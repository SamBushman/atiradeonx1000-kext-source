#include "decls.h"

/* _PPCTextureSamplerSampleTexelRECTRTCNO @ 0x97be1e9c (488 bytes) */
int _PPCTextureSamplerSampleTexelRECTRTCNO(param_1, param_2, param_3)
  int *param_1;
  uint param_2;
  uint *param_3;
{
  short sVar1;
  short sVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  
  if (7 < param_2) {
    param_2 = 7;
  }
  piVar4 = *(int **)(param_2 * 4 + *param_1);
  if (piVar4 != (int *)0x0) {
    param_1[1] = (int)piVar4;
    sVar1 = *(short *)(*piVar4 + 0x10);
    sVar2 = *(short *)(*piVar4 + 0x12);
    if ((sVar1 == -0x7ed3) || (sVar2 == -0x7ed3)) {
      iVar6 = 0x812d;
    }
    else if ((sVar1 == 0x2900) || (iVar6 = 0, sVar2 == 0x2900)) {
      iVar6 = 0x2900;
    }
    if ((param_1[5] != param_2) || (param_1[6] != 2)) {
      *param_3 = param_2 * 4 & 0xfffc | 0x82220000;
      puVar7 = param_3 + 1;
      if (sVar1 == 0x2901) {
        *puVar7 = 0x82910160;
        puVar7 = param_3 + 2;
      }
      if (sVar2 == 0x2901) {
        *puVar7 = 0x82b10164;
        puVar7 = puVar7 + 1;
      }
      if (iVar6 == 0x812d) {
        *puVar7 = 0x82510190;
        puVar7[1] = 0xc1d10170;
        puVar7[2] = 0xc1f10174;
        uVar3 = 0x823101c4;
      }
      else if (iVar6 == 0x2900) {
        *puVar7 = 0x82510190;
        puVar7[1] = 0xc1d10170;
        puVar7[2] = 0xc1f10174;
        uVar3 = 0x823101c8;
      }
      else {
        *puVar7 = 0x82510140;
        puVar7[1] = 0xc1d10120;
        puVar7[2] = 0xc1f10124;
        uVar3 = 0x823101c0;
      }
      puVar7[3] = uVar3;
      param_3 = puVar7 + 4;
      param_1[7] = iVar6;
      param_1[5] = param_2;
      param_1[6] = 2;
    }
    iVar6 = _glpRTCAddAChunk(&_glpOpTexPrepareCoords4CCRTC,param_3);
    iVar5 = _glpRTCAddAChunk(&_glpOpTexSampleRTC,param_3 + iVar6);
    param_3 = param_3 + iVar6 + iVar5;
  }
  return param_3;
}

/* _PPCTextureSamplerWrapCoordinates1DRTCAV @ 0x97be2084 (144 bytes) */
int _PPCTextureSamplerWrapCoordinates1DRTCAV(param_1, param_2)
  int param_1;
  int param_2;
{
  short sVar1;
  short sVar2;
  undefined *puVar3;
  int iVar4;
  
  sVar1 = *(short *)(**(int **)(param_1 + 4) + 0x16);
  sVar2 = *(short *)(**(int **)(param_1 + 4) + 0x10);
  if (((sVar1 == 0x2600) || (sVar1 == 0x2700)) && (sVar2 == 0x2900)) {
    sVar2 = -0x7ed1;
  }
  if (sVar2 == 0x2901) {
    puVar3 = &_glpOpTexWrapCoordsRRRAVRTC;
  }
  else {
    puVar3 = &_glpOpTexWrapCoordsCCCAVRTC;
  }
  iVar4 = _glpRTCAddAChunk(puVar3,param_2);
  return param_2 + iVar4 * 4;
}

/* _PPCTextureSamplerWrapCoordinates2DRTCAV @ 0x97be2114 (212 bytes) */
int _PPCTextureSamplerWrapCoordinates2DRTCAV(param_1, param_2)
  int param_1;
  int param_2;
{
  short sVar1;
  undefined *puVar2;
  int iVar3;
  short sVar4;
  
  iVar3 = **(int **)(param_1 + 4);
  sVar1 = *(short *)(iVar3 + 0x10);
  sVar4 = *(short *)(iVar3 + 0x12);
  if ((*(short *)(iVar3 + 0x16) == 0x2600) || (*(short *)(iVar3 + 0x16) == 0x2700)) {
    if (sVar1 == 0x2900) {
      sVar1 = -0x7ed1;
    }
    if (sVar4 == 0x2900) {
      sVar4 = -0x7ed1;
    }
  }
  if (sVar1 == 0x2901) {
    if (sVar4 == 0x2901) {
      puVar2 = &_glpOpTexWrapCoordsRRRAVRTC;
    }
    else {
      puVar2 = &_glpOpTexWrapCoordsRCCAVRTC;
    }
  }
  else if (sVar4 == 0x2901) {
    puVar2 = &_glpOpTexWrapCoordsCRRAVRTC;
  }
  else {
    puVar2 = &_glpOpTexWrapCoordsCCCAVRTC;
  }
  iVar3 = _glpRTCAddAChunk(puVar2,param_2);
  return param_2 + iVar3 * 4;
}

/* _PPCTextureSamplerWrapCoordinates3DRTCAV @ 0x97be21e8 (328 bytes) */
int _PPCTextureSamplerWrapCoordinates3DRTCAV(param_1, param_2)
  int param_1;
  int param_2;
{
  short sVar1;
  undefined *puVar2;
  int iVar3;
  short sVar4;
  short sVar5;
  
  iVar3 = **(int **)(param_1 + 4);
  sVar1 = *(short *)(iVar3 + 0x10);
  sVar5 = *(short *)(iVar3 + 0x12);
  sVar4 = *(short *)(iVar3 + 0x14);
  if ((*(short *)(iVar3 + 0x16) == 0x2600) || (*(short *)(iVar3 + 0x16) == 0x2700)) {
    if (sVar1 == 0x2900) {
      sVar1 = -0x7ed1;
    }
    if (sVar5 == 0x2900) {
      sVar5 = -0x7ed1;
    }
    if (sVar4 == 0x2900) {
      sVar4 = -0x7ed1;
    }
  }
  if (sVar1 == 0x2901) {
    if (sVar5 == 0x2901) {
      if (sVar4 == 0x2901) {
        puVar2 = &_glpOpTexWrapCoordsRRRAVRTC;
      }
      else {
        puVar2 = &_glpOpTexWrapCoordsRRCAVRTC;
      }
    }
    else if (sVar4 == 0x2901) {
      puVar2 = &_glpOpTexWrapCoordsRCRAVRTC;
    }
    else {
      puVar2 = &_glpOpTexWrapCoordsRCCAVRTC;
    }
  }
  else if (sVar5 == 0x2901) {
    if (sVar4 == 0x2901) {
      puVar2 = &_glpOpTexWrapCoordsCRRAVRTC;
    }
    else {
      puVar2 = &_glpOpTexWrapCoordsCRCAVRTC;
    }
  }
  else if (sVar4 == 0x2901) {
    puVar2 = &_glpOpTexWrapCoordsCCRAVRTC;
  }
  else {
    puVar2 = &_glpOpTexWrapCoordsCCCAVRTC;
  }
  iVar3 = _glpRTCAddAChunk(puVar2,param_2);
  return param_2 + iVar3 * 4;
}

/* _PPCTextureSamplerSampleTexel1DRTCAV @ 0x97be2330 (780 bytes) */
int _PPCTextureSamplerSampleTexel1DRTCAV(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  uint *param_3;
{
  uint *puVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  int *piVar5;
  uint *puVar6;
  
  piVar5 = *(int **)(param_2 * 4 + *param_1);
  if (*(ushort *)(*piVar5 + 0x16) - 0x2700 < 4) {
    param_1[10] = 1;
    if (param_1[9] != 0) {
      *param_3 = 0x39e00200;
      param_3[1] = 0x7c4379ce;
      param_3 = param_3 + 2;
    }
    uVar4 = param_2 * 4 & 0xfffcU | 0x82220000;
    *param_3 = uVar4;
    param_3[1] = 0x39e00120;
    param_3[2] = 0x7df178ce;
    param_3[3] = 0x39e00040;
    param_3[4] = 0x7c2c78ce;
    param_3[5] = 0x39ef00c0;
    param_3[6] = 0x7c4c78ce;
    iVar2 = _glpRTCAddAChunk(&_glpOpTexCalculateLambda1DAVRTC,param_3 + 7);
    puVar1 = param_3 + 7 + iVar2;
    *puVar1 = 0x39e00040;
    puVar1[1] = 0x7c9178ce;
    puVar1[2] = 0x1063200a;
    puVar6 = puVar1 + 3;
    if (param_1[9] != 0) {
      *puVar6 = 0x39e00200;
      puVar1[4] = 0x7c4378ce;
      puVar1[5] = 0x1063100a;
      puVar6 = puVar1 + 6;
    }
    *puVar6 = 0x39e00030;
    puVar6[1] = 0x7c3178ce;
    puVar6[2] = 0x39e00020;
    puVar6[3] = 0x7c5178ce;
    puVar6[4] = 0x1063144a;
    puVar6[5] = 0x10630c0a;
    puVar6[6] = 0x10601a8c;
    puVar6[7] = 0x10801b8a;
    puVar6[8] = 0x39e00200;
    puVar6[9] = 0x7c8379ce;
    puVar6[10] = 0x7f03782e;
    if (*(ushort *)(*piVar5 + 0x16) - 0x2700 < 2) {
      puVar3 = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel1DFromLevelRTCAV)(param_1,param_2,puVar6 + 0xb);
    }
    else {
      puVar6[0xb] = 0x10801aca;
      puVar6[0xc] = 0x1083204a;
      puVar6[0xd] = 0x39e00210;
      puVar6[0xe] = 0x7c8379ce;
      puVar6[0xf] = 0x39e00230;
      puVar6[0x10] = 0x7c0379ce;
      puVar3 = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel1DFromLevelRTCAV)(param_1,param_2,puVar6 + 0x11);
      *puVar3 = 0x39e00220;
      puVar3[1] = 0x7c4379ce;
      puVar3[2] = 0x3b180001;
      puVar3[3] = 0x39e00230;
      puVar3[4] = 0x7c0378ce;
      puVar3[5] = uVar4;
      puVar3 = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel1DFromLevelRTCAV)(param_1,param_2,puVar3 + 6);
      *puVar3 = 0x39e00220;
      puVar3[1] = 0x7c2378ce;
      puVar3[2] = 0x39e00210;
      puVar3[3] = 0x7c0378ce;
      puVar3[4] = 0x1000028c;
      puVar3[5] = 0x1068004a;
      puVar3[6] = 0x1063386e;
      puVar3[7] = 0x104018ae;
      puVar3 = puVar3 + 8;
    }
    return puVar3;
  }
  param_1[10] = 0;
  puVar3 = (undefined4 *)((int (*)())_PPCTextureSamplerSampleTexel1DFromLevelRTCAV)();
  return puVar3;
}

/* _PPCTextureSamplerSampleTexel2DRTCAV @ 0x97be263c (780 bytes) */
int _PPCTextureSamplerSampleTexel2DRTCAV(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  uint *param_3;
{
  uint *puVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  int *piVar5;
  uint *puVar6;
  
  piVar5 = *(int **)(param_2 * 4 + *param_1);
  if (*(ushort *)(*piVar5 + 0x16) - 0x2700 < 4) {
    param_1[10] = 1;
    if (param_1[9] != 0) {
      *param_3 = 0x39e00200;
      param_3[1] = 0x7c4379ce;
      param_3 = param_3 + 2;
    }
    uVar4 = param_2 * 4 & 0xfffcU | 0x82220000;
    *param_3 = uVar4;
    param_3[1] = 0x39e00120;
    param_3[2] = 0x7df178ce;
    param_3[3] = 0x39e00040;
    param_3[4] = 0x7c2c78ce;
    param_3[5] = 0x39ef00c0;
    param_3[6] = 0x7c4c78ce;
    iVar2 = _glpRTCAddAChunk(&_glpOpTexCalculateLambda2DAVRTC,param_3 + 7);
    puVar1 = param_3 + 7 + iVar2;
    *puVar1 = 0x39e00040;
    puVar1[1] = 0x7c9178ce;
    puVar1[2] = 0x1063200a;
    puVar6 = puVar1 + 3;
    if (param_1[9] != 0) {
      *puVar6 = 0x39e00200;
      puVar1[4] = 0x7c4378ce;
      puVar1[5] = 0x1063100a;
      puVar6 = puVar1 + 6;
    }
    *puVar6 = 0x39e00030;
    puVar6[1] = 0x7c3178ce;
    puVar6[2] = 0x39e00020;
    puVar6[3] = 0x7c5178ce;
    puVar6[4] = 0x1063144a;
    puVar6[5] = 0x10630c0a;
    puVar6[6] = 0x10601a8c;
    puVar6[7] = 0x10801b8a;
    puVar6[8] = 0x39e00200;
    puVar6[9] = 0x7c8379ce;
    puVar6[10] = 0x7f03782e;
    if (*(ushort *)(*piVar5 + 0x16) - 0x2700 < 2) {
      puVar3 = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel2DFromLevelRTCAV)(param_1,param_2,puVar6 + 0xb);
    }
    else {
      puVar6[0xb] = 0x10801aca;
      puVar6[0xc] = 0x1083204a;
      puVar6[0xd] = 0x39e00210;
      puVar6[0xe] = 0x7c8379ce;
      puVar6[0xf] = 0x39e00230;
      puVar6[0x10] = 0x7c0379ce;
      puVar3 = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel2DFromLevelRTCAV)(param_1,param_2,puVar6 + 0x11);
      *puVar3 = 0x39e00220;
      puVar3[1] = 0x7c4379ce;
      puVar3[2] = 0x3b180001;
      puVar3[3] = 0x39e00230;
      puVar3[4] = 0x7c0378ce;
      puVar3[5] = uVar4;
      puVar3 = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel2DFromLevelRTCAV)(param_1,param_2,puVar3 + 6);
      *puVar3 = 0x39e00220;
      puVar3[1] = 0x7c2378ce;
      puVar3[2] = 0x39e00210;
      puVar3[3] = 0x7c0378ce;
      puVar3[4] = 0x1000028c;
      puVar3[5] = 0x1068004a;
      puVar3[6] = 0x1063386e;
      puVar3[7] = 0x104018ae;
      puVar3 = puVar3 + 8;
    }
    return puVar3;
  }
  param_1[10] = 0;
  puVar3 = (undefined4 *)((int (*)())_PPCTextureSamplerSampleTexel2DFromLevelRTCAV)();
  return puVar3;
}

/* _PPCTextureSamplerSampleTexel3DRTCAV @ 0x97be2948 (780 bytes) */
int _PPCTextureSamplerSampleTexel3DRTCAV(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  uint *param_3;
{
  uint *puVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  int *piVar5;
  uint *puVar6;
  
  piVar5 = *(int **)(param_2 * 4 + *param_1);
  if (*(ushort *)(*piVar5 + 0x16) - 0x2700 < 4) {
    param_1[10] = 1;
    if (param_1[9] != 0) {
      *param_3 = 0x39e00200;
      param_3[1] = 0x7c4379ce;
      param_3 = param_3 + 2;
    }
    uVar4 = param_2 * 4 & 0xfffcU | 0x82220000;
    *param_3 = uVar4;
    param_3[1] = 0x39e00120;
    param_3[2] = 0x7df178ce;
    param_3[3] = 0x39e00040;
    param_3[4] = 0x7c2c78ce;
    param_3[5] = 0x39ef00c0;
    param_3[6] = 0x7c4c78ce;
    iVar2 = _glpRTCAddAChunk(&_glpOpTexCalculateLambda3DAVRTC,param_3 + 7);
    puVar1 = param_3 + 7 + iVar2;
    *puVar1 = 0x39e00040;
    puVar1[1] = 0x7c9178ce;
    puVar1[2] = 0x1063200a;
    puVar6 = puVar1 + 3;
    if (param_1[9] != 0) {
      *puVar6 = 0x39e00200;
      puVar1[4] = 0x7c4378ce;
      puVar1[5] = 0x1063100a;
      puVar6 = puVar1 + 6;
    }
    *puVar6 = 0x39e00030;
    puVar6[1] = 0x7c3178ce;
    puVar6[2] = 0x39e00020;
    puVar6[3] = 0x7c5178ce;
    puVar6[4] = 0x1063144a;
    puVar6[5] = 0x10630c0a;
    puVar6[6] = 0x10601a8c;
    puVar6[7] = 0x10801b8a;
    puVar6[8] = 0x39e00200;
    puVar6[9] = 0x7c8379ce;
    puVar6[10] = 0x7f03782e;
    if (*(ushort *)(*piVar5 + 0x16) - 0x2700 < 2) {
      puVar3 = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel3DFromLevelRTCAV)(param_1,param_2,puVar6 + 0xb);
    }
    else {
      puVar6[0xb] = 0x10801aca;
      puVar6[0xc] = 0x1083204a;
      puVar6[0xd] = 0x39e00210;
      puVar6[0xe] = 0x7c8379ce;
      puVar6[0xf] = 0x39e00230;
      puVar6[0x10] = 0x7c0379ce;
      puVar3 = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel3DFromLevelRTCAV)(param_1,param_2,puVar6 + 0x11);
      *puVar3 = 0x39e00220;
      puVar3[1] = 0x7c4379ce;
      puVar3[2] = 0x3b180001;
      puVar3[3] = 0x39e00230;
      puVar3[4] = 0x7c0378ce;
      puVar3[5] = uVar4;
      puVar3 = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel3DFromLevelRTCAV)(param_1,param_2,puVar3 + 6);
      *puVar3 = 0x39e00220;
      puVar3[1] = 0x7c2378ce;
      puVar3[2] = 0x39e00210;
      puVar3[3] = 0x7c0378ce;
      puVar3[4] = 0x1000028c;
      puVar3[5] = 0x1068004a;
      puVar3[6] = 0x1063386e;
      puVar3[7] = 0x104018ae;
      puVar3 = puVar3 + 8;
    }
    return puVar3;
  }
  param_1[10] = 0;
  puVar3 = (undefined4 *)((int (*)())_PPCTextureSamplerSampleTexel3DFromLevelRTCAV)();
  return puVar3;
}

/* _PPCTextureSamplerSampleTexel1DFromLevelRTCAV @ 0x97be2c58 (960 bytes) */
int _PPCTextureSamplerSampleTexel1DFromLevelRTCAV(param_1, param_2, param_3)
  int *param_1;
  uint param_2;
  uint *param_3;
{
  bool bVar1;
  short sVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  uint *puVar9;
  undefined4 *puVar10;
  
  if (7 < param_2) {
    param_2 = 7;
  }
  piVar8 = *(int **)(param_2 * 4 + *param_1);
  if (piVar8 == (int *)0x0) {
    return param_3;
  }
  param_1[1] = (int)piVar8;
  iVar5 = *piVar8;
  iVar7 = 0x812d;
  sVar2 = *(short *)(iVar5 + 0x10);
  if ((sVar2 != -0x7ed3) &&
     (((sVar2 != 0x2900 || (*(short *)(iVar5 + 0x16) == 0x2600)) ||
      (iVar7 = 0x2900, *(short *)(iVar5 + 0x16) == 0x2700)))) {
    iVar7 = 0;
  }
  if (((param_1[5] == param_2) && (param_1[6] == 4)) && (param_1[7] == iVar7)) {
    iVar4 = param_1[10];
    if (iVar4 != 0) goto LAB_97be2d14;
  }
  else {
    iVar4 = param_1[10];
LAB_97be2d14:
    if (iVar4 == 0) {
      uVar6 = 0x3a310120;
      *param_3 = param_2 * 4 & 0xfffc | 0x82220000;
    }
    else {
      *param_3 = 0x1ef800d0;
      uVar6 = 0x7e31ba14;
      param_3 = param_3 + 1;
      *param_3 = 0x3a310120;
    }
    param_3[1] = uVar6;
    puVar9 = param_3 + 2;
    if (sVar2 == 0x2901) {
      *puVar9 = 0x39e00040;
      param_3[3] = 0x7e3178ce;
      puVar9 = param_3 + 4;
    }
    if (iVar7 == 0x812d) {
      *puVar9 = 0x82510070;
      puVar9[1] = 0x39e00050;
      puVar9[2] = 0x7df178ce;
      puVar9[3] = 0x39e00080;
      puVar9[4] = 0x7e1178ce;
      uVar6 = 0x823100a4;
    }
    else if (iVar7 == 0x2900) {
      *puVar9 = 0x82510070;
      puVar9[1] = 0x39e00050;
      puVar9[2] = 0x7df178ce;
      puVar9[3] = 0x39e00080;
      puVar9[4] = 0x7e1178ce;
      uVar6 = 0x823100a8;
    }
    else {
      *puVar9 = 0x82510020;
      puVar9[1] = 0x39e00000;
      puVar9[2] = 0x7df178ce;
      puVar9[3] = 0x39e00030;
      puVar9[4] = 0x7e1178ce;
      uVar6 = 0x823100a0;
    }
    puVar9[5] = uVar6;
    param_1[5] = param_2;
    param_3 = puVar9 + 6;
    param_1[6] = 4;
    param_1[7] = iVar7;
    iVar5 = *piVar8;
  }
  uVar3 = *(ushort *)(iVar5 + 0x16);
  if (uVar3 == 0x2700) {
LAB_97be2ebc:
    if (param_1[8] != 0) {
      iVar5 = _glpRTCAddAChunk(&_glpOpTexProjectCoordinatesAVRTC,param_3);
      param_3 = param_3 + iVar5;
    }
    iVar5 = _glpRTCAddAChunk(&_glpOpTexFloatToIntNormalisedAVRTC,param_3);
    iVar5 = ((int (*)())_PPCTextureSamplerWrapCoordinates1DRTCAV)(param_1,param_3 + iVar5);
    iVar7 = _glpRTCAddAChunk(&_glpOpTexSample1DAVRTC,iVar5);
    puVar10 = (undefined4 *)(iVar5 + iVar7 * 4);
    *puVar10 = 0x10431c84;
  }
  else {
    if (uVar3 < 0x2701) {
      if (uVar3 == 0x2600) goto LAB_97be2ebc;
      bVar1 = uVar3 == 0x2601;
LAB_97be2eb4:
      if (!bVar1) {
        return param_3;
      }
    }
    else {
      if (uVar3 == 0x2702) goto LAB_97be2ebc;
      if (0x2701 < uVar3) {
        bVar1 = uVar3 == 0x2703;
        goto LAB_97be2eb4;
      }
    }
    if (param_1[8] != 0) {
      iVar5 = _glpRTCAddAChunk(&_glpOpTexProjectCoordinatesAVRTC,param_3);
      param_3 = param_3 + iVar5;
    }
    iVar5 = _glpRTCAddAChunk(&_glpOpTexFloatToIntNormalisedWithLERPValuesAVRTC,param_3);
    param_3[iVar5] = 0x10c00484;
    iVar5 = ((int (*)())_PPCTextureSamplerWrapCoordinates1DRTCAV)(param_1,param_3 + iVar5 + 1);
    iVar7 = _glpRTCAddAChunk(&_glpOpTexSample1DAVRTC,iVar5);
    puVar10 = (undefined4 *)(iVar5 + iVar7 * 4);
    *puVar10 = 0x1020228c;
    puVar10[1] = 0x104138ee;
    puVar10[2] = 0x100a4b2c;
    puVar10[3] = 0x10060780;
    iVar5 = ((int (*)())_PPCTextureSamplerWrapCoordinates1DRTCAV)(param_1,puVar10 + 4);
    iVar7 = _glpRTCAddAChunk(&_glpOpTexSample1DAVRTC,iVar5);
    puVar10 = (undefined4 *)(iVar5 + iVar7 * 4);
    *puVar10 = 0x10202a8c;
    puVar10 = puVar10 + 1;
    *puVar10 = 0x104110ee;
  }
  return puVar10 + 1;
}

/* _PPCTextureSamplerSampleTexel2DFromLevelRTCAV @ 0x97be3018 (1172 bytes) */
int _PPCTextureSamplerSampleTexel2DFromLevelRTCAV(param_1, param_2, param_3)
  int *param_1;
  uint param_2;
  uint *param_3;
{
  bool bVar1;
  short sVar2;
  short sVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  uint *puVar10;
  undefined4 *puVar11;
  
  if (7 < param_2) {
    param_2 = 7;
  }
  piVar9 = *(int **)(param_2 * 4 + *param_1);
  if (piVar9 == (int *)0x0) {
    return param_3;
  }
  param_1[1] = (int)piVar9;
  iVar6 = *piVar9;
  sVar2 = *(short *)(iVar6 + 0x10);
  sVar3 = *(short *)(iVar6 + 0x12);
  if ((sVar2 == -0x7ed3) || (sVar3 == -0x7ed3)) {
    iVar8 = 0x812d;
  }
  else if ((((sVar2 != 0x2900) && (sVar3 != 0x2900)) || (*(short *)(iVar6 + 0x16) == 0x2600)) ||
          (iVar8 = 0x2900, *(short *)(iVar6 + 0x16) == 0x2700)) {
    iVar8 = 0;
  }
  if (((param_1[5] == param_2) && (param_1[6] == 3)) && (param_1[7] == iVar8)) {
    iVar5 = param_1[10];
    if (iVar5 != 0) goto LAB_97be30f0;
  }
  else {
    iVar5 = param_1[10];
LAB_97be30f0:
    if (iVar5 == 0) {
      uVar7 = 0x3a310120;
      *param_3 = param_2 * 4 & 0xfffc | 0x82220000;
    }
    else {
      *param_3 = 0x1ef800d0;
      uVar7 = 0x7e31ba14;
      param_3 = param_3 + 1;
      *param_3 = 0x3a310120;
    }
    param_3[1] = uVar7;
    puVar10 = param_3 + 2;
    if ((sVar2 == 0x2901) || (sVar3 == 0x2901)) {
      *puVar10 = 0x39e00040;
      param_3[3] = 0x7e3178ce;
      puVar10 = param_3 + 4;
    }
    if (iVar8 == 0x812d) {
      *puVar10 = 0x82510070;
      puVar10[1] = 0x39e00050;
      puVar10[2] = 0x7df178ce;
      puVar10[3] = 0x39e00080;
      puVar10[4] = 0x7e1178ce;
      uVar7 = 0x823100a4;
    }
    else if (iVar8 == 0x2900) {
      *puVar10 = 0x82510070;
      puVar10[1] = 0x39e00050;
      puVar10[2] = 0x7df178ce;
      puVar10[3] = 0x39e00080;
      puVar10[4] = 0x7e1178ce;
      uVar7 = 0x823100a8;
    }
    else {
      *puVar10 = 0x82510020;
      puVar10[1] = 0x39e00000;
      puVar10[2] = 0x7df178ce;
      puVar10[3] = 0x39e00030;
      puVar10[4] = 0x7e1178ce;
      uVar7 = 0x823100a0;
    }
    puVar10[5] = uVar7;
    param_1[5] = param_2;
    param_3 = puVar10 + 6;
    param_1[6] = 3;
    param_1[7] = iVar8;
    iVar6 = *piVar9;
  }
  uVar4 = *(ushort *)(iVar6 + 0x16);
  if (uVar4 == 0x2700) {
LAB_97be32a0:
    if (param_1[8] != 0) {
      iVar6 = _glpRTCAddAChunk(&_glpOpTexProjectCoordinatesAVRTC,param_3);
      param_3 = param_3 + iVar6;
    }
    iVar6 = _glpRTCAddAChunk(&_glpOpTexFloatToIntNormalisedAVRTC,param_3);
    iVar6 = ((int (*)())_PPCTextureSamplerWrapCoordinates2DRTCAV)(param_1,param_3 + iVar6);
    iVar8 = _glpRTCAddAChunk(&_glpOpTexSample2DAVRTC,iVar6);
    puVar11 = (undefined4 *)(iVar6 + iVar8 * 4);
    *puVar11 = 0x10431c84;
  }
  else {
    if (uVar4 < 0x2701) {
      if (uVar4 == 0x2600) goto LAB_97be32a0;
      bVar1 = uVar4 == 0x2601;
LAB_97be3298:
      if (!bVar1) {
        return param_3;
      }
    }
    else {
      if (uVar4 == 0x2702) goto LAB_97be32a0;
      if (0x2701 < uVar4) {
        bVar1 = uVar4 == 0x2703;
        goto LAB_97be3298;
      }
    }
    if (param_1[8] != 0) {
      iVar6 = _glpRTCAddAChunk(&_glpOpTexProjectCoordinatesAVRTC,param_3);
      param_3 = param_3 + iVar6;
    }
    iVar6 = _glpRTCAddAChunk(&_glpOpTexFloatToIntNormalisedWithLERPValuesAVRTC,param_3);
    param_3[iVar6] = 0x10c00484;
    iVar6 = ((int (*)())_PPCTextureSamplerWrapCoordinates2DRTCAV)(param_1,param_3 + iVar6 + 1);
    iVar8 = _glpRTCAddAChunk(&_glpOpTexSample2DAVRTC,iVar6);
    puVar11 = (undefined4 *)(iVar6 + iVar8 * 4);
    *puVar11 = 0x1024492c;
    puVar11[1] = 0x1021392e;
    puVar11[2] = 0x10200a8c;
    puVar11[3] = 0x104138ee;
    puVar11[4] = 0x100a4a2c;
    puVar11[5] = 0x10060780;
    iVar6 = ((int (*)())_PPCTextureSamplerWrapCoordinates2DRTCAV)(param_1,puVar11 + 6);
    iVar8 = _glpRTCAddAChunk(&_glpOpTexSample2DAVRTC,iVar6);
    puVar11 = (undefined4 *)(iVar6 + iVar8 * 4);
    *puVar11 = 0x1025492c;
    puVar11[1] = 0x1021392e;
    puVar11[2] = 0x10200a8c;
    puVar11[3] = 0x104110ee;
    puVar11[4] = 0x100a4b2c;
    puVar11[5] = 0x10060780;
    iVar6 = ((int (*)())_PPCTextureSamplerWrapCoordinates2DRTCAV)(param_1,puVar11 + 6);
    iVar8 = _glpRTCAddAChunk(&_glpOpTexSample2DAVRTC,iVar6);
    puVar11 = (undefined4 *)(iVar6 + iVar8 * 4);
    *puVar11 = 0x1024492c;
    puVar11[1] = 0x1021396e;
    puVar11[2] = 0x10200a8c;
    puVar11[3] = 0x104110ee;
    puVar11[4] = 0x1003528c;
    puVar11[5] = 0x10060780;
    iVar6 = ((int (*)())_PPCTextureSamplerWrapCoordinates2DRTCAV)(param_1,puVar11 + 6);
    iVar8 = _glpRTCAddAChunk(&_glpOpTexSample2DAVRTC,iVar6);
    puVar11 = (undefined4 *)(iVar6 + iVar8 * 4);
    *puVar11 = 0x1025492c;
    puVar11[1] = 0x1021396e;
    puVar11[2] = 0x10200a8c;
    puVar11 = puVar11 + 3;
    *puVar11 = 0x104110ee;
  }
  return puVar11 + 1;
}

/* _PPCTextureSamplerSampleTexel3DFromLevelRTCAV @ 0x97be34ac (1612 bytes) */
int _PPCTextureSamplerSampleTexel3DFromLevelRTCAV(param_1, param_2, param_3)
  int *param_1;
  uint param_2;
  uint *param_3;
{
  bool bVar1;
  short sVar2;
  short sVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  int iVar9;
  uint *puVar10;
  undefined4 *puVar11;
  
  if (7 < param_2) {
    param_2 = 7;
  }
  piVar8 = *(int **)(param_2 * 4 + *param_1);
  if (piVar8 == (int *)0x0) {
    return param_3;
  }
  param_1[1] = (int)piVar8;
  iVar6 = *piVar8;
  sVar2 = *(short *)(iVar6 + 0x10);
  sVar3 = *(short *)(iVar6 + 0x12);
  if (((sVar2 == -0x7ed3) || (sVar3 == -0x7ed3)) || (*(short *)(iVar6 + 0x14) == -0x7ed3)) {
    iVar9 = 0x812d;
  }
  else if ((((sVar2 != 0x2900) && (sVar3 != 0x2900)) && (*(short *)(iVar6 + 0x14) != 0x2900)) ||
          ((*(short *)(iVar6 + 0x16) == 0x2600 ||
           (iVar9 = 0x2900, *(short *)(iVar6 + 0x16) == 0x2700)))) {
    iVar9 = 0;
  }
  if (((param_1[5] == param_2) && (param_1[6] == 1)) && (param_1[7] == iVar9)) {
    iVar5 = param_1[10];
    if (iVar5 != 0) goto LAB_97be359c;
  }
  else {
    iVar5 = param_1[10];
LAB_97be359c:
    if (iVar5 == 0) {
      uVar7 = 0x3a310120;
      *param_3 = param_2 * 4 & 0xfffc | 0x82220000;
    }
    else {
      *param_3 = 0x1ef800d0;
      uVar7 = 0x7e31ba14;
      param_3 = param_3 + 1;
      *param_3 = 0x3a310120;
    }
    param_3[1] = uVar7;
    puVar10 = param_3 + 2;
    if ((sVar2 == 0x2901) || (sVar3 == 0x2901)) {
      *puVar10 = 0x39e00040;
      param_3[3] = 0x7e3178ce;
      puVar10 = param_3 + 4;
    }
    if (iVar9 == 0x812d) {
      *puVar10 = 0x82510070;
      puVar10[1] = 0x82710074;
      puVar10[2] = 0x39e00050;
      puVar10[3] = 0x7df178ce;
      puVar10[4] = 0x39e00080;
      puVar10[5] = 0x7e1178ce;
      uVar7 = 0x823100a4;
    }
    else if (iVar9 == 0x2900) {
      *puVar10 = 0x82510070;
      puVar10[1] = 0x82710074;
      puVar10[2] = 0x39e00050;
      puVar10[3] = 0x7df178ce;
      puVar10[4] = 0x39e00080;
      puVar10[5] = 0x7e1178ce;
      uVar7 = 0x823100a8;
    }
    else {
      *puVar10 = 0x82510020;
      puVar10[1] = 0x82710024;
      puVar10[2] = 0x39e00000;
      puVar10[3] = 0x7df178ce;
      puVar10[4] = 0x39e00030;
      puVar10[5] = 0x7e1178ce;
      uVar7 = 0x823100a0;
    }
    puVar10[6] = uVar7;
    param_1[5] = param_2;
    param_3 = puVar10 + 7;
    param_1[6] = 1;
    param_1[7] = iVar9;
    iVar6 = *piVar8;
  }
  uVar4 = *(ushort *)(iVar6 + 0x16);
  if (uVar4 == 0x2700) {
LAB_97be376c:
    if (param_1[8] != 0) {
      iVar6 = _glpRTCAddAChunk(&_glpOpTexProjectCoordinatesAVRTC,param_3);
      param_3 = param_3 + iVar6;
    }
    iVar6 = _glpRTCAddAChunk(&_glpOpTexFloatToIntNormalisedAVRTC,param_3);
    iVar6 = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(param_1,param_3 + iVar6);
    iVar9 = _glpRTCAddAChunk(&_glpOpTexSample3DAVRTC,iVar6);
    puVar11 = (undefined4 *)(iVar6 + iVar9 * 4);
    *puVar11 = 0x10431c84;
  }
  else {
    if (uVar4 < 0x2701) {
      if (uVar4 == 0x2600) goto LAB_97be376c;
      bVar1 = uVar4 == 0x2601;
LAB_97be3764:
      if (!bVar1) {
        return param_3;
      }
    }
    else {
      if (uVar4 == 0x2702) goto LAB_97be376c;
      if (0x2701 < uVar4) {
        bVar1 = uVar4 == 0x2703;
        goto LAB_97be3764;
      }
    }
    if (param_1[8] != 0) {
      iVar6 = _glpRTCAddAChunk(&_glpOpTexProjectCoordinatesAVRTC,param_3);
      param_3 = param_3 + iVar6;
    }
    iVar6 = _glpRTCAddAChunk(&_glpOpTexFloatToIntNormalisedWithLERPValuesAVRTC,param_3);
    param_3[iVar6] = 0x10c00484;
    iVar6 = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(param_1,param_3 + iVar6 + 1);
    iVar9 = _glpRTCAddAChunk(&_glpOpTexSample3DAVRTC,iVar6);
    puVar11 = (undefined4 *)(iVar6 + iVar9 * 4);
    *puVar11 = 0x1024492c;
    puVar11[1] = 0x1021392e;
    puVar11[2] = 0x10044a2c;
    puVar11[3] = 0x1021382e;
    puVar11[4] = 0x10200a8c;
    puVar11[5] = 0x104138ee;
    puVar11[6] = 0x100a4a2c;
    puVar11[7] = 0x10060780;
    iVar6 = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(param_1,puVar11 + 8);
    iVar9 = _glpRTCAddAChunk(&_glpOpTexSample3DAVRTC,iVar6);
    puVar11 = (undefined4 *)(iVar6 + iVar9 * 4);
    *puVar11 = 0x1025492c;
    puVar11[1] = 0x1021392e;
    puVar11[2] = 0x10044a2c;
    puVar11[3] = 0x1021382e;
    puVar11[4] = 0x10200a8c;
    puVar11[5] = 0x104110ee;
    puVar11[6] = 0x100a4b2c;
    puVar11[7] = 0x10060780;
    iVar6 = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(param_1,puVar11 + 8);
    iVar9 = _glpRTCAddAChunk(&_glpOpTexSample3DAVRTC,iVar6);
    puVar11 = (undefined4 *)(iVar6 + iVar9 * 4);
    *puVar11 = 0x1024492c;
    puVar11[1] = 0x1021396e;
    puVar11[2] = 0x10044a2c;
    puVar11[3] = 0x1021382e;
    puVar11[4] = 0x10200a8c;
    puVar11[5] = 0x104110ee;
    puVar11[6] = 0x1003528c;
    puVar11[7] = 0x10004a2c;
    puVar11[8] = 0x10060780;
    iVar6 = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(param_1,puVar11 + 9);
    iVar9 = _glpRTCAddAChunk(&_glpOpTexSample3DAVRTC,iVar6);
    puVar11 = (undefined4 *)(iVar6 + iVar9 * 4);
    *puVar11 = 0x1025492c;
    puVar11[1] = 0x1021396e;
    puVar11[2] = 0x10044a2c;
    puVar11[3] = 0x1021382e;
    puVar11[4] = 0x10200a8c;
    puVar11[5] = 0x104110ee;
    puVar11[6] = 0x100a492c;
    puVar11[7] = 0x10060780;
    iVar6 = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(param_1,puVar11 + 8);
    iVar9 = _glpRTCAddAChunk(&_glpOpTexSample3DAVRTC,iVar6);
    puVar11 = (undefined4 *)(iVar6 + iVar9 * 4);
    *puVar11 = 0x1024492c;
    puVar11[1] = 0x1021392e;
    puVar11[2] = 0x10054a2c;
    puVar11[3] = 0x1021382e;
    puVar11[4] = 0x10200a8c;
    puVar11[5] = 0x104110ee;
    puVar11[6] = 0x1003528c;
    puVar11[7] = 0x1009032c;
    puVar11[8] = 0x10060780;
    iVar6 = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(param_1,puVar11 + 9);
    iVar9 = _glpRTCAddAChunk(&_glpOpTexSample3DAVRTC,iVar6);
    puVar11 = (undefined4 *)(iVar6 + iVar9 * 4);
    *puVar11 = 0x1025492c;
    puVar11[1] = 0x1021392e;
    puVar11[2] = 0x10054a2c;
    puVar11[3] = 0x1021382e;
    puVar11[4] = 0x10200a8c;
    puVar11[5] = 0x104110ee;
    puVar11[6] = 0x1003528c;
    puVar11[7] = 0x1000492c;
    puVar11[8] = 0x1000022c;
    puVar11[9] = 0x10060780;
    iVar6 = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(param_1,puVar11 + 10);
    iVar9 = _glpRTCAddAChunk(&_glpOpTexSample3DAVRTC,iVar6);
    puVar11 = (undefined4 *)(iVar6 + iVar9 * 4);
    *puVar11 = 0x1024492c;
    puVar11[1] = 0x1021396e;
    puVar11[2] = 0x10054a2c;
    puVar11[3] = 0x1021382e;
    puVar11[4] = 0x10200a8c;
    puVar11[5] = 0x104110ee;
    puVar11[6] = 0x1003528c;
    puVar11[7] = 0x10060780;
    iVar6 = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(param_1,puVar11 + 8);
    iVar9 = _glpRTCAddAChunk(&_glpOpTexSample3DAVRTC,iVar6);
    puVar11 = (undefined4 *)(iVar6 + iVar9 * 4);
    *puVar11 = 0x1025492c;
    puVar11[1] = 0x1021396e;
    puVar11[2] = 0x10054a2c;
    puVar11[3] = 0x1021382e;
    puVar11[4] = 0x10200a8c;
    puVar11 = puVar11 + 5;
    *puVar11 = 0x104110ee;
  }
  return puVar11 + 1;
}

/* _PPCTextureSamplerSampleTexelRECTFromLevelRTCAV @ 0x97be3af8 (1084 bytes) */
int _PPCTextureSamplerSampleTexelRECTFromLevelRTCAV(param_1, param_2, param_3)
  int *param_1;
  uint param_2;
  uint *param_3;
{
  bool bVar1;
  short sVar2;
  short sVar3;
  ushort uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  uint *puVar9;
  
  if (7 < param_2) {
    param_2 = 7;
  }
  piVar8 = *(int **)(param_2 * 4 + *param_1);
  if (piVar8 == (int *)0x0) {
    return param_3;
  }
  param_1[1] = (int)piVar8;
  iVar6 = *piVar8;
  sVar2 = *(short *)(iVar6 + 0x10);
  sVar3 = *(short *)(iVar6 + 0x12);
  if ((sVar2 == -0x7ed3) || (sVar3 == -0x7ed3)) {
    iVar7 = 0x812d;
  }
  else if ((((sVar2 != 0x2900) && (sVar3 != 0x2900)) || (*(short *)(iVar6 + 0x16) == 0x2600)) ||
          (iVar7 = 0x2900, *(short *)(iVar6 + 0x16) == 0x2700)) {
    iVar7 = 0;
  }
  if (((param_1[5] != param_2) || (param_1[6] != 2)) || (param_1[7] != iVar7)) {
    *param_3 = param_2 * 4 & 0xfffc | 0x82220000;
    puVar9 = param_3 + 1;
    if ((sVar2 == 0x2901) || (sVar3 == 0x2901)) {
      *puVar9 = 0x39e00160;
      param_3[2] = 0x7e3178ce;
      puVar9 = param_3 + 3;
    }
    if (iVar7 == 0x812d) {
      *puVar9 = 0x82510190;
      puVar9[1] = 0x39e00170;
      puVar9[2] = 0x7df178ce;
      puVar9[3] = 0x39e001a0;
      puVar9[4] = 0x7e1178ce;
      uVar5 = 0x823101c4;
    }
    else if (iVar7 == 0x2900) {
      *puVar9 = 0x82510190;
      puVar9[1] = 0x39e00170;
      puVar9[2] = 0x7df178ce;
      puVar9[3] = 0x39e001a0;
      puVar9[4] = 0x7e1178ce;
      uVar5 = 0x823101c8;
    }
    else {
      *puVar9 = 0x82510140;
      puVar9[1] = 0x39e00120;
      puVar9[2] = 0x7df178ce;
      puVar9[3] = 0x39e00150;
      puVar9[4] = 0x7e1178ce;
      uVar5 = 0x823101c0;
    }
    puVar9[5] = uVar5;
    param_1[7] = iVar7;
    param_3 = puVar9 + 6;
    param_1[5] = param_2;
    param_1[6] = 2;
    iVar6 = *piVar8;
  }
  uVar4 = *(ushort *)(iVar6 + 0x16);
  if (uVar4 == 0x2700) {
LAB_97be3d34:
    iVar6 = _glpRTCAddAChunk(&_glpOpTexFloatToIntDenormalisedAVRTC,param_3);
    param_3 = param_3 + iVar6;
    iVar6 = _glpRTCAddAChunk(&_glpOpTexWrapCoordsCCCAVRTC,param_3);
    iVar7 = _glpRTCAddAChunk(&_glpOpTexSample2DAVRTC,param_3 + iVar6);
    puVar9 = param_3 + iVar6 + iVar7;
    *puVar9 = 0x10431c84;
  }
  else {
    if (uVar4 < 0x2701) {
      if (uVar4 == 0x2600) goto LAB_97be3d34;
      bVar1 = uVar4 == 0x2601;
LAB_97be3d2c:
      if (!bVar1) {
        return param_3;
      }
    }
    else {
      if (uVar4 == 0x2702) goto LAB_97be3d34;
      if (0x2701 < uVar4) {
        bVar1 = uVar4 == 0x2703;
        goto LAB_97be3d2c;
      }
    }
    iVar6 = _glpRTCAddAChunk(&_glpOpTexFloatToIntDenormalisedWithLERPValuesAVRTC,param_3);
    param_3 = param_3 + iVar6;
    *param_3 = 0x10c00484;
    param_3 = param_3 + 1;
    iVar6 = _glpRTCAddAChunk(&_glpOpTexWrapCoordsCCCAVRTC,param_3);
    iVar7 = _glpRTCAddAChunk(&_glpOpTexSample2DAVRTC,param_3 + iVar6);
    puVar9 = param_3 + iVar6 + iVar7;
    *puVar9 = 0x1024492c;
    puVar9[1] = 0x1021392e;
    puVar9[2] = 0x10200a8c;
    puVar9[3] = 0x104138ee;
    puVar9[4] = 0x100a4a2c;
    puVar9[5] = 0x10060780;
    puVar9 = puVar9 + 6;
    iVar6 = _glpRTCAddAChunk(&_glpOpTexWrapCoordsCCCAVRTC,puVar9);
    iVar7 = _glpRTCAddAChunk(&_glpOpTexSample2DAVRTC,puVar9 + iVar6);
    puVar9 = puVar9 + iVar6 + iVar7;
    *puVar9 = 0x1025492c;
    puVar9[1] = 0x1021392e;
    puVar9[2] = 0x10200a8c;
    puVar9[3] = 0x104110ee;
    puVar9[4] = 0x100a4b2c;
    puVar9[5] = 0x10060780;
    puVar9 = puVar9 + 6;
    iVar6 = _glpRTCAddAChunk(&_glpOpTexWrapCoordsCCCAVRTC,puVar9);
    iVar7 = _glpRTCAddAChunk(&_glpOpTexSample2DAVRTC,puVar9 + iVar6);
    puVar9 = puVar9 + iVar6 + iVar7;
    *puVar9 = 0x1024492c;
    puVar9[1] = 0x1021396e;
    puVar9[2] = 0x10200a8c;
    puVar9[3] = 0x104110ee;
    puVar9[4] = 0x1003528c;
    puVar9[5] = 0x10060780;
    puVar9 = puVar9 + 6;
    iVar6 = _glpRTCAddAChunk(&_glpOpTexWrapCoordsCCCAVRTC,puVar9);
    iVar7 = _glpRTCAddAChunk(&_glpOpTexSample2DAVRTC,puVar9 + iVar6);
    puVar9 = puVar9 + iVar6 + iVar7;
    *puVar9 = 0x1025492c;
    puVar9[1] = 0x1021396e;
    puVar9[2] = 0x10200a8c;
    puVar9 = puVar9 + 3;
    *puVar9 = 0x104110ee;
  }
  return puVar9 + 1;
}

/* _PPCNoiseGeneratorCreate @ 0x97be3f34 (56 bytes) */
int _PPCNoiseGeneratorCreate()
{
  void *pvVar1;
  
  pvVar1 = _malloc(0xa20);
  ((int (*)())_PPCNoiseGeneratorInitialise)();
  return pvVar1;
}

/* _PPCNoiseGeneratorInitialise @ 0x97be3f6c (280 bytes) */
int _PPCNoiseGeneratorInitialise(param_1)
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

/* _glpRTCAddAChunk_97be4088 @ 0x97be4088 (48 bytes) */
int _glpRTCAddAChunk_97be4088(param_1, param_2)
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

/* _PPCNoiseGeneratorCalculate1DAVRTC @ 0x97be40b8 (228 bytes) */
int _PPCNoiseGeneratorCalculate1DAVRTC(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  *param_2 = 0x11a8400a;
  param_2[1] = 0x102b5c84;
  param_2 = param_2 + 2;
  uVar4 = 0;
  do {
    uVar4 = uVar4 + 1;
    iVar2 = _glpRTCAddAChunk(&_glpOpFirstStageAVRTC,param_2);
    iVar3 = _glpRTCAddAChunk(&_glpOpSecondStage1DAVRTC,param_2 + iVar2);
    puVar1 = param_2 + iVar2 + iVar3;
    *puVar1 = 0x1122486e;
    puVar1[1] = 0x10003b6e;
    puVar1[2] = 0x10213aee;
    param_2 = puVar1 + 3;
  } while (uVar4 < 6);
  *param_2 = 0x10494c84;
  puVar1[4] = 0x1120038c;
  puVar1[5] = 0x39c00030;
  puVar1[6] = 0x7dae18ce;
  return puVar1 + 7;
}

/* _PPCNoiseGeneratorCalculate2DAVRTC @ 0x97be419c (228 bytes) */
int _PPCNoiseGeneratorCalculate2DAVRTC(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  *param_2 = 0x11a8400a;
  param_2[1] = 0x102b5c84;
  param_2 = param_2 + 2;
  uVar4 = 0;
  do {
    uVar4 = uVar4 + 1;
    iVar2 = _glpRTCAddAChunk(&_glpOpFirstStageAVRTC,param_2);
    iVar3 = _glpRTCAddAChunk(&_glpOpSecondStage2DAVRTC,param_2 + iVar2);
    puVar1 = param_2 + iVar2 + iVar3;
    *puVar1 = 0x1122486e;
    puVar1[1] = 0x10003b6e;
    puVar1[2] = 0x10213aee;
    param_2 = puVar1 + 3;
  } while (uVar4 < 6);
  *param_2 = 0x10494c84;
  puVar1[4] = 0x1120038c;
  puVar1[5] = 0x39c00030;
  puVar1[6] = 0x7dae18ce;
  return puVar1 + 7;
}

/* _PPCNoiseGeneratorCalculate3DAVRTC @ 0x97be4280 (228 bytes) */
int _PPCNoiseGeneratorCalculate3DAVRTC(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  *param_2 = 0x11a8400a;
  param_2[1] = 0x102b5c84;
  param_2 = param_2 + 2;
  uVar4 = 0;
  do {
    uVar4 = uVar4 + 1;
    iVar2 = _glpRTCAddAChunk(&_glpOpFirstStageAVRTC,param_2);
    iVar3 = _glpRTCAddAChunk(&_glpOpSecondStage3DAVRTC,param_2 + iVar2);
    puVar1 = param_2 + iVar2 + iVar3;
    *puVar1 = 0x1122486e;
    puVar1[1] = 0x10003b6e;
    puVar1[2] = 0x10213aee;
    param_2 = puVar1 + 3;
  } while (uVar4 < 6);
  *param_2 = 0x10494c84;
  puVar1[4] = 0x1120038c;
  puVar1[5] = 0x39c00030;
  puVar1[6] = 0x7dae18ce;
  return puVar1 + 7;
}

/* _PPCNoiseGeneratorCalculate4DAVRTC @ 0x97be4364 (8 bytes) */
int _PPCNoiseGeneratorCalculate4DAVRTC(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  return param_2;
}

/* _PPCRasterOpMachineCreate @ 0x97be436c (60 bytes) */
int _PPCRasterOpMachineCreate()
{
  void *pvVar1;
  
  pvVar1 = _calloc(8,1);
  ((int (*)())_PPCRasterOpMachineInitialise)();
  return pvVar1;
}

/* _PPCRasterOpMachineInitialise @ 0x97be43a8 (16 bytes) */
int _PPCRasterOpMachineInitialise(param_1)
  undefined4 *param_1;
{
  param_1[1] = 0;
  *param_1 = 0;
  return;
}

/* _PPCRasterOpMachineAttachEmulatorContext @ 0x97be43bc (8 bytes) */
int _PPCRasterOpMachineAttachEmulatorContext(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  *param_1 = param_2;
  return;
}

/* _PPCRasterOpMachineAttachRuntimeCompiler @ 0x97be43c4 (8 bytes) */
int _PPCRasterOpMachineAttachRuntimeCompiler(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(param_1 + 4) = param_2;
  return;
}

/* _PPCRasterOpMachine_DepthTestRTCAV @ 0x97be43cc (272 bytes) */
int _PPCRasterOpMachine_DepthTestRTCAV(param_1, param_2)
  int *param_1;
  uint *param_2;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = param_1[1];
  uVar2 = *(uint *)(*(int *)(*param_1 + 0xd80) + 0x50);
  uVar1 = uVar2 & 7;
  if ((uVar1 != 0) && (uVar1 != 7)) {
    *param_2 = 0x81e30da8;
    param_2[1] = 0xc10f0000;
    param_2[2] = 0xfc0d4000;
    param_2 = param_2 + 3;
  }
  uVar1 = (uint)(*(int *)(iVar3 + 0xe3c) - (int)param_2) >> 2;
  switch(uVar2 & 7) {
  case 0:
    *param_2 = (uVar1 & 0xffffff) << 2 | 0x48000000;
    goto LAB_97be44f0;
  case 1:
    uVar2 = 0x41800000;
    break;
  case 2:
    uVar2 = 0x41820000;
    break;
  case 3:
    uVar2 = 0x40810000;
    break;
  case 4:
    uVar2 = 0x41810000;
    break;
  case 5:
    uVar2 = 0x40820000;
    break;
  case 6:
    uVar2 = 0x40800000;
    break;
  default:
    goto switchD_97be4464_caseD_7;
  }
  *param_2 = uVar2 | 8;
  param_2 = param_2 + 1;
  *param_2 = (uVar1 - 1) * 4 & 0x3fffffc | 0x48000000;
LAB_97be44f0:
  param_2 = param_2 + 1;
switchD_97be4464_caseD_7:
  return param_2;
}

/* _PPCRasterOpMachine_DepthAndStencilTestRTCAV @ 0x97be44fc (1172 bytes) */
int _PPCRasterOpMachine_DepthAndStencilTestRTCAV(param_1, param_2)
  int *param_1;
  uint *param_2;
{
  bool bVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  uint *puVar14;
  undefined1 uStack_2e;
  
  iVar11 = *param_1;
  puVar14 = (uint *)0x0;
  iVar13 = param_1[1];
  iVar4 = *(int *)(iVar11 + 0xd80);
  uVar5 = *(uint *)(iVar4 + 0x48);
  uVar10 = *(uint *)(iVar4 + 0x3c);
  uVar2 = *(uint *)(iVar4 + 0x4c) >> 0x18;
  bVar1 = (uVar10 >> 6 & 1) == 0;
  uVar8 = *(uint *)(*(int *)(iVar11 + 0xd80) + 0x50);
  uVar9 = *(uint *)(*(int *)(iVar11 + 0xd80) + 0x70);
  if (bVar1) {
    uStack_2e = 0xff;
  }
  else {
    uStack_2e = (undefined1)(uVar9 >> 8);
  }
  bVar3 = (uVar10 & 2) != 0;
  uVar12 = *(uint *)(iVar4 + 0x4c) >> 8 & 0xff;
  if (!bVar3) goto LAB_97be4754;
  *param_2 = 0x83430dac;
  param_2[1] = 0x8b3a0000;
  puVar7 = param_2 + 2;
  puVar6 = puVar7;
  switch(uVar5 >> 0xc & 7) {
  case 0:
    uVar5 = uVar5 >> 0xf;
    param_2 = puVar7;
    goto LAB_97be47b8;
  case 1:
    *puVar7 = uVar2 & uVar12 | 0x3ba00000;
    param_2[3] = uVar12 | 0x733e0000;
    uVar12 = 0x41800000;
    break;
  case 2:
    *puVar7 = uVar2 & uVar12 | 0x3ba00000;
    param_2[3] = uVar12 | 0x733e0000;
    uVar12 = 0x41820000;
    break;
  case 3:
    *puVar7 = uVar2 & uVar12 | 0x3ba00000;
    param_2[3] = uVar12 | 0x733e0000;
    uVar12 = 0x40810000;
    break;
  case 4:
    *puVar7 = uVar2 & uVar12 | 0x3ba00000;
    param_2[3] = uVar12 | 0x733e0000;
    uVar12 = 0x41810000;
    break;
  case 5:
    *puVar7 = uVar2 & uVar12 | 0x3ba00000;
    param_2[3] = uVar12 | 0x733e0000;
    uVar12 = 0x40820000;
    break;
  case 6:
    *puVar7 = uVar2 & uVar12 | 0x3ba00000;
    param_2[3] = uVar12 | 0x733e0000;
    uVar12 = 0x40800000;
    break;
  case 7:
    *puVar7 = 0x48000000;
    puVar6 = param_2 + 3;
    puVar14 = puVar7;
  default:
    goto switchD_97be45d8_default;
  }
  param_2[4] = 0x7c1df000;
  puVar14 = param_2 + 5;
  *puVar14 = uVar12;
  puVar6 = param_2 + 6;
switchD_97be45d8_default:
  puVar6 = (uint *)((int (*)())_PPCRasterOpMachineUpdateStencilBufferRTCAV)(uVar5 >> 0xf & 7,0x1a,0x19,uVar2,uStack_2e,puVar6);
  param_2 = puVar6 + 1;
  *puVar6 = *(int *)(iVar13 + 0xe3c) - (int)puVar6 & 0x3fffffcU | 0x48000000;
  *puVar14 = *puVar14 | (int)param_2 - (int)puVar14 & 0xfffcU;
LAB_97be4754:
  if ((uVar10 & 4) == 0) {
    if (!bVar3) {
      return param_2;
    }
    puVar14 = (uint *)((int (*)())_PPCRasterOpMachineUpdateStencilBufferRTCAV)(uVar5 >> 0x15 & 7,0x1a,0x19,uVar2,uStack_2e,param_2);
    return puVar14;
  }
  switch(uVar8 & 7) {
  case 0:
    if (bVar3) {
      uVar5 = uVar5 >> 0x12;
LAB_97be47b8:
      param_2 = (uint *)((int (*)())_PPCRasterOpMachineUpdateStencilBufferRTCAV)(uVar5 & 7,0x1a,0x19,uVar2,uStack_2e,param_2);
    }
    *param_2 = *(int *)(iVar13 + 0xe3c) - (int)param_2 & 0x3fffffcU | 0x48000000;
    return param_2 + 1;
  case 1:
    *param_2 = 0x81e30da8;
    param_2[1] = 0xc10f0000;
    uVar8 = 0x41800000;
    break;
  case 2:
    *param_2 = 0x81e30da8;
    param_2[1] = 0xc10f0000;
    uVar8 = 0x41820000;
    break;
  case 3:
    *param_2 = 0x81e30da8;
    param_2[1] = 0xc10f0000;
    uVar8 = 0x40810000;
    break;
  case 4:
    *param_2 = 0x81e30da8;
    param_2[1] = 0xc10f0000;
    uVar8 = 0x41810000;
    break;
  case 5:
    *param_2 = 0x81e30da8;
    param_2[1] = 0xc10f0000;
    uVar8 = 0x40820000;
    break;
  case 6:
    *param_2 = 0x81e30da8;
    param_2[1] = 0xc10f0000;
    uVar8 = 0x40800000;
    break;
  case 7:
    *param_2 = 0x81e30da8;
    uVar8 = 0x48000000;
    goto LAB_97be48e0;
  default:
    goto switchD_97be4784_default;
  }
  param_2 = param_2 + 2;
  *param_2 = 0xfc0d4000;
LAB_97be48e0:
  puVar14 = param_2 + 1;
  *puVar14 = uVar8;
  param_2 = param_2 + 2;
switchD_97be4784_default:
  if (bVar3) {
    param_2 = (uint *)((int (*)())_PPCRasterOpMachineUpdateStencilBufferRTCAV)(uVar5 >> 0x12 & 7,0x1a,0x19,uVar2,uStack_2e,param_2);
  }
  *param_2 = *(int *)(iVar13 + 0xe3c) - (int)param_2 & 0x3fffffcU | 0x48000000;
  param_2 = param_2 + 1;
  *puVar14 = *puVar14 | (int)param_2 - (int)puVar14 & 0xfffcU;
  if (bVar3) {
    param_2 = (uint *)((int (*)())_PPCRasterOpMachineUpdateStencilBufferRTCAV)(uVar5 >> 0x15 & 7,0x1a,0x19,uVar2,uStack_2e,param_2);
  }
  if ((bVar1) || ((uVar9 & 0x10000) != 0)) {
    *param_2 = 0xd1af0000;
    param_2 = param_2 + 1;
  }
  return param_2;
}

/* _PPCRasterOpMachine_AlphaTestRTCAV @ 0x97be49d0 (616 bytes) */
int _PPCRasterOpMachine_AlphaTestRTCAV(param_1, param_2)
  int *param_1;
  uint *param_2;
{
  float fVar1;
  uint uVar2;
  float fVar3;
  uint uVar4;
  uint uVar5;
  double dVar6;
  
  uVar5 = 0;
  uVar4 = *(uint *)(*(int *)(*param_1 + 0xd80) + 0x40);
  fVar3 = *(float *)(*(int *)(*param_1 + 0xd80) + 0x44);
  uVar2 = uVar4 & 7;
  if ((uVar2 != 7) && (uVar2 != 0)) {
    uVar5 = ((int (*)())_PPEmulatorFramebufferFormat)();
    if ((uVar5 & 0x1c000) == 0) {
      *param_2 = 0x3b000210;
      param_2[1] = 0x7e63c1ce;
      param_2[2] = 0xc123021c;
      param_2[3] = (uint)fVar3 >> 0x10 | 0x3de00000;
      param_2[4] = (uint)fVar3 & 0xffff | 0x61ef0000;
      param_2[5] = 0x91e30210;
      param_2[6] = 0xc1030210;
      uVar5 = 0xfc094000;
    }
    else {
      fVar1 = TAllocation__guardBlockSize;
      if ((fVar3 < TAllocation__guardBlockSize) || (fVar1 = FLOAT_97c3acd8, FLOAT_97c3acd8 < fVar3))
      {
        fVar3 = fVar1;
      }
      fVar3 = fVar3 * FLOAT_97c3acbc + FLOAT_97c3acc0;
      dVar6 = (double)fVar3;
      if (DOUBLE_97c30a78 <= dVar6) {
        uVar5 = (uint)(dVar6 - DOUBLE_97c30a78);
      }
      else {
        uVar5 = (uint)fVar3;
      }
      *param_2 = 0x10734c0a;
      param_2[1] = 0x1063444a;
      param_2[2] = 0x10635b2e;
      param_2[3] = 0x10601b8a;
      param_2[4] = 0x3b000210;
      param_2[5] = 0x7c63c1ce;
      uVar5 = uVar5 & 0xffff | 0x2c170000;
      param_2[6] = 0x82e3021c;
    }
    param_2[7] = uVar5;
    param_2 = param_2 + 8;
    uVar5 = (uint)(*(int *)(param_1[1] + 0xe3c) - (int)param_2) >> 2;
  }
  switch(uVar4 & 7) {
  case 0:
    uVar5 = *(int *)(param_1[1] + 0xe3c) - (int)param_2 & 0x3fffffcU | 0x48000000;
    break;
  case 1:
    uVar5 = (uVar5 & 0x3fff) << 2 | 0x40800000;
    break;
  case 2:
    uVar5 = (uVar5 & 0x3fff) << 2 | 0x40820000;
    break;
  case 3:
    uVar5 = (uVar5 & 0x3fff) << 2 | 0x41810000;
    break;
  case 4:
    uVar5 = (uVar5 & 0x3fff) << 2 | 0x40810000;
    break;
  case 5:
    uVar5 = (uVar5 & 0x3fff) << 2 | 0x41820000;
    break;
  case 6:
    uVar5 = (uVar5 & 0x3fff) << 2 | 0x41800000;
    break;
  default:
    goto switchD_97be4bb8_caseD_7;
  }
  *param_2 = uVar5;
  param_2 = param_2 + 1;
switchD_97be4bb8_caseD_7:
  return param_2;
}

/* _PPCRasterOpMachine_BlendingRTCAV @ 0x97be4c58 (888 bytes) */
int _PPCRasterOpMachine_BlendingRTCAV(param_1, param_2)
  int *param_1;
  uint *param_2;
{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  
  iVar6 = 0x13;
  uVar5 = *(uint *)(*(int *)(*param_1 + 0xd80) + 0x58);
  uVar2 = ((int (*)())_PPEmulatorFramebufferFormat)();
  if ((uVar2 & 0x8000000) == 0) {
    *param_2 = 0x1273444a;
    param_2[1] = 0x12734c0a;
    param_2 = param_2 + 2;
  }
  if ((1 < (uVar5 >> 0x10 & 7) - 3) || (1 < (uVar5 >> 0x13 & 7) - 3)) {
    if (((((uVar5 & 0xf) - 8 < 4) ||
         (((uVar2 = uVar5 >> 4 & 0xf, uVar2 == 8 || (uVar2 == 9)) || (uVar2 == 10)))) ||
        ((((uVar2 == 0xb || (uVar2 = uVar5 >> 8 & 0xf, uVar2 == 8)) || (uVar2 == 9)) ||
         ((uVar2 == 10 || (uVar2 == 0xb)))))) ||
       ((uVar2 = uVar5 >> 0xc & 0xf, uVar2 == 8 ||
        (((uVar2 == 9 || (uVar2 == 10)) || (uVar2 == 0xb)))))) {
      *param_2 = 0x81e30d9c;
      param_2[1] = 0x81ef00d8;
      param_2[2] = 0x39c02d70;
      param_2[3] = 0x7ccf70ce;
      param_2 = param_2 + 4;
    }
    puVar3 = (undefined4 *)((int (*)())_PPCRasterOpMachineCalculateBlendingFactorsRTCAV)(param_2,0,uVar5 & 0xf);
    uVar2 = uVar5 >> 4 & 0xf;
    if ((uVar5 & 0xf) != uVar2) {
      puVar4 = (undefined4 *)((int (*)())_PPCRasterOpMachineCalculateBlendingFactorsRTCAV)(puVar3,3,uVar2);
      puVar3 = puVar4 + 1;
      *puVar4 = 0x10001b6a;
    }
    param_2 = (uint *)((int (*)())_PPCRasterOpMachineCalculateBlendingFactorsRTCAV)(puVar3,1,uVar5 >> 8 & 0xf);
    uVar2 = uVar5 >> 0xc & 0xf;
    if ((uVar5 >> 8 & 0xf) != uVar2) {
      puVar3 = (undefined4 *)((int (*)())_PPCRasterOpMachineCalculateBlendingFactorsRTCAV)(param_2,3,uVar2);
      param_2 = puVar3 + 1;
      *puVar3 = 0x10211b6a;
    }
  }
  uVar2 = uVar5 >> 0x10 & 7;
  bVar1 = uVar2 == (uVar5 >> 0x13 & 7);
  if (!bVar1) {
    iVar6 = 3;
  }
  switch(uVar2) {
  case 0:
    *param_2 = 0x1093482e;
    param_2 = param_2 + 1;
    *param_2 = iVar6 << 0x15 | 0x1002206e;
    goto LAB_97be4f04;
  case 1:
    *param_2 = 0x1093482e;
    uVar2 = iVar6 << 0x15 | 0x1004284a;
    break;
  case 2:
    *param_2 = 0x1093482e;
    uVar2 = iVar6 << 0x15 | 0x1005204a;
    break;
  case 3:
    uVar2 = iVar6 << 0x15 | 0x1013144a;
    goto LAB_97be4f00;
  case 4:
    uVar2 = iVar6 << 0x15 | 0x1013140a;
LAB_97be4f00:
    *param_2 = uVar2;
    goto LAB_97be4f04;
  default:
    goto switchD_97be4e5c_default;
  }
  param_2[1] = 0x10a2486e;
  param_2 = param_2 + 2;
  *param_2 = uVar2;
LAB_97be4f04:
  param_2 = param_2 + 1;
switchD_97be4e5c_default:
  if (bVar1) {
    return param_2;
  }
  switch(uVar5 >> 0x13 & 7) {
  case 0:
    uVar2 = 0x1262206e;
    *param_2 = 0x1093482e;
    goto LAB_97be4f88;
  case 1:
    *param_2 = 0x1093482e;
    uVar2 = 0x1264284a;
    break;
  case 2:
    *param_2 = 0x1093482e;
    uVar2 = 0x1265204a;
    break;
  case 3:
    uVar2 = 0x1273144a;
    goto LAB_97be4fc4;
  case 4:
    uVar2 = 0x1273140a;
LAB_97be4fc4:
    *param_2 = uVar2;
    goto LAB_97be4fc8;
  default:
    goto switchD_97be4f38_default;
  }
  param_2 = param_2 + 1;
  *param_2 = 0x10a2486e;
LAB_97be4f88:
  param_2 = param_2 + 1;
  *param_2 = uVar2;
LAB_97be4fc8:
  param_2 = param_2 + 1;
switchD_97be4f38_default:
  *param_2 = iVar6 << 0x10 | 0x12609b6a;
  return param_2 + 1;
}

/* _PPCRasterOpMachine_LogicOpRTCAV @ 0x97be4ff8 (520 bytes) */
int _PPCRasterOpMachine_LogicOpRTCAV(param_1, param_2)
  int *param_1;
  uint *param_2;
{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(*(int *)(*param_1 + 0xd80) + 0x68);
  uVar1 = uVar2 & 0xf;
  if ((uVar1 < 3) || (uVar1 == 4)) {
    if (uVar1 == 1) {
      uVar1 = 0x12684484;
    }
    else if (uVar1 < 2) {
      if (uVar1 != 0) {
        return param_2;
      }
      uVar1 = 0x12694c84;
    }
    else {
      if (uVar1 == 2) {
        return param_2;
      }
      if (uVar1 != 4) {
        return param_2;
      }
      uVar1 = 0x12621484;
    }
    *param_2 = uVar1;
    goto LAB_97be507c;
  }
  if (uVar1 != 5) {
    *param_2 = 0x10734b2e;
    param_2[1] = 0x10601b8a;
    param_2 = param_2 + 2;
  }
  uVar2 = uVar2 & 0xf;
  if (uVar2 != 3) {
    *param_2 = 0x10824b2e;
    param_2[1] = 0x1080238a;
    param_2 = param_2 + 2;
  }
  switch(uVar2) {
  case 3:
    uVar1 = 0x10c30000;
    goto LAB_97be5148;
  default:
    goto switchD_97be5104_caseD_4;
  case 5:
    uVar1 = 0x10c40000;
LAB_97be5148:
    uVar1 = uVar1 | 0x4d04;
    break;
  case 6:
    uVar1 = 0x10c32404;
    break;
  case 7:
    uVar1 = 0x10c32404;
    goto LAB_97be51a0;
  case 8:
    uVar1 = 0x10c32484;
    break;
  case 9:
    uVar1 = 0x10c32504;
    break;
  case 10:
    uVar1 = 0x10c324c4;
    break;
  case 0xb:
    uVar1 = 0x10c324c4;
LAB_97be51a0:
    uVar2 = 0x10c64d04;
LAB_97be51d8:
    *param_2 = uVar1;
    param_2 = param_2 + 1;
    *param_2 = uVar2;
    goto LAB_97be51e0;
  case 0xc:
    uVar1 = 0x10c32444;
    break;
  case 0xd:
    uVar1 = 0x10c41c44;
    break;
  case 0xe:
    uVar1 = 0x10840000;
    goto LAB_97be51cc;
  case 0xf:
    uVar1 = 0x10630000;
LAB_97be51cc:
    uVar1 = uVar1 | 0x4d04;
    uVar2 = 0x10c32484;
    goto LAB_97be51d8;
  }
  *param_2 = uVar1;
LAB_97be51e0:
  param_2 = param_2 + 1;
switchD_97be5104_caseD_4:
  *param_2 = 0x39e00020;
  param_2[1] = 0x7c6378ce;
  param_2[2] = 0x10c61c04;
  param_2[3] = 0x10c0330a;
  param_2[4] = 0x39e00070;
  param_2[5] = 0x7c6378ce;
  param_2 = param_2 + 6;
  *param_2 = 0x126648ee;
LAB_97be507c:
  return param_2 + 1;
}

/* _PPCRasterOpMachine_BufferMaskRTCAV @ 0x97be5234 (208 bytes) */
int _PPCRasterOpMachine_BufferMaskRTCAV(param_1, param_2)
  int *param_1;
  undefined4 *param_2;
{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 0x1063492c;
  uVar1 = *(uint *)(*(int *)(*param_1 + 0xd80) + 0x70);
  *param_2 = 0x10836a8c;
  if ((uVar1 & 0x20000) == 0) {
    uVar2 = 0x1063212c;
  }
  param_2[1] = uVar2;
  uVar2 = 0x1063492c;
  if ((uVar1 & 0x40000) == 0) {
    uVar2 = 0x1063212c;
  }
  param_2[2] = uVar2;
  uVar2 = 0x1063492c;
  if ((uVar1 & 0x80000) == 0) {
    uVar2 = 0x1063212c;
  }
  param_2[3] = uVar2;
  uVar2 = 0x1063492c;
  if ((uVar1 & 0x100000) == 0) {
    uVar2 = 0x1063212c;
  }
  param_2[4] = uVar2;
  param_2[5] = 0x127310ea;
  return param_2 + 6;
}

/* _PPCRasterOpMachineCalculateBlendingFactorsRTCAV @ 0x97be5304 (400 bytes) */
int _PPCRasterOpMachineCalculateBlendingFactorsRTCAV(param_1, param_2, param_3)
  uint *param_1;
  int param_2;
  undefined4 param_3;
{
  uint uVar1;
  uint uVar2;
  
  switch(param_3) {
  case 0:
    uVar1 = param_2 << 0x15 | 0x10094c84;
    break;
  case 1:
    uVar1 = param_2 << 0x15 | 0x10084484;
    break;
  case 2:
    uVar1 = param_2 << 0x15 | 0x10139c84;
    break;
  case 3:
    uVar1 = param_2 << 0x15 | 0x1008984a;
    break;
  case 4:
    uVar1 = param_2 << 0x15 | 0x10039a8c;
    break;
  case 5:
    uVar1 = param_2 << 0x15 | param_2 << 0xb | 0x10080000;
    uVar2 = param_2 << 0x15 | 0x10039a8c;
    goto LAB_97be545c;
  case 6:
    uVar1 = param_2 << 0x15 | 0x1003128c;
    break;
  case 7:
    uVar1 = param_2 << 0x15 | param_2 << 0xb | 0x10080000;
    uVar2 = param_2 << 0x15 | 0x1003128c;
    goto LAB_97be545c;
  case 8:
    uVar1 = param_2 << 0x15 | 0x10063484;
    break;
  case 9:
    uVar1 = param_2 << 0x15 | 0x1008304a;
    break;
  case 10:
    uVar1 = param_2 << 0x15 | 0x1003328c;
    break;
  case 0xb:
    uVar1 = param_2 << 0x15 | param_2 << 0xb | 0x10080000;
    uVar2 = param_2 << 0x15 | 0x1003328c;
LAB_97be545c:
    *param_1 = uVar2;
    param_1 = param_1 + 1;
    *param_1 = uVar1 | 0x4a;
    goto LAB_97be5394;
  case 0xc:
    uVar1 = param_2 << 0x15 | 0x10021484;
    break;
  case 0xd:
    uVar1 = param_2 << 0x15 | 0x1008104a;
    break;
  case 0xe:
    uVar1 = param_2 << 0x15;
    uVar2 = uVar1 | param_2 << 0x10;
    *param_1 = uVar1 | 0x1008104a;
    param_1[1] = uVar2 | 0x10009c4a;
    param_1[2] = uVar1 | param_2 << 0xb | 0x1003028c;
    param_1 = param_1 + 3;
    *param_1 = uVar2 | 0x1000436a;
    goto LAB_97be5394;
  default:
    return param_1;
  }
  *param_1 = uVar1;
LAB_97be5394:
  return param_1 + 1;
}

/* _PPCRasterOpMachineUpdateStencilBufferRTCAV @ 0x97be54d0 (468 bytes) */
int _PPCRasterOpMachineUpdateStencilBufferRTCAV(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int param_2;
  uint param_3;
  uint param_4;
  uint param_5;
  uint *param_6;
{
  uint uVar1;
  uint uVar2;
  
  switch(param_1) {
  case 0:
    *param_6 = param_5 ^ 0xffff | param_3 << 0x15 | 0x701e0000;
    param_6 = param_6 + 1;
    *param_6 = param_2 << 0x10 | 0x9bc00000;
    goto LAB_97be5588;
  case 1:
    return param_6;
  case 2:
    *param_6 = param_5 ^ 0xffff | param_3 << 0x15 | 0x701e0000;
    param_6[1] = param_4 & param_5 | 0x3be00000;
    param_6 = param_6 + 2;
    *param_6 = 0x7fdefb78;
    goto LAB_97be5580;
  case 3:
    *param_6 = (param_3 & 0x1f) << 0x10 | 0x2c0000ff;
    param_6[1] = param_3 << 0x10 | 0x3be00000;
    param_6[2] = 0x40800008;
    uVar1 = param_5 ^ 0xffff | param_3 << 0x15;
    uVar2 = param_3 << 0x10 | 0x3be00001;
    break;
  case 4:
    *param_6 = (param_3 & 0x1f) << 0x10 | 0x2c000000;
    param_6[1] = param_3 << 0x10 | 0x3be00000;
    param_6[2] = 0x40810008;
    uVar1 = param_5 ^ 0xffff | param_3 << 0x15;
    uVar2 = param_3 << 0x10 | 0x3be0ffff;
    break;
  case 5:
    *param_6 = param_5 ^ 0xffff | param_3 << 0x15 | 0x701e0000;
    param_6[1] = param_3 << 0x15 | param_3 << 0xb | 0x7c1f00f8;
    param_6[2] = param_5 | 0x73ff0000;
    param_6[3] = 0x7fdefb78;
    param_6[4] = param_2 << 0x10 | 0x9bc00000;
    return param_6 + 5;
  case 6:
    uVar1 = param_5 ^ 0xffff | param_3 << 0x15;
    uVar2 = param_3 << 0x10 | 0x3be00001;
    goto LAB_97be55e8;
  case 7:
    uVar1 = param_5 ^ 0xffff | param_3 << 0x15;
    uVar2 = param_3 << 0x10 | 0x3be0ffff;
LAB_97be55e8:
    *param_6 = uVar2;
    param_6 = param_6 + 1;
    *param_6 = 0x73ff00ff;
    goto LAB_97be55f4;
  default:
    return param_6;
  }
  param_6 = param_6 + 3;
  *param_6 = uVar2;
LAB_97be55f4:
  param_6[1] = uVar1 | 0x701e0000;
  param_6[2] = param_5 | 0x73ff0000;
  param_6 = param_6 + 3;
  *param_6 = 0x7fdefb78;
LAB_97be5580:
  param_6 = param_6 + 1;
  *param_6 = param_2 << 0x10 | 0x9bc00000;
LAB_97be5588:
  return param_6 + 1;
}

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
  ((int (*)())_PPCNoiseGeneratorInitialise)(param_1 + 0xd8);
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
    _handleDigit(local_20,iVar1);
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

