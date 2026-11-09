#include "decls.h"

/* _glColor3s_Comp @ 0x5af7c (204 bytes) */
int _glColor3s_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  double dVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  
  pfVar4 = (float *)_gleAddListItem(param_1,PTR__glColor3_ListExec_0011005c,0xc);
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

/* _glColor3s_Exec @ 0x5b048 (196 bytes) */
int _glColor3s_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  float fVar1;
  float fVar2;
  float fVar3;
  double dVar4;
  double dVar5;
  
  fVar3 = FLOAT_00108e74;
  fVar2 = FLOAT_00108e70;
  dVar5 = (double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - DOUBLE_00108d58;
  dVar4 = (double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58;
  fVar1 = (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e70 + FLOAT_00108e74;
  *(undefined4 *)(param_1 + 0x2ac) = *(undefined4 *)(param_1 + 0x24);
  *(float *)(param_1 + 0x2a0) = fVar1;
  *(float *)(param_1 + 0x2a8) = (float)dVar5 * fVar2 + fVar3;
  *(float *)(param_1 + 0x2a4) = (float)dVar4 * fVar2 + fVar3;
  if (*(char *)(param_1 + 0x4df8) != '\0') {
    (**(code **)(param_1 + 0x4de0))(param_1,param_1 + 0x2a0);
  }
  return;
}

/* _glColor3s_CompExec @ 0x5b10c (72 bytes) */
int _glColor3s_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glColor3s_Comp)(param_1,param_2,param_3,param_4);
  ((int (*)())_glColor3s_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glColor3sv_Comp @ 0x5b154 (208 bytes) */
int _glColor3sv_Comp(param_1, param_2)
  undefined4 param_1;
  short *param_2;
{
  double dVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  
  pfVar4 = (float *)_gleAddListItem(param_1,PTR__glColor3_ListExec_0011005c,0xc);
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

/* _glColor3sv_Exec @ 0x5b224 (208 bytes) */
int _glColor3sv_Exec(param_1, param_2)
  int param_1;
  short *param_2;
{
  float fVar1;
  float fVar2;
  float fVar3;
  double dVar4;
  double dVar5;
  
  fVar3 = FLOAT_00108e74;
  fVar2 = FLOAT_00108e70;
  dVar5 = (double)CONCAT44(0x43300000,(int)param_2[2] ^ 0x80000000) - DOUBLE_00108d58;
  dVar4 = (double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - DOUBLE_00108d58;
  fVar1 = (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e70 + FLOAT_00108e74;
  *(undefined4 *)(param_1 + 0x2ac) = *(undefined4 *)(param_1 + 0x24);
  *(float *)(param_1 + 0x2a0) = fVar1;
  *(float *)(param_1 + 0x2a8) = (float)dVar5 * fVar2 + fVar3;
  *(float *)(param_1 + 0x2a4) = (float)dVar4 * fVar2 + fVar3;
  if (*(char *)(param_1 + 0x4df8) != '\0') {
    (**(code **)(param_1 + 0x4de0))(param_1,param_1 + 0x2a0);
  }
  return;
}

/* _glColor3sv_CompExec @ 0x5b2f4 (56 bytes) */
int _glColor3sv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glColor3sv_Comp)(param_1,param_2);
  ((int (*)())_glColor3sv_Exec)(param_1,param_2);
  return;
}

/* _glColor3ub_Comp @ 0x5b32c (120 bytes) */
int _glColor3ub_Comp(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x4674);
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glColor3_ListExec_0011005c,0xc);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *(undefined4 *)(iVar2 + param_2 * 4);
    puVar1[1] = *(undefined4 *)(param_3 * 4 + iVar2);
    puVar1[2] = *(undefined4 *)(iVar2 + param_4 * 4);
  }
  return puVar1;
}

/* _glColor3ub_CompExec @ 0x5b3f0 (148 bytes) */
int _glColor3ub_CompExec(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  ((int (*)())_glColor3ub_Comp)(param_1,param_2,param_3,param_4);
  iVar3 = *(int *)(param_1 + 0x4674);
  uVar1 = *(undefined4 *)(param_4 * 4 + iVar3);
  uVar2 = *(undefined4 *)(param_3 * 4 + iVar3);
  *(undefined4 *)(param_1 + 0x2a0) = *(undefined4 *)(param_2 * 4 + iVar3);
  *(undefined4 *)(param_1 + 0x2a4) = uVar2;
  *(undefined4 *)(param_1 + 0x2a8) = uVar1;
  *(undefined4 *)(param_1 + 0x2ac) = *(undefined4 *)(param_1 + 0x24);
  if (*(char *)(param_1 + 0x4df8) == '\0') {
    return;
  }
                    
                    
  (**(code **)(param_1 + 0x4de0))(param_1,param_1 + 0x2a0);
  return;
}

/* _glColor3ubv_Comp @ 0x5b438 (124 bytes) */
int _glColor3ubv_Comp(param_1, param_2)
  int param_1;
  byte *param_2;
{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x4674);
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glColor3_ListExec_0011005c,0xc);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *(undefined4 *)(iVar2 + (uint)*param_2 * 4);
    puVar1[1] = *(undefined4 *)(iVar2 + (uint)param_2[1] * 4);
    puVar1[2] = *(undefined4 *)(iVar2 + (uint)param_2[2] * 4);
  }
  return puVar1;
}

/* _glColor3ubv_Exec @ 0x5b4b4 (88 bytes) */
int _glColor3ubv_Exec(param_1, param_2)
  int param_1;
  byte *param_2;
{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x4674);
  uVar1 = *(undefined4 *)(iVar3 + (uint)param_2[2] * 4);
  uVar2 = *(undefined4 *)((uint)param_2[1] * 4 + iVar3);
  *(undefined4 *)(param_1 + 0x2a0) = *(undefined4 *)((uint)*param_2 * 4 + iVar3);
  *(undefined4 *)(param_1 + 0x2a4) = uVar2;
  *(undefined4 *)(param_1 + 0x2a8) = uVar1;
  *(undefined4 *)(param_1 + 0x2ac) = *(undefined4 *)(param_1 + 0x24);
  if (*(char *)(param_1 + 0x4df8) == '\0') {
    return;
  }
                    
                    
  (**(code **)(param_1 + 0x4de0))(param_1,param_1 + 0x2a0);
  return;
}

/* _glColor3ubv_CompExec @ 0x5b50c (56 bytes) */
int _glColor3ubv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glColor3ubv_Comp)(param_1,param_2);
  ((int (*)())_glColor3ubv_Exec)(param_1,param_2);
  return;
}

/* _glColor3ui_Comp @ 0x5b544 (184 bytes) */
int _glColor3ui_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  double dVar1;
  float fVar2;
  float *pfVar3;
  
  pfVar3 = (float *)_gleAddListItem(param_1,PTR__glColor3_ListExec_0011005c,0xc);
  fVar2 = FLOAT_00108e6c;
  dVar1 = DOUBLE_00108d70;
  if (pfVar3 != (float *)0x0) {
    *pfVar3 = (float)((double)CONCAT44(0x43300000,param_2) - DOUBLE_00108d70) * FLOAT_00108e6c;
    pfVar3[1] = (float)((double)CONCAT44(0x43300000,param_3) - dVar1) * fVar2;
    pfVar3[2] = (float)((double)CONCAT44(0x43300000,param_4) - dVar1) * fVar2;
  }
  return pfVar3;
}

/* _glColor3ui_Exec @ 0x5b5fc (176 bytes) */
int _glColor3ui_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  float fVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  
  fVar1 = FLOAT_00108e6c;
  dVar2 = (double)CONCAT44(0x43300000,param_2) - DOUBLE_00108d70;
  dVar4 = (double)CONCAT44(0x43300000,param_4) - DOUBLE_00108d70;
  dVar3 = (double)CONCAT44(0x43300000,param_3) - DOUBLE_00108d70;
  *(undefined4 *)(param_1 + 0x2ac) = *(undefined4 *)(param_1 + 0x24);
  *(float *)(param_1 + 0x2a0) = (float)dVar2 * fVar1;
  *(float *)(param_1 + 0x2a8) = (float)dVar4 * fVar1;
  *(float *)(param_1 + 0x2a4) = (float)dVar3 * fVar1;
  if (*(char *)(param_1 + 0x4df8) != '\0') {
    (**(code **)(param_1 + 0x4de0))(param_1,param_1 + 0x2a0);
  }
  return;
}

/* _glColor3ui_CompExec @ 0x5b6ac (72 bytes) */
int _glColor3ui_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glColor3ui_Comp)(param_1,param_2,param_3,param_4);
  ((int (*)())_glColor3ui_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glColor3uiv_Comp @ 0x5b6f4 (188 bytes) */
int _glColor3uiv_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  double dVar1;
  float fVar2;
  float *pfVar3;
  
  pfVar3 = (float *)_gleAddListItem(param_1,PTR__glColor3_ListExec_0011005c,0xc);
  fVar2 = FLOAT_00108e6c;
  dVar1 = DOUBLE_00108d70;
  if (pfVar3 != (float *)0x0) {
    *pfVar3 = (float)((double)CONCAT44(0x43300000,*param_2) - DOUBLE_00108d70) * FLOAT_00108e6c;
    pfVar3[1] = (float)((double)CONCAT44(0x43300000,param_2[1]) - dVar1) * fVar2;
    pfVar3[2] = (float)((double)CONCAT44(0x43300000,param_2[2]) - dVar1) * fVar2;
  }
  return pfVar3;
}

/* _glColor3uiv_Exec @ 0x5b7b0 (188 bytes) */
int _glColor3uiv_Exec(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  float fVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  
  fVar1 = FLOAT_00108e6c;
  dVar2 = (double)CONCAT44(0x43300000,*param_2) - DOUBLE_00108d70;
  dVar4 = (double)CONCAT44(0x43300000,param_2[2]) - DOUBLE_00108d70;
  dVar3 = (double)CONCAT44(0x43300000,param_2[1]) - DOUBLE_00108d70;
  *(undefined4 *)(param_1 + 0x2ac) = *(undefined4 *)(param_1 + 0x24);
  *(float *)(param_1 + 0x2a0) = (float)dVar2 * fVar1;
  *(float *)(param_1 + 0x2a8) = (float)dVar4 * fVar1;
  *(float *)(param_1 + 0x2a4) = (float)dVar3 * fVar1;
  if (*(char *)(param_1 + 0x4df8) != '\0') {
    (**(code **)(param_1 + 0x4de0))(param_1,param_1 + 0x2a0);
  }
  return;
}

/* _glColor3uiv_CompExec @ 0x5b86c (56 bytes) */
int _glColor3uiv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glColor3uiv_Comp)(param_1,param_2);
  ((int (*)())_glColor3uiv_Exec)(param_1,param_2);
  return;
}

/* _glColor3us_Comp @ 0x5b8a4 (192 bytes) */
int _glColor3us_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  float fVar1;
  float *pfVar2;
  
  pfVar2 = (float *)_gleAddListItem(param_1,PTR__glColor3_ListExec_0011005c,0xc);
  fVar1 = FLOAT_00108e74;
  if (pfVar2 != (float *)0x0) {
    *pfVar2 = (GH_U2F((unsigned int)((param_2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
    pfVar2[1] = (GH_U2F((unsigned int)((param_3 | 0x4b000000))) - 8388608.0) * fVar1;
    pfVar2[2] = (GH_U2F((unsigned int)((param_4 | 0x4b000000))) - 8388608.0) * fVar1;
  }
  return pfVar2;
}

/* _glColor3us_Exec @ 0x5b964 (184 bytes) */
double _glColor3us_Exec(int param_1,uint param_2,uint param_3,uint param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar3 = FLOAT_00108e74;
  fVar1 = (GH_U2F((unsigned int)((param_2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  fVar2 = (GH_U2F((unsigned int)((param_4 | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(undefined4 *)(param_1 + 0x2ac) = *(undefined4 *)(param_1 + 0x24);
  *(float *)(param_1 + 0x2a0) = fVar1;
  *(float *)(param_1 + 0x2a8) = fVar2;
  *(float *)(param_1 + 0x2a4) = (GH_U2F((unsigned int)((param_3 | 0x4b000000))) - 8388608.0) * fVar3;
  if (*(char *)(param_1 + 0x4df8) != '\0') {
    fparam_1 = (double)(**(double ( **)(int,int))(param_1 + 0x4de0))(param_1, param_1 + 0x2a0);
  }
  return fparam_1;
}

/* _glColor3us_CompExec @ 0x5ba1c (72 bytes) */
int _glColor3us_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, param_4, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined4 in_LR;
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glColor3us_Comp)(param_1,param_2,param_3,param_4);
  ((double (*)())_glColor3us_Exec)(param_1,param_2,param_3,param_4,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,
                   in_f8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                   (*(double *)((unsigned char *)ghidra_home + 0)),(*(double *)((unsigned char *)ghidra_home + 8)),(*(double *)((unsigned char *)ghidra_home + 16)));
  return;
}

/* _glColor3usv_Comp @ 0x5ba64 (196 bytes) */
int _glColor3usv_Comp(param_1, param_2)
  undefined4 param_1;
  ushort *param_2;
{
  float fVar1;
  float *pfVar2;
  
  pfVar2 = (float *)_gleAddListItem(param_1,PTR__glColor3_ListExec_0011005c,0xc);
  fVar1 = FLOAT_00108e74;
  if (pfVar2 != (float *)0x0) {
    *pfVar2 = (GH_U2F((unsigned int)((*param_2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
    pfVar2[1] = (GH_U2F((unsigned int)((param_2[1] | 0x4b000000))) - 8388608.0) * fVar1;
    pfVar2[2] = (GH_U2F((unsigned int)((param_2[2] | 0x4b000000))) - 8388608.0) * fVar1;
  }
  return pfVar2;
}

/* _glColor3usv_Exec @ 0x5bb28 (196 bytes) */
double _glColor3usv_Exec(int param_1,ushort *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  ushort uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar4 = FLOAT_00108e74;
  uVar1 = param_2[1];
  fVar2 = (GH_U2F((unsigned int)((*param_2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  fVar3 = (GH_U2F((unsigned int)((param_2[2] | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(undefined4 *)(param_1 + 0x2ac) = *(undefined4 *)(param_1 + 0x24);
  *(float *)(param_1 + 0x2a0) = fVar2;
  *(float *)(param_1 + 0x2a8) = fVar3;
  *(float *)(param_1 + 0x2a4) = (GH_U2F((unsigned int)((uVar1 | 0x4b000000))) - 8388608.0) * fVar4;
  if (*(char *)(param_1 + 0x4df8) != '\0') {
    fparam_1 = (double)(**(double ( **)(int,int))(param_1 + 0x4de0))(param_1, param_1 + 0x2a0);
  }
  return fparam_1;
}

/* _glColor3usv_CompExec @ 0x5bbec (56 bytes) */
int _glColor3usv_CompExec(param_1, param_2)
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
  
  ((int (*)())_glColor3usv_Comp)(param_1,param_2);
  ((double (*)())_glColor3usv_Exec)(param_1,param_2,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                    (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)((unsigned char *)ghidra_home + 0)),
                    (*(double *)((unsigned char *)ghidra_home + 8)),(*(double *)((unsigned char *)ghidra_home + 16)));
  return;
}

/* _glColor4b_Comp @ 0x5bc24 (240 bytes) */
int _glColor4b_Comp(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  uint param_2;
  uint param_3;
  uint param_4;
  uint param_5;
{
  double dVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  
  pfVar4 = (float *)_gleAddListItem(param_1,PTR__glColor4_ListExec_00110058,0x10);
  fVar3 = FLOAT_00108e64;
  fVar2 = FLOAT_00108e60;
  dVar1 = DOUBLE_00108d58;
  if (pfVar4 != (float *)0x0) {
    *pfVar4 = (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58) *
              FLOAT_00108e60 + FLOAT_00108e64;
    pfVar4[1] = (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - dVar1) * fVar2 + fVar3;
    pfVar4[2] = (float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - dVar1) * fVar2 + fVar3;
    pfVar4[3] = (float)((double)CONCAT44(0x43300000,param_5 ^ 0x80000000) - dVar1) * fVar2 + fVar3;
  }
  return pfVar4;
}

/* _glColor4b_Exec @ 0x5bd14 (216 bytes) */
int _glColor4b_Exec(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
  uint param_5;
{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar2 = (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e60 + FLOAT_00108e64;
  fVar3 = (float)((double)CONCAT44(0x43300000,param_5 ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e60 + FLOAT_00108e64;
  fVar1 = (float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e60 + FLOAT_00108e64;
  *(float *)(param_1 + 0x2a0) =
       (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58) * FLOAT_00108e60
       + FLOAT_00108e64;
  *(float *)(param_1 + 0x2a4) = fVar2;
  *(float *)(param_1 + 0x2ac) = fVar3;
  *(float *)(param_1 + 0x2a8) = fVar1;
  if (*(char *)(param_1 + 0x4df8) != '\0') {
    (**(code **)(param_1 + 0x4de0))(param_1,param_1 + 0x2a0);
  }
  return;
}

/* _glColor4b_CompExec @ 0x5bdec (80 bytes) */
int _glColor4b_CompExec(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  ((int (*)())_glColor4b_Comp)(param_1,param_2,param_3,param_4,param_5);
  ((int (*)())_glColor4b_Exec)(param_1,param_2,param_3,param_4,param_5);
  return;
}

/* _glColor4bv_Comp @ 0x5be3c (260 bytes) */
int _glColor4bv_Comp(param_1, param_2)
  undefined4 param_1;
  char *param_2;
{
  double dVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  
  pfVar4 = (float *)_gleAddListItem(param_1,PTR__glColor4_ListExec_00110058,0x10);
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
    pfVar4[3] = (float)((double)CONCAT44(0x43300000,(int)param_2[3] ^ 0x80000000) - dVar1) * fVar2 +
                fVar3;
  }
  return pfVar4;
}

/* _glColor4bv_Exec @ 0x5bf40 (248 bytes) */
int _glColor4bv_Exec(param_1, param_2)
  int param_1;
  char *param_2;
{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar2 = (float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e60 + FLOAT_00108e64;
  fVar3 = (float)((double)CONCAT44(0x43300000,(int)param_2[3] ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e60 + FLOAT_00108e64;
  fVar1 = (float)((double)CONCAT44(0x43300000,(int)param_2[2] ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e60 + FLOAT_00108e64;
  *(float *)(param_1 + 0x2a0) =
       (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e60 + FLOAT_00108e64;
  *(float *)(param_1 + 0x2a4) = fVar2;
  *(float *)(param_1 + 0x2ac) = fVar3;
  *(float *)(param_1 + 0x2a8) = fVar1;
  if (*(char *)(param_1 + 0x4df8) != '\0') {
    (**(code **)(param_1 + 0x4de0))(param_1,param_1 + 0x2a0);
  }
  return;
}

/* _glColor4bv_CompExec @ 0x5c038 (56 bytes) */
int _glColor4bv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glColor4bv_Comp)(param_1,param_2);
  ((int (*)())_glColor4bv_Exec)(param_1,param_2);
  return;
}

/* _glColor4d_Comp @ 0x5c070 (108 bytes) */
void _glColor4d_Comp(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glColor4_ListExec_00110058,0x10);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)fparam_1;
    pfVar1[1] = (float)fparam_2;
    pfVar1[2] = (float)fparam_3;
    pfVar1[3] = (float)fparam_4;
  }
  FUN_00008b68();
  return;
}

/* _glColor4d_CompExec @ 0x5c0dc (96 bytes) */
void _glColor4d_CompExec(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  ((void (*)())_glColor4d_Comp)(param_1,fparam_1,fparam_2,fparam_3,fparam_4);
  ((void (*)())_glColor4d_Exec)(param_1,fparam_1,fparam_2,fparam_3,fparam_4);
  return;
}

/* _glColor4dv_Comp @ 0x5c13c (120 bytes) */
int _glColor4dv_Comp(param_1, param_2)
  undefined4 param_1;
  double *param_2;
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glColor4_ListExec_00110058,0x10);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = GH_U2F((unsigned int)(*param_2));
    pfVar1[1] = GH_U2F((unsigned int)(param_2[1]));
    pfVar1[2] = GH_U2F((unsigned int)(param_2[2]));
    pfVar1[3] = GH_U2F((unsigned int)(param_2[3]));
  }
  return pfVar1;
}

/* _glColor4dv_Exec @ 0x5c1b4 (76 bytes) */
int _glColor4dv_Exec(param_1, param_2)
  int param_1;
  double *param_2;
{
  double dVar1;
  double dVar2;
  double dVar3;
  
  dVar1 = *param_2;
  dVar3 = param_2[1];
  dVar2 = param_2[2];
  *(float *)(param_1 + 0x2ac) = GH_U2F((unsigned int)(param_2[3]));
  *(float *)(param_1 + 0x2a0) = (float)dVar1;
  *(float *)(param_1 + 0x2a4) = (float)dVar3;
  *(float *)(param_1 + 0x2a8) = (float)dVar2;
  if (*(char *)(param_1 + 0x4df8) == '\0') {
    return;
  }
                    
                    
  (**(code **)(param_1 + 0x4de0))(param_1,param_1 + 0x2a0);
  return;
}

/* _glColor4dv_CompExec @ 0x5c200 (56 bytes) */
int _glColor4dv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glColor4dv_Comp)(param_1,param_2);
  ((int (*)())_glColor4dv_Exec)(param_1,param_2);
  return;
}

/* _glColor4f_ColorMat_Exec @ 0x5c238 (32 bytes) */
void _glColor4f_ColorMat_Exec(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  *(float *)(param_1 + 0x2a0) = (float)fparam_1;
  *(float *)(param_1 + 0x2a4) = (float)fparam_2;
  *(float *)(param_1 + 0x2a8) = (float)fparam_3;
  *(float *)(param_1 + 0x2ac) = (float)fparam_4;
                    
                    
  (**(code **)(param_1 + 0x4de0))(param_1,param_1 + 0x2a0);
  return;
}

/* _glColor4fv_Comp @ 0x5c258 (104 bytes) */
int _glColor4fv_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glColor4_ListExec_00110058,0x10);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_2;
    puVar1[1] = param_2[1];
    puVar1[2] = param_2[2];
    puVar1[3] = param_2[3];
  }
  return puVar1;
}

/* _glColor4fv_ColorMat_Exec @ 0x5c2c0 (48 bytes) */
int _glColor4fv_ColorMat_Exec(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = param_2[3];
  uVar2 = param_2[1];
  uVar3 = param_2[2];
  *(undefined4 *)(param_1 + 0x2a0) = *param_2;
  *(undefined4 *)(param_1 + 0x2a4) = uVar2;
  *(undefined4 *)(param_1 + 0x2a8) = uVar3;
  *(undefined4 *)(param_1 + 0x2ac) = uVar1;
                    
                    
  (**(code **)(param_1 + 0x4de0))(param_1,param_1 + 0x2a0);
  return;
}

/* _glColor4fv_CompExec @ 0x5c2f0 (96 bytes) */
int _glColor4fv_CompExec(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  ((int (*)())_glColor4fv_Comp)(param_1,param_2);
  if (*(char *)(param_1 + 0x4df8) != '\0') {
    ((int (*)())_glColor4fv_ColorMat_Exec)(param_1,param_2);
    return;
  }
  _glColor4fv_NoColorMat_Exec(param_1,param_2);
  return;
}

/* _glColor4i_Comp @ 0x5c350 (240 bytes) */
int _glColor4i_Comp(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  uint param_2;
  uint param_3;
  uint param_4;
  uint param_5;
{
  double dVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  
  pfVar4 = (float *)_gleAddListItem(param_1,PTR__glColor4_ListExec_00110058,0x10);
  fVar3 = FLOAT_00108e6c;
  fVar2 = FLOAT_00108e68;
  dVar1 = DOUBLE_00108d58;
  if (pfVar4 != (float *)0x0) {
    *pfVar4 = (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58) *
              FLOAT_00108e68 + FLOAT_00108e6c;
    pfVar4[1] = (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - dVar1) * fVar2 + fVar3;
    pfVar4[2] = (float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - dVar1) * fVar2 + fVar3;
    pfVar4[3] = (float)((double)CONCAT44(0x43300000,param_5 ^ 0x80000000) - dVar1) * fVar2 + fVar3;
  }
  return pfVar4;
}

/* _glColor4i_Exec @ 0x5c440 (216 bytes) */
int _glColor4i_Exec(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
  uint param_5;
{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar2 = (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e68 + FLOAT_00108e6c;
  fVar3 = (float)((double)CONCAT44(0x43300000,param_5 ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e68 + FLOAT_00108e6c;
  fVar1 = (float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e68 + FLOAT_00108e6c;
  *(float *)(param_1 + 0x2a0) =
       (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58) * FLOAT_00108e68
       + FLOAT_00108e6c;
  *(float *)(param_1 + 0x2a4) = fVar2;
  *(float *)(param_1 + 0x2ac) = fVar3;
  *(float *)(param_1 + 0x2a8) = fVar1;
  if (*(char *)(param_1 + 0x4df8) != '\0') {
    (**(code **)(param_1 + 0x4de0))(param_1,param_1 + 0x2a0);
  }
  return;
}

/* _glColor4i_CompExec @ 0x5c518 (80 bytes) */
int _glColor4i_CompExec(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  ((int (*)())_glColor4i_Comp)(param_1,param_2,param_3,param_4,param_5);
  ((int (*)())_glColor4i_Exec)(param_1,param_2,param_3,param_4,param_5);
  return;
}

/* _glColor4iv_Comp @ 0x5c568 (244 bytes) */
int _glColor4iv_Comp(param_1, param_2)
  undefined4 param_1;
  uint *param_2;
{
  double dVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  
  pfVar4 = (float *)_gleAddListItem(param_1,PTR__glColor4_ListExec_00110058,0x10);
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
    pfVar4[3] = (float)((double)CONCAT44(0x43300000,param_2[3] ^ 0x80000000) - dVar1) * fVar2 +
                fVar3;
  }
  return pfVar4;
}

/* _glColor4iv_Exec @ 0x5c65c (232 bytes) */
int _glColor4iv_Exec(param_1, param_2)
  int param_1;
  uint *param_2;
{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar2 = (float)((double)CONCAT44(0x43300000,param_2[1] ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e68 + FLOAT_00108e6c;
  fVar3 = (float)((double)CONCAT44(0x43300000,param_2[3] ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e68 + FLOAT_00108e6c;
  fVar1 = (float)((double)CONCAT44(0x43300000,param_2[2] ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e68 + FLOAT_00108e6c;
  *(float *)(param_1 + 0x2a0) =
       (float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e68 + FLOAT_00108e6c;
  *(float *)(param_1 + 0x2a4) = fVar2;
  *(float *)(param_1 + 0x2ac) = fVar3;
  *(float *)(param_1 + 0x2a8) = fVar1;
  if (*(char *)(param_1 + 0x4df8) != '\0') {
    (**(code **)(param_1 + 0x4de0))(param_1,param_1 + 0x2a0);
  }
  return;
}

/* _glColor4iv_CompExec @ 0x5c744 (56 bytes) */
int _glColor4iv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glColor4iv_Comp)(param_1,param_2);
  ((int (*)())_glColor4iv_Exec)(param_1,param_2);
  return;
}

/* _glColor4s_Comp @ 0x5c77c (240 bytes) */
int _glColor4s_Comp(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  uint param_2;
  uint param_3;
  uint param_4;
  uint param_5;
{
  double dVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  
  pfVar4 = (float *)_gleAddListItem(param_1,PTR__glColor4_ListExec_00110058,0x10);
  fVar3 = FLOAT_00108e74;
  fVar2 = FLOAT_00108e70;
  dVar1 = DOUBLE_00108d58;
  if (pfVar4 != (float *)0x0) {
    *pfVar4 = (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58) *
              FLOAT_00108e70 + FLOAT_00108e74;
    pfVar4[1] = (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - dVar1) * fVar2 + fVar3;
    pfVar4[2] = (float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - dVar1) * fVar2 + fVar3;
    pfVar4[3] = (float)((double)CONCAT44(0x43300000,param_5 ^ 0x80000000) - dVar1) * fVar2 + fVar3;
  }
  return pfVar4;
}

/* _glColor4s_Exec @ 0x5c86c (216 bytes) */
int _glColor4s_Exec(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
  uint param_5;
{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar2 = (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e70 + FLOAT_00108e74;
  fVar3 = (float)((double)CONCAT44(0x43300000,param_5 ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e70 + FLOAT_00108e74;
  fVar1 = (float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e70 + FLOAT_00108e74;
  *(float *)(param_1 + 0x2a0) =
       (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58) * FLOAT_00108e70
       + FLOAT_00108e74;
  *(float *)(param_1 + 0x2a4) = fVar2;
  *(float *)(param_1 + 0x2ac) = fVar3;
  *(float *)(param_1 + 0x2a8) = fVar1;
  if (*(char *)(param_1 + 0x4df8) != '\0') {
    (**(code **)(param_1 + 0x4de0))(param_1,param_1 + 0x2a0);
  }
  return;
}

/* _glColor4s_CompExec @ 0x5c944 (80 bytes) */
int _glColor4s_CompExec(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  ((int (*)())_glColor4s_Comp)(param_1,param_2,param_3,param_4,param_5);
  ((int (*)())_glColor4s_Exec)(param_1,param_2,param_3,param_4,param_5);
  return;
}

/* _glColor4sv_Comp @ 0x5c994 (244 bytes) */
int _glColor4sv_Comp(param_1, param_2)
  undefined4 param_1;
  short *param_2;
{
  double dVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  
  pfVar4 = (float *)_gleAddListItem(param_1,PTR__glColor4_ListExec_00110058,0x10);
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
    pfVar4[3] = (float)((double)CONCAT44(0x43300000,(int)param_2[3] ^ 0x80000000) - dVar1) * fVar2 +
                fVar3;
  }
  return pfVar4;
}

/* _glColor4sv_Exec @ 0x5ca88 (232 bytes) */
int _glColor4sv_Exec(param_1, param_2)
  int param_1;
  short *param_2;
{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar2 = (float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e70 + FLOAT_00108e74;
  fVar3 = (float)((double)CONCAT44(0x43300000,(int)param_2[3] ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e70 + FLOAT_00108e74;
  fVar1 = (float)((double)CONCAT44(0x43300000,(int)param_2[2] ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e70 + FLOAT_00108e74;
  *(float *)(param_1 + 0x2a0) =
       (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e70 + FLOAT_00108e74;
  *(float *)(param_1 + 0x2a4) = fVar2;
  *(float *)(param_1 + 0x2ac) = fVar3;
  *(float *)(param_1 + 0x2a8) = fVar1;
  if (*(char *)(param_1 + 0x4df8) != '\0') {
    (**(code **)(param_1 + 0x4de0))(param_1,param_1 + 0x2a0);
  }
  return;
}

/* _glColor4sv_CompExec @ 0x5cb70 (56 bytes) */
int _glColor4sv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glColor4sv_Comp)(param_1,param_2);
  ((int (*)())_glColor4sv_Exec)(param_1,param_2);
  return;
}

/* _glColor4ub_Comp @ 0x5cba8 (136 bytes) */
int _glColor4ub_Comp(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x4674);
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glColor4_ListExec_00110058,0x10);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *(undefined4 *)(iVar2 + param_2 * 4);
    puVar1[1] = *(undefined4 *)(param_3 * 4 + iVar2);
    puVar1[2] = *(undefined4 *)(iVar2 + param_4 * 4);
    puVar1[3] = *(undefined4 *)(param_5 * 4 + iVar2);
  }
  return puVar1;
}

/* _glColor4ub_CompExec @ 0x5cc30 (80 bytes) */
int _glColor4ub_CompExec(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  ((int (*)())_glColor4ub_Comp)(param_1,param_2,param_3,param_4,param_5);
  _glColor4ub_Exec(param_1,param_2,param_3,param_4,param_5);
  return;
}

/* _glColor4ubv_Comp @ 0x5cc80 (140 bytes) */
int _glColor4ubv_Comp(param_1, param_2)
  int param_1;
  byte *param_2;
{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x4674);
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glColor4_ListExec_00110058,0x10);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *(undefined4 *)(iVar2 + (uint)*param_2 * 4);
    puVar1[1] = *(undefined4 *)(iVar2 + (uint)param_2[1] * 4);
    puVar1[2] = *(undefined4 *)(iVar2 + (uint)param_2[2] * 4);
    puVar1[3] = *(undefined4 *)(iVar2 + (uint)param_2[3] * 4);
  }
  return puVar1;
}

/* _glColor4ubv_Exec @ 0x5cd0c (96 bytes) */
int _glColor4ubv_Exec(param_1, param_2)
  int param_1;
  byte *param_2;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x4674);
  uVar1 = *(undefined4 *)(iVar4 + (uint)param_2[3] * 4);
  uVar2 = *(undefined4 *)((uint)param_2[1] * 4 + iVar4);
  uVar3 = *(undefined4 *)((uint)param_2[2] * 4 + iVar4);
  *(undefined4 *)(param_1 + 0x2a0) = *(undefined4 *)((uint)*param_2 * 4 + iVar4);
  *(undefined4 *)(param_1 + 0x2a4) = uVar2;
  *(undefined4 *)(param_1 + 0x2a8) = uVar3;
  *(undefined4 *)(param_1 + 0x2ac) = uVar1;
  if (*(char *)(param_1 + 0x4df8) == '\0') {
    return;
  }
                    
                    
  (**(code **)(param_1 + 0x4de0))(param_1,param_1 + 0x2a0);
  return;
}

/* _glColor4ubv_CompExec @ 0x5cd6c (56 bytes) */
int _glColor4ubv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glColor4ubv_Comp)(param_1,param_2);
  ((int (*)())_glColor4ubv_Exec)(param_1,param_2);
  return;
}

/* _glColor4ui_Comp @ 0x5cda4 (216 bytes) */
int _glColor4ui_Comp(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  double dVar1;
  float fVar2;
  float *pfVar3;
  
  pfVar3 = (float *)_gleAddListItem(param_1,PTR__glColor4_ListExec_00110058,0x10);
  fVar2 = FLOAT_00108e6c;
  dVar1 = DOUBLE_00108d70;
  if (pfVar3 != (float *)0x0) {
    *pfVar3 = (float)((double)CONCAT44(0x43300000,param_2) - DOUBLE_00108d70) * FLOAT_00108e6c;
    pfVar3[1] = (float)((double)CONCAT44(0x43300000,param_3) - dVar1) * fVar2;
    pfVar3[2] = (float)((double)CONCAT44(0x43300000,param_4) - dVar1) * fVar2;
    pfVar3[3] = (float)((double)CONCAT44(0x43300000,param_5) - dVar1) * fVar2;
  }
  return pfVar3;
}

/* _glColor4ui_Exec @ 0x5ce7c (192 bytes) */
int _glColor4ui_Exec(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = (float)((double)CONCAT44(0x43300000,param_3) - DOUBLE_00108d70) * FLOAT_00108e6c;
  fVar2 = (float)((double)CONCAT44(0x43300000,param_5) - DOUBLE_00108d70) * FLOAT_00108e6c;
  fVar3 = (float)((double)CONCAT44(0x43300000,param_4) - DOUBLE_00108d70) * FLOAT_00108e6c;
  *(float *)(param_1 + 0x2a0) =
       (float)((double)CONCAT44(0x43300000,param_2) - DOUBLE_00108d70) * FLOAT_00108e6c;
  *(float *)(param_1 + 0x2a4) = fVar1;
  *(float *)(param_1 + 0x2ac) = fVar2;
  *(float *)(param_1 + 0x2a8) = fVar3;
  if (*(char *)(param_1 + 0x4df8) != '\0') {
    (**(code **)(param_1 + 0x4de0))(param_1,param_1 + 0x2a0);
  }
  return;
}

/* _glColor4ui_CompExec @ 0x5cf3c (80 bytes) */
int _glColor4ui_CompExec(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  ((int (*)())_glColor4ui_Comp)(param_1,param_2,param_3,param_4,param_5);
  ((int (*)())_glColor4ui_Exec)(param_1,param_2,param_3,param_4,param_5);
  return;
}

/* _glColor4uiv_Comp @ 0x5cf8c (220 bytes) */
int _glColor4uiv_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  double dVar1;
  float fVar2;
  float *pfVar3;
  
  pfVar3 = (float *)_gleAddListItem(param_1,PTR__glColor4_ListExec_00110058,0x10);
  fVar2 = FLOAT_00108e6c;
  dVar1 = DOUBLE_00108d70;
  if (pfVar3 != (float *)0x0) {
    *pfVar3 = (float)((double)CONCAT44(0x43300000,*param_2) - DOUBLE_00108d70) * FLOAT_00108e6c;
    pfVar3[1] = (float)((double)CONCAT44(0x43300000,param_2[1]) - dVar1) * fVar2;
    pfVar3[2] = (float)((double)CONCAT44(0x43300000,param_2[2]) - dVar1) * fVar2;
    pfVar3[3] = (float)((double)CONCAT44(0x43300000,param_2[3]) - dVar1) * fVar2;
  }
  return pfVar3;
}

/* _glColor4uiv_Exec @ 0x5d068 (208 bytes) */
int _glColor4uiv_Exec(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = (float)((double)CONCAT44(0x43300000,param_2[1]) - DOUBLE_00108d70) * FLOAT_00108e6c;
  fVar2 = (float)((double)CONCAT44(0x43300000,param_2[3]) - DOUBLE_00108d70) * FLOAT_00108e6c;
  fVar3 = (float)((double)CONCAT44(0x43300000,param_2[2]) - DOUBLE_00108d70) * FLOAT_00108e6c;
  *(float *)(param_1 + 0x2a0) =
       (float)((double)CONCAT44(0x43300000,*param_2) - DOUBLE_00108d70) * FLOAT_00108e6c;
  *(float *)(param_1 + 0x2a4) = fVar1;
  *(float *)(param_1 + 0x2ac) = fVar2;
  *(float *)(param_1 + 0x2a8) = fVar3;
  if (*(char *)(param_1 + 0x4df8) != '\0') {
    (**(code **)(param_1 + 0x4de0))(param_1,param_1 + 0x2a0);
  }
  return;
}

