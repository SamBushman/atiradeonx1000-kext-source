#include "decls.h"

/* R300MachineAssembler__emitTexRecord @ 0x197b30 (692 bytes) */
int R300MachineAssembler__emitTexRecord(this, inst, unused, compiler)
  int *this;
  int inst;
  undefined4 unused;
  int compiler;
{
  int *operandVReg;
  undefined2 sourceRegister;
  int iVar2;
  int iVar3;
  byte texFlags;
  int irOpcode;
  int iVar7;
  
  operandVReg = (int *)IRInst__getOperandSource(inst,1);
  sourceRegister = thunk_FUN_00134de8(*(undefined4 *)(compiler + 0x6c4),operandVReg);
  iVar2 = (**(code **)(**(int **)(compiler + 0x30c) + 0x7c))(*(int **)(compiler + 0x30c),inst);
  if (iVar2 == 0) {
    IRInst__getOperandRecord(inst,0);
  }
  *(undefined4 *)(this[0x18] * 0x48 + this[0x16]) = 2;
  *(undefined2 *)(this[0x18] * 0x48 + this[0x16] + 0xe) = sourceRegister;
  iVar2 = *(int *)(inst + 0x134);
  irOpcode = *(int *)(*(int *)(inst + 0x88) + 8);
  if (irOpcode != 0x77) {
    *(char *)(this[0x18] * 0x48 + this[0x16] + 0x19) = (char)iVar2;
    iVar7 = this[0x18];
    iVar3 = this[0x16];
    sourceRegister = thunk_FUN_00134de8(*(undefined4 *)(compiler + 0x6c4),inst);
    *(undefined2 *)(iVar7 * 0x48 + iVar3 + 0xc) = sourceRegister;
  }
  else {
    *(undefined2 *)(this[0x18] * 0x48 + this[0x16] + 0xc) = 0;
    *(undefined4 *)(this[0x17] + 0x9370) = 1;
    *(undefined1 *)(this[0x18] * 0x48 + this[0x16] + 0x19) = 0;
  }
  iVar3 = (**(code **)(*operandVReg + 0x80))(operandVReg);
  if (iVar3 == 0) {
    *(undefined4 *)(iVar2 * 4 + this[0x17] + 0x9378) = 1;
  }
  if (*(int *)(PTR_DAT_001e913c + irOpcode * 0x38 + 0xc) != -1) {
    *(char *)(this[0x18] * 0x48 + this[0x16] + 0x1a) =
         (char)*(int *)(PTR_DAT_001e913c + irOpcode * 0x38 + 0xc);
  }
  texFlags = 0xc;
  iVar2 = *(int *)(iVar2 * 0xc + *(int *)(*(int *)(compiler + 0x6c4) + 0x78) + 4);
  if (((iVar2 != 2) && (texFlags = 8, iVar2 != 3)) && (texFlags = 0, iVar2 == 1)) {
    texFlags = 0xe;
  }
  if (irOpcode != 0x77) {
    if (irOpcode - 0x75U < 2) {
      *(byte *)(this[0x18] * 0x48 + this[0x16] + 0x1f) = texFlags & 7;
    }
    else {
      *(byte *)(this[0x18] * 0x48 + this[0x16] + 0x1f) = texFlags;
    }
  }
  else {
    *(undefined1 *)(this[0x18] * 0x48 + this[0x16] + 0x1f) = 0;
  }
  operandVReg = (int *)IRInst__getOperandSource(inst,1);
  iVar2 = (**(code **)(*operandVReg + 0x80))(operandVReg);
  if (iVar2 != 0) {
                    
                    
    (**(code **)(*this + 0x154))(this,1,inst,compiler);
    return;
  }
  return;
}

/* R300MachineAssembler__rgbSelectForLiteralFloat @ 0x197de4 (232 bytes) */
int R300MachineAssembler__rgbSelectForLiteralFloat(this, sourceIndex, selectOut, unused, inst)
  undefined4 this;
  int sourceIndex;
  int selectOut;
  undefined4 unused;
  undefined4 inst;
{
  float literalValue;
  uint laneSelector;
  int operandVReg;
  int loopRemaining;
  int loopIndex;
  undefined4 swizzleWord [9];
  
  operandVReg = IRInst__getOperandSource(inst,sourceIndex);
  loopRemaining = IRInst__getOperandRecord(inst,sourceIndex);
  loopIndex = 0;
  swizzleWord[0] = *(undefined4 *)(loopRemaining + 0x10);
  loopRemaining = 4;
  do {
    laneSelector = (uint)*(byte *)((int)swizzleWord + loopIndex);
    if (laneSelector < 4) goto LAB_00197e50;
    loopIndex = loopIndex + 1;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  laneSelector = 0;
LAB_00197e50:
  literalValue = *(float *)(laneSelector * 0x18 + operandVReg + 0x20);
  if (literalValue == FLOAT_001aa0d4) {
    *(undefined4 *)(sourceIndex * 4 + selectOut) = 0x14;
  }
  else if (literalValue == FLOAT_001aa10c) {
    *(undefined4 *)(sourceIndex * 4 + selectOut) = 0x16;
  }
  else if (literalValue == FLOAT_001aa0e8) {
    *(undefined4 *)(sourceIndex * 4 + selectOut) = 0x15;
  }
  return;
}

/* R300MachineAssembler__alphaSelectForLiteralFloat @ 0x197ecc (232 bytes) */
int R300MachineAssembler__alphaSelectForLiteralFloat(this, sourceIndex, selectOut, unused, inst)
  undefined4 this;
  int sourceIndex;
  int selectOut;
  undefined4 unused;
  undefined4 inst;
{
  float literalValue;
  uint laneSelector;
  int operandVReg;
  int loopRemaining;
  int loopIndex;
  undefined4 swizzleWord [9];
  
  operandVReg = IRInst__getOperandSource(inst,sourceIndex);
  loopRemaining = IRInst__getOperandRecord(inst,sourceIndex);
  loopIndex = 0;
  swizzleWord[0] = *(undefined4 *)(loopRemaining + 0x10);
  loopRemaining = 4;
  do {
    laneSelector = (uint)*(byte *)((int)swizzleWord + loopIndex);
    if (laneSelector < 4) goto LAB_00197f38;
    loopIndex = loopIndex + 1;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  laneSelector = 0;
LAB_00197f38:
  literalValue = *(float *)(laneSelector * 0x18 + operandVReg + 0x20);
  if (literalValue == FLOAT_001aa0d4) {
    *(undefined4 *)(sourceIndex * 4 + selectOut) = 0x10;
  }
  else if (literalValue == FLOAT_001aa10c) {
    *(undefined4 *)(sourceIndex * 4 + selectOut) = 0x12;
  }
  else if (literalValue == FLOAT_001aa0e8) {
    *(undefined4 *)(sourceIndex * 4 + selectOut) = 0x11;
  }
  return;
}

/* R300MachineAssembler__setTempDestination @ 0x197fb4 (208 bytes) */
int R300MachineAssembler__setTempDestination(this, writeRgb, writeAlpha, inst, destRegister)
  int this;
  int writeRgb;
  int writeAlpha;
  undefined4 inst;
  undefined4 destRegister;
{
  int recordBase;
  int operandRecord;
  undefined1 writeMask;
  int recordIndex;
  
  if (writeRgb != 0) {
    *(undefined2 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0xc) =
         (*(unsigned short *)((unsigned char *)&(destRegister) + 2));
    recordIndex = *(int *)(this + 0x60);
    recordBase = *(int *)(this + 0x58);
    operandRecord = IRInst__getOperandRecord(inst,0);
    writeMask = lanesToRgbMask(*(undefined4 *)(operandRecord + 0x10));
    *(undefined1 *)(recordIndex * 0x48 + recordBase + 0x14) = writeMask;
  }
  if (writeAlpha != 0) {
    *(undefined2 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x18) =
         (*(unsigned short *)((unsigned char *)&(destRegister) + 2));
    recordIndex = *(int *)(this + 0x60);
    recordBase = *(int *)(this + 0x58);
    operandRecord = IRInst__getOperandRecord(inst,0);
    *(bool *)(recordIndex * 0x48 + recordBase + 0x20) = *(char *)(operandRecord + 0x13) == '\0';
  }
  return;
}

/* R300MachineAssembler__setOutputDestination @ 0x198084 (296 bytes) */
int R300MachineAssembler__setOutputDestination(this, writeRgb, writeAlpha, inst)
  int this;
  int writeRgb;
  int writeAlpha;
  int inst;
{
  int iVar1;
  undefined1 writeMask;
  int iVar3;
  int iVar4;
  undefined1 outputIndex;
  int destinationClass;
  
  destinationClass = *(int *)(inst + 0x98);
  iVar4 = *(int *)(inst + 0x94);
  if (destinationClass == 9) {
    iVar1 = iVar4 + 1;
    iVar3 = *(int *)(*(int *)(this + 0x5c) + 0x9374);
    if (iVar1 <= iVar3) {
      iVar1 = iVar3;
    }
    *(int *)(*(int *)(this + 0x5c) + 0x9374) = iVar1;
  }
  outputIndex = (undefined1)iVar4;
  if ((writeRgb != 0) && (destinationClass != 8)) {
    *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x16) = outputIndex;
    iVar3 = *(int *)(this + 0x60);
    iVar4 = *(int *)(this + 0x58);
    iVar1 = IRInst__getOperandRecord(inst,0);
    writeMask = lanesToRgbMask(*(undefined4 *)(iVar1 + 0x10));
    *(undefined1 *)(iVar3 * 0x48 + iVar4 + 0x15) = writeMask;
  }
  if (writeAlpha != 0) {
    *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x22) = outputIndex;
    if (destinationClass == 8) {
      *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x23) = 1;
    }
    else {
      iVar1 = *(int *)(this + 0x60);
      iVar4 = *(int *)(this + 0x58);
      destinationClass = IRInst__getOperandRecord(inst,0);
      *(bool *)(iVar1 * 0x48 + iVar4 + 0x21) = *(char *)(destinationClass + 0x13) == '\0';
    }
  }
  return;
}

/* R300MachineAssembler__assembleAluInstruction @ 0x1981ac (8500 bytes) */
int R300MachineAssembler__assembleAluInstruction(this, irInst)
  int *this;
  int *irInst;
{
  undefined4 sourceDef2;
  int *sourceDef;
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
  loopIndex2 = irInst;
  uVar10 = R300MachineAssembler__classifyAluOperation(this,&local_9c,loopIndex,irInst,a4,piVar25);
  local_6c = uVar10 & 1;
  local_70 = uVar10 >> 1 & 1;
  local_68 = *(int *)(irInst[0x22] + 8);
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
  iVar8 = (**(code **)(*irInst + 0x14))(irInst);
  uVar6 = local_6c;
  uVar10 = local_70;
  if (local_68 == 0xb4) {
    iVar8 = 3;
LAB_00198290:
    piVar22 = (int *)((int)((unsigned char *)0x0) + 1);
    piVar19 = irInst + 0x26;
    bVar1 = local_6c != 0;
    bVar2 = local_70 != 0;
    local_64 = (uint)(byte)(((int)local_78 < 0) << 3 | (0 < (int)local_78) << 2 |
                            (local_78 == 0) << 1 | in_xer_so & 1) << 0x1c;
    local_60 = &DAT_001b81b8;
    do {
      loopRemaining = IRInst__getOperandRecord(irInst,piVar22);
      piVar23 = *(int **)(loopRemaining + 0x10);
      local_f0 = -1;
      operandVReg = IRInst__getOperandSource(irInst,piVar22);
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
        loopRemaining = IRInst__getOperandRecord(irInst,piVar22);
        iVar20 = *(int *)(loopRemaining + 0x10);
        FUN_000f2bdc(&local_88,uVar14,iVar20);
        piVar23 = local_88;
        a0 = (int *)IRInst__getOperandSource(local_80,1);
        a4 = (int *)this[3];
        loopIndex2 = (int *)0x0;
        loopIndex = a0;
        IRInst__setOperandSource(irInst,piVar22,a0,0,a4);
        if (piVar22 == (int *)0x0) {
          local_7c = 1;
          irInst[0x27] = (int)piVar23;
        }
        else {
          loopRemaining = IRInst__getOperandRecord(irInst,piVar22);
          *(int **)(loopRemaining + 0x10) = piVar23;
          local_7c = 1;
        }
      }
      loopRemaining = a0[0x26];
      if (loopRemaining != 0x2c) {
        if (loopRemaining == 0x29) {
          loopIndex2 = (int *)this[3];
          loopIndex = piVar22;
          /* dropped 2 args (found auditing #70 via ExtendIndirectCalls.java / ground-truth
           * disassembly): stock passes piVar22 and loopIndex2 (the value just computed above) too. */
          local_f0 = (**(code **)(*this + 0x158))(this,irInst,piVar22,loopIndex2);
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
            loopRemaining = anyEnabledLaneSelectsW(piVar23,uVar14);
            iVar13 = anyEnabledLaneSelectsXyz(piVar23,uVar14);
            local_bc[(int)piVar22] = 0x14;
            piVar15 = piVar22;
            if (loopRemaining == 0) {
              if (iVar13 != 0) {
                loopIndex3 = 1;
                loopIndex2 = this + 0xe;
                loopIndex = this;
                do {
                  piVar25 = (int *)loopIndex[7];
                  a4 = (int *)(loopIndex3 - 1);
                  if ((a0 == piVar25) ||
                     ((((((((piVar25 != (int *)0x0 && (a0 != (int *)0x0)) && (piVar25[0x20] != 0))
                          && ((loopRemaining = RegKind__flagBit0(piVar25[0x26]), loopRemaining != 0 &&
                              ((piVar25[5] & 2U) == 0)))) &&
                         ((loopRemaining = (**(code **)(*piVar25 + 0x50))(piVar25), loopRemaining == 0 &&
                          ((a0[0x20] != 0 && (loopRemaining = RegKind__flagBit0(a0[0x26]), loopRemaining != 0)))))) &&
                        ((a0[5] & 2U) == 0)) &&
                       (((loopRemaining = (**(code **)(*a0 + 0x50))(a0), loopRemaining == 0 &&
                         ((*(uint *)(loopIndex[7] + 0x14) & 0x40) != 0)) && ((a0[5] & 0x40U) != 0))))
                      && (*(int *)(loopIndex[7] + 0x94) == a0[0x25])))) {
                    uVar9 = this[0x20];
                    *loopIndex2 = local_f0;
                    this[0x20] = 1 << (loopIndex3 & 0x3f) | uVar9;
                    goto LAB_00199c88;
                  }
                  bVar4 = loopIndex3 != 3;
                  loopIndex2 = loopIndex2 + 1;
                  loopIndex = loopIndex + 1;
                  loopIndex3 = loopIndex3 + 1;
                } while (bVar4);
                a4 = (int *)((int)((unsigned char *)0x0) + 3);
LAB_00199c88:
                pcVar7 = *(code **)(*this + 0xf8);
                goto joined_r0x00199c90;
              }
            }
            else {
              if (iVar13 == 0) {
                loopIndex3 = 1;
                loopIndex2 = this + 0x12;
                loopIndex = this;
                do {
                  piVar25 = (int *)loopIndex[10];
                  a4 = (int *)(loopIndex3 - 1);
                  if ((a0 == piVar25) ||
                     ((((((piVar25 != (int *)0x0 && (a0 != (int *)0x0)) &&
                         ((piVar25[0x20] != 0 &&
                          ((loopRemaining = RegKind__flagBit0(piVar25[0x26]), loopRemaining != 0 &&
                           ((piVar25[5] & 2U) == 0)))))) &&
                        (loopRemaining = (**(code **)(*piVar25 + 0x50))(piVar25), loopRemaining == 0)) &&
                       (((a0[0x20] != 0 && (loopRemaining = RegKind__flagBit0(a0[0x26]), loopRemaining != 0)) &&
                        ((a0[5] & 2U) == 0)))) &&
                      (((loopRemaining = (**(code **)(*a0 + 0x50))(a0), loopRemaining == 0 &&
                        ((*(uint *)(loopIndex[10] + 0x14) & 0x40) != 0)) &&
                       (((a0[5] & 0x40U) != 0 && (*(int *)(loopIndex[10] + 0x94) == a0[0x25])))))))) {
                    uVar9 = this[0x21];
                    *loopIndex2 = local_f0;
                    this[0x21] = 1 << (loopIndex3 & 0x3f) | uVar9;
                    goto LAB_00199b44;
                  }
                  bVar4 = loopIndex3 != 3;
                  loopIndex2 = loopIndex2 + 1;
                  loopIndex = loopIndex + 1;
                  loopIndex3 = loopIndex3 + 1;
                } while (bVar4);
                a4 = (int *)((int)((unsigned char *)0x0) + 3);
LAB_00199b44:
                pcVar7 = *(code **)(*this + 0xf4);
              }
              else {
                loopIndex3 = 1;
                loopIndex2 = this;
                loopIndex = this;
                do {
                  piVar25 = (int *)loopIndex2[7];
                  a4 = (int *)(loopIndex3 - 1);
                  if (((a0 == piVar25) ||
                      ((((piVar25 != (int *)0x0 && (a0 != (int *)0x0)) &&
                        ((piVar25[0x20] != 0 &&
                         ((((((loopRemaining = RegKind__flagBit0(piVar25[0x26]), loopRemaining != 0 &&
                              ((piVar25[5] & 2U) == 0)) &&
                             (loopRemaining = (**(code **)(*piVar25 + 0x50))(piVar25), loopRemaining == 0)) &&
                            ((a0[0x20] != 0 && (loopRemaining = RegKind__flagBit0(a0[0x26]), loopRemaining != 0)))) &&
                           ((a0[5] & 2U) == 0)) &&
                          ((loopRemaining = (**(code **)(*a0 + 0x50))(a0), loopRemaining == 0 &&
                           ((*(uint *)(loopIndex2[7] + 0x14) & 0x40) != 0)))))))) &&
                       (((a0[5] & 0x40U) != 0 && (*(int *)(loopIndex2[7] + 0x94) == a0[0x25])))))) &&
                     ((piVar25 = (int *)loopIndex2[10], a0 == piVar25 ||
                      ((((((piVar25 != (int *)0x0 && (a0 != (int *)0x0)) && (piVar25[0x20] != 0)) &&
                         ((loopRemaining = RegKind__flagBit0(piVar25[0x26]), loopRemaining != 0 &&
                          ((piVar25[5] & 2U) == 0)))) &&
                        (((loopRemaining = (**(code **)(*piVar25 + 0x50))(piVar25), loopRemaining == 0 &&
                          ((a0[0x20] != 0 && (loopRemaining = RegKind__flagBit0(a0[0x26]), loopRemaining != 0)))) &&
                         ((a0[5] & 2U) == 0)))) &&
                       ((((loopRemaining = (**(code **)(*a0 + 0x50))(a0), loopRemaining == 0 &&
                          ((*(uint *)(loopIndex2[10] + 0x14) & 0x40) != 0)) && ((a0[5] & 0x40U) != 0))
                        && (*(int *)(loopIndex2[10] + 0x94) == a0[0x25])))))))) {
                    uVar18 = this[0x20];
                    uVar9 = this[0x21];
                    loopIndex3 = 1 << (loopIndex3 & 0x3f);
                    loopIndex[0x12] = local_f0;
                    this[0x20] = loopIndex3 | uVar18;
                    this[0x21] = loopIndex3 | uVar9;
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
                (**(code **)(*this + 0xf4))(this,piVar22,local_bc,local_dc,a4,piVar23);
                pcVar7 = *(code **)(*this + 0xf8);
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
              (*pcVar7)(this,piVar15,loopIndex,loopIndex2,a4,piVar23);
              piVar25 = piVar23;
            }
          }
LAB_00199cdc:
          if (bVar2) {
            loopRemaining = IRInst__getOperandRecord(irInst,piVar22);
            piVar23 = *(int **)(loopRemaining + 0x10);
            loopRemaining = local_ac;
            if ((bVar3) && (local_74 != 0)) {
              loopRemaining = local_a8;
            }
            iVar13 = anyEnabledLaneSelectsW(piVar23,loopRemaining);
            loopRemaining = anyEnabledLaneSelectsXyz(piVar23,loopRemaining);
            local_ec[(int)piVar22] = 0x10;
            if (iVar13 != 0) {
              loopIndex3 = 1;
              loopIndex2 = this + 0x12;
              loopIndex = this;
              do {
                piVar25 = (int *)loopIndex[10];
                a4 = (int *)(loopIndex3 - 1);
                if ((a0 == piVar25) ||
                   ((((piVar25 != (int *)0x0 && (a0 != (int *)0x0)) &&
                     ((piVar25[0x20] != 0 &&
                      ((((iVar13 = RegKind__flagBit0(piVar25[0x26]), iVar13 != 0 &&
                         ((piVar25[5] & 2U) == 0)) &&
                        (iVar13 = (**(code **)(*piVar25 + 0x50))(piVar25), iVar13 == 0)) &&
                       ((a0[0x20] != 0 && (iVar13 = RegKind__flagBit0(a0[0x26]), iVar13 != 0)))))))) &&
                    ((((a0[5] & 2U) == 0 &&
                      ((iVar13 = (**(code **)(*a0 + 0x50))(a0), iVar13 == 0 &&
                       ((*(uint *)(loopIndex[10] + 0x14) & 0x40) != 0)))) &&
                     (((a0[5] & 0x40U) != 0 && (*(int *)(loopIndex[10] + 0x94) == a0[0x25])))))))) {
                  uVar9 = this[0x21];
                  *loopIndex2 = local_f0;
                  this[0x21] = 1 << (loopIndex3 & 0x3f) | uVar9;
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
              (**(code **)(*this + 0xfc))(this,piVar15,loopIndex,loopIndex2,a4,piVar25);
            }
            if (loopRemaining != 0) {
              loopIndex3 = 1;
              loopIndex2 = this + 0xe;
              loopIndex = this;
              do {
                piVar25 = (int *)loopIndex[7];
                a4 = (int *)(loopIndex3 - 1);
                if ((a0 == piVar25) ||
                   (((((piVar25 != (int *)0x0 && (a0 != (int *)0x0)) && (piVar25[0x20] != 0)) &&
                     ((((loopRemaining = RegKind__flagBit0(piVar25[0x26]), loopRemaining != 0 &&
                        ((piVar25[5] & 2U) == 0)) &&
                       ((loopRemaining = (**(code **)(*piVar25 + 0x50))(piVar25), loopRemaining == 0 &&
                        ((a0[0x20] != 0 && (loopRemaining = RegKind__flagBit0(a0[0x26]), loopRemaining != 0)))))) &&
                      ((a0[5] & 2U) == 0)))) &&
                    ((((loopRemaining = (**(code **)(*a0 + 0x50))(a0), loopRemaining == 0 &&
                       ((*(uint *)(loopIndex[7] + 0x14) & 0x40) != 0)) && ((a0[5] & 0x40U) != 0)) &&
                     (*(int *)(loopIndex[7] + 0x94) == a0[0x25])))))) {
                  uVar9 = this[0x20];
                  *loopIndex2 = local_f0;
                  this[0x20] = 1 << (loopIndex3 & 0x3f) | uVar9;
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
              (**(code **)(*this + 0x100))(this,piVar25,loopIndex,loopIndex2,a4,piVar23);
              piVar25 = piVar23;
            }
          }
        }
        else {
          if ((((a0[0x20] != 0) && (loopRemaining = RegKind__flagBit0(loopRemaining), loopRemaining != 0)) &&
              ((a0[5] & 2U) == 0)) && (loopRemaining = (**(code **)(*a0 + 0x50))(a0), loopRemaining == 0)) {
            local_f0 = FUN_00134de8(*(undefined4 *)(this[3] + 0x6c4),a0);
            loopRemaining = (**(code **)(*a0 + 0x80))(a0);
            if (loopRemaining != 0) {
              loopIndex2 = (int *)this[3];
              loopIndex = irInst;
              /* dropped 2 args (found auditing #70 via ExtendIndirectCalls.java / ground-truth
               * disassembly): stock passes irInst and loopIndex2 too. */
              (**(code **)(*this + 0x154))(this,piVar22,irInst,loopIndex2);
            }
            goto LAB_0019852c;
          }
          loopRemaining = (**(code **)(*a0 + 0x50))(a0);
          if (loopRemaining != 0) {
            local_f0 = thunk_FUN_00134de8(*(undefined4 *)(this[3] + 0x6c4),a0);
            goto LAB_0019852c;
          }
          loopRemaining = (**(code **)(*a0 + 0x48))(a0);
          if (loopRemaining != 0) {
            if (a0[0x26] == 0x33) {
              loopIndex = &local_f0;
              /* dropped 1 arg (found auditing #70 via ExtendIndirectCalls.java / ground-truth
               * disassembly): stock passes &local_f0 (loopIndex) too. */
              loopRemaining = (**(code **)(*this + 0xdc))(this,a0,loopIndex);
              if (loopRemaining == 0) {
                if ((piVar22 != (int *)((int)((unsigned char *)0x0) + 3)) ||
                   ((bool)((byte)((uint)local_64 >> 0x1d) & 1))) {
                  if (bVar1) {
                    loopIndex = local_bc;
                    loopIndex2 = local_dc;
                    a4 = irInst;
                    /* dropped 3 args (found auditing #70 via ExtendIndirectCalls.java /
                     * ground-truth disassembly): stock passes loopIndex, loopIndex2, a4 too. */
                    (**(code **)(*this + 0xd4))(this,piVar22,loopIndex,loopIndex2,a4);
                  }
                  if (bVar2) {
                    loopIndex = local_ec;
                    loopIndex2 = local_5c;
                    a4 = irInst;
                    /* dropped 3 args (found auditing #70 via ExtendIndirectCalls.java /
                     * ground-truth disassembly): stock passes loopIndex, loopIndex2, a4 too. */
                    (**(code **)(*this + 0xd8))(this,piVar22,loopIndex,loopIndex2,a4);
                  }
                }
                else {
                  local_ec[2] = 0x11;
                  loopIndex = local_ec;
                  loopIndex2 = local_5c;
                  a4 = irInst;
                  (**(code **)(*this + 0xd8))
                            (this,3,local_ec,local_5c,irInst,piVar25,*(code **)(*this + 0xd8)
                            );
                  local_ec[1] = local_ec[3];
                }
                goto LAB_0019a030;
              }
            }
            else {
              local_f0 = a0[0x25];
              loopIndex = a0;
              R300MachineAssembler__trackMaxLevelAndAssemble(this,local_f0,a0);
              local_f0 = (**(code **)(*this + 0xe0))(this,local_f0);
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
              (**(code **)(*this + 0xec))(this,piVar22,loopIndex,loopIndex2,a4);
            }
            if (bVar2) {
              loopIndex = local_ec;
              loopIndex2 = local_5c;
              a4 = piVar23;
              /* dropped 3 args (found auditing #70 via ExtendIndirectCalls.java /
               * ground-truth disassembly): stock passes loopIndex, loopIndex2, a4 too. */
              (**(code **)(*this + 0xf0))(this,piVar22,loopIndex,loopIndex2,a4);
            }
          }
          else {
            local_ec[2] = 0x11;
            loopIndex = local_ec;
            loopIndex2 = local_5c;
            a4 = piVar23;
            (**(code **)(*this + 0xf0))
                      (this,1,local_ec,local_5c,piVar23,piVar25,*(code **)(*this + 0xf0));
          }
          FUN_000f3398(&local_84,piVar23);
          loopIndex3 = local_84 & 0xff;
          bVar3 = (local_84 & 0xffffff00) == 0;
          iVar13 = *(int *)(a0[0x22] + 8);
          loopRemaining = (**(code **)(*a0 + 0x14))
                             (a0,a1,loopIndex,loopIndex2,a4,piVar25,a0[0x22],*(code **)(*a0 + 0x14));
          if (!bVar3) {
            this[0x20] = loopRemaining * 4 - 2U | this[0x20];
            (**(code **)(*this + 0xe4))
                      (this,*(undefined4 *)(PTR_DAT_001e913c + iVar13 * 0x38 + 0xc),loopIndex,
                       loopIndex2,a4,piVar25,PTR_DAT_001e913c + iVar13 * 0x38);
          }
          bVar4 = -1 < (int)-loopIndex3;
          if (!bVar4) {
            this[0x21] = loopRemaining * 4 - 2U | this[0x21];
            (**(code **)(*this + 0xe8))
                      (this,*(undefined4 *)(PTR_DAT_001e913c + iVar13 * 0x38 + 0xc),loopIndex,
                       loopIndex2,a4,piVar25,PTR_DAT_001e913c + iVar13 * 0x38);
          }
          if (loopRemaining < 2) {
            if (loopRemaining != 1) goto LAB_0019a030;
            piVar23 = (int *)IRInst__getOperandSource(a0,1);
            if ((((piVar23[0x20] == 0) || (loopRemaining = RegKind__flagBit0(piVar23[0x26]), loopRemaining == 0)) ||
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
                R300MachineAssembler__trackMaxLevelAndAssemble(this,uVar14,loopIndex);
                iVar13 = (**(code **)(*this + 0xe0))(this,uVar14);
              }
            }
            else {
LAB_001994a8:
              uVar24 = *(undefined4 *)(this[3] + 0x6c4);
              sourceDef2 = IRInst__getOperandSource(a0,1);
              iVar13 = thunk_FUN_00134de8(uVar24,sourceDef2);
            }
            if (!bVar3) {
              loopRemaining = IRInst__getOperandSource(a0,1);
              if ((((((loopRemaining != this[7]) && (loopRemaining = IRInst__getOperandSource(a0,1), loopRemaining != 0)) &&
                    ((this[7] != 0 &&
                     ((piVar23 = (int *)IRInst__getOperandSource(a0,1), piVar23[0x20] != 0 &&
                      (loopRemaining = RegKind__flagBit0(piVar23[0x26]), loopRemaining != 0)))))) &&
                   ((piVar23[5] & 2U) == 0)) &&
                  (((loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining == 0 &&
                    (piVar23 = (int *)this[7], piVar23[0x20] != 0)) &&
                   (loopRemaining = RegKind__flagBit0(piVar23[0x26]), loopRemaining != 0)))) &&
                 ((((piVar23[5] & 2U) == 0 &&
                   (loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining == 0)) &&
                  ((loopRemaining = IRInst__getOperandSource(a0,1), (*(uint *)(loopRemaining + 0x14) & 0x40) != 0 &&
                   ((*(uint *)(this[7] + 0x14) & 0x40) != 0)))))) {
                IRInst__getOperandSource(a0,1);
              }
              this[0xe] = iVar13;
            }
            if (!bVar4) {
              loopRemaining = IRInst__getOperandSource(a0,1);
              if (((((loopRemaining != this[10]) && (loopRemaining = IRInst__getOperandSource(a0,1), loopRemaining != 0)) &&
                   ((this[10] != 0 &&
                    (((piVar23 = (int *)IRInst__getOperandSource(a0,1), piVar23[0x20] != 0 &&
                      (loopRemaining = RegKind__flagBit0(piVar23[0x26]), loopRemaining != 0)) &&
                     ((piVar23[5] & 2U) == 0)))))) &&
                  ((loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining == 0 &&
                   (piVar23 = (int *)this[10], piVar23[0x20] != 0)))) &&
                 ((loopRemaining = RegKind__flagBit0(piVar23[0x26]), loopRemaining != 0 &&
                  ((((piVar23[5] & 2U) == 0 &&
                    (loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining == 0)) &&
                   ((loopRemaining = IRInst__getOperandSource(a0,1), (*(uint *)(loopRemaining + 0x14) & 0x40) != 0 &&
                    ((*(uint *)(this[10] + 0x14) & 0x40) != 0)))))))) {
                IRInst__getOperandSource(a0,1);
              }
              this[0x12] = iVar13;
            }
          }
          else {
            sourceDef = (int *)IRInst__getOperandSource(a0,1);
            if ((((sourceDef[0x20] == 0) || (loopRemaining = RegKind__flagBit0(sourceDef[0x26]), loopRemaining == 0)) ||
                ((sourceDef[5] & 2U) != 0)) ||
               (loopRemaining = (**(code **)(*sourceDef + 0x50))(sourceDef), loopRemaining != 0)) {
              sourceDef = (int *)IRInst__getOperandSource(a0,1);
              loopRemaining = (**(code **)(*sourceDef + 0x50))(sourceDef);
              if (loopRemaining != 0) goto LAB_00198950;
              sourceDef = (int *)IRInst__getOperandSource(a0,1);
              iVar11 = 0;
              loopRemaining = (**(code **)(*sourceDef + 0x48))(sourceDef);
              if (loopRemaining != 0) {
                loopRemaining = IRInst__getOperandSource(a0,1);
                uVar14 = *(undefined4 *)(loopRemaining + 0x94);
                loopIndex = (int *)IRInst__getOperandSource(a0,1);
                R300MachineAssembler__trackMaxLevelAndAssemble(this,uVar14,loopIndex);
                iVar11 = (**(code **)(*this + 0xe0))(this,uVar14);
              }
            }
            else {
LAB_00198950:
              uVar24 = *(undefined4 *)(this[3] + 0x6c4);
              sourceDef2 = IRInst__getOperandSource(a0,1);
              iVar11 = thunk_FUN_00134de8(uVar24,sourceDef2);
            }
            piVar23 = (int *)IRInst__getOperandSource(a0,2);
            if (((piVar23[0x20] == 0) || (loopRemaining = RegKind__flagBit0(piVar23[0x26]), loopRemaining == 0)) ||
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
                R300MachineAssembler__trackMaxLevelAndAssemble(this,uVar14,loopIndex);
                iVar12 = (**(code **)(*this + 0xe0))(this,uVar14);
              }
            }
            else {
LAB_00198a1c:
              uVar24 = *(undefined4 *)(this[3] + 0x6c4);
              sourceDef2 = IRInst__getOperandSource(a0,2);
              iVar12 = thunk_FUN_00134de8(uVar24,sourceDef2);
            }
            if (bVar3) {
LAB_00198f54:
              bVar3 = false;
            }
            else {
              loopRemaining = IRInst__getOperandSource(a0,1);
              if (((loopRemaining != this[8]) &&
                  (((((loopRemaining = IRInst__getOperandSource(a0,1), loopRemaining == 0 || (this[8] == 0)) ||
                     ((piVar23 = (int *)IRInst__getOperandSource(a0,1), piVar23[0x20] == 0 ||
                      (((loopRemaining = RegKind__flagBit0(piVar23[0x26]), loopRemaining == 0 ||
                        ((piVar23[5] & 2U) != 0)) ||
                       (loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining != 0)))))) ||
                    ((piVar23 = (int *)this[8], piVar23[0x20] == 0 ||
                     (loopRemaining = RegKind__flagBit0(piVar23[0x26]), loopRemaining == 0)))) ||
                   (((piVar23[5] & 2U) != 0 ||
                    (((loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining != 0 ||
                      (loopRemaining = IRInst__getOperandSource(a0,1), (*(uint *)(loopRemaining + 0x14) & 0x40) == 0)) ||
                     (((*(uint *)(this[8] + 0x14) & 0x40) == 0 ||
                      (loopRemaining = IRInst__getOperandSource(a0,1),
                      *(int *)(loopRemaining + 0x94) != *(int *)(this[8] + 0x94))))))))))) ||
                 ((loopRemaining = IRInst__getOperandSource(a0,2), loopRemaining != this[7] &&
                  ((((loopRemaining = IRInst__getOperandSource(a0,2), loopRemaining == 0 || (this[7] == 0)) ||
                    (piVar23 = (int *)IRInst__getOperandSource(a0,2), piVar23[0x20] == 0)) ||
                   (((loopRemaining = RegKind__flagBit0(piVar23[0x26]), loopRemaining == 0 || ((piVar23[5] & 2U) != 0))
                    || ((((loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining != 0 ||
                          ((piVar23 = (int *)this[7], piVar23[0x20] == 0 ||
                           (loopRemaining = RegKind__flagBit0(piVar23[0x26]), loopRemaining == 0)))) ||
                         ((piVar23[5] & 2U) != 0)) ||
                        ((((loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining != 0 ||
                           (loopRemaining = IRInst__getOperandSource(a0,2), (*(uint *)(loopRemaining + 0x14) & 0x40) == 0)) ||
                          ((*(uint *)(this[7] + 0x14) & 0x40) == 0)) ||
                         (loopRemaining = IRInst__getOperandSource(a0,2),
                         *(int *)(loopRemaining + 0x94) != *(int *)(this[7] + 0x94))))))))))))) {
                loopRemaining = IRInst__getOperandSource(a0,1);
                if (((loopRemaining == this[7]) ||
                    ((((loopRemaining = IRInst__getOperandSource(a0,1), loopRemaining != 0 && (this[7] != 0)) &&
                      ((piVar23 = (int *)IRInst__getOperandSource(a0,1), piVar23[0x20] != 0 &&
                       ((loopRemaining = RegKind__flagBit0(piVar23[0x26]), loopRemaining != 0 &&
                        ((piVar23[5] & 2U) == 0)))))) &&
                     (((loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining == 0 &&
                       ((((piVar23 = (int *)this[7], piVar23[0x20] != 0 &&
                          (loopRemaining = RegKind__flagBit0(piVar23[0x26]), loopRemaining != 0)) &&
                         ((piVar23[5] & 2U) == 0)) &&
                        ((loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining == 0 &&
                         (loopRemaining = IRInst__getOperandSource(a0,1), (*(uint *)(loopRemaining + 0x14) & 0x40) != 0))))))
                      && (((*(uint *)(this[7] + 0x14) & 0x40) != 0 &&
                          (loopRemaining = IRInst__getOperandSource(a0,1),
                          *(int *)(loopRemaining + 0x94) == *(int *)(this[7] + 0x94))))))))) &&
                   ((loopRemaining = IRInst__getOperandSource(a0,2), loopRemaining == this[8] ||
                    (((((loopRemaining = IRInst__getOperandSource(a0,2), loopRemaining != 0 && (this[8] != 0)) &&
                       ((piVar23 = (int *)IRInst__getOperandSource(a0,2), piVar23[0x20] != 0 &&
                        (((loopRemaining = RegKind__flagBit0(piVar23[0x26]), loopRemaining != 0 &&
                          ((piVar23[5] & 2U) == 0)) &&
                         (loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining == 0)))))) &&
                      ((piVar23 = (int *)this[8], piVar23[0x20] != 0 &&
                       (loopRemaining = RegKind__flagBit0(piVar23[0x26]), loopRemaining != 0)))) &&
                     (((piVar23[5] & 2U) == 0 &&
                      (((loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining == 0 &&
                        (loopRemaining = IRInst__getOperandSource(a0,2), (*(uint *)(loopRemaining + 0x14) & 0x40) != 0)) &&
                       (((*(uint *)(this[8] + 0x14) & 0x40) != 0 &&
                        (loopRemaining = IRInst__getOperandSource(a0,2),
                        *(int *)(loopRemaining + 0x94) == *(int *)(this[8] + 0x94))))))))))))) {
                  this[0xe] = iVar11;
                  this[0xf] = iVar12;
                  if ((iVar13 == 0x9a) && (bVar3 = true, (piVar19[8] & 2U) == 0)) goto LAB_00198f58;
                }
                goto LAB_00198f54;
              }
              bVar3 = false;
              this[0xf] = iVar11;
              this[0xe] = iVar12;
            }
LAB_00198f58:
            if (bVar4) {
LAB_0019941c:
              bVar4 = false;
            }
            else {
              loopRemaining = IRInst__getOperandSource(a0,1);
              if (((loopRemaining != this[0xb]) &&
                  (((((((loopRemaining = IRInst__getOperandSource(a0,1), loopRemaining == 0 || (this[0xb] == 0)) ||
                       (piVar23 = (int *)IRInst__getOperandSource(a0,1), piVar23[0x20] == 0)) ||
                      ((loopRemaining = RegKind__flagBit0(piVar23[0x26]), loopRemaining == 0 ||
                       ((piVar23[5] & 2U) != 0)))) ||
                     (loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining != 0)) ||
                    (((piVar23 = (int *)this[0xb], piVar23[0x20] == 0 ||
                      (loopRemaining = RegKind__flagBit0(piVar23[0x26]), loopRemaining == 0)) ||
                     (((piVar23[5] & 2U) != 0 ||
                      (((loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining != 0 ||
                        (loopRemaining = IRInst__getOperandSource(a0,1), (*(uint *)(loopRemaining + 0x14) & 0x40) == 0)) ||
                       ((*(uint *)(this[0xb] + 0x14) & 0x40) == 0)))))))) ||
                   (loopRemaining = IRInst__getOperandSource(a0,1),
                   *(int *)(loopRemaining + 0x94) != *(int *)(this[0xb] + 0x94))))) ||
                 ((loopRemaining = IRInst__getOperandSource(a0,2), loopRemaining != this[10] &&
                  ((((loopRemaining = IRInst__getOperandSource(a0,2), loopRemaining == 0 || (this[10] == 0)) ||
                    ((piVar23 = (int *)IRInst__getOperandSource(a0,2), piVar23[0x20] == 0 ||
                     ((loopRemaining = RegKind__flagBit0(piVar23[0x26]), loopRemaining == 0 || ((piVar23[5] & 2U) != 0)
                      ))))) ||
                   (((loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining != 0 ||
                     (((piVar23 = (int *)this[10], piVar23[0x20] == 0 ||
                       (loopRemaining = RegKind__flagBit0(piVar23[0x26]), loopRemaining == 0)) ||
                      ((piVar23[5] & 2U) != 0)))) ||
                    (((loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining != 0 ||
                      (loopRemaining = IRInst__getOperandSource(a0,2), (*(uint *)(loopRemaining + 0x14) & 0x40) == 0)) ||
                     (((*(uint *)(this[10] + 0x14) & 0x40) == 0 ||
                      (loopRemaining = IRInst__getOperandSource(a0,2),
                      *(int *)(loopRemaining + 0x94) != *(int *)(this[10] + 0x94))))))))))))) {
                loopRemaining = IRInst__getOperandSource(a0,1);
                if (((loopRemaining == this[10]) ||
                    ((((loopRemaining = IRInst__getOperandSource(a0,1), loopRemaining != 0 && (this[10] != 0)) &&
                      (((piVar23 = (int *)IRInst__getOperandSource(a0,1), piVar23[0x20] != 0 &&
                        ((((loopRemaining = RegKind__flagBit0(piVar23[0x26]), loopRemaining != 0 &&
                           ((piVar23[5] & 2U) == 0)) &&
                          (loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining == 0)) &&
                         ((piVar23 = (int *)this[10], piVar23[0x20] != 0 &&
                          (loopRemaining = RegKind__flagBit0(piVar23[0x26]), loopRemaining != 0)))))) &&
                       ((piVar23[5] & 2U) == 0)))) &&
                     (((loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining == 0 &&
                       (loopRemaining = IRInst__getOperandSource(a0,1), (*(uint *)(loopRemaining + 0x14) & 0x40) != 0)) &&
                      (((*(uint *)(this[10] + 0x14) & 0x40) != 0 &&
                       (loopRemaining = IRInst__getOperandSource(a0,1),
                       *(int *)(loopRemaining + 0x94) == *(int *)(this[10] + 0x94))))))))) &&
                   ((loopRemaining = IRInst__getOperandSource(a0,2), loopRemaining == this[0xb] ||
                    (((((loopRemaining = IRInst__getOperandSource(a0,2), loopRemaining != 0 && (this[0xb] != 0)) &&
                       (piVar23 = (int *)IRInst__getOperandSource(a0,2), piVar23[0x20] != 0)) &&
                      (((loopRemaining = RegKind__flagBit0(piVar23[0x26]), loopRemaining != 0 &&
                        ((piVar23[5] & 2U) == 0)) &&
                       ((loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining == 0 &&
                        ((piVar23 = (int *)this[0xb], piVar23[0x20] != 0 &&
                         (loopRemaining = RegKind__flagBit0(piVar23[0x26]), loopRemaining != 0)))))))) &&
                     (((piVar23[5] & 2U) == 0 &&
                      ((((loopRemaining = (**(code **)(*piVar23 + 0x50))(piVar23), loopRemaining == 0 &&
                         (loopRemaining = IRInst__getOperandSource(a0,2), (*(uint *)(loopRemaining + 0x14) & 0x40) != 0)) &&
                        ((*(uint *)(this[0xb] + 0x14) & 0x40) != 0)) &&
                       (loopRemaining = IRInst__getOperandSource(a0,2),
                       *(int *)(loopRemaining + 0x94) == *(int *)(this[0xb] + 0x94))))))))))) {
                  this[0x12] = iVar11;
                  this[0x13] = iVar12;
                  if ((iVar13 == 0x9a) && (bVar4 = true, (piVar19[8] & 2U) == 0)) goto LAB_00199420;
                }
                goto LAB_0019941c;
              }
              bVar4 = false;
              this[0x13] = iVar11;
              this[0x12] = iVar12;
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
            (**(code **)(*this + 0x10c))(this,piVar22,local_5c,local_80,iVar20);
          }
          if (bVar1) {
            (**(code **)(*this + 0x108))(this,piVar22,local_dc,local_80,iVar20);
          }
          a4 = (int *)this[3];
          loopIndex2 = (int *)0x0;
          loopIndex = local_80;
          IRInst__setOperandSource(irInst,piVar22,local_80,0,a4);
          if (piVar22 == (int *)0x0) {
            irInst[0x27] = iVar20;
          }
          else {
            loopRemaining = IRInst__getOperandRecord(irInst,piVar22);
            *(int *)(loopRemaining + 0x10) = iVar20;
          }
        }
      }
      piVar22 = (int *)((int)piVar22 + 1);
      piVar19 = piVar19 + 6;
    } while ((int)piVar22 <= iVar8);
  }
  else if (0 < iVar8) goto LAB_00198290;
  (**(code **)(*this + 0x118))(this,this[0x20],this + 0xd,this[0x21],this + 0x11);
  (**(code **)(*this + 0x11c))
            (this,irInst,local_6c,local_bc,local_dc,local_70,local_ec,local_5c);
  if (irInst[0x26] == 0x2c) {
LAB_0019a1f4:
    pcVar7 = *(code **)(*this + 0x124);
  }
  else {
    if ((((irInst[0x20] != 0) && (iVar8 = RegKind__flagBit0(irInst[0x26]), iVar8 != 0)) &&
        (((irInst[5] & 2U) == 0 && (iVar8 = (**(code **)(*irInst + 0x50))(irInst), iVar8 == 0))))
       || (iVar8 = (**(code **)(*irInst + 0x50))(irInst), iVar8 != 0)) {
      pcVar7 = *(code **)(*this + 0x120);
      uVar14 = thunk_FUN_00134de8(*(undefined4 *)(this[3] + 0x6c4),irInst);
      (*pcVar7)(this,local_6c,local_70,irInst,uVar14);
      goto LAB_0019a230;
    }
    if ((irInst[5] & 2U) != 0) goto LAB_0019a1f4;
    if ((irInst[5] & 0x80000U) == 0) goto LAB_0019a230;
    pcVar7 = *(code **)(*this + 0x128);
  }
  (*pcVar7)(this,local_6c,local_70,irInst);
LAB_0019a230:
  if (uVar6 != 0) {
    (**(code **)(*this + 300))(this,local_f8,local_68,irInst);
  }
  if (uVar10 != 0) {
    (**(code **)(*this + 0x130))(this,local_f4,local_68,irInst);
  }
  return;
}

/* maxSigned @ 0x19a2e0 (16 bytes) */
int maxSigned(firstValue, secondValue)
  int firstValue;
  int secondValue;
{
  if (secondValue < firstValue) {
    return firstValue;
  }
  return secondValue;
}

/* R300VMachineAssembler__finishProgram @ 0x19a2f0 (120 bytes) */
int R300VMachineAssembler__finishProgram(this)
  int this;
{
  **(undefined4 **)(this + 0x50) =
       *(undefined4 *)(*(int *)(*(int *)(this + 0xc) + 0x30c) + 0x40);
  *(undefined4 *)(*(int *)(this + 0x50) + 0xc) = *(undefined4 *)(this + 0x24);
  *(undefined4 *)(*(int *)(this + 0x50) + 0x10) = *(undefined4 *)(this + 0x58);
  *(int *)(*(int *)(this + 0x50) + 0x14) = *(int *)(this + 0x34) + 1;
  *(int *)(*(int *)(this + 0x50) + 0x18) = *(int *)(this + 0x38) + 1;
  *(undefined4 *)(*(int *)(this + 0x50) + 0x1c) = *(undefined4 *)(this + 0x2c);
  *(undefined4 *)(*(int *)(this + 0x50) + 0x20) = *(undefined4 *)(this + 0x30);
  *(int *)(*(int *)(this + 0x50) + 0x24) = *(int *)(this + 0x4c) + 1;
  return;
}

/* R300VMachineAssembler__clearInstructionByte3 @ 0x19a368 (28 bytes) */
int R300VMachineAssembler__clearInstructionByte3(this)
  int this;
{
  *(undefined1 *)(*(int *)(this + 0x58) * 0x10 + *(int *)(this + 0x44) + 3) = 0;
  return;
}

/* R300VMachineAssembler__nextInstruction @ 0x19a384 (56 bytes) */
int R300VMachineAssembler__nextInstruction(this)
  int this;
{
  ((int (*)())R300VMachineAssembler__clearInstructionByte3)(this);
  *(int *)(this + 0x58) = *(int *)(this + 0x58) + 1;
  return;
}

/* R300VMachineAssembler__logStatistics @ 0x19a3bc (172 bytes) */
int R300VMachineAssembler__logStatistics(this, quiet, unused1, unused2, unused3, printfArg6, printfArg7, printfArg8)
  int this;
  int quiet;
  undefined4 unused1;
  undefined4 unused2;
  undefined4 unused3;
  undefined4 printfArg6;
  undefined4 printfArg7;
  undefined4 printfArg8;
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(this + 0x5c) + *(int *)(this + 0x58);
  Compiler__logf(*(undefined4 *)(this + 0xc),
               "Assembler : emits %d cf, %d alu -> %d total instruction(s)\n",
               *(int *)(this + 0x5c),*(int *)(this + 0x58),iVar1,printfArg6,printfArg7,printfArg8);
  Compiler__logf(*(undefined4 *)(this + 0xc),
               "INFO:# of control flow %d, # of exec %d instructions\n",
               *(undefined4 *)(this + 0x5c),*(undefined4 *)(this + 0x58),iVar1,printfArg6,printfArg7
               ,printfArg8);
  if (quiet == 0) {
    iVar1 = *(int *)(this + 0x78);
    iVar2 = 0;
    if (iVar1 != 0) {
      iVar2 = (*(int *)(this + 0x74) * 100) / iVar1;
    }
    Compiler__logf(*(undefined4 *)(this + 0xc),
                 "Assembler : of %d candidate alu instruction(s), %d are packed (%%%d)\n",iVar1,
                 *(int *)(this + 0x74),iVar2,printfArg6,printfArg7,printfArg8);
    return;
  }
  return;
}

/* R300VMachineAssembler__copyControlFlowToOutput @ 0x19a484 (132 bytes) */
int R300VMachineAssembler__copyControlFlowToOutput(this)
  int this;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  int loopIndex;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  
  **(undefined4 **)(this + 0x54) = *(undefined4 *)(this + 0x5c);
  if (*(int *)(this + 0x5c) < 1) {
    return;
  }
  loopIndex = 0;
  iVar4 = 0;
  do {
    loopIndex = loopIndex + 1;
    iVar8 = iVar4 + *(int *)(this + 0x40);
    puVar1 = (undefined4 *)(iVar4 + *(int *)(this + 0x40));
    uVar2 = *(undefined4 *)(iVar8 + 4);
    iVar6 = iVar4 + *(int *)(this + 0x54);
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
  } while (loopIndex < *(int *)(this + 0x5c));
  return;
}

/* R300VMachineAssembler__vslot_noOp_19a508 @ 0x19a508 (4 bytes) */
int R300VMachineAssembler__vslot_noOp_19a508()
{
  return;
}

/* R300VMachineAssembler__vslot_noOp_19a50c @ 0x19a50c (4 bytes) */
int R300VMachineAssembler__vslot_noOp_19a50c()
{
  return;
}

/* R300VMachineAssembler__clearCurrentInstruction @ 0x19a510 (40 bytes) */
int R300VMachineAssembler__clearCurrentInstruction(this)
  int this;
{
  int instructionByteOffset;
  int instructionWords;
  
  instructionByteOffset = *(int *)(this + 0x58) * 0x10;
  instructionWords = instructionByteOffset + *(int *)(this + 0x44);
  *(undefined4 *)(instructionByteOffset + *(int *)(this + 0x44)) = 0;
  *(undefined4 *)(instructionWords + 0xc) = 0;
  *(undefined4 *)(instructionWords + 4) = 0;
  *(undefined4 *)(instructionWords + 8) = 0;
  return;
}

/* opcodeInfoIsVsFlagBit2 @ 0x19a538 (48 bytes) */
int opcodeInfoIsVsFlagBit2(unusedThis, irInst)
  undefined4 unusedThis;
  int irInst;
{
  return *(uint *)(PTR_DAT_001e9140 + *(int *)(*(int *)(irInst + 0x88) + 8) * 0x38) >> 2 & 1;
}

/* R300VMachineAssembler__transitionState @ 0x19a568 (176 bytes) */
int R300VMachineAssembler__transitionState(this, event)
  int this;
  int event;
{
  int loopIndex;
  int loopRemaining;
  
  loopRemaining = (event * 5 + *(int *)(this + 0x1c)) * 4;
  loopIndex = *(int *)(&DAT_001e6668 + loopRemaining);
  loopRemaining = *(int *)(&DAT_001e66cc + loopRemaining);
  *(int *)(this + 0x1c) = loopIndex;
  if (loopIndex == -1) {
    *(undefined4 *)(this + 0x1c) = 2;
  }
  else if (loopRemaining < 1) {
    if (loopRemaining < 0) {
      loopRemaining = -loopRemaining;
      loopIndex = *(int *)(this + 0x58);
      do {
        loopIndex = loopIndex + -1;
        loopRemaining = loopRemaining + -1;
      } while (loopRemaining != 0);
      *(int *)(this + 0x58) = loopIndex;
    }
  }
  else {
    loopIndex = 0;
    do {
      loopIndex = loopIndex + 1;
      ((int (*)())R300VMachineAssembler__nextInstruction)(this);
    } while (loopIndex != loopRemaining);
  }
  return;
}

/* R300VMachineAssembler__vslot2_exceedsLimits @ 0x19a618 (120 bytes) */
int R300VMachineAssembler__vslot2_exceedsLimits(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
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
  
  Compiler__logf(*(int *)(param_1 + 0xc),"next_sp = %d, max = %d\n",*(undefined4 *)(param_1 + 0x58),
               *(undefined4 *)(*(int *)(*(int *)(param_1 + 0xc) + 0x30c) + 0x40),param_5,param_6,
               param_7,param_8);
  if ((*(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0x30c) + 0x40) < *(int *)(param_1 + 0x58)) ||
     (uVar1 = 0, 0x10 < *(int *)(param_1 + 0x5c))) {
    uVar1 = 1;
  }
  return uVar1;
}

/* R300VMachineAssembler__vslot49_advanceInstruction @ 0x19a690 (16 bytes) */
int R300VMachineAssembler__vslot49_advanceInstruction(this)
  int this;
{
  *(int *)(this + 0x58) = *(int *)(this + 0x58) + 1;
  return;
}

/* R300VMachineAssembler__vslot48_declareAndAssemble @ 0x19a6a0 (80 bytes) */
int R300VMachineAssembler__vslot48_declareAndAssemble(this, node)
  int *this;
  undefined4 node;
{
  FUN_000e2c78(node,this,this[3]);
                    
                    
  (**(code **)(*this + 0x88))(this,node);
  return;
}

/* vsSourceSelectForConstant @ 0x19a6f0 (192 bytes) */
int vsSourceSelectForConstant(sourceBlock, sourceNumber, negateOut)
  int sourceBlock;
  int sourceNumber;
  undefined4 *negateOut;
{
  float literalValue;
  
  *negateOut = 0;
  if (3 < sourceNumber) {
    if (sourceNumber < 6) {
      return 4;
    }
    if (sourceNumber == 6) {
      return 5;
    }
  }
  literalValue = *(float *)(sourceNumber * 0x18 + sourceBlock + 0x20);
  if (literalValue == FLOAT_001aa0e8) {
    return 5;
  }
  if ((literalValue != FLOAT_001aa0d4) && (literalValue == FLOAT_001aa114)) {
    *negateOut = 1;
    return 5;
  }
  return 4;
}

/* copyLaneWord @ 0x19a7b0 (92 bytes) */
int copyLaneWord(laneBlock, sourceLane, destLane)
  int laneBlock;
  int sourceLane;
  int destLane;
{
  undefined4 *destPtr;
  undefined4 *sourcePtr;
  
  sourcePtr = (undefined4 *)(laneBlock + 8);
  if (((sourceLane != 2) && (sourcePtr = (undefined4 *)(laneBlock + 0xc), sourceLane != 3)) &&
     (sourcePtr = (undefined4 *)0x0, sourceLane == 1)) {
    sourcePtr = (undefined4 *)(laneBlock + 4);
  }
  destPtr = (undefined4 *)(laneBlock + 8);
  if (((destLane != 2) && (destPtr = (undefined4 *)(laneBlock + 0xc), destLane != 3)) &&
     (destPtr = (undefined4 *)0x0, destLane == 1)) {
    destPtr = (undefined4 *)(laneBlock + 4);
  }
  *destPtr = *sourcePtr;
  return;
}

/* R300VMachineAssembler__vslot15_assembleUnlessConstantMove @ 0x19a80c (156 bytes) */
int R300VMachineAssembler__vslot15_assembleUnlessConstantMove(this, inst, extra1, compiler)
  int *this;
  int inst;
  undefined4 extra1;
  undefined4 compiler;
{
  int *a0;
  int callResult;
  
  a0 = (int *)IRInst__getOperandSource(inst,1);
  callResult = (**(code **)(*a0 + 0x50))(a0);
  if ((callResult != 0) && (*(int *)(inst + 0x144) != 0)) {
    return;
  }
                    
                    
  (**(code **)(*this + 0x38))(this,inst,extra1,compiler);
  return;
}

/* R300VMachineAssembler__vslot16_noOp @ 0x19a8a8 (4 bytes) */
int R300VMachineAssembler__vslot16_noOp()
{
  return;
}

/* R300VMachineAssembler__vslot18_callSlot14 @ 0x19a8ac (16 bytes) */
int R300VMachineAssembler__vslot18_callSlot14(this)
  int *this;
{
                    
                    
  (**(code **)(*this + 0x38))();
  return;
}

/* R300VMachineAssembler__vslot19_callSlot14 @ 0x19a8bc (16 bytes) */
int R300VMachineAssembler__vslot19_callSlot14(this)
  int *this;
{
                    
                    
  (**(code **)(*this + 0x38))();
  return;
}

/* R300VMachineAssembler__vslot43_beginLoop @ 0x19a8d4 (128 bytes) */
int R300VMachineAssembler__vslot43_beginLoop(this, node)
  int this;
  int node;
{
  int loopId;
  
  if ((1 < *(int *)(node + 0x130)) && (*(int *)(this + 0x5c) != 0x10)) {
    loopId = *(int *)(node + 300);
    *(int *)(this + 0x70) = loopId;
    *(undefined4 *)(loopId * 0xc + *(int *)(this + 0x60)) = *(undefined4 *)(this + 0x58);
    *(undefined4 *)(*(int *)(this + 0x70) * 0xc + *(int *)(this + 0x60) + 8) =
         *(undefined4 *)(this + 0x1c);
    ((int (*)())R300VMachineAssembler__transitionState)(this,3);
    *(undefined4 *)(this + 100) = 1;
  }
  return;
}

/* R300VMachineAssembler__vslot44_endLoopBody @ 0x19a954 (92 bytes) */
int R300VMachineAssembler__vslot44_endLoopBody(this)
  int this;
{
  if (*(int *)(this + 100) != 0) {
    ((int (*)())R300VMachineAssembler__transitionState)(this,3);
    *(undefined4 *)(*(int *)(this + 0x70) * 0xc + *(int *)(this + 0x60) + 4) =
         *(undefined4 *)(this + 0x58);
    *(undefined4 *)(this + 100) = 1;
  }
  return;
}

/* R300VMachineAssembler__appendControlFlowEntry @ 0x19a9b0 (44 bytes) */
int R300VMachineAssembler__appendControlFlowEntry(this, fieldA, fieldB)
  int this;
  undefined4 fieldA;
  undefined4 fieldB;
{
  int entry;
  undefined4 instructionCount;
  
  instructionCount = *(undefined4 *)(this + 0x58);
  entry = *(int *)(this + 0x5c) * 0x1c + *(int *)(this + 0x40);
  *(int *)(this + 0x5c) = *(int *)(this + 0x5c) + 1;
  *(undefined4 *)(entry + 0x18) = fieldB;
  *(undefined4 *)(entry + 0x10) = instructionCount;
  *(undefined4 *)(entry + 0x14) = fieldA;
  return;
}

/* R300VMachineAssembler__vslot45_endLoop @ 0x19a9dc (160 bytes) */
int R300VMachineAssembler__vslot45_endLoop(this, node)
  int this;
  int node;
{
  int loopId;
  
  if ((1 < *(int *)(node + 0x130)) && (*(int *)(this + 0x5c) != 0x10)) {
    *(undefined4 *)(this + 0x68) = *(undefined4 *)(this + 0x58);
    *(undefined4 *)(this + 0x6c) = *(undefined4 *)(this + 0x1c);
    loopId = *(int *)(node + 300);
    *(int *)(this + 0x70) = loopId;
    *(undefined4 *)(this + 0x58) = *(undefined4 *)(loopId * 0xc + *(int *)(this + 0x60));
    ((int (*)())R300VMachineAssembler__transitionState)(this,4);
    loopId = *(int *)(this + 0x70) * 0xc;
    ((int (*)())R300VMachineAssembler__appendControlFlowEntry)(this,*(undefined4 *)(loopId + *(int *)(this + 0x60)),
                 *(undefined4 *)(loopId + *(int *)(this + 0x60) + 4));
    *(undefined4 *)(this + 100) = 1;
  }
  return;
}

/* R300VMachineAssembler__vslot46_leaveLoop @ 0x19aa7c (92 bytes) */
int R300VMachineAssembler__vslot46_leaveLoop(this)
  int this;
{
  if (*(int *)(this + 100) != 0) {
    ((int (*)())R300VMachineAssembler__transitionState)(this,3);
    *(undefined4 *)(this + 0x70) = 0xffffffff;
    *(undefined4 *)(this + 0x58) = *(undefined4 *)(this + 0x68);
    *(undefined4 *)(this + 0x1c) = *(undefined4 *)(this + 0x6c);
    *(undefined4 *)(this + 100) = 0;
  }
  return;
}

/* R300VMachineAssembler__vslot27_assembleOrFail @ 0x19aaf4 (100 bytes) */
int R300VMachineAssembler__vslot27_assembleOrFail(this, node, extra1, extra2, extra3, compiler)
  undefined4 this;
  int *node;
  undefined4 extra1;
  undefined4 extra2;
  undefined4 extra3;
  undefined4 compiler;
{
  int callResult;
  
  callResult = (**(code **)(*node + 0x40))(node,node,extra1,extra2,extra3,compiler);
  if (callResult == 0) {
    Compiler__fail(compiler,0xf);
    return;
  }
  return;
}

/* R300VMachineAssembler__vslot25_assembleOrFail @ 0x19ab60 (100 bytes) */
int R300VMachineAssembler__vslot25_assembleOrFail(this, node, extra1, compiler)
  undefined4 this;
  int *node;
  undefined4 extra1;
  undefined4 compiler;
{
  int callResult;
  
  callResult = (**(code **)(*node + 0x40))(node,node,extra1,compiler);
  if (callResult == 0) {
    Compiler__fail(compiler,0xf);
    return;
  }
  return;
}

/* R300VMachineAssembler__vslot28_assembleChildOrFail @ 0x19abc4 (100 bytes) */
int R300VMachineAssembler__vslot28_assembleChildOrFail(this, node, extra1, compiler)
  undefined4 this;
  int node;
  undefined4 extra1;
  undefined4 compiler;
{
  int callResult;
  
  callResult = (**(code **)(**(int **)(node + 300) + 0x40))
                    (*(int **)(node + 300),node,extra1,compiler);
  if (callResult == 0) {
    Compiler__fail(compiler,0xf);
    return;
  }
  return;
}

/* R300VMachineAssembler__vslot38_appendCallEntry @ 0x19ac2c (120 bytes) */
int R300VMachineAssembler__vslot38_appendCallEntry(this, entryField0, entryField3)
  int this;
  undefined4 entryField0;
  undefined4 entryField3;
{
  int entry;
  int entryByteOffset;
  
  ((int (*)())R300VMachineAssembler__transitionState)(this,4);
  entryByteOffset = *(int *)(this + 0x5c) * 0x1c;
  *(int *)(this + 0x5c) = *(int *)(this + 0x5c) + 1;
  entry = entryByteOffset + *(int *)(this + 0x40);
  *(undefined4 *)(entryByteOffset + *(int *)(this + 0x40)) = entryField0;
  *(undefined4 *)(entry + 8) = 0x35;
  *(undefined4 *)(entry + 0xc) = entryField3;
  entryByteOffset = *(int *)(this + 0x58);
  *(undefined4 *)(entry + 0x18) = 0;
  *(undefined4 *)(entry + 0x14) = 0;
  *(int *)(entry + 0x10) = entryByteOffset + -2;
  return;
}

/* R300VMachineAssembler__vslot42_noOp @ 0x19aca4 (4 bytes) */
int R300VMachineAssembler__vslot42_noOp()
{
  return;
}

/* R300VMachineAssembler__init @ 0x19acb0 (328 bytes) */
int R300VMachineAssembler__init(this, program, allocatorArg, compiler)
  int this;
  undefined4 program;
  undefined4 allocatorArg;
  int compiler;
{
  int programInstructionLimit;
  undefined4 allocation;
  int maxInstructions;
  
  *(int *)(this + 0xc) = compiler;
  *(undefined4 *)(this + 0x88) = *(undefined4 *)(compiler + 0x30c);
  maxInstructions = *(int *)(compiler + 0x324) << 4;
  programInstructionLimit = *(int *)(*(int *)(compiler + 0x30c) + 0x40) << 4;
  if (maxInstructions < programInstructionLimit) {
    maxInstructions = programInstructionLimit;
  }
  allocation = Arena__alloc(*(undefined4 *)(compiler + 0x374),maxInstructions);
  *(undefined4 *)(this + 0x44) = allocation;
  allocation = Arena__alloc(*(undefined4 *)(compiler + 0x374),*(int *)(compiler + 0x324) * 0x38);
  *(undefined4 *)(this + 0x40) = allocation;
  allocation = Arena__alloc(*(undefined4 *)(compiler + 0x374),900);
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x54) = allocation;
  allocation = Arena__alloc(*(undefined4 *)(compiler + 0x374),*(int *)(compiler + 0x324) << 3);
  *(undefined4 *)(this + 8) = allocation;
  allocation = FUN_000e14e4(compiler,0x28,allocatorArg);
  *(undefined4 *)(this + 0x50) = allocation;
  _memset(allocation,0,0x28);
  **(int **)(this + 0x50) = maxInstructions;
  *(undefined4 *)(*(int *)(this + 0x50) + 4) = *(undefined4 *)(this + 0x44);
  *(undefined4 *)(*(int *)(this + 0x50) + 8) = *(undefined4 *)(this + 0x54);
  *(undefined4 *)(this + 0x7c) = 0;
  *(undefined4 *)(this + 0x10) = program;
  *(undefined4 *)(this + 0x70) = 0xffffffff;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x60) = 0;
  *(undefined4 *)(this + 0x5c) = 0;
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 100) = 0;
  *(undefined4 *)(this + 0x74) = 0;
  *(undefined4 *)(this + 0x78) = 0;
  return;
}

/* R300VMachineAssembler__vslot6_setLoopStack @ 0x19adf8 (136 bytes) */
int R300VMachineAssembler__vslot6_setLoopStack(this, enable)
  int this;
  int enable;
{
  int loopStackLevels;
  int compilerPtr;
  undefined4 loopStack;
  
  if (enable == 0) {
    *(undefined4 *)(*(int *)(this + 0xc) + 0x3d4) = 0;
  }
  else {
    compilerPtr = *(int *)(this + 0xc);
    if (*(int *)(compilerPtr + 0x3d4) == 0) {
      *(undefined4 *)(compilerPtr + 0x3d4) = 1;
      compilerPtr = *(int *)(this + 0xc);
    }
    loopStackLevels = *(int *)(compilerPtr + 0x3d4);
    Arena__free(*(undefined4 *)(compilerPtr + 0x374),*(undefined4 *)(this + 0x60));
    loopStack = Arena__alloc(*(undefined4 *)(*(int *)(this + 0xc) + 0x374),loopStackLevels * 0xc);
    *(undefined4 *)(this + 0x60) = loopStack;
  }
  return;
}

/* R300VMachineAssembler__vslot24_assembleWithTarget @ 0x19ae80 (104 bytes) */
int R300VMachineAssembler__vslot24_assembleWithTarget(this, node, block)
  int *this;
  int node;
  undefined4 block;
{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  (**(code **)(*this + 0x34))(this,block,*(undefined4 *)(node + 0xdc));
  UNRECOVERED_JUMPTABLE = *(code **)(*this + 0x9c);
  uVar1 = FUN_000e7d5c(node);
                    
                    
  (*UNRECOVERED_JUMPTABLE)(this,uVar1,*(undefined4 *)(node + 0x134));
  return;
}

/* R300VMachineAssembler__vslot30_assembleBlockThenSlot40 @ 0x19aee8 (88 bytes) */
int R300VMachineAssembler__vslot30_assembleBlockThenSlot40(this, node, block)
  int *this;
  int node;
  undefined4 block;
{
  (**(code **)(*this + 0x34))(this,block,*(undefined4 *)(node + 0xdc));
                    
                    
  (**(code **)(*this + 0xa0))(this,0);
  return;
}

/* R300VMachineAssembler__vslot37_patchControlFlowTarget @ 0x19af40 (252 bytes) */
int R300VMachineAssembler__vslot37_patchControlFlowTarget(this, node)
  int this;
  int *node;
{
  uint uVar1;
  int *lastEntryPtr;
  uint uVar3;
  int callResult;
  int conditionRegister;
  
  conditionRegister = node[0x4e];
  callResult = DList__count(conditionRegister + 0x90);
  if ((callResult < 3) && (callResult = FUN_000e79e8(conditionRegister), callResult != 0)) {
    lastEntryPtr = (int *)0x0;
    if (*(int *)(*(int *)(conditionRegister + 0xd0) + 4) != 0) {
      lastEntryPtr = *(int **)(*(int *)(conditionRegister + 0xd0) + 8);
    }
    if (*lastEntryPtr == node[0x4f]) {
      return;
    }
  }
  callResult = (**(code **)(*node + 0x40))(node);
  if (callResult != 0) {
    lastEntryPtr = (int *)0x0;
    callResult = *(int *)(*(int *)(this + 0x10) + 0x24);
    uVar3 = *(uint *)(callResult + 4);
    uVar1 = uVar3 - 1;
    if (uVar1 < uVar3) {
      lastEntryPtr = (int *)(uVar1 * 4 + *(int *)(callResult + 8));
    }
    callResult = *lastEntryPtr;
    ((int (*)())R300VMachineAssembler__transitionState)(this,4);
    *(int *)(callResult + 0x14) = *(int *)(this + 0x58) + -2;
    return;
  }
  Compiler__fail(*(undefined4 *)(this + 0xc),0xf);
  return;
}

/* R300VMachineAssembler__findFoldableMovePair @ 0x19b03c (908 bytes) */
int R300VMachineAssembler__findFoldableMovePair(this, block, groupHead, foldNotNeededOut)
  int this;
  undefined4 block;
  int *groupHead;
  undefined4 *foldNotNeededOut;
{
  undefined4 sourceDef2;
  int operandRecord;
  int sourceDef;
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
  
  *foldNotNeededOut = 0;
  piVar4 = (int *)0x0;
  if (groupHead != (int *)0x0) {
    piVar8 = (int *)0x0;
    piVar9 = (int *)0x0;
    bVar2 = false;
    bVar1 = true;
    piVar10 = groupHead;
    do {
      uVar11 = piVar10[5];
      if ((uVar11 & 1) != 0) {
        if ((uVar11 & 4) != 0) {
          bVar2 = true;
        }
        iVar3 = ((int (*)())opcodeInfoIsVsFlagBit2)(*(undefined4 *)(this + 0x88),piVar10);
        if (iVar3 == 0) {
          if ((uVar11 & 0x10000) == 0) {
            piVar8 = piVar10;
          }
        }
        else {
          piVar9 = piVar10;
          if (piVar10[0x26] == 1) {
            iVar3 = thunk_FUN_00134de8(*(undefined4 *)(*(int *)(this + 0xc) + 0x6c4),piVar10);
            piVar4 = *(int **)(*(int *)(this + 0xc) + 0x30c);
            iVar5 = (**(code **)(*piVar4 + 0x138))(piVar4,0);
            if ((uint)(iVar3 - iVar5) < 4) {
              iVar3 = (**(code **)(*piVar10 + 0x14))(piVar10);
              if (1 < iVar3) {
                sourceDef = IRInst__getOperandSource(piVar10,1);
                iVar5 = *(int *)(sourceDef + 0x94);
                sourceDef = IRInst__getOperandSource(piVar10,2);
                if (iVar5 != *(int *)(sourceDef + 0x94)) goto LAB_0019b168;
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
    piVar4 = groupHead;
    if ((piVar8 != (int *)0x0) && (piVar9 != (int *)0x0)) {
      if (bVar1) {
        *foldNotNeededOut = 1;
      }
      else if (bVar2) {
        *(int *)(*(int *)(this + 0x10) + 0x14) = *(int *)(*(int *)(this + 0x10) + 0x14) + 1;
        piVar4 = (int *)piVar10[1];
        iVar3 = groupHead[0x56];
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
            iVar6 = thunk_FUN_00134de8(*(undefined4 *)(*(int *)(this + 0xc) + 0x6c4),piVar8);
            uVar13 = *(undefined4 *)(*(int *)(this + 0xc) + 0x6c4);
            sourceDef2 = IRInst__getOperandSource(piVar9,iVar5);
            iVar12 = thunk_FUN_00134de8(uVar13,sourceDef2);
            if (iVar6 == iVar12) {
              iVar6 = 1;
              piVar4 = (int *)IRInst__create(0x31,*(undefined4 *)(this + 0xc));
              uVar7 = FUN_00130690(*(undefined4 *)(*(int *)(this + 0xc) + 0x6c4),0);
              operandRecord = IRInst__getOperandRecord(piVar4,0);
              *(undefined4 *)(operandRecord + 0xc) = 0;
              *(undefined4 *)(operandRecord + 8) = uVar7;
              IRInst__setOperandSource(piVar4,1,piVar8,0,*(undefined4 *)(this + 0xc));
              Block__insertInstBefore(iVar3,piVar8,piVar4);
              *(int *)(*(int *)(this + 0x10) + 0x18) =
                   *(int *)(*(int *)(this + 0x10) + 0x18) + 1;
              if (piVar4 == (int *)0x0) {
                return piVar8;
              }
              for (; iVar3 = (**(code **)(*piVar9 + 0x14))(piVar9), iVar6 <= iVar3;
                  iVar6 = iVar6 + 1) {
                iVar5 = piVar8[0x26];
                iVar3 = IRInst__getOperandSource(piVar9,iVar6);
                if (iVar5 == *(int *)(iVar3 + 0x98)) {
                  iVar3 = thunk_FUN_00134de8(*(undefined4 *)(*(int *)(this + 0xc) + 0x6c4),piVar8
                                            );
                  uVar13 = *(undefined4 *)(*(int *)(this + 0xc) + 0x6c4);
                  sourceDef2 = IRInst__getOperandSource(piVar9,iVar6);
                  iVar5 = thunk_FUN_00134de8(uVar13,sourceDef2);
                  if (iVar3 == iVar5) {
                    IRInst__setOperandSource(piVar9,iVar6,piVar4,0,*(undefined4 *)(this + 0xc));
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

/* R300VMachineAssembler__assembleBlock @ 0x19b3c8 (728 bytes) */
int R300VMachineAssembler__assembleBlock(this, block)
  int *this;
  int block;
{
  int *operandVReg;
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int local_38 [9];
  
  piVar5 = *(int **)(block + 8);
  if (piVar5[2] == 0) {
    return;
  }
  do {
    iVar3 = (**(code **)(*this + 8))(this);
    if (iVar3 != 0) {
      Compiler__fail(this[3],5);
    }
    iVar3 = this[3];
    if (**(int **)(iVar3 + 0x6c4) == 0) {
      piVar4 = (int *)FUN_000e3b88(this[4],block,piVar5,local_38);
      if ((piVar4 == (int *)0x0) || (local_38[0] == 0)) {
        iVar3 = this[3];
      }
      else {
        iVar3 = this[3];
        piVar5 = piVar4;
      }
    }
    piVar4 = piVar5;
    if (**(int **)(iVar3 + 0x6c4) == 0) {
      piVar4 = (int *)((int (*)())R300VMachineAssembler__findFoldableMovePair)(this,block,piVar5,this + 0x1f);
      iVar3 = this[3];
    }
    iVar3 = FUN_00106cf8(piVar4,*(undefined4 *)(iVar3 + 0x6c4));
    if ((((iVar3 == 0) || (uVar2 = piVar4[5], (uVar2 & 4) != 0)) || ((int)uVar2 < 0)) ||
       ((uVar2 & 0x1000) != 0)) {
      (**(code **)(*this + 0xbc))(this);
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
            ((int (*)())R300VMachineAssembler__transitionState)(this,2);
            (**(code **)(*piVar6 + 0x1c))(piVar6,this,0,this[3]);
          }
          else {
            iVar3 = (**(code **)(*piVar6 + 0x48))(piVar6);
            if (iVar3 != 0) {
              (**(code **)(*this + 0xc0))(this,piVar6,this[3]);
            }
          }
          (**(code **)(*piVar6 + 0x20))(piVar6,this,0,this[3]);
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
        (**(code **)(*this + 0xc4))(this);
        piVar6 = (int *)piVar4[2];
      }
    }
    else {
      *(int *)(this[4] + 0xc) = *(int *)(this[4] + 0xc) + 1;
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

/* R300VMachineAssembler__vslot40_endControlFlowBlock @ 0x19b6a0 (168 bytes) */
int R300VMachineAssembler__vslot40_endControlFlowBlock(this)
  int this;
{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  
  ((int (*)())R300VMachineAssembler__transitionState)(this,3);
  piVar3 = (int *)0x0;
  iVar1 = *(int *)(*(int *)(this + 0x10) + 0x28);
  uVar2 = *(uint *)(iVar1 + 4);
  if (uVar2 - 1 < uVar2) {
    piVar3 = (int *)((uVar2 - 1) * 4 + *(int *)(iVar1 + 8));
  }
  iVar4 = *piVar3;
  Vector__removeAt(iVar1,uVar2 - 1);
  uVar2 = *(uint *)(iVar4 + 0x10);
  *(int *)(iVar4 + 0x18) = *(int *)(this + 0x58) + -2;
  if (uVar2 < *(uint *)(this + 0x2c)) {
    *(int *)(this + 0x2c) = *(int *)(this + 0x58) + -1;
    uVar2 = *(uint *)(iVar4 + 0x10);
  }
  if (uVar2 < *(uint *)(this + 0x30)) {
    *(int *)(this + 0x30) = *(int *)(this + 0x58) + -1;
  }
  return;
}

/* R300VMachineAssembler__vslot39_appendBranchEntry @ 0x19b748 (192 bytes) */
int R300VMachineAssembler__vslot39_appendBranchEntry(this, entryField3, entryField1)
  int this;
  undefined4 entryField3;
  undefined4 entryField1;
{
  int entryIndex;
  int *piVar2;
  uint uVar3;
  uint *puVar4;
  int entry;
  
  ((int (*)())R300VMachineAssembler__transitionState)(this,4);
  entryIndex = *(int *)(this + 0x5c);
  *(int *)(this + 0x5c) = entryIndex + 1;
  entry = entryIndex * 0x1c + *(int *)(this + 0x40);
  *(undefined4 *)(entry + 8) = 0x3e;
  entryIndex = *(int *)(this + 0x58);
  *(undefined4 *)(entry + 0xc) = entryField3;
  *(undefined4 *)(entry + 4) = entryField1;
  *(int *)(entry + 0x10) = entryIndex + -2;
  puVar4 = *(uint **)(*(int *)(this + 0x10) + 0x28);
  uVar3 = puVar4[1];
  if (uVar3 < *puVar4) {
    _memset(uVar3 * 4 + puVar4[2],0,4);
    piVar2 = (int *)(uVar3 * 4 + puVar4[2]);
    puVar4[1] = uVar3 + 1;
  }
  else {
    piVar2 = (int *)Vector__elementRefGrow(puVar4,uVar3);
  }
  *piVar2 = entry;
  return;
}

/* R300VMachineAssembler__vslot29_endIfBlock @ 0x19b808 (180 bytes) */
int R300VMachineAssembler__vslot29_endIfBlock(this)
  int this;
{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = (int *)0x0;
  iVar1 = *(int *)(*(int *)(this + 0x10) + 0x24);
  uVar2 = *(uint *)(iVar1 + 4);
  if (uVar2 - 1 < uVar2) {
    piVar3 = (int *)((uVar2 - 1) * 4 + *(int *)(iVar1 + 8));
  }
  iVar4 = *piVar3;
  Vector__removeAt(iVar1,uVar2 - 1);
  *(undefined4 *)(iVar4 + 0x18) = *(undefined4 *)(this + 0x58);
  if (*(int *)(iVar4 + 0x14) == 0) {
    uVar2 = *(uint *)(iVar4 + 0x10);
    *(uint *)(iVar4 + 0x14) = uVar2;
  }
  else {
    uVar2 = *(uint *)(iVar4 + 0x10);
  }
  if (uVar2 < *(uint *)(this + 0x2c)) {
    *(undefined4 *)(this + 0x2c) = *(undefined4 *)(this + 0x58);
    uVar2 = *(uint *)(iVar4 + 0x10);
  }
  if (uVar2 < *(uint *)(this + 0x30)) {
    *(undefined4 *)(this + 0x30) = *(undefined4 *)(this + 0x58);
  }
  return ((int (*)())R300VMachineAssembler__transitionState)(this,3);
}

/* R300VMachineAssembler__create @ 0x19b8bc (96 bytes) */
int R300VMachineAssembler__create(unusedThis, compiler)
  undefined4 unusedThis;
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

/* R300VMachineAssembler__encodeDestinationWord @ 0x19baf4 (1596 bytes) */
int R300VMachineAssembler__encodeDestinationWord(this, inst, instructionWords)
  int this;
  int *inst;
  uint *instructionWords;
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
  
  piVar4 = *(int **)(*(int *)(this + 0xc) + 0x30c);
  iVar5 = (**(code **)(*piVar4 + 0x16c))(piVar4,inst,instructionWords);
  iVar2 = *(int *)(inst[0x22] + 8);
  iVar5 = *(int *)(iVar2 * 0x38 + iVar5 + 0xc);
  if (iVar2 == 0x32) {
    uVar15 = instructionWords[3];
    bVar1 = true;
    uVar12 = instructionWords[1];
    uVar14 = instructionWords[2] >> 0x10 & 7;
    uVar13 = uVar12 >> 0xd & 7;
    instructionWords[1] = uVar14 << 0x16 |
                 uVar14 << 0x13 | uVar14 << 0x10 | uVar14 << 0xd | instructionWords[2] & 0xfe001fff;
    *(byte *)((int)instructionWords + 3) = (byte)iVar5 | 0x40;
    instructionWords[2] = uVar13 << 0x16 | uVar13 << 0x13 | uVar13 << 0x10 | uVar12 & 0xfe00ffff;
    instructionWords[3] = (uVar15 & 0xfff81fff) >> 3 & 0x380000 |
                 (uVar15 & 0xffff1fff) >> 6 & 0x70000 | uVar15 >> 9 & 0xe000 | uVar15 & 0xffc01fff;
  }
  else if (iVar5 == -1) {
    if (iVar2 < 0x32) {
      if (iVar2 < 0x30) {
        if (iVar2 == 0x1c) {
          bVar1 = true;
          *(undefined1 *)((int)instructionWords + 3) = 1;
          instructionWords[1] = instructionWords[1] & 0xfe3fffff | 0x1000000;
          instructionWords[2] = instructionWords[2] & 0xfe3fffff | 0x1000000;
        }
        else {
          if (iVar2 != 0x28) goto LAB_0019bc7c;
          uVar12 = instructionWords[1];
          bVar1 = true;
          *(undefined1 *)((int)instructionWords + 3) = 10;
          instructionWords[1] = instructionWords[2];
          instructionWords[2] = uVar12;
        }
      }
      else {
LAB_0019bbfc:
        bVar1 = false;
        *(undefined1 *)((int)instructionWords + 3) = 7;
        instructionWords[2] = instructionWords[1];
      }
    }
    else {
      if (iVar2 == 0x66) goto LAB_0019bbfc;
      if (iVar2 != 0xa5) goto LAB_0019bc7c;
      bVar1 = true;
      *(undefined1 *)((int)instructionWords + 3) = 5;
      instructionWords[3] = instructionWords[2];
    }
  }
  else {
    *(byte *)((int)instructionWords + 3) = (byte)iVar5;
LAB_0019bc7c:
    bVar1 = true;
  }
  iVar2 = (**(code **)(*inst + 0x14))(inst);
  if (iVar2 != 3) goto LAB_0019bee4;
  operandVReg = (int *)IRInst__getOperandSource(inst,1);
  iVar2 = (**(code **)(*operandVReg + 0x60))(operandVReg);
  if (iVar2 == 0) {
    uVar16 = *(undefined4 *)(*(int *)(this + 0xc) + 0x6c4);
    uVar6 = IRInst__getOperandSource(inst,1);
    iVar2 = thunk_FUN_00134de8(uVar16,uVar6);
    iVar7 = IRInst__getOperandSource(inst,1);
    iVar7 = *(int *)(iVar7 + 0x98);
  }
  else {
    uVar16 = *(undefined4 *)(*(int *)(this + 0xc) + 0x6c4);
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
    uVar16 = *(undefined4 *)(*(int *)(this + 0xc) + 0x6c4);
    uVar6 = IRInst__getOperandSource(inst,2);
    callResult = thunk_FUN_00134de8(uVar16,uVar6);
    iVar9 = IRInst__getOperandSource(inst,2);
    iVar9 = *(int *)(iVar9 + 0x98);
  }
  else {
    uVar16 = *(undefined4 *)(*(int *)(this + 0xc) + 0x6c4);
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
    uVar16 = *(undefined4 *)(*(int *)(this + 0xc) + 0x6c4);
    uVar6 = IRInst__getOperandSource(inst,3);
    iVar11 = thunk_FUN_00134de8(uVar16,uVar6);
    iVar10 = IRInst__getOperandSource(inst,3);
    iVar10 = *(int *)(iVar10 + 0x98);
  }
  else {
    uVar16 = *(undefined4 *)(*(int *)(this + 0xc) + 0x6c4);
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
    *(undefined1 *)((int)instructionWords + 3) = uVar3;
  }
  else if (iVar5 == 0xb) {
    uVar3 = 1;
    goto LAB_0019bed0;
  }
  *(byte *)((int)instructionWords + 3) = (byte)*instructionWords | 0x80;
LAB_0019bee4:
  iVar2 = ((int (*)())opcodeInfoIsVsFlagBit2)(*(undefined4 *)(this + 0x88),inst);
  if ((iVar2 != 0) && (bVar1)) {
    *(byte *)((int)instructionWords + 3) = (byte)*instructionWords | 0x40;
  }
  iVar2 = inst[0x26];
  if ((iVar2 == 5) && (inst[0x25] == 0)) {
    *(undefined4 *)(this + 0x2c) = *(undefined4 *)(this + 0x58);
    iVar2 = inst[0x26];
  }
  *instructionWords = (*(uint *)(&DAT_001b2ad0 + iVar2 * 4) & 0xf) << 8 | *instructionWords & 0xfffff0ff;
  iVar2 = FUN_00105dbc(inst,0);
  if (iVar2 == 1) {
    *(undefined4 *)(this + 0x24) = 1;
    *instructionWords = *instructionWords | 0x1000;
    uVar13 = FUN_00105c5c(inst,0);
    uVar12 = *instructionWords;
  }
  else if (iVar2 == 2) {
    uVar13 = 0;
    *(undefined4 *)(this + 0x24) = 1;
    uVar12 = *instructionWords & 0x1fffffff | 0x20000000;
    *instructionWords = uVar12;
  }
  else {
    uVar12 = *instructionWords;
    uVar13 = 0;
  }
  if (((uVar12 & 0xf00) == 0x200) || ((uVar12 & 0xf00) == 0x300)) {
    if (iVar2 == 0) {
      uVar13 = uVar13 + inst[0x25];
    }
    else {
      uVar13 = uVar13 + *(int *)(*(int *)(*(int *)(this + 0xc) + 0x6c4) + 0x3f0);
    }
  }
  else if (iVar2 == 0) {
    iVar2 = thunk_FUN_00134de8(*(undefined4 *)(*(int *)(this + 0xc) + 0x6c4),inst);
    iVar5 = inst[0x26];
    uVar13 = uVar13 + iVar2;
    if (iVar5 == 1) {
      piVar4 = *(int **)(*(int *)(this + 0xc) + 0x30c);
      iVar2 = (**(code **)(*piVar4 + 0x138))(piVar4,0);
      uVar13 = uVar13 - iVar2;
      uVar6 = ((int (*)())maxSigned)(*(undefined4 *)(this + 0x38),uVar13);
      *(undefined4 *)(this + 0x38) = uVar6;
      iVar5 = inst[0x26];
    }
    if (iVar5 == 0) {
      uVar6 = ((int (*)())maxSigned)(*(undefined4 *)(this + 0x34),uVar13);
      *(undefined4 *)(this + 0x34) = uVar6;
      uVar12 = *instructionWords;
    }
    else {
      uVar12 = *instructionWords;
    }
  }
  *instructionWords = (uVar13 & 0x7f) << 0xd | uVar12 & 0xfff01fff;
  iVar2 = IRInst__getOperandRecord(inst,0);
  uVar12 = *(uint *)(iVar2 + 0x10);
  uVar12 = (uint)((uVar12 & 0xff) == 0) << 0x17 |
           (uint)((uVar12 >> 8 & 0xff) == 0) << 0x16 |
           (uint)((uVar12 >> 0x10 & 0xff) == 0) << 0x15 |
           (uint)(uVar12 >> 0x18 == 0) << 0x14 | *instructionWords & 0xff0fffff;
  *instructionWords = uVar12;
  if (inst[0x48] != 0) {
    iVar2 = ((int (*)())opcodeInfoIsVsFlagBit2)(*(undefined4 *)(this + 0x88),inst);
    if ((iVar2 == 0) || (!bVar1)) {
      *instructionWords = uVar12 | 0x1000000;
    }
    else {
      *instructionWords = uVar12 | 0x2000000;
    }
  }
  return;
}

/* R300VMachineAssembler__encodeSourceOperand @ 0x19c130 (2376 bytes) */
int R300VMachineAssembler__encodeSourceOperand(this, inst, instructionWords, sourceNumber, operandSlot)
  int this;
  int inst;
  int instructionWords;
  int sourceNumber;
  int operandSlot;
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
  uint *sourceWord;
  undefined8 uVar21;
  uint local_88;
  uint local_84;
  int local_80;
  uint local_7c [4];
  uint local_6c [5];
  uint local_58;
  uint *local_54;
  
  sourceWord = (uint *)(instructionWords + 8);
  if (((operandSlot != 2) && (sourceWord = (uint *)(instructionWords + 0xc), operandSlot != 3)) &&
     (sourceWord = (uint *)0x0, operandSlot == 1)) {
    sourceWord = (uint *)(instructionWords + 4);
  }
  iVar10 = instructionWords;
  loopIndex2 = sourceNumber;
  a0 = (int *)IRInst__getOperandSource(inst,sourceNumber);
  if (a0[0x26] == 0x33) {
    if (sourceNumber < 2) {
      *sourceWord = *sourceWord & 0xffffe018;
      *(undefined4 *)(this + 0x80) = 1;
    }
    else {
      uVar6 = *sourceWord;
      uVar19 = *(uint *)(instructionWords + 4) & 7;
      *sourceWord = uVar19 | uVar6 & 0xfffffff8;
      uVar9 = *(uint *)(instructionWords + 4) & 0x10;
      *sourceWord = uVar9 | uVar19 | uVar6 & 0xffffffe8;
      uVar11 = *(uint *)(instructionWords + 4) & 0x80000000;
      *sourceWord = uVar11 | uVar9 | uVar19 | uVar6 & 0x7fffffe8;
      uVar8 = *(uint *)(instructionWords + 4) & 0x60000000;
      *sourceWord = uVar8 | uVar11 | uVar9 | uVar19 | uVar6 & 0x1fffffe8;
      *sourceWord = *(uint *)(instructionWords + 4) & 0x1fe0 |
                 uVar8 | uVar11 | uVar9 | uVar19 | uVar6 & 0x1fffe008;
    }
    iVar10 = IRInst__getOperandRecord(inst,sourceNumber);
    uVar19 = *(uint *)(iVar10 + 0x10);
    uVar9 = *(uint *)(sourceNumber * 0x18 + inst + 0xa0) & 1;
    iVar10 = ((int (*)())opcodeInfoIsVsFlagBit2)(*(undefined4 *)(this + 0x88),inst);
    if (iVar10 != 0) {
      if (sourceNumber != 1) {
        uVar19 = uVar19 >> 0x18;
      }
      uVar11 = ((int (*)())vsSourceSelectForConstant)(a0,uVar19 & 0xff,&local_80);
      uVar6 = *sourceWord;
      uVar11 = uVar11 & 7;
      uVar19 = uVar11 << 0xd;
      *sourceWord = uVar19 | uVar6 & 0xffff1fff;
      uVar8 = uVar9 ^ 1;
      if (local_80 == 0) {
        uVar8 = uVar9;
      }
      *sourceWord = uVar8 << 0x19 | uVar19 | uVar6 & 0xfdff1fff;
      *sourceWord = uVar8 << 0x1c |
                 uVar11 << 0x16 |
                 uVar8 << 0x1b |
                 uVar11 << 0x13 |
                 uVar8 << 0x1a | uVar11 << 0x10 | uVar8 << 0x19 | uVar19 | uVar6 & 0xe0001fff;
      return;
    }
    uVar11 = ((int (*)())vsSourceSelectForConstant)(a0,uVar19 >> 0x18,&local_80);
    uVar6 = *sourceWord;
    uVar11 = (uVar11 & 7) << 0xd;
    *sourceWord = uVar11 | uVar6 & 0xffff1fff;
    uVar8 = uVar9 ^ 1;
    if (local_80 == 0) {
      uVar8 = uVar9;
    }
    *sourceWord = uVar8 << 0x19 | uVar11 | uVar6 & 0xfdff1fff;
    uVar11 = ((int (*)())vsSourceSelectForConstant)(a0,uVar19 >> 0x10 & 0xff,&local_80);
    uVar6 = *sourceWord;
    uVar11 = (uVar11 & 7) << 0x10;
    *sourceWord = uVar11 | uVar6 & 0xfff8ffff;
    uVar8 = uVar9 ^ 1;
    if (local_80 == 0) {
      uVar8 = uVar9;
    }
    *sourceWord = uVar8 << 0x1a | uVar11 | uVar6 & 0xfbf8ffff;
    uVar11 = ((int (*)())vsSourceSelectForConstant)(a0,uVar19 >> 8 & 0xff,&local_80);
    uVar6 = *sourceWord;
    uVar11 = (uVar11 & 7) << 0x13;
    *sourceWord = uVar11 | uVar6 & 0xffc7ffff;
    uVar8 = uVar9 ^ 1;
    if (local_80 == 0) {
      uVar8 = uVar9;
    }
    *sourceWord = uVar8 << 0x1b | uVar11 | uVar6 & 0xf7c7ffff;
    uVar19 = ((int (*)())vsSourceSelectForConstant)(a0,uVar19 & 0xff,&local_80);
    uVar8 = *sourceWord;
    uVar19 = (uVar19 & 7) << 0x16;
    *sourceWord = uVar19 | uVar8 & 0xfe3fffff;
    uVar11 = uVar9 ^ 1;
    if (local_80 == 0) {
      uVar11 = uVar9;
    }
    *sourceWord = uVar11 << 0x1c | uVar19 | uVar8 & 0xee3fffff;
    return;
  }
  loopIndex = (**(code **)(*a0 + 0x60))(a0);
  if (loopIndex == 0) {
    loopIndex = FUN_00105dbc(inst,sourceNumber);
    iVar13 = a0[0x26];
    uVar17 = *(undefined4 *)(*(int *)(this + 0xc) + 0x6c4);
    piVar14 = a0;
LAB_0019c490:
    uVar19 = thunk_FUN_00134de8(uVar17,piVar14);
    *sourceWord = *(uint *)(&DAT_001b2c14 + iVar13 * 4) & 7 | *sourceWord & 0xfffffff8;
    if (iVar13 == 0x37) {
      *(undefined4 *)(this + 0x30) = *(undefined4 *)(this + 0x58);
    }
    else if (iVar13 == 1) {
      piVar14 = *(int **)(*(int *)(this + 0xc) + 0x30c);
      iVar15 = (**(code **)(*piVar14 + 0x138))(piVar14,0);
      uVar19 = uVar19 - iVar15;
    }
  }
  else {
    loopIndex = FUN_00105dbc(a0,1);
    iVar13 = IRInst__getOperandSource(a0,1);
    iVar13 = *(int *)(iVar13 + 0x98);
    if (iVar13 != 0x33) {
      uVar17 = *(undefined4 *)(*(int *)(this + 0xc) + 0x6c4);
      piVar14 = (int *)IRInst__getOperandSource(a0,1);
      goto LAB_0019c490;
    }
    if (sourceNumber < 2) {
      uVar19 = 0;
      *sourceWord = *sourceWord & 0xfffffff8;
      *(undefined4 *)(this + 0x80) = 1;
    }
    else {
      uVar6 = *sourceWord;
      uVar9 = *(uint *)(instructionWords + 4) & 7;
      *sourceWord = uVar9 | uVar6 & 0xfffffff8;
      uVar11 = *(uint *)(instructionWords + 4) & 0x10;
      uVar19 = *(uint *)(instructionWords + 4) >> 5 & 0xff;
      *sourceWord = uVar11 | uVar9 | uVar6 & 0xffffffe8;
      uVar8 = *(uint *)(instructionWords + 4) & 0x80000000;
      *sourceWord = uVar8 | uVar11 | uVar9 | uVar6 & 0x7fffffe8;
      *sourceWord = *(uint *)(instructionWords + 4) & 0x60000000 | uVar8 | uVar11 | uVar9 | uVar6 & 0x1fffffe8;
    }
  }
  iVar15 = RegKind__flagBit7(a0[0x26]);
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
    iVar15 = RegKind__flagBit7(iVar15);
  }
  if ((iVar15 != 0) && (*(uint *)(this + 0x4c) < uVar19)) {
    *(uint *)(this + 0x4c) = uVar19;
  }
  if (loopIndex - 1U < 2) {
    loopIndex = (**(code **)(*a0 + 0x60))(a0);
    if (loopIndex == 0) {
      uVar21 = FUN_00105c5c(inst,sourceNumber);
    }
    else {
      uVar21 = FUN_00105c5c(a0,1);
    }
    uVar19 = (uint)((ulonglong)uVar21 >> 0x20);
    *(undefined4 *)(this + 0x24) = 1;
    if (iVar13 == 0x28) {
      *(undefined4 *)(this + 0x4c) = 0xff;
    }
    else if (iVar13 != 0x29) {
      if (iVar13 == 0x26) {
        *(undefined4 *)(this + 0x4c) = 0xff;
        uVar9 = *sourceWord;
        *sourceWord = uVar9 | 0x10;
        iVar10 = (**(code **)(*a0 + 0x60))(a0,(int)uVar21,iVar10,loopIndex2,operandSlot,in_r8,uVar9 | 0x10);
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
          uVar9 = *sourceWord & 0x9fffffff;
          *sourceWord = uVar9;
          goto LAB_0019c710;
        }
        iVar10 = FUN_000f2d18(uVar17,0x1010101);
        if (iVar10 != 0) {
          uVar9 = *sourceWord & 0x9fffffff | 0x20000000;
          *sourceWord = uVar9;
          goto LAB_0019c710;
        }
        iVar10 = FUN_000f2d18(uVar17,0x2020202);
        if (iVar10 != 0) {
          uVar9 = *sourceWord & 0x9fffffff | 0x40000000;
          *sourceWord = uVar9;
          goto LAB_0019c710;
        }
        iVar10 = FUN_000f2d18(uVar17,0x3030303);
        if (iVar10 != 0) {
          uVar9 = *sourceWord & 0x9fffffff | 0x60000000;
          *sourceWord = uVar9;
          goto LAB_0019c710;
        }
      }
      goto LAB_0019c70c;
    }
    uVar9 = *sourceWord & 0x9fffffff | 0x80000000;
    *sourceWord = uVar9;
  }
  else {
LAB_0019c70c:
    uVar9 = *sourceWord;
  }
LAB_0019c710:
  *sourceWord = (uVar19 & 0xff) << 5 | uVar9 & 0xffffe01f;
  uVar19 = *(uint *)(sourceNumber * 0x18 + inst + 0xa0) & 1;
  iVar10 = IRInst__getOperandRecord(inst,sourceNumber);
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
                uVar17 = ((int (*)())vsSourceSelectForConstant)(uVar17,uVar9,&local_80);
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
  iVar10 = ((int (*)())opcodeInfoIsVsFlagBit2)(*(undefined4 *)(this + 0x88),inst);
  if (iVar10 == 0) {
    uVar7 = *sourceWord;
    uVar19 = (local_7c[0] & 7) << 0xd;
    *sourceWord = uVar19 | uVar7 & 0xffff1fff;
    uVar9 = (local_7c[1] & 7) << 0x10;
    *sourceWord = uVar9 | uVar19 | uVar7 & 0xfff81fff;
    uVar11 = (local_7c[2] & 7) << 0x13;
    *sourceWord = uVar11 | uVar9 | uVar19 | uVar7 & 0xffc01fff;
    uVar8 = (local_7c[3] & 7) << 0x16;
    *sourceWord = uVar8 | uVar11 | uVar9 | uVar19 | uVar7 & 0xfe001fff;
    uVar6 = (local_6c[0] & 1) << 0x19;
    *sourceWord = uVar6 | uVar8 | uVar11 | uVar9 | uVar19 | uVar7 & 0xfc001fff;
    uVar4 = (local_6c[1] & 1) << 0x1a;
    *sourceWord = uVar4 | uVar6 | uVar8 | uVar11 | uVar9 | uVar19 | uVar7 & 0xf8001fff;
    uVar5 = (local_6c[2] & 1) << 0x1b;
    *sourceWord = uVar5 | uVar4 | uVar6 | uVar8 | uVar11 | uVar9 | uVar19 | uVar7 & 0xf0001fff;
    uVar19 = (local_6c[3] & 1) << 0x1c |
             uVar5 | uVar4 | uVar6 | uVar8 | uVar11 | uVar9 | uVar19 | uVar7 & 0xe0001fff;
    *sourceWord = uVar19;
  }
  else {
    if (sourceNumber == 1) {
      uVar9 = *sourceWord;
      uVar19 = (local_7c[3] & 7) << 0xd;
      *sourceWord = uVar19 | uVar9 & 0xffff1fff;
      uVar19 = (local_6c[3] & 1) << 0x19 | uVar19 | uVar9 & 0xfdff1fff;
      *sourceWord = uVar19;
    }
    else if (sourceNumber == 2) {
      uVar9 = *sourceWord;
      uVar19 = (local_7c[0] & 7) << 0xd;
      *sourceWord = uVar19 | uVar9 & 0xffff1fff;
      uVar19 = (local_6c[0] & 1) << 0x19 | uVar19 | uVar9 & 0xfdff1fff;
      *sourceWord = uVar19;
    }
    else {
      uVar19 = *sourceWord;
    }
    uVar19 = (uVar19 & 0x2000000) << 3 |
             (uVar19 & 0x2000000) << 2 |
             (uVar19 & 0x2000000) << 1 |
             (uVar19 & 0xe000) << 9 |
             (uVar19 & 0xe000) << 6 | (uVar19 & 0xe000) << 3 | uVar19 & 0xe200ffff;
    *sourceWord = uVar19;
  }
  if ((*(int *)(this + 0x84) != 0) && ((uVar19 & 0x80000010) == 0)) {
    uVar9 = *(uint *)(instructionWords + 0xc);
    *(uint *)(instructionWords + 0xc) = uVar19 & 3 | uVar9 & 0xfffffffc;
    *(uint *)(instructionWords + 0xc) = *sourceWord & 0x1fe0 | uVar19 & 3 | uVar9 & 0xffffe01c;
  }
  if ((*(int *)(this + 0x80) != 0) && (sourceNumber == 2)) {
    uVar8 = *(uint *)(instructionWords + 4);
    uVar19 = *sourceWord & 7;
    *(uint *)(instructionWords + 4) = uVar19 | uVar8 & 0xfffffff8;
    uVar9 = *sourceWord & 0x1fe0;
    *(uint *)(instructionWords + 4) = uVar9 | uVar19 | uVar8 & 0xffffe018;
    uVar11 = *sourceWord & 0x10;
    *(uint *)(instructionWords + 4) = uVar11 | uVar9 | uVar19 | uVar8 & 0xffffe008;
    uVar6 = *sourceWord;
    *(uint *)(instructionWords + 4) = uVar6 & 0x80000000 | uVar11 | uVar9 | uVar19 | uVar8 & 0x7fffe008;
    *(uint *)(instructionWords + 4) =
         *sourceWord & 0x60000000 | uVar6 & 0x80000000 | uVar11 | uVar9 | uVar19 | uVar8 & 0x1fffe008;
  }
  return;
}

/* R300VMachineAssembler__encodeDualMathOperands @ 0x19ca78 (1916 bytes) */
int R300VMachineAssembler__encodeDualMathOperands(this, inst, instructionWords)
  int this;
  int *inst;
  uint *instructionWords;
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
  uint *dualMathWord;
  undefined4 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  int local_48 [4];
  uint local_38;
  uint local_34 [2];
  
  dualMathWord = instructionWords + 3;
  *instructionWords = *instructionWords | 0x10000000;
  a2 = instructionWords;
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
    *(undefined4 *)(this + 0x30) = *(undefined4 *)(this + 0x58);
  }
  iVar6 = (**(code **)(*operandVReg + 0x60))(operandVReg);
  if (iVar6 == 0) {
    uVar13 = thunk_FUN_00134de8(*(undefined4 *)(*(int *)(this + 0xc) + 0x6c4),operandVReg);
  }
  else {
    uVar12 = *(undefined4 *)(*(int *)(this + 0xc) + 0x6c4);
    uVar7 = IRInst__getOperandSource(operandVReg,1);
    uVar13 = thunk_FUN_00134de8(uVar12,uVar7);
  }
  iVar6 = (int)((ulonglong)uVar13 >> 0x20);
  if (loopIndex == 1) {
    piVar8 = *(int **)(*(int *)(this + 0xc) + 0x30c);
    iVar9 = (**(code **)(*piVar8 + 0x138))(piVar8,0);
    uVar14 = ((int (*)())maxSigned)(*(undefined4 *)(this + 0x38),iVar6 - iVar9);
    uVar13 = CONCAT44(iVar6 - iVar9,(int)uVar14);
    *(int *)(this + 0x38) = (int)((ulonglong)uVar14 >> 0x20);
  }
  else if (loopIndex == 0) {
    uVar14 = ((int (*)())maxSigned)(*(undefined4 *)(this + 0x34),iVar6);
    uVar13 = CONCAT44(iVar6,(int)uVar14);
    *(int *)(this + 0x34) = (int)((ulonglong)uVar14 >> 0x20);
  }
  uVar3 = (uint)((ulonglong)uVar13 >> 0x20);
  uVar2 = inst[0x2e];
  if ((uVar2 & 2) == 0) {
    uVar10 = *dualMathWord;
  }
  else {
    uVar10 = *dualMathWord | 8;
    *dualMathWord = uVar10;
    uVar2 = inst[0x2e];
  }
  if ((uVar2 & 1) != 0) {
    uVar10 = uVar10 | 0x2000000;
    *dualMathWord = uVar10;
  }
  if ((inst[0x34] & 1U) != 0) {
    uVar10 = uVar10 | 0x4000000;
    *dualMathWord = uVar10;
  }
  if (operandVReg[0x26] == 0x33) {
    uVar2 = instructionWords[1];
    if ((uVar2 & 0x80000010) == 0) {
      *dualMathWord = uVar2 & 3 | uVar10 & 0xfffffffc;
      *dualMathWord = instructionWords[1] & 0x1fe0 | uVar2 & 3 | uVar10 & 0xffffe01c;
    }
    else {
      uVar3 = instructionWords[2];
      if ((uVar3 & 0x80000010) == 0) {
        *dualMathWord = uVar3 & 3 | uVar10 & 0xfffffffc;
        *dualMathWord = instructionWords[2] & 0x1fe0 | uVar3 & 3 | uVar10 & 0xffffe01c;
      }
      else if (((uVar2 & 7) == 0) && ((uVar3 & 7) == 0)) {
        *dualMathWord = uVar10 & 0xffffe01c | 2;
      }
      else {
        *dualMathWord = uVar10 & 0xffffe01c;
      }
    }
    *(undefined4 *)(this + 0x84) = 1;
    loopIndex = IRInst__getOperandRecord(inst,1);
    uVar2 = ((int (*)())vsSourceSelectForConstant)(operandVReg,(uint)*(byte *)(loopIndex + 0x13),local_48);
    uVar3 = *dualMathWord;
    uVar2 = (uVar2 & 7) << 0xd;
    *dualMathWord = uVar2 | uVar3 & 0xffff1fff;
    uVar10 = uVar3 >> 0x19 & 1;
    if (local_48[0] != 0) {
      uVar10 = 1 - uVar10;
    }
    *dualMathWord = (uVar10 & 1) << 0x19 | uVar2 | uVar3 & 0xfdff1fff;
    loopIndex = (**(code **)(*inst + 0x14))(inst);
    if (1 < loopIndex) {
      uVar7 = IRInst__getOperandSource(inst,2);
      loopIndex = IRInst__getOperandRecord(inst,2);
      uVar2 = ((int (*)())vsSourceSelectForConstant)(uVar7,(uint)*(byte *)(loopIndex + 0x10),local_48);
      uVar3 = *dualMathWord;
      uVar2 = (uVar2 & 7) << 0x10;
      *dualMathWord = uVar2 | uVar3 & 0xfff8ffff;
      uVar10 = uVar3 >> 0x1a & 1;
      if (local_48[0] != 0) {
        uVar10 = 1 - uVar10;
      }
      *dualMathWord = (uVar10 & 1) << 0x1a | uVar2 | uVar3 & 0xfbf8ffff;
    }
    goto LAB_0019d024;
  }
  *dualMathWord = *(uint *)(&DAT_001b2c14 + loopIndex * 4) & 3 | uVar10 & 0xfffffffc;
  loopIndex = (**(code **)(*operandVReg + 0x60))(operandVReg,(int)uVar13,a2,in_r6,in_r7,in_r8,loopIndex * 4);
  if (loopIndex == 0) {
    loopIndex = RegKind__flagBit7(operandVReg[0x26]);
  }
  else {
    loopIndex = IRInst__getOperandSource(operandVReg,1);
    loopIndex = RegKind__flagBit7(*(undefined4 *)(loopIndex + 0x98));
  }
  if ((loopIndex != 0) && (*(uint *)(this + 0x4c) < uVar3)) {
    *(uint *)(this + 0x4c) = uVar3;
  }
  *dualMathWord = (uVar3 & 0xff) << 5 | *dualMathWord & 0xffffe01f;
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
            uVar3 = ((int (*)())vsSourceSelectForConstant)(uVar12,(uint)bVar1,local_48);
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
            uVar2 = ((int (*)())vsSourceSelectForConstant)(uVar7,(uint)bVar1,local_48);
            goto LAB_0019d014;
          }
          loopIndex = loopIndex + 1;
        } while (loopIndex <= operandVReg[0x21]);
      }
    }
    uVar2 = 0;
  }
LAB_0019d014:
  *dualMathWord = (uVar2 & 7) << 0x10 | (uVar3 & 7) << 0xd | *dualMathWord & 0xfff81fff;
LAB_0019d024:
  piVar5 = *(int **)(*(int *)(this + 0xc) + 0x30c);
  loopIndex = (**(code **)(*piVar5 + 0x16c))(piVar5);
  uVar2 = *(uint *)(*(int *)(inst[0x22] + 8) * 0x38 + loopIndex + 0xc);
  if (uVar2 == 0xffffffff) {
    if (*(int *)(inst[0x22] + 8) == 0x66) {
      *dualMathWord = *dualMathWord & 0xfe18ffff | 0x1450000;
    }
  }
  else {
    uVar3 = (uVar2 & 0xf) << 0x15 | *dualMathWord & 0xfe1fffff;
    *dualMathWord = uVar3;
    if (0xf < (int)uVar2) {
      *dualMathWord = uVar3 | 4;
    }
  }
  loopIndex = IRInst__getOperandRecord(inst,0);
  loopIndex = *(int *)(loopIndex + 0x10);
  if (loopIndex == 0x10101) {
    *dualMathWord = *dualMathWord & 0xe7ffffff;
  }
  else if (loopIndex == 0x1000101) {
    *dualMathWord = *dualMathWord & 0xe7ffffff | 0x8000000;
  }
  else if (loopIndex == 0x1010001) {
    *dualMathWord = *dualMathWord & 0xe7ffffff | 0x10000000;
  }
  else if (loopIndex == 0x1010100) {
    *dualMathWord = *dualMathWord & 0xe7ffffff | 0x18000000;
  }
  loopIndex = thunk_FUN_00134de8(*(undefined4 *)(*(int *)(this + 0xc) + 0x6c4),inst);
  piVar5 = *(int **)(*(int *)(this + 0xc) + 0x30c);
  iVar6 = (**(code **)(*piVar5 + 0x138))(piVar5,0);
  *dualMathWord = (loopIndex - iVar6) * 0x80000 & 0x180000U | *dualMathWord & 0xffe7ffff;
  if (inst[0x48] != 0) {
    piVar5 = *(int **)(*(int *)(this + 0xc) + 0x30c);
    (**(code **)(*piVar5 + 0x80))(piVar5);
    *instructionWords = *instructionWords | 0x2000000;
  }
  return;
}

/* R300VMachineAssembler__vslot14_assembleInstruction @ 0x19d1f4 (572 bytes) */
int R300VMachineAssembler__vslot14_assembleInstruction(this, inst)
  int this;
  int *inst;
{
  int iVar1;
  int iVar2;
  uint *instructionWords;
  
  iVar2 = *(int *)(this + 8);
  iVar1 = *(int *)(this + 0x58) * 8;
  if (*(int *)(iVar2 + iVar1) == 0) {
    *(int **)(iVar2 + iVar1) = inst;
  }
  else {
    *(int **)(iVar2 + iVar1 + 4) = inst;
  }
  instructionWords = (uint *)(*(int *)(this + 0x58) * 0x10 + *(int *)(this + 0x44));
  iVar1 = ((int (*)())opcodeInfoIsVsFlagBit2)(*(undefined4 *)(this + 0x88),inst);
  if ((iVar1 == 0) || (*(int *)(this + 0x7c) == 0)) {
    *(undefined4 *)(this + 0x84) = 0;
    *(undefined4 *)(this + 0x80) = 0;
    iVar1 = (**(code **)(*inst + 0x14))(inst);
    if (0 < iVar1) {
      ((int (*)())R300VMachineAssembler__encodeSourceOperand)(this,inst,instructionWords,1,1);
    }
    iVar1 = (**(code **)(*inst + 0x14))(inst);
    if (iVar1 < 2) {
      ((int (*)())copyLaneWord)(instructionWords,1,2);
    }
    else {
      ((int (*)())R300VMachineAssembler__encodeSourceOperand)(this,inst,instructionWords,2,2);
    }
    iVar1 = (**(code **)(*inst + 0x14))(inst);
    if (iVar1 < 3) {
      if (*(int *)(this + 0x7c) == 0) {
        ((int (*)())copyLaneWord)(instructionWords,2,3);
      }
    }
    else {
      ((int (*)())R300VMachineAssembler__encodeSourceOperand)(this,inst,instructionWords,3,3);
    }
    ((int (*)())R300VMachineAssembler__encodeDestinationWord)(this,inst,instructionWords);
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
    ((int (*)())R300VMachineAssembler__encodeDualMathOperands)(this,inst,instructionWords);
  }
  if (inst[0x47] == 2) {
    *instructionWords = *instructionWords & 0xf7ffffff | 0x4000000;
  }
  else if (inst[0x47] == 3) {
    *instructionWords = *instructionWords | 0xc000000;
  }
  return;
}

/* R300VMachineAssembler__getOrAllocateScratchRegister @ 0x19d430 (68 bytes) */
int R300VMachineAssembler__getOrAllocateScratchRegister(this, registerAllocator)
  int this;
  undefined4 registerAllocator;
{
  undefined4 uVar1;
  
  if (*(int *)(this + 0x8c) < 0) {
    uVar1 = FUN_00130690(registerAllocator,0);
    *(undefined4 *)(this + 0x8c) = uVar1;
  }
  return;
}

/* R520VMachineAssembler__vslot33_noOp @ 0x19d474 (4 bytes) */
int R520VMachineAssembler__vslot33_noOp()
{
  return;
}

/* R520VMachineAssembler__vslot12_visitNode @ 0x19d478 (140 bytes) */
int R520VMachineAssembler__vslot12_visitNode(this, node, visitFlag)
  int this;
  int *node;
  int visitFlag;
{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  if (visitFlag == 0) {
    puVar3 = (undefined4 *)0x0;
    uVar2 = *(uint *)(*(int *)(this + 0x94) + 4);
    uVar1 = uVar2 - 1;
    if (uVar1 < uVar2) {
      puVar3 = (undefined4 *)(uVar1 * 4 + *(int *)(*(int *)(this + 0x94) + 8));
    }
    FUN_000e2bf4(node + 0x24,*puVar3);
  }
                    
                    
  (**(code **)(*node + 0x44))(node,*(undefined4 *)(this + 0x10),visitFlag);
  return;
}

/* R520VMachineAssembler__getOrCreateConstantZeroInst @ 0x19d4e8 (116 bytes) */
int R520VMachineAssembler__getOrCreateConstantZeroInst(this)
  int this;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 *instAlloc;
  undefined4 arenaAt378;
  
  iVar1 = *(int *)(this + 0x90);
  if (iVar1 == 0) {
    uVar2 = FUN_00130690(*(undefined4 *)(*(int *)(this + 0xc) + 0x6c4),0);
    arenaAt378 = *(undefined4 *)(*(int *)(this + 0xc) + 0x378);
    instAlloc = (undefined4 *)Arena__alloc(arenaAt378,0x168);
    *instAlloc = arenaAt378;
    FUN_00109554(instAlloc + 1,*(undefined4 *)(this + 0xc));
    *(undefined4 **)(this + 0x90) = instAlloc + 1;
    instAlloc[0x27] = 0;
    instAlloc[0x26] = uVar2;
    iVar1 = *(int *)(this + 0x90);
  }
  return iVar1;
}

/* R520VMachineAssembler__vslot37_closeConditional @ 0x19d590 (528 bytes) */
int R520VMachineAssembler__vslot37_closeConditional(this, node, extra1, compiler)
  int this;
  int *node;
  undefined4 extra1;
  int compiler;
{
  int *newInst;
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int callResult;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  int conditionBlock;
  uint *puVar9;
  
  conditionBlock = node[0x4e];
  callResult = DList__count(conditionBlock + 0x90);
  if ((callResult < 3) && (callResult = FUN_000e79e8(conditionBlock), callResult != 0)) {
    piVar7 = (int *)0x0;
    if (*(int *)(*(int *)(conditionBlock + 0xd0) + 4) != 0) {
      piVar7 = *(int **)(*(int *)(conditionBlock + 0xd0) + 8);
    }
    if (*piVar7 == node[0x4f]) {
      return;
    }
  }
  callResult = (**(code **)(*node + 0x40))(node);
  if (callResult == 0) {
    if ((node[0x51] == 0) || (*(int *)(*(int *)(this + 0x94) + 4) != 2)) {
      if (**(int **)(compiler + 0x6c4) == 0) {
        newInst = (int *)IRInst__create(0x57,compiler);
        iVar6 = ((int (*)())R520VMachineAssembler__getOrCreateConstantZeroInst)(this);
        callResult = DAT_001b2d50;
        newInst[0x25] = *(int *)(iVar6 + 0x94);
        newInst[0x27] = callResult;
        newInst[0x26] = 0;
        IRInst__setOperandSource(newInst,1,iVar6,0,compiler);
        uVar1 = DAT_001b2d4c;
        callResult = IRInst__getOperandRecord(newInst,1);
        *(undefined4 *)(callResult + 0x10) = uVar1;
        (**(code **)(*newInst + 0x84))(newInst,0);
        Block__prependInst(conditionBlock,newInst);
        return;
      }
    }
    else {
      Vector__removeAt(*(int *)(this + 0x94),1);
      puVar9 = *(uint **)(this + 0x94);
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
    callResult = *(int *)(*(int *)(this + 0x10) + 0x24);
    uVar3 = *(uint *)(callResult + 4);
    uVar2 = uVar3 - 1;
    if (uVar2 < uVar3) {
      piVar7 = (int *)(uVar2 * 4 + *(int *)(callResult + 8));
    }
    callResult = *piVar7;
    ((int (*)())R300VMachineAssembler__transitionState)(this,4);
    *(int *)(callResult + 0x14) = *(int *)(this + 0x58) + -2;
  }
  return;
}

/* R520VMachineAssembler__vslot32_assembleWithPredicateClear @ 0x19d7a0 (184 bytes) */
int R520VMachineAssembler__vslot32_assembleWithPredicateClear(this, node, block, compiler)
  int *this;
  int node;
  undefined4 block;
  undefined4 compiler;
{
  int iVar1;
  int *newInst;
  int iVar3;
  
  if (**(int **)(node + 0xac) == 0) {
    iVar1 = ((int (*)())R520VMachineAssembler__getOrCreateConstantZeroInst)(this);
    iVar3 = *(int *)(iVar1 + 0x94);
    newInst = (int *)IRInst__create(0x59,compiler);
    iVar1 = DAT_001b2d50;
    newInst[0x25] = iVar3;
    newInst[0x26] = 0;
    newInst[0x27] = iVar1;
    (**(code **)(*newInst + 0x84))(newInst,3);
    Block__appendInst(node,newInst);
  }
                    
                    
  (**(code **)(*this + 0x34))(this,block,*(undefined4 *)(node + 0xdc));
  return;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl FUN_00197b30");
asm(".set FUN_00197b30, _R300MachineAssembler__emitTexRecord");
asm(".globl FUN_00197de4");
asm(".set FUN_00197de4, _R300MachineAssembler__rgbSelectForLiteralFloat");
asm(".globl FUN_00197ecc");
asm(".set FUN_00197ecc, _R300MachineAssembler__alphaSelectForLiteralFloat");
asm(".globl FUN_00197fb4");
asm(".set FUN_00197fb4, _R300MachineAssembler__setTempDestination");
asm(".globl FUN_00198084");
asm(".set FUN_00198084, _R300MachineAssembler__setOutputDestination");
asm(".globl FUN_001981ac");
asm(".set FUN_001981ac, _R300MachineAssembler__assembleAluInstruction");
asm(".globl FUN_0019a2f0");
asm(".set FUN_0019a2f0, _R300VMachineAssembler__finishProgram");
asm(".globl FUN_0019a3bc");
asm(".set FUN_0019a3bc, _R300VMachineAssembler__logStatistics");
asm(".globl FUN_0019a484");
asm(".set FUN_0019a484, _R300VMachineAssembler__copyControlFlowToOutput");
asm(".globl FUN_0019a510");
asm(".set FUN_0019a510, _R300VMachineAssembler__clearCurrentInstruction");
asm(".globl FUN_0019a618");
asm(".set FUN_0019a618, _R300VMachineAssembler__vslot2_exceedsLimits");
asm(".globl FUN_0019a690");
asm(".set FUN_0019a690, _R300VMachineAssembler__vslot49_advanceInstruction");
asm(".globl FUN_0019a6a0");
asm(".set FUN_0019a6a0, _R300VMachineAssembler__vslot48_declareAndAssemble");
asm(".globl FUN_0019a80c");
asm(".set FUN_0019a80c, _R300VMachineAssembler__vslot15_assembleUnlessConstantMove");
asm(".globl FUN_0019a8a8");
asm(".set FUN_0019a8a8, _R300VMachineAssembler__vslot16_noOp");
asm(".globl FUN_0019a8ac");
asm(".set FUN_0019a8ac, _R300VMachineAssembler__vslot18_callSlot14");
asm(".globl FUN_0019a8bc");
asm(".set FUN_0019a8bc, _R300VMachineAssembler__vslot19_callSlot14");
asm(".globl FUN_0019a8d4");
asm(".set FUN_0019a8d4, _R300VMachineAssembler__vslot43_beginLoop");
asm(".globl FUN_0019a954");
asm(".set FUN_0019a954, _R300VMachineAssembler__vslot44_endLoopBody");
asm(".globl FUN_0019a9dc");
asm(".set FUN_0019a9dc, _R300VMachineAssembler__vslot45_endLoop");
asm(".globl FUN_0019aa7c");
asm(".set FUN_0019aa7c, _R300VMachineAssembler__vslot46_leaveLoop");
asm(".globl FUN_0019aaf4");
asm(".set FUN_0019aaf4, _R300VMachineAssembler__vslot27_assembleOrFail");
asm(".globl FUN_0019ab60");
asm(".set FUN_0019ab60, _R300VMachineAssembler__vslot25_assembleOrFail");
asm(".globl FUN_0019abc4");
asm(".set FUN_0019abc4, _R300VMachineAssembler__vslot28_assembleChildOrFail");
asm(".globl FUN_0019ac2c");
asm(".set FUN_0019ac2c, _R300VMachineAssembler__vslot38_appendCallEntry");
asm(".globl FUN_0019aca4");
asm(".set FUN_0019aca4, _R300VMachineAssembler__vslot42_noOp");
asm(".globl FUN_0019acb0");
asm(".set FUN_0019acb0, _R300VMachineAssembler__init");
asm(".globl FUN_0019adf8");
asm(".set FUN_0019adf8, _R300VMachineAssembler__vslot6_setLoopStack");
asm(".globl FUN_0019ae80");
asm(".set FUN_0019ae80, _R300VMachineAssembler__vslot24_assembleWithTarget");
asm(".globl FUN_0019aee8");
asm(".set FUN_0019aee8, _R300VMachineAssembler__vslot30_assembleBlockThenSlot40");
asm(".globl FUN_0019af40");
asm(".set FUN_0019af40, _R300VMachineAssembler__vslot37_patchControlFlowTarget");
asm(".globl FUN_0019b3c8");
asm(".set FUN_0019b3c8, _R300VMachineAssembler__assembleBlock");
asm(".globl FUN_0019b6a0");
asm(".set FUN_0019b6a0, _R300VMachineAssembler__vslot40_endControlFlowBlock");
asm(".globl FUN_0019b748");
asm(".set FUN_0019b748, _R300VMachineAssembler__vslot39_appendBranchEntry");
asm(".globl FUN_0019b808");
asm(".set FUN_0019b808, _R300VMachineAssembler__vslot29_endIfBlock");
asm(".globl FUN_0019b8bc");
asm(".set FUN_0019b8bc, _R300VMachineAssembler__create");
asm(".globl FUN_0019b9ac");
asm(".set FUN_0019b9ac, _MachineAssembler__dtor_19b9ac");
asm(".globl FUN_0019ba3c");
asm(".set FUN_0019ba3c, _R300VMachineAssembler__deleting_dtor");
asm(".globl FUN_0019d1f4");
asm(".set FUN_0019d1f4, _R300VMachineAssembler__vslot14_assembleInstruction");
asm(".globl FUN_0019d474");
asm(".set FUN_0019d474, _R520VMachineAssembler__vslot33_noOp");
asm(".globl FUN_0019d478");
asm(".set FUN_0019d478, _R520VMachineAssembler__vslot12_visitNode");
asm(".globl FUN_0019d590");
asm(".set FUN_0019d590, _R520VMachineAssembler__vslot37_closeConditional");
asm(".globl FUN_0019d7a0");
asm(".set FUN_0019d7a0, _R520VMachineAssembler__vslot32_assembleWithPredicateClear");
