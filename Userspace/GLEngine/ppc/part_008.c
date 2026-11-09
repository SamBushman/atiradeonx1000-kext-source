#include "decls.h"

/* _glClientActiveTexture_Exec @ 0x4f0b0 (88 bytes) */
int _glClientActiveTexture_Exec(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 - 0x84c0U < (uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0xba)) {
      *(uint *)(param_1 + 0x53d8) = param_2 - 0x84c0U;
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x500;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glLoadMatrixf_Exec @ 0x4f108 (128 bytes) */
int _glLoadMatrixf_Exec(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  if ((*(short *)(param_1 + 0x4a10) < 0) && (*(int *)(param_1 + 0x4ff4) < 0x18)) {
    param_2 = ((int (*)())_gleLoadMatrixf)(param_2,*(undefined4 *)(param_1 + 0x4fec));
    *(uint *)(param_1 + 0x50ac) = *(uint *)(param_1 + 0x50ac) | *(uint *)(param_1 + 0x50a8);
    *(uint *)(param_1 + 0x50b0) = *(uint *)(param_1 + 0x50b0) | *(uint *)(param_1 + 0x50a8);
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
  }
  return param_2;
}

/* _gleLoadMatrixf @ 0x4f188 (132 bytes) */
int _gleLoadMatrixf(param_1, param_2)
  undefined4 *param_1;
  undefined4 *param_2;
{
  *param_2 = *param_1;
  param_2[1] = param_1[1];
  param_2[2] = param_1[2];
  param_2[3] = param_1[3];
  param_2[4] = param_1[4];
  param_2[5] = param_1[5];
  param_2[6] = param_1[6];
  param_2[7] = param_1[7];
  param_2[8] = param_1[8];
  param_2[9] = param_1[9];
  param_2[10] = param_1[10];
  param_2[0xb] = param_1[0xb];
  param_2[0xc] = param_1[0xc];
  param_2[0xd] = param_1[0xd];
  param_2[0xe] = param_1[0xe];
  param_2[0xf] = param_1[0xf];
  return;
}

/* _glDisableClientState_Exec @ 0x4f20c (44 bytes) */
int _glDisableClientState_Exec(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  if (*(short *)(param_1 + 0x4a10) < 0) {
    _gleSetClientEnableFlag(param_1,param_2,0);
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x502;
  return;
}

/* _glColor4fv_NoColorMat_Exec @ 0x4f238 (36 bytes) */
int _glColor4fv_NoColorMat_Exec(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = param_2[1];
  uVar2 = param_2[2];
  uVar3 = param_2[3];
  *(undefined4 *)(param_1 + 0x2a0) = *param_2;
  *(undefined4 *)(param_1 + 0x2a4) = uVar1;
  *(undefined4 *)(param_1 + 0x2a8) = uVar2;
  *(undefined4 *)(param_1 + 0x2ac) = uVar3;
  return;
}

/* _gleSetEnable_TEXTURE_3D @ 0x4f25c (80 bytes) */
int _gleSetEnable_TEXTURE_3D(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = *(uint *)(param_1 + 0x53d4);
  if (uVar3 < 8) {
    iVar2 = uVar3 * 0x7c + param_1;
    uVar4 = *(uint *)(iVar2 + 0x3534);
    uVar1 = uVar4 & 0xfffffffd | param_3 << 1;
    if (uVar4 == uVar1) {
      return;
    }
    *(uint *)(iVar2 + 0x3534) = uVar1;
    _gleUpdateTextureParams(param_1,uVar3);
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x502;
  return;
}

/* _glProgramEnvParameter4fvARB_Exec @ 0x4f2ac (324 bytes) */
int _glProgramEnvParameter4fvARB_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  undefined4 *param_4;
{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (param_2 == 0x8620) {
    iVar5 = 0;
    if (param_3 < 0x100) {
      uVar2 = *(uint *)(param_1 + 0x31c) | 0x800000;
LAB_0004f340:
      *(uint *)(param_1 + 0x31c) = uVar2;
      if (*(int *)(param_1 + 0x5434) == 0) {
        bVar1 = *(byte *)(param_3 + *(int *)(param_1 + 0x5420) + 0x158);
      }
      else {
        bVar1 = *(byte *)(param_3 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x18c);
      }
      iVar6 = (bVar1 >> 3 & 0x1c) + param_1;
      iVar4 = *(int *)(param_1 + 0x5424);
      *(uint *)(iVar6 + 0x324) = *(uint *)(iVar6 + 0x324) | 1 << (bVar1 & 0x1f);
      bVar1 = *(byte *)(param_3 + iVar4 + 0x158);
      iVar4 = (bVar1 >> 3 & 0x1c) + param_1;
      *(uint *)(iVar4 + 0x348) = *(uint *)(iVar4 + 0x348) | 1 << (bVar1 & 0x1f);
      iVar5 = *(int *)(iVar5 * 8 + param_1 + 0x4668);
      *(undefined4 *)(iVar5 + param_3 * 0x10) = *param_4;
      iVar5 = iVar5 + param_3 * 0x10;
      *(undefined4 *)(iVar5 + 4) = param_4[1];
      *(undefined4 *)(iVar5 + 8) = param_4[2];
      *(undefined4 *)(iVar5 + 0xc) = param_4[3];
      return;
    }
  }
  else {
    if (param_2 < 0x8621) {
      uVar2 = 0x8200;
    }
    else {
      uVar2 = 0x8804;
    }
    if (param_2 != uVar2) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar3 = 0x500;
      goto LAB_0004f338;
    }
    iVar5 = 1;
    if (param_3 < 0x80) {
      uVar2 = *(uint *)(param_1 + 0x31c) | 0x2000000;
      goto LAB_0004f340;
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar3 = 0x501;
LAB_0004f338:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* _glePPRelocateAttrib @ 0x4f3f0 (184 bytes) */
int _glePPRelocateAttrib(param_1, param_2, param_3)
  uint param_1;
  undefined4 param_2;
  int *param_3;
{
  int iVar1;
  uint uVar2;
  
  iVar1 = *param_3;
  if (iVar1 != 0) {
    do {
      if ((((*(uint *)(iVar1 + 0xc) >> 0x1d != 0) &&
           ((*(uint *)(iVar1 + 0xc) >> 0x12 & 0xff) != 0x4a)) &&
          ((*(uint *)(iVar1 + 0x1c) & 0x3800000) == 0)) && (*(ushort *)(iVar1 + 0x22) == param_1)) {
        *(undefined2 *)(iVar1 + 0x22) = (*(unsigned short *)((unsigned char *)&(param_2) + 2));
      }
      uVar2 = *(uint *)(iVar1 + 0xc);
      if (((1 < uVar2 >> 0x1d) && (3 < (uVar2 >> 0x12 & 0xff) - 0x41)) &&
         (((*(uint *)(iVar1 + 0x24) & 0x3800000) == 0 && (*(ushort *)(iVar1 + 0x2a) == param_1)))) {
        *(undefined2 *)(iVar1 + 0x2a) = (*(unsigned short *)((unsigned char *)&(param_2) + 2));
      }
      if (((2 < uVar2 >> 0x1d) && ((*(uint *)(iVar1 + 0x2c) & 0x3800000) == 0)) &&
         (*(ushort *)(iVar1 + 0x32) == param_1)) {
        *(undefined2 *)(iVar1 + 0x32) = (*(unsigned short *)((unsigned char *)&(param_2) + 2));
      }
      iVar1 = *(int *)(iVar1 + 8);
    } while (iVar1 != 0);
    return;
  }
  return;
}

/* _glePPRelocateLocal @ 0x4f4a8 (240 bytes) */
int _glePPRelocateLocal(param_1, param_2, param_3)
  uint param_1;
  undefined4 param_2;
  int *param_3;
{
  int iVar1;
  uint uVar2;
  
  iVar1 = *param_3;
  if (iVar1 != 0) {
    do {
      if ((((*(uint *)(iVar1 + 0xc) >> 0x12 & 0xff) < 0x4b) &&
          ((*(uint *)(iVar1 + 0x14) >> 0x11 & 7) == 1)) && (*(ushort *)(iVar1 + 0x1a) == param_1)) {
        *(undefined2 *)(iVar1 + 0x1a) = (*(unsigned short *)((unsigned char *)&(param_2) + 2));
      }
      uVar2 = *(uint *)(iVar1 + 0xc);
      if (((uVar2 >> 0x1d != 0) && ((uVar2 >> 0x12 & 0xff) != 0x4a)) &&
         (((*(uint *)(iVar1 + 0x1c) >> 0x17 & 7) == 1 && (*(ushort *)(iVar1 + 0x22) == param_1)))) {
        *(undefined2 *)(iVar1 + 0x22) = (*(unsigned short *)((unsigned char *)&(param_2) + 2));
      }
      if (((1 < uVar2 >> 0x1d) && (3 < (uVar2 >> 0x12 & 0xff) - 0x41)) &&
         (((*(uint *)(iVar1 + 0x24) >> 0x17 & 7) == 1 && (*(ushort *)(iVar1 + 0x2a) == param_1)))) {
        *(undefined2 *)(iVar1 + 0x2a) = (*(unsigned short *)((unsigned char *)&(param_2) + 2));
      }
      if (((2 < uVar2 >> 0x1d) && ((*(uint *)(iVar1 + 0x2c) >> 0x17 & 7) == 1)) &&
         (*(ushort *)(iVar1 + 0x32) == param_1)) {
        *(undefined2 *)(iVar1 + 0x32) = (*(unsigned short *)((unsigned char *)&(param_2) + 2));
      }
      iVar1 = *(int *)(iVar1 + 8);
    } while (iVar1 != 0);
    return;
  }
  return;
}

/* _glePPRelocateParam @ 0x4f598 (264 bytes) */
int _glePPRelocateParam(param_1, param_2, param_3, param_4)
  uint param_1;
  undefined4 param_2;
  int *param_3;
  int *param_4;
{
  int iVar1;
  uint uVar2;
  
  for (iVar1 = *param_3; iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
    if ((((*(uint *)(iVar1 + 0xc) >> 0x1d != 0) && ((*(uint *)(iVar1 + 0xc) >> 0x12 & 0xff) != 0x4a)
         ) && ((*(uint *)(iVar1 + 0x1c) >> 0x17 & 7) == 2)) &&
       (*(ushort *)(iVar1 + 0x22) == param_1)) {
      *(short *)(iVar1 + 0x22) = (*(unsigned short *)((unsigned char *)&(param_2) + 2));
    }
    uVar2 = *(uint *)(iVar1 + 0xc);
    if (((1 < uVar2 >> 0x1d) && (3 < (uVar2 >> 0x12 & 0xff) - 0x41)) &&
       (((*(uint *)(iVar1 + 0x24) >> 0x17 & 7) == 2 && (*(ushort *)(iVar1 + 0x2a) == param_1)))) {
      *(short *)(iVar1 + 0x2a) = (*(unsigned short *)((unsigned char *)&(param_2) + 2));
    }
    if (((2 < uVar2 >> 0x1d) && ((*(uint *)(iVar1 + 0x2c) >> 0x17 & 7) == 2)) &&
       (*(ushort *)(iVar1 + 0x32) == param_1)) {
      *(short *)(iVar1 + 0x32) = (*(unsigned short *)((unsigned char *)&(param_2) + 2));
    }
  }
  if (param_4 == (int *)0x0) {
    return;
  }
  iVar1 = *param_4;
  if (iVar1 == 0) {
    return;
  }
  do {
    if (*(ushort *)(iVar1 + 0xe) == param_1) {
      *(short *)(iVar1 + 0xe) = (*(unsigned short *)((unsigned char *)&(param_2) + 2));
      *(short *)(iVar1 + 0x12) = (*(short *)(iVar1 + 0x12) + (*(unsigned short *)((unsigned char *)&(param_2) + 2))) - (short)param_1;
    }
    iVar1 = *(int *)(iVar1 + 8);
  } while (iVar1 != 0);
  return;
}

/* _glFinishRender_Exec @ 0x4f6a0 (136 bytes) */
int _glFinishRender_Exec(param_1)
  int param_1;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar3 = param_1 + 0x10000;
    iVar4 = 0;
    if (*(char *)(param_1 + 0x85a4) != '\0') {
      do {
        piVar1 = (int *)(iVar3 + -0x777c);
        iVar4 = iVar4 + 1;
        puVar2 = (undefined4 *)(iVar3 + -0x7a54);
        iVar3 = iVar3 + 0x2e0;
        (**(code **)(*piVar1 + 0x178))(*puVar2);
      } while (iVar4 < (int)(uint)*(byte *)(param_1 + 0x85a4));
    }
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
  }
  return;
}

/* _gleDrawArraysOrElements_VAR_Exec @ 0x4f798 (972 bytes) */
int _gleDrawArraysOrElements_VAR_Exec(int param_1,uint param_2,undefined4 param_3,int param_4,undefined4 param_5,int param_6,undefined4 param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int *piVar12;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  double extraout_f1_02;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
LAB_0004f820:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_0004fac4;
  }
  if (9 < param_2) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x500;
    goto LAB_0004fac4;
  }
  if (param_4 < 0) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x501;
    goto LAB_0004fac4;
  }
  if ((*(char *)(param_1 + 0x4664) != '\0') && (*(int *)(*(int *)(param_1 + 0x5420) + 0x4cc) == 0))
  goto LAB_0004f820;
  if ((*(uint *)(param_6 + 800) & 1) == 0 && (*(uint *)(param_6 + 0x324) & 0x10000) == 0) {
    return;
  }
  if (param_4 == 0) {
    return;
  }
  iVar7 = param_6;
  if (*(int *)(param_6 + 0x340) != 0 || *(int *)(param_6 + 0x344) != 0) {
    uVar10 = *(uint *)(param_6 + 0x340);
    uVar11 = *(uint *)(param_6 + 0x344);
    iVar7 = param_1 + 0x10000;
    *(undefined4 *)(param_6 + 0x340) = 0;
    *(undefined4 *)(param_6 + 0x344) = 0;
    iVar9 = 0;
    if (*(char *)(param_1 + 0x85a4) != '\0') {
      iVar8 = param_6 + 0x450;
      do {
        iVar9 = iVar9 + 1;
        *(uint *)(iVar8 + 4) = *(uint *)(iVar8 + 4) | uVar10;
        *(uint *)(iVar8 + 8) = *(uint *)(iVar8 + 8) | uVar11;
        iVar8 = iVar8 + 0x8c;
      } while (iVar9 < (int)(uint)*(byte *)(param_1 + 0x85a4));
    }
    *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x100000;
  }
  iVar8 = *(int *)(param_1 + 0x50ac);
  uVar3 = param_3;
  iVar9 = param_4;
  uVar6 = param_5;
  if (iVar8 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) == '\0') goto LAB_0004faf0;
  iVar5 = *(int *)(param_1 + 0x744c);
  piVar12 = (int *)(param_1 + 0x310);
  cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
    ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,uVar3,iVar9,uVar6,iVar7,iVar8,fparam_1,fparam_2,fparam_3,
               fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
    fparam_1 = fparam_1;
  }
  if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_0004f9c8:
    uVar10 = *(uint *)(param_1 + 0x31c);
  }
  else {
    iVar7 = 0;
    piVar4 = (int *)(param_1 + 0x324);
    do {
      iVar9 = *piVar4;
      piVar4 = piVar4 + 1;
      if (iVar9 != 0) {
        *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
        break;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < 9);
    uVar10 = *(uint *)(param_1 + 0x31c);
    if ((uVar10 & 0x15555) != 0) {
      if (*(char *)(param_1 + 0x2e54) != '\0') {
        fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
      }
      if (*(char *)(param_1 + 0x3094) != '\0') {
        fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
      }
      goto LAB_0004f9c8;
    }
  }
  bVar1 = cVar2 == '\0';
  if (bVar1) {
    uVar10 = uVar10 & 0x17000000;
  }
  else {
    uVar10 = uVar10 & 0x17ffffff;
  }
  if (bVar1) {
    bVar1 = ((*piVar12 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar10 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  else {
    bVar1 = (((*piVar12 == 0 && *(int *)(param_1 + 0x314) == 0) &&
             (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar10 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  if (!bVar1) {
    if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
      uVar10 = (**(code **)(param_1 + 0x4788))
                         (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar12);
      if ((((uVar10 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
          ((uVar10 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
         (fparam_1 = extraout_f1_01, (uVar10 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
        if ((uVar10 & 4) == 0) {
          uVar10 = uVar10 & 0xfffffffe;
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
        }
        fparam_1 = (double)_gleUpdateDispatchCodeChange(param_1,uVar10);
        if (*(char *)(param_1 + 0x759d) == '\0') {
          if (*(int *)(param_1 + 0x7574) != 0) {
            return;
          }
          uVar3 = 0x506;
LAB_0004fac4:
          *(undefined4 *)(param_1 + 0x7574) = uVar3;
          return;
        }
      }
    }
    else {
      fparam_1 = (double)_gleSwitchToNonRevertRenderer(param_1);
    }
    iVar7 = 0x13;
    do {
      *piVar12 = 0;
      piVar12 = piVar12 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
LAB_0004faf0:
  if ((*(char *)(param_1 + 0x7580) != '\0') &&
     (iVar7 = _gleExecuteVertexArrayRange
                        (param_1,param_5,param_2,param_3,param_4,*(undefined4 *)(param_1 + 0x48dc),
                         *(undefined4 *)(param_1 + 0x48d8)), fparam_1 = extraout_f1_02, iVar7 != 0))
  {
    return;
  }
  ((int (*)())_gleDrawArraysOrElements_IMM_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,fparam_1,fparam_2,fparam_3,fparam_4,
             fparam_5,fparam_6,fparam_7,fparam_8);
  return;
}

/* _glSetFenceAPPLE_Exec @ 0x4fb9c (712 bytes) */
int _glSetFenceAPPLE_Exec(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  bool bVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar6;
  uint uVar7;
  int *piVar8;
  double extraout_f1;
  double fparam_1;
  double extraout_f1_00;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
    return;
  }
  iVar4 = _gleLookupHashObject(param_1 + 0x543c,param_2);
  fparam_1 = extraout_f1;
  if (iVar4 == 0) {
    iVar4 = ((int (*)())_gleCreateFenceObject)(param_2);
    ((int (*)())_gleCreatePluginFence)(param_1,iVar4 + 0x10);
    in_r5 = iVar4;
    fparam_1 = (double)_gleAddHashNameAndObject(param_1,param_1 + 0x543c,iVar4);
  }
  iVar6 = *(int *)(param_1 + 0x50ac);
  if (iVar6 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1_00;
  }
  if (*(char *)(param_1 + 0x4691) == '\0') goto LAB_0004fe34;
  iVar5 = *(int *)(param_1 + 0x744c);
  piVar8 = (int *)(param_1 + 0x310);
  cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
    ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,in_r5,in_r6,in_r7,in_r8,iVar6,fparam_1,in_f2,in_f3,in_f4,in_f5,
               in_f6,in_f7,in_f8);
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
  }
  if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_0004fd20:
    uVar7 = *(uint *)(param_1 + 0x31c);
  }
  else {
    iVar6 = 0;
    piVar3 = (int *)(param_1 + 0x324);
    do {
      iVar5 = *piVar3;
      piVar3 = piVar3 + 1;
      if (iVar5 != 0) {
        *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
        break;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 9);
    uVar7 = *(uint *)(param_1 + 0x31c);
    if ((uVar7 & 0x15555) != 0) {
      if (*(char *)(param_1 + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
      }
      if (*(char *)(param_1 + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
      }
      goto LAB_0004fd20;
    }
  }
  bVar1 = cVar2 == '\0';
  if (bVar1) {
    uVar7 = uVar7 & 0x17000000;
  }
  else {
    uVar7 = uVar7 & 0x17ffffff;
  }
  if (bVar1) {
    bVar1 = ((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar7 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  else {
    bVar1 = (((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) &&
             (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar7 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  if (!bVar1) {
    if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
      uVar7 = (**(code **)(param_1 + 0x4788))
                        (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar8);
      if ((((uVar7 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
          ((uVar7 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
         ((uVar7 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
        if ((uVar7 & 4) == 0) {
          uVar7 = uVar7 & 0xfffffffe;
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
        }
        _gleUpdateDispatchCodeChange(param_1,uVar7);
      }
    }
    else {
      _gleSwitchToNonRevertRenderer(param_1);
    }
  }
  iVar6 = 0;
  do {
    iVar6 = iVar6 + 1;
    *piVar8 = 0;
    piVar8 = piVar8 + 1;
  } while (iVar6 < 0x13);
LAB_0004fe34:
                    
                    
  (**(code **)(param_1 + 0x46fc))
            (*(undefined4 *)(param_1 + 0x4688),
             *(undefined4 *)((uint)*(byte *)(param_1 + 0x85a8) * 4 + iVar4 + 0x10));
  return;
}

/* _gleCreateFenceObject @ 0x4fe64 (112 bytes) */
int _gleCreateFenceObject(param_1)
  undefined4 param_1;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  puVar3 = (undefined4 *)_malloc(0x30);
  puVar1 = PTR__gleFreeFenceObject_00110e1c;
  puVar3[2] = 1;
  puVar3[3] = puVar1;
  puVar3[1] = param_1;
  puVar2 = puVar3 + 4;
  *puVar3 = 0;
  iVar4 = 8;
  do {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return;
}

/* _gleCreatePluginFence @ 0x4fed4 (112 bytes) */
int _gleCreatePluginFence(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = param_1 + 0x10000;
  iVar4 = 0;
  if (*(char *)(param_1 + 0x85a4) != '\0') {
    do {
      piVar1 = (int *)(iVar3 + -0x777c);
      puVar2 = (undefined4 *)(iVar3 + -0x7a54);
      iVar3 = iVar3 + 0x2e0;
      iVar4 = iVar4 + 1;
      (**(code **)(*piVar1 + 0x1b8))(*puVar2,param_2);
      param_2 = param_2 + 4;
    } while (iVar4 < (int)(uint)*(byte *)(param_1 + 0x85a4));
  }
  return;
}

/* _glPointSize_Exec @ 0x4ff44 (216 bytes) */
void _glPointSize_Exec(int param_1,double fparam_1)
{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((double)FLOAT_00108e50 < fparam_1) {
      *(float *)(param_1 + 0x341c) = (float)fparam_1;
      if (*(int *)(param_1 + 0x5434) == 0) {
        bVar1 = *(byte *)(*(int *)(param_1 + 0x5420) + 0x325);
      }
      else {
        bVar1 = *(byte *)(*(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x359);
      }
      iVar3 = (bVar1 >> 3 & 0x1c) + param_1;
      iVar4 = *(int *)(param_1 + 0x5424);
      *(uint *)(iVar3 + 0x324) = *(uint *)(iVar3 + 0x324) | 1 << (bVar1 & 0x1f);
      bVar1 = *(byte *)(iVar4 + 0x325);
      iVar3 = (bVar1 >> 3 & 0x1c) + param_1;
      *(uint *)(iVar3 + 0x348) = *(uint *)(iVar3 + 0x348) | 1 << (bVar1 & 0x1f);
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x400000;
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x501;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
  return;
}

/* _glProgramLocalParameter4fARB_Exec @ 0x5001c (328 bytes) */
void _glProgramLocalParameter4fARB_Exec(int param_1,uint param_2,uint param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if (param_2 == 0x8620) {
    iVar5 = 0;
    if (param_3 < 0x100) {
      uVar2 = *(uint *)(param_1 + 0x31c) | 0x400000;
LAB_000500b0:
      *(uint *)(param_1 + 0x31c) = uVar2;
      if (*(int *)(param_1 + 0x5434) == 0) {
        bVar1 = *(byte *)(param_3 + *(int *)(param_1 + 0x5420) + 0x58);
      }
      else {
        bVar1 = *(byte *)(param_3 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x8c);
      }
      iVar7 = (bVar1 >> 3 & 0x1c) + param_1;
      iVar4 = *(int *)(param_1 + 0x5424);
      iVar6 = iVar5 * 4 + param_1;
      *(uint *)(iVar7 + 0x324) = *(uint *)(iVar7 + 0x324) | 1 << (bVar1 & 0x1f);
      bVar1 = *(byte *)(param_3 + iVar4 + 0x58);
      iVar4 = *(int *)(iVar6 + 0x5420);
      iVar5 = (bVar1 >> 3 & 0x1c) + param_1;
      *(uint *)(iVar5 + 0x348) = *(uint *)(iVar5 + 0x348) | 1 << (bVar1 & 0x1f);
      iVar4 = *(int *)(iVar4 + 0x4e0);
      iVar5 = iVar4 + param_3 * 0x10;
      *(float *)(iVar4 + param_3 * 0x10) = (float)fparam_1;
      *(float *)(iVar5 + 0xc) = (float)fparam_4;
      *(float *)(iVar5 + 4) = (float)fparam_2;
      *(float *)(iVar5 + 8) = (float)fparam_3;
      _gleModifyPluginPipelineProgram(param_1,*(int *)(iVar6 + 0x5420) + 0x10,2);
      return;
    }
  }
  else {
    if (param_2 < 0x8621) {
      uVar2 = 0x8200;
    }
    else {
      uVar2 = 0x8804;
    }
    if (param_2 != uVar2) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar3 = 0x500;
      goto LAB_000500a8;
    }
    iVar5 = 1;
    if (param_3 < 0x80) {
      uVar2 = *(uint *)(param_1 + 0x31c) | 0x1000000;
      goto LAB_000500b0;
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar3 = 0x501;
LAB_000500a8:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* _glPrioritizeTextures_Exec @ 0x50164 (348 bytes) */
int _glPrioritizeTextures_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (-1 < param_2) {
      if (param_2 == 0) {
        return;
      }
      iVar5 = *(int *)(param_1 + 0x5148);
      if (*(char *)(iVar5 + 0x8024) != '\0') {
        _pthread_mutex_lock(iVar5 + 0x8028);
        iVar5 = *(int *)(param_1 + 0x5148);
      }
      fVar2 = FLOAT_00108e54;
      fVar1 = FLOAT_00108e50;
      iVar7 = 0;
      if (0 < param_2) {
        do {
          iVar6 = *(int *)(iVar7 * 4 + param_3);
          if (iVar6 != 0) {
            iVar5 = _gleLookupHashObject(iVar5 + 0x2008,iVar6);
            if (iVar5 != 0) {
              fVar4 = *(float *)(iVar7 * 4 + param_4);
              if (fVar1 <= fVar4) {
                if (fVar2 < fVar4) {
                  fVar4 = 1.0;
                }
              }
              else {
                fVar4 = 0.0;
              }
              *(float *)(iVar5 + 0x38) = fVar4;
            }
            iVar5 = *(int *)(param_1 + 0x5148);
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < param_2);
      }
      if (*(char *)(iVar5 + 0x8024) == '\0') {
        return;
      }
      _pthread_mutex_unlock(iVar5 + 0x8028);
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x501;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* _glPassThrough_Exec @ 0x502c0 (152 bytes) */
void _glPassThrough_Exec(int param_1,double fparam_1)
{
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (*(int *)(param_1 + 0x4e1c) == 0x1c01) {
      ((void (*)())_gleFeedbackToken)(param_1,(double)FLOAT_00108e7c);
      ((void (*)())_gleFeedbackToken)(param_1,fparam_1);
      return;
    }
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
  }
  return;
}

/* _gleCopyPixelMapi @ 0x50358 (232 bytes) */
int _gleCopyPixelMapi(param_1, param_2, param_3, param_4)
  int *param_1;
  undefined4 *param_2;
  int param_3;
  int *param_4;
{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = (undefined *)*param_2;
  if ((param_3 == 1) && (*param_1 == 0)) {
    if (puVar1 == PTR__gle_default_pix_map_i_00112044) {
      return;
    }
    _free(puVar1);
LAB_0005041c:
    *param_2 = PTR__gle_default_pix_map_i_00112044;
    *param_4 = 1;
  }
  else {
    if ((param_3 != *param_4) || (puVar1 == PTR__gle_default_pix_map_i_00112044)) {
      if (puVar1 == PTR__gle_default_pix_map_i_00112044) {
        puVar1 = (undefined *)0x0;
      }
      puVar1 = (undefined *)_realloc(puVar1,param_3 << 2);
      if (puVar1 == (undefined *)0x0) goto LAB_0005041c;
      *param_2 = puVar1;
      *param_4 = param_3;
    }
    iVar2 = 0;
    if (0 < param_3) {
      do {
        *(int *)(puVar1 + iVar2 * 4) = param_1[iVar2];
        param_3 = param_3 + -1;
        iVar2 = iVar2 + 1;
      } while (param_3 != 0);
    }
  }
  return;
}

/* _gleCopyPixelMapf @ 0x50440 (240 bytes) */
int _gleCopyPixelMapf(param_1, param_2, param_3, param_4)
  float *param_1;
  undefined4 *param_2;
  int param_3;
  int *param_4;
{
  int iVar1;
  undefined *puVar2;
  
  puVar2 = (undefined *)*param_2;
  if ((param_3 == 1) && (*param_1 == FLOAT_00108e50)) {
    if (puVar2 == PTR__gle_default_pix_map_f_00112040) {
      return;
    }
    _free(puVar2);
LAB_0005050c:
    *param_2 = PTR__gle_default_pix_map_f_00112040;
    *param_4 = 1;
  }
  else {
    if ((param_3 != *param_4) || (puVar2 == PTR__gle_default_pix_map_f_00112040)) {
      if (puVar2 == PTR__gle_default_pix_map_f_00112040) {
        puVar2 = (undefined *)0x0;
      }
      puVar2 = (undefined *)_realloc(puVar2,param_3 << 2);
      if (puVar2 == (undefined *)0x0) goto LAB_0005050c;
      *param_2 = puVar2;
      *param_4 = param_3;
    }
    iVar1 = 0;
    if (0 < param_3) {
      do {
        *(float *)(puVar2 + iVar1 * 4) = param_1[iVar1];
        param_3 = param_3 + -1;
        iVar1 = iVar1 + 1;
      } while (param_3 != 0);
    }
  }
  return;
}

/* _gleFreeFenceObject @ 0x50530 (52 bytes) */
int _gleFreeFenceObject(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  ((int (*)())_gleDestroyPluginFence)(param_1,param_2 + 0x10);
  _free(param_2);
  return;
}

/* _gleDestroyPluginFence @ 0x50564 (120 bytes) */
int _gleDestroyPluginFence(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = param_1 + 0x10000;
  iVar5 = 0;
  if (*(char *)(param_1 + 0x85a4) != '\0') {
    do {
      piVar1 = (int *)(iVar4 + -0x777c);
      iVar3 = iVar5 * 4;
      puVar2 = (undefined4 *)(iVar4 + -0x7a54);
      iVar4 = iVar4 + 0x2e0;
      iVar5 = iVar5 + 1;
      (**(code **)(*piVar1 + 0x1bc))(*puVar2,*(undefined4 *)(iVar3 + param_2));
      *(undefined4 *)(iVar3 + param_2) = 0;
    } while (iVar5 < (int)(uint)*(byte *)(param_1 + 0x85a4));
  }
  return;
}

/* _glFeedbackBuffer_Exec @ 0x505dc (132 bytes) */
int _glFeedbackBuffer_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
{
  undefined4 uVar1;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (4 < param_3 - 0x600U) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar1 = 0x500;
      goto LAB_00050604;
    }
    if (param_2 < 0) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar1 = 0x501;
      goto LAB_00050604;
    }
    if (*(int *)(param_1 + 0x4e1c) != 0x1c01) {
      *(int *)(param_1 + 0x4fd8) = param_3;
      *(undefined4 *)(param_1 + 0x4fd0) = param_4;
      *(char *)(param_1 + 0x4fdc) = (char)param_2;
      *(undefined4 *)(param_1 + 0x4fcc) = param_4;
      *(int *)(param_1 + 0x4fd4) = param_2;
      return;
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar1 = 0x502;
LAB_00050604:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glRenderMode_Exec @ 0x50660 (508 bytes) */
int _glRenderMode_Exec(param_1, param_2)
  int param_1;
  uint param_2;
{
  undefined *puVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  double fparam_1;
  double fparam_1_00;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffffb8;
  double in_stack_ffffffc0;
  double in_stack_ffffffc8;
  double in_stack_ffffffd0;
  double in_stack_ffffffd8;
  
  iVar4 = 0;
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 - 0x1c00 < 3) {
      uVar3 = *(uint *)(param_1 + 0x4e1c);
      if (uVar3 == 0x1c01) {
        iVar4 = -1;
        if (*(char *)(param_1 + 0x4fdc) == '\0') {
          iVar4 = *(int *)(param_1 + 0x4fd0) - *(int *)(param_1 + 0x4fcc) >> 2;
        }
      }
      else if (((0x1c01 < uVar3) && (uVar3 == 0x1c02)) &&
              (iVar4 = -1, *(char *)(param_1 + 0x4fc9) == '\0')) {
        iVar4 = *(int *)(param_1 + 0x4fc4);
      }
      if (param_2 == 0x1c01) {
        if (*(int *)(param_1 + 0x4fd4) == 0) {
LAB_000507ac:
          if (*(int *)(param_1 + 0x7574) == 0) {
            *(undefined4 *)(param_1 + 0x7574) = 0x502;
            return iVar4;
          }
          return iVar4;
        }
        *(undefined1 *)(param_1 + 0x4691) = 0;
        *(undefined4 *)(param_1 + 0x4fd0) = *(undefined4 *)(param_1 + 0x4fcc);
        *(undefined1 *)(param_1 + 0x4fdc) = 0;
        *(undefined1 *)(param_1 + 0x7580) = 0;
      }
      else if (param_2 < 0x1c02) {
        if (param_2 == 0x1c00) {
          *(bool *)(param_1 + 0x4691) = *(char *)(param_1 + 0x4692) == '\0';
          *(undefined4 *)(param_1 + 0x757c) = 0xffffffff;
        }
      }
      else if (param_2 == 0x1c02) {
        if (*(int *)(param_1 + 0x4e28) == 0) goto LAB_000507ac;
        *(undefined4 *)(param_1 + 0x4e24) = *(undefined4 *)(param_1 + 20000);
        *(undefined1 *)(param_1 + 0x4fc9) = 0;
        *(int *)(param_1 + 0x4fbc) = param_1 + 0x4e2c;
        *(undefined1 *)(param_1 + 0x4691) = 0;
        *(undefined4 *)(param_1 + 0x4fc4) = 0;
        *(undefined1 *)(param_1 + 0x4fc8) = 0;
        *(undefined4 *)(param_1 + 0x4fc0) = 0;
        *(undefined1 *)(param_1 + 0x7580) = 0;
      }
      *(uint *)(param_1 + 0x4e1c) = param_2;
      *(uint *)(param_1 + 0x50ac) = *(uint *)(param_1 + 0x50ac) | 1;
      _gleSetColorMaterialEnable(param_1);
      puVar1 = PTR__gleSetClipInterpFunc_00112038;
      *(undefined **)(param_1 + 0x49c8) = PTR__gleSetEyeInterpFunc_0011203c;
      *(undefined **)(param_1 + 0x49cc) = puVar1;
      _gleSelectVertexSubmitFunc(param_1);
      _gleSelectVertexAddMaterialFunc(param_1);
      _gleUpdatePrimitiveData(param_1);
      ((void (*)())_gleUpdateViewScissorData)(param_1,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
      ((void (*)())_gleUpdateDepthRangeData)(param_1,fparam_1_00,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_ffffffb8,
                 in_stack_ffffffc0,in_stack_ffffffc8,in_stack_ffffffd0,in_stack_ffffffd8);
      _gleUpdateTextureTransform(param_1);
      _gleUpdatePolyMode(param_1);
      return iVar4;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar2 = 0x500;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar2 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
  return 0;
}

/* _gleFeedbackToken @ 0x5086c (68 bytes) */
void _gleFeedbackToken(int param_1,double fparam_1)
{
  float *pfVar1;
  
  if (*(char *)(param_1 + 0x4fdc) != '\0') {
    return;
  }
  pfVar1 = *(float **)(param_1 + 0x4fd0);
  if ((float *)(*(int *)(param_1 + 0x4fcc) + *(int *)(param_1 + 0x4fd4) * 4) <= pfVar1) {
    *(undefined1 *)(param_1 + 0x4fdc) = 1;
    return;
  }
  *pfVar1 = (float)fparam_1;
  *(float **)(param_1 + 0x4fd0) = pfVar1 + 1;
  return;
}

/* _gleBeginQuadsSelectFeedback @ 0x508b0 (76 bytes) */
int _gleBeginQuadsSelectFeedback(param_1)
  int param_1;
{
  undefined *puVar1;
  
  *(undefined **)(param_1 + 0x4a0c) = PTR__gleFlushAtomicFunc_00112224;
  puVar1 = PTR__gleFeedbackQuadsFunc_00112278;
  if (*(int *)(param_1 + 0x4e1c) == 0x1c02) {
    puVar1 = PTR__gleSelectQuadsFunc_0011227c;
  }
  *(undefined **)(param_1 + 0x4a08) = puVar1;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  return;
}

/* FUN_00050900 @ 0x50900 (1284 bytes) */
int FUN_00050900(param_1)
  int param_1;
{
  char cVar1;
  ushort uVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  uint *puVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  code *pcVar11;
  int iVar12;
  uint *puVar13;
  uint *puVar14;
  uint uVar15;
  uint *puVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  int iVar21;
  double dVar22;
  double extraout_f1;
  double extraout_f1_00;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffff78;
  double in_stack_ffffff80;
  double in_stack_ffffff88;
  int local_50;
  int local_4c [4];
  
  iVar12 = -1;
  bVar3 = false;
  if ((*(char *)(param_1 + 0x4664) != '\0') || (*(int *)(param_1 + 0x5434) != 0)) {
    bVar3 = true;
  }
  bVar3 = !bVar3;
  bVar5 = false;
  if ((bVar3) && (*(char *)(param_1 + 0x30aa) != '\0')) {
    bVar5 = true;
  }
  bVar6 = false;
  if (((bVar3) && (*(char *)(param_1 + 0x30aa) != '\0')) && (*(char *)(param_1 + 0x30ac) != '\0')) {
    bVar6 = true;
  }
  cVar1 = *(char *)(param_1 + 0x4fe0);
  uVar19 = *(uint *)(param_1 + 0x4854);
  if (((int)*(short *)(param_1 + 0x487c) != 0) &&
     (uVar15 = (*(int *)(param_1 + 0x4858) - uVar19) / (uint)(int)*(short *)(param_1 + 0x487c),
     3 < (int)uVar15)) {
    if (bVar3) {
      uVar9 = (**(code **)(param_1 + 0x5060))(param_1,uVar19,uVar15);
    }
    else {
      uVar9 = _gleVPEmulate(param_1,uVar15);
    }
    if ((uVar9 & 0xff00) == 0) {
      if (bVar3) {
        if (*(char *)(param_1 + 0x53e4) != '\0') {
          (**(code **)(param_1 + 0x53dc))(param_1,uVar19,uVar15);
        }
        if (*(char *)(param_1 + 0x50b4) != '\0') {
          (**(code **)(param_1 + 0x5064))(param_1,uVar19,uVar15);
        }
        if ((bVar5) || (*(char *)(param_1 + 0x53e6) != '\0')) {
          (**(code **)(param_1 + 0x5068))(param_1,uVar19,uVar15);
        }
        if (*(char *)(param_1 + 0x53e5) != '\0') {
          (**(code **)(param_1 + 0x53e0))(param_1,uVar19,uVar15);
        }
      }
      else {
        uVar19 = *(uint *)(param_1 + 0x4864);
      }
      if (((uVar9 & 0xff) == 0) && (*(char *)(param_1 + 0x4e18) == '\0')) {
        dVar22 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x506c))(param_1, uVar19, uVar15, 0);
        if (cVar1 == '\0') {
          if (bVar5) {
            (**(code **)(param_1 + 0x4de8))(param_1,uVar19,uVar15);
          }
          _gleFeedbackQuads(param_1,uVar19,uVar15,*(ushort *)(param_1 + 0x34d0) - 0x1b00);
        }
        else {
          uVar15 = (uVar19 + uVar15 * 0x100) - 0x400;
          do {
            bVar4 = false;
            iVar20 = 0;
            uVar9 = uVar19;
            uVar18 = uVar19;
            if (uVar19 <= uVar15) {
              do {
                iVar10 = ((undefined4 (*)())_gleCullQuad)(param_1,uVar19,uVar19 + 0x100,uVar19 + 0x200,uVar19 + 0x300,
                                      &local_50,dVar22,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                                      in_stack_ffffff78,in_stack_ffffff80,in_stack_ffffff88);
                dVar22 = dVar22;
                if (iVar10 == 0) {
                  if (iVar12 != local_50) {
                    bVar4 = true;
                  }
                  if ((bVar4) && (uVar9 = uVar19, 0 < iVar20)) break;
                  iVar20 = iVar20 + 4;
                  iVar12 = local_50;
                  uVar17 = uVar18;
                }
                else {
                  uVar17 = uVar19 + 0x400;
                  uVar9 = uVar17;
                  if (0 < iVar20) break;
                }
                uVar19 = uVar19 + 0x400;
                uVar9 = uVar19;
                uVar18 = uVar17;
              } while (uVar19 <= uVar15);
              if (3 < iVar20) {
                if (bVar6) {
                  pcVar11 = *(code **)(iVar12 * 4 + param_1 + 0x4de8);
LAB_00050bc0:
                  (*pcVar11)(param_1,uVar18,iVar20);
                }
                else if (bVar5) {
                  pcVar11 = *(code **)(param_1 + 0x4de8);
                  goto LAB_00050bc0;
                }
                if ((!bVar3) && (bVar5)) {
                  _gleVPFlipColors(param_1,uVar18,iVar20,iVar12);
                }
                if (iVar12 == 0) {
                  uVar2 = *(ushort *)(param_1 + 0x34d0);
                }
                else {
                  uVar2 = *(ushort *)(param_1 + 0x34d2);
                }
                dVar22 = (double)_gleFeedbackQuads(param_1,uVar18,iVar20,uVar2 - 0x1b00);
              }
            }
            uVar19 = uVar9;
          } while (uVar9 <= uVar15);
        }
      }
      else {
        dVar22 = (double)(**(double ( **)(int,int,int,int))(param_1 + 0x5074))(param_1, uVar19, uVar15, 0);
        iVar12 = uVar19 + uVar15 * 0x100;
        puVar16 = *(uint **)(param_1 + 0x4870);
        puVar13 = *(uint **)(param_1 + 0x4874);
        for (; uVar19 <= iVar12 - 0x400U; uVar19 = uVar19 + 0x400) {
          puVar16[1] = uVar19 + 0x100;
          puVar16[2] = uVar19 + 0x200;
          puVar16[3] = uVar19 + 0x300;
          *puVar16 = uVar19;
          if (bVar3) {
            uVar8 = *(undefined4 *)(param_1 + 0x485c);
          }
          else {
            uVar8 = *(undefined4 *)(param_1 + 0x4854);
          }
          *(undefined4 *)(param_1 + 0x4858) = uVar8;
          puVar14 = puVar13;
          iVar20 = 4;
          puVar7 = puVar16;
          if ((*(char *)(param_1 + 0x4e18) == '\0') ||
             (dVar22 = (double)((double (*)())_gleClipPolyPlane)(param_1,puVar16,4,puVar13,local_4c,dVar22,in_f2,
                                                 in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                                                 in_stack_ffffff78,in_stack_ffffff80),
             puVar14 = puVar16, iVar20 = local_4c[0], puVar7 = puVar13, local_4c[0] != 0)) {
            puVar16 = puVar7;
            puVar13 = puVar14;
            if ((uVar9 & 0xff) != 0) {
              dVar22 = (double)((int (*)())_gleClipPoly)(param_1,puVar16,iVar20,uVar9 & 0xff,puVar14,local_4c,1);
              if (local_4c[0] == 0) goto LAB_00050ddc;
              if (0 < local_4c[0]) {
                puVar13 = puVar16;
                iVar20 = local_4c[0];
                puVar16 = puVar14;
              }
            }
            if ((cVar1 == '\0') ||
               (iVar10 = _gleCullPolygonPtrStack(param_1,puVar16,iVar20,&local_50),
               dVar22 = extraout_f1_00, iVar10 == 0)) {
              iVar10 = local_50;
              if (bVar6) {
                pcVar11 = *(code **)(local_50 * 4 + param_1 + 0x4df0);
LAB_00050d70:
                (*pcVar11)(param_1,puVar16,iVar20);
              }
              else if (bVar5) {
                pcVar11 = *(code **)(param_1 + 0x4df0);
                goto LAB_00050d70;
              }
              if (((!bVar3) && (bVar5)) && (puVar14 = puVar16, iVar21 = iVar20, 0 < iVar20)) {
                do {
                  _gleVPFlipColors(param_1,*puVar14,1,iVar10);
                  iVar21 = iVar21 + -1;
                  puVar14 = puVar14 + 1;
                } while (iVar21 != 0);
              }
              if (iVar10 == 0) {
                uVar2 = *(ushort *)(param_1 + 0x34d0);
              }
              else {
                uVar2 = *(ushort *)(param_1 + 0x34d2);
              }
              dVar22 = (double)((int (*)())_gleFeedbackPolygonPtr)(param_1,puVar16,iVar20,uVar2 - 0x1b00);
            }
          }
LAB_00050ddc: ;
        }
      }
    }
  }
  return;
}

/* _gleSetProjectionFuncAll @ 0x50e04 (104 bytes) */
int _gleSetProjectionFuncAll(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  code *pcVar1;
  
  pcVar1 = (code *)(*_gleBuildProjectionTransformFunc)(param_1,0);
  *(code **)(param_1 + 0x5060) = pcVar1;
  (*pcVar1)(param_1,param_2,param_3);
  return;
}

/* _gleBuildProjectionTransformFuncAV @ 0x50e6c (1208 bytes) */
int _gleBuildProjectionTransformFuncAV(param_1, param_2)
  int param_1;
  uint param_2;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined *puVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  int *piVar13;
  int *piVar14;
  undefined4 *puVar15;
  undefined4 *puVar16;
  
  piVar14 = (int *)PTR__gleTransformProjectionBlend_00110a10;
  if (*(char *)(param_1 + 0x4661) == '\0') {
    uVar2 = (**(code **)PTR__gleGenerateMatrixIdentifier_00112060)(param_1,param_1 + 0x27c0);
    *(uint *)(param_1 + 0x5084) = uVar2;
    if (((param_2 & 1) != 0) && ((uVar2 & 0x3030303) == 0x3030302)) {
      param_2 = param_2 | 4;
    }
    if ((uVar2 != 0xbfeffbfe) &&
       (uVar1 = uVar2 & 0x3fcff3fc, uVar2 = 0x3fcff3fc, uVar1 != 0x3fcff3fc)) {
      uVar2 = 0;
    }
    if (*(undefined **)(param_1 + 0x5080) == ((unsigned char *)0x00001101)) {
      param_2 = param_2 | 8;
    }
    piVar13 = *(int **)(param_1 + 0x5088);
    piVar14 = piVar13;
    do {
      if (uVar2 == piVar14[2] && param_2 == piVar14[3]) {
        if (piVar14 != piVar13) {
          _gleMoveFuncCacheElem(piVar13,piVar14);
          *(int **)(param_1 + 0x5088) = piVar14;
        }
        return piVar14 + 8;
      }
      piVar14 = (int *)*piVar14;
    } while (piVar14 != piVar13);
    iVar3 = _gleCreateFuncCacheElem(piVar14,0xb8);
    piVar14 = (int *)PTR__gleRTCNoop_00112058;
    if (iVar3 != 0) {
      *(uint *)(iVar3 + 8) = uVar2;
      *(uint *)(iVar3 + 0xc) = param_2;
      if (*(short *)(param_1 + 0x508e) == *(short *)(param_1 + 0x508c)) {
        _gleDeleteFuncCacheElem(*(undefined4 *)(iVar3 + 4));
      }
      else {
        *(short *)(param_1 + 0x508e) = *(short *)(param_1 + 0x508e) + 1;
      }
      iVar4 = _gleRTCAddAChunk_c5ddc(&_glePrologAVRTC,iVar3 + 0x20);
      iVar4 = iVar3 + 0x20 + iVar4 * 4;
      if (uVar2 != 0xbfeffbfe) {
        iVar5 = _gleRTCAddAChunk_c5ddc(&_gleLoadMatrixPtrRTC,iVar4);
        iVar4 = iVar4 + iVar5 * 4;
        if ((param_2 & 2) == 0) {
          puVar6 = &_gleLoadMatrixVectorsRTC;
        }
        else {
          puVar6 = &_gleLoadMatrixVectorsZ0RTC;
        }
        iVar5 = _gleRTCAddAChunk_c5ddc(puVar6,iVar4);
        iVar4 = iVar4 + iVar5 * 4;
      }
      iVar5 = _gleRTCAddAChunk_c5ddc(&_gleLoadModelOffsetRTC,iVar4);
      iVar4 = iVar4 + iVar5 * 4;
      if (uVar2 == 0) {
        if ((param_2 & 1) == 0) {
          if ((param_2 & 2) == 0) {
            puVar6 = &_gleFullMatrixMultRTC;
          }
          else {
            puVar6 = &_gleFullMatrixMultZ0RTC;
          }
        }
        else if ((param_2 & 2) == 0) {
          puVar6 = &_gleFullMatrixMultW1RTC;
        }
        else {
          puVar6 = &_gleFullMatrixMultZ0W1RTC;
        }
      }
      else if (uVar2 == 0x3fcff3fc) {
        iVar5 = _gleRTCAddAChunk_c5ddc(&_gleDiagMatrixSetupRTC,iVar4);
        iVar4 = iVar4 + iVar5 * 4;
        puVar6 = &_gleDiagMatrixMultRTC;
      }
      else {
        puVar6 = &_gleIdentityMatrixMultRTC;
      }
      iVar5 = _gleRTCAddAChunk_c5ddc(puVar6,iVar4);
      iVar5 = iVar4 + iVar5 * 4;
      if ((param_2 & 8) == 0) {
        if ((param_2 & 4) == 0) {
          iVar7 = _gleRTCAddAChunk_c5ddc(&_gleCalcClipCode0AVRTC,iVar5);
          iVar5 = iVar5 + iVar7 * 4;
          iVar7 = _gleRTCAddAChunk_c5ddc(&_gleCalcClipCode1AVRTC,iVar5);
          iVar7 = iVar5 + iVar7 * 4;
          puVar6 = &_gleCalcClipCode2AVRTC;
        }
        else {
          iVar7 = _gleRTCAddAChunk_c5ddc(&_gleCalcClipCode0W1AVRTC,iVar5);
          iVar5 = iVar5 + iVar7 * 4;
          iVar7 = _gleRTCAddAChunk_c5ddc(&_gleCalcClipCode1W1AVRTC,iVar5);
          iVar7 = iVar5 + iVar7 * 4;
          puVar6 = &_gleCalcClipCode2W1AVRTC;
        }
        puVar10 = (undefined4 *)(iVar5 + -8);
        puVar16 = (undefined4 *)(iVar5 + -4);
        puVar12 = (undefined4 *)(iVar7 + -8);
        iVar5 = _gleRTCAddAChunk_c5ddc(puVar6,iVar7);
        puVar9 = (undefined4 *)(iVar7 + -4);
        iVar7 = iVar7 + iVar5 * 4;
        puVar15 = (undefined4 *)(iVar7 + -8);
        puVar11 = (undefined4 *)(iVar7 + -4);
        iVar5 = _gleRTCAddAChunk_c5ddc(&_gleCalcClipCode3AVRTC,iVar7);
        iVar5 = iVar7 + iVar5 * 4;
        uVar8 = _gleRTCBuildABranch_c5dd0(*puVar10,iVar4 - (int)puVar10 >> 2);
        *puVar10 = uVar8;
        uVar8 = _gleRTCBuildABranch_c5dd0(*puVar12,iVar4 - (int)puVar12 >> 2);
        *puVar12 = uVar8;
        uVar8 = _gleRTCBuildABranch_c5dd0(*puVar15,iVar4 - (int)puVar15 >> 2);
        *puVar15 = uVar8;
        uVar8 = _gleRTCBuildABranch_c5dd0(*puVar16,iVar5 - (int)puVar16 >> 2);
        *puVar16 = uVar8;
        uVar8 = _gleRTCBuildABranch_c5dd0(*puVar9,iVar5 - (int)puVar9 >> 2);
        *puVar9 = uVar8;
        uVar8 = _gleRTCBuildABranch_c5dd0(*puVar11,iVar5 - (int)puVar11 >> 2);
        *puVar11 = uVar8;
      }
      else {
        if ((param_2 & 4) == 0) {
          puVar6 = &_gleNoClipCodeAVRTC;
        }
        else {
          puVar6 = &_gleNoClipCodeW1AVRTC;
        }
        iVar7 = _gleRTCAddAChunk_c5ddc(puVar6,iVar5);
        iVar5 = iVar5 + iVar7 * 4;
      }
      puVar16 = (undefined4 *)(iVar5 + -4);
      uVar8 = _gleRTCBuildABranch_c5dd0(*puVar16,iVar4 - (int)puVar16 >> 2);
      *puVar16 = uVar8;
      iVar4 = _gleRTCAddAChunk_c5ddc(&_gleCombineClipSumsAVRTC,iVar5);
      iVar5 = iVar5 + iVar4 * 4;
      iVar4 = _gleRTCAddAChunk_c5ddc(&_gleEpilogAVRTC,iVar5);
      puVar16 = (undefined4 *)(iVar5 + iVar4 * 4);
      *puVar16 = 0x4e800020;
      iVar4 = (int)puVar16 + (-0x1c - iVar3) >> 2;
      if (0xb8 < iVar4) {
                    
        _exit(1);
      }
      iVar3 = _gleShrinkFuncCacheElem(iVar3,iVar4);
      puVar6 = PTR__glePushInstructions_00112054;
      *(int *)(param_1 + 0x5088) = iVar3;
      (**(code **)puVar6)(iVar4,(int *)(iVar3 + 0x20));
      piVar14 = (int *)(iVar3 + 0x20);
    }
  }
  return piVar14;
}

/* _gleRTCAddAChunk_51324 @ 0x51324 (48 bytes) */
int _gleRTCAddAChunk_51324(param_1, param_2)
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

/* _gleRTCBuildABranch_51354 @ 0x51354 (12 bytes) */
int _gleRTCBuildABranch_51354(param_1, param_2)
  uint param_1;
  uint param_2;
{
  return (param_2 & 0x3fff) << 2 | param_1 & 0xffff0003;
}

/* FUN_00051364 @ 0x51364 (232 bytes) */
void FUN_00051364(int param_1,uint param_2,int param_3,int param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12)
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
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  int iVar21;
  uint uVar22;
  
  iVar21 = param_1 + param_4 * 0x40;
  fVar1 = *(float *)(iVar21 + 0x1fc0);
  fVar2 = *(float *)(iVar21 + 0x1ff8);
  fVar3 = *(float *)(iVar21 + 0x1fc4);
  fVar4 = *(float *)(0x1fcc + iVar21);
  fVar5 = *(float *)(iVar21 + 0x1fd0);
  fVar6 = *(float *)(iVar21 + 0x1fd4);
  fVar7 = *(float *)(iVar21 + 0x1fdc);
  fVar8 = *(float *)(iVar21 + 0x1fe0);
  fVar9 = *(float *)(iVar21 + 0x1fe4);
  fVar10 = *(float *)(iVar21 + 0x1fec);
  fVar11 = *(float *)(iVar21 + 0x1ff0);
  fVar12 = *(float *)(iVar21 + 0x1ff4);
  fVar13 = *(float *)(iVar21 + 0x1ffc);
  fVar14 = *(float *)(iVar21 + 0x1fc8);
  fVar15 = *(float *)(iVar21 + 0x1fd8);
  fVar16 = *(float *)(iVar21 + 0x1fe8);
  if (param_2 < param_2 + param_3) {
    uVar22 = ((param_2 + param_3) - param_2) + 0xff >> 8;
    do {
      iVar21 = param_2 + param_4 * 0x10;
      param_2 = param_2 + 0x100;
      fVar17 = *(float *)(iVar21 + 0x80);
      fVar18 = *(float *)(iVar21 + 0x84);
      fVar19 = *(float *)(iVar21 + 0x88);
      fVar20 = *(float *)(iVar21 + 0x8c);
      *(float *)(iVar21 + 0x8c) =
           fVar20 * fVar13 + (fVar19 * fVar10 + (fVar17 * fVar4 + fVar18 * fVar7));
      *(float *)(iVar21 + 0x80) = fVar20 * fVar11 + (fVar19 * fVar8 + (fVar17 * fVar1 + fVar18 * fVar5))
      ;
      *(float *)(iVar21 + 0x84) = fVar20 * fVar12 + (fVar19 * fVar9 + (fVar17 * fVar3 + fVar18 * fVar6))
      ;
      *(float *)(iVar21 + 0x88) =
           fVar20 * fVar2 + (fVar19 * fVar16 + (fVar17 * fVar14 + fVar18 * fVar15));
      uVar22 = uVar22 - 1;
    } while (uVar22 != 0);
  }
  return;
}

/* _gleClipPoly @ 0x5144c (432 bytes) */
int _gleClipPoly(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int *param_2;
  int param_3;
  uint param_4;
  int *param_5;
  int *param_6;
  int param_7;
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  
  if (param_7 == 0) {
LAB_000514ac:
    iVar1 = *(int *)(param_1 + 0x4858);
    piVar8 = param_2 + param_3;
    iVar5 = 0;
    uVar2 = 1;
    piVar6 = param_5;
    do {
      piVar7 = piVar6;
      if ((param_4 & uVar2) != 0) {
        *piVar8 = *param_2;
        for (piVar9 = param_2; piVar9 < piVar8; piVar9 = piVar9 + 1) {
          iVar5 = *piVar9;
          if ((uVar2 & *(byte *)(iVar5 + 0x7f)) == 0) {
            *piVar7 = iVar5;
            piVar7 = piVar7 + 1;
            if ((uVar2 & *(byte *)(piVar9[1] + 0x7f)) != 0) {
              uVar3 = (**(code **)(param_1 + 0x49cc))(param_1,piVar9[1],*piVar9,iVar1,uVar2);
              *(undefined1 *)(iVar1 + 0x7c) = 0;
              *piVar7 = iVar1;
              goto LAB_0005156c;
            }
          }
          else if ((uVar2 & *(byte *)(piVar9[1] + 0x7f)) == 0) {
            uVar3 = (**(code **)(param_1 + 0x49cc))(param_1,iVar5,piVar9[1],iVar1,uVar2);
            *piVar7 = iVar1;
LAB_0005156c:
            param_4 = (param_4 | uVar3) & 0xff;
            iVar1 = iVar1 + 0x100;
            piVar7 = piVar7 + 1;
          }
        }
        iVar5 = (int)piVar7 - (int)piVar6 >> 2;
        if (iVar5 < 3) goto LAB_000514a0;
        piVar8 = piVar6 + iVar5;
        piVar7 = param_2;
        param_2 = piVar6;
      }
      uVar2 = (uVar2 & 0x7f) << 1;
      piVar6 = piVar7;
    } while (uVar2 < 0x21);
    if ((param_2 != param_5) && (iVar4 = 0, iVar10 = iVar5, 0 < iVar5)) {
      do {
        param_5[iVar4] = param_2[iVar4];
        iVar10 = iVar10 + -1;
        iVar4 = iVar4 + 1;
      } while (iVar10 != 0);
    }
    *param_6 = iVar5;
    *(int *)(param_1 + 0x4858) = iVar1;
  }
  else {
    uVar2 = ((int (*)())_glePolyClipCode)(param_1,param_2,param_3);
    if ((uVar2 & 0xff) == 0) {
      iVar1 = -1;
    }
    else {
      param_4 = uVar2 & 0xff;
      if ((uVar2 & 0xff00) == 0) goto LAB_000514ac;
LAB_000514a0:
      iVar1 = 0;
    }
    *param_6 = iVar1;
  }
  return;
}

/* _glePolyClipCode @ 0x515fc (76 bytes) */
int _glePolyClipCode(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  int param_3;
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 0;
  uVar2 = 0xff;
  if (param_2 < param_2 + param_3) {
    uVar4 = (uint)((int)(param_2 + param_3) + (3 - (int)param_2)) >> 2;
    do {
      iVar1 = *param_2;
      param_2 = param_2 + 1;
      uVar2 = uVar2 & *(byte *)(iVar1 + 0x7f);
      uVar3 = uVar3 | *(byte *)(iVar1 + 0x7f);
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  return uVar2 << 8 | uVar3;
}

/* _gleSetClipInterpFunc @ 0x51648 (100 bytes) */
int _gleSetClipInterpFunc(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  code *pcVar1;
  
  pcVar1 = (code *)((int (*)())_gleBuildInterpolateFunc)(param_1,1,param_3,param_4,param_5,param_6,param_7,param_8);
  *(code **)(param_1 + 0x49cc) = pcVar1;
  (*pcVar1)(param_1,param_2,param_3,param_4,param_5);
  return;
}

/* _gleBuildInterpolateFunc @ 0x516ac (1776 bytes) */
int _gleBuildInterpolateFunc(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined *puVar8;
  uint *puVar9;
  uint *puVar10;
  uint uVar11;
  uint uVar12;
  int *piVar13;
  int *piVar14;
  uint *puVar15;
  
  puVar10 = (uint *)0x0;
  if ((*(uint *)PTR__gle_processor_0011204c & 0x10) == 0) {
    piVar6 = (int *)_gleSelectArrayInterpFunc(param_1,param_2);
    return piVar6;
  }
  uVar11 = 1;
  if (param_2 != 1) {
    uVar11 = 0x10;
  }
  if (*(int *)(param_1 + 0x34f4) == 0x1d01) {
    uVar11 = uVar11 | 2;
  }
  uVar2 = *(uint *)(param_1 + 0x4e1c);
  if (uVar2 == 0x1c01) {
    uVar12 = uVar11 | 0x10020;
    if (((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5434) == 0)) &&
       (uVar12 = uVar11 | 0x10060, *(char *)(param_1 + 0x30aa) != '\0')) {
      uVar12 = uVar11 | 0x10470;
    }
  }
  else {
    uVar12 = uVar11;
    if ((uVar2 < 0x1c02) && (uVar2 == 0x1c00)) {
      if ((*(uint *)(*(int *)(param_1 + 0x468c) + 0x94) & 4) == 0) {
        uVar11 = uVar11 | 4;
      }
      bVar1 = *(char *)(param_1 + 0x466c) != '\0';
      if (bVar1) {
        iVar3 = *(int *)(param_1 + 0x5438);
      }
      else {
        iVar3 = *(int *)(param_1 + 0x5438);
        if (iVar3 == 0) {
          uVar2 = 0;
          *(uint *)(param_1 + 0x5150) = *(uint *)(param_1 + 0x514c);
          do {
            uVar12 = *(uint *)(param_1 + 0x514c) >> (uVar2 & 0x3f);
            if ((uVar12 & 1) == 0) {
              if (uVar12 == 0) goto LAB_00051840;
            }
            else {
              uVar11 = uVar11 | 0x10000 << (uVar2 & 0x3f);
            }
            uVar2 = uVar2 + 1;
          } while( true );
        }
      }
      iVar5 = 0;
      if (bVar1) {
        iVar5 = *(int *)(*(int *)(param_1 + 0x5424) + 0x4cc);
      }
      if (iVar3 != 0) {
        iVar5 = *(int *)(*(int *)(*(int *)(param_1 + 0x5430) + 0x24) + 0x508);
      }
      *(undefined4 *)(param_1 + 0x5150) = 0;
      if (iVar5 != 0) {
        puVar9 = (uint *)(iVar5 + *(int *)(iVar5 + 0x24) * 8);
        for (iVar3 = *(int *)(iVar5 + 0x20); iVar3 != 0; iVar3 = iVar3 + -1) {
          if ((*puVar9 >> 0x10 & 0xf) == 7) {
            uVar2 = *puVar9 & 0x1f;
            uVar11 = uVar11 | 0x10000 << uVar2;
            *(uint *)(param_1 + 0x5150) = *(uint *)(param_1 + 0x5150) | 1 << uVar2;
          }
          puVar9 = puVar9 + 2;
        }
      }
LAB_00051840:
      uVar2 = uVar11;
      if ((*(char *)(param_1 + 0x316a) != '\0') &&
         (uVar2 = uVar11 | 0x80, *(short *)(0x3170 + param_1 + 4) == 0x1102)) {
        uVar2 = uVar11 | 0x280;
      }
      if (((*(char *)(param_1 + 0x30aa) == '\0') || (*(char *)(param_1 + 0x4664) != '\0')) ||
         (*(int *)(param_1 + 0x5434) != 0)) {
        uVar12 = uVar2 | 0x20;
        if (*(char *)(param_1 + 0x4fea) != '\0') {
          uVar12 = uVar2 | 0x120;
        }
      }
      else {
        uVar12 = uVar2 | 0x450;
      }
    }
  }
  piVar6 = (int *)(param_1 + 0x49d0);
  if (param_2 != 0) {
    piVar6 = (int *)(param_1 + 0x49d8);
  }
  piVar13 = (int *)*piVar6;
  piVar14 = piVar13;
  do {
    if (uVar12 == piVar14[2]) {
      if (piVar14 != piVar13) {
        _gleMoveFuncCacheElem(piVar13,piVar14);
        *piVar6 = (int)piVar14;
      }
      return piVar14 + 8;
    }
    piVar14 = (int *)*piVar14;
  } while (piVar14 != piVar13);
  iVar3 = _gleCreateFuncCacheElem(piVar14,0xa0);
  piVar14 = (int *)PTR__gleRTCNoop_00112058;
  if (iVar3 != 0) {
    *(uint *)(iVar3 + 8) = uVar12;
    if (*(short *)((int)piVar6 + 6) == *(short *)(piVar6 + 1)) {
      _gleDeleteFuncCacheElem(*(undefined4 *)(iVar3 + 4));
    }
    else {
      *(short *)((int)piVar6 + 6) = *(short *)((int)piVar6 + 6) + 1;
    }
    uVar11 = uVar12 & 1;
    iVar5 = ((int (*)())_gleRTCAddAChunk_51324)(&_gleStartAVRTC,iVar3 + 0x20);
    iVar5 = iVar3 + 0x20 + iVar5 * 4;
    if (uVar11 != 0) {
      iVar7 = ((int (*)())_gleRTCAddAChunk_51324)(&_gleCalculateTAVRTC,iVar5);
      iVar5 = iVar5 + iVar7 * 4;
    }
    iVar7 = ((int (*)())_gleRTCAddAChunk_51324)(&_gleInterpClip1AVRTC,iVar5);
    iVar5 = iVar5 + iVar7 * 4;
    if (uVar11 != 0) {
      iVar7 = ((int (*)())_gleRTCAddAChunk_51324)(&_gleClipExactWAVRTC,iVar5);
      iVar5 = iVar5 + iVar7 * 4;
    }
    bVar1 = true;
    iVar7 = ((int (*)())_gleRTCAddAChunk_51324)(&_gleInterpClip2AVRTC,iVar5);
    puVar9 = (uint *)(iVar5 + iVar7 * 4);
    if ((uVar12 & 0x10) != 0) {
      *puVar9 = 0x39200020;
      puVar9 = puVar9 + 1;
      if ((uVar12 & 3) == 1) {
        iVar5 = ((int (*)())_gleRTCAddAChunk_51324)(&_gleTestSrcEqualDestAVRTC,puVar9);
        puVar9 = puVar9 + iVar5;
        puVar10 = puVar9 + -1;
        bVar1 = puVar10 == (uint *)0x0;
        puVar8 = &_gleCopyVecAVRTC;
      }
      else {
        puVar8 = &_gleInterpVecAVRTC;
        bVar1 = true;
      }
      iVar5 = ((int (*)())_gleRTCAddAChunk_51324)(puVar8,puVar9);
      puVar9 = puVar9 + iVar5;
    }
    if ((uVar12 & 0x20) != 0) {
      *puVar9 = 0x39200030;
      puVar9 = puVar9 + 1;
      if ((uVar12 & 2) == 0) {
        if (bVar1) {
          iVar5 = ((int (*)())_gleRTCAddAChunk_51324)(&_gleTestSrcEqualDestAVRTC,puVar9);
          puVar9 = puVar9 + iVar5;
          puVar10 = puVar9 + -1;
          bVar1 = puVar10 == (uint *)0x0;
        }
        puVar8 = &_gleCopyVecAVRTC;
      }
      else {
        puVar8 = &_gleInterpVecAVRTC;
      }
      iVar5 = ((int (*)())_gleRTCAddAChunk_51324)(puVar8,puVar9);
      puVar9 = puVar9 + iVar5;
    }
    if ((uVar12 & 0x40) != 0) {
      *puVar9 = 0x39200040;
      puVar9 = puVar9 + 1;
      if ((uVar12 & 2) == 0) {
        if (bVar1) {
          iVar5 = ((int (*)())_gleRTCAddAChunk_51324)(&_gleTestSrcEqualDestAVRTC,puVar9);
          puVar9 = puVar9 + iVar5;
          puVar10 = puVar9 + -1;
          bVar1 = puVar10 == (uint *)0x0;
        }
        puVar8 = &_gleCopyVecAVRTC;
      }
      else {
        puVar8 = &_gleInterpVecAVRTC;
      }
      iVar5 = ((int (*)())_gleRTCAddAChunk_51324)(puVar8,puVar9);
      puVar9 = puVar9 + iVar5;
    }
    if ((uVar12 & 0x100) != 0) {
      *puVar9 = 0x39200050;
      puVar9 = puVar9 + 1;
      if ((uVar12 & 2) == 0) {
        if (bVar1) {
          iVar5 = ((int (*)())_gleRTCAddAChunk_51324)(&_gleTestSrcEqualDestAVRTC,puVar9);
          puVar9 = puVar9 + iVar5;
          puVar10 = puVar9 + -1;
          bVar1 = puVar10 == (uint *)0x0;
        }
        puVar8 = &_gleCopyVecAVRTC;
      }
      else {
        puVar8 = &_gleInterpVecAVRTC;
      }
      iVar5 = ((int (*)())_gleRTCAddAChunk_51324)(puVar8,puVar9);
      puVar9 = puVar9 + iVar5;
    }
    if ((uVar12 & 0x400) != 0) {
      if (bVar1) {
        iVar5 = ((int (*)())_gleRTCAddAChunk_51324)(&_gleTestSrcEqualDestAVRTC,puVar9);
        puVar9 = puVar9 + iVar5;
        puVar10 = puVar9 + -1;
        bVar1 = puVar10 == (uint *)0x0;
      }
      iVar5 = ((int (*)())_gleRTCAddAChunk_51324)(&_gleCopyMaterialsAVRTC,puVar9);
      puVar9 = puVar9 + iVar5;
    }
    puVar15 = puVar9;
    if (((uVar12 & 0x80) != 0) && ((uVar12 & 0x42) != 0x42)) {
      iVar5 = ((int (*)())_gleRTCAddAChunk_51324)(&_gleInterpFogAVRTC,puVar9);
      puVar15 = puVar9 + iVar5;
    }
    if (((uVar12 & 0x200) != 0) && ((uVar12 & 0x102) != 0x102)) {
      iVar5 = ((int (*)())_gleRTCAddAChunk_51324)(&_gleInterpFogCoordAVRTC,puVar15);
      puVar15 = puVar15 + iVar5;
    }
    if (uVar12 >> 0x10 != 0) {
      uVar2 = 0;
      do {
        if ((uVar12 & 0x10000 << (uVar2 & 0x3f)) != 0) {
          *puVar15 = uVar2 * 0x10 + 0x80 & 0xffff | 0x39200000;
          if ((uVar12 & 4) == 0) {
            puVar8 = &_gleInterpTexNoDivAVRTC;
          }
          else if (uVar11 == 0) {
            puVar8 = &_gleInterpTexTestAVRTC;
          }
          else {
            puVar8 = &_gleInterpTexAVRTC;
          }
          iVar5 = ((int (*)())_gleRTCAddAChunk_51324)(puVar8,puVar15 + 1);
          puVar15 = puVar15 + 1 + iVar5;
        }
      } while (((int)(uVar2 + 1) < 8) &&
              (uVar4 = uVar2 + 0x11, uVar2 = uVar2 + 1, uVar12 >> (uVar4 & 0x3f) != 0));
    }
    if (uVar11 != 0) {
      iVar5 = ((int (*)())_gleRTCAddAChunk_51324)(&_gleSetReturnAVRTC,puVar15);
      puVar15 = puVar15 + iVar5;
    }
    iVar5 = ((int (*)())_gleRTCAddAChunk_51324)(&_gleEndAVRTC,puVar15);
    if (!bVar1) {
      uVar11 = ((int (*)())_gleRTCBuildABranch_51354)(*puVar10,(int)puVar9 - (int)puVar10 >> 2);
      *puVar10 = uVar11;
    }
    iVar5 = (int)puVar15 + (iVar5 * 4 - iVar3) + -0x20 >> 2;
    if (0xa0 < iVar5) {
                    
      _exit(1);
    }
    iVar3 = _gleShrinkFuncCacheElem(iVar3,iVar5);
    puVar8 = PTR__glePushInstructions_00112054;
    *piVar6 = iVar3;
    (**(code **)puVar8)(iVar5,(int *)(iVar3 + 0x20));
    piVar14 = (int *)(iVar3 + 0x20);
  }
  return piVar14;
}

/* _gleFeedbackPolygonPtr @ 0x51d9c (512 bytes) */
int _gleFeedbackPolygonPtr(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int *param_2;
  uint param_3;
  uint param_4;
{
  uint uVar1;
  double dVar2;
  undefined4 uVar3;
  int *piVar4;
  
  dVar2 = DOUBLE_00108d70;
  uVar1 = param_4 & 3;
  uVar3 = 0x707;
  if (uVar1 != 1) {
    if (uVar1 == 0) {
      piVar4 = param_2 + param_3;
      for (; param_2 < piVar4; param_2 = param_2 + 1) {
        if ((*(char *)(*param_2 + 0x7c) != '\0') && (*(char *)(*param_2 + 0x7d) == '\0')) {
          ((void (*)())_gleFeedbackToken)(param_1,(double)FLOAT_00108f28);
          ((int (*)())_gleFeedbackHitRecord)(param_1,*param_2);
        }
      }
      return;
    }
    if (uVar1 == 2) {
      ((void (*)())_gleFeedbackToken)(param_1,(double)FLOAT_00108f30);
      ((void (*)())_gleFeedbackToken)(param_1,(double)(float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) -
                                               DOUBLE_00108d58));
      piVar4 = param_2 + param_3;
      for (; param_2 < piVar4; param_2 = param_2 + 1) {
        ((int (*)())_gleFeedbackHitRecord)(param_1,*param_2);
      }
      return;
    }
    if (uVar1 != 3) {
      return;
    }
    uVar3 = 0x702;
  }
  for (piVar4 = param_2; piVar4 < param_2 + (param_3 - 1); piVar4 = piVar4 + 1) {
    if (*(char *)(*piVar4 + 0x7c) != '\0') {
      ((void (*)())_gleFeedbackToken)(param_1,(double)(float)((double)CONCAT44(0x43300000,uVar3) - dVar2));
      ((int (*)())_gleFeedbackHitRecord)(param_1,*piVar4);
      ((int (*)())_gleFeedbackHitRecord)(param_1,piVar4[1]);
      uVar3 = 0x702;
    }
  }
  if (*(char *)(*piVar4 + 0x7c) != '\0') {
    ((void (*)())_gleFeedbackToken)(param_1,(double)(float)((double)CONCAT44(0x43300000,uVar3) - DOUBLE_00108d70))
    ;
    ((int (*)())_gleFeedbackHitRecord)(param_1,*piVar4);
    ((int (*)())_gleFeedbackHitRecord)(param_1,*param_2);
  }
  return;
}

/* _gleFeedbackHitRecord @ 0x51f9c (528 bytes) */
int _gleFeedbackHitRecord(param_1, param_2)
  int param_1;
  float *param_2;
{
  uint uVar1;
  double fparam_1;
  
  if (*(char *)(param_1 + 0x4fdc) == '\0') {
    uVar1 = *(uint *)(param_1 + 0x4fd8);
    if (uVar1 == 0x601) {
      ((void (*)())_gleFeedbackToken)(param_1,(double)*param_2);
      ((void (*)())_gleFeedbackToken)(param_1,(double)param_2[1]);
      fparam_1 = (double)param_2[2];
      goto LAB_000520f4;
    }
    if (uVar1 < 0x602) {
      if (uVar1 == 0x600) {
        ((void (*)())_gleFeedbackToken)(param_1,(double)*param_2);
        fparam_1 = (double)param_2[1];
        goto LAB_000520f4;
      }
    }
    else {
      if (uVar1 == 0x602) {
        ((void (*)())_gleFeedbackToken)(param_1,(double)*param_2);
        ((void (*)())_gleFeedbackToken)(param_1,(double)param_2[1]);
        ((void (*)())_gleFeedbackToken)(param_1,(double)param_2[2]);
        ((void (*)())_gleFeedbackToken)(param_1,(double)param_2[0xc]);
        ((void (*)())_gleFeedbackToken)(param_1,(double)param_2[0xd]);
        ((void (*)())_gleFeedbackToken)(param_1,(double)param_2[0xe]);
        fparam_1 = (double)param_2[0xf];
LAB_000520f4:
        ((void (*)())_gleFeedbackToken)(param_1,fparam_1);
        return;
      }
      if (uVar1 == 0x603) {
        ((void (*)())_gleFeedbackToken)(param_1,(double)*param_2);
        ((void (*)())_gleFeedbackToken)(param_1,(double)param_2[1]);
        ((void (*)())_gleFeedbackToken)(param_1,(double)param_2[2]);
        ((void (*)())_gleFeedbackToken)(param_1,(double)param_2[0xc]);
        ((void (*)())_gleFeedbackToken)(param_1,(double)param_2[0xd]);
        ((void (*)())_gleFeedbackToken)(param_1,(double)param_2[0xe]);
        ((void (*)())_gleFeedbackToken)(param_1,(double)param_2[0xf]);
        ((void (*)())_gleFeedbackToken)(param_1,(double)param_2[0x20]);
        ((void (*)())_gleFeedbackToken)(param_1,(double)param_2[0x21]);
        ((void (*)())_gleFeedbackToken)(param_1,(double)param_2[0x22]);
        fparam_1 = (double)param_2[0x23];
        goto LAB_000520f4;
      }
    }
    ((void (*)())_gleFeedbackToken)(param_1,(double)*param_2);
    ((void (*)())_gleFeedbackToken)(param_1,(double)param_2[1]);
    ((void (*)())_gleFeedbackToken)(param_1,(double)param_2[2]);
    ((void (*)())_gleFeedbackToken)(param_1,(double)param_2[7]);
    ((void (*)())_gleFeedbackToken)(param_1,(double)param_2[0xc]);
    ((void (*)())_gleFeedbackToken)(param_1,(double)param_2[0xd]);
    ((void (*)())_gleFeedbackToken)(param_1,(double)param_2[0xe]);
    ((void (*)())_gleFeedbackToken)(param_1,(double)param_2[0xf]);
    ((void (*)())_gleFeedbackToken)(param_1,(double)param_2[0x20]);
    ((void (*)())_gleFeedbackToken)(param_1,(double)param_2[0x21]);
    ((void (*)())_gleFeedbackToken)(param_1,(double)param_2[0x22]);
    ((void (*)())_gleFeedbackToken)(param_1,(double)param_2[0x23]);
  }
  return;
}

/* _gleMultiTextureMatTransPtr @ 0x521ac (120 bytes) */
int _gleMultiTextureMatTransPtr(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = _gleTexEnableBits(param_1);
  uVar3 = 0;
  do {
    uVar1 = uVar2 >> (uVar3 & 0x3f);
    if ((uVar1 & 1) == 0) {
      if (uVar1 == 0) {
        return;
      }
    }
    else {
      (**(code **)(param_1 + 0x5078))(param_1,param_2,param_3,uVar3);
    }
    uVar3 = uVar3 + 1;
  } while( true );
}

/* _glLoadMatrixd_Exec @ 0x52224 (128 bytes) */
int _glLoadMatrixd_Exec(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  if ((*(short *)(param_1 + 0x4a10) < 0) && (*(int *)(param_1 + 0x4ff4) < 0x18)) {
    param_2 = ((int (*)())_gleLoadMatrixd)(param_2,*(undefined4 *)(param_1 + 0x4fec));
    *(uint *)(param_1 + 0x50ac) = *(uint *)(param_1 + 0x50ac) | *(uint *)(param_1 + 0x50a8);
    *(uint *)(param_1 + 0x50b0) = *(uint *)(param_1 + 0x50b0) | *(uint *)(param_1 + 0x50a8);
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
  }
  return param_2;
}

/* _gleLoadMatrixd @ 0x522a4 (196 bytes) */
int _gleLoadMatrixd(param_1, param_2)
  double *param_1;
  float *param_2;
{
  *param_2 = GH_U2F((unsigned int)(*param_1));
  param_2[1] = GH_U2F((unsigned int)(param_1[1]));
  param_2[2] = GH_U2F((unsigned int)(param_1[2]));
  param_2[3] = GH_U2F((unsigned int)(param_1[3]));
  param_2[4] = GH_U2F((unsigned int)(param_1[4]));
  param_2[5] = GH_U2F((unsigned int)(param_1[5]));
  param_2[6] = GH_U2F((unsigned int)(param_1[6]));
  param_2[7] = GH_U2F((unsigned int)(param_1[7]));
  param_2[8] = GH_U2F((unsigned int)(param_1[8]));
  param_2[9] = GH_U2F((unsigned int)(param_1[9]));
  param_2[10] = GH_U2F((unsigned int)(param_1[10]));
  param_2[0xb] = GH_U2F((unsigned int)(param_1[0xb]));
  param_2[0xc] = GH_U2F((unsigned int)(param_1[0xc]));
  param_2[0xd] = GH_U2F((unsigned int)(param_1[0xd]));
  param_2[0xe] = GH_U2F((unsigned int)(param_1[0xe]));
  param_2[0xf] = GH_U2F((unsigned int)(param_1[0xf]));
  return;
}

/* _glGetTexParameteriv_Exec @ 0x52368 (964 bytes) */
int _glGetTexParameteriv_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined *param_3;
  uint *param_4;
{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = _gleLookUpNonProxyTexture(param_1,param_2);
  fVar2 = FLOAT_00108e94;
  fVar1 = FLOAT_00108e90;
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_00052714;
  }
  if (iVar5 == 0) goto LAB_00052704;
  if (param_3 == (undefined *)0x813c) {
    uVar4 = (uint)*(short *)(iVar5 + 0x60);
    goto LAB_00052644;
  }
  if ((undefined *)0x813c < param_3) {
    if (param_3 == (undefined *)0x85b7) {
      uVar4 = *(uint *)(iVar5 + 0x70);
      goto LAB_00052644;
    }
    if (param_3 < (undefined *)0x85b8) {
      if (param_3 == (undefined *)0x84fe) {
        fVar1 = *(float *)(iVar5 + 0x50);
        goto LAB_00052638;
      }
      if (param_3 < (undefined *)0x84ff) {
        if (param_3 == (undefined *)0x813d) {
          uVar4 = (uint)*(short *)(iVar5 + 0x62);
          goto LAB_00052644;
        }
        if (param_3 == (undefined *)0x8191) {
          uVar4 = *(uint *)(iVar5 + 0x6c) >> 0xf & 1;
          goto LAB_00052644;
        }
      }
      else {
        if (param_3 == (undefined *)0x8501) {
          fVar1 = *(float *)(iVar5 + 0x5c);
          goto LAB_00052638;
        }
        if (param_3 == (undefined *)0x85b6) {
          uVar4 = *(uint *)(iVar5 + 0x6c) >> 7 & 1;
          goto LAB_00052644;
        }
      }
    }
    else {
      if (param_3 == (undefined *)0x884b) {
        uVar4 = (uint)*(ushort *)(iVar5 + 0x6c);
        goto LAB_00052644;
      }
      if (param_3 < (undefined *)0x884c) {
        if (param_3 == (undefined *)0x85bc) {
          uVar4 = (uint)*(ushort *)(iVar5 + 0x3e);
          goto LAB_00052644;
        }
        if (param_3 == (undefined *)0x871a) {
          *param_4 = (int)*(float *)(iVar5 + 0x40);
          param_4[1] = (int)*(float *)(iVar5 + 0x44);
          param_4[2] = (int)*(float *)(iVar5 + 0x48);
          fVar1 = *(float *)(iVar5 + 0x4c);
          goto LAB_000526f0;
        }
      }
      else {
        if (param_3 == (undefined *)0x884d) {
          uVar4 = (uint)*(ushort *)(iVar5 + 100);
          goto LAB_00052644;
        }
        if (param_3 < (undefined *)0x884d) {
          uVar4 = (uint)*(ushort *)(iVar5 + 0x66);
          goto LAB_00052644;
        }
        if (param_3 == (undefined *)0x8a7f) {
          uVar4 = *(uint *)(iVar5 + 0x6c) >> 6 & 1;
          goto LAB_00052644;
        }
      }
    }
LAB_00052704:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x500;
LAB_00052714:
    *(undefined4 *)(param_1 + 0x7574) = uVar3;
    return;
  }
  if (param_3 == (undefined *)0x8066) {
    fVar1 = *(float *)(iVar5 + 0x28);
  }
  else {
    if (param_3 < (undefined *)0x8067) {
      if (param_3 == (undefined *)0x2801) {
        uVar4 = (uint)*(ushort *)(iVar5 + 0x3a);
        goto LAB_00052644;
      }
      if (param_3 < (undefined *)0x2802) {
        if (param_3 == ((unsigned char *)0x00001004)) {
          *param_4 = (int)(*(float *)(iVar5 + 0x40) * FLOAT_00108e94 - FLOAT_00108e90);
          param_4[1] = (int)(*(float *)(iVar5 + 0x44) * fVar2 - fVar1);
          param_4[2] = (int)(*(float *)(iVar5 + 0x48) * fVar2 - fVar1);
          fVar1 = *(float *)(iVar5 + 0x4c) * fVar2 - fVar1;
LAB_000526f0:
          param_4[3] = (int)fVar1;
          return;
        }
        if (param_3 == (undefined *)0x2800) {
          uVar4 = (uint)*(ushort *)(iVar5 + 0x3c);
          goto LAB_00052644;
        }
      }
      else {
        if (param_3 == (undefined *)0x2802) {
          uVar4 = (uint)*(ushort *)(iVar5 + 0x34);
          goto LAB_00052644;
        }
        if (param_3 == (undefined *)0x2803) {
          uVar4 = (uint)*(ushort *)(iVar5 + 0x36);
          goto LAB_00052644;
        }
      }
      goto LAB_00052704;
    }
    if (param_3 == (undefined *)0x80bf) {
      fVar1 = *(float *)(iVar5 + 0x68);
    }
    else {
      if (param_3 < (undefined *)0x80c0) {
        if (param_3 == (undefined *)0x8067) {
          uVar4 = (**(code **)(param_1 + 0x47ac))
                            (*(undefined4 *)(param_1 + 0x4688),
                             *(undefined4 *)(iVar5 + (uint)*(byte *)(param_1 + 0x85a8) * 4));
          *param_4 = uVar4;
          return;
        }
        if (param_3 == (undefined *)0x8072) {
          uVar4 = (uint)*(ushort *)(iVar5 + 0x38);
          goto LAB_00052644;
        }
        goto LAB_00052704;
      }
      if (param_3 == (undefined *)0x813a) {
        fVar1 = *(float *)(iVar5 + 0x54);
      }
      else {
        if (param_3 != (undefined *)0x813b) goto LAB_00052704;
        fVar1 = *(float *)(iVar5 + 0x58);
      }
    }
  }
LAB_00052638:
  uVar4 = (uint)(int)fVar1;
LAB_00052644:
  *param_4 = uVar4;
  return;
}

/* _glGetTexParameterfv_Exec @ 0x5272c (916 bytes) */
int _glGetTexParameterfv_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined *param_3;
  float *param_4;
{
  float fVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = _gleLookUpNonProxyTexture(param_1,param_2);
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x502;
    goto LAB_00052aa8;
  }
  if (iVar4 != 0) {
    if (param_3 == (undefined *)0x813c) {
      uVar3 = (uint)*(short *)(iVar4 + 0x60);
LAB_000529b4:
      fVar1 = (float)((double)CONCAT44(0x43300000,uVar3 ^ 0x80000000) - DOUBLE_00108d58);
LAB_00052a3c:
      *param_4 = fVar1;
      return;
    }
    if (param_3 < (undefined *)0x813d) {
      if (param_3 == (undefined *)0x8066) {
        fVar1 = *(float *)(iVar4 + 0x28);
        goto LAB_00052a3c;
      }
      if (param_3 < (undefined *)0x8067) {
        if (param_3 == (undefined *)0x2801) {
          uVar3 = (uint)*(ushort *)(iVar4 + 0x3a);
          goto LAB_00052a80;
        }
        if (param_3 < (undefined *)0x2802) {
          if (param_3 == ((unsigned char *)0x00001004)) {
LAB_0005294c:
            *param_4 = *(float *)(iVar4 + 0x40);
            param_4[1] = *(float *)(iVar4 + 0x44);
            param_4[2] = *(float *)(iVar4 + 0x48);
            param_4[3] = *(float *)(iVar4 + 0x4c);
            return;
          }
          if (param_3 == (undefined *)0x2800) {
            uVar3 = (uint)*(ushort *)(iVar4 + 0x3c);
            goto LAB_00052a80;
          }
        }
        else {
          if (param_3 == (undefined *)0x2802) {
            uVar3 = (uint)*(ushort *)(iVar4 + 0x34);
            goto LAB_00052a80;
          }
          if (param_3 == (undefined *)0x2803) {
            uVar3 = (uint)*(ushort *)(iVar4 + 0x36);
            goto LAB_00052a80;
          }
        }
      }
      else {
        if (param_3 == (undefined *)0x80bf) {
          fVar1 = *(float *)(iVar4 + 0x68);
          goto LAB_00052a3c;
        }
        if (param_3 < (undefined *)0x80c0) {
          if (param_3 == (undefined *)0x8067) {
            uVar3 = (**(code **)(param_1 + 0x47ac))
                              (*(undefined4 *)(param_1 + 0x4688),
                               *(undefined4 *)(iVar4 + (uint)*(byte *)(param_1 + 0x85a8) * 4));
            uVar3 = uVar3 & 0xffff;
            goto LAB_00052a80;
          }
          if (param_3 == (undefined *)0x8072) {
            uVar3 = (uint)*(ushort *)(iVar4 + 0x38);
            goto LAB_00052a80;
          }
        }
        else {
          if (param_3 == (undefined *)0x813a) {
            fVar1 = *(float *)(iVar4 + 0x54);
            goto LAB_00052a3c;
          }
          if (param_3 == (undefined *)0x813b) {
            fVar1 = *(float *)(iVar4 + 0x58);
            goto LAB_00052a3c;
          }
        }
      }
    }
    else {
      if (param_3 == (undefined *)0x85b7) {
        uVar3 = *(uint *)(iVar4 + 0x70);
        goto LAB_000529b4;
      }
      if (param_3 < (undefined *)0x85b8) {
        if (param_3 == (undefined *)0x84fe) {
          fVar1 = *(float *)(iVar4 + 0x50);
          goto LAB_00052a3c;
        }
        if (param_3 < (undefined *)0x84ff) {
          if (param_3 == (undefined *)0x813d) {
            uVar3 = (uint)*(short *)(iVar4 + 0x62);
            goto LAB_000529b4;
          }
          if (param_3 == (undefined *)0x8191) {
            uVar3 = *(uint *)(iVar4 + 0x6c) >> 0xf & 1;
            goto LAB_00052a80;
          }
        }
        else {
          if (param_3 == (undefined *)0x8501) {
            fVar1 = *(float *)(iVar4 + 0x5c);
            goto LAB_00052a3c;
          }
          if (param_3 == (undefined *)0x85b6) {
            uVar3 = *(uint *)(iVar4 + 0x6c) >> 7 & 1;
            goto LAB_00052a80;
          }
        }
      }
      else {
        if (param_3 == (undefined *)0x884b) {
          uVar3 = (uint)*(ushort *)(iVar4 + 0x6c);
          goto LAB_00052a80;
        }
        if (param_3 < (undefined *)0x884c) {
          if (param_3 == (undefined *)0x85bc) {
            uVar3 = (uint)*(ushort *)(iVar4 + 0x3e);
            goto LAB_00052a80;
          }
          if (param_3 == (undefined *)0x871a) goto LAB_0005294c;
        }
        else {
          if (param_3 == (undefined *)0x884d) {
            uVar3 = (uint)*(ushort *)(iVar4 + 100);
LAB_00052a80:
            *param_4 = GH_U2F((unsigned int)((uVar3 | 0x4b000000))) - 8388608.0;
            return;
          }
          if (param_3 < (undefined *)0x884d) {
            uVar3 = (uint)*(ushort *)(iVar4 + 0x66);
            goto LAB_00052a80;
          }
          if (param_3 == (undefined *)0x8a7f) {
            uVar3 = *(uint *)(iVar4 + 0x6c) >> 6 & 1;
            goto LAB_00052a80;
          }
        }
      }
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar2 = 0x500;
LAB_00052aa8:
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
  return;
}

/* _glColor4d_Exec @ 0x52ac0 (60 bytes) */
void _glColor4d_Exec(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  *(float *)(param_1 + 0x2a0) = (float)fparam_1;
  *(float *)(param_1 + 0x2a4) = (float)fparam_2;
  *(float *)(param_1 + 0x2a8) = (float)fparam_3;
  *(float *)(param_1 + 0x2ac) = (float)fparam_4;
  if (*(char *)(param_1 + 0x4df8) == '\0') {
    return;
  }
                    
                    
  (**(code **)(param_1 + 0x4de0))(param_1,param_1 + 0x2a0);
  return;
}

/* _glFinishObjectAPPLE_Exec @ 0x52afc (900 bytes) */
int _glFinishObjectAPPLE_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  undefined4 param_3;
{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_00052bec;
  }
  if (param_2 == 0x8a0a) {
    return;
  }
  if (param_2 < 0x8a0b) {
    if (param_2 == 0x8074) {
      uVar3 = 2;
    }
    else if (param_2 < 0x8075) {
      if (param_2 != 0x1702) {
LAB_00052bdc:
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        uVar3 = 0x500;
LAB_00052bec:
        *(undefined4 *)(param_1 + 0x7574) = uVar3;
        return;
      }
      uVar3 = 1;
    }
    else {
      if (param_2 != 0x85b3) goto LAB_00052bdc;
      uVar3 = 3;
    }
  }
  else if (param_2 == 0x8d40) {
    uVar3 = 5;
  }
  else if (param_2 < 0x8d41) {
    if (param_2 != 0x8a0b) goto LAB_00052bdc;
    uVar3 = 0;
  }
  else {
    if (param_2 != 0x8d41) goto LAB_00052bdc;
    uVar3 = 4;
  }
  switch(uVar3) {
  case 0:
    iVar4 = _gleLookupHashObject(param_1 + 0x543c,param_3);
    if (iVar4 != 0) {
      iVar6 = param_1 + 0x10000;
      uVar7 = 0;
      if (*(char *)(param_1 + 0x85a4) == '\0') {
        return;
      }
      puVar8 = (undefined4 *)(iVar4 + 0x10);
      do {
        piVar1 = (int *)(iVar6 + -0x777c);
        uVar5 = *puVar8;
        uVar7 = uVar7 + 1;
        puVar8 = puVar8 + 1;
        puVar2 = (undefined4 *)(iVar6 + -0x7a54);
        iVar6 = iVar6 + 0x2e0;
        (**(code **)(*piVar1 + 0x1c4))(*puVar2,uVar3,uVar5);
      } while (uVar7 < *(byte *)(param_1 + 0x85a4));
      return;
    }
    break;
  case 1:
    iVar4 = _gleLookupHashObject(*(int *)(param_1 + 0x5148) + 0x2008,param_3);
    if (iVar4 != 0) {
      iVar6 = param_1 + 0x10000;
      uVar7 = 0;
      if (*(char *)(param_1 + 0x85a4) == '\0') {
        return;
      }
      puVar8 = (undefined4 *)(iVar4 + 0x10);
      do {
        piVar1 = (int *)(iVar6 + -0x777c);
        uVar5 = *puVar8;
        uVar7 = uVar7 + 1;
        puVar8 = puVar8 + 1;
        puVar2 = (undefined4 *)(iVar6 + -0x7a54);
        iVar6 = iVar6 + 0x2e0;
        (**(code **)(*piVar1 + 0x1c4))(*puVar2,uVar3,uVar5);
      } while (uVar7 < *(byte *)(param_1 + 0x85a4));
      return;
    }
    break;
  case 2:
    iVar4 = _gleLookupHashObject(*(int *)(param_1 + 0x5148) + 0x5014,param_3);
    if (iVar4 != 0) {
      iVar6 = param_1 + 0x10000;
      uVar7 = 0;
      if (*(char *)(param_1 + 0x85a4) == '\0') {
        return;
      }
      puVar8 = (undefined4 *)(iVar4 + 0x10);
      do {
        piVar1 = (int *)(iVar6 + -0x777c);
        uVar5 = *puVar8;
        uVar7 = uVar7 + 1;
        puVar8 = puVar8 + 1;
        puVar2 = (undefined4 *)(iVar6 + -0x7a54);
        iVar6 = iVar6 + 0x2e0;
        (**(code **)(*piVar1 + 0x1c4))(*puVar2,uVar3,uVar5);
      } while (uVar7 < *(byte *)(param_1 + 0x85a4));
      return;
    }
    break;
  case 3:
    iVar4 = _gleLookupHashObject(*(int *)(param_1 + 0x5148) + 0x701c,param_3);
    if (iVar4 != 0) {
      iVar6 = param_1 + 0x10000;
      uVar7 = 0;
      if (*(char *)(param_1 + 0x85a4) == '\0') {
        return;
      }
      puVar8 = (undefined4 *)(iVar4 + 0x10);
      do {
        piVar1 = (int *)(iVar6 + -0x777c);
        uVar5 = *puVar8;
        uVar7 = uVar7 + 1;
        puVar8 = puVar8 + 1;
        puVar2 = (undefined4 *)(iVar6 + -0x7a54);
        iVar6 = iVar6 + 0x2e0;
        (**(code **)(*piVar1 + 0x1c4))(*puVar2,uVar3,uVar5);
      } while (uVar7 < *(byte *)(param_1 + 0x85a4));
      return;
    }
    break;
  case 4:
    iVar4 = _gleLookupHashObject(((unsigned char *)0x00001004) + *(int *)(param_1 + 0x5148),param_3);
    if (iVar4 != 0) {
      iVar6 = param_1 + 0x10000;
      uVar7 = 0;
      if (*(char *)(param_1 + 0x85a4) == '\0') {
        return;
      }
      puVar8 = (undefined4 *)(iVar4 + 0x10);
      do {
        piVar1 = (int *)(iVar6 + -0x777c);
        uVar5 = *puVar8;
        uVar7 = uVar7 + 1;
        puVar8 = puVar8 + 1;
        puVar2 = (undefined4 *)(iVar6 + -0x7a54);
        iVar6 = iVar6 + 0x2e0;
        (**(code **)(*piVar1 + 0x1c4))(*puVar2,uVar3,uVar5);
      } while (uVar7 < *(byte *)(param_1 + 0x85a4));
      return;
    }
    break;
  case 5:
    goto switchD_00052c3c_caseD_5;
  default:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x500;
    goto LAB_00052e80;
  }
  if (*(int *)(param_1 + 0x7574) == 0) {
    uVar3 = 0x502;
LAB_00052e80:
    *(undefined4 *)(param_1 + 0x7574) = uVar3;
  }
switchD_00052c3c_caseD_5:
  return;
}

/* _gleSetEnable_POLYGON_SMOOTH @ 0x52e98 (20 bytes) */
int _gleSetEnable_POLYGON_SMOOTH(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  *(undefined1 *)(param_1 + 0x34d9) = (undefined1)param_3;
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x800000;
  return;
}

/* _gleFogExp @ 0x52eac (88 bytes) */
double _gleFogExp(int param_1,double fparam_1)
{
  float fVar1;
  float fVar2;
  
  fVar2 = *(float *)(param_1 + 0x24);
  if ((double)FLOAT_00108e50 < fparam_1) {
    fparam_1 = -fparam_1;
  }
  fVar1 = (float)((double)*(float *)(param_1 + 0x3150) * fparam_1);
  return (double)(fVar2 / ((((*(float *)(param_1 + 0x38) * fVar1 - *(float *)(param_1 + 0x34)) *
                             fVar1 + *(float *)(param_1 + 0x30)) * fVar1 - fVar2) * fVar1 + fVar2));
}

/* _glFogi_Exec @ 0x52f04 (652 bytes) */
int _glFogi_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint param_3;
{
  bool bVar1;
  byte bVar2;
  undefined4 uVar3;
  undefined4 extraout_r3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return param_1;
    }
    uVar3 = 0x502;
LAB_0005301c:
    *(undefined4 *)(param_1 + 0x7574) = uVar3;
    return param_1;
  }
  if (param_2 == 0xb64) {
    bVar1 = *(int *)(param_1 + 0x5434) == 0;
    *(float *)(param_1 + 0x3158) =
         (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
  }
  else {
    if (0xb64 < param_2) {
      uVar4 = (undefined2)param_3;
      if (param_2 == 0x8450) {
        if (param_3 - 0x8451 < 2) {
          *(undefined2 *)(param_1 + 0x3166) = uVar4;
          _gleSelectVertexSubmitFunc(param_1);
          goto LAB_00053168;
        }
      }
      else if (param_2 < 0x8451) {
        if (((param_2 == 0xb65) && (0x7ff < (int)param_3)) &&
           (((int)param_3 < 0x802 || (param_3 == 0x2601)))) {
          *(undefined2 *)(param_1 + 0x3164) = uVar4;
          goto LAB_00053168;
        }
      }
      else if ((param_2 == 0x855a) &&
              ((param_3 == 0x2502 || ((0x2501 < (int)param_3 && (param_3 - 0x855b < 2)))))) {
        *(undefined2 *)(param_1 + 0x3168) = uVar4;
        goto LAB_00053168;
      }
LAB_00053154:
      if (*(int *)(param_1 + 0x7574) == 0) {
        *(undefined4 *)(param_1 + 0x7574) = 0x500;
      }
      goto LAB_00053168;
    }
    if (param_2 == 0xb62) {
      if ((int)param_3 < 0) {
        if (*(int *)(param_1 + 0x7574) != 0) {
          return param_1;
        }
        uVar3 = 0x501;
        goto LAB_0005301c;
      }
      bVar1 = *(int *)(param_1 + 0x5434) == 0;
      *(float *)(param_1 + 0x3150) =
           (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
    }
    else {
      if (param_2 < 0xb63) {
        if (param_2 == 0xb61) {
          *(float *)(param_1 + 0x3160) =
               (float)((double)CONCAT44(0x43300000,param_3 * 0x101 ^ 0x80000000) - DOUBLE_00108d58);
          goto LAB_00053168;
        }
        goto LAB_00053154;
      }
      bVar1 = *(int *)(param_1 + 0x5434) == 0;
      *(float *)(param_1 + 0x3154) =
           (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58);
    }
  }
  if (bVar1) {
    bVar2 = *(byte *)(*(int *)(param_1 + 0x5420) + 0x323);
  }
  else {
    bVar2 = *(byte *)(*(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x357);
  }
  iVar6 = (bVar2 >> 3 & 0x1c) + param_1;
  iVar5 = *(int *)(param_1 + 0x5424);
  *(uint *)(iVar6 + 0x324) = *(uint *)(iVar6 + 0x324) | 1 << (bVar2 & 0x1f);
  bVar2 = *(byte *)(iVar5 + 0x323);
  iVar5 = (bVar2 >> 3 & 0x1c) + param_1;
  *(uint *)(iVar5 + 0x348) = *(uint *)(iVar5 + 0x348) | 1 << (bVar2 & 0x1f);
LAB_00053168:
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x800;
  ((double (*)())_gleUpdateFogData)(param_1);
  return extraout_r3;
}

/* _gleFogLinear @ 0x53190 (92 bytes) */
double _gleFogLinear(int param_1,double fparam_1)
{
  double dVar1;
  
  if ((double)FLOAT_00108e50 < fparam_1) {
    fparam_1 = -fparam_1;
  }
  dVar1 = (double)((float)((double)*(float *)(param_1 + 0x3158) + fparam_1) *
                  *(float *)(param_1 + 0x315c));
  if ((double)*(float *)(param_1 + 0x24) < dVar1) {
    return (double)*(float *)(param_1 + 0x24);
  }
  if ((double)FLOAT_00108e50 <= dVar1) {
    return dVar1;
  }
  return (double)FLOAT_00108e50;
}

/* _glFogfv_Exec @ 0x531ec (1096 bytes) */
int _glFogfv_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  float *param_3;
{
  bool bVar1;
  byte bVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined4 uVar6;
  undefined2 uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  double dVar11;
  
  fVar5 = FLOAT_00108e54;
  fVar4 = FLOAT_00108e50;
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar6 = 0x502;
LAB_000533ac:
    *(undefined4 *)(param_1 + 0x7574) = uVar6;
    return;
  }
  if (param_2 == 0xb64) {
    bVar1 = *(int *)(param_1 + 0x5434) == 0;
    *(float *)(param_1 + 0x3158) = *param_3;
LAB_00053594:
    if (bVar1) {
      bVar2 = *(byte *)(*(int *)(param_1 + 0x5420) + 0x323);
    }
    else {
      bVar2 = *(byte *)(*(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x357);
    }
    iVar10 = (bVar2 >> 3 & 0x1c) + param_1;
    iVar9 = *(int *)(param_1 + 0x5424);
    *(uint *)(iVar10 + 0x324) = *(uint *)(iVar10 + 0x324) | 1 << (bVar2 & 0x1f);
    bVar2 = *(byte *)(iVar9 + 0x323);
  }
  else {
    if (param_2 < 0xb65) {
      if (param_2 == 0xb62) {
        if (*param_3 < FLOAT_00108e50) {
          if (*(int *)(param_1 + 0x7574) != 0) {
            return;
          }
          uVar6 = 0x501;
          goto LAB_000533ac;
        }
        *(float *)(param_1 + 0x3150) = *param_3;
        bVar1 = *(int *)(param_1 + 0x5434) == 0;
      }
      else {
        if (param_2 < 0xb63) {
          if (param_2 == 0xb61) {
            *(float *)(param_1 + 0x3160) = *param_3 * FLOAT_00108e5c;
            goto LAB_0005360c;
          }
          goto LAB_000535f8;
        }
        bVar1 = *(int *)(param_1 + 0x5434) == 0;
        *(float *)(param_1 + 0x3154) = *param_3;
      }
      goto LAB_00053594;
    }
    if (param_2 != 0xb66) {
      if (param_2 < 0xb66) {
        dVar11 = (double)*param_3;
        if (DOUBLE_00108d80 <= dVar11) {
          uVar8 = (int)(dVar11 - DOUBLE_00108d80) ^ 0x80000000;
        }
        else {
          uVar8 = (uint)(int)*param_3;
        }
        if (uVar8 != 0x801) {
          if (uVar8 < 0x802) {
            bVar1 = uVar8 == 0x800;
          }
          else {
            bVar1 = uVar8 == 0x2601;
          }
          if (!bVar1) goto LAB_000535f8;
        }
        *(short *)(param_1 + 0x3164) = (short)uVar8;
      }
      else {
        if (param_2 == 0x8450) {
          fVar4 = *param_3;
          dVar11 = (double)fVar4;
          if (DOUBLE_00108d80 <= dVar11) {
            uVar8 = (int)(dVar11 - DOUBLE_00108d80) ^ 0x80000000;
          }
          else {
            uVar8 = (uint)(int)fVar4;
          }
          if (uVar8 - 0x8451 < 2) {
            if (DOUBLE_00108d80 <= dVar11) {
              uVar7 = (undefined2)(int)(dVar11 - DOUBLE_00108d80);
            }
            else {
              uVar7 = (undefined2)(int)fVar4;
            }
            *(undefined2 *)(param_1 + 0x3166) = uVar7;
            _gleSelectVertexSubmitFunc(param_1);
            goto LAB_0005360c;
          }
        }
        else if (param_2 == 0x855a) {
          fVar4 = *param_3;
          dVar11 = (double)fVar4;
          if (DOUBLE_00108d80 <= dVar11) {
            uVar8 = (int)(dVar11 - DOUBLE_00108d80) ^ 0x80000000;
          }
          else {
            uVar8 = (uint)(int)fVar4;
          }
          if ((uVar8 == 0x2502) || ((0x2501 < uVar8 && (uVar8 - 0x855b < 2)))) {
            if (DOUBLE_00108d80 <= dVar11) {
              uVar7 = (undefined2)(int)(dVar11 - DOUBLE_00108d80);
            }
            else {
              uVar7 = (undefined2)(int)fVar4;
            }
            *(undefined2 *)(param_1 + 0x3168) = uVar7;
            goto LAB_0005360c;
          }
        }
LAB_000535f8:
        if (*(int *)(param_1 + 0x7574) == 0) {
          *(undefined4 *)(param_1 + 0x7574) = 0x500;
        }
      }
      goto LAB_0005360c;
    }
    fVar3 = *param_3;
    if (FLOAT_00108e50 <= fVar3) {
      if (fVar3 <= FLOAT_00108e54) {
        *(float *)(param_1 + 0x3140) = fVar3;
      }
      else {
        *(float *)(param_1 + 0x3140) = FLOAT_00108e54;
      }
    }
    else {
      *(float *)(param_1 + 0x3140) = FLOAT_00108e50;
    }
    fVar3 = param_3[1];
    if (fVar4 <= fVar3) {
      if (fVar3 <= fVar5) {
        *(float *)(param_1 + 0x3144) = fVar3;
      }
      else {
        *(float *)(param_1 + 0x3144) = fVar5;
      }
    }
    else {
      *(float *)(param_1 + 0x3144) = fVar4;
    }
    fVar3 = param_3[2];
    if (fVar4 <= fVar3) {
      if (fVar3 <= fVar5) {
        *(float *)(param_1 + 0x3148) = fVar3;
      }
      else {
        *(float *)(param_1 + 0x3148) = fVar5;
      }
    }
    else {
      *(float *)(param_1 + 0x3148) = fVar4;
    }
    fVar3 = param_3[3];
    if (fVar4 <= fVar3) {
      if (fVar3 <= fVar5) {
        *(float *)(param_1 + 0x314c) = fVar3;
      }
      else {
        *(float *)(param_1 + 0x314c) = fVar5;
      }
    }
    else {
      *(float *)(param_1 + 0x314c) = fVar4;
    }
    if (*(int *)(param_1 + 0x5434) == 0) {
      bVar2 = *(byte *)(*(int *)(param_1 + 0x5420) + 0x322);
    }
    else {
      bVar2 = *(byte *)(*(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x356);
    }
    iVar10 = (bVar2 >> 3 & 0x1c) + param_1;
    iVar9 = *(int *)(param_1 + 0x5424);
    *(uint *)(iVar10 + 0x324) = *(uint *)(iVar10 + 0x324) | 1 << (bVar2 & 0x1f);
    bVar2 = *(byte *)(iVar9 + 0x322);
  }
  iVar9 = (bVar2 >> 3 & 0x1c) + param_1;
  *(uint *)(iVar9 + 0x348) = *(uint *)(iVar9 + 0x348) | 1 << (bVar2 & 0x1f);
LAB_0005360c:
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x800;
  ((double (*)())_gleUpdateFogData)(param_1);
  return;
}

/* _glFogf_Exec @ 0x53634 (700 bytes) */
void _glFogf_Exec(int param_1,uint param_2,double fparam_1)
{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x502;
LAB_000536f4:
    *(undefined4 *)(param_1 + 0x7574) = uVar2;
    return;
  }
  if (param_2 == 0xb64) {
    iVar3 = *(int *)(param_1 + 0x5434);
    *(float *)(param_1 + 0x3158) = (float)fparam_1;
  }
  else {
    if (0xb64 < param_2) {
      if (param_2 == 0x8450) {
        if (DOUBLE_00108d80 <= fparam_1) {
          uVar4 = (int)(fparam_1 - DOUBLE_00108d80) ^ 0x80000000;
        }
        else {
          uVar4 = (uint)(int)fparam_1;
        }
        if (uVar4 - 0x8451 < 2) {
          *(short *)(param_1 + 0x3166) = (short)uVar4;
          _gleSelectVertexSubmitFunc(param_1);
          goto LAB_000538c8;
        }
      }
      else if (param_2 < 0x8451) {
        if (param_2 == 0xb65) {
          if (DOUBLE_00108d80 <= fparam_1) {
            uVar4 = (int)(fparam_1 - DOUBLE_00108d80) ^ 0x80000000;
          }
          else {
            uVar4 = (uint)(int)fparam_1;
          }
          if ((0x7ff < uVar4) && ((uVar4 < 0x802 || (uVar4 == 0x2601)))) {
            *(short *)(param_1 + 0x3164) = (short)uVar4;
            goto LAB_000538c8;
          }
        }
      }
      else if (param_2 == 0x855a) {
        if (DOUBLE_00108d80 <= fparam_1) {
          uVar4 = (int)(fparam_1 - DOUBLE_00108d80) ^ 0x80000000;
        }
        else {
          uVar4 = (uint)(int)fparam_1;
        }
        if ((uVar4 == 0x2502) || ((0x2501 < uVar4 && (uVar4 - 0x855b < 2)))) {
          *(short *)(param_1 + 0x3168) = (short)uVar4;
          goto LAB_000538c8;
        }
      }
LAB_000538b4:
      if (*(int *)(param_1 + 0x7574) == 0) {
        *(undefined4 *)(param_1 + 0x7574) = 0x500;
      }
      goto LAB_000538c8;
    }
    if (param_2 == 0xb62) {
      if (fparam_1 < (double)FLOAT_00108e50) {
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        uVar2 = 0x501;
        goto LAB_000536f4;
      }
      iVar3 = *(int *)(param_1 + 0x5434);
      *(float *)(param_1 + 0x3150) = (float)fparam_1;
    }
    else {
      if (param_2 < 0xb63) {
        if (param_2 == 0xb61) {
          *(float *)(param_1 + 0x3160) = (float)(fparam_1 * (double)FLOAT_00108e5c);
          goto LAB_000538c8;
        }
        goto LAB_000538b4;
      }
      iVar3 = *(int *)(param_1 + 0x5434);
      *(float *)(param_1 + 0x3154) = (float)fparam_1;
    }
  }
  if (iVar3 == 0) {
    bVar1 = *(byte *)(*(int *)(param_1 + 0x5420) + 0x323);
  }
  else {
    bVar1 = *(byte *)(*(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x357);
  }
  iVar5 = (bVar1 >> 3 & 0x1c) + param_1;
  iVar3 = *(int *)(param_1 + 0x5424);
  *(uint *)(iVar5 + 0x324) = *(uint *)(iVar5 + 0x324) | 1 << (bVar1 & 0x1f);
  bVar1 = *(byte *)(iVar3 + 0x323);
  iVar3 = (bVar1 >> 3 & 0x1c) + param_1;
  *(uint *)(iVar3 + 0x348) = *(uint *)(iVar3 + 0x348) | 1 << (bVar1 & 0x1f);
LAB_000538c8:
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x800;
  ((double (*)())_gleUpdateFogData)(param_1);
  return;
}

/* _gleLightMaterialRGBAChange_FB_AD @ 0x538f0 (344 bytes) */
int _gleLightMaterialRGBAChange_FB_AD(param_1, param_2)
  int param_1;
  undefined8 *param_2;
{
  byte bVar1;
  undefined8 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined8 uVar8;
  
  iVar7 = 0;
  do {
    puVar2 = (undefined8 *)_glePushMaterial(param_1,iVar7);
    *puVar2 = *param_2;
    puVar2[1] = param_2[1];
    puVar2[2] = *param_2;
    uVar8 = param_2[1];
    *(ushort *)((int)puVar2 + 0x234) = *(ushort *)((int)puVar2 + 0x234) | 0xc0c;
    puVar2[3] = uVar8;
    iVar4 = *(int *)(param_1 + 0x5434);
    if (iVar4 == 0) {
      bVar1 = *(byte *)(iVar7 * 6 + *(int *)(param_1 + 0x5420) + 0x2c0);
    }
    else {
      bVar1 = *(byte *)(iVar7 * 6 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x2f4);
    }
    iVar5 = iVar7 * 6;
    iVar6 = (bVar1 >> 3 & 0x1c) + param_1;
    iVar3 = *(int *)(param_1 + 0x5424);
    *(uint *)(iVar6 + 0x324) = *(uint *)(iVar6 + 0x324) | 1 << (bVar1 & 0x1f);
    bVar1 = *(byte *)(iVar5 + iVar3 + 0x2c0);
    iVar6 = (bVar1 >> 3 & 0x1c) + param_1;
    *(uint *)(iVar6 + 0x348) = *(uint *)(iVar6 + 0x348) | 1 << (bVar1 & 0x1f);
    if (iVar4 == 0) {
      bVar1 = *(byte *)(iVar5 + *(int *)(param_1 + 0x5420) + 0x2c1);
    }
    else {
      bVar1 = *(byte *)(iVar5 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x2f5);
    }
    iVar4 = (bVar1 >> 3 & 0x1c) + param_1;
    iVar7 = iVar7 + 1;
    *(uint *)(iVar4 + 0x324) = *(uint *)(iVar4 + 0x324) | 1 << (bVar1 & 0x1f);
    bVar1 = *(byte *)(iVar5 + iVar3 + 0x2c1);
    iVar4 = (bVar1 >> 3 & 0x1c) + param_1;
    *(uint *)(iVar4 + 0x348) = *(uint *)(iVar4 + 0x348) | 1 << (bVar1 & 0x1f);
  } while (iVar7 < 2);
  return;
}

/* _glCopyTexImage2D_Exec @ 0x53a48 (1780 bytes) */
void _glCopyTexImage2D_Exec(int param_1,int param_2,uint param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,int param_7,int param_8,undefined4 param_9,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  ushort uVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  byte bVar8;
  uint uVar7;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  int *piVar16;
  int iVar17;
  double extraout_f1;
  
  if ((*(int *)(param_1 + 0x744c) != 0) || (*(int *)(param_1 + 0x310) < 0)) {
    iVar13 = *(int *)(param_1 + 0x50ac);
    uVar14 = param_3;
    uVar4 = param_4;
    uVar11 = param_5;
    uVar12 = param_6;
    if (iVar13 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
      _gleUpdateMatrixFunc(param_1);
      fparam_1 = extraout_f1;
    }
    if (*(char *)(param_1 + 0x4691) != '\0') {
      iVar10 = *(int *)(param_1 + 0x744c);
      piVar16 = (int *)(param_1 + 0x310);
      cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
      if ((iVar10 != 0) && (*(int *)(iVar10 + 0xec) != 0)) {
        ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar10 + 0x10,uVar14,uVar4,uVar11,uVar12,iVar13,fparam_1,fparam_2,
                   fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
        *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
      }
      if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_00053b9c:
        uVar14 = *(uint *)(param_1 + 0x31c);
      }
      else {
        iVar13 = 0;
        piVar5 = (int *)(param_1 + 0x324);
        do {
          iVar10 = *piVar5;
          piVar5 = piVar5 + 1;
          if (iVar10 != 0) {
            *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
            break;
          }
          iVar13 = iVar13 + 1;
        } while (iVar13 < 9);
        uVar14 = *(uint *)(param_1 + 0x31c);
        if ((uVar14 & 0x15555) != 0) {
          if (*(char *)(param_1 + 0x2e54) != '\0') {
            _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
          }
          if (*(char *)(param_1 + 0x3094) != '\0') {
            _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
          }
          goto LAB_00053b9c;
        }
      }
      bVar1 = cVar2 == '\0';
      if (bVar1) {
        uVar14 = uVar14 & 0x17000000;
      }
      else {
        uVar14 = uVar14 & 0x17ffffff;
      }
      if (bVar1) {
        bVar1 = ((*piVar16 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar14 == 0) &&
                *(int *)(param_1 + 800) == 0;
      }
      else {
        bVar1 = (((*piVar16 == 0 && *(int *)(param_1 + 0x314) == 0) &&
                 (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar14 == 0) &&
                *(int *)(param_1 + 800) == 0;
      }
      if (!bVar1) {
        if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
          uVar14 = (**(code **)(param_1 + 0x4788))
                             (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar16);
          if ((((uVar14 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
              ((uVar14 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
             ((uVar14 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
            if ((uVar14 & 4) == 0) {
              uVar14 = uVar14 & 0xfffffffe;
              *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
            }
            _gleUpdateDispatchCodeChange(param_1,uVar14);
            if (*(char *)(param_1 + 0x759d) == '\0') {
              if (*(int *)(param_1 + 0x7574) != 0) {
                return;
              }
              uVar4 = 0x506;
              goto LAB_00053d34;
            }
          }
        }
        else {
          _gleSwitchToNonRevertRenderer(param_1);
        }
        iVar13 = 0x13;
        do {
          *piVar16 = 0;
          piVar16 = piVar16 + 1;
          iVar13 = iVar13 + -1;
        } while (iVar13 != 0);
      }
    }
  }
  if (-1 < *(short *)(param_1 + 0x4a10)) {
LAB_00053d24:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar4 = 0x502;
LAB_00053d34:
    *(undefined4 *)(param_1 + 0x7574) = uVar4;
    return;
  }
  iVar13 = ((int (*)())_gleCheckCopyTexImage2DArgs)(param_1,param_2,param_3,param_4,param_7,param_8,param_9);
  if (iVar13 == 0) {
    return;
  }
  uVar3 = *(ushort *)(iVar13 + 0x24);
  if ((uVar3 & 0x3c00) != 0x1000) {
    if ((uVar3 & 0x3c00) == 0) {
      *(ushort *)(iVar13 + 0x24) = uVar3 | 0x1000;
    }
    else if ((uVar3 & 0xc00) != 0) goto LAB_00053d24;
  }
  iVar10 = param_7;
  iVar15 = param_8;
  if ((*(uint *)(param_1 + 0x3410) & 2) == 0) {
    if (((*(uint *)(param_1 + 0x3410) & 4) != 0) && (*(short *)(param_1 + 0x3348) == -0x7fea)) {
      iVar15 = *(int *)(param_1 + 0x3354);
      iVar10 = *(int *)(param_1 + 0x3350);
      goto LAB_00053d90;
    }
  }
  else if (*(short *)(param_1 + 0x3308) == -0x7fea) {
    iVar15 = *(int *)(param_1 + 0x3314);
    iVar10 = *(int *)(param_1 + 0x3310);
LAB_00053d90:
    iVar10 = (param_7 - iVar10) + 1;
    iVar15 = (param_8 - iVar15) + 1;
  }
  uVar14 = param_2 - 0x8515;
  if (5 < uVar14) {
    uVar14 = 0;
  }
  iVar6 = iVar13 + uVar14 * 0x168 + param_3 * 0x18;
  iVar17 = iVar6 + 0xc4;
  if ((*(byte *)(iVar6 + 0xcf) & 0x20) != 0) {
    _gleDeletePluginTextureLevel(param_1,iVar13,iVar17,uVar14,param_3);
    if (*(int *)(iVar6 + 0xd8) != 0) {
      bVar8 = *(byte *)(iVar6 + 0xcf);
      if ((bVar8 & 1) == 0) {
        _gleFreeTextureLevel(param_1,iVar13,iVar17);
        bVar8 = *(byte *)(iVar6 + 0xcf);
      }
      else {
        *(undefined4 *)(iVar6 + 0xd8) = 0;
      }
      *(byte *)(iVar6 + 0xcf) = bVar8 & 0xef;
    }
    *(byte *)(iVar6 + 0xcf) = *(byte *)(iVar6 + 0xcf) & 0xdf;
  }
  iVar15 = _gleCreateTextureLevel
                     (param_1,iVar13,iVar17,param_4,iVar10,iVar15,1,param_9,0x1908,0x1401,0,0);
  if (iVar15 != 0) {
    _gleCreatePluginTextureLevel(param_1,iVar13,iVar17,uVar14,param_3,param_4);
    if ((((int)param_3 < (int)(uint)*(byte *)(iVar13 + 0x8d)) ||
        ((int)(uint)*(byte *)(iVar13 + 0x8f) < (int)param_3)) ||
       (iVar15 = uVar14 * 2 + iVar13, (*(ushort *)(iVar15 + 0x94) >> (param_3 & 0x3f) & 1) == 0)) {
LAB_00053fcc:
      bVar8 = *(byte *)(iVar6 + 0xcf);
    }
    else {
      bVar8 = *(byte *)(iVar6 + 0xcf);
      if ((bVar8 & 0x80) == 0) {
        iVar9 = (**(code **)(param_1 + 0x470c))
                          (*(undefined4 *)(param_1 + 0x4688),
                           *(undefined4 *)(iVar13 + (uint)*(byte *)(param_1 + 0x85a8) * 4),uVar14,
                           param_3,0,0,0,param_5);
        if (iVar9 != 0) {
          *(undefined4 *)(iVar13 + 0x20) =
               *(undefined4 *)
                ((uint)*(byte *)(param_1 + 0x85a8) * 4 + *(int *)(param_1 + 0x5148) + 0x8054);
          *(byte *)(iVar6 + 0xcf) = *(byte *)(iVar6 + 0xcf) | 0x40;
          if ((((*(uint *)(iVar13 + 0x6c) & 0x8000) != 0) &&
              ((int)*(short *)(iVar13 + 0x60) == param_3)) &&
             (uVar7 = param_3 + 1, (int)uVar7 <= (int)(uint)*(byte *)(iVar13 + 0x83))) {
            iVar10 = uVar7 * 0x18 + uVar14 * 0x168 + iVar13 + 0xc4;
            do {
              if (*(int *)(iVar10 + 0x14) != 0) {
                if (((*(byte *)(iVar10 + 0xb) & 1) == 0) && (*(short *)(iVar13 + 0x3e) == -0x7a43))
                {
                  _gleFreeTextureLevel(param_1,iVar13,iVar10);
                }
                *(byte *)(iVar10 + 0xb) = *(byte *)(iVar10 + 0xb) & 0xef;
                *(ushort *)(iVar15 + 0xa0) =
                     *(ushort *)(iVar15 + 0xa0) & ~(ushort)(1 << (uVar7 & 0x3f));
              }
              uVar7 = uVar7 + 1;
              *(byte *)(iVar10 + 0xb) = *(byte *)(iVar10 + 0xb) | 0x40;
              iVar10 = iVar10 + 0x18;
            } while ((int)uVar7 <= (int)(uint)*(byte *)(iVar13 + 0x83));
          }
          uVar14 = *(uint *)(param_1 + 0x53d4);
          uVar7 = *(uint *)(param_1 + 0x314);
          goto LAB_00054120;
        }
        goto LAB_00053fcc;
      }
    }
    if ((bVar8 & 0x10) == 0) {
      if ((bVar8 & 0x40) == 0) {
        if (*(int *)(iVar6 + 0xd8) == 0) {
          _gleAllocateTextureLevel(param_1,iVar13,iVar17);
          bVar8 = *(byte *)(iVar6 + 0xcf);
        }
        *(byte *)(iVar6 + 0xcf) = bVar8 | 0x10;
      }
      else {
        _gleUploadPluginTextureLevel
                  (param_1,iVar13,iVar17,uVar14,param_3,(uint)*(byte *)(param_1 + 0x85a8));
      }
    }
    _gleModifyPluginTextureLevel(param_1,iVar13,iVar17,uVar14,param_3,0,0,0,iVar10);
    _gleTextureImageCopy(param_1,iVar17,param_4,param_5,param_6,param_7,param_8);
    if ((((*(uint *)(iVar13 + 0x6c) & 0x8000) != 0) && ((int)*(short *)(iVar13 + 0x60) == param_3))
       && (iVar13 = _gleGenMipmapsToLevel(param_1,iVar13,uVar14,param_3,0xf,1), iVar13 != 0)) {
      return;
    }
  }
  uVar14 = *(uint *)(param_1 + 0x53d4);
  uVar7 = *(uint *)(param_1 + 0x314);
LAB_00054120:
  *(uint *)(param_1 + 0x314) = uVar7 | 1 << (uVar14 & 0x3f);
  return;
}

/* _gleCheckCopyTexImage2DArgs @ 0x5413c (492 bytes) */
int _gleCheckCopyTexImage2DArgs(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
  int param_6;
  int param_7;
{
  ushort uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  
  iVar3 = _gleLookUpNonProxyTexture2D(param_1,param_2);
  uVar4 = 1;
  uVar7 = 1;
  if (iVar3 == 0) {
    if (*(int *)(param_1 + 0x7574) == 0) {
      uVar4 = 0x500;
LAB_000542e0:
      *(undefined4 *)(param_1 + 0x7574) = uVar4;
    }
LAB_000542e4:
    iVar2 = 0;
  }
  else {
    if ((*(uint *)(param_1 + 0x3410) & 2) == 0) {
      if (((*(uint *)(param_1 + 0x3410) & 4) != 0) && (*(short *)(param_1 + 0x3348) == -0x7fea)) {
        iVar6 = *(int *)(param_1 + 0x3354);
        iVar2 = *(int *)(param_1 + 0x3350);
        goto LAB_000541e0;
      }
    }
    else if (*(short *)(param_1 + 0x3308) == -0x7fea) {
      iVar6 = *(int *)(param_1 + 0x3314);
      iVar2 = *(int *)(param_1 + 0x3310);
LAB_000541e0:
      param_5 = (param_5 - iVar2) + 1;
      param_6 = (param_6 - iVar6) + 1;
    }
    uVar8 = param_6 + param_7 * -2;
    uVar9 = param_5 + param_7 * -2;
    uVar1 = *(ushort *)(iVar3 + 0x24) & 0xf;
    if (uVar1 == 2) {
      uVar7 = 0;
      if ((((int)uVar9 < 0) ||
          (uVar5 = (uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0xc0), (int)uVar5 < (int)uVar9))
         || ((int)uVar8 < 0)) goto LAB_000542d0;
LAB_000542cc:
      if ((int)uVar5 < (int)uVar8) {
LAB_000542d0:
        if (*(int *)(param_1 + 0x7574) == 0) {
          uVar4 = 0x501;
          goto LAB_000542e0;
        }
        goto LAB_000542e4;
      }
    }
    else if (uVar1 < 3) {
      if ((*(ushort *)(iVar3 + 0x24) & 0xf) == 0) {
        uVar4 = 0;
        if ((uVar9 != uVar8) ||
           ((int)(uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0xc2) < (int)uVar8))
        goto LAB_000542d0;
LAB_00054244:
        if (-1 < (int)uVar9) {
          if ((uVar9 & uVar9 - 1) == 0) {
            iVar2 = *(int *)(param_1 + 0x468c);
          }
          else {
            iVar2 = *(int *)(param_1 + 0x468c);
            if ((*(uint *)(iVar2 + 0x124) & 0x80000) == 0) goto LAB_000542d0;
          }
          uVar5 = (uint)*(ushort *)(iVar2 + 0xbc);
          if ((((int)uVar9 <= (int)uVar5) && (-1 < (int)uVar8)) &&
             (((uVar8 & uVar8 - 1) == 0 || ((*(uint *)(iVar2 + 0x124) & 0x80000) != 0))))
          goto LAB_000542cc;
        }
        goto LAB_000542d0;
      }
    }
    else if (uVar1 == 3) goto LAB_00054244;
    iVar6 = ((int (*)())_gleCheckCopyTexImageArgs)(param_1,param_3,param_4,param_7,uVar4,uVar7);
    iVar2 = 0;
    if (iVar6 != 0) {
      iVar2 = iVar3;
    }
  }
  return iVar2;
}

/* _gleCheckCopyTexImageArgs @ 0x54328 (552 bytes) */
int _gleCheckCopyTexImageArgs(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  uint param_2;
  int param_3;
  uint param_4;
  int param_5;
  int param_6;
{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  
  bVar1 = true;
  if (0xe < param_2) {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x501;
    }
    bVar1 = false;
  }
  if (!bVar1) {
    return 0;
  }
  if (param_3 < 0x83f4) {
    if (0x83ef < param_3) goto LAB_00054528;
    if (param_3 < 0x804e) {
      if (param_3 < 0x803b) {
        if (param_3 == 0x1902) goto LAB_000544f8;
        if (param_3 < 0x1903) {
          bVar1 = 3 < param_3 - 1U;
          goto LAB_000544e0;
        }
        if (param_3 < 0x1906) goto LAB_000544e4;
        if (0x190a < param_3) {
          bVar1 = param_3 == 0x2a10;
          goto LAB_00054478;
        }
      }
      goto LAB_00054528;
    }
    if (32999 < param_3) {
      if (2 < param_3 - 0x81a5U) goto LAB_000544e4;
LAB_000544f8:
      if (param_5 == 0) {
        if (*(int *)(param_1 + 0x7574) != 0) {
          return 0;
        }
        uVar2 = 0x502;
        goto LAB_00054544;
      }
      goto LAB_00054528;
    }
    if (param_3 < 0x80e2) {
      uVar3 = param_3 - 0x804f;
      goto LAB_000544b8;
    }
    if (param_6 != 0) goto LAB_00054528;
  }
  else {
    if (param_3 < 0x8700) {
      if (param_3 < 0x86fe) {
        if (0x86f6 < param_3) {
          bVar1 = 4 < param_3 - 0x86f8U;
          goto LAB_000544e0;
        }
        if (param_3 < 0x86f4) {
          if (param_3 < 0x84e9) goto LAB_000544e4;
          if (0x84ee < param_3) {
            bVar1 = param_3 == 0x86dc;
LAB_00054478:
            if (!bVar1) goto LAB_000544e4;
          }
        }
      }
    }
    else if (param_3 < 0x8820) {
      if (param_3 < 0x8814) {
        uVar3 = param_3 - 0x8701;
LAB_000544b8:
        bVar1 = 0xc < uVar3;
LAB_000544e0:
        if (bVar1) {
LAB_000544e4:
          if (*(int *)(param_1 + 0x7574) != 0) {
            return 0;
          }
          uVar2 = 0x501;
          goto LAB_00054544;
        }
      }
    }
    else if (param_3 != 0x8837) {
      if (param_3 < 0x8837) goto LAB_000544e4;
      bVar1 = 1 < param_3 - 0x885eU;
      goto LAB_000544e0;
    }
LAB_00054528:
    if ((param_4 & 0xfffffffe) == 0) {
      return 1;
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return 0;
  }
  uVar2 = 0x500;
LAB_00054544:
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
  return 0;
}

/* _glRasterPos2i_Exec @ 0x54550 (740 bytes) */
void _glRasterPos2i_Exec(int param_1,uint param_2,uint param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar6;
  uint uVar7;
  int *piVar8;
  double extraout_f1;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((*(int *)(param_1 + 0x744c) != 0) || (*(int *)(param_1 + 0x310) < 0)) {
      iVar6 = *(int *)(param_1 + 0x50ac);
      uVar7 = param_3;
      if (iVar6 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
        _gleUpdateMatrixFunc(param_1);
        fparam_1 = extraout_f1;
      }
      if (*(char *)(param_1 + 0x4691) != '\0') {
        iVar5 = *(int *)(param_1 + 0x744c);
        piVar8 = (int *)(param_1 + 0x310);
        cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
        if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
          ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,uVar7,in_r6,in_r7,in_r8,iVar6,fparam_1,fparam_2,fparam_3,
                     fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
          *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
        }
        if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_000546a8:
          uVar7 = *(uint *)(param_1 + 0x31c);
        }
        else {
          iVar6 = 0;
          piVar4 = (int *)(param_1 + 0x324);
          do {
            iVar5 = *piVar4;
            piVar4 = piVar4 + 1;
            if (iVar5 != 0) {
              *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
              break;
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 < 9);
          uVar7 = *(uint *)(param_1 + 0x31c);
          if ((uVar7 & 0x15555) != 0) {
            if (*(char *)(param_1 + 0x2e54) != '\0') {
              _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
            }
            if (*(char *)(param_1 + 0x3094) != '\0') {
              _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
            }
            goto LAB_000546a8;
          }
        }
        bVar1 = cVar2 == '\0';
        if (bVar1) {
          uVar7 = uVar7 & 0x17000000;
        }
        else {
          uVar7 = uVar7 & 0x17ffffff;
        }
        if (bVar1) {
          bVar1 = ((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar7 == 0) &&
                  *(int *)(param_1 + 800) == 0;
        }
        else {
          bVar1 = (((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) &&
                   (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar7 == 0) &&
                  *(int *)(param_1 + 800) == 0;
        }
        if (!bVar1) {
          if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
            uVar7 = (**(code **)(param_1 + 0x4788))
                              (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar8);
            if ((((uVar7 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
                ((uVar7 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
               ((uVar7 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
              if ((uVar7 & 4) == 0) {
                uVar7 = uVar7 & 0xfffffffe;
                *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
              }
              _gleUpdateDispatchCodeChange(param_1,uVar7);
              if (*(char *)(param_1 + 0x759d) == '\0') {
                if (*(int *)(param_1 + 0x7574) != 0) {
                  return;
                }
                uVar3 = 0x506;
                goto LAB_000547a4;
              }
            }
          }
          else {
            _gleSwitchToNonRevertRenderer(param_1);
          }
          iVar6 = 0x13;
          do {
            *piVar8 = 0;
            piVar8 = piVar8 + 1;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
        }
      }
    }
    ((void (*)())_gleSetRasterPos)(param_1,(double)(float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) -
                                            DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) -
                                    DOUBLE_00108d58),(double)FLOAT_00108e50,(double)FLOAT_00108e54);
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
LAB_000547a4:
    *(undefined4 *)(param_1 + 0x7574) = uVar3;
  }
  return;
}

/* _gleSetRasterPos @ 0x54834 (1524 bytes) */
void _gleSetRasterPos(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  undefined4 *puVar1;
  bool bVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  int iVar14;
  int iVar15;
  int *piVar16;
  undefined4 uVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  double dVar21;
  
  iVar14 = *(int *)(param_1 + 0x4854);
  *(undefined1 *)(param_1 + 0x2ef) = 0;
  iVar19 = iVar14 + -0x200;
  if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5434) == 0)) {
    iVar20 = 8;
    iVar18 = iVar19;
    iVar15 = param_1;
    do {
      puVar1 = (undefined4 *)(iVar15 + 0x120);
      uVar17 = *(undefined4 *)(iVar15 + 0x124);
      uVar7 = *(undefined4 *)(iVar15 + 0x128);
      uVar8 = *(undefined4 *)(iVar15 + 300);
      iVar15 = iVar15 + 0x10;
      *(undefined4 *)(iVar18 + 0x80) = *puVar1;
      *(undefined4 *)(iVar18 + 0x84) = uVar17;
      *(undefined4 *)(iVar18 + 0x88) = uVar7;
      *(undefined4 *)(iVar18 + 0x8c) = uVar8;
      iVar18 = iVar18 + 0x10;
      iVar20 = iVar20 + -1;
    } while (iVar20 != 0);
    *(undefined4 *)(iVar14 + -0x184) = *(undefined4 *)(param_1 + 0x2ec);
    if (*(char *)(param_1 + 0x53e4) != '\0') {
      *(float *)(iVar14 + -0x1e0) = (float)fparam_1;
      *(float *)(iVar14 + -0x1dc) = (float)fparam_2;
      *(float *)(iVar14 + -0x1d8) = (float)fparam_3;
      *(float *)(iVar14 + -0x1d4) = (float)fparam_4;
      (**(code **)(param_1 + 0x53dc))(param_1,iVar19,1);
    }
    fVar3 = (float)(fparam_4 * (double)*(float *)(param_1 + 0x1cf4) +
                   (double)(float)(fparam_3 * (double)*(float *)(param_1 + 0x1ce4) +
                                  (double)(float)(fparam_1 * (double)*(float *)(param_1 + 0x1cc4) +
                                                 (double)(float)(fparam_2 *
                                                                (double)*(float *)(param_1 + 0x1cd4)
                                                                ))));
    fVar4 = (float)(fparam_4 * (double)*(float *)(param_1 + 0x1cf0) +
                   (double)(float)(fparam_3 * (double)*(float *)(param_1 + 0x1ce0) +
                                  (double)(float)(fparam_1 * (double)*(float *)(param_1 + 0x1cc0) +
                                                 (double)(float)(fparam_2 *
                                                                (double)*(float *)(param_1 + 0x1cd0)
                                                                ))));
    fVar5 = (float)(fparam_4 * (double)*(float *)(param_1 + 0x1cf8) +
                   (double)(float)(fparam_3 * (double)*(float *)(param_1 + 0x1ce8) +
                                  (double)(float)(fparam_1 *
                                                  (double)*(float *)(0x1cc8 + param_1) +
                                                 (double)(float)(fparam_2 *
                                                                (double)*(float *)(param_1 + 0x1cd8)
                                                                ))));
    fVar6 = (float)(fparam_4 * (double)*(float *)(param_1 + 0x1cfc) +
                   (double)(float)(fparam_3 * (double)*(float *)(param_1 + 0x1cec) +
                                  (double)(float)(fparam_1 * (double)*(float *)(param_1 + 0x1ccc) +
                                                 (double)(float)(fparam_2 *
                                                                (double)*(float *)(param_1 + 0x1cdc)
                                                                ))));
    fVar12 = fVar6 * *(float *)(param_1 + 0x1cbc) +
             (fVar5 * *(float *)(param_1 + 0x1cac) +
             (fVar4 * *(float *)(param_1 + 0x1c8c) + fVar3 * *(float *)(param_1 + 0x1c9c)));
    fVar11 = fVar6 * *(float *)(param_1 + 0x1cb0) +
             (fVar5 * *(float *)(param_1 + 0x1ca0) +
             (fVar4 * *(float *)(param_1 + 0x1c80) + fVar3 * *(float *)(param_1 + 0x1c90)));
    fVar10 = fVar6 * *(float *)(param_1 + 0x1cb8) +
             (fVar5 * *(float *)(param_1 + 0x1ca8) +
             (fVar4 * *(float *)(param_1 + 0x1c88) + fVar3 * *(float *)(param_1 + 0x1c98)));
    fVar9 = fVar6 * *(float *)(param_1 + 0x1cb4) +
            (fVar5 * *(float *)(param_1 + 0x1ca4) +
            (fVar4 * *(float *)(param_1 + 0x1c84) + fVar3 * *(float *)(param_1 + 0x1c94)));
    fVar13 = -fVar12;
    if (((*(char *)(param_1 + 0x50b5) == '\0') &&
        ((((fVar11 < fVar13 || (fVar12 < fVar11)) || (fVar9 < fVar13)) || (fVar12 < fVar9)))) ||
       ((fVar10 < fVar13 || (fVar12 < fVar10)))) goto LAB_00054e14;
    if (*(char *)(param_1 + 0x4e18) != '\0') {
      iVar18 = 0;
      if (0 < *(int *)(param_1 + 0x4dfc)) {
        piVar16 = (int *)(param_1 + 0x4e00);
        do {
          iVar15 = *piVar16;
          piVar16 = piVar16 + 1;
          iVar15 = param_1 + iVar15 * 0x10;
          if (fVar6 * *(float *)(iVar15 + 0x4198) +
              (fVar5 * *(float *)(iVar15 + 0x4194) +
              (fVar4 * *(float *)(iVar15 + 0x418c) + fVar3 * *(float *)(iVar15 + 0x4190))) <
              FLOAT_00108e50) goto LAB_00054e14;
          iVar18 = iVar18 + 1;
        } while (iVar18 < *(int *)(param_1 + 0x4dfc));
      }
    }
    *(float *)(iVar14 + -0x1e0) = fVar4;
    fVar4 = FLOAT_00108e50;
    *(float *)(iVar14 + -0x1dc) = fVar3;
    *(float *)(iVar14 + -0x1d8) = fVar5;
    *(float *)(iVar14 + -0x1d4) = fVar6;
    *(float *)(iVar14 + -0x1f0) = fVar11;
    *(float *)(iVar14 + -0x1ec) = fVar9;
    *(float *)(iVar14 + -0x1e8) = fVar10;
    *(float *)(iVar14 + -0x1e4) = fVar12;
    if (fVar12 < fVar4) {
      bVar2 = fVar12 <= FLOAT_00108f3c;
    }
    else {
      bVar2 = FLOAT_00108e80 <= fVar12;
    }
    if (bVar2) {
      fVar3 = FLOAT_00108e54 / fVar12;
    }
    else {
      fVar3 = FLOAT_00108f7c;
      if (FLOAT_00108e50 <= fVar12) {
        fVar3 = FLOAT_00108eb4;
      }
    }
    *(float *)(param_1 + 0x2e0) =
         *(float *)(param_1 + 0x4a2c) * fVar11 * fVar3 + *(float *)(param_1 + 0x4a30);
    *(float *)(param_1 + 0x2e4) =
         *(float *)(param_1 + 0x4a34) * fVar9 * fVar3 + *(float *)(param_1 + 19000);
    *(float *)(param_1 + 0x2e8) =
         *(float *)(param_1 + 0x4a3c) * fVar10 * fVar3 + *(float *)(param_1 + 0x4a40);
    *(float *)(iVar14 + -500) = fVar3;
    if (*(int *)(param_1 + 0x50ac) != 0 ||
        (*(uint *)(param_1 + 0x50b0) & *(uint *)(param_1 + 0x505c)) != 0) {
      _gleUpdateMatrixFunc(param_1);
    }
    if ((*(char *)(param_1 + 0x30aa) != '\0') || (*(char *)(param_1 + 0x53e6) != '\0')) {
      fVar3 = *(float *)(param_1 + 0x2b4);
      fVar4 = *(float *)(param_1 + 0x2b0);
      fVar5 = *(float *)(param_1 + 0x2b8);
      *(float *)(iVar14 + -0x1c0) =
           fVar5 * *(float *)(param_1 + 0x22e0) +
           (fVar4 * *(float *)(param_1 + 0x22c0) + fVar3 * *(float *)(param_1 + 0x22d0));
      *(float *)(iVar14 + -0x1bc) =
           fVar5 * *(float *)(param_1 + 0x22e4) +
           (fVar4 * *(float *)(param_1 + 0x22c4) + fVar3 * *(float *)(param_1 + 0x22d4));
      *(float *)(iVar14 + -0x1b8) =
           fVar5 * *(float *)(param_1 + 0x22e8) +
           (fVar4 * *(float *)(param_1 + 0x22c8) + fVar3 * *(float *)(param_1 + 0x22d8));
      if (*(char *)(param_1 + 0x280d) != '\0') {
        (**(code **)PTR__gleVectorNormalize_00112064)(param_1,iVar14 + -0x1c0,iVar14 + -0x1c0);
      }
    }
    if (*(char *)(param_1 + 0x53e5) != '\0') {
      (**(code **)(param_1 + 0x53e0))(param_1,iVar19,1);
    }
    (**(code **)(param_1 + 0x506c))(param_1,iVar19,1,0);
    if (*(short *)(param_1 + 0x3166) == -0x7baf) {
      *(undefined4 *)(iVar14 + -0x1d8) = *(undefined4 *)(param_1 + 0x2cc);
    }
    dVar21 = (double)(**(double ( **)(int,double))(param_1 + 0x4fe4))(param_1, (double)*(float *)(iVar14 + -0x1d8));
    *(float *)(iVar14 + -0x1b4) = (float)dVar21;
    if (*(char *)(param_1 + 0x30aa) == '\0') {
      *(undefined8 *)(iVar14 + -0x1d0) = *(undefined8 *)(param_1 + 0x2a0);
      *(undefined8 *)(iVar14 + -0x1c8) = *(undefined8 *)(param_1 + 0x2a8);
      *(undefined8 *)(iVar14 + -0x1b0) = *(undefined8 *)(param_1 + 0x2c0);
      *(undefined4 *)(iVar14 + -0x1a8) = *(undefined4 *)(param_1 + 0x2c8);
    }
    else {
      *(undefined4 *)(iVar14 + -0x18c) = *(undefined4 *)(param_1 + 0x4dd0);
      *(undefined4 *)(iVar14 + -0x188) = *(undefined4 *)(param_1 + 0x4dd4);
      (**(code **)(param_1 + 0x4de8))(param_1,iVar19,1);
    }
    iVar18 = *(int *)(param_1 + 0x4e1c);
  }
  else {
    iVar18 = *(int *)(param_1 + 0x48d0);
    *(int *)(param_1 + 0x4858) = iVar14;
    uVar17 = *(undefined4 *)(param_1 + 0x4864);
    if (iVar18 != 0) {
      *(undefined4 *)(param_1 + 0x48d0) = 0;
      _gleSelectVertexSubmitFunc(param_1);
    }
    (**(int ( **)(int,double,double,double,double))(param_1 + 0x4888))(param_1, fparam_1, fparam_2, fparam_3, fparam_4);
    if (iVar18 != 0) {
      *(int *)(param_1 + 0x48d0) = iVar18;
      _gleSelectVertexSubmitFunc(param_1);
    }
    *(int *)(param_1 + 0x4864) = iVar19;
    _gleVPEmulate(param_1,1);
    *(undefined4 *)(param_1 + 0x4864) = uVar17;
    iVar18 = *(int *)(param_1 + 0x4e1c);
    *(float *)(param_1 + 0x2e0) =
         *(float *)(param_1 + 0x4a2c) * *(float *)(iVar14 + -0x1f0) * *(float *)(iVar14 + -0x1e4) +
         *(float *)(param_1 + 0x4a30);
    *(float *)(param_1 + 0x2e4) =
         *(float *)(param_1 + 0x4a34) * *(float *)(iVar14 + -0x1ec) * *(float *)(iVar14 + -0x1e4) +
         *(float *)(param_1 + 19000);
    *(float *)(param_1 + 0x2e8) =
         *(float *)(param_1 + 0x4a3c) * *(float *)(iVar14 + -0x1e8) * *(float *)(iVar14 + -0x1e4) +
         *(float *)(param_1 + 0x4a40);
  }
  if (iVar18 == 0x1c02) {
    _gleSelectHit(param_1,iVar19);
  }
  *(undefined1 *)(param_1 + 0x2ef) = 1;
LAB_00054e14:
  FUN_00008b68();
  return;
}

/* _glBitmap_Exec @ 0x54e2c (984 bytes) */
void _glBitmap_Exec(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  float *pfVar9;
  int iVar10;
  int *piVar11;
  double extraout_f1;
  double fparam_1_00;
  double extraout_f1_00;
  double fparam_2_00;
  double fparam_3_00;
  double fparam_4_00;
  
  iVar4 = *(int *)(param_1 + 0x4854);
  pfVar9 = (float *)(iVar4 + -0x200);
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((-1 < param_2) && (-1 < param_3)) {
      iVar10 = *(int *)(param_1 + 0x4a6c);
      iVar7 = param_3;
      fparam_1_00 = fparam_1;
      fparam_2_00 = fparam_2;
      fparam_3_00 = fparam_3;
      fparam_4_00 = fparam_4;
      if (iVar10 != 0) {
        param_4 = 0;
        param_5 = 0x1a00;
        iVar6 = _gleOffsetLimitImage(param_1 + 0x31cc,param_2,param_3,0,0x1a00,param_8);
        if (*(int *)(iVar10 + 0x38) < iVar6) goto LAB_00054ec8;
        param_6 = param_8;
        fparam_1_00 = extraout_f1;
        if (*(int *)(iVar10 + 0x40) != 0) {
          fparam_1_00 = (double)_gleSynchronizePluginBuffer(param_1,iVar10 + 0x10);
          param_6 = param_8;
        }
      }
      if (*(char *)(param_1 + 0x2ef) == '\0') goto LAB_000551f0;
      if (*(int *)(param_1 + 0x4e1c) == 0x1c00) {
        if ((0 < param_2) && (0 < param_3)) {
          iVar10 = *(int *)(param_1 + 0x50ac);
          if (iVar10 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
            _gleUpdateMatrixFunc(param_1);
            fparam_1_00 = extraout_f1_00;
          }
          if (*(char *)(param_1 + 0x4691) != '\0') {
            iVar6 = *(int *)(param_1 + 0x744c);
            piVar11 = (int *)(param_1 + 0x310);
            cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
            if ((iVar6 != 0) && (*(int *)(iVar6 + 0xec) != 0)) {
              ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar6 + 0x10,iVar7,param_4,param_5,param_6,iVar10,fparam_1_00,
                         fparam_2_00,fparam_3_00,fparam_4_00,fparam_5,fparam_6,fparam_7,fparam_8);
              *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
            }
            if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_0005501c:
              uVar8 = *(uint *)(param_1 + 0x31c);
            }
            else {
              iVar7 = 0;
              piVar5 = (int *)(param_1 + 0x324);
              do {
                iVar10 = *piVar5;
                piVar5 = piVar5 + 1;
                if (iVar10 != 0) {
                  *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
                  break;
                }
                iVar7 = iVar7 + 1;
              } while (iVar7 < 9);
              uVar8 = *(uint *)(param_1 + 0x31c);
              if ((uVar8 & 0x15555) != 0) {
                if (*(char *)(param_1 + 0x2e54) != '\0') {
                  _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
                }
                if (*(char *)(param_1 + 0x3094) != '\0') {
                  _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
                }
                goto LAB_0005501c;
              }
            }
            bVar1 = cVar2 == '\0';
            if (bVar1) {
              uVar8 = uVar8 & 0x17000000;
            }
            else {
              uVar8 = uVar8 & 0x17ffffff;
            }
            if (bVar1) {
              bVar1 = ((*piVar11 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar8 == 0) &&
                      *(int *)(param_1 + 800) == 0;
            }
            else {
              bVar1 = (((*piVar11 == 0 && *(int *)(param_1 + 0x314) == 0) &&
                       (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar8 == 0) &&
                      *(int *)(param_1 + 800) == 0;
            }
            if (!bVar1) {
              if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
                uVar8 = (**(code **)(param_1 + 0x4788))
                                  (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar11);
                if ((((uVar8 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
                    ((uVar8 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
                   ((uVar8 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
                  if ((uVar8 & 4) == 0) {
                    uVar8 = uVar8 & 0xfffffffe;
                    *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
                  }
                  _gleUpdateDispatchCodeChange(param_1,uVar8);
                  if (*(char *)(param_1 + 0x759d) == '\0') {
                    if (*(int *)(param_1 + 0x7574) != 0) goto LAB_000551f0;
                    uVar3 = 0x506;
                    goto LAB_00055118;
                  }
                }
              }
              else {
                _gleSwitchToNonRevertRenderer(param_1);
              }
              iVar7 = 0x13;
              do {
                *piVar11 = 0;
                piVar11 = piVar11 + 1;
                iVar7 = iVar7 + -1;
              } while (iVar7 != 0);
            }
          }
          *pfVar9 = *(float *)(param_1 + 0x4a44) * *(float *)(param_1 + 0x2e0) +
                    *(float *)(param_1 + 0x4a48);
          *(float *)(iVar4 + -0x1fc) =
               *(float *)(param_1 + 0x4a4c) * *(float *)(param_1 + 0x2e4) +
               *(float *)(param_1 + 0x4a50);
          *(float *)(iVar4 + -0x1f8) = *(float *)(param_1 + 0x4a54) * *(float *)(param_1 + 0x2e8);
          (**(int ( **)(int,int,int,int,double,double))(param_1 + 0x46ac))
                    (*(undefined4 *)(param_1 + 0x4688), pfVar9, param_2, param_3, fparam_1, fparam_2);
        }
      }
      else if (*(int *)(param_1 + 0x4e1c) == 0x1c01) {
        *pfVar9 = *(float *)(param_1 + 0x2e0);
        *(undefined4 *)(iVar4 + -0x1fc) = *(undefined4 *)(param_1 + 0x2e4);
        *(undefined4 *)(iVar4 + -0x1f8) = *(undefined4 *)(param_1 + 0x2e8);
        _gleFeedbackBitmap(param_1,pfVar9);
      }
      *(float *)(param_1 + 0x2e0) = (float)((double)*(float *)(param_1 + 0x2e0) + fparam_3);
      *(float *)(param_1 + 0x2e4) = (float)((double)*(float *)(param_1 + 0x2e4) + fparam_4);
      goto LAB_000551f0;
    }
    if (*(int *)(param_1 + 0x7574) != 0) goto LAB_000551f0;
    uVar3 = 0x501;
  }
  else {
LAB_00054ec8:
    if (*(int *)(param_1 + 0x7574) != 0) goto LAB_000551f0;
    uVar3 = 0x502;
  }
LAB_00055118:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
LAB_000551f0:
  FUN_00008b68();
  return;
}

/* _glCopyPixels_Exec @ 0x55204 (976 bytes) */
void _glCopyPixels_Exec(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,int param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  float *pfVar13;
  double extraout_f1;
  
  iVar6 = *(int *)(param_1 + 0x4854);
  pfVar13 = (float *)(iVar6 + -0x200);
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_000555bc;
  }
  if ((param_4 < 0) || (param_5 < 0)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x501;
    goto LAB_000555bc;
  }
  if (param_6 - 0x1800U < 3) {
    if (*(char *)(param_1 + 0x2ef) == '\0') {
      return;
    }
    uVar4 = *(uint *)(param_1 + 0x4e1c);
    if (uVar4 == 0x1c01) {
      *(undefined4 *)(iVar6 + -0x200) = *(undefined4 *)(param_1 + 0x2e0);
      *(undefined4 *)(iVar6 + -0x1fc) = *(undefined4 *)(param_1 + 0x2e4);
      *(undefined4 *)(iVar6 + -0x1f8) = *(undefined4 *)(param_1 + 0x2e8);
      _gleFeedbackCopyPixels(param_1,pfVar13);
      return;
    }
    if (uVar4 < 0x1c02) {
      if (uVar4 == 0x1c00) {
        if (*(float *)(param_1 + 0x31a8) == FLOAT_00108e50) {
          return;
        }
        if (*(float *)(param_1 + 0x31ac) == FLOAT_00108e50) {
          return;
        }
        if (param_4 == 0) {
          return;
        }
        if (param_5 == 0) {
          return;
        }
        iVar10 = *(int *)(param_1 + 0x50ac);
        uVar3 = param_3;
        iVar11 = param_4;
        iVar5 = param_5;
        iVar9 = param_6;
        if (iVar10 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
          _gleUpdateMatrixFunc(param_1);
          fparam_1 = extraout_f1;
        }
        if (*(char *)(param_1 + 0x4691) == '\0') goto LAB_0005550c;
        iVar8 = *(int *)(param_1 + 0x744c);
        piVar12 = (int *)(param_1 + 0x310);
        cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
        if ((iVar8 != 0) && (*(int *)(iVar8 + 0xec) != 0)) {
          ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar8 + 0x10,uVar3,iVar11,iVar5,iVar9,iVar10,fparam_1,fparam_2,fparam_3
                     ,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
          *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
        }
        if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_000553e8:
          uVar4 = *(uint *)(param_1 + 0x31c);
        }
        else {
          iVar11 = 0;
          piVar7 = (int *)(param_1 + 0x324);
          do {
            iVar5 = *piVar7;
            piVar7 = piVar7 + 1;
            if (iVar5 != 0) {
              *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
              break;
            }
            iVar11 = iVar11 + 1;
          } while (iVar11 < 9);
          uVar4 = *(uint *)(param_1 + 0x31c);
          if ((uVar4 & 0x15555) != 0) {
            if (*(char *)(param_1 + 0x2e54) != '\0') {
              _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
            }
            if (*(char *)(param_1 + 0x3094) != '\0') {
              _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
            }
            goto LAB_000553e8;
          }
        }
        bVar1 = cVar2 == '\0';
        if (bVar1) {
          uVar4 = uVar4 & 0x17000000;
        }
        else {
          uVar4 = uVar4 & 0x17ffffff;
        }
        if (bVar1) {
          bVar1 = ((*piVar12 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar4 == 0) &&
                  *(int *)(param_1 + 800) == 0;
        }
        else {
          bVar1 = (((*piVar12 == 0 && *(int *)(param_1 + 0x314) == 0) &&
                   (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar4 == 0) &&
                  *(int *)(param_1 + 800) == 0;
        }
        if (!bVar1) {
          if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
            uVar4 = (**(code **)(param_1 + 0x4788))
                              (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar12);
            if ((((uVar4 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
                ((uVar4 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
               ((uVar4 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
              if ((uVar4 & 4) == 0) {
                uVar4 = uVar4 & 0xfffffffe;
                *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
              }
              _gleUpdateDispatchCodeChange(param_1,uVar4);
              if (*(char *)(param_1 + 0x759d) == '\0') {
                if (*(int *)(param_1 + 0x7574) != 0) {
                  return;
                }
                uVar3 = 0x506;
                goto LAB_000555bc;
              }
            }
          }
          else {
            _gleSwitchToNonRevertRenderer(param_1);
          }
          iVar11 = 0x13;
          do {
            *piVar12 = 0;
            piVar12 = piVar12 + 1;
            iVar11 = iVar11 + -1;
          } while (iVar11 != 0);
        }
LAB_0005550c:
        *pfVar13 = *(float *)(param_1 + 0x4a44) * *(float *)(param_1 + 0x2e0) +
                   *(float *)(param_1 + 0x4a48);
        *(float *)(iVar6 + -0x1fc) =
             *(float *)(param_1 + 0x4a4c) * *(float *)(param_1 + 0x2e4) +
             *(float *)(param_1 + 0x4a50);
        *(float *)(iVar6 + -0x1f8) = *(float *)(param_1 + 0x4a54) * *(float *)(param_1 + 0x2e8);
                    
                    
        (**(code **)(param_1 + 0x46a8))
                  (*(undefined4 *)(param_1 + 0x4688),pfVar13,param_2,param_3,param_4,param_5,param_6
                  );
        return;
      }
    }
    else if (uVar4 == 0x1c02) {
      return;
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar3 = 0x500;
LAB_000555bc:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

