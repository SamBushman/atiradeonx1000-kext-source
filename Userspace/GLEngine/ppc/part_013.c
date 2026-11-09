#include "decls.h"

/* _glSecondaryColor3f_Exec @ 0x5e9bc (16 bytes) */
void _glSecondaryColor3f_Exec(int param_1,double fparam_1,double fparam_2,double fparam_3)
{
  *(float *)(param_1 + 0x2c8) = (float)fparam_3;
  *(float *)(param_1 + 0x2c0) = (float)fparam_1;
  *(float *)(param_1 + 0x2c4) = (float)fparam_2;
  return;
}

/* _glSecondaryColor3f_Comp @ 0x5e9cc (116 bytes) */
float * _glSecondaryColor3f_Comp(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3)
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glSecondaryColor3_ListExec_00110064,0xc);
  if (pfVar1 != (float *)0x0) {
    pfVar1[2] = (float)fparam_3;
    *pfVar1 = (float)fparam_1;
    pfVar1[1] = (float)fparam_2;
  }
  return pfVar1;
}

/* _glSecondaryColor3f_CompExec @ 0x5ea40 (96 bytes) */
void _glSecondaryColor3f_CompExec(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3)
{
  ((float * (*)())_glSecondaryColor3f_Comp)(param_1,fparam_1,fparam_2,fparam_3);
  ((void (*)())_glSecondaryColor3f_Exec)(param_1,fparam_1,fparam_2,fparam_3);
  return;
}

/* _glSecondaryColor3fv_Exec @ 0x5eaa0 (28 bytes) */
int _glSecondaryColor3fv_Exec(param_1, param_2)
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
  return;
}

/* _glSecondaryColor3fv_Comp @ 0x5eabc (96 bytes) */
int _glSecondaryColor3fv_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glSecondaryColor3_ListExec_00110064,0xc);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_2;
    puVar1[1] = param_2[1];
    puVar1[2] = param_2[2];
  }
  return puVar1;
}

/* _glSecondaryColor3fv_CompExec @ 0x5eb1c (56 bytes) */
int _glSecondaryColor3fv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glSecondaryColor3fv_Comp)(param_1,param_2);
  ((int (*)())_glSecondaryColor3fv_Exec)(param_1,param_2);
  return;
}

/* _glSecondaryColor3d_Exec @ 0x5eb54 (28 bytes) */
void _glSecondaryColor3d_Exec(int param_1,double fparam_1,double fparam_2,double fparam_3)
{
  *(float *)(param_1 + 0x2c0) = (float)fparam_1;
  *(float *)(param_1 + 0x2c4) = (float)fparam_2;
  *(float *)(param_1 + 0x2c8) = (float)fparam_3;
  return;
}

/* _glSecondaryColor3d_Comp @ 0x5eb70 (128 bytes) */
float * _glSecondaryColor3d_Comp(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3)
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glSecondaryColor3_ListExec_00110064,0xc);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)fparam_1;
    pfVar1[1] = (float)fparam_2;
    pfVar1[2] = (float)fparam_3;
  }
  return pfVar1;
}

/* _glSecondaryColor3d_CompExec @ 0x5ebf0 (96 bytes) */
void _glSecondaryColor3d_CompExec(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3)
{
  ((float * (*)())_glSecondaryColor3d_Comp)(param_1,fparam_1,fparam_2,fparam_3);
  ((void (*)())_glSecondaryColor3d_Exec)(param_1,fparam_1,fparam_2,fparam_3);
  return;
}

/* _glSecondaryColor3dv_Exec @ 0x5ec50 (40 bytes) */
int _glSecondaryColor3dv_Exec(param_1, param_2)
  int param_1;
  double *param_2;
{
  double dVar1;
  double dVar2;
  
  dVar1 = *param_2;
  dVar2 = param_2[1];
  *(float *)(param_1 + 0x2c8) = GH_U2F((unsigned int)(param_2[2]));
  *(float *)(param_1 + 0x2c0) = (float)dVar1;
  *(float *)(param_1 + 0x2c4) = (float)dVar2;
  return;
}

/* _glSecondaryColor3dv_Comp @ 0x5ec78 (108 bytes) */
int _glSecondaryColor3dv_Comp(param_1, param_2)
  undefined4 param_1;
  double *param_2;
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glSecondaryColor3_ListExec_00110064,0xc);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = GH_U2F((unsigned int)(*param_2));
    pfVar1[1] = GH_U2F((unsigned int)(param_2[1]));
    pfVar1[2] = GH_U2F((unsigned int)(param_2[2]));
  }
  return pfVar1;
}

/* _glSecondaryColor3dv_CompExec @ 0x5ece4 (56 bytes) */
int _glSecondaryColor3dv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glSecondaryColor3dv_Comp)(param_1,param_2);
  ((int (*)())_glSecondaryColor3dv_Exec)(param_1,param_2);
  return;
}

/* _glSecondaryColor3ub_Exec @ 0x5ed1c (120 bytes) */
int _glSecondaryColor3ub_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  float fVar1;
  float fVar2;
  
  fVar1 = (GH_U2F((unsigned int)((param_4 | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  fVar2 = (GH_U2F((unsigned int)((param_3 | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  *(float *)(param_1 + 0x2c0) = (GH_U2F((unsigned int)((param_2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  *(float *)(param_1 + 0x2c8) = fVar1;
  *(float *)(param_1 + 0x2c4) = fVar2;
  return;
}

/* _glSecondaryColor3ub_Comp @ 0x5ed94 (192 bytes) */
int _glSecondaryColor3ub_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  float fVar1;
  float *pfVar2;
  
  pfVar2 = (float *)_gleAddListItem(param_1,PTR__glSecondaryColor3_ListExec_00110064,0xc);
  fVar1 = FLOAT_00108e78;
  if (pfVar2 != (float *)0x0) {
    *pfVar2 = (GH_U2F((unsigned int)((param_2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
    pfVar2[1] = (GH_U2F((unsigned int)((param_3 | 0x4b000000))) - 8388608.0) * fVar1;
    pfVar2[2] = (GH_U2F((unsigned int)((param_4 | 0x4b000000))) - 8388608.0) * fVar1;
  }
  return pfVar2;
}

/* _glSecondaryColor3ub_CompExec @ 0x5ee54 (72 bytes) */
int _glSecondaryColor3ub_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glSecondaryColor3ub_Comp)(param_1,param_2,param_3,param_4);
  ((int (*)())_glSecondaryColor3ub_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glSecondaryColor3ubv_Exec @ 0x5ee9c (132 bytes) */
int _glSecondaryColor3ubv_Exec(param_1, param_2)
  int param_1;
  byte *param_2;
{
  float fVar1;
  float fVar2;
  
  fVar1 = (GH_U2F((unsigned int)((param_2[2] | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  fVar2 = (GH_U2F((unsigned int)((param_2[1] | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  *(float *)(param_1 + 0x2c0) = (GH_U2F((unsigned int)((*param_2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  *(float *)(param_1 + 0x2c8) = fVar1;
  *(float *)(param_1 + 0x2c4) = fVar2;
  return;
}

/* _glSecondaryColor3ubv_Comp @ 0x5ef20 (196 bytes) */
int _glSecondaryColor3ubv_Comp(param_1, param_2)
  undefined4 param_1;
  byte *param_2;
{
  float fVar1;
  float *pfVar2;
  
  pfVar2 = (float *)_gleAddListItem(param_1,PTR__glSecondaryColor3_ListExec_00110064,0xc);
  fVar1 = FLOAT_00108e78;
  if (pfVar2 != (float *)0x0) {
    *pfVar2 = (GH_U2F((unsigned int)((*param_2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
    pfVar2[1] = (GH_U2F((unsigned int)((param_2[1] | 0x4b000000))) - 8388608.0) * fVar1;
    pfVar2[2] = (GH_U2F((unsigned int)((param_2[2] | 0x4b000000))) - 8388608.0) * fVar1;
  }
  return pfVar2;
}

/* _glSecondaryColor3ubv_CompExec @ 0x5efe4 (56 bytes) */
int _glSecondaryColor3ubv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glSecondaryColor3ubv_Comp)(param_1,param_2);
  ((int (*)())_glSecondaryColor3ubv_Exec)(param_1,param_2);
  return;
}

/* _glSecondaryColor3us_Exec @ 0x5f01c (120 bytes) */
int _glSecondaryColor3us_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  float fVar1;
  float fVar2;
  
  fVar1 = (GH_U2F((unsigned int)((param_4 | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  fVar2 = (GH_U2F((unsigned int)((param_3 | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(float *)(param_1 + 0x2c0) = (GH_U2F((unsigned int)((param_2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(float *)(param_1 + 0x2c8) = fVar1;
  *(float *)(param_1 + 0x2c4) = fVar2;
  return;
}

/* _glSecondaryColor3us_Comp @ 0x5f094 (192 bytes) */
int _glSecondaryColor3us_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  float fVar1;
  float *pfVar2;
  
  pfVar2 = (float *)_gleAddListItem(param_1,PTR__glSecondaryColor3_ListExec_00110064,0xc);
  fVar1 = FLOAT_00108e74;
  if (pfVar2 != (float *)0x0) {
    *pfVar2 = (GH_U2F((unsigned int)((param_2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
    pfVar2[1] = (GH_U2F((unsigned int)((param_3 | 0x4b000000))) - 8388608.0) * fVar1;
    pfVar2[2] = (GH_U2F((unsigned int)((param_4 | 0x4b000000))) - 8388608.0) * fVar1;
  }
  return pfVar2;
}

/* _glSecondaryColor3us_CompExec @ 0x5f154 (72 bytes) */
int _glSecondaryColor3us_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glSecondaryColor3us_Comp)(param_1,param_2,param_3,param_4);
  ((int (*)())_glSecondaryColor3us_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glSecondaryColor3usv_Exec @ 0x5f19c (132 bytes) */
int _glSecondaryColor3usv_Exec(param_1, param_2)
  int param_1;
  ushort *param_2;
{
  float fVar1;
  float fVar2;
  
  fVar1 = (GH_U2F((unsigned int)((param_2[2] | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  fVar2 = (GH_U2F((unsigned int)((param_2[1] | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(float *)(param_1 + 0x2c0) = (GH_U2F((unsigned int)((*param_2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(float *)(param_1 + 0x2c8) = fVar1;
  *(float *)(param_1 + 0x2c4) = fVar2;
  return;
}

/* _glSecondaryColor3usv_Comp @ 0x5f220 (196 bytes) */
int _glSecondaryColor3usv_Comp(param_1, param_2)
  undefined4 param_1;
  ushort *param_2;
{
  float fVar1;
  float *pfVar2;
  
  pfVar2 = (float *)_gleAddListItem(param_1,PTR__glSecondaryColor3_ListExec_00110064,0xc);
  fVar1 = FLOAT_00108e74;
  if (pfVar2 != (float *)0x0) {
    *pfVar2 = (GH_U2F((unsigned int)((*param_2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
    pfVar2[1] = (GH_U2F((unsigned int)((param_2[1] | 0x4b000000))) - 8388608.0) * fVar1;
    pfVar2[2] = (GH_U2F((unsigned int)((param_2[2] | 0x4b000000))) - 8388608.0) * fVar1;
  }
  return pfVar2;
}

/* _glSecondaryColor3usv_CompExec @ 0x5f2e4 (56 bytes) */
int _glSecondaryColor3usv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glSecondaryColor3usv_Comp)(param_1,param_2);
  ((int (*)())_glSecondaryColor3usv_Exec)(param_1,param_2);
  return;
}

/* _glSecondaryColor3ui_Exec @ 0x5f31c (116 bytes) */
int _glSecondaryColor3ui_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)((double)CONCAT44(0x43300000,param_4) - DOUBLE_00108d70) * FLOAT_00108e6c;
  fVar2 = (float)((double)CONCAT44(0x43300000,param_3) - DOUBLE_00108d70) * FLOAT_00108e6c;
  *(float *)(param_1 + 0x2c0) =
       (float)((double)CONCAT44(0x43300000,param_2) - DOUBLE_00108d70) * FLOAT_00108e6c;
  *(float *)(param_1 + 0x2c8) = fVar1;
  *(float *)(param_1 + 0x2c4) = fVar2;
  return;
}

/* _glSecondaryColor3ui_Comp @ 0x5f390 (184 bytes) */
int _glSecondaryColor3ui_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  double dVar1;
  float fVar2;
  float *pfVar3;
  
  pfVar3 = (float *)_gleAddListItem(param_1,PTR__glSecondaryColor3_ListExec_00110064,0xc);
  fVar2 = FLOAT_00108e6c;
  dVar1 = DOUBLE_00108d70;
  if (pfVar3 != (float *)0x0) {
    *pfVar3 = (float)((double)CONCAT44(0x43300000,param_2) - DOUBLE_00108d70) * FLOAT_00108e6c;
    pfVar3[1] = (float)((double)CONCAT44(0x43300000,param_3) - dVar1) * fVar2;
    pfVar3[2] = (float)((double)CONCAT44(0x43300000,param_4) - dVar1) * fVar2;
  }
  return pfVar3;
}

/* _glSecondaryColor3ui_CompExec @ 0x5f448 (72 bytes) */
int _glSecondaryColor3ui_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glSecondaryColor3ui_Comp)(param_1,param_2,param_3,param_4);
  ((int (*)())_glSecondaryColor3ui_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glSecondaryColor3uiv_Exec @ 0x5f490 (128 bytes) */
int _glSecondaryColor3uiv_Exec(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)((double)CONCAT44(0x43300000,param_2[2]) - DOUBLE_00108d70) * FLOAT_00108e6c;
  fVar2 = (float)((double)CONCAT44(0x43300000,param_2[1]) - DOUBLE_00108d70) * FLOAT_00108e6c;
  *(float *)(param_1 + 0x2c0) =
       (float)((double)CONCAT44(0x43300000,*param_2) - DOUBLE_00108d70) * FLOAT_00108e6c;
  *(float *)(param_1 + 0x2c8) = fVar1;
  *(float *)(param_1 + 0x2c4) = fVar2;
  return;
}

/* _glSecondaryColor3uiv_Comp @ 0x5f510 (188 bytes) */
int _glSecondaryColor3uiv_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  double dVar1;
  float fVar2;
  float *pfVar3;
  
  pfVar3 = (float *)_gleAddListItem(param_1,PTR__glSecondaryColor3_ListExec_00110064,0xc);
  fVar2 = FLOAT_00108e6c;
  dVar1 = DOUBLE_00108d70;
  if (pfVar3 != (float *)0x0) {
    *pfVar3 = (float)((double)CONCAT44(0x43300000,*param_2) - DOUBLE_00108d70) * FLOAT_00108e6c;
    pfVar3[1] = (float)((double)CONCAT44(0x43300000,param_2[1]) - dVar1) * fVar2;
    pfVar3[2] = (float)((double)CONCAT44(0x43300000,param_2[2]) - dVar1) * fVar2;
  }
  return pfVar3;
}

/* _glSecondaryColor3uiv_CompExec @ 0x5f5cc (56 bytes) */
int _glSecondaryColor3uiv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glSecondaryColor3uiv_Comp)(param_1,param_2);
  ((int (*)())_glSecondaryColor3uiv_Exec)(param_1,param_2);
  return;
}

/* _glColorTable_ListExec @ 0x5f604 (644 bytes) */
int _glColorTable_ListExec(param_1, param_2)
  int param_1;
  uint *param_2;
{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  int iVar9;
  int iVar10;
  
  iVar7 = param_2[5] + 0x18;
  iVar5 = _gleCheckColorTableArgs(param_1,*param_2,param_2[1],param_2[2],param_2[3],param_2[4]);
  if (iVar5 != 0) {
    uVar2 = *(ushort *)(iVar5 + 0x24);
    if ((uVar2 & 0x3c00) != 0x1000) {
      if ((uVar2 & 0x3c00) == 0) {
        *(ushort *)(iVar5 + 0x24) = uVar2 | 0x1000;
      }
      else if ((uVar2 & 0xc00) != 0) {
        if (*(int *)(param_1 + 0x7574) != 0) {
          return iVar7;
        }
        *(undefined4 *)(param_1 + 0x7574) = 0x502;
        return iVar7;
      }
    }
    iVar10 = iVar5 + 0xac;
    if ((*(byte *)(iVar5 + 0xb7) & 0x20) != 0) {
      _gleDeletePluginTextureLevel(param_1,iVar5,iVar10,0,0xffffffff);
      if (*(int *)(iVar5 + 0xc0) != 0) {
        bVar1 = *(byte *)(iVar5 + 0xb7);
        if ((bVar1 & 1) == 0) {
          _gleFreeTextureLevel(param_1,iVar5,iVar10);
          bVar1 = *(byte *)(iVar5 + 0xb7);
        }
        else {
          *(undefined4 *)(iVar5 + 0xc0) = 0;
        }
        *(byte *)(iVar5 + 0xb7) = bVar1 & 0xef;
      }
      *(byte *)(iVar5 + 0xb7) = *(byte *)(iVar5 + 0xb7) & 0xdf;
    }
    uVar4 = *param_2;
    iVar9 = param_1 + 0x33d0;
    if (uVar4 != 0x80d1) {
      if (uVar4 < 0x80d2) {
        iVar9 = param_1 + 0x33b0;
        uVar3 = 0x80d0;
      }
      else {
        iVar9 = param_1 + 0x33f0;
        uVar3 = 0x80d2;
      }
      if (uVar4 != uVar3) {
        iVar9 = 0;
      }
    }
    puVar8 = param_2 + 6;
    if (iVar9 == 0) {
      iVar9 = _gleCreateTextureLevel
                        (param_1,iVar5,iVar10,param_2[1],param_2[2],1,1,0,param_2[3],param_2[4],0,
                         puVar8);
      if (iVar9 != 0) {
        _gleTextureImagePut(param_1,iVar10,0,0,0,param_2[2],1,1,param_2[3],param_2[4],0,0,puVar8);
      }
      *(uint *)(param_1 + 0x314) =
           *(uint *)(param_1 + 0x314) | 1 << (*(uint *)(param_1 + 0x53d4) & 0x3f);
    }
    else {
      iVar6 = _gleCreateColorTableLevel
                        (param_1,iVar5,iVar10,param_2[1],param_2[2],param_2[3],param_2[4],puVar8);
      if ((iVar6 != 0) && (puVar8 != (uint *)0x0)) {
        _gleColorTable(param_1,iVar9,iVar10,param_2[2],param_2[3],param_2[4],puVar8);
      }
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x40000000;
    }
    _gleCreatePluginTextureLevel(param_1,iVar5,iVar10,0,0xffffffff,param_2[1]);
  }
  return iVar7;
}

/* _glColorTable_Comp @ 0x5f888 (840 bytes) */
int _glColorTable_Comp(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
  uint param_5;
  uint param_6;
  int param_7;
{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  int iVar8;
  double dVar9;
  
  iVar8 = *(int *)(param_1 + 0x4a6c);
  iVar5 = param_1;
  if (iVar8 == 0) {
LAB_0005f94c:
    if (param_2 < 0x80d3) {
      if (param_2 < 0x80d0) {
        if (param_2 < 0x8065) {
          if (0x8062 < param_2) goto LAB_0005fa24;
          if (1 < param_2 - 0xde0) goto LAB_0005fb20;
        }
        else if (param_2 != 0x806f) {
          uVar2 = 0x8070;
LAB_0005f9ec:
          if (param_2 == uVar2) {
LAB_0005fa24:
            uVar3 = ((int (*)())_glColorTable_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
            return uVar3;
          }
          goto LAB_0005fb20;
        }
      }
LAB_0005fa48:
      if ((int)param_4 < 0) {
        if (*(int *)(param_1 + 0x7574) != 0) {
          return iVar5;
        }
        uVar3 = 0x501;
        goto LAB_0005fb30;
      }
      if (param_6 < 0x8037) {
        if (0x8032 < param_6) {
LAB_0005faf4:
          if (param_5 == 0x1908) goto LAB_0005fb38;
          bVar1 = param_5 == 0x80e1;
LAB_0005fb08:
          if (bVar1) {
LAB_0005fb38:
            iVar5 = _glePixelBytes(param_5,param_6);
            if ((int)(iVar5 * param_4) < 1) {
              return iVar5;
            }
            uVar2 = iVar5 * param_4 + 3 & 0xfffffffc;
            puVar6 = (uint *)_gleAddListItem(param_1,PTR__glColorTable_ListExec_00110074,
                                             uVar2 + 0x18);
            if (puVar6 == (uint *)0x0) {
              return 0;
            }
            *puVar6 = param_2;
            puVar6[1] = param_3;
            puVar6[5] = uVar2;
            puVar6[2] = param_4;
            puVar6[3] = param_5;
            puVar6[4] = param_6;
            if ((int)uVar2 < 1) {
              return (int)puVar6;
            }
            if (param_7 == 0) {
              return (int)puVar6;
            }
            uVar3 = _gleFillImage(param_1,param_4,1,1,param_5,param_6,param_7,puVar6 + 6);
            return uVar3;
          }
          goto LAB_0005fb0c;
        }
        if (0x13ff < param_6) {
          if (param_6 < 0x1407) {
            if (param_5 == 0x8000) goto LAB_0005fb38;
            if (param_5 < 0x8001) {
              bVar1 = 7 < param_5 - 0x1903;
            }
            else {
              bVar1 = 1 < param_5 - 0x80e0;
            }
            if (!bVar1) goto LAB_0005fb38;
            goto LAB_0005fb0c;
          }
          if (param_6 == 0x8032) goto LAB_0005faec;
        }
      }
      else if (0x8361 < param_6) {
        if (param_6 < 0x8365) {
LAB_0005faec:
          bVar1 = param_5 == 0x1907;
          goto LAB_0005fb08;
        }
        if (param_6 < 0x8369) goto LAB_0005faf4;
      }
    }
    else {
      if (param_2 == 0x84f5) goto LAB_0005fa48;
      if (0x84f5 < param_2) {
        if (param_2 != 0x8513) {
          if (param_2 < 0x8514) {
            uVar2 = 0x84f7;
            goto LAB_0005f9ec;
          }
          if (param_2 == 0x851b) goto LAB_0005fa24;
          if (param_2 != 0x85b3) goto LAB_0005fb20;
          param_2 = 0x84f5;
        }
        goto LAB_0005fa48;
      }
      if (param_2 < 0x80d6) goto LAB_0005fa24;
      if (param_2 == 0x81fb) goto LAB_0005fa48;
    }
LAB_0005fb20:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return iVar5;
    }
    uVar3 = 0x500;
  }
  else {
    iVar4 = _gleOffsetLimitImage(param_1 + 0x31cc,param_4,1,param_5,param_6,param_7);
    iVar7 = *(int *)(iVar8 + 0x38);
    dVar9 = (double)((double (*)())_gleBytesPerElement)(param_6);
    iVar5 = (int)dVar9;
    if (iVar4 <= iVar7) {
      if (iVar5 == 0) {
        iVar5 = _glePixelBytes(param_5,param_6);
      }
      if (param_7 == (param_7 / iVar5) * iVar5) {
        if (*(int *)(iVar8 + 0x40) != 0) {
          iVar5 = _gleSynchronizePluginBuffer(param_1,iVar8 + 0x10);
        }
        param_7 = param_7 + *(int *)(iVar8 + 0x30);
        goto LAB_0005f94c;
      }
    }
LAB_0005fb0c:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return iVar5;
    }
    uVar3 = 0x502;
  }
LAB_0005fb30:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return iVar5;
}

/* _glColorTable_Exec @ 0x5fbd0 (860 bytes) */
int _glColorTable_Exec(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  uint param_2;
  undefined4 param_3;
  int param_4;
  undefined4 param_5;
  undefined4 param_6;
  int param_7;
{
  bool bVar1;
  byte bVar2;
  ushort uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  double dVar10;
  
  iVar9 = *(int *)(param_1 + 0x4a6c);
  if (iVar9 == 0) {
LAB_0005fc94:
    if (*(short *)(param_1 + 0x4a10) < 0) {
      bVar1 = param_7 != 0;
      if ((!bVar1) && (*(char *)(param_1 + 0x31e6) != '\0')) {
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        uVar4 = 0x501;
        goto LAB_0005fd2c;
      }
      iVar9 = _gleCheckColorTableArgs(param_1,param_2,param_3,param_4,param_5,param_6);
      if (iVar9 == 0) {
        return;
      }
      uVar3 = *(ushort *)(iVar9 + 0x24);
      if ((uVar3 & 0x3c00) == 0x1000) {
LAB_0005fd34:
        iVar7 = iVar9 + 0xac;
        if ((*(byte *)(iVar9 + 0xb7) & 0x20) != 0) {
          _gleDeletePluginTextureLevel(param_1,iVar9,iVar7,0,0xffffffff);
          if (*(int *)(iVar9 + 0xc0) != 0) {
            bVar2 = *(byte *)(iVar9 + 0xb7);
            if ((bVar2 & 1) == 0) {
              _gleFreeTextureLevel(param_1,iVar9,iVar7);
              bVar2 = *(byte *)(iVar9 + 0xb7);
            }
            else {
              *(undefined4 *)(iVar9 + 0xc0) = 0;
            }
            *(byte *)(iVar9 + 0xb7) = bVar2 & 0xef;
          }
          *(byte *)(iVar9 + 0xb7) = *(byte *)(iVar9 + 0xb7) & 0xdf;
        }
        iVar6 = param_1 + 0x33d0;
        if (param_2 != 0x80d1) {
          if (param_2 < 0x80d2) {
            iVar6 = param_1 + 0x33b0;
            uVar5 = 0x80d0;
          }
          else {
            iVar6 = param_1 + 0x33f0;
            uVar5 = 0x80d2;
          }
          if (param_2 != uVar5) {
            iVar6 = 0;
          }
        }
        if (iVar6 == 0) {
          iVar6 = _gleCreateTextureLevel
                            (param_1,iVar9,iVar7,param_3,param_4,1,1,0,param_5,param_6,1,param_7);
          if ((iVar6 != 0) && (bVar1)) {
            _gleTextureImagePut(param_1,iVar7,0,0,0,param_4,1,1,param_5,param_6,0,param_1 + 0x31cc,
                                param_7);
          }
          *(uint *)(param_1 + 0x314) =
               *(uint *)(param_1 + 0x314) | 1 << (*(uint *)(param_1 + 0x53d4) & 0x3f);
        }
        else {
          iVar8 = _gleCreateColorTableLevel
                            (param_1,iVar9,iVar7,param_3,param_4,param_5,param_6,param_7);
          if ((iVar8 != 0) && (bVar1)) {
            _gleColorTable(param_1,iVar6,iVar7,param_4,param_5,param_6,param_7);
          }
          *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x40000000;
        }
        if (param_4 == 0) {
          return;
        }
        _gleCreatePluginTextureLevel(param_1,iVar9,iVar7,0,0xffffffff,param_3);
        return;
      }
      if ((uVar3 & 0x3c00) == 0) {
        *(ushort *)(iVar9 + 0x24) = uVar3 | 0x1000;
        goto LAB_0005fd34;
      }
      if ((uVar3 & 0xc00) == 0) goto LAB_0005fd34;
    }
  }
  else {
    iVar6 = _gleOffsetLimitImage(param_1 + 0x31cc,param_4,1,param_5,param_6,param_7);
    iVar8 = *(int *)(iVar9 + 0x38);
    dVar10 = (double)((double (*)())_gleBytesPerElement)(param_6);
    iVar7 = (int)dVar10;
    if (iVar6 <= iVar8) {
      if (iVar7 == 0) {
        iVar7 = _glePixelBytes(param_5,param_6);
      }
      if (param_7 == (param_7 / iVar7) * iVar7) {
        if (*(int *)(iVar9 + 0x40) != 0) {
          _gleSynchronizePluginBuffer(param_1,iVar9 + 0x10);
        }
        param_7 = param_7 + *(int *)(iVar9 + 0x30);
        goto LAB_0005fc94;
      }
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar4 = 0x502;
LAB_0005fd2c:
  *(undefined4 *)(param_1 + 0x7574) = uVar4;
  return;
}

/* _glColorTable_CompExec @ 0x5ff2c (96 bytes) */
int _glColorTable_CompExec(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  ((int (*)())_glColorTable_Comp)(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  ((int (*)())_glColorTable_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* _glColorSubTable_ListExec @ 0x5ff8c (504 bytes) */
int _glColorSubTable_ListExec(param_1, param_2)
  int param_1;
  uint *param_2;
{
  uint uVar1;
  uint uVar2;
  byte bVar4;
  uint uVar3;
  int iVar5;
  int iVar6;
  
  uVar2 = param_2[5];
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar5 = _gleCheckColorSubTableArgs(param_1,*param_2,param_2[1],param_2[2],param_2[3],param_2[4])
    ;
    if (iVar5 != 0) {
      iVar6 = iVar5 + 0xac;
      bVar4 = *(byte *)(iVar5 + 0xb7);
      if ((bVar4 & 0x10) == 0) {
        if ((bVar4 & 0x40) == 0) {
          if (*(int *)(iVar5 + 0xc0) == 0) {
            _gleAllocateTextureLevel(param_1,iVar5,iVar6);
            bVar4 = *(byte *)(iVar5 + 0xb7);
          }
          *(byte *)(iVar5 + 0xb7) = bVar4 | 0x10;
        }
        else {
          _gleUploadPluginTextureLevel
                    (param_1,iVar5,iVar6,0,0xffffffff,(uint)*(byte *)(param_1 + 0x85a8));
        }
      }
      _gleModifyPluginTextureLevel(param_1,iVar5,iVar6,0,0xffffffff,param_2[1],0,0,param_2[2]);
      uVar3 = *param_2;
      iVar5 = param_1 + 0x33d0;
      if (uVar3 != 0x80d1) {
        if (uVar3 < 0x80d2) {
          iVar5 = param_1 + 0x33b0;
          uVar1 = 0x80d0;
        }
        else {
          iVar5 = param_1 + 0x33f0;
          uVar1 = 0x80d2;
        }
        if (uVar3 != uVar1) {
          iVar5 = 0;
        }
      }
      if (iVar5 == 0) {
        _gleTextureImagePut(param_1,iVar6,param_2[1],0,0,param_2[2],1,1,param_2[3],param_2[4],0,0,
                            param_2 + 6);
        *(uint *)(param_1 + 0x314) =
             *(uint *)(param_1 + 0x314) | 1 << (*(uint *)(param_1 + 0x53d4) & 0x3f);
      }
      else {
        _gleColorSubTable(param_1,iVar5,iVar6,param_2[1],param_2[2],param_2[3],param_2[4],
                          param_2 + 6);
        *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x40000000;
      }
    }
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
  }
  return uVar2 + 0x18;
}

/* _glColorSubTable_Comp @ 0x60184 (656 bytes) */
int _glColorSubTable_Comp(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
  uint param_5;
  uint param_6;
  int param_7;
{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  int iVar8;
  double dVar9;
  
  iVar8 = *(int *)(param_1 + 0x4a6c);
  iVar5 = param_1;
  if (iVar8 == 0) {
LAB_00060248:
    if (param_7 == 0) {
      return iVar5;
    }
    if (param_2 < 0x80d3) {
      if (param_2 < 0x80d0) {
        if (param_2 < 0xde0) goto LAB_00060374;
        if (0xde1 < param_2) {
          uVar2 = 0x806f;
          goto LAB_00060294;
        }
      }
LAB_0006029c:
      if ((int)param_4 < 0) {
        if (*(int *)(param_1 + 0x7574) != 0) {
          return iVar5;
        }
        uVar3 = 0x501;
        goto LAB_00060384;
      }
      if (param_6 < 0x8037) {
        if (0x8032 < param_6) {
LAB_00060348:
          if (param_5 == 0x1908) goto LAB_0006038c;
          bVar1 = param_5 == 0x80e1;
LAB_0006035c:
          if (bVar1) {
LAB_0006038c:
            iVar5 = _glePixelBytes(param_5,param_6);
            if ((int)(iVar5 * param_4) < 1) {
              return iVar5;
            }
            uVar2 = iVar5 * param_4 + 3 & 0xfffffffc;
            puVar6 = (uint *)_gleAddListItem(param_1,PTR__glColorSubTable_ListExec_00110070,
                                             uVar2 + 0x18);
            if (puVar6 == (uint *)0x0) {
              return 0;
            }
            *puVar6 = param_2;
            puVar6[1] = param_3;
            puVar6[5] = uVar2;
            puVar6[2] = param_4;
            puVar6[3] = param_5;
            puVar6[4] = param_6;
            uVar3 = _gleFillImage(param_1,param_4,1,1,param_5,param_6,param_7,puVar6 + 6);
            return uVar3;
          }
          goto LAB_00060360;
        }
        if (0x13ff < param_6) {
          if (param_6 < 0x1407) {
            if (param_5 == 0x8000) goto LAB_0006038c;
            if (param_5 < 0x8001) {
              bVar1 = 7 < param_5 - 0x1903;
            }
            else {
              bVar1 = 1 < param_5 - 0x80e0;
            }
            if (!bVar1) goto LAB_0006038c;
            goto LAB_00060360;
          }
          if (param_6 == 0x8032) goto LAB_00060340;
        }
      }
      else if (0x8361 < param_6) {
        if (param_6 < 0x8365) {
LAB_00060340:
          bVar1 = param_5 == 0x1907;
          goto LAB_0006035c;
        }
        if (param_6 < 0x8369) goto LAB_00060348;
      }
    }
    else {
      if (param_2 == 0x81fb) goto LAB_0006029c;
      uVar2 = 0x8513;
LAB_00060294:
      if (param_2 == uVar2) goto LAB_0006029c;
    }
LAB_00060374:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return iVar5;
    }
    uVar3 = 0x500;
  }
  else {
    iVar4 = _gleOffsetLimitImage(param_1 + 0x31cc,param_4,1,param_5,param_6,param_7);
    iVar7 = *(int *)(iVar8 + 0x38);
    dVar9 = (double)((double (*)())_gleBytesPerElement)(param_6);
    iVar5 = (int)dVar9;
    if (iVar4 <= iVar7) {
      if (iVar5 == 0) {
        iVar5 = _glePixelBytes(param_5,param_6);
      }
      if (param_7 == (param_7 / iVar5) * iVar5) {
        if (*(int *)(iVar8 + 0x40) != 0) {
          iVar5 = _gleSynchronizePluginBuffer(param_1,iVar8 + 0x10);
        }
        param_7 = param_7 + *(int *)(iVar8 + 0x30);
        goto LAB_00060248;
      }
    }
LAB_00060360:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return iVar5;
    }
    uVar3 = 0x502;
  }
LAB_00060384:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return iVar5;
}

/* _glColorSubTable_Exec @ 0x60414 (652 bytes) */
int _glColorSubTable_Exec(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  uint param_2;
  undefined4 param_3;
  int param_4;
  undefined4 param_5;
  undefined4 param_6;
  int param_7;
{
  uint uVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  double dVar7;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar5 = *(int *)(param_1 + 0x4a6c);
    if (iVar5 == 0) {
LAB_000604f4:
      if (param_4 == 0) {
        return;
      }
      iVar5 = _gleCheckColorSubTableArgs(param_1,param_2,param_3,param_4,param_5,param_6);
      if (iVar5 == 0) {
        return;
      }
      iVar4 = iVar5 + 0xac;
      bVar2 = *(byte *)(iVar5 + 0xb7);
      if ((bVar2 & 0x10) == 0) {
        if ((bVar2 & 0x40) == 0) {
          if (*(int *)(iVar5 + 0xc0) == 0) {
            _gleAllocateTextureLevel(param_1,iVar5,iVar4);
            bVar2 = *(byte *)(iVar5 + 0xb7);
          }
          *(byte *)(iVar5 + 0xb7) = bVar2 | 0x10;
        }
        else {
          _gleUploadPluginTextureLevel
                    (param_1,iVar5,iVar4,0,0xffffffff,(uint)*(byte *)(param_1 + 0x85a8));
        }
      }
      _gleModifyPluginTextureLevel(param_1,iVar5,iVar4,0,0xffffffff,param_3,0,0,param_4);
      iVar5 = param_1 + 0x33d0;
      if (param_2 != 0x80d1) {
        if (param_2 < 0x80d2) {
          iVar5 = param_1 + 0x33b0;
          uVar1 = 0x80d0;
        }
        else {
          iVar5 = param_1 + 0x33f0;
          uVar1 = 0x80d2;
        }
        if (param_2 != uVar1) {
          iVar5 = 0;
        }
      }
      if (iVar5 != 0) {
        _gleColorSubTable(param_1,iVar5,iVar4,param_3,param_4,param_5,param_6,param_7);
        *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x40000000;
        return;
      }
      _gleTextureImagePut(param_1,iVar4,param_3,0,0,param_4,1,1,param_5,param_6,0,param_1 + 0x31cc,
                          param_7);
      *(uint *)(param_1 + 0x314) =
           *(uint *)(param_1 + 0x314) | 1 << (*(uint *)(param_1 + 0x53d4) & 0x3f);
      return;
    }
    iVar3 = _gleOffsetLimitImage(param_1 + 0x31cc,param_4,1,param_5,param_6,param_7);
    iVar6 = *(int *)(iVar5 + 0x38);
    dVar7 = (double)((double (*)())_gleBytesPerElement)(param_6);
    iVar4 = (int)dVar7;
    if (iVar3 <= iVar6) {
      if (iVar4 == 0) {
        iVar4 = _glePixelBytes(param_5,param_6);
      }
      if (param_7 == (param_7 / iVar4) * iVar4) {
        if (*(int *)(iVar5 + 0x40) != 0) {
          _gleSynchronizePluginBuffer(param_1,iVar5 + 0x10);
        }
        param_7 = param_7 + *(int *)(iVar5 + 0x30);
        goto LAB_000604f4;
      }
    }
  }
  if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
  }
  return;
}

/* _glColorSubTable_CompExec @ 0x606a0 (96 bytes) */
int _glColorSubTable_CompExec(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  ((int (*)())_glColorSubTable_Comp)(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  ((int (*)())_glColorSubTable_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* _glCopyColorTable_ListExec @ 0x60700 (60 bytes) */
undefined4 _glCopyColorTable_ListExec(undefined4 param_1,undefined4 *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  ((void (*)())_glCopyColorTable_Exec)(param_1,*param_2,param_2[1],param_2[2],param_2[3],param_2[4],fparam_1,fparam_2,fparam_3
             ,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  return 0x14;
}

/* _glCopyColorTable_Comp @ 0x6073c (108 bytes) */
int _glCopyColorTable_Comp(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glCopyColorTable_ListExec_0011006c,0x14);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[4] = param_6;
    *puVar1 = param_2;
    puVar1[1] = param_3;
    puVar1[2] = param_4;
    puVar1[3] = param_5;
  }
  return puVar1;
}

/* _glCopyColorTable_Exec @ 0x607a8 (1232 bytes) */
void _glCopyColorTable_Exec(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  byte bVar3;
  ushort uVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int *piVar15;
  double extraout_f1;
  
  if ((*(int *)(param_1 + 0x744c) != 0) || (*(int *)(param_1 + 0x310) < 0)) {
    iVar12 = *(int *)(param_1 + 0x50ac);
    uVar5 = param_3;
    uVar9 = param_4;
    uVar10 = param_5;
    uVar11 = param_6;
    if (iVar12 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
      _gleUpdateMatrixFunc(param_1);
      fparam_1 = extraout_f1;
    }
    if (*(char *)(param_1 + 0x4691) != '\0') {
      iVar8 = *(int *)(param_1 + 0x744c);
      piVar15 = (int *)(param_1 + 0x310);
      cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
      if ((iVar8 != 0) && (*(int *)(iVar8 + 0xec) != 0)) {
        ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar8 + 0x10,uVar5,uVar9,uVar10,uVar11,iVar12,fparam_1,fparam_2,fparam_3,
                   fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
        *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
      }
      if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_000608e8:
        uVar13 = *(uint *)(param_1 + 0x31c);
      }
      else {
        iVar12 = 0;
        piVar6 = (int *)(param_1 + 0x324);
        do {
          iVar8 = *piVar6;
          piVar6 = piVar6 + 1;
          if (iVar8 != 0) {
            *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
            break;
          }
          iVar12 = iVar12 + 1;
        } while (iVar12 < 9);
        uVar13 = *(uint *)(param_1 + 0x31c);
        if ((uVar13 & 0x15555) != 0) {
          if (*(char *)(param_1 + 0x2e54) != '\0') {
            _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
          }
          if (*(char *)(param_1 + 0x3094) != '\0') {
            _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
          }
          goto LAB_000608e8;
        }
      }
      bVar1 = cVar2 == '\0';
      if (bVar1) {
        uVar13 = uVar13 & 0x17000000;
      }
      else {
        uVar13 = uVar13 & 0x17ffffff;
      }
      if (bVar1) {
        bVar1 = ((*piVar15 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar13 == 0) &&
                *(int *)(param_1 + 800) == 0;
      }
      else {
        bVar1 = (((*piVar15 == 0 && *(int *)(param_1 + 0x314) == 0) &&
                 (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar13 == 0) &&
                *(int *)(param_1 + 800) == 0;
      }
      if (!bVar1) {
        if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
          uVar13 = (**(code **)(param_1 + 0x4788))
                             (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar15);
          if ((((uVar13 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
              ((uVar13 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
             ((uVar13 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
            if ((uVar13 & 4) == 0) {
              uVar13 = uVar13 & 0xfffffffe;
              *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
            }
            _gleUpdateDispatchCodeChange(param_1,uVar13);
            if (*(char *)(param_1 + 0x759d) == '\0') {
              if (*(int *)(param_1 + 0x7574) != 0) {
                return;
              }
              uVar5 = 0x506;
              goto LAB_00060a74;
            }
          }
        }
        else {
          _gleSwitchToNonRevertRenderer(param_1);
        }
        iVar12 = 0x13;
        do {
          *piVar15 = 0;
          piVar15 = piVar15 + 1;
          iVar12 = iVar12 + -1;
        } while (iVar12 != 0);
      }
    }
  }
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar12 = _gleCheckCopyColorTableArgs(param_1,param_2,param_3,param_6);
    if (iVar12 == 0) {
      return;
    }
    uVar4 = *(ushort *)(iVar12 + 0x24);
    if ((uVar4 & 0x3c00) == 0x1000) {
LAB_00060a7c:
      iVar8 = iVar12 + 0xac;
      if ((*(byte *)(iVar12 + 0xb7) & 0x20) != 0) {
        _gleDeletePluginTextureLevel(param_1,iVar12,iVar8,0,0xffffffff);
        if (*(int *)(iVar12 + 0xc0) != 0) {
          bVar3 = *(byte *)(iVar12 + 0xb7);
          if ((bVar3 & 1) == 0) {
            _gleFreeTextureLevel(param_1,iVar12,iVar8);
            bVar3 = *(byte *)(iVar12 + 0xb7);
          }
          else {
            *(undefined4 *)(iVar12 + 0xc0) = 0;
          }
          *(byte *)(iVar12 + 0xb7) = bVar3 & 0xef;
        }
        *(byte *)(iVar12 + 0xb7) = *(byte *)(iVar12 + 0xb7) & 0xdf;
      }
      iVar14 = param_1 + 0x33d0;
      if (param_2 != 0x80d1) {
        if (param_2 < 0x80d2) {
          iVar14 = param_1 + 0x33b0;
          uVar13 = 0x80d0;
        }
        else {
          iVar14 = param_1 + 0x33f0;
          uVar13 = 0x80d2;
        }
        if (param_2 != uVar13) {
          iVar14 = 0;
        }
      }
      if (iVar14 == 0) {
        iVar14 = _gleCreateTextureLevel
                           (param_1,iVar12,iVar8,param_3,param_6,1,1,0,0x1908,0x1401,0,0x1000);
        if (iVar14 != 0) {
          _gleTextureImageCopy(param_1,iVar8,param_3,param_4,param_5,param_6,1);
        }
        *(uint *)(param_1 + 0x314) =
             *(uint *)(param_1 + 0x314) | 1 << (*(uint *)(param_1 + 0x53d4) & 0x3f);
      }
      else {
        iVar7 = _gleCreateColorTableLevel(param_1,iVar12,iVar8,param_3,param_6,0x1908,0x1401,0x1000)
        ;
        if (iVar7 != 0) {
          _gleTextureImageCopy(param_1,iVar8,param_3,param_4,param_5,param_6,1);
        }
        _gleImagingScaleAndBias
                  (param_1,iVar14,*(undefined4 *)(iVar12 + 0xc0),(uint)*(ushort *)(iVar12 + 0xbc),0,
                   param_6,1);
        *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x40000000;
      }
      _gleCreatePluginTextureLevel(param_1,iVar12,iVar8,0,0xffffffff,param_3);
      return;
    }
    if ((uVar4 & 0x3c00) == 0) {
      *(ushort *)(iVar12 + 0x24) = uVar4 | 0x1000;
      goto LAB_00060a7c;
    }
    if ((uVar4 & 0xc00) == 0) goto LAB_00060a7c;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar5 = 0x502;
LAB_00060a74:
  *(undefined4 *)(param_1 + 0x7574) = uVar5;
  return;
}

/* _glCopyColorTable_CompExec @ 0x60c78 (88 bytes) */
int _glCopyColorTable_CompExec(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glCopyColorTable_Comp)(param_1,param_2,param_3,param_4,param_5,param_6);
  ((void (*)())_glCopyColorTable_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,
             in_f7,in_f8);
  return;
}

/* _glCopyColorSubTable_ListExec @ 0x60cd0 (60 bytes) */
undefined4 _glCopyColorSubTable_ListExec(undefined4 param_1,undefined4 *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  ((void (*)())_glCopyColorSubTable_Exec)(param_1,*param_2,param_2[1],param_2[2],param_2[3],param_2[4],fparam_1,fparam_2,fparam_3
             ,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  return 0x14;
}

/* _glCopyColorSubTable_Comp @ 0x60d0c (108 bytes) */
int _glCopyColorSubTable_Comp(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glCopyColorSubTable_ListExec_00110068,0x14);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[4] = param_6;
    *puVar1 = param_2;
    puVar1[1] = param_3;
    puVar1[2] = param_4;
    puVar1[3] = param_5;
  }
  return puVar1;
}

/* _glCopyColorSubTable_Exec @ 0x60d78 (1044 bytes) */
void _glCopyColorSubTable_Exec(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,int param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  byte bVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int *piVar12;
  double extraout_f1;
  
  if ((*(int *)(param_1 + 0x744c) != 0) || (*(int *)(param_1 + 0x310) < 0)) {
    iVar9 = *(int *)(param_1 + 0x50ac);
    uVar3 = param_3;
    uVar7 = param_4;
    uVar8 = param_5;
    iVar10 = param_6;
    if (iVar9 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
      _gleUpdateMatrixFunc(param_1);
      fparam_1 = extraout_f1;
    }
    if (*(char *)(param_1 + 0x4691) != '\0') {
      iVar6 = *(int *)(param_1 + 0x744c);
      piVar12 = (int *)(param_1 + 0x310);
      cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
      if ((iVar6 != 0) && (*(int *)(iVar6 + 0xec) != 0)) {
        ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar6 + 0x10,uVar3,uVar7,uVar8,iVar10,iVar9,fparam_1,fparam_2,fparam_3,
                   fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
        *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
      }
      if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_00060eb8:
        uVar11 = *(uint *)(param_1 + 0x31c);
      }
      else {
        iVar10 = 0;
        piVar4 = (int *)(param_1 + 0x324);
        do {
          iVar9 = *piVar4;
          piVar4 = piVar4 + 1;
          if (iVar9 != 0) {
            *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
            break;
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 < 9);
        uVar11 = *(uint *)(param_1 + 0x31c);
        if ((uVar11 & 0x15555) != 0) {
          if (*(char *)(param_1 + 0x2e54) != '\0') {
            _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
          }
          if (*(char *)(param_1 + 0x3094) != '\0') {
            _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
          }
          goto LAB_00060eb8;
        }
      }
      bVar1 = cVar2 == '\0';
      if (bVar1) {
        uVar11 = uVar11 & 0x17000000;
      }
      else {
        uVar11 = uVar11 & 0x17ffffff;
      }
      if (bVar1) {
        bVar1 = ((*piVar12 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar11 == 0) &&
                *(int *)(param_1 + 800) == 0;
      }
      else {
        bVar1 = (((*piVar12 == 0 && *(int *)(param_1 + 0x314) == 0) &&
                 (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar11 == 0) &&
                *(int *)(param_1 + 800) == 0;
      }
      if (!bVar1) {
        if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
          uVar11 = (**(code **)(param_1 + 0x4788))
                             (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar12);
          if ((((uVar11 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
              ((uVar11 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
             ((uVar11 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
            if ((uVar11 & 4) == 0) {
              uVar11 = uVar11 & 0xfffffffe;
              *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
            }
            _gleUpdateDispatchCodeChange(param_1,uVar11);
            if (*(char *)(param_1 + 0x759d) == '\0') {
              if (*(int *)(param_1 + 0x7574) != 0) {
                return;
              }
              uVar3 = 0x506;
              goto LAB_00060ff8;
            }
          }
        }
        else {
          _gleSwitchToNonRevertRenderer(param_1);
        }
        iVar10 = 0x13;
        do {
          *piVar12 = 0;
          piVar12 = piVar12 + 1;
          iVar10 = iVar10 + -1;
        } while (iVar10 != 0);
      }
    }
  }
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_6 == 0) {
      return;
    }
    iVar10 = _gleCheckCopyColorSubTableArgs(param_1,param_2,param_3,param_6);
    if (iVar10 == 0) {
      return;
    }
    iVar9 = iVar10 + 0xac;
    bVar5 = *(byte *)(iVar10 + 0xb7);
    if ((bVar5 & 0x10) == 0) {
      if ((bVar5 & 0x40) == 0) {
        if (*(int *)(iVar10 + 0xc0) == 0) {
          _gleAllocateTextureLevel(param_1,iVar10,iVar9);
          bVar5 = *(byte *)(iVar10 + 0xb7);
        }
        *(byte *)(iVar10 + 0xb7) = bVar5 | 0x10;
      }
      else {
        _gleUploadPluginTextureLevel
                  (param_1,iVar10,iVar9,0,0xffffffff,(uint)*(byte *)(param_1 + 0x85a8));
      }
    }
    iVar6 = param_1 + 0x33d0;
    _gleModifyPluginTextureLevel(param_1,iVar10,iVar9,0,0xffffffff,param_3,0,0,param_6);
    if (param_2 != 0x80d1) {
      if (param_2 < 0x80d2) {
        iVar6 = param_1 + 0x33b0;
        uVar11 = 0x80d0;
      }
      else {
        iVar6 = param_1 + 0x33f0;
        uVar11 = 0x80d2;
      }
      if (param_2 != uVar11) {
        iVar6 = 0;
      }
    }
    _gleTextureSubImageCopy(param_1,iVar9,param_3,0,0,param_4,param_5,param_6,1);
    if (iVar6 != 0) {
      _gleImagingScaleAndBias
                (param_1,iVar6,*(undefined4 *)(iVar10 + 0xc0),(uint)*(ushort *)(iVar10 + 0xbc),
                 param_3,param_6,1);
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x40000000;
      return;
    }
    *(uint *)(param_1 + 0x314) =
         *(uint *)(param_1 + 0x314) | 1 << (*(uint *)(param_1 + 0x53d4) & 0x3f);
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar3 = 0x502;
LAB_00060ff8:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* _glCopyColorSubTable_CompExec @ 0x6118c (88 bytes) */
int _glCopyColorSubTable_CompExec(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glCopyColorSubTable_Comp)(param_1,param_2,param_3,param_4,param_5,param_6);
  ((void (*)())_glCopyColorSubTable_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,
             in_f7,in_f8);
  return;
}

/* _glGetColorTable_Exec @ 0x611e4 (852 bytes) */
int _glGetColorTable_Exec(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  uint param_3;
  uint param_4;
  int param_5;
{
  bool bVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint uVar10;
  undefined1 *puVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  double dVar15;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  int local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  uint local_ac;
  undefined4 local_a8;
  uint local_a4;
  uint local_a0;
  undefined1 local_64;
  undefined4 local_60;
  undefined1 auStack_5c [4];
  undefined1 auStack_58 [4];
  undefined1 auStack_54 [4];
  undefined1 auStack_50 [4];
  int local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c [5];
  
  iVar4 = _gleLookUpNonProxyColorTable(param_1,param_2);
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (iVar4 != 0) {
      if (param_4 < 0x8037) {
        if (0x8032 < param_4) {
LAB_000612b0:
          if (param_3 != 0x1908) {
            bVar1 = param_3 == 0x80e1;
LAB_000612c4:
            if (!bVar1) goto LAB_00061354;
          }
LAB_000612e0:
          iVar13 = *(int *)(param_1 + 0x4a68);
          if (iVar13 == 0) {
LAB_0006138c:
            bVar2 = *(byte *)(iVar4 + 0xb7);
            if ((bVar2 & 0x20) == 0) {
              return;
            }
            if ((bVar2 & 0x40) == 0) {
              if ((bVar2 & 0x10) == 0) {
                return;
              }
            }
            else {
              _gleUploadPluginTextureLevel
                        (param_1,iVar4,iVar4 + 0xac,0,0xffffffff,(uint)*(byte *)(param_1 + 0x85a8));
            }
            uVar9 = (uint)*(ushort *)(iVar4 + 0xb2);
            puVar11 = auStack_50;
            piVar12 = &local_4c;
            _glePixelPackSettings
                      (param_1,param_3,param_4,(uint)*(ushort *)(iVar4 + 0xb0),uVar9,
                       param_1 + 0x31b0,puVar11,piVar12,&local_60,auStack_5c,auStack_58,auStack_54);
            if (((((*(byte *)(iVar4 + 0xb7) & 1) == 0) ||
                 (param_5 + local_4c != *(int *)(iVar4 + 0xc0))) ||
                (param_3 != *(ushort *)(iVar4 + 0xbc))) || (param_4 != *(ushort *)(iVar4 + 0xbe))) {
              uVar10 = (uint)*(byte *)(param_1 + 0x31c8);
            }
            else {
              uVar10 = (uint)*(byte *)(param_1 + 0x31c8);
              if (uVar10 == 0) {
                return;
              }
            }
            local_ac = (uint)(uVar10 != 0);
            uVar3 = _gleRowBytes((uint)*(ushort *)(iVar4 + 0xbc),(uint)*(ushort *)(iVar4 + 0xbe),
                                 (uint)*(ushort *)(iVar4 + 0xb8));
            _glgConvertType((uint)*(ushort *)(iVar4 + 0xbc),(uint)*(ushort *)(iVar4 + 0xbe),
                            &local_48,&local_44,uVar9,uVar10,puVar11,piVar12);
            puVar7 = &local_40;
            puVar8 = local_3c;
            _glgConvertType(param_3,param_4,puVar7,puVar8,uVar9,uVar10,puVar11,piVar12);
            local_c8 = local_48;
            local_c4 = local_44;
            local_bc = local_60;
            local_b8 = local_40;
            local_b4 = local_3c[0];
            local_a8 = 1;
            local_b0 = 2;
            local_a4 = (uint)*(ushort *)(iVar4 + 0xb0);
            local_a0 = (uint)*(ushort *)(iVar4 + 0xb2);
            local_c0 = param_5 + local_4c;
            local_d0 = *(undefined4 *)(iVar4 + 0xc0);
            local_64 = 0;
            local_cc = uVar3;
            _glgProcessPixels(param_1 + 0x31a8,&local_d0,puVar7,puVar8,uVar9,uVar10,local_a0,piVar12
                             );
            return;
          }
          iVar5 = _gleOffsetLimitImage
                            (param_1 + 0x31b0,(uint)*(ushort *)(iVar4 + 0xb0),
                             (uint)*(ushort *)(iVar4 + 0xb2),param_3,param_4,param_5);
          iVar14 = *(int *)(iVar13 + 0x38);
          dVar15 = (double)((double (*)())_gleBytesPerElement)(param_4);
          iVar6 = (int)dVar15;
          if (iVar5 <= iVar14) {
            if (iVar6 == 0) {
              iVar6 = _glePixelBytes(param_3,param_4);
            }
            if (param_5 == (param_5 / iVar6) * iVar6) {
              if (*(int *)(iVar13 + 0x40) != 0) {
                _gleSynchronizePluginBuffer(param_1,iVar13 + 0x10);
              }
              param_5 = param_5 + *(int *)(iVar13 + 0x30);
              goto LAB_0006138c;
            }
          }
          goto LAB_00061354;
        }
        if (0x13ff < param_4) {
          if (param_4 < 0x1407) {
            if (param_3 != 0x8000) {
              if (param_3 < 0x8001) {
                bVar1 = 7 < param_3 - 0x1903;
              }
              else {
                bVar1 = 1 < param_3 - 0x80e0;
              }
              if (bVar1) goto LAB_00061354;
            }
            goto LAB_000612e0;
          }
          if (param_4 == 0x8032) goto LAB_000612a8;
        }
      }
      else if (0x8361 < param_4) {
        if (param_4 < 0x8365) {
LAB_000612a8:
          bVar1 = param_3 == 0x1907;
          goto LAB_000612c4;
        }
        if (param_4 < 0x8369) goto LAB_000612b0;
      }
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x500;
  }
  else {
LAB_00061354:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* _glColorTableParameterfv_ListExec @ 0x61538 (52 bytes) */
int _glColorTableParameterfv_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((int (*)())_glColorTableParameterfv_Exec)(param_1,*param_2,param_2[1],param_2 + 2);
  return 0x18;
}

/* _glColorTableParameterfv_Comp @ 0x6156c (136 bytes) */
int _glColorTableParameterfv_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  undefined4 *param_4;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           _gleAddListItem(param_1,PTR__glColorTableParameterfv_ListExec_0011007c,0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    puVar1[1] = param_3;
    if (param_3 - 0x80d6U < 2) {
      puVar1[2] = *param_4;
      puVar1[3] = param_4[1];
      puVar1[4] = param_4[2];
      puVar1[5] = param_4[3];
    }
  }
  return puVar1;
}

/* _glColorTableParameterfv_Exec @ 0x615f4 (260 bytes) */
int _glColorTableParameterfv_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int param_3;
  undefined4 *param_4;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
    goto LAB_00061690;
  }
  switch(param_2) {
  case 0x80d0:
  case 0x80d3:
    puVar2 = (undefined4 *)(param_1 + 0x33b0);
    break;
  case 0x80d1:
  case 0x80d4:
    puVar2 = (undefined4 *)(param_1 + 0x33d0);
    break;
  case 0x80d2:
  case 0x80d5:
    puVar2 = (undefined4 *)(param_1 + 0x33f0);
    break;
  default:
    goto switchD_0006164c_default;
  }
  if (param_3 == 0x80d6) {
    *puVar2 = *param_4;
    puVar2[2] = param_4[1];
    puVar2[4] = param_4[2];
    puVar2[6] = param_4[3];
  }
  else {
    if (param_3 != 0x80d7) {
switchD_0006164c_default:
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar1 = 0x500;
LAB_00061690:
      *(undefined4 *)(param_1 + 0x7574) = uVar1;
      return;
    }
    puVar2[1] = *param_4;
    puVar2[3] = param_4[1];
    puVar2[5] = param_4[2];
    puVar2[7] = param_4[3];
  }
  *(uint *)(param_1 + 0x314) = *(uint *)(param_1 + 0x314) | 0x40000000;
  return;
}

/* _glColorTableParameterfv_CompExec @ 0x61710 (72 bytes) */
int _glColorTableParameterfv_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glColorTableParameterfv_Comp)(param_1,param_2,param_3,param_4);
  ((int (*)())_glColorTableParameterfv_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glColorTableParameteriv_ListExec @ 0x61758 (52 bytes) */
int _glColorTableParameteriv_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((int (*)())_glColorTableParameteriv_Exec)(param_1,*param_2,param_2[1],param_2 + 2);
  return 0x18;
}

/* _glColorTableParameteriv_Comp @ 0x6178c (136 bytes) */
int _glColorTableParameteriv_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  undefined4 *param_4;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           _gleAddListItem(param_1,PTR__glColorTableParameteriv_ListExec_00110078,0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    puVar1[1] = param_3;
    if (param_3 - 0x80d6U < 2) {
      puVar1[2] = *param_4;
      puVar1[3] = param_4[1];
      puVar1[4] = param_4[2];
      puVar1[5] = param_4[3];
    }
  }
  return puVar1;
}

/* _glColorTableParameteriv_Exec @ 0x61814 (476 bytes) */
int _glColorTableParameteriv_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int param_3;
  uint *param_4;
{
  double dVar1;
  undefined4 uVar2;
  float *pfVar3;
  
  dVar1 = DOUBLE_00108d58;
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x502;
    goto LAB_000618b0;
  }
  switch(param_2) {
  case 0x80d0:
  case 0x80d3:
    pfVar3 = (float *)(param_1 + 0x33b0);
    break;
  case 0x80d1:
  case 0x80d4:
    pfVar3 = (float *)(param_1 + 0x33d0);
    break;
  case 0x80d2:
  case 0x80d5:
    pfVar3 = (float *)(param_1 + 0x33f0);
    break;
  default:
    goto switchD_0006186c_default;
  }
  if (param_3 == 0x80d6) {
    *pfVar3 = (float)((double)CONCAT44(0x43300000,*param_4 ^ 0x80000000) - DOUBLE_00108d58);
    pfVar3[2] = (float)((double)CONCAT44(0x43300000,param_4[1] ^ 0x80000000) - dVar1);
    pfVar3[4] = (float)((double)CONCAT44(0x43300000,param_4[2] ^ 0x80000000) - dVar1);
    pfVar3[6] = (float)((double)CONCAT44(0x43300000,param_4[3] ^ 0x80000000) - dVar1);
  }
  else {
    if (param_3 != 0x80d7) {
switchD_0006186c_default:
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar2 = 0x500;
LAB_000618b0:
      *(undefined4 *)(param_1 + 0x7574) = uVar2;
      return;
    }
    pfVar3[1] = (float)((double)CONCAT44(0x43300000,*param_4 ^ 0x80000000) - DOUBLE_00108d58);
    pfVar3[3] = (float)((double)CONCAT44(0x43300000,param_4[1] ^ 0x80000000) - dVar1);
    pfVar3[5] = (float)((double)CONCAT44(0x43300000,param_4[2] ^ 0x80000000) - dVar1);
    pfVar3[7] = (float)((double)CONCAT44(0x43300000,param_4[3] ^ 0x80000000) - dVar1);
  }
  *(uint *)(param_1 + 0x314) = *(uint *)(param_1 + 0x314) | 0x40000000;
  return;
}

/* _glColorTableParameteriv_CompExec @ 0x61a08 (72 bytes) */
int _glColorTableParameteriv_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glColorTableParameteriv_Comp)(param_1,param_2,param_3,param_4);
  ((int (*)())_glColorTableParameteriv_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glGetColorTableParameterfv_Exec @ 0x61a50 (368 bytes) */
int _glGetColorTableParameterfv_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  float *param_4;
{
  float fVar1;
  ushort uVar2;
  undefined4 uVar3;
  int iVar4;
  float *pfVar5;
  
  iVar4 = _gleLookUpColorTable(param_1,param_2);
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_00061be8;
  }
  if (iVar4 == 0) {
switchD_00061acc_default:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x500;
LAB_00061be8:
    *(undefined4 *)(param_1 + 0x7574) = uVar3;
    return;
  }
  switch(param_2) {
  case 0x80d0:
  case 0x80d3:
    pfVar5 = (float *)(param_1 + 0x33b0);
    break;
  case 0x80d1:
  case 0x80d4:
    pfVar5 = (float *)(param_1 + 0x33d0);
    break;
  case 0x80d2:
  case 0x80d5:
    pfVar5 = (float *)(param_1 + 0x33f0);
    break;
  default:
    goto switchD_00061acc_default;
  }
  switch(param_3) {
  case 0x80d6:
    *param_4 = *pfVar5;
    param_4[1] = pfVar5[2];
    param_4[2] = pfVar5[4];
    fVar1 = pfVar5[6];
    break;
  case 0x80d7:
    *param_4 = pfVar5[1];
    param_4[1] = pfVar5[3];
    param_4[2] = pfVar5[5];
    fVar1 = pfVar5[7];
    break;
  case 0x80d8:
    uVar2 = *(ushort *)(iVar4 + 0xbc);
    goto LAB_00061ba4;
  case 0x80d9:
    uVar2 = *(ushort *)(iVar4 + 0xb0);
LAB_00061ba4:
    *param_4 = GH_U2F((unsigned int)((uVar2 | 0x4b000000))) - 8388608.0;
    return;
  case 0x80da:
  case 0x80db:
  case 0x80dc:
  case 0x80dd:
  case 0x80de:
  case 0x80df:
    *param_4 = 8.0;
    return;
  default:
    goto switchD_00061acc_default;
  }
  param_4[3] = fVar1;
  return;
}

/* _glGetColorTableParameteriv_Exec @ 0x61c00 (416 bytes) */
int _glGetColorTableParameteriv_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  uint *param_4;
{
  float fVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  float *pfVar5;
  
  iVar4 = _gleLookUpColorTable(param_1,param_2);
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x502;
    goto LAB_00061dc8;
  }
  if (iVar4 == 0) {
switchD_00061c7c_default:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x500;
LAB_00061dc8:
    *(undefined4 *)(param_1 + 0x7574) = uVar2;
    return;
  }
  switch(param_2) {
  case 0x80d0:
  case 0x80d3:
    pfVar5 = (float *)(param_1 + 0x33b0);
    break;
  case 0x80d1:
  case 0x80d4:
    pfVar5 = (float *)(param_1 + 0x33d0);
    break;
  case 0x80d2:
  case 0x80d5:
    pfVar5 = (float *)(param_1 + 0x33f0);
    break;
  default:
    goto switchD_00061c7c_default;
  }
  switch(param_3) {
  case 0x80d6:
    *param_4 = (int)*pfVar5;
    param_4[1] = (int)pfVar5[2];
    param_4[2] = (int)pfVar5[4];
    fVar1 = pfVar5[6];
    goto LAB_00061d88;
  case 0x80d7:
    *param_4 = (int)pfVar5[1];
    param_4[1] = (int)pfVar5[3];
    param_4[2] = (int)pfVar5[5];
    fVar1 = pfVar5[7];
LAB_00061d88:
    param_4[3] = (int)fVar1;
    return;
  case 0x80d8:
    uVar3 = (uint)*(ushort *)(iVar4 + 0xbc);
    break;
  case 0x80d9:
    uVar3 = (uint)*(ushort *)(iVar4 + 0xb0);
    break;
  case 0x80da:
  case 0x80db:
  case 0x80dc:
  case 0x80dd:
  case 0x80de:
  case 0x80df:
    uVar3 = 8;
    break;
  default:
    goto switchD_00061c7c_default;
  }
  *param_4 = uVar3;
  return;
}

/* _glCopyPixels_ListExec @ 0x61de0 (876 bytes) */
undefined4 _glCopyPixels_ListExec(int param_1,undefined4 *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar8;
  int *piVar9;
  float *pfVar10;
  double extraout_f1;
  
  iVar5 = *(int *)(param_1 + 0x4854);
  pfVar10 = (float *)(iVar5 + -0x200);
  if (*(char *)(param_1 + 0x2ef) == '\0') {
    return 0x14;
  }
  uVar3 = *(uint *)(param_1 + 0x4e1c);
  if (uVar3 == 0x1c01) {
    *(undefined4 *)(iVar5 + -0x200) = *(undefined4 *)(param_1 + 0x2e0);
    *(undefined4 *)(iVar5 + -0x1fc) = *(undefined4 *)(param_1 + 0x2e4);
    *(undefined4 *)(iVar5 + -0x1f8) = *(undefined4 *)(param_1 + 0x2e8);
    _gleFeedbackCopyPixels(param_1,pfVar10);
    return 0x14;
  }
  if (uVar3 < 0x1c02) {
    if (uVar3 == 0x1c00) {
      if (*(float *)(param_1 + 0x31a8) == FLOAT_00108e50) {
        return 0x14;
      }
      if (*(float *)(param_1 + 0x31ac) == FLOAT_00108e50) {
        return 0x14;
      }
      if (param_2[2] == 0) {
        return 0x14;
      }
      if (param_2[3] == 0) {
        return 0x14;
      }
      iVar8 = *(int *)(param_1 + 0x50ac);
      if (iVar8 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
        _gleUpdateMatrixFunc(param_1);
        fparam_1 = extraout_f1;
      }
      if (*(char *)(param_1 + 0x4691) == '\0') goto LAB_00062098;
      iVar7 = *(int *)(param_1 + 0x744c);
      piVar9 = (int *)(param_1 + 0x310);
      cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
      if ((iVar7 != 0) && (*(int *)(iVar7 + 0xec) != 0)) {
        ((int (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar7 + 0x10,in_r5,in_r6,in_r7,in_r8,iVar8,fparam_1,fparam_2,fparam_3,
                   fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
        *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
      }
      if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_00061f74:
        uVar3 = *(uint *)(param_1 + 0x31c);
      }
      else {
        iVar8 = 0;
        piVar6 = (int *)(param_1 + 0x324);
        do {
          iVar7 = *piVar6;
          piVar6 = piVar6 + 1;
          if (iVar7 != 0) {
            *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
            break;
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < 9);
        uVar3 = *(uint *)(param_1 + 0x31c);
        if ((uVar3 & 0x15555) != 0) {
          if (*(char *)(param_1 + 0x2e54) != '\0') {
            _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
          }
          if (*(char *)(param_1 + 0x3094) != '\0') {
            _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
          }
          goto LAB_00061f74;
        }
      }
      bVar1 = cVar2 == '\0';
      if (bVar1) {
        uVar3 = uVar3 & 0x17000000;
      }
      else {
        uVar3 = uVar3 & 0x17ffffff;
      }
      if (bVar1) {
        bVar1 = ((*piVar9 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar3 == 0) &&
                *(int *)(param_1 + 800) == 0;
      }
      else {
        bVar1 = (((*piVar9 == 0 && *(int *)(param_1 + 0x314) == 0) &&
                 (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar3 == 0) &&
                *(int *)(param_1 + 800) == 0;
      }
      if (!bVar1) {
        if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
          uVar3 = (**(code **)(param_1 + 0x4788))
                            (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar9);
          if ((((uVar3 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
              ((uVar3 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
             ((uVar3 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
            if ((uVar3 & 4) == 0) {
              uVar3 = uVar3 & 0xfffffffe;
              *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
            }
            _gleUpdateDispatchCodeChange(param_1,uVar3);
            if (*(char *)(param_1 + 0x759d) == '\0') {
              if (*(int *)(param_1 + 0x7574) != 0) {
                return 0x14;
              }
              uVar4 = 0x506;
              goto LAB_00062130;
            }
          }
        }
        else {
          _gleSwitchToNonRevertRenderer(param_1);
        }
        iVar8 = 0x13;
        do {
          *piVar9 = 0;
          piVar9 = piVar9 + 1;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
LAB_00062098:
      *pfVar10 = *(float *)(param_1 + 0x4a44) * *(float *)(param_1 + 0x2e0) +
                 *(float *)(param_1 + 0x4a48);
      *(float *)(iVar5 + -0x1fc) =
           *(float *)(param_1 + 0x4a4c) * *(float *)(param_1 + 0x2e4) + *(float *)(param_1 + 0x4a50)
      ;
      *(float *)(iVar5 + -0x1f8) = *(float *)(param_1 + 0x4a54) * *(float *)(param_1 + 0x2e8);
      (**(code **)(param_1 + 0x46a8))
                (*(undefined4 *)(param_1 + 0x4688),pfVar10,*param_2,param_2[1],param_2[2],param_2[3]
                 ,param_2[4]);
      return 0x14;
    }
  }
  else if (uVar3 == 0x1c02) {
    return 0x14;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return 0x14;
  }
  uVar4 = 0x500;
LAB_00062130:
  *(undefined4 *)(param_1 + 0x7574) = uVar4;
  return 0x14;
}

/* _glCopyPixels_Comp @ 0x6214c (216 bytes) */
int _glCopyPixels_Comp(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
  int param_6;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((param_4 < 0) || (param_5 < 0)) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return param_1;
      }
      uVar1 = 0x501;
    }
    else {
      if (param_6 - 0x1800U < 3) {
        puVar2 = (undefined4 *)_gleAddListItem(param_1,PTR__glCopyPixels_ListExec_00110080,0x14);
        if (puVar2 == (undefined4 *)0x0) {
          return 0;
        }
        puVar2[4] = param_6;
        *puVar2 = param_2;
        puVar2[1] = param_3;
        puVar2[2] = param_4;
        puVar2[3] = param_5;
        return (int)puVar2;
      }
      if (*(int *)(param_1 + 0x7574) != 0) {
        return param_1;
      }
      uVar1 = 0x500;
    }
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return param_1;
    }
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return param_1;
}

/* _glCopyPixels_CompExec @ 0x62224 (88 bytes) */
int _glCopyPixels_CompExec(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glCopyPixels_Comp)(param_1,param_2,param_3,param_4,param_5,param_6);
  ((void (*)())_glCopyPixels_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,fparam_1,in_f2,in_f3,in_f4,
                     in_f5,in_f6,in_f7,in_f8);
  return;
}

