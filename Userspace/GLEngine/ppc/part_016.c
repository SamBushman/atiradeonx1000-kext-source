#include "decls.h"

/* _glFogf_Comp @ 0x67598 (92 bytes) */
undefined4 * _glFogf_Comp(undefined4 param_1,undefined4 param_2,double fparam_1)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glFogf_ListExec_001100f8,8);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = (float)fparam_1;
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glFogf_CompExec @ 0x675f4 (72 bytes) */
void _glFogf_CompExec(undefined4 param_1,undefined4 param_2,double fparam_1)
{
  ((undefined4 * (*)())_glFogf_Comp)(param_1,param_2,fparam_1);
  ((void (*)())_glFogf_Exec)(param_1,param_2,fparam_1);
  return;
}

/* _glFogfv_ListExec @ 0x6763c (48 bytes) */
int _glFogfv_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glFogfv_Exec(param_1,*param_2,param_2 + 1);
  return 0x14;
}

/* _glFogfv_Comp @ 0x6766c (112 bytes) */
int _glFogfv_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glFogfv_ListExec_001100f4,0x14);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    puVar1[1] = *param_3;
    puVar1[2] = param_3[1];
    puVar1[3] = param_3[2];
    puVar1[4] = param_3[3];
  }
  return puVar1;
}

/* _glFogfv_CompExec @ 0x676dc (64 bytes) */
void _glFogfv_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glFogfv_Comp)(param_1,param_2,param_3);
  _glFogfv_Exec(param_1,param_2,param_3);
  return;
}

/* _glFogi_ListExec @ 0x6771c (44 bytes) */
int _glFogi_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glFogi_Exec(param_1,*param_2,param_2[1]);
  return 8;
}

/* _glFogi_Comp @ 0x67748 (84 bytes) */
void _glFogi_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glFogi_ListExec_001100f0,8);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = param_3;
    *puVar1 = param_2;
  }
  return;
}

/* _glFogi_CompExec @ 0x6779c (64 bytes) */
void _glFogi_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  _glFogi_Exec(param_1,param_2,param_3);
  ((void (*)())_glFogi_Comp)(param_1,param_2,param_3);
  return;
}

/* _glFogiv_ListExec @ 0x677dc (48 bytes) */
int _glFogiv_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((void (*)())_glFogiv_Exec)(param_1,*param_2,param_2 + 1);
  return 0x14;
}

/* _glFogiv_Comp @ 0x6780c (112 bytes) */
int _glFogiv_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glFogiv_ListExec_001100ec,0x14);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    puVar1[1] = *param_3;
    puVar1[2] = param_3[1];
    puVar1[3] = param_3[2];
    puVar1[4] = param_3[3];
  }
  return puVar1;
}

/* _glFogiv_Exec @ 0x6787c (1096 bytes) */
void _glFogiv_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint *param_3;
{
  bool bVar1;
  byte bVar2;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  fVar4 = FLOAT_00108e50;
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar5 = 0x502;
LAB_00067b44:
    *(undefined4 *)(param_1 + 0x7574) = uVar5;
    return;
  }
  if (param_2 == 0xb64) {
    bVar1 = *(int *)(param_1 + 0x5434) == 0;
    *(float *)(param_1 + 0x3158) =
         (float)((double)CONCAT44(0x43300000,*param_3 ^ 0x80000000) - DOUBLE_00108d58);
LAB_00067bec:
    if (bVar1) {
      bVar2 = *(byte *)(*(int *)(param_1 + 0x5420) + 0x323);
    }
    else {
      bVar2 = *(byte *)(*(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x357);
    }
    iVar8 = (bVar2 >> 3 & 0x1c) + param_1;
    iVar7 = *(int *)(param_1 + 0x5424);
    *(uint *)(iVar8 + 0x324) = *(uint *)(iVar8 + 0x324) | 1 << (bVar2 & 0x1f);
    bVar2 = *(byte *)(iVar7 + 0x323);
  }
  else {
    if (param_2 < 0xb65) {
      if (param_2 == 0xb62) {
        if (-1 < (int)*param_3) {
          if (*(int *)(param_1 + 0x7574) != 0) {
            return;
          }
          uVar5 = 0x501;
          goto LAB_00067b44;
        }
        bVar1 = *(int *)(param_1 + 0x5434) == 0;
        *(float *)(param_1 + 0x3150) =
             (float)((double)CONCAT44(0x43300000,*param_3 ^ 0x80000000) - DOUBLE_00108d58);
      }
      else {
        if (param_2 < 0xb63) {
          if (param_2 == 0xb61) {
            *(float *)(param_1 + 0x3160) =
                 (float)((double)CONCAT44(0x43300000,*param_3 * 0x101 ^ 0x80000000) -
                        DOUBLE_00108d58);
            goto LAB_00067c9c;
          }
          goto LAB_00067c88;
        }
        bVar1 = *(int *)(param_1 + 0x5434) == 0;
        *(float *)(param_1 + 0x3154) =
             (float)((double)CONCAT44(0x43300000,*param_3 ^ 0x80000000) - DOUBLE_00108d58);
      }
      goto LAB_00067bec;
    }
    if (param_2 != 0xb66) {
      if (param_2 < 0xb66) {
        uVar6 = *param_3;
        if ((0x7ff < (int)uVar6) && (((int)uVar6 < 0x802 || (uVar6 == 0x2601)))) {
          *(short *)(param_1 + 0x3164) = (short)*param_3;
          goto LAB_00067c9c;
        }
      }
      else if (param_2 == 0x8450) {
        if (*param_3 - 0x8451 < 2) {
          *(short *)(param_1 + 0x3166) = (short)*param_3;
          _gleSelectVertexSubmitFunc(param_1);
          goto LAB_00067c9c;
        }
      }
      else if (param_2 == 0x855a) {
        uVar6 = *param_3;
        if ((uVar6 == 0x2502) || ((0x2501 < (int)uVar6 && (uVar6 - 0x855b < 2)))) {
          *(short *)(param_1 + 0x3168) = (short)*param_3;
          goto LAB_00067c9c;
        }
      }
LAB_00067c88:
      if (*(int *)(param_1 + 0x7574) == 0) {
        *(undefined4 *)(param_1 + 0x7574) = 0x500;
      }
      goto LAB_00067c9c;
    }
    fVar3 = (float)((double)CONCAT44(0x43300000,*param_3 ^ 0x80000000) - DOUBLE_00108d58) *
            FLOAT_00108e68 + FLOAT_00108e6c;
    if (FLOAT_00108e50 <= fVar3) {
      *(float *)(param_1 + 0x3140) = fVar3;
    }
    else {
      *(float *)(param_1 + 0x3140) = FLOAT_00108e50;
    }
    fVar3 = (float)((double)CONCAT44(0x43300000,param_3[1] ^ 0x80000000) - DOUBLE_00108d58) *
            FLOAT_00108e68 + FLOAT_00108e6c;
    if (fVar4 <= fVar3) {
      *(float *)(param_1 + 0x3144) = fVar3;
    }
    else {
      *(float *)(param_1 + 0x3144) = fVar4;
    }
    fVar3 = (float)((double)CONCAT44(0x43300000,param_3[2] ^ 0x80000000) - DOUBLE_00108d58) *
            FLOAT_00108e68 + FLOAT_00108e6c;
    if (fVar4 <= fVar3) {
      *(float *)(param_1 + 0x3148) = fVar3;
    }
    else {
      *(float *)(param_1 + 0x3148) = fVar4;
    }
    fVar3 = (float)((double)CONCAT44(0x43300000,param_3[3] ^ 0x80000000) - DOUBLE_00108d58) *
            FLOAT_00108e68 + FLOAT_00108e6c;
    if (fVar4 <= fVar3) {
      *(float *)(param_1 + 0x314c) = fVar3;
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
    iVar8 = (bVar2 >> 3 & 0x1c) + param_1;
    iVar7 = *(int *)(param_1 + 0x5424);
    *(uint *)(iVar8 + 0x324) = *(uint *)(iVar8 + 0x324) | 1 << (bVar2 & 0x1f);
    bVar2 = *(byte *)(iVar7 + 0x322);
  }
  iVar7 = (bVar2 >> 3 & 0x1c) + param_1;
  *(uint *)(iVar7 + 0x348) = *(uint *)(iVar7 + 0x348) | 1 << (bVar2 & 0x1f);
LAB_00067c9c:
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x800;
  ((double (*)())_gleUpdateFogData)(param_1);
  return;
}

/* _glFogiv_CompExec @ 0x67cc4 (64 bytes) */
void _glFogiv_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glFogiv_Comp)(param_1,param_2,param_3);
  ((void (*)())_glFogiv_Exec)(param_1,param_2,param_3);
  return;
}

/* _glFogCoord_ListExec @ 0x67d04 (16 bytes) */
int _glFogCoord_ListExec(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *(undefined4 *)(param_1 + 0x2cc) = *param_2;
  return 4;
}

/* _glFogCoordf_Comp @ 0x67d14 (84 bytes) */
float * _glFogCoordf_Comp(undefined4 param_1,double fparam_1)
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glFogCoord_ListExec_001100fc,4);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)fparam_1;
  }
  return pfVar1;
}

/* _glFogCoordfv_Comp @ 0x67d68 (80 bytes) */
int _glFogCoordfv_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glFogCoord_ListExec_001100fc,4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_2;
  }
  return puVar1;
}

/* _glFogCoordd_Comp @ 0x67db8 (88 bytes) */
float * _glFogCoordd_Comp(undefined4 param_1,double fparam_1)
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glFogCoord_ListExec_001100fc,4);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)fparam_1;
  }
  return pfVar1;
}

/* _glFogCoorddv_Comp @ 0x67e10 (84 bytes) */
int _glFogCoorddv_Comp(param_1, param_2)
  undefined4 param_1;
  double *param_2;
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glFogCoord_ListExec_001100fc,4);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)*param_2;
  }
  return pfVar1;
}

/* _glFogCoordf_Exec @ 0x67e64 (8 bytes) */
void _glFogCoordf_Exec(int param_1,float fparam_1)
{
  *(float *)(param_1 + 0x2cc) = (float)fparam_1;
  return;
}

/* _glFogCoordfv_Exec @ 0x67e6c (12 bytes) */
double _glFogCoordfv_Exec(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *(undefined4 *)(param_1 + 0x2cc) = *param_2;
  return;
}

/* _glFogCoordd_Exec @ 0x67e78 (12 bytes) */
void _glFogCoordd_Exec(int param_1,double fparam_1)
{
  *(float *)(param_1 + 0x2cc) = (float)fparam_1;
  return;
}

/* _glFogCoorddv_Exec @ 0x67e84 (16 bytes) */
double _glFogCoorddv_Exec(param_1, param_2)
  int param_1;
  double *param_2;
{
  *(float *)(param_1 + 0x2cc) = (float)*param_2;
  return;
}

/* _glFogCoordf_CompExec @ 0x67e94 (64 bytes) */
void _glFogCoordf_CompExec(undefined4 param_1,double fparam_1)
{
  ((float * (*)())_glFogCoordf_Comp)(param_1,fparam_1);
  ((void (*)())_glFogCoordf_Exec)(param_1,fparam_1);
  return;
}

/* _glFogCoordfv_CompExec @ 0x67ed4 (56 bytes) */
void _glFogCoordfv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glFogCoordfv_Comp)(param_1,param_2);
  ((double (*)())_glFogCoordfv_Exec)(param_1,param_2);
  return;
}

/* _glFogCoordd_CompExec @ 0x67f0c (64 bytes) */
void _glFogCoordd_CompExec(undefined4 param_1,double fparam_1)
{
  ((float * (*)())_glFogCoordd_Comp)(param_1,fparam_1);
  ((void (*)())_glFogCoordd_Exec)(param_1,fparam_1);
  return;
}

/* _glFogCoorddv_CompExec @ 0x67f4c (56 bytes) */
void _glFogCoorddv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glFogCoorddv_Comp)(param_1,param_2);
  ((double (*)())_glFogCoorddv_Exec)(param_1,param_2);
  return;
}

/* _glFrontFace_ListExec @ 0x67f84 (40 bytes) */
int _glFrontFace_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glFrontFace_Exec(param_1,*param_2);
  return 4;
}

/* _glFrontFace_Comp @ 0x67fac (76 bytes) */
int _glFrontFace_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glFrontFace_ListExec_00110100,4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glFrontFace_CompExec @ 0x67ff8 (56 bytes) */
void _glFrontFace_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glFrontFace_Comp)(param_1,param_2);
  _glFrontFace_Exec(param_1,param_2);
  return;
}

/* _glFrustum_ListExec @ 0x68030 (360 bytes) */
undefined4 _glFrustum_ListExec(int param_1,float *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11)
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
  float *pfVar11;
  
  pfVar11 = *(float **)(param_1 + 0x4fec);
  if ((*(short *)(param_1 + 0x4a10) < 0) && (*(int *)(param_1 + 0x4ff4) < 0x18)) {
    fVar1 = param_2[3];
    fVar2 = param_2[2];
    fVar3 = param_2[4];
    fVar4 = pfVar11[8];
    fVar5 = pfVar11[9];
    fVar6 = pfVar11[10];
    fVar7 = param_2[5];
    fVar8 = *param_2;
    fVar9 = param_2[1];
    fVar10 = pfVar11[0xf];
    pfVar11[8] = (fVar4 * fVar3 + (*pfVar11 * fVar2 + pfVar11[4] * fVar1)) - pfVar11[0xc];
    pfVar11[9] = (fVar5 * fVar3 + (pfVar11[1] * fVar2 + pfVar11[5] * fVar1)) - pfVar11[0xd];
    pfVar11[10] = (fVar6 * fVar3 + (pfVar11[2] * fVar2 + pfVar11[6] * fVar1)) - pfVar11[0xe];
    pfVar11[4] = pfVar11[4] * fVar9;
    *pfVar11 = *pfVar11 * fVar8;
    pfVar11[5] = pfVar11[5] * fVar9;
    pfVar11[1] = pfVar11[1] * fVar8;
    pfVar11[6] = pfVar11[6] * fVar9;
    pfVar11[0xc] = fVar4 * fVar7;
    pfVar11[0xd] = fVar5 * fVar7;
    pfVar11[0xe] = fVar6 * fVar7;
    pfVar11[2] = pfVar11[2] * fVar8;
    pfVar11[0xf] = pfVar11[0xb] * fVar7;
    pfVar11[0xb] = (pfVar11[0xb] * fVar3 + (pfVar11[3] * fVar2 + pfVar11[7] * fVar1)) - fVar10;
    pfVar11[3] = pfVar11[3] * fVar8;
    pfVar11[7] = pfVar11[7] * fVar9;
    *(uint *)(param_1 + 0x50ac) = *(uint *)(param_1 + 0x50ac) | *(uint *)(param_1 + 0x50a8);
    *(uint *)(param_1 + 0x50b0) = *(uint *)(param_1 + 0x50b0) | *(uint *)(param_1 + 0x50a8);
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
  }
  return 0x18;
}

/* _glFrustum_Comp @ 0x68198 (408 bytes) */
int _glFrustum_Comp(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  float dVar6;
  
  if ((DOUBLE_00108d60 < fparam_5) && (DOUBLE_00108d60 < fparam_6)) {
    fVar1 = (float)(fparam_2 - fparam_1);
    fVar2 = (float)(fparam_4 - fparam_3);
    fVar3 = (float)(fparam_5 - fparam_6);
    fVar4 = fVar1;
    if (fVar1 < 0.0) {
      fVar4 = -fVar1;
    }
    if (FLOAT_00108e80 <= fVar4) {
      fVar4 = fVar2;
      if (fVar2 < FLOAT_00108e50) {
        fVar4 = -fVar2;
      }
      if (FLOAT_00108e80 <= fVar4) {
        fVar4 = fVar3;
        if (fVar3 < FLOAT_00108e50) {
          fVar4 = -fVar3;
        }
        if (FLOAT_00108e80 <= fVar4) {
          pfVar5 = (float *)_gleAddListItem(param_1,PTR__glFrustum_ListExec_00110104,0x18);
          if (pfVar5 == (float *)0x0) {
            return 0;
          }
          dVar6 = (double)(float)(fparam_5 + fparam_5);
          *pfVar5 = (float)((double)dVar6 * (double)(1.0 / fVar1));
          pfVar5[2] = (float)((fparam_2 + fparam_1) * (double)(1.0 / fVar1));
          pfVar5[3] = (float)((fparam_4 + fparam_3) * (double)(1.0 / fVar2));
          pfVar5[4] = (float)((fparam_6 + fparam_5) * (double)(1.0 / fVar3));
          pfVar5[5] = (float)(fparam_6 * (double)dVar6 * (double)(1.0 / fVar3));
          pfVar5[1] = (float)((double)dVar6 * (double)(1.0 / fVar2));
          return (int)pfVar5;
        }
      }
    }
  }
  if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x501;
  }
  return param_1;
}

/* _glFrustum_CompExec @ 0x68330 (120 bytes) */
void _glFrustum_CompExec(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  double in_stack_ffffff68;
  double in_stack_ffffff70;
  double in_stack_ffffff78;
  double in_stack_ffffff80;
  double in_stack_ffffff88;
  
  ((int (*)())_glFrustum_Comp)(param_1,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,
                  in_stack_ffffff68,in_stack_ffffff70,in_stack_ffffff78,in_stack_ffffff80,
                  in_stack_ffffff88);
  ((void (*)())_glFrustum_Exec)(param_1,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,
                  fparam_9,fparam_10,fparam_11,fparam_12,fparam_13);
  return;
}

/* _glHint_ListExec @ 0x683a8 (44 bytes) */
int _glHint_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glHint_Exec(param_1,*param_2,param_2[1]);
  return 8;
}

/* _glHint_Comp @ 0x683d4 (84 bytes) */
int _glHint_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glHint_ListExec_00110108,8);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = param_3;
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glHint_CompExec @ 0x68428 (64 bytes) */
void _glHint_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glHint_Comp)(param_1,param_2,param_3);
  _glHint_Exec(param_1,param_2,param_3);
  return;
}

/* _CheckInternalFormat @ 0x68468 (76 bytes) */
int _CheckInternalFormat(param_1)
  uint param_1;
{
  if (param_1 < 0x8049) {
    if ((param_1 < 0x803b) && ((param_1 < 0x1906 || ((0x190a < param_1 && (param_1 != 0x2a10)))))) {
      return 0;
    }
  }
  else if (0xc < param_1 - 0x804f) {
    return 0;
  }
  return 1;
}

/* _CheckTypeFormat @ 0x684b4 (184 bytes) */
int _CheckTypeFormat(param_1, param_2)
  uint param_1;
  uint param_2;
{
  bool bVar1;
  
  if (param_1 < 0x8037) {
    if (0x8032 < param_1) {
LAB_00068548:
      if (param_2 == 0x1908) {
        return 1;
      }
      bVar1 = param_2 == 0x80e1;
      goto LAB_0006855c;
    }
    if (param_1 < 0x1400) {
      return 1;
    }
    if (param_1 < 0x1407) {
      if (param_2 == 0x8000) {
        return 1;
      }
      if (param_2 < 0x8001) {
        bVar1 = 7 < param_2 - 0x1903;
      }
      else {
        bVar1 = 1 < param_2 - 0x80e0;
      }
      if (!bVar1) {
        return 1;
      }
      return 0;
    }
    if (param_1 != 0x8032) {
      return 1;
    }
  }
  else {
    if (param_1 < 0x8362) {
      return 1;
    }
    if (0x8364 < param_1) {
      if (0x8368 < param_1) {
        return 1;
      }
      goto LAB_00068548;
    }
  }
  bVar1 = param_2 == 0x1907;
LAB_0006855c:
  if (bVar1) {
    return 1;
  }
  return 0;
}

/* _glConvolutionFilter1D_ListExec @ 0x6856c (72 bytes) */
int _glConvolutionFilter1D_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glConvolutionFilter1D_Exec
            (param_1,*param_2,param_2[1],param_2[2],param_2[3],param_2[4],param_2 + 6);
  return param_2[5];
}

/* _glConvolutionFilter2D_ListExec @ 0x685b4 (76 bytes) */
int _glConvolutionFilter2D_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glConvolutionFilter2D_Exec
            (param_1,*param_2,param_2[1],param_2[2],param_2[3],param_2[4],param_2[5],param_2 + 7);
  return param_2[6];
}

/* _glSeparableFilter2D_ListExec @ 0x68600 (120 bytes) */
int _glSeparableFilter2D_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  int iVar1;
  
  iVar1 = _gleRowBytes(param_2[4],param_2[5],param_2[2]);
  _glSeparableFilter2D_Exec
            (param_1,*param_2,param_2[1],param_2[2],param_2[3],param_2[4],param_2[5],param_2 + 7,
             (int)(param_2 + 7) + (iVar1 + 3U & 0xfffffffc));
  return param_2[6];
}

/* _glConvolutionParameterf_ListExec @ 0x68678 (52 bytes) */
int _glConvolutionParameterf_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((void (*)())_glConvolutionParameterf_Exec)(param_1,*param_2,param_2[1],(double)GH_U2F((unsigned int)(param_2[2])));
  return 0x18;
}

/* _glConvolutionParameterfv_ListExec @ 0x686ac (52 bytes) */
int _glConvolutionParameterfv_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glConvolutionParameterfv_Exec(param_1,*param_2,param_2[1],param_2 + 2);
  return 0x18;
}

/* _glConvolutionParameteri_ListExec @ 0x686e0 (52 bytes) */
int _glConvolutionParameteri_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glConvolutionParameteri_Exec(param_1,*param_2,param_2[1],param_2[2]);
  return 0x18;
}

/* _glConvolutionParameteriv_ListExec @ 0x68714 (52 bytes) */
int _glConvolutionParameteriv_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glConvolutionParameteriv_Exec(param_1,*param_2,param_2[1],param_2 + 2);
  return 0x18;
}

/* _glCopyConvolutionFilter1D_ListExec @ 0x68748 (60 bytes) */
int _glCopyConvolutionFilter1D_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glCopyConvolutionFilter1D_Exec(param_1,*param_2,param_2[1],param_2[2],param_2[3],param_2[4]);
  return 0x18;
}

/* _glCopyConvolutionFilter2D_ListExec @ 0x68784 (64 bytes) */
int _glCopyConvolutionFilter2D_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glCopyConvolutionFilter2D_Exec
            (param_1,*param_2,param_2[1],param_2[2],param_2[3],param_2[4],param_2[5]);
  return 0x18;
}

/* _glHistogram_ListExec @ 0x687c4 (56 bytes) */
int _glHistogram_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glHistogram_Exec(param_1,*param_2,param_2[2],param_2[1],(uint)*(byte *)(param_2 + 3));
  return 0x10;
}

/* _glMinmax_ListExec @ 0x687fc (52 bytes) */
int _glMinmax_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glMinmax_Exec(param_1,*param_2,param_2[1],(uint)*(byte *)(param_2 + 2));
  return 0xc;
}

/* _glResetHistogram_ListExec @ 0x68830 (40 bytes) */
int _glResetHistogram_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glResetHistogram_Exec(param_1,*param_2);
  return 0x10;
}

/* _glResetMinmax_ListExec @ 0x68858 (40 bytes) */
int _glResetMinmax_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glResetMinmax_Exec(param_1,*param_2);
  return 0xc;
}

/* _glConvolutionFilter1D_Comp @ 0x68880 (372 bytes) */
int _glConvolutionFilter1D_Comp(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  int param_7;
{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  double dVar6;
  
  iVar1 = _gleRowBytes(param_5,param_6,param_4);
  if (iVar1 < 1) {
    return (undefined4 *)iVar1;
  }
  iVar4 = *(int *)(param_1 + 0x4a6c);
  if (iVar4 == 0) {
LAB_0006897c:
    iVar1 = (iVar1 + 3U & 0xfffffffc) + 0x18;
    puVar3 = (undefined4 *)
             _gleAddListItem(param_1,PTR__glConvolutionFilter1D_ListExec_00110134,iVar1);
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = param_2;
      puVar3[1] = param_3;
      puVar3[5] = iVar1;
      puVar3[2] = param_4;
      puVar3[3] = param_5;
      puVar3[4] = param_6;
      if (param_7 != 0) {
        puVar3 = (undefined4 *)_gleFillImage(param_1,param_4,1,1,param_5,param_6,param_7,puVar3 + 6)
        ;
      }
    }
  }
  else {
    iVar2 = _gleOffsetLimitImage(param_1 + 0x31cc,param_4,1,param_5,param_6,param_7);
    iVar5 = *(int *)(iVar4 + 0x38);
    dVar6 = (double)((double (*)())_gleBytesPerElement)(param_6);
    puVar3 = (undefined4 *)(int)dVar6;
    if (iVar2 <= iVar5) {
      if (puVar3 == (undefined4 *)0x0) {
        puVar3 = (undefined4 *)_glePixelBytes(param_5,param_6);
      }
      if (param_7 == (param_7 / (int)puVar3) * (int)puVar3) {
        if (*(int *)(iVar4 + 0x40) != 0) {
          _gleSynchronizePluginBuffer(param_1,iVar4 + 0x10);
        }
        param_7 = param_7 + *(int *)(iVar4 + 0x30);
        goto LAB_0006897c;
      }
    }
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
  }
  return puVar3;
}

/* _glConvolutionFilter2D_Comp @ 0x689f4 (384 bytes) */
int _glConvolutionFilter2D_Comp(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  int param_8;
{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  double dVar6;
  
  iVar1 = _gleImageSize(param_6,param_7,param_4,param_5);
  if (iVar1 < 1) {
    return (undefined4 *)iVar1;
  }
  iVar4 = *(int *)(param_1 + 0x4a6c);
  if (iVar4 == 0) {
LAB_00068af8:
    iVar1 = (iVar1 + 3U & 0xfffffffc) + 0x1c;
    puVar3 = (undefined4 *)
             _gleAddListItem(param_1,PTR__glConvolutionFilter2D_ListExec_00110130,iVar1);
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = param_2;
      puVar3[1] = param_3;
      puVar3[6] = iVar1;
      puVar3[2] = param_4;
      puVar3[3] = param_5;
      puVar3[4] = param_6;
      puVar3[5] = param_7;
      if (param_8 != 0) {
        puVar3 = (undefined4 *)
                 _gleFillImage(param_1,param_4,param_5,1,param_6,param_7,param_8,puVar3 + 7);
      }
    }
  }
  else {
    iVar2 = _gleOffsetLimitImage(param_1 + 0x31cc,param_4,param_5,param_6,param_7,param_8);
    iVar5 = *(int *)(iVar4 + 0x38);
    dVar6 = (double)((double (*)())_gleBytesPerElement)(param_7);
    puVar3 = (undefined4 *)(int)dVar6;
    if (iVar2 <= iVar5) {
      if (puVar3 == (undefined4 *)0x0) {
        puVar3 = (undefined4 *)_glePixelBytes(param_6,param_7);
      }
      if (param_8 == (param_8 / (int)puVar3) * (int)puVar3) {
        if (*(int *)(iVar4 + 0x40) != 0) {
          _gleSynchronizePluginBuffer(param_1,iVar4 + 0x10);
        }
        param_8 = param_8 + *(int *)(iVar4 + 0x30);
        goto LAB_00068af8;
      }
    }
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
  }
  return puVar3;
}

/* _glSeparableFilter2D_Comp @ 0x68b74 (536 bytes) */
int _glSeparableFilter2D_Comp(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  int param_8;
  int param_9;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  double dVar8;
  
  iVar2 = _gleRowBytes(param_6,param_7,param_4);
  iVar3 = _gleRowBytes(param_6,param_7,param_5);
  if (iVar2 < 1) {
    return (undefined4 *)iVar3;
  }
  if (iVar3 < 1) {
    return (undefined4 *)iVar3;
  }
  iVar6 = *(int *)(param_1 + 0x4a6c);
  uVar1 = iVar2 + 3U & 0xfffffffc;
  if (iVar6 == 0) {
LAB_00068cdc:
    iVar2 = uVar1 + (iVar3 + 3U & 0xfffffffc) + 0x1c;
    puVar5 = (undefined4 *)_gleAddListItem(param_1,PTR__glSeparableFilter2D_ListExec_0011012c,iVar2)
    ;
    if (puVar5 != (undefined4 *)0x0) {
      *puVar5 = param_2;
      puVar5[1] = param_3;
      puVar5[6] = iVar2;
      puVar5[2] = param_4;
      puVar5[3] = param_5;
      puVar5[4] = param_6;
      puVar5[5] = param_7;
      if ((param_8 != 0) && (param_9 != 0)) {
        _gleFillImage(param_1,param_4,1,1,param_6,param_7,param_8,puVar5 + 7);
        puVar5 = (undefined4 *)
                 _gleFillImage(param_1,param_5,1,1,param_6,param_7,param_9,(int)(puVar5 + 7) + uVar1
                              );
      }
    }
  }
  else {
    iVar2 = _gleOffsetLimitImage(param_1 + 0x31cc,param_4,1,param_6,param_7,param_8);
    iVar4 = _gleOffsetLimitImage(param_1 + 0x31cc,param_5,1,param_6,param_7,param_9);
    iVar7 = *(int *)(iVar6 + 0x38);
    dVar8 = (double)((double (*)())_gleBytesPerElement)(param_7);
    puVar5 = (undefined4 *)(int)dVar8;
    if ((iVar2 <= iVar7) && (iVar4 <= iVar7)) {
      if (puVar5 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)_glePixelBytes(param_6,param_7);
      }
      if ((param_8 == (param_8 / (int)puVar5) * (int)puVar5) &&
         (param_9 == (param_9 / (int)puVar5) * (int)puVar5)) {
        if (*(int *)(iVar6 + 0x40) != 0) {
          _gleSynchronizePluginBuffer(param_1,iVar6 + 0x10);
        }
        param_9 = param_9 + *(int *)(iVar6 + 0x30);
        param_8 = param_8 + *(int *)(iVar6 + 0x30);
        goto LAB_00068cdc;
      }
    }
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
  }
  return puVar5;
}

/* _glConvolutionParameterF_Comp @ 0x68d8c (188 bytes) */
int _glConvolutionParameterF_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  uint param_3;
  undefined4 *param_4;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           _gleAddListItem(param_1,PTR__glConvolutionParameterf_ListExec_00110128,0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    puVar1[1] = param_3;
    if (param_3 < 0x8016) {
      if (param_3 < 0x8014) {
        if (param_3 != 0x8013) {
          return puVar1;
        }
        puVar1[2] = *param_4;
        return puVar1;
      }
    }
    else if (param_3 != 0x8154) {
      return puVar1;
    }
    puVar1[2] = *param_4;
    puVar1[3] = param_4[1];
    puVar1[4] = param_4[2];
    puVar1[5] = param_4[3];
  }
  return puVar1;
}

/* _glConvolutionParameterf_Comp @ 0x68e48 (40 bytes) */
undefined4 _glConvolutionParameterf_Comp(undefined4 param_1,undefined4 param_2,undefined4 param_3,float fparam_1)
{
  undefined4 uVar1;
  float fStack00000024;
  
  fStack00000024 = (float)fparam_1;
  uVar1 = ((int (*)())_glConvolutionParameterF_Comp)(param_1,param_2,param_3,&STACKARG(0x24));
  return uVar1;
}

/* _glConvolutionParameterI_Comp @ 0x68e74 (168 bytes) */
int _glConvolutionParameterI_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  uint param_3;
  undefined4 *param_4;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           _gleAddListItem(param_1,PTR__glConvolutionParameteri_ListExec_00110124,0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    puVar1[1] = param_3;
    if (0x8012 < param_3) {
      if (param_3 < 0x8016) {
        puVar1[2] = *param_4;
      }
      else if (param_3 == 0x8154) {
        puVar1[2] = *param_4;
        puVar1[3] = param_4[1];
        puVar1[4] = param_4[2];
        puVar1[5] = param_4[3];
      }
    }
  }
  return puVar1;
}

/* _glConvolutionParameteri_Comp @ 0x68f1c (40 bytes) */
int _glConvolutionParameteri_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, param_4, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined4 uVar1;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 12)) = param_4;
  uVar1 = ((int (*)())_glConvolutionParameterI_Comp)(param_1,param_2,param_3,&(*(unsigned int *)((unsigned char *)ghidra_home + 12)));
  return uVar1;
}

/* _glCopyConvolutionFilter1D_Comp @ 0x68f48 (116 bytes) */
int _glCopyConvolutionFilter1D_Comp(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           _gleAddListItem(param_1,PTR__glCopyConvolutionFilter1D_ListExec_00110120,0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    puVar1[5] = 1;
    puVar1[1] = param_3;
    puVar1[2] = param_4;
    puVar1[3] = param_5;
    puVar1[4] = param_6;
  }
  return puVar1;
}

/* _glCopyConvolutionFilter2D_Comp @ 0x68fbc (116 bytes) */
int _glCopyConvolutionFilter2D_Comp(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           _gleAddListItem(param_1,PTR__glCopyConvolutionFilter2D_ListExec_0011011c,0x18);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[5] = param_7;
    *puVar1 = param_2;
    puVar1[1] = param_3;
    puVar1[2] = param_4;
    puVar1[3] = param_5;
    puVar1[4] = param_6;
  }
  return puVar1;
}

/* _glHistogram_Comp @ 0x69030 (100 bytes) */
int _glHistogram_Comp(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glHistogram_ListExec_00110118,0x10);
  if (puVar1 != (undefined4 *)0x0) {
    *(undefined1 *)(puVar1 + 3) = (undefined1)param_5;
    *puVar1 = param_2;
    puVar1[2] = param_3;
    puVar1[1] = param_4;
  }
  return puVar1;
}

/* _glMinmax_Comp @ 0x69094 (92 bytes) */
int _glMinmax_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glMinmax_ListExec_00110114,0xc);
  if (puVar1 != (undefined4 *)0x0) {
    *(undefined1 *)(puVar1 + 2) = (undefined1)param_4;
    *puVar1 = param_2;
    puVar1[1] = param_3;
  }
  return puVar1;
}

