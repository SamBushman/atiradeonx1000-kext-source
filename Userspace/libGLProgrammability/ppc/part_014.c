#include "decls.h"

/* _InterpreterTextureSamplerAttachDerivatives @ 0x97bd3614 (12 bytes) */
void _InterpreterTextureSamplerAttachDerivatives(int param_1,undefined4 param_2,double fparam_1)
{
  *(float *)(param_1 + 0x10) = (float)fparam_1;
  *(undefined4 *)(param_1 + 0xc) = param_2;
  return;
}

/* _InterpreterTextureSamplerSampleTexel1D @ 0x97bd3620 (512 bytes) */
void _InterpreterTextureSamplerSampleTexel1D(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,float *param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12)
{
  float fVar1;
  int *piVar2;
  uint uVar3;
  double dVar4;
  double fparam_1_00;
  double in_stack_ffffff48;
  double in_stack_ffffff50;
  double in_stack_ffffff58;
  double in_stack_ffffff60;
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
  
  piVar2 = *(int **)(*param_1 + param_2 * 4);
  if (*(ushort *)(*piVar2 + 0x16) - 0x2700 < 4) {
    param_1[10] = 1;
    dVar4 = (double)((double (*)())_InterpreterTextureSamplerCalculateLambda1D)(param_1,param_4,param_2,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
                               fparam_6,fparam_7,fparam_8,in_stack_ffffff48,in_stack_ffffff50,
                               in_stack_ffffff58,in_stack_ffffff60);
    local_40 = (float)((double)(float)(dVar4 + (double)GH_U2F((unsigned int)(piVar2[0x10]))) + fparam_1);
    if (local_40 < GH_U2F((unsigned int)(piVar2[0xc]))) {
      local_40 = GH_U2F((unsigned int)(piVar2[0xc]));
    }
    fparam_1 = (double)local_40;
    dVar4 = fparam_1;
    if ((double)GH_U2F((unsigned int)(piVar2[8])) < fparam_1) {
      dVar4 = (double)GH_U2F((unsigned int)(piVar2[8]));
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
      fparam_1_00 = (double)((double (*)())_InterpreterTextureSamplerSampleTexel1DFromLevel)(param_1,param_2,uVar3,param_4,&local_80,fparam_1,fparam_2,
                                       fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,
                                       in_stack_ffffff48,in_stack_ffffff50,in_stack_ffffff58);
      ((double (*)())_InterpreterTextureSamplerSampleTexel1DFromLevel)(param_1,param_2,uVar3 + 1,param_4,&local_70,fparam_1_00,fparam_2,fparam_3,fparam_4,
                 fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffff48,in_stack_ffffff50,
                 in_stack_ffffff58);
      dVar4 = (double)(float)(dVar4 - (double)(float)((double)CONCAT44(0x43300000,uVar3) -
                                                     DOUBLE_97c30a68));
      fVar1 = (float)(DOUBLE_97c30a60 - dVar4);
      *param_5 = fVar1 * local_80 + (float)(dVar4 * (double)local_70);
      param_5[3] = fVar1 * local_74 + (float)(dVar4 * (double)local_64);
      param_5[1] = fVar1 * local_7c + (float)(dVar4 * (double)local_6c);
      param_5[2] = fVar1 * local_78 + (float)(dVar4 * (double)local_68);
      return;
    }
  }
  else {
    uVar3 = 0;
    param_1[10] = 0;
  }
  ((double (*)())_InterpreterTextureSamplerSampleTexel1DFromLevel)(param_1,param_2,uVar3,param_4,param_5,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
             fparam_6,fparam_7,fparam_8,in_stack_ffffff48,in_stack_ffffff50,in_stack_ffffff58);
  return;
}

/* _InterpreterTextureSamplerSampleTexel2D @ 0x97bd3820 (512 bytes) */
void _InterpreterTextureSamplerSampleTexel2D(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,float *param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
  int *piVar2;
  uint uVar3;
  double dVar4;
  double fparam_1_00;
  double in_stack_ffffff48;
  double in_stack_ffffff50;
  double in_stack_ffffff58;
  double in_stack_ffffff60;
  double in_stack_ffffff68;
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
  
  piVar2 = *(int **)(*param_1 + param_2 * 4);
  if (*(ushort *)(*piVar2 + 0x16) - 0x2700 < 4) {
    param_1[10] = 1;
    dVar4 = (double)((double (*)())_InterpreterTextureSamplerCalculateLambda2D)(param_1,param_4,param_2,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
                               fparam_6,fparam_7,fparam_8,in_stack_ffffff48,in_stack_ffffff50,
                               in_stack_ffffff58,in_stack_ffffff60);
    local_40 = (float)((double)(float)(dVar4 + (double)GH_U2F((unsigned int)(piVar2[0x10]))) + fparam_1);
    if (local_40 < GH_U2F((unsigned int)(piVar2[0xc]))) {
      local_40 = GH_U2F((unsigned int)(piVar2[0xc]));
    }
    fparam_1 = (double)local_40;
    dVar4 = fparam_1;
    if ((double)GH_U2F((unsigned int)(piVar2[8])) < fparam_1) {
      dVar4 = (double)GH_U2F((unsigned int)(piVar2[8]));
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
      fparam_1_00 = (double)((double (*)())_InterpreterTextureSamplerSampleTexel2DFromLevel)(param_1,param_2,uVar3,param_4,&local_80,fparam_1,fparam_2,
                                       fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,
                                       in_stack_ffffff48,in_stack_ffffff50,in_stack_ffffff58,
                                       in_stack_ffffff60,in_stack_ffffff68);
      ((double (*)())_InterpreterTextureSamplerSampleTexel2DFromLevel)(param_1,param_2,uVar3 + 1,param_4,&local_70,fparam_1_00,fparam_2,fparam_3,fparam_4,
                 fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffff48,in_stack_ffffff50,
                 in_stack_ffffff58,in_stack_ffffff60,in_stack_ffffff68);
      dVar4 = (double)(float)(dVar4 - (double)(float)((double)CONCAT44(0x43300000,uVar3) -
                                                     DOUBLE_97c30a68));
      fVar1 = (float)(DOUBLE_97c30a60 - dVar4);
      *param_5 = fVar1 * local_80 + (float)(dVar4 * (double)local_70);
      param_5[3] = fVar1 * local_74 + (float)(dVar4 * (double)local_64);
      param_5[1] = fVar1 * local_7c + (float)(dVar4 * (double)local_6c);
      param_5[2] = fVar1 * local_78 + (float)(dVar4 * (double)local_68);
      return;
    }
  }
  else {
    uVar3 = 0;
    param_1[10] = 0;
  }
  ((double (*)())_InterpreterTextureSamplerSampleTexel2DFromLevel)(param_1,param_2,uVar3,param_4,param_5,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
             fparam_6,fparam_7,fparam_8,in_stack_ffffff48,in_stack_ffffff50,in_stack_ffffff58,
             in_stack_ffffff60,in_stack_ffffff68);
  return;
}

/* _InterpreterTextureSamplerSampleTexel3D @ 0x97bd3a20 (512 bytes) */
void _InterpreterTextureSamplerSampleTexel3D(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,float *param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12)
{
  float fVar1;
  int *piVar2;
  uint uVar3;
  double dVar4;
  double fparam_1_00;
  double in_stack_ffffff48;
  double in_stack_ffffff50;
  double in_stack_ffffff58;
  double in_stack_ffffff60;
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
  
  piVar2 = *(int **)(*param_1 + param_2 * 4);
  if (*(ushort *)(*piVar2 + 0x16) - 0x2700 < 4) {
    param_1[10] = 1;
    dVar4 = (double)((double (*)())_InterpreterTextureSamplerCalculateLambda3D)(param_1,param_4,param_2,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
                               fparam_6,fparam_7,fparam_8,in_stack_ffffff48,in_stack_ffffff50,
                               in_stack_ffffff58,in_stack_ffffff60);
    local_40 = (float)((double)(float)(dVar4 + (double)GH_U2F((unsigned int)(piVar2[0x10]))) + fparam_1);
    if (local_40 < GH_U2F((unsigned int)(piVar2[0xc]))) {
      local_40 = GH_U2F((unsigned int)(piVar2[0xc]));
    }
    fparam_1 = (double)local_40;
    dVar4 = fparam_1;
    if ((double)GH_U2F((unsigned int)(piVar2[8])) < fparam_1) {
      dVar4 = (double)GH_U2F((unsigned int)(piVar2[8]));
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
      fparam_1_00 = (double)((double (*)())_InterpreterTextureSamplerSampleTexel3DFromLevel)(param_1,param_2,uVar3,param_4,&local_80,fparam_1,fparam_2,
                                       fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,
                                       in_stack_ffffff48,in_stack_ffffff50,in_stack_ffffff58);
      ((double (*)())_InterpreterTextureSamplerSampleTexel3DFromLevel)(param_1,param_2,uVar3 + 1,param_4,&local_70,fparam_1_00,fparam_2,fparam_3,fparam_4,
                 fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffff48,in_stack_ffffff50,
                 in_stack_ffffff58);
      dVar4 = (double)(float)(dVar4 - (double)(float)((double)CONCAT44(0x43300000,uVar3) -
                                                     DOUBLE_97c30a68));
      fVar1 = (float)(DOUBLE_97c30a60 - dVar4);
      *param_5 = fVar1 * local_80 + (float)(dVar4 * (double)local_70);
      param_5[3] = fVar1 * local_74 + (float)(dVar4 * (double)local_64);
      param_5[1] = fVar1 * local_7c + (float)(dVar4 * (double)local_6c);
      param_5[2] = fVar1 * local_78 + (float)(dVar4 * (double)local_68);
      return;
    }
  }
  else {
    uVar3 = 0;
    param_1[10] = 0;
  }
  ((double (*)())_InterpreterTextureSamplerSampleTexel3DFromLevel)(param_1,param_2,uVar3,param_4,param_5,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
             fparam_6,fparam_7,fparam_8,in_stack_ffffff48,in_stack_ffffff50,in_stack_ffffff58);
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
double _InterpreterTextureSamplerCalculateLambda1D(int *param_1,float *param_2,int param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12)
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
  dVar10 = _sqrt((double)(fVar2 * fVar2));
  dVar11 = _sqrt((double)(fVar7 * fVar7));
  fVar1 = (float)dVar11;
  if ((float)dVar11 < (float)dVar10) {
    fVar1 = (float)dVar10;
  }
  dVar10 = _log2((double)(fVar1 * GH_U2F((unsigned int)(param_1[4]))));
  return (double)(float)dVar10;
}

/* _InterpreterTextureSamplerCalculateLambda2D @ 0x97bd3f4c (348 bytes) */
double _InterpreterTextureSamplerCalculateLambda2D(int *param_1,float *param_2,int param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12)
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
  dVar13 = _sqrt((double)(fVar1 * fVar1 + fVar9 * fVar9));
  dVar14 = _sqrt((double)(fVar8 * fVar8 + fVar7 * fVar7));
  fVar1 = (float)dVar14;
  if ((float)dVar14 < (float)dVar13) {
    fVar1 = (float)dVar13;
  }
  dVar13 = _log2((double)(fVar1 * GH_U2F((unsigned int)(param_1[4]))));
  return (double)(float)dVar13;
}

/* _InterpreterTextureSamplerCalculateLambda3D @ 0x97bd40a8 (360 bytes) */
double _InterpreterTextureSamplerCalculateLambda3D(int *param_1,float *param_2,int param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12)
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
  int iVar10;
  int iVar11;
  double dVar12;
  double dVar13;
  
  fVar4 = param_2[3];
  iVar10 = param_3 * 0x10 + param_1[3];
  iVar11 = param_3 * 0x10 + param_1[3] + 0xc0;
  fVar5 = *param_2;
  fVar6 = param_2[1];
  iVar9 = *(int *)(param_3 * 4 + *param_1);
  fVar1 = (float)(DOUBLE_97c30a60 / (double)(fVar4 + *(float *)(iVar10 + 0x4c)));
  fVar2 = (float)(DOUBLE_97c30a60 / (double)(fVar4 - *(float *)(iVar10 + 0x4c)));
  fVar3 = (float)(DOUBLE_97c30a60 / (double)(fVar4 + *(float *)(iVar11 + 0x4c)));
  fVar4 = (float)(DOUBLE_97c30a60 / (double)(fVar4 - *(float *)(iVar11 + 0x4c)));
  fVar7 = -((fVar6 - *(float *)(iVar10 + 0x44)) * fVar2 -
           (fVar6 + *(float *)(iVar10 + 0x44)) * fVar1) * *(float *)(iVar9 + 0x124);
  fVar8 = -((param_2[2] - *(float *)(iVar10 + 0x48)) * fVar2 -
           (param_2[2] + *(float *)(iVar10 + 0x48)) * fVar1) * *(float *)(iVar9 + 0x128);
  fVar2 = -((fVar5 - *(float *)(iVar10 + 0x40)) * fVar2 -
           (fVar5 + *(float *)(iVar10 + 0x40)) * fVar1) * *(float *)(iVar9 + 0x120);
  fVar8 = fVar8 * fVar8;
  fVar1 = -((fVar6 - *(float *)(iVar11 + 0x44)) * fVar4 -
           (fVar6 + *(float *)(iVar11 + 0x44)) * fVar3) * *(float *)(iVar9 + 0x124);
  fVar3 = -((fVar5 - *(float *)(iVar11 + 0x40)) * fVar4 -
           (fVar5 + *(float *)(iVar11 + 0x40)) * fVar3) * *(float *)(iVar9 + 0x120);
  dVar12 = _sqrt((double)(fVar2 * fVar2 + fVar7 * fVar7 + fVar8));
  dVar13 = _sqrt((double)(fVar3 * fVar3 + fVar1 * fVar1 + fVar8));
  fVar1 = (float)dVar13;
  if ((float)dVar13 < (float)dVar12) {
    fVar1 = (float)dVar12;
  }
  dVar12 = _log2((double)(fVar1 * GH_U2F((unsigned int)(param_1[4]))));
  return (double)(float)dVar12;
}

/* _InterpreterTextureSamplerSampleTexel1DFromLevel @ 0x97bd4210 (876 bytes) */
double _InterpreterTextureSamplerSampleTexel1DFromLevel(int *param_1,uint param_2,int param_3,float *param_4,float *param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11)
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
    return fparam_1;
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
      fVar3 = GH_U2F((unsigned int)(piVar6[param_3 * 0x34 + 0x5c]));
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
    dVar9 = (double)((int (*)())_InterpreterTextureSamplerLoadTexel1D)(param_1,iVar8,piVar6 + iVar5,&local_90,param_5);
    return dVar9;
  }
  if (uVar4 < 0x2701) {
    if (uVar4 == 0x2600) goto LAB_97bd42d8;
    bVar1 = uVar4 == 0x2601;
LAB_97bd42d0:
    if (!bVar1) {
      return fparam_1;
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
    fVar3 = GH_U2F((unsigned int)(piVar6[param_3 * 0x34 + 0x5c]));
    iVar5 = piVar6[param_3 * 0x34 + 0x71];
  }
  else {
    if (*(short *)(iVar5 + 0x10) != 0x2900) {
      fVar3 = *pfVar7;
      iVar8 = param_3 * 0x34 + 0x50;
      iVar5 = piVar6[param_3 * 0x34 + 0x70];
      goto LAB_97bd43d4;
    }
    fVar3 = GH_U2F((unsigned int)(piVar6[param_3 * 0x34 + 0x5c]));
    iVar5 = piVar6[param_3 * 0x34 + 0x72];
  }
  iVar8 = param_3 * 0x34 + 100;
LAB_97bd43d4:
  fVar2 = (float)((double)(fVar2 * fVar3) + DOUBLE_97c30a88);
  dVar11 = DOUBLE_97c30a88 + 0.0;
  dVar9 = DOUBLE_97c30a88 + 0.0;
  dVar10 = _floor((double)fVar2);
  local_90 = (uint)dVar10;
  local_80 = (longlong)(int)local_90;
  dVar10 = _floor((double)(float)dVar11);
  local_8c = (int)dVar10;
  local_80 = (longlong)local_8c;
  dVar10 = _floor((double)(float)dVar9);
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
  dVar9 = (double)((int (*)())_InterpreterTextureSamplerLoadTexel1D)(param_1,iVar5,piVar6 + iVar8,&local_50,&local_60);
  *param_5 = (float)(dVar10 * (double)local_70 + (double)(fVar2 * local_60));
  param_5[3] = (float)(dVar10 * (double)local_64 + (double)(fVar2 * local_54));
  param_5[1] = (float)(dVar10 * (double)local_6c + (double)(fVar2 * local_5c));
  param_5[2] = (float)(dVar10 * (double)local_68 + (double)(fVar2 * local_58));
  return dVar9;
}

/* _InterpreterTextureSamplerSampleTexel2DFromLevel @ 0x97bd457c (1196 bytes) */
double _InterpreterTextureSamplerSampleTexel2DFromLevel(int *param_1,uint param_2,int param_3,float *param_4,float *param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  bool bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  ushort uVar6;
  int *piVar7;
  int iVar8;
  float *pfVar9;
  int iVar10;
  double dVar11;
  double dVar12;
  double dVar13;
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
  
  if (7 < param_2) {
    param_2 = 7;
  }
  piVar7 = *(int **)(*param_1 + param_2 * 4);
  if (piVar7 == (int *)0x0) {
    return fparam_1;
  }
  param_1[1] = (int)piVar7;
  pfVar9 = (float *)(piVar7 + param_3 * 0x34 + 0x48);
  param_1[2] = (int)pfVar9;
  if (param_1[8] == 0) {
    fVar3 = param_4[1];
    fVar2 = *param_4;
  }
  else {
    fVar3 = param_4[1] / param_4[3];
    fVar2 = *param_4 / param_4[3];
  }
  iVar8 = *piVar7;
  uVar6 = *(ushort *)(iVar8 + 0x16);
  if (uVar6 == 0x2700) {
LAB_97bd4648:
    if ((*(short *)(iVar8 + 0x10) == -0x7ed3) || (*(short *)(iVar8 + 0x12) == -0x7ed3)) {
      fVar5 = GH_U2F((unsigned int)(piVar7[param_3 * 0x34 + 0x5c]));
      iVar8 = param_3 * 0x34 + 100;
      iVar10 = piVar7[param_3 * 0x34 + 0x71];
      fVar4 = GH_U2F((unsigned int)(piVar7[param_3 * 0x34 + 0x5d]));
    }
    else {
      fVar5 = *pfVar9;
      iVar8 = param_3 * 0x34 + 0x50;
      iVar10 = piVar7[param_3 * 0x34 + 0x70];
      fVar4 = GH_U2F((unsigned int)(piVar7[param_3 * 0x34 + 0x49]));
    }
    local_c0 = (uint)(fVar2 * fVar5);
    local_bc = (uint)(fVar3 * fVar4);
    local_b0 = 0;
    local_b8 = 0;
    ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(param_1,&local_c0);
    dVar11 = (double)((int (*)())_InterpreterTextureSamplerLoadTexel2D)(param_1,iVar10,piVar7 + iVar8,&local_c0,param_5);
    return dVar11;
  }
  if (uVar6 < 0x2701) {
    if (uVar6 == 0x2600) goto LAB_97bd4648;
    bVar1 = uVar6 == 0x2601;
LAB_97bd4640:
    if (!bVar1) {
      return fparam_1;
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
    fVar4 = GH_U2F((unsigned int)(piVar7[param_3 * 0x34 + 0x5c]));
    iVar8 = piVar7[param_3 * 0x34 + 0x71];
  }
  else {
    if ((*(short *)(iVar8 + 0x10) != 0x2900) && (*(short *)(iVar8 + 0x12) != 0x2900)) {
      fVar4 = *pfVar9;
      iVar10 = param_3 * 0x34 + 0x50;
      iVar8 = piVar7[param_3 * 0x34 + 0x70];
      fVar5 = GH_U2F((unsigned int)(piVar7[param_3 * 0x34 + 0x49]));
      goto LAB_97bd479c;
    }
    fVar4 = GH_U2F((unsigned int)(piVar7[param_3 * 0x34 + 0x5c]));
    iVar8 = piVar7[param_3 * 0x34 + 0x72];
  }
  iVar10 = param_3 * 0x34 + 100;
  fVar5 = GH_U2F((unsigned int)(piVar7[param_3 * 0x34 + 0x5d]));
LAB_97bd479c:
  piVar7 = piVar7 + iVar10;
  fVar2 = (float)((double)(fVar2 * fVar4) + DOUBLE_97c30a88);
  dVar11 = DOUBLE_97c30a88 + 0.0;
  fVar3 = (float)((double)(fVar3 * fVar5) + DOUBLE_97c30a88);
  dVar12 = _floor((double)fVar2);
  local_c0 = (uint)dVar12;
  local_b0 = (longlong)(int)local_c0;
  dVar12 = _floor((double)fVar3);
  local_bc = (uint)dVar12;
  local_b0 = (longlong)(int)local_bc;
  dVar11 = _floor((double)(float)dVar11);
  local_50 = 0x43300000;
  uStack_4c = local_bc ^ 0x80000000;
  local_5c = local_bc;
  local_60 = local_c0;
  dVar13 = (double)(fVar2 - (float)((double)CONCAT44(0x43300000,local_c0 ^ 0x80000000) -
                                   DOUBLE_97c30a58));
  dVar12 = (double)(fVar3 - (float)((double)CONCAT44(0x43300000,uStack_4c) - DOUBLE_97c30a58));
  local_b8 = (int)dVar11;
  local_b0 = (longlong)local_b8;
  fVar3 = (float)(dVar13 * dVar12);
  fVar2 = (float)((double)(float)(DOUBLE_97c30a60 - dVar13) * dVar12);
  fVar4 = (float)(dVar13 * (double)(float)(DOUBLE_97c30a60 - dVar12));
  fVar5 = (float)((double)(float)(DOUBLE_97c30a60 - dVar13) *
                 (double)(float)(DOUBLE_97c30a60 - dVar12));
  local_58 = local_b8;
  ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(param_1,&local_60);
  ((int (*)())_InterpreterTextureSamplerLoadTexel2D)(param_1,iVar8,piVar7,&local_60,&local_a0);
  local_60 = local_c0;
  local_5c = local_bc - 1;
  local_58 = local_b8;
  ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(param_1,&local_60);
  ((int (*)())_InterpreterTextureSamplerLoadTexel2D)(param_1,iVar8,piVar7,&local_60,&local_90);
  local_60 = local_c0 - 1;
  local_5c = local_bc - 1;
  local_58 = local_b8;
  ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(param_1,&local_60);
  ((int (*)())_InterpreterTextureSamplerLoadTexel2D)(param_1,iVar8,piVar7,&local_60,&local_70);
  local_60 = local_c0 - 1;
  local_5c = local_bc;
  local_58 = local_b8;
  ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(param_1,&local_60);
  dVar11 = (double)((int (*)())_InterpreterTextureSamplerLoadTexel2D)(param_1,iVar8,piVar7,&local_60,&local_80);
  *param_5 = fVar5 * local_70 + fVar2 * local_80 + fVar3 * local_a0 + fVar4 * local_90;
  param_5[3] = fVar5 * local_64 + fVar2 * local_74 + fVar3 * local_94 + fVar4 * local_84;
  param_5[1] = fVar5 * local_6c + fVar2 * local_7c + fVar3 * local_9c + fVar4 * local_8c;
  param_5[2] = fVar5 * local_68 + fVar2 * local_78 + fVar3 * local_98 + fVar4 * local_88;
  return dVar11;
}

/* _InterpreterTextureSamplerSampleTexel3DFromLevel @ 0x97bd4a28 (1768 bytes) */
double _InterpreterTextureSamplerSampleTexel3DFromLevel(int *param_1,uint param_2,int param_3,float *param_4,float *param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11)
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
  int iVar11;
  int *piVar12;
  float *pfVar13;
  int iVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  double dVar21;
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
  
  if (7 < param_2) {
    param_2 = 7;
  }
  piVar12 = *(int **)(*param_1 + param_2 * 4);
  if (piVar12 == (int *)0x0) {
    return fparam_1;
  }
  param_1[1] = (int)piVar12;
  pfVar13 = (float *)(piVar12 + param_3 * 0x34 + 0x48);
  param_1[2] = (int)pfVar13;
  if (param_1[8] == 0) {
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
  iVar11 = *piVar12;
  uVar10 = *(ushort *)(iVar11 + 0x16);
  if (uVar10 == 0x2700) {
LAB_97bd4b08:
    if (((*(short *)(iVar11 + 0x10) == -0x7ed3) || (*(short *)(iVar11 + 0x12) == -0x7ed3)) ||
       (*(short *)(iVar11 + 0x14) == -0x7ed3)) {
      fVar8 = GH_U2F((unsigned int)(piVar12[param_3 * 0x34 + 0x5c]));
      iVar11 = param_3 * 0x34 + 100;
      iVar14 = piVar12[param_3 * 0x34 + 0x71];
      fVar9 = GH_U2F((unsigned int)(piVar12[param_3 * 0x34 + 0x5d]));
      fVar7 = GH_U2F((unsigned int)(piVar12[param_3 * 0x34 + 0x5e]));
    }
    else {
      fVar8 = *pfVar13;
      iVar11 = param_3 * 0x34 + 0x50;
      iVar14 = piVar12[param_3 * 0x34 + 0x70];
      fVar9 = GH_U2F((unsigned int)(piVar12[param_3 * 0x34 + 0x49]));
      fVar7 = GH_U2F((unsigned int)(piVar12[param_3 * 0x34 + 0x4a]));
    }
    local_120 = (uint)(local_130 * fVar8);
    local_11c = (uint)(local_12c * fVar9);
    local_118 = (uint)(local_128 * fVar7);
    local_110 = (longlong)(int)local_118;
    ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(param_1,&local_120);
    dVar15 = (double)((int (*)())_InterpreterTextureSamplerLoadTexel3D)(param_1,iVar14,piVar12 + iVar11,&local_120,param_5);
    return dVar15;
  }
  if (uVar10 < 0x2701) {
    if (uVar10 == 0x2600) goto LAB_97bd4b08;
    bVar1 = uVar10 == 0x2601;
LAB_97bd4b00:
    if (!bVar1) {
      return fparam_1;
    }
  }
  else {
    if (uVar10 == 0x2702) goto LAB_97bd4b08;
    if (0x2701 < uVar10) {
      bVar1 = uVar10 == 0x2703;
      goto LAB_97bd4b00;
    }
  }
  if (((*(short *)(iVar11 + 0x10) == -0x7ed3) || (*(short *)(iVar11 + 0x12) == -0x7ed3)) ||
     (*(short *)(iVar11 + 0x14) == -0x7ed3)) {
    fVar7 = GH_U2F((unsigned int)(piVar12[param_3 * 0x34 + 0x5c]));
    iVar11 = piVar12[param_3 * 0x34 + 0x71];
  }
  else {
    if (((*(short *)(iVar11 + 0x10) != 0x2900) && (*(short *)(iVar11 + 0x12) != 0x2900)) &&
       (*(short *)(iVar11 + 0x14) != 0x2900)) {
      fVar7 = *pfVar13;
      iVar14 = param_3 * 0x34 + 0x50;
      iVar11 = piVar12[param_3 * 0x34 + 0x70];
      fVar8 = GH_U2F((unsigned int)(piVar12[param_3 * 0x34 + 0x49]));
      fVar9 = GH_U2F((unsigned int)(piVar12[param_3 * 0x34 + 0x4a]));
      goto LAB_97bd4cb4;
    }
    fVar7 = GH_U2F((unsigned int)(piVar12[param_3 * 0x34 + 0x5c]));
    iVar11 = piVar12[param_3 * 0x34 + 0x72];
  }
  iVar14 = param_3 * 0x34 + 100;
  fVar8 = GH_U2F((unsigned int)(piVar12[param_3 * 0x34 + 0x5d]));
  fVar9 = GH_U2F((unsigned int)(piVar12[param_3 * 0x34 + 0x5e]));
LAB_97bd4cb4:
  piVar12 = piVar12 + iVar14;
  fVar7 = (float)((double)(local_130 * fVar7) + DOUBLE_97c30a88);
  fVar8 = (float)((double)(local_12c * fVar8) + DOUBLE_97c30a88);
  fVar9 = (float)((double)(local_128 * fVar9) + DOUBLE_97c30a88);
  dVar15 = _floor((double)fVar7);
  local_120 = (uint)dVar15;
  local_110 = (longlong)(int)local_120;
  dVar15 = _floor((double)fVar8);
  local_11c = (uint)dVar15;
  local_110 = (longlong)(int)local_11c;
  dVar15 = _floor((double)fVar9);
  local_118 = (uint)dVar15;
  local_110 = (longlong)(int)local_118;
  local_70 = 0x43300000;
  uStack_6c = local_118 ^ 0x80000000;
  local_7c = local_11c;
  dVar18 = (double)(fVar7 - (float)((double)CONCAT44(0x43300000,local_120 ^ 0x80000000) -
                                   DOUBLE_97c30a58));
  local_80 = local_120;
  dVar16 = (double)(fVar8 - (float)((double)CONCAT44(0x43300000,local_11c ^ 0x80000000) -
                                   DOUBLE_97c30a58));
  dVar15 = (double)(fVar9 - (float)((double)CONCAT44(0x43300000,uStack_6c) - DOUBLE_97c30a58));
  dVar20 = (double)(float)(DOUBLE_97c30a60 - dVar15);
  dVar19 = (double)(float)(dVar18 * (double)(float)(DOUBLE_97c30a60 - dVar16));
  dVar17 = (double)(float)((double)(float)(DOUBLE_97c30a60 - dVar18) * dVar16);
  dVar21 = (double)(float)((double)(float)(DOUBLE_97c30a60 - dVar18) *
                          (double)(float)(DOUBLE_97c30a60 - dVar16));
  fVar7 = (float)((double)(float)(dVar18 * dVar16) * dVar20);
  fVar9 = (float)(dVar17 * dVar20);
  fVar8 = (float)((double)(float)(dVar18 * dVar16) * dVar15);
  fVar2 = (float)(dVar17 * dVar15);
  fVar3 = (float)(dVar21 * dVar20);
  fVar4 = (float)(dVar21 * dVar15);
  fVar5 = (float)(dVar19 * dVar20);
  fVar6 = (float)(dVar19 * dVar15);
  local_78 = local_118;
  ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(param_1,&local_80);
  ((int (*)())_InterpreterTextureSamplerLoadTexel3D)(param_1,iVar11,piVar12,&local_80,&local_100);
  local_80 = local_120;
  local_7c = local_11c - 1;
  local_78 = local_118;
  ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(param_1,&local_80);
  ((int (*)())_InterpreterTextureSamplerLoadTexel3D)(param_1,iVar11,piVar12,&local_80,&local_f0);
  local_80 = local_120 - 1;
  local_7c = local_11c - 1;
  local_78 = local_118;
  ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(param_1,&local_80);
  ((int (*)())_InterpreterTextureSamplerLoadTexel3D)(param_1,iVar11,piVar12,&local_80,&local_d0);
  local_80 = local_120 - 1;
  local_7c = local_11c;
  local_78 = local_118;
  ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(param_1,&local_80);
  ((int (*)())_InterpreterTextureSamplerLoadTexel3D)(param_1,iVar11,piVar12,&local_80,&local_e0);
  local_78 = local_118 - 1;
  local_80 = local_120;
  local_7c = local_11c;
  ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(param_1,&local_80);
  ((int (*)())_InterpreterTextureSamplerLoadTexel3D)(param_1,iVar11,piVar12,&local_80,&local_c0);
  local_7c = local_11c - 1;
  local_78 = local_118 - 1;
  local_80 = local_120;
  ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(param_1,&local_80);
  ((int (*)())_InterpreterTextureSamplerLoadTexel3D)(param_1,iVar11,piVar12,&local_80,&local_b0);
  local_80 = local_120 - 1;
  local_7c = local_11c - 1;
  local_78 = local_118 - 1;
  ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(param_1,&local_80);
  ((int (*)())_InterpreterTextureSamplerLoadTexel3D)(param_1,iVar11,piVar12,&local_80,&local_90);
  local_80 = local_120 - 1;
  local_78 = local_118 - 1;
  local_7c = local_11c;
  ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(param_1,&local_80);
  dVar15 = (double)((int (*)())_InterpreterTextureSamplerLoadTexel3D)(param_1,iVar11,piVar12,&local_80,&local_a0)
  ;
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
  return dVar15;
}

/* _InterpreterTextureSamplerSampleTexelRECTFromLevel @ 0x97bd5110 (1056 bytes) */
int _InterpreterTextureSamplerSampleTexelRECTFromLevel(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
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
  int iVar10;
  double dVar11;
  double dVar12;
  double dVar13;
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
  
  if (7 < param_2) {
    param_2 = 7;
  }
  piVar7 = *(int **)(*param_1 + param_2 * 4);
  if (piVar7 == (int *)0x0) {
    return;
  }
  param_1[1] = (int)piVar7;
  param_1[2] = (int)(piVar7 + param_3 * 0x34 + 0x48);
  iVar8 = *piVar7;
  uVar6 = *(ushort *)(iVar8 + 0x16);
  if (uVar6 == 0x2700) {
LAB_97bd51b8:
    if ((*(short *)(iVar8 + 0x10) == -0x7ed3) || (*(short *)(iVar8 + 0x12) == -0x7ed3)) {
      iVar8 = param_3 * 0x34 + 100;
      iVar10 = piVar7[param_3 * 0x34 + 0x71];
    }
    else {
      iVar10 = piVar7[param_3 * 0x34 + 0x70];
      iVar8 = param_3 * 0x34 + 0x50;
    }
    local_c0 = (uint)*param_4;
    local_bc = (uint)param_4[1];
    local_b0 = 0;
    local_b8 = 0;
    ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(param_1,&local_c0);
    ((int (*)())_InterpreterTextureSamplerLoadTexel2D)(param_1,iVar10,piVar7 + iVar8,&local_c0,param_5);
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
      piVar9 = piVar7 + param_3 * 0x34 + 100;
      iVar8 = piVar7[param_3 * 0x34 + 0x71];
    }
    else if ((*(short *)(iVar8 + 0x10) == 0x2900) || (*(short *)(iVar8 + 0x12) == 0x2900)) {
      piVar9 = piVar7 + param_3 * 0x34 + 100;
      iVar8 = piVar7[param_3 * 0x34 + 0x72];
    }
    else {
      iVar8 = piVar7[param_3 * 0x34 + 0x70];
      piVar9 = piVar7 + param_3 * 0x34 + 0x50;
    }
    fVar4 = (float)((double)*param_4 + DOUBLE_97c30a88);
    dVar11 = DOUBLE_97c30a88 + 0.0;
    fVar5 = (float)((double)param_4[1] + DOUBLE_97c30a88);
    dVar12 = _floor((double)fVar4);
    local_c0 = (uint)dVar12;
    local_b0 = (longlong)(int)local_c0;
    dVar12 = _floor((double)fVar5);
    local_bc = (uint)dVar12;
    local_b0 = (longlong)(int)local_bc;
    dVar11 = _floor((double)(float)dVar11);
    local_50 = 0x43300000;
    uStack_4c = local_bc ^ 0x80000000;
    local_5c = local_bc;
    local_60 = local_c0;
    dVar13 = (double)(fVar4 - (float)((double)CONCAT44(0x43300000,local_c0 ^ 0x80000000) -
                                     DOUBLE_97c30a58));
    dVar12 = (double)(fVar5 - (float)((double)CONCAT44(0x43300000,uStack_4c) - DOUBLE_97c30a58));
    local_b8 = (int)dVar11;
    local_b0 = (longlong)local_b8;
    fVar4 = (float)(dVar13 * dVar12);
    fVar5 = (float)((double)(float)(DOUBLE_97c30a60 - dVar13) * dVar12);
    fVar2 = (float)(dVar13 * (double)(float)(DOUBLE_97c30a60 - dVar12));
    fVar3 = (float)((double)(float)(DOUBLE_97c30a60 - dVar13) *
                   (double)(float)(DOUBLE_97c30a60 - dVar12));
    local_58 = local_b8;
    ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(param_1,&local_60);
    ((int (*)())_InterpreterTextureSamplerLoadTexel2D)(param_1,iVar8,piVar9,&local_60,&local_a0);
    local_60 = local_c0;
    local_5c = local_bc - 1;
    local_58 = local_b8;
    ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(param_1,&local_60);
    ((int (*)())_InterpreterTextureSamplerLoadTexel2D)(param_1,iVar8,piVar9,&local_60,&local_90);
    local_60 = local_c0 - 1;
    local_5c = local_bc - 1;
    local_58 = local_b8;
    ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(param_1,&local_60);
    ((int (*)())_InterpreterTextureSamplerLoadTexel2D)(param_1,iVar8,piVar9,&local_60,&local_70);
    local_60 = local_c0 - 1;
    local_5c = local_bc;
    local_58 = local_b8;
    ((int (*)())_InterpreterTextureSamplerWrapCoordinate)(param_1,&local_60);
    ((int (*)())_InterpreterTextureSamplerLoadTexel2D)(param_1,iVar8,piVar9,&local_60,&local_80);
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
  undefined4 uVar1;
  
  uVar1 = _calloc(0xa20,1);
  ((int (*)())_InterpreterNoiseGeneratorInitialise)(uVar1);
  return uVar1;
}

/* _InterpreterNoiseGeneratorInitialise @ 0x97bd57a0 (280 bytes) */
int _InterpreterNoiseGeneratorInitialise(param_1)
  undefined1 *param_1;
{
  undefined1 uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  float *pfVar5;
  uint uVar6;
  undefined1 *puVar7;
  
  _memset(param_1,0,0xa20);
  uVar6 = 0;
  pfVar5 = (float *)(param_1 + 0x210);
  do {
    param_1[uVar6] = (char)uVar6;
    uVar3 = _random();
    uVar6 = uVar6 + 1;
    *pfVar5 = (float)(((double)CONCAT44(0x43300000,
                                        (uVar3 + (((int)uVar3 >> 9) +
                                                 (uint)((int)uVar3 < 0 && (uVar3 & 0x1ff) != 0)) *
                                                 -0x200) - 0x100 ^ 0x80000000) - 4503601774854144.0)
                     * 0.00390625);
    pfVar5 = pfVar5 + 1;
  } while (uVar6 < 0x100);
  puVar7 = param_1 + 0xff;
  do {
    uVar1 = *puVar7;
    uVar6 = _random();
    iVar4 = uVar6 + (((int)uVar6 >> 8) + (uint)((int)uVar6 < 0 && (uVar6 & 0xff) != 0)) * -0x100;
    *puVar7 = param_1[iVar4];
    puVar7 = puVar7 + -1;
    param_1[iVar4] = uVar1;
  } while (puVar7 != param_1);
  iVar4 = 0x102;
  puVar7 = param_1;
  do {
    uVar2 = *(undefined4 *)(puVar7 + 0x210);
    param_1[0x100] = *param_1;
    param_1 = param_1 + 1;
    *(undefined4 *)(puVar7 + 0x610) = uVar2;
    puVar7 = puVar7 + 4;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return puVar7;
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
  
  dVar2 = _floor((double)*param_2);
  uVar1 = (uint)dVar2;
  local_30 = (longlong)(int)uVar1;
  dVar2 = _floor((double)param_2[1]);
  local_30 = (longlong)(int)dVar2;
  dVar3 = _floor((double)param_2[2]);
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
  
  dVar5 = _floor((double)*param_2);
  uVar1 = (uint)dVar5;
  local_30 = (longlong)(int)uVar1;
  dVar5 = _floor((double)param_2[1]);
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
  local_38 = GH_U2F((unsigned int)(local_44));
  local_34 = local_50;
  ((int (*)())_InterpreterNoiseGeneratorInterpolate)(param_1,&local_50,&local_40,&local_60,&local_50);
  local_40 = local_48;
  local_3c = local_44;
  local_38 = local_50;
  local_34 = GH_U2F((unsigned int)(local_4c));
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
  
  dVar9 = _floor((double)*param_2);
  uVar5 = (uint)dVar9;
  local_30 = (longlong)(int)uVar5;
  dVar9 = _floor((double)param_2[1]);
  uVar7 = (uint)dVar9;
  local_30 = (longlong)(int)uVar7;
  dVar9 = _floor((double)param_2[2]);
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
  local_38 = GH_U2F((unsigned int)(local_44));
  local_34 = local_50;
  local_60 = local_6c;
  local_5c = local_6c;
  local_58 = local_6c;
  ((int (*)())_InterpreterNoiseGeneratorInterpolate)(param_1,&local_50,&local_40,&local_60,&local_50);
  local_40 = local_48;
  local_3c = local_44;
  local_54 = local_68;
  local_38 = local_50;
  local_34 = GH_U2F((unsigned int)(local_4c));
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
    dVar4 = _exp2((double)(float)((double)CONCAT44(0x43300000,uStack_4c) - dVar2));
    local_60[4] = 176.0;
    uStack_4c = uVar3;
    dVar5 = _pow(DOUBLE_97c30a88,(double)CONCAT44(0x43300000,uVar3) - dVar2);
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
    dVar4 = _exp2((double)(float)((double)CONCAT44(0x43300000,uStack_4c) - dVar2));
    local_50 = 0x43300000;
    uStack_4c = uVar3;
    dVar5 = _pow(DOUBLE_97c30a88,(double)CONCAT44(0x43300000,uVar3) - dVar2);
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
    dVar5 = _exp2((double)(float)((double)CONCAT44(0x43300000,uStack_4c) - dVar3));
    local_50 = 0x43300000;
    fVar2 = (float)dVar5;
    uStack_4c = uVar4;
    dVar5 = _pow(DOUBLE_97c30a88,(double)CONCAT44(0x43300000,uVar4) - dVar3);
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
  undefined4 uVar1;
  
  uVar1 = _calloc(8,1);
  ((int (*)())_InterpreterRasterOpMachineInitialise)(uVar1);
  return uVar1;
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

/* _InterpreterRasterOpMachine_DepthAndStencilTest @ 0x97bd6520 (732 bytes) */
int _InterpreterRasterOpMachine_DepthAndStencilTest(param_1)
  int *param_1;
{
  bool bVar1;
  bool bVar2;
  float fVar3;
  uint uVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  float *pfVar14;
  uint uVar15;
  
  uVar15 = 0;
  iVar13 = *param_1;
  iVar7 = *(int *)(iVar13 + 0xd80);
  uVar6 = *(uint *)(iVar7 + 0x48);
  uVar12 = *(uint *)(iVar7 + 0x3c);
  uVar4 = *(uint *)(iVar7 + 0x4c) >> 0x18;
  fVar3 = *(float *)(*(int *)(iVar13 + 0xdf0) + 0xa38);
  pfVar14 = *(float **)(iVar13 + 0xda8);
  pbVar8 = *(byte **)(iVar13 + 0xdac);
  bVar1 = (uVar12 >> 6 & 1) == 0;
  uVar10 = *(uint *)(iVar7 + 0x4c) >> 8 & 0xff;
  uVar11 = *(uint *)(*(int *)(iVar13 + 0xd80) + 0x70);
  if (bVar1) {
    uVar9 = 0xff;
  }
  else {
    uVar9 = uVar11 >> 8 & 0xff;
  }
  bVar5 = (uVar12 & 2) != 0;
  if (bVar5) {
    switch(uVar6 >> 0xc & 7) {
    case 0:
      uVar15 = 0;
      break;
    case 1:
      uVar15 = (uint)((uVar4 & uVar10) < (uVar10 & *pbVar8));
      break;
    case 2:
      uVar15 = (uint)((uVar4 & uVar10) == (uVar10 & *pbVar8));
      break;
    case 3:
      uVar15 = (uint)((uVar4 & uVar10) <= (uVar10 & *pbVar8));
      break;
    case 4:
      uVar15 = (uint)((uVar10 & *pbVar8) < (uVar4 & uVar10));
      break;
    case 5:
      uVar15 = -((*pbVar8 ^ uVar4) & uVar10) >> 0x1f;
      break;
    case 6:
      uVar15 = (uint)((uVar10 & *pbVar8) <= (uVar4 & uVar10));
      break;
    case 7:
      uVar15 = 1;
    }
    if (uVar15 == 0) {
      ((int (*)())_InterpreterRasterOpMachineUpdateStencilBuffer)(uVar6 >> 0xf & 7,uVar4,pbVar8,uVar9);
      return true;
    }
  }
  if ((uVar12 & 4) == 0) {
    if (bVar5) {
      ((int (*)())_InterpreterRasterOpMachineUpdateStencilBuffer)(uVar6 >> 0x15 & 7,uVar4,pbVar8,uVar9);
    }
    return uVar15 == 0;
  }
  switch(*(uint *)(*(int *)(iVar13 + 0xd80) + 0x50) & 7) {
  case 0:
    uVar15 = 0;
    break;
  case 1:
    uVar15 = (uint)GH_F2U((fVar3 < *pfVar14));
    break;
  case 2:
    uVar15 = (uint)GH_F2U((fVar3 == *pfVar14));
    break;
  case 3:
    bVar2 = fVar3 <= *pfVar14;
    goto LAB_97bd67ac;
  case 4:
    uVar15 = (uint)(*pfVar14 < fVar3);
    break;
  case 5:
    uVar15 = (uint)GH_F2U((fVar3 != *pfVar14));
    break;
  case 6:
    bVar2 = *pfVar14 <= fVar3;
LAB_97bd67ac:
    uVar15 = (uint)bVar2;
    break;
  case 7:
    uVar15 = 1;
  }
  if (uVar15 == 0) {
    if (bVar5) {
      ((int (*)())_InterpreterRasterOpMachineUpdateStencilBuffer)(uVar6 >> 0x12 & 7,uVar4,pbVar8,uVar9);
    }
  }
  else {
    if (bVar5) {
      ((int (*)())_InterpreterRasterOpMachineUpdateStencilBuffer)(uVar6 >> 0x15 & 7,uVar4,pbVar8,uVar9);
    }
    if ((bVar1) || ((uVar11 & 0x10000) != 0)) {
      *pfVar14 = fVar3;
    }
  }
  return uVar15 == 0;
}

/* _InterpreterRasterOpMachine_AlphaTest @ 0x97bd683c (1548 bytes) */
int _InterpreterRasterOpMachine_AlphaTest(param_1, param_2)
  int *param_1;
  int param_2;
{
  float fVar1;
  int iVar2;
  uint uVar3;
  float fVar4;
  uint uVar5;
  bool bVar6;
  double dVar7;
  
  iVar2 = *(int *)(*param_1 + 0xd80);
  fVar1 = *(float *)(iVar2 + 0x44);
  uVar5 = *(uint *)(iVar2 + 0x40);
  uVar3 = _PPEmulatorFramebufferFormat(*param_1);
  bVar6 = false;
  if ((uVar3 & 0x1c000) == 0) {
    switch(uVar5 & 7) {
    case 0:
switchD_97bd6924_caseD_0:
      bVar6 = false;
      break;
    case 1:
      bVar6 = *(float *)(param_2 + 0xc) < fVar1;
      break;
    case 2:
      bVar6 = *(float *)(param_2 + 0xc) == fVar1;
      break;
    case 3:
      bVar6 = *(float *)(param_2 + 0xc) <= fVar1;
      break;
    case 4:
      bVar6 = fVar1 < *(float *)(param_2 + 0xc);
      break;
    case 5:
      bVar6 = *(float *)(param_2 + 0xc) != fVar1;
      break;
    case 6:
      bVar6 = fVar1 <= *(float *)(param_2 + 0xc);
      break;
    case 7:
switchD_97bd6924_caseD_7:
      bVar6 = true;
    }
  }
  else {
    fVar4 = *(float *)(param_2 + 0xc);
    if (TAllocation__guardBlockSize <= fVar4) {
      if (FLOAT_97c3acd8 < fVar4) {
        fVar4 = 1.0;
      }
    }
    else {
      fVar4 = 0.0;
    }
    if (TAllocation__guardBlockSize <= fVar1) {
      if (FLOAT_97c3acd8 < fVar1) {
        fVar1 = 1.0;
      }
    }
    else {
      fVar1 = 0.0;
    }
    switch(uVar5 & 7) {
    case 0:
      goto switchD_97bd6924_caseD_0;
    case 1:
      fVar4 = fVar4 * FLOAT_97c3acbc + FLOAT_97c3acc0;
      dVar7 = (double)fVar4;
      if (DOUBLE_97c30a78 <= dVar7) {
        uVar3 = (int)(dVar7 - DOUBLE_97c30a78) ^ 0x80000000;
      }
      else {
        uVar3 = (uint)fVar4;
      }
      fVar1 = fVar1 * FLOAT_97c3acbc + FLOAT_97c3acc0;
      dVar7 = (double)fVar1;
      if (DOUBLE_97c30a78 <= dVar7) {
        uVar5 = (int)(dVar7 - DOUBLE_97c30a78) ^ 0x80000000;
      }
      else {
        uVar5 = (uint)fVar1;
      }
      bVar6 = uVar3 < uVar5;
      break;
    case 2:
      fVar4 = fVar4 * FLOAT_97c3acbc + FLOAT_97c3acc0;
      dVar7 = (double)fVar4;
      if (DOUBLE_97c30a78 <= dVar7) {
        uVar3 = (int)(dVar7 - DOUBLE_97c30a78) ^ 0x80000000;
      }
      else {
        uVar3 = (uint)fVar4;
      }
      fVar1 = fVar1 * FLOAT_97c3acbc + FLOAT_97c3acc0;
      dVar7 = (double)fVar1;
      if (DOUBLE_97c30a78 <= dVar7) {
        uVar5 = (int)(dVar7 - DOUBLE_97c30a78) ^ 0x80000000;
      }
      else {
        uVar5 = (uint)fVar1;
      }
      bVar6 = uVar3 == uVar5;
      break;
    case 3:
      fVar4 = fVar4 * FLOAT_97c3acbc + FLOAT_97c3acc0;
      dVar7 = (double)fVar4;
      if (DOUBLE_97c30a78 <= dVar7) {
        uVar3 = (int)(dVar7 - DOUBLE_97c30a78) ^ 0x80000000;
      }
      else {
        uVar3 = (uint)fVar4;
      }
      fVar1 = fVar1 * FLOAT_97c3acbc + FLOAT_97c3acc0;
      dVar7 = (double)fVar1;
      if (DOUBLE_97c30a78 <= dVar7) {
        uVar5 = (int)(dVar7 - DOUBLE_97c30a78) ^ 0x80000000;
      }
      else {
        uVar5 = (uint)fVar1;
      }
      bVar6 = uVar3 <= uVar5;
      break;
    case 4:
      fVar4 = fVar4 * FLOAT_97c3acbc + FLOAT_97c3acc0;
      dVar7 = (double)fVar4;
      if (DOUBLE_97c30a78 <= dVar7) {
        uVar3 = (int)(dVar7 - DOUBLE_97c30a78) ^ 0x80000000;
      }
      else {
        uVar3 = (uint)fVar4;
      }
      fVar1 = fVar1 * FLOAT_97c3acbc + FLOAT_97c3acc0;
      dVar7 = (double)fVar1;
      if (DOUBLE_97c30a78 <= dVar7) {
        uVar5 = (int)(dVar7 - DOUBLE_97c30a78) ^ 0x80000000;
      }
      else {
        uVar5 = (uint)fVar1;
      }
      bVar6 = uVar5 < uVar3;
      break;
    case 5:
      fVar4 = fVar4 * FLOAT_97c3acbc + FLOAT_97c3acc0;
      dVar7 = (double)fVar4;
      if (DOUBLE_97c30a78 <= dVar7) {
        uVar3 = (int)(dVar7 - DOUBLE_97c30a78) ^ 0x80000000;
      }
      else {
        uVar3 = (uint)fVar4;
      }
      fVar1 = fVar1 * FLOAT_97c3acbc + FLOAT_97c3acc0;
      dVar7 = (double)fVar1;
      if (DOUBLE_97c30a78 <= dVar7) {
        uVar5 = (int)(dVar7 - DOUBLE_97c30a78) ^ 0x80000000;
      }
      else {
        uVar5 = (uint)fVar1;
      }
      bVar6 = uVar3 != uVar5;
      break;
    case 6:
      fVar4 = fVar4 * FLOAT_97c3acbc + FLOAT_97c3acc0;
      dVar7 = (double)fVar4;
      if (DOUBLE_97c30a78 <= dVar7) {
        uVar3 = (int)(dVar7 - DOUBLE_97c30a78) ^ 0x80000000;
      }
      else {
        uVar3 = (uint)fVar4;
      }
      fVar1 = fVar1 * FLOAT_97c3acbc + FLOAT_97c3acc0;
      dVar7 = (double)fVar1;
      if (DOUBLE_97c30a78 <= dVar7) {
        uVar5 = (int)(dVar7 - DOUBLE_97c30a78) ^ 0x80000000;
      }
      else {
        uVar5 = (uint)fVar1;
      }
      bVar6 = uVar5 <= uVar3;
      break;
    case 7:
      goto switchD_97bd6924_caseD_7;
    }
  }
  return bVar6 ^ 1;
}

/* _InterpreterRasterOpMachine_Blending @ 0x97bd6e88 (1252 bytes) */
int _InterpreterRasterOpMachine_Blending(param_1, param_2, param_3, param_4)
  int *param_1;
  float *param_2;
  float *param_3;
  float *param_4;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  undefined1 auStack_40 [12];
  float local_34;
  float local_30;
  
  iVar5 = *param_1;
  uVar7 = *(uint *)(*(int *)(iVar5 + 0xd80) + 0x58);
  iVar8 = *(int *)(*(int *)(iVar5 + 0xd9c) + 0xd8) + 0x2d70;
  uVar6 = _PPEmulatorFramebufferFormat(iVar5);
  fVar2 = FLOAT_97c3acd8;
  if ((uVar6 & 0x8000000) == 0) {
    fVar3 = *param_2;
    fVar4 = fVar3;
    if (FLOAT_97c3acd8 <= fVar3) {
      fVar3 = 1.0;
      fVar4 = local_30;
    }
    local_30 = fVar4;
    fVar4 = param_2[1];
    *param_2 = fVar3;
    fVar3 = FLOAT_97c3acd8;
    fVar1 = fVar4;
    if (fVar2 <= fVar4) {
      fVar4 = 1.0;
      fVar1 = local_30;
    }
    local_30 = fVar1;
    fVar2 = param_2[2];
    param_2[1] = fVar4;
    fVar4 = FLOAT_97c3acd8;
    fVar1 = fVar2;
    if (fVar3 <= fVar2) {
      fVar2 = 1.0;
      fVar1 = local_30;
    }
    local_30 = fVar1;
    fVar3 = param_2[3];
    param_2[2] = fVar2;
    fVar2 = TAllocation__guardBlockSize;
    fVar1 = fVar3;
    if (fVar4 <= fVar3) {
      fVar3 = 1.0;
      fVar1 = local_30;
    }
    local_30 = fVar1;
    fVar4 = *param_2;
    param_2[3] = fVar3;
    fVar3 = TAllocation__guardBlockSize;
    fVar1 = fVar4;
    if (fVar4 <= fVar2) {
      fVar4 = 0.0;
      fVar1 = local_30;
    }
    local_30 = fVar1;
    fVar2 = param_2[1];
    *param_2 = fVar4;
    fVar4 = TAllocation__guardBlockSize;
    fVar1 = fVar2;
    if (fVar2 <= fVar3) {
      fVar2 = 0.0;
      fVar1 = local_30;
    }
    local_30 = fVar1;
    fVar3 = param_2[2];
    param_2[1] = fVar2;
    fVar2 = TAllocation__guardBlockSize;
    fVar1 = fVar3;
    if (fVar3 <= fVar4) {
      fVar3 = 0.0;
      fVar1 = local_30;
    }
    local_30 = fVar1;
    fVar4 = param_2[3];
    param_2[2] = fVar3;
    fVar3 = fVar4;
    if (fVar4 <= fVar2) {
      fVar4 = 0.0;
      fVar3 = local_30;
    }
    local_30 = fVar3;
    param_2[3] = fVar4;
  }
  if ((1 < (uVar7 >> 0x10 & 7) - 3) || (1 < (uVar7 >> 0x13 & 7) - 3)) {
    ((int (*)())_InterpreterRasterOpMachineCalculateBlendingFactors)(uVar7 & 0xf,param_2,param_3,iVar8,&local_60)
    ;
    ((int (*)())_InterpreterRasterOpMachineCalculateBlendingFactors)(uVar7 >> 8 & 0xf,param_2,param_3,iVar8,&local_50);
    if ((uVar7 & 0xf) != (uVar7 >> 4 & 0xf)) {
      ((int (*)())_InterpreterRasterOpMachineCalculateBlendingFactors)(uVar7 >> 4 & 0xf,param_2,param_3,iVar8,auStack_40);
      local_54 = local_34;
    }
    if ((uVar7 >> 8 & 0xf) != (uVar7 >> 0xc & 0xf)) {
      ((int (*)())_InterpreterRasterOpMachineCalculateBlendingFactors)(uVar7 >> 0xc & 0xf,param_2,param_3,iVar8,auStack_40);
      local_44 = local_34;
    }
  }
  switch(uVar7 >> 0x10 & 7) {
  case 0:
    *param_4 = *param_2 * local_60 + *param_3 * local_50;
    param_4[1] = param_2[1] * local_5c + param_3[1] * local_4c;
    fVar2 = param_2[2] * local_58 + param_3[2] * local_48;
    goto LAB_97bd7230;
  case 1:
    *param_4 = *param_2 * local_60 - *param_3 * local_50;
    param_4[1] = param_2[1] * local_5c - param_3[1] * local_4c;
    fVar2 = param_3[2];
    fVar3 = param_2[2];
    fVar4 = local_48;
    local_48 = local_58;
    break;
  case 2:
    *param_4 = *param_3 * local_50 - *param_2 * local_60;
    param_4[1] = param_3[1] * local_4c - param_2[1] * local_5c;
    fVar2 = param_2[2];
    fVar3 = param_3[2];
    fVar4 = local_58;
    break;
  case 3:
    fVar2 = *param_3;
    if (*param_2 < *param_3) {
      fVar2 = *param_2;
    }
    *param_4 = fVar2;
    fVar2 = param_3[1];
    if (param_2[1] < param_3[1]) {
      fVar2 = param_2[1];
    }
    param_4[1] = fVar2;
    fVar3 = param_2[2];
    fVar2 = param_3[2];
    if (fVar3 < fVar2) {
LAB_97bd72bc:
      fVar2 = fVar3;
    }
    goto LAB_97bd72c0;
  case 4:
    fVar2 = *param_3;
    if (*param_3 < *param_2) {
      fVar2 = *param_2;
    }
    *param_4 = fVar2;
    fVar2 = param_3[1];
    if (param_3[1] < param_2[1]) {
      fVar2 = param_2[1];
    }
    param_4[1] = fVar2;
    fVar3 = param_2[2];
    fVar2 = param_3[2];
    if (param_3[2] < fVar3) goto LAB_97bd72bc;
LAB_97bd72c0:
    param_4[2] = fVar2;
  default:
    goto switchD_97bd7128_default;
  }
  fVar2 = fVar3 * local_48 - fVar2 * fVar4;
LAB_97bd7230:
  param_4[2] = fVar2;
switchD_97bd7128_default:
  switch(uVar7 >> 0x13 & 7) {
  case 0:
    fVar3 = param_2[3] * local_54 + param_3[3] * local_44;
    goto LAB_97bd734c;
  case 1:
    fVar2 = param_2[3];
    fVar3 = param_3[3] * local_44;
    local_44 = local_54;
    break;
  case 2:
    fVar2 = param_3[3];
    fVar3 = param_2[3] * local_54;
    break;
  case 3:
    fVar3 = param_2[3];
    fVar2 = param_3[3];
    if (fVar3 < fVar2) {
LAB_97bd7378:
      fVar2 = fVar3;
    }
    goto LAB_97bd737c;
  case 4:
    fVar3 = param_2[3];
    fVar2 = param_3[3];
    if (param_3[3] < fVar3) goto LAB_97bd7378;
LAB_97bd737c:
    param_4[3] = fVar2;
  default:
    goto switchD_97bd72e8_default;
  }
  fVar3 = fVar2 * local_44 - fVar3;
LAB_97bd734c:
  param_4[3] = fVar3;
switchD_97bd72e8_default:
  return;
}

/* _InterpreterRasterOpMachine_LogicOp @ 0x97bd7394 (1208 bytes) */
int _InterpreterRasterOpMachine_LogicOp(param_1, param_2, param_3, param_4)
  int *param_1;
  float *param_2;
  float *param_3;
  float *param_4;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  
  uVar6 = *(uint *)(*(int *)(*param_1 + 0xd80) + 0x68) & 0xf;
  if ((uVar6 < 3) || (uVar6 == 4)) {
    if (uVar6 == 1) {
      fVar4 = 1.0;
    }
    else {
      if (1 < uVar6) {
        if (uVar6 == 2) {
          *param_4 = *param_2;
          param_4[1] = param_2[1];
          param_4[2] = param_2[2];
          fVar4 = param_2[3];
        }
        else {
          if (uVar6 != 4) {
            return;
          }
          *param_4 = *param_3;
          param_4[1] = param_3[1];
          param_4[2] = param_3[2];
          fVar4 = param_3[3];
        }
        param_4[3] = fVar4;
        return;
      }
      fVar4 = 0.0;
      if (uVar6 != 0) {
        return;
      }
    }
    param_4[3] = fVar4;
    *param_4 = fVar4;
    param_4[1] = fVar4;
    param_4[2] = fVar4;
    return;
  }
  if (uVar6 == 5) {
    fVar4 = *param_3;
    fVar1 = param_3[1];
    fVar2 = param_3[2];
    fVar3 = param_3[3];
LAB_97bd74b4:
    uVar6 = ~(int)((double)fVar3 * DOUBLE_97c30a98) & 0xffU |
            (~(int)((double)fVar2 * DOUBLE_97c30a98) & 0xffU) << 8 |
            (~(int)((double)fVar1 * DOUBLE_97c30a98) & 0xffU) << 0x10 |
            ~(int)((double)fVar4 * DOUBLE_97c30a98) << 0x18;
    goto LAB_97bd77d8;
  }
  if (uVar6 == 3) {
    fVar4 = *param_2;
    fVar1 = param_2[1];
    fVar2 = param_2[2];
    fVar3 = param_2[3];
    goto LAB_97bd74b4;
  }
  uVar10 = (uint)((double)*param_2 * DOUBLE_97c30a98);
  uVar5 = (uint)((double)*param_3 * DOUBLE_97c30a98);
  uVar7 = ((int)((double)param_2[1] * DOUBLE_97c30a98) & 0xffU) << 0x10 | uVar10 << 0x18;
  uVar8 = ((int)((double)param_2[2] * DOUBLE_97c30a98) & 0xffU) << 8 | uVar7;
  uVar11 = ((int)((double)param_3[1] * DOUBLE_97c30a98) & 0xffU) << 0x10 | uVar5 << 0x18;
  uVar9 = (int)((double)param_2[3] * DOUBLE_97c30a98) & 0xffU | uVar8;
  uVar12 = ((int)((double)param_3[2] * DOUBLE_97c30a98) & 0xffU) << 8 | uVar11;
  uVar13 = (int)((double)param_3[3] * DOUBLE_97c30a98) & 0xffU | uVar12;
  switch(uVar6) {
  case 6:
    uVar5 = uVar13 & uVar9;
    uVar7 = uVar9 & uVar13;
    uVar6 = uVar5 >> 8;
    uVar10 = uVar5 >> 0x10;
    goto LAB_97bd7670;
  case 7:
    uVar6 = uVar13 & uVar9;
    uVar7 = ~(uVar9 & uVar13);
    uVar5 = uVar6 ^ 0xff000000;
    uVar10 = ~(uVar6 >> 0x10);
    uVar6 = ~(uVar6 >> 8);
LAB_97bd7670:
    uVar6 = (uVar6 & 0xff) << 8 | (uVar10 & 0xff) << 0x10 | uVar5 & 0xff000000;
    goto LAB_97bd770c;
  case 8:
    uVar10 = uVar13 | uVar9;
    uVar7 = uVar9 | uVar13;
    uVar5 = uVar13 | uVar9;
    goto LAB_97bd76cc;
  case 9:
    uVar7 = ~(uVar9 | uVar13);
    uVar5 = (uVar13 | uVar9) ^ 0xff000000;
    uVar6 = ~((uVar13 | uVar9) >> 0x10);
    uVar10 = ~((uVar13 | uVar9) >> 8);
    goto LAB_97bd7700;
  case 10:
    uVar10 = uVar13 ^ uVar9;
    uVar7 = uVar9 ^ uVar13;
    uVar5 = uVar13 ^ uVar9;
LAB_97bd76cc:
    uVar6 = uVar10 >> 0x10;
    uVar10 = uVar10 >> 8;
    goto LAB_97bd7700;
  case 0xb:
    uVar5 = uVar13 ^ uVar9 ^ 0xff000000;
    uVar6 = ~((uVar13 ^ uVar9) >> 0x10);
    uVar10 = ~((uVar13 ^ uVar9) >> 8);
    uVar7 = ~(uVar9 ^ uVar13);
LAB_97bd7700:
    uVar6 = (uVar10 & 0xff) << 8 | (uVar6 & 0xff) << 0x10 | uVar5 & 0xff000000;
LAB_97bd770c:
    uVar6 = uVar7 & 0xff | uVar6;
    goto LAB_97bd77d8;
  case 0xc:
    uVar7 = uVar7 >> 0x10 & ~(uVar11 >> 0x10);
    uVar10 = uVar10 & 0xff & ~(uVar5 & 0xff);
    uVar6 = uVar8 >> 8 & ~(uVar12 >> 8);
    uVar13 = uVar9 & ~uVar13;
    break;
  case 0xd:
    uVar7 = uVar11 >> 0x10 & ~(uVar7 >> 0x10);
    uVar10 = uVar5 & 0xff & ~(uVar10 & 0xff);
    uVar6 = uVar12 >> 8 & ~(uVar8 >> 8);
    uVar13 = uVar13 & ~uVar9;
    break;
  case 0xe:
    uVar7 = uVar7 >> 0x10 | ~(uVar11 >> 0x10);
    uVar10 = uVar10 & 0xff | ~(uVar5 & 0xff);
    uVar6 = uVar8 >> 8 | ~(uVar12 >> 8);
    uVar13 = uVar9 | ~uVar13;
    break;
  case 0xf:
    uVar7 = uVar11 >> 0x10 | ~(uVar7 >> 0x10);
    uVar10 = uVar5 & 0xff | ~(uVar10 & 0xff);
    uVar6 = uVar12 >> 8 | ~(uVar8 >> 8);
    uVar13 = uVar13 | ~uVar9;
    break;
  default:
    uVar6 = 0;
    goto LAB_97bd77d8;
  }
  uVar6 = uVar13 & 0xff | (uVar6 & 0xff) << 8 | (uVar7 & 0xff) << 0x10 | uVar10 << 0x18;
LAB_97bd77d8:
  fVar4 = (GH_U2F((unsigned int)((uVar6 & 0xff | 0x4b000000))) - 8388608.0) * FLOAT_97c3acc8;
  fVar1 = (GH_U2F((unsigned int)((uVar6 >> 0x10 & 0xff | 0x4b000000))) - 8388608.0) * FLOAT_97c3acc8;
  fVar2 = (GH_U2F((unsigned int)((uVar6 >> 8 & 0xff | 0x4b000000))) - 8388608.0) * FLOAT_97c3acc8;
  *param_4 = (GH_U2F((unsigned int)((uVar6 >> 0x18 | 0x4b000000))) - 8388608.0) * FLOAT_97c3acc8;
  param_4[3] = fVar4;
  param_4[1] = fVar1;
  param_4[2] = fVar2;
  return;
}

/* _InterpreterRasterOpMachine_BufferMask @ 0x97bd7874 (128 bytes) */
int _InterpreterRasterOpMachine_BufferMask(param_1, param_2, param_3, param_4)
  int *param_1;
  undefined4 *param_2;
  undefined4 *param_3;
  undefined4 *param_4;
{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(*(int *)(*param_1 + 0xd80) + 0x70);
  if ((uVar2 & 0x20000) == 0) {
    uVar1 = *param_3;
  }
  else {
    uVar1 = *param_2;
  }
  *param_4 = uVar1;
  if ((uVar2 & 0x40000) == 0) {
    uVar1 = param_3[1];
  }
  else {
    uVar1 = param_2[1];
  }
  param_4[1] = uVar1;
  if ((uVar2 & 0x80000) == 0) {
    uVar1 = param_3[2];
  }
  else {
    uVar1 = param_2[2];
  }
  param_4[2] = uVar1;
  if ((uVar2 & 0x100000) == 0) {
    uVar1 = param_3[3];
  }
  else {
    uVar1 = param_2[3];
  }
  param_4[3] = uVar1;
  return;
}

/* _InterpreterRasterOpMachineCalculateBlendingFactors @ 0x97bd78f4 (664 bytes) */
int _InterpreterRasterOpMachineCalculateBlendingFactors(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  float *param_2;
  float *param_3;
  float *param_4;
  float *param_5;
{
  double dVar1;
  float fVar2;
  double dVar3;
  
  dVar1 = DOUBLE_97c30a60;
  switch(param_1) {
  case 0:
    fVar2 = 0.0;
    goto LAB_97bd7970;
  case 1:
    fVar2 = 1.0;
LAB_97bd7970:
    param_5[3] = fVar2;
    *param_5 = fVar2;
    param_5[1] = fVar2;
    param_5[2] = fVar2;
    return;
  case 2:
    *param_5 = *param_2;
    param_5[1] = param_2[1];
    fVar2 = param_2[2];
    break;
  case 3:
    *param_5 = (float)(DOUBLE_97c30a60 - (double)*param_2);
    param_5[1] = (float)(dVar1 - (double)param_2[1]);
    fVar2 = param_2[2];
    goto LAB_97bd7a1c;
  case 4:
    *param_5 = param_2[3];
    param_5[1] = param_2[3];
    fVar2 = param_2[3];
    break;
  case 5:
    *param_5 = (float)(DOUBLE_97c30a60 - (double)param_2[3]);
    param_5[1] = (float)(dVar1 - (double)param_2[3]);
    fVar2 = param_2[3];
LAB_97bd7a1c:
    param_5[2] = (float)(dVar1 - (double)fVar2);
    dVar3 = (double)param_2[3];
LAB_97bd7a2c:
    param_5[3] = (float)(dVar1 - dVar3);
    return;
  case 6:
    *param_5 = param_3[3];
    param_5[1] = param_3[3];
    fVar2 = param_3[3];
    goto LAB_97bd7b40;
  case 7:
    *param_5 = (float)(DOUBLE_97c30a60 - (double)param_3[3]);
    param_5[1] = (float)(dVar1 - (double)param_3[3]);
    fVar2 = param_3[3];
    goto LAB_97bd7b78;
  case 8:
    *param_5 = *param_4;
    param_5[1] = param_4[1];
    fVar2 = param_4[2];
    goto LAB_97bd7ae0;
  case 9:
    *param_5 = (float)(DOUBLE_97c30a60 - (double)*param_4);
    param_5[1] = (float)(dVar1 - (double)param_4[1]);
    fVar2 = param_4[2];
    goto LAB_97bd7b18;
  case 10:
    *param_5 = param_4[3];
    param_5[1] = param_4[3];
    fVar2 = param_4[3];
LAB_97bd7ae0:
    param_5[2] = fVar2;
    fVar2 = param_4[3];
    goto LAB_97bd79e8;
  case 0xb:
    *param_5 = (float)(DOUBLE_97c30a60 - (double)param_4[3]);
    param_5[1] = (float)(dVar1 - (double)param_4[3]);
    fVar2 = param_4[3];
LAB_97bd7b18:
    param_5[2] = (float)(dVar1 - (double)fVar2);
    dVar3 = (double)param_4[3];
    goto LAB_97bd7a2c;
  case 0xc:
    *param_5 = *param_3;
    param_5[1] = param_3[1];
    fVar2 = param_3[2];
LAB_97bd7b40:
    param_5[2] = fVar2;
    fVar2 = param_3[3];
    goto LAB_97bd79e8;
  case 0xd:
    *param_5 = (float)(DOUBLE_97c30a60 - (double)*param_3);
    param_5[1] = (float)(dVar1 - (double)param_3[1]);
    fVar2 = param_3[2];
LAB_97bd7b78:
    param_5[2] = (float)(dVar1 - (double)fVar2);
    dVar3 = (double)param_3[3];
    goto LAB_97bd7a2c;
  case 0xe:
    fVar2 = (float)(DOUBLE_97c30a60 - (double)param_3[3]);
    if (param_2[3] < (float)(DOUBLE_97c30a60 - (double)param_3[3])) {
      fVar2 = param_2[3];
    }
    param_5[2] = fVar2;
    param_5[3] = 1.0;
    *param_5 = fVar2;
    param_5[1] = fVar2;
    return;
  default:
    return;
  }
  param_5[2] = fVar2;
  fVar2 = param_2[3];
LAB_97bd79e8:
  param_5[3] = fVar2;
  return;
}

/* _InterpreterRasterOpMachineUpdateStencilBuffer @ 0x97bd7bc8 (212 bytes) */
int _InterpreterRasterOpMachineUpdateStencilBuffer(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  byte *param_3;
  undefined4 param_4;
{
  byte bVar1;
  byte bVar2;
  
  switch(param_1) {
  case 0:
    bVar2 = *param_3 & ~(byte)param_4;
    goto LAB_97bd7c38;
  case 1:
    return;
  case 2:
    bVar2 = *param_3 & ~(byte)param_4;
    goto LAB_97bd7c34;
  case 3:
    bVar2 = *param_3;
    (*(unsigned char *)((unsigned char *)&(param_2) + 3)) = 0xff;
    if (bVar2 != 0xff) {
      (*(unsigned char *)((unsigned char *)&(param_2) + 3)) = bVar2 + 1;
    }
    break;
  case 4:
    bVar2 = *param_3;
    (*(unsigned char *)((unsigned char *)&(param_2) + 3)) = 0;
    if (bVar2 != 0) {
      (*(unsigned char *)((unsigned char *)&(param_2) + 3)) = bVar2 - 1;
    }
    break;
  case 5:
    *param_3 = *param_3 & ~(byte)param_4 | (byte)param_4 & ~*param_3;
    return;
  case 6:
    bVar2 = *param_3;
    bVar1 = bVar2 + 1;
    goto LAB_97bd7c90;
  case 7:
    bVar2 = *param_3;
    bVar1 = bVar2 - 1;
LAB_97bd7c90:
    *param_3 = bVar2 & ~(byte)param_4 | bVar1 & (byte)param_4;
    return;
  default:
    return;
  }
  bVar2 = bVar2 & ~(byte)param_4;
LAB_97bd7c34:
  bVar2 = bVar2 | (byte)param_2 & (byte)param_4;
LAB_97bd7c38:
  *param_3 = bVar2;
  return;
}

/* _glpRTCAddAChunk_97bd7cbc @ 0x97bd7cbc (48 bytes) */
int _glpRTCAddAChunk_97bd7cbc(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = *param_1;
  while (iVar1 != 0) {
    *param_2 = iVar1;
    iVar2 = iVar2 + 1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
    iVar1 = *param_1;
  }
  return iVar2;
}

/* _PPCRuntimeCompilerCreate @ 0x97bd7cec (88 bytes) */
int _PPCRuntimeCompilerCreate()
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _calloc(0xe54,1);
  uVar2 = _PPCTextureSamplerCreate();
  *(undefined4 *)(iVar1 + 0xe1c) = uVar2;
  _PPCRasterOpMachineInitialise(iVar1 + 0xe14);
  _PPCRasterOpMachineAttachRuntimeCompiler(iVar1 + 0xe14,iVar1);
  return iVar1;
}

/* _PPCRuntimeCompilerInitialise @ 0x97bd7d44 (76 bytes) */
int _PPCRuntimeCompilerInitialise(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(param_1 + 0xe0c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xe08) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xe4c) = param_2;
  _PPCTextureSamplerInitialise(*(undefined4 *)(param_1 + 0xe1c));
  ((int (*)())_PPCRuntimeCompilerInitialiseRegisterAllocator)(param_1);
  ((int (*)())_PPCRuntimeCompilerInitialiseVariableInfo)(param_1);
  return;
}

/* _PPCRuntimeCompilerInitialiseRegisterAllocator @ 0x97bd7d90 (156 bytes) */
int _PPCRuntimeCompilerInitialiseRegisterAllocator(param_1)
  int param_1;
{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  
  *(undefined4 *)(param_1 + 0xe44) = 0;
  uVar1 = 0;
  do {
    uVar3 = uVar1 + 1;
    ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,uVar1);
    uVar1 = uVar3;
  } while (uVar3 < 0x20);
  uVar1 = *(uint *)(param_1 + 0xe50);
  if ((uVar1 & 1) != 0) {
    iVar4 = 0xc;
    puVar2 = (undefined4 *)(param_1 + 0x48c);
    do {
      *puVar2 = 1;
      puVar2 = puVar2 + 0xe;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    uVar1 = *(uint *)(param_1 + 0xe50);
  }
  if ((uVar1 & 2) != 0) {
    puVar2 = (undefined4 *)(param_1 + 0xbc4);
    iVar4 = 0xb;
    do {
      *puVar2 = 1;
      puVar2 = puVar2 + 0xe;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return;
}

/* _PPCRuntimeCompilerInitialiseVariableInfo @ 0x97bd7e2c (224 bytes) */
int _PPCRuntimeCompilerInitialiseVariableInfo(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  if (*(int *)(param_1 + 0xe00) != 0) {
    _free(*(int *)(param_1 + 0xe00));
    *(undefined4 *)(param_1 + 0xe04) = 0;
    *(undefined4 *)(param_1 + 0xe00) = 0;
  }
  iVar6 = *(int *)(param_1 + 0xe24);
  if (iVar6 != 0) {
    iVar7 = 0;
    iVar8 = 4;
    *(undefined4 *)(param_1 + 0xe04) = 0;
    piVar4 = (int *)(iVar6 + 0x84);
    do {
      iVar1 = *piVar4;
      piVar4 = piVar4 + 3;
      iVar1 = *(int *)(param_1 + 0xe04) + iVar1;
      *(int *)(param_1 + 0xe04) = iVar1;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    uVar2 = _calloc(iVar1,8);
    *(undefined4 *)(param_1 + 0xe00) = uVar2;
    uVar3 = 0;
    do {
      uVar5 = 0;
      if (*(int *)(iVar6 + 0x84) != 0) {
        do {
          iVar8 = uVar5 * 0x10;
          uVar5 = uVar5 + 1;
          *(int *)(iVar7 * 8 + *(int *)(param_1 + 0xe00)) = *(int *)(iVar6 + 0x80) + iVar8;
          iVar7 = iVar7 + 1;
        } while (uVar5 < *(uint *)(iVar6 + 0x84));
      }
      uVar3 = uVar3 + 1;
      iVar6 = iVar6 + 0xc;
    } while (uVar3 < 4);
  }
  return;
}

/* _PPCRuntimeCompilerFree @ 0x97bd7f0c (80 bytes) */
int _PPCRuntimeCompilerFree(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 0xe00) != 0) {
    _free(*(int *)(param_1 + 0xe00));
    *(undefined4 *)(param_1 + 0xe04) = 0;
    *(undefined4 *)(param_1 + 0xe00) = 0;
  }
  _PPCTextureSamplerFree(*(undefined4 *)(param_1 + 0xe1c));
  _free(param_1);
  return;
}

/* _PPCRuntimeCompilerOutputAllRegisters @ 0x97bd7f5c (4 bytes) */
int _PPCRuntimeCompilerOutputAllRegisters()
{
  return;
}

/* _PPCRuntimeCompilerAttachEmulatorContext @ 0x97bd7f60 (12 bytes) */
int _PPCRuntimeCompilerAttachEmulatorContext(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(param_1 + 0xe20) = param_2;
  _PPCRasterOpMachineAttachEmulatorContext(param_1 + 0xe14,param_2);
  return;
}

/* _PPCRuntimeCompilerAttachEmulatorProgram @ 0x97bd7f6c (8 bytes) */
int _PPCRuntimeCompilerAttachEmulatorProgram(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(param_1 + 0xe24) = param_2;
  return;
}

/* _PPCRuntimeCompilerSetOptionFlags @ 0x97bd7f74 (16 bytes) */
int _PPCRuntimeCompilerSetOptionFlags(param_1, param_2)
  int param_1;
  uint param_2;
{
  *(uint *)(param_1 + 0xe50) = *(uint *)(param_1 + 0xe50) | param_2;
  return;
}

/* _PPCRuntimeCompilerCalculateIndirectAddress @ 0x97bd7f84 (224 bytes) */
int _PPCRuntimeCompilerCalculateIndirectAddress(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  ushort uVar1;
  uint *puVar2;
  short sStack00000028;
  
  sStack00000028 = (short)((uint)param_5 >> 0x10);
  puVar2 = *(uint **)(param_1 + 0xe30);
  *puVar2 = ((uint)(param_2 - *(int *)(param_3 * 0xc + *(int *)(param_1 + 0xe24) + 0x80)) >> 4) +
            (int)sStack00000028 & 0xffff | 0x39f00000;
  *(uint **)(param_1 + 0xe30) = puVar2 + 1;
  uVar1 = *(ushort *)(param_3 * 0xc + *(int *)(param_1 + 0xe24) + 0x8a);
  puVar2[2] = 0x1def0010;
  puVar2[1] = uVar1 | 0x71ef0000;
  *(uint **)(param_1 + 0xe30) = puVar2 + 3;
  puVar2[3] = *(ushort *)(param_3 * 0xc + *(int *)(param_1 + 0xe24) + 0x80) | 0x3ee00000;
  *(uint **)(param_1 + 0xe30) = puVar2 + 4;
  puVar2[4] = *(ushort *)(param_3 * 0xc + *(int *)(param_1 + 0xe24) + 0x82) | 0x62f70000;
  puVar2[5] = 0x7defba14;
  *(uint **)(param_1 + 0xe30) = puVar2 + 6;
  return;
}

/* _PPCRuntimeCompilerLoadRegister @ 0x97bd8064 (2736 bytes) */
int _PPCRuntimeCompilerLoadRegister(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  int *param_1;
  uint param_2;
  uint *param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  uint param_7;
  undefined4 param_8;
  int param_9;
  undefined4 param_10;
  undefined4 param_11;
  int param_12;
{
  byte bVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint *puVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int *piVar12;
  uint *puStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  ushort uStack00000030;
  char cStack00000032;
  char cStack00000033;
  undefined4 uStack00000034;
  undefined1 auStack_40 [28];
  
  iVar4 = param_12;
  uVar8 = 0;
  uVar9 = 0;
  uStack00000028 = param_5;
  iVar11 = 0;
  uStack0000002c = param_6;
  (*(unsigned int *)(*(unsigned int *)__builtin_frame_address(0) + 0x30)) = param_7;
  uStack00000034 = param_8;
  if (param_1[0x393] != 0) {
    param_2 = param_2 + 0x20;
  }
  param_1[param_2 * 0xe + 0xc] = param_1[0x391];
  uVar5 = param_1[0x394];
  param_1[0x391] = param_1[0x391] + 1;
  puStack00000020 = param_3;
  uStack00000024 = param_4;
  if ((uVar5 & 4) != 0) {
    uVar5 = param_2;
    if (param_1[0x393] != 0) {
      uVar5 = param_2 - 0x20;
    }
    iVar3 = ((int (*)())_PPCRuntimeCompilerRegisterContainsData)(param_1,uVar5,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                       param_10,param_11,param_12);
    if (iVar3 == 1) {
      return;
    }
    uVar5 = param_1[0x394];
  }
  if (param_1[0x393] == 0) {
    if ((uVar5 & 4) != 0) {
      uVar9 = 0;
      piVar12 = param_1;
      do {
        if ((*piVar12 == 0) &&
           (iVar11 = ((int (*)())_PPCRuntimeCompilerRegisterContainsData)(param_1,uVar9,puStack00000020,uStack00000024,uStack00000028,
                                uStack0000002c,(*(unsigned int *)(*(unsigned int *)__builtin_frame_address(0) + 0x30)),uStack00000034,param_9,param_10,
                                param_11,iVar4), iVar11 == 1)) {
          if (uVar9 != param_2) {
            puVar2 = (uint *)param_1[0x38c];
            *puVar2 = param_2 << 0x15 | uVar9 << 0xb | 0xfc000090;
            param_1[0x38c] = (int)(puVar2 + 1);
            ((int (*)())_PPCRuntimeCompilerSetRegister)(param_1,param_2,puStack00000020,uStack00000024,uStack00000028,uStack0000002c,
                       (*(unsigned int *)(*(unsigned int *)__builtin_frame_address(0) + 0x30)),uStack00000034,param_9,param_10,param_11,0,iVar4);
            piVar12[0xc] = param_1[0x391];
            goto LAB_97bd8938;
          }
          if (*(char *)((int)piVar12 + 0x1a) == cStack00000032) {
            return;
          }
        }
        uVar9 = uVar9 + 1;
        piVar12 = piVar12 + 0xe;
      } while (uVar9 < 0x20);
    }
    if (cStack00000033 == '\0') {
      if (((*(int *)(param_1[0x389] + 0x38) == 0x8804) ||
          (*(int *)(param_1[0x389] + 0x38) == 0x8b30)) && (uStack00000030 == 2)) {
        puVar7 = (uint *)param_1[0x38c];
        *puVar7 = puStack00000020[*(byte *)((int)&STACKARG(0x28) + iVar4)] & 0xffff | 0xc10d0000;
        bVar1 = *(byte *)((int)&STACKARG(0x28) + iVar4);
        param_1[0x38c] = (int)(puVar7 + 1);
        uVar9 = puStack00000020[bVar1];
        puVar2 = puVar7 + 3;
        puVar7[2] = param_2 << 0x15 | 0xec09433a;
        puVar7[1] = uVar9 & 0xffff | 0xc12c0000;
      }
      else {
        puVar2 = (uint *)param_1[0x38c];
        *puVar2 = param_2 << 0x15 | (uStack00000030 + 5) * 0x10000 |
                  puStack00000020[*(byte *)((int)&STACKARG(0x28) + iVar4)] & 0xffff | 0xc0000000;
        puVar2 = puVar2 + 1;
      }
      param_1[0x38c] = (int)puVar2;
    }
    else {
      ((int (*)())_PPCRuntimeCompilerCalculateIndirectAddress)(param_1,puStack00000020,uStack00000024,uStack00000028,uStack0000002c,
                 (*(unsigned int *)(*(unsigned int *)__builtin_frame_address(0) + 0x30)),uStack00000034,param_9);
      puVar2 = (uint *)param_1[0x38c];
      *puVar2 = (uint)*(byte *)((int)&STACKARG(0x28) + iVar4) << 2 | 0x82ef0000;
      puVar2[1] = param_2 << 0x15 | (((*(unsigned int *)(*(unsigned int *)__builtin_frame_address(0) + 0x30)) >> 0x10) + 5) * 0x10000 | 0x7c00bc2e;
      param_1[0x38c] = (int)(puVar2 + 2);
    }
    ((int (*)())_PPCRuntimeCompilerSetRegister)(param_1,param_2,puStack00000020,uStack00000024,uStack00000028,uStack0000002c,
               (*(unsigned int *)(*(unsigned int *)__builtin_frame_address(0) + 0x30)),uStack00000034,param_9,param_10,param_11,0,iVar4);
    return;
  }
  if ((uVar5 & 4) != 0) {
    piVar12 = param_1 + 0x1c0;
    uVar5 = 0;
    do {
      uVar10 = uVar5;
      iVar3 = *piVar12;
      piVar12 = piVar12 + 0xe;
      if (iVar3 == 0) {
        iVar3 = ((int (*)())_PPCRuntimeCompilerRegisterContainsData)(param_1,uVar10,puStack00000020,uStack00000024,uStack00000028,
                           uStack0000002c,(*(unsigned int *)(*(unsigned int *)__builtin_frame_address(0) + 0x30)),uStack00000034,param_9,param_10,param_11,
                           iVar4);
        if ((iVar3 == 3) && (uStack00000030 == 0)) {
          iVar11 = 3;
          uVar9 = uVar10;
        }
        else if (iVar3 - 1U < 2) break;
      }
      uVar5 = uVar10 + 1;
      uVar10 = uVar9;
      iVar3 = iVar11;
    } while (uVar5 < 0x20);
    if (iVar3 != 0) {
      iVar3 = param_2 - 0x20;
      puVar2 = (uint *)param_1[0x38c];
      *puVar2 = iVar3 * 0x200000 | uVar10 << 0x10 | uVar10 << 0xb | 0x10000484;
      param_1[0x38c] = (int)(puVar2 + 1);
      iVar11 = _memcmp(param_1 + uVar10 * 0xe + 0x1c4,&STACKARG(0x28),4);
      if (iVar11 != 0) {
        _PPCRuntimeCompilerBuildTransferSwizzle
                  (auStack_40,param_1 + uVar10 * 0xe + 0x1c4,&STACKARG(0x28));
        _PPCRuntimeCompilerSwizzleRegisterAV(param_1,iVar3,auStack_40);
      }
      ((int (*)())_PPCRuntimeCompilerSetRegister)(param_1,iVar3,puStack00000020,uStack00000024,uStack00000028,uStack0000002c,
                 (*(unsigned int *)(*(unsigned int *)__builtin_frame_address(0) + 0x30)),uStack00000034,param_9,param_10,param_11,0,iVar4);
      param_1[uVar10 * 0xe + 0x1cc] = param_1[0x391];
LAB_97bd8938:
      param_1[0x391] = param_1[0x391] + 1;
      return;
    }
  }
  puVar2 = puStack00000020;
  if (((*(int *)(param_1[0x389] + 0x38) == 0x8804) || (*(int *)(param_1[0x389] + 0x38) == 0x8b30))
     && (uStack00000030 == 2)) {
    if ((param_1[0x394] & 8U) == 0) {
      uVar9 = *puStack00000020;
    }
    else {
      uVar9 = 0;
      if (*puStack00000020 != 0) {
        puVar2 = (uint *)param_1[0x38c];
        *puVar2 = *puStack00000020 & 0xffff | 0x39e00000;
        puVar2[1] = 0x10c0728c;
        uVar9 = (param_2 - 0x20) * 0x200000;
        puVar2[2] = 0x7c6d78ce;
        puVar2[3] = 0x10a3728c;
        puVar2[4] = 0x7c8c78ce;
        puVar2[5] = uVar9 | 0x100419ae;
        puVar2[6] = uVar9 | (param_2 - 0x20) * 0x10000 | 0x1000396e;
        param_1[0x38c] = (int)(puVar2 + 7);
        goto LAB_97bd87b4;
      }
    }
    puVar2 = (uint *)param_1[0x38c];
    *puVar2 = uVar9 & 0xffff | 0x39e00000;
    puVar2[1] = 0x7c6d78ce;
    puVar2[2] = 0x7c8c78ce;
    puVar2[3] = 0x10c0728c;
    puVar2[4] = (param_2 - 0x20) * 0x200000 | 0x100419ae;
    param_1[0x38c] = (int)(puVar2 + 5);
    goto LAB_97bd87b4;
  }
  if (cStack00000033 == '\0') {
    uVar9 = *puStack00000020;
    if (((((uVar9 & 0xf) != 0) || (puStack00000020[1] != uVar9 + 4)) ||
        (puStack00000020[2] != uVar9 + 8)) || (puStack00000020[3] != uVar9 + 0xc)) {
      puVar2 = (uint *)param_1[0x38c];
      *puVar2 = (uStack00000030 + 5) * 0x10000 | uVar9 & 0xffff | 0xc0000000;
      param_1[0x38c] = (int)(puVar2 + 1);
      puVar2[1] = (uStack00000030 + 5) * 0x10000 | (uint)*(ushort *)((int)puStack00000020 + 6) |
                  0xc0200000;
      param_1[0x38c] = (int)(puVar2 + 2);
      puVar2[2] = (uStack00000030 + 5) * 0x10000 | (uint)*(ushort *)((int)puStack00000020 + 10) |
                  0xc0400000;
      param_1[0x38c] = (int)(puVar2 + 3);
      puVar2[3] = (uStack00000030 + 5) * 0x10000 | (uint)*(ushort *)((int)puStack00000020 + 0xe) |
                  0xc0600000;
      puVar2[4] = 0xd0030200;
      puVar2[5] = 0xd0230204;
      puVar2[6] = 0xd0430208;
      puVar2[7] = 0xd063020c;
      puVar2[8] = 0x39e00200;
      puVar2[9] = (param_2 - 0x20) * 0x200000 | 0x7c0378ce;
      param_1[0x38c] = (int)(puVar2 + 10);
      goto LAB_97bd877c;
    }
    if (uVar9 != 0) {
      puVar2 = (uint *)param_1[0x38c];
      *puVar2 = uVar9 & 0xffff | 0x39e00000;
      uVar9 = (param_2 - 0x20) * 0x200000 | (uStack00000030 + 5) * 0x10000 | 0x7c0078ce;
      goto LAB_97bd8640;
    }
    puVar2 = (uint *)param_1[0x38c];
    *puVar2 = (param_2 - 0x20) * 0x200000 | (uStack00000030 + 5) * 0x800 | 0x7c0000ce;
    param_1[0x38c] = (int)(puVar2 + 1);
  }
  else {
    if (uStack00000030 == 0) {
      ((int (*)())_PPCRuntimeCompilerSaveAllTemporariesToMemory)(param_1);
    }
    ((int (*)())_PPCRuntimeCompilerCalculateIndirectAddress)(param_1,puStack00000020,uStack00000024,uStack00000028,uStack0000002c,(*(unsigned int *)(*(unsigned int *)__builtin_frame_address(0) + 0x30)),
               uStack00000034,param_9);
    uVar9 = *puVar2;
    if ((((uVar9 & 0xf) == 0) && (puVar2[1] == uVar9 + 4)) &&
       ((puVar2[2] == uVar9 + 8 && (puVar2[3] == uVar9 + 0xc)))) {
      puVar2 = (uint *)param_1[0x38c];
      *puVar2 = 0x82ef0000;
      uVar9 = (param_2 - 0x20) * 0x200000 | (uStack00000030 + 5) * 0x10000 | 0x7c00b8ce;
LAB_97bd8640:
      puVar2[1] = uVar9;
      param_1[0x38c] = (int)(puVar2 + 2);
    }
    else {
      puVar6 = (undefined4 *)param_1[0x38c];
      *puVar6 = 0x82ef0000;
      puVar6[1] = (uStack00000030 + 5) * 0x10000 | 0x7c00bc2e;
      puVar6[2] = 0x82ef0004;
      puVar6[3] = (uStack00000030 + 5) * 0x10000 | 0x7c20bc2e;
      puVar6[4] = 0x82ef0008;
      puVar6[5] = (uStack00000030 + 5) * 0x10000 | 0x7c40bc2e;
      puVar6[6] = 0x82ef000c;
      puVar6[7] = (uStack00000030 + 5) * 0x10000 | 0x7c60bc2e;
      puVar6[8] = 0xd0030200;
      puVar6[9] = 0xd0230204;
      puVar6[10] = 0xd0430208;
      puVar6[0xb] = 0xd063020c;
      puVar6[0xc] = 0x39e00200;
      puVar6[0xd] = (param_2 - 0x20) * 0x200000 | 0x7c0378ce;
      param_1[0x38c] = (int)(puVar6 + 0xe);
LAB_97bd877c:
      uVar8 = 1;
    }
  }
  if (param_9 - 3U < 2) {
    puVar2 = (uint *)param_1[0x38c];
    *puVar2 = (param_2 - 0x20) * 0x200000 | (param_2 - 0x20) * 0x800 | 0x1000034a;
    param_1[0x38c] = (int)(puVar2 + 1);
  }
LAB_97bd87b4:
  _PPCRuntimeCompilerSwizzleRegisterAV(param_1,param_2 - 0x20,&STACKARG(0x28));
  ((int (*)())_PPCRuntimeCompilerSetRegister)(param_1,param_2 - 0x20,puStack00000020,uStack00000024,uStack00000028,uStack0000002c,
             (*(unsigned int *)(*(unsigned int *)__builtin_frame_address(0) + 0x30)),uStack00000034,param_9,param_10,param_11,uVar8,iVar4);
  iVar4 = _PPCRuntimeCompilerFindVariableInfo
                    (param_1,puStack00000020,uStack00000024,uStack00000028,uStack0000002c,
                     (*(unsigned int *)(*(unsigned int *)__builtin_frame_address(0) + 0x30)),uStack00000034,param_9);
  *(undefined4 *)(iVar4 + 4) = 0;
  return;
}

/* _PPCRuntimeCompilerBackupRegister @ 0x97bd8b14 (2144 bytes) */
int _PPCRuntimeCompilerBackupRegister(param_1, param_2)
  int *param_1;
  uint param_2;
{
  char cVar1;
  byte bVar2;
  bool bVar3;
  undefined4 uVar4;
  byte *pbVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint *puVar8;
  int *piVar9;
  int iVar10;
  int *piVar11;
  uint uVar12;
  int *piVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  uint uVar19;
  uint uVar20;
  int local_60 [4];
  byte local_50;
  byte local_4f;
  byte local_4e;
  byte local_4d;
  undefined4 local_4c;
  undefined4 local_48;
  
  iVar15 = param_1[0x393];
  uVar17 = 0;
  iVar16 = 0;
  bVar3 = false;
  if (iVar15 != 0) {
    param_2 = param_2 + 0x20;
  }
  iVar18 = param_2 * 0x38;
  if (param_1[param_2 * 0xe] == 0) {
    uVar19 = 0;
    piVar11 = param_1;
    do {
      if (iVar15 == 0) {
        if (((uVar19 != param_2) && (*piVar11 == 0)) && (piVar11[0xb] != 0)) {
          iVar15 = ((int (*)())_PPCRuntimeCompilerRegisterContainsData)(param_1,uVar19,param_1[param_2 * 0xe + 2],param_1[param_2 * 0xe + 3],
                              param_1[param_2 * 0xe + 4],param_1[param_2 * 0xe + 5],
                              param_1[param_2 * 0xe + 6],param_1[param_2 * 0xe + 7],
                              param_1[param_2 * 0xe + 8],param_1[param_2 * 0xe + 9],
                              param_1[param_2 * 0xe + 10],param_1[param_2 * 0xe + 1]);
          if (iVar15 == 1) {
            return;
          }
          goto LAB_97bd8c50;
        }
      }
      else if (((uVar19 != param_2 - 0x20) && (piVar11[0x1c0] == 0)) && (piVar11[0x1cb] != 0)) {
        iVar15 = ((int (*)())_PPCRuntimeCompilerRegisterContainsData)(param_1,uVar19,param_1[param_2 * 0xe + 2],param_1[param_2 * 0xe + 3],
                            param_1[param_2 * 0xe + 4],param_1[param_2 * 0xe + 5],
                            param_1[param_2 * 0xe + 6],param_1[param_2 * 0xe + 7],
                            param_1[param_2 * 0xe + 8],param_1[param_2 * 0xe + 9],
                            param_1[param_2 * 0xe + 10],param_1[param_2 * 0xe + 1]);
        if (iVar15 - 1U < 2) {
          return;
        }
LAB_97bd8c50:
        iVar15 = param_1[0x393];
      }
      uVar19 = uVar19 + 1;
      piVar11 = piVar11 + 0xe;
    } while (uVar19 < 0x20);
    iVar10 = 0;
    if (iVar15 != 0) {
      uVar19 = param_2 - 0x20;
      uVar20 = 0;
      iVar15 = uVar19 * 0x38 + 0x708;
      piVar11 = param_1;
      do {
        if (((uVar20 != uVar19) && (piVar11[0x1c0] == 0)) &&
           ((piVar11[0x1cb] != 0 &&
            ((iVar10 = _memcmp(piVar11[0x1c2],param_1[param_2 * 0xe + 2],0x10), iVar10 == 0 &&
             (*(short *)(piVar11 + 0x1c6) == *(short *)(param_1 + param_2 * 0xe + 6))))))) {
          local_4c = 0x10203;
          if (((uint)param_1[uVar19 * 0xe + 0x1c4] >> 8 !=
               (param_1[uVar19 * 0xe + 0x1c4] & 0xffffffU)) &&
             (((*(char *)(param_1 + uVar19 * 0xe + 0x1c4) != '\0' &&
               (*(char *)(param_1 + uVar19 * 0xe + 0x1c4) != -1)) ||
              ((((cVar1 = *(char *)((int)param_1 + uVar19 * 0x38 + 0x711), cVar1 != '\x01' &&
                 (cVar1 != -1)) ||
                ((cVar1 = *(char *)((int)param_1 + uVar19 * 0x38 + 0x712), cVar1 != '\x02' &&
                 (cVar1 != -1)))) ||
               ((cVar1 = *(char *)((int)param_1 + uVar19 * 0x38 + 0x713), cVar1 != '\x03' &&
                (cVar1 != -1)))))))) {
            _PPCRuntimeCompilerBuildTransferSwizzle
                      (&local_50,param_1 + uVar19 * 0xe + 0x1c4,&local_4c);
            _PPCRuntimeCompilerSwizzleRegisterAV(param_1,uVar19,&local_50);
            local_48 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)
                                                   ((int)param_1 + (uint)local_50 + iVar15 + 8),
                                                  *(undefined1 *)
                                                   ((int)param_1 + (uint)local_4f + iVar15 + 8)),
                                         *(undefined1 *)((int)param_1 + (uint)local_4e + iVar15 + 8)
                                        ),
                                *(undefined1 *)((int)param_1 + (uint)local_4d + iVar15 + 8));
            param_1[uVar19 * 0xe + 0x1c4] = local_48;
          }
          if (((uint)piVar11[0x1c4] >> 8 != (piVar11[0x1c4] & 0xffffffU)) &&
             (((((*(char *)(piVar11 + 0x1c4) != '\0' && (*(char *)(piVar11 + 0x1c4) != -1)) ||
                ((*(char *)((int)piVar11 + 0x711) != '\x01' &&
                 (*(char *)((int)piVar11 + 0x711) != -1)))) ||
               ((*(char *)((int)piVar11 + 0x712) != '\x02' &&
                (*(char *)((int)piVar11 + 0x712) != -1)))) ||
              ((*(char *)((int)piVar11 + 0x713) != '\x03' && (*(char *)((int)piVar11 + 0x713) != -1)
               ))))) {
            _PPCRuntimeCompilerBuildTransferSwizzle(&local_50,piVar11 + 0x1c4,&local_4c);
            _PPCRuntimeCompilerSwizzleRegisterAV(param_1,uVar20,&local_50);
            local_48 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)((int)piVar11 + local_50 + 0x710),
                                                  *(undefined1 *)((int)piVar11 + local_4f + 0x710)),
                                         *(undefined1 *)((int)piVar11 + local_4e + 0x710)),
                                *(undefined1 *)((int)piVar11 + local_4d + 0x710));
            piVar11[0x1c4] = local_48;
          }
          local_60[3] = 0;
          iVar16 = 4;
          local_60[0] = 0;
          local_60[1] = 0;
          piVar13 = local_60;
          local_60[2] = 0;
          pbVar5 = (byte *)(param_1 + uVar19 * 0xe + 0x1c4);
          do {
            bVar2 = *pbVar5;
            pbVar5 = pbVar5 + 1;
            if (bVar2 < 4) {
              piVar13[bVar2] = 1;
            }
            iVar16 = iVar16 + -1;
          } while (iVar16 != 0);
          if (local_60[0] + local_60[1] + local_60[2] + local_60[3] == 1) {
            if (local_60[0] == 0) {
              if (local_60[1] == 0) {
                if (local_60[2] == 0) {
                  if (local_60[3] == 0) goto LAB_97bd9024;
                  puVar6 = (undefined4 *)param_1[0x38c];
                  uVar4 = 0x106d6c84;
                }
                else {
                  puVar6 = (undefined4 *)param_1[0x38c];
                  uVar4 = 0x106d492c;
                }
              }
              else {
                puVar6 = (undefined4 *)param_1[0x38c];
                uVar4 = 0x106d4a2c;
              }
            }
            else {
              puVar6 = (undefined4 *)param_1[0x38c];
              uVar4 = 0x106d4b2c;
            }
            *puVar6 = uVar4;
            param_1[0x38c] = (int)(puVar6 + 1);
          }
          else {
            puVar6 = (undefined4 *)param_1[0x38c];
            *puVar6 = 0x10836a8c;
            puVar6[1] = 0x10694c84;
            param_1[0x38c] = (int)(puVar6 + 2);
            uVar17 = 0;
            do {
              uVar12 = uVar17 + 1;
              if (piVar13[uVar17] != 0) {
                uVar14 = 3 - uVar17;
                if (uVar12 < 4) {
                  piVar9 = piVar13 + uVar12;
                  uVar7 = uVar12;
                  do {
                    iVar16 = *piVar9;
                    piVar9 = piVar9 + 1;
                    if (iVar16 != 0) {
                      uVar14 = (uVar7 - uVar17) - 1;
                      break;
                    }
                    uVar7 = uVar7 + 1;
                  } while (uVar7 < 4);
                }
                puVar6 = (undefined4 *)param_1[0x38c];
                *puVar6 = 0x1063212c;
                param_1[0x38c] = (int)(puVar6 + 1);
                if (uVar14 != 0) {
                  puVar6[1] = (uVar14 & 3) << 8 | 0x1063482c;
                  param_1[0x38c] = (int)(puVar6 + 2);
                }
              }
              uVar17 = uVar12;
            } while (uVar12 < 4);
          }
LAB_97bd9024:
          puVar8 = (uint *)param_1[0x38c];
          piVar11 = piVar11 + 0x1c4;
          *puVar8 = uVar20 << 0x15 | uVar20 << 0x10 | uVar19 * 0x800 | 0x100000ea;
          iVar16 = 4;
          param_1[0x38c] = (int)(puVar8 + 1);
          piVar9 = param_1 + uVar19 * 0xe + 0x1c4;
          do {
            iVar15 = *piVar13;
            piVar13 = piVar13 + 1;
            if (iVar15 != 0) {
              *(undefined1 *)piVar11 = *(undefined1 *)piVar9;
            }
            piVar9 = (int *)((int)piVar9 + 1);
            piVar11 = (int *)((int)piVar11 + 1);
            iVar16 = iVar16 + -1;
          } while (iVar16 != 0);
          return;
        }
        uVar20 = uVar20 + 1;
        piVar11 = piVar11 + 0xe;
      } while (uVar20 < 0x20);
      iVar10 = param_1[0x393];
    }
    if (((iVar10 != 0) && (*(short *)(param_1 + param_2 * 0xe + 6) == 0)) &&
       ((*(char *)(param_1 + param_2 * 0xe + 4) == -1 ||
        (((*(char *)((int)param_1 + iVar18 + 0x11) == -1 ||
          (*(char *)((int)param_1 + iVar18 + 0x12) == -1)) ||
         (*(char *)((int)param_1 + iVar18 + 0x13) == -1)))))) {
      iVar15 = _PPCRuntimeCompilerFindVariableInfo
                         (param_1,param_1[param_2 * 0xe + 2],param_1[param_2 * 0xe + 3],
                          param_1[param_2 * 0xe + 4],param_1[param_2 * 0xe + 5],
                          param_1[param_2 * 0xe + 6],param_1[param_2 * 0xe + 7],
                          param_1[param_2 * 0xe + 8]);
      if (*(int *)(iVar15 + 4) != 0) {
        ((int (*)())_PPCRuntimeCompilerSaveRegisterToMemory)(param_1,param_2 - 0x20);
        ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,param_2 - 0x20);
        return;
      }
      iVar10 = param_1[0x393];
    }
    uVar20 = (uint)(iVar10 != 0);
    uVar19 = uVar20 * 0x20;
    if (iVar10 == 0) {
      uVar12 = 0x20;
    }
    else {
      uVar12 = 0x40;
    }
    if (uVar19 < uVar12) {
      iVar15 = uVar12 + uVar20 * -0x20;
      piVar11 = param_1 + uVar20 * 0x1c0;
      do {
        if (((uVar19 != param_2) && (piVar11[0xb] != 0)) &&
           ((iVar16 <= param_1[0x391] - piVar11[0xc] && (piVar11[0xd] == 0)))) {
          bVar3 = true;
          iVar16 = param_1[0x391] - piVar11[0xc];
          uVar17 = uVar19;
        }
        uVar19 = uVar19 + 1;
        piVar11 = piVar11 + 0xe;
        iVar15 = iVar15 + -1;
      } while (iVar15 != 0);
      if (bVar3) {
        if ((*(short *)(param_1 + uVar17 * 0xe + 6) == 0) && (param_1[uVar17 * 0xe] == 0)) {
          if (iVar10 == 0) {
            ((int (*)())_PPCRuntimeCompilerSaveRegisterToMemory)(param_1,uVar17);
          }
          else {
            ((int (*)())_PPCRuntimeCompilerSaveRegisterToMemory)(param_1,uVar17 - 0x20);
            iVar16 = _PPCRuntimeCompilerFindVariableInfo
                               (param_1,param_1[uVar17 * 0xe + 2],param_1[uVar17 * 0xe + 3],
                                param_1[uVar17 * 0xe + 4],param_1[uVar17 * 0xe + 5],
                                param_1[uVar17 * 0xe + 6],param_1[uVar17 * 0xe + 7],
                                param_1[uVar17 * 0xe + 8]);
            *(undefined4 *)(iVar16 + 4) = 1;
          }
          iVar10 = param_1[0x393];
        }
        if (iVar10 == 0) {
          iVar16 = param_1[param_2 * 0xe + 7];
          uVar19 = uVar17;
        }
        else {
          iVar16 = param_1[param_2 * 0xe + 7];
          uVar19 = uVar17 - 0x20;
        }
        ((int (*)())_PPCRuntimeCompilerSetRegister)(param_1,uVar19,param_1[param_2 * 0xe + 2],param_1[param_2 * 0xe + 3],
                   param_1[param_2 * 0xe + 4],param_1[param_2 * 0xe + 5],param_1[param_2 * 0xe + 6],
                   iVar16,param_1[param_2 * 0xe + 8],param_1[param_2 * 0xe + 9],
                   param_1[param_2 * 0xe + 10],param_1[param_2 * 0xe + 0xd],
                   param_1[param_2 * 0xe + 1]);
        if (param_1[0x393] == 0) {
          puVar8 = (uint *)param_1[0x38c];
          uVar17 = uVar17 << 0x15 | param_2 << 0xb | 0xfc000090;
        }
        else {
          puVar8 = (uint *)param_1[0x38c];
          uVar17 = (uVar17 - 0x20) * 0x200000 | (param_2 - 0x20) * 0x10000 |
                   (param_2 - 0x20) * 0x800 | 0x10000484;
        }
        *puVar8 = uVar17;
        param_1[0x38c] = (int)(puVar8 + 1);
        return;
      }
    }
    if (*(short *)(param_1 + param_2 * 0xe + 6) == 0) {
      if (iVar10 != 0) {
        param_2 = param_2 - 0x20;
      }
      ((int (*)())_PPCRuntimeCompilerSaveRegisterToMemory)(param_1,param_2);
    }
  }
  return;
}

/* _PPCRuntimeCompilerSaveAllTemporariesToMemory @ 0x97bd9374 (120 bytes) */
int _PPCRuntimeCompilerSaveAllTemporariesToMemory(param_1)
  int param_1;
{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    uVar1 = uVar2;
    if (*(int *)(param_1 + 0xe4c) != 0) {
      uVar1 = uVar2 + 0x20;
    }
    if (*(short *)(uVar1 * 0x38 + param_1 + 0x18) == 0) {
      ((int (*)())_PPCRuntimeCompilerSaveRegisterToMemory)(param_1,uVar2);
      ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,uVar2);
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x20);
  return;
}

/* _PPCRuntimeCompilerSaveRegisterToMemory @ 0x97bd93ec (1400 bytes) */
int _PPCRuntimeCompilerSaveRegisterToMemory(param_1, param_2)
  int param_1;
  int param_2;
{
  uint *puVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  uint *puVar6;
  uint uVar7;
  int iVar8;
  uint *local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  uint local_34;
  
  if (*(int *)(param_1 + 0xe4c) == 0) {
    iVar8 = param_2 * 0x38 + param_1;
    if (*(int *)(param_1 + param_2 * 0x38) != 0) {
      return;
    }
    puVar6 = *(uint **)(param_1 + 0xe30);
    uVar2 = param_2 << 0x15 | (*(ushort *)(iVar8 + 0x18) + 5) * 0x10000 |
            *(uint *)((uint)*(byte *)(iVar8 + *(int *)(iVar8 + 4) + 0x10) * 4 + *(int *)(iVar8 + 8))
            & 0xffff | 0xd0000000;
LAB_97bd9944:
    *puVar6 = uVar2;
  }
  else {
    iVar8 = param_2 * 0x38 + param_1;
    if (*(int *)(iVar8 + 0x700) != 0) {
      return;
    }
    _memcpy(&local_50,iVar8 + 0x708,0x24);
    puVar1 = local_50;
    iVar8 = *(ushort *)(iVar8 + 0x718) + 5;
    _PPEmulatorVariableMaskFromSwizzle(&local_50);
    if ((*(unsigned char *)((unsigned char *)&(local_34) + 0)) == '\x0f') {
      iVar4 = *(int *)(*(int *)(param_1 + 0xe24) + 0x38);
      if ((((iVar4 == 0x8804) || (iVar4 == 0x8b30)) && ((*(unsigned short *)((unsigned char *)&(local_40) + 0)) == 1)) && (*puVar1 == 0)) {
        puVar6 = *(uint **)(param_1 + 0xe30);
        *puVar6 = param_2 << 0x10 | param_2 << 0xb | 0x12600484;
        *(uint **)(param_1 + 0xe30) = puVar6 + 1;
        return;
      }
      if ((char)local_40 == '\0') {
        if (*puVar1 == 0) {
          puVar6 = *(uint **)(param_1 + 0xe30);
          uVar2 = param_2 << 0x15 | iVar8 * 0x800 | 0x7c0001ce;
          goto LAB_97bd9944;
        }
        puVar6 = *(uint **)(param_1 + 0xe30);
        uVar7 = *puVar1 & 0xffff | 0x39e00000;
        uVar2 = param_2 << 0x15 | iVar8 * 0x10000 | 0x7c0079ce;
      }
      else {
        ((int (*)())_PPCRuntimeCompilerCalculateIndirectAddress)(param_1,local_50,local_4c,local_48,local_44,local_40,local_3c,local_38);
        uVar7 = 0x82ef0000;
        puVar6 = *(uint **)(param_1 + 0xe30);
        uVar2 = param_2 << 0x15 | iVar8 * 0x10000 | 0x7c00b9ce;
      }
    }
    else {
      iVar4 = *(int *)(*(int *)(param_1 + 0xe24) + 0x38);
      if (((iVar4 == 0x8804) || (iVar4 == 0x8b30)) && ((*(unsigned short *)((unsigned char *)&(local_40) + 0)) == 1)) {
        puVar5 = *(undefined4 **)(param_1 + 0xe30);
        puVar5[1] = 0x10836a8c;
        *puVar5 = 0x10694c84;
        *(undefined4 **)(param_1 + 0xe30) = puVar5 + 3;
        uVar3 = 0x1063212c;
        if ((local_34 & 0x1000000) == 0) {
          uVar3 = 0x1063492c;
        }
        puVar5[2] = uVar3;
        puVar5 = *(undefined4 **)(param_1 + 0xe30);
        uVar3 = 0x1063212c;
        *(undefined4 **)(param_1 + 0xe30) = puVar5 + 1;
        if ((local_34 & 0x2000000) == 0) {
          uVar3 = 0x1063492c;
        }
        *puVar5 = uVar3;
        puVar5 = *(undefined4 **)(param_1 + 0xe30);
        uVar3 = 0x1063212c;
        *(undefined4 **)(param_1 + 0xe30) = puVar5 + 1;
        if ((local_34 & 0x4000000) == 0) {
          uVar3 = 0x1063492c;
        }
        *puVar5 = uVar3;
        puVar5 = *(undefined4 **)(param_1 + 0xe30);
        uVar3 = 0x1063212c;
        *(undefined4 **)(param_1 + 0xe30) = puVar5 + 1;
        if ((local_34 & 0x8000000) == 0) {
          uVar3 = 0x1063492c;
        }
        *puVar5 = uVar3;
        puVar6 = *(uint **)(param_1 + 0xe30);
        uVar2 = param_2 << 0xb | 0x127300ea;
        goto LAB_97bd9944;
      }
      iVar4 = *(int *)(*(int *)(param_1 + 0xe24) + 0x38);
      if (((iVar4 == 0x8804) || (iVar4 == 0x8b30)) && ((*(unsigned short *)((unsigned char *)&(local_40) + 0)) == 9)) {
        puVar5 = *(undefined4 **)(param_1 + 0xe30);
        *puVar5 = 0x39e00210;
        puVar5[1] = param_2 << 0x15 | 0x7c0379ce;
        puVar6 = puVar5 + 3;
        puVar5[2] = 0xc1a30218;
        goto LAB_97bd994c;
      }
      if ((char)local_40 == '\0') {
        if ((local_34 & 0x1000000) != 0) {
          puVar6 = *(uint **)(param_1 + 0xe30);
          *puVar6 = (ushort)*puVar1 | 0x39e00000;
          puVar6[1] = param_2 << 0x15 | iVar8 * 0x10000 | 0x7c00798e;
          *(uint **)(param_1 + 0xe30) = puVar6 + 2;
        }
        if ((local_34 & 0x2000000) != 0) {
          puVar6 = *(uint **)(param_1 + 0xe30);
          *puVar6 = *(ushort *)((int)puVar1 + 6) | 0x39e00000;
          puVar6[1] = param_2 << 0x15 | iVar8 * 0x10000 | 0x7c00798e;
          *(uint **)(param_1 + 0xe30) = puVar6 + 2;
        }
        if ((local_34 & 0x4000000) != 0) {
          puVar6 = *(uint **)(param_1 + 0xe30);
          *puVar6 = *(ushort *)((int)puVar1 + 10) | 0x39e00000;
          puVar6[1] = param_2 << 0x15 | iVar8 * 0x10000 | 0x7c00798e;
          *(uint **)(param_1 + 0xe30) = puVar6 + 2;
        }
        if ((local_34 & 0x8000000) == 0) {
          return;
        }
        puVar6 = *(uint **)(param_1 + 0xe30);
        uVar7 = *(ushort *)((int)puVar1 + 0xe) | 0x39e00000;
        uVar2 = param_2 << 0x15 | iVar8 * 0x10000 | 0x7c00798e;
      }
      else {
        ((int (*)())_PPCRuntimeCompilerCalculateIndirectAddress)(param_1,local_50,local_4c,local_48,local_44,local_40,local_3c,local_38);
        if ((local_34 & 0x1000000) != 0) {
          puVar5 = *(undefined4 **)(param_1 + 0xe30);
          *puVar5 = 0x82ef0000;
          puVar5[1] = param_2 << 0x15 | iVar8 * 0x10000 | 0x7c00b98e;
          *(undefined4 **)(param_1 + 0xe30) = puVar5 + 2;
        }
        if ((local_34 & 0x2000000) != 0) {
          puVar5 = *(undefined4 **)(param_1 + 0xe30);
          *puVar5 = 0x82ef0004;
          puVar5[1] = param_2 << 0x15 | iVar8 * 0x10000 | 0x7c00b98e;
          *(undefined4 **)(param_1 + 0xe30) = puVar5 + 2;
        }
        if ((local_34 & 0x4000000) != 0) {
          puVar5 = *(undefined4 **)(param_1 + 0xe30);
          *puVar5 = 0x82ef0008;
          puVar5[1] = param_2 << 0x15 | iVar8 * 0x10000 | 0x7c00b98e;
          *(undefined4 **)(param_1 + 0xe30) = puVar5 + 2;
        }
        if ((local_34 & 0x8000000) == 0) {
          return;
        }
        puVar6 = *(uint **)(param_1 + 0xe30);
        uVar7 = 0x82ef000c;
        uVar2 = param_2 << 0x15 | iVar8 * 0x10000 | 0x7c00b98e;
      }
    }
    *puVar6 = uVar7;
    puVar6 = puVar6 + 1;
    *puVar6 = uVar2;
  }
  puVar6 = puVar6 + 1;
LAB_97bd994c:
  *(uint **)(param_1 + 0xe30) = puVar6;
  return;
}

/* _PPCRuntimeCompilerDirtyRegister @ 0x97bd9964 (112 bytes) */
int _PPCRuntimeCompilerDirtyRegister(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  if (*(int *)(param_1 + 0xe4c) != 0) {
    param_2 = param_2 + 0x20;
  }
  iVar1 = param_2 * 0x38 + param_1;
  *(undefined4 *)(param_2 * 0x38 + param_1) = 1;
  *(undefined4 *)(iVar1 + 4) = 0;
  *(undefined4 *)(iVar1 + 8) = 0;
  *(undefined4 *)(iVar1 + 0x28) = 0;
  *(undefined4 *)(iVar1 + 0xc) = 0;
  *(undefined4 *)(iVar1 + 0x10) = 0;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  *(undefined4 *)(iVar1 + 0x20) = 0;
  *(undefined4 *)(iVar1 + 0x24) = 0;
  *(undefined4 *)(iVar1 + 0x34) = 0;
  *(undefined1 *)(iVar1 + 0x13) = 0xff;
  *(undefined1 *)(iVar1 + 0x10) = 0xff;
  *(undefined1 *)(iVar1 + 0x11) = 0xff;
  *(undefined1 *)(iVar1 + 0x12) = 0xff;
  *(undefined4 *)(iVar1 + 0x30) = 0;
  return;
}

/* _PPCRuntimeCompilerDirtyRegistersWithData @ 0x97bd99d4 (436 bytes) */
int _PPCRuntimeCompilerDirtyRegistersWithData(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
  undefined4 param_11;
{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  
  uVar2 = param_11;
  uVar7 = 0;
  uStack0000001c = param_2;
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  if (*(int *)(param_1 + 0xe4c) == 0) {
    do {
      iVar6 = ((int (*)())_PPCRuntimeCompilerRegisterContainsData)(param_1,uVar7,uStack0000001c,uStack00000020,uStack00000024,uStack00000028,
                         uStack0000002c,uStack00000030,uStack00000034,param_9,param_10,uVar2);
      if (iVar6 == 1) {
        ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,uVar7);
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < 0x20);
  }
  else {
    iVar6 = 0;
    do {
      iVar3 = ((int (*)())_PPCRuntimeCompilerRegisterContainsData)(param_1,uVar7,uStack0000001c,uStack00000020,uStack00000024,uStack00000028,
                         uStack0000002c,uStack00000030,uStack00000034,param_9,param_10,uVar2);
      if (iVar3 - 1U < 3) {
        uVar4 = 0;
        iVar3 = iVar6 + param_1 + 0x700;
        do {
          iVar8 = 4;
          pcVar5 = (char *)&STACKARG(0x24);
          do {
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
            if (*(char *)(iVar3 + 0x10) == cVar1) {
              *(undefined1 *)(iVar3 + 0x10) = 0xff;
            }
            iVar8 = iVar8 + -1;
          } while (iVar8 != 0);
          uVar4 = uVar4 + 1;
          iVar3 = iVar3 + 1;
        } while (uVar4 < 4);
        iVar3 = iVar6 + param_1;
        if ((((*(char *)(iVar3 + 0x710) == -1) && (*(char *)(iVar3 + 0x711) == -1)) &&
            (*(char *)(iVar3 + 0x712) == -1)) && (*(char *)(iVar3 + 0x713) == -1)) {
          ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,uVar7);
        }
      }
      uVar7 = uVar7 + 1;
      iVar6 = iVar6 + 0x38;
    } while (uVar7 < 0x20);
  }
  return;
}

/* _PPCRuntimeCompilerDirtyRegistersWithIndirectData @ 0x97bd9b88 (136 bytes) */
int _PPCRuntimeCompilerDirtyRegistersWithIndirectData(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  
  iVar1 = 0;
  if (*(int *)(param_1 + 0xe4c) != 0) {
    iVar1 = 0x20;
  }
  iVar1 = iVar1 * 0x38;
  uVar2 = 0;
  pcVar3 = (char *)(iVar1 + param_1 + 0x1b);
  do {
    if ((*(int *)(iVar1 + param_1) == 0) && (*pcVar3 != '\0')) {
      ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,uVar2);
    }
    uVar2 = uVar2 + 1;
    iVar1 = iVar1 + 0x38;
    pcVar3 = pcVar3 + 0x38;
  } while (uVar2 < 0x20);
  return;
}

/* _PPCRuntimeCompilerDirtyRegistersContainingAttributes @ 0x97bd9c10 (136 bytes) */
int _PPCRuntimeCompilerDirtyRegistersContainingAttributes(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  short *psVar3;
  
  iVar1 = 0;
  if (*(int *)(param_1 + 0xe4c) != 0) {
    iVar1 = 0x20;
  }
  iVar1 = iVar1 * 0x38;
  uVar2 = 0;
  psVar3 = (short *)(iVar1 + param_1 + 0x18);
  do {
    if ((*(int *)(iVar1 + param_1) == 0) && (*psVar3 == 2)) {
      ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,uVar2);
    }
    uVar2 = uVar2 + 1;
    iVar1 = iVar1 + 0x38;
    psVar3 = psVar3 + 0x1c;
  } while (uVar2 < 0x20);
  return;
}

/* _PPCRuntimeCompilerDirtyRegistersContainingTemps @ 0x97bd9c98 (136 bytes) */
int _PPCRuntimeCompilerDirtyRegistersContainingTemps(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  short *psVar3;
  
  iVar1 = 0;
  if (*(int *)(param_1 + 0xe4c) != 0) {
    iVar1 = 0x20;
  }
  iVar1 = iVar1 * 0x38;
  uVar2 = 0;
  psVar3 = (short *)(iVar1 + param_1 + 0x18);
  do {
    if ((*(int *)(iVar1 + param_1) == 0) && (*psVar3 == 0)) {
      ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,uVar2);
    }
    uVar2 = uVar2 + 1;
    iVar1 = iVar1 + 0x38;
    psVar3 = psVar3 + 0x1c;
  } while (uVar2 < 0x20);
  return;
}

/* _PPCRuntimeCompilerDirtyRegistersContainingParams @ 0x97bd9d20 (136 bytes) */
int _PPCRuntimeCompilerDirtyRegistersContainingParams(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  int *piVar3;
  
  iVar1 = 0;
  if (*(int *)(param_1 + 0xe4c) != 0) {
    iVar1 = 0x20;
  }
  uVar2 = 0;
  piVar3 = (int *)(iVar1 * 0x38 + param_1);
  do {
    if (((*piVar3 == 0) && (piVar3[3] == 3)) && (piVar3[0xd] == 0)) {
      ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,uVar2);
    }
    uVar2 = uVar2 + 1;
    piVar3 = piVar3 + 0xe;
  } while (uVar2 < 0x20);
  return;
}

/* _PPCRuntimeCompilerSetRegister @ 0x97bd9da8 (148 bytes) */
int _PPCRuntimeCompilerSetRegister(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
  undefined4 param_11;
  undefined4 param_12;
  undefined4 param_13;
{
  int iVar1;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  
  if (*(int *)(param_1 + 0xe4c) != 0) {
    param_2 = param_2 + 0x20;
  }
  *(undefined4 *)(param_2 * 0x38 + param_1) = 0;
  iVar1 = param_2 * 0x38 + param_1;
  *(undefined4 *)(iVar1 + 4) = param_13;
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  _memcpy(iVar1 + 8,&STACKARG(0x20),0x24);
  *(undefined4 *)(iVar1 + 0x34) = param_12;
  *(undefined4 *)(iVar1 + 0x30) = *(undefined4 *)(param_1 + 0xe44);
  *(int *)(param_1 + 0xe44) = *(int *)(param_1 + 0xe44) + 1;
  return;
}

/* _PPCRuntimeCompilerRegisterContainsData @ 0x97bd9e3c (560 bytes) */
int _PPCRuntimeCompilerRegisterContainsData(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  uint param_8;
  undefined4 param_9;
  undefined4 param_10;
  undefined4 param_11;
  int param_12;
{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  short sStack00000030;
  char cStack00000033;
  uint uStack00000034;
  int local_20 [6];
  
  local_20[3] = 0;
  local_20[0] = 0;
  local_20[1] = 0;
  local_20[2] = 0;
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  (*(short *)(*(unsigned int *)__builtin_frame_address(0) + 0x30)) = param_7;
  uStack00000034 = param_8;
  if (*(int *)(param_1 + 0xe4c) == 0) {
    iVar2 = param_2 * 0x38 + param_1;
    if ((((*(int *)(param_1 + param_2 * 0x38) == 0) &&
         (iVar7 = _memcmp(*(undefined4 *)(iVar2 + 8),param_3,0x10), iVar7 == 0)) &&
        (*(short *)(iVar2 + 0x18) == sStack00000030)) &&
       (((*(char *)(iVar2 + *(int *)(iVar2 + 4) + 0x10) ==
          *(char *)((int)&STACKARG(0x28) + param_12) && (cStack00000033 == '\0')) &&
        (*(char *)(iVar2 + 0x1b) == '\0')))) {
      return 1;
    }
  }
  else {
    iVar2 = (param_2 + 0x20) * 0x38;
    iVar7 = iVar2 + param_1;
    if ((*(int *)(param_1 + iVar2) == 0) &&
       (iVar2 = _memcmp(*(undefined4 *)(iVar7 + 8),param_3,0x10), iVar2 == 0)) {
      if ((*(short *)(iVar7 + 0x18) == sStack00000030) &&
         ((cStack00000033 == '\0' && (*(char *)(iVar7 + 0x1b) == '\0')))) {
        iVar2 = _memcmp(iVar7 + 0x10,&STACKARG(0x28),uStack00000034 >> 0x10 & 0xff);
        if (iVar2 == 0) {
          return 1;
        }
        uVar6 = 0;
        piVar4 = local_20;
        do {
          if ((uVar6 < (uStack00000034 >> 0x10 & 0xff)) &&
             (*(byte *)((int)&STACKARG(0x28) + uVar6) < 4)) {
            uVar5 = 0;
            pbVar3 = (byte *)(iVar7 + 0x10);
            do {
              bVar1 = *pbVar3;
              pbVar3 = pbVar3 + 1;
              if (bVar1 == *(byte *)((int)&STACKARG(0x28) + uVar6)) goto LAB_97bd9f54;
              uVar5 = uVar5 + 1;
            } while (uVar5 < 4);
          }
          else {
LAB_97bd9f54:
            *piVar4 = 1;
          }
          uVar6 = uVar6 + 1;
          piVar4 = piVar4 + 1;
          if (3 < uVar6) {
            if ((((local_20[0] != 0) && (local_20[1] != 0)) && (local_20[2] != 0)) &&
               (local_20[3] != 0)) {
              return 2;
            }
            if (((local_20[0] == 0) && (local_20[1] == 0)) &&
               ((local_20[2] == 0 && (local_20[3] == 0)))) {
              return 0;
            }
            return 3;
          }
        } while( true );
      }
    }
  }
  return 0;
}

