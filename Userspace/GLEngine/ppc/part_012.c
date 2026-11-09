#include "decls.h"

/* _glColor4uiv_CompExec @ 0x5d138 (56 bytes) */
int _glColor4uiv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  _glColor4uiv_Comp(param_1,param_2);
  _glColor4uiv_Exec(param_1,param_2);
  return;
}

/* _glColor4us_Comp @ 0x5d170 (228 bytes) */
int _glColor4us_Comp(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  uint param_2;
  uint param_3;
  uint param_4;
  uint param_5;
{
  float fVar1;
  float *pfVar2;
  
  pfVar2 = (float *)_gleAddListItem(param_1,PTR__glColor4_ListExec_00110058,0x10);
  fVar1 = FLOAT_00108e74;
  if (pfVar2 != (float *)0x0) {
    *pfVar2 = (GH_U2F((unsigned int)((param_2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
    pfVar2[1] = (GH_U2F((unsigned int)((param_3 | 0x4b000000))) - 8388608.0) * fVar1;
    pfVar2[2] = (GH_U2F((unsigned int)((param_4 | 0x4b000000))) - 8388608.0) * fVar1;
    pfVar2[3] = (GH_U2F((unsigned int)((param_5 | 0x4b000000))) - 8388608.0) * fVar1;
  }
  return pfVar2;
}

/* _glColor4us_Exec @ 0x5d254 (204 bytes) */
double _glColor4us_Exec(int param_1,uint param_2,uint param_3,uint param_4,uint param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = (GH_U2F((unsigned int)((param_5 | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  fVar2 = (GH_U2F((unsigned int)((param_3 | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  fVar3 = (GH_U2F((unsigned int)((param_4 | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(float *)(param_1 + 0x2a0) = (GH_U2F((unsigned int)((param_2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(float *)(param_1 + 0x2ac) = fVar1;
  *(float *)(param_1 + 0x2a4) = fVar2;
  *(float *)(param_1 + 0x2a8) = fVar3;
  if (*(char *)(param_1 + 0x4df8) != '\0') {
    fparam_1 = (double)(**(double ( **)(int,int))(param_1 + 0x4de0))(param_1, param_1 + 0x2a0);
  }
  return fparam_1;
}

/* _glColor4us_CompExec @ 0x5d320 (80 bytes) */
int _glColor4us_CompExec(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, param_4, param_5, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined4 in_LR;
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glColor4us_Comp)(param_1,param_2,param_3,param_4,param_5);
  ((double (*)())_glColor4us_Exec)(param_1,param_2,param_3,param_4,param_5,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,
                   in_f7,in_f8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                   (*(double *)((unsigned char *)ghidra_home + 0)),(*(double *)((unsigned char *)ghidra_home + 8)),(*(double *)((unsigned char *)ghidra_home + 16)));
  return;
}

/* _glColor4usv_Comp @ 0x5d370 (232 bytes) */
int _glColor4usv_Comp(param_1, param_2)
  undefined4 param_1;
  ushort *param_2;
{
  float fVar1;
  float *pfVar2;
  
  pfVar2 = (float *)_gleAddListItem(param_1,PTR__glColor4_ListExec_00110058,0x10);
  fVar1 = FLOAT_00108e74;
  if (pfVar2 != (float *)0x0) {
    *pfVar2 = (GH_U2F((unsigned int)((*param_2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
    pfVar2[1] = (GH_U2F((unsigned int)((param_2[1] | 0x4b000000))) - 8388608.0) * fVar1;
    pfVar2[2] = (GH_U2F((unsigned int)((param_2[2] | 0x4b000000))) - 8388608.0) * fVar1;
    pfVar2[3] = (GH_U2F((unsigned int)((param_2[3] | 0x4b000000))) - 8388608.0) * fVar1;
  }
  return pfVar2;
}

/* _glColor4usv_Exec @ 0x5d458 (220 bytes) */
double _glColor4usv_Exec(int param_1,ushort *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = (GH_U2F((unsigned int)((param_2[3] | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  fVar2 = (GH_U2F((unsigned int)((param_2[1] | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  fVar3 = (GH_U2F((unsigned int)((param_2[2] | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(float *)(param_1 + 0x2a0) = (GH_U2F((unsigned int)((*param_2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(float *)(param_1 + 0x2ac) = fVar1;
  *(float *)(param_1 + 0x2a4) = fVar2;
  *(float *)(param_1 + 0x2a8) = fVar3;
  if (*(char *)(param_1 + 0x4df8) != '\0') {
    fparam_1 = (double)(**(double ( **)(int,int))(param_1 + 0x4de0))(param_1, param_1 + 0x2a0);
  }
  return fparam_1;
}

/* _glColor4usv_CompExec @ 0x5d534 (56 bytes) */
int _glColor4usv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  unsigned int ghidra_home[8] = { param_1, param_2, 0, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined4 in_LR;
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glColor4usv_Comp)(param_1,param_2);
  ((double (*)())_glColor4usv_Exec)(param_1,param_2,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                    (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)((unsigned char *)ghidra_home + 0)),
                    (*(double *)((unsigned char *)ghidra_home + 8)),(*(double *)((unsigned char *)ghidra_home + 16)));
  return;
}

/* _gleLightMaterialChangeNoop @ 0x5d56c (4 bytes) */
int _gleLightMaterialChangeNoop()
{
  return;
}

/* _glIndex_ListExec @ 0x5d570 (16 bytes) */
int _glIndex_ListExec(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *(undefined4 *)(param_1 + 700) = *param_2;
  return 4;
}

/* _glIndexd_Comp @ 0x5d580 (100 bytes) */
float * _glIndexd_Comp(undefined4 param_1,double fparam_1)
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glIndex_ListExec_00110054,4);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)(fparam_1 * DOUBLE_00108d78);
  }
  return pfVar1;
}

/* _glIndexd_Exec @ 0x5d5e4 (40 bytes) */
void _glIndexd_Exec(int param_1,double fparam_1)
{
  *(float *)(param_1 + 700) = (float)(fparam_1 * DOUBLE_00108d78);
  return;
}

/* _glIndexd_CompExec @ 0x5d60c (64 bytes) */
void _glIndexd_CompExec(undefined4 param_1,double fparam_1)
{
  ((float * (*)())_glIndexd_Comp)(param_1,fparam_1);
  ((void (*)())_glIndexd_Exec)(param_1,fparam_1);
  return;
}

/* _glIndexdv_Comp @ 0x5d64c (96 bytes) */
int _glIndexdv_Comp(param_1, param_2)
  undefined4 param_1;
  double *param_2;
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glIndex_ListExec_00110054,4);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)(*param_2 * DOUBLE_00108d78);
  }
  return pfVar1;
}

/* _glIndexdv_Exec @ 0x5d6ac (44 bytes) */
int _glIndexdv_Exec(param_1, param_2)
  int param_1;
  double *param_2;
{
  *(float *)(param_1 + 700) = (float)(*param_2 * DOUBLE_00108d78);
  return;
}

/* _glIndexdv_CompExec @ 0x5d6d8 (56 bytes) */
int _glIndexdv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glIndexdv_Comp)(param_1,param_2);
  ((int (*)())_glIndexdv_Exec)(param_1,param_2);
  return;
}

/* _glIndexf_Comp @ 0x5d710 (96 bytes) */
float * _glIndexf_Comp(undefined4 param_1,double fparam_1)
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glIndex_ListExec_00110054,4);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)(fparam_1 * (double)FLOAT_00108e5c);
  }
  return pfVar1;
}

/* _glIndexf_Exec @ 0x5d770 (36 bytes) */
void _glIndexf_Exec(int param_1,float fparam_1)
{
  *(float *)(param_1 + 700) = (float)(fparam_1 * (double)FLOAT_00108e5c);
  return;
}

/* _glIndexf_CompExec @ 0x5d794 (64 bytes) */
void _glIndexf_CompExec(undefined4 param_1,double fparam_1)
{
  ((float * (*)())_glIndexf_Comp)(param_1,fparam_1);
  ((void (*)())_glIndexf_Exec)(param_1,fparam_1);
  return;
}

/* _glIndexfv_Comp @ 0x5d7d4 (92 bytes) */
int _glIndexfv_Comp(param_1, param_2)
  undefined4 param_1;
  float *param_2;
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glIndex_ListExec_00110054,4);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = *param_2 * FLOAT_00108e5c;
  }
  return pfVar1;
}

/* _glIndexfv_Exec @ 0x5d830 (40 bytes) */
int _glIndexfv_Exec(param_1, param_2)
  int param_1;
  float *param_2;
{
  *(float *)(param_1 + 700) = *param_2 * FLOAT_00108e5c;
  return;
}

/* _glIndexfv_CompExec @ 0x5d858 (56 bytes) */
int _glIndexfv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glIndexfv_Comp)(param_1,param_2);
  ((int (*)())_glIndexfv_Exec)(param_1,param_2);
  return;
}

/* _glIndexi_Comp @ 0x5d890 (120 bytes) */
int _glIndexi_Comp(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glIndex_ListExec_00110054,4);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)((double)CONCAT44(0x43300000,param_2 * 0x101 ^ 0x80000000) - DOUBLE_00108d58);
  }
  return pfVar1;
}

/* _glIndexi_Exec @ 0x5d908 (68 bytes) */
int _glIndexi_Exec(param_1, param_2)
  int param_1;
  int param_2;
{
  *(float *)(param_1 + 700) =
       (float)((double)CONCAT44(0x43300000,param_2 * 0x101 ^ 0x80000000) - DOUBLE_00108d58);
  return;
}

/* _glIndexi_CompExec @ 0x5d94c (56 bytes) */
int _glIndexi_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glIndexi_Comp)(param_1,param_2);
  ((int (*)())_glIndexi_Exec)(param_1,param_2);
  return;
}

/* _glIndexiv_Comp @ 0x5d984 (124 bytes) */
int _glIndexiv_Comp(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glIndex_ListExec_00110054,4);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)((double)CONCAT44(0x43300000,*param_2 * 0x101 ^ 0x80000000) - DOUBLE_00108d58);
  }
  return pfVar1;
}

/* _glIndexiv_CompExec @ 0x5da48 (128 bytes) */
int _glIndexiv_CompExec(param_1, param_2)
  int param_1;
  int *param_2;
{
  ((int (*)())_glIndexiv_Comp)(param_1,param_2);
  *(float *)(param_1 + 700) =
       (float)((double)CONCAT44(0x43300000,*param_2 * 0x101 ^ 0x80000000) - DOUBLE_00108d58);
  return;
}

/* _glIndexs_Comp @ 0x5da80 (120 bytes) */
int _glIndexs_Comp(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glIndex_ListExec_00110054,4);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)((double)CONCAT44(0x43300000,param_2 * 0x101 ^ 0x80000000) - DOUBLE_00108d58);
  }
  return pfVar1;
}

/* _glIndexs_Exec @ 0x5daf8 (68 bytes) */
int _glIndexs_Exec(param_1, param_2)
  int param_1;
  int param_2;
{
  *(float *)(param_1 + 700) =
       (float)((double)CONCAT44(0x43300000,param_2 * 0x101 ^ 0x80000000) - DOUBLE_00108d58);
  return;
}

/* _glIndexs_CompExec @ 0x5db3c (56 bytes) */
int _glIndexs_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glIndexs_Comp)(param_1,param_2);
  ((int (*)())_glIndexs_Exec)(param_1,param_2);
  return;
}

/* _glIndexsv_Comp @ 0x5db74 (124 bytes) */
int _glIndexsv_Comp(param_1, param_2)
  undefined4 param_1;
  short *param_2;
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glIndex_ListExec_00110054,4);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)((double)CONCAT44(0x43300000,*param_2 * 0x101 ^ 0x80000000) - DOUBLE_00108d58);
  }
  return pfVar1;
}

/* _glIndexsv_CompExec @ 0x5dc38 (128 bytes) */
int _glIndexsv_CompExec(param_1, param_2)
  int param_1;
  short *param_2;
{
  ((int (*)())_glIndexsv_Comp)(param_1,param_2);
  *(float *)(param_1 + 700) =
       (float)((double)CONCAT44(0x43300000,*param_2 * 0x101 ^ 0x80000000) - DOUBLE_00108d58);
  return;
}

/* _glIndexub_Comp @ 0x5dc70 (120 bytes) */
int _glIndexub_Comp(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glIndex_ListExec_00110054,4);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)((double)CONCAT44(0x43300000,param_2 * 0x101 ^ 0x80000000) - DOUBLE_00108d58);
  }
  return pfVar1;
}

/* _glIndexub_Exec @ 0x5dce8 (68 bytes) */
int _glIndexub_Exec(param_1, param_2)
  int param_1;
  int param_2;
{
  *(float *)(param_1 + 700) =
       (float)((double)CONCAT44(0x43300000,param_2 * 0x101 ^ 0x80000000) - DOUBLE_00108d58);
  return;
}

/* _glIndexub_CompExec @ 0x5dd2c (56 bytes) */
int _glIndexub_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glIndexub_Comp)(param_1,param_2);
  ((int (*)())_glIndexub_Exec)(param_1,param_2);
  return;
}

/* _glIndexubv_Comp @ 0x5dd64 (124 bytes) */
int _glIndexubv_Comp(param_1, param_2)
  undefined4 param_1;
  byte *param_2;
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glIndex_ListExec_00110054,4);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)((double)CONCAT44(0x43300000,
                                       (uint)*param_2 * 0x100 + (uint)*param_2 ^ 0x80000000) -
                     DOUBLE_00108d58);
  }
  return pfVar1;
}

/* _glIndexubv_Exec @ 0x5dde0 (72 bytes) */
int _glIndexubv_Exec(param_1, param_2)
  int param_1;
  byte *param_2;
{
  *(float *)(param_1 + 700) =
       (float)((double)CONCAT44(0x43300000,(uint)*param_2 * 0x100 + (uint)*param_2 ^ 0x80000000) -
              DOUBLE_00108d58);
  return;
}

/* _glIndexubv_CompExec @ 0x5de28 (56 bytes) */
int _glIndexubv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glIndexubv_Comp)(param_1,param_2);
  ((int (*)())_glIndexubv_Exec)(param_1,param_2);
  return;
}

/* _glColorMaterial_ListExec @ 0x5de60 (44 bytes) */
int _glColorMaterial_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((int (*)())_glColorMaterial_Exec)(param_1,*param_2,param_2[1]);
  return 8;
}

/* _glColorMaterial_Comp @ 0x5de8c (84 bytes) */
int _glColorMaterial_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glColorMaterial_ListExec_00110060,8);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = param_3;
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glColorMaterial_Exec @ 0x5dee0 (188 bytes) */
int _glColorMaterial_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint param_3;
{
  undefined4 uVar1;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((param_2 < 0x404) || ((0x405 < param_2 && (param_2 != 0x408)))) goto LAB_0005df54;
    if (param_3 != 0x1600) {
      if (param_3 < 0x1601) {
        if (2 < param_3 - 0x1200) {
LAB_0005df54:
          if (*(int *)(param_1 + 0x7574) != 0) {
            return;
          }
          uVar1 = 0x500;
          goto LAB_0005df64;
        }
      }
      else if (param_3 != 0x1602) goto LAB_0005df54;
    }
    *(short *)(param_1 + 0x30a4) = (short)param_2;
    *(short *)(param_1 + 0x30a6) = (short)param_3;
    _gleUpdateLightColorChangeFunc(param_1);
    *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x40000;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
LAB_0005df64:
    *(undefined4 *)(param_1 + 0x7574) = uVar1;
  }
  return;
}

/* _glColorMaterial_CompExec @ 0x5df9c (64 bytes) */
int _glColorMaterial_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glColorMaterial_Comp)(param_1,param_2,param_3);
  ((int (*)())_glColorMaterial_Exec)(param_1,param_2,param_3);
  return;
}

/* _glSecondaryColor3_ListExec @ 0x5dfdc (32 bytes) */
int _glSecondaryColor3_ListExec(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = *param_2;
  uVar2 = param_2[1];
  *(undefined4 *)(param_1 + 0x2c8) = param_2[2];
  *(undefined4 *)(param_1 + 0x2c0) = uVar1;
  *(undefined4 *)(param_1 + 0x2c4) = uVar2;
  return 0xc;
}

/* _glSecondaryColor3b_Exec @ 0x5dffc (136 bytes) */
int _glSecondaryColor3b_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  float fVar1;
  float fVar2;
  
  fVar2 = (float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e60 + FLOAT_00108e64;
  fVar1 = (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e60 + FLOAT_00108e64;
  *(float *)(param_1 + 0x2c0) =
       (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58) * FLOAT_00108e60
       + FLOAT_00108e64;
  *(float *)(param_1 + 0x2c8) = fVar2;
  *(float *)(param_1 + 0x2c4) = fVar1;
  return;
}

/* _glSecondaryColor3b_Comp @ 0x5e084 (204 bytes) */
int _glSecondaryColor3b_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  double dVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  
  pfVar4 = (float *)_gleAddListItem(param_1,PTR__glSecondaryColor3_ListExec_00110064,0xc);
  fVar3 = FLOAT_00108e64;
  fVar2 = FLOAT_00108e60;
  dVar1 = DOUBLE_00108d58;
  if (pfVar4 != (float *)0x0) {
    *pfVar4 = (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58) *
              FLOAT_00108e60 + FLOAT_00108e64;
    pfVar4[1] = (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - dVar1) * fVar2 + fVar3;
    pfVar4[2] = (float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - dVar1) * fVar2 + fVar3;
  }
  return pfVar4;
}

/* _glSecondaryColor3b_CompExec @ 0x5e150 (72 bytes) */
int _glSecondaryColor3b_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glSecondaryColor3b_Comp)(param_1,param_2,param_3,param_4);
  ((int (*)())_glSecondaryColor3b_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glSecondaryColor3bv_Exec @ 0x5e198 (160 bytes) */
int _glSecondaryColor3bv_Exec(param_1, param_2)
  int param_1;
  char *param_2;
{
  float fVar1;
  float fVar2;
  
  fVar2 = (float)((double)CONCAT44(0x43300000,(int)param_2[2] ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e60 + FLOAT_00108e64;
  fVar1 = (float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e60 + FLOAT_00108e64;
  *(float *)(param_1 + 0x2c0) =
       (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e60 + FLOAT_00108e64;
  *(float *)(param_1 + 0x2c8) = fVar2;
  *(float *)(param_1 + 0x2c4) = fVar1;
  return;
}

/* _glSecondaryColor3bv_Comp @ 0x5e238 (220 bytes) */
int _glSecondaryColor3bv_Comp(param_1, param_2)
  undefined4 param_1;
  char *param_2;
{
  double dVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  
  pfVar4 = (float *)_gleAddListItem(param_1,PTR__glSecondaryColor3_ListExec_00110064,0xc);
  fVar3 = FLOAT_00108e64;
  fVar2 = FLOAT_00108e60;
  dVar1 = DOUBLE_00108d58;
  if (pfVar4 != (float *)0x0) {
    *pfVar4 = (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
              FLOAT_00108e60 + FLOAT_00108e64;
    pfVar4[1] = (float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - dVar1) * fVar2 +
                fVar3;
    pfVar4[2] = (float)((double)CONCAT44(0x43300000,(int)param_2[2] ^ 0x80000000) - dVar1) * fVar2 +
                fVar3;
  }
  return pfVar4;
}

/* _glSecondaryColor3bv_CompExec @ 0x5e314 (56 bytes) */
int _glSecondaryColor3bv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glSecondaryColor3bv_Comp)(param_1,param_2);
  ((int (*)())_glSecondaryColor3bv_Exec)(param_1,param_2);
  return;
}

/* _glSecondaryColor3s_Exec @ 0x5e34c (136 bytes) */
int _glSecondaryColor3s_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  float fVar1;
  float fVar2;
  
  fVar2 = (float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e70 + FLOAT_00108e74;
  fVar1 = (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e70 + FLOAT_00108e74;
  *(float *)(param_1 + 0x2c0) =
       (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58) * FLOAT_00108e70
       + FLOAT_00108e74;
  *(float *)(param_1 + 0x2c8) = fVar2;
  *(float *)(param_1 + 0x2c4) = fVar1;
  return;
}

/* _glSecondaryColor3s_Comp @ 0x5e3d4 (204 bytes) */
int _glSecondaryColor3s_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  double dVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  
  pfVar4 = (float *)_gleAddListItem(param_1,PTR__glSecondaryColor3_ListExec_00110064,0xc);
  fVar3 = FLOAT_00108e74;
  fVar2 = FLOAT_00108e70;
  dVar1 = DOUBLE_00108d58;
  if (pfVar4 != (float *)0x0) {
    *pfVar4 = (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58) *
              FLOAT_00108e70 + FLOAT_00108e74;
    pfVar4[1] = (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - dVar1) * fVar2 + fVar3;
    pfVar4[2] = (float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - dVar1) * fVar2 + fVar3;
  }
  return pfVar4;
}

/* _glSecondaryColor3s_CompExec @ 0x5e4a0 (72 bytes) */
int _glSecondaryColor3s_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glSecondaryColor3s_Comp)(param_1,param_2,param_3,param_4);
  ((int (*)())_glSecondaryColor3s_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glSecondaryColor3sv_Exec @ 0x5e4e8 (148 bytes) */
int _glSecondaryColor3sv_Exec(param_1, param_2)
  int param_1;
  short *param_2;
{
  float fVar1;
  float fVar2;
  
  fVar2 = (float)((double)CONCAT44(0x43300000,(int)param_2[2] ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e70 + FLOAT_00108e74;
  fVar1 = (float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e70 + FLOAT_00108e74;
  *(float *)(param_1 + 0x2c0) =
       (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e70 + FLOAT_00108e74;
  *(float *)(param_1 + 0x2c8) = fVar2;
  *(float *)(param_1 + 0x2c4) = fVar1;
  return;
}

/* _glSecondaryColor3sv_Comp @ 0x5e57c (208 bytes) */
int _glSecondaryColor3sv_Comp(param_1, param_2)
  undefined4 param_1;
  short *param_2;
{
  double dVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  
  pfVar4 = (float *)_gleAddListItem(param_1,PTR__glSecondaryColor3_ListExec_00110064,0xc);
  fVar3 = FLOAT_00108e74;
  fVar2 = FLOAT_00108e70;
  dVar1 = DOUBLE_00108d58;
  if (pfVar4 != (float *)0x0) {
    *pfVar4 = (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
              FLOAT_00108e70 + FLOAT_00108e74;
    pfVar4[1] = (float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - dVar1) * fVar2 +
                fVar3;
    pfVar4[2] = (float)((double)CONCAT44(0x43300000,(int)param_2[2] ^ 0x80000000) - dVar1) * fVar2 +
                fVar3;
  }
  return pfVar4;
}

/* _glSecondaryColor3sv_CompExec @ 0x5e64c (56 bytes) */
int _glSecondaryColor3sv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glSecondaryColor3sv_Comp)(param_1,param_2);
  ((int (*)())_glSecondaryColor3sv_Exec)(param_1,param_2);
  return;
}

/* _glSecondaryColor3i_Exec @ 0x5e684 (136 bytes) */
int _glSecondaryColor3i_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  float fVar1;
  float fVar2;
  
  fVar2 = (float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e68 + FLOAT_00108e6c;
  fVar1 = (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e68 + FLOAT_00108e6c;
  *(float *)(param_1 + 0x2c0) =
       (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58) * FLOAT_00108e68
       + FLOAT_00108e6c;
  *(float *)(param_1 + 0x2c8) = fVar2;
  *(float *)(param_1 + 0x2c4) = fVar1;
  return;
}

/* _glSecondaryColor3i_Comp @ 0x5e70c (204 bytes) */
int _glSecondaryColor3i_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  double dVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  
  pfVar4 = (float *)_gleAddListItem(param_1,PTR__glSecondaryColor3_ListExec_00110064,0xc);
  fVar3 = FLOAT_00108e6c;
  fVar2 = FLOAT_00108e68;
  dVar1 = DOUBLE_00108d58;
  if (pfVar4 != (float *)0x0) {
    *pfVar4 = (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58) *
              FLOAT_00108e68 + FLOAT_00108e6c;
    pfVar4[1] = (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - dVar1) * fVar2 + fVar3;
    pfVar4[2] = (float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - dVar1) * fVar2 + fVar3;
  }
  return pfVar4;
}

/* _glSecondaryColor3i_CompExec @ 0x5e7d8 (72 bytes) */
int _glSecondaryColor3i_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glSecondaryColor3i_Comp)(param_1,param_2,param_3,param_4);
  ((int (*)())_glSecondaryColor3i_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glSecondaryColor3iv_Exec @ 0x5e820 (148 bytes) */
int _glSecondaryColor3iv_Exec(param_1, param_2)
  int param_1;
  uint *param_2;
{
  float fVar1;
  float fVar2;
  
  fVar2 = (float)((double)CONCAT44(0x43300000,param_2[2] ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e68 + FLOAT_00108e6c;
  fVar1 = (float)((double)CONCAT44(0x43300000,param_2[1] ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e68 + FLOAT_00108e6c;
  *(float *)(param_1 + 0x2c0) =
       (float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e68 + FLOAT_00108e6c;
  *(float *)(param_1 + 0x2c8) = fVar2;
  *(float *)(param_1 + 0x2c4) = fVar1;
  return;
}

/* _glSecondaryColor3iv_Comp @ 0x5e8b4 (208 bytes) */
int _glSecondaryColor3iv_Comp(param_1, param_2)
  undefined4 param_1;
  uint *param_2;
{
  double dVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  
  pfVar4 = (float *)_gleAddListItem(param_1,PTR__glSecondaryColor3_ListExec_00110064,0xc);
  fVar3 = FLOAT_00108e6c;
  fVar2 = FLOAT_00108e68;
  dVar1 = DOUBLE_00108d58;
  if (pfVar4 != (float *)0x0) {
    *pfVar4 = (float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
              FLOAT_00108e68 + FLOAT_00108e6c;
    pfVar4[1] = (float)((double)CONCAT44(0x43300000,param_2[1] ^ 0x80000000) - dVar1) * fVar2 +
                fVar3;
    pfVar4[2] = (float)((double)CONCAT44(0x43300000,param_2[2] ^ 0x80000000) - dVar1) * fVar2 +
                fVar3;
  }
  return pfVar4;
}

/* _glSecondaryColor3iv_CompExec @ 0x5e984 (56 bytes) */
int _glSecondaryColor3iv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glSecondaryColor3iv_Comp)(param_1,param_2);
  ((int (*)())_glSecondaryColor3iv_Exec)(param_1,param_2);
  return;
}

