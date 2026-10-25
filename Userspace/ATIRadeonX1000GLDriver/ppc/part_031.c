#include "decls.h"

/* IRInst__createWithConstantOperands @ 0x10bed0 (320 bytes) */
int IRInst__createWithConstantOperands(int operandCount,undefined4 destSelect,undefined4 newSource,int program,undefined4 compiler,double value)
{
  undefined4 defaultSelect;
  int newInst;
  int operandRecord;
  double thirdConstant;
  
  *(int *)(program + 0x228) = *(int *)(program + 0x228) + 1;
  newInst = IRLoadConst__vslot73(0xa2,compiler);
  *(undefined4 *)(newInst + 0x98) = 0x36;
  *(undefined4 *)(newInst + 0x94) = *(undefined4 *)(newInst + 0x14c);
  *(undefined4 *)(newInst + 0x9c) = destSelect;
  *(int *)(newInst + 0x84) = operandCount;
  IRInst__setOperandSource(newInst,1,newSource,*(uint *)(program + 0x30) >> 7 & 1,compiler);
  defaultSelect = DAT_001af9fc;
  operandRecord = IRInst__getOperandRecord(newInst,1);
  *(undefined4 *)(operandRecord + 0x10) = defaultSelect;
  ((void (*)())IRInst__makeLiteralVec4Float)(newInst,program,2,value,value,value,value);
  operandRecord = IRInst__getOperandRecord(newInst,2);
  *(undefined4 *)(operandRecord + 0x10) = defaultSelect;
  if (operandCount == 3) {
    thirdConstant = (double)FLOAT_001aa0d4;
    if (value == thirdConstant) {
      thirdConstant = (double)FLOAT_001aa0e8;
    }
    ((void (*)())IRInst__makeLiteralVec4Float)(newInst,program,3,thirdConstant,thirdConstant,thirdConstant,thirdConstant);
    defaultSelect = DAT_001af9fc;
    operandRecord = IRInst__getOperandRecord(newInst,3);
    *(undefined4 *)(operandRecord + 0x10) = defaultSelect;
  }
  *(int *)(newInst + 0x160) = *(int *)(program + 0x478) + 1;
  return newInst;
}

/* IRInst__reduceTernaryToBinary @ 0x10c010 (600 bytes) */
int IRInst__reduceTernaryToBinary(inst, operandIndex, compiler)
  int *inst;
  int operandIndex;
  int compiler;
{
  int newOpcode;
  int useCount;
  bool invertFirstNegate;
  uint modifiers1;
  uint modifiers2;
  uint modifiers3;
  int oldOpcode;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 operandVReg;
  int operandRecord;
  undefined4 operandVReg2;
  undefined4 select2;
  undefined4 operandVReg3;
  undefined4 select3;
  int keptSource;
  undefined4 select1;
  int extraSource;
  int ownerBlock;
  int nextLink;
  int regKind;
  int regNumber;
  int destSelect;
  int outputClampFlag;
  int scaleExponentWord;
  int *operand1Record;
  
  extraSource = 0;
  operandVReg = IRInst__getOperandSource(inst,1);
  modifiers1 = inst[0x2e];
  operandRecord = IRInst__getOperandRecord(inst,1);
  select1 = *(undefined4 *)(operandRecord + 0x10);
  operandVReg2 = IRInst__getOperandSource(inst,2);
  modifiers2 = inst[0x34];
  operandRecord = IRInst__getOperandRecord(inst,2);
  select2 = *(undefined4 *)(operandRecord + 0x10);
  operandVReg3 = IRInst__getOperandSource(inst,3);
  modifiers3 = inst[0x3a];
  operandRecord = IRInst__getOperandRecord(inst,3);
  select3 = *(undefined4 *)(operandRecord + 0x10);
  nextLink = inst[1];
  ownerBlock = inst[0x56];
  regKind = inst[0x26];
  regNumber = inst[0x25];
  operandRecord = IRInst__getOperandRecord(inst,0);
  destSelect = *(int *)(operandRecord + 0x10);
  outputClampFlag = inst[0x48];
  scaleExponentWord = inst[0x49];
  useCount = IRInst__useCount(inst,*(undefined4 *)(compiler + 0x6c4));
  if ((inst[5] & 0x200U) != 0) {
    extraSource = IRInst__getOperandSource(inst,inst[0x21]);
  }
  keptSource = IRInst__getOperandSource(inst,operandIndex);
  DList__unlink(inst);
  oldOpcode = *(int *)(inst[0x22] + 8);
  if (oldOpcode == 0x25) {
    invertFirstNegate = operandIndex == 2;
    newOpcode = 0xb2 - (uint)(operandIndex == 3);
  }
  else if (oldOpcode == 0x26) {
    invertFirstNegate = operandIndex == 2;
    newOpcode = (operandIndex == 3) + 0xb1;
  }
  else if (oldOpcode == 0x24) {
    if (operandIndex == 3) {
      newOpcode = 0xb0;
      invertFirstNegate = false;
    }
    else {
      newOpcode = 0xb3;
      invertFirstNegate = false;
    }
  }
  else {
    newOpcode = 0;
    invertFirstNegate = false;
  }
  IRInst__reinitAsBinary(inst,newOpcode,compiler);
  inst[0x49] = scaleExponentWord;
  inst[0x25] = regNumber;
  inst[0x26] = regKind;
  inst[0x27] = destSelect;
  operand1Record = inst + 0x29;
  inst[0x48] = outputClampFlag;
  inst[0x58] = useCount + *(int *)(*(int *)(compiler + 0x6c4) + 0x478);
  Block__insertInstAfter(ownerBlock,nextLink,inst);
  IRInst__setOperandSource(inst,1,operandVReg,0,compiler);
  IROperand__setModifierBits(operand1Record,1,modifiers1 & 1);
  IROperand__setModifierBits(operand1Record,2,modifiers1 >> 1 & 1);
  operandRecord = IRInst__getOperandRecord(inst,1);
  *(undefined4 *)(operandRecord + 0x10) = select1;
  if (invertFirstNegate) {
    IROperand__setModifierBits(operand1Record,1,inst[0x2e] & 1U ^ 1);
  }
  if (operandIndex == 3) {
    IRInst__setOperandSource(inst,2,operandVReg2,0,compiler);
    IROperand__setModifierBits(inst + 0x2f,1,modifiers2 & 1);
    IROperand__setModifierBits(inst + 0x2f,2,modifiers2 >> 1 & 1);
    operandRecord = IRInst__getOperandRecord(inst,2);
    *(undefined4 *)(operandRecord + 0x10) = select2;
  }
  else {
    IRInst__setOperandSource(inst,2,operandVReg3,0,compiler);
    IROperand__setModifierBits(inst + 0x2f,1,modifiers3 & 1);
    IROperand__setModifierBits(inst + 0x2f,2,modifiers3 >> 1 & 1);
    operandRecord = IRInst__getOperandRecord(inst,2);
    *(undefined4 *)(operandRecord + 0x10) = select3;
  }
  if (extraSource == 0) {
    UNRECOVERED_JUMPTABLE = *(code **)(*inst + 0x94);
  }
  else {
    UNRECOVERED_JUMPTABLE = *(code **)(*inst + 0x94);
    keptSource = extraSource;
  }
                    
                    
  return (*UNRECOVERED_JUMPTABLE)(inst,keptSource,compiler);
}

/* IRInst__removeDefaultSelectOperands @ 0x10c37c (256 bytes) */
int IRInst__removeDefaultSelectOperands(inst, compilerCtx)
  int inst;
  undefined4 compilerCtx;
{
  int operandRecord;
  undefined4 operandVReg;
  int loopIndex;
  int operandCount;
  int shiftIndex;
  
  operandCount = *(int *)(inst + 0x84);
  if (0 < operandCount) {
    loopIndex = 1;
    do {
      operandRecord = IRInst__getOperandRecord(inst,loopIndex);
      shiftIndex = loopIndex;
      if (*(int *)(operandRecord + 0x10) == DAT_001af9fc) {
        do {
          if (shiftIndex < operandCount) {
            IRInst__copyOperandFrom(inst,shiftIndex,inst,shiftIndex + 1);
            operandVReg = IRInst__getOperandSource(inst,shiftIndex + 1);
            IRInst__setOperandSource(inst,shiftIndex,operandVReg,0,compilerCtx);
          }
          else {
            IRInst__initOperandRecord(inst,shiftIndex);
            IRInst__setOperandSource(inst,shiftIndex,0,0,compilerCtx);
          }
          shiftIndex = shiftIndex + 1;
        } while (shiftIndex <= operandCount);
        operandCount = operandCount + -1;
        *(int *)(inst + 0x84) = operandCount;
      }
      else {
        loopIndex = loopIndex + 1;
      }
    } while (loopIndex <= operandCount);
  }
  return;
}

/* FUN_0010c47c @ 0x10c47c (500 bytes) */
int FUN_0010c47c(inst, param_2)
  int *inst;
  int param_2;
{
  int operandRecord;
  bool bVar1;
  bool bVar2;
  int iVar3;
  int *a0;
  int iVar4;
  undefined4 uVar5;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar6;
  int operandVReg;
  uint uVar8;
  uint uVar9;
  undefined8 operandVReg2;
  undefined4 local_38 [8];
  
  (**(code **)(*inst + 0x60))(inst,param_2);
  operandVReg2 = IRInst__getOperandSource(inst,1);
  a0 = (int *)((ulonglong)operandVReg2 >> 0x20);
  iVar3 = *(int *)(a0[0x22] + 8);
  if (((((iVar3 - 0x16U < 2) || (iVar3 == 0x19)) || (iVar3 == 0x31)) ||
      (((iVar3 == 0x13 || (iVar3 == 0x14)) || (iVar3 == 0x12)))) &&
     (operandVReg = *(int *)(*(int *)(param_2 + 0x6c4) + 0x228),
     iVar3 = (**(code **)(*a0 + 0x14))
                       (a0,(int)operandVReg2,in_r5,in_r6,in_r7,in_r8,*(int *)(param_2 + 0x6c4)),
     operandVReg + iVar3 < *(int *)(param_2 + 0x664))) {
    bVar2 = true;
    if (1 < inst[0x21]) {
      iVar3 = 2;
      bVar2 = true;
      do {
        operandVReg = IRInst__getOperandSource(inst,iVar3);
        if (*(int *)(operandVReg + 0x98) == 0x33) {
          operandRecord = IRInst__getOperandRecord(inst,iVar3);
          iVar6 = 0;
          local_38[0] = *(undefined4 *)(operandRecord + 0x10);
          iVar4 = 4;
          do {
            if ((*(byte *)((int)local_38 + iVar6) != 4) &&
               (*(float *)((uint)*(byte *)((int)local_38 + iVar6) * 0x18 + operandVReg + 0x20) != 0.0)) {
              bVar2 = false;
              break;
            }
            iVar6 = iVar6 + 1;
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 <= inst[0x21]);
    }
    if ((a0[5] & 0x200U) != 0) {
      uVar9 = 0;
      do {
        iVar3 = IRInst__getOperandRecord(inst,1);
        uVar8 = (uint)*(byte *)(uVar9 + iVar3 + 0x10);
        if (((uVar8 != 4) && (iVar3 = IRInst__getOperandRecord(a0,0), *(char *)(uVar9 + iVar3 + 0x10) == '\x01')
            ) && (uVar8 != uVar9)) goto LAB_0010c648;
        bVar1 = uVar9 != 3;
        uVar9 = uVar9 + 1;
      } while (bVar1);
    }
    if ((!bVar2) && (iVar3 = IRInst__compareResultIsConstant(a0), iVar3 == 0)) {
      return 0;
    }
    uVar5 = 1;
  }
  else {
LAB_0010c648:
    uVar5 = 0;
  }
  return uVar5;
}

/* FUN_0010c670 @ 0x10c670 (1240 bytes) */
int FUN_0010c670(inst, inst2, param_3)
  int inst;
  int *inst2;
  int param_3;
{
  undefined4 sourceDef3;
  undefined8 sourceDef2;
  int operandRecord3;
  int operandRecord5;
  int operandRecord4;
  int sourceDef;
  int operandRecord2;
  int loopIndex2;
  int loopIndex;
  bool bVar1;
  int *a0;
  int iVar2;
  int *piVar3;
  int iVar4;
  int operandRecord;
  undefined4 uVar6;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  double dVar11;
  undefined8 uVar12;
  undefined4 local_48;
  int local_44 [6];
  
  a0 = (int *)IRInst__getOperandSource(inst,1);
  operandRecord2 = IRInst__getOperandRecord(inst,1);
  uVar6 = *(undefined4 *)(operandRecord2 + 0x10);
  uVar12 = IRInst__allSelectsAreHwConstants(a0,param_3,uVar6,in_r6,in_r7,in_r8,in_r9);
  if ((int)((ulonglong)uVar12 >> 0x20) == 0) {
    iVar8 = *(int *)(*(int *)(param_3 + 0x6c4) + 0x478);
    iVar2 = (**(code **)(*a0 + 0x5c))
                      (a0,(int)uVar12,uVar6,in_r6,in_r7,in_r8,*(int *)(param_3 + 0x6c4));
    if (iVar2 == 0) {
      if (iVar8 < a0[0x58]) {
        a0[0x58] = a0[0x58] + 1;
      }
      else {
        a0[0x58] = iVar8 + 1;
      }
    }
    else {
      iVar7 = iVar8 + 1;
      piVar3 = (int *)IRInst__clone(a0,param_3,0);
      piVar3[0x26] = 0x31;
      piVar3[0x25] = piVar3[0x53];
      Block__insertInstAfter(a0[0x56],a0,piVar3);
      piVar3[0x58] = iVar7;
      sourceDef = IRInst__getOperandSource(piVar3,1);
      if (iVar8 < *(int *)(sourceDef + 0x160)) {
        *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + 1;
      }
      else {
        *(int *)(sourceDef + 0x160) = iVar7;
      }
      a0 = piVar3;
      if (1 < piVar3[0x21]) {
        sourceDef = IRInst__getOperandSource(piVar3,2);
        if (iVar8 < *(int *)(sourceDef + 0x160)) {
          *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + 1;
        }
        else {
          *(int *)(sourceDef + 0x160) = iVar7;
        }
      }
    }
    IRInst__setOperandSource(inst2,1,a0,0,param_3);
    if ((*(uint *)(*(int *)(param_3 + 0x6c4) + 0x30) & 8) == 0) {
      IRInst__setOperandRef(inst2,1,*(undefined4 *)(inst + 0xa4));
    }
    else {
      IRInst__dropCounterAndDeleteIfUnused(inst,param_3);
    }
    iVar2 = 0;
    local_48 = 0x4040404;
    do {
      operandRecord3 = IRInst__getOperandRecord(inst2,1);
      uVar10 = (uint)*(byte *)(iVar2 + operandRecord3 + 0x10);
      if (uVar10 != 4) {
        operandRecord3 = IRInst__getOperandRecord(inst,1);
        if (*(char *)(uVar10 + operandRecord3 + 0x10) == '\x04') {
          if (1 < *(int *)(inst + 0x84)) {
            iVar8 = 2;
            do {
              operandRecord5 = IRInst__getOperandRecord(inst,iVar8);
              uVar9 = (uint)*(byte *)(uVar10 + operandRecord5 + 0x10);
              if (uVar9 != 4) {
                sourceDef2 = IRInst__getOperandSource(inst,iVar8);
                dVar11 = (double)*(float *)(uVar9 * 0x18 + (int)((ulonglong)sourceDef2 >> 0x20) + 0x20);
                uVar12 = ((int (*)())IRInst__findConstantOperandWithValue)(inst2,(int)sourceDef2,local_44,dVar11);
                iVar8 = local_44[0];
                iVar7 = (int)((ulonglong)uVar12 >> 0x20);
                if (iVar7 == 0) {
                  iVar8 = inst2[0x21];
                  ((void (*)())IRInst__setLiteralOperandAndSource)(inst2,(int)uVar12,iVar8 + 1,param_3,dVar11);
                  (**(code **)(*inst2 + 0x88))(inst2,iVar8 + 1,iVar2,iVar2);
                }
                else if (local_44[0] != iVar2) {
                  operandRecord4 = IRInst__getOperandRecord(inst2,iVar7);
                  (**(code **)(*inst2 + 0x88))
                            (inst2,iVar7,iVar2,*(undefined1 *)(iVar8 + operandRecord4 + 0x10));
                }
                break;
              }
              iVar8 = iVar8 + 1;
            } while (iVar8 <= *(int *)(inst + 0x84));
          }
        }
        else {
          operandRecord3 = IRInst__getOperandRecord(inst,1);
          *(undefined1 *)((int)local_44 + iVar2 + -4) = *(undefined1 *)(uVar10 + operandRecord3 + 0x10);
        }
      }
      uVar6 = local_48;
      bVar1 = iVar2 != 3;
      iVar2 = iVar2 + 1;
    } while (bVar1);
    operandRecord2 = IRInst__getOperandRecord(inst2,1);
    *(undefined4 *)(operandRecord2 + 0x10) = uVar6;
  }
  else {
    operandRecord2 = IRInst__getOperandRecord(inst2,1);
    iVar8 = inst2[0x21];
    local_48 = *(undefined4 *)(operandRecord2 + 0x10);
    if (1 < iVar8) {
      iVar7 = 2;
      loopIndex = 1;
      do {
        sourceDef3 = IRInst__getOperandSource(inst2,iVar7);
        IRInst__setOperandSource(inst2,loopIndex,sourceDef3,0,param_3);
        operandRecord4 = IRInst__getOperandRecord(inst2,iVar7);
        iVar4 = *(int *)(operandRecord4 + 0x10);
        if (loopIndex == 0) {
          inst2[0x27] = iVar4;
        }
        else {
          operandRecord = IRInst__getOperandRecord(inst2,loopIndex);
          *(int *)(operandRecord + 0x10) = iVar4;
        }
        iVar7 = iVar7 + 1;
        loopIndex = loopIndex + 1;
      } while (iVar7 <= iVar8);
    }
    inst2[0x21] = iVar8 + -1;
    iVar2 = 0;
    do {
      uVar10 = (uint)*(byte *)((int)local_44 + iVar2 + -4);
      if ((uVar10 != 4) && (0 < *(int *)(inst + 0x84))) {
        loopIndex2 = 1;
        do {
          operandRecord5 = IRInst__getOperandRecord(inst,loopIndex2);
          uVar9 = (uint)*(byte *)(uVar10 + operandRecord5 + 0x10);
          if (uVar9 != 4) {
            sourceDef2 = IRInst__getOperandSource(inst,loopIndex2);
            dVar11 = (double)*(float *)(uVar9 * 0x18 + (int)((ulonglong)sourceDef2 >> 0x20) + 0x20);
            uVar12 = ((int (*)())IRInst__findConstantOperandWithValue)(inst2,(int)sourceDef2,local_44,dVar11);
            iVar8 = local_44[0];
            iVar7 = (int)((ulonglong)uVar12 >> 0x20);
            if (iVar7 == 0) {
              iVar8 = inst2[0x21];
              ((void (*)())IRInst__setLiteralOperandAndSource)(inst2,(int)uVar12,iVar8 + 1,param_3,dVar11);
              (**(code **)(*inst2 + 0x88))(inst2,iVar8 + 1,iVar2,iVar2);
            }
            else if (local_44[0] != iVar2) {
              operandRecord4 = IRInst__getOperandRecord(inst2,iVar7);
              (**(code **)(*inst2 + 0x88))
                        (inst2,iVar7,iVar2,*(undefined1 *)(iVar8 + operandRecord4 + 0x10));
            }
            break;
          }
          loopIndex2 = loopIndex2 + 1;
        } while (loopIndex2 <= *(int *)(inst + 0x84));
      }
      bVar1 = iVar2 != 3;
      iVar2 = iVar2 + 1;
    } while (bVar1);
    IRInst__dropCounterAndDeleteIfUnused(inst,param_3);
  }
  return;
}

/* FUN_0010cb48 @ 0x10cb48 (1156 bytes) */
int FUN_0010cb48(inst, param_2)
  int inst;
  int param_2;
{
  undefined4 sourceDef;
  int operandRecord2;
  int operandRecord3;
  int operandRecord;
  int sourceDef2;
  bool bVar1;
  int iVar2;
  int *operandVReg;
  int iVar4;
  int *a0;
  int iVar5;
  int iVar6;
  undefined4 extraout_r4;
  undefined4 in_r8;
  undefined4 uVar7;
  undefined4 *puVar8;
  uint uVar9;
  int *piVar10;
  int iVar11;
  double fparam_1;
  undefined8 uVar12;
  int local_78;
  undefined4 local_74;
  undefined4 local_70;
  int local_6c;
  undefined4 local_68;
  int local_64 [2];
  undefined4 local_5c [5];
  float local_48 [4];
  
  operandVReg = (int *)IRInst__getOperandSource(inst,1);
  iVar2 = *(int *)(*(int *)(param_2 + 0x6c4) + 0x478);
  if (iVar2 < operandVReg[0x58]) {
    operandVReg[0x58] = operandVReg[0x58] + 1;
  }
  else {
    operandVReg[0x58] = iVar2 + 1;
  }
  operandRecord = IRInst__getOperandRecord(inst,1);
  local_70 = *(undefined4 *)(operandRecord + 0x10);
  operandRecord = IRInst__getOperandRecord(inst,0);
  local_78 = *(int *)(operandRecord + 0x10);
  operandRecord = IRInst__getOperandRecord(operandVReg,0);
  local_74 = *(undefined4 *)(operandRecord + 0x10);
  if ((operandVReg[5] & 0x200U) != 0) {
    iVar2 = 0;
    iVar11 = 4;
    do {
      if ((*(byte *)((int)&local_70 + iVar2) != 4) &&
         (*(char *)((int)&local_74 + (uint)*(byte *)((int)&local_70 + iVar2)) == '\x01')) {
        *(undefined1 *)((int)&local_78 + iVar2) = 1;
        *(undefined1 *)((int)&local_70 + iVar2) = 4;
      }
      iVar2 = iVar2 + 1;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
  }
  iVar2 = operandVReg[0x56];
  puVar8 = local_5c;
  for (iVar11 = 1; iVar5 = (**(code **)(*operandVReg + 0x14))(operandVReg), iVar11 <= iVar5;
      iVar11 = iVar11 + 1) {
    iVar6 = 0;
    *(int *)(*(int *)(param_2 + 0x6c4) + 0x228) = *(int *)(*(int *)(param_2 + 0x6c4) + 0x228) + 1;
    piVar10 = (int *)IRLoadConst__vslot73(0xa2,param_2);
    *puVar8 = piVar10;
    piVar10[0x26] = 0x36;
    piVar10[0x25] = piVar10[0x53];
    piVar10[0x21] = 1;
    piVar10[0x4b] = 1;
    sourceDef = IRInst__getOperandSource(operandVReg,iVar11);
    iVar5 = param_2;
    IRInst__setOperandSource(piVar10,1,sourceDef,0,param_2);
    piVar10[0x27] = local_78;
    operandRecord3 = IRInst__getOperandRecord(operandVReg,iVar11);
    local_68 = *(undefined4 *)(operandRecord3 + 0x10);
    do {
      uVar9 = (uint)*(byte *)((int)&local_70 + iVar6);
      if (uVar9 != 4) {
        (**(code **)(*piVar10 + 0x88))
                  (piVar10,1,iVar6,(uint)*(byte *)((int)local_64 + (uVar9 - 4)),iVar5,in_r8,
                   (int)&local_78 + uVar9);
      }
      bVar1 = iVar6 != 3;
      iVar6 = iVar6 + 1;
    } while (bVar1);
    Block__insertInstBefore(iVar2,operandVReg,piVar10);
    a0 = (int *)IRInst__getOperandSource(piVar10,1);
    iVar5 = (**(code **)(*a0 + 0x60))(a0);
    if (iVar5 != 0) {
      sourceDef = IRInst__getOperandSource(piVar10,1);
      ((int (*)())FUN_0010c670)(sourceDef,piVar10,param_2);
    }
    IRInst__setOperandSource(operandVReg,iVar11,piVar10,0,param_2);
    puVar8 = puVar8 + 1;
    piVar10[0x58] = *(int *)(*(int *)(param_2 + 0x6c4) + 0x478) + 1;
  }
  iVar2 = 0;
  do {
    if ((*(char *)((int)&local_78 + iVar2) != '\x01') &&
       (*(char *)((int)&local_70 + iVar2) == '\x04')) {
      if (1 < *(int *)(inst + 0x84)) {
        iVar11 = 2;
        do {
          iVar5 = IRInst__getOperandRecord(inst,iVar11);
          uVar9 = (uint)*(byte *)(iVar2 + iVar5 + 0x10);
          if (uVar9 != 4) {
            sourceDef2 = IRInst__getOperandSource(inst,iVar11);
            uVar7 = *(undefined4 *)(uVar9 * 0x18 + sourceDef2 + 0x20);
            goto LAB_0010ce20;
          }
          iVar11 = iVar11 + 1;
        } while (iVar11 <= *(int *)(inst + 0x84));
      }
      uVar7 = 0;
LAB_0010ce20:
      puVar8 = local_5c;
      for (iVar11 = 1; iVar5 = (**(code **)(*operandVReg + 0x14))(operandVReg), iVar11 <= iVar5;
          iVar11 = iVar11 + 1) {
        IRInst__foldCompareConstResult(local_48,operandVReg,iVar11,uVar7,param_2);
        fparam_1 = (double)local_48[0];
        piVar10 = (int *)*puVar8;
        uVar12 = ((int (*)())IRInst__findConstantOperandWithValue)(piVar10,extraout_r4,local_64,fparam_1);
        iVar5 = local_64[0];
        iVar4 = (int)((ulonglong)uVar12 >> 0x20);
        if (iVar4 == 0) {
          iVar5 = piVar10[0x21];
          ((void (*)())IRInst__setLiteralOperandAndSource)(piVar10,(int)uVar12,iVar5 + 1,param_2,fparam_1);
          (**(code **)(*piVar10 + 0x88))(piVar10,iVar5 + 1,iVar2,iVar2);
        }
        else {
          operandRecord2 = IRInst__getOperandRecord(piVar10,iVar4);
          (**(code **)(*piVar10 + 0x88))(piVar10,iVar4,iVar2,*(undefined1 *)(iVar5 + operandRecord2 + 0x10));
        }
        puVar8 = puVar8 + 1;
      }
    }
    bVar1 = iVar2 == 3;
    iVar2 = iVar2 + 1;
    if (bVar1) {
      iVar2 = 0;
      operandVReg[0x27] = local_78;
      local_6c = 0x10203;
      iVar11 = 4;
      do {
        if (*(char *)((int)&local_78 + iVar2) == '\x01') {
          *(undefined1 *)((int)&local_6c + iVar2) = 4;
        }
        iVar2 = iVar2 + 1;
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
      for (iVar2 = 1; iVar5 = (**(code **)(*operandVReg + 0x14))(operandVReg), iVar11 = local_6c,
          iVar2 <= iVar5; iVar2 = iVar2 + 1) {
        if (iVar2 == 0) {
          operandVReg[0x27] = local_6c;
        }
        else {
          iVar5 = IRInst__getOperandRecord(operandVReg,iVar2);
          *(int *)(iVar5 + 0x10) = iVar11;
        }
      }
      IRInst__dropCounterAndDeleteIfUnused(inst,param_2);
      return operandVReg;
    }
  } while( true );
}

/* IRInst__foldMovSourceSelect @ 0x10cfcc (400 bytes) */
int IRInst__foldMovSourceSelect(outSelect, inst, operandIndex, program)
  undefined4 *outSelect;
  undefined4 inst;
  undefined4 operandIndex;
  int program;
{
  int hasNoUsesResult;
  int isMovLike;
  undefined4 sourceDef;
  int operandRecord;
  int loopIndex;
  byte selectByte;
  int *a0;
  int iVar2;
  int srcRecord;
  undefined4 innerSelect;
  undefined4 trackUses;
  undefined4 compilerArg;
  undefined4 staleR8;
  undefined4 staleR9;
  undefined4 composedSelect [2];
  
  a0 = (int *)IRInst__getOperandSource(inst,operandIndex);
  isMovLike = (**(code **)(*a0 + 0x60))(a0);
  if (isMovLike != 0) {
    operandRecord = IRInst__getOperandRecord(inst,0);
    iVar2 = SelectWord__splatComponent(*(undefined4 *)(operandRecord + 0x10));
    srcRecord = IRInst__getOperandRecord(inst,operandIndex);
    selectByte = *(byte *)(iVar2 + srcRecord + 0x10);
    if (-1 < iVar2) {
      IRInst__getOperandRecord(a0,0);
    }
    for (loopIndex = 1; srcRecord = (**(code **)(*a0 + 0x14))(a0), loopIndex <= srcRecord; loopIndex = loopIndex + 1) {
      srcRecord = IRInst__getOperandRecord(a0,loopIndex);
      if (*(char *)((uint)selectByte + srcRecord + 0x10) != '\x04') {
        sourceDef = IRInst__getOperandSource(a0,loopIndex);
        compilerArg = *(undefined4 *)(program + 8);
        trackUses = 1;
        IRInst__setOperandSource(inst,operandIndex,sourceDef,1,compilerArg);
        hasNoUsesResult = IRInst__hasNoUses(a0,program,sourceDef,trackUses,compilerArg,staleR8,staleR9);
        if (hasNoUsesResult != 0) {
          (**(code **)(*a0 + 0xc))(a0,1,*(undefined4 *)(program + 8));
        }
        operandRecord = IRInst__getOperandRecord(a0,loopIndex);
        innerSelect = *(undefined4 *)(operandRecord + 0x10);
        operandRecord = IRInst__getOperandRecord(inst,operandIndex);
        SelectWord__compose(composedSelect,innerSelect,*(undefined4 *)(operandRecord + 0x10));
        *outSelect = composedSelect[0];
        return outSelect;
      }
    }
  }
  operandRecord = IRInst__getOperandRecord(inst,operandIndex);
  *outSelect = *(undefined4 *)(operandRecord + 0x10);
  return outSelect;
}

/* IRInst__replaceWithMovOfSource @ 0x10d15c (448 bytes) */
int IRInst__replaceWithMovOfSource(inst, operandIndex, trackUses, param_4)
  int *inst;
  int operandIndex;
  int trackUses;
  int param_4;
{
  int operandRecord3;
  int operandRecord2;
  uint operandModifiers;
  int useCount;
  int destSelect;
  undefined4 operandVReg;
  int operandRecord;
  undefined4 operandVReg2;
  int nextLink;
  int ownerBlock;
  int debugVector;
  undefined4 operandSelect;
  int outputClampFlag;
  int scaleExponentWord;
  int program;
  int otherIndex;
  undefined4 lastOperandRecord;
  int lastOperandSource;
  undefined4 lastOperandFlags;
  
  program = *(int *)(param_4 + 0x6c4);
  nextLink = inst[2];
  ownerBlock = inst[0x56];
  debugVector = inst[4];
  useCount = IRInst__useCount(inst,program);
  operandRecord3 = IRInst__getOperandRecord(inst,0);
  destSelect = *(int *)(operandRecord3 + 0x10);
  lastOperandFlags = 0;
  lastOperandRecord = 0;
  lastOperandSource = 0;
  outputClampFlag = inst[0x48];
  scaleExponentWord = inst[0x49];
  if ((inst[5] & 0x200U) != 0) {
    IRInst__readLastOperand(inst,&lastOperandRecord);
  }
  operandVReg = IRInst__getOperandSource(inst,operandIndex);
  operandModifiers = inst[operandIndex * 6 + 0x28];
  otherIndex = 1;
  operandRecord = IRInst__getOperandRecord(inst,operandIndex);
  operandSelect = *(undefined4 *)(operandRecord + 0x10);
  if (trackUses == 0) {
    for (; operandRecord = (**(code **)(*inst + 0x14))(inst), otherIndex <= operandRecord; otherIndex = otherIndex + 1) {
      if (otherIndex != operandIndex) {
        operandVReg2 = IRInst__getOperandSource(inst,otherIndex);
        IRInst__dropCounterAndDeleteIfUnused(operandVReg2,param_4);
      }
    }
    DList__unlink(inst);
  }
  else {
    (**(code **)(*inst + 0xc))(inst,1,param_4);
  }
  IRInst__reinitAsMov(inst,0x31,*(undefined4 *)(program + 8));
  inst[4] = debugVector;
  inst[0x58] = useCount + *(int *)(program + 0x478);
  inst[0x26] = 0;
  inst[0x25] = inst[0x53];
  inst[0x48] = outputClampFlag;
  inst[0x49] = scaleExponentWord;
  inst[0x27] = destSelect;
  IRInst__setOperandSource(inst,1,operandVReg,0,param_4);
  IROperand__setModifierBits(inst + 0x29,1,operandModifiers & 1);
  IROperand__setModifierBits(inst + 0x29,2,operandModifiers >> 1 & 1);
  operandRecord2 = IRInst__getOperandRecord(inst,1);
  *(undefined4 *)(operandRecord2 + 0x10) = operandSelect;
  if (lastOperandSource != 0) {
    IRInst__setLastOperandFromRecord(inst,&lastOperandRecord,trackUses,param_4);
  }
  return Block__insertInstBefore(ownerBlock,nextLink,inst);
}

/* IRInst__canonicalizeCommutativeOperands @ 0x10d358 (372 bytes) */
int IRInst__canonicalizeCommutativeOperands(inst, compiler)
  int inst;
  uint compiler;
{
  undefined4 src2Kind;
  int flagBit7Result;
  int uniformSourceConstant;
  int sourceDef;
  int operandRecord;
  int flagBit0Result;
  int uniformSourceConstant2;
  undefined4 destSelect;
  undefined4 src1Kind;
  undefined1 constantBuf1 [4];
  float constantValue1;
  undefined1 constantBuf2 [4];
  float constantValue2;
  
  flagBit0Result = OpcodeTraits__flagBit0(*(undefined4 *)(*(int *)(inst + 0x88) + 8),compiler);
  if (flagBit0Result != 0) {
    operandRecord = IRInst__getOperandRecord(inst,0);
    destSelect = *(undefined4 *)(operandRecord + 0x10);
    uniformSourceConstant = IRInst__getUniformSourceConstant(inst,1,destSelect,constantBuf1);
    uniformSourceConstant2 = IRInst__getUniformSourceConstant(inst,2,destSelect,constantBuf2);
    if (uniformSourceConstant == 0) {
      sourceDef = IRInst__getOperandSource(inst,1);
      src1Kind = *(undefined4 *)(sourceDef + 0x98);
      sourceDef = IRInst__getOperandSource(inst,2);
      src2Kind = *(undefined4 *)(sourceDef + 0x98);
      flagBit7Result = RegKind__flagBit7(src1Kind);
      if (flagBit7Result == 0) {
        return;
      }
      flagBit7Result = RegKind__flagBit7(src2Kind);
      if (flagBit7Result != 0) {
        return;
      }
    }
    else if (uniformSourceConstant2 != 0) {
      if ((((constantValue1 != 1.0) && (constantValue1 != -1.0)) && (constantValue1 != 2.0)) && (constantValue1 != -2.0)) {
        return;
      }
      if (constantValue2 == 1.0) {
        return;
      }
      if (constantValue2 == -1.0) {
        return;
      }
      if (constantValue2 == 2.0) {
        return;
      }
      if (constantValue2 == -2.0) {
        return;
      }
    }
    IRInst__swapOperands(inst,1,2,compiler);
  }
  return;
}

/* IRInst__convertCompareToBinaryAlu @ 0x10d4cc (280 bytes) */
int IRInst__convertCompareToBinaryAlu(inst, compiler)
  int inst;
  int compiler;
{
  int compareCondition;
  int operandRecord;
  uint negate1;
  uint negate2;
  undefined4 defaultSelect;
  undefined4 operandVReg;
  int iVar5;
  undefined4 operandVReg2;
  undefined4 newOpcode;
  undefined4 staleR5;
  undefined4 staleR6;
  undefined4 staleR7;
  undefined4 staleR8;
  undefined4 staleR9;
  undefined4 select2;
  uint abs2;
  undefined4 select1;
  uint abs1;
  undefined4 instId;
  int *block;
  undefined8 blockQuery;
  
  operandVReg = IRInst__getOperandSource(inst,1);
  negate1 = *(uint *)(inst + 0xb8) & 1;
  abs1 = *(uint *)(inst + 0xb8) >> 1 & 1;
  operandRecord = IRInst__getOperandRecord(inst,1);
  select1 = *(undefined4 *)(operandRecord + 0x10);
  operandVReg2 = IRInst__getOperandSource(inst,2);
  negate2 = *(uint *)(inst + 0xd0) & 1;
  abs2 = *(uint *)(inst + 0xd0) >> 1 & 1;
  operandRecord = IRInst__getOperandRecord(inst,2);
  defaultSelect = DAT_001af9dc;
  block = *(int **)(inst + 0x158);
  select2 = *(undefined4 *)(operandRecord + 0x10);
  instId = *(undefined4 *)(inst + 0x14c);
  blockQuery = (**(code **)(*block + 0x24))(block);
  if ((int)((ulonglong)blockQuery >> 0x20) != 0) {
    Block__getBranchInst(block,(int)blockQuery,staleR5,staleR6,staleR7,staleR8,staleR9);
    block[0x4c] = 0;
  }
  DList__unlink(inst);
  compareCondition = IRInst__getCompareCondition(inst);
  newOpcode = *(undefined4 *)(PTR_DAT_001e8c70 + compareCondition * 4);
  iVar5 = *(int *)(PTR_DAT_001e8c6c + compareCondition * 4);
  *(int *)(*(int *)(compiler + 0x6c4) + 0x21c) = *(int *)(*(int *)(compiler + 0x6c4) + 0x21c) + 1;
  IRInst__reinitAsBinary(inst,newOpcode,compiler);
  *(undefined4 *)(inst + 0x94) = instId;
  *(undefined4 *)(inst + 0x98) = 0;
  *(undefined4 *)(inst + 0x9c) = defaultSelect;
  if (iVar5 == 0) {
    IRInst__setOperandSource(inst,1,operandVReg,0,compiler);
    IROperand__setModifierBits(inst + 0xa4,1,negate1);
    IROperand__setModifierBits(inst + 0xa4,2,abs1);
    operandRecord = IRInst__getOperandRecord(inst,1);
    *(undefined4 *)(operandRecord + 0x10) = select1;
    IRInst__setOperandSource(inst,2,operandVReg2,0,compiler);
    IROperand__setModifierBits(inst + 0xbc,1,negate2);
    IROperand__setModifierBits(inst + 0xbc,2,abs2);
    operandRecord = IRInst__getOperandRecord(inst,2);
    *(undefined4 *)(operandRecord + 0x10) = select2;
  }
  else {
    IRInst__setOperandSource(inst,2,operandVReg,0,compiler);
    IROperand__setModifierBits(inst + 0xbc,1,negate1);
    IROperand__setModifierBits(inst + 0xbc,2,abs1);
    operandRecord = IRInst__getOperandRecord(inst,2);
    *(undefined4 *)(operandRecord + 0x10) = select1;
    IRInst__setOperandSource(inst,1,operandVReg2,0,compiler);
    IROperand__setModifierBits(inst + 0xa4,1,negate2);
    IROperand__setModifierBits(inst + 0xa4,2,abs2);
    operandRecord = IRInst__getOperandRecord(inst,1);
    *(undefined4 *)(operandRecord + 0x10) = select2;
  }
  return;
}

/* IRInst__foldConstantFactor @ 0x10d730 (636 bytes) */
int IRInst__foldConstantFactor(inst, newSource, newSelect, compiler)
  int inst;
  int *newSource;
  uint newSelect;
  int compiler;
{
  int operandRecord2;
  int useCount;
  uint negate1;
  uint negate2;
  undefined4 operandVReg;
  int operandRecord;
  undefined4 operandVReg2;
  int isConstant;
  undefined4 operandVReg3;
  undefined4 operandVReg4;
  undefined4 select2;
  undefined4 select1;
  uint abs2;
  uint abs1;
  undefined4 regKind;
  undefined4 destSelect;
  undefined4 regNumber;
  int program;
  
  operandVReg = IRInst__getOperandSource(inst,1);
  negate1 = *(uint *)(inst + 0xb8) & 1;
  abs1 = *(uint *)(inst + 0xb8) >> 1 & 1;
  operandRecord = IRInst__getOperandRecord(inst,1);
  select1 = *(undefined4 *)(operandRecord + 0x10);
  operandVReg2 = IRInst__getOperandSource(inst,2);
  negate2 = *(uint *)(inst + 0xd0) & 1;
  abs2 = *(uint *)(inst + 0xd0) >> 1 & 1;
  operandRecord = IRInst__getOperandRecord(inst,2);
  program = *(int *)(compiler + 0x6c4);
  select2 = *(undefined4 *)(operandRecord + 0x10);
  useCount = IRInst__useCount(inst,program);
  regKind = *(undefined4 *)(inst + 0x98);
  regNumber = *(undefined4 *)(inst + 0x94);
  operandRecord2 = IRInst__getOperandRecord(inst,0);
  destSelect = *(undefined4 *)(operandRecord2 + 0x10);
  DList__unlink(inst);
  isConstant = (**(code **)(*newSource + 0x48))(newSource);
  if ((isConstant != 0) && (((int)*(char *)(newSource + 0x57) >> (newSelect >> 0x18 & 0x3f) & 1U) != 0)) {
    operandVReg3 = IRInst__getOperandSource(inst,1);
    operandVReg4 = IRInst__getOperandSource(inst,2);
    *(int *)(program + 0x220) = *(int *)(program + 0x220) + 1;
    IRInst__reinitAsMov(inst,0x31,compiler);
    *(undefined4 *)(inst + 0x94) = regNumber;
    *(undefined4 *)(inst + 0x98) = regKind;
    *(undefined4 *)(inst + 0x9c) = destSelect;
    *(int *)(inst + 0x160) = useCount + *(int *)(program + 0x478);
    if (GH_U2F((unsigned int)(newSource[(newSelect >> 0x18) * 6 + 8])) == FLOAT_001aa0d4) {
      IRInst__setOperandSource(inst,1,operandVReg,0,compiler);
      IROperand__setModifierBits(inst + 0xa4,1,negate1);
      IROperand__setModifierBits(inst + 0xa4,2,abs1);
      operandRecord = IRInst__getOperandRecord(inst,1);
      *(undefined4 *)(operandRecord + 0x10) = select1;
      operandVReg3 = operandVReg4;
    }
    else {
      IRInst__setOperandSource(inst,1,operandVReg2,0,compiler);
      IROperand__setModifierBits(inst + 0xa4,1,negate2);
      IROperand__setModifierBits(inst + 0xa4,2,abs2);
      operandRecord = IRInst__getOperandRecord(inst,1);
      *(undefined4 *)(operandRecord + 0x10) = select2;
    }
    IRInst__dropCounterAndDeleteIfUnused(operandVReg3,compiler);
    return;
  }
  *(int *)(program + 0x224) = *(int *)(program + 0x224) + 1;
  IRInst__reinitAsTrinary(inst,0x24,compiler);
  *(undefined4 *)(inst + 0x94) = regNumber;
  *(undefined4 *)(inst + 0x98) = regKind;
  *(undefined4 *)(inst + 0x9c) = destSelect;
  *(int *)(inst + 0x160) = useCount + *(int *)(program + 0x478);
  IRInst__setOperandSource(inst,1,newSource,0,compiler);
  if (*(int *)(program + 0x478) < newSource[0x58]) {
    newSource[0x58] = newSource[0x58] + 1;
  }
  else {
    newSource[0x58] = *(int *)(program + 0x478) + 1;
  }
  operandRecord = IRInst__getOperandRecord(inst,1);
  *(uint *)(operandRecord + 0x10) = newSelect;
  IRInst__setOperandSource(inst,3,operandVReg,0,compiler);
  IROperand__setModifierBits(inst + 0xd4,1,negate1);
  IROperand__setModifierBits(inst + 0xd4,2,abs1);
  operandRecord = IRInst__getOperandRecord(inst,3);
  *(undefined4 *)(operandRecord + 0x10) = select1;
  IRInst__setOperandSource(inst,2,operandVReg2,0,compiler);
  IROperand__setModifierBits(inst + 0xbc,1,negate2);
  IROperand__setModifierBits(inst + 0xbc,2,abs2);
  operandRecord = IRInst__getOperandRecord(inst,2);
  *(undefined4 *)(operandRecord + 0x10) = select2;
  return;
}

/* HwLimits__vslot24_resetBindingTables @ 0x10da84 (84 bytes) */
int HwLimits__vslot24_resetBindingTables(this)
  int this;
{
  *(undefined4 *)(((unsigned char *)0x00001730) + this) = 0;
  *(undefined4 *)(((unsigned char *)0x0000172c) + this) = 0;
  *(undefined4 *)(((unsigned char *)0x00001728) + this) = 0;
  _memset(this + 0x68,0,0xd00);
  return _memset(this + 0xd68,0,0x9c0);
}

/* HwLimits__dtor_10dad8 @ 0x10dad8 (128 bytes) */
int HwLimits__dtor_10dad8(this)
  undefined4 *this;
{
  this[5] = 1;
  this[4] = 1;
  this[0x19] = 0;
  this[2] = 0;
  this[6] = 0;
  *this = &PTR_FUN_001ea5b0;
  this[9] = 0;
  this[10] = 0;
  this[0xb] = 0;
  this[0xc] = 0;
  this[0xd] = 0;
  this[0xe] = 0;
  this[0xf] = 0;
  this[0x10] = 0;
  this[0x11] = 0;
  this[0x12] = 0;
  this[0x13] = 0;
  this[0x14] = 0;
  this[0x15] = 0;
  this[0x16] = 0;
  this[0x17] = 0;
  this[0x18] = 0;
  return;
}

/* HwLimits__dtor_10db58 @ 0x10db58 (128 bytes) */
int HwLimits__dtor_10db58(this)
  undefined4 *this;
{
  this[5] = 1;
  this[4] = 1;
  this[0x19] = 0;
  this[2] = 0;
  this[6] = 0;
  *this = &PTR_FUN_001ea5b0;
  this[9] = 0;
  this[10] = 0;
  this[0xb] = 0;
  this[0xc] = 0;
  this[0xd] = 0;
  this[0xe] = 0;
  this[0xf] = 0;
  this[0x10] = 0;
  this[0x11] = 0;
  this[0x12] = 0;
  this[0x13] = 0;
  this[0x14] = 0;
  this[0x15] = 0;
  this[0x16] = 0;
  this[0x17] = 0;
  this[0x18] = 0;
  return;
}

/* BitSet__setBit @ 0x10dbd8 (36 bytes) */
int BitSet__setBit(bits, bitIndex)
  int bits;
  uint bitIndex;
{
  int byteAddr;
  
  byteAddr = ((int)bitIndex >> 3) + bits;
  ((unsigned char *)0x00001734)[byteAddr] = (byte)(1 << (bitIndex & 7)) | ((unsigned char *)0x00001734)[byteAddr];
  return;
}

/* BitSet__clearBit @ 0x10dbfc (36 bytes) */
int BitSet__clearBit(bits, bitIndex)
  int bits;
  uint bitIndex;
{
  int byteAddr;
  
  byteAddr = ((int)bitIndex >> 3) + bits;
  ((unsigned char *)0x00001734)[byteAddr] =
       ((byte)(-2 << (bitIndex & 7)) | (byte)(0xfffffffe >> 0x20 - (bitIndex & 7))) &
       ((unsigned char *)0x00001734)[byteAddr];
  return;
}

/* BitSet__initDefault @ 0x10dc20 (124 bytes) */
int BitSet__initDefault(bits)
  int bits;
{
  bool moreBits;
  int cursor;
  int remaining;
  
  remaining = 5;
  cursor = bits;
  do {
    ((unsigned char *)0x00001734)[cursor] = 0xff;
    cursor = cursor + 1;
    remaining = remaining + -1;
  } while (remaining != 0);
  remaining = 6;
  cursor = bits;
  do {
    ((unsigned char *)0x00001739)[cursor] = 0;
    cursor = cursor + 1;
    remaining = remaining + -1;
  } while (remaining != 0);
  cursor = 0x28;
  do {
    ((int (*)())BitSet__setBit)(bits,cursor);
    moreBits = cursor != 0x2c;
    cursor = cursor + 1;
  } while (moreBits);
  return;
}

/* BitSet__testBit @ 0x10dc9c (28 bytes) */
int BitSet__testBit(bits, bitIndex)
  int bits;
  uint bitIndex;
{
  return (int)(uint)(byte)((unsigned char *)0x00001734)[((int)bitIndex >> 3) + bits] >> (bitIndex & 7) & 1;
}

/* HwLimits__vslot77_getBindingLimitsDefault @ 0x10dcb8 (12 bytes) */
int HwLimits__vslot77_getBindingLimitsDefault(this, outLimits)
  undefined4 this;
  undefined4 *outLimits;
{
  *outLimits = 0;
  return;
}

/* HwLimits__vslot10_failNotSupported @ 0x10dcc4 (56 bytes) */
int HwLimits__vslot10_failNotSupported()
{
  
  if (*(int *)((*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)) + 0x6c4) != 0) {
    Compiler__fail((*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),0xf);
  }
  return 0;
}

/* HwLimits__vslot20_createInstWithOwner @ 0x10dd08 (68 bytes) */
int HwLimits__vslot20_createInstWithOwner(this, owner, compiler)
  undefined4 this;
  undefined4 owner;
  undefined4 compiler;
{
  int newInst;
  
  newInst = IRLoadVertex__new_109810(0xa4,compiler);
  *(undefined4 *)(newInst + 300) = owner;
  *(uint *)(newInst + 0x14) = *(uint *)(newInst + 0x14) & 0xffff7fff;
  return;
}

/* FUN_0010dd54 @ 0x10dd54 (120 bytes) */
int FUN_0010dd54(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0xc);
  *(undefined4 *)(iVar4 + 0xc78) = 0;
  *(undefined4 *)(iVar4 + 0x2a0) = 0;
  puVar3 = PTR_DAT_001e8c84;
  puVar2 = PTR_FUN_001e8c7c;
  puVar1 = PTR_DAT_001e8c78;
  *(undefined4 *)(iVar4 + 0xc60) = 0x4c;
  *(undefined **)(iVar4 + 0xd08) = puVar1;
  *(undefined **)(iVar4 + 0xc9c) = puVar3;
  *(undefined4 *)(iVar4 + 0xc70) = 4;
  *(undefined **)(iVar4 + 0xc74) = puVar2;
  *(undefined4 *)(iVar4 + 0x288) = 0x4d;
  *(undefined4 *)(iVar4 + 0x298) = 4;
  *(undefined **)(iVar4 + 0x29c) = puVar2;
  *(undefined **)(*(int *)(param_1 + 0xc) + 0xe28) = puVar3;
  return;
}

/* Compiler__getResourceModel @ 0x10ddcc (12 bytes) */
int Compiler__getResourceModel(compiler)
  int compiler;
{
  return *(undefined4 *)(*(int *)(compiler + 0x30c) + 0x60);
}

/* Compiler__getThreadModel @ 0x10ddd8 (12 bytes) */
int Compiler__getThreadModel(compiler)
  int compiler;
{
  return *(undefined4 *)(*(int *)(compiler + 0x30c) + 100);
}

/* FUN_0010dde4 @ 0x10dde4 (8 bytes) */
int FUN_0010dde4()
{
  return 0x10c;
}

/* KhanPs__vslot16_getConstant0xb5 @ 0x10ddec (8 bytes) */
int KhanPs__vslot16_getConstant0xb5()
{
  return 0xb5;
}

/* HwLimits__vslot8_failNotSupported @ 0x10ddfc (56 bytes) */
int HwLimits__vslot8_failNotSupported(this, unusedArg2, unusedArg3, unusedArg4, unusedArg5, unusedArg6, compiler)
  undefined4 this;
  undefined4 unusedArg2;
  undefined4 unusedArg3;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  int compiler;
{
  if (*(int *)(compiler + 0x6c4) != 0) {
    Compiler__fail(compiler,0xf);
  }
  return 0;
}

/* HwLimits__vslot9_failNotSupported @ 0x10de34 (56 bytes) */
int HwLimits__vslot9_failNotSupported()
{
  
  if (*(int *)((*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x3c)) + 0x6c4) != 0) {
    Compiler__fail((*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x3c)),0xf);
  }
  return 0;
}

/* FUN_0010de6c @ 0x10de6c (140 bytes) */
int FUN_0010de6c(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  uint *param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  uVar1 = *param_4;
  uVar5 = *(undefined4 *)(param_2 + 0x3ac);
  uVar4 = *(undefined4 *)(param_2 + 8);
  uVar2 = Program__registerFileOfIlType(param_2,*param_4 >> 0x10 & 0x3f);
  uVar2 = FUN_00127608(uVar5,uVar2,(int)(short)uVar1,0);
  iVar3 = IRLoadVertex__new_109810(0xa4,uVar4);
  IRInst__setOperandRef(iVar3,0,uVar2);
  *(int *)(iVar3 + 300) = (int)(short)uVar1;
  return Program__appendInst(param_2,iVar3,param_6);
}

/* FUN_0010defc @ 0x10defc (340 bytes) */
int FUN_0010defc(this, compiler)
  int this;
  int compiler;
{
  int entry;
  int firstEntry;
  undefined4 *shaderObject;
  
  entry = *(int *)(this + 4);
  firstEntry = 0;
  if (entry != 0) {
    shaderObject = *(undefined4 **)(entry + 0x60);
    if (shaderObject != (undefined4 *)0x0) {
      (**(code **)*shaderObject)(shaderObject);
      (**(code **)(compiler + 0x34c))(*(undefined4 *)(compiler + 0x354),shaderObject);
      entry = *(int *)(this + 4);
    }
    if (*(int *)(entry + 100) != 0) {
      /* issue #79 class: r4 = `lwz r4,0x64(r2)` (compared, then the release argument); the sibling in the
       * second block passes the same field */
      (**(code **)(compiler + 0x34c))(*(undefined4 *)(compiler + 0x354),*(int *)(entry + 100));
      entry = *(int *)(this + 4);
    }
    (**(code **)(compiler + 0x34c))(*(undefined4 *)(compiler + 0x354),entry);
    firstEntry = *(int *)(this + 4);
  }
  entry = *(int *)(this + 8);
  if ((firstEntry != entry) && (entry != 0)) {
    shaderObject = *(undefined4 **)(entry + 0x60);
    if (shaderObject != (undefined4 *)0x0) {
      (**(code **)*shaderObject)(shaderObject);
      (**(code **)(compiler + 0x34c))(*(undefined4 *)(compiler + 0x354),shaderObject);
      entry = *(int *)(this + 8);
    }
    if (*(int *)(entry + 100) != 0) {
      (**(code **)(compiler + 0x34c))(*(undefined4 *)(compiler + 0x354),*(int *)(entry + 100));
      entry = *(int *)(this + 8);
    }
    (**(code **)(compiler + 0x34c))(*(undefined4 *)(compiler + 0x354),entry);
  }
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 4) = 0;
  return;
}

/* KhanChip__ctor_10e050 @ 0x10e050 (172 bytes) */
int KhanChip__ctor_10e050(this, allocContext)
  undefined4 *this;
  undefined4 allocContext;
{
  undefined *vtable;
  int limitsObject;
  
  this[2] = 0;
  vtable = PTR_DAT_001e8c88;
  this[1] = 0;
  *this = vtable + 8;
  *this = PTR_DAT_001e8c74 + 8;
  limitsObject = Compiler__allocateOrFail(allocContext,0x1740);
  if (limitsObject != 0) {
    KhanVs__ctor_12a578(limitsObject,allocContext,1);
  }
  this[1] = limitsObject;
  limitsObject = Compiler__allocateOrFail(allocContext,0x1744);
  if (limitsObject != 0) {
    KhanPs__ctor_129130(limitsObject,allocContext,1);
  }
  this[2] = limitsObject;
  return;
}

/* KhanChip__ctor_10e114 @ 0x10e114 (172 bytes) */
int KhanChip__ctor_10e114(this, allocContext)
  undefined4 *this;
  undefined4 allocContext;
{
  undefined *vtable;
  int limitsObject;
  
  this[2] = 0;
  vtable = PTR_DAT_001e8c88;
  this[1] = 0;
  *this = vtable + 8;
  *this = PTR_DAT_001e8c74 + 8;
  limitsObject = Compiler__allocateOrFail(allocContext,0x1740);
  if (limitsObject != 0) {
    KhanVs__ctor_12a578(limitsObject,allocContext,1);
  }
  this[1] = limitsObject;
  limitsObject = Compiler__allocateOrFail(allocContext,0x1744);
  if (limitsObject != 0) {
    KhanPs__ctor_129130(limitsObject,allocContext,1);
  }
  this[2] = limitsObject;
  return;
}

/* FudoChip__ctor_10e1d8 @ 0x10e1d8 (176 bytes) */
int FudoChip__ctor_10e1d8(this, allocContext)
  undefined4 *this;
  undefined4 allocContext;
{
  undefined *vtable;
  int iVar2;
  undefined *puVar3;
  
  vtable = PTR_DAT_001e8c80;
  puVar3 = PTR_DAT_001e8c74 + 8;
  this[2] = 0;
  *this = puVar3;
  this[1] = 0;
  *this = vtable + 8;
  iVar2 = Compiler__allocateOrFail(allocContext,0x1740);
  if (iVar2 != 0) {
    FudoVs__ctor_12a8bc(iVar2,allocContext,1);
  }
  this[1] = iVar2;
  iVar2 = Compiler__allocateOrFail(allocContext,0x1944);
  if (iVar2 != 0) {
    FudoPs__ctor_1920e0(iVar2,allocContext,1);
  }
  this[2] = iVar2;
  return;
}

/* FudoChip__ctor_10e2a0 @ 0x10e2a0 (176 bytes) */
int FudoChip__ctor_10e2a0(this, allocContext)
  undefined4 *this;
  undefined4 allocContext;
{
  undefined *vtable;
  int iVar2;
  undefined *puVar3;
  
  vtable = PTR_DAT_001e8c80;
  puVar3 = PTR_DAT_001e8c74 + 8;
  this[2] = 0;
  *this = puVar3;
  this[1] = 0;
  *this = vtable + 8;
  iVar2 = Compiler__allocateOrFail(allocContext,0x1740);
  if (iVar2 != 0) {
    FudoVs__ctor_12a8bc(iVar2,allocContext,1);
  }
  this[1] = iVar2;
  iVar2 = Compiler__allocateOrFail(allocContext,0x1944);
  if (iVar2 != 0) {
    FudoPs__ctor_1920e0(iVar2,allocContext,1);
  }
  this[2] = iVar2;
  return;
}

/* FUN_0010e368 @ 0x10e368 (76 bytes) */
int FUN_0010e368(regKind)
  int regKind;
{
  int iVar1;
  int iVar2;
  
  iVar1 = 3;
  if (regKind != 0x18) {
    iVar2 = RegKind__vectorWidthKind(regKind);
    iVar1 = 1;
    if (iVar2 != 0x15) {
      iVar1 = (uint)(iVar2 == 0x16) << 1;
    }
  }
  return iVar1;
}

/* FUN_0010e3b4 @ 0x10e3b4 (88 bytes) */
int FUN_0010e3b4(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (0 < param_2) {
    iVar2 = 0;
    iVar3 = *(int *)(param_2 * 4 + param_1 + 4);
    if (iVar3 == *(int *)(param_1 + 4)) {
      return iVar2;
    }
    while( true ) {
      iVar2 = iVar2 + 1;
      param_2 = param_2 + -1;
      if (param_2 == 0) break;
      piVar1 = (int *)(param_1 + 8);
      param_1 = param_1 + 4;
      if (iVar3 == *piVar1) {
        return iVar2;
      }
    }
  }
  return -1;
}

/* FUN_0010e40c @ 0x10e40c (84 bytes) */
int FUN_0010e40c(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_1 != 0x16) {
    if (param_1 != 0x17) {
      return param_2;
    }
    if (param_2 == 0) {
      return 1;
    }
    if (param_2 != 1) {
      return param_2;
    }
    return 3;
  }
  if (param_2 == 0) {
    return param_2;
  }
  if (param_2 != 1) {
    return param_2;
  }
  return 2;
}

/* FUN_0010e460 @ 0x10e460 (140 bytes) */
int FUN_0010e460(param_1, param_2, param_3)
  int *param_1;
  int *param_2;
  int param_3;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  if ((*param_1 != *param_2) && (param_1[5] <= param_2[5])) {
    iVar2 = 0;
    do {
      if (param_1[1] == 0) {
        *(undefined4 *)(param_3 + iVar2) = 0xffffffff;
      }
      else {
        iVar5 = 4;
        iVar4 = 0;
        piVar3 = param_2;
        while (param_1[1] != piVar3[1]) {
          iVar4 = iVar4 + 1;
          piVar3 = piVar3 + 1;
          iVar5 = iVar5 + -1;
          if (iVar5 == 0) {
            return 0;
          }
        }
        *(int *)(iVar2 + param_3) = iVar4;
      }
      bVar1 = iVar2 != 0xc;
      param_1 = param_1 + 1;
      iVar2 = iVar2 + 4;
    } while (bVar1);
    return 1;
  }
  return 0;
}

/* FUN_0010e4ec @ 0x10e4ec (68 bytes) */
int FUN_0010e4ec(inst, inst2)
  undefined4 inst;
  undefined4 inst2;
{
  int countWrittenComponentsResult;
  int countWrittenComponentsResult2;
  
  countWrittenComponentsResult = IRInst__countWrittenComponents(inst);
  countWrittenComponentsResult2 = IRInst__countWrittenComponents(inst2);
  return countWrittenComponentsResult < countWrittenComponentsResult2;
}

/* FUN_0010e530 @ 0x10e530 (44 bytes) */
int FUN_0010e530(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_1 == 6) {
    return param_2 << 1;
  }
  if (param_1 != 7) {
    return param_2;
  }
  return param_2 * 2 + 1;
}

/* FUN_0010e55c @ 0x10e55c (16 bytes) */
int FUN_0010e55c(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 *param_4;
{
  *param_4 = 0;
  return 0;
}

/* FUN_0010e56c @ 0x10e56c (200 bytes) */
int FUN_0010e56c(param_1, program)
  int *param_1;
  int program;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(program + 0x3d4) == 0) {
    iVar3 = *(int *)(program + 0x3a0);
    iVar1 = (**(code **)(*param_1 + 0xe4))(param_1);
    iVar3 = *(int *)(iVar3 + 0x98);
    for (iVar2 = *(int *)(iVar3 + 8); iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
      if (((*(uint *)(iVar3 + 0x14) & 1) != 0) && (*(int *)(*(int *)(iVar3 + 0x88) + 8) == 0xa4)) {
        while (iVar2 = FUN_00130478(program,iVar1), iVar2 == 0) {
          iVar1 = iVar1 + 1;
        }
        Program__markHwRegUsed(program,iVar1);
        iVar2 = *(int *)(iVar3 + 8);
        *(int *)(iVar3 + 0x94) = iVar1;
        *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) | 0x40;
      }
      iVar3 = iVar2;
    }
  }
  return;
}

/* FUN_0010e634 @ 0x10e634 (92 bytes) */
int FUN_0010e634(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x68))(param_1);
  if ((iVar1 == 0) || (uVar2 = 1, param_1[0x4f] - 6U < 2)) {
    uVar2 = 0;
  }
  return uVar2;
}

/* FUN_0010e690 @ 0x10e690 (88 bytes) */
int FUN_0010e690(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x68))(param_1);
  if ((iVar1 == 0) || (uVar2 = 1, param_1[0x4f] != 0x18)) {
    uVar2 = 0;
  }
  return uVar2;
}

/* FUN_0010e6e8 @ 0x10e6e8 (92 bytes) */
int FUN_0010e6e8(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x68))(param_1);
  if ((iVar1 == 0) || (uVar2 = 1, 1 < param_1[0x4f] - 0x16U)) {
    uVar2 = 0;
  }
  return uVar2;
}

/* FUN_0010e744 @ 0x10e744 (116 bytes) */
int FUN_0010e744(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x68))(param_1);
  if ((iVar1 == 0) ||
     (((uint)param_1[0x4f] < 0x19 && ((1 << (param_1[0x4f] & 0x3fU) & 0x1c000c0U) != 0)))) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

/* FUN_0010e7b8 @ 0x10e7b8 (92 bytes) */
int FUN_0010e7b8(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  param_1[5] = 0;
  *param_1 = param_2;
  iVar1 = ((int (*)())FUN_0010e368)(*(undefined4 *)(param_2 + 0x13c));
  iVar2 = 4;
  param_1[6] = iVar1;
  do {
    param_1[1] = 0;
    param_1[7] = 0;
    param_1 = param_1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

/* FUN_0010e814 @ 0x10e814 (92 bytes) */
int FUN_0010e814(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  param_1[5] = 0;
  *param_1 = param_2;
  iVar1 = ((int (*)())FUN_0010e368)(*(undefined4 *)(param_2 + 0x13c));
  iVar2 = 4;
  param_1[6] = iVar1;
  do {
    param_1[1] = 0;
    param_1[7] = 0;
    param_1 = param_1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

/* FUN_0010e870 @ 0x10e870 (84 bytes) */
int FUN_0010e870(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_2;
  iVar1 = ((int (*)())FUN_0010e40c)(*(undefined4 *)(*param_1 + 0x13c),*(undefined4 *)(*param_1 + 0x140));
  iVar2 = ((int (*)())FUN_0010e40c)(*(undefined4 *)(iVar2 + 0x13c),*(undefined4 *)(iVar2 + 0x140));
  return iVar2 < iVar1;
}

/* FUN_0010e8c4 @ 0x10e8c4 (32 bytes) */
int FUN_0010e8c4(param_1, param_2)
  int *param_1;
  int *param_2;
{
  return *(int *)(*param_2 + 0x140) < *(int *)(*param_1 + 0x140);
}

/* FUN_0010e8e4 @ 0x10e8e4 (120 bytes) */
int FUN_0010e8e4(param_1, param_2)
  undefined4 *param_1;
  undefined4 *param_2;
{
  int operandRecord;
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar3 = 0;
  puVar4 = param_1;
  do {
    operandRecord = IRInst__getOperandRecord(*param_1,0);
    if (*(char *)(iVar3 + operandRecord + 0x10) != '\x01') {
      iVar2 = param_1[5];
      puVar4[1] = *param_2;
      param_1[5] = iVar2 + 1;
    }
    bVar1 = iVar3 != 3;
    param_2 = param_2 + 1;
    puVar4 = puVar4 + 1;
    iVar3 = iVar3 + 1;
  } while (bVar1);
  return;
}

/* FUN_0010e95c @ 0x10e95c (116 bytes) */
int FUN_0010e95c(param_1)
  undefined4 *param_1;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
  iVar3 = 0;
  iVar4 = 0;
  puVar5 = param_1;
  do {
    if ((puVar5[7] != 0) ||
       (iVar2 = IRInst__getOperandRecord(*param_1,0), *(char *)(iVar4 + iVar2 + 0x10) == '\0')) {
      iVar3 = iVar3 + 1;
    }
    bVar1 = iVar4 != 3;
    puVar5 = puVar5 + 1;
    iVar4 = iVar4 + 1;
  } while (bVar1);
  return iVar3;
}

/* FUN_0010e9d0 @ 0x10e9d0 (96 bytes) */
int FUN_0010e9d0(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  int iVar1;
  
  if ((param_1[param_2 + 7] == 0) &&
     (iVar1 = IRInst__getOperandRecord(*param_1,0), *(char *)(param_2 + iVar1 + 0x10) == '\x01')) {
    return 1;
  }
  return 0;
}

/* FUN_0010ea30 @ 0x10ea30 (164 bytes) */
int FUN_0010ea30(param_1)
  int param_1;
{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  int *piVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 8);
  uVar1 = *(uint *)(*(int *)(iVar3 + 0x6c4) + 0x30);
  if ((uVar1 & 1) == 0) {
    if ((uVar1 & 0x2000) == 0) {
      return;
    }
    piVar2 = *(int **)(iVar3 + 0x30c);
    UNRECOVERED_JUMPTABLE = *(code **)(*piVar2 + 0x15c);
  }
  else {
    (**(code **)(**(int **)(iVar3 + 0x30c) + 0x164))(*(int **)(iVar3 + 0x30c),param_1);
    piVar2 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
    UNRECOVERED_JUMPTABLE = *(code **)(*piVar2 + 0x160);
  }
                    
                    
  (*UNRECOVERED_JUMPTABLE)(piVar2,param_1);
  return;
}

/* FUN_0010ead4 @ 0x10ead4 (484 bytes) */
int FUN_0010ead4(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int local_a8 [16];
  int local_68 [18];
  
  piVar8 = *(int **)(*(int *)(param_2 + 0x3a8) + 0x98);
  piVar1 = (int *)piVar8[2];
  if (piVar1 == (int *)0x0) {
    piVar7 = (int *)0x0;
    iVar5 = 0;
    iVar6 = 0;
  }
  else {
    piVar7 = (int *)0x0;
    iVar5 = 0;
    iVar6 = 0;
    do {
      piVar2 = piVar1;
      if ((piVar8[5] & 1U) == 0) goto LAB_0010ebe4;
      iVar3 = (**(code **)(*piVar8 + 0x68))(piVar8);
      if (iVar3 == 0) {
LAB_0010ebe0:
        piVar2 = (int *)piVar8[2];
      }
      else {
        iVar3 = IRLoadInterp__laneKind_104ee4(piVar8,0);
        if (((iVar3 == 0xb) || (iVar3 = IRLoadInterp__laneKind_104ee4(piVar8,0), iVar3 == 0xc)) ||
           (iVar3 = IRLoadInterp__laneKind_104ee4(piVar8,0), iVar3 == 1)) {
          *(undefined4 *)(param_1 + 0x17c8) = 1;
        }
        iVar3 = piVar8[0x4f];
        if (iVar3 == 6) goto LAB_0010ebe0;
        if (iVar3 == 0x18) {
          piVar2 = (int *)piVar8[2];
          piVar7 = piVar8;
        }
        else {
          if (iVar3 == 7) goto LAB_0010ebe0;
          if (iVar3 - 0x16U < 2) {
            local_a8[iVar6] = (int)piVar8;
            iVar6 = iVar6 + 1;
            piVar2 = (int *)piVar8[2];
          }
          else {
            local_68[iVar5] = (int)piVar8;
            piVar2 = (int *)piVar8[2];
            iVar5 = iVar5 + 1;
          }
        }
      }
LAB_0010ebe4:
      piVar1 = (int *)piVar2[2];
      piVar8 = piVar2;
    } while ((int *)piVar2[2] != (int *)0x0);
  }
  if (*(int *)(param_2 + 0x3e4) != 0) {
    *(int *)(param_2 + 0x3f0) = -*(int *)(param_2 + 1000);
    if (0 < iVar6) {
      piVar1 = local_a8;
      do {
        iVar3 = *piVar1;
        piVar1 = piVar1 + 1;
        iVar4 = *(int *)(param_2 + 0x3f0);
        *(undefined4 *)(iVar3 + 0x98) = 5;
        *(int *)(iVar3 + 0x94) = *(int *)(iVar3 + 0x140) + iVar4;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    if (piVar7 != (int *)0x0) {
      iVar6 = *(int *)(param_2 + 0x3f0);
      piVar7[0x26] = 5;
      piVar7[0x25] = piVar7[0x50] + iVar6;
    }
    if (0 < iVar5) {
      piVar1 = local_68;
      do {
        iVar6 = *piVar1;
        piVar1 = piVar1 + 1;
        iVar3 = *(int *)(param_2 + 0x3f0);
        *(undefined4 *)(iVar6 + 0x98) = 5;
        *(int *)(iVar6 + 0x94) = *(int *)(iVar6 + 0x140) + iVar3;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
  }
  return;
}

/* FUN_0010ecb8 @ 0x10ecb8 (148 bytes) */
int FUN_0010ecb8(inst)
  undefined4 inst;
{
  int operandRecord;
  bool bVar1;
  int iVar2;
  int iVar3;
  int local_28 [9];
  
  operandRecord = IRInst__getOperandRecord(inst,0);
  local_28[0] = *(int *)(operandRecord + 0x10);
  if (*(int *)(operandRecord + 0x10) != DAT_001afa18) {
    bVar1 = false;
    iVar3 = 4;
    iVar2 = 0;
    do {
      if (*(char *)((int)local_28 + iVar2) == '\0') {
        if (bVar1) {
          return 1;
        }
      }
      else if (*(char *)((int)local_28 + iVar2) == '\x01') {
        bVar1 = true;
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return 0;
}

/* KhanPs__vslot87_assignInterpolatorBindings @ 0x10ed4c (540 bytes) */
int KhanPs__vslot87_assignInterpolatorBindings(this, program)
  int *this;
  int program;
{
  uint bindingFlags;
  int laneKind;
  int loadInst;
  int operandRecord;
  bool moreLanes;
  int isInterpLoad;
  int laneUsed;
  int laneIndex;
  int otherLaneInfo;
  undefined4 kindCode;
  int *nextLink;
  int *nextInst;
  uint remainingLanes;
  int interpolatorIndex;
  uint otherLane;
  uint laneGroup;
  code *appendBinding;
  uint loopIndex;
  int *inst;
  
  inst = *(int **)(*(int *)(program + 0x3a0) + 0x98);
  nextLink = (int *)inst[2];
  if (nextLink != (int *)0x0) {
    interpolatorIndex = 0;
    do {
      nextInst = nextLink;
      if ((inst[5] & 1U) != 0) {
        isInterpLoad = (**(code **)(*inst + 0x4c))(inst);
        if (isInterpLoad == 0) {
          nextInst = (int *)inst[2];
        }
        else {
          remainingLanes = 0xf;
          loopIndex = 0;
          loadInst = (**(code **)(*inst + 0x80))(inst);
          *(undefined4 *)(loadInst + 0x98) = 0;
          *(int *)(loadInst + 0x94) = interpolatorIndex;
          *(uint *)(loadInst + 0x14) = *(uint *)(loadInst + 0x14) | 0x40;
          Program__markHwRegUsed(program,interpolatorIndex);
          do {
            laneUsed = IRLoadInterp__laneUsed(loadInst,loopIndex);
            if ((laneUsed != 0) && (laneGroup = 1 << (loopIndex & 0x3f), (laneGroup & remainingLanes) != 0)) {
              laneKind = IRLoadInterp__laneKind(loadInst,loopIndex);
              otherLane = loopIndex + 1;
              laneIndex = IRLoadInterp__laneIndex(loadInst,loopIndex);
              if ((int)otherLane < 4) {
                do {
                  otherLaneInfo = IRLoadInterp__laneUsed(loadInst,otherLane);
                  if (((otherLaneInfo != 0) && (otherLaneInfo = IRLoadInterp__laneKind(loadInst,otherLane), otherLaneInfo == laneKind)) &&
                     (otherLaneInfo = IRLoadInterp__laneIndex(loadInst,otherLane), laneIndex == otherLaneInfo)) {
                    laneGroup = laneGroup | 1 << (otherLane & 0x3f);
                  }
                  moreLanes = otherLane != 3;
                  otherLane = otherLane + 1;
                } while (moreLanes);
              }
              if (laneGroup != 0) {
                remainingLanes = remainingLanes - laneGroup;
                appendBinding = *(code **)(*this + 0x54);
                kindCode = Table__interpolatorKindToCode(program,laneKind);
                operandRecord = IRInst__getOperandRecord(loadInst,1);
                bindingFlags = *(uint *)(loadInst + 0x13c);
                (*appendBinding)(this,interpolatorIndex,kindCode,laneIndex,*(undefined4 *)(operandRecord + 0x10),bindingFlags & 1,
                           bindingFlags >> 2 & 1,bindingFlags >> 1 & 1);
              }
            }
            loopIndex = loopIndex + 1;
          } while ((int)loopIndex < 4);
          nextInst = (int *)inst[2];
          interpolatorIndex = interpolatorIndex + 1;
        }
      }
      nextLink = (int *)nextInst[2];
      inst = nextInst;
    } while ((int *)nextInst[2] != (int *)0x0);
  }
  return;
}

/* FUN_0010ef68 @ 0x10ef68 (1052 bytes) */
int FUN_0010ef68(psBackend, program, param_3, param_4, param_5, param_6, param_7)
  int *psBackend;
  int program;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  int loadInst;
  int isInterpLoadB;
  int laneIndexValue;
  uint remainingLaneMask;
  uint nextFreeRegister;
  int laneUsedB;
  int laneKind;
  int operandRecord;
  bool moreLanes;
  int *nextInstLink;
  int *inst;
  int isInterpLoad;
  undefined4 interpolatorCode;
  int *cursorInst;
  undefined4 compiler;
  uint followingLane;
  uint laneGroupMask;
  uint assignedRegister;
  uint fixedRegister;
  int regLimitOrScratch;
  uint savedNextFreeRegister;
  int fixedRegBase;
  code *bindInterpolatorFn;
  int fixedStreamKey;
  uint loopIndex;
  int entryBlock;
  undefined1 laneSelects [20];
  
  entryBlock = *(int *)(program + 0x3a4);
  if (entryBlock == 0) {
    entryBlock = *(int *)(program + 0x3a0);
  }
  compiler = *(undefined4 *)(program + 8);
  fixedStreamKey = *(int *)(program + 0x3f4);
  fixedRegBase = *(int *)(program + 1000);
  regLimitOrScratch = *(int *)(program + 0x3ec);
  if (*(int *)(program + 0x3e4) != 0) {
    inst = *(int **)(entryBlock + 0x98);
    nextInstLink = (int *)inst[2];
    if ((int *)inst[2] == (int *)0x0) goto LAB_0010f084;
    do {
      cursorInst = nextInstLink;
      if ((inst[5] & 1U) != 0) {
        isInterpLoad = (**(code **)(*inst + 0x4c))(inst);
        if ((((isInterpLoad == 0) || (isInterpLoad = inst[0x52], fixedStreamKey != inst[0x51])) || (isInterpLoad < fixedRegBase))
           || (regLimitOrScratch <= isInterpLoad)) {
          cursorInst = (int *)inst[2];
        }
        else {
          fixedRegister = isInterpLoad - fixedRegBase;
          Program__markHwRegUsed(program,fixedRegister);
          FUN_00130bd4(program,fixedRegister);
          inst[0x25] = fixedRegister;
          inst[0x26] = 0;
          inst[5] = inst[5] | 0x40;
          if (*(int *)(program + 0x80) < (int)fixedRegister) {
            *(uint *)(program + 0x80) = fixedRegister;
          }
          *(uint *)(program + 0x88) = 1 << (fixedRegister & 0x3f) | *(uint *)(program + 0x88);
          cursorInst = (int *)inst[2];
        }
      }
      nextInstLink = (int *)cursorInst[2];
      inst = cursorInst;
    } while ((int *)cursorInst[2] != (int *)0x0);
  }
  inst = *(int **)(entryBlock + 0x98);
LAB_0010f084:
  if ((int *)inst[2] != (int *)0x0) {
    nextInstLink = (int *)inst[2];
    nextFreeRegister = 0;
    do {
      cursorInst = nextInstLink;
      savedNextFreeRegister = nextFreeRegister;
      if ((inst[5] & 1U) != 0) {
        isInterpLoadB = (**(code **)(*inst + 0x4c))(inst);
        if (isInterpLoadB != 0) {
          loadInst = (**(code **)(*inst + 0x80))(inst);
          if (((*(uint *)(loadInst + 0x14) & 0x40) == 0) || (*(int *)(loadInst + 0x98) != 0)) {
            for (; regLimitOrScratch = (**(code **)(*psBackend + 0x138))(psBackend,*(undefined4 *)(program + 8)),
                (int)nextFreeRegister < regLimitOrScratch; nextFreeRegister = nextFreeRegister + 1) {
              regLimitOrScratch = Program__isHwRegAllowed(program,nextFreeRegister);
              if ((regLimitOrScratch != 0) && (regLimitOrScratch = FUN_00130478(program,nextFreeRegister), regLimitOrScratch != 0)) {
                savedNextFreeRegister = nextFreeRegister + 1;
                assignedRegister = nextFreeRegister;
                goto LAB_0010f168;
              }
            }
            assignedRegister = 0xffffffff;
            savedNextFreeRegister = nextFreeRegister;
LAB_0010f168:
            Program__markHwRegUsed(program,assignedRegister);
            *(undefined4 *)(loadInst + 0x98) = 0;
            *(uint *)(loadInst + 0x94) = assignedRegister;
            if (*(int *)(program + 0x80) < (int)assignedRegister) {
              *(uint *)(program + 0x80) = assignedRegister;
            }
            *(uint *)(program + 0x88) = 1 << (assignedRegister & 0x3f) | *(uint *)(program + 0x88);
            *(uint *)(loadInst + 0x14) = *(uint *)(loadInst + 0x14) | 0x40;
          }
          else {
            assignedRegister = *(uint *)(loadInst + 0x94);
          }
          if (((int)assignedRegister < 0) ||
             (regLimitOrScratch = (**(code **)(*psBackend + 0x138))(psBackend,*(undefined4 *)(program + 8)),
             regLimitOrScratch <= (int)assignedRegister)) {
            Compiler__fail(compiler,4);
          }
          regLimitOrScratch = *(int *)(loadInst + 0x144);
          if ((regLimitOrScratch != 0x1b) && (regLimitOrScratch != 0x23)) {
            if (regLimitOrScratch == 0x24) {
              *(uint *)(loadInst + 0x148) = assignedRegister;
            }
            remainingLaneMask = 0xf;
            loopIndex = 0;
            do {
              regLimitOrScratch = IRLoadInterp__laneUsed(loadInst,loopIndex);
              if ((regLimitOrScratch != 0) && (laneGroupMask = 1 << (loopIndex & 0x3f), (laneGroupMask & remainingLaneMask) != 0)) {
                laneKind = IRLoadInterp__laneKind(loadInst,loopIndex);
                laneIndexValue = IRLoadInterp__laneIndex(loadInst,loopIndex);
                regLimitOrScratch = 1;
                if (laneKind != 7) {
                  regLimitOrScratch = laneIndexValue;
                }
                followingLane = loopIndex + 1;
                if ((int)followingLane < 4) {
                  do {
                    laneUsedB = IRLoadInterp__laneUsed(loadInst,followingLane);
                    if (((laneUsedB != 0) && (laneUsedB = IRLoadInterp__laneKind(loadInst,followingLane), laneUsedB == laneKind)) &&
                       (laneUsedB = IRLoadInterp__laneIndex(loadInst,followingLane), laneIndexValue == laneUsedB)) {
                      laneGroupMask = laneGroupMask | 1 << (followingLane & 0x3f);
                    }
                    moreLanes = followingLane != 3;
                    followingLane = followingLane + 1;
                  } while (moreLanes);
                }
                if (laneGroupMask != 0) {
                  IRLoadInterp__laneSelects(laneSelects,loadInst);
                  bindInterpolatorFn = *(code **)(*psBackend + 0x54);
                  remainingLaneMask = remainingLaneMask - laneGroupMask;
                  interpolatorCode = Table__interpolatorKindToCode(program,laneKind);
                  operandRecord = IRInst__getOperandRecord(loadInst,1);
                  laneGroupMask = *(uint *)(loadInst + 0x13c);
                  (*bindInterpolatorFn)(psBackend,assignedRegister,interpolatorCode,regLimitOrScratch,*(undefined4 *)(operandRecord + 0x10),laneGroupMask & 1,
                             laneGroupMask >> 2 & 1,laneGroupMask >> 1 & 1);
                }
              }
              loopIndex = loopIndex + 1;
            } while ((int)loopIndex < 4);
          }
        }
        cursorInst = (int *)inst[2];
      }
      nextInstLink = (int *)cursorInst[2];
      nextFreeRegister = savedNextFreeRegister;
      inst = cursorInst;
    } while ((int *)cursorInst[2] != (int *)0x0);
  }
  return;
}

/* FUN_0010f38c @ 0x10f38c (328 bytes) */
int FUN_0010f38c(param_1, vector)
  undefined4 *param_1;
  uint *vector;
{
  undefined4 *vectorElementRef;
  int operandRecord2;
  int operandRecord;
  bool bVar1;
  uint vectorCount;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *vectorElement;
  uint loopIndex;
  int *piVar10;
  
  vectorCount = vector[1];
  if (vectorCount != 0) {
    loopIndex = 0;
    do {
      if (loopIndex < *vector) {
        if (vectorCount <= loopIndex) {
          _memset(vectorCount * 4 + vector[2],0,(loopIndex - vectorCount) * 4 + 4);
          vector[1] = loopIndex + 1;
        }
        vectorElementRef = (undefined4 *)(loopIndex * 4 + vector[2]);
      }
      else {
        vectorElementRef = (undefined4 *)Vector__elementRefGrow(vector,loopIndex);
      }
      loopIndex = loopIndex + 1;
      vectorElement = (int *)*vectorElementRef;
      iVar7 = 0;
      puVar3 = param_1;
      do {
        operandRecord = IRInst__getOperandRecord(*param_1,0);
        if (*(char *)(iVar7 + operandRecord + 0x10) != '\x01') {
          iVar4 = 0;
          piVar10 = vectorElement;
          do {
            operandRecord2 = IRInst__getOperandRecord(*vectorElement,0);
            if ((*(char *)(iVar4 + operandRecord2 + 0x10) != '\x01') && (piVar10[1] == puVar3[1])) {
              iVar5 = vectorElement[5];
              iVar6 = *vectorElement;
              piVar10[1] = 0;
              vectorElement[5] = iVar5 + -1;
              *(undefined1 *)(iVar4 + iVar6 + 0x9c) = 1;
            }
            bVar1 = iVar4 != 3;
            piVar10 = piVar10 + 1;
            iVar4 = iVar4 + 1;
          } while (bVar1);
        }
        bVar1 = iVar7 != 3;
        puVar3 = puVar3 + 1;
        iVar7 = iVar7 + 1;
      } while (bVar1);
      vectorCount = vector[1];
    } while (loopIndex < vectorCount);
  }
  return;
}

/* FUN_0010f4d4 @ 0x10f4d4 (560 bytes) */
int FUN_0010f4d4(param_1)
  int param_1;
{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint *puVar4;
  undefined4 uVar5;
  uint loopIndex;
  
  puVar4 = *(uint **)(param_1 + 0x41c);
  uVar1 = puVar4[1];
  if (uVar1 != 0) {
    loopIndex = 0;
    do {
      if (loopIndex < *puVar4) {
        if (uVar1 <= loopIndex) {
          _memset(uVar1 * 4 + puVar4[2],0,(loopIndex - uVar1) * 4 + 4);
          puVar4[1] = loopIndex + 1;
        }
        puVar2 = (undefined4 *)(loopIndex * 4 + puVar4[2]);
      }
      else {
        puVar2 = (undefined4 *)Vector__elementRefGrow(puVar4,loopIndex);
      }
      uVar5 = *(undefined4 *)*puVar2;
      IRInst__getOperandRecord(uVar5,0);
      iVar3 = IRInst__operandKindClass(uVar5,0);
      if (iVar3 != 0) {
        return 1;
      }
      puVar4 = *(uint **)(param_1 + 0x41c);
      loopIndex = loopIndex + 1;
      uVar1 = puVar4[1];
    } while (loopIndex < uVar1);
  }
  puVar4 = *(uint **)(param_1 + 0x420);
  uVar1 = puVar4[1];
  if (uVar1 != 0) {
    loopIndex = 0;
    do {
      if (loopIndex < *puVar4) {
        if (uVar1 <= loopIndex) {
          _memset(uVar1 * 4 + puVar4[2],0,(loopIndex - uVar1) * 4 + 4);
          puVar4[1] = loopIndex + 1;
        }
        puVar2 = (undefined4 *)(loopIndex * 4 + puVar4[2]);
      }
      else {
        puVar2 = (undefined4 *)Vector__elementRefGrow(puVar4,loopIndex);
      }
      uVar5 = *(undefined4 *)*puVar2;
      IRInst__getOperandRecord(uVar5,0);
      iVar3 = IRInst__operandKindClass(uVar5,0);
      if (iVar3 != 0) {
        return 1;
      }
      puVar4 = *(uint **)(param_1 + 0x420);
      loopIndex = loopIndex + 1;
      uVar1 = puVar4[1];
    } while (loopIndex < uVar1);
  }
  puVar4 = *(uint **)(param_1 + 0x424);
  uVar1 = puVar4[1];
  if (uVar1 != 0) {
    loopIndex = 0;
    do {
      if (loopIndex < *puVar4) {
        if (uVar1 <= loopIndex) {
          _memset(uVar1 * 4 + puVar4[2],0,(loopIndex - uVar1) * 4 + 4);
          puVar4[1] = loopIndex + 1;
        }
        puVar2 = (undefined4 *)(loopIndex * 4 + puVar4[2]);
      }
      else {
        puVar2 = (undefined4 *)Vector__elementRefGrow(puVar4,loopIndex);
      }
      uVar5 = *(undefined4 *)*puVar2;
      IRInst__getOperandRecord(uVar5,0);
      iVar3 = IRInst__operandKindClass(uVar5,0);
      if (iVar3 != 0) {
        return 1;
      }
      puVar4 = *(uint **)(param_1 + 0x424);
      loopIndex = loopIndex + 1;
      uVar1 = puVar4[1];
    } while (loopIndex < uVar1);
  }
  return 0;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl FUN_0010da84");
asm(".set FUN_0010da84, _HwLimits__vslot24_resetBindingTables");
asm(".globl FUN_0010dcb8");
asm(".set FUN_0010dcb8, _HwLimits__vslot77_getBindingLimitsDefault");
asm(".globl FUN_0010dcc4");
asm(".set FUN_0010dcc4, _HwLimits__vslot10_failNotSupported");
asm(".globl FUN_0010dd08");
asm(".set FUN_0010dd08, _HwLimits__vslot20_createInstWithOwner");
asm(".globl FUN_0010ddec");
asm(".set FUN_0010ddec, _KhanPs__vslot16_getConstant0xb5");
asm(".globl FUN_0010ddfc");
asm(".set FUN_0010ddfc, _HwLimits__vslot8_failNotSupported");
asm(".globl FUN_0010de34");
asm(".set FUN_0010de34, _HwLimits__vslot9_failNotSupported");
asm(".globl FUN_0010de6c");
asm(".set FUN_0010de6c, _FUN_0010de6c");
asm(".globl FUN_0010ed4c");
asm(".set FUN_0010ed4c, _KhanPs__vslot87_assignInterpolatorBindings");
asm(".globl FUN_0010ef68");
asm(".set FUN_0010ef68, _FUN_0010ef68");
