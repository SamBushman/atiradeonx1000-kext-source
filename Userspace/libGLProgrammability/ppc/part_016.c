#include "decls.h"

/* _PPCConstantsAndScratchCreate @ 0x97be56c4 (56 bytes) */
int _PPCConstantsAndScratchCreate()
{
  void *pvVar1;
  
  pvVar1 = _malloc(0xd80);
  ((int (*)())_PPCConstantsAndScratchInitialise)();
  return pvVar1;
}

/* _PPCConstantsAndScratchInitialise @ 0x97be5700 (1196 bytes) */
int _PPCConstantsAndScratchInitialise(param_1)
  undefined4 *param_1;
{
  double dVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  double dVar5;
  double dVar6;
  
  _memset(param_1,0,0xd80);
  fVar2 = FLOAT_97c3acc8;
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
  param_1[0x1c] = fVar2;
  param_1[0x1d] = fVar2;
  param_1[0x1e] = fVar2;
  param_1[0x1f] = fVar2;
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
  fVar4 = FLOAT_97c3ad08;
  param_1[0x23] = 0x41400000;
  fVar3 = FLOAT_97c3ad00;
  param_1[0x22] = 0x40400000;
  param_1[0x25] = fVar3;
  fVar3 = FLOAT_97c3ad04;
  param_1[0x24] = 0x3f000000;
  param_1[0x27] = fVar3;
  fVar3 = FLOAT_97c3ad0c;
  param_1[0x26] = 0x3e800000;
  param_1[0x2a] = fVar3;
  fVar3 = FLOAT_97c3ad10;
  param_1[0x28] = 0x3d800000;
  param_1[0x2c] = fVar3;
  fVar3 = FLOAT_97c3ad14;
  param_1[0x21] = 0x3f800000;
  param_1[0x2d] = fVar3;
  fVar3 = FLOAT_97c3acf0;
  param_1[0x2b] = fVar2;
  param_1[0x30] = fVar3;
  fVar2 = FLOAT_97c3acf8;
  param_1[0x2e] = 0x30000000;
  param_1[0x31] = fVar2;
  fVar2 = FLOAT_97c3ad18;
  param_1[0x2f] = 0x2f800000;
  param_1[0x32] = fVar2;
  fVar2 = FLOAT_97c3ad1c;
  param_1[0x29] = fVar4;
  param_1[0x33] = fVar2;
  param_1[0x34] = FLOAT_97c3ad20;
  param_1[0x38] = FLOAT_97c3ad24;
  param_1[0x39] = FLOAT_97c3ad28;
  fVar2 = FLOAT_97c3ad2c;
  param_1[0x40] = 0x3f800000;
  param_1[0x3b] = fVar2;
  fVar2 = FLOAT_97c3ad30;
  param_1[0x3a] = 0x47800000;
  param_1[0x3c] = fVar2;
  param_1[0x3d] = FLOAT_97c3ad34;
  param_1[0x3e] = FLOAT_97c3ad38;
  param_1[0x3f] = FLOAT_97c3ad3c;
  param_1[0x41] = FLOAT_97c3ad40;
  param_1[0x42] = FLOAT_97c3ad44;
  param_1[0x43] = FLOAT_97c3ad48;
  param_1[0x44] = FLOAT_97c3ad4c;
  param_1[0x45] = FLOAT_97c3ad50;
  param_1[0x46] = FLOAT_97c3ad54;
  param_1[0x47] = FLOAT_97c3ad58;
  param_1[0x48] = FLOAT_97c3ad5c;
  param_1[0x49] = FLOAT_97c3ad60;
  param_1[0x4a] = FLOAT_97c3ad64;
  param_1[0x4b] = FLOAT_97c3ad68;
  fVar2 = FLOAT_97c3ad6c;
  param_1[0x54] = 0xbf000000;
  param_1[0x4c] = fVar2;
  fVar2 = FLOAT_97c3ad70;
  param_1[0x55] = fVar4;
  param_1[0x4d] = fVar2;
  fVar2 = FLOAT_97c3ad74;
  param_1[0x5c] = 0xff800000;
  param_1[0x4e] = fVar2;
  fVar2 = FLOAT_97c3ad78;
  param_1[0x5d] = 0xff800000;
  param_1[0x4f] = fVar2;
  fVar2 = FLOAT_97c3ad7c;
  param_1[0x5e] = 0xff800000;
  param_1[0x50] = fVar2;
  param_1[0x51] = FLOAT_97c3ad80;
  param_1[0x52] = FLOAT_97c3ad84;
  param_1[0x53] = FLOAT_97c3ad88;
  param_1[0x56] = FLOAT_97c3ad8c;
  param_1[0x57] = FLOAT_97c3ad90;
  param_1[0x58] = FLOAT_97c3ad94;
  param_1[0x59] = FLOAT_97c3ad98;
  param_1[0x5a] = FLOAT_97c3ad9c;
  param_1[0x5b] = FLOAT_97c3ada0;
  param_1[0x5f] = 0xff800000;
  fVar4 = FLOAT_97c3ada4;
  fVar3 = FLOAT_97c3acd4;
  fVar2 = FLOAT_97c3acd0;
  dVar6 = DOUBLE_97c30aa0;
  param_1[0x67] = FLOAT_97c3acd0;
  param_1[0x6b] = fVar3;
  param_1[100] = fVar2;
  param_1[0x65] = fVar2;
  param_1[0x66] = fVar2;
  param_1[0x68] = fVar3;
  param_1[0x69] = fVar3;
  param_1[0x6a] = fVar3;
  param_1[99] = fVar4;
  param_1[0x60] = fVar4;
  param_1[0x61] = fVar4;
  param_1[0x62] = fVar4;
  dVar5 = (double)_log2(dVar6);
  dVar1 = DOUBLE_97c30a60;
  param_1[0x6c] = (float)dVar5;
  dVar5 = (double)_log2(dVar6);
  param_1[0x6d] = (float)dVar5;
  dVar5 = (double)_log2(dVar6);
  param_1[0x6e] = (float)dVar5;
  dVar5 = (double)_log2(dVar6);
  param_1[0x6f] = (float)dVar5;
  dVar5 = (double)_log2(dVar6);
  param_1[0x70] = (float)(dVar1 / dVar5);
  dVar5 = (double)_log2(dVar6);
  param_1[0x71] = (float)(dVar1 / dVar5);
  dVar5 = (double)_log2(dVar6);
  param_1[0x72] = (float)(dVar1 / dVar5);
  dVar6 = (double)_log2(dVar6);
  *(undefined8 *)(param_1 + 0x78) = 0x4330000080000000;
  *(undefined8 *)(param_1 + 0x7a) = 0x4330000000000000;
  param_1[0x7e] = 0x43300000;
  param_1[0x7f] = 0;
  param_1[0x7c] = 0x43300000;
  param_1[0x7d] = 0;
  param_1[0x73] = (float)(dVar1 / dVar6);
  _PPCNoiseGeneratorInitialise(param_1 + 0xd8);
  return;
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
int _PPEmulatorEmulateSingleOp(param_1)
  int param_1;
{
  _InterpreterEmulateOp(*(undefined4 *)(param_1 + 0xdf0));
  return;
}

/* _PPEmulatorRun @ 0x97be5bec (116 bytes) */
int _PPEmulatorRun(param_1, param_2)
  int param_1;
  undefined4 param_2;
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
                    
                    
  (*UNRECOVERED_JUMPTABLE)(param_1,param_2);
  return;
}

/* _PPEmulatorBuild @ 0x97be5c60 (576 bytes) */
int _PPEmulatorBuild(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  bool bVar5;
  code *UNRECOVERED_JUMPTABLE;
  uint uVar6;
  int iVar7;
  
  iVar7 = *(int *)(param_1 + 0xd80);
  bVar5 = false;
  uVar6 = *(uint *)(iVar7 + 0x124);
  if (((*(int *)(iVar7 + 0x38) == 0x8804) || (*(int *)(iVar7 + 0x38) == 0x8b30)) &&
     ((double)*(float *)(*(int *)(param_1 + 0xda0) + 0xc) != DOUBLE_97c30a60)) {
    bVar5 = true;
  }
  bVar5 = !bVar5;
  if (bVar5) {
    if (*(int *)(iVar7 + 0x1c) != 0) {
      _glpDCBFree();
    }
    iVar2 = *(int *)(iVar7 + 0x14);
  }
  else {
    if (*(int *)(iVar7 + 0x20) != 0) {
      _glpDCBFree();
    }
    iVar2 = *(int *)(iVar7 + 0x18);
  }
  if (iVar2 != 0) {
    _glpDCBFree();
  }
  if ((uVar6 & 2) != 0) {
    if ((uVar6 & 8) == 0) {
      uVar3 = _PPCRuntimeCompilerCreate();
      _PPCRuntimeCompilerAttachEmulatorContext(uVar3,param_1);
      _PPCRuntimeCompilerAttachEmulatorProgram(uVar3,iVar7);
      if ((uVar6 & 4) != 0) {
        _PPCRuntimeCompilerSetOptionFlags(uVar3,7);
      }
      if (bVar5) {
        _PPCRuntimeCompilerCompileNO(uVar3);
        uVar4 = _PPCRuntimeCompilerGetCompiledResult(uVar3);
        *(undefined4 *)(iVar7 + 0x1c) = uVar4;
      }
      else {
        _PPCRuntimeCompilerSetOptionFlags(uVar3,8);
        _PPCRuntimeCompilerCompileNO(uVar3);
        uVar4 = _PPCRuntimeCompilerGetCompiledResult(uVar3);
        *(undefined4 *)(iVar7 + 0x20) = uVar4;
      }
      _PPCRuntimeCompilerFree(uVar3);
    }
    if ((uVar6 & 8) != 0) {
      uVar3 = _PPCRuntimeCompilerCreate();
      _PPCRuntimeCompilerAttachEmulatorContext(uVar3,param_1);
      _PPCRuntimeCompilerAttachEmulatorProgram(uVar3,iVar7);
      if ((uVar6 & 4) != 0) {
        _PPCRuntimeCompilerSetOptionFlags(uVar3,7);
      }
      if (bVar5) {
        _PPCRuntimeCompilerCompileAV(uVar3);
        uVar4 = _PPCRuntimeCompilerGetCompiledResult(uVar3);
        *(undefined4 *)(iVar7 + 0x14) = uVar4;
      }
      else {
        _PPCRuntimeCompilerSetOptionFlags(uVar3,8);
        _PPCRuntimeCompilerCompileAV(uVar3);
        uVar4 = _PPCRuntimeCompilerGetCompiledResult(uVar3);
        *(undefined4 *)(iVar7 + 0x18) = uVar4;
      }
      _PPCRuntimeCompilerFree(uVar3);
    }
  }
  puVar1 = PTR__InterpreterRun_a7b7c104;
  *(undefined **)(iVar7 + 0x10) = PTR__InterpreterRun_a7b7c104;
  if ((uVar6 & 2) == 0) {
    if (bVar5) goto LAB_97be5e64;
  }
  else if ((uVar6 & 8) == 0) {
    if (bVar5) {
      puVar1 = *(undefined **)(iVar7 + 0x1c);
      goto LAB_97be5e64;
    }
    puVar1 = *(undefined **)(iVar7 + 0x20);
  }
  else {
    if (bVar5) {
      puVar1 = *(undefined **)(iVar7 + 0x14);
LAB_97be5e64:
      *(undefined **)(iVar7 + 8) = puVar1;
      goto LAB_97be5e68;
    }
    puVar1 = *(undefined **)(iVar7 + 0x18);
  }
  *(undefined **)(iVar7 + 0xc) = puVar1;
LAB_97be5e68:
  if (bVar5) {
    UNRECOVERED_JUMPTABLE = *(code **)(iVar7 + 8);
  }
  else {
    UNRECOVERED_JUMPTABLE = *(code **)(iVar7 + 0xc);
  }
                    
                    
  (*UNRECOVERED_JUMPTABLE)(param_1,param_2);
  return;
}

/* _PPEmulatorRunNoop @ 0x97be5ea0 (8 bytes) */
int _PPEmulatorRunNoop()
{
  return 0;
}

/* _PPEmulatorVariableSwizzleFromMask @ 0x97be5ea8 (108 bytes) */
int _PPEmulatorVariableSwizzleFromMask(param_1)
  int param_1;
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

/* _ncpy @ 0x97be5f58 (144 bytes) */
int _ncpy(param_1, param_2)
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
    ((int (*)())_handleDigit)(local_20,iVar1);
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
  iVar3 = ((int (*)())_ncpy)(param_1 + iVar2,param_2 + 1);
  iVar3 = param_1 + iVar2 + iVar3;
  if (param_3 == 1) {
    iVar2 = 0;
    cVar1 = s___97c2a320[0];
    while (cVar1 != '\0') {
      *(char *)(iVar3 + iVar2) = cVar1;
      cVar1 = ":"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    iVar4 = ((int (*)())_ncpy)(iVar3 + iVar2,param_2 + 1);
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
    iVar3 = ((int (*)())_ncpy)(param_1 + iVar2,param_2 + 1);
    param_1 = param_1 + iVar2 + iVar3;
    if (param_3 == 1) {
      iVar2 = 0;
      cVar1 = s___97c2a320[0];
      while (cVar1 != '\0') {
        *(char *)(param_1 + iVar2) = cVar1;
        cVar1 = ":"[iVar2 + 1];
        iVar2 = iVar2 + 1;
      }
      iVar3 = ((int (*)())_ncpy)(param_1 + iVar2,param_2 + 1);
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
  iVar3 = ((int (*)())_ncpy)(param_1 + iVar2,param_2 + 1);
  iVar3 = param_1 + iVar2 + iVar3;
  if (param_3 != 0) {
    iVar2 = 0;
    cVar1 = s___97c2a320[0];
    while (cVar1 != '\0') {
      *(char *)(iVar3 + iVar2) = cVar1;
      cVar1 = ":"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    iVar4 = ((int (*)())_ncpy)(iVar3 + iVar2,param_2 + 1);
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

/* _glpWriteDestinationOperand @ 0x97be6730 (2328 bytes) */
int _glpWriteDestinationOperand(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  char *param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
{
  char cVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  
  param_5 = param_5 * 8;
  uVar3 = *(uint *)(param_5 + param_1) >> 0x11 & 7;
  if (uVar3 == 1) {
    iVar4 = 0;
    cVar1 = s_tmp_97c2d76c[0];
    while (cVar1 != '\0') {
      param_2[iVar4] = cVar1;
      cVar1 = "tmp"[iVar4 + 1];
      iVar4 = iVar4 + 1;
    }
    param_2 = param_2 + iVar4;
    if ((param_6 == 0) || (param_3 == 0)) {
      uVar2 = *(undefined2 *)(param_5 + param_1 + 6);
      goto LAB_97be68f4;
    }
    iVar4 = ((int (*)())_ncpy)(param_2,*(undefined4 *)(param_3 + (uint)*(ushort *)(param_5 + param_1 + 6) * 4));
    param_2 = param_2 + iVar4;
    if (((param_4 != 0) && (uVar3 = *(uint *)(param_5 + param_1 + 4), -1 < (int)uVar3)) &&
       (*(int *)(param_4 + (uVar3 & 0xffff) * 4) != -1)) {
      iVar4 = 0;
      cVar1 = s___97c29860[0];
      while (cVar1 != '\0') {
        param_2[iVar4] = cVar1;
        cVar1 = "["[iVar4 + 1];
        iVar4 = iVar4 + 1;
      }
      param_2 = param_2 + iVar4;
      iVar6 = ((int (*)())_ncpy)(param_2,*(undefined4 *)(param_4 + (uint)*(ushort *)(param_5 + param_1 + 6) * 4))
      ;
      iVar4 = 0;
      cVar1 = s___97c2d770[0];
      while (cVar1 != '\0') {
        param_2[iVar4 + iVar6] = cVar1;
        cVar1 = "]"[iVar4 + 1];
        iVar4 = iVar4 + 1;
      }
      param_2 = param_2 + iVar4 + iVar6;
    }
  }
  else if (uVar3 == 3) {
    iVar4 = 0;
    cVar1 = s_res_97c2d774[0];
    while (cVar1 != '\0') {
      param_2[iVar4] = cVar1;
      cVar1 = "res"[iVar4 + 1];
      iVar4 = iVar4 + 1;
    }
    param_2 = param_2 + iVar4;
    uVar2 = *(undefined2 *)(param_5 + param_1 + 6);
LAB_97be68f4:
    iVar4 = ((int (*)())_ncpy)(param_2,uVar2);
    param_2 = param_2 + iVar4;
  }
  if (param_6 == 0) {
    if ((*(uint *)(param_5 + param_1) & 0x1e000) != 0x1e000) {
      iVar4 = 0;
      cVar1 = s___97c2a130[0];
      while (cVar1 != '\0') {
        param_2[iVar4] = cVar1;
        cVar1 = "."[iVar4 + 1];
        iVar4 = iVar4 + 1;
      }
      param_2 = param_2 + iVar4;
      if ((*(uint *)(param_5 + param_1) & 0x2000) != 0) {
        iVar4 = 0;
        cVar1 = s_x_97c2d790[0];
        while (cVar1 != '\0') {
          param_2[iVar4] = cVar1;
          cVar1 = "x"[iVar4 + 1];
          iVar4 = iVar4 + 1;
        }
        param_2 = param_2 + iVar4;
      }
      if ((*(uint *)(param_5 + param_1) & 0x4000) != 0) {
        iVar4 = 0;
        cVar1 = s_y_97c2d794[0];
        while (cVar1 != '\0') {
          param_2[iVar4] = cVar1;
          cVar1 = "y"[iVar4 + 1];
          iVar4 = iVar4 + 1;
        }
        param_2 = param_2 + iVar4;
      }
      if ((*(uint *)(param_5 + param_1) & 0x8000) != 0) {
        iVar4 = 0;
        cVar1 = s_z_97c2d798[0];
        while (cVar1 != '\0') {
          param_2[iVar4] = cVar1;
          cVar1 = "z"[iVar4 + 1];
          iVar4 = iVar4 + 1;
        }
        param_2 = param_2 + iVar4;
      }
      if ((*(uint *)(param_5 + param_1) & 0x10000) != 0) {
        iVar4 = 0;
        cVar1 = s_w_97c2d79c[0];
        while (cVar1 != '\0') {
          param_2[iVar4] = cVar1;
          cVar1 = "w"[iVar4 + 1];
          iVar4 = iVar4 + 1;
        }
        param_2 = param_2 + iVar4;
      }
    }
  }
  else {
    if (*(int *)(param_5 + param_1 + 4) < 0) {
      iVar6 = 0;
      iVar4 = 0;
      cVar1 = s__adr_97c2d778[0];
      while (cVar1 != '\0') {
        param_2[iVar4] = cVar1;
        cVar1 = "[adr"[iVar4 + 1];
        iVar4 = iVar4 + 1;
      }
      iVar5 = ((int (*)())_ncpy)(param_2 + iVar4,*(uint *)(param_5 + param_1 + 4) >> 0x1e & 1);
      param_2 = param_2 + iVar4 + iVar5;
      uVar3 = *(uint *)(param_5 + param_1 + 4) >> 0x1c & 3;
      if (uVar3 == 1) {
        iVar4 = 0;
        cVar1 = s__y_97c2d784[0];
        while (cVar1 != '\0') {
          param_2[iVar4] = cVar1;
          cVar1 = ".y"[iVar4 + 1];
          iVar4 = iVar4 + 1;
        }
LAB_97be6a74:
        param_2 = param_2 + iVar4;
      }
      else {
        if (1 < uVar3) {
          if (uVar3 == 2) {
            iVar4 = 0;
            cVar1 = s__z_97c2d788[0];
            while (cVar1 != '\0') {
              param_2[iVar4] = cVar1;
              cVar1 = ".z"[iVar4 + 1];
              iVar4 = iVar4 + 1;
            }
          }
          else {
            if (uVar3 != 3) goto LAB_97be6a78;
            iVar4 = 0;
            cVar1 = s__w_97c2d78c[0];
            while (cVar1 != '\0') {
              param_2[iVar4] = cVar1;
              cVar1 = ".w"[iVar4 + 1];
              iVar4 = iVar4 + 1;
            }
          }
          goto LAB_97be6a74;
        }
        if (uVar3 == 0) {
          iVar4 = 0;
          cVar1 = s__x_97c2d780[0];
          while (cVar1 != '\0') {
            param_2[iVar4] = cVar1;
            cVar1 = ".x"[iVar4 + 1];
            iVar4 = iVar4 + 1;
          }
          goto LAB_97be6a74;
        }
      }
LAB_97be6a78:
      if ((((*(uint *)(param_5 + param_1) >> 0x11 & 7) == 1) && (param_4 != 0)) &&
         (iVar4 = *(int *)(param_4 + (uint)*(ushort *)(param_5 + param_1 + 6) * 4), iVar4 != -1)) {
        iVar6 = iVar4;
      }
      uVar3 = *(uint *)(param_5 + param_1 + 4);
      iVar6 = iVar6 + ((int)(uVar3 << 4 | uVar3 >> 0x1c) >> 0x18);
      if (iVar6 != 0) {
        if (0 < iVar6) {
          iVar4 = 0;
          cVar1 = s___97c2a308[0];
          while (cVar1 != '\0') {
            param_2[iVar4] = cVar1;
            cVar1 = "+"[iVar4 + 1];
            iVar4 = iVar4 + 1;
          }
          param_2 = param_2 + iVar4;
        }
        iVar4 = ((int (*)())_ncpy)(param_2,iVar6);
        param_2 = param_2 + iVar4;
      }
      iVar4 = 0;
      cVar1 = s___97c2d770[0];
      while (cVar1 != '\0') {
        param_2[iVar4] = cVar1;
        cVar1 = "]"[iVar4 + 1];
        iVar4 = iVar4 + 1;
      }
      param_2 = param_2 + iVar4;
    }
    iVar4 = 0;
    cVar1 = s___97c2a130[0];
    while (cVar1 != '\0') {
      param_2[iVar4] = cVar1;
      cVar1 = "."[iVar4 + 1];
      iVar4 = iVar4 + 1;
    }
    pcVar7 = param_2 + iVar4;
    if ((*(uint *)(param_5 + param_1) & 0x2000) == 0) {
      *pcVar7 = '_';
    }
    else {
      *pcVar7 = (((byte)(*(uint *)(param_5 + param_1) >> 8) & 3) + 1 & 3) + 0x77;
    }
    uVar3 = *(uint *)(param_5 + param_1);
    param_2 = pcVar7 + 1;
    if ((uVar3 & 0xc00) != 0) {
      if ((uVar3 & 0x4000) == 0) {
        *param_2 = '_';
      }
      else {
        *param_2 = (((byte)(uVar3 >> 6) & 3) + 1 & 3) + 0x77;
      }
      param_2 = pcVar7 + 2;
    }
    uVar3 = *(uint *)(param_5 + param_1);
    if (1 < (uVar3 >> 10 & 3)) {
      if ((uVar3 & 0x8000) == 0) {
        *param_2 = '_';
      }
      else {
        *param_2 = (((byte)(uVar3 >> 4) & 3) + 1 & 3) + 0x77;
      }
      param_2 = param_2 + 1;
    }
    uVar3 = *(uint *)(param_5 + param_1);
    if (2 < (uVar3 >> 10 & 3)) {
      if ((uVar3 & 0x10000) == 0) {
        *param_2 = '_';
      }
      else {
        *param_2 = (((byte)(uVar3 >> 2) & 3) + 1 & 3) + 0x77;
      }
      param_2 = param_2 + 1;
    }
  }
  if (param_6 != 0) {
    param_2 = (char *)((int (*)())_glpWriteOperandSize)(param_2,*(uint *)(param_5 + param_1) >> 10 & 3,
                                 *(uint *)(param_5 + param_1) >> 0xc & 1);
  }
  uVar3 = *(uint *)(param_5 + param_1) >> 0x1c & 7;
  if (uVar3 == 0) {
    return param_2;
  }
  switch(uVar3) {
  case 1:
    iVar4 = 0;
    cVar1 = s__EQ_97c2d7a8[0];
    while (cVar1 != '\0') {
      param_2[iVar4] = cVar1;
      cVar1 = " (EQ"[iVar4 + 1];
      iVar4 = iVar4 + 1;
    }
    break;
  case 2:
    iVar4 = 0;
    cVar1 = s__GE_97c2d7b0[0];
    while (cVar1 != '\0') {
      param_2[iVar4] = cVar1;
      cVar1 = " (GE"[iVar4 + 1];
      iVar4 = iVar4 + 1;
    }
    break;
  case 3:
    iVar4 = 0;
    cVar1 = s__GT_97c2d7b8[0];
    while (cVar1 != '\0') {
      param_2[iVar4] = cVar1;
      cVar1 = " (GT"[iVar4 + 1];
      iVar4 = iVar4 + 1;
    }
    break;
  case 4:
    iVar4 = 0;
    cVar1 = s__LE_97c2d7c0[0];
    while (cVar1 != '\0') {
      param_2[iVar4] = cVar1;
      cVar1 = " (LE"[iVar4 + 1];
      iVar4 = iVar4 + 1;
    }
    break;
  case 5:
    iVar4 = 0;
    cVar1 = s__LT_97c2d7c8[0];
    while (cVar1 != '\0') {
      param_2[iVar4] = cVar1;
      cVar1 = " (LT"[iVar4 + 1];
      iVar4 = iVar4 + 1;
    }
    break;
  case 6:
    iVar4 = 0;
    cVar1 = s__NE_97c2d7d0[0];
    while (cVar1 != '\0') {
      param_2[iVar4] = cVar1;
      cVar1 = " (NE"[iVar4 + 1];
      iVar4 = iVar4 + 1;
    }
    break;
  case 7:
    iVar4 = 0;
    cVar1 = s__FL_97c2d7d8[0];
    while (cVar1 != '\0') {
      param_2[iVar4] = cVar1;
      cVar1 = " (FL"[iVar4 + 1];
      iVar4 = iVar4 + 1;
    }
    break;
  default:
    goto switchD_97be6e10_default;
  }
  param_2 = param_2 + iVar4;
switchD_97be6e10_default:
  if (*(int *)(param_5 + param_1) < 0) {
    *param_2 = '1';
    param_2 = param_2 + 1;
  }
  *param_2 = '.';
  param_2[1] = (((byte)((uint)*(undefined4 *)(param_5 + param_1) >> 0x1a) & 3) + 1 & 3) + 0x77;
  param_2[2] = ((*(byte *)(param_5 + param_1) & 3) + 1 & 3) + 0x77;
  param_2[3] = (((byte)(*(uint *)(param_5 + param_1) >> 0x16) & 3) + 1 & 3) + 0x77;
  param_2[4] = (((byte)(*(uint *)(param_5 + param_1) >> 0x14) & 3) + 1 & 3) + 0x77;
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
  
  param_3 = param_3 * 8;
  if ((*(uint *)(param_3 + param_1) >> 0x11 & 7) == 4) {
    iVar2 = 0;
    cVar1 = s_adr_97c2d7e0[0];
    while (cVar1 != '\0') {
      *(char *)(param_2 + iVar2) = cVar1;
      cVar1 = "adr"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    iVar3 = ((int (*)())_ncpy)(param_2 + iVar2,*(undefined2 *)(param_3 + param_1 + 6));
    param_2 = param_2 + iVar2 + iVar3;
  }
  if ((*(uint *)(param_3 + param_1) & 0x1e000) != 0x1e000) {
    iVar2 = 0;
    cVar1 = s___97c2a130[0];
    while (cVar1 != '\0') {
      *(char *)(param_2 + iVar2) = cVar1;
      cVar1 = "."[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    param_2 = param_2 + iVar2;
    if (param_4 == 0) {
      if ((*(uint *)(param_3 + param_1) & 0x2000) != 0) {
        iVar2 = 0;
        cVar1 = s_x_97c2d790[0];
        while (cVar1 != '\0') {
          *(char *)(param_2 + iVar2) = cVar1;
          cVar1 = "x"[iVar2 + 1];
          iVar2 = iVar2 + 1;
        }
        param_2 = param_2 + iVar2;
      }
      if ((*(uint *)(param_3 + param_1) & 0x4000) != 0) {
        iVar2 = 0;
        cVar1 = s_y_97c2d794[0];
        while (cVar1 != '\0') {
          *(char *)(param_2 + iVar2) = cVar1;
          cVar1 = "y"[iVar2 + 1];
          iVar2 = iVar2 + 1;
        }
        param_2 = param_2 + iVar2;
      }
      if ((*(uint *)(param_3 + param_1) & 0x8000) != 0) {
        iVar2 = 0;
        cVar1 = s_z_97c2d798[0];
        while (cVar1 != '\0') {
          *(char *)(param_2 + iVar2) = cVar1;
          cVar1 = "z"[iVar2 + 1];
          iVar2 = iVar2 + 1;
        }
        param_2 = param_2 + iVar2;
      }
      if ((*(uint *)(param_3 + param_1) & 0x10000) == 0) {
        return param_2;
      }
      iVar2 = 0;
      cVar1 = s_w_97c2d79c[0];
      while (cVar1 != '\0') {
        *(char *)(param_2 + iVar2) = cVar1;
        cVar1 = "w"[iVar2 + 1];
        iVar2 = iVar2 + 1;
      }
    }
    else {
      if ((*(uint *)(param_3 + param_1) & 0x2000) != 0) {
        iVar2 = 0;
        cVar1 = s_x_97c2d790[0];
        while (cVar1 != '\0') {
          *(char *)(param_2 + iVar2) = cVar1;
          cVar1 = "x"[iVar2 + 1];
          iVar2 = iVar2 + 1;
        }
        param_2 = param_2 + iVar2;
      }
      if (((*(uint *)(param_3 + param_1) & 0xc00) != 0) &&
         ((*(uint *)(param_3 + param_1) & 0x4000) != 0)) {
        iVar2 = 0;
        cVar1 = s_y_97c2d794[0];
        while (cVar1 != '\0') {
          *(char *)(param_2 + iVar2) = cVar1;
          cVar1 = "y"[iVar2 + 1];
          iVar2 = iVar2 + 1;
        }
        param_2 = param_2 + iVar2;
      }
      if ((1 < (*(uint *)(param_3 + param_1) >> 10 & 3)) &&
         ((*(uint *)(param_3 + param_1) & 0x8000) != 0)) {
        iVar2 = 0;
        cVar1 = s_z_97c2d798[0];
        while (cVar1 != '\0') {
          *(char *)(param_2 + iVar2) = cVar1;
          cVar1 = "z"[iVar2 + 1];
          iVar2 = iVar2 + 1;
        }
        param_2 = param_2 + iVar2;
      }
      if ((*(uint *)(param_3 + param_1) >> 10 & 3) < 3) {
        return param_2;
      }
      if ((*(uint *)(param_3 + param_1) & 0x10000) == 0) {
        return param_2;
      }
      iVar2 = 0;
      cVar1 = s_w_97c2d79c[0];
      while (cVar1 != '\0') {
        *(char *)(param_2 + iVar2) = cVar1;
        cVar1 = "w"[iVar2 + 1];
        iVar2 = iVar2 + 1;
      }
    }
    param_2 = param_2 + iVar2;
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
  
  param_7 = param_7 * 8;
  switch(*(uint *)(param_7 + param_1) >> 0x17 & 7) {
  case 0:
    iVar4 = 0;
    cVar1 = s_att_97c2d7e4[0];
    while (cVar1 != '\0') {
      *(char *)(param_2 + iVar4) = cVar1;
      cVar1 = "att"[iVar4 + 1];
      iVar4 = iVar4 + 1;
    }
    goto LAB_97be770c;
  case 1:
    iVar4 = 0;
    cVar1 = s_tmp_97c2d76c[0];
    while (cVar1 != '\0') {
      *(char *)(param_2 + iVar4) = cVar1;
      cVar1 = "tmp"[iVar4 + 1];
      iVar4 = iVar4 + 1;
    }
    if (param_5 == 0) {
      uVar2 = (uint)*(ushort *)(param_7 + param_1 + 6);
    }
    else {
      uVar2 = *(uint *)(param_5 + (uint)*(ushort *)(param_7 + param_1 + 6) * 4);
    }
    iVar5 = ((int (*)())_ncpy)(param_2 + iVar4,uVar2);
    param_2 = param_2 + iVar4 + iVar5;
    if (((param_6 != 0) && (-1 < *(int *)(param_7 + param_1))) &&
       (*(int *)(param_6 + (uint)*(ushort *)(param_7 + param_1 + 6) * 4) != -1)) {
      iVar4 = 0;
      cVar1 = s___97c29860[0];
      while (cVar1 != '\0') {
        *(char *)(param_2 + iVar4) = cVar1;
        cVar1 = "["[iVar4 + 1];
        iVar4 = iVar4 + 1;
      }
      iVar5 = ((int (*)())_ncpy)(param_2 + iVar4,
                    *(undefined4 *)(param_6 + (uint)*(ushort *)(param_7 + param_1 + 6) * 4));
      iVar5 = param_2 + iVar4 + iVar5;
      param_2 = 0;
      cVar1 = s___97c2d770[0];
      while (cVar1 != '\0') {
        *(char *)(iVar5 + param_2) = cVar1;
        cVar1 = "]"[param_2 + 1];
        param_2 = param_2 + 1;
      }
LAB_97be7698:
      param_2 = iVar5 + param_2;
    }
    break;
  case 2:
    iVar4 = 0;
    cVar1 = s_prm_97c2d7e8[0];
    while (cVar1 != '\0') {
      *(char *)(param_2 + iVar4) = cVar1;
      cVar1 = "prm"[iVar4 + 1];
      iVar4 = iVar4 + 1;
    }
    iVar5 = ((int (*)())_ncpy)(param_2 + iVar4,
                  *(undefined4 *)(param_3 + (uint)*(ushort *)(param_7 + param_1 + 6) * 4));
    param_2 = param_2 + iVar4 + iVar5;
    if ((-1 < *(int *)(param_7 + param_1)) &&
       (*(int *)(param_4 + (uint)*(ushort *)(param_7 + param_1 + 6) * 4) != -1)) {
      iVar4 = 0;
      cVar1 = s___97c29860[0];
      while (cVar1 != '\0') {
        *(char *)(param_2 + iVar4) = cVar1;
        cVar1 = "["[iVar4 + 1];
        iVar4 = iVar4 + 1;
      }
      iVar5 = ((int (*)())_ncpy)(param_2 + iVar4,
                    *(undefined4 *)(param_4 + (uint)*(ushort *)(param_7 + param_1 + 6) * 4));
      iVar5 = param_2 + iVar4 + iVar5;
      param_2 = 0;
      cVar1 = s___97c2d770[0];
      while (cVar1 != '\0') {
        *(char *)(iVar5 + param_2) = cVar1;
        cVar1 = "]"[param_2 + 1];
        param_2 = param_2 + 1;
      }
      goto LAB_97be7698;
    }
    break;
  case 3:
    iVar4 = 0;
    cVar1 = s_res_97c2d774[0];
    while (cVar1 != '\0') {
      *(char *)(param_2 + iVar4) = cVar1;
      cVar1 = "res"[iVar4 + 1];
      iVar4 = iVar4 + 1;
    }
    goto LAB_97be770c;
  case 4:
    iVar4 = 0;
    cVar1 = s_adr_97c2d7e0[0];
    while (cVar1 != '\0') {
      *(char *)(param_2 + iVar4) = cVar1;
      cVar1 = "adr"[iVar4 + 1];
      iVar4 = iVar4 + 1;
    }
LAB_97be770c:
    iVar5 = ((int (*)())_ncpy)(param_2 + iVar4,*(undefined2 *)(param_7 + param_1 + 6));
    param_2 = param_2 + iVar4 + iVar5;
  }
  if (-1 < *(int *)(param_7 + param_1)) {
    return param_2;
  }
  iVar5 = 0;
  iVar4 = 0;
  cVar1 = s__adr_97c2d778[0];
  while (cVar1 != '\0') {
    *(char *)(param_2 + iVar4) = cVar1;
    cVar1 = "[adr"[iVar4 + 1];
    iVar4 = iVar4 + 1;
  }
  iVar3 = ((int (*)())_ncpy)(param_2 + iVar4,*(uint *)(param_7 + param_1) >> 0x1e & 1);
  iVar3 = param_2 + iVar4 + iVar3;
  uVar2 = *(uint *)(param_7 + param_1) >> 0x1c & 3;
  if (uVar2 == 1) {
    iVar4 = 0;
    cVar1 = s__y_97c2d784[0];
    while (cVar1 != '\0') {
      *(char *)(iVar3 + iVar4) = cVar1;
      cVar1 = ".y"[iVar4 + 1];
      iVar4 = iVar4 + 1;
    }
  }
  else if (uVar2 < 2) {
    if (uVar2 != 0) goto LAB_97be7894;
    iVar4 = 0;
    cVar1 = s__x_97c2d780[0];
    while (cVar1 != '\0') {
      *(char *)(iVar3 + iVar4) = cVar1;
      cVar1 = ".x"[iVar4 + 1];
      iVar4 = iVar4 + 1;
    }
  }
  else if (uVar2 == 2) {
    iVar4 = 0;
    cVar1 = s__z_97c2d788[0];
    while (cVar1 != '\0') {
      *(char *)(iVar3 + iVar4) = cVar1;
      cVar1 = ".z"[iVar4 + 1];
      iVar4 = iVar4 + 1;
    }
  }
  else {
    if (uVar2 != 3) goto LAB_97be7894;
    iVar4 = 0;
    cVar1 = s__w_97c2d78c[0];
    while (cVar1 != '\0') {
      *(char *)(iVar3 + iVar4) = cVar1;
      cVar1 = ".w"[iVar4 + 1];
      iVar4 = iVar4 + 1;
    }
  }
  iVar3 = iVar3 + iVar4;
LAB_97be7894:
  if ((((((*(uint *)(param_7 + param_1) >> 0x17 & 7) != 1) || (param_6 == 0)) ||
       (iVar4 = *(int *)(param_6 + (uint)*(ushort *)(param_7 + param_1 + 6) * 4), iVar4 == -1)) &&
      ((iVar4 = iVar5, (*(uint *)(param_7 + param_1) >> 0x17 & 7) == 2 && (param_4 != 0)))) &&
     (iVar5 = *(int *)(param_4 + (uint)*(ushort *)(param_7 + param_1 + 6) * 4), iVar5 != -1)) {
    iVar4 = iVar5;
  }
  iVar4 = iVar4 + (char)*(undefined4 *)(param_7 + param_1);
  if (iVar4 != 0) {
    if (0 < iVar4) {
      iVar5 = 0;
      cVar1 = s___97c2a308[0];
      while (cVar1 != '\0') {
        *(char *)(iVar3 + iVar5) = cVar1;
        cVar1 = "+"[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      iVar3 = iVar3 + iVar5;
    }
    iVar4 = ((int (*)())_ncpy)(iVar3,iVar4);
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
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  
  if (param_4 == 0) {
    param_3 = param_3 * 8;
    if ((*(uint *)(param_3 + param_1) & 0x7f8000) == 0xd8000) {
      return param_2;
    }
    iVar2 = 0;
    cVar1 = s___97c2a130[0];
    while (cVar1 != '\0') {
      param_2[iVar2] = cVar1;
      cVar1 = "."[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    uVar3 = *(uint *)(param_3 + param_1);
    pcVar4 = param_2 + iVar2;
    uVar5 = uVar3 >> 0x15 & 3;
    if (((uVar5 == (uVar3 >> 0x13 & 3)) && (uVar5 == (uVar3 >> 0x11 & 3))) &&
       (uVar5 == (uVar3 >> 0xf & 3))) {
      param_2[iVar2] = ((char)uVar5 + 1U & 3) + 0x77;
    }
    else {
      *pcVar4 = (((byte)(*(uint *)(param_3 + param_1) >> 0x15) & 3) + 1 & 3) + 0x77;
      pcVar4[1] = (((byte)(*(uint *)(param_3 + param_1) >> 0x13) & 3) + 1 & 3) + 0x77;
      pcVar4[2] = (((byte)(*(uint *)(param_3 + param_1) >> 0x11) & 3) + 1 & 3) + 0x77;
      pcVar4 = pcVar4 + 3;
      *pcVar4 = (((byte)(*(uint *)(param_3 + param_1) >> 0xf) & 3) + 1 & 3) + 0x77;
    }
  }
  else {
    iVar2 = 0;
    cVar1 = s___97c2a130[0];
    while (cVar1 != '\0') {
      param_2[iVar2] = cVar1;
      cVar1 = "."[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    param_3 = param_3 * 8;
    pcVar4 = param_2 + iVar2 + 1;
    param_2[iVar2] = (((byte)(*(uint *)(param_3 + param_1) >> 0x15) & 3) + 1 & 3) + 0x77;
    uVar3 = *(uint *)(param_3 + param_1);
    if ((uVar3 & 0x3000) != 0) {
      *pcVar4 = (((byte)(uVar3 >> 0x13) & 3) + 1 & 3) + 0x77;
      pcVar4 = param_2 + iVar2 + 2;
      uVar3 = *(uint *)(param_3 + param_1);
    }
    if (1 < (uVar3 >> 0xc & 3)) {
      *pcVar4 = (((byte)(uVar3 >> 0x11) & 3) + 1 & 3) + 0x77;
      pcVar4 = pcVar4 + 1;
      uVar3 = *(uint *)(param_3 + param_1);
    }
    if ((uVar3 >> 0xc & 3) < 3) {
      return pcVar4;
    }
    *pcVar4 = (((byte)(uVar3 >> 0xf) & 3) + 1 & 3) + 0x77;
  }
  return pcVar4 + 1;
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

/* _glpWriteSourceOperand @ 0x97be7fc0 (380 bytes) */
int _glpWriteSourceOperand(param_1, param_2)
  int param_1;
  int param_2;
{
  char cVar1;
  int iVar2;
  int iVar3;
  int in_r9;
  int in_r10;
  int in_stack_00000038;
  
  iVar2 = in_r9 * 8;
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
  iVar3 = ((int (*)())_glpWriteSourceOperandType)(param_1,param_2);
  if ((*(uint *)(iVar2 + param_1) >> 0x17 & 7) != 4) {
    if (in_stack_00000038 == 0) {
      iVar3 = ((int (*)())_glpWriteSourceOperandSwizzle)(param_1,iVar3,in_r9,in_r10);
    }
    else {
      iVar3 = ((int (*)())_glpWriteSourceOperandExtendedSwizzle)(param_1,iVar3,in_r9 + 1,in_r10);
    }
  }
  if (in_r10 != 0) {
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
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  if (param_3 == (uint *)0x0) {
    iVar3 = -1;
  }
  else {
    uVar2 = *param_3;
    while (uVar2 != (*(uint *)(param_4 * 8 + param_1 + -4) & 0x3ffff)) {
      param_3 = param_3 + 1;
      iVar3 = iVar3 + 1;
      uVar2 = *param_3;
    }
  }
  iVar3 = _sprintf(param_2,"label_%i",iVar3);
  param_2 = param_2 + iVar3;
  if (param_5 == 0) {
    return param_2;
  }
  param_4 = param_4 * 8;
  switch(*(uint *)(param_4 + param_1) >> 0x1c & 7) {
  case 0:
    iVar3 = 0;
    cVar1 = s__TR_97c2d7a0[0];
    while (cVar1 != '\0') {
      param_2[iVar3] = cVar1;
      cVar1 = " (TR"[iVar3 + 1];
      iVar3 = iVar3 + 1;
    }
    break;
  case 1:
    iVar3 = 0;
    cVar1 = s__EQ_97c2d7a8[0];
    while (cVar1 != '\0') {
      param_2[iVar3] = cVar1;
      cVar1 = " (EQ"[iVar3 + 1];
      iVar3 = iVar3 + 1;
    }
    break;
  case 2:
    iVar3 = 0;
    cVar1 = s__GE_97c2d7b0[0];
    while (cVar1 != '\0') {
      param_2[iVar3] = cVar1;
      cVar1 = " (GE"[iVar3 + 1];
      iVar3 = iVar3 + 1;
    }
    break;
  case 3:
    iVar3 = 0;
    cVar1 = s__GT_97c2d7b8[0];
    while (cVar1 != '\0') {
      param_2[iVar3] = cVar1;
      cVar1 = " (GT"[iVar3 + 1];
      iVar3 = iVar3 + 1;
    }
    break;
  case 4:
    iVar3 = 0;
    cVar1 = s__LE_97c2d7c0[0];
    while (cVar1 != '\0') {
      param_2[iVar3] = cVar1;
      cVar1 = " (LE"[iVar3 + 1];
      iVar3 = iVar3 + 1;
    }
    break;
  case 5:
    iVar3 = 0;
    cVar1 = s__LT_97c2d7c8[0];
    while (cVar1 != '\0') {
      param_2[iVar3] = cVar1;
      cVar1 = " (LT"[iVar3 + 1];
      iVar3 = iVar3 + 1;
    }
    break;
  case 6:
    iVar3 = 0;
    cVar1 = s__NE_97c2d7d0[0];
    while (cVar1 != '\0') {
      param_2[iVar3] = cVar1;
      cVar1 = " (NE"[iVar3 + 1];
      iVar3 = iVar3 + 1;
    }
    break;
  case 7:
    iVar3 = 0;
    cVar1 = s__FL_97c2d7d8[0];
    while (cVar1 != '\0') {
      param_2[iVar3] = cVar1;
      cVar1 = " (FL"[iVar3 + 1];
      iVar3 = iVar3 + 1;
    }
    break;
  default:
    goto switchD_97be81f4_default;
  }
  param_2 = param_2 + iVar3;
switchD_97be81f4_default:
  if (*(int *)(param_4 + param_1) < 0) {
    *param_2 = '1';
    param_2 = param_2 + 1;
  }
  *param_2 = '.';
  param_2[1] = (((byte)((uint)*(undefined4 *)(param_4 + param_1) >> 0x1a) & 3) + 1 & 3) + 0x77;
  param_2[2] = ((*(byte *)(param_4 + param_1) & 3) + 1 & 3) + 0x77;
  param_2[3] = (((byte)(*(uint *)(param_4 + param_1) >> 0x16) & 3) + 1 & 3) + 0x77;
  param_2[4] = (((byte)(*(uint *)(param_4 + param_1) >> 0x14) & 3) + 1 & 3) + 0x77;
  param_2[5] = ')';
  return param_2 + 6;
}

/* _glpWriteTextureOperand @ 0x97be8478 (736 bytes) */
int _glpWriteTextureOperand(param_1, param_2)
  int param_1;
  int param_2;
{
  char cVar1;
  int iVar2;
  int in_r9;
  int in_r10;
  
  iVar2 = 0;
  cVar1 = s_texture__97c2d814[0];
  while (cVar1 != '\0') {
    *(char *)(param_2 + iVar2) = cVar1;
    cVar1 = "texture["[iVar2 + 1];
    iVar2 = iVar2 + 1;
  }
  param_2 = param_2 + iVar2;
  if (in_r10 == 0) {
    in_r9 = in_r9 * 8;
    iVar2 = ((int (*)())_ncpy)(param_2,*(uint *)(in_r9 + param_1) & 0x1f);
    param_2 = param_2 + iVar2;
  }
  else {
    param_2 = ((int (*)())_glpWriteSourceOperand)(param_1,param_2);
    in_r9 = (in_r9 + 1) * 8;
  }
  iVar2 = 0;
  cVar1 = s____97c2d820[0];
  while (cVar1 != '\0') {
    *(char *)(param_2 + iVar2) = cVar1;
    cVar1 = "], "[iVar2 + 1];
    iVar2 = iVar2 + 1;
  }
  param_2 = param_2 + iVar2;
  switch(*(uint *)(in_r9 + param_1) >> 5 & 7) {
  case 0:
    iVar2 = 0;
    cVar1 = s_CUBE_97c2d830[0];
    while (cVar1 != '\0') {
      *(char *)(param_2 + iVar2) = cVar1;
      cVar1 = "CUBE"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 1:
    iVar2 = 0;
    cVar1 = s_3D_97c2d82c[0];
    while (cVar1 != '\0') {
      *(char *)(param_2 + iVar2) = cVar1;
      cVar1 = "3D"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 2:
    iVar2 = 0;
    cVar1 = s_RECT_97c2d838[0];
    while (cVar1 != '\0') {
      *(char *)(param_2 + iVar2) = cVar1;
      cVar1 = "RECT"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 3:
    iVar2 = 0;
    cVar1 = s_2D_97c2d828[0];
    while (cVar1 != '\0') {
      *(char *)(param_2 + iVar2) = cVar1;
      cVar1 = "2D"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 4:
    iVar2 = 0;
    cVar1 = s_1D_97c2d824[0];
    while (cVar1 != '\0') {
      *(char *)(param_2 + iVar2) = cVar1;
      cVar1 = "1D"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 5:
    iVar2 = 0;
    cVar1 = s_SHADOWRECT_97c2d840[0];
    while (cVar1 != '\0') {
      *(char *)(param_2 + iVar2) = cVar1;
      cVar1 = "SHADOWRECT"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 6:
    iVar2 = 0;
    cVar1 = s_SHADOW2D_97c2d84c[0];
    while (cVar1 != '\0') {
      *(char *)(param_2 + iVar2) = cVar1;
      cVar1 = "SHADOW2D"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 7:
    iVar2 = 0;
    cVar1 = s_SHADOW1D_97c2d858[0];
    while (cVar1 != '\0') {
      *(char *)(param_2 + iVar2) = cVar1;
      cVar1 = "SHADOW1D"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  default:
    goto switchD_97be857c_default;
  }
  param_2 = param_2 + iVar2;
switchD_97be857c_default:
  return param_2;
}

/* _glpDisassemble1Op @ 0x97be8778 (4416 bytes) */
int _glpDisassemble1Op(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  uint *param_1;
  int param_2;
  int *param_3;
  int *param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
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
  undefined4 in_stack_00000038;
  int *in_stack_0000003c;
  byte in_stack_00000043;
  
  iVar13 = 0;
  uVar1 = *param_1;
  iVar10 = *in_stack_0000003c;
  uVar3 = param_1[1];
  uVar12 = (uint)in_stack_00000043;
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
        iVar10 = *in_stack_0000003c;
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
    iVar9 = ((int (*)())_glpWriteDestinationOperand)(param_1,iVar14 + iVar9,param_7,param_8,1,uVar12);
    iVar14 = 0;
    cVar2 = s___97c2d7ec[0];
    while (cVar2 != '\0') {
      *(char *)(iVar9 + iVar14) = cVar2;
      cVar2 = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    puVar15 = (undefined1 *)
              ((int (*)())_glpWriteSourceOperand)(param_1,iVar9 + iVar14,param_5,param_6,param_7,param_8,2,uVar12);
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
    iVar9 = ((int (*)())_glpWriteDestinationOperand)(param_1,iVar14 + iVar9,param_7,param_8,1,uVar12);
    iVar14 = 0;
    cVar2 = s___97c2d7ec[0];
    while (cVar2 != '\0') {
      *(char *)(iVar9 + iVar14) = cVar2;
      cVar2 = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    puVar15 = (undefined1 *)
              ((int (*)())_glpWriteSourceOperand)(param_1,iVar9 + iVar14,param_5,param_6,param_7,param_8,2,uVar12);
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
    iVar9 = ((int (*)())_glpWriteDestinationOperand)(param_1,iVar14 + iVar9,param_7,param_8,1,uVar12);
    iVar14 = 0;
    cVar2 = s___97c2d7ec[0];
    while (cVar2 != '\0') {
      *(char *)(iVar9 + iVar14) = cVar2;
      cVar2 = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    iVar9 = ((int (*)())_glpWriteSourceOperand)(param_1,iVar9 + iVar14,param_5,param_6,param_7,param_8,2,uVar12);
    iVar14 = 0;
    cVar2 = s___97c2d7ec[0];
    while (cVar2 != '\0') {
      *(char *)(iVar9 + iVar14) = cVar2;
      cVar2 = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    iVar13 = 3;
    puVar15 = (undefined1 *)
              ((int (*)())_glpWriteSourceOperand)(param_1,iVar9 + iVar14,param_5,param_6,param_7,param_8,3,uVar12);
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
    iVar9 = ((int (*)())_glpWriteDestinationOperand)(param_1,iVar14 + iVar9,param_7,param_8,1,uVar12);
    iVar14 = 0;
    cVar2 = s___97c2d7ec[0];
    while (cVar2 != '\0') {
      *(char *)(iVar9 + iVar14) = cVar2;
      cVar2 = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    puVar15 = (undefined1 *)
              ((int (*)())_glpWriteSourceOperand)(param_1,iVar9 + iVar14,param_5,param_6,param_7,param_8,2,uVar12);
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
    iVar9 = ((int (*)())_glpWriteDestinationOperand)(param_1,iVar14 + iVar9,param_7,param_8,1,uVar12);
    iVar14 = 0;
    cVar2 = s___97c2d7ec[0];
    while (cVar2 != '\0') {
      *(char *)(iVar9 + iVar14) = cVar2;
      cVar2 = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    iVar9 = ((int (*)())_glpWriteSourceOperand)(param_1,iVar9 + iVar14,param_5,param_6,param_7,param_8,2,uVar12);
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
    iVar9 = ((int (*)())_glpWriteDestinationOperand)(param_1,iVar14 + iVar9,param_7,param_8,1,uVar12);
    iVar14 = 0;
    cVar2 = s___97c2d7ec[0];
    while (cVar2 != '\0') {
      *(char *)(iVar9 + iVar14) = cVar2;
      cVar2 = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    iVar9 = ((int (*)())_glpWriteSourceOperand)(param_1,iVar9 + iVar14,param_5,param_6,param_7,param_8,2,uVar12);
    iVar14 = 0;
    cVar2 = s___97c2d7ec[0];
    while (cVar2 != '\0') {
      *(char *)(iVar9 + iVar14) = cVar2;
      cVar2 = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    puVar15 = (undefined1 *)
              ((int (*)())_glpWriteTextureOperand)(param_1,iVar9 + iVar14,param_5,param_6,param_7,param_8,3,uVar12);
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
              ((int (*)())_glpWriteSourceOperand)(param_1,puVar15 + iVar14,param_5,param_6,param_7,param_8,iVar13,uVar12);
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
              ((int (*)())_glpWriteBranchOperand)(param_1,puVar15 + iVar14,in_stack_00000038,1,uVar11 == 0x4b);
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
    *in_stack_0000003c = *in_stack_0000003c + 1;
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
    *in_stack_0000003c = *in_stack_0000003c + 1;
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
    *in_stack_0000003c = *in_stack_0000003c + 1;
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
              ((int (*)())_glpWriteSourceOperand)(param_1,puVar15,param_5,param_6,param_7,param_8,2,uVar12);
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
    iVar9 = ((int (*)())_glpWriteDestinationOperand)(param_1,iVar14 + iVar9,param_7,param_8,1,uVar12);
    iVar14 = 0;
    cVar2 = s___97c2d7ec[0];
    while (cVar2 != '\0') {
      *(char *)(iVar9 + iVar14) = cVar2;
      cVar2 = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    iVar9 = ((int (*)())_glpWriteSourceOperand)(param_1,iVar9 + iVar14,param_5,param_6,param_7,param_8,2,uVar12);
    iVar14 = 0;
    cVar2 = s___97c2d7ec[0];
    while (cVar2 != '\0') {
      *(char *)(iVar9 + iVar14) = cVar2;
      cVar2 = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    iVar9 = ((int (*)())_glpWriteSourceOperand)(param_1,iVar9 + iVar14,param_5,param_6,param_7,param_8,3,uVar12);
    iVar14 = 0;
    cVar2 = s___97c2d7ec[0];
    while (cVar2 != '\0') {
      *(char *)(iVar9 + iVar14) = cVar2;
      cVar2 = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
    iVar10 = 4;
    iVar9 = ((int (*)())_glpWriteSourceOperand)(param_1,iVar9 + iVar14,param_5,param_6,param_7,param_8,4,uVar12);
    iVar14 = 0;
    cVar2 = s___97c2d7ec[0];
    while (cVar2 != '\0') {
      *(char *)(iVar9 + iVar14) = cVar2;
      cVar2 = ", "[iVar14 + 1];
      iVar14 = iVar14 + 1;
    }
LAB_97be9848:
    puVar15 = (undefined1 *)
              ((int (*)())_glpWriteTextureOperand)(param_1,iVar9 + iVar14,param_5,param_6,param_7,param_8,iVar10 + 1,uVar12);
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
  
  iVar2 = *(int *)(param_1 + 0x40);
  param_1 = param_1 + *(int *)(param_1 + 0x44) * 8;
  if ((iVar2 != 0) && (iVar1 = 0, 0 < iVar2)) {
    do {
      if ((*(uint *)(param_1 + iVar1 * 8) & 0xffff) == param_2) {
        *param_3 = (uint)*(ushort *)(iVar1 * 8 + param_1 + 6);
        return 1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < iVar2);
  }
  return 0;
}

/* _isParamArrayStart @ 0x97be9b80 (96 bytes) */
int _isParamArrayStart(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint *param_3;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x38);
  param_1 = param_1 + *(int *)(param_1 + 0x3c) * 8;
  if ((iVar2 != 0) && (iVar1 = 0, 0 < iVar2)) {
    do {
      if ((*(uint *)(param_1 + iVar1 * 8) & 0xffff) == param_2) {
        *param_3 = (uint)*(ushort *)(iVar1 * 8 + param_1 + 6);
        return 1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < iVar2);
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
  undefined4 uVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar7 = 0;
  if ((param_5 < 1) || (piVar5 = param_1, param_3 <= *param_1)) {
    bVar1 = param_5 == 0;
    iVar2 = 0;
  }
  else {
    do {
      iVar7 = iVar7 + 1;
      bVar1 = iVar7 == param_5;
      if (param_5 <= iVar7) {
        iVar2 = iVar7 * 4;
        break;
      }
      piVar5 = piVar5 + 1;
      iVar2 = iVar7 * 4;
    } while (*piVar5 < param_3);
  }
  if (bVar1) {
    *(int *)(iVar2 + (int)param_1) = param_3;
    *(undefined4 *)(iVar2 + param_2) = param_4;
    iVar9 = param_5 + 1;
  }
  else {
    iVar6 = *(int *)(iVar2 + (int)param_1);
    iVar9 = param_5;
    if (iVar6 != param_3) {
      iVar7 = iVar7 + 1;
      *(int *)(iVar2 + (int)param_1) = param_3;
      uVar3 = *(undefined4 *)(iVar2 + param_2);
      *(undefined4 *)(iVar2 + param_2) = param_4;
      iVar9 = param_5 + 1;
      if (iVar7 < param_5) {
        param_5 = param_5 - iVar7;
        uVar4 = uVar3;
        iVar2 = iVar7;
        iVar8 = iVar6;
        do {
          iVar7 = iVar2 + 1;
          iVar6 = param_1[iVar2];
          param_1[iVar2] = iVar8;
          uVar3 = *(undefined4 *)(param_2 + iVar2 * 4);
          *(undefined4 *)(param_2 + iVar2 * 4) = uVar4;
          param_5 = param_5 + -1;
          uVar4 = uVar3;
          iVar2 = iVar7;
          iVar8 = iVar6;
        } while (param_5 != 0);
      }
      param_1[iVar7] = iVar6;
      *(undefined4 *)(param_2 + iVar7 * 4) = uVar3;
    }
  }
  return iVar9;
}

/* _adjustAllocation @ 0x97be9cb4 (124 bytes) */
int _adjustAllocation(param_1, param_2, param_3)
  size_t *param_1;
  int *param_2;
  int *param_3;
{
  int iVar1;
  void *pvVar2;
  size_t sVar3;
  int iVar4;
  
  iVar1 = *param_2;
  iVar4 = *param_3;
  if ((int)(*param_1 - (iVar4 - iVar1)) < 0x100) {
    sVar3 = *param_1 + 0x800;
    *param_1 = sVar3;
    pvVar2 = _realloc((void *)*param_2,sVar3);
    *param_3 = (int)pvVar2;
    if (pvVar2 == (void *)0x0) {
      return 0;
    }
    *param_2 = (int)pvVar2;
    *param_3 = (int)pvVar2 + (iVar4 - iVar1);
  }
  return 1;
}

/* _glpPPDisassemble @ 0x97be9d30 (27772 bytes) */
int _glpPPDisassemble(param_1)
  uint *param_1;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  char acVar6;
  byte bVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint *puVar12;
  undefined1 *puVar13;
  int iVar14;
  void *pvVar15;
  uint uVar16;
  uint uVar17;
  int *piVar18;
  uint *puVar19;
  int iVar20;
  int iVar21;
  uint uVar22;
  size_t sVar23;
  float *pfVar24;
  byte in_xer_so;
  uint uVar25;
  undefined8 uVar26;
  char local_2b0;
  char acStack_2af [255];
  char local_1b0 [256];
  int local_b0;
  void *local_ac;
  undefined1 *local_a8;
  uint local_a4;
  uint local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  void *local_88;
  void *local_84;
  void *local_80;
  void *local_7c;
  int *local_78;
  void *local_74;
  void *local_70;
  size_t local_6c;
  int local_68;
  uint local_64;
  char *local_60;
  int local_5c;
  int local_58;
  
  local_b0 = 0x800;
  local_9c = 1;
  local_ac = _malloc(0x800);
  local_90 = 0;
  local_88 = (void *)0x0;
  local_84 = (void *)0x0;
  local_80 = (void *)0x0;
  local_7c = (void *)0x0;
  local_78 = (int *)0x0;
  local_74 = (void *)0x0;
  local_70 = (void *)0x0;
  local_6c = 0;
  local_68 = 0;
  if (local_ac == (void *)0x0) {
    return (void *)0x0;
  }
  uVar16 = *param_1;
  local_64 = (uint)(uVar16 - 0x8b30 < 2);
  if (uVar16 == 0x8804) {
    iVar20 = 0;
    cVar5 = s___ARBfp1_0_97c2d8bc[0];
    while (cVar5 != '\0') {
      *(char *)((int)local_ac + iVar20) = cVar5;
      cVar5 = "!!ARBfp1.0\n"[iVar20 + 1];
      iVar20 = iVar20 + 1;
    }
  }
  else if (uVar16 < 0x8805) {
    if (uVar16 == 0x8620) {
      iVar20 = 0;
      cVar5 = s___ARBvp1_0_97c2d89c[0];
      while (cVar5 != '\0') {
        *(char *)((int)local_ac + iVar20) = cVar5;
        cVar5 = "!!ARBvp1.0\n"[iVar20 + 1];
        iVar20 = iVar20 + 1;
      }
    }
    else {
LAB_97be9f08:
      iVar20 = 0;
      cVar5 = s_Unkown_Target__error__97c2d8e0[0];
      while (cVar5 != '\0') {
        *(char *)((int)local_ac + iVar20) = cVar5;
        cVar5 = "Unkown Target (error)\n"[iVar20 + 1];
        iVar20 = iVar20 + 1;
      }
    }
  }
  else if (uVar16 == 0x8b30) {
    iVar20 = 0;
    cVar5 = s___ARBfragmentshader_97c2d8c8[0];
    while (cVar5 != '\0') {
      *(char *)((int)local_ac + iVar20) = cVar5;
      cVar5 = "!!ARBfragmentshader\n"[iVar20 + 1];
      iVar20 = iVar20 + 1;
    }
  }
  else {
    if (uVar16 != 0x8b31) goto LAB_97be9f08;
    iVar20 = 0;
    cVar5 = s___ARBvertexshader_97c2d8a8[0];
    while (cVar5 != '\0') {
      *(char *)((int)local_ac + iVar20) = cVar5;
      cVar5 = "!!ARBvertexshader\n"[iVar20 + 1];
      iVar20 = iVar20 + 1;
    }
  }
  local_a8 = (undefined1 *)((int)local_ac + iVar20);
  bVar2 = local_64 == 0;
  if (!bVar2) {
    iVar20 = 0;
    cVar5 = s__97c26c38[0];
    while (cVar5 != '\0') {
      local_a8[iVar20] = cVar5;
      cVar5 = "\n"[iVar20 + 1];
      iVar20 = iVar20 + 1;
    }
    local_a8 = local_a8 + iVar20;
  }
  uVar17 = param_1[0x12];
  iVar20 = 0;
  uVar9 = param_1[0x13];
  if (0 < (int)uVar17) {
    local_60 = "o intialize the Preprocessor";
    do {
      iVar11 = 0;
      cVar5 = s_OPTION_97c2d8fc[0];
      while (cVar5 != '\0') {
        local_a8[iVar11] = cVar5;
        cVar5 = "OPTION "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      local_a8 = local_a8 + iVar11;
      switch(param_1[uVar9 * 2 + iVar20 * 2] & 0xff) {
      case 0:
        iVar11 = 0;
        cVar5 = s_ARB_position_invariant_97c2d904[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "ARB_position_invariant"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      case 1:
        iVar11 = 0;
        cVar5 = s_ARB_fog_exp_97c2d91c[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "ARB_fog_exp"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      case 2:
        iVar11 = 0;
        cVar5 = s_ARB_fog_exp2_97c2d928[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "ARB_fog_exp2"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      case 3:
        iVar11 = 0;
        cVar5 = s_ARB_fog_linear_97c2d938[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "ARB_fog_linear"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      case 4:
        iVar11 = 0;
        cVar5 = s_ARB_precision_hint_fastest_97c2d948[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "ARB_precision_hint_fastest"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      case 5:
        iVar11 = 0;
        cVar5 = s_ARB_precision_hint_nicest_97c2d964[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "ARB_precision_hint_nicest"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      case 6:
        iVar11 = 0;
        cVar5 = s_APPLE_no_runtime_compile_97c2d980[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "APPLE_no_runtime_compile"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      case 7:
        iVar11 = 0;
        cVar5 = s_APPLE_no_altivec_97c2d99c[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "APPLE_no_altivec"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      case 8:
        iVar11 = 0;
        cVar5 = s_NV_fragment_program_97c2d9b0[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "NV_fragment_program"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      case 9:
        iVar11 = 0;
        cVar5 = s_NV_fragment_program2_97c2d9c4[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "NV_fragment_program2"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      case 10:
        iVar11 = 0;
        cVar5 = s_NV_vertex_program2_97c2d9f8[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "NV_vertex_program2"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      case 0xb:
        iVar11 = 0;
        cVar5 = s_NV_vertex_program3_97c2da0c[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "NV_vertex_program3"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      case 0xc:
        iVar11 = 0;
        cVar5 = s_ARB_draw_buffers_97c2da20[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "ARB_draw_buffers"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      case 0xd:
        iVar11 = 0;
        cVar5 = s_ARB_fragment_program_shadow_97c2d9dc[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "ARB_fragment_program_shadow"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      default:
        goto switchD_97bea038_default;
      }
      local_a8 = local_a8 + iVar11;
switchD_97bea038_default:
      iVar11 = 0;
      cVar5 = local_60[0x3bbc];
      while (cVar5 != '\0') {
        local_a8[iVar11] = cVar5;
        iVar11 = iVar11 + 1;
        cVar5 = (local_60 + 0x3bbc)[iVar11];
      }
      local_a8 = local_a8 + iVar11;
      iVar11 = ((int (*)())_adjustAllocation)(&local_b0,&local_ac,&local_a8);
      if (iVar11 == 0) goto LAB_97bf0cec;
      iVar20 = iVar20 + 1;
    } while (iVar20 < (int)uVar17);
  }
  if ((uVar17 != 0) && (!bVar2)) {
    iVar20 = 0;
    cVar5 = s__97c26c38[0];
    while (cVar5 != '\0') {
      local_a8[iVar20] = cVar5;
      cVar5 = "\n"[iVar20 + 1];
      iVar20 = iVar20 + 1;
    }
    local_a8 = local_a8 + iVar20;
  }
  uVar9 = param_1[6];
  if (uVar9 != 0) {
    iVar20 = 0;
    cVar5 = s_ADDRESS_adr0_97c2da34[0];
    while (cVar5 != '\0') {
      local_a8[iVar20] = cVar5;
      cVar5 = "ADDRESS adr0"[iVar20 + 1];
      iVar20 = iVar20 + 1;
    }
    iVar11 = 1;
    local_a8 = local_a8 + iVar20;
    if (1 < (int)uVar9) {
      do {
        iVar20 = 0;
        cVar5 = s___adr_97c2da44[0];
        while (cVar5 != '\0') {
          local_a8[iVar20] = cVar5;
          cVar5 = ", adr"[iVar20 + 1];
          iVar20 = iVar20 + 1;
        }
        local_a8 = local_a8 + iVar20;
        iVar21 = iVar11 + 1;
        iVar20 = ((int (*)())_ncpy)(local_a8,iVar11);
        local_a8 = local_a8 + iVar20;
        iVar11 = iVar21;
      } while (iVar21 < (int)uVar9);
    }
    iVar20 = 0;
    cVar5 = s___97c2d8f8[0];
    while (cVar5 != '\0') {
      local_a8[iVar20] = cVar5;
      cVar5 = ";\n"[iVar20 + 1];
      iVar20 = iVar20 + 1;
    }
    local_a8 = local_a8 + iVar20;
    iVar20 = ((int (*)())_adjustAllocation)(&local_b0,&local_ac,&local_a8);
    if (iVar20 == 0) goto LAB_97bf0cec;
    if (!bVar2) {
      iVar20 = 0;
      cVar5 = s__97c26c38[0];
      while (cVar5 != '\0') {
        local_a8[iVar20] = cVar5;
        cVar5 = "\n"[iVar20 + 1];
        iVar20 = iVar20 + 1;
      }
      local_a8 = local_a8 + iVar20;
    }
  }
  uVar9 = 0;
  bVar3 = true;
  uVar17 = param_1[4];
  puVar19 = param_1 + param_1[5] * 2;
  if (!bVar2) {
    uVar22 = 0xffffffff;
    if ((int)uVar17 < 1) {
LAB_97bea680:
      local_5c = (uint)(byte)(((int)local_80 < 0) << 3 | (0 < (int)local_80) << 2 |
                              (local_80 == (void *)0x0) << 1 | in_xer_so & 1) << 0x1c;
      local_58 = local_5c;
LAB_97bea698:
      local_78 = (int *)0x0;
      if (param_1[0x10] != 0) {
        local_78 = _malloc(param_1[0x10] << 2);
      }
      iVar20 = 0;
      iVar11 = -1;
      local_a4 = 0xffffffff;
      uVar22 = 0xffffffff;
      if (0 < (int)uVar17) {
        iVar21 = 0;
        piVar18 = local_78;
        puVar12 = puVar19;
        do {
          if (uVar22 == 0xffffffff) {
            *(uint *)((uint)*(ushort *)((int)puVar12 + 6) * 4 + (int)local_80) =
                 (uint)*(ushort *)((int)puVar12 + 6);
            iVar14 = ((int (*)())_isTempArrayStart)(param_1,*(undefined2 *)((int)puVar12 + 6),&local_a4);
            if (iVar14 == 0) {
              *(int *)((int)local_7c + (uint)*(ushort *)((int)puVar12 + 6) * 4) = iVar11;
            }
            else {
              uVar22 = (uint)*(ushort *)((int)puVar12 + 6);
              *(undefined4 *)((int)local_7c + uVar22 * 4) = 0;
              iVar11 = 1;
            }
            bVar1 = *(ushort *)((int)puVar19 + iVar21 + 6) == local_a4;
LAB_97bea790:
            if (bVar1) {
              local_a4 = 0xffffffff;
              uVar22 = 0xffffffff;
              *piVar18 = iVar11;
              piVar18 = piVar18 + 1;
              iVar11 = -1;
            }
          }
          else if ((int)(uint)*(ushort *)((int)puVar12 + 6) <= (int)local_a4) {
            *(uint *)((uint)*(ushort *)((int)puVar12 + 6) * 4 + (int)local_80) = uVar22;
            *(int *)((int)local_7c + (uint)*(ushort *)((int)puVar12 + 6) * 4) = iVar11;
            iVar11 = iVar11 + 1;
            bVar1 = *(ushort *)((int)puVar12 + 6) == local_a4;
            goto LAB_97bea790;
          }
          iVar20 = iVar20 + 1;
          iVar21 = iVar21 + 8;
          puVar12 = puVar12 + 2;
        } while (iVar20 < (int)uVar17);
      }
      local_90 = 0;
      goto LAB_97bea7e0;
    }
    puVar12 = puVar19 + 1;
    uVar25 = uVar17;
    do {
      uVar10 = *puVar12;
      puVar12 = puVar12 + 2;
      if ((int)uVar22 < (int)(uVar10 & 0xffff)) {
        uVar22 = uVar10 & 0xffff;
      }
      uVar25 = uVar25 - 1;
    } while (uVar25 != 0);
    if (uVar22 == 0xffffffff) goto LAB_97bea680;
    sVar23 = uVar22 * 4 + 4;
    local_80 = _malloc(sVar23);
    local_5c = (uint)(byte)(((int)local_80 < 0) << 3 | (0 < (int)local_80) << 2 |
                            (local_80 == (void *)0x0) << 1 | in_xer_so & 1) << 0x1c;
    local_7c = _malloc(sVar23);
    bVar7 = (byte)((uint)local_5c >> 0x18);
    if (!(bool)(bVar7 >> 5 & 1)) {
      local_58 = (uint)(byte)(((int)local_7c < 0) << 3 | (0 < (int)local_7c) << 2 |
                              (local_7c == (void *)0x0) << 1 | in_xer_so & 1) << 0x1c;
      if (local_7c == (void *)0x0) goto joined_r0x97bea678;
      goto LAB_97bea698;
    }
    local_58 = (uint)(byte)(((int)local_7c < 0) << 3 | (0 < (int)local_7c) << 2 |
                            (local_7c == (void *)0x0) << 1 | in_xer_so & 1) << 0x1c;
joined_r0x97bea678:
    if (!(bool)(bVar7 >> 5 & 1)) {
      _free(local_80);
    }
    pvVar15 = local_7c;
    if (!(bool)((byte)((uint)local_58 >> 0x1d) & 1)) {
LAB_97bee10c:
      _free(pvVar15);
    }
LAB_97bf0cec:
    _free(local_ac);
    return (void *)0x0;
  }
  local_5c = (uint)(byte)(((int)local_80 < 0) << 3 | (0 < (int)local_80) << 2 |
                          (local_80 == (void *)0x0) << 1 | in_xer_so & 1) << 0x1c;
  local_58 = local_5c;
LAB_97bea7e0:
  uVar22 = 0;
  local_8c = -1;
  if (0 < (int)uVar17) {
    do {
      iVar20 = uVar22 * 8;
      if (bVar3) {
        uVar9 = puVar19[uVar22 * 2] >> 0x1d;
        if (uVar9 == 1) {
          iVar11 = 0;
          cVar5 = s_LONG_TEMP_97c2da54[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = "LONG TEMP "[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
LAB_97bea924:
          local_a8 = local_a8 + iVar11;
        }
        else if (uVar9 < 2) {
          if (uVar9 == 0) {
            iVar11 = 0;
            cVar5 = s_TEMP_97c2da4c[0];
            while (cVar5 != '\0') {
              local_a8[iVar11] = cVar5;
              cVar5 = "TEMP "[iVar11 + 1];
              iVar11 = iVar11 + 1;
            }
            goto LAB_97bea924;
          }
        }
        else if (uVar9 == 2) {
          iVar11 = 0;
          cVar5 = s_SHORT_TEMP_97c2da60[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = "SHORT TEMP "[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          goto LAB_97bea924;
        }
        bVar3 = false;
        uVar9 = puVar19[uVar22 * 2] >> 0x1d;
      }
      if (bVar2) {
        iVar11 = 0;
        cVar5 = s_tmp_97c2d76c[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "tmp"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        local_a8 = local_a8 + iVar11;
        iVar20 = ((int (*)())_ncpy)(local_a8,*(undefined2 *)((int)puVar19 + iVar20 + 6));
        local_a8 = local_a8 + iVar20;
      }
      else {
        iVar11 = *(int *)((int)local_7c + (uint)*(ushort *)((int)puVar19 + iVar20 + 6) * 4);
        if (iVar11 == -1) {
          iVar11 = 0;
          cVar5 = s_tmp_97c2d76c[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = "tmp"[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          local_a8 = local_a8 + iVar11;
          iVar20 = ((int (*)())_ncpy)(local_a8,*(undefined4 *)
                                   ((int)local_80 + (uint)*(ushort *)((int)puVar19 + iVar20 + 6) * 4
                                   ));
          local_a8 = local_a8 + iVar20;
          uVar25 = puVar19[uVar22 * 2];
          local_a8 = (undefined1 *)
                     ((int (*)())_glpWriteSizeTypePrecision)(local_a8,uVar25 >> 0x18 & 3,0,uVar25 >> 0x1a & 7,uVar25 >> 0x1d);
        }
        else {
          if (iVar11 == 0) {
            local_8c = 0;
            iVar11 = 0;
            cVar5 = s_tmp_97c2d76c[0];
            while (cVar5 != '\0') {
              local_a8[iVar11] = cVar5;
              cVar5 = "tmp"[iVar11 + 1];
              iVar11 = iVar11 + 1;
            }
            local_a8 = local_a8 + iVar11;
            iVar11 = ((int (*)())_ncpy)(local_a8,*(undefined4 *)
                                     ((int)local_80 +
                                     (uint)*(ushort *)((int)puVar19 + iVar20 + 6) * 4));
            iVar20 = 0;
            cVar5 = s___97c29860[0];
            while (cVar5 != '\0') {
              local_a8[iVar20 + iVar11] = cVar5;
              cVar5 = "["[iVar20 + 1];
              iVar20 = iVar20 + 1;
            }
            local_a8 = local_a8 + iVar20 + iVar11;
            iVar20 = local_90 * 4;
            iVar21 = ((int (*)())_ncpy)(local_a8,local_78[local_90]);
            iVar11 = 0;
            cVar5 = s___97c2d770[0];
            while (cVar5 != '\0') {
              local_a8[iVar11 + iVar21] = cVar5;
              cVar5 = "]"[iVar11 + 1];
              iVar11 = iVar11 + 1;
            }
            local_a8 = local_a8 + iVar11 + iVar21;
            uVar25 = puVar19[uVar22 * 2];
            local_a8 = (undefined1 *)
                       ((int (*)())_glpWriteSizeTypePrecision)(local_a8,uVar25 >> 0x18 & 3,0,uVar25 >> 0x1a & 7,uVar25 >> 0x1d);
          }
          else {
            local_8c = local_8c + 1;
            iVar20 = local_90 << 2;
          }
          if (local_8c + 1 == *(int *)(iVar20 + (int)local_78)) {
            local_8c = -1;
            local_90 = local_90 + 1;
          }
        }
      }
      uVar25 = uVar22 + 1;
      if (uVar25 == uVar17) {
        iVar20 = 0;
        cVar5 = s___97c2d8f8[0];
        while (cVar5 != '\0') {
          local_a8[iVar20] = cVar5;
          cVar5 = ";\n"[iVar20 + 1];
          iVar20 = iVar20 + 1;
        }
LAB_97beacc8:
        local_a8 = local_a8 + iVar20;
      }
      else {
        if (puVar19[uVar22 * 2 + 2] >> 0x1d != uVar9) {
          local_60 = "o intialize the Preprocessor";
          iVar20 = 0;
          cVar5 = s___97c2d8f8[0];
          while (cVar5 != '\0') {
            local_a8[iVar20] = cVar5;
            cVar5 = ";\n"[iVar20 + 1];
            iVar20 = iVar20 + 1;
          }
          bVar3 = true;
          goto LAB_97beacc8;
        }
        if (local_8c == -1) {
          iVar20 = 0;
          cVar5 = s___97c2d7ec[0];
          while (cVar5 != '\0') {
            local_a8[iVar20] = cVar5;
            cVar5 = ", "[iVar20 + 1];
            iVar20 = iVar20 + 1;
          }
          goto LAB_97beacc8;
        }
      }
      iVar20 = ((int (*)())_adjustAllocation)(&local_b0,&local_ac,&local_a8);
      if (iVar20 == 0) goto LAB_97bf0c18;
      uVar22 = uVar25;
    } while ((int)uVar25 < (int)uVar17);
  }
  if (local_78 != (int *)0x0) {
    _free(local_78);
  }
  if ((uVar17 != 0) && (!bVar2)) {
    iVar20 = 0;
    cVar5 = s__97c26c38[0];
    while (cVar5 != '\0') {
      local_a8[iVar20] = cVar5;
      cVar5 = "\n"[iVar20 + 1];
      iVar20 = iVar20 + 1;
    }
    local_a8 = local_a8 + iVar20;
  }
  uVar17 = param_1[8];
  iVar20 = 0;
  uVar9 = param_1[9];
  if (0 < (int)uVar17) {
    do {
      uVar22 = param_1[uVar9 * 2 + iVar20 * 2] >> 0x10 & 0xf;
      if (uVar22 != 0) {
        iVar11 = 0;
        cVar5 = s_ATTRIB_att_97c2da6c[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "ATTRIB att"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        local_a8 = local_a8 + iVar11;
        iVar11 = ((int (*)())_ncpy)(local_a8,*(undefined2 *)((int)param_1 + iVar20 * 8 + uVar9 * 8 + 6));
        local_a8 = local_a8 + iVar11;
        if (!bVar2) {
          uVar25 = param_1[uVar9 * 2 + iVar20 * 2];
          local_a8 = (undefined1 *)
                     ((int (*)())_glpWriteSizeTypePrecision)(local_a8,uVar25 >> 0x18 & 3,0,uVar25 >> 0x1a & 7,uVar25 >> 0x1d);
        }
        if (uVar16 == 0x8804) {
LAB_97beae94:
          iVar11 = 0;
          cVar5 = s___fragment__97c2da84[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = " = fragment."[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
LAB_97beaecc:
          local_a8 = local_a8 + iVar11;
        }
        else {
          if (uVar16 < 0x8805) {
            uVar25 = 0x8620;
          }
          else {
            if (uVar16 == 0x8b30) goto LAB_97beae94;
            uVar25 = 0x8b31;
          }
          if (uVar16 == uVar25) {
            iVar11 = 0;
            cVar5 = s___vertex__97c2da78[0];
            while (cVar5 != '\0') {
              local_a8[iVar11] = cVar5;
              cVar5 = " = vertex."[iVar11 + 1];
              iVar11 = iVar11 + 1;
            }
            goto LAB_97beaecc;
          }
        }
        switch(uVar22) {
        default:
          goto switchD_97beaef4_caseD_0;
        case 1:
          iVar11 = 0;
          cVar5 = s_position_97c2da94[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = "position"[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          break;
        case 2:
          iVar11 = 0;
          cVar5 = s_color_primary_97c2daa0[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = "color.primary"[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          break;
        case 3:
          iVar11 = 0;
          cVar5 = s_color_secondary_97c2dab0[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = "color.secondary"[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          break;
        case 4:
          iVar11 = 0;
          cVar5 = s_normal_97c2dac0[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = "normal"[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          break;
        case 5:
          iVar11 = 0;
          cVar5 = s_fogcoord_97c2dac8[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = "fogcoord"[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          break;
        case 6:
          iVar11 = 0;
          cVar5 = s_weight__97c2daec[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = "weight["[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          local_a8 = local_a8 + iVar11;
          iVar11 = ((int (*)())_ncpy)(local_a8,param_1[uVar9 * 2 + iVar20 * 2] & 0x1f);
          local_a8 = local_a8 + iVar11;
          iVar11 = 0;
          cVar5 = s___97c2d770[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = "]"[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          break;
        case 7:
          iVar11 = 0;
          cVar5 = s_texcoord__97c2dae0[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = "texcoord["[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          local_a8 = local_a8 + iVar11;
          iVar11 = ((int (*)())_ncpy)(local_a8,param_1[uVar9 * 2 + iVar20 * 2] & 0x1f);
          local_a8 = local_a8 + iVar11;
          iVar11 = 0;
          cVar5 = s___97c2d770[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = "]"[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          break;
        case 8:
          iVar11 = 0;
          cVar5 = s_matrixindex__97c2daf4[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = "matrixindex["[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          local_a8 = local_a8 + iVar11;
          iVar11 = ((int (*)())_ncpy)(local_a8,param_1[uVar9 * 2 + iVar20 * 2] & 0x1f);
          local_a8 = local_a8 + iVar11;
          iVar11 = 0;
          cVar5 = s___97c2d770[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = "]"[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          break;
        case 9:
          iVar11 = 0;
          cVar5 = s_attrib__97c2db04[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = "attrib["[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          local_a8 = local_a8 + iVar11;
          iVar11 = ((int (*)())_ncpy)(local_a8,param_1[uVar9 * 2 + iVar20 * 2] & 0x1f);
          local_a8 = local_a8 + iVar11;
          iVar11 = 0;
          cVar5 = s___97c2d770[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = "]"[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          break;
        case 10:
          iVar11 = 0;
          cVar5 = s_material__97c2db0c[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = "material."[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          local_a8 = local_a8 + iVar11;
          if ((param_1[uVar9 * 2 + iVar20 * 2] & 1) == 0) {
            iVar11 = 0;
            cVar5 = s_front__97c2db18[0];
            while (cVar5 != '\0') {
              local_a8[iVar11] = cVar5;
              cVar5 = "front."[iVar11 + 1];
              iVar11 = iVar11 + 1;
            }
LAB_97beb3a8:
            local_a8 = local_a8 + iVar11;
          }
          else if ((param_1[uVar9 * 2 + iVar20 * 2] & 1) == 1) {
            iVar11 = 0;
            cVar5 = s_back__97c2db20[0];
            while (cVar5 != '\0') {
              local_a8[iVar11] = cVar5;
              cVar5 = "back."[iVar11 + 1];
              iVar11 = iVar11 + 1;
            }
            goto LAB_97beb3a8;
          }
          switch(param_1[uVar9 * 2 + iVar20 * 2] >> 0xc & 0xf) {
          case 0:
            iVar11 = 0;
            cVar5 = s_ambient_97c2db28[0];
            while (cVar5 != '\0') {
              local_a8[iVar11] = cVar5;
              cVar5 = "ambient"[iVar11 + 1];
              iVar11 = iVar11 + 1;
            }
            break;
          case 1:
            iVar11 = 0;
            cVar5 = s_diffuse_97c2db30[0];
            while (cVar5 != '\0') {
              local_a8[iVar11] = cVar5;
              cVar5 = "diffuse"[iVar11 + 1];
              iVar11 = iVar11 + 1;
            }
            break;
          case 2:
            iVar11 = 0;
            cVar5 = s_specular_97c2db38[0];
            while (cVar5 != '\0') {
              local_a8[iVar11] = cVar5;
              cVar5 = "specular"[iVar11 + 1];
              iVar11 = iVar11 + 1;
            }
            break;
          case 3:
            iVar11 = 0;
            cVar5 = s_emission_97c2db44[0];
            while (cVar5 != '\0') {
              local_a8[iVar11] = cVar5;
              cVar5 = "emission"[iVar11 + 1];
              iVar11 = iVar11 + 1;
            }
            break;
          case 4:
            iVar11 = 0;
            cVar5 = s_shininess_97c2db50[0];
            while (cVar5 != '\0') {
              local_a8[iVar11] = cVar5;
              cVar5 = "shininess"[iVar11 + 1];
              iVar11 = iVar11 + 1;
            }
            break;
          default:
            goto switchD_97beaef4_caseD_0;
          }
          break;
        case 0xb:
          iVar11 = 0;
          cVar5 = s_frontfacing_97c2dad4[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = "frontfacing"[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
        }
        local_a8 = local_a8 + iVar11;
switchD_97beaef4_caseD_0:
        iVar11 = 0;
        cVar5 = s___97c2d8f8[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = ";\n"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        local_a8 = local_a8 + iVar11;
        iVar11 = ((int (*)())_adjustAllocation)(&local_b0,&local_ac,&local_a8);
        if (iVar11 == 0) goto LAB_97bf0c18;
      }
      iVar20 = iVar20 + 1;
    } while (iVar20 < (int)uVar17);
  }
  if ((uVar17 != 0) && (!bVar2)) {
    iVar20 = 0;
    cVar5 = s__97c26c38[0];
    while (cVar5 != '\0') {
      local_a8[iVar20] = cVar5;
      cVar5 = "\n"[iVar20 + 1];
      iVar20 = iVar20 + 1;
    }
    local_a8 = local_a8 + iVar20;
  }
  uVar9 = param_1[10];
  puVar19 = param_1 + param_1[0xb] * 2;
  if (uVar9 == 0) {
    bVar3 = local_88 == (void *)0x0;
    goto LAB_97bed528;
  }
  uVar17 = 0xffffffff;
  if ((int)uVar9 < 1) {
LAB_97beb670:
    bVar3 = local_88 == (void *)0x0;
  }
  else {
    puVar12 = puVar19 + 1;
    uVar22 = uVar9;
    do {
      uVar25 = *puVar12;
      puVar12 = puVar12 + 2;
      if ((int)uVar17 < (int)(uVar25 & 0xffff)) {
        uVar17 = uVar25 & 0xffff;
      }
      uVar22 = uVar22 - 1;
    } while (uVar22 != 0);
    if (uVar17 == 0xffffffff) goto LAB_97beb670;
    sVar23 = uVar17 * 4 + 4;
    local_88 = _malloc(sVar23);
    bVar1 = local_88 == (void *)0x0;
    local_84 = _malloc(sVar23);
    if ((bVar1) || (bVar3 = false, local_84 == (void *)0x0)) {
      bVar3 = local_84 == (void *)0x0;
joined_r0x97beb668:
      if (!bVar1) {
        _free(local_88);
      }
      if (!bVar3) {
        _free(local_84);
      }
LAB_97bf0c18:
      bVar7 = (byte)((uint)local_5c >> 0x18);
      goto joined_r0x97bea678;
    }
  }
  local_78 = (int *)0x0;
  if (param_1[0xe] != 0) {
    local_78 = _malloc(param_1[0xe] << 2);
  }
  iVar20 = 0;
  iVar11 = -1;
  local_a0 = 0xffffffff;
  uVar17 = 0xffffffff;
  piVar18 = local_78;
  puVar12 = puVar19;
  if (0 < (int)uVar9) {
    do {
      if ((*puVar12 & 0x1f0000) != 0) {
        if (uVar17 == 0xffffffff) {
          *(uint *)((uint)*(ushort *)((int)puVar12 + 6) * 4 + (int)local_88) =
               (uint)*(ushort *)((int)puVar12 + 6);
          iVar21 = ((int (*)())_isParamArrayStart)(param_1,*(undefined2 *)((int)puVar12 + 6),&local_a0);
          if (iVar21 == 0) {
            *(int *)((int)local_84 + (uint)*(ushort *)((int)puVar12 + 6) * 4) = iVar11;
          }
          else {
            uVar17 = (uint)*(ushort *)((int)puVar12 + 6);
            *(undefined4 *)((int)local_84 + uVar17 * 4) = 0;
            iVar11 = 1;
          }
          if (*(ushort *)((int)puVar12 + 6) == local_a0) {
LAB_97beb790:
            local_a0 = 0xffffffff;
            *piVar18 = iVar11;
            uVar17 = 0xffffffff;
            piVar18 = piVar18 + 1;
            iVar11 = -1;
          }
        }
        else if ((int)(uint)*(ushort *)((int)puVar12 + 6) <= (int)local_a0) {
          *(uint *)((uint)*(ushort *)((int)puVar12 + 6) * 4 + (int)local_88) = uVar17;
          *(int *)((int)local_84 + (uint)*(ushort *)((int)puVar12 + 6) * 4) = iVar11;
          iVar11 = iVar11 + 1;
          if (*(ushort *)((int)puVar12 + 6) == local_a0) goto LAB_97beb790;
        }
      }
      iVar20 = iVar20 + 1;
      puVar12 = puVar12 + 2;
    } while (iVar20 < (int)uVar9);
  }
  iVar20 = 0;
  local_90 = 0;
  if (0 < (int)uVar9) {
    do {
      iVar11 = iVar20 * 8;
      uVar17 = puVar19[iVar20 * 2] >> 0x10 & 0x1f;
      if (uVar17 == 0) goto LAB_97bed4a8;
      iVar21 = *(int *)((int)local_84 + (uint)*(ushort *)((int)puVar19 + iVar11 + 6) * 4);
      if (iVar21 == -1) {
        iVar21 = 0;
        cVar5 = s_PARAM_prm_97c2db5c[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "PARAM prm"[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        iVar21 = ((int (*)())_ncpy)(local_a8,*(undefined4 *)
                                 ((int)local_88 + (uint)*(ushort *)((int)puVar19 + iVar11 + 6) * 4))
        ;
        local_a8 = local_a8 + iVar21;
        if (!bVar2) {
          uVar22 = puVar19[iVar20 * 2];
          local_a8 = (undefined1 *)
                     ((int (*)())_glpWriteSizeTypePrecision)(local_a8,uVar22 >> 0x18 & 3,0,uVar22 >> 0x1a & 7,uVar22 >> 0x1d);
        }
        iVar21 = 0;
        cVar5 = s___97c2db68[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = " = "[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
      }
      else if (iVar21 == 0) {
        local_8c = 0;
        iVar21 = 0;
        cVar5 = s_PARAM_prm_97c2db5c[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "PARAM prm"[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        iVar14 = ((int (*)())_ncpy)(local_a8,*(undefined4 *)
                                 ((int)local_88 + (uint)*(ushort *)((int)puVar19 + iVar11 + 6) * 4))
        ;
        iVar21 = 0;
        cVar5 = s___97c29860[0];
        while (cVar5 != '\0') {
          local_a8[iVar21 + iVar14] = cVar5;
          cVar5 = "["[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21 + iVar14;
        iVar14 = ((int (*)())_ncpy)(local_a8,local_78[local_90]);
        iVar21 = 0;
        cVar5 = s___97c2d770[0];
        while (cVar5 != '\0') {
          local_a8[iVar21 + iVar14] = cVar5;
          cVar5 = "]"[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        puVar13 = local_a8 + iVar21 + iVar14;
        if (!bVar2) {
          uVar22 = puVar19[iVar20 * 2];
          local_a8 = puVar13;
          puVar13 = (undefined1 *)
                    ((int (*)())_glpWriteSizeTypePrecision)(puVar13,uVar22 >> 0x18 & 3,0,uVar22 >> 0x1a & 7,uVar22 >> 0x1d);
        }
        iVar21 = 0;
        cVar5 = s_____97c2db6c[0];
        while (local_a8 = puVar13, cVar5 != '\0') {
          puVar13[iVar21] = cVar5;
          cVar5 = " = {\n    "[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
      }
      else {
        local_8c = local_8c + 1;
        iVar21 = 0;
        cVar5 = s__97c2db78[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "    "[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
      }
      if (uVar17 == 0) {
LAB_97bebb2c:
        iVar14 = 0;
        cVar5 = s_state__97c2db8c[0];
        while (cVar5 != '\0') {
          local_a8[iVar14 + iVar21] = cVar5;
          cVar5 = "state."[iVar14 + 1];
          iVar14 = iVar14 + 1;
        }
      }
      else if (uVar17 < 3) {
        iVar14 = 0;
        cVar5 = s_program__97c2db80[0];
        while (cVar5 != '\0') {
          local_a8[iVar14 + iVar21] = cVar5;
          cVar5 = "program."[iVar14 + 1];
          iVar14 = iVar14 + 1;
        }
      }
      else {
        if (uVar17 != 0x11) goto LAB_97bebb2c;
        iVar14 = 0;
        acVar6 = s__97c23d6c[0];
        while (acVar6 != '\0') {
          local_a8[iVar14 + iVar21] = acVar6;
          acVar6 = ""[iVar14];
          iVar14 = iVar14 + 1;
        }
      }
      local_a8 = local_a8 + iVar14 + iVar21;
      switch(uVar17) {
      default:
        goto switchD_97bebb8c_caseD_0;
      case 1:
        iVar21 = 0;
        cVar5 = s_local__97c2db94[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "local["[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        iVar21 = ((int (*)())_ncpy)(local_a8,puVar19[iVar20 * 2] & 0xffff);
        local_a8 = local_a8 + iVar21;
        iVar21 = 0;
        cVar5 = s___97c2d770[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "]"[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        goto LAB_97bed350;
      case 2:
        iVar21 = 0;
        cVar5 = s_env__97c2db9c[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "env["[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        iVar21 = ((int (*)())_ncpy)(local_a8,puVar19[iVar20 * 2] & 0xffff);
        local_a8 = local_a8 + iVar21;
        iVar21 = 0;
        cVar5 = s___97c2d770[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "]"[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        goto LAB_97bed350;
      case 3:
        iVar21 = 0;
        cVar5 = s_light__97c2dba4[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "light["[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        iVar14 = ((int (*)())_ncpy)(local_a8,puVar19[iVar20 * 2] & 0xff);
        iVar21 = 0;
        cVar5 = s____97c2dbac[0];
        while (cVar5 != '\0') {
          local_a8[iVar21 + iVar14] = cVar5;
          cVar5 = "]."[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21 + iVar14;
        switch(puVar19[iVar20 * 2] >> 8 & 0xf) {
        case 0:
          iVar21 = 0;
          cVar5 = s_ambient_97c2db28[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "ambient"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 1:
          iVar21 = 0;
          cVar5 = s_diffuse_97c2db30[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "diffuse"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 2:
          iVar21 = 0;
          cVar5 = s_specular_97c2db38[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "specular"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 3:
          iVar21 = 0;
          cVar5 = s_position_97c2da94[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "position"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 4:
          iVar21 = 0;
          cVar5 = s_spot_direction_97c2dbb0[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "spot.direction"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 5:
          iVar21 = 0;
          cVar5 = s_attenuation_97c2dbc0[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "attenuation"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 6:
          iVar21 = 0;
          cVar5 = s_half_97c2dbcc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "half"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 7:
          iVar21 = 0;
          cVar5 = s_spotcutoff_97c2dbd4[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "spotcutoff"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        default:
          goto switchD_97bebb8c_caseD_0;
        }
        break;
      case 4:
        iVar21 = 0;
        cVar5 = s_lightprod__97c2dbe0[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "lightprod["[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        iVar14 = ((int (*)())_ncpy)(local_a8,puVar19[iVar20 * 2] & 0xff);
        iVar21 = 0;
        cVar5 = s____97c2dbac[0];
        while (cVar5 != '\0') {
          local_a8[iVar21 + iVar14] = cVar5;
          cVar5 = "]."[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21 + iVar14;
        uVar17 = puVar19[iVar20 * 2] >> 8 & 1;
        if (uVar17 == 0) {
          iVar21 = 0;
          cVar5 = s_front__97c2db18[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "front."[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
LAB_97bec0ec:
          local_a8 = local_a8 + iVar21;
        }
        else if (uVar17 == 1) {
          iVar21 = 0;
          cVar5 = s_back__97c2db20[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "back."[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          goto LAB_97bec0ec;
        }
        uVar17 = puVar19[iVar20 * 2] >> 9 & 3;
        if (uVar17 == 1) {
          iVar21 = 0;
          cVar5 = s_diffuse_97c2db30[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "diffuse"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        }
        if (uVar17 < 2) {
          if (uVar17 == 0) {
            iVar21 = 0;
            cVar5 = s_ambient_97c2db28[0];
            while (cVar5 != '\0') {
              local_a8[iVar21] = cVar5;
              cVar5 = "ambient"[iVar21 + 1];
              iVar21 = iVar21 + 1;
            }
            break;
          }
        }
        else if (uVar17 == 2) {
          iVar21 = 0;
          cVar5 = s_specular_97c2db38[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "specular"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        }
        goto switchD_97bebb8c_caseD_0;
      case 5:
        if ((puVar19[iVar20 * 2] >> 1 & 7) == 5) {
          iVar21 = 0;
          cVar5 = s_lightmodel__97c2dc00[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "lightmodel."[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
        }
        else {
          iVar21 = 0;
          cVar5 = s_material__97c2db0c[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "material."[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
        }
        local_a8 = local_a8 + iVar21;
        if ((puVar19[iVar20 * 2] & 1) == 0) {
          iVar21 = 0;
          cVar5 = s_front__97c2db18[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "front."[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
LAB_97bec314:
          local_a8 = local_a8 + iVar21;
        }
        else if ((puVar19[iVar20 * 2] & 1) == 1) {
          iVar21 = 0;
          cVar5 = s_back__97c2db20[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "back."[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          goto LAB_97bec314;
        }
        switch(puVar19[iVar20 * 2] >> 1 & 7) {
        case 0:
          iVar21 = 0;
          cVar5 = s_ambient_97c2db28[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "ambient"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 1:
          iVar21 = 0;
          cVar5 = s_diffuse_97c2db30[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "diffuse"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 2:
          iVar21 = 0;
          cVar5 = s_specular_97c2db38[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "specular"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 3:
          iVar21 = 0;
          cVar5 = s_emission_97c2db44[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "emission"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 4:
          iVar21 = 0;
          cVar5 = s_shininess_97c2db50[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "shininess"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 5:
          iVar21 = 0;
          cVar5 = s_scenecolor_97c2dc0c[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "scenecolor"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        default:
          goto switchD_97bebb8c_caseD_0;
        }
        break;
      case 6:
        iVar21 = 0;
        cVar5 = s_lightmodel_ambient_97c2dbec[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "lightmodel.ambient"[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        break;
      case 7:
        iVar21 = 0;
        cVar5 = s_texgen__97c2dc18[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "texgen["[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        iVar14 = ((int (*)())_ncpy)(local_a8,puVar19[iVar20 * 2] & 0x1f);
        iVar21 = 0;
        cVar5 = s___eye__97c2dc20[0];
        while (cVar5 != '\0') {
          local_a8[iVar21 + iVar14] = cVar5;
          cVar5 = "].eye."[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21 + iVar14;
        uVar17 = puVar19[iVar20 * 2] >> 5 & 7;
        if (uVar17 == 1) {
          iVar21 = 0;
          cVar5 = s_t_97c2dc2c[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "t"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
        }
        else if (uVar17 < 2) {
          if (uVar17 != 0) goto switchD_97bebb8c_caseD_0;
          iVar21 = 0;
          cVar5 = s_s_97c2dc28[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "s"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
        }
        else if (uVar17 == 2) {
          iVar21 = 0;
          cVar5 = s_r_97c2dc30[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "r"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
        }
        else {
          if (uVar17 != 3) goto switchD_97bebb8c_caseD_0;
          iVar21 = 0;
          cVar5 = s_q_97c2dc34[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "q"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
        }
        break;
      case 8:
        iVar21 = 0;
        cVar5 = s_texgen__97c2dc18[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "texgen["[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        iVar14 = ((int (*)())_ncpy)(local_a8,puVar19[iVar20 * 2] & 0x1f);
        iVar21 = 0;
        cVar5 = s___object__97c2dc38[0];
        while (cVar5 != '\0') {
          local_a8[iVar21 + iVar14] = cVar5;
          cVar5 = "].object."[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21 + iVar14;
        uVar17 = puVar19[iVar20 * 2] >> 5 & 7;
        if (uVar17 == 1) {
          iVar21 = 0;
          cVar5 = s_t_97c2dc2c[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "t"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
        }
        else if (uVar17 < 2) {
          if (uVar17 != 0) goto switchD_97bebb8c_caseD_0;
          iVar21 = 0;
          cVar5 = s_s_97c2dc28[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "s"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
        }
        else if (uVar17 == 2) {
          iVar21 = 0;
          cVar5 = s_r_97c2dc30[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "r"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
        }
        else {
          if (uVar17 != 3) goto switchD_97bebb8c_caseD_0;
          iVar21 = 0;
          cVar5 = s_q_97c2dc34[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "q"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
        }
        break;
      case 9:
        iVar21 = 0;
        cVar5 = s_texenv__97c2dc44[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "texenv["[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        iVar21 = ((int (*)())_ncpy)(local_a8,puVar19[iVar20 * 2] & 0x1f);
        local_a8 = local_a8 + iVar21;
        iVar21 = 0;
        cVar5 = s___color_97c2dc4c[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "].color"[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        goto LAB_97bed350;
      case 10:
        iVar21 = 0;
        cVar5 = s_clip__97c2dc54[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "clip["[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        iVar21 = ((int (*)())_ncpy)(local_a8,puVar19[iVar20 * 2] & 0xff);
        local_a8 = local_a8 + iVar21;
        iVar21 = 0;
        cVar5 = s___plane_97c2dc5c[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "].plane"[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        goto LAB_97bed350;
      case 0xb:
        iVar21 = 0;
        cVar5 = s_fog_color_97c2dc64[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "fog.color"[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        break;
      case 0xc:
        iVar21 = 0;
        cVar5 = s_fog_params_97c2dc70[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "fog.params"[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        break;
      case 0xd:
        iVar21 = 0;
        cVar5 = s_point_size_97c2dc88[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "point.size"[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        break;
      case 0xe:
        iVar21 = 0;
        cVar5 = s_point_attenuation_97c2dc94[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "point.attenuation"[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        break;
      case 0xf:
        iVar21 = 0;
        cVar5 = s_depth_range_97c2dc7c[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "depth.range"[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        break;
      case 0x10:
        iVar21 = 0;
        cVar5 = s_matrix__97c2dca8[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "matrix."[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        switch(puVar19[iVar20 * 2] >> 8 & 7) {
        case 0:
          iVar21 = 0;
          cVar5 = s_mvp__97c2dcbc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "mvp."[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          goto LAB_97becb60;
        case 1:
          iVar21 = 0;
          cVar5 = s_projection__97c2dcb0[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "projection."[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
LAB_97becb60:
          local_a8 = local_a8 + iVar21;
          goto switchD_97becad4_default;
        case 2:
          iVar21 = 0;
          cVar5 = s_color__97c2dcc4[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "color["[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          local_a8 = local_a8 + iVar21;
          iVar21 = ((int (*)())_ncpy)(local_a8,puVar19[iVar20 * 2] & 0xff);
          local_a8 = local_a8 + iVar21;
          iVar21 = 0;
          cVar5 = s____97c2dbac[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "]."[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 3:
          iVar21 = 0;
          cVar5 = s_modelview__97c2dccc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "modelview["[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          local_a8 = local_a8 + iVar21;
          iVar21 = ((int (*)())_ncpy)(local_a8,puVar19[iVar20 * 2] & 0xff);
          local_a8 = local_a8 + iVar21;
          iVar21 = 0;
          cVar5 = s____97c2dbac[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "]."[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 4:
          iVar21 = 0;
          cVar5 = s_texture__97c2d814[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "texture["[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          local_a8 = local_a8 + iVar21;
          iVar21 = ((int (*)())_ncpy)(local_a8,puVar19[iVar20 * 2] & 0xff);
          local_a8 = local_a8 + iVar21;
          iVar21 = 0;
          cVar5 = s____97c2dbac[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "]."[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 5:
          iVar21 = 0;
          cVar5 = s_program__97c2dcd8[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "program["[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          local_a8 = local_a8 + iVar21;
          iVar21 = ((int (*)())_ncpy)(local_a8,puVar19[iVar20 * 2] & 0xff);
          local_a8 = local_a8 + iVar21;
          iVar21 = 0;
          cVar5 = s____97c2dbac[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "]."[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        default:
          goto switchD_97becad4_default;
        }
        local_a8 = local_a8 + iVar21;
switchD_97becad4_default:
        uVar17 = puVar19[iVar20 * 2] >> 0xe & 3;
        if (uVar17 == 1) {
          iVar21 = 0;
          cVar5 = s_transpose__97c2dce4[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "transpose."[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
LAB_97becea0:
          local_a8 = local_a8 + iVar21;
        }
        else if (1 < uVar17) {
          if (uVar17 == 2) {
            iVar21 = 0;
            cVar5 = s_inverse__97c2dcf0[0];
            while (cVar5 != '\0') {
              local_a8[iVar21] = cVar5;
              cVar5 = "inverse."[iVar21 + 1];
              iVar21 = iVar21 + 1;
            }
          }
          else {
            if (uVar17 != 3) goto LAB_97becea8;
            iVar21 = 0;
            cVar5 = s_invtrans__97c2dcfc[0];
            while (cVar5 != '\0') {
              local_a8[iVar21] = cVar5;
              cVar5 = "invtrans."[iVar21 + 1];
              iVar21 = iVar21 + 1;
            }
          }
          goto LAB_97becea0;
        }
LAB_97becea8:
        iVar21 = 0;
        cVar5 = s_row__97c2dd08[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "row["[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        iVar21 = ((int (*)())_ncpy)(local_a8,puVar19[iVar20 * 2] >> 0xc & 3);
        local_a8 = local_a8 + iVar21;
        iVar21 = 0;
        cVar5 = s___97c2d770[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "]"[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
LAB_97bed350:
        local_a8 = local_a8 + iVar21;
        goto switchD_97bebb8c_caseD_0;
      case 0x11:
        pfVar24 = (float *)(param_1 + param_1[0x1b] * 2 + (puVar19[iVar20 * 2] & 0xffff) * 4);
        switch(puVar19[iVar20 * 2] >> 0x1a & 7) {
        case 0:
        case 1:
          iVar21 = 0;
          cVar5 = s___97c2dd10[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "{"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          local_a8 = local_a8 + iVar21;
          uVar26 = ((char * (*)())_glp_dtostr)((double)*pfVar24,DOUBLE_97c30a70);
          iVar14 = (int)((ulonglong)uVar26 >> 0x20);
          iVar21 = 0;
          cVar5 = s___97c2d7ec[0];
          while (cVar5 != '\0') {
            *(char *)(iVar14 + iVar21) = cVar5;
            cVar5 = ", "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          local_a8 = (undefined1 *)(iVar14 + iVar21);
          uVar26 = ((char * (*)())_glp_dtostr)((double)pfVar24[1],DOUBLE_97c30a70,iVar14,(int)uVar26,local_a8,
                               (int)local_ac + (local_b0 - (int)local_a8));
          iVar14 = (int)((ulonglong)uVar26 >> 0x20);
          iVar21 = 0;
          cVar5 = s___97c2d7ec[0];
          while (cVar5 != '\0') {
            *(char *)(iVar14 + iVar21) = cVar5;
            cVar5 = ", "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          local_a8 = (undefined1 *)(iVar14 + iVar21);
          uVar26 = ((char * (*)())_glp_dtostr)((double)pfVar24[2],DOUBLE_97c30a70,iVar14,(int)uVar26,local_a8,
                               (int)local_ac + (local_b0 - (int)local_a8));
          iVar14 = (int)((ulonglong)uVar26 >> 0x20);
          iVar21 = 0;
          cVar5 = s___97c2d7ec[0];
          while (cVar5 != '\0') {
            *(char *)(iVar14 + iVar21) = cVar5;
            cVar5 = ", "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          local_a8 = (undefined1 *)(iVar14 + iVar21);
          local_a8 = (undefined1 *)
                     ((char * (*)())_glp_dtostr)((double)pfVar24[3],DOUBLE_97c30a70,iVar14,(int)uVar26,local_a8,
                                 (int)local_ac + (local_b0 - (int)local_a8));
          iVar21 = 0;
          cVar5 = s___97c2dd14[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "}"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 2:
          iVar21 = 0;
          cVar5 = s_____Fixed_constant_data_not_curr_97c2dd18[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "{-- Fixed constant data not currently supported --}"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 3:
        case 4:
          iVar21 = 0;
          cVar5 = s___97c2dd10[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "{"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          local_a8 = local_a8 + iVar21;
          iVar14 = ((int (*)())_ncpy)(local_a8,*pfVar24);
          iVar21 = 0;
          cVar5 = s___97c2d7ec[0];
          while (cVar5 != '\0') {
            local_a8[iVar21 + iVar14] = cVar5;
            cVar5 = ", "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          local_a8 = local_a8 + iVar21 + iVar14;
          iVar14 = ((int (*)())_ncpy)(local_a8,pfVar24[1]);
          iVar21 = 0;
          cVar5 = s___97c2d7ec[0];
          while (cVar5 != '\0') {
            local_a8[iVar21 + iVar14] = cVar5;
            cVar5 = ", "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          local_a8 = local_a8 + iVar21 + iVar14;
          iVar14 = ((int (*)())_ncpy)(local_a8,pfVar24[2]);
          iVar21 = 0;
          cVar5 = s___97c2d7ec[0];
          while (cVar5 != '\0') {
            local_a8[iVar21 + iVar14] = cVar5;
            cVar5 = ", "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          local_a8 = local_a8 + iVar21 + iVar14;
          iVar21 = ((int (*)())_ncpy)(local_a8,pfVar24[3]);
          local_a8 = local_a8 + iVar21;
          iVar21 = 0;
          cVar5 = s___97c2dd14[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "}"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          goto LAB_97bed350;
        default:
          goto switchD_97bebb8c_caseD_0;
        }
        break;
      case 0x12:
        iVar21 = 0;
        cVar5 = s_normalscale_97c2dd4c[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "normalscale"[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
      }
      local_a8 = local_a8 + iVar21;
switchD_97bebb8c_caseD_0:
      if (*(int *)((int)local_84 + (uint)*(ushort *)((int)puVar19 + iVar11 + 6) * 4) == -1) {
        iVar11 = 0;
        cVar5 = s___97c2d8f8[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = ";\n"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
      }
      else if (local_8c + 1 == local_78[local_90]) {
        local_90 = local_90 + 1;
        iVar11 = 0;
        cVar5 = s____97c2dd58[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "\n};\n"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
      }
      else {
        iVar11 = 0;
        cVar5 = s___97c2dd60[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = ",\n"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
      }
      local_a8 = local_a8 + iVar11;
      iVar11 = ((int (*)())_adjustAllocation)(&local_b0,&local_ac,&local_a8);
      bVar1 = bVar3;
      if (iVar11 == 0) goto joined_r0x97beb668;
LAB_97bed4a8:
      iVar20 = iVar20 + 1;
    } while (iVar20 < (int)uVar9);
  }
  if (local_78 != (int *)0x0) {
    _free(local_78);
  }
  iVar20 = 0;
  cVar5 = s__97c26c38[0];
  while (cVar5 != '\0') {
    local_a8[iVar20] = cVar5;
    cVar5 = "\n"[iVar20 + 1];
    iVar20 = iVar20 + 1;
  }
  local_a8 = local_a8 + iVar20;
LAB_97bed528:
  uVar17 = param_1[0xc];
  iVar20 = 0;
  uVar9 = param_1[0xd];
  bVar1 = bVar3;
  if (0 < (int)uVar17) {
    do {
      uVar22 = param_1[uVar9 * 2 + iVar20 * 2] >> 0x10 & 0xf;
      if (uVar22 == 0) goto LAB_97bedcb4;
      uVar25 = param_1[uVar9 * 2 + iVar20 * 2] >> 0x1d;
      if (uVar25 == 1) {
        iVar11 = 0;
        cVar5 = s_LONG_OUTPUT_res_97c2dd70[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "LONG OUTPUT res"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
LAB_97bed644:
        local_a8 = local_a8 + iVar11;
      }
      else if (uVar25 < 2) {
        if (uVar25 == 0) {
          iVar11 = 0;
          cVar5 = s_OUTPUT_res_97c2dd64[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = "OUTPUT res"[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          goto LAB_97bed644;
        }
      }
      else if (uVar25 == 2) {
        iVar11 = 0;
        cVar5 = s_SHORT_OUTPUT_res_97c2dd80[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "SHORT OUTPUT res"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        goto LAB_97bed644;
      }
      iVar11 = ((int (*)())_ncpy)(local_a8,*(undefined2 *)((int)param_1 + iVar20 * 8 + uVar9 * 8 + 6));
      local_a8 = local_a8 + iVar11;
      if (!bVar2) {
        uVar25 = param_1[uVar9 * 2 + iVar20 * 2];
        local_a8 = (undefined1 *)
                   ((int (*)())_glpWriteSizeTypePrecision)(local_a8,uVar25 >> 0x18 & 3,0,uVar25 >> 0x1a & 7,uVar25 >> 0x1d);
      }
      iVar11 = 0;
      cVar5 = s___97c2db68[0];
      while (cVar5 != '\0') {
        local_a8[iVar11] = cVar5;
        cVar5 = " = "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      local_a8 = local_a8 + iVar11;
      switch(uVar22) {
      default:
        goto switchD_97bed6f4_caseD_0;
      case 1:
        iVar11 = 0;
        cVar5 = s_result_position_97c2dd94[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "result.position"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      case 2:
        iVar11 = 0;
        cVar5 = s_result_fogcoord_97c2dda4[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "result.fogcoord"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      case 3:
        iVar11 = 0;
        cVar5 = s_result_pointsize_97c2ddb4[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "result.pointsize"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      case 4:
        iVar11 = 0;
        cVar5 = s_result_color_97c2ddc8[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "result.color"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        local_a8 = local_a8 + iVar11;
        if ((uVar16 == 0x8620) || (uVar16 == 0x8b31)) {
          if ((param_1[uVar9 * 2 + iVar20 * 2] & 1) == 0) {
            iVar11 = 0;
            cVar5 = s__front_primary_97c2ddd8[0];
            while (cVar5 != '\0') {
              local_a8[iVar11] = cVar5;
              cVar5 = ".front.primary"[iVar11 + 1];
              iVar11 = iVar11 + 1;
            }
          }
          else {
            if ((param_1[uVar9 * 2 + iVar20 * 2] & 1) != 1) goto switchD_97bed6f4_caseD_0;
            iVar11 = 0;
            cVar5 = s__back_primary_97c2dde8[0];
            while (cVar5 != '\0') {
              local_a8[iVar11] = cVar5;
              cVar5 = ".back.primary"[iVar11 + 1];
              iVar11 = iVar11 + 1;
            }
          }
          break;
        }
        if (((uVar16 == 0x8804) || (uVar16 == 0x8b30)) &&
           (1 < (param_1[uVar9 * 2 + iVar20 * 2] >> 1 & 7))) {
          iVar11 = 0;
          cVar5 = s___97c29860[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = "["[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          local_a8 = local_a8 + iVar11;
          iVar21 = ((int (*)())_ncpy)(local_a8,param_1[uVar9 * 2 + iVar20 * 2] >> 1 & 7);
          iVar11 = 0;
          cVar5 = s___97c2d770[0];
          while (cVar5 != '\0') {
            local_a8[iVar11 + iVar21] = cVar5;
            cVar5 = "]"[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          local_a8 = local_a8 + iVar11 + iVar21;
        }
        goto switchD_97bed6f4_caseD_0;
      case 5:
        iVar11 = 0;
        cVar5 = s_result_color_97c2ddc8[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "result.color"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        local_a8 = local_a8 + iVar11;
        if ((uVar16 == 0x8620) || (uVar16 == 0x8b31)) {
          if ((param_1[uVar9 * 2 + iVar20 * 2] & 1) == 0) {
            iVar11 = 0;
            cVar5 = s__front_secondary_97c2ddf8[0];
            while (cVar5 != '\0') {
              local_a8[iVar11] = cVar5;
              cVar5 = ".front.secondary"[iVar11 + 1];
              iVar11 = iVar11 + 1;
            }
          }
          else {
            if ((param_1[uVar9 * 2 + iVar20 * 2] & 1) != 1) goto switchD_97bed6f4_caseD_0;
            iVar11 = 0;
            cVar5 = s__back_secondary_97c2de0c[0];
            while (cVar5 != '\0') {
              local_a8[iVar11] = cVar5;
              cVar5 = ".back.secondary"[iVar11 + 1];
              iVar11 = iVar11 + 1;
            }
          }
          break;
        }
        goto switchD_97bed6f4_caseD_0;
      case 6:
        iVar11 = 0;
        cVar5 = s_result_texcoord__97c2de1c[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "result.texcoord["[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        local_a8 = local_a8 + iVar11;
        iVar11 = ((int (*)())_ncpy)(local_a8,param_1[uVar9 * 2 + iVar20 * 2] & 0x1f);
        local_a8 = local_a8 + iVar11;
        iVar11 = 0;
        cVar5 = s___97c2d770[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "]"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      case 7:
        iVar11 = 0;
        cVar5 = s_result_depth_97c2de30[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "result.depth"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      case 8:
        iVar11 = 0;
        cVar5 = s_result_eyePosition_97c2de50[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "result.eyePosition"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      case 9:
        iVar11 = 0;
        cVar5 = s_result_clipVertex_97c2de64[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "result.clipVertex"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      case 10:
        iVar11 = 0;
        cVar5 = s_result_attrib__97c2de40[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "result.attrib["[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        local_a8 = local_a8 + iVar11;
        iVar11 = ((int (*)())_ncpy)(local_a8,param_1[uVar9 * 2 + iVar20 * 2] & 0x1f);
        local_a8 = local_a8 + iVar11;
        iVar11 = 0;
        cVar5 = s___97c2d770[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "]"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
      }
      local_a8 = local_a8 + iVar11;
switchD_97bed6f4_caseD_0:
      iVar11 = 0;
      cVar5 = s___97c2d8f8[0];
      while (cVar5 != '\0') {
        local_a8[iVar11] = cVar5;
        cVar5 = ";\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      local_a8 = local_a8 + iVar11;
      iVar11 = ((int (*)())_adjustAllocation)(&local_b0,&local_ac,&local_a8);
      if (iVar11 == 0) goto joined_r0x97beb668;
LAB_97bedcb4:
      iVar20 = iVar20 + 1;
    } while (iVar20 < (int)uVar17);
  }
  if ((uVar17 != 0) || (bVar2)) {
    iVar20 = 0;
    cVar5 = s__97c26c38[0];
    while (cVar5 != '\0') {
      local_a8[iVar20] = cVar5;
      cVar5 = "\n"[iVar20 + 1];
      iVar20 = iVar20 + 1;
    }
    local_a8 = local_a8 + iVar20;
  }
  uVar17 = param_1[0x14];
  iVar20 = 0;
  uVar9 = param_1[0x15];
  uVar16 = uVar17;
  if (0 < (int)uVar17) {
    do {
      if ((param_1[uVar9 * 2 + iVar20 * 2] >> 0x12 & 0xff) - 0x4b < 2) {
        local_6c = local_6c + 1;
      }
      iVar20 = iVar20 + (param_1[uVar9 * 2 + iVar20 * 2] >> 0x1d) + 2;
      uVar16 = uVar16 - 1;
    } while (uVar16 != 0);
  }
  bVar4 = local_6c == 0;
  if (!bVar4) {
    sVar23 = local_6c << 2;
    iVar20 = 0;
    iVar11 = 0;
    local_74 = _malloc(sVar23);
    _memset(local_74,0,local_6c);
    local_70 = _malloc(sVar23);
    _memset(local_70,0,local_6c);
    local_6c = 0;
    bVar4 = true;
    if (0 < (int)uVar17) {
      do {
        uVar16 = param_1[uVar9 * 2 + iVar11 * 2];
        if ((uVar16 >> 0x12 & 0xff) - 0x4b < 2) {
          local_6c = ((int (*)())_InsertLabel)(local_74,local_70,param_1[uVar9 * 2 + iVar11 * 2 + 1] & 0x3ffff,
                                  uVar16 & 0x3ffff,local_6c);
          uVar16 = param_1[uVar9 * 2 + iVar11 * 2];
        }
        iVar20 = iVar20 + 1;
        iVar11 = iVar11 + (uVar16 >> 0x1d) + 2;
        bVar4 = local_6c == 0;
      } while (iVar20 < (int)uVar17);
    }
  }
  iVar20 = 0;
  iVar11 = 0;
  if (0 < (int)uVar17) {
    puVar19 = (uint *)(local_68 * 4 + (int)local_74);
    do {
      if (((param_1[uVar9 * 2 + iVar11 * 2] & 0x3ffff) == 0) && (!bVar2)) {
        iVar21 = 0;
        cVar5 = s_main__97c2de78[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "main:\n"[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
      }
      if (((!bVar4) && (local_68 < (int)local_6c)) &&
         ((param_1[uVar9 * 2 + iVar11 * 2] & 0x3ffff) == *puVar19)) {
        iVar21 = 0;
        local_9c = local_9c + -1;
        if (0 < local_9c) {
          do {
            iVar14 = 0;
            cVar5 = s__97c28c28[0];
            while (cVar5 != '\0') {
              local_a8[iVar14] = cVar5;
              cVar5 = "  "[iVar14 + 1];
              iVar14 = iVar14 + 1;
            }
            iVar21 = iVar21 + 1;
            local_a8 = local_a8 + iVar14;
          } while (iVar21 < local_9c);
        }
        iVar21 = 0;
        cVar5 = s_label__97c2de80[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "label_"[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        iVar14 = ((int (*)())_ncpy)(local_a8,local_68);
        local_68 = local_68 + 1;
        puVar19 = puVar19 + 1;
        iVar21 = 0;
        cVar5 = s___97c2de88[0];
        while (cVar5 != '\0') {
          local_a8[iVar21 + iVar14] = cVar5;
          cVar5 = ":\n"[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21 + iVar14;
        local_9c = local_9c + 1;
      }
      uVar16 = param_1[uVar9 * 2 + iVar11 * 2] >> 0x12 & 0xff;
      if (((uVar16 == 0x6b) || (uVar16 == 0x58)) ||
         ((uVar16 == 0x59 || ((uVar16 == 0x5a || (uVar16 == 0x5b)))))) {
        local_9c = local_9c + -1;
      }
      ((int (*)())_glpDisassemble1Op)(param_1 + uVar9 * 2 + iVar11 * 2,local_a8,&local_98,&local_94,local_88,
                         local_84,local_80,local_7c);
      local_a8 = local_a8 + local_94;
      iVar11 = iVar11 + local_98;
      iVar21 = ((int (*)())_adjustAllocation)(&local_b0,&local_ac,&local_a8);
      if (iVar21 == 0) {
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
        pvVar15 = local_70;
        goto LAB_97bee10c;
      }
      iVar20 = iVar20 + 1;
      iVar11 = iVar11 + 1;
    } while (iVar20 < (int)uVar17);
  }
  if (!bVar4) {
    if ((local_68 < (int)local_6c) && (iVar20 + 1 == *(int *)((int)local_74 + local_68 * 4))) {
      iVar20 = 0;
      cVar5 = s_label__97c2de8c[0];
      while (cVar5 != '\0') {
        local_a8[iVar20] = cVar5;
        cVar5 = "  label_"[iVar20 + 1];
        iVar20 = iVar20 + 1;
      }
      local_a8 = local_a8 + iVar20;
      iVar11 = ((int (*)())_ncpy)(local_a8,local_68);
      iVar20 = 0;
      cVar5 = s___97c2de88[0];
      while (cVar5 != '\0') {
        local_a8[iVar20 + iVar11] = cVar5;
        cVar5 = ":\n"[iVar20 + 1];
        iVar20 = iVar20 + 1;
      }
      local_a8 = local_a8 + iVar20 + iVar11;
    }
    _free(local_74);
    _free(local_70);
  }
  iVar20 = 0;
  cVar5 = s_END_97c2de98[0];
  while (cVar5 != '\0') {
    local_a8[iVar20] = cVar5;
    cVar5 = "END\n"[iVar20 + 1];
    iVar20 = iVar20 + 1;
  }
  uVar9 = param_1[0x18];
  iVar11 = 0;
  uVar16 = param_1[0x19];
  local_a8 = local_a8 + iVar20;
  iVar20 = 0;
  if (0 < (int)uVar9) {
    local_60 = "o intialize the Preprocessor";
    do {
      uVar17 = param_1[uVar16 * 2 + iVar20 * 2];
      iVar21 = 0;
      cVar5 = s_STATE_97c2dea0[0];
      while (cVar5 != '\0') {
        local_a8[iVar21] = cVar5;
        cVar5 = "STATE "[iVar21 + 1];
        iVar21 = iVar21 + 1;
      }
      local_a8 = local_a8 + iVar21;
      switch(uVar17 >> 0x18 & 7) {
      case 0:
        iVar21 = 0;
        cVar5 = s_ALPHA_TEST_97c2dea8[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "ALPHA_TEST "[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        switch(param_1[uVar16 * 2 + iVar20 * 2] & 7) {
        case 0:
          iVar14 = 0;
          cVar5 = s_PP_NEVER_97c2deb4[0];
          while (cVar5 != '\0') {
            local_a8[iVar14 + iVar21] = cVar5;
            cVar5 = "PP_NEVER "[iVar14 + 1];
            iVar14 = iVar14 + 1;
          }
          break;
        case 1:
          iVar14 = 0;
          cVar5 = s_PP_LESS_97c2dec0[0];
          while (cVar5 != '\0') {
            local_a8[iVar14 + iVar21] = cVar5;
            cVar5 = "PP_LESS "[iVar14 + 1];
            iVar14 = iVar14 + 1;
          }
          break;
        case 2:
          iVar14 = 0;
          cVar5 = s_PP_EQUAL_97c2decc[0];
          while (cVar5 != '\0') {
            local_a8[iVar14 + iVar21] = cVar5;
            cVar5 = "PP_EQUAL "[iVar14 + 1];
            iVar14 = iVar14 + 1;
          }
          break;
        case 3:
          iVar14 = 0;
          cVar5 = s_PP_LEQUAL_97c2ded8[0];
          while (cVar5 != '\0') {
            local_a8[iVar14 + iVar21] = cVar5;
            cVar5 = "PP_LEQUAL "[iVar14 + 1];
            iVar14 = iVar14 + 1;
          }
          break;
        case 4:
          iVar14 = 0;
          cVar5 = s_PP_GREATER_97c2dee4[0];
          while (cVar5 != '\0') {
            local_a8[iVar14 + iVar21] = cVar5;
            cVar5 = "PP_GREATER "[iVar14 + 1];
            iVar14 = iVar14 + 1;
          }
          break;
        case 5:
          iVar14 = 0;
          cVar5 = s_PP_NOTEQUAL_97c2def0[0];
          while (cVar5 != '\0') {
            local_a8[iVar14 + iVar21] = cVar5;
            cVar5 = "PP_NOTEQUAL "[iVar14 + 1];
            iVar14 = iVar14 + 1;
          }
          break;
        case 6:
          iVar14 = 0;
          cVar5 = s_PP_GEQUAL_97c2df00[0];
          while (cVar5 != '\0') {
            local_a8[iVar14 + iVar21] = cVar5;
            cVar5 = "PP_GEQUAL "[iVar14 + 1];
            iVar14 = iVar14 + 1;
          }
          break;
        default:
          iVar14 = 0;
          cVar5 = s_PP_ALWAYS_97c2df0c[0];
          while (cVar5 != '\0') {
            local_a8[iVar14 + iVar21] = cVar5;
            cVar5 = "PP_ALWAYS "[iVar14 + 1];
            iVar14 = iVar14 + 1;
          }
        }
        iVar8 = 0;
        cVar5 = s_ref__97c2df18[0];
        while (cVar5 != '\0') {
          local_a8[iVar8 + iVar14 + iVar21] = cVar5;
          cVar5 = "ref="[iVar8 + 1];
          iVar8 = iVar8 + 1;
        }
        local_a8 = local_a8 + iVar8 + iVar14 + iVar21;
        local_a8 = (undefined1 *)
                   ((char * (*)())_glp_dtostr)((double)(float)param_1[uVar16 * 2 + iVar20 * 2 + 1],DOUBLE_97c30a70);
        goto switchD_97bee2f0_default;
      case 1:
        iVar21 = 0;
        cVar5 = s_STENCIL_TEST_func__97c2df20[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "STENCIL_TEST func="[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        switch(param_1[uVar16 * 2 + iVar20 * 2] >> 0xc & 7) {
        case 0:
          iVar14 = 0;
          cVar5 = s_PP_NEVER_97c2deb4[0];
          while (cVar5 != '\0') {
            local_a8[iVar14 + iVar21] = cVar5;
            cVar5 = "PP_NEVER "[iVar14 + 1];
            iVar14 = iVar14 + 1;
          }
          break;
        case 1:
          iVar14 = 0;
          cVar5 = s_PP_LESS_97c2dec0[0];
          while (cVar5 != '\0') {
            local_a8[iVar14 + iVar21] = cVar5;
            cVar5 = "PP_LESS "[iVar14 + 1];
            iVar14 = iVar14 + 1;
          }
          break;
        case 2:
          iVar14 = 0;
          cVar5 = s_PP_EQUAL_97c2decc[0];
          while (cVar5 != '\0') {
            local_a8[iVar14 + iVar21] = cVar5;
            cVar5 = "PP_EQUAL "[iVar14 + 1];
            iVar14 = iVar14 + 1;
          }
          break;
        case 3:
          iVar14 = 0;
          cVar5 = s_PP_LEQUAL_97c2ded8[0];
          while (cVar5 != '\0') {
            local_a8[iVar14 + iVar21] = cVar5;
            cVar5 = "PP_LEQUAL "[iVar14 + 1];
            iVar14 = iVar14 + 1;
          }
          break;
        case 4:
          iVar14 = 0;
          cVar5 = s_PP_GREATER_97c2dee4[0];
          while (cVar5 != '\0') {
            local_a8[iVar14 + iVar21] = cVar5;
            cVar5 = "PP_GREATER "[iVar14 + 1];
            iVar14 = iVar14 + 1;
          }
          break;
        case 5:
          iVar14 = 0;
          cVar5 = s_PP_NOTEQUAL_97c2def0[0];
          while (cVar5 != '\0') {
            local_a8[iVar14 + iVar21] = cVar5;
            cVar5 = "PP_NOTEQUAL "[iVar14 + 1];
            iVar14 = iVar14 + 1;
          }
          break;
        case 6:
          iVar14 = 0;
          cVar5 = s_PP_GEQUAL_97c2df00[0];
          while (cVar5 != '\0') {
            local_a8[iVar14 + iVar21] = cVar5;
            cVar5 = "PP_GEQUAL "[iVar14 + 1];
            iVar14 = iVar14 + 1;
          }
          break;
        default:
          iVar14 = 0;
          cVar5 = s_PP_ALWAYS_97c2df0c[0];
          while (cVar5 != '\0') {
            local_a8[iVar14 + iVar21] = cVar5;
            cVar5 = "PP_ALWAYS "[iVar14 + 1];
            iVar14 = iVar14 + 1;
          }
        }
        iVar8 = 0;
        cVar5 = s_opfail__97c2df34[0];
        while (cVar5 != '\0') {
          local_a8[iVar8 + iVar14 + iVar21] = cVar5;
          cVar5 = "opfail="[iVar8 + 1];
          iVar8 = iVar8 + 1;
        }
        local_a8 = local_a8 + iVar8 + iVar14 + iVar21;
        switch(param_1[uVar16 * 2 + iVar20 * 2] >> 0xf & 7) {
        case 0:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_ZERO_97c2df3c[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_ZERO "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 1:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_KEEP_97c2df50[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_KEEP "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 2:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_REPLACE_97c2df64[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_REPLACE "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 3:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_INCR_97c2df78[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_INCR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 4:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_DECR_97c2df8c[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_DECR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 5:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_INVERT_97c2dfa0[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_INVERT "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 6:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_INCR_WRAP_97c2dfb4[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_INCR_WRAP "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 7:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_DECR_WRAP_97c2dfcc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_DECR_WRAP "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        default:
          goto switchD_97bee894_default;
        }
        local_a8 = local_a8 + iVar21;
switchD_97bee894_default:
        iVar21 = 0;
        cVar5 = s_opzfail__97c2dfe4[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "opzfail="[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        switch(param_1[uVar16 * 2 + iVar20 * 2] >> 0x12 & 7) {
        case 0:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_ZERO_97c2df3c[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_ZERO "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 1:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_KEEP_97c2df50[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_KEEP "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 2:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_REPLACE_97c2df64[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_REPLACE "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 3:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_INCR_97c2df78[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_INCR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 4:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_DECR_97c2df8c[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_DECR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 5:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_INVERT_97c2dfa0[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_INVERT "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 6:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_INCR_WRAP_97c2dfb4[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_INCR_WRAP "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 7:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_DECR_WRAP_97c2dfcc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_DECR_WRAP "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        default:
          goto switchD_97beeaec_default;
        }
        local_a8 = local_a8 + iVar21;
switchD_97beeaec_default:
        iVar21 = 0;
        cVar5 = s_opzpass__97c2dff0[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "opzpass="[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        switch(param_1[uVar16 * 2 + iVar20 * 2] >> 0x15 & 7) {
        case 0:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_ZERO_97c2df3c[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_ZERO "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 1:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_KEEP_97c2df50[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_KEEP "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 2:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_REPLACE_97c2df64[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_REPLACE "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 3:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_INCR_97c2df78[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_INCR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 4:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_DECR_97c2df8c[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_DECR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 5:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_INVERT_97c2dfa0[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_INVERT "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 6:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_INCR_WRAP_97c2dfb4[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_INCR_WRAP "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 7:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_DECR_WRAP_97c2dfcc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_DECR_WRAP "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        default:
          goto switchD_97beed44_default;
        }
        local_a8 = local_a8 + iVar21;
switchD_97beed44_default:
        _sprintf(&local_2b0,"ref= %#x mask = %#x ",param_1[uVar16 * 2 + iVar20 * 2 + 1] >> 0x18,
                 param_1[uVar16 * 2 + iVar20 * 2 + 1] >> 8 & 0xff);
        iVar21 = 0;
        cVar5 = local_2b0;
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = acStack_2af[iVar21];
          iVar21 = iVar21 + 1;
        }
        break;
      case 2:
        iVar21 = 0;
        cVar5 = s_DEPTH_TEST_func__97c2e014[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "DEPTH_TEST func="[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        switch(param_1[uVar16 * 2 + iVar20 * 2] & 7) {
        case 0:
          iVar21 = 0;
          cVar5 = s_PP_NEVER_97c2deb4[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_NEVER "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 1:
          iVar21 = 0;
          cVar5 = s_PP_LESS_97c2dec0[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_LESS "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 2:
          iVar21 = 0;
          cVar5 = s_PP_EQUAL_97c2decc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_EQUAL "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 3:
          iVar21 = 0;
          cVar5 = s_PP_LEQUAL_97c2ded8[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_LEQUAL "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 4:
          iVar21 = 0;
          cVar5 = s_PP_GREATER_97c2dee4[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_GREATER "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 5:
          iVar21 = 0;
          cVar5 = s_PP_NOTEQUAL_97c2def0[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_NOTEQUAL "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 6:
          iVar21 = 0;
          cVar5 = s_PP_GEQUAL_97c2df00[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_GEQUAL "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        default:
          iVar21 = 0;
          cVar5 = s_PP_ALWAYS_97c2df0c[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_ALWAYS "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
        }
        break;
      case 3:
        iVar21 = 0;
        cVar5 = s_BLENDING_alpha_equ___97c2e028[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "BLENDING \n\talpha equ = "[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        switch(param_1[uVar16 * 2 + iVar20 * 2] >> 0x13 & 7) {
        case 0:
          iVar21 = 0;
          cVar5 = s_PP_FUNC_ADD_97c2e040[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_FUNC_ADD "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 1:
          iVar21 = 0;
          cVar5 = s_PP_FUNC_SUBTRACT_97c2e050[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_FUNC_SUBTRACT "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 2:
          iVar21 = 0;
          cVar5 = s_PP_FUNC_REVERSE_SUBTRACT_97c2e064[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_FUNC_REVERSE_SUBTRACT "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 3:
          iVar21 = 0;
          cVar5 = s_PP_FUNC_MIN_97c2e080[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_FUNC_MIN "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 4:
          iVar21 = 0;
          cVar5 = s_PP_FUNC_MAX_97c2e090[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_FUNC_MAX "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        default:
          goto switchD_97bef244_default;
        }
        local_a8 = local_a8 + iVar21;
switchD_97bef244_default:
        iVar21 = 0;
        cVar5 = s_rgb_equ___97c2e0a0[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "\n\trgb equ = "[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        switch(param_1[uVar16 * 2 + iVar20 * 2] >> 0x10 & 7) {
        case 0:
          iVar21 = 0;
          cVar5 = s_PP_FUNC_ADD_97c2e040[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_FUNC_ADD "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 1:
          iVar21 = 0;
          cVar5 = s_PP_FUNC_SUBTRACT_97c2e050[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_FUNC_SUBTRACT "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 2:
          iVar21 = 0;
          cVar5 = s_PP_FUNC_REVERSE_SUBTRACT_97c2e064[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_FUNC_REVERSE_SUBTRACT "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 3:
          iVar21 = 0;
          cVar5 = s_PP_FUNC_MIN_97c2e080[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_FUNC_MIN "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 4:
          iVar21 = 0;
          cVar5 = s_PP_FUNC_MAX_97c2e090[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_FUNC_MAX "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        default:
          goto switchD_97bef3e8_default;
        }
        local_a8 = local_a8 + iVar21;
switchD_97bef3e8_default:
        iVar21 = 0;
        cVar5 = s_src___97c2e0b0[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "\n\tsrc = "[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        switch(param_1[uVar16 * 2 + iVar20 * 2] & 0xf) {
        case 0:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ZERO_97c2e0bc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ZERO "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 1:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_97c2e0cc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 2:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_SRC_COLOR_97c2e0dc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_SRC_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 3:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_SRC_COLOR_97c2e0f0[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_SRC_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 4:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_SRC_ALPHA_97c2e110[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_SRC_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 5:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_SRC_ALPHA_97c2e124[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_SRC_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 6:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_DST_ALPHA_97c2e144[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_DST_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 7:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_DST_ALPHA_97c2e158[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_DST_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 8:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_CONSTANT_COLOR_97c2e178[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_CONSTANT_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 9:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_CONSTANT_COLO_97c2e194[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_CONSTANT_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 10:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_CONSTANT_ALPHA_97c2e1b8[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_CONSTANT_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xb:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_CONSTANT_ALPH_97c2e1d4[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_CONSTANT_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xc:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_DST_COLOR_97c2e1f8[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_DST_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xd:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_DST_COLOR_97c2e20c[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_DST_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xe:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_SRC_ALPHA_SATURATE_97c2e22c[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_SRC_ALPHA_SATURATE "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        default:
          goto switchD_97bef58c_default;
        }
        local_a8 = local_a8 + iVar21;
switchD_97bef58c_default:
        iVar21 = 0;
        cVar5 = s_srcA___97c2e24c[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "\n\tsrcA = "[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        switch(param_1[uVar16 * 2 + iVar20 * 2] >> 4 & 0xf) {
        case 0:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ZERO_97c2e0bc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ZERO "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 1:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_97c2e0cc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 2:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_SRC_COLOR_97c2e0dc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_SRC_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 3:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_SRC_COLOR_97c2e0f0[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_SRC_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 4:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_SRC_ALPHA_97c2e110[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_SRC_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 5:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_SRC_ALPHA_97c2e124[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_SRC_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 6:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_DST_ALPHA_97c2e144[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_DST_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 7:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_DST_ALPHA_97c2e158[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_DST_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 8:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_CONSTANT_COLOR_97c2e178[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_CONSTANT_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 9:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_CONSTANT_COLO_97c2e194[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_CONSTANT_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 10:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_CONSTANT_ALPHA_97c2e1b8[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_CONSTANT_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xb:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_CONSTANT_ALPH_97c2e1d4[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_CONSTANT_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xc:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_DST_COLOR_97c2e1f8[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_DST_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xd:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_DST_COLOR_97c2e20c[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_DST_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xe:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_SRC_ALPHA_SATURATE_97c2e22c[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_SRC_ALPHA_SATURATE "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        default:
          goto switchD_97bef988_default;
        }
        local_a8 = local_a8 + iVar21;
switchD_97bef988_default:
        iVar21 = 0;
        cVar5 = s_dst___97c2e258[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "\n\tdst = "[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        switch(param_1[uVar16 * 2 + iVar20 * 2] >> 8 & 0xf) {
        case 0:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ZERO_97c2e0bc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ZERO "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 1:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_97c2e0cc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 2:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_SRC_COLOR_97c2e0dc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_SRC_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 3:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_SRC_COLOR_97c2e0f0[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_SRC_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 4:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_SRC_ALPHA_97c2e110[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_SRC_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 5:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_SRC_ALPHA_97c2e124[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_SRC_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 6:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_DST_ALPHA_97c2e144[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_DST_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 7:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_DST_ALPHA_97c2e158[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_DST_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 8:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_CONSTANT_COLOR_97c2e178[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_CONSTANT_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 9:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_CONSTANT_COLO_97c2e194[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_CONSTANT_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 10:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_CONSTANT_ALPHA_97c2e1b8[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_CONSTANT_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xb:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_CONSTANT_ALPH_97c2e1d4[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_CONSTANT_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xc:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_DST_COLOR_97c2e1f8[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_DST_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xd:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_DST_COLOR_97c2e20c[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_DST_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xe:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_SRC_ALPHA_SATURATE_97c2e22c[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_SRC_ALPHA_SATURATE "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        default:
          goto switchD_97befd84_default;
        }
        local_a8 = local_a8 + iVar21;
switchD_97befd84_default:
        iVar21 = 0;
        cVar5 = s_dstA___97c2e264[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "\n\tdstA = "[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        switch(param_1[uVar16 * 2 + iVar20 * 2] >> 0xc & 0xf) {
        case 0:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ZERO_97c2e0bc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ZERO "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 1:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_97c2e0cc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 2:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_SRC_COLOR_97c2e0dc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_SRC_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 3:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_SRC_COLOR_97c2e0f0[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_SRC_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 4:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_SRC_ALPHA_97c2e110[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_SRC_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 5:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_SRC_ALPHA_97c2e124[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_SRC_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 6:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_DST_ALPHA_97c2e144[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_DST_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 7:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_DST_ALPHA_97c2e158[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_DST_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 8:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_CONSTANT_COLOR_97c2e178[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_CONSTANT_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 9:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_CONSTANT_COLO_97c2e194[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_CONSTANT_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 10:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_CONSTANT_ALPHA_97c2e1b8[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_CONSTANT_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xb:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_CONSTANT_ALPH_97c2e1d4[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_CONSTANT_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xc:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_DST_COLOR_97c2e1f8[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_DST_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xd:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_DST_COLOR_97c2e20c[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_DST_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xe:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_SRC_ALPHA_SATURATE_97c2e22c[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_SRC_ALPHA_SATURATE "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        default:
          goto switchD_97bee2f0_default;
        }
        break;
      case 4:
        iVar21 = 0;
        cVar5 = s_DITHERING_ENABLED_97c2e270[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "DITHERING ENABLED"[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        break;
      case 5:
        iVar21 = 0;
        cVar5 = s_LOGIC_OP_97c2e284[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "LOGIC_OP "[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        switch(param_1[uVar16 * 2 + iVar20 * 2] & 0xf) {
        case 0:
          iVar21 = 0;
          cVar5 = s_PP_LOGIC_CLEAR_97c2e290[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_LOGIC_CLEAR"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 1:
          iVar21 = 0;
          cVar5 = s_PP_LOGIC_SET_97c2e2a0[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_LOGIC_SET"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 2:
          iVar21 = 0;
          cVar5 = s_PP_LOGIC_COPY_97c2e2b0[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_LOGIC_COPY"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 3:
          iVar21 = 0;
          cVar5 = s_PP_LOGIC_COPY_INVERTED_97c2e2c0[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_LOGIC_COPY_INVERTED"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 4:
          iVar21 = 0;
          cVar5 = s_PP_LOGIC_NOOP_97c2e2d8[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_LOGIC_NOOP"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 5:
          iVar21 = 0;
          cVar5 = s_PP_LOGIC_INVERT_97c2e2e8[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_LOGIC_INVERT"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 6:
          iVar21 = 0;
          cVar5 = s_PP_LOGIC_AND_97c2e2f8[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_LOGIC_AND"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 7:
          iVar21 = 0;
          cVar5 = s_PP_LOGIC_NAND_97c2e308[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_LOGIC_NAND"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 8:
          iVar21 = 0;
          cVar5 = s_PP_LOGIC_OR_97c2e318[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_LOGIC_OR"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 9:
          iVar21 = 0;
          cVar5 = s_PP_LOGIC_NOR_97c2e324[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_LOGIC_NOR"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 10:
          iVar21 = 0;
          cVar5 = s_PP_LOGIC_XOR_97c2e334[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_LOGIC_XOR"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xb:
          iVar21 = 0;
          cVar5 = s_PP_LOGIC_EQUIV_97c2e344[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_LOGIC_EQUIV"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xc:
          iVar21 = 0;
          cVar5 = s_PP_LOGIC_AND_REVERSE_97c2e354[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_LOGIC_AND_REVERSE"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xd:
          iVar21 = 0;
          cVar5 = s_PP_LOGIC_AND_INVERTED_97c2e36c[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_LOGIC_AND_INVERTED"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xe:
          iVar21 = 0;
          cVar5 = s_PP_LOGIC_OR_REVERSE_97c2e384[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_LOGIC_OR_REVERSE"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xf:
          iVar21 = 0;
          cVar5 = s_PP_LOGIC_OR_INVERTED_97c2e398[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_LOGIC_OR_INVERTED"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        default:
          goto switchD_97bee2f0_default;
        }
        break;
      case 6:
        iVar21 = 0;
        cVar5 = s_BUFFER_MASK_97c2e3b0[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "BUFFER_MASK "[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        if ((param_1[uVar16 * 2 + iVar20 * 2] & 0x20000) == 0) {
          iVar21 = 0;
          cVar5 = s_RED_MASKED_97c2e3c0[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "RED MASKED "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          local_a8 = local_a8 + iVar21;
        }
        if ((param_1[uVar16 * 2 + iVar20 * 2] & 0x40000) == 0) {
          iVar21 = 0;
          cVar5 = s_GREEN_MASKED_97c2e3cc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "GREEN MASKED "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          local_a8 = local_a8 + iVar21;
        }
        if ((param_1[uVar16 * 2 + iVar20 * 2] & 0x80000) == 0) {
          iVar21 = 0;
          cVar5 = s_BLUE_MASKED_97c2e3dc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "BLUE MASKED "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          local_a8 = local_a8 + iVar21;
        }
        if ((param_1[uVar16 * 2 + iVar20 * 2] & 0x100000) == 0) {
          iVar21 = 0;
          cVar5 = s_ALPHA_MASKED_97c2e3ec[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "ALPHA MASKED "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          local_a8 = local_a8 + iVar21;
        }
        if ((param_1[uVar16 * 2 + iVar20 * 2] & 0x10000) == 0) {
          iVar21 = 0;
          cVar5 = s_DEPTH_MASKED_97c2e3fc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "DEPTH MASKED "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          local_a8 = local_a8 + iVar21;
        }
        if (*(char *)((int)param_1 + iVar20 * 8 + uVar16 * 8 + 2) != -1) {
          _sprintf(local_1b0,"STENCIL MASK = %0x",param_1[uVar16 * 2 + iVar20 * 2] >> 8 & 0xff);
          iVar21 = 0;
          cVar5 = local_1b0[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            iVar21 = iVar21 + 1;
            cVar5 = local_1b0[iVar21];
          }
          break;
        }
      default:
        goto switchD_97bee2f0_default;
      }
      local_a8 = local_a8 + iVar21;
switchD_97bee2f0_default:
      iVar21 = 0;
      cVar5 = local_60[0x3bbc];
      while (cVar5 != '\0') {
        local_a8[iVar21] = cVar5;
        iVar21 = iVar21 + 1;
        cVar5 = (local_60 + 0x3bbc)[iVar21];
      }
      local_a8 = local_a8 + iVar21;
      iVar21 = ((int (*)())_adjustAllocation)(&local_b0,&local_ac,&local_a8);
      if (iVar21 == 0) goto joined_r0x97beb668;
      iVar11 = iVar11 + 1;
      iVar20 = iVar20 + 1;
    } while (iVar11 < (int)uVar9);
  }
  puVar13 = local_a8 + 1;
  *local_a8 = 0;
  local_a8 = puVar13;
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
    pvVar15 = _realloc(local_ac,(int)local_a8 - (int)local_ac);
    return pvVar15;
  }
  _free(local_ac);
  return (void *)0x0;
}

/* _handleDigit @ 0x97bf0d2c (112 bytes) */
int _handleDigit(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = param_2 / 10;
  if (iVar1 != 0) {
    ((int (*)())_handleDigit)(param_1,iVar1);
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
  
  iVar1 = _GetChunkAllocationSize();
  puVar2 = _calloc(iVar1 + 0xcU,1);
  _memset(puVar2,0,iVar1 + 0xcU);
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
  size_t sVar3;
  
  uVar1 = 1;
  if (*param_2 == *param_1) {
    switch(*param_2) {
    case '\0':
    case '\x03':
    case '\n':
      sVar3 = 0x10;
      break;
    case '\x01':
      sVar3 = 4;
      break;
    case '\x02':
    case '\x04':
    case '\x05':
    case '\x06':
    case '\a':
    case '\t':
      sVar3 = 8;
      break;
    case '\b':
      sVar3 = 0x38;
      uVar1 = *(undefined4 *)(param_1 + 0x40);
      *(undefined4 *)(param_2 + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
      *(undefined4 *)(param_2 + 0x40) = uVar1;
      break;
    default:
      return 1;
    }
    iVar2 = _memcmp(param_1 + 0xc,param_2 + 0xc,sVar3);
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
    _PPStreamChunkListAddChunk();
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
  
  puVar1 = _calloc(0x14,1);
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
  
  puVar1 = _calloc(0x10,1);
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
  
  puVar1 = _calloc(0x14,1);
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
  void *param_2;
  void *param_3;
  int param_4;
  int param_5;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined1 *puVar4;
  size_t sVar5;
  
  sVar5 = *(size_t *)((int)param_2 + 0x34);
  iVar3 = 0x38;
  if (sVar5 != 0) {
    iVar3 = sVar5 + 0x39;
  }
  puVar4 = _calloc(iVar3 + 0xc,1);
  *puVar4 = 8;
  _memcpy(puVar4 + 0xc,param_2,0x38);
  if ((sVar5 != 0) && (param_3 != (void *)0x0)) {
    _memmove(puVar4 + 0x44,param_3,sVar5);
    puVar4[sVar5 + 0x44] = 0;
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
  void *param_2;
  void *param_3;
  int param_4;
  undefined4 param_5;
{
  uint uVar1;
  int iVar2;
  undefined1 *puVar3;
  size_t sVar4;
  
  sVar4 = *(size_t *)((int)param_2 + 0x34);
  iVar2 = 0x38;
  if (sVar4 != 0) {
    iVar2 = sVar4 + 0x39;
  }
  puVar3 = _calloc(iVar2 + 0xc,1);
  *puVar3 = 8;
  _memcpy(puVar3 + 0xc,param_2,0x38);
  if ((sVar4 != 0) && (param_3 != (void *)0x0)) {
    _memmove(puVar3 + 0x44,param_3,sVar4);
    puVar3[sVar4 + 0x44] = 0;
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
  void *param_2;
  size_t param_3;
{
  undefined1 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  puVar1 = _calloc(param_3 + 0x15,1);
  uVar2 = *(undefined4 *)(param_1 + 0x20);
  *puVar1 = 0xb;
  *(size_t *)(puVar1 + 0x10) = param_3;
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
  int *piVar1;
  int iVar2;
  
  iVar2 = **(int **)(param_1 + 0x24);
  while (iVar2 != 0) {
    piVar1 = (int *)(iVar2 + 0xc);
    iVar2 = *(int *)(iVar2 + 8);
    if (*piVar1 == param_2) {
      _PPStreamChunkListRemoveChunk(*(undefined4 *)(param_1 + 0x24));
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
  
  puVar1 = _calloc(0x14,1);
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
      puVar5 = _calloc(0x10,1);
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
      puVar5 = _calloc(0x1c,1);
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
      puVar5 = _calloc(0x14,1);
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
      puVar5 = _calloc(0x1c,1);
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
      puVar5 = _calloc(0x14,1);
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
      puVar5 = _calloc(0x14,1);
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
      puVar5 = _calloc(0x14,1);
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
      puVar5 = _calloc(0x14,1);
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
      puVar5 = _calloc(0x44,1);
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
      puVar5 = _calloc(0x14,1);
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
      puVar5 = _calloc(0x1c,1);
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
  int param_3;
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
              *(undefined2 *)(iVar4 + 0x12) = param_3;
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
              *(undefined2 *)(iVar6 + 0x1a) = param_3;
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
  int param_3;
{
  if (param_1 != 0) {
    do {
      if (param_2 == *(ushort *)(param_1 + 0xe)) {
        *(undefined2 *)(param_1 + 0xe) = param_3;
      }
      if (param_2 == *(ushort *)(param_1 + 0x12)) {
        *(undefined2 *)(param_1 + 0x12) = param_3;
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
  int param_3;
{
  if (param_1 != 0) {
    do {
      if (param_2 == *(ushort *)(param_1 + 0xe)) {
        *(undefined2 *)(param_1 + 0xe) = param_3;
      }
      if (param_2 == *(ushort *)(param_1 + 0x12)) {
        *(undefined2 *)(param_1 + 0x12) = param_3;
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
      ((int (*)())_renumberTempArrayIndices)(**(undefined4 **)(param_1 + 8),*(undefined2 *)(iVar3 + 0x12),uVar2);
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
      ((int (*)())_renumberParamArrayIndices)(**(undefined4 **)(param_1 + 0x14),*(undefined2 *)(iVar3 + 0x12),uVar2);
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
  iVar2 = _PPStreamChunkListGetMaxIndex();
  if (iVar4 != 0) {
    uVar1 = *(ushort *)(iVar4 + 0x12);
    uVar3 = iVar2 + 1U;
    while ((uint)uVar1 < iVar2 + 1U) {
      if ((*(uint *)(iVar4 + 0xc) >> 0x10 & 0x1f) == 0x11) {
        ((int (*)())_PPStreamRenumberOperandIndices)(param_1,iVar4,uVar3);
        ((int (*)())_renumberParamArrayIndices)(**(undefined4 **)(param_1 + 0x14),*(undefined2 *)(iVar4 + 0x12),uVar3);
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
  size_t sVar6;
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
        iVar7 = _memcmp("main(",(void *)(iVar5 + 0x14),6);
        if (iVar7 == 0) break;
        iVar5 = *(int *)(iVar5 + 8);
      }
      iVar7 = *piVar4;
      if (iVar7 == 0) {
        return uVar2;
      }
      do {
        if (*(uint *)(iVar5 + 0xc) == (*(uint *)(iVar7 + 0xc) & 0x3ffff)) {
          *(uint *)(iVar7 + 0xc) = *(uint *)(iVar7 + 0xc) & 0xfffc0000;
          *(undefined4 *)(iVar5 + 0xc) = 0;
          return uVar2;
        }
        iVar7 = *(int *)(iVar7 + 8);
      } while (iVar7 != 0);
      return uVar2;
    }
    sVar6 = *(size_t *)(iVar5 + 0x40);
    if (sVar6 != 0) {
      *(uint *)(iVar5 + 0x10) = piVar4[2] + 1U & 0x3ffff | *(uint *)(iVar5 + 0x10) & 0xfffc0000;
      for (iVar7 = *piVar3; iVar7 != 0; iVar7 = *(int *)(iVar7 + 8)) {
        if ((sVar6 == *(size_t *)(iVar7 + 0x10)) &&
           (iVar1 = _strncmp((char *)(iVar5 + 0x44),(char *)(iVar7 + 0x14),sVar6), iVar1 == 0)) {
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

