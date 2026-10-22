#include "decls.h"

/* FUN_0010bed0 @ 0x10bed0 (320 bytes) */
int FUN_0010bed0(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,double fparam_1)
{
  undefined4 uVar1;
  int iVar2;
  int operandRecord;
  double fparam_1_00;
  
  *(int *)(param_4 + 0x228) = *(int *)(param_4 + 0x228) + 1;
  iVar2 = FUN_0010a240(0xa2,param_5);
  *(undefined4 *)(iVar2 + 0x98) = 0x36;
  *(undefined4 *)(iVar2 + 0x94) = *(undefined4 *)(iVar2 + 0x14c);
  *(undefined4 *)(iVar2 + 0x9c) = param_2;
  *(int *)(iVar2 + 0x84) = param_1;
  IRInst__setOperandSource(iVar2,1,param_3,*(uint *)(param_4 + 0x30) >> 7 & 1,param_5);
  uVar1 = DAT_001af9fc;
  operandRecord = IRInst__getOperandRecord(iVar2,1);
  *(undefined4 *)(operandRecord + 0x10) = uVar1;
  ((void (*)())FUN_000f79c4)(iVar2,param_4,2,fparam_1,fparam_1,fparam_1,fparam_1);
  operandRecord = IRInst__getOperandRecord(iVar2,2);
  *(undefined4 *)(operandRecord + 0x10) = uVar1;
  if (param_1 == 3) {
    fparam_1_00 = (double)FLOAT_001aa0d4;
    if (fparam_1 == fparam_1_00) {
      fparam_1_00 = (double)FLOAT_001aa0e8;
    }
    ((void (*)())FUN_000f79c4)(iVar2,param_4,3,fparam_1_00,fparam_1_00,fparam_1_00,fparam_1_00);
    uVar1 = DAT_001af9fc;
    operandRecord = IRInst__getOperandRecord(iVar2,3);
    *(undefined4 *)(operandRecord + 0x10) = uVar1;
  }
  *(int *)(iVar2 + 0x160) = *(int *)(param_4 + 0x478) + 1;
  return iVar2;
}

/* FUN_0010c010 @ 0x10c010 (600 bytes) */
int FUN_0010c010(inst, param_2, param_3)
  int *inst;
  int param_2;
  int param_3;
{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 operandVReg;
  int iVar7;
  undefined4 operandVReg2;
  undefined4 uVar9;
  undefined4 operandVReg3;
  undefined4 uVar11;
  int iVar12;
  undefined4 uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int *piVar22;
  
  iVar14 = 0;
  operandVReg = IRInst__getOperandSource(inst,1);
  uVar2 = inst[0x2e];
  iVar7 = IRInst__getOperandRecord(inst,1);
  uVar13 = *(undefined4 *)(iVar7 + 0x10);
  operandVReg2 = IRInst__getOperandSource(inst,2);
  uVar3 = inst[0x34];
  iVar7 = IRInst__getOperandRecord(inst,2);
  uVar9 = *(undefined4 *)(iVar7 + 0x10);
  operandVReg3 = IRInst__getOperandSource(inst,3);
  uVar4 = inst[0x3a];
  iVar7 = IRInst__getOperandRecord(inst,3);
  uVar11 = *(undefined4 *)(iVar7 + 0x10);
  iVar16 = inst[1];
  iVar15 = inst[0x56];
  iVar17 = inst[0x26];
  iVar18 = inst[0x25];
  iVar7 = IRInst__getOperandRecord(inst,0);
  iVar19 = *(int *)(iVar7 + 0x10);
  iVar20 = inst[0x48];
  iVar21 = inst[0x49];
  iVar7 = IRInst__useCount(inst,*(undefined4 *)(param_3 + 0x6c4));
  if ((inst[5] & 0x200U) != 0) {
    iVar14 = IRInst__getOperandSource(inst,inst[0x21]);
  }
  iVar12 = IRInst__getOperandSource(inst,param_2);
  DList__unlink(inst);
  iVar5 = *(int *)(inst[0x22] + 8);
  if (iVar5 == 0x25) {
    bVar1 = param_2 == 2;
    iVar5 = 0xb2 - (uint)(param_2 == 3);
  }
  else if (iVar5 == 0x26) {
    bVar1 = param_2 == 2;
    iVar5 = (param_2 == 3) + 0xb1;
  }
  else if (iVar5 == 0x24) {
    if (param_2 == 3) {
      iVar5 = 0xb0;
      bVar1 = false;
    }
    else {
      iVar5 = 0xb3;
      bVar1 = false;
    }
  }
  else {
    iVar5 = 0;
    bVar1 = false;
  }
  FUN_00108174(inst,iVar5,param_3);
  inst[0x49] = iVar21;
  inst[0x25] = iVar18;
  inst[0x26] = iVar17;
  inst[0x27] = iVar19;
  piVar22 = inst + 0x29;
  inst[0x48] = iVar20;
  inst[0x58] = iVar7 + *(int *)(*(int *)(param_3 + 0x6c4) + 0x478);
  Block__insertInstAfter(iVar15,iVar16,inst);
  IRInst__setOperandSource(inst,1,operandVReg,0,param_3);
  IROperand__setModifierBits(piVar22,1,uVar2 & 1);
  IROperand__setModifierBits(piVar22,2,uVar2 >> 1 & 1);
  iVar7 = IRInst__getOperandRecord(inst,1);
  *(undefined4 *)(iVar7 + 0x10) = uVar13;
  if (bVar1) {
    IROperand__setModifierBits(piVar22,1,inst[0x2e] & 1U ^ 1);
  }
  if (param_2 == 3) {
    IRInst__setOperandSource(inst,2,operandVReg2,0,param_3);
    IROperand__setModifierBits(inst + 0x2f,1,uVar3 & 1);
    IROperand__setModifierBits(inst + 0x2f,2,uVar3 >> 1 & 1);
    iVar7 = IRInst__getOperandRecord(inst,2);
    *(undefined4 *)(iVar7 + 0x10) = uVar9;
  }
  else {
    IRInst__setOperandSource(inst,2,operandVReg3,0,param_3);
    IROperand__setModifierBits(inst + 0x2f,1,uVar4 & 1);
    IROperand__setModifierBits(inst + 0x2f,2,uVar4 >> 1 & 1);
    iVar7 = IRInst__getOperandRecord(inst,2);
    *(undefined4 *)(iVar7 + 0x10) = uVar11;
  }
  if (iVar14 == 0) {
    UNRECOVERED_JUMPTABLE = *(code **)(*inst + 0x94);
  }
  else {
    UNRECOVERED_JUMPTABLE = *(code **)(*inst + 0x94);
    iVar12 = iVar14;
  }
                    
                    
  return (*UNRECOVERED_JUMPTABLE)(inst,iVar12,param_3);
}

/* FUN_0010c37c @ 0x10c37c (256 bytes) */
int FUN_0010c37c(inst, param_2)
  int inst;
  undefined4 param_2;
{
  int operandRecord;
  undefined4 operandVReg;
  int loopIndex;
  int iVar4;
  int iVar5;
  
  iVar4 = *(int *)(inst + 0x84);
  if (0 < iVar4) {
    loopIndex = 1;
    do {
      operandRecord = IRInst__getOperandRecord(inst,loopIndex);
      iVar5 = loopIndex;
      if (*(int *)(operandRecord + 0x10) == DAT_001af9fc) {
        do {
          if (iVar5 < iVar4) {
            FUN_00105e54(inst,iVar5,inst,iVar5 + 1);
            operandVReg = IRInst__getOperandSource(inst,iVar5 + 1);
            IRInst__setOperandSource(inst,iVar5,operandVReg,0,param_2);
          }
          else {
            FUN_00104be8(inst,iVar5);
            IRInst__setOperandSource(inst,iVar5,0,0,param_2);
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 <= iVar4);
        iVar4 = iVar4 + -1;
        *(int *)(inst + 0x84) = iVar4;
      }
      else {
        loopIndex = loopIndex + 1;
      }
    } while (loopIndex <= iVar4);
  }
  return;
}

/* FUN_0010c47c @ 0x10c47c (500 bytes) */
int FUN_0010c47c(inst, param_2)
  int *inst;
  int param_2;
{
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
          iVar4 = IRInst__getOperandRecord(inst,iVar3);
          iVar6 = 0;
          local_38[0] = *(undefined4 *)(iVar4 + 0x10);
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
    if ((!bVar2) && (iVar3 = FUN_0010bb14(a0), iVar3 == 0)) {
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
  iVar2 = IRInst__getOperandRecord(inst,1);
  uVar6 = *(undefined4 *)(iVar2 + 0x10);
  uVar12 = FUN_0010453c(a0,param_3,uVar6,in_r6,in_r7,in_r8,in_r9);
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
      iVar2 = IRInst__getOperandSource(piVar3,1);
      if (iVar8 < *(int *)(iVar2 + 0x160)) {
        *(int *)(iVar2 + 0x160) = *(int *)(iVar2 + 0x160) + 1;
      }
      else {
        *(int *)(iVar2 + 0x160) = iVar7;
      }
      a0 = piVar3;
      if (1 < piVar3[0x21]) {
        iVar2 = IRInst__getOperandSource(piVar3,2);
        if (iVar8 < *(int *)(iVar2 + 0x160)) {
          *(int *)(iVar2 + 0x160) = *(int *)(iVar2 + 0x160) + 1;
        }
        else {
          *(int *)(iVar2 + 0x160) = iVar7;
        }
      }
    }
    IRInst__setOperandSource(inst2,1,a0,0,param_3);
    if ((*(uint *)(*(int *)(param_3 + 0x6c4) + 0x30) & 8) == 0) {
      IRInst__setOperandRef(inst2,1,*(undefined4 *)(inst + 0xa4));
    }
    else {
      FUN_00105894(inst,param_3);
    }
    iVar2 = 0;
    local_48 = 0x4040404;
    do {
      iVar8 = IRInst__getOperandRecord(inst2,1);
      uVar10 = (uint)*(byte *)(iVar2 + iVar8 + 0x10);
      if (uVar10 != 4) {
        iVar8 = IRInst__getOperandRecord(inst,1);
        if (*(char *)(uVar10 + iVar8 + 0x10) == '\x04') {
          if (1 < *(int *)(inst + 0x84)) {
            iVar8 = 2;
            do {
              iVar7 = IRInst__getOperandRecord(inst,iVar8);
              uVar9 = (uint)*(byte *)(uVar10 + iVar7 + 0x10);
              if (uVar9 != 4) {
                uVar12 = IRInst__getOperandSource(inst,iVar8);
                dVar11 = (double)*(float *)(uVar9 * 0x18 + (int)((ulonglong)uVar12 >> 0x20) + 0x20);
                uVar12 = ((int (*)())FUN_0010b184)(inst2,(int)uVar12,local_44,dVar11);
                iVar8 = local_44[0];
                iVar7 = (int)((ulonglong)uVar12 >> 0x20);
                if (iVar7 == 0) {
                  iVar8 = inst2[0x21];
                  ((void (*)())FUN_0010bd50)(inst2,(int)uVar12,iVar8 + 1,param_3,dVar11);
                  (**(code **)(*inst2 + 0x88))(inst2,iVar8 + 1,iVar2,iVar2);
                }
                else if (local_44[0] != iVar2) {
                  iVar4 = IRInst__getOperandRecord(inst2,iVar7);
                  (**(code **)(*inst2 + 0x88))
                            (inst2,iVar7,iVar2,*(undefined1 *)(iVar8 + iVar4 + 0x10));
                }
                break;
              }
              iVar8 = iVar8 + 1;
            } while (iVar8 <= *(int *)(inst + 0x84));
          }
        }
        else {
          iVar8 = IRInst__getOperandRecord(inst,1);
          *(undefined1 *)((int)local_44 + iVar2 + -4) = *(undefined1 *)(uVar10 + iVar8 + 0x10);
        }
      }
      uVar6 = local_48;
      bVar1 = iVar2 != 3;
      iVar2 = iVar2 + 1;
    } while (bVar1);
    iVar2 = IRInst__getOperandRecord(inst2,1);
    *(undefined4 *)(iVar2 + 0x10) = uVar6;
  }
  else {
    iVar2 = IRInst__getOperandRecord(inst2,1);
    iVar8 = inst2[0x21];
    local_48 = *(undefined4 *)(iVar2 + 0x10);
    if (1 < iVar8) {
      iVar7 = 2;
      loopIndex = 1;
      do {
        uVar6 = IRInst__getOperandSource(inst2,iVar7);
        IRInst__setOperandSource(inst2,loopIndex,uVar6,0,param_3);
        iVar4 = IRInst__getOperandRecord(inst2,iVar7);
        iVar4 = *(int *)(iVar4 + 0x10);
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
          iVar7 = IRInst__getOperandRecord(inst,loopIndex2);
          uVar9 = (uint)*(byte *)(uVar10 + iVar7 + 0x10);
          if (uVar9 != 4) {
            uVar12 = IRInst__getOperandSource(inst,loopIndex2);
            dVar11 = (double)*(float *)(uVar9 * 0x18 + (int)((ulonglong)uVar12 >> 0x20) + 0x20);
            uVar12 = ((int (*)())FUN_0010b184)(inst2,(int)uVar12,local_44,dVar11);
            iVar8 = local_44[0];
            iVar7 = (int)((ulonglong)uVar12 >> 0x20);
            if (iVar7 == 0) {
              iVar8 = inst2[0x21];
              ((void (*)())FUN_0010bd50)(inst2,(int)uVar12,iVar8 + 1,param_3,dVar11);
              (**(code **)(*inst2 + 0x88))(inst2,iVar8 + 1,iVar2,iVar2);
            }
            else if (local_44[0] != iVar2) {
              iVar4 = IRInst__getOperandRecord(inst2,iVar7);
              (**(code **)(*inst2 + 0x88))
                        (inst2,iVar7,iVar2,*(undefined1 *)(iVar8 + iVar4 + 0x10));
            }
            break;
          }
          loopIndex2 = loopIndex2 + 1;
        } while (loopIndex2 <= *(int *)(inst + 0x84));
      }
      bVar1 = iVar2 != 3;
      iVar2 = iVar2 + 1;
    } while (bVar1);
    FUN_00105894(inst,param_3);
  }
  return;
}

/* FUN_0010cb48 @ 0x10cb48 (1156 bytes) */
int FUN_0010cb48(inst, param_2)
  int inst;
  int param_2;
{
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
  iVar2 = IRInst__getOperandRecord(inst,1);
  local_70 = *(undefined4 *)(iVar2 + 0x10);
  iVar2 = IRInst__getOperandRecord(inst,0);
  local_78 = *(int *)(iVar2 + 0x10);
  iVar2 = IRInst__getOperandRecord(operandVReg,0);
  local_74 = *(undefined4 *)(iVar2 + 0x10);
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
    piVar10 = (int *)FUN_0010a240(0xa2,param_2);
    *puVar8 = piVar10;
    piVar10[0x26] = 0x36;
    piVar10[0x25] = piVar10[0x53];
    piVar10[0x21] = 1;
    piVar10[0x4b] = 1;
    uVar7 = IRInst__getOperandSource(operandVReg,iVar11);
    iVar5 = param_2;
    IRInst__setOperandSource(piVar10,1,uVar7,0,param_2);
    piVar10[0x27] = local_78;
    iVar4 = IRInst__getOperandRecord(operandVReg,iVar11);
    local_68 = *(undefined4 *)(iVar4 + 0x10);
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
      uVar7 = IRInst__getOperandSource(piVar10,1);
      ((int (*)())FUN_0010c670)(uVar7,piVar10,param_2);
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
            iVar11 = IRInst__getOperandSource(inst,iVar11);
            uVar7 = *(undefined4 *)(uVar9 * 0x18 + iVar11 + 0x20);
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
        FUN_0010b93c(local_48,operandVReg,iVar11,uVar7,param_2);
        fparam_1 = (double)local_48[0];
        piVar10 = (int *)*puVar8;
        uVar12 = ((int (*)())FUN_0010b184)(piVar10,extraout_r4,local_64,fparam_1);
        iVar5 = local_64[0];
        iVar4 = (int)((ulonglong)uVar12 >> 0x20);
        if (iVar4 == 0) {
          iVar5 = piVar10[0x21];
          ((void (*)())FUN_0010bd50)(piVar10,(int)uVar12,iVar5 + 1,param_2,fparam_1);
          (**(code **)(*piVar10 + 0x88))(piVar10,iVar5 + 1,iVar2,iVar2);
        }
        else {
          iVar6 = IRInst__getOperandRecord(piVar10,iVar4);
          (**(code **)(*piVar10 + 0x88))(piVar10,iVar4,iVar2,*(undefined1 *)(iVar5 + iVar6 + 0x10));
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
      FUN_00105894(inst,param_2);
      return operandVReg;
    }
  } while( true );
}

/* FUN_0010cfcc @ 0x10cfcc (400 bytes) */
int FUN_0010cfcc(param_1, inst, param_3, param_4)
  undefined4 *param_1;
  undefined4 inst;
  undefined4 param_3;
  int param_4;
{
  int loopIndex;
  byte bVar1;
  int *a0;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined4 local_28 [2];
  
  a0 = (int *)IRInst__getOperandSource(inst,param_3);
  iVar2 = (**(code **)(*a0 + 0x60))(a0);
  if (iVar2 != 0) {
    iVar2 = IRInst__getOperandRecord(inst,0);
    iVar2 = FUN_000f37b8(*(undefined4 *)(iVar2 + 0x10));
    iVar3 = IRInst__getOperandRecord(inst,param_3);
    bVar1 = *(byte *)(iVar2 + iVar3 + 0x10);
    if (-1 < iVar2) {
      IRInst__getOperandRecord(a0,0);
    }
    for (loopIndex = 1; iVar3 = (**(code **)(*a0 + 0x14))(a0), loopIndex <= iVar3; loopIndex = loopIndex + 1) {
      iVar3 = IRInst__getOperandRecord(a0,loopIndex);
      if (*(char *)((uint)bVar1 + iVar3 + 0x10) != '\x04') {
        uVar4 = IRInst__getOperandSource(a0,loopIndex);
        uVar6 = *(undefined4 *)(param_4 + 8);
        uVar5 = 1;
        IRInst__setOperandSource(inst,param_3,uVar4,1,uVar6);
        iVar3 = FUN_001049c4(a0,param_4,uVar4,uVar5,uVar6,in_r8,in_r9);
        if (iVar3 != 0) {
          (**(code **)(*a0 + 0xc))(a0,1,*(undefined4 *)(param_4 + 8));
        }
        iVar2 = IRInst__getOperandRecord(a0,loopIndex);
        uVar4 = *(undefined4 *)(iVar2 + 0x10);
        iVar2 = IRInst__getOperandRecord(inst,param_3);
        FUN_000f2bdc(local_28,uVar4,*(undefined4 *)(iVar2 + 0x10));
        *param_1 = local_28[0];
        return param_1;
      }
    }
  }
  iVar2 = IRInst__getOperandRecord(inst,param_3);
  *param_1 = *(undefined4 *)(iVar2 + 0x10);
  return param_1;
}

/* FUN_0010d15c @ 0x10d15c (448 bytes) */
int FUN_0010d15c(inst, param_2, param_3, param_4)
  int *inst;
  int param_2;
  int param_3;
  int param_4;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 operandVReg;
  int operandRecord;
  undefined4 operandVReg2;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  undefined4 local_78;
  int local_74;
  undefined4 local_64;
  
  iVar13 = *(int *)(param_4 + 0x6c4);
  iVar7 = inst[2];
  iVar8 = inst[0x56];
  iVar9 = inst[4];
  iVar2 = IRInst__useCount(inst,iVar13);
  iVar3 = IRInst__getOperandRecord(inst,0);
  iVar3 = *(int *)(iVar3 + 0x10);
  local_64 = 0;
  local_78 = 0;
  local_74 = 0;
  iVar11 = inst[0x48];
  iVar12 = inst[0x49];
  if ((inst[5] & 0x200U) != 0) {
    FUN_00104d3c(inst,&local_78);
  }
  operandVReg = IRInst__getOperandSource(inst,param_2);
  uVar1 = inst[param_2 * 6 + 0x28];
  iVar14 = 1;
  operandRecord = IRInst__getOperandRecord(inst,param_2);
  uVar10 = *(undefined4 *)(operandRecord + 0x10);
  if (param_3 == 0) {
    for (; operandRecord = (**(code **)(*inst + 0x14))(inst), iVar14 <= operandRecord; iVar14 = iVar14 + 1) {
      if (iVar14 != param_2) {
        operandVReg2 = IRInst__getOperandSource(inst,iVar14);
        FUN_00105894(operandVReg2,param_4);
      }
    }
    DList__unlink(inst);
  }
  else {
    (**(code **)(*inst + 0xc))(inst,1,param_4);
  }
  FUN_00108448(inst,0x31,*(undefined4 *)(iVar13 + 8));
  inst[4] = iVar9;
  inst[0x58] = iVar2 + *(int *)(iVar13 + 0x478);
  inst[0x26] = 0;
  inst[0x25] = inst[0x53];
  inst[0x48] = iVar11;
  inst[0x49] = iVar12;
  inst[0x27] = iVar3;
  IRInst__setOperandSource(inst,1,operandVReg,0,param_4);
  IROperand__setModifierBits(inst + 0x29,1,uVar1 & 1);
  IROperand__setModifierBits(inst + 0x29,2,uVar1 >> 1 & 1);
  iVar2 = IRInst__getOperandRecord(inst,1);
  *(undefined4 *)(iVar2 + 0x10) = uVar10;
  if (local_74 != 0) {
    FUN_00106b48(inst,&local_78,param_3,param_4);
  }
  return Block__insertInstBefore(iVar8,iVar7,inst);
}

/* FUN_0010d358 @ 0x10d358 (372 bytes) */
int FUN_0010d358(inst, param_2)
  int inst;
  uint param_2;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 auStack_58 [4];
  float local_54;
  undefined1 auStack_40 [4];
  float local_3c;
  
  iVar1 = FUN_00112f78(*(undefined4 *)(*(int *)(inst + 0x88) + 8),param_2);
  if (iVar1 != 0) {
    iVar1 = IRInst__getOperandRecord(inst,0);
    uVar3 = *(undefined4 *)(iVar1 + 0x10);
    iVar1 = FUN_000f5cf0(inst,1,uVar3,auStack_58);
    iVar2 = FUN_000f5cf0(inst,2,uVar3,auStack_40);
    if (iVar1 == 0) {
      iVar1 = IRInst__getOperandSource(inst,1);
      uVar4 = *(undefined4 *)(iVar1 + 0x98);
      iVar1 = IRInst__getOperandSource(inst,2);
      uVar3 = *(undefined4 *)(iVar1 + 0x98);
      iVar1 = FUN_00126708(uVar4);
      if (iVar1 == 0) {
        return;
      }
      iVar1 = FUN_00126708(uVar3);
      if (iVar1 != 0) {
        return;
      }
    }
    else if (iVar2 != 0) {
      if ((((local_54 != 1.0) && (local_54 != -1.0)) && (local_54 != 2.0)) && (local_54 != -2.0)) {
        return;
      }
      if (local_3c == 1.0) {
        return;
      }
      if (local_3c == -1.0) {
        return;
      }
      if (local_3c == 2.0) {
        return;
      }
      if (local_3c == -2.0) {
        return;
      }
    }
    FUN_0010ac38(inst,1,2,param_2);
  }
  return;
}

/* FUN_0010d4cc @ 0x10d4cc (280 bytes) */
int FUN_0010d4cc(inst, param_2)
  int inst;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 operandVReg;
  int iVar5;
  undefined4 operandVReg2;
  undefined4 uVar7;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined4 uVar8;
  uint uVar9;
  undefined4 uVar10;
  uint uVar11;
  undefined4 uVar12;
  int *block;
  undefined8 uVar14;
  
  operandVReg = IRInst__getOperandSource(inst,1);
  uVar1 = *(uint *)(inst + 0xb8) & 1;
  uVar11 = *(uint *)(inst + 0xb8) >> 1 & 1;
  iVar5 = IRInst__getOperandRecord(inst,1);
  uVar10 = *(undefined4 *)(iVar5 + 0x10);
  operandVReg2 = IRInst__getOperandSource(inst,2);
  uVar2 = *(uint *)(inst + 0xd0) & 1;
  uVar9 = *(uint *)(inst + 0xd0) >> 1 & 1;
  iVar5 = IRInst__getOperandRecord(inst,2);
  uVar3 = DAT_001af9dc;
  block = *(int **)(inst + 0x158);
  uVar8 = *(undefined4 *)(iVar5 + 0x10);
  uVar12 = *(undefined4 *)(inst + 0x14c);
  uVar14 = (**(code **)(*block + 0x24))(block);
  if ((int)((ulonglong)uVar14 >> 0x20) != 0) {
    Block__getBranchInst(block,(int)uVar14,in_r5,in_r6,in_r7,in_r8,in_r9);
    block[0x4c] = 0;
  }
  DList__unlink(inst);
  iVar5 = IRInst__getCompareCondition(inst);
  uVar7 = *(undefined4 *)(PTR_DAT_001e8c70 + iVar5 * 4);
  iVar5 = *(int *)(PTR_DAT_001e8c6c + iVar5 * 4);
  *(int *)(*(int *)(param_2 + 0x6c4) + 0x21c) = *(int *)(*(int *)(param_2 + 0x6c4) + 0x21c) + 1;
  FUN_00108174(inst,uVar7,param_2);
  *(undefined4 *)(inst + 0x94) = uVar12;
  *(undefined4 *)(inst + 0x98) = 0;
  *(undefined4 *)(inst + 0x9c) = uVar3;
  if (iVar5 == 0) {
    IRInst__setOperandSource(inst,1,operandVReg,0,param_2);
    IROperand__setModifierBits(inst + 0xa4,1,uVar1);
    IROperand__setModifierBits(inst + 0xa4,2,uVar11);
    iVar5 = IRInst__getOperandRecord(inst,1);
    *(undefined4 *)(iVar5 + 0x10) = uVar10;
    IRInst__setOperandSource(inst,2,operandVReg2,0,param_2);
    IROperand__setModifierBits(inst + 0xbc,1,uVar2);
    IROperand__setModifierBits(inst + 0xbc,2,uVar9);
    iVar5 = IRInst__getOperandRecord(inst,2);
    *(undefined4 *)(iVar5 + 0x10) = uVar8;
  }
  else {
    IRInst__setOperandSource(inst,2,operandVReg,0,param_2);
    IROperand__setModifierBits(inst + 0xbc,1,uVar1);
    IROperand__setModifierBits(inst + 0xbc,2,uVar11);
    iVar5 = IRInst__getOperandRecord(inst,2);
    *(undefined4 *)(iVar5 + 0x10) = uVar10;
    IRInst__setOperandSource(inst,1,operandVReg2,0,param_2);
    IROperand__setModifierBits(inst + 0xa4,1,uVar2);
    IROperand__setModifierBits(inst + 0xa4,2,uVar9);
    iVar5 = IRInst__getOperandRecord(inst,1);
    *(undefined4 *)(iVar5 + 0x10) = uVar8;
  }
  return;
}

/* FUN_0010d730 @ 0x10d730 (636 bytes) */
int FUN_0010d730(inst, param_2, param_3, param_4)
  int inst;
  int *param_2;
  uint param_3;
  int param_4;
{
  uint uVar1;
  uint uVar2;
  undefined4 operandVReg;
  int iVar4;
  undefined4 operandVReg2;
  int iVar6;
  undefined4 operandVReg3;
  undefined4 operandVReg4;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uVar11;
  uint uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  int iVar16;
  
  operandVReg = IRInst__getOperandSource(inst,1);
  uVar1 = *(uint *)(inst + 0xb8) & 1;
  uVar12 = *(uint *)(inst + 0xb8) >> 1 & 1;
  iVar4 = IRInst__getOperandRecord(inst,1);
  uVar10 = *(undefined4 *)(iVar4 + 0x10);
  operandVReg2 = IRInst__getOperandSource(inst,2);
  uVar2 = *(uint *)(inst + 0xd0) & 1;
  uVar11 = *(uint *)(inst + 0xd0) >> 1 & 1;
  iVar4 = IRInst__getOperandRecord(inst,2);
  iVar16 = *(int *)(param_4 + 0x6c4);
  uVar9 = *(undefined4 *)(iVar4 + 0x10);
  iVar4 = IRInst__useCount(inst,iVar16);
  uVar13 = *(undefined4 *)(inst + 0x98);
  uVar15 = *(undefined4 *)(inst + 0x94);
  iVar6 = IRInst__getOperandRecord(inst,0);
  uVar14 = *(undefined4 *)(iVar6 + 0x10);
  DList__unlink(inst);
  iVar6 = (**(code **)(*param_2 + 0x48))(param_2);
  if ((iVar6 != 0) && (((int)*(char *)(param_2 + 0x57) >> (param_3 >> 0x18 & 0x3f) & 1U) != 0)) {
    operandVReg3 = IRInst__getOperandSource(inst,1);
    operandVReg4 = IRInst__getOperandSource(inst,2);
    *(int *)(iVar16 + 0x220) = *(int *)(iVar16 + 0x220) + 1;
    FUN_00108448(inst,0x31,param_4);
    *(undefined4 *)(inst + 0x94) = uVar15;
    *(undefined4 *)(inst + 0x98) = uVar13;
    *(undefined4 *)(inst + 0x9c) = uVar14;
    *(int *)(inst + 0x160) = iVar4 + *(int *)(iVar16 + 0x478);
    if (GH_U2F((unsigned int)(param_2[(param_3 >> 0x18) * 6 + 8])) == FLOAT_001aa0d4) {
      IRInst__setOperandSource(inst,1,operandVReg,0,param_4);
      IROperand__setModifierBits(inst + 0xa4,1,uVar1);
      IROperand__setModifierBits(inst + 0xa4,2,uVar12);
      iVar4 = IRInst__getOperandRecord(inst,1);
      *(undefined4 *)(iVar4 + 0x10) = uVar10;
      operandVReg3 = operandVReg4;
    }
    else {
      IRInst__setOperandSource(inst,1,operandVReg2,0,param_4);
      IROperand__setModifierBits(inst + 0xa4,1,uVar2);
      IROperand__setModifierBits(inst + 0xa4,2,uVar11);
      iVar4 = IRInst__getOperandRecord(inst,1);
      *(undefined4 *)(iVar4 + 0x10) = uVar9;
    }
    FUN_00105894(operandVReg3,param_4);
    return;
  }
  *(int *)(iVar16 + 0x224) = *(int *)(iVar16 + 0x224) + 1;
  FUN_00108304(inst,0x24,param_4);
  *(undefined4 *)(inst + 0x94) = uVar15;
  *(undefined4 *)(inst + 0x98) = uVar13;
  *(undefined4 *)(inst + 0x9c) = uVar14;
  *(int *)(inst + 0x160) = iVar4 + *(int *)(iVar16 + 0x478);
  IRInst__setOperandSource(inst,1,param_2,0,param_4);
  if (*(int *)(iVar16 + 0x478) < param_2[0x58]) {
    param_2[0x58] = param_2[0x58] + 1;
  }
  else {
    param_2[0x58] = *(int *)(iVar16 + 0x478) + 1;
  }
  iVar4 = IRInst__getOperandRecord(inst,1);
  *(uint *)(iVar4 + 0x10) = param_3;
  IRInst__setOperandSource(inst,3,operandVReg,0,param_4);
  IROperand__setModifierBits(inst + 0xd4,1,uVar1);
  IROperand__setModifierBits(inst + 0xd4,2,uVar12);
  iVar4 = IRInst__getOperandRecord(inst,3);
  *(undefined4 *)(iVar4 + 0x10) = uVar10;
  IRInst__setOperandSource(inst,2,operandVReg2,0,param_4);
  IROperand__setModifierBits(inst + 0xbc,1,uVar2);
  IROperand__setModifierBits(inst + 0xbc,2,uVar11);
  iVar4 = IRInst__getOperandRecord(inst,2);
  *(undefined4 *)(iVar4 + 0x10) = uVar9;
  return;
}

/* FUN_0010da84 @ 0x10da84 (84 bytes) */
int FUN_0010da84(param_1)
  int param_1;
{
  *(undefined4 *)(((unsigned char *)0x00001730) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x0000172c) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x00001728) + param_1) = 0;
  _memset(param_1 + 0x68,0,0xd00);
  return _memset(param_1 + 0xd68,0,0x9c0);
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

/* FUN_0010dbd8 @ 0x10dbd8 (36 bytes) */
int FUN_0010dbd8(param_1, param_2)
  int param_1;
  uint param_2;
{
  int iVar1;
  
  iVar1 = ((int)param_2 >> 3) + param_1;
  ((unsigned char *)0x00001734)[iVar1] = (byte)(1 << (param_2 & 7)) | ((unsigned char *)0x00001734)[iVar1];
  return;
}

/* FUN_0010dbfc @ 0x10dbfc (36 bytes) */
int FUN_0010dbfc(param_1, param_2)
  int param_1;
  uint param_2;
{
  int iVar1;
  
  iVar1 = ((int)param_2 >> 3) + param_1;
  ((unsigned char *)0x00001734)[iVar1] =
       ((byte)(-2 << (param_2 & 7)) | (byte)(0xfffffffe >> 0x20 - (param_2 & 7))) &
       ((unsigned char *)0x00001734)[iVar1];
  return;
}

/* FUN_0010dc20 @ 0x10dc20 (124 bytes) */
int FUN_0010dc20(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 5;
  iVar2 = param_1;
  do {
    ((unsigned char *)0x00001734)[iVar2] = 0xff;
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar3 = 6;
  iVar2 = param_1;
  do {
    ((unsigned char *)0x00001739)[iVar2] = 0;
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar2 = 0x28;
  do {
    ((int (*)())FUN_0010dbd8)(param_1,iVar2);
    bVar1 = iVar2 != 0x2c;
    iVar2 = iVar2 + 1;
  } while (bVar1);
  return;
}

/* FUN_0010dc9c @ 0x10dc9c (28 bytes) */
int FUN_0010dc9c(param_1, param_2)
  int param_1;
  uint param_2;
{
  return (int)(uint)(byte)((unsigned char *)0x00001734)[((int)param_2 >> 3) + param_1] >> (param_2 & 7) & 1;
}

/* FUN_0010dcb8 @ 0x10dcb8 (12 bytes) */
int FUN_0010dcb8(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  *param_2 = 0;
  return;
}

/* FUN_0010dcc4 @ 0x10dcc4 (56 bytes) */
int FUN_0010dcc4()
{
  
  if (*(int *)((*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)) + 0x6c4) != 0) {
    Compiler__fail((*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),0xf);
  }
  return 0;
}

/* FUN_0010dd08 @ 0x10dd08 (68 bytes) */
int FUN_0010dd08(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  
  iVar1 = FUN_00109810(0xa4,param_3);
  *(undefined4 *)(iVar1 + 300) = param_2;
  *(uint *)(iVar1 + 0x14) = *(uint *)(iVar1 + 0x14) & 0xffff7fff;
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

/* FUN_0010ddcc @ 0x10ddcc (12 bytes) */
int FUN_0010ddcc(param_1)
  int param_1;
{
  return *(undefined4 *)(*(int *)(param_1 + 0x30c) + 0x60);
}

/* FUN_0010ddd8 @ 0x10ddd8 (12 bytes) */
int FUN_0010ddd8(param_1)
  int param_1;
{
  return *(undefined4 *)(*(int *)(param_1 + 0x30c) + 100);
}

/* FUN_0010dde4 @ 0x10dde4 (8 bytes) */
int FUN_0010dde4()
{
  return 0x10c;
}

/* FUN_0010ddec @ 0x10ddec (8 bytes) */
int FUN_0010ddec()
{
  return 0xb5;
}

/* FUN_0010ddfc @ 0x10ddfc (56 bytes) */
int FUN_0010ddfc(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  int param_7;
{
  if (*(int *)(param_7 + 0x6c4) != 0) {
    Compiler__fail(param_7,0xf);
  }
  return 0;
}

/* FUN_0010de34 @ 0x10de34 (56 bytes) */
int FUN_0010de34()
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
  uVar2 = FUN_000ec208(param_2,*param_4 >> 0x10 & 0x3f);
  uVar2 = FUN_00127608(uVar5,uVar2,(int)(short)uVar1,0);
  iVar3 = FUN_00109810(0xa4,uVar4);
  IRInst__setOperandRef(iVar3,0,uVar2);
  *(int *)(iVar3 + 300) = (int)(short)uVar1;
  return FUN_000f92fc(param_2,iVar3,param_6);
}

/* FUN_0010defc @ 0x10defc (340 bytes) */
int FUN_0010defc(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  iVar2 = 0;
  if (iVar1 != 0) {
    puVar3 = *(undefined4 **)(iVar1 + 0x60);
    if (puVar3 != (undefined4 *)0x0) {
      (**(code **)*puVar3)(puVar3);
      (**(code **)(param_2 + 0x34c))(*(undefined4 *)(param_2 + 0x354),puVar3);
      iVar1 = *(int *)(param_1 + 4);
    }
    if (*(int *)(iVar1 + 100) != 0) {
      /* issue #79 class: r4 = `lwz r4,0x64(r2)` (compared, then the release argument); the sibling in the
       * second block passes the same field */
      (**(code **)(param_2 + 0x34c))(*(undefined4 *)(param_2 + 0x354),*(int *)(iVar1 + 100));
      iVar1 = *(int *)(param_1 + 4);
    }
    (**(code **)(param_2 + 0x34c))(*(undefined4 *)(param_2 + 0x354),iVar1);
    iVar2 = *(int *)(param_1 + 4);
  }
  iVar1 = *(int *)(param_1 + 8);
  if ((iVar2 != iVar1) && (iVar1 != 0)) {
    puVar3 = *(undefined4 **)(iVar1 + 0x60);
    if (puVar3 != (undefined4 *)0x0) {
      (**(code **)*puVar3)(puVar3);
      (**(code **)(param_2 + 0x34c))(*(undefined4 *)(param_2 + 0x354),puVar3);
      iVar1 = *(int *)(param_1 + 8);
    }
    if (*(int *)(iVar1 + 100) != 0) {
      (**(code **)(param_2 + 0x34c))(*(undefined4 *)(param_2 + 0x354),*(int *)(iVar1 + 100));
      iVar1 = *(int *)(param_1 + 8);
    }
    (**(code **)(param_2 + 0x34c))(*(undefined4 *)(param_2 + 0x354),iVar1);
  }
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

/* KhanChip__ctor_10e050 @ 0x10e050 (172 bytes) */
int KhanChip__ctor_10e050(this, param_2)
  undefined4 *this;
  undefined4 param_2;
{
  undefined *puVar1;
  int iVar2;
  
  this[2] = 0;
  puVar1 = PTR_DAT_001e8c88;
  this[1] = 0;
  *this = puVar1 + 8;
  *this = PTR_DAT_001e8c74 + 8;
  iVar2 = FUN_000e1564(param_2,0x1740);
  if (iVar2 != 0) {
    KhanVs__ctor_12a578(iVar2,param_2,1);
  }
  this[1] = iVar2;
  iVar2 = FUN_000e1564(param_2,0x1744);
  if (iVar2 != 0) {
    KhanPs__ctor_129130(iVar2,param_2,1);
  }
  this[2] = iVar2;
  return;
}

/* KhanChip__ctor_10e114 @ 0x10e114 (172 bytes) */
int KhanChip__ctor_10e114(this, param_2)
  undefined4 *this;
  undefined4 param_2;
{
  undefined *puVar1;
  int iVar2;
  
  this[2] = 0;
  puVar1 = PTR_DAT_001e8c88;
  this[1] = 0;
  *this = puVar1 + 8;
  *this = PTR_DAT_001e8c74 + 8;
  iVar2 = FUN_000e1564(param_2,0x1740);
  if (iVar2 != 0) {
    KhanVs__ctor_12a578(iVar2,param_2,1);
  }
  this[1] = iVar2;
  iVar2 = FUN_000e1564(param_2,0x1744);
  if (iVar2 != 0) {
    KhanPs__ctor_129130(iVar2,param_2,1);
  }
  this[2] = iVar2;
  return;
}

/* FUN_0010e1d8 @ 0x10e1d8 (176 bytes) */
int FUN_0010e1d8(this, param_2)
  undefined4 *this;
  undefined4 param_2;
{
  undefined *puVar1;
  int iVar2;
  undefined *puVar3;
  
  puVar1 = PTR_DAT_001e8c80;
  puVar3 = PTR_DAT_001e8c74 + 8;
  this[2] = 0;
  *this = puVar3;
  this[1] = 0;
  *this = puVar1 + 8;
  iVar2 = FUN_000e1564(param_2,0x1740);
  if (iVar2 != 0) {
    FudoVs__ctor_12a8bc(iVar2,param_2,1);
  }
  this[1] = iVar2;
  iVar2 = FUN_000e1564(param_2,0x1944);
  if (iVar2 != 0) {
    FudoPs__ctor_1920e0(iVar2,param_2,1);
  }
  this[2] = iVar2;
  return;
}

/* FUN_0010e2a0 @ 0x10e2a0 (176 bytes) */
int FUN_0010e2a0(this, param_2)
  undefined4 *this;
  undefined4 param_2;
{
  undefined *puVar1;
  int iVar2;
  undefined *puVar3;
  
  puVar1 = PTR_DAT_001e8c80;
  puVar3 = PTR_DAT_001e8c74 + 8;
  this[2] = 0;
  *this = puVar3;
  this[1] = 0;
  *this = puVar1 + 8;
  iVar2 = FUN_000e1564(param_2,0x1740);
  if (iVar2 != 0) {
    FudoVs__ctor_12a8bc(iVar2,param_2,1);
  }
  this[1] = iVar2;
  iVar2 = FUN_000e1564(param_2,0x1944);
  if (iVar2 != 0) {
    FudoPs__ctor_1920e0(iVar2,param_2,1);
  }
  this[2] = iVar2;
  return;
}

/* FUN_0010e368 @ 0x10e368 (76 bytes) */
int FUN_0010e368(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  iVar1 = 3;
  if (param_1 != 0x18) {
    iVar2 = FUN_0010406c(param_1);
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
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_000f3a30(inst);
  iVar2 = FUN_000f3a30(inst2);
  return iVar1 < iVar2;
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
int FUN_0010e56c(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_2 + 0x3d4) == 0) {
    iVar3 = *(int *)(param_2 + 0x3a0);
    iVar1 = (**(code **)(*param_1 + 0xe4))(param_1);
    iVar3 = *(int *)(iVar3 + 0x98);
    for (iVar2 = *(int *)(iVar3 + 8); iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
      if (((*(uint *)(iVar3 + 0x14) & 1) != 0) && (*(int *)(*(int *)(iVar3 + 0x88) + 8) == 0xa4)) {
        while (iVar2 = FUN_00130478(param_2,iVar1), iVar2 == 0) {
          iVar1 = iVar1 + 1;
        }
        Program__markHwRegUsed(param_2,iVar1);
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
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar3 = 0;
  puVar4 = param_1;
  do {
    iVar2 = IRInst__getOperandRecord(*param_1,0);
    if (*(char *)(iVar3 + iVar2 + 0x10) != '\x01') {
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
        iVar3 = FUN_00104ee4(piVar8,0);
        if (((iVar3 == 0xb) || (iVar3 = FUN_00104ee4(piVar8,0), iVar3 == 0xc)) ||
           (iVar3 = FUN_00104ee4(piVar8,0), iVar3 == 1)) {
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
  bool bVar1;
  int iVar2;
  int iVar3;
  int local_28 [9];
  
  iVar2 = IRInst__getOperandRecord(inst,0);
  local_28[0] = *(int *)(iVar2 + 0x10);
  if (*(int *)(iVar2 + 0x10) != DAT_001afa18) {
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

/* FUN_0010ed4c @ 0x10ed4c (540 bytes) */
int FUN_0010ed4c(param_1, param_2)
  int *param_1;
  int param_2;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  code *pcVar13;
  uint loopIndex;
  int *piVar15;
  
  piVar15 = *(int **)(*(int *)(param_2 + 0x3a0) + 0x98);
  piVar7 = (int *)piVar15[2];
  if (piVar7 != (int *)0x0) {
    iVar10 = 0;
    do {
      piVar8 = piVar7;
      if ((piVar15[5] & 1U) != 0) {
        iVar2 = (**(code **)(*piVar15 + 0x4c))(piVar15);
        if (iVar2 == 0) {
          piVar8 = (int *)piVar15[2];
        }
        else {
          uVar9 = 0xf;
          loopIndex = 0;
          iVar2 = (**(code **)(*piVar15 + 0x80))(piVar15);
          *(undefined4 *)(iVar2 + 0x98) = 0;
          *(int *)(iVar2 + 0x94) = iVar10;
          *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) | 0x40;
          Program__markHwRegUsed(param_2,iVar10);
          do {
            iVar3 = FUN_00104a94(iVar2,loopIndex);
            if ((iVar3 != 0) && (uVar12 = 1 << (loopIndex & 0x3f), (uVar12 & uVar9) != 0)) {
              iVar3 = FUN_00104b6c(iVar2,loopIndex);
              uVar11 = loopIndex + 1;
              iVar4 = FUN_0010426c(iVar2,loopIndex);
              if ((int)uVar11 < 4) {
                do {
                  iVar5 = FUN_00104a94(iVar2,uVar11);
                  if (((iVar5 != 0) && (iVar5 = FUN_00104b6c(iVar2,uVar11), iVar5 == iVar3)) &&
                     (iVar5 = FUN_0010426c(iVar2,uVar11), iVar4 == iVar5)) {
                    uVar12 = uVar12 | 1 << (uVar11 & 0x3f);
                  }
                  bVar1 = uVar11 != 3;
                  uVar11 = uVar11 + 1;
                } while (bVar1);
              }
              if (uVar12 != 0) {
                uVar9 = uVar9 - uVar12;
                pcVar13 = *(code **)(*param_1 + 0x54);
                uVar6 = FUN_000ec2c4(param_2,iVar3);
                iVar3 = IRInst__getOperandRecord(iVar2,1);
                uVar12 = *(uint *)(iVar2 + 0x13c);
                (*pcVar13)(param_1,iVar10,uVar6,iVar4,*(undefined4 *)(iVar3 + 0x10),uVar12 & 1,
                           uVar12 >> 2 & 1,uVar12 >> 1 & 1);
              }
            }
            loopIndex = loopIndex + 1;
          } while ((int)loopIndex < 4);
          piVar8 = (int *)piVar15[2];
          iVar10 = iVar10 + 1;
        }
      }
      piVar7 = (int *)piVar8[2];
      piVar15 = piVar8;
    } while ((int *)piVar8[2] != (int *)0x0);
  }
  return;
}

/* FUN_0010ef68 @ 0x10ef68 (1052 bytes) */
int FUN_0010ef68(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  bool bVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  code *pcVar15;
  int iVar16;
  uint loopIndex;
  int iVar18;
  undefined1 local_58 [20];
  
  iVar18 = *(int *)(param_2 + 0x3a4);
  if (iVar18 == 0) {
    iVar18 = *(int *)(param_2 + 0x3a0);
  }
  uVar7 = *(undefined4 *)(param_2 + 8);
  iVar16 = *(int *)(param_2 + 0x3f4);
  iVar14 = *(int *)(param_2 + 1000);
  iVar12 = *(int *)(param_2 + 0x3ec);
  if (*(int *)(param_2 + 0x3e4) != 0) {
    piVar3 = *(int **)(iVar18 + 0x98);
    piVar2 = (int *)piVar3[2];
    if ((int *)piVar3[2] == (int *)0x0) goto LAB_0010f084;
    do {
      piVar6 = piVar2;
      if ((piVar3[5] & 1U) != 0) {
        iVar4 = (**(code **)(*piVar3 + 0x4c))(piVar3);
        if ((((iVar4 == 0) || (iVar4 = piVar3[0x52], iVar16 != piVar3[0x51])) || (iVar4 < iVar14))
           || (iVar12 <= iVar4)) {
          piVar6 = (int *)piVar3[2];
        }
        else {
          uVar11 = iVar4 - iVar14;
          Program__markHwRegUsed(param_2,uVar11);
          FUN_00130bd4(param_2,uVar11);
          piVar3[0x25] = uVar11;
          piVar3[0x26] = 0;
          piVar3[5] = piVar3[5] | 0x40;
          if (*(int *)(param_2 + 0x80) < (int)uVar11) {
            *(uint *)(param_2 + 0x80) = uVar11;
          }
          *(uint *)(param_2 + 0x88) = 1 << (uVar11 & 0x3f) | *(uint *)(param_2 + 0x88);
          piVar6 = (int *)piVar3[2];
        }
      }
      piVar2 = (int *)piVar6[2];
      piVar3 = piVar6;
    } while ((int *)piVar6[2] != (int *)0x0);
  }
  piVar3 = *(int **)(iVar18 + 0x98);
LAB_0010f084:
  if ((int *)piVar3[2] != (int *)0x0) {
    piVar2 = (int *)piVar3[2];
    uVar11 = 0;
    do {
      piVar6 = piVar2;
      uVar13 = uVar11;
      if ((piVar3[5] & 1U) != 0) {
        iVar18 = (**(code **)(*piVar3 + 0x4c))(piVar3);
        if (iVar18 != 0) {
          iVar18 = (**(code **)(*piVar3 + 0x80))(piVar3);
          if (((*(uint *)(iVar18 + 0x14) & 0x40) == 0) || (*(int *)(iVar18 + 0x98) != 0)) {
            for (; iVar12 = (**(code **)(*param_1 + 0x138))(param_1,*(undefined4 *)(param_2 + 8)),
                (int)uVar11 < iVar12; uVar11 = uVar11 + 1) {
              iVar12 = Program__isHwRegAllowed(param_2,uVar11);
              if ((iVar12 != 0) && (iVar12 = FUN_00130478(param_2,uVar11), iVar12 != 0)) {
                uVar13 = uVar11 + 1;
                uVar10 = uVar11;
                goto LAB_0010f168;
              }
            }
            uVar10 = 0xffffffff;
            uVar13 = uVar11;
LAB_0010f168:
            Program__markHwRegUsed(param_2,uVar10);
            *(undefined4 *)(iVar18 + 0x98) = 0;
            *(uint *)(iVar18 + 0x94) = uVar10;
            if (*(int *)(param_2 + 0x80) < (int)uVar10) {
              *(uint *)(param_2 + 0x80) = uVar10;
            }
            *(uint *)(param_2 + 0x88) = 1 << (uVar10 & 0x3f) | *(uint *)(param_2 + 0x88);
            *(uint *)(iVar18 + 0x14) = *(uint *)(iVar18 + 0x14) | 0x40;
          }
          else {
            uVar10 = *(uint *)(iVar18 + 0x94);
          }
          if (((int)uVar10 < 0) ||
             (iVar12 = (**(code **)(*param_1 + 0x138))(param_1,*(undefined4 *)(param_2 + 8)),
             iVar12 <= (int)uVar10)) {
            Compiler__fail(uVar7,4);
          }
          iVar12 = *(int *)(iVar18 + 0x144);
          if ((iVar12 != 0x1b) && (iVar12 != 0x23)) {
            if (iVar12 == 0x24) {
              *(uint *)(iVar18 + 0x148) = uVar10;
            }
            uVar11 = 0xf;
            loopIndex = 0;
            do {
              iVar12 = FUN_00104a94(iVar18,loopIndex);
              if ((iVar12 != 0) && (uVar9 = 1 << (loopIndex & 0x3f), (uVar9 & uVar11) != 0)) {
                iVar14 = FUN_00104b6c(iVar18,loopIndex);
                iVar16 = FUN_0010426c(iVar18,loopIndex);
                iVar12 = 1;
                if (iVar14 != 7) {
                  iVar12 = iVar16;
                }
                uVar8 = loopIndex + 1;
                if ((int)uVar8 < 4) {
                  do {
                    iVar4 = FUN_00104a94(iVar18,uVar8);
                    if (((iVar4 != 0) && (iVar4 = FUN_00104b6c(iVar18,uVar8), iVar4 == iVar14)) &&
                       (iVar4 = FUN_0010426c(iVar18,uVar8), iVar16 == iVar4)) {
                      uVar9 = uVar9 | 1 << (uVar8 & 0x3f);
                    }
                    bVar1 = uVar8 != 3;
                    uVar8 = uVar8 + 1;
                  } while (bVar1);
                }
                if (uVar9 != 0) {
                  FUN_00104ae4(local_58,iVar18);
                  pcVar15 = *(code **)(*param_1 + 0x54);
                  uVar11 = uVar11 - uVar9;
                  uVar5 = FUN_000ec2c4(param_2,iVar14);
                  iVar14 = IRInst__getOperandRecord(iVar18,1);
                  uVar9 = *(uint *)(iVar18 + 0x13c);
                  (*pcVar15)(param_1,uVar10,uVar5,iVar12,*(undefined4 *)(iVar14 + 0x10),uVar9 & 1,
                             uVar9 >> 2 & 1,uVar9 >> 1 & 1);
                }
              }
              loopIndex = loopIndex + 1;
            } while ((int)loopIndex < 4);
          }
        }
        piVar6 = (int *)piVar3[2];
      }
      piVar2 = (int *)piVar6[2];
      uVar11 = uVar13;
      piVar3 = piVar6;
    } while ((int *)piVar6[2] != (int *)0x0);
  }
  return;
}

/* FUN_0010f38c @ 0x10f38c (328 bytes) */
int FUN_0010f38c(param_1, vector)
  undefined4 *param_1;
  uint *vector;
{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  uint loopIndex;
  int *piVar10;
  
  uVar2 = vector[1];
  if (uVar2 != 0) {
    loopIndex = 0;
    do {
      if (loopIndex < *vector) {
        if (uVar2 <= loopIndex) {
          _memset(uVar2 * 4 + vector[2],0,(loopIndex - uVar2) * 4 + 4);
          vector[1] = loopIndex + 1;
        }
        puVar3 = (undefined4 *)(loopIndex * 4 + vector[2]);
      }
      else {
        puVar3 = (undefined4 *)Vector__elementRefGrow(vector,loopIndex);
      }
      loopIndex = loopIndex + 1;
      piVar8 = (int *)*puVar3;
      iVar7 = 0;
      puVar3 = param_1;
      do {
        iVar4 = IRInst__getOperandRecord(*param_1,0);
        if (*(char *)(iVar7 + iVar4 + 0x10) != '\x01') {
          iVar4 = 0;
          piVar10 = piVar8;
          do {
            iVar5 = IRInst__getOperandRecord(*piVar8,0);
            if ((*(char *)(iVar4 + iVar5 + 0x10) != '\x01') && (piVar10[1] == puVar3[1])) {
              iVar5 = piVar8[5];
              iVar6 = *piVar8;
              piVar10[1] = 0;
              piVar8[5] = iVar5 + -1;
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
      uVar2 = vector[1];
    } while (loopIndex < uVar2);
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
      iVar3 = FUN_00105dbc(uVar5,0);
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
      iVar3 = FUN_00105dbc(uVar5,0);
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
      iVar3 = FUN_00105dbc(uVar5,0);
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
asm(".set FUN_0010da84, _FUN_0010da84");
asm(".globl FUN_0010dcb8");
asm(".set FUN_0010dcb8, _FUN_0010dcb8");
asm(".globl FUN_0010dcc4");
asm(".set FUN_0010dcc4, _FUN_0010dcc4");
asm(".globl FUN_0010dd08");
asm(".set FUN_0010dd08, _FUN_0010dd08");
asm(".globl FUN_0010ddec");
asm(".set FUN_0010ddec, _FUN_0010ddec");
asm(".globl FUN_0010ddfc");
asm(".set FUN_0010ddfc, _FUN_0010ddfc");
asm(".globl FUN_0010de34");
asm(".set FUN_0010de34, _FUN_0010de34");
asm(".globl FUN_0010de6c");
asm(".set FUN_0010de6c, _FUN_0010de6c");
asm(".globl FUN_0010ed4c");
asm(".set FUN_0010ed4c, _FUN_0010ed4c");
asm(".globl FUN_0010ef68");
asm(".set FUN_0010ef68, _FUN_0010ef68");
