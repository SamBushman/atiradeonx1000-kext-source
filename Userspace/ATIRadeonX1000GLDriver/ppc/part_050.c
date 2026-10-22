#include "decls.h"

/* R300VSchedModel__vslot12 @ 0x19156c (412 bytes) */
int R300VSchedModel__vslot12(this, inst)
  undefined4 this;
  int inst;
{
  int iVar1;
  int iVar2;
  int *operandVReg;
  
  if (((*(uint *)(inst + 0x14) & 2) == 0) &&
     ((*(int *)(inst + 0x98) == 0 || (*(int *)(inst + 0x98) == 1)))) {
    iVar2 = *(int *)(inst + 0x88);
    iVar1 = *(int *)(iVar2 + 8);
    if ((iVar1 == 0x66) || (iVar1 == 0x36)) {
      return 1;
    }
    if (iVar1 == 0x31) {
      iVar1 = FUN_000f3a30(inst);
      if (iVar1 == 1) {
        return 1;
      }
      iVar2 = *(int *)(inst + 0x88);
    }
    if (((*(int *)(iVar2 + 8) == 0x13) && (iVar1 = FUN_000f3a30(inst), iVar1 == 1)) &&
       ((*(uint *)(inst + 0xb8) & 1) == (*(uint *)(inst + 0xd0) & 1))) {
      iVar1 = IRInst__getOperandSource(inst,1);
      iVar2 = IRInst__getOperandSource(inst,2);
      if (iVar1 == iVar2) {
        return 1;
      }
      operandVReg = (int *)IRInst__getOperandSource(inst,1);
      if (((((operandVReg[0x20] != 0) && (iVar1 = FUN_00126760(operandVReg[0x26]), iVar1 != 0)) &&
           (((operandVReg[5] & 2U) == 0 &&
            ((iVar1 = (**(code **)(*operandVReg + 0x50))(operandVReg), iVar1 == 0 &&
             (operandVReg = (int *)IRInst__getOperandSource(inst,2), operandVReg[0x20] != 0)))))) &&
          (iVar1 = FUN_00126760(operandVReg[0x26]), iVar1 != 0)) &&
         (((operandVReg[5] & 2U) == 0 && (iVar1 = (**(code **)(*operandVReg + 0x50))(operandVReg), iVar1 == 0)))) {
        return 1;
      }
    }
  }
  return 0;
}

/* isLiteralZeroHalfOrOne @ 0x191710 (76 bytes) */
undefined4 isLiteralZeroHalfOrOne(double value)
{
  if (((value != (double)FLOAT_001aa0d4) && (value != (double)FLOAT_001aa10c)) &&
     (value != (double)FLOAT_001aa0e8)) {
    return 0;
  }
  return 1;
}

/* FudoPs__encodeImmediateFloat @ 0x191888 (184 bytes) */
undefined4 FudoPs__encodeImmediateFloat(int this,undefined4 unused,uint *exponentOut,uint *mantissaOut,double value)
{
  float value32;
  uint loopIndex;
  int loopRemaining;
  
  if ((double)FLOAT_001aa0d4 < value) {
    value32 = (float)value;
    if (((uint)GH_F2U(value32) & 1) == 0) {
      loopIndex = (uint)GH_F2U(value32) >> 1 & 0xff;
      *exponentOut = loopIndex;
      if ((loopIndex == 0) || (*exponentOut = loopIndex - 0x78, loopIndex - 0x78 < 0x10)) {
        if (*exponentOut == 0) {
          loopIndex = 0;
          loopRemaining = 8;
          do {
            if (value == (double)*(float *)(0x00001740 + this + 4)) {
              *mantissaOut = loopIndex;
              return 1;
            }
            loopIndex = loopIndex + 1;
            this = this + 4;
            loopRemaining = loopRemaining + -1;
          } while (loopRemaining != 0);
        }
        else {
          *mantissaOut = (uint)GH_F2U(value32) >> 9;
          if (((uint)GH_F2U(value32) >> 9 & 0xfffff) == 0) {
            *mantissaOut = (uint)GH_F2U(value32) >> 0x1d;
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

/* FudoPs__encodeUniformImmediate @ 0x191940 (152 bytes) */
int FudoPs__encodeUniformImmediate(this, values, laneSelectors)
  undefined4 this;
  float *values;
  undefined4 laneSelectors;
{
  unsigned int ghidra_home[8] = { this, values, laneSelectors, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  bool haveFirstValue;
  char *loopIndex;
  undefined4 callResult;
  int loopRemaining;
  double commonValue;
  undefined1 auStack_28 [4];
  undefined1 auStack_24 [32];
  
  haveFirstValue = false;
  loopRemaining = 4;
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = laneSelectors;
  commonValue = (double)FLOAT_001aa0d4;
  loopIndex = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 8));
  do {
    if (*loopIndex != '\x04') {
      if (haveFirstValue) {
        if ((double)*values != commonValue) {
          return 0;
        }
        haveFirstValue = true;
      }
      else {
        commonValue = (double)*values;
        haveFirstValue = true;
      }
    }
    loopIndex = loopIndex + 1;
    values = values + 1;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  callResult = ((undefined4 (*)())FudoPs__encodeImmediateFloat)(this,values,auStack_28,auStack_24,commonValue);
  return callResult;
}

/* FudoPs__vslot85 @ 0x1919d8 (344 bytes) */
int FudoPs__vslot85(this, param_2, param_3, param_4)
  undefined4 this;
  int param_2;
  dword *param_3;
  int *param_4;
{
  float fVar1;
  bool bVar2;
  int *piVar3;
  uint *loopIndex2;
  undefined *puVar5;
  int iVar6;
  dword *loopIndex;
  undefined4 uVar8;
  int loopRemaining2;
  int loopRemaining;
  uint local_38;
  float local_20;
  
  if (*param_4 != 0x4040404) {
    puVar5 = &DAT_001b19e0;
    fVar1 = 0.0;
    loopRemaining2 = 4;
    bVar2 = true;
    iVar6 = 1;
    piVar3 = param_4;
    loopIndex = param_3;
    do {
      if (*(char *)piVar3 != '\x04') {
        if (bVar2) {
          fVar1 = (float)*loopIndex;
          bVar2 = false;
        }
        else if ((float)*loopIndex != fVar1) {
          iVar6 = 0;
        }
      }
      piVar3 = (int *)((int)piVar3 + 1);
      loopIndex = loopIndex + 1;
      loopRemaining2 = loopRemaining2 + -1;
    } while (loopRemaining2 != 0);
    piVar3 = param_4;
    if (iVar6 == 0) {
      loopRemaining2 = FUN_000f6a04(param_2,param_3,*param_4);
    }
    else {
      puVar5 = (undefined *)0x4;
      loopRemaining2 = 4;
      loopIndex2 = &local_38;
      do {
        *loopIndex2 = 0x7ffffffe;
        loopIndex2 = loopIndex2 + 1;
        loopRemaining2 = loopRemaining2 + -1;
      } while (loopRemaining2 != 0);
      loopIndex = ((unsigned char *)0x4);
      loopRemaining2 = 0;
      loopRemaining = 4;
      do {
        local_20 = fVar1;
        *(float *)(loopRemaining2 + (int)&local_38) = fVar1;
        loopRemaining2 = loopRemaining2 + 4;
        loopRemaining = loopRemaining + -1;
      } while (loopRemaining != 0);
      loopRemaining2 = FUN_000f6a04(param_2,&local_38,0x10203);
    }
    if (loopRemaining2 != 0) {
      return loopRemaining2;
    }
    uVar8 = *(undefined4 *)(param_2 + 0x3ac);
    iVar6 = FUN_000f5f94(uVar8,param_3,param_4,piVar3,puVar5,iVar6,loopIndex);
    if (iVar6 != 0) {
      return iVar6;
    }
    iVar6 = FUN_000f57f0(uVar8,param_3,param_4,piVar3);
    if (iVar6 != 0) {
      return iVar6;
    }
  }
  return 0;
}

/* FudoPs__vslot59 @ 0x191b30 (316 bytes) */
int FudoPs__vslot59(this, inst, param_3, param_4, param_5)
  undefined4 this;
  undefined4 inst;
  undefined4 param_3;
  uint param_4;
  int param_5;
{
  char cVar1;
  float fVar2;
  int *a0;
  int loopRemaining;
  undefined4 uVar4;
  float *loopIndex2;
  int loopIndex;
  uint local_58;
  undefined4 local_54;
  uint local_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  undefined4 local_30;
  
  local_58 = param_4 << 0x18 | (param_4 & 0xff00) << 8 | param_4 >> 8 & 0xff00 | param_4 >> 0x18;
  a0 = (int *)IRInst__getOperandSource(inst,param_3);
  loopRemaining = (**(code **)(*a0 + 0x48))(a0);
  if (loopRemaining == 0) {
LAB_00191c54:
    uVar4 = 0;
  }
  else {
    loopRemaining = IRInst__getOperandRecord(inst,param_3);
    loopIndex = 0;
    local_54 = *(undefined4 *)(loopRemaining + 0x10);
    loopRemaining = 4;
    loopIndex2 = (float *)&local_50;
    do {
      cVar1 = *(char *)((int)&local_58 + loopIndex);
      *loopIndex2 = 0.0;
      if (cVar1 == '\0') {
        if ((((int)*(char *)(a0 + 0x57) >> (*(byte *)((int)&local_54 + loopIndex) & 0x3f) & 1U) == 0) ||
           (((fVar2 = GH_U2F((unsigned int)(a0[(uint)*(byte *)((int)&local_54 + loopIndex) * 6 + 8])), fVar2 != 0.0 &&
             (fVar2 != 1.0)) && (local_30 = 0x3f000000, fVar2 != 0.5)))) goto LAB_00191c54;
        *loopIndex2 = fVar2;
      }
      loopIndex = loopIndex + 1;
      loopIndex2 = loopIndex2 + 1;
      loopRemaining = loopRemaining + -1;
    } while (loopRemaining != 0);
    ((void (*)())FUN_000f79c4)(inst,*(undefined4 *)(param_5 + 0x6c4),param_3,(double)GH_U2F((unsigned int)(local_50)),
                 (double)fStack_4c,(double)fStack_48,(double)fStack_44);
    uVar4 = 1;
  }
  return uVar4;
}

/* FudoChip__vslot2 @ 0x191c6c (16 bytes) */
int FudoChip__vslot2(this)
  int this;
{
  *(undefined4 *)(*(int *)(this + 8) + 0x2c) = 0x100;
  return;
}

/* FudoPs__classifyLiteralOperand @ 0x191c7c (428 bytes) */
int FudoPs__classifyLiteralOperand(this, laneValues, kindOut, laneSelectors, compiler)
  int *this;
  float *laneValues;
  undefined4 *kindOut;
  undefined4 laneSelectors;
  undefined4 compiler;
{
  unsigned int ghidra_home[8] = { this, laneValues, kindOut, laneSelectors, compiler, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  float laneValue;
  bool haveFirstValue;
  char *loopIndex;
  float *loopIndex3;
  char *loopIndex2;
  int loopRemaining;
  int loopRemaining2;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 12)) = laneSelectors;
  *kindOut = 0xffffffff;
  loopIndex = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 12));
  loopRemaining = 4;
  loopIndex3 = laneValues;
  loopIndex2 = loopIndex;
  while ((((*loopIndex2 == '\x04' || (laneValue = *loopIndex3, laneValue == FLOAT_001aa0d4)) ||
          (laneValue == FLOAT_001aa10c)) || (laneValue == 1.0))) {
    loopIndex2 = loopIndex2 + 1;
    loopIndex3 = loopIndex3 + 1;
    loopRemaining = loopRemaining + -1;
    if (loopRemaining == 0) {
      loopRemaining = (int)loopIndex2 - (int)loopIndex;
      do {
        if (*loopIndex == '\x04') {
          *laneValues = 0.0;
        }
        loopIndex = loopIndex + 1;
        laneValues = laneValues + 1;
        loopRemaining = loopRemaining + -1;
      } while (loopRemaining != 0);
      return 1;
    }
  }
  loopRemaining = Compiler__isOptionEnabled(compiler,0x2f);
  if (loopRemaining == 0) {
    return 0;
  }
  loopRemaining = 4;
  haveFirstValue = true;
  loopIndex3 = laneValues;
  laneValue = FLOAT_001aa0d4;
  do {
    if (*loopIndex != '\x04') {
      if (haveFirstValue) {
        laneValue = *loopIndex3;
        haveFirstValue = false;
      }
      else if (*loopIndex3 != laneValue) {
        return 0;
      }
    }
    loopIndex = loopIndex + 1;
    loopIndex3 = loopIndex3 + 1;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  loopRemaining = (**(code **)(*this + 0x98))(this,laneValues,(*(unsigned int *)((unsigned char *)ghidra_home + 12)));
  if (loopRemaining != 0) {
    loopRemaining = 0;
    loopRemaining2 = 4;
    do {
      *(float *)((int)laneValues + loopRemaining) = laneValue;
      loopRemaining = loopRemaining + 4;
      loopRemaining2 = loopRemaining2 + -1;
    } while (loopRemaining2 != 0);
    *kindOut = 3;
    return 1;
  }
  return 0;
}

/* FudoPs__createSchedModels @ 0x191e28 (196 bytes) */
int FudoPs__createSchedModels(this, compiler)
  int this;
  undefined4 compiler;
{
  undefined *puVar1;
  undefined4 *modelAllocation;
  undefined *puVar3;
  
  modelAllocation = (undefined4 *)FUN_000e1564(compiler,0x6c);
  puVar1 = PTR_DAT_001e90f4;
  puVar3 = PTR_DAT_001e90fc + 8;
  modelAllocation[2] = compiler;
  *modelAllocation = puVar3;
  modelAllocation[1] = 0;
  *modelAllocation = puVar1 + 8;
  FUN_00189560(modelAllocation + 10);
  R520SchedModel__vslot2_reset(modelAllocation);
  modelAllocation[0x1a] = 0;
  *modelAllocation = PTR_DAT_001e9148 + 8;
  *(undefined4 **)(this + 0x60) = modelAllocation;
  modelAllocation = (undefined4 *)FUN_000e1564(compiler,0xc);
  puVar1 = PTR_DAT_001e9100;
  modelAllocation[1] = 1;
  modelAllocation[2] = 0;
  *modelAllocation = puVar1 + 8;
  *(undefined4 **)(this + 100) = modelAllocation;
  return;
}

/* FudoPs__ctor_191efc @ 0x191efc (448 bytes) */
int FudoPs__ctor_191efc(this, compiler, createSchedModels)
  undefined4 *this;
  undefined4 compiler;
  int createSchedModels;
{
  bool notLastMantissa;
  float immediateValue;
  float oneValue;
  float mantissaStep;
  float denormalScale;
  double intToDoubleBias;
  double exponentBias;
  uint loopIndex3;
  float *rowStart;
  uint loopIndex2;
  float *loopIndex;
  double powerOfTwo;
  
  KhanPs__ctor_128fd0(this,compiler,0);
  this[7] = 0;
  this[0x10] = 0x200;
  *this = &PTR_FUN_001eb450;
  this[0xb] = 0x100;
  this[8] = 0x7fffffff;
  this[0x13] = 4;
  this[9] = 0x20;
  this[10] = 0x10;
  this[0xe] = 0x89;
  this[0x15] = 0x400;
  this[0xf] = 0x10;
  this[0x11] = 4;
  this[0x12] = 4;
  this[0x14] = 0x20;
  FUN_0010dc20(this);
  FUN_0010dbd8(this,0x2f);
  FUN_0010dbd8(this,0x30);
  FUN_0010dbd8(this,0x31);
  FUN_0010dbd8(this,0x34);
  FUN_0010dbd8(this,0x35);
  FUN_0010dbd8(this,0x36);
  FUN_0010dbd8(this,0x37);
  FUN_0010dbd8(this,0x38);
  FUN_0010dbd8(this,0x39);
  FUN_0010dbd8(this,0x3a);
  FUN_0010dbd8(this,0x3b);
  FUN_0010dbd8(this,0x3c);
  FUN_0010dbd8(this,0x3d);
  FUN_0010dbd8(this,0x40);
  FUN_0010dbd8(this,0x42);
  FUN_0010dbd8(this,0x47);
  FUN_0010dbd8(this,0x4a);
  FUN_0010dbd8(this,0x4b);
  this[2] = this[2] & 0xfffdffff | 0x1d80;
  FudoPs__vslot96(this);
  if (createSchedModels != 0) {
    ((int (*)())FudoPs__createSchedModels)(this,compiler);
  }
  exponentBias = DOUBLE_001aa2a8[0];
  intToDoubleBias = DOUBLE_001aa1e0;
  denormalScale = FLOAT_001aa1c4;
  mantissaStep = FLOAT_001aa170;
  oneValue = FLOAT_001aa0e8;
  rowStart = (float *)(this + 0x5d0);
  loopIndex3 = 0;
  do {
    loopIndex2 = 0;
    loopIndex = rowStart;
    do {
      loopIndex = loopIndex + 1;
      if (loopIndex3 == 0) {
        immediateValue = FLOAT_001aa1c0;
        if (loopIndex2 != 0) {
          immediateValue = (float)((double)CONCAT44(0x43300000,loopIndex2 ^ 0x80000000) - intToDoubleBias) * mantissaStep * denormalScale;
        }
      }
      else {
        powerOfTwo = _pow(DOUBLE_001aa2a0,
                      (double)(float)((double)CONCAT44(0x43300000,loopIndex3 ^ 0x80000000) - intToDoubleBias) -
                      exponentBias);
        immediateValue = (float)powerOfTwo *
                ((float)((double)CONCAT44(0x43300000,loopIndex2 ^ 0x80000000) - intToDoubleBias) * mantissaStep + oneValue);
      }
      notLastMantissa = loopIndex2 != 7;
      *loopIndex = immediateValue;
      loopIndex2 = loopIndex2 + 1;
    } while (notLastMantissa);
    notLastMantissa = loopIndex3 != 0xf;
    rowStart = rowStart + 8;
    loopIndex3 = loopIndex3 + 1;
  } while (notLastMantissa);
  return;
}

/* FudoPs__ctor_1920e0 @ 0x1920e0 (748 bytes) */
int FudoPs__ctor_1920e0(this, compiler, createSchedModels)
  undefined4 *this;
  undefined4 compiler;
  int createSchedModels;
{
  bool notLastMantissa;
  float immediateValue;
  float oneValue;
  float mantissaStep;
  float denormalScale;
  double intToDoubleBias;
  double exponentBias;
  uint loopIndex3;
  float *rowStart;
  uint loopIndex2;
  float *loopIndex;
  double powerOfTwo;
  
  KhanPs__ctor_128fd0(this,compiler,0);
  this[7] = 0;
  this[0x10] = 0x200;
  *this = &PTR_FUN_001eb450;
  this[0xb] = 0x100;
  this[8] = 0x7fffffff;
  this[0x13] = 4;
  this[9] = 0x20;
  this[10] = 0x10;
  this[0xe] = 0x89;
  this[0x15] = 0x400;
  this[0xf] = 0x10;
  this[0x11] = 4;
  this[0x12] = 4;
  this[0x14] = 0x20;
  FUN_0010dc20(this);
  FUN_0010dbd8(this,0x2f);
  FUN_0010dbd8(this,0x30);
  FUN_0010dbd8(this,0x31);
  FUN_0010dbd8(this,0x34);
  FUN_0010dbd8(this,0x35);
  FUN_0010dbd8(this,0x36);
  FUN_0010dbd8(this,0x37);
  FUN_0010dbd8(this,0x38);
  FUN_0010dbd8(this,0x39);
  FUN_0010dbd8(this,0x3a);
  FUN_0010dbd8(this,0x3b);
  FUN_0010dbd8(this,0x3c);
  FUN_0010dbd8(this,0x3d);
  FUN_0010dbd8(this,0x40);
  FUN_0010dbd8(this,0x42);
  FUN_0010dbd8(this,0x47);
  FUN_0010dbd8(this,0x4a);
  FUN_0010dbd8(this,0x4b);
  this[2] = this[2] & 0xfffdffff | 0x1d80;
  FudoPs__vslot96(this);
  if (createSchedModels != 0) {
    ((int (*)())FudoPs__createSchedModels)(this,compiler);
  }
  exponentBias = DOUBLE_001aa2a8[0];
  intToDoubleBias = DOUBLE_001aa1e0;
  denormalScale = FLOAT_001aa1c4;
  mantissaStep = FLOAT_001aa170;
  oneValue = FLOAT_001aa0e8;
  rowStart = (float *)(this + 0x5d0);
  loopIndex3 = 0;
  do {
    loopIndex2 = 0;
    loopIndex = rowStart;
    do {
      loopIndex = loopIndex + 1;
      if (loopIndex3 == 0) {
        immediateValue = FLOAT_001aa1c0;
        if (loopIndex2 != 0) {
          immediateValue = (float)((double)CONCAT44(0x43300000,loopIndex2 ^ 0x80000000) - intToDoubleBias) * mantissaStep * denormalScale;
        }
      }
      else {
        powerOfTwo = _pow(DOUBLE_001aa2a0,
                      (double)(float)((double)CONCAT44(0x43300000,loopIndex3 ^ 0x80000000) - intToDoubleBias) -
                      exponentBias);
        immediateValue = (float)powerOfTwo *
                ((float)((double)CONCAT44(0x43300000,loopIndex2 ^ 0x80000000) - intToDoubleBias) * mantissaStep + oneValue);
      }
      notLastMantissa = loopIndex2 != 7;
      *loopIndex = immediateValue;
      loopIndex2 = loopIndex2 + 1;
    } while (notLastMantissa);
    notLastMantissa = loopIndex3 != 0xf;
    rowStart = rowStart + 8;
    loopIndex3 = loopIndex3 + 1;
  } while (notLastMantissa);
  return;
}

/* FUN_001922c4 @ 0x1922c4 (1016 bytes) */
int FUN_001922c4(param_1, param_2, inst, param_4)
  undefined4 param_1;
  undefined4 param_2;
  int *inst;
  int param_4;
{
  bool bVar1;
  int iVar2;
  int inst2;
  undefined4 uVar4;
  int loopIndex;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int iVar12;
  double dVar13;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  
  uVar11 = *(undefined4 *)(param_4 + 8);
  iVar2 = *(int *)(inst[0x22] + 8);
  if (((((iVar2 == 0x5d) || (iVar2 == 0x29)) || (iVar2 == 0x5b)) ||
      ((iVar2 == 0x27 || (iVar2 == 0x5e)))) ||
     ((iVar2 == 0x2a || ((iVar2 == 0x5c || (iVar2 == 0x28)))))) {
    switch(iVar2) {
    case 0x27:
    case 0x5b:
      iVar12 = 1;
      iVar2 = 2;
      uVar9 = 3;
      uVar10 = 2;
      uVar8 = 1;
      uVar7 = 1;
      break;
    case 0x28:
    case 0x5c:
      iVar12 = 2;
      iVar2 = 1;
      uVar9 = 2;
      uVar10 = 3;
      uVar8 = 0;
      uVar7 = 0;
      break;
    case 0x29:
    case 0x5d:
      iVar12 = 1;
      iVar2 = 2;
      uVar9 = 3;
      uVar10 = 2;
      uVar8 = 0;
      uVar7 = 0;
      break;
    case 0x2a:
    case 0x5e:
      iVar12 = 1;
      iVar2 = 2;
      uVar9 = 2;
      uVar10 = 3;
      uVar8 = 1;
      uVar7 = 1;
      break;
    default:
      iVar12 = 0;
      iVar2 = 0;
      uVar9 = 0;
      uVar10 = 0;
      uVar8 = 0;
      uVar7 = 0;
    }
    inst2 = IRInst__create(0x12,uVar11);
    uVar4 = IRInst__getOperandSource(inst,iVar12);
    IRInst__setOperandSource(inst2,iVar12,uVar4,*(uint *)(param_4 + 0x30) >> 7 & 1,uVar11);
    loopIndex = IRInst__getOperandRecord(inst,iVar12);
    uVar4 = *(undefined4 *)(loopIndex + 0x10);
    loopIndex = IRInst__getOperandRecord(inst2,iVar12);
    *(undefined4 *)(loopIndex + 0x10) = uVar4;
    loopIndex = inst2 + iVar12 * 0x18 + 0x8c;
    IROperand__setModifierBits(loopIndex,2,(uint)inst[iVar12 * 6 + 0x28] >> 1 & 1);
    IROperand__setModifierBits(loopIndex,1,inst[iVar12 * 6 + 0x28] & 1);
    uVar4 = IRInst__getOperandSource(inst,iVar2);
    IRInst__setOperandSource(inst2,iVar2,uVar4,*(uint *)(param_4 + 0x30) >> 7 & 1,uVar11);
    iVar12 = IRInst__getOperandRecord(inst,iVar2);
    uVar4 = *(undefined4 *)(iVar12 + 0x10);
    iVar12 = IRInst__getOperandRecord(inst2,iVar2);
    *(undefined4 *)(iVar12 + 0x10) = uVar4;
    iVar12 = inst2 + iVar2 * 0x18 + 0x8c;
    IROperand__setModifierBits(iVar12,2,(uint)inst[iVar2 * 6 + 0x28] >> 1 & 1);
    IROperand__setModifierBits(iVar12,1,inst[iVar2 * 6 + 0x28] & 1U ^ 1);
    iVar2 = IRInst__getOperandRecord(inst,0);
    uVar4 = *(undefined4 *)(iVar2 + 0x10);
    *(undefined4 *)(inst2 + 0x94) = *(undefined4 *)(inst2 + 0x14c);
    *(undefined4 *)(inst2 + 0x9c) = uVar4;
    *(undefined4 *)(inst2 + 0x98) = 0;
    ((int (*)())DList__insertBefore)(inst2,inst);
    if ((*(uint *)(param_4 + 0x30) & 0x80) == 0) {
      *(int *)(inst2 + 0x160) = *(int *)(param_4 + 0x478) + 1;
    }
    *(int *)(inst2 + 0x158) = inst[0x56];
    iVar2 = 0;
    local_40 = 0;
    local_48 = 0;
    local_44 = 0;
    IRInst__saveCounters(inst,&local_48,0xffffffff);
    if ((inst[5] & 0x200U) != 0) {
      iVar2 = IRInst__getOperandSource(inst,inst[0x21]);
    }
    iVar12 = inst[4];
    ((int (*)())DList__unlink)(inst);
    IRInst__setOperandSource(inst,1,0,*(uint *)(param_4 + 0x30) >> 7 & 1,uVar11);
    IRInst__setOperandSource(inst,2,0,*(uint *)(param_4 + 0x30) >> 7 & 1,uVar11);
    FUN_00108304(inst,0x25,*(undefined4 *)(param_4 + 8));
    IRInst__restoreCounters(inst,&local_48);
    inst[4] = iVar12;
    IRInst__setOperandSource(inst,1,inst2,*(uint *)(param_4 + 0x30) >> 7 & 1,uVar11);
    loopIndex = 0;
    IROperand__setModifierBits(inst + 0x29,1,uVar8);
    IROperand__setModifierBits(inst + 0x29,2,uVar7);
    dVar13 = (double)FLOAT_001aa0e8;
    ((void (*)())FUN_000f79c4)(inst,param_4,uVar10,dVar13,dVar13,dVar13,dVar13);
    dVar13 = (double)FLOAT_001aa0d4;
    ((void (*)())FUN_000f79c4)(inst,param_4,uVar9,dVar13,dVar13,dVar13,dVar13);
    inst[0x25] = inst[0x53];
    inst[0x26] = 0;
    iVar12 = IRInst__getOperandRecord(inst2,0);
    inst[0x27] = *(int *)(iVar12 + 0x10);
    do {
      iVar12 = IRInst__getOperandRecord(inst2,0);
      if (*(char *)(loopIndex + iVar12 + 0x10) == '\x01') {
        for (iVar12 = 1; iVar6 = (**(code **)(*inst + 0x14))(inst), iVar12 <= iVar6;
            iVar12 = iVar12 + 1) {
          (**(code **)(*inst + 0x88))(inst,iVar12,loopIndex,4);
        }
      }
      bVar1 = loopIndex != 3;
      loopIndex = loopIndex + 1;
    } while (bVar1);
    if (iVar2 != 0) {
      IRInst__setExtraOperandSource(inst,iVar2,*(uint *)(param_4 + 0x30) >> 7 & 1,uVar11);
    }
    inst[0x56] = *(int *)(inst2 + 0x158);
    ((int (*)())DList__insertAfter)(inst,inst2);
    if ((*(uint *)(param_4 + 0x30) & 0x80) == 0) {
      FUN_001875a8(inst,1,inst2,param_4);
    }
  }
  return inst;
}

/* FudoPs__vslot28 @ 0x19286c (2512 bytes) */
int FudoPs__vslot28(this, inst, param_3, inst2, param_5, param_6, param_7)
  undefined4 this;
  int *inst;
  int param_3;
  int *inst2;
  undefined4 *param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  bool bVar1;
  char *loopIndex4;
  int loopIndex3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  int *operandVReg;
  int loopRemaining;
  int loopIndex;
  uint uVar11;
  int iVar12;
  int callResult;
  undefined4 uVar14;
  undefined4 *puVar15;
  undefined4 *puVar16;
  uint uVar17;
  uint uVar18;
  int loopIndex2;
  uint uVar20;
  undefined4 uVar21;
  undefined4 local_58;
  int local_54 [7];
  
  local_58 = 0;
  puVar16 = param_5;
  loopIndex3 = (**(code **)(*inst2 + 0x60))(inst2,inst,param_3,inst2,param_5,param_6,param_7);
  if (loopIndex3 != 0) {
    piVar4 = (int *)IRInst__getOperandSource(inst2,1);
    loopIndex3 = (**(code **)(*piVar4 + 0x60))(piVar4);
    if (loopIndex3 != 0) {
      uVar5 = IRInst__getOperandSource(inst2,1);
      FUN_0010c670(uVar5,inst2,param_5[2]);
    }
  }
  loopIndex3 = Compiler__isOptionEnabled(param_5[2],0x38);
  if (((loopIndex3 != 0) && (inst != (int *)0x0)) &&
     (loopIndex3 = (**(code **)(*inst + 100))(inst), loopIndex3 == 0)) {
    FUN_0014a918(inst,param_3,param_5);
  }
  uVar5 = 0;
  loopIndex3 = Compiler__isOptionEnabled(param_5[2],0x1b);
  if (loopIndex3 != 0) {
    uVar5 = (**(code **)(*inst2 + 100))(inst2);
    loopIndex3 = FUN_0014abdc(inst2,param_5,&local_58);
    if ((loopIndex3 != 0) &&
       (inst2 = (int *)FUN_00146610(inst,param_3,inst2), inst2 == (int *)0x0)) {
      return 1;
    }
    if (inst != (int *)0x0) {
      puVar16 = &local_58;
      loopIndex3 = FUN_00160320(inst,param_3,inst2,param_5,puVar16);
      if ((loopIndex3 != 0) &&
         (inst2 = (int *)FUN_00146610(inst,param_3,inst2), inst2 == (int *)0x0)) {
        return 1;
      }
    }
  }
  loopIndex3 = Compiler__isOptionEnabled(param_5[2],0x1c);
  if (loopIndex3 != 0) {
    loopIndex3 = FUN_00162cc0(inst2,param_5);
    if (loopIndex3 != 0) {
      loopIndex3 = (**(code **)(*inst2 + 100))(inst2);
      if (((loopIndex3 != 0) && ((inst2[5] & 0x200U) == 0)) && (inst != (int *)0x0)) {
        puVar16 = &local_58;
        FUN_00160320(inst,param_3,inst2,param_5,puVar16);
      }
      inst2 = (int *)FUN_00146610(inst,param_3,inst2);
      if (inst2 == (int *)0x0) {
        return 1;
      }
    }
    loopIndex3 = (**(code **)(*inst2 + 0x14))(inst2);
    if ((param_3 <= loopIndex3) && (loopIndex3 = FUN_00158264(inst,param_3,inst2,param_5), loopIndex3 != 0)) {
      inst2 = (int *)FUN_00146610(inst,param_3,inst2);
      if (inst2 == (int *)0x0) {
        return 1;
      }
      uVar5 = 1;
    }
    loopIndex3 = FUN_00155a60(inst2,param_5);
    if (loopIndex3 != 0) {
      inst2 = (int *)FUN_00146610(inst,param_3,inst2);
    }
    loopIndex3 = FUN_0014bdbc(inst2,param_5);
    if (loopIndex3 != 0) {
      inst2 = (int *)FUN_00146610(inst,param_3,inst2);
    }
    loopIndex3 = FUN_0014b82c(inst2,param_5,0,1);
    if (loopIndex3 != 0) {
      inst2 = (int *)FUN_00146610(inst,param_3,inst2);
    }
    loopIndex3 = FUN_0014b150(inst2,param_5);
    if (loopIndex3 != 0) {
      loopIndex3 = (**(code **)(*inst2 + 100))(inst2);
      if (((loopIndex3 != 0) && ((inst2[5] & 0x200U) == 0)) && (inst != (int *)0x0)) {
        puVar16 = &local_58;
        FUN_00160320(inst,param_3,inst2,param_5,puVar16);
      }
      inst2 = (int *)FUN_00146610(inst,param_3,inst2);
      if (inst2 == (int *)0x0) {
        return 1;
      }
      uVar5 = 1;
    }
    loopIndex3 = FUN_0014caec(inst2,param_5);
    if (loopIndex3 != 0) {
      inst2 = (int *)FUN_00146610(inst,param_3,inst2);
    }
    loopIndex3 = FUN_0014d8f8(inst2,param_5);
    if (loopIndex3 != 0) {
      inst2 = (int *)FUN_00146610(inst,param_3,inst2);
    }
    loopIndex3 = FUN_0015ceb0(inst2,param_5);
    if (loopIndex3 != 0) {
      inst2 = (int *)FUN_00146610(inst,param_3,inst2);
    }
    loopIndex3 = FUN_0015bd40(inst2,param_5);
    if (loopIndex3 != 0) {
      inst2 = (int *)FUN_00146610(inst,param_3,inst2);
    }
    loopIndex3 = FUN_00163994(inst2,param_5);
    if (loopIndex3 != 0) {
      inst2 = (int *)FUN_00146610(inst,param_3,inst2);
    }
    loopIndex3 = FUN_0015c6d4(inst2,param_5);
    if (loopIndex3 != 0) {
      inst2 = (int *)FUN_00146610(inst,param_3,inst2);
    }
    loopIndex3 = FUN_0014cec8(inst2,param_5);
    if (loopIndex3 != 0) {
      inst2 = (int *)FUN_00146610(inst,param_3,inst2);
    }
    loopIndex3 = FUN_00150d38(inst2,param_5);
    if (loopIndex3 != 0) {
      inst2 = (int *)FUN_00146610(inst,param_3,inst2);
    }
    loopIndex3 = FUN_0014acb8(inst2,param_5);
    if (loopIndex3 != 0) {
      inst2 = (int *)FUN_00146610(inst,param_3,inst2);
    }
    loopIndex3 = FUN_001595f0(inst2,param_5);
    if (loopIndex3 != 0) {
      inst2 = (int *)FUN_00146610(inst,param_3,inst2);
    }
    loopIndex3 = FUN_0015df44(inst2,param_5);
    if (loopIndex3 != 0) {
      inst2 = (int *)FUN_00146610(inst,param_3,inst2);
    }
    loopIndex3 = FUN_0015e494(inst2,param_5);
    if (loopIndex3 != 0) {
      inst2 = (int *)FUN_00146610(inst,param_3,inst2);
    }
    loopIndex3 = Compiler__isOptionEnabled(param_5[2],0x3c);
    if ((loopIndex3 != 0) && (loopIndex3 = FUN_00163478(inst,param_3,inst2,param_5), loopIndex3 != 0)) {
      inst2 = (int *)FUN_00146610(inst,param_3,inst2);
    }
    loopIndex3 = FUN_0014d274(inst2,param_5);
    if (loopIndex3 != 0) {
      inst2 = (int *)FUN_00146610(inst,param_3,inst2);
    }
    loopIndex3 = FUN_00158c3c(inst2,param_5);
    if (loopIndex3 != 0) {
      uVar5 = 1;
    }
  }
  loopIndex3 = FUN_0015546c(inst,param_3,inst2,(uint)param_5);
  if (loopIndex3 != 0) {
    uVar5 = 1;
    inst2 = (int *)FUN_00146610(inst,param_3,inst2);
  }
  piVar4 = inst2;
  puVar15 = param_5;
  loopIndex3 = FUN_00155654(inst,param_3,inst2,param_5);
  piVar6 = inst2;
  if (loopIndex3 != 0) {
    uVar5 = 1;
    piVar6 = (int *)FUN_00146610(inst,param_3,inst2);
    piVar4 = inst2;
  }
  loopIndex3 = Compiler__isOptionEnabled(param_5[2],0x1d);
  if (((((loopIndex3 != 0) &&
        (loopIndex3 = FUN_001633f8(piVar6,param_5,piVar4,puVar15,puVar16,param_6,param_7), loopIndex3 != 0))
       && (loopIndex3 = (**(code **)(*piVar6 + 100))(piVar6), loopIndex3 != 0)) &&
      ((inst != (int *)0x0 &&
       (loopIndex3 = FUN_00160320(inst,param_3,piVar6,param_5,&local_58), loopIndex3 != 0)))) &&
     (piVar6 = (int *)FUN_00146610(inst,param_3,piVar6), piVar6 == (int *)0x0)) {
    return 1;
  }
  loopIndex3 = FUN_00160eb0(inst,param_3,piVar6,param_5);
  if (loopIndex3 != 0) {
    piVar6 = (int *)FUN_00146610(inst,param_3,piVar6);
  }
  uVar21 = param_5[2];
  if (*(int *)(piVar6[0x22] + 8) != 0x77) goto LAB_00193490;
  loopIndex3 = Compiler__isOptionEnabled(uVar21,0x3d);
  if (loopIndex3 != 0) {
    loopIndex3 = IRInst__getOperandRecord(piVar6,1);
    loopIndex3 = FUN_000f2c5c(*(undefined4 *)(loopIndex3 + 0x10));
    if (((loopIndex3 != 0) &&
        (piVar4 = (int *)IRInst__getOperandSource(piVar6,1), *(int *)(piVar4[0x22] + 8) == 0x12)) &&
       ((piVar4[0x48] == 0 &&
        (((piVar4[0x49] == 0 && ((piVar4[5] & 0x200U) == 0)) &&
         (loopIndex3 = IRInst__hasSingleUse(piVar4,param_5), loopIndex3 != 0)))))) {
      loopIndex3 = IRInst__getOperandRecord(piVar4,0);
      loopIndex3 = FUN_000f37b8(*(undefined4 *)(loopIndex3 + 0x10));
      if (-1 < loopIndex3) {
        piVar7 = (int *)IRInst__getOperandSource(piVar4,1);
        operandVReg = (int *)IRInst__getOperandSource(piVar4,2);
        loopRemaining = (**(code **)(*piVar7 + 0x48))(piVar7);
        if (loopRemaining == 0) {
          loopRemaining = (**(code **)(*operandVReg + 0x48))(operandVReg);
          if (loopRemaining == 0) goto LAB_0019348c;
          uVar14 = 2;
          loopRemaining = 1;
        }
        else {
          uVar14 = 1;
          loopRemaining = 2;
          piVar7 = operandVReg;
        }
        loopIndex = ((undefined4 (*)())FUN_00139838)(piVar4,uVar14,-0.5);
        if (((loopIndex != 0) && ((piVar4[loopRemaining * 6 + 0x28] & 1U) == 0)) &&
           ((piVar4[loopRemaining * 6 + 0x28] & 2U) == 0)) {
          loopRemaining = IRInst__getOperandRecord(piVar4,loopRemaining);
          uVar17 = (uint)*(byte *)(loopIndex3 + loopRemaining + 0x10);
          if (((*(int *)(piVar7[0x22] + 8) == 0x12) && (piVar7[0x48] == 0)) && (piVar7[0x49] == 0))
          {
            loopIndex3 = IRInst__getOperandRecord(piVar7,0);
            uVar11 = FUN_000f37b8(*(undefined4 *)(loopIndex3 + 0x10));
            if ((uVar17 == uVar11) && (loopIndex3 = IRInst__hasSingleUse(piVar7,param_5), loopIndex3 != 0)) {
              loopIndex3 = IRInst__getOperandSource(piVar7,1);
              loopRemaining = IRInst__getOperandSource(piVar7,2);
              uVar11 = piVar7[0x2e] & 1;
              if (((loopIndex3 == loopRemaining) &&
                  (((uVar11 != (piVar7[0x34] & 1U) && ((piVar7[0x2e] & 2U) == 0)) &&
                   ((piVar7[0x34] & 2U) == 0)))) &&
                 (loopRemaining = FUN_001049a0(loopRemaining,param_5), loopRemaining != 0)) {
                loopRemaining = IRInst__getOperandRecord(piVar7,1);
                uVar20 = (uint)*(byte *)(uVar17 + loopRemaining + 0x10);
                loopRemaining = IRInst__getOperandRecord(piVar7,2);
                uVar18 = (uint)*(byte *)(uVar17 + loopRemaining + 0x10);
                uVar17 = uVar18;
                if (uVar11 == 0) {
                  uVar17 = uVar20;
                  uVar20 = uVar18;
                }
                if ((((*(int *)(*(int *)(loopIndex3 + 0x88) + 8) == 0x25) &&
                     (loopRemaining = ((undefined4 (*)())FUN_00139838)(loopIndex3,2,1.0), loopRemaining != 0)) &&
                    ((loopRemaining = ((undefined4 (*)())FUN_00139838)(loopIndex3,3,0.0), loopRemaining != 0 &&
                     (((*(uint *)(loopIndex3 + 0x14) & 0x200) == 0 &&
                      ((*(uint *)(loopIndex3 + 0xb8) & 1) == 0)))))) &&
                   ((*(uint *)(loopIndex3 + 0xb8) & 2) == 0)) {
                  ((int (*)())DList__unlink)(piVar4);
                  ((int (*)())DList__unlink)(piVar7);
                  ((int (*)())DList__unlink)(loopIndex3);
                  FUN_00108174(piVar4,0x17,uVar21);
                  loopIndex3 = IRInst__getOperandSource(loopIndex3,1);
                  if ((int)param_5[0x11e] < *(int *)(loopIndex3 + 0x160)) {
                    *(int *)(loopIndex3 + 0x160) = *(int *)(loopIndex3 + 0x160) + 1;
                  }
                  else {
                    *(int *)(loopIndex3 + 0x160) = param_5[0x11e] + 1;
                  }
                  if ((int)param_5[0x11e] < *(int *)(loopIndex3 + 0x160)) {
                    *(int *)(loopIndex3 + 0x160) = *(int *)(loopIndex3 + 0x160) + 1;
                  }
                  else {
                    *(int *)(loopIndex3 + 0x160) = param_5[0x11e] + 1;
                  }
                  IRInst__setOperandSource(piVar4,1,loopIndex3,0,uVar21);
                  IRInst__setOperandSource(piVar4,2,loopIndex3,0,uVar21);
                  piVar4[0x27] = *(int *)(PTR_DAT_001e8b64 + uVar20 * 4);
                  IRInst__setExtraOperandSource(piVar4,loopIndex3,0,uVar21);
                  loopIndex3 = IRInst__getOperandRecord(piVar4,1);
                  *(undefined4 *)(loopIndex3 + 0x10) = 0x4040404;
                  loopIndex3 = IRInst__getOperandRecord(piVar4,2);
                  *(undefined4 *)(loopIndex3 + 0x10) = 0x4040404;
                  loopIndex3 = IRInst__getOperandRecord(piVar6,1);
                  *(undefined4 *)(loopIndex3 + 0x10) = 0x4040404;
                  (**(code **)(*piVar6 + 0x88))(piVar6,1,uVar17,uVar17);
                  (**(code **)(*piVar6 + 0x88))(piVar6,1,uVar20,uVar20);
                  (**(code **)(*piVar4 + 0x88))(piVar4,1,uVar20,uVar20);
                  (**(code **)(*piVar4 + 0x88))(piVar4,2,uVar20,uVar20);
                  IROperand__setModifierBits(piVar4 + 0x29,1,1);
                  IROperand__setModifierBits(piVar4 + 0x2f,1,1);
                  piVar4[0x26] = 0;
                  piVar4[0x25] = piVar4[0x53];
                  if ((int)param_5[0x11e] < piVar4[0x58]) {
                    piVar4[0x58] = piVar4[0x58] + 1;
                  }
                  else {
                    piVar4[0x58] = param_5[0x11e] + 1;
                  }
                  Block__insertInstBefore(piVar6[0x56],piVar6,piVar4);
                  local_54[0] = *(int *)(PTR_DAT_001e8b64 + uVar17 * 4);
                  loopIndex4 = PTR_DAT_001e8b64 + uVar20 * 4;
                  loopRemaining = 4;
                  loopIndex3 = 0;
                  do {
                    if (*loopIndex4 != '\x01') {
                      *(char *)((int)local_54 + loopIndex3) = *loopIndex4;
                    }
                    loopIndex3 = loopIndex3 + 1;
                    loopIndex4 = loopIndex4 + 1;
                    loopRemaining = loopRemaining + -1;
                  } while (loopRemaining != 0);
                  piVar6[0x27] = local_54[0];
                  piVar6[5] = piVar6[5] | 0x2000000;
                  piVar6 = (int *)FUN_00146610(inst,param_3,piVar6);
                  uVar21 = param_5[2];
                  goto LAB_00193490;
                }
              }
            }
          }
        }
      }
    }
  }
LAB_0019348c:
  uVar21 = param_5[2];
LAB_00193490:
  loopIndex3 = Compiler__isOptionEnabled(uVar21,0x39);
  if (loopIndex3 != 0) {
    FUN_001882a4(piVar6,param_5[2]);
    for (loopIndex3 = 1; loopRemaining = (**(code **)(*piVar6 + 0x14))(piVar6), loopIndex3 <= loopRemaining; loopIndex3 = loopIndex3 + 1
        ) {
      uVar21 = IRInst__getOperandSource(piVar6,loopIndex3);
      FUN_001875a8(piVar6,loopIndex3,uVar21,param_5);
    }
    loopIndex3 = FUN_001875a8(inst,param_3,piVar6,param_5);
    if (loopIndex3 != 0) {
      uVar5 = 1;
      piVar6 = (int *)FUN_00146610(inst,param_3,piVar6);
    }
  }
  piVar4 = (int *)((int (*)())FUN_001922c4)(inst,param_3,piVar6,param_5);
  loopIndex3 = FUN_00159b58(piVar4,1,param_5);
  if (loopIndex3 != 0) {
    uVar5 = 1;
    piVar4 = (int *)FUN_00146610(inst,param_3,piVar4);
  }
  loopIndex3 = FUN_0011379c(param_5[2],piVar4);
  if ((loopIndex3 != 0) && ((piVar4[5] & 0x200U) == 0)) {
    for (loopIndex3 = 1; loopRemaining = (**(code **)(*piVar4 + 0x14))(piVar4), loopIndex3 <= loopRemaining; loopIndex3 = loopIndex3 + 1
        ) {
      loopRemaining = IRInst__getOperandSource(piVar4,loopIndex3);
      if ((((*(int *)(*(int *)(loopRemaining + 0x88) + 8) == 0x4c) &&
           (loopIndex = IRInst__hasSingleUse(loopRemaining,param_5), loopIndex != 0)) &&
          ((*(uint *)(loopRemaining + 0x14) & 0x200) != 0)) &&
         (loopIndex = IRInst__getOperandSource(loopRemaining,*(undefined4 *)(loopRemaining + 0x84)),
         *(int *)(*(int *)(loopIndex + 0x88) + 8) == 0x4d)) {
        uVar21 = IRInst__getOperandSource(loopRemaining,*(undefined4 *)(loopRemaining + 0x84));
        loopIndex = IRInst__hasSingleUse(uVar21,param_5);
        if ((loopIndex != 0) &&
           (loopIndex = IRInst__getOperandSource(loopRemaining,*(undefined4 *)(loopRemaining + 0x84)),
           (*(uint *)(loopIndex + 0x14) & 0x200) == 0)) {
          loopIndex2 = 0;
          uVar21 = IRInst__getOperandSource(loopRemaining,*(undefined4 *)(loopRemaining + 0x84));
          iVar12 = IRInst__clone(piVar4,param_5[2],0);
          piVar6 = piVar4;
          loopIndex = iVar12;
          do {
            callResult = IRInst__getOperandRecord(piVar4,loopIndex3);
            uVar17 = (uint)*(byte *)(loopIndex2 + callResult + 0x10);
            if (uVar17 < 4) {
              callResult = FUN_000f313c(uVar21,uVar17);
              if (callResult == 0) {
                *(undefined1 *)(loopIndex + 0x9c) = 1;
              }
              else {
                *(undefined1 *)(piVar6 + 0x27) = 1;
              }
            }
            bVar1 = loopIndex2 != 3;
            piVar6 = (int *)((int)piVar6 + 1);
            loopIndex = loopIndex + 1;
            loopIndex2 = loopIndex2 + 1;
          } while (bVar1);
          IRInst__setOperandSource(iVar12,loopIndex3,uVar21,0,param_5[2]);
          IRInst__setExtraOperandSource(piVar4,iVar12,0,param_5[2]);
          Block__insertInstBefore(piVar4[0x56],piVar4,iVar12);
          IRInst__setOperandSource(loopRemaining,*(undefined4 *)(loopRemaining + 0x84),0,0,param_5[2]);
          *(int *)(loopRemaining + 0x84) = *(int *)(loopRemaining + 0x84) + -1;
          *(uint *)(loopRemaining + 0x14) = *(uint *)(loopRemaining + 0x14) & 0xfffffdff;
          FUN_000f35c4(piVar4);
          FUN_000f35c4(iVar12);
          loopRemaining = *(int *)(iVar12 + 0x84);
          *(int *)(iVar12 + 0x160) = param_5[0x11e] + 1;
          if (0 < loopRemaining) {
            loopIndex = 1;
            do {
              if (loopIndex != loopIndex3) {
                piVar6 = (int *)IRInst__getOperandSource(iVar12,loopIndex);
                loopRemaining = (**(code **)(*piVar6 + 0x5c))();
                if (loopRemaining == 0) {
                  loopIndex2 = IRInst__getOperandSource(iVar12,loopIndex);
                  if ((int)param_5[0x11e] < *(int *)(loopIndex2 + 0x160)) {
                    loopRemaining = *(int *)(iVar12 + 0x84);
                    *(int *)(loopIndex2 + 0x160) = *(int *)(loopIndex2 + 0x160) + 1;
                  }
                  else {
                    loopRemaining = *(int *)(iVar12 + 0x84);
                    *(int *)(loopIndex2 + 0x160) = param_5[0x11e] + 1;
                  }
                }
                else {
                  uVar21 = IRInst__getOperandSource(iVar12,loopIndex);
                  loopRemaining = IRInst__clone(uVar21,param_5[2],0);
                  IRInst__setOperandSource(iVar12,loopIndex,loopRemaining,0,param_5[2]);
                  Block__insertInstBefore(*(undefined4 *)(iVar12 + 0x158),iVar12,loopRemaining);
                  if (0 < *(int *)(loopRemaining + 0x84)) {
                    loopIndex2 = 1;
                    do {
                      callResult = IRInst__getOperandSource(loopRemaining,loopIndex2);
                      if ((int)param_5[0x11e] < *(int *)(callResult + 0x160)) {
                        *(int *)(callResult + 0x160) = *(int *)(callResult + 0x160) + 1;
                      }
                      else {
                        *(int *)(callResult + 0x160) = param_5[0x11e] + 1;
                      }
                      loopIndex2 = loopIndex2 + 1;
                    } while (loopIndex2 <= *(int *)(loopRemaining + 0x84));
                  }
                  loopRemaining = *(int *)(iVar12 + 0x84);
                }
              }
              loopIndex = loopIndex + 1;
            } while (loopIndex <= loopRemaining);
          }
          break;
        }
      }
    }
  }
  loopIndex3 = Compiler__isOptionEnabled(param_5[2],0x3a);
  if (loopIndex3 == 0) {
    return uVar5;
  }
  if (((int)param_5[0x8a] < *(int *)(param_5[2] + 0x664)) &&
     (loopIndex3 = FUN_0015ea3c(inst,param_3,piVar4,param_5), loopIndex3 != 0)) {
    uVar5 = 1;
    piVar4 = (int *)FUN_00146610(inst,param_3,piVar4);
  }
  loopIndex3 = FUN_0015f44c(inst,param_3,piVar4,param_5);
  if (loopIndex3 != 0) {
    FUN_00146610(inst,param_3,piVar4);
    return 1;
  }
  return uVar5;
}

/* R520SchedModel__vslot21 @ 0x193944 (112 bytes) */
int R520SchedModel__vslot21(this, param_2, param_3, param_4)
  undefined4 this;
  int *param_2;
  int param_3;
  undefined4 *param_4;
{
  int callResult;
  undefined4 uVar2;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar3;
  
  iVar3 = *(int *)(*(int *)(param_3 + 0x88) + 8);
  callResult = (**(code **)(*param_2 + 0x24))
                    (param_2,param_2,param_3,param_4,in_r7,in_r8,*(int *)(param_3 + 0x88));
  if ((callResult == 0) || (3 < iVar3 - 0x9eU)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
    *param_4 = 2;
  }
  return uVar2;
}

/* R520SchedModel__vslot22 @ 0x1939b4 (76 bytes) */
int R520SchedModel__vslot22(this, param_2, param_3, param_4)
  int this;
  int param_2;
  int param_3;
  int param_4;
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (*(int *)(*(int *)(this + 8) + 0x6b8) != 0) {
    return 1;
  }
  if ((param_2 < 0x18) && ((param_3 < 0x10 || (param_4 <= param_3 << 2)))) {
    uVar1 = 0;
    uVar2 = 0;
  }
  else {
    uVar1 = 1;
    uVar2 = 1;
  }
  *(undefined4 *)(*(int *)(this + 8) + 0x6b8) = uVar1;
  return uVar2;
}

/* FudoPs__vslot29 @ 0x193a00 (140 bytes) */
int FudoPs__vslot29(this, param_2)
  undefined4 this;
  int param_2;
{
  int iVar1;
  int *piVar2;
  
  iVar1 = Compiler__isOptionEnabled(*(undefined4 *)(param_2 + 8),0x4a);
  if (iVar1 != 0) {
    piVar2 = *(int **)(param_2 + 900);
    iVar1 = piVar2[2];
    while (iVar1 != 0) {
      iVar1 = (**(code **)(*piVar2 + 0x24))(piVar2);
      if (iVar1 != 0) {
        piVar2 = (int *)FUN_0012bb48(param_2,piVar2);
      }
      piVar2 = (int *)piVar2[2];
      iVar1 = piVar2[2];
    }
  }
  return;
}

/* FUN_00193a8c @ 0x193a8c (88 bytes) */
int FUN_00193a8c(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  
  param_1[1] = param_3;
  *param_1 = param_4;
  param_1[2] = param_2;
  if (param_2 < 3) {
    param_1[5] = 0;
  }
  else {
    iVar1 = ((int (*)())Arena__alloc)(*(undefined4 *)(param_4 + 0x370),param_2 << 2);
    param_1[5] = iVar1;
  }
  return;
}

/* FUN_00193ae4 @ 0x193ae4 (88 bytes) */
int FUN_00193ae4(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  
  param_1[1] = param_3;
  *param_1 = param_4;
  param_1[2] = param_2;
  if (param_2 < 3) {
    param_1[5] = 0;
  }
  else {
    iVar1 = ((int (*)())Arena__alloc)(*(undefined4 *)(param_4 + 0x370),param_2 << 2);
    param_1[5] = iVar1;
  }
  return;
}

/* FUN_00193b3c @ 0x193b3c (76 bytes) */
int FUN_00193b3c(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_3 + 0x370);
  puVar1 = (undefined4 *)((int (*)())Arena__alloc)(uVar2,0x1c);
  *puVar1 = uVar2;
  ((int (*)())FUN_00193ae4)(puVar1 + 1,1,0x22,param_3);
  puVar1[4] = param_1;
  puVar1[3] = 1;
  puVar1[5] = param_2;
  return puVar1 + 1;
}

/* FUN_00193be8 @ 0x193be8 (24 bytes) */
int FUN_00193be8(param_1)
  int *param_1;
{
  if (param_1[5] == 0) {
    return;
  }
  return ((int (*)())Arena__free)(*(undefined4 *)(*param_1 + 0x370),param_1[5]);
}

/* FUN_00193c00 @ 0x193c00 (116 bytes) */
int FUN_00193c00(param_1, param_2)
  int param_1;
  int param_2;
{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = 4;
  cVar1 = *(char *)(param_1 + 5);
  if ((cVar1 != '\x01') && (iVar3 = 0x10, cVar1 != '\x02')) {
    iVar3 = (uint)(cVar1 == '\0') << 1;
  }
  uVar4 = *(undefined4 *)(param_2 + 0x370);
  puVar2 = (undefined4 *)((int (*)())Arena__alloc)(uVar4,0x1c);
  *puVar2 = uVar4;
  ((int (*)())FUN_00193ae4)(puVar2 + 1,1,iVar3,param_2);
  puVar2[4] = param_1;
  puVar2[3] = 1;
  puVar2[5] = 0;
  return puVar2 + 1;
}

/* Arena__free @ 0x193cc0 (88 bytes) */
int Arena__free(arena, ptr)
  int arena;
  int ptr;
{
  int lastAllocation;
  
  if ((*(int *)(arena + 0x28) != 0) && (lastAllocation = *(int *)(arena + 0x14), lastAllocation == ptr)) {
    _memset(lastAllocation,0,*(int *)(arena + 8) - lastAllocation);
    *(undefined4 *)(arena + 8) = *(undefined4 *)(arena + 0x14);
  }
  return;
}

/* FUN_00193d18 @ 0x193d18 (124 bytes) */
int FUN_00193d18(param_1)
  int *param_1;
{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)param_1[1];
  while (piVar1 != (int *)0x0) {
    iVar2 = *piVar1;
    (**(code **)(*param_1 + 0x34c))(*(undefined4 *)(*param_1 + 0x354),piVar1);
    piVar1 = (int *)iVar2;
  }
  param_1[3] = 0;
  param_1[1] = 0;
  param_1[5] = 0;
  param_1[4] = 0;
  param_1[2] = 0;
  return;
}

/* Arena__grow @ 0x193d98 (128 bytes) */
int Arena__grow(arena, param_2)
  undefined4 *arena;
  int param_2;
{
  undefined *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined *puVar4;
  undefined4 uVar5;
  
  puVar1 = (undefined *)(param_2 + 3U & 0xfffffffc);
  puVar4 = ((unsigned char *)0x00002fd8U);
  if (0x2fd7 < (int)puVar1) {
    puVar4 = puVar1;
  }
  uVar5 = arena[1];
  puVar2 = (undefined4 *)FUN_000e1564(*arena,(uint)(puVar4 + 8));
  arena[1] = puVar2;
  *puVar2 = uVar5;
  *(undefined **)(arena[1] + 4) = puVar4 + 8;
  iVar3 = arena[1] + 8;
  arena[5] = iVar3;
  arena[4] = puVar4 + arena[1] + 8;
  arena[2] = iVar3;
  return;
}

/* Arena__alloc @ 0x193e18 (92 bytes) */
int Arena__alloc(arena, size)
  int arena;
  int size;
{
  uint alignedSize;
  int result;
  
  alignedSize = size + 3U & 0xfffffffc;
  if (*(uint *)(arena + 0x10) < alignedSize + *(int *)(arena + 8)) {
    ((int (*)())Arena__grow)(arena,alignedSize);
  }
  result = *(int *)(arena + 8);
  *(int *)(arena + 0x14) = result;
  *(uint *)(arena + 8) = alignedSize + result;
  return result;
}

/* FUN_00193e74 @ 0x193e74 (68 bytes) */
int FUN_00193e74(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int param_3;
{
  undefined4 callResult;
  
  callResult = ((int (*)())Arena__alloc)(param_1,param_2 * param_3);
  _memset(callResult,0,param_2 * param_3);
  return callResult;
}

/* FUN_00193eb8 @ 0x193eb8 (76 bytes) */
int FUN_00193eb8(param_1)
  int param_1;
{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar1 = *(int **)(param_1 + 4);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  piVar3 = (int *)*piVar1;
  iVar2 = piVar1[1] - (*(int *)(param_1 + 0x10) - *(int *)(param_1 + 8));
  if (piVar3 == (int *)0x0) {
    return iVar2;
  }
  do {
    piVar1 = piVar3 + 1;
    piVar3 = (int *)*piVar3;
    iVar2 = iVar2 + *piVar1;
  } while (piVar3 != (int *)0x0);
  return iVar2;
}

/* FUN_00193f08 @ 0x193f08 (24 bytes) */
int FUN_00193f08(param_1)
  int param_1;
{
  return *(int *)(param_1 + 8) == param_1 + 0xc;
}

/* FUN_00193f20 @ 0x193f20 (36 bytes) */
int FUN_00193f20(param_1)
  int *param_1;
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1[2];
  iVar1 = *param_1;
  *(int *)(iVar2 + 4) = param_1[1];
  *(int *)(param_1[1] + 8) = iVar2;
                    
                    
  (**(code **)(iVar1 + 4))();
  return;
}

/* DList__insertBefore @ 0x193f44 (32 bytes) */
int DList__insertBefore(node, ref)
  int node;
  int ref;
{
  int prev;
  
  prev = *(int *)(ref + 4);
  *(int *)(node + 4) = prev;
  if (prev != 0) {
    *(int *)(prev + 8) = node;
  }
  *(int *)(ref + 4) = node;
  *(int *)(node + 8) = ref;
  return;
}

/* DList__pushBack @ 0x193f64 (16 bytes) */
int DList__pushBack(list, node)
  int list;
  undefined4 node;
{
  return ((int (*)())DList__insertBefore)(node,list + 0xc);
}

/* DList__insertAfter @ 0x193f74 (32 bytes) */
int DList__insertAfter(node, ref)
  int node;
  int ref;
{
  int next;
  
  next = *(int *)(ref + 8);
  *(int *)(node + 8) = next;
  if (next != 0) {
    *(int *)(next + 4) = node;
  }
  *(int *)(ref + 8) = node;
  *(int *)(node + 4) = ref;
  return;
}

/* DList__pushFront @ 0x193f94 (16 bytes) */
int DList__pushFront(list, node)
  undefined4 list;
  undefined4 node;
{
  return ((int (*)())DList__insertAfter)(node,list);
}

/* FUN_00193fa4 @ 0x193fa4 (16 bytes) */
int FUN_00193fa4(param_1)
  int param_1;
{
  *(int *)(param_1 + 0x10) = param_1;
  *(int *)(param_1 + 8) = param_1 + 0xc;
  return;
}

/* DListNode__clear @ 0x193fb4 (104 bytes) */
int DListNode__clear(param_1)
  int param_1;
{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 8);
  while (piVar1 != (int *)(param_1 + 0xc)) {
    piVar2 = (int *)piVar1[2];
    (**(code **)(*piVar1 + 4))(piVar1);
    piVar1 = piVar2;
  }
  return ((int (*)())FUN_00193fa4)(param_1);
}

/* DList__unlink @ 0x19401c (24 bytes) */
int DList__unlink(node)
  int node;
{
  int prev;
  
  prev = *(int *)(node + 4);
  *(undefined4 *)(prev + 8) = *(undefined4 *)(node + 8);
  *(int *)(*(int *)(node + 8) + 4) = prev;
  return;
}

/* DList__count @ 0x194034 (44 bytes) */
int DList__count(list)
  int list;
{
  int node;
  int count;
  
  count = 0;
  for (node = *(int *)(list + 8); node != list + 0xc; node = *(int *)(node + 8)) {
    count = count + 1;
  }
  return count;
}

/* FUN_00194060 @ 0x194060 (72 bytes) */
int FUN_00194060(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  param_1[4] = 0;
  puVar1 = PTR_DAT_001e8b48;
  param_1[5] = 0;
  param_1[5] = 0;
  param_1[3] = puVar1 + 8;
  param_1[2] = param_1 + 3;
  *param_1 = puVar1 + 8;
  param_1[1] = 0;
  param_1[4] = param_1;
  return;
}

/* DListNode__init @ 0x1940a8 (72 bytes) */
int DListNode__init(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  param_1[4] = 0;
  puVar1 = PTR_DAT_001e8b48;
  param_1[5] = 0;
  param_1[5] = 0;
  param_1[3] = puVar1 + 8;
  param_1[2] = param_1 + 3;
  *param_1 = puVar1 + 8;
  param_1[1] = 0;
  param_1[4] = param_1;
  return;
}

/* FUN_001940f0 @ 0x1940f0 (280 bytes) */
int FUN_001940f0(param_1, param_2)
  int param_1;
  code *param_2;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *loopIndex2;
  uint loopIndex3;
  undefined4 uVar6;
  int loopIndex;
  int iVar8;
  int iVar9;
  
  uVar1 = 1;
  iVar8 = *(int *)(param_1 + 8);
  uVar3 = *(uint *)(param_1 + 4);
  do {
    uVar1 = uVar1 * 3 + 1;
  } while (uVar1 < uVar3);
  do {
    do {
      uVar1 = uVar1 / 3;
      if (uVar1 == 0) {
        return;
      }
    } while (uVar3 <= uVar1);
    loopIndex2 = (undefined4 *)(iVar8 + uVar1 * 4);
    loopIndex = 0;
    loopIndex3 = uVar1;
    do {
      uVar6 = *loopIndex2;
      for (iVar9 = loopIndex; -1 < iVar9; iVar9 = iVar9 - uVar1) {
        iVar2 = (*param_2)(*(undefined4 *)(iVar8 + iVar9 * 4),uVar6);
        if (iVar2 < 1) break;
        *(undefined4 *)((uVar1 + iVar9) * 4 + iVar8) = *(undefined4 *)(iVar8 + iVar9 * 4);
      }
      loopIndex3 = loopIndex3 + 1;
      loopIndex = loopIndex + 1;
      *(undefined4 *)(iVar8 + (uVar1 + iVar9) * 4) = uVar6;
      loopIndex2 = loopIndex2 + 1;
      uVar3 = *(uint *)(param_1 + 4);
    } while (loopIndex3 < uVar3);
  } while( true );
}

/* Vector__removeAt @ 0x194208 (52 bytes) */
int Vector__removeAt(vector, index)
  int vector;
  uint index;
{
  int newCount;
  int elementPtr;
  
  if (*(uint *)(vector + 4) <= index) {
    return;
  }
  newCount = *(uint *)(vector + 4) - 1;
  elementPtr = index * 4 + *(int *)(vector + 8);
  *(int *)(vector + 4) = newCount;
  return _memcpy(elementPtr,elementPtr + 4,(newCount - index) * 4);
}

/* Vector__elementRefGrow @ 0x19423c (152 bytes) */
int Vector__elementRefGrow(vector, index)
  uint *vector;
  uint index;
{
  uint capacity;
  uint oldData;
  
  capacity = *vector;
  if (capacity <= index) {
    do {
      capacity = capacity << 1;
    } while (capacity <= index);
    *vector = capacity;
  }
  oldData = vector[2];
  capacity = ((int (*)())Arena__alloc)(vector[3],capacity << 2);
  vector[2] = capacity;
  _memcpy(capacity,oldData,vector[1] << 2);
  ((int (*)())Arena__free)(vector[3],oldData);
  if (vector[1] < index + 1) {
    vector[1] = index + 1;
  }
  return index * 4 + vector[2];
}

/* FUN_001942d4 @ 0x1942d4 (160 bytes) */
int FUN_001942d4(param_1, param_2)
  uint *param_1;
  uint param_2;
{
  int loopRemaining;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  uVar2 = param_1[1];
  if (param_1[1] < param_2) {
    uVar2 = param_2;
  }
  if (*param_1 < uVar2 + 1) {
    ((int (*)())Vector__elementRefGrow)(param_1,uVar2);
  }
  else {
    param_1[1] = uVar2 + 1;
  }
  loopRemaining = (param_1[1] - param_2) + -1;
  iVar3 = param_2 * 4 + param_1[2];
  puVar4 = (undefined4 *)(iVar3 + loopRemaining * 4);
  if (loopRemaining != 0) {
    loopRemaining = (param_1[1] - param_2) + -1;
    puVar5 = puVar4;
    do {
      puVar4 = puVar5 + -1;
      *puVar5 = *puVar4;
      loopRemaining = loopRemaining + -1;
      puVar5 = puVar4;
    } while (loopRemaining != 0);
  }
  *puVar4 = 0;
  return iVar3;
}

/* Vector__removeValue @ 0x194374 (124 bytes) */
int Vector__removeValue(vector, value)
  int vector;
  int value;
{
  int remaining;
  undefined4 found;
  int loopIndex;
  
  remaining = *(int *)(vector + 4);
  if (remaining == 0) {
LAB_001943c4:
    found = 0;
  }
  else {
    loopIndex = 0;
    if (value != **(int **)(vector + 8)) {
      loopIndex = 0;
      do {
        loopIndex = loopIndex + 1;
        remaining = remaining + -1;
        if (remaining == 0) goto LAB_001943c4;
      } while (value != (*(int **)(vector + 8))[loopIndex]);
    }
    ((int (*)())Vector__removeAt)(vector,loopIndex);
    found = 1;
  }
  return found;
}

/* FUN_001943f0 @ 0x1943f0 (276 bytes) */
int FUN_001943f0(param_1)
  uint *param_1;
{
  uint uVar1;
  int *piVar2;
  uint loopIndex;
  int iVar4;
  uint loopIndex2;
  uint *puVar6;
  
  uVar1 = *param_1;
  if (uVar1 == 0) {
    loopIndex = param_1[2];
  }
  else {
    loopIndex = param_1[2];
    loopIndex2 = 0;
    do {
      puVar6 = *(uint **)(loopIndex + loopIndex2 * 4);
      if (puVar6 != (uint *)0x0) {
        uVar1 = puVar6[1];
        if (uVar1 != 0) {
          loopIndex = 0;
          do {
            if (loopIndex < *puVar6) {
              if (uVar1 <= loopIndex) {
                _memset(uVar1 * 4 + puVar6[2],0,(loopIndex - uVar1) * 4 + 4);
                puVar6[1] = loopIndex + 1;
              }
              piVar2 = (int *)(loopIndex * 4 + puVar6[2]);
            }
            else {
              piVar2 = (int *)((int (*)())Vector__elementRefGrow)(puVar6,loopIndex);
            }
            loopIndex = loopIndex + 1;
            iVar4 = *piVar2;
            if (iVar4 != 0) {
              ((int (*)())Arena__free)(*(undefined4 *)(iVar4 + -4),iVar4 + -4);
            }
            uVar1 = puVar6[1];
          } while (loopIndex < uVar1);
          loopIndex = param_1[2];
        }
        ((int (*)())Arena__free)(param_1[5],*(undefined4 *)(loopIndex + loopIndex2 * 4));
        uVar1 = *param_1;
        loopIndex = param_1[2];
      }
      loopIndex2 = loopIndex2 + 1;
    } while (loopIndex2 < uVar1);
  }
  return ((int (*)())Arena__free)(param_1[5],loopIndex);
}

/* FUN_00194504 @ 0x194504 (276 bytes) */
int FUN_00194504(param_1)
  uint *param_1;
{
  uint uVar1;
  int *piVar2;
  uint loopIndex;
  int iVar4;
  uint loopIndex2;
  uint *puVar6;
  
  uVar1 = *param_1;
  if (uVar1 == 0) {
    loopIndex = param_1[2];
  }
  else {
    loopIndex = param_1[2];
    loopIndex2 = 0;
    do {
      puVar6 = *(uint **)(loopIndex + loopIndex2 * 4);
      if (puVar6 != (uint *)0x0) {
        uVar1 = puVar6[1];
        if (uVar1 != 0) {
          loopIndex = 0;
          do {
            if (loopIndex < *puVar6) {
              if (uVar1 <= loopIndex) {
                _memset(uVar1 * 4 + puVar6[2],0,(loopIndex - uVar1) * 4 + 4);
                puVar6[1] = loopIndex + 1;
              }
              piVar2 = (int *)(loopIndex * 4 + puVar6[2]);
            }
            else {
              piVar2 = (int *)((int (*)())Vector__elementRefGrow)(puVar6,loopIndex);
            }
            loopIndex = loopIndex + 1;
            iVar4 = *piVar2;
            if (iVar4 != 0) {
              ((int (*)())Arena__free)(*(undefined4 *)(iVar4 + -4),iVar4 + -4);
            }
            uVar1 = puVar6[1];
          } while (loopIndex < uVar1);
          loopIndex = param_1[2];
        }
        ((int (*)())Arena__free)(param_1[5],*(undefined4 *)(loopIndex + loopIndex2 * 4));
        uVar1 = *param_1;
        loopIndex = param_1[2];
      }
      loopIndex2 = loopIndex2 + 1;
    } while (loopIndex2 < uVar1);
  }
  return ((int (*)())Arena__free)(param_1[5],loopIndex);
}

/* FUN_00194618 @ 0x194618 (264 bytes) */
int FUN_00194618(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  uint uVar1;
  undefined4 *puVar2;
  int callResult;
  uint loopIndex;
  uint *puVar5;
  
  uVar1 = (*(code *)param_1[4])(param_2,param_2);
  puVar5 = *(uint **)((uVar1 & *param_1 - 1U) * 4 + param_1[2]);
  if ((puVar5 != (uint *)0x0) && (uVar1 = puVar5[1], uVar1 != 0)) {
    loopIndex = 0;
    do {
      if (loopIndex < *puVar5) {
        if (uVar1 <= loopIndex) {
          _memset(uVar1 * 4 + puVar5[2],0,(loopIndex - uVar1) * 4 + 4);
          puVar5[1] = loopIndex + 1;
        }
        puVar2 = (undefined4 *)(loopIndex * 4 + puVar5[2]);
      }
      else {
        puVar2 = (undefined4 *)((int (*)())Vector__elementRefGrow)(puVar5,loopIndex);
      }
      puVar2 = (undefined4 *)*puVar2;
      callResult = (*(code *)param_1[3])(*puVar2,param_2);
      if (callResult == 0) {
  return puVar2;
      }
      uVar1 = puVar5[1];
      loopIndex = loopIndex + 1;
    } while (loopIndex < uVar1);
  }
  return 0;
}

/* FUN_00194720 @ 0x194720 (276 bytes) */
int FUN_00194720(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  uint uVar1;
  undefined4 *puVar2;
  int callResult;
  uint loopIndex;
  uint *puVar5;
  
  uVar1 = (*(code *)param_1[4])(param_2,param_2);
  puVar5 = *(uint **)((*param_1 - 1U & uVar1) * 4 + param_1[2]);
  if ((puVar5 != (uint *)0x0) && (uVar1 = puVar5[1], uVar1 != 0)) {
    loopIndex = 0;
    do {
      if (loopIndex < *puVar5) {
        if (uVar1 <= loopIndex) {
          _memset(uVar1 * 4 + puVar5[2],0,(loopIndex - uVar1) * 4 + 4);
          puVar5[1] = loopIndex + 1;
        }
        puVar2 = (undefined4 *)(loopIndex * 4 + puVar5[2]);
      }
      else {
        puVar2 = (undefined4 *)((int (*)())Vector__elementRefGrow)(puVar5,loopIndex);
      }
      callResult = (*(code *)param_1[3])(*puVar2,param_2);
      if (callResult == 0) {
        ((int (*)())Vector__removeAt)(puVar5,loopIndex);
        return;
      }
      uVar1 = puVar5[1];
      loopIndex = loopIndex + 1;
    } while (loopIndex < uVar1);
  }
  return;
}

/* FUN_00194834 @ 0x194834 (260 bytes) */
int FUN_00194834(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  uint uVar1;
  undefined4 *puVar2;
  int callResult;
  uint loopIndex;
  uint *puVar5;
  undefined4 uVar6;
  
  uVar1 = (*(code *)param_1[4])(param_2,param_2);
  puVar5 = *(uint **)((*param_1 - 1U & uVar1) * 4 + param_1[2]);
  if ((puVar5 != (uint *)0x0) && (uVar1 = puVar5[1], uVar1 != 0)) {
    loopIndex = 0;
    do {
      if (loopIndex < *puVar5) {
        if (uVar1 <= loopIndex) {
          _memset(uVar1 * 4 + puVar5[2],0,(loopIndex - uVar1) * 4 + 4);
          puVar5[1] = loopIndex + 1;
        }
        puVar2 = (undefined4 *)(loopIndex * 4 + puVar5[2]);
      }
      else {
        puVar2 = (undefined4 *)((int (*)())Vector__elementRefGrow)(puVar5,loopIndex);
      }
      uVar6 = *puVar2;
      callResult = (*(code *)param_1[3])(uVar6,param_2);
      if (callResult == 0) {
        return uVar6;
      }
      uVar1 = puVar5[1];
      loopIndex = loopIndex + 1;
    } while (loopIndex < uVar1);
  }
  return 0;
}

/* FUN_00194938 @ 0x194938 (348 bytes) */
int FUN_00194938(param_1)
  undefined4 *param_1;
{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint *puVar4;
  uint loopIndex;
  
  loopIndex = param_1[3];
  if ((int)loopIndex < 0) {
    loopIndex = param_1[1];
    do {
      loopIndex = loopIndex + 1;
      param_1[1] = loopIndex;
      if (*(uint *)*param_1 <= loopIndex) {
        param_1[4] = 0;
        return;
      }
      puVar4 = *(uint **)(loopIndex * 4 + ((uint *)*param_1)[2]);
      param_1[2] = puVar4;
    } while ((puVar4 == (uint *)0x0) || (uVar1 = puVar4[1], uVar1 == 0));
    loopIndex = uVar1 - 1;
    param_1[3] = uVar1 - 2;
    if (loopIndex < *puVar4) {
      uVar3 = puVar4[1];
      if (uVar3 <= loopIndex) {
        _memset(uVar3 * 4 + puVar4[2],0,(loopIndex - uVar3) * 4 + 4);
        puVar4[1] = uVar1;
      }
      puVar2 = (undefined4 *)(loopIndex * 4 + puVar4[2]);
    }
    else {
      puVar2 = (undefined4 *)((int (*)())Vector__elementRefGrow)(puVar4,loopIndex);
    }
  }
  else {
    puVar4 = (uint *)param_1[2];
    param_1[3] = loopIndex - 1;
    if (loopIndex < *puVar4) {
      uVar1 = puVar4[1];
      if (uVar1 <= loopIndex) {
        _memset(uVar1 * 4 + puVar4[2],0,(loopIndex - uVar1) * 4 + 4);
        puVar4[1] = loopIndex + 1;
      }
      puVar2 = (undefined4 *)(loopIndex * 4 + puVar4[2]);
    }
    else {
      puVar2 = (undefined4 *)((int (*)())Vector__elementRefGrow)(puVar4,loopIndex);
    }
  }
  param_1[4] = *puVar2;
  return;
}

/* FUN_00194a94 @ 0x194a94 (20 bytes) */
int FUN_00194a94(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  *param_1 = param_2;
  param_1[3] = 0xffffffff;
  param_1[1] = 0xffffffff;
  return ((int (*)())FUN_00194938)(param_1);
}

/* FUN_00194aa8 @ 0x194aa8 (260 bytes) */
int FUN_00194aa8(param_1)
  uint *param_1;
{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 *loopIndex;
  uint loopIndex3;
  uint *puVar9;
  uint uVar10;
  uint loopIndex2;
  int iVar12;
  uint *puVar13;
  uint *puVar14;
  undefined4 uVar15;
  uint uVar16;
  uint uVar17;
  
  uVar5 = *param_1;
  *param_1 = uVar5 << 1;
  uVar1 = ((int (*)())Arena__alloc)(param_1[5],uVar5 << 3);
  _memset(uVar1,0,*param_1 << 2);
  if (0 < (int)uVar5) {
    loopIndex3 = 0;
    loopIndex = (undefined4 *)(uVar1 + uVar5 * 4);
    iVar6 = 0;
    do {
      puVar13 = *(uint **)(param_1[2] + iVar6);
      if (puVar13 != (uint *)0x0) {
        uVar17 = param_1[5];
        puVar2 = (uint *)((int (*)())Arena__alloc)(uVar17,0x14);
        *puVar2 = uVar17;
        uVar17 = param_1[5];
        puVar2[1] = 2;
        puVar2[4] = uVar17;
        puVar2[2] = 0;
        uVar17 = ((int (*)())Arena__alloc)(uVar17,8);
        puVar2[3] = uVar17;
        *(uint **)(uVar1 + iVar6) = puVar2 + 1;
        uVar17 = param_1[5];
        puVar2 = (uint *)((int (*)())Arena__alloc)(uVar17,0x14);
        *puVar2 = uVar17;
        puVar14 = puVar2 + 1;
        uVar17 = param_1[5];
        puVar2[1] = 2;
        puVar2[2] = 0;
        puVar2[4] = uVar17;
        uVar17 = ((int (*)())Arena__alloc)(uVar17,8);
        puVar2[3] = uVar17;
        loopIndex2 = 0;
        *loopIndex = puVar14;
        uVar10 = puVar13[1];
        puVar9 = *(uint **)(uVar1 + iVar6);
        iVar12 = uVar10 << 2;
        uVar17 = uVar10;
        while( true ) {
          iVar12 = iVar12 + -4;
          uVar16 = uVar17 - 1;
          if (uVar10 == loopIndex2) break;
          if (uVar16 < *puVar13) {
            uVar3 = puVar13[1];
            if (uVar3 <= uVar16) {
              _memset(uVar3 * 4 + puVar13[2],0,(uVar16 - uVar3) * 4 + 4);
              puVar13[1] = uVar17;
            }
            puVar4 = (undefined4 *)(iVar12 + puVar13[2]);
          }
          else {
            puVar4 = (undefined4 *)((int (*)())Vector__elementRefGrow)(puVar13,uVar16);
          }
          uVar15 = *puVar4;
          uVar17 = (*(code *)param_1[4])(uVar15);
          if (loopIndex3 == (uVar17 & *param_1 - 1)) {
            uVar17 = puVar9[1];
            if (uVar17 < *puVar9) {
              _memset(uVar17 * 4 + puVar9[2],0,4);
              puVar4 = (undefined4 *)(uVar17 * 4 + puVar9[2]);
              puVar9[1] = uVar17 + 1;
            }
            else {
              puVar4 = (undefined4 *)((int (*)())Vector__elementRefGrow)(puVar9,uVar17);
            }
          }
          else {
            uVar17 = puVar2[2];
            if (uVar17 < *puVar14) {
              _memset(uVar17 * 4 + puVar2[3],0,4);
              puVar4 = (undefined4 *)(uVar17 * 4 + puVar2[3]);
              puVar2[2] = uVar17 + 1;
            }
            else {
              puVar4 = (undefined4 *)((int (*)())Vector__elementRefGrow)(puVar14,uVar17);
            }
          }
          *puVar4 = uVar15;
          loopIndex2 = loopIndex2 + 1;
          uVar17 = uVar16;
        }
      }
      loopIndex3 = loopIndex3 + 1;
      iVar6 = iVar6 + 4;
      loopIndex = loopIndex + 1;
    } while (uVar5 != loopIndex3);
  }
  param_1[2] = uVar1;
  return;
}

/* FUN_00194d44 @ 0x194d44 (184 bytes) */
int FUN_00194d44(param_1, param_2)
  uint *param_1;
  undefined4 param_2;
{
  uint uVar1;
  uint *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  
  uVar1 = (*(code *)param_1[4])(param_2,param_2);
  uVar4 = param_1[2];
  iVar5 = (*param_1 - 1 & uVar1) * 4;
  if (*(int *)(iVar5 + uVar4) == 0) {
    uVar1 = param_1[5];
    puVar2 = (uint *)((int (*)())Arena__alloc)(uVar1,0x14);
    *puVar2 = uVar1;
    uVar1 = param_1[5];
    puVar2[1] = 2;
    puVar2[2] = 0;
    puVar2[4] = uVar1;
    uVar1 = ((int (*)())Arena__alloc)(uVar1,8);
    puVar2[3] = uVar1;
    *(uint **)(iVar5 + uVar4) = puVar2 + 1;
    uVar4 = param_1[2];
  }
  iVar5 = *(int *)(iVar5 + uVar4);
  puVar3 = (undefined4 *)((int (*)())FUN_001942d4)(iVar5,0);
  *puVar3 = param_2;
  if (*param_1 < *(uint *)(iVar5 + 4)) {
    ((int (*)())FUN_00194aa8)(param_1);
  }
  param_1[1] = param_1[1] + 1;
  return;
}

/* FUN_00194e44 @ 0x194e44 (260 bytes) */
int FUN_00194e44(param_1)
  uint *param_1;
{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  undefined4 *loopIndex;
  uint loopIndex3;
  uint *puVar10;
  uint uVar11;
  uint loopIndex2;
  int iVar13;
  uint *puVar14;
  uint *puVar15;
  uint uVar16;
  uint uVar17;
  
  uVar6 = *param_1;
  *param_1 = uVar6 << 1;
  uVar1 = ((int (*)())Arena__alloc)(param_1[5],uVar6 << 3);
  _memset(uVar1,0,*param_1 << 2);
  if (uVar6 != 0) {
    loopIndex3 = 0;
    loopIndex = (undefined4 *)(uVar1 + uVar6 * 4);
    iVar7 = 0;
    do {
      puVar14 = *(uint **)(param_1[2] + iVar7);
      if (puVar14 != (uint *)0x0) {
        uVar17 = param_1[5];
        puVar2 = (uint *)((int (*)())Arena__alloc)(uVar17,0x14);
        *puVar2 = uVar17;
        uVar17 = param_1[5];
        puVar2[1] = 2;
        puVar2[4] = uVar17;
        puVar2[2] = 0;
        uVar17 = ((int (*)())Arena__alloc)(uVar17,8);
        puVar2[3] = uVar17;
        *(uint **)(uVar1 + iVar7) = puVar2 + 1;
        uVar17 = param_1[5];
        puVar2 = (uint *)((int (*)())Arena__alloc)(uVar17,0x14);
        *puVar2 = uVar17;
        puVar15 = puVar2 + 1;
        uVar17 = param_1[5];
        puVar2[1] = 2;
        puVar2[2] = 0;
        puVar2[4] = uVar17;
        uVar17 = ((int (*)())Arena__alloc)(uVar17,8);
        puVar2[3] = uVar17;
        loopIndex2 = 0;
        *loopIndex = puVar15;
        uVar11 = puVar14[1];
        puVar10 = *(uint **)(uVar1 + iVar7);
        iVar13 = uVar11 << 2;
        uVar17 = uVar11;
        while( true ) {
          iVar13 = iVar13 + -4;
          uVar16 = uVar17 - 1;
          if (uVar11 == loopIndex2) break;
          if (uVar16 < *puVar14) {
            uVar3 = puVar14[1];
            if (uVar3 <= uVar16) {
              _memset(uVar3 * 4 + puVar14[2],0,(uVar16 - uVar3) * 4 + 4);
              puVar14[1] = uVar17;
            }
            puVar4 = (undefined4 *)(iVar13 + puVar14[2]);
          }
          else {
            puVar4 = (undefined4 *)((int (*)())Vector__elementRefGrow)(puVar14,uVar16);
          }
          puVar4 = (undefined4 *)*puVar4;
          uVar17 = (*(code *)param_1[4])(*puVar4);
          if (loopIndex3 == (uVar17 & *param_1 - 1)) {
            uVar17 = puVar10[1];
            if (uVar17 < *puVar10) {
              _memset(uVar17 * 4 + puVar10[2],0,4);
              puVar5 = (undefined4 *)(uVar17 * 4 + puVar10[2]);
              puVar10[1] = uVar17 + 1;
            }
            else {
              puVar5 = (undefined4 *)((int (*)())Vector__elementRefGrow)(puVar10,uVar17);
            }
          }
          else {
            uVar17 = puVar2[2];
            if (uVar17 < *puVar15) {
              _memset(uVar17 * 4 + puVar2[3],0,4);
              puVar5 = (undefined4 *)(uVar17 * 4 + puVar2[3]);
              puVar2[2] = uVar17 + 1;
            }
            else {
              puVar5 = (undefined4 *)((int (*)())Vector__elementRefGrow)(puVar15,uVar17);
            }
          }
          *puVar5 = puVar4;
          loopIndex2 = loopIndex2 + 1;
          uVar17 = uVar16;
        }
      }
      loopIndex3 = loopIndex3 + 1;
      iVar7 = iVar7 + 4;
      loopIndex = loopIndex + 1;
    } while (uVar6 != loopIndex3);
  }
  param_1[2] = uVar1;
  return;
}

/* FUN_001950e0 @ 0x1950e0 (208 bytes) */
int FUN_001950e0(param_1, param_2, param_3)
  uint *param_1;
  uint param_2;
  uint param_3;
{
  uint uVar1;
  uint *puVar2;
  undefined4 *puVar3;
  int iVar4;
  uint loopIndex;
  uint *puVar6;
  
  uVar1 = (*(code *)param_1[4])(param_2,param_2,param_3);
  loopIndex = param_1[2];
  iVar4 = (uVar1 & *param_1 - 1) * 4;
  if (*(int *)(iVar4 + loopIndex) == 0) {
    uVar1 = param_1[5];
    puVar2 = (uint *)((int (*)())Arena__alloc)(uVar1,0x14);
    *puVar2 = uVar1;
    uVar1 = param_1[5];
    puVar2[1] = 2;
    puVar2[2] = 0;
    puVar2[4] = uVar1;
    uVar1 = ((int (*)())Arena__alloc)(uVar1,8);
    puVar2[3] = uVar1;
    *(uint **)(iVar4 + loopIndex) = puVar2 + 1;
    loopIndex = param_1[2];
  }
  uVar1 = param_1[5];
  puVar6 = *(uint **)(iVar4 + loopIndex);
  puVar2 = (uint *)((int (*)())Arena__alloc)(uVar1,0xc);
  *puVar2 = uVar1;
  puVar2[1] = param_2;
  puVar2[2] = param_3;
  uVar1 = puVar6[1];
  if (uVar1 != 0) {
    loopIndex = 0;
    do {
      if (loopIndex < *puVar6) {
        if (uVar1 <= loopIndex) {
          _memset(uVar1 * 4 + puVar6[2],0,(loopIndex - uVar1) * 4 + 4);
          puVar6[1] = loopIndex + 1;
        }
        puVar3 = (undefined4 *)(loopIndex * 4 + puVar6[2]);
      }
      else {
        puVar3 = (undefined4 *)((int (*)())Vector__elementRefGrow)(puVar6,loopIndex);
      }
      loopIndex = loopIndex + 1;
      puVar3 = (undefined4 *)*puVar3;
      iVar4 = (*(code *)param_1[3])(*puVar3,param_2);
      if (((iVar4 == 0) && (param_3 == puVar3[1])) && (puVar2 + 1 != (uint *)0x0)) {
        ((int (*)())Arena__free)(*puVar2,puVar2);
      }
      uVar1 = puVar6[1];
    } while (loopIndex < uVar1);
  }
  puVar3 = (undefined4 *)((int (*)())FUN_001942d4)(puVar6,0);
  *puVar3 = puVar2 + 1;
  if (*param_1 < puVar6[1]) {
    ((int (*)())FUN_00194e44)(param_1);
  }
  param_1[1] = param_1[1] + 1;
  return;
}

/* disjointSetFindRoot @ 0x1952d8 (88 bytes) */
int disjointSetFindRoot(element, parents)
  int element;
  int parents;
{
  int nextLink;
  int link;
  int root;
  
  link = *(int *)(parents + element * 4);
  root = element;
  if (element != link) {
    do {
      root = *(int *)(parents + link * 4);
      link = *(int *)(root * 4 + parents);
    } while (root != link);
    if (element != root) {
      link = element << 2;
      do {
        nextLink = *(int *)(parents + link);
        link = nextLink * 4;
        *(int *)(parents + link) = root;
      } while (root != nextLink);
    }
  }
  *(int *)(element * 4 + parents) = root;
  return root;
}

/* storeIndexedWord @ 0x195330 (12 bytes) */
int storeIndexedWord(value, elementIndex, array)
  undefined4 value;
  int elementIndex;
  int array;
{
  *(undefined4 *)(elementIndex * 4 + array) = value;
  return;
}

/* psnOutputScaleCode @ 0x19533c (16 bytes) */
int psnOutputScaleCode(scaleExponent)
  int scaleExponent;
{
  if (-1 < scaleExponent) {
    return scaleExponent;
  }
  return 3 - scaleExponent;
}

/* anyEnabledLaneSelectsW @ 0x19534c (108 bytes) */
int anyEnabledLaneSelectsW(swizzle, laneEnable)
  uint swizzle;
  uint laneEnable;
{
  if (((((swizzle >> 0x18 != 3) || (laneEnable >> 0x18 == 0)) &&
       (((swizzle >> 0x10 & 0xff) != 3 || ((laneEnable >> 0x10 & 0xff) == 0)))) &&
      (((swizzle >> 8 & 0xff) != 3 || ((laneEnable >> 8 & 0xff) == 0)))) &&
     (((swizzle & 0xff) != 3 || ((laneEnable & 0xff) == 0)))) {
    return 0;
  }
  return 1;
}

/* anyEnabledLaneSelectsXyz @ 0x1953b8 (108 bytes) */
int anyEnabledLaneSelectsXyz(swizzle, laneEnable)
  uint swizzle;
  uint laneEnable;
{
  if (((((2 < swizzle >> 0x18) || (laneEnable >> 0x18 == 0)) &&
       ((2 < (swizzle >> 0x10 & 0xff) || ((laneEnable >> 0x10 & 0xff) == 0)))) &&
      ((2 < (swizzle >> 8 & 0xff) || ((laneEnable >> 8 & 0xff) == 0)))) &&
     ((2 < (swizzle & 0xff) || ((laneEnable & 0xff) == 0)))) {
    return 0;
  }
  return 1;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl FUN_0019156c");
asm(".set FUN_0019156c, _R300VSchedModel__vslot12");
asm(".globl FUN_00191710");
asm(".set FUN_00191710, _isLiteralZeroHalfOrOne");
asm(".globl FUN_00191940");
asm(".set FUN_00191940, _FudoPs__encodeUniformImmediate");
asm(".globl FUN_001919d8");
asm(".set FUN_001919d8, _FudoPs__vslot85");
asm(".globl FUN_00191b30");
asm(".set FUN_00191b30, _FudoPs__vslot59");
asm(".globl FUN_00191c6c");
asm(".set FUN_00191c6c, _FudoChip__vslot2");
asm(".globl FUN_00191c7c");
asm(".set FUN_00191c7c, _FudoPs__classifyLiteralOperand");
asm(".globl FUN_00191e28");
asm(".set FUN_00191e28, _FudoPs__createSchedModels");
asm(".globl FUN_0019286c");
asm(".set FUN_0019286c, _FudoPs__vslot28");
asm(".globl FUN_00193944");
asm(".set FUN_00193944, _R520SchedModel__vslot21");
asm(".globl FUN_001939b4");
asm(".set FUN_001939b4, _R520SchedModel__vslot22");
asm(".globl FUN_00193a00");
asm(".set FUN_00193a00, _FudoPs__vslot29");
asm(".globl FUN_00193e18");
asm(".set FUN_00193e18, _Arena__alloc");
