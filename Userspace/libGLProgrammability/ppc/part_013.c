#include "decls.h"

/* FunctionTable__setNumParams @ 0x97bccbcc (20 bytes) */
int FunctionTable__setNumParams(this, param_1, param_2)
  unsigned char * this;
  int param_1;
  int param_2;
{
  *(int *)(param_1 * 0x18 + *(int *)this + 0xc) = param_2;
  return;
}

/* FunctionTable__setFirstOp @ 0x97bccbe0 (20 bytes) */
int FunctionTable__setFirstOp(this, param_1, param_2)
  unsigned char * this;
  int param_1;
  uint param_2;
{
  *(uint *)(param_1 * 0x18 + *(int *)this + 0x10) = param_2;
  return;
}

/* FunctionTable__setLastOp @ 0x97bccbf4 (20 bytes) */
int FunctionTable__setLastOp(this, param_1, param_2)
  unsigned char * this;
  int param_1;
  uint param_2;
{
  *(uint *)(param_1 * 0x18 + *(int *)this + 0x14) = param_2;
  return;
}

/* FunctionTable__updateForRemovingChunk @ 0x97bccc08 (168 bytes) */
int FunctionTable__updateForRemovingChunk(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar1 = 0;
  if (0 < *(int *)(this + 4)) {
    iVar2 = 0;
    do {
      iVar3 = *(int *)this;
      uVar5 = *(uint *)(param_1 + 0xc);
      iVar4 = iVar2 + iVar3;
      if ((((uVar5 & 0x3ffff) == *(uint *)(iVar4 + 0x14)) && (*(int *)(param_1 + 4) != 0)) &&
         (*(int *)(iVar4 + 0x10) != 0)) {
        *(uint *)(iVar4 + 0x14) = *(uint *)(*(int *)(param_1 + 4) + 0xc) & 0x3ffff;
        uVar5 = *(uint *)(param_1 + 0xc);
        iVar3 = *(int *)this;
      }
      if ((((uVar5 & 0x3ffff) == *(uint *)(iVar2 + iVar3 + 0x10)) && (*(int *)(param_1 + 8) != 0))
         && ((uVar5 & 0x3ffff) != 0)) {
        *(uint *)(iVar2 + iVar3 + 0x10) = *(uint *)(*(int *)(param_1 + 8) + 0xc) & 0x3ffff;
      }
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x18;
    } while (iVar1 < *(int *)(this + 4));
    return;
  }
  return;
}

/* FunctionTable__findFunction @ 0x97bcccb0 (132 bytes) */
int FunctionTable__findFunction(this, param_1)
  unsigned char * this;
  char *param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar1 = *(int *)(this + 4);
  if (0 < iVar1) {
    iVar2 = 0;
    do {
      iVar1 = _strcmp(*(char **)(iVar2 + *(int *)this),param_1);
      if (iVar1 == 0) {
        iVar1 = *(int *)(this + 4);
        break;
      }
      iVar1 = *(int *)(this + 4);
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x18;
    } while (iVar3 < iVar1);
  }
  if (iVar3 == iVar1) {
    iVar3 = -1;
  }
  return iVar3;
}

/* FunctionTable__getFunctionName @ 0x97bccd34 (16 bytes) */
int FunctionTable__getFunctionName(this, param_1)
  unsigned char * this;
  int param_1;
{
  return *(undefined4 *)(param_1 * 0x18 + *(int *)this);
}

/* FunctionTable__getReturnVal @ 0x97bccd44 (20 bytes) */
int FunctionTable__getReturnVal(this, param_1)
  unsigned char * this;
  int param_1;
{
  return *(undefined4 *)(param_1 * 0x18 + *(int *)this + 4);
}

/* FunctionTable__getEmpty @ 0x97bccd58 (20 bytes) */
int FunctionTable__getEmpty(this, param_1)
  unsigned char * this;
  int param_1;
{
  return *(undefined4 *)(param_1 * 0x18 + *(int *)this + 8);
}

/* FunctionTable__getNumParams @ 0x97bccd6c (20 bytes) */
int FunctionTable__getNumParams(this, param_1)
  unsigned char * this;
  int param_1;
{
  return *(undefined4 *)(param_1 * 0x18 + *(int *)this + 0xc);
}

/* FunctionTable__getFirstOp @ 0x97bccd80 (20 bytes) */
int FunctionTable__getFirstOp(this, param_1)
  unsigned char * this;
  int param_1;
{
  return *(undefined4 *)(param_1 * 0x18 + *(int *)this + 0x10);
}

/* FunctionTable__getLastOp @ 0x97bccd94 (20 bytes) */
int FunctionTable__getLastOp(this, param_1)
  unsigned char * this;
  int param_1;
{
  return *(undefined4 *)(param_1 * 0x18 + *(int *)this + 0x14);
}

/* FunctionTable__dump @ 0x97bccda8 (4 bytes) */
int FunctionTable__dump()
{
  return;
}

/* _InterpreterCreate @ 0x97bccdac (60 bytes) */
int _InterpreterCreate()
{
  void *pvVar1;
  
  pvVar1 = _calloc(0xa70,1);
  ((int (*)())_InterpreterInit)();
  return pvVar1;
}

/* _InterpreterFree @ 0x97bccde8 (48 bytes) */
int _InterpreterFree(param_1)
  void *param_1;
{
  ((int (*)())_InterpreterShutdown)();
  _free(param_1);
  return;
}

/* _InterpreterInit @ 0x97bcce18 (72 bytes) */
int _InterpreterInit(param_1)
  void *param_1;
{
  undefined4 uVar1;
  
  _memset(param_1,0,0xa70);
  uVar1 = ((int (*)())_InterpreterTextureSamplerCreate)();
  *(undefined4 *)((int)param_1 + 0xa2c) = uVar1;
  ((int (*)())_InterpreterNoiseGeneratorInitialise)((int)param_1 + 4);
  ((int (*)())_InterpreterRasterOpMachineInitialise)((int)param_1 + 0xa24);
  return;
}

/* _InterpreterShutdown @ 0x97bcce60 (8 bytes) */
int _InterpreterShutdown(param_1)
  int param_1;
{
  _InterpreterTextureSamplerFree(*(undefined4 *)(param_1 + 0xa2c));
  return;
}

/* _InterpreterAttachEmulatorContext @ 0x97bcce68 (12 bytes) */
int _InterpreterAttachEmulatorContext(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  *param_1 = param_2;
  ((int (*)())_InterpreterRasterOpMachineAttachEmulatorContext)(param_1 + 0x289);
  return;
}

/* _InterpreterPackPixel @ 0x97bcce74 (1208 bytes) */
int _InterpreterPackPixel(param_1, param_2, param_3)
  int *param_1;
  float *param_2;
  float *param_3;
{
  float fVar1;
  float fVar2;
  uint uVar3;
  uint uVar4;
  float fVar5;
  uint uVar6;
  float fVar7;
  uint uVar8;
  int iVar9;
  bool bVar10;
  double dVar11;
  double dVar12;
  
  iVar9 = *param_1;
  if (*(int *)(iVar9 + 0xd9c) != 0) {
    uVar4 = _PPEmulatorFramebufferFormat(iVar9);
    if ((uVar4 & 0x8000000) == 0) {
      uVar4 = _PPEmulatorFramebufferFormat(iVar9);
      fVar5 = FLOAT_97c3acc0;
      fVar2 = FLOAT_97c3acbc;
      if ((uVar4 & 0x8000) == 0) {
        uVar4 = _PPEmulatorFramebufferFormat(iVar9);
        fVar5 = FLOAT_97c3acc4;
        fVar2 = FLOAT_97c3acc0;
        if ((uVar4 & 0x400) == 0) {
          return;
        }
        fVar7 = *param_2 * FLOAT_97c3acc4 + FLOAT_97c3acc0;
        fVar1 = param_2[1] * FLOAT_97c3acc4 + FLOAT_97c3acc0;
        bVar10 = TAllocation__guardBlockSize <= fVar7;
        *param_2 = fVar7;
        param_2[1] = fVar1;
        param_2[2] = param_2[2] * fVar5 + fVar2;
        fVar2 = TAllocation__guardBlockSize;
        if (bVar10) {
          if (fVar5 < fVar7) {
            fVar7 = 31.0;
          }
        }
        else {
          fVar7 = 0.0;
        }
        fVar5 = param_2[1];
        *param_2 = fVar7;
        fVar7 = TAllocation__guardBlockSize;
        if (fVar2 <= fVar5) {
          if (FLOAT_97c3acc4 < fVar5) {
            fVar5 = 31.0;
          }
        }
        else {
          fVar5 = 0.0;
        }
        fVar2 = param_2[2];
        param_2[1] = fVar5;
        dVar12 = DOUBLE_97c30a78;
        if (fVar7 <= fVar2) {
          if (FLOAT_97c3acc4 < fVar2) {
            fVar2 = 31.0;
          }
        }
        else {
          fVar2 = 0.0;
        }
        dVar11 = (double)*param_2;
        param_2[2] = fVar2;
        if (dVar12 <= dVar11) {
          uVar4 = (uint)(dVar11 - dVar12);
        }
        else {
          uVar4 = (uint)*param_2;
        }
        dVar12 = (double)param_2[1];
        if (DOUBLE_97c30a78 <= dVar12) {
          uVar6 = (uint)(dVar12 - DOUBLE_97c30a78);
        }
        else {
          uVar6 = (uint)param_2[1];
        }
        dVar12 = (double)param_2[2];
        if (DOUBLE_97c30a78 <= dVar12) {
          uVar8 = (uint)(dVar12 - DOUBLE_97c30a78);
        }
        else {
          uVar8 = (uint)param_2[2];
        }
        if (FLOAT_97c3acc0 <= param_2[3]) {
          uVar3 = 0x8000;
        }
        else {
          uVar3 = 0;
        }
        fVar2 = (float)(uVar3 | (uVar4 & 0x1f) << 10 | (uVar6 & 0x1f) << 5 | uVar8 & 0x1f);
      }
      else {
        fVar7 = *param_2 * FLOAT_97c3acbc + FLOAT_97c3acc0;
        fVar1 = param_2[1] * FLOAT_97c3acbc + FLOAT_97c3acc0;
        bVar10 = TAllocation__guardBlockSize <= fVar7;
        *param_2 = fVar7;
        param_2[1] = fVar1;
        param_2[3] = param_2[3] * fVar2 + fVar5;
        param_2[2] = param_2[2] * fVar2 + fVar5;
        fVar5 = TAllocation__guardBlockSize;
        if (bVar10) {
          if (fVar2 < fVar7) {
            fVar7 = 255.0;
          }
        }
        else {
          fVar7 = 0.0;
        }
        fVar2 = param_2[1];
        *param_2 = fVar7;
        fVar7 = TAllocation__guardBlockSize;
        if (fVar5 <= fVar2) {
          if (FLOAT_97c3acbc < fVar2) {
            fVar2 = 255.0;
          }
        }
        else {
          fVar2 = 0.0;
        }
        fVar5 = param_2[2];
        param_2[1] = fVar2;
        fVar2 = TAllocation__guardBlockSize;
        if (fVar7 <= fVar5) {
          if (FLOAT_97c3acbc < fVar5) {
            fVar5 = 255.0;
          }
        }
        else {
          fVar5 = 0.0;
        }
        fVar7 = param_2[3];
        param_2[2] = fVar5;
        dVar12 = DOUBLE_97c30a78;
        if (fVar2 <= fVar7) {
          if (FLOAT_97c3acbc < fVar7) {
            fVar7 = 255.0;
          }
        }
        else {
          fVar7 = 0.0;
        }
        dVar11 = (double)*param_2;
        param_2[3] = fVar7;
        if (dVar12 <= dVar11) {
          uVar4 = (uint)(dVar11 - dVar12);
        }
        else {
          uVar4 = (uint)*param_2;
        }
        dVar12 = (double)param_2[1];
        if (DOUBLE_97c30a78 <= dVar12) {
          uVar6 = (uint)(dVar12 - DOUBLE_97c30a78);
        }
        else {
          uVar6 = (uint)param_2[1];
        }
        dVar12 = (double)param_2[2];
        if (DOUBLE_97c30a78 <= dVar12) {
          uVar8 = (uint)(dVar12 - DOUBLE_97c30a78);
        }
        else {
          uVar8 = (uint)param_2[2];
        }
        dVar12 = (double)param_2[3];
        if (DOUBLE_97c30a78 <= dVar12) {
          iVar9 = (int)(dVar12 - DOUBLE_97c30a78);
        }
        else {
          iVar9 = (int)param_2[3];
        }
        fVar2 = (float)(iVar9 << 0x18 | (uVar4 & 0xff) << 0x10 | (uVar6 & 0xff) << 8 | uVar8 & 0xff)
        ;
      }
      *param_3 = fVar2;
    }
    else {
      fVar2 = *param_2;
      fVar5 = param_2[1];
      fVar7 = param_2[2];
      param_3[3] = param_2[3];
      *param_3 = fVar2;
      param_3[1] = fVar5;
      param_3[2] = fVar7;
    }
  }
  return;
}

/* _InterpreterUnpackPixel @ 0x97bcd32c (428 bytes) */
int _InterpreterUnpackPixel(param_1, param_2, param_3)
  int *param_1;
  float *param_2;
  float *param_3;
{
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  
  iVar7 = *param_1;
  if (*(int *)(iVar7 + 0xd9c) != 0) {
    uVar4 = _PPEmulatorFramebufferFormat(iVar7);
    if ((uVar4 & 0x8000000) == 0) {
      uVar4 = _PPEmulatorFramebufferFormat(iVar7);
      if ((uVar4 & 0x8000) == 0) {
        uVar4 = _PPEmulatorFramebufferFormat(iVar7);
        if ((uVar4 & 0x400) == 0) {
          return;
        }
        fVar6 = *param_3;
        fVar3 = (float)((double)CONCAT44(0x43300000,(uint)fVar6 >> 10 & 0x1f) - DOUBLE_97c30a68) -
                FLOAT_97c3acc0;
        fVar5 = (float)((double)CONCAT44(0x43300000,(uint)fVar6 >> 5 & 0x1f) - DOUBLE_97c30a68) -
                FLOAT_97c3acc0;
        fVar2 = (float)((double)CONCAT44(0x43300000,(uint)fVar6 >> 0xf & 1) - DOUBLE_97c30a68) -
                FLOAT_97c3acc0;
        fVar6 = (float)((double)CONCAT44(0x43300000,(uint)fVar6 & 0x1f) - DOUBLE_97c30a68) -
                FLOAT_97c3acc0;
        fVar1 = FLOAT_97c3accc;
      }
      else {
        fVar2 = *param_3;
        fVar3 = (float)((double)CONCAT44(0x43300000,(uint)fVar2 >> 0x10 & 0xff) - DOUBLE_97c30a68);
        fVar5 = (float)((double)CONCAT44(0x43300000,(uint)fVar2 >> 8 & 0xff) - DOUBLE_97c30a68);
        fVar6 = (float)((double)CONCAT44(0x43300000,(uint)fVar2 & 0xff) - DOUBLE_97c30a68);
        fVar2 = (float)((double)CONCAT44(0x43300000,(uint)fVar2 >> 0x18) - DOUBLE_97c30a68);
        fVar1 = FLOAT_97c3acc8;
      }
      param_2[3] = fVar2 * fVar1;
      *param_2 = fVar3 * fVar1;
      param_2[1] = fVar5 * fVar1;
      param_2[2] = fVar6 * fVar1;
    }
    else {
      fVar3 = *param_3;
      fVar5 = param_3[1];
      fVar6 = param_3[2];
      param_2[3] = param_3[3];
      *param_2 = fVar3;
      param_2[1] = fVar5;
      param_2[2] = fVar6;
    }
  }
  return;
}

/* _InterpreterWriteDestination @ 0x97bcd4d8 (1100 bytes) */
int _InterpreterWriteDestination(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int *param_1;
  int param_2;
  int param_3;
  uint param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  int iVar1;
  int iVar2;
  float *pfVar3;
  float *pfVar4;
  float *pfVar5;
  int *piVar6;
  float *pfVar7;
  int *piVar8;
  undefined1 uVar9;
  int iStack0000001c;
  int iStack00000020;
  uint uStack00000024;
  short sStack00000028;
  ushort uStack0000002c;
  char cStack0000002f;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  uint in_stack_00000038;
  int in_stack_00000040;
  float *in_stack_00000044;
  char in_stack_0000004b;
  float local_50 [4];
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  
  pfVar5 = local_50;
  local_40 = in_stack_00000044[param_4 >> 0x18];
  local_3c = in_stack_00000044[param_4 >> 0x10 & 0xff];
  local_38 = in_stack_00000044[param_4 >> 8 & 0xff];
  local_34 = in_stack_00000044[param_4 & 0xff];
  iVar1 = *param_1;
  *in_stack_00000044 = local_40;
  in_stack_00000044[1] = local_3c;
  in_stack_00000044[2] = local_38;
  in_stack_00000044[3] = local_34;
  iVar2 = *(int *)(iVar1 + 0xd80);
  uStack0000002c = (ushort)((uint)param_6 >> 0x10);
  if (((*(int *)(iVar2 + 0x38) == 0x8804) || (*(int *)(iVar2 + 0x38) == 0x8b30)) &&
     (uStack0000002c == 1)) {
    piVar6 = param_1 + 0x292;
    piVar8 = (int *)(param_2 + in_stack_00000040 * 0x10);
  }
  else {
    if (((*(int *)(iVar2 + 0x38) == 0x8804) || (*(int *)(iVar2 + 0x38) == 0x8b30)) &&
       (uStack0000002c == 9)) {
      piVar6 = param_1 + 0x28c;
    }
    else {
      cStack0000002f = (char)param_6;
      piVar6 = *(int **)((uint)uStack0000002c * 4 + iVar1 + 0xd84);
      if (cStack0000002f != '\0') {
        iVar2 = param_3 * 0xc + iVar2;
        sStack00000028 = (short)((uint)param_5 >> 0x10);
        iVar1 = *(int *)(iVar2 + 0x80);
        piVar8 = (int *)(iVar1 + (((uint)((param_2 + in_stack_00000040 * 0x10) - iVar1) >> 4) +
                                  param_1[0x290] + (int)sStack00000028 & *(uint *)(iVar2 + 0x88)) *
                                 0x10);
        goto LAB_97bcd680;
      }
    }
    piVar8 = (int *)(param_2 + in_stack_00000040 * 0x10);
  }
LAB_97bcd680:
  pfVar4 = pfVar5;
  iStack0000001c = param_2;
  iStack00000020 = param_3;
  uStack00000024 = param_4;
  (*(short *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)) = param_5;
  (*(unsigned int *)(*(unsigned int *)__builtin_frame_address(0) + 0x2c)) = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  if ((((in_stack_00000038 & 0x1000000) != 0) &&
      (iVar1 = ((int (*)())_InterpreterTestCR)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8),
      iVar1 != 0)) && (pfVar4 = (float *)((int)piVar6 + *piVar8), in_stack_0000004b != '\0')) {
    iVar1 = ___isnanf((double)*in_stack_00000044);
    uVar9 = 3;
    if ((iVar1 == 0) &&
       (uVar9 = DOUBLE_97c30a48 < (double)*in_stack_00000044,
       (double)*in_stack_00000044 < DOUBLE_97c30a48)) {
      uVar9 = 2;
    }
    *(undefined1 *)(param_1 + 0x291) = uVar9;
  }
  pfVar7 = pfVar5;
  if ((((in_stack_00000038 & 0x2000000) != 0) &&
      (iVar1 = ((int (*)())_InterpreterTestCR)(param_1,iStack0000001c,iStack00000020,uStack00000024,
                                  (*(short *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)),(*(unsigned int *)(*(unsigned int *)__builtin_frame_address(0) + 0x2c)),uStack00000030,uStack00000034),
      iVar1 != 0)) && (pfVar7 = (float *)((int)piVar6 + piVar8[1]), in_stack_0000004b != '\0')) {
    iVar1 = ___isnanf((double)in_stack_00000044[1]);
    uVar9 = 3;
    if ((iVar1 == 0) &&
       (uVar9 = DOUBLE_97c30a48 < (double)in_stack_00000044[1],
       (double)in_stack_00000044[1] < DOUBLE_97c30a48)) {
      uVar9 = 2;
    }
    *(undefined1 *)((int)param_1 + 0xa45) = uVar9;
  }
  pfVar3 = pfVar5;
  if ((((in_stack_00000038 & 0x4000000) != 0) &&
      (iVar1 = ((int (*)())_InterpreterTestCR)(param_1,iStack0000001c,iStack00000020,uStack00000024,
                                  (*(short *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)),(*(unsigned int *)(*(unsigned int *)__builtin_frame_address(0) + 0x2c)),uStack00000030,uStack00000034),
      iVar1 != 0)) && (pfVar3 = (float *)((int)piVar6 + piVar8[2]), in_stack_0000004b != '\0')) {
    iVar1 = ___isnanf((double)in_stack_00000044[2]);
    uVar9 = 3;
    if ((iVar1 == 0) &&
       (uVar9 = DOUBLE_97c30a48 < (double)in_stack_00000044[2],
       (double)in_stack_00000044[2] < DOUBLE_97c30a48)) {
      uVar9 = 2;
    }
    *(undefined1 *)((int)param_1 + 0xa46) = uVar9;
  }
  if ((((in_stack_00000038 & 0x8000000) != 0) &&
      (iVar1 = ((int (*)())_InterpreterTestCR)(param_1,iStack0000001c,iStack00000020,uStack00000024,
                                  (*(short *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)),(*(unsigned int *)(*(unsigned int *)__builtin_frame_address(0) + 0x2c)),uStack00000030,uStack00000034),
      iVar1 != 0)) && (pfVar5 = (float *)((int)piVar6 + piVar8[3]), in_stack_0000004b != '\0')) {
    iVar1 = ___isnanf((double)in_stack_00000044[3]);
    uVar9 = 3;
    if ((iVar1 == 0) &&
       (uVar9 = DOUBLE_97c30a48 < (double)in_stack_00000044[3],
       (double)in_stack_00000044[3] < DOUBLE_97c30a48)) {
      uVar9 = 2;
    }
    *(undefined1 *)((int)param_1 + 0xa47) = uVar9;
  }
  *pfVar4 = *in_stack_00000044;
  *pfVar7 = in_stack_00000044[1];
  *pfVar3 = in_stack_00000044[2];
  *pfVar5 = in_stack_00000044[3];
  return;
}

/* _InterpreterLoadSource @ 0x97bcd924 (796 bytes) */
int _InterpreterLoadSource(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int *param_1;
  int *param_2;
  int param_3;
  uint param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  uint param_8;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  double dVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  byte bStack00000024;
  byte bStack00000025;
  byte bStack00000026;
  short sStack00000028;
  ushort uStack0000002c;
  char cStack0000002e;
  char cStack0000002f;
  int in_stack_00000040;
  float *in_stack_00000044;
  
  dVar5 = DOUBLE_97c30a58;
  iVar8 = *param_1;
  iVar6 = *(int *)(*(int *)(iVar8 + 0xd80) + 0x38);
  uStack0000002c = (ushort)((uint)param_6 >> 0x10);
  bStack00000026 = (byte)(param_4 >> 8);
  bStack00000025 = (byte)(param_4 >> 0x10);
  bStack00000024 = (byte)(param_4 >> 0x18);
  if (((iVar6 == 0x8804) || (iVar6 == 0x8b30)) && (uStack0000002c == 2)) {
    iVar6 = *(int *)(iVar8 + 0xda4);
    iVar8 = *(int *)(iVar8 + 0xda0);
    fVar1 = *(float *)(iVar6 + param_2[in_stack_00000040 * 4 + (uint)bStack00000024]) *
            (float)param_1[0x28c] +
            *(float *)(iVar8 + param_2[in_stack_00000040 * 4 + (uint)bStack00000024]);
    *in_stack_00000044 = fVar1;
    fVar2 = *(float *)(iVar6 + param_2[in_stack_00000040 * 4 + (uint)bStack00000025]) *
            (float)param_1[0x28c] +
            *(float *)(iVar8 + param_2[in_stack_00000040 * 4 + (uint)bStack00000025]);
    in_stack_00000044[1] = fVar2;
    fVar3 = *(float *)(iVar6 + param_2[in_stack_00000040 * 4 + (uint)bStack00000026]) *
            (float)param_1[0x28c] +
            *(float *)(iVar8 + param_2[in_stack_00000040 * 4 + (uint)bStack00000026]);
    in_stack_00000044[2] = fVar3;
    fVar4 = *(float *)(iVar6 + param_2[in_stack_00000040 * 4 + (param_4 & 0xff)]) *
            (float)param_1[0x28c] +
            *(float *)(iVar8 + param_2[in_stack_00000040 * 4 + (param_4 & 0xff)]);
    in_stack_00000044[3] = fVar4;
    if (*param_2 != 0) {
      *in_stack_00000044 = fVar1 * (float)param_1[0x28f];
      in_stack_00000044[1] = fVar2 * (float)param_1[0x28f];
      in_stack_00000044[2] = fVar3 * (float)param_1[0x28f];
      in_stack_00000044[3] = fVar4 * (float)param_1[0x28f];
    }
  }
  else {
    cStack0000002f = (char)param_6;
    if (cStack0000002f == '\0') {
      param_2 = param_2 + in_stack_00000040 * 4;
    }
    else {
      iVar7 = param_3 * 0xc + *(int *)(iVar8 + 0xd80);
      sStack00000028 = (short)((uint)param_5 >> 0x10);
      iVar6 = *(int *)(iVar7 + 0x80);
      param_2 = (int *)(iVar6 + (((uint)((int)param_2 + (in_stack_00000040 * 0x10 - iVar6)) >> 4) +
                                 param_1[0x290] + (int)sStack00000028 & *(uint *)(iVar7 + 0x88)) *
                                0x10);
    }
    iVar6 = *(int *)((uint)uStack0000002c * 4 + iVar8 + 0xd84);
    if (param_8 < 2) {
      *in_stack_00000044 = *(float *)(iVar6 + param_2[bStack00000024]);
      in_stack_00000044[1] = *(float *)(iVar6 + param_2[bStack00000025]);
      in_stack_00000044[2] = *(float *)(iVar6 + param_2[bStack00000026]);
      fVar1 = *(float *)(iVar6 + param_2[param_4 & 0xff]);
    }
    else {
      if (1 < param_8 - 3) goto LAB_97bcdbfc;
      *in_stack_00000044 =
           (float)((double)CONCAT44(0x43300000,
                                    *(uint *)(iVar6 + param_2[bStack00000024]) ^ 0x80000000) -
                  DOUBLE_97c30a58);
      in_stack_00000044[1] =
           (float)((double)CONCAT44(0x43300000,
                                    *(uint *)(iVar6 + param_2[bStack00000025]) ^ 0x80000000) - dVar5
                  );
      in_stack_00000044[2] =
           (float)((double)CONCAT44(0x43300000,
                                    *(uint *)(iVar6 + param_2[bStack00000026]) ^ 0x80000000) - dVar5
                  );
      fVar1 = (float)((double)CONCAT44(0x43300000,
                                       *(uint *)(iVar6 + param_2[param_4 & 0xff]) ^ 0x80000000) -
                     dVar5);
    }
    in_stack_00000044[3] = fVar1;
  }
LAB_97bcdbfc:
  cStack0000002e = (char)((uint)param_6 >> 8);
  if (cStack0000002e != '\0') {
    *in_stack_00000044 = -*in_stack_00000044;
    in_stack_00000044[1] = -in_stack_00000044[1];
    in_stack_00000044[2] = -in_stack_00000044[2];
    in_stack_00000044[3] = -in_stack_00000044[3];
  }
  return;
}

/* _InterpreterTestCR @ 0x97bcdc40 (240 bytes) */
int _InterpreterTestCR(param_1)
  int param_1;
{
  uint uVar1;
  uint uVar2;
  undefined4 in_stack_00000038;
  int in_stack_00000040;
  
  uVar1 = 0;
  uVar2 = (uint)*(byte *)((uint)*(byte *)((int)&STACKARG(0x38) + in_stack_00000040 + 2) + param_1 +
                         0xa44);
  switch((*(unsigned char *)((unsigned char *)&(in_stack_00000038) + 1))) {
  case 0:
    uVar1 = 1;
    break;
  case 1:
    uVar1 = (uint)(uVar2 == 0);
    break;
  case 2:
    uVar1 = (uint)(uVar2 < 2);
    break;
  case 3:
    uVar1 = (uint)(uVar2 == 1);
    break;
  case 4:
    uVar1 = 0;
    if ((uVar2 == 2) || (uVar2 == 0)) {
      uVar1 = 1;
    }
    break;
  case 5:
    uVar1 = (uint)(uVar2 == 2);
    break;
  case 6:
    uVar1 = -uVar2 >> 0x1f;
    break;
  case 7:
    uVar1 = 0;
  }
  return uVar1;
}

/* _InterpreterEmulateOp @ 0x97bcdd50 (20820 bytes) */
int _InterpreterEmulateOp()
{
  float *pfVar1;
  float *pfVar2;
  bool bVar3;
  float fVar4;
  char cVar5;
  byte bVar6;
  char cVar7;
  float fVar8;
  uint uVar9;
  uint uVar10;
  byte *pbVar11;
  float *pfVar12;
  int *piVar13;
  int *piVar14;
  int *piVar15;
  undefined4 uVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int *piVar21;
  int iVar22;
  uint uVar23;
  int iVar24;
  uint uVar25;
  bool bVar26;
  int iVar27;
  double dVar28;
  double dVar29;
  double dVar30;
  double dVar31;
  double dVar32;
  undefined8 uVar33;
  float local_130 [12];
  float local_100 [4];
  float local_f0;
  float local_ec;
  float local_e8;
  float local_e4;
  float local_e0;
  float local_dc;
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  undefined4 local_b0;
  uint uStack_ac;
  longlong local_a8;
  longlong local_a0;
  longlong local_98;
  longlong local_90;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  
  uVar33 = FUN_97c1a258();
  piVar14 = (int *)((ulonglong)uVar33 >> 0x20);
  piVar15 = (int *)uVar33;
  iVar22 = *piVar14;
  piVar21 = piVar15 + 0x47;
  if (piVar15 == *(int **)(*(int *)(iVar22 + 0xd80) + 4)) {
    piVar21 = (int *)0x0;
  }
  iVar18 = piVar15[0xc];
  local_130[3] = 0.0;
  uVar23 = 1;
  local_130[0] = 0.0;
  local_130[1] = 0.0;
  bVar26 = true;
  local_130[2] = 0.0;
  iVar24 = *piVar15;
  cVar5 = *(char *)(piVar15 + 1);
  if (iVar18 != 0) {
    pbVar11 = (byte *)((int)piVar15 + 0x49);
    iVar27 = iVar18;
    do {
      if ((pbVar11[-1] != 0) && (uVar23 < *pbVar11)) {
        uVar23 = (uint)*pbVar11;
      }
      pbVar11 = pbVar11 + 0x24;
      iVar27 = iVar27 + -1;
    } while (iVar27 != 0);
  }
  if (iVar24 == 0x22) {
    cVar5 = *(char *)(piVar15 + 0x12);
    if ((cVar5 == '\0') && (*(char *)(piVar15 + 0x1b) == '\0')) {
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                 piVar15[0x1b],piVar15[0x1c]);
      local_130[0] = local_130[4] * local_130[8];
      local_130[1] = local_130[5] * local_130[9];
      local_130[2] = local_130[6] * local_130[10];
      iVar20 = piVar15[9];
      local_130[3] = local_130[7] * local_130[0xb];
      iVar22 = piVar15[3];
      iVar18 = piVar15[4];
      iVar24 = piVar15[5];
      iVar27 = piVar15[6];
      iVar17 = piVar15[7];
      iVar19 = piVar15[8];
    }
    else if ((cVar5 == '\0') ||
            ((*(char *)(piVar15 + 0x1b) == '\0' ||
             (*(char *)((int)piVar15 + 0x49) != *(char *)((int)piVar15 + 0x6d))))) {
      if ((cVar5 == '\0') || (*(byte *)((int)piVar15 + 0x6d) < 2)) {
        if ((*(char *)(piVar15 + 0x1b) == '\0') || (*(byte *)((int)piVar15 + 0x49) < 2)) {
          uVar25 = (uint)(cVar5 == '\0');
          if (uVar25 == 0) {
            iVar22 = 0x54;
          }
          else {
            iVar22 = 0x30;
          }
          ((int (*)())_InterpreterLoadSource)(piVar14,*(undefined4 *)((int)piVar15 + iVar22 + 4),
                     *(undefined4 *)((int)piVar15 + iVar22 + 8),
                     *(undefined4 *)((int)piVar15 + iVar22 + 0xc),
                     *(undefined4 *)((int)piVar15 + iVar22 + 0x10),
                     *(undefined4 *)((int)piVar15 + iVar22 + 0x14),
                     *(undefined4 *)((int)piVar15 + iVar22 + 0x18),
                     *(undefined4 *)((int)piVar15 + iVar22 + 0x1c));
          ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[uVar25 * 9 + 0xd],piVar15[uVar25 * 9 + 0xe],
                     piVar15[uVar25 * 9 + 0xf],piVar15[uVar25 * 9 + 0x10],piVar15[uVar25 * 9 + 0x11]
                     ,piVar15[uVar25 * 9 + 0x12],piVar15[uVar25 * 9 + 0x13]);
          if (uVar23 == 2) {
            local_130[0] = local_130[4] * local_130[8];
            local_130[1] = local_130[4] * local_130[9];
            ((int (*)())_InterpreterWriteDestination)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],piVar15[7],piVar15[8],
                       piVar15[9]);
            ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[uVar25 * 9 + 0xd],piVar15[uVar25 * 9 + 0xe],
                       piVar15[uVar25 * 9 + 0xf],piVar15[uVar25 * 9 + 0x10],
                       piVar15[uVar25 * 9 + 0x11],piVar15[uVar25 * 9 + 0x12],
                       piVar15[uVar25 * 9 + 0x13]);
            local_130[0] = local_130[4] * local_130[8];
            iVar20 = piVar15[9];
            local_130[1] = local_130[4] * local_130[9];
            iVar22 = piVar15[3];
            iVar18 = piVar15[4];
            iVar24 = piVar15[5];
            iVar27 = piVar15[6];
            iVar17 = piVar15[7];
            iVar19 = piVar15[8];
          }
          else if (uVar23 == 3) {
            local_130[0] = local_130[4] * local_130[8];
            local_130[2] = local_130[4] * local_130[10];
            local_130[1] = local_130[4] * local_130[9];
            ((int (*)())_InterpreterWriteDestination)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],piVar15[7],piVar15[8],
                       piVar15[9]);
            ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[uVar25 * 9 + 0xd],piVar15[uVar25 * 9 + 0xe],
                       piVar15[uVar25 * 9 + 0xf],piVar15[uVar25 * 9 + 0x10],
                       piVar15[uVar25 * 9 + 0x11],piVar15[uVar25 * 9 + 0x12],
                       piVar15[uVar25 * 9 + 0x13]);
            local_130[0] = local_130[4] * local_130[8];
            local_130[2] = local_130[4] * local_130[10];
            local_130[1] = local_130[4] * local_130[9];
            ((int (*)())_InterpreterWriteDestination)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],piVar15[7],piVar15[8],
                       piVar15[9]);
            ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[uVar25 * 9 + 0xd],piVar15[uVar25 * 9 + 0xe],
                       piVar15[uVar25 * 9 + 0xf],piVar15[uVar25 * 9 + 0x10],
                       piVar15[uVar25 * 9 + 0x11],piVar15[uVar25 * 9 + 0x12],
                       piVar15[uVar25 * 9 + 0x13]);
            local_130[0] = local_130[4] * local_130[8];
            local_130[2] = local_130[4] * local_130[10];
            iVar20 = piVar15[9];
            local_130[1] = local_130[4] * local_130[9];
            iVar22 = piVar15[3];
            iVar18 = piVar15[4];
            iVar24 = piVar15[5];
            iVar27 = piVar15[6];
            iVar17 = piVar15[7];
            iVar19 = piVar15[8];
          }
          else {
            if (uVar23 != 4) {
              return piVar21;
            }
            local_130[0] = local_130[4] * local_130[8];
            local_130[3] = local_130[4] * local_130[0xb];
            local_130[1] = local_130[4] * local_130[9];
            local_130[2] = local_130[4] * local_130[10];
            ((int (*)())_InterpreterWriteDestination)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],piVar15[7],piVar15[8],
                       piVar15[9]);
            ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[uVar25 * 9 + 0xd],piVar15[uVar25 * 9 + 0xe],
                       piVar15[uVar25 * 9 + 0xf],piVar15[uVar25 * 9 + 0x10],
                       piVar15[uVar25 * 9 + 0x11],piVar15[uVar25 * 9 + 0x12],
                       piVar15[uVar25 * 9 + 0x13]);
            local_130[0] = local_130[4] * local_130[8];
            local_130[3] = local_130[4] * local_130[0xb];
            local_130[1] = local_130[4] * local_130[9];
            local_130[2] = local_130[4] * local_130[10];
            ((int (*)())_InterpreterWriteDestination)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],piVar15[7],piVar15[8],
                       piVar15[9]);
            ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[uVar25 * 9 + 0xd],piVar15[uVar25 * 9 + 0xe],
                       piVar15[uVar25 * 9 + 0xf],piVar15[uVar25 * 9 + 0x10],
                       piVar15[uVar25 * 9 + 0x11],piVar15[uVar25 * 9 + 0x12],
                       piVar15[uVar25 * 9 + 0x13]);
            local_130[0] = local_130[4] * local_130[8];
            local_130[3] = local_130[4] * local_130[0xb];
            local_130[1] = local_130[4] * local_130[9];
            local_130[2] = local_130[4] * local_130[10];
            ((int (*)())_InterpreterWriteDestination)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],piVar15[7],piVar15[8],
                       piVar15[9]);
            ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[uVar25 * 9 + 0xd],piVar15[uVar25 * 9 + 0xe],
                       piVar15[uVar25 * 9 + 0xf],piVar15[uVar25 * 9 + 0x10],
                       piVar15[uVar25 * 9 + 0x11],piVar15[uVar25 * 9 + 0x12],
                       piVar15[uVar25 * 9 + 0x13]);
            local_130[0] = local_130[4] * local_130[8];
            local_130[3] = local_130[4] * local_130[0xb];
            local_130[1] = local_130[4] * local_130[9];
            iVar20 = piVar15[9];
            local_130[2] = local_130[4] * local_130[10];
            iVar22 = piVar15[3];
            iVar18 = piVar15[4];
            iVar24 = piVar15[5];
            iVar27 = piVar15[6];
            iVar17 = piVar15[7];
            iVar19 = piVar15[8];
          }
          goto LAB_97bd043c;
        }
        ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                   piVar15[0x12],piVar15[0x13]);
        ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                   piVar15[0x1b],piVar15[0x1c]);
        if (uVar23 == 2) {
          local_130[0] = local_130[4] * local_130[8] + local_130[5] * local_130[9];
          ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                     piVar15[0x1b],piVar15[0x1c]);
          local_130[1] = local_130[4] * local_130[8] + local_130[5] * local_130[9];
        }
        else if (uVar23 == 3) {
          local_130[0] = local_130[6] * local_130[10] +
                         local_130[4] * local_130[8] + local_130[5] * local_130[9];
          ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                     piVar15[0x1b],piVar15[0x1c]);
          local_130[1] = local_130[6] * local_130[10] +
                         local_130[4] * local_130[8] + local_130[5] * local_130[9];
          ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                     piVar15[0x1b],piVar15[0x1c]);
          local_130[2] = local_130[6] * local_130[10] +
                         local_130[4] * local_130[8] + local_130[5] * local_130[9];
        }
        else if (uVar23 == 4) {
          local_130[0] = local_130[7] * local_130[0xb] +
                         local_130[6] * local_130[10] +
                         local_130[4] * local_130[8] + local_130[5] * local_130[9];
          ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                     piVar15[0x1b],piVar15[0x1c]);
          local_130[1] = local_130[7] * local_130[0xb] +
                         local_130[6] * local_130[10] +
                         local_130[4] * local_130[8] + local_130[5] * local_130[9];
          ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                     piVar15[0x1b],piVar15[0x1c]);
          local_130[2] = local_130[7] * local_130[0xb] +
                         local_130[6] * local_130[10] +
                         local_130[4] * local_130[8] + local_130[5] * local_130[9];
          ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                     piVar15[0x1b],piVar15[0x1c]);
          local_130[3] = local_130[7] * local_130[0xb] +
                         local_130[6] * local_130[10] +
                         local_130[4] * local_130[8] + local_130[5] * local_130[9];
        }
      }
      else {
        ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                   piVar15[0x12],piVar15[0x13]);
        ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                   piVar15[0x1b],piVar15[0x1c]);
        if (uVar23 == 2) {
          local_130[0] = local_130[4] * local_130[8];
          local_130[1] = local_130[4] * local_130[9];
          ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                     piVar15[0x12],piVar15[0x13]);
          local_130[0] = local_130[5] * local_130[8] + local_130[0];
          local_130[1] = local_130[5] * local_130[9] + local_130[1];
        }
        else if (uVar23 == 3) {
          local_130[0] = local_130[4] * local_130[8];
          local_130[2] = local_130[4] * local_130[10];
          local_130[1] = local_130[4] * local_130[9];
          ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                     piVar15[0x12],piVar15[0x13]);
          local_130[0] = local_130[5] * local_130[8] + local_130[0];
          local_130[2] = local_130[5] * local_130[10] + local_130[2];
          local_130[1] = local_130[5] * local_130[9] + local_130[1];
          ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                     piVar15[0x12],piVar15[0x13]);
          local_130[0] = local_130[6] * local_130[8] + local_130[0];
          local_130[2] = local_130[6] * local_130[10] + local_130[2];
          local_130[1] = local_130[6] * local_130[9] + local_130[1];
        }
        else if (uVar23 == 4) {
          local_130[0] = local_130[4] * local_130[8];
          local_130[3] = local_130[4] * local_130[0xb];
          local_130[1] = local_130[4] * local_130[9];
          local_130[2] = local_130[4] * local_130[10];
          ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                     piVar15[0x12],piVar15[0x13]);
          local_130[0] = local_130[5] * local_130[8] + local_130[0];
          local_130[3] = local_130[5] * local_130[0xb] + local_130[3];
          local_130[1] = local_130[5] * local_130[9] + local_130[1];
          local_130[2] = local_130[5] * local_130[10] + local_130[2];
          ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                     piVar15[0x12],piVar15[0x13]);
          local_130[0] = local_130[6] * local_130[8] + local_130[0];
          local_130[3] = local_130[6] * local_130[0xb] + local_130[3];
          local_130[1] = local_130[6] * local_130[9] + local_130[1];
          local_130[2] = local_130[6] * local_130[10] + local_130[2];
          ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                     piVar15[0x12],piVar15[0x13]);
          local_130[0] = local_130[7] * local_130[8] + local_130[0];
          local_130[3] = local_130[7] * local_130[0xb] + local_130[3];
          local_130[1] = local_130[7] * local_130[9] + local_130[1];
          local_130[2] = local_130[7] * local_130[10] + local_130[2];
        }
      }
      iVar20 = piVar15[9];
      iVar22 = piVar15[3];
      iVar18 = piVar15[4];
      iVar24 = piVar15[5];
      iVar27 = piVar15[6];
      iVar17 = piVar15[7];
      iVar19 = piVar15[8];
    }
    else if (uVar23 == 2) {
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                 piVar15[0x1b],piVar15[0x1c]);
      local_f0 = local_130[4] * local_130[8];
      local_ec = local_130[5] * local_130[8];
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      local_f0 = local_130[4] * local_130[9] + local_f0;
      local_ec = local_130[5] * local_130[9] + local_ec;
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                 piVar15[0x1b],piVar15[0x1c]);
      local_e0 = local_130[4] * local_130[9];
      local_dc = local_130[5] * local_130[9];
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      local_e0 = local_130[4] * local_130[8] + local_e0;
      local_dc = local_130[5] * local_130[8] + local_dc;
      ((int (*)())_InterpreterWriteDestination)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],piVar15[7],piVar15[8],
                 piVar15[9]);
      iVar20 = piVar15[9];
      iVar22 = piVar15[3];
      iVar18 = piVar15[4];
      iVar24 = piVar15[5];
      iVar27 = piVar15[6];
      iVar17 = piVar15[7];
      iVar19 = piVar15[8];
    }
    else if (uVar23 == 3) {
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                 piVar15[0x1b],piVar15[0x1c]);
      local_f0 = local_130[4] * local_130[8];
      local_e8 = local_130[6] * local_130[8];
      local_ec = local_130[5] * local_130[8];
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      local_f0 = local_130[4] * local_130[9] + local_f0;
      local_e8 = local_130[6] * local_130[9] + local_e8;
      local_ec = local_130[5] * local_130[9] + local_ec;
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      local_f0 = local_130[4] * local_130[10] + local_f0;
      local_e8 = local_130[6] * local_130[10] + local_e8;
      local_ec = local_130[5] * local_130[10] + local_ec;
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                 piVar15[0x1b],piVar15[0x1c]);
      local_e0 = local_130[4] * local_130[10];
      local_d8 = local_130[6] * local_130[10];
      local_dc = local_130[5] * local_130[10];
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      local_e0 = local_130[4] * local_130[9] + local_e0;
      local_d8 = local_130[6] * local_130[9] + local_d8;
      local_dc = local_130[5] * local_130[9] + local_dc;
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      local_e0 = local_130[4] * local_130[8] + local_e0;
      local_d8 = local_130[6] * local_130[8] + local_d8;
      local_dc = local_130[5] * local_130[8] + local_dc;
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                 piVar15[0x1b],piVar15[0x1c]);
      local_d0 = local_130[4] * local_130[8];
      local_c8 = local_130[6] * local_130[8];
      local_cc = local_130[5] * local_130[8];
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      local_d0 = local_130[4] * local_130[9] + local_d0;
      local_c8 = local_130[6] * local_130[9] + local_c8;
      local_cc = local_130[5] * local_130[9] + local_cc;
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      local_d0 = local_130[4] * local_130[10] + local_d0;
      local_c8 = local_130[6] * local_130[10] + local_c8;
      local_cc = local_130[5] * local_130[10] + local_cc;
      ((int (*)())_InterpreterWriteDestination)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],piVar15[7],piVar15[8],
                 piVar15[9]);
      ((int (*)())_InterpreterWriteDestination)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],piVar15[7],piVar15[8],
                 piVar15[9]);
      iVar20 = piVar15[9];
      iVar22 = piVar15[3];
      iVar18 = piVar15[4];
      iVar24 = piVar15[5];
      iVar27 = piVar15[6];
      iVar17 = piVar15[7];
      iVar19 = piVar15[8];
    }
    else {
      if (uVar23 != 4) {
        return piVar21;
      }
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                 piVar15[0x1b],piVar15[0x1c]);
      local_f0 = local_130[4] * local_130[8];
      local_e4 = local_130[7] * local_130[8];
      local_ec = local_130[5] * local_130[8];
      local_e8 = local_130[6] * local_130[8];
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      local_f0 = local_130[4] * local_130[9] + local_f0;
      local_e4 = local_130[7] * local_130[9] + local_e4;
      local_ec = local_130[5] * local_130[9] + local_ec;
      local_e8 = local_130[6] * local_130[9] + local_e8;
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      local_f0 = local_130[4] * local_130[10] + local_f0;
      local_e4 = local_130[7] * local_130[10] + local_e4;
      local_ec = local_130[5] * local_130[10] + local_ec;
      local_e8 = local_130[6] * local_130[10] + local_e8;
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      local_f0 = local_130[4] * local_130[0xb] + local_f0;
      local_e4 = local_130[7] * local_130[0xb] + local_e4;
      local_ec = local_130[5] * local_130[0xb] + local_ec;
      local_e8 = local_130[6] * local_130[0xb] + local_e8;
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                 piVar15[0x1b],piVar15[0x1c]);
      local_e0 = local_130[4] * local_130[0xb];
      local_d4 = local_130[7] * local_130[0xb];
      local_dc = local_130[5] * local_130[0xb];
      local_d8 = local_130[6] * local_130[0xb];
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      local_e0 = local_130[4] * local_130[10] + local_e0;
      local_d4 = local_130[7] * local_130[10] + local_d4;
      local_dc = local_130[5] * local_130[10] + local_dc;
      local_d8 = local_130[6] * local_130[10] + local_d8;
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      local_e0 = local_130[4] * local_130[9] + local_e0;
      local_d4 = local_130[7] * local_130[9] + local_d4;
      local_dc = local_130[5] * local_130[9] + local_dc;
      local_d8 = local_130[6] * local_130[9] + local_d8;
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      local_e0 = local_130[4] * local_130[8] + local_e0;
      local_d4 = local_130[7] * local_130[8] + local_d4;
      local_dc = local_130[5] * local_130[8] + local_dc;
      local_d8 = local_130[6] * local_130[8] + local_d8;
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                 piVar15[0x1b],piVar15[0x1c]);
      local_d0 = local_130[4] * local_130[8];
      local_c4 = local_130[7] * local_130[8];
      local_cc = local_130[5] * local_130[8];
      local_c8 = local_130[6] * local_130[8];
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      local_d0 = local_130[4] * local_130[9] + local_d0;
      local_c4 = local_130[7] * local_130[9] + local_c4;
      local_cc = local_130[5] * local_130[9] + local_cc;
      local_c8 = local_130[6] * local_130[9] + local_c8;
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      local_d0 = local_130[4] * local_130[10] + local_d0;
      local_c4 = local_130[7] * local_130[10] + local_c4;
      local_cc = local_130[5] * local_130[10] + local_cc;
      local_c8 = local_130[6] * local_130[10] + local_c8;
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      local_d0 = local_130[4] * local_130[0xb] + local_d0;
      local_c4 = local_130[7] * local_130[0xb] + local_c4;
      local_cc = local_130[5] * local_130[0xb] + local_cc;
      local_c8 = local_130[6] * local_130[0xb] + local_c8;
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                 piVar15[0x1b],piVar15[0x1c]);
      local_c0 = local_130[4] * local_130[0xb];
      local_b4 = local_130[7] * local_130[0xb];
      local_bc = local_130[5] * local_130[0xb];
      local_b8 = local_130[6] * local_130[0xb];
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      local_c0 = local_130[4] * local_130[10] + local_c0;
      local_b4 = local_130[7] * local_130[10] + local_b4;
      local_bc = local_130[5] * local_130[10] + local_bc;
      local_b8 = local_130[6] * local_130[10] + local_b8;
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      local_c0 = local_130[4] * local_130[9] + local_c0;
      local_b4 = local_130[7] * local_130[9] + local_b4;
      local_bc = local_130[5] * local_130[9] + local_bc;
      local_b8 = local_130[6] * local_130[9] + local_b8;
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      local_c0 = local_130[4] * local_130[8] + local_c0;
      local_b4 = local_130[7] * local_130[8] + local_b4;
      local_bc = local_130[5] * local_130[8] + local_bc;
      local_b8 = local_130[6] * local_130[8] + local_b8;
      ((int (*)())_InterpreterWriteDestination)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],piVar15[7],piVar15[8],
                 piVar15[9]);
      ((int (*)())_InterpreterWriteDestination)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],piVar15[7],piVar15[8],
                 piVar15[9]);
      ((int (*)())_InterpreterWriteDestination)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],piVar15[7],piVar15[8],
                 piVar15[9]);
      iVar20 = piVar15[9];
      iVar22 = piVar15[3];
      iVar18 = piVar15[4];
      iVar24 = piVar15[5];
      iVar27 = piVar15[6];
      iVar17 = piVar15[7];
      iVar19 = piVar15[8];
    }
    goto LAB_97bd043c;
  }
  if ((iVar24 != 0x31) && (iVar24 != 0x36)) {
    uVar25 = 0;
    if (uVar23 == 0) {
      return piVar21;
    }
    do {
      if (((iVar18 != 0) &&
          (((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                      piVar15[0x12],piVar15[0x13]), 1 < (uint)piVar15[0xc])) &&
         (((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                     piVar15[0x1b],piVar15[0x1c]), 2 < (uint)piVar15[0xc])) {
        ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x1f],piVar15[0x20],piVar15[0x21],piVar15[0x22],piVar15[0x23],
                   piVar15[0x24],piVar15[0x25]);
      }
      fVar4 = TAllocation__guardBlockSize;
      dVar28 = DOUBLE_97c30a60;
      fVar8 = local_130[7];
      switch(iVar24) {
      case 0:
switchD_97bd0598_caseD_0:
        local_130[0] = local_130[4];
        local_130[1] = local_130[5];
        local_130[2] = local_130[6];
        local_130[3] = local_130[7];
        break;
      case 1:
        local_130[0] = 1.0;
        if (local_130[4] <= TAllocation__guardBlockSize) {
          local_130[1] = 0.0;
          local_130[2] = TAllocation__guardBlockSize;
        }
        else {
          local_70 = local_130[4];
          local_130[1] = local_130[4];
          dVar28 = (double)_pow((double)local_130[5],(double)local_130[7]);
          local_130[2] = (float)dVar28;
        }
        goto LAB_97bd1cd8;
      case 2:
        local_130[0] = ABS(local_130[4]);
        local_130[1] = ABS(local_130[5]);
        local_130[2] = ABS(local_130[6]);
        local_130[3] = ABS(local_130[7]);
        break;
      case 3:
        dVar28 = (double)_ceil((double)local_130[4]);
        local_130[0] = (float)dVar28;
        dVar28 = (double)_ceil((double)local_130[5]);
        local_130[1] = (float)dVar28;
        dVar28 = (double)_ceil((double)local_130[6]);
        local_130[2] = (float)dVar28;
        dVar28 = (double)_ceil((double)local_130[7]);
        goto LAB_97bd2010;
      case 4:
        dVar30 = (double)local_130[4];
        dVar28 = (double)_floor(dVar30);
        dVar29 = (double)local_130[5];
        local_130[0] = (float)(dVar30 - dVar28);
        dVar28 = (double)_floor(dVar29);
        dVar30 = (double)local_130[6];
        local_130[1] = (float)(dVar29 - dVar28);
        dVar29 = (double)_floor(dVar30);
        dVar28 = (double)local_130[7];
        local_130[2] = (float)(dVar30 - dVar29);
        dVar29 = (double)_floor(dVar28);
        dVar28 = dVar28 - dVar29;
        goto LAB_97bd1440;
      case 5:
        dVar28 = (double)_floor((double)local_130[4]);
        local_130[0] = (float)dVar28;
        dVar28 = (double)_floor((double)local_130[5]);
        local_130[1] = (float)dVar28;
        dVar28 = (double)_floor((double)local_130[6]);
        local_130[2] = (float)dVar28;
        dVar28 = (double)_floor((double)local_130[7]);
        goto LAB_97bd2010;
      default:
        goto switchD_97bd0598_caseD_6;
      case 7:
        if (local_130[4] <= TAllocation__guardBlockSize) {
          if (TAllocation__guardBlockSize <= local_130[4]) {
            local_130[0] = 0.0;
          }
          else {
            local_130[0] = -1.0;
          }
        }
        else {
          local_130[0] = 1.0;
        }
        if (local_130[5] <= TAllocation__guardBlockSize) {
          if (TAllocation__guardBlockSize <= local_130[5]) {
            local_130[1] = 0.0;
          }
          else {
            local_130[1] = -1.0;
          }
        }
        else {
          local_130[1] = 1.0;
        }
        if (local_130[6] <= TAllocation__guardBlockSize) {
          if (TAllocation__guardBlockSize <= local_130[6]) {
            local_130[2] = 0.0;
          }
          else {
            local_130[2] = -1.0;
          }
        }
        else {
          local_130[2] = 1.0;
        }
        if (TAllocation__guardBlockSize < local_130[7]) goto LAB_97bd1cd8;
        if (TAllocation__guardBlockSize <= local_130[7]) goto LAB_97bd1ce0;
        local_130[3] = -1.0;
        break;
      case 8:
        if (((local_130[4] == TAllocation__guardBlockSize) &&
            (local_130[5] == TAllocation__guardBlockSize)) &&
           (local_130[6] == TAllocation__guardBlockSize)) {
LAB_97bd0ab8:
          uVar9 = 0;
          if (local_130[7] == TAllocation__guardBlockSize) goto LAB_97bd0ac8;
        }
        uVar9 = 1;
        goto LAB_97bd0ac8;
      case 9:
        uVar9 = 0;
        if (((local_130[4] != TAllocation__guardBlockSize) &&
            (local_130[5] != TAllocation__guardBlockSize)) &&
           (local_130[6] != TAllocation__guardBlockSize)) goto LAB_97bd0ab8;
LAB_97bd0ac8:
        uStack_ac = uVar9 ^ 0x80000000;
        local_b0 = 0x43300000;
        dVar28 = (double)CONCAT44(0x43300000,uVar9 ^ 0x80000000) - DOUBLE_97c30a58;
LAB_97bd0cc8:
        local_130[0] = (float)dVar28;
        local_130[1] = local_130[0];
        local_130[2] = local_130[0];
        local_130[3] = local_130[0];
        break;
      case 10:
        local_130[0] = 1.0;
        if (local_130[4] != TAllocation__guardBlockSize) {
          local_130[0] = 0.0;
        }
        local_130[1] = 1.0;
        if (local_130[5] != TAllocation__guardBlockSize) {
          local_130[1] = 0.0;
        }
        local_130[2] = 1.0;
        if (local_130[6] != TAllocation__guardBlockSize) {
          local_130[2] = 0.0;
        }
        local_130[3] = 1.0;
        if (local_130[7] != TAllocation__guardBlockSize) goto LAB_97bd1ce0;
        break;
      case 0xb:
        bVar6 = *(byte *)((int)piVar15 + 5);
        if (bVar6 == 2) {
          ((int (*)())_InterpreterNoiseGeneratorCalculate2D)(piVar14 + 1,local_130 + 4,local_130);
        }
        else if (bVar6 < 3) {
          if (bVar6 == 1) {
            ((int (*)())_InterpreterNoiseGeneratorCalculate1D)(piVar14 + 1,local_130 + 4,local_130);
          }
        }
        else if (bVar6 == 3) {
          ((int (*)())_InterpreterNoiseGeneratorCalculate3D)(piVar14 + 1,local_130 + 4,local_130);
        }
        else if (bVar6 == 4) {
          _InterpreterNoiseGeneratorCalculate4D(piVar14 + 1,local_130 + 4,local_130);
        }
        break;
      case 0xc:
        dVar28 = (double)_sqrt(ABS((double)local_130[4]));
        local_130[0] = (float)dVar28;
        dVar28 = (double)_sqrt(ABS((double)local_130[5]));
        local_130[1] = (float)dVar28;
        dVar28 = (double)_sqrt(ABS((double)local_130[6]));
        local_130[2] = (float)dVar28;
        dVar28 = (double)_sqrt(ABS((double)local_130[7]));
        goto LAB_97bd2010;
      case 0xd:
        if (*(int *)(*(int *)(iVar22 + 0xd80) + 0x38) - 0x8b30U < 2) {
          dVar29 = (double)_sqrt(ABS((double)local_130[4]));
          local_130[0] = (float)(dVar28 / dVar29);
          dVar29 = (double)_sqrt(ABS((double)local_130[5]));
          local_130[1] = (float)(dVar28 / dVar29);
          dVar29 = (double)_sqrt(ABS((double)local_130[6]));
          local_130[2] = (float)(dVar28 / dVar29);
          dVar29 = (double)_sqrt(ABS((double)local_130[7]));
          dVar28 = dVar28 / dVar29;
          goto LAB_97bd1440;
        }
        dVar28 = (double)_sqrt(ABS((double)local_130[7]));
        dVar28 = DOUBLE_97c30a60 / dVar28;
        goto LAB_97bd0cc8;
      case 0xe:
        local_130[0] = FLOAT_97c3acd8 / local_130[7];
        local_130[1] = local_130[0];
        local_130[2] = local_130[0];
        local_130[3] = local_130[0];
        break;
      case 0xf:
        local_130[0] = FLOAT_97c3ace0;
        local_130[1] = FLOAT_97c3ace0;
        local_130[2] = FLOAT_97c3ace0;
        local_130[3] = FLOAT_97c3ace0;
        if ((local_130[7] <= FLOAT_97c3acdc) &&
           ((FLOAT_97c3ace0 <= local_130[7] ||
            (((local_130[0] = FLOAT_97c3acdc, local_130[1] = FLOAT_97c3acdc,
              local_130[2] = FLOAT_97c3acdc, local_130[3] = FLOAT_97c3acdc,
              local_130[7] < TAllocation__guardBlockSize &&
              (local_130[0] = FLOAT_97c3ace8, local_130[1] = FLOAT_97c3ace8,
              local_130[2] = FLOAT_97c3ace8, local_130[3] = FLOAT_97c3ace8,
              local_130[7] <= FLOAT_97c3ace4)) &&
             (local_130[0] = FLOAT_97c3ace4, local_130[1] = FLOAT_97c3ace4,
             local_130[2] = FLOAT_97c3ace4, local_130[3] = FLOAT_97c3ace4,
             FLOAT_97c3ace8 <= local_130[7])))))) {
          local_130[0] = FLOAT_97c3acd8 / local_130[7];
          local_130[1] = local_130[0];
          local_130[2] = local_130[0];
          local_130[3] = local_130[0];
        }
        break;
      case 0x10:
        if (1 < *(int *)(*(int *)(iVar22 + 0xd80) + 0x38) - 0x8b30U) {
          dVar28 = (double)_exp2((double)local_130[7]);
          goto LAB_97bd1d68;
        }
        dVar28 = (double)_exp2((double)local_130[4]);
        local_130[0] = (float)dVar28;
        dVar28 = (double)_exp2((double)local_130[5]);
        local_130[1] = (float)dVar28;
        dVar28 = (double)_exp2((double)local_130[6]);
        local_130[2] = (float)dVar28;
        dVar28 = (double)_exp2((double)local_130[7]);
        goto LAB_97bd2010;
      case 0x11:
        dVar28 = (double)_floor((double)local_130[7]);
        dVar29 = (double)_exp2((double)(float)dVar28);
        local_130[0] = (float)dVar29;
        local_130[1] = (float)((double)local_130[7] - (double)(float)dVar28);
        dVar28 = (double)_exp2((double)local_130[7]);
        goto LAB_97bd0fd4;
      case 0x12:
        uVar9 = (uint)*(byte *)((int)piVar15 + 5);
        dVar28 = (double)TAllocation__guardBlockSize;
        if (uVar9 != 0) {
          pfVar12 = local_130 + 4;
          do {
            fVar4 = *pfVar12;
            pfVar12 = pfVar12 + 1;
            dVar28 = (double)(float)((double)fVar4 * (double)fVar4 + dVar28);
            uVar9 = uVar9 - 1;
          } while (uVar9 != 0);
        }
LAB_97bd1924:
        dVar28 = (double)_sqrt(dVar28);
LAB_97bd1d68:
        local_130[0] = (float)dVar28;
        local_130[1] = local_130[0];
        local_130[2] = local_130[0];
        local_130[3] = local_130[0];
        break;
      case 0x13:
        if (1 < *(int *)(*(int *)(iVar22 + 0xd80) + 0x38) - 0x8b30U) {
          dVar28 = (double)local_130[7];
          if ((double)local_130[7] < (double)TAllocation__guardBlockSize) {
            dVar28 = DOUBLE_97c30a48;
          }
          dVar28 = (double)_log2(dVar28);
          goto LAB_97bd1d68;
        }
        dVar28 = (double)local_130[4];
        if ((double)local_130[4] < (double)TAllocation__guardBlockSize) {
          dVar28 = DOUBLE_97c30a48;
        }
        dVar29 = (double)_log2(dVar28);
        dVar28 = (double)local_130[5];
        local_130[0] = (float)dVar29;
        if (dVar28 < (double)TAllocation__guardBlockSize) {
          dVar28 = DOUBLE_97c30a48;
        }
        dVar29 = (double)_log2(dVar28);
        dVar28 = (double)local_130[6];
        local_130[1] = (float)dVar29;
        if (dVar28 < (double)TAllocation__guardBlockSize) {
          dVar28 = DOUBLE_97c30a48;
        }
        dVar29 = (double)_log2(dVar28);
        dVar28 = (double)local_130[7];
        local_130[2] = (float)dVar29;
        if (dVar28 < (double)TAllocation__guardBlockSize) {
          dVar28 = DOUBLE_97c30a48;
        }
        dVar28 = (double)_log2(dVar28);
        goto LAB_97bd2010;
      case 0x14:
        dVar28 = ABS((double)local_130[7]);
        _log2(dVar28);
        dVar29 = (double)_floor();
        local_130[0] = (float)dVar29;
        dVar29 = (double)_exp2((double)local_130[0]);
        local_130[1] = (float)(dVar28 / dVar29);
        if (dVar28 < (double)TAllocation__guardBlockSize) {
          dVar28 = DOUBLE_97c30a48;
        }
        dVar28 = (double)_log2(dVar28);
LAB_97bd0fd4:
        local_130[2] = (float)dVar28;
        local_130[3] = 1.0;
        break;
      case 0x15:
        uVar9 = (uint)*(byte *)((int)piVar15 + 5);
        dVar28 = (double)TAllocation__guardBlockSize;
        if (uVar9 != 0) {
          pfVar12 = local_130 + 4;
          do {
            fVar4 = *pfVar12;
            pfVar12 = pfVar12 + 1;
            dVar28 = (double)(float)((double)fVar4 * (double)fVar4 + dVar28);
            uVar9 = uVar9 - 1;
          } while (uVar9 != 0);
        }
        dVar28 = (double)_sqrt(dVar28);
        uVar9 = (uint)*(byte *)((int)piVar15 + 5);
        if (uVar9 != 0) {
          pfVar12 = local_130;
          do {
            *pfVar12 = pfVar12[4] / (float)dVar28;
            pfVar12 = pfVar12 + 1;
            uVar9 = uVar9 - 1;
          } while (uVar9 != 0);
        }
        break;
      case 0x16:
        fVar4 = FLOAT_97c3acd0;
        goto LAB_97bd109c;
      case 0x17:
        fVar4 = FLOAT_97c3acd4;
LAB_97bd109c:
        local_130[0] = local_130[4] * fVar4;
        local_130[1] = local_130[5] * fVar4;
        local_130[2] = local_130[6] * fVar4;
        local_130[3] = local_130[7] * fVar4;
        break;
      case 0x18:
        dVar28 = (double)_cos((double)local_130[4]);
        local_130[0] = (float)dVar28;
        dVar28 = (double)_sin((double)local_130[4]);
        local_130[1] = (float)dVar28;
        local_130[3] = 0.0;
        local_130[2] = 0.0;
        break;
      case 0x19:
        if (1 < *(int *)(*(int *)(iVar22 + 0xd80) + 0x38) - 0x8b30U) {
          dVar28 = (double)_sin((double)local_130[7]);
          goto LAB_97bd1d68;
        }
        dVar28 = (double)_sin((double)local_130[4]);
        local_130[0] = (float)dVar28;
        dVar28 = (double)_sin((double)local_130[5]);
        local_130[1] = (float)dVar28;
        dVar28 = (double)_sin((double)local_130[6]);
        local_130[2] = (float)dVar28;
        dVar28 = (double)_sin((double)local_130[7]);
        goto LAB_97bd2010;
      case 0x1a:
        if (1 < *(int *)(*(int *)(iVar22 + 0xd80) + 0x38) - 0x8b30U) {
          dVar28 = (double)_cos((double)local_130[7]);
          goto LAB_97bd1d68;
        }
        dVar28 = (double)_cos((double)local_130[4]);
        local_130[0] = (float)dVar28;
        dVar28 = (double)_cos((double)local_130[5]);
        local_130[1] = (float)dVar28;
        dVar28 = (double)_cos((double)local_130[6]);
        local_130[2] = (float)dVar28;
        dVar28 = (double)_cos((double)local_130[7]);
        goto LAB_97bd2010;
      case 0x1b:
        dVar28 = (double)_tan((double)local_130[4]);
        local_130[0] = (float)dVar28;
        dVar28 = (double)_tan((double)local_130[5]);
        local_130[1] = (float)dVar28;
        dVar28 = (double)_tan((double)local_130[6]);
        local_130[2] = (float)dVar28;
        dVar28 = (double)_tan((double)local_130[7]);
        goto LAB_97bd2010;
      case 0x1c:
        dVar28 = (double)_asin((double)local_130[4]);
        local_130[0] = (float)dVar28;
        dVar28 = (double)_asin((double)local_130[5]);
        local_130[1] = (float)dVar28;
        dVar28 = (double)_asin((double)local_130[6]);
        local_130[2] = (float)dVar28;
        dVar28 = (double)_asin((double)local_130[7]);
        goto LAB_97bd2010;
      case 0x1d:
        dVar28 = (double)_acos((double)local_130[4]);
        local_130[0] = (float)dVar28;
        dVar28 = (double)_acos((double)local_130[5]);
        local_130[1] = (float)dVar28;
        dVar28 = (double)_acos((double)local_130[6]);
        local_130[2] = (float)dVar28;
        dVar28 = (double)_acos((double)local_130[7]);
        goto LAB_97bd2010;
      case 0x1e:
        if (piVar15[0xc] == 1) {
          dVar28 = (double)_atan((double)local_130[4]);
          local_130[0] = (float)dVar28;
          dVar28 = (double)_atan((double)local_130[5]);
          local_130[1] = (float)dVar28;
          dVar28 = (double)_atan((double)local_130[6]);
          local_130[2] = (float)dVar28;
          dVar28 = (double)_atan((double)local_130[7]);
          goto LAB_97bd2010;
        }
        dVar28 = (double)_atan2f((double)local_130[4],(double)local_130[8]);
        local_130[0] = (float)dVar28;
        dVar28 = (double)_atan2f((double)local_130[5],(double)local_130[9]);
        local_130[1] = (float)dVar28;
        dVar28 = (double)_atan2f((double)local_130[6],(double)local_130[10]);
        local_130[2] = (float)dVar28;
        dVar28 = (double)_atan2f((double)local_130[7],(double)local_130[0xb]);
        goto LAB_97bd2014;
      case 0x1f:
        local_130[0] = local_130[4] + local_130[8];
        local_130[1] = local_130[5] + local_130[9];
        local_130[2] = local_130[6] + local_130[10];
        local_130[3] = local_130[7] + local_130[0xb];
        break;
      case 0x20:
        local_130[0] = local_130[4] - local_130[8];
        local_130[1] = local_130[5] - local_130[9];
        local_130[2] = local_130[6] - local_130[10];
        local_130[3] = local_130[7] - local_130[0xb];
        break;
      case 0x21:
        if (*(char *)((int)piVar15 + 0x6d) == '\x01') {
          dVar28 = (double)local_130[4];
          dVar32 = (double)local_130[8];
          dVar29 = (double)_floor((double)(float)(dVar28 / dVar32));
          dVar30 = (double)local_130[5];
          dVar31 = (double)local_130[8];
          local_130[0] = (float)-(dVar32 * dVar29 - dVar28);
          dVar28 = (double)_floor((double)(float)(dVar30 / dVar31));
          dVar29 = (double)local_130[6];
          dVar32 = (double)local_130[8];
          local_130[1] = (float)-(dVar31 * dVar28 - dVar30);
          dVar28 = (double)_floor((double)(float)(dVar29 / dVar32));
          fVar4 = local_130[8];
        }
        else {
          dVar28 = (double)local_130[4];
          dVar32 = (double)local_130[8];
          dVar29 = (double)_floor((double)(float)(dVar28 / dVar32));
          dVar30 = (double)local_130[5];
          dVar31 = (double)local_130[9];
          local_130[0] = (float)-(dVar32 * dVar29 - dVar28);
          dVar28 = (double)_floor((double)(float)(dVar30 / dVar31));
          dVar29 = (double)local_130[6];
          dVar32 = (double)local_130[10];
          local_130[1] = (float)-(dVar31 * dVar28 - dVar30);
          dVar28 = (double)_floor((double)(float)(dVar29 / dVar32));
          fVar4 = local_130[0xb];
        }
        dVar30 = (double)local_130[7];
        local_130[2] = (float)-(dVar32 * dVar28 - dVar29);
        dVar28 = (double)_floor((double)(float)(dVar30 / (double)fVar4));
        dVar28 = -((double)fVar4 * dVar28 - dVar30);
LAB_97bd1440:
        local_130[3] = (float)dVar28;
        break;
      case 0x22:
      case 0x31:
      case 0x36:
        break;
      case 0x23:
        local_130[0] = local_130[4] * local_130[8];
        local_130[1] = local_130[5] * local_130[9];
        local_130[2] = local_130[6] * local_130[10];
        local_130[3] = local_130[7] * local_130[0xb];
        break;
      case 0x24:
        uVar9 = 0;
        if ((local_130[4] != TAllocation__guardBlockSize) &&
           (local_130[8] != TAllocation__guardBlockSize)) {
          uVar9 = 1;
        }
        uVar10 = 0;
        local_130[0] = (float)((double)CONCAT44(0x43300000,uVar9 ^ 0x80000000) - DOUBLE_97c30a58);
        if ((local_130[5] != TAllocation__guardBlockSize) &&
           (local_130[9] != TAllocation__guardBlockSize)) {
          uVar10 = 1;
        }
        uVar9 = 0;
        local_130[1] = (float)((double)CONCAT44(0x43300000,uVar10 ^ 0x80000000) - DOUBLE_97c30a58);
        if ((local_130[6] != TAllocation__guardBlockSize) &&
           (local_130[10] != TAllocation__guardBlockSize)) {
          uVar9 = 1;
        }
        uVar10 = 0;
        local_130[2] = (float)((double)CONCAT44(0x43300000,uVar9 ^ 0x80000000) - DOUBLE_97c30a58);
        if (local_130[7] != TAllocation__guardBlockSize) {
LAB_97bd17d0:
          uVar10 = 0;
          if (local_130[0xb] != TAllocation__guardBlockSize) goto LAB_97bd17ec;
        }
        goto LAB_97bd17f0;
      case 0x25:
        uVar9 = 0;
        if ((local_130[4] != TAllocation__guardBlockSize) ||
           (local_130[8] != TAllocation__guardBlockSize)) {
          uVar9 = 1;
        }
        uVar10 = 0;
        local_130[0] = (float)((double)CONCAT44(0x43300000,uVar9 ^ 0x80000000) - DOUBLE_97c30a58);
        if ((local_130[5] != TAllocation__guardBlockSize) ||
           (local_130[9] != TAllocation__guardBlockSize)) {
          uVar10 = 1;
        }
        uVar9 = 0;
        local_130[1] = (float)((double)CONCAT44(0x43300000,uVar10 ^ 0x80000000) - DOUBLE_97c30a58);
        if ((local_130[6] != TAllocation__guardBlockSize) ||
           (local_130[10] != TAllocation__guardBlockSize)) {
          uVar9 = 1;
        }
        local_130[2] = (float)((double)CONCAT44(0x43300000,uVar9 ^ 0x80000000) - DOUBLE_97c30a58);
        if (local_130[7] == TAllocation__guardBlockSize) goto LAB_97bd17d0;
LAB_97bd17ec:
        uVar10 = 1;
        goto LAB_97bd17f0;
      case 0x26:
        uVar9 = 0;
        if (local_130[4] == TAllocation__guardBlockSize) {
          if (local_130[8] != TAllocation__guardBlockSize) {
LAB_97bd16cc:
            uVar9 = 1;
          }
        }
        else if (local_130[8] == TAllocation__guardBlockSize) goto LAB_97bd16cc;
        uVar10 = 0;
        local_130[0] = (float)((double)CONCAT44(0x43300000,uVar9 ^ 0x80000000) - DOUBLE_97c30a58);
        if (local_130[5] == TAllocation__guardBlockSize) {
          if (local_130[9] != TAllocation__guardBlockSize) {
LAB_97bd172c:
            uVar10 = 1;
          }
        }
        else if (local_130[9] == TAllocation__guardBlockSize) goto LAB_97bd172c;
        uVar9 = 0;
        local_130[1] = (float)((double)CONCAT44(0x43300000,uVar10 ^ 0x80000000) - DOUBLE_97c30a58);
        if (local_130[6] == TAllocation__guardBlockSize) {
          if (local_130[10] != TAllocation__guardBlockSize) {
LAB_97bd178c:
            uVar9 = 1;
          }
        }
        else if (local_130[10] == TAllocation__guardBlockSize) goto LAB_97bd178c;
        uVar10 = 0;
        local_130[2] = (float)((double)CONCAT44(0x43300000,uVar9 ^ 0x80000000) - DOUBLE_97c30a58);
        if (local_130[7] == TAllocation__guardBlockSize) goto LAB_97bd17d0;
        if (local_130[0xb] == TAllocation__guardBlockSize) goto LAB_97bd17ec;
LAB_97bd17f0:
        uStack_ac = uVar10 ^ 0x80000000;
        local_b0 = 0x43300000;
        local_130[3] = (float)((double)CONCAT44(0x43300000,uVar10 ^ 0x80000000) - DOUBLE_97c30a58);
        break;
      case 0x27:
        uVar9 = (uint)*(byte *)((int)piVar15 + 5);
        local_130[0] = TAllocation__guardBlockSize;
        local_130[1] = TAllocation__guardBlockSize;
        local_130[2] = TAllocation__guardBlockSize;
        local_130[3] = TAllocation__guardBlockSize;
        if (uVar9 != 0) {
          pfVar12 = local_130;
          do {
            pfVar1 = pfVar12 + 4;
            pfVar2 = pfVar12 + 8;
            pfVar12 = pfVar12 + 1;
            local_130[0] = *pfVar1 * *pfVar2 + local_130[0];
            uVar9 = uVar9 - 1;
            local_130[1] = local_130[0];
            local_130[2] = local_130[0];
            local_130[3] = local_130[0];
          } while (uVar9 != 0);
        }
        break;
      case 0x28:
        local_130[0] = local_130[6] * local_130[10] +
                       local_130[4] * local_130[8] + local_130[5] * local_130[9];
        local_130[1] = local_130[0];
        local_130[2] = local_130[0];
        local_130[3] = local_130[0];
        break;
      case 0x29:
        local_130[0] = local_130[7] * local_130[0xb] +
                       local_130[6] * local_130[10] +
                       local_130[4] * local_130[8] + local_130[5] * local_130[9];
        local_130[1] = local_130[0];
        local_130[2] = local_130[0];
        local_130[3] = local_130[0];
        break;
      case 0x2a:
        local_130[0] = local_130[6] * local_130[10] +
                       local_130[4] * local_130[8] + local_130[5] * local_130[9] + local_130[0xb];
        local_130[1] = local_130[0];
        local_130[2] = local_130[0];
        local_130[3] = local_130[0];
        break;
      case 0x2b:
        if (*(int *)(*(int *)(iVar22 + 0xd80) + 0x38) - 0x8b30U < 2) {
          uVar9 = (uint)*(byte *)((int)piVar15 + 5);
          dVar28 = (double)TAllocation__guardBlockSize;
          if (uVar9 != 0) {
            pfVar12 = local_130;
            do {
              pfVar1 = pfVar12 + 4;
              pfVar2 = pfVar12 + 8;
              pfVar12 = pfVar12 + 1;
              dVar28 = (double)(float)((double)(*pfVar1 - *pfVar2) * (double)(*pfVar1 - *pfVar2) +
                                      dVar28);
              uVar9 = uVar9 - 1;
            } while (uVar9 != 0);
          }
          goto LAB_97bd1924;
        }
        local_130[0] = 1.0;
        local_130[1] = local_130[5] * local_130[9];
        local_130[2] = local_130[6];
        local_130[3] = local_130[0xb];
        break;
      case 0x2c:
        local_130[0] = local_130[8];
        if (local_130[4] < local_130[8]) {
          local_130[0] = local_130[4];
        }
        local_130[1] = local_130[9];
        if (local_130[5] < local_130[9]) {
          local_130[1] = local_130[5];
        }
        local_130[2] = local_130[10];
        if (local_130[6] < local_130[10]) {
          local_130[2] = local_130[6];
        }
        local_130[3] = local_130[0xb];
        if (local_130[7] < local_130[0xb]) {
LAB_97bd2210:
          local_130[3] = fVar8;
        }
        break;
      case 0x2d:
        local_130[0] = local_130[8];
        if (local_130[8] < local_130[4]) {
          local_130[0] = local_130[4];
        }
        local_130[1] = local_130[9];
        if (local_130[9] < local_130[5]) {
          local_130[1] = local_130[5];
        }
        local_130[2] = local_130[10];
        if (local_130[10] < local_130[6]) {
          local_130[2] = local_130[6];
        }
        local_130[3] = local_130[0xb];
        if (local_130[0xb] < local_130[7]) goto LAB_97bd2210;
        break;
      case 0x2e:
        local_130[0] = local_130[5] * local_130[10] - local_130[9] * local_130[6];
        local_130[2] = local_130[4] * local_130[9] - local_130[8] * local_130[5];
        local_130[1] = local_130[6] * local_130[8] - local_130[10] * local_130[4];
        goto LAB_97bd1ce0;
      case 0x2f:
        uVar9 = (uint)*(byte *)((int)piVar15 + 5);
        if (uVar9 != 0) {
          pfVar12 = local_130;
          do {
            pfVar1 = pfVar12 + 4;
            pfVar2 = pfVar12 + 8;
            pfVar12 = pfVar12 + 1;
            fVar4 = *pfVar1 * *pfVar2 + fVar4;
            uVar9 = uVar9 - 1;
          } while (uVar9 != 0);
        }
        fVar4 = fVar4 + fVar4;
        local_130[0] = -(fVar4 * local_130[8] - local_130[4]);
        local_130[1] = -(fVar4 * local_130[9] - local_130[5]);
        local_130[2] = -(fVar4 * local_130[10] - local_130[6]);
        local_130[3] = -(fVar4 * local_130[0xb] - local_130[7]);
        break;
      case 0x30:
        local_130[0] = FLOAT_97c3acd8;
        local_130[1] = FLOAT_97c3acd8;
        local_130[2] = FLOAT_97c3acd8;
        local_130[3] = FLOAT_97c3acd8;
        break;
      case 0x32:
        local_130[0] = 1.0;
        if (local_130[4] < local_130[8]) {
          local_130[0] = 0.0;
        }
        local_130[1] = 1.0;
        if (local_130[5] < local_130[9]) {
          local_130[1] = 0.0;
        }
        local_130[2] = 1.0;
        if (local_130[6] < local_130[10]) {
          local_130[2] = 0.0;
        }
        bVar3 = local_130[0xb] <= local_130[7];
        goto LAB_97bd1c60;
      case 0x33:
        if (local_130[4] <= local_130[8]) {
          local_130[0] = 0.0;
        }
        else {
          local_130[0] = 1.0;
        }
        if (local_130[5] <= local_130[9]) {
          local_130[1] = 0.0;
        }
        else {
          local_130[1] = 1.0;
        }
        if (local_130[6] <= local_130[10]) {
          local_130[2] = 0.0;
        }
        else {
          local_130[2] = 1.0;
        }
        if (local_130[7] <= local_130[0xb]) goto LAB_97bd1ce0;
        goto LAB_97bd1cd8;
      case 0x34:
        local_130[0] = 1.0;
        if (local_130[8] < local_130[4]) {
          local_130[0] = 0.0;
        }
        local_130[1] = 1.0;
        if (local_130[9] < local_130[5]) {
          local_130[1] = 0.0;
        }
        local_130[2] = 1.0;
        if (local_130[10] < local_130[6]) {
          local_130[2] = 0.0;
        }
        bVar3 = local_130[7] <= local_130[0xb];
LAB_97bd1c60:
        local_130[3] = 1.0;
        if (!bVar3) {
LAB_97bd1ce0:
          local_130[3] = 0.0;
        }
        break;
      case 0x35:
        if (local_130[8] <= local_130[4]) {
          local_130[0] = 0.0;
        }
        else {
          local_130[0] = 1.0;
        }
        if (local_130[9] <= local_130[5]) {
          local_130[1] = 0.0;
        }
        else {
          local_130[1] = 1.0;
        }
        if (local_130[10] <= local_130[6]) {
          local_130[2] = 0.0;
        }
        else {
          local_130[2] = 1.0;
        }
        if (local_130[0xb] <= local_130[7]) goto LAB_97bd1ce0;
LAB_97bd1cd8:
        local_130[3] = 1.0;
        break;
      case 0x37:
        local_130[0] = TAllocation__guardBlockSize;
        local_130[1] = TAllocation__guardBlockSize;
        local_130[2] = TAllocation__guardBlockSize;
        local_130[3] = TAllocation__guardBlockSize;
        break;
      case 0x38:
        if (1 < *(int *)(*(int *)(iVar22 + 0xd80) + 0x38) - 0x8b30U) {
          dVar28 = (double)_pow((double)local_130[7],(double)local_130[0xb]);
          goto LAB_97bd1d68;
        }
        dVar28 = (double)_pow((double)local_130[4],(double)local_130[8]);
        local_130[0] = (float)dVar28;
        dVar28 = (double)_pow((double)local_130[5],(double)local_130[9]);
        local_130[1] = (float)dVar28;
        dVar28 = (double)_pow((double)local_130[6],(double)local_130[10]);
        local_130[2] = (float)dVar28;
        dVar28 = (double)_pow((double)local_130[7],(double)local_130[0xb]);
        goto LAB_97bd2010;
      case 0x39:
        dVar28 = (double)local_130[8];
        if (DOUBLE_97c30a78 <= dVar28) {
          iVar18 = (int)(dVar28 - DOUBLE_97c30a78);
          local_a0 = (longlong)iVar18;
        }
        else {
          iVar18 = (int)local_130[8];
          local_a8 = (longlong)iVar18;
        }
        local_130[0] = local_130[iVar18 + 4];
        if (DOUBLE_97c30a78 <= dVar28) {
          iVar18 = (int)(dVar28 - DOUBLE_97c30a78);
          local_a8 = (longlong)iVar18;
        }
        else {
          iVar18 = (int)local_130[8];
          local_a0 = (longlong)iVar18;
        }
        local_130[1] = local_130[iVar18 + 4];
        if (DOUBLE_97c30a78 <= dVar28) {
          iVar18 = (int)(dVar28 - DOUBLE_97c30a78);
          local_a8 = (longlong)iVar18;
        }
        else {
          iVar18 = (int)local_130[8];
          local_a0 = (longlong)iVar18;
        }
        local_130[2] = local_130[iVar18 + 4];
        if (DOUBLE_97c30a78 <= dVar28) {
          iVar18 = (int)(dVar28 - DOUBLE_97c30a78);
          local_a8 = (longlong)iVar18;
        }
        else {
          iVar18 = (int)local_130[8];
          local_a0 = (longlong)iVar18;
        }
        local_130[3] = local_130[iVar18 + 4];
        break;
      case 0x3a:
        if (piVar15[9] == 1) {
          local_130[0] = local_130[4] / local_130[8];
          local_130[1] = local_130[5] / local_130[9];
          local_130[2] = local_130[6] / local_130[10];
          local_130[3] = local_130[7] / local_130[0xb];
        }
        else if (piVar15[9] == 3) {
          dVar28 = (double)_trunc((double)(local_130[4] / local_130[8]));
          local_130[0] = (float)dVar28;
          dVar28 = (double)_trunc((double)(local_130[5] / local_130[9]));
          local_130[1] = (float)dVar28;
          dVar28 = (double)_trunc((double)(local_130[6] / local_130[10]));
          fVar4 = local_130[7] / local_130[0xb];
          goto LAB_97bd200c;
        }
        break;
      case 0x3b:
        uVar9 = (uint)*(byte *)((int)piVar15 + 5);
        if (uVar9 != 0) {
          pfVar12 = local_130;
          do {
            pfVar1 = pfVar12 + 0xc;
            pfVar2 = pfVar12 + 8;
            pfVar12 = pfVar12 + 1;
            fVar4 = *pfVar1 * *pfVar2 + fVar4;
            uVar9 = uVar9 - 1;
          } while (uVar9 != 0);
        }
        if (fVar4 < TAllocation__guardBlockSize) goto switchD_97bd0598_caseD_0;
        local_130[0] = -local_130[4];
        local_130[1] = -local_130[5];
        local_130[2] = -local_130[6];
        local_130[3] = -local_130[7];
        break;
      case 0x3c:
        local_130[0] = local_130[4] * local_130[8] + (FLOAT_97c3acd8 - local_130[4]) * local_100[0];
        local_130[1] = local_130[5] * local_130[9] + (FLOAT_97c3acd8 - local_130[5]) * local_100[1];
        local_130[2] = local_130[6] * local_130[10] + (FLOAT_97c3acd8 - local_130[6]) * local_100[2]
        ;
        local_130[3] = local_130[7] * local_130[0xb] +
                       (FLOAT_97c3acd8 - local_130[7]) * local_100[3];
        break;
      case 0x3d:
        fVar4 = local_130[8];
        if (local_130[8] < local_130[4]) {
          fVar4 = local_130[4];
        }
        local_130[0] = local_100[0];
        if ((fVar4 < local_100[0]) && (local_130[0] = local_130[8], local_130[8] < local_130[4])) {
          local_130[0] = local_130[4];
        }
        fVar4 = local_130[9];
        if (local_130[9] < local_130[5]) {
          fVar4 = local_130[5];
        }
        local_130[1] = local_100[1];
        if ((fVar4 < local_100[1]) && (local_130[1] = local_130[9], local_130[9] < local_130[5])) {
          local_130[1] = local_130[5];
        }
        fVar4 = local_130[10];
        if (local_130[10] < local_130[6]) {
          fVar4 = local_130[6];
        }
        local_130[2] = local_100[2];
        if ((fVar4 < local_100[2]) && (local_130[2] = local_130[10], local_130[10] < local_130[6]))
        {
          local_130[2] = local_130[6];
        }
        fVar4 = local_130[0xb];
        if (local_130[0xb] < local_130[7]) {
          fVar4 = local_130[7];
        }
        local_130[3] = local_100[3];
        if ((fVar4 < local_100[3]) &&
           (fVar8 = local_130[0xb], local_130[3] = local_130[7], local_130[7] <= local_130[0xb]))
        goto LAB_97bd2210;
        break;
      case 0x3e:
        local_130[0] = local_100[0];
        if ((double)local_130[4] < DOUBLE_97c30a48) {
          local_130[0] = local_130[8];
        }
        local_130[1] = local_100[1];
        if ((double)local_130[5] < DOUBLE_97c30a48) {
          local_130[1] = local_130[9];
        }
        local_130[2] = local_100[2];
        if ((double)local_130[6] < DOUBLE_97c30a48) {
          local_130[2] = local_130[10];
        }
        local_130[3] = local_100[3];
        if ((double)local_130[7] < DOUBLE_97c30a48) {
          local_130[3] = local_130[0xb];
        }
        break;
      case 0x3f:
        local_130[0] = local_130[4] * local_130[8] + local_100[0];
        local_130[1] = local_130[5] * local_130[9] + local_100[1];
        local_130[2] = local_130[6] * local_130[10] + local_100[2];
        local_130[3] = local_130[7] * local_130[0xb] + local_100[3];
        break;
      case 0x40:
        dVar28 = (double)((local_100[0] - local_130[4]) / (local_130[8] - local_130[4]));
        if ((dVar28 <= DOUBLE_97c30a48) || (dVar28 < DOUBLE_97c30a60)) {
          if (dVar28 <= DOUBLE_97c30a48) {
            dVar28 = (double)TAllocation__guardBlockSize;
          }
        }
        else {
          dVar28 = (double)FLOAT_97c3acd8;
        }
        dVar29 = (double)((local_100[1] - local_130[5]) / (local_130[9] - local_130[5]));
        local_130[0] = (float)((double)(float)(dVar28 * dVar28) *
                              (DOUBLE_97c30a80 - (dVar28 + dVar28)));
        if ((dVar29 <= DOUBLE_97c30a48) || (dVar29 < DOUBLE_97c30a60)) {
          if (dVar29 <= DOUBLE_97c30a48) {
            dVar29 = (double)TAllocation__guardBlockSize;
          }
        }
        else {
          dVar29 = (double)FLOAT_97c3acd8;
        }
        dVar28 = (double)((local_100[2] - local_130[6]) / (local_130[10] - local_130[6]));
        local_130[1] = (float)((double)(float)(dVar29 * dVar29) *
                              (DOUBLE_97c30a80 - (dVar29 + dVar29)));
        if ((dVar28 <= DOUBLE_97c30a48) || (dVar28 < DOUBLE_97c30a60)) {
          if (dVar28 <= DOUBLE_97c30a48) {
            dVar28 = (double)TAllocation__guardBlockSize;
          }
        }
        else {
          dVar28 = (double)FLOAT_97c3acd8;
        }
        dVar29 = (double)((local_100[3] - local_130[7]) / (local_130[0xb] - local_130[7]));
        local_130[2] = (float)((double)(float)(dVar28 * dVar28) *
                              (DOUBLE_97c30a80 - (dVar28 + dVar28)));
        if ((dVar29 <= DOUBLE_97c30a48) || (dVar29 < DOUBLE_97c30a60)) {
          if (dVar29 <= DOUBLE_97c30a48) {
            dVar29 = (double)TAllocation__guardBlockSize;
          }
        }
        else {
          dVar29 = (double)FLOAT_97c3acd8;
        }
        local_130[3] = (float)((double)(float)(dVar29 * dVar29) *
                              (DOUBLE_97c30a80 - (dVar29 + dVar29)));
        break;
      case 0x41:
        cVar7 = *(char *)(piVar15 + 0x18);
        local_130[0] = local_130[4];
        if ((((cVar7 != '\0') && (local_130[0] = local_130[5], cVar7 != '\x01')) &&
            (local_130[0] = local_130[6], cVar7 != '\x02')) &&
           (local_130[0] = local_130[7], cVar7 != '\x03')) {
          fVar4 = local_130[4];
          if (((cVar7 == '\x04') || (fVar4 = local_130[5], cVar7 == '\x05')) ||
             ((fVar4 = local_130[6], cVar7 == '\x06' || (fVar4 = local_130[7], cVar7 == '\a')))) {
            local_130[0] = -fVar4;
          }
          else {
            local_130[0] = TAllocation__guardBlockSize;
            if (((cVar7 != '\t') && (local_130[0] = FLOAT_97c3acd8, cVar7 != '\b')) &&
               (local_130[0] = FLOAT_97c3acec, cVar7 != '\n')) {
              local_130[0] = TAllocation__guardBlockSize;
            }
          }
        }
        cVar7 = *(char *)((int)piVar15 + 0x61);
        local_130[1] = local_130[4];
        if ((((cVar7 != '\0') && (local_130[1] = local_130[5], cVar7 != '\x01')) &&
            (local_130[1] = local_130[6], cVar7 != '\x02')) &&
           (local_130[1] = local_130[7], cVar7 != '\x03')) {
          fVar4 = local_130[4];
          if (((cVar7 == '\x04') || (fVar4 = local_130[5], cVar7 == '\x05')) ||
             ((fVar4 = local_130[6], cVar7 == '\x06' || (fVar4 = local_130[7], cVar7 == '\a')))) {
            local_130[1] = -fVar4;
          }
          else {
            local_130[1] = TAllocation__guardBlockSize;
            if (((cVar7 != '\t') && (local_130[1] = FLOAT_97c3acd8, cVar7 != '\b')) &&
               (local_130[1] = FLOAT_97c3acec, cVar7 != '\n')) {
              local_130[1] = TAllocation__guardBlockSize;
            }
          }
        }
        cVar7 = *(char *)((int)piVar15 + 0x62);
        local_130[2] = local_130[4];
        if ((((cVar7 != '\0') && (local_130[2] = local_130[5], cVar7 != '\x01')) &&
            (local_130[2] = local_130[6], cVar7 != '\x02')) &&
           (local_130[2] = local_130[7], cVar7 != '\x03')) {
          fVar4 = local_130[4];
          if (((cVar7 == '\x04') || (fVar4 = local_130[5], cVar7 == '\x05')) ||
             ((fVar4 = local_130[6], cVar7 == '\x06' || (fVar4 = local_130[7], cVar7 == '\a')))) {
            local_130[2] = -fVar4;
          }
          else {
            local_130[2] = TAllocation__guardBlockSize;
            if (((cVar7 != '\t') && (local_130[2] = FLOAT_97c3acd8, cVar7 != '\b')) &&
               (local_130[2] = FLOAT_97c3acec, cVar7 != '\n')) {
              local_130[2] = TAllocation__guardBlockSize;
            }
          }
        }
        cVar7 = *(char *)((int)piVar15 + 99);
        local_130[3] = local_130[4];
        if ((((cVar7 != '\0') && (local_130[3] = local_130[5], cVar7 != '\x01')) &&
            (local_130[3] = local_130[6], cVar7 != '\x02')) &&
           (local_130[3] = local_130[7], cVar7 != '\x03')) {
          fVar4 = local_130[4];
          if (((cVar7 == '\x04') || (fVar4 = local_130[5], cVar7 == '\x05')) ||
             ((fVar4 = local_130[6], cVar7 == '\x06' || (fVar4 = local_130[7], cVar7 == '\a')))) {
            local_130[3] = -fVar4;
          }
          else {
            local_130[3] = TAllocation__guardBlockSize;
            if (((cVar7 != '\t') && (local_130[3] = FLOAT_97c3acd8, cVar7 != '\b')) &&
               (local_130[3] = FLOAT_97c3acec, cVar7 != '\n')) {
              local_130[3] = TAllocation__guardBlockSize;
            }
          }
        }
        break;
      case 0x42:
      case 0x43:
      case 0x44:
      case 0x45:
        ((int (*)())_InterpreterTextureSamplerAttachGLDContext)(piVar14[0x28b],*(undefined4 *)(iVar22 + 0xd9c));
        uVar16 = 0;
        if ((iVar24 == 0x43) || (iVar24 == 0x45)) {
          uVar16 = 1;
        }
        ((int (*)())_InterpreterTextureSamplerSetProjectionEnabled)(piVar14[0x28b],uVar16);
        ((int (*)())_InterpreterTextureSamplerSetLodBiasEnabled)(piVar14[0x28b],iVar24 == 0x44 || iVar24 - 0x44U == 1);
        ((void (*)())_InterpreterTextureSamplerAttachDerivatives)((double)(float)piVar14[0x28f],piVar14[0x28b],*(undefined4 *)(iVar22 + 0xda4));
        fVar8 = local_130[7];
        if (iVar24 - 0x44U < 2) {
          iVar18 = *(int *)(iVar22 + 0xd80);
          fVar4 = local_100[0];
          if (1 < *(int *)(iVar18 + 0x38) - 0x8b30U) {
            local_130[7] = 1.0;
            fVar4 = fVar8;
            goto LAB_97bd29a8;
          }
        }
        else {
LAB_97bd29a8:
          iVar18 = *(int *)(iVar22 + 0xd80);
        }
        dVar28 = (double)fVar4;
        if (*(int *)(iVar18 + 0x38) - 0x8b30U < 2) {
          if (DOUBLE_97c30a78 <= (double)local_130[8]) {
            uVar9 = (uint)((double)local_130[8] - DOUBLE_97c30a78);
            local_98 = (longlong)(int)uVar9;
            uVar9 = uVar9 ^ 0x80000000;
          }
          else {
            uVar9 = (uint)local_130[8];
            local_90 = (longlong)(int)uVar9;
          }
        }
        else {
          uVar9 = piVar15[0x43];
        }
        uVar10 = piVar15[0x44];
        if (uVar10 == 2) {
          _InterpreterTextureSamplerSampleTexelRECT(dVar28,piVar14[0x28b],uVar9);
        }
        else if (uVar10 < 3) {
          if (uVar10 == 1) {
            ((void (*)())_InterpreterTextureSamplerSampleTexel3D)(dVar28,piVar14[0x28b]);
          }
        }
        else if (uVar10 == 3) {
          ((void (*)())_InterpreterTextureSamplerSampleTexel2D)(dVar28,piVar14[0x28b]);
        }
        else if (uVar10 == 4) {
          ((void (*)())_InterpreterTextureSamplerSampleTexel1D)(dVar28,piVar14[0x28b]);
        }
        local_130[0] = local_80;
        local_130[1] = local_7c;
        local_130[2] = local_78;
        local_130[3] = local_74;
        break;
      case 0x48:
      case 0x49:
        dVar28 = (double)_floor((double)local_130[4]);
        if (DOUBLE_97c30a78 <= dVar28) {
          local_98 = (longlong)(int)(dVar28 - DOUBLE_97c30a78);
          uVar9 = (int)(dVar28 - DOUBLE_97c30a78) ^ 0x80000000;
        }
        else {
          uVar9 = (uint)dVar28;
          local_90 = (longlong)(int)uVar9;
        }
        piVar14[0x290] = uVar9;
        goto switchD_97bd0598_caseD_6;
      case 0x4b:
        iVar18 = ((int (*)())_InterpreterTestCR)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],piVar15[7],
                                    piVar15[8],piVar15[9]);
        if (((iVar18 != 0) ||
            (iVar18 = ((int (*)())_InterpreterTestCR)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],
                                         piVar15[7],piVar15[8],piVar15[9]), iVar18 != 0)) ||
           ((iVar18 = ((int (*)())_InterpreterTestCR)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],
                                         piVar15[7],piVar15[8],piVar15[9]), iVar18 != 0 ||
            (iVar18 = ((int (*)())_InterpreterTestCR)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],
                                         piVar15[7],piVar15[8],piVar15[9]), iVar18 != 0))))
        goto switchD_97bd0598_caseD_54;
        goto switchD_97bd0598_caseD_6;
      case 0x4c:
        iVar18 = ((int (*)())_InterpreterTestCR)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],piVar15[7],
                                    piVar15[8],piVar15[9]);
        if ((((iVar18 == 0) &&
             (iVar18 = ((int (*)())_InterpreterTestCR)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],
                                          piVar15[7],piVar15[8],piVar15[9]), iVar18 == 0)) &&
            (iVar18 = ((int (*)())_InterpreterTestCR)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],
                                         piVar15[7],piVar15[8],piVar15[9]), iVar18 == 0)) &&
           (iVar18 = ((int (*)())_InterpreterTestCR)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],
                                        piVar15[7],piVar15[8],piVar15[9]), iVar18 == 0))
        goto switchD_97bd0598_caseD_6;
        if ((uint *)piVar14[0x29b] + 1 <= piVar14 + 0x29b) {
          *(uint *)piVar14[0x29b] = (uint)piVar21;
          piVar14[0x29b] = piVar14[0x29b] + 4;
          goto switchD_97bd0598_caseD_54;
        }
        break;
      case 0x4d:
        iVar18 = ((int (*)())_InterpreterTestCR)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],piVar15[7],
                                    piVar15[8],piVar15[9]);
        if (((iVar18 != 0) ||
            (iVar18 = ((int (*)())_InterpreterTestCR)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],
                                         piVar15[7],piVar15[8],piVar15[9]), iVar18 != 0)) ||
           ((iVar18 = ((int (*)())_InterpreterTestCR)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],
                                         piVar15[7],piVar15[8],piVar15[9]), iVar18 != 0 ||
            (iVar18 = ((int (*)())_InterpreterTestCR)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],
                                         piVar15[7],piVar15[8],piVar15[9]), iVar18 != 0)))) {
          iVar18 = piVar14[0x29b];
          piVar21 = (int *)0x0;
          piVar13 = (int *)(iVar18 - 4);
          if (piVar14 + 0x297 <= piVar13) {
            piVar14[0x29b] = (int)piVar13;
            piVar21 = *(int **)(iVar18 + -4);
          }
        }
        goto switchD_97bd0598_caseD_6;
      case 0x4f:
        if ((((double)local_130[4] < DOUBLE_97c30a48) || ((double)local_130[5] < DOUBLE_97c30a48))
           || (((double)local_130[6] < DOUBLE_97c30a48 || ((double)local_130[7] < DOUBLE_97c30a48)))
           ) {
          piVar14[0x296] = 1;
        }
        goto switchD_97bd0598_caseD_6;
      case 0x54:
      case 0x58:
      case 0x6b:
switchD_97bd0598_caseD_54:
        piVar21 = (int *)((**(int **)(iVar22 + 0xd80) + piVar15[2] * 0x11c) - 0x11c);
        if ((int *)(*(int **)(iVar22 + 0xd80))[1] < piVar21) {
          piVar21 = (int *)0x0;
        }
switchD_97bd0598_caseD_6:
        bVar26 = false;
        break;
      case 0x55:
        if ((((local_130[4] == TAllocation__guardBlockSize) &&
             (local_130[5] == TAllocation__guardBlockSize)) &&
            (local_130[6] == TAllocation__guardBlockSize)) &&
           (local_130[7] == TAllocation__guardBlockSize)) goto switchD_97bd0598_caseD_54;
        break;
      case 0x68:
        uVar9 = (uint)*(byte *)((int)piVar15 + 5);
        if (uVar9 != 0) {
          pfVar12 = local_130;
          do {
            pfVar1 = pfVar12 + 4;
            pfVar2 = pfVar12 + 8;
            pfVar12 = pfVar12 + 1;
            fVar4 = *pfVar1 * *pfVar2 + fVar4;
            uVar9 = uVar9 - 1;
          } while (uVar9 != 0);
        }
        dVar28 = (double)(float)-((double)(local_100[0] * local_100[0]) *
                                  (DOUBLE_97c30a60 - (double)(fVar4 * fVar4)) - DOUBLE_97c30a60);
        if ((double)TAllocation__guardBlockSize <= dVar28) {
          fVar4 = local_100[0] * fVar4;
          dVar28 = (double)_sqrt(dVar28);
          fVar4 = (float)((double)fVar4 + dVar28);
          local_130[0] = local_100[0] * local_130[4] - fVar4 * local_130[8];
          local_130[1] = local_100[0] * local_130[5] - fVar4 * local_130[9];
          local_130[2] = local_100[0] * local_130[6] - fVar4 * local_130[10];
          local_130[3] = local_100[0] * local_130[7] - fVar4 * local_130[0xb];
        }
        else {
          local_130[3] = TAllocation__guardBlockSize;
          local_130[0] = TAllocation__guardBlockSize;
          local_130[1] = TAllocation__guardBlockSize;
          local_130[2] = TAllocation__guardBlockSize;
        }
        break;
      case 0x6c:
        if ((piVar15[9] == 3) && (piVar15[0x13] == 1)) {
          dVar28 = (double)_trunc((double)local_130[4]);
          local_130[0] = (float)dVar28;
          dVar28 = (double)_trunc((double)local_130[5]);
          local_130[1] = (float)dVar28;
          dVar28 = (double)_trunc((double)local_130[6]);
          fVar4 = local_130[7];
LAB_97bd200c:
          local_130[2] = (float)dVar28;
          dVar28 = (double)_trunc((double)fVar4);
          goto LAB_97bd2010;
        }
        if ((piVar15[9] != 4) || ((piVar15[0x13] != 1 && (piVar15[0x13] != 3))))
        goto switchD_97bd0598_caseD_0;
        local_130[0] = 1.0;
        if (local_130[4] == TAllocation__guardBlockSize) {
          local_130[0] = 0.0;
        }
        local_130[1] = 1.0;
        if (local_130[5] == TAllocation__guardBlockSize) {
          local_130[1] = 0.0;
        }
        local_130[2] = 1.0;
        if (local_130[6] == TAllocation__guardBlockSize) {
          local_130[2] = 0.0;
        }
        local_130[3] = 1.0;
        if (local_130[7] == TAllocation__guardBlockSize) goto LAB_97bd1ce0;
        break;
      case 0x6d:
        dVar28 = (double)local_130[8];
        local_130[0] = local_100[0];
        local_130[1] = local_100[1];
        local_130[2] = local_100[2];
        local_130[3] = local_100[3];
        if (DOUBLE_97c30a78 <= dVar28) {
          iVar18 = (int)(dVar28 - DOUBLE_97c30a78);
          local_a8 = (longlong)iVar18;
        }
        else {
          iVar18 = (int)local_130[8];
          local_a0 = (longlong)iVar18;
        }
        if (DOUBLE_97c30a78 <= dVar28) {
          iVar27 = (int)(dVar28 - DOUBLE_97c30a78);
          local_90 = (longlong)iVar27;
        }
        else {
          iVar27 = (int)local_130[8];
          local_98 = (longlong)iVar27;
        }
        local_130[iVar18] = local_130[iVar27 + 4];
        break;
      case 0x6f:
        dVar28 = (double)_exp((double)local_130[4]);
        local_130[0] = (float)dVar28;
        dVar28 = (double)_exp((double)local_130[5]);
        local_130[1] = (float)dVar28;
        dVar28 = (double)_exp((double)local_130[6]);
        local_130[2] = (float)dVar28;
        dVar28 = (double)_exp((double)local_130[7]);
        goto LAB_97bd2010;
      case 0x70:
        dVar28 = (double)_log((double)local_130[4]);
        local_130[0] = (float)dVar28;
        dVar28 = (double)_log((double)local_130[5]);
        local_130[1] = (float)dVar28;
        dVar28 = (double)_log((double)local_130[6]);
        local_130[2] = (float)dVar28;
        dVar28 = (double)_log((double)local_130[7]);
LAB_97bd2010:
        dVar28 = (double)(float)dVar28;
LAB_97bd2014:
        local_130[3] = (float)dVar28;
      }
      if (cVar5 != '\0') {
        if (DOUBLE_97c30a48 <= (double)local_130[0]) {
          if ((double)local_130[0] <= DOUBLE_97c30a60) {
            local_70 = local_130[0];
          }
          else {
            local_130[0] = 1.0;
          }
        }
        else {
          local_130[0] = 0.0;
        }
        if (DOUBLE_97c30a48 <= (double)local_130[1]) {
          if ((double)local_130[1] <= DOUBLE_97c30a60) {
            local_70 = local_130[1];
          }
          else {
            local_130[1] = 1.0;
          }
        }
        else {
          local_130[1] = 0.0;
        }
        if (DOUBLE_97c30a48 <= (double)local_130[2]) {
          if ((double)local_130[2] <= DOUBLE_97c30a60) {
            local_70 = local_130[2];
          }
          else {
            local_130[2] = 1.0;
          }
        }
        else {
          local_130[2] = 0.0;
        }
        if (DOUBLE_97c30a48 <= (double)local_130[3]) {
          if ((double)local_130[3] <= DOUBLE_97c30a60) {
            local_70 = local_130[3];
          }
          else {
            local_130[3] = 1.0;
          }
        }
        else {
          local_130[3] = 0.0;
        }
      }
      if (bVar26) {
        ((int (*)())_InterpreterWriteDestination)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],piVar15[7],piVar15[8],
                   piVar15[9]);
      }
      uVar25 = uVar25 + 1;
      if (uVar23 <= uVar25) {
        return piVar21;
      }
      iVar18 = piVar15[0xc];
    } while( true );
  }
  if (uVar23 < 2) {
    ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
               piVar15[0x12],piVar15[0x13]);
    ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
               piVar15[0x1b],piVar15[0x1c]);
    if (*(char *)((int)piVar15 + 0x21) == '\x01') {
      cVar5 = *(char *)((int)piVar15 + 5);
      if (cVar5 == '\x01') {
LAB_97bd0310:
        local_130[0] = 1.0;
        if (local_130[5] == local_130[9]) goto LAB_97bd0328;
      }
      else if (cVar5 == '\x02') {
        if (local_130[4] == local_130[8]) goto LAB_97bd0310;
      }
      else if (cVar5 == '\x03') {
        if ((local_130[4] == local_130[8]) &&
           (bVar26 = local_130[5] == local_130[9], local_130[5] = local_130[6],
           local_130[9] = local_130[10], bVar26)) goto LAB_97bd0310;
      }
      else {
        if (cVar5 != '\x04') goto LAB_97bd0328;
        if (((local_130[4] == local_130[8]) && (local_130[5] == local_130[9])) &&
           (local_130[5] = local_130[7], local_130[9] = local_130[0xb],
           local_130[6] == local_130[10])) goto LAB_97bd0310;
      }
      local_130[0] = 0.0;
      goto LAB_97bd0328;
    }
    local_130[0] = 1.0;
    if (local_130[4] != local_130[8]) {
      local_130[0] = 0.0;
    }
    local_130[1] = 1.0;
    if (local_130[5] != local_130[9]) {
      local_130[1] = 0.0;
    }
    local_130[2] = 1.0;
    if (local_130[6] != local_130[10]) {
      local_130[2] = 0.0;
    }
    local_130[3] = 1.0;
    if (local_130[7] != local_130[0xb]) {
      local_130[3] = 0.0;
    }
  }
  else {
    if (uVar23 == 3) {
      pfVar12 = local_130;
      uVar23 = 0;
      do {
        ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                   piVar15[0x12],piVar15[0x13]);
        ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                   piVar15[0x1b],piVar15[0x1c]);
        if (((local_130[4] != local_130[8]) || (local_130[5] != local_130[9])) ||
           (fVar4 = FLOAT_97c3acd8, local_130[6] != local_130[10])) {
          fVar4 = TAllocation__guardBlockSize;
        }
        uVar23 = uVar23 + 1;
        *pfVar12 = fVar4;
        pfVar12 = pfVar12 + 1;
      } while (uVar23 < 3);
      uStack_ac = 0;
      if ((local_130[0] != TAllocation__guardBlockSize) &&
         (local_130[1] != TAllocation__guardBlockSize)) {
LAB_97bd0194:
        uStack_ac = 0;
        if (local_130[2] != TAllocation__guardBlockSize) {
          uStack_ac = 1;
        }
      }
LAB_97bd01a0:
      uStack_ac = uStack_ac ^ 0x80000000;
      local_b0 = 0x43300000;
      local_130[0] = (float)((double)CONCAT44(0x43300000,uStack_ac) - DOUBLE_97c30a58);
    }
    else if (uVar23 < 4) {
      if (uVar23 == 2) {
        pfVar12 = local_130;
        uVar23 = 0;
        do {
          ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                     piVar15[0x12],piVar15[0x13]);
          ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                     piVar15[0x1b],piVar15[0x1c]);
          if ((local_130[4] != local_130[8]) ||
             (fVar4 = FLOAT_97c3acd8, local_130[5] != local_130[9])) {
            fVar4 = TAllocation__guardBlockSize;
          }
          uVar23 = uVar23 + 1;
          *pfVar12 = fVar4;
          pfVar12 = pfVar12 + 1;
        } while (uVar23 < 2);
        uStack_ac = 0;
        local_130[2] = local_130[1];
        if (local_130[0] != TAllocation__guardBlockSize) goto LAB_97bd0194;
        goto LAB_97bd01a0;
      }
    }
    else if (uVar23 == 4) {
      pfVar12 = local_130;
      uVar23 = 0;
      do {
        ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                   piVar15[0x12],piVar15[0x13]);
        ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                   piVar15[0x1b],piVar15[0x1c]);
        if ((((local_130[4] != local_130[8]) || (local_130[5] != local_130[9])) ||
            (local_130[6] != local_130[10])) ||
           (fVar4 = FLOAT_97c3acd8, local_130[7] != local_130[0xb])) {
          fVar4 = TAllocation__guardBlockSize;
        }
        uVar23 = uVar23 + 1;
        *pfVar12 = fVar4;
        pfVar12 = pfVar12 + 1;
      } while (uVar23 < 4);
      uStack_ac = 0;
      if (((local_130[0] != TAllocation__guardBlockSize) &&
          (local_130[1] != TAllocation__guardBlockSize)) &&
         (bVar26 = local_130[2] != TAllocation__guardBlockSize, local_130[2] = local_130[3], bVar26)
         ) goto LAB_97bd0194;
      goto LAB_97bd01a0;
    }
LAB_97bd0328:
    local_130[3] = local_130[0];
    local_130[1] = local_130[0];
    local_130[2] = local_130[0];
  }
  if (iVar24 == 0x36) {
    local_130[0] = (float)(DOUBLE_97c30a60 - (double)local_130[0]);
    local_130[1] = (float)(DOUBLE_97c30a60 - (double)local_130[1]);
    local_130[2] = (float)(DOUBLE_97c30a60 - (double)local_130[2]);
    local_130[3] = (float)(DOUBLE_97c30a60 - (double)local_130[3]);
  }
  iVar20 = piVar15[9];
  iVar22 = piVar15[3];
  iVar18 = piVar15[4];
  iVar24 = piVar15[5];
  iVar27 = piVar15[6];
  iVar17 = piVar15[7];
  iVar19 = piVar15[8];
LAB_97bd043c:
  ((int (*)())_InterpreterWriteDestination)(piVar14,iVar22,iVar18,iVar24,iVar27,iVar17,iVar19,iVar20);
  return piVar21;
}

/* _InterpreterWriteFinalFragmentToBuffer @ 0x97bd3068 (376 bytes) */
int _InterpreterWriteFinalFragmentToBuffer(param_1)
  int *param_1;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined1 auStack_40 [16];
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  
  piVar3 = param_1 + 0x292;
  iVar2 = *param_1;
  iVar1 = *(int *)(iVar2 + 0xd80);
  if ((*(uint *)(iVar1 + 0x3c) & 1) != 0) {
    iVar1 = _InterpreterRasterOpMachine_AlphaTest(param_1 + 0x289,piVar3);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = *(int *)(iVar2 + 0xd80);
  }
  if ((*(uint *)(iVar1 + 0x3c) & 6) != 0) {
    iVar1 = _InterpreterRasterOpMachine_DepthAndStencilTest(param_1 + 0x289);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = *(int *)(iVar2 + 0xd80);
  }
  if ((*(uint *)(iVar1 + 0x3c) & 0x68) != 0) {
    ((int (*)())_InterpreterUnpackPixel)(param_1,auStack_40,*(undefined4 *)(iVar2 + 0xd88));
    iVar1 = *(int *)(iVar2 + 0xd80);
  }
  if ((*(uint *)(iVar1 + 0x3c) & 8) != 0) {
    _InterpreterRasterOpMachine_Blending(param_1 + 0x289,piVar3,auStack_40,&local_30);
    param_1[0x292] = local_30;
    param_1[0x293] = local_2c;
    param_1[0x294] = local_28;
    param_1[0x295] = local_24;
    iVar1 = *(int *)(iVar2 + 0xd80);
  }
  if ((*(uint *)(iVar1 + 0x3c) & 0x20) != 0) {
    _InterpreterRasterOpMachine_LogicOp(param_1 + 0x289,piVar3,auStack_40,&local_30);
    param_1[0x292] = local_30;
    param_1[0x293] = local_2c;
    param_1[0x294] = local_28;
    param_1[0x295] = local_24;
    iVar1 = *(int *)(iVar2 + 0xd80);
  }
  if ((*(uint *)(iVar1 + 0x3c) & 0x40) == 0) {
    local_24 = param_1[0x295];
    local_30 = param_1[0x292];
    local_2c = param_1[0x293];
    local_28 = param_1[0x294];
  }
  else {
    _InterpreterRasterOpMachine_BufferMask(param_1 + 0x289,piVar3,auStack_40,&local_30);
  }
  ((int (*)())_InterpreterPackPixel)(param_1,&local_30,*(undefined4 *)(iVar2 + 0xd88));
  return;
}

/* _InterpreterRun @ 0x97bd31e0 (1020 bytes) */
int _InterpreterRun()
{
  bool bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  double dVar13;
  float fVar14;
  int iVar15;
  float *pfVar16;
  int iVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  int iVar22;
  int iVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  double dVar27;
  double dVar28;
  undefined8 uVar29;
  
  uVar29 = FUN_97c1a23c();
  dVar13 = DOUBLE_97c30a60;
  iVar17 = (int)((ulonglong)uVar29 >> 0x20);
  iVar22 = (int)uVar29;
  iVar19 = *(int *)(*(int *)(iVar17 + 0xd80) + 0x38);
  iVar23 = *(int *)(iVar17 + 0xdf0);
  iVar15 = *(int *)(iVar17 + 0xd9c);
  uVar21 = 0xff;
  uVar20 = 0;
  if ((iVar19 == 0x8804) || (iVar19 == 0x8b30)) {
    dVar28 = (double)*(float *)(*(int *)(iVar17 + 0xda0) + 0xc);
    dVar26 = (double)*(float *)(*(int *)(iVar17 + 0xda0) + 8);
    dVar27 = (double)*(float *)(*(int *)(iVar17 + 0xda4) + 0xc);
    dVar25 = (double)*(float *)(*(int *)(iVar17 + 0xda4) + 8);
    fVar6 = TAllocation__guardBlockSize;
    fVar7 = TAllocation__guardBlockSize;
    fVar8 = TAllocation__guardBlockSize;
    fVar9 = TAllocation__guardBlockSize;
    fVar10 = TAllocation__guardBlockSize;
    fVar11 = TAllocation__guardBlockSize;
  }
  else {
    dVar27 = (double)TAllocation__guardBlockSize;
    dVar25 = dVar27;
    dVar26 = dVar27;
    dVar28 = dVar27;
    fVar6 = *(float *)(iVar15 + 0x1b88);
    fVar7 = *(float *)(iVar15 + 0x1b78);
    fVar8 = *(float *)(iVar15 + 0x1b70);
    fVar9 = *(float *)(iVar15 + 0x1b80);
    fVar10 = *(float *)(iVar15 + 0x1b84);
    fVar11 = *(float *)(iVar15 + 0x1b74);
  }
  iVar15 = *(int *)(*(int *)(iVar17 + 0xd80) + 0x38);
  if ((iVar15 == 0x8804) || (iVar15 == 0x8b30)) {
    *(undefined4 *)(iVar23 + 0xa30) = 0;
    *(float *)(iVar23 + 0xa38) = (float)dVar26;
    *(float *)(iVar23 + 0xa3c) = (float)(dVar13 / dVar28);
  }
  *(undefined1 *)(iVar23 + 0xa47) = 0;
  *(undefined4 *)(iVar23 + 0xa68) = 0;
  *(int *)(iVar23 + 0xa6c) = iVar23 + 0xa5c;
  *(undefined1 *)(iVar23 + 0xa44) = 0;
  *(undefined1 *)(iVar23 + 0xa45) = 0;
  *(undefined1 *)(iVar23 + 0xa46) = 0;
  *(undefined4 *)(iVar23 + 0xa5c) = 0;
  *(undefined4 *)(iVar23 + 0xa60) = 0;
  *(undefined4 *)(iVar23 + 0xa64) = 0;
  fVar14 = TAllocation__guardBlockSize;
  dVar13 = DOUBLE_97c30a60;
  do {
    if (iVar22 == 0) {
      iVar22 = *(int *)(*(int *)(iVar17 + 0xd80) + 0x38);
      if ((iVar22 == 0x8804) || (iVar22 == 0x8b30)) {
        uVar20 = 0;
      }
      else {
        uVar20 = uVar21 << 8 | uVar20;
      }
      FUN_97c1a28c(uVar20);
      return;
    }
    iVar22 = iVar22 + -1;
    *(undefined4 *)(iVar23 + 0xa58) = 0;
    iVar15 = *(int *)(iVar17 + 0xd80);
    if (((*(uint *)(iVar15 + 0x3c) & 6) == 4) && ((*(uint *)(iVar15 + 0x34) & 0xa000) == 0)) {
      uVar18 = ((int (*)())_InterpreterRasterOpMachine_DepthTest)(iVar23 + 0xa24);
      *(uint *)(iVar23 + 0xa58) = *(uint *)(iVar23 + 0xa58) | uVar18;
      iVar15 = *(int *)(iVar17 + 0xd80);
    }
    iVar19 = *(int *)(iVar15 + 0x120);
    if ((iVar19 != 0) && (*(int *)(iVar23 + 0xa58) == 0)) {
      do {
        iVar19 = ((int (*)())_InterpreterEmulateOp)(iVar23,iVar19);
        if (iVar19 == 0) break;
      } while (*(int *)(iVar23 + 0xa58) == 0);
      iVar15 = *(int *)(iVar17 + 0xd80);
    }
    if ((*(int *)(iVar15 + 0x38) == 0x8804) || (*(int *)(iVar15 + 0x38) == 0x8b30)) {
      if (*(int *)(iVar23 + 0xa58) == 0) {
        ((int (*)())_InterpreterWriteFinalFragmentToBuffer)(iVar23);
        iVar15 = *(int *)(iVar17 + 0xd80);
      }
    }
    else {
      pfVar16 = *(float **)(iVar17 + 0xd88);
      uVar18 = 0;
      fVar2 = pfVar16[7];
      fVar3 = pfVar16[4];
      fVar12 = -fVar2;
      fVar4 = pfVar16[5];
      fVar5 = pfVar16[6];
      if (fVar3 < fVar12) {
        uVar18 = 0x10;
      }
      if (fVar2 <= fVar3) {
        uVar18 = uVar18 | 0x20;
      }
      if (fVar4 < fVar12) {
        uVar18 = uVar18 | 4;
      }
      if (fVar2 <= fVar4) {
        uVar18 = uVar18 | 8;
      }
      if (fVar5 < fVar12) {
        uVar18 = uVar18 | 1;
      }
      if (fVar2 < fVar5) {
        uVar18 = uVar18 | 2;
      }
      pfVar16[0x1f] = (float)(uVar18 | 0x1000000);
      if (uVar18 == 0) {
        if (fVar2 < fVar14) {
          bVar1 = fVar2 <= FLOAT_97c3acf4;
        }
        else {
          bVar1 = FLOAT_97c3acf0 <= fVar2;
        }
        if (bVar1) {
          fVar12 = FLOAT_97c3acd8 / fVar2;
        }
        else {
          fVar12 = FLOAT_97c3acfc;
          if (fVar14 <= fVar2) {
            fVar12 = FLOAT_97c3acf8;
          }
        }
        pfVar16[3] = fVar12;
        *pfVar16 = fVar3 * fVar12 * fVar8 + fVar9;
        pfVar16[1] = fVar4 * fVar12 * fVar11 + fVar10;
        pfVar16[2] = fVar5 * fVar12 * fVar7 + fVar6;
      }
      iVar15 = *(int *)(iVar17 + 0xd80);
      uVar21 = uVar21 & uVar18;
      uVar20 = uVar20 | uVar18;
    }
    *(int *)(iVar17 + 0xd8c) = *(int *)(iVar17 + 0xd8c) + *(int *)(iVar15 + 0xbc);
    *(int *)(iVar17 + 0xd88) = *(int *)(iVar17 + 0xd88) + *(int *)(iVar15 + 0xb8);
    *(int *)(iVar17 + 0xda8) = *(int *)(iVar17 + 0xda8) + *(int *)(iVar15 + 0xd8);
    *(int *)(iVar17 + 0xdac) = *(int *)(iVar17 + 0xdac) + *(int *)(iVar15 + 0xdc);
    if ((*(int *)(iVar15 + 0x38) == 0x8804) || (*(int *)(iVar15 + 0x38) == 0x8b30)) {
      fVar2 = (float)((double)*(float *)(iVar23 + 0xa30) + dVar13);
      dVar24 = (double)fVar2;
      *(float *)(iVar23 + 0xa30) = fVar2;
      *(float *)(iVar23 + 0xa38) = (float)(dVar25 * dVar24 + dVar26);
      *(float *)(iVar23 + 0xa3c) = (float)(dVar13 / (double)(float)(dVar27 * dVar24 + dVar28));
    }
  } while( true );
}

/* _InterpreterTextureSamplerCreate @ 0x97bd35dc (12 bytes) */
int _InterpreterTextureSamplerCreate()
{
  _calloc(0x2c,1);
  return;
}

/* _InterpreterTextureSamplerInitialise @ 0x97bd35e8 (16 bytes) */
int _InterpreterTextureSamplerInitialise(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0x18) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x14) = 0xffffffff;
  return;
}

/* _InterpreterTextureSamplerAttachGLDContext @ 0x97bd35fc (8 bytes) */
int _InterpreterTextureSamplerAttachGLDContext(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  *param_1 = param_2;
  return;
}

/* _InterpreterTextureSamplerSetProjectionEnabled @ 0x97bd3604 (8 bytes) */
int _InterpreterTextureSamplerSetProjectionEnabled(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(param_1 + 0x20) = param_2;
  return;
}

/* _InterpreterTextureSamplerSetLodBiasEnabled @ 0x97bd360c (8 bytes) */
int _InterpreterTextureSamplerSetLodBiasEnabled(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(param_1 + 0x24) = param_2;
  return;
}

/* _InterpreterTextureSamplerAttachDerivatives @ 0x97bd3614 (12 bytes) */
void _InterpreterTextureSamplerAttachDerivatives(double param_1,int param_2,undefined4 param_3)

{
  *(float *)(param_2 + 0x10) = (float)param_1;
  *(undefined4 *)(param_2 + 0xc) = param_3;
  return;
}

/* _InterpreterTextureSamplerSampleTexel1D @ 0x97bd3620 (512 bytes) */
void _InterpreterTextureSamplerSampleTexel1D
               (double param_1,int *param_2,int param_3,undefined4 param_4,undefined4 param_5,
               float *param_6)

{
  float fVar1;
  int *piVar2;
  uint uVar3;
  double dVar4;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  longlong local_60;
  longlong local_58;
  float local_40;
  
  piVar2 = *(int **)(*param_2 + param_3 * 4);
  if (*(ushort *)(*piVar2 + 0x16) - 0x2700 < 4) {
    param_2[10] = 1;
    dVar4 = (double)((double (*)())_InterpreterTextureSamplerCalculateLambda1D)(param_2,param_5,param_3);
    local_40 = (float)((double)(float)(dVar4 + (double)(float)piVar2[0x10]) + param_1);
    if (local_40 < (float)piVar2[0xc]) {
      local_40 = (float)piVar2[0xc];
    }
    dVar4 = (double)local_40;
    if ((double)(float)piVar2[8] < dVar4) {
      dVar4 = (double)(float)piVar2[8];
    }
    if (DOUBLE_97c30a78 <= dVar4) {
      local_58 = (longlong)(int)(dVar4 - DOUBLE_97c30a78);
      uVar3 = (int)(dVar4 - DOUBLE_97c30a78) ^ 0x80000000;
    }
    else {
      uVar3 = (uint)dVar4;
      local_60 = (longlong)(int)uVar3;
    }
    if (1 < *(ushort *)(*piVar2 + 0x16) - 0x2700) {
      ((int (*)())_InterpreterTextureSamplerSampleTexel1DFromLevel)(param_2,param_3,uVar3,param_5,&local_80);
      ((int (*)())_InterpreterTextureSamplerSampleTexel1DFromLevel)(param_2,param_3,uVar3 + 1,param_5,&local_70);
      dVar4 = (double)(float)(dVar4 - (double)(float)((double)CONCAT44(0x43300000,uVar3) -
                                                     DOUBLE_97c30a68));
      fVar1 = (float)(DOUBLE_97c30a60 - dVar4);
      *param_6 = fVar1 * local_80 + (float)(dVar4 * (double)local_70);
      param_6[3] = fVar1 * local_74 + (float)(dVar4 * (double)local_64);
      param_6[1] = fVar1 * local_7c + (float)(dVar4 * (double)local_6c);
      param_6[2] = fVar1 * local_78 + (float)(dVar4 * (double)local_68);
      return;
    }
  }
  else {
    uVar3 = 0;
    param_2[10] = 0;
  }
  ((int (*)())_InterpreterTextureSamplerSampleTexel1DFromLevel)(param_2,param_3,uVar3,param_5,param_6);
  return;
}

/* _InterpreterTextureSamplerSampleTexel2D @ 0x97bd3820 (512 bytes) */
void _InterpreterTextureSamplerSampleTexel2D
               (double param_1,int *param_2,int param_3,undefined4 param_4,undefined4 param_5,
               float *param_6)

{
  float fVar1;
  int *piVar2;
  uint uVar3;
  double dVar4;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  longlong local_60;
  longlong local_58;
  float local_40;
  
  piVar2 = *(int **)(*param_2 + param_3 * 4);
  if (*(ushort *)(*piVar2 + 0x16) - 0x2700 < 4) {
    param_2[10] = 1;
    dVar4 = (double)((double (*)())_InterpreterTextureSamplerCalculateLambda2D)(param_2,param_5,param_3);
    local_40 = (float)((double)(float)(dVar4 + (double)(float)piVar2[0x10]) + param_1);
    if (local_40 < (float)piVar2[0xc]) {
      local_40 = (float)piVar2[0xc];
    }
    dVar4 = (double)local_40;
    if ((double)(float)piVar2[8] < dVar4) {
      dVar4 = (double)(float)piVar2[8];
    }
    if (DOUBLE_97c30a78 <= dVar4) {
      local_58 = (longlong)(int)(dVar4 - DOUBLE_97c30a78);
      uVar3 = (int)(dVar4 - DOUBLE_97c30a78) ^ 0x80000000;
    }
    else {
      uVar3 = (uint)dVar4;
      local_60 = (longlong)(int)uVar3;
    }
    if (1 < *(ushort *)(*piVar2 + 0x16) - 0x2700) {
      ((int (*)())_InterpreterTextureSamplerSampleTexel2DFromLevel)(param_2,param_3,uVar3,param_5,&local_80);
      ((int (*)())_InterpreterTextureSamplerSampleTexel2DFromLevel)(param_2,param_3,uVar3 + 1,param_5,&local_70);
      dVar4 = (double)(float)(dVar4 - (double)(float)((double)CONCAT44(0x43300000,uVar3) -
                                                     DOUBLE_97c30a68));
      fVar1 = (float)(DOUBLE_97c30a60 - dVar4);
      *param_6 = fVar1 * local_80 + (float)(dVar4 * (double)local_70);
      param_6[3] = fVar1 * local_74 + (float)(dVar4 * (double)local_64);
      param_6[1] = fVar1 * local_7c + (float)(dVar4 * (double)local_6c);
      param_6[2] = fVar1 * local_78 + (float)(dVar4 * (double)local_68);
      return;
    }
  }
  else {
    uVar3 = 0;
    param_2[10] = 0;
  }
  ((int (*)())_InterpreterTextureSamplerSampleTexel2DFromLevel)(param_2,param_3,uVar3,param_5,param_6);
  return;
}

/* _InterpreterTextureSamplerSampleTexel3D @ 0x97bd3a20 (512 bytes) */
void _InterpreterTextureSamplerSampleTexel3D
               (double param_1,int *param_2,int param_3,undefined4 param_4,undefined4 param_5,
               float *param_6)

{
  float fVar1;
  int *piVar2;
  uint uVar3;
  double dVar4;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  longlong local_60;
  longlong local_58;
  float local_40;
  
  piVar2 = *(int **)(*param_2 + param_3 * 4);
  if (*(ushort *)(*piVar2 + 0x16) - 0x2700 < 4) {
    param_2[10] = 1;
    dVar4 = (double)((double (*)())_InterpreterTextureSamplerCalculateLambda3D)(param_2,param_5,param_3);
    local_40 = (float)((double)(float)(dVar4 + (double)(float)piVar2[0x10]) + param_1);
    if (local_40 < (float)piVar2[0xc]) {
      local_40 = (float)piVar2[0xc];
    }
    dVar4 = (double)local_40;
    if ((double)(float)piVar2[8] < dVar4) {
      dVar4 = (double)(float)piVar2[8];
    }
    if (DOUBLE_97c30a78 <= dVar4) {
      local_58 = (longlong)(int)(dVar4 - DOUBLE_97c30a78);
      uVar3 = (int)(dVar4 - DOUBLE_97c30a78) ^ 0x80000000;
    }
    else {
      uVar3 = (uint)dVar4;
      local_60 = (longlong)(int)uVar3;
    }
    if (1 < *(ushort *)(*piVar2 + 0x16) - 0x2700) {
      ((int (*)())_InterpreterTextureSamplerSampleTexel3DFromLevel)(param_2,param_3,uVar3,param_5,&local_80);
      ((int (*)())_InterpreterTextureSamplerSampleTexel3DFromLevel)(param_2,param_3,uVar3 + 1,param_5,&local_70);
      dVar4 = (double)(float)(dVar4 - (double)(float)((double)CONCAT44(0x43300000,uVar3) -
                                                     DOUBLE_97c30a68));
      fVar1 = (float)(DOUBLE_97c30a60 - dVar4);
      *param_6 = fVar1 * local_80 + (float)(dVar4 * (double)local_70);
      param_6[3] = fVar1 * local_74 + (float)(dVar4 * (double)local_64);
      param_6[1] = fVar1 * local_7c + (float)(dVar4 * (double)local_6c);
      param_6[2] = fVar1 * local_78 + (float)(dVar4 * (double)local_68);
      return;
    }
  }
  else {
    uVar3 = 0;
    param_2[10] = 0;
  }
  ((int (*)())_InterpreterTextureSamplerSampleTexel3DFromLevel)(param_2,param_3,uVar3,param_5,param_6);
  return;
}

/* _InterpreterTextureSamplerWrapCoordinate @ 0x97bd3c28 (528 bytes) */
int _InterpreterTextureSamplerWrapCoordinate(param_1, param_2)
  int param_1;
  uint *param_2;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  
  iVar4 = *(int *)(param_1 + 8);
  iVar2 = **(int **)(param_1 + 4);
  uVar5 = *(ushort *)(iVar2 + 0x10);
  uVar7 = *(ushort *)(iVar2 + 0x12);
  uVar6 = *(ushort *)(iVar2 + 0x14);
  if ((*(short *)(iVar2 + 0x16) == 0x2600) || (*(short *)(iVar2 + 0x16) == 0x2700)) {
    if (uVar5 == 0x2900) {
      uVar5 = 0x812f;
    }
    if (uVar7 == 0x2900) {
      uVar7 = 0x812f;
    }
    if (uVar6 == 0x2900) {
      uVar6 = 0x812f;
    }
  }
  if (uVar5 == 0x2901) {
    uVar1 = *param_2 & *(uint *)(iVar4 + 0x40);
LAB_97bd3d20:
    *param_2 = uVar1;
  }
  else {
    if (uVar5 < 0x2902) {
      if (uVar5 != 0x2900) goto LAB_97bd3d24;
LAB_97bd3cec:
      uVar1 = *param_2;
      if ((int)uVar1 < 0) {
LAB_97bd3cf8:
        uVar1 = 0;
        goto LAB_97bd3d20;
      }
      uVar3 = *(uint *)(iVar4 + 0x80);
    }
    else {
      if (uVar5 == 0x812d) goto LAB_97bd3cec;
      if (uVar5 != 0x812f) goto LAB_97bd3d24;
      uVar1 = *param_2;
      if ((int)uVar1 < 0) goto LAB_97bd3cf8;
      uVar3 = *(uint *)(iVar4 + 0x30);
    }
    if (uVar3 < uVar1) {
      *param_2 = uVar3;
    }
  }
LAB_97bd3d24:
  if (uVar7 == 0x2901) {
    uVar1 = param_2[1] & *(uint *)(iVar4 + 0x44);
LAB_97bd3da8:
    param_2[1] = uVar1;
  }
  else {
    if (uVar7 < 0x2902) {
      if (uVar7 != 0x2900) goto LAB_97bd3dac;
LAB_97bd3d74:
      uVar1 = param_2[1];
      if ((int)uVar1 < 0) {
LAB_97bd3d80:
        uVar1 = 0;
        goto LAB_97bd3da8;
      }
      uVar3 = *(uint *)(iVar4 + 0x84);
    }
    else {
      if (uVar7 == 0x812d) goto LAB_97bd3d74;
      if (uVar7 != 0x812f) goto LAB_97bd3dac;
      uVar1 = param_2[1];
      if ((int)uVar1 < 0) goto LAB_97bd3d80;
      uVar3 = *(uint *)(iVar4 + 0x34);
    }
    if (uVar3 < uVar1) {
      param_2[1] = uVar3;
    }
  }
LAB_97bd3dac:
  if (uVar6 == 0x2901) {
    uVar1 = param_2[2] & *(uint *)(iVar4 + 0x48);
    goto LAB_97bd3e30;
  }
  if (uVar6 < 0x2902) {
    if (uVar6 != 0x2900) {
      return;
    }
LAB_97bd3dfc:
    uVar1 = param_2[2];
    if (-1 < (int)uVar1) {
      uVar3 = *(uint *)(iVar4 + 0x88);
LAB_97bd3e14:
      if (uVar3 < uVar1) {
        param_2[2] = uVar3;
        return;
      }
      return;
    }
  }
  else {
    if (uVar6 == 0x812d) goto LAB_97bd3dfc;
    if (uVar6 != 0x812f) {
      return;
    }
    uVar1 = param_2[2];
    if (-1 < (int)uVar1) {
      uVar3 = *(uint *)(iVar4 + 0x38);
      goto LAB_97bd3e14;
    }
  }
  uVar1 = 0;
LAB_97bd3e30:
  param_2[2] = uVar1;
  return;
}

/* _InterpreterTextureSamplerCalculateLambda1D @ 0x97bd3e38 (276 bytes) */
double _InterpreterTextureSamplerCalculateLambda1D(int *param_1,float *param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  int iVar9;
  double dVar10;
  double dVar11;
  
  fVar1 = param_2[3];
  iVar9 = param_3 * 0x10 + param_1[3];
  fVar2 = *(float *)(iVar9 + 0x4c);
  iVar8 = param_3 * 0x10 + param_1[3] + 0xc0;
  fVar3 = *(float *)(iVar8 + 0x4c);
  fVar4 = *param_2;
  fVar5 = *(float *)(iVar9 + 0x40);
  fVar6 = *(float *)(iVar8 + 0x40);
  fVar7 = *(float *)(*(int *)(param_3 * 4 + *param_1) + 0x120);
  fVar2 = -((fVar4 - fVar5) * (float)(DOUBLE_97c30a60 / (double)(fVar1 - fVar2)) -
           (fVar4 + fVar5) * (float)(DOUBLE_97c30a60 / (double)(fVar1 + fVar2))) * fVar7;
  fVar7 = -((fVar4 - fVar6) * (float)(DOUBLE_97c30a60 / (double)(fVar1 - fVar3)) -
           (fVar4 + fVar6) * (float)(DOUBLE_97c30a60 / (double)(fVar1 + fVar3))) * fVar7;
  dVar10 = (double)_sqrt((double)(fVar2 * fVar2));
  dVar11 = (double)_sqrt((double)(fVar7 * fVar7));
  fVar1 = (float)dVar11;
  if ((float)dVar11 < (float)dVar10) {
    fVar1 = (float)dVar10;
  }
  dVar10 = (double)_log2((double)(fVar1 * (float)param_1[4]));
  return (double)(float)dVar10;
}

/* _InterpreterTextureSamplerCalculateLambda2D @ 0x97bd3f4c (348 bytes) */
double _InterpreterTextureSamplerCalculateLambda2D(int *param_1,float *param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  double dVar13;
  double dVar14;
  
  fVar4 = param_2[3];
  iVar11 = param_3 * 0x10 + param_1[3];
  iVar12 = param_3 * 0x10 + param_1[3] + 0xc0;
  fVar5 = *param_2;
  fVar6 = param_2[1];
  iVar10 = *(int *)(param_3 * 4 + *param_1);
  fVar7 = *(float *)(iVar10 + 0x124);
  fVar8 = *(float *)(iVar10 + 0x120);
  fVar1 = (float)(DOUBLE_97c30a60 / (double)(fVar4 + *(float *)(iVar11 + 0x4c)));
  fVar2 = (float)(DOUBLE_97c30a60 / (double)(fVar4 - *(float *)(iVar11 + 0x4c)));
  fVar3 = (float)(DOUBLE_97c30a60 / (double)(fVar4 + *(float *)(iVar12 + 0x4c)));
  fVar4 = (float)(DOUBLE_97c30a60 / (double)(fVar4 - *(float *)(iVar12 + 0x4c)));
  fVar9 = -((fVar6 - *(float *)(iVar11 + 0x44)) * fVar2 -
           (fVar6 + *(float *)(iVar11 + 0x44)) * fVar1) * fVar7;
  fVar1 = -((fVar5 - *(float *)(iVar11 + 0x40)) * fVar2 -
           (fVar5 + *(float *)(iVar11 + 0x40)) * fVar1) * fVar8;
  fVar8 = -((fVar5 - *(float *)(iVar12 + 0x40)) * fVar4 -
           (fVar5 + *(float *)(iVar12 + 0x40)) * fVar3) * fVar8;
  fVar7 = -((fVar6 - *(float *)(iVar12 + 0x44)) * fVar4 -
           (fVar6 + *(float *)(iVar12 + 0x44)) * fVar3) * fVar7;
  dVar13 = (double)_sqrt((double)(fVar1 * fVar1 + fVar9 * fVar9));
  dVar14 = (double)_sqrt((double)(fVar8 * fVar8 + fVar7 * fVar7));
  fVar1 = (float)dVar14;
  if ((float)dVar14 < (float)dVar13) {
    fVar1 = (float)dVar13;
  }
  dVar13 = (double)_log2((double)(fVar1 * (float)param_1[4]));
  return (double)(float)dVar13;
}

/* _InterpreterTextureSamplerCalculateLambda3D @ 0x97bd40a8 (360 bytes) */
double _InterpreterTextureSamplerCalculateLambda3D
                 (undefined4 param_1,undefined4 param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  int *piVar10;
  float *pfVar11;
  int iVar12;
  int iVar13;
  double dVar14;
  double dVar15;
  undefined8 uVar16;
  
  uVar16 = FUN_97c1a25c();
  piVar10 = (int *)((ulonglong)uVar16 >> 0x20);
  pfVar11 = (float *)uVar16;
  fVar4 = pfVar11[3];
  iVar12 = param_3 * 0x10 + piVar10[3];
  iVar13 = param_3 * 0x10 + piVar10[3] + 0xc0;
  fVar5 = *pfVar11;
  fVar6 = pfVar11[1];
  iVar9 = *(int *)(param_3 * 4 + *piVar10);
  fVar1 = (float)(DOUBLE_97c30a60 / (double)(fVar4 + *(float *)(iVar12 + 0x4c)));
  fVar2 = (float)(DOUBLE_97c30a60 / (double)(fVar4 - *(float *)(iVar12 + 0x4c)));
  fVar3 = (float)(DOUBLE_97c30a60 / (double)(fVar4 + *(float *)(iVar13 + 0x4c)));
  fVar4 = (float)(DOUBLE_97c30a60 / (double)(fVar4 - *(float *)(iVar13 + 0x4c)));
  fVar8 = -((fVar6 - *(float *)(iVar12 + 0x44)) * fVar2 -
           (fVar6 + *(float *)(iVar12 + 0x44)) * fVar1) * *(float *)(iVar9 + 0x124);
  fVar7 = -((pfVar11[2] - *(float *)(iVar12 + 0x48)) * fVar2 -
           (pfVar11[2] + *(float *)(iVar12 + 0x48)) * fVar1) * *(float *)(iVar9 + 0x128);
  fVar2 = -((fVar5 - *(float *)(iVar12 + 0x40)) * fVar2 -
           (fVar5 + *(float *)(iVar12 + 0x40)) * fVar1) * *(float *)(iVar9 + 0x120);
  fVar7 = fVar7 * fVar7;
  fVar1 = -((fVar6 - *(float *)(iVar13 + 0x44)) * fVar4 -
           (fVar6 + *(float *)(iVar13 + 0x44)) * fVar3) * *(float *)(iVar9 + 0x124);
  fVar3 = -((fVar5 - *(float *)(iVar13 + 0x40)) * fVar4 -
           (fVar5 + *(float *)(iVar13 + 0x40)) * fVar3) * *(float *)(iVar9 + 0x120);
  dVar14 = (double)_sqrt((double)(fVar2 * fVar2 + fVar8 * fVar8 + fVar7));
  dVar15 = (double)_sqrt((double)(fVar3 * fVar3 + fVar1 * fVar1 + fVar7));
  fVar1 = (float)dVar15;
  if ((float)dVar15 < (float)dVar14) {
    fVar1 = (float)dVar14;
  }
  dVar14 = (double)_log2((double)(fVar1 * (float)piVar10[4]));
  return (double)(float)dVar14;
}

/* _InterpreterTextureSamplerSampleTexel1DFromLevel @ 0x97bd4210 (876 bytes) */
int _InterpreterTextureSamplerSampleTexel1DFromLevel(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  uint param_2;
  int param_3;
  float *param_4;
  float *param_5;
{
  bool bVar1;
  float fVar2;
  float fVar3;
  ushort uVar4;
  int iVar5;
  int *piVar6;
  float *pfVar7;
  int iVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  uint local_90;
  int local_8c;
  int local_88;
  longlong local_80;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  uint local_50;
  int local_4c;
  int local_48;
  undefined4 local_40;
  uint uStack_3c;
  
  if (7 < param_2) {
    param_2 = 7;
  }
  piVar6 = *(int **)(*param_1 + param_2 * 4);
  if (piVar6 == (int *)0x0) {
    return;
  }
  param_1[1] = (int)piVar6;
  pfVar7 = (float *)(piVar6 + param_3 * 0x34 + 0x48);
  param_1[2] = (int)pfVar7;
  if (param_1[8] == 0) {
    fVar2 = *param_4;
  }
  else {
    fVar2 = *param_4 / param_4[3];
  }
  iVar5 = *piVar6;
  uVar4 = *(ushort *)(iVar5 + 0x16);
  if (uVar4 == 0x2700) {
LAB_97bd42d8:
    if (*(short *)(iVar5 + 0x10) == -0x7ed3) {
      fVar3 = (float)piVar6[param_3 * 0x34 + 0x5c];
      iVar5 = param_3 * 0x34 + 100;
      iVar8 = piVar6[param_3 * 0x34 + 0x71];
    }
    else {
      fVar3 = *pfVar7;
      iVar5 = param_3 * 0x34 + 0x50;
      iVar8 = piVar6[param_3 * 0x34 + 0x70];
    }
    local_90 = (uint)(fVar2 * fVar3);
    local_80 = 0;
    local_8c = 0;
    local_88 = 0;
    ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(param_1,&local_90);
    ((int (*)())_InterpreterTextureSamplerLoadTexel1D)(param_1,iVar8,piVar6 + iVar5,&local_90,param_5);
    return;
  }
  if (uVar4 < 0x2701) {
    if (uVar4 == 0x2600) goto LAB_97bd42d8;
    bVar1 = uVar4 == 0x2601;
LAB_97bd42d0:
    if (!bVar1) {
      return;
    }
  }
  else {
    if (uVar4 == 0x2702) goto LAB_97bd42d8;
    if (0x2701 < uVar4) {
      bVar1 = uVar4 == 0x2703;
      goto LAB_97bd42d0;
    }
  }
  if (*(short *)(iVar5 + 0x10) == -0x7ed3) {
    fVar3 = (float)piVar6[param_3 * 0x34 + 0x5c];
    iVar5 = piVar6[param_3 * 0x34 + 0x71];
  }
  else {
    if (*(short *)(iVar5 + 0x10) != 0x2900) {
      fVar3 = *pfVar7;
      iVar8 = param_3 * 0x34 + 0x50;
      iVar5 = piVar6[param_3 * 0x34 + 0x70];
      goto LAB_97bd43d4;
    }
    fVar3 = (float)piVar6[param_3 * 0x34 + 0x5c];
    iVar5 = piVar6[param_3 * 0x34 + 0x72];
  }
  iVar8 = param_3 * 0x34 + 100;
LAB_97bd43d4:
  fVar2 = (float)((double)(fVar2 * fVar3) + DOUBLE_97c30a88);
  dVar11 = DOUBLE_97c30a88 + 0.0;
  dVar9 = DOUBLE_97c30a88 + 0.0;
  dVar10 = (double)_floor((double)fVar2);
  local_90 = (uint)dVar10;
  local_80 = (longlong)(int)local_90;
  dVar10 = (double)_floor((double)(float)dVar11);
  local_8c = (int)dVar10;
  local_80 = (longlong)local_8c;
  dVar10 = (double)_floor((double)(float)dVar9);
  dVar9 = DOUBLE_97c30a60;
  local_40 = 0x43300000;
  local_88 = (int)dVar10;
  local_80 = (longlong)local_88;
  uStack_3c = local_90 ^ 0x80000000;
  local_50 = local_90;
  local_4c = local_8c;
  dVar10 = (double)(fVar2 - (float)((double)CONCAT44(0x43300000,uStack_3c) - DOUBLE_97c30a58));
  local_48 = local_88;
  ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(param_1,&local_50);
  ((int (*)())_InterpreterTextureSamplerLoadTexel1D)(param_1,iVar5,piVar6 + iVar8,&local_50,&local_70);
  local_50 = local_90 - 1;
  fVar2 = (float)(dVar9 - dVar10);
  local_4c = local_8c;
  local_48 = local_88;
  ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(param_1,&local_50);
  ((int (*)())_InterpreterTextureSamplerLoadTexel1D)(param_1,iVar5,piVar6 + iVar8,&local_50,&local_60);
  *param_5 = (float)(dVar10 * (double)local_70 + (double)(fVar2 * local_60));
  param_5[3] = (float)(dVar10 * (double)local_64 + (double)(fVar2 * local_54));
  param_5[1] = (float)(dVar10 * (double)local_6c + (double)(fVar2 * local_5c));
  param_5[2] = (float)(dVar10 * (double)local_68 + (double)(fVar2 * local_58));
  return;
}

/* _InterpreterTextureSamplerSampleTexel2DFromLevel @ 0x97bd457c (1196 bytes) */
int _InterpreterTextureSamplerSampleTexel2DFromLevel(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  uint param_2;
  int param_3;
  float *param_4;
  float *param_5;
{
  bool bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  ushort uVar6;
  int *piVar7;
  int iVar8;
  int *piVar9;
  float *pfVar10;
  int iVar11;
  byte bVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  undefined8 uVar16;
  uint local_c0;
  uint local_bc;
  int local_b8;
  longlong local_b0;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  uint local_60;
  uint local_5c;
  int local_58;
  undefined4 local_50;
  uint uStack_4c;
  
  bVar12 = (7 < param_2) << 2;
  uVar16 = FUN_97c1a25c();
  piVar7 = (int *)((ulonglong)uVar16 >> 0x20);
  iVar8 = (int)uVar16;
  if ((bool)(bVar12 >> 2 & 1)) {
    iVar8 = 7;
  }
  piVar9 = *(int **)(*piVar7 + iVar8 * 4);
  if (piVar9 == (int *)0x0) {
    return;
  }
  piVar7[1] = (int)piVar9;
  pfVar10 = (float *)(piVar9 + param_3 * 0x34 + 0x48);
  piVar7[2] = (int)pfVar10;
  if (piVar7[8] == 0) {
    fVar3 = param_4[1];
    fVar2 = *param_4;
  }
  else {
    fVar3 = param_4[1] / param_4[3];
    fVar2 = *param_4 / param_4[3];
  }
  iVar8 = *piVar9;
  uVar6 = *(ushort *)(iVar8 + 0x16);
  if (uVar6 == 0x2700) {
LAB_97bd4648:
    if ((*(short *)(iVar8 + 0x10) == -0x7ed3) || (*(short *)(iVar8 + 0x12) == -0x7ed3)) {
      fVar5 = (float)piVar9[param_3 * 0x34 + 0x5c];
      iVar8 = param_3 * 0x34 + 100;
      iVar11 = piVar9[param_3 * 0x34 + 0x71];
      fVar4 = (float)piVar9[param_3 * 0x34 + 0x5d];
    }
    else {
      fVar5 = *pfVar10;
      iVar8 = param_3 * 0x34 + 0x50;
      iVar11 = piVar9[param_3 * 0x34 + 0x70];
      fVar4 = (float)piVar9[param_3 * 0x34 + 0x49];
    }
    local_c0 = (uint)(fVar2 * fVar5);
    local_bc = (uint)(fVar3 * fVar4);
    local_b0 = 0;
    local_b8 = 0;
    ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(piVar7,&local_c0);
    ((int (*)())_InterpreterTextureSamplerLoadTexel2D)(piVar7,iVar11,piVar9 + iVar8,&local_c0,param_5);
    return;
  }
  if (uVar6 < 0x2701) {
    if (uVar6 == 0x2600) goto LAB_97bd4648;
    bVar1 = uVar6 == 0x2601;
LAB_97bd4640:
    if (!bVar1) {
      return;
    }
  }
  else {
    if (uVar6 == 0x2702) goto LAB_97bd4648;
    if (0x2701 < uVar6) {
      bVar1 = uVar6 == 0x2703;
      goto LAB_97bd4640;
    }
  }
  if ((*(short *)(iVar8 + 0x10) == -0x7ed3) || (*(short *)(iVar8 + 0x12) == -0x7ed3)) {
    fVar4 = (float)piVar9[param_3 * 0x34 + 0x5c];
    iVar8 = piVar9[param_3 * 0x34 + 0x71];
  }
  else {
    if ((*(short *)(iVar8 + 0x10) != 0x2900) && (*(short *)(iVar8 + 0x12) != 0x2900)) {
      fVar4 = *pfVar10;
      iVar11 = param_3 * 0x34 + 0x50;
      iVar8 = piVar9[param_3 * 0x34 + 0x70];
      fVar5 = (float)piVar9[param_3 * 0x34 + 0x49];
      goto LAB_97bd479c;
    }
    fVar4 = (float)piVar9[param_3 * 0x34 + 0x5c];
    iVar8 = piVar9[param_3 * 0x34 + 0x72];
  }
  iVar11 = param_3 * 0x34 + 100;
  fVar5 = (float)piVar9[param_3 * 0x34 + 0x5d];
LAB_97bd479c:
  piVar9 = piVar9 + iVar11;
  fVar2 = (float)((double)(fVar2 * fVar4) + DOUBLE_97c30a88);
  dVar13 = DOUBLE_97c30a88 + 0.0;
  fVar3 = (float)((double)(fVar3 * fVar5) + DOUBLE_97c30a88);
  dVar14 = (double)_floor((double)fVar2);
  local_c0 = (uint)dVar14;
  local_b0 = (longlong)(int)local_c0;
  dVar14 = (double)_floor((double)fVar3);
  local_bc = (uint)dVar14;
  local_b0 = (longlong)(int)local_bc;
  dVar13 = (double)_floor((double)(float)dVar13);
  local_50 = 0x43300000;
  uStack_4c = local_bc ^ 0x80000000;
  local_5c = local_bc;
  local_60 = local_c0;
  dVar15 = (double)(fVar2 - (float)((double)CONCAT44(0x43300000,local_c0 ^ 0x80000000) -
                                   DOUBLE_97c30a58));
  dVar14 = (double)(fVar3 - (float)((double)CONCAT44(0x43300000,uStack_4c) - DOUBLE_97c30a58));
  local_b8 = (int)dVar13;
  local_b0 = (longlong)local_b8;
  fVar3 = (float)(dVar15 * dVar14);
  fVar2 = (float)((double)(float)(DOUBLE_97c30a60 - dVar15) * dVar14);
  fVar4 = (float)(dVar15 * (double)(float)(DOUBLE_97c30a60 - dVar14));
  fVar5 = (float)((double)(float)(DOUBLE_97c30a60 - dVar15) *
                 (double)(float)(DOUBLE_97c30a60 - dVar14));
  local_58 = local_b8;
  ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(piVar7,&local_60);
  ((int (*)())_InterpreterTextureSamplerLoadTexel2D)(piVar7,iVar8,piVar9,&local_60,&local_a0);
  local_60 = local_c0;
  local_5c = local_bc - 1;
  local_58 = local_b8;
  ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(piVar7,&local_60);
  ((int (*)())_InterpreterTextureSamplerLoadTexel2D)(piVar7,iVar8,piVar9,&local_60,&local_90);
  local_60 = local_c0 - 1;
  local_5c = local_bc - 1;
  local_58 = local_b8;
  ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(piVar7,&local_60);
  ((int (*)())_InterpreterTextureSamplerLoadTexel2D)(piVar7,iVar8,piVar9,&local_60,&local_70);
  local_60 = local_c0 - 1;
  local_5c = local_bc;
  local_58 = local_b8;
  ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(piVar7,&local_60);
  ((int (*)())_InterpreterTextureSamplerLoadTexel2D)(piVar7,iVar8,piVar9,&local_60,&local_80);
  *param_5 = fVar5 * local_70 + fVar2 * local_80 + fVar3 * local_a0 + fVar4 * local_90;
  param_5[3] = fVar5 * local_64 + fVar2 * local_74 + fVar3 * local_94 + fVar4 * local_84;
  param_5[1] = fVar5 * local_6c + fVar2 * local_7c + fVar3 * local_9c + fVar4 * local_8c;
  param_5[2] = fVar5 * local_68 + fVar2 * local_78 + fVar3 * local_98 + fVar4 * local_88;
  return;
}

/* _InterpreterTextureSamplerSampleTexel3DFromLevel @ 0x97bd4a28 (1768 bytes) */
int _InterpreterTextureSamplerSampleTexel3DFromLevel(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  uint param_2;
  int param_3;
  float *param_4;
  float *param_5;
{
  bool bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  ushort uVar10;
  int *piVar11;
  int iVar12;
  int *piVar13;
  float *pfVar14;
  int iVar15;
  byte bVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  undefined8 uVar24;
  float local_130;
  float local_12c;
  float local_128;
  uint local_120;
  uint local_11c;
  uint local_118;
  longlong local_110;
  float local_100;
  float local_fc;
  float local_f8;
  float local_f4;
  float local_f0;
  float local_ec;
  float local_e8;
  float local_e4;
  float local_e0;
  float local_dc;
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  uint local_80;
  uint local_7c;
  uint local_78;
  undefined4 local_70;
  uint uStack_6c;
  
  bVar16 = (7 < param_2) << 2;
  uVar24 = FUN_97c1a24c();
  piVar11 = (int *)((ulonglong)uVar24 >> 0x20);
  iVar12 = (int)uVar24;
  if ((bool)(bVar16 >> 2 & 1)) {
    iVar12 = 7;
  }
  piVar13 = *(int **)(*piVar11 + iVar12 * 4);
  if (piVar13 == (int *)0x0) {
    return;
  }
  piVar11[1] = (int)piVar13;
  pfVar14 = (float *)(piVar13 + param_3 * 0x34 + 0x48);
  piVar11[2] = (int)pfVar14;
  if (piVar11[8] == 0) {
    local_128 = param_4[2];
    local_130 = *param_4;
    local_12c = param_4[1];
  }
  else {
    local_12c = param_4[3];
    local_130 = *param_4 / local_12c;
    local_128 = param_4[2] / local_12c;
    local_12c = param_4[1] / local_12c;
  }
  iVar12 = *piVar13;
  uVar10 = *(ushort *)(iVar12 + 0x16);
  if (uVar10 == 0x2700) {
LAB_97bd4b08:
    if (((*(short *)(iVar12 + 0x10) == -0x7ed3) || (*(short *)(iVar12 + 0x12) == -0x7ed3)) ||
       (*(short *)(iVar12 + 0x14) == -0x7ed3)) {
      fVar8 = (float)piVar13[param_3 * 0x34 + 0x5c];
      iVar12 = param_3 * 0x34 + 100;
      iVar15 = piVar13[param_3 * 0x34 + 0x71];
      fVar9 = (float)piVar13[param_3 * 0x34 + 0x5d];
      fVar7 = (float)piVar13[param_3 * 0x34 + 0x5e];
    }
    else {
      fVar8 = *pfVar14;
      iVar12 = param_3 * 0x34 + 0x50;
      iVar15 = piVar13[param_3 * 0x34 + 0x70];
      fVar9 = (float)piVar13[param_3 * 0x34 + 0x49];
      fVar7 = (float)piVar13[param_3 * 0x34 + 0x4a];
    }
    local_120 = (uint)(local_130 * fVar8);
    local_11c = (uint)(local_12c * fVar9);
    local_118 = (uint)(local_128 * fVar7);
    local_110 = (longlong)(int)local_118;
    ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(piVar11,&local_120);
    ((int (*)())_InterpreterTextureSamplerLoadTexel3D)(piVar11,iVar15,piVar13 + iVar12,&local_120,param_5);
    return;
  }
  if (uVar10 < 0x2701) {
    if (uVar10 == 0x2600) goto LAB_97bd4b08;
    bVar1 = uVar10 == 0x2601;
LAB_97bd4b00:
    if (!bVar1) {
      return;
    }
  }
  else {
    if (uVar10 == 0x2702) goto LAB_97bd4b08;
    if (0x2701 < uVar10) {
      bVar1 = uVar10 == 0x2703;
      goto LAB_97bd4b00;
    }
  }
  if (((*(short *)(iVar12 + 0x10) == -0x7ed3) || (*(short *)(iVar12 + 0x12) == -0x7ed3)) ||
     (*(short *)(iVar12 + 0x14) == -0x7ed3)) {
    fVar7 = (float)piVar13[param_3 * 0x34 + 0x5c];
    iVar12 = piVar13[param_3 * 0x34 + 0x71];
  }
  else {
    if (((*(short *)(iVar12 + 0x10) != 0x2900) && (*(short *)(iVar12 + 0x12) != 0x2900)) &&
       (*(short *)(iVar12 + 0x14) != 0x2900)) {
      fVar7 = *pfVar14;
      iVar15 = param_3 * 0x34 + 0x50;
      iVar12 = piVar13[param_3 * 0x34 + 0x70];
      fVar8 = (float)piVar13[param_3 * 0x34 + 0x49];
      fVar9 = (float)piVar13[param_3 * 0x34 + 0x4a];
      goto LAB_97bd4cb4;
    }
    fVar7 = (float)piVar13[param_3 * 0x34 + 0x5c];
    iVar12 = piVar13[param_3 * 0x34 + 0x72];
  }
  iVar15 = param_3 * 0x34 + 100;
  fVar8 = (float)piVar13[param_3 * 0x34 + 0x5d];
  fVar9 = (float)piVar13[param_3 * 0x34 + 0x5e];
LAB_97bd4cb4:
  piVar13 = piVar13 + iVar15;
  fVar7 = (float)((double)(local_130 * fVar7) + DOUBLE_97c30a88);
  fVar8 = (float)((double)(local_12c * fVar8) + DOUBLE_97c30a88);
  fVar9 = (float)((double)(local_128 * fVar9) + DOUBLE_97c30a88);
  dVar17 = (double)_floor((double)fVar7);
  local_120 = (uint)dVar17;
  local_110 = (longlong)(int)local_120;
  dVar17 = (double)_floor((double)fVar8);
  local_11c = (uint)dVar17;
  local_110 = (longlong)(int)local_11c;
  dVar17 = (double)_floor((double)fVar9);
  local_118 = (uint)dVar17;
  local_110 = (longlong)(int)local_118;
  local_70 = 0x43300000;
  uStack_6c = local_118 ^ 0x80000000;
  local_7c = local_11c;
  dVar20 = (double)(fVar7 - (float)((double)CONCAT44(0x43300000,local_120 ^ 0x80000000) -
                                   DOUBLE_97c30a58));
  local_80 = local_120;
  dVar18 = (double)(fVar8 - (float)((double)CONCAT44(0x43300000,local_11c ^ 0x80000000) -
                                   DOUBLE_97c30a58));
  dVar17 = (double)(fVar9 - (float)((double)CONCAT44(0x43300000,uStack_6c) - DOUBLE_97c30a58));
  dVar22 = (double)(float)(DOUBLE_97c30a60 - dVar17);
  dVar21 = (double)(float)(dVar20 * (double)(float)(DOUBLE_97c30a60 - dVar18));
  dVar19 = (double)(float)((double)(float)(DOUBLE_97c30a60 - dVar20) * dVar18);
  dVar23 = (double)(float)((double)(float)(DOUBLE_97c30a60 - dVar20) *
                          (double)(float)(DOUBLE_97c30a60 - dVar18));
  fVar7 = (float)((double)(float)(dVar20 * dVar18) * dVar22);
  fVar9 = (float)(dVar19 * dVar22);
  fVar8 = (float)((double)(float)(dVar20 * dVar18) * dVar17);
  fVar2 = (float)(dVar19 * dVar17);
  fVar3 = (float)(dVar23 * dVar22);
  fVar4 = (float)(dVar23 * dVar17);
  fVar5 = (float)(dVar21 * dVar22);
  fVar6 = (float)(dVar21 * dVar17);
  local_78 = local_118;
  ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(piVar11,&local_80);
  ((int (*)())_InterpreterTextureSamplerLoadTexel3D)(piVar11,iVar12,piVar13,&local_80,&local_100);
  local_80 = local_120;
  local_7c = local_11c - 1;
  local_78 = local_118;
  ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(piVar11,&local_80);
  ((int (*)())_InterpreterTextureSamplerLoadTexel3D)(piVar11,iVar12,piVar13,&local_80,&local_f0);
  local_80 = local_120 - 1;
  local_7c = local_11c - 1;
  local_78 = local_118;
  ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(piVar11,&local_80);
  ((int (*)())_InterpreterTextureSamplerLoadTexel3D)(piVar11,iVar12,piVar13,&local_80,&local_d0);
  local_80 = local_120 - 1;
  local_7c = local_11c;
  local_78 = local_118;
  ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(piVar11,&local_80);
  ((int (*)())_InterpreterTextureSamplerLoadTexel3D)(piVar11,iVar12,piVar13,&local_80,&local_e0);
  local_78 = local_118 - 1;
  local_80 = local_120;
  local_7c = local_11c;
  ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(piVar11,&local_80);
  ((int (*)())_InterpreterTextureSamplerLoadTexel3D)(piVar11,iVar12,piVar13,&local_80,&local_c0);
  local_7c = local_11c - 1;
  local_78 = local_118 - 1;
  local_80 = local_120;
  ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(piVar11,&local_80);
  ((int (*)())_InterpreterTextureSamplerLoadTexel3D)(piVar11,iVar12,piVar13,&local_80,&local_b0);
  local_80 = local_120 - 1;
  local_7c = local_11c - 1;
  local_78 = local_118 - 1;
  ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(piVar11,&local_80);
  ((int (*)())_InterpreterTextureSamplerLoadTexel3D)(piVar11,iVar12,piVar13,&local_80,&local_90);
  local_80 = local_120 - 1;
  local_78 = local_118 - 1;
  local_7c = local_11c;
  ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(piVar11,&local_80);
  ((int (*)())_InterpreterTextureSamplerLoadTexel3D)(piVar11,iVar12,piVar13,&local_80,&local_a0);
  *param_5 = fVar3 * local_90 +
             fVar9 * local_a0 +
             fVar5 * local_b0 +
             fVar7 * local_c0 +
             fVar4 * local_d0 + fVar2 * local_e0 + fVar8 * local_100 + fVar6 * local_f0;
  param_5[1] = fVar3 * local_8c +
               fVar9 * local_9c +
               fVar5 * local_ac +
               fVar7 * local_bc +
               fVar4 * local_cc + fVar2 * local_dc + fVar8 * local_fc + fVar6 * local_ec;
  param_5[2] = fVar3 * local_88 +
               fVar9 * local_98 +
               fVar5 * local_a8 +
               fVar7 * local_b8 +
               fVar4 * local_c8 + fVar2 * local_d8 + fVar8 * local_f8 + fVar6 * local_e8;
  param_5[3] = fVar3 * local_84 +
               fVar9 * local_94 +
               fVar5 * local_a4 +
               fVar7 * local_b4 +
               fVar4 * local_c4 + fVar2 * local_d4 + fVar8 * local_f4 + fVar6 * local_e4;
  return;
}

/* _InterpreterTextureSamplerSampleTexelRECTFromLevel @ 0x97bd5110 (1056 bytes) */
int _InterpreterTextureSamplerSampleTexelRECTFromLevel(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  uint param_2;
  int param_3;
  float *param_4;
  float *param_5;
{
  bool bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  ushort uVar6;
  int *piVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  int iVar11;
  byte bVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  undefined8 uVar16;
  uint local_c0;
  uint local_bc;
  int local_b8;
  longlong local_b0;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  uint local_60;
  uint local_5c;
  int local_58;
  undefined4 local_50;
  uint uStack_4c;
  
  bVar12 = (7 < param_2) << 2;
  uVar16 = FUN_97c1a25c();
  piVar7 = (int *)((ulonglong)uVar16 >> 0x20);
  iVar8 = (int)uVar16;
  if ((bool)(bVar12 >> 2 & 1)) {
    iVar8 = 7;
  }
  piVar9 = *(int **)(*piVar7 + iVar8 * 4);
  if (piVar9 == (int *)0x0) {
    return;
  }
  piVar7[1] = (int)piVar9;
  piVar7[2] = (int)(piVar9 + param_3 * 0x34 + 0x48);
  iVar8 = *piVar9;
  uVar6 = *(ushort *)(iVar8 + 0x16);
  if (uVar6 == 0x2700) {
LAB_97bd51b8:
    if ((*(short *)(iVar8 + 0x10) == -0x7ed3) || (*(short *)(iVar8 + 0x12) == -0x7ed3)) {
      iVar8 = param_3 * 0x34 + 100;
      iVar11 = piVar9[param_3 * 0x34 + 0x71];
    }
    else {
      iVar11 = piVar9[param_3 * 0x34 + 0x70];
      iVar8 = param_3 * 0x34 + 0x50;
    }
    local_c0 = (uint)*param_4;
    local_bc = (uint)param_4[1];
    local_b0 = 0;
    local_b8 = 0;
    ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(piVar7,&local_c0);
    ((int (*)())_InterpreterTextureSamplerLoadTexel2D)(piVar7,iVar11,piVar9 + iVar8,&local_c0,param_5);
  }
  else {
    if (uVar6 < 0x2701) {
      if (uVar6 == 0x2600) goto LAB_97bd51b8;
      bVar1 = uVar6 == 0x2601;
LAB_97bd51b0:
      if (!bVar1) {
        return;
      }
    }
    else {
      if (uVar6 == 0x2702) goto LAB_97bd51b8;
      if (0x2701 < uVar6) {
        bVar1 = uVar6 == 0x2703;
        goto LAB_97bd51b0;
      }
    }
    if ((*(short *)(iVar8 + 0x10) == -0x7ed3) || (*(short *)(iVar8 + 0x12) == -0x7ed3)) {
      piVar10 = piVar9 + param_3 * 0x34 + 100;
      iVar8 = piVar9[param_3 * 0x34 + 0x71];
    }
    else if ((*(short *)(iVar8 + 0x10) == 0x2900) || (*(short *)(iVar8 + 0x12) == 0x2900)) {
      piVar10 = piVar9 + param_3 * 0x34 + 100;
      iVar8 = piVar9[param_3 * 0x34 + 0x72];
    }
    else {
      iVar8 = piVar9[param_3 * 0x34 + 0x70];
      piVar10 = piVar9 + param_3 * 0x34 + 0x50;
    }
    fVar4 = (float)((double)*param_4 + DOUBLE_97c30a88);
    dVar13 = DOUBLE_97c30a88 + 0.0;
    fVar5 = (float)((double)param_4[1] + DOUBLE_97c30a88);
    dVar14 = (double)_floor((double)fVar4);
    local_c0 = (uint)dVar14;
    local_b0 = (longlong)(int)local_c0;
    dVar14 = (double)_floor((double)fVar5);
    local_bc = (uint)dVar14;
    local_b0 = (longlong)(int)local_bc;
    dVar13 = (double)_floor((double)(float)dVar13);
    local_50 = 0x43300000;
    uStack_4c = local_bc ^ 0x80000000;
    local_5c = local_bc;
    local_60 = local_c0;
    dVar15 = (double)(fVar4 - (float)((double)CONCAT44(0x43300000,local_c0 ^ 0x80000000) -
                                     DOUBLE_97c30a58));
    dVar14 = (double)(fVar5 - (float)((double)CONCAT44(0x43300000,uStack_4c) - DOUBLE_97c30a58));
    local_b8 = (int)dVar13;
    local_b0 = (longlong)local_b8;
    fVar4 = (float)(dVar15 * dVar14);
    fVar5 = (float)((double)(float)(DOUBLE_97c30a60 - dVar15) * dVar14);
    fVar2 = (float)(dVar15 * (double)(float)(DOUBLE_97c30a60 - dVar14));
    fVar3 = (float)((double)(float)(DOUBLE_97c30a60 - dVar15) *
                   (double)(float)(DOUBLE_97c30a60 - dVar14));
    local_58 = local_b8;
    ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(piVar7,&local_60);
    ((int (*)())_InterpreterTextureSamplerLoadTexel2D)(piVar7,iVar8,piVar10,&local_60,&local_a0);
    local_60 = local_c0;
    local_5c = local_bc - 1;
    local_58 = local_b8;
    ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(piVar7,&local_60);
    ((int (*)())_InterpreterTextureSamplerLoadTexel2D)(piVar7,iVar8,piVar10,&local_60,&local_90);
    local_60 = local_c0 - 1;
    local_5c = local_bc - 1;
    local_58 = local_b8;
    ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(piVar7,&local_60);
    ((int (*)())_InterpreterTextureSamplerLoadTexel2D)(piVar7,iVar8,piVar10,&local_60,&local_70);
    local_60 = local_c0 - 1;
    local_5c = local_bc;
    local_58 = local_b8;
    ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(piVar7,&local_60);
    ((int (*)())_InterpreterTextureSamplerLoadTexel2D)(piVar7,iVar8,piVar10,&local_60,&local_80);
    *param_5 = fVar3 * local_70 + fVar5 * local_80 + fVar4 * local_a0 + fVar2 * local_90;
    param_5[3] = fVar3 * local_64 + fVar5 * local_74 + fVar4 * local_94 + fVar2 * local_84;
    param_5[1] = fVar3 * local_6c + fVar5 * local_7c + fVar4 * local_9c + fVar2 * local_8c;
    param_5[2] = fVar3 * local_68 + fVar5 * local_78 + fVar4 * local_98 + fVar2 * local_88;
  }
  return;
}

/* _InterpreterTextureSamplerLoadTexel1D @ 0x97bd5530 (172 bytes) */
int _InterpreterTextureSamplerLoadTexel1D(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  undefined4 param_3;
  int *param_4;
  undefined4 *param_5;
{
  undefined4 *puVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(*(int *)(param_1 + 4) + 0xae4);
  if (uVar2 < 0x8368) {
    if (0x8365 < uVar2) {
      return;
    }
    if (uVar2 != 0x1406) {
      if (uVar2 < 0x1407) {
        if (uVar2 == 0x1401) {
          return;
        }
      }
      else {
        if (uVar2 == 0x8033) {
          return;
        }
        if (uVar2 == 0x8363) {
          return;
        }
      }
    }
  }
  else {
    if (uVar2 == 0x8815) {
      return;
    }
    if ((0x8815 < uVar2) && (uVar2 - 0x881a < 2)) {
      return;
    }
  }
  puVar1 = (undefined4 *)(param_2 + *param_4 * 0x10);
  *param_5 = *puVar1;
  param_5[1] = puVar1[1];
  param_5[2] = puVar1[2];
  param_5[3] = puVar1[3];
  return;
}

/* _InterpreterTextureSamplerLoadTexel2D @ 0x97bd55dc (188 bytes) */
int _InterpreterTextureSamplerLoadTexel2D(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int *param_3;
  int *param_4;
  undefined4 *param_5;
{
  undefined4 *puVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(*(int *)(param_1 + 4) + 0xae4);
  if (uVar2 < 0x8368) {
    if (0x8365 < uVar2) {
      return;
    }
    if (uVar2 != 0x1406) {
      if (uVar2 < 0x1407) {
        if (uVar2 == 0x1401) {
          return;
        }
      }
      else {
        if (uVar2 == 0x8033) {
          return;
        }
        if (uVar2 == 0x8363) {
          return;
        }
      }
    }
  }
  else {
    if (uVar2 == 0x8815) {
      return;
    }
    if ((0x8815 < uVar2) && (uVar2 - 0x881a < 2)) {
      return;
    }
  }
  puVar1 = (undefined4 *)(param_2 + (param_4[1] * *param_3 + *param_4) * 0x10);
  *param_5 = *puVar1;
  param_5[1] = puVar1[1];
  param_5[2] = puVar1[2];
  param_5[3] = puVar1[3];
  return;
}

/* _InterpreterTextureSamplerLoadTexel3D @ 0x97bd5698 (204 bytes) */
int _InterpreterTextureSamplerLoadTexel3D(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int *param_3;
  int *param_4;
  undefined4 *param_5;
{
  undefined4 *puVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(*(int *)(param_1 + 4) + 0xae4);
  if (uVar2 < 0x8368) {
    if (0x8365 < uVar2) {
      return;
    }
    if (uVar2 != 0x1406) {
      if (uVar2 < 0x1407) {
        if (uVar2 == 0x1401) {
          return;
        }
      }
      else {
        if (uVar2 == 0x8033) {
          return;
        }
        if (uVar2 == 0x8363) {
          return;
        }
      }
    }
  }
  else {
    if (uVar2 == 0x8815) {
      return;
    }
    if ((0x8815 < uVar2) && (uVar2 - 0x881a < 2)) {
      return;
    }
  }
  puVar1 = (undefined4 *)
           (param_2 + ((param_4[2] * param_3[1] + param_4[1]) * *param_3 + *param_4) * 0x10);
  *param_5 = *puVar1;
  param_5[1] = puVar1[1];
  param_5[2] = puVar1[2];
  param_5[3] = puVar1[3];
  return;
}

/* _InterpreterNoiseGeneratorCreate @ 0x97bd5764 (60 bytes) */
int _InterpreterNoiseGeneratorCreate()
{
  void *pvVar1;
  
  pvVar1 = _calloc(0xa20,1);
  ((int (*)())_InterpreterNoiseGeneratorInitialise)();
  return pvVar1;
}

/* _InterpreterNoiseGeneratorInitialise @ 0x97bd57a0 (280 bytes) */
int _InterpreterNoiseGeneratorInitialise(param_1)
  undefined1 *param_1;
{
  undefined1 uVar1;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  uint uVar5;
  int iVar6;
  float *pfVar7;
  uint uVar8;
  undefined1 *puVar9;
  
  _memset(param_1,0,0xa20);
  dVar4 = DOUBLE_97c30a90;
  dVar3 = DOUBLE_97c30a58;
  uVar8 = 0;
  pfVar7 = (float *)(param_1 + 0x210);
  do {
    param_1[uVar8] = (char)uVar8;
    uVar5 = _random();
    uVar8 = uVar8 + 1;
    *pfVar7 = (float)(((double)CONCAT44(0x43300000,
                                        (uVar5 + (((int)uVar5 >> 9) +
                                                 (uint)((int)uVar5 < 0 && (uVar5 & 0x1ff) != 0)) *
                                                 -0x200) - 0x100 ^ 0x80000000) - dVar3) * dVar4);
    pfVar7 = pfVar7 + 1;
  } while (uVar8 < 0x100);
  puVar9 = param_1 + 0xff;
  do {
    uVar1 = *puVar9;
    uVar8 = _random();
    iVar6 = uVar8 + (((int)uVar8 >> 8) + (uint)((int)uVar8 < 0 && (uVar8 & 0xff) != 0)) * -0x100;
    *puVar9 = param_1[iVar6];
    puVar9 = puVar9 + -1;
    param_1[iVar6] = uVar1;
  } while (puVar9 != param_1);
  iVar6 = 0x102;
  puVar9 = param_1;
  do {
    uVar2 = *(undefined4 *)(puVar9 + 0x210);
    param_1[0x100] = *param_1;
    param_1 = param_1 + 1;
    *(undefined4 *)(puVar9 + 0x610) = uVar2;
    puVar9 = puVar9 + 4;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  return;
}

/* _InterpreterNoiseGeneratorSmoothHermiteCurve @ 0x97bd58bc (156 bytes) */
int _InterpreterNoiseGeneratorSmoothHermiteCurve(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  float *param_3;
{
  double dVar1;
  double dVar2;
  
  dVar1 = DOUBLE_97c30a80;
  dVar2 = (double)*param_2;
  *param_3 = (float)((double)(float)(dVar2 * dVar2) * (DOUBLE_97c30a80 - (dVar2 + dVar2)));
  dVar2 = (double)param_2[1];
  param_3[1] = (float)((double)(float)(dVar2 * dVar2) * (dVar1 - (dVar2 + dVar2)));
  dVar2 = (double)param_2[2];
  param_3[2] = (float)((double)(float)(dVar2 * dVar2) * (dVar1 - (dVar2 + dVar2)));
  dVar2 = (double)param_2[3];
  param_3[3] = (float)((double)(float)(dVar2 * dVar2) * (dVar1 - (dVar2 + dVar2)));
  return;
}

/* _InterpreterNoiseGeneratorInterpolate @ 0x97bd5958 (100 bytes) */
int _InterpreterNoiseGeneratorInterpolate(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  float *param_2;
  float *param_3;
  float *param_4;
  float *param_5;
{
  *param_5 = *param_4 * (*param_3 - *param_2) + *param_2;
  param_5[1] = param_4[1] * (param_3[1] - param_2[1]) + param_2[1];
  param_5[2] = param_4[2] * (param_3[2] - param_2[2]) + param_2[2];
  param_5[3] = param_4[3] * (param_3[3] - param_2[3]) + param_2[3];
  return;
}

/* _InterpreterNoiseGeneratorInterpolatedNoise1D @ 0x97bd59bc (476 bytes) */
double _InterpreterNoiseGeneratorInterpolatedNoise1D(int param_1,float *param_2)

{
  uint uVar1;
  double dVar2;
  double dVar3;
  float local_80;
  float local_7c;
  float local_78;
  undefined4 local_74;
  undefined4 local_70 [4];
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  float local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  float local_34;
  longlong local_30;
  undefined4 local_28;
  uint uStack_24;
  
  dVar2 = (double)_floor((double)*param_2);
  uVar1 = (uint)dVar2;
  local_30 = (longlong)(int)uVar1;
  dVar2 = (double)_floor((double)param_2[1]);
  local_30 = (longlong)(int)dVar2;
  dVar3 = (double)_floor((double)param_2[2]);
  local_30 = (longlong)(int)dVar3;
  local_28 = 0x43300000;
  uStack_24 = (int)dVar3 ^ 0x80000000;
  local_80 = *param_2 - (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - DOUBLE_97c30a58);
  local_78 = param_2[2] - (float)((double)CONCAT44(0x43300000,uStack_24) - DOUBLE_97c30a58);
  local_7c = param_2[1] -
             (float)((double)CONCAT44(0x43300000,(int)dVar2 ^ 0x80000000) - DOUBLE_97c30a58);
  local_74 = 0;
  ((int (*)())_InterpreterNoiseGeneratorSmoothHermiteCurve)(param_1,&local_80,local_70);
  local_50 = *(float *)((uint)*(byte *)(param_1 + (uVar1 & 0xff)) * 4 + param_1 + 0x210);
  local_4c = *(undefined4 *)
              ((uint)*(byte *)(param_1 + ((uVar1 & 0xff) + 1 & 0xff)) * 4 + param_1 + 0x210);
  local_38 = 0;
  local_48 = 0;
  local_44 = 0;
  local_3c = 0;
  local_54 = local_70[0];
  local_60 = local_70[0];
  local_5c = local_70[0];
  local_58 = local_70[0];
  local_40 = local_4c;
  local_34 = local_50;
  ((int (*)())_InterpreterNoiseGeneratorInterpolate)(param_1,&local_50,&local_40,&local_60,&local_50);
  return (double)local_50;
}

/* _InterpreterNoiseGeneratorInterpolatedNoise2D @ 0x97bd5b98 (544 bytes) */
double _InterpreterNoiseGeneratorInterpolatedNoise2D(int param_1,float *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  double dVar5;
  float local_80;
  float local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  float local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  float local_38;
  float local_34;
  longlong local_30;
  undefined4 local_28;
  uint uStack_24;
  
  dVar5 = (double)_floor((double)*param_2);
  uVar1 = (uint)dVar5;
  local_30 = (longlong)(int)uVar1;
  dVar5 = (double)_floor((double)param_2[1]);
  uVar2 = (uint)dVar5;
  local_30 = (longlong)(int)uVar2;
  local_28 = 0x43300000;
  uStack_24 = uVar2 ^ 0x80000000;
  uVar2 = uVar2 & 0xff;
  local_74 = 0;
  local_80 = *param_2 - (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - DOUBLE_97c30a58);
  local_7c = param_2[1] - (float)((double)CONCAT44(0x43300000,uStack_24) - DOUBLE_97c30a58);
  local_78 = 0;
  ((int (*)())_InterpreterNoiseGeneratorSmoothHermiteCurve)(param_1,&local_80,&local_70);
  uVar3 = (uint)*(byte *)(param_1 + (uVar1 & 0xff));
  uVar4 = (uint)*(byte *)(param_1 + ((uVar1 & 0xff) + 1 & 0xff));
  uVar1 = uVar2 + 1 & 0xff;
  local_50 = *(float *)(((uVar3 + uVar2) * 4 & 0x3fc) + param_1 + 0x210);
  local_4c = *(undefined4 *)(((uVar4 + uVar2) * 4 & 0x3fc) + param_1 + 0x210);
  local_48 = *(undefined4 *)(((uVar3 + uVar1) * 4 & 0x3fc) + param_1 + 0x210);
  local_44 = *(undefined4 *)(((uVar4 + uVar1) * 4 & 0x3fc) + param_1 + 0x210);
  local_54 = local_70;
  local_60 = local_70;
  local_5c = local_70;
  local_58 = local_70;
  local_40 = local_4c;
  local_3c = local_48;
  local_38 = (float)local_44;
  local_34 = local_50;
  ((int (*)())_InterpreterNoiseGeneratorInterpolate)(param_1,&local_50,&local_40,&local_60,&local_50);
  local_40 = local_48;
  local_3c = local_44;
  local_38 = local_50;
  local_34 = (float)local_4c;
  local_54 = local_6c;
  local_60 = local_6c;
  local_5c = local_6c;
  local_58 = local_6c;
  ((int (*)())_InterpreterNoiseGeneratorInterpolate)(param_1,&local_50,&local_40,&local_60,&local_50);
  return (double)local_50;
}

/* _InterpreterNoiseGeneratorInterpolatedNoise3D @ 0x97bd5db8 (784 bytes) */
double _InterpreterNoiseGeneratorInterpolatedNoise3D(int param_1,float *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  double dVar9;
  float local_80;
  float local_7c;
  float local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  float local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  float local_38;
  float local_34;
  longlong local_30;
  undefined4 local_28;
  uint uStack_24;
  
  dVar9 = (double)_floor((double)*param_2);
  uVar5 = (uint)dVar9;
  local_30 = (longlong)(int)uVar5;
  dVar9 = (double)_floor((double)param_2[1]);
  uVar7 = (uint)dVar9;
  local_30 = (longlong)(int)uVar7;
  dVar9 = (double)_floor((double)param_2[2]);
  uVar1 = (uint)dVar9;
  local_30 = (longlong)(int)uVar1;
  local_28 = 0x43300000;
  uStack_24 = uVar1 ^ 0x80000000;
  uVar1 = uVar1 & 0xff;
  uVar2 = uVar7 & 0xff;
  local_80 = *param_2 - (float)((double)CONCAT44(0x43300000,uVar5 ^ 0x80000000) - DOUBLE_97c30a58);
  local_78 = param_2[2] - (float)((double)CONCAT44(0x43300000,uStack_24) - DOUBLE_97c30a58);
  local_74 = 0;
  local_7c = param_2[1] - (float)((double)CONCAT44(0x43300000,uVar7 ^ 0x80000000) - DOUBLE_97c30a58)
  ;
  ((int (*)())_InterpreterNoiseGeneratorSmoothHermiteCurve)(param_1,&local_80,&local_70);
  uVar7 = uVar2 + 1 & 0xff;
  uVar3 = uVar1 + 1 & 0xff;
  iVar8 = (uint)*(byte *)(param_1 + (uVar5 & 0xff)) + param_1;
  uVar4 = (uint)*(byte *)(iVar8 + uVar2);
  uVar6 = (uint)*(byte *)(iVar8 + uVar7);
  local_50 = *(float *)(((uVar4 + uVar1) * 4 & 0x3fc) + param_1 + 0x210);
  local_4c = *(undefined4 *)(((uVar6 + uVar1) * 4 & 0x3fc) + param_1 + 0x210);
  local_48 = *(undefined4 *)(((uVar4 + uVar3) * 4 & 0x3fc) + param_1 + 0x210);
  local_44 = *(undefined4 *)(((uVar6 + uVar3) * 4 & 0x3fc) + param_1 + 0x210);
  iVar8 = (uint)*(byte *)(param_1 + ((uVar5 & 0xff) + 1 & 0xff)) + param_1;
  uVar5 = (uint)*(byte *)(iVar8 + uVar2);
  uVar7 = (uint)*(byte *)(iVar8 + uVar7);
  local_40 = *(undefined4 *)(((uVar5 + uVar1) * 4 & 0x3fc) + param_1 + 0x210);
  local_3c = *(undefined4 *)(((uVar7 + uVar1) * 4 & 0x3fc) + param_1 + 0x210);
  local_38 = *(float *)(((uVar5 + uVar3) * 4 & 0x3fc) + param_1 + 0x210);
  local_34 = *(float *)(((uVar7 + uVar3) * 4 & 0x3fc) + param_1 + 0x210);
  local_54 = local_70;
  local_60 = local_70;
  local_5c = local_70;
  local_58 = local_70;
  ((int (*)())_InterpreterNoiseGeneratorInterpolate)(param_1,&local_50,&local_40,&local_60,&local_50);
  local_40 = local_4c;
  local_3c = local_48;
  local_54 = local_6c;
  local_38 = (float)local_44;
  local_34 = local_50;
  local_60 = local_6c;
  local_5c = local_6c;
  local_58 = local_6c;
  ((int (*)())_InterpreterNoiseGeneratorInterpolate)(param_1,&local_50,&local_40,&local_60,&local_50);
  local_40 = local_48;
  local_3c = local_44;
  local_54 = local_68;
  local_38 = local_50;
  local_34 = (float)local_4c;
  local_60 = local_68;
  local_5c = local_68;
  local_58 = local_68;
  ((int (*)())_InterpreterNoiseGeneratorInterpolate)(param_1,&local_50,&local_40,&local_60,&local_50);
  return (double)local_50;
}

/* _InterpreterNoiseGeneratorCalculate1D @ 0x97bd60c8 (240 bytes) */
int _InterpreterNoiseGeneratorCalculate1D(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  float *param_3;
{
  float fVar1;
  double dVar2;
  uint uVar3;
  double dVar4;
  double dVar5;
  float local_60 [5];
  uint uStack_4c;
  
  dVar2 = DOUBLE_97c30a68;
  uStack_4c = 0;
  fVar1 = TAllocation__guardBlockSize;
  do {
    uVar3 = uStack_4c + 1;
    local_60[4] = 176.0;
    dVar4 = (double)_exp2((double)(float)((double)CONCAT44(0x43300000,uStack_4c) - dVar2));
    local_60[4] = 176.0;
    uStack_4c = uVar3;
    dVar5 = (double)_pow(DOUBLE_97c30a88,(double)CONCAT44(0x43300000,uVar3) - dVar2);
    local_60[0] = *param_2 * (float)dVar4;
    local_60[1] = 0.0;
    local_60[2] = 0.0;
    local_60[3] = 0.0;
    dVar4 = (double)((double (*)())_InterpreterNoiseGeneratorInterpolatedNoise1D)(param_1,local_60);
    fVar1 = (float)(dVar4 * (double)(float)dVar5 + (double)fVar1);
    uStack_4c = uVar3;
  } while (uVar3 < 8);
  param_3[3] = fVar1;
  *param_3 = fVar1;
  param_3[1] = fVar1;
  param_3[2] = fVar1;
  return;
}

/* _InterpreterNoiseGeneratorCalculate2D @ 0x97bd61b8 (248 bytes) */
int _InterpreterNoiseGeneratorCalculate2D(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  float *param_3;
{
  float fVar1;
  double dVar2;
  uint uVar3;
  double dVar4;
  double dVar5;
  float local_60;
  float local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  uint uStack_4c;
  
  dVar2 = DOUBLE_97c30a68;
  uStack_4c = 0;
  fVar1 = TAllocation__guardBlockSize;
  do {
    uVar3 = uStack_4c + 1;
    local_50 = 0x43300000;
    dVar4 = (double)_exp2((double)(float)((double)CONCAT44(0x43300000,uStack_4c) - dVar2));
    local_50 = 0x43300000;
    uStack_4c = uVar3;
    dVar5 = (double)_pow(DOUBLE_97c30a88,(double)CONCAT44(0x43300000,uVar3) - dVar2);
    local_60 = *param_2 * (float)dVar4;
    local_5c = param_2[1] * (float)dVar4;
    local_58 = 0;
    local_54 = 0;
    dVar4 = (double)((double (*)())_InterpreterNoiseGeneratorInterpolatedNoise2D)(param_1,&local_60);
    fVar1 = (float)(dVar4 * (double)(float)dVar5 + (double)fVar1);
    uStack_4c = uVar3;
  } while (uVar3 < 8);
  param_3[3] = fVar1;
  *param_3 = fVar1;
  param_3[1] = fVar1;
  param_3[2] = fVar1;
  return;
}

/* _InterpreterNoiseGeneratorCalculate3D @ 0x97bd62b0 (256 bytes) */
int _InterpreterNoiseGeneratorCalculate3D(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  float *param_3;
{
  float fVar1;
  float fVar2;
  double dVar3;
  uint uVar4;
  double dVar5;
  double dVar6;
  float local_60;
  float local_5c;
  float local_58;
  undefined4 local_54;
  undefined4 local_50;
  uint uStack_4c;
  
  dVar3 = DOUBLE_97c30a68;
  uStack_4c = 0;
  fVar1 = TAllocation__guardBlockSize;
  do {
    uVar4 = uStack_4c + 1;
    local_50 = 0x43300000;
    dVar5 = (double)_exp2((double)(float)((double)CONCAT44(0x43300000,uStack_4c) - dVar3));
    local_50 = 0x43300000;
    fVar2 = (float)dVar5;
    uStack_4c = uVar4;
    dVar5 = (double)_pow(DOUBLE_97c30a88,(double)CONCAT44(0x43300000,uVar4) - dVar3);
    local_60 = *param_2 * fVar2;
    local_5c = param_2[1] * fVar2;
    local_58 = param_2[2] * fVar2;
    local_54 = 0;
    dVar6 = (double)((double (*)())_InterpreterNoiseGeneratorInterpolatedNoise3D)(param_1,&local_60);
    fVar1 = (float)(dVar6 * (double)(float)dVar5 + (double)fVar1);
    uStack_4c = uVar4;
  } while (uVar4 < 8);
  param_3[3] = fVar1;
  *param_3 = fVar1;
  param_3[1] = fVar1;
  param_3[2] = fVar1;
  return;
}

/* _InterpreterRasterOpMachineCreate @ 0x97bd63b4 (60 bytes) */
int _InterpreterRasterOpMachineCreate()
{
  void *pvVar1;
  
  pvVar1 = _calloc(8,1);
  ((int (*)())_InterpreterRasterOpMachineInitialise)();
  return pvVar1;
}

/* _InterpreterRasterOpMachineInitialise @ 0x97bd63f0 (16 bytes) */
int _InterpreterRasterOpMachineInitialise(param_1)
  undefined4 *param_1;
{
  param_1[1] = 0;
  *param_1 = 0;
  return;
}

/* _InterpreterRasterOpMachineAttachEmulatorContext @ 0x97bd6404 (8 bytes) */
int _InterpreterRasterOpMachineAttachEmulatorContext(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  *param_1 = param_2;
  return;
}

/* _InterpreterRasterOpMachineAttachRuntimeCompiler @ 0x97bd640c (8 bytes) */
int _InterpreterRasterOpMachineAttachRuntimeCompiler(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(param_1 + 4) = param_2;
  return;
}

/* _InterpreterRasterOpMachine_DepthTest @ 0x97bd6414 (236 bytes) */
int _InterpreterRasterOpMachine_DepthTest(param_1)
  int *param_1;
{
  float fVar1;
  int iVar2;
  float *pfVar3;
  bool bVar4;
  
  iVar2 = *param_1;
  fVar1 = *(float *)(*(int *)(iVar2 + 0xdf0) + 0xa38);
  pfVar3 = *(float **)(iVar2 + 0xda8);
  switch(*(uint *)(*(int *)(iVar2 + 0xd80) + 0x50) & 7) {
  case 0:
    return true;
  case 1:
    bVar4 = fVar1 < *pfVar3;
    break;
  case 2:
    return fVar1 != *pfVar3;
  case 3:
    bVar4 = fVar1 <= *pfVar3;
    break;
  case 4:
    bVar4 = *pfVar3 < fVar1;
    break;
  case 5:
    return fVar1 == *pfVar3;
  case 6:
    bVar4 = *pfVar3 <= fVar1;
    break;
  default:
    return false;
  }
  return (bool)(bVar4 ^ 1);
}

