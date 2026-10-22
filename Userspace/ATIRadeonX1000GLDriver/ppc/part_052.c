#include "decls.h"

/* FUN_00197b30 @ 0x197b30 (692 bytes) */
int FUN_00197b30(param_1, inst, param_3, compiler)
  int *param_1;
  int inst;
  undefined4 param_3;
  int compiler;
{
  int *operandVReg;
  undefined2 uVar4;
  int iVar2;
  int iVar3;
  byte bVar5;
  int iVar6;
  int iVar7;
  
  operandVReg = (int *)IRInst__getOperandSource(inst,1);
  uVar4 = thunk_FUN_00134de8(*(undefined4 *)(compiler + 0x6c4),operandVReg);
  iVar2 = (**(code **)(**(int **)(compiler + 0x30c) + 0x7c))(*(int **)(compiler + 0x30c),inst);
  if (iVar2 == 0) {
    IRInst__getOperandRecord(inst,0);
  }
  *(undefined4 *)(param_1[0x18] * 0x48 + param_1[0x16]) = 2;
  *(undefined2 *)(param_1[0x18] * 0x48 + param_1[0x16] + 0xe) = uVar4;
  iVar2 = *(int *)(inst + 0x134);
  iVar6 = *(int *)(*(int *)(inst + 0x88) + 8);
  if (iVar6 != 0x77) {
    *(char *)(param_1[0x18] * 0x48 + param_1[0x16] + 0x19) = (char)iVar2;
    iVar7 = param_1[0x18];
    iVar3 = param_1[0x16];
    uVar4 = thunk_FUN_00134de8(*(undefined4 *)(compiler + 0x6c4),inst);
    *(undefined2 *)(iVar7 * 0x48 + iVar3 + 0xc) = uVar4;
  }
  else {
    *(undefined2 *)(param_1[0x18] * 0x48 + param_1[0x16] + 0xc) = 0;
    *(undefined4 *)(param_1[0x17] + 0x9370) = 1;
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x16] + 0x19) = 0;
  }
  iVar3 = (**(code **)(*operandVReg + 0x80))(operandVReg);
  if (iVar3 == 0) {
    *(undefined4 *)(iVar2 * 4 + param_1[0x17] + 0x9378) = 1;
  }
  if (*(int *)(PTR_DAT_001e913c + iVar6 * 0x38 + 0xc) != -1) {
    *(char *)(param_1[0x18] * 0x48 + param_1[0x16] + 0x1a) =
         (char)*(int *)(PTR_DAT_001e913c + iVar6 * 0x38 + 0xc);
  }
  bVar5 = 0xc;
  iVar2 = *(int *)(iVar2 * 0xc + *(int *)(*(int *)(compiler + 0x6c4) + 0x78) + 4);
  if (((iVar2 != 2) && (bVar5 = 8, iVar2 != 3)) && (bVar5 = 0, iVar2 == 1)) {
    bVar5 = 0xe;
  }
  if (iVar6 != 0x77) {
    if (iVar6 - 0x75U < 2) {
      *(byte *)(param_1[0x18] * 0x48 + param_1[0x16] + 0x1f) = bVar5 & 7;
    }
    else {
      *(byte *)(param_1[0x18] * 0x48 + param_1[0x16] + 0x1f) = bVar5;
    }
  }
  else {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x16] + 0x1f) = 0;
  }
  operandVReg = (int *)IRInst__getOperandSource(inst,1);
  iVar2 = (**(code **)(*operandVReg + 0x80))(operandVReg);
  if (iVar2 != 0) {
                    
                    
    (**(code **)(*param_1 + 0x154))(param_1,1,inst,compiler);
    return;
  }
  return;
}

/* FUN_00197de4 @ 0x197de4 (232 bytes) */
int FUN_00197de4(param_1, param_2, param_3, param_4, inst)
  undefined4 param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 inst;
{
  float fVar1;
  uint uVar2;
  int operandVReg;
  int loopRemaining;
  int loopIndex;
  undefined4 local_38 [9];
  
  operandVReg = IRInst__getOperandSource(inst,param_2);
  loopRemaining = IRInst__getOperandRecord(inst,param_2);
  loopIndex = 0;
  local_38[0] = *(undefined4 *)(loopRemaining + 0x10);
  loopRemaining = 4;
  do {
    uVar2 = (uint)*(byte *)((int)local_38 + loopIndex);
    if (uVar2 < 4) goto LAB_00197e50;
    loopIndex = loopIndex + 1;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  uVar2 = 0;
LAB_00197e50:
  fVar1 = *(float *)(uVar2 * 0x18 + operandVReg + 0x20);
  if (fVar1 == FLOAT_001aa0d4) {
    *(undefined4 *)(param_2 * 4 + param_3) = 0x14;
  }
  else if (fVar1 == FLOAT_001aa10c) {
    *(undefined4 *)(param_2 * 4 + param_3) = 0x16;
  }
  else if (fVar1 == FLOAT_001aa0e8) {
    *(undefined4 *)(param_2 * 4 + param_3) = 0x15;
  }
  return;
}

/* FUN_00197ecc @ 0x197ecc (232 bytes) */
int FUN_00197ecc(param_1, param_2, param_3, param_4, inst)
  undefined4 param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 inst;
{
  float fVar1;
  uint uVar2;
  int operandVReg;
  int loopRemaining;
  int loopIndex;
  undefined4 local_38 [9];
  
  operandVReg = IRInst__getOperandSource(inst,param_2);
  loopRemaining = IRInst__getOperandRecord(inst,param_2);
  loopIndex = 0;
  local_38[0] = *(undefined4 *)(loopRemaining + 0x10);
  loopRemaining = 4;
  do {
    uVar2 = (uint)*(byte *)((int)local_38 + loopIndex);
    if (uVar2 < 4) goto LAB_00197f38;
    loopIndex = loopIndex + 1;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  uVar2 = 0;
LAB_00197f38:
  fVar1 = *(float *)(uVar2 * 0x18 + operandVReg + 0x20);
  if (fVar1 == FLOAT_001aa0d4) {
    *(undefined4 *)(param_2 * 4 + param_3) = 0x10;
  }
  else if (fVar1 == FLOAT_001aa10c) {
    *(undefined4 *)(param_2 * 4 + param_3) = 0x12;
  }
  else if (fVar1 == FLOAT_001aa0e8) {
    *(undefined4 *)(param_2 * 4 + param_3) = 0x11;
  }
  return;
}

/* FUN_00197fb4 @ 0x197fb4 (208 bytes) */
int FUN_00197fb4(param_1, param_2, param_3, inst, param_5)
  int param_1;
  int param_2;
  int param_3;
  undefined4 inst;
  undefined4 param_5;
{
  int iVar1;
  int operandRecord;
  undefined1 uVar3;
  int iVar4;
  
  if (param_2 != 0) {
    *(undefined2 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0xc) =
         (*(unsigned short *)((unsigned char *)&(param_5) + 2));
    iVar4 = *(int *)(param_1 + 0x60);
    iVar1 = *(int *)(param_1 + 0x58);
    operandRecord = IRInst__getOperandRecord(inst,0);
    uVar3 = FUN_00195424(*(undefined4 *)(operandRecord + 0x10));
    *(undefined1 *)(iVar4 * 0x48 + iVar1 + 0x14) = uVar3;
  }
  if (param_3 != 0) {
    *(undefined2 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x18) =
         (*(unsigned short *)((unsigned char *)&(param_5) + 2));
    iVar4 = *(int *)(param_1 + 0x60);
    iVar1 = *(int *)(param_1 + 0x58);
    operandRecord = IRInst__getOperandRecord(inst,0);
    *(bool *)(iVar4 * 0x48 + iVar1 + 0x20) = *(char *)(operandRecord + 0x13) == '\0';
  }
  return;
}

/* FUN_00198084 @ 0x198084 (296 bytes) */
int FUN_00198084(param_1, param_2, param_3, inst)
  int param_1;
  int param_2;
  int param_3;
  int inst;
{
  int iVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  undefined1 uVar5;
  int iVar6;
  
  iVar6 = *(int *)(inst + 0x98);
  iVar4 = *(int *)(inst + 0x94);
  if (iVar6 == 9) {
    iVar1 = iVar4 + 1;
    iVar3 = *(int *)(*(int *)(param_1 + 0x5c) + 0x9374);
    if (iVar1 <= iVar3) {
      iVar1 = iVar3;
    }
    *(int *)(*(int *)(param_1 + 0x5c) + 0x9374) = iVar1;
  }
  uVar5 = (undefined1)iVar4;
  if ((param_2 != 0) && (iVar6 != 8)) {
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x16) = uVar5;
    iVar3 = *(int *)(param_1 + 0x60);
    iVar4 = *(int *)(param_1 + 0x58);
    iVar1 = IRInst__getOperandRecord(inst,0);
    uVar2 = FUN_00195424(*(undefined4 *)(iVar1 + 0x10));
    *(undefined1 *)(iVar3 * 0x48 + iVar4 + 0x15) = uVar2;
  }
  if (param_3 != 0) {
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x22) = uVar5;
    if (iVar6 == 8) {
      *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x23) = 1;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x60);
      iVar4 = *(int *)(param_1 + 0x58);
      iVar6 = IRInst__getOperandRecord(inst,0);
      *(bool *)(iVar1 * 0x48 + iVar4 + 0x21) = *(char *)(iVar6 + 0x13) == '\0';
    }
  }
  return;
}

/* FUN_001981ac @ 0x1981ac (8500 bytes) */
int FUN_001981ac(inst, inst2)
  int *inst;
  int *inst2;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  byte bVar5;
  uint uVar6;
  code *pcVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int *a0;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  undefined4 a1;
  int *piVar15;
  int *loopIndex;
  int *loopIndex2;
  uint uVar18;
  int *piVar19;
  int iVar20;
  int *a4;
  uint loopIndex3;
  int *piVar22;
  int *piVar23;
  undefined4 uVar24;
  int *piVar25;
  byte in_xer_so = 0;
  int loopRemaining;
  undefined8 operandVReg;
  int local_f8;
  int local_f4;
  int local_f0;
  int local_ec [4];
  int local_dc [4];
  int local_cc [4];
  int local_bc [4];
  int local_ac;
  int local_a8;
  undefined4 local_9c;
  undefined4 local_98;
  int *local_88;
  uint local_84;
  int *local_80;
  int local_7c;
  uint local_78;
  uint local_74;
  uint local_70;
  uint local_6c;
  int local_68;
  int local_64;
  undefined *local_60;
  int *local_5c;
  
  loopIndex = &local_ac;
  a4 = &local_f8;
  piVar25 = &local_f4;
  loopIndex2 = inst2;
  uVar10 = FUN_0019786c(inst,&local_9c,loopIndex,inst2,a4,piVar25);
  local_6c = uVar10 & 1;
  local_70 = uVar10 >> 1 & 1;
  local_68 = *(int *)(inst2[0x22] + 8);
  local_5c = local_cc;
  loopRemaining = 4;
  local_78 = uVar10 >> 4 & 1;
  local_74 = uVar10 >> 2 & 1;
  iVar8 = 0;
  do {
    *(undefined4 *)(iVar8 + (int)local_bc) = 0;
    *(undefined4 *)(iVar8 + (int)local_dc) = 0;
    *(undefined4 *)(iVar8 + (int)local_ec) = 0;
    *(undefined4 *)(iVar8 + (int)local_5c) = 0;
    iVar8 = iVar8 + 4;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  iVar8 = (**(code **)(*inst2 + 0x14))(inst2);
  uVar6 = local_6c;
  uVar10 = local_70;
  if (local_68 == 0xb4) {
    iVar8 = 3;
LAB_00198290:
    piVar22 = (int *)((int)((unsigned char *)0x0) + 1);
    piVar19 = inst2 + 0x26;
    bVar1 = local_6c != 0;
    bVar2 = local_70 != 0;
    local_64 = (uint)(byte)(((int)local_78 < 0) << 3 | (0 < (int)local_78) << 2 |
                            (local_78 == 0) << 1 | in_xer_so & 1) << 0x1c;
    local_60 = &DAT_001b81b8;
    do {
      loopRemaining = IRInst__getOperandRecord(inst2,piVar22);
      piVar23 = *(int **)(loopRemaining + 0x10);
      local_f0 = -1;
      operandVReg = IRInst__getOperandSource(inst2,piVar22);
      a0 = (int *)((ulonglong)operandVReg >> 0x20);
      iVar20 = *(int *)(local_60 + -0x56f8);
      loopRemaining = (**(code **)(*a0 + 0x60))(a0,(int)operandVReg,loopIndex,loopIndex2,a4,piVar25,local_60);
      if (loopRemaining == 0) {
        local_7c = 0;
        local_80 = (int *)0x0;
      }
      else {
        local_80 = a0;
        loopRemaining = IRInst__getOperandRecord(a0,1);
        uVar14 = *(undefined4 *)(loopRemaining + 0x10);
        loopRemaining = IRInst__getOperandRecord(inst2,piVar22);
        iVar20 = *(int *)(loopRemaining + 0x10);
        FUN_000f2bdc(&local_88,uVar14,iVar20);
        piVar23 = local_88;
        a0 = (int *)IRInst__getOperandSource(local_80,1);
        a4 = (int *)inst[3];
        loopIndex2 = (int *)0x0;
        loopIndex = a0;
        IRInst__setOperandSource(inst2,piVar22,a0,0,a4);
        if (piVar22 == (int *)0x0) {
          local_7c = 1;
          inst2[0x27] = (int)piVar23;
        }
        else {
          loopRemaining = IRInst__getOperandRecord(inst2,piVar22);
          *(int **)(loopRemaining + 0x10) = piVar23;
          local_7c = 1;
        }
      }
      loopRemaining = a0[0x26];
      if (loopRemaining != 0x2c) {
        if (loopRemaining == 0x29) {
          loopIndex2 = (int *)inst[3];
          loopIndex = piVar22;
          /* dropped 2 args (found auditing #70 via ExtendIndirectCalls.java / ground-truth
           * disassembly): stock passes piVar22 and loopIndex2 (the value just computed above) too. */
          local_f0 = (**(code **)(*inst + 0x158))(inst,inst2,piVar22,loopIndex2);
LAB_0019852c:
          bVar3 = piVar22 == (int *)((int)((unsigned char *)0x0) + 3);
          bVar5 = (byte)((uint)local_64 >> 0x18);
          if ((bVar3) && (!(bool)(bVar5 >> 5 & 1))) {
            local_ec[2] = 0x11;
          }
          if (bVar1) {
            uVar14 = local_9c;
            if (bVar3) {
              if (!(bool)(bVar5 >> 5 & 1)) goto LAB_00199cdc;
              if (local_74 != 0) {
                uVar14 = local_98;
              }
            }
            loopRemaining = FUN_0019534c(piVar23,uVar14);
            iVar13 = FUN_001953b8(piVar23,uVar14);
            local_bc[(int)piVar22] = 0x14;
            piVar15 = piVar22;
            if (loopRemaining == 0) {
              if (iVar13 != 0) {
                loopIndex3 = 1;
                loopIndex2 = inst + 0xe;
                loopIndex = inst;
                do {
                  piVar25 = (int *)loopIndex[7];
                  a4 = (int *)(loopIndex3 - 1);
                  if ((a0 == piVar25) ||
                     ((((((((piVar25 != (int *)0x0 && (a0 != (int *)0x0)) && (piVar25[0x20] != 0))
                          && ((loopRemaining = FUN_00126760(piVar25[0x26]), loopRemaining != 0 &&
                              ((piVar25[5] & 2U) == 0)))) &&
                         ((loopRemaining = (**(code **)(*piVar25 + 0x50))(piVar25), loopRemaining == 0 &&
                          ((a0[0x20] != 0 && (loopRemaining = FUN_00126760(a0[0x26]), loopRemaining != 0)))))) &&
                        ((a0[5] & 2U) == 0)) &&
                       (((loopRemaining = (**(code **)(*a0 + 0x50))(a0), loopRemaining == 0 &&
                         ((*(uint *)(loopIndex[7] + 0x14) & 0x40) != 0)) && ((a0[5] & 0x40U) != 0))))
                      && (*(int *)(loopIndex[7] + 0x94) == a0[0x25])))) {
                    uVar9 = inst[0x20];
                    *loopIndex2 = local_f0;
                    inst[0x20] = 1 << (loopIndex3 & 0x3f) | uVar9;
                    goto LAB_00199c88;
                  }
                  bVar4 = loopIndex3 != 3;
                  loopIndex2 = loopIndex2 + 1;
                  loopIndex = loopIndex + 1;
                  loopIndex3 = loopIndex3 + 1;
                } while (bVar4);
                a4 = (int *)((int)((unsigned char *)0x0) + 3);
LAB_00199c88:
                pcVar7 = *(code **)(*inst + 0xf8);
                goto joined_r0x00199c90;
              }
            }
            else {
              if (iVar13 == 0) {
                loopIndex3 = 1;
                loopIndex2 = inst + 0x12;
                loopIndex = inst;
                do {
                  piVar25 = (int *)loopIndex[10];
                  a4 = (int *)(loopIndex3 - 1);
                  if ((a0 == piVar25) ||
                     ((((((piVar25 != (int *)0x0 && (a0 != (int *)0x0)) &&
                         ((piVar25[0x20] != 0 &&
                          ((loopRemaining = FUN_00126760(piVar25[0x26]), loopRemaining != 0 &&
                           ((piVar25[5] & 2U) == 0)))))) &&
                        (loopRemaining = (**(code **)(*piVar25 + 0x50))(piVar25), loopRemaining == 0)) &&
                       (((a0[0x20] != 0 && (loopRemaining = FUN_00126760(a0[0x26]), loopRemaining != 0)) &&
                        ((a0[5] & 2U) == 0)))) &&
                      (((loopRemaining = (**(code **)(*a0 + 0x50))(a0), loopRemaining == 0 &&
                        ((*(uint *)(loopIndex[10] + 0x14) & 0x40) != 0)) &&
                       (((a0[5] & 0x40U) != 0 && (*(int *)(loopIndex[10] + 0x94) == a0[0x25])))))))) {
                    uVar9 = inst[0x21];
                    *loopIndex2 = local_f0;
                    inst[0x21] = 1 << (loopIndex3 & 0x3f) | uVar9;
                    goto LAB_00199b44;
                  }
                  bVar4 = loopIndex3 != 3;
                  loopIndex2 = loopIndex2 + 1;
                  loopIndex = loopIndex + 1;
                  loopIndex3 = loopIndex3 + 1;
                } while (bVar4);
                a4 = (int *)((int)((unsigned char *)0x0) + 3);
LAB_00199b44:
                pcVar7 = *(code **)(*inst + 0xf4);
              }
              else {
                loopIndex3 = 1;
                loopIndex2 = inst;
                loopIndex = inst;
                do {
                  piVar25 = (int *)loopIndex2[7];
                  a4 = (int *)(loopIndex3 - 1);
                  if (((a0 == piVar25) ||
                      ((((piVar25 != (int *)0x0 && (a0 != (int *)0x0)) &&
                        ((piVar25[0x20] != 0 &&
                         ((((((loopRemaining = FUN_00126760(piVar25[0x26]), loopRemaining != 0 &&
                              ((piVar25[5] & 2U) == 0)) &&
                             (loopRemaining = (**(code **)(*piVar25 + 0x50))(piVar25), loopRemaining == 0)) &&
                            ((a0[0x20] != 0 && (loopRemaining = FUN_00126760(a0[0x26]), loopRemaining != 0)))) &&
                           ((a0[5] & 2U) == 0)) &&
                          ((loopRemaining = (**(code **)(*a0 + 0x50))(a0), loopRemaining == 0 &&
                           ((*(uint *)(loopIndex2[7] + 0x14) & 0x40) != 0)))))))) &&
                       (((a0[5] & 0x40U) != 0 && (*(int *)(loopIndex2[7] + 0x94) == a0[0x25])))))) &&
                     ((piVar25 = (int *)loopIndex2[10], a0 == piVar25 ||
                      ((((((piVar25 != (int *)0x0 && (a0 != (int *)0x0)) && (piVar25[0x20] != 0)) &&
                         ((loopRemaining = FUN_00126760(piVar25[0x26]), loopRemaining != 0 &&
                          ((piVar25[5] & 2U) == 0)))) &&
                        (((loopRemaining = (**(code **)(*piVar25 + 0x50))(piVar25), loopRemaining == 0 &&
                          ((a0[0x20] != 0 && (loopRemaining = FUN_00126760(a0[0x26]), loopRemaining != 0)))) &&
                         ((a0[5] & 2U) == 0)))) &&
                       ((((loopRemaining = (**(code **)(*a0 + 0x50))(a0), loopRemaining == 0 &&
                          ((*(uint *)(loopIndex2[10] + 0x14) & 0x40) != 0)) && ((a0[5] & 0x40U) != 0))
                        && (*(int *)(loopIndex2[10] + 0x94) == a0[0x25])))))))) {
                    uVar18 = inst[0x20];
                    uVar9 = inst[0x21];
                    loopIndex3 = 1 << (loopIndex3 & 0x3f);
                    loopIndex[0x12] = local_f0;
                    inst[0x20] = loopIndex3 | uVar18;
                    inst[0x21] = loopIndex3 | uVar9;
                    loopIndex[0xe] = local_f0;
                    goto LAB_001999e8;
                  }
                  bVar4 = loopIndex3 != 3;
                  loopIndex2 = loopIndex2 + 1;
                  loopIndex3 = loopIndex3 + 1;
                  loopIndex = loopIndex + 1;
                } while (bVar4);
                a4 = (int *)((int)((unsigned char *)0x0) + 3);
LAB_001999e8:
                (**(code **)(*inst + 0xf4))(inst,piVar22,local_bc,local_dc,a4,piVar23);
                pcVar7 = *(code **)(*inst + 0xf8);
joined_r0x00199c90:
                if (bVar3) {
                  if ((bool)((byte)((uint)local_64 >> 0x1d) & 1)) {
                    piVar15 = (int *)((int)((unsigned char *)0x0) + 3);
                  }
                  else {
                    piVar15 = (int *)((int)((unsigned char *)0x0) + 1);
                  }
                }
              }
              loopIndex = local_bc;
              loopIndex2 = local_dc;
              /* dropped 4 args (found auditing #70 via ExtendIndirectCalls.java / ground-truth
               * disassembly): stock passes loopIndex, loopIndex2, r21 (== a4: the search loop's
               * `r23 - 1`, or 3 only when the loop runs out - NOT a literal 3, #80), and piVar23
               * too - piVar23's real register (r27) is set once, early in the function, and never
               * reassigned before this call, same as the already-fixed 0xec/0xf0 calls above. */
              (*pcVar7)(inst,piVar15,loopIndex,loopIndex2,a4,piVar23);
              piVar25 = piVar23;
            }
          }
LAB_00199cdc:
          if (bVar2) {
            loopRemaining = IRInst__getOperandRecord(inst2,piVar22);
            piVar23 = *(int **)(loopRemaining + 0x10);
            loopRemaining = local_ac;
            if ((bVar3) && (local_74 != 0)) {
              loopRemaining = local_a8;
            }
            iVar13 = FUN_0019534c(piVar23,loopRemaining);
            loopRemaining = FUN_001953b8(piVar23,loopRemaining);
            local_ec[(int)piVar22] = 0x10;
            if (iVar13 != 0) {
              loopIndex3 = 1;
              loopIndex2 = inst + 0x12;
              loopIndex = inst;
              do {
                piVar25 = (int *)loopIndex[10];
                a4 = (int *)(loopIndex3 - 1);
                if ((a0 == piVar25) ||
                   ((((piVar25 != (int *)0x0 && (a0 != (int *)0x0)) &&
                     ((piVar25[0x20] != 0 &&
                      ((((iVar13 = FUN_00126760(piVar25[0x26]), iVar13 != 0 &&
                         ((piVar25[5] & 2U) == 0)) &&
                        (iVar13 = (**(code **)(*piVar25 + 0x50))(piVar25), iVar13 == 0)) &&
                       ((a0[0x20] != 0 && (iVar13 = FUN_00126760(a0[0x26]), iVar13 != 0)))))))) &&
                    ((((a0[5] & 2U) == 0 &&
                      ((iVar13 = (**(code **)(*a0 + 0x50))(a0), iVar13 == 0 &&
                       ((*(uint *)(loopIndex[10] + 0x14) & 0x40) != 0)))) &&
                     (((a0[5] & 0x40U) != 0 && (*(int *)(loopIndex[10] + 0x94) == a0[0x25])))))))) {
                  uVar9 = inst[0x21];
                  *loopIndex2 = local_f0;
                  inst[0x21] = 1 << (loopIndex3 & 0x3f) | uVar9;
                  goto LAB_00199e60;
                }
                bVar4 = loopIndex3 != 3;
                loopIndex2 = loopIndex2 + 1;
                loopIndex = loopIndex + 1;
                loopIndex3 = loopIndex3 + 1;
              } while (bVar4);
              a4 = (int *)((int)((unsigned char *)0x0) + 3);
LAB_00199e60:
              piVar15 = piVar22;
              if (bVar3) {
                if ((bool)((byte)((uint)local_64 >> 0x1d) & 1)) {
                  piVar15 = (int *)((int)((unsigned char *)0x0) + 3);
                }
                else {
                  piVar15 = (int *)((int)((unsigned char *)0x0) + 1);
                }
              }
              loopIndex = local_ec;
              loopIndex2 = local_5c;
              piVar25 = piVar23;
              /* dropped 4 args (found auditing #70 via ExtendIndirectCalls.java / ground-truth
               * disassembly): stock passes loopIndex, loopIndex2, r21 (== a4, search-loop r23-1 / 3 on exhaustion - not a literal 3, #80), and piVar25 too. */
              (**(code **)(*inst + 0xfc))(inst,piVar15,loopIndex,loopIndex2,a4,piVar25);
            }
            if (loopRemaining != 0) {
              loopIndex3 = 1;
              loopIndex2 = inst + 0xe;
              loopIndex = inst;
              do {
                piVar25 = (int *)loopIndex[7];
                a4 = (int *)(loopIndex3 - 1);
                if ((a0 == piVar25) ||
                   (((((piVar25 != (int *)0x0 && (a0 != (int *)0x0)) && (piVar25[0x20] != 0)) &&
                     ((((loopRemaining = FUN_00126760(piVar25[0x26]), loopRemaining != 0 &&
                        ((piVar25[5] & 2U) == 0)) &&
                       ((loopRemaining = (**(code **)(*piVar25 + 0x50))(piVar25), loopRemaining == 0 &&
                        ((a0[0x20] != 0 && (loopRemaining = FUN_00126760(a0[0x26]), loopRemaining != 0)))))) &&
                      ((a0[5] & 2U) == 0)))) &&
                    ((((loopRemaining = (**(code **)(*a0 + 0x50))(a0), loopRemaining == 0 &&
                       ((*(uint *)(loopIndex[7] + 0x14) & 0x40) != 0)) && ((a0[5] & 0x40U) != 0)) &&
                     (*(int *)(loopIndex[7] + 0x94) == a0[0x25])))))) {
                  uVar9 = inst[0x20];
                  *loopIndex2 = local_f0;
                  inst[0x20] = 1 << (loopIndex3 & 0x3f) | uVar9;
                  goto LAB_00199fdc;
                }
                bVar4 = loopIndex3 != 3;
                loopIndex2 = loopIndex2 + 1;
                loopIndex = loopIndex + 1;
                loopIndex3 = loopIndex3 + 1;
              } while (bVar4);
              a4 = (int *)((int)((unsigned char *)0x0) + 3);
LAB_00199fdc:
              piVar25 = piVar22;
              if (bVar3) {
                if ((bool)((byte)((uint)local_64 >> 0x1d) & 1)) {
                  piVar25 = (int *)((int)((unsigned char *)0x0) + 3);
                }
                else {
                  piVar25 = (int *)((int)((unsigned char *)0x0) + 1);
                }
              }
              loopIndex = local_ec;
              loopIndex2 = local_5c;
              /* dropped 4 args (found auditing #70 via ExtendIndirectCalls.java / ground-truth
               * disassembly): stock passes loopIndex, loopIndex2, r21 (== a4, not a literal 3, #80), and piVar23 too -
               * piVar23 directly, not piVar25 (reassigned below, diverged from piVar23 by here). */
              (**(code **)(*inst + 0x100))(inst,piVar25,loopIndex,loopIndex2,a4,piVar23);
              piVar25 = piVar23;
            }
          }
        }
        else {
          if ((((a0[0x20] != 0) && (loopRemaining = FUN_00126760(loopRemaining), loopRemaining != 0)) &&
              ((a0[5] & 2U) == 0)) && (loopRemaining = (**(code **)(*a0 + 0x50))(a0), loopRemaining == 0)) {
            local_f0 = FUN_00134de8(*(undefined4 *)(inst[3] + 0x6c4),a0);
            loopRemaining = (**(code **)(*a0 + 0x80))(a0);
            if (loopRemaining != 0) {
              loopIndex2 = (int *)inst[3];
              loopIndex = inst2;
              /* dropped 2 args (found auditing #70 via ExtendIndirectCalls.java / ground-truth
               * disassembly): stock passes inst2 and loopIndex2 too. */
              (**(code **)(*inst + 0x154))(inst,piVar22,inst2,loopIndex2);
            }
            goto LAB_0019852c;
          }
          loopRemaining = (**(code **)(*a0 + 0x50))(a0);
          if (loopRemaining != 0) {
            local_f0 = thunk_FUN_00134de8(*(undefined4 *)(inst[3] + 0x6c4),a0);
            goto LAB_0019852c;
          }
          loopRemaining = (**(code **)(*a0 + 0x48))(a0);
          if (loopRemaining != 0) {
            if (a0[0x26] == 0x33) {
              loopIndex = &local_f0;
              /* dropped 1 arg (found auditing #70 via ExtendIndirectCalls.java / ground-truth
               * disassembly): stock passes &local_f0 (loopIndex) too. */
              loopRemaining = (**(code **)(*inst + 0xdc))(inst,a0,loopIndex);
              if (loopRemaining == 0) {
                if ((piVar22 != (int *)((int)((unsigned char *)0x0) + 3)) ||
                   ((bool)((byte)((uint)local_64 >> 0x1d) & 1))) {
                  if (bVar1) {
                    loopIndex = local_bc;
                    loopIndex2 = local_dc;
                    a4 = inst2;
                    /* dropped 3 args (found auditing #70 via ExtendIndirectCalls.java /
                     * ground-truth disassembly): stock passes loopIndex, loopIndex2, a4 too. */
                    (**(code **)(*inst + 0xd4))(inst,piVar22,loopIndex,loopIndex2,a4);
                  }
                  if (bVar2) {
                    loopIndex = local_ec;
                    loopIndex2 = local_5c;
                    a4 = inst2;
                    /* dropped 3 args (found auditing #70 via ExtendIndirectCalls.java /
                     * ground-truth disassembly): stock passes loopIndex, loopIndex2, a4 too. */
                    (**(code **)(*inst + 0xd8))(inst,piVar22,loopIndex,loopIndex2,a4);
                  }
                }
                else {
                  local_ec[2] = 0x11;
                  loopIndex = local_ec;
                  loopIndex2 = local_5c;
                  a4 = inst2;
                  (**(code **)(*inst + 0xd8))
                            (inst,3,local_ec,local_5c,inst2,piVar25,*(code **)(*inst + 0xd8)
                            );
                  local_ec[1] = local_ec[3];
                }
                goto LAB_0019a030;
              }
            }
            else {
              local_f0 = a0[0x25];
              loopIndex = a0;
              FUN_00196370(inst,local_f0,a0);
              local_f0 = (**(code **)(*inst + 0xe0))(inst,local_f0);
            }
            goto LAB_0019852c;
          }
          loopRemaining = (**(code **)(*a0 + 0x5c))(a0);
          if (loopRemaining == 0) goto LAB_0019852c;
          if ((piVar22 != (int *)((int)((unsigned char *)0x0) + 3)) ||
             ((bool)((byte)((uint)local_64 >> 0x1d) & 1))) {
            if (bVar1) {
              loopIndex = local_bc;
              loopIndex2 = local_dc;
              a4 = piVar23;
              /* dropped 3 args (found auditing #70 via ExtendIndirectCalls.java /
               * ground-truth disassembly): stock passes loopIndex, loopIndex2, a4 too. */
              (**(code **)(*inst + 0xec))(inst,piVar22,loopIndex,loopIndex2,a4);
            }
            if (bVar2) {
              loopIndex = local_ec;
              loopIndex2 = local_5c;
              a4 = piVar23;
              /* dropped 3 args (found auditing #70 via ExtendIndirectCalls.java /
               * ground-truth disassembly): stock passes loopIndex, loopIndex2, a4 too. */
              (**(code **)(*inst + 0xf0))(inst,piVar22,loopIndex,loopIndex2,a4);
            }
          }
          else {
            local_ec[2] = 0x11;
            loopIndex = local_ec;
            loopIndex2 = local_5c;
            a4 = piVar23;
            (**(code **)(*inst + 0xf0))
                      (inst,1,local_ec,local_5c,piVar23,piVar25,*(code **)(*inst + 0xf0));
          }
          FUN_000f3398(&local_84,piVar23);
          loopIndex3 = local_84 & 0xff;
          bVar3 = (local_84 & 0xffffff00) == 0;
          iVar13 = *(int *)(a0[0x22] + 8);
          loopRemaining = (**(code **)(*a0 + 0x14))
                             (a0,a1,loopIndex,loopIndex2,a4,piVar25,a0[0x22],*(code **)(*a0 + 0x14));
          if (!bVar3) {
            inst[0x20] = loopRemaining * 4 - 2U | inst[0x20];
            (**(code **)(*inst + 0xe4))
                      (inst,*(undefined4 *)(PTR_DAT_001e913c + iVar13 * 0x38 + 0xc),loopIndex,
                       loopIndex2,a4,piVar25,PTR_DAT_001e913c + iVar13 * 0x38);
          }
          bVar4 = -1 < (int)-loopIndex3;
          if (!bVar4) {
            inst[0x21] = loopRemaining * 4 - 2U | inst[0x21];
            (**(code **)(*inst + 0xe8))
                      (inst,*(undefined4 *)(PTR_DAT_001e913c + iVar13 * 0x38 + 0xc),loopIndex,
                       loopIndex2,a4,piVar25,PTR_DAT_001e913c + iVar13 * 0x38);
          }
          if (loopRemaining < 2) {
            if (loopRemaining != 1) goto LAB_0019a030;
            piVar23 = (int *)IRInst__getOperandSource(a0,1);
            if ((((piVar23[0x20] == 0) || (loopRemaining = FUN_00126760(piVar23[0x26]), loopRemaining == 0)) ||
                ((piVar23[5] & 2U) != 0)) ||
               (loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining != 0)) {
              piVar23 = (int *)IRInst__getOperandSource(a0,1);
              loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23);
              if (loopRemaining != 0) goto LAB_001994a8;
              piVar23 = (int *)IRInst__getOperandSource(a0,1);
              iVar13 = 0;
              loopRemaining = (**(code **)(*piVar23 + 0x48))(piVar23);
              if (loopRemaining != 0) {
                loopRemaining = IRInst__getOperandSource(a0,1);
                uVar14 = *(undefined4 *)(loopRemaining + 0x94);
                loopIndex = (int *)IRInst__getOperandSource(a0,1);
                FUN_00196370(inst,uVar14,loopIndex);
                iVar13 = (**(code **)(*inst + 0xe0))(inst,uVar14);
              }
            }
            else {
LAB_001994a8:
              uVar24 = *(undefined4 *)(inst[3] + 0x6c4);
              uVar14 = IRInst__getOperandSource(a0,1);
              iVar13 = thunk_FUN_00134de8(uVar24,uVar14);
            }
            if (!bVar3) {
              loopRemaining = IRInst__getOperandSource(a0,1);
              if ((((((loopRemaining != inst[7]) && (loopRemaining = IRInst__getOperandSource(a0,1), loopRemaining != 0)) &&
                    ((inst[7] != 0 &&
                     ((piVar23 = (int *)IRInst__getOperandSource(a0,1), piVar23[0x20] != 0 &&
                      (loopRemaining = FUN_00126760(piVar23[0x26]), loopRemaining != 0)))))) &&
                   ((piVar23[5] & 2U) == 0)) &&
                  (((loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining == 0 &&
                    (piVar23 = (int *)inst[7], piVar23[0x20] != 0)) &&
                   (loopRemaining = FUN_00126760(piVar23[0x26]), loopRemaining != 0)))) &&
                 ((((piVar23[5] & 2U) == 0 &&
                   (loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining == 0)) &&
                  ((loopRemaining = IRInst__getOperandSource(a0,1), (*(uint *)(loopRemaining + 0x14) & 0x40) != 0 &&
                   ((*(uint *)(inst[7] + 0x14) & 0x40) != 0)))))) {
                IRInst__getOperandSource(a0,1);
              }
              inst[0xe] = iVar13;
            }
            if (!bVar4) {
              loopRemaining = IRInst__getOperandSource(a0,1);
              if (((((loopRemaining != inst[10]) && (loopRemaining = IRInst__getOperandSource(a0,1), loopRemaining != 0)) &&
                   ((inst[10] != 0 &&
                    (((piVar23 = (int *)IRInst__getOperandSource(a0,1), piVar23[0x20] != 0 &&
                      (loopRemaining = FUN_00126760(piVar23[0x26]), loopRemaining != 0)) &&
                     ((piVar23[5] & 2U) == 0)))))) &&
                  ((loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining == 0 &&
                   (piVar23 = (int *)inst[10], piVar23[0x20] != 0)))) &&
                 ((loopRemaining = FUN_00126760(piVar23[0x26]), loopRemaining != 0 &&
                  ((((piVar23[5] & 2U) == 0 &&
                    (loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining == 0)) &&
                   ((loopRemaining = IRInst__getOperandSource(a0,1), (*(uint *)(loopRemaining + 0x14) & 0x40) != 0 &&
                    ((*(uint *)(inst[10] + 0x14) & 0x40) != 0)))))))) {
                IRInst__getOperandSource(a0,1);
              }
              inst[0x12] = iVar13;
            }
          }
          else {
            piVar23 = (int *)IRInst__getOperandSource(a0,1);
            if ((((piVar23[0x20] == 0) || (loopRemaining = FUN_00126760(piVar23[0x26]), loopRemaining == 0)) ||
                ((piVar23[5] & 2U) != 0)) ||
               (loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining != 0)) {
              piVar23 = (int *)IRInst__getOperandSource(a0,1);
              loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23);
              if (loopRemaining != 0) goto LAB_00198950;
              piVar23 = (int *)IRInst__getOperandSource(a0,1);
              iVar11 = 0;
              loopRemaining = (**(code **)(*piVar23 + 0x48))(piVar23);
              if (loopRemaining != 0) {
                loopRemaining = IRInst__getOperandSource(a0,1);
                uVar14 = *(undefined4 *)(loopRemaining + 0x94);
                loopIndex = (int *)IRInst__getOperandSource(a0,1);
                FUN_00196370(inst,uVar14,loopIndex);
                iVar11 = (**(code **)(*inst + 0xe0))(inst,uVar14);
              }
            }
            else {
LAB_00198950:
              uVar24 = *(undefined4 *)(inst[3] + 0x6c4);
              uVar14 = IRInst__getOperandSource(a0,1);
              iVar11 = thunk_FUN_00134de8(uVar24,uVar14);
            }
            piVar23 = (int *)IRInst__getOperandSource(a0,2);
            if (((piVar23[0x20] == 0) || (loopRemaining = FUN_00126760(piVar23[0x26]), loopRemaining == 0)) ||
               (((piVar23[5] & 2U) != 0 ||
                (loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining != 0)))) {
              piVar23 = (int *)IRInst__getOperandSource(a0,2);
              loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23);
              if (loopRemaining != 0) goto LAB_00198a1c;
              piVar23 = (int *)IRInst__getOperandSource(a0,2);
              iVar12 = 0;
              loopRemaining = (**(code **)(*piVar23 + 0x48))(piVar23);
              if (loopRemaining != 0) {
                loopRemaining = IRInst__getOperandSource(a0,2);
                uVar14 = *(undefined4 *)(loopRemaining + 0x94);
                loopIndex = (int *)IRInst__getOperandSource(a0,2);
                FUN_00196370(inst,uVar14,loopIndex);
                iVar12 = (**(code **)(*inst + 0xe0))(inst,uVar14);
              }
            }
            else {
LAB_00198a1c:
              uVar24 = *(undefined4 *)(inst[3] + 0x6c4);
              uVar14 = IRInst__getOperandSource(a0,2);
              iVar12 = thunk_FUN_00134de8(uVar24,uVar14);
            }
            if (bVar3) {
LAB_00198f54:
              bVar3 = false;
            }
            else {
              loopRemaining = IRInst__getOperandSource(a0,1);
              if (((loopRemaining != inst[8]) &&
                  (((((loopRemaining = IRInst__getOperandSource(a0,1), loopRemaining == 0 || (inst[8] == 0)) ||
                     ((piVar23 = (int *)IRInst__getOperandSource(a0,1), piVar23[0x20] == 0 ||
                      (((loopRemaining = FUN_00126760(piVar23[0x26]), loopRemaining == 0 ||
                        ((piVar23[5] & 2U) != 0)) ||
                       (loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining != 0)))))) ||
                    ((piVar23 = (int *)inst[8], piVar23[0x20] == 0 ||
                     (loopRemaining = FUN_00126760(piVar23[0x26]), loopRemaining == 0)))) ||
                   (((piVar23[5] & 2U) != 0 ||
                    (((loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining != 0 ||
                      (loopRemaining = IRInst__getOperandSource(a0,1), (*(uint *)(loopRemaining + 0x14) & 0x40) == 0)) ||
                     (((*(uint *)(inst[8] + 0x14) & 0x40) == 0 ||
                      (loopRemaining = IRInst__getOperandSource(a0,1),
                      *(int *)(loopRemaining + 0x94) != *(int *)(inst[8] + 0x94))))))))))) ||
                 ((loopRemaining = IRInst__getOperandSource(a0,2), loopRemaining != inst[7] &&
                  ((((loopRemaining = IRInst__getOperandSource(a0,2), loopRemaining == 0 || (inst[7] == 0)) ||
                    (piVar23 = (int *)IRInst__getOperandSource(a0,2), piVar23[0x20] == 0)) ||
                   (((loopRemaining = FUN_00126760(piVar23[0x26]), loopRemaining == 0 || ((piVar23[5] & 2U) != 0))
                    || ((((loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining != 0 ||
                          ((piVar23 = (int *)inst[7], piVar23[0x20] == 0 ||
                           (loopRemaining = FUN_00126760(piVar23[0x26]), loopRemaining == 0)))) ||
                         ((piVar23[5] & 2U) != 0)) ||
                        ((((loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining != 0 ||
                           (loopRemaining = IRInst__getOperandSource(a0,2), (*(uint *)(loopRemaining + 0x14) & 0x40) == 0)) ||
                          ((*(uint *)(inst[7] + 0x14) & 0x40) == 0)) ||
                         (loopRemaining = IRInst__getOperandSource(a0,2),
                         *(int *)(loopRemaining + 0x94) != *(int *)(inst[7] + 0x94))))))))))))) {
                loopRemaining = IRInst__getOperandSource(a0,1);
                if (((loopRemaining == inst[7]) ||
                    ((((loopRemaining = IRInst__getOperandSource(a0,1), loopRemaining != 0 && (inst[7] != 0)) &&
                      ((piVar23 = (int *)IRInst__getOperandSource(a0,1), piVar23[0x20] != 0 &&
                       ((loopRemaining = FUN_00126760(piVar23[0x26]), loopRemaining != 0 &&
                        ((piVar23[5] & 2U) == 0)))))) &&
                     (((loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining == 0 &&
                       ((((piVar23 = (int *)inst[7], piVar23[0x20] != 0 &&
                          (loopRemaining = FUN_00126760(piVar23[0x26]), loopRemaining != 0)) &&
                         ((piVar23[5] & 2U) == 0)) &&
                        ((loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining == 0 &&
                         (loopRemaining = IRInst__getOperandSource(a0,1), (*(uint *)(loopRemaining + 0x14) & 0x40) != 0))))))
                      && (((*(uint *)(inst[7] + 0x14) & 0x40) != 0 &&
                          (loopRemaining = IRInst__getOperandSource(a0,1),
                          *(int *)(loopRemaining + 0x94) == *(int *)(inst[7] + 0x94))))))))) &&
                   ((loopRemaining = IRInst__getOperandSource(a0,2), loopRemaining == inst[8] ||
                    (((((loopRemaining = IRInst__getOperandSource(a0,2), loopRemaining != 0 && (inst[8] != 0)) &&
                       ((piVar23 = (int *)IRInst__getOperandSource(a0,2), piVar23[0x20] != 0 &&
                        (((loopRemaining = FUN_00126760(piVar23[0x26]), loopRemaining != 0 &&
                          ((piVar23[5] & 2U) == 0)) &&
                         (loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining == 0)))))) &&
                      ((piVar23 = (int *)inst[8], piVar23[0x20] != 0 &&
                       (loopRemaining = FUN_00126760(piVar23[0x26]), loopRemaining != 0)))) &&
                     (((piVar23[5] & 2U) == 0 &&
                      (((loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining == 0 &&
                        (loopRemaining = IRInst__getOperandSource(a0,2), (*(uint *)(loopRemaining + 0x14) & 0x40) != 0)) &&
                       (((*(uint *)(inst[8] + 0x14) & 0x40) != 0 &&
                        (loopRemaining = IRInst__getOperandSource(a0,2),
                        *(int *)(loopRemaining + 0x94) == *(int *)(inst[8] + 0x94))))))))))))) {
                  inst[0xe] = iVar11;
                  inst[0xf] = iVar12;
                  if ((iVar13 == 0x9a) && (bVar3 = true, (piVar19[8] & 2U) == 0)) goto LAB_00198f58;
                }
                goto LAB_00198f54;
              }
              bVar3 = false;
              inst[0xf] = iVar11;
              inst[0xe] = iVar12;
            }
LAB_00198f58:
            if (bVar4) {
LAB_0019941c:
              bVar4 = false;
            }
            else {
              loopRemaining = IRInst__getOperandSource(a0,1);
              if (((loopRemaining != inst[0xb]) &&
                  (((((((loopRemaining = IRInst__getOperandSource(a0,1), loopRemaining == 0 || (inst[0xb] == 0)) ||
                       (piVar23 = (int *)IRInst__getOperandSource(a0,1), piVar23[0x20] == 0)) ||
                      ((loopRemaining = FUN_00126760(piVar23[0x26]), loopRemaining == 0 ||
                       ((piVar23[5] & 2U) != 0)))) ||
                     (loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining != 0)) ||
                    (((piVar23 = (int *)inst[0xb], piVar23[0x20] == 0 ||
                      (loopRemaining = FUN_00126760(piVar23[0x26]), loopRemaining == 0)) ||
                     (((piVar23[5] & 2U) != 0 ||
                      (((loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining != 0 ||
                        (loopRemaining = IRInst__getOperandSource(a0,1), (*(uint *)(loopRemaining + 0x14) & 0x40) == 0)) ||
                       ((*(uint *)(inst[0xb] + 0x14) & 0x40) == 0)))))))) ||
                   (loopRemaining = IRInst__getOperandSource(a0,1),
                   *(int *)(loopRemaining + 0x94) != *(int *)(inst[0xb] + 0x94))))) ||
                 ((loopRemaining = IRInst__getOperandSource(a0,2), loopRemaining != inst[10] &&
                  ((((loopRemaining = IRInst__getOperandSource(a0,2), loopRemaining == 0 || (inst[10] == 0)) ||
                    ((piVar23 = (int *)IRInst__getOperandSource(a0,2), piVar23[0x20] == 0 ||
                     ((loopRemaining = FUN_00126760(piVar23[0x26]), loopRemaining == 0 || ((piVar23[5] & 2U) != 0)
                      ))))) ||
                   (((loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining != 0 ||
                     (((piVar23 = (int *)inst[10], piVar23[0x20] == 0 ||
                       (loopRemaining = FUN_00126760(piVar23[0x26]), loopRemaining == 0)) ||
                      ((piVar23[5] & 2U) != 0)))) ||
                    (((loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining != 0 ||
                      (loopRemaining = IRInst__getOperandSource(a0,2), (*(uint *)(loopRemaining + 0x14) & 0x40) == 0)) ||
                     (((*(uint *)(inst[10] + 0x14) & 0x40) == 0 ||
                      (loopRemaining = IRInst__getOperandSource(a0,2),
                      *(int *)(loopRemaining + 0x94) != *(int *)(inst[10] + 0x94))))))))))))) {
                loopRemaining = IRInst__getOperandSource(a0,1);
                if (((loopRemaining == inst[10]) ||
                    ((((loopRemaining = IRInst__getOperandSource(a0,1), loopRemaining != 0 && (inst[10] != 0)) &&
                      (((piVar23 = (int *)IRInst__getOperandSource(a0,1), piVar23[0x20] != 0 &&
                        ((((loopRemaining = FUN_00126760(piVar23[0x26]), loopRemaining != 0 &&
                           ((piVar23[5] & 2U) == 0)) &&
                          (loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining == 0)) &&
                         ((piVar23 = (int *)inst[10], piVar23[0x20] != 0 &&
                          (loopRemaining = FUN_00126760(piVar23[0x26]), loopRemaining != 0)))))) &&
                       ((piVar23[5] & 2U) == 0)))) &&
                     (((loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining == 0 &&
                       (loopRemaining = IRInst__getOperandSource(a0,1), (*(uint *)(loopRemaining + 0x14) & 0x40) != 0)) &&
                      (((*(uint *)(inst[10] + 0x14) & 0x40) != 0 &&
                       (loopRemaining = IRInst__getOperandSource(a0,1),
                       *(int *)(loopRemaining + 0x94) == *(int *)(inst[10] + 0x94))))))))) &&
                   ((loopRemaining = IRInst__getOperandSource(a0,2), loopRemaining == inst[0xb] ||
                    (((((loopRemaining = IRInst__getOperandSource(a0,2), loopRemaining != 0 && (inst[0xb] != 0)) &&
                       (piVar23 = (int *)IRInst__getOperandSource(a0,2), piVar23[0x20] != 0)) &&
                      (((loopRemaining = FUN_00126760(piVar23[0x26]), loopRemaining != 0 &&
                        ((piVar23[5] & 2U) == 0)) &&
                       ((loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining == 0 &&
                        ((piVar23 = (int *)inst[0xb], piVar23[0x20] != 0 &&
                         (loopRemaining = FUN_00126760(piVar23[0x26]), loopRemaining != 0)))))))) &&
                     (((piVar23[5] & 2U) == 0 &&
                      ((((loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining == 0 &&
                         (loopRemaining = IRInst__getOperandSource(a0,2), (*(uint *)(loopRemaining + 0x14) & 0x40) != 0)) &&
                        ((*(uint *)(inst[0xb] + 0x14) & 0x40) != 0)) &&
                       (loopRemaining = IRInst__getOperandSource(a0,2),
                       *(int *)(loopRemaining + 0x94) == *(int *)(inst[0xb] + 0x94))))))))))) {
                  inst[0x12] = iVar11;
                  inst[0x13] = iVar12;
                  if ((iVar13 == 0x9a) && (bVar4 = true, (piVar19[8] & 2U) == 0)) goto LAB_00199420;
                }
                goto LAB_0019941c;
              }
              bVar4 = false;
              inst[0x13] = iVar11;
              inst[0x12] = iVar12;
            }
LAB_00199420:
            if ((bVar3) || (bVar4)) {
              loopIndex = (int *)(piVar19[8] & 1U ^ 1);
              IROperand__setModifierBits(piVar19 + 3,1,loopIndex);
            }
          }
        }
LAB_0019a030:
        if (local_7c != 0) {
          if (bVar2) {
            (**(code **)(*inst + 0x10c))(inst,piVar22,local_5c,local_80,iVar20);
          }
          if (bVar1) {
            (**(code **)(*inst + 0x108))(inst,piVar22,local_dc,local_80,iVar20);
          }
          a4 = (int *)inst[3];
          loopIndex2 = (int *)0x0;
          loopIndex = local_80;
          IRInst__setOperandSource(inst2,piVar22,local_80,0,a4);
          if (piVar22 == (int *)0x0) {
            inst2[0x27] = iVar20;
          }
          else {
            loopRemaining = IRInst__getOperandRecord(inst2,piVar22);
            *(int *)(loopRemaining + 0x10) = iVar20;
          }
        }
      }
      piVar22 = (int *)((int)piVar22 + 1);
      piVar19 = piVar19 + 6;
    } while ((int)piVar22 <= iVar8);
  }
  else if (0 < iVar8) goto LAB_00198290;
  (**(code **)(*inst + 0x118))(inst,inst[0x20],inst + 0xd,inst[0x21],inst + 0x11);
  (**(code **)(*inst + 0x11c))
            (inst,inst2,local_6c,local_bc,local_dc,local_70,local_ec,local_5c);
  if (inst2[0x26] == 0x2c) {
LAB_0019a1f4:
    pcVar7 = *(code **)(*inst + 0x124);
  }
  else {
    if ((((inst2[0x20] != 0) && (iVar8 = FUN_00126760(inst2[0x26]), iVar8 != 0)) &&
        (((inst2[5] & 2U) == 0 && (iVar8 = (**(code **)(*inst2 + 0x50))(inst2), iVar8 == 0))))
       || (iVar8 = (**(code **)(*inst2 + 0x50))(inst2), iVar8 != 0)) {
      pcVar7 = *(code **)(*inst + 0x120);
      uVar14 = thunk_FUN_00134de8(*(undefined4 *)(inst[3] + 0x6c4),inst2);
      (*pcVar7)(inst,local_6c,local_70,inst2,uVar14);
      goto LAB_0019a230;
    }
    if ((inst2[5] & 2U) != 0) goto LAB_0019a1f4;
    if ((inst2[5] & 0x80000U) == 0) goto LAB_0019a230;
    pcVar7 = *(code **)(*inst + 0x128);
  }
  (*pcVar7)(inst,local_6c,local_70,inst2);
LAB_0019a230:
  if (uVar6 != 0) {
    (**(code **)(*inst + 300))(inst,local_f8,local_68,inst2);
  }
  if (uVar10 != 0) {
    (**(code **)(*inst + 0x130))(inst,local_f4,local_68,inst2);
  }
  return;
}

/* FUN_0019a2e0 @ 0x19a2e0 (16 bytes) */
int FUN_0019a2e0(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 < param_1) {
    return param_1;
  }
  return param_2;
}

/* FUN_0019a2f0 @ 0x19a2f0 (120 bytes) */
int FUN_0019a2f0(param_1)
  int param_1;
{
  **(undefined4 **)(param_1 + 0x50) =
       *(undefined4 *)(*(int *)(*(int *)(param_1 + 0xc) + 0x30c) + 0x40);
  *(undefined4 *)(*(int *)(param_1 + 0x50) + 0xc) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x10) = *(undefined4 *)(param_1 + 0x58);
  *(int *)(*(int *)(param_1 + 0x50) + 0x14) = *(int *)(param_1 + 0x34) + 1;
  *(int *)(*(int *)(param_1 + 0x50) + 0x18) = *(int *)(param_1 + 0x38) + 1;
  *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x1c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x20) = *(undefined4 *)(param_1 + 0x30);
  *(int *)(*(int *)(param_1 + 0x50) + 0x24) = *(int *)(param_1 + 0x4c) + 1;
  return;
}

/* FUN_0019a368 @ 0x19a368 (28 bytes) */
int FUN_0019a368(param_1)
  int param_1;
{
  *(undefined1 *)(*(int *)(param_1 + 0x58) * 0x10 + *(int *)(param_1 + 0x44) + 3) = 0;
  return;
}

/* FUN_0019a384 @ 0x19a384 (56 bytes) */
int FUN_0019a384(param_1)
  int param_1;
{
  ((int (*)())FUN_0019a368)(param_1);
  *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + 1;
  return;
}

/* FUN_0019a3bc @ 0x19a3bc (172 bytes) */
int FUN_0019a3bc(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x5c) + *(int *)(param_1 + 0x58);
  FUN_000e0e0c(*(undefined4 *)(param_1 + 0xc),
               "Assembler : emits %d cf, %d alu -> %d total instruction(s)\n",
               *(int *)(param_1 + 0x5c),*(int *)(param_1 + 0x58),iVar1,param_6,param_7,param_8);
  FUN_000e0e0c(*(undefined4 *)(param_1 + 0xc),
               "INFO:# of control flow %d, # of exec %d instructions\n",
               *(undefined4 *)(param_1 + 0x5c),*(undefined4 *)(param_1 + 0x58),iVar1,param_6,param_7
               ,param_8);
  if (param_2 == 0) {
    iVar1 = *(int *)(param_1 + 0x78);
    iVar2 = 0;
    if (iVar1 != 0) {
      iVar2 = (*(int *)(param_1 + 0x74) * 100) / iVar1;
    }
    FUN_000e0e0c(*(undefined4 *)(param_1 + 0xc),
                 "Assembler : of %d candidate alu instruction(s), %d are packed (%%%d)\n",iVar1,
                 *(int *)(param_1 + 0x74),iVar2,param_6,param_7,param_8);
    return;
  }
  return;
}

/* FUN_0019a484 @ 0x19a484 (132 bytes) */
int FUN_0019a484(param_1)
  int param_1;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  int loopIndex;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  
  **(undefined4 **)(param_1 + 0x54) = *(undefined4 *)(param_1 + 0x5c);
  if (*(int *)(param_1 + 0x5c) < 1) {
    return;
  }
  loopIndex = 0;
  iVar4 = 0;
  do {
    loopIndex = loopIndex + 1;
    iVar8 = iVar4 + *(int *)(param_1 + 0x40);
    puVar1 = (undefined4 *)(iVar4 + *(int *)(param_1 + 0x40));
    uVar2 = *(undefined4 *)(iVar8 + 4);
    iVar6 = iVar4 + *(int *)(param_1 + 0x54);
    uVar7 = *(undefined4 *)(iVar8 + 8);
    uVar5 = *(undefined4 *)(iVar8 + 0xc);
    iVar4 = iVar4 + 0x1c;
    *(undefined4 *)(iVar6 + 4) = *puVar1;
    *(undefined4 *)(iVar6 + 8) = uVar2;
    *(undefined4 *)(iVar6 + 0xc) = uVar7;
    *(undefined4 *)(iVar6 + 0x10) = uVar5;
    uVar2 = *(undefined4 *)(iVar8 + 0x10);
    uVar5 = *(undefined4 *)(iVar8 + 0x14);
    *(undefined4 *)(iVar6 + 0x1c) = *(undefined4 *)(iVar8 + 0x18);
    *(undefined4 *)(iVar6 + 0x14) = uVar2;
    *(undefined4 *)(iVar6 + 0x18) = uVar5;
  } while (loopIndex < *(int *)(param_1 + 0x5c));
  return;
}

/* FUN_0019a508 @ 0x19a508 (4 bytes) */
int FUN_0019a508()
{
  return;
}

/* FUN_0019a50c @ 0x19a50c (4 bytes) */
int FUN_0019a50c()
{
  return;
}

/* FUN_0019a510 @ 0x19a510 (40 bytes) */
int FUN_0019a510(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x58) * 0x10;
  iVar2 = iVar1 + *(int *)(param_1 + 0x44);
  *(undefined4 *)(iVar1 + *(int *)(param_1 + 0x44)) = 0;
  *(undefined4 *)(iVar2 + 0xc) = 0;
  *(undefined4 *)(iVar2 + 4) = 0;
  *(undefined4 *)(iVar2 + 8) = 0;
  return;
}

/* FUN_0019a538 @ 0x19a538 (48 bytes) */
int FUN_0019a538(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  return *(uint *)(PTR_DAT_001e9140 + *(int *)(*(int *)(param_2 + 0x88) + 8) * 0x38) >> 2 & 1;
}

/* FUN_0019a568 @ 0x19a568 (176 bytes) */
int FUN_0019a568(param_1, param_2)
  int param_1;
  int param_2;
{
  int loopIndex;
  int loopRemaining;
  
  loopRemaining = (param_2 * 5 + *(int *)(param_1 + 0x1c)) * 4;
  loopIndex = *(int *)(&DAT_001e6668 + loopRemaining);
  loopRemaining = *(int *)(&DAT_001e66cc + loopRemaining);
  *(int *)(param_1 + 0x1c) = loopIndex;
  if (loopIndex == -1) {
    *(undefined4 *)(param_1 + 0x1c) = 2;
  }
  else if (loopRemaining < 1) {
    if (loopRemaining < 0) {
      loopRemaining = -loopRemaining;
      loopIndex = *(int *)(param_1 + 0x58);
      do {
        loopIndex = loopIndex + -1;
        loopRemaining = loopRemaining + -1;
      } while (loopRemaining != 0);
      *(int *)(param_1 + 0x58) = loopIndex;
    }
  }
  else {
    loopIndex = 0;
    do {
      loopIndex = loopIndex + 1;
      ((int (*)())FUN_0019a384)(param_1);
    } while (loopIndex != loopRemaining);
  }
  return;
}

/* R300VMachineAssembler__vslot2 @ 0x19a618 (120 bytes) */
int R300VMachineAssembler__vslot2(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 uVar1;
  
  FUN_000e0e0c(*(int *)(param_1 + 0xc),"next_sp = %d, max = %d\n",*(undefined4 *)(param_1 + 0x58),
               *(undefined4 *)(*(int *)(*(int *)(param_1 + 0xc) + 0x30c) + 0x40),param_5,param_6,
               param_7,param_8);
  if ((*(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0x30c) + 0x40) < *(int *)(param_1 + 0x58)) ||
     (uVar1 = 0, 0x10 < *(int *)(param_1 + 0x5c))) {
    uVar1 = 1;
  }
  return uVar1;
}

/* FUN_0019a690 @ 0x19a690 (16 bytes) */
int FUN_0019a690(param_1)
  int param_1;
{
  *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + 1;
  return;
}

/* FUN_0019a6a0 @ 0x19a6a0 (80 bytes) */
int FUN_0019a6a0(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  FUN_000e2c78(param_2,param_1,param_1[3]);
                    
                    
  (**(code **)(*param_1 + 0x88))(param_1,param_2);
  return;
}

/* FUN_0019a6f0 @ 0x19a6f0 (192 bytes) */
int FUN_0019a6f0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 *param_3;
{
  float fVar1;
  
  *param_3 = 0;
  if (3 < param_2) {
    if (param_2 < 6) {
      return 4;
    }
    if (param_2 == 6) {
      return 5;
    }
  }
  fVar1 = *(float *)(param_2 * 0x18 + param_1 + 0x20);
  if (fVar1 == FLOAT_001aa0e8) {
    return 5;
  }
  if ((fVar1 != FLOAT_001aa0d4) && (fVar1 == FLOAT_001aa114)) {
    *param_3 = 1;
    return 5;
  }
  return 4;
}

/* FUN_0019a7b0 @ 0x19a7b0 (92 bytes) */
int FUN_0019a7b0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(param_1 + 8);
  if (((param_2 != 2) && (puVar2 = (undefined4 *)(param_1 + 0xc), param_2 != 3)) &&
     (puVar2 = (undefined4 *)0x0, param_2 == 1)) {
    puVar2 = (undefined4 *)(param_1 + 4);
  }
  puVar1 = (undefined4 *)(param_1 + 8);
  if (((param_3 != 2) && (puVar1 = (undefined4 *)(param_1 + 0xc), param_3 != 3)) &&
     (puVar1 = (undefined4 *)0x0, param_3 == 1)) {
    puVar1 = (undefined4 *)(param_1 + 4);
  }
  *puVar1 = *puVar2;
  return;
}

/* FUN_0019a80c @ 0x19a80c (156 bytes) */
int FUN_0019a80c(param_1, inst, param_3, param_4)
  int *param_1;
  int inst;
  undefined4 param_3;
  undefined4 param_4;
{
  int *a0;
  int callResult;
  
  a0 = (int *)IRInst__getOperandSource(inst,1);
  callResult = (**(code **)(*a0 + 0x50))(a0);
  if ((callResult != 0) && (*(int *)(inst + 0x144) != 0)) {
    return;
  }
                    
                    
  (**(code **)(*param_1 + 0x38))(param_1,inst,param_3,param_4);
  return;
}

/* FUN_0019a8a8 @ 0x19a8a8 (4 bytes) */
int FUN_0019a8a8()
{
  return;
}

/* FUN_0019a8ac @ 0x19a8ac (16 bytes) */
int FUN_0019a8ac(param_1)
  int *param_1;
{
                    
                    
  (**(code **)(*param_1 + 0x38))();
  return;
}

/* FUN_0019a8bc @ 0x19a8bc (16 bytes) */
int FUN_0019a8bc(param_1)
  int *param_1;
{
                    
                    
  (**(code **)(*param_1 + 0x38))();
  return;
}

/* FUN_0019a8d4 @ 0x19a8d4 (128 bytes) */
int FUN_0019a8d4(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  if ((1 < *(int *)(param_2 + 0x130)) && (*(int *)(param_1 + 0x5c) != 0x10)) {
    iVar1 = *(int *)(param_2 + 300);
    *(int *)(param_1 + 0x70) = iVar1;
    *(undefined4 *)(iVar1 * 0xc + *(int *)(param_1 + 0x60)) = *(undefined4 *)(param_1 + 0x58);
    *(undefined4 *)(*(int *)(param_1 + 0x70) * 0xc + *(int *)(param_1 + 0x60) + 8) =
         *(undefined4 *)(param_1 + 0x1c);
    ((int (*)())FUN_0019a568)(param_1,3);
    *(undefined4 *)(param_1 + 100) = 1;
  }
  return;
}

/* FUN_0019a954 @ 0x19a954 (92 bytes) */
int FUN_0019a954(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 100) != 0) {
    ((int (*)())FUN_0019a568)(param_1,3);
    *(undefined4 *)(*(int *)(param_1 + 0x70) * 0xc + *(int *)(param_1 + 0x60) + 4) =
         *(undefined4 *)(param_1 + 0x58);
    *(undefined4 *)(param_1 + 100) = 1;
  }
  return;
}

/* FUN_0019a9b0 @ 0x19a9b0 (44 bytes) */
int FUN_0019a9b0(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_1 + 0x58);
  iVar1 = *(int *)(param_1 + 0x5c) * 0x1c + *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + 1;
  *(undefined4 *)(iVar1 + 0x18) = param_3;
  *(undefined4 *)(iVar1 + 0x10) = uVar2;
  *(undefined4 *)(iVar1 + 0x14) = param_2;
  return;
}

/* FUN_0019a9dc @ 0x19a9dc (160 bytes) */
int FUN_0019a9dc(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  if ((1 < *(int *)(param_2 + 0x130)) && (*(int *)(param_1 + 0x5c) != 0x10)) {
    *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(param_1 + 0x58);
    *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(param_1 + 0x1c);
    iVar1 = *(int *)(param_2 + 300);
    *(int *)(param_1 + 0x70) = iVar1;
    *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(iVar1 * 0xc + *(int *)(param_1 + 0x60));
    ((int (*)())FUN_0019a568)(param_1,4);
    iVar1 = *(int *)(param_1 + 0x70) * 0xc;
    ((int (*)())FUN_0019a9b0)(param_1,*(undefined4 *)(iVar1 + *(int *)(param_1 + 0x60)),
                 *(undefined4 *)(iVar1 + *(int *)(param_1 + 0x60) + 4));
    *(undefined4 *)(param_1 + 100) = 1;
  }
  return;
}

/* FUN_0019aa7c @ 0x19aa7c (92 bytes) */
int FUN_0019aa7c(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 100) != 0) {
    ((int (*)())FUN_0019a568)(param_1,3);
    *(undefined4 *)(param_1 + 0x70) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_1 + 0x68);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x6c);
    *(undefined4 *)(param_1 + 100) = 0;
  }
  return;
}

/* FUN_0019aaf4 @ 0x19aaf4 (100 bytes) */
int FUN_0019aaf4(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int *param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  int callResult;
  
  callResult = (**(code **)(*param_2 + 0x40))(param_2,param_2,param_3,param_4,param_5,param_6);
  if (callResult == 0) {
    Compiler__fail(param_6,0xf);
    return;
  }
  return;
}

/* FUN_0019ab60 @ 0x19ab60 (100 bytes) */
int FUN_0019ab60(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int *param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  int callResult;
  
  callResult = (**(code **)(*param_2 + 0x40))(param_2,param_2,param_3,param_4);
  if (callResult == 0) {
    Compiler__fail(param_4,0xf);
    return;
  }
  return;
}

/* FUN_0019abc4 @ 0x19abc4 (100 bytes) */
int FUN_0019abc4(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  int callResult;
  
  callResult = (**(code **)(**(int **)(param_2 + 300) + 0x40))
                    (*(int **)(param_2 + 300),param_2,param_3,param_4);
  if (callResult == 0) {
    Compiler__fail(param_4,0xf);
    return;
  }
  return;
}

/* FUN_0019ac2c @ 0x19ac2c (120 bytes) */
int FUN_0019ac2c(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  int iVar2;
  
  ((int (*)())FUN_0019a568)(param_1,4);
  iVar2 = *(int *)(param_1 + 0x5c) * 0x1c;
  *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + 1;
  iVar1 = iVar2 + *(int *)(param_1 + 0x40);
  *(undefined4 *)(iVar2 + *(int *)(param_1 + 0x40)) = param_2;
  *(undefined4 *)(iVar1 + 8) = 0x35;
  *(undefined4 *)(iVar1 + 0xc) = param_3;
  iVar2 = *(int *)(param_1 + 0x58);
  *(undefined4 *)(iVar1 + 0x18) = 0;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  *(int *)(iVar1 + 0x10) = iVar2 + -2;
  return;
}

/* FUN_0019aca4 @ 0x19aca4 (4 bytes) */
int FUN_0019aca4()
{
  return;
}

/* FUN_0019acb0 @ 0x19acb0 (328 bytes) */
int FUN_0019acb0(param_1, param_2, param_3, compiler)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  int compiler;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  *(int *)(param_1 + 0xc) = compiler;
  *(undefined4 *)(param_1 + 0x88) = *(undefined4 *)(compiler + 0x30c);
  iVar3 = *(int *)(compiler + 0x324) << 4;
  iVar1 = *(int *)(*(int *)(compiler + 0x30c) + 0x40) << 4;
  if (iVar3 < iVar1) {
    iVar3 = iVar1;
  }
  uVar2 = Arena__alloc(*(undefined4 *)(compiler + 0x374),iVar3);
  *(undefined4 *)(param_1 + 0x44) = uVar2;
  uVar2 = Arena__alloc(*(undefined4 *)(compiler + 0x374),*(int *)(compiler + 0x324) * 0x38);
  *(undefined4 *)(param_1 + 0x40) = uVar2;
  uVar2 = Arena__alloc(*(undefined4 *)(compiler + 0x374),900);
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x54) = uVar2;
  uVar2 = Arena__alloc(*(undefined4 *)(compiler + 0x374),*(int *)(compiler + 0x324) << 3);
  *(undefined4 *)(param_1 + 8) = uVar2;
  uVar2 = FUN_000e14e4(compiler,0x28,param_3);
  *(undefined4 *)(param_1 + 0x50) = uVar2;
  _memset(uVar2,0,0x28);
  **(int **)(param_1 + 0x50) = iVar3;
  *(undefined4 *)(*(int *)(param_1 + 0x50) + 4) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(*(int *)(param_1 + 0x50) + 8) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 0x70) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  return;
}

/* FUN_0019adf8 @ 0x19adf8 (136 bytes) */
int FUN_0019adf8(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_2 == 0) {
    *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x3d4) = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 0xc);
    if (*(int *)(iVar2 + 0x3d4) == 0) {
      *(undefined4 *)(iVar2 + 0x3d4) = 1;
      iVar2 = *(int *)(param_1 + 0xc);
    }
    iVar1 = *(int *)(iVar2 + 0x3d4);
    Arena__free(*(undefined4 *)(iVar2 + 0x374),*(undefined4 *)(param_1 + 0x60));
    uVar3 = Arena__alloc(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x374),iVar1 * 0xc);
    *(undefined4 *)(param_1 + 0x60) = uVar3;
  }
  return;
}

/* FUN_0019ae80 @ 0x19ae80 (104 bytes) */
int FUN_0019ae80(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined4 *)(param_2 + 0xdc));
  UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x9c);
  uVar1 = FUN_000e7d5c(param_2);
                    
                    
  (*UNRECOVERED_JUMPTABLE)(param_1,uVar1,*(undefined4 *)(param_2 + 0x134));
  return;
}

/* FUN_0019aee8 @ 0x19aee8 (88 bytes) */
int FUN_0019aee8(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 param_3;
{
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined4 *)(param_2 + 0xdc));
                    
                    
  (**(code **)(*param_1 + 0xa0))(param_1,0);
  return;
}

/* FUN_0019af40 @ 0x19af40 (252 bytes) */
int FUN_0019af40(param_1, param_2)
  int param_1;
  int *param_2;
{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = param_2[0x4e];
  iVar4 = DList__count(iVar5 + 0x90);
  if ((iVar4 < 3) && (iVar4 = FUN_000e79e8(iVar5), iVar4 != 0)) {
    piVar2 = (int *)0x0;
    if (*(int *)(*(int *)(iVar5 + 0xd0) + 4) != 0) {
      piVar2 = *(int **)(*(int *)(iVar5 + 0xd0) + 8);
    }
    if (*piVar2 == param_2[0x4f]) {
      return;
    }
  }
  iVar4 = (**(code **)(*param_2 + 0x40))(param_2);
  if (iVar4 != 0) {
    piVar2 = (int *)0x0;
    iVar4 = *(int *)(*(int *)(param_1 + 0x10) + 0x24);
    uVar3 = *(uint *)(iVar4 + 4);
    uVar1 = uVar3 - 1;
    if (uVar1 < uVar3) {
      piVar2 = (int *)(uVar1 * 4 + *(int *)(iVar4 + 8));
    }
    iVar4 = *piVar2;
    ((int (*)())FUN_0019a568)(param_1,4);
    *(int *)(iVar4 + 0x14) = *(int *)(param_1 + 0x58) + -2;
    return;
  }
  Compiler__fail(*(undefined4 *)(param_1 + 0xc),0xf);
  return;
}

/* FUN_0019b03c @ 0x19b03c (908 bytes) */
int FUN_0019b03c(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int *param_3;
  undefined4 *param_4;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  uint uVar11;
  int iVar12;
  undefined4 uVar13;
  
  *param_4 = 0;
  piVar4 = (int *)0x0;
  if (param_3 != (int *)0x0) {
    piVar8 = (int *)0x0;
    piVar9 = (int *)0x0;
    bVar2 = false;
    bVar1 = true;
    piVar10 = param_3;
    do {
      uVar11 = piVar10[5];
      if ((uVar11 & 1) != 0) {
        if ((uVar11 & 4) != 0) {
          bVar2 = true;
        }
        iVar3 = ((int (*)())FUN_0019a538)(*(undefined4 *)(param_1 + 0x88),piVar10);
        if (iVar3 == 0) {
          if ((uVar11 & 0x10000) == 0) {
            piVar8 = piVar10;
          }
        }
        else {
          piVar9 = piVar10;
          if (piVar10[0x26] == 1) {
            iVar3 = thunk_FUN_00134de8(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4),piVar10);
            piVar4 = *(int **)(*(int *)(param_1 + 0xc) + 0x30c);
            iVar5 = (**(code **)(*piVar4 + 0x138))(piVar4,0);
            if ((uint)(iVar3 - iVar5) < 4) {
              iVar3 = (**(code **)(*piVar10 + 0x14))(piVar10);
              if (1 < iVar3) {
                iVar3 = IRInst__getOperandSource(piVar10,1);
                iVar5 = *(int *)(iVar3 + 0x94);
                iVar3 = IRInst__getOperandSource(piVar10,2);
                if (iVar5 != *(int *)(iVar3 + 0x94)) goto LAB_0019b168;
              }
              uVar11 = piVar10[5];
              goto LAB_0019b144;
            }
LAB_0019b168:
            uVar11 = piVar10[5];
          }
          bVar1 = false;
        }
      }
LAB_0019b144:
      piVar10 = (int *)piVar10[2];
    } while ((piVar10 != (int *)0x0) && ((uVar11 & 4) != 0));
    piVar4 = param_3;
    if ((piVar8 != (int *)0x0) && (piVar9 != (int *)0x0)) {
      if (bVar1) {
        *param_4 = 1;
      }
      else if (bVar2) {
        *(int *)(*(int *)(param_1 + 0x10) + 0x14) = *(int *)(*(int *)(param_1 + 0x10) + 0x14) + 1;
        piVar4 = (int *)piVar10[1];
        iVar3 = param_3[0x56];
        if (piVar4 == piVar9) {
          *(uint *)(piVar9[1] + 0x14) = *(uint *)(piVar9[1] + 0x14) & 0xfffffffb;
        }
        else {
          piVar9[5] = piVar9[5] & 0xfffffffb;
          DList__unlink(piVar9);
          Block__insertInstAfter(iVar3,piVar4,piVar9);
        }
        for (iVar5 = 1; iVar6 = (**(code **)(*piVar9 + 0x14))(piVar9), piVar4 = piVar8,
            iVar5 <= iVar6; iVar5 = iVar5 + 1) {
          iVar12 = piVar8[0x26];
          iVar6 = IRInst__getOperandSource(piVar9,iVar5);
          if (iVar12 == *(int *)(iVar6 + 0x98)) {
            iVar6 = thunk_FUN_00134de8(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4),piVar8);
            uVar13 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4);
            uVar7 = IRInst__getOperandSource(piVar9,iVar5);
            iVar12 = thunk_FUN_00134de8(uVar13,uVar7);
            if (iVar6 == iVar12) {
              iVar6 = 1;
              piVar4 = (int *)IRInst__create(0x31,*(undefined4 *)(param_1 + 0xc));
              uVar7 = FUN_00130690(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4),0);
              iVar5 = IRInst__getOperandRecord(piVar4,0);
              *(undefined4 *)(iVar5 + 0xc) = 0;
              *(undefined4 *)(iVar5 + 8) = uVar7;
              IRInst__setOperandSource(piVar4,1,piVar8,0,*(undefined4 *)(param_1 + 0xc));
              Block__insertInstBefore(iVar3,piVar8,piVar4);
              *(int *)(*(int *)(param_1 + 0x10) + 0x18) =
                   *(int *)(*(int *)(param_1 + 0x10) + 0x18) + 1;
              if (piVar4 == (int *)0x0) {
                return piVar8;
              }
              for (; iVar3 = (**(code **)(*piVar9 + 0x14))(piVar9), iVar6 <= iVar3;
                  iVar6 = iVar6 + 1) {
                iVar5 = piVar8[0x26];
                iVar3 = IRInst__getOperandSource(piVar9,iVar6);
                if (iVar5 == *(int *)(iVar3 + 0x98)) {
                  iVar3 = thunk_FUN_00134de8(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4),piVar8
                                            );
                  uVar13 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4);
                  uVar7 = IRInst__getOperandSource(piVar9,iVar6);
                  iVar5 = thunk_FUN_00134de8(uVar13,uVar7);
                  if (iVar3 == iVar5) {
                    IRInst__setOperandSource(piVar9,iVar6,piVar4,0,*(undefined4 *)(param_1 + 0xc));
                  }
                }
              }
              return piVar4;
            }
          }
        }
      }
    }
  }
  return piVar4;
}

/* FUN_0019b3c8 @ 0x19b3c8 (728 bytes) */
int FUN_0019b3c8(param_1, param_2)
  int *param_1;
  int param_2;
{
  int *operandVReg;
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int local_38 [9];
  
  piVar5 = *(int **)(param_2 + 8);
  if (piVar5[2] == 0) {
    return;
  }
  do {
    iVar3 = (**(code **)(*param_1 + 8))(param_1);
    if (iVar3 != 0) {
      Compiler__fail(param_1[3],5);
    }
    iVar3 = param_1[3];
    if (**(int **)(iVar3 + 0x6c4) == 0) {
      piVar4 = (int *)FUN_000e3b88(param_1[4],param_2,piVar5,local_38);
      if ((piVar4 == (int *)0x0) || (local_38[0] == 0)) {
        iVar3 = param_1[3];
      }
      else {
        iVar3 = param_1[3];
        piVar5 = piVar4;
      }
    }
    piVar4 = piVar5;
    if (**(int **)(iVar3 + 0x6c4) == 0) {
      piVar4 = (int *)((int (*)())FUN_0019b03c)(param_1,param_2,piVar5,param_1 + 0x1f);
      iVar3 = param_1[3];
    }
    iVar3 = FUN_00106cf8(piVar4,*(undefined4 *)(iVar3 + 0x6c4));
    if ((((iVar3 == 0) || (uVar2 = piVar4[5], (uVar2 & 4) != 0)) || ((int)uVar2 < 0)) ||
       ((uVar2 & 0x1000) != 0)) {
      (**(code **)(*param_1 + 0xbc))(param_1);
      piVar6 = piVar4;
      piVar5 = piVar4;
      do {
        if (piVar5 == (int *)0x0) break;
        uVar2 = piVar6[5];
        if ((uVar2 & 1) != 0) {
          if ((uVar2 & 0x10000) == 0) {
            iVar3 = (**(code **)(*piVar6 + 0x68))(piVar6);
            if (iVar3 != 0) {
              operandVReg = (int *)IRInst__getOperandSource(piVar6,1);
              iVar3 = (**(code **)(*operandVReg + 0x50))(operandVReg);
              if ((iVar3 != 0) && (piVar6[0x51] != 0)) {
                return;
              }
            }
            ((int (*)())FUN_0019a568)(param_1,2);
            (**(code **)(*piVar6 + 0x1c))(piVar6,param_1,0,param_1[3]);
          }
          else {
            iVar3 = (**(code **)(*piVar6 + 0x48))(piVar6);
            if (iVar3 != 0) {
              (**(code **)(*param_1 + 0xc0))(param_1,piVar6,param_1[3]);
            }
          }
          (**(code **)(*piVar6 + 0x20))(piVar6,param_1,0,param_1[3]);
          uVar2 = piVar6[5];
        }
        piVar6 = (int *)piVar6[2];
        piVar5 = (int *)(uVar2 & 4);
      } while (piVar6 != (int *)0x0);
      iVar3 = (**(code **)(*piVar4 + 0x24))(piVar4);
      if (iVar3 == 0) {
        piVar6 = (int *)piVar4[2];
      }
      else {
        (**(code **)(*param_1 + 0xc4))(param_1);
        piVar6 = (int *)piVar4[2];
      }
    }
    else {
      *(int *)(param_1[4] + 0xc) = *(int *)(param_1[4] + 0xc) + 1;
      piVar6 = (int *)piVar4[2];
    }
    do {
      piVar5 = piVar6;
      puVar1 = (uint *)(piVar4 + 5);
      if ((int *)piVar5[2] == (int *)0x0) {
        return;
      }
      piVar6 = (int *)piVar5[2];
      piVar4 = piVar5;
    } while ((*puVar1 & 4) != 0);
  } while( true );
}

/* FUN_0019b6a0 @ 0x19b6a0 (168 bytes) */
int FUN_0019b6a0(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  
  ((int (*)())FUN_0019a568)(param_1,3);
  piVar3 = (int *)0x0;
  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 0x28);
  uVar2 = *(uint *)(iVar1 + 4);
  if (uVar2 - 1 < uVar2) {
    piVar3 = (int *)((uVar2 - 1) * 4 + *(int *)(iVar1 + 8));
  }
  iVar4 = *piVar3;
  Vector__removeAt(iVar1,uVar2 - 1);
  uVar2 = *(uint *)(iVar4 + 0x10);
  *(int *)(iVar4 + 0x18) = *(int *)(param_1 + 0x58) + -2;
  if (uVar2 < *(uint *)(param_1 + 0x2c)) {
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x58) + -1;
    uVar2 = *(uint *)(iVar4 + 0x10);
  }
  if (uVar2 < *(uint *)(param_1 + 0x30)) {
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x58) + -1;
  }
  return;
}

/* FUN_0019b748 @ 0x19b748 (192 bytes) */
int FUN_0019b748(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  
  ((int (*)())FUN_0019a568)(param_1,4);
  iVar1 = *(int *)(param_1 + 0x5c);
  *(int *)(param_1 + 0x5c) = iVar1 + 1;
  iVar5 = iVar1 * 0x1c + *(int *)(param_1 + 0x40);
  *(undefined4 *)(iVar5 + 8) = 0x3e;
  iVar1 = *(int *)(param_1 + 0x58);
  *(undefined4 *)(iVar5 + 0xc) = param_2;
  *(undefined4 *)(iVar5 + 4) = param_3;
  *(int *)(iVar5 + 0x10) = iVar1 + -2;
  puVar4 = *(uint **)(*(int *)(param_1 + 0x10) + 0x28);
  uVar3 = puVar4[1];
  if (uVar3 < *puVar4) {
    _memset(uVar3 * 4 + puVar4[2],0,4);
    piVar2 = (int *)(uVar3 * 4 + puVar4[2]);
    puVar4[1] = uVar3 + 1;
  }
  else {
    piVar2 = (int *)Vector__elementRefGrow(puVar4,uVar3);
  }
  *piVar2 = iVar5;
  return;
}

/* FUN_0019b808 @ 0x19b808 (180 bytes) */
int FUN_0019b808(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = (int *)0x0;
  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 0x24);
  uVar2 = *(uint *)(iVar1 + 4);
  if (uVar2 - 1 < uVar2) {
    piVar3 = (int *)((uVar2 - 1) * 4 + *(int *)(iVar1 + 8));
  }
  iVar4 = *piVar3;
  Vector__removeAt(iVar1,uVar2 - 1);
  *(undefined4 *)(iVar4 + 0x18) = *(undefined4 *)(param_1 + 0x58);
  if (*(int *)(iVar4 + 0x14) == 0) {
    uVar2 = *(uint *)(iVar4 + 0x10);
    *(uint *)(iVar4 + 0x14) = uVar2;
  }
  else {
    uVar2 = *(uint *)(iVar4 + 0x10);
  }
  if (uVar2 < *(uint *)(param_1 + 0x2c)) {
    *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x58);
    uVar2 = *(uint *)(iVar4 + 0x10);
  }
  if (uVar2 < *(uint *)(param_1 + 0x30)) {
    *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 0x58);
  }
  return ((int (*)())FUN_0019a568)(param_1,3);
}

/* FUN_0019b8bc @ 0x19b8bc (96 bytes) */
int FUN_0019b8bc(param_1, compiler)
  undefined4 param_1;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + 0x378);
  allocation = (undefined4 *)Arena__alloc(arena,0x90);
  *allocation = arena;
  allocation[1] = &PTR_FUN_001eb808;
  allocation[7] = 0;
  return allocation + 1;
}

/* MachineAssembler__dtor_19b91c @ 0x19b91c (124 bytes) */
int MachineAssembler__dtor_19b91c(this)
  undefined4 *this;
{
  *this = &PTR_FUN_001eb808;
  Arena__free(*(undefined4 *)(this[3] + 0x374),this[2]);
  this[2] = 0;
  Arena__free(*(undefined4 *)(this[3] + 0x374),this[0x18]);
  this[0x11] = 0;
  *this = PTR_DAT_001e914c + 8;
  return;
}

/* MachineAssembler__dtor_19b9ac @ 0x19b9ac (124 bytes) */
int MachineAssembler__dtor_19b9ac(this)
  undefined4 *this;
{
  *this = &PTR_FUN_001eb808;
  Arena__free(*(undefined4 *)(this[3] + 0x374),this[2]);
  this[2] = 0;
  Arena__free(*(undefined4 *)(this[3] + 0x374),this[0x18]);
  this[0x11] = 0;
  *this = PTR_DAT_001e914c + 8;
  return;
}

/* R300VMachineAssembler__deleting_dtor @ 0x19ba3c (136 bytes) */
int R300VMachineAssembler__deleting_dtor(this)
  undefined4 *this;
{
  undefined *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  *this = &PTR_FUN_001eb808;
  Arena__free(*(undefined4 *)(this[3] + 0x374),this[2]);
  this[2] = 0;
  Arena__free(*(undefined4 *)(this[3] + 0x374),this[0x18]);
  puVar1 = PTR_DAT_001e914c;
  this[0x11] = 0;
  *this = puVar1 + 8;
  if (this == (undefined4 *)0x0) {
    return;
  }
  iVar3 = this[-1];
  if ((*(int *)(iVar3 + 0x28) != 0) &&
     (puVar2 = *(undefined4 **)(iVar3 + 0x14), puVar2 == this + -1)) {
    _memset(puVar2,0,*(int *)(iVar3 + 8) - (int)puVar2);
    *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar3 + 0x14);
  }
  return;
}

/* FUN_0019baf4 @ 0x19baf4 (1596 bytes) */
int FUN_0019baf4(param_1, inst, param_3)
  int param_1;
  int *inst;
  uint *param_3;
{
  int *operandVReg;
  bool bVar1;
  int iVar2;
  undefined1 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int callResult;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  undefined4 uVar16;
  
  piVar4 = *(int **)(*(int *)(param_1 + 0xc) + 0x30c);
  iVar5 = (**(code **)(*piVar4 + 0x16c))(piVar4,inst,param_3);
  iVar2 = *(int *)(inst[0x22] + 8);
  iVar5 = *(int *)(iVar2 * 0x38 + iVar5 + 0xc);
  if (iVar2 == 0x32) {
    uVar15 = param_3[3];
    bVar1 = true;
    uVar12 = param_3[1];
    uVar14 = param_3[2] >> 0x10 & 7;
    uVar13 = uVar12 >> 0xd & 7;
    param_3[1] = uVar14 << 0x16 |
                 uVar14 << 0x13 | uVar14 << 0x10 | uVar14 << 0xd | param_3[2] & 0xfe001fff;
    *(byte *)((int)param_3 + 3) = (byte)iVar5 | 0x40;
    param_3[2] = uVar13 << 0x16 | uVar13 << 0x13 | uVar13 << 0x10 | uVar12 & 0xfe00ffff;
    param_3[3] = (uVar15 & 0xfff81fff) >> 3 & 0x380000 |
                 (uVar15 & 0xffff1fff) >> 6 & 0x70000 | uVar15 >> 9 & 0xe000 | uVar15 & 0xffc01fff;
  }
  else if (iVar5 == -1) {
    if (iVar2 < 0x32) {
      if (iVar2 < 0x30) {
        if (iVar2 == 0x1c) {
          bVar1 = true;
          *(undefined1 *)((int)param_3 + 3) = 1;
          param_3[1] = param_3[1] & 0xfe3fffff | 0x1000000;
          param_3[2] = param_3[2] & 0xfe3fffff | 0x1000000;
        }
        else {
          if (iVar2 != 0x28) goto LAB_0019bc7c;
          uVar12 = param_3[1];
          bVar1 = true;
          *(undefined1 *)((int)param_3 + 3) = 10;
          param_3[1] = param_3[2];
          param_3[2] = uVar12;
        }
      }
      else {
LAB_0019bbfc:
        bVar1 = false;
        *(undefined1 *)((int)param_3 + 3) = 7;
        param_3[2] = param_3[1];
      }
    }
    else {
      if (iVar2 == 0x66) goto LAB_0019bbfc;
      if (iVar2 != 0xa5) goto LAB_0019bc7c;
      bVar1 = true;
      *(undefined1 *)((int)param_3 + 3) = 5;
      param_3[3] = param_3[2];
    }
  }
  else {
    *(byte *)((int)param_3 + 3) = (byte)iVar5;
LAB_0019bc7c:
    bVar1 = true;
  }
  iVar2 = (**(code **)(*inst + 0x14))(inst);
  if (iVar2 != 3) goto LAB_0019bee4;
  operandVReg = (int *)IRInst__getOperandSource(inst,1);
  iVar2 = (**(code **)(*operandVReg + 0x60))(operandVReg);
  if (iVar2 == 0) {
    uVar16 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4);
    uVar6 = IRInst__getOperandSource(inst,1);
    iVar2 = thunk_FUN_00134de8(uVar16,uVar6);
    iVar7 = IRInst__getOperandSource(inst,1);
    iVar7 = *(int *)(iVar7 + 0x98);
  }
  else {
    uVar16 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4);
    uVar6 = IRInst__getOperandSource(inst,1);
    uVar6 = IRInst__getOperandSource(uVar6,1);
    iVar2 = thunk_FUN_00134de8(uVar16,uVar6);
    uVar6 = IRInst__getOperandSource(inst,1);
    iVar7 = IRInst__getOperandSource(uVar6,1);
    iVar7 = *(int *)(iVar7 + 0x98);
  }
  operandVReg = (int *)IRInst__getOperandSource(inst,2);
  callResult = (**(code **)(*operandVReg + 0x60))(operandVReg);
  if (callResult == 0) {
    uVar16 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4);
    uVar6 = IRInst__getOperandSource(inst,2);
    callResult = thunk_FUN_00134de8(uVar16,uVar6);
    iVar9 = IRInst__getOperandSource(inst,2);
    iVar9 = *(int *)(iVar9 + 0x98);
  }
  else {
    uVar16 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4);
    uVar6 = IRInst__getOperandSource(inst,2);
    uVar6 = IRInst__getOperandSource(uVar6,1);
    callResult = thunk_FUN_00134de8(uVar16,uVar6);
    uVar6 = IRInst__getOperandSource(inst,2);
    iVar9 = IRInst__getOperandSource(uVar6,1);
    iVar9 = *(int *)(iVar9 + 0x98);
  }
  operandVReg = (int *)IRInst__getOperandSource(inst,3);
  iVar10 = (**(code **)(*operandVReg + 0x60))(operandVReg);
  if (iVar10 == 0) {
    uVar16 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4);
    uVar6 = IRInst__getOperandSource(inst,3);
    iVar11 = thunk_FUN_00134de8(uVar16,uVar6);
    iVar10 = IRInst__getOperandSource(inst,3);
    iVar10 = *(int *)(iVar10 + 0x98);
  }
  else {
    uVar16 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4);
    uVar6 = IRInst__getOperandSource(inst,3);
    uVar6 = IRInst__getOperandSource(uVar6,1);
    iVar11 = thunk_FUN_00134de8(uVar16,uVar6);
    uVar6 = IRInst__getOperandSource(inst,3);
    iVar10 = IRInst__getOperandSource(uVar6,1);
    iVar10 = *(int *)(iVar10 + 0x98);
  }
  if (((((iVar7 != 0) || (iVar9 != 0)) || (iVar10 != 0)) || ((iVar2 == callResult || (callResult == iVar11))))
     || (iVar2 == iVar11)) goto LAB_0019bee4;
  uVar3 = 0;
  if (iVar5 == 4) {
LAB_0019bed0:
    *(undefined1 *)((int)param_3 + 3) = uVar3;
  }
  else if (iVar5 == 0xb) {
    uVar3 = 1;
    goto LAB_0019bed0;
  }
  *(byte *)((int)param_3 + 3) = (byte)*param_3 | 0x80;
LAB_0019bee4:
  iVar2 = ((int (*)())FUN_0019a538)(*(undefined4 *)(param_1 + 0x88),inst);
  if ((iVar2 != 0) && (bVar1)) {
    *(byte *)((int)param_3 + 3) = (byte)*param_3 | 0x40;
  }
  iVar2 = inst[0x26];
  if ((iVar2 == 5) && (inst[0x25] == 0)) {
    *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x58);
    iVar2 = inst[0x26];
  }
  *param_3 = (*(uint *)(&DAT_001b2ad0 + iVar2 * 4) & 0xf) << 8 | *param_3 & 0xfffff0ff;
  iVar2 = FUN_00105dbc(inst,0);
  if (iVar2 == 1) {
    *(undefined4 *)(param_1 + 0x24) = 1;
    *param_3 = *param_3 | 0x1000;
    uVar13 = FUN_00105c5c(inst,0);
    uVar12 = *param_3;
  }
  else if (iVar2 == 2) {
    uVar13 = 0;
    *(undefined4 *)(param_1 + 0x24) = 1;
    uVar12 = *param_3 & 0x1fffffff | 0x20000000;
    *param_3 = uVar12;
  }
  else {
    uVar12 = *param_3;
    uVar13 = 0;
  }
  if (((uVar12 & 0xf00) == 0x200) || ((uVar12 & 0xf00) == 0x300)) {
    if (iVar2 == 0) {
      uVar13 = uVar13 + inst[0x25];
    }
    else {
      uVar13 = uVar13 + *(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0x6c4) + 0x3f0);
    }
  }
  else if (iVar2 == 0) {
    iVar2 = thunk_FUN_00134de8(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4),inst);
    iVar5 = inst[0x26];
    uVar13 = uVar13 + iVar2;
    if (iVar5 == 1) {
      piVar4 = *(int **)(*(int *)(param_1 + 0xc) + 0x30c);
      iVar2 = (**(code **)(*piVar4 + 0x138))(piVar4,0);
      uVar13 = uVar13 - iVar2;
      uVar6 = ((int (*)())FUN_0019a2e0)(*(undefined4 *)(param_1 + 0x38),uVar13);
      *(undefined4 *)(param_1 + 0x38) = uVar6;
      iVar5 = inst[0x26];
    }
    if (iVar5 == 0) {
      uVar6 = ((int (*)())FUN_0019a2e0)(*(undefined4 *)(param_1 + 0x34),uVar13);
      *(undefined4 *)(param_1 + 0x34) = uVar6;
      uVar12 = *param_3;
    }
    else {
      uVar12 = *param_3;
    }
  }
  *param_3 = (uVar13 & 0x7f) << 0xd | uVar12 & 0xfff01fff;
  iVar2 = IRInst__getOperandRecord(inst,0);
  uVar12 = *(uint *)(iVar2 + 0x10);
  uVar12 = (uint)((uVar12 & 0xff) == 0) << 0x17 |
           (uint)((uVar12 >> 8 & 0xff) == 0) << 0x16 |
           (uint)((uVar12 >> 0x10 & 0xff) == 0) << 0x15 |
           (uint)(uVar12 >> 0x18 == 0) << 0x14 | *param_3 & 0xff0fffff;
  *param_3 = uVar12;
  if (inst[0x48] != 0) {
    iVar2 = ((int (*)())FUN_0019a538)(*(undefined4 *)(param_1 + 0x88),inst);
    if ((iVar2 == 0) || (!bVar1)) {
      *param_3 = uVar12 | 0x1000000;
    }
    else {
      *param_3 = uVar12 | 0x2000000;
    }
  }
  return;
}

/* FUN_0019c130 @ 0x19c130 (2376 bytes) */
int FUN_0019c130(param_1, inst, param_3, param_4, param_5)
  int param_1;
  int inst;
  int param_3;
  int param_4;
  int param_5;
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int *a0;
  int iVar10;
  uint uVar11;
  int loopIndex;
  int iVar13;
  int *piVar14;
  int iVar15;
  int callResult;
  undefined4 uVar17;
  undefined4 in_r8;
  int loopIndex2;
  uint uVar19;
  uint *puVar20;
  undefined8 uVar21;
  uint local_88;
  uint local_84;
  int local_80;
  uint local_7c [4];
  uint local_6c [5];
  uint local_58;
  uint *local_54;
  
  puVar20 = (uint *)(param_3 + 8);
  if (((param_5 != 2) && (puVar20 = (uint *)(param_3 + 0xc), param_5 != 3)) &&
     (puVar20 = (uint *)0x0, param_5 == 1)) {
    puVar20 = (uint *)(param_3 + 4);
  }
  iVar10 = param_3;
  loopIndex2 = param_4;
  a0 = (int *)IRInst__getOperandSource(inst,param_4);
  if (a0[0x26] == 0x33) {
    if (param_4 < 2) {
      *puVar20 = *puVar20 & 0xffffe018;
      *(undefined4 *)(param_1 + 0x80) = 1;
    }
    else {
      uVar6 = *puVar20;
      uVar19 = *(uint *)(param_3 + 4) & 7;
      *puVar20 = uVar19 | uVar6 & 0xfffffff8;
      uVar9 = *(uint *)(param_3 + 4) & 0x10;
      *puVar20 = uVar9 | uVar19 | uVar6 & 0xffffffe8;
      uVar11 = *(uint *)(param_3 + 4) & 0x80000000;
      *puVar20 = uVar11 | uVar9 | uVar19 | uVar6 & 0x7fffffe8;
      uVar8 = *(uint *)(param_3 + 4) & 0x60000000;
      *puVar20 = uVar8 | uVar11 | uVar9 | uVar19 | uVar6 & 0x1fffffe8;
      *puVar20 = *(uint *)(param_3 + 4) & 0x1fe0 |
                 uVar8 | uVar11 | uVar9 | uVar19 | uVar6 & 0x1fffe008;
    }
    iVar10 = IRInst__getOperandRecord(inst,param_4);
    uVar19 = *(uint *)(iVar10 + 0x10);
    uVar9 = *(uint *)(param_4 * 0x18 + inst + 0xa0) & 1;
    iVar10 = ((int (*)())FUN_0019a538)(*(undefined4 *)(param_1 + 0x88),inst);
    if (iVar10 != 0) {
      if (param_4 != 1) {
        uVar19 = uVar19 >> 0x18;
      }
      uVar11 = ((int (*)())FUN_0019a6f0)(a0,uVar19 & 0xff,&local_80);
      uVar6 = *puVar20;
      uVar11 = uVar11 & 7;
      uVar19 = uVar11 << 0xd;
      *puVar20 = uVar19 | uVar6 & 0xffff1fff;
      uVar8 = uVar9 ^ 1;
      if (local_80 == 0) {
        uVar8 = uVar9;
      }
      *puVar20 = uVar8 << 0x19 | uVar19 | uVar6 & 0xfdff1fff;
      *puVar20 = uVar8 << 0x1c |
                 uVar11 << 0x16 |
                 uVar8 << 0x1b |
                 uVar11 << 0x13 |
                 uVar8 << 0x1a | uVar11 << 0x10 | uVar8 << 0x19 | uVar19 | uVar6 & 0xe0001fff;
      return;
    }
    uVar11 = ((int (*)())FUN_0019a6f0)(a0,uVar19 >> 0x18,&local_80);
    uVar6 = *puVar20;
    uVar11 = (uVar11 & 7) << 0xd;
    *puVar20 = uVar11 | uVar6 & 0xffff1fff;
    uVar8 = uVar9 ^ 1;
    if (local_80 == 0) {
      uVar8 = uVar9;
    }
    *puVar20 = uVar8 << 0x19 | uVar11 | uVar6 & 0xfdff1fff;
    uVar11 = ((int (*)())FUN_0019a6f0)(a0,uVar19 >> 0x10 & 0xff,&local_80);
    uVar6 = *puVar20;
    uVar11 = (uVar11 & 7) << 0x10;
    *puVar20 = uVar11 | uVar6 & 0xfff8ffff;
    uVar8 = uVar9 ^ 1;
    if (local_80 == 0) {
      uVar8 = uVar9;
    }
    *puVar20 = uVar8 << 0x1a | uVar11 | uVar6 & 0xfbf8ffff;
    uVar11 = ((int (*)())FUN_0019a6f0)(a0,uVar19 >> 8 & 0xff,&local_80);
    uVar6 = *puVar20;
    uVar11 = (uVar11 & 7) << 0x13;
    *puVar20 = uVar11 | uVar6 & 0xffc7ffff;
    uVar8 = uVar9 ^ 1;
    if (local_80 == 0) {
      uVar8 = uVar9;
    }
    *puVar20 = uVar8 << 0x1b | uVar11 | uVar6 & 0xf7c7ffff;
    uVar19 = ((int (*)())FUN_0019a6f0)(a0,uVar19 & 0xff,&local_80);
    uVar8 = *puVar20;
    uVar19 = (uVar19 & 7) << 0x16;
    *puVar20 = uVar19 | uVar8 & 0xfe3fffff;
    uVar11 = uVar9 ^ 1;
    if (local_80 == 0) {
      uVar11 = uVar9;
    }
    *puVar20 = uVar11 << 0x1c | uVar19 | uVar8 & 0xee3fffff;
    return;
  }
  loopIndex = (**(code **)(*a0 + 0x60))(a0);
  if (loopIndex == 0) {
    loopIndex = FUN_00105dbc(inst,param_4);
    iVar13 = a0[0x26];
    uVar17 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4);
    piVar14 = a0;
LAB_0019c490:
    uVar19 = thunk_FUN_00134de8(uVar17,piVar14);
    *puVar20 = *(uint *)(&DAT_001b2c14 + iVar13 * 4) & 7 | *puVar20 & 0xfffffff8;
    if (iVar13 == 0x37) {
      *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 0x58);
    }
    else if (iVar13 == 1) {
      piVar14 = *(int **)(*(int *)(param_1 + 0xc) + 0x30c);
      iVar15 = (**(code **)(*piVar14 + 0x138))(piVar14,0);
      uVar19 = uVar19 - iVar15;
    }
  }
  else {
    loopIndex = FUN_00105dbc(a0,1);
    iVar13 = IRInst__getOperandSource(a0,1);
    iVar13 = *(int *)(iVar13 + 0x98);
    if (iVar13 != 0x33) {
      uVar17 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4);
      piVar14 = (int *)IRInst__getOperandSource(a0,1);
      goto LAB_0019c490;
    }
    if (param_4 < 2) {
      uVar19 = 0;
      *puVar20 = *puVar20 & 0xfffffff8;
      *(undefined4 *)(param_1 + 0x80) = 1;
    }
    else {
      uVar6 = *puVar20;
      uVar9 = *(uint *)(param_3 + 4) & 7;
      *puVar20 = uVar9 | uVar6 & 0xfffffff8;
      uVar11 = *(uint *)(param_3 + 4) & 0x10;
      uVar19 = *(uint *)(param_3 + 4) >> 5 & 0xff;
      *puVar20 = uVar11 | uVar9 | uVar6 & 0xffffffe8;
      uVar8 = *(uint *)(param_3 + 4) & 0x80000000;
      *puVar20 = uVar8 | uVar11 | uVar9 | uVar6 & 0x7fffffe8;
      *puVar20 = *(uint *)(param_3 + 4) & 0x60000000 | uVar8 | uVar11 | uVar9 | uVar6 & 0x1fffffe8;
    }
  }
  iVar15 = FUN_00126708(a0[0x26]);
  callResult = (**(code **)(*a0 + 0x60))(a0);
  if (callResult != 0) {
    iVar15 = IRInst__getOperandSource(a0,1);
    if (iVar15 == 0) {
      iVar15 = a0[0x2c];
    }
    else {
      iVar15 = IRInst__getOperandSource(a0,1);
      iVar15 = *(int *)(iVar15 + 0x98);
    }
    iVar15 = FUN_00126708(iVar15);
  }
  if ((iVar15 != 0) && (*(uint *)(param_1 + 0x4c) < uVar19)) {
    *(uint *)(param_1 + 0x4c) = uVar19;
  }
  if (loopIndex - 1U < 2) {
    loopIndex = (**(code **)(*a0 + 0x60))(a0);
    if (loopIndex == 0) {
      uVar21 = FUN_00105c5c(inst,param_4);
    }
    else {
      uVar21 = FUN_00105c5c(a0,1);
    }
    uVar19 = (uint)((ulonglong)uVar21 >> 0x20);
    *(undefined4 *)(param_1 + 0x24) = 1;
    if (iVar13 == 0x28) {
      *(undefined4 *)(param_1 + 0x4c) = 0xff;
    }
    else if (iVar13 != 0x29) {
      if (iVar13 == 0x26) {
        *(undefined4 *)(param_1 + 0x4c) = 0xff;
        uVar9 = *puVar20;
        *puVar20 = uVar9 | 0x10;
        iVar10 = (**(code **)(*a0 + 0x60))(a0,(int)uVar21,iVar10,loopIndex2,param_5,in_r8,uVar9 | 0x10);
        if (iVar10 == 0) {
          iVar10 = IRInst__getOperandRecord(a0,1);
          uVar17 = *(undefined4 *)(iVar10 + 0x10);
        }
        else {
          uVar17 = IRInst__getOperandSource(a0,1);
          iVar10 = IRInst__getOperandRecord(uVar17,1);
          uVar17 = *(undefined4 *)(iVar10 + 0x10);
        }
        iVar10 = FUN_000f2d18(uVar17,0);
        if (iVar10 != 0) {
          uVar9 = *puVar20 & 0x9fffffff;
          *puVar20 = uVar9;
          goto LAB_0019c710;
        }
        iVar10 = FUN_000f2d18(uVar17,0x1010101);
        if (iVar10 != 0) {
          uVar9 = *puVar20 & 0x9fffffff | 0x20000000;
          *puVar20 = uVar9;
          goto LAB_0019c710;
        }
        iVar10 = FUN_000f2d18(uVar17,0x2020202);
        if (iVar10 != 0) {
          uVar9 = *puVar20 & 0x9fffffff | 0x40000000;
          *puVar20 = uVar9;
          goto LAB_0019c710;
        }
        iVar10 = FUN_000f2d18(uVar17,0x3030303);
        if (iVar10 != 0) {
          uVar9 = *puVar20 & 0x9fffffff | 0x60000000;
          *puVar20 = uVar9;
          goto LAB_0019c710;
        }
      }
      goto LAB_0019c70c;
    }
    uVar9 = *puVar20 & 0x9fffffff | 0x80000000;
    *puVar20 = uVar9;
  }
  else {
LAB_0019c70c:
    uVar9 = *puVar20;
  }
LAB_0019c710:
  *puVar20 = (uVar19 & 0xff) << 5 | uVar9 & 0xffffe01f;
  uVar19 = *(uint *)(param_4 * 0x18 + inst + 0xa0) & 1;
  iVar10 = IRInst__getOperandRecord(inst,param_4);
  local_88 = *(uint *)(iVar10 + 0x10);
  iVar10 = (**(code **)(*a0 + 0x60))(a0);
  if (iVar10 == 0) {
    local_7c[0] = *(uint *)(&DAT_001b2be8 + (local_88 >> 0x18) * 4);
    local_7c[2] = *(uint *)(&DAT_001b2be8 + (local_88 >> 8 & 0xff) * 4);
    local_7c[3] = *(uint *)(&DAT_001b2be8 + (local_88 & 0xff) * 4);
    local_7c[1] = *(uint *)(&DAT_001b2be8 + (local_88 >> 0x10 & 0xff) * 4);
    local_6c[0] = uVar19;
    local_6c[1] = uVar19;
    local_6c[2] = uVar19;
    local_6c[3] = uVar19;
  }
  else {
    iVar10 = IRInst__getOperandRecord(a0,1);
    local_84 = local_88;
    FUN_000f2bdc(&local_58,*(undefined4 *)(iVar10 + 0x10),local_88);
    local_88 = local_58;
    loopIndex2 = 0;
    iVar10 = 0;
    local_54 = local_7c;
    do {
      bVar2 = *(byte *)((int)&local_84 + loopIndex2);
      if (bVar2 != 4) {
        if ((iVar13 == 0x33) || (bVar3 = *(byte *)((int)&local_88 + loopIndex2), bVar3 == 4)) {
          if (0 < a0[0x21]) {
            loopIndex = 1;
            do {
              iVar15 = IRInst__getOperandRecord(a0,loopIndex);
              uVar9 = (uint)*(byte *)((uint)bVar2 + iVar15 + 0x10);
              if (uVar9 != 4) {
                uVar17 = IRInst__getOperandSource(a0,loopIndex);
                uVar17 = ((int (*)())FUN_0019a6f0)(uVar17,uVar9,&local_80);
                *(undefined4 *)(iVar10 + (int)local_54) = uVar17;
                uVar9 = uVar19;
                if (local_80 != 0) {
                  uVar9 = (uint)(uVar19 == 0);
                }
                *(uint *)((int)local_6c + iVar10) = uVar9;
                break;
              }
              loopIndex = loopIndex + 1;
            } while (loopIndex <= a0[0x21]);
          }
        }
        else {
          *(uint *)((int)local_6c + iVar10) = uVar19;
          *(undefined4 *)(iVar10 + (int)local_7c) = *(undefined4 *)(&DAT_001b2be8 + (uint)bVar3 * 4)
          ;
        }
      }
      bVar1 = loopIndex2 != 3;
      iVar10 = iVar10 + 4;
      loopIndex2 = loopIndex2 + 1;
    } while (bVar1);
  }
  iVar10 = ((int (*)())FUN_0019a538)(*(undefined4 *)(param_1 + 0x88),inst);
  if (iVar10 == 0) {
    uVar7 = *puVar20;
    uVar19 = (local_7c[0] & 7) << 0xd;
    *puVar20 = uVar19 | uVar7 & 0xffff1fff;
    uVar9 = (local_7c[1] & 7) << 0x10;
    *puVar20 = uVar9 | uVar19 | uVar7 & 0xfff81fff;
    uVar11 = (local_7c[2] & 7) << 0x13;
    *puVar20 = uVar11 | uVar9 | uVar19 | uVar7 & 0xffc01fff;
    uVar8 = (local_7c[3] & 7) << 0x16;
    *puVar20 = uVar8 | uVar11 | uVar9 | uVar19 | uVar7 & 0xfe001fff;
    uVar6 = (local_6c[0] & 1) << 0x19;
    *puVar20 = uVar6 | uVar8 | uVar11 | uVar9 | uVar19 | uVar7 & 0xfc001fff;
    uVar4 = (local_6c[1] & 1) << 0x1a;
    *puVar20 = uVar4 | uVar6 | uVar8 | uVar11 | uVar9 | uVar19 | uVar7 & 0xf8001fff;
    uVar5 = (local_6c[2] & 1) << 0x1b;
    *puVar20 = uVar5 | uVar4 | uVar6 | uVar8 | uVar11 | uVar9 | uVar19 | uVar7 & 0xf0001fff;
    uVar19 = (local_6c[3] & 1) << 0x1c |
             uVar5 | uVar4 | uVar6 | uVar8 | uVar11 | uVar9 | uVar19 | uVar7 & 0xe0001fff;
    *puVar20 = uVar19;
  }
  else {
    if (param_4 == 1) {
      uVar9 = *puVar20;
      uVar19 = (local_7c[3] & 7) << 0xd;
      *puVar20 = uVar19 | uVar9 & 0xffff1fff;
      uVar19 = (local_6c[3] & 1) << 0x19 | uVar19 | uVar9 & 0xfdff1fff;
      *puVar20 = uVar19;
    }
    else if (param_4 == 2) {
      uVar9 = *puVar20;
      uVar19 = (local_7c[0] & 7) << 0xd;
      *puVar20 = uVar19 | uVar9 & 0xffff1fff;
      uVar19 = (local_6c[0] & 1) << 0x19 | uVar19 | uVar9 & 0xfdff1fff;
      *puVar20 = uVar19;
    }
    else {
      uVar19 = *puVar20;
    }
    uVar19 = (uVar19 & 0x2000000) << 3 |
             (uVar19 & 0x2000000) << 2 |
             (uVar19 & 0x2000000) << 1 |
             (uVar19 & 0xe000) << 9 |
             (uVar19 & 0xe000) << 6 | (uVar19 & 0xe000) << 3 | uVar19 & 0xe200ffff;
    *puVar20 = uVar19;
  }
  if ((*(int *)(param_1 + 0x84) != 0) && ((uVar19 & 0x80000010) == 0)) {
    uVar9 = *(uint *)(param_3 + 0xc);
    *(uint *)(param_3 + 0xc) = uVar19 & 3 | uVar9 & 0xfffffffc;
    *(uint *)(param_3 + 0xc) = *puVar20 & 0x1fe0 | uVar19 & 3 | uVar9 & 0xffffe01c;
  }
  if ((*(int *)(param_1 + 0x80) != 0) && (param_4 == 2)) {
    uVar8 = *(uint *)(param_3 + 4);
    uVar19 = *puVar20 & 7;
    *(uint *)(param_3 + 4) = uVar19 | uVar8 & 0xfffffff8;
    uVar9 = *puVar20 & 0x1fe0;
    *(uint *)(param_3 + 4) = uVar9 | uVar19 | uVar8 & 0xffffe018;
    uVar11 = *puVar20 & 0x10;
    *(uint *)(param_3 + 4) = uVar11 | uVar9 | uVar19 | uVar8 & 0xffffe008;
    uVar6 = *puVar20;
    *(uint *)(param_3 + 4) = uVar6 & 0x80000000 | uVar11 | uVar9 | uVar19 | uVar8 & 0x7fffe008;
    *(uint *)(param_3 + 4) =
         *puVar20 & 0x60000000 | uVar6 & 0x80000000 | uVar11 | uVar9 | uVar19 | uVar8 & 0x1fffe008;
  }
  return;
}

/* FUN_0019ca78 @ 0x19ca78 (1916 bytes) */
int FUN_0019ca78(param_1, inst, param_3)
  int param_1;
  int *inst;
  uint *param_3;
{
  int *operandVReg;
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int loopIndex;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  int iVar9;
  uint *a2;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  uint uVar10;
  uint *puVar11;
  undefined4 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  int local_48 [4];
  uint local_38;
  uint local_34 [2];
  
  puVar11 = param_3 + 3;
  *param_3 = *param_3 | 0x10000000;
  a2 = param_3;
  FUN_00105dbc(inst,1);
  loopIndex = (**(code **)(*inst + 0x14))(inst);
  if (loopIndex == 2) {
    FUN_00105dbc(inst,2);
  }
  operandVReg = (int *)IRInst__getOperandSource(inst,1);
  loopIndex = (**(code **)(*operandVReg + 0x60))(operandVReg);
  if (loopIndex == 0) {
    loopIndex = operandVReg[0x26];
  }
  else {
    loopIndex = IRInst__getOperandSource(operandVReg,1);
    loopIndex = *(int *)(loopIndex + 0x98);
  }
  if (loopIndex == 0x37) {
    *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 0x58);
  }
  iVar6 = (**(code **)(*operandVReg + 0x60))(operandVReg);
  if (iVar6 == 0) {
    uVar13 = thunk_FUN_00134de8(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4),operandVReg);
  }
  else {
    uVar12 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4);
    uVar7 = IRInst__getOperandSource(operandVReg,1);
    uVar13 = thunk_FUN_00134de8(uVar12,uVar7);
  }
  iVar6 = (int)((ulonglong)uVar13 >> 0x20);
  if (loopIndex == 1) {
    piVar8 = *(int **)(*(int *)(param_1 + 0xc) + 0x30c);
    iVar9 = (**(code **)(*piVar8 + 0x138))(piVar8,0);
    uVar14 = ((int (*)())FUN_0019a2e0)(*(undefined4 *)(param_1 + 0x38),iVar6 - iVar9);
    uVar13 = CONCAT44(iVar6 - iVar9,(int)uVar14);
    *(int *)(param_1 + 0x38) = (int)((ulonglong)uVar14 >> 0x20);
  }
  else if (loopIndex == 0) {
    uVar14 = ((int (*)())FUN_0019a2e0)(*(undefined4 *)(param_1 + 0x34),iVar6);
    uVar13 = CONCAT44(iVar6,(int)uVar14);
    *(int *)(param_1 + 0x34) = (int)((ulonglong)uVar14 >> 0x20);
  }
  uVar3 = (uint)((ulonglong)uVar13 >> 0x20);
  uVar2 = inst[0x2e];
  if ((uVar2 & 2) == 0) {
    uVar10 = *puVar11;
  }
  else {
    uVar10 = *puVar11 | 8;
    *puVar11 = uVar10;
    uVar2 = inst[0x2e];
  }
  if ((uVar2 & 1) != 0) {
    uVar10 = uVar10 | 0x2000000;
    *puVar11 = uVar10;
  }
  if ((inst[0x34] & 1U) != 0) {
    uVar10 = uVar10 | 0x4000000;
    *puVar11 = uVar10;
  }
  if (operandVReg[0x26] == 0x33) {
    uVar2 = param_3[1];
    if ((uVar2 & 0x80000010) == 0) {
      *puVar11 = uVar2 & 3 | uVar10 & 0xfffffffc;
      *puVar11 = param_3[1] & 0x1fe0 | uVar2 & 3 | uVar10 & 0xffffe01c;
    }
    else {
      uVar3 = param_3[2];
      if ((uVar3 & 0x80000010) == 0) {
        *puVar11 = uVar3 & 3 | uVar10 & 0xfffffffc;
        *puVar11 = param_3[2] & 0x1fe0 | uVar3 & 3 | uVar10 & 0xffffe01c;
      }
      else if (((uVar2 & 7) == 0) && ((uVar3 & 7) == 0)) {
        *puVar11 = uVar10 & 0xffffe01c | 2;
      }
      else {
        *puVar11 = uVar10 & 0xffffe01c;
      }
    }
    *(undefined4 *)(param_1 + 0x84) = 1;
    loopIndex = IRInst__getOperandRecord(inst,1);
    uVar2 = ((int (*)())FUN_0019a6f0)(operandVReg,(uint)*(byte *)(loopIndex + 0x13),local_48);
    uVar3 = *puVar11;
    uVar2 = (uVar2 & 7) << 0xd;
    *puVar11 = uVar2 | uVar3 & 0xffff1fff;
    uVar10 = uVar3 >> 0x19 & 1;
    if (local_48[0] != 0) {
      uVar10 = 1 - uVar10;
    }
    *puVar11 = (uVar10 & 1) << 0x19 | uVar2 | uVar3 & 0xfdff1fff;
    loopIndex = (**(code **)(*inst + 0x14))(inst);
    if (1 < loopIndex) {
      uVar7 = IRInst__getOperandSource(inst,2);
      loopIndex = IRInst__getOperandRecord(inst,2);
      uVar2 = ((int (*)())FUN_0019a6f0)(uVar7,(uint)*(byte *)(loopIndex + 0x10),local_48);
      uVar3 = *puVar11;
      uVar2 = (uVar2 & 7) << 0x10;
      *puVar11 = uVar2 | uVar3 & 0xfff8ffff;
      uVar10 = uVar3 >> 0x1a & 1;
      if (local_48[0] != 0) {
        uVar10 = 1 - uVar10;
      }
      *puVar11 = (uVar10 & 1) << 0x1a | uVar2 | uVar3 & 0xfbf8ffff;
    }
    goto LAB_0019d024;
  }
  *puVar11 = *(uint *)(&DAT_001b2c14 + loopIndex * 4) & 3 | uVar10 & 0xfffffffc;
  loopIndex = (**(code **)(*operandVReg + 0x60))(operandVReg,(int)uVar13,a2,in_r6,in_r7,in_r8,loopIndex * 4);
  if (loopIndex == 0) {
    loopIndex = FUN_00126708(operandVReg[0x26]);
  }
  else {
    loopIndex = IRInst__getOperandSource(operandVReg,1);
    loopIndex = FUN_00126708(*(undefined4 *)(loopIndex + 0x98));
  }
  if ((loopIndex != 0) && (*(uint *)(param_1 + 0x4c) < uVar3)) {
    *(uint *)(param_1 + 0x4c) = uVar3;
  }
  *puVar11 = (uVar3 & 0xff) << 5 | *puVar11 & 0xffffe01f;
  loopIndex = IRInst__getOperandRecord(inst,1);
  uVar3 = *(uint *)(loopIndex + 0x10);
  loopIndex = (**(code **)(*inst + 0x14))(inst);
  uVar2 = uVar3;
  if (1 < loopIndex) {
    loopIndex = IRInst__getOperandRecord(inst,2);
    uVar2 = *(uint *)(loopIndex + 0x10);
  }
  loopIndex = (**(code **)(*operandVReg + 0x60))(operandVReg);
  if (loopIndex == 0) {
    loopIndex = (**(code **)(*inst + 0x14))(inst);
    if (loopIndex < 2) {
      uVar3 = *(uint *)(&DAT_001b2be8 + (uVar3 & 0xff) * 4);
      uVar2 = uVar3;
    }
    else {
      uVar3 = *(uint *)(&DAT_001b2be8 + (uVar3 & 0xff) * 4);
      uVar2 = *(uint *)(&DAT_001b2be8 + (uVar2 >> 0x16 & 0x3fc));
    }
  }
  else {
    loopIndex = IRInst__getOperandRecord(operandVReg,1);
    uVar7 = *(undefined4 *)(loopIndex + 0x10);
    FUN_000f2bdc(&local_38,uVar7,uVar3);
    if (((uVar3 & 0xff) == 4) || ((local_38 & 0xff) == 4)) {
      loopIndex = 1;
      if (0 < operandVReg[0x21]) {
        do {
          iVar6 = IRInst__getOperandRecord(operandVReg,loopIndex);
          bVar1 = *(byte *)(iVar6 + 0x13);
          if (bVar1 != 4) {
            uVar12 = IRInst__getOperandSource(operandVReg,loopIndex);
            uVar3 = ((int (*)())FUN_0019a6f0)(uVar12,(uint)bVar1,local_48);
            goto LAB_0019cf10;
          }
          loopIndex = loopIndex + 1;
        } while (loopIndex <= operandVReg[0x21]);
      }
      uVar3 = 0;
    }
    else {
      uVar3 = *(uint *)(&DAT_001b2be8 + (local_38 & 0xff) * 4);
    }
LAB_0019cf10:
    loopIndex = (**(code **)(*inst + 0x14))(inst);
    if (1 < loopIndex) {
      FUN_000f2bdc(local_34,uVar7,uVar2);
      if ((uVar2 >> 0x18 != 4) && (local_34[0] >> 0x18 != 4)) {
        uVar2 = *(uint *)(&DAT_001b2be8 + (local_34[0] >> 0x18) * 4);
        goto LAB_0019d014;
      }
      loopIndex = 1;
      if (0 < operandVReg[0x21]) {
        do {
          iVar6 = IRInst__getOperandRecord(operandVReg,loopIndex);
          bVar1 = *(byte *)(iVar6 + 0x10);
          if (bVar1 != 4) {
            uVar7 = IRInst__getOperandSource(operandVReg,loopIndex);
            uVar2 = ((int (*)())FUN_0019a6f0)(uVar7,(uint)bVar1,local_48);
            goto LAB_0019d014;
          }
          loopIndex = loopIndex + 1;
        } while (loopIndex <= operandVReg[0x21]);
      }
    }
    uVar2 = 0;
  }
LAB_0019d014:
  *puVar11 = (uVar2 & 7) << 0x10 | (uVar3 & 7) << 0xd | *puVar11 & 0xfff81fff;
LAB_0019d024:
  piVar5 = *(int **)(*(int *)(param_1 + 0xc) + 0x30c);
  loopIndex = (**(code **)(*piVar5 + 0x16c))(piVar5);
  uVar2 = *(uint *)(*(int *)(inst[0x22] + 8) * 0x38 + loopIndex + 0xc);
  if (uVar2 == 0xffffffff) {
    if (*(int *)(inst[0x22] + 8) == 0x66) {
      *puVar11 = *puVar11 & 0xfe18ffff | 0x1450000;
    }
  }
  else {
    uVar3 = (uVar2 & 0xf) << 0x15 | *puVar11 & 0xfe1fffff;
    *puVar11 = uVar3;
    if (0xf < (int)uVar2) {
      *puVar11 = uVar3 | 4;
    }
  }
  loopIndex = IRInst__getOperandRecord(inst,0);
  loopIndex = *(int *)(loopIndex + 0x10);
  if (loopIndex == 0x10101) {
    *puVar11 = *puVar11 & 0xe7ffffff;
  }
  else if (loopIndex == 0x1000101) {
    *puVar11 = *puVar11 & 0xe7ffffff | 0x8000000;
  }
  else if (loopIndex == 0x1010001) {
    *puVar11 = *puVar11 & 0xe7ffffff | 0x10000000;
  }
  else if (loopIndex == 0x1010100) {
    *puVar11 = *puVar11 & 0xe7ffffff | 0x18000000;
  }
  loopIndex = thunk_FUN_00134de8(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4),inst);
  piVar5 = *(int **)(*(int *)(param_1 + 0xc) + 0x30c);
  iVar6 = (**(code **)(*piVar5 + 0x138))(piVar5,0);
  *puVar11 = (loopIndex - iVar6) * 0x80000 & 0x180000U | *puVar11 & 0xffe7ffff;
  if (inst[0x48] != 0) {
    piVar5 = *(int **)(*(int *)(param_1 + 0xc) + 0x30c);
    (**(code **)(*piVar5 + 0x80))(piVar5);
    *param_3 = *param_3 | 0x2000000;
  }
  return;
}

/* FUN_0019d1f4 @ 0x19d1f4 (572 bytes) */
int FUN_0019d1f4(param_1, inst)
  int param_1;
  int *inst;
{
  int iVar1;
  int iVar2;
  uint *puVar3;
  
  iVar2 = *(int *)(param_1 + 8);
  iVar1 = *(int *)(param_1 + 0x58) * 8;
  if (*(int *)(iVar2 + iVar1) == 0) {
    *(int **)(iVar2 + iVar1) = inst;
  }
  else {
    *(int **)(iVar2 + iVar1 + 4) = inst;
  }
  puVar3 = (uint *)(*(int *)(param_1 + 0x58) * 0x10 + *(int *)(param_1 + 0x44));
  iVar1 = ((int (*)())FUN_0019a538)(*(undefined4 *)(param_1 + 0x88),inst);
  if ((iVar1 == 0) || (*(int *)(param_1 + 0x7c) == 0)) {
    *(undefined4 *)(param_1 + 0x84) = 0;
    *(undefined4 *)(param_1 + 0x80) = 0;
    iVar1 = (**(code **)(*inst + 0x14))(inst);
    if (0 < iVar1) {
      ((int (*)())FUN_0019c130)(param_1,inst,puVar3,1,1);
    }
    iVar1 = (**(code **)(*inst + 0x14))(inst);
    if (iVar1 < 2) {
      ((int (*)())FUN_0019a7b0)(puVar3,1,2);
    }
    else {
      ((int (*)())FUN_0019c130)(param_1,inst,puVar3,2,2);
    }
    iVar1 = (**(code **)(*inst + 0x14))(inst);
    if (iVar1 < 3) {
      if (*(int *)(param_1 + 0x7c) == 0) {
        ((int (*)())FUN_0019a7b0)(puVar3,2,3);
      }
    }
    else {
      ((int (*)())FUN_0019c130)(param_1,inst,puVar3,3,3);
    }
    ((int (*)())FUN_0019baf4)(param_1,inst,puVar3);
  }
  else {
    iVar1 = (**(code **)(*inst + 0x14))(inst);
    if (1 < iVar1) {
      IRInst__getOperandSource(inst,1);
      IRInst__getOperandSource(inst,2);
    }
    iVar1 = (**(code **)(*inst + 0x14))(inst);
    if (0 < iVar1) {
      iVar1 = IRInst__getOperandRecord(inst,1);
      FUN_000f2c5c(*(undefined4 *)(iVar1 + 0x10));
    }
    ((int (*)())FUN_0019ca78)(param_1,inst,puVar3);
  }
  if (inst[0x47] == 2) {
    *puVar3 = *puVar3 & 0xf7ffffff | 0x4000000;
  }
  else if (inst[0x47] == 3) {
    *puVar3 = *puVar3 | 0xc000000;
  }
  return;
}

/* FUN_0019d430 @ 0x19d430 (68 bytes) */
int FUN_0019d430(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x8c) < 0) {
    uVar1 = FUN_00130690(param_2,0);
    *(undefined4 *)(param_1 + 0x8c) = uVar1;
  }
  return;
}

/* FUN_0019d474 @ 0x19d474 (4 bytes) */
int FUN_0019d474()
{
  return;
}

/* FUN_0019d478 @ 0x19d478 (140 bytes) */
int FUN_0019d478(param_1, param_2, in_r5)
  int param_1;
  int *param_2;
  int in_r5;
{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  if (in_r5 == 0) {
    puVar3 = (undefined4 *)0x0;
    uVar2 = *(uint *)(*(int *)(param_1 + 0x94) + 4);
    uVar1 = uVar2 - 1;
    if (uVar1 < uVar2) {
      puVar3 = (undefined4 *)(uVar1 * 4 + *(int *)(*(int *)(param_1 + 0x94) + 8));
    }
    FUN_000e2bf4(param_2 + 0x24,*puVar3);
  }
                    
                    
  (**(code **)(*param_2 + 0x44))(param_2,*(undefined4 *)(param_1 + 0x10),in_r5);
  return;
}

/* FUN_0019d4e8 @ 0x19d4e8 (116 bytes) */
int FUN_0019d4e8(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 *instAlloc;
  undefined4 arenaAt378;
  
  iVar1 = *(int *)(param_1 + 0x90);
  if (iVar1 == 0) {
    uVar2 = FUN_00130690(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4),0);
    arenaAt378 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x378);
    instAlloc = (undefined4 *)Arena__alloc(arenaAt378,0x168);
    *instAlloc = arenaAt378;
    FUN_00109554(instAlloc + 1,*(undefined4 *)(param_1 + 0xc));
    *(undefined4 **)(param_1 + 0x90) = instAlloc + 1;
    instAlloc[0x27] = 0;
    instAlloc[0x26] = uVar2;
    iVar1 = *(int *)(param_1 + 0x90);
  }
  return iVar1;
}

/* FUN_0019d590 @ 0x19d590 (528 bytes) */
int FUN_0019d590(param_1, param_2, param_3, compiler)
  int param_1;
  int *param_2;
  undefined4 param_3;
  int compiler;
{
  int *newInst;
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  uint *puVar9;
  
  iVar8 = param_2[0x4e];
  iVar4 = DList__count(iVar8 + 0x90);
  if ((iVar4 < 3) && (iVar4 = FUN_000e79e8(iVar8), iVar4 != 0)) {
    piVar7 = (int *)0x0;
    if (*(int *)(*(int *)(iVar8 + 0xd0) + 4) != 0) {
      piVar7 = *(int **)(*(int *)(iVar8 + 0xd0) + 8);
    }
    if (*piVar7 == param_2[0x4f]) {
      return;
    }
  }
  iVar4 = (**(code **)(*param_2 + 0x40))(param_2);
  if (iVar4 == 0) {
    if ((param_2[0x51] == 0) || (*(int *)(*(int *)(param_1 + 0x94) + 4) != 2)) {
      if (**(int **)(compiler + 0x6c4) == 0) {
        newInst = (int *)IRInst__create(0x57,compiler);
        iVar6 = ((int (*)())FUN_0019d4e8)(param_1);
        iVar4 = DAT_001b2d50;
        newInst[0x25] = *(int *)(iVar6 + 0x94);
        newInst[0x27] = iVar4;
        newInst[0x26] = 0;
        IRInst__setOperandSource(newInst,1,iVar6,0,compiler);
        uVar1 = DAT_001b2d4c;
        iVar4 = IRInst__getOperandRecord(newInst,1);
        *(undefined4 *)(iVar4 + 0x10) = uVar1;
        (**(code **)(*newInst + 0x84))(newInst,0);
        Block__prependInst(iVar8,newInst);
        return;
      }
    }
    else {
      Vector__removeAt(*(int *)(param_1 + 0x94),1);
      puVar9 = *(uint **)(param_1 + 0x94);
      uVar2 = puVar9[1];
      if (uVar2 < *puVar9) {
        _memset(uVar2 * 4 + puVar9[2],0,4);
        puVar5 = (undefined4 *)(uVar2 * 4 + puVar9[2]);
        puVar9[1] = uVar2 + 1;
      }
      else {
        puVar5 = (undefined4 *)Vector__elementRefGrow(puVar9,uVar2);
      }
      *puVar5 = 2;
    }
  }
  else {
    piVar7 = (int *)0x0;
    iVar4 = *(int *)(*(int *)(param_1 + 0x10) + 0x24);
    uVar3 = *(uint *)(iVar4 + 4);
    uVar2 = uVar3 - 1;
    if (uVar2 < uVar3) {
      piVar7 = (int *)(uVar2 * 4 + *(int *)(iVar4 + 8));
    }
    iVar4 = *piVar7;
    ((int (*)())FUN_0019a568)(param_1,4);
    *(int *)(iVar4 + 0x14) = *(int *)(param_1 + 0x58) + -2;
  }
  return;
}

/* FUN_0019d7a0 @ 0x19d7a0 (184 bytes) */
int FUN_0019d7a0(param_1, param_2, param_3, compiler)
  int *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 compiler;
{
  int iVar1;
  int *newInst;
  int iVar3;
  
  if (**(int **)(param_2 + 0xac) == 0) {
    iVar1 = ((int (*)())FUN_0019d4e8)(param_1);
    iVar3 = *(int *)(iVar1 + 0x94);
    newInst = (int *)IRInst__create(0x59,compiler);
    iVar1 = DAT_001b2d50;
    newInst[0x25] = iVar3;
    newInst[0x26] = 0;
    newInst[0x27] = iVar1;
    (**(code **)(*newInst + 0x84))(newInst,3);
    Block__appendInst(param_2,newInst);
  }
                    
                    
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined4 *)(param_2 + 0xdc));
  return;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl FUN_00197b30");
asm(".set FUN_00197b30, _FUN_00197b30");
asm(".globl FUN_00197de4");
asm(".set FUN_00197de4, _FUN_00197de4");
asm(".globl FUN_00197ecc");
asm(".set FUN_00197ecc, _FUN_00197ecc");
asm(".globl FUN_00197fb4");
asm(".set FUN_00197fb4, _FUN_00197fb4");
asm(".globl FUN_00198084");
asm(".set FUN_00198084, _FUN_00198084");
asm(".globl FUN_001981ac");
asm(".set FUN_001981ac, _FUN_001981ac");
asm(".globl FUN_0019a2f0");
asm(".set FUN_0019a2f0, _FUN_0019a2f0");
asm(".globl FUN_0019a3bc");
asm(".set FUN_0019a3bc, _FUN_0019a3bc");
asm(".globl FUN_0019a484");
asm(".set FUN_0019a484, _FUN_0019a484");
asm(".globl FUN_0019a510");
asm(".set FUN_0019a510, _FUN_0019a510");
asm(".globl FUN_0019a618");
asm(".set FUN_0019a618, _R300VMachineAssembler__vslot2");
asm(".globl FUN_0019a690");
asm(".set FUN_0019a690, _FUN_0019a690");
asm(".globl FUN_0019a6a0");
asm(".set FUN_0019a6a0, _FUN_0019a6a0");
asm(".globl FUN_0019a80c");
asm(".set FUN_0019a80c, _FUN_0019a80c");
asm(".globl FUN_0019a8a8");
asm(".set FUN_0019a8a8, _FUN_0019a8a8");
asm(".globl FUN_0019a8ac");
asm(".set FUN_0019a8ac, _FUN_0019a8ac");
asm(".globl FUN_0019a8bc");
asm(".set FUN_0019a8bc, _FUN_0019a8bc");
asm(".globl FUN_0019a8d4");
asm(".set FUN_0019a8d4, _FUN_0019a8d4");
asm(".globl FUN_0019a954");
asm(".set FUN_0019a954, _FUN_0019a954");
asm(".globl FUN_0019a9dc");
asm(".set FUN_0019a9dc, _FUN_0019a9dc");
asm(".globl FUN_0019aa7c");
asm(".set FUN_0019aa7c, _FUN_0019aa7c");
asm(".globl FUN_0019aaf4");
asm(".set FUN_0019aaf4, _FUN_0019aaf4");
asm(".globl FUN_0019ab60");
asm(".set FUN_0019ab60, _FUN_0019ab60");
asm(".globl FUN_0019abc4");
asm(".set FUN_0019abc4, _FUN_0019abc4");
asm(".globl FUN_0019ac2c");
asm(".set FUN_0019ac2c, _FUN_0019ac2c");
asm(".globl FUN_0019aca4");
asm(".set FUN_0019aca4, _FUN_0019aca4");
asm(".globl FUN_0019acb0");
asm(".set FUN_0019acb0, _FUN_0019acb0");
asm(".globl FUN_0019adf8");
asm(".set FUN_0019adf8, _FUN_0019adf8");
asm(".globl FUN_0019ae80");
asm(".set FUN_0019ae80, _FUN_0019ae80");
asm(".globl FUN_0019aee8");
asm(".set FUN_0019aee8, _FUN_0019aee8");
asm(".globl FUN_0019af40");
asm(".set FUN_0019af40, _FUN_0019af40");
asm(".globl FUN_0019b3c8");
asm(".set FUN_0019b3c8, _FUN_0019b3c8");
asm(".globl FUN_0019b6a0");
asm(".set FUN_0019b6a0, _FUN_0019b6a0");
asm(".globl FUN_0019b748");
asm(".set FUN_0019b748, _FUN_0019b748");
asm(".globl FUN_0019b808");
asm(".set FUN_0019b808, _FUN_0019b808");
asm(".globl FUN_0019b8bc");
asm(".set FUN_0019b8bc, _FUN_0019b8bc");
asm(".globl FUN_0019b9ac");
asm(".set FUN_0019b9ac, _MachineAssembler__dtor_19b9ac");
asm(".globl FUN_0019ba3c");
asm(".set FUN_0019ba3c, _R300VMachineAssembler__deleting_dtor");
asm(".globl FUN_0019d1f4");
asm(".set FUN_0019d1f4, _FUN_0019d1f4");
asm(".globl FUN_0019d474");
asm(".set FUN_0019d474, _FUN_0019d474");
asm(".globl FUN_0019d478");
asm(".set FUN_0019d478, _FUN_0019d478");
asm(".globl FUN_0019d590");
asm(".set FUN_0019d590, _FUN_0019d590");
asm(".globl FUN_0019d7a0");
asm(".set FUN_0019d7a0, _FUN_0019d7a0");
