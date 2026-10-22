#include "decls.h"

/* _PPCConstantsAndScratchCreate @ 0x97be56c4 (56 bytes) */
int _PPCConstantsAndScratchCreate()
{
  undefined4 uVar1;
  
  uVar1 = _malloc(0xd80);
  ((double (*)())_PPCConstantsAndScratchInitialise)(uVar1);
  return uVar1;
}

/* _PPCConstantsAndScratchInitialise @ 0x97be5700 (1196 bytes) */
double _PPCConstantsAndScratchInitialise(undefined4 *param_1)
{
  double dVar1;
  double extraout_f1;
  
  _memset(param_1,0,0xd80);
  *param_1 = 0x1a;
  param_1[1] = 0x1c;
  param_1[2] = 0x1e;
  param_1[7] = 1;
  param_1[0xf] = 0xffffffff;
  param_1[0x15] = 0x12;
  param_1[0x14] = 0x11;
  param_1[0x16] = 0x13;
  param_1[0x17] = 0x10;
  param_1[0x1b] = 0x437f0000;
  param_1[0x18] = 0x437f0000;
  param_1[0x19] = 0x437f0000;
  param_1[0x1a] = 0x437f0000;
  param_1[0xb] = 0xff;
  param_1[0x10] = 0xf03070b;
  param_1[8] = 0xff;
  param_1[9] = 0xff;
  param_1[10] = 0xff;
  param_1[0x1c] = 0.003921569;
  param_1[0x1d] = 0.003921569;
  param_1[0x1e] = 0.003921569;
  param_1[0x1f] = 0.003921569;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x20] = 0;
  param_1[0x23] = 0x41400000;
  param_1[0x22] = 0x40400000;
  param_1[0x25] = 0.33333334;
  param_1[0x24] = 0x3f000000;
  param_1[0x27] = 0.16666667;
  param_1[0x26] = 0x3e800000;
  param_1[0x2a] = 0.007874016;
  param_1[0x28] = 0x3d800000;
  param_1[0x2c] = 3.051851e-05;
  param_1[0x21] = 0x3f800000;
  param_1[0x2d] = 1.5259022e-05;
  param_1[0x2b] = 0.003921569;
  param_1[0x30] = 5e-06;
  param_1[0x2e] = 0x30000000;
  param_1[0x31] = 200000.0;
  param_1[0x2f] = 0x2f800000;
  param_1[0x32] = 1.442695;
  param_1[0x29] = 0.041666668;
  param_1[0x33] = -1.442695;
  param_1[0x34] = 0.6931472;
  param_1[0x38] = 255.996;
  param_1[0x39] = 65535.996;
  param_1[0x40] = 0x3f800000;
  param_1[0x3b] = 0.0001;
  param_1[0x3a] = 0x47800000;
  param_1[0x3c] = 0.009615976;
  param_1[0x3d] = -0.0013282397;
  param_1[0x3e] = 0.0001474911;
  param_1[0x3f] = -1.08635e-05;
  param_1[0x41] = -0.6931472;
  param_1[0x42] = 0.24022646;
  param_1[0x43] = -0.055503644;
  param_1[0x44] = 0.2418737;
  param_1[0x45] = -0.1375312;
  param_1[0x46] = 0.05206468;
  param_1[0x47] = -0.009310494;
  param_1[0x48] = 1.4426897;
  param_1[0x49] = -0.7211658;
  param_1[0x4a] = 0.4786848;
  param_1[0x4b] = -0.34730542;
  param_1[0x54] = 0xbf000000;
  param_1[0x4c] = -0.16666667;
  param_1[0x55] = 0.041666668;
  param_1[0x4d] = 0.008333334;
  param_1[0x5c] = 0xff800000;
  param_1[0x4e] = -0.0001984127;
  param_1[0x5d] = 0xff800000;
  param_1[0x4f] = 2.7557319e-06;
  param_1[0x5e] = 0xff800000;
  param_1[0x50] = -2.5052108e-08;
  param_1[0x51] = 1.6059044e-10;
  param_1[0x52] = -7.6471636e-13;
  param_1[0x53] = 2.8114571e-15;
  param_1[0x56] = -0.0013888889;
  param_1[0x57] = 2.4801588e-05;
  param_1[0x58] = -2.755732e-07;
  param_1[0x59] = 2.0876758e-09;
  param_1[0x5a] = -1.1470745e-11;
  param_1[0x5b] = 4.7794773e-14;
  param_1[0x5f] = 0xff800000;
  param_1[0x67] = 0.017453292;
  param_1[0x6b] = 57.29578;
  param_1[100] = 0.017453292;
  param_1[0x65] = 0.017453292;
  param_1[0x66] = 0.017453292;
  param_1[0x68] = 57.29578;
  param_1[0x69] = 57.29578;
  param_1[0x6a] = 57.29578;
  param_1[99] = 6.2831855;
  param_1[0x60] = 6.2831855;
  param_1[0x61] = 6.2831855;
  param_1[0x62] = 6.2831855;
  dVar1 = _log2(2.718281828459045);
  param_1[0x6c] = (float)dVar1;
  dVar1 = _log2(2.718281828459045);
  param_1[0x6d] = (float)dVar1;
  dVar1 = _log2(2.718281828459045);
  param_1[0x6e] = (float)dVar1;
  dVar1 = _log2(2.718281828459045);
  param_1[0x6f] = (float)dVar1;
  dVar1 = _log2(2.718281828459045);
  param_1[0x70] = (float)(1.0 / dVar1);
  dVar1 = _log2(2.718281828459045);
  param_1[0x71] = (float)(1.0 / dVar1);
  dVar1 = _log2(2.718281828459045);
  param_1[0x72] = (float)(1.0 / dVar1);
  dVar1 = _log2(2.718281828459045);
  *(undefined8 *)(param_1 + 0x78) = 0x4330000080000000;
  *(undefined8 *)(param_1 + 0x7a) = 0x4330000000000000;
  param_1[0x7e] = 0x43300000;
  param_1[0x7f] = 0;
  param_1[0x7c] = 0x43300000;
  param_1[0x7d] = 0;
  param_1[0x73] = (float)(1.0 / dVar1);
  _PPCNoiseGeneratorInitialise(param_1 + 0xd8);
  return extraout_f1;
}

/* _PPEmulatorAttachProgram @ 0x97be5bac (8 bytes) */
int _PPEmulatorAttachProgram(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(param_1 + 0xd80) = param_2;
  return;
}

/* _PPEmulatorGetEmulationLevel @ 0x97be5bb4 (24 bytes) */
int _PPEmulatorGetEmulationLevel(emulator)
  int emulator;
{
  if (*(int *)(emulator + 0xd80) == 0) {
    return 0;
  }
  return *(undefined4 *)(*(int *)(emulator + 0xd80) + 0x124);
}

/* _PPEmulatorFramebufferFormat @ 0x97be5bcc (24 bytes) */
int _PPEmulatorFramebufferFormat(emulator)
  int emulator;
{
  if (*(int *)(emulator + 0xd9c) == 0) {
    return 0;
  }
  return *(undefined4 *)(*(int *)(emulator + 0xd9c) + 0x60);
}

/* _PPEmulatorEmulateSingleOp @ 0x97be5be4 (8 bytes) */
void _PPEmulatorEmulateSingleOp(int param_1,undefined4 param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  ((int * (*)())_InterpreterEmulateOp)(*(undefined4 *)(param_1 + 0xdf0),param_2,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
             fparam_6,fparam_7,fparam_8,fparam_9,fparam_10,fparam_11,fparam_12,fparam_13);
  return;
}

/* _PPEmulatorRun @ 0x97be5bec (116 bytes) */
int _PPEmulatorRun(emulator, param_2, param_3, param_4, param_5)
  int emulator;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = *(int *)(emulator + 0xd80);
  if (((*(int *)(iVar1 + 0x38) == 0x8804) || (*(int *)(iVar1 + 0x38) == 0x8b30)) &&
     ((double)*(float *)(*(int *)(emulator + 0xda0) + 0xc) != DOUBLE_97c30a60)) {
    UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 0xc);
  }
  else {
    UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 8);
  }


  /* dropped-return-value defect (class 25, issue #68) - stock does this as a real bctr tail-jump
   * (no blr afterward), so whatever the JIT/interpreter target returns in r3 IS this function's
   * real return value; verified via Capstone disasm of the real 0x97be5bec body. */
  return (*UNRECOVERED_JUMPTABLE)(emulator,param_2,param_3,param_4,param_5,0x97be5bf8,emulator,param_2);
}

/* _PPEmulatorBuild @ 0x97be5c60 (576 bytes) */
int _PPEmulatorBuild(emulator, param_2, param_3, param_4, param_5, param_6)
  int emulator;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int a6;
  code *UNRECOVERED_JUMPTABLE;
  uint uVar6;
  int iVar7;
  
  iVar7 = *(int *)(emulator + 0xd80);
  a6 = 0;
  uVar6 = *(uint *)(iVar7 + 0x124);
  if (((*(int *)(iVar7 + 0x38) == 0x8804) || (*(int *)(iVar7 + 0x38) == 0x8b30)) &&
     ((double)*(float *)(*(int *)(emulator + 0xda0) + 0xc) != DOUBLE_97c30a60)) {
    a6 = 1;
  }
  bVar1 = a6 == 0;
  if (bVar1) {
    if (*(int *)(iVar7 + 0x1c) != 0) {
      _glpDCBFree(*(int *)(iVar7 + 0x1c));
    }
    iVar3 = *(int *)(iVar7 + 0x14);
  }
  else {
    if (*(int *)(iVar7 + 0x20) != 0) {
      _glpDCBFree(*(int *)(iVar7 + 0x20));
    }
    iVar3 = *(int *)(iVar7 + 0x18);
  }
  if (iVar3 != 0) {
    _glpDCBFree(iVar3);
  }
  if ((uVar6 & 2) != 0) {
    if ((uVar6 & 8) == 0) {
      uVar4 = _PPCRuntimeCompilerCreate();
      _PPCRuntimeCompilerAttachEmulatorContext(uVar4,emulator);
      _PPCRuntimeCompilerAttachEmulatorProgram(uVar4,iVar7);
      if ((uVar6 & 4) != 0) {
        _PPCRuntimeCompilerSetOptionFlags(uVar4,7);
      }
      if (bVar1) {
        _PPCRuntimeCompilerCompileNO(uVar4);
        uVar5 = _PPCRuntimeCompilerGetCompiledResult(uVar4);
        *(undefined4 *)(iVar7 + 0x1c) = uVar5;
      }
      else {
        _PPCRuntimeCompilerSetOptionFlags(uVar4,8);
        _PPCRuntimeCompilerCompileNO(uVar4);
        uVar5 = _PPCRuntimeCompilerGetCompiledResult(uVar4);
        *(undefined4 *)(iVar7 + 0x20) = uVar5;
      }
      _PPCRuntimeCompilerFree(uVar4);
    }
    if ((uVar6 & 8) != 0) {
      uVar4 = _PPCRuntimeCompilerCreate();
      _PPCRuntimeCompilerAttachEmulatorContext(uVar4,emulator);
      _PPCRuntimeCompilerAttachEmulatorProgram(uVar4,iVar7);
      if ((uVar6 & 4) != 0) {
        _PPCRuntimeCompilerSetOptionFlags(uVar4,7);
      }
      if (bVar1) {
        _PPCRuntimeCompilerCompileAV(uVar4);
        uVar5 = _PPCRuntimeCompilerGetCompiledResult(uVar4);
        *(undefined4 *)(iVar7 + 0x14) = uVar5;
      }
      else {
        _PPCRuntimeCompilerSetOptionFlags(uVar4,8);
        _PPCRuntimeCompilerCompileAV(uVar4);
        uVar5 = _PPCRuntimeCompilerGetCompiledResult(uVar4);
        *(undefined4 *)(iVar7 + 0x18) = uVar5;
      }
      _PPCRuntimeCompilerFree(uVar4);
    }
  }
  puVar2 = PTR__InterpreterRun_a7b7c104;
  *(undefined **)(iVar7 + 0x10) = PTR__InterpreterRun_a7b7c104;
  if ((uVar6 & 2) == 0) {
    if (bVar1) goto LAB_97be5e64;
  }
  else if ((uVar6 & 8) == 0) {
    if (bVar1) {
      puVar2 = *(undefined **)(iVar7 + 0x1c);
      goto LAB_97be5e64;
    }
    puVar2 = *(undefined **)(iVar7 + 0x20);
  }
  else {
    if (bVar1) {
      puVar2 = *(undefined **)(iVar7 + 0x14);
LAB_97be5e64:
      *(undefined **)(iVar7 + 8) = puVar2;
      goto LAB_97be5e68;
    }
    puVar2 = *(undefined **)(iVar7 + 0x18);
  }
  *(undefined **)(iVar7 + 0xc) = puVar2;
LAB_97be5e68:
  if (bVar1) {
    UNRECOVERED_JUMPTABLE = *(code **)(iVar7 + 8);
  }
  else {
    UNRECOVERED_JUMPTABLE = *(code **)(iVar7 + 0xc);
  }


  /* dropped-return-value defect (class 25, issue #68) - same real bctr tail-jump shape as
   * _PPEmulatorRun above; verified via Capstone disasm of the real 0x97be5c60 body. */
  return (*UNRECOVERED_JUMPTABLE)(emulator,param_2,param_3,param_4,param_5,param_6,a6);
}

/* _PPEmulatorRunNoop @ 0x97be5ea0 (8 bytes) */
int _PPEmulatorRunNoop()
{
  return 0;
}

/* _PPEmulatorVariableSwizzleFromMask @ 0x97be5ea8 (108 bytes) */
int _PPEmulatorVariableSwizzleFromMask(emulator, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int emulator;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  byte bVar1;
  uint uVar2;
  undefined1 *puVar3;
  int iVar4;
  
  bVar1 = *(byte *)(emulator + 0x1c);
  if (bVar1 == 0) {
    *(byte *)(emulator + 8) = bVar1;
    *(undefined1 *)(emulator + 0xb) = 3;
    *(undefined1 *)(emulator + 10) = 2;
    *(undefined1 *)(emulator + 9) = 1;
    return;
  }
  iVar4 = 4;
  puVar3 = (undefined1 *)(emulator + 8);
  uVar2 = 0;
  do {
    if (((int)(uint)bVar1 >> (uVar2 & 0x3f) & 1U) == 0) {
      *puVar3 = 0xff;
    }
    else {
      *puVar3 = (char)uVar2;
    }
    uVar2 = uVar2 + 1;
    puVar3 = puVar3 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return;
}

/* _PPEmulatorVariableMaskFromSwizzle @ 0x97be5f14 (68 bytes) */
int _PPEmulatorVariableMaskFromSwizzle(emulator)
  int emulator;
{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  
  *(undefined1 *)(emulator + 0x1c) = 0;
  iVar3 = 4;
  pbVar2 = (byte *)(emulator + 8);
  do {
    bVar1 = *pbVar2;
    pbVar2 = pbVar2 + 1;
    if (bVar1 != 0xff) {
      *(byte *)(emulator + 0x1c) = *(byte *)(emulator + 0x1c) | (byte)(1 << (bVar1 & 0x3f));
    }
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

/* _ncpy_97be5f58 @ 0x97be5f58 (144 bytes) */
int _ncpy_97be5f58(param_1, param_2)
  char *param_1;
  int param_2;
{
  int iVar1;
  char *local_20 [4];
  
  local_20[0] = param_1;
  if (param_2 < 0) {
    local_20[0] = param_1 + 1;
    *param_1 = '-';
    param_2 = -param_2;
  }
  iVar1 = param_2 / 10;
  if (iVar1 != 0) {
    ((int (*)())_handleDigit_97bf0d2c)(local_20,iVar1);
  }
  *local_20[0] = (char)param_2 + (char)iVar1 * -10 + '0';
  return local_20[0] + (1 - (int)param_1);
}

/* _glpWriteSizeTypePrecision @ 0x97be5fe8 (676 bytes) */
int _glpWriteSizeTypePrecision(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
{
  char ch;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = 0;
  ch = s___97c2a320[0];
  while (ch != '\0') {
    *(char *)(param_1 + iVar2) = ch;
    ch = ":"[iVar2 + 1];
    iVar2 = iVar2 + 1;
  }
  iVar3 = ((int (*)())_ncpy_97be5f58)(param_1 + iVar2,param_2 + 1);
  iVar3 = param_1 + iVar2 + iVar3;
  if (param_3 == 1) {
    iVar2 = 0;
    ch = s___97c2a320[0];
    while (ch != '\0') {
      *(char *)(iVar3 + iVar2) = ch;
      ch = ":"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    iVar4 = ((int (*)())_ncpy_97be5f58)(iVar3 + iVar2,param_2 + 1);
    iVar3 = iVar3 + iVar2 + iVar4;
  }
  switch(param_4) {
  default:
    goto switchD_97be60c8_caseD_0;
  case 1:
    iVar2 = 0;
    ch = s_F_97c2d738[0];
    while (ch != '\0') {
      *(char *)(iVar3 + iVar2) = ch;
      ch = "F"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 2:
    iVar2 = 0;
    ch = s_X_97c2d73c[0];
    while (ch != '\0') {
      *(char *)(iVar3 + iVar2) = ch;
      ch = "X"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 3:
    iVar2 = 0;
    ch = s_I_97c2d740[0];
    while (ch != '\0') {
      *(char *)(iVar3 + iVar2) = ch;
      ch = "I"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 4:
    iVar2 = 0;
    ch = s_B_97c2d744[0];
    while (ch != '\0') {
      *(char *)(iVar3 + iVar2) = ch;
      ch = "B"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
  }
  iVar3 = iVar3 + iVar2;
switchD_97be60c8_caseD_0:
  if (param_5 == 1) {
    iVar2 = 0;
    ch = s_32_97c2d748[0];
    while (ch != '\0') {
      *(char *)(iVar3 + iVar2) = ch;
      ch = "32"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
  }
  else {
    if (param_5 < 2) {
      return iVar3;
    }
    if (param_5 == 2) {
      iVar2 = 0;
      ch = s_16_97c2d74c[0];
      while (ch != '\0') {
        *(char *)(iVar3 + iVar2) = ch;
        ch = "16"[iVar2 + 1];
        iVar2 = iVar2 + 1;
      }
    }
    else {
      if (param_5 != 3) {
        return iVar3;
      }
      iVar2 = 0;
      ch = s_12_97c2d750[0];
      while (ch != '\0') {
        *(char *)(iVar3 + iVar2) = ch;
        ch = "12"[iVar2 + 1];
        iVar2 = iVar2 + 1;
      }
    }
  }
  return iVar3 + iVar2;
}

/* _glpWritePrecision @ 0x97be62a0 (224 bytes) */
int _glpWritePrecision(param_1, param_2)
  int param_1;
  int param_2;
{
  char ch;
  int iVar2;
  
  if (param_2 == 1) {
    iVar2 = 0;
    ch = s_R_97c2d754[0];
    while (ch != '\0') {
      *(char *)(param_1 + iVar2) = ch;
      ch = "R"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
  }
  else {
    if (param_2 < 2) {
      return param_1;
    }
    if (param_2 == 2) {
      iVar2 = 0;
      ch = s_H_97c2d758[0];
      while (ch != '\0') {
        *(char *)(param_1 + iVar2) = ch;
        ch = "H"[iVar2 + 1];
        iVar2 = iVar2 + 1;
      }
    }
    else {
      if (param_2 != 3) {
        return param_1;
      }
      iVar2 = 0;
      ch = s_X_97c2d73c[0];
      while (ch != '\0') {
        *(char *)(param_1 + iVar2) = ch;
        ch = "X"[iVar2 + 1];
        iVar2 = iVar2 + 1;
      }
    }
  }
  return param_1 + iVar2;
}

/* _glpWriteOperandSize @ 0x97be6380 (236 bytes) */
int _glpWriteOperandSize(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  char ch;
  int iVar2;
  int iVar3;
  
  if ((param_2 != 3) || (param_3 == 1)) {
    iVar2 = 0;
    ch = s___97c2a320[0];
    while (ch != '\0') {
      *(char *)(param_1 + iVar2) = ch;
      ch = ":"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    iVar3 = ((int (*)())_ncpy_97be5f58)(param_1 + iVar2,param_2 + 1);
    param_1 = param_1 + iVar2 + iVar3;
    if (param_3 == 1) {
      iVar2 = 0;
      ch = s___97c2a320[0];
      while (ch != '\0') {
        *(char *)(param_1 + iVar2) = ch;
        ch = ":"[iVar2 + 1];
        iVar2 = iVar2 + 1;
      }
      iVar3 = ((int (*)())_ncpy_97be5f58)(param_1 + iVar2,param_2 + 1);
      param_1 = param_1 + iVar2 + iVar3;
    }
  }
  return param_1;
}

/* _glpWriteSizeType @ 0x97be646c (472 bytes) */
int _glpWriteSizeType(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
{
  char ch;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = 0;
  ch = s___97c2a320[0];
  while (ch != '\0') {
    *(char *)(param_1 + iVar2) = ch;
    ch = ":"[iVar2 + 1];
    iVar2 = iVar2 + 1;
  }
  iVar3 = ((int (*)())_ncpy_97be5f58)(param_1 + iVar2,param_2 + 1);
  iVar3 = param_1 + iVar2 + iVar3;
  if (param_3 != 0) {
    iVar2 = 0;
    ch = s___97c2a320[0];
    while (ch != '\0') {
      *(char *)(iVar3 + iVar2) = ch;
      ch = ":"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    iVar4 = ((int (*)())_ncpy_97be5f58)(iVar3 + iVar2,param_2 + 1);
    iVar3 = iVar3 + iVar2 + iVar4;
  }
  switch(param_4) {
  default:
    goto switchD_97be6548_caseD_0;
  case 1:
    iVar2 = 0;
    ch = s_F_97c2d738[0];
    while (ch != '\0') {
      *(char *)(iVar3 + iVar2) = ch;
      ch = "F"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 2:
    iVar2 = 0;
    ch = s_X_97c2d73c[0];
    while (ch != '\0') {
      *(char *)(iVar3 + iVar2) = ch;
      ch = "X"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 3:
    iVar2 = 0;
    ch = s_I_97c2d740[0];
    while (ch != '\0') {
      *(char *)(iVar3 + iVar2) = ch;
      ch = "I"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 4:
    iVar2 = 0;
    ch = s_B_97c2d744[0];
    while (ch != '\0') {
      *(char *)(iVar3 + iVar2) = ch;
      ch = "B"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
  }
  iVar3 = iVar3 + iVar2;
switchD_97be6548_caseD_0:
  return iVar3;
}

/* _glpWriteClampSat @ 0x97be6658 (216 bytes) */
int _glpWriteClampSat(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  char ch;
  int iVar2;
  
  if (param_2 != 0) {
    iVar2 = 0;
    ch = s_C_97c2d75c[0];
    while (ch != '\0') {
      *(char *)(param_1 + iVar2) = ch;
      ch = "C"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    param_1 = param_1 + iVar2;
    if (0 < param_3) {
      iVar2 = 0;
      ch = s_1_97c2d760[0];
      while (ch != '\0') {
        *(char *)(param_1 + iVar2) = ch;
        ch = "1"[iVar2 + 1];
        iVar2 = iVar2 + 1;
      }
      param_1 = param_1 + iVar2;
    }
  }
  if (param_4 != 0) {
    iVar2 = 0;
    ch = s__SAT_97c2d764[0];
    while (ch != '\0') {
      *(char *)(param_1 + iVar2) = ch;
      ch = "_SAT"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    return param_1 + iVar2;
  }
  return param_1;
}

/* _glpWriteDestinationOperand_97be6730 @ 0x97be6730 (1764 bytes) */
int _glpWriteDestinationOperand_97be6730(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  char *param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
{
  char ch;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  
  iVar3 = param_5 * 8;
  uVar4 = *(uint *)(iVar3 + param_1) >> 0x11 & 7;
  if (uVar4 == 1) {
    iVar5 = 0;
    ch = s_tmp_97c2d76c[0];
    while (ch != '\0') {
      param_2[iVar5] = ch;
      ch = "tmp"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    pcVar8 = param_2 + iVar5;
    if ((param_6 == 0) || (param_3 == 0)) {
      uVar2 = *(ushort *)(iVar3 + param_1 + 6);
      goto LAB_97be68f4;
    }
    iVar5 = ((int (*)())_ncpy_97be5f58)(pcVar8,*(undefined4 *)
                                   (param_3 + (uint)*(ushort *)(iVar3 + param_1 + 6) * 4));
    param_2 = pcVar8 + iVar5;
    if (((param_4 != 0) && (uVar4 = *(uint *)(iVar3 + param_1 + 4), -1 < (int)uVar4)) &&
       (*(int *)(param_4 + (uVar4 & 0xffff) * 4) != -1)) {
      iVar5 = 0;
      ch = s___97c29860[0];
      while (ch != '\0') {
        param_2[iVar5] = ch;
        ch = "["[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      pcVar8 = param_2 + iVar5;
      iVar7 = ((int (*)())_ncpy_97be5f58)(pcVar8,*(undefined4 *)
                                     (param_4 + (uint)*(ushort *)(iVar3 + param_1 + 6) * 4));
      iVar5 = 0;
      ch = s___97c2d770[0];
      while (ch != '\0') {
        pcVar8[iVar5 + iVar7] = ch;
        ch = "]"[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      param_2 = pcVar8 + iVar5 + iVar7;
    }
  }
  else if (uVar4 == 3) {
    iVar5 = 0;
    ch = s_res_97c2d774[0];
    while (ch != '\0') {
      param_2[iVar5] = ch;
      ch = "res"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    pcVar8 = param_2 + iVar5;
    uVar2 = *(ushort *)(iVar3 + param_1 + 6);
LAB_97be68f4:
    iVar5 = ((int (*)())_ncpy_97be5f58)(pcVar8,(uint)uVar2);
    param_2 = pcVar8 + iVar5;
  }
  if (param_6 == 0) {
    if ((*(uint *)(iVar3 + param_1) & 0x1e000) != 0x1e000) {
      iVar5 = 0;
      ch = s___97c2a130[0];
      while (ch != '\0') {
        param_2[iVar5] = ch;
        ch = "."[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      param_2 = param_2 + iVar5;
      if ((*(uint *)(iVar3 + param_1) & 0x2000) != 0) {
        iVar5 = 0;
        ch = s_x_97c2d790[0];
        while (ch != '\0') {
          param_2[iVar5] = ch;
          ch = "x"[iVar5 + 1];
          iVar5 = iVar5 + 1;
        }
        param_2 = param_2 + iVar5;
      }
      if ((*(uint *)(iVar3 + param_1) & 0x4000) != 0) {
        iVar5 = 0;
        ch = s_y_97c2d794[0];
        while (ch != '\0') {
          param_2[iVar5] = ch;
          ch = "y"[iVar5 + 1];
          iVar5 = iVar5 + 1;
        }
        param_2 = param_2 + iVar5;
      }
      if ((*(uint *)(iVar3 + param_1) & 0x8000) != 0) {
        iVar5 = 0;
        ch = s_z_97c2d798[0];
        while (ch != '\0') {
          param_2[iVar5] = ch;
          ch = "z"[iVar5 + 1];
          iVar5 = iVar5 + 1;
        }
        param_2 = param_2 + iVar5;
      }
      if ((*(uint *)(iVar3 + param_1) & 0x10000) != 0) {
        iVar5 = 0;
        ch = s_w_97c2d79c[0];
        while (ch != '\0') {
          param_2[iVar5] = ch;
          ch = "w"[iVar5 + 1];
          iVar5 = iVar5 + 1;
        }
        param_2 = param_2 + iVar5;
      }
    }
  }
  else {
    if (*(int *)(iVar3 + param_1 + 4) < 0) {
      iVar7 = 0;
      iVar5 = 0;
      ch = s__adr_97c2d778[0];
      while (ch != '\0') {
        param_2[iVar5] = ch;
        ch = "[adr"[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      iVar6 = ((int (*)())_ncpy_97be5f58)(param_2 + iVar5,*(uint *)(iVar3 + param_1 + 4) >> 0x1e & 1);
      pcVar8 = param_2 + iVar5 + iVar6;
      uVar4 = *(uint *)(iVar3 + param_1 + 4) >> 0x1c & 3;
      if (uVar4 == 1) {
        iVar5 = 0;
        ch = s__y_97c2d784[0];
        while (ch != '\0') {
          pcVar8[iVar5] = ch;
          ch = ".y"[iVar5 + 1];
          iVar5 = iVar5 + 1;
        }
LAB_97be6a74:
        pcVar8 = pcVar8 + iVar5;
      }
      else {
        if (1 < uVar4) {
          if (uVar4 == 2) {
            iVar5 = 0;
            ch = s__z_97c2d788[0];
            while (ch != '\0') {
              pcVar8[iVar5] = ch;
              ch = ".z"[iVar5 + 1];
              iVar5 = iVar5 + 1;
            }
          }
          else {
            if (uVar4 != 3) goto LAB_97be6a78;
            iVar5 = 0;
            ch = s__w_97c2d78c[0];
            while (ch != '\0') {
              pcVar8[iVar5] = ch;
              ch = ".w"[iVar5 + 1];
              iVar5 = iVar5 + 1;
            }
          }
          goto LAB_97be6a74;
        }
        if (uVar4 == 0) {
          iVar5 = 0;
          ch = s__x_97c2d780[0];
          while (ch != '\0') {
            pcVar8[iVar5] = ch;
            ch = ".x"[iVar5 + 1];
            iVar5 = iVar5 + 1;
          }
          goto LAB_97be6a74;
        }
      }
LAB_97be6a78:
      if ((((*(uint *)(iVar3 + param_1) >> 0x11 & 7) == 1) && (param_4 != 0)) &&
         (iVar5 = *(int *)(param_4 + (uint)*(ushort *)(iVar3 + param_1 + 6) * 4), iVar5 != -1)) {
        iVar7 = iVar5;
      }
      uVar4 = *(uint *)(iVar3 + param_1 + 4);
      iVar7 = iVar7 + ((int)(uVar4 << 4 | uVar4 >> 0x1c) >> 0x18);
      if (iVar7 != 0) {
        if (0 < iVar7) {
          iVar5 = 0;
          ch = s___97c2a308[0];
          while (ch != '\0') {
            pcVar8[iVar5] = ch;
            ch = "+"[iVar5 + 1];
            iVar5 = iVar5 + 1;
          }
          pcVar8 = pcVar8 + iVar5;
        }
        iVar5 = ((int (*)())_ncpy_97be5f58)(pcVar8,iVar7);
        pcVar8 = pcVar8 + iVar5;
      }
      iVar5 = 0;
      ch = s___97c2d770[0];
      while (ch != '\0') {
        pcVar8[iVar5] = ch;
        ch = "]"[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      param_2 = pcVar8 + iVar5;
    }
    iVar5 = 0;
    ch = s___97c2a130[0];
    while (ch != '\0') {
      param_2[iVar5] = ch;
      ch = "."[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    pcVar8 = param_2 + iVar5;
    if ((*(uint *)(iVar3 + param_1) & 0x2000) == 0) {
      *pcVar8 = '_';
    }
    else {
      *pcVar8 = (((byte)(*(uint *)(iVar3 + param_1) >> 8) & 3) + 1 & 3) + 0x77;
    }
    uVar4 = *(uint *)(iVar3 + param_1);
    param_2 = pcVar8 + 1;
    if ((uVar4 & 0xc00) != 0) {
      if ((uVar4 & 0x4000) == 0) {
        *param_2 = '_';
      }
      else {
        *param_2 = (((byte)(uVar4 >> 6) & 3) + 1 & 3) + 0x77;
      }
      param_2 = pcVar8 + 2;
    }
    uVar4 = *(uint *)(iVar3 + param_1);
    if (1 < (uVar4 >> 10 & 3)) {
      if ((uVar4 & 0x8000) == 0) {
        *param_2 = '_';
      }
      else {
        *param_2 = (((byte)(uVar4 >> 4) & 3) + 1 & 3) + 0x77;
      }
      param_2 = param_2 + 1;
    }
    uVar4 = *(uint *)(iVar3 + param_1);
    if (2 < (uVar4 >> 10 & 3)) {
      if ((uVar4 & 0x10000) == 0) {
        *param_2 = '_';
      }
      else {
        *param_2 = (((byte)(uVar4 >> 2) & 3) + 1 & 3) + 0x77;
      }
      param_2 = param_2 + 1;
    }
  }
  if (param_6 != 0) {
    param_2 = (char *)((int (*)())_glpWriteOperandSize)(param_2,*(uint *)(iVar3 + param_1) >> 10 & 3,
                                 *(uint *)(iVar3 + param_1) >> 0xc & 1);
  }
  uVar4 = *(uint *)(iVar3 + param_1) >> 0x1c & 7;
  if (uVar4 == 0) {
    return param_2;
  }
  switch(uVar4) {
  case 1:
    iVar5 = 0;
    ch = s__EQ_97c2d7a8[0];
    while (ch != '\0') {
      param_2[iVar5] = ch;
      ch = " (EQ"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    break;
  case 2:
    iVar5 = 0;
    ch = s__GE_97c2d7b0[0];
    while (ch != '\0') {
      param_2[iVar5] = ch;
      ch = " (GE"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    break;
  case 3:
    iVar5 = 0;
    ch = s__GT_97c2d7b8[0];
    while (ch != '\0') {
      param_2[iVar5] = ch;
      ch = " (GT"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    break;
  case 4:
    iVar5 = 0;
    ch = s__LE_97c2d7c0[0];
    while (ch != '\0') {
      param_2[iVar5] = ch;
      ch = " (LE"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    break;
  case 5:
    iVar5 = 0;
    ch = s__LT_97c2d7c8[0];
    while (ch != '\0') {
      param_2[iVar5] = ch;
      ch = " (LT"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    break;
  case 6:
    iVar5 = 0;
    ch = s__NE_97c2d7d0[0];
    while (ch != '\0') {
      param_2[iVar5] = ch;
      ch = " (NE"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    break;
  case 7:
    iVar5 = 0;
    ch = s__FL_97c2d7d8[0];
    while (ch != '\0') {
      param_2[iVar5] = ch;
      ch = " (FL"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    break;
  default:
    goto switchD_97be6e10_default;
  }
  param_2 = param_2 + iVar5;
switchD_97be6e10_default:
  if (*(int *)(iVar3 + param_1) < 0) {
    *param_2 = '1';
    param_2 = param_2 + 1;
  }
  *param_2 = '.';
  param_2[1] = (((byte)((uint)*(undefined4 *)(iVar3 + param_1) >> 0x1a) & 3) + 1 & 3) + 0x77;
  param_2[2] = ((*(byte *)(iVar3 + param_1) & 3) + 1 & 3) + 0x77;
  param_2[3] = (((byte)(*(uint *)(iVar3 + param_1) >> 0x16) & 3) + 1 & 3) + 0x77;
  param_2[4] = (((byte)(*(uint *)(iVar3 + param_1) >> 0x14) & 3) + 1 & 3) + 0x77;
  param_2[5] = ')';
  return param_2 + 6;
}

/* _glpWriteAddressOperand @ 0x97be70a0 (820 bytes) */
int _glpWriteAddressOperand(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  char ch;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = param_3 * 8;
  if ((*(uint *)(iVar2 + param_1) >> 0x11 & 7) == 4) {
    iVar4 = 0;
    ch = s_adr_97c2d7e0[0];
    while (ch != '\0') {
      *(char *)(param_2 + iVar4) = ch;
      ch = "adr"[iVar4 + 1];
      iVar4 = iVar4 + 1;
    }
    iVar3 = ((int (*)())_ncpy_97be5f58)(param_2 + iVar4,(uint)*(ushort *)(iVar2 + param_1 + 6));
    param_2 = param_2 + iVar4 + iVar3;
  }
  if ((*(uint *)(iVar2 + param_1) & 0x1e000) != 0x1e000) {
    iVar4 = 0;
    ch = s___97c2a130[0];
    while (ch != '\0') {
      *(char *)(param_2 + iVar4) = ch;
      ch = "."[iVar4 + 1];
      iVar4 = iVar4 + 1;
    }
    iVar4 = param_2 + iVar4;
    if (param_4 == 0) {
      if ((*(uint *)(iVar2 + param_1) & 0x2000) != 0) {
        iVar3 = 0;
        ch = s_x_97c2d790[0];
        while (ch != '\0') {
          *(char *)(iVar4 + iVar3) = ch;
          ch = "x"[iVar3 + 1];
          iVar3 = iVar3 + 1;
        }
        iVar4 = iVar4 + iVar3;
      }
      if ((*(uint *)(iVar2 + param_1) & 0x4000) != 0) {
        iVar3 = 0;
        ch = s_y_97c2d794[0];
        while (ch != '\0') {
          *(char *)(iVar4 + iVar3) = ch;
          ch = "y"[iVar3 + 1];
          iVar3 = iVar3 + 1;
        }
        iVar4 = iVar4 + iVar3;
      }
      if ((*(uint *)(iVar2 + param_1) & 0x8000) != 0) {
        iVar3 = 0;
        ch = s_z_97c2d798[0];
        while (ch != '\0') {
          *(char *)(iVar4 + iVar3) = ch;
          ch = "z"[iVar3 + 1];
          iVar3 = iVar3 + 1;
        }
        iVar4 = iVar4 + iVar3;
      }
      if ((*(uint *)(iVar2 + param_1) & 0x10000) == 0) {
        return iVar4;
      }
      iVar2 = 0;
      ch = s_w_97c2d79c[0];
      while (ch != '\0') {
        *(char *)(iVar4 + iVar2) = ch;
        ch = "w"[iVar2 + 1];
        iVar2 = iVar2 + 1;
      }
    }
    else {
      if ((*(uint *)(iVar2 + param_1) & 0x2000) != 0) {
        iVar3 = 0;
        ch = s_x_97c2d790[0];
        while (ch != '\0') {
          *(char *)(iVar4 + iVar3) = ch;
          ch = "x"[iVar3 + 1];
          iVar3 = iVar3 + 1;
        }
        iVar4 = iVar4 + iVar3;
      }
      if (((*(uint *)(iVar2 + param_1) & 0xc00) != 0) &&
         ((*(uint *)(iVar2 + param_1) & 0x4000) != 0)) {
        iVar3 = 0;
        ch = s_y_97c2d794[0];
        while (ch != '\0') {
          *(char *)(iVar4 + iVar3) = ch;
          ch = "y"[iVar3 + 1];
          iVar3 = iVar3 + 1;
        }
        iVar4 = iVar4 + iVar3;
      }
      if ((1 < (*(uint *)(iVar2 + param_1) >> 10 & 3)) &&
         ((*(uint *)(iVar2 + param_1) & 0x8000) != 0)) {
        iVar3 = 0;
        ch = s_z_97c2d798[0];
        while (ch != '\0') {
          *(char *)(iVar4 + iVar3) = ch;
          ch = "z"[iVar3 + 1];
          iVar3 = iVar3 + 1;
        }
        iVar4 = iVar4 + iVar3;
      }
      if ((*(uint *)(iVar2 + param_1) >> 10 & 3) < 3) {
        return iVar4;
      }
      if ((*(uint *)(iVar2 + param_1) & 0x10000) == 0) {
        return iVar4;
      }
      iVar2 = 0;
      ch = s_w_97c2d79c[0];
      while (ch != '\0') {
        *(char *)(iVar4 + iVar2) = ch;
        ch = "w"[iVar2 + 1];
        iVar2 = iVar2 + 1;
      }
    }
    param_2 = iVar4 + iVar2;
  }
  return param_2;
}

/* _glpWriteSourceOperandType @ 0x97be73d4 (1476 bytes) */
int _glpWriteSourceOperandType(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
  int param_7;
{
  char ch;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = param_7 * 8;
  switch(*(uint *)(iVar4 + param_1) >> 0x17 & 7) {
  case 0:
    iVar5 = 0;
    ch = s_att_97c2d7e4[0];
    while (ch != '\0') {
      *(char *)(param_2 + iVar5) = ch;
      ch = "att"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    goto LAB_97be770c;
  case 1:
    iVar5 = 0;
    ch = s_tmp_97c2d76c[0];
    while (ch != '\0') {
      *(char *)(param_2 + iVar5) = ch;
      ch = "tmp"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    if (param_5 == 0) {
      uVar2 = (uint)*(ushort *)(iVar4 + param_1 + 6);
    }
    else {
      uVar2 = *(uint *)(param_5 + (uint)*(ushort *)(iVar4 + param_1 + 6) * 4);
    }
    iVar6 = ((int (*)())_ncpy_97be5f58)(param_2 + iVar5,uVar2);
    param_2 = param_2 + iVar5 + iVar6;
    if (((param_6 != 0) && (-1 < *(int *)(iVar4 + param_1))) &&
       (*(int *)(param_6 + (uint)*(ushort *)(iVar4 + param_1 + 6) * 4) != -1)) {
      iVar5 = 0;
      ch = s___97c29860[0];
      while (ch != '\0') {
        *(char *)(param_2 + iVar5) = ch;
        ch = "["[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      iVar6 = ((int (*)())_ncpy_97be5f58)(param_2 + iVar5,
                             *(undefined4 *)(param_6 + (uint)*(ushort *)(iVar4 + param_1 + 6) * 4));
      iVar6 = param_2 + iVar5 + iVar6;
      iVar5 = 0;
      ch = s___97c2d770[0];
      while (ch != '\0') {
        *(char *)(iVar6 + iVar5) = ch;
        ch = "]"[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
LAB_97be7698:
      param_2 = iVar6 + iVar5;
    }
    break;
  case 2:
    iVar5 = 0;
    ch = s_prm_97c2d7e8[0];
    while (ch != '\0') {
      *(char *)(param_2 + iVar5) = ch;
      ch = "prm"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    iVar6 = ((int (*)())_ncpy_97be5f58)(param_2 + iVar5,
                           *(undefined4 *)(param_3 + (uint)*(ushort *)(iVar4 + param_1 + 6) * 4));
    param_2 = param_2 + iVar5 + iVar6;
    if ((-1 < *(int *)(iVar4 + param_1)) &&
       (*(int *)(param_4 + (uint)*(ushort *)(iVar4 + param_1 + 6) * 4) != -1)) {
      iVar5 = 0;
      ch = s___97c29860[0];
      while (ch != '\0') {
        *(char *)(param_2 + iVar5) = ch;
        ch = "["[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      iVar6 = ((int (*)())_ncpy_97be5f58)(param_2 + iVar5,
                             *(undefined4 *)(param_4 + (uint)*(ushort *)(iVar4 + param_1 + 6) * 4));
      iVar6 = param_2 + iVar5 + iVar6;
      iVar5 = 0;
      ch = s___97c2d770[0];
      while (ch != '\0') {
        *(char *)(iVar6 + iVar5) = ch;
        ch = "]"[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      goto LAB_97be7698;
    }
    break;
  case 3:
    iVar5 = 0;
    ch = s_res_97c2d774[0];
    while (ch != '\0') {
      *(char *)(param_2 + iVar5) = ch;
      ch = "res"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    goto LAB_97be770c;
  case 4:
    iVar5 = 0;
    ch = s_adr_97c2d7e0[0];
    while (ch != '\0') {
      *(char *)(param_2 + iVar5) = ch;
      ch = "adr"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
LAB_97be770c:
    iVar6 = ((int (*)())_ncpy_97be5f58)(param_2 + iVar5,(uint)*(ushort *)(iVar4 + param_1 + 6));
    param_2 = param_2 + iVar5 + iVar6;
  }
  if (-1 < *(int *)(iVar4 + param_1)) {
    return param_2;
  }
  iVar6 = 0;
  iVar5 = 0;
  ch = s__adr_97c2d778[0];
  while (ch != '\0') {
    *(char *)(param_2 + iVar5) = ch;
    ch = "[adr"[iVar5 + 1];
    iVar5 = iVar5 + 1;
  }
  iVar3 = ((int (*)())_ncpy_97be5f58)(param_2 + iVar5,*(uint *)(iVar4 + param_1) >> 0x1e & 1);
  iVar3 = param_2 + iVar5 + iVar3;
  uVar2 = *(uint *)(iVar4 + param_1) >> 0x1c & 3;
  if (uVar2 == 1) {
    iVar5 = 0;
    ch = s__y_97c2d784[0];
    while (ch != '\0') {
      *(char *)(iVar3 + iVar5) = ch;
      ch = ".y"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
  }
  else if (uVar2 < 2) {
    if (uVar2 != 0) goto LAB_97be7894;
    iVar5 = 0;
    ch = s__x_97c2d780[0];
    while (ch != '\0') {
      *(char *)(iVar3 + iVar5) = ch;
      ch = ".x"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
  }
  else if (uVar2 == 2) {
    iVar5 = 0;
    ch = s__z_97c2d788[0];
    while (ch != '\0') {
      *(char *)(iVar3 + iVar5) = ch;
      ch = ".z"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
  }
  else {
    if (uVar2 != 3) goto LAB_97be7894;
    iVar5 = 0;
    ch = s__w_97c2d78c[0];
    while (ch != '\0') {
      *(char *)(iVar3 + iVar5) = ch;
      ch = ".w"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
  }
  iVar3 = iVar3 + iVar5;
LAB_97be7894:
  if ((((((*(uint *)(iVar4 + param_1) >> 0x17 & 7) != 1) || (param_6 == 0)) ||
       (iVar5 = *(int *)(param_6 + (uint)*(ushort *)(iVar4 + param_1 + 6) * 4), iVar5 == -1)) &&
      ((iVar5 = iVar6, (*(uint *)(iVar4 + param_1) >> 0x17 & 7) == 2 && (param_4 != 0)))) &&
     (iVar6 = *(int *)(param_4 + (uint)*(ushort *)(iVar4 + param_1 + 6) * 4), iVar6 != -1)) {
    iVar5 = iVar6;
  }
  iVar5 = iVar5 + (char)*(undefined4 *)(iVar4 + param_1);
  if (iVar5 != 0) {
    if (0 < iVar5) {
      iVar4 = 0;
      ch = s___97c2a308[0];
      while (ch != '\0') {
        *(char *)(iVar3 + iVar4) = ch;
        ch = "+"[iVar4 + 1];
        iVar4 = iVar4 + 1;
      }
      iVar3 = iVar3 + iVar4;
    }
    iVar4 = ((int (*)())_ncpy_97be5f58)(iVar3,iVar5);
    iVar3 = iVar3 + iVar4;
  }
  iVar4 = 0;
  ch = s___97c2d770[0];
  while (ch != '\0') {
    *(char *)(iVar3 + iVar4) = ch;
    ch = "]"[iVar4 + 1];
    iVar4 = iVar4 + 1;
  }
  return iVar3 + iVar4;
}

/* _glpWriteSourceOperandSwizzle @ 0x97be79ac (488 bytes) */
int _glpWriteSourceOperandSwizzle(param_1, param_2, param_3, param_4)
  int param_1;
  char *param_2;
  int param_3;
  int param_4;
{
  char ch;
  int iVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  uint uVar6;
  
  if (param_4 == 0) {
    iVar3 = param_3 * 8;
    if ((*(uint *)(iVar3 + param_1) & 0x7f8000) == 0xd8000) {
      return param_2;
    }
    iVar2 = 0;
    ch = s___97c2a130[0];
    while (ch != '\0') {
      param_2[iVar2] = ch;
      ch = "."[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    uVar4 = *(uint *)(iVar3 + param_1);
    pcVar5 = param_2 + iVar2;
    uVar6 = uVar4 >> 0x15 & 3;
    if (((uVar6 == (uVar4 >> 0x13 & 3)) && (uVar6 == (uVar4 >> 0x11 & 3))) &&
       (uVar6 == (uVar4 >> 0xf & 3))) {
      param_2[iVar2] = ((char)uVar6 + 1U & 3) + 0x77;
    }
    else {
      *pcVar5 = (((byte)(*(uint *)(iVar3 + param_1) >> 0x15) & 3) + 1 & 3) + 0x77;
      pcVar5[1] = (((byte)(*(uint *)(iVar3 + param_1) >> 0x13) & 3) + 1 & 3) + 0x77;
      pcVar5[2] = (((byte)(*(uint *)(iVar3 + param_1) >> 0x11) & 3) + 1 & 3) + 0x77;
      pcVar5 = pcVar5 + 3;
      *pcVar5 = (((byte)(*(uint *)(iVar3 + param_1) >> 0xf) & 3) + 1 & 3) + 0x77;
    }
  }
  else {
    iVar3 = 0;
    ch = s___97c2a130[0];
    while (ch != '\0') {
      param_2[iVar3] = ch;
      ch = "."[iVar3 + 1];
      iVar3 = iVar3 + 1;
    }
    iVar2 = param_3 * 8;
    pcVar5 = param_2 + iVar3 + 1;
    param_2[iVar3] = (((byte)(*(uint *)(iVar2 + param_1) >> 0x15) & 3) + 1 & 3) + 0x77;
    uVar4 = *(uint *)(iVar2 + param_1);
    if ((uVar4 & 0x3000) != 0) {
      *pcVar5 = (((byte)(uVar4 >> 0x13) & 3) + 1 & 3) + 0x77;
      pcVar5 = param_2 + iVar3 + 2;
      uVar4 = *(uint *)(iVar2 + param_1);
    }
    if (1 < (uVar4 >> 0xc & 3)) {
      *pcVar5 = (((byte)(uVar4 >> 0x11) & 3) + 1 & 3) + 0x77;
      pcVar5 = pcVar5 + 1;
      uVar4 = *(uint *)(iVar2 + param_1);
    }
    if ((uVar4 >> 0xc & 3) < 3) {
      return pcVar5;
    }
    *pcVar5 = (((byte)(uVar4 >> 0xf) & 3) + 1 & 3) + 0x77;
  }
  return pcVar5 + 1;
}

/* _glpWriteSourceOperandExtendedSwizzle @ 0x97be7b94 (1024 bytes) */
int _glpWriteSourceOperandExtendedSwizzle(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  char ch;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = 0;
  iVar4 = 0;
  do {
    if (iVar4 == 1) {
      uVar3 = *(uint *)(param_3 * 8 + param_1) >> 8 & 0xf;
      iVar2 = 0;
      ch = s___97c2a324[0];
      while (ch != '\0') {
        *(char *)(param_2 + iVar2) = ch;
        ch = ","[iVar2 + 1];
        iVar2 = iVar2 + 1;
      }
LAB_97be7cf0:
      param_2 = param_2 + iVar2;
    }
    else {
      if (1 < iVar4) {
        if (iVar4 == 2) {
          uVar3 = *(uint *)(param_3 * 8 + param_1) >> 4 & 0xf;
          iVar2 = 0;
          ch = s___97c2a324[0];
          while (ch != '\0') {
            *(char *)(param_2 + iVar2) = ch;
            ch = ","[iVar2 + 1];
            iVar2 = iVar2 + 1;
          }
        }
        else {
          if (iVar4 != 3) goto LAB_97be7cf4;
          uVar3 = *(uint *)(param_3 * 8 + param_1) & 0xf;
          iVar2 = 0;
          ch = s___97c2a324[0];
          while (ch != '\0') {
            *(char *)(param_2 + iVar2) = ch;
            ch = ","[iVar2 + 1];
            iVar2 = iVar2 + 1;
          }
        }
        goto LAB_97be7cf0;
      }
      if (iVar4 == 0) {
        uVar3 = *(uint *)(param_3 * 8 + param_1) >> 0xc & 0xf;
        iVar2 = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(param_2 + iVar2) = ch;
          ch = ", "[iVar2 + 1];
          iVar2 = iVar2 + 1;
        }
        goto LAB_97be7cf0;
      }
    }
LAB_97be7cf4:
    switch(uVar3) {
    case 0:
      iVar2 = 0;
      ch = s_x_97c2d790[0];
      while (ch != '\0') {
        *(char *)(param_2 + iVar2) = ch;
        ch = "x"[iVar2 + 1];
        iVar2 = iVar2 + 1;
      }
      break;
    case 1:
      iVar2 = 0;
      ch = s_y_97c2d794[0];
      while (ch != '\0') {
        *(char *)(param_2 + iVar2) = ch;
        ch = "y"[iVar2 + 1];
        iVar2 = iVar2 + 1;
      }
      break;
    case 2:
      iVar2 = 0;
      ch = s_z_97c2d798[0];
      while (ch != '\0') {
        *(char *)(param_2 + iVar2) = ch;
        ch = "z"[iVar2 + 1];
        iVar2 = iVar2 + 1;
      }
      break;
    case 3:
      iVar2 = 0;
      ch = s_w_97c2d79c[0];
      while (ch != '\0') {
        *(char *)(param_2 + iVar2) = ch;
        ch = "w"[iVar2 + 1];
        iVar2 = iVar2 + 1;
      }
      break;
    case 4:
      iVar2 = 0;
      ch = s__x_97c2d7f0[0];
      while (ch != '\0') {
        *(char *)(param_2 + iVar2) = ch;
        ch = "-x"[iVar2 + 1];
        iVar2 = iVar2 + 1;
      }
      break;
    case 5:
      iVar2 = 0;
      ch = s__y_97c2d7f4[0];
      while (ch != '\0') {
        *(char *)(param_2 + iVar2) = ch;
        ch = "-y"[iVar2 + 1];
        iVar2 = iVar2 + 1;
      }
      break;
    case 6:
      iVar2 = 0;
      ch = s__z_97c2d7f8[0];
      while (ch != '\0') {
        *(char *)(param_2 + iVar2) = ch;
        ch = "-z"[iVar2 + 1];
        iVar2 = iVar2 + 1;
      }
      break;
    case 7:
      iVar2 = 0;
      ch = s__w_97c2d7fc[0];
      while (ch != '\0') {
        *(char *)(param_2 + iVar2) = ch;
        ch = "-w"[iVar2 + 1];
        iVar2 = iVar2 + 1;
      }
      break;
    case 8:
      iVar2 = 0;
      ch = s_1_97c2d760[0];
      while (ch != '\0') {
        *(char *)(param_2 + iVar2) = ch;
        ch = "1"[iVar2 + 1];
        iVar2 = iVar2 + 1;
      }
      break;
    case 9:
      iVar2 = 0;
      ch = s_0_97c2d800[0];
      while (ch != '\0') {
        *(char *)(param_2 + iVar2) = ch;
        ch = "0"[iVar2 + 1];
        iVar2 = iVar2 + 1;
      }
      break;
    case 10:
      iVar2 = 0;
      ch = s__1_97c2d804[0];
      while (ch != '\0') {
        *(char *)(param_2 + iVar2) = ch;
        ch = "-1"[iVar2 + 1];
        iVar2 = iVar2 + 1;
      }
      break;
    default:
      goto switchD_97be7d14_default;
    }
    param_2 = param_2 + iVar2;
switchD_97be7d14_default:
    iVar4 = iVar4 + 1;
    if (3 < iVar4) {
      return;
    }
  } while( true );
}

/* _glpWriteSourceOperand_97be7fc0 @ 0x97be7fc0 (380 bytes) */
int _glpWriteSourceOperand_97be7fc0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  int param_7;
  int param_8;
  int param_9;
{
  char ch;
  int iVar2;
  int iVar3;
  
  iVar2 = param_7 * 8;
  if ((*(uint *)(iVar2 + param_1) & 0x8000000) != 0) {
    iVar3 = 0;
    ch = s___97c2a2d4[0];
    while (ch != '\0') {
      *(char *)(param_2 + iVar3) = ch;
      ch = "-"[iVar3 + 1];
      iVar3 = iVar3 + 1;
    }
    param_2 = param_2 + iVar3;
  }
  if ((*(uint *)(iVar2 + param_1) & 0x4000000) != 0) {
    iVar3 = 0;
    ch = s___97c2a31c[0];
    while (ch != '\0') {
      *(char *)(param_2 + iVar3) = ch;
      ch = "|"[iVar3 + 1];
      iVar3 = iVar3 + 1;
    }
    param_2 = param_2 + iVar3;
  }
  iVar3 = ((int (*)())_glpWriteSourceOperandType)(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  if ((*(uint *)(iVar2 + param_1) >> 0x17 & 7) != 4) {
    if (param_9 == 0) {
      iVar3 = ((int (*)())_glpWriteSourceOperandSwizzle)(param_1,iVar3,param_7,param_8);
    }
    else {
      iVar3 = ((int (*)())_glpWriteSourceOperandExtendedSwizzle)(param_1,iVar3,param_7 + 1);
    }
  }
  if (param_8 != 0) {
    iVar3 = ((int (*)())_glpWriteOperandSize)(iVar3,*(uint *)(iVar2 + param_1) >> 0xc & 3,
                       *(uint *)(iVar2 + param_1) >> 0xe & 1);
  }
  if ((*(uint *)(iVar2 + param_1) & 0x4000000) != 0) {
    iVar2 = 0;
    ch = s___97c2a31c[0];
    while (ch != '\0') {
      *(char *)(iVar3 + iVar2) = ch;
      ch = "|"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    iVar3 = iVar3 + iVar2;
  }
  return iVar3;
}

/* _glpWriteBranchOperand @ 0x97be813c (796 bytes) */
int _glpWriteBranchOperand(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  char *param_2;
  uint *param_3;
  int param_4;
  int param_5;
{
  char ch;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = 0;
  if (param_3 == (uint *)0x0) {
    iVar5 = -1;
  }
  else {
    uVar4 = *param_3;
    while (uVar4 != (*(uint *)(param_4 * 8 + param_1 + -4) & 0x3ffff)) {
      param_3 = param_3 + 1;
      iVar5 = iVar5 + 1;
      uVar4 = *param_3;
    }
  }
  iVar5 = _sprintf(param_2,"label_%i",iVar5);
  pcVar3 = param_2 + iVar5;
  if (param_5 == 0) {
    return pcVar3;
  }
  iVar5 = param_4 * 8;
  switch(*(uint *)(iVar5 + param_1) >> 0x1c & 7) {
  case 0:
    iVar2 = 0;
    ch = s__TR_97c2d7a0[0];
    while (ch != '\0') {
      pcVar3[iVar2] = ch;
      ch = " (TR"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 1:
    iVar2 = 0;
    ch = s__EQ_97c2d7a8[0];
    while (ch != '\0') {
      pcVar3[iVar2] = ch;
      ch = " (EQ"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 2:
    iVar2 = 0;
    ch = s__GE_97c2d7b0[0];
    while (ch != '\0') {
      pcVar3[iVar2] = ch;
      ch = " (GE"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 3:
    iVar2 = 0;
    ch = s__GT_97c2d7b8[0];
    while (ch != '\0') {
      pcVar3[iVar2] = ch;
      ch = " (GT"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 4:
    iVar2 = 0;
    ch = s__LE_97c2d7c0[0];
    while (ch != '\0') {
      pcVar3[iVar2] = ch;
      ch = " (LE"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 5:
    iVar2 = 0;
    ch = s__LT_97c2d7c8[0];
    while (ch != '\0') {
      pcVar3[iVar2] = ch;
      ch = " (LT"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 6:
    iVar2 = 0;
    ch = s__NE_97c2d7d0[0];
    while (ch != '\0') {
      pcVar3[iVar2] = ch;
      ch = " (NE"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 7:
    iVar2 = 0;
    ch = s__FL_97c2d7d8[0];
    while (ch != '\0') {
      pcVar3[iVar2] = ch;
      ch = " (FL"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  default:
    goto switchD_97be81f4_default;
  }
  pcVar3 = pcVar3 + iVar2;
switchD_97be81f4_default:
  if (*(int *)(iVar5 + param_1) < 0) {
    *pcVar3 = '1';
    pcVar3 = pcVar3 + 1;
  }
  *pcVar3 = '.';
  pcVar3[1] = (((byte)((uint)*(undefined4 *)(iVar5 + param_1) >> 0x1a) & 3) + 1 & 3) + 0x77;
  pcVar3[2] = ((*(byte *)(iVar5 + param_1) & 3) + 1 & 3) + 0x77;
  pcVar3[3] = (((byte)(*(uint *)(iVar5 + param_1) >> 0x16) & 3) + 1 & 3) + 0x77;
  pcVar3[4] = (((byte)(*(uint *)(iVar5 + param_1) >> 0x14) & 3) + 1 & 3) + 0x77;
  pcVar3[5] = ')';
  return pcVar3 + 6;
}

/* _glpWriteTextureOperand_97be8478 @ 0x97be8478 (736 bytes) */
int _glpWriteTextureOperand_97be8478(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  int param_7;
  int param_8;
{
  char ch;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  ch = 't';
  iVar3 = 0;
  do {
    *(char *)(param_2 + iVar3) = ch;
    iVar4 = iVar3 + 1;
    ch = "texture["[iVar3 + 1];
    iVar3 = iVar4;
  } while (ch != '\0');
  iVar4 = param_2 + iVar4;
  if (param_8 == 0) {
    iVar3 = param_7 * 8;
    iVar5 = ((int (*)())_ncpy_97be5f58)(iVar4,*(uint *)(iVar3 + param_1) & 0x1f);
    iVar4 = iVar4 + iVar5;
  }
  else {
    iVar4 = ((int (*)())_glpWriteSourceOperand_97be7fc0)(param_1,iVar4,param_3,param_4,param_5,param_6,param_7,1,0);
    iVar3 = (param_7 + 1) * 8;
  }
  ch = ']';
  iVar5 = 0;
  do {
    *(char *)(iVar4 + iVar5) = ch;
    iVar2 = iVar5 + 1;
    ch = "], "[iVar5 + 1];
    iVar5 = iVar2;
  } while (ch != '\0');
  iVar4 = iVar4 + iVar2;
  switch(*(uint *)(iVar3 + param_1) >> 5 & 7) {
  case 0:
    ch = 'C';
    iVar3 = 0;
    do {
      *(char *)(iVar4 + iVar3) = ch;
      iVar5 = iVar3 + 1;
      ch = "CUBE"[iVar3 + 1];
      iVar3 = iVar5;
    } while (ch != '\0');
    break;
  case 1:
    ch = '3';
    iVar3 = 0;
    do {
      *(char *)(iVar4 + iVar3) = ch;
      iVar5 = iVar3 + 1;
      ch = "3D"[iVar3 + 1];
      iVar3 = iVar5;
    } while (ch != '\0');
    break;
  case 2:
    ch = 'R';
    iVar3 = 0;
    do {
      *(char *)(iVar4 + iVar3) = ch;
      iVar5 = iVar3 + 1;
      ch = "RECT"[iVar3 + 1];
      iVar3 = iVar5;
    } while (ch != '\0');
    break;
  case 3:
    ch = '2';
    iVar3 = 0;
    do {
      *(char *)(iVar4 + iVar3) = ch;
      iVar5 = iVar3 + 1;
      ch = "2D"[iVar3 + 1];
      iVar3 = iVar5;
    } while (ch != '\0');
    break;
  case 4:
    ch = '1';
    iVar3 = 0;
    do {
      *(char *)(iVar4 + iVar3) = ch;
      iVar5 = iVar3 + 1;
      ch = "1D"[iVar3 + 1];
      iVar3 = iVar5;
    } while (ch != '\0');
    break;
  case 5:
    ch = 'S';
    iVar3 = 0;
    do {
      *(char *)(iVar4 + iVar3) = ch;
      iVar5 = iVar3 + 1;
      ch = "SHADOWRECT"[iVar3 + 1];
      iVar3 = iVar5;
    } while (ch != '\0');
    break;
  case 6:
    ch = 'S';
    iVar3 = 0;
    do {
      *(char *)(iVar4 + iVar3) = ch;
      iVar5 = iVar3 + 1;
      ch = "SHADOW2D"[iVar3 + 1];
      iVar3 = iVar5;
    } while (ch != '\0');
    break;
  case 7:
    ch = 'S';
    iVar3 = 0;
    do {
      *(char *)(iVar4 + iVar3) = ch;
      iVar5 = iVar3 + 1;
      ch = "SHADOW1D"[iVar3 + 1];
      iVar3 = iVar5;
    } while (ch != '\0');
    break;
  default:
    goto switchD_97be857c_default;
  }
  iVar4 = iVar4 + iVar5;
switchD_97be857c_default:
  return iVar4;
}

/* _glpDisassemble1Op @ 0x97be8778 (4416 bytes) */
int _glpDisassemble1Op(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11)
  uint *param_1;
  int param_2;
  int *param_3;
  int *param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  int *param_10;
  uint param_11;
{
  uint uVar1;
  char ch;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  char *pcVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  undefined1 *puVar15;
  
  iVar13 = 0;
  uVar1 = *param_1;
  iVar10 = *param_10;
  uVar3 = param_1[1];
  uVar12 = param_11 & 0xff;
  uVar11 = uVar1 >> 0x12 & 0xff;
  iVar9 = 0;
  iVar14 = param_2;
  if (0 < iVar10) {
    do {
      iVar4 = 0;
      iVar5 = iVar4;
      ch = s__97c28c28[0];
      if (s__97c28c28[0] != '\0') {
        do {
          *(char *)(iVar14 + iVar5) = ch;
          iVar4 = iVar5 + 1;
          ch = "  "[iVar5 + 1];
          iVar5 = iVar4;
        } while (ch != '\0');
        iVar10 = *param_10;
      }
      iVar9 = iVar9 + 1;
      iVar14 = iVar14 + iVar4;
    } while (iVar9 < iVar10);
  }
  pcVar8 = *(char **)(&_ppstreamOpString + uVar11 * 4);
  iVar9 = 0;
  ch = *pcVar8;
  while (ch != '\0') {
    *(char *)(iVar14 + iVar9) = ch;
    iVar9 = iVar9 + 1;
    ch = pcVar8[iVar9];
  }
  puVar15 = (undefined1 *)(iVar14 + iVar9);
  switch(uVar11) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x18:
  case 0x19:
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1d:
  case 0x1e:
  case 0x50:
  case 0x51:
  case 0x5c:
  case 0x5d:
  case 0x5e:
  case 0x5f:
  case 99:
  case 100:
  case 0x65:
  case 0x66:
  case 0x6c:
  case 0x6f:
  case 0x70:
    uVar6 = ((int (*)())_glpWritePrecision)(puVar15,param_1[1] >> 0x12 & 3);
    uVar7 = param_1[1];
    iVar14 = ((int (*)())_glpWriteClampSat)(uVar6,uVar7 >> 0x16 & 1,uVar7 >> 0x15 & 1,uVar7 >> 0x14 & 1);
    if (uVar12 != 0) {
      uVar7 = param_1[1];
      iVar14 = ((int (*)())_glpWriteSizeType)(iVar14,uVar7 >> 0x1a & 3,uVar7 >> 0x1c & 1,uVar7 >> 0x17 & 7);
    }
    iVar9 = 0;
    ch = s__97c291c0[0];
    while (ch != '\0') {
      *(char *)(iVar14 + iVar9) = ch;
      ch = " "[iVar9 + 1];
      iVar9 = iVar9 + 1;
    }
    iVar9 = ((int (*)())_glpWriteDestinationOperand_97be6730)(param_1,iVar14 + iVar9,param_7,param_8,1,uVar12);
    iVar14 = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(iVar9 + iVar14) = ch;
      ch = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    puVar15 = (undefined1 *)
              ((int (*)())_glpWriteSourceOperand_97be7fc0)(param_1,iVar9 + iVar14,param_5,param_6,param_7,param_8,2,uVar12,0);
    iVar13 = 2;
    if (uVar1 >> 0x1d != 2) break;
    iVar14 = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      puVar15[iVar14] = ch;
      ch = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    goto LAB_97be9620;
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x2f:
  case 0x30:
  case 0x31:
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x38:
  case 0x39:
  case 0x3a:
  case 0x4e:
  case 0x52:
  case 0x6d:
    uVar6 = ((int (*)())_glpWritePrecision)(puVar15,param_1[1] >> 0x12 & 3);
    uVar1 = param_1[1];
    iVar14 = ((int (*)())_glpWriteClampSat)(uVar6,uVar1 >> 0x16 & 1,uVar1 >> 0x15 & 1,uVar1 >> 0x14 & 1);
    if (uVar12 != 0) {
      uVar1 = param_1[1];
      iVar14 = ((int (*)())_glpWriteSizeType)(iVar14,uVar1 >> 0x1a & 3,uVar1 >> 0x1c & 1,uVar1 >> 0x17 & 7);
    }
    iVar9 = 0;
    ch = s__97c291c0[0];
    while (ch != '\0') {
      *(char *)(iVar14 + iVar9) = ch;
      ch = " "[iVar9 + 1];
      iVar9 = iVar9 + 1;
    }
    iVar9 = ((int (*)())_glpWriteDestinationOperand_97be6730)(param_1,iVar14 + iVar9,param_7,param_8,1,uVar12);
    iVar14 = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(iVar9 + iVar14) = ch;
      ch = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    puVar15 = (undefined1 *)
              ((int (*)())_glpWriteSourceOperand_97be7fc0)(param_1,iVar9 + iVar14,param_5,param_6,param_7,param_8,2,uVar12,0);
    iVar13 = 2;
    iVar14 = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      puVar15[iVar14] = ch;
      ch = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    goto LAB_97be9620;
  case 0x3b:
  case 0x3c:
  case 0x3d:
  case 0x3e:
  case 0x3f:
  case 0x40:
  case 0x53:
  case 0x67:
  case 0x68:
    uVar6 = ((int (*)())_glpWritePrecision)(puVar15,param_1[1] >> 0x12 & 3);
    uVar1 = param_1[1];
    iVar14 = ((int (*)())_glpWriteClampSat)(uVar6,uVar1 >> 0x16 & 1,uVar1 >> 0x15 & 1,uVar1 >> 0x14 & 1);
    if (uVar12 != 0) {
      uVar1 = param_1[1];
      iVar14 = ((int (*)())_glpWriteSizeType)(iVar14,uVar1 >> 0x1a & 3,uVar1 >> 0x1c & 1,uVar1 >> 0x17 & 7);
    }
    iVar9 = 0;
    ch = s__97c291c0[0];
    while (ch != '\0') {
      *(char *)(iVar14 + iVar9) = ch;
      ch = " "[iVar9 + 1];
      iVar9 = iVar9 + 1;
    }
    iVar9 = ((int (*)())_glpWriteDestinationOperand_97be6730)(param_1,iVar14 + iVar9,param_7,param_8,1,uVar12);
    iVar14 = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(iVar9 + iVar14) = ch;
      ch = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    iVar9 = ((int (*)())_glpWriteSourceOperand_97be7fc0)(param_1,iVar9 + iVar14,param_5,param_6,param_7,param_8,2,uVar12,0);
    iVar14 = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(iVar9 + iVar14) = ch;
      ch = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    iVar13 = 3;
    puVar15 = (undefined1 *)
              ((int (*)())_glpWriteSourceOperand_97be7fc0)(param_1,iVar9 + iVar14,param_5,param_6,param_7,param_8,3,uVar12,0);
    iVar14 = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      puVar15[iVar14] = ch;
      ch = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    goto LAB_97be9620;
  case 0x41:
    uVar1 = param_1[1];
    iVar14 = ((int (*)())_glpWriteClampSat)(puVar15,uVar1 >> 0x16 & 1,uVar1 >> 0x15 & 1,uVar1 >> 0x14 & 1);
    if (uVar12 != 0) {
      uVar1 = param_1[1];
      iVar14 = ((int (*)())_glpWriteSizeType)(iVar14,uVar1 >> 0x1a & 3,uVar1 >> 0x1c & 1,uVar1 >> 0x17 & 7);
    }
    iVar9 = 0;
    ch = s__97c291c0[0];
    while (ch != '\0') {
      *(char *)(iVar14 + iVar9) = ch;
      ch = " "[iVar9 + 1];
      iVar9 = iVar9 + 1;
    }
    iVar9 = ((int (*)())_glpWriteDestinationOperand_97be6730)(param_1,iVar14 + iVar9,param_7,param_8,1,uVar12);
    iVar14 = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(iVar9 + iVar14) = ch;
      ch = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    puVar15 = (undefined1 *)
              ((int (*)())_glpWriteSourceOperand_97be7fc0)(param_1,iVar9 + iVar14,param_5,param_6,param_7,param_8,2,uVar12,1);
    iVar13 = 3;
    break;
  case 0x42:
  case 0x43:
    uVar1 = param_1[1];
    iVar14 = ((int (*)())_glpWriteClampSat)(puVar15,uVar1 >> 0x16 & 1,uVar1 >> 0x15 & 1,uVar1 >> 0x14 & 1);
    if (uVar12 != 0) {
      uVar1 = param_1[1];
      iVar14 = ((int (*)())_glpWriteSizeType)(iVar14,uVar1 >> 0x1a & 3,uVar1 >> 0x1c & 1,uVar1 >> 0x17 & 7);
    }
    iVar9 = 0;
    ch = s__97c291c0[0];
    while (ch != '\0') {
      *(char *)(iVar14 + iVar9) = ch;
      ch = " "[iVar9 + 1];
      iVar9 = iVar9 + 1;
    }
    iVar9 = ((int (*)())_glpWriteDestinationOperand_97be6730)(param_1,iVar14 + iVar9,param_7,param_8,1,uVar12);
    iVar14 = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(iVar9 + iVar14) = ch;
      ch = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    iVar9 = ((int (*)())_glpWriteSourceOperand_97be7fc0)(param_1,iVar9 + iVar14,param_5,param_6,param_7,param_8,2,uVar12,0);
    iVar10 = 2;
    iVar14 = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(iVar9 + iVar14) = ch;
      ch = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    goto LAB_97be9848;
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x47:
    uVar1 = param_1[1];
    iVar14 = ((int (*)())_glpWriteClampSat)(puVar15,uVar1 >> 0x16 & 1,uVar1 >> 0x15 & 1,uVar1 >> 0x14 & 1);
    if (uVar12 != 0) {
      uVar1 = param_1[1];
      iVar14 = ((int (*)())_glpWriteSizeType)(iVar14,uVar1 >> 0x1a & 3,uVar1 >> 0x1c & 1,uVar1 >> 0x17 & 7);
    }
    iVar9 = 0;
    ch = s__97c291c0[0];
    while (ch != '\0') {
      *(char *)(iVar14 + iVar9) = ch;
      ch = " "[iVar9 + 1];
      iVar9 = iVar9 + 1;
    }
    iVar9 = ((int (*)())_glpWriteDestinationOperand_97be6730)(param_1,iVar14 + iVar9,param_7,param_8,1,uVar12);
    iVar14 = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(iVar9 + iVar14) = ch;
      ch = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    iVar9 = ((int (*)())_glpWriteSourceOperand_97be7fc0)(param_1,iVar9 + iVar14,param_5,param_6,param_7,param_8,2,uVar12,0);
    iVar14 = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(iVar9 + iVar14) = ch;
      ch = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    puVar15 = (undefined1 *)
              ((int (*)())_glpWriteTextureOperand_97be8478)(param_1,iVar9 + iVar14,param_5,param_6,param_7,param_8,3,uVar12);
    iVar13 = 3 - ((int)-uVar12 >> 0x1f);
    if (uVar12 == 0) break;
    iVar14 = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      puVar15[iVar14] = ch;
      ch = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
LAB_97be9620:
    iVar13 = iVar13 + 1;
    puVar15 = (undefined1 *)
              ((int (*)())_glpWriteSourceOperand_97be7fc0)(param_1,puVar15 + iVar14,param_5,param_6,param_7,param_8,iVar13,uVar12,0);
    break;
  case 0x48:
  case 0x49:
  case 0x4a:
    if (uVar12 != 0) {
      uVar1 = param_1[1];
      puVar15 = (undefined1 *)
                ((int (*)())_glpWriteSizeType)(puVar15,uVar1 >> 0x1a & 3,uVar1 >> 0x1c & 1,uVar1 >> 0x17 & 7);
    }
    iVar14 = 0;
    ch = s__97c291c0[0];
    while (ch != '\0') {
      puVar15[iVar14] = ch;
      ch = " "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    iVar9 = ((int (*)())_glpWriteAddressOperand)(param_1,puVar15 + iVar14,1,uVar12);
    iVar14 = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(iVar9 + iVar14) = ch;
      ch = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
LAB_97be9928:
    puVar15 = (undefined1 *)(iVar9 + iVar14);
    goto LAB_97be99b4;
  case 0x4b:
  case 0x4c:
    iVar14 = 0;
    ch = s__97c291c0[0];
    while (ch != '\0') {
      puVar15[iVar14] = ch;
      ch = " "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    puVar15 = (undefined1 *)
              ((int (*)())_glpWriteBranchOperand)(param_1,puVar15 + iVar14,param_9,1,(uint)(uVar11 == 0x4b));
  case 0x4d:
  case 0x54:
  case 0x59:
  case 0x5a:
  case 0x5b:
  case 0x69:
  case 0x6b:
  case 0x6e:
LAB_97be8e48:
    iVar13 = 1;
    break;
  case 0x4f:
    iVar14 = 0;
    ch = s__97c291c0[0];
    while (ch != '\0') {
      puVar15[iVar14] = ch;
      ch = " "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    goto LAB_97be9988;
  case 0x55:
    *param_10 = *param_10 + 1;
    if (uVar12 != 0) {
      uVar1 = param_1[1];
      iVar9 = ((int (*)())_glpWriteSizeType)(puVar15,uVar1 >> 0x1a & 3,uVar1 >> 0x1c & 1,uVar1 >> 0x17 & 7);
      iVar14 = 0;
      ch = s__97c291c0[0];
      while (ch != '\0') {
        *(char *)(iVar9 + iVar14) = ch;
        ch = " "[iVar14 + 1];
        iVar14 = iVar14 + 1;
      }
      goto LAB_97be9928;
    }
    iVar13 = 1;
    switch(param_1[2] >> 0x1c & 7) {
    case 0:
      iVar14 = 0;
      ch = s_TR_97c2d864[0];
      while (ch != '\0') {
        puVar15[iVar14] = ch;
        ch = " TR"[iVar14 + 1];
        iVar14 = iVar14 + 1;
      }
      break;
    case 1:
      iVar14 = 0;
      ch = s_EQ_97c2d868[0];
      while (ch != '\0') {
        puVar15[iVar14] = ch;
        ch = " EQ"[iVar14 + 1];
        iVar14 = iVar14 + 1;
      }
      break;
    case 2:
      iVar14 = 0;
      ch = s_GE_97c2d86c[0];
      while (ch != '\0') {
        puVar15[iVar14] = ch;
        ch = " GE"[iVar14 + 1];
        iVar14 = iVar14 + 1;
      }
      break;
    case 3:
      iVar14 = 0;
      ch = s_GT_97c2d870[0];
      while (ch != '\0') {
        puVar15[iVar14] = ch;
        ch = " GT"[iVar14 + 1];
        iVar14 = iVar14 + 1;
      }
      break;
    case 4:
      iVar14 = 0;
      ch = s_LE_97c2d874[0];
      while (ch != '\0') {
        puVar15[iVar14] = ch;
        ch = " LE"[iVar14 + 1];
        iVar14 = iVar14 + 1;
      }
      break;
    case 5:
      iVar14 = 0;
      ch = s_LT_97c2d878[0];
      while (ch != '\0') {
        puVar15[iVar14] = ch;
        ch = " LT"[iVar14 + 1];
        iVar14 = iVar14 + 1;
      }
      break;
    case 6:
      iVar14 = 0;
      ch = s_NE_97c2d87c[0];
      while (ch != '\0') {
        puVar15[iVar14] = ch;
        ch = " NE"[iVar14 + 1];
        iVar14 = iVar14 + 1;
      }
      break;
    case 7:
      iVar14 = 0;
      ch = s_FL_97c2d880[0];
      while (ch != '\0') {
        puVar15[iVar14] = ch;
        ch = " FL"[iVar14 + 1];
        iVar14 = iVar14 + 1;
      }
      break;
    default:
      goto switchD_97be8b04_default;
    }
    puVar15 = puVar15 + iVar14;
switchD_97be8b04_default:
    if ((int)param_1[2] < 0) {
      *puVar15 = 0x31;
      puVar15 = puVar15 + 1;
    }
    *puVar15 = 0x2e;
    puVar15[1] = (((byte)(param_1[2] >> 0x1a) & 3) + 1 & 3) + 0x77;
    puVar15[2] = ((*(byte *)(param_1 + 2) & 3) + 1 & 3) + 0x77;
    puVar15[3] = (((byte)(param_1[2] >> 0x16) & 3) + 1 & 3) + 0x77;
    puVar15[4] = (((byte)(param_1[2] >> 0x14) & 3) + 1 & 3) + 0x77;
    puVar15 = puVar15 + 5;
    break;
  case 0x56:
  case 0x57:
    *param_10 = *param_10 + 1;
    iVar14 = 0;
    ch = s__97c291c0[0];
    while (ch != '\0') {
      puVar15[iVar14] = ch;
      ch = " "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    goto LAB_97be9988;
  case 0x58:
  case 0x6a:
    *param_10 = *param_10 + 1;
    goto LAB_97be8e48;
  case 0x60:
  case 0x61:
    iVar14 = 0;
    ch = s__97c291c0[0];
    while (ch != '\0') {
      puVar15[iVar14] = ch;
      ch = " "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
LAB_97be9988:
    puVar15 = puVar15 + iVar14;
LAB_97be99b4:
    puVar15 = (undefined1 *)
              ((int (*)())_glpWriteSourceOperand_97be7fc0)(param_1,puVar15,param_5,param_6,param_7,param_8,2,uVar12,0);
    iVar13 = 2;
    break;
  case 0x62:
    uVar1 = param_1[1];
    iVar14 = ((int (*)())_glpWriteClampSat)(puVar15,uVar1 >> 0x16 & 1,uVar1 >> 0x15 & 1,uVar1 >> 0x14 & 1);
    if (uVar12 != 0) {
      uVar1 = param_1[1];
      iVar14 = ((int (*)())_glpWriteSizeType)(iVar14,uVar1 >> 0x1a & 3,uVar1 >> 0x1c & 1,uVar1 >> 0x17 & 7);
    }
    iVar9 = 0;
    ch = s__97c291c0[0];
    while (ch != '\0') {
      *(char *)(iVar14 + iVar9) = ch;
      ch = " "[iVar9 + 1];
      iVar9 = iVar9 + 1;
    }
    iVar9 = ((int (*)())_glpWriteDestinationOperand_97be6730)(param_1,iVar14 + iVar9,param_7,param_8,1,uVar12);
    iVar14 = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(iVar9 + iVar14) = ch;
      ch = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    iVar9 = ((int (*)())_glpWriteSourceOperand_97be7fc0)(param_1,iVar9 + iVar14,param_5,param_6,param_7,param_8,2,uVar12,0);
    iVar14 = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(iVar9 + iVar14) = ch;
      ch = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    iVar9 = ((int (*)())_glpWriteSourceOperand_97be7fc0)(param_1,iVar9 + iVar14,param_5,param_6,param_7,param_8,3,uVar12,0);
    iVar14 = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(iVar9 + iVar14) = ch;
      ch = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    iVar10 = 4;
    iVar9 = ((int (*)())_glpWriteSourceOperand_97be7fc0)(param_1,iVar9 + iVar14,param_5,param_6,param_7,param_8,4,uVar12,0);
    iVar14 = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(iVar9 + iVar14) = ch;
      ch = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
LAB_97be9848:
    puVar15 = (undefined1 *)
              ((int (*)())_glpWriteTextureOperand_97be8478)(param_1,iVar9 + iVar14,param_5,param_6,param_7,param_8,iVar10 + 1,uVar12);
    iVar13 = (iVar10 + 1) - ((int)-uVar12 >> 0x1f);
  }
  iVar14 = 0;
  ch = s___97c2d884[0];
  while (ch != '\0') {
    puVar15[iVar14] = ch;
    ch = ";"[iVar14 + 1];
    iVar14 = iVar14 + 1;
  }
  pcVar8 = puVar15 + iVar14;
  if (uVar12 != 0) {
    switch(uVar11) {
    case 0x4b:
    case 0x4c:
    case 0x54:
    case 0x55:
    case 0x56:
    case 0x57:
    case 0x58:
    case 0x5a:
    case 0x5b:
    case 0x69:
    case 0x6a:
    case 0x6b:
      iVar14 = _sprintf(pcVar8,"    # Target: %d",uVar3 & 0x3ffff);
      pcVar8 = pcVar8 + iVar14;
    }
  }
  iVar14 = 0;
  ch = s__97c26c38[0];
  while (ch != '\0') {
    pcVar8[iVar14] = ch;
    ch = "\n"[iVar14 + 1];
    iVar14 = iVar14 + 1;
  }
  *param_3 = iVar13;
  *param_4 = (int)(pcVar8 + (iVar14 - param_2));
  return;
}

/* _isTempArrayStart @ 0x97be9b20 (96 bytes) */
int _isTempArrayStart(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint *param_3;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x40);
  iVar1 = param_1 + *(int *)(param_1 + 0x44) * 8;
  if ((iVar3 != 0) && (iVar2 = 0, 0 < iVar3)) {
    do {
      if ((*(uint *)(iVar1 + iVar2 * 8) & 0xffff) == param_2) {
        *param_3 = (uint)*(ushort *)(iVar2 * 8 + iVar1 + 6);
        return 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar3);
  }
  return 0;
}

/* _isParamArrayStart_97be9b80 @ 0x97be9b80 (96 bytes) */
int _isParamArrayStart_97be9b80(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint *param_3;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x38);
  iVar1 = param_1 + *(int *)(param_1 + 0x3c) * 8;
  if ((iVar3 != 0) && (iVar2 = 0, 0 < iVar3)) {
    do {
      if ((*(uint *)(iVar1 + iVar2 * 8) & 0xffff) == param_2) {
        *param_3 = (uint)*(ushort *)(iVar2 * 8 + iVar1 + 6);
        return 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar3);
  }
  return 0;
}

/* _InsertLabel @ 0x97be9be0 (212 bytes) */
int _InsertLabel(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  iVar8 = 0;
  if ((param_5 < 1) || (piVar6 = param_1, param_3 <= *param_1)) {
    bVar1 = param_5 == 0;
    iVar2 = 0;
  }
  else {
    do {
      iVar8 = iVar8 + 1;
      bVar1 = iVar8 == param_5;
      if (param_5 <= iVar8) {
        iVar2 = iVar8 * 4;
        break;
      }
      piVar6 = piVar6 + 1;
      iVar2 = iVar8 * 4;
    } while (*piVar6 < param_3);
  }
  if (bVar1) {
    *(int *)(iVar2 + (int)param_1) = param_3;
    *(undefined4 *)(iVar2 + param_2) = param_4;
    iVar10 = param_5 + 1;
  }
  else {
    iVar7 = *(int *)(iVar2 + (int)param_1);
    iVar10 = param_5;
    if (iVar7 != param_3) {
      iVar8 = iVar8 + 1;
      *(int *)(iVar2 + (int)param_1) = param_3;
      uVar4 = *(undefined4 *)(iVar2 + param_2);
      *(undefined4 *)(iVar2 + param_2) = param_4;
      iVar10 = param_5 + 1;
      if (iVar8 < param_5) {
        iVar3 = param_5 - iVar8;
        uVar5 = uVar4;
        iVar2 = iVar8;
        iVar9 = iVar7;
        do {
          iVar8 = iVar2 + 1;
          iVar7 = param_1[iVar2];
          param_1[iVar2] = iVar9;
          uVar4 = *(undefined4 *)(param_2 + iVar2 * 4);
          *(undefined4 *)(param_2 + iVar2 * 4) = uVar5;
          iVar3 = iVar3 + -1;
          uVar5 = uVar4;
          iVar2 = iVar8;
          iVar9 = iVar7;
        } while (iVar3 != 0);
      }
      param_1[iVar8] = iVar7;
      *(undefined4 *)(param_2 + iVar8 * 4) = uVar4;
    }
  }
  return iVar10;
}

/* _adjustAllocation_97be9cb4 @ 0x97be9cb4 (124 bytes) */
int _adjustAllocation_97be9cb4(param_1, param_2, param_3)
  int *param_1;
  int *param_2;
  int *param_3;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *param_2;
  iVar3 = *param_3;
  if (*param_1 - (iVar3 - iVar1) < 0x100) {
    iVar2 = *param_1 + 0x800;
    *param_1 = iVar2;
    iVar2 = _realloc(*param_2,iVar2);
    *param_3 = iVar2;
    if (iVar2 == 0) {
      return 0;
    }
    *param_2 = iVar2;
    *param_3 = iVar2 + (iVar3 - iVar1);
  }
  return 1;
}

/* _glpPPDisassemble @ 0x97be9d30 (27772 bytes) */
int _glpPPDisassemble(program)
  uint *program;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  byte bVar5;
  char ch;
  uint uVar6;
  uint uVar7;
  int iVar9;
  int iVar10;
  uint *puVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int *piVar15;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 uVar16;
  undefined4 extraout_r3_01;
  void *pvVar17;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 extraout_r4_03;
  undefined4 extraout_r4_04;
  undefined4 extraout_r4_05;
  undefined4 extraout_r4_06;
  undefined4 extraout_r4_07;
  undefined1 *puVar18;
  uint uVar19;
  uint uVar20;
  uint *puVar21;
  int iVar22;
  uint uVar23;
  float *pfVar24;
  byte in_xer_so = 0;
  uint uVar25;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  undefined8 uVar26;
  double in_stack_fffffd08;
  double in_stack_fffffd10;
  double in_stack_fffffd18;
  double in_stack_fffffd20;
  double in_stack_fffffd28;
  char local_2b0;
  char acStack_2af [255];
  char local_1b0 [256];
  int outBufCapacity;
  int *outBuf;
  int *outCursor;
  uint local_a4;
  uint local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int *local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  uint local_64;
  char *local_60;
  int local_5c;
  int local_58;
  
  outBufCapacity = 0x800;
  local_9c = 1;
  outBuf = (int *)_malloc(0x800);
  uVar26 = CONCAT44(outBuf,extraout_r4);
  local_90 = 0;
  local_88 = 0;
  local_84 = 0;
  local_80 = 0;
  local_7c = 0;
  local_78 = (int *)0x0;
  local_74 = 0;
  local_70 = 0;
  local_6c = 0;
  local_68 = 0;
  if (outBuf == (int *)0x0) {
    return (void *)0x0;
  }
  uVar19 = *program;
  local_64 = (uint)(uVar19 - 0x8b30 < 2);
  if (uVar19 == 0x8804) {
    ch = '!';
    iVar22 = 0;
    do {
      *(char *)((int)outBuf + iVar22) = ch;
      iVar9 = iVar22 + 1;
      ch = "!!ARBfp1.0\n"[iVar22 + 1];
      iVar22 = iVar9;
    } while (ch != '\0');
  }
  else if (uVar19 < 0x8805) {
    if (uVar19 == 0x8620) {
      ch = '!';
      iVar22 = 0;
      do {
        *(char *)((int)outBuf + iVar22) = ch;
        iVar9 = iVar22 + 1;
        ch = "!!ARBvp1.0\n"[iVar22 + 1];
        iVar22 = iVar9;
      } while (ch != '\0');
    }
    else {
LAB_97be9f08:
      ch = 'U';
      iVar22 = 0;
      do {
        *(char *)((int)outBuf + iVar22) = ch;
        iVar9 = iVar22 + 1;
        ch = "Unkown Target (error)\n"[iVar22 + 1];
        iVar22 = iVar9;
      } while (ch != '\0');
    }
  }
  else if (uVar19 == 0x8b30) {
    ch = '!';
    iVar22 = 0;
    do {
      *(char *)((int)outBuf + iVar22) = ch;
      iVar9 = iVar22 + 1;
      ch = "!!ARBfragmentshader\n"[iVar22 + 1];
      iVar22 = iVar9;
    } while (ch != '\0');
  }
  else {
    if (uVar19 != 0x8b31) goto LAB_97be9f08;
    ch = '!';
    iVar22 = 0;
    do {
      *(char *)((int)outBuf + iVar22) = ch;
      iVar9 = iVar22 + 1;
      ch = "!!ARBvertexshader\n"[iVar22 + 1];
      iVar22 = iVar9;
    } while (ch != '\0');
  }
  outCursor = (int *)((int)outBuf + iVar9);
  bVar2 = local_64 == 0;
  if (!bVar2) {
    ch = '\n';
    iVar22 = 0;
    do {
      *(char *)((int)outCursor + iVar22) = ch;
      iVar9 = iVar22 + 1;
      ch = "\n"[iVar22 + 1];
      iVar22 = iVar9;
    } while (ch != '\0');
    outCursor = (int *)((int)outCursor + iVar9);
  }
  uVar20 = program[0x12];
  iVar22 = 0;
  uVar6 = program[0x13];
  if (0 < (int)uVar20) {
    local_60 = "o intialize the Preprocessor";
    do {
      ch = 'O';
      iVar9 = 0;
      do {
        *(char *)((int)outCursor + iVar9) = ch;
        iVar10 = iVar9 + 1;
        ch = "OPTION "[iVar9 + 1];
        iVar9 = iVar10;
      } while (ch != '\0');
      puVar18 = (undefined1 *)((int)outCursor + iVar10);
      switch(program[uVar6 * 2 + iVar22 * 2] & 0xff) {
      case 0:
        ch = 'A';
        iVar9 = 0;
        do {
          puVar18[iVar9] = ch;
          iVar10 = iVar9 + 1;
          ch = "ARB_position_invariant"[iVar9 + 1];
          iVar9 = iVar10;
        } while (ch != '\0');
        break;
      case 1:
        ch = 'A';
        iVar9 = 0;
        do {
          puVar18[iVar9] = ch;
          iVar10 = iVar9 + 1;
          ch = "ARB_fog_exp"[iVar9 + 1];
          iVar9 = iVar10;
        } while (ch != '\0');
        break;
      case 2:
        ch = 'A';
        iVar9 = 0;
        do {
          puVar18[iVar9] = ch;
          iVar10 = iVar9 + 1;
          ch = "ARB_fog_exp2"[iVar9 + 1];
          iVar9 = iVar10;
        } while (ch != '\0');
        break;
      case 3:
        ch = 'A';
        iVar9 = 0;
        do {
          puVar18[iVar9] = ch;
          iVar10 = iVar9 + 1;
          ch = "ARB_fog_linear"[iVar9 + 1];
          iVar9 = iVar10;
        } while (ch != '\0');
        break;
      case 4:
        ch = 'A';
        iVar9 = 0;
        do {
          puVar18[iVar9] = ch;
          iVar10 = iVar9 + 1;
          ch = "ARB_precision_hint_fastest"[iVar9 + 1];
          iVar9 = iVar10;
        } while (ch != '\0');
        break;
      case 5:
        ch = 'A';
        iVar9 = 0;
        do {
          puVar18[iVar9] = ch;
          iVar10 = iVar9 + 1;
          ch = "ARB_precision_hint_nicest"[iVar9 + 1];
          iVar9 = iVar10;
        } while (ch != '\0');
        break;
      case 6:
        ch = 'A';
        iVar9 = 0;
        do {
          puVar18[iVar9] = ch;
          iVar10 = iVar9 + 1;
          ch = "APPLE_no_runtime_compile"[iVar9 + 1];
          iVar9 = iVar10;
        } while (ch != '\0');
        break;
      case 7:
        ch = 'A';
        iVar9 = 0;
        do {
          puVar18[iVar9] = ch;
          iVar10 = iVar9 + 1;
          ch = "APPLE_no_altivec"[iVar9 + 1];
          iVar9 = iVar10;
        } while (ch != '\0');
        break;
      case 8:
        ch = 'N';
        iVar9 = 0;
        do {
          puVar18[iVar9] = ch;
          iVar10 = iVar9 + 1;
          ch = "NV_fragment_program"[iVar9 + 1];
          iVar9 = iVar10;
        } while (ch != '\0');
        break;
      case 9:
        ch = 'N';
        iVar9 = 0;
        do {
          puVar18[iVar9] = ch;
          iVar10 = iVar9 + 1;
          ch = "NV_fragment_program2"[iVar9 + 1];
          iVar9 = iVar10;
        } while (ch != '\0');
        break;
      case 10:
        ch = 'N';
        iVar9 = 0;
        do {
          puVar18[iVar9] = ch;
          iVar10 = iVar9 + 1;
          ch = "NV_vertex_program2"[iVar9 + 1];
          iVar9 = iVar10;
        } while (ch != '\0');
        break;
      case 0xb:
        ch = 'N';
        iVar9 = 0;
        do {
          puVar18[iVar9] = ch;
          iVar10 = iVar9 + 1;
          ch = "NV_vertex_program3"[iVar9 + 1];
          iVar9 = iVar10;
        } while (ch != '\0');
        break;
      case 0xc:
        ch = 'A';
        iVar9 = 0;
        do {
          puVar18[iVar9] = ch;
          iVar10 = iVar9 + 1;
          ch = "ARB_draw_buffers"[iVar9 + 1];
          iVar9 = iVar10;
        } while (ch != '\0');
        break;
      case 0xd:
        ch = 'A';
        iVar9 = 0;
        do {
          puVar18[iVar9] = ch;
          iVar10 = iVar9 + 1;
          ch = "ARB_fragment_program_shadow"[iVar9 + 1];
          iVar9 = iVar10;
        } while (ch != '\0');
        break;
      default:
        goto switchD_97bea038_default;
      }
      puVar18 = puVar18 + iVar10;
switchD_97bea038_default:
      iVar9 = 0;
      ch = local_60[0x3bbc];
      while (ch != '\0') {
        puVar18[iVar9] = ch;
        iVar9 = iVar9 + 1;
        ch = (local_60 + 0x3bbc)[iVar9];
      }
      outCursor = (int *)(puVar18 + iVar9);
      uVar26 = ((int (*)())_adjustAllocation_97be9cb4)(&outBufCapacity,&outBuf,&outCursor);
      if ((int)((ulonglong)uVar26 >> 0x20) == 0) goto LAB_97bf0cec;
      iVar22 = iVar22 + 1;
    } while (iVar22 < (int)uVar20);
  }
  if ((uVar20 != 0) && (!bVar2)) {
    ch = '\n';
    iVar22 = 0;
    do {
      *(char *)((int)outCursor + iVar22) = ch;
      iVar9 = iVar22 + 1;
      ch = "\n"[iVar22 + 1];
      iVar22 = iVar9;
    } while (ch != '\0');
    outCursor = (int *)((int)outCursor + iVar9);
  }
  uVar6 = program[6];
  if (uVar6 != 0) {
    ch = 'A';
    iVar22 = 0;
    do {
      *(char *)((int)outCursor + iVar22) = ch;
      iVar9 = iVar22 + 1;
      ch = "ADDRESS adr0"[iVar22 + 1];
      iVar22 = iVar9;
    } while (ch != '\0');
    iVar22 = 1;
    puVar18 = (undefined1 *)((int)outCursor + iVar9);
    if (1 < (int)uVar6) {
      do {
        ch = ',';
        iVar9 = 0;
        do {
          puVar18[iVar9] = ch;
          iVar10 = iVar9 + 1;
          ch = ", adr"[iVar9 + 1];
          iVar9 = iVar10;
        } while (ch != '\0');
        outCursor = (int *)(puVar18 + iVar10);
        iVar9 = iVar22 + 1;
        iVar22 = ((int (*)())_ncpy_97be5f58)(outCursor,iVar22);
        puVar18 = (undefined1 *)((int)outCursor + iVar22);
        iVar22 = iVar9;
      } while (iVar9 < (int)uVar6);
    }
    ch = ';';
    iVar22 = 0;
    do {
      puVar18[iVar22] = ch;
      iVar9 = iVar22 + 1;
      ch = ";\n"[iVar22 + 1];
      iVar22 = iVar9;
    } while (ch != '\0');
    outCursor = (int *)(puVar18 + iVar9);
    uVar26 = ((int (*)())_adjustAllocation_97be9cb4)(&outBufCapacity,&outBuf,&outCursor);
    if ((int)((ulonglong)uVar26 >> 0x20) == 0) goto LAB_97bf0cec;
    if (!bVar2) {
      ch = '\n';
      iVar22 = 0;
      do {
        *(char *)((int)outCursor + iVar22) = ch;
        iVar9 = iVar22 + 1;
        ch = "\n"[iVar22 + 1];
        iVar22 = iVar9;
      } while (ch != '\0');
      outCursor = (int *)((int)outCursor + iVar9);
    }
  }
  uVar16 = (undefined4)uVar26;
  uVar6 = 0;
  bVar3 = true;
  uVar20 = program[4];
  puVar21 = program + program[5] * 2;
  if (!bVar2) {
    uVar23 = 0xffffffff;
    if ((int)uVar20 < 1) {
LAB_97bea680:
      local_5c = (uint)(byte)((local_80 < 0) << 3 | (0 < local_80) << 2 | (local_80 == 0) << 1 |
                             in_xer_so & 1) << 0x1c;
      local_58 = local_5c;
LAB_97bea698:
      local_78 = (int *)0x0;
      if (program[0x10] != 0) {
        local_78 = (int *)_malloc(program[0x10] << 2);
        uVar16 = extraout_r4_01;
      }
      uVar26 = CONCAT44(local_78,uVar16);
      iVar22 = 0;
      iVar9 = -1;
      local_a4 = 0xffffffff;
      uVar23 = 0xffffffff;
      if (0 < (int)uVar20) {
        iVar10 = 0;
        piVar15 = local_78;
        puVar11 = puVar21;
        do {
          if (uVar23 == 0xffffffff) {
            *(uint *)((uint)*(ushort *)((int)puVar11 + 6) * 4 + local_80) =
                 (uint)*(ushort *)((int)puVar11 + 6);
            uVar26 = ((int (*)())_isTempArrayStart)(program,(uint)*(ushort *)((int)puVar11 + 6),&local_a4);
            if ((int)((ulonglong)uVar26 >> 0x20) == 0) {
              *(int *)(local_7c + (uint)*(ushort *)((int)puVar11 + 6) * 4) = iVar9;
            }
            else {
              uVar23 = (uint)*(ushort *)((int)puVar11 + 6);
              *(undefined4 *)(local_7c + uVar23 * 4) = 0;
              iVar9 = 1;
            }
            bVar1 = *(ushort *)((int)puVar21 + iVar10 + 6) == local_a4;
LAB_97bea790:
            if (bVar1) {
              local_a4 = 0xffffffff;
              uVar23 = 0xffffffff;
              *piVar15 = iVar9;
              piVar15 = piVar15 + 1;
              iVar9 = -1;
            }
          }
          else if ((int)(uint)*(ushort *)((int)puVar11 + 6) <= (int)local_a4) {
            *(uint *)((uint)*(ushort *)((int)puVar11 + 6) * 4 + local_80) = uVar23;
            *(int *)(local_7c + (uint)*(ushort *)((int)puVar11 + 6) * 4) = iVar9;
            iVar9 = iVar9 + 1;
            bVar1 = *(ushort *)((int)puVar11 + 6) == local_a4;
            goto LAB_97bea790;
          }
          iVar22 = iVar22 + 1;
          iVar10 = iVar10 + 8;
          puVar11 = puVar11 + 2;
        } while (iVar22 < (int)uVar20);
      }
      local_90 = 0;
      goto LAB_97bea7e0;
    }
    puVar11 = puVar21 + 1;
    uVar25 = uVar20;
    do {
      uVar7 = *puVar11;
      puVar11 = puVar11 + 2;
      if ((int)uVar23 < (int)(uVar7 & 0xffff)) {
        uVar23 = uVar7 & 0xffff;
      }
      uVar25 = uVar25 - 1;
    } while (uVar25 != 0);
    if (uVar23 == 0xffffffff) goto LAB_97bea680;
    iVar22 = uVar23 * 4 + 4;
    local_80 = _malloc(iVar22);
    local_5c = (uint)(byte)((local_80 < 0) << 3 | (0 < local_80) << 2 | (local_80 == 0) << 1 |
                           in_xer_so & 1) << 0x1c;
    local_7c = _malloc(iVar22);
    bVar5 = (byte)((uint)local_5c >> 0x18);
    if (!(bool)(bVar5 >> 5 & 1)) {
      local_58 = (uint)(byte)((local_7c < 0) << 3 | (0 < local_7c) << 2 | (local_7c == 0) << 1 |
                             in_xer_so & 1) << 0x1c;
      uVar16 = extraout_r4_00;
      if (local_7c == 0) goto joined_r0x97bea678;
      goto LAB_97bea698;
    }
    local_58 = (uint)(byte)((local_7c < 0) << 3 | (0 < local_7c) << 2 | (local_7c == 0) << 1 |
                           in_xer_so & 1) << 0x1c;
joined_r0x97bea678:
    if (!(bool)(bVar5 >> 5 & 1)) {
      _free(local_80);
    }
    iVar22 = local_7c;
    if (!(bool)((byte)((uint)local_58 >> 0x1d) & 1)) {
LAB_97bee10c:
      _free(iVar22);
    }
LAB_97bf0cec:
    _free(outBuf);
    return (void *)0x0;
  }
  local_5c = (uint)(byte)((local_80 < 0) << 3 | (0 < local_80) << 2 | (local_80 == 0) << 1 |
                         in_xer_so & 1) << 0x1c;
  local_58 = local_5c;
LAB_97bea7e0:
  uVar23 = 0;
  local_8c = -1;
  if (0 < (int)uVar20) {
    do {
      iVar22 = uVar23 * 8;
      if (bVar3) {
        uVar6 = puVar21[uVar23 * 2] >> 0x1d;
        if (uVar6 == 1) {
          ch = 'L';
          iVar9 = 0;
          do {
            *(char *)((int)outCursor + iVar9) = ch;
            iVar10 = iVar9 + 1;
            ch = "LONG TEMP "[iVar9 + 1];
            iVar9 = iVar10;
          } while (ch != '\0');
LAB_97bea920:
          outCursor = (int *)((int)outCursor + iVar10);
        }
        else if (uVar6 < 2) {
          if (uVar6 == 0) {
            ch = 'T';
            iVar9 = 0;
            do {
              *(char *)((int)outCursor + iVar9) = ch;
              iVar10 = iVar9 + 1;
              ch = "TEMP "[iVar9 + 1];
              iVar9 = iVar10;
            } while (ch != '\0');
            goto LAB_97bea920;
          }
        }
        else if (uVar6 == 2) {
          ch = 'S';
          iVar9 = 0;
          do {
            *(char *)((int)outCursor + iVar9) = ch;
            iVar10 = iVar9 + 1;
            ch = "SHORT TEMP "[iVar9 + 1];
            iVar9 = iVar10;
          } while (ch != '\0');
          goto LAB_97bea920;
        }
        bVar3 = false;
        uVar6 = puVar21[uVar23 * 2] >> 0x1d;
      }
      if (bVar2) {
        ch = 't';
        iVar9 = 0;
        do {
          *(char *)((int)outCursor + iVar9) = ch;
          iVar10 = iVar9 + 1;
          ch = "tmp"[iVar9 + 1];
          iVar9 = iVar10;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + iVar10);
        iVar22 = ((int (*)())_ncpy_97be5f58)(outCursor,(uint)*(ushort *)((int)puVar21 + iVar22 + 6));
        outCursor = (int *)((int)outCursor + iVar22);
      }
      else {
        iVar9 = *(int *)(local_7c + (uint)*(ushort *)((int)puVar21 + iVar22 + 6) * 4);
        if (iVar9 == -1) {
          ch = 't';
          iVar9 = 0;
          do {
            *(char *)((int)outCursor + iVar9) = ch;
            iVar10 = iVar9 + 1;
            ch = "tmp"[iVar9 + 1];
            iVar9 = iVar10;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + iVar10);
          iVar22 = ((int (*)())_ncpy_97be5f58)(outCursor,*(undefined4 *)
                                            (local_80 +
                                            (uint)*(ushort *)((int)puVar21 + iVar22 + 6) * 4));
          outCursor = (int *)((int)outCursor + iVar22);
          uVar25 = puVar21[uVar23 * 2];
          outCursor = (int *)((int (*)())_glpWriteSizeTypePrecision)(outCursor,uVar25 >> 0x18 & 3,0,uVar25 >> 0x1a & 7,
                                       uVar25 >> 0x1d);
        }
        else {
          if (iVar9 == 0) {
            ch = 't';
            local_8c = 0;
            iVar9 = 0;
            do {
              *(char *)((int)outCursor + iVar9) = ch;
              iVar10 = iVar9 + 1;
              ch = "tmp"[iVar9 + 1];
              iVar9 = iVar10;
            } while (ch != '\0');
            outCursor = (int *)((int)outCursor + iVar10);
            iVar9 = ((int (*)())_ncpy_97be5f58)(outCursor,*(undefined4 *)
                                             (local_80 +
                                             (uint)*(ushort *)((int)puVar21 + iVar22 + 6) * 4));
            ch = '[';
            iVar22 = 0;
            do {
              *(char *)((int)outCursor + iVar22 + iVar9) = ch;
              iVar10 = iVar22 + 1;
              ch = "["[iVar22 + 1];
              iVar22 = iVar10;
            } while (ch != '\0');
            outCursor = (int *)((int)outCursor + iVar10 + iVar9);
            iVar22 = local_90 * 4;
            iVar10 = ((int (*)())_ncpy_97be5f58)(outCursor,local_78[local_90]);
            ch = ']';
            iVar9 = 0;
            do {
              *(char *)((int)outCursor + iVar9 + iVar10) = ch;
              iVar12 = iVar9 + 1;
              ch = "]"[iVar9 + 1];
              iVar9 = iVar12;
            } while (ch != '\0');
            outCursor = (int *)((int)outCursor + iVar12 + iVar10);
            uVar25 = puVar21[uVar23 * 2];
            outCursor = (int *)((int (*)())_glpWriteSizeTypePrecision)(outCursor,uVar25 >> 0x18 & 3,0,uVar25 >> 0x1a & 7,
                                         uVar25 >> 0x1d);
          }
          else {
            local_8c = local_8c + 1;
            iVar22 = local_90 << 2;
          }
          if (local_8c + 1 == *(int *)(iVar22 + (int)local_78)) {
            local_8c = -1;
            local_90 = local_90 + 1;
          }
        }
      }
      uVar25 = uVar23 + 1;
      if (uVar25 == uVar20) {
        ch = ';';
        iVar22 = 0;
        do {
          *(char *)((int)outCursor + iVar22) = ch;
          iVar9 = iVar22 + 1;
          ch = ";\n"[iVar22 + 1];
          iVar22 = iVar9;
        } while (ch != '\0');
LAB_97beacc8:
        outCursor = (int *)((int)outCursor + iVar9);
      }
      else {
        if (puVar21[uVar23 * 2 + 2] >> 0x1d != uVar6) {
          local_60 = "o intialize the Preprocessor";
          ch = ';';
          iVar22 = 0;
          do {
            *(char *)((int)outCursor + iVar22) = ch;
            iVar9 = iVar22 + 1;
            ch = ";\n"[iVar22 + 1];
            iVar22 = iVar9;
          } while (ch != '\0');
          bVar3 = true;
          goto LAB_97beacc8;
        }
        if (local_8c == -1) {
          ch = ',';
          iVar22 = 0;
          do {
            *(char *)((int)outCursor + iVar22) = ch;
            iVar9 = iVar22 + 1;
            ch = ", "[iVar22 + 1];
            iVar22 = iVar9;
          } while (ch != '\0');
          goto LAB_97beacc8;
        }
      }
      uVar26 = ((int (*)())_adjustAllocation_97be9cb4)(&outBufCapacity,&outBuf,&outCursor);
      if ((int)((ulonglong)uVar26 >> 0x20) == 0) goto LAB_97bf0c18;
      uVar23 = uVar25;
    } while ((int)uVar25 < (int)uVar20);
  }
  if (local_78 != (int *)0x0) {
    _free(local_78);
    uVar26 = CONCAT44(extraout_r3,extraout_r4_02);
  }
  if ((uVar20 != 0) && (!bVar2)) {
    ch = '\n';
    iVar22 = 0;
    do {
      *(char *)((int)outCursor + iVar22) = ch;
      iVar9 = iVar22 + 1;
      ch = "\n"[iVar22 + 1];
      iVar22 = iVar9;
    } while (ch != '\0');
    outCursor = (int *)((int)outCursor + iVar9);
  }
  uVar20 = program[8];
  iVar22 = 0;
  uVar6 = program[9];
  if (0 < (int)uVar20) {
    do {
      uVar23 = program[uVar6 * 2 + iVar22 * 2] >> 0x10 & 0xf;
      if (uVar23 != 0) {
        ch = 'A';
        iVar9 = 0;
        do {
          *(char *)((int)outCursor + iVar9) = ch;
          iVar10 = iVar9 + 1;
          ch = "ATTRIB att"[iVar9 + 1];
          iVar9 = iVar10;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + iVar10);
        iVar9 = ((int (*)())_ncpy_97be5f58)(outCursor,(uint)*(ushort *)((int)program + iVar22 * 8 + uVar6 * 8 + 6)
                              );
        outCursor = (int *)((int)outCursor + iVar9);
        if (!bVar2) {
          uVar25 = program[uVar6 * 2 + iVar22 * 2];
          outCursor = (int *)((int (*)())_glpWriteSizeTypePrecision)(outCursor,uVar25 >> 0x18 & 3,0,uVar25 >> 0x1a & 7,
                                       uVar25 >> 0x1d);
        }
        if (uVar19 == 0x8804) {
LAB_97beae94:
          ch = ' ';
          iVar9 = 0;
          do {
            *(char *)((int)outCursor + iVar9) = ch;
            iVar10 = iVar9 + 1;
            ch = " = fragment."[iVar9 + 1];
            iVar9 = iVar10;
          } while (ch != '\0');
LAB_97beaec8:
          outCursor = (int *)((int)outCursor + iVar10);
        }
        else {
          if (uVar19 < 0x8805) {
            uVar25 = 0x8620;
          }
          else {
            if (uVar19 == 0x8b30) goto LAB_97beae94;
            uVar25 = 0x8b31;
          }
          if (uVar19 == uVar25) {
            ch = ' ';
            iVar9 = 0;
            do {
              *(char *)((int)outCursor + iVar9) = ch;
              iVar10 = iVar9 + 1;
              ch = " = vertex."[iVar9 + 1];
              iVar9 = iVar10;
            } while (ch != '\0');
            goto LAB_97beaec8;
          }
        }
        switch(uVar23) {
        default:
          goto switchD_97beaef4_caseD_0;
        case 1:
          ch = 'p';
          iVar9 = 0;
          do {
            *(char *)((int)outCursor + iVar9) = ch;
            iVar10 = iVar9 + 1;
            ch = "position"[iVar9 + 1];
            iVar9 = iVar10;
          } while (ch != '\0');
          break;
        case 2:
          ch = 'c';
          iVar9 = 0;
          do {
            *(char *)((int)outCursor + iVar9) = ch;
            iVar10 = iVar9 + 1;
            ch = "color.primary"[iVar9 + 1];
            iVar9 = iVar10;
          } while (ch != '\0');
          break;
        case 3:
          ch = 'c';
          iVar9 = 0;
          do {
            *(char *)((int)outCursor + iVar9) = ch;
            iVar10 = iVar9 + 1;
            ch = "color.secondary"[iVar9 + 1];
            iVar9 = iVar10;
          } while (ch != '\0');
          break;
        case 4:
          ch = 'n';
          iVar9 = 0;
          do {
            *(char *)((int)outCursor + iVar9) = ch;
            iVar10 = iVar9 + 1;
            ch = "normal"[iVar9 + 1];
            iVar9 = iVar10;
          } while (ch != '\0');
          break;
        case 5:
          ch = 'f';
          iVar9 = 0;
          do {
            *(char *)((int)outCursor + iVar9) = ch;
            iVar10 = iVar9 + 1;
            ch = "fogcoord"[iVar9 + 1];
            iVar9 = iVar10;
          } while (ch != '\0');
          break;
        case 6:
          ch = 'w';
          iVar9 = 0;
          do {
            *(char *)((int)outCursor + iVar9) = ch;
            iVar10 = iVar9 + 1;
            ch = "weight["[iVar9 + 1];
            iVar9 = iVar10;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + iVar10);
          iVar9 = ((int (*)())_ncpy_97be5f58)(outCursor,program[uVar6 * 2 + iVar22 * 2] & 0x1f);
          ch = ']';
          outCursor = (int *)((int)outCursor + iVar9);
          iVar9 = 0;
          do {
            *(char *)((int)outCursor + iVar9) = ch;
            iVar10 = iVar9 + 1;
            ch = "]"[iVar9 + 1];
            iVar9 = iVar10;
          } while (ch != '\0');
          break;
        case 7:
          ch = 't';
          iVar9 = 0;
          do {
            *(char *)((int)outCursor + iVar9) = ch;
            iVar10 = iVar9 + 1;
            ch = "texcoord["[iVar9 + 1];
            iVar9 = iVar10;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + iVar10);
          iVar9 = ((int (*)())_ncpy_97be5f58)(outCursor,program[uVar6 * 2 + iVar22 * 2] & 0x1f);
          ch = ']';
          outCursor = (int *)((int)outCursor + iVar9);
          iVar9 = 0;
          do {
            *(char *)((int)outCursor + iVar9) = ch;
            iVar10 = iVar9 + 1;
            ch = "]"[iVar9 + 1];
            iVar9 = iVar10;
          } while (ch != '\0');
          break;
        case 8:
          ch = 'm';
          iVar9 = 0;
          do {
            *(char *)((int)outCursor + iVar9) = ch;
            iVar10 = iVar9 + 1;
            ch = "matrixindex["[iVar9 + 1];
            iVar9 = iVar10;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + iVar10);
          iVar9 = ((int (*)())_ncpy_97be5f58)(outCursor,program[uVar6 * 2 + iVar22 * 2] & 0x1f);
          ch = ']';
          outCursor = (int *)((int)outCursor + iVar9);
          iVar9 = 0;
          do {
            *(char *)((int)outCursor + iVar9) = ch;
            iVar10 = iVar9 + 1;
            ch = "]"[iVar9 + 1];
            iVar9 = iVar10;
          } while (ch != '\0');
          break;
        case 9:
          ch = 'a';
          iVar9 = 0;
          do {
            *(char *)((int)outCursor + iVar9) = ch;
            iVar10 = iVar9 + 1;
            ch = "attrib["[iVar9 + 1];
            iVar9 = iVar10;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + iVar10);
          iVar9 = ((int (*)())_ncpy_97be5f58)(outCursor,program[uVar6 * 2 + iVar22 * 2] & 0x1f);
          ch = ']';
          outCursor = (int *)((int)outCursor + iVar9);
          iVar9 = 0;
          do {
            *(char *)((int)outCursor + iVar9) = ch;
            iVar10 = iVar9 + 1;
            ch = "]"[iVar9 + 1];
            iVar9 = iVar10;
          } while (ch != '\0');
          break;
        case 10:
          ch = 'm';
          iVar9 = 0;
          do {
            *(char *)((int)outCursor + iVar9) = ch;
            iVar10 = iVar9 + 1;
            ch = "material."[iVar9 + 1];
            iVar9 = iVar10;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + iVar10);
          if ((program[uVar6 * 2 + iVar22 * 2] & 1) == 0) {
            ch = 'f';
            iVar9 = 0;
            do {
              *(char *)((int)outCursor + iVar9) = ch;
              iVar10 = iVar9 + 1;
              ch = "front."[iVar9 + 1];
              iVar9 = iVar10;
            } while (ch != '\0');
LAB_97beb3a4:
            outCursor = (int *)((int)outCursor + iVar10);
          }
          else if ((program[uVar6 * 2 + iVar22 * 2] & 1) == 1) {
            ch = 'b';
            iVar9 = 0;
            do {
              *(char *)((int)outCursor + iVar9) = ch;
              iVar10 = iVar9 + 1;
              ch = "back."[iVar9 + 1];
              iVar9 = iVar10;
            } while (ch != '\0');
            goto LAB_97beb3a4;
          }
          switch(program[uVar6 * 2 + iVar22 * 2] >> 0xc & 0xf) {
          case 0:
            ch = 'a';
            iVar9 = 0;
            do {
              *(char *)((int)outCursor + iVar9) = ch;
              iVar10 = iVar9 + 1;
              ch = "ambient"[iVar9 + 1];
              iVar9 = iVar10;
            } while (ch != '\0');
            break;
          case 1:
            ch = 'd';
            iVar9 = 0;
            do {
              *(char *)((int)outCursor + iVar9) = ch;
              iVar10 = iVar9 + 1;
              ch = "diffuse"[iVar9 + 1];
              iVar9 = iVar10;
            } while (ch != '\0');
            break;
          case 2:
            ch = 's';
            iVar9 = 0;
            do {
              *(char *)((int)outCursor + iVar9) = ch;
              iVar10 = iVar9 + 1;
              ch = "specular"[iVar9 + 1];
              iVar9 = iVar10;
            } while (ch != '\0');
            break;
          case 3:
            ch = 'e';
            iVar9 = 0;
            do {
              *(char *)((int)outCursor + iVar9) = ch;
              iVar10 = iVar9 + 1;
              ch = "emission"[iVar9 + 1];
              iVar9 = iVar10;
            } while (ch != '\0');
            break;
          case 4:
            ch = 's';
            iVar9 = 0;
            do {
              *(char *)((int)outCursor + iVar9) = ch;
              iVar10 = iVar9 + 1;
              ch = "shininess"[iVar9 + 1];
              iVar9 = iVar10;
            } while (ch != '\0');
            break;
          default:
            goto switchD_97beaef4_caseD_0;
          }
          break;
        case 0xb:
          ch = 'f';
          iVar9 = 0;
          do {
            *(char *)((int)outCursor + iVar9) = ch;
            iVar10 = iVar9 + 1;
            ch = "frontfacing"[iVar9 + 1];
            iVar9 = iVar10;
          } while (ch != '\0');
        }
        outCursor = (int *)((int)outCursor + iVar10);
switchD_97beaef4_caseD_0:
        ch = ';';
        iVar9 = 0;
        do {
          *(char *)((int)outCursor + iVar9) = ch;
          iVar10 = iVar9 + 1;
          ch = ";\n"[iVar9 + 1];
          iVar9 = iVar10;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + iVar10);
        uVar26 = ((int (*)())_adjustAllocation_97be9cb4)(&outBufCapacity,&outBuf,&outCursor);
        if ((int)((ulonglong)uVar26 >> 0x20) == 0) goto LAB_97bf0c18;
      }
      iVar22 = iVar22 + 1;
    } while (iVar22 < (int)uVar20);
  }
  uVar16 = (undefined4)uVar26;
  if ((uVar20 != 0) && (!bVar2)) {
    ch = '\n';
    iVar22 = 0;
    do {
      *(char *)((int)outCursor + iVar22) = ch;
      iVar9 = iVar22 + 1;
      ch = "\n"[iVar22 + 1];
      iVar22 = iVar9;
    } while (ch != '\0');
    outCursor = (int *)((int)outCursor + iVar9);
  }
  uVar6 = program[10];
  puVar21 = program + program[0xb] * 2;
  if (uVar6 == 0) {
    bVar3 = local_88 == 0;
    goto LAB_97bed528;
  }
  uVar20 = 0xffffffff;
  if ((int)uVar6 < 1) {
LAB_97beb670:
    bVar3 = local_88 == 0;
  }
  else {
    puVar11 = puVar21 + 1;
    uVar23 = uVar6;
    do {
      uVar25 = *puVar11;
      puVar11 = puVar11 + 2;
      if ((int)uVar20 < (int)(uVar25 & 0xffff)) {
        uVar20 = uVar25 & 0xffff;
      }
      uVar23 = uVar23 - 1;
    } while (uVar23 != 0);
    if (uVar20 == 0xffffffff) goto LAB_97beb670;
    iVar22 = uVar20 * 4 + 4;
    local_88 = _malloc(iVar22);
    bVar1 = local_88 == 0;
    local_84 = _malloc(iVar22);
    if ((bVar1) || (bVar3 = false, uVar16 = extraout_r4_03, local_84 == 0)) {
      bVar3 = local_84 == 0;
joined_r0x97beb668:
      if (!bVar1) {
        _free(local_88);
      }
      if (!bVar3) {
        _free(local_84);
      }
LAB_97bf0c18:
      bVar5 = (byte)((uint)local_5c >> 0x18);
      goto joined_r0x97bea678;
    }
  }
  local_78 = (int *)0x0;
  if (program[0xe] != 0) {
    local_78 = (int *)_malloc(program[0xe] << 2);
    uVar16 = extraout_r4_04;
  }
  uVar26 = CONCAT44(local_78,uVar16);
  iVar22 = 0;
  iVar9 = -1;
  local_a0 = 0xffffffff;
  uVar20 = 0xffffffff;
  piVar15 = local_78;
  puVar11 = puVar21;
  if (0 < (int)uVar6) {
    do {
      if ((*puVar11 & 0x1f0000) != 0) {
        if (uVar20 == 0xffffffff) {
          *(uint *)((uint)*(ushort *)((int)puVar11 + 6) * 4 + local_88) =
               (uint)*(ushort *)((int)puVar11 + 6);
          uVar26 = ((int (*)())_isParamArrayStart_97be9b80)(program,(uint)*(ushort *)((int)puVar11 + 6),&local_a0);
          if ((int)((ulonglong)uVar26 >> 0x20) == 0) {
            *(int *)(local_84 + (uint)*(ushort *)((int)puVar11 + 6) * 4) = iVar9;
          }
          else {
            uVar20 = (uint)*(ushort *)((int)puVar11 + 6);
            *(undefined4 *)(local_84 + uVar20 * 4) = 0;
            iVar9 = 1;
          }
          if (*(ushort *)((int)puVar11 + 6) == local_a0) {
LAB_97beb790:
            local_a0 = 0xffffffff;
            *piVar15 = iVar9;
            uVar20 = 0xffffffff;
            piVar15 = piVar15 + 1;
            iVar9 = -1;
          }
        }
        else if ((int)(uint)*(ushort *)((int)puVar11 + 6) <= (int)local_a0) {
          *(uint *)((uint)*(ushort *)((int)puVar11 + 6) * 4 + local_88) = uVar20;
          *(int *)(local_84 + (uint)*(ushort *)((int)puVar11 + 6) * 4) = iVar9;
          iVar9 = iVar9 + 1;
          if (*(ushort *)((int)puVar11 + 6) == local_a0) goto LAB_97beb790;
        }
      }
      iVar22 = iVar22 + 1;
      puVar11 = puVar11 + 2;
    } while (iVar22 < (int)uVar6);
  }
  iVar22 = 0;
  local_90 = 0;
  if (0 < (int)uVar6) {
    do {
      iVar9 = iVar22 * 8;
      uVar20 = puVar21[iVar22 * 2] >> 0x10 & 0x1f;
      if (uVar20 == 0) goto LAB_97bed4a8;
      iVar10 = *(int *)(local_84 + (uint)*(ushort *)((int)puVar21 + iVar9 + 6) * 4);
      if (iVar10 == -1) {
        ch = 'P';
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10) = ch;
          iVar12 = iVar10 + 1;
          ch = "PARAM prm"[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + iVar12);
        uVar26 = ((int (*)())_ncpy_97be5f58)(outCursor,*(undefined4 *)
                                          (local_88 +
                                          (uint)*(ushort *)((int)puVar21 + iVar9 + 6) * 4));
        outCursor = (int *)((int)outCursor + (int)((ulonglong)uVar26 >> 0x20));
        if (!bVar2) {
          uVar23 = puVar21[iVar22 * 2];
          uVar26 = ((int (*)())_glpWriteSizeTypePrecision)(outCursor,uVar23 >> 0x18 & 3,0,uVar23 >> 0x1a & 7,uVar23 >> 0x1d);
          outCursor = (int *)((ulonglong)uVar26 >> 0x20);
        }
        ch = ' ';
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10) = ch;
          iVar12 = iVar10 + 1;
          ch = " = "[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
      }
      else if (iVar10 == 0) {
        ch = 'P';
        local_8c = 0;
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10) = ch;
          iVar12 = iVar10 + 1;
          ch = "PARAM prm"[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + iVar12);
        iVar12 = ((int (*)())_ncpy_97be5f58)(outCursor,*(undefined4 *)
                                          (local_88 +
                                          (uint)*(ushort *)((int)puVar21 + iVar9 + 6) * 4));
        ch = '[';
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10 + iVar12) = ch;
          iVar13 = iVar10 + 1;
          ch = "["[iVar10 + 1];
          iVar10 = iVar13;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + iVar13 + iVar12);
        uVar26 = ((int (*)())_ncpy_97be5f58)(outCursor,local_78[local_90]);
        ch = ']';
        puVar18 = (undefined1 *)((int)outCursor + (int)((ulonglong)uVar26 >> 0x20));
        iVar10 = 0;
        do {
          puVar18[iVar10] = ch;
          iVar12 = iVar10 + 1;
          ch = "]"[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
        outCursor = (int *)(puVar18 + iVar12);
        if (!bVar2) {
          uVar23 = puVar21[iVar22 * 2];
          uVar26 = ((int (*)())_glpWriteSizeTypePrecision)(outCursor,uVar23 >> 0x18 & 3,0,uVar23 >> 0x1a & 7,uVar23 >> 0x1d);
          outCursor = (int *)((ulonglong)uVar26 >> 0x20);
        }
        ch = ' ';
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10) = ch;
          iVar12 = iVar10 + 1;
          ch = " = {\n    "[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
      }
      else {
        ch = ' ';
        local_8c = local_8c + 1;
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10) = ch;
          iVar12 = iVar10 + 1;
          ch = "    "[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
      }
      if (uVar20 == 0) {
LAB_97bebb2c:
        ch = 's';
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10 + iVar12) = ch;
          iVar13 = iVar10 + 1;
          ch = "state."[iVar10 + 1];
          iVar10 = iVar13;
        } while (ch != '\0');
      }
      else if (uVar20 < 3) {
        ch = 'p';
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10 + iVar12) = ch;
          iVar13 = iVar10 + 1;
          ch = "program."[iVar10 + 1];
          iVar10 = iVar13;
        } while (ch != '\0');
      }
      else {
        if (uVar20 != 0x11) goto LAB_97bebb2c;
        iVar13 = 0;
      }
      outCursor = (int *)((int)outCursor + iVar13 + iVar12);
      switch(uVar20) {
      default:
        goto switchD_97bebb8c_caseD_0;
      case 1:
        ch = 'l';
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10) = ch;
          iVar12 = iVar10 + 1;
          ch = "local["[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + iVar12);
        iVar10 = ((int (*)())_ncpy_97be5f58)(outCursor,puVar21[iVar22 * 2] & 0xffff);
        ch = ']';
        outCursor = (int *)((int)outCursor + iVar10);
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10) = ch;
          iVar12 = iVar10 + 1;
          ch = "]"[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
        goto LAB_97bed34c;
      case 2:
        ch = 'e';
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10) = ch;
          iVar12 = iVar10 + 1;
          ch = "env["[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + iVar12);
        iVar10 = ((int (*)())_ncpy_97be5f58)(outCursor,puVar21[iVar22 * 2] & 0xffff);
        ch = ']';
        outCursor = (int *)((int)outCursor + iVar10);
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10) = ch;
          iVar12 = iVar10 + 1;
          ch = "]"[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
        goto LAB_97bed34c;
      case 3:
        ch = 'l';
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10) = ch;
          iVar12 = iVar10 + 1;
          ch = "light["[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + iVar12);
        iVar12 = ((int (*)())_ncpy_97be5f58)(outCursor,puVar21[iVar22 * 2] & 0xff);
        ch = ']';
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10 + iVar12) = ch;
          iVar13 = iVar10 + 1;
          ch = "]."[iVar10 + 1];
          iVar10 = iVar13;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + iVar13 + iVar12);
        switch(puVar21[iVar22 * 2] >> 8 & 0xf) {
        case 0:
          ch = 'a';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "ambient"[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 1:
          ch = 'd';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "diffuse"[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 2:
          ch = 's';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "specular"[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 3:
          ch = 'p';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "position"[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 4:
          ch = 's';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "spot.direction"[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 5:
          ch = 'a';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "attenuation"[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 6:
          ch = 'h';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "half"[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 7:
          ch = 's';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "spotcutoff"[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        default:
          goto switchD_97bebb8c_caseD_0;
        }
        break;
      case 4:
        ch = 'l';
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10) = ch;
          iVar12 = iVar10 + 1;
          ch = "lightprod["[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + iVar12);
        iVar12 = ((int (*)())_ncpy_97be5f58)(outCursor,puVar21[iVar22 * 2] & 0xff);
        ch = ']';
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10 + iVar12) = ch;
          iVar13 = iVar10 + 1;
          ch = "]."[iVar10 + 1];
          iVar10 = iVar13;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + iVar13 + iVar12);
        uVar20 = puVar21[iVar22 * 2] >> 8 & 1;
        if (uVar20 == 0) {
          ch = 'f';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "front."[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
LAB_97bec0e8:
          outCursor = (int *)((int)outCursor + iVar12);
        }
        else if (uVar20 == 1) {
          ch = 'b';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "back."[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          goto LAB_97bec0e8;
        }
        uVar20 = puVar21[iVar22 * 2] >> 9 & 3;
        if (uVar20 == 1) {
          ch = 'd';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "diffuse"[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        }
        if (uVar20 < 2) {
          if (uVar20 == 0) {
            ch = 'a';
            iVar10 = 0;
            do {
              *(char *)((int)outCursor + iVar10) = ch;
              iVar12 = iVar10 + 1;
              ch = "ambient"[iVar10 + 1];
              iVar10 = iVar12;
            } while (ch != '\0');
            break;
          }
        }
        else if (uVar20 == 2) {
          ch = 's';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "specular"[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        }
        goto switchD_97bebb8c_caseD_0;
      case 5:
        if ((puVar21[iVar22 * 2] >> 1 & 7) == 5) {
          ch = 'l';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "lightmodel."[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
        }
        else {
          ch = 'm';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "material."[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
        }
        outCursor = (int *)((int)outCursor + iVar12);
        if ((puVar21[iVar22 * 2] & 1) == 0) {
          ch = 'f';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "front."[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
LAB_97bec310:
          outCursor = (int *)((int)outCursor + iVar12);
        }
        else if ((puVar21[iVar22 * 2] & 1) == 1) {
          ch = 'b';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "back."[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          goto LAB_97bec310;
        }
        switch(puVar21[iVar22 * 2] >> 1 & 7) {
        case 0:
          ch = 'a';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "ambient"[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 1:
          ch = 'd';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "diffuse"[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 2:
          ch = 's';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "specular"[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 3:
          ch = 'e';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "emission"[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 4:
          ch = 's';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "shininess"[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 5:
          ch = 's';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "scenecolor"[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        default:
          goto switchD_97bebb8c_caseD_0;
        }
        break;
      case 6:
        ch = 'l';
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10) = ch;
          iVar12 = iVar10 + 1;
          ch = "lightmodel.ambient"[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
        break;
      case 7:
        ch = 't';
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10) = ch;
          iVar12 = iVar10 + 1;
          ch = "texgen["[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + iVar12);
        iVar12 = ((int (*)())_ncpy_97be5f58)(outCursor,puVar21[iVar22 * 2] & 0x1f);
        ch = ']';
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10 + iVar12) = ch;
          iVar13 = iVar10 + 1;
          ch = "].eye."[iVar10 + 1];
          iVar10 = iVar13;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + iVar13 + iVar12);
        uVar20 = puVar21[iVar22 * 2] >> 5 & 7;
        if (uVar20 == 1) {
          ch = 't';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "t"[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
        }
        else if (uVar20 < 2) {
          if (uVar20 != 0) goto switchD_97bebb8c_caseD_0;
          ch = 's';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "s"[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
        }
        else if (uVar20 == 2) {
          ch = 'r';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "r"[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
        }
        else {
          if (uVar20 != 3) goto switchD_97bebb8c_caseD_0;
          ch = 'q';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "q"[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
        }
        break;
      case 8:
        ch = 't';
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10) = ch;
          iVar12 = iVar10 + 1;
          ch = "texgen["[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + iVar12);
        iVar12 = ((int (*)())_ncpy_97be5f58)(outCursor,puVar21[iVar22 * 2] & 0x1f);
        ch = ']';
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10 + iVar12) = ch;
          iVar13 = iVar10 + 1;
          ch = "].object."[iVar10 + 1];
          iVar10 = iVar13;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + iVar13 + iVar12);
        uVar20 = puVar21[iVar22 * 2] >> 5 & 7;
        if (uVar20 == 1) {
          ch = 't';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "t"[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
        }
        else if (uVar20 < 2) {
          if (uVar20 != 0) goto switchD_97bebb8c_caseD_0;
          ch = 's';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "s"[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
        }
        else if (uVar20 == 2) {
          ch = 'r';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "r"[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
        }
        else {
          if (uVar20 != 3) goto switchD_97bebb8c_caseD_0;
          ch = 'q';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "q"[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
        }
        break;
      case 9:
        ch = 't';
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10) = ch;
          iVar12 = iVar10 + 1;
          ch = "texenv["[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + iVar12);
        iVar10 = ((int (*)())_ncpy_97be5f58)(outCursor,puVar21[iVar22 * 2] & 0x1f);
        ch = ']';
        outCursor = (int *)((int)outCursor + iVar10);
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10) = ch;
          iVar12 = iVar10 + 1;
          ch = "].color"[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
        goto LAB_97bed34c;
      case 10:
        ch = 'c';
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10) = ch;
          iVar12 = iVar10 + 1;
          ch = "clip["[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + iVar12);
        iVar10 = ((int (*)())_ncpy_97be5f58)(outCursor,puVar21[iVar22 * 2] & 0xff);
        ch = ']';
        outCursor = (int *)((int)outCursor + iVar10);
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10) = ch;
          iVar12 = iVar10 + 1;
          ch = "].plane"[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
        goto LAB_97bed34c;
      case 0xb:
        ch = 'f';
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10) = ch;
          iVar12 = iVar10 + 1;
          ch = "fog.color"[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
        break;
      case 0xc:
        ch = 'f';
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10) = ch;
          iVar12 = iVar10 + 1;
          ch = "fog.params"[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
        break;
      case 0xd:
        ch = 'p';
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10) = ch;
          iVar12 = iVar10 + 1;
          ch = "point.size"[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
        break;
      case 0xe:
        ch = 'p';
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10) = ch;
          iVar12 = iVar10 + 1;
          ch = "point.attenuation"[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
        break;
      case 0xf:
        ch = 'd';
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10) = ch;
          iVar12 = iVar10 + 1;
          ch = "depth.range"[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
        break;
      case 0x10:
        ch = 'm';
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10) = ch;
          iVar12 = iVar10 + 1;
          ch = "matrix."[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + iVar12);
        switch(puVar21[iVar22 * 2] >> 8 & 7) {
        case 0:
          ch = 'm';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "mvp."[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          goto LAB_97becb5c;
        case 1:
          ch = 'p';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "projection."[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
LAB_97becb5c:
          outCursor = (int *)((int)outCursor + iVar12);
          goto switchD_97becad4_default;
        case 2:
          ch = 'c';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "color["[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + iVar12);
          iVar10 = ((int (*)())_ncpy_97be5f58)(outCursor,puVar21[iVar22 * 2] & 0xff);
          ch = ']';
          outCursor = (int *)((int)outCursor + iVar10);
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "]."[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 3:
          ch = 'm';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "modelview["[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + iVar12);
          iVar10 = ((int (*)())_ncpy_97be5f58)(outCursor,puVar21[iVar22 * 2] & 0xff);
          ch = ']';
          outCursor = (int *)((int)outCursor + iVar10);
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "]."[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 4:
          ch = 't';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "texture["[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + iVar12);
          iVar10 = ((int (*)())_ncpy_97be5f58)(outCursor,puVar21[iVar22 * 2] & 0xff);
          ch = ']';
          outCursor = (int *)((int)outCursor + iVar10);
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "]."[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 5:
          ch = 'p';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "program["[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + iVar12);
          iVar10 = ((int (*)())_ncpy_97be5f58)(outCursor,puVar21[iVar22 * 2] & 0xff);
          ch = ']';
          outCursor = (int *)((int)outCursor + iVar10);
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "]."[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        default:
          goto switchD_97becad4_default;
        }
        outCursor = (int *)((int)outCursor + iVar12);
switchD_97becad4_default:
        uVar20 = puVar21[iVar22 * 2] >> 0xe & 3;
        if (uVar20 == 1) {
          ch = 't';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "transpose."[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
LAB_97bece9c:
          outCursor = (int *)((int)outCursor + iVar12);
        }
        else if (1 < uVar20) {
          if (uVar20 == 2) {
            ch = 'i';
            iVar10 = 0;
            do {
              *(char *)((int)outCursor + iVar10) = ch;
              iVar12 = iVar10 + 1;
              ch = "inverse."[iVar10 + 1];
              iVar10 = iVar12;
            } while (ch != '\0');
          }
          else {
            if (uVar20 != 3) goto LAB_97becea8;
            ch = 'i';
            iVar10 = 0;
            do {
              *(char *)((int)outCursor + iVar10) = ch;
              iVar12 = iVar10 + 1;
              ch = "invtrans."[iVar10 + 1];
              iVar10 = iVar12;
            } while (ch != '\0');
          }
          goto LAB_97bece9c;
        }
LAB_97becea8:
        ch = 'r';
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10) = ch;
          iVar12 = iVar10 + 1;
          ch = "row["[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + iVar12);
        iVar10 = ((int (*)())_ncpy_97be5f58)(outCursor,puVar21[iVar22 * 2] >> 0xc & 3);
        ch = ']';
        outCursor = (int *)((int)outCursor + iVar10);
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10) = ch;
          iVar12 = iVar10 + 1;
          ch = "]"[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
LAB_97bed34c:
        outCursor = (int *)((int)outCursor + iVar12);
        goto switchD_97bebb8c_caseD_0;
      case 0x11:
        pfVar24 = (float *)(program + program[0x1b] * 2 + (puVar21[iVar22 * 2] & 0xffff) * 4);
        switch(puVar21[iVar22 * 2] >> 0x1a & 7) {
        case 0:
        case 1:
          ch = '{';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "{"[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + iVar12);
          uVar26 = ((char * (*)())_glp_dtostr)((int)((ulonglong)uVar26 >> 0x20),(int)uVar26,outCursor,
                               (int)outBuf + (outBufCapacity - (int)outCursor),(double)*pfVar24,1e-07,
                               in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_fffffd08,
                               in_stack_fffffd10,in_stack_fffffd18,in_stack_fffffd20,
                               in_stack_fffffd28);
          iVar12 = (int)((ulonglong)uVar26 >> 0x20);
          ch = ',';
          iVar10 = 0;
          do {
            *(char *)(iVar12 + iVar10) = ch;
            iVar13 = iVar10 + 1;
            ch = ", "[iVar10 + 1];
            iVar10 = iVar13;
          } while (ch != '\0');
          outCursor = (int *)(iVar12 + iVar13);
          uVar26 = ((char * (*)())_glp_dtostr)(iVar12,(int)uVar26,outCursor,
                               (int)outBuf + (outBufCapacity - (int)outCursor),(double)pfVar24[1],1e-07,
                               in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_fffffd08,
                               in_stack_fffffd10,in_stack_fffffd18,in_stack_fffffd20,
                               in_stack_fffffd28);
          iVar12 = (int)((ulonglong)uVar26 >> 0x20);
          ch = ',';
          iVar10 = 0;
          do {
            *(char *)(iVar12 + iVar10) = ch;
            iVar13 = iVar10 + 1;
            ch = ", "[iVar10 + 1];
            iVar10 = iVar13;
          } while (ch != '\0');
          outCursor = (int *)(iVar12 + iVar13);
          uVar26 = ((char * (*)())_glp_dtostr)(iVar12,(int)uVar26,outCursor,
                               (int)outBuf + (outBufCapacity - (int)outCursor),(double)pfVar24[2],1e-07,
                               in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_fffffd08,
                               in_stack_fffffd10,in_stack_fffffd18,in_stack_fffffd20,
                               in_stack_fffffd28);
          iVar12 = (int)((ulonglong)uVar26 >> 0x20);
          ch = ',';
          iVar10 = 0;
          do {
            *(char *)(iVar12 + iVar10) = ch;
            iVar13 = iVar10 + 1;
            ch = ", "[iVar10 + 1];
            iVar10 = iVar13;
          } while (ch != '\0');
          outCursor = (int *)(iVar12 + iVar13);
          outCursor = (int *)((char * (*)())_glp_dtostr)(iVar12,(int)uVar26,outCursor,
                                        (int)outBuf + (outBufCapacity - (int)outCursor),
                                        (double)pfVar24[3],1e-07,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8
                                        ,in_stack_fffffd08,in_stack_fffffd10,in_stack_fffffd18,
                                        in_stack_fffffd20,in_stack_fffffd28);
          ch = '}';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "}"[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 2:
          ch = '{';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "{-- Fixed constant data not currently supported --}"[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 3:
        case 4:
          ch = '{';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "{"[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + iVar12);
          iVar12 = ((int (*)())_ncpy_97be5f58)(outCursor, *(unsigned int *)pfVar24);
          ch = ',';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10 + iVar12) = ch;
            iVar13 = iVar10 + 1;
            ch = ", "[iVar10 + 1];
            iVar10 = iVar13;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + iVar13 + iVar12);
          iVar12 = ((int (*)())_ncpy_97be5f58)(outCursor, ((unsigned int *)pfVar24)[1]);
          ch = ',';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10 + iVar12) = ch;
            iVar13 = iVar10 + 1;
            ch = ", "[iVar10 + 1];
            iVar10 = iVar13;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + iVar13 + iVar12);
          iVar12 = ((int (*)())_ncpy_97be5f58)(outCursor, ((unsigned int *)pfVar24)[2]);
          ch = ',';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10 + iVar12) = ch;
            iVar13 = iVar10 + 1;
            ch = ", "[iVar10 + 1];
            iVar10 = iVar13;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + iVar13 + iVar12);
          iVar10 = ((int (*)())_ncpy_97be5f58)(outCursor, ((unsigned int *)pfVar24)[3]);
          ch = '}';
          outCursor = (int *)((int)outCursor + iVar10);
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "}"[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          goto LAB_97bed34c;
        default:
          goto switchD_97bebb8c_caseD_0;
        }
        break;
      case 0x12:
        ch = 'n';
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10) = ch;
          iVar12 = iVar10 + 1;
          ch = "normalscale"[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
      }
      outCursor = (int *)((int)outCursor + iVar12);
switchD_97bebb8c_caseD_0:
      if (*(int *)(local_84 + (uint)*(ushort *)((int)puVar21 + iVar9 + 6) * 4) == -1) {
        ch = ';';
        iVar9 = 0;
        do {
          *(char *)((int)outCursor + iVar9) = ch;
          iVar10 = iVar9 + 1;
          ch = ";\n"[iVar9 + 1];
          iVar9 = iVar10;
        } while (ch != '\0');
      }
      else if (local_8c + 1 == local_78[local_90]) {
        ch = '\n';
        local_90 = local_90 + 1;
        iVar9 = 0;
        do {
          *(char *)((int)outCursor + iVar9) = ch;
          iVar10 = iVar9 + 1;
          ch = "\n};\n"[iVar9 + 1];
          iVar9 = iVar10;
        } while (ch != '\0');
      }
      else {
        ch = ',';
        iVar9 = 0;
        do {
          *(char *)((int)outCursor + iVar9) = ch;
          iVar10 = iVar9 + 1;
          ch = ",\n"[iVar9 + 1];
          iVar9 = iVar10;
        } while (ch != '\0');
      }
      outCursor = (int *)((int)outCursor + iVar10);
      uVar26 = ((int (*)())_adjustAllocation_97be9cb4)(&outBufCapacity,&outBuf,&outCursor);
      bVar1 = bVar3;
      if ((int)((ulonglong)uVar26 >> 0x20) == 0) goto joined_r0x97beb668;
LAB_97bed4a8:
      iVar22 = iVar22 + 1;
    } while (iVar22 < (int)uVar6);
  }
  if (local_78 != (int *)0x0) {
    _free(local_78);
    uVar26 = CONCAT44(extraout_r3_00,extraout_r4_05);
  }
  ch = '\n';
  iVar22 = 0;
  do {
    *(char *)((int)outCursor + iVar22) = ch;
    iVar9 = iVar22 + 1;
    ch = "\n"[iVar22 + 1];
    iVar22 = iVar9;
  } while (ch != '\0');
  outCursor = (int *)((int)outCursor + iVar9);
LAB_97bed528:
  uVar20 = program[0xc];
  iVar22 = 0;
  uVar6 = program[0xd];
  bVar1 = bVar3;
  if (0 < (int)uVar20) {
    do {
      uVar23 = program[uVar6 * 2 + iVar22 * 2] >> 0x10 & 0xf;
      if (uVar23 == 0) goto LAB_97bedcb4;
      uVar25 = program[uVar6 * 2 + iVar22 * 2] >> 0x1d;
      if (uVar25 == 1) {
        ch = 'L';
        iVar9 = 0;
        do {
          *(char *)((int)outCursor + iVar9) = ch;
          iVar10 = iVar9 + 1;
          ch = "LONG OUTPUT res"[iVar9 + 1];
          iVar9 = iVar10;
        } while (ch != '\0');
LAB_97bed640:
        outCursor = (int *)((int)outCursor + iVar10);
      }
      else if (uVar25 < 2) {
        if (uVar25 == 0) {
          ch = 'O';
          iVar9 = 0;
          do {
            *(char *)((int)outCursor + iVar9) = ch;
            iVar10 = iVar9 + 1;
            ch = "OUTPUT res"[iVar9 + 1];
            iVar9 = iVar10;
          } while (ch != '\0');
          goto LAB_97bed640;
        }
      }
      else if (uVar25 == 2) {
        ch = 'S';
        iVar9 = 0;
        do {
          *(char *)((int)outCursor + iVar9) = ch;
          iVar10 = iVar9 + 1;
          ch = "SHORT OUTPUT res"[iVar9 + 1];
          iVar9 = iVar10;
        } while (ch != '\0');
        goto LAB_97bed640;
      }
      iVar9 = ((int (*)())_ncpy_97be5f58)(outCursor,(uint)*(ushort *)((int)program + iVar22 * 8 + uVar6 * 8 + 6));
      outCursor = (int *)((int)outCursor + iVar9);
      if (!bVar2) {
        uVar25 = program[uVar6 * 2 + iVar22 * 2];
        outCursor = (int *)((int (*)())_glpWriteSizeTypePrecision)(outCursor,uVar25 >> 0x18 & 3,0,uVar25 >> 0x1a & 7,uVar25 >> 0x1d
                                    );
      }
      ch = ' ';
      iVar9 = 0;
      do {
        *(char *)((int)outCursor + iVar9) = ch;
        iVar10 = iVar9 + 1;
        ch = " = "[iVar9 + 1];
        iVar9 = iVar10;
      } while (ch != '\0');
      outCursor = (int *)((int)outCursor + iVar10);
      switch(uVar23) {
      default:
        goto switchD_97bed6f4_caseD_0;
      case 1:
        ch = 'r';
        iVar9 = 0;
        do {
          *(char *)((int)outCursor + iVar9) = ch;
          iVar10 = iVar9 + 1;
          ch = "result.position"[iVar9 + 1];
          iVar9 = iVar10;
        } while (ch != '\0');
        break;
      case 2:
        ch = 'r';
        iVar9 = 0;
        do {
          *(char *)((int)outCursor + iVar9) = ch;
          iVar10 = iVar9 + 1;
          ch = "result.fogcoord"[iVar9 + 1];
          iVar9 = iVar10;
        } while (ch != '\0');
        break;
      case 3:
        ch = 'r';
        iVar9 = 0;
        do {
          *(char *)((int)outCursor + iVar9) = ch;
          iVar10 = iVar9 + 1;
          ch = "result.pointsize"[iVar9 + 1];
          iVar9 = iVar10;
        } while (ch != '\0');
        break;
      case 4:
        ch = 'r';
        iVar9 = 0;
        do {
          *(char *)((int)outCursor + iVar9) = ch;
          iVar10 = iVar9 + 1;
          ch = "result.color"[iVar9 + 1];
          iVar9 = iVar10;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + iVar10);
        if ((uVar19 == 0x8620) || (uVar19 == 0x8b31)) {
          if ((program[uVar6 * 2 + iVar22 * 2] & 1) == 0) {
            ch = '.';
            iVar9 = 0;
            do {
              *(char *)((int)outCursor + iVar9) = ch;
              iVar10 = iVar9 + 1;
              ch = ".front.primary"[iVar9 + 1];
              iVar9 = iVar10;
            } while (ch != '\0');
          }
          else {
            if ((program[uVar6 * 2 + iVar22 * 2] & 1) != 1) goto switchD_97bed6f4_caseD_0;
            ch = '.';
            iVar9 = 0;
            do {
              *(char *)((int)outCursor + iVar9) = ch;
              iVar10 = iVar9 + 1;
              ch = ".back.primary"[iVar9 + 1];
              iVar9 = iVar10;
            } while (ch != '\0');
          }
          break;
        }
        if (((uVar19 == 0x8804) || (uVar19 == 0x8b30)) &&
           (1 < (program[uVar6 * 2 + iVar22 * 2] >> 1 & 7))) {
          ch = '[';
          iVar9 = 0;
          do {
            *(char *)((int)outCursor + iVar9) = ch;
            iVar10 = iVar9 + 1;
            ch = "["[iVar9 + 1];
            iVar9 = iVar10;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + iVar10);
          iVar10 = ((int (*)())_ncpy_97be5f58)(outCursor,program[uVar6 * 2 + iVar22 * 2] >> 1 & 7);
          ch = ']';
          iVar9 = 0;
          do {
            *(char *)((int)outCursor + iVar9 + iVar10) = ch;
            iVar12 = iVar9 + 1;
            ch = "]"[iVar9 + 1];
            iVar9 = iVar12;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + iVar12 + iVar10);
        }
        goto switchD_97bed6f4_caseD_0;
      case 5:
        ch = 'r';
        iVar9 = 0;
        do {
          *(char *)((int)outCursor + iVar9) = ch;
          iVar10 = iVar9 + 1;
          ch = "result.color"[iVar9 + 1];
          iVar9 = iVar10;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + iVar10);
        if ((uVar19 == 0x8620) || (uVar19 == 0x8b31)) {
          if ((program[uVar6 * 2 + iVar22 * 2] & 1) == 0) {
            ch = '.';
            iVar9 = 0;
            do {
              *(char *)((int)outCursor + iVar9) = ch;
              iVar10 = iVar9 + 1;
              ch = ".front.secondary"[iVar9 + 1];
              iVar9 = iVar10;
            } while (ch != '\0');
          }
          else {
            if ((program[uVar6 * 2 + iVar22 * 2] & 1) != 1) goto switchD_97bed6f4_caseD_0;
            ch = '.';
            iVar9 = 0;
            do {
              *(char *)((int)outCursor + iVar9) = ch;
              iVar10 = iVar9 + 1;
              ch = ".back.secondary"[iVar9 + 1];
              iVar9 = iVar10;
            } while (ch != '\0');
          }
          break;
        }
        goto switchD_97bed6f4_caseD_0;
      case 6:
        ch = 'r';
        iVar9 = 0;
        do {
          *(char *)((int)outCursor + iVar9) = ch;
          iVar10 = iVar9 + 1;
          ch = "result.texcoord["[iVar9 + 1];
          iVar9 = iVar10;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + iVar10);
        iVar9 = ((int (*)())_ncpy_97be5f58)(outCursor,program[uVar6 * 2 + iVar22 * 2] & 0x1f);
        ch = ']';
        outCursor = (int *)((int)outCursor + iVar9);
        iVar9 = 0;
        do {
          *(char *)((int)outCursor + iVar9) = ch;
          iVar10 = iVar9 + 1;
          ch = "]"[iVar9 + 1];
          iVar9 = iVar10;
        } while (ch != '\0');
        break;
      case 7:
        ch = 'r';
        iVar9 = 0;
        do {
          *(char *)((int)outCursor + iVar9) = ch;
          iVar10 = iVar9 + 1;
          ch = "result.depth"[iVar9 + 1];
          iVar9 = iVar10;
        } while (ch != '\0');
        break;
      case 8:
        ch = 'r';
        iVar9 = 0;
        do {
          *(char *)((int)outCursor + iVar9) = ch;
          iVar10 = iVar9 + 1;
          ch = "result.eyePosition"[iVar9 + 1];
          iVar9 = iVar10;
        } while (ch != '\0');
        break;
      case 9:
        ch = 'r';
        iVar9 = 0;
        do {
          *(char *)((int)outCursor + iVar9) = ch;
          iVar10 = iVar9 + 1;
          ch = "result.clipVertex"[iVar9 + 1];
          iVar9 = iVar10;
        } while (ch != '\0');
        break;
      case 10:
        ch = 'r';
        iVar9 = 0;
        do {
          *(char *)((int)outCursor + iVar9) = ch;
          iVar10 = iVar9 + 1;
          ch = "result.attrib["[iVar9 + 1];
          iVar9 = iVar10;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + iVar10);
        iVar9 = ((int (*)())_ncpy_97be5f58)(outCursor,program[uVar6 * 2 + iVar22 * 2] & 0x1f);
        ch = ']';
        outCursor = (int *)((int)outCursor + iVar9);
        iVar9 = 0;
        do {
          *(char *)((int)outCursor + iVar9) = ch;
          iVar10 = iVar9 + 1;
          ch = "]"[iVar9 + 1];
          iVar9 = iVar10;
        } while (ch != '\0');
      }
      outCursor = (int *)((int)outCursor + iVar10);
switchD_97bed6f4_caseD_0:
      ch = ';';
      iVar9 = 0;
      do {
        *(char *)((int)outCursor + iVar9) = ch;
        iVar10 = iVar9 + 1;
        ch = ";\n"[iVar9 + 1];
        iVar9 = iVar10;
      } while (ch != '\0');
      outCursor = (int *)((int)outCursor + iVar10);
      uVar26 = ((int (*)())_adjustAllocation_97be9cb4)(&outBufCapacity,&outBuf,&outCursor);
      if ((int)((ulonglong)uVar26 >> 0x20) == 0) goto joined_r0x97beb668;
LAB_97bedcb4:
      iVar22 = iVar22 + 1;
    } while (iVar22 < (int)uVar20);
  }
  if ((uVar20 != 0) || (bVar2)) {
    ch = '\n';
    iVar22 = 0;
    do {
      *(char *)((int)outCursor + iVar22) = ch;
      iVar9 = iVar22 + 1;
      ch = "\n"[iVar22 + 1];
      iVar22 = iVar9;
    } while (ch != '\0');
    outCursor = (int *)((int)outCursor + iVar9);
  }
  uVar20 = program[0x14];
  iVar22 = 0;
  uVar6 = program[0x15];
  uVar19 = uVar20;
  if (0 < (int)uVar20) {
    do {
      if ((program[uVar6 * 2 + iVar22 * 2] >> 0x12 & 0xff) - 0x4b < 2) {
        local_6c = local_6c + 1;
      }
      iVar22 = iVar22 + (program[uVar6 * 2 + iVar22 * 2] >> 0x1d) + 2;
      uVar19 = uVar19 - 1;
    } while (uVar19 != 0);
  }
  bVar4 = local_6c == 0;
  if (!bVar4) {
    iVar22 = local_6c << 2;
    iVar9 = 0;
    iVar10 = 0;
    local_74 = _malloc(iVar22);
    _memset(local_74,0,local_6c);
    local_70 = _malloc(iVar22);
    uVar16 = _memset(local_70,0,local_6c);
    uVar26 = CONCAT44(uVar16,extraout_r4_06);
    local_6c = 0;
    bVar4 = true;
    if (0 < (int)uVar20) {
      do {
        uVar19 = program[uVar6 * 2 + iVar10 * 2];
        if ((uVar19 >> 0x12 & 0xff) - 0x4b < 2) {
          uVar26 = ((int (*)())_InsertLabel)(local_74,local_70,program[uVar6 * 2 + iVar10 * 2 + 1] & 0x3ffff,
                                uVar19 & 0x3ffff,local_6c);
          local_6c = (int)((ulonglong)uVar26 >> 0x20);
          uVar19 = program[uVar6 * 2 + iVar10 * 2];
        }
        iVar9 = iVar9 + 1;
        iVar10 = iVar10 + (uVar19 >> 0x1d) + 2;
        bVar4 = local_6c == 0;
      } while (iVar9 < (int)uVar20);
    }
  }
  iVar22 = 0;
  iVar9 = 0;
  if (0 < (int)uVar20) {
    puVar21 = (uint *)(local_68 * 4 + local_74);
    do {
      if (((program[uVar6 * 2 + iVar9 * 2] & 0x3ffff) == 0) && (!bVar2)) {
        ch = 'm';
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10) = ch;
          iVar12 = iVar10 + 1;
          ch = "main:\n"[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + iVar12);
      }
      if (((!bVar4) && (local_68 < local_6c)) &&
         ((program[uVar6 * 2 + iVar9 * 2] & 0x3ffff) == *puVar21)) {
        iVar10 = 0;
        local_9c = local_9c + -1;
        if (0 < local_9c) {
          do {
            ch = ' ';
            iVar12 = 0;
            do {
              *(char *)((int)outCursor + iVar12) = ch;
              iVar13 = iVar12 + 1;
              ch = "  "[iVar12 + 1];
              iVar12 = iVar13;
            } while (ch != '\0');
            iVar10 = iVar10 + 1;
            outCursor = (int *)((int)outCursor + iVar13);
          } while (iVar10 < local_9c);
        }
        ch = 'l';
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10) = ch;
          iVar12 = iVar10 + 1;
          ch = "label_"[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + iVar12);
        iVar12 = ((int (*)())_ncpy_97be5f58)(outCursor,local_68);
        ch = ':';
        local_68 = local_68 + 1;
        puVar21 = puVar21 + 1;
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10 + iVar12) = ch;
          iVar13 = iVar10 + 1;
          ch = ":\n"[iVar10 + 1];
          iVar10 = iVar13;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + iVar13 + iVar12);
        local_9c = local_9c + 1;
      }
      uVar19 = program[uVar6 * 2 + iVar9 * 2] >> 0x12 & 0xff;
      if (((uVar19 == 0x6b) || (uVar19 == 0x58)) ||
         ((uVar19 == 0x59 || ((uVar19 == 0x5a || (uVar19 == 0x5b)))))) {
        local_9c = local_9c + -1;
      }
      ((int (*)())_glpDisassemble1Op)(program + uVar6 * 2 + iVar9 * 2,outCursor,&local_98,&local_94,local_88,
                         local_84,local_80,local_7c,local_74,&local_9c,local_64);
      outCursor = (int *)((int)outCursor + local_94);
      iVar9 = iVar9 + local_98;
      uVar26 = ((int (*)())_adjustAllocation_97be9cb4)(&outBufCapacity,&outBuf,&outCursor);
      if ((int)((ulonglong)uVar26 >> 0x20) == 0) {
        if (!bVar3) {
          _free(local_88);
          _free(local_84);
        }
        if (!(bool)((byte)((uint)local_5c >> 0x1d) & 1)) {
          _free(local_80);
        }
        if (!(bool)((byte)((uint)local_58 >> 0x1d) & 1)) {
          _free(local_7c);
        }
        if (bVar4) goto LAB_97bf0cec;
        _free(local_74);
        iVar22 = local_70;
        goto LAB_97bee10c;
      }
      iVar22 = iVar22 + 1;
      iVar9 = iVar9 + 1;
    } while (iVar22 < (int)uVar20);
  }
  if (!bVar4) {
    if ((local_68 < local_6c) && (iVar22 + 1 == *(int *)(local_74 + local_68 * 4))) {
      ch = ' ';
      iVar22 = 0;
      do {
        *(char *)((int)outCursor + iVar22) = ch;
        iVar9 = iVar22 + 1;
        ch = "  label_"[iVar22 + 1];
        iVar22 = iVar9;
      } while (ch != '\0');
      outCursor = (int *)((int)outCursor + iVar9);
      iVar9 = ((int (*)())_ncpy_97be5f58)(outCursor,local_68);
      ch = ':';
      iVar22 = 0;
      do {
        *(char *)((int)outCursor + iVar22 + iVar9) = ch;
        iVar10 = iVar22 + 1;
        ch = ":\n"[iVar22 + 1];
        iVar22 = iVar10;
      } while (ch != '\0');
      outCursor = (int *)((int)outCursor + iVar10 + iVar9);
    }
    _free(local_74);
    _free(local_70);
    uVar26 = CONCAT44(extraout_r3_01,extraout_r4_07);
  }
  ch = 'E';
  iVar22 = 0;
  do {
    *(char *)((int)outCursor + iVar22) = ch;
    iVar9 = iVar22 + 1;
    ch = "END\n"[iVar22 + 1];
    iVar22 = iVar9;
  } while (ch != '\0');
  uVar6 = program[0x18];
  iVar22 = 0;
  uVar19 = program[0x19];
  outCursor = (int *)((int)outCursor + iVar9);
  iVar9 = 0;
  if (0 < (int)uVar6) {
    local_60 = "o intialize the Preprocessor";
    do {
      ch = 'S';
      uVar20 = program[uVar19 * 2 + iVar9 * 2];
      iVar10 = 0;
      do {
        *(char *)((int)outCursor + iVar10) = ch;
        iVar12 = iVar10 + 1;
        ch = "STATE "[iVar10 + 1];
        iVar10 = iVar12;
      } while (ch != '\0');
      outCursor = (int *)((int)outCursor + iVar12);
      switch(uVar20 >> 0x18 & 7) {
      case 0:
        ch = 'A';
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10) = ch;
          iVar12 = iVar10 + 1;
          ch = "ALPHA_TEST "[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
        switch(program[uVar19 * 2 + iVar9 * 2] & 7) {
        case 0:
          ch = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10 + iVar12) = ch;
            iVar13 = iVar10 + 1;
            ch = "PP_NEVER "[iVar10 + 1];
            iVar10 = iVar13;
          } while (ch != '\0');
          break;
        case 1:
          ch = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10 + iVar12) = ch;
            iVar13 = iVar10 + 1;
            ch = "PP_LESS "[iVar10 + 1];
            iVar10 = iVar13;
          } while (ch != '\0');
          break;
        case 2:
          ch = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10 + iVar12) = ch;
            iVar13 = iVar10 + 1;
            ch = "PP_EQUAL "[iVar10 + 1];
            iVar10 = iVar13;
          } while (ch != '\0');
          break;
        case 3:
          ch = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10 + iVar12) = ch;
            iVar13 = iVar10 + 1;
            ch = "PP_LEQUAL "[iVar10 + 1];
            iVar10 = iVar13;
          } while (ch != '\0');
          break;
        case 4:
          ch = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10 + iVar12) = ch;
            iVar13 = iVar10 + 1;
            ch = "PP_GREATER "[iVar10 + 1];
            iVar10 = iVar13;
          } while (ch != '\0');
          break;
        case 5:
          ch = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10 + iVar12) = ch;
            iVar13 = iVar10 + 1;
            ch = "PP_NOTEQUAL "[iVar10 + 1];
            iVar10 = iVar13;
          } while (ch != '\0');
          break;
        case 6:
          ch = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10 + iVar12) = ch;
            iVar13 = iVar10 + 1;
            ch = "PP_GEQUAL "[iVar10 + 1];
            iVar10 = iVar13;
          } while (ch != '\0');
          break;
        default:
          ch = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10 + iVar12) = ch;
            iVar13 = iVar10 + 1;
            ch = "PP_ALWAYS "[iVar10 + 1];
            iVar10 = iVar13;
          } while (ch != '\0');
        }
        ch = 'r';
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10 + iVar13 + iVar12) = ch;
          iVar14 = iVar10 + 1;
          ch = "ref="[iVar10 + 1];
          iVar10 = iVar14;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + iVar14 + iVar13 + iVar12);
        outCursor = (int *)((char * (*)())_glp_dtostr)((int)((ulonglong)uVar26 >> 0x20),(int)uVar26,outCursor,
                                      (int)outBuf + (outBufCapacity - (int)outCursor),
                                      (double)GH_U2F((unsigned int)(program[uVar19 * 2 + iVar9 * 2 + 1])),1e-07,in_f3
                                      ,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_fffffd08,
                                      in_stack_fffffd10,in_stack_fffffd18,in_stack_fffffd20,
                                      in_stack_fffffd28);
        goto switchD_97bee2f0_default;
      case 1:
        ch = 'S';
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10) = ch;
          iVar12 = iVar10 + 1;
          ch = "STENCIL_TEST func="[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
        switch(program[uVar19 * 2 + iVar9 * 2] >> 0xc & 7) {
        case 0:
          ch = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10 + iVar12) = ch;
            iVar13 = iVar10 + 1;
            ch = "PP_NEVER "[iVar10 + 1];
            iVar10 = iVar13;
          } while (ch != '\0');
          break;
        case 1:
          ch = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10 + iVar12) = ch;
            iVar13 = iVar10 + 1;
            ch = "PP_LESS "[iVar10 + 1];
            iVar10 = iVar13;
          } while (ch != '\0');
          break;
        case 2:
          ch = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10 + iVar12) = ch;
            iVar13 = iVar10 + 1;
            ch = "PP_EQUAL "[iVar10 + 1];
            iVar10 = iVar13;
          } while (ch != '\0');
          break;
        case 3:
          ch = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10 + iVar12) = ch;
            iVar13 = iVar10 + 1;
            ch = "PP_LEQUAL "[iVar10 + 1];
            iVar10 = iVar13;
          } while (ch != '\0');
          break;
        case 4:
          ch = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10 + iVar12) = ch;
            iVar13 = iVar10 + 1;
            ch = "PP_GREATER "[iVar10 + 1];
            iVar10 = iVar13;
          } while (ch != '\0');
          break;
        case 5:
          ch = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10 + iVar12) = ch;
            iVar13 = iVar10 + 1;
            ch = "PP_NOTEQUAL "[iVar10 + 1];
            iVar10 = iVar13;
          } while (ch != '\0');
          break;
        case 6:
          ch = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10 + iVar12) = ch;
            iVar13 = iVar10 + 1;
            ch = "PP_GEQUAL "[iVar10 + 1];
            iVar10 = iVar13;
          } while (ch != '\0');
          break;
        default:
          ch = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10 + iVar12) = ch;
            iVar13 = iVar10 + 1;
            ch = "PP_ALWAYS "[iVar10 + 1];
            iVar10 = iVar13;
          } while (ch != '\0');
        }
        ch = 'o';
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10 + iVar13 + iVar12) = ch;
          iVar14 = iVar10 + 1;
          ch = "opfail="[iVar10 + 1];
          iVar10 = iVar14;
        } while (ch != '\0');
        puVar18 = (undefined1 *)((int)outCursor + iVar14 + iVar13 + iVar12);
        switch(program[uVar19 * 2 + iVar9 * 2] >> 0xf & 7) {
        case 0:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_STENCIL_ZERO "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 1:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_STENCIL_KEEP "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 2:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_STENCIL_REPLACE "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 3:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_STENCIL_INCR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 4:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_STENCIL_DECR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 5:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_STENCIL_INVERT "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 6:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_STENCIL_INCR_WRAP "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 7:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_STENCIL_DECR_WRAP "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        default:
          goto switchD_97bee894_default;
        }
        puVar18 = puVar18 + iVar12;
switchD_97bee894_default:
        ch = 'o';
        iVar10 = 0;
        do {
          puVar18[iVar10] = ch;
          iVar12 = iVar10 + 1;
          ch = "opzfail="[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
        puVar18 = puVar18 + iVar12;
        switch(program[uVar19 * 2 + iVar9 * 2] >> 0x12 & 7) {
        case 0:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_STENCIL_ZERO "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 1:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_STENCIL_KEEP "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 2:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_STENCIL_REPLACE "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 3:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_STENCIL_INCR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 4:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_STENCIL_DECR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 5:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_STENCIL_INVERT "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 6:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_STENCIL_INCR_WRAP "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 7:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_STENCIL_DECR_WRAP "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        default:
          goto switchD_97beeaec_default;
        }
        puVar18 = puVar18 + iVar12;
switchD_97beeaec_default:
        ch = 'o';
        iVar10 = 0;
        do {
          puVar18[iVar10] = ch;
          iVar12 = iVar10 + 1;
          ch = "opzpass="[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
        outCursor = (int *)(puVar18 + iVar12);
        switch(program[uVar19 * 2 + iVar9 * 2] >> 0x15 & 7) {
        case 0:
          ch = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_STENCIL_ZERO "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 1:
          ch = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_STENCIL_KEEP "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 2:
          ch = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_STENCIL_REPLACE "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 3:
          ch = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_STENCIL_INCR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 4:
          ch = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_STENCIL_DECR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 5:
          ch = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_STENCIL_INVERT "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 6:
          ch = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_STENCIL_INCR_WRAP "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 7:
          ch = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_STENCIL_DECR_WRAP "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        default:
          goto switchD_97beed44_default;
        }
        outCursor = (int *)((int)outCursor + iVar12);
switchD_97beed44_default:
        _sprintf(&local_2b0,"ref= %#x mask = %#x ",program[uVar19 * 2 + iVar9 * 2 + 1] >> 0x18,
                 program[uVar19 * 2 + iVar9 * 2 + 1] >> 8 & 0xff);
        iVar10 = 0;
        ch = local_2b0;
        while (ch != '\0') {
          *(char *)((int)outCursor + iVar10) = ch;
          ch = acStack_2af[iVar10];
          iVar10 = iVar10 + 1;
        }
        break;
      case 2:
        ch = 'D';
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10) = ch;
          iVar12 = iVar10 + 1;
          ch = "DEPTH_TEST func="[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + iVar12);
        switch(program[uVar19 * 2 + iVar9 * 2] & 7) {
        case 0:
          ch = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)outCursor + iVar12) = ch;
            iVar10 = iVar12 + 1;
            ch = "PP_NEVER "[iVar12 + 1];
            iVar12 = iVar10;
          } while (ch != '\0');
          break;
        case 1:
          ch = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)outCursor + iVar12) = ch;
            iVar10 = iVar12 + 1;
            ch = "PP_LESS "[iVar12 + 1];
            iVar12 = iVar10;
          } while (ch != '\0');
          break;
        case 2:
          ch = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)outCursor + iVar12) = ch;
            iVar10 = iVar12 + 1;
            ch = "PP_EQUAL "[iVar12 + 1];
            iVar12 = iVar10;
          } while (ch != '\0');
          break;
        case 3:
          ch = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)outCursor + iVar12) = ch;
            iVar10 = iVar12 + 1;
            ch = "PP_LEQUAL "[iVar12 + 1];
            iVar12 = iVar10;
          } while (ch != '\0');
          break;
        case 4:
          ch = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)outCursor + iVar12) = ch;
            iVar10 = iVar12 + 1;
            ch = "PP_GREATER "[iVar12 + 1];
            iVar12 = iVar10;
          } while (ch != '\0');
          break;
        case 5:
          ch = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)outCursor + iVar12) = ch;
            iVar10 = iVar12 + 1;
            ch = "PP_NOTEQUAL "[iVar12 + 1];
            iVar12 = iVar10;
          } while (ch != '\0');
          break;
        case 6:
          ch = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)outCursor + iVar12) = ch;
            iVar10 = iVar12 + 1;
            ch = "PP_GEQUAL "[iVar12 + 1];
            iVar12 = iVar10;
          } while (ch != '\0');
          break;
        default:
          ch = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)outCursor + iVar12) = ch;
            iVar10 = iVar12 + 1;
            ch = "PP_ALWAYS "[iVar12 + 1];
            iVar12 = iVar10;
          } while (ch != '\0');
        }
        break;
      case 3:
        ch = 'B';
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10) = ch;
          iVar12 = iVar10 + 1;
          ch = "BLENDING \n\talpha equ = "[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
        puVar18 = (undefined1 *)((int)outCursor + iVar12);
        switch(program[uVar19 * 2 + iVar9 * 2] >> 0x13 & 7) {
        case 0:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_FUNC_ADD "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 1:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_FUNC_SUBTRACT "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 2:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_FUNC_REVERSE_SUBTRACT "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 3:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_FUNC_MIN "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 4:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_FUNC_MAX "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        default:
          goto switchD_97bef244_default;
        }
        puVar18 = puVar18 + iVar12;
switchD_97bef244_default:
        ch = '\n';
        iVar10 = 0;
        do {
          puVar18[iVar10] = ch;
          iVar12 = iVar10 + 1;
          ch = "\n\trgb equ = "[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
        puVar18 = puVar18 + iVar12;
        switch(program[uVar19 * 2 + iVar9 * 2] >> 0x10 & 7) {
        case 0:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_FUNC_ADD "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 1:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_FUNC_SUBTRACT "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 2:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_FUNC_REVERSE_SUBTRACT "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 3:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_FUNC_MIN "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 4:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_FUNC_MAX "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        default:
          goto switchD_97bef3e8_default;
        }
        puVar18 = puVar18 + iVar12;
switchD_97bef3e8_default:
        ch = '\n';
        iVar10 = 0;
        do {
          puVar18[iVar10] = ch;
          iVar12 = iVar10 + 1;
          ch = "\n\tsrc = "[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
        puVar18 = puVar18 + iVar12;
        switch(program[uVar19 * 2 + iVar9 * 2] & 0xf) {
        case 0:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_ZERO "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 1:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_ONE "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 2:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_SRC_COLOR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 3:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_ONE_MINUS_SRC_COLOR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 4:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_SRC_ALPHA "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 5:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_ONE_MINUS_SRC_ALPHA "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 6:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_DST_ALPHA "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 7:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_ONE_MINUS_DST_ALPHA "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 8:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_CONSTANT_COLOR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 9:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_ONE_MINUS_CONSTANT_COLOR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 10:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_CONSTANT_ALPHA "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 0xb:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_ONE_MINUS_CONSTANT_ALPHA "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 0xc:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_DST_COLOR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 0xd:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_ONE_MINUS_DST_COLOR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 0xe:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_SRC_ALPHA_SATURATE "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        default:
          goto switchD_97bef58c_default;
        }
        puVar18 = puVar18 + iVar12;
switchD_97bef58c_default:
        ch = '\n';
        iVar10 = 0;
        do {
          puVar18[iVar10] = ch;
          iVar12 = iVar10 + 1;
          ch = "\n\tsrcA = "[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
        puVar18 = puVar18 + iVar12;
        switch(program[uVar19 * 2 + iVar9 * 2] >> 4 & 0xf) {
        case 0:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_ZERO "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 1:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_ONE "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 2:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_SRC_COLOR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 3:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_ONE_MINUS_SRC_COLOR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 4:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_SRC_ALPHA "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 5:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_ONE_MINUS_SRC_ALPHA "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 6:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_DST_ALPHA "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 7:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_ONE_MINUS_DST_ALPHA "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 8:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_CONSTANT_COLOR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 9:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_ONE_MINUS_CONSTANT_COLOR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 10:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_CONSTANT_ALPHA "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 0xb:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_ONE_MINUS_CONSTANT_ALPHA "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 0xc:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_DST_COLOR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 0xd:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_ONE_MINUS_DST_COLOR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 0xe:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_SRC_ALPHA_SATURATE "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        default:
          goto switchD_97bef988_default;
        }
        puVar18 = puVar18 + iVar12;
switchD_97bef988_default:
        ch = '\n';
        iVar10 = 0;
        do {
          puVar18[iVar10] = ch;
          iVar12 = iVar10 + 1;
          ch = "\n\tdst = "[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
        puVar18 = puVar18 + iVar12;
        switch(program[uVar19 * 2 + iVar9 * 2] >> 8 & 0xf) {
        case 0:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_ZERO "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 1:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_ONE "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 2:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_SRC_COLOR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 3:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_ONE_MINUS_SRC_COLOR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 4:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_SRC_ALPHA "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 5:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_ONE_MINUS_SRC_ALPHA "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 6:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_DST_ALPHA "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 7:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_ONE_MINUS_DST_ALPHA "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 8:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_CONSTANT_COLOR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 9:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_ONE_MINUS_CONSTANT_COLOR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 10:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_CONSTANT_ALPHA "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 0xb:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_ONE_MINUS_CONSTANT_ALPHA "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 0xc:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_DST_COLOR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 0xd:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_ONE_MINUS_DST_COLOR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        case 0xe:
          ch = 'P';
          iVar10 = 0;
          do {
            puVar18[iVar10] = ch;
            iVar12 = iVar10 + 1;
            ch = "PP_BLEND_SRC_ALPHA_SATURATE "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          break;
        default:
          goto switchD_97befd84_default;
        }
        puVar18 = puVar18 + iVar12;
switchD_97befd84_default:
        ch = '\n';
        iVar10 = 0;
        do {
          puVar18[iVar10] = ch;
          iVar12 = iVar10 + 1;
          ch = "\n\tdstA = "[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
        outCursor = (int *)(puVar18 + iVar12);
        switch(program[uVar19 * 2 + iVar9 * 2] >> 0xc & 0xf) {
        case 0:
          ch = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)outCursor + iVar12) = ch;
            iVar10 = iVar12 + 1;
            ch = "PP_BLEND_ZERO "[iVar12 + 1];
            iVar12 = iVar10;
          } while (ch != '\0');
          break;
        case 1:
          ch = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)outCursor + iVar12) = ch;
            iVar10 = iVar12 + 1;
            ch = "PP_BLEND_ONE "[iVar12 + 1];
            iVar12 = iVar10;
          } while (ch != '\0');
          break;
        case 2:
          ch = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)outCursor + iVar12) = ch;
            iVar10 = iVar12 + 1;
            ch = "PP_BLEND_SRC_COLOR "[iVar12 + 1];
            iVar12 = iVar10;
          } while (ch != '\0');
          break;
        case 3:
          ch = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)outCursor + iVar12) = ch;
            iVar10 = iVar12 + 1;
            ch = "PP_BLEND_ONE_MINUS_SRC_COLOR "[iVar12 + 1];
            iVar12 = iVar10;
          } while (ch != '\0');
          break;
        case 4:
          ch = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)outCursor + iVar12) = ch;
            iVar10 = iVar12 + 1;
            ch = "PP_BLEND_SRC_ALPHA "[iVar12 + 1];
            iVar12 = iVar10;
          } while (ch != '\0');
          break;
        case 5:
          ch = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)outCursor + iVar12) = ch;
            iVar10 = iVar12 + 1;
            ch = "PP_BLEND_ONE_MINUS_SRC_ALPHA "[iVar12 + 1];
            iVar12 = iVar10;
          } while (ch != '\0');
          break;
        case 6:
          ch = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)outCursor + iVar12) = ch;
            iVar10 = iVar12 + 1;
            ch = "PP_BLEND_DST_ALPHA "[iVar12 + 1];
            iVar12 = iVar10;
          } while (ch != '\0');
          break;
        case 7:
          ch = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)outCursor + iVar12) = ch;
            iVar10 = iVar12 + 1;
            ch = "PP_BLEND_ONE_MINUS_DST_ALPHA "[iVar12 + 1];
            iVar12 = iVar10;
          } while (ch != '\0');
          break;
        case 8:
          ch = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)outCursor + iVar12) = ch;
            iVar10 = iVar12 + 1;
            ch = "PP_BLEND_CONSTANT_COLOR "[iVar12 + 1];
            iVar12 = iVar10;
          } while (ch != '\0');
          break;
        case 9:
          ch = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)outCursor + iVar12) = ch;
            iVar10 = iVar12 + 1;
            ch = "PP_BLEND_ONE_MINUS_CONSTANT_COLOR "[iVar12 + 1];
            iVar12 = iVar10;
          } while (ch != '\0');
          break;
        case 10:
          ch = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)outCursor + iVar12) = ch;
            iVar10 = iVar12 + 1;
            ch = "PP_BLEND_CONSTANT_ALPHA "[iVar12 + 1];
            iVar12 = iVar10;
          } while (ch != '\0');
          break;
        case 0xb:
          ch = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)outCursor + iVar12) = ch;
            iVar10 = iVar12 + 1;
            ch = "PP_BLEND_ONE_MINUS_CONSTANT_ALPHA "[iVar12 + 1];
            iVar12 = iVar10;
          } while (ch != '\0');
          break;
        case 0xc:
          ch = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)outCursor + iVar12) = ch;
            iVar10 = iVar12 + 1;
            ch = "PP_BLEND_DST_COLOR "[iVar12 + 1];
            iVar12 = iVar10;
          } while (ch != '\0');
          break;
        case 0xd:
          ch = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)outCursor + iVar12) = ch;
            iVar10 = iVar12 + 1;
            ch = "PP_BLEND_ONE_MINUS_DST_COLOR "[iVar12 + 1];
            iVar12 = iVar10;
          } while (ch != '\0');
          break;
        case 0xe:
          ch = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)outCursor + iVar12) = ch;
            iVar10 = iVar12 + 1;
            ch = "PP_BLEND_SRC_ALPHA_SATURATE "[iVar12 + 1];
            iVar12 = iVar10;
          } while (ch != '\0');
          break;
        default:
          goto switchD_97bee2f0_default;
        }
        break;
      case 4:
        ch = 'D';
        iVar12 = 0;
        do {
          *(char *)((int)outCursor + iVar12) = ch;
          iVar10 = iVar12 + 1;
          ch = "DITHERING ENABLED"[iVar12 + 1];
          iVar12 = iVar10;
        } while (ch != '\0');
        break;
      case 5:
        ch = 'L';
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10) = ch;
          iVar12 = iVar10 + 1;
          ch = "LOGIC_OP "[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + iVar12);
        switch(program[uVar19 * 2 + iVar9 * 2] & 0xf) {
        case 0:
          ch = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)outCursor + iVar12) = ch;
            iVar10 = iVar12 + 1;
            ch = "PP_LOGIC_CLEAR"[iVar12 + 1];
            iVar12 = iVar10;
          } while (ch != '\0');
          break;
        case 1:
          ch = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)outCursor + iVar12) = ch;
            iVar10 = iVar12 + 1;
            ch = "PP_LOGIC_SET"[iVar12 + 1];
            iVar12 = iVar10;
          } while (ch != '\0');
          break;
        case 2:
          ch = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)outCursor + iVar12) = ch;
            iVar10 = iVar12 + 1;
            ch = "PP_LOGIC_COPY"[iVar12 + 1];
            iVar12 = iVar10;
          } while (ch != '\0');
          break;
        case 3:
          ch = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)outCursor + iVar12) = ch;
            iVar10 = iVar12 + 1;
            ch = "PP_LOGIC_COPY_INVERTED"[iVar12 + 1];
            iVar12 = iVar10;
          } while (ch != '\0');
          break;
        case 4:
          ch = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)outCursor + iVar12) = ch;
            iVar10 = iVar12 + 1;
            ch = "PP_LOGIC_NOOP"[iVar12 + 1];
            iVar12 = iVar10;
          } while (ch != '\0');
          break;
        case 5:
          ch = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)outCursor + iVar12) = ch;
            iVar10 = iVar12 + 1;
            ch = "PP_LOGIC_INVERT"[iVar12 + 1];
            iVar12 = iVar10;
          } while (ch != '\0');
          break;
        case 6:
          ch = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)outCursor + iVar12) = ch;
            iVar10 = iVar12 + 1;
            ch = "PP_LOGIC_AND"[iVar12 + 1];
            iVar12 = iVar10;
          } while (ch != '\0');
          break;
        case 7:
          ch = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)outCursor + iVar12) = ch;
            iVar10 = iVar12 + 1;
            ch = "PP_LOGIC_NAND"[iVar12 + 1];
            iVar12 = iVar10;
          } while (ch != '\0');
          break;
        case 8:
          ch = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)outCursor + iVar12) = ch;
            iVar10 = iVar12 + 1;
            ch = "PP_LOGIC_OR"[iVar12 + 1];
            iVar12 = iVar10;
          } while (ch != '\0');
          break;
        case 9:
          ch = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)outCursor + iVar12) = ch;
            iVar10 = iVar12 + 1;
            ch = "PP_LOGIC_NOR"[iVar12 + 1];
            iVar12 = iVar10;
          } while (ch != '\0');
          break;
        case 10:
          ch = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)outCursor + iVar12) = ch;
            iVar10 = iVar12 + 1;
            ch = "PP_LOGIC_XOR"[iVar12 + 1];
            iVar12 = iVar10;
          } while (ch != '\0');
          break;
        case 0xb:
          ch = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)outCursor + iVar12) = ch;
            iVar10 = iVar12 + 1;
            ch = "PP_LOGIC_EQUIV"[iVar12 + 1];
            iVar12 = iVar10;
          } while (ch != '\0');
          break;
        case 0xc:
          ch = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)outCursor + iVar12) = ch;
            iVar10 = iVar12 + 1;
            ch = "PP_LOGIC_AND_REVERSE"[iVar12 + 1];
            iVar12 = iVar10;
          } while (ch != '\0');
          break;
        case 0xd:
          ch = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)outCursor + iVar12) = ch;
            iVar10 = iVar12 + 1;
            ch = "PP_LOGIC_AND_INVERTED"[iVar12 + 1];
            iVar12 = iVar10;
          } while (ch != '\0');
          break;
        case 0xe:
          ch = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)outCursor + iVar12) = ch;
            iVar10 = iVar12 + 1;
            ch = "PP_LOGIC_OR_REVERSE"[iVar12 + 1];
            iVar12 = iVar10;
          } while (ch != '\0');
          break;
        case 0xf:
          ch = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)outCursor + iVar12) = ch;
            iVar10 = iVar12 + 1;
            ch = "PP_LOGIC_OR_INVERTED"[iVar12 + 1];
            iVar12 = iVar10;
          } while (ch != '\0');
          break;
        default:
          goto switchD_97bee2f0_default;
        }
        break;
      case 6:
        ch = 'B';
        iVar10 = 0;
        do {
          *(char *)((int)outCursor + iVar10) = ch;
          iVar12 = iVar10 + 1;
          ch = "BUFFER_MASK "[iVar10 + 1];
          iVar10 = iVar12;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + iVar12);
        if ((program[uVar19 * 2 + iVar9 * 2] & 0x20000) == 0) {
          ch = 'R';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "RED MASKED "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + iVar12);
        }
        if ((program[uVar19 * 2 + iVar9 * 2] & 0x40000) == 0) {
          ch = 'G';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "GREEN MASKED "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + iVar12);
        }
        if ((program[uVar19 * 2 + iVar9 * 2] & 0x80000) == 0) {
          ch = 'B';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "BLUE MASKED "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + iVar12);
        }
        if ((program[uVar19 * 2 + iVar9 * 2] & 0x100000) == 0) {
          ch = 'A';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "ALPHA MASKED "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + iVar12);
        }
        if ((program[uVar19 * 2 + iVar9 * 2] & 0x10000) == 0) {
          ch = 'D';
          iVar10 = 0;
          do {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar12 = iVar10 + 1;
            ch = "DEPTH MASKED "[iVar10 + 1];
            iVar10 = iVar12;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + iVar12);
        }
        if (*(char *)((int)program + iVar9 * 8 + uVar19 * 8 + 2) != -1) {
          _sprintf(local_1b0,"STENCIL MASK = %0x",program[uVar19 * 2 + iVar9 * 2] >> 8 & 0xff);
          iVar10 = 0;
          ch = local_1b0[0];
          while (ch != '\0') {
            *(char *)((int)outCursor + iVar10) = ch;
            iVar10 = iVar10 + 1;
            ch = local_1b0[iVar10];
          }
          break;
        }
      default:
        goto switchD_97bee2f0_default;
      }
      outCursor = (int *)((int)outCursor + iVar10);
switchD_97bee2f0_default:
      iVar10 = 0;
      ch = local_60[0x3bbc];
      while (ch != '\0') {
        *(char *)((int)outCursor + iVar10) = ch;
        iVar10 = iVar10 + 1;
        ch = (local_60 + 0x3bbc)[iVar10];
      }
      outCursor = (int *)((int)outCursor + iVar10);
      uVar26 = ((int (*)())_adjustAllocation_97be9cb4)(&outBufCapacity,&outBuf,&outCursor);
      if ((int)((ulonglong)uVar26 >> 0x20) == 0) goto joined_r0x97beb668;
      iVar22 = iVar22 + 1;
      iVar9 = iVar9 + 1;
    } while (iVar22 < (int)uVar6);
  }
  piVar15 = (int *)((int)outCursor + 1);
  *(undefined1 *)outCursor = 0;
  outCursor = piVar15;
  if (!bVar3) {
    _free(local_88);
    _free(local_84);
  }
  if (!(bool)((byte)((uint)local_5c >> 0x1d) & 1)) {
    _free(local_80);
  }
  if (!(bool)((byte)((uint)local_58 >> 0x1d) & 1)) {
    _free(local_7c);
  }
  if (0 < (int)outCursor - (int)outBuf) {
    pvVar17 = (void *)_realloc(outBuf,(int)outCursor - (int)outBuf);
    return pvVar17;
  }
  _free(outBuf);
  return (void *)0x0;
}

/* _handleDigit_97bf0d2c @ 0x97bf0d2c (112 bytes) */
int _handleDigit_97bf0d2c(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = param_2 / 10;
  if (iVar1 != 0) {
    ((int (*)())_handleDigit_97bf0d2c)(param_1,iVar1);
  }
  *(char *)*param_1 = (char)param_2 + (char)iVar1 * -10 + '0';
  *param_1 = *param_1 + 1;
  return;
}

/* _PPStreamChunkCreateWithType @ 0x97bf0d9c (116 bytes) */
int _PPStreamChunkCreateWithType(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = _GetChunkAllocationSize(param_1,param_2);
  puVar2 = (undefined1 *)_calloc(iVar1 + 0xc,1);
  _memset(puVar2,0,iVar1 + 0xc);
  *puVar2 = (char)param_1;
  if (param_1 == 8) {
    *(undefined4 *)(puVar2 + 0x40) = param_2;
  }
  else if (param_1 == 0xb) {
    *(undefined4 *)(puVar2 + 0x10) = param_2;
  }
  return puVar2;
}

/* _PPStreamChunkCompare @ 0x97bf0e10 (212 bytes) */
int _PPStreamChunkCompare(stream, param_2)
  char *stream;
  char *param_2;
{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = 1;
  if (*param_2 == *stream) {
    switch(*param_2) {
    case '\0':
    case '\x03':
    case '\n':
      uVar3 = 0x10;
      break;
    case '\x01':
      uVar3 = 4;
      break;
    case '\x02':
    case '\x04':
    case '\x05':
    case '\x06':
    case '\a':
    case '\t':
      uVar3 = 8;
      break;
    case '\b':
      uVar3 = 0x38;
      uVar1 = *(undefined4 *)(stream + 0x40);
      *(undefined4 *)(param_2 + 0x3c) = *(undefined4 *)(stream + 0x3c);
      *(undefined4 *)(param_2 + 0x40) = uVar1;
      break;
    default:
      return 1;
    }
    iVar2 = _memcmp(stream + 0xc,param_2 + 0xc,uVar3);
    uVar1 = 1;
    if (iVar2 == 0) {
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* _PPStreamChunkListInsertChunkBeforeChunk @ 0x97bf0f14 (84 bytes) */
int _PPStreamChunkListInsertChunkBeforeChunk(stream, param_2, param_3)
  int *stream;
  int param_2;
  int param_3;
{
  undefined4 uVar1;
  
  if (param_3 == 0) {
    _PPStreamChunkListAddChunk(stream,param_2);
    return;
  }
  uVar1 = *(undefined4 *)(param_3 + 4);
  *(int *)(param_2 + 8) = param_3;
  *(undefined4 *)(param_2 + 4) = uVar1;
  if (*(int *)(param_3 + 4) != 0) {
    *(int *)(*(int *)(param_3 + 4) + 8) = param_2;
  }
  *(int *)(param_3 + 4) = param_2;
  if (*stream == param_3) {
    *stream = param_2;
  }
  stream[2] = stream[2] + 1;
  return;
}

/* _PPStreamChunkListInsertChunkAfterChunk @ 0x97bf0f68 (116 bytes) */
int _PPStreamChunkListInsertChunkAfterChunk(stream, param_2, param_3)
  int *stream;
  int param_2;
  int param_3;
{
  undefined4 uVar1;
  
  if (param_3 == 0) {
    *(undefined4 *)(param_2 + 4) = 0;
    if (*stream == 0) {
      *(undefined4 *)(param_2 + 8) = 0;
    }
    else {
      *(int *)(param_2 + 8) = *stream;
      *(int *)(*stream + 4) = param_2;
    }
    *stream = param_2;
  }
  else {
    uVar1 = *(undefined4 *)(param_3 + 8);
    *(int *)(param_2 + 4) = param_3;
    *(undefined4 *)(param_2 + 8) = uVar1;
    if (*(int *)(param_3 + 8) != 0) {
      *(int *)(*(int *)(param_3 + 8) + 4) = param_2;
    }
    *(int *)(param_3 + 8) = param_2;
    if (stream[1] == param_3) {
      stream[1] = param_2;
    }
  }
  stream[2] = stream[2] + 1;
  return;
}

/* _PPStreamChunkListRemoveChunkNoFree @ 0x97bf0fdc (88 bytes) */
int _PPStreamChunkListRemoveChunkNoFree(stream, param_2)
  undefined4 *stream;
  int param_2;
{
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
  *(undefined4 *)(param_2 + 8) = 0;
  *(undefined4 *)(param_2 + 4) = 0;
  stream[2] = stream[2] + -1;
  return;
}

/* _PPStreamChunkListCompare @ 0x97bf1034 (132 bytes) */
int _PPStreamChunkListCompare(stream, param_2)
  int *stream;
  int *param_2;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *stream;
  uVar1 = 1;
  iVar4 = *param_2;
  if (stream[2] == param_2[2]) {
    for (; (iVar3 != 0 && (iVar4 != 0)); iVar4 = *(int *)(iVar4 + 8)) {
      iVar2 = ((int (*)())_PPStreamChunkCompare)(iVar3,iVar4);
      if (iVar2 != 0) {
        return 1;
      }
      iVar3 = *(int *)(iVar3 + 8);
    }
    uVar1 = 0;
  }
  return uVar1;
}

/* _PPStreamDuplicate @ 0x97bf10b8 (636 bytes) */
int _PPStreamDuplicate(stream)
  undefined4 *stream;
{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  puVar2 = (undefined4 *)_PPStreamCreate();
  piVar1 = (int *)stream[1];
  *puVar2 = *stream;
  for (iVar4 = *piVar1; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar3 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar2[1],uVar3);
  }
  for (iVar4 = *(int *)stream[2]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar3 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar2[2],uVar3);
  }
  for (iVar4 = *(int *)stream[3]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar3 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar2[3],uVar3);
  }
  for (iVar4 = *(int *)stream[4]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar3 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar2[4],uVar3);
  }
  for (iVar4 = *(int *)stream[5]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar3 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar2[5],uVar3);
  }
  for (iVar4 = *(int *)stream[6]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar3 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar2[6],uVar3);
  }
  for (iVar4 = *(int *)stream[7]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar3 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar2[7],uVar3);
  }
  for (iVar4 = *(int *)stream[8]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar3 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar2[8],uVar3);
  }
  for (iVar4 = *(int *)stream[9]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar3 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar2[9],uVar3);
  }
  for (iVar4 = *(int *)stream[0xb]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar3 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar2[0xb],uVar3);
  }
  for (iVar4 = *(int *)stream[10]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar3 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar2[10],uVar3);
  }
  for (iVar4 = *(int *)stream[0xc]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar3 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar2[0xc],uVar3);
  }
  return puVar2;
}

/* _PPStreamAddTempUsageArray @ 0x97bf1334 (92 bytes) */
int _PPStreamAddTempUsageArray(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined1 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  puVar1 = (undefined1 *)_calloc(0x14,1);
  uVar4 = param_2[1];
  uVar2 = *(undefined4 *)(param_1 + 8);
  uVar3 = *param_2;
  *puVar1 = 6;
  *(undefined4 *)(puVar1 + 0xc) = uVar3;
  *(undefined4 *)(puVar1 + 0x10) = uVar4;
  return _PPStreamChunkListAddChunk(uVar2,puVar1);
}

/* _PPStreamAddAddressUsage @ 0x97bf1390 (84 bytes) */
int _PPStreamAddAddressUsage(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined1 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  puVar1 = (undefined1 *)_calloc(0x10,1);
  uVar3 = *param_2;
  uVar2 = *(undefined4 *)(param_1 + 0xc);
  *puVar1 = 1;
  *(undefined4 *)(puVar1 + 0xc) = uVar3;
  return _PPStreamChunkListAddChunk(uVar2,puVar1);
}

/* _PPStreamAddParamBindingArray @ 0x97bf13e4 (92 bytes) */
int _PPStreamAddParamBindingArray(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined1 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  puVar1 = (undefined1 *)_calloc(0x14,1);
  uVar4 = param_2[1];
  uVar2 = *(undefined4 *)(param_1 + 0x14);
  uVar3 = *param_2;
  *puVar1 = 5;
  *(undefined4 *)(puVar1 + 0xc) = uVar3;
  *(undefined4 *)(puVar1 + 0x10) = uVar4;
  return _PPStreamChunkListAddChunk(uVar2,puVar1);
}

/* _PPStreamInsertOperationBeforeChunk @ 0x97bf1440 (288 bytes) */
int _PPStreamInsertOperationBeforeChunk(stream, param_2, param_3, param_4, param_5)
  int stream;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_2 + 0x34);
  iVar3 = 0x38;
  if (iVar5 != 0) {
    iVar3 = iVar5 + 0x39;
  }
  puVar4 = (undefined1 *)_calloc(iVar3 + 0xc,1);
  *puVar4 = 8;
  _memcpy(puVar4 + 0xc,param_2,0x38);
  if ((iVar5 != 0) && (param_3 != 0)) {
    _memmove(puVar4 + 0x44,param_3,iVar5);
    puVar4[iVar5 + 0x44] = 0;
  }
  if (param_4 == 0) {
    iVar3 = _PPStreamChunkListGetMaxIndex(*(undefined4 *)(stream + 0x20));
    uVar1 = iVar3 + 1U & 0x3ffff | *(uint *)(puVar4 + 0xc) & 0xfffc0000;
  }
  else {
    uVar1 = *(uint *)(puVar4 + 0xc) & 0xfffc0000;
  }
  *(uint *)(puVar4 + 0xc) = uVar1;
  if (param_5 != 0) {
    uVar1 = *(uint *)(param_5 + 0xc);
    uVar2 = *(uint *)(puVar4 + 0xc);
    *(uint *)(param_5 + 0xc) =
         uVar2 & 0x3ffff | (uVar2 & 0xe3ffffff) >> 3 & 0x1c000000 | uVar1 & 0xe3fc0000;
    *(uint *)(puVar4 + 0xc) = uVar1 & 0x3ffff | (uVar1 >> 0x1a & 7) << 0x1a | uVar2 & 0xe3fc0000;
  }
  ((int (*)())_PPStreamChunkListInsertChunkBeforeChunk)(*(undefined4 *)(stream + 0x20),puVar4,param_5);
  return puVar4;
}

/* _PPStreamInsertOperationAfterChunk @ 0x97bf1560 (236 bytes) */
int _PPStreamInsertOperationAfterChunk(stream, param_2, param_3, param_4, param_5)
  int stream;
  int param_2;
  int param_3;
  int param_4;
  undefined4 param_5;
{
  uint uVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_2 + 0x34);
  iVar2 = 0x38;
  if (iVar4 != 0) {
    iVar2 = iVar4 + 0x39;
  }
  puVar3 = (undefined1 *)_calloc(iVar2 + 0xc,1);
  *puVar3 = 8;
  _memcpy(puVar3 + 0xc,param_2,0x38);
  if ((iVar4 != 0) && (param_3 != 0)) {
    _memmove(puVar3 + 0x44,param_3,iVar4);
    puVar3[iVar4 + 0x44] = 0;
  }
  if (param_4 == 0) {
    iVar2 = _PPStreamChunkListGetMaxIndex(*(undefined4 *)(stream + 0x20));
    uVar1 = iVar2 + 1U & 0x3ffff | *(uint *)(puVar3 + 0xc) & 0xfffc0000;
  }
  else {
    uVar1 = *(uint *)(puVar3 + 0xc) & 0xfffc0000;
  }
  *(uint *)(puVar3 + 0xc) = uVar1;
  ((int (*)())_PPStreamChunkListInsertChunkAfterChunk)(*(undefined4 *)(stream + 0x20),puVar3,param_5);
  return puVar3;
}

/* _PPStreamAddLabel @ 0x97bf164c (128 bytes) */
int _PPStreamAddLabel(stream, param_2, param_3)
  int stream;
  undefined4 param_2;
  int param_3;
{
  undefined1 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  puVar1 = (undefined1 *)_calloc(param_3 + 0x15,1);
  uVar2 = *(undefined4 *)(stream + 0x20);
  *puVar1 = 0xb;
  *(int *)(puVar1 + 0x10) = param_3;
  iVar3 = _PPStreamChunkListGetMaxIndex(uVar2);
  *(int *)(puVar1 + 0xc) = iVar3 + 1;
  _memmove(puVar1 + 0x14,param_2,param_3);
  uVar2 = *(undefined4 *)(stream + 0x24);
  puVar1[param_3 + 0x14] = 0;
  return _PPStreamChunkListAddChunk(uVar2,puVar1);
}

/* _PPStreamRemoveLabelsAtOperationIndex @ 0x97bf16cc (96 bytes) */
int _PPStreamRemoveLabelsAtOperationIndex(stream, param_2)
  int stream;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = **(int **)(stream + 0x24);
  while (iVar1 = iVar2, iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 8);
    if (*(int *)(iVar1 + 0xc) == param_2) {
      _PPStreamChunkListRemoveChunk(*(undefined4 *)(stream + 0x24),iVar1);
    }
  }
  return;
}

/* _PPStreamAddRasterOp @ 0x97bf172c (92 bytes) */
int _PPStreamAddRasterOp(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined1 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  puVar1 = (undefined1 *)_calloc(0x14,1);
  uVar4 = param_2[1];
  uVar2 = *(undefined4 *)(param_1 + 0x28);
  uVar3 = *param_2;
  *puVar1 = 9;
  *(undefined4 *)(puVar1 + 0xc) = uVar3;
  *(undefined4 *)(puVar1 + 0x10) = uVar4;
  return _PPStreamChunkListAddChunk(uVar2,puVar1);
}

/* _PPStreamAttachStream @ 0x97bf1788 (1212 bytes) */
int _PPStreamAttachStream(stream, param_2)
  undefined4 *stream;
  undefined4 *param_2;
{
  uint *puVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  uint uVar7;
  uint *puVar8;
  undefined4 *puVar9;
  uint uVar10;
  
  uVar7 = 0;
  *stream = *param_2;
  if (param_2[6] != 0) {
    do {
      puVar5 = (undefined1 *)_calloc(0x10,1);
      *(uint *)(puVar5 + 0xc) = uVar7;
      *puVar5 = 1;
      uVar7 = uVar7 + 1;
      _PPStreamChunkListAddChunk(stream[3],puVar5);
    } while (uVar7 < (uint)param_2[6]);
  }
  uVar7 = 0;
  puVar9 = param_2 + param_2[5] * 2;
  if (param_2[4] != 0) {
    do {
      puVar5 = (undefined1 *)_calloc(0x1c,1);
      uVar7 = uVar7 + 1;
      *puVar5 = 0;
      uVar3 = puVar9[1];
      *(undefined4 *)(puVar5 + 0xc) = *puVar9;
      *(undefined4 *)(puVar5 + 0x10) = uVar3;
      _PPStreamChunkListAddChunk(stream[1],puVar5);
      puVar9 = puVar9 + 2;
    } while (uVar7 < (uint)param_2[4]);
  }
  uVar7 = 0;
  puVar9 = param_2 + param_2[9] * 2;
  if (param_2[8] != 0) {
    do {
      puVar5 = (undefined1 *)_calloc(0x14,1);
      uVar7 = uVar7 + 1;
      *puVar5 = 2;
      uVar3 = puVar9[1];
      *(undefined4 *)(puVar5 + 0xc) = *puVar9;
      *(undefined4 *)(puVar5 + 0x10) = uVar3;
      _PPStreamChunkListAddChunk(stream[6],puVar5);
      puVar9 = puVar9 + 2;
    } while (uVar7 < (uint)param_2[8]);
  }
  uVar7 = 0;
  puVar9 = param_2 + param_2[0xb] * 2;
  if (param_2[10] != 0) {
    do {
      puVar5 = (undefined1 *)_calloc(0x1c,1);
      uVar7 = uVar7 + 1;
      *puVar5 = 3;
      uVar3 = puVar9[1];
      *(undefined4 *)(puVar5 + 0xc) = *puVar9;
      *(undefined4 *)(puVar5 + 0x10) = uVar3;
      _PPStreamChunkListAddChunk(stream[4],puVar5);
      puVar9 = puVar9 + 2;
    } while (uVar7 < (uint)param_2[10]);
  }
  uVar7 = 0;
  puVar9 = param_2 + param_2[0xd] * 2;
  if (param_2[0xc] != 0) {
    do {
      puVar5 = (undefined1 *)_calloc(0x14,1);
      uVar7 = uVar7 + 1;
      *puVar5 = 4;
      uVar3 = puVar9[1];
      *(undefined4 *)(puVar5 + 0xc) = *puVar9;
      *(undefined4 *)(puVar5 + 0x10) = uVar3;
      _PPStreamChunkListAddChunk(stream[7],puVar5);
      puVar9 = puVar9 + 2;
    } while (uVar7 < (uint)param_2[0xc]);
  }
  uVar7 = 0;
  puVar9 = param_2 + param_2[0xf] * 2;
  if (param_2[0xe] != 0) {
    do {
      puVar5 = (undefined1 *)_calloc(0x14,1);
      uVar7 = uVar7 + 1;
      *puVar5 = 5;
      uVar3 = puVar9[1];
      *(undefined4 *)(puVar5 + 0xc) = *puVar9;
      *(undefined4 *)(puVar5 + 0x10) = uVar3;
      _PPStreamChunkListAddChunk(stream[5],puVar5);
      puVar9 = puVar9 + 2;
    } while (uVar7 < (uint)param_2[0xe]);
  }
  uVar7 = 0;
  puVar9 = param_2 + param_2[0x11] * 2;
  if (param_2[0x10] != 0) {
    do {
      puVar5 = (undefined1 *)_calloc(0x14,1);
      uVar7 = uVar7 + 1;
      *puVar5 = 6;
      uVar3 = puVar9[1];
      *(undefined4 *)(puVar5 + 0xc) = *puVar9;
      *(undefined4 *)(puVar5 + 0x10) = uVar3;
      _PPStreamChunkListAddChunk(stream[2],puVar5);
      puVar9 = puVar9 + 2;
    } while (uVar7 < (uint)param_2[0x10]);
  }
  uVar7 = 0;
  puVar9 = param_2 + param_2[0x13] * 2;
  if (param_2[0x12] != 0) {
    do {
      puVar5 = (undefined1 *)_calloc(0x14,1);
      uVar7 = uVar7 + 1;
      *puVar5 = 7;
      uVar3 = puVar9[1];
      *(undefined4 *)(puVar5 + 0xc) = *puVar9;
      *(undefined4 *)(puVar5 + 0x10) = uVar3;
      _PPStreamChunkListAddChunk(stream[0xc],puVar5);
      puVar9 = puVar9 + 2;
    } while (uVar7 < (uint)param_2[0x12]);
  }
  uVar7 = 0;
  puVar8 = param_2 + param_2[0x15] * 2;
  if (param_2[0x14] != 0) {
    do {
      puVar5 = (undefined1 *)_calloc(0x44,1);
      *puVar5 = 8;
      *(undefined4 *)(puVar5 + 0x40) = 0;
      uVar2 = puVar8[1];
      uVar10 = *puVar8 >> 0x1d;
      *(uint *)(puVar5 + 0xc) = *puVar8;
      *(uint *)(puVar5 + 0x10) = uVar2;
      puVar1 = puVar8 + 2;
      uVar2 = puVar8[3];
      puVar8 = puVar8 + 4;
      *(uint *)(puVar5 + 0x14) = *puVar1;
      *(uint *)(puVar5 + 0x18) = uVar2;
      if (uVar10 != 0) {
        puVar6 = puVar5 + 0x10;
        do {
          uVar2 = *puVar8;
          uVar4 = puVar8[1];
          puVar8 = puVar8 + 2;
          *(uint *)(puVar6 + 0xc) = uVar2;
          *(uint *)(puVar6 + 0x10) = uVar4;
          puVar6 = puVar6 + 8;
          uVar10 = uVar10 - 1;
        } while (uVar10 != 0);
      }
      uVar7 = uVar7 + 1;
      _PPStreamChunkListAddChunk(stream[8],puVar5);
    } while (uVar7 < (uint)param_2[0x14]);
  }
  uVar7 = 0;
  puVar9 = param_2 + param_2[0x19] * 2;
  if (param_2[0x18] != 0) {
    do {
      puVar5 = (undefined1 *)_calloc(0x14,1);
      uVar7 = uVar7 + 1;
      *puVar5 = 9;
      uVar3 = puVar9[1];
      *(undefined4 *)(puVar5 + 0xc) = *puVar9;
      *(undefined4 *)(puVar5 + 0x10) = uVar3;
      _PPStreamChunkListAddChunk(stream[10],puVar5);
      puVar9 = puVar9 + 2;
    } while (uVar7 < (uint)param_2[0x18]);
  }
  uVar7 = 0;
  puVar9 = param_2 + param_2[0x1b] * 2;
  if (param_2[0x1a] != 0) {
    do {
      puVar5 = (undefined1 *)_calloc(0x1c,1);
      uVar7 = uVar7 + 1;
      *puVar5 = 10;
      *(undefined4 *)(puVar5 + 0xc) = *puVar9;
      *(undefined4 *)(puVar5 + 0x10) = puVar9[1];
      *(undefined4 *)(puVar5 + 0x14) = puVar9[2];
      *(undefined4 *)(puVar5 + 0x18) = puVar9[3];
      puVar9 = puVar9 + 4;
      _PPStreamChunkListAddChunk(stream[0xb],puVar5);
    } while (uVar7 < (uint)param_2[0x1a]);
  }
  return 0;
}

/* _PPStreamCompare @ 0x97bf1c44 (328 bytes) */
int _PPStreamCompare(stream, param_2)
  int *stream;
  int *param_2;
{
  int iVar1;
  bool bVar2;
  
  bVar2 = true;
  if (*stream == *param_2) {
    iVar1 = ((int (*)())_PPStreamChunkListCompare)(stream[1],param_2[1]);
    bVar2 = true;
    if (iVar1 == 0) {
      iVar1 = ((int (*)())_PPStreamChunkListCompare)(stream[3],param_2[3]);
      bVar2 = true;
      if (iVar1 == 0) {
        iVar1 = ((int (*)())_PPStreamChunkListCompare)(stream[4],param_2[4]);
        bVar2 = true;
        if (iVar1 == 0) {
          iVar1 = ((int (*)())_PPStreamChunkListCompare)(stream[5],param_2[5]);
          bVar2 = true;
          if (iVar1 == 0) {
            iVar1 = ((int (*)())_PPStreamChunkListCompare)(stream[2],param_2[2]);
            bVar2 = true;
            if (iVar1 == 0) {
              iVar1 = ((int (*)())_PPStreamChunkListCompare)(stream[6],param_2[6]);
              bVar2 = true;
              if (iVar1 == 0) {
                iVar1 = ((int (*)())_PPStreamChunkListCompare)(stream[7],param_2[7]);
                bVar2 = true;
                if (iVar1 == 0) {
                  iVar1 = ((int (*)())_PPStreamChunkListCompare)(stream[8],param_2[8]);
                  bVar2 = true;
                  if (iVar1 == 0) {
                    iVar1 = ((int (*)())_PPStreamChunkListCompare)(stream[0xb],param_2[0xb]);
                    bVar2 = true;
                    if (iVar1 == 0) {
                      iVar1 = ((int (*)())_PPStreamChunkListCompare)(stream[10],param_2[10]);
                      bVar2 = true;
                      if (iVar1 == 0) {
                        iVar1 = ((int (*)())_PPStreamChunkListCompare)(stream[0xc],param_2[0xc]);
                        bVar2 = iVar1 != 0;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return bVar2;
}

/* _PPStreamRenumberOperandIndices @ 0x97bf1d8c (332 bytes) */
int _PPStreamRenumberOperandIndices(param_1, param_2, param_3)
  int param_1;
  byte *param_2;
  undefined4 param_3;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  int iVar6;
  
  iVar6 = **(int **)(param_1 + 0x20);
  if (iVar6 == 0) {
    return;
  }
  do {
    uVar2 = *(uint *)(iVar6 + 0xc);
    iVar3 = 0;
    if (uVar2 >> 0x1d != 0) {
      bVar5 = *param_2;
      iVar4 = iVar6 + 0x10;
      do {
        if (bVar5 == 2) {
          if ((*(uint *)(iVar4 + 0xc) & 0x3800000) == 0) goto LAB_97bf1e1c;
        }
        else {
          if (bVar5 < 3) {
            if (bVar5 != 0) goto LAB_97bf1e38;
            bVar1 = (*(uint *)(iVar4 + 0xc) >> 0x17 & 7) == 1;
          }
          else if (bVar5 == 3) {
            bVar1 = (*(uint *)(iVar4 + 0xc) >> 0x17 & 7) == 2;
          }
          else {
            if (bVar5 != 4) goto LAB_97bf1e38;
            bVar1 = (*(uint *)(iVar4 + 0xc) >> 0x17 & 7) == 3;
          }
          if (bVar1) {
LAB_97bf1e1c:
            if (*(short *)(iVar4 + 0x12) == *(short *)(param_2 + 0x12)) {
              *(undefined2 *)(iVar4 + 0x12) = (*(unsigned short *)((unsigned char *)&(param_3) + 2));
              uVar2 = *(uint *)(iVar6 + 0xc);
              bVar5 = *param_2;
            }
          }
        }
LAB_97bf1e38:
        if (bVar5 == 2) {
          if ((*(uint *)(iVar6 + 0x14) & 0xe0000) == 0) goto LAB_97bf1ea0;
        }
        else {
          if (bVar5 < 3) {
            if (bVar5 != 0) goto LAB_97bf1eb4;
            bVar1 = (*(uint *)(iVar6 + 0x14) >> 0x11 & 7) == 1;
          }
          else if (bVar5 == 3) {
            bVar1 = (*(uint *)(iVar6 + 0x14) >> 0x11 & 7) == 2;
          }
          else {
            if (bVar5 != 4) goto LAB_97bf1eb4;
            bVar1 = (*(uint *)(iVar6 + 0x14) >> 0x11 & 7) == 3;
          }
          if (bVar1) {
LAB_97bf1ea0:
            if (*(short *)(iVar6 + 0x1a) == *(short *)(param_2 + 0x12)) {
              *(undefined2 *)(iVar6 + 0x1a) = (*(unsigned short *)((unsigned char *)&(param_3) + 2));
            }
          }
        }
LAB_97bf1eb4:
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 8;
      } while (iVar3 < (int)(uVar2 >> 0x1d));
    }
    iVar6 = *(int *)(iVar6 + 8);
    if (iVar6 == 0) {
      return;
    }
  } while( true );
}

/* _renumberTempArrayIndices @ 0x97bf1ed8 (56 bytes) */
int _renumberTempArrayIndices(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  undefined4 param_3;
{
  if (param_1 != 0) {
    do {
      if (param_2 == *(ushort *)(param_1 + 0xe)) {
        *(undefined2 *)(param_1 + 0xe) = (*(unsigned short *)((unsigned char *)&(param_3) + 2));
      }
      if (param_2 == *(ushort *)(param_1 + 0x12)) {
        *(undefined2 *)(param_1 + 0x12) = (*(unsigned short *)((unsigned char *)&(param_3) + 2));
      }
      param_1 = *(int *)(param_1 + 8);
    } while (param_1 != 0);
    return;
  }
  return;
}

/* _renumberParamArrayIndices @ 0x97bf1f10 (56 bytes) */
int _renumberParamArrayIndices(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  undefined4 param_3;
{
  if (param_1 != 0) {
    do {
      if (param_2 == *(ushort *)(param_1 + 0xe)) {
        *(undefined2 *)(param_1 + 0xe) = (*(unsigned short *)((unsigned char *)&(param_3) + 2));
      }
      if (param_2 == *(ushort *)(param_1 + 0x12)) {
        *(undefined2 *)(param_1 + 0x12) = (*(unsigned short *)((unsigned char *)&(param_3) + 2));
      }
      param_1 = *(int *)(param_1 + 8);
    } while (param_1 != 0);
    return;
  }
  return;
}

/* _renumberLabels @ 0x97bf1f48 (72 bytes) */
int _renumberLabels(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  if (param_1 != 0) {
    do {
      if (((param_4 == 0) || (*(char *)(param_1 + 1) == '\0')) &&
         (param_2 == *(int *)(param_1 + 0xc))) {
        if (param_4 != 0) {
          *(undefined1 *)(param_1 + 1) = 1;
        }
        *(undefined4 *)(param_1 + 0xc) = param_3;
      }
      param_1 = *(int *)(param_1 + 8);
    } while (param_1 != 0);
    return;
  }
  return;
}

/* _renumberTargets @ 0x97bf1f90 (148 bytes) */
int _renumberTargets(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  int param_4;
{
  if (param_1 == 0) {
    return;
  }
  do {
    switch(*(uint *)(param_1 + 0xc) >> 0x12 & 0xff) {
    case 0x4b:
    case 0x4c:
    case 0x54:
    case 0x55:
    case 0x56:
    case 0x57:
    case 0x58:
    case 0x5a:
    case 0x5b:
    case 0x69:
    case 0x6a:
    case 0x6b:
      if (((param_4 == 0) || (*(char *)(param_1 + 1) == '\0')) &&
         (param_2 == (*(uint *)(param_1 + 0x10) & 0x3ffff))) {
        if (param_4 != 0) {
          *(undefined1 *)(param_1 + 1) = 1;
        }
        *(uint *)(param_1 + 0x10) = param_3 & 0x3ffff | *(uint *)(param_1 + 0x10) & 0xfffc0000;
      }
    }
    param_1 = *(int *)(param_1 + 8);
  } while (param_1 != 0);
  return;
}

/* _PPStreamChangeBranchTargets @ 0x97bf20a8 (84 bytes) */
int _PPStreamChangeBranchTargets(stream, param_2, param_3)
  int stream;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_renumberLabels)(**(undefined4 **)(stream + 0x24),param_2,param_3,0);
  return ((int (*)())_renumberTargets)(**(undefined4 **)(stream + 0x20),param_2,param_3,0);
}

/* _PPStreamPackIndices @ 0x97bf20fc (612 bytes) */
int _PPStreamPackIndices(stream)
  int stream;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = 0;
  for (iVar3 = **(int **)(stream + 4); iVar3 != 0; iVar3 = *(int *)(iVar3 + 8)) {
    if (*(ushort *)(iVar3 + 0x12) != uVar2) {
      ((int (*)())_PPStreamRenumberOperandIndices)(stream,iVar3,uVar2);
      ((int (*)())_renumberTempArrayIndices)(**(undefined4 **)(stream + 8),(uint)*(ushort *)(iVar3 + 0x12),uVar2);
      *(short *)(iVar3 + 0x12) = (short)uVar2;
    }
    uVar2 = uVar2 + 1;
  }
  iVar3 = 0;
  for (iVar4 = **(int **)(stream + 0xc); iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    if (*(int *)(iVar4 + 0xc) != iVar3) {
      ((int (*)())_PPStreamRenumberOperandIndices)(stream,iVar4,iVar3);
      *(int *)(iVar4 + 0xc) = iVar3;
    }
    iVar3 = iVar3 + 1;
  }
  uVar2 = 0;
  for (iVar3 = **(int **)(stream + 0x10); iVar3 != 0; iVar3 = *(int *)(iVar3 + 8)) {
    if (*(ushort *)(iVar3 + 0x12) != uVar2) {
      ((int (*)())_PPStreamRenumberOperandIndices)(stream,iVar3,uVar2);
      ((int (*)())_renumberParamArrayIndices)(**(undefined4 **)(stream + 0x14),(uint)*(ushort *)(iVar3 + 0x12),uVar2);
      *(short *)(iVar3 + 0x12) = (short)uVar2;
    }
    uVar2 = uVar2 + 1;
  }
  uVar2 = 0;
  for (iVar3 = **(int **)(stream + 0x18); iVar3 != 0; iVar3 = *(int *)(iVar3 + 8)) {
    if (*(ushort *)(iVar3 + 0x12) != uVar2) {
      ((int (*)())_PPStreamRenumberOperandIndices)(stream,iVar3,uVar2);
      *(short *)(iVar3 + 0x12) = (short)uVar2;
    }
    uVar2 = uVar2 + 1;
  }
  uVar2 = 0;
  for (iVar3 = **(int **)(stream + 0x1c); iVar3 != 0; iVar3 = *(int *)(iVar3 + 8)) {
    if (*(ushort *)(iVar3 + 0x12) != uVar2) {
      ((int (*)())_PPStreamRenumberOperandIndices)(stream,iVar3,uVar2);
      *(short *)(iVar3 + 0x12) = (short)uVar2;
    }
    uVar2 = uVar2 + 1;
  }
  for (iVar3 = **(int **)(stream + 0x20); iVar3 != 0; iVar3 = *(int *)(iVar3 + 8)) {
    *(undefined1 *)(iVar3 + 1) = 0;
  }
  for (iVar3 = **(int **)(stream + 0x24); iVar3 != 0; iVar3 = *(int *)(iVar3 + 8)) {
    *(undefined1 *)(iVar3 + 1) = 0;
  }
  uVar2 = 1;
  for (iVar3 = **(int **)(stream + 0x20); iVar3 != 0; iVar3 = *(int *)(iVar3 + 8)) {
    uVar1 = *(uint *)(iVar3 + 0xc) & 0x3ffff;
    if ((uVar1 != 0) && (uVar1 != uVar2)) {
      ((int (*)())_renumberLabels)(**(undefined4 **)(stream + 0x24),uVar1,uVar2,1);
      ((int (*)())_renumberTargets)(**(undefined4 **)(stream + 0x20),*(uint *)(iVar3 + 0xc) & 0x3ffff,uVar2,1);
      *(uint *)(iVar3 + 0xc) = uVar2 & 0x3ffff | *(uint *)(iVar3 + 0xc) & 0xfffc0000;
    }
    uVar2 = uVar2 + 1;
  }
  return;
}

/* _PPStreamSortParamConstants @ 0x97bf2360 (168 bytes) */
int _PPStreamSortParamConstants(stream)
  int stream;
{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = **(int **)(stream + 0x10);
  iVar2 = _PPStreamChunkListGetMaxIndex(*(int **)(stream + 0x10));
  if (iVar4 != 0) {
    uVar1 = *(ushort *)(iVar4 + 0x12);
    uVar3 = iVar2 + 1U;
    while ((uint)uVar1 < iVar2 + 1U) {
      if ((*(uint *)(iVar4 + 0xc) >> 0x10 & 0x1f) == 0x11) {
        ((int (*)())_PPStreamRenumberOperandIndices)(stream,iVar4,uVar3);
        ((int (*)())_renumberParamArrayIndices)(**(undefined4 **)(stream + 0x14),(uint)*(ushort *)(iVar4 + 0x12),uVar3);
        *(short *)(iVar4 + 0x12) = (short)uVar3;
        uVar3 = uVar3 + 1;
      }
      iVar4 = *(int *)(iVar4 + 8);
      if (iVar4 == 0) break;
      uVar1 = *(ushort *)(iVar4 + 0x12);
    }
  }
  return _PPStreamChunkListSort(*(undefined4 *)(stream + 0x10));
}

/* _PPStreamResolveBranches @ 0x97bf2408 (340 bytes) */
int _PPStreamResolveBranches(stream)
  int stream;
{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  piVar4 = *(int **)(stream + 0x20);
  uVar2 = 0;
  piVar3 = *(int **)(stream + 0x24);
  iVar5 = *piVar4;
  do {
    if (iVar5 == 0) {
      iVar5 = *piVar3;
      while( true ) {
        if (iVar5 == 0) {
          return uVar2;
        }
        iVar6 = _memcmp("main(",iVar5 + 0x14,6);
        if (iVar6 == 0) break;
        iVar5 = *(int *)(iVar5 + 8);
      }
      iVar6 = *piVar4;
      if (iVar6 == 0) {
        return uVar2;
      }
      do {
        if (*(uint *)(iVar5 + 0xc) == (*(uint *)(iVar6 + 0xc) & 0x3ffff)) {
          *(uint *)(iVar6 + 0xc) = *(uint *)(iVar6 + 0xc) & 0xfffc0000;
          *(undefined4 *)(iVar5 + 0xc) = 0;
          return uVar2;
        }
        iVar6 = *(int *)(iVar6 + 8);
      } while (iVar6 != 0);
      return uVar2;
    }
    iVar6 = *(int *)(iVar5 + 0x40);
    if (iVar6 != 0) {
      *(uint *)(iVar5 + 0x10) = piVar4[2] + 1U & 0x3ffff | *(uint *)(iVar5 + 0x10) & 0xfffc0000;
      for (iVar7 = *piVar3; iVar7 != 0; iVar7 = *(int *)(iVar7 + 8)) {
        if ((iVar6 == *(int *)(iVar7 + 0x10)) &&
           (iVar1 = _strncmp(iVar5 + 0x44,iVar7 + 0x14,iVar6), iVar1 == 0)) {
          *(uint *)(iVar5 + 0x10) =
               *(uint *)(iVar7 + 0xc) & 0x3ffff | *(uint *)(iVar5 + 0x10) & 0xfffc0000;
          goto LAB_97bf24b8;
        }
      }
      uVar2 = 1;
    }
LAB_97bf24b8:
    iVar5 = *(int *)(iVar5 + 8);
  } while( true );
}

/* _PPStreamGetArray @ 0x97bf255c (152 bytes) */
int _PPStreamGetArray(stream, param_2, param_3)
  int stream;
  int param_2;
  uint param_3;
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_2 == 1) {
    for (iVar1 = **(int **)(stream + 8); iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
      if ((*(ushort *)(iVar1 + 0xe) <= param_3) && (param_3 <= *(ushort *)(iVar1 + 0x12))) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    }
  }
  else if (param_2 == 2) {
    for (iVar1 = **(int **)(stream + 0x14); iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
      if ((*(ushort *)(iVar1 + 0xe) <= param_3) && (param_3 <= *(ushort *)(iVar1 + 0x12))) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    }
  }
  return -1;
}

/* _PPStreamFindDuplicateChunk @ 0x97bf25f4 (240 bytes) */
int _PPStreamFindDuplicateChunk(stream, param_2)
  int stream;
  undefined1 *param_2;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = (int *)0x0;
  switch(*param_2) {
  case 0:
    piVar1 = *(int **)(stream + 4);
    break;
  case 1:
    piVar1 = *(int **)(stream + 0xc);
    break;
  case 2:
    piVar1 = *(int **)(stream + 0x18);
    break;
  case 3:
    piVar1 = *(int **)(stream + 0x10);
    break;
  case 4:
    piVar1 = *(int **)(stream + 0x1c);
    break;
  case 5:
    piVar1 = *(int **)(stream + 0x14);
    break;
  case 6:
    piVar1 = *(int **)(stream + 8);
    break;
  case 7:
    piVar1 = *(int **)(stream + 0x30);
    break;
  case 8:
    piVar1 = *(int **)(stream + 0x20);
    break;
  case 9:
    piVar1 = *(int **)(stream + 0x28);
    break;
  case 10:
    piVar1 = *(int **)(stream + 0x2c);
    break;
  case 0xb:
    piVar1 = *(int **)(stream + 0x24);
  }
  iVar3 = *piVar1;
  while( true ) {
    if (iVar3 == 0) {
      return 0;
    }
    iVar2 = ((int (*)())_PPStreamChunkCompare)(iVar3,param_2);
    if (iVar2 == 0) break;
    iVar3 = *(int *)(iVar3 + 8);
  }
  return iVar3;
}

