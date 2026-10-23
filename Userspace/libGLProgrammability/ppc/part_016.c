#include "decls.h"

/* _PPCConstantsAndScratchCreate @ 0x97be56c4 (56 bytes) */
int _PPCConstantsAndScratchCreate()
{
  undefined4 allocation;
  
  allocation = _malloc(0xd80);
  ((double (*)())_PPCConstantsAndScratchInitialise)(allocation);
  return allocation;
}

/* _PPCConstantsAndScratchInitialise @ 0x97be5700 (1196 bytes) */
double _PPCConstantsAndScratchInitialise(undefined4 *constants)
{
  double log2Result;
  double extraout_f1;
  
  _memset(constants,0,0xd80);
  *constants = 0x1a;
  constants[1] = 0x1c;
  constants[2] = 0x1e;
  constants[7] = 1;
  constants[0xf] = 0xffffffff;
  constants[0x15] = 0x12;
  constants[0x14] = 0x11;
  constants[0x16] = 0x13;
  constants[0x17] = 0x10;
  constants[0x1b] = 0x437f0000;
  constants[0x18] = 0x437f0000;
  constants[0x19] = 0x437f0000;
  constants[0x1a] = 0x437f0000;
  constants[0xb] = 0xff;
  constants[0x10] = 0xf03070b;
  constants[8] = 0xff;
  constants[9] = 0xff;
  constants[10] = 0xff;
  constants[0x1c] = 0.003921569;
  constants[0x1d] = 0.003921569;
  constants[0x1e] = 0.003921569;
  constants[0x1f] = 0.003921569;
  constants[3] = 0;
  constants[4] = 0;
  constants[5] = 0;
  constants[6] = 0;
  constants[0xc] = 0;
  constants[0xd] = 0;
  constants[0xe] = 0;
  constants[0x11] = 0;
  constants[0x12] = 0;
  constants[0x13] = 0;
  constants[0x20] = 0;
  constants[0x23] = 0x41400000;
  constants[0x22] = 0x40400000;
  constants[0x25] = 0.33333334;
  constants[0x24] = 0x3f000000;
  constants[0x27] = 0.16666667;
  constants[0x26] = 0x3e800000;
  constants[0x2a] = 0.007874016;
  constants[0x28] = 0x3d800000;
  constants[0x2c] = 3.051851e-05;
  constants[0x21] = 0x3f800000;
  constants[0x2d] = 1.5259022e-05;
  constants[0x2b] = 0.003921569;
  constants[0x30] = 5e-06;
  constants[0x2e] = 0x30000000;
  constants[0x31] = 200000.0;
  constants[0x2f] = 0x2f800000;
  constants[0x32] = 1.442695;
  constants[0x29] = 0.041666668;
  constants[0x33] = -1.442695;
  constants[0x34] = 0.6931472;
  constants[0x38] = 255.996;
  constants[0x39] = 65535.996;
  constants[0x40] = 0x3f800000;
  constants[0x3b] = 0.0001;
  constants[0x3a] = 0x47800000;
  constants[0x3c] = 0.009615976;
  constants[0x3d] = -0.0013282397;
  constants[0x3e] = 0.0001474911;
  constants[0x3f] = -1.08635e-05;
  constants[0x41] = -0.6931472;
  constants[0x42] = 0.24022646;
  constants[0x43] = -0.055503644;
  constants[0x44] = 0.2418737;
  constants[0x45] = -0.1375312;
  constants[0x46] = 0.05206468;
  constants[0x47] = -0.009310494;
  constants[0x48] = 1.4426897;
  constants[0x49] = -0.7211658;
  constants[0x4a] = 0.4786848;
  constants[0x4b] = -0.34730542;
  constants[0x54] = 0xbf000000;
  constants[0x4c] = -0.16666667;
  constants[0x55] = 0.041666668;
  constants[0x4d] = 0.008333334;
  constants[0x5c] = 0xff800000;
  constants[0x4e] = -0.0001984127;
  constants[0x5d] = 0xff800000;
  constants[0x4f] = 2.7557319e-06;
  constants[0x5e] = 0xff800000;
  constants[0x50] = -2.5052108e-08;
  constants[0x51] = 1.6059044e-10;
  constants[0x52] = -7.6471636e-13;
  constants[0x53] = 2.8114571e-15;
  constants[0x56] = -0.0013888889;
  constants[0x57] = 2.4801588e-05;
  constants[0x58] = -2.755732e-07;
  constants[0x59] = 2.0876758e-09;
  constants[0x5a] = -1.1470745e-11;
  constants[0x5b] = 4.7794773e-14;
  constants[0x5f] = 0xff800000;
  constants[0x67] = 0.017453292;
  constants[0x6b] = 57.29578;
  constants[100] = 0.017453292;
  constants[0x65] = 0.017453292;
  constants[0x66] = 0.017453292;
  constants[0x68] = 57.29578;
  constants[0x69] = 57.29578;
  constants[0x6a] = 57.29578;
  constants[99] = 6.2831855;
  constants[0x60] = 6.2831855;
  constants[0x61] = 6.2831855;
  constants[0x62] = 6.2831855;
  log2Result = _log2(2.718281828459045);
  constants[0x6c] = (float)log2Result;
  log2Result = _log2(2.718281828459045);
  constants[0x6d] = (float)log2Result;
  log2Result = _log2(2.718281828459045);
  constants[0x6e] = (float)log2Result;
  log2Result = _log2(2.718281828459045);
  constants[0x6f] = (float)log2Result;
  log2Result = _log2(2.718281828459045);
  constants[0x70] = (float)(1.0 / log2Result);
  log2Result = _log2(2.718281828459045);
  constants[0x71] = (float)(1.0 / log2Result);
  log2Result = _log2(2.718281828459045);
  constants[0x72] = (float)(1.0 / log2Result);
  log2Result = _log2(2.718281828459045);
  *(undefined8 *)(constants + 0x78) = 0x4330000080000000;
  *(undefined8 *)(constants + 0x7a) = 0x4330000000000000;
  constants[0x7e] = 0x43300000;
  constants[0x7f] = 0;
  constants[0x7c] = 0x43300000;
  constants[0x7d] = 0;
  constants[0x73] = (float)(1.0 / log2Result);
  _PPCNoiseGeneratorInitialise(constants + 0xd8);
  return extraout_f1;
}

/* _PPEmulatorAttachProgram @ 0x97be5bac (8 bytes) */
int _PPEmulatorAttachProgram(emulator, programInfo)
  int emulator;
  undefined4 programInfo;
{
  *(undefined4 *)(emulator + 0xd80) = programInfo;
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
void _PPEmulatorEmulateSingleOp(int emulator,undefined4 inst,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  ((int * (*)())_InterpreterEmulateOp)(*(undefined4 *)(emulator + 0xdf0),inst,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
             fparam_6,fparam_7,fparam_8,fparam_9,fparam_10,fparam_11,fparam_12,fparam_13);
  return;
}

/* _PPEmulatorRun @ 0x97be5bec (116 bytes) */
int _PPEmulatorRun(emulator, elementCount, runnerArg3, runnerArg4, runnerArg5)
  int emulator;
  undefined4 elementCount;
  undefined4 runnerArg3;
  undefined4 runnerArg4;
  undefined4 runnerArg5;
{
  int programInfo;
  code *runEntry;
  
  programInfo = *(int *)(emulator + 0xd80);
  if (((*(int *)(programInfo + 0x38) == 0x8804) || (*(int *)(programInfo + 0x38) == 0x8b30)) &&
     ((double)*(float *)(*(int *)(emulator + 0xda0) + 0xc) != DOUBLE_97c30a60)) {
    runEntry = *(code **)(programInfo + 0xc);
  }
  else {
    runEntry = *(code **)(programInfo + 8);
  }


  /* dropped-return-value defect (class 25, issue #68) - stock does this as a real bctr tail-jump
   * (no blr afterward), so whatever the JIT/interpreter target returns in r3 IS this function's
   * real return value; verified via Capstone disasm of the real 0x97be5bec body. */
  return (*runEntry)(emulator,elementCount,runnerArg3,runnerArg4,runnerArg5,0x97be5bf8,emulator,elementCount);
}

/* _PPEmulatorBuild @ 0x97be5c60 (576 bytes) */
int _PPEmulatorBuild(emulator, elementCount, runnerArg3, runnerArg4, runnerArg5, runnerArg6)
  int emulator;
  undefined4 elementCount;
  undefined4 runnerArg3;
  undefined4 runnerArg4;
  undefined4 runnerArg5;
  undefined4 runnerArg6;
{
  bool isVertexPath;
  undefined *selectedEntry;
  int oldCodeBuffer;
  undefined4 ppcRuntimeCompilerCreateResult;
  undefined4 compiledResult;
  int isFragmentPath;
  code *runEntry;
  uint compileFlags;
  int programInfo;
  
  programInfo = *(int *)(emulator + 0xd80);
  isFragmentPath = 0;
  compileFlags = *(uint *)(programInfo + 0x124);
  if (((*(int *)(programInfo + 0x38) == 0x8804) || (*(int *)(programInfo + 0x38) == 0x8b30)) &&
     ((double)*(float *)(*(int *)(emulator + 0xda0) + 0xc) != DOUBLE_97c30a60)) {
    isFragmentPath = 1;
  }
  isVertexPath = isFragmentPath == 0;
  if (isVertexPath) {
    if (*(int *)(programInfo + 0x1c) != 0) {
      _glpDCBFree(*(int *)(programInfo + 0x1c));
    }
    oldCodeBuffer = *(int *)(programInfo + 0x14);
  }
  else {
    if (*(int *)(programInfo + 0x20) != 0) {
      _glpDCBFree(*(int *)(programInfo + 0x20));
    }
    oldCodeBuffer = *(int *)(programInfo + 0x18);
  }
  if (oldCodeBuffer != 0) {
    _glpDCBFree(oldCodeBuffer);
  }
  if ((compileFlags & 2) != 0) {
    if ((compileFlags & 8) == 0) {
      ppcRuntimeCompilerCreateResult = _PPCRuntimeCompilerCreate();
      _PPCRuntimeCompilerAttachEmulatorContext(ppcRuntimeCompilerCreateResult,emulator);
      _PPCRuntimeCompilerAttachEmulatorProgram(ppcRuntimeCompilerCreateResult,programInfo);
      if ((compileFlags & 4) != 0) {
        _PPCRuntimeCompilerSetOptionFlags(ppcRuntimeCompilerCreateResult,7);
      }
      if (isVertexPath) {
        _PPCRuntimeCompilerCompileNO(ppcRuntimeCompilerCreateResult);
        compiledResult = _PPCRuntimeCompilerGetCompiledResult(ppcRuntimeCompilerCreateResult);
        *(undefined4 *)(programInfo + 0x1c) = compiledResult;
      }
      else {
        _PPCRuntimeCompilerSetOptionFlags(ppcRuntimeCompilerCreateResult,8);
        _PPCRuntimeCompilerCompileNO(ppcRuntimeCompilerCreateResult);
        compiledResult = _PPCRuntimeCompilerGetCompiledResult(ppcRuntimeCompilerCreateResult);
        *(undefined4 *)(programInfo + 0x20) = compiledResult;
      }
      _PPCRuntimeCompilerFree(ppcRuntimeCompilerCreateResult);
    }
    if ((compileFlags & 8) != 0) {
      ppcRuntimeCompilerCreateResult = _PPCRuntimeCompilerCreate();
      _PPCRuntimeCompilerAttachEmulatorContext(ppcRuntimeCompilerCreateResult,emulator);
      _PPCRuntimeCompilerAttachEmulatorProgram(ppcRuntimeCompilerCreateResult,programInfo);
      if ((compileFlags & 4) != 0) {
        _PPCRuntimeCompilerSetOptionFlags(ppcRuntimeCompilerCreateResult,7);
      }
      if (isVertexPath) {
        _PPCRuntimeCompilerCompileAV(ppcRuntimeCompilerCreateResult);
        compiledResult = _PPCRuntimeCompilerGetCompiledResult(ppcRuntimeCompilerCreateResult);
        *(undefined4 *)(programInfo + 0x14) = compiledResult;
      }
      else {
        _PPCRuntimeCompilerSetOptionFlags(ppcRuntimeCompilerCreateResult,8);
        _PPCRuntimeCompilerCompileAV(ppcRuntimeCompilerCreateResult);
        compiledResult = _PPCRuntimeCompilerGetCompiledResult(ppcRuntimeCompilerCreateResult);
        *(undefined4 *)(programInfo + 0x18) = compiledResult;
      }
      _PPCRuntimeCompilerFree(ppcRuntimeCompilerCreateResult);
    }
  }
  selectedEntry = PTR__InterpreterRun_a7b7c104;
  *(undefined **)(programInfo + 0x10) = PTR__InterpreterRun_a7b7c104;
  if ((compileFlags & 2) == 0) {
    if (isVertexPath) goto LAB_97be5e64;
  }
  else if ((compileFlags & 8) == 0) {
    if (isVertexPath) {
      selectedEntry = *(undefined **)(programInfo + 0x1c);
      goto LAB_97be5e64;
    }
    selectedEntry = *(undefined **)(programInfo + 0x20);
  }
  else {
    if (isVertexPath) {
      selectedEntry = *(undefined **)(programInfo + 0x14);
LAB_97be5e64:
      *(undefined **)(programInfo + 8) = selectedEntry;
      goto LAB_97be5e68;
    }
    selectedEntry = *(undefined **)(programInfo + 0x18);
  }
  *(undefined **)(programInfo + 0xc) = selectedEntry;
LAB_97be5e68:
  if (isVertexPath) {
    runEntry = *(code **)(programInfo + 8);
  }
  else {
    runEntry = *(code **)(programInfo + 0xc);
  }


  /* dropped-return-value defect (class 25, issue #68) - same real bctr tail-jump shape as
   * _PPEmulatorRun above; verified via Capstone disasm of the real 0x97be5c60 body. */
  return (*runEntry)(emulator,elementCount,runnerArg3,runnerArg4,runnerArg5,runnerArg6,isFragmentPath);
}

/* _PPEmulatorRunNoop @ 0x97be5ea0 (8 bytes) */
int _PPEmulatorRunNoop()
{
  return 0;
}

/* _PPEmulatorVariableSwizzleFromMask @ 0x97be5ea8 (108 bytes) */
int _PPEmulatorVariableSwizzleFromMask(emulator, unusedArg2, unusedArg3, unusedArg4, unusedArg5, unusedArg6, unusedArg7, unusedArg8)
  int emulator;
  undefined4 unusedArg2;
  undefined4 unusedArg3;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
  undefined4 unusedArg8;
{
  byte writeMask;
  uint componentIndex;
  undefined1 *swizzleByte;
  int componentsLeft;
  
  writeMask = *(byte *)(emulator + 0x1c);
  if (writeMask == 0) {
    *(byte *)(emulator + 8) = writeMask;
    *(undefined1 *)(emulator + 0xb) = 3;
    *(undefined1 *)(emulator + 10) = 2;
    *(undefined1 *)(emulator + 9) = 1;
    return;
  }
  componentsLeft = 4;
  swizzleByte = (undefined1 *)(emulator + 8);
  componentIndex = 0;
  do {
    if (((int)(uint)writeMask >> (componentIndex & 0x3f) & 1U) == 0) {
      *swizzleByte = 0xff;
    }
    else {
      *swizzleByte = (char)componentIndex;
    }
    componentIndex = componentIndex + 1;
    swizzleByte = swizzleByte + 1;
    componentsLeft = componentsLeft + -1;
  } while (componentsLeft != 0);
  return;
}

/* _PPEmulatorVariableMaskFromSwizzle @ 0x97be5f14 (68 bytes) */
int _PPEmulatorVariableMaskFromSwizzle(emulator)
  int emulator;
{
  byte swizzleByte;
  byte *swizzleCursor;
  int componentsLeft;
  
  *(undefined1 *)(emulator + 0x1c) = 0;
  componentsLeft = 4;
  swizzleCursor = (byte *)(emulator + 8);
  do {
    swizzleByte = *swizzleCursor;
    swizzleCursor = swizzleCursor + 1;
    if (swizzleByte != 0xff) {
      *(byte *)(emulator + 0x1c) = *(byte *)(emulator + 0x1c) | (byte)(1 << (swizzleByte & 0x3f));
    }
    componentsLeft = componentsLeft + -1;
  } while (componentsLeft != 0);
  return;
}

/* _ncpy_97be5f58 @ 0x97be5f58 (144 bytes) */
int _ncpy_97be5f58(out, value)
  char *out;
  int value;
{
  int leadingValue;
  char *writeCursor [4];
  
  writeCursor[0] = out;
  if (value < 0) {
    writeCursor[0] = out + 1;
    *out = '-';
    value = -value;
  }
  leadingValue = value / 10;
  if (leadingValue != 0) {
    ((int (*)())_handleDigit_97bf0d2c)(writeCursor,leadingValue);
  }
  *writeCursor[0] = (char)value + (char)leadingValue * -10 + '0';
  return writeCursor[0] + (1 - (int)out);
}

/* _glpWriteSizeTypePrecision @ 0x97be5fe8 (676 bytes) */
int _glpWriteSizeTypePrecision(out, sizeMinusOne, isMatrix, valueType, precision)
  int out;
  int sizeMinusOne;
  int isMatrix;
  undefined4 valueType;
  int precision;
{
  int copyEnd;
  char ch;
  int copyIndex;
  int writeCursor;
  int copyEnd2;
  
  copyIndex = 0;
  ch = s___97c2a320[0];
  while (ch != '\0') {
    *(char *)(out + copyIndex) = ch;
    ch = ":"[copyIndex + 1];
    copyIndex = copyIndex + 1;
  }
  copyEnd = ((int (*)())_ncpy_97be5f58)(out + copyIndex,sizeMinusOne + 1);
  writeCursor = out + copyIndex + copyEnd;
  if (isMatrix == 1) {
    copyIndex = 0;
    ch = s___97c2a320[0];
    while (ch != '\0') {
      *(char *)(writeCursor + copyIndex) = ch;
      ch = ":"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyEnd2 = ((int (*)())_ncpy_97be5f58)(writeCursor + copyIndex,sizeMinusOne + 1);
    writeCursor = writeCursor + copyIndex + copyEnd2;
  }
  switch(valueType) {
  default:
    goto switchD_97be60c8_caseD_0;
  case 1:
    copyIndex = 0;
    ch = s_F_97c2d738[0];
    while (ch != '\0') {
      *(char *)(writeCursor + copyIndex) = ch;
      ch = "F"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    break;
  case 2:
    copyIndex = 0;
    ch = s_X_97c2d73c[0];
    while (ch != '\0') {
      *(char *)(writeCursor + copyIndex) = ch;
      ch = "X"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    break;
  case 3:
    copyIndex = 0;
    ch = s_I_97c2d740[0];
    while (ch != '\0') {
      *(char *)(writeCursor + copyIndex) = ch;
      ch = "I"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    break;
  case 4:
    copyIndex = 0;
    ch = s_B_97c2d744[0];
    while (ch != '\0') {
      *(char *)(writeCursor + copyIndex) = ch;
      ch = "B"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
  }
  writeCursor = writeCursor + copyIndex;
switchD_97be60c8_caseD_0:
  if (precision == 1) {
    copyIndex = 0;
    ch = s_32_97c2d748[0];
    while (ch != '\0') {
      *(char *)(writeCursor + copyIndex) = ch;
      ch = "32"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
  }
  else {
    if (precision < 2) {
      return writeCursor;
    }
    if (precision == 2) {
      copyIndex = 0;
      ch = s_16_97c2d74c[0];
      while (ch != '\0') {
        *(char *)(writeCursor + copyIndex) = ch;
        ch = "16"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
    }
    else {
      if (precision != 3) {
        return writeCursor;
      }
      copyIndex = 0;
      ch = s_12_97c2d750[0];
      while (ch != '\0') {
        *(char *)(writeCursor + copyIndex) = ch;
        ch = "12"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
    }
  }
  return writeCursor + copyIndex;
}

/* _glpWritePrecision @ 0x97be62a0 (224 bytes) */
int _glpWritePrecision(out, precision)
  int out;
  int precision;
{
  char ch;
  int copyIndex;
  
  if (precision == 1) {
    copyIndex = 0;
    ch = s_R_97c2d754[0];
    while (ch != '\0') {
      *(char *)(out + copyIndex) = ch;
      ch = "R"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
  }
  else {
    if (precision < 2) {
      return out;
    }
    if (precision == 2) {
      copyIndex = 0;
      ch = s_H_97c2d758[0];
      while (ch != '\0') {
        *(char *)(out + copyIndex) = ch;
        ch = "H"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
    }
    else {
      if (precision != 3) {
        return out;
      }
      copyIndex = 0;
      ch = s_X_97c2d73c[0];
      while (ch != '\0') {
        *(char *)(out + copyIndex) = ch;
        ch = "X"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
    }
  }
  return out + copyIndex;
}

/* _glpWriteOperandSize @ 0x97be6380 (236 bytes) */
int _glpWriteOperandSize(outCursor, sizeCode, repeatSize)
  int outCursor;
  int sizeCode;
  int repeatSize;
{
  char ch;
  int copyIndex;
  int copyEnd;
  
  if ((sizeCode != 3) || (repeatSize == 1)) {
    copyIndex = 0;
    ch = s___97c2a320[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ":"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyEnd = ((int (*)())_ncpy_97be5f58)(outCursor + copyIndex,sizeCode + 1);
    outCursor = outCursor + copyIndex + copyEnd;
    if (repeatSize == 1) {
      copyIndex = 0;
      ch = s___97c2a320[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ":"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyEnd = ((int (*)())_ncpy_97be5f58)(outCursor + copyIndex,sizeCode + 1);
      outCursor = outCursor + copyIndex + copyEnd;
    }
  }
  return outCursor;
}

/* _glpWriteSizeType @ 0x97be646c (472 bytes) */
int _glpWriteSizeType(out, sizeMinusOne, isMatrix, valueType)
  int out;
  int sizeMinusOne;
  int isMatrix;
  undefined4 valueType;
{
  int copyEnd;
  char ch;
  int copyIndex;
  int writeCursor;
  int copyEnd2;
  
  copyIndex = 0;
  ch = s___97c2a320[0];
  while (ch != '\0') {
    *(char *)(out + copyIndex) = ch;
    ch = ":"[copyIndex + 1];
    copyIndex = copyIndex + 1;
  }
  copyEnd = ((int (*)())_ncpy_97be5f58)(out + copyIndex,sizeMinusOne + 1);
  writeCursor = out + copyIndex + copyEnd;
  if (isMatrix != 0) {
    copyIndex = 0;
    ch = s___97c2a320[0];
    while (ch != '\0') {
      *(char *)(writeCursor + copyIndex) = ch;
      ch = ":"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyEnd2 = ((int (*)())_ncpy_97be5f58)(writeCursor + copyIndex,sizeMinusOne + 1);
    writeCursor = writeCursor + copyIndex + copyEnd2;
  }
  switch(valueType) {
  default:
    goto switchD_97be6548_caseD_0;
  case 1:
    copyIndex = 0;
    ch = s_F_97c2d738[0];
    while (ch != '\0') {
      *(char *)(writeCursor + copyIndex) = ch;
      ch = "F"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    break;
  case 2:
    copyIndex = 0;
    ch = s_X_97c2d73c[0];
    while (ch != '\0') {
      *(char *)(writeCursor + copyIndex) = ch;
      ch = "X"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    break;
  case 3:
    copyIndex = 0;
    ch = s_I_97c2d740[0];
    while (ch != '\0') {
      *(char *)(writeCursor + copyIndex) = ch;
      ch = "I"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    break;
  case 4:
    copyIndex = 0;
    ch = s_B_97c2d744[0];
    while (ch != '\0') {
      *(char *)(writeCursor + copyIndex) = ch;
      ch = "B"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
  }
  writeCursor = writeCursor + copyIndex;
switchD_97be6548_caseD_0:
  return writeCursor;
}

/* _glpWriteClampSat @ 0x97be6658 (216 bytes) */
int _glpWriteClampSat(outCursor, hasClamp, clampKind, saturate)
  int outCursor;
  int hasClamp;
  int clampKind;
  int saturate;
{
  char ch;
  int copyIndex;
  
  if (hasClamp != 0) {
    copyIndex = 0;
    ch = s_C_97c2d75c[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = "C"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = outCursor + copyIndex;
    if (0 < clampKind) {
      copyIndex = 0;
      ch = s_1_97c2d760[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = "1"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = outCursor + copyIndex;
    }
  }
  if (saturate != 0) {
    copyIndex = 0;
    ch = s__SAT_97c2d764[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = "_SAT"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    return outCursor + copyIndex;
  }
  return outCursor;
}

/* _glpWriteDestinationOperand_97be6730 @ 0x97be6730 (1764 bytes) */
int _glpWriteDestinationOperand_97be6730(operands, outCursor, tempNumberMap, tempArrayMap, operandIndex, printSwizzle)
  int operands;
  char *outCursor;
  int tempNumberMap;
  int tempArrayMap;
  int operandIndex;
  int printSwizzle;
{
  uint conditionCode;
  uint destWord0;
  uint relativeWord;
  uint addressComponent;
  int numberLength;
  int copyEnd;
  char ch;
  ushort registerNumber;
  int operandByteOffset;
  uint registerFile;
  int copyIndex;
  int copyEnd2;
  int relativeOffset;
  char *textCursor;
  
  operandByteOffset = operandIndex * 8;
  registerFile = *(uint *)(operandByteOffset + operands) >> 0x11 & 7;
  if (registerFile == 1) {
    copyIndex = 0;
    ch = s_tmp_97c2d76c[0];
    while (ch != '\0') {
      outCursor[copyIndex] = ch;
      ch = "tmp"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    textCursor = outCursor + copyIndex;
    if ((printSwizzle == 0) || (tempNumberMap == 0)) {
      registerNumber = *(ushort *)(operandByteOffset + operands + 6);
      goto LAB_97be68f4;
    }
    numberLength = ((int (*)())_ncpy_97be5f58)(textCursor,*(undefined4 *)
                                   (tempNumberMap + (uint)*(ushort *)(operandByteOffset + operands + 6) * 4));
    outCursor = textCursor + numberLength;
    if (((tempArrayMap != 0) && (registerFile = *(uint *)(operandByteOffset + operands + 4), -1 < (int)registerFile)) &&
       (*(int *)(tempArrayMap + (registerFile & 0xffff) * 4) != -1)) {
      copyIndex = 0;
      ch = s___97c29860[0];
      while (ch != '\0') {
        outCursor[copyIndex] = ch;
        ch = "["[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      textCursor = outCursor + copyIndex;
      copyEnd = ((int (*)())_ncpy_97be5f58)(textCursor,*(undefined4 *)
                                     (tempArrayMap + (uint)*(ushort *)(operandByteOffset + operands + 6) * 4));
      copyIndex = 0;
      ch = s___97c2d770[0];
      while (ch != '\0') {
        textCursor[copyIndex + copyEnd] = ch;
        ch = "]"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = textCursor + copyIndex + copyEnd;
    }
  }
  else if (registerFile == 3) {
    copyIndex = 0;
    ch = s_res_97c2d774[0];
    while (ch != '\0') {
      outCursor[copyIndex] = ch;
      ch = "res"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    textCursor = outCursor + copyIndex;
    registerNumber = *(ushort *)(operandByteOffset + operands + 6);
LAB_97be68f4:
    numberLength = ((int (*)())_ncpy_97be5f58)(textCursor,(uint)registerNumber);
    outCursor = textCursor + numberLength;
  }
  if (printSwizzle == 0) {
    if ((*(uint *)(operandByteOffset + operands) & 0x1e000) != 0x1e000) {
      copyIndex = 0;
      ch = s___97c2a130[0];
      while (ch != '\0') {
        outCursor[copyIndex] = ch;
        ch = "."[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = outCursor + copyIndex;
      if ((*(uint *)(operandByteOffset + operands) & 0x2000) != 0) {
        copyIndex = 0;
        ch = s_x_97c2d790[0];
        while (ch != '\0') {
          outCursor[copyIndex] = ch;
          ch = "x"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = outCursor + copyIndex;
      }
      if ((*(uint *)(operandByteOffset + operands) & 0x4000) != 0) {
        copyIndex = 0;
        ch = s_y_97c2d794[0];
        while (ch != '\0') {
          outCursor[copyIndex] = ch;
          ch = "y"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = outCursor + copyIndex;
      }
      if ((*(uint *)(operandByteOffset + operands) & 0x8000) != 0) {
        copyIndex = 0;
        ch = s_z_97c2d798[0];
        while (ch != '\0') {
          outCursor[copyIndex] = ch;
          ch = "z"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = outCursor + copyIndex;
      }
      if ((*(uint *)(operandByteOffset + operands) & 0x10000) != 0) {
        copyIndex = 0;
        ch = s_w_97c2d79c[0];
        while (ch != '\0') {
          outCursor[copyIndex] = ch;
          ch = "w"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = outCursor + copyIndex;
      }
    }
  }
  else {
    if (*(int *)(operandByteOffset + operands + 4) < 0) {
      relativeOffset = 0;
      copyIndex = 0;
      ch = s__adr_97c2d778[0];
      while (ch != '\0') {
        outCursor[copyIndex] = ch;
        ch = "[adr"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyEnd2 = ((int (*)())_ncpy_97be5f58)(outCursor + copyIndex,*(uint *)(operandByteOffset + operands + 4) >> 0x1e & 1);
      textCursor = outCursor + copyIndex + copyEnd2;
      addressComponent = *(uint *)(operandByteOffset + operands + 4) >> 0x1c & 3;
      if (addressComponent == 1) {
        copyIndex = 0;
        ch = s__y_97c2d784[0];
        while (ch != '\0') {
          textCursor[copyIndex] = ch;
          ch = ".y"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
LAB_97be6a74:
        textCursor = textCursor + copyIndex;
      }
      else {
        if (1 < addressComponent) {
          if (addressComponent == 2) {
            copyIndex = 0;
            ch = s__z_97c2d788[0];
            while (ch != '\0') {
              textCursor[copyIndex] = ch;
              ch = ".z"[copyIndex + 1];
              copyIndex = copyIndex + 1;
            }
          }
          else {
            if (addressComponent != 3) goto LAB_97be6a78;
            copyIndex = 0;
            ch = s__w_97c2d78c[0];
            while (ch != '\0') {
              textCursor[copyIndex] = ch;
              ch = ".w"[copyIndex + 1];
              copyIndex = copyIndex + 1;
            }
          }
          goto LAB_97be6a74;
        }
        if (addressComponent == 0) {
          copyIndex = 0;
          ch = s__x_97c2d780[0];
          while (ch != '\0') {
            textCursor[copyIndex] = ch;
            ch = ".x"[copyIndex + 1];
            copyIndex = copyIndex + 1;
          }
          goto LAB_97be6a74;
        }
      }
LAB_97be6a78:
      if ((((*(uint *)(operandByteOffset + operands) >> 0x11 & 7) == 1) && (tempArrayMap != 0)) &&
         (copyIndex = *(int *)(tempArrayMap + (uint)*(ushort *)(operandByteOffset + operands + 6) * 4), copyIndex != -1)) {
        relativeOffset = copyIndex;
      }
      relativeWord = *(uint *)(operandByteOffset + operands + 4);
      relativeOffset = relativeOffset + ((int)(relativeWord << 4 | relativeWord >> 0x1c) >> 0x18);
      if (relativeOffset != 0) {
        if (0 < relativeOffset) {
          copyIndex = 0;
          ch = s___97c2a308[0];
          while (ch != '\0') {
            textCursor[copyIndex] = ch;
            ch = "+"[copyIndex + 1];
            copyIndex = copyIndex + 1;
          }
          textCursor = textCursor + copyIndex;
        }
        numberLength = ((int (*)())_ncpy_97be5f58)(textCursor,relativeOffset);
        textCursor = textCursor + numberLength;
      }
      copyIndex = 0;
      ch = s___97c2d770[0];
      while (ch != '\0') {
        textCursor[copyIndex] = ch;
        ch = "]"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = textCursor + copyIndex;
    }
    copyIndex = 0;
    ch = s___97c2a130[0];
    while (ch != '\0') {
      outCursor[copyIndex] = ch;
      ch = "."[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    textCursor = outCursor + copyIndex;
    if ((*(uint *)(operandByteOffset + operands) & 0x2000) == 0) {
      *textCursor = '_';
    }
    else {
      *textCursor = (((byte)(*(uint *)(operandByteOffset + operands) >> 8) & 3) + 1 & 3) + 0x77;
    }
    destWord0 = *(uint *)(operandByteOffset + operands);
    outCursor = textCursor + 1;
    if ((destWord0 & 0xc00) != 0) {
      if ((destWord0 & 0x4000) == 0) {
        *outCursor = '_';
      }
      else {
        *outCursor = (((byte)(destWord0 >> 6) & 3) + 1 & 3) + 0x77;
      }
      outCursor = textCursor + 2;
    }
    destWord0 = *(uint *)(operandByteOffset + operands);
    if (1 < (destWord0 >> 10 & 3)) {
      if ((destWord0 & 0x8000) == 0) {
        *outCursor = '_';
      }
      else {
        *outCursor = (((byte)(destWord0 >> 4) & 3) + 1 & 3) + 0x77;
      }
      outCursor = outCursor + 1;
    }
    destWord0 = *(uint *)(operandByteOffset + operands);
    if (2 < (destWord0 >> 10 & 3)) {
      if ((destWord0 & 0x10000) == 0) {
        *outCursor = '_';
      }
      else {
        *outCursor = (((byte)(destWord0 >> 2) & 3) + 1 & 3) + 0x77;
      }
      outCursor = outCursor + 1;
    }
  }
  if (printSwizzle != 0) {
    outCursor = (char *)((int (*)())_glpWriteOperandSize)(outCursor,*(uint *)(operandByteOffset + operands) >> 10 & 3,
                                 *(uint *)(operandByteOffset + operands) >> 0xc & 1);
  }
  conditionCode = *(uint *)(operandByteOffset + operands) >> 0x1c & 7;
  if (conditionCode == 0) {
    return outCursor;
  }
  switch(conditionCode) {
  case 1:
    copyIndex = 0;
    ch = s__EQ_97c2d7a8[0];
    while (ch != '\0') {
      outCursor[copyIndex] = ch;
      ch = " (EQ"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    break;
  case 2:
    copyIndex = 0;
    ch = s__GE_97c2d7b0[0];
    while (ch != '\0') {
      outCursor[copyIndex] = ch;
      ch = " (GE"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    break;
  case 3:
    copyIndex = 0;
    ch = s__GT_97c2d7b8[0];
    while (ch != '\0') {
      outCursor[copyIndex] = ch;
      ch = " (GT"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    break;
  case 4:
    copyIndex = 0;
    ch = s__LE_97c2d7c0[0];
    while (ch != '\0') {
      outCursor[copyIndex] = ch;
      ch = " (LE"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    break;
  case 5:
    copyIndex = 0;
    ch = s__LT_97c2d7c8[0];
    while (ch != '\0') {
      outCursor[copyIndex] = ch;
      ch = " (LT"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    break;
  case 6:
    copyIndex = 0;
    ch = s__NE_97c2d7d0[0];
    while (ch != '\0') {
      outCursor[copyIndex] = ch;
      ch = " (NE"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    break;
  case 7:
    copyIndex = 0;
    ch = s__FL_97c2d7d8[0];
    while (ch != '\0') {
      outCursor[copyIndex] = ch;
      ch = " (FL"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    break;
  default:
    goto switchD_97be6e10_default;
  }
  outCursor = outCursor + copyIndex;
switchD_97be6e10_default:
  if (*(int *)(operandByteOffset + operands) < 0) {
    *outCursor = '1';
    outCursor = outCursor + 1;
  }
  *outCursor = '.';
  outCursor[1] = (((byte)((uint)*(undefined4 *)(operandByteOffset + operands) >> 0x1a) & 3) + 1 & 3) + 0x77;
  outCursor[2] = ((*(byte *)(operandByteOffset + operands) & 3) + 1 & 3) + 0x77;
  outCursor[3] = (((byte)(*(uint *)(operandByteOffset + operands) >> 0x16) & 3) + 1 & 3) + 0x77;
  outCursor[4] = (((byte)(*(uint *)(operandByteOffset + operands) >> 0x14) & 3) + 1 & 3) + 0x77;
  outCursor[5] = ')';
  return outCursor + 6;
}

/* _glpWriteAddressOperand @ 0x97be70a0 (820 bytes) */
int _glpWriteAddressOperand(operands, outCursor, operandIndex, printSwizzle)
  int operands;
  int outCursor;
  int operandIndex;
  int printSwizzle;
{
  int copyIndex2;
  int copyIndex3;
  int copyEnd;
  char ch;
  int operandByteOffset;
  int copyIndex;
  int textCursor;
  
  operandByteOffset = operandIndex * 8;
  if ((*(uint *)(operandByteOffset + operands) >> 0x11 & 7) == 4) {
    copyIndex2 = 0;
    ch = s_adr_97c2d7e0[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex2) = ch;
      ch = "adr"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    copyEnd = ((int (*)())_ncpy_97be5f58)(outCursor + copyIndex2,(uint)*(ushort *)(operandByteOffset + operands + 6));
    outCursor = outCursor + copyIndex2 + copyEnd;
  }
  if ((*(uint *)(operandByteOffset + operands) & 0x1e000) != 0x1e000) {
    copyIndex2 = 0;
    ch = s___97c2a130[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex2) = ch;
      ch = "."[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    textCursor = outCursor + copyIndex2;
    if (printSwizzle == 0) {
      if ((*(uint *)(operandByteOffset + operands) & 0x2000) != 0) {
        copyIndex = 0;
        ch = s_x_97c2d790[0];
        while (ch != '\0') {
          *(char *)(textCursor + copyIndex) = ch;
          ch = "x"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        textCursor = textCursor + copyIndex;
      }
      if ((*(uint *)(operandByteOffset + operands) & 0x4000) != 0) {
        copyIndex = 0;
        ch = s_y_97c2d794[0];
        while (ch != '\0') {
          *(char *)(textCursor + copyIndex) = ch;
          ch = "y"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        textCursor = textCursor + copyIndex;
      }
      if ((*(uint *)(operandByteOffset + operands) & 0x8000) != 0) {
        copyIndex = 0;
        ch = s_z_97c2d798[0];
        while (ch != '\0') {
          *(char *)(textCursor + copyIndex) = ch;
          ch = "z"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        textCursor = textCursor + copyIndex;
      }
      if ((*(uint *)(operandByteOffset + operands) & 0x10000) == 0) {
        return textCursor;
      }
      copyIndex3 = 0;
      ch = s_w_97c2d79c[0];
      while (ch != '\0') {
        *(char *)(textCursor + copyIndex3) = ch;
        ch = "w"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
    }
    else {
      if ((*(uint *)(operandByteOffset + operands) & 0x2000) != 0) {
        copyIndex = 0;
        ch = s_x_97c2d790[0];
        while (ch != '\0') {
          *(char *)(textCursor + copyIndex) = ch;
          ch = "x"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        textCursor = textCursor + copyIndex;
      }
      if (((*(uint *)(operandByteOffset + operands) & 0xc00) != 0) &&
         ((*(uint *)(operandByteOffset + operands) & 0x4000) != 0)) {
        copyIndex = 0;
        ch = s_y_97c2d794[0];
        while (ch != '\0') {
          *(char *)(textCursor + copyIndex) = ch;
          ch = "y"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        textCursor = textCursor + copyIndex;
      }
      if ((1 < (*(uint *)(operandByteOffset + operands) >> 10 & 3)) &&
         ((*(uint *)(operandByteOffset + operands) & 0x8000) != 0)) {
        copyIndex = 0;
        ch = s_z_97c2d798[0];
        while (ch != '\0') {
          *(char *)(textCursor + copyIndex) = ch;
          ch = "z"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        textCursor = textCursor + copyIndex;
      }
      if ((*(uint *)(operandByteOffset + operands) >> 10 & 3) < 3) {
        return textCursor;
      }
      if ((*(uint *)(operandByteOffset + operands) & 0x10000) == 0) {
        return textCursor;
      }
      copyIndex3 = 0;
      ch = s_w_97c2d79c[0];
      while (ch != '\0') {
        *(char *)(textCursor + copyIndex3) = ch;
        ch = "w"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
    }
    outCursor = textCursor + copyIndex3;
  }
  return outCursor;
}

/* _glpWriteSourceOperandType @ 0x97be73d4 (1476 bytes) */
int _glpWriteSourceOperandType(operands, outCursor, paramNumberMap, paramArrayMap, tempNumberMap, tempArrayMap, operandIndex)
  int operands;
  int outCursor;
  int paramNumberMap;
  int paramArrayMap;
  int tempNumberMap;
  int tempArrayMap;
  int operandIndex;
{
  int defaultArrayBase;
  int relativeOffset;
  int copyIndex;
  int copyEnd;
  int copyEnd2;
  char ch;
  uint displayNumber;
  int writeCursor;
  int operandByteOffset;
  int copyIndex2;
  int numberLength;
  
  operandByteOffset = operandIndex * 8;
  switch(*(uint *)(operandByteOffset + operands) >> 0x17 & 7) {
  case 0:
    copyIndex2 = 0;
    ch = s_att_97c2d7e4[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex2) = ch;
      ch = "att"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    goto LAB_97be770c;
  case 1:
    copyIndex2 = 0;
    ch = s_tmp_97c2d76c[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex2) = ch;
      ch = "tmp"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    if (tempNumberMap == 0) {
      displayNumber = (uint)*(ushort *)(operandByteOffset + operands + 6);
    }
    else {
      displayNumber = *(uint *)(tempNumberMap + (uint)*(ushort *)(operandByteOffset + operands + 6) * 4);
    }
    numberLength = ((int (*)())_ncpy_97be5f58)(outCursor + copyIndex2,displayNumber);
    outCursor = outCursor + copyIndex2 + numberLength;
    if (((tempArrayMap != 0) && (-1 < *(int *)(operandByteOffset + operands))) &&
       (*(int *)(tempArrayMap + (uint)*(ushort *)(operandByteOffset + operands + 6) * 4) != -1)) {
      copyIndex2 = 0;
      ch = s___97c29860[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex2) = ch;
        ch = "["[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      numberLength = ((int (*)())_ncpy_97be5f58)(outCursor + copyIndex2,
                             *(undefined4 *)(tempArrayMap + (uint)*(ushort *)(operandByteOffset + operands + 6) * 4));
      numberLength = outCursor + copyIndex2 + numberLength;
      copyIndex2 = 0;
      ch = s___97c2d770[0];
      while (ch != '\0') {
        *(char *)(numberLength + copyIndex2) = ch;
        ch = "]"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
LAB_97be7698:
      outCursor = numberLength + copyIndex2;
    }
    break;
  case 2:
    copyIndex2 = 0;
    ch = s_prm_97c2d7e8[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex2) = ch;
      ch = "prm"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    numberLength = ((int (*)())_ncpy_97be5f58)(outCursor + copyIndex2,
                           *(undefined4 *)(paramNumberMap + (uint)*(ushort *)(operandByteOffset + operands + 6) * 4));
    outCursor = outCursor + copyIndex2 + numberLength;
    if ((-1 < *(int *)(operandByteOffset + operands)) &&
       (*(int *)(paramArrayMap + (uint)*(ushort *)(operandByteOffset + operands + 6) * 4) != -1)) {
      copyIndex2 = 0;
      ch = s___97c29860[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex2) = ch;
        ch = "["[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      numberLength = ((int (*)())_ncpy_97be5f58)(outCursor + copyIndex2,
                             *(undefined4 *)(paramArrayMap + (uint)*(ushort *)(operandByteOffset + operands + 6) * 4));
      numberLength = outCursor + copyIndex2 + numberLength;
      copyIndex2 = 0;
      ch = s___97c2d770[0];
      while (ch != '\0') {
        *(char *)(numberLength + copyIndex2) = ch;
        ch = "]"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      goto LAB_97be7698;
    }
    break;
  case 3:
    copyIndex2 = 0;
    ch = s_res_97c2d774[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex2) = ch;
      ch = "res"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    goto LAB_97be770c;
  case 4:
    copyIndex2 = 0;
    ch = s_adr_97c2d7e0[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex2) = ch;
      ch = "adr"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
LAB_97be770c:
    numberLength = ((int (*)())_ncpy_97be5f58)(outCursor + copyIndex2,(uint)*(ushort *)(operandByteOffset + operands + 6));
    outCursor = outCursor + copyIndex2 + numberLength;
  }
  if (-1 < *(int *)(operandByteOffset + operands)) {
    return outCursor;
  }
  defaultArrayBase = 0;
  copyIndex2 = 0;
  ch = s__adr_97c2d778[0];
  while (ch != '\0') {
    *(char *)(outCursor + copyIndex2) = ch;
    ch = "[adr"[copyIndex2 + 1];
    copyIndex2 = copyIndex2 + 1;
  }
  copyEnd2 = ((int (*)())_ncpy_97be5f58)(outCursor + copyIndex2,*(uint *)(operandByteOffset + operands) >> 0x1e & 1);
  writeCursor = outCursor + copyIndex2 + copyEnd2;
  displayNumber = *(uint *)(operandByteOffset + operands) >> 0x1c & 3;
  if (displayNumber == 1) {
    copyIndex2 = 0;
    ch = s__y_97c2d784[0];
    while (ch != '\0') {
      *(char *)(writeCursor + copyIndex2) = ch;
      ch = ".y"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
  }
  else if (displayNumber < 2) {
    if (displayNumber != 0) goto LAB_97be7894;
    copyIndex2 = 0;
    ch = s__x_97c2d780[0];
    while (ch != '\0') {
      *(char *)(writeCursor + copyIndex2) = ch;
      ch = ".x"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
  }
  else if (displayNumber == 2) {
    copyIndex2 = 0;
    ch = s__z_97c2d788[0];
    while (ch != '\0') {
      *(char *)(writeCursor + copyIndex2) = ch;
      ch = ".z"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
  }
  else {
    if (displayNumber != 3) goto LAB_97be7894;
    copyIndex2 = 0;
    ch = s__w_97c2d78c[0];
    while (ch != '\0') {
      *(char *)(writeCursor + copyIndex2) = ch;
      ch = ".w"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
  }
  writeCursor = writeCursor + copyIndex2;
LAB_97be7894:
  if ((((((*(uint *)(operandByteOffset + operands) >> 0x17 & 7) != 1) || (tempArrayMap == 0)) ||
       (relativeOffset = *(int *)(tempArrayMap + (uint)*(ushort *)(operandByteOffset + operands + 6) * 4), relativeOffset == -1)) &&
      ((relativeOffset = defaultArrayBase, (*(uint *)(operandByteOffset + operands) >> 0x17 & 7) == 2 && (paramArrayMap != 0)))) &&
     (defaultArrayBase = *(int *)(paramArrayMap + (uint)*(ushort *)(operandByteOffset + operands + 6) * 4), defaultArrayBase != -1)) {
    relativeOffset = defaultArrayBase;
  }
  relativeOffset = relativeOffset + (char)*(undefined4 *)(operandByteOffset + operands);
  if (relativeOffset != 0) {
    if (0 < relativeOffset) {
      copyIndex = 0;
      ch = s___97c2a308[0];
      while (ch != '\0') {
        *(char *)(writeCursor + copyIndex) = ch;
        ch = "+"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      writeCursor = writeCursor + copyIndex;
    }
    copyEnd = ((int (*)())_ncpy_97be5f58)(writeCursor,relativeOffset);
    writeCursor = writeCursor + copyEnd;
  }
  copyIndex = 0;
  ch = s___97c2d770[0];
  while (ch != '\0') {
    *(char *)(writeCursor + copyIndex) = ch;
    ch = "]"[copyIndex + 1];
    copyIndex = copyIndex + 1;
  }
  return writeCursor + copyIndex;
}

/* _glpWriteSourceOperandSwizzle @ 0x97be79ac (488 bytes) */
int _glpWriteSourceOperandSwizzle(operands, outCursor, operandIndex, printSize)
  int operands;
  char *outCursor;
  int operandIndex;
  int printSize;
{
  int copyIndex;
  int copyIndex2;
  char ch;
  int operandByteOffset2;
  int operandByteOffset;
  uint operandWord;
  char *textCursor;
  uint xSelect;
  
  if (printSize == 0) {
    operandByteOffset = operandIndex * 8;
    if ((*(uint *)(operandByteOffset + operands) & 0x7f8000) == 0xd8000) {
      return outCursor;
    }
    copyIndex2 = 0;
    ch = s___97c2a130[0];
    while (ch != '\0') {
      outCursor[copyIndex2] = ch;
      ch = "."[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    operandWord = *(uint *)(operandByteOffset + operands);
    textCursor = outCursor + copyIndex2;
    xSelect = operandWord >> 0x15 & 3;
    if (((xSelect == (operandWord >> 0x13 & 3)) && (xSelect == (operandWord >> 0x11 & 3))) &&
       (xSelect == (operandWord >> 0xf & 3))) {
      outCursor[copyIndex2] = ((char)xSelect + 1U & 3) + 0x77;
    }
    else {
      *textCursor = (((byte)(*(uint *)(operandByteOffset + operands) >> 0x15) & 3) + 1 & 3) + 0x77;
      textCursor[1] = (((byte)(*(uint *)(operandByteOffset + operands) >> 0x13) & 3) + 1 & 3) + 0x77;
      textCursor[2] = (((byte)(*(uint *)(operandByteOffset + operands) >> 0x11) & 3) + 1 & 3) + 0x77;
      textCursor = textCursor + 3;
      *textCursor = (((byte)(*(uint *)(operandByteOffset + operands) >> 0xf) & 3) + 1 & 3) + 0x77;
    }
  }
  else {
    copyIndex = 0;
    ch = s___97c2a130[0];
    while (ch != '\0') {
      outCursor[copyIndex] = ch;
      ch = "."[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    operandByteOffset2 = operandIndex * 8;
    textCursor = outCursor + copyIndex + 1;
    outCursor[copyIndex] = (((byte)(*(uint *)(operandByteOffset2 + operands) >> 0x15) & 3) + 1 & 3) + 0x77;
    operandWord = *(uint *)(operandByteOffset2 + operands);
    if ((operandWord & 0x3000) != 0) {
      *textCursor = (((byte)(operandWord >> 0x13) & 3) + 1 & 3) + 0x77;
      textCursor = outCursor + copyIndex + 2;
      operandWord = *(uint *)(operandByteOffset2 + operands);
    }
    if (1 < (operandWord >> 0xc & 3)) {
      *textCursor = (((byte)(operandWord >> 0x11) & 3) + 1 & 3) + 0x77;
      textCursor = textCursor + 1;
      operandWord = *(uint *)(operandByteOffset2 + operands);
    }
    if ((operandWord >> 0xc & 3) < 3) {
      return textCursor;
    }
    *textCursor = (((byte)(operandWord >> 0xf) & 3) + 1 & 3) + 0x77;
  }
  return textCursor + 1;
}

/* _glpWriteSourceOperandExtendedSwizzle @ 0x97be7b94 (1024 bytes) */
int _glpWriteSourceOperandExtendedSwizzle(operands, outCursor, operandIndex)
  int operands;
  int outCursor;
  int operandIndex;
{
  char ch;
  int copyIndex;
  uint componentSelect;
  int loopIndex;
  
  componentSelect = 0;
  loopIndex = 0;
  do {
    if (loopIndex == 1) {
      componentSelect = *(uint *)(operandIndex * 8 + operands) >> 8 & 0xf;
      copyIndex = 0;
      ch = s___97c2a324[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ","[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
LAB_97be7cf0:
      outCursor = outCursor + copyIndex;
    }
    else {
      if (1 < loopIndex) {
        if (loopIndex == 2) {
          componentSelect = *(uint *)(operandIndex * 8 + operands) >> 4 & 0xf;
          copyIndex = 0;
          ch = s___97c2a324[0];
          while (ch != '\0') {
            *(char *)(outCursor + copyIndex) = ch;
            ch = ","[copyIndex + 1];
            copyIndex = copyIndex + 1;
          }
        }
        else {
          if (loopIndex != 3) goto LAB_97be7cf4;
          componentSelect = *(uint *)(operandIndex * 8 + operands) & 0xf;
          copyIndex = 0;
          ch = s___97c2a324[0];
          while (ch != '\0') {
            *(char *)(outCursor + copyIndex) = ch;
            ch = ","[copyIndex + 1];
            copyIndex = copyIndex + 1;
          }
        }
        goto LAB_97be7cf0;
      }
      if (loopIndex == 0) {
        componentSelect = *(uint *)(operandIndex * 8 + operands) >> 0xc & 0xf;
        copyIndex = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ", "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        goto LAB_97be7cf0;
      }
    }
LAB_97be7cf4:
    switch(componentSelect) {
    case 0:
      copyIndex = 0;
      ch = s_x_97c2d790[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = "x"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      break;
    case 1:
      copyIndex = 0;
      ch = s_y_97c2d794[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = "y"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      break;
    case 2:
      copyIndex = 0;
      ch = s_z_97c2d798[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = "z"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      break;
    case 3:
      copyIndex = 0;
      ch = s_w_97c2d79c[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = "w"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      break;
    case 4:
      copyIndex = 0;
      ch = s__x_97c2d7f0[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = "-x"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      break;
    case 5:
      copyIndex = 0;
      ch = s__y_97c2d7f4[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = "-y"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      break;
    case 6:
      copyIndex = 0;
      ch = s__z_97c2d7f8[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = "-z"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      break;
    case 7:
      copyIndex = 0;
      ch = s__w_97c2d7fc[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = "-w"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      break;
    case 8:
      copyIndex = 0;
      ch = s_1_97c2d760[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = "1"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      break;
    case 9:
      copyIndex = 0;
      ch = s_0_97c2d800[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = "0"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      break;
    case 10:
      copyIndex = 0;
      ch = s__1_97c2d804[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = "-1"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      break;
    default:
      goto switchD_97be7d14_default;
    }
    outCursor = outCursor + copyIndex;
switchD_97be7d14_default:
    loopIndex = loopIndex + 1;
    if (3 < loopIndex) {
      return;
    }
  } while( true );
}

/* _glpWriteSourceOperand_97be7fc0 @ 0x97be7fc0 (380 bytes) */
int _glpWriteSourceOperand_97be7fc0(operands, outCursor, paramNumberMap, paramArrayMap, tempNumberMap, tempArrayMap, operandIndex, printSize, useExtendedSwizzle)
  int operands;
  int outCursor;
  undefined4 paramNumberMap;
  undefined4 paramArrayMap;
  undefined4 tempNumberMap;
  undefined4 tempArrayMap;
  int operandIndex;
  int printSize;
  int useExtendedSwizzle;
{
  int copyIndex;
  int copyIndex2;
  char ch;
  int operandByteOffset;
  int textCursor;
  
  operandByteOffset = operandIndex * 8;
  if ((*(uint *)(operandByteOffset + operands) & 0x8000000) != 0) {
    copyIndex = 0;
    ch = s___97c2a2d4[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = "-"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = outCursor + copyIndex;
  }
  if ((*(uint *)(operandByteOffset + operands) & 0x4000000) != 0) {
    copyIndex = 0;
    ch = s___97c2a31c[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = "|"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = outCursor + copyIndex;
  }
  textCursor = ((int (*)())_glpWriteSourceOperandType)(operands,outCursor,paramNumberMap,paramArrayMap,tempNumberMap,tempArrayMap,operandIndex);
  if ((*(uint *)(operandByteOffset + operands) >> 0x17 & 7) != 4) {
    if (useExtendedSwizzle == 0) {
      textCursor = ((int (*)())_glpWriteSourceOperandSwizzle)(operands,textCursor,operandIndex,printSize);
    }
    else {
      textCursor = ((int (*)())_glpWriteSourceOperandExtendedSwizzle)(operands,textCursor,operandIndex + 1);
    }
  }
  if (printSize != 0) {
    textCursor = ((int (*)())_glpWriteOperandSize)(textCursor,*(uint *)(operandByteOffset + operands) >> 0xc & 3,
                       *(uint *)(operandByteOffset + operands) >> 0xe & 1);
  }
  if ((*(uint *)(operandByteOffset + operands) & 0x4000000) != 0) {
    copyIndex2 = 0;
    ch = s___97c2a31c[0];
    while (ch != '\0') {
      *(char *)(textCursor + copyIndex2) = ch;
      ch = "|"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    textCursor = textCursor + copyIndex2;
  }
  return textCursor;
}

/* _glpWriteBranchOperand @ 0x97be813c (796 bytes) */
int _glpWriteBranchOperand(operands, outCursor, labelTable, operandIndex, printCondition)
  int operands;
  char *outCursor;
  uint *labelTable;
  int operandIndex;
  int printCondition;
{
  int operandByteOffset;
  int sprintfResult;
  char ch;
  int copyIndex;
  char *textCursor;
  uint labelEntry;
  int labelIndex;
  
  labelIndex = 0;
  if (labelTable == (uint *)0x0) {
    labelIndex = -1;
  }
  else {
    labelEntry = *labelTable;
    while (labelEntry != (*(uint *)(operandIndex * 8 + operands + -4) & 0x3ffff)) {
      labelTable = labelTable + 1;
      labelIndex = labelIndex + 1;
      labelEntry = *labelTable;
    }
  }
  sprintfResult = _sprintf(outCursor,"label_%i",labelIndex);
  textCursor = outCursor + sprintfResult;
  if (printCondition == 0) {
    return textCursor;
  }
  operandByteOffset = operandIndex * 8;
  switch(*(uint *)(operandByteOffset + operands) >> 0x1c & 7) {
  case 0:
    copyIndex = 0;
    ch = s__TR_97c2d7a0[0];
    while (ch != '\0') {
      textCursor[copyIndex] = ch;
      ch = " (TR"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    break;
  case 1:
    copyIndex = 0;
    ch = s__EQ_97c2d7a8[0];
    while (ch != '\0') {
      textCursor[copyIndex] = ch;
      ch = " (EQ"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    break;
  case 2:
    copyIndex = 0;
    ch = s__GE_97c2d7b0[0];
    while (ch != '\0') {
      textCursor[copyIndex] = ch;
      ch = " (GE"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    break;
  case 3:
    copyIndex = 0;
    ch = s__GT_97c2d7b8[0];
    while (ch != '\0') {
      textCursor[copyIndex] = ch;
      ch = " (GT"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    break;
  case 4:
    copyIndex = 0;
    ch = s__LE_97c2d7c0[0];
    while (ch != '\0') {
      textCursor[copyIndex] = ch;
      ch = " (LE"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    break;
  case 5:
    copyIndex = 0;
    ch = s__LT_97c2d7c8[0];
    while (ch != '\0') {
      textCursor[copyIndex] = ch;
      ch = " (LT"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    break;
  case 6:
    copyIndex = 0;
    ch = s__NE_97c2d7d0[0];
    while (ch != '\0') {
      textCursor[copyIndex] = ch;
      ch = " (NE"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    break;
  case 7:
    copyIndex = 0;
    ch = s__FL_97c2d7d8[0];
    while (ch != '\0') {
      textCursor[copyIndex] = ch;
      ch = " (FL"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    break;
  default:
    goto switchD_97be81f4_default;
  }
  textCursor = textCursor + copyIndex;
switchD_97be81f4_default:
  if (*(int *)(operandByteOffset + operands) < 0) {
    *textCursor = '1';
    textCursor = textCursor + 1;
  }
  *textCursor = '.';
  textCursor[1] = (((byte)((uint)*(undefined4 *)(operandByteOffset + operands) >> 0x1a) & 3) + 1 & 3) + 0x77;
  textCursor[2] = ((*(byte *)(operandByteOffset + operands) & 3) + 1 & 3) + 0x77;
  textCursor[3] = (((byte)(*(uint *)(operandByteOffset + operands) >> 0x16) & 3) + 1 & 3) + 0x77;
  textCursor[4] = (((byte)(*(uint *)(operandByteOffset + operands) >> 0x14) & 3) + 1 & 3) + 0x77;
  textCursor[5] = ')';
  return textCursor + 6;
}

/* _glpWriteTextureOperand_97be8478 @ 0x97be8478 (736 bytes) */
int _glpWriteTextureOperand_97be8478(operands, outCursor, paramNumberMap, paramArrayMap, tempNumberMap, tempArrayMap, operandIndex, indirectUnit)
  int operands;
  int outCursor;
  undefined4 paramNumberMap;
  undefined4 paramArrayMap;
  undefined4 tempNumberMap;
  undefined4 tempArrayMap;
  int operandIndex;
  int indirectUnit;
{
  int copiedLength;
  int operandByteOffset;
  int copyEnd;
  char ch;
  int nextIndex;
  int copyIndex;
  int writeCursor;
  int copyIndex2;
  
  ch = 't';
  copyIndex = 0;
  do {
    *(char *)(outCursor + copyIndex) = ch;
    writeCursor = copyIndex + 1;
    ch = "texture["[copyIndex + 1];
    copyIndex = writeCursor;
  } while (ch != '\0');
  writeCursor = outCursor + writeCursor;
  if (indirectUnit == 0) {
    operandByteOffset = operandIndex * 8;
    copyEnd = ((int (*)())_ncpy_97be5f58)(writeCursor,*(uint *)(operandByteOffset + operands) & 0x1f);
    writeCursor = writeCursor + copyEnd;
  }
  else {
    writeCursor = ((int (*)())_glpWriteSourceOperand_97be7fc0)(operands,writeCursor,paramNumberMap,paramArrayMap,tempNumberMap,tempArrayMap,operandIndex,1,0);
    operandByteOffset = (operandIndex + 1) * 8;
  }
  ch = ']';
  copyIndex2 = 0;
  do {
    *(char *)(writeCursor + copyIndex2) = ch;
    nextIndex = copyIndex2 + 1;
    ch = "], "[copyIndex2 + 1];
    copyIndex2 = nextIndex;
  } while (ch != '\0');
  writeCursor = writeCursor + nextIndex;
  switch(*(uint *)(operandByteOffset + operands) >> 5 & 7) {
  case 0:
    ch = 'C';
    copyIndex = 0;
    do {
      *(char *)(writeCursor + copyIndex) = ch;
      copiedLength = copyIndex + 1;
      ch = "CUBE"[copyIndex + 1];
      copyIndex = copiedLength;
    } while (ch != '\0');
    break;
  case 1:
    ch = '3';
    copyIndex = 0;
    do {
      *(char *)(writeCursor + copyIndex) = ch;
      copiedLength = copyIndex + 1;
      ch = "3D"[copyIndex + 1];
      copyIndex = copiedLength;
    } while (ch != '\0');
    break;
  case 2:
    ch = 'R';
    copyIndex = 0;
    do {
      *(char *)(writeCursor + copyIndex) = ch;
      copiedLength = copyIndex + 1;
      ch = "RECT"[copyIndex + 1];
      copyIndex = copiedLength;
    } while (ch != '\0');
    break;
  case 3:
    ch = '2';
    copyIndex = 0;
    do {
      *(char *)(writeCursor + copyIndex) = ch;
      copiedLength = copyIndex + 1;
      ch = "2D"[copyIndex + 1];
      copyIndex = copiedLength;
    } while (ch != '\0');
    break;
  case 4:
    ch = '1';
    copyIndex = 0;
    do {
      *(char *)(writeCursor + copyIndex) = ch;
      copiedLength = copyIndex + 1;
      ch = "1D"[copyIndex + 1];
      copyIndex = copiedLength;
    } while (ch != '\0');
    break;
  case 5:
    ch = 'S';
    copyIndex = 0;
    do {
      *(char *)(writeCursor + copyIndex) = ch;
      copiedLength = copyIndex + 1;
      ch = "SHADOWRECT"[copyIndex + 1];
      copyIndex = copiedLength;
    } while (ch != '\0');
    break;
  case 6:
    ch = 'S';
    copyIndex = 0;
    do {
      *(char *)(writeCursor + copyIndex) = ch;
      copiedLength = copyIndex + 1;
      ch = "SHADOW2D"[copyIndex + 1];
      copyIndex = copiedLength;
    } while (ch != '\0');
    break;
  case 7:
    ch = 'S';
    copyIndex = 0;
    do {
      *(char *)(writeCursor + copyIndex) = ch;
      copiedLength = copyIndex + 1;
      ch = "SHADOW1D"[copyIndex + 1];
      copyIndex = copiedLength;
    } while (ch != '\0');
    break;
  default:
    goto switchD_97be857c_default;
  }
  writeCursor = writeCursor + copiedLength;
switchD_97be857c_default:
  return writeCursor;
}

/* _glpDisassemble1Op @ 0x97be8778 (4416 bytes) */
int _glpDisassemble1Op(inst, outText, outWordCount, outTextLength, paramNumbers, paramArrayPos, reserved7, reserved8, reserved9, indentDepth, printOptions)
  uint *inst;
  int outText;
  int *outWordCount;
  int *outTextLength;
  undefined4 paramNumbers;
  undefined4 paramArrayPos;
  undefined4 reserved7;
  undefined4 reserved8;
  undefined4 reserved9;
  int *indentDepth;
  uint printOptions;
{
  int lastSourceIndex;
  char *lineEnd;
  int sprintfLength;
  int copyIndex12;
  uint instWord1;
  int loopIndex;
  int outCursor;
  int copyIndex2;
  int copyIndex;
  int outCursor2;
  uint instWord0;
  char ch;
  uint branchWord;
  int indentCopyLength;
  int indentCopyIndex;
  undefined4 glpWritePrecisionResult;
  uint instWord1Copy;
  char *opMnemonic;
  int copyIndex4;
  int indentLevel;
  uint opcode;
  uint printSuffixes;
  int operandsPrinted;
  int outBase;
  undefined1 *textPtr;
  
  operandsPrinted = 0;
  instWord0 = *inst;
  indentLevel = *indentDepth;
  branchWord = inst[1];
  printSuffixes = printOptions & 0xff;
  opcode = instWord0 >> 0x12 & 0xff;
  loopIndex = 0;
  outBase = outText;
  if (0 < indentLevel) {
    do {
      indentCopyLength = 0;
      indentCopyIndex = indentCopyLength;
      ch = s__97c28c28[0];
      if (s__97c28c28[0] != '\0') {
        do {
          *(char *)(outBase + indentCopyIndex) = ch;
          indentCopyLength = indentCopyIndex + 1;
          ch = "  "[indentCopyIndex + 1];
          indentCopyIndex = indentCopyLength;
        } while (ch != '\0');
        indentLevel = *indentDepth;
      }
      loopIndex = loopIndex + 1;
      outBase = outBase + indentCopyLength;
    } while (loopIndex < indentLevel);
  }
  opMnemonic = *(char **)(&_ppstreamOpString + opcode * 4);
  copyIndex4 = 0;
  ch = *opMnemonic;
  while (ch != '\0') {
    *(char *)(outBase + copyIndex4) = ch;
    copyIndex4 = copyIndex4 + 1;
    ch = opMnemonic[copyIndex4];
  }
  textPtr = (undefined1 *)(outBase + copyIndex4);
  switch(opcode) {
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
    glpWritePrecisionResult = ((int (*)())_glpWritePrecision)(textPtr,inst[1] >> 0x12 & 3);
    instWord1Copy = inst[1];
    outCursor2 = ((int (*)())_glpWriteClampSat)(glpWritePrecisionResult,instWord1Copy >> 0x16 & 1,instWord1Copy >> 0x15 & 1,instWord1Copy >> 0x14 & 1);
    if (printSuffixes != 0) {
      instWord1Copy = inst[1];
      outCursor2 = ((int (*)())_glpWriteSizeType)(outCursor2,instWord1Copy >> 0x1a & 3,instWord1Copy >> 0x1c & 1,instWord1Copy >> 0x17 & 7);
    }
    copyIndex2 = 0;
    ch = s__97c291c0[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex2) = ch;
      ch = " "[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97be6730)(inst,outCursor2 + copyIndex2,reserved7,reserved8,1,printSuffixes);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    textPtr = (undefined1 *)
              ((int (*)())_glpWriteSourceOperand_97be7fc0)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,reserved7,reserved8,2,printSuffixes,0);
    operandsPrinted = 2;
    if (instWord0 >> 0x1d != 2) break;
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      textPtr[copyIndex] = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
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
    glpWritePrecisionResult = ((int (*)())_glpWritePrecision)(textPtr,inst[1] >> 0x12 & 3);
    instWord1 = inst[1];
    outCursor2 = ((int (*)())_glpWriteClampSat)(glpWritePrecisionResult,instWord1 >> 0x16 & 1,instWord1 >> 0x15 & 1,instWord1 >> 0x14 & 1);
    if (printSuffixes != 0) {
      instWord1 = inst[1];
      outCursor2 = ((int (*)())_glpWriteSizeType)(outCursor2,instWord1 >> 0x1a & 3,instWord1 >> 0x1c & 1,instWord1 >> 0x17 & 7);
    }
    copyIndex2 = 0;
    ch = s__97c291c0[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex2) = ch;
      ch = " "[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97be6730)(inst,outCursor2 + copyIndex2,reserved7,reserved8,1,printSuffixes);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    textPtr = (undefined1 *)
              ((int (*)())_glpWriteSourceOperand_97be7fc0)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,reserved7,reserved8,2,printSuffixes,0);
    operandsPrinted = 2;
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      textPtr[copyIndex] = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
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
    glpWritePrecisionResult = ((int (*)())_glpWritePrecision)(textPtr,inst[1] >> 0x12 & 3);
    instWord1 = inst[1];
    outCursor2 = ((int (*)())_glpWriteClampSat)(glpWritePrecisionResult,instWord1 >> 0x16 & 1,instWord1 >> 0x15 & 1,instWord1 >> 0x14 & 1);
    if (printSuffixes != 0) {
      instWord1 = inst[1];
      outCursor2 = ((int (*)())_glpWriteSizeType)(outCursor2,instWord1 >> 0x1a & 3,instWord1 >> 0x1c & 1,instWord1 >> 0x17 & 7);
    }
    copyIndex2 = 0;
    ch = s__97c291c0[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex2) = ch;
      ch = " "[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97be6730)(inst,outCursor2 + copyIndex2,reserved7,reserved8,1,printSuffixes);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97be7fc0)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,reserved7,reserved8,2,printSuffixes,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    operandsPrinted = 3;
    textPtr = (undefined1 *)
              ((int (*)())_glpWriteSourceOperand_97be7fc0)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,reserved7,reserved8,3,printSuffixes,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      textPtr[copyIndex] = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    goto LAB_97be9620;
  case 0x41:
    instWord1 = inst[1];
    outCursor2 = ((int (*)())_glpWriteClampSat)(textPtr,instWord1 >> 0x16 & 1,instWord1 >> 0x15 & 1,instWord1 >> 0x14 & 1);
    if (printSuffixes != 0) {
      instWord1 = inst[1];
      outCursor2 = ((int (*)())_glpWriteSizeType)(outCursor2,instWord1 >> 0x1a & 3,instWord1 >> 0x1c & 1,instWord1 >> 0x17 & 7);
    }
    copyIndex2 = 0;
    ch = s__97c291c0[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex2) = ch;
      ch = " "[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97be6730)(inst,outCursor2 + copyIndex2,reserved7,reserved8,1,printSuffixes);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    textPtr = (undefined1 *)
              ((int (*)())_glpWriteSourceOperand_97be7fc0)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,reserved7,reserved8,2,printSuffixes,1);
    operandsPrinted = 3;
    break;
  case 0x42:
  case 0x43:
    instWord1 = inst[1];
    outCursor2 = ((int (*)())_glpWriteClampSat)(textPtr,instWord1 >> 0x16 & 1,instWord1 >> 0x15 & 1,instWord1 >> 0x14 & 1);
    if (printSuffixes != 0) {
      instWord1 = inst[1];
      outCursor2 = ((int (*)())_glpWriteSizeType)(outCursor2,instWord1 >> 0x1a & 3,instWord1 >> 0x1c & 1,instWord1 >> 0x17 & 7);
    }
    copyIndex2 = 0;
    ch = s__97c291c0[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex2) = ch;
      ch = " "[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97be6730)(inst,outCursor2 + copyIndex2,reserved7,reserved8,1,printSuffixes);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97be7fc0)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,reserved7,reserved8,2,printSuffixes,0);
    lastSourceIndex = 2;
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    goto LAB_97be9848;
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x47:
    instWord1 = inst[1];
    outCursor2 = ((int (*)())_glpWriteClampSat)(textPtr,instWord1 >> 0x16 & 1,instWord1 >> 0x15 & 1,instWord1 >> 0x14 & 1);
    if (printSuffixes != 0) {
      instWord1 = inst[1];
      outCursor2 = ((int (*)())_glpWriteSizeType)(outCursor2,instWord1 >> 0x1a & 3,instWord1 >> 0x1c & 1,instWord1 >> 0x17 & 7);
    }
    copyIndex2 = 0;
    ch = s__97c291c0[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex2) = ch;
      ch = " "[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97be6730)(inst,outCursor2 + copyIndex2,reserved7,reserved8,1,printSuffixes);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97be7fc0)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,reserved7,reserved8,2,printSuffixes,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    textPtr = (undefined1 *)
              ((int (*)())_glpWriteTextureOperand_97be8478)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,reserved7,reserved8,3,printSuffixes);
    operandsPrinted = 3 - ((int)-printSuffixes >> 0x1f);
    if (printSuffixes == 0) break;
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      textPtr[copyIndex] = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
LAB_97be9620:
    operandsPrinted = operandsPrinted + 1;
    textPtr = (undefined1 *)
              ((int (*)())_glpWriteSourceOperand_97be7fc0)(inst,textPtr + copyIndex,paramNumbers,paramArrayPos,reserved7,reserved8,operandsPrinted,printSuffixes,0);
    break;
  case 0x48:
  case 0x49:
  case 0x4a:
    if (printSuffixes != 0) {
      instWord1 = inst[1];
      textPtr = (undefined1 *)
                ((int (*)())_glpWriteSizeType)(textPtr,instWord1 >> 0x1a & 3,instWord1 >> 0x1c & 1,instWord1 >> 0x17 & 7);
    }
    copyIndex = 0;
    ch = s__97c291c0[0];
    while (ch != '\0') {
      textPtr[copyIndex] = ch;
      ch = " "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteAddressOperand)(inst,textPtr + copyIndex,1,printSuffixes);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
LAB_97be9928:
    textPtr = (undefined1 *)(outCursor + copyIndex);
    goto LAB_97be99b4;
  case 0x4b:
  case 0x4c:
    copyIndex = 0;
    ch = s__97c291c0[0];
    while (ch != '\0') {
      textPtr[copyIndex] = ch;
      ch = " "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    textPtr = (undefined1 *)
              ((int (*)())_glpWriteBranchOperand)(inst,textPtr + copyIndex,reserved9,1,(uint)(opcode == 0x4b));
  case 0x4d:
  case 0x54:
  case 0x59:
  case 0x5a:
  case 0x5b:
  case 0x69:
  case 0x6b:
  case 0x6e:
LAB_97be8e48:
    operandsPrinted = 1;
    break;
  case 0x4f:
    copyIndex = 0;
    ch = s__97c291c0[0];
    while (ch != '\0') {
      textPtr[copyIndex] = ch;
      ch = " "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    goto LAB_97be9988;
  case 0x55:
    *indentDepth = *indentDepth + 1;
    if (printSuffixes != 0) {
      instWord1 = inst[1];
      outCursor = ((int (*)())_glpWriteSizeType)(textPtr,instWord1 >> 0x1a & 3,instWord1 >> 0x1c & 1,instWord1 >> 0x17 & 7);
      copyIndex = 0;
      ch = s__97c291c0[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = " "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      goto LAB_97be9928;
    }
    operandsPrinted = 1;
    switch(inst[2] >> 0x1c & 7) {
    case 0:
      copyIndex12 = 0;
      ch = s_TR_97c2d864[0];
      while (ch != '\0') {
        textPtr[copyIndex12] = ch;
        ch = " TR"[copyIndex12 + 1];
        copyIndex12 = copyIndex12 + 1;
      }
      break;
    case 1:
      copyIndex12 = 0;
      ch = s_EQ_97c2d868[0];
      while (ch != '\0') {
        textPtr[copyIndex12] = ch;
        ch = " EQ"[copyIndex12 + 1];
        copyIndex12 = copyIndex12 + 1;
      }
      break;
    case 2:
      copyIndex12 = 0;
      ch = s_GE_97c2d86c[0];
      while (ch != '\0') {
        textPtr[copyIndex12] = ch;
        ch = " GE"[copyIndex12 + 1];
        copyIndex12 = copyIndex12 + 1;
      }
      break;
    case 3:
      copyIndex12 = 0;
      ch = s_GT_97c2d870[0];
      while (ch != '\0') {
        textPtr[copyIndex12] = ch;
        ch = " GT"[copyIndex12 + 1];
        copyIndex12 = copyIndex12 + 1;
      }
      break;
    case 4:
      copyIndex12 = 0;
      ch = s_LE_97c2d874[0];
      while (ch != '\0') {
        textPtr[copyIndex12] = ch;
        ch = " LE"[copyIndex12 + 1];
        copyIndex12 = copyIndex12 + 1;
      }
      break;
    case 5:
      copyIndex12 = 0;
      ch = s_LT_97c2d878[0];
      while (ch != '\0') {
        textPtr[copyIndex12] = ch;
        ch = " LT"[copyIndex12 + 1];
        copyIndex12 = copyIndex12 + 1;
      }
      break;
    case 6:
      copyIndex12 = 0;
      ch = s_NE_97c2d87c[0];
      while (ch != '\0') {
        textPtr[copyIndex12] = ch;
        ch = " NE"[copyIndex12 + 1];
        copyIndex12 = copyIndex12 + 1;
      }
      break;
    case 7:
      copyIndex12 = 0;
      ch = s_FL_97c2d880[0];
      while (ch != '\0') {
        textPtr[copyIndex12] = ch;
        ch = " FL"[copyIndex12 + 1];
        copyIndex12 = copyIndex12 + 1;
      }
      break;
    default:
      goto switchD_97be8b04_default;
    }
    textPtr = textPtr + copyIndex12;
switchD_97be8b04_default:
    if ((int)inst[2] < 0) {
      *textPtr = 0x31;
      textPtr = textPtr + 1;
    }
    *textPtr = 0x2e;
    textPtr[1] = (((byte)(inst[2] >> 0x1a) & 3) + 1 & 3) + 0x77;
    textPtr[2] = ((*(byte *)(inst + 2) & 3) + 1 & 3) + 0x77;
    textPtr[3] = (((byte)(inst[2] >> 0x16) & 3) + 1 & 3) + 0x77;
    textPtr[4] = (((byte)(inst[2] >> 0x14) & 3) + 1 & 3) + 0x77;
    textPtr = textPtr + 5;
    break;
  case 0x56:
  case 0x57:
    *indentDepth = *indentDepth + 1;
    copyIndex = 0;
    ch = s__97c291c0[0];
    while (ch != '\0') {
      textPtr[copyIndex] = ch;
      ch = " "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    goto LAB_97be9988;
  case 0x58:
  case 0x6a:
    *indentDepth = *indentDepth + 1;
    goto LAB_97be8e48;
  case 0x60:
  case 0x61:
    copyIndex = 0;
    ch = s__97c291c0[0];
    while (ch != '\0') {
      textPtr[copyIndex] = ch;
      ch = " "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
LAB_97be9988:
    textPtr = textPtr + copyIndex;
LAB_97be99b4:
    textPtr = (undefined1 *)
              ((int (*)())_glpWriteSourceOperand_97be7fc0)(inst,textPtr,paramNumbers,paramArrayPos,reserved7,reserved8,2,printSuffixes,0);
    operandsPrinted = 2;
    break;
  case 0x62:
    instWord1 = inst[1];
    outCursor2 = ((int (*)())_glpWriteClampSat)(textPtr,instWord1 >> 0x16 & 1,instWord1 >> 0x15 & 1,instWord1 >> 0x14 & 1);
    if (printSuffixes != 0) {
      instWord1 = inst[1];
      outCursor2 = ((int (*)())_glpWriteSizeType)(outCursor2,instWord1 >> 0x1a & 3,instWord1 >> 0x1c & 1,instWord1 >> 0x17 & 7);
    }
    copyIndex2 = 0;
    ch = s__97c291c0[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex2) = ch;
      ch = " "[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97be6730)(inst,outCursor2 + copyIndex2,reserved7,reserved8,1,printSuffixes);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97be7fc0)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,reserved7,reserved8,2,printSuffixes,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97be7fc0)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,reserved7,reserved8,3,printSuffixes,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    lastSourceIndex = 4;
    outCursor = ((int (*)())_glpWriteSourceOperand_97be7fc0)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,reserved7,reserved8,4,printSuffixes,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
LAB_97be9848:
    textPtr = (undefined1 *)
              ((int (*)())_glpWriteTextureOperand_97be8478)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,reserved7,reserved8,lastSourceIndex + 1,printSuffixes);
    operandsPrinted = (lastSourceIndex + 1) - ((int)-printSuffixes >> 0x1f);
  }
  copyIndex = 0;
  ch = s___97c2d884[0];
  while (ch != '\0') {
    textPtr[copyIndex] = ch;
    ch = ";"[copyIndex + 1];
    copyIndex = copyIndex + 1;
  }
  lineEnd = textPtr + copyIndex;
  if (printSuffixes != 0) {
    switch(opcode) {
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
      sprintfLength = _sprintf(lineEnd,"    # Target: %d",branchWord & 0x3ffff);
      lineEnd = lineEnd + sprintfLength;
    }
  }
  copyIndex = 0;
  ch = s__97c26c38[0];
  while (ch != '\0') {
    lineEnd[copyIndex] = ch;
    ch = "\n"[copyIndex + 1];
    copyIndex = copyIndex + 1;
  }
  *outWordCount = operandsPrinted;
  *outTextLength = (int)(lineEnd + (copyIndex - outText));
  return;
}

/* _isTempArrayStart @ 0x97be9b20 (96 bytes) */
int _isTempArrayStart(program, startRegister, arraySize)
  int program;
  uint startRegister;
  uint *arraySize;
{
  int arrayTable;
  int entryIndex;
  int arrayCount;
  
  arrayCount = *(int *)(program + 0x40);
  arrayTable = program + *(int *)(program + 0x44) * 8;
  if ((arrayCount != 0) && (entryIndex = 0, 0 < arrayCount)) {
    do {
      if ((*(uint *)(arrayTable + entryIndex * 8) & 0xffff) == startRegister) {
        *arraySize = (uint)*(ushort *)(entryIndex * 8 + arrayTable + 6);
        return 1;
      }
      entryIndex = entryIndex + 1;
    } while (entryIndex < arrayCount);
  }
  return 0;
}

/* _isParamArrayStart_97be9b80 @ 0x97be9b80 (96 bytes) */
int _isParamArrayStart_97be9b80(program, startRegister, arraySize)
  int program;
  uint startRegister;
  uint *arraySize;
{
  int arrayTable;
  int entryIndex;
  int arrayCount;
  
  arrayCount = *(int *)(program + 0x38);
  arrayTable = program + *(int *)(program + 0x3c) * 8;
  if ((arrayCount != 0) && (entryIndex = 0, 0 < arrayCount)) {
    do {
      if ((*(uint *)(arrayTable + entryIndex * 8) & 0xffff) == startRegister) {
        *arraySize = (uint)*(ushort *)(entryIndex * 8 + arrayTable + 6);
        return 1;
      }
      entryIndex = entryIndex + 1;
    } while (entryIndex < arrayCount);
  }
  return 0;
}

/* _InsertLabel @ 0x97be9be0 (212 bytes) */
int _InsertLabel(keys, values, newKey, newValue, count)
  int *keys;
  int values;
  int newKey;
  undefined4 newValue;
  int count;
{
  int shiftIndex;
  int loopIndex;
  bool appendAtEnd;
  int byteOffset;
  int shiftCount;
  undefined4 displacedValue;
  undefined4 carriedValue;
  int *keyCursor;
  int displacedKey;
  int nextIndex;
  int carriedKey;
  int newCount;
  
  loopIndex = 0;
  if ((count < 1) || (keyCursor = keys, newKey <= *keys)) {
    appendAtEnd = count == 0;
    byteOffset = 0;
  }
  else {
    do {
      loopIndex = loopIndex + 1;
      appendAtEnd = loopIndex == count;
      if (count <= loopIndex) {
        byteOffset = loopIndex * 4;
        break;
      }
      keyCursor = keyCursor + 1;
      byteOffset = loopIndex * 4;
    } while (*keyCursor < newKey);
  }
  if (appendAtEnd) {
    *(int *)(byteOffset + (int)keys) = newKey;
    *(undefined4 *)(byteOffset + values) = newValue;
    newCount = count + 1;
  }
  else {
    displacedKey = *(int *)(byteOffset + (int)keys);
    newCount = count;
    if (displacedKey != newKey) {
      nextIndex = loopIndex + 1;
      *(int *)(byteOffset + (int)keys) = newKey;
      displacedValue = *(undefined4 *)(byteOffset + values);
      *(undefined4 *)(byteOffset + values) = newValue;
      newCount = count + 1;
      if (nextIndex < count) {
        shiftCount = count - nextIndex;
        carriedValue = displacedValue;
        shiftIndex = nextIndex;
        carriedKey = displacedKey;
        do {
          nextIndex = shiftIndex + 1;
          displacedKey = keys[shiftIndex];
          keys[shiftIndex] = carriedKey;
          displacedValue = *(undefined4 *)(values + shiftIndex * 4);
          *(undefined4 *)(values + shiftIndex * 4) = carriedValue;
          shiftCount = shiftCount + -1;
          carriedValue = displacedValue;
          shiftIndex = nextIndex;
          carriedKey = displacedKey;
        } while (shiftCount != 0);
      }
      keys[nextIndex] = displacedKey;
      *(undefined4 *)(values + nextIndex * 4) = displacedValue;
    }
  }
  return newCount;
}

/* _adjustAllocation_97be9cb4 @ 0x97be9cb4 (124 bytes) */
int _adjustAllocation_97be9cb4(capacityPtr, bufferPtr, cursorPtr)
  int *capacityPtr;
  int *bufferPtr;
  int *cursorPtr;
{
  int allocation;
  int oldBuffer;
  int newCapacity;
  int oldCursor;
  
  oldBuffer = *bufferPtr;
  oldCursor = *cursorPtr;
  if (*capacityPtr - (oldCursor - oldBuffer) < 0x100) {
    newCapacity = *capacityPtr + 0x800;
    *capacityPtr = newCapacity;
    allocation = _realloc(*bufferPtr,newCapacity);
    *cursorPtr = allocation;
    if (allocation == 0) {
      return 0;
    }
    *bufferPtr = allocation;
    *cursorPtr = allocation + (oldCursor - oldBuffer);
  }
  return 1;
}

/* _glpPPDisassemble @ 0x97be9d30 (27772 bytes) */
int _glpPPDisassemble(program)
  uint *program;
{
  undefined4 memsetResult;
  uint loopIndex10;
  uint *nextIndex5;
  int loopIndex5;
  int nextIndex4;
  int allocation2;
  int nextIndex2;
  int nextIndex;
  int loopIndex4;
  uint stateOffset;
  uint programTarget;
  uint stateCount;
  uint instructionOffset;
  uint outputOffset;
  uint paramCount;
  uint attribOffset;
  uint addressRegCount;
  uint optionsOffset;
  uint instructionCount;
  uint outputCount;
  uint attribCount;
  uint tempCount;
  uint optionCount;
  int copyIndex5;
  int copyIndex6;
  int copyEnd3;
  int copyEnd4;
  int copyEnd2;
  int copyEnd;
  int loopIndex2;
  int loopIndex;
  int loopIndex3;
  int copyIndex2;
  int copyLength3;
  int copyIndex4;
  int copyLength4;
  int copyIndex3;
  int copyLength;
  int copyIndex;
  int copyLength2;
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
  int nextIndex3;
  int copyLength5;
  int *piVar15;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 uVar16;
  undefined4 extraout_r3_01;
  void *allocation;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 extraout_r4_03;
  undefined4 extraout_r4_04;
  undefined4 extraout_r4_05;
  undefined4 extraout_r4_06;
  undefined4 extraout_r4_07;
  undefined1 *outBytePtr;
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
  uint registerId;
  uint paramRegisterId;
  int indentDepth;
  int outWordCount;
  int outTextLength;
  int arrayIndex;
  int elementInArray;
  int paramNumbers;
  int paramArrayPos;
  int tempNumbers;
  int tempArrayPos;
  int *arraySizes;
  int labelIds;
  int labelValues;
  int labelCount;
  int nextLabelNumber;
  uint printOptions;
  char *dataBase;
  int cr0Image;
  int cr0Image2;
  
  outBufCapacity = 0x800;
  indentDepth = 1;
  outBuf = (int *)_malloc(0x800);
  uVar26 = CONCAT44(outBuf,extraout_r4);
  arrayIndex = 0;
  paramNumbers = 0;
  paramArrayPos = 0;
  tempNumbers = 0;
  tempArrayPos = 0;
  arraySizes = (int *)0x0;
  labelIds = 0;
  labelValues = 0;
  labelCount = 0;
  nextLabelNumber = 0;
  if (outBuf == (int *)0x0) {
    return (void *)0x0;
  }
  programTarget = *program;
  printOptions = (uint)(programTarget - 0x8b30 < 2);
  if (programTarget == 0x8804) {
    ch = '!';
    copyIndex4 = 0;
    do {
      *(char *)((int)outBuf + copyIndex4) = ch;
      copyLength3 = copyIndex4 + 1;
      ch = "!!ARBfp1.0\n"[copyIndex4 + 1];
      copyIndex4 = copyLength3;
    } while (ch != '\0');
  }
  else if (programTarget < 0x8805) {
    if (programTarget == 0x8620) {
      ch = '!';
      copyIndex4 = 0;
      do {
        *(char *)((int)outBuf + copyIndex4) = ch;
        copyLength3 = copyIndex4 + 1;
        ch = "!!ARBvp1.0\n"[copyIndex4 + 1];
        copyIndex4 = copyLength3;
      } while (ch != '\0');
    }
    else {
LAB_97be9f08:
      ch = 'U';
      copyIndex4 = 0;
      do {
        *(char *)((int)outBuf + copyIndex4) = ch;
        copyLength3 = copyIndex4 + 1;
        ch = "Unkown Target (error)\n"[copyIndex4 + 1];
        copyIndex4 = copyLength3;
      } while (ch != '\0');
    }
  }
  else if (programTarget == 0x8b30) {
    ch = '!';
    copyIndex4 = 0;
    do {
      *(char *)((int)outBuf + copyIndex4) = ch;
      copyLength3 = copyIndex4 + 1;
      ch = "!!ARBfragmentshader\n"[copyIndex4 + 1];
      copyIndex4 = copyLength3;
    } while (ch != '\0');
  }
  else {
    if (programTarget != 0x8b31) goto LAB_97be9f08;
    ch = '!';
    copyIndex4 = 0;
    do {
      *(char *)((int)outBuf + copyIndex4) = ch;
      copyLength3 = copyIndex4 + 1;
      ch = "!!ARBvertexshader\n"[copyIndex4 + 1];
      copyIndex4 = copyLength3;
    } while (ch != '\0');
  }
  outCursor = (int *)((int)outBuf + copyLength3);
  bVar2 = printOptions == 0;
  if (!bVar2) {
    ch = '\n';
    copyIndex4 = 0;
    do {
      *(char *)((int)outCursor + copyIndex4) = ch;
      copyLength3 = copyIndex4 + 1;
      ch = "\n"[copyIndex4 + 1];
      copyIndex4 = copyLength3;
    } while (ch != '\0');
    outCursor = (int *)((int)outCursor + copyLength3);
  }
  optionCount = program[0x12];
  loopIndex = 0;
  optionsOffset = program[0x13];
  if (0 < (int)optionCount) {
    dataBase = "o intialize the Preprocessor";
    do {
      ch = 'O';
      copyIndex2 = 0;
      do {
        *(char *)((int)outCursor + copyIndex2) = ch;
        copyLength2 = copyIndex2 + 1;
        ch = "OPTION "[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      outBytePtr = (undefined1 *)((int)outCursor + copyLength2);
      switch(program[optionsOffset * 2 + loopIndex * 2] & 0xff) {
      case 0:
        ch = 'A';
        copyIndex2 = 0;
        do {
          outBytePtr[copyIndex2] = ch;
          copyLength2 = copyIndex2 + 1;
          ch = "ARB_position_invariant"[copyIndex2 + 1];
          copyIndex2 = copyLength2;
        } while (ch != '\0');
        break;
      case 1:
        ch = 'A';
        copyIndex2 = 0;
        do {
          outBytePtr[copyIndex2] = ch;
          copyLength2 = copyIndex2 + 1;
          ch = "ARB_fog_exp"[copyIndex2 + 1];
          copyIndex2 = copyLength2;
        } while (ch != '\0');
        break;
      case 2:
        ch = 'A';
        copyIndex2 = 0;
        do {
          outBytePtr[copyIndex2] = ch;
          copyLength2 = copyIndex2 + 1;
          ch = "ARB_fog_exp2"[copyIndex2 + 1];
          copyIndex2 = copyLength2;
        } while (ch != '\0');
        break;
      case 3:
        ch = 'A';
        copyIndex2 = 0;
        do {
          outBytePtr[copyIndex2] = ch;
          copyLength2 = copyIndex2 + 1;
          ch = "ARB_fog_linear"[copyIndex2 + 1];
          copyIndex2 = copyLength2;
        } while (ch != '\0');
        break;
      case 4:
        ch = 'A';
        copyIndex2 = 0;
        do {
          outBytePtr[copyIndex2] = ch;
          copyLength2 = copyIndex2 + 1;
          ch = "ARB_precision_hint_fastest"[copyIndex2 + 1];
          copyIndex2 = copyLength2;
        } while (ch != '\0');
        break;
      case 5:
        ch = 'A';
        copyIndex2 = 0;
        do {
          outBytePtr[copyIndex2] = ch;
          copyLength2 = copyIndex2 + 1;
          ch = "ARB_precision_hint_nicest"[copyIndex2 + 1];
          copyIndex2 = copyLength2;
        } while (ch != '\0');
        break;
      case 6:
        ch = 'A';
        copyIndex2 = 0;
        do {
          outBytePtr[copyIndex2] = ch;
          copyLength2 = copyIndex2 + 1;
          ch = "APPLE_no_runtime_compile"[copyIndex2 + 1];
          copyIndex2 = copyLength2;
        } while (ch != '\0');
        break;
      case 7:
        ch = 'A';
        copyIndex2 = 0;
        do {
          outBytePtr[copyIndex2] = ch;
          copyLength2 = copyIndex2 + 1;
          ch = "APPLE_no_altivec"[copyIndex2 + 1];
          copyIndex2 = copyLength2;
        } while (ch != '\0');
        break;
      case 8:
        ch = 'N';
        copyIndex2 = 0;
        do {
          outBytePtr[copyIndex2] = ch;
          copyLength2 = copyIndex2 + 1;
          ch = "NV_fragment_program"[copyIndex2 + 1];
          copyIndex2 = copyLength2;
        } while (ch != '\0');
        break;
      case 9:
        ch = 'N';
        copyIndex2 = 0;
        do {
          outBytePtr[copyIndex2] = ch;
          copyLength2 = copyIndex2 + 1;
          ch = "NV_fragment_program2"[copyIndex2 + 1];
          copyIndex2 = copyLength2;
        } while (ch != '\0');
        break;
      case 10:
        ch = 'N';
        copyIndex2 = 0;
        do {
          outBytePtr[copyIndex2] = ch;
          copyLength2 = copyIndex2 + 1;
          ch = "NV_vertex_program2"[copyIndex2 + 1];
          copyIndex2 = copyLength2;
        } while (ch != '\0');
        break;
      case 0xb:
        ch = 'N';
        copyIndex2 = 0;
        do {
          outBytePtr[copyIndex2] = ch;
          copyLength2 = copyIndex2 + 1;
          ch = "NV_vertex_program3"[copyIndex2 + 1];
          copyIndex2 = copyLength2;
        } while (ch != '\0');
        break;
      case 0xc:
        ch = 'A';
        copyIndex2 = 0;
        do {
          outBytePtr[copyIndex2] = ch;
          copyLength2 = copyIndex2 + 1;
          ch = "ARB_draw_buffers"[copyIndex2 + 1];
          copyIndex2 = copyLength2;
        } while (ch != '\0');
        break;
      case 0xd:
        ch = 'A';
        copyIndex2 = 0;
        do {
          outBytePtr[copyIndex2] = ch;
          copyLength2 = copyIndex2 + 1;
          ch = "ARB_fragment_program_shadow"[copyIndex2 + 1];
          copyIndex2 = copyLength2;
        } while (ch != '\0');
        break;
      default:
        goto switchD_97bea038_default;
      }
      outBytePtr = outBytePtr + copyLength2;
switchD_97bea038_default:
      copyIndex5 = 0;
      ch = dataBase[0x3bbc];
      while (ch != '\0') {
        outBytePtr[copyIndex5] = ch;
        copyIndex5 = copyIndex5 + 1;
        ch = (dataBase + 0x3bbc)[copyIndex5];
      }
      outCursor = (int *)(outBytePtr + copyIndex5);
      uVar26 = ((int (*)())_adjustAllocation_97be9cb4)(&outBufCapacity,&outBuf,&outCursor);
      if ((int)((ulonglong)uVar26 >> 0x20) == 0) goto LAB_97bf0cec;
      loopIndex = loopIndex + 1;
    } while (loopIndex < (int)optionCount);
  }
  if ((optionCount != 0) && (!bVar2)) {
    ch = '\n';
    copyIndex4 = 0;
    do {
      *(char *)((int)outCursor + copyIndex4) = ch;
      copyLength3 = copyIndex4 + 1;
      ch = "\n"[copyIndex4 + 1];
      copyIndex4 = copyLength3;
    } while (ch != '\0');
    outCursor = (int *)((int)outCursor + copyLength3);
  }
  addressRegCount = program[6];
  if (addressRegCount != 0) {
    ch = 'A';
    copyIndex4 = 0;
    do {
      *(char *)((int)outCursor + copyIndex4) = ch;
      copyLength3 = copyIndex4 + 1;
      ch = "ADDRESS adr0"[copyIndex4 + 1];
      copyIndex4 = copyLength3;
    } while (ch != '\0');
    iVar22 = 1;
    outBytePtr = (undefined1 *)((int)outCursor + copyLength3);
    if (1 < (int)addressRegCount) {
      do {
        ch = ',';
        copyIndex2 = 0;
        do {
          outBytePtr[copyIndex2] = ch;
          copyLength2 = copyIndex2 + 1;
          ch = ", adr"[copyIndex2 + 1];
          copyIndex2 = copyLength2;
        } while (ch != '\0');
        outCursor = (int *)(outBytePtr + copyLength2);
        nextIndex4 = iVar22 + 1;
        copyEnd4 = ((int (*)())_ncpy_97be5f58)(outCursor,iVar22);
        outBytePtr = (undefined1 *)((int)outCursor + copyEnd4);
        iVar22 = nextIndex4;
      } while (nextIndex4 < (int)addressRegCount);
    }
    ch = ';';
    copyIndex4 = 0;
    do {
      outBytePtr[copyIndex4] = ch;
      copyLength3 = copyIndex4 + 1;
      ch = ";\n"[copyIndex4 + 1];
      copyIndex4 = copyLength3;
    } while (ch != '\0');
    outCursor = (int *)(outBytePtr + copyLength3);
    uVar26 = ((int (*)())_adjustAllocation_97be9cb4)(&outBufCapacity,&outBuf,&outCursor);
    if ((int)((ulonglong)uVar26 >> 0x20) == 0) goto LAB_97bf0cec;
    if (!bVar2) {
      ch = '\n';
      copyIndex4 = 0;
      do {
        *(char *)((int)outCursor + copyIndex4) = ch;
        copyLength3 = copyIndex4 + 1;
        ch = "\n"[copyIndex4 + 1];
        copyIndex4 = copyLength3;
      } while (ch != '\0');
      outCursor = (int *)((int)outCursor + copyLength3);
    }
  }
  uVar16 = (undefined4)uVar26;
  uVar6 = 0;
  bVar3 = true;
  tempCount = program[4];
  puVar21 = program + program[5] * 2;
  if (!bVar2) {
    uVar23 = 0xffffffff;
    if ((int)tempCount < 1) {
LAB_97bea680:
      cr0Image = (uint)(byte)((tempNumbers < 0) << 3 | (0 < tempNumbers) << 2 | (tempNumbers == 0) << 1 |
                             in_xer_so & 1) << 0x1c;
      cr0Image2 = cr0Image;
LAB_97bea698:
      arraySizes = (int *)0x0;
      if (program[0x10] != 0) {
        arraySizes = (int *)_malloc(program[0x10] << 2);
        uVar16 = extraout_r4_01;
      }
      uVar26 = CONCAT44(arraySizes,uVar16);
      loopIndex = 0;
      iVar9 = -1;
      registerId = 0xffffffff;
      uVar23 = 0xffffffff;
      if (0 < (int)tempCount) {
        iVar10 = 0;
        piVar15 = arraySizes;
        puVar11 = puVar21;
        do {
          if (uVar23 == 0xffffffff) {
            *(uint *)((uint)*(ushort *)((int)puVar11 + 6) * 4 + tempNumbers) =
                 (uint)*(ushort *)((int)puVar11 + 6);
            uVar26 = ((int (*)())_isTempArrayStart)(program,(uint)*(ushort *)((int)puVar11 + 6),&registerId);
            if ((int)((ulonglong)uVar26 >> 0x20) == 0) {
              *(int *)(tempArrayPos + (uint)*(ushort *)((int)puVar11 + 6) * 4) = iVar9;
            }
            else {
              uVar23 = (uint)*(ushort *)((int)puVar11 + 6);
              *(undefined4 *)(tempArrayPos + uVar23 * 4) = 0;
              iVar9 = 1;
            }
            bVar1 = *(ushort *)((int)puVar21 + iVar10 + 6) == registerId;
LAB_97bea790:
            if (bVar1) {
              registerId = 0xffffffff;
              uVar23 = 0xffffffff;
              *piVar15 = iVar9;
              piVar15 = piVar15 + 1;
              iVar9 = -1;
            }
          }
          else if ((int)(uint)*(ushort *)((int)puVar11 + 6) <= (int)registerId) {
            *(uint *)((uint)*(ushort *)((int)puVar11 + 6) * 4 + tempNumbers) = uVar23;
            *(int *)(tempArrayPos + (uint)*(ushort *)((int)puVar11 + 6) * 4) = iVar9;
            iVar9 = iVar9 + 1;
            bVar1 = *(ushort *)((int)puVar11 + 6) == registerId;
            goto LAB_97bea790;
          }
          loopIndex = loopIndex + 1;
          iVar10 = iVar10 + 8;
          puVar11 = puVar11 + 2;
        } while (loopIndex < (int)tempCount);
      }
      arrayIndex = 0;
      goto LAB_97bea7e0;
    }
    puVar11 = puVar21 + 1;
    uVar25 = tempCount;
    do {
      uVar7 = *puVar11;
      puVar11 = puVar11 + 2;
      if ((int)uVar23 < (int)(uVar7 & 0xffff)) {
        uVar23 = uVar7 & 0xffff;
      }
      uVar25 = uVar25 - 1;
    } while (uVar25 != 0);
    if (uVar23 == 0xffffffff) goto LAB_97bea680;
    allocation2 = uVar23 * 4 + 4;
    tempNumbers = _malloc(allocation2);
    cr0Image = (uint)(byte)((tempNumbers < 0) << 3 | (0 < tempNumbers) << 2 | (tempNumbers == 0) << 1 |
                           in_xer_so & 1) << 0x1c;
    tempArrayPos = _malloc(allocation2);
    bVar5 = (byte)((uint)cr0Image >> 0x18);
    if (!(bool)(bVar5 >> 5 & 1)) {
      cr0Image2 = (uint)(byte)((tempArrayPos < 0) << 3 | (0 < tempArrayPos) << 2 | (tempArrayPos == 0) << 1 |
                             in_xer_so & 1) << 0x1c;
      uVar16 = extraout_r4_00;
      if (tempArrayPos == 0) goto joined_r0x97bea678;
      goto LAB_97bea698;
    }
    cr0Image2 = (uint)(byte)((tempArrayPos < 0) << 3 | (0 < tempArrayPos) << 2 | (tempArrayPos == 0) << 1 |
                           in_xer_so & 1) << 0x1c;
joined_r0x97bea678:
    if (!(bool)(bVar5 >> 5 & 1)) {
      _free(tempNumbers);
    }
    iVar22 = tempArrayPos;
    if (!(bool)((byte)((uint)cr0Image2 >> 0x1d) & 1)) {
LAB_97bee10c:
      _free(iVar22);
    }
LAB_97bf0cec:
    _free(outBuf);
    return (void *)0x0;
  }
  cr0Image = (uint)(byte)((tempNumbers < 0) << 3 | (0 < tempNumbers) << 2 | (tempNumbers == 0) << 1 |
                         in_xer_so & 1) << 0x1c;
  cr0Image2 = cr0Image;
LAB_97bea7e0:
  loopIndex10 = 0;
  elementInArray = -1;
  if (0 < (int)tempCount) {
    do {
      iVar22 = loopIndex10 * 8;
      if (bVar3) {
        uVar6 = puVar21[loopIndex10 * 2] >> 0x1d;
        if (uVar6 == 1) {
          ch = 'L';
          copyIndex2 = 0;
          do {
            *(char *)((int)outCursor + copyIndex2) = ch;
            copyLength2 = copyIndex2 + 1;
            ch = "LONG TEMP "[copyIndex2 + 1];
            copyIndex2 = copyLength2;
          } while (ch != '\0');
LAB_97bea920:
          outCursor = (int *)((int)outCursor + copyLength2);
        }
        else if (uVar6 < 2) {
          if (uVar6 == 0) {
            ch = 'T';
            copyIndex2 = 0;
            do {
              *(char *)((int)outCursor + copyIndex2) = ch;
              copyLength2 = copyIndex2 + 1;
              ch = "TEMP "[copyIndex2 + 1];
              copyIndex2 = copyLength2;
            } while (ch != '\0');
            goto LAB_97bea920;
          }
        }
        else if (uVar6 == 2) {
          ch = 'S';
          copyIndex2 = 0;
          do {
            *(char *)((int)outCursor + copyIndex2) = ch;
            copyLength2 = copyIndex2 + 1;
            ch = "SHORT TEMP "[copyIndex2 + 1];
            copyIndex2 = copyLength2;
          } while (ch != '\0');
          goto LAB_97bea920;
        }
        bVar3 = false;
        uVar6 = puVar21[loopIndex10 * 2] >> 0x1d;
      }
      if (bVar2) {
        ch = 't';
        copyIndex2 = 0;
        do {
          *(char *)((int)outCursor + copyIndex2) = ch;
          copyLength2 = copyIndex2 + 1;
          ch = "tmp"[copyIndex2 + 1];
          copyIndex2 = copyLength2;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + copyLength2);
        copyEnd4 = ((int (*)())_ncpy_97be5f58)(outCursor,(uint)*(ushort *)((int)puVar21 + iVar22 + 6));
        outCursor = (int *)((int)outCursor + copyEnd4);
      }
      else {
        iVar9 = *(int *)(tempArrayPos + (uint)*(ushort *)((int)puVar21 + iVar22 + 6) * 4);
        if (iVar9 == -1) {
          ch = 't';
          copyIndex2 = 0;
          do {
            *(char *)((int)outCursor + copyIndex2) = ch;
            copyLength2 = copyIndex2 + 1;
            ch = "tmp"[copyIndex2 + 1];
            copyIndex2 = copyLength2;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + copyLength2);
          copyEnd4 = ((int (*)())_ncpy_97be5f58)(outCursor,*(undefined4 *)
                                            (tempNumbers +
                                            (uint)*(ushort *)((int)puVar21 + iVar22 + 6) * 4));
          outCursor = (int *)((int)outCursor + copyEnd4);
          uVar25 = puVar21[loopIndex10 * 2];
          outCursor = (int *)((int (*)())_glpWriteSizeTypePrecision)(outCursor,uVar25 >> 0x18 & 3,0,uVar25 >> 0x1a & 7,
                                       uVar25 >> 0x1d);
        }
        else {
          if (iVar9 == 0) {
            ch = 't';
            elementInArray = 0;
            copyIndex2 = 0;
            do {
              *(char *)((int)outCursor + copyIndex2) = ch;
              copyLength2 = copyIndex2 + 1;
              ch = "tmp"[copyIndex2 + 1];
              copyIndex2 = copyLength2;
            } while (ch != '\0');
            outCursor = (int *)((int)outCursor + copyLength2);
            copyEnd3 = ((int (*)())_ncpy_97be5f58)(outCursor,*(undefined4 *)
                                             (tempNumbers +
                                             (uint)*(ushort *)((int)puVar21 + iVar22 + 6) * 4));
            ch = '[';
            copyIndex4 = 0;
            do {
              *(char *)((int)outCursor + copyIndex4 + copyEnd3) = ch;
              copyLength2 = copyIndex4 + 1;
              ch = "["[copyIndex4 + 1];
              copyIndex4 = copyLength2;
            } while (ch != '\0');
            outCursor = (int *)((int)outCursor + copyLength2 + copyEnd3);
            iVar22 = arrayIndex * 4;
            copyEnd = ((int (*)())_ncpy_97be5f58)(outCursor,arraySizes[arrayIndex]);
            ch = ']';
            copyIndex2 = 0;
            do {
              *(char *)((int)outCursor + copyIndex2 + copyEnd) = ch;
              copyLength = copyIndex2 + 1;
              ch = "]"[copyIndex2 + 1];
              copyIndex2 = copyLength;
            } while (ch != '\0');
            outCursor = (int *)((int)outCursor + copyLength + copyEnd);
            uVar25 = puVar21[loopIndex10 * 2];
            outCursor = (int *)((int (*)())_glpWriteSizeTypePrecision)(outCursor,uVar25 >> 0x18 & 3,0,uVar25 >> 0x1a & 7,
                                         uVar25 >> 0x1d);
          }
          else {
            elementInArray = elementInArray + 1;
            iVar22 = arrayIndex << 2;
          }
          if (elementInArray + 1 == *(int *)(iVar22 + (int)arraySizes)) {
            elementInArray = -1;
            arrayIndex = arrayIndex + 1;
          }
        }
      }
      uVar25 = loopIndex10 + 1;
      if (uVar25 == tempCount) {
        ch = ';';
        copyIndex4 = 0;
        do {
          *(char *)((int)outCursor + copyIndex4) = ch;
          copyLength3 = copyIndex4 + 1;
          ch = ";\n"[copyIndex4 + 1];
          copyIndex4 = copyLength3;
        } while (ch != '\0');
LAB_97beacc8:
        outCursor = (int *)((int)outCursor + copyLength3);
      }
      else {
        if (puVar21[loopIndex10 * 2 + 2] >> 0x1d != uVar6) {
          dataBase = "o intialize the Preprocessor";
          ch = ';';
          copyIndex4 = 0;
          do {
            *(char *)((int)outCursor + copyIndex4) = ch;
            copyLength3 = copyIndex4 + 1;
            ch = ";\n"[copyIndex4 + 1];
            copyIndex4 = copyLength3;
          } while (ch != '\0');
          bVar3 = true;
          goto LAB_97beacc8;
        }
        if (elementInArray == -1) {
          ch = ',';
          copyIndex4 = 0;
          do {
            *(char *)((int)outCursor + copyIndex4) = ch;
            copyLength3 = copyIndex4 + 1;
            ch = ", "[copyIndex4 + 1];
            copyIndex4 = copyLength3;
          } while (ch != '\0');
          goto LAB_97beacc8;
        }
      }
      uVar26 = ((int (*)())_adjustAllocation_97be9cb4)(&outBufCapacity,&outBuf,&outCursor);
      if ((int)((ulonglong)uVar26 >> 0x20) == 0) goto LAB_97bf0c18;
      loopIndex10 = uVar25;
    } while ((int)uVar25 < (int)tempCount);
  }
  if (arraySizes != (int *)0x0) {
    _free(arraySizes);
    uVar26 = CONCAT44(extraout_r3,extraout_r4_02);
  }
  if ((tempCount != 0) && (!bVar2)) {
    ch = '\n';
    copyIndex4 = 0;
    do {
      *(char *)((int)outCursor + copyIndex4) = ch;
      copyLength3 = copyIndex4 + 1;
      ch = "\n"[copyIndex4 + 1];
      copyIndex4 = copyLength3;
    } while (ch != '\0');
    outCursor = (int *)((int)outCursor + copyLength3);
  }
  attribCount = program[8];
  loopIndex = 0;
  attribOffset = program[9];
  if (0 < (int)attribCount) {
    do {
      uVar23 = program[attribOffset * 2 + loopIndex * 2] >> 0x10 & 0xf;
      if (uVar23 != 0) {
        ch = 'A';
        copyIndex2 = 0;
        do {
          *(char *)((int)outCursor + copyIndex2) = ch;
          copyLength2 = copyIndex2 + 1;
          ch = "ATTRIB att"[copyIndex2 + 1];
          copyIndex2 = copyLength2;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + copyLength2);
        copyEnd3 = ((int (*)())_ncpy_97be5f58)(outCursor,(uint)*(ushort *)((int)program + loopIndex * 8 + attribOffset * 8 + 6)
                              );
        outCursor = (int *)((int)outCursor + copyEnd3);
        if (!bVar2) {
          uVar25 = program[attribOffset * 2 + loopIndex * 2];
          outCursor = (int *)((int (*)())_glpWriteSizeTypePrecision)(outCursor,uVar25 >> 0x18 & 3,0,uVar25 >> 0x1a & 7,
                                       uVar25 >> 0x1d);
        }
        if (programTarget == 0x8804) {
LAB_97beae94:
          ch = ' ';
          copyIndex2 = 0;
          do {
            *(char *)((int)outCursor + copyIndex2) = ch;
            copyLength2 = copyIndex2 + 1;
            ch = " = fragment."[copyIndex2 + 1];
            copyIndex2 = copyLength2;
          } while (ch != '\0');
LAB_97beaec8:
          outCursor = (int *)((int)outCursor + copyLength2);
        }
        else {
          if (programTarget < 0x8805) {
            uVar25 = 0x8620;
          }
          else {
            if (programTarget == 0x8b30) goto LAB_97beae94;
            uVar25 = 0x8b31;
          }
          if (programTarget == uVar25) {
            ch = ' ';
            copyIndex2 = 0;
            do {
              *(char *)((int)outCursor + copyIndex2) = ch;
              copyLength2 = copyIndex2 + 1;
              ch = " = vertex."[copyIndex2 + 1];
              copyIndex2 = copyLength2;
            } while (ch != '\0');
            goto LAB_97beaec8;
          }
        }
        switch(uVar23) {
        default:
          goto switchD_97beaef4_caseD_0;
        case 1:
          ch = 'p';
          copyIndex2 = 0;
          do {
            *(char *)((int)outCursor + copyIndex2) = ch;
            copyLength2 = copyIndex2 + 1;
            ch = "position"[copyIndex2 + 1];
            copyIndex2 = copyLength2;
          } while (ch != '\0');
          break;
        case 2:
          ch = 'c';
          copyIndex2 = 0;
          do {
            *(char *)((int)outCursor + copyIndex2) = ch;
            copyLength2 = copyIndex2 + 1;
            ch = "color.primary"[copyIndex2 + 1];
            copyIndex2 = copyLength2;
          } while (ch != '\0');
          break;
        case 3:
          ch = 'c';
          copyIndex2 = 0;
          do {
            *(char *)((int)outCursor + copyIndex2) = ch;
            copyLength2 = copyIndex2 + 1;
            ch = "color.secondary"[copyIndex2 + 1];
            copyIndex2 = copyLength2;
          } while (ch != '\0');
          break;
        case 4:
          ch = 'n';
          copyIndex2 = 0;
          do {
            *(char *)((int)outCursor + copyIndex2) = ch;
            copyLength2 = copyIndex2 + 1;
            ch = "normal"[copyIndex2 + 1];
            copyIndex2 = copyLength2;
          } while (ch != '\0');
          break;
        case 5:
          ch = 'f';
          copyIndex2 = 0;
          do {
            *(char *)((int)outCursor + copyIndex2) = ch;
            copyLength2 = copyIndex2 + 1;
            ch = "fogcoord"[copyIndex2 + 1];
            copyIndex2 = copyLength2;
          } while (ch != '\0');
          break;
        case 6:
          ch = 'w';
          copyIndex2 = 0;
          do {
            *(char *)((int)outCursor + copyIndex2) = ch;
            copyLength2 = copyIndex2 + 1;
            ch = "weight["[copyIndex2 + 1];
            copyIndex2 = copyLength2;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + copyLength2);
          copyEnd3 = ((int (*)())_ncpy_97be5f58)(outCursor,program[attribOffset * 2 + loopIndex * 2] & 0x1f);
          ch = ']';
          outCursor = (int *)((int)outCursor + copyEnd3);
          copyIndex2 = 0;
          do {
            *(char *)((int)outCursor + copyIndex2) = ch;
            copyLength2 = copyIndex2 + 1;
            ch = "]"[copyIndex2 + 1];
            copyIndex2 = copyLength2;
          } while (ch != '\0');
          break;
        case 7:
          ch = 't';
          copyIndex2 = 0;
          do {
            *(char *)((int)outCursor + copyIndex2) = ch;
            copyLength2 = copyIndex2 + 1;
            ch = "texcoord["[copyIndex2 + 1];
            copyIndex2 = copyLength2;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + copyLength2);
          copyEnd3 = ((int (*)())_ncpy_97be5f58)(outCursor,program[attribOffset * 2 + loopIndex * 2] & 0x1f);
          ch = ']';
          outCursor = (int *)((int)outCursor + copyEnd3);
          copyIndex2 = 0;
          do {
            *(char *)((int)outCursor + copyIndex2) = ch;
            copyLength2 = copyIndex2 + 1;
            ch = "]"[copyIndex2 + 1];
            copyIndex2 = copyLength2;
          } while (ch != '\0');
          break;
        case 8:
          ch = 'm';
          copyIndex2 = 0;
          do {
            *(char *)((int)outCursor + copyIndex2) = ch;
            copyLength2 = copyIndex2 + 1;
            ch = "matrixindex["[copyIndex2 + 1];
            copyIndex2 = copyLength2;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + copyLength2);
          copyEnd3 = ((int (*)())_ncpy_97be5f58)(outCursor,program[attribOffset * 2 + loopIndex * 2] & 0x1f);
          ch = ']';
          outCursor = (int *)((int)outCursor + copyEnd3);
          copyIndex2 = 0;
          do {
            *(char *)((int)outCursor + copyIndex2) = ch;
            copyLength2 = copyIndex2 + 1;
            ch = "]"[copyIndex2 + 1];
            copyIndex2 = copyLength2;
          } while (ch != '\0');
          break;
        case 9:
          ch = 'a';
          copyIndex2 = 0;
          do {
            *(char *)((int)outCursor + copyIndex2) = ch;
            copyLength2 = copyIndex2 + 1;
            ch = "attrib["[copyIndex2 + 1];
            copyIndex2 = copyLength2;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + copyLength2);
          copyEnd3 = ((int (*)())_ncpy_97be5f58)(outCursor,program[attribOffset * 2 + loopIndex * 2] & 0x1f);
          ch = ']';
          outCursor = (int *)((int)outCursor + copyEnd3);
          copyIndex2 = 0;
          do {
            *(char *)((int)outCursor + copyIndex2) = ch;
            copyLength2 = copyIndex2 + 1;
            ch = "]"[copyIndex2 + 1];
            copyIndex2 = copyLength2;
          } while (ch != '\0');
          break;
        case 10:
          ch = 'm';
          copyIndex2 = 0;
          do {
            *(char *)((int)outCursor + copyIndex2) = ch;
            copyLength2 = copyIndex2 + 1;
            ch = "material."[copyIndex2 + 1];
            copyIndex2 = copyLength2;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + copyLength2);
          if ((program[attribOffset * 2 + loopIndex * 2] & 1) == 0) {
            ch = 'f';
            copyIndex2 = 0;
            do {
              *(char *)((int)outCursor + copyIndex2) = ch;
              copyLength2 = copyIndex2 + 1;
              ch = "front."[copyIndex2 + 1];
              copyIndex2 = copyLength2;
            } while (ch != '\0');
LAB_97beb3a4:
            outCursor = (int *)((int)outCursor + copyLength2);
          }
          else if ((program[attribOffset * 2 + loopIndex * 2] & 1) == 1) {
            ch = 'b';
            copyIndex2 = 0;
            do {
              *(char *)((int)outCursor + copyIndex2) = ch;
              copyLength2 = copyIndex2 + 1;
              ch = "back."[copyIndex2 + 1];
              copyIndex2 = copyLength2;
            } while (ch != '\0');
            goto LAB_97beb3a4;
          }
          switch(program[attribOffset * 2 + loopIndex * 2] >> 0xc & 0xf) {
          case 0:
            ch = 'a';
            copyIndex2 = 0;
            do {
              *(char *)((int)outCursor + copyIndex2) = ch;
              copyLength2 = copyIndex2 + 1;
              ch = "ambient"[copyIndex2 + 1];
              copyIndex2 = copyLength2;
            } while (ch != '\0');
            break;
          case 1:
            ch = 'd';
            copyIndex2 = 0;
            do {
              *(char *)((int)outCursor + copyIndex2) = ch;
              copyLength2 = copyIndex2 + 1;
              ch = "diffuse"[copyIndex2 + 1];
              copyIndex2 = copyLength2;
            } while (ch != '\0');
            break;
          case 2:
            ch = 's';
            copyIndex2 = 0;
            do {
              *(char *)((int)outCursor + copyIndex2) = ch;
              copyLength2 = copyIndex2 + 1;
              ch = "specular"[copyIndex2 + 1];
              copyIndex2 = copyLength2;
            } while (ch != '\0');
            break;
          case 3:
            ch = 'e';
            copyIndex2 = 0;
            do {
              *(char *)((int)outCursor + copyIndex2) = ch;
              copyLength2 = copyIndex2 + 1;
              ch = "emission"[copyIndex2 + 1];
              copyIndex2 = copyLength2;
            } while (ch != '\0');
            break;
          case 4:
            ch = 's';
            copyIndex2 = 0;
            do {
              *(char *)((int)outCursor + copyIndex2) = ch;
              copyLength2 = copyIndex2 + 1;
              ch = "shininess"[copyIndex2 + 1];
              copyIndex2 = copyLength2;
            } while (ch != '\0');
            break;
          default:
            goto switchD_97beaef4_caseD_0;
          }
          break;
        case 0xb:
          ch = 'f';
          copyIndex2 = 0;
          do {
            *(char *)((int)outCursor + copyIndex2) = ch;
            copyLength2 = copyIndex2 + 1;
            ch = "frontfacing"[copyIndex2 + 1];
            copyIndex2 = copyLength2;
          } while (ch != '\0');
        }
        outCursor = (int *)((int)outCursor + copyLength2);
switchD_97beaef4_caseD_0:
        ch = ';';
        copyIndex2 = 0;
        do {
          *(char *)((int)outCursor + copyIndex2) = ch;
          copyLength2 = copyIndex2 + 1;
          ch = ";\n"[copyIndex2 + 1];
          copyIndex2 = copyLength2;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + copyLength2);
        uVar26 = ((int (*)())_adjustAllocation_97be9cb4)(&outBufCapacity,&outBuf,&outCursor);
        if ((int)((ulonglong)uVar26 >> 0x20) == 0) goto LAB_97bf0c18;
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < (int)attribCount);
  }
  uVar16 = (undefined4)uVar26;
  if ((attribCount != 0) && (!bVar2)) {
    ch = '\n';
    copyIndex4 = 0;
    do {
      *(char *)((int)outCursor + copyIndex4) = ch;
      copyLength3 = copyIndex4 + 1;
      ch = "\n"[copyIndex4 + 1];
      copyIndex4 = copyLength3;
    } while (ch != '\0');
    outCursor = (int *)((int)outCursor + copyLength3);
  }
  paramCount = program[10];
  nextIndex5 = program + program[0xb] * 2;
  if (paramCount == 0) {
    bVar3 = paramNumbers == 0;
    goto LAB_97bed528;
  }
  uVar20 = 0xffffffff;
  if ((int)paramCount < 1) {
LAB_97beb670:
    bVar3 = paramNumbers == 0;
  }
  else {
    puVar11 = nextIndex5 + 1;
    uVar23 = paramCount;
    do {
      uVar25 = *puVar11;
      puVar11 = puVar11 + 2;
      if ((int)uVar20 < (int)(uVar25 & 0xffff)) {
        uVar20 = uVar25 & 0xffff;
      }
      uVar23 = uVar23 - 1;
    } while (uVar23 != 0);
    if (uVar20 == 0xffffffff) goto LAB_97beb670;
    allocation2 = uVar20 * 4 + 4;
    paramNumbers = _malloc(allocation2);
    bVar1 = paramNumbers == 0;
    paramArrayPos = _malloc(allocation2);
    if ((bVar1) || (bVar3 = false, uVar16 = extraout_r4_03, paramArrayPos == 0)) {
      bVar3 = paramArrayPos == 0;
joined_r0x97beb668:
      if (!bVar1) {
        _free(paramNumbers);
      }
      if (!bVar3) {
        _free(paramArrayPos);
      }
LAB_97bf0c18:
      bVar5 = (byte)((uint)cr0Image >> 0x18);
      goto joined_r0x97bea678;
    }
  }
  arraySizes = (int *)0x0;
  if (program[0xe] != 0) {
    arraySizes = (int *)_malloc(program[0xe] << 2);
    uVar16 = extraout_r4_04;
  }
  uVar26 = CONCAT44(arraySizes,uVar16);
  loopIndex = 0;
  iVar9 = -1;
  paramRegisterId = 0xffffffff;
  uVar20 = 0xffffffff;
  piVar15 = arraySizes;
  puVar11 = nextIndex5;
  if (0 < (int)paramCount) {
    do {
      if ((*puVar11 & 0x1f0000) != 0) {
        if (uVar20 == 0xffffffff) {
          *(uint *)((uint)*(ushort *)((int)puVar11 + 6) * 4 + paramNumbers) =
               (uint)*(ushort *)((int)puVar11 + 6);
          uVar26 = ((int (*)())_isParamArrayStart_97be9b80)(program,(uint)*(ushort *)((int)puVar11 + 6),&paramRegisterId);
          if ((int)((ulonglong)uVar26 >> 0x20) == 0) {
            *(int *)(paramArrayPos + (uint)*(ushort *)((int)puVar11 + 6) * 4) = iVar9;
          }
          else {
            uVar20 = (uint)*(ushort *)((int)puVar11 + 6);
            *(undefined4 *)(paramArrayPos + uVar20 * 4) = 0;
            iVar9 = 1;
          }
          if (*(ushort *)((int)puVar11 + 6) == paramRegisterId) {
LAB_97beb790:
            paramRegisterId = 0xffffffff;
            *piVar15 = iVar9;
            uVar20 = 0xffffffff;
            piVar15 = piVar15 + 1;
            iVar9 = -1;
          }
        }
        else if ((int)(uint)*(ushort *)((int)puVar11 + 6) <= (int)paramRegisterId) {
          *(uint *)((uint)*(ushort *)((int)puVar11 + 6) * 4 + paramNumbers) = uVar20;
          *(int *)(paramArrayPos + (uint)*(ushort *)((int)puVar11 + 6) * 4) = iVar9;
          iVar9 = iVar9 + 1;
          if (*(ushort *)((int)puVar11 + 6) == paramRegisterId) goto LAB_97beb790;
        }
      }
      loopIndex = loopIndex + 1;
      puVar11 = puVar11 + 2;
    } while (loopIndex < (int)paramCount);
  }
  loopIndex = 0;
  arrayIndex = 0;
  if (0 < (int)paramCount) {
    do {
      iVar9 = loopIndex * 8;
      uVar20 = nextIndex5[loopIndex * 2] >> 0x10 & 0x1f;
      if (uVar20 == 0) goto LAB_97bed4a8;
      iVar10 = *(int *)(paramArrayPos + (uint)*(ushort *)((int)nextIndex5 + iVar9 + 6) * 4);
      if (iVar10 == -1) {
        ch = 'P';
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex) = ch;
          copyLength = copyIndex + 1;
          ch = "PARAM prm"[copyIndex + 1];
          copyIndex = copyLength;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + copyLength);
        uVar26 = ((int (*)())_ncpy_97be5f58)(outCursor,*(undefined4 *)
                                          (paramNumbers +
                                          (uint)*(ushort *)((int)nextIndex5 + iVar9 + 6) * 4));
        outCursor = (int *)((int)outCursor + (int)((ulonglong)uVar26 >> 0x20));
        if (!bVar2) {
          uVar23 = nextIndex5[loopIndex * 2];
          uVar26 = ((int (*)())_glpWriteSizeTypePrecision)(outCursor,uVar23 >> 0x18 & 3,0,uVar23 >> 0x1a & 7,uVar23 >> 0x1d);
          outCursor = (int *)((ulonglong)uVar26 >> 0x20);
        }
        ch = ' ';
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex) = ch;
          nextIndex2 = copyIndex + 1;
          ch = " = "[copyIndex + 1];
          copyIndex = nextIndex2;
        } while (ch != '\0');
      }
      else if (iVar10 == 0) {
        ch = 'P';
        elementInArray = 0;
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex) = ch;
          copyLength = copyIndex + 1;
          ch = "PARAM prm"[copyIndex + 1];
          copyIndex = copyLength;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + copyLength);
        copyEnd2 = ((int (*)())_ncpy_97be5f58)(outCursor,*(undefined4 *)
                                          (paramNumbers +
                                          (uint)*(ushort *)((int)nextIndex5 + iVar9 + 6) * 4));
        ch = '[';
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex + copyEnd2) = ch;
          copyLength4 = copyIndex + 1;
          ch = "["[copyIndex + 1];
          copyIndex = copyLength4;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + copyLength4 + copyEnd2);
        uVar26 = ((int (*)())_ncpy_97be5f58)(outCursor,arraySizes[arrayIndex]);
        ch = ']';
        outBytePtr = (undefined1 *)((int)outCursor + (int)((ulonglong)uVar26 >> 0x20));
        copyIndex = 0;
        do {
          outBytePtr[copyIndex] = ch;
          copyLength = copyIndex + 1;
          ch = "]"[copyIndex + 1];
          copyIndex = copyLength;
        } while (ch != '\0');
        outCursor = (int *)(outBytePtr + copyLength);
        if (!bVar2) {
          uVar23 = nextIndex5[loopIndex * 2];
          uVar26 = ((int (*)())_glpWriteSizeTypePrecision)(outCursor,uVar23 >> 0x18 & 3,0,uVar23 >> 0x1a & 7,uVar23 >> 0x1d);
          outCursor = (int *)((ulonglong)uVar26 >> 0x20);
        }
        ch = ' ';
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex) = ch;
          nextIndex2 = copyIndex + 1;
          ch = " = {\n    "[copyIndex + 1];
          copyIndex = nextIndex2;
        } while (ch != '\0');
      }
      else {
        ch = ' ';
        elementInArray = elementInArray + 1;
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex) = ch;
          nextIndex2 = copyIndex + 1;
          ch = "    "[copyIndex + 1];
          copyIndex = nextIndex2;
        } while (ch != '\0');
      }
      if (uVar20 == 0) {
LAB_97bebb2c:
        ch = 's';
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex + nextIndex2) = ch;
          nextIndex3 = copyIndex + 1;
          ch = "state."[copyIndex + 1];
          copyIndex = nextIndex3;
        } while (ch != '\0');
      }
      else if (uVar20 < 3) {
        ch = 'p';
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex + nextIndex2) = ch;
          nextIndex3 = copyIndex + 1;
          ch = "program."[copyIndex + 1];
          copyIndex = nextIndex3;
        } while (ch != '\0');
      }
      else {
        if (uVar20 != 0x11) goto LAB_97bebb2c;
        nextIndex3 = 0;
      }
      outCursor = (int *)((int)outCursor + nextIndex3 + nextIndex2);
      switch(uVar20) {
      default:
        goto switchD_97bebb8c_caseD_0;
      case 1:
        ch = 'l';
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex) = ch;
          copyLength = copyIndex + 1;
          ch = "local["[copyIndex + 1];
          copyIndex = copyLength;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + copyLength);
        copyEnd = ((int (*)())_ncpy_97be5f58)(outCursor,nextIndex5[loopIndex * 2] & 0xffff);
        ch = ']';
        outCursor = (int *)((int)outCursor + copyEnd);
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex) = ch;
          copyLength = copyIndex + 1;
          ch = "]"[copyIndex + 1];
          copyIndex = copyLength;
        } while (ch != '\0');
        goto LAB_97bed34c;
      case 2:
        ch = 'e';
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex) = ch;
          copyLength = copyIndex + 1;
          ch = "env["[copyIndex + 1];
          copyIndex = copyLength;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + copyLength);
        copyEnd = ((int (*)())_ncpy_97be5f58)(outCursor,nextIndex5[loopIndex * 2] & 0xffff);
        ch = ']';
        outCursor = (int *)((int)outCursor + copyEnd);
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex) = ch;
          copyLength = copyIndex + 1;
          ch = "]"[copyIndex + 1];
          copyIndex = copyLength;
        } while (ch != '\0');
        goto LAB_97bed34c;
      case 3:
        ch = 'l';
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex) = ch;
          copyLength = copyIndex + 1;
          ch = "light["[copyIndex + 1];
          copyIndex = copyLength;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + copyLength);
        iVar12 = ((int (*)())_ncpy_97be5f58)(outCursor,nextIndex5[loopIndex * 2] & 0xff);
        ch = ']';
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex + iVar12) = ch;
          nextIndex3 = copyIndex + 1;
          ch = "]."[copyIndex + 1];
          copyIndex = nextIndex3;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + nextIndex3 + iVar12);
        switch(nextIndex5[loopIndex * 2] >> 8 & 0xf) {
        case 0:
          ch = 'a';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            nextIndex2 = copyIndex + 1;
            ch = "ambient"[copyIndex + 1];
            copyIndex = nextIndex2;
          } while (ch != '\0');
          break;
        case 1:
          ch = 'd';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            nextIndex2 = copyIndex + 1;
            ch = "diffuse"[copyIndex + 1];
            copyIndex = nextIndex2;
          } while (ch != '\0');
          break;
        case 2:
          ch = 's';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            nextIndex2 = copyIndex + 1;
            ch = "specular"[copyIndex + 1];
            copyIndex = nextIndex2;
          } while (ch != '\0');
          break;
        case 3:
          ch = 'p';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            nextIndex2 = copyIndex + 1;
            ch = "position"[copyIndex + 1];
            copyIndex = nextIndex2;
          } while (ch != '\0');
          break;
        case 4:
          ch = 's';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            nextIndex2 = copyIndex + 1;
            ch = "spot.direction"[copyIndex + 1];
            copyIndex = nextIndex2;
          } while (ch != '\0');
          break;
        case 5:
          ch = 'a';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            nextIndex2 = copyIndex + 1;
            ch = "attenuation"[copyIndex + 1];
            copyIndex = nextIndex2;
          } while (ch != '\0');
          break;
        case 6:
          ch = 'h';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            nextIndex2 = copyIndex + 1;
            ch = "half"[copyIndex + 1];
            copyIndex = nextIndex2;
          } while (ch != '\0');
          break;
        case 7:
          ch = 's';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            nextIndex2 = copyIndex + 1;
            ch = "spotcutoff"[copyIndex + 1];
            copyIndex = nextIndex2;
          } while (ch != '\0');
          break;
        default:
          goto switchD_97bebb8c_caseD_0;
        }
        break;
      case 4:
        ch = 'l';
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex) = ch;
          copyLength = copyIndex + 1;
          ch = "lightprod["[copyIndex + 1];
          copyIndex = copyLength;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + copyLength);
        copyEnd2 = ((int (*)())_ncpy_97be5f58)(outCursor,nextIndex5[loopIndex * 2] & 0xff);
        ch = ']';
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex + copyEnd2) = ch;
          nextIndex3 = copyIndex + 1;
          ch = "]."[copyIndex + 1];
          copyIndex = nextIndex3;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + nextIndex3 + copyEnd2);
        uVar20 = nextIndex5[loopIndex * 2] >> 8 & 1;
        if (uVar20 == 0) {
          ch = 'f';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            copyLength = copyIndex + 1;
            ch = "front."[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
LAB_97bec0e8:
          outCursor = (int *)((int)outCursor + copyLength);
        }
        else if (uVar20 == 1) {
          ch = 'b';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            copyLength = copyIndex + 1;
            ch = "back."[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          goto LAB_97bec0e8;
        }
        uVar20 = nextIndex5[loopIndex * 2] >> 9 & 3;
        if (uVar20 == 1) {
          ch = 'd';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            nextIndex2 = copyIndex + 1;
            ch = "diffuse"[copyIndex + 1];
            copyIndex = nextIndex2;
          } while (ch != '\0');
          break;
        }
        if (uVar20 < 2) {
          if (uVar20 == 0) {
            ch = 'a';
            copyIndex = 0;
            do {
              *(char *)((int)outCursor + copyIndex) = ch;
              nextIndex2 = copyIndex + 1;
              ch = "ambient"[copyIndex + 1];
              copyIndex = nextIndex2;
            } while (ch != '\0');
            break;
          }
        }
        else if (uVar20 == 2) {
          ch = 's';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            nextIndex2 = copyIndex + 1;
            ch = "specular"[copyIndex + 1];
            copyIndex = nextIndex2;
          } while (ch != '\0');
          break;
        }
        goto switchD_97bebb8c_caseD_0;
      case 5:
        if ((nextIndex5[loopIndex * 2] >> 1 & 7) == 5) {
          ch = 'l';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            nextIndex2 = copyIndex + 1;
            ch = "lightmodel."[copyIndex + 1];
            copyIndex = nextIndex2;
          } while (ch != '\0');
        }
        else {
          ch = 'm';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            nextIndex2 = copyIndex + 1;
            ch = "material."[copyIndex + 1];
            copyIndex = nextIndex2;
          } while (ch != '\0');
        }
        outCursor = (int *)((int)outCursor + nextIndex2);
        if ((nextIndex5[loopIndex * 2] & 1) == 0) {
          ch = 'f';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            nextIndex2 = copyIndex + 1;
            ch = "front."[copyIndex + 1];
            copyIndex = nextIndex2;
          } while (ch != '\0');
LAB_97bec310:
          outCursor = (int *)((int)outCursor + nextIndex2);
        }
        else if ((nextIndex5[loopIndex * 2] & 1) == 1) {
          ch = 'b';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            nextIndex2 = copyIndex + 1;
            ch = "back."[copyIndex + 1];
            copyIndex = nextIndex2;
          } while (ch != '\0');
          goto LAB_97bec310;
        }
        switch(nextIndex5[loopIndex * 2] >> 1 & 7) {
        case 0:
          ch = 'a';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            nextIndex2 = copyIndex + 1;
            ch = "ambient"[copyIndex + 1];
            copyIndex = nextIndex2;
          } while (ch != '\0');
          break;
        case 1:
          ch = 'd';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            nextIndex2 = copyIndex + 1;
            ch = "diffuse"[copyIndex + 1];
            copyIndex = nextIndex2;
          } while (ch != '\0');
          break;
        case 2:
          ch = 's';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            nextIndex2 = copyIndex + 1;
            ch = "specular"[copyIndex + 1];
            copyIndex = nextIndex2;
          } while (ch != '\0');
          break;
        case 3:
          ch = 'e';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            nextIndex2 = copyIndex + 1;
            ch = "emission"[copyIndex + 1];
            copyIndex = nextIndex2;
          } while (ch != '\0');
          break;
        case 4:
          ch = 's';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            nextIndex2 = copyIndex + 1;
            ch = "shininess"[copyIndex + 1];
            copyIndex = nextIndex2;
          } while (ch != '\0');
          break;
        case 5:
          ch = 's';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            nextIndex2 = copyIndex + 1;
            ch = "scenecolor"[copyIndex + 1];
            copyIndex = nextIndex2;
          } while (ch != '\0');
          break;
        default:
          goto switchD_97bebb8c_caseD_0;
        }
        break;
      case 6:
        ch = 'l';
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex) = ch;
          nextIndex2 = copyIndex + 1;
          ch = "lightmodel.ambient"[copyIndex + 1];
          copyIndex = nextIndex2;
        } while (ch != '\0');
        break;
      case 7:
        ch = 't';
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex) = ch;
          copyLength = copyIndex + 1;
          ch = "texgen["[copyIndex + 1];
          copyIndex = copyLength;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + copyLength);
        copyEnd2 = ((int (*)())_ncpy_97be5f58)(outCursor,nextIndex5[loopIndex * 2] & 0x1f);
        ch = ']';
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex + copyEnd2) = ch;
          nextIndex3 = copyIndex + 1;
          ch = "].eye."[copyIndex + 1];
          copyIndex = nextIndex3;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + nextIndex3 + copyEnd2);
        uVar20 = nextIndex5[loopIndex * 2] >> 5 & 7;
        if (uVar20 == 1) {
          ch = 't';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            nextIndex2 = copyIndex + 1;
            ch = "t"[copyIndex + 1];
            copyIndex = nextIndex2;
          } while (ch != '\0');
        }
        else if (uVar20 < 2) {
          if (uVar20 != 0) goto switchD_97bebb8c_caseD_0;
          ch = 's';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            nextIndex2 = copyIndex + 1;
            ch = "s"[copyIndex + 1];
            copyIndex = nextIndex2;
          } while (ch != '\0');
        }
        else if (uVar20 == 2) {
          ch = 'r';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            nextIndex2 = copyIndex + 1;
            ch = "r"[copyIndex + 1];
            copyIndex = nextIndex2;
          } while (ch != '\0');
        }
        else {
          if (uVar20 != 3) goto switchD_97bebb8c_caseD_0;
          ch = 'q';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            nextIndex2 = copyIndex + 1;
            ch = "q"[copyIndex + 1];
            copyIndex = nextIndex2;
          } while (ch != '\0');
        }
        break;
      case 8:
        ch = 't';
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex) = ch;
          copyLength = copyIndex + 1;
          ch = "texgen["[copyIndex + 1];
          copyIndex = copyLength;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + copyLength);
        copyEnd2 = ((int (*)())_ncpy_97be5f58)(outCursor,nextIndex5[loopIndex * 2] & 0x1f);
        ch = ']';
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex + copyEnd2) = ch;
          nextIndex3 = copyIndex + 1;
          ch = "].object."[copyIndex + 1];
          copyIndex = nextIndex3;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + nextIndex3 + copyEnd2);
        uVar20 = nextIndex5[loopIndex * 2] >> 5 & 7;
        if (uVar20 == 1) {
          ch = 't';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            nextIndex2 = copyIndex + 1;
            ch = "t"[copyIndex + 1];
            copyIndex = nextIndex2;
          } while (ch != '\0');
        }
        else if (uVar20 < 2) {
          if (uVar20 != 0) goto switchD_97bebb8c_caseD_0;
          ch = 's';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            nextIndex2 = copyIndex + 1;
            ch = "s"[copyIndex + 1];
            copyIndex = nextIndex2;
          } while (ch != '\0');
        }
        else if (uVar20 == 2) {
          ch = 'r';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            nextIndex2 = copyIndex + 1;
            ch = "r"[copyIndex + 1];
            copyIndex = nextIndex2;
          } while (ch != '\0');
        }
        else {
          if (uVar20 != 3) goto switchD_97bebb8c_caseD_0;
          ch = 'q';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            nextIndex2 = copyIndex + 1;
            ch = "q"[copyIndex + 1];
            copyIndex = nextIndex2;
          } while (ch != '\0');
        }
        break;
      case 9:
        ch = 't';
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex) = ch;
          copyLength = copyIndex + 1;
          ch = "texenv["[copyIndex + 1];
          copyIndex = copyLength;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + copyLength);
        copyEnd = ((int (*)())_ncpy_97be5f58)(outCursor,nextIndex5[loopIndex * 2] & 0x1f);
        ch = ']';
        outCursor = (int *)((int)outCursor + copyEnd);
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex) = ch;
          copyLength = copyIndex + 1;
          ch = "].color"[copyIndex + 1];
          copyIndex = copyLength;
        } while (ch != '\0');
        goto LAB_97bed34c;
      case 10:
        ch = 'c';
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex) = ch;
          copyLength = copyIndex + 1;
          ch = "clip["[copyIndex + 1];
          copyIndex = copyLength;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + copyLength);
        copyEnd = ((int (*)())_ncpy_97be5f58)(outCursor,nextIndex5[loopIndex * 2] & 0xff);
        ch = ']';
        outCursor = (int *)((int)outCursor + copyEnd);
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex) = ch;
          copyLength = copyIndex + 1;
          ch = "].plane"[copyIndex + 1];
          copyIndex = copyLength;
        } while (ch != '\0');
        goto LAB_97bed34c;
      case 0xb:
        ch = 'f';
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex) = ch;
          nextIndex2 = copyIndex + 1;
          ch = "fog.color"[copyIndex + 1];
          copyIndex = nextIndex2;
        } while (ch != '\0');
        break;
      case 0xc:
        ch = 'f';
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex) = ch;
          nextIndex2 = copyIndex + 1;
          ch = "fog.params"[copyIndex + 1];
          copyIndex = nextIndex2;
        } while (ch != '\0');
        break;
      case 0xd:
        ch = 'p';
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex) = ch;
          nextIndex2 = copyIndex + 1;
          ch = "point.size"[copyIndex + 1];
          copyIndex = nextIndex2;
        } while (ch != '\0');
        break;
      case 0xe:
        ch = 'p';
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex) = ch;
          nextIndex2 = copyIndex + 1;
          ch = "point.attenuation"[copyIndex + 1];
          copyIndex = nextIndex2;
        } while (ch != '\0');
        break;
      case 0xf:
        ch = 'd';
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex) = ch;
          nextIndex2 = copyIndex + 1;
          ch = "depth.range"[copyIndex + 1];
          copyIndex = nextIndex2;
        } while (ch != '\0');
        break;
      case 0x10:
        ch = 'm';
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex) = ch;
          copyLength = copyIndex + 1;
          ch = "matrix."[copyIndex + 1];
          copyIndex = copyLength;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + copyLength);
        switch(nextIndex5[loopIndex * 2] >> 8 & 7) {
        case 0:
          ch = 'm';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            copyLength = copyIndex + 1;
            ch = "mvp."[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          goto LAB_97becb5c;
        case 1:
          ch = 'p';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            copyLength = copyIndex + 1;
            ch = "projection."[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
LAB_97becb5c:
          outCursor = (int *)((int)outCursor + copyLength);
          goto switchD_97becad4_default;
        case 2:
          ch = 'c';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            copyLength = copyIndex + 1;
            ch = "color["[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + copyLength);
          copyEnd = ((int (*)())_ncpy_97be5f58)(outCursor,nextIndex5[loopIndex * 2] & 0xff);
          ch = ']';
          outCursor = (int *)((int)outCursor + copyEnd);
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            copyLength = copyIndex + 1;
            ch = "]."[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 3:
          ch = 'm';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            copyLength = copyIndex + 1;
            ch = "modelview["[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + copyLength);
          copyEnd = ((int (*)())_ncpy_97be5f58)(outCursor,nextIndex5[loopIndex * 2] & 0xff);
          ch = ']';
          outCursor = (int *)((int)outCursor + copyEnd);
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            copyLength = copyIndex + 1;
            ch = "]."[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 4:
          ch = 't';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            copyLength = copyIndex + 1;
            ch = "texture["[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + copyLength);
          copyEnd = ((int (*)())_ncpy_97be5f58)(outCursor,nextIndex5[loopIndex * 2] & 0xff);
          ch = ']';
          outCursor = (int *)((int)outCursor + copyEnd);
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            copyLength = copyIndex + 1;
            ch = "]."[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 5:
          ch = 'p';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            copyLength = copyIndex + 1;
            ch = "program["[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + copyLength);
          copyEnd = ((int (*)())_ncpy_97be5f58)(outCursor,nextIndex5[loopIndex * 2] & 0xff);
          ch = ']';
          outCursor = (int *)((int)outCursor + copyEnd);
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            copyLength = copyIndex + 1;
            ch = "]."[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        default:
          goto switchD_97becad4_default;
        }
        outCursor = (int *)((int)outCursor + copyLength);
switchD_97becad4_default:
        uVar20 = nextIndex5[loopIndex * 2] >> 0xe & 3;
        if (uVar20 == 1) {
          ch = 't';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            copyLength = copyIndex + 1;
            ch = "transpose."[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
LAB_97bece9c:
          outCursor = (int *)((int)outCursor + copyLength);
        }
        else if (1 < uVar20) {
          if (uVar20 == 2) {
            ch = 'i';
            copyIndex = 0;
            do {
              *(char *)((int)outCursor + copyIndex) = ch;
              copyLength = copyIndex + 1;
              ch = "inverse."[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
          }
          else {
            if (uVar20 != 3) goto LAB_97becea8;
            ch = 'i';
            copyIndex = 0;
            do {
              *(char *)((int)outCursor + copyIndex) = ch;
              copyLength = copyIndex + 1;
              ch = "invtrans."[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
          }
          goto LAB_97bece9c;
        }
LAB_97becea8:
        ch = 'r';
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex) = ch;
          copyLength = copyIndex + 1;
          ch = "row["[copyIndex + 1];
          copyIndex = copyLength;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + copyLength);
        copyEnd = ((int (*)())_ncpy_97be5f58)(outCursor,nextIndex5[loopIndex * 2] >> 0xc & 3);
        ch = ']';
        outCursor = (int *)((int)outCursor + copyEnd);
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex) = ch;
          copyLength = copyIndex + 1;
          ch = "]"[copyIndex + 1];
          copyIndex = copyLength;
        } while (ch != '\0');
LAB_97bed34c:
        outCursor = (int *)((int)outCursor + copyLength);
        goto switchD_97bebb8c_caseD_0;
      case 0x11:
        pfVar24 = (float *)(program + program[0x1b] * 2 + (nextIndex5[loopIndex * 2] & 0xffff) * 4);
        switch(nextIndex5[loopIndex * 2] >> 0x1a & 7) {
        case 0:
        case 1:
          ch = '{';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            copyLength = copyIndex + 1;
            ch = "{"[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + copyLength);
          uVar26 = ((char * (*)())_glp_dtostr)((int)((ulonglong)uVar26 >> 0x20),(int)uVar26,outCursor,
                               (int)outBuf + (outBufCapacity - (int)outCursor),(double)*pfVar24,1e-07,
                               in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_fffffd08,
                               in_stack_fffffd10,in_stack_fffffd18,in_stack_fffffd20,
                               in_stack_fffffd28);
          iVar12 = (int)((ulonglong)uVar26 >> 0x20);
          ch = ',';
          copyIndex = 0;
          do {
            *(char *)(iVar12 + copyIndex) = ch;
            copyLength4 = copyIndex + 1;
            ch = ", "[copyIndex + 1];
            copyIndex = copyLength4;
          } while (ch != '\0');
          outCursor = (int *)(iVar12 + copyLength4);
          uVar26 = ((char * (*)())_glp_dtostr)(iVar12,(int)uVar26,outCursor,
                               (int)outBuf + (outBufCapacity - (int)outCursor),(double)pfVar24[1],1e-07,
                               in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_fffffd08,
                               in_stack_fffffd10,in_stack_fffffd18,in_stack_fffffd20,
                               in_stack_fffffd28);
          iVar12 = (int)((ulonglong)uVar26 >> 0x20);
          ch = ',';
          copyIndex = 0;
          do {
            *(char *)(iVar12 + copyIndex) = ch;
            copyLength4 = copyIndex + 1;
            ch = ", "[copyIndex + 1];
            copyIndex = copyLength4;
          } while (ch != '\0');
          outCursor = (int *)(iVar12 + copyLength4);
          uVar26 = ((char * (*)())_glp_dtostr)(iVar12,(int)uVar26,outCursor,
                               (int)outBuf + (outBufCapacity - (int)outCursor),(double)pfVar24[2],1e-07,
                               in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_fffffd08,
                               in_stack_fffffd10,in_stack_fffffd18,in_stack_fffffd20,
                               in_stack_fffffd28);
          iVar12 = (int)((ulonglong)uVar26 >> 0x20);
          ch = ',';
          copyIndex = 0;
          do {
            *(char *)(iVar12 + copyIndex) = ch;
            nextIndex3 = copyIndex + 1;
            ch = ", "[copyIndex + 1];
            copyIndex = nextIndex3;
          } while (ch != '\0');
          outCursor = (int *)(iVar12 + nextIndex3);
          outCursor = (int *)((char * (*)())_glp_dtostr)(iVar12,(int)uVar26,outCursor,
                                        (int)outBuf + (outBufCapacity - (int)outCursor),
                                        (double)pfVar24[3],1e-07,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8
                                        ,in_stack_fffffd08,in_stack_fffffd10,in_stack_fffffd18,
                                        in_stack_fffffd20,in_stack_fffffd28);
          ch = '}';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            nextIndex2 = copyIndex + 1;
            ch = "}"[copyIndex + 1];
            copyIndex = nextIndex2;
          } while (ch != '\0');
          break;
        case 2:
          ch = '{';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            nextIndex2 = copyIndex + 1;
            ch = "{-- Fixed constant data not currently supported --}"[copyIndex + 1];
            copyIndex = nextIndex2;
          } while (ch != '\0');
          break;
        case 3:
        case 4:
          ch = '{';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            copyLength = copyIndex + 1;
            ch = "{"[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + copyLength);
          copyEnd2 = ((int (*)())_ncpy_97be5f58)(outCursor, *(unsigned int *)pfVar24);
          ch = ',';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex + copyEnd2) = ch;
            copyLength4 = copyIndex + 1;
            ch = ", "[copyIndex + 1];
            copyIndex = copyLength4;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + copyLength4 + copyEnd2);
          copyEnd2 = ((int (*)())_ncpy_97be5f58)(outCursor, ((unsigned int *)pfVar24)[1]);
          ch = ',';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex + copyEnd2) = ch;
            copyLength4 = copyIndex + 1;
            ch = ", "[copyIndex + 1];
            copyIndex = copyLength4;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + copyLength4 + copyEnd2);
          copyEnd2 = ((int (*)())_ncpy_97be5f58)(outCursor, ((unsigned int *)pfVar24)[2]);
          ch = ',';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex + copyEnd2) = ch;
            nextIndex3 = copyIndex + 1;
            ch = ", "[copyIndex + 1];
            copyIndex = nextIndex3;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + nextIndex3 + copyEnd2);
          copyEnd = ((int (*)())_ncpy_97be5f58)(outCursor, ((unsigned int *)pfVar24)[3]);
          ch = '}';
          outCursor = (int *)((int)outCursor + copyEnd);
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            copyLength = copyIndex + 1;
            ch = "}"[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          goto LAB_97bed34c;
        default:
          goto switchD_97bebb8c_caseD_0;
        }
        break;
      case 0x12:
        ch = 'n';
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex) = ch;
          nextIndex2 = copyIndex + 1;
          ch = "normalscale"[copyIndex + 1];
          copyIndex = nextIndex2;
        } while (ch != '\0');
      }
      outCursor = (int *)((int)outCursor + nextIndex2);
switchD_97bebb8c_caseD_0:
      if (*(int *)(paramArrayPos + (uint)*(ushort *)((int)nextIndex5 + iVar9 + 6) * 4) == -1) {
        ch = ';';
        copyIndex2 = 0;
        do {
          *(char *)((int)outCursor + copyIndex2) = ch;
          copyLength2 = copyIndex2 + 1;
          ch = ";\n"[copyIndex2 + 1];
          copyIndex2 = copyLength2;
        } while (ch != '\0');
      }
      else if (elementInArray + 1 == arraySizes[arrayIndex]) {
        ch = '\n';
        arrayIndex = arrayIndex + 1;
        copyIndex2 = 0;
        do {
          *(char *)((int)outCursor + copyIndex2) = ch;
          copyLength2 = copyIndex2 + 1;
          ch = "\n};\n"[copyIndex2 + 1];
          copyIndex2 = copyLength2;
        } while (ch != '\0');
      }
      else {
        ch = ',';
        copyIndex2 = 0;
        do {
          *(char *)((int)outCursor + copyIndex2) = ch;
          copyLength2 = copyIndex2 + 1;
          ch = ",\n"[copyIndex2 + 1];
          copyIndex2 = copyLength2;
        } while (ch != '\0');
      }
      outCursor = (int *)((int)outCursor + copyLength2);
      uVar26 = ((int (*)())_adjustAllocation_97be9cb4)(&outBufCapacity,&outBuf,&outCursor);
      bVar1 = bVar3;
      if ((int)((ulonglong)uVar26 >> 0x20) == 0) goto joined_r0x97beb668;
LAB_97bed4a8:
      loopIndex = loopIndex + 1;
    } while (loopIndex < (int)paramCount);
  }
  if (arraySizes != (int *)0x0) {
    _free(arraySizes);
    uVar26 = CONCAT44(extraout_r3_00,extraout_r4_05);
  }
  ch = '\n';
  copyIndex4 = 0;
  do {
    *(char *)((int)outCursor + copyIndex4) = ch;
    copyLength3 = copyIndex4 + 1;
    ch = "\n"[copyIndex4 + 1];
    copyIndex4 = copyLength3;
  } while (ch != '\0');
  outCursor = (int *)((int)outCursor + copyLength3);
LAB_97bed528:
  outputCount = program[0xc];
  loopIndex = 0;
  outputOffset = program[0xd];
  bVar1 = bVar3;
  if (0 < (int)outputCount) {
    do {
      uVar23 = program[outputOffset * 2 + loopIndex * 2] >> 0x10 & 0xf;
      if (uVar23 == 0) goto LAB_97bedcb4;
      uVar25 = program[outputOffset * 2 + loopIndex * 2] >> 0x1d;
      if (uVar25 == 1) {
        ch = 'L';
        copyIndex2 = 0;
        do {
          *(char *)((int)outCursor + copyIndex2) = ch;
          copyLength2 = copyIndex2 + 1;
          ch = "LONG OUTPUT res"[copyIndex2 + 1];
          copyIndex2 = copyLength2;
        } while (ch != '\0');
LAB_97bed640:
        outCursor = (int *)((int)outCursor + copyLength2);
      }
      else if (uVar25 < 2) {
        if (uVar25 == 0) {
          ch = 'O';
          copyIndex2 = 0;
          do {
            *(char *)((int)outCursor + copyIndex2) = ch;
            copyLength2 = copyIndex2 + 1;
            ch = "OUTPUT res"[copyIndex2 + 1];
            copyIndex2 = copyLength2;
          } while (ch != '\0');
          goto LAB_97bed640;
        }
      }
      else if (uVar25 == 2) {
        ch = 'S';
        copyIndex2 = 0;
        do {
          *(char *)((int)outCursor + copyIndex2) = ch;
          copyLength2 = copyIndex2 + 1;
          ch = "SHORT OUTPUT res"[copyIndex2 + 1];
          copyIndex2 = copyLength2;
        } while (ch != '\0');
        goto LAB_97bed640;
      }
      copyEnd3 = ((int (*)())_ncpy_97be5f58)(outCursor,(uint)*(ushort *)((int)program + loopIndex * 8 + outputOffset * 8 + 6));
      outCursor = (int *)((int)outCursor + copyEnd3);
      if (!bVar2) {
        uVar25 = program[outputOffset * 2 + loopIndex * 2];
        outCursor = (int *)((int (*)())_glpWriteSizeTypePrecision)(outCursor,uVar25 >> 0x18 & 3,0,uVar25 >> 0x1a & 7,uVar25 >> 0x1d
                                    );
      }
      ch = ' ';
      copyIndex2 = 0;
      do {
        *(char *)((int)outCursor + copyIndex2) = ch;
        copyLength2 = copyIndex2 + 1;
        ch = " = "[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      outCursor = (int *)((int)outCursor + copyLength2);
      switch(uVar23) {
      default:
        goto switchD_97bed6f4_caseD_0;
      case 1:
        ch = 'r';
        copyIndex2 = 0;
        do {
          *(char *)((int)outCursor + copyIndex2) = ch;
          copyLength2 = copyIndex2 + 1;
          ch = "result.position"[copyIndex2 + 1];
          copyIndex2 = copyLength2;
        } while (ch != '\0');
        break;
      case 2:
        ch = 'r';
        copyIndex2 = 0;
        do {
          *(char *)((int)outCursor + copyIndex2) = ch;
          copyLength2 = copyIndex2 + 1;
          ch = "result.fogcoord"[copyIndex2 + 1];
          copyIndex2 = copyLength2;
        } while (ch != '\0');
        break;
      case 3:
        ch = 'r';
        copyIndex2 = 0;
        do {
          *(char *)((int)outCursor + copyIndex2) = ch;
          copyLength2 = copyIndex2 + 1;
          ch = "result.pointsize"[copyIndex2 + 1];
          copyIndex2 = copyLength2;
        } while (ch != '\0');
        break;
      case 4:
        ch = 'r';
        copyIndex2 = 0;
        do {
          *(char *)((int)outCursor + copyIndex2) = ch;
          copyLength2 = copyIndex2 + 1;
          ch = "result.color"[copyIndex2 + 1];
          copyIndex2 = copyLength2;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + copyLength2);
        if ((programTarget == 0x8620) || (programTarget == 0x8b31)) {
          if ((program[outputOffset * 2 + loopIndex * 2] & 1) == 0) {
            ch = '.';
            copyIndex2 = 0;
            do {
              *(char *)((int)outCursor + copyIndex2) = ch;
              copyLength2 = copyIndex2 + 1;
              ch = ".front.primary"[copyIndex2 + 1];
              copyIndex2 = copyLength2;
            } while (ch != '\0');
          }
          else {
            if ((program[outputOffset * 2 + loopIndex * 2] & 1) != 1) goto switchD_97bed6f4_caseD_0;
            ch = '.';
            copyIndex2 = 0;
            do {
              *(char *)((int)outCursor + copyIndex2) = ch;
              copyLength2 = copyIndex2 + 1;
              ch = ".back.primary"[copyIndex2 + 1];
              copyIndex2 = copyLength2;
            } while (ch != '\0');
          }
          break;
        }
        if (((programTarget == 0x8804) || (programTarget == 0x8b30)) &&
           (1 < (program[outputOffset * 2 + loopIndex * 2] >> 1 & 7))) {
          ch = '[';
          copyIndex2 = 0;
          do {
            *(char *)((int)outCursor + copyIndex2) = ch;
            copyLength2 = copyIndex2 + 1;
            ch = "["[copyIndex2 + 1];
            copyIndex2 = copyLength2;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + copyLength2);
          copyEnd = ((int (*)())_ncpy_97be5f58)(outCursor,program[outputOffset * 2 + loopIndex * 2] >> 1 & 7);
          ch = ']';
          copyIndex2 = 0;
          do {
            *(char *)((int)outCursor + copyIndex2 + copyEnd) = ch;
            copyLength = copyIndex2 + 1;
            ch = "]"[copyIndex2 + 1];
            copyIndex2 = copyLength;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + copyLength + copyEnd);
        }
        goto switchD_97bed6f4_caseD_0;
      case 5:
        ch = 'r';
        copyIndex2 = 0;
        do {
          *(char *)((int)outCursor + copyIndex2) = ch;
          copyLength2 = copyIndex2 + 1;
          ch = "result.color"[copyIndex2 + 1];
          copyIndex2 = copyLength2;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + copyLength2);
        if ((programTarget == 0x8620) || (programTarget == 0x8b31)) {
          if ((program[outputOffset * 2 + loopIndex * 2] & 1) == 0) {
            ch = '.';
            copyIndex2 = 0;
            do {
              *(char *)((int)outCursor + copyIndex2) = ch;
              copyLength2 = copyIndex2 + 1;
              ch = ".front.secondary"[copyIndex2 + 1];
              copyIndex2 = copyLength2;
            } while (ch != '\0');
          }
          else {
            if ((program[outputOffset * 2 + loopIndex * 2] & 1) != 1) goto switchD_97bed6f4_caseD_0;
            ch = '.';
            copyIndex2 = 0;
            do {
              *(char *)((int)outCursor + copyIndex2) = ch;
              copyLength2 = copyIndex2 + 1;
              ch = ".back.secondary"[copyIndex2 + 1];
              copyIndex2 = copyLength2;
            } while (ch != '\0');
          }
          break;
        }
        goto switchD_97bed6f4_caseD_0;
      case 6:
        ch = 'r';
        copyIndex2 = 0;
        do {
          *(char *)((int)outCursor + copyIndex2) = ch;
          copyLength2 = copyIndex2 + 1;
          ch = "result.texcoord["[copyIndex2 + 1];
          copyIndex2 = copyLength2;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + copyLength2);
        copyEnd3 = ((int (*)())_ncpy_97be5f58)(outCursor,program[outputOffset * 2 + loopIndex * 2] & 0x1f);
        ch = ']';
        outCursor = (int *)((int)outCursor + copyEnd3);
        copyIndex2 = 0;
        do {
          *(char *)((int)outCursor + copyIndex2) = ch;
          copyLength2 = copyIndex2 + 1;
          ch = "]"[copyIndex2 + 1];
          copyIndex2 = copyLength2;
        } while (ch != '\0');
        break;
      case 7:
        ch = 'r';
        copyIndex2 = 0;
        do {
          *(char *)((int)outCursor + copyIndex2) = ch;
          copyLength2 = copyIndex2 + 1;
          ch = "result.depth"[copyIndex2 + 1];
          copyIndex2 = copyLength2;
        } while (ch != '\0');
        break;
      case 8:
        ch = 'r';
        copyIndex2 = 0;
        do {
          *(char *)((int)outCursor + copyIndex2) = ch;
          copyLength2 = copyIndex2 + 1;
          ch = "result.eyePosition"[copyIndex2 + 1];
          copyIndex2 = copyLength2;
        } while (ch != '\0');
        break;
      case 9:
        ch = 'r';
        copyIndex2 = 0;
        do {
          *(char *)((int)outCursor + copyIndex2) = ch;
          copyLength2 = copyIndex2 + 1;
          ch = "result.clipVertex"[copyIndex2 + 1];
          copyIndex2 = copyLength2;
        } while (ch != '\0');
        break;
      case 10:
        ch = 'r';
        copyIndex2 = 0;
        do {
          *(char *)((int)outCursor + copyIndex2) = ch;
          copyLength2 = copyIndex2 + 1;
          ch = "result.attrib["[copyIndex2 + 1];
          copyIndex2 = copyLength2;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + copyLength2);
        copyEnd3 = ((int (*)())_ncpy_97be5f58)(outCursor,program[outputOffset * 2 + loopIndex * 2] & 0x1f);
        ch = ']';
        outCursor = (int *)((int)outCursor + copyEnd3);
        copyIndex2 = 0;
        do {
          *(char *)((int)outCursor + copyIndex2) = ch;
          copyLength2 = copyIndex2 + 1;
          ch = "]"[copyIndex2 + 1];
          copyIndex2 = copyLength2;
        } while (ch != '\0');
      }
      outCursor = (int *)((int)outCursor + copyLength2);
switchD_97bed6f4_caseD_0:
      ch = ';';
      copyIndex2 = 0;
      do {
        *(char *)((int)outCursor + copyIndex2) = ch;
        copyLength2 = copyIndex2 + 1;
        ch = ";\n"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      outCursor = (int *)((int)outCursor + copyLength2);
      uVar26 = ((int (*)())_adjustAllocation_97be9cb4)(&outBufCapacity,&outBuf,&outCursor);
      if ((int)((ulonglong)uVar26 >> 0x20) == 0) goto joined_r0x97beb668;
LAB_97bedcb4:
      loopIndex = loopIndex + 1;
    } while (loopIndex < (int)outputCount);
  }
  if ((outputCount != 0) || (bVar2)) {
    ch = '\n';
    copyIndex4 = 0;
    do {
      *(char *)((int)outCursor + copyIndex4) = ch;
      copyLength3 = copyIndex4 + 1;
      ch = "\n"[copyIndex4 + 1];
      copyIndex4 = copyLength3;
    } while (ch != '\0');
    outCursor = (int *)((int)outCursor + copyLength3);
  }
  instructionCount = program[0x14];
  iVar22 = 0;
  instructionOffset = program[0x15];
  uVar19 = instructionCount;
  if (0 < (int)instructionCount) {
    do {
      if ((program[instructionOffset * 2 + iVar22 * 2] >> 0x12 & 0xff) - 0x4b < 2) {
        labelCount = labelCount + 1;
      }
      iVar22 = iVar22 + (program[instructionOffset * 2 + iVar22 * 2] >> 0x1d) + 2;
      uVar19 = uVar19 - 1;
    } while (uVar19 != 0);
  }
  bVar4 = labelCount == 0;
  if (!bVar4) {
    allocation2 = labelCount << 2;
    loopIndex2 = 0;
    loopIndex4 = 0;
    labelIds = _malloc(allocation2);
    _memset(labelIds,0,labelCount);
    labelValues = _malloc(allocation2);
    memsetResult = _memset(labelValues,0,labelCount);
    uVar26 = CONCAT44(memsetResult,extraout_r4_06);
    labelCount = 0;
    bVar4 = true;
    if (0 < (int)instructionCount) {
      do {
        uVar19 = program[instructionOffset * 2 + loopIndex4 * 2];
        if ((uVar19 >> 0x12 & 0xff) - 0x4b < 2) {
          uVar26 = ((int (*)())_InsertLabel)(labelIds,labelValues,program[instructionOffset * 2 + loopIndex4 * 2 + 1] & 0x3ffff,
                                uVar19 & 0x3ffff,labelCount);
          labelCount = (int)((ulonglong)uVar26 >> 0x20);
          uVar19 = program[instructionOffset * 2 + loopIndex4 * 2];
        }
        loopIndex2 = loopIndex2 + 1;
        loopIndex4 = loopIndex4 + (uVar19 >> 0x1d) + 2;
        bVar4 = labelCount == 0;
      } while (loopIndex2 < (int)instructionCount);
    }
  }
  loopIndex = 0;
  loopIndex5 = 0;
  if (0 < (int)instructionCount) {
    puVar21 = (uint *)(nextLabelNumber * 4 + labelIds);
    do {
      if (((program[instructionOffset * 2 + loopIndex5 * 2] & 0x3ffff) == 0) && (!bVar2)) {
        ch = 'm';
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex) = ch;
          copyLength = copyIndex + 1;
          ch = "main:\n"[copyIndex + 1];
          copyIndex = copyLength;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + copyLength);
      }
      if (((!bVar4) && (nextLabelNumber < labelCount)) &&
         ((program[instructionOffset * 2 + loopIndex5 * 2] & 0x3ffff) == *puVar21)) {
        loopIndex3 = 0;
        indentDepth = indentDepth + -1;
        if (0 < indentDepth) {
          do {
            ch = ' ';
            copyIndex3 = 0;
            do {
              *(char *)((int)outCursor + copyIndex3) = ch;
              copyLength4 = copyIndex3 + 1;
              ch = "  "[copyIndex3 + 1];
              copyIndex3 = copyLength4;
            } while (ch != '\0');
            loopIndex3 = loopIndex3 + 1;
            outCursor = (int *)((int)outCursor + copyLength4);
          } while (loopIndex3 < indentDepth);
        }
        ch = 'l';
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex) = ch;
          copyLength = copyIndex + 1;
          ch = "label_"[copyIndex + 1];
          copyIndex = copyLength;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + copyLength);
        copyEnd2 = ((int (*)())_ncpy_97be5f58)(outCursor,nextLabelNumber);
        ch = ':';
        nextLabelNumber = nextLabelNumber + 1;
        puVar21 = puVar21 + 1;
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex + copyEnd2) = ch;
          nextIndex3 = copyIndex + 1;
          ch = ":\n"[copyIndex + 1];
          copyIndex = nextIndex3;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + nextIndex3 + copyEnd2);
        indentDepth = indentDepth + 1;
      }
      uVar19 = program[instructionOffset * 2 + loopIndex5 * 2] >> 0x12 & 0xff;
      if (((uVar19 == 0x6b) || (uVar19 == 0x58)) ||
         ((uVar19 == 0x59 || ((uVar19 == 0x5a || (uVar19 == 0x5b)))))) {
        indentDepth = indentDepth + -1;
      }
      ((int (*)())_glpDisassemble1Op)(program + instructionOffset * 2 + loopIndex5 * 2,outCursor,&outWordCount,&outTextLength,paramNumbers,
                         paramArrayPos,tempNumbers,tempArrayPos,labelIds,&indentDepth,printOptions);
      outCursor = (int *)((int)outCursor + outTextLength);
      loopIndex5 = loopIndex5 + outWordCount;
      uVar26 = ((int (*)())_adjustAllocation_97be9cb4)(&outBufCapacity,&outBuf,&outCursor);
      if ((int)((ulonglong)uVar26 >> 0x20) == 0) {
        if (!bVar3) {
          _free(paramNumbers);
          _free(paramArrayPos);
        }
        if (!(bool)((byte)((uint)cr0Image >> 0x1d) & 1)) {
          _free(tempNumbers);
        }
        if (!(bool)((byte)((uint)cr0Image2 >> 0x1d) & 1)) {
          _free(tempArrayPos);
        }
        if (bVar4) goto LAB_97bf0cec;
        _free(labelIds);
        iVar22 = labelValues;
        goto LAB_97bee10c;
      }
      loopIndex = loopIndex + 1;
      loopIndex5 = loopIndex5 + 1;
    } while (loopIndex < (int)instructionCount);
  }
  if (!bVar4) {
    if ((nextLabelNumber < labelCount) && (loopIndex + 1 == *(int *)(labelIds + nextLabelNumber * 4))) {
      ch = ' ';
      copyIndex4 = 0;
      do {
        *(char *)((int)outCursor + copyIndex4) = ch;
        copyLength3 = copyIndex4 + 1;
        ch = "  label_"[copyIndex4 + 1];
        copyIndex4 = copyLength3;
      } while (ch != '\0');
      outCursor = (int *)((int)outCursor + copyLength3);
      copyEnd3 = ((int (*)())_ncpy_97be5f58)(outCursor,nextLabelNumber);
      ch = ':';
      copyIndex4 = 0;
      do {
        *(char *)((int)outCursor + copyIndex4 + copyEnd3) = ch;
        copyLength2 = copyIndex4 + 1;
        ch = ":\n"[copyIndex4 + 1];
        copyIndex4 = copyLength2;
      } while (ch != '\0');
      outCursor = (int *)((int)outCursor + copyLength2 + copyEnd3);
    }
    _free(labelIds);
    _free(labelValues);
    uVar26 = CONCAT44(extraout_r3_01,extraout_r4_07);
  }
  ch = 'E';
  copyIndex4 = 0;
  do {
    *(char *)((int)outCursor + copyIndex4) = ch;
    copyLength3 = copyIndex4 + 1;
    ch = "END\n"[copyIndex4 + 1];
    copyIndex4 = copyLength3;
  } while (ch != '\0');
  stateCount = program[0x18];
  loopIndex = 0;
  stateOffset = program[0x19];
  outCursor = (int *)((int)outCursor + copyLength3);
  loopIndex5 = 0;
  if (0 < (int)stateCount) {
    dataBase = "o intialize the Preprocessor";
    do {
      ch = 'S';
      uVar20 = program[stateOffset * 2 + loopIndex5 * 2];
      loopIndex4 = 0;
      do {
        *(char *)((int)outCursor + loopIndex4) = ch;
        copyLength = loopIndex4 + 1;
        ch = "STATE "[loopIndex4 + 1];
        loopIndex4 = copyLength;
      } while (ch != '\0');
      outCursor = (int *)((int)outCursor + copyLength);
      switch(uVar20 >> 0x18 & 7) {
      case 0:
        ch = 'A';
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex) = ch;
          copyLength = copyIndex + 1;
          ch = "ALPHA_TEST "[copyIndex + 1];
          copyIndex = copyLength;
        } while (ch != '\0');
        switch(program[stateOffset * 2 + loopIndex5 * 2] & 7) {
        case 0:
          ch = 'P';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex + copyLength) = ch;
            nextIndex3 = copyIndex + 1;
            ch = "PP_NEVER "[copyIndex + 1];
            copyIndex = nextIndex3;
          } while (ch != '\0');
          break;
        case 1:
          ch = 'P';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex + copyLength) = ch;
            nextIndex3 = copyIndex + 1;
            ch = "PP_LESS "[copyIndex + 1];
            copyIndex = nextIndex3;
          } while (ch != '\0');
          break;
        case 2:
          ch = 'P';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex + copyLength) = ch;
            nextIndex3 = copyIndex + 1;
            ch = "PP_EQUAL "[copyIndex + 1];
            copyIndex = nextIndex3;
          } while (ch != '\0');
          break;
        case 3:
          ch = 'P';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex + copyLength) = ch;
            nextIndex3 = copyIndex + 1;
            ch = "PP_LEQUAL "[copyIndex + 1];
            copyIndex = nextIndex3;
          } while (ch != '\0');
          break;
        case 4:
          ch = 'P';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex + copyLength) = ch;
            nextIndex3 = copyIndex + 1;
            ch = "PP_GREATER "[copyIndex + 1];
            copyIndex = nextIndex3;
          } while (ch != '\0');
          break;
        case 5:
          ch = 'P';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex + copyLength) = ch;
            nextIndex3 = copyIndex + 1;
            ch = "PP_NOTEQUAL "[copyIndex + 1];
            copyIndex = nextIndex3;
          } while (ch != '\0');
          break;
        case 6:
          ch = 'P';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex + copyLength) = ch;
            nextIndex3 = copyIndex + 1;
            ch = "PP_GEQUAL "[copyIndex + 1];
            copyIndex = nextIndex3;
          } while (ch != '\0');
          break;
        default:
          ch = 'P';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex + copyLength) = ch;
            nextIndex3 = copyIndex + 1;
            ch = "PP_ALWAYS "[copyIndex + 1];
            copyIndex = nextIndex3;
          } while (ch != '\0');
        }
        ch = 'r';
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex + nextIndex3 + copyLength) = ch;
          copyLength5 = copyIndex + 1;
          ch = "ref="[copyIndex + 1];
          copyIndex = copyLength5;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + copyLength5 + nextIndex3 + copyLength);
        outCursor = (int *)((char * (*)())_glp_dtostr)((int)((ulonglong)uVar26 >> 0x20),(int)uVar26,outCursor,
                                      (int)outBuf + (outBufCapacity - (int)outCursor),
                                      (double)GH_U2F((unsigned int)(program[stateOffset * 2 + loopIndex5 * 2 + 1])),1e-07,in_f3
                                      ,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_fffffd08,
                                      in_stack_fffffd10,in_stack_fffffd18,in_stack_fffffd20,
                                      in_stack_fffffd28);
        goto switchD_97bee2f0_default;
      case 1:
        ch = 'S';
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex) = ch;
          copyLength = copyIndex + 1;
          ch = "STENCIL_TEST func="[copyIndex + 1];
          copyIndex = copyLength;
        } while (ch != '\0');
        switch(program[stateOffset * 2 + loopIndex5 * 2] >> 0xc & 7) {
        case 0:
          ch = 'P';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex + copyLength) = ch;
            nextIndex3 = copyIndex + 1;
            ch = "PP_NEVER "[copyIndex + 1];
            copyIndex = nextIndex3;
          } while (ch != '\0');
          break;
        case 1:
          ch = 'P';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex + copyLength) = ch;
            nextIndex3 = copyIndex + 1;
            ch = "PP_LESS "[copyIndex + 1];
            copyIndex = nextIndex3;
          } while (ch != '\0');
          break;
        case 2:
          ch = 'P';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex + copyLength) = ch;
            nextIndex3 = copyIndex + 1;
            ch = "PP_EQUAL "[copyIndex + 1];
            copyIndex = nextIndex3;
          } while (ch != '\0');
          break;
        case 3:
          ch = 'P';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex + copyLength) = ch;
            nextIndex3 = copyIndex + 1;
            ch = "PP_LEQUAL "[copyIndex + 1];
            copyIndex = nextIndex3;
          } while (ch != '\0');
          break;
        case 4:
          ch = 'P';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex + copyLength) = ch;
            nextIndex3 = copyIndex + 1;
            ch = "PP_GREATER "[copyIndex + 1];
            copyIndex = nextIndex3;
          } while (ch != '\0');
          break;
        case 5:
          ch = 'P';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex + copyLength) = ch;
            nextIndex3 = copyIndex + 1;
            ch = "PP_NOTEQUAL "[copyIndex + 1];
            copyIndex = nextIndex3;
          } while (ch != '\0');
          break;
        case 6:
          ch = 'P';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex + copyLength) = ch;
            nextIndex3 = copyIndex + 1;
            ch = "PP_GEQUAL "[copyIndex + 1];
            copyIndex = nextIndex3;
          } while (ch != '\0');
          break;
        default:
          ch = 'P';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex + copyLength) = ch;
            nextIndex3 = copyIndex + 1;
            ch = "PP_ALWAYS "[copyIndex + 1];
            copyIndex = nextIndex3;
          } while (ch != '\0');
        }
        ch = 'o';
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex + nextIndex3 + copyLength) = ch;
          copyLength5 = copyIndex + 1;
          ch = "opfail="[copyIndex + 1];
          copyIndex = copyLength5;
        } while (ch != '\0');
        outBytePtr = (undefined1 *)((int)outCursor + copyLength5 + nextIndex3 + copyLength);
        switch(program[stateOffset * 2 + loopIndex5 * 2] >> 0xf & 7) {
        case 0:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_STENCIL_ZERO "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 1:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_STENCIL_KEEP "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 2:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_STENCIL_REPLACE "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 3:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_STENCIL_INCR "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 4:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_STENCIL_DECR "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 5:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_STENCIL_INVERT "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 6:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_STENCIL_INCR_WRAP "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 7:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_STENCIL_DECR_WRAP "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        default:
          goto switchD_97bee894_default;
        }
        outBytePtr = outBytePtr + copyLength;
switchD_97bee894_default:
        ch = 'o';
        copyIndex = 0;
        do {
          outBytePtr[copyIndex] = ch;
          copyLength = copyIndex + 1;
          ch = "opzfail="[copyIndex + 1];
          copyIndex = copyLength;
        } while (ch != '\0');
        outBytePtr = outBytePtr + copyLength;
        switch(program[stateOffset * 2 + loopIndex5 * 2] >> 0x12 & 7) {
        case 0:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_STENCIL_ZERO "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 1:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_STENCIL_KEEP "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 2:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_STENCIL_REPLACE "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 3:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_STENCIL_INCR "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 4:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_STENCIL_DECR "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 5:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_STENCIL_INVERT "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 6:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_STENCIL_INCR_WRAP "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 7:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_STENCIL_DECR_WRAP "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        default:
          goto switchD_97beeaec_default;
        }
        outBytePtr = outBytePtr + copyLength;
switchD_97beeaec_default:
        ch = 'o';
        copyIndex = 0;
        do {
          outBytePtr[copyIndex] = ch;
          copyLength = copyIndex + 1;
          ch = "opzpass="[copyIndex + 1];
          copyIndex = copyLength;
        } while (ch != '\0');
        outCursor = (int *)(outBytePtr + copyLength);
        switch(program[stateOffset * 2 + loopIndex5 * 2] >> 0x15 & 7) {
        case 0:
          ch = 'P';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            copyLength = copyIndex + 1;
            ch = "PP_STENCIL_ZERO "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 1:
          ch = 'P';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            copyLength = copyIndex + 1;
            ch = "PP_STENCIL_KEEP "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 2:
          ch = 'P';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            copyLength = copyIndex + 1;
            ch = "PP_STENCIL_REPLACE "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 3:
          ch = 'P';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            copyLength = copyIndex + 1;
            ch = "PP_STENCIL_INCR "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 4:
          ch = 'P';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            copyLength = copyIndex + 1;
            ch = "PP_STENCIL_DECR "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 5:
          ch = 'P';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            copyLength = copyIndex + 1;
            ch = "PP_STENCIL_INVERT "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 6:
          ch = 'P';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            copyLength = copyIndex + 1;
            ch = "PP_STENCIL_INCR_WRAP "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 7:
          ch = 'P';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            copyLength = copyIndex + 1;
            ch = "PP_STENCIL_DECR_WRAP "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        default:
          goto switchD_97beed44_default;
        }
        outCursor = (int *)((int)outCursor + copyLength);
switchD_97beed44_default:
        _sprintf(&local_2b0,"ref= %#x mask = %#x ",program[stateOffset * 2 + loopIndex5 * 2 + 1] >> 0x18,
                 program[stateOffset * 2 + loopIndex5 * 2 + 1] >> 8 & 0xff);
        nextIndex = 0;
        ch = local_2b0;
        while (ch != '\0') {
          *(char *)((int)outCursor + nextIndex) = ch;
          ch = acStack_2af[nextIndex];
          nextIndex = nextIndex + 1;
        }
        break;
      case 2:
        ch = 'D';
        loopIndex4 = 0;
        do {
          *(char *)((int)outCursor + loopIndex4) = ch;
          copyLength = loopIndex4 + 1;
          ch = "DEPTH_TEST func="[loopIndex4 + 1];
          loopIndex4 = copyLength;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + copyLength);
        switch(program[stateOffset * 2 + loopIndex5 * 2] & 7) {
        case 0:
          ch = 'P';
          copyIndex3 = 0;
          do {
            *(char *)((int)outCursor + copyIndex3) = ch;
            nextIndex = copyIndex3 + 1;
            ch = "PP_NEVER "[copyIndex3 + 1];
            copyIndex3 = nextIndex;
          } while (ch != '\0');
          break;
        case 1:
          ch = 'P';
          copyIndex3 = 0;
          do {
            *(char *)((int)outCursor + copyIndex3) = ch;
            nextIndex = copyIndex3 + 1;
            ch = "PP_LESS "[copyIndex3 + 1];
            copyIndex3 = nextIndex;
          } while (ch != '\0');
          break;
        case 2:
          ch = 'P';
          copyIndex3 = 0;
          do {
            *(char *)((int)outCursor + copyIndex3) = ch;
            nextIndex = copyIndex3 + 1;
            ch = "PP_EQUAL "[copyIndex3 + 1];
            copyIndex3 = nextIndex;
          } while (ch != '\0');
          break;
        case 3:
          ch = 'P';
          copyIndex3 = 0;
          do {
            *(char *)((int)outCursor + copyIndex3) = ch;
            nextIndex = copyIndex3 + 1;
            ch = "PP_LEQUAL "[copyIndex3 + 1];
            copyIndex3 = nextIndex;
          } while (ch != '\0');
          break;
        case 4:
          ch = 'P';
          copyIndex3 = 0;
          do {
            *(char *)((int)outCursor + copyIndex3) = ch;
            nextIndex = copyIndex3 + 1;
            ch = "PP_GREATER "[copyIndex3 + 1];
            copyIndex3 = nextIndex;
          } while (ch != '\0');
          break;
        case 5:
          ch = 'P';
          copyIndex3 = 0;
          do {
            *(char *)((int)outCursor + copyIndex3) = ch;
            nextIndex = copyIndex3 + 1;
            ch = "PP_NOTEQUAL "[copyIndex3 + 1];
            copyIndex3 = nextIndex;
          } while (ch != '\0');
          break;
        case 6:
          ch = 'P';
          copyIndex3 = 0;
          do {
            *(char *)((int)outCursor + copyIndex3) = ch;
            nextIndex = copyIndex3 + 1;
            ch = "PP_GEQUAL "[copyIndex3 + 1];
            copyIndex3 = nextIndex;
          } while (ch != '\0');
          break;
        default:
          ch = 'P';
          copyIndex3 = 0;
          do {
            *(char *)((int)outCursor + copyIndex3) = ch;
            nextIndex = copyIndex3 + 1;
            ch = "PP_ALWAYS "[copyIndex3 + 1];
            copyIndex3 = nextIndex;
          } while (ch != '\0');
        }
        break;
      case 3:
        ch = 'B';
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex) = ch;
          copyLength = copyIndex + 1;
          ch = "BLENDING \n\talpha equ = "[copyIndex + 1];
          copyIndex = copyLength;
        } while (ch != '\0');
        outBytePtr = (undefined1 *)((int)outCursor + copyLength);
        switch(program[stateOffset * 2 + loopIndex5 * 2] >> 0x13 & 7) {
        case 0:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_FUNC_ADD "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 1:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_FUNC_SUBTRACT "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 2:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_FUNC_REVERSE_SUBTRACT "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 3:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_FUNC_MIN "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 4:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_FUNC_MAX "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        default:
          goto switchD_97bef244_default;
        }
        outBytePtr = outBytePtr + copyLength;
switchD_97bef244_default:
        ch = '\n';
        copyIndex = 0;
        do {
          outBytePtr[copyIndex] = ch;
          copyLength = copyIndex + 1;
          ch = "\n\trgb equ = "[copyIndex + 1];
          copyIndex = copyLength;
        } while (ch != '\0');
        outBytePtr = outBytePtr + copyLength;
        switch(program[stateOffset * 2 + loopIndex5 * 2] >> 0x10 & 7) {
        case 0:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_FUNC_ADD "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 1:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_FUNC_SUBTRACT "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 2:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_FUNC_REVERSE_SUBTRACT "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 3:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_FUNC_MIN "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 4:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_FUNC_MAX "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        default:
          goto switchD_97bef3e8_default;
        }
        outBytePtr = outBytePtr + copyLength;
switchD_97bef3e8_default:
        ch = '\n';
        copyIndex = 0;
        do {
          outBytePtr[copyIndex] = ch;
          copyLength = copyIndex + 1;
          ch = "\n\tsrc = "[copyIndex + 1];
          copyIndex = copyLength;
        } while (ch != '\0');
        outBytePtr = outBytePtr + copyLength;
        switch(program[stateOffset * 2 + loopIndex5 * 2] & 0xf) {
        case 0:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_ZERO "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 1:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_ONE "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 2:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_SRC_COLOR "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 3:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_ONE_MINUS_SRC_COLOR "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 4:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_SRC_ALPHA "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 5:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_ONE_MINUS_SRC_ALPHA "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 6:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_DST_ALPHA "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 7:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_ONE_MINUS_DST_ALPHA "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 8:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_CONSTANT_COLOR "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 9:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_ONE_MINUS_CONSTANT_COLOR "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 10:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_CONSTANT_ALPHA "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 0xb:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_ONE_MINUS_CONSTANT_ALPHA "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 0xc:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_DST_COLOR "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 0xd:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_ONE_MINUS_DST_COLOR "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 0xe:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_SRC_ALPHA_SATURATE "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        default:
          goto switchD_97bef58c_default;
        }
        outBytePtr = outBytePtr + copyLength;
switchD_97bef58c_default:
        ch = '\n';
        copyIndex = 0;
        do {
          outBytePtr[copyIndex] = ch;
          copyLength = copyIndex + 1;
          ch = "\n\tsrcA = "[copyIndex + 1];
          copyIndex = copyLength;
        } while (ch != '\0');
        outBytePtr = outBytePtr + copyLength;
        switch(program[stateOffset * 2 + loopIndex5 * 2] >> 4 & 0xf) {
        case 0:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_ZERO "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 1:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_ONE "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 2:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_SRC_COLOR "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 3:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_ONE_MINUS_SRC_COLOR "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 4:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_SRC_ALPHA "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 5:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_ONE_MINUS_SRC_ALPHA "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 6:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_DST_ALPHA "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 7:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_ONE_MINUS_DST_ALPHA "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 8:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_CONSTANT_COLOR "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 9:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_ONE_MINUS_CONSTANT_COLOR "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 10:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_CONSTANT_ALPHA "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 0xb:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_ONE_MINUS_CONSTANT_ALPHA "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 0xc:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_DST_COLOR "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 0xd:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_ONE_MINUS_DST_COLOR "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 0xe:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_SRC_ALPHA_SATURATE "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        default:
          goto switchD_97bef988_default;
        }
        outBytePtr = outBytePtr + copyLength;
switchD_97bef988_default:
        ch = '\n';
        copyIndex = 0;
        do {
          outBytePtr[copyIndex] = ch;
          copyLength = copyIndex + 1;
          ch = "\n\tdst = "[copyIndex + 1];
          copyIndex = copyLength;
        } while (ch != '\0');
        outBytePtr = outBytePtr + copyLength;
        switch(program[stateOffset * 2 + loopIndex5 * 2] >> 8 & 0xf) {
        case 0:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_ZERO "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 1:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_ONE "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 2:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_SRC_COLOR "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 3:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_ONE_MINUS_SRC_COLOR "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 4:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_SRC_ALPHA "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 5:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_ONE_MINUS_SRC_ALPHA "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 6:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_DST_ALPHA "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 7:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_ONE_MINUS_DST_ALPHA "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 8:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_CONSTANT_COLOR "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 9:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_ONE_MINUS_CONSTANT_COLOR "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 10:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_CONSTANT_ALPHA "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 0xb:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_ONE_MINUS_CONSTANT_ALPHA "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 0xc:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_DST_COLOR "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 0xd:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_ONE_MINUS_DST_COLOR "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        case 0xe:
          ch = 'P';
          copyIndex = 0;
          do {
            outBytePtr[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PP_BLEND_SRC_ALPHA_SATURATE "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          break;
        default:
          goto switchD_97befd84_default;
        }
        outBytePtr = outBytePtr + copyLength;
switchD_97befd84_default:
        ch = '\n';
        loopIndex4 = 0;
        do {
          outBytePtr[loopIndex4] = ch;
          copyLength = loopIndex4 + 1;
          ch = "\n\tdstA = "[loopIndex4 + 1];
          loopIndex4 = copyLength;
        } while (ch != '\0');
        outCursor = (int *)(outBytePtr + copyLength);
        switch(program[stateOffset * 2 + loopIndex5 * 2] >> 0xc & 0xf) {
        case 0:
          ch = 'P';
          copyIndex3 = 0;
          do {
            *(char *)((int)outCursor + copyIndex3) = ch;
            nextIndex = copyIndex3 + 1;
            ch = "PP_BLEND_ZERO "[copyIndex3 + 1];
            copyIndex3 = nextIndex;
          } while (ch != '\0');
          break;
        case 1:
          ch = 'P';
          copyIndex3 = 0;
          do {
            *(char *)((int)outCursor + copyIndex3) = ch;
            nextIndex = copyIndex3 + 1;
            ch = "PP_BLEND_ONE "[copyIndex3 + 1];
            copyIndex3 = nextIndex;
          } while (ch != '\0');
          break;
        case 2:
          ch = 'P';
          copyIndex3 = 0;
          do {
            *(char *)((int)outCursor + copyIndex3) = ch;
            nextIndex = copyIndex3 + 1;
            ch = "PP_BLEND_SRC_COLOR "[copyIndex3 + 1];
            copyIndex3 = nextIndex;
          } while (ch != '\0');
          break;
        case 3:
          ch = 'P';
          copyIndex3 = 0;
          do {
            *(char *)((int)outCursor + copyIndex3) = ch;
            nextIndex = copyIndex3 + 1;
            ch = "PP_BLEND_ONE_MINUS_SRC_COLOR "[copyIndex3 + 1];
            copyIndex3 = nextIndex;
          } while (ch != '\0');
          break;
        case 4:
          ch = 'P';
          copyIndex3 = 0;
          do {
            *(char *)((int)outCursor + copyIndex3) = ch;
            nextIndex = copyIndex3 + 1;
            ch = "PP_BLEND_SRC_ALPHA "[copyIndex3 + 1];
            copyIndex3 = nextIndex;
          } while (ch != '\0');
          break;
        case 5:
          ch = 'P';
          copyIndex3 = 0;
          do {
            *(char *)((int)outCursor + copyIndex3) = ch;
            nextIndex = copyIndex3 + 1;
            ch = "PP_BLEND_ONE_MINUS_SRC_ALPHA "[copyIndex3 + 1];
            copyIndex3 = nextIndex;
          } while (ch != '\0');
          break;
        case 6:
          ch = 'P';
          copyIndex3 = 0;
          do {
            *(char *)((int)outCursor + copyIndex3) = ch;
            nextIndex = copyIndex3 + 1;
            ch = "PP_BLEND_DST_ALPHA "[copyIndex3 + 1];
            copyIndex3 = nextIndex;
          } while (ch != '\0');
          break;
        case 7:
          ch = 'P';
          copyIndex3 = 0;
          do {
            *(char *)((int)outCursor + copyIndex3) = ch;
            nextIndex = copyIndex3 + 1;
            ch = "PP_BLEND_ONE_MINUS_DST_ALPHA "[copyIndex3 + 1];
            copyIndex3 = nextIndex;
          } while (ch != '\0');
          break;
        case 8:
          ch = 'P';
          copyIndex3 = 0;
          do {
            *(char *)((int)outCursor + copyIndex3) = ch;
            nextIndex = copyIndex3 + 1;
            ch = "PP_BLEND_CONSTANT_COLOR "[copyIndex3 + 1];
            copyIndex3 = nextIndex;
          } while (ch != '\0');
          break;
        case 9:
          ch = 'P';
          copyIndex3 = 0;
          do {
            *(char *)((int)outCursor + copyIndex3) = ch;
            nextIndex = copyIndex3 + 1;
            ch = "PP_BLEND_ONE_MINUS_CONSTANT_COLOR "[copyIndex3 + 1];
            copyIndex3 = nextIndex;
          } while (ch != '\0');
          break;
        case 10:
          ch = 'P';
          copyIndex3 = 0;
          do {
            *(char *)((int)outCursor + copyIndex3) = ch;
            nextIndex = copyIndex3 + 1;
            ch = "PP_BLEND_CONSTANT_ALPHA "[copyIndex3 + 1];
            copyIndex3 = nextIndex;
          } while (ch != '\0');
          break;
        case 0xb:
          ch = 'P';
          copyIndex3 = 0;
          do {
            *(char *)((int)outCursor + copyIndex3) = ch;
            nextIndex = copyIndex3 + 1;
            ch = "PP_BLEND_ONE_MINUS_CONSTANT_ALPHA "[copyIndex3 + 1];
            copyIndex3 = nextIndex;
          } while (ch != '\0');
          break;
        case 0xc:
          ch = 'P';
          copyIndex3 = 0;
          do {
            *(char *)((int)outCursor + copyIndex3) = ch;
            nextIndex = copyIndex3 + 1;
            ch = "PP_BLEND_DST_COLOR "[copyIndex3 + 1];
            copyIndex3 = nextIndex;
          } while (ch != '\0');
          break;
        case 0xd:
          ch = 'P';
          copyIndex3 = 0;
          do {
            *(char *)((int)outCursor + copyIndex3) = ch;
            nextIndex = copyIndex3 + 1;
            ch = "PP_BLEND_ONE_MINUS_DST_COLOR "[copyIndex3 + 1];
            copyIndex3 = nextIndex;
          } while (ch != '\0');
          break;
        case 0xe:
          ch = 'P';
          copyIndex3 = 0;
          do {
            *(char *)((int)outCursor + copyIndex3) = ch;
            nextIndex = copyIndex3 + 1;
            ch = "PP_BLEND_SRC_ALPHA_SATURATE "[copyIndex3 + 1];
            copyIndex3 = nextIndex;
          } while (ch != '\0');
          break;
        default:
          goto switchD_97bee2f0_default;
        }
        break;
      case 4:
        ch = 'D';
        copyIndex3 = 0;
        do {
          *(char *)((int)outCursor + copyIndex3) = ch;
          nextIndex = copyIndex3 + 1;
          ch = "DITHERING ENABLED"[copyIndex3 + 1];
          copyIndex3 = nextIndex;
        } while (ch != '\0');
        break;
      case 5:
        ch = 'L';
        loopIndex4 = 0;
        do {
          *(char *)((int)outCursor + loopIndex4) = ch;
          copyLength = loopIndex4 + 1;
          ch = "LOGIC_OP "[loopIndex4 + 1];
          loopIndex4 = copyLength;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + copyLength);
        switch(program[stateOffset * 2 + loopIndex5 * 2] & 0xf) {
        case 0:
          ch = 'P';
          copyIndex3 = 0;
          do {
            *(char *)((int)outCursor + copyIndex3) = ch;
            nextIndex = copyIndex3 + 1;
            ch = "PP_LOGIC_CLEAR"[copyIndex3 + 1];
            copyIndex3 = nextIndex;
          } while (ch != '\0');
          break;
        case 1:
          ch = 'P';
          copyIndex3 = 0;
          do {
            *(char *)((int)outCursor + copyIndex3) = ch;
            nextIndex = copyIndex3 + 1;
            ch = "PP_LOGIC_SET"[copyIndex3 + 1];
            copyIndex3 = nextIndex;
          } while (ch != '\0');
          break;
        case 2:
          ch = 'P';
          copyIndex3 = 0;
          do {
            *(char *)((int)outCursor + copyIndex3) = ch;
            nextIndex = copyIndex3 + 1;
            ch = "PP_LOGIC_COPY"[copyIndex3 + 1];
            copyIndex3 = nextIndex;
          } while (ch != '\0');
          break;
        case 3:
          ch = 'P';
          copyIndex3 = 0;
          do {
            *(char *)((int)outCursor + copyIndex3) = ch;
            nextIndex = copyIndex3 + 1;
            ch = "PP_LOGIC_COPY_INVERTED"[copyIndex3 + 1];
            copyIndex3 = nextIndex;
          } while (ch != '\0');
          break;
        case 4:
          ch = 'P';
          copyIndex3 = 0;
          do {
            *(char *)((int)outCursor + copyIndex3) = ch;
            nextIndex = copyIndex3 + 1;
            ch = "PP_LOGIC_NOOP"[copyIndex3 + 1];
            copyIndex3 = nextIndex;
          } while (ch != '\0');
          break;
        case 5:
          ch = 'P';
          copyIndex3 = 0;
          do {
            *(char *)((int)outCursor + copyIndex3) = ch;
            nextIndex = copyIndex3 + 1;
            ch = "PP_LOGIC_INVERT"[copyIndex3 + 1];
            copyIndex3 = nextIndex;
          } while (ch != '\0');
          break;
        case 6:
          ch = 'P';
          copyIndex3 = 0;
          do {
            *(char *)((int)outCursor + copyIndex3) = ch;
            nextIndex = copyIndex3 + 1;
            ch = "PP_LOGIC_AND"[copyIndex3 + 1];
            copyIndex3 = nextIndex;
          } while (ch != '\0');
          break;
        case 7:
          ch = 'P';
          copyIndex3 = 0;
          do {
            *(char *)((int)outCursor + copyIndex3) = ch;
            nextIndex = copyIndex3 + 1;
            ch = "PP_LOGIC_NAND"[copyIndex3 + 1];
            copyIndex3 = nextIndex;
          } while (ch != '\0');
          break;
        case 8:
          ch = 'P';
          copyIndex3 = 0;
          do {
            *(char *)((int)outCursor + copyIndex3) = ch;
            nextIndex = copyIndex3 + 1;
            ch = "PP_LOGIC_OR"[copyIndex3 + 1];
            copyIndex3 = nextIndex;
          } while (ch != '\0');
          break;
        case 9:
          ch = 'P';
          copyIndex3 = 0;
          do {
            *(char *)((int)outCursor + copyIndex3) = ch;
            nextIndex = copyIndex3 + 1;
            ch = "PP_LOGIC_NOR"[copyIndex3 + 1];
            copyIndex3 = nextIndex;
          } while (ch != '\0');
          break;
        case 10:
          ch = 'P';
          copyIndex3 = 0;
          do {
            *(char *)((int)outCursor + copyIndex3) = ch;
            nextIndex = copyIndex3 + 1;
            ch = "PP_LOGIC_XOR"[copyIndex3 + 1];
            copyIndex3 = nextIndex;
          } while (ch != '\0');
          break;
        case 0xb:
          ch = 'P';
          copyIndex3 = 0;
          do {
            *(char *)((int)outCursor + copyIndex3) = ch;
            nextIndex = copyIndex3 + 1;
            ch = "PP_LOGIC_EQUIV"[copyIndex3 + 1];
            copyIndex3 = nextIndex;
          } while (ch != '\0');
          break;
        case 0xc:
          ch = 'P';
          copyIndex3 = 0;
          do {
            *(char *)((int)outCursor + copyIndex3) = ch;
            nextIndex = copyIndex3 + 1;
            ch = "PP_LOGIC_AND_REVERSE"[copyIndex3 + 1];
            copyIndex3 = nextIndex;
          } while (ch != '\0');
          break;
        case 0xd:
          ch = 'P';
          copyIndex3 = 0;
          do {
            *(char *)((int)outCursor + copyIndex3) = ch;
            nextIndex = copyIndex3 + 1;
            ch = "PP_LOGIC_AND_INVERTED"[copyIndex3 + 1];
            copyIndex3 = nextIndex;
          } while (ch != '\0');
          break;
        case 0xe:
          ch = 'P';
          copyIndex3 = 0;
          do {
            *(char *)((int)outCursor + copyIndex3) = ch;
            nextIndex = copyIndex3 + 1;
            ch = "PP_LOGIC_OR_REVERSE"[copyIndex3 + 1];
            copyIndex3 = nextIndex;
          } while (ch != '\0');
          break;
        case 0xf:
          ch = 'P';
          copyIndex3 = 0;
          do {
            *(char *)((int)outCursor + copyIndex3) = ch;
            nextIndex = copyIndex3 + 1;
            ch = "PP_LOGIC_OR_INVERTED"[copyIndex3 + 1];
            copyIndex3 = nextIndex;
          } while (ch != '\0');
          break;
        default:
          goto switchD_97bee2f0_default;
        }
        break;
      case 6:
        ch = 'B';
        copyIndex = 0;
        do {
          *(char *)((int)outCursor + copyIndex) = ch;
          copyLength = copyIndex + 1;
          ch = "BUFFER_MASK "[copyIndex + 1];
          copyIndex = copyLength;
        } while (ch != '\0');
        outCursor = (int *)((int)outCursor + copyLength);
        if ((program[stateOffset * 2 + loopIndex5 * 2] & 0x20000) == 0) {
          ch = 'R';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            copyLength = copyIndex + 1;
            ch = "RED MASKED "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + copyLength);
        }
        if ((program[stateOffset * 2 + loopIndex5 * 2] & 0x40000) == 0) {
          ch = 'G';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            copyLength = copyIndex + 1;
            ch = "GREEN MASKED "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + copyLength);
        }
        if ((program[stateOffset * 2 + loopIndex5 * 2] & 0x80000) == 0) {
          ch = 'B';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            copyLength = copyIndex + 1;
            ch = "BLUE MASKED "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + copyLength);
        }
        if ((program[stateOffset * 2 + loopIndex5 * 2] & 0x100000) == 0) {
          ch = 'A';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            copyLength = copyIndex + 1;
            ch = "ALPHA MASKED "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + copyLength);
        }
        if ((program[stateOffset * 2 + loopIndex5 * 2] & 0x10000) == 0) {
          ch = 'D';
          copyIndex = 0;
          do {
            *(char *)((int)outCursor + copyIndex) = ch;
            copyLength = copyIndex + 1;
            ch = "DEPTH MASKED "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          outCursor = (int *)((int)outCursor + copyLength);
        }
        if (*(char *)((int)program + loopIndex5 * 8 + stateOffset * 8 + 2) != -1) {
          _sprintf(local_1b0,"STENCIL MASK = %0x",program[stateOffset * 2 + loopIndex5 * 2] >> 8 & 0xff);
          nextIndex = 0;
          ch = local_1b0[0];
          while (ch != '\0') {
            *(char *)((int)outCursor + nextIndex) = ch;
            nextIndex = nextIndex + 1;
            ch = local_1b0[nextIndex];
          }
          break;
        }
      default:
        goto switchD_97bee2f0_default;
      }
      outCursor = (int *)((int)outCursor + nextIndex);
switchD_97bee2f0_default:
      copyIndex6 = 0;
      ch = dataBase[0x3bbc];
      while (ch != '\0') {
        *(char *)((int)outCursor + copyIndex6) = ch;
        copyIndex6 = copyIndex6 + 1;
        ch = (dataBase + 0x3bbc)[copyIndex6];
      }
      outCursor = (int *)((int)outCursor + copyIndex6);
      uVar26 = ((int (*)())_adjustAllocation_97be9cb4)(&outBufCapacity,&outBuf,&outCursor);
      if ((int)((ulonglong)uVar26 >> 0x20) == 0) goto joined_r0x97beb668;
      loopIndex = loopIndex + 1;
      loopIndex5 = loopIndex5 + 1;
    } while (loopIndex < (int)stateCount);
  }
  piVar15 = (int *)((int)outCursor + 1);
  *(undefined1 *)outCursor = 0;
  outCursor = piVar15;
  if (!bVar3) {
    _free(paramNumbers);
    _free(paramArrayPos);
  }
  if (!(bool)((byte)((uint)cr0Image >> 0x1d) & 1)) {
    _free(tempNumbers);
  }
  if (!(bool)((byte)((uint)cr0Image2 >> 0x1d) & 1)) {
    _free(tempArrayPos);
  }
  if (0 < (int)outCursor - (int)outBuf) {
    allocation = (void *)_realloc(outBuf,(int)outCursor - (int)outBuf);
    return allocation;
  }
  _free(outBuf);
  return (void *)0x0;
}

/* _handleDigit_97bf0d2c @ 0x97bf0d2c (112 bytes) */
int _handleDigit_97bf0d2c(writeCursorPtr, value)
  int *writeCursorPtr;
  int value;
{
  int leadingValue;
  
  leadingValue = value / 10;
  if (leadingValue != 0) {
    ((int (*)())_handleDigit_97bf0d2c)(writeCursorPtr,leadingValue);
  }
  *(char *)*writeCursorPtr = (char)value + (char)leadingValue * -10 + '0';
  *writeCursorPtr = *writeCursorPtr + 1;
  return;
}

/* _PPStreamChunkCreateWithType @ 0x97bf0d9c (116 bytes) */
int _PPStreamChunkCreateWithType(chunkType, chunkExtra)
  int chunkType;
  undefined4 chunkExtra;
{
  int chunkAllocationSize;
  undefined1 *allocation;
  
  chunkAllocationSize = _GetChunkAllocationSize(chunkType,chunkExtra);
  allocation = (undefined1 *)_calloc(chunkAllocationSize + 0xc,1);
  _memset(allocation,0,chunkAllocationSize + 0xc);
  *allocation = (char)chunkType;
  if (chunkType == 8) {
    *(undefined4 *)(allocation + 0x40) = chunkExtra;
  }
  else if (chunkType == 0xb) {
    *(undefined4 *)(allocation + 0x10) = chunkExtra;
  }
  return allocation;
}

/* _PPStreamChunkCompare @ 0x97bf0e10 (212 bytes) */
int _PPStreamChunkCompare(chunk, otherChunk)
  char *chunk;
  char *otherChunk;
{
  undefined4 result;
  int compareResult;
  undefined4 payloadSize;
  
  result = 1;
  if (*otherChunk == *chunk) {
    switch(*otherChunk) {
    case '\0':
    case '\x03':
    case '\n':
      payloadSize = 0x10;
      break;
    case '\x01':
      payloadSize = 4;
      break;
    case '\x02':
    case '\x04':
    case '\x05':
    case '\x06':
    case '\a':
    case '\t':
      payloadSize = 8;
      break;
    case '\b':
      payloadSize = 0x38;
      result = *(undefined4 *)(chunk + 0x40);
      *(undefined4 *)(otherChunk + 0x3c) = *(undefined4 *)(chunk + 0x3c);
      *(undefined4 *)(otherChunk + 0x40) = result;
      break;
    default:
      return 1;
    }
    compareResult = _memcmp(chunk + 0xc,otherChunk + 0xc,payloadSize);
    result = 1;
    if (compareResult == 0) {
      result = 0;
    }
  }
  return result;
}

/* _PPStreamChunkListInsertChunkBeforeChunk @ 0x97bf0f14 (84 bytes) */
int _PPStreamChunkListInsertChunkBeforeChunk(chunkList, newChunk, beforeChunk)
  int *chunkList;
  int newChunk;
  int beforeChunk;
{
  undefined4 previousChunk;
  
  if (beforeChunk == 0) {
    _PPStreamChunkListAddChunk(chunkList,newChunk);
    return;
  }
  previousChunk = *(undefined4 *)(beforeChunk + 4);
  *(int *)(newChunk + 8) = beforeChunk;
  *(undefined4 *)(newChunk + 4) = previousChunk;
  if (*(int *)(beforeChunk + 4) != 0) {
    *(int *)(*(int *)(beforeChunk + 4) + 8) = newChunk;
  }
  *(int *)(beforeChunk + 4) = newChunk;
  if (*chunkList == beforeChunk) {
    *chunkList = newChunk;
  }
  chunkList[2] = chunkList[2] + 1;
  return;
}

/* _PPStreamChunkListInsertChunkAfterChunk @ 0x97bf0f68 (116 bytes) */
int _PPStreamChunkListInsertChunkAfterChunk(chunkList, newChunk, afterChunk)
  int *chunkList;
  int newChunk;
  int afterChunk;
{
  undefined4 nextChunk;
  
  if (afterChunk == 0) {
    *(undefined4 *)(newChunk + 4) = 0;
    if (*chunkList == 0) {
      *(undefined4 *)(newChunk + 8) = 0;
    }
    else {
      *(int *)(newChunk + 8) = *chunkList;
      *(int *)(*chunkList + 4) = newChunk;
    }
    *chunkList = newChunk;
  }
  else {
    nextChunk = *(undefined4 *)(afterChunk + 8);
    *(int *)(newChunk + 4) = afterChunk;
    *(undefined4 *)(newChunk + 8) = nextChunk;
    if (*(int *)(afterChunk + 8) != 0) {
      *(int *)(*(int *)(afterChunk + 8) + 4) = newChunk;
    }
    *(int *)(afterChunk + 8) = newChunk;
    if (chunkList[1] == afterChunk) {
      chunkList[1] = newChunk;
    }
  }
  chunkList[2] = chunkList[2] + 1;
  return;
}

/* _PPStreamChunkListRemoveChunkNoFree @ 0x97bf0fdc (88 bytes) */
int _PPStreamChunkListRemoveChunkNoFree(chunkList, chunk)
  undefined4 *chunkList;
  int chunk;
{
  int previousChunk;
  
  previousChunk = *(int *)(chunk + 4);
  if (previousChunk == 0) {
    *chunkList = *(undefined4 *)(chunk + 8);
    previousChunk = *(int *)(chunk + 4);
  }
  else {
    *(undefined4 *)(previousChunk + 8) = *(undefined4 *)(chunk + 8);
  }
  if (*(int *)(chunk + 8) == 0) {
    chunkList[1] = previousChunk;
  }
  else {
    *(int *)(*(int *)(chunk + 8) + 4) = previousChunk;
  }
  *(undefined4 *)(chunk + 8) = 0;
  *(undefined4 *)(chunk + 4) = 0;
  chunkList[2] = chunkList[2] + -1;
  return;
}

/* _PPStreamChunkListCompare @ 0x97bf1034 (132 bytes) */
int _PPStreamChunkListCompare(chunkList, otherList)
  int *chunkList;
  int *otherList;
{
  undefined4 result;
  int ppStreamChunkCompareResult;
  int chunk;
  int otherChunk;
  
  chunk = *chunkList;
  result = 1;
  otherChunk = *otherList;
  if (chunkList[2] == otherList[2]) {
    for (; (chunk != 0 && (otherChunk != 0)); otherChunk = *(int *)(otherChunk + 8)) {
      ppStreamChunkCompareResult = ((int (*)())_PPStreamChunkCompare)(chunk,otherChunk);
      if (ppStreamChunkCompareResult != 0) {
        return 1;
      }
      chunk = *(int *)(chunk + 8);
    }
    result = 0;
  }
  return result;
}

/* _PPStreamDuplicate @ 0x97bf10b8 (636 bytes) */
int _PPStreamDuplicate(stream)
  undefined4 *stream;
{
  int *tempList;
  undefined4 *newStream;
  undefined4 chunk;
  int sourceChunk;
  
  newStream = (undefined4 *)_PPStreamCreate();
  tempList = (int *)stream[1];
  *newStream = *stream;
  for (sourceChunk = *tempList; sourceChunk != 0; sourceChunk = *(int *)(sourceChunk + 8)) {
    chunk = _PPStreamChunkCreateFromChunk(sourceChunk);
    _PPStreamChunkListAddChunk(newStream[1],chunk);
  }
  for (sourceChunk = *(int *)stream[2]; sourceChunk != 0; sourceChunk = *(int *)(sourceChunk + 8)) {
    chunk = _PPStreamChunkCreateFromChunk(sourceChunk);
    _PPStreamChunkListAddChunk(newStream[2],chunk);
  }
  for (sourceChunk = *(int *)stream[3]; sourceChunk != 0; sourceChunk = *(int *)(sourceChunk + 8)) {
    chunk = _PPStreamChunkCreateFromChunk(sourceChunk);
    _PPStreamChunkListAddChunk(newStream[3],chunk);
  }
  for (sourceChunk = *(int *)stream[4]; sourceChunk != 0; sourceChunk = *(int *)(sourceChunk + 8)) {
    chunk = _PPStreamChunkCreateFromChunk(sourceChunk);
    _PPStreamChunkListAddChunk(newStream[4],chunk);
  }
  for (sourceChunk = *(int *)stream[5]; sourceChunk != 0; sourceChunk = *(int *)(sourceChunk + 8)) {
    chunk = _PPStreamChunkCreateFromChunk(sourceChunk);
    _PPStreamChunkListAddChunk(newStream[5],chunk);
  }
  for (sourceChunk = *(int *)stream[6]; sourceChunk != 0; sourceChunk = *(int *)(sourceChunk + 8)) {
    chunk = _PPStreamChunkCreateFromChunk(sourceChunk);
    _PPStreamChunkListAddChunk(newStream[6],chunk);
  }
  for (sourceChunk = *(int *)stream[7]; sourceChunk != 0; sourceChunk = *(int *)(sourceChunk + 8)) {
    chunk = _PPStreamChunkCreateFromChunk(sourceChunk);
    _PPStreamChunkListAddChunk(newStream[7],chunk);
  }
  for (sourceChunk = *(int *)stream[8]; sourceChunk != 0; sourceChunk = *(int *)(sourceChunk + 8)) {
    chunk = _PPStreamChunkCreateFromChunk(sourceChunk);
    _PPStreamChunkListAddChunk(newStream[8],chunk);
  }
  for (sourceChunk = *(int *)stream[9]; sourceChunk != 0; sourceChunk = *(int *)(sourceChunk + 8)) {
    chunk = _PPStreamChunkCreateFromChunk(sourceChunk);
    _PPStreamChunkListAddChunk(newStream[9],chunk);
  }
  for (sourceChunk = *(int *)stream[0xb]; sourceChunk != 0; sourceChunk = *(int *)(sourceChunk + 8)) {
    chunk = _PPStreamChunkCreateFromChunk(sourceChunk);
    _PPStreamChunkListAddChunk(newStream[0xb],chunk);
  }
  for (sourceChunk = *(int *)stream[10]; sourceChunk != 0; sourceChunk = *(int *)(sourceChunk + 8)) {
    chunk = _PPStreamChunkCreateFromChunk(sourceChunk);
    _PPStreamChunkListAddChunk(newStream[10],chunk);
  }
  for (sourceChunk = *(int *)stream[0xc]; sourceChunk != 0; sourceChunk = *(int *)(sourceChunk + 8)) {
    chunk = _PPStreamChunkCreateFromChunk(sourceChunk);
    _PPStreamChunkListAddChunk(newStream[0xc],chunk);
  }
  return newStream;
}

/* _PPStreamAddTempUsageArray @ 0x97bf1334 (92 bytes) */
int _PPStreamAddTempUsageArray(stream, arrayEntry)
  int stream;
  undefined4 *arrayEntry;
{
  undefined1 *allocation;
  undefined4 tempArrayList;
  undefined4 entryWord0;
  undefined4 entryWord1;
  
  allocation = (undefined1 *)_calloc(0x14,1);
  entryWord1 = arrayEntry[1];
  tempArrayList = *(undefined4 *)(stream + 8);
  entryWord0 = *arrayEntry;
  *allocation = 6;
  *(undefined4 *)(allocation + 0xc) = entryWord0;
  *(undefined4 *)(allocation + 0x10) = entryWord1;
  return _PPStreamChunkListAddChunk(tempArrayList,allocation);
}

/* _PPStreamAddAddressUsage @ 0x97bf1390 (84 bytes) */
int _PPStreamAddAddressUsage(stream, addressEntry)
  int stream;
  undefined4 *addressEntry;
{
  undefined1 *allocation;
  undefined4 addressList;
  undefined4 addressIndex;
  
  allocation = (undefined1 *)_calloc(0x10,1);
  addressIndex = *addressEntry;
  addressList = *(undefined4 *)(stream + 0xc);
  *allocation = 1;
  *(undefined4 *)(allocation + 0xc) = addressIndex;
  return _PPStreamChunkListAddChunk(addressList,allocation);
}

/* _PPStreamAddParamBindingArray @ 0x97bf13e4 (92 bytes) */
int _PPStreamAddParamBindingArray(stream, arrayEntry)
  int stream;
  undefined4 *arrayEntry;
{
  undefined1 *allocation;
  undefined4 paramArrayList;
  undefined4 entryWord0;
  undefined4 entryWord1;
  
  allocation = (undefined1 *)_calloc(0x14,1);
  entryWord1 = arrayEntry[1];
  paramArrayList = *(undefined4 *)(stream + 0x14);
  entryWord0 = *arrayEntry;
  *allocation = 5;
  *(undefined4 *)(allocation + 0xc) = entryWord0;
  *(undefined4 *)(allocation + 0x10) = entryWord1;
  return _PPStreamChunkListAddChunk(paramArrayList,allocation);
}

/* _PPStreamInsertOperationBeforeChunk @ 0x97bf1440 (288 bytes) */
int _PPStreamInsertOperationBeforeChunk(stream, opRecord, operationText, keepIndex, beforeChunk)
  int stream;
  int opRecord;
  int operationText;
  int keepIndex;
  int beforeChunk;
{
  uint beforeOpWord0;
  int maxIndex;
  uint newOpWord0;
  uint newOpWord0Final;
  int chunkPayloadSize;
  undefined1 *allocation;
  int operationTextLength;
  
  operationTextLength = *(int *)(opRecord + 0x34);
  chunkPayloadSize = 0x38;
  if (operationTextLength != 0) {
    chunkPayloadSize = operationTextLength + 0x39;
  }
  allocation = (undefined1 *)_calloc(chunkPayloadSize + 0xc,1);
  *allocation = 8;
  _memcpy(allocation + 0xc,opRecord,0x38);
  if ((operationTextLength != 0) && (operationText != 0)) {
    _memmove(allocation + 0x44,operationText,operationTextLength);
    allocation[operationTextLength + 0x44] = 0;
  }
  if (keepIndex == 0) {
    maxIndex = _PPStreamChunkListGetMaxIndex(*(undefined4 *)(stream + 0x20));
    newOpWord0 = maxIndex + 1U & 0x3ffff | *(uint *)(allocation + 0xc) & 0xfffc0000;
  }
  else {
    newOpWord0 = *(uint *)(allocation + 0xc) & 0xfffc0000;
  }
  *(uint *)(allocation + 0xc) = newOpWord0;
  if (beforeChunk != 0) {
    beforeOpWord0 = *(uint *)(beforeChunk + 0xc);
    newOpWord0Final = *(uint *)(allocation + 0xc);
    *(uint *)(beforeChunk + 0xc) =
         newOpWord0Final & 0x3ffff | (newOpWord0Final & 0xe3ffffff) >> 3 & 0x1c000000 | beforeOpWord0 & 0xe3fc0000;
    *(uint *)(allocation + 0xc) = beforeOpWord0 & 0x3ffff | (beforeOpWord0 >> 0x1a & 7) << 0x1a | newOpWord0Final & 0xe3fc0000;
  }
  ((int (*)())_PPStreamChunkListInsertChunkBeforeChunk)(*(undefined4 *)(stream + 0x20),allocation,beforeChunk);
  return allocation;
}

/* _PPStreamInsertOperationAfterChunk @ 0x97bf1560 (236 bytes) */
int _PPStreamInsertOperationAfterChunk(stream, opRecord, operationText, keepIndex, afterChunk)
  int stream;
  int opRecord;
  int operationText;
  int keepIndex;
  undefined4 afterChunk;
{
  int maxIndex;
  uint newOpWord0;
  int chunkPayloadSize;
  undefined1 *allocation;
  int operationTextLength;
  
  operationTextLength = *(int *)(opRecord + 0x34);
  chunkPayloadSize = 0x38;
  if (operationTextLength != 0) {
    chunkPayloadSize = operationTextLength + 0x39;
  }
  allocation = (undefined1 *)_calloc(chunkPayloadSize + 0xc,1);
  *allocation = 8;
  _memcpy(allocation + 0xc,opRecord,0x38);
  if ((operationTextLength != 0) && (operationText != 0)) {
    _memmove(allocation + 0x44,operationText,operationTextLength);
    allocation[operationTextLength + 0x44] = 0;
  }
  if (keepIndex == 0) {
    maxIndex = _PPStreamChunkListGetMaxIndex(*(undefined4 *)(stream + 0x20));
    newOpWord0 = maxIndex + 1U & 0x3ffff | *(uint *)(allocation + 0xc) & 0xfffc0000;
  }
  else {
    newOpWord0 = *(uint *)(allocation + 0xc) & 0xfffc0000;
  }
  *(uint *)(allocation + 0xc) = newOpWord0;
  ((int (*)())_PPStreamChunkListInsertChunkAfterChunk)(*(undefined4 *)(stream + 0x20),allocation,afterChunk);
  return allocation;
}

/* _PPStreamAddLabel @ 0x97bf164c (128 bytes) */
int _PPStreamAddLabel(stream, labelText, labelLength)
  int stream;
  undefined4 labelText;
  int labelLength;
{
  undefined4 labelList;
  undefined1 *allocation;
  undefined4 operationList;
  int maxIndex;
  
  allocation = (undefined1 *)_calloc(labelLength + 0x15,1);
  operationList = *(undefined4 *)(stream + 0x20);
  *allocation = 0xb;
  *(int *)(allocation + 0x10) = labelLength;
  maxIndex = _PPStreamChunkListGetMaxIndex(operationList);
  *(int *)(allocation + 0xc) = maxIndex + 1;
  _memmove(allocation + 0x14,labelText,labelLength);
  labelList = *(undefined4 *)(stream + 0x24);
  allocation[labelLength + 0x14] = 0;
  return _PPStreamChunkListAddChunk(labelList,allocation);
}

/* _PPStreamRemoveLabelsAtOperationIndex @ 0x97bf16cc (96 bytes) */
int _PPStreamRemoveLabelsAtOperationIndex(stream, operationIndex)
  int stream;
  int operationIndex;
{
  int label;
  int nextLabel;
  
  nextLabel = **(int **)(stream + 0x24);
  while (label = nextLabel, label != 0) {
    nextLabel = *(int *)(label + 8);
    if (*(int *)(label + 0xc) == operationIndex) {
      _PPStreamChunkListRemoveChunk(*(undefined4 *)(stream + 0x24),label);
    }
  }
  return;
}

/* _PPStreamAddRasterOp @ 0x97bf172c (92 bytes) */
int _PPStreamAddRasterOp(stream, rasterOpEntry)
  int stream;
  undefined4 *rasterOpEntry;
{
  undefined1 *allocation;
  undefined4 rasterOpList;
  undefined4 entryWord0;
  undefined4 entryWord1;
  
  allocation = (undefined1 *)_calloc(0x14,1);
  entryWord1 = rasterOpEntry[1];
  rasterOpList = *(undefined4 *)(stream + 0x28);
  entryWord0 = *rasterOpEntry;
  *allocation = 9;
  *(undefined4 *)(allocation + 0xc) = entryWord0;
  *(undefined4 *)(allocation + 0x10) = entryWord1;
  return _PPStreamChunkListAddChunk(rasterOpList,allocation);
}

/* _PPStreamAttachStream @ 0x97bf1788 (1212 bytes) */
int _PPStreamAttachStream(stream, packedProgram)
  undefined4 *stream;
  undefined4 *packedProgram;
{
  undefined4 *extraTableEntry;
  undefined4 *rasterOpEntry;
  undefined4 *optionEntry;
  undefined4 *tempArrayEntry;
  undefined4 *paramArrayEntry;
  undefined4 *outputEntry;
  undefined4 *paramEntry;
  undefined4 *attributeEntry;
  uint operandWord0;
  uint operationWord3;
  uint *operationWord2Ptr;
  uint operationWord1;
  undefined4 entryWord1;
  uint operandWord1;
  undefined1 *allocation;
  undefined1 *operandCursor;
  uint loopIndex;
  uint *operationCursor;
  undefined4 *tempEntry;
  uint sourceOperandCount;
  
  loopIndex = 0;
  *stream = *packedProgram;
  if (packedProgram[6] != 0) {
    do {
      allocation = (undefined1 *)_calloc(0x10,1);
      *(uint *)(allocation + 0xc) = loopIndex;
      *allocation = 1;
      loopIndex = loopIndex + 1;
      _PPStreamChunkListAddChunk(stream[3],allocation);
    } while (loopIndex < (uint)packedProgram[6]);
  }
  loopIndex = 0;
  tempEntry = packedProgram + packedProgram[5] * 2;
  if (packedProgram[4] != 0) {
    do {
      allocation = (undefined1 *)_calloc(0x1c,1);
      loopIndex = loopIndex + 1;
      *allocation = 0;
      entryWord1 = tempEntry[1];
      *(undefined4 *)(allocation + 0xc) = *tempEntry;
      *(undefined4 *)(allocation + 0x10) = entryWord1;
      _PPStreamChunkListAddChunk(stream[1],allocation);
      tempEntry = tempEntry + 2;
    } while (loopIndex < (uint)packedProgram[4]);
  }
  loopIndex = 0;
  attributeEntry = packedProgram + packedProgram[9] * 2;
  if (packedProgram[8] != 0) {
    do {
      allocation = (undefined1 *)_calloc(0x14,1);
      loopIndex = loopIndex + 1;
      *allocation = 2;
      entryWord1 = attributeEntry[1];
      *(undefined4 *)(allocation + 0xc) = *attributeEntry;
      *(undefined4 *)(allocation + 0x10) = entryWord1;
      _PPStreamChunkListAddChunk(stream[6],allocation);
      attributeEntry = attributeEntry + 2;
    } while (loopIndex < (uint)packedProgram[8]);
  }
  loopIndex = 0;
  paramEntry = packedProgram + packedProgram[0xb] * 2;
  if (packedProgram[10] != 0) {
    do {
      allocation = (undefined1 *)_calloc(0x1c,1);
      loopIndex = loopIndex + 1;
      *allocation = 3;
      entryWord1 = paramEntry[1];
      *(undefined4 *)(allocation + 0xc) = *paramEntry;
      *(undefined4 *)(allocation + 0x10) = entryWord1;
      _PPStreamChunkListAddChunk(stream[4],allocation);
      paramEntry = paramEntry + 2;
    } while (loopIndex < (uint)packedProgram[10]);
  }
  loopIndex = 0;
  outputEntry = packedProgram + packedProgram[0xd] * 2;
  if (packedProgram[0xc] != 0) {
    do {
      allocation = (undefined1 *)_calloc(0x14,1);
      loopIndex = loopIndex + 1;
      *allocation = 4;
      entryWord1 = outputEntry[1];
      *(undefined4 *)(allocation + 0xc) = *outputEntry;
      *(undefined4 *)(allocation + 0x10) = entryWord1;
      _PPStreamChunkListAddChunk(stream[7],allocation);
      outputEntry = outputEntry + 2;
    } while (loopIndex < (uint)packedProgram[0xc]);
  }
  loopIndex = 0;
  paramArrayEntry = packedProgram + packedProgram[0xf] * 2;
  if (packedProgram[0xe] != 0) {
    do {
      allocation = (undefined1 *)_calloc(0x14,1);
      loopIndex = loopIndex + 1;
      *allocation = 5;
      entryWord1 = paramArrayEntry[1];
      *(undefined4 *)(allocation + 0xc) = *paramArrayEntry;
      *(undefined4 *)(allocation + 0x10) = entryWord1;
      _PPStreamChunkListAddChunk(stream[5],allocation);
      paramArrayEntry = paramArrayEntry + 2;
    } while (loopIndex < (uint)packedProgram[0xe]);
  }
  loopIndex = 0;
  tempArrayEntry = packedProgram + packedProgram[0x11] * 2;
  if (packedProgram[0x10] != 0) {
    do {
      allocation = (undefined1 *)_calloc(0x14,1);
      loopIndex = loopIndex + 1;
      *allocation = 6;
      entryWord1 = tempArrayEntry[1];
      *(undefined4 *)(allocation + 0xc) = *tempArrayEntry;
      *(undefined4 *)(allocation + 0x10) = entryWord1;
      _PPStreamChunkListAddChunk(stream[2],allocation);
      tempArrayEntry = tempArrayEntry + 2;
    } while (loopIndex < (uint)packedProgram[0x10]);
  }
  loopIndex = 0;
  optionEntry = packedProgram + packedProgram[0x13] * 2;
  if (packedProgram[0x12] != 0) {
    do {
      allocation = (undefined1 *)_calloc(0x14,1);
      loopIndex = loopIndex + 1;
      *allocation = 7;
      entryWord1 = optionEntry[1];
      *(undefined4 *)(allocation + 0xc) = *optionEntry;
      *(undefined4 *)(allocation + 0x10) = entryWord1;
      _PPStreamChunkListAddChunk(stream[0xc],allocation);
      optionEntry = optionEntry + 2;
    } while (loopIndex < (uint)packedProgram[0x12]);
  }
  loopIndex = 0;
  operationCursor = packedProgram + packedProgram[0x15] * 2;
  if (packedProgram[0x14] != 0) {
    do {
      allocation = (undefined1 *)_calloc(0x44,1);
      *allocation = 8;
      *(undefined4 *)(allocation + 0x40) = 0;
      operationWord1 = operationCursor[1];
      sourceOperandCount = *operationCursor >> 0x1d;
      *(uint *)(allocation + 0xc) = *operationCursor;
      *(uint *)(allocation + 0x10) = operationWord1;
      operationWord2Ptr = operationCursor + 2;
      operationWord3 = operationCursor[3];
      operationCursor = operationCursor + 4;
      *(uint *)(allocation + 0x14) = *operationWord2Ptr;
      *(uint *)(allocation + 0x18) = operationWord3;
      if (sourceOperandCount != 0) {
        operandCursor = allocation + 0x10;
        do {
          operandWord0 = *operationCursor;
          operandWord1 = operationCursor[1];
          operationCursor = operationCursor + 2;
          *(uint *)(operandCursor + 0xc) = operandWord0;
          *(uint *)(operandCursor + 0x10) = operandWord1;
          operandCursor = operandCursor + 8;
          sourceOperandCount = sourceOperandCount - 1;
        } while (sourceOperandCount != 0);
      }
      loopIndex = loopIndex + 1;
      _PPStreamChunkListAddChunk(stream[8],allocation);
    } while (loopIndex < (uint)packedProgram[0x14]);
  }
  loopIndex = 0;
  rasterOpEntry = packedProgram + packedProgram[0x19] * 2;
  if (packedProgram[0x18] != 0) {
    do {
      allocation = (undefined1 *)_calloc(0x14,1);
      loopIndex = loopIndex + 1;
      *allocation = 9;
      entryWord1 = rasterOpEntry[1];
      *(undefined4 *)(allocation + 0xc) = *rasterOpEntry;
      *(undefined4 *)(allocation + 0x10) = entryWord1;
      _PPStreamChunkListAddChunk(stream[10],allocation);
      rasterOpEntry = rasterOpEntry + 2;
    } while (loopIndex < (uint)packedProgram[0x18]);
  }
  loopIndex = 0;
  extraTableEntry = packedProgram + packedProgram[0x1b] * 2;
  if (packedProgram[0x1a] != 0) {
    do {
      allocation = (undefined1 *)_calloc(0x1c,1);
      loopIndex = loopIndex + 1;
      *allocation = 10;
      *(undefined4 *)(allocation + 0xc) = *extraTableEntry;
      *(undefined4 *)(allocation + 0x10) = extraTableEntry[1];
      *(undefined4 *)(allocation + 0x14) = extraTableEntry[2];
      *(undefined4 *)(allocation + 0x18) = extraTableEntry[3];
      extraTableEntry = extraTableEntry + 4;
      _PPStreamChunkListAddChunk(stream[0xb],allocation);
    } while (loopIndex < (uint)packedProgram[0x1a]);
  }
  return 0;
}

/* _PPStreamCompare @ 0x97bf1c44 (328 bytes) */
int _PPStreamCompare(stream, otherStream)
  int *stream;
  int *otherStream;
{
  int listCompare;
  bool streamsDiffer;
  
  streamsDiffer = true;
  if (*stream == *otherStream) {
    listCompare = ((int (*)())_PPStreamChunkListCompare)(stream[1],otherStream[1]);
    streamsDiffer = true;
    if (listCompare == 0) {
      listCompare = ((int (*)())_PPStreamChunkListCompare)(stream[3],otherStream[3]);
      streamsDiffer = true;
      if (listCompare == 0) {
        listCompare = ((int (*)())_PPStreamChunkListCompare)(stream[4],otherStream[4]);
        streamsDiffer = true;
        if (listCompare == 0) {
          listCompare = ((int (*)())_PPStreamChunkListCompare)(stream[5],otherStream[5]);
          streamsDiffer = true;
          if (listCompare == 0) {
            listCompare = ((int (*)())_PPStreamChunkListCompare)(stream[2],otherStream[2]);
            streamsDiffer = true;
            if (listCompare == 0) {
              listCompare = ((int (*)())_PPStreamChunkListCompare)(stream[6],otherStream[6]);
              streamsDiffer = true;
              if (listCompare == 0) {
                listCompare = ((int (*)())_PPStreamChunkListCompare)(stream[7],otherStream[7]);
                streamsDiffer = true;
                if (listCompare == 0) {
                  listCompare = ((int (*)())_PPStreamChunkListCompare)(stream[8],otherStream[8]);
                  streamsDiffer = true;
                  if (listCompare == 0) {
                    listCompare = ((int (*)())_PPStreamChunkListCompare)(stream[0xb],otherStream[0xb]);
                    streamsDiffer = true;
                    if (listCompare == 0) {
                      listCompare = ((int (*)())_PPStreamChunkListCompare)(stream[10],otherStream[10]);
                      streamsDiffer = true;
                      if (listCompare == 0) {
                        listCompare = ((int (*)())_PPStreamChunkListCompare)(stream[0xc],otherStream[0xc]);
                        streamsDiffer = listCompare != 0;
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
  return streamsDiffer;
}

/* _PPStreamRenumberOperandIndices @ 0x97bf1d8c (332 bytes) */
int _PPStreamRenumberOperandIndices(stream, declChunk, newIndex)
  int stream;
  byte *declChunk;
  undefined4 newIndex;
{
  bool destFileMatches;
  bool sourceFileMatches;
  uint opWord0;
  int loopIndex;
  int sourceOperand;
  byte declType;
  int opChunk;
  
  opChunk = **(int **)(stream + 0x20);
  if (opChunk == 0) {
    return;
  }
  do {
    opWord0 = *(uint *)(opChunk + 0xc);
    loopIndex = 0;
    if (opWord0 >> 0x1d != 0) {
      declType = *declChunk;
      sourceOperand = opChunk + 0x10;
      do {
        if (declType == 2) {
          if ((*(uint *)(sourceOperand + 0xc) & 0x3800000) == 0) goto LAB_97bf1e1c;
        }
        else {
          if (declType < 3) {
            if (declType != 0) goto LAB_97bf1e38;
            sourceFileMatches = (*(uint *)(sourceOperand + 0xc) >> 0x17 & 7) == 1;
          }
          else if (declType == 3) {
            sourceFileMatches = (*(uint *)(sourceOperand + 0xc) >> 0x17 & 7) == 2;
          }
          else {
            if (declType != 4) goto LAB_97bf1e38;
            sourceFileMatches = (*(uint *)(sourceOperand + 0xc) >> 0x17 & 7) == 3;
          }
          if (sourceFileMatches) {
LAB_97bf1e1c:
            if (*(short *)(sourceOperand + 0x12) == *(short *)(declChunk + 0x12)) {
              *(undefined2 *)(sourceOperand + 0x12) = (*(unsigned short *)((unsigned char *)&(newIndex) + 2));
              opWord0 = *(uint *)(opChunk + 0xc);
              declType = *declChunk;
            }
          }
        }
LAB_97bf1e38:
        if (declType == 2) {
          if ((*(uint *)(opChunk + 0x14) & 0xe0000) == 0) goto LAB_97bf1ea0;
        }
        else {
          if (declType < 3) {
            if (declType != 0) goto LAB_97bf1eb4;
            destFileMatches = (*(uint *)(opChunk + 0x14) >> 0x11 & 7) == 1;
          }
          else if (declType == 3) {
            destFileMatches = (*(uint *)(opChunk + 0x14) >> 0x11 & 7) == 2;
          }
          else {
            if (declType != 4) goto LAB_97bf1eb4;
            destFileMatches = (*(uint *)(opChunk + 0x14) >> 0x11 & 7) == 3;
          }
          if (destFileMatches) {
LAB_97bf1ea0:
            if (*(short *)(opChunk + 0x1a) == *(short *)(declChunk + 0x12)) {
              *(undefined2 *)(opChunk + 0x1a) = (*(unsigned short *)((unsigned char *)&(newIndex) + 2));
            }
          }
        }
LAB_97bf1eb4:
        loopIndex = loopIndex + 1;
        sourceOperand = sourceOperand + 8;
      } while (loopIndex < (int)(opWord0 >> 0x1d));
    }
    opChunk = *(int *)(opChunk + 8);
    if (opChunk == 0) {
      return;
    }
  } while( true );
}

/* _renumberTempArrayIndices @ 0x97bf1ed8 (56 bytes) */
int _renumberTempArrayIndices(arrayChunk, oldIndex, newIndex)
  int arrayChunk;
  uint oldIndex;
  undefined4 newIndex;
{
  if (arrayChunk != 0) {
    do {
      if (oldIndex == *(ushort *)(arrayChunk + 0xe)) {
        *(undefined2 *)(arrayChunk + 0xe) = (*(unsigned short *)((unsigned char *)&(newIndex) + 2));
      }
      if (oldIndex == *(ushort *)(arrayChunk + 0x12)) {
        *(undefined2 *)(arrayChunk + 0x12) = (*(unsigned short *)((unsigned char *)&(newIndex) + 2));
      }
      arrayChunk = *(int *)(arrayChunk + 8);
    } while (arrayChunk != 0);
    return;
  }
  return;
}

/* _renumberParamArrayIndices @ 0x97bf1f10 (56 bytes) */
int _renumberParamArrayIndices(arrayChunk, oldIndex, newIndex)
  int arrayChunk;
  uint oldIndex;
  undefined4 newIndex;
{
  if (arrayChunk != 0) {
    do {
      if (oldIndex == *(ushort *)(arrayChunk + 0xe)) {
        *(undefined2 *)(arrayChunk + 0xe) = (*(unsigned short *)((unsigned char *)&(newIndex) + 2));
      }
      if (oldIndex == *(ushort *)(arrayChunk + 0x12)) {
        *(undefined2 *)(arrayChunk + 0x12) = (*(unsigned short *)((unsigned char *)&(newIndex) + 2));
      }
      arrayChunk = *(int *)(arrayChunk + 8);
    } while (arrayChunk != 0);
    return;
  }
  return;
}

/* _renumberLabels @ 0x97bf1f48 (72 bytes) */
int _renumberLabels(label, oldIndex, newIndex, markRenumbered)
  int label;
  int oldIndex;
  undefined4 newIndex;
  int markRenumbered;
{
  if (label != 0) {
    do {
      if (((markRenumbered == 0) || (*(char *)(label + 1) == '\0')) &&
         (oldIndex == *(int *)(label + 0xc))) {
        if (markRenumbered != 0) {
          *(undefined1 *)(label + 1) = 1;
        }
        *(undefined4 *)(label + 0xc) = newIndex;
      }
      label = *(int *)(label + 8);
    } while (label != 0);
    return;
  }
  return;
}

/* _renumberTargets @ 0x97bf1f90 (148 bytes) */
int _renumberTargets(opChunk, oldIndex, newIndex, markRenumbered)
  int opChunk;
  uint oldIndex;
  uint newIndex;
  int markRenumbered;
{
  if (opChunk == 0) {
    return;
  }
  do {
    switch(*(uint *)(opChunk + 0xc) >> 0x12 & 0xff) {
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
      if (((markRenumbered == 0) || (*(char *)(opChunk + 1) == '\0')) &&
         (oldIndex == (*(uint *)(opChunk + 0x10) & 0x3ffff))) {
        if (markRenumbered != 0) {
          *(undefined1 *)(opChunk + 1) = 1;
        }
        *(uint *)(opChunk + 0x10) = newIndex & 0x3ffff | *(uint *)(opChunk + 0x10) & 0xfffc0000;
      }
    }
    opChunk = *(int *)(opChunk + 8);
  } while (opChunk != 0);
  return;
}

/* _PPStreamChangeBranchTargets @ 0x97bf20a8 (84 bytes) */
int _PPStreamChangeBranchTargets(stream, oldTarget, newTarget)
  int stream;
  undefined4 oldTarget;
  undefined4 newTarget;
{
  ((int (*)())_renumberLabels)(**(undefined4 **)(stream + 0x24),oldTarget,newTarget,0);
  return ((int (*)())_renumberTargets)(**(undefined4 **)(stream + 0x20),oldTarget,newTarget,0);
}

/* _PPStreamPackIndices @ 0x97bf20fc (612 bytes) */
int _PPStreamPackIndices(stream)
  int stream;
{
  int renumberOpChunk;
  int labelChunk;
  int opChunk;
  int outputChunk;
  int attributeChunk;
  int paramChunk;
  int loopIndex2;
  uint oldOpIndex;
  uint loopIndex;
  int tempChunk;
  int addressChunk;
  
  loopIndex = 0;
  for (tempChunk = **(int **)(stream + 4); tempChunk != 0; tempChunk = *(int *)(tempChunk + 8)) {
    if (*(ushort *)(tempChunk + 0x12) != loopIndex) {
      ((int (*)())_PPStreamRenumberOperandIndices)(stream,tempChunk,loopIndex);
      ((int (*)())_renumberTempArrayIndices)(**(undefined4 **)(stream + 8),(uint)*(ushort *)(tempChunk + 0x12),loopIndex);
      *(short *)(tempChunk + 0x12) = (short)loopIndex;
    }
    loopIndex = loopIndex + 1;
  }
  loopIndex2 = 0;
  for (addressChunk = **(int **)(stream + 0xc); addressChunk != 0; addressChunk = *(int *)(addressChunk + 8)) {
    if (*(int *)(addressChunk + 0xc) != loopIndex2) {
      ((int (*)())_PPStreamRenumberOperandIndices)(stream,addressChunk,loopIndex2);
      *(int *)(addressChunk + 0xc) = loopIndex2;
    }
    loopIndex2 = loopIndex2 + 1;
  }
  loopIndex = 0;
  for (paramChunk = **(int **)(stream + 0x10); paramChunk != 0; paramChunk = *(int *)(paramChunk + 8)) {
    if (*(ushort *)(paramChunk + 0x12) != loopIndex) {
      ((int (*)())_PPStreamRenumberOperandIndices)(stream,paramChunk,loopIndex);
      ((int (*)())_renumberParamArrayIndices)(**(undefined4 **)(stream + 0x14),(uint)*(ushort *)(paramChunk + 0x12),loopIndex);
      *(short *)(paramChunk + 0x12) = (short)loopIndex;
    }
    loopIndex = loopIndex + 1;
  }
  loopIndex = 0;
  for (attributeChunk = **(int **)(stream + 0x18); attributeChunk != 0; attributeChunk = *(int *)(attributeChunk + 8)) {
    if (*(ushort *)(attributeChunk + 0x12) != loopIndex) {
      ((int (*)())_PPStreamRenumberOperandIndices)(stream,attributeChunk,loopIndex);
      *(short *)(attributeChunk + 0x12) = (short)loopIndex;
    }
    loopIndex = loopIndex + 1;
  }
  loopIndex = 0;
  for (outputChunk = **(int **)(stream + 0x1c); outputChunk != 0; outputChunk = *(int *)(outputChunk + 8)) {
    if (*(ushort *)(outputChunk + 0x12) != loopIndex) {
      ((int (*)())_PPStreamRenumberOperandIndices)(stream,outputChunk,loopIndex);
      *(short *)(outputChunk + 0x12) = (short)loopIndex;
    }
    loopIndex = loopIndex + 1;
  }
  for (opChunk = **(int **)(stream + 0x20); opChunk != 0; opChunk = *(int *)(opChunk + 8)) {
    *(undefined1 *)(opChunk + 1) = 0;
  }
  for (labelChunk = **(int **)(stream + 0x24); labelChunk != 0; labelChunk = *(int *)(labelChunk + 8)) {
    *(undefined1 *)(labelChunk + 1) = 0;
  }
  loopIndex = 1;
  for (renumberOpChunk = **(int **)(stream + 0x20); renumberOpChunk != 0; renumberOpChunk = *(int *)(renumberOpChunk + 8)) {
    oldOpIndex = *(uint *)(renumberOpChunk + 0xc) & 0x3ffff;
    if ((oldOpIndex != 0) && (oldOpIndex != loopIndex)) {
      ((int (*)())_renumberLabels)(**(undefined4 **)(stream + 0x24),oldOpIndex,loopIndex,1);
      ((int (*)())_renumberTargets)(**(undefined4 **)(stream + 0x20),*(uint *)(renumberOpChunk + 0xc) & 0x3ffff,loopIndex,1);
      *(uint *)(renumberOpChunk + 0xc) = loopIndex & 0x3ffff | *(uint *)(renumberOpChunk + 0xc) & 0xfffc0000;
    }
    loopIndex = loopIndex + 1;
  }
  return;
}

/* _PPStreamSortParamConstants @ 0x97bf2360 (168 bytes) */
int _PPStreamSortParamConstants(stream)
  int stream;
{
  ushort chunkIndex;
  int maxIndex;
  uint nextConstantIndex;
  int paramChunk;
  
  paramChunk = **(int **)(stream + 0x10);
  maxIndex = _PPStreamChunkListGetMaxIndex(*(int **)(stream + 0x10));
  if (paramChunk != 0) {
    chunkIndex = *(ushort *)(paramChunk + 0x12);
    nextConstantIndex = maxIndex + 1U;
    while ((uint)chunkIndex < maxIndex + 1U) {
      if ((*(uint *)(paramChunk + 0xc) >> 0x10 & 0x1f) == 0x11) {
        ((int (*)())_PPStreamRenumberOperandIndices)(stream,paramChunk,nextConstantIndex);
        ((int (*)())_renumberParamArrayIndices)(**(undefined4 **)(stream + 0x14),(uint)*(ushort *)(paramChunk + 0x12),nextConstantIndex);
        *(short *)(paramChunk + 0x12) = (short)nextConstantIndex;
        nextConstantIndex = nextConstantIndex + 1;
      }
      paramChunk = *(int *)(paramChunk + 8);
      if (paramChunk == 0) break;
      chunkIndex = *(ushort *)(paramChunk + 0x12);
    }
  }
  return _PPStreamChunkListSort(*(undefined4 *)(stream + 0x10));
}

/* _PPStreamResolveBranches @ 0x97bf2408 (340 bytes) */
int _PPStreamResolveBranches(stream)
  int stream;
{
  int operationCursor;
  int compareResult;
  int nameCompareResult;
  undefined4 hasUnresolvedBranch;
  int *labelList;
  int *operationList;
  int chunkCursor;
  int operationTextLength;
  int labelCursor;
  
  operationList = *(int **)(stream + 0x20);
  hasUnresolvedBranch = 0;
  labelList = *(int **)(stream + 0x24);
  chunkCursor = *operationList;
  do {
    if (chunkCursor == 0) {
      chunkCursor = *labelList;
      while( true ) {
        if (chunkCursor == 0) {
          return hasUnresolvedBranch;
        }
        compareResult = _memcmp("main(",chunkCursor + 0x14,6);
        if (compareResult == 0) break;
        chunkCursor = *(int *)(chunkCursor + 8);
      }
      operationCursor = *operationList;
      if (operationCursor == 0) {
        return hasUnresolvedBranch;
      }
      do {
        if (*(uint *)(chunkCursor + 0xc) == (*(uint *)(operationCursor + 0xc) & 0x3ffff)) {
          *(uint *)(operationCursor + 0xc) = *(uint *)(operationCursor + 0xc) & 0xfffc0000;
          *(undefined4 *)(chunkCursor + 0xc) = 0;
          return hasUnresolvedBranch;
        }
        operationCursor = *(int *)(operationCursor + 8);
      } while (operationCursor != 0);
      return hasUnresolvedBranch;
    }
    operationTextLength = *(int *)(chunkCursor + 0x40);
    if (operationTextLength != 0) {
      *(uint *)(chunkCursor + 0x10) = operationList[2] + 1U & 0x3ffff | *(uint *)(chunkCursor + 0x10) & 0xfffc0000;
      for (labelCursor = *labelList; labelCursor != 0; labelCursor = *(int *)(labelCursor + 8)) {
        if ((operationTextLength == *(int *)(labelCursor + 0x10)) &&
           (nameCompareResult = _strncmp(chunkCursor + 0x44,labelCursor + 0x14,operationTextLength), nameCompareResult == 0)) {
          *(uint *)(chunkCursor + 0x10) =
               *(uint *)(labelCursor + 0xc) & 0x3ffff | *(uint *)(chunkCursor + 0x10) & 0xfffc0000;
          goto LAB_97bf24b8;
        }
      }
      hasUnresolvedBranch = 1;
    }
LAB_97bf24b8:
    chunkCursor = *(int *)(chunkCursor + 8);
  } while( true );
}

/* _PPStreamGetArray @ 0x97bf255c (152 bytes) */
int _PPStreamGetArray(stream, arrayKind, registerIndex)
  int stream;
  int arrayKind;
  uint registerIndex;
{
  int arrayChunk;
  int arrayNumber;
  
  arrayNumber = 0;
  if (arrayKind == 1) {
    for (arrayChunk = **(int **)(stream + 8); arrayChunk != 0; arrayChunk = *(int *)(arrayChunk + 8)) {
      if ((*(ushort *)(arrayChunk + 0xe) <= registerIndex) && (registerIndex <= *(ushort *)(arrayChunk + 0x12))) {
        return arrayNumber;
      }
      arrayNumber = arrayNumber + 1;
    }
  }
  else if (arrayKind == 2) {
    for (arrayChunk = **(int **)(stream + 0x14); arrayChunk != 0; arrayChunk = *(int *)(arrayChunk + 8)) {
      if ((*(ushort *)(arrayChunk + 0xe) <= registerIndex) && (registerIndex <= *(ushort *)(arrayChunk + 0x12))) {
        return arrayNumber;
      }
      arrayNumber = arrayNumber + 1;
    }
  }
  return -1;
}

/* _PPStreamFindDuplicateChunk @ 0x97bf25f4 (240 bytes) */
int _PPStreamFindDuplicateChunk(stream, chunk)
  int stream;
  undefined1 *chunk;
{
  int *chunkList;
  int ppStreamChunkCompareResult;
  int candidate;
  
  chunkList = (int *)0x0;
  switch(*chunk) {
  case 0:
    chunkList = *(int **)(stream + 4);
    break;
  case 1:
    chunkList = *(int **)(stream + 0xc);
    break;
  case 2:
    chunkList = *(int **)(stream + 0x18);
    break;
  case 3:
    chunkList = *(int **)(stream + 0x10);
    break;
  case 4:
    chunkList = *(int **)(stream + 0x1c);
    break;
  case 5:
    chunkList = *(int **)(stream + 0x14);
    break;
  case 6:
    chunkList = *(int **)(stream + 8);
    break;
  case 7:
    chunkList = *(int **)(stream + 0x30);
    break;
  case 8:
    chunkList = *(int **)(stream + 0x20);
    break;
  case 9:
    chunkList = *(int **)(stream + 0x28);
    break;
  case 10:
    chunkList = *(int **)(stream + 0x2c);
    break;
  case 0xb:
    chunkList = *(int **)(stream + 0x24);
  }
  candidate = *chunkList;
  while( true ) {
    if (candidate == 0) {
      return 0;
    }
    ppStreamChunkCompareResult = ((int (*)())_PPStreamChunkCompare)(candidate,chunk);
    if (ppStreamChunkCompareResult == 0) break;
    candidate = *(int *)(candidate + 8);
  }
  return candidate;
}

