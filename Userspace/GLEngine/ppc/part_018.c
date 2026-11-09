#include "decls.h"

/* _glLightModelfv_Comp @ 0x6cee0 (188 bytes) */
int _glLightModelfv_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  uint *param_3;
{
  uint *puVar1;
  
  puVar1 = (uint *)_gleAddListItem(param_1,PTR__glLightModelfv_ListExec_00110150,0x14);
  if (puVar1 != (uint *)0x0) {
    *puVar1 = param_2;
    if (param_2 == 0xb53) {
      puVar1[1] = *param_3;
      puVar1[2] = param_3[1];
      puVar1[3] = param_3[2];
      puVar1[4] = param_3[3];
    }
    else {
      if (param_2 < 0xb54) {
        if (param_2 < 0xb51) {
          return puVar1;
        }
      }
      else if ((param_2 != 0x81f8) && (param_2 != 0x85b0)) {
        return puVar1;
      }
      puVar1[1] = *param_3;
    }
  }
  return puVar1;
}

/* _glLightModelfv_Exec @ 0x6cf9c (696 bytes) */
int _glLightModelfv_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  float *param_3;
{
  byte bVar1;
  float fVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined2 uVar5;
  int iVar6;
  int iVar7;
  double dVar8;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 == 0xb53) {
      *(float *)(param_1 + 0x2810) = *param_3;
      *(float *)(param_1 + 0x2814) = param_3[1];
      *(float *)(param_1 + 0x2818) = param_3[2];
      *(float *)(param_1 + 0x281c) = param_3[3];
      *(byte *)(*(int *)(param_1 + 0x4dd0) + 0x234) =
           *(byte *)(*(int *)(param_1 + 0x4dd0) + 0x234) | 0x1e;
      *(byte *)(*(int *)(param_1 + 0x4dd4) + 0x234) =
           *(byte *)(*(int *)(param_1 + 0x4dd4) + 0x234) | 0x1e;
      if (*(int *)(param_1 + 0x5434) == 0) {
        bVar1 = *(byte *)(*(int *)(param_1 + 0x5420) + 0x324);
      }
      else {
        bVar1 = *(byte *)(*(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x358);
      }
      iVar7 = (bVar1 >> 3 & 0x1c) + param_1;
      iVar6 = *(int *)(param_1 + 0x5424);
      *(uint *)(iVar7 + 0x324) = *(uint *)(iVar7 + 0x324) | 1 << (bVar1 & 0x1f);
      bVar1 = *(byte *)(iVar6 + 0x324);
      iVar6 = (bVar1 >> 3 & 0x1c) + param_1;
      *(uint *)(iVar6 + 0x348) = *(uint *)(iVar6 + 0x348) | 1 << (bVar1 & 0x1f);
    }
    else if (param_2 < 0xb54) {
      if (param_2 == 0xb51) {
        *(bool *)(param_1 + 0x30ad) = *param_3 != FLOAT_00108e50;
      }
      else {
        if (param_2 != 0xb52) goto LAB_0006d214;
        *(bool *)(param_1 + 0x30ac) = *param_3 != FLOAT_00108e50;
        _gleUpdatePolyMode(param_1);
        _gleSelectVertexSubmitFunc(param_1);
        _gleSelectVertexAddMaterialFunc(param_1);
      }
    }
    else if (param_2 == 0x81f8) {
      fVar2 = *param_3;
      dVar8 = (double)fVar2;
      if (DOUBLE_00108d80 <= dVar8) {
        uVar4 = (int)(dVar8 - DOUBLE_00108d80) ^ 0x80000000;
      }
      else {
        uVar4 = (uint)(int)fVar2;
      }
      if (1 < uVar4 - 0x81f9) goto LAB_0006d214;
      if (DOUBLE_00108d80 <= dVar8) {
        uVar5 = (undefined2)(int)(dVar8 - DOUBLE_00108d80);
      }
      else {
        uVar5 = (undefined2)(int)fVar2;
      }
      *(undefined2 *)(param_1 + 0x30a8) = uVar5;
      if ((*(char *)(param_1 + 0x30aa) != '\0') && (*(char *)(param_1 + 0x4664) == '\0')) {
        *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x800;
        *(bool *)(param_1 + 0x316b) = *(short *)(param_1 + 0x30a8) == -0x7e06;
      }
    }
    else {
      if (param_2 != 0x85b0) {
LAB_0006d214:
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        uVar3 = 0x500;
        goto LAB_0006d224;
      }
      *(bool *)(param_1 + 0x30ae) = *param_3 != FLOAT_00108e50;
    }
    _gleUpdateLightModel(param_1);
    *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 1;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
LAB_0006d224:
    *(undefined4 *)(param_1 + 0x7574) = uVar3;
  }
  return;
}

/* _glLightModelfv_CompExec @ 0x6d254 (64 bytes) */
int _glLightModelfv_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glLightModelfv_Comp)(param_1,param_2,param_3);
  ((int (*)())_glLightModelfv_Exec)(param_1,param_2,param_3);
  return;
}

/* _glLightModeli_ListExec @ 0x6d294 (44 bytes) */
int _glLightModeli_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glLightModeli_Exec(param_1,*param_2,param_2[1]);
  return 8;
}

/* _glLightModeli_Comp @ 0x6d2c0 (84 bytes) */
int _glLightModeli_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glLightModeli_ListExec_0011014c,8);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = param_3;
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glLightModeli_CompExec @ 0x6d314 (64 bytes) */
int _glLightModeli_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glLightModeli_Comp)(param_1,param_2,param_3);
  _glLightModeli_Exec(param_1,param_2,param_3);
  return;
}

/* _glLightModeliv_ListExec @ 0x6d354 (48 bytes) */
int _glLightModeliv_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((int (*)())_glLightModeliv_Exec)(param_1,*param_2,param_2 + 1);
  return 0x14;
}

/* _glLightModeliv_Comp @ 0x6d384 (188 bytes) */
int _glLightModeliv_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  uint *param_3;
{
  uint *puVar1;
  
  puVar1 = (uint *)_gleAddListItem(param_1,PTR__glLightModeliv_ListExec_00110148,0x14);
  if (puVar1 != (uint *)0x0) {
    *puVar1 = param_2;
    if (param_2 == 0xb53) {
      puVar1[1] = *param_3;
      puVar1[2] = param_3[1];
      puVar1[3] = param_3[2];
      puVar1[4] = param_3[3];
    }
    else {
      if (param_2 < 0xb54) {
        if (param_2 < 0xb51) {
          return puVar1;
        }
      }
      else if ((param_2 != 0x81f8) && (param_2 != 0x85b0)) {
        return puVar1;
      }
      puVar1[1] = *param_3;
    }
  }
  return puVar1;
}

/* _glLightModeliv_Exec @ 0x6d440 (656 bytes) */
int _glLightModeliv_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint *param_3;
{
  byte bVar1;
  double dVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  dVar2 = DOUBLE_00108d58;
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 == 0xb53) {
      *(float *)(param_1 + 0x2810) =
           (float)((double)CONCAT44(0x43300000,*param_3 ^ 0x80000000) - DOUBLE_00108d58);
      *(float *)(param_1 + 0x2814) =
           (float)((double)CONCAT44(0x43300000,param_3[1] ^ 0x80000000) - dVar2);
      *(float *)(param_1 + 0x2818) =
           (float)((double)CONCAT44(0x43300000,param_3[2] ^ 0x80000000) - dVar2);
      *(float *)(param_1 + 0x281c) =
           (float)((double)CONCAT44(0x43300000,param_3[3] ^ 0x80000000) - dVar2);
      *(byte *)(*(int *)(param_1 + 0x4dd0) + 0x234) =
           *(byte *)(*(int *)(param_1 + 0x4dd0) + 0x234) | 0x1e;
      *(byte *)(*(int *)(param_1 + 0x4dd4) + 0x234) =
           *(byte *)(*(int *)(param_1 + 0x4dd4) + 0x234) | 0x1e;
      if (*(int *)(param_1 + 0x5434) == 0) {
        bVar1 = *(byte *)(*(int *)(param_1 + 0x5420) + 0x324);
      }
      else {
        bVar1 = *(byte *)(*(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x358);
      }
      iVar5 = (bVar1 >> 3 & 0x1c) + param_1;
      iVar4 = *(int *)(param_1 + 0x5424);
      *(uint *)(iVar5 + 0x324) = *(uint *)(iVar5 + 0x324) | 1 << (bVar1 & 0x1f);
      bVar1 = *(byte *)(iVar4 + 0x324);
      iVar4 = (bVar1 >> 3 & 0x1c) + param_1;
      *(uint *)(iVar4 + 0x348) = *(uint *)(iVar4 + 0x348) | 1 << (bVar1 & 0x1f);
    }
    else if (param_2 < 0xb54) {
      if (param_2 == 0xb51) {
        *(bool *)(param_1 + 0x30ad) = *param_3 != 0;
      }
      else {
        if (param_2 != 0xb52) goto LAB_0006d690;
        *(bool *)(param_1 + 0x30ac) = *param_3 != 0;
        _gleUpdatePolyMode(param_1);
        _gleSelectVertexSubmitFunc(param_1);
        _gleSelectVertexAddMaterialFunc(param_1);
      }
    }
    else if (param_2 == 0x81f8) {
      if (1 < *param_3 - 0x81f9) goto LAB_0006d690;
      *(short *)(param_1 + 0x30a8) = (short)*param_3;
      if ((*(char *)(param_1 + 0x30aa) != '\0') && (*(char *)(param_1 + 0x4664) == '\0')) {
        *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x800;
        *(bool *)(param_1 + 0x316b) = *(short *)(param_1 + 0x30a8) == -0x7e06;
      }
    }
    else {
      if (param_2 != 0x85b0) {
LAB_0006d690:
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        uVar3 = 0x500;
        goto LAB_0006d6a0;
      }
      *(bool *)(param_1 + 0x30ae) = *param_3 != 0;
    }
    _gleUpdateLightModel(param_1);
    *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 1;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
LAB_0006d6a0:
    *(undefined4 *)(param_1 + 0x7574) = uVar3;
  }
  return;
}

/* _glLightModeliv_CompExec @ 0x6d6d0 (64 bytes) */
int _glLightModeliv_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glLightModeliv_Comp)(param_1,param_2,param_3);
  ((int (*)())_glLightModeliv_Exec)(param_1,param_2,param_3);
  return;
}

/* _glLockArraysEXT_Exec @ 0x6d710 (352 bytes) */
int _glLockArraysEXT_Exec(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  bool bVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  
  if ((*(short *)(param_1 + 0x4a10) < 0) && (*(int *)(param_1 + 0x4988) == 0)) {
    if ((-1 < param_2) && (0 < param_3)) {
      iVar4 = *(int *)(*(int *)(param_1 + 0x468c) + 0x88);
      if (param_3 < iVar4 + -0x12) {
        pvVar3 = *(void **)(param_1 + 0x49ac);
        bVar1 = pvVar3 == (void *)0x0;
        if (bVar1) {
          pvVar3 = _malloc(iVar4 * 5 + 0x48);
          *(void **)(param_1 + 0x49ac) = pvVar3;
          *(int *)(param_1 + 0x49a0) = (int)pvVar3 + iVar4;
          *(int *)(param_1 + 0x499c) = (int)pvVar3 + iVar4 + iVar4 * 4;
          bVar1 = pvVar3 == (void *)0x0;
        }
        else if (param_2 != *(int *)(param_1 + 0x4984)) {
          *(int *)(param_1 + 0x499c) = *(int *)(param_1 + 0x49a0) + iVar4 * 4;
        }
        if (bVar1) {
          *(void **)(param_1 + 0x499c) = pvVar3;
          *(void **)(param_1 + 0x49a0) = pvVar3;
        }
        else {
          *(undefined4 *)(param_1 + 0x497c) = 0x1f;
        }
      }
      else if (*(void **)(param_1 + 0x49ac) != (void *)0x0) {
        _free(*(void **)(param_1 + 0x49ac));
        *(undefined4 *)(param_1 + 0x499c) = 0;
        *(undefined4 *)(param_1 + 0x49ac) = 0;
        *(undefined4 *)(param_1 + 0x49a0) = 0;
      }
      *(int *)(param_1 + 0x4984) = param_2;
      *(int *)(param_1 + 0x4988) = param_3;
      if (param_3 == 0) {
        return;
      }
      _gleUpdateDrawArraysFuncs(param_1);
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

/* _glUnlockArraysEXT_Exec @ 0x6d870 (64 bytes) */
int _glUnlockArraysEXT_Exec(param_1)
  int param_1;
{
  if ((*(short *)(param_1 + 0x4a10) < 0) && (*(int *)(param_1 + 0x4988) != 0)) {
    *(undefined4 *)(param_1 + 0x4988) = 0;
    *(undefined4 *)(param_1 + 0x4984) = 0;
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x502;
  return;
}

/* _glLogicOp_ListExec @ 0x6d8b0 (40 bytes) */
int _glLogicOp_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((int (*)())_glLogicOp_Exec)(param_1,*param_2);
  return 4;
}

/* _glLogicOp_Comp @ 0x6d8d8 (76 bytes) */
int _glLogicOp_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glLogicOp_ListExec_0011015c,4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glLogicOp_Exec @ 0x6d924 (88 bytes) */
int _glLogicOp_Exec(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 - 0x1500U < 0x10) {
      *(short *)(param_1 + 0x3190) = (short)param_2;
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x20000;
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

/* _glLogicOp_CompExec @ 0x6d97c (56 bytes) */
int _glLogicOp_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glLogicOp_Comp)(param_1,param_2);
  ((int (*)())_glLogicOp_Exec)(param_1,param_2);
  return;
}

/* _glMap1Vertex3_ListExec @ 0x6d9b4 (140 bytes) */
int _glMap1Vertex3_ListExec(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  piVar5 = (int *)_gleGetMapData(param_1);
  iVar4 = *param_2;
  iVar6 = param_2[2];
  iVar2 = param_2[3];
  piVar5[1] = param_2[1];
  piVar5[2] = iVar6;
  piVar5[3] = iVar2;
  *piVar5 = iVar4;
  for (iVar6 = iVar4; iVar6 != 0; iVar6 = iVar6 + -1) {
    piVar1 = param_2 + 4;
    iVar2 = param_2[5];
    iVar3 = param_2[6];
    param_2 = param_2 + 3;
    piVar5[4] = *piVar1;
    piVar5[5] = iVar2;
    piVar5[6] = iVar3;
    piVar5 = piVar5 + 3;
  }
  return (10 - iVar4) * -0xc + 0x88;
}

/* _glMap1Vertex4_ListExec @ 0x6da40 (156 bytes) */
int _glMap1Vertex4_ListExec(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar6 = _gleGetMapData(param_1);
  iVar5 = *param_2;
  iVar8 = param_2[2];
  iVar1 = param_2[3];
  *(int *)(iVar6 + 0x8c) = param_2[1];
  *(int *)(iVar6 + 0x90) = iVar8;
  *(int *)(iVar6 + 0x94) = iVar1;
  *(int *)(iVar6 + 0x88) = iVar5;
  iVar1 = 0;
  for (iVar8 = iVar5; iVar8 != 0; iVar8 = iVar8 + -1) {
    iVar7 = iVar1 * 0x10 + iVar6;
    iVar2 = param_2[iVar1 * 4 + 4];
    iVar3 = param_2[iVar1 * 4 + 5];
    iVar4 = param_2[iVar1 * 4 + 6];
    *(int *)(iVar7 + 0xa4) = param_2[iVar1 * 4 + 7];
    *(int *)(iVar7 + 0x98) = iVar2;
    *(int *)(iVar7 + 0x9c) = iVar3;
    *(int *)(iVar7 + 0xa0) = iVar4;
    iVar1 = iVar1 + 1;
  }
  return (10 - iVar5) * -0x10 + 0xb0;
}

/* _glMap1Color_ListExec @ 0x6dadc (156 bytes) */
int _glMap1Color_ListExec(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar6 = _gleGetMapData(param_1);
  iVar5 = *param_2;
  iVar8 = param_2[2];
  iVar1 = param_2[3];
  *(int *)(iVar6 + 0x1c4) = param_2[1];
  *(int *)(iVar6 + 0x1c8) = iVar8;
  *(int *)(iVar6 + 0x1cc) = iVar1;
  *(int *)(iVar6 + 0x1c0) = iVar5;
  iVar1 = 0;
  for (iVar8 = iVar5; iVar8 != 0; iVar8 = iVar8 + -1) {
    iVar7 = iVar1 * 0x10 + iVar6;
    iVar2 = param_2[iVar1 * 4 + 4];
    iVar3 = param_2[iVar1 * 4 + 5];
    iVar4 = param_2[iVar1 * 4 + 6];
    *(int *)(iVar7 + 0x1dc) = param_2[iVar1 * 4 + 7];
    *(int *)(iVar7 + 0x1d0) = iVar2;
    *(int *)(iVar7 + 0x1d4) = iVar3;
    *(int *)(iVar7 + 0x1d8) = iVar4;
    iVar1 = iVar1 + 1;
  }
  return (10 - iVar5) * -0x10 + 0xb0;
}

/* _glMap1Index_ListExec @ 0x6db78 (128 bytes) */
int _glMap1Index_ListExec(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  
  iVar3 = _gleGetMapData(param_1);
  iVar2 = *param_2;
  iVar6 = param_2[2];
  iVar1 = param_2[3];
  *(int *)(iVar3 + 0x274) = param_2[1];
  *(int *)(iVar3 + 0x278) = iVar6;
  *(int *)(iVar3 + 0x27c) = iVar1;
  *(int *)(iVar3 + 0x270) = iVar2;
  if (iVar2 != 0) {
    piVar4 = (int *)(iVar3 + 0x280);
    piVar5 = param_2 + 4;
    iVar6 = iVar2;
    do {
      iVar1 = *piVar5;
      piVar5 = piVar5 + 1;
      *piVar4 = iVar1;
      piVar4 = piVar4 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  return (10 - iVar2) * -4 + 0x38;
}

/* _glMap1Normal_ListExec @ 0x6dbf8 (140 bytes) */
int _glMap1Normal_ListExec(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = _gleGetMapData(param_1);
  iVar4 = *param_2;
  iVar6 = param_2[2];
  iVar2 = param_2[3];
  *(int *)(iVar5 + 0x13c) = param_2[1];
  *(int *)(iVar5 + 0x140) = iVar6;
  *(int *)(iVar5 + 0x144) = iVar2;
  *(int *)(iVar5 + 0x138) = iVar4;
  for (iVar6 = iVar4; iVar6 != 0; iVar6 = iVar6 + -1) {
    piVar1 = param_2 + 4;
    iVar2 = param_2[5];
    iVar3 = param_2[6];
    param_2 = param_2 + 3;
    *(int *)(iVar5 + 0x148) = *piVar1;
    *(int *)(iVar5 + 0x14c) = iVar2;
    *(int *)(iVar5 + 0x150) = iVar3;
    iVar5 = iVar5 + 0xc;
  }
  return (10 - iVar4) * -0xc + 0x88;
}

/* _glMap1Texture1_ListExec @ 0x6dc84 (128 bytes) */
int _glMap1Texture1_ListExec(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  
  iVar3 = _gleGetMapData(param_1);
  iVar2 = *param_2;
  iVar6 = param_2[2];
  iVar1 = param_2[3];
  *(int *)(iVar3 + 0x2ac) = param_2[1];
  *(int *)(iVar3 + 0x2b0) = iVar6;
  *(int *)(iVar3 + 0x2b4) = iVar1;
  *(int *)(iVar3 + 0x2a8) = iVar2;
  if (iVar2 != 0) {
    piVar4 = (int *)(iVar3 + 0x2b8);
    piVar5 = param_2 + 4;
    iVar6 = iVar2;
    do {
      iVar1 = *piVar5;
      piVar5 = piVar5 + 1;
      *piVar4 = iVar1;
      piVar4 = piVar4 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  return (10 - iVar2) * -4 + 0x38;
}

/* _glMap1Texture2_ListExec @ 0x6dd04 (140 bytes) */
int _glMap1Texture2_ListExec(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = _gleGetMapData(param_1);
  iVar3 = *param_2;
  iVar6 = param_2[2];
  iVar1 = param_2[3];
  *(int *)(iVar5 + 0x2e4) = param_2[1];
  *(int *)(iVar5 + 0x2e8) = iVar6;
  *(int *)(iVar5 + 0x2ec) = iVar1;
  *(int *)(iVar5 + 0x2e0) = iVar3;
  iVar1 = 0;
  for (iVar6 = iVar3; iVar6 != 0; iVar6 = iVar6 + -1) {
    iVar4 = iVar1 * 8 + iVar5;
    iVar2 = param_2[iVar1 * 2 + 4];
    *(int *)(iVar4 + 0x2f4) = param_2[iVar1 * 2 + 5];
    *(int *)(iVar4 + 0x2f0) = iVar2;
    iVar1 = iVar1 + 1;
  }
  return (10 - iVar3) * -8 + 0x60;
}

/* _glMap1Texture3_ListExec @ 0x6dd90 (140 bytes) */
int _glMap1Texture3_ListExec(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = _gleGetMapData(param_1);
  iVar4 = *param_2;
  iVar6 = param_2[2];
  iVar2 = param_2[3];
  *(int *)(iVar5 + 0x344) = param_2[1];
  *(int *)(iVar5 + 0x348) = iVar6;
  *(int *)(iVar5 + 0x34c) = iVar2;
  *(int *)(iVar5 + 0x340) = iVar4;
  for (iVar6 = iVar4; iVar6 != 0; iVar6 = iVar6 + -1) {
    piVar1 = param_2 + 4;
    iVar2 = param_2[5];
    iVar3 = param_2[6];
    param_2 = param_2 + 3;
    *(int *)(iVar5 + 0x350) = *piVar1;
    *(int *)(iVar5 + 0x354) = iVar2;
    *(int *)(iVar5 + 0x358) = iVar3;
    iVar5 = iVar5 + 0xc;
  }
  return (10 - iVar4) * -0xc + 0x88;
}

/* _glMap1Texture4_ListExec @ 0x6de1c (156 bytes) */
int _glMap1Texture4_ListExec(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar6 = _gleGetMapData(param_1);
  iVar5 = *param_2;
  iVar8 = param_2[2];
  iVar1 = param_2[3];
  *(int *)(iVar6 + 0x3cc) = param_2[1];
  *(int *)(iVar6 + 0x3d0) = iVar8;
  *(int *)(iVar6 + 0x3d4) = iVar1;
  *(int *)(iVar6 + 0x3c8) = iVar5;
  iVar1 = 0;
  for (iVar8 = iVar5; iVar8 != 0; iVar8 = iVar8 + -1) {
    iVar7 = iVar1 * 0x10 + iVar6;
    iVar2 = param_2[iVar1 * 4 + 4];
    iVar3 = param_2[iVar1 * 4 + 5];
    iVar4 = param_2[iVar1 * 4 + 6];
    *(int *)(iVar7 + 0x3e4) = param_2[iVar1 * 4 + 7];
    *(int *)(iVar7 + 0x3d8) = iVar2;
    *(int *)(iVar7 + 0x3dc) = iVar3;
    *(int *)(iVar7 + 0x3e0) = iVar4;
    iVar1 = iVar1 + 1;
  }
  return (10 - iVar5) * -0x10 + 0xb0;
}

/* _glMap1VertexAttrib1ARB_ListExec @ 0x6deb8 (164 bytes) */
int _glMap1VertexAttrib1ARB_ListExec(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = _gleGetMapData(param_1);
  iVar5 = *param_2;
  iVar6 = param_2[1];
  iVar3 = iVar2 + iVar5 * 0xb0;
  *(int *)(iVar3 + 0x2ca8) = iVar6;
  ((code **)_gleSelectVertexAddMaterialFunc)[iVar5 + iVar2] = (code *)0x1;
  iVar2 = param_2[2];
  iVar5 = param_2[3];
  *(int *)(iVar3 + 0x2cb4) = param_2[4];
  *(int *)(iVar3 + 0x2cac) = iVar2;
  *(int *)(iVar3 + 0x2cb0) = iVar5;
  if (iVar6 != 0) {
    piVar4 = (int *)(iVar3 + 0x2cb8);
    piVar1 = param_2 + 5;
    iVar2 = iVar6;
    do {
      iVar5 = *piVar1;
      piVar1 = piVar1 + 1;
      *piVar4 = iVar5;
      piVar4 = piVar4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return (10 - iVar6) * -4 + 0x3c;
}

/* _glMap1VertexAttrib2ARB_ListExec @ 0x6df5c (164 bytes) */
int _glMap1VertexAttrib2ARB_ListExec(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  
  iVar3 = _gleGetMapData(param_1);
  iVar2 = *param_2;
  iVar6 = param_2[1];
  piVar7 = param_2 + 1;
  iVar4 = iVar3 + iVar2 * 0xb0;
  *(int *)(iVar4 + 0x2ca8) = iVar6;
  iVar5 = iVar4 + 0x2ca8;
  ((code **)_gleSelectVertexAddMaterialFunc)[iVar2 + iVar3] = (code *)0x2;
  iVar2 = param_2[3];
  iVar3 = param_2[4];
  *(int *)(iVar4 + 0x2cac) = param_2[2];
  *(int *)(iVar4 + 0x2cb0) = iVar2;
  *(int *)(iVar4 + 0x2cb4) = iVar3;
  for (iVar2 = iVar6; iVar2 != 0; iVar2 = iVar2 + -1) {
    piVar1 = piVar7 + 4;
    iVar3 = piVar7[5];
    piVar7 = piVar7 + 2;
    *(int *)(iVar5 + 0x10) = *piVar1;
    *(int *)(iVar5 + 0x14) = iVar3;
    iVar5 = iVar5 + 8;
  }
  return (10 - iVar6) * -8 + 100;
}

/* _glMap1VertexAttrib3ARB_ListExec @ 0x6e000 (172 bytes) */
int _glMap1VertexAttrib3ARB_ListExec(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  
  iVar3 = _gleGetMapData(param_1);
  iVar2 = *param_2;
  iVar6 = param_2[1];
  piVar7 = param_2 + 1;
  iVar4 = iVar3 + iVar2 * 0xb0;
  *(int *)(iVar4 + 0x2ca8) = iVar6;
  iVar5 = iVar4 + 0x2ca8;
  ((code **)_gleSelectVertexAddMaterialFunc)[iVar2 + iVar3] = (code *)0x3;
  iVar2 = param_2[3];
  iVar3 = param_2[4];
  *(int *)(iVar4 + 0x2cac) = param_2[2];
  *(int *)(iVar4 + 0x2cb0) = iVar2;
  *(int *)(iVar4 + 0x2cb4) = iVar3;
  for (iVar2 = iVar6; iVar2 != 0; iVar2 = iVar2 + -1) {
    piVar1 = piVar7 + 4;
    iVar3 = piVar7[5];
    iVar4 = piVar7[6];
    piVar7 = piVar7 + 3;
    *(int *)(iVar5 + 0x10) = *piVar1;
    *(int *)(iVar5 + 0x14) = iVar3;
    *(int *)(iVar5 + 0x18) = iVar4;
    iVar5 = iVar5 + 0xc;
  }
  return (10 - iVar6) * -0xc + 0x8c;
}

/* _glMap1VertexAttrib4ARB_ListExec @ 0x6e0ac (200 bytes) */
int _glMap1VertexAttrib4ARB_ListExec(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar2 = _gleGetMapData(param_1);
  iVar1 = *param_2;
  iVar4 = param_2[1];
  iVar3 = iVar2 + iVar1 * 0xb0;
  *(int *)(iVar3 + 0x2ca8) = iVar4;
  ((code **)_gleSelectVertexAddMaterialFunc)[iVar1 + iVar2] = (code *)0x4;
  iVar1 = param_2[3];
  iVar2 = param_2[4];
  *(int *)(iVar3 + 0x2cac) = param_2[2];
  *(int *)(iVar3 + 0x2cb0) = iVar1;
  *(int *)(iVar3 + 0x2cb4) = iVar2;
  iVar2 = 0;
  for (iVar1 = iVar4; iVar1 != 0; iVar1 = iVar1 + -1) {
    iVar8 = iVar2 * 0x10 + iVar3 + 0x2ca8;
    iVar7 = param_2[iVar2 * 4 + 8];
    iVar6 = param_2[iVar2 * 4 + 6];
    iVar5 = param_2[iVar2 * 4 + 7];
    *(int *)(iVar8 + 0x10) = param_2[iVar2 * 4 + 5];
    *(int *)(iVar8 + 0x1c) = iVar7;
    *(int *)(iVar8 + 0x14) = iVar6;
    *(int *)(iVar8 + 0x18) = iVar5;
    iVar2 = iVar2 + 1;
  }
  return (10 - iVar4) * -0x10 + 0xb4;
}

/* _glMap1d_Comp @ 0x6e174 (1080 bytes) */
double _glMap1d_Comp(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,int param_7,int param_8,double fparam_1,double fparam_2)
{
  undefined4 uVar1;
  int iVar2;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 extraout_r4_03;
  undefined4 extraout_r4_04;
  undefined4 extraout_r4_05;
  undefined4 extraout_r4_06;
  undefined4 extraout_r4_07;
  int iVar3;
  undefined4 in_LR;
  double extraout_f1;
  double extraout_f1_00;
  double dVar4;
  double extraout_f1_01;
  double extraout_f1_02;
  double extraout_f1_03;
  double extraout_f1_04;
  double extraout_f1_05;
  double extraout_f1_06;
  double extraout_f1_07;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((fparam_1 != fparam_2) && (param_8 - 1U < 10)) {
      switch(param_2) {
      case 0xd90:
        if (3 < param_7) {
          iVar3 = (10 - param_8) * -0x10 + 0xb0;
          iVar2 = _gleAddListItem(param_1,PTR__glMap1Color_ListExec_00110188,iVar3);
          if (iVar2 == 0) {
            return extraout_f1_01;
          }
          dVar4 = (double)((double (*)())_gleMap1ColordLoad)(param_1,extraout_r4_01,iVar3,param_4,param_5,param_7,
                                             param_8,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),fparam_1,fparam_2,in_f3,in_f4
                                             ,in_f5,in_f6,in_f7,in_f8,
                                             (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),
                                             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),
                                             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return dVar4;
        }
        break;
      case 0xd91:
        if (0 < param_7) {
          iVar3 = (10 - param_8) * -4 + 0x38;
          iVar2 = _gleAddListItem(param_1,PTR__glMap1Index_ListExec_00110184,iVar3);
          if (iVar2 == 0) {
            return extraout_f1_02;
          }
          dVar4 = (double)((double (*)())_gleMap1IndexdLoad)(param_1,extraout_r4_02,iVar3,param_4,param_5,param_7,
                                             param_8,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),fparam_1,fparam_2,in_f3,in_f4
                                             ,in_f5,in_f6,in_f7,in_f8,
                                             (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),
                                             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),
                                             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return dVar4;
        }
        break;
      case 0xd92:
        if (2 < param_7) {
          iVar3 = (10 - param_8) * -0xc + 0x88;
          iVar2 = _gleAddListItem(param_1,PTR__glMap1Normal_ListExec_00110180,iVar3);
          if (iVar2 == 0) {
            return extraout_f1_03;
          }
          dVar4 = (double)((double (*)())_gleMap1NormaldLoad)(param_1,extraout_r4_03,iVar3,param_4,param_5,param_7,
                                              param_8,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),fparam_1,fparam_2,in_f3,
                                              in_f4,in_f5,in_f6,in_f7,in_f8,
                                              (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),
                                              (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),
                                              (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return dVar4;
        }
        break;
      case 0xd93:
        if (0 < param_7) {
          iVar3 = (10 - param_8) * -4 + 0x38;
          iVar2 = _gleAddListItem(param_1,PTR__glMap1Texture1_ListExec_0011017c,iVar3);
          if (iVar2 == 0) {
            return extraout_f1_04;
          }
          dVar4 = (double)((double (*)())_gleMap1Texture1dLoad)(param_1,extraout_r4_04,iVar3,param_4,param_5,param_7,param_8,
                                     (*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),fparam_1,fparam_2,in_f3,in_f4,in_f5,in_f6,
                                     in_f7,in_f8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),
                                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),
                                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return dVar4;
        }
        break;
      case 0xd94:
        if (1 < param_7) {
          iVar3 = (10 - param_8) * -8 + 0x60;
          iVar2 = _gleAddListItem(param_1,PTR__glMap1Texture2_ListExec_00110178,iVar3);
          if (iVar2 == 0) {
            return extraout_f1_05;
          }
          dVar4 = (double)((double (*)())_gleMap1Texture2dLoad)(param_1,extraout_r4_05,iVar3,param_4,param_5,param_7,param_8,
                                     (*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),fparam_1,fparam_2,in_f3,in_f4,in_f5,in_f6,
                                     in_f7,in_f8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),
                                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),
                                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return dVar4;
        }
        break;
      case 0xd95:
        if (2 < param_7) {
          iVar3 = (10 - param_8) * -0xc + 0x88;
          iVar2 = _gleAddListItem(param_1,PTR__glMap1Texture3_ListExec_00110174,iVar3);
          if (iVar2 == 0) {
            return extraout_f1_06;
          }
          dVar4 = (double)((double (*)())_gleMap1Texture3dLoad)(param_1,extraout_r4_06,iVar3,param_4,param_5,param_7,param_8,
                                     (*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),fparam_1,fparam_2,in_f3,in_f4,in_f5,in_f6,
                                     in_f7,in_f8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),
                                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),
                                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return dVar4;
        }
        break;
      case 0xd96:
        if (3 < param_7) {
          iVar3 = (10 - param_8) * -0x10 + 0xb0;
          iVar2 = _gleAddListItem(param_1,PTR__glMap1Texture4_ListExec_00110170,iVar3);
          if (iVar2 == 0) {
            return extraout_f1_07;
          }
          dVar4 = (double)((double (*)())_gleMap1Texture4dLoad)(param_1,extraout_r4_07,iVar3,param_4,param_5,param_7,param_8,
                                     (*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),fparam_1,fparam_2,in_f3,in_f4,in_f5,in_f6,
                                     in_f7,in_f8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),
                                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),
                                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return dVar4;
        }
        break;
      case 0xd97:
        if (2 < param_7) {
          iVar3 = (10 - param_8) * -0xc + 0x88;
          iVar2 = _gleAddListItem(param_1,PTR__glMap1Vertex3_ListExec_00110190,iVar3);
          if (iVar2 == 0) {
            return extraout_f1;
          }
          dVar4 = (double)((double (*)())_gleMap1Vertex3dLoad)(param_1,extraout_r4,iVar3,param_4,param_5,param_7,param_8,
                                     (*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),fparam_1,fparam_2,in_f3,in_f4,in_f5,in_f6,
                                     in_f7,in_f8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),
                                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),
                                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return dVar4;
        }
        break;
      case 0xd98:
        if (3 < param_7) {
          iVar3 = (10 - param_8) * -0x10 + 0xb0;
          iVar2 = _gleAddListItem(param_1,PTR__glMap1Vertex4_ListExec_0011018c,iVar3);
          if (iVar2 == 0) {
            return extraout_f1_00;
          }
          dVar4 = (double)((double (*)())_gleMap1Vertex4dLoad)(param_1,extraout_r4_00,iVar3,param_4,param_5,param_7,param_8,
                                     (*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),fparam_1,fparam_2,in_f3,in_f4,in_f5,in_f6,
                                     in_f7,in_f8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),
                                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),
                                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return dVar4;
        }
        break;
      default:
        if (*(int *)(param_1 + 0x7574) != 0) {
          return fparam_1;
        }
        uVar1 = 0x500;
        goto LAB_0006e5b0;
      }
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return fparam_1;
    }
    uVar1 = 0x501;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return fparam_1;
    }
    uVar1 = 0x502;
  }
LAB_0006e5b0:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return fparam_1;
}

/* _glMap1d_Exec @ 0x6e5d0 (836 bytes) */
void _glMap1d_Exec(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,int param_7,int param_8,double fparam_1,double fparam_2)
{
  undefined4 uVar1;
  int iVar2;
  undefined4 in_LR;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  _gleGetMapData(param_1);
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((fparam_1 != fparam_2) && (param_8 - 1U < 10)) {
      iVar2 = param_2 + -0xd90;
      switch(iVar2) {
      case 0:
        if (3 < param_7) {
          ((double (*)())_gleMap1ColordLoad)(param_1,iVar2,param_3,param_4,param_5,param_7,param_8,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0x38))
                             ,fparam_1,fparam_2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                             (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 1:
        if (0 < param_7) {
          ((double (*)())_gleMap1IndexdLoad)(param_1,iVar2,param_3,param_4,param_5,param_7,param_8,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0x38))
                             ,fparam_1,fparam_2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                             (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 2:
        if (2 < param_7) {
          ((double (*)())_gleMap1NormaldLoad)(param_1,iVar2,param_3,param_4,param_5,param_7,param_8,
                              (*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),fparam_1,fparam_2,in_f3,in_f4,in_f5,in_f6,in_f7,
                              in_f8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                              (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 3:
        if (0 < param_7) {
          ((double (*)())_gleMap1Texture1dLoad)(param_1,iVar2,param_3,param_4,param_5,param_7,param_8,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),
                     fparam_1,fparam_2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                     (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),
                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 4:
        if (1 < param_7) {
          ((double (*)())_gleMap1Texture2dLoad)(param_1,iVar2,param_3,param_4,param_5,param_7,param_8,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),
                     fparam_1,fparam_2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                     (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),
                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 5:
        if (2 < param_7) {
          ((double (*)())_gleMap1Texture3dLoad)(param_1,iVar2,param_3,param_4,param_5,param_7,param_8,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),
                     fparam_1,fparam_2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                     (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),
                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 6:
        if (3 < param_7) {
          ((double (*)())_gleMap1Texture4dLoad)(param_1,iVar2,param_3,param_4,param_5,param_7,param_8,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),
                     fparam_1,fparam_2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                     (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),
                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 7:
        if (2 < param_7) {
          ((double (*)())_gleMap1Vertex3dLoad)(param_1,iVar2,param_3,param_4,param_5,param_7,param_8,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),
                     fparam_1,fparam_2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                     (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),
                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 8:
        if (3 < param_7) {
          ((double (*)())_gleMap1Vertex4dLoad)(param_1,iVar2,param_3,param_4,param_5,param_7,param_8,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),
                     fparam_1,fparam_2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                     (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),
                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      default:
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        uVar1 = 0x500;
        goto LAB_0006e918;
      }
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x501;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
  }
LAB_0006e918:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glMap1d_CompExec @ 0x6e938 (116 bytes) */
void _glMap1d_CompExec(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,double fparam_1,double fparam_2)
{
  ((double (*)())_glMap1d_Comp)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,fparam_1,fparam_2);
  ((void (*)())_glMap1d_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,fparam_1,fparam_2);
  return;
}

/* _glMap1f_Comp @ 0x6e9ac (1044 bytes) */
int _glMap1f_Comp(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,int param_6,undefined4 param_7,double fparam_1,double fparam_2)
{
  undefined4 uVar1;
  int iVar2;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 extraout_r4_03;
  undefined4 extraout_r4_04;
  undefined4 extraout_r4_05;
  undefined4 extraout_r4_06;
  undefined4 extraout_r4_07;
  int iVar3;
  undefined4 in_LR;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((fparam_1 != fparam_2) && (param_6 - 1U < 10)) {
      switch(param_2) {
      case 0xd90:
        if (3 < param_5) {
          iVar3 = (10 - param_6) * -0x10 + 0xb0;
          iVar2 = _gleAddListItem(param_1,PTR__glMap1Color_ListExec_00110188,iVar3);
          if (iVar2 == 0) {
            return 0;
          }
          uVar1 = ((int (*)())_gleMap1ColorfLoad)(param_1,extraout_r4_01,iVar3,param_5,param_6,param_7,iVar2,
                                     fparam_1,fparam_2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                                     (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return uVar1;
        }
        break;
      case 0xd91:
        if (0 < param_5) {
          iVar3 = (10 - param_6) * -4 + 0x38;
          iVar2 = _gleAddListItem(param_1,PTR__glMap1Index_ListExec_00110184,iVar3);
          if (iVar2 == 0) {
            return 0;
          }
          uVar1 = ((int (*)())_gleMap1IndexfLoad)(param_1,extraout_r4_02,iVar3,param_5,param_6,param_7,iVar2,
                                     fparam_1,fparam_2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                                     (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return uVar1;
        }
        break;
      case 0xd92:
        if (2 < param_5) {
          iVar3 = (10 - param_6) * -0xc + 0x88;
          iVar2 = _gleAddListItem(param_1,PTR__glMap1Normal_ListExec_00110180,iVar3);
          if (iVar2 == 0) {
            return 0;
          }
          uVar1 = ((int (*)())_gleMap1NormalfLoad)(param_1,extraout_r4_03,iVar3,param_5,param_6,param_7,iVar2,
                                      fparam_1,fparam_2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                                      (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                                      (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return uVar1;
        }
        break;
      case 0xd93:
        if (0 < param_5) {
          iVar3 = (10 - param_6) * -4 + 0x38;
          iVar2 = _gleAddListItem(param_1,PTR__glMap1Texture1_ListExec_0011017c,iVar3);
          if (iVar2 == 0) {
            return 0;
          }
          uVar1 = ((int (*)())_gleMap1Texture1fLoad)(param_1,extraout_r4_04,iVar3,param_5,param_6,param_7,iVar2,fparam_1,
                             fparam_2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                             (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return uVar1;
        }
        break;
      case 0xd94:
        if (1 < param_5) {
          iVar3 = (10 - param_6) * -8 + 0x60;
          iVar2 = _gleAddListItem(param_1,PTR__glMap1Texture2_ListExec_00110178,iVar3);
          if (iVar2 == 0) {
            return 0;
          }
          uVar1 = ((int (*)())_gleMap1Texture2fLoad)(param_1,extraout_r4_05,iVar3,param_5,param_6,param_7,iVar2,fparam_1,
                             fparam_2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                             (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return uVar1;
        }
        break;
      case 0xd95:
        if (2 < param_5) {
          iVar3 = (10 - param_6) * -0xc + 0x88;
          iVar2 = _gleAddListItem(param_1,PTR__glMap1Texture3_ListExec_00110174,iVar3);
          if (iVar2 == 0) {
            return 0;
          }
          uVar1 = ((int (*)())_gleMap1Texture3fLoad)(param_1,extraout_r4_06,iVar3,param_5,param_6,param_7,iVar2,fparam_1,
                             fparam_2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                             (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return uVar1;
        }
        break;
      case 0xd96:
        if (3 < param_5) {
          iVar3 = (10 - param_6) * -0x10 + 0xb0;
          iVar2 = _gleAddListItem(param_1,PTR__glMap1Texture4_ListExec_00110170,iVar3);
          if (iVar2 == 0) {
            return 0;
          }
          uVar1 = ((int (*)())_gleMap1Texture4fLoad)(param_1,extraout_r4_07,iVar3,param_5,param_6,param_7,iVar2,fparam_1,
                             fparam_2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                             (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return uVar1;
        }
        break;
      case 0xd97:
        if (2 < param_5) {
          iVar3 = (10 - param_6) * -0xc + 0x88;
          iVar2 = _gleAddListItem(param_1,PTR__glMap1Vertex3_ListExec_00110190,iVar3);
          if (iVar2 == 0) {
            return 0;
          }
          uVar1 = ((int (*)())_gleMap1Vertex3fLoad)(param_1,extraout_r4,iVar3,param_5,param_6,param_7,iVar2,fparam_1,
                             fparam_2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                             (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return uVar1;
        }
        break;
      case 0xd98:
        if (3 < param_5) {
          iVar3 = (10 - param_6) * -0x10 + 0xb0;
          iVar2 = _gleAddListItem(param_1,PTR__glMap1Vertex4_ListExec_0011018c,iVar3);
          if (iVar2 == 0) {
            return 0;
          }
          uVar1 = ((int (*)())_gleMap1Vertex4fLoad)(param_1,extraout_r4_00,iVar3,param_5,param_6,param_7,iVar2,fparam_1,
                             fparam_2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                             (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return uVar1;
        }
        break;
      default:
        if (*(int *)(param_1 + 0x7574) != 0) {
          return param_1;
        }
        uVar1 = 0x500;
        goto LAB_0006edc4;
      }
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return param_1;
    }
    uVar1 = 0x501;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return param_1;
    }
    uVar1 = 0x502;
  }
LAB_0006edc4:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return param_1;
}

/* _glMap1f_Exec @ 0x6ede4 (804 bytes) */
void _glMap1f_Exec(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,int param_6,undefined4 param_7,double fparam_1,double fparam_2)
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 in_LR;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  iVar2 = _gleGetMapData(param_1);
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((fparam_1 != fparam_2) && (param_6 - 1U < 10)) {
      iVar3 = param_2 + -0xd90;
      switch(iVar3) {
      case 0:
        if (3 < param_5) {
          ((int (*)())_gleMap1ColorfLoad)(param_1,iVar3,param_3,param_5,param_6,param_7,iVar2 + 0x1c0,fparam_1,
                             fparam_2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                             (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 1:
        if (0 < param_5) {
          ((int (*)())_gleMap1IndexfLoad)(param_1,iVar3,param_3,param_5,param_6,param_7,iVar2 + 0x270,fparam_1,
                             fparam_2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                             (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 2:
        if (2 < param_5) {
          ((int (*)())_gleMap1NormalfLoad)(param_1,iVar3,param_3,param_5,param_6,param_7,iVar2 + 0x138,fparam_1,
                              fparam_2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                              (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                              (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 3:
        if (0 < param_5) {
          ((int (*)())_gleMap1Texture1fLoad)(param_1,iVar3,param_3,param_5,param_6,param_7,iVar2 + 0x2a8,fparam_1,fparam_2,
                     in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),
                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 4:
        if (1 < param_5) {
          ((int (*)())_gleMap1Texture2fLoad)(param_1,iVar3,param_3,param_5,param_6,param_7,iVar2 + 0x2e0,fparam_1,fparam_2,
                     in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),
                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 5:
        if (2 < param_5) {
          ((int (*)())_gleMap1Texture3fLoad)(param_1,iVar3,param_3,param_5,param_6,param_7,iVar2 + 0x340,fparam_1,fparam_2,
                     in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),
                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 6:
        if (3 < param_5) {
          ((int (*)())_gleMap1Texture4fLoad)(param_1,iVar3,param_3,param_5,param_6,param_7,iVar2 + 0x3c8,fparam_1,fparam_2,
                     in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),
                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 7:
        if (2 < param_5) {
          ((int (*)())_gleMap1Vertex3fLoad)(param_1,iVar3,param_3,param_5,param_6,param_7,iVar2,fparam_1,fparam_2,in_f3,
                     in_f4,in_f5,in_f6,in_f7,in_f8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),
                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 8:
        if (3 < param_5) {
          ((int (*)())_gleMap1Vertex4fLoad)(param_1,iVar3,param_3,param_5,param_6,param_7,iVar2 + 0x88,fparam_1,fparam_2,
                     in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),
                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      default:
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        uVar1 = 0x500;
        goto LAB_0006f10c;
      }
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x501;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
  }
LAB_0006f10c:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glMap1f_CompExec @ 0x6f12c (112 bytes) */
void _glMap1f_CompExec(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,double fparam_2)
{
  ((int (*)())_glMap1f_Comp)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,fparam_1,fparam_2);
  ((void (*)())_glMap1f_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,fparam_1,fparam_2);
  return;
}

/* _glMapVertexAttrib1fARB_Comp @ 0x6f19c (432 bytes) */
double _glMapVertexAttrib1fARB_Comp(int param_1,undefined4 param_2,uint param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,int param_7,undefined4 param_8,double fparam_1,double fparam_2)
{
  undefined4 *puVar1;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  int iVar2;
  double extraout_f1;
  double dVar3;
  double extraout_f1_00;
  double extraout_f1_01;
  double extraout_f1_02;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffff98;
  double in_stack_ffffffa0;
  double in_stack_ffffffa8;
  double in_stack_ffffffb0;
  double in_stack_ffffffb8;
  
  if (param_3 == 2) {
    iVar2 = (10 - param_7) * -8 + 100;
    puVar1 = (undefined4 *)
             _gleAddListItem(param_1,PTR__glMap1VertexAttrib2ARB_ListExec_00110168,iVar2);
    if (puVar1 == (undefined4 *)0x0) {
      return extraout_f1_00;
    }
    dVar3 = (double)((double (*)())_gleMap1VertexAttrib2fLoad)(param_1,extraout_r4_00,iVar2,param_6,param_7,param_8,puVar1 + 1,
                               fparam_1,fparam_2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                               in_stack_ffffff98,in_stack_ffffffa0,in_stack_ffffffa8,
                               in_stack_ffffffb0,in_stack_ffffffb8);
  }
  else if (param_3 < 3) {
    if (param_3 != 1) {
LAB_0006f31c:
      if (*(int *)(param_1 + 0x7574) != 0) {
        return fparam_1;
      }
      *(undefined4 *)(param_1 + 0x7574) = 0x501;
      return fparam_1;
    }
    iVar2 = (10 - param_7) * -4 + 0x3c;
    puVar1 = (undefined4 *)
             _gleAddListItem(param_1,PTR__glMap1VertexAttrib1ARB_ListExec_0011016c,iVar2);
    if (puVar1 == (undefined4 *)0x0) {
      return extraout_f1;
    }
    dVar3 = (double)((double (*)())_gleMap1VertexAttrib1fLoad)(param_1,extraout_r4,iVar2,param_6,param_7,param_8,puVar1 + 1,fparam_1
                               ,fparam_2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_ffffff98,
                               in_stack_ffffffa0,in_stack_ffffffa8,in_stack_ffffffb0,
                               in_stack_ffffffb8);
  }
  else if (param_3 == 3) {
    iVar2 = (10 - param_7) * -0xc + 0x8c;
    puVar1 = (undefined4 *)
             _gleAddListItem(param_1,PTR__glMap1VertexAttrib3ARB_ListExec_00110164,iVar2);
    if (puVar1 == (undefined4 *)0x0) {
      return extraout_f1_01;
    }
    dVar3 = (double)((double (*)())_gleMap1VertexAttrib3fLoad)(param_1,extraout_r4_01,iVar2,param_6,param_7,param_8,puVar1 + 1,
                               fparam_1,fparam_2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                               in_stack_ffffff98,in_stack_ffffffa0,in_stack_ffffffa8,
                               in_stack_ffffffb0,in_stack_ffffffb8);
  }
  else {
    if (param_3 != 4) goto LAB_0006f31c;
    iVar2 = (10 - param_7) * -0x10 + 0xb4;
    puVar1 = (undefined4 *)
             _gleAddListItem(param_1,PTR__glMap1VertexAttrib4ARB_ListExec_00110160,iVar2);
    if (puVar1 == (undefined4 *)0x0) {
      return extraout_f1_02;
    }
    dVar3 = (double)((double (*)())_gleMap1VertexAttrib4fLoad)(param_1,extraout_r4_02,iVar2,param_6,param_7,param_8,puVar1 + 1,
                               fparam_1,fparam_2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                               in_stack_ffffff98,in_stack_ffffffa0,in_stack_ffffffa8,
                               in_stack_ffffffb0,in_stack_ffffffb8);
  }
  *puVar1 = param_2;
  return dVar3;
}

/* _glMapVertexAttrib1fARB_Exec @ 0x6f34c (444 bytes) */
void _glMapVertexAttrib1fARB_Exec(int param_1,uint param_2,uint param_3,undefined4 param_4,undefined4 param_5,int param_6,int param_7,undefined4 param_8,double fparam_1,double fparam_2)
{
  undefined4 uVar1;
  int iVar2;
  undefined4 extraout_r4;
  uint uVar3;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffff98;
  double in_stack_ffffffa0;
  double in_stack_ffffffa8;
  double in_stack_ffffffb0;
  double in_stack_ffffffb8;
  
  uVar3 = param_3;
  iVar2 = _gleGetMapData(param_1);
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((((param_2 < 0x10) && (fparam_1 != fparam_2)) && (0 < param_7)) && (param_7 < 0xb)) {
      if (param_3 == 2) {
        if (1 < param_6) {
          ((double (*)())_gleMap1VertexAttrib2fLoad)(param_1,extraout_r4,uVar3,param_6,param_7,param_8,
                     iVar2 + param_2 * 0xb0 + 0x2ca8,fparam_1,fparam_2,in_f3,in_f4,in_f5,in_f6,in_f7
                     ,in_f8,in_stack_ffffff98,in_stack_ffffffa0,in_stack_ffffffa8,in_stack_ffffffb0,
                     in_stack_ffffffb8);
          goto LAB_0006f4c8;
        }
      }
      else if (param_3 < 3) {
        if ((param_3 == 1) && (0 < param_6)) {
          ((double (*)())_gleMap1VertexAttrib1fLoad)(param_1,extraout_r4,uVar3,param_6,param_7,param_8,
                     iVar2 + param_2 * 0xb0 + 0x2ca8,fparam_1,fparam_2,in_f3,in_f4,in_f5,in_f6,in_f7
                     ,in_f8,in_stack_ffffff98,in_stack_ffffffa0,in_stack_ffffffa8,in_stack_ffffffb0,
                     in_stack_ffffffb8);
          goto LAB_0006f4c8;
        }
      }
      else if (param_3 == 3) {
        if (2 < param_6) {
          ((double (*)())_gleMap1VertexAttrib3fLoad)(param_1,extraout_r4,uVar3,param_6,param_7,param_8,
                     iVar2 + param_2 * 0xb0 + 0x2ca8,fparam_1,fparam_2,in_f3,in_f4,in_f5,in_f6,in_f7
                     ,in_f8,in_stack_ffffff98,in_stack_ffffffa0,in_stack_ffffffa8,in_stack_ffffffb0,
                     in_stack_ffffffb8);
          goto LAB_0006f4c8;
        }
      }
      else if ((param_3 == 4) && (3 < param_6)) {
        ((double (*)())_gleMap1VertexAttrib4fLoad)(param_1,extraout_r4,uVar3,param_6,param_7,param_8,iVar2 + param_2 * 0xb0 + 0x2ca8
                   ,fparam_1,fparam_2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_ffffff98,
                   in_stack_ffffffa0,in_stack_ffffffa8,in_stack_ffffffb0,in_stack_ffffffb8);
LAB_0006f4c8:
        ((code **)_gleSelectVertexAddMaterialFunc)[param_2 + iVar2] = SUB41(param_3,0);
        return;
      }
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x501;
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

/* _glMapVertexAttrib1fARB_CompExec @ 0x6f508 (120 bytes) */
void _glMapVertexAttrib1fARB_CompExec(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,double fparam_1,double fparam_2)
{
  ((double (*)())_glMapVertexAttrib1fARB_Comp)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,fparam_1,fparam_2);
  ((void (*)())_glMapVertexAttrib1fARB_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,fparam_1,fparam_2);
  return;
}

/* _glMapVertexAttrib1dARB_Comp @ 0x6f580 (448 bytes) */
double _glMapVertexAttrib1dARB_Comp(int param_1,undefined4 param_2,uint param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,double fparam_1,double fparam_2)
{
  undefined4 *puVar1;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  int iVar2;
  double extraout_f1;
  double dVar3;
  double extraout_f1_00;
  double extraout_f1_01;
  double extraout_f1_02;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffff88;
  double in_stack_ffffff90;
  double in_stack_ffffff98;
  double in_stack_ffffffa0;
  double in_stack_ffffffa8;
  
  if (param_3 == 2) {
    iVar2 = (10 - (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38))) * -8 + 100;
    puVar1 = (undefined4 *)
             _gleAddListItem(param_1,PTR__glMap1VertexAttrib2ARB_ListExec_00110168,iVar2);
    if (puVar1 == (undefined4 *)0x0) {
      return extraout_f1_00;
    }
    dVar3 = (double)((double (*)())_gleMap1VertexAttrib2dLoad)(param_1,extraout_r4_00,iVar2,param_4,param_5,param_8,
                               (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0x3c)),fparam_1,fparam_2,in_f3,in_f4,
                               in_f5,in_f6,in_f7,in_f8,in_stack_ffffff88,in_stack_ffffff90,
                               in_stack_ffffff98,in_stack_ffffffa0,in_stack_ffffffa8);
  }
  else if (param_3 < 3) {
    if (param_3 != 1) {
LAB_0006f710:
      if (*(int *)(param_1 + 0x7574) != 0) {
        return fparam_1;
      }
      *(undefined4 *)(param_1 + 0x7574) = 0x501;
      return fparam_1;
    }
    iVar2 = (10 - (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38))) * -4 + 0x3c;
    puVar1 = (undefined4 *)
             _gleAddListItem(param_1,PTR__glMap1VertexAttrib1ARB_ListExec_0011016c,iVar2);
    if (puVar1 == (undefined4 *)0x0) {
      return extraout_f1;
    }
    dVar3 = (double)((double (*)())_gleMap1VertexAttrib1dLoad)(param_1,extraout_r4,iVar2,param_4,param_5,param_8,(*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),
                               (*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0x3c)),fparam_1,fparam_2,in_f3,in_f4,in_f5,in_f6,in_f7,
                               in_f8,in_stack_ffffff88,in_stack_ffffff90,in_stack_ffffff98,
                               in_stack_ffffffa0,in_stack_ffffffa8);
  }
  else if (param_3 == 3) {
    iVar2 = (10 - (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38))) * -0xc + 0x8c;
    puVar1 = (undefined4 *)
             _gleAddListItem(param_1,PTR__glMap1VertexAttrib3ARB_ListExec_00110164,iVar2);
    if (puVar1 == (undefined4 *)0x0) {
      return extraout_f1_01;
    }
    dVar3 = (double)((double (*)())_gleMap1VertexAttrib3dLoad)(param_1,extraout_r4_01,iVar2,param_4,param_5,param_8,
                               (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0x3c)),fparam_1,fparam_2,in_f3,in_f4,
                               in_f5,in_f6,in_f7,in_f8,in_stack_ffffff88,in_stack_ffffff90,
                               in_stack_ffffff98,in_stack_ffffffa0,in_stack_ffffffa8);
  }
  else {
    if (param_3 != 4) goto LAB_0006f710;
    iVar2 = (10 - (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38))) * -0x10 + 0xb4;
    puVar1 = (undefined4 *)
             _gleAddListItem(param_1,PTR__glMap1VertexAttrib4ARB_ListExec_00110160,iVar2);
    if (puVar1 == (undefined4 *)0x0) {
      return extraout_f1_02;
    }
    dVar3 = (double)((double (*)())_gleMap1VertexAttrib4dLoad)(param_1,extraout_r4_02,iVar2,param_4,param_5,param_8,
                               (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0x3c)),fparam_1,fparam_2,in_f3,in_f4,
                               in_f5,in_f6,in_f7,in_f8,in_stack_ffffff88,in_stack_ffffff90,
                               in_stack_ffffff98,in_stack_ffffffa0,in_stack_ffffffa8);
  }
  *puVar1 = param_2;
  return dVar3;
}

/* _glMapVertexAttrib1dARB_Exec @ 0x6f740 (460 bytes) */
void _glMapVertexAttrib1dARB_Exec(int param_1,uint param_2,uint param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,int param_8,double fparam_1,double fparam_2)
{
  undefined4 uVar1;
  int iVar2;
  undefined4 extraout_r4;
  uint uVar3;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffff88;
  double in_stack_ffffff90;
  double in_stack_ffffff98;
  double in_stack_ffffffa0;
  double in_stack_ffffffa8;
  
  uVar3 = param_3;
  iVar2 = _gleGetMapData(param_1);
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((((param_2 < 0x10) && (fparam_1 != fparam_2)) && (0 < (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)))) &&
       ((*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)) < 0xb)) {
      if (param_3 == 2) {
        if (1 < param_8) {
          ((double (*)())_gleMap1VertexAttrib2dLoad)(param_1,extraout_r4,uVar3,param_4,param_5,param_8,(*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),
                     (*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0x3c)),fparam_1,fparam_2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                     in_stack_ffffff88,in_stack_ffffff90,in_stack_ffffff98,in_stack_ffffffa0,
                     in_stack_ffffffa8);
          goto LAB_0006f8cc;
        }
      }
      else if (param_3 < 3) {
        if ((param_3 == 1) && (0 < param_8)) {
          ((double (*)())_gleMap1VertexAttrib1dLoad)(param_1,extraout_r4,uVar3,param_4,param_5,param_8,(*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),
                     (*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0x3c)),fparam_1,fparam_2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                     in_stack_ffffff88,in_stack_ffffff90,in_stack_ffffff98,in_stack_ffffffa0,
                     in_stack_ffffffa8);
          goto LAB_0006f8cc;
        }
      }
      else if (param_3 == 3) {
        if (2 < param_8) {
          ((double (*)())_gleMap1VertexAttrib3dLoad)(param_1,extraout_r4,uVar3,param_4,param_5,param_8,(*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),
                     (*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0x3c)),fparam_1,fparam_2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                     in_stack_ffffff88,in_stack_ffffff90,in_stack_ffffff98,in_stack_ffffffa0,
                     in_stack_ffffffa8);
          goto LAB_0006f8cc;
        }
      }
      else if ((param_3 == 4) && (3 < param_8)) {
        ((double (*)())_gleMap1VertexAttrib4dLoad)(param_1,extraout_r4,uVar3,param_4,param_5,param_8,(*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),
                   (*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0x3c)),fparam_1,fparam_2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                   in_stack_ffffff88,in_stack_ffffff90,in_stack_ffffff98,in_stack_ffffffa0,
                   in_stack_ffffffa8);
LAB_0006f8cc:
        ((code **)_gleSelectVertexAddMaterialFunc)[param_2 + iVar2] = SUB41(param_3,0);
        return;
      }
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x501;
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

/* _glMapVertexAttrib1dARB_CompExec @ 0x6f90c (128 bytes) */
void _glMapVertexAttrib1dARB_CompExec(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,double fparam_1,double fparam_2)
{
  ((double (*)())_glMapVertexAttrib1dARB_Comp)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,fparam_1,fparam_2);
  ((void (*)())_glMapVertexAttrib1dARB_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,fparam_1,fparam_2);
  return;
}

/* _glMap2Vertex3_ListExec @ 0x6f98c (180 bytes) */
int _glMap2Vertex3_ListExec(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar8 = _gleGetMapData(param_1);
  iVar7 = param_2[1];
  *(int *)(iVar8 + 0x478) = *param_2;
  *(int *)(iVar8 + 0x47c) = iVar7;
  iVar9 = *param_2;
  iVar6 = param_2[1];
  iVar7 = param_2[3];
  iVar2 = param_2[6];
  iVar3 = param_2[4];
  iVar4 = param_2[5];
  iVar5 = param_2[7];
  *(int *)(iVar8 + 0x480) = param_2[2];
  *(int *)(iVar8 + 0x484) = iVar7;
  *(int *)(iVar8 + 0x490) = iVar2;
  *(int *)(iVar8 + 0x488) = iVar3;
  *(int *)(iVar8 + 0x48c) = iVar4;
  *(int *)(iVar8 + 0x494) = iVar5;
  for (iVar7 = iVar9 * iVar6; iVar7 != 0; iVar7 = iVar7 + -1) {
    piVar1 = param_2 + 8;
    iVar2 = param_2[9];
    iVar3 = param_2[10];
    param_2 = param_2 + 3;
    *(int *)(iVar8 + 0x498) = *piVar1;
    *(int *)(iVar8 + 0x49c) = iVar2;
    *(int *)(iVar8 + 0x4a0) = iVar3;
    iVar8 = iVar8 + 0xc;
  }
  return (100 - iVar9 * iVar6) * -0xc + 0x4d0;
}

/* _glMap2Vertex4_ListExec @ 0x6fa40 (200 bytes) */
int _glMap2Vertex4_ListExec(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar6 = _gleGetMapData(param_1);
  iVar5 = param_2[1];
  *(int *)(iVar6 + 0x948) = *param_2;
  *(int *)(iVar6 + 0x94c) = iVar5;
  iVar7 = *param_2;
  iVar4 = param_2[1];
  iVar5 = param_2[3];
  iVar9 = param_2[6];
  iVar1 = param_2[4];
  iVar2 = param_2[5];
  iVar3 = param_2[7];
  *(int *)(iVar6 + 0x950) = param_2[2];
  *(int *)(iVar6 + 0x954) = iVar5;
  *(int *)(iVar6 + 0x960) = iVar9;
  *(int *)(iVar6 + 0x958) = iVar1;
  *(int *)(iVar6 + 0x95c) = iVar2;
  *(int *)(iVar6 + 0x964) = iVar3;
  iVar5 = 0;
  for (iVar9 = iVar7 * iVar4; iVar9 != 0; iVar9 = iVar9 + -1) {
    iVar8 = iVar5 * 0x10 + iVar6;
    iVar1 = param_2[iVar5 * 4 + 8];
    iVar2 = param_2[iVar5 * 4 + 9];
    iVar3 = param_2[iVar5 * 4 + 10];
    *(int *)(iVar8 + 0x974) = param_2[iVar5 * 4 + 0xb];
    *(int *)(iVar8 + 0x968) = iVar1;
    *(int *)(iVar8 + 0x96c) = iVar2;
    *(int *)(iVar8 + 0x970) = iVar3;
    iVar5 = iVar5 + 1;
  }
  return (100 - iVar7 * iVar4) * -0x10 + 0x660;
}

/* _glMap2Color_ListExec @ 0x6fb08 (200 bytes) */
int _glMap2Color_ListExec(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar6 = _gleGetMapData(param_1);
  iVar5 = param_2[1];
  *(int *)(iVar6 + 0x1478) = *param_2;
  *(int *)(iVar6 + 0x147c) = iVar5;
  iVar7 = *param_2;
  iVar4 = param_2[1];
  iVar5 = param_2[3];
  iVar9 = param_2[6];
  iVar1 = param_2[4];
  iVar2 = param_2[5];
  iVar3 = param_2[7];
  *(int *)(iVar6 + 0x1480) = param_2[2];
  *(int *)(iVar6 + 0x1484) = iVar5;
  *(int *)(iVar6 + 0x1490) = iVar9;
  *(int *)(iVar6 + 0x1488) = iVar1;
  *(int *)(iVar6 + 0x148c) = iVar2;
  *(int *)(iVar6 + 0x1494) = iVar3;
  iVar5 = 0;
  for (iVar9 = iVar7 * iVar4; iVar9 != 0; iVar9 = iVar9 + -1) {
    iVar8 = iVar5 * 0x10 + iVar6;
    iVar1 = param_2[iVar5 * 4 + 8];
    iVar2 = param_2[iVar5 * 4 + 9];
    iVar3 = param_2[iVar5 * 4 + 10];
    *(int *)(iVar8 + 0x14a4) = param_2[iVar5 * 4 + 0xb];
    *(int *)(iVar8 + 0x1498) = iVar1;
    *(int *)(iVar8 + 0x149c) = iVar2;
    *(int *)(iVar8 + 0x14a0) = iVar3;
    iVar5 = iVar5 + 1;
  }
  return (100 - iVar7 * iVar4) * -0x10 + 0x660;
}

/* _glMap2Index_ListExec @ 0x6fbd0 (168 bytes) */
int _glMap2Index_ListExec(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  
  iVar6 = _gleGetMapData(param_1);
  iVar5 = param_2[1];
  *(int *)(iVar6 + 0x1ad8) = *param_2;
  *(int *)(iVar6 + 0x1adc) = iVar5;
  iVar9 = *param_2 * param_2[1];
  iVar5 = param_2[3];
  iVar1 = param_2[6];
  iVar2 = param_2[4];
  iVar3 = param_2[5];
  iVar4 = param_2[7];
  *(int *)(iVar6 + 0x1ae0) = param_2[2];
  *(int *)(iVar6 + 0x1ae4) = iVar5;
  *(int *)(iVar6 + 0x1af0) = iVar1;
  *(int *)(iVar6 + 0x1ae8) = iVar2;
  *(int *)(iVar6 + 0x1aec) = iVar3;
  *(int *)(iVar6 + 0x1af4) = iVar4;
  if (iVar9 != 0) {
    piVar7 = (int *)(iVar6 + 0x1af8);
    piVar8 = param_2 + 8;
    iVar5 = iVar9;
    do {
      iVar1 = *piVar8;
      piVar8 = piVar8 + 1;
      *piVar7 = iVar1;
      piVar7 = piVar7 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  return (100 - iVar9) * -4 + 0x1b0;
}

/* _glMap2Normal_ListExec @ 0x6fc78 (180 bytes) */
int _glMap2Normal_ListExec(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar8 = _gleGetMapData(param_1);
  iVar7 = param_2[1];
  *(int *)(iVar8 + 0xfa8) = *param_2;
  *(int *)(iVar8 + 0xfac) = iVar7;
  iVar9 = *param_2;
  iVar6 = param_2[1];
  iVar7 = param_2[3];
  iVar2 = param_2[6];
  iVar3 = param_2[4];
  iVar4 = param_2[5];
  iVar5 = param_2[7];
  *(int *)(iVar8 + 0xfb0) = param_2[2];
  *(int *)(iVar8 + 0xfb4) = iVar7;
  *(int *)(iVar8 + 0xfc0) = iVar2;
  *(int *)(iVar8 + 0xfb8) = iVar3;
  *(int *)(iVar8 + 0xfbc) = iVar4;
  *(int *)(iVar8 + 0xfc4) = iVar5;
  for (iVar7 = iVar9 * iVar6; iVar7 != 0; iVar7 = iVar7 + -1) {
    piVar1 = param_2 + 8;
    iVar2 = param_2[9];
    iVar3 = param_2[10];
    param_2 = param_2 + 3;
    *(int *)(iVar8 + 0xfc8) = *piVar1;
    *(int *)(iVar8 + 0xfcc) = iVar2;
    *(int *)(iVar8 + 0xfd0) = iVar3;
    iVar8 = iVar8 + 0xc;
  }
  return (100 - iVar9 * iVar6) * -0xc + 0x4d0;
}

/* _glMap2Texture1_ListExec @ 0x6fd2c (168 bytes) */
int _glMap2Texture1_ListExec(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  
  iVar6 = _gleGetMapData(param_1);
  iVar5 = param_2[1];
  *(int *)(iVar6 + 0x1c88) = *param_2;
  *(int *)(iVar6 + 0x1c8c) = iVar5;
  iVar9 = *param_2 * param_2[1];
  iVar5 = param_2[3];
  iVar1 = param_2[6];
  iVar2 = param_2[4];
  iVar3 = param_2[5];
  iVar4 = param_2[7];
  *(int *)(iVar6 + 0x1c90) = param_2[2];
  *(int *)(iVar6 + 0x1c94) = iVar5;
  *(int *)(iVar6 + 0x1ca0) = iVar1;
  *(int *)(iVar6 + 0x1c98) = iVar2;
  *(int *)(iVar6 + 0x1c9c) = iVar3;
  *(int *)(iVar6 + 0x1ca4) = iVar4;
  if (iVar9 != 0) {
    piVar7 = (int *)(iVar6 + 0x1ca8);
    piVar8 = param_2 + 8;
    iVar5 = iVar9;
    do {
      iVar1 = *piVar8;
      piVar8 = piVar8 + 1;
      *piVar7 = iVar1;
      piVar7 = piVar7 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  return (100 - iVar9) * -4 + 0x1b0;
}

/* _glMap2Texture2_ListExec @ 0x6fdd4 (184 bytes) */
int _glMap2Texture2_ListExec(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar6 = _gleGetMapData(param_1);
  iVar4 = param_2[1];
  *(int *)(iVar6 + 0x1e38) = *param_2;
  *(int *)(iVar6 + 0x1e3c) = iVar4;
  iVar7 = *param_2;
  iVar3 = param_2[1];
  iVar4 = param_2[3];
  iVar8 = param_2[6];
  iVar1 = param_2[4];
  iVar5 = param_2[5];
  iVar2 = param_2[7];
  *(int *)(iVar6 + 0x1e40) = param_2[2];
  *(int *)(iVar6 + 0x1e44) = iVar4;
  *(int *)(iVar6 + 0x1e50) = iVar8;
  *(int *)(iVar6 + 0x1e48) = iVar1;
  *(int *)(iVar6 + 0x1e4c) = iVar5;
  *(int *)(iVar6 + 0x1e54) = iVar2;
  iVar4 = 0;
  for (iVar8 = iVar7 * iVar3; iVar8 != 0; iVar8 = iVar8 + -1) {
    iVar5 = iVar4 * 8 + iVar6;
    iVar1 = param_2[iVar4 * 2 + 8];
    *(int *)(iVar5 + 0x1e5c) = param_2[iVar4 * 2 + 9];
    *(int *)(iVar5 + 0x1e58) = iVar1;
    iVar4 = iVar4 + 1;
  }
  return (100 - iVar7 * iVar3) * -8 + 0x340;
}

/* _glMap2Texture3_ListExec @ 0x6fe8c (180 bytes) */
int _glMap2Texture3_ListExec(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar8 = _gleGetMapData(param_1);
  iVar7 = param_2[1];
  *(int *)(iVar8 + 0x2178) = *param_2;
  *(int *)(iVar8 + 0x217c) = iVar7;
  iVar9 = *param_2;
  iVar6 = param_2[1];
  iVar7 = param_2[3];
  iVar2 = param_2[6];
  iVar3 = param_2[4];
  iVar4 = param_2[5];
  iVar5 = param_2[7];
  *(int *)(iVar8 + 0x2180) = param_2[2];
  *(int *)(iVar8 + 0x2184) = iVar7;
  *(int *)(iVar8 + 0x2190) = iVar2;
  *(int *)(iVar8 + 0x2188) = iVar3;
  *(int *)(iVar8 + 0x218c) = iVar4;
  *(int *)(iVar8 + 0x2194) = iVar5;
  for (iVar7 = iVar9 * iVar6; iVar7 != 0; iVar7 = iVar7 + -1) {
    piVar1 = param_2 + 8;
    iVar2 = param_2[9];
    iVar3 = param_2[10];
    param_2 = param_2 + 3;
    *(int *)(iVar8 + 0x2198) = *piVar1;
    *(int *)(iVar8 + 0x219c) = iVar2;
    *(int *)(iVar8 + 0x21a0) = iVar3;
    iVar8 = iVar8 + 0xc;
  }
  return (100 - iVar9 * iVar6) * -0xc + 0x4d0;
}

/* _glMap2Texture4_ListExec @ 0x6ff40 (200 bytes) */
int _glMap2Texture4_ListExec(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar6 = _gleGetMapData(param_1);
  iVar5 = param_2[1];
  *(int *)(iVar6 + 0x2648) = *param_2;
  *(int *)(iVar6 + 0x264c) = iVar5;
  iVar7 = *param_2;
  iVar4 = param_2[1];
  iVar5 = param_2[3];
  iVar9 = param_2[6];
  iVar1 = param_2[4];
  iVar2 = param_2[5];
  iVar3 = param_2[7];
  *(int *)(iVar6 + 0x2650) = param_2[2];
  *(int *)(iVar6 + 0x2654) = iVar5;
  *(int *)(iVar6 + 0x2660) = iVar9;
  *(int *)(iVar6 + 0x2658) = iVar1;
  *(int *)(iVar6 + 0x265c) = iVar2;
  *(int *)(iVar6 + 0x2664) = iVar3;
  iVar5 = 0;
  for (iVar9 = iVar7 * iVar4; iVar9 != 0; iVar9 = iVar9 + -1) {
    iVar8 = iVar5 * 0x10 + iVar6;
    iVar1 = param_2[iVar5 * 4 + 8];
    iVar2 = param_2[iVar5 * 4 + 9];
    iVar3 = param_2[iVar5 * 4 + 10];
    *(int *)(iVar8 + 0x2674) = param_2[iVar5 * 4 + 0xb];
    *(int *)(iVar8 + 0x2668) = iVar1;
    *(int *)(iVar8 + 0x266c) = iVar2;
    *(int *)(iVar8 + 0x2670) = iVar3;
    iVar5 = iVar5 + 1;
  }
  return (100 - iVar7 * iVar4) * -0x10 + 0x660;
}

/* _glMap2VertexAttrib1ARB_ListExec @ 0x70008 (200 bytes) */
int _glMap2VertexAttrib1ARB_ListExec(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar4 = _gleGetMapData(param_1);
  iVar9 = *param_2;
  iVar8 = param_2[1];
  iVar7 = param_2[2];
  iVar6 = iVar4 + iVar9 * 0x660;
  *(int *)(iVar6 + 0x37a8) = iVar8;
  *(int *)(iVar6 + 0x37ac) = iVar7;
  iVar7 = iVar7 * iVar8;
  *(undefined1 *)(iVar9 + iVar4 + 0x9db8) = 1;
  iVar4 = param_2[3];
  iVar8 = param_2[4];
  iVar9 = param_2[7];
  iVar1 = param_2[5];
  iVar2 = param_2[6];
  *(int *)(iVar6 + 0x37c4) = param_2[8];
  *(int *)(iVar6 + 0x37b0) = iVar4;
  *(int *)(iVar6 + 0x37b4) = iVar8;
  *(int *)(iVar6 + 0x37c0) = iVar9;
  *(int *)(iVar6 + 0x37b8) = iVar1;
  *(int *)(iVar6 + 0x37bc) = iVar2;
  if (iVar7 != 0) {
    piVar5 = (int *)(iVar6 + 0x37c8);
    piVar3 = param_2 + 9;
    iVar4 = iVar7;
    do {
      iVar8 = *piVar3;
      piVar3 = piVar3 + 1;
      *piVar5 = iVar8;
      piVar5 = piVar5 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return (100 - iVar7) * -4 + 0x1b4;
}

/* _glMap2VertexAttrib2ARB_ListExec @ 0x700d0 (208 bytes) */
int _glMap2VertexAttrib2ARB_ListExec(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  iVar6 = _gleGetMapData(param_1);
  iVar5 = *param_2;
  piVar8 = param_2 + 1;
  iVar11 = param_2[1];
  iVar7 = param_2[2];
  iVar9 = iVar6 + iVar5 * 0x660;
  iVar10 = iVar9 + 0x37a8;
  *(int *)(iVar9 + 0x37a8) = iVar11;
  *(int *)(iVar9 + 0x37ac) = iVar7;
  *(undefined1 *)(iVar5 + iVar6 + 0x9db8) = 2;
  iVar5 = param_2[4];
  iVar6 = param_2[7];
  iVar2 = param_2[5];
  iVar3 = param_2[6];
  iVar4 = param_2[8];
  *(int *)(iVar9 + 0x37b0) = param_2[3];
  *(int *)(iVar9 + 0x37b4) = iVar5;
  *(int *)(iVar9 + 0x37c0) = iVar6;
  *(int *)(iVar9 + 0x37b8) = iVar2;
  *(int *)(iVar9 + 0x37bc) = iVar3;
  *(int *)(iVar9 + 0x37c4) = iVar4;
  iVar7 = iVar7 * iVar11;
  for (iVar5 = iVar7; iVar5 != 0; iVar5 = iVar5 + -1) {
    piVar1 = piVar8 + 8;
    iVar6 = piVar8[9];
    piVar8 = piVar8 + 2;
    *(int *)(iVar10 + 0x20) = *piVar1;
    *(int *)(iVar10 + 0x24) = iVar6;
    iVar10 = iVar10 + 8;
  }
  return (100 - iVar7) * -8 + 0x344;
}

/* _glMap2VertexAttrib3ARB_ListExec @ 0x701a0 (216 bytes) */
int _glMap2VertexAttrib3ARB_ListExec(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  iVar5 = _gleGetMapData(param_1);
  iVar4 = *param_2;
  piVar7 = param_2 + 1;
  iVar11 = param_2[1];
  iVar6 = param_2[2];
  iVar8 = iVar5 + iVar4 * 0x660;
  iVar10 = iVar8 + 0x37a8;
  *(int *)(iVar8 + 0x37a8) = iVar11;
  *(int *)(iVar8 + 0x37ac) = iVar6;
  *(undefined1 *)(iVar4 + iVar5 + 0x9db8) = 3;
  iVar4 = param_2[4];
  iVar5 = param_2[7];
  iVar9 = param_2[5];
  iVar2 = param_2[6];
  iVar3 = param_2[8];
  *(int *)(iVar8 + 0x37b0) = param_2[3];
  *(int *)(iVar8 + 0x37b4) = iVar4;
  *(int *)(iVar8 + 0x37c0) = iVar5;
  *(int *)(iVar8 + 0x37b8) = iVar9;
  *(int *)(iVar8 + 0x37bc) = iVar2;
  *(int *)(iVar8 + 0x37c4) = iVar3;
  iVar6 = iVar6 * iVar11;
  for (iVar4 = iVar6; iVar4 != 0; iVar4 = iVar4 + -1) {
    piVar1 = piVar7 + 8;
    iVar5 = piVar7[9];
    iVar9 = piVar7[10];
    piVar7 = piVar7 + 3;
    *(int *)(iVar10 + 0x20) = *piVar1;
    *(int *)(iVar10 + 0x24) = iVar5;
    *(int *)(iVar10 + 0x28) = iVar9;
    iVar10 = iVar10 + 0xc;
  }
  return (100 - iVar6) * -0xc + 0x4d4;
}

/* _glMap2VertexAttrib4ARB_ListExec @ 0x70278 (236 bytes) */
int _glMap2VertexAttrib4ARB_ListExec(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar2 = _gleGetMapData(param_1);
  iVar6 = *param_2;
  iVar4 = param_2[1];
  iVar3 = param_2[2];
  iVar1 = iVar2 + iVar6 * 0x660;
  *(int *)(iVar1 + 0x37a8) = iVar4;
  *(int *)(iVar1 + 0x37ac) = iVar3;
  *(undefined1 *)(iVar6 + iVar2 + 0x9db8) = 4;
  iVar2 = param_2[4];
  iVar6 = param_2[7];
  iVar5 = param_2[5];
  iVar7 = param_2[6];
  iVar8 = param_2[8];
  *(int *)(iVar1 + 0x37b0) = param_2[3];
  *(int *)(iVar1 + 0x37b4) = iVar2;
  *(int *)(iVar1 + 0x37c0) = iVar6;
  *(int *)(iVar1 + 0x37b8) = iVar5;
  *(int *)(iVar1 + 0x37bc) = iVar7;
  *(int *)(iVar1 + 0x37c4) = iVar8;
  iVar3 = iVar3 * iVar4;
  iVar6 = 0;
  for (iVar2 = iVar3; iVar2 != 0; iVar2 = iVar2 + -1) {
    iVar4 = iVar6 * 0x10 + iVar1 + 0x37a8;
    iVar8 = param_2[iVar6 * 4 + 0xc];
    iVar7 = param_2[iVar6 * 4 + 10];
    iVar5 = param_2[iVar6 * 4 + 0xb];
    *(int *)(iVar4 + 0x20) = param_2[iVar6 * 4 + 9];
    *(int *)(iVar4 + 0x2c) = iVar8;
    *(int *)(iVar4 + 0x24) = iVar7;
    *(int *)(iVar4 + 0x28) = iVar5;
    iVar6 = iVar6 + 1;
  }
  return (100 - iVar3) * -0x10 + 0x664;
}

/* _glMap2d_Comp @ 0x70364 (1420 bytes) */
double _glMap2d_Comp(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,int param_7,int param_8,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  undefined4 uVar1;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 extraout_r4_03;
  undefined4 extraout_r4_04;
  undefined4 extraout_r4_05;
  undefined4 extraout_r4_06;
  undefined4 extraout_r4_07;
  int iVar2;
  double dVar3;
  double extraout_f1;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  int iStack00000050;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((((fparam_1 != fparam_2) && (fparam_3 != fparam_4)) && (param_8 - 1U < 10)) &&
       ((0 < (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x4c)) && ((*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x4c)) < 0xb)))) {
      switch(param_2) {
      case 0xdb0:
        if ((3 < param_7) && (3 < (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x48)))) {
          iVar2 = (100 - param_8 * (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x4c))) * -0x10 + 0x660;
          iStack00000050 = _gleAddListItem(param_1,PTR__glMap2Color_ListExec_001101bc,iVar2);
          if (iStack00000050 != 0) {
            dVar3 = (double)((double (*)())_gleMap2ColordLoad)(param_1,extraout_r4_01,iVar2,param_4,param_5,param_7,
                                               param_8,fparam_1,fparam_2,fparam_3,fparam_4,in_f5,
                                               in_f6,in_f7,in_f8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10))
                                               ,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),
                                               (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
            return dVar3;
          }
          goto LAB_00070908;
        }
        break;
      case 0xdb1:
        if ((0 < param_7) && (0 < (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x48)))) {
          iVar2 = (100 - param_8 * (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x4c))) * -4 + 0x1b0;
          iStack00000050 = _gleAddListItem(param_1,PTR__glMap2Index_ListExec_001101b8,iVar2);
          if (iStack00000050 != 0) {
            dVar3 = (double)((double (*)())_gleMap2IndexdLoad)(param_1,extraout_r4_02,iVar2,param_4,param_5,param_7,
                                               param_8,fparam_1,fparam_2,fparam_3,fparam_4,in_f5,
                                               in_f6,in_f7,in_f8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10))
                                               ,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),
                                               (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
            return dVar3;
          }
          goto LAB_00070908;
        }
        break;
      case 0xdb2:
        if ((2 < param_7) && (2 < (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x48)))) {
          iVar2 = (100 - param_8 * (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x4c))) * -0xc + 0x4d0;
          iStack00000050 = _gleAddListItem(param_1,PTR__glMap2Normal_ListExec_001101b4,iVar2);
          if (iStack00000050 != 0) {
            dVar3 = (double)((double (*)())_gleMap2NormaldLoad)(param_1,extraout_r4_03,iVar2,param_4,param_5,param_7
                                                ,param_8,fparam_1,fparam_2,fparam_3,fparam_4,in_f5,
                                                in_f6,in_f7,in_f8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),
                                                (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),
                                                (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
            return dVar3;
          }
          goto LAB_00070908;
        }
        break;
      case 0xdb3:
        if ((0 < param_7) && (0 < (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x48)))) {
          iVar2 = (100 - param_8 * (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x4c))) * -4 + 0x1b0;
          iStack00000050 = _gleAddListItem(param_1,PTR__glMap2Texture1_ListExec_001101b0,iVar2);
          if (iStack00000050 != 0) {
            dVar3 = (double)((double (*)())_gleMap2Texture1dLoad)(param_1,extraout_r4_04,iVar2,param_4,param_5,param_7,param_8,
                                       fparam_1,fparam_2,fparam_3,fparam_4,in_f5,in_f6,in_f7,in_f8,
                                       (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),
                                       (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
            return dVar3;
          }
          goto LAB_00070908;
        }
        break;
      case 0xdb4:
        if ((1 < param_7) && (1 < (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x48)))) {
          iVar2 = (100 - param_8 * (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x4c))) * -8 + 0x340;
          iStack00000050 = _gleAddListItem(param_1,PTR__glMap2Texture2_ListExec_001101ac,iVar2);
          if (iStack00000050 != 0) {
            dVar3 = (double)((double (*)())_gleMap2Texture2dLoad)(param_1,extraout_r4_05,iVar2,param_4,param_5,param_7,param_8,
                                       fparam_1,fparam_2,fparam_3,fparam_4,in_f5,in_f6,in_f7,in_f8,
                                       (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),
                                       (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
            return dVar3;
          }
          goto LAB_00070908;
        }
        break;
      case 0xdb5:
        if ((2 < param_7) && (2 < (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x48)))) {
          iVar2 = (100 - param_8 * (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x4c))) * -0xc + 0x4d0;
          iStack00000050 = _gleAddListItem(param_1,PTR__glMap2Texture3_ListExec_001101a8,iVar2);
          if (iStack00000050 != 0) {
            dVar3 = (double)((double (*)())_gleMap2Texture3dLoad)(param_1,extraout_r4_06,iVar2,param_4,param_5,param_7,param_8,
                                       fparam_1,fparam_2,fparam_3,fparam_4,in_f5,in_f6,in_f7,in_f8,
                                       (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),
                                       (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
            return dVar3;
          }
          goto LAB_00070908;
        }
        break;
      case 0xdb6:
        if ((3 < param_7) && (3 < (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x48)))) {
          iVar2 = (100 - param_8 * (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x4c))) * -0x10 + 0x660;
          iStack00000050 = _gleAddListItem(param_1,PTR__glMap2Texture4_ListExec_001101a4,iVar2);
          if (iStack00000050 != 0) {
            dVar3 = (double)((double (*)())_gleMap2Texture4dLoad)(param_1,extraout_r4_07,iVar2,param_4,param_5,param_7,param_8,
                                       fparam_1,fparam_2,fparam_3,fparam_4,in_f5,in_f6,in_f7,in_f8,
                                       (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),
                                       (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
            return dVar3;
          }
          goto LAB_00070908;
        }
        break;
      case 0xdb7:
        if ((2 < param_7) && (2 < (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x48)))) {
          iVar2 = (100 - param_8 * (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x4c))) * -0xc + 0x4d0;
          iStack00000050 = _gleAddListItem(param_1,PTR__glMap2Vertex3_ListExec_001101c4,iVar2);
          if (iStack00000050 != 0) {
            dVar3 = (double)((double (*)())_gleMap2Vertex3dLoad)(param_1,extraout_r4,iVar2,param_4,param_5,param_7,param_8,
                                       fparam_1,fparam_2,fparam_3,fparam_4,in_f5,in_f6,in_f7,in_f8,
                                       (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),
                                       (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
            return dVar3;
          }
          goto LAB_00070908;
        }
        break;
      case 0xdb8:
        if ((3 < param_7) && (3 < (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x48)))) {
          iVar2 = (100 - param_8 * (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x4c))) * -0x10 + 0x660;
          iStack00000050 = _gleAddListItem(param_1,PTR__glMap2Vertex4_ListExec_001101c0,iVar2);
          if (iStack00000050 != 0) {
            dVar3 = (double)((double (*)())_gleMap2Vertex4dLoad)(param_1,extraout_r4_00,iVar2,param_4,param_5,param_7,param_8,
                                       fparam_1,fparam_2,fparam_3,fparam_4,in_f5,in_f6,in_f7,in_f8,
                                       (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),
                                       (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
            return dVar3;
          }
          goto LAB_00070908;
        }
        break;
      default:
        if (*(int *)(param_1 + 0x7574) != 0) goto LAB_00070908;
        uVar1 = 0x500;
        goto LAB_00070904;
      }
    }
    if (*(int *)(param_1 + 0x7574) != 0) goto LAB_00070908;
    uVar1 = 0x501;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) goto LAB_00070908;
    uVar1 = 0x502;
  }
LAB_00070904:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
LAB_00070908:
  FUN_00008b68();
  return extraout_f1;
}

/* _glMap2d_Exec @ 0x70914 (1140 bytes) */
void _glMap2d_Exec(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,int param_7,int param_8,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  undefined4 uVar1;
  int iVar2;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  int iStack00000050;
  
  iStack00000050 = _gleGetMapData(param_1);
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((((fparam_1 != fparam_2) && (fparam_3 != fparam_4)) && (param_8 - 1U < 10)) &&
       ((0 < (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x4c)) && ((*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x4c)) < 0xb)))) {
      iVar2 = param_2 + -0xdb0;
      switch(iVar2) {
      case 0:
        if ((3 < param_7) && (3 < (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x48)))) {
          iStack00000050 = iStack00000050 + 0x1478;
          ((double (*)())_gleMap2ColordLoad)(param_1,iVar2,param_3,param_4,param_5,param_7,param_8,fparam_1,fparam_2
                             ,fparam_3,fparam_4,in_f5,in_f6,in_f7,in_f8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),
                             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28))
                            );
          return;
        }
        break;
      case 1:
        if ((0 < param_7) && (0 < (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x48)))) {
          iStack00000050 = iStack00000050 + 0x1ad8;
          ((double (*)())_gleMap2IndexdLoad)(param_1,iVar2,param_3,param_4,param_5,param_7,param_8,fparam_1,fparam_2
                             ,fparam_3,fparam_4,in_f5,in_f6,in_f7,in_f8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),
                             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28))
                            );
          return;
        }
        break;
      case 2:
        if ((2 < param_7) && (2 < (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x48)))) {
          iStack00000050 = iStack00000050 + 0xfa8;
          ((double (*)())_gleMap2NormaldLoad)(param_1,iVar2,param_3,param_4,param_5,param_7,param_8,fparam_1,
                              fparam_2,fparam_3,fparam_4,in_f5,in_f6,in_f7,in_f8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),
                              (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),
                              (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 3:
        if ((0 < param_7) && (0 < (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x48)))) {
          iStack00000050 = iStack00000050 + 0x1c88;
          ((double (*)())_gleMap2Texture1dLoad)(param_1,iVar2,param_3,param_4,param_5,param_7,param_8,fparam_1,fparam_2,
                     fparam_3,fparam_4,in_f5,in_f6,in_f7,in_f8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 4:
        if ((1 < param_7) && (1 < (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x48)))) {
          iStack00000050 = iStack00000050 + 0x1e38;
          ((double (*)())_gleMap2Texture2dLoad)(param_1,iVar2,param_3,param_4,param_5,param_7,param_8,fparam_1,fparam_2,
                     fparam_3,fparam_4,in_f5,in_f6,in_f7,in_f8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 5:
        if ((2 < param_7) && (2 < (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x48)))) {
          iStack00000050 = iStack00000050 + 0x2178;
          ((double (*)())_gleMap2Texture3dLoad)(param_1,iVar2,param_3,param_4,param_5,param_7,param_8,fparam_1,fparam_2,
                     fparam_3,fparam_4,in_f5,in_f6,in_f7,in_f8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 6:
        if ((3 < param_7) && (3 < (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x48)))) {
          iStack00000050 = iStack00000050 + 0x2648;
          ((double (*)())_gleMap2Texture4dLoad)(param_1,iVar2,param_3,param_4,param_5,param_7,param_8,fparam_1,fparam_2,
                     fparam_3,fparam_4,in_f5,in_f6,in_f7,in_f8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 7:
        if ((2 < param_7) && (2 < (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x48)))) {
          iStack00000050 = iStack00000050 + 0x478;
          ((double (*)())_gleMap2Vertex3dLoad)(param_1,iVar2,param_3,param_4,param_5,param_7,param_8,fparam_1,fparam_2,
                     fparam_3,fparam_4,in_f5,in_f6,in_f7,in_f8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 8:
        if ((3 < param_7) && (3 < (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x48)))) {
          iStack00000050 = iStack00000050 + 0x948;
          ((double (*)())_gleMap2Vertex4dLoad)(param_1,iVar2,param_3,param_4,param_5,param_7,param_8,fparam_1,fparam_2,
                     fparam_3,fparam_4,in_f5,in_f6,in_f7,in_f8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      default:
        if (*(int *)(param_1 + 0x7574) != 0) goto LAB_00070da0;
        uVar1 = 0x500;
        goto LAB_00070d9c;
      }
    }
    if (*(int *)(param_1 + 0x7574) != 0) goto LAB_00070da0;
    uVar1 = 0x501;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) goto LAB_00070da0;
    uVar1 = 0x502;
  }
LAB_00070d9c:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
LAB_00070da0:
  FUN_00008b68();
  return;
}

/* _glMap2d_CompExec @ 0x70dac (156 bytes) */
void _glMap2d_CompExec(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  ((double (*)())_glMap2d_Comp)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,fparam_1,fparam_2,
                fparam_3,fparam_4);
  ((void (*)())_glMap2d_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,fparam_1,fparam_2,
                fparam_3,fparam_4);
  return;
}

/* _glMap2f_Comp @ 0x70e48 (1420 bytes) */
undefined4 _glMap2f_Comp(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,int param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  undefined4 uVar1;
  undefined4 extraout_r3;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 extraout_r4_03;
  undefined4 extraout_r4_04;
  undefined4 extraout_r4_05;
  undefined4 extraout_r4_06;
  undefined4 extraout_r4_07;
  int iVar2;
  int iVar3;
  int iVar4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  int iStack00000040;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((((fparam_1 != fparam_2) && (fparam_3 != fparam_4)) && (param_6 - 1U < 10)) &&
       ((0 < (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x3c)) && ((*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x3c)) < 0xb)))) {
      if (8 < param_2 - 0xdb0U) {
        if (*(int *)(param_1 + 0x7574) != 0) goto LAB_000713ec;
        uVar1 = 0x500;
        goto LAB_000713e8;
      }
      iVar4 = (param_2 - 0xdb0U) * 4;
      switch(param_2) {
      case 0xdb0:
        if ((3 < param_5) && (3 < (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)))) {
          iVar2 = (100 - param_6 * (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x3c))) * -0x10 + 0x660;
          iVar3 = param_6;
          iStack00000040 = _gleAddListItem(param_1,PTR__glMap2Color_ListExec_001101bc,iVar2);
          if (iStack00000040 != 0) {
            uVar1 = ((int (*)())_gleMap2ColorfLoad)(param_1,extraout_r4_01,iVar2,param_5,param_6,iVar3,iVar4,
                                       (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),fparam_1,fparam_2,fparam_3,fparam_4,in_f5,
                                       in_f6,in_f7,in_f8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                                       (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
            return uVar1;
          }
          goto LAB_000713ec;
        }
        break;
      case 0xdb1:
        if ((0 < param_5) && (0 < (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)))) {
          iVar2 = (100 - param_6 * (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x3c))) * -4 + 0x1b0;
          iVar3 = param_6;
          iStack00000040 = _gleAddListItem(param_1,PTR__glMap2Index_ListExec_001101b8,iVar2);
          if (iStack00000040 != 0) {
            uVar1 = ((int (*)())_gleMap2IndexfLoad)(param_1,extraout_r4_02,iVar2,param_5,param_6,iVar3,iVar4,
                                       (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),fparam_1,fparam_2,fparam_3,fparam_4,in_f5,
                                       in_f6,in_f7,in_f8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                                       (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
            return uVar1;
          }
          goto LAB_000713ec;
        }
        break;
      case 0xdb2:
        if ((2 < param_5) && (2 < (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)))) {
          iVar2 = (100 - param_6 * (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x3c))) * -0xc + 0x4d0;
          iVar3 = param_6;
          iStack00000040 = _gleAddListItem(param_1,PTR__glMap2Normal_ListExec_001101b4,iVar2);
          if (iStack00000040 != 0) {
            uVar1 = ((int (*)())_gleMap2NormalfLoad)(param_1,extraout_r4_03,iVar2,param_5,param_6,iVar3,iVar4,
                                        (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),fparam_1,fparam_2,fparam_3,fparam_4,in_f5,
                                        in_f6,in_f7,in_f8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                                        (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
            return uVar1;
          }
          goto LAB_000713ec;
        }
        break;
      case 0xdb3:
        if ((0 < param_5) && (0 < (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)))) {
          iVar2 = (100 - param_6 * (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x3c))) * -4 + 0x1b0;
          iVar3 = param_6;
          iStack00000040 = _gleAddListItem(param_1,PTR__glMap2Texture1_ListExec_001101b0,iVar2);
          if (iStack00000040 != 0) {
            uVar1 = ((int (*)())_gleMap2Texture1fLoad)(param_1,extraout_r4_04,iVar2,param_5,param_6,iVar3,iVar4,
                               (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),fparam_1,fparam_2,fparam_3,fparam_4,in_f5,in_f6,
                               in_f7,in_f8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),
                               (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
            return uVar1;
          }
          goto LAB_000713ec;
        }
        break;
      case 0xdb4:
        if ((1 < param_5) && (1 < (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)))) {
          iVar2 = (100 - param_6 * (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x3c))) * -8 + 0x340;
          iVar3 = param_6;
          iStack00000040 = _gleAddListItem(param_1,PTR__glMap2Texture2_ListExec_001101ac,iVar2);
          if (iStack00000040 != 0) {
            uVar1 = ((int (*)())_gleMap2Texture2fLoad)(param_1,extraout_r4_05,iVar2,param_5,param_6,iVar3,iVar4,
                               (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),fparam_1,fparam_2,fparam_3,fparam_4,in_f5,in_f6,
                               in_f7,in_f8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),
                               (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
            return uVar1;
          }
          goto LAB_000713ec;
        }
        break;
      case 0xdb5:
        if ((2 < param_5) && (2 < (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)))) {
          iVar2 = (100 - param_6 * (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x3c))) * -0xc + 0x4d0;
          iVar3 = param_6;
          iStack00000040 = _gleAddListItem(param_1,PTR__glMap2Texture3_ListExec_001101a8,iVar2);
          if (iStack00000040 != 0) {
            uVar1 = ((int (*)())_gleMap2Texture3fLoad)(param_1,extraout_r4_06,iVar2,param_5,param_6,iVar3,iVar4,
                               (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),fparam_1,fparam_2,fparam_3,fparam_4,in_f5,in_f6,
                               in_f7,in_f8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),
                               (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
            return uVar1;
          }
          goto LAB_000713ec;
        }
        break;
      case 0xdb6:
        if ((3 < param_5) && (3 < (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)))) {
          iVar2 = (100 - param_6 * (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x3c))) * -0x10 + 0x660;
          iVar3 = param_6;
          iStack00000040 = _gleAddListItem(param_1,PTR__glMap2Texture4_ListExec_001101a4,iVar2);
          if (iStack00000040 != 0) {
            uVar1 = ((int (*)())_gleMap2Texture4fLoad)(param_1,extraout_r4_07,iVar2,param_5,param_6,iVar3,iVar4,
                               (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),fparam_1,fparam_2,fparam_3,fparam_4,in_f5,in_f6,
                               in_f7,in_f8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),
                               (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
            return uVar1;
          }
          goto LAB_000713ec;
        }
        break;
      case 0xdb7:
        if ((2 < param_5) && (2 < (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)))) {
          iVar2 = (100 - param_6 * (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x3c))) * -0xc + 0x4d0;
          iVar3 = param_6;
          iStack00000040 = _gleAddListItem(param_1,PTR__glMap2Vertex3_ListExec_001101c4,iVar2);
          if (iStack00000040 != 0) {
            uVar1 = ((int (*)())_gleMap2Vertex3fLoad)(param_1,extraout_r4,iVar2,param_5,param_6,iVar3,iVar4,
                               (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),fparam_1,fparam_2,fparam_3,fparam_4,in_f5,in_f6,
                               in_f7,in_f8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),
                               (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
            return uVar1;
          }
          goto LAB_000713ec;
        }
        break;
      case 0xdb8:
        if ((3 < param_5) && (3 < (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)))) {
          iVar2 = (100 - param_6 * (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x3c))) * -0x10 + 0x660;
          iVar3 = param_6;
          iStack00000040 = _gleAddListItem(param_1,PTR__glMap2Vertex4_ListExec_001101c0,iVar2);
          if (iStack00000040 != 0) {
            uVar1 = ((int (*)())_gleMap2Vertex4fLoad)(param_1,extraout_r4_00,iVar2,param_5,param_6,iVar3,iVar4,
                               (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),fparam_1,fparam_2,fparam_3,fparam_4,in_f5,in_f6,
                               in_f7,in_f8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),
                               (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
            return uVar1;
          }
          goto LAB_000713ec;
        }
      }
    }
    if (*(int *)(param_1 + 0x7574) != 0) goto LAB_000713ec;
    uVar1 = 0x501;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) goto LAB_000713ec;
    uVar1 = 0x502;
  }
LAB_000713e8:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
LAB_000713ec:
  FUN_00008b68();
  return extraout_r3;
}

/* _glMap2f_Exec @ 0x713f8 (1140 bytes) */
void _glMap2f_Exec(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,int param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  int iStack00000040;
  
  iVar4 = param_6;
  iStack00000040 = _gleGetMapData(param_1);
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((((fparam_1 != fparam_2) && (fparam_3 != fparam_4)) && (param_6 - 1U < 10)) &&
       ((0 < (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x3c)) && ((*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x3c)) < 0xb)))) {
      uVar3 = param_2 - 0xdb0;
      if (8 < uVar3) {
        if (*(int *)(param_1 + 0x7574) != 0) goto LAB_00071884;
        uVar2 = 0x500;
        goto LAB_00071880;
      }
      iVar1 = uVar3 * 4;
      switch(uVar3) {
      case 0:
        if ((3 < param_5) && (3 < (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)))) {
          iStack00000040 = iStack00000040 + 0x1478;
          ((int (*)())_gleMap2ColorfLoad)(param_1,uVar3,param_3,param_5,param_6,iVar4,iVar1,(*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),
                             fparam_1,fparam_2,fparam_3,fparam_4,in_f5,in_f6,in_f7,in_f8,
                             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20))
                             ,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 1:
        if ((0 < param_5) && (0 < (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)))) {
          iStack00000040 = iStack00000040 + 0x1ad8;
          ((int (*)())_gleMap2IndexfLoad)(param_1,uVar3,param_3,param_5,param_6,iVar4,iVar1,(*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),
                             fparam_1,fparam_2,fparam_3,fparam_4,in_f5,in_f6,in_f7,in_f8,
                             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20))
                             ,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 2:
        if ((2 < param_5) && (2 < (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)))) {
          iStack00000040 = iStack00000040 + 0xfa8;
          ((int (*)())_gleMap2NormalfLoad)(param_1,uVar3,param_3,param_5,param_6,iVar4,iVar1,(*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),
                              fparam_1,fparam_2,fparam_3,fparam_4,in_f5,in_f6,in_f7,in_f8,
                              (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),
                              (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 3:
        if ((0 < param_5) && (0 < (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)))) {
          iStack00000040 = iStack00000040 + 0x1c88;
          ((int (*)())_gleMap2Texture1fLoad)(param_1,uVar3,param_3,param_5,param_6,iVar4,iVar1,(*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),fparam_1,
                     fparam_2,fparam_3,fparam_4,in_f5,in_f6,in_f7,in_f8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),
                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 4:
        if ((1 < param_5) && (1 < (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)))) {
          iStack00000040 = iStack00000040 + 0x1e38;
          ((int (*)())_gleMap2Texture2fLoad)(param_1,uVar3,param_3,param_5,param_6,iVar4,iVar1,(*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),fparam_1,
                     fparam_2,fparam_3,fparam_4,in_f5,in_f6,in_f7,in_f8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),
                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 5:
        if ((2 < param_5) && (2 < (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)))) {
          iStack00000040 = iStack00000040 + 0x2178;
          ((int (*)())_gleMap2Texture3fLoad)(param_1,uVar3,param_3,param_5,param_6,iVar4,iVar1,(*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),fparam_1,
                     fparam_2,fparam_3,fparam_4,in_f5,in_f6,in_f7,in_f8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),
                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 6:
        if ((3 < param_5) && (3 < (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)))) {
          iStack00000040 = iStack00000040 + 0x2648;
          ((int (*)())_gleMap2Texture4fLoad)(param_1,uVar3,param_3,param_5,param_6,iVar4,iVar1,(*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),fparam_1,
                     fparam_2,fparam_3,fparam_4,in_f5,in_f6,in_f7,in_f8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),
                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 7:
        if ((2 < param_5) && (2 < (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)))) {
          iStack00000040 = iStack00000040 + 0x478;
          ((int (*)())_gleMap2Vertex3fLoad)(param_1,uVar3,param_3,param_5,param_6,iVar4,iVar1,(*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),fparam_1,
                     fparam_2,fparam_3,fparam_4,in_f5,in_f6,in_f7,in_f8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),
                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 8:
        if ((3 < param_5) && (3 < (*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)))) {
          iStack00000040 = iStack00000040 + 0x948;
          ((int (*)())_gleMap2Vertex4fLoad)(param_1,uVar3,param_3,param_5,param_6,iVar4,iVar1,(*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x38)),fparam_1,
                     fparam_2,fparam_3,fparam_4,in_f5,in_f6,in_f7,in_f8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),
                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
      }
    }
    if (*(int *)(param_1 + 0x7574) != 0) goto LAB_00071884;
    uVar2 = 0x501;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) goto LAB_00071884;
    uVar2 = 0x502;
  }
LAB_00071880:
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
LAB_00071884:
  FUN_00008b68();
  return;
}

/* _glMap2f_CompExec @ 0x71890 (156 bytes) */
void _glMap2f_CompExec(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  ((undefined4 (*)())_glMap2f_Comp)(param_1,param_2,param_3,param_4,param_5,param_6,fparam_1,fparam_2,fparam_3,fparam_4)
  ;
  ((void (*)())_glMap2f_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,fparam_1,fparam_2,fparam_3,fparam_4)
  ;
  return;
}

