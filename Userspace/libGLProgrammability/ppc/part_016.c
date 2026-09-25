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
int _PPEmulatorGetEmulationLevel(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 0xd80) == 0) {
    return 0;
  }
  return *(undefined4 *)(*(int *)(param_1 + 0xd80) + 0x124);
}

/* _PPEmulatorFramebufferFormat @ 0x97be5bcc (24 bytes) */
int _PPEmulatorFramebufferFormat(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 0xd9c) == 0) {
    return 0;
  }
  return *(undefined4 *)(*(int *)(param_1 + 0xd9c) + 0x60);
}

/* _PPEmulatorEmulateSingleOp @ 0x97be5be4 (8 bytes) */
void _PPEmulatorEmulateSingleOp(int param_1,undefined4 param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  ((int * (*)())_InterpreterEmulateOp)(*(undefined4 *)(param_1 + 0xdf0),param_2,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
             fparam_6,fparam_7,fparam_8,fparam_9,fparam_10,fparam_11,fparam_12,fparam_13);
  return;
}

/* _PPEmulatorRun @ 0x97be5bec (116 bytes) */
int _PPEmulatorRun(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = *(int *)(param_1 + 0xd80);
  if (((*(int *)(iVar1 + 0x38) == 0x8804) || (*(int *)(iVar1 + 0x38) == 0x8b30)) &&
     ((double)*(float *)(*(int *)(param_1 + 0xda0) + 0xc) != DOUBLE_97c30a60)) {
    UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 0xc);
  }
  else {
    UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 8);
  }
                    
                    
  (*UNRECOVERED_JUMPTABLE)(param_1,param_2,param_3,param_4,param_5,0x97be5bf8,param_1,param_2);
  return;
}

/* _PPEmulatorBuild @ 0x97be5c60 (576 bytes) */
int _PPEmulatorBuild(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
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
  
  iVar7 = *(int *)(param_1 + 0xd80);
  a6 = 0;
  uVar6 = *(uint *)(iVar7 + 0x124);
  if (((*(int *)(iVar7 + 0x38) == 0x8804) || (*(int *)(iVar7 + 0x38) == 0x8b30)) &&
     ((double)*(float *)(*(int *)(param_1 + 0xda0) + 0xc) != DOUBLE_97c30a60)) {
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
      _PPCRuntimeCompilerAttachEmulatorContext(uVar4,param_1);
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
      _PPCRuntimeCompilerAttachEmulatorContext(uVar4,param_1);
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
                    
                    
  (*UNRECOVERED_JUMPTABLE)(param_1,param_2,param_3,param_4,param_5,param_6,a6);
  return;
}

/* _PPEmulatorRunNoop @ 0x97be5ea0 (8 bytes) */
int _PPEmulatorRunNoop()
{
  return 0;
}

/* _PPEmulatorVariableSwizzleFromMask @ 0x97be5ea8 (108 bytes) */
int _PPEmulatorVariableSwizzleFromMask(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
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
  
  bVar1 = *(byte *)(param_1 + 0x1c);
  if (bVar1 == 0) {
    *(byte *)(param_1 + 8) = bVar1;
    *(undefined1 *)(param_1 + 0xb) = 3;
    *(undefined1 *)(param_1 + 10) = 2;
    *(undefined1 *)(param_1 + 9) = 1;
    return;
  }
  iVar4 = 4;
  puVar3 = (undefined1 *)(param_1 + 8);
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
int _PPEmulatorVariableMaskFromSwizzle(param_1)
  int param_1;
{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  
  *(undefined1 *)(param_1 + 0x1c) = 0;
  iVar3 = 4;
  pbVar2 = (byte *)(param_1 + 8);
  do {
    bVar1 = *pbVar2;
    pbVar2 = pbVar2 + 1;
    if (bVar1 != 0xff) {
      *(byte *)(param_1 + 0x1c) = *(byte *)(param_1 + 0x1c) | (byte)(1 << (bVar1 & 0x3f));
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
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = 0;
  cVar1 = s___97c2a320[0];
  while (cVar1 != '\0') {
    *(char *)(param_1 + iVar2) = cVar1;
    cVar1 = ":"[iVar2 + 1];
    iVar2 = iVar2 + 1;
  }
  iVar3 = ((int (*)())_ncpy_97be5f58)(param_1 + iVar2,param_2 + 1);
  iVar3 = param_1 + iVar2 + iVar3;
  if (param_3 == 1) {
    iVar2 = 0;
    cVar1 = s___97c2a320[0];
    while (cVar1 != '\0') {
      *(char *)(iVar3 + iVar2) = cVar1;
      cVar1 = ":"[iVar2 + 1];
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
    cVar1 = s_F_97c2d738[0];
    while (cVar1 != '\0') {
      *(char *)(iVar3 + iVar2) = cVar1;
      cVar1 = "F"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 2:
    iVar2 = 0;
    cVar1 = s_X_97c2d73c[0];
    while (cVar1 != '\0') {
      *(char *)(iVar3 + iVar2) = cVar1;
      cVar1 = "X"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 3:
    iVar2 = 0;
    cVar1 = s_I_97c2d740[0];
    while (cVar1 != '\0') {
      *(char *)(iVar3 + iVar2) = cVar1;
      cVar1 = "I"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 4:
    iVar2 = 0;
    cVar1 = s_B_97c2d744[0];
    while (cVar1 != '\0') {
      *(char *)(iVar3 + iVar2) = cVar1;
      cVar1 = "B"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
  }
  iVar3 = iVar3 + iVar2;
switchD_97be60c8_caseD_0:
  if (param_5 == 1) {
    iVar2 = 0;
    cVar1 = s_32_97c2d748[0];
    while (cVar1 != '\0') {
      *(char *)(iVar3 + iVar2) = cVar1;
      cVar1 = "32"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
  }
  else {
    if (param_5 < 2) {
      return iVar3;
    }
    if (param_5 == 2) {
      iVar2 = 0;
      cVar1 = s_16_97c2d74c[0];
      while (cVar1 != '\0') {
        *(char *)(iVar3 + iVar2) = cVar1;
        cVar1 = "16"[iVar2 + 1];
        iVar2 = iVar2 + 1;
      }
    }
    else {
      if (param_5 != 3) {
        return iVar3;
      }
      iVar2 = 0;
      cVar1 = s_12_97c2d750[0];
      while (cVar1 != '\0') {
        *(char *)(iVar3 + iVar2) = cVar1;
        cVar1 = "12"[iVar2 + 1];
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
  char cVar1;
  int iVar2;
  
  if (param_2 == 1) {
    iVar2 = 0;
    cVar1 = s_R_97c2d754[0];
    while (cVar1 != '\0') {
      *(char *)(param_1 + iVar2) = cVar1;
      cVar1 = "R"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
  }
  else {
    if (param_2 < 2) {
      return param_1;
    }
    if (param_2 == 2) {
      iVar2 = 0;
      cVar1 = s_H_97c2d758[0];
      while (cVar1 != '\0') {
        *(char *)(param_1 + iVar2) = cVar1;
        cVar1 = "H"[iVar2 + 1];
        iVar2 = iVar2 + 1;
      }
    }
    else {
      if (param_2 != 3) {
        return param_1;
      }
      iVar2 = 0;
      cVar1 = s_X_97c2d73c[0];
      while (cVar1 != '\0') {
        *(char *)(param_1 + iVar2) = cVar1;
        cVar1 = "X"[iVar2 + 1];
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
  char cVar1;
  int iVar2;
  int iVar3;
  
  if ((param_2 != 3) || (param_3 == 1)) {
    iVar2 = 0;
    cVar1 = s___97c2a320[0];
    while (cVar1 != '\0') {
      *(char *)(param_1 + iVar2) = cVar1;
      cVar1 = ":"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    iVar3 = ((int (*)())_ncpy_97be5f58)(param_1 + iVar2,param_2 + 1);
    param_1 = param_1 + iVar2 + iVar3;
    if (param_3 == 1) {
      iVar2 = 0;
      cVar1 = s___97c2a320[0];
      while (cVar1 != '\0') {
        *(char *)(param_1 + iVar2) = cVar1;
        cVar1 = ":"[iVar2 + 1];
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
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = 0;
  cVar1 = s___97c2a320[0];
  while (cVar1 != '\0') {
    *(char *)(param_1 + iVar2) = cVar1;
    cVar1 = ":"[iVar2 + 1];
    iVar2 = iVar2 + 1;
  }
  iVar3 = ((int (*)())_ncpy_97be5f58)(param_1 + iVar2,param_2 + 1);
  iVar3 = param_1 + iVar2 + iVar3;
  if (param_3 != 0) {
    iVar2 = 0;
    cVar1 = s___97c2a320[0];
    while (cVar1 != '\0') {
      *(char *)(iVar3 + iVar2) = cVar1;
      cVar1 = ":"[iVar2 + 1];
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
    cVar1 = s_F_97c2d738[0];
    while (cVar1 != '\0') {
      *(char *)(iVar3 + iVar2) = cVar1;
      cVar1 = "F"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 2:
    iVar2 = 0;
    cVar1 = s_X_97c2d73c[0];
    while (cVar1 != '\0') {
      *(char *)(iVar3 + iVar2) = cVar1;
      cVar1 = "X"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 3:
    iVar2 = 0;
    cVar1 = s_I_97c2d740[0];
    while (cVar1 != '\0') {
      *(char *)(iVar3 + iVar2) = cVar1;
      cVar1 = "I"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 4:
    iVar2 = 0;
    cVar1 = s_B_97c2d744[0];
    while (cVar1 != '\0') {
      *(char *)(iVar3 + iVar2) = cVar1;
      cVar1 = "B"[iVar2 + 1];
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
  char cVar1;
  int iVar2;
  
  if (param_2 != 0) {
    iVar2 = 0;
    cVar1 = s_C_97c2d75c[0];
    while (cVar1 != '\0') {
      *(char *)(param_1 + iVar2) = cVar1;
      cVar1 = "C"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    param_1 = param_1 + iVar2;
    if (0 < param_3) {
      iVar2 = 0;
      cVar1 = s_1_97c2d760[0];
      while (cVar1 != '\0') {
        *(char *)(param_1 + iVar2) = cVar1;
        cVar1 = "1"[iVar2 + 1];
        iVar2 = iVar2 + 1;
      }
      param_1 = param_1 + iVar2;
    }
  }
  if (param_4 != 0) {
    iVar2 = 0;
    cVar1 = s__SAT_97c2d764[0];
    while (cVar1 != '\0') {
      *(char *)(param_1 + iVar2) = cVar1;
      cVar1 = "_SAT"[iVar2 + 1];
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
  char cVar1;
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
    cVar1 = s_tmp_97c2d76c[0];
    while (cVar1 != '\0') {
      param_2[iVar5] = cVar1;
      cVar1 = "tmp"[iVar5 + 1];
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
      cVar1 = s___97c29860[0];
      while (cVar1 != '\0') {
        param_2[iVar5] = cVar1;
        cVar1 = "["[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      pcVar8 = param_2 + iVar5;
      iVar7 = ((int (*)())_ncpy_97be5f58)(pcVar8,*(undefined4 *)
                                     (param_4 + (uint)*(ushort *)(iVar3 + param_1 + 6) * 4));
      iVar5 = 0;
      cVar1 = s___97c2d770[0];
      while (cVar1 != '\0') {
        pcVar8[iVar5 + iVar7] = cVar1;
        cVar1 = "]"[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      param_2 = pcVar8 + iVar5 + iVar7;
    }
  }
  else if (uVar4 == 3) {
    iVar5 = 0;
    cVar1 = s_res_97c2d774[0];
    while (cVar1 != '\0') {
      param_2[iVar5] = cVar1;
      cVar1 = "res"[iVar5 + 1];
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
      cVar1 = s___97c2a130[0];
      while (cVar1 != '\0') {
        param_2[iVar5] = cVar1;
        cVar1 = "."[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      param_2 = param_2 + iVar5;
      if ((*(uint *)(iVar3 + param_1) & 0x2000) != 0) {
        iVar5 = 0;
        cVar1 = s_x_97c2d790[0];
        while (cVar1 != '\0') {
          param_2[iVar5] = cVar1;
          cVar1 = "x"[iVar5 + 1];
          iVar5 = iVar5 + 1;
        }
        param_2 = param_2 + iVar5;
      }
      if ((*(uint *)(iVar3 + param_1) & 0x4000) != 0) {
        iVar5 = 0;
        cVar1 = s_y_97c2d794[0];
        while (cVar1 != '\0') {
          param_2[iVar5] = cVar1;
          cVar1 = "y"[iVar5 + 1];
          iVar5 = iVar5 + 1;
        }
        param_2 = param_2 + iVar5;
      }
      if ((*(uint *)(iVar3 + param_1) & 0x8000) != 0) {
        iVar5 = 0;
        cVar1 = s_z_97c2d798[0];
        while (cVar1 != '\0') {
          param_2[iVar5] = cVar1;
          cVar1 = "z"[iVar5 + 1];
          iVar5 = iVar5 + 1;
        }
        param_2 = param_2 + iVar5;
      }
      if ((*(uint *)(iVar3 + param_1) & 0x10000) != 0) {
        iVar5 = 0;
        cVar1 = s_w_97c2d79c[0];
        while (cVar1 != '\0') {
          param_2[iVar5] = cVar1;
          cVar1 = "w"[iVar5 + 1];
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
      cVar1 = s__adr_97c2d778[0];
      while (cVar1 != '\0') {
        param_2[iVar5] = cVar1;
        cVar1 = "[adr"[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      iVar6 = ((int (*)())_ncpy_97be5f58)(param_2 + iVar5,*(uint *)(iVar3 + param_1 + 4) >> 0x1e & 1);
      pcVar8 = param_2 + iVar5 + iVar6;
      uVar4 = *(uint *)(iVar3 + param_1 + 4) >> 0x1c & 3;
      if (uVar4 == 1) {
        iVar5 = 0;
        cVar1 = s__y_97c2d784[0];
        while (cVar1 != '\0') {
          pcVar8[iVar5] = cVar1;
          cVar1 = ".y"[iVar5 + 1];
          iVar5 = iVar5 + 1;
        }
LAB_97be6a74:
        pcVar8 = pcVar8 + iVar5;
      }
      else {
        if (1 < uVar4) {
          if (uVar4 == 2) {
            iVar5 = 0;
            cVar1 = s__z_97c2d788[0];
            while (cVar1 != '\0') {
              pcVar8[iVar5] = cVar1;
              cVar1 = ".z"[iVar5 + 1];
              iVar5 = iVar5 + 1;
            }
          }
          else {
            if (uVar4 != 3) goto LAB_97be6a78;
            iVar5 = 0;
            cVar1 = s__w_97c2d78c[0];
            while (cVar1 != '\0') {
              pcVar8[iVar5] = cVar1;
              cVar1 = ".w"[iVar5 + 1];
              iVar5 = iVar5 + 1;
            }
          }
          goto LAB_97be6a74;
        }
        if (uVar4 == 0) {
          iVar5 = 0;
          cVar1 = s__x_97c2d780[0];
          while (cVar1 != '\0') {
            pcVar8[iVar5] = cVar1;
            cVar1 = ".x"[iVar5 + 1];
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
          cVar1 = s___97c2a308[0];
          while (cVar1 != '\0') {
            pcVar8[iVar5] = cVar1;
            cVar1 = "+"[iVar5 + 1];
            iVar5 = iVar5 + 1;
          }
          pcVar8 = pcVar8 + iVar5;
        }
        iVar5 = ((int (*)())_ncpy_97be5f58)(pcVar8,iVar7);
        pcVar8 = pcVar8 + iVar5;
      }
      iVar5 = 0;
      cVar1 = s___97c2d770[0];
      while (cVar1 != '\0') {
        pcVar8[iVar5] = cVar1;
        cVar1 = "]"[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      param_2 = pcVar8 + iVar5;
    }
    iVar5 = 0;
    cVar1 = s___97c2a130[0];
    while (cVar1 != '\0') {
      param_2[iVar5] = cVar1;
      cVar1 = "."[iVar5 + 1];
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
    cVar1 = s__EQ_97c2d7a8[0];
    while (cVar1 != '\0') {
      param_2[iVar5] = cVar1;
      cVar1 = " (EQ"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    break;
  case 2:
    iVar5 = 0;
    cVar1 = s__GE_97c2d7b0[0];
    while (cVar1 != '\0') {
      param_2[iVar5] = cVar1;
      cVar1 = " (GE"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    break;
  case 3:
    iVar5 = 0;
    cVar1 = s__GT_97c2d7b8[0];
    while (cVar1 != '\0') {
      param_2[iVar5] = cVar1;
      cVar1 = " (GT"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    break;
  case 4:
    iVar5 = 0;
    cVar1 = s__LE_97c2d7c0[0];
    while (cVar1 != '\0') {
      param_2[iVar5] = cVar1;
      cVar1 = " (LE"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    break;
  case 5:
    iVar5 = 0;
    cVar1 = s__LT_97c2d7c8[0];
    while (cVar1 != '\0') {
      param_2[iVar5] = cVar1;
      cVar1 = " (LT"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    break;
  case 6:
    iVar5 = 0;
    cVar1 = s__NE_97c2d7d0[0];
    while (cVar1 != '\0') {
      param_2[iVar5] = cVar1;
      cVar1 = " (NE"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    break;
  case 7:
    iVar5 = 0;
    cVar1 = s__FL_97c2d7d8[0];
    while (cVar1 != '\0') {
      param_2[iVar5] = cVar1;
      cVar1 = " (FL"[iVar5 + 1];
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
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = param_3 * 8;
  if ((*(uint *)(iVar2 + param_1) >> 0x11 & 7) == 4) {
    iVar4 = 0;
    cVar1 = s_adr_97c2d7e0[0];
    while (cVar1 != '\0') {
      *(char *)(param_2 + iVar4) = cVar1;
      cVar1 = "adr"[iVar4 + 1];
      iVar4 = iVar4 + 1;
    }
    iVar3 = ((int (*)())_ncpy_97be5f58)(param_2 + iVar4,(uint)*(ushort *)(iVar2 + param_1 + 6));
    param_2 = param_2 + iVar4 + iVar3;
  }
  if ((*(uint *)(iVar2 + param_1) & 0x1e000) != 0x1e000) {
    iVar4 = 0;
    cVar1 = s___97c2a130[0];
    while (cVar1 != '\0') {
      *(char *)(param_2 + iVar4) = cVar1;
      cVar1 = "."[iVar4 + 1];
      iVar4 = iVar4 + 1;
    }
    iVar4 = param_2 + iVar4;
    if (param_4 == 0) {
      if ((*(uint *)(iVar2 + param_1) & 0x2000) != 0) {
        iVar3 = 0;
        cVar1 = s_x_97c2d790[0];
        while (cVar1 != '\0') {
          *(char *)(iVar4 + iVar3) = cVar1;
          cVar1 = "x"[iVar3 + 1];
          iVar3 = iVar3 + 1;
        }
        iVar4 = iVar4 + iVar3;
      }
      if ((*(uint *)(iVar2 + param_1) & 0x4000) != 0) {
        iVar3 = 0;
        cVar1 = s_y_97c2d794[0];
        while (cVar1 != '\0') {
          *(char *)(iVar4 + iVar3) = cVar1;
          cVar1 = "y"[iVar3 + 1];
          iVar3 = iVar3 + 1;
        }
        iVar4 = iVar4 + iVar3;
      }
      if ((*(uint *)(iVar2 + param_1) & 0x8000) != 0) {
        iVar3 = 0;
        cVar1 = s_z_97c2d798[0];
        while (cVar1 != '\0') {
          *(char *)(iVar4 + iVar3) = cVar1;
          cVar1 = "z"[iVar3 + 1];
          iVar3 = iVar3 + 1;
        }
        iVar4 = iVar4 + iVar3;
      }
      if ((*(uint *)(iVar2 + param_1) & 0x10000) == 0) {
        return iVar4;
      }
      iVar2 = 0;
      cVar1 = s_w_97c2d79c[0];
      while (cVar1 != '\0') {
        *(char *)(iVar4 + iVar2) = cVar1;
        cVar1 = "w"[iVar2 + 1];
        iVar2 = iVar2 + 1;
      }
    }
    else {
      if ((*(uint *)(iVar2 + param_1) & 0x2000) != 0) {
        iVar3 = 0;
        cVar1 = s_x_97c2d790[0];
        while (cVar1 != '\0') {
          *(char *)(iVar4 + iVar3) = cVar1;
          cVar1 = "x"[iVar3 + 1];
          iVar3 = iVar3 + 1;
        }
        iVar4 = iVar4 + iVar3;
      }
      if (((*(uint *)(iVar2 + param_1) & 0xc00) != 0) &&
         ((*(uint *)(iVar2 + param_1) & 0x4000) != 0)) {
        iVar3 = 0;
        cVar1 = s_y_97c2d794[0];
        while (cVar1 != '\0') {
          *(char *)(iVar4 + iVar3) = cVar1;
          cVar1 = "y"[iVar3 + 1];
          iVar3 = iVar3 + 1;
        }
        iVar4 = iVar4 + iVar3;
      }
      if ((1 < (*(uint *)(iVar2 + param_1) >> 10 & 3)) &&
         ((*(uint *)(iVar2 + param_1) & 0x8000) != 0)) {
        iVar3 = 0;
        cVar1 = s_z_97c2d798[0];
        while (cVar1 != '\0') {
          *(char *)(iVar4 + iVar3) = cVar1;
          cVar1 = "z"[iVar3 + 1];
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
      cVar1 = s_w_97c2d79c[0];
      while (cVar1 != '\0') {
        *(char *)(iVar4 + iVar2) = cVar1;
        cVar1 = "w"[iVar2 + 1];
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
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = param_7 * 8;
  switch(*(uint *)(iVar4 + param_1) >> 0x17 & 7) {
  case 0:
    iVar5 = 0;
    cVar1 = s_att_97c2d7e4[0];
    while (cVar1 != '\0') {
      *(char *)(param_2 + iVar5) = cVar1;
      cVar1 = "att"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    goto LAB_97be770c;
  case 1:
    iVar5 = 0;
    cVar1 = s_tmp_97c2d76c[0];
    while (cVar1 != '\0') {
      *(char *)(param_2 + iVar5) = cVar1;
      cVar1 = "tmp"[iVar5 + 1];
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
      cVar1 = s___97c29860[0];
      while (cVar1 != '\0') {
        *(char *)(param_2 + iVar5) = cVar1;
        cVar1 = "["[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      iVar6 = ((int (*)())_ncpy_97be5f58)(param_2 + iVar5,
                             *(undefined4 *)(param_6 + (uint)*(ushort *)(iVar4 + param_1 + 6) * 4));
      iVar6 = param_2 + iVar5 + iVar6;
      iVar5 = 0;
      cVar1 = s___97c2d770[0];
      while (cVar1 != '\0') {
        *(char *)(iVar6 + iVar5) = cVar1;
        cVar1 = "]"[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
LAB_97be7698:
      param_2 = iVar6 + iVar5;
    }
    break;
  case 2:
    iVar5 = 0;
    cVar1 = s_prm_97c2d7e8[0];
    while (cVar1 != '\0') {
      *(char *)(param_2 + iVar5) = cVar1;
      cVar1 = "prm"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    iVar6 = ((int (*)())_ncpy_97be5f58)(param_2 + iVar5,
                           *(undefined4 *)(param_3 + (uint)*(ushort *)(iVar4 + param_1 + 6) * 4));
    param_2 = param_2 + iVar5 + iVar6;
    if ((-1 < *(int *)(iVar4 + param_1)) &&
       (*(int *)(param_4 + (uint)*(ushort *)(iVar4 + param_1 + 6) * 4) != -1)) {
      iVar5 = 0;
      cVar1 = s___97c29860[0];
      while (cVar1 != '\0') {
        *(char *)(param_2 + iVar5) = cVar1;
        cVar1 = "["[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      iVar6 = ((int (*)())_ncpy_97be5f58)(param_2 + iVar5,
                             *(undefined4 *)(param_4 + (uint)*(ushort *)(iVar4 + param_1 + 6) * 4));
      iVar6 = param_2 + iVar5 + iVar6;
      iVar5 = 0;
      cVar1 = s___97c2d770[0];
      while (cVar1 != '\0') {
        *(char *)(iVar6 + iVar5) = cVar1;
        cVar1 = "]"[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      goto LAB_97be7698;
    }
    break;
  case 3:
    iVar5 = 0;
    cVar1 = s_res_97c2d774[0];
    while (cVar1 != '\0') {
      *(char *)(param_2 + iVar5) = cVar1;
      cVar1 = "res"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    goto LAB_97be770c;
  case 4:
    iVar5 = 0;
    cVar1 = s_adr_97c2d7e0[0];
    while (cVar1 != '\0') {
      *(char *)(param_2 + iVar5) = cVar1;
      cVar1 = "adr"[iVar5 + 1];
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
  cVar1 = s__adr_97c2d778[0];
  while (cVar1 != '\0') {
    *(char *)(param_2 + iVar5) = cVar1;
    cVar1 = "[adr"[iVar5 + 1];
    iVar5 = iVar5 + 1;
  }
  iVar3 = ((int (*)())_ncpy_97be5f58)(param_2 + iVar5,*(uint *)(iVar4 + param_1) >> 0x1e & 1);
  iVar3 = param_2 + iVar5 + iVar3;
  uVar2 = *(uint *)(iVar4 + param_1) >> 0x1c & 3;
  if (uVar2 == 1) {
    iVar5 = 0;
    cVar1 = s__y_97c2d784[0];
    while (cVar1 != '\0') {
      *(char *)(iVar3 + iVar5) = cVar1;
      cVar1 = ".y"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
  }
  else if (uVar2 < 2) {
    if (uVar2 != 0) goto LAB_97be7894;
    iVar5 = 0;
    cVar1 = s__x_97c2d780[0];
    while (cVar1 != '\0') {
      *(char *)(iVar3 + iVar5) = cVar1;
      cVar1 = ".x"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
  }
  else if (uVar2 == 2) {
    iVar5 = 0;
    cVar1 = s__z_97c2d788[0];
    while (cVar1 != '\0') {
      *(char *)(iVar3 + iVar5) = cVar1;
      cVar1 = ".z"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
  }
  else {
    if (uVar2 != 3) goto LAB_97be7894;
    iVar5 = 0;
    cVar1 = s__w_97c2d78c[0];
    while (cVar1 != '\0') {
      *(char *)(iVar3 + iVar5) = cVar1;
      cVar1 = ".w"[iVar5 + 1];
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
      cVar1 = s___97c2a308[0];
      while (cVar1 != '\0') {
        *(char *)(iVar3 + iVar4) = cVar1;
        cVar1 = "+"[iVar4 + 1];
        iVar4 = iVar4 + 1;
      }
      iVar3 = iVar3 + iVar4;
    }
    iVar4 = ((int (*)())_ncpy_97be5f58)(iVar3,iVar5);
    iVar3 = iVar3 + iVar4;
  }
  iVar4 = 0;
  cVar1 = s___97c2d770[0];
  while (cVar1 != '\0') {
    *(char *)(iVar3 + iVar4) = cVar1;
    cVar1 = "]"[iVar4 + 1];
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
  char cVar1;
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
    cVar1 = s___97c2a130[0];
    while (cVar1 != '\0') {
      param_2[iVar2] = cVar1;
      cVar1 = "."[iVar2 + 1];
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
    cVar1 = s___97c2a130[0];
    while (cVar1 != '\0') {
      param_2[iVar3] = cVar1;
      cVar1 = "."[iVar3 + 1];
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
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = 0;
  iVar4 = 0;
  do {
    if (iVar4 == 1) {
      uVar3 = *(uint *)(param_3 * 8 + param_1) >> 8 & 0xf;
      iVar2 = 0;
      cVar1 = s___97c2a324[0];
      while (cVar1 != '\0') {
        *(char *)(param_2 + iVar2) = cVar1;
        cVar1 = ","[iVar2 + 1];
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
          cVar1 = s___97c2a324[0];
          while (cVar1 != '\0') {
            *(char *)(param_2 + iVar2) = cVar1;
            cVar1 = ","[iVar2 + 1];
            iVar2 = iVar2 + 1;
          }
        }
        else {
          if (iVar4 != 3) goto LAB_97be7cf4;
          uVar3 = *(uint *)(param_3 * 8 + param_1) & 0xf;
          iVar2 = 0;
          cVar1 = s___97c2a324[0];
          while (cVar1 != '\0') {
            *(char *)(param_2 + iVar2) = cVar1;
            cVar1 = ","[iVar2 + 1];
            iVar2 = iVar2 + 1;
          }
        }
        goto LAB_97be7cf0;
      }
      if (iVar4 == 0) {
        uVar3 = *(uint *)(param_3 * 8 + param_1) >> 0xc & 0xf;
        iVar2 = 0;
        cVar1 = s___97c2d7ec[0];
        while (cVar1 != '\0') {
          *(char *)(param_2 + iVar2) = cVar1;
          cVar1 = ", "[iVar2 + 1];
          iVar2 = iVar2 + 1;
        }
        goto LAB_97be7cf0;
      }
    }
LAB_97be7cf4:
    switch(uVar3) {
    case 0:
      iVar2 = 0;
      cVar1 = s_x_97c2d790[0];
      while (cVar1 != '\0') {
        *(char *)(param_2 + iVar2) = cVar1;
        cVar1 = "x"[iVar2 + 1];
        iVar2 = iVar2 + 1;
      }
      break;
    case 1:
      iVar2 = 0;
      cVar1 = s_y_97c2d794[0];
      while (cVar1 != '\0') {
        *(char *)(param_2 + iVar2) = cVar1;
        cVar1 = "y"[iVar2 + 1];
        iVar2 = iVar2 + 1;
      }
      break;
    case 2:
      iVar2 = 0;
      cVar1 = s_z_97c2d798[0];
      while (cVar1 != '\0') {
        *(char *)(param_2 + iVar2) = cVar1;
        cVar1 = "z"[iVar2 + 1];
        iVar2 = iVar2 + 1;
      }
      break;
    case 3:
      iVar2 = 0;
      cVar1 = s_w_97c2d79c[0];
      while (cVar1 != '\0') {
        *(char *)(param_2 + iVar2) = cVar1;
        cVar1 = "w"[iVar2 + 1];
        iVar2 = iVar2 + 1;
      }
      break;
    case 4:
      iVar2 = 0;
      cVar1 = s__x_97c2d7f0[0];
      while (cVar1 != '\0') {
        *(char *)(param_2 + iVar2) = cVar1;
        cVar1 = "-x"[iVar2 + 1];
        iVar2 = iVar2 + 1;
      }
      break;
    case 5:
      iVar2 = 0;
      cVar1 = s__y_97c2d7f4[0];
      while (cVar1 != '\0') {
        *(char *)(param_2 + iVar2) = cVar1;
        cVar1 = "-y"[iVar2 + 1];
        iVar2 = iVar2 + 1;
      }
      break;
    case 6:
      iVar2 = 0;
      cVar1 = s__z_97c2d7f8[0];
      while (cVar1 != '\0') {
        *(char *)(param_2 + iVar2) = cVar1;
        cVar1 = "-z"[iVar2 + 1];
        iVar2 = iVar2 + 1;
      }
      break;
    case 7:
      iVar2 = 0;
      cVar1 = s__w_97c2d7fc[0];
      while (cVar1 != '\0') {
        *(char *)(param_2 + iVar2) = cVar1;
        cVar1 = "-w"[iVar2 + 1];
        iVar2 = iVar2 + 1;
      }
      break;
    case 8:
      iVar2 = 0;
      cVar1 = s_1_97c2d760[0];
      while (cVar1 != '\0') {
        *(char *)(param_2 + iVar2) = cVar1;
        cVar1 = "1"[iVar2 + 1];
        iVar2 = iVar2 + 1;
      }
      break;
    case 9:
      iVar2 = 0;
      cVar1 = s_0_97c2d800[0];
      while (cVar1 != '\0') {
        *(char *)(param_2 + iVar2) = cVar1;
        cVar1 = "0"[iVar2 + 1];
        iVar2 = iVar2 + 1;
      }
      break;
    case 10:
      iVar2 = 0;
      cVar1 = s__1_97c2d804[0];
      while (cVar1 != '\0') {
        *(char *)(param_2 + iVar2) = cVar1;
        cVar1 = "-1"[iVar2 + 1];
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
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_7 * 8;
  if ((*(uint *)(iVar2 + param_1) & 0x8000000) != 0) {
    iVar3 = 0;
    cVar1 = s___97c2a2d4[0];
    while (cVar1 != '\0') {
      *(char *)(param_2 + iVar3) = cVar1;
      cVar1 = "-"[iVar3 + 1];
      iVar3 = iVar3 + 1;
    }
    param_2 = param_2 + iVar3;
  }
  if ((*(uint *)(iVar2 + param_1) & 0x4000000) != 0) {
    iVar3 = 0;
    cVar1 = s___97c2a31c[0];
    while (cVar1 != '\0') {
      *(char *)(param_2 + iVar3) = cVar1;
      cVar1 = "|"[iVar3 + 1];
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
    cVar1 = s___97c2a31c[0];
    while (cVar1 != '\0') {
      *(char *)(iVar3 + iVar2) = cVar1;
      cVar1 = "|"[iVar2 + 1];
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
  char cVar1;
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
    cVar1 = s__TR_97c2d7a0[0];
    while (cVar1 != '\0') {
      pcVar3[iVar2] = cVar1;
      cVar1 = " (TR"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 1:
    iVar2 = 0;
    cVar1 = s__EQ_97c2d7a8[0];
    while (cVar1 != '\0') {
      pcVar3[iVar2] = cVar1;
      cVar1 = " (EQ"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 2:
    iVar2 = 0;
    cVar1 = s__GE_97c2d7b0[0];
    while (cVar1 != '\0') {
      pcVar3[iVar2] = cVar1;
      cVar1 = " (GE"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 3:
    iVar2 = 0;
    cVar1 = s__GT_97c2d7b8[0];
    while (cVar1 != '\0') {
      pcVar3[iVar2] = cVar1;
      cVar1 = " (GT"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 4:
    iVar2 = 0;
    cVar1 = s__LE_97c2d7c0[0];
    while (cVar1 != '\0') {
      pcVar3[iVar2] = cVar1;
      cVar1 = " (LE"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 5:
    iVar2 = 0;
    cVar1 = s__LT_97c2d7c8[0];
    while (cVar1 != '\0') {
      pcVar3[iVar2] = cVar1;
      cVar1 = " (LT"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 6:
    iVar2 = 0;
    cVar1 = s__NE_97c2d7d0[0];
    while (cVar1 != '\0') {
      pcVar3[iVar2] = cVar1;
      cVar1 = " (NE"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 7:
    iVar2 = 0;
    cVar1 = s__FL_97c2d7d8[0];
    while (cVar1 != '\0') {
      pcVar3[iVar2] = cVar1;
      cVar1 = " (FL"[iVar2 + 1];
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
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  cVar1 = s_texture__97c2d814[0];
  while (cVar1 != '\0') {
    *(char *)(param_2 + iVar4) = cVar1;
    cVar1 = "texture["[iVar4 + 1];
    iVar4 = iVar4 + 1;
  }
  iVar4 = param_2 + iVar4;
  if (param_8 == 0) {
    iVar2 = param_7 * 8;
    iVar3 = ((int (*)())_ncpy_97be5f58)(iVar4,*(uint *)(iVar2 + param_1) & 0x1f);
    iVar4 = iVar4 + iVar3;
  }
  else {
    iVar4 = ((int (*)())_glpWriteSourceOperand_97be7fc0)(param_1,iVar4,param_3,param_4,param_5,param_6,param_7,1)
    ;
    iVar2 = (param_7 + 1) * 8;
  }
  iVar3 = 0;
  cVar1 = s____97c2d820[0];
  while (cVar1 != '\0') {
    *(char *)(iVar4 + iVar3) = cVar1;
    cVar1 = "], "[iVar3 + 1];
    iVar3 = iVar3 + 1;
  }
  iVar4 = iVar4 + iVar3;
  switch(*(uint *)(iVar2 + param_1) >> 5 & 7) {
  case 0:
    iVar2 = 0;
    cVar1 = s_CUBE_97c2d830[0];
    while (cVar1 != '\0') {
      *(char *)(iVar4 + iVar2) = cVar1;
      cVar1 = "CUBE"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 1:
    iVar2 = 0;
    cVar1 = s_3D_97c2d82c[0];
    while (cVar1 != '\0') {
      *(char *)(iVar4 + iVar2) = cVar1;
      cVar1 = "3D"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 2:
    iVar2 = 0;
    cVar1 = s_RECT_97c2d838[0];
    while (cVar1 != '\0') {
      *(char *)(iVar4 + iVar2) = cVar1;
      cVar1 = "RECT"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 3:
    iVar2 = 0;
    cVar1 = s_2D_97c2d828[0];
    while (cVar1 != '\0') {
      *(char *)(iVar4 + iVar2) = cVar1;
      cVar1 = "2D"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 4:
    iVar2 = 0;
    cVar1 = s_1D_97c2d824[0];
    while (cVar1 != '\0') {
      *(char *)(iVar4 + iVar2) = cVar1;
      cVar1 = "1D"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 5:
    iVar2 = 0;
    cVar1 = s_SHADOWRECT_97c2d840[0];
    while (cVar1 != '\0') {
      *(char *)(iVar4 + iVar2) = cVar1;
      cVar1 = "SHADOWRECT"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 6:
    iVar2 = 0;
    cVar1 = s_SHADOW2D_97c2d84c[0];
    while (cVar1 != '\0') {
      *(char *)(iVar4 + iVar2) = cVar1;
      cVar1 = "SHADOW2D"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 7:
    iVar2 = 0;
    cVar1 = s_SHADOW1D_97c2d858[0];
    while (cVar1 != '\0') {
      *(char *)(iVar4 + iVar2) = cVar1;
      cVar1 = "SHADOW1D"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  default:
    goto switchD_97be857c_default;
  }
  iVar4 = iVar4 + iVar2;
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
  char cVar2;
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
      cVar2 = s__97c28c28[0];
      if (s__97c28c28[0] != '\0') {
        do {
          *(char *)(iVar14 + iVar5) = cVar2;
          iVar4 = iVar5 + 1;
          cVar2 = "  "[iVar5 + 1];
          iVar5 = iVar4;
        } while (cVar2 != '\0');
        iVar10 = *param_10;
      }
      iVar9 = iVar9 + 1;
      iVar14 = iVar14 + iVar4;
    } while (iVar9 < iVar10);
  }
  pcVar8 = *(char **)(&_ppstreamOpString + uVar11 * 4);
  iVar9 = 0;
  cVar2 = *pcVar8;
  while (cVar2 != '\0') {
    *(char *)(iVar14 + iVar9) = cVar2;
    iVar9 = iVar9 + 1;
    cVar2 = pcVar8[iVar9];
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
    cVar2 = s__97c291c0[0];
    while (cVar2 != '\0') {
      *(char *)(iVar14 + iVar9) = cVar2;
      cVar2 = " "[iVar9 + 1];
      iVar9 = iVar9 + 1;
    }
    iVar9 = ((int (*)())_glpWriteDestinationOperand_97be6730)(param_1,iVar14 + iVar9,param_7,param_8,1,uVar12);
    iVar14 = 0;
    cVar2 = s___97c2d7ec[0];
    while (cVar2 != '\0') {
      *(char *)(iVar9 + iVar14) = cVar2;
      cVar2 = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    puVar15 = (undefined1 *)
              ((int (*)())_glpWriteSourceOperand_97be7fc0)(param_1,iVar9 + iVar14,param_5,param_6,param_7,param_8,2,uVar12,0);
    iVar13 = 2;
    if (uVar1 >> 0x1d != 2) break;
    iVar14 = 0;
    cVar2 = s___97c2d7ec[0];
    while (cVar2 != '\0') {
      puVar15[iVar14] = cVar2;
      cVar2 = ", "[iVar14 + 1];
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
    cVar2 = s__97c291c0[0];
    while (cVar2 != '\0') {
      *(char *)(iVar14 + iVar9) = cVar2;
      cVar2 = " "[iVar9 + 1];
      iVar9 = iVar9 + 1;
    }
    iVar9 = ((int (*)())_glpWriteDestinationOperand_97be6730)(param_1,iVar14 + iVar9,param_7,param_8,1,uVar12);
    iVar14 = 0;
    cVar2 = s___97c2d7ec[0];
    while (cVar2 != '\0') {
      *(char *)(iVar9 + iVar14) = cVar2;
      cVar2 = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    puVar15 = (undefined1 *)
              ((int (*)())_glpWriteSourceOperand_97be7fc0)(param_1,iVar9 + iVar14,param_5,param_6,param_7,param_8,2,uVar12,0);
    iVar13 = 2;
    iVar14 = 0;
    cVar2 = s___97c2d7ec[0];
    while (cVar2 != '\0') {
      puVar15[iVar14] = cVar2;
      cVar2 = ", "[iVar14 + 1];
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
    cVar2 = s__97c291c0[0];
    while (cVar2 != '\0') {
      *(char *)(iVar14 + iVar9) = cVar2;
      cVar2 = " "[iVar9 + 1];
      iVar9 = iVar9 + 1;
    }
    iVar9 = ((int (*)())_glpWriteDestinationOperand_97be6730)(param_1,iVar14 + iVar9,param_7,param_8,1,uVar12);
    iVar14 = 0;
    cVar2 = s___97c2d7ec[0];
    while (cVar2 != '\0') {
      *(char *)(iVar9 + iVar14) = cVar2;
      cVar2 = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    iVar9 = ((int (*)())_glpWriteSourceOperand_97be7fc0)(param_1,iVar9 + iVar14,param_5,param_6,param_7,param_8,2,uVar12,0);
    iVar14 = 0;
    cVar2 = s___97c2d7ec[0];
    while (cVar2 != '\0') {
      *(char *)(iVar9 + iVar14) = cVar2;
      cVar2 = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    iVar13 = 3;
    puVar15 = (undefined1 *)
              ((int (*)())_glpWriteSourceOperand_97be7fc0)(param_1,iVar9 + iVar14,param_5,param_6,param_7,param_8,3,uVar12,0);
    iVar14 = 0;
    cVar2 = s___97c2d7ec[0];
    while (cVar2 != '\0') {
      puVar15[iVar14] = cVar2;
      cVar2 = ", "[iVar14 + 1];
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
    cVar2 = s__97c291c0[0];
    while (cVar2 != '\0') {
      *(char *)(iVar14 + iVar9) = cVar2;
      cVar2 = " "[iVar9 + 1];
      iVar9 = iVar9 + 1;
    }
    iVar9 = ((int (*)())_glpWriteDestinationOperand_97be6730)(param_1,iVar14 + iVar9,param_7,param_8,1,uVar12);
    iVar14 = 0;
    cVar2 = s___97c2d7ec[0];
    while (cVar2 != '\0') {
      *(char *)(iVar9 + iVar14) = cVar2;
      cVar2 = ", "[iVar14 + 1];
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
    cVar2 = s__97c291c0[0];
    while (cVar2 != '\0') {
      *(char *)(iVar14 + iVar9) = cVar2;
      cVar2 = " "[iVar9 + 1];
      iVar9 = iVar9 + 1;
    }
    iVar9 = ((int (*)())_glpWriteDestinationOperand_97be6730)(param_1,iVar14 + iVar9,param_7,param_8,1,uVar12);
    iVar14 = 0;
    cVar2 = s___97c2d7ec[0];
    while (cVar2 != '\0') {
      *(char *)(iVar9 + iVar14) = cVar2;
      cVar2 = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    iVar9 = ((int (*)())_glpWriteSourceOperand_97be7fc0)(param_1,iVar9 + iVar14,param_5,param_6,param_7,param_8,2,uVar12,0);
    iVar10 = 2;
    iVar14 = 0;
    cVar2 = s___97c2d7ec[0];
    while (cVar2 != '\0') {
      *(char *)(iVar9 + iVar14) = cVar2;
      cVar2 = ", "[iVar14 + 1];
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
    cVar2 = s__97c291c0[0];
    while (cVar2 != '\0') {
      *(char *)(iVar14 + iVar9) = cVar2;
      cVar2 = " "[iVar9 + 1];
      iVar9 = iVar9 + 1;
    }
    iVar9 = ((int (*)())_glpWriteDestinationOperand_97be6730)(param_1,iVar14 + iVar9,param_7,param_8,1,uVar12);
    iVar14 = 0;
    cVar2 = s___97c2d7ec[0];
    while (cVar2 != '\0') {
      *(char *)(iVar9 + iVar14) = cVar2;
      cVar2 = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    iVar9 = ((int (*)())_glpWriteSourceOperand_97be7fc0)(param_1,iVar9 + iVar14,param_5,param_6,param_7,param_8,2,uVar12,0);
    iVar14 = 0;
    cVar2 = s___97c2d7ec[0];
    while (cVar2 != '\0') {
      *(char *)(iVar9 + iVar14) = cVar2;
      cVar2 = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    puVar15 = (undefined1 *)
              ((int (*)())_glpWriteTextureOperand_97be8478)(param_1,iVar9 + iVar14,param_5,param_6,param_7,param_8,3,uVar12);
    iVar13 = 3 - ((int)-uVar12 >> 0x1f);
    if (uVar12 == 0) break;
    iVar14 = 0;
    cVar2 = s___97c2d7ec[0];
    while (cVar2 != '\0') {
      puVar15[iVar14] = cVar2;
      cVar2 = ", "[iVar14 + 1];
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
    cVar2 = s__97c291c0[0];
    while (cVar2 != '\0') {
      puVar15[iVar14] = cVar2;
      cVar2 = " "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    iVar9 = ((int (*)())_glpWriteAddressOperand)(param_1,puVar15 + iVar14,1,uVar12);
    iVar14 = 0;
    cVar2 = s___97c2d7ec[0];
    while (cVar2 != '\0') {
      *(char *)(iVar9 + iVar14) = cVar2;
      cVar2 = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
LAB_97be9928:
    puVar15 = (undefined1 *)(iVar9 + iVar14);
    goto LAB_97be99b4;
  case 0x4b:
  case 0x4c:
    iVar14 = 0;
    cVar2 = s__97c291c0[0];
    while (cVar2 != '\0') {
      puVar15[iVar14] = cVar2;
      cVar2 = " "[iVar14 + 1];
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
    cVar2 = s__97c291c0[0];
    while (cVar2 != '\0') {
      puVar15[iVar14] = cVar2;
      cVar2 = " "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    goto LAB_97be9988;
  case 0x55:
    *param_10 = *param_10 + 1;
    if (uVar12 != 0) {
      uVar1 = param_1[1];
      iVar9 = ((int (*)())_glpWriteSizeType)(puVar15,uVar1 >> 0x1a & 3,uVar1 >> 0x1c & 1,uVar1 >> 0x17 & 7);
      iVar14 = 0;
      cVar2 = s__97c291c0[0];
      while (cVar2 != '\0') {
        *(char *)(iVar9 + iVar14) = cVar2;
        cVar2 = " "[iVar14 + 1];
        iVar14 = iVar14 + 1;
      }
      goto LAB_97be9928;
    }
    iVar13 = 1;
    switch(param_1[2] >> 0x1c & 7) {
    case 0:
      iVar14 = 0;
      cVar2 = s_TR_97c2d864[0];
      while (cVar2 != '\0') {
        puVar15[iVar14] = cVar2;
        cVar2 = " TR"[iVar14 + 1];
        iVar14 = iVar14 + 1;
      }
      break;
    case 1:
      iVar14 = 0;
      cVar2 = s_EQ_97c2d868[0];
      while (cVar2 != '\0') {
        puVar15[iVar14] = cVar2;
        cVar2 = " EQ"[iVar14 + 1];
        iVar14 = iVar14 + 1;
      }
      break;
    case 2:
      iVar14 = 0;
      cVar2 = s_GE_97c2d86c[0];
      while (cVar2 != '\0') {
        puVar15[iVar14] = cVar2;
        cVar2 = " GE"[iVar14 + 1];
        iVar14 = iVar14 + 1;
      }
      break;
    case 3:
      iVar14 = 0;
      cVar2 = s_GT_97c2d870[0];
      while (cVar2 != '\0') {
        puVar15[iVar14] = cVar2;
        cVar2 = " GT"[iVar14 + 1];
        iVar14 = iVar14 + 1;
      }
      break;
    case 4:
      iVar14 = 0;
      cVar2 = s_LE_97c2d874[0];
      while (cVar2 != '\0') {
        puVar15[iVar14] = cVar2;
        cVar2 = " LE"[iVar14 + 1];
        iVar14 = iVar14 + 1;
      }
      break;
    case 5:
      iVar14 = 0;
      cVar2 = s_LT_97c2d878[0];
      while (cVar2 != '\0') {
        puVar15[iVar14] = cVar2;
        cVar2 = " LT"[iVar14 + 1];
        iVar14 = iVar14 + 1;
      }
      break;
    case 6:
      iVar14 = 0;
      cVar2 = s_NE_97c2d87c[0];
      while (cVar2 != '\0') {
        puVar15[iVar14] = cVar2;
        cVar2 = " NE"[iVar14 + 1];
        iVar14 = iVar14 + 1;
      }
      break;
    case 7:
      iVar14 = 0;
      cVar2 = s_FL_97c2d880[0];
      while (cVar2 != '\0') {
        puVar15[iVar14] = cVar2;
        cVar2 = " FL"[iVar14 + 1];
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
    cVar2 = s__97c291c0[0];
    while (cVar2 != '\0') {
      puVar15[iVar14] = cVar2;
      cVar2 = " "[iVar14 + 1];
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
    cVar2 = s__97c291c0[0];
    while (cVar2 != '\0') {
      puVar15[iVar14] = cVar2;
      cVar2 = " "[iVar14 + 1];
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
    cVar2 = s__97c291c0[0];
    while (cVar2 != '\0') {
      *(char *)(iVar14 + iVar9) = cVar2;
      cVar2 = " "[iVar9 + 1];
      iVar9 = iVar9 + 1;
    }
    iVar9 = ((int (*)())_glpWriteDestinationOperand_97be6730)(param_1,iVar14 + iVar9,param_7,param_8,1,uVar12);
    iVar14 = 0;
    cVar2 = s___97c2d7ec[0];
    while (cVar2 != '\0') {
      *(char *)(iVar9 + iVar14) = cVar2;
      cVar2 = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    iVar9 = ((int (*)())_glpWriteSourceOperand_97be7fc0)(param_1,iVar9 + iVar14,param_5,param_6,param_7,param_8,2,uVar12,0);
    iVar14 = 0;
    cVar2 = s___97c2d7ec[0];
    while (cVar2 != '\0') {
      *(char *)(iVar9 + iVar14) = cVar2;
      cVar2 = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    iVar9 = ((int (*)())_glpWriteSourceOperand_97be7fc0)(param_1,iVar9 + iVar14,param_5,param_6,param_7,param_8,3,uVar12,0);
    iVar14 = 0;
    cVar2 = s___97c2d7ec[0];
    while (cVar2 != '\0') {
      *(char *)(iVar9 + iVar14) = cVar2;
      cVar2 = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    iVar10 = 4;
    iVar9 = ((int (*)())_glpWriteSourceOperand_97be7fc0)(param_1,iVar9 + iVar14,param_5,param_6,param_7,param_8,4,uVar12,0);
    iVar14 = 0;
    cVar2 = s___97c2d7ec[0];
    while (cVar2 != '\0') {
      *(char *)(iVar9 + iVar14) = cVar2;
      cVar2 = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
LAB_97be9848:
    puVar15 = (undefined1 *)
              ((int (*)())_glpWriteTextureOperand_97be8478)(param_1,iVar9 + iVar14,param_5,param_6,param_7,param_8,iVar10 + 1,uVar12);
    iVar13 = (iVar10 + 1) - ((int)-uVar12 >> 0x1f);
  }
  iVar14 = 0;
  cVar2 = s___97c2d884[0];
  while (cVar2 != '\0') {
    puVar15[iVar14] = cVar2;
    cVar2 = ";"[iVar14 + 1];
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
  cVar2 = s__97c26c38[0];
  while (cVar2 != '\0') {
    pcVar8[iVar14] = cVar2;
    cVar2 = "\n"[iVar14 + 1];
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
double _glpPPDisassemble(uint *param_1)
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  byte bVar5;
  char cVar8;
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
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 extraout_r4_03;
  undefined4 extraout_r4_04;
  undefined4 extraout_r4_05;
  undefined4 extraout_r4_06;
  undefined4 extraout_r4_07;
  undefined1 *puVar17;
  uint uVar18;
  uint uVar19;
  uint *puVar20;
  int iVar21;
  uint uVar22;
  float *pfVar23;
  byte in_xer_so;
  uint uVar24;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  double extraout_f1_02;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  undefined8 uVar25;
  double in_stack_fffffd08;
  double in_stack_fffffd10;
  double in_stack_fffffd18;
  double in_stack_fffffd20;
  double in_stack_fffffd28;
  char local_2b0;
  char acStack_2af [255];
  char local_1b0 [256];
  int local_b0;
  int *local_ac;
  int *local_a8;
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
  
  local_b0 = 0x800;
  local_9c = 1;
  local_ac = (int *)_malloc(0x800);
  uVar25 = CONCAT44(local_ac,extraout_r4);
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
  if (local_ac == (int *)0x0) {
    return extraout_f1;
  }
  uVar18 = *param_1;
  local_64 = (uint)(uVar18 - 0x8b30 < 2);
  if (uVar18 == 0x8804) {
    cVar8 = '!';
    iVar21 = 0;
    do {
      *(char *)((int)local_ac + iVar21) = cVar8;
      iVar9 = iVar21 + 1;
      cVar8 = "!!ARBfp1.0\n"[iVar21 + 1];
      iVar21 = iVar9;
    } while (cVar8 != '\0');
  }
  else if (uVar18 < 0x8805) {
    if (uVar18 == 0x8620) {
      cVar8 = '!';
      iVar21 = 0;
      do {
        *(char *)((int)local_ac + iVar21) = cVar8;
        iVar9 = iVar21 + 1;
        cVar8 = "!!ARBvp1.0\n"[iVar21 + 1];
        iVar21 = iVar9;
      } while (cVar8 != '\0');
    }
    else {
LAB_97be9f08:
      cVar8 = 'U';
      iVar21 = 0;
      do {
        *(char *)((int)local_ac + iVar21) = cVar8;
        iVar9 = iVar21 + 1;
        cVar8 = "Unkown Target (error)\n"[iVar21 + 1];
        iVar21 = iVar9;
      } while (cVar8 != '\0');
    }
  }
  else if (uVar18 == 0x8b30) {
    cVar8 = '!';
    iVar21 = 0;
    do {
      *(char *)((int)local_ac + iVar21) = cVar8;
      iVar9 = iVar21 + 1;
      cVar8 = "!!ARBfragmentshader\n"[iVar21 + 1];
      iVar21 = iVar9;
    } while (cVar8 != '\0');
  }
  else {
    if (uVar18 != 0x8b31) goto LAB_97be9f08;
    cVar8 = '!';
    iVar21 = 0;
    do {
      *(char *)((int)local_ac + iVar21) = cVar8;
      iVar9 = iVar21 + 1;
      cVar8 = "!!ARBvertexshader\n"[iVar21 + 1];
      iVar21 = iVar9;
    } while (cVar8 != '\0');
  }
  local_a8 = (int *)((int)local_ac + iVar9);
  bVar2 = local_64 == 0;
  if (!bVar2) {
    cVar8 = '\n';
    iVar21 = 0;
    do {
      *(char *)((int)local_a8 + iVar21) = cVar8;
      iVar9 = iVar21 + 1;
      cVar8 = "\n"[iVar21 + 1];
      iVar21 = iVar9;
    } while (cVar8 != '\0');
    local_a8 = (int *)((int)local_a8 + iVar9);
  }
  uVar19 = param_1[0x12];
  iVar21 = 0;
  uVar6 = param_1[0x13];
  if (0 < (int)uVar19) {
    local_60 = "o intialize the Preprocessor";
    do {
      cVar8 = 'O';
      iVar9 = 0;
      do {
        *(char *)((int)local_a8 + iVar9) = cVar8;
        iVar10 = iVar9 + 1;
        cVar8 = "OPTION "[iVar9 + 1];
        iVar9 = iVar10;
      } while (cVar8 != '\0');
      puVar17 = (undefined1 *)((int)local_a8 + iVar10);
      switch(param_1[uVar6 * 2 + iVar21 * 2] & 0xff) {
      case 0:
        cVar8 = 'A';
        iVar9 = 0;
        do {
          puVar17[iVar9] = cVar8;
          iVar10 = iVar9 + 1;
          cVar8 = "ARB_position_invariant"[iVar9 + 1];
          iVar9 = iVar10;
        } while (cVar8 != '\0');
        break;
      case 1:
        cVar8 = 'A';
        iVar9 = 0;
        do {
          puVar17[iVar9] = cVar8;
          iVar10 = iVar9 + 1;
          cVar8 = "ARB_fog_exp"[iVar9 + 1];
          iVar9 = iVar10;
        } while (cVar8 != '\0');
        break;
      case 2:
        cVar8 = 'A';
        iVar9 = 0;
        do {
          puVar17[iVar9] = cVar8;
          iVar10 = iVar9 + 1;
          cVar8 = "ARB_fog_exp2"[iVar9 + 1];
          iVar9 = iVar10;
        } while (cVar8 != '\0');
        break;
      case 3:
        cVar8 = 'A';
        iVar9 = 0;
        do {
          puVar17[iVar9] = cVar8;
          iVar10 = iVar9 + 1;
          cVar8 = "ARB_fog_linear"[iVar9 + 1];
          iVar9 = iVar10;
        } while (cVar8 != '\0');
        break;
      case 4:
        cVar8 = 'A';
        iVar9 = 0;
        do {
          puVar17[iVar9] = cVar8;
          iVar10 = iVar9 + 1;
          cVar8 = "ARB_precision_hint_fastest"[iVar9 + 1];
          iVar9 = iVar10;
        } while (cVar8 != '\0');
        break;
      case 5:
        cVar8 = 'A';
        iVar9 = 0;
        do {
          puVar17[iVar9] = cVar8;
          iVar10 = iVar9 + 1;
          cVar8 = "ARB_precision_hint_nicest"[iVar9 + 1];
          iVar9 = iVar10;
        } while (cVar8 != '\0');
        break;
      case 6:
        cVar8 = 'A';
        iVar9 = 0;
        do {
          puVar17[iVar9] = cVar8;
          iVar10 = iVar9 + 1;
          cVar8 = "APPLE_no_runtime_compile"[iVar9 + 1];
          iVar9 = iVar10;
        } while (cVar8 != '\0');
        break;
      case 7:
        cVar8 = 'A';
        iVar9 = 0;
        do {
          puVar17[iVar9] = cVar8;
          iVar10 = iVar9 + 1;
          cVar8 = "APPLE_no_altivec"[iVar9 + 1];
          iVar9 = iVar10;
        } while (cVar8 != '\0');
        break;
      case 8:
        cVar8 = 'N';
        iVar9 = 0;
        do {
          puVar17[iVar9] = cVar8;
          iVar10 = iVar9 + 1;
          cVar8 = "NV_fragment_program"[iVar9 + 1];
          iVar9 = iVar10;
        } while (cVar8 != '\0');
        break;
      case 9:
        cVar8 = 'N';
        iVar9 = 0;
        do {
          puVar17[iVar9] = cVar8;
          iVar10 = iVar9 + 1;
          cVar8 = "NV_fragment_program2"[iVar9 + 1];
          iVar9 = iVar10;
        } while (cVar8 != '\0');
        break;
      case 10:
        cVar8 = 'N';
        iVar9 = 0;
        do {
          puVar17[iVar9] = cVar8;
          iVar10 = iVar9 + 1;
          cVar8 = "NV_vertex_program2"[iVar9 + 1];
          iVar9 = iVar10;
        } while (cVar8 != '\0');
        break;
      case 0xb:
        cVar8 = 'N';
        iVar9 = 0;
        do {
          puVar17[iVar9] = cVar8;
          iVar10 = iVar9 + 1;
          cVar8 = "NV_vertex_program3"[iVar9 + 1];
          iVar9 = iVar10;
        } while (cVar8 != '\0');
        break;
      case 0xc:
        cVar8 = 'A';
        iVar9 = 0;
        do {
          puVar17[iVar9] = cVar8;
          iVar10 = iVar9 + 1;
          cVar8 = "ARB_draw_buffers"[iVar9 + 1];
          iVar9 = iVar10;
        } while (cVar8 != '\0');
        break;
      case 0xd:
        cVar8 = 'A';
        iVar9 = 0;
        do {
          puVar17[iVar9] = cVar8;
          iVar10 = iVar9 + 1;
          cVar8 = "ARB_fragment_program_shadow"[iVar9 + 1];
          iVar9 = iVar10;
        } while (cVar8 != '\0');
        break;
      default:
        goto switchD_97bea038_default;
      }
      puVar17 = puVar17 + iVar10;
switchD_97bea038_default:
      iVar9 = 0;
      cVar8 = local_60[0x3bbc];
      while (cVar8 != '\0') {
        puVar17[iVar9] = cVar8;
        iVar9 = iVar9 + 1;
        cVar8 = (local_60 + 0x3bbc)[iVar9];
      }
      local_a8 = (int *)(puVar17 + iVar9);
      uVar25 = ((int (*)())_adjustAllocation_97be9cb4)(&local_b0,&local_ac,&local_a8);
      if ((int)((ulonglong)uVar25 >> 0x20) == 0) goto LAB_97bf0cec;
      iVar21 = iVar21 + 1;
    } while (iVar21 < (int)uVar19);
  }
  if ((uVar19 != 0) && (!bVar2)) {
    cVar8 = '\n';
    iVar21 = 0;
    do {
      *(char *)((int)local_a8 + iVar21) = cVar8;
      iVar9 = iVar21 + 1;
      cVar8 = "\n"[iVar21 + 1];
      iVar21 = iVar9;
    } while (cVar8 != '\0');
    local_a8 = (int *)((int)local_a8 + iVar9);
  }
  uVar6 = param_1[6];
  if (uVar6 != 0) {
    cVar8 = 'A';
    iVar21 = 0;
    do {
      *(char *)((int)local_a8 + iVar21) = cVar8;
      iVar9 = iVar21 + 1;
      cVar8 = "ADDRESS adr0"[iVar21 + 1];
      iVar21 = iVar9;
    } while (cVar8 != '\0');
    iVar21 = 1;
    puVar17 = (undefined1 *)((int)local_a8 + iVar9);
    if (1 < (int)uVar6) {
      do {
        cVar8 = ',';
        iVar9 = 0;
        do {
          puVar17[iVar9] = cVar8;
          iVar10 = iVar9 + 1;
          cVar8 = ", adr"[iVar9 + 1];
          iVar9 = iVar10;
        } while (cVar8 != '\0');
        local_a8 = (int *)(puVar17 + iVar10);
        iVar9 = iVar21 + 1;
        iVar21 = ((int (*)())_ncpy_97be5f58)(local_a8,iVar21);
        puVar17 = (undefined1 *)((int)local_a8 + iVar21);
        iVar21 = iVar9;
      } while (iVar9 < (int)uVar6);
    }
    cVar8 = ';';
    iVar21 = 0;
    do {
      puVar17[iVar21] = cVar8;
      iVar9 = iVar21 + 1;
      cVar8 = ";\n"[iVar21 + 1];
      iVar21 = iVar9;
    } while (cVar8 != '\0');
    local_a8 = (int *)(puVar17 + iVar9);
    uVar25 = ((int (*)())_adjustAllocation_97be9cb4)(&local_b0,&local_ac,&local_a8);
    if ((int)((ulonglong)uVar25 >> 0x20) == 0) goto LAB_97bf0cec;
    if (!bVar2) {
      cVar8 = '\n';
      iVar21 = 0;
      do {
        *(char *)((int)local_a8 + iVar21) = cVar8;
        iVar9 = iVar21 + 1;
        cVar8 = "\n"[iVar21 + 1];
        iVar21 = iVar9;
      } while (cVar8 != '\0');
      local_a8 = (int *)((int)local_a8 + iVar9);
    }
  }
  uVar16 = (undefined4)uVar25;
  uVar6 = 0;
  bVar3 = true;
  uVar19 = param_1[4];
  puVar20 = param_1 + param_1[5] * 2;
  if (!bVar2) {
    uVar22 = 0xffffffff;
    if ((int)uVar19 < 1) {
LAB_97bea680:
      local_5c = (uint)(byte)((local_80 < 0) << 3 | (0 < local_80) << 2 | (local_80 == 0) << 1 |
                             in_xer_so & 1) << 0x1c;
      local_58 = local_5c;
LAB_97bea698:
      local_78 = (int *)0x0;
      if (param_1[0x10] != 0) {
        local_78 = (int *)_malloc(param_1[0x10] << 2);
        uVar16 = extraout_r4_01;
      }
      uVar25 = CONCAT44(local_78,uVar16);
      iVar21 = 0;
      iVar9 = -1;
      local_a4 = 0xffffffff;
      uVar22 = 0xffffffff;
      if (0 < (int)uVar19) {
        iVar10 = 0;
        piVar15 = local_78;
        puVar11 = puVar20;
        do {
          if (uVar22 == 0xffffffff) {
            *(uint *)((uint)*(ushort *)((int)puVar11 + 6) * 4 + local_80) =
                 (uint)*(ushort *)((int)puVar11 + 6);
            uVar25 = ((int (*)())_isTempArrayStart)(param_1,(uint)*(ushort *)((int)puVar11 + 6),&local_a4);
            if ((int)((ulonglong)uVar25 >> 0x20) == 0) {
              *(int *)(local_7c + (uint)*(ushort *)((int)puVar11 + 6) * 4) = iVar9;
            }
            else {
              uVar22 = (uint)*(ushort *)((int)puVar11 + 6);
              *(undefined4 *)(local_7c + uVar22 * 4) = 0;
              iVar9 = 1;
            }
            bVar1 = *(ushort *)((int)puVar20 + iVar10 + 6) == local_a4;
LAB_97bea790:
            if (bVar1) {
              local_a4 = 0xffffffff;
              uVar22 = 0xffffffff;
              *piVar15 = iVar9;
              piVar15 = piVar15 + 1;
              iVar9 = -1;
            }
          }
          else if ((int)(uint)*(ushort *)((int)puVar11 + 6) <= (int)local_a4) {
            *(uint *)((uint)*(ushort *)((int)puVar11 + 6) * 4 + local_80) = uVar22;
            *(int *)(local_7c + (uint)*(ushort *)((int)puVar11 + 6) * 4) = iVar9;
            iVar9 = iVar9 + 1;
            bVar1 = *(ushort *)((int)puVar11 + 6) == local_a4;
            goto LAB_97bea790;
          }
          iVar21 = iVar21 + 1;
          iVar10 = iVar10 + 8;
          puVar11 = puVar11 + 2;
        } while (iVar21 < (int)uVar19);
      }
      local_90 = 0;
      goto LAB_97bea7e0;
    }
    puVar11 = puVar20 + 1;
    uVar24 = uVar19;
    do {
      uVar7 = *puVar11;
      puVar11 = puVar11 + 2;
      if ((int)uVar22 < (int)(uVar7 & 0xffff)) {
        uVar22 = uVar7 & 0xffff;
      }
      uVar24 = uVar24 - 1;
    } while (uVar24 != 0);
    if (uVar22 == 0xffffffff) goto LAB_97bea680;
    iVar21 = uVar22 * 4 + 4;
    local_80 = _malloc(iVar21);
    local_5c = (uint)(byte)((local_80 < 0) << 3 | (0 < local_80) << 2 | (local_80 == 0) << 1 |
                           in_xer_so & 1) << 0x1c;
    local_7c = _malloc(iVar21);
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
    iVar21 = local_7c;
    if (!(bool)((byte)((uint)local_58 >> 0x1d) & 1)) {
LAB_97bee10c:
      _free(iVar21);
    }
LAB_97bf0cec:
    _free(local_ac);
    return extraout_f1_01;
  }
  local_5c = (uint)(byte)((local_80 < 0) << 3 | (0 < local_80) << 2 | (local_80 == 0) << 1 |
                         in_xer_so & 1) << 0x1c;
  local_58 = local_5c;
LAB_97bea7e0:
  uVar22 = 0;
  local_8c = -1;
  if (0 < (int)uVar19) {
    do {
      iVar21 = uVar22 * 8;
      if (bVar3) {
        uVar6 = puVar20[uVar22 * 2] >> 0x1d;
        if (uVar6 == 1) {
          cVar8 = 'L';
          iVar9 = 0;
          do {
            *(char *)((int)local_a8 + iVar9) = cVar8;
            iVar10 = iVar9 + 1;
            cVar8 = "LONG TEMP "[iVar9 + 1];
            iVar9 = iVar10;
          } while (cVar8 != '\0');
LAB_97bea920:
          local_a8 = (int *)((int)local_a8 + iVar10);
        }
        else if (uVar6 < 2) {
          if (uVar6 == 0) {
            cVar8 = 'T';
            iVar9 = 0;
            do {
              *(char *)((int)local_a8 + iVar9) = cVar8;
              iVar10 = iVar9 + 1;
              cVar8 = "TEMP "[iVar9 + 1];
              iVar9 = iVar10;
            } while (cVar8 != '\0');
            goto LAB_97bea920;
          }
        }
        else if (uVar6 == 2) {
          cVar8 = 'S';
          iVar9 = 0;
          do {
            *(char *)((int)local_a8 + iVar9) = cVar8;
            iVar10 = iVar9 + 1;
            cVar8 = "SHORT TEMP "[iVar9 + 1];
            iVar9 = iVar10;
          } while (cVar8 != '\0');
          goto LAB_97bea920;
        }
        bVar3 = false;
        uVar6 = puVar20[uVar22 * 2] >> 0x1d;
      }
      if (bVar2) {
        cVar8 = 't';
        iVar9 = 0;
        do {
          *(char *)((int)local_a8 + iVar9) = cVar8;
          iVar10 = iVar9 + 1;
          cVar8 = "tmp"[iVar9 + 1];
          iVar9 = iVar10;
        } while (cVar8 != '\0');
        local_a8 = (int *)((int)local_a8 + iVar10);
        iVar21 = ((int (*)())_ncpy_97be5f58)(local_a8,(uint)*(ushort *)((int)puVar20 + iVar21 + 6));
        local_a8 = (int *)((int)local_a8 + iVar21);
      }
      else {
        iVar9 = *(int *)(local_7c + (uint)*(ushort *)((int)puVar20 + iVar21 + 6) * 4);
        if (iVar9 == -1) {
          cVar8 = 't';
          iVar9 = 0;
          do {
            *(char *)((int)local_a8 + iVar9) = cVar8;
            iVar10 = iVar9 + 1;
            cVar8 = "tmp"[iVar9 + 1];
            iVar9 = iVar10;
          } while (cVar8 != '\0');
          local_a8 = (int *)((int)local_a8 + iVar10);
          iVar21 = ((int (*)())_ncpy_97be5f58)(local_a8,*(undefined4 *)
                                            (local_80 +
                                            (uint)*(ushort *)((int)puVar20 + iVar21 + 6) * 4));
          local_a8 = (int *)((int)local_a8 + iVar21);
          uVar24 = puVar20[uVar22 * 2];
          local_a8 = (int *)((int (*)())_glpWriteSizeTypePrecision)(local_a8,uVar24 >> 0x18 & 3,0,uVar24 >> 0x1a & 7,
                                       uVar24 >> 0x1d);
        }
        else {
          if (iVar9 == 0) {
            cVar8 = 't';
            local_8c = 0;
            iVar9 = 0;
            do {
              *(char *)((int)local_a8 + iVar9) = cVar8;
              iVar10 = iVar9 + 1;
              cVar8 = "tmp"[iVar9 + 1];
              iVar9 = iVar10;
            } while (cVar8 != '\0');
            local_a8 = (int *)((int)local_a8 + iVar10);
            iVar9 = ((int (*)())_ncpy_97be5f58)(local_a8,*(undefined4 *)
                                             (local_80 +
                                             (uint)*(ushort *)((int)puVar20 + iVar21 + 6) * 4));
            cVar8 = '[';
            iVar21 = 0;
            do {
              *(char *)((int)local_a8 + iVar21 + iVar9) = cVar8;
              iVar10 = iVar21 + 1;
              cVar8 = "["[iVar21 + 1];
              iVar21 = iVar10;
            } while (cVar8 != '\0');
            local_a8 = (int *)((int)local_a8 + iVar10 + iVar9);
            iVar21 = local_90 * 4;
            iVar10 = ((int (*)())_ncpy_97be5f58)(local_a8,local_78[local_90]);
            cVar8 = ']';
            iVar9 = 0;
            do {
              *(char *)((int)local_a8 + iVar9 + iVar10) = cVar8;
              iVar12 = iVar9 + 1;
              cVar8 = "]"[iVar9 + 1];
              iVar9 = iVar12;
            } while (cVar8 != '\0');
            local_a8 = (int *)((int)local_a8 + iVar12 + iVar10);
            uVar24 = puVar20[uVar22 * 2];
            local_a8 = (int *)((int (*)())_glpWriteSizeTypePrecision)(local_a8,uVar24 >> 0x18 & 3,0,uVar24 >> 0x1a & 7,
                                         uVar24 >> 0x1d);
          }
          else {
            local_8c = local_8c + 1;
            iVar21 = local_90 << 2;
          }
          if (local_8c + 1 == *(int *)(iVar21 + (int)local_78)) {
            local_8c = -1;
            local_90 = local_90 + 1;
          }
        }
      }
      uVar24 = uVar22 + 1;
      if (uVar24 == uVar19) {
        cVar8 = ';';
        iVar21 = 0;
        do {
          *(char *)((int)local_a8 + iVar21) = cVar8;
          iVar9 = iVar21 + 1;
          cVar8 = ";\n"[iVar21 + 1];
          iVar21 = iVar9;
        } while (cVar8 != '\0');
LAB_97beacc8:
        local_a8 = (int *)((int)local_a8 + iVar9);
      }
      else {
        if (puVar20[uVar22 * 2 + 2] >> 0x1d != uVar6) {
          local_60 = "o intialize the Preprocessor";
          cVar8 = ';';
          iVar21 = 0;
          do {
            *(char *)((int)local_a8 + iVar21) = cVar8;
            iVar9 = iVar21 + 1;
            cVar8 = ";\n"[iVar21 + 1];
            iVar21 = iVar9;
          } while (cVar8 != '\0');
          bVar3 = true;
          goto LAB_97beacc8;
        }
        if (local_8c == -1) {
          cVar8 = ',';
          iVar21 = 0;
          do {
            *(char *)((int)local_a8 + iVar21) = cVar8;
            iVar9 = iVar21 + 1;
            cVar8 = ", "[iVar21 + 1];
            iVar21 = iVar9;
          } while (cVar8 != '\0');
          goto LAB_97beacc8;
        }
      }
      uVar25 = ((int (*)())_adjustAllocation_97be9cb4)(&local_b0,&local_ac,&local_a8);
      if ((int)((ulonglong)uVar25 >> 0x20) == 0) goto LAB_97bf0c18;
      uVar22 = uVar24;
    } while ((int)uVar24 < (int)uVar19);
  }
  if (local_78 != (int *)0x0) {
    _free(local_78);
    uVar25 = CONCAT44(extraout_r3,extraout_r4_02);
  }
  if ((uVar19 != 0) && (!bVar2)) {
    cVar8 = '\n';
    iVar21 = 0;
    do {
      *(char *)((int)local_a8 + iVar21) = cVar8;
      iVar9 = iVar21 + 1;
      cVar8 = "\n"[iVar21 + 1];
      iVar21 = iVar9;
    } while (cVar8 != '\0');
    local_a8 = (int *)((int)local_a8 + iVar9);
  }
  uVar19 = param_1[8];
  iVar21 = 0;
  uVar6 = param_1[9];
  if (0 < (int)uVar19) {
    do {
      uVar22 = param_1[uVar6 * 2 + iVar21 * 2] >> 0x10 & 0xf;
      if (uVar22 != 0) {
        cVar8 = 'A';
        iVar9 = 0;
        do {
          *(char *)((int)local_a8 + iVar9) = cVar8;
          iVar10 = iVar9 + 1;
          cVar8 = "ATTRIB att"[iVar9 + 1];
          iVar9 = iVar10;
        } while (cVar8 != '\0');
        local_a8 = (int *)((int)local_a8 + iVar10);
        iVar9 = ((int (*)())_ncpy_97be5f58)(local_a8,(uint)*(ushort *)((int)param_1 + iVar21 * 8 + uVar6 * 8 + 6)
                              );
        local_a8 = (int *)((int)local_a8 + iVar9);
        if (!bVar2) {
          uVar24 = param_1[uVar6 * 2 + iVar21 * 2];
          local_a8 = (int *)((int (*)())_glpWriteSizeTypePrecision)(local_a8,uVar24 >> 0x18 & 3,0,uVar24 >> 0x1a & 7,
                                       uVar24 >> 0x1d);
        }
        if (uVar18 == 0x8804) {
LAB_97beae94:
          cVar8 = ' ';
          iVar9 = 0;
          do {
            *(char *)((int)local_a8 + iVar9) = cVar8;
            iVar10 = iVar9 + 1;
            cVar8 = " = fragment."[iVar9 + 1];
            iVar9 = iVar10;
          } while (cVar8 != '\0');
LAB_97beaec8:
          local_a8 = (int *)((int)local_a8 + iVar10);
        }
        else {
          if (uVar18 < 0x8805) {
            uVar24 = 0x8620;
          }
          else {
            if (uVar18 == 0x8b30) goto LAB_97beae94;
            uVar24 = 0x8b31;
          }
          if (uVar18 == uVar24) {
            cVar8 = ' ';
            iVar9 = 0;
            do {
              *(char *)((int)local_a8 + iVar9) = cVar8;
              iVar10 = iVar9 + 1;
              cVar8 = " = vertex."[iVar9 + 1];
              iVar9 = iVar10;
            } while (cVar8 != '\0');
            goto LAB_97beaec8;
          }
        }
        switch(uVar22) {
        default:
          goto switchD_97beaef4_caseD_0;
        case 1:
          cVar8 = 'p';
          iVar9 = 0;
          do {
            *(char *)((int)local_a8 + iVar9) = cVar8;
            iVar10 = iVar9 + 1;
            cVar8 = "position"[iVar9 + 1];
            iVar9 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 2:
          cVar8 = 'c';
          iVar9 = 0;
          do {
            *(char *)((int)local_a8 + iVar9) = cVar8;
            iVar10 = iVar9 + 1;
            cVar8 = "color.primary"[iVar9 + 1];
            iVar9 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 3:
          cVar8 = 'c';
          iVar9 = 0;
          do {
            *(char *)((int)local_a8 + iVar9) = cVar8;
            iVar10 = iVar9 + 1;
            cVar8 = "color.secondary"[iVar9 + 1];
            iVar9 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 4:
          cVar8 = 'n';
          iVar9 = 0;
          do {
            *(char *)((int)local_a8 + iVar9) = cVar8;
            iVar10 = iVar9 + 1;
            cVar8 = "normal"[iVar9 + 1];
            iVar9 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 5:
          cVar8 = 'f';
          iVar9 = 0;
          do {
            *(char *)((int)local_a8 + iVar9) = cVar8;
            iVar10 = iVar9 + 1;
            cVar8 = "fogcoord"[iVar9 + 1];
            iVar9 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 6:
          cVar8 = 'w';
          iVar9 = 0;
          do {
            *(char *)((int)local_a8 + iVar9) = cVar8;
            iVar10 = iVar9 + 1;
            cVar8 = "weight["[iVar9 + 1];
            iVar9 = iVar10;
          } while (cVar8 != '\0');
          local_a8 = (int *)((int)local_a8 + iVar10);
          iVar9 = ((int (*)())_ncpy_97be5f58)(local_a8,param_1[uVar6 * 2 + iVar21 * 2] & 0x1f);
          cVar8 = ']';
          local_a8 = (int *)((int)local_a8 + iVar9);
          iVar9 = 0;
          do {
            *(char *)((int)local_a8 + iVar9) = cVar8;
            iVar10 = iVar9 + 1;
            cVar8 = "]"[iVar9 + 1];
            iVar9 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 7:
          cVar8 = 't';
          iVar9 = 0;
          do {
            *(char *)((int)local_a8 + iVar9) = cVar8;
            iVar10 = iVar9 + 1;
            cVar8 = "texcoord["[iVar9 + 1];
            iVar9 = iVar10;
          } while (cVar8 != '\0');
          local_a8 = (int *)((int)local_a8 + iVar10);
          iVar9 = ((int (*)())_ncpy_97be5f58)(local_a8,param_1[uVar6 * 2 + iVar21 * 2] & 0x1f);
          cVar8 = ']';
          local_a8 = (int *)((int)local_a8 + iVar9);
          iVar9 = 0;
          do {
            *(char *)((int)local_a8 + iVar9) = cVar8;
            iVar10 = iVar9 + 1;
            cVar8 = "]"[iVar9 + 1];
            iVar9 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 8:
          cVar8 = 'm';
          iVar9 = 0;
          do {
            *(char *)((int)local_a8 + iVar9) = cVar8;
            iVar10 = iVar9 + 1;
            cVar8 = "matrixindex["[iVar9 + 1];
            iVar9 = iVar10;
          } while (cVar8 != '\0');
          local_a8 = (int *)((int)local_a8 + iVar10);
          iVar9 = ((int (*)())_ncpy_97be5f58)(local_a8,param_1[uVar6 * 2 + iVar21 * 2] & 0x1f);
          cVar8 = ']';
          local_a8 = (int *)((int)local_a8 + iVar9);
          iVar9 = 0;
          do {
            *(char *)((int)local_a8 + iVar9) = cVar8;
            iVar10 = iVar9 + 1;
            cVar8 = "]"[iVar9 + 1];
            iVar9 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 9:
          cVar8 = 'a';
          iVar9 = 0;
          do {
            *(char *)((int)local_a8 + iVar9) = cVar8;
            iVar10 = iVar9 + 1;
            cVar8 = "attrib["[iVar9 + 1];
            iVar9 = iVar10;
          } while (cVar8 != '\0');
          local_a8 = (int *)((int)local_a8 + iVar10);
          iVar9 = ((int (*)())_ncpy_97be5f58)(local_a8,param_1[uVar6 * 2 + iVar21 * 2] & 0x1f);
          cVar8 = ']';
          local_a8 = (int *)((int)local_a8 + iVar9);
          iVar9 = 0;
          do {
            *(char *)((int)local_a8 + iVar9) = cVar8;
            iVar10 = iVar9 + 1;
            cVar8 = "]"[iVar9 + 1];
            iVar9 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 10:
          cVar8 = 'm';
          iVar9 = 0;
          do {
            *(char *)((int)local_a8 + iVar9) = cVar8;
            iVar10 = iVar9 + 1;
            cVar8 = "material."[iVar9 + 1];
            iVar9 = iVar10;
          } while (cVar8 != '\0');
          local_a8 = (int *)((int)local_a8 + iVar10);
          if ((param_1[uVar6 * 2 + iVar21 * 2] & 1) == 0) {
            cVar8 = 'f';
            iVar9 = 0;
            do {
              *(char *)((int)local_a8 + iVar9) = cVar8;
              iVar10 = iVar9 + 1;
              cVar8 = "front."[iVar9 + 1];
              iVar9 = iVar10;
            } while (cVar8 != '\0');
LAB_97beb3a4:
            local_a8 = (int *)((int)local_a8 + iVar10);
          }
          else if ((param_1[uVar6 * 2 + iVar21 * 2] & 1) == 1) {
            cVar8 = 'b';
            iVar9 = 0;
            do {
              *(char *)((int)local_a8 + iVar9) = cVar8;
              iVar10 = iVar9 + 1;
              cVar8 = "back."[iVar9 + 1];
              iVar9 = iVar10;
            } while (cVar8 != '\0');
            goto LAB_97beb3a4;
          }
          switch(param_1[uVar6 * 2 + iVar21 * 2] >> 0xc & 0xf) {
          case 0:
            cVar8 = 'a';
            iVar9 = 0;
            do {
              *(char *)((int)local_a8 + iVar9) = cVar8;
              iVar10 = iVar9 + 1;
              cVar8 = "ambient"[iVar9 + 1];
              iVar9 = iVar10;
            } while (cVar8 != '\0');
            break;
          case 1:
            cVar8 = 'd';
            iVar9 = 0;
            do {
              *(char *)((int)local_a8 + iVar9) = cVar8;
              iVar10 = iVar9 + 1;
              cVar8 = "diffuse"[iVar9 + 1];
              iVar9 = iVar10;
            } while (cVar8 != '\0');
            break;
          case 2:
            cVar8 = 's';
            iVar9 = 0;
            do {
              *(char *)((int)local_a8 + iVar9) = cVar8;
              iVar10 = iVar9 + 1;
              cVar8 = "specular"[iVar9 + 1];
              iVar9 = iVar10;
            } while (cVar8 != '\0');
            break;
          case 3:
            cVar8 = 'e';
            iVar9 = 0;
            do {
              *(char *)((int)local_a8 + iVar9) = cVar8;
              iVar10 = iVar9 + 1;
              cVar8 = "emission"[iVar9 + 1];
              iVar9 = iVar10;
            } while (cVar8 != '\0');
            break;
          case 4:
            cVar8 = 's';
            iVar9 = 0;
            do {
              *(char *)((int)local_a8 + iVar9) = cVar8;
              iVar10 = iVar9 + 1;
              cVar8 = "shininess"[iVar9 + 1];
              iVar9 = iVar10;
            } while (cVar8 != '\0');
            break;
          default:
            goto switchD_97beaef4_caseD_0;
          }
          break;
        case 0xb:
          cVar8 = 'f';
          iVar9 = 0;
          do {
            *(char *)((int)local_a8 + iVar9) = cVar8;
            iVar10 = iVar9 + 1;
            cVar8 = "frontfacing"[iVar9 + 1];
            iVar9 = iVar10;
          } while (cVar8 != '\0');
        }
        local_a8 = (int *)((int)local_a8 + iVar10);
switchD_97beaef4_caseD_0:
        cVar8 = ';';
        iVar9 = 0;
        do {
          *(char *)((int)local_a8 + iVar9) = cVar8;
          iVar10 = iVar9 + 1;
          cVar8 = ";\n"[iVar9 + 1];
          iVar9 = iVar10;
        } while (cVar8 != '\0');
        local_a8 = (int *)((int)local_a8 + iVar10);
        uVar25 = ((int (*)())_adjustAllocation_97be9cb4)(&local_b0,&local_ac,&local_a8);
        if ((int)((ulonglong)uVar25 >> 0x20) == 0) goto LAB_97bf0c18;
      }
      iVar21 = iVar21 + 1;
    } while (iVar21 < (int)uVar19);
  }
  uVar16 = (undefined4)uVar25;
  if ((uVar19 != 0) && (!bVar2)) {
    cVar8 = '\n';
    iVar21 = 0;
    do {
      *(char *)((int)local_a8 + iVar21) = cVar8;
      iVar9 = iVar21 + 1;
      cVar8 = "\n"[iVar21 + 1];
      iVar21 = iVar9;
    } while (cVar8 != '\0');
    local_a8 = (int *)((int)local_a8 + iVar9);
  }
  uVar6 = param_1[10];
  puVar20 = param_1 + param_1[0xb] * 2;
  if (uVar6 == 0) {
    bVar3 = local_88 == 0;
    goto LAB_97bed528;
  }
  uVar19 = 0xffffffff;
  if ((int)uVar6 < 1) {
LAB_97beb670:
    bVar3 = local_88 == 0;
  }
  else {
    puVar11 = puVar20 + 1;
    uVar22 = uVar6;
    do {
      uVar24 = *puVar11;
      puVar11 = puVar11 + 2;
      if ((int)uVar19 < (int)(uVar24 & 0xffff)) {
        uVar19 = uVar24 & 0xffff;
      }
      uVar22 = uVar22 - 1;
    } while (uVar22 != 0);
    if (uVar19 == 0xffffffff) goto LAB_97beb670;
    iVar21 = uVar19 * 4 + 4;
    local_88 = _malloc(iVar21);
    bVar1 = local_88 == 0;
    local_84 = _malloc(iVar21);
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
  if (param_1[0xe] != 0) {
    local_78 = (int *)_malloc(param_1[0xe] << 2);
    uVar16 = extraout_r4_04;
  }
  uVar25 = CONCAT44(local_78,uVar16);
  iVar21 = 0;
  iVar9 = -1;
  local_a0 = 0xffffffff;
  uVar19 = 0xffffffff;
  piVar15 = local_78;
  puVar11 = puVar20;
  if (0 < (int)uVar6) {
    do {
      if ((*puVar11 & 0x1f0000) != 0) {
        if (uVar19 == 0xffffffff) {
          *(uint *)((uint)*(ushort *)((int)puVar11 + 6) * 4 + local_88) =
               (uint)*(ushort *)((int)puVar11 + 6);
          uVar25 = ((int (*)())_isParamArrayStart_97be9b80)(param_1,(uint)*(ushort *)((int)puVar11 + 6),&local_a0);
          if ((int)((ulonglong)uVar25 >> 0x20) == 0) {
            *(int *)(local_84 + (uint)*(ushort *)((int)puVar11 + 6) * 4) = iVar9;
          }
          else {
            uVar19 = (uint)*(ushort *)((int)puVar11 + 6);
            *(undefined4 *)(local_84 + uVar19 * 4) = 0;
            iVar9 = 1;
          }
          if (*(ushort *)((int)puVar11 + 6) == local_a0) {
LAB_97beb790:
            local_a0 = 0xffffffff;
            *piVar15 = iVar9;
            uVar19 = 0xffffffff;
            piVar15 = piVar15 + 1;
            iVar9 = -1;
          }
        }
        else if ((int)(uint)*(ushort *)((int)puVar11 + 6) <= (int)local_a0) {
          *(uint *)((uint)*(ushort *)((int)puVar11 + 6) * 4 + local_88) = uVar19;
          *(int *)(local_84 + (uint)*(ushort *)((int)puVar11 + 6) * 4) = iVar9;
          iVar9 = iVar9 + 1;
          if (*(ushort *)((int)puVar11 + 6) == local_a0) goto LAB_97beb790;
        }
      }
      iVar21 = iVar21 + 1;
      puVar11 = puVar11 + 2;
    } while (iVar21 < (int)uVar6);
  }
  iVar21 = 0;
  local_90 = 0;
  if (0 < (int)uVar6) {
    do {
      iVar9 = iVar21 * 8;
      uVar19 = puVar20[iVar21 * 2] >> 0x10 & 0x1f;
      if (uVar19 == 0) goto LAB_97bed4a8;
      iVar10 = *(int *)(local_84 + (uint)*(ushort *)((int)puVar20 + iVar9 + 6) * 4);
      if (iVar10 == -1) {
        cVar8 = 'P';
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10) = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = "PARAM prm"[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
        local_a8 = (int *)((int)local_a8 + iVar12);
        uVar25 = ((int (*)())_ncpy_97be5f58)(local_a8,*(undefined4 *)
                                          (local_88 +
                                          (uint)*(ushort *)((int)puVar20 + iVar9 + 6) * 4));
        local_a8 = (int *)((int)local_a8 + (int)((ulonglong)uVar25 >> 0x20));
        if (!bVar2) {
          uVar22 = puVar20[iVar21 * 2];
          uVar25 = ((int (*)())_glpWriteSizeTypePrecision)(local_a8,uVar22 >> 0x18 & 3,0,uVar22 >> 0x1a & 7,uVar22 >> 0x1d);
          local_a8 = (int *)((ulonglong)uVar25 >> 0x20);
        }
        cVar8 = ' ';
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10) = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = " = "[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
      }
      else if (iVar10 == 0) {
        cVar8 = 'P';
        local_8c = 0;
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10) = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = "PARAM prm"[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
        local_a8 = (int *)((int)local_a8 + iVar12);
        iVar12 = ((int (*)())_ncpy_97be5f58)(local_a8,*(undefined4 *)
                                          (local_88 +
                                          (uint)*(ushort *)((int)puVar20 + iVar9 + 6) * 4));
        cVar8 = '[';
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10 + iVar12) = cVar8;
          iVar13 = iVar10 + 1;
          cVar8 = "["[iVar10 + 1];
          iVar10 = iVar13;
        } while (cVar8 != '\0');
        local_a8 = (int *)((int)local_a8 + iVar13 + iVar12);
        uVar25 = ((int (*)())_ncpy_97be5f58)(local_a8,local_78[local_90]);
        cVar8 = ']';
        puVar17 = (undefined1 *)((int)local_a8 + (int)((ulonglong)uVar25 >> 0x20));
        iVar10 = 0;
        do {
          puVar17[iVar10] = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = "]"[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
        local_a8 = (int *)(puVar17 + iVar12);
        if (!bVar2) {
          uVar22 = puVar20[iVar21 * 2];
          uVar25 = ((int (*)())_glpWriteSizeTypePrecision)(local_a8,uVar22 >> 0x18 & 3,0,uVar22 >> 0x1a & 7,uVar22 >> 0x1d);
          local_a8 = (int *)((ulonglong)uVar25 >> 0x20);
        }
        cVar8 = ' ';
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10) = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = " = {\n    "[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
      }
      else {
        cVar8 = ' ';
        local_8c = local_8c + 1;
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10) = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = "    "[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
      }
      if (uVar19 == 0) {
LAB_97bebb2c:
        cVar8 = 's';
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10 + iVar12) = cVar8;
          iVar13 = iVar10 + 1;
          cVar8 = "state."[iVar10 + 1];
          iVar10 = iVar13;
        } while (cVar8 != '\0');
      }
      else if (uVar19 < 3) {
        cVar8 = 'p';
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10 + iVar12) = cVar8;
          iVar13 = iVar10 + 1;
          cVar8 = "program."[iVar10 + 1];
          iVar10 = iVar13;
        } while (cVar8 != '\0');
      }
      else {
        if (uVar19 != 0x11) goto LAB_97bebb2c;
        iVar13 = 0;
      }
      local_a8 = (int *)((int)local_a8 + iVar13 + iVar12);
      switch(uVar19) {
      default:
        goto switchD_97bebb8c_caseD_0;
      case 1:
        cVar8 = 'l';
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10) = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = "local["[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
        local_a8 = (int *)((int)local_a8 + iVar12);
        iVar10 = ((int (*)())_ncpy_97be5f58)(local_a8,puVar20[iVar21 * 2] & 0xffff);
        cVar8 = ']';
        local_a8 = (int *)((int)local_a8 + iVar10);
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10) = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = "]"[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
        goto LAB_97bed34c;
      case 2:
        cVar8 = 'e';
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10) = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = "env["[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
        local_a8 = (int *)((int)local_a8 + iVar12);
        iVar10 = ((int (*)())_ncpy_97be5f58)(local_a8,puVar20[iVar21 * 2] & 0xffff);
        cVar8 = ']';
        local_a8 = (int *)((int)local_a8 + iVar10);
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10) = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = "]"[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
        goto LAB_97bed34c;
      case 3:
        cVar8 = 'l';
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10) = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = "light["[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
        local_a8 = (int *)((int)local_a8 + iVar12);
        iVar12 = ((int (*)())_ncpy_97be5f58)(local_a8,puVar20[iVar21 * 2] & 0xff);
        cVar8 = ']';
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10 + iVar12) = cVar8;
          iVar13 = iVar10 + 1;
          cVar8 = "]."[iVar10 + 1];
          iVar10 = iVar13;
        } while (cVar8 != '\0');
        local_a8 = (int *)((int)local_a8 + iVar13 + iVar12);
        switch(puVar20[iVar21 * 2] >> 8 & 0xf) {
        case 0:
          cVar8 = 'a';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "ambient"[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 1:
          cVar8 = 'd';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "diffuse"[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 2:
          cVar8 = 's';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "specular"[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 3:
          cVar8 = 'p';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "position"[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 4:
          cVar8 = 's';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "spot.direction"[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 5:
          cVar8 = 'a';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "attenuation"[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 6:
          cVar8 = 'h';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "half"[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 7:
          cVar8 = 's';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "spotcutoff"[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        default:
          goto switchD_97bebb8c_caseD_0;
        }
        break;
      case 4:
        cVar8 = 'l';
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10) = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = "lightprod["[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
        local_a8 = (int *)((int)local_a8 + iVar12);
        iVar12 = ((int (*)())_ncpy_97be5f58)(local_a8,puVar20[iVar21 * 2] & 0xff);
        cVar8 = ']';
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10 + iVar12) = cVar8;
          iVar13 = iVar10 + 1;
          cVar8 = "]."[iVar10 + 1];
          iVar10 = iVar13;
        } while (cVar8 != '\0');
        local_a8 = (int *)((int)local_a8 + iVar13 + iVar12);
        uVar19 = puVar20[iVar21 * 2] >> 8 & 1;
        if (uVar19 == 0) {
          cVar8 = 'f';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "front."[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
LAB_97bec0e8:
          local_a8 = (int *)((int)local_a8 + iVar12);
        }
        else if (uVar19 == 1) {
          cVar8 = 'b';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "back."[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          goto LAB_97bec0e8;
        }
        uVar19 = puVar20[iVar21 * 2] >> 9 & 3;
        if (uVar19 == 1) {
          cVar8 = 'd';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "diffuse"[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        }
        if (uVar19 < 2) {
          if (uVar19 == 0) {
            cVar8 = 'a';
            iVar10 = 0;
            do {
              *(char *)((int)local_a8 + iVar10) = cVar8;
              iVar12 = iVar10 + 1;
              cVar8 = "ambient"[iVar10 + 1];
              iVar10 = iVar12;
            } while (cVar8 != '\0');
            break;
          }
        }
        else if (uVar19 == 2) {
          cVar8 = 's';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "specular"[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        }
        goto switchD_97bebb8c_caseD_0;
      case 5:
        if ((puVar20[iVar21 * 2] >> 1 & 7) == 5) {
          cVar8 = 'l';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "lightmodel."[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
        }
        else {
          cVar8 = 'm';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "material."[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
        }
        local_a8 = (int *)((int)local_a8 + iVar12);
        if ((puVar20[iVar21 * 2] & 1) == 0) {
          cVar8 = 'f';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "front."[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
LAB_97bec310:
          local_a8 = (int *)((int)local_a8 + iVar12);
        }
        else if ((puVar20[iVar21 * 2] & 1) == 1) {
          cVar8 = 'b';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "back."[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          goto LAB_97bec310;
        }
        switch(puVar20[iVar21 * 2] >> 1 & 7) {
        case 0:
          cVar8 = 'a';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "ambient"[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 1:
          cVar8 = 'd';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "diffuse"[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 2:
          cVar8 = 's';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "specular"[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 3:
          cVar8 = 'e';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "emission"[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 4:
          cVar8 = 's';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "shininess"[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 5:
          cVar8 = 's';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "scenecolor"[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        default:
          goto switchD_97bebb8c_caseD_0;
        }
        break;
      case 6:
        cVar8 = 'l';
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10) = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = "lightmodel.ambient"[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
        break;
      case 7:
        cVar8 = 't';
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10) = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = "texgen["[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
        local_a8 = (int *)((int)local_a8 + iVar12);
        iVar12 = ((int (*)())_ncpy_97be5f58)(local_a8,puVar20[iVar21 * 2] & 0x1f);
        cVar8 = ']';
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10 + iVar12) = cVar8;
          iVar13 = iVar10 + 1;
          cVar8 = "].eye."[iVar10 + 1];
          iVar10 = iVar13;
        } while (cVar8 != '\0');
        local_a8 = (int *)((int)local_a8 + iVar13 + iVar12);
        uVar19 = puVar20[iVar21 * 2] >> 5 & 7;
        if (uVar19 == 1) {
          cVar8 = 't';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "t"[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
        }
        else if (uVar19 < 2) {
          if (uVar19 != 0) goto switchD_97bebb8c_caseD_0;
          cVar8 = 's';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "s"[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
        }
        else if (uVar19 == 2) {
          cVar8 = 'r';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "r"[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
        }
        else {
          if (uVar19 != 3) goto switchD_97bebb8c_caseD_0;
          cVar8 = 'q';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "q"[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
        }
        break;
      case 8:
        cVar8 = 't';
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10) = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = "texgen["[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
        local_a8 = (int *)((int)local_a8 + iVar12);
        iVar12 = ((int (*)())_ncpy_97be5f58)(local_a8,puVar20[iVar21 * 2] & 0x1f);
        cVar8 = ']';
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10 + iVar12) = cVar8;
          iVar13 = iVar10 + 1;
          cVar8 = "].object."[iVar10 + 1];
          iVar10 = iVar13;
        } while (cVar8 != '\0');
        local_a8 = (int *)((int)local_a8 + iVar13 + iVar12);
        uVar19 = puVar20[iVar21 * 2] >> 5 & 7;
        if (uVar19 == 1) {
          cVar8 = 't';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "t"[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
        }
        else if (uVar19 < 2) {
          if (uVar19 != 0) goto switchD_97bebb8c_caseD_0;
          cVar8 = 's';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "s"[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
        }
        else if (uVar19 == 2) {
          cVar8 = 'r';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "r"[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
        }
        else {
          if (uVar19 != 3) goto switchD_97bebb8c_caseD_0;
          cVar8 = 'q';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "q"[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
        }
        break;
      case 9:
        cVar8 = 't';
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10) = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = "texenv["[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
        local_a8 = (int *)((int)local_a8 + iVar12);
        iVar10 = ((int (*)())_ncpy_97be5f58)(local_a8,puVar20[iVar21 * 2] & 0x1f);
        cVar8 = ']';
        local_a8 = (int *)((int)local_a8 + iVar10);
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10) = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = "].color"[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
        goto LAB_97bed34c;
      case 10:
        cVar8 = 'c';
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10) = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = "clip["[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
        local_a8 = (int *)((int)local_a8 + iVar12);
        iVar10 = ((int (*)())_ncpy_97be5f58)(local_a8,puVar20[iVar21 * 2] & 0xff);
        cVar8 = ']';
        local_a8 = (int *)((int)local_a8 + iVar10);
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10) = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = "].plane"[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
        goto LAB_97bed34c;
      case 0xb:
        cVar8 = 'f';
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10) = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = "fog.color"[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
        break;
      case 0xc:
        cVar8 = 'f';
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10) = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = "fog.params"[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
        break;
      case 0xd:
        cVar8 = 'p';
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10) = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = "point.size"[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
        break;
      case 0xe:
        cVar8 = 'p';
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10) = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = "point.attenuation"[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
        break;
      case 0xf:
        cVar8 = 'd';
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10) = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = "depth.range"[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
        break;
      case 0x10:
        cVar8 = 'm';
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10) = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = "matrix."[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
        local_a8 = (int *)((int)local_a8 + iVar12);
        switch(puVar20[iVar21 * 2] >> 8 & 7) {
        case 0:
          cVar8 = 'm';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "mvp."[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          goto LAB_97becb5c;
        case 1:
          cVar8 = 'p';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "projection."[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
LAB_97becb5c:
          local_a8 = (int *)((int)local_a8 + iVar12);
          goto switchD_97becad4_default;
        case 2:
          cVar8 = 'c';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "color["[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          local_a8 = (int *)((int)local_a8 + iVar12);
          iVar10 = ((int (*)())_ncpy_97be5f58)(local_a8,puVar20[iVar21 * 2] & 0xff);
          cVar8 = ']';
          local_a8 = (int *)((int)local_a8 + iVar10);
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "]."[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 3:
          cVar8 = 'm';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "modelview["[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          local_a8 = (int *)((int)local_a8 + iVar12);
          iVar10 = ((int (*)())_ncpy_97be5f58)(local_a8,puVar20[iVar21 * 2] & 0xff);
          cVar8 = ']';
          local_a8 = (int *)((int)local_a8 + iVar10);
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "]."[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 4:
          cVar8 = 't';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "texture["[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          local_a8 = (int *)((int)local_a8 + iVar12);
          iVar10 = ((int (*)())_ncpy_97be5f58)(local_a8,puVar20[iVar21 * 2] & 0xff);
          cVar8 = ']';
          local_a8 = (int *)((int)local_a8 + iVar10);
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "]."[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 5:
          cVar8 = 'p';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "program["[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          local_a8 = (int *)((int)local_a8 + iVar12);
          iVar10 = ((int (*)())_ncpy_97be5f58)(local_a8,puVar20[iVar21 * 2] & 0xff);
          cVar8 = ']';
          local_a8 = (int *)((int)local_a8 + iVar10);
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "]."[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        default:
          goto switchD_97becad4_default;
        }
        local_a8 = (int *)((int)local_a8 + iVar12);
switchD_97becad4_default:
        uVar19 = puVar20[iVar21 * 2] >> 0xe & 3;
        if (uVar19 == 1) {
          cVar8 = 't';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "transpose."[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
LAB_97bece9c:
          local_a8 = (int *)((int)local_a8 + iVar12);
        }
        else if (1 < uVar19) {
          if (uVar19 == 2) {
            cVar8 = 'i';
            iVar10 = 0;
            do {
              *(char *)((int)local_a8 + iVar10) = cVar8;
              iVar12 = iVar10 + 1;
              cVar8 = "inverse."[iVar10 + 1];
              iVar10 = iVar12;
            } while (cVar8 != '\0');
          }
          else {
            if (uVar19 != 3) goto LAB_97becea8;
            cVar8 = 'i';
            iVar10 = 0;
            do {
              *(char *)((int)local_a8 + iVar10) = cVar8;
              iVar12 = iVar10 + 1;
              cVar8 = "invtrans."[iVar10 + 1];
              iVar10 = iVar12;
            } while (cVar8 != '\0');
          }
          goto LAB_97bece9c;
        }
LAB_97becea8:
        cVar8 = 'r';
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10) = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = "row["[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
        local_a8 = (int *)((int)local_a8 + iVar12);
        iVar10 = ((int (*)())_ncpy_97be5f58)(local_a8,puVar20[iVar21 * 2] >> 0xc & 3);
        cVar8 = ']';
        local_a8 = (int *)((int)local_a8 + iVar10);
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10) = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = "]"[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
LAB_97bed34c:
        local_a8 = (int *)((int)local_a8 + iVar12);
        goto switchD_97bebb8c_caseD_0;
      case 0x11:
        pfVar23 = (float *)(param_1 + param_1[0x1b] * 2 + (puVar20[iVar21 * 2] & 0xffff) * 4);
        switch(puVar20[iVar21 * 2] >> 0x1a & 7) {
        case 0:
        case 1:
          cVar8 = '{';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "{"[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          local_a8 = (int *)((int)local_a8 + iVar12);
          uVar25 = ((char * (*)())_glp_dtostr)((int)((ulonglong)uVar25 >> 0x20),(int)uVar25,local_a8,
                               (int)local_ac + (local_b0 - (int)local_a8),(double)*pfVar23,1e-07,
                               in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_fffffd08,
                               in_stack_fffffd10,in_stack_fffffd18,in_stack_fffffd20,
                               in_stack_fffffd28);
          iVar12 = (int)((ulonglong)uVar25 >> 0x20);
          cVar8 = ',';
          iVar10 = 0;
          do {
            *(char *)(iVar12 + iVar10) = cVar8;
            iVar13 = iVar10 + 1;
            cVar8 = ", "[iVar10 + 1];
            iVar10 = iVar13;
          } while (cVar8 != '\0');
          local_a8 = (int *)(iVar12 + iVar13);
          uVar25 = ((char * (*)())_glp_dtostr)(iVar12,(int)uVar25,local_a8,
                               (int)local_ac + (local_b0 - (int)local_a8),(double)pfVar23[1],1e-07,
                               in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_fffffd08,
                               in_stack_fffffd10,in_stack_fffffd18,in_stack_fffffd20,
                               in_stack_fffffd28);
          iVar12 = (int)((ulonglong)uVar25 >> 0x20);
          cVar8 = ',';
          iVar10 = 0;
          do {
            *(char *)(iVar12 + iVar10) = cVar8;
            iVar13 = iVar10 + 1;
            cVar8 = ", "[iVar10 + 1];
            iVar10 = iVar13;
          } while (cVar8 != '\0');
          local_a8 = (int *)(iVar12 + iVar13);
          uVar25 = ((char * (*)())_glp_dtostr)(iVar12,(int)uVar25,local_a8,
                               (int)local_ac + (local_b0 - (int)local_a8),(double)pfVar23[2],1e-07,
                               in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_fffffd08,
                               in_stack_fffffd10,in_stack_fffffd18,in_stack_fffffd20,
                               in_stack_fffffd28);
          iVar12 = (int)((ulonglong)uVar25 >> 0x20);
          cVar8 = ',';
          iVar10 = 0;
          do {
            *(char *)(iVar12 + iVar10) = cVar8;
            iVar13 = iVar10 + 1;
            cVar8 = ", "[iVar10 + 1];
            iVar10 = iVar13;
          } while (cVar8 != '\0');
          local_a8 = (int *)(iVar12 + iVar13);
          local_a8 = (int *)((char * (*)())_glp_dtostr)(iVar12,(int)uVar25,local_a8,
                                        (int)local_ac + (local_b0 - (int)local_a8),
                                        (double)pfVar23[3],1e-07,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8
                                        ,in_stack_fffffd08,in_stack_fffffd10,in_stack_fffffd18,
                                        in_stack_fffffd20,in_stack_fffffd28);
          cVar8 = '}';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "}"[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 2:
          cVar8 = '{';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "{-- Fixed constant data not currently supported --}"[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 3:
        case 4:
          cVar8 = '{';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "{"[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          local_a8 = (int *)((int)local_a8 + iVar12);
          iVar12 = ((int (*)())_ncpy_97be5f58)(local_a8,*pfVar23);
          cVar8 = ',';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10 + iVar12) = cVar8;
            iVar13 = iVar10 + 1;
            cVar8 = ", "[iVar10 + 1];
            iVar10 = iVar13;
          } while (cVar8 != '\0');
          local_a8 = (int *)((int)local_a8 + iVar13 + iVar12);
          iVar12 = ((int (*)())_ncpy_97be5f58)(local_a8,pfVar23[1]);
          cVar8 = ',';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10 + iVar12) = cVar8;
            iVar13 = iVar10 + 1;
            cVar8 = ", "[iVar10 + 1];
            iVar10 = iVar13;
          } while (cVar8 != '\0');
          local_a8 = (int *)((int)local_a8 + iVar13 + iVar12);
          iVar12 = ((int (*)())_ncpy_97be5f58)(local_a8,pfVar23[2]);
          cVar8 = ',';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10 + iVar12) = cVar8;
            iVar13 = iVar10 + 1;
            cVar8 = ", "[iVar10 + 1];
            iVar10 = iVar13;
          } while (cVar8 != '\0');
          local_a8 = (int *)((int)local_a8 + iVar13 + iVar12);
          iVar10 = ((int (*)())_ncpy_97be5f58)(local_a8,pfVar23[3]);
          cVar8 = '}';
          local_a8 = (int *)((int)local_a8 + iVar10);
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "}"[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          goto LAB_97bed34c;
        default:
          goto switchD_97bebb8c_caseD_0;
        }
        break;
      case 0x12:
        cVar8 = 'n';
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10) = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = "normalscale"[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
      }
      local_a8 = (int *)((int)local_a8 + iVar12);
switchD_97bebb8c_caseD_0:
      if (*(int *)(local_84 + (uint)*(ushort *)((int)puVar20 + iVar9 + 6) * 4) == -1) {
        cVar8 = ';';
        iVar9 = 0;
        do {
          *(char *)((int)local_a8 + iVar9) = cVar8;
          iVar10 = iVar9 + 1;
          cVar8 = ";\n"[iVar9 + 1];
          iVar9 = iVar10;
        } while (cVar8 != '\0');
      }
      else if (local_8c + 1 == local_78[local_90]) {
        cVar8 = '\n';
        local_90 = local_90 + 1;
        iVar9 = 0;
        do {
          *(char *)((int)local_a8 + iVar9) = cVar8;
          iVar10 = iVar9 + 1;
          cVar8 = "\n};\n"[iVar9 + 1];
          iVar9 = iVar10;
        } while (cVar8 != '\0');
      }
      else {
        cVar8 = ',';
        iVar9 = 0;
        do {
          *(char *)((int)local_a8 + iVar9) = cVar8;
          iVar10 = iVar9 + 1;
          cVar8 = ",\n"[iVar9 + 1];
          iVar9 = iVar10;
        } while (cVar8 != '\0');
      }
      local_a8 = (int *)((int)local_a8 + iVar10);
      uVar25 = ((int (*)())_adjustAllocation_97be9cb4)(&local_b0,&local_ac,&local_a8);
      bVar1 = bVar3;
      if ((int)((ulonglong)uVar25 >> 0x20) == 0) goto joined_r0x97beb668;
LAB_97bed4a8:
      iVar21 = iVar21 + 1;
    } while (iVar21 < (int)uVar6);
  }
  if (local_78 != (int *)0x0) {
    _free(local_78);
    uVar25 = CONCAT44(extraout_r3_00,extraout_r4_05);
  }
  cVar8 = '\n';
  iVar21 = 0;
  do {
    *(char *)((int)local_a8 + iVar21) = cVar8;
    iVar9 = iVar21 + 1;
    cVar8 = "\n"[iVar21 + 1];
    iVar21 = iVar9;
  } while (cVar8 != '\0');
  local_a8 = (int *)((int)local_a8 + iVar9);
LAB_97bed528:
  uVar19 = param_1[0xc];
  iVar21 = 0;
  uVar6 = param_1[0xd];
  bVar1 = bVar3;
  if (0 < (int)uVar19) {
    do {
      uVar22 = param_1[uVar6 * 2 + iVar21 * 2] >> 0x10 & 0xf;
      if (uVar22 == 0) goto LAB_97bedcb4;
      uVar24 = param_1[uVar6 * 2 + iVar21 * 2] >> 0x1d;
      if (uVar24 == 1) {
        cVar8 = 'L';
        iVar9 = 0;
        do {
          *(char *)((int)local_a8 + iVar9) = cVar8;
          iVar10 = iVar9 + 1;
          cVar8 = "LONG OUTPUT res"[iVar9 + 1];
          iVar9 = iVar10;
        } while (cVar8 != '\0');
LAB_97bed640:
        local_a8 = (int *)((int)local_a8 + iVar10);
      }
      else if (uVar24 < 2) {
        if (uVar24 == 0) {
          cVar8 = 'O';
          iVar9 = 0;
          do {
            *(char *)((int)local_a8 + iVar9) = cVar8;
            iVar10 = iVar9 + 1;
            cVar8 = "OUTPUT res"[iVar9 + 1];
            iVar9 = iVar10;
          } while (cVar8 != '\0');
          goto LAB_97bed640;
        }
      }
      else if (uVar24 == 2) {
        cVar8 = 'S';
        iVar9 = 0;
        do {
          *(char *)((int)local_a8 + iVar9) = cVar8;
          iVar10 = iVar9 + 1;
          cVar8 = "SHORT OUTPUT res"[iVar9 + 1];
          iVar9 = iVar10;
        } while (cVar8 != '\0');
        goto LAB_97bed640;
      }
      iVar9 = ((int (*)())_ncpy_97be5f58)(local_a8,(uint)*(ushort *)((int)param_1 + iVar21 * 8 + uVar6 * 8 + 6));
      local_a8 = (int *)((int)local_a8 + iVar9);
      if (!bVar2) {
        uVar24 = param_1[uVar6 * 2 + iVar21 * 2];
        local_a8 = (int *)((int (*)())_glpWriteSizeTypePrecision)(local_a8,uVar24 >> 0x18 & 3,0,uVar24 >> 0x1a & 7,uVar24 >> 0x1d
                                    );
      }
      cVar8 = ' ';
      iVar9 = 0;
      do {
        *(char *)((int)local_a8 + iVar9) = cVar8;
        iVar10 = iVar9 + 1;
        cVar8 = " = "[iVar9 + 1];
        iVar9 = iVar10;
      } while (cVar8 != '\0');
      local_a8 = (int *)((int)local_a8 + iVar10);
      switch(uVar22) {
      default:
        goto switchD_97bed6f4_caseD_0;
      case 1:
        cVar8 = 'r';
        iVar9 = 0;
        do {
          *(char *)((int)local_a8 + iVar9) = cVar8;
          iVar10 = iVar9 + 1;
          cVar8 = "result.position"[iVar9 + 1];
          iVar9 = iVar10;
        } while (cVar8 != '\0');
        break;
      case 2:
        cVar8 = 'r';
        iVar9 = 0;
        do {
          *(char *)((int)local_a8 + iVar9) = cVar8;
          iVar10 = iVar9 + 1;
          cVar8 = "result.fogcoord"[iVar9 + 1];
          iVar9 = iVar10;
        } while (cVar8 != '\0');
        break;
      case 3:
        cVar8 = 'r';
        iVar9 = 0;
        do {
          *(char *)((int)local_a8 + iVar9) = cVar8;
          iVar10 = iVar9 + 1;
          cVar8 = "result.pointsize"[iVar9 + 1];
          iVar9 = iVar10;
        } while (cVar8 != '\0');
        break;
      case 4:
        cVar8 = 'r';
        iVar9 = 0;
        do {
          *(char *)((int)local_a8 + iVar9) = cVar8;
          iVar10 = iVar9 + 1;
          cVar8 = "result.color"[iVar9 + 1];
          iVar9 = iVar10;
        } while (cVar8 != '\0');
        local_a8 = (int *)((int)local_a8 + iVar10);
        if ((uVar18 == 0x8620) || (uVar18 == 0x8b31)) {
          if ((param_1[uVar6 * 2 + iVar21 * 2] & 1) == 0) {
            cVar8 = '.';
            iVar9 = 0;
            do {
              *(char *)((int)local_a8 + iVar9) = cVar8;
              iVar10 = iVar9 + 1;
              cVar8 = ".front.primary"[iVar9 + 1];
              iVar9 = iVar10;
            } while (cVar8 != '\0');
          }
          else {
            if ((param_1[uVar6 * 2 + iVar21 * 2] & 1) != 1) goto switchD_97bed6f4_caseD_0;
            cVar8 = '.';
            iVar9 = 0;
            do {
              *(char *)((int)local_a8 + iVar9) = cVar8;
              iVar10 = iVar9 + 1;
              cVar8 = ".back.primary"[iVar9 + 1];
              iVar9 = iVar10;
            } while (cVar8 != '\0');
          }
          break;
        }
        if (((uVar18 == 0x8804) || (uVar18 == 0x8b30)) &&
           (1 < (param_1[uVar6 * 2 + iVar21 * 2] >> 1 & 7))) {
          cVar8 = '[';
          iVar9 = 0;
          do {
            *(char *)((int)local_a8 + iVar9) = cVar8;
            iVar10 = iVar9 + 1;
            cVar8 = "["[iVar9 + 1];
            iVar9 = iVar10;
          } while (cVar8 != '\0');
          local_a8 = (int *)((int)local_a8 + iVar10);
          iVar10 = ((int (*)())_ncpy_97be5f58)(local_a8,param_1[uVar6 * 2 + iVar21 * 2] >> 1 & 7);
          cVar8 = ']';
          iVar9 = 0;
          do {
            *(char *)((int)local_a8 + iVar9 + iVar10) = cVar8;
            iVar12 = iVar9 + 1;
            cVar8 = "]"[iVar9 + 1];
            iVar9 = iVar12;
          } while (cVar8 != '\0');
          local_a8 = (int *)((int)local_a8 + iVar12 + iVar10);
        }
        goto switchD_97bed6f4_caseD_0;
      case 5:
        cVar8 = 'r';
        iVar9 = 0;
        do {
          *(char *)((int)local_a8 + iVar9) = cVar8;
          iVar10 = iVar9 + 1;
          cVar8 = "result.color"[iVar9 + 1];
          iVar9 = iVar10;
        } while (cVar8 != '\0');
        local_a8 = (int *)((int)local_a8 + iVar10);
        if ((uVar18 == 0x8620) || (uVar18 == 0x8b31)) {
          if ((param_1[uVar6 * 2 + iVar21 * 2] & 1) == 0) {
            cVar8 = '.';
            iVar9 = 0;
            do {
              *(char *)((int)local_a8 + iVar9) = cVar8;
              iVar10 = iVar9 + 1;
              cVar8 = ".front.secondary"[iVar9 + 1];
              iVar9 = iVar10;
            } while (cVar8 != '\0');
          }
          else {
            if ((param_1[uVar6 * 2 + iVar21 * 2] & 1) != 1) goto switchD_97bed6f4_caseD_0;
            cVar8 = '.';
            iVar9 = 0;
            do {
              *(char *)((int)local_a8 + iVar9) = cVar8;
              iVar10 = iVar9 + 1;
              cVar8 = ".back.secondary"[iVar9 + 1];
              iVar9 = iVar10;
            } while (cVar8 != '\0');
          }
          break;
        }
        goto switchD_97bed6f4_caseD_0;
      case 6:
        cVar8 = 'r';
        iVar9 = 0;
        do {
          *(char *)((int)local_a8 + iVar9) = cVar8;
          iVar10 = iVar9 + 1;
          cVar8 = "result.texcoord["[iVar9 + 1];
          iVar9 = iVar10;
        } while (cVar8 != '\0');
        local_a8 = (int *)((int)local_a8 + iVar10);
        iVar9 = ((int (*)())_ncpy_97be5f58)(local_a8,param_1[uVar6 * 2 + iVar21 * 2] & 0x1f);
        cVar8 = ']';
        local_a8 = (int *)((int)local_a8 + iVar9);
        iVar9 = 0;
        do {
          *(char *)((int)local_a8 + iVar9) = cVar8;
          iVar10 = iVar9 + 1;
          cVar8 = "]"[iVar9 + 1];
          iVar9 = iVar10;
        } while (cVar8 != '\0');
        break;
      case 7:
        cVar8 = 'r';
        iVar9 = 0;
        do {
          *(char *)((int)local_a8 + iVar9) = cVar8;
          iVar10 = iVar9 + 1;
          cVar8 = "result.depth"[iVar9 + 1];
          iVar9 = iVar10;
        } while (cVar8 != '\0');
        break;
      case 8:
        cVar8 = 'r';
        iVar9 = 0;
        do {
          *(char *)((int)local_a8 + iVar9) = cVar8;
          iVar10 = iVar9 + 1;
          cVar8 = "result.eyePosition"[iVar9 + 1];
          iVar9 = iVar10;
        } while (cVar8 != '\0');
        break;
      case 9:
        cVar8 = 'r';
        iVar9 = 0;
        do {
          *(char *)((int)local_a8 + iVar9) = cVar8;
          iVar10 = iVar9 + 1;
          cVar8 = "result.clipVertex"[iVar9 + 1];
          iVar9 = iVar10;
        } while (cVar8 != '\0');
        break;
      case 10:
        cVar8 = 'r';
        iVar9 = 0;
        do {
          *(char *)((int)local_a8 + iVar9) = cVar8;
          iVar10 = iVar9 + 1;
          cVar8 = "result.attrib["[iVar9 + 1];
          iVar9 = iVar10;
        } while (cVar8 != '\0');
        local_a8 = (int *)((int)local_a8 + iVar10);
        iVar9 = ((int (*)())_ncpy_97be5f58)(local_a8,param_1[uVar6 * 2 + iVar21 * 2] & 0x1f);
        cVar8 = ']';
        local_a8 = (int *)((int)local_a8 + iVar9);
        iVar9 = 0;
        do {
          *(char *)((int)local_a8 + iVar9) = cVar8;
          iVar10 = iVar9 + 1;
          cVar8 = "]"[iVar9 + 1];
          iVar9 = iVar10;
        } while (cVar8 != '\0');
      }
      local_a8 = (int *)((int)local_a8 + iVar10);
switchD_97bed6f4_caseD_0:
      cVar8 = ';';
      iVar9 = 0;
      do {
        *(char *)((int)local_a8 + iVar9) = cVar8;
        iVar10 = iVar9 + 1;
        cVar8 = ";\n"[iVar9 + 1];
        iVar9 = iVar10;
      } while (cVar8 != '\0');
      local_a8 = (int *)((int)local_a8 + iVar10);
      uVar25 = ((int (*)())_adjustAllocation_97be9cb4)(&local_b0,&local_ac,&local_a8);
      if ((int)((ulonglong)uVar25 >> 0x20) == 0) goto joined_r0x97beb668;
LAB_97bedcb4:
      iVar21 = iVar21 + 1;
    } while (iVar21 < (int)uVar19);
  }
  if ((uVar19 != 0) || (bVar2)) {
    cVar8 = '\n';
    iVar21 = 0;
    do {
      *(char *)((int)local_a8 + iVar21) = cVar8;
      iVar9 = iVar21 + 1;
      cVar8 = "\n"[iVar21 + 1];
      iVar21 = iVar9;
    } while (cVar8 != '\0');
    local_a8 = (int *)((int)local_a8 + iVar9);
  }
  uVar19 = param_1[0x14];
  iVar21 = 0;
  uVar6 = param_1[0x15];
  uVar18 = uVar19;
  if (0 < (int)uVar19) {
    do {
      if ((param_1[uVar6 * 2 + iVar21 * 2] >> 0x12 & 0xff) - 0x4b < 2) {
        local_6c = local_6c + 1;
      }
      iVar21 = iVar21 + (param_1[uVar6 * 2 + iVar21 * 2] >> 0x1d) + 2;
      uVar18 = uVar18 - 1;
    } while (uVar18 != 0);
  }
  bVar4 = local_6c == 0;
  if (!bVar4) {
    iVar21 = local_6c << 2;
    iVar9 = 0;
    iVar10 = 0;
    local_74 = _malloc(iVar21);
    _memset(local_74,0,local_6c);
    local_70 = _malloc(iVar21);
    uVar16 = _memset(local_70,0,local_6c);
    uVar25 = CONCAT44(uVar16,extraout_r4_06);
    local_6c = 0;
    bVar4 = true;
    if (0 < (int)uVar19) {
      do {
        uVar18 = param_1[uVar6 * 2 + iVar10 * 2];
        if ((uVar18 >> 0x12 & 0xff) - 0x4b < 2) {
          uVar25 = ((int (*)())_InsertLabel)(local_74,local_70,param_1[uVar6 * 2 + iVar10 * 2 + 1] & 0x3ffff,
                                uVar18 & 0x3ffff,local_6c);
          local_6c = (int)((ulonglong)uVar25 >> 0x20);
          uVar18 = param_1[uVar6 * 2 + iVar10 * 2];
        }
        iVar9 = iVar9 + 1;
        iVar10 = iVar10 + (uVar18 >> 0x1d) + 2;
        bVar4 = local_6c == 0;
      } while (iVar9 < (int)uVar19);
    }
  }
  iVar21 = 0;
  iVar9 = 0;
  if (0 < (int)uVar19) {
    puVar20 = (uint *)(local_68 * 4 + local_74);
    do {
      if (((param_1[uVar6 * 2 + iVar9 * 2] & 0x3ffff) == 0) && (!bVar2)) {
        cVar8 = 'm';
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10) = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = "main:\n"[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
        local_a8 = (int *)((int)local_a8 + iVar12);
      }
      if (((!bVar4) && (local_68 < local_6c)) &&
         ((param_1[uVar6 * 2 + iVar9 * 2] & 0x3ffff) == *puVar20)) {
        iVar10 = 0;
        local_9c = local_9c + -1;
        if (0 < local_9c) {
          do {
            cVar8 = ' ';
            iVar12 = 0;
            do {
              *(char *)((int)local_a8 + iVar12) = cVar8;
              iVar13 = iVar12 + 1;
              cVar8 = "  "[iVar12 + 1];
              iVar12 = iVar13;
            } while (cVar8 != '\0');
            iVar10 = iVar10 + 1;
            local_a8 = (int *)((int)local_a8 + iVar13);
          } while (iVar10 < local_9c);
        }
        cVar8 = 'l';
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10) = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = "label_"[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
        local_a8 = (int *)((int)local_a8 + iVar12);
        iVar12 = ((int (*)())_ncpy_97be5f58)(local_a8,local_68);
        cVar8 = ':';
        local_68 = local_68 + 1;
        puVar20 = puVar20 + 1;
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10 + iVar12) = cVar8;
          iVar13 = iVar10 + 1;
          cVar8 = ":\n"[iVar10 + 1];
          iVar10 = iVar13;
        } while (cVar8 != '\0');
        local_a8 = (int *)((int)local_a8 + iVar13 + iVar12);
        local_9c = local_9c + 1;
      }
      uVar18 = param_1[uVar6 * 2 + iVar9 * 2] >> 0x12 & 0xff;
      if (((uVar18 == 0x6b) || (uVar18 == 0x58)) ||
         ((uVar18 == 0x59 || ((uVar18 == 0x5a || (uVar18 == 0x5b)))))) {
        local_9c = local_9c + -1;
      }
      ((int (*)())_glpDisassemble1Op)(param_1 + uVar6 * 2 + iVar9 * 2,local_a8,&local_98,&local_94,local_88,
                         local_84,local_80,local_7c,local_74,&local_9c,local_64);
      local_a8 = (int *)((int)local_a8 + local_94);
      iVar9 = iVar9 + local_98;
      uVar25 = ((int (*)())_adjustAllocation_97be9cb4)(&local_b0,&local_ac,&local_a8);
      if ((int)((ulonglong)uVar25 >> 0x20) == 0) {
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
        iVar21 = local_70;
        goto LAB_97bee10c;
      }
      iVar21 = iVar21 + 1;
      iVar9 = iVar9 + 1;
    } while (iVar21 < (int)uVar19);
  }
  if (!bVar4) {
    if ((local_68 < local_6c) && (iVar21 + 1 == *(int *)(local_74 + local_68 * 4))) {
      cVar8 = ' ';
      iVar21 = 0;
      do {
        *(char *)((int)local_a8 + iVar21) = cVar8;
        iVar9 = iVar21 + 1;
        cVar8 = "  label_"[iVar21 + 1];
        iVar21 = iVar9;
      } while (cVar8 != '\0');
      local_a8 = (int *)((int)local_a8 + iVar9);
      iVar9 = ((int (*)())_ncpy_97be5f58)(local_a8,local_68);
      cVar8 = ':';
      iVar21 = 0;
      do {
        *(char *)((int)local_a8 + iVar21 + iVar9) = cVar8;
        iVar10 = iVar21 + 1;
        cVar8 = ":\n"[iVar21 + 1];
        iVar21 = iVar10;
      } while (cVar8 != '\0');
      local_a8 = (int *)((int)local_a8 + iVar10 + iVar9);
    }
    _free(local_74);
    _free(local_70);
    uVar25 = CONCAT44(extraout_r3_01,extraout_r4_07);
  }
  cVar8 = 'E';
  iVar21 = 0;
  do {
    *(char *)((int)local_a8 + iVar21) = cVar8;
    iVar9 = iVar21 + 1;
    cVar8 = "END\n"[iVar21 + 1];
    iVar21 = iVar9;
  } while (cVar8 != '\0');
  uVar6 = param_1[0x18];
  iVar21 = 0;
  uVar18 = param_1[0x19];
  local_a8 = (int *)((int)local_a8 + iVar9);
  iVar9 = 0;
  if (0 < (int)uVar6) {
    local_60 = "o intialize the Preprocessor";
    do {
      cVar8 = 'S';
      uVar19 = param_1[uVar18 * 2 + iVar9 * 2];
      iVar10 = 0;
      do {
        *(char *)((int)local_a8 + iVar10) = cVar8;
        iVar12 = iVar10 + 1;
        cVar8 = "STATE "[iVar10 + 1];
        iVar10 = iVar12;
      } while (cVar8 != '\0');
      local_a8 = (int *)((int)local_a8 + iVar12);
      switch(uVar19 >> 0x18 & 7) {
      case 0:
        cVar8 = 'A';
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10) = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = "ALPHA_TEST "[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
        switch(param_1[uVar18 * 2 + iVar9 * 2] & 7) {
        case 0:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10 + iVar12) = cVar8;
            iVar13 = iVar10 + 1;
            cVar8 = "PP_NEVER "[iVar10 + 1];
            iVar10 = iVar13;
          } while (cVar8 != '\0');
          break;
        case 1:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10 + iVar12) = cVar8;
            iVar13 = iVar10 + 1;
            cVar8 = "PP_LESS "[iVar10 + 1];
            iVar10 = iVar13;
          } while (cVar8 != '\0');
          break;
        case 2:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10 + iVar12) = cVar8;
            iVar13 = iVar10 + 1;
            cVar8 = "PP_EQUAL "[iVar10 + 1];
            iVar10 = iVar13;
          } while (cVar8 != '\0');
          break;
        case 3:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10 + iVar12) = cVar8;
            iVar13 = iVar10 + 1;
            cVar8 = "PP_LEQUAL "[iVar10 + 1];
            iVar10 = iVar13;
          } while (cVar8 != '\0');
          break;
        case 4:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10 + iVar12) = cVar8;
            iVar13 = iVar10 + 1;
            cVar8 = "PP_GREATER "[iVar10 + 1];
            iVar10 = iVar13;
          } while (cVar8 != '\0');
          break;
        case 5:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10 + iVar12) = cVar8;
            iVar13 = iVar10 + 1;
            cVar8 = "PP_NOTEQUAL "[iVar10 + 1];
            iVar10 = iVar13;
          } while (cVar8 != '\0');
          break;
        case 6:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10 + iVar12) = cVar8;
            iVar13 = iVar10 + 1;
            cVar8 = "PP_GEQUAL "[iVar10 + 1];
            iVar10 = iVar13;
          } while (cVar8 != '\0');
          break;
        default:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10 + iVar12) = cVar8;
            iVar13 = iVar10 + 1;
            cVar8 = "PP_ALWAYS "[iVar10 + 1];
            iVar10 = iVar13;
          } while (cVar8 != '\0');
        }
        cVar8 = 'r';
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10 + iVar13 + iVar12) = cVar8;
          iVar14 = iVar10 + 1;
          cVar8 = "ref="[iVar10 + 1];
          iVar10 = iVar14;
        } while (cVar8 != '\0');
        local_a8 = (int *)((int)local_a8 + iVar14 + iVar13 + iVar12);
        local_a8 = (int *)((char * (*)())_glp_dtostr)((int)((ulonglong)uVar25 >> 0x20),(int)uVar25,local_a8,
                                      (int)local_ac + (local_b0 - (int)local_a8),
                                      (double)(float)param_1[uVar18 * 2 + iVar9 * 2 + 1],1e-07,in_f3
                                      ,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_fffffd08,
                                      in_stack_fffffd10,in_stack_fffffd18,in_stack_fffffd20,
                                      in_stack_fffffd28);
        goto switchD_97bee2f0_default;
      case 1:
        cVar8 = 'S';
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10) = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = "STENCIL_TEST func="[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
        switch(param_1[uVar18 * 2 + iVar9 * 2] >> 0xc & 7) {
        case 0:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10 + iVar12) = cVar8;
            iVar13 = iVar10 + 1;
            cVar8 = "PP_NEVER "[iVar10 + 1];
            iVar10 = iVar13;
          } while (cVar8 != '\0');
          break;
        case 1:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10 + iVar12) = cVar8;
            iVar13 = iVar10 + 1;
            cVar8 = "PP_LESS "[iVar10 + 1];
            iVar10 = iVar13;
          } while (cVar8 != '\0');
          break;
        case 2:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10 + iVar12) = cVar8;
            iVar13 = iVar10 + 1;
            cVar8 = "PP_EQUAL "[iVar10 + 1];
            iVar10 = iVar13;
          } while (cVar8 != '\0');
          break;
        case 3:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10 + iVar12) = cVar8;
            iVar13 = iVar10 + 1;
            cVar8 = "PP_LEQUAL "[iVar10 + 1];
            iVar10 = iVar13;
          } while (cVar8 != '\0');
          break;
        case 4:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10 + iVar12) = cVar8;
            iVar13 = iVar10 + 1;
            cVar8 = "PP_GREATER "[iVar10 + 1];
            iVar10 = iVar13;
          } while (cVar8 != '\0');
          break;
        case 5:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10 + iVar12) = cVar8;
            iVar13 = iVar10 + 1;
            cVar8 = "PP_NOTEQUAL "[iVar10 + 1];
            iVar10 = iVar13;
          } while (cVar8 != '\0');
          break;
        case 6:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10 + iVar12) = cVar8;
            iVar13 = iVar10 + 1;
            cVar8 = "PP_GEQUAL "[iVar10 + 1];
            iVar10 = iVar13;
          } while (cVar8 != '\0');
          break;
        default:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10 + iVar12) = cVar8;
            iVar13 = iVar10 + 1;
            cVar8 = "PP_ALWAYS "[iVar10 + 1];
            iVar10 = iVar13;
          } while (cVar8 != '\0');
        }
        cVar8 = 'o';
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10 + iVar13 + iVar12) = cVar8;
          iVar14 = iVar10 + 1;
          cVar8 = "opfail="[iVar10 + 1];
          iVar10 = iVar14;
        } while (cVar8 != '\0');
        puVar17 = (undefined1 *)((int)local_a8 + iVar14 + iVar13 + iVar12);
        switch(param_1[uVar18 * 2 + iVar9 * 2] >> 0xf & 7) {
        case 0:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_STENCIL_ZERO "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 1:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_STENCIL_KEEP "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 2:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_STENCIL_REPLACE "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 3:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_STENCIL_INCR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 4:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_STENCIL_DECR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 5:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_STENCIL_INVERT "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 6:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_STENCIL_INCR_WRAP "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 7:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_STENCIL_DECR_WRAP "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        default:
          goto switchD_97bee894_default;
        }
        puVar17 = puVar17 + iVar12;
switchD_97bee894_default:
        cVar8 = 'o';
        iVar10 = 0;
        do {
          puVar17[iVar10] = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = "opzfail="[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
        puVar17 = puVar17 + iVar12;
        switch(param_1[uVar18 * 2 + iVar9 * 2] >> 0x12 & 7) {
        case 0:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_STENCIL_ZERO "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 1:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_STENCIL_KEEP "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 2:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_STENCIL_REPLACE "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 3:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_STENCIL_INCR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 4:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_STENCIL_DECR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 5:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_STENCIL_INVERT "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 6:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_STENCIL_INCR_WRAP "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 7:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_STENCIL_DECR_WRAP "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        default:
          goto switchD_97beeaec_default;
        }
        puVar17 = puVar17 + iVar12;
switchD_97beeaec_default:
        cVar8 = 'o';
        iVar10 = 0;
        do {
          puVar17[iVar10] = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = "opzpass="[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
        local_a8 = (int *)(puVar17 + iVar12);
        switch(param_1[uVar18 * 2 + iVar9 * 2] >> 0x15 & 7) {
        case 0:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_STENCIL_ZERO "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 1:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_STENCIL_KEEP "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 2:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_STENCIL_REPLACE "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 3:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_STENCIL_INCR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 4:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_STENCIL_DECR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 5:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_STENCIL_INVERT "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 6:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_STENCIL_INCR_WRAP "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 7:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_STENCIL_DECR_WRAP "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        default:
          goto switchD_97beed44_default;
        }
        local_a8 = (int *)((int)local_a8 + iVar12);
switchD_97beed44_default:
        _sprintf(&local_2b0,"ref= %#x mask = %#x ",param_1[uVar18 * 2 + iVar9 * 2 + 1] >> 0x18,
                 param_1[uVar18 * 2 + iVar9 * 2 + 1] >> 8 & 0xff);
        iVar10 = 0;
        cVar8 = local_2b0;
        while (cVar8 != '\0') {
          *(char *)((int)local_a8 + iVar10) = cVar8;
          cVar8 = acStack_2af[iVar10];
          iVar10 = iVar10 + 1;
        }
        break;
      case 2:
        cVar8 = 'D';
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10) = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = "DEPTH_TEST func="[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
        local_a8 = (int *)((int)local_a8 + iVar12);
        switch(param_1[uVar18 * 2 + iVar9 * 2] & 7) {
        case 0:
          cVar8 = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)local_a8 + iVar12) = cVar8;
            iVar10 = iVar12 + 1;
            cVar8 = "PP_NEVER "[iVar12 + 1];
            iVar12 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 1:
          cVar8 = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)local_a8 + iVar12) = cVar8;
            iVar10 = iVar12 + 1;
            cVar8 = "PP_LESS "[iVar12 + 1];
            iVar12 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 2:
          cVar8 = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)local_a8 + iVar12) = cVar8;
            iVar10 = iVar12 + 1;
            cVar8 = "PP_EQUAL "[iVar12 + 1];
            iVar12 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 3:
          cVar8 = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)local_a8 + iVar12) = cVar8;
            iVar10 = iVar12 + 1;
            cVar8 = "PP_LEQUAL "[iVar12 + 1];
            iVar12 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 4:
          cVar8 = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)local_a8 + iVar12) = cVar8;
            iVar10 = iVar12 + 1;
            cVar8 = "PP_GREATER "[iVar12 + 1];
            iVar12 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 5:
          cVar8 = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)local_a8 + iVar12) = cVar8;
            iVar10 = iVar12 + 1;
            cVar8 = "PP_NOTEQUAL "[iVar12 + 1];
            iVar12 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 6:
          cVar8 = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)local_a8 + iVar12) = cVar8;
            iVar10 = iVar12 + 1;
            cVar8 = "PP_GEQUAL "[iVar12 + 1];
            iVar12 = iVar10;
          } while (cVar8 != '\0');
          break;
        default:
          cVar8 = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)local_a8 + iVar12) = cVar8;
            iVar10 = iVar12 + 1;
            cVar8 = "PP_ALWAYS "[iVar12 + 1];
            iVar12 = iVar10;
          } while (cVar8 != '\0');
        }
        break;
      case 3:
        cVar8 = 'B';
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10) = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = "BLENDING \n\talpha equ = "[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
        puVar17 = (undefined1 *)((int)local_a8 + iVar12);
        switch(param_1[uVar18 * 2 + iVar9 * 2] >> 0x13 & 7) {
        case 0:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_FUNC_ADD "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 1:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_FUNC_SUBTRACT "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 2:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_FUNC_REVERSE_SUBTRACT "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 3:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_FUNC_MIN "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 4:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_FUNC_MAX "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        default:
          goto switchD_97bef244_default;
        }
        puVar17 = puVar17 + iVar12;
switchD_97bef244_default:
        cVar8 = '\n';
        iVar10 = 0;
        do {
          puVar17[iVar10] = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = "\n\trgb equ = "[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
        puVar17 = puVar17 + iVar12;
        switch(param_1[uVar18 * 2 + iVar9 * 2] >> 0x10 & 7) {
        case 0:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_FUNC_ADD "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 1:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_FUNC_SUBTRACT "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 2:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_FUNC_REVERSE_SUBTRACT "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 3:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_FUNC_MIN "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 4:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_FUNC_MAX "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        default:
          goto switchD_97bef3e8_default;
        }
        puVar17 = puVar17 + iVar12;
switchD_97bef3e8_default:
        cVar8 = '\n';
        iVar10 = 0;
        do {
          puVar17[iVar10] = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = "\n\tsrc = "[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
        puVar17 = puVar17 + iVar12;
        switch(param_1[uVar18 * 2 + iVar9 * 2] & 0xf) {
        case 0:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_ZERO "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 1:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_ONE "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 2:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_SRC_COLOR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 3:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_ONE_MINUS_SRC_COLOR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 4:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_SRC_ALPHA "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 5:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_ONE_MINUS_SRC_ALPHA "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 6:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_DST_ALPHA "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 7:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_ONE_MINUS_DST_ALPHA "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 8:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_CONSTANT_COLOR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 9:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_ONE_MINUS_CONSTANT_COLOR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 10:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_CONSTANT_ALPHA "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 0xb:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_ONE_MINUS_CONSTANT_ALPHA "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 0xc:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_DST_COLOR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 0xd:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_ONE_MINUS_DST_COLOR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 0xe:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_SRC_ALPHA_SATURATE "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        default:
          goto switchD_97bef58c_default;
        }
        puVar17 = puVar17 + iVar12;
switchD_97bef58c_default:
        cVar8 = '\n';
        iVar10 = 0;
        do {
          puVar17[iVar10] = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = "\n\tsrcA = "[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
        puVar17 = puVar17 + iVar12;
        switch(param_1[uVar18 * 2 + iVar9 * 2] >> 4 & 0xf) {
        case 0:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_ZERO "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 1:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_ONE "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 2:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_SRC_COLOR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 3:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_ONE_MINUS_SRC_COLOR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 4:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_SRC_ALPHA "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 5:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_ONE_MINUS_SRC_ALPHA "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 6:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_DST_ALPHA "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 7:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_ONE_MINUS_DST_ALPHA "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 8:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_CONSTANT_COLOR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 9:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_ONE_MINUS_CONSTANT_COLOR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 10:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_CONSTANT_ALPHA "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 0xb:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_ONE_MINUS_CONSTANT_ALPHA "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 0xc:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_DST_COLOR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 0xd:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_ONE_MINUS_DST_COLOR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 0xe:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_SRC_ALPHA_SATURATE "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        default:
          goto switchD_97bef988_default;
        }
        puVar17 = puVar17 + iVar12;
switchD_97bef988_default:
        cVar8 = '\n';
        iVar10 = 0;
        do {
          puVar17[iVar10] = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = "\n\tdst = "[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
        puVar17 = puVar17 + iVar12;
        switch(param_1[uVar18 * 2 + iVar9 * 2] >> 8 & 0xf) {
        case 0:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_ZERO "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 1:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_ONE "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 2:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_SRC_COLOR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 3:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_ONE_MINUS_SRC_COLOR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 4:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_SRC_ALPHA "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 5:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_ONE_MINUS_SRC_ALPHA "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 6:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_DST_ALPHA "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 7:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_ONE_MINUS_DST_ALPHA "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 8:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_CONSTANT_COLOR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 9:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_ONE_MINUS_CONSTANT_COLOR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 10:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_CONSTANT_ALPHA "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 0xb:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_ONE_MINUS_CONSTANT_ALPHA "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 0xc:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_DST_COLOR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 0xd:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_ONE_MINUS_DST_COLOR "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        case 0xe:
          cVar8 = 'P';
          iVar10 = 0;
          do {
            puVar17[iVar10] = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "PP_BLEND_SRC_ALPHA_SATURATE "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          break;
        default:
          goto switchD_97befd84_default;
        }
        puVar17 = puVar17 + iVar12;
switchD_97befd84_default:
        cVar8 = '\n';
        iVar10 = 0;
        do {
          puVar17[iVar10] = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = "\n\tdstA = "[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
        local_a8 = (int *)(puVar17 + iVar12);
        switch(param_1[uVar18 * 2 + iVar9 * 2] >> 0xc & 0xf) {
        case 0:
          cVar8 = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)local_a8 + iVar12) = cVar8;
            iVar10 = iVar12 + 1;
            cVar8 = "PP_BLEND_ZERO "[iVar12 + 1];
            iVar12 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 1:
          cVar8 = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)local_a8 + iVar12) = cVar8;
            iVar10 = iVar12 + 1;
            cVar8 = "PP_BLEND_ONE "[iVar12 + 1];
            iVar12 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 2:
          cVar8 = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)local_a8 + iVar12) = cVar8;
            iVar10 = iVar12 + 1;
            cVar8 = "PP_BLEND_SRC_COLOR "[iVar12 + 1];
            iVar12 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 3:
          cVar8 = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)local_a8 + iVar12) = cVar8;
            iVar10 = iVar12 + 1;
            cVar8 = "PP_BLEND_ONE_MINUS_SRC_COLOR "[iVar12 + 1];
            iVar12 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 4:
          cVar8 = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)local_a8 + iVar12) = cVar8;
            iVar10 = iVar12 + 1;
            cVar8 = "PP_BLEND_SRC_ALPHA "[iVar12 + 1];
            iVar12 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 5:
          cVar8 = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)local_a8 + iVar12) = cVar8;
            iVar10 = iVar12 + 1;
            cVar8 = "PP_BLEND_ONE_MINUS_SRC_ALPHA "[iVar12 + 1];
            iVar12 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 6:
          cVar8 = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)local_a8 + iVar12) = cVar8;
            iVar10 = iVar12 + 1;
            cVar8 = "PP_BLEND_DST_ALPHA "[iVar12 + 1];
            iVar12 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 7:
          cVar8 = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)local_a8 + iVar12) = cVar8;
            iVar10 = iVar12 + 1;
            cVar8 = "PP_BLEND_ONE_MINUS_DST_ALPHA "[iVar12 + 1];
            iVar12 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 8:
          cVar8 = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)local_a8 + iVar12) = cVar8;
            iVar10 = iVar12 + 1;
            cVar8 = "PP_BLEND_CONSTANT_COLOR "[iVar12 + 1];
            iVar12 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 9:
          cVar8 = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)local_a8 + iVar12) = cVar8;
            iVar10 = iVar12 + 1;
            cVar8 = "PP_BLEND_ONE_MINUS_CONSTANT_COLOR "[iVar12 + 1];
            iVar12 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 10:
          cVar8 = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)local_a8 + iVar12) = cVar8;
            iVar10 = iVar12 + 1;
            cVar8 = "PP_BLEND_CONSTANT_ALPHA "[iVar12 + 1];
            iVar12 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 0xb:
          cVar8 = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)local_a8 + iVar12) = cVar8;
            iVar10 = iVar12 + 1;
            cVar8 = "PP_BLEND_ONE_MINUS_CONSTANT_ALPHA "[iVar12 + 1];
            iVar12 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 0xc:
          cVar8 = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)local_a8 + iVar12) = cVar8;
            iVar10 = iVar12 + 1;
            cVar8 = "PP_BLEND_DST_COLOR "[iVar12 + 1];
            iVar12 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 0xd:
          cVar8 = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)local_a8 + iVar12) = cVar8;
            iVar10 = iVar12 + 1;
            cVar8 = "PP_BLEND_ONE_MINUS_DST_COLOR "[iVar12 + 1];
            iVar12 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 0xe:
          cVar8 = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)local_a8 + iVar12) = cVar8;
            iVar10 = iVar12 + 1;
            cVar8 = "PP_BLEND_SRC_ALPHA_SATURATE "[iVar12 + 1];
            iVar12 = iVar10;
          } while (cVar8 != '\0');
          break;
        default:
          goto switchD_97bee2f0_default;
        }
        break;
      case 4:
        cVar8 = 'D';
        iVar12 = 0;
        do {
          *(char *)((int)local_a8 + iVar12) = cVar8;
          iVar10 = iVar12 + 1;
          cVar8 = "DITHERING ENABLED"[iVar12 + 1];
          iVar12 = iVar10;
        } while (cVar8 != '\0');
        break;
      case 5:
        cVar8 = 'L';
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10) = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = "LOGIC_OP "[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
        local_a8 = (int *)((int)local_a8 + iVar12);
        switch(param_1[uVar18 * 2 + iVar9 * 2] & 0xf) {
        case 0:
          cVar8 = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)local_a8 + iVar12) = cVar8;
            iVar10 = iVar12 + 1;
            cVar8 = "PP_LOGIC_CLEAR"[iVar12 + 1];
            iVar12 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 1:
          cVar8 = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)local_a8 + iVar12) = cVar8;
            iVar10 = iVar12 + 1;
            cVar8 = "PP_LOGIC_SET"[iVar12 + 1];
            iVar12 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 2:
          cVar8 = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)local_a8 + iVar12) = cVar8;
            iVar10 = iVar12 + 1;
            cVar8 = "PP_LOGIC_COPY"[iVar12 + 1];
            iVar12 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 3:
          cVar8 = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)local_a8 + iVar12) = cVar8;
            iVar10 = iVar12 + 1;
            cVar8 = "PP_LOGIC_COPY_INVERTED"[iVar12 + 1];
            iVar12 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 4:
          cVar8 = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)local_a8 + iVar12) = cVar8;
            iVar10 = iVar12 + 1;
            cVar8 = "PP_LOGIC_NOOP"[iVar12 + 1];
            iVar12 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 5:
          cVar8 = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)local_a8 + iVar12) = cVar8;
            iVar10 = iVar12 + 1;
            cVar8 = "PP_LOGIC_INVERT"[iVar12 + 1];
            iVar12 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 6:
          cVar8 = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)local_a8 + iVar12) = cVar8;
            iVar10 = iVar12 + 1;
            cVar8 = "PP_LOGIC_AND"[iVar12 + 1];
            iVar12 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 7:
          cVar8 = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)local_a8 + iVar12) = cVar8;
            iVar10 = iVar12 + 1;
            cVar8 = "PP_LOGIC_NAND"[iVar12 + 1];
            iVar12 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 8:
          cVar8 = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)local_a8 + iVar12) = cVar8;
            iVar10 = iVar12 + 1;
            cVar8 = "PP_LOGIC_OR"[iVar12 + 1];
            iVar12 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 9:
          cVar8 = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)local_a8 + iVar12) = cVar8;
            iVar10 = iVar12 + 1;
            cVar8 = "PP_LOGIC_NOR"[iVar12 + 1];
            iVar12 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 10:
          cVar8 = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)local_a8 + iVar12) = cVar8;
            iVar10 = iVar12 + 1;
            cVar8 = "PP_LOGIC_XOR"[iVar12 + 1];
            iVar12 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 0xb:
          cVar8 = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)local_a8 + iVar12) = cVar8;
            iVar10 = iVar12 + 1;
            cVar8 = "PP_LOGIC_EQUIV"[iVar12 + 1];
            iVar12 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 0xc:
          cVar8 = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)local_a8 + iVar12) = cVar8;
            iVar10 = iVar12 + 1;
            cVar8 = "PP_LOGIC_AND_REVERSE"[iVar12 + 1];
            iVar12 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 0xd:
          cVar8 = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)local_a8 + iVar12) = cVar8;
            iVar10 = iVar12 + 1;
            cVar8 = "PP_LOGIC_AND_INVERTED"[iVar12 + 1];
            iVar12 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 0xe:
          cVar8 = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)local_a8 + iVar12) = cVar8;
            iVar10 = iVar12 + 1;
            cVar8 = "PP_LOGIC_OR_REVERSE"[iVar12 + 1];
            iVar12 = iVar10;
          } while (cVar8 != '\0');
          break;
        case 0xf:
          cVar8 = 'P';
          iVar12 = 0;
          do {
            *(char *)((int)local_a8 + iVar12) = cVar8;
            iVar10 = iVar12 + 1;
            cVar8 = "PP_LOGIC_OR_INVERTED"[iVar12 + 1];
            iVar12 = iVar10;
          } while (cVar8 != '\0');
          break;
        default:
          goto switchD_97bee2f0_default;
        }
        break;
      case 6:
        cVar8 = 'B';
        iVar10 = 0;
        do {
          *(char *)((int)local_a8 + iVar10) = cVar8;
          iVar12 = iVar10 + 1;
          cVar8 = "BUFFER_MASK "[iVar10 + 1];
          iVar10 = iVar12;
        } while (cVar8 != '\0');
        local_a8 = (int *)((int)local_a8 + iVar12);
        if ((param_1[uVar18 * 2 + iVar9 * 2] & 0x20000) == 0) {
          cVar8 = 'R';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "RED MASKED "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          local_a8 = (int *)((int)local_a8 + iVar12);
        }
        if ((param_1[uVar18 * 2 + iVar9 * 2] & 0x40000) == 0) {
          cVar8 = 'G';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "GREEN MASKED "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          local_a8 = (int *)((int)local_a8 + iVar12);
        }
        if ((param_1[uVar18 * 2 + iVar9 * 2] & 0x80000) == 0) {
          cVar8 = 'B';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "BLUE MASKED "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          local_a8 = (int *)((int)local_a8 + iVar12);
        }
        if ((param_1[uVar18 * 2 + iVar9 * 2] & 0x100000) == 0) {
          cVar8 = 'A';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "ALPHA MASKED "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          local_a8 = (int *)((int)local_a8 + iVar12);
        }
        if ((param_1[uVar18 * 2 + iVar9 * 2] & 0x10000) == 0) {
          cVar8 = 'D';
          iVar10 = 0;
          do {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar12 = iVar10 + 1;
            cVar8 = "DEPTH MASKED "[iVar10 + 1];
            iVar10 = iVar12;
          } while (cVar8 != '\0');
          local_a8 = (int *)((int)local_a8 + iVar12);
        }
        if (*(char *)((int)param_1 + iVar9 * 8 + uVar18 * 8 + 2) != -1) {
          _sprintf(local_1b0,"STENCIL MASK = %0x",param_1[uVar18 * 2 + iVar9 * 2] >> 8 & 0xff);
          iVar10 = 0;
          cVar8 = local_1b0[0];
          while (cVar8 != '\0') {
            *(char *)((int)local_a8 + iVar10) = cVar8;
            iVar10 = iVar10 + 1;
            cVar8 = local_1b0[iVar10];
          }
          break;
        }
      default:
        goto switchD_97bee2f0_default;
      }
      local_a8 = (int *)((int)local_a8 + iVar10);
switchD_97bee2f0_default:
      iVar10 = 0;
      cVar8 = local_60[0x3bbc];
      while (cVar8 != '\0') {
        *(char *)((int)local_a8 + iVar10) = cVar8;
        iVar10 = iVar10 + 1;
        cVar8 = (local_60 + 0x3bbc)[iVar10];
      }
      local_a8 = (int *)((int)local_a8 + iVar10);
      uVar25 = ((int (*)())_adjustAllocation_97be9cb4)(&local_b0,&local_ac,&local_a8);
      if ((int)((ulonglong)uVar25 >> 0x20) == 0) goto joined_r0x97beb668;
      iVar21 = iVar21 + 1;
      iVar9 = iVar9 + 1;
    } while (iVar21 < (int)uVar6);
  }
  piVar15 = (int *)((int)local_a8 + 1);
  *(undefined1 *)local_a8 = 0;
  local_a8 = piVar15;
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
  if (0 < (int)local_a8 - (int)local_ac) {
    _realloc(local_ac,(int)local_a8 - (int)local_ac);
    return extraout_f1_00;
  }
  _free(local_ac);
  return extraout_f1_02;
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
int _PPStreamChunkCompare(param_1, param_2)
  char *param_1;
  char *param_2;
{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = 1;
  if (*param_2 == *param_1) {
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
      uVar1 = *(undefined4 *)(param_1 + 0x40);
      *(undefined4 *)(param_2 + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
      *(undefined4 *)(param_2 + 0x40) = uVar1;
      break;
    default:
      return 1;
    }
    iVar2 = _memcmp(param_1 + 0xc,param_2 + 0xc,uVar3);
    uVar1 = 1;
    if (iVar2 == 0) {
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* _PPStreamChunkListInsertChunkBeforeChunk @ 0x97bf0f14 (84 bytes) */
int _PPStreamChunkListInsertChunkBeforeChunk(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  undefined4 uVar1;
  
  if (param_3 == 0) {
    _PPStreamChunkListAddChunk(param_1,param_2);
    return;
  }
  uVar1 = *(undefined4 *)(param_3 + 4);
  *(int *)(param_2 + 8) = param_3;
  *(undefined4 *)(param_2 + 4) = uVar1;
  if (*(int *)(param_3 + 4) != 0) {
    *(int *)(*(int *)(param_3 + 4) + 8) = param_2;
  }
  *(int *)(param_3 + 4) = param_2;
  if (*param_1 == param_3) {
    *param_1 = param_2;
  }
  param_1[2] = param_1[2] + 1;
  return;
}

/* _PPStreamChunkListInsertChunkAfterChunk @ 0x97bf0f68 (116 bytes) */
int _PPStreamChunkListInsertChunkAfterChunk(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  undefined4 uVar1;
  
  if (param_3 == 0) {
    *(undefined4 *)(param_2 + 4) = 0;
    if (*param_1 == 0) {
      *(undefined4 *)(param_2 + 8) = 0;
    }
    else {
      *(int *)(param_2 + 8) = *param_1;
      *(int *)(*param_1 + 4) = param_2;
    }
    *param_1 = param_2;
  }
  else {
    uVar1 = *(undefined4 *)(param_3 + 8);
    *(int *)(param_2 + 4) = param_3;
    *(undefined4 *)(param_2 + 8) = uVar1;
    if (*(int *)(param_3 + 8) != 0) {
      *(int *)(*(int *)(param_3 + 8) + 4) = param_2;
    }
    *(int *)(param_3 + 8) = param_2;
    if (param_1[1] == param_3) {
      param_1[1] = param_2;
    }
  }
  param_1[2] = param_1[2] + 1;
  return;
}

/* _PPStreamChunkListRemoveChunkNoFree @ 0x97bf0fdc (88 bytes) */
int _PPStreamChunkListRemoveChunkNoFree(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 4);
  if (iVar1 == 0) {
    *param_1 = *(undefined4 *)(param_2 + 8);
    iVar1 = *(int *)(param_2 + 4);
  }
  else {
    *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(param_2 + 8);
  }
  if (*(int *)(param_2 + 8) == 0) {
    param_1[1] = iVar1;
  }
  else {
    *(int *)(*(int *)(param_2 + 8) + 4) = iVar1;
  }
  *(undefined4 *)(param_2 + 8) = 0;
  *(undefined4 *)(param_2 + 4) = 0;
  param_1[2] = param_1[2] + -1;
  return;
}

/* _PPStreamChunkListCompare @ 0x97bf1034 (132 bytes) */
int _PPStreamChunkListCompare(param_1, param_2)
  int *param_1;
  int *param_2;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *param_1;
  uVar1 = 1;
  iVar4 = *param_2;
  if (param_1[2] == param_2[2]) {
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
int _PPStreamDuplicate(param_1)
  undefined4 *param_1;
{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  puVar2 = (undefined4 *)_PPStreamCreate();
  piVar1 = (int *)param_1[1];
  *puVar2 = *param_1;
  for (iVar4 = *piVar1; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar3 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar2[1],uVar3);
  }
  for (iVar4 = *(int *)param_1[2]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar3 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar2[2],uVar3);
  }
  for (iVar4 = *(int *)param_1[3]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar3 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar2[3],uVar3);
  }
  for (iVar4 = *(int *)param_1[4]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar3 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar2[4],uVar3);
  }
  for (iVar4 = *(int *)param_1[5]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar3 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar2[5],uVar3);
  }
  for (iVar4 = *(int *)param_1[6]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar3 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar2[6],uVar3);
  }
  for (iVar4 = *(int *)param_1[7]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar3 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar2[7],uVar3);
  }
  for (iVar4 = *(int *)param_1[8]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar3 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar2[8],uVar3);
  }
  for (iVar4 = *(int *)param_1[9]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar3 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar2[9],uVar3);
  }
  for (iVar4 = *(int *)param_1[0xb]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar3 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar2[0xb],uVar3);
  }
  for (iVar4 = *(int *)param_1[10]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar3 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar2[10],uVar3);
  }
  for (iVar4 = *(int *)param_1[0xc]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
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
  _PPStreamChunkListAddChunk(uVar2,puVar1);
  return;
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
  _PPStreamChunkListAddChunk(uVar2,puVar1);
  return;
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
  _PPStreamChunkListAddChunk(uVar2,puVar1);
  return;
}

/* _PPStreamInsertOperationBeforeChunk @ 0x97bf1440 (288 bytes) */
int _PPStreamInsertOperationBeforeChunk(param_1, param_2, param_3, param_4, param_5)
  int param_1;
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
    iVar3 = _PPStreamChunkListGetMaxIndex(*(undefined4 *)(param_1 + 0x20));
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
  ((int (*)())_PPStreamChunkListInsertChunkBeforeChunk)(*(undefined4 *)(param_1 + 0x20),puVar4,param_5);
  return puVar4;
}

/* _PPStreamInsertOperationAfterChunk @ 0x97bf1560 (236 bytes) */
int _PPStreamInsertOperationAfterChunk(param_1, param_2, param_3, param_4, param_5)
  int param_1;
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
    iVar2 = _PPStreamChunkListGetMaxIndex(*(undefined4 *)(param_1 + 0x20));
    uVar1 = iVar2 + 1U & 0x3ffff | *(uint *)(puVar3 + 0xc) & 0xfffc0000;
  }
  else {
    uVar1 = *(uint *)(puVar3 + 0xc) & 0xfffc0000;
  }
  *(uint *)(puVar3 + 0xc) = uVar1;
  ((int (*)())_PPStreamChunkListInsertChunkAfterChunk)(*(undefined4 *)(param_1 + 0x20),puVar3,param_5);
  return puVar3;
}

/* _PPStreamAddLabel @ 0x97bf164c (128 bytes) */
int _PPStreamAddLabel(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  undefined1 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  puVar1 = (undefined1 *)_calloc(param_3 + 0x15,1);
  uVar2 = *(undefined4 *)(param_1 + 0x20);
  *puVar1 = 0xb;
  *(int *)(puVar1 + 0x10) = param_3;
  iVar3 = _PPStreamChunkListGetMaxIndex(uVar2);
  *(int *)(puVar1 + 0xc) = iVar3 + 1;
  _memmove(puVar1 + 0x14,param_2,param_3);
  uVar2 = *(undefined4 *)(param_1 + 0x24);
  puVar1[param_3 + 0x14] = 0;
  _PPStreamChunkListAddChunk(uVar2,puVar1);
  return;
}

/* _PPStreamRemoveLabelsAtOperationIndex @ 0x97bf16cc (96 bytes) */
int _PPStreamRemoveLabelsAtOperationIndex(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = **(int **)(param_1 + 0x24);
  while (iVar1 = iVar2, iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 8);
    if (*(int *)(iVar1 + 0xc) == param_2) {
      _PPStreamChunkListRemoveChunk(*(undefined4 *)(param_1 + 0x24),iVar1);
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
  _PPStreamChunkListAddChunk(uVar2,puVar1);
  return;
}

/* _PPStreamAttachStream @ 0x97bf1788 (1212 bytes) */
int _PPStreamAttachStream(param_1, param_2)
  undefined4 *param_1;
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
  *param_1 = *param_2;
  if (param_2[6] != 0) {
    do {
      puVar5 = (undefined1 *)_calloc(0x10,1);
      *(uint *)(puVar5 + 0xc) = uVar7;
      *puVar5 = 1;
      uVar7 = uVar7 + 1;
      _PPStreamChunkListAddChunk(param_1[3],puVar5);
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
      _PPStreamChunkListAddChunk(param_1[1],puVar5);
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
      _PPStreamChunkListAddChunk(param_1[6],puVar5);
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
      _PPStreamChunkListAddChunk(param_1[4],puVar5);
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
      _PPStreamChunkListAddChunk(param_1[7],puVar5);
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
      _PPStreamChunkListAddChunk(param_1[5],puVar5);
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
      _PPStreamChunkListAddChunk(param_1[2],puVar5);
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
      _PPStreamChunkListAddChunk(param_1[0xc],puVar5);
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
      _PPStreamChunkListAddChunk(param_1[8],puVar5);
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
      _PPStreamChunkListAddChunk(param_1[10],puVar5);
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
      _PPStreamChunkListAddChunk(param_1[0xb],puVar5);
    } while (uVar7 < (uint)param_2[0x1a]);
  }
  return 0;
}

/* _PPStreamCompare @ 0x97bf1c44 (328 bytes) */
int _PPStreamCompare(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int iVar1;
  bool bVar2;
  
  bVar2 = true;
  if (*param_1 == *param_2) {
    iVar1 = ((int (*)())_PPStreamChunkListCompare)(param_1[1],param_2[1]);
    bVar2 = true;
    if (iVar1 == 0) {
      iVar1 = ((int (*)())_PPStreamChunkListCompare)(param_1[3],param_2[3]);
      bVar2 = true;
      if (iVar1 == 0) {
        iVar1 = ((int (*)())_PPStreamChunkListCompare)(param_1[4],param_2[4]);
        bVar2 = true;
        if (iVar1 == 0) {
          iVar1 = ((int (*)())_PPStreamChunkListCompare)(param_1[5],param_2[5]);
          bVar2 = true;
          if (iVar1 == 0) {
            iVar1 = ((int (*)())_PPStreamChunkListCompare)(param_1[2],param_2[2]);
            bVar2 = true;
            if (iVar1 == 0) {
              iVar1 = ((int (*)())_PPStreamChunkListCompare)(param_1[6],param_2[6]);
              bVar2 = true;
              if (iVar1 == 0) {
                iVar1 = ((int (*)())_PPStreamChunkListCompare)(param_1[7],param_2[7]);
                bVar2 = true;
                if (iVar1 == 0) {
                  iVar1 = ((int (*)())_PPStreamChunkListCompare)(param_1[8],param_2[8]);
                  bVar2 = true;
                  if (iVar1 == 0) {
                    iVar1 = ((int (*)())_PPStreamChunkListCompare)(param_1[0xb],param_2[0xb]);
                    bVar2 = true;
                    if (iVar1 == 0) {
                      iVar1 = ((int (*)())_PPStreamChunkListCompare)(param_1[10],param_2[10]);
                      bVar2 = true;
                      if (iVar1 == 0) {
                        iVar1 = ((int (*)())_PPStreamChunkListCompare)(param_1[0xc],param_2[0xc]);
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
int _PPStreamChangeBranchTargets(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_renumberLabels)(**(undefined4 **)(param_1 + 0x24),param_2,param_3,0);
  ((int (*)())_renumberTargets)(**(undefined4 **)(param_1 + 0x20),param_2,param_3,0);
  return;
}

/* _PPStreamPackIndices @ 0x97bf20fc (612 bytes) */
int _PPStreamPackIndices(param_1)
  int param_1;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = 0;
  for (iVar3 = **(int **)(param_1 + 4); iVar3 != 0; iVar3 = *(int *)(iVar3 + 8)) {
    if (*(ushort *)(iVar3 + 0x12) != uVar2) {
      ((int (*)())_PPStreamRenumberOperandIndices)(param_1,iVar3,uVar2);
      ((int (*)())_renumberTempArrayIndices)(**(undefined4 **)(param_1 + 8),(uint)*(ushort *)(iVar3 + 0x12),uVar2);
      *(short *)(iVar3 + 0x12) = (short)uVar2;
    }
    uVar2 = uVar2 + 1;
  }
  iVar3 = 0;
  for (iVar4 = **(int **)(param_1 + 0xc); iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    if (*(int *)(iVar4 + 0xc) != iVar3) {
      ((int (*)())_PPStreamRenumberOperandIndices)(param_1,iVar4,iVar3);
      *(int *)(iVar4 + 0xc) = iVar3;
    }
    iVar3 = iVar3 + 1;
  }
  uVar2 = 0;
  for (iVar3 = **(int **)(param_1 + 0x10); iVar3 != 0; iVar3 = *(int *)(iVar3 + 8)) {
    if (*(ushort *)(iVar3 + 0x12) != uVar2) {
      ((int (*)())_PPStreamRenumberOperandIndices)(param_1,iVar3,uVar2);
      ((int (*)())_renumberParamArrayIndices)(**(undefined4 **)(param_1 + 0x14),(uint)*(ushort *)(iVar3 + 0x12),uVar2);
      *(short *)(iVar3 + 0x12) = (short)uVar2;
    }
    uVar2 = uVar2 + 1;
  }
  uVar2 = 0;
  for (iVar3 = **(int **)(param_1 + 0x18); iVar3 != 0; iVar3 = *(int *)(iVar3 + 8)) {
    if (*(ushort *)(iVar3 + 0x12) != uVar2) {
      ((int (*)())_PPStreamRenumberOperandIndices)(param_1,iVar3,uVar2);
      *(short *)(iVar3 + 0x12) = (short)uVar2;
    }
    uVar2 = uVar2 + 1;
  }
  uVar2 = 0;
  for (iVar3 = **(int **)(param_1 + 0x1c); iVar3 != 0; iVar3 = *(int *)(iVar3 + 8)) {
    if (*(ushort *)(iVar3 + 0x12) != uVar2) {
      ((int (*)())_PPStreamRenumberOperandIndices)(param_1,iVar3,uVar2);
      *(short *)(iVar3 + 0x12) = (short)uVar2;
    }
    uVar2 = uVar2 + 1;
  }
  for (iVar3 = **(int **)(param_1 + 0x20); iVar3 != 0; iVar3 = *(int *)(iVar3 + 8)) {
    *(undefined1 *)(iVar3 + 1) = 0;
  }
  for (iVar3 = **(int **)(param_1 + 0x24); iVar3 != 0; iVar3 = *(int *)(iVar3 + 8)) {
    *(undefined1 *)(iVar3 + 1) = 0;
  }
  uVar2 = 1;
  for (iVar3 = **(int **)(param_1 + 0x20); iVar3 != 0; iVar3 = *(int *)(iVar3 + 8)) {
    uVar1 = *(uint *)(iVar3 + 0xc) & 0x3ffff;
    if ((uVar1 != 0) && (uVar1 != uVar2)) {
      ((int (*)())_renumberLabels)(**(undefined4 **)(param_1 + 0x24),uVar1,uVar2,1);
      ((int (*)())_renumberTargets)(**(undefined4 **)(param_1 + 0x20),*(uint *)(iVar3 + 0xc) & 0x3ffff,uVar2,1);
      *(uint *)(iVar3 + 0xc) = uVar2 & 0x3ffff | *(uint *)(iVar3 + 0xc) & 0xfffc0000;
    }
    uVar2 = uVar2 + 1;
  }
  return;
}

/* _PPStreamSortParamConstants @ 0x97bf2360 (168 bytes) */
int _PPStreamSortParamConstants(param_1)
  int param_1;
{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = **(int **)(param_1 + 0x10);
  iVar2 = _PPStreamChunkListGetMaxIndex(*(int **)(param_1 + 0x10));
  if (iVar4 != 0) {
    uVar1 = *(ushort *)(iVar4 + 0x12);
    uVar3 = iVar2 + 1U;
    while ((uint)uVar1 < iVar2 + 1U) {
      if ((*(uint *)(iVar4 + 0xc) >> 0x10 & 0x1f) == 0x11) {
        ((int (*)())_PPStreamRenumberOperandIndices)(param_1,iVar4,uVar3);
        ((int (*)())_renumberParamArrayIndices)(**(undefined4 **)(param_1 + 0x14),(uint)*(ushort *)(iVar4 + 0x12),uVar3);
        *(short *)(iVar4 + 0x12) = (short)uVar3;
        uVar3 = uVar3 + 1;
      }
      iVar4 = *(int *)(iVar4 + 8);
      if (iVar4 == 0) break;
      uVar1 = *(ushort *)(iVar4 + 0x12);
    }
  }
  _PPStreamChunkListSort(*(undefined4 *)(param_1 + 0x10));
  return;
}

/* _PPStreamResolveBranches @ 0x97bf2408 (340 bytes) */
int _PPStreamResolveBranches(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  piVar4 = *(int **)(param_1 + 0x20);
  uVar2 = 0;
  piVar3 = *(int **)(param_1 + 0x24);
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
int _PPStreamGetArray(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint param_3;
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_2 == 1) {
    for (iVar1 = **(int **)(param_1 + 8); iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
      if ((*(ushort *)(iVar1 + 0xe) <= param_3) && (param_3 <= *(ushort *)(iVar1 + 0x12))) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    }
  }
  else if (param_2 == 2) {
    for (iVar1 = **(int **)(param_1 + 0x14); iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
      if ((*(ushort *)(iVar1 + 0xe) <= param_3) && (param_3 <= *(ushort *)(iVar1 + 0x12))) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    }
  }
  return -1;
}

/* _PPStreamFindDuplicateChunk @ 0x97bf25f4 (240 bytes) */
int _PPStreamFindDuplicateChunk(param_1, param_2)
  int param_1;
  undefined1 *param_2;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = (int *)0x0;
  switch(*param_2) {
  case 0:
    piVar1 = *(int **)(param_1 + 4);
    break;
  case 1:
    piVar1 = *(int **)(param_1 + 0xc);
    break;
  case 2:
    piVar1 = *(int **)(param_1 + 0x18);
    break;
  case 3:
    piVar1 = *(int **)(param_1 + 0x10);
    break;
  case 4:
    piVar1 = *(int **)(param_1 + 0x1c);
    break;
  case 5:
    piVar1 = *(int **)(param_1 + 0x14);
    break;
  case 6:
    piVar1 = *(int **)(param_1 + 8);
    break;
  case 7:
    piVar1 = *(int **)(param_1 + 0x30);
    break;
  case 8:
    piVar1 = *(int **)(param_1 + 0x20);
    break;
  case 9:
    piVar1 = *(int **)(param_1 + 0x28);
    break;
  case 10:
    piVar1 = *(int **)(param_1 + 0x2c);
    break;
  case 0xb:
    piVar1 = *(int **)(param_1 + 0x24);
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

