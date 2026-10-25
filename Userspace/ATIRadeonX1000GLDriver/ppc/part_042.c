#include "decls.h"

/* FUN_0013922c @ 0x13922c (104 bytes) */
int FUN_0013922c(param_1)
  int param_1;
{
  uint uVar1;
  int loopIndex;
  int *piVar3;
  int countdown;
  undefined4 local_28;
  
  piVar3 = (int *)0x0;
  uVar1 = *(uint *)(param_1 + 4) - 1;
  if (uVar1 < *(uint *)(param_1 + 4)) {
    piVar3 = (int *)(uVar1 * 4 + *(int *)(param_1 + 8));
  }
  local_28 = *piVar3;
  if ((char)local_28 == '\0') {
    return local_28;
  }
  loopIndex = 0;
  countdown = 4;
  do {
    if (*(char *)((int)&local_28 + loopIndex) != -1) {
      return (int)*(char *)((int)&local_28 + loopIndex);
    }
    loopIndex = loopIndex + 1;
    countdown = countdown + -1;
  } while (countdown != 0);
  return 0;
}

/* FUN_00139294 @ 0x139294 (176 bytes) */
int FUN_00139294(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int isIfHeader;
  int isIfFooter;
  undefined4 uVar2;
  
  if (param_1[0x2e] == 0) {
    do {
      while( true ) {
        param_1 = (int *)param_1[0x3c];
        if ((param_1 == param_2) || (param_1[0x2e] != 0)) goto LAB_0013932c;
        isIfFooter = (**(code **)(*param_1 + 0x28))(param_1);
        if (isIfFooter == 0) break;
        param_1 = (int *)Block__getPredecessor(param_1[0x4b],0);
      }
      isIfHeader = (**(code **)(*param_1 + 0x24))(param_1);
    } while (isIfHeader == 0);
    uVar2 = 1;
  }
  else {
LAB_0013932c:
    uVar2 = 0;
  }
  return uVar2;
}

/* IRInst__isOpcodeInSet139344 @ 0x139344 (80 bytes) */
int IRInst__isOpcodeInSet139344(param_1)
  int param_1;
{
  switch(*(undefined4 *)(*(int *)(param_1 + 0x88) + 8)) {
  case 0x69:
  case 0x6b:
  case 0x75:
  case 0x76:
  case 0x9e:
  case 0x9f:
  case 0xa0:
  case 0xa1:
  case 0xaf:
    return 1;
  default:
    return 0;
  }
}

/* Program__moveInterpFetchesOutOfIfs @ 0x1394b0 (496 bytes) */
int Program__moveInterpFetchesOutOfIfs(param_1)
  int param_1;
{
  int vcall24Result;
  int vcall4cResult;
  int isPostLoopFooter;
  int isLoopHeader;
  int isIfFooter;
  int isIfHeader;
  int *operandVReg;
  int *piVar1;
  int *piVar2;
  int *a0;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  piVar4 = *(int **)(param_1 + 0x3a0);
  piVar1 = (int *)(*(int **)(param_1 + 900))[2];
  if (piVar1 != (int *)0x0) {
    a0 = (int *)0x0;
    piVar3 = *(int **)(param_1 + 900);
    do {
      piVar2 = piVar1;
      iVar5 = *(int *)(piVar3[0x26] + 8);
      iVar7 = piVar3[0x26];
      if (iVar5 != 0) {
        do {
          iVar6 = iVar5;
          iVar5 = ((int (*)())IRInst__isOpcodeInSet139344)(iVar7);
          if (iVar5 != 0) {
            operandVReg = (int *)IRInst__getOperandSource(iVar7,1);
            vcall4cResult = (**(code **)(*operandVReg + 0x4c))(operandVReg);
            piVar1 = piVar3;
            if (vcall4cResult != 0) {
              while (piVar1 != piVar4) {
                isIfHeader = (**(code **)(*piVar1 + 0x24))(piVar1);
                if (isIfHeader != 0) {
                  if (a0 == (int *)0x0) {
                    Block__hasMultipleSuccessors(piVar4);
                    a0 = (int *)Block__getSuccessor(piVar4,0);
                    vcall24Result = (**(code **)(*a0 + 0x24))(a0);
                    if (vcall24Result == 0) {
                      (**(code **)(*a0 + 0x2c))(a0);
                    }
                  }
                  IRInst__unlinkAndClearFlag0(iVar7);
                  *(uint *)(iVar7 + 0x14) = *(uint *)(iVar7 + 0x14) | 1;
                  Block__appendInst(a0,iVar7);
                  break;
                }
                isIfFooter = (**(code **)(*piVar1 + 0x28))(piVar1);
                if (isIfFooter == 0) {
                  isLoopHeader = (**(code **)(*piVar1 + 0x2c))(piVar1);
                  if (isLoopHeader == 0) {
                    isPostLoopFooter = (**(code **)(*piVar1 + 0x34))(piVar1);
                    if (isPostLoopFooter != 0) {
                      piVar1 = (int *)Block__findSimplePredecessor(piVar1[0x4b]);
                    }
                    goto LAB_00139654;
                  }
                  piVar1 = (int *)Block__findSimplePredecessor(piVar1);
                }
                else {
                  piVar1 = (int *)Block__getPredecessor(piVar1[0x4b],0);
LAB_00139654:
                  piVar1 = (int *)piVar1[0x3c];
                }
              }
            }
          }
          iVar5 = *(int *)(iVar6 + 8);
          iVar7 = iVar6;
        } while (iVar5 != 0);
        piVar2 = (int *)piVar3[2];
      }
      piVar1 = (int *)piVar2[2];
      piVar3 = piVar2;
    } while ((int *)piVar2[2] != (int *)0x0);
  }
  return;
}

/* IRInst__markOpcode13After12 @ 0x1396a0 (48 bytes) */
int IRInst__markOpcode13After12(param_1, param_2)
  int param_1;
  int param_2;
{
  if (*(int *)(*(int *)(param_1 + 0x88) + 8) != 0x13) {
    return;
  }
  if (*(int *)(*(int *)(param_2 + 0x88) + 8) == 0x12) {
    return;
  }
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x20000;
  return;
}

/* FUN_001396d0 @ 0x1396d0 (360 bytes) */
int FUN_001396d0(param_1, inst, operandIndex, param_4)
  int param_1;
  int *inst;
  int operandIndex;
  int param_4;
{
  int vcall14Result;
  int sourceDef;
  int operandRecord;
  int vcall5cResult;
  int operandVReg;
  uint uVar3;
  undefined4 local_38;
  uint local_34;
  uint local_30 [4];
  
  vcall5cResult = (**(code **)(*inst + 0x5c))(inst,inst,operandIndex,param_4);
  if (vcall5cResult == 0) {
    operandRecord = IRInst__getOperandRecord(inst,0);
    SelectWord__selectWhereMasked(&local_38,*(undefined4 *)(operandRecord + 0x10),inst[3]);
    vcall14Result = (**(code **)(*inst + 0x14))(inst);
    uVar3 = 0x1010101;
    if (operandIndex <= vcall14Result) {
      IRInst__computeSourceLaneMask(&local_34,inst,operandIndex,param_4,local_38);
      uVar3 = local_34;
    }
    SelectWord__selectWhereMasked(local_30,0,uVar3);
    sourceDef = IRInst__getOperandSource(inst,operandIndex);
    if ((sourceDef != 0) &&
       (((*(int *)(sourceDef + 0x98) == 2 || (*(int *)(sourceDef + 0x98) == 0xc)) &&
        (operandVReg = (**(code **)(**(int **)(param_1 + 0x30c) + 0xec))
                           (*(int **)(param_1 + 0x30c),inst,operandIndex,
                            local_30[0] << 0x18 | (local_30[0] >> 8 & 0xff) << 0x10 |
                            (local_30[0] >> 0x10 & 0xff) << 8 | local_30[0] >> 0x18,
                            *(undefined4 *)(param_4 + 8)), operandVReg != 0)))) {
      operandVReg = IRInst__getOperandSource(inst,operandIndex);
      if (sourceDef == operandVReg) {
        return 1;
      }
      *(uint *)(operandVReg + 0xc) = uVar3 | *(uint *)(operandVReg + 0xc);
      return 1;
    }
  }
  return 0;
}

/* IRInst__sourceIsSplatConstant @ 0x139838 (124 bytes) */
undefined4 IRInst__sourceIsSplatConstant(undefined4 inst,undefined4 srcIndex,double fparam_1)
{
  int operandRecord;
  int iVar1;
  undefined4 uVar2;
  int local_48;
  float local_44;
  
  operandRecord = IRInst__getOperandRecord(inst,0);
  iVar1 = IRInst__getUniformSourceConstant(inst,srcIndex,*(undefined4 *)(operandRecord + 0x10),&local_48);
  if (((iVar1 == 0) || ((double)local_44 != fparam_1)) || (uVar2 = 1, local_48 != 2)) {
    uVar2 = 0;
  }
  return uVar2;
}

/* FUN_001398b4 @ 0x1398b4 (964 bytes) */
int FUN_001398b4(inst, param_2, param_3, program)
  int inst;
  undefined4 param_2;
  undefined4 param_3;
  int program;
{
  int sourceIsSplatConstantResult;
  undefined4 opcodeInfo;
  int sourceDef;
  int operandRecord2;
  int iVar1;
  int operandVReg;
  int operandRecord;
  int operandVReg2;
  int callResult;
  undefined4 uVar6;
  undefined4 operandSelect;
  undefined4 uVar8;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40 [6];
  
  if (*(int *)(*(int *)(inst + 0x88) + 8) != 0x29) {
    return 0;
  }
  sourceIsSplatConstantResult = ((undefined4 (*)())IRInst__sourceIsSplatConstant)(inst,1,(double)FLOAT_001aa0d4);
  if (sourceIsSplatConstantResult == 0) {
    return 0;
  }
  operandVReg = IRInst__getOperandSource(inst,2);
  iVar1 = *(int *)(operandVReg + 0x88);
  if ((*(int *)(iVar1 + 8) == 0x24) && ((*(uint *)(operandVReg + 0x14) & 0x200) == 0)) {
    iVar1 = ((undefined4 (*)())IRInst__sourceIsSplatConstant)(operandVReg,2,(double)FLOAT_001aa0d4);
    if ((iVar1 == 0) ||
       (((iVar1 = ((undefined4 (*)())IRInst__sourceIsSplatConstant)(operandVReg,3,(double)FLOAT_001aa0e8), iVar1 == 0 ||
         ((*(uint *)(operandVReg + 0xb8) & 1) != 0)) || ((*(uint *)(operandVReg + 0xb8) & 2) != 0)))) {
      iVar1 = *(int *)(operandVReg + 0x88);
      goto LAB_00139c2c;
    }
  }
  else {
LAB_00139c2c:
    if ((*(int *)(iVar1 + 8) == 0x28) && ((*(uint *)(operandVReg + 0x14) & 0x200) == 0)) {
      sourceIsSplatConstantResult = ((undefined4 (*)())IRInst__sourceIsSplatConstant)(operandVReg,2,(double)FLOAT_001aa0d4);
      if ((sourceIsSplatConstantResult != 0) &&
         (((*(uint *)(operandVReg + 0xb8) & 1) == 0 && ((*(uint *)(operandVReg + 0xb8) & 2) != 0)))) {
        uVar8 = 1;
        uVar6 = 0x27;
        goto LAB_00139978;
      }
      iVar1 = *(int *)(operandVReg + 0x88);
    }
    if ((*(int *)(iVar1 + 8) == 0x28) && ((*(uint *)(operandVReg + 0x14) & 0x200) == 0)) {
      sourceIsSplatConstantResult = ((undefined4 (*)())IRInst__sourceIsSplatConstant)(operandVReg,1,(double)FLOAT_001aa0d4);
      if ((sourceIsSplatConstantResult != 0) &&
         (((*(uint *)(operandVReg + 0xd0) & 1) == 0 && ((*(uint *)(operandVReg + 0xd0) & 2) == 0)))) {
        uVar8 = 2;
        uVar6 = 0x29;
        goto LAB_00139978;
      }
      iVar1 = *(int *)(operandVReg + 0x88);
    }
    if (*(int *)(iVar1 + 8) != 0x25) {
      return 0;
    }
    if ((*(uint *)(operandVReg + 0x14) & 0x200) != 0) {
      return 0;
    }
    sourceIsSplatConstantResult = ((undefined4 (*)())IRInst__sourceIsSplatConstant)(operandVReg,2,(double)FLOAT_001aa0d4);
    if (sourceIsSplatConstantResult == 0) {
      return 0;
    }
    sourceIsSplatConstantResult = ((undefined4 (*)())IRInst__sourceIsSplatConstant)(operandVReg,3,(double)FLOAT_001aa0e8);
    if (sourceIsSplatConstantResult == 0) {
      return 0;
    }
    if ((*(uint *)(operandVReg + 0xb8) & 1) != 0) {
      return 0;
    }
    if ((*(uint *)(operandVReg + 0xb8) & 2) != 0) {
      return 0;
    }
  }
  uVar8 = 1;
  uVar6 = 0x29;
LAB_00139978:
  iVar1 = IRInst__getOperandSource(operandVReg,uVar8);
  if (((((*(int *)(*(int *)(iVar1 + 0x88) + 8) == 0x12) && ((*(uint *)(iVar1 + 0x14) & 0x200) == 0))
       && ((*(uint *)(iVar1 + 0xb8) & 1) == 0)) &&
      (((*(uint *)(iVar1 + 0xb8) & 2) == 0 && ((*(uint *)(iVar1 + 0xd0) & 1) != 0)))) &&
     ((*(uint *)(iVar1 + 0xd0) & 2) == 0)) {
    operandRecord = IRInst__getOperandRecord(inst,2);
    operandSelect = *(undefined4 *)(operandRecord + 0x10);
    operandRecord = IRInst__getOperandRecord(operandVReg,uVar8);
    SelectWord__compose(&local_48,*(undefined4 *)(operandRecord + 0x10),operandSelect);
    operandRecord = IRInst__getOperandRecord(iVar1,1);
    SelectWord__compose(&local_44,*(undefined4 *)(operandRecord + 0x10),local_48);
    operandRecord = IRInst__getOperandRecord(iVar1,2);
    SelectWord__compose(local_40,*(undefined4 *)(operandRecord + 0x10),local_48);
    sourceDef = IRInst__getOperandSource(iVar1,1);
    IRInst__setOperandSource(inst,1,sourceDef,0,*(undefined4 *)(program + 8));
    operandVReg2 = IRInst__getOperandSource(iVar1,2);
    callResult = IRInst__hasSingleUse(operandVReg,program);
    if ((callResult == 0) || (iVar1 = IRInst__hasSingleUse(iVar1,program), iVar1 == 0)) {
      if (*(int *)(program + 0x478) < *(int *)(sourceDef + 0x160)) {
        *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + 1;
      }
      else {
        *(int *)(sourceDef + 0x160) = *(int *)(program + 0x478) + 1;
      }
      if (*(int *)(program + 0x478) < *(int *)(operandVReg2 + 0x160)) {
        *(int *)(operandVReg2 + 0x160) = *(int *)(operandVReg2 + 0x160) + 1;
      }
      else {
        *(int *)(operandVReg2 + 0x160) = *(int *)(program + 0x478) + 1;
      }
    }
    IRInst__setOperandSource(inst,2,operandVReg2,0,*(undefined4 *)(program + 8));
    operandRecord2 = IRInst__getOperandRecord(inst,1);
    *(undefined4 *)(operandRecord2 + 0x10) = local_44;
    operandRecord2 = IRInst__getOperandRecord(inst,2);
    *(undefined4 *)(operandRecord2 + 0x10) = local_40[0];
    opcodeInfo = Opcode__getInfo(uVar6);
    *(undefined4 *)(inst + 0x88) = opcodeInfo;
    IRInst__dropCounterAndDeleteIfUnused(operandVReg,*(undefined4 *)(program + 8));
  }
  return 0;
}

/* FUN_00139c78 @ 0x139c78 (200 bytes) */
int FUN_00139c78(inst, param_2, param_3, program)
  int inst;
  int param_2;
  undefined4 param_3;
  int program;
{
  int vcall70Result;
  int iVar1;
  int *piVar2;
  
  if (((*(uint *)(inst + 0x14) & 1) != 0) &&
     ((param_2 == 0 || ((*(uint *)(param_2 + 0x14) & 1) != 0)))) {
    iVar1 = ((int (*)())FUN_001398b4)(inst,param_2,param_3,program);
    if (iVar1 != 0) {
      *(int *)(inst + 0x150) = *(int *)(program + 0x474) + -1;
    }
    piVar2 = *(int **)(*(int *)(program + 8) + 0x30c);
    vcall70Result = (**(code **)(*piVar2 + 0x70))(piVar2,param_2,param_3,inst,program);
    if (vcall70Result != 0) {
      *(int *)(inst + 0x150) = *(int *)(program + 0x474) + -1;
    }
    FUN_001486e8(inst,program);
    return;
  }
  return;
}

/* FUN_00139d40 @ 0x139d40 (524 bytes) */
int FUN_00139d40(param_1)
  int param_1;
{
  uint countBefore;
  int slotByteOffsetB;
  int vcall30Result;
  int slotByteOffset;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  int callResult;
  uint uVar8;
  int *piVar9;
  int loopIndex;
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - vecCapacity/vecCount/vecData/vecArena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_48_buf [0x10];
  #define vecCapacity (*(uint *)(local_48_buf + 0x00))
  #define vecCount (*(uint *)(local_48_buf + 0x04))
  #define vecData (*(int *)(local_48_buf + 0x08))
  #define vecArena (*(undefined4 *)(local_48_buf + 0x0c))
  
  vecArena = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  vecCount = 0;
  vecCapacity = 2;
  vecData = Arena__alloc(vecArena,8);
  *(int *)(param_1 + 0x474) = *(int *)(param_1 + 0x474) + 1;
  iVar2 = *(int *)(param_1 + 900);
  for (iVar5 = *(int *)(*(int *)(param_1 + 900) + 8); iVar5 != 0; iVar5 = *(int *)(iVar5 + 8)) {
    piVar3 = (int *)(*(int **)(iVar2 + 0x98))[2];
    piVar9 = *(int **)(iVar2 + 0x98);
    if (piVar3 != (int *)0x0) {
      do {
        piVar4 = piVar3;
        if ((piVar9[5] & 1U) != 0) {
          vcall30Result = (**(code **)(*piVar9 + 0x30))(piVar9);
          countBefore = vecCount;
          if ((vcall30Result != 0) && (*(int *)(param_1 + 0x474) != piVar9[0x54])) {
            piVar9[0x54] = *(int *)(param_1 + 0x474);
            if (vecCount < vecCapacity) {
              slotByteOffsetB = vecCount * 4;
              _memset(slotByteOffsetB + vecData,0,4);
              vecCount = countBefore + 1;
              puVar6 = (undefined4 *)(slotByteOffsetB + vecData);
            }
            else {
              puVar6 = (undefined4 *)Vector__elementRefGrow(&vecCapacity,vecCount);
            }
            *puVar6 = piVar9;
            do {
              uVar8 = vecCount - 1;
              piVar3 = (int *)0x0;
              if (uVar8 < vecCount) {
                piVar3 = (int *)(uVar8 * 4 + vecData);
              }
              iVar5 = *piVar3;
              Vector__removeAt(&vecCapacity,uVar8);
              if (0 < *(int *)(iVar5 + 0x84)) {
                loopIndex = 1;
                do {
                  callResult = IRInst__getOperandSource(iVar5,loopIndex);
                  countBefore = vecCount;
                  *(uint *)(callResult + 0x14) = *(uint *)(callResult + 0x14) | 0x2000;
                  if ((callResult != 0) && (*(int *)(param_1 + 0x474) != *(int *)(callResult + 0x150))) {
                    *(int *)(callResult + 0x150) = *(int *)(param_1 + 0x474);
                    if (vecCount < vecCapacity) {
                      slotByteOffset = vecCount * 4;
                      _memset(slotByteOffset + vecData,0,4);
                      vecCount = countBefore + 1;
                      piVar3 = (int *)(slotByteOffset + vecData);
                    }
                    else {
                      piVar3 = (int *)Vector__elementRefGrow(&vecCapacity,vecCount);
                    }
                    *piVar3 = callResult;
                  }
                  loopIndex = loopIndex + 1;
                } while (loopIndex <= *(int *)(iVar5 + 0x84));
              }
            } while (vecCount != 0);
          }
          piVar4 = (int *)piVar9[2];
        }
        piVar3 = (int *)piVar4[2];
        piVar9 = piVar4;
      } while ((int *)piVar4[2] != (int *)0x0);
      iVar5 = *(int *)(iVar2 + 8);
    }
    iVar2 = iVar5;
  }
  return Arena__free(vecArena,vecData);
}
#undef vecCapacity
#undef vecCount
#undef vecData
#undef vecArena

/* Block__scanBranchConeForFetchAndInterp @ 0x139f84 (700 bytes) */
int Block__scanBranchConeForFetchAndInterp(block, vector, coneStamp)
  int *block;
  uint *vector;
  int coneStamp;
{
  int vcall28ResultB;
  int vcall4cResult;
  int vcall28Result;
  int vcall40Result;
  int *operandVReg;
  int loopIndex;
  byte coneHasInterpLoad;
  byte coneHasFetch;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined4 branchInst;
  undefined4 *puVar7;
  int *piVar8;
  int iVar9;
  undefined4 extraout_r4;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  int iVar10;
  uint uVar11;
  
  iVar10 = coneStamp;
  vcall40Result = (**(code **)(*block + 0x40))(block,vector,coneStamp);
  if (vcall40Result != 0) {
    return;
  }
  branchInst = Block__getBranchInst(block,extraout_r4,iVar10,in_r6,in_r7,in_r8,in_r9);
  uVar11 = vector[1];
  if (uVar11 < *vector) {
    _memset(uVar11 * 4 + vector[2],0,4);
    puVar7 = (undefined4 *)(uVar11 * 4 + vector[2]);
    vector[1] = uVar11 + 1;
  }
  else {
    puVar7 = (undefined4 *)Vector__elementRefGrow(vector,uVar11);
  }
  *puVar7 = branchInst;
  coneHasInterpLoad = 0;
  uVar11 = vector[1];
  coneHasFetch = 0;
  do {
    piVar8 = (int *)0x0;
    if (uVar11 - 1 < vector[1]) {
      piVar8 = (int *)((uVar11 - 1) * 4 + vector[2]);
    }
    iVar10 = *piVar8;
    Vector__removeAt(vector,vector[1] - 1);
    if (0 < *(int *)(iVar10 + 0x84)) {
      loopIndex = 1;
      do {
        operandVReg = (int *)IRInst__getOperandSource(iVar10,loopIndex);
        if (operandVReg != (int *)0x0) {
          vcall28Result = (**(code **)(*operandVReg + 0x28))(operandVReg);
          if (vcall28Result == 0) {
            vcall4cResult = (**(code **)(*operandVReg + 0x4c))(operandVReg);
            if (vcall4cResult != 0) {
              coneHasInterpLoad = 1;
            }
          }
          else {
            coneHasFetch = 1;
          }
          if ((bool)(coneHasFetch & coneHasInterpLoad)) {
            iVar9 = block[0x4d];
            iVar5 = block[0x4e];
            iVar10 = FUN_000e9294(block);
            if (iVar10 == 0) goto LAB_0013a198;
            piVar8 = *(int **)(iVar9 + 0x98);
            piVar3 = (int *)(*(int **)(iVar9 + 0x98))[2];
            goto joined_r0x0013a104;
          }
          if (coneStamp != operandVReg[0x54]) {
            operandVReg[0x54] = coneStamp;
            uVar11 = vector[1];
            if (uVar11 < *vector) {
              _memset(uVar11 * 4 + vector[2],0,4);
              puVar7 = (undefined4 *)(uVar11 * 4 + vector[2]);
              vector[1] = uVar11 + 1;
            }
            else {
              puVar7 = (undefined4 *)Vector__elementRefGrow(vector,uVar11);
            }
            *puVar7 = operandVReg;
          }
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex <= *(int *)(iVar10 + 0x84));
    }
    uVar11 = vector[1];
  } while (uVar11 != 0);
LAB_0013a220:
  block[3] = block[3] | 0x400;
  return;
joined_r0x0013a104:
  if (piVar3 == (int *)0x0) goto LAB_0013a148;
  if ((piVar8[5] & 1U) != 0) {
    vcall28ResultB = (**(code **)(*piVar8 + 0x28))(piVar8);
    if (vcall28ResultB != 0) goto LAB_0013a220;
    piVar3 = (int *)piVar8[2];
  }
  piVar8 = piVar3;
  piVar3 = (int *)piVar3[2];
  goto joined_r0x0013a104;
LAB_0013a148:
  piVar8 = *(int **)(iVar5 + 0x98);
  piVar3 = (int *)piVar8[2];
  do {
    piVar4 = piVar3;
    if (piVar4 == (int *)0x0) {
LAB_0013a198:
      block[3] = block[3] | 0x800;
      return;
    }
    if ((piVar8[5] & 1U) != 0) {
      vcall28ResultB = (**(code **)(*piVar8 + 0x28))(piVar8);
      if (vcall28ResultB != 0) goto LAB_0013a220;
      piVar4 = (int *)piVar8[2];
    }
    piVar3 = (int *)piVar4[2];
    piVar8 = piVar4;
  } while( true );
}

/* FUN_0013a240 @ 0x13a240 (332 bytes) */
int FUN_0013a240(vector)
  uint *vector;
{
  int countdown;
  char cVar1;
  uint uVar2;
  int *piVar3;
  char *pcVar4;
  int iVar5;
  undefined4 local_38;
  
  piVar3 = (int *)0x0;
  uVar2 = vector[1] - 1;
  if (uVar2 < vector[1]) {
    piVar3 = (int *)(uVar2 * 4 + vector[2]);
  }
  iVar5 = *piVar3;
  Vector__removeAt(vector,vector[1] - 1);
  local_38 = iVar5;
  iVar5 = local_38;
  (*(unsigned char *)((unsigned char *)&(local_38) + 3)) = (char)iVar5;
  local_38 = iVar5;
  if ((char)local_38 == '\0') {
    uVar2 = vector[1];
    iVar5 = iVar5 + 1;
    if (uVar2 < *vector) {
      _memset(uVar2 * 4 + vector[2],0,4);
      piVar3 = (int *)(uVar2 * 4 + vector[2]);
      vector[1] = uVar2 + 1;
    }
    else {
      piVar3 = (int *)Vector__elementRefGrow(vector,uVar2);
    }
    *piVar3 = iVar5;
  }
  else {
    pcVar4 = (char *)&local_38;
    countdown = 4;
    do {
      if (*pcVar4 != -1) {
        cVar1 = pcVar4[1];
        *pcVar4 = -1;
        iVar5 = local_38;
        uVar2 = vector[1];
        if (uVar2 < *vector) {
          _memset(uVar2 * 4 + vector[2],0,4);
          piVar3 = (int *)(uVar2 * 4 + vector[2]);
          vector[1] = uVar2 + 1;
        }
        else {
          piVar3 = (int *)Vector__elementRefGrow(vector,uVar2);
        }
        *piVar3 = iVar5;
        return (int)cVar1;
      }
      pcVar4 = pcVar4 + 1;
      countdown = countdown + -1;
    } while (countdown != 0);
    iVar5 = 0;
  }
  return iVar5;
}

/* FUN_0013a38c @ 0x13a38c (696 bytes) */
int FUN_0013a38c(inst, vector, program)
  int inst;
  uint *vector;
  undefined4 program;
{
  undefined4 sourceDef;
  undefined1 uVar1;
  undefined1 uVar2;
  bool bVar3;
  int loopIndex;
  undefined4 *puVar5;
  undefined4 uVar6;
  int loopIndexB;
  int iVar8;
  int *piVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  undefined4 local_48;
  int local_44 [12];
  
  if (inst == 0) {
    return 1;
  }
  iVar10 = *(int *)(inst + 0x84);
  local_48 = 0xffffffff;
  if (iVar10 == 1) {
    uVar11 = vector[1];
    local_48 = 0x1ffffff;
    if (uVar11 < *vector) {
      _memset(uVar11 * 4 + vector[2],0,4);
      puVar5 = (undefined4 *)(uVar11 * 4 + vector[2]);
      vector[1] = uVar11 + 1;
    }
    else {
      puVar5 = (undefined4 *)Vector__elementRefGrow(vector,uVar11);
    }
    *puVar5 = 0x1ffffff;
    return 1;
  }
  if (4 < iVar10) {
    uVar11 = vector[1];
    if (uVar11 < *vector) {
      _memset(uVar11 * 4 + vector[2],0,4);
      puVar5 = (undefined4 *)(uVar11 * 4 + vector[2]);
      vector[1] = uVar11 + 1;
    }
    else {
      puVar5 = (undefined4 *)Vector__elementRefGrow(vector,uVar11);
    }
    *puVar5 = 1;
    return 1;
  }
  sourceDef = IRInst__getOperandSource(inst,1);
  local_44[0] = IRInst__useCount(sourceDef,program);
  sourceDef = IRInst__getOperandSource(inst,2);
  local_44[1] = IRInst__useCount(sourceDef,program);
  if (iVar10 == 2) {
    if (local_44[0] < local_44[1]) {
      (*(unsigned int *)((unsigned char *)&(local_48) + 1)) = CONCAT12(2,(*(unsigned short *)((unsigned char *)&(local_48) + 2)));
      local_48 = CONCAT13(1,(*(unsigned int *)((unsigned char *)&(local_48) + 1)));
    }
    else {
      (*(unsigned int *)((unsigned char *)&(local_48) + 1)) = CONCAT12(1,(*(unsigned short *)((unsigned char *)&(local_48) + 2)));
      local_48 = CONCAT13(2,(*(unsigned int *)((unsigned char *)&(local_48) + 1)));
    }
    goto LAB_0013a5cc;
  }
  sourceDef = IRInst__getOperandSource(inst,3);
  local_44[2] = IRInst__useCount(sourceDef,program);
  if (iVar10 == 4) {
    sourceDef = IRInst__getOperandSource(inst,4);
    local_44[3] = IRInst__useCount(sourceDef,program);
LAB_0013a528:
    loopIndex = 0;
    iVar12 = iVar10;
    do {
      *(char *)((int)local_44 + loopIndex + -4) = (char)(loopIndex + 1);
      iVar12 = iVar12 + -1;
      loopIndex = loopIndex + 1;
    } while (iVar12 != 0);
  }
  else if (0 < iVar10) goto LAB_0013a528;
  do {
    bVar3 = false;
    loopIndexB = 0;
    loopIndex = 0;
    piVar9 = local_44;
    iVar12 = iVar10;
    if (iVar10 + -1 < 0) {
      iVar12 = 1;
    }
    while (iVar12 = iVar12 + -1, iVar12 != 0) {
      iVar8 = *piVar9;
      if (piVar9[1] < iVar8) {
        uVar2 = *(undefined1 *)((int)local_44 + loopIndexB + -4);
        uVar1 = *(undefined1 *)((int)local_44 + loopIndex + -3);
        *piVar9 = piVar9[1];
        *(undefined1 *)((int)local_44 + loopIndexB + -4) = uVar1;
        bVar3 = true;
        piVar9[1] = iVar8;
        *(undefined1 *)((int)local_44 + loopIndex + -3) = uVar2;
      }
      loopIndexB = loopIndexB + 1;
      loopIndex = loopIndex + 1;
      piVar9 = piVar9 + 1;
    }
  } while (bVar3);
LAB_0013a5cc:
  uVar6 = local_48;
  uVar11 = vector[1];
  if (uVar11 < *vector) {
    _memset(uVar11 * 4 + vector[2],0,4);
    puVar5 = (undefined4 *)(uVar11 * 4 + vector[2]);
    vector[1] = uVar11 + 1;
  }
  else {
    puVar5 = (undefined4 *)Vector__elementRefGrow(vector,uVar11);
  }
  *puVar5 = uVar6;
  return (int)(*(unsigned char *)((unsigned char *)&(local_48) + 0));
}

/* FUN_0013a644 @ 0x13a644 (304 bytes) */
int FUN_0013a644(param_1)
  int param_1;
{
  bool moreComponents;
  uint uVar2;
  undefined4 *puVar3;
  int operandRecord;
  int iVar5;
  uint uVar6;
  uint loopIndex;
  int iVar8;
  uint *puVar9;
  int *piVar10;
  
  uVar6 = 0;
  puVar9 = *(uint **)(param_1 + 0x10);
  uVar2 = puVar9[1];
  if (uVar2 != 0) {
    loopIndex = 0;
    do {
      if (loopIndex < *puVar9) {
        if (uVar2 <= loopIndex) {
          _memset(uVar2 * 4 + puVar9[2],0,(loopIndex - uVar2) * 4 + 4);
          puVar9[1] = loopIndex + 1;
        }
        puVar3 = (undefined4 *)(loopIndex * 4 + puVar9[2]);
      }
      else {
        puVar3 = (undefined4 *)Vector__elementRefGrow(puVar9,loopIndex);
      }
      loopIndex = loopIndex + 1;
      piVar10 = (int *)*puVar3;
      for (iVar8 = 1; iVar5 = (**(code **)(*piVar10 + 0x14))(piVar10), iVar8 <= iVar5;
          iVar8 = iVar8 + 1) {
        iVar5 = IRInst__getOperandSource(piVar10,iVar8);
        if (param_1 == iVar5) {
          iVar5 = 0;
          do {
            operandRecord = IRInst__getOperandRecord(piVar10,iVar8);
            uVar2 = (uint)*(byte *)(iVar5 + operandRecord + 0x10);
            if (uVar2 != 4) {
              uVar6 = uVar6 | 1 << (uVar2 & 0x3f);
            }
            moreComponents = iVar5 != 3;
            iVar5 = iVar5 + 1;
          } while (moreComponents);
        }
      }
      puVar9 = *(uint **)(param_1 + 0x10);
      uVar2 = puVar9[1];
    } while (loopIndex < uVar2);
  }
  return uVar6;
}

/* FUN_0013a774 @ 0x13a774 (304 bytes) */
int FUN_0013a774(param_1, param_2, param_3)
  int *param_1;
  uint param_2;
  uint param_3;
{
  undefined8 operandRecord;
  undefined8 sourceDef;
  bool moreComponents;
  uint uVar2;
  int iVar3;
  uint extraout_r4;
  undefined4 a1;
  uint extraout_r4_00;
  uint loopIndex;
  uint uVar5;
  undefined4 uVar6;
  uint *puVar7;
  int iVar8;
  undefined8 uVar9;
  
  puVar7 = (uint *)param_1[4];
  uVar2 = puVar7[1];
  uVar5 = param_2;
  if (uVar2 != 0) {
    loopIndex = 0;
    do {
      if (loopIndex < *puVar7) {
        if (uVar2 <= loopIndex) {
          param_3 = (loopIndex - uVar2) * 4 + 4;
          _memset(uVar2 * 4 + puVar7[2],0,param_3);
          puVar7[1] = loopIndex + 1;
          param_2 = extraout_r4;
        }
        uVar9 = CONCAT44(loopIndex * 4 + puVar7[2],param_2);
      }
      else {
        uVar9 = Vector__elementRefGrow(puVar7,loopIndex);
      }
      a1 = (undefined4)uVar9;
      uVar6 = *(undefined4 *)((ulonglong)uVar9 >> 0x20);
      for (iVar8 = 1; iVar3 = (**(code **)(*param_1 + 0x14))(param_1,a1,param_3), iVar8 <= iVar3;
          iVar8 = iVar8 + 1) {
        sourceDef = IRInst__getOperandSource(uVar6,iVar8);
        a1 = (undefined4)sourceDef;
        if (param_1 == (int *)((ulonglong)sourceDef >> 0x20)) {
          iVar3 = 0;
          do {
            operandRecord = IRInst__getOperandRecord(uVar6,iVar8);
            a1 = (undefined4)operandRecord;
            uVar2 = (uint)*(byte *)(iVar3 + (int)((ulonglong)operandRecord >> 0x20) + 0x10);
            if ((uVar2 != 4) && (uVar5 = uVar5 & ~(1 << (uVar2 & 0x3f)), uVar5 == 0)) {
              return 0;
            }
            moreComponents = iVar3 != 3;
            iVar3 = iVar3 + 1;
          } while (moreComponents);
        }
      }
      puVar7 = (uint *)param_1[4];
      loopIndex = loopIndex + 1;
      uVar2 = puVar7[1];
      param_2 = extraout_r4_00;
    } while (loopIndex < uVar2);
  }
  return uVar5;
}

/* FUN_0013a8a4 @ 0x13a8a4 (2372 bytes) */
int FUN_0013a8a4(pass)
  uint pass;
{
  bool moreComponentsB;
  bool laneByteZero;
  bool chainFailed;
  uint candidateMask;
  uint savedLaneWord;
  uint laneTagB;
  uint laneTag;
  uint foldMask;
  int *nextInst;
  int *targetInfo;
  int *sourceInst;
  int chainDestRecord;
  int componentIdxB;
  int sourceId;
  int operandRecordB;
  int laneTagValue;
  int nextBlockB;
  int laneEntryPtr;
  int sourceInstB;
  int laneIndex;
  int destOperandRecord;
  int srcDestRecord;
  int operandRecordA;
  int predicateResult;
  int laneFillIndex;
  int opcodeDesc;
  int destRecord;
  int flagResult;
  int operandIndex;
  int opcodeKind;
  bool moreComponents;
  bool sawRemappedComponent;
  byte laneTagByte;
  bool sawComponent3;
  uint usableMask;
  int blockCursor;
  int *lookaheadInst;
  int *chainInst;
  int laneTable;
  int operandLimit;
  int operandRecord;
  undefined4 staleArg5;
  undefined4 staleArg6;
  int laneEntryAddr;
  uint requiredLaneMask;
  uint componentIndex;
  int nextBlock;
  undefined4 compiler;
  uint operandComponent;
  code *setComponentFn;
  int laneCountdown;
  int *inst;
  undefined4 laneWord;
  uint maskedSelectWord;
  int currentBlock;
  int blockListObject;
  uint laneWordInsert1;
  uint laneWordInsert2;
  uint laneWordInsert3;
  uint laneWordInsert4;
  uint laneWordInsert5;
  uint laneWordInsert6;
  uint laneWordInsert7;
  uint laneWordInsert8;
  uint laneWordInsert9;
  uint laneWordInsert10;
  uint laneWordInsert11;
  uint laneWordInsert12;
  uint laneWordInsert13;
  uint laneWordInsert14;
  uint laneWordInsert15;
  uint laneWordInsert16;
  
  blockListObject = pass + 0x37c;
  laneTable = FUN_00193e74(*(undefined4 *)(*(int *)(pass + 8) + 0x378),
                       *(int *)(*(int *)(pass + 8) + 0x324) << 2,1);
  blockCursor = *(int *)(blockListObject + 8);
  laneWordInsert1 = 0;
  laneWordInsert2 = 0;
  laneWordInsert3 = 0;
  laneWordInsert4 = 0;
  laneWordInsert5 = 0;
  laneWordInsert6 = 0;
  laneWordInsert7 = 0;
  laneWordInsert8 = 0;
  laneWordInsert9 = 0;
  laneWordInsert10 = 0;
  laneWordInsert11 = 0;
  laneWordInsert12 = 0;
  laneWordInsert13 = 0;
  laneWordInsert14 = 0;
  laneWordInsert15 = 0;
  laneWordInsert16 = 0;
  nextBlock = *(int *)(blockCursor + 8);
  currentBlock = blockCursor;
  if (*(int *)(blockCursor + 8) != 0) {
    do {
      blockCursor = nextBlock;
      lookaheadInst = (int *)(*(int **)(currentBlock + 0x98))[2];
      inst = *(int **)(currentBlock + 0x98);
      if (lookaheadInst != (int *)0x0) {
        do {
          nextInst = lookaheadInst;
          if ((inst[5] & 1U) != 0) {
            opcodeKind = *(int *)(inst[0x22] + 8);
            for (operandIndex = 1; operandLimit = (**(code **)(*inst + 0x14))(inst), operandIndex <= operandLimit;
                operandIndex = operandIndex + 1) {
              sourceInst = (int *)IRInst__getOperandSource(inst,operandIndex);
              laneWord = *(uint *)(laneTable + sourceInst[0x53] * 4);
              if (opcodeKind == 0x8e) {
LAB_0013a9dc:
                laneFillIndex = 0;
                laneCountdown = 4;
                do {
                  *(byte *)((int)&laneWord + laneFillIndex) =
                       (byte)laneFillIndex & 0x3f | *(byte *)((int)&laneWord + laneFillIndex) & 0xc0 | 0x80;
                  laneFillIndex = laneFillIndex + 1;
                  laneCountdown = laneCountdown + -1;
                } while (laneCountdown != 0);
LAB_0013ae00:
                *(uint *)(laneTable + sourceInst[0x53] * 4) = laneWord;
              }
              else {
                compiler = *(undefined4 *)(pass + 8);
                predicateResult = (**(code **)(*sourceInst + 0x24))(sourceInst);
                if (((predicateResult == 0) || (predicateResult = OpcodeTraits__instFlagBit2(compiler,sourceInst), predicateResult != 0)) ||
                   ((sourceInst[5] & 0x400000U) != 0)) goto LAB_0013a9dc;
                sawComponent3 = false;
                sawRemappedComponent = false;
                usableMask = 0xf;
                requiredLaneMask = 0;
                componentIndex = 0;
                do {
                  operandRecordA = IRInst__getOperandRecord(inst,operandIndex);
                  operandComponent = (uint)*(byte *)(componentIndex + operandRecordA + 0x10);
                  srcDestRecord = IRInst__getOperandRecord(sourceInst,0);
                  if (*(char *)(componentIndex + srcDestRecord + 0x10) != '\x01') {
                    usableMask = usableMask & ~(1 << (componentIndex & 0x3f));
                  }
                  if (operandComponent != 4) {
                    if (operandComponent == 3) {
                      laneWordInsert1 = laneWord << 0x18 | laneWordInsert1 & 0xffffff;
                      if (((int)laneWordInsert1 < 0) &&
                         (laneWordInsert2 = laneWord << 0x18 | laneWordInsert2 & 0xffffff, (laneWord & 0x3f) != 3)
                         ) {
                        usableMask = usableMask & 0xfffffff7;
                        sawComponent3 = true;
                        laneWordInsert3 = laneWord << 0x18 | laneWordInsert3 & 0xffffff;
                        requiredLaneMask = requiredLaneMask | 1 << (laneWord & 0x3f);
                      }
                      else {
                        usableMask = usableMask & 0xfffffff7;
                        sawComponent3 = true;
                        laneWordInsert4 = (laneWord & 0xc0) << 0x18 | laneWordInsert4 & 0xffffff | 0x3000000;
                        laneWord = CONCAT31((*(unsigned int *)((unsigned char *)&(laneWord) + 0)),(char)(laneWordInsert4 >> 0x18));
                      }
                    }
                    else {
                      laneWordInsert5 = laneWord << 0x18 | laneWordInsert5 & 0xffffff;
                      if (((int)laneWordInsert5 < 0) &&
                         (laneWordInsert6 = laneWord << 0x18 | laneWordInsert6 & 0xffffff,
                         operandComponent == (laneWord & 0x3f))) {
                        usableMask = 0;
                        laneWordInsert7 = (laneWord & 0xc0) << 0x18 | laneWordInsert7 & 0xffffff | 0x3000000;
                        laneWord = CONCAT31((*(unsigned int *)((unsigned char *)&(laneWord) + 0)),(char)(laneWordInsert7 >> 0x18));
                        laneWordInsert8 = (operandComponent & 0x3f) << 0x18 |
                                   (*(byte *)((int)&laneWord + operandComponent) & 0xc0) << 0x18 |
                                   laneWordInsert8 & 0xffffff;
                        *(char *)((int)&laneWord + operandComponent) = (char)(laneWordInsert8 >> 0x18);
                      }
                      else {
                        usableMask = usableMask & ~(1 << (operandComponent & 0x3f));
                        sawRemappedComponent = true;
                        laneWordInsert9 = (operandComponent & 0x3f) << 0x18 |
                                   (*(byte *)((int)&laneWord + operandComponent) & 0xc0) << 0x18 |
                                   laneWordInsert9 & 0xffffff;
                        *(char *)((int)&laneWord + operandComponent) = (char)(laneWordInsert9 >> 0x18);
                      }
                    }
                    *(byte *)((int)&laneWord + operandComponent) = *(byte *)((int)&laneWord + operandComponent) | 0x80;
                  }
                  moreComponents = componentIndex != 3;
                  componentIndex = componentIndex + 1;
                } while (moreComponents);
                if (((((usableMask != 0) && (sawRemappedComponent)) && (sawComponent3)) &&
                    ((candidateMask = usableMask, requiredLaneMask == 0 || (candidateMask = requiredLaneMask, (usableMask & requiredLaneMask) != 0)))) &&
                   (foldMask = ((int (*)())FUN_0013a774)(sourceInst,candidateMask,pass), foldMask != 0)) {
                  destOperandRecord = IRInst__getOperandRecord(sourceInst,0);
                  if (*(char *)(destOperandRecord + 0x13) == '\x01') {
                    if ((sourceInst[5] & 0x200U) != 0) {
                      chainInst = (int *)IRInst__getOperandSource(sourceInst,sourceInst[0x21]);
                      chainFailed = false;
                      for (; chainInst != (int *)0x0; chainInst = (int *)IRInst__getOperandSource(chainInst,chainInst[0x21])
                          ) {
                        destOperandRecord = IRInst__getOperandRecord(chainInst,0);
                        if (*(char *)(destOperandRecord + 0x13) == '\x01') {
                          foldMask = ((int (*)())FUN_0013a774)(chainInst,foldMask,pass);
                          chainFailed = foldMask == 0;
                        }
                        else {
                          predicateResult = (**(code **)(*chainInst + 0x24))(chainInst);
                          if ((predicateResult == 0) ||
                             (predicateResult = OpcodeTraits__instFlagBit2(*(undefined4 *)(pass + 8),chainInst),
                             predicateResult != 0)) goto LAB_0013ae10;
                        }
                        if (chainFailed) goto LAB_0013ae10;
                        if ((chainInst[5] & 0x200U) == 0) break;
                      }
                    }
                    if ((foldMask & 1) == 0) {
                      if ((foldMask & 2) == 0) {
                        laneIndex = 2;
                        laneTagValue = 2;
                      }
                      else {
                        laneIndex = 1;
                        laneTagValue = 1;
                      }
                    }
                    else {
                      laneIndex = 0;
                      laneTagValue = 0;
                    }
                    operandRecord = IRInst__getOperandRecord(sourceInst,0);
                    if ((*(char *)(operandRecord + 0x13) == '\x01') && ((sourceInst[5] & 0x200U) != 0)) {
                      for (operandRecord = IRInst__getOperandSource(sourceInst,sourceInst[0x21]); operandRecord != 0;
                          operandRecord = IRInst__getOperandSource(operandRecord,*(undefined4 *)(operandRecord + 0x84))) {
                        laneEntryAddr = laneTable + *(int *)(operandRecord + 0x14c) * 4;
                        laneWordInsert10 = laneTagValue << 0x18 |
                                   (*(byte *)(laneEntryAddr + 3) & 0xc0) << 0x18 | laneWordInsert10 & 0xffffff;
                        *(char *)(laneEntryAddr + 3) = (char)(laneWordInsert10 >> 0x18);
                        laneEntryAddr = laneTable + *(int *)(operandRecord + 0x14c) * 4;
                        laneWordInsert11 = (uint)*(byte *)(laneEntryAddr + 3) << 0x18 | laneWordInsert11 & 0xffffff |
                                   0x80000000;
                        *(char *)(laneEntryAddr + 3) = (char)(laneWordInsert11 >> 0x18);
                        laneEntryAddr = laneTable + *(int *)(operandRecord + 0x14c) * 4;
                        laneWordInsert12 = (uint)*(byte *)(laneEntryAddr + laneIndex) << 0x18 | laneWordInsert12 & 0xffffff |
                                   0x80000000;
                        *(char *)(laneEntryAddr + laneIndex) = (char)(laneWordInsert12 >> 0x18);
                        chainDestRecord = IRInst__getOperandRecord(operandRecord,0);
                        if ((*(char *)(chainDestRecord + 0x13) != '\x01') ||
                           ((*(uint *)(operandRecord + 0x14) & 0x200) == 0)) break;
                      }
                    }
                    laneWordInsert13 = laneTagValue << 0x18 | (laneWord & 0xc0) << 0x18 | laneWordInsert13 & 0xffffff;
                    laneWord = CONCAT31((*(unsigned int *)((unsigned char *)&(laneWord) + 0)),(char)(laneWordInsert13 >> 0x18));
                  }
                  goto LAB_0013ae00;
                }
              }
LAB_0013ae10: ;
            }
            nextInst = (int *)inst[2];
          }
          lookaheadInst = (int *)nextInst[2];
          inst = nextInst;
        } while ((int *)nextInst[2] != (int *)0x0);
        blockCursor = *(int *)(currentBlock + 8);
      }
      nextBlock = *(int *)(blockCursor + 8);
      currentBlock = blockCursor;
    } while (*(int *)(blockCursor + 8) != 0);
    blockCursor = *(int *)(blockListObject + 8);
  }
  nextBlock = *(int *)(blockCursor + 8);
  while (nextBlockB = nextBlock, nextBlockB != 0) {
    inst = *(int **)(blockCursor + 0x98);
    lookaheadInst = (int *)inst[2];
    if ((int *)inst[2] != (int *)0x0) {
      do {
        nextInst = lookaheadInst;
        if ((inst[5] & 1U) != 0) {
          flagResult = (**(code **)(*inst + 0x24))(inst);
          if ((flagResult != 0) &&
             (flagResult = OpcodeTraits__instFlagBit2(*(undefined4 *)(pass + 8),inst), flagResult == 0)) {
            laneTag = (uint)*(byte *)(inst[0x53] * 4 + laneTable + 3);
            laneWordInsert14 = laneTag << 0x18 | laneWordInsert14 & 0xffffff;
            if ((int)laneWordInsert14 < 0) {
              laneWordInsert15 = laneTag << 0x18 | laneWordInsert15 & 0xffffff;
              laneTag = laneTag & 0x3f;
              IRInst__getOperandRecord(inst,0);
              if (laneTag != 3) {
                destRecord = IRInst__getOperandRecord(inst,0);
                SelectWord__selectWhereMasked(&maskedSelectWord,*(undefined4 *)(destRecord + 0x10),inst[3]);
                laneWord = maskedSelectWord;
                savedLaneWord = laneWord;
                (*(unsigned char *)((unsigned char *)&(laneWord) + 3)) = (char)maskedSelectWord;
                laneByteZero = (char)laneWord == '\0';
                laneWord = savedLaneWord;
                if (laneByteZero) {
                  (*(unsigned int *)((unsigned char *)&(laneWord) + 0)) = (undefined3)(maskedSelectWord >> 8);
                  laneWord = CONCAT31((*(unsigned int *)((unsigned char *)&(laneWord) + 0)),1);
                  *(undefined1 *)((int)&laneWord + laneTag) = 0;
                  opcodeDesc = inst[0x22];
                  *(undefined1 *)((int)inst + 0xf) = 0;
                  *(undefined1 *)((int)inst + laneTag + 0xc) = 1;
                  flagResult = OpcodeTraits__flagBit7(*(undefined4 *)(opcodeDesc + 8),*(undefined4 *)(pass + 8));
                  if (flagResult == 0) {
                    for (operandIndex = 1; operandLimit = (**(code **)(*inst + 0x14))(inst),
                        operandIndex <= operandLimit; operandIndex = operandIndex + 1) {
                      sourceInstB = IRInst__getOperandSource(inst,operandIndex);
                      operandRecordB = IRInst__getOperandRecord(inst,operandIndex);
                      if (*(char *)(laneTag + operandRecordB + 0x10) != '\x04') {
                        IRInst__getOperandRecord(inst,operandIndex);
                        IRInst__getOperandRecord(inst,operandIndex);
                      }
                      setComponentFn = *(code **)(*inst + 0x88);
                      operandRecordB = IRInst__getOperandRecord(inst,operandIndex);
                      (*setComponentFn)(inst,operandIndex,laneTag,*(undefined1 *)(operandRecordB + 0x13));
                      (**(code **)(*inst + 0x88))
                                (inst,operandIndex,3,4,staleArg5,staleArg6,*(code **)(*inst + 0x88));
                      if (*(int *)(sourceInstB + 0x98) == 0x33) {
                        (**(code **)(*inst + 0x88))(inst,operandIndex,laneTag,laneTag);
                        *(undefined1 *)(sourceInstB + laneTag + 0x9c) = 0;
                        *(undefined1 *)(sourceInstB + laneTag + 0xc) = 1;
                      }
                    }
                  }
                  targetInfo = *(int **)(*(int *)(pass + 8) + 0x30c);
                  flagResult = (**(code **)(*targetInfo + 0x7c))(targetInfo,inst);
                  if (flagResult != 0) {
                    inst[0x27] = laneWord;
                  }
                }
              }
            }
          }
          for (operandIndex = 1; operandLimit = (**(code **)(*inst + 0x14))(inst), operandIndex <= operandLimit;
              operandIndex = operandIndex + 1) {
            sourceInst = (int *)IRInst__getOperandSource(inst,operandIndex);
            sourceId = sourceInst[0x53];
            predicateResult = (**(code **)(*sourceInst + 0x24))(sourceInst);
            if (predicateResult != 0) {
              laneEntryPtr = laneTable + sourceId * 4;
              laneTagByte = *(byte *)(laneEntryPtr + 3);
              if (((int)((uint)laneTagByte << 0x18) < 0) && ((laneTagByte & 0x3f) != 3)) {
                componentIdxB = 0;
                do {
                  operandRecord = IRInst__getOperandRecord(inst,operandIndex);
                  if (*(char *)(componentIdxB + operandRecord + 0x10) == '\x03') {
                    laneTagB = (uint)*(byte *)(laneEntryPtr + 3);
                    laneWordInsert16 = laneTagB << 0x18 | laneWordInsert16 & 0xffffff;
                    (**(code **)(*inst + 0x88))
                              (inst,operandIndex,componentIdxB,laneTagB & 0x3f,staleArg5,staleArg6,
                               *(code **)(*inst + 0x88));
                  }
                  moreComponentsB = componentIdxB != 3;
                  componentIdxB = componentIdxB + 1;
                } while (moreComponentsB);
              }
            }
          }
          nextInst = (int *)inst[2];
        }
        lookaheadInst = (int *)nextInst[2];
        inst = nextInst;
      } while ((int *)nextInst[2] != (int *)0x0);
      nextBlockB = *(int *)(blockCursor + 8);
    }
    blockCursor = nextBlockB;
    nextBlock = *(int *)(nextBlockB + 8);
  }
  return Arena__free(*(undefined4 *)(*(int *)(pass + 8) + 0x378),laneTable);
}

/* FUN_0013b1e8 @ 0x13b1e8 (520 bytes) */
int FUN_0013b1e8(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int operandVReg;
  int iVar6;
  int *piVar7;
  uint loopIndex;
  int *piVar9;
  uint *puVar10;
  int iVar11;
  
  piVar7 = (int *)0x0;
  for (loopIndex = 0; iVar6 = IRInst__useCount(param_1,param_2), (int)loopIndex < iVar6; loopIndex = loopIndex + 1) {
    puVar10 = *(uint **)(param_1 + 0x10);
    if (loopIndex < *puVar10) {
      uVar3 = puVar10[1];
      if (uVar3 <= loopIndex) {
        _memset(uVar3 * 4 + puVar10[2],0,(loopIndex - uVar3) * 4 + 4);
        puVar10[1] = loopIndex + 1;
      }
      piVar4 = (int *)(loopIndex * 4 + puVar10[2]);
    }
    else {
      piVar4 = (int *)Vector__elementRefGrow(puVar10,loopIndex);
    }
    iVar6 = *piVar4;
    piVar4 = *(int **)(iVar6 + 0x158);
    if ((piVar4[3] & 0x40U) != 0) goto LAB_0013b3c4;
    if (*(int *)(*(int *)(iVar6 + 0x88) + 8) == 0x8e) {
      iVar2 = 0;
      do {
        iVar11 = iVar2;
        if (*(int *)(iVar6 + 0x84) <= iVar11) goto LAB_0013b2d8;
        operandVReg = IRInst__getOperandSource(iVar6,iVar11 + 1);
        iVar2 = iVar11 + 1;
      } while (param_1 != operandVReg);
      piVar4 = (int *)Block__getPredecessor(piVar4,iVar11);
    }
LAB_0013b2d8:
    iVar6 = (**(code **)(*piVar4 + 0x24))(piVar4);
    if ((iVar6 != 0) && (piVar4 = (int *)Block__getPredecessor(piVar4,0), piVar4 == (int *)0x0))
    goto LAB_0013b3c4;
    bVar1 = piVar7 == (int *)0x0;
    piVar9 = piVar4;
    if ((!bVar1) && (piVar9 = piVar7, piVar7 != piVar4)) {
      do {
        iVar2 = piVar4[0x2f];
        iVar6 = piVar7[0x2f];
        if (iVar6 < iVar2) {
          piVar4 = (int *)piVar4[0x3c];
LAB_0013b318:
          if (piVar4 == (int *)0x0) goto LAB_0013b3c4;
          bVar1 = piVar7 == (int *)0x0;
        }
        else if (iVar2 < iVar6) {
          piVar7 = (int *)piVar7[0x3c];
          bVar1 = piVar7 == (int *)0x0;
        }
        else if (iVar2 == iVar6) {
          piVar4 = (int *)piVar4[0x3c];
          piVar7 = (int *)piVar7[0x3c];
          goto LAB_0013b318;
        }
        piVar9 = piVar4;
      } while ((!bVar1) && (piVar9 = piVar7, piVar7 != piVar4));
    }
    piVar7 = piVar9;
  }
  iVar6 = Block__successorCount(piVar7);
  if (((1 < iVar6) && (piVar7 = (int *)Block__getPredecessor(piVar7,0), piVar7 == *(int **)(param_1 + 0x158))
      ) || (iVar6 = ((int (*)())FUN_00139294)(piVar7,*(undefined4 *)(param_2 + 0x3a0)), iVar6 == 0)) {
LAB_0013b3c4:
    piVar7 = (int *)0x0;
  }
  return piVar7;
}

/* Program__hoistFetchInsts @ 0x13b3f0 (172 bytes) */
int Program__hoistFetchInsts(param_1)
  int param_1;
{
  int vcall2cResult;
  int vcall34Result;
  int vcall28Result;
  int vcall24Result;
  int predecessorCountResult;
  int operandSource;
  undefined4 vectorData;
  undefined4 arena;
  undefined4 *vectorAlloc;
  uint loopIndex3;
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 *allocation;
  int iVar6;
  int vcall24ResultB;
  int *piVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  uint uVar11;
  int *piVar12;
  uint loopIndex;
  uint *puVar14;
  int iVar15;
  uint uVar16;
  uint *puVar17;
  int loopIndex2;
  int *piVar19;
  int *piVar20;
  undefined4 operandSourceB;
  int *piVar22;
  int iVar23;
  uint uVar24;
  uint *puVar25;
  
  iVar23 = *(int *)(param_1 + 0x3a8);
  while ((iVar23 != 0 && (predecessorCountResult = Block__predecessorCount(iVar23), predecessorCountResult != 0))) {
    *(uint *)(iVar23 + 0xc) = *(uint *)(iVar23 + 0xc) | 0x40;
    iVar23 = *(int *)(iVar23 + 0xf0);
  }
  iVar15 = *(int *)(param_1 + 0x3a0);
  arena = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  allocation = (undefined4 *)Arena__alloc(arena,0x14);
  puVar14 = allocation + 1;
  *allocation = arena;
  allocation[1] = 2;
  allocation[2] = 0;
  allocation[4] = arena;
  vectorData = Arena__alloc(arena,8);
  allocation[3] = vectorData;
  iVar23 = *(int *)(param_1 + 900);
  for (iVar4 = *(int *)(*(int *)(param_1 + 900) + 8); iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    if (iVar23 != iVar15) {
      iVar4 = ((int (*)())FUN_00139294)(iVar23,iVar15);
      if (iVar4 != 0) {
        iVar4 = *(int *)(iVar23 + 0x98);
        for (iVar3 = *(int *)(*(int *)(iVar23 + 0x98) + 8); iVar3 != 0; iVar3 = *(int *)(iVar3 + 8))
        {
          loopIndex2 = 0;
          if ((*(uint *)(iVar4 + 0x14) & 1) != 0) {
            while (loopIndex2 < *(int *)(iVar4 + 0x84)) {
              loopIndex2 = loopIndex2 + 1;
              operandSource = IRInst__getOperandSource(iVar4,loopIndex2);
              iVar6 = ((int (*)())IRInst__isOpcodeInSet139344)(operandSource);
              if ((((iVar6 != 0) && (*(int *)(*(int *)(operandSource + 0x158) + 0xb8) == 0)) &&
                  (iVar6 = ((int (*)())FUN_0013b1e8)(operandSource,param_1), iVar6 != 0)) &&
                 (iVar6 != *(int *)(operandSource + 0x158))) {
                piVar8 = *(int **)(iVar6 + 0xf0);
                while ((piVar8 != (int *)0x0 &&
                       (vcall24ResultB = (**(code **)(*piVar8 + 0x24))(piVar8), vcall24ResultB == 0))) {
                  uVar24 = piVar8[3];
                  if ((uVar24 & 0x40) != 0) goto LAB_0013b588;
                  piVar8 = (int *)piVar8[0x3c];
                }
                uVar24 = piVar8[3];
LAB_0013b588:
                if ((uVar24 & 0x800) == 0) {
                  uVar24 = allocation[2];
                  if (uVar24 < *puVar14) {
                    _memset((void *)(uVar24 * 4 + allocation[3]),0,4);
                    piVar8 = (int *)(uVar24 * 4 + allocation[3]);
                    allocation[2] = uVar24 + 1;
                  }
                  else {
                    piVar8 = (int *)Vector__elementRefGrow(puVar14,uVar24);
                  }
                  *piVar8 = operandSource;
                  IRInst__unlinkAndClearFlag0(operandSource);
                  *(uint *)(operandSource + 0x14) = *(uint *)(operandSource + 0x14) | 1;
                  Block__prependInst(iVar6,operandSource);
                }
              }
            }
            iVar3 = *(int *)(iVar4 + 8);
          }
          iVar4 = iVar3;
        }
      }
      iVar4 = *(int *)(iVar23 + 8);
    }
    iVar23 = iVar4;
  }
  uVar24 = allocation[2];
  if (uVar24 == 0) {
    return;
  }
  loopIndex = 0;
code_r0x0013b658:
  if (loopIndex < *puVar14) {
    if (uVar24 <= loopIndex) {
      _memset((void *)(uVar24 * 4 + allocation[3]),0,(loopIndex - uVar24) * 4 + 4);
      allocation[2] = loopIndex + 1;
    }
    piVar8 = (int *)(loopIndex * 4 + allocation[3]);
  }
  else {
    piVar8 = (int *)Vector__elementRefGrow(puVar14,loopIndex);
  }
  iVar23 = *piVar8;
  piVar8 = *(int **)(iVar23 + 0x158);
  if (piVar8 == (int *)0x0) {
    piVar20 = (int *)0x0;
    piVar12 = (int *)0x0;
  }
  else {
    piVar12 = (int *)0x0;
    piVar22 = piVar8;
    do {
      iVar4 = (**(code **)(*piVar22 + 0x14))(piVar22);
      if (iVar4 != 0) goto code_r0x0013ba08;
      vcall24Result = (**(code **)(*piVar22 + 0x24))(piVar22);
      piVar20 = piVar22;
      if (vcall24Result != 0) break;
      vcall28Result = (**(code **)(*piVar22 + 0x28))(piVar22);
      if (vcall28Result == 0) {
        vcall34Result = (**(code **)(*piVar22 + 0x34))(piVar22);
        if (vcall34Result == 0) {
          vcall2cResult = (**(code **)(*piVar22 + 0x2c))(piVar22);
          if (vcall2cResult == 0) {
            piVar20 = (int *)Block__getPredecessor(piVar22,0);
          }
          else {
            piVar20 = (int *)Block__findSimplePredecessor(piVar22);
          }
        }
        else {
          piVar22 = (int *)piVar22[0x4b];
          piVar20 = (int *)Block__findSimplePredecessor(piVar22);
        }
      }
      else {
        piVar22 = (int *)piVar22[0x4b];
        piVar20 = (int *)Block__getPredecessor(piVar22,0);
      }
      piVar12 = piVar22;
      piVar22 = piVar20;
    } while (piVar20 != (int *)0x0);
  }
  arena = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
  puVar9 = (undefined4 *)Arena__alloc(arena,0x134);
  *puVar9 = arena;
  piVar22 = puVar9 + 1;
  AnyBlock__ctor_ea3c0(piVar22,*(undefined4 *)(param_1 + 8));
  if (piVar12 == (int *)piVar20[0x4e]) {
    piVar20[0x4e] = (int)piVar22;
  }
  Program__insertBlockBefore(param_1,piVar12,piVar22);
  FUN_000e977c(piVar20,piVar12,piVar22);
  Block__connect(piVar22,piVar12);
  piVar19 = (int *)piVar20[0x4f];
  piVar20 = piVar8;
  piVar12 = piVar8;
  do {
    vcall28Result = (**(code **)(*piVar12 + 0x28))(piVar12);
    if ((vcall28Result != 0) && (piVar12 == piVar19)) {
      iVar4 = 0;
      for (loopIndex3 = 1; loopIndex3 <= *(uint *)(piVar12[0x35] + 4); loopIndex3 = loopIndex3 + 1) {
        piVar2 = *(int **)(*(int *)(piVar12[0x35] + 8) + iVar4);
        if ((piVar2 != (int *)0x0) && (piVar20 != piVar2)) goto code_r0x0013b8e4;
        iVar4 = iVar4 + 4;
      }
      piVar2 = (int *)0x0;
code_r0x0013b8e4:
      iVar4 = (**(code **)(*piVar2 + 0x18))(piVar2);
      if (iVar4 == 0) break;
    }
    vcall24Result = (**(code **)(*piVar12 + 0x24))(piVar12);
    piVar20 = piVar12;
    if (vcall24Result != 0) {
      piVar20 = (int *)Block__getSuccessor(piVar12[0x4f],0);
    }
    iVar4 = (**(code **)(*piVar20 + 0x2c))(piVar20);
    if (iVar4 != 0) {
      piVar20 = (int *)piVar20[0x55];
    }
    piVar2 = (int *)Block__getSuccessor(piVar20,0);
    piVar20 = piVar12;
    piVar12 = piVar2;
  } while( true );
  arena = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
  puVar9 = (undefined4 *)Arena__alloc(arena,0x134);
  *puVar9 = arena;
  puVar10 = puVar9 + 1;
  Block__ctor_ea148(puVar10,*(undefined4 *)(param_1 + 8));
  puVar1 = PTR_DAT_001e9134;
  puVar9[0x4c] = piVar22;
  puVar9[1] = puVar1 + 8;
  Program__insertBlockAfter(param_1,piVar2,puVar10);
  FUN_000e9948(piVar12,piVar2,puVar10);
  Block__connect(piVar2,puVar10);
code_r0x0013ba08:
  arena = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  vectorAlloc = (undefined4 *)Arena__alloc(arena,0x14);
  puVar17 = vectorAlloc + 1;
  *vectorAlloc = arena;
  vectorAlloc[1] = 2;
  vectorAlloc[2] = 0;
  vectorAlloc[4] = arena;
  vectorData = Arena__alloc(arena,8);
  vectorAlloc[3] = vectorData;
  operandSourceB = IRInst__getOperandSource(iVar23,1);
  uVar24 = vectorAlloc[2];
  if (uVar24 < (uint)vectorAlloc[1]) {
    _memset((void *)(uVar24 * 4 + vectorAlloc[3]),0,4);
    puVar10 = (undefined4 *)(uVar24 * 4 + vectorAlloc[3]);
    vectorAlloc[2] = uVar24 + 1;
  }
  else {
    puVar10 = (undefined4 *)Vector__elementRefGrow(puVar17,uVar24);
  }
  *puVar10 = operandSourceB;
  uVar24 = vectorAlloc[2];
  if (uVar24 != 0) {
    uVar11 = 0;
    do {
      if (uVar11 < *puVar17) {
        if (uVar24 <= uVar11) {
          _memset((void *)(uVar24 * 4 + vectorAlloc[3]),0,(uVar11 - uVar24) * 4 + 4);
          vectorAlloc[2] = uVar11 + 1;
        }
        puVar10 = (undefined4 *)(uVar11 * 4 + vectorAlloc[3]);
      }
      else {
        puVar10 = (undefined4 *)Vector__elementRefGrow(puVar17,uVar11);
      }
      uVar16 = uVar11 + 1;
      piVar20 = (int *)*puVar10;
      if ((int *)piVar20[0x56] != piVar22) {
        if (uVar11 == 0) {
          puVar25 = (uint *)piVar22[0x4b];
          uVar24 = puVar25[1];
          if (uVar24 < *puVar25) {
            _memset((void *)(uVar24 * 4 + puVar25[2]),0,4);
            puVar10 = (undefined4 *)(uVar24 * 4 + puVar25[2]);
            puVar25[1] = uVar24 + 1;
          }
          else {
            puVar10 = (undefined4 *)Vector__elementRefGrow(puVar25,uVar24);
          }
          *puVar10 = piVar20;
        }
        if ((((piVar20[5] & 8U) == 0) && (*(int *)(piVar20[0x22] + 8) != 0x8e)) &&
           (piVar20[0x56] != *(int *)(param_1 + 0x3a0))) {
          uVar24 = 0;
          iVar23 = (**(code **)(*piVar20 + 0x50))(piVar20);
          if (iVar23 == 0) {
            for (; iVar23 = IRInst__useCount(piVar20,param_1), (int)uVar24 < iVar23; uVar24 = uVar24 + 1
                ) {
              puVar25 = (uint *)piVar20[4];
              if (uVar24 < *puVar25) {
                uVar11 = puVar25[1];
                if (uVar11 <= uVar24) {
                  _memset((void *)(uVar11 * 4 + puVar25[2]),0,(uVar24 - uVar11) * 4 + 4);
                  puVar25[1] = uVar24 + 1;
                }
                piVar12 = (int *)(uVar24 * 4 + puVar25[2]);
              }
              else {
                piVar12 = (int *)Vector__elementRefGrow(puVar25,uVar24);
              }
              if ((piVar22 != *(int **)(*piVar12 + 0x158)) &&
                 (piVar8 != *(int **)(*piVar12 + 0x158))) goto code_r0x0013bd34;
            }
            IRInst__unlinkAndClearFlag0(piVar20);
            piVar20[5] = piVar20[5] | 1;
            Block__prependInst(piVar22,piVar20);
            for (iVar23 = 1; iVar4 = (**(code **)(*piVar20 + 0x14))(piVar20), iVar23 < iVar4;
                iVar23 = iVar23 + 1) {
              operandSourceB = IRInst__getOperandSource(piVar20,iVar23);
              uVar24 = vectorAlloc[2];
              if (uVar24 < *puVar17) {
                _memset((void *)(uVar24 * 4 + vectorAlloc[3]),0,4);
                puVar10 = (undefined4 *)(uVar24 * 4 + vectorAlloc[3]);
                vectorAlloc[2] = uVar24 + 1;
              }
              else {
                puVar10 = (undefined4 *)Vector__elementRefGrow(puVar17,uVar24);
              }
              *puVar10 = operandSourceB;
            }
          }
        }
      }
code_r0x0013bd34:
      uVar24 = vectorAlloc[2];
      uVar11 = uVar16;
    } while (uVar16 < uVar24);
  }
  uVar24 = allocation[2];
  loopIndex = loopIndex + 1;
  if (uVar24 <= loopIndex) {
    return;
  }
  goto code_r0x0013b658;
}

/* Program__eliminateDeadInstsAndRecountUses @ 0x13bd68 (1124 bytes) */
int Program__eliminateDeadInstsAndRecountUses(program, verifyCounts)
  int program;
  int verifyCounts;
{
  uint countBefore;
  int slotByteOffset;
  int operandSource;
  int loopIndex;
  bool skipVerify;
  int instVector;
  int iVar3;
  int iVar4;
  int *piVar5;
  int savedUseCounts;
  int *piVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint loopIndex2;
  undefined4 consistent;
  int *piVar14;
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - vecCapacity/vecCount/vecData/vecArena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_54_buf [0x10];
  #define vecCapacity (*(uint *)(local_54_buf + 0x00))
  #define vecCount (*(uint *)(local_54_buf + 0x04))
  #define vecData (*(int *)(local_54_buf + 0x08))
  #define vecArena (*(undefined4 *)(local_54_buf + 0x0c))
  
  skipVerify = verifyCounts == 0;
  iVar11 = *(int *)(program + 0x2ac);
  iVar9 = *(int *)(program + PROG_compiler);
  *(int *)(program + 0x2ac) = iVar11 + 1;
  instVector = *(int *)(iVar9 + 0x324);
  if (skipVerify) {
    savedUseCounts = 0;
  }
  else {
    savedUseCounts = Arena__alloc(*(undefined4 *)(iVar9 + 0x378),instVector << 2);
    iVar9 = *(int *)(program + PROG_blockListHead);
    for (iVar4 = *(int *)(*(int *)(program + PROG_blockListHead) + 8); iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
      iVar3 = *(int *)(*(int *)(iVar9 + 0x98) + 8);
      iVar10 = *(int *)(iVar9 + 0x98);
      if (iVar3 != 0) {
        do {
          iVar4 = iVar3;
          if ((*(uint *)(iVar10 + 0x14) & 1) != 0) {
            iVar4 = *(int *)(iVar10 + 0x160) - *(int *)(program + PROG_useEpoch);
            if (iVar4 < 0) {
              iVar4 = 0;
            }
            *(int *)(*(int *)(iVar10 + 0x14c) * 4 + savedUseCounts) = iVar4;
            iVar4 = *(int *)(iVar10 + 8);
          }
          iVar3 = *(int *)(iVar4 + 8);
          iVar10 = iVar4;
        } while (*(int *)(iVar4 + 8) != 0);
        iVar4 = *(int *)(iVar9 + 8);
      }
      iVar9 = iVar4;
    }
    iVar9 = *(int *)(program + PROG_compiler);
  }
  iVar4 = 0;
  *(int *)(program + PROG_visitStamp) = *(int *)(program + PROG_visitStamp) + 1;
  *(int *)(program + PROG_useEpoch) = instVector * 4 + *(int *)(program + PROG_useEpoch);
  vecArena = *(undefined4 *)(iVar9 + 0x378);
  vecCapacity = 2;
  vecCount = 0;
  vecData = Arena__alloc(vecArena,8);
  instVector = *(int *)(program + PROG_instructionVector);
  for (loopIndex2 = 1; loopIndex2 <= *(uint *)(instVector + 4); loopIndex2 = loopIndex2 + 1) {
    iVar9 = *(int *)(*(int *)(instVector + 8) + iVar4);
    if ((*(uint *)(iVar9 + 0x14) & 1) != 0) {
      instVector = IRInst__getOperandRecord(iVar9,0);
      countBefore = vecCount;
      if ((*(int *)(instVector + 0x10) != DAT_001b0014) &&
         (*(int *)(program + PROG_visitStamp) != *(int *)(iVar9 + 0x150))) {
        *(int *)(iVar9 + 0x150) = *(int *)(program + PROG_visitStamp);
        if (vecCount < vecCapacity) {
          instVector = vecCount * 4;
          _memset(instVector + vecData,0,4);
          vecCount = countBefore + 1;
          piVar7 = (int *)(instVector + vecData);
        }
        else {
          piVar7 = (int *)Vector__elementRefGrow(&vecCapacity,vecCount);
        }
        *piVar7 = iVar9;
        do {
          uVar8 = vecCount - 1;
          piVar7 = (int *)0x0;
          if (uVar8 < vecCount) {
            piVar7 = (int *)(uVar8 * 4 + vecData);
          }
          instVector = *piVar7;
          Vector__removeAt(&vecCapacity,uVar8);
          if (0 < *(int *)(instVector + 0x84)) {
            loopIndex = 1;
            do {
              operandSource = IRInst__getOperandSource(instVector,loopIndex);
              countBefore = vecCount;
              if (operandSource != 0) {
                if (*(int *)(program + PROG_useEpoch) < *(int *)(operandSource + 0x160)) {
                  *(int *)(operandSource + 0x160) = *(int *)(operandSource + 0x160) + 1;
                }
                else {
                  *(int *)(operandSource + 0x160) = *(int *)(program + PROG_useEpoch) + 1;
                }
                if (*(int *)(program + PROG_visitStamp) != *(int *)(operandSource + 0x150)) {
                  *(int *)(operandSource + 0x150) = *(int *)(program + PROG_visitStamp);
                  if (vecCount < vecCapacity) {
                    slotByteOffset = vecCount * 4;
                    _memset(slotByteOffset + vecData,0,4);
                    vecCount = countBefore + 1;
                    piVar7 = (int *)(slotByteOffset + vecData);
                  }
                  else {
                    piVar7 = (int *)Vector__elementRefGrow(&vecCapacity,vecCount);
                  }
                  *piVar7 = operandSource;
                }
              }
              loopIndex = loopIndex + 1;
            } while (loopIndex <= *(int *)(instVector + 0x84));
          }
        } while (vecCount != 0);
      }
      instVector = *(int *)(program + PROG_instructionVector);
    }
    iVar4 = iVar4 + 4;
  }
  instVector = *(int *)(*(int *)(program + PROG_blockListHead) + 8);
  if (instVector == 0) {
    consistent = 1;
  }
  else {
    consistent = 1;
    iVar11 = iVar11 * 4 + program;
    iVar9 = *(int *)(program + PROG_blockListHead);
    do {
      iVar4 = instVector;
      piVar7 = (int *)(*(int **)(iVar9 + 0x98))[2];
      piVar14 = *(int **)(iVar9 + 0x98);
      if (piVar7 != (int *)0x0) {
        do {
          piVar5 = piVar7;
          if ((piVar14[5] & 1U) != 0) {
            instVector = (**(code **)(*piVar14 + 0x34))(piVar14);
            if ((instVector == 0) && (instVector = (**(code **)(*piVar14 + 0x38))(piVar14), instVector == 0)) {
              if ((!skipVerify) && (instVector = (**(code **)(*piVar14 + 0x48))(piVar14), instVector == 0)) {
                instVector = piVar14[0x58] - *(int *)(program + PROG_useEpoch);
                if (instVector < 0) {
                  instVector = 0;
                }
                if (*(int *)(piVar14[0x53] * 4 + savedUseCounts) != instVector) {
                  consistent = 0;
                }
              }
              if (((*(int *)(program + PROG_visitStamp) != piVar14[0x54]) && ((piVar14[5] & 8U) == 0)) &&
                 ((piVar14[5] & 0x10U) == 0)) {
                (**(code **)(*piVar14 + 0x10))(piVar14,*(undefined4 *)(program + PROG_compiler));
                if ((piVar14[0x26] != 2) && (piVar14[0x26] != 0x33)) {
                  *(int *)(iVar11 + 0x2b0) = *(int *)(iVar11 + 0x2b0) + 1;
                  piVar5 = (int *)piVar14[2];
                  goto LAB_0013c188;
                }
              }
            }
            piVar5 = (int *)piVar14[2];
          }
LAB_0013c188:
          piVar7 = (int *)piVar5[2];
          piVar14 = piVar5;
        } while ((int *)piVar5[2] != (int *)0x0);
        iVar4 = *(int *)(iVar9 + 8);
      }
      instVector = *(int *)(iVar4 + 8);
      iVar9 = iVar4;
    } while (*(int *)(iVar4 + 8) != 0);
  }
  if (!skipVerify) {
    Arena__free(*(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaB),savedUseCounts);
  }
  Arena__free(vecArena,vecData);
  return consistent;
}
#undef vecCapacity
#undef vecCount
#undef vecData
#undef vecArena

/* FUN_0013c210 @ 0x13c210 (964 bytes) */
int FUN_0013c210(program)
  int program;
{
  int slotByteOffset;
  int sourceDef;
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int callResult;
  undefined4 uVar6;
  uint uVar7;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined4 in_r10;
  int iVar8;
  uint loopIndex;
  undefined4 uVar10;
  uint countBefore;
  int local_58;
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - vecCapacity/vecCount/vecData/vecArena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_54_buf [0x10];
  #define vecCapacity (*(uint *)(local_54_buf + 0x00))
  #define vecCount (*(uint *)(local_54_buf + 0x04))
  #define vecData (*(int *)(local_54_buf + 0x08))
  #define vecArena (*(undefined4 *)(local_54_buf + 0x0c))
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - vec2Capacity/vec2Count/vec2Data/vec2Arena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_44_buf [0x10];
  #define vec2Capacity (*(uint *)(local_44_buf + 0x00))
  #define vec2Count (*(uint *)(local_44_buf + 0x04))
  #define vec2Data (*(int *)(local_44_buf + 0x08))
  #define vec2Arena (*(undefined4 *)(local_44_buf + 0x0c))
  
  iVar2 = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),0x1c);
  if ((((iVar2 == 0) && (iVar2 = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),0x1d), iVar2 == 0)) &&
      (iVar2 = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),0x39), iVar2 == 0)) &&
     (iVar2 = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),0x1b), iVar2 == 0)) {
    Compiler__logf(*(undefined4 *)(program + 8),
                 "Special : all peephole flags off -> bypass Rewrite()\n",in_r5,in_r6,in_r7,in_r8,
                 in_r9,in_r10);
  }
  *(int *)(program + 0x474) = *(int *)(program + 0x474) + 1;
  vecArena = *(undefined4 *)(*(int *)(program + 8) + 0x378);
  vecCount = 0;
  vecCapacity = 2;
  vecData = Arena__alloc(vecArena,8);
  vec2Arena = *(undefined4 *)(*(int *)(program + 8) + 0x378);
  vec2Capacity = 2;
  vec2Count = 0;
  vec2Data = Arena__alloc(vec2Arena,8);
  iVar2 = *(int *)(program + 0x3c4);
  loopIndex = 1;
  iVar8 = 0;
  do {
    countBefore = vecCount;
    if (*(uint *)(iVar2 + 4) < loopIndex) {
      Arena__free(vec2Arena,vec2Data);
      Arena__free(vecArena,vecData);
      return;
    }
    local_58 = *(int *)(*(int *)(iVar2 + 8) + iVar8);
    if ((*(uint *)(local_58 + 0x14) & 1) != 0) {
      if (vecCount < vecCapacity) {
        slotByteOffset = vecCount * 4;
        _memset(slotByteOffset + vecData,0,4);
        vecCount = countBefore + 1;
        puVar3 = (undefined4 *)(slotByteOffset + vecData);
      }
      else {
        puVar3 = (undefined4 *)Vector__elementRefGrow(&vecCapacity,vecCount);
      }
      countBefore = vec2Count;
      *puVar3 = 0;
      if (vec2Count < vec2Capacity) {
        slotByteOffset = vec2Count * 4;
        _memset(slotByteOffset + vec2Data,0,4);
        vec2Count = countBefore + 1;
        puVar3 = (undefined4 *)(slotByteOffset + vec2Data);
      }
      else {
        puVar3 = (undefined4 *)Vector__elementRefGrow(&vec2Capacity,vec2Count);
      }
      *puVar3 = 0;
      bVar1 = true;
      countBefore = vecCount;
      while (countBefore != 0) {
        if (bVar1) {
          if ((local_58 == 0) || (*(int *)(program + 0x474) == *(int *)(local_58 + 0x150))) {
            bVar1 = false;
          }
          else {
            *(int *)(local_58 + 0x150) = *(int *)(program + 0x474);
            sourceDef = IRInst__getOperandSource(local_58,1);
            countBefore = vecCount;
            if (sourceDef == 0) {
              puVar3 = (undefined4 *)0x0;
              if (vecCount - 1 < vecCount) {
                puVar3 = (undefined4 *)((vecCount - 1) * 4 + vecData);
              }
              uVar10 = *puVar3;
LAB_0013c528:
              uVar6 = ((int (*)())FUN_0013922c)(&vec2Capacity);
              ((int (*)())FUN_00139c78)(local_58,uVar10,uVar6,program);
              goto LAB_0013c540;
            }
            if (vecCount < vecCapacity) {
              slotByteOffset = vecCount * 4;
              _memset(slotByteOffset + vecData,0,4);
              vecCount = countBefore + 1;
              piVar4 = (int *)(slotByteOffset + vecData);
            }
            else {
              piVar4 = (int *)Vector__elementRefGrow(&vecCapacity,vecCount);
            }
            *piVar4 = local_58;
            uVar10 = ((int (*)())FUN_0013a38c)(local_58,&vec2Capacity,program);
LAB_0013c54c:
            local_58 = IRInst__getOperandSource(local_58,uVar10);
            bVar1 = true;
            countBefore = vecCount;
          }
        }
        else {
          uVar7 = countBefore - 1;
          piVar4 = (int *)0x0;
          if (uVar7 < countBefore) {
            piVar4 = (int *)(uVar7 * 4 + vecData);
          }
          iVar2 = *piVar4;
          if (iVar2 != 0) {
            if (local_58 != 0) {
              callResult = FUN_00139190(&vec2Capacity,*(undefined4 *)(iVar2 + 0x84));
              countBefore = vecCount;
              if (callResult == 0) {
                uVar10 = ((int (*)())FUN_0013a240)(&vec2Capacity);
                local_58 = iVar2;
                goto LAB_0013c54c;
              }
            }
            Vector__removeAt(&vecCapacity,countBefore - 1);
            Vector__removeAt(&vec2Capacity,vec2Count - 1);
            puVar3 = (undefined4 *)0x0;
            if (vecCount - 1 < vecCount) {
              puVar3 = (undefined4 *)((vecCount - 1) * 4 + vecData);
            }
            uVar10 = *puVar3;
            local_58 = iVar2;
            goto LAB_0013c528;
          }
          Vector__removeAt(&vecCapacity,uVar7);
          Vector__removeAt(&vec2Capacity,vec2Count - 1);
          local_58 = iVar2;
LAB_0013c540:
          bVar1 = false;
          countBefore = vecCount;
        }
      }
      iVar2 = *(int *)(program + 0x3c4);
    }
    loopIndex = loopIndex + 1;
    iVar8 = iVar8 + 4;
  } while( true );
}
#undef vecCapacity
#undef vecCount
#undef vecData
#undef vecArena
#undef vec2Capacity
#undef vec2Count
#undef vec2Data
#undef vec2Arena

/* Program__scanUsevectorChains @ 0x13c60c (1084 bytes) */
int Program__scanUsevectorChains(program)
  int program;
{
  uint countBefore;
  int slotByteOffsetB;
  int movAndShiftUsevectorEnabled;
  int slotByteOffset;
  bool descending;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int instByteOffset;
  uint loopIndex;
  int iVar11;
  int currentInst;
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - vecCapacity/vecCount/vecData/vecArena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_54_buf [0x10];
  #define vecCapacity (*(uint *)(local_54_buf + 0x00))
  #define vecCount (*(uint *)(local_54_buf + 0x04))
  #define vecData (*(int *)(local_54_buf + 0x08))
  #define vecArena (*(undefined4 *)(local_54_buf + 0x0c))
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - vec2Capacity/vec2Count/vec2Data/vec2Arena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_44_buf [0x10];
  #define vec2Capacity (*(uint *)(local_44_buf + 0x00))
  #define vec2Count (*(uint *)(local_44_buf + 0x04))
  #define vec2Data (*(int *)(local_44_buf + 0x08))
  #define vec2Arena (*(undefined4 *)(local_44_buf + 0x0c))
  
  *(int *)(program + PROG_visitStamp) = *(int *)(program + PROG_visitStamp) + 1;
  vecArena = *(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaB);
  vecCount = 0;
  vecCapacity = 2;
  vecData = Arena__alloc(vecArena,8);
  vec2Arena = *(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaB);
  vec2Capacity = 2;
  vec2Count = 0;
  vec2Data = Arena__alloc(vec2Arena,8);
  iVar8 = *(int *)(program + PROG_instructionVector);
  loopIndex = 1;
  instByteOffset = 0;
LAB_0013c9f4:
  countBefore = vecCount;
  if (*(uint *)(iVar8 + 4) < loopIndex) {
    Arena__free(vec2Arena,vec2Data);
    Arena__free(vecArena,vecData);
    return;
  }
  currentInst = *(int *)(instByteOffset + *(int *)(iVar8 + 8));
  if ((*(uint *)(currentInst + 0x14) & 1) != 0) {
    if (vecCount < vecCapacity) {
      slotByteOffsetB = vecCount * 4;
      _memset(slotByteOffsetB + vecData,0,4);
      vecCount = countBefore + 1;
      puVar4 = (undefined4 *)(slotByteOffsetB + vecData);
    }
    else {
      puVar4 = (undefined4 *)Vector__elementRefGrow(&vecCapacity,vecCount);
    }
    countBefore = vec2Count;
    *puVar4 = 0;
    if (vec2Count < vec2Capacity) {
      slotByteOffsetB = vec2Count * 4;
      _memset(slotByteOffsetB + vec2Data,0,4);
      vec2Count = countBefore + 1;
      puVar4 = (undefined4 *)(slotByteOffsetB + vec2Data);
    }
    else {
      puVar4 = (undefined4 *)Vector__elementRefGrow(&vec2Capacity,vec2Count);
    }
    *puVar4 = 0;
    descending = true;
    countBefore = vecCount;
LAB_0013c9e0:
    do {
      if (countBefore == 0) goto code_r0x0013c9e8;
      if (descending) {
        if (currentInst != 0) {
          movAndShiftUsevectorEnabled = Compiler__isOptionEnabled(*(undefined4 *)(program + PROG_compiler),0x14);
          if (movAndShiftUsevectorEnabled != 0) {
            currentInst = FUN_00147f54(currentInst,*(undefined4 *)(program + PROG_compiler));
          }
          countBefore = vecCount;
          if (*(int *)(program + PROG_visitStamp) != *(int *)(currentInst + 0x150)) {
            *(int *)(currentInst + 0x150) = *(int *)(program + PROG_visitStamp);
            iVar8 = IRInst__getOperandSource(currentInst,1);
            countBefore = vecCount;
            if (iVar8 == 0) goto LAB_0013c8f0;
            if (vecCount < vecCapacity) {
              slotByteOffsetB = vecCount * 4;
              _memset(slotByteOffsetB + vecData,0,4);
              vecCount = countBefore + 1;
              piVar5 = (int *)(slotByteOffsetB + vecData);
            }
            else {
              piVar5 = (int *)Vector__elementRefGrow(&vecCapacity,vecCount);
            }
            countBefore = vec2Count;
            *piVar5 = currentInst;
            if (vec2Count < vec2Capacity) {
              slotByteOffsetB = vec2Count * 4;
              _memset(slotByteOffsetB + vec2Data,0,4);
              vec2Count = countBefore + 1;
              puVar4 = (undefined4 *)(slotByteOffsetB + vec2Data);
            }
            else {
              puVar4 = (undefined4 *)Vector__elementRefGrow(&vec2Capacity,vec2Count);
            }
            *puVar4 = 1;
            currentInst = IRInst__getOperandSource(currentInst,1);
LAB_0013c9c8:
            descending = true;
            countBefore = vecCount;
            goto LAB_0013c9e0;
          }
        }
        descending = false;
        goto LAB_0013c9e0;
      }
      uVar7 = countBefore - 1;
      piVar5 = (int *)0x0;
      if (uVar7 < countBefore) {
        piVar5 = (int *)(uVar7 * 4 + vecData);
      }
      iVar8 = *piVar5;
      if (iVar8 == 0) {
        Vector__removeAt(&vecCapacity,uVar7);
        Vector__removeAt(&vec2Capacity,vec2Count - 1);
        currentInst = iVar8;
      }
      else {
        if (currentInst != 0) {
          piVar5 = (int *)0x0;
          uVar6 = vec2Count - 1;
          if (uVar6 < vec2Count) {
            piVar5 = (int *)(uVar6 * 4 + vec2Data);
          }
          if (*piVar5 != *(int *)(iVar8 + 0x84)) {
            piVar5 = (int *)0x0;
            if (uVar6 < vec2Count) {
              piVar5 = (int *)(uVar6 * 4 + vec2Data);
            }
            iVar11 = *piVar5;
            Vector__removeAt(&vec2Capacity,uVar6);
            countBefore = vec2Count;
            if (vec2Count < vec2Capacity) {
              slotByteOffset = vec2Count * 4;
              _memset(slotByteOffset + vec2Data,0,4);
              vec2Count = countBefore + 1;
              piVar5 = (int *)(slotByteOffset + vec2Data);
            }
            else {
              piVar5 = (int *)Vector__elementRefGrow(&vec2Capacity,vec2Count);
            }
            *piVar5 = iVar11 + 1;
            currentInst = IRInst__getOperandSource(iVar8,iVar11 + 1);
            goto LAB_0013c9c8;
          }
        }
        Vector__removeAt(&vecCapacity,uVar7);
        Vector__removeAt(&vec2Capacity,vec2Count - 1);
        currentInst = iVar8;
LAB_0013c8f0:
        puVar4 = (undefined4 *)0x0;
        if (vecCount - 1 < vecCount) {
          puVar4 = (undefined4 *)((vecCount - 1) * 4 + vecData);
        }
        puVar3 = (undefined4 *)0x0;
        if (vec2Count - 1 < vec2Count) {
          puVar3 = (undefined4 *)((vec2Count - 1) * 4 + vec2Data);
        }
        Program__finishUsevectorChain(currentInst,*puVar4,*puVar3,program);
      }
      descending = false;
      countBefore = vecCount;
    } while( true );
  }
  goto LAB_0013c9ec;
code_r0x0013c9e8:
  iVar8 = *(int *)(program + PROG_instructionVector);
LAB_0013c9ec:
  loopIndex = loopIndex + 1;
  instByteOffset = instByteOffset + 4;
  goto LAB_0013c9f4;
}
#undef vecCapacity
#undef vecCount
#undef vecData
#undef vecArena
#undef vec2Capacity
#undef vec2Count
#undef vec2Data
#undef vec2Arena

/* FUN_0013ca84 @ 0x13ca84 (112 bytes) */
int FUN_0013ca84(inst)
  int *inst;
{
  undefined4 sourceDef;
  undefined4 uVar1;
  int vcall7cResult;
  
  if (*(int *)(inst[0x22] + 8) == 0x8e) {
    vcall7cResult = (**(code **)(*inst + 0x7c))(inst);
    uVar1 = *(undefined4 *)(vcall7cResult + 300);
  }
  else {
    uVar1 = 0;
    if ((inst[5] & 0x200U) != 0) {
      sourceDef = IRInst__getOperandSource(inst,inst[0x21]);
      return sourceDef;
    }
  }
  return uVar1;
}

/* IfHeader__convertInnerIfToCmov @ 0x13caf4 (1644 bytes) */
int IfHeader__convertInnerIfToCmov(block, program, compiler)
  int *block;
  undefined4 program;
  uint compiler;
{
  int operandKindClassResult;
  int countdown;
  undefined8 predecessor;
  int listCount;
  undefined8 isStatic;
  int *operandVReg;
  int loopIndex;
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 operandVReg2;
  undefined4 operandVReg3;
  uint uVar9;
  int in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int *in_r9;
  undefined4 uVar10;
  int iVar11;
  int operandRecord;
  int iVar13;
  uint uVar14;
  int *piVar15;
  int iVar16;
  bool bVar17;
  undefined8 uVar18;
  
  uVar9 = compiler;
  iVar3 = FUN_000e9294(block);
  if (iVar3 != 0) {
    isStatic = (**(code **)(*block + 0x40))(block);
    if ((int)((ulonglong)isStatic >> 0x20) == 0) {
      uVar18 = Block__getBranchInst(block,(int)isStatic,uVar9,in_r6,in_r7,in_r8,in_r9);
      if ((*(int *)(*(int *)((int)((ulonglong)uVar18 >> 0x20) + 0x88) + 8) == 0x8b) ||
         (iVar3 = Block__getBranchInst(block,(int)uVar18,uVar9,in_r6,in_r7,in_r8,in_r9),
         *(int *)(*(int *)(iVar3 + 0x88) + 8) == 0x8c)) {
        iVar3 = block[0x4f];
        uVar14 = block[0x4d];
        iVar13 = block[0x4e];
        piVar15 = *(int **)(iVar3 + 0x98);
        piVar1 = (int *)piVar15[2];
        if (piVar1 == (int *)0x0) {
          iVar11 = 0;
          loopIndex = 0;
          iVar16 = 2;
        }
        else {
          iVar11 = 0;
          iVar16 = 0;
          loopIndex = 0;
          do {
            piVar2 = piVar1;
            in_r9 = (int *)(piVar15[5] & 1);
            if (in_r9 != (int *)0x0) {
              iVar5 = (**(code **)(*piVar15 + 0x34))(piVar15);
              if (((iVar5 == 0) && (iVar5 = (**(code **)(*piVar15 + 0x38))(piVar15), iVar5 == 0)) &&
                 (*(int *)(piVar15[0x22] + 8) == 0x8e)) {
                operandVReg = (int *)IRInst__getOperandSource(piVar15,1);
                iVar11 = iVar11 + 1;
                if ((uVar14 == operandVReg[0x56]) &&
                   (iVar5 = (**(code **)(*operandVReg + 100))(operandVReg), iVar5 != 0)) {
                  for (iVar5 = 1; iVar4 = (**(code **)(*operandVReg + 0x14))(operandVReg), iVar5 <= iVar4;
                      iVar5 = iVar5 + 1) {
                    if ((((operandVReg[iVar5 * 6 + 0x28] & 1U) != 0) ||
                        (in_r9 = (int *)(operandVReg[iVar5 * 6 + 0x28] & 2), in_r9 != (int *)0x0)) ||
                       (iVar4 = IRInst__isSourceSelectIdentity(operandVReg,iVar5), iVar4 == 0)) goto LAB_0013cd68;
                  }
                  if ((operandVReg[0x48] != 0) || (operandVReg[0x49] != 0)) goto LAB_0013cd68;
                  if ((operandVReg[0x20] != 0) &&
                     (((iVar5 = RegKind__flagBit0(operandVReg[0x26]), iVar5 != 0 && ((operandVReg[5] & 2U) == 0))
                      && (iVar5 = (**(code **)(*operandVReg + 0x50))(operandVReg), iVar5 == 0)))) {
                    countdown = 4;
                    in_r9 = operandVReg;
                    do {
                      if ((uint)(*(byte *)(in_r9 + 0x27) - 2) < 2) goto LAB_0013cd68;
                      in_r9 = (int *)((int)in_r9 + 1);
                      countdown = countdown + -1;
                    } while (countdown != 0);
                  }
                  IRInst__getOperandRecord(operandVReg,0);
                  iVar5 = IRInst__operandKindClass(operandVReg,0);
                  if (((iVar5 != 0) || ((operandVReg[5] & 2U) != 0)) ||
                     ((in_r9 = (int *)(operandVReg[5] & 0x200), in_r9 != (int *)0x0 ||
                      (*(int *)(operandVReg[4] + 4) != 1)))) goto LAB_0013cd68;
                  iVar16 = iVar16 + 1;
                  bVar17 = true;
                }
                else {
LAB_0013cd68:
                  uVar9 = uVar14;
                  in_r6 = iVar13;
                  iVar5 = FUN_00139034(operandVReg,block,uVar14,iVar13);
                  bVar17 = iVar5 != 0;
                }
                operandVReg = (int *)IRInst__getOperandSource(piVar15,2);
                if ((iVar13 == operandVReg[0x56]) &&
                   (iVar5 = (**(code **)(*operandVReg + 100))(operandVReg), iVar5 != 0)) {
                  for (iVar5 = 1; iVar4 = (**(code **)(*operandVReg + 0x14))(operandVReg), iVar5 <= iVar4;
                      iVar5 = iVar5 + 1) {
                    if ((((operandVReg[iVar5 * 6 + 0x28] & 1U) != 0) ||
                        (in_r9 = (int *)(operandVReg[iVar5 * 6 + 0x28] & 2), in_r9 != (int *)0x0)) ||
                       (iVar4 = IRInst__isSourceSelectIdentity(operandVReg,iVar5), iVar4 == 0)) goto LAB_0013cee8;
                  }
                  if ((operandVReg[0x48] != 0) || (operandVReg[0x49] != 0)) goto LAB_0013cee8;
                  if (((operandVReg[0x20] != 0) &&
                      ((iVar5 = RegKind__flagBit0(operandVReg[0x26]), iVar5 != 0 && ((operandVReg[5] & 2U) == 0))))
                     && (iVar5 = (**(code **)(*operandVReg + 0x50))(operandVReg), iVar5 == 0)) {
                    countdown = 4;
                    in_r9 = operandVReg;
                    do {
                      if ((uint)(*(byte *)(in_r9 + 0x27) - 2) < 2) goto LAB_0013cee8;
                      in_r9 = (int *)((int)in_r9 + 1);
                      countdown = countdown + -1;
                    } while (countdown != 0);
                  }
                  IRInst__getOperandRecord(operandVReg,0);
                  operandKindClassResult = IRInst__operandKindClass(operandVReg,0);
                  if ((((operandKindClassResult != 0) || ((operandVReg[5] & 2U) != 0)) ||
                      (in_r9 = (int *)(operandVReg[5] & 0x200), in_r9 != (int *)0x0)) ||
                     (*(int *)(operandVReg[4] + 4) != 1)) goto LAB_0013cee8;
                  loopIndex = loopIndex + 1;
                }
                else {
LAB_0013cee8:
                  uVar9 = uVar14;
                  in_r6 = iVar13;
                  iVar5 = FUN_00139034(operandVReg,block,uVar14,iVar13);
                  if (iVar5 == 0) {
                    return;
                  }
                }
                if (!bVar17) {
                  return;
                }
              }
              piVar2 = (int *)piVar15[2];
            }
            piVar1 = (int *)piVar2[2];
            piVar15 = piVar2;
          } while ((int *)piVar2[2] != (int *)0x0);
          iVar16 = iVar16 + 2;
        }
        listCount = DList__count(uVar14 + 0x90);
        if (((iVar16 == listCount) && (iVar16 = DList__count(iVar13 + 0x90), iVar16 == loopIndex + 2)) &&
           (iVar11 != 0)) {
          predecessor = Block__getPredecessor(block,0);
          uVar6 = (undefined4)((ulonglong)predecessor >> 0x20);
          iVar11 = Block__getBranchInst(block,(int)predecessor,uVar9,in_r6,in_r7,in_r8,in_r9);
          uVar10 = 0;
          if (*(int *)(*(int *)(iVar11 + 0x88) + 8) == 0x8c) {
            operandRecord = IRInst__getOperandRecord(iVar11,1);
            uVar10 = *(undefined4 *)(operandRecord + 0x10);
            Program__removeInst(program,iVar11);
            bVar17 = *(int *)(iVar11 + 300) != 7;
            iVar11 = IRInst__getOperandSource(iVar11,1);
          }
          else {
            bVar17 = false;
            IRInst__convertCompareToBinaryAlu(iVar11,compiler);
            Block__appendInst(uVar6,iVar11);
          }
          piVar1 = *(int **)(iVar3 + 0x98);
          for (piVar15 = (int *)piVar1[2]; piVar15 != (int *)0x0; piVar15 = (int *)piVar15[2]) {
            iVar3 = (**(code **)(*piVar1 + 0x34))(piVar1);
            if ((iVar3 == 0) && (iVar3 = (**(code **)(*piVar1 + 0x38))(piVar1), iVar3 == 0)) {
              if (*(int *)(piVar1[0x22] + 8) == 0x8e) {
                operandVReg2 = IRInst__getOperandSource(piVar1,1);
                operandVReg3 = IRInst__getOperandSource(piVar1,2);
                iVar3 = FUN_00139034(operandVReg2,block,uVar14,iVar13);
                if (iVar3 == 0) {
                  DList__unlink(operandVReg2);
                  Block__appendInst(uVar6,operandVReg2);
                }
                iVar3 = FUN_00139034(operandVReg3,block,uVar14,iVar13);
                if (iVar3 == 0) {
                  DList__unlink(operandVReg3);
                  Block__appendInst(uVar6,operandVReg3);
                }
                IRInst__foldConstantFactor(piVar1,iVar11,uVar10,compiler);
                if ((*(int *)(piVar1[0x22] + 8) != 0x31) && (bVar17)) {
                  IRInst__swapOperands(piVar1,2,3,compiler);
                }
                Block__appendInst(uVar6,piVar1);
              }
              else {
                DList__unlink(piVar1);
                Block__appendInst(uVar6,piVar1);
              }
            }
            piVar1 = piVar15;
          }
        }
      }
    }
  }
  return;
}

/* pass_rewrite @ 0x13d160 (376 bytes) */
int pass_rewrite(program)
  int program;
{
  int vcall24Result;
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  iVar2 = Compiler__isOptionEnabled(*(undefined4 *)(program + PROG_compiler),0x13);
  if (iVar2 != 0) {
    iVar2 = Compiler__isOptionEnabled(*(undefined4 *)(program + PROG_compiler),0x17);
    if (iVar2 != 0) {
      Program__foldUselessPhis(program);
    }
    ((int (*)())Program__scanUsevectorChains)(program);
    local_1c = *(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaB);
    local_24 = 0;
    local_28 = 2;
    local_20 = Arena__alloc(local_1c,8);
    piVar3 = *(int **)(program + PROG_blockListHead);
    iVar2 = piVar3[2];
    while (iVar2 != 0) {
      vcall24Result = (**(code **)(*piVar3 + 0x24))(piVar3);
      if (vcall24Result != 0) {
        iVar2 = *(int *)(program + PROG_visitStamp) + 1;
        *(int *)(program + PROG_visitStamp) = iVar2;
        ((int (*)())Block__scanBranchConeForFetchAndInterp)(piVar3,&local_28,iVar2);
      }
      piVar3 = (int *)piVar3[2];
      iVar2 = piVar3[2];
    }
    iVar2 = Compiler__isOptionEnabled(*(undefined4 *)(program + PROG_compiler),0x18);
    if (((iVar2 != 0) && (iVar2 = FUN_000e0830(*(undefined4 *)(program + PROG_compiler),0,3), iVar2 == 0)) &&
       ((*(uint *)(*(int *)(*(int *)(program + PROG_compiler) + COMP_target) + 8) & 0x20000) == 0)) {
      ((int (*)())Program__moveInterpFetchesOutOfIfs)(program);
      ((int (*)())Program__hoistFetchInsts)(program);
    }
    Arena__free(local_1c,local_20);
  }
  piVar3 = *(int **)(*(int *)(program + PROG_compiler) + COMP_target);
  (**(code **)(*piVar3 + 0x110))(piVar3,program);
  *(uint *)(program + PROG_flags) = *(uint *)(program + PROG_flags) & 0xffffff7f;
  iVar2 = Compiler__isOptionEnabled(*(undefined4 *)(program + PROG_compiler),0x19);
  if (iVar2 != 0) {
    piVar3 = *(int **)(program + PROG_blockListHead);
    for (piVar1 = (int *)(*(int **)(program + PROG_blockListHead))[2]; piVar1 != (int *)0x0;
        piVar1 = (int *)piVar1[2]) {
      vcall24Result = (**(code **)(*piVar3 + 0x24))(piVar3);
      if (vcall24Result != 0) {
        ((int (*)())IfHeader__convertInnerIfToCmov)(piVar3,program,*(undefined4 *)(program + PROG_compiler));
      }
      piVar3 = piVar1;
    }
  }
  iVar2 = Compiler__isOptionEnabled(*(undefined4 *)(program + PROG_compiler),0x37);
  if (iVar2 != 0) {
    Program__packPsInputs(program);
  }
  ((int (*)())FUN_0013c210)(program);
  ((int (*)())Program__eliminateDeadInstsAndRecountUses)(program,0);
  Program__beginPass(program,(int)"rewrite");
  iVar2 = Compiler__isOptionEnabled(*(undefined4 *)(program + PROG_compiler),0x1f);
  if (iVar2 != 0) {
    pass_loop_trans(program);
  }
  return;
}

/* FUN_0013d3b8 @ 0x13d3b8 (1128 bytes) */
int FUN_0013d3b8(param_1)
  int param_1;
{
  int *vcall7cResult;
  int loopIndex;
  int cloneResult3;
  int cloneResult;
  int splitIntoScalarEnabled;
  undefined4 sourceDef;
  int operandRecord;
  int operandRecord2;
  int *operandVReg;
  bool moreComponents;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int cloneResult2;
  undefined4 uVar8;
  uint operandSelect;
  int *piVar10;
  
  iVar2 = *(int *)(param_1 + 900);
  for (iVar5 = *(int *)(*(int *)(param_1 + 900) + 8); iVar5 != 0; iVar5 = *(int *)(iVar5 + 8)) {
    piVar3 = (int *)(*(int **)(iVar2 + 0x98))[2];
    piVar10 = *(int **)(iVar2 + 0x98);
    if (piVar3 != (int *)0x0) {
      do {
        piVar4 = piVar3;
        if ((piVar10[5] & 1U) != 0) {
          vcall7cResult = (int *)(**(code **)(*piVar10 + 0x7c))(piVar10);
          if ((((vcall7cResult != (int *)0x0) && (vcall7cResult[0x20] != 0)) &&
              (iVar5 = RegKind__flagBit0(vcall7cResult[0x26]), iVar5 != 0)) &&
             ((((vcall7cResult[5] & 2U) == 0 && (iVar5 = (**(code **)(*vcall7cResult + 0x50))(vcall7cResult), iVar5 == 0)
               ) && ((vcall7cResult[5] & 0x40U) == 0)))) {
            cloneResult = IRInst__clone(vcall7cResult,*(undefined4 *)(param_1 + 8),0);
            *(undefined4 *)(cloneResult + 0x94) = *(undefined4 *)(cloneResult + 0x14c);
            *(undefined4 *)(cloneResult + 0x9c) = 0x10101;
            Block__insertInstBefore(iVar2,vcall7cResult,cloneResult);
            cloneResult3 = IRInst__clone(vcall7cResult,*(undefined4 *)(param_1 + 8),0);
            *(undefined4 *)(cloneResult3 + 0x94) = *(undefined4 *)(cloneResult3 + 0x14c);
            *(undefined4 *)(cloneResult3 + 0x9c) = 0x1000101;
            Block__insertInstBefore(iVar2,vcall7cResult,cloneResult3);
            cloneResult2 = IRInst__clone(vcall7cResult,*(undefined4 *)(param_1 + 8),0);
            *(undefined4 *)(cloneResult2 + 0x9c) = 0x1010001;
            *(undefined4 *)(cloneResult2 + 0x94) = *(undefined4 *)(cloneResult2 + 0x14c);
            Block__insertInstBefore(iVar2,vcall7cResult,cloneResult2);
            vcall7cResult[0x27] = 0x1010100;
            *(undefined4 *)(cloneResult + 300) = 0;
            *(int *)(cloneResult3 + 300) = cloneResult;
            *(int *)(cloneResult2 + 300) = cloneResult3;
            vcall7cResult[0x4b] = cloneResult2;
          }
          iVar5 = (**(code **)(*piVar10 + 0x24))(piVar10);
          if (((iVar5 != 0) && (piVar10[0x20] != 0)) &&
             ((iVar5 = RegKind__flagBit0(piVar10[0x26]), iVar5 != 0 &&
              ((((piVar10[5] & 2U) == 0 &&
                (iVar5 = (**(code **)(*piVar10 + 0x50))(piVar10), iVar5 == 0)) &&
               (iVar5 = OpcodeTraits__getField34(*(undefined4 *)(piVar10[0x22] + 8),*(undefined4 *)(param_1 + 8)
                                    ), iVar5 == 0)))))) {
            splitIntoScalarEnabled = Compiler__isOptionEnabled(*(undefined4 *)(param_1 + 8),0x32);
            if (splitIntoScalarEnabled == 0) {
              iVar5 = Compiler__isOptionEnabled(*(undefined4 *)(param_1 + 8),0x30);
              if (iVar5 != 0) {
                operandRecord2 = IRInst__getOperandRecord(piVar10,0);
                operandSelect = *(uint *)(operandRecord2 + 0x10);
                iVar5 = FUN_000f2e18(operandSelect);
                if (iVar5 == 0) {
                  cloneResult = IRInst__clone(piVar10,*(undefined4 *)(param_1 + 8),0);
                  *(uint *)(cloneResult + 0x9c) = operandSelect & 0xffffff00 | 1;
                  uVar8 = *(undefined4 *)(cloneResult + 0x14c);
                  iVar6 = IRInst__getOperandRecord(cloneResult,0);
                  *(undefined4 *)(iVar6 + 8) = uVar8;
                  piVar10[0x27] = 0x1010100;
                  IRInst__setExtraOperandSource(piVar10,cloneResult,0,*(undefined4 *)(param_1 + 8));
                  Block__insertInstBefore(iVar2,piVar10,cloneResult);
                  for (iVar5 = 1; iVar6 = (**(code **)(*piVar10 + 0x14))(piVar10), iVar5 <= iVar6;
                      iVar5 = iVar5 + 1) {
                    operandVReg = (int *)IRInst__getOperandSource(piVar10,iVar5);
                    iVar6 = (**(code **)(*operandVReg + 0x5c))(operandVReg);
                    if (iVar6 != 0) {
                      iVar6 = IRInst__clone(operandVReg,*(undefined4 *)(param_1 + 8),0);
                      uVar8 = *(undefined4 *)(iVar6 + 0x14c);
                      operandRecord = IRInst__getOperandRecord(iVar6,0);
                      *(undefined4 *)(operandRecord + 8) = uVar8;
                      Block__insertInstAfter(operandVReg[0x56],operandVReg,iVar6);
                      IRInst__setOperandSource(piVar10,iVar5,iVar6,0,*(undefined4 *)(param_1 + 8));
                    }
                  }
                }
              }
            }
            else {
              iVar5 = IRInst__countWrittenComponents(piVar10);
              if (1 < iVar5) {
                loopIndex = 0;
                piVar3 = (int *)PTR_DAT_001e8b64;
                do {
                  operandRecord = IRInst__getOperandRecord(piVar10,0);
                  if (*(char *)(loopIndex + operandRecord + 0x10) != '\x01') {
                    if (iVar5 < 2) {
                      piVar10[0x27] = *piVar3;
                      IRInst__clearSourceSelectsOfUnwrittenComponents(piVar10);
                    }
                    else {
                      cloneResult2 = IRInst__clone(piVar10,*(undefined4 *)(param_1 + 8),0);
                      *(int *)(cloneResult2 + 0x9c) = *piVar3;
                      Block__insertInstBefore(iVar2,piVar10,cloneResult2);
                      if ((piVar10[5] & 0x200U) != 0) {
                        sourceDef = IRInst__getOperandSource(piVar10,piVar10[0x21]);
                        IRInst__setExtraOperandSource(cloneResult2,sourceDef,0,*(undefined4 *)(param_1 + 8));
                      }
                      IRInst__setExtraOperandSource(piVar10,cloneResult2,0,*(undefined4 *)(param_1 + 8));
                    }
                    iVar5 = iVar5 + -1;
                  }
                  moreComponents = loopIndex != 3;
                  piVar3 = piVar3 + 1;
                  loopIndex = loopIndex + 1;
                } while (moreComponents);
              }
            }
          }
          piVar4 = (int *)piVar10[2];
        }
        piVar3 = (int *)piVar4[2];
        piVar10 = piVar4;
      } while ((int *)piVar4[2] != (int *)0x0);
      iVar5 = *(int *)(iVar2 + 8);
    }
    iVar2 = iVar5;
  }
  return;
}

/* FUN_0013d820 @ 0x13d820 (540 bytes) */
int FUN_0013d820(inst, param_2)
  int *inst;
  int param_2;
{
  int vcall64Result;
  int operandRecord;
  bool moreComponents;
  char cVar2;
  uint uVar3;
  int iVar4;
  int *callResult;
  int *operandVReg;
  undefined4 uVar7;
  int loopIndex;
  undefined4 operandSelectB;
  undefined4 operandSelect;
  int local_40 [7];
  
  uVar7 = *(undefined4 *)(param_2 + 8);
  vcall64Result = (**(code **)(*inst + 100))(inst,param_2);
  if ((vcall64Result != 0) && ((inst[5] & 0x200U) != 0)) {
    callResult = (int *)IRInst__getOperandSource(inst,1);
    operandVReg = (int *)IRInst__getOperandSource(inst,inst[0x21]);
    iVar4 = (**(code **)(*callResult + 0x48))(callResult);
    if ((iVar4 != 0) && (iVar4 = (**(code **)(*operandVReg + 0x2c))(operandVReg), iVar4 != 0)) {
      operandRecord = IRInst__getOperandRecord(operandVReg,0);
      operandSelectB = *(undefined4 *)(operandRecord + 0x10);
      loopIndex = 0;
      operandRecord = IRInst__getOperandRecord(inst,0);
      operandSelect = *(undefined4 *)(operandRecord + 0x10);
      local_40[0] = operandVReg[0x50];
      do {
        cVar2 = *(char *)((int)local_40 + loopIndex + -4);
        if (cVar2 == '\0') {
          if (*(char *)((int)&operandSelectB + loopIndex) != '\0') {
            return;
          }
          operandRecord = IRInst__getOperandRecord(inst,1);
          uVar3 = (uint)*(byte *)(loopIndex + operandRecord + 0x10);
          if (((int)*(char *)(callResult + 0x57) >> (uVar3 & 0x3f) & 1U) == 0) {
            return;
          }
          if (callResult[uVar3 * 6 + 7] != 2) {
            return;
          }
          if ((GH_U2F((unsigned int)(callResult[uVar3 * 6 + 8])) != 0.0) || (*(char *)((int)local_40 + loopIndex) != '\x05'))
          {
            if (GH_U2F((unsigned int)(callResult[uVar3 * 6 + 8])) != 1.0) {
              return;
            }
            if (*(char *)((int)local_40 + loopIndex) != '\x03') {
              return;
            }
          }
        }
        else if (cVar2 != '\x01') {
          return;
        }
        moreComponents = loopIndex != 3;
        loopIndex = loopIndex + 1;
      } while (moreComponents);
      IRInst__setOperandSource(inst,1,operandVReg,0,uVar7);
      inst[0x27] = 0;
      operandRecord = IRInst__getOperandRecord(inst,1);
      *(undefined4 *)(operandRecord + 0x10) = 0x10203;
      IRInst__setOperandSource(inst,inst[0x21],0,0,*(undefined4 *)(param_2 + 8));
      inst[0x21] = inst[0x21] + -1;
      inst[5] = inst[5] & 0xfffffdff;
    }
  }
  return;
}

/* FUN_0013da3c @ 0x13da3c (760 bytes) */
int FUN_0013da3c(program)
  int program;
{
  bool replacesWriteMask;
  bool moreComponents;
  bool byte1IsZero;
  bool byte2IsZero;
  bool lowByteIsZero;
  int poppedInstB;
  int operandIndexB;
  int cloneOperandCount;
  int identitySelectD;
  int savedUsers;
  int matchedDef;
  int destOperandRecordC;
  int candidateDef;
  int predicateResultD;
  int destSelectWord;
  int nextBlockB;
  int vcall48Result;
  int blockCursor;
  int isProjectionOf2a;
  int rootCursor;
  int identitySelectC;
  int operandLimitB;
  int fixedSelectWord;
  int cloneSource;
  int lastOperandRecordB;
  int defRoot;
  int lastOperandIndexB;
  int destOperandRecordB;
  int predicateResultC;
  int nextBlock;
  int byteOffsetD;
  int resolvedRoot;
  int destOperandRecord;
  int byteOffsetC;
  int chainInst;
  int selectRecord;
  int lastOperandRecord;
  int lastOperandIndex;
  int candidateRoot;
  int operandIndex;
  int mergeTarget;
  int maskedSelectWord;
  int predicateResultB;
  int hasSpecialSource;
  int identitySelectB;
  int componentIndex;
  int predicateResult;
  int byteOffsetB;
  int sourceIndex;
  int identitySelect;
  int successorBlock;
  int unionFindParents;
  int vcall30Result;
  int operandCount;
  int pushedInst;
  int block;
  int idArrayBytes;
  int byteOffset;
  int *growSlotPtr;
  int *workInst;
  int *operandSourceInst;
  int *sourceInst;
  int *lookaheadInst;
  int *topElementPtr;
  int *userElementPtr;
  int *producerInst;
  int *defInst;
  undefined4 firstOperandSource;
  undefined4 lastOperandSource;
  undefined4 selectWordConst;
  undefined4 *selectConstPtr;
  undefined4 *pushSlot;
  uint oldWriteMask;
  uint userIndex;
  uint operandReadMask;
  uint uncoveredMask;
  uint defWriteMask;
  uint mergedMask;
  uint userCount;
  uint operandSelectWord;
  uint savedScratchWord;
  uint vecCountBefore;
  uint topIndex;
  uint instOrdinal;
  undefined4 *allocation;
  undefined4 vectorData;
  undefined4 arena;
  int flagBit8Result;
  int cloneResult;
  int instFlagBit2Result;
  int isProjectionOfClass26or3a;
  int softilGenAttribShdrEnabled;
  int operandRecord4;
  int operandRecord3;
  int operandRecord2;
  int sourceDef;
  int operandRecord;
  int operandRecord5;
  int *operandVReg;
  bool highByteIsZero;
  uint maskedWriteMask;
  uint option4eEnabled;
  int *elementPtr;
  int matchingDefMap;
  undefined4 *topSlot;
  int disjointSetFindRootResult;
  int hasDefaultSelects;
  int operandLimit;
  int prevRoot;
  int instVector;
  int *nextInst;
  int prevMergeTarget;
  int instByteOffset;
  int candidateInst;
  undefined4 poppedInst;
  int *inst;
  uint *userList;
  uint queuedCount;
  int scanInst;
  uint *userListRef;
  int operandSelectBytes;
  uint coveredMask;
  undefined4 selectReadMaskBytes;
  undefined4 maskedWriteMaskBytes;
  int currentInst;
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/uVar19) used with Vector__elementRefGrow - vecCapacity/vecCount/vecData/vecArena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_b4_buf [0x10];
  #define vecCapacity (*(uint *)(local_b4_buf + 0x00))
  #define vecCount (*(uint *)(local_b4_buf + 0x04))
  #define vecData (*(int *)(local_b4_buf + 0x08))
  #define vecArena (*(undefined4 *)(local_b4_buf + 0x0c))
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/uVar19) used with Vector__elementRefGrow - vec2Capacity/vec2Count/vec2Data/vec2Arena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_a4_buf [0x10];
  #define vec2Capacity (*(undefined4 *)(local_a4_buf + 0x00))
  #define vec2Count (*(uint *)(local_a4_buf + 0x04))
  #define vec2Data (*(int *)(local_a4_buf + 0x08))
  #define vec2Arena (*(undefined4 *)(local_a4_buf + 0x0c))
  undefined4 destWriteMask;
  uint operandReadMaskOutA;
  uint chainedWriteMask;
  undefined4 mergedSelectWord;
  uint operandWriteMask;
  int destSelectWordB;
  uint operandSelectOutA;
  uint operandSelectOutB;
  int projSelectWord;
  uint operandReadMaskOutB;
  int maskedSelectOut;
  undefined4 selectReadMask;
  int blockListObject;
  undefined *globalsBase;
  
  option4eEnabled = Compiler__isOptionEnabled(*(undefined4 *)(program + PROG_compiler),0x4e);
  if (option4eEnabled == 0) {
    softilGenAttribShdrEnabled = Compiler__isOptionEnabled(*(undefined4 *)(program + PROG_compiler),0x4f);
    if (softilGenAttribShdrEnabled == 0) goto LAB_0013dcf0;
    vec2Arena = *(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaB);
    instByteOffset = 0;
    vec2Capacity = 2;
    vec2Count = option4eEnabled;
    vec2Data = Arena__alloc(vec2Arena,8);
    instVector = *(int *)(program + PROG_instructionVector);
    currentInst = 0;
    for (instOrdinal = 1; queuedCount = vec2Count, instOrdinal <= *(uint *)(instVector + 4); instOrdinal = instOrdinal + 1) {
      candidateInst = *(int *)(instByteOffset + *(int *)(instVector + 8));
      currentInst = candidateInst;
      if (((*(uint *)(candidateInst + 0x14) & 1) != 0) && (*(int *)(candidateInst + 0x98) == 6)) {
        if (vec2Count < vec2Capacity) {
          byteOffset = vec2Count * 4;
          _memset(byteOffset + vec2Data,0,4);
          vec2Count = queuedCount + 1;
          elementPtr = (int *)(byteOffset + vec2Data);
        }
        else {
          elementPtr = (int *)Vector__elementRefGrow(&vec2Capacity,vec2Count);
        }
        *elementPtr = candidateInst;
        *(uint *)(currentInst + 0x14) = *(uint *)(currentInst + 0x14) & 0xfffffff7;
        *(uint *)(currentInst + 0x14) = *(uint *)(currentInst + 0x14) & 0xffffffef;
        instVector = *(int *)(program + PROG_instructionVector);
      }
      instByteOffset = instByteOffset + 4;
    }
    while (vec2Count != 0) {
      topIndex = vec2Count - 1;
      topSlot = (undefined4 *)0x0;
      if (topIndex < vec2Count) {
        topSlot = (undefined4 *)(topIndex * 4 + vec2Data);
      }
      poppedInst = *topSlot;
      Vector__removeAt(&vec2Capacity,topIndex);
      Program__removeInst(program,poppedInst);
    }
  }
  else {
    vec2Arena = *(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaB);
    vec2Capacity = 2;
    instByteOffset = 0;
    vec2Count = 0;
    vec2Data = Arena__alloc(vec2Arena,8);
    instVector = *(int *)(program + PROG_instructionVector);
    currentInst = 0;
    for (instOrdinal = 1; queuedCount = vec2Count, instOrdinal <= *(uint *)(instVector + 4); instOrdinal = instOrdinal + 1) {
      candidateInst = *(int *)(instByteOffset + *(int *)(instVector + 8));
      currentInst = candidateInst;
      if (((*(uint *)(candidateInst + 0x14) & 1) != 0) && (*(int *)(candidateInst + 0x98) != 6)) {
        if (vec2Count < vec2Capacity) {
          byteOffset = vec2Count * 4;
          _memset(byteOffset + vec2Data,0,4);
          vec2Count = queuedCount + 1;
          elementPtr = (int *)(byteOffset + vec2Data);
        }
        else {
          elementPtr = (int *)Vector__elementRefGrow(&vec2Capacity,vec2Count);
        }
        *elementPtr = candidateInst;
        *(uint *)(currentInst + 0x14) = *(uint *)(currentInst + 0x14) & 0xfffffff7;
        *(uint *)(currentInst + 0x14) = *(uint *)(currentInst + 0x14) & 0xffffffef;
        instVector = *(int *)(program + PROG_instructionVector);
      }
      instByteOffset = instByteOffset + 4;
    }
    while (vec2Count != 0) {
      topIndex = vec2Count - 1;
      topSlot = (undefined4 *)0x0;
      if (topIndex < vec2Count) {
        topSlot = (undefined4 *)(topIndex * 4 + vec2Data);
      }
      poppedInst = *topSlot;
      Vector__removeAt(&vec2Capacity,topIndex);
      Program__removeInst(program,poppedInst);
    }
  }
  Arena__free(vec2Arena,vec2Data);
LAB_0013dcf0:
  vecArena = *(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaB);
  vecCount = 0;
  vecCapacity = 2;
  vecData = Arena__alloc(vecArena,8);
  idArrayBytes = *(int *)(*(int *)(program + PROG_compiler) + COMP_nextInstId) << 2;
  unionFindParents = Arena__alloc(*(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaB),idArrayBytes);
  matchingDefMap = Arena__alloc(*(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaB),idArrayBytes);
  blockListObject = program + 0x37c;
  block = *(int *)(program + PROG_blockListHead);
  for (blockCursor = *(int *)(*(int *)(program + PROG_blockListHead) + 8); blockCursor != 0; blockCursor = *(int *)(blockCursor + 8)) {
    inst = *(int **)(block + 0x98);
    lookaheadInst = (int *)inst[2];
    if ((int *)inst[2] != (int *)0x0) {
      do {
        nextInst = lookaheadInst;
        if ((inst[5] & 1U) != 0) {
          *(int *)(inst[0x53] * 4 + unionFindParents) = inst[0x53];
          *(undefined4 *)(matchingDefMap + inst[0x53] * 4) = 0;
          vcall48Result = (**(code **)(*inst + 0x48))(inst);
          if (vcall48Result != 0) {
            inst[0x27] = DAT_001b0008;
          }
          inst[3] = 0;
          ((int (*)())FUN_0013d820)(inst,program);
          arena = *(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaB);
          allocation = (undefined4 *)Arena__alloc(arena,0x14);
          *allocation = arena;
          allocation[1] = 2;
          allocation[2] = 0;
          allocation[4] = arena;
          vectorData = Arena__alloc(arena,8);
          allocation[3] = vectorData;
          nextInst = (int *)inst[2];
          inst[4] = (int)(allocation + 1);
        }
        lookaheadInst = (int *)nextInst[2];
        inst = nextInst;
      } while ((int *)nextInst[2] != (int *)0x0);
      blockCursor = *(int *)(block + 8);
    }
    block = blockCursor;
  }
  instVector = *(int *)(program + PROG_instructionVector);
  instByteOffset = 0;
  currentInst = 0;
  for (instOrdinal = 1; instOrdinal <= *(uint *)(instVector + 4); instOrdinal = instOrdinal + 1) {
    scanInst = *(int *)(instByteOffset + *(int *)(instVector + 8));
    currentInst = scanInst;
    if ((*(uint *)(scanInst + 0x14) & 1) != 0) {
      operandRecord2 = IRInst__getOperandRecord(scanInst,0);
      WriteMask__fromSelectWord(&destWriteMask,*(undefined4 *)(operandRecord2 + 0x10));
      queuedCount = vecCount;
      pushedInst = currentInst;
      *(undefined4 *)(scanInst + 0xc) = destWriteMask;
      if (vecCount < vecCapacity) {
        byteOffsetD = vecCount * 4;
        _memset(byteOffsetD + vecData,0,4);
        vecCount = queuedCount + 1;
        elementPtr = (int *)(byteOffsetD + vecData);
      }
      else {
        elementPtr = (int *)Vector__elementRefGrow(&vecCapacity,vecCount);
      }
      *elementPtr = pushedInst;
      instVector = *(int *)(program + PROG_instructionVector);
    }
    instByteOffset = instByteOffset + 4;
  }
  do {
    do {
      if (vecCount == 0) {
        block = *(int *)(blockListObject + 8);
        nextBlockB = *(int *)(block + 8);
        if (*(int *)(block + 8) != 0) {
          do {
            nextBlock = nextBlockB;
            lookaheadInst = (int *)(*(int **)(block + 0x98))[2];
            inst = *(int **)(block + 0x98);
            if (lookaheadInst != (int *)0x0) {
              do {
                nextInst = lookaheadInst;
                if ((inst[5] & 1U) != 0) {
                  operandRecord3 = IRInst__getOperandRecord(inst,0);
                  SelectWord__selectWhereMasked(&destSelectWordB,*(undefined4 *)(operandRecord3 + 0x10),inst[3]);
                  destSelectWord = destSelectWordB;
                  if (((((inst[0x20] != 0) && (predicateResultC = RegKind__flagBit0(inst[0x26]), predicateResultC != 0)
                        ) && (((inst[5] & 2U) == 0 &&
                              (predicateResultC = (**(code **)(*inst + 0x50))(inst), predicateResultC == 0)))) ||
                      ((predicateResultC = RegKind__flagBit7(inst[0x26]), predicateResultC != 0 ||
                       (predicateResultC = RegKind__flagBit8(inst[0x26]), predicateResultC != 0)))) &&
                     ((lookaheadInst = *(int **)(*(int *)(program + PROG_compiler) + COMP_target),
                      predicateResultC = (**(code **)(*lookaheadInst + 0x7c))(lookaheadInst,inst), predicateResultC != 0 &&
                      (destOperandRecordB = IRInst__getOperandRecord(inst,0), destSelectWord != *(int *)(destOperandRecordB + 0x10))))) {
                    inst[0x27] = destSelectWord;
                  }
                  if (inst[3] != 0) {
                    lastOperandIndexB = inst[0x21];
                    if ((inst[5] & 0x200U) != 0) {
                      lastOperandIndexB = lastOperandIndexB + -1;
                    }
                    hasDefaultSelects = (**(code **)(*inst + 0x60))(inst);
                    if (hasDefaultSelects != 0) {
                      if (0 < lastOperandIndexB) {
                        operandIndex = 1;
                        do {
                          vec2Capacity = DAT_001b0020;
                          operandLimit = (**(code **)(*inst + 0x14))(inst);
                          if (operandIndex <= operandLimit) {
                            IRInst__computeSourceLaneMask(&operandSelectOutA,inst,operandIndex,program,destSelectWord);
                            identitySelectB = DAT_001b0000;
                            vec2Capacity = operandSelectOutA;
                            savedScratchWord = vec2Capacity;
                            (*(unsigned char *)((unsigned char *)&(vec2Capacity) + 3)) = (char)operandSelectOutA;
                            (*(unsigned char *)((unsigned char *)&(vec2Capacity) + 2)) = (char)(operandSelectOutA >> 8);
                            (*(unsigned char *)((unsigned char *)&(vec2Capacity) + 1)) = (char)(operandSelectOutA >> 0x10);
                            (*(unsigned char *)((unsigned char *)&(vec2Capacity) + 0)) = (char)(operandSelectOutA >> 0x18);
                            lowByteIsZero = (char)vec2Capacity == '\0';
                            byte2IsZero = (*(unsigned char *)((unsigned char *)&(vec2Capacity) + 2)) == '\0';
                            byte1IsZero = (*(unsigned char *)((unsigned char *)&(vec2Capacity) + 1)) == '\0';
                            highByteIsZero = (*(unsigned char *)((unsigned char *)&(vec2Capacity) + 0)) == '\0';
                            vec2Capacity = savedScratchWord;
                            if (((lowByteIsZero && byte2IsZero) && byte1IsZero) && highByteIsZero) {
                              if (operandIndex == 0) {
                                inst[0x27] = DAT_001b0000;
                              }
                              else {
                                operandRecord = IRInst__getOperandRecord(inst,operandIndex);
                                *(int *)(operandRecord + 0x10) = identitySelectB;
                              }
                            }
                          }
                          operandIndex = operandIndex + 1;
                        } while (operandIndex <= lastOperandIndexB);
                      }
                      IRInst__removeDefaultSelectOperands(inst,*(undefined4 *)(program + PROG_compiler));
                      lastOperandIndexB = inst[0x21];
                      if ((inst[5] & 0x200U) != 0) {
                        lastOperandIndexB = lastOperandIndexB + -1;
                      }
                    }
                    if (0 < lastOperandIndexB) {
                      operandIndex = 1;
                      do {
                        operandSelectWord = DAT_001b0020;
                        sourceInst = (int *)IRInst__getOperandSource(inst,operandIndex);
                        operandLimit = (**(code **)(*inst + 0x14))(inst);
                        if (operandIndex <= operandLimit) {
                          IRInst__computeSourceLaneMask(&operandSelectOutB,inst,operandIndex,program,destSelectWord);
                          operandSelectWord = operandSelectOutB;
                        }
                        hasSpecialSource = ((int (*)())FUN_001396d0)(*(undefined4 *)(program + PROG_compiler),inst,operandIndex,program);
                        operandReadMask = DAT_001b0020;
                        if (hasSpecialSource == 0) {
                          operandLimit = (**(code **)(*inst + 0x14))(inst);
                          if (operandIndex <= operandLimit) {
                            FUN_000f403c(&operandReadMaskOutB,inst,operandIndex,inst[3],program);
                            operandReadMask = operandReadMaskOutB;
                          }
                          if (sourceInst != (int *)0x0) {
                            if (((((sourceInst[0x20] != 0) &&
                                  (predicateResultB = RegKind__flagBit0(sourceInst[0x26]), predicateResultB != 0)) &&
                                 ((sourceInst[5] & 2U) == 0)) &&
                                (predicateResultB = (**(code **)(*sourceInst + 0x50))(sourceInst), predicateResultB == 0)) ||
                               ((predicateResultB = RegKind__flagBit7(sourceInst[0x26]), predicateResultB != 0 ||
                                (predicateResultB = RegKind__flagBit8(sourceInst[0x26]), predicateResultB != 0)))) {
                              while( true ) {
                                maskedWriteMask = operandReadMask & sourceInst[3];
                                (*(unsigned char *)((unsigned char *)&(maskedWriteMaskBytes) + 3)) = (char)maskedWriteMask;
                                (*(unsigned char *)((unsigned char *)&(maskedWriteMaskBytes) + 2)) = (char)(maskedWriteMask >> 8);
                                (*(unsigned char *)((unsigned char *)&(maskedWriteMaskBytes) + 1)) = (char)(maskedWriteMask >> 0x10);
                                (*(unsigned char *)((unsigned char *)&(maskedWriteMaskBytes) + 0)) = (char)(maskedWriteMask >> 0x18);
                                maskedWriteMaskBytes = maskedWriteMask;
                                if ((((char)maskedWriteMaskBytes != '\0' || (*(unsigned char *)((unsigned char *)&(maskedWriteMaskBytes) + 2)) != '\0') ||
                                    (*(unsigned char *)((unsigned char *)&(maskedWriteMaskBytes) + 1)) != '\0') || (*(unsigned char *)((unsigned char *)&(maskedWriteMaskBytes) + 0)) != '\0') break;
                                sourceInst = (int *)((int (*)())FUN_0013ca84)(sourceInst);
                              }
                              IRInst__setOperandSource(inst,operandIndex,sourceInst,0,*(undefined4 *)(program + PROG_compiler));
                              operandRecord5 = IRInst__getOperandRecord(inst,operandIndex);
                              SelectWord__maskUnused(&maskedSelectOut,*(undefined4 *)(operandRecord5 + 0x10),operandSelectWord);
                              maskedSelectWord = maskedSelectOut;
                              operandRecord = IRInst__getOperandRecord(inst,operandIndex);
                              if (*(int *)(operandRecord + 0x10) != DAT_001b0000) {
                                userList = (uint *)sourceInst[4];
                                userCount = userList[1];
                                if (userCount < *userList) {
                                  _memset(userCount * 4 + userList[2],0,4);
                                  pushSlot = (undefined4 *)(userCount * 4 + userList[2]);
                                  userList[1] = userCount + 1;
                                }
                                else {
                                  pushSlot = (undefined4 *)Vector__elementRefGrow(userList,userCount);
                                }
                                *pushSlot = inst;
                              }
                              ((int (*)())IRInst__markOpcode13After12)(sourceInst,inst);
                              goto code_r0x0013e80c;
                            }
                            userList = (uint *)sourceInst[4];
                            userCount = userList[1];
                            if (userCount < *userList) {
                              _memset(userCount * 4 + userList[2],0,4);
                              pushSlot = (undefined4 *)(userCount * 4 + userList[2]);
                              userList[1] = userCount + 1;
                            }
                            else {
                              pushSlot = (undefined4 *)Vector__elementRefGrow(userList,userCount);
                            }
                            *pushSlot = inst;
                          }
                        }
                        else {
                          isProjectionOfClass26or3a = IRInst__isProjectionOfClass26or3a(inst);
                          selectWordConst = DAT_001b0004;
                          if (isProjectionOfClass26or3a != 0) {
                            selectWordConst = DAT_001b001c;
                          }
                          instFlagBit2Result = OpcodeTraits__instFlagBit2(*(undefined4 *)(program + PROG_compiler),inst);
                          if (instFlagBit2Result != 0) {
                            if (operandIndex == 1) {
                              selectConstPtr = &UNK_001b0018;
                            }
                            else {
                              selectConstPtr = &DAT_001b001c;
                            }
                            selectWordConst = *selectConstPtr;
                          }
                          SelectWord__maskUnused(&projSelectWord,selectWordConst,operandSelectWord);
                          maskedSelectWord = projSelectWord;
                          sourceDef = IRInst__getOperandSource(inst,operandIndex);
                          userList = *(uint **)(sourceDef + 0x10);
                          if (userList == (uint *)0x0) {
                            arena = *(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaB);
                            allocation = (undefined4 *)Arena__alloc(arena,0x14);
                            userList = allocation + 1;
                            *allocation = arena;
                            allocation[1] = 2;
                            allocation[2] = 0;
                            allocation[4] = arena;
                            vectorData = Arena__alloc(arena,8);
                            allocation[3] = vectorData;
                            *(uint **)(sourceDef + 0x10) = userList;
                          }
                          userCount = userList[1];
                          if (userCount < *userList) {
                            _memset(userCount * 4 + userList[2],0,4);
                            pushSlot = (undefined4 *)(userCount * 4 + userList[2]);
                            userList[1] = userCount + 1;
                          }
                          else {
                            pushSlot = (undefined4 *)Vector__elementRefGrow(userList,userCount);
                          }
                          *pushSlot = inst;
code_r0x0013e80c:
                          operandRecord = IRInst__getOperandRecord(inst,operandIndex);
                          if (maskedSelectWord != *(int *)(operandRecord + 0x10)) {
                            if (operandIndex == 0) {
                              inst[0x27] = maskedSelectWord;
                            }
                            else {
                              operandRecord = IRInst__getOperandRecord(inst,operandIndex);
                              *(int *)(operandRecord + 0x10) = maskedSelectWord;
                            }
                          }
                        }
                        operandIndex = operandIndex + 1;
                      } while (operandIndex <= lastOperandIndexB);
                    }
                  }
                  if ((((inst[0x20] == 0) || (predicateResultD = RegKind__flagBit0(inst[0x26]), predicateResultD == 0))
                      || (((inst[5] & 2U) != 0 ||
                          (predicateResultD = (**(code **)(*inst + 0x50))(inst), predicateResultD != 0)))) &&
                     ((predicateResultD = RegKind__flagBit7(inst[0x26]), predicateResultD == 0 &&
                      (predicateResultD = RegKind__flagBit8(inst[0x26]), predicateResultD == 0)))) {
                    nextInst = (int *)inst[2];
                  }
                  else {
                    candidateDef = 0;
                    if (inst[3] != 0) {
                      candidateDef = ((int (*)())FUN_0013ca84)(inst);
                    }
                    defRoot = disjointSetFindRoot(inst[0x53],unionFindParents);
                    while ((candidateDef != 0 &&
                           ((candidateRoot = disjointSetFindRoot(*(undefined4 *)(candidateDef + 0x14c),unionFindParents),
                            defRoot != candidateRoot || (candidateRoot = FUN_000f497c(candidateDef,inst), candidateRoot == 0)
                            )))) {
                      candidateDef = ((int (*)())FUN_0013ca84)(candidateDef);
                    }
                    *(int *)(matchingDefMap + inst[0x53] * 4) = candidateDef;
                    nextInst = (int *)inst[2];
                  }
                }
                lookaheadInst = (int *)nextInst[2];
                inst = nextInst;
              } while ((int *)nextInst[2] != (int *)0x0);
              nextBlock = *(int *)(block + 8);
            }
            nextBlockB = *(int *)(nextBlock + 8);
            block = nextBlock;
          } while (*(int *)(nextBlock + 8) != 0);
          block = *(int *)(blockListObject + 8);
        }
        nextBlockB = *(int *)(block + 8);
        while (successorBlock = nextBlockB, successorBlock != 0) {
          lookaheadInst = (int *)(*(int **)(block + 0x98))[2];
          inst = *(int **)(block + 0x98);
          if (lookaheadInst != (int *)0x0) {
            do {
              nextInst = lookaheadInst;
              if ((inst[5] & 1U) != 0) {
                if (((((inst[0x20] != 0) && (predicateResultD = RegKind__flagBit0(inst[0x26]), predicateResultD != 0))
                     && ((inst[5] & 2U) == 0)) &&
                    (predicateResultD = (**(code **)(*inst + 0x50))(inst), predicateResultD == 0)) ||
                   ((predicateResultD = RegKind__flagBit7(inst[0x26]), predicateResultD != 0 ||
                    (predicateResultD = RegKind__flagBit8(inst[0x26]), predicateResultD != 0)))) {
                  destOperandRecordC = IRInst__getOperandRecord(inst,0);
                  if (*(int *)(destOperandRecordC + 0x10) != DAT_001b0014) {
                    IRInst__canonicalizeCommutativeOperands(inst,*(undefined4 *)(program + PROG_compiler));
                  }
                  if ((inst[5] & 0x200U) != 0) {
                    matchedDef = *(int *)(matchingDefMap + inst[0x53] * 4);
                    if (matchedDef == 0) {
                      IRInst__setOperandSource(inst,inst[0x21],0,0,*(undefined4 *)(program + PROG_compiler));
                      inst[0x21] = inst[0x21] + -1;
                      inst[5] = inst[5] & 0xfffffdff;
                    }
                    else {
                      IRInst__setExtraOperandSource(inst,matchedDef,0,*(undefined4 *)(program + PROG_compiler));
                      identitySelect = DAT_001b0000;
                      if (inst[0x21] == 0) {
                        inst[0x27] = DAT_001b0000;
                      }
                      else {
                        lastOperandRecordB = IRInst__getOperandRecord(inst,inst[0x21]);
                        *(int *)(lastOperandRecordB + 0x10) = identitySelect;
                      }
                      userList = *(uint **)(matchedDef + 0x10);
                      userCount = userList[1];
                      if (userCount < *userList) {
                        _memset(userCount * 4 + userList[2],0,4);
                        pushSlot = (undefined4 *)(userCount * 4 + userList[2]);
                        userList[1] = userCount + 1;
                      }
                      else {
                        pushSlot = (undefined4 *)Vector__elementRefGrow(userList,userCount);
                      }
                      *pushSlot = inst;
                      *(uint *)(matchedDef + 0x14) = *(uint *)(matchedDef + 0x14) | 0x400000;
                    }
                  }
                  if (((inst[0x48] != 0) || (inst[0x49] != 0)) &&
                     (((inst[5] & 0x200U) != 0 &&
                      (lookaheadInst = *(int **)(*(int *)(program + PROG_compiler) + COMP_target),
                      predicateResultD = (**(code **)(*lookaheadInst + 0x7c))(lookaheadInst,inst), predicateResultD == 0)))) {
                    cloneResult = IRInst__clone(inst,*(undefined4 *)(program + PROG_compiler),0);
                    arena = *(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaB);
                    allocation = (undefined4 *)Arena__alloc(arena,0x14);
                    *allocation = arena;
                    allocation[1] = 2;
                    allocation[2] = 0;
                    allocation[4] = arena;
                    vectorData = Arena__alloc(arena,8);
                    allocation[3] = vectorData;
                    *(undefined4 **)(cloneResult + 0x10) = allocation + 1;
                    Block__insertInstBefore(block,inst,cloneResult);
                    savedUsers = inst[4];
                    DList__unlink(inst);
                    IRInst__reinitAsMov(inst,0x31,*(undefined4 *)(program + PROG_compiler));
                    inst[4] = savedUsers;
                    inst[0x25] = inst[0x53];
                    inst[0x26] = 0;
                    IRInst__setOperandSource(inst,1,cloneResult,0,*(undefined4 *)(program + PROG_compiler));
                    lastOperandSource = IRInst__getOperandSource(cloneResult,*(undefined4 *)(cloneResult + 0x84));
                    IRInst__setExtraOperandSource(inst,lastOperandSource,0,*(undefined4 *)(program + PROG_compiler));
                    identitySelectD = DAT_001b0000;
                    if (inst[0x21] == 0) {
                      inst[0x27] = DAT_001b0000;
                    }
                    else {
                      lastOperandRecordB = IRInst__getOperandRecord(inst,inst[0x21]);
                      *(int *)(lastOperandRecordB + 0x10) = identitySelectD;
                    }
                    userList = *(uint **)(cloneResult + 0x10);
                    userCount = userList[1];
                    if (userCount < *userList) {
                      _memset(userCount * 4 + userList[2],0,4);
                      pushSlot = (undefined4 *)(userCount * 4 + userList[2]);
                      userList[1] = userCount + 1;
                    }
                    else {
                      pushSlot = (undefined4 *)Vector__elementRefGrow(userList,userCount);
                    }
                    *pushSlot = inst;
                    IRInst__setOperandSource(cloneResult,*(undefined4 *)(cloneResult + 0x84),0,0,
                                 *(undefined4 *)(program + PROG_compiler));
                    cloneOperandCount = *(int *)(cloneResult + 0x84) + -1;
                    *(int *)(cloneResult + 0x84) = cloneOperandCount;
                    *(uint *)(cloneResult + 0x14) = *(uint *)(cloneResult + 0x14) & 0xfffffdff;
                    *(int *)(cloneResult + 0x160) =
                         *(int *)(*(int *)(*(int *)(program + PROG_compiler) + COMP_currentProgram) + 0x478) + 1;
                    if (0 < cloneOperandCount) {
                      operandIndexB = 1;
                      do {
                        cloneSource = IRInst__getOperandSource(cloneResult,operandIndexB);
                        userCount = (*(uint **)(cloneSource + 0x10))[1];
                        if (userCount != 0) {
                          userIndex = 0;
                          userList = *(uint **)(cloneSource + 0x10);
                          do {
                            if (userIndex < *userList) {
                              userListRef = userList;
                              if (userCount <= userIndex) {
                                _memset(userCount * 4 + userList[2],0,(userIndex - userCount) * 4 + 4);
                                userList[1] = userIndex + 1;
                                userListRef = *(uint **)(cloneSource + 0x10);
                              }
                              userElementPtr = (int *)(userIndex * 4 + userList[2]);
                            }
                            else {
                              userElementPtr = (int *)Vector__elementRefGrow(userList,userIndex);
                              userListRef = *(uint **)(cloneSource + 0x10);
                            }
                            if (inst == (int *)*userElementPtr) {
                              Vector__removeAt(userListRef,userIndex);
                              userList = *(uint **)(cloneSource + 0x10);
                              userCount = userList[1];
                              if (userCount < *userList) {
                                _memset(userCount * 4 + userList[2],0,4);
                                userElementPtr = (int *)(userCount * 4 + userList[2]);
                                userList[1] = userCount + 1;
                              }
                              else {
                                userElementPtr = (int *)Vector__elementRefGrow(userList,userCount);
                              }
                              *userElementPtr = cloneResult;
                              break;
                            }
                            userCount = userListRef[1];
                            userIndex = userIndex + 1;
                            userList = userListRef;
                          } while (userIndex < userCount);
                        }
                        operandIndexB = operandIndexB + 1;
                      } while (operandIndexB <= *(int *)(cloneResult + 0x84));
                    }
                    Block__insertInstAfter(block,cloneResult,inst);
                  }
                }
                nextInst = (int *)inst[2];
              }
              lookaheadInst = (int *)nextInst[2];
              inst = nextInst;
            } while ((int *)nextInst[2] != (int *)0x0);
            successorBlock = *(int *)(block + 8);
          }
          block = successorBlock;
          nextBlockB = *(int *)(successorBlock + 8);
        }
        instVector = *(int *)(program + PROG_instructionVector);
        instByteOffset = 0;
        *(int *)(program + PROG_visitStamp) = *(int *)(program + PROG_visitStamp) + 1;
        currentInst = 0;
        for (instOrdinal = 1; queuedCount = vecCount, instOrdinal <= *(uint *)(instVector + 4); instOrdinal = instOrdinal + 1) {
          candidateInst = *(int *)(*(int *)(instVector + 8) + instByteOffset);
          currentInst = candidateInst;
          if ((*(uint *)(candidateInst + 0x14) & 1) != 0) {
            if (vecCount < vecCapacity) {
              byteOffset = vecCount * 4;
              _memset(byteOffset + vecData,0,4);
              vecCount = queuedCount + 1;
              elementPtr = (int *)(byteOffset + vecData);
            }
            else {
              elementPtr = (int *)Vector__elementRefGrow(&vecCapacity,vecCount);
            }
            *elementPtr = candidateInst;
            instVector = *(int *)(program + PROG_instructionVector);
          }
          instByteOffset = instByteOffset + 4;
        }
        do {
          do {
            if (vecCount == 0) {
              *(uint *)(program + PROG_flags) = *(uint *)(program + PROG_flags) | 0x20000;
              Program__beginPass(program,"reduce");
              *(uint *)(program + PROG_flags) = *(uint *)(program + PROG_flags) | 0x80;
              Arena__free(vecArena,vecData);
              return;
            }
            topIndex = vecCount - 1;
            topElementPtr = (int *)0x0;
            if (topIndex < vecCount) {
              topElementPtr = (int *)(topIndex * 4 + vecData);
            }
            poppedInstB = *topElementPtr;
            Vector__removeAt(&vecCapacity,topIndex);
            operandCount = *(int *)(poppedInstB + 0x84);
            *(undefined4 *)(poppedInstB + 0x150) = *(undefined4 *)(program + PROG_visitStamp);
            if ((*(uint *)(poppedInstB + 0x14) & 0x200) != 0) {
              operandCount = operandCount + -1;
            }
          } while (operandCount < 1);
          sourceIndex = 1;
          do {
            operandSourceInst = (int *)IRInst__getOperandSource(poppedInstB,sourceIndex);
            vecCountBefore = vecCount;
            if (operandSourceInst != (int *)0x0) {
              if (*(int *)(program + PROG_visitStamp) != operandSourceInst[0x54]) {
                if (vecCount < vecCapacity) {
                  byteOffsetB = vecCount * 4;
                  _memset(byteOffsetB + vecData,0,4);
                  vecCount = vecCountBefore + 1;
                  pushSlot = (undefined4 *)(byteOffsetB + vecData);
                }
                else {
                  pushSlot = (undefined4 *)Vector__elementRefGrow(&vecCapacity,vecCount);
                }
                *pushSlot = operandSourceInst;
              }
              if (((((operandSourceInst[0x20] != 0) && (predicateResult = RegKind__flagBit0(operandSourceInst[0x26]), predicateResult != 0)) &&
                   ((operandSourceInst[5] & 2U) == 0)) &&
                  (predicateResult = (**(code **)(*operandSourceInst + 0x50))(operandSourceInst), predicateResult == 0)) ||
                 ((predicateResult = RegKind__flagBit7(operandSourceInst[0x26]), predicateResult != 0 ||
                  (predicateResult = RegKind__flagBit8(operandSourceInst[0x26]), predicateResult != 0)))) {
                operandRecord4 = IRInst__getOperandRecord(poppedInstB,sourceIndex);
                SelectWord__readMask(&selectReadMask,*(undefined4 *)(operandRecord4 + 0x10));
                componentIndex = 0;
                selectReadMaskBytes = selectReadMask;
                defInst = operandSourceInst;
code_r0x0013f320:
                do {
                  predicateResultC = RegKind__flagBit6(defInst[0x26]);
                  vecCountBefore = vecCount;
                  if (predicateResultC == 0) {
                    if (*(int *)(program + PROG_visitStamp) != defInst[0x54]) {
                      if (vecCount < vecCapacity) {
                        byteOffsetD = vecCount * 4;
                        _memset(byteOffsetD + vecData,0,4);
                        pushSlot = (undefined4 *)(byteOffsetD + vecData);
                        vecCount = vecCountBefore + 1;
                      }
                      else {
                        pushSlot = (undefined4 *)Vector__elementRefGrow(&vecCapacity,vecCount);
                      }
                      *pushSlot = defInst;
                    }
                    vec2Capacity = defInst[3];
                    if ((*(char *)((int)&selectReadMaskBytes + componentIndex) != '\0') &&
                       (*(char *)((int)&vec2Capacity + componentIndex) == '\0')) {
                      lastOperandIndex = defInst[0x21];
                      destOperandRecordB = IRInst__getOperandRecord(defInst,lastOperandIndex);
                      operandSelectBytes = *(int *)(destOperandRecordB + 0x10);
                      if (*(char *)((int)&operandSelectBytes + componentIndex) == '\x04') {
                        *(char *)((int)&operandSelectBytes + componentIndex) = (char)componentIndex;
                        fixedSelectWord = operandSelectBytes;
                        if (lastOperandIndex == 0) {
                          defInst[0x27] = operandSelectBytes;
                        }
                        else {
                          lastOperandRecord = IRInst__getOperandRecord(defInst,lastOperandIndex);
                          *(int *)(lastOperandRecord + 0x10) = fixedSelectWord;
                        }
                        defInst = (int *)IRInst__getOperandSource(defInst,defInst[0x21]);
                        if (defInst != (int *)0x0) goto code_r0x0013f320;
                      }
                    }
                  }
                  moreComponents = componentIndex != 3;
                  componentIndex = componentIndex + 1;
                  defInst = operandSourceInst;
                } while (moreComponents);
              }
            }
            sourceIndex = sourceIndex + 1;
          } while (sourceIndex <= operandCount);
        } while( true );
      }
      topIndex = vecCount - 1;
      topSlot = (undefined4 *)0x0;
      if (topIndex < vecCount) {
        topSlot = (undefined4 *)(topIndex * 4 + vecData);
      }
      workInst = (int *)*topSlot;
      Vector__removeAt(&vecCapacity,topIndex);
      vcall30Result = (**(code **)(*workInst + 0x30))(workInst);
      if (((vcall30Result != 0) && (-1 < workInst[0x4d])) &&
         (*(int *)(workInst[0x4d] * 0xc + *(int *)(program + 0x78) + 4) - 10U < 2)) {
        firstOperandSource = IRInst__getOperandSource(workInst,1);
        producerInst = (int *)FUN_001382b8(firstOperandSource,3,&currentInst);
        if ((producerInst != (int *)0x0) && (vcall30Result = (**(code **)(*producerInst + 0x50))(), vcall30Result != 0)) {
          (**(code **)(*workInst + 0x88))(workInst,1,3,4);
        }
      }
      if ((workInst[5] & 0x200U) == 0) {
        operandCount = workInst[0x21];
      }
      else {
        operandCount = workInst[0x21] + -1;
      }
    } while (operandCount < 1);
    operandIndexB = 1;
    globalsBase = &UNK_001ada48;
    do {
      operandVReg = (int *)IRInst__getOperandSource(workInst,operandIndexB);
      if (operandVReg != (int *)0x0) {
        if ((((operandVReg[0x20] == 0) || (predicateResultC = RegKind__flagBit0(operandVReg[0x26]), predicateResultC == 0)) ||
            (((operandVReg[5] & 2U) != 0 ||
             (predicateResultC = (**(code **)(*operandVReg + 0x50))(operandVReg), predicateResultC != 0)))) &&
           (predicateResultC = RegKind__flagBit7(operandVReg[0x26]), predicateResultC == 0)) {
          flagBit8Result = RegKind__flagBit8(operandVReg[0x26]);
          replacesWriteMask = false;
          if (flagBit8Result != 0) goto code_r0x0013e0ac;
        }
        else {
code_r0x0013e0ac:
          replacesWriteMask = true;
        }
        vec2Capacity = *(uint *)(globalsBase + 0x25d8);
        operandLimitB = (**(code **)(*workInst + 0x14))(workInst);
        if (operandIndexB <= operandLimitB) {
          FUN_000f403c(&operandReadMaskOutA,workInst,operandIndexB,workInst[3],program);
          vec2Capacity = operandReadMaskOutA;
        }
        identitySelectC = DAT_001b0000;
        if ((((char)vec2Capacity == '\0' && (*(unsigned char *)((unsigned char *)&(vec2Capacity) + 2)) == '\0') && (*(unsigned char *)((unsigned char *)&(vec2Capacity) + 1)) == '\0') &&
            (*(unsigned char *)((unsigned char *)&(vec2Capacity) + 0)) == '\0') {
          if (operandIndexB == 0) {
            workInst[0x27] = DAT_001b0000;
          }
          else {
            selectRecord = IRInst__getOperandRecord(workInst,operandIndexB);
            *(int *)(selectRecord + 0x10) = identitySelectC;
          }
        }
        replacesWriteMask = !replacesWriteMask;
        if (replacesWriteMask) {
          vec2Capacity = 0x1000000;
        }
        rootCursor = -1;
        while (vec2Capacity != 0) {
          if (*(int *)(operandVReg[0x22] + 8) == 0x8e) {
            chainInst = (**(code **)(*operandVReg + 0x7c))(operandVReg);
            mergedMask = vec2Capacity;
            if (chainInst == 0) {
              mergeTarget = 0;
            }
            else {
              prevRoot = rootCursor;
              prevMergeTarget = 0;
              do {
                disjointSetFindRootResult = disjointSetFindRoot(*(undefined4 *)(chainInst + 0x14c),unionFindParents);
                destOperandRecordB = IRInst__getOperandRecord(chainInst,0);
                WriteMask__fromSelectWord(&chainedWriteMask,*(undefined4 *)(destOperandRecordB + 0x10));
                if ((prevRoot == disjointSetFindRootResult) ||
                   (rootCursor = prevRoot, mergeTarget = prevMergeTarget, (chainedWriteMask & mergedMask) != 0)) {
                  mergedMask = mergedMask | chainedWriteMask;
                  rootCursor = disjointSetFindRootResult;
                  if ((-1 < prevRoot) && (rootCursor = prevRoot, prevRoot != disjointSetFindRootResult)) {
                    storeIndexedWord(prevRoot,disjointSetFindRootResult,unionFindParents);
                  }
                  mergeTarget = chainInst;
                  if (prevMergeTarget != 0) {
                    *(undefined4 *)(chainInst + 0xc) = 0;
                    *(int *)(chainInst + 0x9c) = DAT_001b0014;
                    mergeTarget = prevMergeTarget;
                  }
                }
                chainInst = *(int *)(chainInst + 300);
                prevRoot = rootCursor;
                prevMergeTarget = mergeTarget;
              } while (chainInst != 0);
            }
            queuedCount = vecCount;
            if (*(uint *)(mergeTarget + 0xc) != mergedMask) {
              if (vecCount < vecCapacity) {
                byteOffsetC = vecCount * 4;
                _memset(byteOffsetC + vecData,0,4);
                vecCount = queuedCount + 1;
                growSlotPtr = (int *)(byteOffsetC + vecData);
              }
              else {
                growSlotPtr = (int *)Vector__elementRefGrow(&vecCapacity,vecCount);
              }
              *growSlotPtr = mergeTarget;
              *(uint *)(mergeTarget + 0xc) = mergedMask;
              SelectWord__selectWhereMasked(&mergedSelectWord,DAT_001b0008,mergedMask);
              *(undefined4 *)(mergeTarget + 0x9c) = mergedSelectWord;
            }
            vec2Capacity = 0;
          }
          else {
            destOperandRecord = IRInst__getOperandRecord(operandVReg,0);
            WriteMask__fromSelectWord(&operandWriteMask,*(undefined4 *)(destOperandRecord + 0x10));
            defWriteMask = operandWriteMask;
            if (((replacesWriteMask) || (resolvedRoot = rootCursor, (operandWriteMask & vec2Capacity) != 0)) &&
               (resolvedRoot = disjointSetFindRoot(operandVReg[0x53],unionFindParents), -1 < rootCursor)) {
              storeIndexedWord(rootCursor,resolvedRoot,unionFindParents);
              resolvedRoot = rootCursor;
            }
            queuedCount = vecCount;
            oldWriteMask = operandVReg[3];
            if (replacesWriteMask) {
              operandVReg[3] = defWriteMask;
            }
            else {
              operandVReg[3] = defWriteMask & vec2Capacity | oldWriteMask;
            }
            if (oldWriteMask != operandVReg[3]) {
              if (vecCount < vecCapacity) {
                byteOffsetD = vecCount * 4;
                _memset(byteOffsetD + vecData,0,4);
                vecCount = queuedCount + 1;
                pushSlot = (undefined4 *)(byteOffsetD + vecData);
              }
              else {
                pushSlot = (undefined4 *)Vector__elementRefGrow(&vecCapacity,vecCount);
              }
              *pushSlot = operandVReg;
            }
            if (replacesWriteMask) break;
            isProjectionOf2a = IRInst__isProjectionOfOpcode2a(operandVReg);
            if (isProjectionOf2a == 0) {
              coveredMask = defWriteMask & vec2Capacity;
              uncoveredMask = (vec2Capacity << 0x18 | (vec2Capacity >> 8 & 0xff) << 0x10 |
                       (vec2Capacity >> 0x10 & 0xff) << 8 | vec2Capacity >> 0x18) -
                      (coveredMask << 0x18 | (coveredMask >> 8 & 0xff) << 0x10 |
                       (coveredMask >> 0x10 & 0xff) << 8 | coveredMask >> 0x18);
              vec2Capacity = uncoveredMask * 0x1000000 | (uncoveredMask & 0xff00) << 8 | uncoveredMask >> 8 & 0xff00 |
                         uncoveredMask >> 0x18;
            }
            rootCursor = resolvedRoot;
            if (vec2Capacity != 0) {
              operandVReg = (int *)IRInst__getOperandSource(operandVReg,operandVReg[0x21]);
            }
          }
        }
      }
      operandIndexB = operandIndexB + 1;
    } while (operandIndexB <= operandCount);
  } while( true );
}
#undef vec2Capacity
#undef vec2Count
#undef vec2Data
#undef vec2Arena
#undef vecCapacity
#undef vecCount
#undef vecData
#undef vecArena

/* FUN_0013f3d4 @ 0x13f3d4 (2148 bytes) */
int FUN_0013f3d4(inst, program)
  int *inst;
  int program;
{
  int vcall64Result;
  int loopIndex3;
  bool moreComponents;
  undefined4 sourceDef4;
  int sourceDef3;
  int operandRecord2;
  int sourceDef2;
  int sourceDef;
  int operandRecord;
  uint loopIndex;
  bool bVar1;
  char cVar2;
  uint uVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  uint uVar10;
  int *operandVReg;
  char cVar12;
  int loopIndexB;
  undefined4 uVar14;
  uint loopIndex2;
  bool bVar16;
  code *pcVar17;
  uint uVar18;
  uint *puVar19;
  int countdown;
  int local_48;
  undefined4 local_44;
  int local_40 [2];
  int local_38 [2];
  
  uVar3 = inst[5];
  if ((uVar3 & 0x200) == 0) {
    if ((uVar3 & 0x400000) == 0) {
      return true;
    }
    piVar4 = (int *)inst[4];
    if (piVar4[1] != 1) {
      return false;
    }
    if (*piVar4 == 0) {
      puVar5 = (undefined4 *)Vector__elementRefGrow(piVar4,0);
    }
    else {
      puVar5 = (undefined4 *)piVar4[2];
    }
    piVar4 = (int *)*puVar5;
    uVar3 = piVar4[5];
    if ((uVar3 & 0x200) != 0) {
      IRInst__getOperandSource(piVar4,piVar4[0x21]);
      uVar3 = piVar4[5];
    }
    bVar16 = (uVar3 & 0x400000) == 0;
  }
  else {
    if ((uVar3 & 0x400000) != 0) {
      return false;
    }
    bVar16 = true;
    piVar4 = (int *)IRInst__getOperandSource(inst,inst[0x21]);
  }
  vcall64Result = (**(code **)(*piVar4 + 100))(piVar4);
  if (vcall64Result != 0) {
    iVar6 = IRInst__getOperandSource(inst,1);
    sourceDef2 = IRInst__getOperandSource(inst,2);
    sourceDef3 = IRInst__getOperandSource(piVar4,1);
    if (iVar6 == sourceDef3) {
      uVar14 = 2;
      iVar8 = 1;
      iVar6 = sourceDef2;
    }
    else {
      if (sourceDef2 != sourceDef3) {
        return false;
      }
      uVar14 = 1;
      iVar8 = 2;
    }
    if ((inst[0x48] == piVar4[0x48]) && (inst[0x49] == piVar4[0x49])) {
      if ((((uint)inst[iVar8 * 6 + 0x28] >> 1 & 1) == ((uint)piVar4[0x2e] >> 1 & 1)) &&
         ((inst[iVar8 * 6 + 0x28] & 1U) == (piVar4[0x2e] & 1U))) {
        operandRecord2 = IRInst__getOperandRecord(inst,0);
        local_48 = *(int *)(operandRecord2 + 0x10);
        operandRecord2 = IRInst__getOperandRecord(piVar4,0);
        loopIndexB = 0;
        local_44 = *(undefined4 *)(operandRecord2 + 0x10);
        countdown = 4;
        do {
          if ((*(char *)((int)&local_48 + loopIndexB) != '\x01') &&
             (*(char *)((int)local_40 + loopIndexB + -4) != '\x01')) {
            return false;
          }
          loopIndexB = loopIndexB + 1;
          countdown = countdown + -1;
        } while (countdown != 0);
        loopIndexB = 0;
        SelectWord__mergeWrittenLanes(local_38,local_48,*(undefined4 *)(operandRecord2 + 0x10));
        inst[0x27] = local_38[0];
        local_48 = local_38[0];
        piVar9 = (int *)((int (*)())IRInst__createWithConstantOperands)(2,local_38[0],iVar6,program,*(undefined4 *)(program + 8),
                                     (double)FLOAT_001aa0d4);
        do {
          if (*(char *)((int)&local_48 + loopIndexB) == '\0') {
            operandRecord = IRInst__getOperandRecord(piVar4,1);
            cVar12 = *(char *)(loopIndexB + operandRecord + 0x10);
            if (cVar12 == '\x04') {
              pcVar17 = *(code **)(*piVar9 + 0x88);
              operandRecord = IRInst__getOperandRecord(inst,uVar14);
              (*pcVar17)(piVar9,1,loopIndexB,*(undefined1 *)(loopIndexB + operandRecord + 0x10));
            }
            else {
              (**(code **)(*piVar9 + 0x88))(piVar9,2,loopIndexB,loopIndexB);
            }
            operandRecord = IRInst__getOperandRecord(inst,iVar8);
            cVar2 = *(char *)(loopIndexB + operandRecord + 0x10);
            if (cVar2 == '\x04') {
              iVar6 = *inst;
            }
            else {
              iVar6 = *inst;
              cVar12 = cVar2;
            }
            (**(code **)(iVar6 + 0x88))(inst,iVar8,loopIndexB,cVar12);
            (**(code **)(*inst + 0x88))(inst,uVar14,loopIndexB,loopIndexB);
          }
          moreComponents = loopIndexB != 3;
          loopIndexB = loopIndexB + 1;
        } while (moreComponents);
        IRInst__setOperandSource(inst,uVar14,piVar9,1,*(undefined4 *)(program + 8));
        Block__insertInstBefore(inst[0x56],inst,piVar9);
        if (((inst[5] & 0x200U) == 0) || ((piVar4[5] & 0x200U) != 0)) {
          if (((inst[5] & 0x200U) == 0) || ((piVar4[5] & 0x200U) == 0)) {
            puVar19 = (uint *)piVar4[4];
            uVar3 = puVar19[1];
            uVar18 = uVar3 - 1;
            if (-1 < (int)uVar18) {
              iVar6 = uVar18 * 4;
              loopIndex2 = 0;
              do {
                if (uVar18 < *puVar19) {
                  uVar10 = puVar19[1];
                  if (uVar10 <= uVar18) {
                    _memset(uVar10 * 4 + puVar19[2],0,(uVar18 - uVar10) * 4 + 4);
                    puVar19[1] = uVar18 + 1;
                  }
                  puVar5 = (undefined4 *)(iVar6 + puVar19[2]);
                }
                else {
                  puVar5 = (undefined4 *)Vector__elementRefGrow(puVar19,uVar18);
                }
                piVar9 = (int *)*puVar5;
                for (iVar7 = 1; iVar8 = (**(code **)(*piVar9 + 0x14))(piVar9), iVar7 <= iVar8;
                    iVar7 = iVar7 + 1) {
                  operandVReg = (int *)IRInst__getOperandSource(piVar9,iVar7);
                  if (piVar4 == operandVReg) {
                    IRInst__setOperandSource(piVar9,iVar7,inst,1,*(undefined4 *)(program + 8));
                    goto LAB_0013fad0;
                  }
                }
                if (((piVar9[5] & 0x200U) != 0) &&
                   (operandVReg = (int *)IRInst__getOperandSource(piVar9,piVar9[0x21]), piVar4 == operandVReg)) {
                  IRInst__setExtraOperandSource(piVar9,inst,1,*(undefined4 *)(program + 8));
                }
LAB_0013fad0:
                loopIndex2 = loopIndex2 + 1;
                uVar18 = uVar18 - 1;
                iVar6 = iVar6 + -4;
                if (loopIndex2 == uVar3) break;
                puVar19 = (uint *)piVar4[4];
              } while( true );
            }
            uVar14 = *(undefined4 *)(program + 8);
            sourceDef = IRInst__getOperandSource(piVar4,piVar4[0x21]);
            puVar19 = *(uint **)(sourceDef + 0x10);
            uVar3 = puVar19[1];
            if (0 < (int)uVar3) {
              loopIndex = 0;
              do {
                if (loopIndex < *puVar19) {
                  if (uVar3 <= loopIndex) {
                    _memset(uVar3 * 4 + puVar19[2],0,(loopIndex - uVar3) * 4 + 4);
                    puVar19[1] = loopIndex + 1;
                  }
                  piVar9 = (int *)(loopIndex * 4 + puVar19[2]);
                }
                else {
                  piVar9 = (int *)Vector__elementRefGrow(puVar19,loopIndex);
                }
                if (piVar4 == (int *)*piVar9) {
                  Vector__removeAt(puVar19,loopIndex);
                  sourceDef = IRInst__getOperandSource(piVar4,piVar4[0x21]);
                  *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + -1;
                  break;
                }
                uVar3 = puVar19[1];
                loopIndex = loopIndex + 1;
              } while ((int)loopIndex < (int)uVar3);
            }
            IRInst__setOperandSource(piVar4,piVar4[0x21],0,1,uVar14);
            piVar4[0x21] = piVar4[0x21] + -1;
            piVar4[5] = piVar4[5] & 0xfffffdff;
          }
          else {
            loopIndex3 = 0;
            operandRecord = IRInst__getOperandRecord(inst,inst[0x21]);
            local_40[0] = *(int *)(operandRecord + 0x10);
            do {
              operandRecord = IRInst__getOperandRecord(inst,0);
              if (*(char *)(loopIndex3 + operandRecord + 0x10) != '\x01') {
                *(undefined1 *)((int)local_40 + loopIndex3) = 4;
              }
              moreComponents = loopIndex3 != 3;
              loopIndex3 = loopIndex3 + 1;
            } while (moreComponents);
            uVar14 = *(undefined4 *)(program + 8);
            sourceDef = IRInst__getOperandSource(inst,inst[0x21]);
            puVar19 = *(uint **)(sourceDef + 0x10);
            uVar3 = puVar19[1];
            if (0 < (int)uVar3) {
              loopIndex = 0;
              do {
                if (loopIndex < *puVar19) {
                  if (uVar3 <= loopIndex) {
                    _memset(uVar3 * 4 + puVar19[2],0,(loopIndex - uVar3) * 4 + 4);
                    puVar19[1] = loopIndex + 1;
                  }
                  piVar9 = (int *)(loopIndex * 4 + puVar19[2]);
                }
                else {
                  piVar9 = (int *)Vector__elementRefGrow(puVar19,loopIndex);
                }
                if (inst == (int *)*piVar9) {
                  Vector__removeAt(puVar19,loopIndex);
                  sourceDef = IRInst__getOperandSource(inst,inst[0x21]);
                  *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + -1;
                  break;
                }
                uVar3 = puVar19[1];
                loopIndex = loopIndex + 1;
              } while ((int)loopIndex < (int)uVar3);
            }
            IRInst__setOperandSource(inst,inst[0x21],0,1,uVar14);
            bVar1 = local_40[0] != DAT_001b0000;
            inst[0x21] = inst[0x21] + -1;
            inst[5] = inst[5] & 0xfffffdff;
            if (bVar1) {
              sourceDef4 = IRInst__getOperandSource(piVar4,piVar4[0x21]);
              IRInst__setExtraOperandSource(inst,sourceDef4,1,*(undefined4 *)(program + 8));
              iVar6 = local_40[0];
              if (inst[0x21] == 0) {
                inst[0x27] = local_40[0];
              }
              else {
                operandRecord2 = IRInst__getOperandRecord(inst,inst[0x21]);
                *(int *)(operandRecord2 + 0x10) = iVar6;
              }
            }
          }
        }
        else {
          uVar14 = *(undefined4 *)(program + 8);
          sourceDef = IRInst__getOperandSource(inst,inst[0x21]);
          puVar19 = *(uint **)(sourceDef + 0x10);
          uVar3 = puVar19[1];
          if (0 < (int)uVar3) {
            loopIndex = 0;
            do {
              if (loopIndex < *puVar19) {
                if (uVar3 <= loopIndex) {
                  _memset(uVar3 * 4 + puVar19[2],0,(loopIndex - uVar3) * 4 + 4);
                  puVar19[1] = loopIndex + 1;
                }
                piVar9 = (int *)(loopIndex * 4 + puVar19[2]);
              }
              else {
                piVar9 = (int *)Vector__elementRefGrow(puVar19,loopIndex);
              }
              if (inst == (int *)*piVar9) {
                Vector__removeAt(puVar19,loopIndex);
                sourceDef = IRInst__getOperandSource(inst,inst[0x21]);
                *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + -1;
                break;
              }
              uVar3 = puVar19[1];
              loopIndex = loopIndex + 1;
            } while ((int)loopIndex < (int)uVar3);
          }
          IRInst__setOperandSource(inst,inst[0x21],0,1,uVar14);
          inst[0x21] = inst[0x21] + -1;
          inst[5] = inst[5] & 0xfffffdff;
        }
        if (*(int *)(piVar4[4] + 4) == 0) {
          (**(code **)(*piVar4 + 0xc))(piVar4,1,*(undefined4 *)(program + 8));
        }
        if (bVar16 == false) {
          inst[5] = inst[5] | 0x400000;
          return false;
        }
        return bVar16;
      }
    }
  }
  return false;
}

/* FUN_0013fc38 @ 0x13fc38 (4516 bytes) */
int FUN_0013fc38(pass)
  int pass;
{
  uint loopIndexD;
  uint loopIndexC;
  uint loopIndexB;
  int loopIndex;
  bool moreComponents;
  undefined4 vectorData;
  undefined4 arena;
  int sourceDef;
  int operandRecord;
  int operandRecord2;
  int operandRecord3;
  undefined4 arenaAt378;
  undefined4 *vectorAlloc2;
  int *operandVReg3;
  char cVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int *piVar5;
  int splitRgbAlphaEnabled;
  undefined4 *allocation;
  undefined4 *vectorAlloc;
  int iVar9;
  uint *puVar10;
  int *piVar11;
  undefined4 *puVar12;
  int iVar13;
  int iVar14;
  int *piVar15;
  int *operandVReg;
  int *operandVReg2;
  uint uVar18;
  undefined4 *puVar19;
  bool bVar20;
  int iVar21;
  bool bVar22;
  int iVar23;
  uint uVar24;
  int iVar25;
  uint uVar26;
  uint uVar27;
  uint *puVar28;
  uint uVar29;
  undefined4 uVar30;
  int *piVar31;
  uint uVar32;
  undefined4 uVar33;
  undefined4 uVar34;
  uint uVar35;
  undefined4 local_88;
  uint local_84;
  undefined4 local_80;
  undefined4 local_7c;
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/uVar34) used with Vector__elementRefGrow - vecCapacity/vecCount/vecData/vecArena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_78_buf [0x10];
  #define vecCapacity (*(uint *)(local_78_buf + 0x00))
  #define vecCount (*(uint *)(local_78_buf + 0x04))
  #define vecData (*(int *)(local_78_buf + 0x08))
  #define vecArena (*(undefined4 *)(local_78_buf + 0x0c))
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54 [3];
  
  splitRgbAlphaEnabled = Compiler__isOptionEnabled(*(undefined4 *)(pass + 8),0x30);
  arena = *(undefined4 *)(*(int *)(pass + 8) + 0x378);
  allocation = (undefined4 *)Arena__alloc(arena,0x14);
  puVar28 = allocation + 1;
  *allocation = arena;
  allocation[1] = 2;
  allocation[4] = arena;
  allocation[2] = 0;
  vectorData = Arena__alloc(arena,8);
  allocation[3] = vectorData;
  arena = *(undefined4 *)(*(int *)(pass + 8) + 0x378);
  vectorAlloc = (undefined4 *)Arena__alloc(arena,0x14);
  *vectorAlloc = arena;
  vectorAlloc[1] = 2;
  vectorAlloc[4] = arena;
  vectorAlloc[2] = 0;
  vectorData = Arena__alloc(arena,8);
  vectorAlloc[3] = vectorData;
  vecArena = *(undefined4 *)(*(int *)(pass + 8) + 0x378);
  vecCount = 0;
  vecCapacity = 2;
  vecData = Arena__alloc(vecArena,8);
  local_5c = *(undefined4 *)(*(int *)(pass + 8) + 0x378);
  local_64 = 0;
  local_68 = 2;
  local_60 = Arena__alloc(local_5c,8);
  iVar25 = *(int *)(pass + 900);
  iVar4 = *(int *)(iVar25 + 8);
  do {
    if (iVar4 == 0) {
      Arena__free(local_5c,local_60);
      Arena__free(vecArena,vecData);
      return;
    }
    allocation[2] = 0;
    vectorAlloc[2] = 0;
    local_64 = 0;
    vecCount = 0;
    piVar11 = *(int **)(iVar25 + 0x98);
    for (piVar5 = (int *)(*(int **)(iVar25 + 0x98))[2]; piVar5 != (int *)0x0;
        piVar5 = (int *)piVar5[2]) {
      if ((piVar11[5] & 1U) != 0) {
        operandRecord2 = IRInst__getOperandRecord(piVar11,0);
        iVar4 = *(int *)(operandRecord2 + 0x10);
        if (((*(int *)(piVar11[0x22] + 8) == 0x12) &&
            (iVar9 = ((int (*)())FUN_0013f3d4)(piVar11,pass), iVar9 != 0)) && (iVar4 != 0x1010101)) {
          if (splitRgbAlphaEnabled == 0) {
            if (iVar4 != 0) goto LAB_0013fe30;
          }
          else if ((iVar4 != 0x1010100) && (iVar4 != 1)) {
LAB_0013fe30:
            uVar32 = allocation[2];
            uVar26 = 0;
            if (uVar32 != 0) {
              do {
                if (uVar26 < *puVar28) {
                  if (uVar32 <= uVar26) {
                    _memset(uVar32 * 4 + allocation[3],0,(uVar26 - uVar32) * 4 + 4);
                    allocation[2] = uVar26 + 1;
                  }
                  piVar5 = (int *)(uVar26 * 4 + allocation[3]);
                }
                else {
                  piVar5 = (int *)Vector__elementRefGrow(puVar28,uVar26);
                }
                iVar4 = *piVar5;
                for (iVar9 = 1; iVar13 = (**(code **)(*piVar11 + 0x14))(piVar11), iVar9 <= iVar13;
                    iVar9 = iVar9 + 1) {
                  iVar13 = IRInst__getOperandSource(piVar11,iVar9);
                  if (iVar4 == iVar13) {
                    uVar32 = allocation[2];
                    if (uVar32 < *puVar28) {
                      _memset(uVar32 * 4 + allocation[3],0,4);
                      allocation[2] = uVar32 + 1;
                      puVar12 = (undefined4 *)(uVar32 * 4 + allocation[3]);
                    }
                    else {
                      puVar12 = (undefined4 *)Vector__elementRefGrow(puVar28,uVar32);
                    }
                    *puVar12 = 0;
                    if (vecCount < vecCapacity) {
                      iVar4 = vecCount * 4;
                      *(undefined4 *)(iVar4 + vecData) = 0;
                      vecCount = vecCount + 1;
                      puVar12 = (undefined4 *)(iVar4 + vecData);
                    }
                    else {
                      puVar12 = (undefined4 *)Vector__elementRefGrow(&vecCapacity,vecCount);
                    }
                    *puVar12 = 0;
                    goto LAB_0013ff84;
                  }
                }
                uVar32 = allocation[2];
                uVar26 = uVar26 + 1;
              } while (uVar26 < uVar32);
            }
LAB_0013ff84:
            uVar34 = ((int (*)())FUN_0013a644)(piVar11);
            uVar32 = allocation[2];
            if (uVar32 < *puVar28) {
              _memset(uVar32 * 4 + allocation[3],0,4);
              allocation[2] = uVar32 + 1;
              piVar5 = (int *)(uVar32 * 4 + allocation[3]);
            }
            else {
              piVar5 = (int *)Vector__elementRefGrow(puVar28,uVar32);
            }
            *piVar5 = (int)piVar11;
            if (vecCount < vecCapacity) {
              iVar4 = vecCount * 4;
              vecCount = vecCount + 1;
              *(undefined4 *)(iVar4 + vecData) = 0;
              puVar12 = (undefined4 *)(iVar4 + vecData);
            }
            else {
              puVar12 = (undefined4 *)Vector__elementRefGrow(&vecCapacity,vecCount);
            }
            *puVar12 = uVar34;
            piVar5 = (int *)piVar11[2];
            goto LAB_00140024;
          }
        }
        piVar5 = (int *)piVar11[2];
      }
LAB_00140024:
      piVar11 = piVar5;
    }
    if (allocation[2] != 0) {
      uVar32 = 0;
      do {
        if (uVar32 < vecCapacity) {
          if (vecCount <= uVar32) {
            _memset(vecCount * 4 + vecData,0,(uVar32 - vecCount) * 4 + 4);
            vecCount = uVar32 + 1;
          }
          puVar10 = (uint *)(uVar32 * 4 + vecData);
        }
        else {
          puVar10 = (uint *)Vector__elementRefGrow(&vecCapacity,uVar32);
        }
        uVar26 = *puVar10;
        if (uVar32 < *puVar28) {
          uVar29 = allocation[2];
          if (uVar29 <= uVar32) {
            _memset(uVar29 * 4 + allocation[3],0,(uVar32 - uVar29) * 4 + 4);
            allocation[2] = uVar32 + 1;
            uVar29 = uVar32 + 1;
          }
          piVar11 = (int *)(uVar32 * 4 + allocation[3]);
        }
        else {
          piVar11 = (int *)Vector__elementRefGrow(puVar28,uVar32);
          uVar29 = allocation[2];
        }
        uVar27 = uVar32 + 1;
        iVar4 = *piVar11;
        if ((iVar4 != 0) && (uVar27 < uVar29)) {
          iVar9 = uVar27 * 4;
          uVar32 = uVar32 + 2;
LAB_00140128:
          uVar35 = uVar32 - 1;
          if (uVar35 < *puVar28) {
            if (uVar29 <= uVar35) {
              _memset(uVar29 * 4 + allocation[3],0,(uVar35 - uVar29) * 4 + 4);
              allocation[2] = uVar32;
            }
            puVar12 = (undefined4 *)(iVar9 + allocation[3]);
          }
          else {
            puVar12 = (undefined4 *)Vector__elementRefGrow(puVar28,uVar35);
          }
          piVar11 = (int *)*puVar12;
          if (piVar11 == (int *)0x0) goto LAB_00140d38;
          if (uVar35 < vecCapacity) {
            if (vecCount <= uVar35) {
              _memset(vecCount * 4 + vecData,0,(uVar35 - vecCount) * 4 + 4);
              vecCount = uVar32;
            }
            puVar10 = (uint *)(iVar9 + vecData);
          }
          else {
            puVar10 = (uint *)Vector__elementRefGrow(&vecCapacity,uVar35);
          }
          uVar29 = *puVar10;
          iVar13 = FUN_00139008(uVar26);
          iVar14 = FUN_00139008(uVar29);
          if (4 < iVar13 + iVar14) goto LAB_00140dc4;
          operandVReg3 = (int *)IRInst__getOperandSource(iVar4,1);
          piVar5 = (int *)IRInst__getOperandSource(iVar4,2);
          operandVReg = (int *)IRInst__getOperandSource(piVar11,1);
          operandVReg2 = (int *)IRInst__getOperandSource(piVar11,2);
          iVar13 = (*(uint *)(iVar4 + 0xb8) >> 1 & 1) + (*(uint *)(iVar4 + 0xb8) & 1) * 2;
          iVar21 = ((uint)piVar11[0x2e] >> 1 & 1) + (piVar11[0x2e] & 1U) * 2;
          iVar23 = (*(uint *)(iVar4 + 0xd0) >> 1 & 1) + (*(uint *)(iVar4 + 0xd0) & 1) * 2;
          iVar14 = ((uint)piVar11[0x34] >> 1 & 1) + (piVar11[0x34] & 1U) * 2;
          if ((operandVReg3 != operandVReg) || (bVar20 = true, iVar13 != iVar21)) {
            bVar20 = false;
          }
          if ((operandVReg3 != operandVReg2) || (bVar2 = true, iVar13 != iVar14)) {
            bVar2 = false;
          }
          if ((piVar5 != operandVReg) || (bVar22 = true, iVar23 != iVar21)) {
            bVar22 = false;
          }
          if ((piVar5 != operandVReg2) || (bVar3 = true, iVar23 != iVar14)) {
            bVar3 = false;
          }
          piVar31 = operandVReg2;
          if ((((!bVar20) && (piVar31 = operandVReg, !bVar2)) &&
              (piVar5 = operandVReg3, piVar31 = operandVReg2, !bVar22)) && (piVar31 = operandVReg, !bVar3))
          goto LAB_00140dc4;
          iVar9 = (**(code **)(*piVar5 + 0x60))(piVar5);
          if (iVar9 != 0) {
            piVar5 = (int *)IRInst__getOperandSource(piVar5,1);
          }
          iVar9 = (**(code **)(*piVar31 + 0x60))(piVar31);
          if (iVar9 == 0) {
            piVar15 = piVar31;
            piVar31 = (int *)0x0;
          }
          else {
            piVar15 = (int *)IRInst__getOperandSource(piVar31,1);
          }
          iVar9 = (**(code **)(*piVar5 + 0x48))(piVar5);
          if ((((iVar9 == 0) && (iVar9 = (**(code **)(*piVar15 + 0x48))(piVar15), iVar9 == 0)) &&
              ((iVar9 = (**(code **)(*piVar5 + 0x80))(piVar5), iVar9 == 0 &&
               (iVar9 = (**(code **)(*piVar15 + 0x80))(piVar15), iVar9 == 0)))) ||
             (iVar9 = FUN_0013905c(iVar4,piVar11), iVar9 == 0)) goto LAB_00140d38;
          if (uVar35 < *puVar28) {
            uVar18 = allocation[2];
            if (uVar18 <= uVar35) {
              _memset(uVar18 * 4 + allocation[3],0,(uVar35 - uVar18) * 4 + 4);
              allocation[2] = uVar32;
            }
            puVar12 = (undefined4 *)(uVar35 * 4 + allocation[3]);
          }
          else {
            puVar12 = (undefined4 *)Vector__elementRefGrow(puVar28,uVar35);
          }
          *puVar12 = 0;
          IRInst__setExtraOperandSource(piVar11,iVar4,1,*(undefined4 *)(pass + 8));
          DList__unlink(piVar11);
          Block__insertInstAfter(*(undefined4 *)(iVar4 + 0x158),iVar4,piVar11);
          if (piVar31 != (int *)0x0) {
            DList__unlink(piVar31);
            Block__insertInstAfter(*(undefined4 *)(iVar4 + 0x158),iVar4,piVar31);
          }
          uVar32 = ~(uVar26 | uVar29) & 0xf;
          local_84 = 0x10203;
          local_88 = 0x10203;
          iVar9 = IRInst__getOperandRecord(piVar11,0);
          local_80 = *(int *)(iVar9 + 0x10);
          cVar1 = (char)local_80;
          if ((uVar26 & uVar29) == 0) {
            *(int *)(pass + 0x278) = *(int *)(pass + 0x278) + 1;
            IRInst__setExtraOperandSource(piVar11,iVar4,1,*(undefined4 *)(pass + 8));
            operandRecord2 = IRInst__getOperandRecord(piVar11,piVar11[0x21]);
            *(undefined4 *)(operandRecord2 + 0x10) = 0x4040404;
            loopIndexC = 0;
            do {
              if (((int)uVar26 >> (loopIndexC & 0x3f) & 1U) != 0) {
                (**(code **)(*piVar11 + 0x88))(piVar11,piVar11[0x21],loopIndexC,loopIndexC);
              }
              moreComponents = loopIndexC != 3;
              loopIndexC = loopIndexC + 1;
            } while (moreComponents);
          }
          else {
            uVar18 = 0;
            loopIndexD = 0;
            puVar12 = &local_88;
            *(int *)(pass + 0x278) = *(int *)(pass + 0x278) + 1;
            uVar34 = 0;
            do {
              if ((((int)(uVar26 & uVar29) >> (loopIndexD & 0x3f) & 1U) != 0) && ((int)uVar18 < 4)) {
                uVar24 = uVar18;
                if (((int)uVar32 >> (uVar18 & 0x3f) & 1U) == 0) {
                  iVar9 = 4 - uVar18;
                  do {
                    uVar18 = uVar18 + 1;
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_001405bc;
                    uVar24 = uVar18;
                  } while (((int)uVar32 >> (uVar18 & 0x3f) & 1U) == 0);
                }
                *(char *)(loopIndexD + (int)puVar12) = (char)uVar24;
                uVar18 = uVar24 + 1;
                *(undefined1 *)((int)&local_80 + loopIndexD) = 1;
                *(char *)((int)&local_84 + uVar24) = (char)loopIndexD;
                *(undefined1 *)((int)&local_80 + uVar24) = 0;
              }
LAB_001405bc:
              moreComponents = loopIndexD != 3;
              loopIndexD = loopIndexD + 1;
            } while (moreComponents);
            piVar11[0x27] = local_80;
            operandRecord = IRInst__getOperandRecord(piVar11,piVar11[0x21]);
            *(undefined4 *)(operandRecord + 0x10) = 0x4040404;
            loopIndexC = 0;
            do {
              if (((int)uVar26 >> (loopIndexC & 0x3f) & 1U) != 0) {
                (**(code **)(*piVar11 + 0x88))
                          (piVar11,piVar11[0x21],*(undefined1 *)((int)&local_88 + loopIndexC),
                           *(undefined1 *)((int)&local_88 + loopIndexC));
              }
              moreComponents = loopIndexC != 3;
              loopIndexC = loopIndexC + 1;
            } while (moreComponents);
            if ((cVar1 == '\0') || ((char)local_80 != '\0')) {
              piVar5 = (int *)0x0;
            }
            else {
              puVar12 = *(undefined4 **)(pass + 8);
              sourceDef = IRInst__getOperandSource(piVar11,piVar11[0x21]);
              puVar10 = *(uint **)(sourceDef + 0x10);
              uVar32 = puVar10[1];
              if (0 < (int)uVar32) {
                loopIndexD = 0;
                do {
                  if (loopIndexD < *puVar10) {
                    if (uVar32 <= loopIndexD) {
                      _memset(uVar32 * 4 + puVar10[2],0,(loopIndexD - uVar32) * 4 + 4);
                      puVar10[1] = loopIndexD + 1;
                    }
                    piVar5 = (int *)(loopIndexD * 4 + puVar10[2]);
                  }
                  else {
                    piVar5 = (int *)Vector__elementRefGrow(puVar10,loopIndexD);
                  }
                  if ((int *)*piVar5 == piVar11) {
                    Vector__removeAt(puVar10,loopIndexD);
                    sourceDef = IRInst__getOperandSource(piVar11,piVar11[0x21]);
                    *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + -1;
                    break;
                  }
                  uVar32 = puVar10[1];
                  loopIndexD = loopIndexD + 1;
                } while ((int)loopIndexD < (int)uVar32);
              }
              IRInst__setOperandSource(piVar11,piVar11[0x21],0,1,puVar12);
              iVar9 = piVar11[0x21];
              piVar11[0x21] = iVar9 + -1;
              piVar11[5] = piVar11[5] & 0xfffffdff;
              operandRecord = IRInst__getOperandRecord(piVar11,iVar9 + -1);
              uVar33 = *(undefined4 *)(operandRecord + 0x10);
              piVar5 = (int *)IRInst__clone(piVar11,*(undefined4 *)(pass + 8),0);
              arenaAt378 = *(undefined4 *)(*(int *)(pass + 8) + 0x378);
              vectorAlloc2 = (undefined4 *)Arena__alloc(arenaAt378,0x14);
              vectorAlloc2[1] = 2;
              *vectorAlloc2 = arenaAt378;
              vectorAlloc2[2] = 0;
              vectorAlloc2[4] = arenaAt378;
              uVar30 = Arena__alloc(arenaAt378,8);
              vectorAlloc2[3] = uVar30;
              piVar5[4] = (int)(vectorAlloc2 + 1);
              piVar5[0x58] = *(int *)(*(int *)(*(int *)(pass + 8) + 0x6c4) + 0x478);
              IRInst__setExtraOperandSource(piVar11,iVar4,1,*(undefined4 *)(pass + 8));
              operandRecord = IRInst__getOperandRecord(piVar11,piVar11[0x21]);
              *(undefined4 *)(operandRecord + 0x10) = uVar33;
              *(undefined1 *)((int)piVar11 + 0x9f) = 1;
              piVar5[0x27] = 0x1010100;
              Block__insertInstAfter(piVar11[0x56],piVar11,piVar5);
              IRInst__setExtraOperandSource(piVar5,piVar11,1,*(undefined4 *)(pass + 8));
              operandRecord = IRInst__getOperandRecord(piVar5,piVar5[0x21]);
              *(undefined4 *)(operandRecord + 0x10) = 0x4040404;
              loopIndexC = 0;
              do {
                if ((((int)uVar29 >> (loopIndexC & 0x3f) & 1U) != 0) && (loopIndexC != 3)) {
                  (**(code **)(*piVar5 + 0x88))(piVar5,piVar5[0x21],loopIndexC,loopIndexC);
                }
                if ((((int)uVar26 >> (loopIndexC & 0x3f) & 1U) != 0) &&
                   (cVar1 = *(char *)((int)&local_88 + loopIndexC), cVar1 != '\x03')) {
                  (**(code **)(*piVar5 + 0x88))(piVar5,piVar5[0x21],cVar1,cVar1);
                }
                moreComponents = loopIndexC != 3;
                loopIndexC = loopIndexC + 1;
              } while (moreComponents);
              iVar14 = piVar5[0x53];
              iVar13 = piVar11[0x26];
              operandRecord = IRInst__getOperandRecord(piVar5,0);
              *(int *)(operandRecord + 0xc) = iVar13;
              *(int *)(operandRecord + 8) = iVar14;
              for (iVar9 = 1; iVar13 = (**(code **)(*piVar5 + 0x14))(piVar5), iVar9 <= iVar13;
                  iVar9 = iVar9 + 1) {
                iVar13 = IRInst__getOperandSource(piVar5,iVar9);
                puVar10 = *(uint **)(iVar13 + 0x10);
                uVar32 = puVar10[1];
                if (uVar32 < *puVar10) {
                  _memset(uVar32 * 4 + puVar10[2],0,4);
                  puVar19 = (undefined4 *)(uVar32 * 4 + puVar10[2]);
                  puVar10[1] = uVar32 + 1;
                }
                else {
                  puVar19 = (undefined4 *)Vector__elementRefGrow(puVar10,uVar32);
                }
                *puVar19 = piVar5;
              }
            }
            uVar32 = local_84 & 0xff;
            for (iVar9 = 1; iVar13 = (**(code **)(*piVar11 + 0x14))(piVar11), iVar9 <= iVar13;
                iVar9 = iVar9 + 1) {
              iVar13 = IRInst__getOperandRecord(piVar11,iVar9);
              iVar14 = 0;
              loopIndex = 0;
              local_7c = *(undefined4 *)(iVar13 + 0x10);
              do {
                if (*(char *)((int)&local_80 + loopIndex) == '\0') {
                  if ((piVar5 == (int *)0x0) || (loopIndex != 3)) {
                    iVar14 = iVar14 + 1;
                    (**(code **)(*piVar11 + 0x88))
                              (piVar11,iVar9,loopIndex,
                               (uint)*(byte *)((int)&local_7c +
                                              (uint)*(byte *)((int)&local_84 + loopIndex)),puVar12,
                               uVar34,(int)&local_88 + (uint)*(byte *)((int)&local_84 + loopIndex));
                  }
                  else {
                    (**(code **)(*piVar11 + 0x88))(piVar11,iVar9,3,4);
                    (**(code **)(*piVar5 + 0x88))
                              (piVar5,iVar9,3,*(undefined1 *)((int)&local_7c + uVar32));
                  }
                }
                else {
                  (**(code **)(*piVar11 + 0x88))(piVar11,iVar9,loopIndex,4);
                  if (piVar5 != (int *)0x0) {
                    (**(code **)(*piVar5 + 0x88))(piVar5,iVar9,loopIndex,4);
                  }
                }
                moreComponents = loopIndex != 3;
                loopIndex = loopIndex + 1;
              } while (moreComponents);
              if (iVar14 == 1) {
                IRInst__foldMovSourceSelect(&local_58,piVar11,iVar9,pass);
                uVar30 = local_58;
                iVar13 = IRInst__getOperandRecord(piVar11,iVar9);
                *(undefined4 *)(iVar13 + 0x10) = uVar30;
              }
              if (piVar5 != (int *)0x0) {
                IRInst__foldMovSourceSelect(local_54,piVar5,iVar9,pass);
                uVar30 = local_54[0];
                iVar13 = IRInst__getOperandRecord(piVar5,iVar9);
                *(undefined4 *)(iVar13 + 0x10) = uVar30;
              }
            }
            puVar10 = (uint *)piVar11[4];
            uVar32 = puVar10[1];
            uVar26 = uVar32 - 1;
            if (-1 < (int)uVar26) {
              iVar9 = uVar26 * 4;
              loopIndexB = 0;
              do {
                if (uVar26 < *puVar10) {
                  uVar35 = puVar10[1];
                  if (uVar35 <= uVar26) {
                    _memset(uVar35 * 4 + puVar10[2],0,(uVar26 - uVar35) * 4 + 4);
                    puVar10[1] = uVar26 + 1;
                  }
                  puVar12 = (undefined4 *)(iVar9 + puVar10[2]);
                }
                else {
                  puVar12 = (undefined4 *)Vector__elementRefGrow(puVar10,uVar26);
                }
                piVar15 = (int *)*puVar12;
                iVar13 = 1;
LAB_00140c04:
                iVar14 = (**(code **)(*piVar15 + 0x14))(piVar15);
                if (iVar13 <= iVar14) {
                  operandVReg = (int *)IRInst__getOperandSource(piVar15,iVar13);
                  if (operandVReg != piVar11) goto LAB_00140c00;
                  if (piVar5 != (int *)0x0) {
                    IRInst__setOperandSource(piVar15,iVar13,piVar5,1,*(undefined4 *)(pass + 8));
                  }
                  iVar14 = 0;
                  do {
                    operandRecord3 = IRInst__getOperandRecord(piVar15,iVar13);
                    uVar35 = (uint)*(byte *)(iVar14 + operandRecord3 + 0x10);
                    if (uVar35 != 4) {
                      (**(code **)(*piVar15 + 0x88))
                                (piVar15,iVar13,iVar14,*(undefined1 *)((int)&local_88 + uVar35));
                    }
                    moreComponents = iVar14 != 3;
                    iVar14 = iVar14 + 1;
                  } while (moreComponents);
                }
                loopIndexB = loopIndexB + 1;
                uVar26 = uVar26 - 1;
                iVar9 = iVar9 + -4;
                if (uVar32 == loopIndexB) break;
                puVar10 = (uint *)piVar11[4];
              } while( true );
            }
            puVar10 = *(uint **)(iVar4 + 0x10);
            uVar32 = puVar10[1];
            uVar26 = uVar32 - 1;
            if (-1 < (int)uVar26) {
              iVar9 = uVar26 * 4;
              loopIndexB = 0;
              do {
                if (uVar26 < *puVar10) {
                  uVar35 = puVar10[1];
                  if (uVar35 <= uVar26) {
                    _memset(uVar35 * 4 + puVar10[2],0,(uVar26 - uVar35) * 4 + 4);
                    puVar10[1] = uVar26 + 1;
                  }
                  puVar12 = (undefined4 *)(iVar9 + puVar10[2]);
                }
                else {
                  puVar12 = (undefined4 *)Vector__elementRefGrow(puVar10,uVar26);
                }
                piVar11 = (int *)*puVar12;
                for (iVar13 = 1; iVar14 = (**(code **)(*piVar11 + 0x14))(piVar11), iVar13 <= iVar14;
                    iVar13 = iVar13 + 1) {
                  iVar14 = IRInst__getOperandSource(piVar11,iVar13);
                  if (iVar4 == iVar14) {
                    if (piVar5 != (int *)0x0) {
                      IRInst__setOperandSource(piVar11,iVar13,piVar5,1,*(undefined4 *)(pass + 8));
                    }
                    break;
                  }
                }
                loopIndexB = loopIndexB + 1;
                uVar26 = uVar26 - 1;
                iVar9 = iVar9 + -4;
                if (uVar32 == loopIndexB) break;
                puVar10 = *(uint **)(iVar4 + 0x10);
              } while( true );
            }
          }
LAB_00140d38:
          uVar29 = allocation[2];
        }
LAB_00140d3c:
        uVar32 = uVar27;
      } while (uVar27 < uVar29);
    }
    iVar25 = *(int *)(iVar25 + 8);
    iVar4 = *(int *)(iVar25 + 8);
  } while( true );
LAB_00140dc4:
  uVar29 = allocation[2];
  iVar9 = iVar9 + 4;
  bVar20 = uVar29 <= uVar32;
  uVar32 = uVar32 + 1;
  if (bVar20) goto LAB_00140d3c;
  goto LAB_00140128;
LAB_00140c00:
  iVar13 = iVar13 + 1;
  goto LAB_00140c04;
}
#undef vecCapacity
#undef vecCount
#undef vecData
#undef vecArena

/* FUN_00140e5c @ 0x140e5c (20 bytes) */
int FUN_00140e5c(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(param_1 + 4) = param_2;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}

/* FUN_00140e70 @ 0x140e70 (12 bytes) */
int FUN_00140e70(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  *param_1 = *(undefined4 *)(param_3 + 0xc);
  return;
}

/* FUN_00140e7c @ 0x140e7c (456 bytes) */
int FUN_00140e7c(param_1, param_2, param_3)
  undefined4 *param_1;
  int *param_2;
  int *param_3;
{
  int iVar1;
  int iVar2;
  
  if ((((((*(int *)(param_2[0x22] + 8) == *(int *)(param_3[0x22] + 8)) &&
         (iVar1 = FUN_0011379c(*param_1,param_2), iVar1 != 0)) &&
        (iVar1 = (**(code **)(*param_2 + 100))(param_2), iVar1 == 0)) &&
       ((param_2[0x20] != 0 && (iVar1 = RegKind__flagBit0(param_2[0x26]), iVar1 != 0)))) &&
      (((param_2[5] & 2U) == 0 &&
       ((iVar1 = (**(code **)(*param_2 + 0x50))(param_2), iVar1 == 0 && (param_3[0x20] != 0)))))) &&
     ((iVar1 = RegKind__flagBit0(param_3[0x26]), iVar1 != 0 &&
      (((((param_3[5] & 2U) == 0 && (iVar1 = (**(code **)(*param_3 + 0x50))(param_3), iVar1 == 0))
        && (param_2[0x48] == param_3[0x48])) && (param_2[0x49] == param_3[0x49])))))) {
    iVar1 = param_2[0x21];
    if ((param_2[5] & 0x200U) != 0) {
      iVar1 = iVar1 + -1;
    }
    if (iVar1 < 1) {
      return 1;
    }
    if (((param_3[0x2e] & 1U) == (param_2[0x2e] & 1U)) &&
       (iVar2 = 1, ((uint)param_2[0x2e] >> 1 & 1) == ((uint)param_3[0x2e] >> 1 & 1))) {
      do {
        iVar2 = iVar2 + 1;
        if (iVar1 < iVar2) {
          return 1;
        }
      } while (((param_3[iVar2 * 6 + 0x28] & 1U) == (param_2[iVar2 * 6 + 0x28] & 1U)) &&
              (((uint)param_3[iVar2 * 6 + 0x28] >> 1 & 1) ==
               ((uint)param_2[iVar2 * 6 + 0x28] >> 1 & 1)));
    }
  }
  return 0;
}

/* FUN_00141044 @ 0x141044 (76 bytes) */
int FUN_00141044(param_1, param_2, inst)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 inst;
{
  int operandRecord;
  undefined4 local_18 [3];
  
  operandRecord = IRInst__getOperandRecord(inst,0);
  WriteMask__fromSelectWord(local_18,*(undefined4 *)(operandRecord + 0x10));
  *param_1 = local_18[0];
  return param_1;
}

/* FUN_00141090 @ 0x141090 (112 bytes) */
int FUN_00141090(param_1, param_2, inst)
  uint *param_1;
  undefined4 param_2;
  undefined4 inst;
{
  uint local_28;
  uint local_24 [4];
  
  ((int (*)())FUN_00140e70)(&local_28,param_2,inst);
  ((int (*)())FUN_00141044)(local_24,param_2,inst);
  local_24[0] = ~local_24[0];
  *param_1 = local_28 &
             (local_24[0] << 0x18 | (local_24[0] & 0xff00) << 8 | local_24[0] >> 8 & 0xff00 |
             local_24[0] >> 0x18);
  return param_1;
}

/* FUN_00141100 @ 0x141100 (220 bytes) */
int FUN_00141100(param_1, inst, param_3, inst2, param_5)
  undefined4 param_1;
  int inst;
  int param_3;
  undefined4 inst2;
  int param_5;
{
  int operandRecord;
  int sourceDef;
  int operandVReg;
  int iVar3;
  int loopIndex;
  undefined4 operandSelect;
  undefined4 local_44 [8];
  
  ((int (*)())FUN_00140e7c)(param_1,inst,inst2);
  iVar3 = *(int *)(inst + 0x84);
  if ((*(uint *)(inst + 0x14) & 0x200) != 0) {
    iVar3 = iVar3 + -1;
  }
  if (0 < iVar3) {
    loopIndex = 1;
    do {
      sourceDef = IRInst__getOperandSource(inst,loopIndex);
      operandVReg = IRInst__getOperandSource(inst2,loopIndex);
      if (sourceDef != operandVReg) {
        return 0;
      }
      operandRecord = IRInst__getOperandRecord(inst,loopIndex);
      operandSelect = *(undefined4 *)(operandRecord + 0x10);
      operandRecord = IRInst__getOperandRecord(inst2,loopIndex);
      local_44[0] = *(undefined4 *)(operandRecord + 0x10);
      if (*(char *)((int)local_44 + param_3 + -4) != *(char *)((int)local_44 + param_5)) {
        return 0;
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex <= iVar3);
  }
  return 1;
}

/* FUN_001411dc @ 0x1411dc (636 bytes) */
int FUN_001411dc(param_1, inst, inst2, param_4)
  undefined4 *param_1;
  int inst;
  int inst2;
  undefined4 param_4;
{
  undefined4 operandSelect;
  int operandRecordB;
  int operandRecord;
  int loopIndexB;
  int countdownB;
  int countdown;
  int loopIndex;
  unsigned int ghidra_home[8] = { param_1, inst, inst2, param_4, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  int countdownC;
  undefined4 operandSelectB;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44 [7];
  
  bVar1 = inst == inst2;
  (*(unsigned int *)((unsigned char *)ghidra_home + 12)) = param_4;
  FUN_0011379c(*param_1,inst);
  FUN_0011379c(*param_1,inst2);
  operandRecord = IRInst__getOperandRecord(inst,0);
  local_44[0] = *(undefined4 *)(operandRecord + 0x10);
  operandRecord = IRInst__getOperandRecord(inst2,0);
  operandSelectB = *(undefined4 *)(operandRecord + 0x10);
  if (bVar1) {
    local_44[0] = DAT_001b0044;
  }
  pbVar5 = (byte *)&(*(unsigned int *)((unsigned char *)ghidra_home + 12));
  countdown = 4;
  loopIndex = 0;
  pbVar4 = pbVar5;
  do {
    if (*(char *)((int)&operandSelectB + loopIndex) != '\x01') {
      *(char *)((int)local_44 + (uint)*pbVar4) = *(char *)((int)&operandSelectB + loopIndex);
    }
    loopIndex = loopIndex + 1;
    pbVar4 = pbVar4 + 1;
    countdown = countdown + -1;
  } while (countdown != 0);
  *(undefined4 *)(inst + 0x9c) = local_44[0];
  iVar6 = *(int *)(inst2 + 0x84);
  iVar3 = iVar6;
  if ((*(uint *)(inst2 + 0x14) & 0x200) != 0) {
    operandRecord = IRInst__getOperandRecord(inst,iVar6);
    local_4c = *(undefined4 *)(operandRecord + 0x10);
    operandRecord = IRInst__getOperandRecord(inst2,iVar6);
    operandSelect = *(undefined4 *)(operandRecord + 0x10);
    if (bVar1) {
      local_4c = DAT_001b0038;
    }
    loopIndex = 0;
    countdownB = 4;
    pbVar4 = pbVar5;
    do {
      if (*(char *)((int)local_44 + loopIndex + -4) != '\x04') {
        *(byte *)((int)&local_4c + (uint)*pbVar4) = *pbVar4;
      }
      uVar2 = local_4c;
      loopIndex = loopIndex + 1;
      pbVar4 = pbVar4 + 1;
      countdownB = countdownB + -1;
    } while (countdownB != 0);
    iVar3 = iVar6 + -1;
    iVar6 = IRInst__getOperandRecord(inst,iVar6);
    *(undefined4 *)(iVar6 + 0x10) = uVar2;
  }
  if (0 < iVar3) {
    iVar6 = 1;
    do {
      operandRecordB = IRInst__getOperandRecord(inst,iVar6);
      local_48 = *(undefined4 *)(operandRecordB + 0x10);
      operandRecordB = IRInst__getOperandRecord(inst2,iVar6);
      local_4c = *(undefined4 *)(operandRecordB + 0x10);
      if (bVar1) {
        local_48 = DAT_001b0038;
      }
      loopIndexB = 0;
      countdownC = 4;
      pbVar4 = pbVar5;
      do {
        if (*(char *)((int)&operandSelectB + loopIndexB) != '\x01') {
          *(undefined1 *)((int)local_44 + (*pbVar4 - 4)) = *(undefined1 *)((int)&local_4c + loopIndexB);
        }
        uVar2 = local_48;
        loopIndexB = loopIndexB + 1;
        pbVar4 = pbVar4 + 1;
        countdownC = countdownC + -1;
      } while (countdownC != 0);
      iVar7 = iVar6 + 1;
      iVar6 = IRInst__getOperandRecord(inst,iVar6);
      *(undefined4 *)(iVar6 + 0x10) = uVar2;
      iVar6 = iVar7;
    } while (iVar7 <= iVar3);
  }
  local_50 = *(undefined4 *)(inst2 + 0xc);
  local_54 = *(undefined4 *)(inst + 0xc);
  if (bVar1) {
    local_54 = DAT_001b0040;
  }
  countdown = 4;
  loopIndex = 0;
  do {
    if (*(char *)((int)&local_50 + loopIndex) != '\0') {
      *(undefined1 *)((int)&local_54 + (uint)*pbVar5) = 1;
    }
    loopIndex = loopIndex + 1;
    pbVar5 = pbVar5 + 1;
    countdown = countdown + -1;
  } while (countdown != 0);
  *(undefined4 *)(inst + 0xc) = local_54;
  return;
}

/* FUN_00141458 @ 0x141458 (332 bytes) */
int FUN_00141458(param_1, inst, param_3, param_4)
  undefined4 *param_1;
  int inst;
  int param_3;
  int param_4;
{
  int operandRecord3;
  int operandRecord2;
  undefined1 uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int operandRecord;
  int iVar6;
  int iVar7;
  undefined4 operandSelect;
  undefined4 local_44 [8];
  
  FUN_0011379c(*param_1,inst);
  operandRecord2 = IRInst__getOperandRecord(inst,0);
  operandSelect = *(undefined4 *)(operandRecord2 + 0x10);
  uVar3 = *(uint *)(inst + 0x14);
  uVar1 = *(undefined1 *)((int)local_44 + param_3 + -4);
  *(undefined1 *)((int)local_44 + param_3 + -4) = *(undefined1 *)((int)local_44 + param_4 + -4);
  *(undefined1 *)((int)local_44 + param_4 + -4) = uVar1;
  iVar6 = *(int *)(inst + 0x84);
  *(undefined4 *)(inst + 0x9c) = operandSelect;
  iVar4 = iVar6;
  if ((uVar3 & 0x200) != 0) {
    operandRecord2 = IRInst__getOperandRecord(inst,iVar6);
    local_44[0] = *(undefined4 *)(operandRecord2 + 0x10);
    uVar1 = *(undefined1 *)((int)local_44 + param_3);
    *(undefined1 *)((int)local_44 + param_3) = *(undefined1 *)((int)local_44 + param_4);
    *(undefined1 *)((int)local_44 + param_4) = uVar1;
    if (*(char *)((int)local_44 + param_3) != '\x04') {
      *(char *)((int)local_44 + param_3) = (char)param_3;
    }
    if (*(char *)((int)local_44 + param_4) != '\x04') {
      *(char *)((int)local_44 + param_4) = (char)param_4;
    }
    uVar2 = local_44[0];
    iVar4 = iVar6 + -1;
    operandRecord3 = IRInst__getOperandRecord(inst,iVar6);
    *(undefined4 *)(operandRecord3 + 0x10) = uVar2;
  }
  if (0 < iVar4) {
    iVar6 = 1;
    do {
      operandRecord = IRInst__getOperandRecord(inst,iVar6);
      iVar7 = iVar6 + 1;
      local_44[0] = *(undefined4 *)(operandRecord + 0x10);
      uVar1 = *(undefined1 *)((int)local_44 + param_3);
      *(undefined1 *)((int)local_44 + param_3) = *(undefined1 *)((int)local_44 + param_4);
      *(undefined1 *)((int)local_44 + param_4) = uVar1;
      uVar2 = local_44[0];
      operandRecord3 = IRInst__getOperandRecord(inst,iVar6);
      *(undefined4 *)(operandRecord3 + 0x10) = uVar2;
      iVar6 = iVar7;
    } while (iVar7 <= iVar4);
  }
  uVar1 = *(undefined1 *)(inst + param_3 + 0xc);
  *(undefined1 *)(inst + param_3 + 0xc) = *(undefined1 *)(inst + param_4 + 0xc);
  *(undefined1 *)(inst + param_4 + 0xc) = uVar1;
  return;
}

/* FUN_001415a4 @ 0x1415a4 (272 bytes) */
int FUN_001415a4(param_1, param_2, newSource)
  undefined4 *param_1;
  int *param_2;
  undefined4 newSource;
{
  int loopIndex;
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  while (piVar1 = (int *)param_2[4], piVar1[1] != 0) {
    if (*piVar1 == 0) {
      piVar1 = (int *)Vector__elementRefGrow(piVar1,0);
    }
    else {
      piVar1 = (int *)piVar1[2];
    }
    iVar2 = *piVar1;
    iVar3 = *(int *)(iVar2 + 0x84);
    iVar4 = iVar3;
    if ((*(uint *)(iVar2 + 0x14) & 0x200) != 0) {
      iVar4 = iVar3 + -1;
      piVar1 = (int *)IRInst__getOperandSource(iVar2,iVar3);
      if (param_2 == piVar1) {
        IRInst__setExtraOperandSource(iVar2,newSource,1,*param_1);
      }
    }
    if (0 < iVar4) {
      loopIndex = 1;
      do {
        piVar1 = (int *)IRInst__getOperandSource(iVar2,loopIndex);
        if (param_2 == piVar1) {
          IRInst__setOperandSource(iVar2,loopIndex,newSource,1,*param_1);
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex <= iVar4);
    }
  }
  *(int *)(param_1[1] + 0x1b4) = *(int *)(param_1[1] + 0x1b4) + 1;
                    
                    
  (**(code **)(*param_2 + 0xc))(param_2,1,*param_1);
  return;
}

/* FUN_001416b4 @ 0x1416b4 (508 bytes) */
int FUN_001416b4(param_1, inst, inst2, param_4)
  undefined4 param_1;
  int inst;
  int inst2;
  int param_4;
{
  int isBeforeOrSameResultB;
  int isBeforeOrSameResult;
  int operandIndex;
  int sourceDef;
  int loopIndex;
  int iVar1;
  int operandVReg;
  undefined4 operandVReg2;
  uint uVar4;
  int *piVar5;
  int iVar6;
  uint loopIndex2;
  uint *puVar8;
  
  isBeforeOrSameResult = Inst__isBeforeOrSame(inst,inst2);
  if (isBeforeOrSameResult == 0) {
    isBeforeOrSameResult = Inst__isBeforeOrSame(inst2,inst);
    if (isBeforeOrSameResult == 0) {
      return 0;
    }
    iVar6 = *(int *)(inst + 0x84);
    iVar1 = iVar6;
    if ((*(uint *)(inst + 0x14) & 0x200) != 0) {
      iVar1 = iVar6 + -1;
      sourceDef = IRInst__getOperandSource(inst,iVar6);
      if ((param_4 != 0) && (inst2 == sourceDef)) {
        return 0;
      }
    }
    if (0 < iVar1) {
      loopIndex = 1;
      do {
        operandVReg = IRInst__getOperandSource(inst,loopIndex);
        if (inst2 == operandVReg) {
          return 0;
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex <= iVar1);
    }
    puVar8 = *(uint **)(inst2 + 0x10);
    uVar4 = puVar8[1];
    if (uVar4 != 0) {
      loopIndex2 = 0;
      do {
        if (loopIndex2 < *puVar8) {
          if (uVar4 <= loopIndex2) {
            _memset(uVar4 * 4 + puVar8[2],0,(loopIndex2 - uVar4) * 4 + 4);
            puVar8[1] = loopIndex2 + 1;
          }
          piVar5 = (int *)(loopIndex2 * 4 + puVar8[2]);
        }
        else {
          piVar5 = (int *)Vector__elementRefGrow(puVar8,loopIndex2);
        }
        if ((*piVar5 != 0) && (iVar1 = Inst__isBeforeOrSame(inst,*piVar5), iVar1 == 0)) {
          return 0;
        }
        puVar8 = *(uint **)(inst2 + 0x10);
        loopIndex2 = loopIndex2 + 1;
        uVar4 = puVar8[1];
      } while (loopIndex2 < uVar4);
    }
  }
  else {
    iVar6 = *(int *)(inst2 + 0x84);
    iVar1 = iVar6;
    if ((*(uint *)(inst2 + 0x14) & 0x200) != 0) {
      iVar1 = iVar6 + -1;
      sourceDef = IRInst__getOperandSource(inst2,iVar6);
      if ((param_4 != 0) && (inst == sourceDef)) {
        return 0;
      }
    }
    if (0 < iVar1) {
      loopIndex = 1;
      do {
        operandVReg = IRInst__getOperandSource(inst2,loopIndex);
        if (inst == operandVReg) {
          return 0;
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex <= iVar1);
    }
    if (0 < *(int *)(inst2 + 0x84)) {
      operandIndex = 1;
      do {
        operandVReg2 = IRInst__getOperandSource(inst2,operandIndex);
        isBeforeOrSameResultB = Inst__isBeforeOrSame(operandVReg2,inst);
        if (isBeforeOrSameResultB == 0) {
          return 0;
        }
        operandIndex = operandIndex + 1;
      } while (operandIndex <= *(int *)(inst2 + 0x84));
    }
  }
  return 1;
}

/* PostPack__canPairInEitherOrder @ 0x1418b0 (128 bytes) */
int PostPack__canPairInEitherOrder(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 *param_4;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = ((int (*)())FUN_001416b4)(param_1,param_2,param_3,0);
  if (iVar1 == 0) {
    iVar1 = ((int (*)())FUN_001416b4)(param_1,param_3,param_2,0);
    uVar2 = 0;
    if (iVar1 != 0) {
      uVar2 = 1;
      *param_4 = 1;
    }
  }
  else {
    uVar2 = 1;
    *param_4 = 0;
  }
  return uVar2;
}

/* FUN_00141930 @ 0x141930 (3700 bytes) */
int FUN_00141930(param_1, inst, inst2, param_4)
  int param_1;
  int *inst;
  int *inst2;
  int *param_4;
{
  int vcall60ResultB;
  int vcall60Result;
  uint loopIndexG;
  uint loopIndexF;
  uint loopIndexE;
  int countdownF;
  int countdownE;
  int countdownD;
  int loopIndexD;
  int loopIndexC;
  int countdownC;
  int countdownB;
  int loopIndexB;
  int countdown;
  byte loopIndex;
  bool moreComponentsB;
  bool isLast;
  bool moreComponents;
  int operandRecord;
  int operandRecord2;
  int *operandVReg;
  int *operandVReg2;
  int *operandVReg3;
  bool bVar1;
  bool bVar2;
  byte bVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  undefined4 allocation;
  int iVar9;
  int *piVar10;
  int iVar11;
  int iVar12;
  byte *pbVar13;
  int *piVar14;
  byte *pbVar15;
  int *piVar16;
  byte *pbVar17;
  byte bVar19;
  byte *pbVar18;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  int iVar23;
  undefined4 *puVar24;
  int iVar25;
  int iVar26;
  undefined4 operandSelect;
  int local_84 [4];
  byte local_74 [16];
  byte local_64 [4];
  undefined4 local_60;
  undefined4 local_5c;
  
  ((int (*)())FUN_00140e7c)(param_1,inst,inst2);
  if (param_4 != (int *)0x0) {
    countdownE = 5;
    *param_4 = 0;
    piVar4 = param_4;
    do {
      piVar4 = piVar4 + 1;
      *piVar4 = 0;
      countdownE = countdownE + -1;
    } while (countdownE != 0);
  }
  iVar25 = inst[0x21];
  if ((inst[5] & 0x200U) == 0) goto LAB_001420b4;
  if ((inst2[5] & 0x200U) != 0) {
    operandVReg2 = (int *)IRInst__getOperandSource(inst,iVar25);
    operandVReg = (int *)IRInst__getOperandSource(inst2,inst2[0x21]);
    if (((operandVReg2 != operandVReg) && (inst2 != operandVReg2)) && (inst != operandVReg)) {
      vcall60Result = (**(code **)(*operandVReg2 + 0x60))(operandVReg2);
      if ((vcall60Result != 0) || (vcall60Result = (**(code **)(*operandVReg + 0x60))(operandVReg), vcall60Result != 0)) {
        return 0;
      }
      countdown = 4;
      loopIndex = 0;
      pbVar13 = local_64;
      piVar10 = local_84;
      do {
        *pbVar13 = loopIndex;
        pbVar13 = pbVar13 + 1;
        *piVar10 = 0;
        loopIndex = loopIndex + 1;
        piVar10[4] = 0;
        piVar10 = piVar10 + 1;
        countdown = countdown + -1;
      } while (countdown != 0);
      operandRecord = IRInst__getOperandRecord(inst,iVar25);
      uVar7 = 0;
      operandSelect = *(undefined4 *)(operandRecord + 0x10);
      piVar10 = local_84;
      pbVar13 = local_64;
      do {
        if (*(char *)((int)local_84 + (uVar7 - 4)) != '\x04') {
          piVar16 = (int *)piVar10[4];
          if (operandVReg2 == piVar16) {
            if (uVar7 == *pbVar13) {
              *piVar10 = 1;
            }
            else {
LAB_00141ae0:
              if (*piVar10 != 0) {
LAB_00141b90:
                bVar1 = false;
                goto LAB_00141b94;
              }
              pbVar17 = local_74;
              piVar10[4] = (int)operandVReg2;
              uVar21 = (uint)*pbVar13;
              *piVar10 = 1;
              *pbVar13 = (byte)uVar7;
              pbVar18 = pbVar17;
              pbVar15 = local_64;
              do {
                if ((piVar16 == *(int **)pbVar18) && (uVar21 == *pbVar15)) goto LAB_00141a9c;
                pbVar18 = pbVar18 + 4;
                pbVar15 = pbVar15 + 1;
              } while (local_64 != pbVar18);
              countdown = 4;
              loopIndexE = 0;
              pbVar18 = local_64;
              while( true ) {
                piVar14 = *(int **)pbVar17;
                if (piVar14 == (int *)0x0) break;
                uVar22 = (uint)*pbVar18;
                if ((loopIndexE != uVar22) &&
                   ((piVar16[0x53] < piVar14[0x53] ||
                    ((piVar14[0x53] == piVar16[0x53] && (uVar21 < uVar22)))))) {
                  *(int **)pbVar17 = piVar16;
                  *pbVar18 = (byte)uVar21;
                  uVar21 = uVar22;
                  piVar16 = piVar14;
                }
                loopIndexE = loopIndexE + 1;
                pbVar17 = pbVar17 + 4;
                pbVar18 = pbVar18 + 1;
                countdown = countdown + -1;
                if (countdown == 0) goto LAB_00141b90;
              }
              local_64[loopIndexE] = (byte)uVar21;
              *(int **)(local_74 + loopIndexE * 4) = piVar16;
            }
          }
          else {
            if (piVar16 != (int *)0x0) goto LAB_00141ae0;
            piVar10[4] = (int)operandVReg2;
            *piVar10 = 1;
            *pbVar13 = (byte)uVar7;
          }
        }
LAB_00141a9c:
        moreComponents = uVar7 != 3;
        piVar10 = piVar10 + 1;
        pbVar13 = pbVar13 + 1;
        uVar7 = uVar7 + 1;
      } while (moreComponents);
      bVar1 = true;
LAB_00141b94:
      operandRecord = IRInst__getOperandRecord(inst2,iVar25);
      uVar7 = 0;
      operandSelect = *(undefined4 *)(operandRecord + 0x10);
      piVar4 = local_84;
      pbVar13 = local_64;
      do {
        if (*(char *)((int)local_84 + (uVar7 - 4)) != '\x04') {
          piVar10 = (int *)piVar4[4];
          if (operandVReg == piVar10) {
            if (*pbVar13 == uVar7) {
              local_84[uVar7] = 1;
            }
            else {
LAB_00141bd8:
              if (*piVar4 != 0) {
LAB_00141d00:
                bVar2 = false;
                goto LAB_00141d04;
              }
              uVar21 = (uint)*pbVar13;
              pbVar17 = local_74;
              *piVar4 = 1;
              piVar4[4] = (int)operandVReg;
              *pbVar13 = (byte)uVar7;
              pbVar18 = pbVar17;
              pbVar15 = local_64;
              do {
                if ((piVar10 == *(int **)pbVar18) && (uVar21 == *pbVar15)) goto LAB_00141c78;
                pbVar18 = pbVar18 + 4;
                pbVar15 = pbVar15 + 1;
              } while (local_64 != pbVar18);
              countdown = 4;
              loopIndexE = 0;
              pbVar18 = local_64;
              while( true ) {
                piVar16 = *(int **)pbVar17;
                if (piVar16 == (int *)0x0) break;
                uVar22 = (uint)*pbVar18;
                if ((loopIndexE != uVar22) &&
                   ((piVar10[0x53] < piVar16[0x53] ||
                    ((piVar16[0x53] == piVar10[0x53] && (uVar21 < uVar22)))))) {
                  *(int **)pbVar17 = piVar10;
                  *pbVar18 = (byte)uVar21;
                  uVar21 = uVar22;
                  piVar10 = piVar16;
                }
                loopIndexE = loopIndexE + 1;
                pbVar17 = pbVar17 + 4;
                pbVar18 = pbVar18 + 1;
                countdown = countdown + -1;
                if (countdown == 0) goto LAB_00141d00;
              }
              local_64[loopIndexE] = (byte)uVar21;
              *(int **)(local_74 + loopIndexE * 4) = piVar10;
            }
          }
          else {
            if (piVar10 != (int *)0x0) goto LAB_00141bd8;
            piVar4[4] = (int)operandVReg;
            *piVar4 = 1;
            *pbVar13 = (byte)uVar7;
          }
        }
LAB_00141c78:
        moreComponentsB = uVar7 != 3;
        piVar4 = piVar4 + 1;
        pbVar13 = pbVar13 + 1;
        uVar7 = uVar7 + 1;
      } while (moreComponentsB);
      bVar2 = true;
LAB_00141d04:
      if (!bVar1) {
        return 0;
      }
      if (!bVar2) {
        return 0;
      }
      puVar24 = (undefined4 *)(param_1 + 0xc);
      uVar7 = *(uint *)(param_1 + 0x10);
      if (uVar7 != 0) {
        iVar6 = *(int *)(param_1 + 0x18);
        loopIndexE = 0;
        uVar21 = uVar7;
        do {
          if (uVar21 <= loopIndexE) {
            uVar21 = loopIndexE + 1;
            if (*(uint *)(param_1 + 0x14) < uVar21) {
              uVar22 = (*(uint *)(param_1 + 0x14) << 4) / 10;
              *(uint *)(param_1 + 0x14) = uVar22;
              if (uVar22 < uVar21) {
                *(uint *)(param_1 + 0x14) = uVar21;
              }
              allocation = Arena__alloc(*puVar24,*(int *)(param_1 + 0x14) * 0x2c);
              *(undefined4 *)(param_1 + 0x18) = allocation;
              if (*(int *)(param_1 + 0x10) != 0) {
                loopIndexG = 0;
                iVar23 = 0;
                do {
                  iVar11 = iVar23 + iVar6;
                  loopIndexG = loopIndexG + 1;
                  iVar9 = iVar23 + *(int *)(param_1 + 0x18);
                  iVar23 = iVar23 + 0x2c;
                  _memcpy(iVar9,iVar11,0x2c);
                } while (loopIndexG < *(uint *)(param_1 + 0x10));
              }
              Arena__free(*puVar24,iVar6);
              iVar6 = *(int *)(param_1 + 0x18);
            }
            *(uint *)(param_1 + 0x10) = uVar21;
          }
          piVar4 = (int *)(loopIndexE * 0x2c + iVar6);
          if (piVar4[9] != 0) {
            loopIndexD = 0;
            pbVar13 = local_74;
            do {
              if (*(int *)pbVar13 != 0) {
                countdownC = 4;
                loopIndexB = 0;
                piVar5 = piVar4;
                while ((*(int *)pbVar13 != piVar5[4] ||
                       (local_64[loopIndexD] != *(byte *)((int)piVar4 + loopIndexB + 0x20)))) {
                  loopIndexB = loopIndexB + 1;
                  piVar5 = piVar5 + 1;
                  countdownC = countdownC + -1;
                  if (countdownC == 0) goto LAB_00142744;
                }
                if ((loopIndexB == -1) ||
                   ((*(int *)(pbVar13 + -0x10) != 0 && ((loopIndexB != loopIndexD || (piVar4[loopIndexB] == 0)))))
                   ) break;
              }
              isLast = loopIndexD == 3;
              pbVar13 = pbVar13 + 4;
              loopIndexD = loopIndexD + 1;
              if (isLast) goto LAB_00142098;
            } while( true );
          }
LAB_00142744:
          loopIndexE = loopIndexE + 1;
          if (uVar7 == loopIndexE) goto LAB_00141e9c;
          uVar21 = *(uint *)(param_1 + 0x10);
        } while( true );
      }
      iVar6 = *(int *)(param_1 + 0x18);
      goto LAB_00141fd8;
    }
  }
  goto LAB_001420b0;
LAB_00141e9c:
  loopIndexF = 0;
  iVar23 = 0;
  do {
    if (*(uint *)(param_1 + 0x10) <= loopIndexF) {
      uVar20 = loopIndexF + 1;
      if (*(uint *)(param_1 + 0x14) < uVar20) {
        uVar22 = (*(uint *)(param_1 + 0x14) << 4) / 10;
        *(uint *)(param_1 + 0x14) = uVar22;
        if (uVar22 < uVar20) {
          *(uint *)(param_1 + 0x14) = uVar20;
        }
        allocation = Arena__alloc(*puVar24,*(int *)(param_1 + 0x14) * 0x2c);
        *(undefined4 *)(param_1 + 0x18) = allocation;
        if (*(int *)(param_1 + 0x10) != 0) {
          loopIndexG = 0;
          iVar9 = 0;
          do {
            loopIndexG = loopIndexG + 1;
            _memcpy(iVar9 + *(int *)(param_1 + 0x18),iVar9 + iVar6,0x2c);
            iVar9 = iVar9 + 0x2c;
          } while (loopIndexG < *(uint *)(param_1 + 0x10));
        }
        Arena__free(*puVar24,iVar6);
        iVar6 = *(int *)(param_1 + 0x18);
      }
      *(uint *)(param_1 + 0x10) = uVar20;
    }
    piVar4 = (int *)(iVar23 + iVar6);
    countdownB = 4;
    pbVar13 = local_64;
    pbVar18 = (byte *)(piVar4 + 8);
    piVar5 = piVar4;
    piVar10 = local_84;
    while ((*piVar5 == *piVar10 && (piVar5[4] == piVar10[4]))) {
      bVar19 = *pbVar18;
      pbVar18 = pbVar18 + 1;
      bVar3 = *pbVar13;
      pbVar13 = pbVar13 + 1;
      if (bVar19 != bVar3) break;
      piVar5 = piVar5 + 1;
      piVar10 = piVar10 + 1;
      countdownB = countdownB + -1;
      if (countdownB == 0) goto LAB_00142098;
    }
    loopIndexF = loopIndexF + 1;
    iVar23 = iVar23 + 0x2c;
  } while (uVar7 != loopIndexF);
  if (*(uint *)(param_1 + 0x10) <= uVar7) {
LAB_00141fd8:
    uVar21 = uVar7 + 1;
    if (*(uint *)(param_1 + 0x14) < uVar21) {
      uVar20 = (*(uint *)(param_1 + 0x14) << 4) / 10;
      *(uint *)(param_1 + 0x14) = uVar20;
      if (uVar20 < uVar21) {
        *(uint *)(param_1 + 0x14) = uVar21;
      }
      allocation = Arena__alloc(*puVar24,*(int *)(param_1 + 0x14) * 0x2c);
      *(undefined4 *)(param_1 + 0x18) = allocation;
      if (*(int *)(param_1 + 0x10) != 0) {
        loopIndexE = 0;
        iVar23 = 0;
        do {
          loopIndexE = loopIndexE + 1;
          _memcpy(iVar23 + *(int *)(param_1 + 0x18),iVar23 + iVar6,0x2c);
          iVar23 = iVar23 + 0x2c;
        } while (loopIndexE < *(uint *)(param_1 + 0x10));
      }
      Arena__free(*puVar24,iVar6);
      iVar6 = *(int *)(param_1 + 0x18);
    }
    *(uint *)(param_1 + 0x10) = uVar21;
  }
  piVar4 = (int *)(uVar7 * 0x2c + iVar6);
  local_60 = 0;
  local_5c = 0;
  _memcpy(piVar4,local_84,0x2c);
LAB_00142098:
  iVar6 = *param_4;
  param_4[iVar25 + 1] = (int)piVar4;
  *param_4 = iVar6 + 1;
LAB_001420b0:
  iVar25 = iVar25 + -1;
LAB_001420b4:
  if (iVar25 < 1) {
LAB_001426c8:
    countdownE = 5;
    do {
      iVar6 = param_4[1];
      if (iVar6 != 0) {
        *(int *)(iVar6 + 0x28) = *(int *)(iVar6 + 0x28) + 1;
      }
      param_4 = param_4 + 1;
      countdownE = countdownE + -1;
    } while (countdownE != 0);
    return 1;
  }
  iVar6 = 1;
  piVar4 = param_4;
LAB_001420c4:
  operandVReg = (int *)IRInst__getOperandSource(inst,iVar6);
  operandVReg3 = (int *)IRInst__getOperandSource(inst2,iVar6);
  if (operandVReg != operandVReg3) {
    vcall60ResultB = (**(code **)(*operandVReg + 0x60))(operandVReg);
    if (vcall60ResultB != 0) {
      return 0;
    }
    vcall60ResultB = (**(code **)(*operandVReg3 + 0x60))(operandVReg3);
    if (vcall60ResultB != 0) {
      return 0;
    }
    countdownD = 4;
    loopIndex = 0;
    pbVar13 = local_64;
    piVar16 = local_84;
    do {
      *pbVar13 = loopIndex;
      pbVar13 = pbVar13 + 1;
      *piVar16 = 0;
      loopIndex = loopIndex + 1;
      piVar16[4] = 0;
      piVar16 = piVar16 + 1;
      countdownD = countdownD + -1;
    } while (countdownD != 0);
    operandRecord2 = IRInst__getOperandRecord(inst,iVar6);
    loopIndexB = 0;
    operandSelect = *(undefined4 *)(operandRecord2 + 0x10);
    do {
      uVar7 = (uint)*(byte *)((int)local_84 + loopIndexB + -4);
      if (uVar7 != 4) {
        pbVar15 = local_74;
        pbVar17 = local_64;
        countdownD = 4;
        pbVar13 = pbVar15;
        pbVar18 = pbVar17;
        do {
          if ((operandVReg == *(int **)pbVar13) && (uVar7 == *pbVar18)) goto LAB_001421bc;
          pbVar13 = pbVar13 + 4;
          pbVar18 = pbVar18 + 1;
          countdownD = countdownD + -1;
        } while (countdownD != 0);
        countdownD = 4;
        loopIndexF = 0;
        piVar16 = operandVReg;
        while( true ) {
          piVar14 = *(int **)pbVar15;
          if (piVar14 == (int *)0x0) break;
          uVar20 = (uint)*pbVar17;
          if ((loopIndexF != uVar20) &&
             ((piVar16[0x53] < piVar14[0x53] ||
              ((piVar14[0x53] == piVar16[0x53] && (uVar7 < uVar20)))))) {
            *(int **)pbVar15 = piVar16;
            *pbVar17 = (byte)uVar7;
            uVar7 = uVar20;
            piVar16 = piVar14;
          }
          loopIndexF = loopIndexF + 1;
          pbVar15 = pbVar15 + 4;
          pbVar17 = pbVar17 + 1;
          countdownD = countdownD + -1;
          if (countdownD == 0) {
            bVar1 = false;
            goto LAB_0014225c;
          }
        }
        local_64[loopIndexF] = (byte)uVar7;
        *(int **)(local_74 + loopIndexF * 4) = piVar16;
      }
LAB_001421bc:
      moreComponents = loopIndexB != 3;
      loopIndexB = loopIndexB + 1;
    } while (moreComponents);
    bVar1 = true;
LAB_0014225c:
    operandRecord2 = IRInst__getOperandRecord(inst2,iVar6);
    loopIndexB = 0;
    operandSelect = *(undefined4 *)(operandRecord2 + 0x10);
    do {
      uVar7 = (uint)*(byte *)((int)local_84 + loopIndexB + -4);
      if (uVar7 != 4) {
        pbVar15 = local_74;
        pbVar17 = local_64;
        countdownD = 4;
        pbVar13 = pbVar15;
        pbVar18 = pbVar17;
        do {
          if ((operandVReg3 == *(int **)pbVar13) && (uVar7 == *pbVar18)) goto LAB_001422b0;
          pbVar13 = pbVar13 + 4;
          pbVar18 = pbVar18 + 1;
          countdownD = countdownD + -1;
        } while (countdownD != 0);
        countdownD = 4;
        loopIndexF = 0;
        piVar5 = operandVReg3;
        while( true ) {
          piVar16 = *(int **)pbVar15;
          if (piVar16 == (int *)0x0) break;
          uVar20 = (uint)*pbVar17;
          if ((loopIndexF != uVar20) &&
             ((piVar5[0x53] < piVar16[0x53] || ((piVar16[0x53] == piVar5[0x53] && (uVar7 < uVar20)))
              ))) {
            *(int **)pbVar15 = piVar5;
            *pbVar17 = (byte)uVar7;
            uVar7 = uVar20;
            piVar5 = piVar16;
          }
          loopIndexF = loopIndexF + 1;
          pbVar15 = pbVar15 + 4;
          pbVar17 = pbVar17 + 1;
          countdownD = countdownD + -1;
          if (countdownD == 0) {
            bVar2 = false;
            goto LAB_00142338;
          }
        }
        local_64[loopIndexF] = (byte)uVar7;
        *(int **)(local_74 + loopIndexF * 4) = piVar5;
      }
LAB_001422b0:
      moreComponentsB = loopIndexB != 3;
      loopIndexB = loopIndexB + 1;
    } while (moreComponentsB);
    bVar2 = true;
LAB_00142338:
    if (!bVar1) {
      return 0;
    }
    if (!bVar2) {
      return 0;
    }
    puVar24 = (undefined4 *)(param_1 + 0xc);
    uVar7 = *(uint *)(param_1 + 0x10);
    if (uVar7 != 0) {
      iVar23 = *(int *)(param_1 + 0x18);
      loopIndexE = 0;
      uVar21 = uVar7;
      do {
        if (uVar21 <= loopIndexE) {
          uVar21 = loopIndexE + 1;
          if (*(uint *)(param_1 + 0x14) < uVar21) {
            uVar22 = (*(uint *)(param_1 + 0x14) << 4) / 10;
            *(uint *)(param_1 + 0x14) = uVar22;
            if (uVar22 < uVar21) {
              *(uint *)(param_1 + 0x14) = uVar21;
            }
            allocation = Arena__alloc(*puVar24,*(int *)(param_1 + 0x14) * 0x2c);
            *(undefined4 *)(param_1 + 0x18) = allocation;
            if (*(int *)(param_1 + 0x10) != 0) {
              loopIndexG = 0;
              iVar9 = 0;
              do {
                loopIndexG = loopIndexG + 1;
                _memcpy(*(int *)(param_1 + 0x18) + iVar9,iVar23 + iVar9,0x2c);
                iVar9 = iVar9 + 0x2c;
              } while (loopIndexG < *(uint *)(param_1 + 0x10));
            }
            Arena__free(*puVar24,iVar23);
            iVar23 = *(int *)(param_1 + 0x18);
          }
          *(uint *)(param_1 + 0x10) = uVar21;
        }
        piVar5 = (int *)(loopIndexE * 0x2c + iVar23);
        if (piVar5[9] != 0) {
          loopIndexB = 0;
          pbVar13 = local_74;
          do {
            if (*(int *)pbVar13 != 0) {
              countdownF = 4;
              loopIndexC = 0;
              piVar10 = piVar5;
              while ((*(int *)pbVar13 != piVar10[4] ||
                     (local_64[loopIndexB] != *(byte *)((int)piVar5 + loopIndexC + 0x20)))) {
                loopIndexC = loopIndexC + 1;
                piVar10 = piVar10 + 1;
                countdownF = countdownF + -1;
                if (countdownF == 0) goto LAB_00142780;
              }
              if ((loopIndexC == -1) ||
                 ((*(int *)(pbVar13 + -0x10) != 0 && ((loopIndexC != loopIndexB || (piVar5[loopIndexC] == 0))))))
              break;
            }
            isLast = loopIndexB == 3;
            pbVar13 = pbVar13 + 4;
            loopIndexB = loopIndexB + 1;
            if (isLast) goto LAB_001426a8;
          } while( true );
        }
LAB_00142780:
        loopIndexE = loopIndexE + 1;
        if (uVar7 == loopIndexE) goto LAB_001424ac;
        uVar21 = *(uint *)(param_1 + 0x10);
      } while( true );
    }
    iVar23 = *(int *)(param_1 + 0x18);
    goto LAB_001425e8;
  }
  goto LAB_001426b8;
LAB_001424ac:
  loopIndexF = 0;
  iVar9 = 0;
  do {
    if (*(uint *)(param_1 + 0x10) <= loopIndexF) {
      uVar20 = loopIndexF + 1;
      if (*(uint *)(param_1 + 0x14) < uVar20) {
        uVar22 = (*(uint *)(param_1 + 0x14) << 4) / 10;
        *(uint *)(param_1 + 0x14) = uVar22;
        if (uVar22 < uVar20) {
          *(uint *)(param_1 + 0x14) = uVar20;
        }
        allocation = Arena__alloc(*puVar24,*(int *)(param_1 + 0x14) * 0x2c);
        *(undefined4 *)(param_1 + 0x18) = allocation;
        if (*(int *)(param_1 + 0x10) != 0) {
          loopIndexG = 0;
          iVar11 = 0;
          do {
            iVar12 = iVar11 + iVar23;
            loopIndexG = loopIndexG + 1;
            iVar26 = iVar11 + *(int *)(param_1 + 0x18);
            iVar11 = iVar11 + 0x2c;
            _memcpy(iVar26,iVar12,0x2c);
          } while (loopIndexG < *(uint *)(param_1 + 0x10));
        }
        Arena__free(*puVar24,iVar23);
        iVar23 = *(int *)(param_1 + 0x18);
      }
      *(uint *)(param_1 + 0x10) = uVar20;
    }
    piVar5 = (int *)(iVar9 + iVar23);
    countdownC = 4;
    pbVar13 = local_64;
    pbVar18 = (byte *)(piVar5 + 8);
    piVar10 = piVar5;
    piVar16 = local_84;
    while ((*piVar10 == *piVar16 && (piVar10[4] == piVar16[4]))) {
      bVar19 = *pbVar18;
      pbVar18 = pbVar18 + 1;
      bVar3 = *pbVar13;
      pbVar13 = pbVar13 + 1;
      if (bVar19 != bVar3) break;
      piVar10 = piVar10 + 1;
      piVar16 = piVar16 + 1;
      countdownC = countdownC + -1;
      if (countdownC == 0) goto LAB_001426a8;
    }
    loopIndexF = loopIndexF + 1;
    iVar9 = iVar9 + 0x2c;
  } while (uVar7 != loopIndexF);
  if (*(uint *)(param_1 + 0x10) <= uVar7) {
LAB_001425e8:
    uVar21 = uVar7 + 1;
    if (*(uint *)(param_1 + 0x14) < uVar21) {
      uVar20 = (*(uint *)(param_1 + 0x14) << 4) / 10;
      *(uint *)(param_1 + 0x14) = uVar20;
      if (uVar20 < uVar21) {
        *(uint *)(param_1 + 0x14) = uVar21;
      }
      allocation = Arena__alloc(*puVar24,*(int *)(param_1 + 0x14) * 0x2c);
      *(undefined4 *)(param_1 + 0x18) = allocation;
      if (*(int *)(param_1 + 0x10) != 0) {
        loopIndexE = 0;
        iVar9 = 0;
        do {
          iVar26 = iVar23 + iVar9;
          loopIndexE = loopIndexE + 1;
          iVar11 = *(int *)(param_1 + 0x18) + iVar9;
          iVar9 = iVar9 + 0x2c;
          _memcpy(iVar11,iVar26,0x2c);
        } while (loopIndexE < *(uint *)(param_1 + 0x10));
      }
      Arena__free(*puVar24,iVar23);
      iVar23 = *(int *)(param_1 + 0x18);
    }
    *(uint *)(param_1 + 0x10) = uVar21;
  }
  local_60 = 0;
  piVar5 = (int *)(uVar7 * 0x2c + iVar23);
  local_5c = 0;
  _memcpy(piVar5,local_84,0x2c);
LAB_001426a8:
  iVar23 = *param_4;
  piVar4[2] = (int)piVar5;
  *param_4 = iVar23 + 1;
LAB_001426b8:
  iVar6 = iVar6 + 1;
  piVar4 = piVar4 + 1;
  if (iVar25 < iVar6) goto LAB_001426c8;
  goto LAB_001420c4;
}

/* FUN_001427a4 @ 0x1427a4 (464 bytes) */
int FUN_001427a4(param_1, param_2, inst)
  uint *param_1;
  undefined4 param_2;
  int *inst;
{
  int vcall5cResult;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  int *piVar7;
  uint loopIndex;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c [3];
  
  if ((*(int *)(inst[0x22] + 8) == 0x8e) ||
     (vcall5cResult = (**(code **)(*inst + 0x5c))(inst), vcall5cResult != 0)) {
    ((int (*)())FUN_00141044)(&local_38,param_2,inst);
    *param_1 = local_38;
  }
  else {
    puVar6 = (uint *)inst[4];
    uVar4 = puVar6[1];
    uVar5 = DAT_001b0040;
    if (uVar4 != 0) {
      loopIndex = 0;
      do {
        if (loopIndex < *puVar6) {
          if (uVar4 <= loopIndex) {
            _memset(uVar4 * 4 + puVar6[2],0,(loopIndex - uVar4) * 4 + 4);
            puVar6[1] = loopIndex + 1;
          }
          puVar2 = (undefined4 *)(loopIndex * 4 + puVar6[2]);
        }
        else {
          puVar2 = (undefined4 *)Vector__elementRefGrow(puVar6,loopIndex);
        }
        loopIndex = loopIndex + 1;
        piVar7 = (int *)*puVar2;
        if (piVar7 != (int *)0x0) {
          if ((*(int *)(piVar7[0x22] + 8) == 0x8e) ||
             (vcall5cResult = (**(code **)(*piVar7 + 0x5c))(piVar7), vcall5cResult != 0)) {
            ((int (*)())FUN_00141044)(&local_34,param_2,piVar7);
            uVar5 = uVar5 | local_34;
          }
          piVar3 = (int *)0x0;
          if ((piVar7[5] & 0x200U) != 0) {
            piVar3 = (int *)IRInst__getOperandSource(piVar7,piVar7[0x21]);
          }
          if (piVar3 == inst) {
            ((int (*)())FUN_00141090)(&local_30,param_2,piVar7);
            uVar5 = uVar5 | local_30;
          }
        }
        puVar6 = (uint *)inst[4];
        uVar4 = puVar6[1];
      } while (loopIndex < uVar4);
    }
    ((int (*)())FUN_00141044)(local_2c,param_2,inst);
    *param_1 = uVar5 & local_2c[0];
  }
  return param_1;
}

/* FUN_00142974 @ 0x142974 (1532 bytes) */
int FUN_00142974(param_1, inst, param_3, param_4)
  int *param_1;
  int *inst;
  int param_3;
  int param_4;
{
  uint countBefore;
  uint uVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint loopIndex2;
  uint loopIndex;
  uint *puVar11;
  uint *puVar12;
  undefined4 uVar13;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - vecCapacity/vecCount/vecData/vecArena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_6c_buf [0x10];
  #define vecCapacity (*(uint *)(local_6c_buf + 0x00))
  #define vecCount (*(uint *)(local_6c_buf + 0x04))
  #define vecData (*(int *)(local_6c_buf + 0x08))
  #define vecArena (*(undefined4 *)(local_6c_buf + 0x0c))
  undefined1 auStack_58 [4];
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48 [4];
  
  ((int (*)())FUN_001427a4)(auStack_58,param_1,inst);
  if (param_3 == param_4) {
    return 1;
  }
  if ((*(int *)(inst[0x22] + 8) == 0x8e) ||
     (vecCount = (**(code **)(*inst + 0x5c))(inst), vecCount != 0)) {
    return 0;
  }
  vecArena = *(undefined4 *)(*param_1 + 0x378);
  vecCapacity = 2;
  vecData = Arena__alloc(vecArena,8);
  puVar11 = (uint *)inst[4];
  if (puVar11[1] != 0) {
    loopIndex = 0;
    uVar5 = 1;
    iVar6 = 0;
    do {
      loopIndex2 = 0;
      do {
        if (loopIndex2 < loopIndex) {
          if (loopIndex < *puVar11) {
            uVar1 = puVar11[1];
            puVar12 = puVar11;
            if (uVar1 <= loopIndex) {
              _memset(uVar1 * 4 + puVar11[2],0,(loopIndex - uVar1) * 4 + 4);
              puVar11[1] = uVar5;
              puVar12 = (uint *)inst[4];
            }
            piVar2 = (int *)(iVar6 + puVar11[2]);
          }
          else {
            piVar2 = (int *)Vector__elementRefGrow(puVar11,loopIndex);
            puVar12 = (uint *)inst[4];
          }
          iVar7 = *piVar2;
          if (loopIndex2 < *puVar12) {
            uVar1 = puVar12[1];
            puVar11 = puVar12;
            if (uVar1 <= loopIndex2) {
              _memset(uVar1 * 4 + puVar12[2],0,(loopIndex2 - uVar1) * 4 + 4);
              puVar12[1] = loopIndex2 + 1;
              puVar11 = (uint *)inst[4];
            }
            piVar2 = (int *)(loopIndex2 * 4 + puVar12[2]);
          }
          else {
            piVar2 = (int *)Vector__elementRefGrow(puVar12,loopIndex2);
            puVar11 = (uint *)inst[4];
          }
          if (iVar7 == *piVar2) break;
        }
        if (loopIndex == loopIndex2) {
          if (loopIndex < *puVar11) {
            uVar1 = puVar11[1];
            if (uVar1 <= loopIndex) {
              _memset(uVar1 * 4 + puVar11[2],0,(loopIndex - uVar1) * 4 + 4);
              puVar11[1] = uVar5;
            }
            puVar3 = (undefined4 *)(iVar6 + puVar11[2]);
          }
          else {
            puVar3 = (undefined4 *)Vector__elementRefGrow(puVar11,loopIndex);
          }
          piVar2 = (int *)*puVar3;
          if (piVar2 != (int *)0x0) {
            if ((*(int *)(piVar2[0x22] + 8) == 0x8e) ||
               (iVar7 = (**(code **)(*piVar2 + 0x5c))(piVar2), iVar7 != 0)) {
              ((int (*)())FUN_00141044)(&local_54,param_1,piVar2);
              local_78 = local_54;
              if (*(char *)((int)&local_78 + param_3) != '\0') goto LAB_00142f88;
            }
            piVar4 = (int *)0x0;
            if ((piVar2[5] & 0x200U) != 0) {
              piVar4 = (int *)IRInst__getOperandSource(piVar2,piVar2[0x21]);
            }
            countBefore = vecCount;
            if (piVar4 == inst) {
              if (vecCount < vecCapacity) {
                iVar7 = vecCount * 4;
                _memset(iVar7 + vecData,0,4);
                vecCount = countBefore + 1;
                puVar3 = (undefined4 *)(iVar7 + vecData);
              }
              else {
                puVar3 = (undefined4 *)Vector__elementRefGrow(&vecCapacity,vecCount);
              }
              *puVar3 = piVar2;
              puVar11 = (uint *)inst[4];
              goto LAB_00142c3c;
            }
          }
          puVar11 = (uint *)inst[4];
        }
LAB_00142c3c:
        loopIndex2 = loopIndex2 + 1;
      } while (loopIndex2 <= loopIndex);
      loopIndex = loopIndex + 1;
      uVar5 = uVar5 + 1;
      iVar6 = iVar6 + 4;
    } while (loopIndex < puVar11[1]);
  }
  while (vecCount != 0) {
    uVar5 = vecCount - 1;
    piVar2 = (int *)0x0;
    if (uVar5 < vecCount) {
      piVar2 = (int *)(uVar5 * 4 + vecData);
    }
    iVar6 = *piVar2;
    Vector__removeAt(&vecCapacity,uVar5);
    ((int (*)())FUN_001427a4)(&local_50,param_1,iVar6);
    local_78 = local_50;
    ((int (*)())FUN_00141090)(&local_4c,param_1,iVar6);
    local_74 = local_4c;
    if (*(char *)((int)&local_74 + param_3) != '\0') {
      iVar7 = FUN_0011379c(*param_1,iVar6);
      if (((iVar7 == 0) || (*(char *)((int)&local_74 + param_4) != '\0')) ||
         (*(char *)((int)&local_78 + param_4) != '\0')) goto LAB_00142f88;
      puVar11 = *(uint **)(iVar6 + 0x10);
      if (puVar11[1] != 0) {
        loopIndex = 0;
        uVar5 = 1;
        iVar7 = 0;
        do {
          loopIndex2 = 0;
          do {
            if (loopIndex2 < loopIndex) {
              if (loopIndex < *puVar11) {
                uVar1 = puVar11[1];
                puVar12 = puVar11;
                if (uVar1 <= loopIndex) {
                  _memset(uVar1 * 4 + puVar11[2],0,(loopIndex - uVar1) * 4 + 4);
                  puVar11[1] = uVar5;
                  puVar12 = *(uint **)(iVar6 + 0x10);
                }
                piVar2 = (int *)(iVar7 + puVar11[2]);
              }
              else {
                piVar2 = (int *)Vector__elementRefGrow(puVar11,loopIndex);
                puVar12 = *(uint **)(iVar6 + 0x10);
              }
              iVar8 = *piVar2;
              if (loopIndex2 < *puVar12) {
                uVar1 = puVar12[1];
                puVar11 = puVar12;
                if (uVar1 <= loopIndex2) {
                  _memset(uVar1 * 4 + puVar12[2],0,(loopIndex2 - uVar1) * 4 + 4);
                  puVar12[1] = loopIndex2 + 1;
                  puVar11 = *(uint **)(iVar6 + 0x10);
                }
                piVar2 = (int *)(loopIndex2 * 4 + puVar12[2]);
              }
              else {
                piVar2 = (int *)Vector__elementRefGrow(puVar12,loopIndex2);
                puVar11 = *(uint **)(iVar6 + 0x10);
              }
              if (iVar8 == *piVar2) break;
            }
            if (loopIndex == loopIndex2) {
              if (loopIndex < *puVar11) {
                uVar1 = puVar11[1];
                if (uVar1 <= loopIndex) {
                  _memset(uVar1 * 4 + puVar11[2],0,(loopIndex - uVar1) * 4 + 4);
                  puVar11[1] = uVar5;
                }
                puVar3 = (undefined4 *)(iVar7 + puVar11[2]);
              }
              else {
                puVar3 = (undefined4 *)Vector__elementRefGrow(puVar11,loopIndex);
              }
              piVar2 = (int *)*puVar3;
              if (piVar2 != (int *)0x0) {
                if ((*(int *)(piVar2[0x22] + 8) == 0x8e) ||
                   (iVar8 = (**(code **)(*piVar2 + 0x5c))(piVar2), iVar8 != 0)) {
                  ((int (*)())FUN_00141044)(local_48,param_1,piVar2);
                  local_70 = local_48[0];
                  if (*(char *)((int)&local_70 + param_3) != '\0') goto LAB_00142f88;
                }
                iVar8 = 0;
                if ((piVar2[5] & 0x200U) != 0) {
                  iVar8 = IRInst__getOperandSource(piVar2,piVar2[0x21]);
                }
                countBefore = vecCount;
                if (iVar8 == iVar6) {
                  if (vecCount < vecCapacity) {
                    iVar8 = vecCount * 4;
                    _memset(iVar8 + vecData,0,4);
                    vecCount = countBefore + 1;
                    puVar3 = (undefined4 *)(iVar8 + vecData);
                  }
                  else {
                    puVar3 = (undefined4 *)Vector__elementRefGrow(&vecCapacity,vecCount);
                  }
                  *puVar3 = piVar2;
                  puVar11 = *(uint **)(iVar6 + 0x10);
                  goto LAB_00142f38;
                }
              }
              puVar11 = *(uint **)(iVar6 + 0x10);
            }
LAB_00142f38:
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 <= loopIndex);
          loopIndex = loopIndex + 1;
          uVar5 = uVar5 + 1;
          iVar7 = iVar7 + 4;
        } while (loopIndex < puVar11[1]);
      }
    }
  }
  uVar13 = 1;
LAB_00142f8c:
  Arena__free(vecArena,vecData);
  return uVar13;
LAB_00142f88:
  uVar13 = 0;
  goto LAB_00142f8c;
}
#undef vecCapacity
#undef vecCount
#undef vecData
#undef vecArena

/* FUN_00142fdc @ 0x142fdc (1672 bytes) */
int FUN_00142fdc(param_1, inst, inst2, param_4, param_5)
  undefined4 param_1;
  int inst;
  int inst2;
  byte *param_4;
  byte *param_5;
{
  int loopIndexB;
  int countdown;
  int loopIndex;
  bool isLast;
  bool moreComponents;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  byte *pbVar7;
  byte bVar8;
  int iVar9;
  byte local_b8 [4];
  uint local_b4;
  uint local_b0;
  uint local_ac;
  uint local_a8;
  undefined4 local_a4;
  uint local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  uint local_90;
  int local_8c [5];
  uint local_78;
  undefined1 auStack_74 [4];
  uint local_70;
  undefined4 local_6c;
  uint local_68;
  undefined1 auStack_64 [4];
  uint local_60;
  undefined4 local_5c [4];
  
  ((int (*)())FUN_00141044)(&local_78,param_1,inst);
  ((int (*)())FUN_00140e70)(auStack_74,param_1,inst);
  ((int (*)())FUN_001427a4)(&local_70,param_1,inst);
  local_a8 = local_70;
  ((int (*)())FUN_00141090)(&local_6c,param_1,inst);
  local_a4 = local_6c;
  ((int (*)())FUN_00141044)(&local_68,param_1,inst2);
  ((int (*)())FUN_00140e70)(auStack_64,param_1,inst2);
  ((int (*)())FUN_001427a4)(&local_60,param_1,inst2);
  local_a0 = local_60;
  ((int (*)())FUN_00141090)(local_5c,param_1,inst2);
  uVar2 = DAT_001b003c;
  iVar3 = 0;
  *(undefined4 *)param_4 = DAT_001b003c;
  *(undefined4 *)param_5 = uVar2;
  local_94 = DAT_001b0040;
  local_9c = local_5c[0];
  local_98 = DAT_001b0040;
  if ((*(uint *)(inst + 0x14) & 0x200) != 0) {
    iVar3 = IRInst__getOperandSource(inst,*(undefined4 *)(inst + 0x84));
  }
  if (iVar3 != inst2) {
    loopIndex = 0;
    iVar9 = 4;
    piVar5 = local_8c;
    do {
      if (*(char *)((int)&local_a4 + loopIndex) != '\0') {
        *(undefined1 *)((int)&local_98 + loopIndex) = 0;
        *(undefined1 *)((int)&local_94 + loopIndex) = 1;
        *piVar5 = inst;
        local_b8[loopIndex] = (byte)loopIndex;
      }
      loopIndex = loopIndex + 1;
      piVar5 = piVar5 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  iVar3 = 0;
  if ((*(uint *)(inst2 + 0x14) & 0x200) != 0) {
    iVar3 = IRInst__getOperandSource(inst2,*(undefined4 *)(inst2 + 0x84));
  }
  if (iVar3 != inst) {
    loopIndex = 0;
    piVar5 = local_8c;
    do {
      if (*(char *)((int)&local_9c + loopIndex) != '\0') {
        if (*(char *)((int)&local_94 + loopIndex) == '\0') {
          *(undefined1 *)((int)&local_98 + loopIndex) = 0;
          *(undefined1 *)((int)&local_94 + loopIndex) = 1;
          *piVar5 = inst2;
          local_b8[loopIndex] = (byte)loopIndex;
        }
        else {
          iVar9 = 0;
          if ((*(uint *)(inst2 + 0x14) & 0x200) != 0) {
            iVar9 = IRInst__getOperandSource(inst2,*(undefined4 *)(inst2 + 0x84));
          }
          iVar4 = 0;
          if ((*(uint *)(inst + 0x14) & 0x200) != 0) {
            iVar4 = IRInst__getOperandSource(inst,*(undefined4 *)(inst + 0x84));
          }
          if (iVar9 != iVar4) {
            return 0;
          }
        }
      }
      moreComponents = loopIndex != 3;
      piVar5 = piVar5 + 1;
      loopIndex = loopIndex + 1;
    } while (moreComponents);
  }
  loopIndex = 0;
  piVar5 = local_8c;
  pbVar7 = param_4;
  do {
    if (*(char *)((int)&local_a8 + loopIndex) != '\0') {
      iVar9 = 0;
      bVar8 = (byte)loopIndex;
      if (*(char *)((int)&local_94 + loopIndex) == '\0') {
        *piVar5 = inst;
        *pbVar7 = bVar8;
        *(undefined1 *)((int)&local_98 + loopIndex) = 1;
        *(undefined1 *)((int)&local_94 + loopIndex) = 1;
        local_b8[loopIndex] = bVar8;
      }
      else {
        while ((*(char *)((int)&local_94 + iVar9) != '\0' ||
               (iVar4 = ((int (*)())FUN_00142974)(param_1,inst,loopIndex,iVar9), iVar4 == 0))) {
          isLast = iVar9 == 3;
          iVar9 = iVar9 + 1;
          if (isLast) {
            return 0;
          }
        }
        *(undefined1 *)((int)&local_94 + iVar9) = 1;
        local_8c[iVar9] = inst;
        *(undefined1 *)((int)&local_98 + iVar9) = 1;
        *pbVar7 = (byte)iVar9;
        local_b8[iVar9] = bVar8;
      }
    }
    moreComponents = loopIndex != 3;
    piVar5 = piVar5 + 1;
    pbVar7 = pbVar7 + 1;
    loopIndex = loopIndex + 1;
  } while (moreComponents);
  iVar3 = 0;
  if ((*(uint *)(inst2 + 0x14) & 0x200) != 0) {
    iVar3 = IRInst__getOperandSource(inst2,*(undefined4 *)(inst2 + 0x84));
  }
  if (iVar3 == inst) {
    iVar9 = 4;
    loopIndex = 0;
    pbVar7 = param_5;
    do {
      if (*(char *)((int)&local_9c + loopIndex) != '\0') {
        *pbVar7 = param_4[loopIndex];
      }
      loopIndex = loopIndex + 1;
      pbVar7 = pbVar7 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  loopIndex = 0;
  piVar5 = local_8c;
  pbVar7 = param_5;
  do {
    if (*(char *)((int)&local_a0 + loopIndex) != '\0') {
      bVar8 = (byte)loopIndex;
      if (*(char *)((int)&local_94 + loopIndex) == '\0') {
        *(undefined1 *)((int)&local_98 + loopIndex) = 1;
        *piVar5 = inst2;
        *pbVar7 = bVar8;
        *(undefined1 *)((int)&local_94 + loopIndex) = 1;
        local_b8[loopIndex] = bVar8;
      }
      else if ((*(char *)((int)&local_98 + loopIndex) == '\0') ||
              (iVar9 = ((int (*)())FUN_00141100)(param_1,*piVar5,(uint)local_b8[loopIndex],inst2,loopIndex), iVar9 == 0
              )) {
        iVar9 = 0;
        while ((*(char *)((int)&local_94 + iVar9) != '\0' ||
               (iVar4 = ((int (*)())FUN_00142974)(param_1,inst2,loopIndex,iVar9), iVar4 == 0))) {
          isLast = iVar9 == 3;
          iVar9 = iVar9 + 1;
          if (isLast) {
            return 0;
          }
        }
        *(undefined1 *)((int)&local_94 + iVar9) = 1;
        local_8c[iVar9] = inst2;
        *(undefined1 *)((int)&local_98 + iVar9) = 1;
        *pbVar7 = (byte)iVar9;
        local_b8[iVar9] = bVar8;
      }
    }
    moreComponents = loopIndex != 3;
    piVar5 = piVar5 + 1;
    pbVar7 = pbVar7 + 1;
    loopIndex = loopIndex + 1;
  } while (moreComponents);
  iVar3 = 0;
  if ((*(uint *)(inst + 0x14) & 0x200) != 0) {
    iVar3 = IRInst__getOperandSource(inst,*(undefined4 *)(inst + 0x84));
  }
  if (iVar3 == inst2) {
    countdown = 4;
    loopIndex = 0;
    pbVar7 = param_4;
    do {
      if (*(char *)((int)&local_a4 + loopIndex) != '\0') {
        *pbVar7 = param_5[loopIndex];
      }
      loopIndex = loopIndex + 1;
      pbVar7 = pbVar7 + 1;
      countdown = countdown + -1;
    } while (countdown != 0);
  }
  loopIndex = 0;
  uVar6 = ~local_a8;
  do {
    local_ac = uVar6 << 0x18 | (uVar6 & 0xff00) << 8 | uVar6 >> 8 & 0xff00 | uVar6 >> 0x18;
    local_b4 = local_78 & local_ac;
    if (*(char *)((int)&local_b4 + loopIndex) != '\0') {
      loopIndexB = 0;
      do {
        if ((*(char *)((int)&local_98 + loopIndexB) != '\0') &&
           (iVar4 = ((int (*)())FUN_00141100)(param_1,local_8c[loopIndexB],(uint)local_b8[loopIndexB],inst,loopIndex),
           iVar4 != 0)) {
          *param_4 = (byte)loopIndexB;
          goto LAB_001434fc;
        }
        moreComponents = loopIndexB != 3;
        loopIndexB = loopIndexB + 1;
      } while (moreComponents);
      loopIndexB = 0;
      iVar4 = 4;
      while (*(char *)((int)&local_94 + loopIndexB) != '\0') {
        loopIndexB = loopIndexB + 1;
        iVar4 = iVar4 + -1;
        if (iVar4 == 0) {
          return 0;
        }
      }
      *(undefined1 *)((int)&local_94 + loopIndexB) = 1;
      local_8c[loopIndexB] = inst;
      *(undefined1 *)((int)&local_98 + loopIndexB) = 1;
      *param_4 = (byte)loopIndexB;
      local_b8[loopIndexB] = (byte)loopIndex;
    }
LAB_001434fc:
    moreComponents = loopIndex != 3;
    param_4 = param_4 + 1;
    loopIndex = loopIndex + 1;
  } while (moreComponents);
  loopIndex = 0;
  uVar6 = ~local_a0;
  do {
    local_b0 = uVar6 << 0x18 | (uVar6 & 0xff00) << 8 | uVar6 >> 8 & 0xff00 | uVar6 >> 0x18;
    local_90 = local_68 & local_b0;
    if (*(char *)((int)local_8c + loopIndex + -4) != '\0') {
      loopIndexB = 0;
      do {
        if ((*(char *)((int)&local_98 + loopIndexB) != '\0') &&
           (iVar4 = ((int (*)())FUN_00141100)(param_1,local_8c[loopIndexB],(uint)local_b8[loopIndexB],inst2,loopIndex),
           iVar4 != 0)) {
          *param_5 = (byte)loopIndexB;
          goto LAB_001435e4;
        }
        moreComponents = loopIndexB != 3;
        loopIndexB = loopIndexB + 1;
      } while (moreComponents);
      loopIndexB = 0;
      iVar4 = 4;
      while (*(char *)((int)&local_94 + loopIndexB) != '\0') {
        loopIndexB = loopIndexB + 1;
        iVar4 = iVar4 + -1;
        if (iVar4 == 0) {
          return 0;
        }
      }
      *(undefined1 *)((int)&local_94 + loopIndexB) = 1;
      local_8c[loopIndexB] = inst2;
      *(undefined1 *)((int)&local_98 + loopIndexB) = 1;
      *param_5 = (byte)loopIndexB;
      local_b8[loopIndexB] = (byte)loopIndex;
    }
LAB_001435e4:
    isLast = loopIndex == 3;
    param_5 = param_5 + 1;
    loopIndex = loopIndex + 1;
    if (isLast) {
      return 1;
    }
  } while( true );
}

/* FUN_00143664 @ 0x143664 (80 bytes) */
int FUN_00143664(param_1, inst, inst2, param_4, param_5)
  undefined4 param_1;
  undefined4 inst;
  undefined4 inst2;
  undefined4 param_4;
  undefined4 param_5;
{
  undefined4 callResult;
  
  ((int (*)())FUN_00140e7c)(param_1,inst,inst2);
  callResult = ((int (*)())FUN_00142fdc)(param_1,inst,inst2,param_4,param_5);
  return callResult;
}

/* PostPack__buildCandidate @ 0x1436b4 (168 bytes) */
int PostPack__buildCandidate(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 *param_4;
{
  int iVar1;
  
  *param_4 = param_2;
  param_4[1] = param_3;
  iVar1 = ((int (*)())FUN_00140e7c)(param_1,param_2,param_3);
  if ((((iVar1 != 0) &&
       (iVar1 = ((int (*)())FUN_00143664)(param_1,param_2,param_3,param_4 + 2,param_4 + 3), iVar1 != 0)) &&
      (iVar1 = ((int (*)())PostPack__canPairInEitherOrder)(param_1,param_2,param_3,param_4 + 4), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_00141930)(param_1,param_2,param_3,param_4 + 5), iVar1 != 0)) {
    return 1;
  }
  return 0;
}

/* FUN_0014375c @ 0x14375c (1672 bytes) */
int FUN_0014375c(param_1, param_2, param_3)
  int *param_1;
  undefined4 param_2;
  int param_3;
{
  int operandRecord;
  uint loopIndexB;
  int countdown;
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  bool moreComponents;
  byte bVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  int *piVar6;
  int operandSource;
  uint uVar8;
  int loopIndex;
  byte *pbVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  uint *puVar16;
  uint *puVar17;
  int iVar18;
  int operandIndex;
  uint uVar20;
  int local_78;
  undefined4 local_74;
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - vecCapacity/vecCount/vecData/vecArena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_70_buf [0x10];
  #define vecCapacity (*(uint *)(local_70_buf + 0x00))
  #define vecCount (*(uint *)(local_70_buf + 0x04))
  #define vecData (*(int *)(local_70_buf + 0x08))
  #define vecArena (*(undefined4 *)(local_70_buf + 0x0c))
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - vec2Capacity/vec2Count/vec2Data/vec2Arena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_60_buf [0x10];
  #define vec2Capacity (*(uint *)(local_60_buf + 0x00))
  #define vec2Count (*(uint *)(local_60_buf + 0x04))
  #define vec2Data (*(int *)(local_60_buf + 0x08))
  #define vec2Arena (*(undefined4 *)(local_60_buf + 0x0c))
  undefined4 local_48 [2];
  
  vecArena = *(undefined4 *)(*param_1 + 0x378);
  vecCount = 0;
  vecCapacity = 2;
  (*(int *)((unsigned char *)ghidra_home + 8)) = param_3;
  vecData = Arena__alloc(vecArena,8);
  vec2Arena = *(undefined4 *)(*param_1 + 0x378);
  vec2Count = 0;
  vec2Capacity = 2;
  vec2Data = Arena__alloc(vec2Arena,8);
  uVar8 = vecCount;
  if (vecCount < vecCapacity) {
    iVar11 = vecCount * 4;
    _memset(iVar11 + vecData,0,4);
    vecCount = uVar8 + 1;
    puVar5 = (undefined4 *)(iVar11 + vecData);
  }
  else {
    puVar5 = (undefined4 *)Vector__elementRefGrow(&vecCapacity,vecCount);
  }
  uVar8 = vec2Count;
  iVar11 = (*(int *)((unsigned char *)ghidra_home + 8));
  *puVar5 = param_2;
  if (vec2Count < vec2Capacity) {
    iVar15 = vec2Count * 4;
    _memset(iVar15 + vec2Data,0,4);
    vec2Count = uVar8 + 1;
    piVar6 = (int *)(iVar15 + vec2Data);
  }
  else {
    piVar6 = (int *)Vector__elementRefGrow(&vec2Capacity,vec2Count);
  }
  *piVar6 = iVar11;
  do {
    do {
      do {
        if (vecCount == 0) {
          Arena__free(vec2Arena,vec2Data);
          Arena__free(vecArena,vecData);
          return;
        }
        uVar8 = vecCount - 1;
        piVar6 = (int *)0x0;
        if (uVar8 < vecCount) {
          piVar6 = (int *)(uVar8 * 4 + vecData);
        }
        iVar11 = *piVar6;
        Vector__removeAt(&vecCapacity,uVar8);
        piVar6 = (int *)0x0;
        uVar8 = vec2Count - 1;
        if (uVar8 < vec2Count) {
          piVar6 = (int *)(uVar8 * 4 + vec2Data);
        }
        iVar15 = *piVar6;
        Vector__removeAt(&vec2Capacity,uVar8);
        (*(int *)((unsigned char *)ghidra_home + 8)) = iVar15;
      } while (iVar15 == DAT_001b003c);
      puVar16 = *(uint **)(iVar11 + 0x10);
      if (puVar16[1] != 0) {
        uVar14 = 0;
        uVar8 = 1;
        iVar15 = 0;
        do {
          uVar13 = 0;
          do {
            if (uVar13 < uVar14) {
              if (uVar14 < *puVar16) {
                uVar4 = puVar16[1];
                puVar17 = puVar16;
                if (uVar4 <= uVar14) {
                  _memset(uVar4 * 4 + puVar16[2],0,(uVar14 - uVar4) * 4 + 4);
                  puVar16[1] = uVar8;
                  puVar17 = *(uint **)(iVar11 + 0x10);
                }
                piVar6 = (int *)(iVar15 + puVar16[2]);
              }
              else {
                piVar6 = (int *)Vector__elementRefGrow(puVar16,uVar14);
                puVar17 = *(uint **)(iVar11 + 0x10);
              }
              iVar18 = *piVar6;
              if (uVar13 < *puVar17) {
                uVar4 = puVar17[1];
                puVar16 = puVar17;
                if (uVar4 <= uVar13) {
                  _memset(uVar4 * 4 + puVar17[2],0,(uVar13 - uVar4) * 4 + 4);
                  puVar17[1] = uVar13 + 1;
                  puVar16 = *(uint **)(iVar11 + 0x10);
                }
                piVar6 = (int *)(uVar13 * 4 + puVar17[2]);
              }
              else {
                piVar6 = (int *)Vector__elementRefGrow(puVar17,uVar13);
                puVar16 = *(uint **)(iVar11 + 0x10);
              }
              if (iVar18 == *piVar6) break;
            }
            if (uVar14 == uVar13) {
              if (uVar14 < *puVar16) {
                uVar4 = puVar16[1];
                if (uVar4 <= uVar14) {
                  _memset(uVar4 * 4 + puVar16[2],0,(uVar14 - uVar4) * 4 + 4);
                  puVar16[1] = uVar8;
                }
                piVar6 = (int *)(iVar15 + puVar16[2]);
              }
              else {
                piVar6 = (int *)Vector__elementRefGrow(puVar16,uVar14);
              }
              iVar18 = *piVar6;
              if (iVar18 != 0) {
                iVar12 = *(int *)(iVar18 + 0x84);
                if ((*(uint *)(iVar18 + 0x14) & 0x200) != 0) {
                  iVar12 = iVar12 + -1;
                }
                if (0 < iVar12) {
                  operandIndex = 1;
                  do {
                    operandSource = IRInst__getOperandSource(iVar18,operandIndex);
                    if (iVar11 == operandSource) {
                      operandRecord = IRInst__getOperandRecord(iVar18,operandIndex);
                      loopIndex = 0;
                      local_78 = *(int *)(operandRecord + 0x10);
                      countdown = 4;
                      do {
                        if (*(byte *)((int)&local_78 + loopIndex) != 4) {
                          *(undefined1 *)((int)&local_78 + loopIndex) =
                               *(undefined1 *)
                                ((int)&(*(unsigned int *)((unsigned char *)ghidra_home + 8)) + (uint)*(byte *)((int)&local_78 + loopIndex));
                        }
                        iVar3 = local_78;
                        loopIndex = loopIndex + 1;
                        countdown = countdown + -1;
                      } while (countdown != 0);
                      operandRecord = IRInst__getOperandRecord(iVar18,operandIndex);
                      *(int *)(operandRecord + 0x10) = iVar3;
                    }
                    operandIndex = operandIndex + 1;
                  } while (operandIndex <= iVar12);
                }
              }
              puVar16 = *(uint **)(iVar11 + 0x10);
            }
            uVar13 = uVar13 + 1;
          } while (uVar13 <= uVar14);
          uVar14 = uVar14 + 1;
          uVar8 = uVar8 + 1;
          iVar15 = iVar15 + 4;
        } while (uVar14 < puVar16[1]);
      }
    } while (puVar16[1] == 0);
    uVar14 = 0;
    uVar8 = 1;
    iVar15 = 0;
    do {
      uVar13 = 0;
      do {
        if (uVar13 < uVar14) {
          if (uVar14 < *puVar16) {
            uVar4 = puVar16[1];
            puVar17 = puVar16;
            if (uVar4 <= uVar14) {
              _memset(uVar4 * 4 + puVar16[2],0,(uVar14 - uVar4) * 4 + 4);
              puVar16[1] = uVar8;
              puVar17 = *(uint **)(iVar11 + 0x10);
            }
            piVar6 = (int *)(iVar15 + puVar16[2]);
          }
          else {
            piVar6 = (int *)Vector__elementRefGrow(puVar16,uVar14);
            puVar17 = *(uint **)(iVar11 + 0x10);
          }
          iVar18 = *piVar6;
          if (uVar13 < *puVar17) {
            uVar4 = puVar17[1];
            puVar16 = puVar17;
            if (uVar4 <= uVar13) {
              _memset(uVar4 * 4 + puVar17[2],0,(uVar13 - uVar4) * 4 + 4);
              puVar17[1] = uVar13 + 1;
              puVar16 = *(uint **)(iVar11 + 0x10);
            }
            piVar6 = (int *)(uVar13 * 4 + puVar17[2]);
          }
          else {
            piVar6 = (int *)Vector__elementRefGrow(puVar17,uVar13);
            puVar16 = *(uint **)(iVar11 + 0x10);
          }
          if (iVar18 == *piVar6) break;
        }
        if (uVar14 == uVar13) {
          if (uVar14 < *puVar16) {
            uVar4 = puVar16[1];
            if (uVar4 <= uVar14) {
              _memset(uVar4 * 4 + puVar16[2],0,(uVar14 - uVar4) * 4 + 4);
              puVar16[1] = uVar8;
            }
            piVar6 = (int *)(iVar15 + puVar16[2]);
          }
          else {
            piVar6 = (int *)Vector__elementRefGrow(puVar16,uVar14);
          }
          iVar18 = *piVar6;
          if (iVar18 != 0) {
            iVar12 = 0;
            if ((*(uint *)(iVar18 + 0x14) & 0x200) != 0) {
              iVar12 = IRInst__getOperandSource(iVar18,*(undefined4 *)(iVar18 + 0x84));
            }
            if (iVar12 == iVar11) {
              local_78 = DAT_001b003c;
              ((int (*)())FUN_00141090)(local_48,param_1,iVar18);
              loopIndexB = 0;
              pbVar10 = (byte *)&(*(unsigned int *)((unsigned char *)ghidra_home + 8));
              local_74 = local_48[0];
              do {
                if (*(char *)((int)&local_74 + loopIndexB) != '\0') {
                  bVar2 = *pbVar10;
                  uVar20 = (uint)bVar2;
                  if (uVar20 != loopIndexB) {
                    ((int (*)())FUN_00141458)(param_1,iVar18,loopIndexB,uVar20);
                    *(byte *)((int)&local_78 + loopIndexB) = bVar2;
                    *(char *)((int)&local_78 + uVar20) = (char)loopIndexB;
                  }
                }
                uVar20 = vecCount;
                moreComponents = loopIndexB != 3;
                pbVar10 = pbVar10 + 1;
                loopIndexB = loopIndexB + 1;
              } while (moreComponents);
              if (vecCount < vecCapacity) {
                iVar12 = vecCount * 4;
                _memset(iVar12 + vecData,0,4);
                vecCount = uVar20 + 1;
                piVar6 = (int *)(iVar12 + vecData);
              }
              else {
                piVar6 = (int *)Vector__elementRefGrow(&vecCapacity,vecCount);
              }
              uVar4 = vec2Count;
              iVar12 = local_78;
              *piVar6 = iVar18;
              if (vec2Count < vec2Capacity) {
                iVar18 = vec2Count * 4;
                _memset(iVar18 + vec2Data,0,4);
                vec2Count = uVar4 + 1;
                piVar6 = (int *)(iVar18 + vec2Data);
              }
              else {
                piVar6 = (int *)Vector__elementRefGrow(&vec2Capacity,vec2Count);
              }
              *piVar6 = iVar12;
              puVar16 = *(uint **)(iVar11 + 0x10);
              goto LAB_00143da4;
            }
          }
          puVar16 = *(uint **)(iVar11 + 0x10);
        }
LAB_00143da4:
        uVar13 = uVar13 + 1;
      } while (uVar13 <= uVar14);
      uVar14 = uVar14 + 1;
      uVar8 = uVar8 + 1;
      iVar15 = iVar15 + 4;
    } while (uVar14 < puVar16[1]);
  } while( true );
}
#undef vecCapacity
#undef vecCount
#undef vecData
#undef vecArena
#undef vec2Capacity
#undef vec2Count
#undef vec2Data
#undef vec2Arena

/* FUN_00143e40 @ 0x143e40 (676 bytes) */
int FUN_00143e40(param_1, param_2)
  undefined4 *param_1;
  int *param_2;
{
  int loopIndex3;
  int countdown;
  int splitRgbAlphaEnabled;
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  uint loopIndex;
  uint loopIndex2;
  uint *puVar10;
  int local_28;
  int local_24 [2];
  
  piVar5 = param_2 + 5;
  iVar1 = *param_2;
  iVar7 = param_2[1];
  if (param_2[4] != 0) {
    iVar1 = param_2[1];
    iVar7 = *param_2;
  }
  splitRgbAlphaEnabled = Compiler__isOptionEnabled(*param_1,0x30);
  if ((splitRgbAlphaEnabled == 0) ||
     ((((int (*)())FUN_00141044)(&local_28,param_1,iVar1), local_28 != 1 &&
      (((int (*)())FUN_00141044)(local_24,param_1,iVar7), local_24[0] != 1)))) {
    puVar10 = *(uint **)(iVar1 + 0x10);
    uVar3 = puVar10[1];
    if (uVar3 != 0) {
      loopIndex = 0;
      do {
        if (loopIndex < *puVar10) {
          if (uVar3 <= loopIndex) {
            _memset(uVar3 * 4 + puVar10[2],0,(loopIndex - uVar3) * 4 + 4);
            puVar10[1] = loopIndex + 1;
          }
          piVar4 = (int *)(loopIndex * 4 + puVar10[2]);
        }
        else {
          piVar4 = (int *)Vector__elementRefGrow(puVar10,loopIndex);
        }
        iVar2 = *piVar4;
        if ((iVar2 != 0) &&
           ((*(int *)(*(int *)(iVar2 + 0x88) + 8) == 0x8e ||
            (((iVar7 != iVar2 && ((*(uint *)(iVar2 + 0x14) & 0x200) != 0)) &&
             (iVar2 = IRInst__getOperandSource(iVar2,*(undefined4 *)(iVar2 + 0x84)), iVar1 == iVar2)))))) {
          puVar10 = *(uint **)(iVar7 + 0x10);
          uVar3 = puVar10[1];
          if (uVar3 != 0) {
            loopIndex2 = 0;
            do {
              if (loopIndex2 < *puVar10) {
                if (uVar3 <= loopIndex2) {
                  _memset(uVar3 * 4 + puVar10[2],0,(loopIndex2 - uVar3) * 4 + 4);
                  puVar10[1] = loopIndex2 + 1;
                }
                piVar4 = (int *)(loopIndex2 * 4 + puVar10[2]);
              }
              else {
                piVar4 = (int *)Vector__elementRefGrow(puVar10,loopIndex2);
              }
              iVar2 = *piVar4;
              if ((iVar2 != 0) &&
                 ((*(int *)(*(int *)(iVar2 + 0x88) + 8) == 0x8e ||
                  (((iVar1 != iVar2 && ((*(uint *)(iVar2 + 0x14) & 0x200) != 0)) &&
                   (iVar2 = IRInst__getOperandSource(iVar2,*(undefined4 *)(iVar2 + 0x84)), iVar7 == iVar2))))))
              goto LAB_001440cc;
              puVar10 = *(uint **)(iVar7 + 0x10);
              loopIndex2 = loopIndex2 + 1;
              uVar3 = puVar10[1];
            } while (loopIndex2 < uVar3);
          }
        }
        puVar10 = *(uint **)(iVar1 + 0x10);
        loopIndex = loopIndex + 1;
        uVar3 = puVar10[1];
      } while (loopIndex < uVar3);
    }
    countdown = 5;
    loopIndex3 = 0;
    iVar1 = 0;
    do {
      iVar6 = piVar5[1];
      if ((iVar6 != 0) && (*(int *)(iVar6 + 0x24) == 0)) {
        loopIndex3 = loopIndex3 + 1;
        if (iVar1 == 0) {
          iVar6 = *(int *)(iVar6 + 0x28);
        }
        else {
          iVar6 = *(int *)(iVar6 + 0x28);
          if (iVar1 <= iVar6) goto LAB_001440b0;
        }
        iVar1 = iVar6;
      }
LAB_001440b0:
      piVar5 = piVar5 + 1;
      countdown = countdown + -1;
    } while (countdown != 0);
    iVar1 = loopIndex3 * -3000 + 1000 + iVar1 * 0xfa;
  }
  else {
LAB_001440cc:
    iVar1 = -1;
  }
  return iVar1;
}

/* FUN_001440e4 @ 0x1440e4 (4680 bytes) */
int FUN_001440e4(param_1, inst, inst2, param_4)
  undefined4 *param_1;
  int inst;
  int inst2;
  int param_4;
{
  int vcall2cResult;
  int vcall1cResult;
  int isBeforeOrSameResult;
  uint loopIndexG;
  int countdownJ;
  int loopIndexF;
  int countdownI;
  int loopIndexE;
  int countdownH;
  int loopIndexD;
  int countdownG;
  int countdownF;
  int countdownE;
  int loopIndexC;
  int countdownD;
  int loopIndexB;
  int countdownC;
  int loopIndex;
  int countdown;
  bool isLast;
  bool moreComponents;
  int newInst;
  int sourceDef3;
  int sourceDef2;
  int operandRecord;
  int sourceDef;
  int operandRecord2;
  int operandRecord4;
  int operandRecord3;
  int operandRecord5;
  bool bVar1;
  bool bVar2;
  byte bVar3;
  char cVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined1 uVar9;
  byte *pbVar10;
  undefined4 *puVar11;
  int countdownB;
  int iVar13;
  int iVar14;
  uint uVar15;
  undefined4 *puVar16;
  undefined4 uVar17;
  uint uVar18;
  int iVar19;
  int *piVar20;
  int *piVar21;
  int iVar22;
  undefined4 *puVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  int iVar28;
  int iVar29;
  int countdownK;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4 [4];
  undefined4 local_b4;
  undefined4 local_b0 [2];
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  int local_8c;
  int operandSourceB;
  int operandSource;
  undefined *local_80;
  undefined4 *local_7c;
  undefined *local_78;
  undefined4 *local_74;
  undefined4 *local_70;
  undefined4 *local_6c;
  undefined4 *local_68;
  undefined4 *local_64;
  undefined4 *local_60;
  undefined4 *local_5c;
  
  local_6c = local_c4 + 1;
  local_68 = local_c4 + 2;
  local_64 = local_c4 + 3;
  local_60 = &local_b4;
  local_5c = &local_d4;
  iVar22 = 0;
LAB_00144144:
  puVar23 = *(undefined4 **)(param_4 + 4);
  if (puVar23 != (undefined4 *)0x0) {
    iVar24 = puVar23[9];
    local_7c = &local_d8;
    if (iVar24 == 0) {
      countdownF = 4;
      iVar24 = 0;
      puVar11 = puVar23;
      do {
        if (puVar11[4] != 0) {
          uVar15 = 1;
          iVar24 = puVar23[iVar24 + 4];
          goto LAB_001441e0;
        }
        iVar24 = iVar24 + 1;
        puVar11 = puVar11 + 1;
        countdownF = countdownF + -1;
      } while (countdownF != 0);
      uVar15 = 0;
      iVar24 = 0;
LAB_001441e0:
      countdownG = 4;
      iVar25 = 0;
      puVar11 = puVar23;
      do {
        if ((iVar24 != puVar11[4]) && (puVar11[4] != 0)) {
          uVar15 = uVar15 + 1;
          iVar25 = puVar23[iVar25 + 4];
          goto LAB_00144214;
        }
        iVar25 = iVar25 + 1;
        puVar11 = puVar11 + 1;
        countdownG = countdownG + -1;
      } while (countdownG != 0);
      iVar25 = 0;
LAB_00144214:
      countdownH = 4;
      iVar26 = 0;
      puVar11 = puVar23;
      do {
        iVar7 = puVar11[4];
        if (((iVar24 != iVar7) && (iVar25 != iVar7)) && (iVar7 != 0)) {
          uVar18 = uVar15 + 1;
          iVar26 = puVar23[iVar26 + 4];
          bVar1 = iVar26 == 0;
          if (bVar1) goto LAB_00144258;
          uVar15 = uVar15 + 2;
          countdownH = 4;
          piVar20 = puVar23 + 4;
          puVar11 = puVar23;
          goto LAB_001442d4;
        }
        iVar26 = iVar26 + 1;
        puVar11 = puVar11 + 1;
        countdownH = countdownH + -1;
      } while (countdownH != 0);
      bVar1 = true;
      iVar26 = 0;
      local_8c = 0;
      bVar2 = bVar1;
      goto LAB_00144264;
    }
    goto LAB_0014516c;
  }
  goto LAB_001452d4;
  while( true ) {
    piVar20 = piVar20 + 1;
    puVar11 = puVar11 + 1;
    countdownH = countdownH + -1;
    if (countdownH == 0) break;
LAB_001442d4:
    iVar7 = puVar11[4];
    if (((iVar24 != iVar7) && (iVar25 != iVar7)) && ((iVar7 != iVar26 && (iVar7 != 0)))) {
      local_8c = *piVar20;
      bVar2 = local_8c == 0;
      if (bVar2) goto LAB_00144264;
      loopIndexG = 0;
      countdownH = 4;
      piVar20 = puVar23 + 4;
      pbVar10 = (byte *)(puVar23 + 8);
      goto LAB_00144334;
    }
  }
LAB_00144258:
  local_8c = 0;
  uVar15 = uVar18;
  bVar2 = true;
  goto LAB_00144264;
  while( true ) {
    loopIndexG = loopIndexG + 1;
    piVar20 = piVar20 + 1;
    countdownH = countdownH + -1;
    if (countdownH == 0) break;
LAB_00144334:
    bVar3 = *pbVar10;
    pbVar10 = pbVar10 + 1;
    if (loopIndexG == bVar3) {
      iVar27 = *piVar20;
      if (iVar27 != local_8c) {
        if (iVar27 == iVar26) {
          bVar1 = local_8c == 0;
          iVar7 = iVar25;
          iVar26 = local_8c;
        }
        else {
          iVar7 = local_8c;
          if ((iVar25 != iVar27) && (iVar7 = iVar25, iVar24 == iVar27)) {
            iVar24 = local_8c;
          }
        }
        iVar25 = iVar7;
        bVar2 = iVar27 == 0;
        local_8c = iVar27;
      }
      break;
    }
  }
LAB_00144264:
  iVar27 = *(int *)(iVar24 + 8);
  piVar20 = *(int **)(iVar27 + 0x158);
  isBeforeOrSameResult = Inst__isBeforeOrSame(iVar27,iVar25);
  if (isBeforeOrSameResult != 0) {
    iVar27 = *(int *)(iVar25 + 8);
    piVar20 = *(int **)(iVar27 + 0x158);
  }
  if (!bVar1) {
    isBeforeOrSameResult = Inst__isBeforeOrSame(iVar27,iVar26);
    if (isBeforeOrSameResult != 0) {
      iVar27 = *(int *)(iVar26 + 8);
      piVar20 = *(int **)(iVar27 + 0x158);
    }
    if ((!bVar2) && (isBeforeOrSameResult = Inst__isBeforeOrSame(iVar27,local_8c), isBeforeOrSameResult != 0)) {
      iVar27 = *(int *)(local_8c + 8);
      piVar20 = *(int **)(iVar27 + 0x158);
    }
  }
  Inst__isBeforeOrSame(iVar24,iVar27);
  Inst__isBeforeOrSame(iVar25,iVar27);
  if (!bVar1) {
    Inst__isBeforeOrSame(iVar26,iVar27);
  }
  if (!bVar2) {
    Inst__isBeforeOrSame(local_8c,iVar27);
  }
  iVar7 = *(int *)(*(int *)(iVar27 + 0x88) + 8);
  while (iVar7 == 0x8e) {
    iVar27 = *(int *)(iVar27 + 8);
    iVar7 = *(int *)(*(int *)(iVar27 + 0x88) + 8);
  }
  vcall1cResult = (**(code **)(*piVar20 + 0x1c))(piVar20);
  if (vcall1cResult != 0) {
    puVar11 = (undefined4 *)0x0;
    if (*(int *)(piVar20[0x34] + 4) != 0) {
      puVar11 = *(undefined4 **)(piVar20[0x34] + 8);
    }
    piVar20 = (int *)*puVar11;
    iVar27 = FUN_000e83bc(piVar20);
  }
  vcall2cResult = (**(code **)(*piVar20 + 0x2c))(piVar20);
  piVar21 = piVar20;
  if (vcall2cResult != 0) {
    puVar11 = (undefined4 *)0x0;
    if (*(int *)(piVar20[0x34] + 4) != 0) {
      puVar11 = *(undefined4 **)(piVar20[0x34] + 8);
    }
    piVar21 = (int *)*puVar11;
    iVar27 = Block__isAncestorOf(piVar21,piVar20[0x54]);
    if (iVar27 == 0) {
      puVar11 = (undefined4 *)0x0;
      if (1 < *(uint *)(piVar20[0x34] + 4)) {
        puVar11 = (undefined4 *)(*(int *)(piVar20[0x34] + 8) + 4);
      }
      piVar21 = (int *)*puVar11;
    }
    iVar27 = FUN_000e83bc(piVar21);
  }
  uVar5 = DAT_001b0044;
  iVar7 = piVar21[0x2b];
  uVar17 = *(undefined4 *)(iVar7 + 8);
  if (uVar15 == 2) {
    loopIndexD = 0;
    local_c4[0] = DAT_001b0038;
    local_c8 = DAT_001b0038;
    local_78 = &DAT_001b40f0;
    countdownC = 4;
    local_80 = &DAT_001b40f0;
    local_d4 = DAT_001b0044;
    local_7c = &local_d8;
    puVar11 = puVar23;
    do {
      if (iVar24 == puVar11[4]) {
        *(undefined1 *)((int)&local_d4 + (uint)*(byte *)((int)puVar23 + loopIndexD + 0x20)) = 0;
        bVar3 = *(byte *)((int)puVar23 + loopIndexD + 0x20);
        *(byte *)((int)&local_c8 + (uint)bVar3) = bVar3;
      }
      loopIndexD = loopIndexD + 1;
      puVar11 = puVar11 + 1;
      countdownC = countdownC + -1;
    } while (countdownC != 0);
    loopIndexD = 0;
    countdownC = 4;
    do {
      if (*(char *)((int)&local_d4 + loopIndexD) == '\x01') {
        *(char *)((int)local_c4 + loopIndexD) = (char)loopIndexD;
        *(undefined1 *)((int)&local_d4 + loopIndexD) = 0;
        break;
      }
      loopIndexD = loopIndexD + 1;
      countdownC = countdownC + -1;
    } while (countdownC != 0);
    iVar24 = ((int (*)())IRInst__createWithConstantOperands)(2,uVar5,iVar24,iVar7,uVar17,(double)FLOAT_001aa0d4);
    *(undefined4 *)(iVar24 + 0x160) = *(undefined4 *)(iVar7 + 0x478);
    operandRecord = IRInst__getOperandRecord(iVar24,0);
    WriteMask__fromSelectWord(&local_a8,*(undefined4 *)(operandRecord + 0x10));
    uVar5 = local_c8;
    *(undefined4 *)(iVar24 + 0xc) = local_a8;
    operandRecord = IRInst__getOperandRecord(iVar24,1);
    uVar6 = local_c4[0];
    *(undefined4 *)(operandRecord + 0x10) = uVar5;
    operandRecord = IRInst__getOperandRecord(iVar24,2);
    loopIndexB = 0;
    local_c4[0] = *(undefined4 *)(local_78 + -0x40ac);
    local_d4 = *(undefined4 *)(local_80 + -0x40b8);
    *(undefined4 *)(operandRecord + 0x10) = uVar6;
    countdownG = 4;
    puVar11 = puVar23;
    do {
      if (iVar25 == puVar11[4]) {
        *(undefined1 *)((int)local_7c + *(byte *)((int)puVar23 + loopIndexB + 0x20) + 0x14) = 0;
        bVar3 = *(byte *)((int)puVar23 + loopIndexB + 0x20);
        *(byte *)((int)local_7c + bVar3 + 0x10) = bVar3;
      }
      loopIndexB = loopIndexB + 1;
      puVar11 = puVar11 + 1;
      countdownG = countdownG + -1;
    } while (countdownG != 0);
    local_70 = local_c4;
    countdownC = 4;
    loopIndexD = 0;
    do {
      if (*(char *)(loopIndexD + (int)local_70) == '\x01') {
        *(char *)((int)local_7c + loopIndexD + 4) = (char)loopIndexD;
        *(undefined1 *)((int)local_7c + loopIndexD + 0x14) = 0;
        break;
      }
      loopIndexD = loopIndexD + 1;
      countdownC = countdownC + -1;
    } while (countdownC != 0);
    local_c8 = local_d4;
    iVar13 = ((int (*)())IRInst__createWithConstantOperands)(2,local_c4[0],iVar25,iVar7,uVar17,(double)FLOAT_001aa0d4);
    *(undefined4 *)(iVar13 + 0x160) = *(undefined4 *)(iVar7 + 0x478);
    operandRecord2 = IRInst__getOperandRecord(iVar13,0);
    WriteMask__fromSelectWord(&local_a4,*(undefined4 *)(operandRecord2 + 0x10));
    uVar6 = local_c8;
    *(undefined4 *)(iVar13 + 0xc) = local_a4;
    operandRecord2 = IRInst__getOperandRecord(iVar13,1);
    uVar5 = local_d4;
    *(undefined4 *)(operandRecord2 + 0x10) = uVar6;
    operandRecord2 = IRInst__getOperandRecord(iVar13,2);
    iVar28 = 0;
    *(undefined4 *)(operandRecord2 + 0x10) = uVar5;
    newInst = IRInst__create(0x12,uVar17);
    *(undefined4 *)(newInst + 0x120) = 0;
    *(undefined4 *)(newInst + 0x98) = 0;
    *(undefined4 *)(newInst + 0x124) = 0;
    *(undefined4 *)(newInst + 0x94) = *(undefined4 *)(newInst + 0x14c);
    sourceDef = IRInst__getOperandSource(iVar24,1);
    operandRecord = IRInst__getOperandRecord(iVar24,2);
    local_d4 = *(undefined4 *)(operandRecord + 0x10);
    countdownG = 4;
    do {
      if (*(char *)((int)&local_d4 + iVar28) != '\x04') goto LAB_0014488c;
      iVar28 = iVar28 + 1;
      countdownG = countdownG + -1;
    } while (countdownG != 0);
    iVar28 = -1;
LAB_0014488c:
    sourceDef2 = IRInst__getOperandSource(iVar13,1);
    operandRecord4 = IRInst__getOperandRecord(iVar13,2);
    iVar29 = 0;
    local_c8 = *(undefined4 *)(operandRecord4 + 0x10);
    countdownD = 4;
    do {
      if (*(char *)((int)&local_c8 + iVar29) != '\x04') goto LAB_001448d8;
      iVar29 = iVar29 + 1;
      countdownD = countdownD + -1;
    } while (countdownD != 0);
    iVar29 = -1;
LAB_001448d8:
    loopIndexC = 0;
    local_c4[0] = *(undefined4 *)(local_78 + -0x40ac);
    puVar16 = puVar23 + 8;
    local_d0 = *(undefined4 *)(local_80 + -0x40b8);
    countdownB = 4;
    puVar11 = puVar23;
    local_cc = local_d0;
    do {
      if (sourceDef == puVar11[4]) {
        *(undefined1 *)(loopIndexC + (int)local_70) = 0;
        local_74 = &local_cc;
        *(undefined1 *)((int)&local_d0 + loopIndexC) = *(undefined1 *)puVar16;
        *(char *)(loopIndexC + (int)&local_cc) = (char)iVar29;
      }
      else if (sourceDef2 == puVar11[4]) {
        *(char *)((int)&local_d0 + loopIndexC) = (char)iVar28;
        *(undefined1 *)(loopIndexC + (int)local_70) = 0;
        local_74 = &local_cc;
        *(undefined1 *)(loopIndexC + (int)&local_cc) = *(undefined1 *)puVar16;
      }
      loopIndexC = loopIndexC + 1;
      puVar16 = (undefined4 *)((int)puVar16 + 1);
      puVar11 = puVar11 + 1;
      countdownB = countdownB + -1;
    } while (countdownB != 0);
    *(undefined4 *)(newInst + 0x9c) = local_c4[0];
    IRInst__setOperandSource(newInst,1,iVar24,1,uVar17);
    IROperand__setModifierBits(newInst + 0xa4,1,0);
    IROperand__setModifierBits(newInst + 0xa4,2,0);
    uVar5 = local_d0;
    operandRecord2 = IRInst__getOperandRecord(newInst,1);
    *(undefined4 *)(operandRecord2 + 0x10) = uVar5;
    IRInst__setOperandSource(newInst,2,iVar13,1,uVar17);
    IROperand__setModifierBits(newInst + 0xbc,1,0);
    IROperand__setModifierBits(newInst + 0xbc,2,0);
    uVar5 = local_cc;
    operandRecord2 = IRInst__getOperandRecord(newInst,2);
    *(undefined4 *)(operandRecord2 + 0x10) = uVar5;
    operandRecord2 = IRInst__getOperandRecord(newInst,0);
    WriteMask__fromSelectWord(&local_a0,*(undefined4 *)(operandRecord2 + 0x10));
    *(undefined4 *)(newInst + 0xc) = local_a0;
    Block__insertInstBefore(piVar21,iVar27,iVar24);
  }
  else {
    if (uVar15 < 2) {
      local_7c = &local_d8;
      goto LAB_0014514c;
    }
    local_7c = &local_d8;
    if (4 < uVar15) goto LAB_0014514c;
    local_78 = &DAT_001b40f0;
    loopIndexB = 0;
    local_80 = &DAT_001b40f0;
    countdownI = 4;
    local_c4[0] = DAT_001b0038;
    local_cc = DAT_001b0044;
    local_d0 = DAT_001b0038;
    puVar11 = puVar23;
    do {
      if (iVar24 == puVar11[4]) {
        *(undefined1 *)((int)&local_cc + (uint)*(byte *)((int)puVar23 + loopIndexB + 0x20)) = 0;
        bVar3 = *(byte *)((int)puVar23 + loopIndexB + 0x20);
        *(byte *)((int)&local_d0 + (uint)bVar3) = bVar3;
      }
      loopIndexB = loopIndexB + 1;
      puVar11 = puVar11 + 1;
      countdownI = countdownI + -1;
    } while (countdownI != 0);
    local_74 = &local_cc;
    countdownI = 4;
    loopIndexB = 0;
    do {
      if (*(char *)(loopIndexB + (int)local_74) == '\x01') {
        *(char *)((int)local_c4 + loopIndexB) = (char)loopIndexB;
        *(undefined1 *)((int)&local_cc + loopIndexB) = 0;
        break;
      }
      loopIndexB = loopIndexB + 1;
      countdownI = countdownI + -1;
    } while (countdownI != 0);
    iVar24 = ((int (*)())IRInst__createWithConstantOperands)(2,uVar5,iVar24,iVar7,uVar17,(double)FLOAT_001aa0e8);
    *(undefined4 *)(iVar24 + 0x160) = *(undefined4 *)(iVar7 + 0x478);
    operandRecord3 = IRInst__getOperandRecord(iVar24,0);
    WriteMask__fromSelectWord(&local_9c,*(undefined4 *)(operandRecord3 + 0x10));
    uVar5 = local_d0;
    *(undefined4 *)(iVar24 + 0xc) = local_9c;
    operandRecord3 = IRInst__getOperandRecord(iVar24,1);
    uVar6 = local_c4[0];
    *(undefined4 *)(operandRecord3 + 0x10) = uVar5;
    operandRecord3 = IRInst__getOperandRecord(iVar24,2);
    local_d0 = *(undefined4 *)(local_80 + -0x40b8);
    loopIndexF = 0;
    local_c4[0] = *(undefined4 *)(local_78 + -0x40ac);
    *(undefined4 *)(operandRecord3 + 0x10) = uVar6;
    countdownC = 4;
    puVar11 = puVar23;
    do {
      if (iVar25 == puVar11[4]) {
        *(undefined1 *)((int)local_7c + *(byte *)((int)puVar23 + loopIndexF + 0x20) + 0x14) = 0;
        bVar3 = *(byte *)((int)puVar23 + loopIndexF + 0x20);
        *(byte *)((int)local_7c + bVar3 + 8) = bVar3;
      }
      loopIndexF = loopIndexF + 1;
      puVar11 = puVar11 + 1;
      countdownC = countdownC + -1;
    } while (countdownC != 0);
    local_70 = local_c4;
    countdownI = 4;
    loopIndexB = 0;
    do {
      if (*(char *)(loopIndexB + (int)local_70) == '\x01') {
        *(char *)((int)local_7c + loopIndexB + 0xc) = (char)loopIndexB;
        *(undefined1 *)((int)local_7c + loopIndexB + 0x14) = 0;
        break;
      }
      loopIndexB = loopIndexB + 1;
      countdownI = countdownI + -1;
    } while (countdownI != 0);
    loopIndexB = 0;
    countdownI = 4;
    do {
      if (*(char *)(loopIndexB + (int)local_70) == '\x01') {
        *(char *)((int)local_7c + loopIndexB + 0x10) = (char)loopIndexB;
        *(undefined1 *)((int)local_7c + loopIndexB + 0x14) = 0;
        break;
      }
      loopIndexB = loopIndexB + 1;
      countdownI = countdownI + -1;
    } while (countdownI != 0);
    local_cc = local_d0;
    local_c8 = local_d0;
    iVar25 = ((int (*)())IRInst__createWithConstantOperands)(3,local_c4[0],iVar25,iVar7,uVar17,(double)FLOAT_001aa0e8);
    *(undefined4 *)(iVar25 + 0x160) = *(undefined4 *)(iVar7 + 0x478);
    operandRecord3 = IRInst__getOperandRecord(iVar25,0);
    WriteMask__fromSelectWord(&local_98,*(undefined4 *)(operandRecord3 + 0x10));
    uVar5 = local_d0;
    *(undefined4 *)(iVar25 + 0xc) = local_98;
    operandRecord3 = IRInst__getOperandRecord(iVar25,1);
    uVar6 = local_cc;
    *(undefined4 *)(operandRecord3 + 0x10) = uVar5;
    operandRecord3 = IRInst__getOperandRecord(iVar25,2);
    uVar5 = local_c8;
    *(undefined4 *)(operandRecord3 + 0x10) = uVar6;
    operandRecord3 = IRInst__getOperandRecord(iVar25,3);
    loopIndexF = 0;
    local_c8 = *(undefined4 *)(local_78 + -0x40ac);
    local_d0 = *(undefined4 *)(local_80 + -0x40b8);
    *(undefined4 *)(operandRecord3 + 0x10) = uVar5;
    countdownC = 4;
    local_cc = local_d0;
    puVar11 = puVar23;
    do {
      if (iVar26 == puVar11[4]) {
        *(undefined1 *)((int)local_7c + *(byte *)((int)puVar23 + loopIndexF + 0x20) + 0x10) = 0;
        bVar3 = *(byte *)((int)puVar23 + loopIndexF + 0x20);
        *(byte *)((int)local_7c + bVar3 + 0xc) = bVar3;
      }
      loopIndexF = loopIndexF + 1;
      puVar11 = puVar11 + 1;
      countdownC = countdownC + -1;
    } while (countdownC != 0);
    loopIndexB = 0;
    countdownI = 4;
    do {
      if (*(char *)((int)&local_c8 + loopIndexB) == '\x01') {
        *(char *)((int)local_7c + loopIndexB + 8) = (char)loopIndexB;
        *(undefined1 *)((int)local_7c + loopIndexB + 0x10) = 0;
        break;
      }
      loopIndexB = loopIndexB + 1;
      countdownI = countdownI + -1;
    } while (countdownI != 0);
    iVar13 = ((int (*)())IRInst__createWithConstantOperands)(2,local_c8,iVar26,iVar7,uVar17,(double)FLOAT_001aa0d4);
    *(undefined4 *)(iVar13 + 0x160) = *(undefined4 *)(iVar7 + 0x478);
    iVar28 = 0;
    operandRecord = IRInst__getOperandRecord(iVar13,0);
    WriteMask__fromSelectWord(&local_94,*(undefined4 *)(operandRecord + 0x10));
    uVar6 = local_cc;
    *(undefined4 *)(iVar13 + 0xc) = local_94;
    operandRecord = IRInst__getOperandRecord(iVar13,1);
    uVar5 = local_d0;
    *(undefined4 *)(operandRecord + 0x10) = uVar6;
    operandRecord = IRInst__getOperandRecord(iVar13,2);
    *(undefined4 *)(operandRecord + 0x10) = uVar5;
    newInst = IRInst__create(0x14,uVar17);
    *(undefined4 *)(newInst + 0x120) = 0;
    *(undefined4 *)(newInst + 0x98) = 0;
    *(undefined4 *)(newInst + 0x124) = 0;
    *(undefined4 *)(newInst + 0x94) = *(undefined4 *)(newInst + 0x14c);
    operandSource = IRInst__getOperandSource(iVar24,1);
    operandRecord = IRInst__getOperandRecord(iVar24,2);
    local_d0 = *(undefined4 *)(operandRecord + 0x10);
    countdownG = 4;
    do {
      if (*(char *)((int)&local_d0 + iVar28) != '\x04') goto LAB_00144dd8;
      iVar28 = iVar28 + 1;
      countdownG = countdownG + -1;
    } while (countdownG != 0);
    iVar28 = -1;
LAB_00144dd8:
    operandSourceB = IRInst__getOperandSource(iVar25,1);
    operandRecord = IRInst__getOperandRecord(iVar25,2);
    local_cc = *(undefined4 *)(operandRecord + 0x10);
    iVar19 = 0;
    operandRecord = IRInst__getOperandRecord(iVar25,3);
    local_c8 = *(undefined4 *)(operandRecord + 0x10);
    countdownG = 4;
    do {
      if (*(char *)(iVar19 + (int)local_74) != '\x04') goto LAB_00144e38;
      iVar19 = iVar19 + 1;
      countdownG = countdownG + -1;
    } while (countdownG != 0);
    iVar19 = -1;
LAB_00144e38:
    iVar26 = 0;
    countdownJ = 4;
    do {
      if (*(char *)((int)&local_c8 + iVar26) != '\x04') goto LAB_00144e5c;
      iVar26 = iVar26 + 1;
      countdownJ = countdownJ + -1;
    } while (countdownJ != 0);
    iVar26 = -1;
LAB_00144e5c:
    sourceDef3 = IRInst__getOperandSource(iVar13,1);
    operandRecord5 = IRInst__getOperandRecord(iVar13,2);
    iVar14 = 0;
    local_c4[0] = *(undefined4 *)(operandRecord5 + 0x10);
    countdownB = 4;
    do {
      if (*(char *)(iVar14 + (int)local_70) != '\x04') goto LAB_00144ea8;
      iVar14 = iVar14 + 1;
      countdownB = countdownB + -1;
    } while (countdownB != 0);
    iVar14 = -1;
LAB_00144ea8:
    local_d4 = *(undefined4 *)(local_80 + -0x40b8);
    puVar16 = puVar23 + 8;
    local_c4[1] = *(undefined4 *)(local_78 + -0x40ac);
    countdownK = 4;
    loopIndex = 0;
    puVar11 = puVar23;
    do {
      iVar8 = puVar11[4];
      if (operandSource == iVar8) {
        *(undefined1 *)(loopIndex + (int)local_6c) = 0;
        uVar9 = *(undefined1 *)puVar16;
        *(char *)(loopIndex + (int)local_64) = (char)iVar19;
        *(undefined1 *)(loopIndex + (int)local_68) = uVar9;
        *(char *)(loopIndex + (int)local_60) = (char)iVar14;
      }
      else if (operandSourceB == iVar8) {
        *(undefined1 *)(loopIndex + (int)local_6c) = 0;
        *(char *)(loopIndex + (int)local_68) = (char)iVar28;
        uVar9 = *(undefined1 *)puVar16;
        *(char *)(loopIndex + (int)local_60) = (char)iVar14;
        *(undefined1 *)(loopIndex + (int)local_64) = uVar9;
      }
      else if (sourceDef3 == iVar8) {
        *(undefined1 *)(loopIndex + (int)local_6c) = 0;
        *(char *)(loopIndex + (int)local_68) = (char)iVar28;
        *(char *)(loopIndex + (int)local_64) = (char)iVar26;
        *(undefined1 *)(loopIndex + (int)local_60) = *(undefined1 *)puVar16;
      }
      else if ((!bVar2) && (local_8c == iVar8)) {
        *(char *)(loopIndex + (int)local_5c) = (char)loopIndex;
      }
      loopIndex = loopIndex + 1;
      puVar16 = (undefined4 *)((int)puVar16 + 1);
      puVar11 = puVar11 + 1;
      countdownK = countdownK + -1;
    } while (countdownK != 0);
    *(undefined4 *)(newInst + 0x9c) = local_c4[1];
    local_c4[2] = local_d4;
    local_c4[3] = local_d4;
    local_b4 = local_d4;
    IRInst__setOperandSource(newInst,1,iVar24,1,uVar17);
    IROperand__setModifierBits(newInst + 0xa4,1,0);
    IROperand__setModifierBits(newInst + 0xa4,2,0);
    uVar5 = local_c4[2];
    operandRecord = IRInst__getOperandRecord(newInst,1);
    *(undefined4 *)(operandRecord + 0x10) = uVar5;
    IRInst__setOperandSource(newInst,2,iVar25,1,uVar17);
    IROperand__setModifierBits(newInst + 0xbc,1,0);
    IROperand__setModifierBits(newInst + 0xbc,2,0);
    uVar5 = local_c4[3];
    operandRecord = IRInst__getOperandRecord(newInst,2);
    *(undefined4 *)(operandRecord + 0x10) = uVar5;
    IRInst__setOperandSource(newInst,3,iVar13,1,uVar17);
    IROperand__setModifierBits(newInst + 0xd4,1,0);
    IROperand__setModifierBits(newInst + 0xd4,2,0);
    uVar5 = local_b4;
    operandRecord = IRInst__getOperandRecord(newInst,3);
    *(undefined4 *)(operandRecord + 0x10) = uVar5;
    if (bVar2) {
      operandRecord = IRInst__getOperandRecord(newInst,0);
      WriteMask__fromSelectWord(&local_90,*(undefined4 *)(operandRecord + 0x10));
      *(undefined4 *)(newInst + 0xc) = local_90;
    }
    else {
      IRInst__setExtraOperandSource(newInst,local_8c,1,uVar17);
      uVar17 = local_d4;
      operandRecord = IRInst__getOperandRecord(newInst,4);
      uVar5 = DAT_001b0048;
      *(undefined4 *)(operandRecord + 0x10) = uVar17;
      *(undefined4 *)(newInst + 0xc) = uVar5;
    }
    Block__insertInstBefore(piVar21,iVar27,iVar24);
    Block__insertInstBefore(piVar21,iVar27,iVar25);
  }
  Block__insertInstBefore(piVar21,iVar27,iVar13);
  Block__insertInstBefore(piVar21,iVar27,newInst);
  puVar23[9] = newInst;
LAB_0014514c:
  countdownE = 4;
  puVar11 = puVar23;
  do {
    *puVar11 = 1;
    puVar11 = puVar11 + 1;
    countdownE = countdownE + -1;
  } while (countdownE != 0);
  iVar24 = puVar23[9];
LAB_0014516c:
  operandRecord2 = IRInst__getOperandRecord(inst,iVar22);
  loopIndexD = 0;
  local_b0[0] = *(undefined4 *)(operandRecord2 + 0x10);
  do {
    cVar4 = *(char *)((int)local_b0 + loopIndexD);
    if (cVar4 != '\x04') {
      sourceDef = IRInst__getOperandSource(inst,iVar22);
      countdown = 4;
      loopIndexE = 0;
      puVar11 = puVar23;
      do {
        if ((sourceDef == puVar11[4]) && (cVar4 == *(char *)((int)puVar23 + loopIndexE + 0x20))) {
          uVar9 = (undefined1)loopIndexE;
          goto LAB_001451cc;
        }
        loopIndexE = loopIndexE + 1;
        puVar11 = puVar11 + 1;
        countdown = countdown + -1;
      } while (countdown != 0);
      uVar9 = 0xff;
LAB_001451cc:
      *(undefined1 *)((int)local_b0 + loopIndexD) = uVar9;
    }
    uVar5 = local_b0[0];
    moreComponents = loopIndexD != 3;
    loopIndexD = loopIndexD + 1;
  } while (moreComponents);
  operandRecord2 = IRInst__getOperandRecord(inst,iVar22);
  *(undefined4 *)(operandRecord2 + 0x10) = uVar5;
  if ((*(int *)(inst + 0x84) == iVar22) && ((*(uint *)(inst + 0x14) & 0x200) != 0)) {
    IRInst__setExtraOperandSource(inst,iVar24,1,*param_1);
  }
  else {
    IRInst__setOperandSource(inst,iVar22,iVar24,1,*param_1);
  }
  operandRecord2 = IRInst__getOperandRecord(inst2,iVar22);
  loopIndexD = 0;
  local_d8 = *(undefined4 *)(operandRecord2 + 0x10);
  do {
    cVar4 = *(char *)(loopIndexD + (int)local_7c);
    if (cVar4 != '\x04') {
      sourceDef = IRInst__getOperandSource(inst2,iVar22);
      countdown = 4;
      loopIndexE = 0;
      puVar11 = puVar23;
      do {
        if ((sourceDef == puVar11[4]) && (cVar4 == *(char *)((int)puVar23 + loopIndexE + 0x20))) {
          uVar9 = (undefined1)loopIndexE;
          goto LAB_00145280;
        }
        loopIndexE = loopIndexE + 1;
        puVar11 = puVar11 + 1;
        countdown = countdown + -1;
      } while (countdown != 0);
      uVar9 = 0xff;
LAB_00145280:
      *(undefined1 *)(loopIndexD + (int)local_7c) = uVar9;
    }
    uVar5 = local_d8;
    moreComponents = loopIndexD != 3;
    loopIndexD = loopIndexD + 1;
  } while (moreComponents);
  operandRecord2 = IRInst__getOperandRecord(inst2,iVar22);
  *(undefined4 *)(operandRecord2 + 0x10) = uVar5;
  if ((*(int *)(inst2 + 0x84) == iVar22) && ((*(uint *)(inst2 + 0x14) & 0x200) != 0)) {
    IRInst__setExtraOperandSource(inst2,iVar24,1,*param_1);
  }
  else {
    IRInst__setOperandSource(inst2,iVar22,iVar24,1,*param_1);
  }
LAB_001452d4:
  isLast = iVar22 == 4;
  param_4 = param_4 + 4;
  iVar22 = iVar22 + 1;
  if (isLast) {
    return;
  }
  goto LAB_00144144;
}

/* FUN_0014532c @ 0x14532c (836 bytes) */
int FUN_0014532c(param_1, param_2)
  undefined4 *param_1;
  int *param_2;
{
  int sourceDef;
  uint uVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint loopIndex;
  int iVar8;
  uint *puVar9;
  int iVar10;
  int iVar11;
  
  iVar5 = param_2[3];
  iVar6 = param_2[2];
  iVar10 = param_2[1];
  iVar11 = *param_2;
  if (param_2[4] != 0) {
    iVar5 = param_2[2];
    iVar6 = param_2[3];
    iVar10 = *param_2;
    iVar11 = param_2[1];
  }
  param_1[2] = param_1[2] + 1;
  if (0 < param_2[5]) {
    ((int (*)())FUN_001440e4)(param_1,iVar11,iVar10,param_2 + 5);
  }
  iVar8 = 0;
  if ((*(uint *)(iVar11 + 0x14) & 0x200) != 0) {
    iVar8 = IRInst__getOperandSource(iVar11,*(undefined4 *)(iVar11 + 0x84));
  }
  if (iVar10 == iVar8) {
    uVar4 = *param_1;
    sourceDef = IRInst__getOperandSource(iVar11,*(undefined4 *)(iVar11 + 0x84));
    puVar9 = *(uint **)(sourceDef + 0x10);
    uVar1 = puVar9[1];
    if (0 < (int)uVar1) {
      loopIndex = 0;
      do {
        if (loopIndex < *puVar9) {
          if (uVar1 <= loopIndex) {
            _memset(uVar1 * 4 + puVar9[2],0,(loopIndex - uVar1) * 4 + 4);
            puVar9[1] = loopIndex + 1;
          }
          piVar2 = (int *)(loopIndex * 4 + puVar9[2]);
        }
        else {
          piVar2 = (int *)Vector__elementRefGrow(puVar9,loopIndex);
        }
        if (iVar11 == *piVar2) {
          Vector__removeAt(puVar9,loopIndex);
          sourceDef = IRInst__getOperandSource(iVar11,*(undefined4 *)(iVar11 + 0x84));
          *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + -1;
          break;
        }
        uVar1 = puVar9[1];
        loopIndex = loopIndex + 1;
      } while ((int)loopIndex < (int)uVar1);
    }
    iVar8 = 0;
    IRInst__setOperandSource(iVar11,*(undefined4 *)(iVar11 + 0x84),0,1,uVar4);
    *(int *)(iVar11 + 0x84) = *(int *)(iVar11 + 0x84) + -1;
    *(uint *)(iVar11 + 0x14) = *(uint *)(iVar11 + 0x14) & 0xfffffdff;
  }
  iVar3 = 0;
  if ((*(uint *)(iVar10 + 0x14) & 0x200) != 0) {
    iVar3 = IRInst__getOperandSource(iVar10,*(undefined4 *)(iVar10 + 0x84));
  }
  if (iVar11 == iVar3) {
    uVar4 = *param_1;
    sourceDef = IRInst__getOperandSource(iVar10,*(undefined4 *)(iVar10 + 0x84));
    puVar9 = *(uint **)(sourceDef + 0x10);
    uVar1 = puVar9[1];
    if (0 < (int)uVar1) {
      loopIndex = 0;
      do {
        if (loopIndex < *puVar9) {
          if (uVar1 <= loopIndex) {
            _memset(uVar1 * 4 + puVar9[2],0,(loopIndex - uVar1) * 4 + 4);
            puVar9[1] = loopIndex + 1;
          }
          piVar2 = (int *)(loopIndex * 4 + puVar9[2]);
        }
        else {
          piVar2 = (int *)Vector__elementRefGrow(puVar9,loopIndex);
        }
        if (iVar10 == *piVar2) {
          Vector__removeAt(puVar9,loopIndex);
          sourceDef = IRInst__getOperandSource(iVar10,*(undefined4 *)(iVar10 + 0x84));
          *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + -1;
          break;
        }
        uVar1 = puVar9[1];
        loopIndex = loopIndex + 1;
      } while ((int)loopIndex < (int)uVar1);
    }
    IRInst__setOperandSource(iVar10,*(undefined4 *)(iVar10 + 0x84),0,1,uVar4);
    *(int *)(iVar10 + 0x84) = *(int *)(iVar10 + 0x84) + -1;
    *(uint *)(iVar10 + 0x14) = *(uint *)(iVar10 + 0x14) & 0xfffffdff;
  }
  else if ((iVar3 != 0) && (iVar8 != iVar3)) {
    IRInst__setExtraOperandSource(iVar11,iVar3,1,*param_1);
    IRInst__getOperandRecord(iVar11,*(undefined4 *)(iVar11 + 0x84));
  }
  ((int (*)())FUN_0014375c)(param_1,iVar11,iVar6);
  ((int (*)())FUN_0014375c)(param_1,iVar10,iVar5);
  ((int (*)())FUN_001411dc)(param_1,iVar11,iVar11,iVar6);
  ((int (*)())FUN_001411dc)(param_1,iVar11,iVar10,iVar5);
  return ((int (*)())FUN_001415a4)(param_1,iVar10,iVar11);
}

/* pass_post_pack_insts @ 0x145670 (3828 bytes) */
int pass_post_pack_insts(param_1)
  int *param_1;
{
  uint lastScanIndex;
  uint minCapacityB;
  uint grownCapacityC;
  uint curCount;
  uint copyIndexG;
  uint scanIndex;
  uint newVecSizeC;
  uint minCapacity;
  uint keptCountB;
  uint scoreIndex;
  uint copyIndexE;
  uint grownCapacityB;
  uint keptCount;
  uint nextPairIndex;
  uint copyIndexD;
  uint grownCapacity;
  uint recordCount;
  uint newVecSizeB;
  uint copyIndexC;
  uint lastIndex;
  uint bestIndex;
  uint copyIndexB;
  uint copyIndex;
  uint vecCapacity;
  int grownDataD;
  int copyDestB;
  int copyOffsetG;
  int replacedInst;
  int copyOffsetF;
  int resultElement;
  int oldData;
  int scoreOffset;
  int candidateTotal;
  int copyOffsetE;
  int candidateRecord;
  int candidateOffset;
  int copySourceB;
  int grownDataC;
  int packable;
  int copyOffsetD;
  int vecData;
  int lastOffset;
  int copyOffsetC;
  int bestOffset;
  int grownDataB;
  int candidateScore;
  int scanData;
  int laneCountdown;
  int nextInst;
  int nextBlock;
  int candInstA;
  int copyDest;
  int copySource;
  int buildResult;
  int copyOffsetB;
  int grownData;
  int resultData;
  int copyOffset;
  int bestScore;
  int lookaheadInst;
  bool candidateLimitHit;
  int allocation3;
  int allocation;
  int operandRecord;
  bool atScanStart;
  int iVar2;
  uint laneIndex;
  int nextInstB;
  int iVar5;
  int iVar6;
  int block;
  int iVar8;
  undefined4 arenaAt378;
  uint candidateCount;
  uint vecSize;
  int *bestCandidate;
  uint newVecSize;
  uint recordIndex;
  uint uVar15;
  uint uVar16;
  int candidateByteOffset;
  int inst;
  uint copyIndexF;
  uint uVar20;
  int instA;
  int *arenaPtr;
  undefined4 packedWriteMask;
  undefined4 local_64 [3];
  undefined4 packResult;
  int replacementInst;
  
  block = *(int *)(param_1[1] + 900);
  for (nextBlock = *(int *)(*(int *)(param_1[1] + 900) + 8); nextBlock != 0; nextBlock = *(int *)(nextBlock + 8)) {
    lookaheadInst = *(int *)(*(int *)(block + 0x98) + 8);
    inst = *(int *)(block + 0x98);
    if (lookaheadInst != 0) {
      do {
        nextInst = lookaheadInst;
        if ((*(uint *)(inst + 0x14) & 1) != 0) {
          ((int (*)())FUN_00141044)(&packResult,param_1,inst);
          packedWriteMask = packResult;
          if ((*(uint *)(inst + 0x14) & 0x200) != 0) {
            operandRecord = IRInst__getOperandRecord(inst,*(undefined4 *)(inst + 0x84));
            laneIndex = 0;
            local_64[0] = *(undefined4 *)(operandRecord + 0x10);
            laneCountdown = 4;
            do {
              if (*(byte *)((int)local_64 + laneIndex) == laneIndex) {
                *(undefined1 *)((int)local_64 + (laneIndex - 4)) = 1;
              }
              laneIndex = laneIndex + 1;
              laneCountdown = laneCountdown + -1;
            } while (laneCountdown != 0);
          }
          nextInst = *(int *)(inst + 8);
          *(undefined4 *)(inst + 0xc) = packedWriteMask;
        }
        lookaheadInst = *(int *)(nextInst + 8);
        inst = nextInst;
      } while (*(int *)(nextInst + 8) != 0);
      nextBlock = *(int *)(block + 8);
    }
    block = nextBlock;
  }
  arenaAt378 = *(undefined4 *)(*param_1 + 0x378);
  vecData = Arena__alloc(arenaAt378,0x2c0);
  iVar2 = param_1[1];
  iVar6 = *(int *)(*(int *)(iVar2 + 900) + 8);
  if (iVar6 != 0) {
    candidateCount = 0;
    candidateTotal = 0;
    vecCapacity = 0x10;
    vecSize = 0;
    iVar2 = *(int *)(iVar2 + 900);
    do {
      iVar5 = iVar6;
      iVar6 = *(int *)(*(int *)(iVar2 + 0x98) + 8);
      instA = *(int *)(iVar2 + 0x98);
      if (iVar6 != 0) {
        do {
          iVar5 = iVar6;
          if ((*(uint *)(instA + 0x14) & 1) != 0) {
            iVar6 = FUN_0011379c(*(undefined4 *)(param_1[1] + 8),instA);
            if (iVar6 != 0) {
              atScanStart = true;
              iVar6 = *(int *)(param_1[1] + 900);
              for (iVar5 = *(int *)(*(int *)(param_1[1] + 900) + 8); iVar5 != 0;
                  iVar5 = *(int *)(iVar5 + 8)) {
                iVar8 = *(int *)(*(int *)(iVar6 + 0x98) + 8);
                if (iVar8 != 0) {
                  candidateByteOffset = candidateCount * 0x2c;
                  iVar5 = *(int *)(iVar6 + 0x98);
                  do {
                    nextInstB = iVar8;
                    if ((*(uint *)(iVar5 + 0x14) & 1) != 0) {
                      if (atScanStart) {
                        nextInstB = *(int *)(instA + 8);
                        atScanStart = false;
                        iVar6 = iVar2;
                      }
                      else {
                        packable = FUN_0011379c(*(undefined4 *)(param_1[1] + 8),iVar5);
                        if (packable == 0) {
                          nextInstB = *(int *)(iVar5 + 8);
                        }
                        else {
                          candidateLimitHit = 0x3ff < candidateTotal;
                          candidateTotal = candidateTotal + 1;
                          if (candidateLimitHit) goto LAB_00146530;
                          newVecSize = vecSize;
                          grownDataC = vecData;
                          if ((vecSize <= candidateCount) && (newVecSize = candidateCount + 1, vecCapacity < newVecSize)) {
                            vecCapacity = (vecCapacity << 4) / 10;
                            if (vecCapacity < newVecSize) {
                              vecCapacity = newVecSize;
                            }
                            grownDataC = Arena__alloc(arenaAt378,vecCapacity * 0x2c);
                            if (vecSize != 0) {
                              copyIndexF = 0;
                              copyOffsetB = 0;
                              do {
                                copyIndexF = copyIndexF + 1;
                                _memcpy(grownDataC + copyOffsetB,vecData + copyOffsetB,0x2c);
                                copyOffsetB = copyOffsetB + 0x2c;
                              } while (vecSize != copyIndexF);
                            }
                            Arena__free(arenaAt378,vecData);
                          }
                          buildResult = ((int (*)())PostPack__buildCandidate)(param_1,instA,iVar5,grownDataC + candidateByteOffset);
                          vecSize = newVecSize;
                          vecData = grownDataC;
                          if (buildResult == 0) {
                            nextInstB = *(int *)(iVar5 + 8);
                            atScanStart = false;
                          }
                          else {
                            nextInstB = *(int *)(iVar5 + 8);
                            candidateCount = candidateCount + 1;
                            candidateByteOffset = candidateByteOffset + 0x2c;
                            atScanStart = false;
                          }
                        }
                      }
                    }
                    iVar8 = *(int *)(nextInstB + 8);
                    iVar5 = nextInstB;
                  } while (*(int *)(nextInstB + 8) != 0);
                  iVar5 = *(int *)(iVar6 + 8);
                }
                iVar6 = iVar5;
              }
            }
            iVar5 = *(int *)(instA + 8);
          }
          iVar6 = *(int *)(iVar5 + 8);
          instA = iVar5;
        } while (*(int *)(iVar5 + 8) != 0);
        iVar5 = *(int *)(iVar2 + 8);
      }
      iVar6 = *(int *)(iVar5 + 8);
      iVar2 = iVar5;
    } while (*(int *)(iVar5 + 8) != 0);
LAB_00146530:
    do {
      if ((int)candidateCount < 1) goto LAB_00146538;
      bestIndex = 0xffffffff;
      bestScore = 0;
      scoreOffset = 0;
      scoreIndex = 0;
      scanData = vecData;
      do {
        newVecSizeB = vecSize;
        vecData = scanData;
        if ((vecSize <= scoreIndex) && (newVecSizeB = scoreIndex + 1, vecCapacity < newVecSizeB)) {
          vecCapacity = (vecCapacity << 4) / 10;
          if (vecCapacity < newVecSizeB) {
            vecCapacity = newVecSizeB;
          }
          vecData = Arena__alloc(arenaAt378,vecCapacity * 0x2c);
          if (vecSize != 0) {
            copyIndexG = 0;
            copyOffsetG = 0;
            do {
              copyIndexG = copyIndexG + 1;
              _memcpy(vecData + copyOffsetG,scanData + copyOffsetG,0x2c);
              copyOffsetG = copyOffsetG + 0x2c;
            } while (vecSize != copyIndexG);
          }
          Arena__free(arenaAt378,scanData);
        }
        candidateScore = ((int (*)())FUN_00143e40)(param_1,vecData + scoreOffset);
        if ((bestIndex == 0xffffffff) || (bestScore < candidateScore)) {
          bestIndex = scoreIndex;
          bestScore = candidateScore;
        }
        scoreIndex = scoreIndex + 1;
        scoreOffset = scoreOffset + 0x2c;
      } while (((int)scoreIndex < (int)candidateCount) && (vecSize = newVecSizeB, scanData = vecData, scoreIndex != 0x80));
      if ((bestIndex == 0xffffffff) || (bestScore < 0)) goto LAB_00146538;
      vecSize = newVecSizeB;
      if ((newVecSizeB <= bestIndex) && (vecSize = bestIndex + 1, vecCapacity < vecSize)) {
        vecCapacity = (vecCapacity << 4) / 10;
        if (vecCapacity < vecSize) {
          vecCapacity = vecSize;
        }
        grownDataB = Arena__alloc(arenaAt378,vecCapacity * 0x2c);
        if (newVecSizeB != 0) {
          copyIndexF = 0;
          copyOffset = 0;
          do {
            copyIndexF = copyIndexF + 1;
            _memcpy(grownDataB + copyOffset,vecData + copyOffset,0x2c);
            copyOffset = copyOffset + 0x2c;
          } while (copyIndexF != newVecSizeB);
        }
        Arena__free(arenaAt378,vecData);
        vecData = grownDataB;
      }
      bestOffset = bestIndex * 0x2c;
      bestCandidate = (int *)(vecData + bestOffset);
      ((int (*)())FUN_0014532c)(param_1,bestCandidate);
      if (0x17 < param_1[2]) goto LAB_00146538;
      arenaPtr = param_1 + 3;
      keptCountB = 0;
      recordCount = param_1[4];
      if (recordCount != 0) {
        recordIndex = 0;
        curCount = recordCount;
        keptCount = keptCountB;
        while( true ) {
          if (curCount <= recordIndex) {
            minCapacity = recordIndex + 1;
            if ((uint)param_1[5] < minCapacity) {
              grownCapacityC = (uint)(param_1[5] << 4) / 10;
              param_1[5] = grownCapacityC;
              if (grownCapacityC < minCapacity) {
                param_1[5] = minCapacity;
              }
              oldData = param_1[6];
              allocation = Arena__alloc(*arenaPtr,param_1[5] * 0x2c);
              param_1[6] = allocation;
              if (param_1[4] != 0) {
                copyIndexG = 0;
                copyOffset = 0;
                do {
                  copySource = oldData + copyOffset;
                  copyIndexG = copyIndexG + 1;
                  copyDestB = param_1[6] + copyOffset;
                  copyOffset = copyOffset + 0x2c;
                  _memcpy(copyDestB,copySource,0x2c);
                } while (copyIndexG < (uint)param_1[4]);
              }
              Arena__free(*arenaPtr,oldData);
            }
            param_1[4] = minCapacity;
          }
          resultData = param_1[6];
          resultElement = recordIndex * 0x2c + resultData;
          keptCountB = keptCount;
          if ((*(int *)(resultElement + 0x24) != 0) && (keptCountB = keptCount + 1, keptCount < recordIndex)) {
            if ((uint)param_1[4] <= keptCount) {
              if ((uint)param_1[5] < keptCountB) {
                grownCapacityC = (uint)(param_1[5] << 4) / 10;
                param_1[5] = grownCapacityC;
                if (grownCapacityC < keptCountB) {
                  param_1[5] = keptCountB;
                }
                allocation3 = Arena__alloc(*arenaPtr,param_1[5] * 0x2c);
                param_1[6] = allocation3;
                if (param_1[4] != 0) {
                  copyIndexG = 0;
                  copyOffsetG = 0;
                  do {
                    copySourceB = resultData + copyOffsetG;
                    copyIndexG = copyIndexG + 1;
                    copyDest = param_1[6] + copyOffsetG;
                    copyOffsetG = copyOffsetG + 0x2c;
                    _memcpy(copyDest,copySourceB,0x2c);
                  } while (copyIndexG < (uint)param_1[4]);
                }
                Arena__free(*arenaPtr,resultData);
                resultData = param_1[6];
              }
              param_1[4] = keptCountB;
            }
            _memcpy(keptCount * 0x2c + resultData,resultElement,0x2c);
          }
          recordIndex = recordIndex + 1;
          if (recordCount == recordIndex) break;
          curCount = param_1[4];
          keptCount = keptCountB;
        }
      }
      if ((uint)param_1[5] < keptCountB) {
        grownCapacity = (uint)(param_1[5] << 4) / 10;
        param_1[5] = grownCapacity;
        if (grownCapacity < keptCountB) {
          param_1[5] = keptCountB;
        }
        oldData = param_1[6];
        allocation = Arena__alloc(*arenaPtr,param_1[5] * 0x2c);
        param_1[6] = allocation;
        if (param_1[4] != 0) {
          copyIndexD = 0;
          copyOffset = 0;
          do {
            copySource = oldData + copyOffset;
            copyIndexD = copyIndexD + 1;
            copyDestB = param_1[6] + copyOffset;
            copyOffset = copyOffset + 0x2c;
            _memcpy(copyDestB,copySource,0x2c);
          } while (copyIndexD < (uint)param_1[4]);
        }
        Arena__free(*arenaPtr,oldData);
      }
      param_1[4] = keptCountB;
      if (keptCountB != 0) {
        uVar15 = 0;
        do {
          minCapacityB = uVar15 + 1;
          if ((uint)param_1[4] <= uVar15) {
            if ((uint)param_1[5] < minCapacityB) {
              grownCapacityB = (uint)(param_1[5] << 4) / 10;
              param_1[5] = grownCapacityB;
              if (grownCapacityB < minCapacityB) {
                param_1[5] = minCapacityB;
              }
              oldData = param_1[6];
              allocation = Arena__alloc(*arenaPtr,param_1[5] * 0x2c);
              param_1[6] = allocation;
              if (param_1[4] != 0) {
                copyIndexE = 0;
                copyOffset = 0;
                do {
                  copySource = oldData + copyOffset;
                  copyIndexE = copyIndexE + 1;
                  copyDestB = param_1[6] + copyOffset;
                  copyOffset = copyOffset + 0x2c;
                  _memcpy(copyDestB,copySource,0x2c);
                } while (copyIndexE < (uint)param_1[4]);
              }
              Arena__free(*arenaPtr,oldData);
            }
            param_1[4] = minCapacityB;
          }
          *(undefined4 *)(uVar15 * 0x2c + param_1[6] + 0x28) = 0;
          uVar15 = minCapacityB;
        } while (minCapacityB < keptCountB);
      }
      newVecSizeC = vecSize;
      grownData = vecData;
      if ((vecSize <= bestIndex) && (newVecSizeC = bestIndex + 1, vecCapacity < newVecSizeC)) {
        vecCapacity = (vecCapacity << 4) / 10;
        if (vecCapacity < newVecSizeC) {
          vecCapacity = newVecSizeC;
        }
        grownData = Arena__alloc(arenaAt378,vecCapacity * 0x2c);
        if (vecSize != 0) {
          copyIndexD = 0;
          copyOffsetF = 0;
          do {
            copyIndexD = copyIndexD + 1;
            _memcpy(grownData + copyOffsetF,vecData + copyOffsetF,0x2c);
            copyOffsetF = copyOffsetF + 0x2c;
          } while (copyIndexD != vecSize);
        }
        Arena__free(arenaAt378,vecData);
        bestCandidate = (int *)(grownData + bestOffset);
      }
      replacementInst = *bestCandidate;
      vecSize = newVecSizeC;
      vecData = grownData;
      if ((newVecSizeC <= bestIndex) && (vecSize = bestIndex + 1, vecCapacity < vecSize)) {
        vecCapacity = (vecCapacity << 4) / 10;
        if (vecCapacity < vecSize) {
          vecCapacity = vecSize;
        }
        vecData = Arena__alloc(arenaAt378,vecCapacity * 0x2c);
        if (newVecSizeC != 0) {
          copyIndexD = 0;
          copyOffsetF = 0;
          do {
            copyIndexD = copyIndexD + 1;
            _memcpy(vecData + copyOffsetF,grownData + copyOffsetF,0x2c);
            copyOffsetF = copyOffsetF + 0x2c;
          } while (copyIndexD != newVecSizeC);
        }
        Arena__free(arenaAt378,grownData);
        bestCandidate = (int *)(vecData + bestOffset);
      }
      replacedInst = bestCandidate[1];
      newVecSizeC = vecSize;
      grownData = vecData;
      if ((vecSize <= bestIndex) && (newVecSizeC = bestIndex + 1, vecCapacity < newVecSizeC)) {
        vecCapacity = (vecCapacity << 4) / 10;
        if (vecCapacity < newVecSizeC) {
          vecCapacity = newVecSizeC;
        }
        grownData = Arena__alloc(arenaAt378,vecCapacity * 0x2c);
        if (vecSize != 0) {
          copyIndexD = 0;
          copyOffsetG = 0;
          do {
            copyIndexD = copyIndexD + 1;
            _memcpy(copyOffsetG + grownData,copyOffsetG + vecData,0x2c);
            copyOffsetG = copyOffsetG + 0x2c;
          } while (copyIndexD != vecSize);
        }
        Arena__free(arenaAt378,vecData);
        bestCandidate = (int *)(grownData + bestOffset);
      }
      if (bestCandidate[4] != 0) {
        vecSize = newVecSizeC;
        vecData = grownData;
        if ((newVecSizeC <= bestIndex) && (vecSize = bestIndex + 1, vecCapacity < vecSize)) {
          vecCapacity = (vecCapacity << 4) / 10;
          if (vecCapacity < vecSize) {
            vecCapacity = vecSize;
          }
          vecData = Arena__alloc(arenaAt378,vecCapacity * 0x2c);
          if (newVecSizeC != 0) {
            copyIndexD = 0;
            copyOffsetF = 0;
            do {
              copyIndexD = copyIndexD + 1;
              _memcpy(copyOffsetF + vecData,copyOffsetF + grownData,0x2c);
              copyOffsetF = copyOffsetF + 0x2c;
            } while (copyIndexD != newVecSizeC);
          }
          Arena__free(arenaAt378,grownData);
          bestCandidate = (int *)(vecData + bestOffset);
        }
        replacementInst = bestCandidate[1];
        newVecSizeC = vecSize;
        grownData = vecData;
        if ((vecSize <= bestIndex) && (newVecSizeC = bestIndex + 1, vecCapacity < newVecSizeC)) {
          vecCapacity = (vecCapacity << 4) / 10;
          if (vecCapacity < newVecSizeC) {
            vecCapacity = newVecSizeC;
          }
          grownData = Arena__alloc(arenaAt378,vecCapacity * 0x2c);
          if (vecSize != 0) {
            copyIndexD = 0;
            copyOffsetF = 0;
            do {
              copyIndexD = copyIndexD + 1;
              _memcpy(copyOffsetF + grownData,copyOffsetF + vecData,0x2c);
              copyOffsetF = copyOffsetF + 0x2c;
            } while (copyIndexD != vecSize);
          }
          Arena__free(arenaAt378,vecData);
          bestCandidate = (int *)(grownData + bestOffset);
        }
        replacedInst = *bestCandidate;
      }
      newVecSizeB = newVecSizeC;
      grownDataD = grownData;
      if ((newVecSizeC <= bestIndex) && (newVecSizeB = bestIndex + 1, vecCapacity < newVecSizeB)) {
        vecCapacity = (vecCapacity << 4) / 10;
        if (vecCapacity < newVecSizeB) {
          vecCapacity = newVecSizeB;
        }
        grownDataD = Arena__alloc(arenaAt378,vecCapacity * 0x2c);
        if (newVecSizeC != 0) {
          copyIndexB = 0;
          copyOffsetD = 0;
          do {
            copyIndexB = copyIndexB + 1;
            _memcpy(copyOffsetD + grownDataD,copyOffsetD + grownData,0x2c);
            copyOffsetD = copyOffsetD + 0x2c;
          } while (copyIndexB != newVecSizeC);
        }
        Arena__free(arenaAt378,grownData);
        bestCandidate = (int *)(grownDataD + bestOffset);
      }
      lastIndex = candidateCount - 1;
      vecSize = newVecSizeB;
      vecData = grownDataD;
      if ((newVecSizeB <= lastIndex) && (vecSize = candidateCount, vecCapacity < candidateCount)) {
        vecCapacity = (vecCapacity << 4) / 10;
        if (vecCapacity < candidateCount) {
          vecCapacity = candidateCount;
        }
        vecData = Arena__alloc(arenaAt378,vecCapacity * 0x2c);
        if (newVecSizeB != 0) {
          copyIndex = 0;
          copyOffsetC = 0;
          do {
            copyIndex = copyIndex + 1;
            _memcpy(copyOffsetC + vecData,copyOffsetC + grownDataD,0x2c);
            copyOffsetC = copyOffsetC + 0x2c;
          } while (copyIndex != newVecSizeB);
        }
        Arena__free(arenaAt378,grownDataD);
      }
      lastOffset = lastIndex * 0x2c;
      _memcpy(bestCandidate,lastOffset + vecData,0x2c);
      if ((int)lastIndex < 1) goto LAB_00146538;
      scanIndex = 0;
      nextPairIndex = 1;
      do {
        candidateCount = vecSize;
        grownData = vecData;
        if ((vecSize <= scanIndex) && (candidateCount = nextPairIndex, vecCapacity < nextPairIndex)) {
          vecCapacity = (vecCapacity << 4) / 10;
          if (vecCapacity < nextPairIndex) {
            vecCapacity = nextPairIndex;
          }
          grownData = Arena__alloc(arenaAt378,vecCapacity * 0x2c);
          if (vecSize != 0) {
            copyIndexG = 0;
            copyOffsetG = 0;
            do {
              copyIndexG = copyIndexG + 1;
              _memcpy(grownData + copyOffsetG,vecData + copyOffsetG,0x2c);
              copyOffsetG = copyOffsetG + 0x2c;
            } while (copyIndexG != vecSize);
          }
          Arena__free(arenaAt378,vecData);
        }
        candidateOffset = scanIndex * 0x2c;
        candidateRecord = grownData + candidateOffset;
        candInstA = *(int *)(grownData + candidateOffset);
        uVar20 = candidateCount;
        grownDataD = grownData;
        if ((candidateCount <= scanIndex) && (uVar20 = nextPairIndex, vecCapacity < nextPairIndex)) {
          vecCapacity = (vecCapacity << 4) / 10;
          if (vecCapacity < nextPairIndex) {
            vecCapacity = nextPairIndex;
          }
          grownDataD = Arena__alloc(arenaAt378,vecCapacity * 0x2c);
          if (candidateCount != 0) {
            copyIndexB = 0;
            copyOffsetD = 0;
            do {
              copyIndexB = copyIndexB + 1;
              _memcpy(grownDataD + copyOffsetD,grownData + copyOffsetD,0x2c);
              copyOffsetD = copyOffsetD + 0x2c;
            } while (copyIndexB != candidateCount);
          }
          Arena__free(arenaAt378,grownData);
          candidateRecord = grownDataD + candidateOffset;
        }
        if (replacedInst == candInstA) {
          candInstA = replacementInst;
        }
        iVar2 = *(int *)(candidateRecord + 4);
        if (replacedInst == *(int *)(candidateRecord + 4)) {
          iVar2 = replacementInst;
        }
        vecSize = uVar20;
        vecData = grownDataD;
        if (candInstA == iVar2) {
LAB_001463fc:
          lastScanIndex = scanIndex - 1;
          nextPairIndex = nextPairIndex - 1;
          uVar16 = vecSize;
          iVar2 = vecData;
          if ((vecSize <= scanIndex) && (uVar16 = scanIndex + 1, vecCapacity < uVar16)) {
            vecCapacity = (vecCapacity << 4) / 10;
            if (vecCapacity < uVar16) {
              vecCapacity = uVar16;
            }
            iVar2 = Arena__alloc(arenaAt378,vecCapacity * 0x2c);
            if (vecSize != 0) {
              copyIndex = 0;
              copyOffsetG = 0;
              do {
                copyIndex = copyIndex + 1;
                _memcpy(iVar2 + copyOffsetG,vecData + copyOffsetG,0x2c);
                copyOffsetG = copyOffsetG + 0x2c;
              } while (copyIndex != vecSize);
            }
            Arena__free(arenaAt378,vecData);
            candidateRecord = iVar2 + candidateOffset;
          }
          candidateCount = lastIndex - 1;
          lastOffset = lastOffset + -0x2c;
          vecSize = uVar16;
          vecData = iVar2;
          if ((uVar16 <= candidateCount) && (vecSize = lastIndex, vecCapacity < lastIndex)) {
            vecCapacity = (vecCapacity << 4) / 10;
            if (vecCapacity < lastIndex) {
              vecCapacity = lastIndex;
            }
            vecData = Arena__alloc(arenaAt378,vecCapacity * 0x2c);
            if (uVar16 != 0) {
              copyIndexC = 0;
              copyOffsetG = 0;
              do {
                copyIndexC = copyIndexC + 1;
                _memcpy(vecData + copyOffsetG,iVar2 + copyOffsetG,0x2c);
                copyOffsetG = copyOffsetG + 0x2c;
              } while (copyIndexC != uVar16);
            }
            Arena__free(arenaAt378,iVar2);
          }
          _memcpy(candidateRecord,lastOffset + vecData,0x2c);
        }
        else {
          if ((uVar20 <= scanIndex) && (vecSize = nextPairIndex, vecCapacity < nextPairIndex)) {
            vecCapacity = (vecCapacity << 4) / 10;
            if (vecCapacity < nextPairIndex) {
              vecCapacity = nextPairIndex;
            }
            vecData = Arena__alloc(arenaAt378,vecCapacity * 0x2c);
            if (uVar20 != 0) {
              copyIndex = 0;
              copyOffsetE = 0;
              do {
                copyIndex = copyIndex + 1;
                _memcpy(vecData + copyOffsetE,grownDataD + copyOffsetE,0x2c);
                copyOffsetE = copyOffsetE + 0x2c;
              } while (copyIndex != uVar20);
            }
            Arena__free(arenaAt378,grownDataD);
            candidateRecord = vecData + candidateOffset;
          }
          iVar2 = ((int (*)())PostPack__buildCandidate)(param_1,candInstA,iVar2,candidateRecord);
          candidateCount = lastIndex;
          lastScanIndex = scanIndex;
          if (iVar2 == 0) goto LAB_001463fc;
        }
        scanIndex = lastScanIndex + 1;
        nextPairIndex = nextPairIndex + 1;
        lastIndex = candidateCount;
      } while ((int)scanIndex < (int)candidateCount);
    } while( true );
  }
LAB_0014653c:
  Program__beginPass(iVar2,(int)"post_pack_insts");
  Arena__free(arenaAt378,vecData);
  return;
LAB_00146538:
  iVar2 = param_1[1];
  goto LAB_0014653c;
}

/* FUN_0014657c @ 0x14657c (92 bytes) */
int FUN_0014657c(param_1)
  int param_1;
{
  int local_38 [3];
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_38[0] = *(int *)(param_1 + 8);
  local_2c = *(undefined4 *)(local_38[0] + 0x378);
  local_28 = 0;
  local_24 = 0x10;
  local_20 = Arena__alloc(local_2c,0x2c0);
  ((int (*)())FUN_00140e5c)(local_38,param_1);
  ((int (*)())pass_post_pack_insts)(local_38);
  return Arena__free(local_2c,local_20);
}

/* IRInst__getOperandSourceOrDefault @ 0x146610 (20 bytes) */
int IRInst__getOperandSourceOrDefault(inst, operandIndex, param_3)
  int inst;
  undefined4 operandIndex;
  undefined4 param_3;
{
  undefined4 callResult;
  
  if (inst != 0) {
    callResult = IRInst__getOperandSource(inst,operandIndex);
    return callResult;
  }
  return param_3;
}

/* FUN_00146624 @ 0x146624 (76 bytes) */
int FUN_00146624(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  unsigned int ghidra_home[8] = { param_1, param_2, 0, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  char *pcVar1;
  char *pcVar2;
  int countdown;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 0)) = param_1;
  countdown = 4;
  (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = param_2;
  pcVar1 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 4));
  pcVar2 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 0));
  while ((*pcVar1 != '\x01' || (*pcVar2 == '\x04'))) {
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
    countdown = countdown + -1;
    if (countdown == 0) {
      return 1;
    }
  }
  return 0;
}

/* FUN_00146670 @ 0x146670 (132 bytes) */
int FUN_00146670(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int *param_2;
  int param_3;
  int param_4;
{
  code *UNRECOVERED_JUMPTABLE;
  int vcall5cResult;
  int *piVar2;
  undefined4 uVar3;
  
  vcall5cResult = (**(code **)(*param_2 + 0x5c))(param_2,param_2,param_3,param_4);
  if ((vcall5cResult == 0) && (param_3 == 0)) {
    piVar2 = *(int **)(param_4 + 0x30c);
    UNRECOVERED_JUMPTABLE = *(code **)(*piVar2 + 0x100);
  }
  else {
    piVar2 = *(int **)(param_4 + 0x30c);
    UNRECOVERED_JUMPTABLE = *(code **)(*piVar2 + 0x108);
  }
                    
                    
  uVar3 = (*UNRECOVERED_JUMPTABLE)(piVar2,param_1);
  return uVar3;
}

/* IRInst__getOperandSourceThroughMix @ 0x1466f4 (104 bytes) */
int IRInst__getOperandSourceThroughMix(inst, operandIndex)
  undefined4 inst;
  undefined4 operandIndex;
{
  int *operandVReg;
  int vcall60Result;
  
  operandVReg = (int *)IRInst__getOperandSource(inst,operandIndex);
  vcall60Result = (**(code **)(*operandVReg + 0x60))(operandVReg);
  if (vcall60Result != 0) {
    operandVReg = (int *)IRInst__getOperandSource(operandVReg,1);
    return operandVReg;
  }
  return operandVReg;
}

/* FUN_0014675c @ 0x14675c (44 bytes) */
int FUN_0014675c(param_1, param_2)
  int param_1;
  int param_2;
{
  if ((*(int *)(param_1 + 0x120) == *(int *)(param_2 + 0x120)) &&
     (*(int *)(param_1 + 0x124) == *(int *)(param_2 + 0x124))) {
    return 1;
  }
  return 0;
}

/* FUN_00146788 @ 0x146788 (96 bytes) */
int FUN_00146788(obj, program)
  int obj;
  undefined4 program;
{
  int callResult;
  undefined4 uVar2;
  
  callResult = IRInst__hasSingleUse(obj,program);
  if ((((callResult == 0) || (*(int *)(obj + 0x120) != 0)) || (*(int *)(obj + 0x124) != 0)) ||
     (uVar2 = 1, (*(uint *)(obj + 0x14) & 0x200) != 0)) {
    uVar2 = 0;
  }
  return uVar2;
}

/* FUN_001467e8 @ 0x1467e8 (128 bytes) */
int FUN_001467e8(param_1, param_2)
  int param_1;
  int param_2;
{
  int vcall24Result;
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  iVar1 = ((int (*)())IRInst__isOpcodeInSet139344)(param_1);
  if (iVar1 != 0) {
    piVar2 = *(int **)(param_2 + 0x3a0);
    for (piVar3 = *(int **)(param_1 + 0x158); piVar2 != piVar3; piVar3 = (int *)piVar3[0x3c]) {
      vcall24Result = (**(code **)(*piVar3 + 0x24))(piVar3);
      if (vcall24Result != 0) {
        return 0;
      }
    }
  }
  return 1;
}

/* FUN_00146868 @ 0x146868 (228 bytes) */
int FUN_00146868(param_1, param_2, param_3)
  int *param_1;
  int *param_2;
  undefined4 param_3;
{
  int vcall1cResult;
  int *piVar1;
  int vcall34Result;
  
  piVar1 = (int *)param_2[0x56];
  if (piVar1 == (int *)param_1[0x56]) {
    do {
      param_2 = (int *)param_2[1];
      vcall34Result = (**(code **)(*param_2 + 0x34))(param_2);
      if (vcall34Result != 0) {
        return 0;
      }
    } while (param_2 != param_1);
  }
  else {
    vcall1cResult = (**(code **)(*piVar1 + 0x1c))(piVar1);
    if (vcall1cResult != 0) {
      return 0;
    }
    FUN_000ec4f0(param_3);
    piVar1 = *(int **)(param_2[0x56] + 0xf0);
    if (piVar1 != (int *)param_1[0x56]) {
      do {
        vcall1cResult = (**(code **)(*piVar1 + 0x1c))(piVar1);
        if (vcall1cResult != 0) {
          return 0;
        }
        piVar1 = (int *)piVar1[0x3c];
      } while (piVar1 != (int *)param_1[0x56]);
    }
  }
  return 1;
}

