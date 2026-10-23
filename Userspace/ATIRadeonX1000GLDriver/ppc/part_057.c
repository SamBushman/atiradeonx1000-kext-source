#include "decls.h"

/* IRInst__dtor_1cfeac @ 0x1cfeac (52 bytes) */
int IRInst__dtor_1cfeac(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8b48 + 8;
  *this = &PTR_FUN_001e9fc8;
  *this = vtable;
  return;
}

/* IRInst__dtor_1cfee0 @ 0x1cfee0 (72 bytes) */
int IRInst__dtor_1cfee0(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8b48 + 8;
  *this = &PTR_FUN_001e9fc8;
  *this = vtable;
  if (this == (undefined4 *)0x0) {
    return;
  }
  return Arena__free(this[-1],this + -1);
}

/* IRInst__dtor_1cff28 @ 0x1cff28 (52 bytes) */
int IRInst__dtor_1cff28(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8b48 + 8;
  *this = &PTR_FUN_001e9fc8;
  *this = vtable;
  return;
}

/* IRInst__dtor_1cff5c @ 0x1cff5c (72 bytes) */
int IRInst__dtor_1cff5c(this)
  undefined4 *this;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8b48 + 8;
  *this = &PTR_FUN_001e9fc8;
  *this = vtable;
  if (this == (undefined4 *)0x0) {
    return;
  }
  return Arena__free(this[-1],this + -1);
}

/* HwLimits__dtor @ 0x1cffa4 (36 bytes) */
int HwLimits__dtor(this)
  undefined4 *this;
{
  *this = &PTR_FUN_001ea5b0;
  return;
}

/* HwLimits__deleting_dtor @ 0x1cffc8 (36 bytes) */
int HwLimits__deleting_dtor(this)
  undefined4 *this;
{
  *this = &PTR_FUN_001ea5b0;
  return operator_delete(this);
}

/* HwLimits__vslot7 @ 0x1d0000 (32 bytes) */
int HwLimits__vslot7(this)
  undefined4 *this;
{
  *this = DAT_001afa04;
  return;
}

/* HwLimits__vslot40 @ 0x1d0070 (32 bytes) */
int HwLimits__vslot40(this)
  undefined4 *this;
{
  *this = DAT_001afa08;
  return;
}

/* HwLimits__vslot70 @ 0x1d014c (32 bytes) */
int HwLimits__vslot70(this)
  undefined4 *this;
{
  *this = DAT_001afa04;
  return;
}

/* HwChip__dtor @ 0x1d01b0 (36 bytes) */
int HwChip__dtor(this)
  undefined4 *this;
{
  *this = PTR_DAT_001e8c88 + 8;
  return;
}

/* HwChip__deleting_dtor @ 0x1d01d4 (36 bytes) */
int HwChip__deleting_dtor(this)
  undefined4 *this;
{
  *this = PTR_DAT_001e8c88 + 8;
  return operator_delete(this);
}

/* OpcodeInfo__dtor @ 0x1d0208 (36 bytes) */
int OpcodeInfo__dtor(this)
  undefined4 *this;
{
  *this = PTR_DAT_001e8f28 + 8;
  return;
}

/* OpcodeInfo__deleting_dtor @ 0x1d022c (36 bytes) */
int OpcodeInfo__deleting_dtor(this)
  undefined4 *this;
{
  *this = PTR_DAT_001e8f28 + 8;
  return operator_delete(this);
}

/* IrAddFloat__vslot5 @ 0x1d0278 (288 bytes) */
int IrAddFloat__vslot5(this, param_2, param_3, param_4)
  undefined4 this;
  int param_2;
  int *param_3;
  int param_4;
{
  bool bVar1;
  int iVar2;
  int operandRecord;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int loopIndex;
  
  iVar2 = FUN_0017d610(param_2);
  if (((iVar2 == 0) && (iVar2 = FUN_0017cdbc(param_2), iVar2 == 0)) &&
     ((iVar2 = Compiler__isOptionEnabled(param_4,0xc), iVar2 == 0 || (iVar2 = FUN_0017e338(param_2), iVar2 == 0))
     )) {
    iVar4 = *(int *)(param_4 + 0x658);
    iVar2 = *(int *)(*(int *)(param_4 + 0x6c4) + 0xa8);
    uVar5 = *(undefined4 *)(param_2 + 0xb0);
    uVar6 = 2;
    loopIndex = 0;
    do {
      operandRecord = IRInst__getOperandRecord(uVar5,0);
      if (*(char *)(loopIndex + operandRecord + 0x10) != '\x01') {
        if (iVar4 <= iVar2) {
          return uVar6;
        }
        if ((*param_3 == 0x7ffffffe) &&
           ((operandRecord = FUN_00179b28(param_2,loopIndex), operandRecord != 0 ||
            (operandRecord = FUN_00179cc0(param_2,loopIndex), operandRecord != 0)))) {
          uVar6 = 1;
        }
      }
      bVar1 = loopIndex != 3;
      param_3 = param_3 + 1;
      loopIndex = loopIndex + 1;
    } while (bVar1);
  }
  else {
    uVar6 = 0;
  }
  return uVar6;
}

/* IrCos__fold @ 0x1d05b0 (144 bytes) */
int IrCos__fold(this, result, operands, compiler)
  undefined4 this;
  float *result;
  int operands;
  int compiler;
{
  double cosine;
  
  if (*(int *)(operands + 4) == 0) {
    *result = 1.0;
  }
  else if (*(float *)(operands + 4) == FLOAT_001aa0e8) {
    *result = 0.0;
  }
  else {
    cosine = (double)_cos(((double (*)(int, double))*(code **)(**(int **)(compiler + COMP_target) + 0xe0))(*(int *)(compiler + COMP_target), (double)*(float *)(operands + 4)));
    *result = (float)cosine;
  }
  return 1;
}

/* IrLogInternal__fold @ 0x1d0640 (172 bytes) */
int IrLogInternal__fold(this, result, operands)
  undefined4 this;
  float *result;
  int operands;
{
  double absOperandOrLn;
  double lnTwo;
  
  if (*(float *)(operands + 4) == FLOAT_001aa0e8) {
    *result = 0.0;
  }
  if (*(int *)(operands + 4) != 0) {
    absOperandOrLn = (double)*(float *)(operands + 4);
    if (absOperandOrLn < (double)FLOAT_001aa0d4) {
      absOperandOrLn = -absOperandOrLn;
    }
    absOperandOrLn = (double)_logf(absOperandOrLn);
    lnTwo = (double)_log(DOUBLE_001aa2a0);
    *result = (float)(absOperandOrLn * (double)(float)(DOUBLE_001aa200 / lnTwo));
  }
  return 1;
}

/* IrRecipSqrtInternal__fold @ 0x1d06ec (112 bytes) */
int IrRecipSqrtInternal__fold(this, result, operands)
  undefined4 this;
  float *result;
  int operands;
{
  float resultValue;
  double squareRoot;
  
  resultValue = FLOAT_001aa0e8;
  if (*(float *)(operands + 4) != FLOAT_001aa0e8) {
    if (*(float *)(operands + 4) <= FLOAT_001aa0d4) {
      return 1;
    }
    squareRoot = (double)_sqrt((double)*(float *)(operands + 4));
    resultValue = (float)(DOUBLE_001aa200 / squareRoot);
  }
  *result = resultValue;
  return 1;
}

/* IrRecipInternal__fold @ 0x1d075c (56 bytes) */
int IrRecipInternal__fold(this, result, operands)
  undefined4 this;
  float *result;
  int operands;
{
  if (*(int *)(operands + 4) != 0) {
    *result = FLOAT_001aa0e8 / *(float *)(operands + 4);
  }
  return 1;
}

/* IrSin__fold @ 0x1d0794 (140 bytes) */
int IrSin__fold(this, result, operands, compiler)
  undefined4 this;
  float *result;
  int operands;
  int compiler;
{
  double sine;
  
  if (*(int *)(operands + 4) == 0) {
    *result = 0.0;
  }
  else if (*(float *)(operands + 4) == FLOAT_001aa0e8) {
    *result = FLOAT_001aa0e8;
  }
  else {
    sine = (double)_sin(((double (*)(int, double))*(code **)(**(int **)(compiler + COMP_target) + 0xe0))(*(int *)(compiler + COMP_target), (double)*(float *)(operands + 4)));
    *result = (float)sine;
  }
  return 1;
}

/* IrSqrt__fold @ 0x1d0820 (100 bytes) */
int IrSqrt__fold(this, result, operands)
  undefined4 this;
  float *result;
  int operands;
{
  float resultValue;
  double squareRoot;
  
  resultValue = *(float *)(operands + 4);
  if ((resultValue != FLOAT_001aa0e8) && (*(int *)(operands + 4) != 0)) {
    if (*(int *)(operands + 4) < 1) {
      return 1;
    }
    squareRoot = (double)_sqrt((double)*(float *)(operands + 4));
    resultValue = (float)squareRoot;
  }
  *result = resultValue;
  return 1;
}

/* IrExp__fold @ 0x1d0884 (100 bytes) */
int IrExp__fold(this, result, operands)
  undefined4 this;
  float *result;
  int operands;
{
  double powerOfTwo;
  
  if (*(int *)(operands + 4) == 0) {
    *result = 1.0;
  }
  else {
    powerOfTwo = (double)_pow(DOUBLE_001aa2a0,(double)*(float *)(operands + 4));
    *result = (float)powerOfTwo;
  }
  return 1;
}

/* IrInt2F__fold @ 0x1d08e8 (68 bytes) */
int IrInt2F__fold(this, result, operands)
  undefined4 this;
  float *result;
  int operands;
{
  *result = (float)((double)CONCAT44(0x43300000,*(uint *)(operands + 4) ^ 0x80000000) -
                    DOUBLE_001aa1e0);
  return 1;
}

/* IrUInt2F__fold @ 0x1d092c (64 bytes) */
int IrUInt2F__fold(this, result, operands)
  undefined4 this;
  float *result;
  int operands;
{
  *result = (float)((double)CONCAT44(0x43300000,*(undefined4 *)(operands + 4)) - DOUBLE_001aa250);
  return 1;
}

/* IrMulAddFloat__fold @ 0x1d09b4 (72 bytes) */
int IrMulAddFloat__fold(this, result, operands)
  undefined4 this;
  float *result;
  int operands;
{
  double product;
  
  product = (double)((double (*)())FUN_00113554)((double)*(float *)(operands + 4),(double)*(float *)(operands + 8));
  *result = (float)(product + (double)*(float *)(operands + 0xc));
  return 1;
}

/* IrFloorFloat__fold @ 0x1d09fc (60 bytes) */
int IrFloorFloat__fold(this, result, operands)
  undefined4 this;
  float *result;
  int operands;
{
  double floorValue;
  
  floorValue = (double)_floor((double)*(float *)(operands + 4));
  *result = (float)floorValue;
  return 1;
}

/* IrFractFloat__fold @ 0x1d0a38 (76 bytes) */
int IrFractFloat__fold(this, result, operands)
  undefined4 this;
  float *result;
  int operands;
{
  float operandValue;
  double floorValue;
  
  operandValue = *(float *)(operands + 4);
  floorValue = (double)_floor((double)operandValue);
  *result = (float)((double)operandValue - floorValue);
  return 1;
}

/* IrDot3__foldVector @ 0x1d0a84 (108 bytes) */
int IrDot3__foldVector(this, result, srcA, srcB)
  undefined4 this;
  float *result;
  float *srcA;
  float *srcB;
{
  double productX;
  double productY;
  double productZ;
  
  productX = (double)((double (*)())FUN_00113554)((double)*srcA,(double)*srcB);
  productY = (double)((double (*)())FUN_00113554)((double)srcA[1],(double)srcB[1]);
  productZ = (double)((double (*)())FUN_00113554)((double)srcA[2],(double)srcB[2]);
  *result = (float)((double)(float)(productX + productY) + productZ);
  return;
}

/* IrDot4__foldVector @ 0x1d0af0 (124 bytes) */
int IrDot4__foldVector(this, result, srcA, srcB)
  undefined4 this;
  float *result;
  float *srcA;
  float *srcB;
{
  double productX;
  double productY;
  double productZ;
  double productW;
  
  productX = (double)((double (*)())FUN_00113554)((double)*srcA,(double)*srcB);
  productY = (double)((double (*)())FUN_00113554)((double)srcA[1],(double)srcB[1]);
  productZ = (double)((double (*)())FUN_00113554)((double)srcA[2],(double)srcB[2]);
  productW = (double)((double (*)())FUN_00113554)((double)srcA[3],(double)srcB[3]);
  *result = (float)((double)(float)((double)(float)(productX + productY) + productZ) + productW);
  return;
}

/* IrDot2Add__foldVector @ 0x1d0b94 (104 bytes) */
int IrDot2Add__foldVector(this, result, srcA, srcB, addOperand)
  undefined4 this;
  float *result;
  float *srcA;
  float *srcB;
  int addOperand;
{
  double productX;
  double productY;
  
  productX = (double)((double (*)())FUN_00113554)((double)*srcA,(double)*srcB);
  productY = (double)((double (*)())FUN_00113554)((double)srcA[1],(double)srcB[1]);
  *result = (float)(productX + productY) + *(float *)(addOperand + 8);
  return;
}

/* IrCndEFloat__fold @ 0x1d0bfc (60 bytes) */
int IrCndEFloat__fold(this, result, operands)
  undefined4 this;
  undefined4 *result;
  int operands;
{
  undefined4 selected;
  
  if (*(float *)(operands + 4) == FLOAT_001aa0d4) {
    selected = *(undefined4 *)(operands + 8);
  }
  else {
    selected = *(undefined4 *)(operands + 0xc);
  }
  *result = selected;
  return 1;
}

/* IrCndGEFloat__fold @ 0x1d0c38 (64 bytes) */
int IrCndGEFloat__fold(this, result, operands)
  undefined4 this;
  undefined4 *result;
  int operands;
{
  undefined4 selected;
  
  if (*(float *)(operands + 4) < FLOAT_001aa0d4) {
    selected = *(undefined4 *)(operands + 0xc);
  }
  else {
    selected = *(undefined4 *)(operands + 8);
  }
  *result = selected;
  return 1;
}

/* IrCndGTFloat__fold @ 0x1d0c78 (60 bytes) */
int IrCndGTFloat__fold(this, result, operands)
  undefined4 this;
  undefined4 *result;
  int operands;
{
  undefined4 selected;
  
  if (*(float *)(operands + 4) <= FLOAT_001aa0d4) {
    selected = *(undefined4 *)(operands + 0xc);
  }
  else {
    selected = *(undefined4 *)(operands + 8);
  }
  *result = selected;
  return 1;
}

/* IrSetGTFloat__fold @ 0x1d0cd8 (68 bytes) */
int IrSetGTFloat__fold(this, result, operands)
  undefined4 this;
  float *result;
  int operands;
{
  float difference;
  float setResult;
  float positiveResult;
  
  difference = *(float *)(operands + 4) - *(float *)(operands + 8);
  positiveResult = FLOAT_001aa0e8;
  if (difference < 0.0) {
    positiveResult = FLOAT_001aa0d4;
  }
  setResult = FLOAT_001aa0d4;
  if (-difference < 0.0) {
    setResult = positiveResult;
  }
  *result = setResult;
  return 1;
}

/* IrAddInt__vslot5 @ 0x1d0e0c (212 bytes) */
int IrAddInt__vslot5(this, param_2, param_3, param_4)
  undefined4 this;
  int param_2;
  int *param_3;
  int param_4;
{
  bool bVar1;
  int iVar2;
  int operandRecord;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int loopIndex;
  
  iVar2 = FUN_0017cdbc(param_2);
  uVar5 = 0;
  if (iVar2 == 0) {
    iVar4 = *(int *)(param_4 + 0x658);
    iVar2 = *(int *)(*(int *)(param_4 + 0x6c4) + 0xa8);
    uVar6 = *(undefined4 *)(param_2 + 0xb0);
    uVar5 = 2;
    loopIndex = 0;
    do {
      operandRecord = IRInst__getOperandRecord(uVar6,0);
      if (*(char *)(loopIndex + operandRecord + 0x10) != '\x01') {
        if (iVar4 <= iVar2) {
          return uVar5;
        }
        if ((*param_3 == 0x7ffffffe) && (operandRecord = FUN_00179cc0(param_2,loopIndex), operandRecord != 0)) {
          uVar5 = 1;
        }
      }
      bVar1 = loopIndex != 3;
      param_3 = param_3 + 1;
      loopIndex = loopIndex + 1;
    } while (bVar1);
  }
  return uVar5;
}

/* IrMulFloat__fold @ 0x1d0ee0 (72 bytes) */
int IrMulFloat__fold(this, result, operands)
  undefined4 this;
  float *result;
  int operands;
{
  if ((*(float *)(operands + 4) == FLOAT_001aa0d4) || (*(float *)(operands + 8) == FLOAT_001aa0d4)) {
    *result = FLOAT_001aa0d4;
  }
  else {
    *result = *(float *)(operands + 4) * *(float *)(operands + 8);
  }
  return 1;
}

/* IrRecipSqrtClamp__deleting_dtor @ 0x1d0f28 (68 bytes) */
int IrRecipSqrtClamp__deleting_dtor(this)
  undefined4 *this;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e8d9c;
  *this = PTR_DAT_001e8e28 + 8;
  puVar2 = PTR_DAT_001e8f28;
  *this = puVar1 + 8;
  *this = puVar2 + 8;
  return operator_delete(this);
}

/* IrRecipSqrtClamp__dtor @ 0x1d0f6c (68 bytes) */
int IrRecipSqrtClamp__dtor(this)
  undefined4 *this;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e8d9c;
  *this = PTR_DAT_001e8e28 + 8;
  puVar2 = PTR_DAT_001e8f28;
  *this = puVar1 + 8;
  *this = puVar2 + 8;
  return;
}

/* IrRecipSqrtFF__deleting_dtor @ 0x1d0fb0 (68 bytes) */
int IrRecipSqrtFF__deleting_dtor(this)
  undefined4 *this;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e8d9c;
  *this = PTR_DAT_001e904c + 8;
  puVar2 = PTR_DAT_001e8f28;
  *this = puVar1 + 8;
  *this = puVar2 + 8;
  return operator_delete(this);
}

/* IrRecipSqrtFF__dtor @ 0x1d0ff4 (68 bytes) */
int IrRecipSqrtFF__dtor(this)
  undefined4 *this;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e8d9c;
  *this = PTR_DAT_001e904c + 8;
  puVar2 = PTR_DAT_001e8f28;
  *this = puVar1 + 8;
  *this = puVar2 + 8;
  return;
}

/* IrRecipSqrtIEEE__deleting_dtor @ 0x1d1038 (68 bytes) */
int IrRecipSqrtIEEE__deleting_dtor(this)
  undefined4 *this;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e8d9c;
  *this = PTR_DAT_001e8f0c + 8;
  puVar2 = PTR_DAT_001e8f28;
  *this = puVar1 + 8;
  *this = puVar2 + 8;
  return operator_delete(this);
}

/* IrRecipSqrtIEEE__dtor @ 0x1d107c (68 bytes) */
int IrRecipSqrtIEEE__dtor(this)
  undefined4 *this;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e8d9c;
  *this = PTR_DAT_001e8f0c + 8;
  puVar2 = PTR_DAT_001e8f28;
  *this = puVar1 + 8;
  *this = puVar2 + 8;
  return;
}

/* IrRecipClamp__deleting_dtor @ 0x1d10c0 (68 bytes) */
int IrRecipClamp__deleting_dtor(this)
  undefined4 *this;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e8d88;
  *this = PTR_DAT_001e8fe4 + 8;
  puVar2 = PTR_DAT_001e8f28;
  *this = puVar1 + 8;
  *this = puVar2 + 8;
  return operator_delete(this);
}

/* IrRecipClamp__dtor @ 0x1d1104 (68 bytes) */
int IrRecipClamp__dtor(this)
  undefined4 *this;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e8d88;
  *this = PTR_DAT_001e8fe4 + 8;
  puVar2 = PTR_DAT_001e8f28;
  *this = puVar1 + 8;
  *this = puVar2 + 8;
  return;
}

/* IrRecipFF__deleting_dtor @ 0x1d1148 (68 bytes) */
int IrRecipFF__deleting_dtor(this)
  undefined4 *this;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e8d88;
  *this = PTR_DAT_001e8f8c + 8;
  puVar2 = PTR_DAT_001e8f28;
  *this = puVar1 + 8;
  *this = puVar2 + 8;
  return operator_delete(this);
}

/* IrRecipFF__dtor @ 0x1d118c (68 bytes) */
int IrRecipFF__dtor(this)
  undefined4 *this;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e8d88;
  *this = PTR_DAT_001e8f8c + 8;
  puVar2 = PTR_DAT_001e8f28;
  *this = puVar1 + 8;
  *this = puVar2 + 8;
  return;
}

/* IrRecipIEEE__deleting_dtor @ 0x1d11d0 (68 bytes) */
int IrRecipIEEE__deleting_dtor(this)
  undefined4 *this;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e8d88;
  *this = PTR_DAT_001e8fec + 8;
  puVar2 = PTR_DAT_001e8f28;
  *this = puVar1 + 8;
  *this = puVar2 + 8;
  return operator_delete(this);
}

/* IrRecipIEEE__dtor @ 0x1d1214 (68 bytes) */
int IrRecipIEEE__dtor(this)
  undefined4 *this;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e8d88;
  *this = PTR_DAT_001e8fec + 8;
  puVar2 = PTR_DAT_001e8f28;
  *this = puVar1 + 8;
  *this = puVar2 + 8;
  return;
}

/* IrMulFloat__deleting_dtor @ 0x1d1258 (68 bytes) */
int IrMulFloat__deleting_dtor(this)
  undefined4 *this;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e8dd8;
  *this = PTR_DAT_001e8fb8 + 8;
  puVar2 = PTR_DAT_001e8f28;
  *this = puVar1 + 8;
  *this = puVar2 + 8;
  return operator_delete(this);
}

/* IrMulFloat__dtor @ 0x1d129c (68 bytes) */
int IrMulFloat__dtor(this)
  undefined4 *this;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e8dd8;
  *this = PTR_DAT_001e8fb8 + 8;
  puVar2 = PTR_DAT_001e8f28;
  *this = puVar1 + 8;
  *this = puVar2 + 8;
  return;
}

/* IrMul__deleting_dtor @ 0x1d12e0 (68 bytes) */
int IrMul__deleting_dtor(this)
  undefined4 *this;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e8dd8;
  *this = PTR_DAT_001e8e90 + 8;
  puVar2 = PTR_DAT_001e8f28;
  *this = puVar1 + 8;
  *this = puVar2 + 8;
  return operator_delete(this);
}

/* IrMul__dtor @ 0x1d1324 (68 bytes) */
int IrMul__dtor(this)
  undefined4 *this;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_001e8dd8;
  *this = PTR_DAT_001e8e90 + 8;
  puVar2 = PTR_DAT_001e8f28;
  *this = puVar1 + 8;
  *this = puVar2 + 8;
  return;
}

/* IrLogClamp__deleting_dtor @ 0x1d1368 (68 bytes) */
int IrLogClamp__deleting_dtor(this)
  undefined4 *this;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = PTR_DAT_001e9038;
  *this = PTR_DAT_001e8d2c + 8;
  puVar1 = PTR_DAT_001e8f28;
  *this = puVar2 + 8;
  *this = puVar1 + 8;
  return operator_delete(this);
}

/* IrLogClamp__dtor @ 0x1d13ac (68 bytes) */
int IrLogClamp__dtor(this)
  undefined4 *this;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = PTR_DAT_001e9038;
  *this = PTR_DAT_001e8d2c + 8;
  puVar1 = PTR_DAT_001e8f28;
  *this = puVar2 + 8;
  *this = puVar1 + 8;
  return;
}

/* IrLogIEEE__deleting_dtor @ 0x1d13f0 (68 bytes) */
int IrLogIEEE__deleting_dtor(this)
  undefined4 *this;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = PTR_DAT_001e9038;
  *this = PTR_DAT_001e8cd8 + 8;
  puVar1 = PTR_DAT_001e8f28;
  *this = puVar2 + 8;
  *this = puVar1 + 8;
  return operator_delete(this);
}

/* IrLogIEEE__dtor @ 0x1d1434 (68 bytes) */
int IrLogIEEE__dtor(this)
  undefined4 *this;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = PTR_DAT_001e9038;
  *this = PTR_DAT_001e8cd8 + 8;
  puVar1 = PTR_DAT_001e8f28;
  *this = puVar2 + 8;
  *this = puVar1 + 8;
  return;
}

/* IrDot2Add__deleting_dtor @ 0x1d1478 (68 bytes) */
int IrDot2Add__deleting_dtor(this)
  undefined4 *this;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = PTR_DAT_001e8f94;
  *this = PTR_DAT_001e9070 + 8;
  puVar1 = PTR_DAT_001e8f28;
  *this = puVar2 + 8;
  *this = puVar1 + 8;
  return operator_delete(this);
}

/* IrDot2Add__dtor @ 0x1d14bc (68 bytes) */
int IrDot2Add__dtor(this)
  undefined4 *this;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = PTR_DAT_001e8f94;
  *this = PTR_DAT_001e9070 + 8;
  puVar1 = PTR_DAT_001e8f28;
  *this = puVar2 + 8;
  *this = puVar1 + 8;
  return;
}

/* IrAdd__deleting_dtor @ 0x1d1500 (68 bytes) */
int IrAdd__deleting_dtor(this)
  undefined4 *this;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = PTR_DAT_001e907c;
  *this = PTR_DAT_001e8cb8 + 8;
  puVar1 = PTR_DAT_001e8f28;
  *this = puVar2 + 8;
  *this = puVar1 + 8;
  return operator_delete(this);
}

/* IrAdd__dtor @ 0x1d1544 (68 bytes) */
int IrAdd__dtor(this)
  undefined4 *this;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = PTR_DAT_001e907c;
  *this = PTR_DAT_001e8cb8 + 8;
  puVar1 = PTR_DAT_001e8f28;
  *this = puVar2 + 8;
  *this = puVar1 + 8;
  return;
}

/* IrImmedConstLoad__dtor @ 0x1d1588 (52 bytes) */
int IrImmedConstLoad__dtor(this2)
  undefined4 *this2;
{
  undefined *vtable;
  
  vtable = PTR_DAT_001e8f28 + 8;
  *this2 = PTR_DAT_001e8db0 + 8;
  *this2 = vtable;
  return;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl FUN_001cfeac");
asm(".set FUN_001cfeac, _IRInst__dtor_1cfeac");
asm(".globl FUN_001cfee0");
asm(".set FUN_001cfee0, _IRInst__dtor_1cfee0");
asm(".globl FUN_001cff28");
asm(".set FUN_001cff28, _IRInst__dtor_1cff28");
asm(".globl FUN_001cff5c");
asm(".set FUN_001cff5c, _IRInst__dtor_1cff5c");
asm(".globl FUN_001cffa4");
asm(".set FUN_001cffa4, _HwLimits__dtor");
asm(".globl FUN_001cffc8");
asm(".set FUN_001cffc8, _HwLimits__deleting_dtor");
asm(".globl FUN_001d0000");
asm(".set FUN_001d0000, _HwLimits__vslot7");
asm(".globl FUN_001d0070");
asm(".set FUN_001d0070, _HwLimits__vslot40");
asm(".globl FUN_001d014c");
asm(".set FUN_001d014c, _HwLimits__vslot70");
asm(".globl FUN_001d01b0");
asm(".set FUN_001d01b0, _HwChip__dtor");
asm(".globl FUN_001d01d4");
asm(".set FUN_001d01d4, _HwChip__deleting_dtor");
asm(".globl FUN_001d0208");
asm(".set FUN_001d0208, _OpcodeInfo__dtor");
asm(".globl FUN_001d022c");
asm(".set FUN_001d022c, _OpcodeInfo__deleting_dtor");
asm(".globl FUN_001d0278");
asm(".set FUN_001d0278, _IrAddFloat__vslot5");
asm(".globl FUN_001d05b0");
asm(".set FUN_001d05b0, _IrCos__fold");
asm(".globl FUN_001d0640");
asm(".set FUN_001d0640, _IrLogInternal__fold");
asm(".globl FUN_001d06ec");
asm(".set FUN_001d06ec, _IrRecipSqrtInternal__fold");
asm(".globl FUN_001d075c");
asm(".set FUN_001d075c, _IrRecipInternal__fold");
asm(".globl FUN_001d0794");
asm(".set FUN_001d0794, _IrSin__fold");
asm(".globl FUN_001d0820");
asm(".set FUN_001d0820, _IrSqrt__fold");
asm(".globl FUN_001d0884");
asm(".set FUN_001d0884, _IrExp__fold");
asm(".globl FUN_001d08e8");
asm(".set FUN_001d08e8, _IrInt2F__fold");
asm(".globl FUN_001d092c");
asm(".set FUN_001d092c, _IrUInt2F__fold");
asm(".globl FUN_001d09b4");
asm(".set FUN_001d09b4, _IrMulAddFloat__fold");
asm(".globl FUN_001d09fc");
asm(".set FUN_001d09fc, _IrFloorFloat__fold");
asm(".globl FUN_001d0a38");
asm(".set FUN_001d0a38, _IrFractFloat__fold");
asm(".globl FUN_001d0a84");
asm(".set FUN_001d0a84, _IrDot3__foldVector");
asm(".globl FUN_001d0af0");
asm(".set FUN_001d0af0, _IrDot4__foldVector");
asm(".globl FUN_001d0b94");
asm(".set FUN_001d0b94, _IrDot2Add__foldVector");
asm(".globl FUN_001d0bfc");
asm(".set FUN_001d0bfc, _IrCndEFloat__fold");
asm(".globl FUN_001d0c38");
asm(".set FUN_001d0c38, _IrCndGEFloat__fold");
asm(".globl FUN_001d0c78");
asm(".set FUN_001d0c78, _IrCndGTFloat__fold");
asm(".globl FUN_001d0cd8");
asm(".set FUN_001d0cd8, _IrSetGTFloat__fold");
asm(".globl FUN_001d0e0c");
asm(".set FUN_001d0e0c, _IrAddInt__vslot5");
asm(".globl FUN_001d0ee0");
asm(".set FUN_001d0ee0, _IrMulFloat__fold");
asm(".globl FUN_001d0f28");
asm(".set FUN_001d0f28, _IrRecipSqrtClamp__deleting_dtor");
asm(".globl FUN_001d0f6c");
asm(".set FUN_001d0f6c, _IrRecipSqrtClamp__dtor");
asm(".globl FUN_001d0fb0");
asm(".set FUN_001d0fb0, _IrRecipSqrtFF__deleting_dtor");
asm(".globl FUN_001d0ff4");
asm(".set FUN_001d0ff4, _IrRecipSqrtFF__dtor");
asm(".globl FUN_001d1038");
asm(".set FUN_001d1038, _IrRecipSqrtIEEE__deleting_dtor");
asm(".globl FUN_001d107c");
asm(".set FUN_001d107c, _IrRecipSqrtIEEE__dtor");
asm(".globl FUN_001d10c0");
asm(".set FUN_001d10c0, _IrRecipClamp__deleting_dtor");
asm(".globl FUN_001d1104");
asm(".set FUN_001d1104, _IrRecipClamp__dtor");
asm(".globl FUN_001d1148");
asm(".set FUN_001d1148, _IrRecipFF__deleting_dtor");
asm(".globl FUN_001d118c");
asm(".set FUN_001d118c, _IrRecipFF__dtor");
asm(".globl FUN_001d11d0");
asm(".set FUN_001d11d0, _IrRecipIEEE__deleting_dtor");
asm(".globl FUN_001d1214");
asm(".set FUN_001d1214, _IrRecipIEEE__dtor");
asm(".globl FUN_001d1258");
asm(".set FUN_001d1258, _IrMulFloat__deleting_dtor");
asm(".globl FUN_001d129c");
asm(".set FUN_001d129c, _IrMulFloat__dtor");
asm(".globl FUN_001d12e0");
asm(".set FUN_001d12e0, _IrMul__deleting_dtor");
asm(".globl FUN_001d1324");
asm(".set FUN_001d1324, _IrMul__dtor");
asm(".globl FUN_001d1368");
asm(".set FUN_001d1368, _IrLogClamp__deleting_dtor");
asm(".globl FUN_001d13ac");
asm(".set FUN_001d13ac, _IrLogClamp__dtor");
asm(".globl FUN_001d13f0");
asm(".set FUN_001d13f0, _IrLogIEEE__deleting_dtor");
asm(".globl FUN_001d1434");
asm(".set FUN_001d1434, _IrLogIEEE__dtor");
asm(".globl FUN_001d1478");
asm(".set FUN_001d1478, _IrDot2Add__deleting_dtor");
asm(".globl FUN_001d14bc");
asm(".set FUN_001d14bc, _IrDot2Add__dtor");
asm(".globl FUN_001d1500");
asm(".set FUN_001d1500, _IrAdd__deleting_dtor");
asm(".globl FUN_001d1544");
asm(".set FUN_001d1544, _IrAdd__dtor");
asm(".globl FUN_001d1588");
asm(".set FUN_001d1588, _IrImmedConstLoad__dtor");
