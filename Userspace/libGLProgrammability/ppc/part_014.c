#include "decls.h"

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
  int iVar12;
  float *pfVar13;
  uint uVar14;
  undefined1 uStack_2e;
  
  uVar14 = 0;
  iVar12 = *param_1;
  iVar7 = *(int *)(iVar12 + 0xd80);
  uVar6 = *(uint *)(iVar7 + 0x48);
  uVar11 = *(uint *)(iVar7 + 0x3c);
  uVar4 = *(uint *)(iVar7 + 0x4c) >> 0x18;
  fVar3 = *(float *)(*(int *)(iVar12 + 0xdf0) + 0xa38);
  pfVar13 = *(float **)(iVar12 + 0xda8);
  pbVar8 = *(byte **)(iVar12 + 0xdac);
  bVar1 = (uVar11 >> 6 & 1) == 0;
  uVar9 = *(uint *)(iVar7 + 0x4c) >> 8 & 0xff;
  uVar10 = *(uint *)(*(int *)(iVar12 + 0xd80) + 0x70);
  if (bVar1) {
    uStack_2e = 0xff;
  }
  else {
    uStack_2e = (undefined1)(uVar10 >> 8);
  }
  bVar5 = (uVar11 & 2) != 0;
  if (bVar5) {
    switch(uVar6 >> 0xc & 7) {
    case 0:
      uVar14 = 0;
      break;
    case 1:
      uVar14 = (uint)((uVar4 & uVar9) < (uVar9 & *pbVar8));
      break;
    case 2:
      uVar14 = (uint)((uVar4 & uVar9) == (uVar9 & *pbVar8));
      break;
    case 3:
      uVar14 = (uint)((uVar4 & uVar9) <= (uVar9 & *pbVar8));
      break;
    case 4:
      uVar14 = (uint)((uVar9 & *pbVar8) < (uVar4 & uVar9));
      break;
    case 5:
      uVar14 = -((*pbVar8 ^ uVar4) & uVar9) >> 0x1f;
      break;
    case 6:
      uVar14 = (uint)((uVar9 & *pbVar8) <= (uVar4 & uVar9));
      break;
    case 7:
      uVar14 = 1;
    }
    if (uVar14 == 0) {
      ((int (*)())_InterpreterRasterOpMachineUpdateStencilBuffer)(uVar6 >> 0xf & 7,uVar4,pbVar8,uStack_2e);
      return true;
    }
  }
  if ((uVar11 & 4) == 0) {
    if (bVar5) {
      ((int (*)())_InterpreterRasterOpMachineUpdateStencilBuffer)(uVar6 >> 0x15 & 7,uVar4,pbVar8,uStack_2e);
    }
    return uVar14 == 0;
  }
  switch(*(uint *)(*(int *)(iVar12 + 0xd80) + 0x50) & 7) {
  case 0:
    uVar14 = 0;
    break;
  case 1:
    uVar14 = (uint)(fVar3 < *pfVar13);
    break;
  case 2:
    uVar14 = (uint)(fVar3 == *pfVar13);
    break;
  case 3:
    bVar2 = fVar3 <= *pfVar13;
    goto LAB_97bd67ac;
  case 4:
    uVar14 = (uint)(*pfVar13 < fVar3);
    break;
  case 5:
    uVar14 = (uint)(fVar3 != *pfVar13);
    break;
  case 6:
    bVar2 = *pfVar13 <= fVar3;
LAB_97bd67ac:
    uVar14 = (uint)bVar2;
    break;
  case 7:
    uVar14 = 1;
  }
  if (uVar14 == 0) {
    if (bVar5) {
      ((int (*)())_InterpreterRasterOpMachineUpdateStencilBuffer)(uVar6 >> 0x12 & 7,uVar4,pbVar8,uStack_2e);
    }
  }
  else {
    if (bVar5) {
      ((int (*)())_InterpreterRasterOpMachineUpdateStencilBuffer)(uVar6 >> 0x15 & 7,uVar4,pbVar8,uStack_2e);
    }
    if ((bVar1) || ((uVar10 & 0x10000) != 0)) {
      *pfVar13 = fVar3;
    }
  }
  return uVar14 == 0;
}

/* _InterpreterRasterOpMachine_AlphaTest @ 0x97bd683c (1548 bytes) */
int _InterpreterRasterOpMachine_AlphaTest(param_1, param_2)
  int *param_1;
  int param_2;
{
  float fVar1;
  uint uVar2;
  float fVar3;
  uint uVar4;
  bool bVar5;
  double dVar6;
  
  fVar1 = *(float *)(*(int *)(*param_1 + 0xd80) + 0x44);
  uVar4 = *(uint *)(*(int *)(*param_1 + 0xd80) + 0x40);
  uVar2 = _PPEmulatorFramebufferFormat();
  bVar5 = false;
  if ((uVar2 & 0x1c000) == 0) {
    switch(uVar4 & 7) {
    case 0:
switchD_97bd6924_caseD_0:
      bVar5 = false;
      break;
    case 1:
      bVar5 = *(float *)(param_2 + 0xc) < fVar1;
      break;
    case 2:
      bVar5 = *(float *)(param_2 + 0xc) == fVar1;
      break;
    case 3:
      bVar5 = *(float *)(param_2 + 0xc) <= fVar1;
      break;
    case 4:
      bVar5 = fVar1 < *(float *)(param_2 + 0xc);
      break;
    case 5:
      bVar5 = *(float *)(param_2 + 0xc) != fVar1;
      break;
    case 6:
      bVar5 = fVar1 <= *(float *)(param_2 + 0xc);
      break;
    case 7:
switchD_97bd6924_caseD_7:
      bVar5 = true;
    }
  }
  else {
    fVar3 = *(float *)(param_2 + 0xc);
    if (TAllocation__guardBlockSize <= fVar3) {
      if (FLOAT_97c3acd8 < fVar3) {
        fVar3 = 1.0;
      }
    }
    else {
      fVar3 = 0.0;
    }
    if (TAllocation__guardBlockSize <= fVar1) {
      if (FLOAT_97c3acd8 < fVar1) {
        fVar1 = 1.0;
      }
    }
    else {
      fVar1 = 0.0;
    }
    switch(uVar4 & 7) {
    case 0:
      goto switchD_97bd6924_caseD_0;
    case 1:
      fVar3 = fVar3 * FLOAT_97c3acbc + FLOAT_97c3acc0;
      dVar6 = (double)fVar3;
      if (DOUBLE_97c30a78 <= dVar6) {
        uVar2 = (int)(dVar6 - DOUBLE_97c30a78) ^ 0x80000000;
      }
      else {
        uVar2 = (uint)fVar3;
      }
      fVar1 = fVar1 * FLOAT_97c3acbc + FLOAT_97c3acc0;
      dVar6 = (double)fVar1;
      if (DOUBLE_97c30a78 <= dVar6) {
        uVar4 = (int)(dVar6 - DOUBLE_97c30a78) ^ 0x80000000;
      }
      else {
        uVar4 = (uint)fVar1;
      }
      bVar5 = uVar2 < uVar4;
      break;
    case 2:
      fVar3 = fVar3 * FLOAT_97c3acbc + FLOAT_97c3acc0;
      dVar6 = (double)fVar3;
      if (DOUBLE_97c30a78 <= dVar6) {
        uVar2 = (int)(dVar6 - DOUBLE_97c30a78) ^ 0x80000000;
      }
      else {
        uVar2 = (uint)fVar3;
      }
      fVar1 = fVar1 * FLOAT_97c3acbc + FLOAT_97c3acc0;
      dVar6 = (double)fVar1;
      if (DOUBLE_97c30a78 <= dVar6) {
        uVar4 = (int)(dVar6 - DOUBLE_97c30a78) ^ 0x80000000;
      }
      else {
        uVar4 = (uint)fVar1;
      }
      bVar5 = uVar2 == uVar4;
      break;
    case 3:
      fVar3 = fVar3 * FLOAT_97c3acbc + FLOAT_97c3acc0;
      dVar6 = (double)fVar3;
      if (DOUBLE_97c30a78 <= dVar6) {
        uVar2 = (int)(dVar6 - DOUBLE_97c30a78) ^ 0x80000000;
      }
      else {
        uVar2 = (uint)fVar3;
      }
      fVar1 = fVar1 * FLOAT_97c3acbc + FLOAT_97c3acc0;
      dVar6 = (double)fVar1;
      if (DOUBLE_97c30a78 <= dVar6) {
        uVar4 = (int)(dVar6 - DOUBLE_97c30a78) ^ 0x80000000;
      }
      else {
        uVar4 = (uint)fVar1;
      }
      bVar5 = uVar2 <= uVar4;
      break;
    case 4:
      fVar3 = fVar3 * FLOAT_97c3acbc + FLOAT_97c3acc0;
      dVar6 = (double)fVar3;
      if (DOUBLE_97c30a78 <= dVar6) {
        uVar2 = (int)(dVar6 - DOUBLE_97c30a78) ^ 0x80000000;
      }
      else {
        uVar2 = (uint)fVar3;
      }
      fVar1 = fVar1 * FLOAT_97c3acbc + FLOAT_97c3acc0;
      dVar6 = (double)fVar1;
      if (DOUBLE_97c30a78 <= dVar6) {
        uVar4 = (int)(dVar6 - DOUBLE_97c30a78) ^ 0x80000000;
      }
      else {
        uVar4 = (uint)fVar1;
      }
      bVar5 = uVar4 < uVar2;
      break;
    case 5:
      fVar3 = fVar3 * FLOAT_97c3acbc + FLOAT_97c3acc0;
      dVar6 = (double)fVar3;
      if (DOUBLE_97c30a78 <= dVar6) {
        uVar2 = (int)(dVar6 - DOUBLE_97c30a78) ^ 0x80000000;
      }
      else {
        uVar2 = (uint)fVar3;
      }
      fVar1 = fVar1 * FLOAT_97c3acbc + FLOAT_97c3acc0;
      dVar6 = (double)fVar1;
      if (DOUBLE_97c30a78 <= dVar6) {
        uVar4 = (int)(dVar6 - DOUBLE_97c30a78) ^ 0x80000000;
      }
      else {
        uVar4 = (uint)fVar1;
      }
      bVar5 = uVar2 != uVar4;
      break;
    case 6:
      fVar3 = fVar3 * FLOAT_97c3acbc + FLOAT_97c3acc0;
      dVar6 = (double)fVar3;
      if (DOUBLE_97c30a78 <= dVar6) {
        uVar2 = (int)(dVar6 - DOUBLE_97c30a78) ^ 0x80000000;
      }
      else {
        uVar2 = (uint)fVar3;
      }
      fVar1 = fVar1 * FLOAT_97c3acbc + FLOAT_97c3acc0;
      dVar6 = (double)fVar1;
      if (DOUBLE_97c30a78 <= dVar6) {
        uVar4 = (int)(dVar6 - DOUBLE_97c30a78) ^ 0x80000000;
      }
      else {
        uVar4 = (uint)fVar1;
      }
      bVar5 = uVar4 <= uVar2;
      break;
    case 7:
      goto switchD_97bd6924_caseD_7;
    }
  }
  return bVar5 ^ 1;
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
  uint uVar5;
  uint uVar6;
  int iVar7;
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
  
  uVar6 = *(uint *)(*(int *)(*param_1 + 0xd80) + 0x58);
  iVar7 = *(int *)(*(int *)(*param_1 + 0xd9c) + 0xd8) + 0x2d70;
  uVar5 = _PPEmulatorFramebufferFormat();
  fVar2 = FLOAT_97c3acd8;
  if ((uVar5 & 0x8000000) == 0) {
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
  if ((1 < (uVar6 >> 0x10 & 7) - 3) || (1 < (uVar6 >> 0x13 & 7) - 3)) {
    ((int (*)())_InterpreterRasterOpMachineCalculateBlendingFactors)(uVar6 & 0xf,param_2,param_3,iVar7,&local_60)
    ;
    ((int (*)())_InterpreterRasterOpMachineCalculateBlendingFactors)(uVar6 >> 8 & 0xf,param_2,param_3,iVar7,&local_50);
    if ((uVar6 & 0xf) != (uVar6 >> 4 & 0xf)) {
      ((int (*)())_InterpreterRasterOpMachineCalculateBlendingFactors)(uVar6 >> 4 & 0xf,param_2,param_3,iVar7,auStack_40);
      local_54 = local_34;
    }
    if ((uVar6 >> 8 & 0xf) != (uVar6 >> 0xc & 0xf)) {
      ((int (*)())_InterpreterRasterOpMachineCalculateBlendingFactors)(uVar6 >> 0xc & 0xf,param_2,param_3,iVar7,auStack_40);
      local_44 = local_34;
    }
  }
  switch(uVar6 >> 0x10 & 7) {
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
  switch(uVar6 >> 0x13 & 7) {
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
  fVar4 = ((float)(uVar6 & 0xff | 0x4b000000) - 8388608.0) * FLOAT_97c3acc8;
  fVar1 = ((float)(uVar6 >> 0x10 & 0xff | 0x4b000000) - 8388608.0) * FLOAT_97c3acc8;
  fVar2 = ((float)(uVar6 >> 8 & 0xff | 0x4b000000) - 8388608.0) * FLOAT_97c3acc8;
  *param_4 = ((float)(uVar6 >> 0x18 | 0x4b000000) - 8388608.0) * FLOAT_97c3acc8;
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
  int param_2;
  byte *param_3;
  int param_4;
{
  byte bVar1;
  byte bVar2;
  
  switch(param_1) {
  case 0:
    bVar2 = *param_3 & ~param_4;
    goto LAB_97bd7c38;
  case 1:
    return;
  case 2:
    bVar2 = *param_3 & ~param_4;
    goto LAB_97bd7c34;
  case 3:
    bVar2 = *param_3;
    param_2 = 0xff;
    if (bVar2 != 0xff) {
      param_2 = bVar2 + 1;
    }
    break;
  case 4:
    bVar2 = *param_3;
    param_2 = 0;
    if (bVar2 != 0) {
      param_2 = bVar2 - 1;
    }
    break;
  case 5:
    *param_3 = *param_3 & ~param_4 | param_4 & ~*param_3;
    return;
  case 6:
    bVar2 = *param_3;
    bVar1 = bVar2 + 1;
    goto LAB_97bd7c90;
  case 7:
    bVar2 = *param_3;
    bVar1 = bVar2 - 1;
LAB_97bd7c90:
    *param_3 = bVar2 & ~param_4 | bVar1 & param_4;
    return;
  default:
    return;
  }
  bVar2 = bVar2 & ~param_4;
LAB_97bd7c34:
  bVar2 = bVar2 | param_2 & param_4;
LAB_97bd7c38:
  *param_3 = bVar2;
  return;
}

/* _glpRTCAddAChunk @ 0x97bd7cbc (48 bytes) */
int _glpRTCAddAChunk(param_1, param_2)
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
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = _calloc(0xe54,1);
  uVar2 = ((int (*)())_PPCTextureSamplerCreate)();
  *(undefined4 *)((int)pvVar1 + 0xe1c) = uVar2;
  _PPCRasterOpMachineInitialise((int)pvVar1 + 0xe14);
  _PPCRasterOpMachineAttachRuntimeCompiler((int)pvVar1 + 0xe14,pvVar1);
  return pvVar1;
}

/* _PPCRuntimeCompilerInitialise @ 0x97bd7d44 (76 bytes) */
int _PPCRuntimeCompilerInitialise(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(param_1 + 0xe0c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xe08) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xe4c) = param_2;
  ((int (*)())_PPCTextureSamplerInitialise)(*(undefined4 *)(param_1 + 0xe1c));
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
  size_t sVar2;
  void *pvVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  if (*(void **)(param_1 + 0xe00) != (void *)0x0) {
    _free(*(void **)(param_1 + 0xe00));
    *(undefined4 *)(param_1 + 0xe04) = 0;
    *(undefined4 *)(param_1 + 0xe00) = 0;
  }
  iVar7 = *(int *)(param_1 + 0xe24);
  if (iVar7 != 0) {
    iVar8 = 0;
    iVar9 = 4;
    *(undefined4 *)(param_1 + 0xe04) = 0;
    piVar5 = (int *)(iVar7 + 0x84);
    do {
      iVar1 = *piVar5;
      piVar5 = piVar5 + 3;
      sVar2 = *(int *)(param_1 + 0xe04) + iVar1;
      *(size_t *)(param_1 + 0xe04) = sVar2;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    pvVar3 = _calloc(sVar2,8);
    *(void **)(param_1 + 0xe00) = pvVar3;
    uVar4 = 0;
    do {
      uVar6 = 0;
      if (*(int *)(iVar7 + 0x84) != 0) {
        do {
          iVar9 = uVar6 * 0x10;
          uVar6 = uVar6 + 1;
          *(int *)(iVar8 * 8 + *(int *)(param_1 + 0xe00)) = *(int *)(iVar7 + 0x80) + iVar9;
          iVar8 = iVar8 + 1;
        } while (uVar6 < *(uint *)(iVar7 + 0x84));
      }
      uVar4 = uVar4 + 1;
      iVar7 = iVar7 + 0xc;
    } while (uVar4 < 4);
  }
  return;
}

/* _PPCRuntimeCompilerFree @ 0x97bd7f0c (80 bytes) */
int _PPCRuntimeCompilerFree(param_1)
  void *param_1;
{
  if (*(void **)((int)param_1 + 0xe00) != (void *)0x0) {
    _free(*(void **)((int)param_1 + 0xe00));
    *(undefined4 *)((int)param_1 + 0xe04) = 0;
    *(undefined4 *)((int)param_1 + 0xe00) = 0;
  }
  _PPCTextureSamplerFree(*(undefined4 *)((int)param_1 + 0xe1c));
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
  _PPCRasterOpMachineAttachEmulatorContext(param_1 + 0xe14);
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
int _PPCRuntimeCompilerCalculateIndirectAddress(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
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
int _PPCRuntimeCompilerLoadRegister(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int *param_1;
  uint param_2;
  uint *param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  uint param_7;
  undefined4 param_8;
{
  byte bVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int *piVar11;
  uint *puStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  ushort uStack00000030;
  char cStack00000032;
  char cStack00000033;
  undefined4 uStack00000034;
  int in_stack_00000038;
  undefined4 in_stack_0000003c;
  undefined4 in_stack_00000040;
  int in_stack_00000044;
  undefined1 auStack_40 [28];
  
  iVar2 = in_stack_00000044;
  uVar8 = 0;
  uStack00000028 = param_5;
  iVar10 = 0;
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
    iVar4 = ((int (*)())_PPCRuntimeCompilerRegisterContainsData)(param_1,uVar5,param_3,param_4,param_5,param_6,param_7,param_8);
    if (iVar4 == 1) {
      return;
    }
    uVar5 = param_1[0x394];
  }
  if (param_1[0x393] == 0) {
    if ((uVar5 & 4) != 0) {
      uVar8 = 0;
      piVar11 = param_1;
      do {
        if ((*piVar11 == 0) &&
           (iVar10 = ((int (*)())_PPCRuntimeCompilerRegisterContainsData)(param_1,uVar8,puStack00000020,uStack00000024,uStack00000028,
                                uStack0000002c,(*(unsigned int *)(*(unsigned int *)__builtin_frame_address(0) + 0x30)),uStack00000034), iVar10 == 1)) {
          if (uVar8 != param_2) {
            puVar3 = (uint *)param_1[0x38c];
            *puVar3 = param_2 << 0x15 | uVar8 << 0xb | 0xfc000090;
            param_1[0x38c] = (int)(puVar3 + 1);
            ((int (*)())_PPCRuntimeCompilerSetRegister)(param_1,param_2,puStack00000020,uStack00000024,uStack00000028,uStack0000002c,
                       (*(unsigned int *)(*(unsigned int *)__builtin_frame_address(0) + 0x30)),uStack00000034);
            piVar11[0xc] = param_1[0x391];
            goto LAB_97bd8938;
          }
          if (*(char *)((int)piVar11 + 0x1a) == cStack00000032) {
            return;
          }
        }
        uVar8 = uVar8 + 1;
        piVar11 = piVar11 + 0xe;
      } while (uVar8 < 0x20);
    }
    if (cStack00000033 == '\0') {
      if (((*(int *)(param_1[0x389] + 0x38) == 0x8804) ||
          (*(int *)(param_1[0x389] + 0x38) == 0x8b30)) && (uStack00000030 == 2)) {
        puVar7 = (uint *)param_1[0x38c];
        *puVar7 = puStack00000020[*(byte *)((int)&STACKARG(0x28) + iVar2)] & 0xffff | 0xc10d0000;
        bVar1 = *(byte *)((int)&STACKARG(0x28) + iVar2);
        param_1[0x38c] = (int)(puVar7 + 1);
        uVar8 = puStack00000020[bVar1];
        puVar3 = puVar7 + 3;
        puVar7[2] = param_2 << 0x15 | 0xec09433a;
        puVar7[1] = uVar8 & 0xffff | 0xc12c0000;
      }
      else {
        puVar3 = (uint *)param_1[0x38c];
        *puVar3 = param_2 << 0x15 | (uStack00000030 + 5) * 0x10000 |
                  puStack00000020[*(byte *)((int)&STACKARG(0x28) + iVar2)] & 0xffff | 0xc0000000;
        puVar3 = puVar3 + 1;
      }
      param_1[0x38c] = (int)puVar3;
    }
    else {
      ((int (*)())_PPCRuntimeCompilerCalculateIndirectAddress)(param_1,puStack00000020,uStack00000024,uStack00000028,uStack0000002c,
                 (*(unsigned int *)(*(unsigned int *)__builtin_frame_address(0) + 0x30)),uStack00000034,in_stack_00000038);
      puVar3 = (uint *)param_1[0x38c];
      *puVar3 = (uint)*(byte *)((int)&STACKARG(0x28) + iVar2) << 2 | 0x82ef0000;
      puVar3[1] = param_2 << 0x15 | (((*(unsigned int *)(*(unsigned int *)__builtin_frame_address(0) + 0x30)) >> 0x10) + 5) * 0x10000 | 0x7c00bc2e;
      param_1[0x38c] = (int)(puVar3 + 2);
    }
    ((int (*)())_PPCRuntimeCompilerSetRegister)(param_1,param_2,puStack00000020,uStack00000024,uStack00000028,uStack0000002c,
               (*(unsigned int *)(*(unsigned int *)__builtin_frame_address(0) + 0x30)),uStack00000034);
    return;
  }
  if ((uVar5 & 4) != 0) {
    piVar11 = param_1 + 0x1c0;
    uVar5 = 0;
    do {
      uVar9 = uVar5;
      iVar2 = *piVar11;
      piVar11 = piVar11 + 0xe;
      if (iVar2 == 0) {
        iVar2 = ((int (*)())_PPCRuntimeCompilerRegisterContainsData)(param_1,uVar9,puStack00000020,uStack00000024,uStack00000028,
                           uStack0000002c,(*(unsigned int *)(*(unsigned int *)__builtin_frame_address(0) + 0x30)),uStack00000034);
        if ((iVar2 == 3) && (uStack00000030 == 0)) {
          iVar10 = 3;
          uVar8 = uVar9;
        }
        else if (iVar2 - 1U < 2) break;
      }
      uVar5 = uVar9 + 1;
      uVar9 = uVar8;
      iVar2 = iVar10;
    } while (uVar5 < 0x20);
    if (iVar2 != 0) {
      iVar10 = param_2 - 0x20;
      puVar3 = (uint *)param_1[0x38c];
      *puVar3 = iVar10 * 0x200000 | uVar9 << 0x10 | uVar9 << 0xb | 0x10000484;
      param_1[0x38c] = (int)(puVar3 + 1);
      iVar2 = _memcmp(param_1 + uVar9 * 0xe + 0x1c4,&STACKARG(0x28),4);
      if (iVar2 != 0) {
        ((int (*)())_PPCRuntimeCompilerBuildTransferSwizzle)(auStack_40,param_1 + uVar9 * 0xe + 0x1c4,&STACKARG(0x28));
        ((int (*)())_PPCRuntimeCompilerSwizzleRegisterAV)(param_1,iVar10,auStack_40);
      }
      ((int (*)())_PPCRuntimeCompilerSetRegister)(param_1,iVar10,puStack00000020,uStack00000024,uStack00000028,uStack0000002c,
                 (*(unsigned int *)(*(unsigned int *)__builtin_frame_address(0) + 0x30)),uStack00000034);
      param_1[uVar9 * 0xe + 0x1cc] = param_1[0x391];
LAB_97bd8938:
      param_1[0x391] = param_1[0x391] + 1;
      return;
    }
  }
  puVar3 = puStack00000020;
  if (((*(int *)(param_1[0x389] + 0x38) == 0x8804) || (*(int *)(param_1[0x389] + 0x38) == 0x8b30))
     && (uStack00000030 == 2)) {
    if ((param_1[0x394] & 8U) == 0) {
      uVar8 = *puStack00000020;
    }
    else {
      uVar8 = 0;
      if (*puStack00000020 != 0) {
        puVar3 = (uint *)param_1[0x38c];
        *puVar3 = *puStack00000020 & 0xffff | 0x39e00000;
        puVar3[1] = 0x10c0728c;
        uVar8 = (param_2 - 0x20) * 0x200000;
        puVar3[2] = 0x7c6d78ce;
        puVar3[3] = 0x10a3728c;
        puVar3[4] = 0x7c8c78ce;
        puVar3[5] = uVar8 | 0x100419ae;
        puVar3[6] = uVar8 | (param_2 - 0x20) * 0x10000 | 0x1000396e;
        param_1[0x38c] = (int)(puVar3 + 7);
        goto LAB_97bd87b4;
      }
    }
    puVar3 = (uint *)param_1[0x38c];
    *puVar3 = uVar8 & 0xffff | 0x39e00000;
    puVar3[1] = 0x7c6d78ce;
    puVar3[2] = 0x7c8c78ce;
    puVar3[3] = 0x10c0728c;
    puVar3[4] = (param_2 - 0x20) * 0x200000 | 0x100419ae;
    param_1[0x38c] = (int)(puVar3 + 5);
    goto LAB_97bd87b4;
  }
  if (cStack00000033 == '\0') {
    uVar8 = *puStack00000020;
    if (((((uVar8 & 0xf) == 0) && (puStack00000020[1] == uVar8 + 4)) &&
        (puStack00000020[2] == uVar8 + 8)) && (puStack00000020[3] == uVar8 + 0xc)) {
      if (uVar8 != 0) {
        puVar3 = (uint *)param_1[0x38c];
        *puVar3 = uVar8 & 0xffff | 0x39e00000;
        uVar8 = (param_2 - 0x20) * 0x200000 | (uStack00000030 + 5) * 0x10000 | 0x7c0078ce;
        goto LAB_97bd8640;
      }
      puVar3 = (uint *)param_1[0x38c];
      *puVar3 = (param_2 - 0x20) * 0x200000 | (uStack00000030 + 5) * 0x800 | 0x7c0000ce;
      param_1[0x38c] = (int)(puVar3 + 1);
    }
    else {
      puVar3 = (uint *)param_1[0x38c];
      *puVar3 = (uStack00000030 + 5) * 0x10000 | uVar8 & 0xffff | 0xc0000000;
      param_1[0x38c] = (int)(puVar3 + 1);
      puVar3[1] = (uStack00000030 + 5) * 0x10000 | (uint)*(ushort *)((int)puStack00000020 + 6) |
                  0xc0200000;
      param_1[0x38c] = (int)(puVar3 + 2);
      puVar3[2] = (uStack00000030 + 5) * 0x10000 | (uint)*(ushort *)((int)puStack00000020 + 10) |
                  0xc0400000;
      param_1[0x38c] = (int)(puVar3 + 3);
      puVar3[3] = (uStack00000030 + 5) * 0x10000 | (uint)*(ushort *)((int)puStack00000020 + 0xe) |
                  0xc0600000;
      puVar3[4] = 0xd0030200;
      puVar3[5] = 0xd0230204;
      puVar3[6] = 0xd0430208;
      puVar3[7] = 0xd063020c;
      puVar3[8] = 0x39e00200;
      puVar3[9] = (param_2 - 0x20) * 0x200000 | 0x7c0378ce;
      param_1[0x38c] = (int)(puVar3 + 10);
    }
  }
  else {
    if (uStack00000030 == 0) {
      ((int (*)())_PPCRuntimeCompilerSaveAllTemporariesToMemory)(param_1);
    }
    ((int (*)())_PPCRuntimeCompilerCalculateIndirectAddress)(param_1,puStack00000020,uStack00000024,uStack00000028,uStack0000002c,(*(unsigned int *)(*(unsigned int *)__builtin_frame_address(0) + 0x30)),
               uStack00000034,in_stack_00000038);
    uVar8 = *puVar3;
    if ((((uVar8 & 0xf) == 0) && (puVar3[1] == uVar8 + 4)) &&
       ((puVar3[2] == uVar8 + 8 && (puVar3[3] == uVar8 + 0xc)))) {
      puVar3 = (uint *)param_1[0x38c];
      *puVar3 = 0x82ef0000;
      uVar8 = (param_2 - 0x20) * 0x200000 | (uStack00000030 + 5) * 0x10000 | 0x7c00b8ce;
LAB_97bd8640:
      puVar3[1] = uVar8;
      param_1[0x38c] = (int)(puVar3 + 2);
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
    }
  }
  if (in_stack_00000038 - 3U < 2) {
    puVar3 = (uint *)param_1[0x38c];
    *puVar3 = (param_2 - 0x20) * 0x200000 | (param_2 - 0x20) * 0x800 | 0x1000034a;
    param_1[0x38c] = (int)(puVar3 + 1);
  }
LAB_97bd87b4:
  ((int (*)())_PPCRuntimeCompilerSwizzleRegisterAV)(param_1,param_2 - 0x20,&STACKARG(0x28));
  ((int (*)())_PPCRuntimeCompilerSetRegister)(param_1,param_2 - 0x20,puStack00000020,uStack00000024,uStack00000028,uStack0000002c,
             (*(unsigned int *)(*(unsigned int *)__builtin_frame_address(0) + 0x30)),uStack00000034);
  iVar2 = ((int (*)())_PPCRuntimeCompilerFindVariableInfo)(param_1,puStack00000020,uStack00000024,uStack00000028,uStack0000002c,
                     (*(unsigned int *)(*(unsigned int *)__builtin_frame_address(0) + 0x30)),uStack00000034,in_stack_00000038);
  *(undefined4 *)(iVar2 + 4) = 0;
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
  int iVar9;
  int *piVar10;
  uint uVar11;
  int *piVar12;
  uint uVar13;
  int iVar14;
  int *piVar15;
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
  
  iVar14 = param_1[0x393];
  uVar17 = 0;
  iVar16 = 0;
  bVar3 = false;
  if (iVar14 != 0) {
    param_2 = param_2 + 0x20;
  }
  iVar18 = param_2 * 0x38;
  if (param_1[param_2 * 0xe] == 0) {
    uVar19 = 0;
    piVar10 = param_1;
    do {
      if (iVar14 == 0) {
        if (((uVar19 != param_2) && (*piVar10 == 0)) && (piVar10[0xb] != 0)) {
          iVar14 = ((int (*)())_PPCRuntimeCompilerRegisterContainsData)(param_1,uVar19,param_1[param_2 * 0xe + 2],param_1[param_2 * 0xe + 3],
                              param_1[param_2 * 0xe + 4],param_1[param_2 * 0xe + 5],
                              param_1[param_2 * 0xe + 6],param_1[param_2 * 0xe + 7]);
          if (iVar14 == 1) {
            return;
          }
          goto LAB_97bd8c50;
        }
      }
      else if (((uVar19 != param_2 - 0x20) && (piVar10[0x1c0] == 0)) && (piVar10[0x1cb] != 0)) {
        iVar14 = ((int (*)())_PPCRuntimeCompilerRegisterContainsData)(param_1,uVar19,param_1[param_2 * 0xe + 2],param_1[param_2 * 0xe + 3],
                            param_1[param_2 * 0xe + 4],param_1[param_2 * 0xe + 5],
                            param_1[param_2 * 0xe + 6],param_1[param_2 * 0xe + 7]);
        if (iVar14 - 1U < 2) {
          return;
        }
LAB_97bd8c50:
        iVar14 = param_1[0x393];
      }
      uVar19 = uVar19 + 1;
      piVar10 = piVar10 + 0xe;
    } while (uVar19 < 0x20);
    iVar9 = 0;
    if (iVar14 != 0) {
      uVar19 = param_2 - 0x20;
      uVar20 = 0;
      iVar14 = uVar19 * 0x38 + 0x708;
      piVar10 = param_1;
      do {
        if (((uVar20 != uVar19) && (piVar10[0x1c0] == 0)) &&
           ((piVar10[0x1cb] != 0 &&
            ((iVar9 = _memcmp((void *)piVar10[0x1c2],(void *)param_1[param_2 * 0xe + 2],0x10),
             iVar9 == 0 && (*(short *)(piVar10 + 0x1c6) == *(short *)(param_1 + param_2 * 0xe + 6)))
            )))) {
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
            ((int (*)())_PPCRuntimeCompilerBuildTransferSwizzle)(&local_50,param_1 + uVar19 * 0xe + 0x1c4,&local_4c);
            ((int (*)())_PPCRuntimeCompilerSwizzleRegisterAV)(param_1,uVar19,&local_50);
            local_48 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)
                                                   ((int)param_1 + (uint)local_50 + iVar14 + 8),
                                                  *(undefined1 *)
                                                   ((int)param_1 + (uint)local_4f + iVar14 + 8)),
                                         *(undefined1 *)((int)param_1 + (uint)local_4e + iVar14 + 8)
                                        ),
                                *(undefined1 *)((int)param_1 + (uint)local_4d + iVar14 + 8));
            param_1[uVar19 * 0xe + 0x1c4] = local_48;
          }
          if (((uint)piVar10[0x1c4] >> 8 != (piVar10[0x1c4] & 0xffffffU)) &&
             (((((*(char *)(piVar10 + 0x1c4) != '\0' && (*(char *)(piVar10 + 0x1c4) != -1)) ||
                ((*(char *)((int)piVar10 + 0x711) != '\x01' &&
                 (*(char *)((int)piVar10 + 0x711) != -1)))) ||
               ((*(char *)((int)piVar10 + 0x712) != '\x02' &&
                (*(char *)((int)piVar10 + 0x712) != -1)))) ||
              ((*(char *)((int)piVar10 + 0x713) != '\x03' && (*(char *)((int)piVar10 + 0x713) != -1)
               ))))) {
            ((int (*)())_PPCRuntimeCompilerBuildTransferSwizzle)(&local_50,piVar10 + 0x1c4,&local_4c);
            ((int (*)())_PPCRuntimeCompilerSwizzleRegisterAV)(param_1,uVar20,&local_50);
            local_48 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)((int)piVar10 + local_50 + 0x710),
                                                  *(undefined1 *)((int)piVar10 + local_4f + 0x710)),
                                         *(undefined1 *)((int)piVar10 + local_4e + 0x710)),
                                *(undefined1 *)((int)piVar10 + local_4d + 0x710));
            piVar10[0x1c4] = local_48;
          }
          local_60[3] = 0;
          iVar16 = 4;
          local_60[0] = 0;
          local_60[1] = 0;
          piVar12 = local_60;
          local_60[2] = 0;
          pbVar5 = (byte *)(param_1 + uVar19 * 0xe + 0x1c4);
          do {
            bVar2 = *pbVar5;
            pbVar5 = pbVar5 + 1;
            if (bVar2 < 4) {
              piVar12[bVar2] = 1;
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
              uVar11 = uVar17 + 1;
              if (piVar12[uVar17] != 0) {
                uVar13 = 3 - uVar17;
                if (uVar11 < 4) {
                  piVar15 = piVar12 + uVar11;
                  uVar7 = uVar11;
                  do {
                    iVar16 = *piVar15;
                    piVar15 = piVar15 + 1;
                    if (iVar16 != 0) {
                      uVar13 = (uVar7 - uVar17) - 1;
                      break;
                    }
                    uVar7 = uVar7 + 1;
                  } while (uVar7 < 4);
                }
                puVar6 = (undefined4 *)param_1[0x38c];
                *puVar6 = 0x1063212c;
                param_1[0x38c] = (int)(puVar6 + 1);
                if (uVar13 != 0) {
                  puVar6[1] = (uVar13 & 3) << 8 | 0x1063482c;
                  param_1[0x38c] = (int)(puVar6 + 2);
                }
              }
              uVar17 = uVar11;
            } while (uVar11 < 4);
          }
LAB_97bd9024:
          puVar8 = (uint *)param_1[0x38c];
          piVar10 = piVar10 + 0x1c4;
          *puVar8 = uVar20 << 0x15 | uVar20 << 0x10 | uVar19 * 0x800 | 0x100000ea;
          iVar16 = 4;
          param_1[0x38c] = (int)(puVar8 + 1);
          param_1 = param_1 + uVar19 * 0xe + 0x1c4;
          do {
            iVar14 = *piVar12;
            piVar12 = piVar12 + 1;
            if (iVar14 != 0) {
              *(undefined1 *)piVar10 = *(undefined1 *)param_1;
            }
            param_1 = (int *)((int)param_1 + 1);
            piVar10 = (int *)((int)piVar10 + 1);
            iVar16 = iVar16 + -1;
          } while (iVar16 != 0);
          return;
        }
        uVar20 = uVar20 + 1;
        piVar10 = piVar10 + 0xe;
      } while (uVar20 < 0x20);
      iVar9 = param_1[0x393];
    }
    if (((iVar9 != 0) && (*(short *)(param_1 + param_2 * 0xe + 6) == 0)) &&
       ((*(char *)(param_1 + param_2 * 0xe + 4) == -1 ||
        (((*(char *)((int)param_1 + iVar18 + 0x11) == -1 ||
          (*(char *)((int)param_1 + iVar18 + 0x12) == -1)) ||
         (*(char *)((int)param_1 + iVar18 + 0x13) == -1)))))) {
      iVar14 = ((int (*)())_PPCRuntimeCompilerFindVariableInfo)(param_1,param_1[param_2 * 0xe + 2],param_1[param_2 * 0xe + 3],
                          param_1[param_2 * 0xe + 4],param_1[param_2 * 0xe + 5],
                          param_1[param_2 * 0xe + 6],param_1[param_2 * 0xe + 7],
                          param_1[param_2 * 0xe + 8]);
      if (*(int *)(iVar14 + 4) != 0) {
        ((int (*)())_PPCRuntimeCompilerSaveRegisterToMemory)(param_1,param_2 - 0x20);
        ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,param_2 - 0x20);
        return;
      }
      iVar9 = param_1[0x393];
    }
    uVar20 = (uint)(iVar9 != 0);
    uVar19 = uVar20 * 0x20;
    if (iVar9 == 0) {
      uVar11 = 0x20;
    }
    else {
      uVar11 = 0x40;
    }
    if (uVar19 < uVar11) {
      iVar14 = uVar11 + uVar20 * -0x20;
      piVar10 = param_1 + uVar20 * 0x1c0;
      do {
        if (((uVar19 != param_2) && (piVar10[0xb] != 0)) &&
           ((iVar16 <= param_1[0x391] - piVar10[0xc] && (piVar10[0xd] == 0)))) {
          bVar3 = true;
          iVar16 = param_1[0x391] - piVar10[0xc];
          uVar17 = uVar19;
        }
        uVar19 = uVar19 + 1;
        piVar10 = piVar10 + 0xe;
        iVar14 = iVar14 + -1;
      } while (iVar14 != 0);
      if (bVar3) {
        if ((*(short *)(param_1 + uVar17 * 0xe + 6) == 0) && (param_1[uVar17 * 0xe] == 0)) {
          if (iVar9 == 0) {
            ((int (*)())_PPCRuntimeCompilerSaveRegisterToMemory)(param_1,uVar17);
          }
          else {
            ((int (*)())_PPCRuntimeCompilerSaveRegisterToMemory)(param_1,uVar17 - 0x20);
            iVar16 = ((int (*)())_PPCRuntimeCompilerFindVariableInfo)(param_1,param_1[uVar17 * 0xe + 2],param_1[uVar17 * 0xe + 3],
                                param_1[uVar17 * 0xe + 4],param_1[uVar17 * 0xe + 5],
                                param_1[uVar17 * 0xe + 6],param_1[uVar17 * 0xe + 7],
                                param_1[uVar17 * 0xe + 8]);
            *(undefined4 *)(iVar16 + 4) = 1;
          }
          iVar9 = param_1[0x393];
        }
        if (iVar9 == 0) {
          iVar16 = param_1[param_2 * 0xe + 7];
          uVar19 = uVar17;
        }
        else {
          iVar16 = param_1[param_2 * 0xe + 7];
          uVar19 = uVar17 - 0x20;
        }
        ((int (*)())_PPCRuntimeCompilerSetRegister)(param_1,uVar19,param_1[param_2 * 0xe + 2],param_1[param_2 * 0xe + 3],
                   param_1[param_2 * 0xe + 4],param_1[param_2 * 0xe + 5],param_1[param_2 * 0xe + 6],
                   iVar16);
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
      if (iVar9 != 0) {
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
    _memcpy(&local_50,(void *)(iVar8 + 0x708),0x24);
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
int _PPCRuntimeCompilerDirtyRegistersWithData(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  undefined4 in_stack_00000038;
  undefined4 in_stack_0000003c;
  undefined4 in_stack_00000040;
  
  uVar6 = 0;
  uStack0000001c = param_2;
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  if (*(int *)(param_1 + 0xe4c) == 0) {
    do {
      iVar5 = ((int (*)())_PPCRuntimeCompilerRegisterContainsData)(param_1,uVar6,uStack0000001c,uStack00000020,uStack00000024,uStack00000028,
                         uStack0000002c,uStack00000030);
      if (iVar5 == 1) {
        ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,uVar6);
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < 0x20);
  }
  else {
    iVar5 = 0;
    do {
      iVar2 = ((int (*)())_PPCRuntimeCompilerRegisterContainsData)(param_1,uVar6,uStack0000001c,uStack00000020,uStack00000024,uStack00000028,
                         uStack0000002c,uStack00000030);
      if (iVar2 - 1U < 3) {
        uVar3 = 0;
        iVar2 = iVar5 + param_1 + 0x700;
        do {
          iVar7 = 4;
          pcVar4 = (char *)&STACKARG(0x24);
          do {
            cVar1 = *pcVar4;
            pcVar4 = pcVar4 + 1;
            if (*(char *)(iVar2 + 0x10) == cVar1) {
              *(undefined1 *)(iVar2 + 0x10) = 0xff;
            }
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
          uVar3 = uVar3 + 1;
          iVar2 = iVar2 + 1;
        } while (uVar3 < 4);
        iVar2 = iVar5 + param_1;
        if ((((*(char *)(iVar2 + 0x710) == -1) && (*(char *)(iVar2 + 0x711) == -1)) &&
            (*(char *)(iVar2 + 0x712) == -1)) && (*(char *)(iVar2 + 0x713) == -1)) {
          ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,uVar6);
        }
      }
      uVar6 = uVar6 + 1;
      iVar5 = iVar5 + 0x38;
    } while (uVar6 < 0x20);
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
int _PPCRuntimeCompilerSetRegister(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
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
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  undefined4 in_stack_00000044;
  undefined4 in_stack_00000048;
  
  if (*(int *)(param_1 + 0xe4c) != 0) {
    param_2 = param_2 + 0x20;
  }
  *(undefined4 *)(param_2 * 0x38 + param_1) = 0;
  iVar1 = param_2 * 0x38 + param_1;
  *(undefined4 *)(iVar1 + 4) = in_stack_00000048;
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  _memcpy((void *)(iVar1 + 8),&STACKARG(0x20),0x24);
  *(undefined4 *)(iVar1 + 0x34) = in_stack_00000044;
  *(undefined4 *)(iVar1 + 0x30) = *(undefined4 *)(param_1 + 0xe44);
  *(int *)(param_1 + 0xe44) = *(int *)(param_1 + 0xe44) + 1;
  return;
}

/* _PPCRuntimeCompilerRegisterContainsData @ 0x97bd9e3c (560 bytes) */
int _PPCRuntimeCompilerRegisterContainsData(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  void *param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  uint param_8;
{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  void *pvStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  short sStack00000030;
  char cStack00000033;
  uint uStack00000034;
  int in_stack_00000044;
  int local_20 [6];
  
  local_20[3] = 0;
  local_20[0] = 0;
  local_20[1] = 0;
  local_20[2] = 0;
  pvStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  (*(short *)(*(unsigned int *)__builtin_frame_address(0) + 0x30)) = param_7;
  uStack00000034 = param_8;
  if (*(int *)(param_1 + 0xe4c) == 0) {
    iVar2 = param_2 * 0x38 + param_1;
    if ((((*(int *)(param_1 + param_2 * 0x38) == 0) &&
         (iVar7 = _memcmp(*(void **)(iVar2 + 8),param_3,0x10), iVar7 == 0)) &&
        (*(short *)(iVar2 + 0x18) == sStack00000030)) &&
       (((*(char *)(iVar2 + *(int *)(iVar2 + 4) + 0x10) ==
          *(char *)((int)&STACKARG(0x28) + in_stack_00000044) && (cStack00000033 == '\0')) &&
        (*(char *)(iVar2 + 0x1b) == '\0')))) {
      return 1;
    }
  }
  else {
    iVar2 = (param_2 + 0x20) * 0x38;
    iVar7 = iVar2 + param_1;
    if ((*(int *)(param_1 + iVar2) == 0) &&
       (iVar2 = _memcmp(*(void **)(iVar7 + 8),param_3,0x10), iVar2 == 0)) {
      if ((*(short *)(iVar7 + 0x18) == sStack00000030) &&
         ((cStack00000033 == '\0' && (*(char *)(iVar7 + 0x1b) == '\0')))) {
        iVar2 = _memcmp((void *)(iVar7 + 0x10),&STACKARG(0x28),uStack00000034 >> 0x10 & 0xff);
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

/* _PPCRuntimeCompilerGetBaseIndexInRegister @ 0x97bda06c (16 bytes) */
int _PPCRuntimeCompilerGetBaseIndexInRegister(param_1, param_2)
  int param_1;
  int param_2;
{
  return *(undefined2 *)(param_2 * 0x38 + param_1 + 0x18);
}

/* _PPCRuntimeCompilerGetOffsetInRegister @ 0x97bda07c (88 bytes) */
int _PPCRuntimeCompilerGetOffsetInRegister(param_1, param_2)
  int param_1;
  int param_2;
{
  int local_40 [2];
  byte abStack_38 [40];
  
  param_1 = param_2 * 0x38 + param_1;
  _memcpy(local_40,(void *)(param_1 + 8),0x24);
  return *(undefined4 *)(local_40[0] + (uint)abStack_38[*(int *)(param_1 + 4)] * 4);
}

/* _PPCRuntimeCompilerBuildTransferSwizzle @ 0x97bda0d4 (104 bytes) */
int _PPCRuntimeCompilerBuildTransferSwizzle(param_1, param_2, param_3)
  undefined1 *param_1;
  int param_2;
  char *param_3;
{
  char cVar1;
  uint uVar2;
  undefined1 *puVar3;
  
  *param_1 = 0;
  param_1[1] = 1;
  param_1[2] = 2;
  param_1[3] = 3;
  puVar3 = param_1 + 3;
  do {
    cVar1 = *param_3;
    uVar2 = 0;
    param_3 = param_3 + 1;
    do {
      if (*(char *)(param_2 + uVar2) == cVar1) {
        *param_1 = (char)uVar2;
        break;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < 4);
    param_1 = param_1 + 1;
    if (puVar3 < param_1) {
      return;
    }
  } while( true );
}

/* _PPCRuntimeCompilerSwizzleRegisterAV @ 0x97bda13c (2444 bytes) */
int _PPCRuntimeCompilerSwizzleRegisterAV(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint *param_3;
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  uint *puVar12;
  
  uVar2 = *param_3;
  iVar4 = 1;
  iVar5 = 1;
  uVar3 = (uVar2 & 0x3000000) << 4 | (uVar2 & 0x30000) << 8 | (uVar2 & 0x300) << 0xc |
          (uVar2 & 3) << 0x10;
  uVar6 = 0;
  uVar3 = uVar3 | uVar3 >> 0x10;
  do {
    if (((uVar3 >> (uVar6 * -4 + 0x1c & 0x3f)) + 1 & 3) == (uVar3 >> (uVar6 * -4 + 0x18 & 0x3f) & 3)
       ) {
      iVar1 = uVar6 * 4 + 8;
      iVar4 = 2;
      uVar10 = 0x20 - iVar1;
      uVar7 = 0x1c - iVar1;
      goto LAB_97bda1ac;
    }
    uVar6 = uVar6 + 1;
  } while ((int)uVar6 < 4);
  goto LAB_97bda240;
  while( true ) {
    iVar5 = iVar5 + 1;
    uVar11 = uVar11 - 4;
    uVar10 = uVar10 - 4;
    if (3 < iVar5) break;
LAB_97bda278:
    if ((uVar3 >> (uVar11 & 0x3f) & 3) != (uVar3 >> (uVar10 & 0x3f) & 3)) break;
  }
  if ((uVar7 == 0) && (iVar5 < 4)) {
    uVar11 = 0x10;
    uVar10 = 0xc;
    do {
      if ((uVar3 >> (uVar11 & 0x3f) & 3) != (uVar3 >> (uVar10 & 0x3f) & 3)) break;
      iVar5 = iVar5 + 1;
      uVar7 = uVar7 - 1 & 3;
      uVar11 = uVar11 + 4;
      uVar10 = uVar10 + 4;
    } while (iVar5 < 4);
  }
  goto LAB_97bda304;
  while( true ) {
    iVar4 = iVar4 + 1;
    uVar10 = uVar10 - 4;
    uVar7 = uVar7 - 4;
    if (3 < iVar4) break;
LAB_97bda1ac:
    if (((uVar3 >> (uVar10 & 0x3f)) + 1 & 3) != (uVar3 >> (uVar7 & 0x3f) & 3)) break;
  }
  if ((uVar6 == 0) && (iVar4 < 4)) {
    uVar10 = 0x10;
    uVar7 = 0xc;
    do {
      if (((uVar3 >> (uVar10 & 0x3f)) + 1 & 3) != (uVar3 >> (uVar7 & 0x3f) & 3)) break;
      iVar4 = iVar4 + 1;
      uVar6 = uVar6 - 1 & 3;
      uVar10 = uVar10 + 4;
      uVar7 = uVar7 + 4;
    } while (iVar4 < 4);
  }
LAB_97bda240:
  uVar7 = 0;
  do {
    if ((uVar3 >> (uVar7 * -4 + 0x1c & 0x3f) & 3) == (uVar3 >> (uVar7 * -4 + 0x18 & 0x3f) & 3)) {
      iVar1 = uVar7 * 4 + 8;
      iVar5 = 2;
      uVar11 = 0x20 - iVar1;
      uVar10 = 0x1c - iVar1;
      goto LAB_97bda278;
    }
    uVar7 = uVar7 + 1;
  } while ((int)uVar7 < 4);
LAB_97bda304:
  if (iVar5 == 4) {
    puVar8 = *(uint **)(param_1 + 0xe30);
    *puVar8 = param_2 << 0x15 | (uVar3 >> (uVar7 * -4 + 0x1c & 0x3f) & 0xf) << 0x10 | param_2 << 0xb
              | 0x1000028c;
    *(uint **)(param_1 + 0xe30) = puVar8 + 1;
    return;
  }
  if (iVar4 == 4) {
    uVar6 = (uVar2 & 0x3000000) >> 0x18;
    if (uVar6 == 0) {
      return;
    }
    uVar2 = param_2 << 0x15 | param_2 << 0x10 | param_2 << 0xb;
    uVar6 = uVar6 << 8;
LAB_97bda710:
    puVar8 = *(uint **)(param_1 + 0xe30);
    uVar6 = uVar2 | uVar6 & 0x300 | 0x1000002c;
LAB_97bdaabc:
    *puVar8 = uVar6;
  }
  else {
    if (iVar5 == 3) {
      uVar2 = param_2 << 0xb;
      uVar6 = uVar3 >> (uVar7 * -4 + 0x10 & 0x3f);
      puVar8 = *(uint **)(param_1 + 0xe30);
      *puVar8 = (uVar3 >> (uVar7 * -4 + 0x1c & 0x3f) & 0xf) << 0x10 | 0x600000 | uVar2 | 0x1000028c;
      *(uint **)(param_1 + 0xe30) = puVar8 + 1;
      iVar4 = param_2;
      if ((uVar6 & 0xf) != 0) {
        iVar4 = 4;
        puVar8[1] = param_2 << 0x10 | 0x800000U | uVar2 | (uVar6 & 3) << 8 | 0x1000002c;
        *(uint **)(param_1 + 0xe30) = puVar8 + 2;
      }
      puVar8 = *(uint **)(param_1 + 0xe30);
      *puVar8 = param_2 << 0x15 | 0x30000U | iVar4 << 0xb | 0x1000012c;
      puVar8 = puVar8 + 1;
      *(uint **)(param_1 + 0xe30) = puVar8;
      if (uVar7 == 0) {
        return;
      }
      uVar2 = param_2 << 0x15 | param_2 << 0x10 | uVar2;
      uVar6 = uVar7;
    }
    else {
      if (iVar4 != 3) {
        if (iVar5 == 2) {
          uVar2 = param_2 << 0xb;
          uVar11 = uVar3 >> (uVar7 * -4 + 0x14 & 0x3f);
          uVar6 = uVar11 & 0xf;
          uVar10 = uVar3 >> (uVar7 * -4 + 0x10 & 0x3f) & 0xf;
          puVar8 = *(uint **)(param_1 + 0xe30);
          *puVar8 = (uVar3 >> (uVar7 * -4 + 0x1c & 0x3f) & 0xf) << 0x10 | 0x600000 | uVar2 |
                    0x1000028c;
          puVar12 = puVar8 + 1;
          *(uint **)(param_1 + 0xe30) = puVar12;
          if (uVar10 == (uVar6 + 1 & 3)) {
            iVar4 = param_2;
            if (uVar6 != 0) {
              iVar4 = 4;
              *puVar12 = param_2 << 0x10 | 0x800000U | uVar2 | (uVar11 & 3) << 8 | 0x1000002c;
              *(uint **)(param_1 + 0xe30) = puVar8 + 2;
            }
            puVar9 = *(uint **)(param_1 + 0xe30);
            uVar6 = param_2 << 0x15 | 0x30000U | iVar4 << 0xb | 0x1000022c;
LAB_97bda6e8:
            *puVar9 = uVar6;
            puVar9 = puVar9 + 1;
          }
          else {
            if (uVar10 != uVar6) {
              iVar4 = param_2;
              if (uVar6 != 0) {
                iVar4 = 4;
                *puVar12 = param_2 << 0x10 | 0x800000U | uVar2 | (uVar11 & 3) << 8 | 0x1000002c;
                *(uint **)(param_1 + 0xe30) = puVar8 + 2;
              }
              uVar3 = uVar3 >> (uVar7 * -4 + 0x10 & 0x3f);
              puVar8 = *(uint **)(param_1 + 0xe30);
              *puVar8 = iVar4 << 0xb | 0x1063012c;
              *(uint **)(param_1 + 0xe30) = puVar8 + 1;
              iVar4 = param_2;
              if ((uVar3 & 0xf) != 0) {
                iVar4 = 4;
                puVar8[1] = param_2 << 0x10 | 0x800000U | uVar2 | (uVar3 & 3) << 8 | 0x1000002c;
                *(uint **)(param_1 + 0xe30) = puVar8 + 2;
              }
              puVar9 = *(uint **)(param_1 + 0xe30);
              uVar6 = param_2 << 0x15 | 0x30000U | iVar4 << 0xb | 0x1000012c;
              goto LAB_97bda6e8;
            }
            puVar9 = puVar8 + 3;
            puVar8[2] = param_2 << 0x15 | 0x1003222c;
            *puVar12 = uVar6 << 0x10 | 0x800000 | uVar2 | 0x1000028c;
          }
          *(uint **)(param_1 + 0xe30) = puVar9;
          if (uVar7 == 0) {
            return;
          }
          uVar2 = param_2 << 0x15 | param_2 << 0x10 | uVar2;
          uVar6 = uVar7;
LAB_97bda70c:
          uVar6 = (4 - uVar6) * 0x100;
          goto LAB_97bda710;
        }
        if (iVar4 == 2) {
          uVar2 = uVar3 >> (uVar6 * -4 + 0x1c & 0x3f) & 0xf;
          iVar4 = param_2;
          if (uVar2 != 2) {
            puVar8 = *(uint **)(param_1 + 0xe30);
            iVar4 = 3;
            *puVar8 = param_2 << 0x10 | 0x600000U | param_2 << 0xb | (uVar2 * 4 + 8) * 0x40 & 0x300
                      | 0x1000002c;
            *(uint **)(param_1 + 0xe30) = puVar8 + 1;
          }
          uVar10 = uVar3 >> (uVar6 * -4 + 0x14 & 0x3f);
          uVar2 = uVar10 & 0xf;
          uVar7 = uVar3 >> (uVar6 * -4 + 0x10 & 0x3f) & 0xf;
          if (uVar7 == (uVar2 + 1 & 3)) {
            iVar5 = param_2;
            if (uVar2 != 0) {
              puVar8 = *(uint **)(param_1 + 0xe30);
              iVar5 = 4;
              *puVar8 = param_2 << 0x10 | 0x800000U | param_2 << 0xb | (uVar10 & 3) << 8 |
                        0x1000002c;
              *(uint **)(param_1 + 0xe30) = puVar8 + 1;
            }
            puVar8 = *(uint **)(param_1 + 0xe30);
            *puVar8 = param_2 << 0x15 | iVar4 << 0x10 | iVar5 << 0xb | 0x1000022c;
LAB_97bda854:
            *(uint **)(param_1 + 0xe30) = puVar8 + 1;
          }
          else {
            if (uVar7 == uVar2) {
              puVar8 = *(uint **)(param_1 + 0xe30);
              *puVar8 = uVar2 << 0x10 | 0x800000 | param_2 << 0xb | 0x1000028c;
              puVar8 = puVar8 + 1;
              *puVar8 = param_2 << 0x15 | iVar4 << 0x10 | 0x1000222c;
              goto LAB_97bda854;
            }
            iVar5 = param_2;
            if (uVar2 != 0) {
              puVar8 = *(uint **)(param_1 + 0xe30);
              iVar5 = 4;
              *puVar8 = param_2 << 0x10 | 0x800000U | param_2 << 0xb | (uVar10 & 3) << 8 |
                        0x1000002c;
              *(uint **)(param_1 + 0xe30) = puVar8 + 1;
            }
            uVar3 = uVar3 >> (uVar6 * -4 + 0x10 & 0x3f);
            puVar8 = *(uint **)(param_1 + 0xe30);
            *puVar8 = iVar4 << 0x10 | iVar5 << 0xb | 0x1060012c;
            *(uint **)(param_1 + 0xe30) = puVar8 + 1;
            iVar4 = param_2;
            if ((uVar3 & 0xf) != 0) {
              iVar4 = 4;
              puVar8[1] = param_2 << 0x10 | 0x800000U | param_2 << 0xb | (uVar3 & 3) << 8 |
                          0x1000002c;
              *(uint **)(param_1 + 0xe30) = puVar8 + 2;
            }
            puVar8 = *(uint **)(param_1 + 0xe30);
            *puVar8 = param_2 << 0x15 | 0x30000U | iVar4 << 0xb | 0x1000012c;
            *(uint **)(param_1 + 0xe30) = puVar8 + 1;
          }
          if (uVar6 == 0) {
            return;
          }
          uVar2 = param_2 << 0x15 | param_2 << 0x10 | param_2 << 0xb;
          goto LAB_97bda70c;
        }
        uVar6 = (uVar2 & 0x3000000) >> 0x18;
        iVar4 = param_2;
        if (uVar6 != 3) {
          puVar8 = *(uint **)(param_1 + 0xe30);
          iVar4 = 3;
          *puVar8 = param_2 << 0x10 | 0x600000U | param_2 << 0xb | (uVar6 * 4 + 4) * 0x40 & 0x300 |
                    0x1000002c;
          *(uint **)(param_1 + 0xe30) = puVar8 + 1;
        }
        iVar5 = param_2;
        if ((uVar2 & 0x30000) != 0) {
          puVar8 = *(uint **)(param_1 + 0xe30);
          iVar5 = 4;
          *puVar8 = param_2 << 0x10 | 0x800000U | param_2 << 0xb | ((uVar2 & 0x30000) >> 0x10) << 8
                    | 0x1000002c;
          *(uint **)(param_1 + 0xe30) = puVar8 + 1;
        }
        puVar8 = *(uint **)(param_1 + 0xe30);
        *puVar8 = iVar4 << 0x10 | iVar5 << 0xb | 0x1060012c;
        *(uint **)(param_1 + 0xe30) = puVar8 + 1;
        iVar4 = param_2;
        if ((uVar2 & 0x300) != 0) {
          iVar4 = 4;
          puVar8[1] = param_2 << 0x10 | 0x800000U | param_2 << 0xb | uVar2 & 0x300 | 0x1000002c;
          *(uint **)(param_1 + 0xe30) = puVar8 + 2;
        }
        puVar8 = *(uint **)(param_1 + 0xe30);
        *puVar8 = iVar4 << 0xb | 0x1063012c;
        *(uint **)(param_1 + 0xe30) = puVar8 + 1;
        iVar4 = param_2;
        if ((uVar2 & 3) != 0) {
          iVar4 = 4;
          puVar8[1] = param_2 << 0x10 | 0x800000U | param_2 << 0xb | (uVar2 & 3) << 8 | 0x1000002c;
          *(uint **)(param_1 + 0xe30) = puVar8 + 2;
        }
        puVar8 = *(uint **)(param_1 + 0xe30);
        uVar6 = param_2 << 0x15 | 0x30000U | iVar4 << 0xb | 0x1000012c;
        goto LAB_97bdaabc;
      }
      uVar2 = uVar3 >> (uVar6 * -4 + 0x1c & 0x3f) & 0xf;
      iVar4 = param_2;
      if (uVar2 != 1) {
        puVar8 = *(uint **)(param_1 + 0xe30);
        iVar4 = 3;
        *puVar8 = param_2 << 0x10 | 0x600000U | param_2 << 0xb | (uVar2 * 4 + 0xc) * 0x40 & 0x300 |
                  0x1000002c;
        *(uint **)(param_1 + 0xe30) = puVar8 + 1;
      }
      uVar3 = uVar3 >> (uVar6 * -4 + 0x10 & 0x3f);
      iVar5 = param_2;
      if ((uVar3 & 0xf) != 0) {
        puVar8 = *(uint **)(param_1 + 0xe30);
        iVar5 = 4;
        *puVar8 = param_2 << 0x10 | 0x800000U | param_2 << 0xb | (uVar3 & 3) << 8 | 0x1000002c;
        *(uint **)(param_1 + 0xe30) = puVar8 + 1;
      }
      puVar8 = *(uint **)(param_1 + 0xe30);
      *puVar8 = param_2 << 0x15 | iVar4 << 0x10 | iVar5 << 0xb | 0x1000012c;
      puVar8 = puVar8 + 1;
      *(uint **)(param_1 + 0xe30) = puVar8;
      if (uVar6 == 0) {
        return;
      }
      uVar2 = param_2 << 0x15 | param_2 << 0x10 | param_2 << 0xb;
    }
    *puVar8 = uVar2 | (4 - uVar6) * 0x100 & 0x300 | 0x1000002c;
  }
  *(uint **)(param_1 + 0xe30) = puVar8 + 1;
  return;
}

/* _PPCRuntimeCompilerFindVariableInfo @ 0x97bdaac8 (88 bytes) */
int _PPCRuntimeCompilerFindVariableInfo(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  uint uVar2;
  
  uVar2 = 0;
  piVar1 = *(int **)(param_1 + 0xe00);
  if (*(uint *)(param_1 + 0xe04) != 0) {
    do {
      if (param_2 == *piVar1) {
        return piVar1;
      }
      uVar2 = uVar2 + 1;
      piVar1 = piVar1 + 2;
    } while (uVar2 < *(uint *)(param_1 + 0xe04));
  }
  return (int *)0x0;
}

/* _PPCRuntimeCompilerLoadSourceNO @ 0x97bdab20 (348 bytes) */
int _PPCRuntimeCompilerLoadSourceNO(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  int iVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  int in_stack_00000044;
  
  iVar1 = in_stack_00000044 * 4;
  uStack0000001c = param_2;
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  if ((*(uint *)(param_1 + 0xe50) & 4) != 0) {
    uVar5 = 0;
    do {
      iVar4 = iVar1 + uVar5;
      ((int (*)())_PPCRuntimeCompilerBackupRegister)(param_1,iVar4);
      uVar5 = uVar5 + 1;
      ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,iVar4);
    } while (uVar5 < 4);
  }
  uVar5 = 0;
  do {
    iVar4 = iVar1 + uVar5;
    uVar5 = uVar5 + 1;
    ((int (*)())_PPCRuntimeCompilerLoadRegister)(param_1,iVar4,uStack0000001c,uStack00000020,uStack00000024,uStack00000028,
               uStack0000002c,uStack00000030);
  } while (uVar5 < 4);
  if ((*(unsigned char *)((unsigned char *)&(uStack0000002c) + 2)) == '\0') {
    return;
  }
  if (in_stack_00000044 == 0) {
    uVar3 = *(undefined4 *)(param_1 + 0xe30);
    puVar2 = &_glpNegateSourceARTC;
  }
  else if (in_stack_00000044 == 1) {
    uVar3 = *(undefined4 *)(param_1 + 0xe30);
    puVar2 = &_glpNegateSourceBRTC;
  }
  else {
    if (in_stack_00000044 != 2) goto LAB_97bdac4c;
    uVar3 = *(undefined4 *)(param_1 + 0xe30);
    puVar2 = &_glpNegateSourceCRTC;
  }
  iVar4 = ((int (*)())_glpRTCAddAChunk)(puVar2,uVar3);
  *(int *)(param_1 + 0xe30) = *(int *)(param_1 + 0xe30) + iVar4 * 4;
LAB_97bdac4c:
  uVar5 = 0;
  do {
    iVar4 = iVar1 + uVar5;
    uVar5 = uVar5 + 1;
    ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,iVar4);
  } while (uVar5 < 4);
  return;
}

/* _PPCRuntimeCompilerLoadSourceAV @ 0x97bdac7c (268 bytes) */
int _PPCRuntimeCompilerLoadSourceAV(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  uint *puVar1;
  int iStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  int in_stack_00000040;
  int in_stack_00000044;
  
  iStack0000001c = param_2;
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  if ((*(uint *)(param_1 + 0xe50) & 4) != 0) {
    ((int (*)())_PPCRuntimeCompilerBackupRegister)(param_1,in_stack_00000044);
    ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,in_stack_00000044);
  }
  iStack0000001c = iStack0000001c + in_stack_00000040 * 0x10;
  ((int (*)())_PPCRuntimeCompilerLoadRegister)(param_1,in_stack_00000044,iStack0000001c,uStack00000020,uStack00000024,uStack00000028,
             uStack0000002c,uStack00000030);
  if ((*(unsigned char *)((unsigned char *)&(uStack0000002c) + 2)) != '\0') {
    puVar1 = *(uint **)(param_1 + 0xe30);
    *puVar1 = in_stack_00000044 << 0x15 | in_stack_00000044 << 0x10 | 0x10003cc4;
    *(uint **)(param_1 + 0xe30) = puVar1 + 1;
    ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,in_stack_00000044);
    return;
  }
  return;
}

/* _PPCRuntimeCompilerWriteDestinationNO @ 0x97bdad88 (368 bytes) */
int _PPCRuntimeCompilerWriteDestinationNO(param_1, param_2)
  int param_1;
  int param_2;
{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  byte local_34;
  
  _memcpy(&local_50,(void *)(*(int *)(param_1 + 0xe28) + 0xc),0x24);
  uVar2 = 0x2000000;
  ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,0x10);
  ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,0x11);
  ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,0x12);
  ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,0x13);
  uVar3 = 0;
  do {
    if ((local_34 >> (uVar3 & 0x3f) & 1) != 0) {
      if (((*(unsigned short *)((unsigned char *)&(local_40) + 0)) == 1) || ((*(uint *)(param_1 + 0xe50) & 4) == 0)) {
        puVar1 = *(uint **)(param_1 + 0xe30);
        *puVar1 = uVar2 | (uint)(ushort)((*(unsigned short *)((unsigned char *)&(local_40) + 0)) + 5) << 0x10 |
                  *(uint *)(uVar3 * 4 + local_50 + param_2 * 0x10) & 0xffff | 0xd0000000;
        *(uint **)(param_1 + 0xe30) = puVar1 + 1;
      }
      else {
        ((int (*)())_PPCRuntimeCompilerDirtyRegistersWithData)(param_1,local_50,local_4c,local_48,local_44,local_40,local_3c,local_38);
        ((int (*)())_PPCRuntimeCompilerSetRegister)(param_1,uVar3 + 0x10,local_50,local_4c,local_48,local_44,local_40,local_3c);
      }
    }
    uVar3 = uVar3 + 1;
    uVar2 = uVar2 + 0x200000;
  } while (uVar3 < 4);
  return;
}

/* _PPCRuntimeCompilerWriteDestinationAV @ 0x97bdaef8 (748 bytes) */
int _PPCRuntimeCompilerWriteDestinationAV(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  uint local_34;
  
  iVar4 = *(int *)(param_1 + 0xe28);
  _memcpy(&local_50,(void *)(iVar4 + 0xc),0x24);
  local_50 = local_50 + param_2 * 0x10;
  ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,2);
  ((int (*)())_PPCRuntimeCompilerSwizzleRegisterAV)(param_1,2,&local_48);
  _PPEmulatorVariableSwizzleFromMask(&local_50);
  if (*(char *)(iVar4 + 6) != '\0') {
    iVar4 = ((int (*)())_glpRTCAddAChunk)(&_glpOpBuildConditionCodeAVRTC,*(undefined4 *)(param_1 + 0xe30));
    iVar3 = *(int *)(param_1 + 0xe30);
    iVar4 = iVar4 * 4;
    puVar2 = (undefined4 *)(iVar3 + iVar4);
    *(undefined4 **)(param_1 + 0xe30) = puVar2;
    if ((*(unsigned char *)((unsigned char *)&(local_34) + 0)) == '\x0f') {
      *(undefined4 *)(iVar3 + iVar4) = 0x12852c84;
    }
    else {
      *(undefined4 *)(iVar3 + iVar4) = 0x10836a8c;
      *(undefined4 **)(param_1 + 0xe30) = puVar2 + 2;
      uVar1 = 0x1063212c;
      if ((local_34 & 0x1000000) == 0) {
        uVar1 = 0x1063492c;
      }
      puVar2[1] = uVar1;
      puVar2 = *(undefined4 **)(param_1 + 0xe30);
      uVar1 = 0x1063212c;
      *(undefined4 **)(param_1 + 0xe30) = puVar2 + 1;
      if ((local_34 & 0x2000000) == 0) {
        uVar1 = 0x1063492c;
      }
      *puVar2 = uVar1;
      puVar2 = *(undefined4 **)(param_1 + 0xe30);
      uVar1 = 0x1063212c;
      *(undefined4 **)(param_1 + 0xe30) = puVar2 + 1;
      if ((local_34 & 0x4000000) == 0) {
        uVar1 = 0x1063492c;
      }
      *puVar2 = uVar1;
      puVar2 = *(undefined4 **)(param_1 + 0xe30);
      uVar1 = 0x1063212c;
      *(undefined4 **)(param_1 + 0xe30) = puVar2 + 1;
      if ((local_34 & 0x8000000) == 0) {
        uVar1 = 0x1063492c;
      }
      *puVar2 = uVar1;
      puVar2 = *(undefined4 **)(param_1 + 0xe30);
      *puVar2 = 0x129428ea;
    }
    *(undefined4 **)(param_1 + 0xe30) = puVar2 + 1;
  }
  if ((char)local_40 != '\0') {
    ((int (*)())_PPCRuntimeCompilerSaveAllTemporariesToMemory)(param_1);
  }
  if (((((*(unsigned short *)((unsigned char *)&(local_40) + 0)) == 1) || ((*(unsigned short *)((unsigned char *)&(local_40) + 0)) == 9)) || ((*(uint *)(param_1 + 0xe50) & 4) == 0))
     || ((local_40 & 0xff) != 0)) {
    ((int (*)())_PPCRuntimeCompilerSetRegister)(param_1,2,local_50,local_4c,local_48,local_44,local_40,local_3c);
    ((int (*)())_PPCRuntimeCompilerSaveRegisterToMemory)(param_1,2);
    ((int (*)())_PPCRuntimeCompilerDirtyRegistersWithData)(param_1,local_50,local_4c,local_48,local_44,local_40,local_3c,local_38);
  }
  else {
    ((int (*)())_PPCRuntimeCompilerDirtyRegistersWithData)(param_1,local_50,local_4c,local_48,local_44,local_40,local_3c,local_38);
    ((int (*)())_PPCRuntimeCompilerSetRegister)(param_1,2,local_50,local_4c,local_48,local_44,local_40,local_3c);
  }
  return;
}

/* _PPCRuntimeCompilerTestConditionRegisterAV @ 0x97bdb1e4 (576 bytes) */
int _PPCRuntimeCompilerTestConditionRegisterAV(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  uint uVar1;
  undefined4 *puVar2;
  uint *puVar3;
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  undefined4 in_stack_00000038;
  
  uStack0000001c = param_2;
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  switch((*(unsigned char *)((unsigned char *)&(in_stack_00000038) + 1))) {
  case 0:
    puVar3 = *(uint **)(param_1 + 0xe30);
    uVar1 = 0x10636a8c;
    goto LAB_97bdb424;
  case 1:
    puVar2 = *(undefined4 **)(param_1 + 0xe30);
    *puVar2 = 0x10b4a484;
    *(undefined4 **)(param_1 + 0xe30) = puVar2 + 1;
    ((int (*)())_PPCRuntimeCompilerSwizzleRegisterAV)(param_1,5,(int)&STACKARG(0x38) + 2);
    puVar3 = *(uint **)(param_1 + 0xe30);
    uVar1 = 0x10600000;
    break;
  case 2:
    puVar2 = *(undefined4 **)(param_1 + 0xe30);
    *puVar2 = 0x10b4a484;
    *(undefined4 **)(param_1 + 0xe30) = puVar2 + 1;
    ((int (*)())_PPCRuntimeCompilerSwizzleRegisterAV)(param_1,5,(int)&STACKARG(0x38) + 2);
    puVar2 = *(undefined4 **)(param_1 + 0xe30);
    uVar1 = 0x10810000;
    goto LAB_97bdb338;
  case 3:
    puVar2 = *(undefined4 **)(param_1 + 0xe30);
    *puVar2 = 0x10b4a484;
    *(undefined4 **)(param_1 + 0xe30) = puVar2 + 1;
    ((int (*)())_PPCRuntimeCompilerSwizzleRegisterAV)(param_1,5,(int)&STACKARG(0x38) + 2);
    puVar3 = *(uint **)(param_1 + 0xe30);
    uVar1 = 0x10610000;
    break;
  case 4:
    puVar2 = *(undefined4 **)(param_1 + 0xe30);
    *puVar2 = 0x10b4a484;
    *(undefined4 **)(param_1 + 0xe30) = puVar2 + 1;
    ((int (*)())_PPCRuntimeCompilerSwizzleRegisterAV)(param_1,5,(int)&STACKARG(0x38) + 2);
    puVar2 = *(undefined4 **)(param_1 + 0xe30);
    uVar1 = 0x10820000;
LAB_97bdb338:
    *puVar2 = 0x1060038c;
    puVar2[1] = uVar1 | 0x38c;
    puVar2[2] = 0x10651886;
    puVar2[3] = 0x10852086;
    puVar2[4] = 0x10632484;
    *(undefined4 **)(param_1 + 0xe30) = puVar2 + 5;
    return;
  case 5:
    puVar2 = *(undefined4 **)(param_1 + 0xe30);
    *puVar2 = 0x10b4a484;
    *(undefined4 **)(param_1 + 0xe30) = puVar2 + 1;
    ((int (*)())_PPCRuntimeCompilerSwizzleRegisterAV)(param_1,5,(int)&STACKARG(0x38) + 2);
    puVar3 = *(uint **)(param_1 + 0xe30);
    uVar1 = 0x10620000;
    break;
  case 6:
    puVar2 = *(undefined4 **)(param_1 + 0xe30);
    *puVar2 = 0x10b4a484;
    *(undefined4 **)(param_1 + 0xe30) = puVar2 + 1;
    ((int (*)())_PPCRuntimeCompilerSwizzleRegisterAV)(param_1,5,(int)&STACKARG(0x38) + 2);
    puVar2 = *(undefined4 **)(param_1 + 0xe30);
    *puVar2 = 0x1060038c;
    puVar2[1] = 0x10651886;
    puVar3 = puVar2 + 3;
    puVar2[2] = 0x10631d04;
    goto LAB_97bdb42c;
  case 7:
    puVar3 = *(uint **)(param_1 + 0xe30);
    uVar1 = 0x10694c84;
LAB_97bdb424:
    *puVar3 = uVar1;
    goto LAB_97bdb428;
  default:
    goto switchD_97bdb240_default;
  }
  *puVar3 = uVar1 | 0x38c;
  puVar3 = puVar3 + 1;
  *puVar3 = 0x10651886;
LAB_97bdb428:
  puVar3 = puVar3 + 1;
LAB_97bdb42c:
  *(uint **)(param_1 + 0xe30) = puVar3;
switchD_97bdb240_default:
  return;
}

/* _PPCRuntimeCompilerWriteFinalFragmentToBuffer @ 0x97bdb444 (568 bytes) */
int _PPCRuntimeCompilerWriteFinalFragmentToBuffer(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  
  iVar6 = *(int *)(param_1 + 0xe20);
  bVar1 = false;
  if (((*(uint *)(*(int *)(iVar6 + 0xd80) + 0x3c) & 0x40) != 0) &&
     ((*(uint *)(*(int *)(iVar6 + 0xd80) + 0x70) & 0x1e0000) != 0x1e0000)) {
    bVar1 = true;
  }
  bVar2 = false;
  if (((*(uint *)(*(int *)(iVar6 + 0xd80) + 0x3c) & 0x20) != 0) &&
     (3 < (*(uint *)(*(int *)(iVar6 + 0xd80) + 0x68) & 0xf))) {
    bVar2 = true;
  }
  if ((*(uint *)(*(int *)(iVar6 + 0xd80) + 0x3c) & 1) != 0) {
    uVar3 = _PPCRasterOpMachine_AlphaTestRTCAV(param_1 + 0xe14,*(undefined4 *)(param_1 + 0xe30));
    iVar6 = *(int *)(param_1 + 0xe20);
    *(undefined4 *)(param_1 + 0xe30) = uVar3;
  }
  if ((*(uint *)(*(int *)(iVar6 + 0xd80) + 0x3c) & 6) != 0) {
    uVar3 = _PPCRasterOpMachine_DepthAndStencilTestRTCAV
                      (param_1 + 0xe14,*(undefined4 *)(param_1 + 0xe30));
    iVar6 = *(int *)(param_1 + 0xe20);
    *(undefined4 *)(param_1 + 0xe30) = uVar3;
  }
  if ((((*(uint *)(*(int *)(iVar6 + 0xd80) + 0x3c) & 8) != 0) || (bVar2)) || (bVar1)) {
    uVar4 = _PPEmulatorFramebufferFormat(iVar6);
    if ((uVar4 & 0x8000) == 0) {
      uVar4 = _PPEmulatorFramebufferFormat(*(undefined4 *)(param_1 + 0xe20));
      if ((uVar4 & 0x8000000) != 0) {
        puVar5 = *(undefined4 **)(param_1 + 0xe30);
        *puVar5 = 0x7c4030ce;
        *(undefined4 **)(param_1 + 0xe30) = puVar5 + 1;
      }
    }
    else {
      iVar6 = ((int (*)())_glpRTCAddAChunk)(&_glpOpConvertARGB8888ToRGBAFFFF,*(undefined4 *)(param_1 + 0xe30));
      *(int *)(param_1 + 0xe30) = *(int *)(param_1 + 0xe30) + iVar6 * 4;
    }
    iVar6 = *(int *)(param_1 + 0xe20);
  }
  if ((*(uint *)(*(int *)(iVar6 + 0xd80) + 0x3c) & 8) != 0) {
    uVar3 = _PPCRasterOpMachine_BlendingRTCAV(param_1 + 0xe14,*(undefined4 *)(param_1 + 0xe30));
    iVar6 = *(int *)(param_1 + 0xe20);
    *(undefined4 *)(param_1 + 0xe30) = uVar3;
  }
  if ((*(uint *)(*(int *)(iVar6 + 0xd80) + 0x3c) & 0x20) != 0) {
    uVar3 = _PPCRasterOpMachine_LogicOpRTCAV(param_1 + 0xe14,*(undefined4 *)(param_1 + 0xe30));
    *(undefined4 *)(param_1 + 0xe30) = uVar3;
  }
  if (bVar1) {
    uVar3 = _PPCRasterOpMachine_BufferMaskRTCAV(param_1 + 0xe14,*(undefined4 *)(param_1 + 0xe30));
    *(undefined4 *)(param_1 + 0xe30) = uVar3;
  }
  uVar4 = _PPEmulatorFramebufferFormat(*(undefined4 *)(param_1 + 0xe20));
  if ((uVar4 & 0x8000) == 0) {
    uVar4 = _PPEmulatorFramebufferFormat(*(undefined4 *)(param_1 + 0xe20));
    if ((uVar4 & 0x8000000) == 0) {
      return;
    }
    puVar5 = *(undefined4 **)(param_1 + 0xe30);
    *puVar5 = 0x7e6031ce;
  }
  else {
    puVar5 = *(undefined4 **)(param_1 + 0xe30);
    *puVar5 = 0x10739c84;
    *(undefined4 **)(param_1 + 0xe30) = puVar5 + 1;
    iVar6 = ((int (*)())_glpRTCAddAChunk)(&_glpOpConvertRGBAFFFFToARGB8888);
    puVar5 = (undefined4 *)(*(int *)(param_1 + 0xe30) + iVar6 * 4);
    *(undefined4 *)(*(int *)(param_1 + 0xe30) + iVar6 * 4) = 0x7c60318e;
  }
  *(undefined4 **)(param_1 + 0xe30) = puVar5 + 1;
  return;
}

/* _PPCRuntimeCompilerWritePrologNO @ 0x97bdb67c (828 bytes) */
int _PPCRuntimeCompilerWritePrologNO(param_1)
  int param_1;
{
  uint *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  iVar7 = 0x13;
  iVar5 = 0xd;
  uVar3 = 0x284;
  do {
    if ((iVar5 != 0x10) || ((*(uint *)(*(int *)(param_1 + 0xe24) + 0x34) & 0x200) != 0)) {
      puVar1 = *(uint **)(param_1 + 0xe30);
      *puVar1 = iVar5 << 0x15 | uVar3 & 0xffff | 0x90030000;
      *(uint **)(param_1 + 0xe30) = puVar1 + 1;
    }
    iVar5 = iVar5 + 1;
    uVar3 = uVar3 + 4;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  uVar6 = 0xe;
  iVar5 = 0x12;
  uVar3 = 0x308;
  piVar4 = (int *)(param_1 + 0x33c);
  do {
    if ((uVar6 < 0x14) || (*piVar4 != 0)) {
      puVar1 = *(uint **)(param_1 + 0xe30);
      *puVar1 = uVar6 << 0x15 | uVar3 & 0xffff | 0xd0030000;
      *(uint **)(param_1 + 0xe30) = puVar1 + 1;
    }
    uVar6 = uVar6 + 1;
    piVar4 = piVar4 + 0xe;
    uVar3 = uVar3 + 4;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  if ((*(uint *)(*(int *)(param_1 + 0xe24) + 0x34) & 0x400) != 0) {
    puVar2 = *(undefined4 **)(param_1 + 0xe30);
    *puVar2 = 0xfd00048e;
    puVar2[1] = 0xd1030350;
    puVar2[2] = 0xffc0004c;
    puVar2[3] = 0xffe0004c;
    *(undefined4 **)(param_1 + 0xe30) = puVar2 + 4;
  }
  puVar2 = *(undefined4 **)(param_1 + 0xe30);
  *puVar2 = 0x80430d9c;
  iVar5 = *(int *)(param_1 + 0xe24);
  *(undefined4 **)(param_1 + 0xe30) = puVar2 + 1;
  if ((*(uint *)(iVar5 + 0x34) & 1) != 0) {
    puVar2[1] = 0x80a30d84;
    iVar5 = *(int *)(param_1 + 0xe24);
    *(undefined4 **)(param_1 + 0xe30) = puVar2 + 2;
  }
  if ((*(uint *)(iVar5 + 0x34) & 2) != 0) {
    puVar2 = *(undefined4 **)(param_1 + 0xe30);
    *puVar2 = 0x80c30d88;
    iVar5 = *(int *)(param_1 + 0xe24);
    *(undefined4 **)(param_1 + 0xe30) = puVar2 + 1;
  }
  if ((*(uint *)(iVar5 + 0x34) & 4) != 0) {
    puVar2 = *(undefined4 **)(param_1 + 0xe30);
    *puVar2 = 0x80e30d8c;
    iVar5 = *(int *)(param_1 + 0xe24);
    *(undefined4 **)(param_1 + 0xe30) = puVar2 + 1;
  }
  if ((*(uint *)(iVar5 + 0x34) & 8) != 0) {
    puVar2 = *(undefined4 **)(param_1 + 0xe30);
    *puVar2 = 0x81030d90;
    iVar5 = *(int *)(param_1 + 0xe24);
    *(undefined4 **)(param_1 + 0xe30) = puVar2 + 1;
  }
  if ((*(uint *)(iVar5 + 0x34) & 0x10) != 0) {
    puVar2 = *(undefined4 **)(param_1 + 0xe30);
    *puVar2 = 0x81230d94;
    iVar5 = *(int *)(param_1 + 0xe24);
    *(undefined4 **)(param_1 + 0xe30) = puVar2 + 1;
  }
  if ((*(uint *)(iVar5 + 0x34) & 0x20) != 0) {
    puVar2 = *(undefined4 **)(param_1 + 0xe30);
    *puVar2 = 0x81430d98;
    iVar5 = *(int *)(param_1 + 0xe24);
    *(undefined4 **)(param_1 + 0xe30) = puVar2 + 1;
  }
  if (((*(int *)(iVar5 + 0x38) == 0x8804) || (*(int *)(iVar5 + 0x38) == 0x8b30)) &&
     ((*(uint *)(iVar5 + 0x34) & 0x1004) != 0)) {
    puVar2 = *(undefined4 **)(param_1 + 0xe30);
    *puVar2 = 0x81830da4;
    puVar2[1] = 0x81a30da0;
    *(undefined4 **)(param_1 + 0xe30) = puVar2 + 2;
  }
  iVar7 = ((int (*)())_glpRTCAddAChunk)(&_glpOpLoadOneAndZeroRTC,*(undefined4 *)(param_1 + 0xe30));
  iVar5 = *(int *)(param_1 + 0xe30);
  *(undefined4 *)(iVar5 + iVar7 * 4) = 0x7c8903a6;
  iVar5 = iVar5 + iVar7 * 4;
  iVar7 = *(int *)(param_1 + 0xe24);
  *(int *)(param_1 + 0xe30) = iVar5 + 4;
  if ((*(int *)(iVar7 + 0x38) != 0x8804) && (*(int *)(iVar7 + 0x38) != 0x8b30)) {
    *(undefined4 *)(iVar5 + 4) = 0x3a2000ff;
    *(undefined4 *)(iVar5 + 8) = 0x3a400000;
    iVar7 = *(int *)(param_1 + 0xe24);
    *(int *)(param_1 + 0xe30) = iVar5 + 0xc;
  }
  if ((*(int *)(iVar7 + 0x38) == 0x8804) || (*(int *)(iVar7 + 0x38) == 0x8b30)) {
    puVar2 = *(undefined4 **)(param_1 + 0xe30);
    *puVar2 = 0xfd805890;
    *(undefined4 **)(param_1 + 0xe30) = puVar2 + 1;
  }
  return;
}

/* _PPCRuntimeCompilerWriteEpilogNO @ 0x97bdb9b8 (352 bytes) */
int _PPCRuntimeCompilerWriteEpilogNO(param_1)
  int param_1;
{
  undefined4 *puVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  
  iVar2 = *(int *)(param_1 + 0xe24);
  if ((*(int *)(iVar2 + 0x38) != 0x8804) && (*(int *)(iVar2 + 0x38) != 0x8b30)) {
    puVar1 = *(undefined4 **)(param_1 + 0xe30);
    *puVar1 = 0x39e00008;
    puVar1[1] = 0x7e317830;
    puVar1[2] = 0x7e259378;
    iVar2 = *(int *)(param_1 + 0xe24);
    *(undefined4 **)(param_1 + 0xe30) = puVar1 + 3;
  }
  if ((*(uint *)(iVar2 + 0x34) & 0x400) != 0) {
    puVar1 = *(undefined4 **)(param_1 + 0xe30);
    *puVar1 = 0xc1030350;
    puVar1[1] = 0xfdfe458e;
    *(undefined4 **)(param_1 + 0xe30) = puVar1 + 2;
  }
  iVar2 = 0xd;
  iVar7 = 0x13;
  uVar4 = 0x284;
  do {
    if ((iVar2 != 0x10) || ((*(uint *)(*(int *)(param_1 + 0xe24) + 0x34) & 0x200) != 0)) {
      puVar3 = *(uint **)(param_1 + 0xe30);
      *puVar3 = iVar2 << 0x15 | uVar4 & 0xffff | 0x80030000;
      *(uint **)(param_1 + 0xe30) = puVar3 + 1;
    }
    iVar2 = iVar2 + 1;
    uVar4 = uVar4 + 4;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  uVar6 = 0xe;
  iVar2 = 0x12;
  uVar4 = 0x308;
  piVar5 = (int *)(param_1 + 0x33c);
  do {
    if ((uVar6 < 0x14) || (*piVar5 != 0)) {
      puVar3 = *(uint **)(param_1 + 0xe30);
      *puVar3 = uVar6 << 0x15 | uVar4 & 0xffff | 0xc0030000;
      *(uint **)(param_1 + 0xe30) = puVar3 + 1;
    }
    uVar6 = uVar6 + 1;
    piVar5 = piVar5 + 0xe;
    uVar4 = uVar4 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar1 = *(undefined4 **)(param_1 + 0xe30);
  *puVar1 = 0x7ca32b78;
  puVar1[1] = 0x4e800020;
  *(undefined4 **)(param_1 + 0xe30) = puVar1 + 2;
  return;
}

/* _PPCRuntimeCompilerWritePrologAV @ 0x97bdbb18 (1132 bytes) */
int _PPCRuntimeCompilerWritePrologAV(param_1)
  int param_1;
{
  undefined4 *puVar1;
  uint *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  puVar1 = *(undefined4 **)(param_1 + 0xe30);
  *puVar1 = 0x7c0042a6;
  iVar7 = 0x20;
  *(undefined4 **)(param_1 + 0xe30) = puVar1 + 1;
  do {
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  puVar1 = *(undefined4 **)(param_1 + 0xe30);
  *puVar1 = 0x6405ffff;
  puVar1[1] = 0x60a5ffff;
  puVar1[2] = 0x7ca043a6;
  puVar1[3] = 0x10ff038c;
  iVar8 = 0x13;
  puVar1[4] = 0x10e73984;
  iVar7 = 0xd;
  *(undefined4 **)(param_1 + 0xe30) = puVar1 + 5;
  uVar4 = 0x284;
  do {
    if ((iVar7 != 0x10) || ((*(uint *)(*(int *)(param_1 + 0xe24) + 0x34) & 0x200) != 0)) {
      puVar2 = *(uint **)(param_1 + 0xe30);
      *puVar2 = iVar7 << 0x15 | uVar4 & 0xffff | 0x90030000;
      *(uint **)(param_1 + 0xe30) = puVar2 + 1;
    }
    iVar7 = iVar7 + 1;
    uVar4 = uVar4 + 4;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  puVar1 = *(undefined4 **)(param_1 + 0xe30);
  *puVar1 = 0x80430d9c;
  iVar7 = *(int *)(param_1 + 0xe24);
  *(undefined4 **)(param_1 + 0xe30) = puVar1 + 1;
  if ((*(uint *)(iVar7 + 0x34) & 1) != 0) {
    puVar1[1] = 0x80a30d84;
    iVar7 = *(int *)(param_1 + 0xe24);
    *(undefined4 **)(param_1 + 0xe30) = puVar1 + 2;
  }
  if ((*(uint *)(iVar7 + 0x34) & 2) != 0) {
    puVar1 = *(undefined4 **)(param_1 + 0xe30);
    *puVar1 = 0x80c30d88;
    iVar7 = *(int *)(param_1 + 0xe24);
    *(undefined4 **)(param_1 + 0xe30) = puVar1 + 1;
  }
  if ((*(uint *)(iVar7 + 0x34) & 4) != 0) {
    puVar1 = *(undefined4 **)(param_1 + 0xe30);
    *puVar1 = 0x80e30d8c;
    iVar7 = *(int *)(param_1 + 0xe24);
    *(undefined4 **)(param_1 + 0xe30) = puVar1 + 1;
  }
  if ((*(uint *)(iVar7 + 0x34) & 8) != 0) {
    puVar1 = *(undefined4 **)(param_1 + 0xe30);
    *puVar1 = 0x81030d90;
    iVar7 = *(int *)(param_1 + 0xe24);
    *(undefined4 **)(param_1 + 0xe30) = puVar1 + 1;
  }
  if ((*(uint *)(iVar7 + 0x34) & 0x10) != 0) {
    puVar1 = *(undefined4 **)(param_1 + 0xe30);
    *puVar1 = 0x81230d94;
    iVar7 = *(int *)(param_1 + 0xe24);
    *(undefined4 **)(param_1 + 0xe30) = puVar1 + 1;
  }
  if ((*(uint *)(iVar7 + 0x34) & 0x20) != 0) {
    puVar1 = *(undefined4 **)(param_1 + 0xe30);
    *puVar1 = 0x81430d98;
    *(undefined4 **)(param_1 + 0xe30) = puVar1 + 1;
  }
  iVar7 = ((int (*)())_glpRTCAddAChunk)(&_glpOpLoadOneAndZeroAVRTC,*(undefined4 *)(param_1 + 0xe30));
  iVar5 = *(int *)(param_1 + 0xe30);
  iVar8 = *(int *)(param_1 + 0xe24);
  iVar6 = iVar5 + iVar7 * 4;
  *(int *)(param_1 + 0xe30) = iVar6;
  if (((*(int *)(iVar8 + 0x38) == 0x8804) || (*(int *)(iVar8 + 0x38) == 0x8b30)) &&
     ((*(uint *)(iVar8 + 0x34) & 0x1004) != 0)) {
    *(undefined4 *)(iVar5 + iVar7 * 4) = 0x81830da4;
    *(undefined4 *)(iVar6 + 4) = 0x81a30da0;
    iVar8 = *(int *)(param_1 + 0xe24);
    *(int *)(param_1 + 0xe30) = iVar6 + 8;
  }
  if ((*(int *)(iVar8 + 0x38) != 0x8804) && (*(int *)(iVar8 + 0x38) != 0x8b30)) {
    puVar1 = *(undefined4 **)(param_1 + 0xe30);
    *puVar1 = 0x39e01b70;
    puVar1[1] = 0x7dcf10ce;
    puVar1[2] = 0x39e01b80;
    puVar1[3] = 0x7def10ce;
    puVar1[4] = 0x39e00000;
    puVar1[5] = 0x7e4f18ce;
    puVar1[6] = 0x121f038c;
    puVar1[7] = 0x12294c84;
    *(undefined4 **)(param_1 + 0xe30) = puVar1 + 8;
  }
  puVar1 = *(undefined4 **)(param_1 + 0xe30);
  *puVar1 = 0x7c8903a6;
  *(undefined4 **)(param_1 + 0xe30) = puVar1 + 1;
  iVar7 = ((int (*)())_glpRTCAddAChunk)(&_glpOpLoadOneAndZeroRTC);
  iVar8 = *(int *)(param_1 + 0xe24);
  *(int *)(param_1 + 0xe30) = *(int *)(param_1 + 0xe30) + iVar7 * 4;
  if ((*(int *)(iVar8 + 0x38) == 0x8804) || (*(int *)(iVar8 + 0x38) == 0x8b30)) {
    uVar4 = _PPEmulatorFramebufferFormat(*(undefined4 *)(param_1 + 0xe20));
    if ((uVar4 & 0x8000) != 0) {
      puVar1 = *(undefined4 **)(param_1 + 0xe30);
      *puVar1 = 0x39e00040;
      puVar1[1] = 0x7e4378ce;
      *(undefined4 **)(param_1 + 0xe30) = puVar1 + 2;
    }
    iVar8 = *(int *)(param_1 + 0xe24);
  }
  if ((*(int *)(iVar8 + 0x38) == 0x8804) || (*(int *)(iVar8 + 0x38) == 0x8b30)) {
    if ((*(uint *)(iVar8 + 0x34) & 4) != 0) {
      puVar1 = *(undefined4 **)(param_1 + 0xe30);
      *puVar1 = 0x7c6068ce;
      puVar3 = puVar1 + 1;
      *(undefined4 **)(param_1 + 0xe30) = puVar3;
      if ((*(uint *)(param_1 + 0xe50) & 8) == 0) {
        *puVar3 = 0x11c9436a;
        iVar8 = *(int *)(param_1 + 0xe24);
        *(undefined4 **)(param_1 + 0xe30) = puVar1 + 2;
      }
      else {
        *puVar3 = 0x1080190a;
        puVar1[2] = 0x11c9236a;
        iVar8 = *(int *)(param_1 + 0xe24);
        *(undefined4 **)(param_1 + 0xe30) = puVar1 + 3;
      }
    }
    if ((*(uint *)(iVar8 + 0x34) & 0x1000) != 0) {
      puVar1 = *(undefined4 **)(param_1 + 0xe30);
      *puVar1 = 0xfd805890;
      puVar1[1] = 0xc1ad0008;
      *(undefined4 **)(param_1 + 0xe30) = puVar1 + 2;
    }
  }
  return;
}

/* _PPCRuntimeCompilerWriteEpilogAV @ 0x97bdbf84 (304 bytes) */
int _PPCRuntimeCompilerWriteEpilogAV(param_1)
  int param_1;
{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0xe24) + 0x38);
  if ((iVar1 != 0x8804) && (iVar1 != 0x8b30)) {
    puVar4 = *(undefined4 **)(param_1 + 0xe30);
    *puVar4 = 0x1210486c;
    puVar4[1] = 0x39e0020e;
    puVar4[2] = 0x10718484;
    puVar4[3] = 0x7c6f194e;
    puVar4[4] = 0x7caf1a2e;
    *(undefined4 **)(param_1 + 0xe30) = puVar4 + 5;
  }
  iVar1 = 0xd;
  iVar5 = 0x13;
  uVar3 = 0x284;
  do {
    if ((iVar1 != 0x10) || ((*(uint *)(*(int *)(param_1 + 0xe24) + 0x34) & 0x200) != 0)) {
      puVar2 = *(uint **)(param_1 + 0xe30);
      *puVar2 = iVar1 << 0x15 | uVar3 & 0xffff | 0x80030000;
      *(uint **)(param_1 + 0xe30) = puVar2 + 1;
    }
    iVar1 = iVar1 + 1;
    uVar3 = uVar3 + 4;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  puVar4 = *(undefined4 **)(param_1 + 0xe30);
  *puVar4 = 0x7ca32b78;
  *(undefined4 **)(param_1 + 0xe30) = puVar4 + 1;
  iVar1 = ((int (*)())_glpRTCAddAChunk)(&_glpEpilogAVRTC);
  *(int *)(param_1 + 0xe30) = *(int *)(param_1 + 0xe30) + iVar1 * 4;
  return;
}

/* _PPCRuntimeCompilerStride @ 0x97bdc0b4 (548 bytes) */
int _PPCRuntimeCompilerStride(param_1)
  int param_1;
{
  ushort uVar1;
  uint *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar3 = *(int *)(param_1 + 0xe24);
  if ((*(int *)(iVar3 + 0x38) == 0x8804) || (*(int *)(iVar3 + 0x38) == 0x8b30)) {
    if (*(int *)(param_1 + 0xe4c) == 0) {
      puVar4 = *(undefined4 **)(param_1 + 0xe30);
      *puVar4 = 0xed8c502a;
      puVar4 = puVar4 + 1;
    }
    else {
      if ((*(uint *)(iVar3 + 0x34) & 4) != 0) {
        puVar4 = *(undefined4 **)(param_1 + 0xe30);
        *puVar4 = 0x10684b2c;
        puVar4[1] = 0x11ce180a;
        *(undefined4 **)(param_1 + 0xe30) = puVar4 + 2;
        if ((*(uint *)(param_1 + 0xe50) & 8) != 0) {
          puVar4[2] = 0x7c6068ce;
          puVar4[3] = 0x7c8060ce;
          puVar4[4] = 0x10a0728c;
          puVar4[5] = 0x10a4196e;
          puVar4[6] = 0x10c0290a;
          puVar4[7] = 0x11ce336a;
          *(undefined4 **)(param_1 + 0xe30) = puVar4 + 8;
        }
        iVar3 = *(int *)(param_1 + 0xe24);
      }
      if ((*(uint *)(iVar3 + 0x34) & 0x1000) == 0) goto LAB_97bdc214;
      puVar4 = *(undefined4 **)(param_1 + 0xe30);
      *puVar4 = 0xed8c502a;
      puVar4[1] = 0xc10d0008;
      puVar4[2] = 0xc12c0008;
      puVar4[3] = 0xeda9433a;
      puVar4 = puVar4 + 4;
    }
    *(undefined4 **)(param_1 + 0xe30) = puVar4;
    iVar3 = *(int *)(param_1 + 0xe24);
  }
  else {
    puVar2 = *(uint **)(param_1 + 0xe30);
    *puVar2 = *(ushort *)(iVar3 + 0xbe) | 0x38e70000;
    iVar3 = *(int *)(param_1 + 0xe24);
    *(uint **)(param_1 + 0xe30) = puVar2 + 1;
  }
LAB_97bdc214:
  if ((*(uint *)(iVar3 + 0x34) & 2) != 0) {
    puVar2 = *(uint **)(param_1 + 0xe30);
    *puVar2 = *(ushort *)(iVar3 + 0xba) | 0x38c60000;
    iVar3 = *(int *)(param_1 + 0xe24);
    *(uint **)(param_1 + 0xe30) = puVar2 + 1;
  }
  if ((*(uint *)(iVar3 + 0x34) & 0x1000) != 0) {
    puVar4 = *(undefined4 **)(param_1 + 0xe30);
    *puVar4 = 0x81e30da8;
    *(undefined4 **)(param_1 + 0xe30) = puVar4 + 1;
    uVar1 = *(ushort *)(*(int *)(param_1 + 0xe24) + 0xda);
    puVar4[2] = 0x91e30da8;
    puVar4[1] = uVar1 | 0x39ef0000;
    iVar3 = *(int *)(param_1 + 0xe24);
    *(undefined4 **)(param_1 + 0xe30) = puVar4 + 3;
  }
  if ((*(uint *)(iVar3 + 0x34) & 0x4000) != 0) {
    puVar4 = *(undefined4 **)(param_1 + 0xe30);
    *puVar4 = 0x81e30dac;
    *(undefined4 **)(param_1 + 0xe30) = puVar4 + 1;
    uVar1 = *(ushort *)(*(int *)(param_1 + 0xe24) + 0xde);
    puVar4[2] = 0x91e30dac;
    puVar4[1] = uVar1 | 0x39ef0000;
    *(undefined4 **)(param_1 + 0xe30) = puVar4 + 3;
  }
  return;
}

/* _PPCRuntimeCompilerLoop @ 0x97bdc2d8 (92 bytes) */
int _PPCRuntimeCompilerLoop(param_1)
  int param_1;
{
  uint uVar1;
  uint *puVar2;
  
  puVar2 = *(uint **)(param_1 + 0xe30);
  uVar1 = (uint)((int)puVar2 - *(int *)(param_1 + 0xe38)) >> 2;
  if (uVar1 < 0x1fff) {
    *puVar2 = uVar1 * -4 & 0xfffc | 0x42000000;
    *(uint **)(param_1 + 0xe30) = puVar2 + 1;
    return;
  }
  *puVar2 = 0x42400008;
  puVar2[1] = (~uVar1 & 0xffffff) << 2 | 0x48000000;
  *(uint **)(param_1 + 0xe30) = puVar2 + 2;
  return;
}

/* _PPCRuntimeCompilerCompileNO @ 0x97bdc334 (5348 bytes) */
int _PPCRuntimeCompilerCompileNO(param_1)
  int param_1;
{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined *puVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  int iVar16;
  undefined4 *puVar17;
  undefined4 uVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  int *piVar22;
  uint *puVar23;
  
  ((int (*)())_PPCRuntimeCompilerInitialise)(param_1,0);
  uVar9 = _glpDCBAlloc(0x2000);
  iVar19 = 0x2000;
  *(undefined4 *)(param_1 + 0xe30) = uVar9;
  *(undefined4 *)(param_1 + 0xe2c) = uVar9;
  ((int (*)())_PPCRuntimeCompilerWritePrologNO)(param_1);
  *(undefined4 *)(param_1 + 0xe48) = 0;
  do {
    iVar6 = *(int *)(param_1 + 0xe48);
    if ((iVar6 != 1) && (iVar6 != 3)) {
      iVar6 = *(int *)(param_1 + 0xe24);
      iVar5 = *(int *)(iVar6 + 0x120);
      *(int *)(param_1 + 0xe28) = iVar5;
      while (iVar5 != 0) {
        puVar23 = *(uint **)(param_1 + 0xe28);
        uVar20 = 1;
        bVar4 = true;
        uVar7 = puVar23[0xc];
        uVar21 = *puVar23;
        cVar1 = *(char *)(puVar23 + 1);
        if (uVar7 != 0) {
          iVar6 = 0;
          do {
            if ((*(char *)((int)puVar23 + iVar6 + 0x48) != '\0') &&
               (uVar8 = (uint)*(byte *)((int)puVar23 + iVar6 + 0x49), uVar20 < uVar8)) {
              uVar20 = uVar8;
            }
            iVar6 = iVar6 + 0x24;
            uVar7 = uVar7 - 1;
          } while (uVar7 != 0);
        }
        if (uVar21 == 0x22) {
          if ((*(int *)(param_1 + 0x380) == 0) &&
             (((uVar3 = *(ushort *)(puVar23 + 7),
               uVar7 = ((int (*)())_PPCRuntimeCompilerGetBaseIndexInRegister)(param_1,0x10), uVar3 != uVar7 ||
               (piVar22 = (int *)puVar23[3],
               iVar6 = ((int (*)())_PPCRuntimeCompilerGetOffsetInRegister)(param_1,0x10), *piVar22 != iVar6)) ||
              (puVar23 = *(uint **)(param_1 + 0xe28), (puVar23[10] & 0x1000000) == 0)))) {
            ((int (*)())_PPCRuntimeCompilerBackupRegister)(param_1,0x10);
            puVar23 = *(uint **)(param_1 + 0xe28);
          }
          if ((*(int *)(param_1 + 0x3b8) == 0) &&
             (((uVar3 = *(ushort *)(puVar23 + 7),
               uVar7 = ((int (*)())_PPCRuntimeCompilerGetBaseIndexInRegister)(param_1,0x11), uVar3 != uVar7 ||
               (uVar7 = puVar23[3], iVar6 = ((int (*)())_PPCRuntimeCompilerGetOffsetInRegister)(param_1,0x11),
               *(int *)(uVar7 + 4) != iVar6)) ||
              (puVar23 = *(uint **)(param_1 + 0xe28), (puVar23[10] & 0x2000000) == 0)))) {
            ((int (*)())_PPCRuntimeCompilerBackupRegister)(param_1,0x11);
            puVar23 = *(uint **)(param_1 + 0xe28);
          }
          if ((*(int *)(param_1 + 0x3f0) == 0) &&
             (((uVar3 = *(ushort *)(puVar23 + 7),
               uVar7 = ((int (*)())_PPCRuntimeCompilerGetBaseIndexInRegister)(param_1,0x12), uVar3 != uVar7 ||
               (uVar7 = puVar23[3], iVar6 = ((int (*)())_PPCRuntimeCompilerGetOffsetInRegister)(param_1,0x12),
               *(int *)(uVar7 + 8) != iVar6)) ||
              (puVar23 = *(uint **)(param_1 + 0xe28), (puVar23[10] & 0x4000000) == 0)))) {
            ((int (*)())_PPCRuntimeCompilerBackupRegister)(param_1,0x12);
            puVar23 = *(uint **)(param_1 + 0xe28);
          }
          if ((*(int *)(param_1 + 0x428) == 0) &&
             (((uVar3 = *(ushort *)(puVar23 + 7),
               uVar7 = ((int (*)())_PPCRuntimeCompilerGetBaseIndexInRegister)(param_1,0x13), uVar3 != uVar7 ||
               (uVar7 = puVar23[3], iVar6 = ((int (*)())_PPCRuntimeCompilerGetOffsetInRegister)(param_1,0x13),
               *(int *)(uVar7 + 0xc) != iVar6)) ||
              (puVar23 = *(uint **)(param_1 + 0xe28), (puVar23[10] & 0x8000000) == 0)))) {
            ((int (*)())_PPCRuntimeCompilerBackupRegister)(param_1,0x13);
            puVar23 = *(uint **)(param_1 + 0xe28);
          }
          if ((*(char *)(puVar23 + 0x12) == '\0') && (*(char *)(puVar23 + 0x1b) == '\0')) {
            ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(param_1,puVar23[0xd],puVar23[0xe],puVar23[0xf],puVar23[0x10],puVar23[0x11],
                       puVar23[0x12],puVar23[0x13]);
            iVar6 = *(int *)(param_1 + 0xe28);
            ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(param_1,*(undefined4 *)(iVar6 + 0x58),*(undefined4 *)(iVar6 + 0x5c),
                       *(undefined4 *)(iVar6 + 0x60),*(undefined4 *)(iVar6 + 100),
                       *(undefined4 *)(iVar6 + 0x68),*(undefined4 *)(iVar6 + 0x6c),
                       *(undefined4 *)(iVar6 + 0x70));
            iVar6 = ((int (*)())_glpRTCAddAChunk)(&_glpOpMultRTC,*(undefined4 *)(param_1 + 0xe30));
            *(int *)(param_1 + 0xe30) = *(int *)(param_1 + 0xe30) + iVar6 * 4;
          }
          else if ((*(char *)(puVar23 + 0x12) == '\0') ||
                  (*(char *)((int)puVar23 + 0x49) != *(char *)((int)puVar23 + 0x6d))) {
            iVar6 = 0;
            if (*(char *)(puVar23 + 0x12) == '\0') {
              if (*(char *)(puVar23 + 0x1b) != '\0') {
                ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(param_1,puVar23[0x16],puVar23[0x17],puVar23[0x18],puVar23[0x19],
                           puVar23[0x1a],puVar23[0x1b],puVar23[0x1c]);
                iVar5 = *(int *)(param_1 + 0xe28);
                iVar6 = 1;
                uVar18 = *(undefined4 *)(iVar5 + 0x4c);
                uVar9 = *(undefined4 *)(iVar5 + 0x34);
                uVar11 = *(undefined4 *)(iVar5 + 0x38);
                uVar12 = *(undefined4 *)(iVar5 + 0x3c);
                uVar13 = *(undefined4 *)(iVar5 + 0x40);
                uVar14 = *(undefined4 *)(iVar5 + 0x44);
                uVar15 = *(undefined4 *)(iVar5 + 0x48);
                goto LAB_97bdc778;
              }
            }
            else {
              ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(param_1,puVar23[0xd],puVar23[0xe],puVar23[0xf],puVar23[0x10],puVar23[0x11],
                         puVar23[0x12],puVar23[0x13]);
              iVar5 = *(int *)(param_1 + 0xe28);
              uVar18 = *(undefined4 *)(iVar5 + 0x70);
              uVar9 = *(undefined4 *)(iVar5 + 0x58);
              uVar11 = *(undefined4 *)(iVar5 + 0x5c);
              uVar12 = *(undefined4 *)(iVar5 + 0x60);
              uVar13 = *(undefined4 *)(iVar5 + 100);
              uVar14 = *(undefined4 *)(iVar5 + 0x68);
              uVar15 = *(undefined4 *)(iVar5 + 0x6c);
LAB_97bdc778:
              ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(param_1,uVar9,uVar11,uVar12,uVar13,uVar14,uVar15,uVar18);
            }
            if (uVar20 == 2) {
              iVar5 = ((int (*)())_glpRTCAddAChunk)(&_glpOpDot4RTC,*(undefined4 *)(param_1 + 0xe30));
              iVar16 = *(int *)(param_1 + 0xe30);
              *(undefined4 *)(iVar16 + iVar5 * 4) = 0xfd008090;
              iVar6 = iVar6 * 0x24 + *(int *)(param_1 + 0xe28);
              *(int *)(param_1 + 0xe30) = iVar16 + iVar5 * 4 + 4;
              ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(param_1,*(undefined4 *)(iVar6 + 0x34),*(undefined4 *)(iVar6 + 0x38),
                         *(undefined4 *)(iVar6 + 0x3c),*(undefined4 *)(iVar6 + 0x40),
                         *(undefined4 *)(iVar6 + 0x44),*(undefined4 *)(iVar6 + 0x48),
                         *(undefined4 *)(iVar6 + 0x4c));
              iVar6 = ((int (*)())_glpRTCAddAChunk)(&_glpOpDot4RTC,*(undefined4 *)(param_1 + 0xe30));
              iVar5 = *(int *)(param_1 + 0xe30);
              iVar6 = iVar6 << 2;
              uVar20 = 0xfe200000;
            }
            else if (uVar20 == 3) {
              iVar5 = ((int (*)())_glpRTCAddAChunk)(&_glpOpDot4RTC,*(undefined4 *)(param_1 + 0xe30));
              iVar16 = *(int *)(param_1 + 0xe30);
              *(undefined4 *)(iVar16 + iVar5 * 4) = 0xfd008090;
              *(int *)(param_1 + 0xe30) = iVar16 + iVar5 * 4 + 4;
              iVar5 = iVar6 * 0x24 + *(int *)(param_1 + 0xe28);
              ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(param_1,*(undefined4 *)(iVar5 + 0x34),*(undefined4 *)(iVar5 + 0x38),
                         *(undefined4 *)(iVar5 + 0x3c),*(undefined4 *)(iVar5 + 0x40),
                         *(undefined4 *)(iVar5 + 0x44),*(undefined4 *)(iVar5 + 0x48),
                         *(undefined4 *)(iVar5 + 0x4c));
              iVar16 = ((int (*)())_glpRTCAddAChunk)(&_glpOpDot4RTC,*(undefined4 *)(param_1 + 0xe30));
              iVar5 = *(int *)(param_1 + 0xe30);
              *(undefined4 *)(iVar5 + iVar16 * 4) = 0xfe208090;
              *(int *)(param_1 + 0xe30) = iVar5 + iVar16 * 4 + 4;
              iVar6 = iVar6 * 0x24 + *(int *)(param_1 + 0xe28);
              ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(param_1,*(undefined4 *)(iVar6 + 0x34),*(undefined4 *)(iVar6 + 0x38),
                         *(undefined4 *)(iVar6 + 0x3c),*(undefined4 *)(iVar6 + 0x40),
                         *(undefined4 *)(iVar6 + 0x44),*(undefined4 *)(iVar6 + 0x48),
                         *(undefined4 *)(iVar6 + 0x4c));
              iVar6 = ((int (*)())_glpRTCAddAChunk)(&_glpOpDot4RTC,*(undefined4 *)(param_1 + 0xe30));
              iVar5 = *(int *)(param_1 + 0xe30);
              iVar6 = iVar6 << 2;
              uVar20 = 0xfe400000;
            }
            else {
              if (uVar20 != 4) goto LAB_97bdcb04;
              iVar6 = iVar6 * 0x24;
              iVar5 = ((int (*)())_glpRTCAddAChunk)(&_glpOpDot4RTC,*(undefined4 *)(param_1 + 0xe30));
              iVar16 = *(int *)(param_1 + 0xe30);
              *(undefined4 *)(iVar16 + iVar5 * 4) = 0xfd008090;
              *(int *)(param_1 + 0xe30) = iVar16 + iVar5 * 4 + 4;
              iVar5 = iVar6 + *(int *)(param_1 + 0xe28);
              ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(param_1,*(undefined4 *)(iVar5 + 0x34),*(undefined4 *)(iVar5 + 0x38),
                         *(undefined4 *)(iVar5 + 0x3c),*(undefined4 *)(iVar5 + 0x40),
                         *(undefined4 *)(iVar5 + 0x44),*(undefined4 *)(iVar5 + 0x48),
                         *(undefined4 *)(iVar5 + 0x4c));
              iVar5 = ((int (*)())_glpRTCAddAChunk)(&_glpOpDot4RTC,*(undefined4 *)(param_1 + 0xe30));
              iVar16 = *(int *)(param_1 + 0xe30);
              *(undefined4 *)(iVar16 + iVar5 * 4) = 0xfe208090;
              *(int *)(param_1 + 0xe30) = iVar16 + iVar5 * 4 + 4;
              iVar5 = iVar6 + *(int *)(param_1 + 0xe28);
              ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(param_1,*(undefined4 *)(iVar5 + 0x34),*(undefined4 *)(iVar5 + 0x38),
                         *(undefined4 *)(iVar5 + 0x3c),*(undefined4 *)(iVar5 + 0x40),
                         *(undefined4 *)(iVar5 + 0x44),*(undefined4 *)(iVar5 + 0x48),
                         *(undefined4 *)(iVar5 + 0x4c));
              iVar16 = ((int (*)())_glpRTCAddAChunk)(&_glpOpDot4RTC,*(undefined4 *)(param_1 + 0xe30));
              iVar5 = *(int *)(param_1 + 0xe30);
              *(undefined4 *)(iVar5 + iVar16 * 4) = 0xfe408090;
              *(int *)(param_1 + 0xe30) = iVar5 + iVar16 * 4 + 4;
              iVar6 = iVar6 + *(int *)(param_1 + 0xe28);
              ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(param_1,*(undefined4 *)(iVar6 + 0x34),*(undefined4 *)(iVar6 + 0x38),
                         *(undefined4 *)(iVar6 + 0x3c),*(undefined4 *)(iVar6 + 0x40),
                         *(undefined4 *)(iVar6 + 0x44),*(undefined4 *)(iVar6 + 0x48),
                         *(undefined4 *)(iVar6 + 0x4c));
              iVar6 = ((int (*)())_glpRTCAddAChunk)(&_glpOpDot4RTC,*(undefined4 *)(param_1 + 0xe30));
              iVar5 = *(int *)(param_1 + 0xe30);
              iVar6 = iVar6 << 2;
              uVar20 = 0xfe600000;
            }
            *(uint *)(iVar5 + iVar6) = uVar20 | 0x8090;
            *(undefined4 *)(iVar5 + iVar6 + 4) = 0xfe004090;
            *(int *)(param_1 + 0xe30) = iVar5 + iVar6 + 8;
          }
LAB_97bdcb04:
          ((int (*)())_PPCRuntimeCompilerWriteDestinationNO)(param_1,0);
        }
        else {
          uVar7 = 0;
          if (uVar20 != 0) {
            do {
              if ((*(int *)(param_1 + 0x380) == 0) &&
                 (((uVar3 = *(ushort *)(puVar23 + 7),
                   uVar8 = ((int (*)())_PPCRuntimeCompilerGetBaseIndexInRegister)(param_1,0x10), uVar3 != uVar8
                   || (piVar22 = (int *)puVar23[3],
                      iVar6 = ((int (*)())_PPCRuntimeCompilerGetOffsetInRegister)(param_1,0x10),
                      *piVar22 != iVar6)) ||
                  (puVar23 = *(uint **)(param_1 + 0xe28), (puVar23[10] & 0x1000000) == 0)))) {
                ((int (*)())_PPCRuntimeCompilerBackupRegister)(param_1,0x10);
                puVar23 = *(uint **)(param_1 + 0xe28);
              }
              if ((*(int *)(param_1 + 0x3b8) == 0) &&
                 (((uVar3 = *(ushort *)(puVar23 + 7),
                   uVar8 = ((int (*)())_PPCRuntimeCompilerGetBaseIndexInRegister)(param_1,0x11), uVar3 != uVar8
                   || (uVar8 = puVar23[3],
                      iVar6 = ((int (*)())_PPCRuntimeCompilerGetOffsetInRegister)(param_1,0x11),
                      *(int *)(uVar8 + 4) != iVar6)) ||
                  (puVar23 = *(uint **)(param_1 + 0xe28), (puVar23[10] & 0x2000000) == 0)))) {
                ((int (*)())_PPCRuntimeCompilerBackupRegister)(param_1,0x11);
                puVar23 = *(uint **)(param_1 + 0xe28);
              }
              if ((*(int *)(param_1 + 0x3f0) == 0) &&
                 (((uVar3 = *(ushort *)(puVar23 + 7),
                   uVar8 = ((int (*)())_PPCRuntimeCompilerGetBaseIndexInRegister)(param_1,0x12), uVar3 != uVar8
                   || (uVar8 = puVar23[3],
                      iVar6 = ((int (*)())_PPCRuntimeCompilerGetOffsetInRegister)(param_1,0x12),
                      *(int *)(uVar8 + 8) != iVar6)) ||
                  (puVar23 = *(uint **)(param_1 + 0xe28), (puVar23[10] & 0x4000000) == 0)))) {
                ((int (*)())_PPCRuntimeCompilerBackupRegister)(param_1,0x12);
                puVar23 = *(uint **)(param_1 + 0xe28);
              }
              if ((*(int *)(param_1 + 0x428) == 0) &&
                 (((uVar3 = *(ushort *)(puVar23 + 7),
                   uVar8 = ((int (*)())_PPCRuntimeCompilerGetBaseIndexInRegister)(param_1,0x13), uVar3 != uVar8
                   || (uVar8 = puVar23[3],
                      iVar6 = ((int (*)())_PPCRuntimeCompilerGetOffsetInRegister)(param_1,0x13),
                      *(int *)(uVar8 + 0xc) != iVar6)) ||
                  (puVar23 = *(uint **)(param_1 + 0xe28), (puVar23[10] & 0x8000000) == 0)))) {
                ((int (*)())_PPCRuntimeCompilerBackupRegister)(param_1,0x13);
                puVar23 = *(uint **)(param_1 + 0xe28);
              }
              uVar8 = 0;
              if (puVar23[0xc] != 0) {
                iVar6 = 0;
                do {
                  uVar8 = uVar8 + 1;
                  ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(param_1,*(undefined4 *)((int)puVar23 + iVar6 + 0x34),
                             *(undefined4 *)((int)puVar23 + iVar6 + 0x38),
                             *(undefined4 *)((int)puVar23 + iVar6 + 0x3c),
                             *(undefined4 *)((int)puVar23 + iVar6 + 0x40),
                             *(undefined4 *)((int)puVar23 + iVar6 + 0x44),
                             *(undefined4 *)((int)puVar23 + iVar6 + 0x48),
                             *(undefined4 *)((int)puVar23 + iVar6 + 0x4c));
                  puVar23 = *(uint **)(param_1 + 0xe28);
                  iVar6 = iVar6 + 0x24;
                } while (uVar8 < puVar23[0xc]);
              }
              if (uVar21 < 0x15) {
                if (((0x12 < uVar21) || (uVar21 == 1)) || ((uVar21 != 0 && (uVar21 - 0x10 < 2)))) {
LAB_97bdcd64:
                  ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,0);
                  ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,1);
                  ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,2);
                  ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,3);
                  ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,4);
                  ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,5);
                  ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,6);
                  ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,7);
                }
              }
              else {
                if (uVar21 == 0x38) goto LAB_97bdcd64;
                if (uVar21 == 0x48) {
                  ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,0);
                  ((int (*)())_PPCRuntimeCompilerDirtyRegistersWithIndirectData)(param_1);
                }
              }
              switch(uVar21) {
              case 0:
                iVar6 = *(int *)(param_1 + 0xe30);
                puVar10 = &_glpOpMovRTC;
                break;
              case 1:
                iVar6 = ((int (*)())_glpRTCAddAChunk)(&_glpOpShuffleSrcRTC,*(undefined4 *)(param_1 + 0xe30));
                iVar6 = *(int *)(param_1 + 0xe30) + iVar6 * 4;
                *(int *)(param_1 + 0xe30) = iVar6;
                iVar6 = ((int (*)())_glpRTCAddAChunk)(&_glpOpLogRTC,iVar6);
                iVar6 = *(int *)(param_1 + 0xe30) + iVar6 * 4;
                *(int *)(param_1 + 0xe30) = iVar6;
                iVar6 = ((int (*)())_glpRTCAddAChunk)(&_glpOpRestoreSrcBRTC,iVar6);
                iVar6 = *(int *)(param_1 + 0xe30) + iVar6 * 4;
                *(int *)(param_1 + 0xe30) = iVar6;
                iVar6 = ((int (*)())_glpRTCAddAChunk)(&_glpOpExpRTC,iVar6);
                iVar6 = *(int *)(param_1 + 0xe30) + iVar6 * 4;
                *(int *)(param_1 + 0xe30) = iVar6;
                puVar10 = &_glpOpShuffleDstRTC;
                break;
              case 2:
                iVar6 = *(int *)(param_1 + 0xe30);
                puVar10 = &_glpOpAbsRTC;
                break;
              default:
                goto switchD_97bdcdfc_caseD_3;
              case 4:
                iVar6 = *(int *)(param_1 + 0xe30);
                puVar10 = &_glpOpFrcRTC;
                break;
              case 5:
                iVar6 = *(int *)(param_1 + 0xe30);
                puVar10 = &_glpOpFlrRTC;
                break;
              case 0xd:
                uVar9 = *(undefined4 *)(param_1 + 0xe30);
                puVar10 = &_glpOpRsqRTC;
                goto LAB_97bdcf9c;
              case 0xe:
                uVar9 = *(undefined4 *)(param_1 + 0xe30);
                puVar10 = &_glpOpRcpRTC;
                goto LAB_97bdcf9c;
              case 0x10:
                iVar6 = *(int *)(param_1 + 0xe30);
                goto LAB_97bdd288;
              case 0x11:
                iVar6 = *(int *)(param_1 + 0xe30);
                puVar10 = &_glpOpExpRTC;
                break;
              case 0x13:
                iVar6 = *(int *)(param_1 + 0xe30);
                puVar10 = &_glpOpLogRTC;
                goto LAB_97bdcfe4;
              case 0x14:
                iVar6 = *(int *)(param_1 + 0xe30);
                puVar10 = &_glpOpLogRTC;
                break;
              case 0x1f:
                iVar6 = *(int *)(param_1 + 0xe30);
                puVar10 = &_glpOpAddRTC;
                break;
              case 0x20:
                iVar6 = *(int *)(param_1 + 0xe30);
                puVar10 = &_glpOpSubRTC;
                break;
              case 0x22:
                iVar6 = *(int *)(param_1 + 0xe30);
                puVar10 = &_glpOpMultRTC;
                break;
              case 0x27:
                bVar2 = *(byte *)(*(int *)(param_1 + 0xe28) + 5);
                if (bVar2 == 2) {
                  uVar9 = *(undefined4 *)(param_1 + 0xe30);
                  puVar10 = &_glpOpDot2RTC;
LAB_97bdd170:
                  iVar6 = ((int (*)())_glpRTCAddAChunk)(puVar10,uVar9);
                  *(int *)(param_1 + 0xe30) = *(int *)(param_1 + 0xe30) + iVar6 * 4;
                }
                else {
                  if (2 < bVar2) {
                    if (bVar2 == 3) {
                      uVar9 = *(undefined4 *)(param_1 + 0xe30);
                      puVar10 = &_glpOpDot3RTC;
                    }
                    else {
                      if (bVar2 != 4) goto LAB_97bdd184;
                      uVar9 = *(undefined4 *)(param_1 + 0xe30);
                      puVar10 = &_glpOpDot4RTC;
                    }
                    goto LAB_97bdd170;
                  }
                  if (bVar2 == 1) {
                    uVar9 = *(undefined4 *)(param_1 + 0xe30);
                    puVar10 = &_glpOpDot1RTC;
                    goto LAB_97bdd170;
                  }
                }
LAB_97bdd184:
                iVar6 = *(int *)(param_1 + 0xe30);
                goto LAB_97bdcfb4;
              case 0x28:
                uVar9 = *(undefined4 *)(param_1 + 0xe30);
                puVar10 = &_glpOpDot3RTC;
                goto LAB_97bdcf9c;
              case 0x29:
                uVar9 = *(undefined4 *)(param_1 + 0xe30);
                puVar10 = &_glpOpDot4RTC;
                goto LAB_97bdcf9c;
              case 0x2a:
                uVar9 = *(undefined4 *)(param_1 + 0xe30);
                puVar10 = &_glpOpDphRTC;
LAB_97bdcf9c:
                iVar6 = ((int (*)())_glpRTCAddAChunk)(puVar10,uVar9);
                iVar6 = *(int *)(param_1 + 0xe30) + iVar6 * 4;
                *(int *)(param_1 + 0xe30) = iVar6;
LAB_97bdcfb4:
                puVar10 = &_glpOpSplatC0RTC;
                break;
              case 0x2b:
                iVar6 = *(int *)(param_1 + 0xe30);
                puVar10 = &_glpOpDistRTC;
                break;
              case 0x2c:
                iVar6 = *(int *)(param_1 + 0xe30);
                puVar10 = &_glpOpMinRTC;
                break;
              case 0x2d:
                iVar6 = *(int *)(param_1 + 0xe30);
                puVar10 = &_glpOpMaxRTC;
                break;
              case 0x2e:
                iVar6 = *(int *)(param_1 + 0xe30);
                puVar10 = &_glpOpXpdRTC;
                break;
              case 0x32:
                iVar6 = *(int *)(param_1 + 0xe30);
                puVar10 = &_glpOpSetGERTC;
                break;
              case 0x35:
                iVar6 = *(int *)(param_1 + 0xe30);
                puVar10 = &_glpOpSetLTRTC;
                break;
              case 0x38:
                iVar6 = ((int (*)())_glpRTCAddAChunk)(&_glpOpSaveSrcBRTC,*(undefined4 *)(param_1 + 0xe30));
                iVar6 = *(int *)(param_1 + 0xe30) + iVar6 * 4;
                *(int *)(param_1 + 0xe30) = iVar6;
                iVar6 = ((int (*)())_glpRTCAddAChunk)(&_glpOpLogRTC,iVar6);
                iVar6 = *(int *)(param_1 + 0xe30) + iVar6 * 4;
                *(int *)(param_1 + 0xe30) = iVar6;
                iVar6 = ((int (*)())_glpRTCAddAChunk)(&_glpOpRestoreSrcBRTC,iVar6);
                iVar6 = *(int *)(param_1 + 0xe30) + iVar6 * 4;
                *(int *)(param_1 + 0xe30) = iVar6;
LAB_97bdd288:
                puVar10 = &_glpOpExpRTC;
LAB_97bdcfe4:
                iVar6 = ((int (*)())_glpRTCAddAChunk)(puVar10,iVar6);
                iVar6 = *(int *)(param_1 + 0xe30) + iVar6 * 4;
                *(int *)(param_1 + 0xe30) = iVar6;
                puVar10 = &_glpOpSplatC2RTC;
                break;
              case 0x3c:
                iVar6 = *(int *)(param_1 + 0xe30);
                puVar10 = &_glpOpLerpRTC;
                break;
              case 0x3e:
                iVar6 = *(int *)(param_1 + 0xe30);
                puVar10 = &_glpOpCmpRTC;
                break;
              case 0x3f:
                iVar6 = *(int *)(param_1 + 0xe30);
                puVar10 = &_glpOpMultAddRTC;
                break;
              case 0x41:
                iVar6 = *(int *)(param_1 + 0xe28);
                switch(*(undefined1 *)(iVar6 + 0x60)) {
                case 0:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  uVar9 = 0xfe000090;
                  break;
                case 1:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  uVar9 = 0xfe000890;
                  break;
                case 2:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  uVar9 = 0xfe001090;
                  break;
                case 3:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  uVar9 = 0xfe001890;
                  break;
                case 4:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  uVar9 = 0xfe000050;
                  break;
                case 5:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  uVar9 = 0xfe000850;
                  break;
                case 6:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  uVar9 = 0xfe001050;
                  break;
                case 7:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  uVar9 = 0xfe001850;
                  break;
                case 8:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  uVar9 = 0xfe005090;
                  break;
                case 9:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  uVar9 = 0xfe005890;
                  break;
                case 10:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  *puVar17 = 0xfe005050;
                  iVar6 = *(int *)(param_1 + 0xe28);
                  *(undefined4 **)(param_1 + 0xe30) = puVar17 + 1;
                default:
                  goto switchD_97bdd2fc_default;
                }
                *puVar17 = uVar9;
                *(undefined4 **)(param_1 + 0xe30) = puVar17 + 1;
                iVar6 = *(int *)(param_1 + 0xe28);
switchD_97bdd2fc_default:
                switch(*(undefined1 *)(iVar6 + 0x61)) {
                case 0:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  uVar9 = 0xfe200090;
                  break;
                case 1:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  uVar9 = 0xfe200890;
                  break;
                case 2:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  uVar9 = 0xfe201090;
                  break;
                case 3:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  uVar9 = 0xfe201890;
                  break;
                case 4:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  uVar9 = 0xfe200050;
                  break;
                case 5:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  uVar9 = 0xfe200850;
                  break;
                case 6:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  uVar9 = 0xfe201050;
                  break;
                case 7:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  uVar9 = 0xfe201850;
                  break;
                case 8:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  uVar9 = 0xfe205090;
                  break;
                case 9:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  uVar9 = 0xfe205890;
                  break;
                case 10:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  *puVar17 = 0xfe205050;
                  iVar6 = *(int *)(param_1 + 0xe28);
                  *(undefined4 **)(param_1 + 0xe30) = puVar17 + 1;
                default:
                  goto switchD_97bdd41c_default;
                }
                *puVar17 = uVar9;
                *(undefined4 **)(param_1 + 0xe30) = puVar17 + 1;
                iVar6 = *(int *)(param_1 + 0xe28);
switchD_97bdd41c_default:
                switch(*(undefined1 *)(iVar6 + 0x62)) {
                case 0:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  uVar9 = 0xfe400090;
                  break;
                case 1:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  uVar9 = 0xfe400890;
                  break;
                case 2:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  uVar9 = 0xfe401090;
                  break;
                case 3:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  uVar9 = 0xfe401890;
                  break;
                case 4:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  uVar9 = 0xfe400050;
                  break;
                case 5:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  uVar9 = 0xfe400850;
                  break;
                case 6:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  uVar9 = 0xfe401050;
                  break;
                case 7:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  uVar9 = 0xfe401850;
                  break;
                case 8:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  uVar9 = 0xfe405090;
                  break;
                case 9:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  uVar9 = 0xfe405890;
                  break;
                case 10:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  *puVar17 = 0xfe405050;
                  iVar6 = *(int *)(param_1 + 0xe28);
                  *(undefined4 **)(param_1 + 0xe30) = puVar17 + 1;
                default:
                  goto switchD_97bdd53c_default;
                }
                *puVar17 = uVar9;
                *(undefined4 **)(param_1 + 0xe30) = puVar17 + 1;
                iVar6 = *(int *)(param_1 + 0xe28);
switchD_97bdd53c_default:
                switch(*(undefined1 *)(iVar6 + 99)) {
                case 0:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  uVar9 = 0xfe600090;
                  break;
                case 1:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  uVar9 = 0xfe600890;
                  break;
                case 2:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  uVar9 = 0xfe601090;
                  break;
                case 3:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  uVar9 = 0xfe601890;
                  break;
                case 4:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  uVar9 = 0xfe600050;
                  break;
                case 5:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  uVar9 = 0xfe600850;
                  break;
                case 6:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  uVar9 = 0xfe601050;
                  break;
                case 7:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  uVar9 = 0xfe601850;
                  break;
                case 8:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  uVar9 = 0xfe605090;
                  break;
                case 9:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  uVar9 = 0xfe605890;
                  break;
                case 10:
                  puVar17 = *(undefined4 **)(param_1 + 0xe30);
                  uVar9 = 0xfe605050;
                  break;
                default:
                  goto switchD_97bdcdfc_caseD_3;
                }
                *puVar17 = uVar9;
                *(undefined4 **)(param_1 + 0xe30) = puVar17 + 1;
                goto switchD_97bdcdfc_caseD_3;
              case 0x42:
                iVar6 = *(int *)(param_1 + 0xe20);
                if (*(int *)(*(int *)(iVar6 + 0xd80) + 0x38) - 0x8b30U < 2) {
                  uVar9 = *(undefined4 *)
                           (*(int *)((uint)*(ushort *)(*(int *)(param_1 + 0xe28) + 0x68) * 4 + iVar6
                                    + 0xd84) + **(int **)(*(int *)(param_1 + 0xe28) + 0x58));
                }
                else {
                  uVar9 = *(undefined4 *)(*(int *)(param_1 + 0xe28) + 0x10c);
                }
                ((int (*)())_PPCTextureSamplerAttachGLDContext)(*(undefined4 *)(param_1 + 0xe1c),*(undefined4 *)(iVar6 + 0xd9c));
                iVar6 = *(int *)(*(int *)(param_1 + 0xe28) + 0x110);
                if (iVar6 == 2) {
                  uVar9 = _PPCTextureSamplerSampleTexelRECTRTCNO
                                    (*(undefined4 *)(param_1 + 0xe1c),uVar9,
                                     *(undefined4 *)(param_1 + 0xe30));
                }
                else {
                  if (iVar6 != 3) goto switchD_97bdcdfc_caseD_3;
                  uVar9 = ((int (*)())_PPCTextureSamplerSampleTexel2DRTCNO)(*(undefined4 *)(param_1 + 0xe1c),uVar9,
                                     *(undefined4 *)(param_1 + 0xe30));
                }
                *(undefined4 *)(param_1 + 0xe30) = uVar9;
                goto switchD_97bdcdfc_caseD_3;
              case 0x48:
                if ((*(byte *)(*(int *)(param_1 + 0xe28) + 0x28) & 1) != 0) {
                  iVar6 = ((int (*)())_glpRTCAddAChunk)(&_glpOpArlRTC,*(undefined4 *)(param_1 + 0xe30));
                  *(int *)(param_1 + 0xe30) = *(int *)(param_1 + 0xe30) + iVar6 * 4;
                }
              case 0x49:
              case 0x4a:
              case 0x4b:
              case 0x4c:
              case 0x4d:
              case 0x4f:
              case 0x55:
              case 0x56:
              case 0x57:
              case 0x58:
              case 0x59:
              case 0x5a:
                bVar4 = false;
                goto LAB_97bdd85c;
              case 0x5b:
                bVar4 = false;
                goto switchD_97bdcdfc_caseD_3;
              }
              iVar6 = ((int (*)())_glpRTCAddAChunk)(puVar10,iVar6);
              *(int *)(param_1 + 0xe30) = *(int *)(param_1 + 0xe30) + iVar6 * 4;
switchD_97bdcdfc_caseD_3:
              if (bVar4) {
                if (cVar1 != '\0') {
                  iVar6 = ((int (*)())_glpRTCAddAChunk)(&_glpOpSaturateRTC,*(undefined4 *)(param_1 + 0xe30));
                  *(int *)(param_1 + 0xe30) = *(int *)(param_1 + 0xe30) + iVar6 * 4;
                }
                ((int (*)())_PPCRuntimeCompilerWriteDestinationNO)(param_1,uVar7);
              }
LAB_97bdd85c:
              uVar7 = uVar7 + 1;
              if (uVar20 <= uVar7) break;
              puVar23 = *(uint **)(param_1 + 0xe28);
            } while( true );
          }
          iVar6 = *(int *)(param_1 + 0xe2c);
          if (iVar19 - 2000U < (uint)(*(int *)(param_1 + 0xe30) - iVar6)) {
            iVar19 = iVar19 + 0x2000;
            iVar5 = _glpDCBRealloc(iVar6,iVar19);
            *(int *)(param_1 + 0xe2c) = iVar5;
            iVar6 = iVar5 - iVar6 >> 2;
            if (iVar6 != 0) {
              iVar6 = iVar6 * 4;
              *(int *)(param_1 + 0xe30) = *(int *)(param_1 + 0xe30) + iVar6;
              *(int *)(param_1 + 0xe34) = *(int *)(param_1 + 0xe34) + iVar6;
              *(int *)(param_1 + 0xe38) = *(int *)(param_1 + 0xe38) + iVar6;
              *(int *)(param_1 + 0xe3c) = *(int *)(param_1 + 0xe3c) + iVar6;
              *(int *)(param_1 + 0xe40) = *(int *)(param_1 + 0xe40) + iVar6;
            }
          }
        }
        iVar6 = *(int *)(param_1 + 0xe24);
        iVar5 = *(int *)(param_1 + 0xe28) + 0x11c;
        if (*(int *)(param_1 + 0xe28) == *(int *)(iVar6 + 4)) {
          iVar5 = 0;
        }
        *(int *)(param_1 + 0xe28) = iVar5;
      }
      if ((*(int *)(iVar6 + 0x38) != 0x8804) && (*(int *)(iVar6 + 0x38) != 0x8b30)) {
        puVar17 = *(undefined4 **)(param_1 + 0xe30);
        *puVar17 = 0xc0060010;
        puVar17[1] = 0xc0260014;
        puVar17[2] = 0xc0460018;
        puVar17[3] = 0xc066001c;
        *(undefined4 **)(param_1 + 0xe30) = puVar17 + 4;
        iVar6 = ((int (*)())_glpRTCAddAChunk)(&_glpOpClippingRTC);
        *(int *)(param_1 + 0xe30) = *(int *)(param_1 + 0xe30) + iVar6 * 4;
      }
      iVar6 = *(int *)(param_1 + 0xe48);
      if (iVar6 == 0) {
        ((int (*)())_PPCRuntimeCompilerDirtyRegistersContainingAttributes)(param_1);
        ((int (*)())_PPCRuntimeCompilerDirtyRegistersContainingTemps)(param_1);
        ((int (*)())_PPCRuntimeCompilerDirtyRegistersContainingParams)(param_1);
        iVar6 = *(int *)(param_1 + 0xe48);
        *(undefined4 *)(param_1 + 0xe38) = *(undefined4 *)(param_1 + 0xe30);
      }
      else if (iVar6 == 2) {
        ((int (*)())_PPCRuntimeCompilerStride)(param_1);
        ((int (*)())_PPCRuntimeCompilerLoop)(param_1);
        iVar6 = *(int *)(param_1 + 0xe48);
      }
    }
    *(uint *)(param_1 + 0xe48) = iVar6 + 1U;
    if (3 < iVar6 + 1U) {
      ((int (*)())_PPCRuntimeCompilerWriteEpilogNO)(param_1);
      iVar19 = *(int *)(param_1 + 0xe30) - *(int *)(param_1 + 0xe2c) >> 2;
      uVar9 = _glpDCBRealloc(*(int *)(param_1 + 0xe2c),iVar19 << 2);
      *(undefined4 *)(param_1 + 0xe2c) = uVar9;
                    
                    
      (*_glpPushInstructions)(iVar19,uVar9);
      return;
    }
  } while( true );
}

/* _PPCRuntimeCompilerCompileAV @ 0x97bdda38 (15728 bytes) */
int _PPCRuntimeCompilerCompileAV(param_1)
  int param_1;
{
  bool bVar1;
  char cVar2;
  byte bVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  uint uVar10;
  uint *puVar11;
  uint *puVar12;
  undefined4 uVar13;
  undefined *puVar14;
  undefined4 uVar15;
  undefined4 *puVar16;
  int iVar17;
  undefined4 *puVar18;
  uint uVar19;
  uint uVar20;
  int iVar21;
  uint uVar22;
  uint uVar23;
  
  ((int (*)())_PPCRuntimeCompilerInitialise)(param_1,1);
  uVar13 = _glpDCBAlloc(0x2000);
  iVar21 = 0x2000;
  *(undefined4 *)(param_1 + 0xe30) = uVar13;
  *(undefined4 *)(param_1 + 0xe2c) = uVar13;
  ((int (*)())_PPCRuntimeCompilerWritePrologAV)(param_1);
  *(undefined4 *)(param_1 + 0xe34) = *(undefined4 *)(param_1 + 0xe30);
  *(undefined4 *)(param_1 + 0xe48) = 0;
  do {
    if (((1 < *(uint *)(param_1 + 0xe48)) &&
        (iVar7 = *(int *)(*(int *)(param_1 + 0xe20) + 0xd80), (*(uint *)(iVar7 + 0x3c) & 6) == 4))
       && ((*(uint *)(iVar7 + 0x34) & 0xa000) == 0)) {
      uVar13 = _PPCRasterOpMachine_DepthTestRTCAV(param_1 + 0xe14,*(undefined4 *)(param_1 + 0xe30));
      *(undefined4 *)(param_1 + 0xe30) = uVar13;
    }
    iVar7 = *(int *)(param_1 + 0xe24);
    iVar5 = *(int *)(iVar7 + 0x120);
    *(int *)(param_1 + 0xe28) = iVar5;
    while (iVar5 != 0) {
      uVar22 = 1;
      bVar4 = true;
      piVar8 = *(int **)(param_1 + 0xe28);
      piVar8[0x46] = *(int *)(param_1 + 0xe30) - *(int *)(param_1 + 0xe2c);
      iVar5 = *piVar8;
      iVar7 = *(int *)(*(int *)(param_1 + 0xe28) + 0x30);
      cVar2 = *(char *)(piVar8 + 1);
      if (iVar7 != 0) {
        iVar17 = 0;
        do {
          iVar9 = iVar17 + *(int *)(param_1 + 0xe28);
          if ((*(char *)(iVar9 + 0x48) != '\0') &&
             (uVar10 = (uint)*(byte *)(iVar9 + 0x49), uVar22 < uVar10)) {
            uVar22 = uVar10;
          }
          iVar17 = iVar17 + 0x24;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      if (iVar5 == 0x22) {
        ((int (*)())_PPCRuntimeCompilerBackupRegister)(param_1,2);
        ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,2);
        iVar17 = *(int *)(param_1 + 0xe28);
        if ((*(char *)(iVar17 + 0x48) == '\0') && (*(char *)(iVar17 + 0x6c) == '\0')) {
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar17 + 0x34),*(undefined4 *)(iVar17 + 0x38),
                     *(undefined4 *)(iVar17 + 0x3c),*(undefined4 *)(iVar17 + 0x40),
                     *(undefined4 *)(iVar17 + 0x44),*(undefined4 *)(iVar17 + 0x48),
                     *(undefined4 *)(iVar17 + 0x4c));
          iVar7 = *(int *)(param_1 + 0xe28);
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x58),*(undefined4 *)(iVar7 + 0x5c),
                     *(undefined4 *)(iVar7 + 0x60),*(undefined4 *)(iVar7 + 100),
                     *(undefined4 *)(iVar7 + 0x68),*(undefined4 *)(iVar7 + 0x6c),
                     *(undefined4 *)(iVar7 + 0x70));
          iVar7 = ((int (*)())_glpRTCAddAChunk)(&_glpOpMulAVRTC,*(undefined4 *)(param_1 + 0xe30));
          *(int *)(param_1 + 0xe30) = *(int *)(param_1 + 0xe30) + iVar7 * 4;
          if (cVar2 != '\0') {
            iVar7 = ((int (*)())_glpRTCAddAChunk)(&_glpOpSaturateAVRTC);
            *(int *)(param_1 + 0xe30) = *(int *)(param_1 + 0xe30) + iVar7 * 4;
          }
LAB_97bdde9c:
          uVar13 = 0;
LAB_97bddea4:
          ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(param_1,uVar13);
          goto LAB_97be18e4;
        }
        if (((*(char *)(iVar17 + 0x48) == '\0') || (*(char *)(iVar17 + 0x6c) == '\0')) ||
           (*(char *)(iVar17 + 0x49) != *(char *)(iVar17 + 0x6d))) {
          if ((*(char *)(iVar17 + 0x48) != '\0') && (1 < *(byte *)(iVar17 + 0x6d))) {
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar17 + 0x34),*(undefined4 *)(iVar17 + 0x38),
                       *(undefined4 *)(iVar17 + 0x3c),*(undefined4 *)(iVar17 + 0x40),
                       *(undefined4 *)(iVar17 + 0x44),*(undefined4 *)(iVar17 + 0x48),
                       *(undefined4 *)(iVar17 + 0x4c));
            iVar7 = *(int *)(param_1 + 0xe28);
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x58),*(undefined4 *)(iVar7 + 0x5c),
                       *(undefined4 *)(iVar7 + 0x60),*(undefined4 *)(iVar7 + 100),
                       *(undefined4 *)(iVar7 + 0x68),*(undefined4 *)(iVar7 + 0x6c),
                       *(undefined4 *)(iVar7 + 0x70));
            if (uVar22 == 2) {
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              *puVar16 = 0x10a0028c;
              puVar16[1] = 0x1045386e;
              iVar7 = *(int *)(param_1 + 0xe28);
              *(undefined4 **)(param_1 + 0xe30) = puVar16 + 2;
              ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x34),*(undefined4 *)(iVar7 + 0x38),
                         *(undefined4 *)(iVar7 + 0x3c),*(undefined4 *)(iVar7 + 0x40),
                         *(undefined4 *)(iVar7 + 0x44),*(undefined4 *)(iVar7 + 0x48),
                         *(undefined4 *)(iVar7 + 0x4c));
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              *puVar16 = 0x10a1028c;
              puVar11 = puVar16 + 1;
              *puVar11 = 0x1045106e;
            }
            else {
              if (uVar22 == 3) {
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                *puVar16 = 0x10a0028c;
                puVar16[1] = 0x1045386e;
                iVar7 = *(int *)(param_1 + 0xe28);
                *(undefined4 **)(param_1 + 0xe30) = puVar16 + 2;
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x34),*(undefined4 *)(iVar7 + 0x38),
                           *(undefined4 *)(iVar7 + 0x3c),*(undefined4 *)(iVar7 + 0x40),
                           *(undefined4 *)(iVar7 + 0x44),*(undefined4 *)(iVar7 + 0x48),
                           *(undefined4 *)(iVar7 + 0x4c));
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                *puVar16 = 0x10a1028c;
                puVar16[1] = 0x1045106e;
                iVar7 = *(int *)(param_1 + 0xe28);
                *(undefined4 **)(param_1 + 0xe30) = puVar16 + 2;
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x34),*(undefined4 *)(iVar7 + 0x38),
                           *(undefined4 *)(iVar7 + 0x3c),*(undefined4 *)(iVar7 + 0x40),
                           *(undefined4 *)(iVar7 + 0x44),*(undefined4 *)(iVar7 + 0x48),
                           *(undefined4 *)(iVar7 + 0x4c));
                puVar11 = *(uint **)(param_1 + 0xe30);
                uVar22 = 0x10a20000;
              }
              else {
                if (uVar22 != 4) goto LAB_97bdde9c;
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                *puVar16 = 0x10a0028c;
                puVar16[1] = 0x1045386e;
                iVar7 = *(int *)(param_1 + 0xe28);
                *(undefined4 **)(param_1 + 0xe30) = puVar16 + 2;
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x34),*(undefined4 *)(iVar7 + 0x38),
                           *(undefined4 *)(iVar7 + 0x3c),*(undefined4 *)(iVar7 + 0x40),
                           *(undefined4 *)(iVar7 + 0x44),*(undefined4 *)(iVar7 + 0x48),
                           *(undefined4 *)(iVar7 + 0x4c));
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                *puVar16 = 0x10a1028c;
                puVar16[1] = 0x1045106e;
                iVar7 = *(int *)(param_1 + 0xe28);
                *(undefined4 **)(param_1 + 0xe30) = puVar16 + 2;
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x34),*(undefined4 *)(iVar7 + 0x38),
                           *(undefined4 *)(iVar7 + 0x3c),*(undefined4 *)(iVar7 + 0x40),
                           *(undefined4 *)(iVar7 + 0x44),*(undefined4 *)(iVar7 + 0x48),
                           *(undefined4 *)(iVar7 + 0x4c));
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                *puVar16 = 0x10a2028c;
                puVar16[1] = 0x1045106e;
                iVar7 = *(int *)(param_1 + 0xe28);
                *(undefined4 **)(param_1 + 0xe30) = puVar16 + 2;
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x34),*(undefined4 *)(iVar7 + 0x38),
                           *(undefined4 *)(iVar7 + 0x3c),*(undefined4 *)(iVar7 + 0x40),
                           *(undefined4 *)(iVar7 + 0x44),*(undefined4 *)(iVar7 + 0x48),
                           *(undefined4 *)(iVar7 + 0x4c));
                puVar11 = *(uint **)(param_1 + 0xe30);
                uVar22 = 0x10a30000;
              }
              *puVar11 = uVar22 | 0x28c;
              puVar11 = puVar11 + 1;
              *puVar11 = 0x1045106e;
            }
            goto LAB_97bdde94;
          }
          if ((*(char *)(iVar17 + 0x6c) != '\0') && (1 < *(byte *)(iVar17 + 0x49))) {
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar17 + 0x58),*(undefined4 *)(iVar17 + 0x5c),
                       *(undefined4 *)(iVar17 + 0x60),*(undefined4 *)(iVar17 + 100),
                       *(undefined4 *)(iVar17 + 0x68),*(undefined4 *)(iVar17 + 0x6c),
                       *(undefined4 *)(iVar17 + 0x70));
            iVar7 = *(int *)(param_1 + 0xe28);
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x34),*(undefined4 *)(iVar7 + 0x38),
                       *(undefined4 *)(iVar7 + 0x3c),*(undefined4 *)(iVar7 + 0x40),
                       *(undefined4 *)(iVar7 + 0x44),*(undefined4 *)(iVar7 + 0x48),
                       *(undefined4 *)(iVar7 + 0x4c));
            if (uVar22 == 2) {
              iVar5 = ((int (*)())_glpRTCAddAChunk)(&_glpOpDp2AVRTC,*(undefined4 *)(param_1 + 0xe30));
              iVar17 = *(int *)(param_1 + 0xe30);
              *(undefined4 *)(iVar17 + iVar5 * 4) = 0x10a5112c;
              iVar7 = *(int *)(param_1 + 0xe28);
              *(int *)(param_1 + 0xe30) = iVar17 + iVar5 * 4 + 4;
              ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x58),*(undefined4 *)(iVar7 + 0x5c),
                         *(undefined4 *)(iVar7 + 0x60),*(undefined4 *)(iVar7 + 100),
                         *(undefined4 *)(iVar7 + 0x68),*(undefined4 *)(iVar7 + 0x6c),
                         *(undefined4 *)(iVar7 + 0x70));
              iVar7 = ((int (*)())_glpRTCAddAChunk)(&_glpOpDp2AVRTC,*(undefined4 *)(param_1 + 0xe30));
              iVar17 = *(int *)(param_1 + 0xe30);
              iVar7 = iVar7 * 4;
              iVar5 = iVar17 + iVar7;
              uVar13 = 0x10a5132c;
LAB_97bdeef0:
              *(undefined4 *)(iVar17 + iVar7) = uVar13;
              *(undefined4 *)(iVar5 + 4) = 0x10452c84;
            }
            else {
              if (uVar22 == 3) {
                iVar5 = ((int (*)())_glpRTCAddAChunk)(&_glpOpDp3AVRTC,*(undefined4 *)(param_1 + 0xe30));
                iVar17 = *(int *)(param_1 + 0xe30);
                *(undefined4 *)(iVar17 + iVar5 * 4) = 0x10a5112c;
                iVar7 = *(int *)(param_1 + 0xe28);
                *(int *)(param_1 + 0xe30) = iVar17 + iVar5 * 4 + 4;
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x58),*(undefined4 *)(iVar7 + 0x5c),
                           *(undefined4 *)(iVar7 + 0x60),*(undefined4 *)(iVar7 + 100),
                           *(undefined4 *)(iVar7 + 0x68),*(undefined4 *)(iVar7 + 0x6c),
                           *(undefined4 *)(iVar7 + 0x70));
                iVar5 = ((int (*)())_glpRTCAddAChunk)(&_glpOpDp3AVRTC,*(undefined4 *)(param_1 + 0xe30));
                iVar7 = *(int *)(param_1 + 0xe30);
                *(undefined4 *)(iVar7 + iVar5 * 4) = 0x10a5112c;
                iVar17 = *(int *)(param_1 + 0xe28);
                *(int *)(param_1 + 0xe30) = iVar7 + iVar5 * 4 + 4;
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar17 + 0x58),*(undefined4 *)(iVar17 + 0x5c),
                           *(undefined4 *)(iVar17 + 0x60),*(undefined4 *)(iVar17 + 100),
                           *(undefined4 *)(iVar17 + 0x68),*(undefined4 *)(iVar17 + 0x6c),
                           *(undefined4 *)(iVar17 + 0x70));
                iVar7 = ((int (*)())_glpRTCAddAChunk)(&_glpOpDp3AVRTC,*(undefined4 *)(param_1 + 0xe30));
                iVar17 = *(int *)(param_1 + 0xe30);
                iVar7 = iVar7 * 4;
                iVar5 = iVar17 + iVar7;
                uVar13 = 0x10a5122c;
                goto LAB_97bdeef0;
              }
              if (uVar22 != 4) goto LAB_97bdde9c;
              iVar5 = ((int (*)())_glpRTCAddAChunk)(&_glpOpDp4AVRTC,*(undefined4 *)(param_1 + 0xe30));
              iVar17 = *(int *)(param_1 + 0xe30);
              *(undefined4 *)(iVar17 + iVar5 * 4) = 0x10a5112c;
              iVar7 = *(int *)(param_1 + 0xe28);
              *(int *)(param_1 + 0xe30) = iVar17 + iVar5 * 4 + 4;
              ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x58),*(undefined4 *)(iVar7 + 0x5c),
                         *(undefined4 *)(iVar7 + 0x60),*(undefined4 *)(iVar7 + 100),
                         *(undefined4 *)(iVar7 + 0x68),*(undefined4 *)(iVar7 + 0x6c),
                         *(undefined4 *)(iVar7 + 0x70));
              iVar5 = ((int (*)())_glpRTCAddAChunk)(&_glpOpDp4AVRTC,*(undefined4 *)(param_1 + 0xe30));
              iVar7 = *(int *)(param_1 + 0xe30);
              *(undefined4 *)(iVar7 + iVar5 * 4) = 0x10a5112c;
              iVar17 = *(int *)(param_1 + 0xe28);
              *(int *)(param_1 + 0xe30) = iVar7 + iVar5 * 4 + 4;
              ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar17 + 0x58),*(undefined4 *)(iVar17 + 0x5c),
                         *(undefined4 *)(iVar17 + 0x60),*(undefined4 *)(iVar17 + 100),
                         *(undefined4 *)(iVar17 + 0x68),*(undefined4 *)(iVar17 + 0x6c),
                         *(undefined4 *)(iVar17 + 0x70));
              iVar5 = ((int (*)())_glpRTCAddAChunk)(&_glpOpDp4AVRTC,*(undefined4 *)(param_1 + 0xe30));
              iVar7 = *(int *)(param_1 + 0xe30);
              *(undefined4 *)(iVar7 + iVar5 * 4) = 0x10a5112c;
              iVar17 = *(int *)(param_1 + 0xe28);
              *(int *)(param_1 + 0xe30) = iVar7 + iVar5 * 4 + 4;
              ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar17 + 0x58),*(undefined4 *)(iVar17 + 0x5c),
                         *(undefined4 *)(iVar17 + 0x60),*(undefined4 *)(iVar17 + 100),
                         *(undefined4 *)(iVar17 + 0x68),*(undefined4 *)(iVar17 + 0x6c),
                         *(undefined4 *)(iVar17 + 0x70));
              iVar7 = ((int (*)())_glpRTCAddAChunk)(&_glpOpDp4AVRTC,*(undefined4 *)(param_1 + 0xe30));
              iVar5 = *(int *)(param_1 + 0xe30) + iVar7 * 4;
              *(undefined4 *)(*(int *)(param_1 + 0xe30) + iVar7 * 4) = 0x10a5112c;
              *(undefined4 *)(iVar5 + 4) = 0x10452c84;
            }
            *(int *)(param_1 + 0xe30) = iVar5 + 8;
            goto LAB_97bdde9c;
          }
          uVar10 = (uint)(*(char *)(iVar17 + 0x48) == '\0');
          if (uVar10 == 0) {
            iVar7 = 0x54;
          }
          else {
            iVar7 = 0x30;
          }
          iVar17 = iVar17 + iVar7;
          iVar5 = uVar10 * 0x24;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar17 + 4),*(undefined4 *)(iVar17 + 8),
                     *(undefined4 *)(iVar17 + 0xc),*(undefined4 *)(iVar17 + 0x10),
                     *(undefined4 *)(iVar17 + 0x14),*(undefined4 *)(iVar17 + 0x18),
                     *(undefined4 *)(iVar17 + 0x1c));
          iVar7 = iVar5 + *(int *)(param_1 + 0xe28);
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x34),*(undefined4 *)(iVar7 + 0x38),
                     *(undefined4 *)(iVar7 + 0x3c),*(undefined4 *)(iVar7 + 0x40),
                     *(undefined4 *)(iVar7 + 0x44),*(undefined4 *)(iVar7 + 0x48),
                     *(undefined4 *)(iVar7 + 0x4c));
          if (uVar22 == 2) {
            puVar16 = *(undefined4 **)(param_1 + 0xe30);
            *puVar16 = 0x1040386e;
            *(undefined4 **)(param_1 + 0xe30) = puVar16 + 1;
            ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(param_1,0);
            ((int (*)())_PPCRuntimeCompilerBackupRegister)(param_1,2);
            ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,2);
            iVar5 = iVar5 + *(int *)(param_1 + 0xe28);
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar5 + 0x34),*(undefined4 *)(iVar5 + 0x38),
                       *(undefined4 *)(iVar5 + 0x3c),*(undefined4 *)(iVar5 + 0x40),
                       *(undefined4 *)(iVar5 + 0x44),*(undefined4 *)(iVar5 + 0x48),
                       *(undefined4 *)(iVar5 + 0x4c));
            puVar16 = *(undefined4 **)(param_1 + 0xe30);
            uVar13 = 1;
          }
          else if (uVar22 == 3) {
            puVar16 = *(undefined4 **)(param_1 + 0xe30);
            *puVar16 = 0x1040386e;
            *(undefined4 **)(param_1 + 0xe30) = puVar16 + 1;
            ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(param_1,0);
            ((int (*)())_PPCRuntimeCompilerBackupRegister)(param_1,2);
            ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,2);
            iVar7 = iVar5 + *(int *)(param_1 + 0xe28);
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x34),*(undefined4 *)(iVar7 + 0x38),
                       *(undefined4 *)(iVar7 + 0x3c),*(undefined4 *)(iVar7 + 0x40),
                       *(undefined4 *)(iVar7 + 0x44),*(undefined4 *)(iVar7 + 0x48),
                       *(undefined4 *)(iVar7 + 0x4c));
            puVar16 = *(undefined4 **)(param_1 + 0xe30);
            *puVar16 = 0x1040386e;
            *(undefined4 **)(param_1 + 0xe30) = puVar16 + 1;
            ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(param_1,1);
            ((int (*)())_PPCRuntimeCompilerBackupRegister)(param_1,2);
            ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,2);
            iVar5 = iVar5 + *(int *)(param_1 + 0xe28);
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar5 + 0x34),*(undefined4 *)(iVar5 + 0x38),
                       *(undefined4 *)(iVar5 + 0x3c),*(undefined4 *)(iVar5 + 0x40),
                       *(undefined4 *)(iVar5 + 0x44),*(undefined4 *)(iVar5 + 0x48),
                       *(undefined4 *)(iVar5 + 0x4c));
            puVar16 = *(undefined4 **)(param_1 + 0xe30);
            uVar13 = 2;
          }
          else {
            if (uVar22 != 4) goto LAB_97be18e4;
            puVar16 = *(undefined4 **)(param_1 + 0xe30);
            *puVar16 = 0x1040386e;
            *(undefined4 **)(param_1 + 0xe30) = puVar16 + 1;
            ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(param_1,0);
            ((int (*)())_PPCRuntimeCompilerBackupRegister)(param_1,2);
            ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,2);
            iVar7 = iVar5 + *(int *)(param_1 + 0xe28);
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x34),*(undefined4 *)(iVar7 + 0x38),
                       *(undefined4 *)(iVar7 + 0x3c),*(undefined4 *)(iVar7 + 0x40),
                       *(undefined4 *)(iVar7 + 0x44),*(undefined4 *)(iVar7 + 0x48),
                       *(undefined4 *)(iVar7 + 0x4c));
            puVar16 = *(undefined4 **)(param_1 + 0xe30);
            *puVar16 = 0x1040386e;
            *(undefined4 **)(param_1 + 0xe30) = puVar16 + 1;
            ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(param_1,1);
            ((int (*)())_PPCRuntimeCompilerBackupRegister)(param_1,2);
            ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,2);
            iVar7 = iVar5 + *(int *)(param_1 + 0xe28);
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x34),*(undefined4 *)(iVar7 + 0x38),
                       *(undefined4 *)(iVar7 + 0x3c),*(undefined4 *)(iVar7 + 0x40),
                       *(undefined4 *)(iVar7 + 0x44),*(undefined4 *)(iVar7 + 0x48),
                       *(undefined4 *)(iVar7 + 0x4c));
            puVar16 = *(undefined4 **)(param_1 + 0xe30);
            *puVar16 = 0x1040386e;
            *(undefined4 **)(param_1 + 0xe30) = puVar16 + 1;
            ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(param_1,2);
            ((int (*)())_PPCRuntimeCompilerBackupRegister)(param_1,2);
            ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,2);
            iVar5 = iVar5 + *(int *)(param_1 + 0xe28);
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar5 + 0x34),*(undefined4 *)(iVar5 + 0x38),
                       *(undefined4 *)(iVar5 + 0x3c),*(undefined4 *)(iVar5 + 0x40),
                       *(undefined4 *)(iVar5 + 0x44),*(undefined4 *)(iVar5 + 0x48),
                       *(undefined4 *)(iVar5 + 0x4c));
            puVar16 = *(undefined4 **)(param_1 + 0xe30);
            uVar13 = 3;
          }
          *puVar16 = 0x1040386e;
          *(undefined4 **)(param_1 + 0xe30) = puVar16 + 1;
          goto LAB_97bddea4;
        }
        if (uVar22 == 2) {
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar17 + 0x34),*(undefined4 *)(iVar17 + 0x38),
                     *(undefined4 *)(iVar17 + 0x3c),*(undefined4 *)(iVar17 + 0x40),
                     *(undefined4 *)(iVar17 + 0x44),*(undefined4 *)(iVar17 + 0x48),
                     *(undefined4 *)(iVar17 + 0x4c));
          iVar7 = *(int *)(param_1 + 0xe28);
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x58),*(undefined4 *)(iVar7 + 0x5c),
                     *(undefined4 *)(iVar7 + 0x60),*(undefined4 *)(iVar7 + 100),
                     *(undefined4 *)(iVar7 + 0x68),*(undefined4 *)(iVar7 + 0x6c),
                     *(undefined4 *)(iVar7 + 0x70));
          puVar16 = *(undefined4 **)(param_1 + 0xe30);
          *puVar16 = 0x10c00a8c;
          puVar16[1] = 0x104039ae;
          iVar7 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar16 + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x34),*(undefined4 *)(iVar7 + 0x38),
                     *(undefined4 *)(iVar7 + 0x3c),*(undefined4 *)(iVar7 + 0x40),
                     *(undefined4 *)(iVar7 + 0x44),*(undefined4 *)(iVar7 + 0x48),
                     *(undefined4 *)(iVar7 + 0x4c));
          puVar16 = *(undefined4 **)(param_1 + 0xe30);
          *puVar16 = 0x10c10a8c;
          puVar16[1] = 0x104011ae;
          puVar16[2] = 0x3b000210;
          puVar16[3] = 0x7c43c1ce;
          iVar7 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar16 + 4;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x58),*(undefined4 *)(iVar7 + 0x5c),
                     *(undefined4 *)(iVar7 + 0x60),*(undefined4 *)(iVar7 + 100),
                     *(undefined4 *)(iVar7 + 0x68),*(undefined4 *)(iVar7 + 0x6c),
                     *(undefined4 *)(iVar7 + 0x70));
          puVar16 = *(undefined4 **)(param_1 + 0xe30);
          *puVar16 = 0x10c10a8c;
          puVar16[1] = 0x104039ae;
          iVar7 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar16 + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x34),*(undefined4 *)(iVar7 + 0x38),
                     *(undefined4 *)(iVar7 + 0x3c),*(undefined4 *)(iVar7 + 0x40),
                     *(undefined4 *)(iVar7 + 0x44),*(undefined4 *)(iVar7 + 0x48),
                     *(undefined4 *)(iVar7 + 0x4c));
          puVar16 = *(undefined4 **)(param_1 + 0xe30);
          *puVar16 = 0x10c00a8c;
          puVar16 = puVar16 + 1;
          *puVar16 = 0x104011ae;
LAB_97bdde5c:
          *(undefined4 **)(param_1 + 0xe30) = puVar16 + 1;
          ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(param_1,1);
          ((int (*)())_PPCRuntimeCompilerBackupRegister)(param_1,2);
          ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,2);
          puVar11 = *(uint **)(param_1 + 0xe30);
          uVar22 = 0x7c43c0ce;
          goto LAB_97bdde90;
        }
        if (uVar22 == 3) {
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar17 + 0x34),*(undefined4 *)(iVar17 + 0x38),
                     *(undefined4 *)(iVar17 + 0x3c),*(undefined4 *)(iVar17 + 0x40),
                     *(undefined4 *)(iVar17 + 0x44),*(undefined4 *)(iVar17 + 0x48),
                     *(undefined4 *)(iVar17 + 0x4c));
          iVar7 = *(int *)(param_1 + 0xe28);
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x58),*(undefined4 *)(iVar7 + 0x5c),
                     *(undefined4 *)(iVar7 + 0x60),*(undefined4 *)(iVar7 + 100),
                     *(undefined4 *)(iVar7 + 0x68),*(undefined4 *)(iVar7 + 0x6c),
                     *(undefined4 *)(iVar7 + 0x70));
          puVar16 = *(undefined4 **)(param_1 + 0xe30);
          *puVar16 = 0x10c00a8c;
          puVar16[1] = 0x104039ae;
          iVar7 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar16 + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x34),*(undefined4 *)(iVar7 + 0x38),
                     *(undefined4 *)(iVar7 + 0x3c),*(undefined4 *)(iVar7 + 0x40),
                     *(undefined4 *)(iVar7 + 0x44),*(undefined4 *)(iVar7 + 0x48),
                     *(undefined4 *)(iVar7 + 0x4c));
          puVar16 = *(undefined4 **)(param_1 + 0xe30);
          *puVar16 = 0x10c10a8c;
          puVar16[1] = 0x104011ae;
          iVar7 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar16 + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x34),*(undefined4 *)(iVar7 + 0x38),
                     *(undefined4 *)(iVar7 + 0x3c),*(undefined4 *)(iVar7 + 0x40),
                     *(undefined4 *)(iVar7 + 0x44),*(undefined4 *)(iVar7 + 0x48),
                     *(undefined4 *)(iVar7 + 0x4c));
          puVar16 = *(undefined4 **)(param_1 + 0xe30);
          *puVar16 = 0x10c20a8c;
          puVar16[1] = 0x104011ae;
          puVar16[2] = 0x3b000210;
          puVar16[3] = 0x7c43c1ce;
          iVar7 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar16 + 4;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x58),*(undefined4 *)(iVar7 + 0x5c),
                     *(undefined4 *)(iVar7 + 0x60),*(undefined4 *)(iVar7 + 100),
                     *(undefined4 *)(iVar7 + 0x68),*(undefined4 *)(iVar7 + 0x6c),
                     *(undefined4 *)(iVar7 + 0x70));
          puVar16 = *(undefined4 **)(param_1 + 0xe30);
          *puVar16 = 0x10c20a8c;
          puVar16[1] = 0x104039ae;
          iVar7 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar16 + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x34),*(undefined4 *)(iVar7 + 0x38),
                     *(undefined4 *)(iVar7 + 0x3c),*(undefined4 *)(iVar7 + 0x40),
                     *(undefined4 *)(iVar7 + 0x44),*(undefined4 *)(iVar7 + 0x48),
                     *(undefined4 *)(iVar7 + 0x4c));
          puVar16 = *(undefined4 **)(param_1 + 0xe30);
          *puVar16 = 0x10c10a8c;
          puVar16[1] = 0x104011ae;
          iVar7 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar16 + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x34),*(undefined4 *)(iVar7 + 0x38),
                     *(undefined4 *)(iVar7 + 0x3c),*(undefined4 *)(iVar7 + 0x40),
                     *(undefined4 *)(iVar7 + 0x44),*(undefined4 *)(iVar7 + 0x48),
                     *(undefined4 *)(iVar7 + 0x4c));
          puVar16 = *(undefined4 **)(param_1 + 0xe30);
          *puVar16 = 0x10c00a8c;
          puVar16[1] = 0x104011ae;
          puVar16[2] = 0x3b200220;
          puVar16[3] = 0x7c43c9ce;
          iVar7 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar16 + 4;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x58),*(undefined4 *)(iVar7 + 0x5c),
                     *(undefined4 *)(iVar7 + 0x60),*(undefined4 *)(iVar7 + 100),
                     *(undefined4 *)(iVar7 + 0x68),*(undefined4 *)(iVar7 + 0x6c),
                     *(undefined4 *)(iVar7 + 0x70));
          puVar16 = *(undefined4 **)(param_1 + 0xe30);
          *puVar16 = 0x10c00a8c;
          puVar16[1] = 0x104039ae;
          iVar7 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar16 + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x34),*(undefined4 *)(iVar7 + 0x38),
                     *(undefined4 *)(iVar7 + 0x3c),*(undefined4 *)(iVar7 + 0x40),
                     *(undefined4 *)(iVar7 + 0x44),*(undefined4 *)(iVar7 + 0x48),
                     *(undefined4 *)(iVar7 + 0x4c));
          puVar16 = *(undefined4 **)(param_1 + 0xe30);
          *puVar16 = 0x10c10a8c;
          puVar16[1] = 0x104011ae;
          iVar7 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar16 + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x34),*(undefined4 *)(iVar7 + 0x38),
                     *(undefined4 *)(iVar7 + 0x3c),*(undefined4 *)(iVar7 + 0x40),
                     *(undefined4 *)(iVar7 + 0x44),*(undefined4 *)(iVar7 + 0x48),
                     *(undefined4 *)(iVar7 + 0x4c));
          puVar16 = *(undefined4 **)(param_1 + 0xe30);
          *puVar16 = 0x10c20a8c;
          puVar16[1] = 0x104011ae;
          *(undefined4 **)(param_1 + 0xe30) = puVar16 + 2;
          ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(param_1,2);
          ((int (*)())_PPCRuntimeCompilerBackupRegister)(param_1,2);
          ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,2);
          puVar16 = *(undefined4 **)(param_1 + 0xe30);
          *puVar16 = 0x7c43c8ce;
          goto LAB_97bdde5c;
        }
        if (uVar22 == 4) {
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar17 + 0x34),*(undefined4 *)(iVar17 + 0x38),
                     *(undefined4 *)(iVar17 + 0x3c),*(undefined4 *)(iVar17 + 0x40),
                     *(undefined4 *)(iVar17 + 0x44),*(undefined4 *)(iVar17 + 0x48),
                     *(undefined4 *)(iVar17 + 0x4c));
          iVar7 = *(int *)(param_1 + 0xe28);
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x58),*(undefined4 *)(iVar7 + 0x5c),
                     *(undefined4 *)(iVar7 + 0x60),*(undefined4 *)(iVar7 + 100),
                     *(undefined4 *)(iVar7 + 0x68),*(undefined4 *)(iVar7 + 0x6c),
                     *(undefined4 *)(iVar7 + 0x70));
          puVar16 = *(undefined4 **)(param_1 + 0xe30);
          *puVar16 = 0x10c00a8c;
          puVar16[1] = 0x104039ae;
          iVar7 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar16 + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x34),*(undefined4 *)(iVar7 + 0x38),
                     *(undefined4 *)(iVar7 + 0x3c),*(undefined4 *)(iVar7 + 0x40),
                     *(undefined4 *)(iVar7 + 0x44),*(undefined4 *)(iVar7 + 0x48),
                     *(undefined4 *)(iVar7 + 0x4c));
          puVar16 = *(undefined4 **)(param_1 + 0xe30);
          *puVar16 = 0x10c10a8c;
          puVar16[1] = 0x104011ae;
          iVar7 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar16 + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x34),*(undefined4 *)(iVar7 + 0x38),
                     *(undefined4 *)(iVar7 + 0x3c),*(undefined4 *)(iVar7 + 0x40),
                     *(undefined4 *)(iVar7 + 0x44),*(undefined4 *)(iVar7 + 0x48),
                     *(undefined4 *)(iVar7 + 0x4c));
          puVar16 = *(undefined4 **)(param_1 + 0xe30);
          *puVar16 = 0x10c20a8c;
          puVar16[1] = 0x104011ae;
          iVar7 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar16 + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x34),*(undefined4 *)(iVar7 + 0x38),
                     *(undefined4 *)(iVar7 + 0x3c),*(undefined4 *)(iVar7 + 0x40),
                     *(undefined4 *)(iVar7 + 0x44),*(undefined4 *)(iVar7 + 0x48),
                     *(undefined4 *)(iVar7 + 0x4c));
          puVar16 = *(undefined4 **)(param_1 + 0xe30);
          *puVar16 = 0x10c30a8c;
          puVar16[1] = 0x104011ae;
          puVar16[2] = 0x3ae00210;
          puVar16[3] = 0x7c43b9ce;
          iVar7 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar16 + 4;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x58),*(undefined4 *)(iVar7 + 0x5c),
                     *(undefined4 *)(iVar7 + 0x60),*(undefined4 *)(iVar7 + 100),
                     *(undefined4 *)(iVar7 + 0x68),*(undefined4 *)(iVar7 + 0x6c),
                     *(undefined4 *)(iVar7 + 0x70));
          puVar16 = *(undefined4 **)(param_1 + 0xe30);
          *puVar16 = 0x10c30a8c;
          puVar16[1] = 0x104039ae;
          iVar7 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar16 + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x34),*(undefined4 *)(iVar7 + 0x38),
                     *(undefined4 *)(iVar7 + 0x3c),*(undefined4 *)(iVar7 + 0x40),
                     *(undefined4 *)(iVar7 + 0x44),*(undefined4 *)(iVar7 + 0x48),
                     *(undefined4 *)(iVar7 + 0x4c));
          puVar16 = *(undefined4 **)(param_1 + 0xe30);
          *puVar16 = 0x10c20a8c;
          puVar16[1] = 0x104011ae;
          iVar7 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar16 + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x34),*(undefined4 *)(iVar7 + 0x38),
                     *(undefined4 *)(iVar7 + 0x3c),*(undefined4 *)(iVar7 + 0x40),
                     *(undefined4 *)(iVar7 + 0x44),*(undefined4 *)(iVar7 + 0x48),
                     *(undefined4 *)(iVar7 + 0x4c));
          puVar16 = *(undefined4 **)(param_1 + 0xe30);
          *puVar16 = 0x10c10a8c;
          puVar16[1] = 0x104011ae;
          iVar7 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar16 + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x34),*(undefined4 *)(iVar7 + 0x38),
                     *(undefined4 *)(iVar7 + 0x3c),*(undefined4 *)(iVar7 + 0x40),
                     *(undefined4 *)(iVar7 + 0x44),*(undefined4 *)(iVar7 + 0x48),
                     *(undefined4 *)(iVar7 + 0x4c));
          puVar16 = *(undefined4 **)(param_1 + 0xe30);
          *puVar16 = 0x10c00a8c;
          puVar16[1] = 0x104011ae;
          puVar16[2] = 0x3b000220;
          puVar16[3] = 0x7c43c1ce;
          iVar7 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar16 + 4;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x58),*(undefined4 *)(iVar7 + 0x5c),
                     *(undefined4 *)(iVar7 + 0x60),*(undefined4 *)(iVar7 + 100),
                     *(undefined4 *)(iVar7 + 0x68),*(undefined4 *)(iVar7 + 0x6c),
                     *(undefined4 *)(iVar7 + 0x70));
          puVar16 = *(undefined4 **)(param_1 + 0xe30);
          *puVar16 = 0x10c00a8c;
          puVar16[1] = 0x104039ae;
          iVar7 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar16 + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x34),*(undefined4 *)(iVar7 + 0x38),
                     *(undefined4 *)(iVar7 + 0x3c),*(undefined4 *)(iVar7 + 0x40),
                     *(undefined4 *)(iVar7 + 0x44),*(undefined4 *)(iVar7 + 0x48),
                     *(undefined4 *)(iVar7 + 0x4c));
          puVar16 = *(undefined4 **)(param_1 + 0xe30);
          *puVar16 = 0x10c10a8c;
          puVar16[1] = 0x104011ae;
          iVar7 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar16 + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x34),*(undefined4 *)(iVar7 + 0x38),
                     *(undefined4 *)(iVar7 + 0x3c),*(undefined4 *)(iVar7 + 0x40),
                     *(undefined4 *)(iVar7 + 0x44),*(undefined4 *)(iVar7 + 0x48),
                     *(undefined4 *)(iVar7 + 0x4c));
          puVar16 = *(undefined4 **)(param_1 + 0xe30);
          *puVar16 = 0x10c20a8c;
          puVar16[1] = 0x104011ae;
          iVar7 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar16 + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x34),*(undefined4 *)(iVar7 + 0x38),
                     *(undefined4 *)(iVar7 + 0x3c),*(undefined4 *)(iVar7 + 0x40),
                     *(undefined4 *)(iVar7 + 0x44),*(undefined4 *)(iVar7 + 0x48),
                     *(undefined4 *)(iVar7 + 0x4c));
          puVar16 = *(undefined4 **)(param_1 + 0xe30);
          *puVar16 = 0x10c30a8c;
          puVar16[1] = 0x104011ae;
          puVar16[2] = 0x3b200230;
          puVar16[3] = 0x7c43c9ce;
          iVar7 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar16 + 4;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x58),*(undefined4 *)(iVar7 + 0x5c),
                     *(undefined4 *)(iVar7 + 0x60),*(undefined4 *)(iVar7 + 100),
                     *(undefined4 *)(iVar7 + 0x68),*(undefined4 *)(iVar7 + 0x6c),
                     *(undefined4 *)(iVar7 + 0x70));
          puVar16 = *(undefined4 **)(param_1 + 0xe30);
          *puVar16 = 0x10c30a8c;
          puVar16[1] = 0x104039ae;
          iVar7 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar16 + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x34),*(undefined4 *)(iVar7 + 0x38),
                     *(undefined4 *)(iVar7 + 0x3c),*(undefined4 *)(iVar7 + 0x40),
                     *(undefined4 *)(iVar7 + 0x44),*(undefined4 *)(iVar7 + 0x48),
                     *(undefined4 *)(iVar7 + 0x4c));
          puVar16 = *(undefined4 **)(param_1 + 0xe30);
          *puVar16 = 0x10c20a8c;
          puVar16[1] = 0x104011ae;
          iVar7 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar16 + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x34),*(undefined4 *)(iVar7 + 0x38),
                     *(undefined4 *)(iVar7 + 0x3c),*(undefined4 *)(iVar7 + 0x40),
                     *(undefined4 *)(iVar7 + 0x44),*(undefined4 *)(iVar7 + 0x48),
                     *(undefined4 *)(iVar7 + 0x4c));
          puVar16 = *(undefined4 **)(param_1 + 0xe30);
          *puVar16 = 0x10c10a8c;
          puVar16[1] = 0x104011ae;
          iVar7 = *(int *)(param_1 + 0xe28);
          *(undefined4 **)(param_1 + 0xe30) = puVar16 + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x34),*(undefined4 *)(iVar7 + 0x38),
                     *(undefined4 *)(iVar7 + 0x3c),*(undefined4 *)(iVar7 + 0x40),
                     *(undefined4 *)(iVar7 + 0x44),*(undefined4 *)(iVar7 + 0x48),
                     *(undefined4 *)(iVar7 + 0x4c));
          puVar16 = *(undefined4 **)(param_1 + 0xe30);
          *puVar16 = 0x10c00a8c;
          puVar16[1] = 0x104011ae;
          *(undefined4 **)(param_1 + 0xe30) = puVar16 + 2;
          ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(param_1,3);
          ((int (*)())_PPCRuntimeCompilerBackupRegister)(param_1,2);
          ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,2);
          puVar16 = *(undefined4 **)(param_1 + 0xe30);
          *puVar16 = 0x7c43c8ce;
          *(undefined4 **)(param_1 + 0xe30) = puVar16 + 1;
          ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(param_1,2);
          ((int (*)())_PPCRuntimeCompilerBackupRegister)(param_1,2);
          ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,2);
          puVar16 = *(undefined4 **)(param_1 + 0xe30);
          *puVar16 = 0x7c43c0ce;
          *(undefined4 **)(param_1 + 0xe30) = puVar16 + 1;
          ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(param_1,1);
          ((int (*)())_PPCRuntimeCompilerBackupRegister)(param_1,2);
          ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,2);
          puVar11 = *(uint **)(param_1 + 0xe30);
          uVar22 = 0x7c43b8ce;
          goto LAB_97bdde90;
        }
      }
      else {
        if ((iVar5 == 0x31) || (iVar5 == 0x36)) {
          ((int (*)())_PPCRuntimeCompilerBackupRegister)(param_1,2);
          ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,2);
          if (uVar22 < 2) {
            iVar7 = *(int *)(param_1 + 0xe28);
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x34),*(undefined4 *)(iVar7 + 0x38),
                       *(undefined4 *)(iVar7 + 0x3c),*(undefined4 *)(iVar7 + 0x40),
                       *(undefined4 *)(iVar7 + 0x44),*(undefined4 *)(iVar7 + 0x48),
                       *(undefined4 *)(iVar7 + 0x4c));
            iVar7 = *(int *)(param_1 + 0xe28);
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x58),*(undefined4 *)(iVar7 + 0x5c),
                       *(undefined4 *)(iVar7 + 0x60),*(undefined4 *)(iVar7 + 100),
                       *(undefined4 *)(iVar7 + 0x68),*(undefined4 *)(iVar7 + 0x6c),
                       *(undefined4 *)(iVar7 + 0x70));
            if (*(char *)(*(int *)(param_1 + 0xe28) + 0x21) == '\x01') {
              cVar2 = *(char *)(*(int *)(param_1 + 0xe28) + 5);
              if (cVar2 == '\x01') {
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                puVar14 = &_glpOpSetAllEqualTo1AVRTC;
              }
              else if (cVar2 == '\x02') {
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                puVar14 = &_glpOpSetAllEqualTo2AVRTC;
              }
              else if (cVar2 == '\x03') {
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                puVar14 = &_glpOpSetAllEqualTo3AVRTC;
              }
              else {
                if (cVar2 != '\x04') goto LAB_97bdf944;
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                puVar14 = &_glpOpSetAllEqualTo4AVRTC;
              }
            }
            else {
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpSetEqualToAVRTC;
            }
LAB_97bdf930:
            iVar7 = ((int (*)())_glpRTCAddAChunk)(puVar14,puVar16);
            *(int *)(param_1 + 0xe30) = *(int *)(param_1 + 0xe30) + iVar7 * 4;
          }
          else {
            puVar16 = *(undefined4 **)(param_1 + 0xe30);
            *puVar16 = 0x10a84484;
            *(undefined4 **)(param_1 + 0xe30) = puVar16 + 1;
            if (uVar22 == 3) {
              uVar22 = 0;
              do {
                iVar7 = *(int *)(param_1 + 0xe28);
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x34),*(undefined4 *)(iVar7 + 0x38),
                           *(undefined4 *)(iVar7 + 0x3c),*(undefined4 *)(iVar7 + 0x40),
                           *(undefined4 *)(iVar7 + 0x44),*(undefined4 *)(iVar7 + 0x48),
                           *(undefined4 *)(iVar7 + 0x4c));
                iVar7 = *(int *)(param_1 + 0xe28);
                uVar22 = uVar22 + 1;
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x58),*(undefined4 *)(iVar7 + 0x5c),
                           *(undefined4 *)(iVar7 + 0x60),*(undefined4 *)(iVar7 + 100),
                           *(undefined4 *)(iVar7 + 0x68),*(undefined4 *)(iVar7 + 0x6c),
                           *(undefined4 *)(iVar7 + 0x70));
                iVar7 = ((int (*)())_glpRTCAddAChunk)(&_glpOpSetAllEqualTo3AVRTC,*(undefined4 *)(param_1 + 0xe30)
                                        );
                iVar17 = *(int *)(param_1 + 0xe30);
                *(undefined4 *)(iVar17 + iVar7 * 4) = 0x10a5112c;
                *(int *)(param_1 + 0xe30) = iVar17 + iVar7 * 4 + 4;
              } while (uVar22 < 3);
LAB_97bdf7ec:
              ((int (*)())_PPCRuntimeCompilerBackupRegister)(param_1,0);
              ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,0);
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpAllAVRTC;
              *puVar16 = 0x10052c84;
              puVar16 = puVar16 + 1;
              *(undefined4 **)(param_1 + 0xe30) = puVar16;
              goto LAB_97bdf930;
            }
            if (uVar22 < 4) {
              if (uVar22 == 2) {
                uVar22 = 0;
                do {
                  iVar7 = *(int *)(param_1 + 0xe28);
                  ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x34),*(undefined4 *)(iVar7 + 0x38),
                             *(undefined4 *)(iVar7 + 0x3c),*(undefined4 *)(iVar7 + 0x40),
                             *(undefined4 *)(iVar7 + 0x44),*(undefined4 *)(iVar7 + 0x48),
                             *(undefined4 *)(iVar7 + 0x4c));
                  iVar7 = *(int *)(param_1 + 0xe28);
                  uVar22 = uVar22 + 1;
                  ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x58),*(undefined4 *)(iVar7 + 0x5c),
                             *(undefined4 *)(iVar7 + 0x60),*(undefined4 *)(iVar7 + 100),
                             *(undefined4 *)(iVar7 + 0x68),*(undefined4 *)(iVar7 + 0x6c),
                             *(undefined4 *)(iVar7 + 0x70));
                  iVar7 = ((int (*)())_glpRTCAddAChunk)(&_glpOpSetAllEqualTo2AVRTC,
                                           *(undefined4 *)(param_1 + 0xe30));
                  iVar17 = *(int *)(param_1 + 0xe30);
                  *(undefined4 *)(iVar17 + iVar7 * 4) = 0x10a5112c;
                  *(int *)(param_1 + 0xe30) = iVar17 + iVar7 * 4 + 4;
                } while (uVar22 < 2);
                goto LAB_97bdf7ec;
              }
            }
            else if (uVar22 == 4) {
              uVar22 = 0;
              do {
                iVar7 = *(int *)(param_1 + 0xe28);
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x34),*(undefined4 *)(iVar7 + 0x38),
                           *(undefined4 *)(iVar7 + 0x3c),*(undefined4 *)(iVar7 + 0x40),
                           *(undefined4 *)(iVar7 + 0x44),*(undefined4 *)(iVar7 + 0x48),
                           *(undefined4 *)(iVar7 + 0x4c));
                iVar7 = *(int *)(param_1 + 0xe28);
                uVar22 = uVar22 + 1;
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x58),*(undefined4 *)(iVar7 + 0x5c),
                           *(undefined4 *)(iVar7 + 0x60),*(undefined4 *)(iVar7 + 100),
                           *(undefined4 *)(iVar7 + 0x68),*(undefined4 *)(iVar7 + 0x6c),
                           *(undefined4 *)(iVar7 + 0x70));
                iVar7 = ((int (*)())_glpRTCAddAChunk)(&_glpOpSetAllEqualTo4AVRTC,*(undefined4 *)(param_1 + 0xe30)
                                        );
                iVar17 = *(int *)(param_1 + 0xe30);
                *(undefined4 *)(iVar17 + iVar7 * 4) = 0x10a5112c;
                *(int *)(param_1 + 0xe30) = iVar17 + iVar7 * 4 + 4;
              } while (uVar22 < 4);
              goto LAB_97bdf7ec;
            }
          }
LAB_97bdf944:
          if (iVar5 == 0x36) {
            puVar11 = *(uint **)(param_1 + 0xe30);
            uVar22 = 0x1048104a;
LAB_97bdde90:
            *puVar11 = uVar22;
LAB_97bdde94:
            *(uint **)(param_1 + 0xe30) = puVar11 + 1;
          }
          goto LAB_97bdde9c;
        }
        uVar10 = 0;
        if (uVar22 != 0) {
          do {
            ((int (*)())_PPCRuntimeCompilerBackupRegister)(param_1,2);
            uVar23 = 0;
            ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,2);
            iVar7 = *(int *)(param_1 + 0xe28);
            if (*(int *)(iVar7 + 0x30) != 0) {
              iVar17 = 0;
              do {
                iVar7 = iVar17 + iVar7;
                uVar23 = uVar23 + 1;
                iVar17 = iVar17 + 0x24;
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(param_1,*(undefined4 *)(iVar7 + 0x34),*(undefined4 *)(iVar7 + 0x38),
                           *(undefined4 *)(iVar7 + 0x3c),*(undefined4 *)(iVar7 + 0x40),
                           *(undefined4 *)(iVar7 + 0x44),*(undefined4 *)(iVar7 + 0x48),
                           *(undefined4 *)(iVar7 + 0x4c));
                iVar7 = *(int *)(param_1 + 0xe28);
              } while (uVar23 < *(uint *)(iVar7 + 0x30));
            }
            switch(iVar5) {
            case 1:
            case 0xb:
            case 0x10:
            case 0x11:
            case 0x13:
            case 0x14:
            case 0x18:
            case 0x2e:
            case 0x38:
            case 0x42:
            case 0x43:
            case 0x44:
            case 0x45:
            case 0x6f:
            case 0x70:
              ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,0);
              ((int (*)())_PPCRuntimeCompilerDirtyRegister)(param_1,1);
              break;
            case 0x48:
              ((int (*)())_PPCRuntimeCompilerDirtyRegistersWithIndirectData)(param_1);
            }
            switch(iVar5) {
            case 0:
switchD_97bdfc38_caseD_0:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpMovAVRTC;
              break;
            case 1:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpLitAVRTC;
              break;
            case 2:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpAbsAVRTC;
              break;
            case 3:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpCeilAVRTC;
              break;
            case 4:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpFrcAVRTC;
              break;
            case 5:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpFlrAVRTC;
              break;
            default:
              goto switchD_97bdfc38_caseD_6;
            case 7:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpSetSignAVRTC;
              break;
            case 8:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpAnyAVRTC;
              break;
            case 9:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpAllAVRTC;
              break;
            case 10:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpNotAVRTC;
              break;
            case 0xb:
              bVar3 = *(byte *)(*(int *)(param_1 + 0xe28) + 5);
              if (bVar3 == 2) {
                uVar13 = _PPCNoiseGeneratorCalculate2DAVRTC
                                   (*(int *)(param_1 + 0xe20) + 0x360,
                                    *(undefined4 *)(param_1 + 0xe30));
              }
              else if (bVar3 < 3) {
                if (bVar3 != 1) goto switchD_97bdfc38_caseD_6;
                uVar13 = _PPCNoiseGeneratorCalculate1DAVRTC
                                   (*(int *)(param_1 + 0xe20) + 0x360,
                                    *(undefined4 *)(param_1 + 0xe30));
              }
              else if (bVar3 == 3) {
                uVar13 = _PPCNoiseGeneratorCalculate3DAVRTC
                                   (*(int *)(param_1 + 0xe20) + 0x360,
                                    *(undefined4 *)(param_1 + 0xe30));
              }
              else {
                if (bVar3 != 4) goto switchD_97bdfc38_caseD_6;
                uVar13 = _PPCNoiseGeneratorCalculate4DAVRTC
                                   (*(int *)(param_1 + 0xe20) + 0x360,
                                    *(undefined4 *)(param_1 + 0xe30));
              }
              goto LAB_97be1634;
            case 0xc:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpSqrtAVRTC;
              break;
            case 0xd:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpRsqAVRTC;
              break;
            case 0xe:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpRcpAVRTC;
              break;
            case 0x10:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              goto LAB_97be04f0;
            case 0x11:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpExpAVRTC;
              break;
            case 0x12:
              bVar3 = *(byte *)(*(int *)(param_1 + 0xe28) + 5);
              if (bVar3 == 2) {
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                puVar14 = &_glpOpLength2AVRTC;
              }
              else if (bVar3 < 3) {
                if (bVar3 != 1) goto switchD_97bdfc38_caseD_6;
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                puVar14 = &_glpOpLength1AVRTC;
              }
              else if (bVar3 == 3) {
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                puVar14 = &_glpOpLength3AVRTC;
              }
              else {
                if (bVar3 != 4) goto switchD_97bdfc38_caseD_6;
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                puVar14 = &_glpOpLength4AVRTC;
              }
              break;
            case 0x13:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpLg2AVRTC;
              break;
            case 0x14:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpLogAVRTC;
              break;
            case 0x15:
              bVar3 = *(byte *)(*(int *)(param_1 + 0xe28) + 5);
              if (bVar3 == 2) {
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                puVar14 = &_glpOpNormalise2AVRTC;
              }
              else if (bVar3 < 3) {
                if (bVar3 != 1) goto switchD_97bdfc38_caseD_6;
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                puVar14 = &_glpOpNormalise1AVRTC;
              }
              else if (bVar3 == 3) {
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                puVar14 = &_glpOpNormalise3AVRTC;
              }
              else {
                if (bVar3 != 4) goto switchD_97bdfc38_caseD_6;
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                puVar14 = &_glpOpNormalise4AVRTC;
              }
              break;
            case 0x16:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpDegreesToRadiansAVRTC;
              break;
            case 0x17:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpRadiansToDegreesAVRTC;
              break;
            case 0x18:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              *puVar16 = 0x1003028c;
              puVar16 = puVar16 + 1;
              *(undefined4 **)(param_1 + 0xe30) = puVar16;
              iVar7 = ((int (*)())_glpRTCAddAChunk)(&_glpOpCosAVRTC,puVar16);
              iVar17 = *(int *)(param_1 + 0xe30);
              *(undefined4 *)(iVar17 + iVar7 * 4) = 0x10221484;
              *(int *)(param_1 + 0xe30) = iVar17 + iVar7 * 4 + 4;
              iVar7 = ((int (*)())_glpRTCAddAChunk)(&_glpOpSinAVRTC);
              puVar12 = (uint *)(*(int *)(param_1 + 0xe30) + iVar7 * 4 + 4);
              *(undefined4 *)(*(int *)(param_1 + 0xe30) + iVar7 * 4) = 0x1041132c;
              goto LAB_97be1820;
            case 0x19:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpSinAVRTC;
              break;
            case 0x1a:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpCosAVRTC;
              break;
            case 0x1f:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpAddAVRTC;
              break;
            case 0x20:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpSubAVRTC;
              break;
            case 0x21:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpModAVRTC;
              break;
            case 0x23:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpMulAVRTC;
              break;
            case 0x24:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpLogicalAndAVRTC;
              break;
            case 0x25:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpLogicalOrAVRTC;
              break;
            case 0x26:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpLogicalXorAVRTC;
              break;
            case 0x27:
              bVar3 = *(byte *)(*(int *)(param_1 + 0xe28) + 5);
              if (bVar3 == 2) {
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                puVar14 = &_glpOpDp2AVRTC;
                break;
              }
              if (bVar3 < 3) {
                if (bVar3 == 1) {
                  puVar16 = *(undefined4 **)(param_1 + 0xe30);
                  puVar14 = &_glpOpDp1AVRTC;
                  break;
                }
              }
              else {
                if (bVar3 == 3) goto switchD_97bdfc38_caseD_28;
                if (bVar3 == 4) goto switchD_97bdfc38_caseD_29;
              }
              goto switchD_97bdfc38_caseD_6;
            case 0x28:
switchD_97bdfc38_caseD_28:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpDp3AVRTC;
              break;
            case 0x29:
switchD_97bdfc38_caseD_29:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpDp4AVRTC;
              break;
            case 0x2a:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpDphAVRTC;
              break;
            case 0x2b:
              if (*(int *)(*(int *)(param_1 + 0xe24) + 0x38) - 0x8b30U < 2) {
                bVar3 = *(byte *)(*(int *)(param_1 + 0xe28) + 5);
                if (bVar3 == 2) {
                  puVar16 = *(undefined4 **)(param_1 + 0xe30);
                  puVar14 = &_glpOpDistance2GLSLAVRTC;
                }
                else if (bVar3 < 3) {
                  if (bVar3 != 1) goto switchD_97bdfc38_caseD_6;
                  puVar16 = *(undefined4 **)(param_1 + 0xe30);
                  puVar14 = &_glpOpDistance1GLSLAVRTC;
                }
                else if (bVar3 == 3) {
                  puVar16 = *(undefined4 **)(param_1 + 0xe30);
                  puVar14 = &_glpOpDistance3GLSLAVRTC;
                }
                else {
                  if (bVar3 != 4) goto switchD_97bdfc38_caseD_6;
                  puVar16 = *(undefined4 **)(param_1 + 0xe30);
                  puVar14 = &_glpOpDistance4GLSLAVRTC;
                }
              }
              else {
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                puVar14 = &_glpOpDistanceARBVPFPAVRTC;
              }
              break;
            case 0x2c:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpMinAVRTC;
              break;
            case 0x2d:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpMaxAVRTC;
              break;
            case 0x2e:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpXpdAVRTC;
              break;
            case 0x2f:
              bVar3 = *(byte *)(*(int *)(param_1 + 0xe28) + 5);
              if (bVar3 == 2) {
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                puVar14 = &_glpOpReflect2AVRTC;
              }
              else if (bVar3 < 3) {
                if (bVar3 != 1) goto switchD_97bdfc38_caseD_6;
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                puVar14 = &_glpOpReflect1AVRTC;
              }
              else if (bVar3 == 3) {
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                puVar14 = &_glpOpReflect3AVRTC;
              }
              else {
                if (bVar3 != 4) goto switchD_97bdfc38_caseD_6;
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                puVar14 = &_glpOpReflect4AVRTC;
              }
              break;
            case 0x30:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpStrAVRTC;
              break;
            case 0x32:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpSgeAVRTC;
              break;
            case 0x33:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpSgtAVRTC;
              break;
            case 0x34:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpSleAVRTC;
              break;
            case 0x35:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpSltAVRTC;
              break;
            case 0x37:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpSflAVRTC;
              break;
            case 0x38:
              iVar7 = ((int (*)())_glpRTCAddAChunk)(&_glpOpLg2AVRTC,*(undefined4 *)(param_1 + 0xe30));
              iVar7 = *(int *)(param_1 + 0xe30) + iVar7 * 4;
              *(int *)(param_1 + 0xe30) = iVar7;
              iVar7 = ((int (*)())_glpRTCAddAChunk)(&_glpOpMulForPowAVRTC,iVar7);
              puVar16 = (undefined4 *)(*(int *)(param_1 + 0xe30) + iVar7 * 4);
              *(undefined4 **)(param_1 + 0xe30) = puVar16;
LAB_97be04f0:
              puVar14 = &_glpOpEx2AVRTC;
              break;
            case 0x39:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpScalarSelectAVRTC;
              break;
            case 0x3a:
              iVar7 = *(int *)(*(int *)(param_1 + 0xe28) + 0x24);
              if (iVar7 == 1) {
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                puVar14 = &_glpOpDivideAVRTC;
              }
              else {
                if (iVar7 != 3) goto switchD_97bdfc38_caseD_6;
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                puVar14 = &_glpOpIntegerDivideAVRTC;
              }
              break;
            case 0x3b:
              bVar3 = *(byte *)(*(int *)(param_1 + 0xe28) + 5);
              if (bVar3 == 2) {
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                puVar14 = &_glpOpFaceForward2AVRTC;
              }
              else if (bVar3 < 3) {
                if (bVar3 != 1) goto switchD_97bdfc38_caseD_6;
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                puVar14 = &_glpOpFaceForward1AVRTC;
              }
              else if (bVar3 == 3) {
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                puVar14 = &_glpOpFaceForward3AVRTC;
              }
              else {
                if (bVar3 != 4) goto switchD_97bdfc38_caseD_6;
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                puVar14 = &_glpOpFaceForward4AVRTC;
              }
              break;
            case 0x3c:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpLerpAVRTC;
              break;
            case 0x3d:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpClampAVRTC;
              break;
            case 0x3e:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpCmpAVRTC;
              break;
            case 0x3f:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpMadAVRTC;
              break;
            case 0x40:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpSmoothStepAVRTC;
              break;
            case 0x41:
              iVar7 = *(int *)(param_1 + 0xe28);
              uVar23 = (uint)*(byte *)(iVar7 + 99);
              uVar20 = (uint)*(byte *)(iVar7 + 0x61);
              uVar19 = (uint)*(byte *)(iVar7 + 0x62);
              switch(*(undefined1 *)(iVar7 + 0x60)) {
              case 0:
                if (uVar20 == 0) {
                  uVar20 = 0xffffffff;
                  if ((uVar19 == 0) && (uVar19 = 0xffffffff, uVar23 == 0)) {
                    uVar23 = 0xffffffff;
                  }
LAB_97be06cc:
                  puVar11 = *(uint **)(param_1 + 0xe30);
                  uVar6 = 0x10400000;
LAB_97be07d8:
                  uVar6 = uVar6 | 0x28c;
LAB_97be0ad4:
                  *puVar11 = uVar6;
LAB_97be0ad8:
                  *(uint **)(param_1 + 0xe30) = puVar11 + 1;
                  break;
                }
                if (uVar20 != 1) goto LAB_97be06cc;
                if (uVar19 != 2) {
                  puVar11 = *(uint **)(param_1 + 0xe30);
                  uVar20 = 0x1040022c;
                  goto LAB_97be0794;
                }
                if (uVar23 != 3) {
                  puVar12 = *(uint **)(param_1 + 0xe30);
                  uVar19 = 0x1040032c;
                  goto LAB_97be077c;
                }
                puVar12 = *(uint **)(param_1 + 0xe30);
                uVar23 = 0x10400484;
                goto LAB_97be1470;
              case 1:
                if (uVar20 == 1) {
                  uVar20 = 0xffffffff;
                  if ((uVar19 == 1) && (uVar19 = 0xffffffff, uVar23 == 1)) {
                    uVar23 = 0xffffffff;
                  }
LAB_97be0748:
                  puVar11 = *(uint **)(param_1 + 0xe30);
                  uVar6 = 0x10410000;
                  goto LAB_97be07d8;
                }
                if (uVar20 != 2) goto LAB_97be0748;
                if (uVar19 != 3) {
                  puVar11 = *(uint **)(param_1 + 0xe30);
                  uVar20 = 0x1040032c;
                  goto LAB_97be0794;
                }
                if (uVar23 != 0) {
                  puVar12 = *(uint **)(param_1 + 0xe30);
                  uVar19 = 0x10400484;
                  goto LAB_97be077c;
                }
                puVar12 = *(uint **)(param_1 + 0xe30);
                uVar23 = 0x10400000;
                goto LAB_97be13a0;
              case 2:
                if (uVar20 == 2) {
                  uVar20 = 0xffffffff;
                  if ((uVar19 == 2) && (uVar19 = 0xffffffff, uVar23 == 2)) {
                    uVar23 = 0xffffffff;
                  }
LAB_97be07d0:
                  puVar11 = *(uint **)(param_1 + 0xe30);
                  uVar6 = 0x10420000;
                  goto LAB_97be07d8;
                }
                if (uVar20 != 3) goto LAB_97be07d0;
                if (uVar19 != 0) {
                  puVar11 = *(uint **)(param_1 + 0xe30);
                  uVar20 = 0x10400484;
                  goto LAB_97be0794;
                }
                if (uVar23 != 1) {
                  puVar12 = *(uint **)(param_1 + 0xe30);
                  uVar19 = 0x10400000;
                  goto LAB_97be1050;
                }
                puVar12 = *(uint **)(param_1 + 0xe30);
                uVar23 = 0x10400000;
                goto LAB_97be1040;
              case 3:
                if (uVar20 == 0) {
                  if (uVar19 != 1) {
                    puVar11 = *(uint **)(param_1 + 0xe30);
                    uVar20 = 0x10400000;
                    goto LAB_97be0c28;
                  }
                  if (uVar23 != 2) {
                    puVar12 = *(uint **)(param_1 + 0xe30);
                    uVar19 = 0x10400000;
                    goto LAB_97be0c18;
                  }
                  puVar12 = *(uint **)(param_1 + 0xe30);
                  uVar23 = 0x10400000;
                  goto LAB_97be0c08;
                }
                if (uVar20 != 3) {
                  puVar11 = *(uint **)(param_1 + 0xe30);
                  uVar6 = 0x10400484;
                  goto LAB_97be0ad4;
                }
                if ((uVar19 == 3) && (uVar19 = 0xffffffff, uVar23 == 3)) {
                  uVar23 = 0xffffffff;
                }
                puVar11 = *(uint **)(param_1 + 0xe30);
                uVar20 = 0x1043028c;
                goto LAB_97be0794;
              case 4:
                if (uVar20 == 4) {
                  uVar20 = 0xffffffff;
                  if ((uVar19 == 4) && (uVar19 = 0xffffffff, uVar23 == 4)) {
                    uVar23 = 0xffffffff;
                  }
LAB_97be08c4:
                  puVar16 = *(undefined4 **)(param_1 + 0xe30);
                  uVar6 = 0x10400000;
LAB_97be0960:
                  *puVar16 = 0x10603cc4;
                  puVar11 = puVar16 + 1;
                  *puVar11 = uVar6 | 0x1a8c;
                  goto LAB_97be0ad8;
                }
                if (uVar20 != 5) goto LAB_97be08c4;
                if (uVar19 != 6) {
                  puVar16 = *(undefined4 **)(param_1 + 0xe30);
                  uVar13 = 0x10603cc4;
                  uVar20 = 0x10431a2c;
                  goto LAB_97be0e64;
                }
                if (uVar23 == 7) {
                  puVar12 = *(uint **)(param_1 + 0xe30);
                  uVar23 = 0x10403cc4;
                  goto LAB_97be1470;
                }
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                uVar13 = 0x10603cc4;
                uVar19 = 0x10431b2c;
                goto LAB_97be1248;
              case 5:
                if (uVar20 == 5) {
                  uVar20 = 0xffffffff;
                  if ((uVar19 == 5) && (uVar19 = 0xffffffff, uVar23 == 5)) {
                    uVar23 = 0xffffffff;
                  }
LAB_97be0954:
                  puVar16 = *(undefined4 **)(param_1 + 0xe30);
                  uVar6 = 0x10410000;
                  goto LAB_97be0960;
                }
                if (uVar20 != 6) goto LAB_97be0954;
                if (uVar19 != 7) {
                  puVar16 = *(undefined4 **)(param_1 + 0xe30);
                  uVar13 = 0x10603cc4;
                  uVar20 = 0x10431b2c;
                  goto LAB_97be0e64;
                }
                if (uVar23 != 4) {
                  puVar12 = *(uint **)(param_1 + 0xe30);
                  uVar19 = 0x10403cc4;
                  goto LAB_97be077c;
                }
                puVar12 = *(uint **)(param_1 + 0xe30);
                uVar23 = 0x10600000;
                uVar19 = 0x10430000;
                goto LAB_97be1484;
              case 6:
                if (uVar20 == 6) {
                  uVar20 = 0xffffffff;
                  if ((uVar19 == 6) && (uVar19 = 0xffffffff, uVar23 == 6)) {
                    uVar23 = 0xffffffff;
                  }
LAB_97be09ec:
                  puVar16 = *(undefined4 **)(param_1 + 0xe30);
                  uVar6 = 0x10420000;
                  goto LAB_97be0960;
                }
                if (uVar20 != 7) goto LAB_97be09ec;
                if (uVar19 != 4) {
                  puVar11 = *(uint **)(param_1 + 0xe30);
                  uVar20 = 0x10403cc4;
                  goto LAB_97be0794;
                }
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                *puVar16 = 0x10603cc4;
                puVar11 = puVar16 + 1;
                *(uint **)(param_1 + 0xe30) = puVar11;
                if (uVar23 != 5) {
                  uVar19 = 0x10430000;
                  goto LAB_97be1338;
                }
                uVar23 = 0x10430000;
                goto LAB_97be132c;
              case 7:
                if (uVar20 != 4) {
                  if (uVar20 != 7) {
                    puVar11 = *(uint **)(param_1 + 0xe30);
                    uVar6 = 0x10403cc4;
                    goto LAB_97be0ad4;
                  }
                  if ((uVar19 == 7) && (uVar19 = 0xffffffff, uVar23 == 7)) {
                    uVar23 = 0xffffffff;
                  }
                  puVar16 = *(undefined4 **)(param_1 + 0xe30);
                  uVar13 = 0x10603cc4;
                  uVar20 = 0x10431a8c;
                  goto LAB_97be0e64;
                }
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                *puVar16 = 0x10603cc4;
                puVar11 = puVar16 + 1;
                *(uint **)(param_1 + 0xe30) = puVar11;
                if (uVar19 != 5) {
                  uVar20 = 0x10430000;
                  goto LAB_97be0fb8;
                }
                uVar19 = 0x10430000;
                if (uVar23 != 6) goto LAB_97be0fac;
                uVar23 = 0x10430000;
                goto LAB_97be0ab4;
              case 8:
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                *puVar16 = 0x10484484;
                *(undefined4 **)(param_1 + 0xe30) = puVar16 + 1;
                if (uVar20 != 8) break;
                if (uVar19 != 8) goto switchD_97be0ba4_default;
                bVar1 = uVar23 == 8;
LAB_97be0b40:
                if (bVar1) goto switchD_97bdfc38_caseD_6;
                goto switchD_97be0fe8_default;
              case 9:
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                *puVar16 = 0x1040038c;
                *(undefined4 **)(param_1 + 0xe30) = puVar16 + 1;
                if (uVar20 != 9) break;
                if (uVar19 == 9) {
                  bVar1 = uVar23 == 9;
                  goto LAB_97be0b40;
                }
                goto switchD_97be0ba4_default;
              case 10:
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                *puVar16 = 0x10483cc4;
                *(undefined4 **)(param_1 + 0xe30) = puVar16 + 1;
                if (uVar20 == 10) {
                  uVar20 = 0xffffffff;
                  if (uVar19 != 10) goto switchD_97be0ba4_default;
                  uVar19 = 0xffffffff;
                  if (uVar23 != 10) goto switchD_97be0fe8_default;
                  uVar23 = 0xffffffff;
                }
              }
              switch(uVar20) {
              case 0:
                if (uVar19 == 0) {
                  bVar1 = uVar23 == 0;
                  puVar11 = *(uint **)(param_1 + 0xe30);
                  uVar19 = 0x10600000;
LAB_97be0c50:
                  uVar19 = uVar19 | 0x28c;
                  goto LAB_97be0c54;
                }
                if (uVar19 != 1) {
                  puVar11 = *(uint **)(param_1 + 0xe30);
                  uVar20 = 0x10420000;
LAB_97be0c28:
                  uVar20 = uVar20 | 300;
                  goto LAB_97be0794;
                }
                if (uVar23 != 2) {
                  puVar12 = *(uint **)(param_1 + 0xe30);
                  uVar19 = 0x10420000;
LAB_97be0c18:
                  uVar19 = uVar19 | 0x22c;
                  goto LAB_97be077c;
                }
                puVar12 = *(uint **)(param_1 + 0xe30);
                uVar23 = 0x10420000;
LAB_97be0c08:
                uVar23 = uVar23 | 0x32c;
                goto LAB_97be1470;
              case 1:
                if (uVar19 == 1) {
                  bVar1 = uVar23 == 1;
                  puVar11 = *(uint **)(param_1 + 0xe30);
                  uVar19 = 0x10610000;
                  goto LAB_97be0c50;
                }
                if (uVar19 != 2) {
                  puVar16 = *(undefined4 **)(param_1 + 0xe30);
                  uVar13 = 0x1060012c;
                  goto LAB_97be0e60;
                }
                bVar1 = uVar23 == 3;
                puVar11 = *(uint **)(param_1 + 0xe30);
                uVar19 = 0x1060012c;
                goto LAB_97be0c54;
              case 2:
                if (uVar19 == 2) {
                  bVar1 = uVar23 == 2;
                  puVar11 = *(uint **)(param_1 + 0xe30);
                  uVar19 = 0x10620000;
                  goto LAB_97be0c50;
                }
                if (uVar19 != 3) {
                  puVar16 = *(undefined4 **)(param_1 + 0xe30);
                  uVar13 = 0x1060022c;
                  goto LAB_97be0e60;
                }
                bVar1 = uVar23 == 0;
                puVar11 = *(uint **)(param_1 + 0xe30);
                uVar19 = 0x1060022c;
                goto LAB_97be0c54;
              case 3:
                if (uVar19 != 0) {
                  if (uVar19 != 3) {
                    puVar16 = *(undefined4 **)(param_1 + 0xe30);
                    uVar13 = 0x1060032c;
                    goto LAB_97be0e60;
                  }
                  bVar1 = uVar23 == 3;
                  puVar11 = *(uint **)(param_1 + 0xe30);
                  uVar19 = 0x10630000;
                  goto LAB_97be0c50;
                }
                bVar1 = uVar23 == 1;
                puVar11 = *(uint **)(param_1 + 0xe30);
                uVar19 = 0x1060032c;
LAB_97be0c54:
                *puVar11 = uVar19;
                puVar11 = puVar11 + 1;
                *(uint **)(param_1 + 0xe30) = puVar11;
LAB_97be0f9c:
                if (!bVar1) {
                  uVar19 = 0x10420000;
LAB_97be0fac:
                  uVar19 = uVar19 | 0x1a2c;
                  goto LAB_97be133c;
                }
                uVar23 = 0x10420000;
LAB_97be0ab4:
                uVar23 = uVar23 | 0x1b2c;
                goto LAB_97be181c;
              case 4:
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                *puVar16 = 0x10603cc4;
                puVar11 = puVar16 + 1;
                *(uint **)(param_1 + 0xe30) = puVar11;
                if (uVar19 == 4) {
                  bVar1 = uVar23 == 4;
                  uVar19 = 0x10600000;
LAB_97be0da4:
                  *puVar11 = uVar19 | 0x1a8c;
                  goto LAB_97be0e24;
                }
                if (uVar19 == 5) {
                  bVar1 = uVar23 == 6;
                  goto LAB_97be0f9c;
                }
                puVar11 = *(uint **)(param_1 + 0xe30);
                uVar20 = 0x1042192c;
LAB_97be0794:
                *puVar11 = uVar20;
                break;
              case 5:
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                *puVar16 = 0x10603cc4;
                puVar11 = puVar16 + 1;
                *(uint **)(param_1 + 0xe30) = puVar11;
                if (uVar19 == 5) {
                  bVar1 = uVar23 == 5;
                  uVar19 = 0x10610000;
                  goto LAB_97be0da4;
                }
                if (uVar19 != 6) {
                  puVar16 = *(undefined4 **)(param_1 + 0xe30);
                  uVar13 = 0x1063192c;
                  goto LAB_97be0e60;
                }
                bVar1 = uVar23 == 7;
                uVar19 = 0x1063192c;
LAB_97be0e1c:
                *puVar11 = uVar19;
LAB_97be0e24:
                *(uint **)(param_1 + 0xe30) = puVar11 + 1;
                if (!bVar1) {
                  puVar12 = puVar11 + 2;
                  puVar11[1] = 0x10421a2c;
                  goto LAB_97be1344;
                }
                uVar23 = 0x10421b2c;
                goto LAB_97be1418;
              case 6:
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                *puVar16 = 0x10603cc4;
                puVar11 = puVar16 + 1;
                *(uint **)(param_1 + 0xe30) = puVar11;
                if (uVar19 == 6) {
                  bVar1 = uVar23 == 6;
                  uVar19 = 0x10620000;
                  goto LAB_97be0da4;
                }
                if (uVar19 == 7) {
                  bVar1 = uVar23 == 4;
                  uVar19 = 0x10631a2c;
                  goto LAB_97be0e1c;
                }
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                uVar13 = 0x10631a2c;
LAB_97be0e60:
                uVar20 = 0x1042192c;
LAB_97be0e64:
                *puVar16 = uVar13;
                puVar11 = puVar16 + 1;
                *puVar11 = uVar20;
                break;
              case 7:
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                *puVar16 = 0x10603cc4;
                puVar18 = puVar16 + 1;
                *(undefined4 **)(param_1 + 0xe30) = puVar18;
                if (uVar19 == 4) {
                  bVar1 = uVar23 == 5;
                  uVar13 = 0x10631b2c;
                }
                else {
                  if (uVar19 != 7) {
                    *puVar18 = 0x10631b2c;
                    puVar16[2] = 0x1042192c;
                    *(undefined4 **)(param_1 + 0xe30) = puVar16 + 3;
                    goto switchD_97be0ba4_default;
                  }
                  bVar1 = uVar23 == 7;
                  uVar13 = 0x10631a8c;
                }
                *puVar18 = uVar13;
                *(undefined4 **)(param_1 + 0xe30) = puVar16 + 2;
                if (bVar1) {
                  puVar12 = puVar16 + 3;
                  puVar16[2] = 0x10421b2c;
                  goto LAB_97be1820;
                }
                puVar12 = puVar16 + 3;
                puVar16[2] = 0x10421a2c;
                goto LAB_97be1344;
              case 8:
                if (uVar19 != 8) {
                  puVar11 = *(uint **)(param_1 + 0xe30);
                  uVar20 = 0x1042412c;
                  goto LAB_97be0794;
                }
                if (uVar23 == 8) {
                  puVar12 = *(uint **)(param_1 + 0xe30);
                  uVar23 = 0x1042432c;
                  goto LAB_97be1470;
                }
                puVar12 = *(uint **)(param_1 + 0xe30);
                uVar19 = 0x1042422c;
                goto LAB_97be077c;
              case 9:
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                *puVar16 = 0x1060038c;
                puVar11 = puVar16 + 1;
                *(uint **)(param_1 + 0xe30) = puVar11;
                if (uVar19 == 9) {
                  bVar1 = uVar23 == 9;
                  goto LAB_97be0f9c;
                }
LAB_97be0fb4:
                uVar20 = 0x10420000;
LAB_97be0fb8:
                *puVar11 = uVar20 | 0x192c;
                break;
              case 10:
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                *puVar16 = 0x10683cc4;
                puVar11 = puVar16 + 1;
                *(uint **)(param_1 + 0xe30) = puVar11;
                if (uVar19 != 10) goto LAB_97be0fb4;
                bVar1 = uVar23 == 10;
                goto LAB_97be0f9c;
              default:
                goto switchD_97be0ba4_default;
              }
              *(uint **)(param_1 + 0xe30) = puVar11 + 1;
switchD_97be0ba4_default:
              switch(uVar19) {
              case 0:
                if (uVar23 == 0) {
                  puVar12 = *(uint **)(param_1 + 0xe30);
                  uVar23 = 0x10600000;
LAB_97be1074:
                  uVar23 = uVar23 | 0x28c;
                  goto LAB_97be107c;
                }
                if (uVar23 != 1) {
                  puVar12 = *(uint **)(param_1 + 0xe30);
                  uVar19 = 0x10420000;
LAB_97be1050:
                  uVar19 = uVar19 | 300;
                  goto LAB_97be077c;
                }
                puVar12 = *(uint **)(param_1 + 0xe30);
                uVar23 = 0x10420000;
LAB_97be1040:
                uVar23 = uVar23 | 0x22c;
                goto LAB_97be1470;
              case 1:
                if (uVar23 == 1) {
                  puVar12 = *(uint **)(param_1 + 0xe30);
                  uVar23 = 0x10610000;
                  goto LAB_97be1074;
                }
                if (uVar23 == 2) {
                  puVar12 = *(uint **)(param_1 + 0xe30);
                  uVar23 = 0x1060012c;
                  goto LAB_97be107c;
                }
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                uVar13 = 0x1060012c;
LAB_97be1244:
                uVar19 = 0x1042192c;
LAB_97be1248:
                *puVar16 = uVar13;
                puVar12 = puVar16 + 1;
                *puVar12 = uVar19;
                goto LAB_97be0780;
              case 2:
                if (uVar23 == 2) {
                  puVar12 = *(uint **)(param_1 + 0xe30);
                  uVar23 = 0x10620000;
                  goto LAB_97be1074;
                }
                if (uVar23 != 3) {
                  puVar16 = *(undefined4 **)(param_1 + 0xe30);
                  uVar13 = 0x1060022c;
                  goto LAB_97be1244;
                }
                puVar12 = *(uint **)(param_1 + 0xe30);
                uVar23 = 0x1060022c;
                goto LAB_97be107c;
              case 3:
                if (uVar23 != 0) {
                  if (uVar23 != 3) {
                    puVar16 = *(undefined4 **)(param_1 + 0xe30);
                    uVar13 = 0x1060032c;
                    goto LAB_97be1244;
                  }
                  puVar12 = *(uint **)(param_1 + 0xe30);
                  uVar23 = 0x10630000;
                  goto LAB_97be1074;
                }
                puVar12 = *(uint **)(param_1 + 0xe30);
                uVar23 = 0x1060032c;
LAB_97be107c:
                uVar19 = 0x10421a2c;
                goto LAB_97be148c;
              case 4:
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                *puVar16 = 0x10603cc4;
                puVar11 = puVar16 + 1;
                *(uint **)(param_1 + 0xe30) = puVar11;
                if (uVar23 == 4) {
                  uVar19 = 0x10600000;
LAB_97be11c0:
                  uVar19 = uVar19 | 0x1a8c;
                  goto LAB_97be1290;
                }
                if (uVar23 != 5) {
                  puVar12 = *(uint **)(param_1 + 0xe30);
                  uVar19 = 0x1042192c;
                  goto LAB_97be077c;
                }
                puVar12 = puVar16 + 2;
                *puVar11 = 0x10421a2c;
                goto LAB_97be1820;
              case 5:
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                *puVar16 = 0x10603cc4;
                puVar11 = puVar16 + 1;
                *(uint **)(param_1 + 0xe30) = puVar11;
                if (uVar23 == 5) {
                  uVar19 = 0x10610000;
                  goto LAB_97be11c0;
                }
                if (uVar23 != 6) {
                  puVar16 = *(undefined4 **)(param_1 + 0xe30);
                  uVar13 = 0x1063192c;
                  goto LAB_97be1244;
                }
                uVar19 = 0x1063192c;
                goto LAB_97be1290;
              case 6:
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                *puVar16 = 0x10603cc4;
                puVar11 = puVar16 + 1;
                *(uint **)(param_1 + 0xe30) = puVar11;
                if (uVar23 == 6) {
                  uVar19 = 0x10620000;
                  goto LAB_97be11c0;
                }
                if (uVar23 != 7) {
                  puVar16 = *(undefined4 **)(param_1 + 0xe30);
                  uVar13 = 0x10631a2c;
                  goto LAB_97be1244;
                }
                uVar19 = 0x10631a2c;
LAB_97be1290:
                *puVar11 = uVar19;
                puVar11[1] = 0x10421a2c;
                *(uint **)(param_1 + 0xe30) = puVar11 + 2;
                goto switchD_97bdfc38_caseD_6;
              case 7:
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                *puVar16 = 0x10603cc4;
                puVar11 = puVar16 + 1;
                *(uint **)(param_1 + 0xe30) = puVar11;
                if (uVar23 == 4) {
                  uVar19 = 0x10631b2c;
                  goto LAB_97be1290;
                }
                uVar19 = 0x10630000;
                if (uVar23 == 7) goto LAB_97be11c0;
                *puVar11 = 0x10631b2c;
                puVar16[2] = 0x1042192c;
                *(undefined4 **)(param_1 + 0xe30) = puVar16 + 3;
                break;
              case 8:
                if (uVar23 == 8) {
                  puVar12 = *(uint **)(param_1 + 0xe30);
                  uVar23 = 0x1042422c;
                  goto LAB_97be1470;
                }
                puVar12 = *(uint **)(param_1 + 0xe30);
                uVar19 = 0x1042412c;
LAB_97be077c:
                *puVar12 = uVar19;
LAB_97be0780:
                puVar12 = puVar12 + 1;
LAB_97be1344:
                *(uint **)(param_1 + 0xe30) = puVar12;
                break;
              case 9:
                bVar1 = uVar23 == 9;
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                uVar13 = 0x1060038c;
                goto LAB_97be1318;
              case 10:
                bVar1 = uVar23 == 10;
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                uVar13 = 0x10683cc4;
LAB_97be1318:
                *puVar16 = uVar13;
                puVar11 = puVar16 + 1;
                *(uint **)(param_1 + 0xe30) = puVar11;
                if (!bVar1) {
                  uVar19 = 0x10420000;
LAB_97be1338:
                  uVar19 = uVar19 | 0x192c;
LAB_97be133c:
                  puVar12 = puVar11 + 1;
                  *puVar11 = uVar19;
                  goto LAB_97be1344;
                }
                uVar23 = 0x10420000;
LAB_97be132c:
                uVar23 = uVar23 | 0x1a2c;
LAB_97be181c:
                puVar12 = puVar11 + 1;
                *puVar11 = uVar23;
                goto LAB_97be1820;
              }
switchD_97be0fe8_default:
              switch(uVar23) {
              case 0:
                puVar12 = *(uint **)(param_1 + 0xe30);
                uVar23 = 0x10420000;
LAB_97be13a0:
                uVar23 = uVar23 | 300;
                goto LAB_97be1470;
              case 1:
                puVar12 = *(uint **)(param_1 + 0xe30);
                uVar19 = 0x10420000;
                uVar23 = 0x1060012c;
                break;
              case 2:
                puVar12 = *(uint **)(param_1 + 0xe30);
                uVar19 = 0x10420000;
                uVar23 = 0x1060022c;
                break;
              case 3:
                puVar12 = *(uint **)(param_1 + 0xe30);
                uVar19 = 0x10420000;
                uVar23 = 0x1060032c;
                break;
              case 4:
                puVar12 = *(uint **)(param_1 + 0xe30);
                uVar23 = 0x10600000;
                goto LAB_97be1480;
              case 5:
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                uVar23 = 0x1063192c;
                goto LAB_97be1404;
              case 6:
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                uVar23 = 0x10631a2c;
                goto LAB_97be1404;
              case 7:
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                uVar23 = 0x10631b2c;
LAB_97be1404:
                *puVar16 = 0x10603cc4;
                puVar11 = puVar16 + 1;
                *puVar11 = uVar23;
                uVar23 = 0x1042192c;
LAB_97be1418:
                puVar12 = puVar11 + 2;
                puVar11[1] = uVar23;
                goto LAB_97be1820;
              case 8:
                puVar12 = *(uint **)(param_1 + 0xe30);
                uVar23 = 0x1042412c;
LAB_97be1470:
                *puVar12 = uVar23;
                goto LAB_97be1494;
              case 9:
                puVar12 = *(uint **)(param_1 + 0xe30);
                uVar19 = 0x10420000;
                uVar23 = 0x1060038c;
                break;
              case 10:
                puVar12 = *(uint **)(param_1 + 0xe30);
                uVar23 = 0x10680000;
LAB_97be1480:
                uVar19 = 0x10420000;
LAB_97be1484:
                uVar23 = uVar23 | 0x3cc4;
                break;
              default:
                goto switchD_97bdfc38_caseD_6;
              }
              uVar19 = uVar19 | 0x192c;
LAB_97be148c:
              *puVar12 = uVar23;
              puVar12 = puVar12 + 1;
              *puVar12 = uVar19;
LAB_97be1494:
              puVar12 = puVar12 + 1;
LAB_97be1820:
              *(uint **)(param_1 + 0xe30) = puVar12;
              goto switchD_97bdfc38_caseD_6;
            case 0x42:
            case 0x43:
            case 0x44:
            case 0x45:
              iVar7 = *(int *)(param_1 + 0xe20);
              if (*(int *)(*(int *)(iVar7 + 0xd80) + 0x38) - 0x8b30U < 2) {
                uVar13 = *(undefined4 *)
                          (*(int *)((uint)*(ushort *)(*(int *)(param_1 + 0xe28) + 0x68) * 4 + iVar7
                                   + 0xd84) + **(int **)(*(int *)(param_1 + 0xe28) + 0x58));
              }
              else {
                uVar13 = *(undefined4 *)(*(int *)(param_1 + 0xe28) + 0x10c);
              }
              ((int (*)())_PPCTextureSamplerAttachGLDContext)(*(undefined4 *)(param_1 + 0xe1c),*(undefined4 *)(iVar7 + 0xd9c));
              uVar15 = 0;
              if ((iVar5 == 0x43) || (iVar5 == 0x45)) {
                uVar15 = 1;
              }
              ((int (*)())_PPCTextureSamplerSetProjectionEnabled)(*(undefined4 *)(param_1 + 0xe1c),uVar15);
              ((int (*)())_PPCTextureSamplerSetLodBiasEnabled)(*(undefined4 *)(param_1 + 0xe1c),iVar5 - 0x44U < 2);
              if (((iVar5 == 0x44) &&
                  (iVar7 = *(int *)(*(int *)(*(int *)(param_1 + 0xe20) + 0xd80) + 0x38),
                  iVar7 != 0x8b30)) && (iVar7 != 0x8b31)) {
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                *puVar16 = 0x1043028c;
                puVar16[1] = 0x1000436a;
                *(undefined4 **)(param_1 + 0xe30) = puVar16 + 2;
              }
              uVar23 = *(uint *)(*(int *)(param_1 + 0xe28) + 0x110);
              if (uVar23 == 2) {
                uVar13 = _PPCTextureSamplerSampleTexelRECTRTCAV
                                   (*(undefined4 *)(param_1 + 0xe1c),uVar13,
                                    *(undefined4 *)(param_1 + 0xe30));
              }
              else if (uVar23 < 3) {
                if (uVar23 != 1) goto switchD_97bdfc38_caseD_6;
                uVar13 = _PPCTextureSamplerSampleTexel3DRTCAV
                                   (*(undefined4 *)(param_1 + 0xe1c),uVar13,
                                    *(undefined4 *)(param_1 + 0xe30));
              }
              else if (uVar23 == 3) {
                uVar13 = _PPCTextureSamplerSampleTexel2DRTCAV
                                   (*(undefined4 *)(param_1 + 0xe1c),uVar13,
                                    *(undefined4 *)(param_1 + 0xe30));
              }
              else {
                if (uVar23 != 4) goto switchD_97bdfc38_caseD_6;
                uVar13 = _PPCTextureSamplerSampleTexel1DRTCAV
                                   (*(undefined4 *)(param_1 + 0xe1c),uVar13,
                                    *(undefined4 *)(param_1 + 0xe30));
              }
LAB_97be1634:
              *(undefined4 *)(param_1 + 0xe30) = uVar13;
              goto switchD_97bdfc38_caseD_6;
            case 0x48:
              if ((*(byte *)(*(int *)(param_1 + 0xe28) + 0x28) & 1) != 0) {
                iVar7 = ((int (*)())_glpRTCAddAChunk)(&_glpOpArlAVRTC,*(undefined4 *)(param_1 + 0xe30));
                *(int *)(param_1 + 0xe30) = *(int *)(param_1 + 0xe30) + iVar7 * 4;
              }
            case 0x49:
            case 0x4a:
            case 0x4c:
            case 0x4f:
            case 0x56:
            case 0x57:
            case 0x59:
            case 0x5a:
            case 0x5b:
            case 0x6a:
              goto switchD_97bdfc38_caseD_49;
            case 0x4b:
              iVar7 = *(int *)(param_1 + 0xe28);
              ((int (*)())_PPCRuntimeCompilerTestConditionRegisterAV)(param_1,*(undefined4 *)(iVar7 + 0xc),*(undefined4 *)(iVar7 + 0x10),
                         *(undefined4 *)(iVar7 + 0x14),*(undefined4 *)(iVar7 + 0x18),
                         *(undefined4 *)(iVar7 + 0x1c),*(undefined4 *)(iVar7 + 0x20),
                         *(undefined4 *)(iVar7 + 0x24));
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              *puVar16 = 0x10634e86;
              puVar16[1] = 0x4098000c;
              puVar16[2] = 0x419a0008;
              puVar16 = puVar16 + 3;
              goto LAB_97be16ec;
            case 0x4d:
              puVar11 = *(uint **)(param_1 + 0xe30);
              *puVar11 = *(int *)(param_1 + 0xe40) - (int)puVar11 & 0x3fffffcU | 0x48000000;
              *(uint **)(param_1 + 0xe30) = puVar11 + 1;
              goto switchD_97bdfc38_caseD_49;
            case 0x54:
            case 0x58:
              piVar8 = *(int **)(*(int *)(param_1 + 0xe20) + 0xd80);
              iVar7 = *piVar8 + *(int *)(*(int *)(param_1 + 0xe28) + 8) * 0x11c;
              if ((uint)piVar8[1] < iVar7 - 0x11cU) {
                puVar11 = *(uint **)(param_1 + 0xe30);
                uVar23 = *(int *)(param_1 + 0xe40) - (int)puVar11;
              }
              else {
                puVar11 = *(uint **)(param_1 + 0xe30);
                uVar23 = *(int *)(iVar7 + -4) - ((int)puVar11 - *(int *)(param_1 + 0xe2c));
              }
              *puVar11 = uVar23 & 0x3fffffc | 0x48000000;
              goto LAB_97be17b0;
            case 0x55:
              puVar18 = *(undefined4 **)(param_1 + 0xe30);
              puVar18[1] = 0x40980008;
              puVar16 = puVar18 + 2;
              *puVar18 = 0x10604cc6;
LAB_97be16ec:
              *(undefined4 **)(param_1 + 0xe30) = puVar16;
              piVar8 = *(int **)(*(int *)(param_1 + 0xe20) + 0xd80);
              iVar7 = *piVar8 + *(int *)(*(int *)(param_1 + 0xe28) + 8) * 0x11c;
              if ((uint)piVar8[1] < iVar7 - 0x11cU) {
                uVar23 = *(int *)(param_1 + 0xe40) - (int)puVar16;
              }
              else {
                uVar23 = *(int *)(iVar7 + -4) - ((int)puVar16 - *(int *)(param_1 + 0xe2c));
              }
              puVar11 = *(uint **)(param_1 + 0xe30);
              *puVar11 = uVar23 & 0x3fffffc | 0x48000000;
LAB_97be17b0:
              *(uint **)(param_1 + 0xe30) = puVar11 + 1;
switchD_97bdfc38_caseD_49:
              bVar4 = false;
              goto LAB_97be1860;
            case 0x68:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpRefractAVRTC;
              break;
            case 0x6b:
              piVar8 = *(int **)(*(int *)(param_1 + 0xe20) + 0xd80);
              iVar7 = *piVar8 + *(int *)(*(int *)(param_1 + 0xe28) + 8) * 0x11c;
              if ((uint)piVar8[1] < iVar7 - 0x11cU) {
                puVar11 = *(uint **)(param_1 + 0xe30);
                uVar23 = *(int *)(param_1 + 0xe40) - (int)puVar11;
              }
              else {
                puVar11 = *(uint **)(param_1 + 0xe30);
                uVar23 = *(int *)(iVar7 + -4) - ((int)puVar11 - *(int *)(param_1 + 0xe2c));
              }
              uVar23 = uVar23 & 0x3fffffc | 0x48000000;
              bVar4 = false;
              goto LAB_97be181c;
            case 0x6c:
              iVar7 = *(int *)(param_1 + 0xe28);
              if ((*(int *)(iVar7 + 0x24) == 3) && (*(int *)(iVar7 + 0x4c) == 1)) {
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                puVar14 = &_glpOpTruncateAVRTC;
              }
              else {
                if ((*(int *)(iVar7 + 0x24) != 4) ||
                   ((*(int *)(iVar7 + 0x4c) != 1 && (*(int *)(iVar7 + 0x4c) != 3))))
                goto switchD_97bdfc38_caseD_0;
                puVar16 = *(undefined4 **)(param_1 + 0xe30);
                puVar14 = &_glpOpSetNotEqualToZeroAVRTC;
              }
              break;
            case 0x6d:
              puVar16 = *(undefined4 **)(param_1 + 0xe30);
              puVar14 = &_glpOpDestinationScalarSelectAVRTC;
              break;
            case 0x6f:
              puVar18 = *(undefined4 **)(param_1 + 0xe30);
              *puVar18 = 0x39e001b0;
              puVar18[1] = 0x7c6378ce;
              puVar16 = puVar18 + 3;
              puVar18[2] = 0x100038ee;
              puVar14 = &_glpOpEx2AVRTC;
              *(undefined4 **)(param_1 + 0xe30) = puVar16;
              break;
            case 0x70:
              iVar7 = ((int (*)())_glpRTCAddAChunk)(&_glpOpLg2AVRTC,*(undefined4 *)(param_1 + 0xe30));
              iVar17 = *(int *)(param_1 + 0xe30) + iVar7 * 4;
              *(undefined4 *)(*(int *)(param_1 + 0xe30) + iVar7 * 4) = 0x39e001c0;
              *(undefined4 *)(iVar17 + 4) = 0x7c6378ce;
              *(undefined4 *)(iVar17 + 8) = 0x104238ee;
              *(int *)(param_1 + 0xe30) = iVar17 + 0xc;
              goto switchD_97bdfc38_caseD_6;
            }
            iVar7 = ((int (*)())_glpRTCAddAChunk)(puVar14,puVar16);
            *(int *)(param_1 + 0xe30) = *(int *)(param_1 + 0xe30) + iVar7 * 4;
switchD_97bdfc38_caseD_6:
            if (bVar4) {
              if (cVar2 != '\0') {
                iVar7 = ((int (*)())_glpRTCAddAChunk)(&_glpOpSaturateAVRTC,*(undefined4 *)(param_1 + 0xe30));
                *(int *)(param_1 + 0xe30) = *(int *)(param_1 + 0xe30) + iVar7 * 4;
              }
              ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(param_1,uVar10);
            }
LAB_97be1860:
            uVar10 = uVar10 + 1;
          } while (uVar10 < uVar22);
        }
        iVar7 = *(int *)(param_1 + 0xe2c);
        if (iVar21 - 3000U < (uint)(*(int *)(param_1 + 0xe30) - iVar7)) {
          iVar21 = iVar21 + 0x2000;
          iVar5 = _glpDCBRealloc(iVar7,iVar21);
          *(int *)(param_1 + 0xe2c) = iVar5;
          iVar7 = iVar5 - iVar7 >> 2;
          if (iVar7 != 0) {
            iVar7 = iVar7 * 4;
            *(int *)(param_1 + 0xe30) = *(int *)(param_1 + 0xe30) + iVar7;
            *(int *)(param_1 + 0xe34) = *(int *)(param_1 + 0xe34) + iVar7;
            *(int *)(param_1 + 0xe38) = *(int *)(param_1 + 0xe38) + iVar7;
            *(int *)(param_1 + 0xe3c) = *(int *)(param_1 + 0xe3c) + iVar7;
            *(int *)(param_1 + 0xe40) = *(int *)(param_1 + 0xe40) + iVar7;
          }
        }
LAB_97be18e4:
        iVar17 = *(int *)(param_1 + 0xe28);
      }
      iVar7 = *(int *)(param_1 + 0xe24);
      iVar5 = iVar17 + 0x11c;
      if (iVar17 == *(int *)(iVar7 + 4)) {
        iVar5 = 0;
      }
      *(int *)(param_1 + 0xe28) = iVar5;
    }
    iVar5 = *(int *)(param_1 + 0xe48);
    if (iVar5 == 0) {
      *(undefined4 **)(param_1 + 0xe40) = *(undefined4 **)(param_1 + 0xe30);
      puVar16 = *(undefined4 **)(param_1 + 0xe30);
      while (((uint)puVar16 & 0xf) != 0) {
        *puVar16 = 0x60000000;
        *(undefined4 **)(param_1 + 0xe30) = puVar16 + 1;
        puVar16 = puVar16 + 1;
      }
      ((int (*)())_PPCRuntimeCompilerInitialise)(param_1,1);
      uVar13 = *(undefined4 *)(param_1 + 0xe34);
LAB_97be1ac8:
      iVar5 = *(int *)(param_1 + 0xe48);
      *(undefined4 *)(param_1 + 0xe30) = uVar13;
    }
    else if (iVar5 == 1) {
      ((int (*)())_PPCRuntimeCompilerBackupRegister)(param_1,0);
      ((int (*)())_PPCRuntimeCompilerBackupRegister)(param_1,1);
      ((int (*)())_PPCRuntimeCompilerBackupRegister)(param_1,2);
      ((int (*)())_PPCRuntimeCompilerDirtyRegistersContainingAttributes)(param_1);
      ((int (*)())_PPCRuntimeCompilerDirtyRegistersContainingTemps)(param_1);
      ((int (*)())_PPCRuntimeCompilerDirtyRegistersContainingParams)(param_1);
      puVar16 = *(undefined4 **)(param_1 + 0xe30);
      while (((uint)puVar16 & 0xf) != 0) {
        *puVar16 = 0x60000000;
        *(undefined4 **)(param_1 + 0xe30) = puVar16 + 1;
        puVar16 = puVar16 + 1;
      }
      ((int (*)())_PPCRuntimeCompilerInitialiseVariableInfo)(param_1);
      iVar5 = *(int *)(param_1 + 0xe48);
      *(undefined4 *)(param_1 + 0xe38) = *(undefined4 *)(param_1 + 0xe30);
    }
    else {
      if (iVar5 == 2) {
        iVar5 = *(int *)(param_1 + 0xe30);
        *(int *)(param_1 + 0xe40) = iVar5;
        if ((*(int *)(iVar7 + 0x38) == 0x8804) || (*(int *)(iVar7 + 0x38) == 0x8b30)) {
          if ((*(uint *)(iVar7 + 0x34) & 2) != 0) {
            ((int (*)())_PPCRuntimeCompilerWriteFinalFragmentToBuffer)(param_1);
            iVar5 = *(int *)(param_1 + 0xe30);
          }
        }
        else {
          ((int (*)())_PPCRuntimeCompilerBackupRegister)(param_1,0);
          puVar16 = *(undefined4 **)(param_1 + 0xe30);
          *puVar16 = 0x39e00010;
          puVar16[1] = 0x7c0678ce;
          *(undefined4 **)(param_1 + 0xe30) = puVar16 + 2;
          iVar7 = ((int (*)())_glpRTCAddAChunk)(&_glpOpClippingAVRTC);
          iVar5 = *(int *)(param_1 + 0xe30) + iVar7 * 4;
          *(int *)(param_1 + 0xe30) = iVar5;
        }
        *(int *)(param_1 + 0xe3c) = iVar5;
        ((int (*)())_PPCRuntimeCompilerBackupRegister)(param_1,0);
        ((int (*)())_PPCRuntimeCompilerBackupRegister)(param_1,1);
        ((int (*)())_PPCRuntimeCompilerBackupRegister)(param_1,2);
        ((int (*)())_PPCRuntimeCompilerDirtyRegistersContainingAttributes)(param_1);
        ((int (*)())_PPCRuntimeCompilerDirtyRegistersContainingTemps)(param_1);
        ((int (*)())_PPCRuntimeCompilerDirtyRegistersContainingParams)(param_1);
        ((int (*)())_PPCRuntimeCompilerInitialiseVariableInfo)(param_1);
        uVar13 = *(undefined4 *)(param_1 + 0xe38);
        goto LAB_97be1ac8;
      }
      if (iVar5 == 3) {
        if ((*(int *)(iVar7 + 0x38) == 0x8804) || (*(int *)(iVar7 + 0x38) == 0x8b30)) {
          if ((*(uint *)(iVar7 + 0x34) & 2) != 0) {
            ((int (*)())_PPCRuntimeCompilerWriteFinalFragmentToBuffer)(param_1);
          }
        }
        else {
          ((int (*)())_PPCRuntimeCompilerBackupRegister)(param_1,0);
          puVar16 = *(undefined4 **)(param_1 + 0xe30);
          *puVar16 = 0x39e00010;
          puVar16[1] = 0x7c0678ce;
          *(undefined4 **)(param_1 + 0xe30) = puVar16 + 2;
          iVar7 = ((int (*)())_glpRTCAddAChunk)(&_glpOpClippingAVRTC);
          *(int *)(param_1 + 0xe30) = *(int *)(param_1 + 0xe30) + iVar7 * 4;
        }
        ((int (*)())_PPCRuntimeCompilerStride)(param_1);
        ((int (*)())_PPCRuntimeCompilerLoop)(param_1);
        iVar5 = *(int *)(param_1 + 0xe48);
      }
    }
    *(uint *)(param_1 + 0xe48) = iVar5 + 1U;
    if (3 < iVar5 + 1U) {
      ((int (*)())_PPCRuntimeCompilerWriteEpilogAV)(param_1);
      iVar21 = *(int *)(param_1 + 0xe30) - *(int *)(param_1 + 0xe2c) >> 2;
      uVar13 = _glpDCBRealloc(*(int *)(param_1 + 0xe2c),iVar21 << 2);
      *(undefined4 *)(param_1 + 0xe2c) = uVar13;
                    
                    
      (*_glpPushInstructions)(iVar21,uVar13);
      return;
    }
  } while( true );
}

/* _PPCRuntimeCompilerGetCompiledResult @ 0x97be1be0 (8 bytes) */
int _PPCRuntimeCompilerGetCompiledResult(param_1)
  int param_1;
{
  return *(undefined4 *)(param_1 + 0xe2c);
}

/* _PPCTextureSamplerCreate @ 0x97be1be8 (12 bytes) */
int _PPCTextureSamplerCreate()
{
  _calloc(0x2c,1);
  return;
}

/* _PPCTextureSamplerInitialise @ 0x97be1bf4 (16 bytes) */
int _PPCTextureSamplerInitialise(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0x18) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x14) = 0xffffffff;
  return;
}

/* _PPCTextureSamplerAttachGLDContext @ 0x97be1c08 (8 bytes) */
int _PPCTextureSamplerAttachGLDContext(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  *param_1 = param_2;
  return;
}

/* _PPCTextureSamplerSetProjectionEnabled @ 0x97be1c10 (8 bytes) */
int _PPCTextureSamplerSetProjectionEnabled(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(param_1 + 0x20) = param_2;
  return;
}

/* _PPCTextureSamplerSetLodBiasEnabled @ 0x97be1c18 (8 bytes) */
int _PPCTextureSamplerSetLodBiasEnabled(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(param_1 + 0x24) = param_2;
  return;
}

/* _PPCTextureSamplerAttachDerivatives @ 0x97be1c20 (12 bytes) */
void _PPCTextureSamplerAttachDerivatives(double param_1,int param_2,undefined4 param_3)

{
  *(float *)(param_2 + 0x10) = (float)param_1;
  *(undefined4 *)(param_2 + 0xc) = param_3;
  return;
}

/* _glpRTCAddAChunk_97be1c2c @ 0x97be1c2c (48 bytes) */
int _glpRTCAddAChunk_97be1c2c(param_1, param_2)
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

/* _PPCTextureSamplerSampleTexel1DRTCNO @ 0x97be1c5c (8 bytes) */
int _PPCTextureSamplerSampleTexel1DRTCNO(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  return param_3;
}

/* _PPCTextureSamplerSampleTexel2DRTCNO @ 0x97be1c64 (560 bytes) */
int _PPCTextureSamplerSampleTexel2DRTCNO(param_1, param_2, param_3)
  int *param_1;
  uint param_2;
  uint *param_3;
{
  short sVar1;
  short sVar2;
  uint uVar3;
  int *piVar4;
  undefined *puVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  
  if (7 < param_2) {
    param_2 = 7;
  }
  piVar4 = *(int **)(param_2 * 4 + *param_1);
  if (piVar4 != (int *)0x0) {
    param_1[1] = (int)piVar4;
    sVar1 = *(short *)(*piVar4 + 0x10);
    sVar2 = *(short *)(*piVar4 + 0x12);
    if ((sVar1 == -0x7ed3) || (sVar2 == -0x7ed3)) {
      iVar7 = 0x812d;
    }
    else if ((sVar1 == 0x2900) || (iVar7 = 0, sVar2 == 0x2900)) {
      iVar7 = 0x2900;
    }
    if (((param_1[5] != param_2) || (param_1[6] != 3)) || (param_1[7] != iVar7)) {
      *param_3 = param_2 * 4 & 0xfffc | 0x82220000;
      puVar8 = param_3 + 1;
      if (sVar1 == 0x2901) {
        *puVar8 = 0x82910160;
        puVar8 = param_3 + 2;
      }
      if (sVar2 == 0x2901) {
        *puVar8 = 0x82b10164;
        puVar8 = puVar8 + 1;
      }
      if (iVar7 == 0x812d) {
        *puVar8 = 0x82510190;
        puVar8[1] = 0xc1d10170;
        puVar8[2] = 0xc1f10174;
        uVar3 = 0x823101c4;
      }
      else if (iVar7 == 0x2900) {
        *puVar8 = 0x82510190;
        puVar8[1] = 0xc1d10170;
        puVar8[2] = 0xc1f10174;
        uVar3 = 0x823101c8;
      }
      else {
        *puVar8 = 0x82510140;
        puVar8[1] = 0xc1d10120;
        puVar8[2] = 0xc1f10124;
        uVar3 = 0x823101c0;
      }
      puVar8[3] = uVar3;
      param_3 = puVar8 + 4;
      param_1[7] = iVar7;
      param_1[5] = param_2;
      param_1[6] = 3;
    }
    if (sVar1 == 0x2901) {
      if (sVar2 == 0x2901) {
        puVar5 = &_glpOpTexPrepareCoords2RRRTC;
      }
      else {
        puVar5 = &_glpOpTexPrepareCoords2RCRTC;
      }
    }
    else if (sVar2 == 0x2901) {
      puVar5 = &_glpOpTexPrepareCoords2CRRTC;
    }
    else {
      puVar5 = &_glpOpTexPrepareCoords2CCRTC;
    }
    iVar7 = ((int (*)())_glpRTCAddAChunk)(puVar5,param_3);
    iVar6 = ((int (*)())_glpRTCAddAChunk)(&_glpOpTexSampleRTC,param_3 + iVar7);
    param_3 = param_3 + iVar7 + iVar6;
  }
  return param_3;
}

/* _PPCTextureSamplerSampleTexel3DRTCNO @ 0x97be1e94 (8 bytes) */
int _PPCTextureSamplerSampleTexel3DRTCNO(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  return param_3;
}

