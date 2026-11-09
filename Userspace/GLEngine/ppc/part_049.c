#include "decls.h"

/* _gleExtractPixel_HILO_Uint @ 0xe513c (108 bytes) */
int _gleExtractPixel_HILO_Uint(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  double dVar1;
  double dVar2;
  
  dVar2 = DOUBLE_00108da0;
  dVar1 = DOUBLE_00108d70;
  *(float *)(param_1 + 0x20) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*param_2) - DOUBLE_00108d70) *
              DOUBLE_00108da0);
  *(float *)(param_1 + 0x24) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_2[1]) - dVar1) * dVar2);
  return;
}

/* _gleExtractPixel_HILO_Float @ 0xe51a8 (20 bytes) */
int _gleExtractPixel_HILO_Float(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *(undefined4 *)(param_1 + 0x20) = *param_2;
  *(undefined4 *)(param_1 + 0x24) = param_2[1];
  return;
}

/* _gleExtractPixel_DSDT_Byte @ 0xe51bc (116 bytes) */
int _gleExtractPixel_DSDT_Byte(param_1, param_2)
  int param_1;
  char *param_2;
{
  double dVar1;
  float fVar2;
  
  fVar2 = FLOAT_00108e98;
  dVar1 = DOUBLE_00108d58;
  *(float *)(param_1 + 0x28) =
       (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e98;
  *(float *)(param_1 + 0x2c) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - dVar1) * fVar2;
  return;
}

/* FUN_000e5234 @ 0xe5234 (100 bytes) */
int FUN_000e5234(param_1, param_2)
  int param_1;
  int param_2;
{
  float fVar1;
  uint unaff_r2;
  
  fVar1 = FLOAT_00108e78;
  *(float *)(param_1 + 0x28) = (GH_U2F((unsigned int)((unaff_r2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  *(float *)(param_1 + 0x2c) = (GH_U2F((unsigned int)((*(byte *)(param_2 + 1) | 0x4b000000))) - 8388608.0) * fVar1;
  return;
}

/* _gleExtractPixel_DSDT_Short @ 0xe5298 (108 bytes) */
int _gleExtractPixel_DSDT_Short(param_1, param_2)
  int param_1;
  short *param_2;
{
  double dVar1;
  float fVar2;
  
  fVar2 = FLOAT_00108e9c;
  dVar1 = DOUBLE_00108d58;
  *(float *)(param_1 + 0x28) =
       (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e9c;
  *(float *)(param_1 + 0x2c) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - dVar1) * fVar2;
  return;
}

/* FUN_000e5308 @ 0xe5308 (100 bytes) */
int FUN_000e5308(param_1, param_2)
  int param_1;
  int param_2;
{
  float fVar1;
  uint unaff_r2;
  
  fVar1 = FLOAT_00108e74;
  *(float *)(param_1 + 0x28) = (GH_U2F((unsigned int)((unaff_r2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(float *)(param_1 + 0x2c) = (GH_U2F((unsigned int)((*(ushort *)(param_2 + 2) | 0x4b000000))) - 8388608.0) * fVar1;
  return;
}

/* _gleExtractPixel_DSDT_Int @ 0xe536c (116 bytes) */
int _gleExtractPixel_DSDT_Int(param_1, param_2)
  int param_1;
  uint *param_2;
{
  double dVar1;
  double dVar2;
  
  dVar2 = DOUBLE_00108d88;
  dVar1 = DOUBLE_00108d58;
  *(float *)(param_1 + 0x28) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) - DOUBLE_00108d58)
              * DOUBLE_00108d88);
  *(float *)(param_1 + 0x2c) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_2[1] ^ 0x80000000) - dVar1) * dVar2
              );
  return;
}

/* _gleExtractPixel_DSDT_Uint @ 0xe53e0 (108 bytes) */
int _gleExtractPixel_DSDT_Uint(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  double dVar1;
  double dVar2;
  
  dVar2 = DOUBLE_00108da0;
  dVar1 = DOUBLE_00108d70;
  *(float *)(param_1 + 0x28) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*param_2) - DOUBLE_00108d70) *
              DOUBLE_00108da0);
  *(float *)(param_1 + 0x2c) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_2[1]) - dVar1) * dVar2);
  return;
}

/* _gleExtractPixel_DSDT_Float @ 0xe544c (20 bytes) */
int _gleExtractPixel_DSDT_Float(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *(undefined4 *)(param_1 + 0x28) = *param_2;
  *(undefined4 *)(param_1 + 0x2c) = param_2[1];
  return;
}

/* _gleExtractPixel_DSDT_MAG_Byte @ 0xe5460 (160 bytes) */
int _gleExtractPixel_DSDT_MAG_Byte(param_1, param_2)
  int param_1;
  char *param_2;
{
  char cVar1;
  double dVar2;
  float fVar3;
  
  fVar3 = FLOAT_00108e98;
  dVar2 = DOUBLE_00108d58;
  *(float *)(param_1 + 0x28) =
       (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e98;
  *(float *)(param_1 + 0x2c) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - dVar2) * fVar3;
  cVar1 = param_2[2];
  *(undefined4 *)(param_1 + 4) = 0;
  *(float *)(param_1 + 0x30) =
       (float)((double)CONCAT44(0x43300000,(int)cVar1 ^ 0x80000000) - dVar2) * fVar3;
  return;
}

/* FUN_000e5504 @ 0xe5504 (144 bytes) */
int FUN_000e5504(param_1, param_2)
  int param_1;
  int param_2;
{
  byte bVar1;
  float fVar2;
  uint unaff_r2;
  
  fVar2 = FLOAT_00108e78;
  *(float *)(param_1 + 0x28) = (GH_U2F((unsigned int)((unaff_r2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  *(float *)(param_1 + 0x2c) = (GH_U2F((unsigned int)((*(byte *)(param_2 + 1) | 0x4b000000))) - 8388608.0) * fVar2;
  bVar1 = *(byte *)(param_2 + 2);
  *(undefined4 *)(param_1 + 4) = 0;
  *(float *)(param_1 + 0x30) = (GH_U2F((unsigned int)((bVar1 | 0x4b000000))) - 8388608.0) * fVar2;
  return;
}

/* _gleExtractPixel_DSDT_MAG_Short @ 0xe5594 (148 bytes) */
int _gleExtractPixel_DSDT_MAG_Short(param_1, param_2)
  int param_1;
  short *param_2;
{
  short sVar1;
  double dVar2;
  float fVar3;
  
  fVar3 = FLOAT_00108e9c;
  dVar2 = DOUBLE_00108d58;
  *(float *)(param_1 + 0x28) =
       (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e9c;
  *(float *)(param_1 + 0x2c) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - dVar2) * fVar3;
  sVar1 = param_2[2];
  *(undefined4 *)(param_1 + 4) = 0;
  *(float *)(param_1 + 0x30) =
       (float)((double)CONCAT44(0x43300000,(int)sVar1 ^ 0x80000000) - dVar2) * fVar3;
  return;
}

/* FUN_000e562c @ 0xe562c (144 bytes) */
int FUN_000e562c(param_1, param_2)
  int param_1;
  int param_2;
{
  ushort uVar1;
  float fVar2;
  uint unaff_r2;
  
  fVar2 = FLOAT_00108e74;
  *(float *)(param_1 + 0x28) = (GH_U2F((unsigned int)((unaff_r2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(float *)(param_1 + 0x2c) = (GH_U2F((unsigned int)((*(ushort *)(param_2 + 2) | 0x4b000000))) - 8388608.0) * fVar2;
  uVar1 = *(ushort *)(param_2 + 4);
  *(undefined4 *)(param_1 + 4) = 0;
  *(float *)(param_1 + 0x30) = (GH_U2F((unsigned int)((uVar1 | 0x4b000000))) - 8388608.0) * fVar2;
  return;
}

/* _gleExtractPixel_DSDT_MAG_Int @ 0xe56bc (160 bytes) */
int _gleExtractPixel_DSDT_MAG_Int(param_1, param_2)
  int param_1;
  uint *param_2;
{
  double dVar1;
  double dVar2;
  uint uVar3;
  
  dVar2 = DOUBLE_00108d88;
  dVar1 = DOUBLE_00108d58;
  *(float *)(param_1 + 0x28) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) - DOUBLE_00108d58)
              * DOUBLE_00108d88);
  *(float *)(param_1 + 0x2c) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_2[1] ^ 0x80000000) - dVar1) * dVar2
              );
  uVar3 = param_2[2];
  *(undefined4 *)(param_1 + 4) = 0;
  *(float *)(param_1 + 0x30) =
       (float)((double)(float)((double)CONCAT44(0x43300000,uVar3 ^ 0x80000000) - dVar1) * dVar2);
  return;
}

/* _gleExtractPixel_DSDT_MAG_Uint @ 0xe575c (148 bytes) */
int _gleExtractPixel_DSDT_MAG_Uint(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  double dVar1;
  double dVar2;
  undefined4 uVar3;
  
  dVar2 = DOUBLE_00108da0;
  dVar1 = DOUBLE_00108d70;
  *(float *)(param_1 + 0x28) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*param_2) - DOUBLE_00108d70) *
              DOUBLE_00108da0);
  *(float *)(param_1 + 0x2c) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_2[1]) - dVar1) * dVar2);
  uVar3 = param_2[2];
  *(undefined4 *)(param_1 + 4) = 0;
  *(float *)(param_1 + 0x30) =
       (float)((double)(float)((double)CONCAT44(0x43300000,uVar3) - dVar1) * dVar2);
  return;
}

/* _gleExtractPixel_DSDT_MAG_Float @ 0xe57f0 (36 bytes) */
int _gleExtractPixel_DSDT_MAG_Float(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x28) = *param_2;
  *(undefined4 *)(param_1 + 0x2c) = param_2[1];
  uVar1 = param_2[2];
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0x30) = uVar1;
  return;
}

/* _gleExtractPixel_DSDT_MAG_VIB_S8_S8_8_8 @ 0xe5814 (200 bytes) */
int _gleExtractPixel_DSDT_MAG_VIB_S8_S8_8_8(param_1, param_2)
  int param_1;
  char *param_2;
{
  double dVar1;
  float fVar2;
  float fVar3;
  
  fVar3 = FLOAT_00108e98;
  fVar2 = FLOAT_00108e78;
  dVar1 = DOUBLE_00108d58;
  *(float *)(param_1 + 0x28) =
       (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e98;
  *(float *)(param_1 + 0x2c) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - dVar1) * fVar3;
  *(float *)(param_1 + 0x30) = (GH_U2F((unsigned int)(((byte)param_2[2] | 0x4b000000))) - 8388608.0) * fVar2;
  *(float *)(param_1 + 4) = (GH_U2F((unsigned int)(((byte)param_2[3] | 0x4b000000))) - 8388608.0) * fVar2;
  return;
}

/* _gleExtractPixel_DSDT_MAG_VIB_8_8_S8_S8_Rev @ 0xe58dc (196 bytes) */
int _gleExtractPixel_DSDT_MAG_VIB_8_8_S8_S8_Rev(param_1, param_2)
  int param_1;
  byte *param_2;
{
  double dVar1;
  float fVar2;
  float fVar3;
  
  fVar3 = FLOAT_00108e98;
  fVar2 = FLOAT_00108e78;
  dVar1 = DOUBLE_00108d58;
  *(float *)(param_1 + 0x28) =
       (float)((double)CONCAT44(0x43300000,(int)(char)param_2[3] ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e98;
  *(float *)(param_1 + 0x2c) =
       (float)((double)CONCAT44(0x43300000,(int)(char)param_2[2] ^ 0x80000000) - dVar1) * fVar3;
  *(float *)(param_1 + 0x30) = (GH_U2F((unsigned int)((param_2[1] | 0x4b000000))) - 8388608.0) * fVar2;
  *(float *)(param_1 + 4) = (GH_U2F((unsigned int)((*param_2 | 0x4b000000))) - 8388608.0) * fVar2;
  return;
}

/* _gleExtractPixel_DSDT_MAG_VIB_Byte @ 0xe59a0 (188 bytes) */
int _gleExtractPixel_DSDT_MAG_VIB_Byte(param_1, param_2)
  int param_1;
  char *param_2;
{
  double dVar1;
  float fVar2;
  
  fVar2 = FLOAT_00108e98;
  dVar1 = DOUBLE_00108d58;
  *(float *)(param_1 + 0x28) =
       (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e98;
  *(float *)(param_1 + 0x2c) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - dVar1) * fVar2;
  *(float *)(param_1 + 0x30) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[2] ^ 0x80000000) - dVar1) * fVar2;
  *(float *)(param_1 + 4) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[3] ^ 0x80000000) - dVar1) * fVar2;
  return;
}

/* FUN_000e5a60 @ 0xe5a60 (172 bytes) */
int FUN_000e5a60(param_1, param_2)
  int param_1;
  int param_2;
{
  float fVar1;
  uint unaff_r2;
  
  fVar1 = FLOAT_00108e78;
  *(float *)(param_1 + 0x28) = (GH_U2F((unsigned int)((unaff_r2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  *(float *)(param_1 + 0x2c) = (GH_U2F((unsigned int)((*(byte *)(param_2 + 1) | 0x4b000000))) - 8388608.0) * fVar1;
  *(float *)(param_1 + 0x30) = (GH_U2F((unsigned int)((*(byte *)(param_2 + 2) | 0x4b000000))) - 8388608.0) * fVar1;
  *(float *)(param_1 + 4) = (GH_U2F((unsigned int)((*(byte *)(param_2 + 3) | 0x4b000000))) - 8388608.0) * fVar1;
  return;
}

/* _gleExtractPixel_DSDT_MAG_VIB_Short @ 0xe5b0c (172 bytes) */
int _gleExtractPixel_DSDT_MAG_VIB_Short(param_1, param_2)
  int param_1;
  short *param_2;
{
  double dVar1;
  float fVar2;
  
  fVar2 = FLOAT_00108e9c;
  dVar1 = DOUBLE_00108d58;
  *(float *)(param_1 + 0x28) =
       (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e9c;
  *(float *)(param_1 + 0x2c) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - dVar1) * fVar2;
  *(float *)(param_1 + 0x30) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[2] ^ 0x80000000) - dVar1) * fVar2;
  *(float *)(param_1 + 4) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[3] ^ 0x80000000) - dVar1) * fVar2;
  return;
}

/* FUN_000e5bbc @ 0xe5bbc (172 bytes) */
int FUN_000e5bbc(param_1, param_2)
  int param_1;
  int param_2;
{
  float fVar1;
  uint unaff_r2;
  
  fVar1 = FLOAT_00108e74;
  *(float *)(param_1 + 0x28) = (GH_U2F((unsigned int)((unaff_r2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(float *)(param_1 + 0x2c) = (GH_U2F((unsigned int)((*(ushort *)(param_2 + 2) | 0x4b000000))) - 8388608.0) * fVar1;
  *(float *)(param_1 + 0x30) = (GH_U2F((unsigned int)((*(ushort *)(param_2 + 4) | 0x4b000000))) - 8388608.0) * fVar1;
  *(float *)(param_1 + 4) = (GH_U2F((unsigned int)((*(ushort *)(param_2 + 6) | 0x4b000000))) - 8388608.0) * fVar1;
  return;
}

/* _gleExtractPixel_DSDT_MAG_VIB_Int @ 0xe5c68 (188 bytes) */
int _gleExtractPixel_DSDT_MAG_VIB_Int(param_1, param_2)
  int param_1;
  uint *param_2;
{
  double dVar1;
  double dVar2;
  
  dVar2 = DOUBLE_00108d88;
  dVar1 = DOUBLE_00108d58;
  *(float *)(param_1 + 0x28) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) - DOUBLE_00108d58)
              * DOUBLE_00108d88);
  *(float *)(param_1 + 0x2c) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_2[1] ^ 0x80000000) - dVar1) * dVar2
              );
  *(float *)(param_1 + 0x30) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_2[2] ^ 0x80000000) - dVar1) * dVar2
              );
  *(float *)(param_1 + 4) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_2[3] ^ 0x80000000) - dVar1) * dVar2
              );
  return;
}

/* _gleExtractPixel_DSDT_MAG_VIB_Uint @ 0xe5d24 (172 bytes) */
int _gleExtractPixel_DSDT_MAG_VIB_Uint(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  double dVar1;
  double dVar2;
  
  dVar2 = DOUBLE_00108da0;
  dVar1 = DOUBLE_00108d70;
  *(float *)(param_1 + 0x28) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*param_2) - DOUBLE_00108d70) *
              DOUBLE_00108da0);
  *(float *)(param_1 + 0x2c) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_2[1]) - dVar1) * dVar2);
  *(float *)(param_1 + 0x30) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_2[2]) - dVar1) * dVar2);
  *(float *)(param_1 + 4) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_2[3]) - dVar1) * dVar2);
  return;
}

/* _gleExtractPixel_DSDT_MAG_VIB_Float @ 0xe5dd0 (36 bytes) */
int _gleExtractPixel_DSDT_MAG_VIB_Float(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *(undefined4 *)(param_1 + 0x28) = *param_2;
  *(undefined4 *)(param_1 + 0x2c) = param_2[1];
  *(undefined4 *)(param_1 + 0x30) = param_2[2];
  *(undefined4 *)(param_1 + 4) = param_2[3];
  return;
}

/* _gleImageSize @ 0xe5df4 (48 bytes) */
int _gleImageSize(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  
  iVar1 = _gleRowBytes(param_1,param_2,param_3);
  return iVar1 * param_4;
}

/* _gleFillImage @ 0xe5e24 (732 bytes) */
int _gleFillImage(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
  int param_6;
  int param_7;
  byte *param_8;
{
  bool bVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  byte bVar10;
  byte *pbVar9;
  int iVar11;
  undefined4 uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  char cVar16;
  int iVar17;
  byte *pbVar18;
  int iVar19;
  double dVar20;
  
  iVar6 = *(int *)(param_1 + 0x31cc);
  iVar19 = *(int *)(param_1 + 0x31e0);
  cVar16 = *(char *)(param_1 + 0x31e4);
  iVar15 = *(int *)(param_1 + 0x31d8);
  iVar14 = *(int *)(param_1 + 0x31d4);
  cVar2 = *(char *)(param_1 + 0x31e5);
  iVar11 = _gleComponents(param_5);
  if (iVar6 < 1) {
    iVar6 = param_2;
  }
  if (param_6 == 0x1a00) {
    iVar17 = iVar6 * iVar11 + 7 >> 3;
    iVar6 = iVar17 - (iVar17 / iVar19) * iVar19;
    if (iVar6 != 0) {
      iVar17 = iVar17 + (iVar19 - iVar6);
    }
    uVar8 = iVar15 * iVar11;
    iVar6 = ((int)uVar8 >> 3) + (uint)((int)uVar8 < 0 && (uVar8 & 7) != 0);
    uVar8 = uVar8 + iVar6 * -8;
    uVar13 = -uVar8 + 8;
    pbVar18 = (byte *)(param_7 + iVar14 * iVar17 + iVar6);
    bVar3 = *(byte *)(-uVar8 + 0x1111d0);
    bVar4 = (&_HighBitsMask)[uVar8];
    if (0 < param_3) {
      bVar1 = cVar2 == '\0';
      iVar6 = param_2 * iVar11;
      pbVar9 = pbVar18;
      do {
        while (iVar6 != 0) {
          if (bVar1) {
            bVar10 = *pbVar18;
          }
          else {
            bVar10 = (&___glMsbToLsbTable)[*pbVar18];
          }
          if (uVar8 != 0) {
            if ((int)uVar13 < iVar6) {
              if (bVar1) {
                bVar5 = pbVar18[1];
              }
              else {
                bVar5 = (&___glMsbToLsbTable)[pbVar18[1]];
              }
              bVar10 = (bVar10 & bVar3) << (uVar8 & 0x3f) |
                       (byte)((int)(uint)(bVar5 & bVar4) >> (uVar13 & 0x3f));
            }
            else {
              bVar10 = (bVar10 & bVar3) << (uVar8 & 0x3f);
            }
          }
          if (iVar6 < 8) {
            iVar14 = 0;
            *param_8 = (&_HighBitsMask)[iVar6] & bVar10;
          }
          else {
            *param_8 = bVar10;
            iVar14 = iVar6 + -8;
          }
          param_8 = param_8 + 1;
          pbVar18 = pbVar18 + 1;
          iVar6 = iVar14;
        }
        param_3 = param_3 + -1;
        pbVar18 = pbVar9 + iVar17;
        iVar6 = param_2 * iVar11;
        pbVar9 = pbVar18;
      } while (param_3 != 0);
    }
  }
  else {
    iVar17 = _glePixelBytes(param_5,param_6);
    if (param_6 - 0x1400U < 2) {
      cVar16 = '\0';
    }
    iVar6 = iVar6 * iVar17;
    iVar7 = iVar6 - (iVar6 / iVar19) * iVar19;
    if (iVar7 != 0) {
      iVar6 = iVar6 + (iVar19 - iVar7);
    }
    iVar14 = iVar14 * iVar6 + iVar15 * iVar17 + param_7;
    if (cVar16 == '\0') {
      uVar12 = _gleRowBytes(param_5,param_6,param_2);
      _gleCopy(iVar14,param_8,uVar12,param_3,iVar6,uVar12);
    }
    else {
      dVar20 = (double)((double (*)())_gleBytesPerElement)(param_6);
      iVar15 = (int)dVar20;
      if (0 < param_3) {
        do {
          iVar19 = param_2 * iVar11;
          iVar17 = iVar14;
          if (0 < param_2 * iVar11) {
            do {
              if (0 < iVar15) {
                pbVar9 = (byte *)(iVar15 + iVar17);
                pbVar18 = param_8;
                iVar7 = iVar15;
                do {
                  pbVar9 = pbVar9 + -1;
                  *pbVar18 = *pbVar9;
                  pbVar18 = pbVar18 + 1;
                  iVar7 = iVar7 + -1;
                } while (iVar7 != 0);
              }
              iVar19 = iVar19 + -1;
              param_8 = param_8 + iVar15;
              iVar17 = iVar17 + iVar15;
            } while (iVar19 != 0);
          }
          param_3 = param_3 + -1;
          iVar14 = iVar14 + iVar6;
        } while (param_3 != 0);
      }
    }
  }
  return;
}

/* _gleEmptyImage @ 0xe6100 (840 bytes) */
int _gleEmptyImage(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
  byte *param_6;
  int param_7;
{
  char cVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  byte *pbVar9;
  int iVar10;
  undefined4 uVar11;
  byte *pbVar12;
  uint uVar13;
  byte *pbVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  char cVar18;
  int iVar19;
  byte *pbVar20;
  int iVar21;
  double dVar22;
  
  iVar6 = *(int *)(param_1 + 0x31cc);
  iVar21 = *(int *)(param_1 + 0x31e0);
  cVar18 = *(char *)(param_1 + 0x31e4);
  iVar17 = *(int *)(param_1 + 0x31d8);
  iVar16 = *(int *)(param_1 + 0x31d4);
  cVar1 = *(char *)(param_1 + 0x31e5);
  iVar10 = _gleComponents(param_4);
  if (iVar6 < 1) {
    iVar6 = param_2;
  }
  if (param_5 == 0x1a00) {
    iVar19 = iVar6 * iVar10 + 7 >> 3;
    iVar6 = iVar19 - (iVar19 / iVar21) * iVar21;
    if (iVar6 != 0) {
      iVar19 = iVar19 + (iVar21 - iVar6);
    }
    uVar8 = iVar17 * iVar10;
    iVar6 = ((int)uVar8 >> 3) + (uint)((int)uVar8 < 0 && (uVar8 & 7) != 0);
    uVar8 = uVar8 + iVar6 * -8;
    pbVar20 = (byte *)(param_7 + iVar16 * iVar19 + iVar6);
    bVar2 = *(byte *)(-uVar8 + 0x1111d0);
    bVar3 = (&_HighBitsMask)[uVar8];
    if (0 < param_3) {
      do {
        uVar13 = 0;
        if (param_2 * iVar10 != 0) {
          pbVar12 = pbVar20;
          iVar6 = param_2 * iVar10;
          uVar15 = (uint)bVar2;
          do {
            if ((int)(iVar6 + uVar8) < 8) {
              uVar15 = uVar15 & (byte)(&_HighBitsMask)[iVar6 + uVar8];
            }
            if (cVar1 == '\0') {
              bVar4 = *pbVar12;
            }
            else {
              bVar4 = (&___glMsbToLsbTable)[*pbVar12];
            }
            if (uVar8 == 0) {
              uVar15 = (uint)bVar4 & ~uVar15 | *param_6 & uVar15;
            }
            else {
              uVar5 = uVar13 | (int)(uint)*param_6 >> (uVar8 & 0x3f) & 0xffU;
              uVar13 = (uint)*param_6 << (-uVar8 + 8 & 0x3f) & 0xff;
              uVar15 = (uint)bVar4 & ~uVar15 | uVar5 & uVar15;
            }
            if (cVar1 == '\0') {
              *pbVar12 = (byte)uVar15;
            }
            else {
              *pbVar12 = (&___glMsbToLsbTable)[uVar15];
            }
            if (iVar6 < 8) {
              iVar6 = 0;
            }
            else {
              iVar6 = iVar6 + -8;
            }
            param_6 = param_6 + 1;
            pbVar12 = pbVar12 + 1;
            uVar15 = 0xff;
          } while (iVar6 != 0);
          if (uVar13 != 0) {
            if (cVar1 == '\0') {
              bVar4 = *pbVar12;
            }
            else {
              bVar4 = (&___glMsbToLsbTable)[*pbVar12];
            }
            uVar13 = (uint)bVar4 & ~(uint)bVar3 | uVar13 & bVar3;
            if (cVar1 == '\0') {
              *pbVar12 = (byte)uVar13;
            }
            else {
              *pbVar12 = (&___glMsbToLsbTable)[uVar13];
            }
          }
        }
        param_3 = param_3 + -1;
        pbVar20 = pbVar20 + iVar19;
      } while (param_3 != 0);
    }
  }
  else {
    iVar19 = _glePixelBytes(param_4,param_5);
    if (param_5 - 0x1400U < 2) {
      cVar18 = '\0';
    }
    iVar6 = iVar6 * iVar19;
    iVar7 = iVar6 - (iVar6 / iVar21) * iVar21;
    if (iVar7 != 0) {
      iVar6 = iVar6 + (iVar21 - iVar7);
    }
    pbVar20 = (byte *)(iVar16 * iVar6 + iVar17 * iVar19 + param_7);
    if (cVar18 == '\0') {
      uVar11 = _gleRowBytes(param_4,param_5,param_2);
      _gleCopy(param_6,pbVar20,uVar11,param_3,uVar11,iVar6);
    }
    else {
      dVar22 = (double)((double (*)())_gleBytesPerElement)(param_5);
      iVar16 = (int)dVar22;
      if (0 < param_3) {
        do {
          pbVar12 = pbVar20;
          iVar17 = param_2 * iVar10;
          if (0 < param_2 * iVar10) {
            do {
              if (0 < iVar16) {
                pbVar9 = param_6 + iVar16;
                pbVar14 = pbVar12;
                iVar21 = iVar16;
                do {
                  pbVar9 = pbVar9 + -1;
                  *pbVar14 = *pbVar9;
                  pbVar14 = pbVar14 + 1;
                  iVar21 = iVar21 + -1;
                } while (iVar21 != 0);
              }
              iVar17 = iVar17 + -1;
              param_6 = param_6 + iVar16;
              pbVar12 = pbVar12 + iVar16;
            } while (iVar17 != 0);
          }
          param_3 = param_3 + -1;
          pbVar20 = pbVar20 + iVar6;
        } while (param_3 != 0);
      }
    }
  }
  return;
}

/* _gleModifyPixelStencil @ 0xe6448 (196 bytes) */
int _gleModifyPixelStencil(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar2 = *(uint *)(param_1 + 0x3214);
  uVar5 = *(uint *)(param_2 + 0x1c);
  uVar3 = *(uint *)(param_2 + 0x18);
  if ((int)uVar2 < 1) {
    if ((int)uVar2 < 0) {
      uVar1 = -uVar2;
      if ((int)uVar1 < 0xf) {
        uVar2 = uVar3 << (uVar2 + 0xf & 0x3f);
      }
      else {
        uVar2 = (int)uVar3 >> (uVar1 - 0xf & 0x3f);
      }
      uVar3 = (int)uVar3 >> (uVar1 & 0x3f);
      uVar5 = ((int)uVar5 >> (uVar1 & 0x3f) | uVar2) & 0x7fff;
    }
  }
  else {
    if ((int)uVar2 < 0xf) {
      uVar1 = (int)uVar5 >> (0xf - uVar2 & 0x3f);
    }
    else {
      uVar1 = uVar5 << (uVar2 - 0xf & 0x3f);
    }
    uVar3 = uVar3 << (uVar2 & 0x3f) | uVar1;
    uVar5 = uVar5 << (uVar2 & 0x3f);
  }
  iVar4 = uVar3 + *(int *)(param_1 + 0x3210);
  if ((*(uint *)(param_1 + 0x3414) & 2) != 0) {
    if (iVar4 < *(int *)(param_1 + 0x3274)) {
      iVar4 = *(int *)(iVar4 * 4 + *(int *)(param_1 + 0x326c));
    }
    else {
      iVar4 = *(int *)(*(int *)(param_1 + 0x3274) * 4 + *(int *)(param_1 + 0x326c) + -4);
    }
  }
  *(uint *)(param_2 + 0x1c) = uVar5;
  *(int *)(param_2 + 0x18) = iVar4;
  return;
}

/* _gleModifyPixelDepth @ 0xe650c (84 bytes) */
int _gleModifyPixelDepth(param_1, param_2)
  int param_1;
  int param_2;
{
  float fVar1;
  float fVar2;
  
  fVar1 = *(float *)(param_2 + 0x14) * *(float *)(param_1 + 0x320c) + *(float *)(param_1 + 0x3208);
  fVar2 = FLOAT_00108e50;
  if ((FLOAT_00108e50 <= fVar1) && (fVar2 = fVar1, FLOAT_00108e54 < fVar1)) {
    fVar2 = FLOAT_00108e54;
  }
  *(float *)(param_2 + 0x14) = fVar2;
  return;
}

/* _gleModifyPixelR @ 0xe6560 (200 bytes) */
void _gleModifyPixelR(int param_1,int param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11)
{
  uint uVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  
  fVar2 = *(float *)(param_2 + 4) * *(float *)(param_1 + 0x31ec) + *(float *)(param_1 + 0x31e8);
  if ((*(uint *)(param_1 + 0x3414) & 1) == 0) {
    fVar3 = FLOAT_00108e50;
    if ((fVar2 < FLOAT_00108e50) || (fVar3 = FLOAT_00108e54, FLOAT_00108e54 < fVar2)) {
      fVar2 = fVar3;
    }
  }
  else {
    uVar4 = *(int *)(param_1 + 0x3288) - 1;
    uVar1 = (uint)(int)(fVar2 * (float)((double)CONCAT44(0x43300000,uVar4 ^ 0x80000000) - DOUBLE_00108d58
                                  ) + FLOAT_00108e90);
    if (((int)uVar1 <= (int)uVar4) && (uVar4 = uVar1, (int)uVar1 < 0)) {
      uVar4 = 0;
    }
    fVar2 = *(float *)(uVar4 * 4 + *(int *)(param_1 + 0x325c));
  }
  *(float *)(param_2 + 4) = fVar2;
  return;
}

/* _gleModifyPixelG @ 0xe6628 (200 bytes) */
void _gleModifyPixelG(int param_1,int param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11)
{
  uint uVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  
  fVar2 = *(float *)(param_2 + 8) * *(float *)(param_1 + 0x31f4) + *(float *)(param_1 + 0x31f0);
  if ((*(uint *)(param_1 + 0x3414) & 1) == 0) {
    fVar3 = FLOAT_00108e50;
    if ((fVar2 < FLOAT_00108e50) || (fVar3 = FLOAT_00108e54, FLOAT_00108e54 < fVar2)) {
      fVar2 = fVar3;
    }
  }
  else {
    uVar4 = *(int *)(param_1 + 0x328c) - 1;
    uVar1 = (uint)(int)(fVar2 * (float)((double)CONCAT44(0x43300000,uVar4 ^ 0x80000000) - DOUBLE_00108d58
                                  ) + FLOAT_00108e90);
    if (((int)uVar1 <= (int)uVar4) && (uVar4 = uVar1, (int)uVar1 < 0)) {
      uVar4 = 0;
    }
    fVar2 = *(float *)(uVar4 * 4 + *(int *)(param_1 + 0x3260));
  }
  *(float *)(param_2 + 8) = fVar2;
  return;
}

/* _gleModifyPixelB @ 0xe66f0 (200 bytes) */
void _gleModifyPixelB(int param_1,int param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11)
{
  uint uVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  
  fVar2 = *(float *)(param_2 + 0xc) * *(float *)(param_1 + 0x31fc) + *(float *)(param_1 + 0x31f8);
  if ((*(uint *)(param_1 + 0x3414) & 1) == 0) {
    fVar3 = FLOAT_00108e50;
    if ((fVar2 < FLOAT_00108e50) || (fVar3 = FLOAT_00108e54, FLOAT_00108e54 < fVar2)) {
      fVar2 = fVar3;
    }
  }
  else {
    uVar4 = *(int *)(param_1 + 0x3290) - 1;
    uVar1 = (uint)(int)(fVar2 * (float)((double)CONCAT44(0x43300000,uVar4 ^ 0x80000000) - DOUBLE_00108d58
                                  ) + FLOAT_00108e90);
    if (((int)uVar1 <= (int)uVar4) && (uVar4 = uVar1, (int)uVar1 < 0)) {
      uVar4 = 0;
    }
    fVar2 = *(float *)(uVar4 * 4 + *(int *)(param_1 + 0x3264));
  }
  *(float *)(param_2 + 0xc) = fVar2;
  return;
}

/* _gleModifyPixelA @ 0xe67b8 (200 bytes) */
void _gleModifyPixelA(int param_1,int param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11)
{
  uint uVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  
  fVar2 = *(float *)(param_2 + 0x10) * *(float *)(param_1 + 0x3204) + *(float *)(param_1 + 0x3200);
  if ((*(uint *)(param_1 + 0x3414) & 1) == 0) {
    fVar3 = FLOAT_00108e50;
    if ((fVar2 < FLOAT_00108e50) || (fVar3 = FLOAT_00108e54, FLOAT_00108e54 < fVar2)) {
      fVar2 = fVar3;
    }
  }
  else {
    uVar4 = *(int *)(param_1 + 0x3294) - 1;
    uVar1 = (uint)(int)(fVar2 * (float)((double)CONCAT44(0x43300000,uVar4 ^ 0x80000000) - DOUBLE_00108d58
                                  ) + FLOAT_00108e90);
    if (((int)uVar1 <= (int)uVar4) && (uVar4 = uVar1, (int)uVar1 < 0)) {
      uVar4 = 0;
    }
    fVar2 = *(float *)(uVar4 * 4 + *(int *)(param_1 + 0x3268));
  }
  *(float *)(param_2 + 0x10) = fVar2;
  return;
}

/* _gleModifyPixelRGB @ 0xe6880 (488 bytes) */
int _gleModifyPixelRGB(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  fVar4 = *(float *)(param_2 + 4) * *(float *)(param_1 + 0x31ec) + *(float *)(param_1 + 0x31e8);
  fVar5 = *(float *)(param_2 + 8) * *(float *)(param_1 + 0x31f4) + *(float *)(param_1 + 0x31f0);
  fVar6 = *(float *)(param_2 + 0xc) * *(float *)(param_1 + 0x31fc) + *(float *)(param_1 + 0x31f8);
  if ((*(uint *)(param_1 + 0x3414) & 1) == 0) {
    fVar7 = FLOAT_00108e50;
    if ((fVar4 < FLOAT_00108e50) || (fVar7 = FLOAT_00108e54, FLOAT_00108e54 < fVar4)) {
      fVar4 = fVar7;
    }
    fVar7 = FLOAT_00108e50;
    if ((fVar5 < FLOAT_00108e50) || (fVar7 = FLOAT_00108e54, FLOAT_00108e54 < fVar5)) {
      fVar5 = fVar7;
    }
    fVar7 = FLOAT_00108e50;
    if ((fVar6 < FLOAT_00108e50) || (fVar7 = FLOAT_00108e54, FLOAT_00108e54 < fVar6)) {
      fVar6 = fVar7;
    }
  }
  else {
    uVar9 = *(int *)(param_1 + 0x3288) - 1;
    uVar10 = *(int *)(param_1 + 0x328c) - 1;
    uVar8 = *(int *)(param_1 + 0x3290) - 1;
    uVar1 = (uint)(int)(fVar4 * (float)((double)CONCAT44(0x43300000,uVar9 ^ 0x80000000) - DOUBLE_00108d58
                                  ) + FLOAT_00108e90);
    uVar2 = (uint)(int)(fVar5 * (float)((double)CONCAT44(0x43300000,uVar10 ^ 0x80000000) -
                                  DOUBLE_00108d58) + FLOAT_00108e90);
    uVar3 = (uint)(int)(fVar6 * (float)((double)CONCAT44(0x43300000,uVar8 ^ 0x80000000) - DOUBLE_00108d58
                                  ) + FLOAT_00108e90);
    if (((int)uVar1 <= (int)uVar9) && (uVar9 = uVar1, (int)uVar1 < 0)) {
      uVar9 = 0;
    }
    if (((int)uVar2 <= (int)uVar10) && (uVar10 = uVar2, (int)uVar2 < 0)) {
      uVar10 = 0;
    }
    if (((int)uVar3 <= (int)uVar8) && (uVar8 = uVar3, (int)uVar3 < 0)) {
      uVar8 = 0;
    }
    fVar4 = *(float *)(uVar9 * 4 + *(int *)(param_1 + 0x325c));
    fVar5 = *(float *)(uVar10 * 4 + *(int *)(param_1 + 0x3260));
    fVar6 = *(float *)(uVar8 * 4 + *(int *)(param_1 + 0x3264));
  }
  *(float *)(param_2 + 0xc) = fVar6;
  *(float *)(param_2 + 4) = fVar4;
  *(float *)(param_2 + 8) = fVar5;
  return;
}

/* _gleModifyPixelRGBA @ 0xe6a68 (636 bytes) */
int _gleModifyPixelRGBA(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  
  fVar5 = *(float *)(param_2 + 4) * *(float *)(param_1 + 0x31ec) + *(float *)(param_1 + 0x31e8);
  fVar6 = *(float *)(param_2 + 8) * *(float *)(param_1 + 0x31f4) + *(float *)(param_1 + 0x31f0);
  fVar7 = *(float *)(param_2 + 0xc) * *(float *)(param_1 + 0x31fc) + *(float *)(param_1 + 0x31f8);
  fVar8 = *(float *)(param_2 + 0x10) * *(float *)(param_1 + 0x3204) + *(float *)(param_1 + 0x3200);
  if ((*(uint *)(param_1 + 0x3414) & 1) == 0) {
    fVar9 = FLOAT_00108e50;
    if ((fVar5 < FLOAT_00108e50) || (fVar9 = FLOAT_00108e54, FLOAT_00108e54 < fVar5)) {
      fVar5 = fVar9;
    }
    fVar9 = FLOAT_00108e50;
    if ((fVar6 < FLOAT_00108e50) || (fVar9 = FLOAT_00108e54, FLOAT_00108e54 < fVar6)) {
      fVar6 = fVar9;
    }
    fVar9 = FLOAT_00108e50;
    if ((fVar7 < FLOAT_00108e50) || (fVar9 = FLOAT_00108e54, FLOAT_00108e54 < fVar7)) {
      fVar7 = fVar9;
    }
    fVar9 = FLOAT_00108e50;
    if ((fVar8 < FLOAT_00108e50) || (fVar9 = FLOAT_00108e54, FLOAT_00108e54 < fVar8)) {
      fVar8 = fVar9;
    }
  }
  else {
    uVar13 = *(int *)(param_1 + 0x3288) - 1;
    uVar12 = *(int *)(param_1 + 0x328c) - 1;
    uVar11 = *(int *)(param_1 + 0x3290) - 1;
    uVar10 = *(int *)(param_1 + 0x3294) - 1;
    uVar1 = (uint)(int)(fVar5 * (float)((double)CONCAT44(0x43300000,uVar13 ^ 0x80000000) -
                                  DOUBLE_00108d58) + FLOAT_00108e90);
    uVar2 = (uint)(int)(fVar6 * (float)((double)CONCAT44(0x43300000,uVar12 ^ 0x80000000) -
                                  DOUBLE_00108d58) + FLOAT_00108e90);
    uVar3 = (uint)(int)(fVar7 * (float)((double)CONCAT44(0x43300000,uVar11 ^ 0x80000000) -
                                  DOUBLE_00108d58) + FLOAT_00108e90);
    uVar4 = (uint)(int)(fVar8 * (float)((double)CONCAT44(0x43300000,uVar10 ^ 0x80000000) -
                                  DOUBLE_00108d58) + FLOAT_00108e90);
    if (((int)uVar1 <= (int)uVar13) && (uVar13 = uVar1, (int)uVar1 < 0)) {
      uVar13 = 0;
    }
    if (((int)uVar2 < (int)uVar12) && (uVar12 = uVar2, (int)uVar2 < 0)) {
      uVar12 = 0;
    }
    if (((int)uVar3 <= (int)uVar11) && (uVar11 = uVar3, (int)uVar3 < 0)) {
      uVar11 = 0;
    }
    if (((int)uVar4 <= (int)uVar10) && (uVar10 = uVar4, (int)uVar4 < 0)) {
      uVar10 = 0;
    }
    fVar5 = *(float *)(uVar13 * 4 + *(int *)(param_1 + 0x325c));
    fVar6 = *(float *)(uVar12 * 4 + *(int *)(param_1 + 0x3260));
    fVar7 = *(float *)(uVar11 * 4 + *(int *)(param_1 + 0x3264));
    fVar8 = *(float *)(uVar10 * 4 + *(int *)(param_1 + 0x3268));
  }
  *(float *)(param_2 + 0x10) = fVar8;
  *(float *)(param_2 + 4) = fVar5;
  *(float *)(param_2 + 8) = fVar6;
  *(float *)(param_2 + 0xc) = fVar7;
  return;
}

/* _gleModifyPixelRGBAIndex @ 0xe6ce4 (248 bytes) */
int _gleModifyPixelRGBAIndex(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar3 = *(uint *)(param_1 + 0x3214);
  uVar5 = *(uint *)(param_2 + 0x18);
  uVar4 = *(uint *)(param_2 + 0x1c);
  if ((int)uVar3 < 1) {
    if ((int)uVar3 < 0) {
      uVar2 = -uVar3;
      if ((int)uVar2 < 0xf) {
        uVar3 = uVar5 << (uVar3 + 0xf & 0x3f);
      }
      else {
        uVar3 = (int)uVar5 >> (uVar2 - 0xf & 0x3f);
      }
      uVar5 = (int)uVar5 >> (uVar2 & 0x3f);
      uVar4 = ((int)uVar4 >> (uVar2 & 0x3f) | uVar3) & 0x7fff;
    }
  }
  else {
    if ((int)uVar3 < 0xf) {
      uVar2 = (int)uVar4 >> (0xf - uVar3 & 0x3f);
    }
    else {
      uVar2 = uVar4 << (uVar3 - 0xf & 0x3f);
    }
    uVar5 = uVar5 << (uVar3 & 0x3f) | uVar2;
    uVar4 = uVar4 << (uVar3 & 0x3f);
  }
  uVar5 = uVar5 + *(int *)(param_1 + 0x3210);
  *(undefined4 *)(param_2 + 4) =
       *(undefined4 *)((uVar5 & *(int *)(param_1 + 0x3278) - 1U) * 4 + *(int *)(param_1 + 0x324c));
  *(undefined4 *)(param_2 + 8) =
       *(undefined4 *)((uVar5 & *(int *)(param_1 + 0x327c) - 1U) * 4 + *(int *)(param_1 + 0x3250));
  *(undefined4 *)(param_2 + 0xc) =
       *(undefined4 *)((uVar5 & *(int *)(param_1 + 0x3280) - 1U) * 4 + *(int *)(param_1 + 0x3254));
  uVar1 = *(undefined4 *)
           ((uVar5 & *(int *)(param_1 + 0x3284) - 1U) * 4 + *(int *)(param_1 + 0x3258));
  *(uint *)(param_2 + 0x1c) = uVar4;
  *(undefined4 *)(param_2 + 0x10) = uVar1;
  *(uint *)(param_2 + 0x18) = uVar5;
  return;
}

/* _gleModifyPixelHILO @ 0xe6ddc (132 bytes) */
void _gleModifyPixelHILO(int param_1,int param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10)
{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = *(float *)(param_2 + 0x20) * *(float *)(param_1 + 0x321c) + *(float *)(param_1 + 0x3218);
  fVar2 = *(float *)(param_2 + 0x24) * *(float *)(param_1 + 0x3224) + *(float *)(param_1 + 0x3220);
  fVar3 = FLOAT_00108e54;
  if ((FLOAT_00108e54 < fVar1) || (fVar3 = FLOAT_00108e58, fVar1 < FLOAT_00108e58)) {
    fVar1 = fVar3;
  }
  fVar3 = FLOAT_00108e54;
  if ((FLOAT_00108e54 < fVar2) || (fVar3 = FLOAT_00108e58, fVar2 < FLOAT_00108e58)) {
    fVar2 = fVar3;
  }
  *(float *)(param_2 + 0x24) = fVar2;
  *(float *)(param_2 + 0x20) = fVar1;
  return;
}

/* _gleModifyPixelDSDTMagVib @ 0xe6e60 (252 bytes) */
void _gleModifyPixelDSDTMagVib(int param_1,int param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar1 = *(float *)(param_2 + 0x28) * *(float *)(param_1 + 0x322c) + *(float *)(param_1 + 0x3228);
  fVar5 = *(float *)(param_2 + 0x2c) * *(float *)(param_1 + 0x3234) + *(float *)(param_1 + 0x3230);
  fVar4 = *(float *)(param_2 + 0x30) * *(float *)(param_1 + 0x323c) + *(float *)(param_1 + 0x3238);
  fVar2 = *(float *)(param_2 + 4) * *(float *)(param_1 + 0x3244) + *(float *)(param_1 + 0x3240);
  fVar3 = FLOAT_00108e54;
  if ((fVar1 <= FLOAT_00108e54) && (fVar3 = fVar1, fVar1 < FLOAT_00108e58)) {
    fVar3 = FLOAT_00108e58;
  }
  fVar1 = FLOAT_00108e54;
  if ((FLOAT_00108e54 < fVar5) || (fVar1 = FLOAT_00108e58, fVar5 < FLOAT_00108e58)) {
    fVar5 = fVar1;
  }
  fVar1 = FLOAT_00108e54;
  if ((FLOAT_00108e54 < fVar4) || (fVar1 = FLOAT_00108e50, fVar4 < FLOAT_00108e50)) {
    fVar4 = fVar1;
  }
  fVar1 = FLOAT_00108e54;
  if ((FLOAT_00108e54 < fVar2) || (fVar1 = FLOAT_00108e50, fVar2 < FLOAT_00108e50)) {
    fVar2 = fVar1;
  }
  *(float *)(param_2 + 4) = fVar2;
  *(float *)(param_2 + 0x28) = fVar3;
  *(float *)(param_2 + 0x2c) = fVar5;
  *(float *)(param_2 + 0x30) = fVar4;
  return;
}

/* _gleModifyPixelSignedRGBA @ 0xe6f5c (636 bytes) */
int _gleModifyPixelSignedRGBA(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  
  fVar5 = *(float *)(param_2 + 4) * *(float *)(param_1 + 0x31ec) + *(float *)(param_1 + 0x31e8);
  fVar6 = *(float *)(param_2 + 8) * *(float *)(param_1 + 0x31f4) + *(float *)(param_1 + 0x31f0);
  fVar7 = *(float *)(param_2 + 0xc) * *(float *)(param_1 + 0x31fc) + *(float *)(param_1 + 0x31f8);
  fVar8 = *(float *)(param_2 + 0x10) * *(float *)(param_1 + 0x3204) + *(float *)(param_1 + 0x3200);
  if ((*(uint *)(param_1 + 0x3414) & 1) == 0) {
    fVar9 = FLOAT_00108e58;
    if ((fVar5 < FLOAT_00108e58) || (fVar9 = FLOAT_00108e54, FLOAT_00108e54 < fVar5)) {
      fVar5 = fVar9;
    }
    fVar9 = FLOAT_00108e58;
    if ((fVar6 < FLOAT_00108e58) || (fVar9 = FLOAT_00108e54, FLOAT_00108e54 < fVar6)) {
      fVar6 = fVar9;
    }
    fVar9 = FLOAT_00108e58;
    if ((fVar7 < FLOAT_00108e58) || (fVar9 = FLOAT_00108e54, FLOAT_00108e54 < fVar7)) {
      fVar7 = fVar9;
    }
    fVar9 = FLOAT_00108e58;
    if ((fVar8 < FLOAT_00108e58) || (fVar9 = FLOAT_00108e54, FLOAT_00108e54 < fVar8)) {
      fVar8 = fVar9;
    }
  }
  else {
    uVar13 = *(int *)(param_1 + 0x3288) - 1;
    uVar12 = *(int *)(param_1 + 0x328c) - 1;
    uVar11 = *(int *)(param_1 + 0x3290) - 1;
    uVar10 = *(int *)(param_1 + 0x3294) - 1;
    uVar1 = (uint)(int)(fVar5 * (float)((double)CONCAT44(0x43300000,uVar13 ^ 0x80000000) -
                                  DOUBLE_00108d58) + FLOAT_00108e90);
    uVar2 = (uint)(int)(fVar6 * (float)((double)CONCAT44(0x43300000,uVar12 ^ 0x80000000) -
                                  DOUBLE_00108d58) + FLOAT_00108e90);
    uVar3 = (uint)(int)(fVar7 * (float)((double)CONCAT44(0x43300000,uVar11 ^ 0x80000000) -
                                  DOUBLE_00108d58) + FLOAT_00108e90);
    uVar4 = (uint)(int)(fVar8 * (float)((double)CONCAT44(0x43300000,uVar10 ^ 0x80000000) -
                                  DOUBLE_00108d58) + FLOAT_00108e90);
    if (((int)uVar1 <= (int)uVar13) && (uVar13 = uVar1, (int)uVar1 < 0)) {
      uVar13 = 0;
    }
    if (((int)uVar2 < (int)uVar12) && (uVar12 = uVar2, (int)uVar2 < 0)) {
      uVar12 = 0;
    }
    if (((int)uVar3 <= (int)uVar11) && (uVar11 = uVar3, (int)uVar3 < 0)) {
      uVar11 = 0;
    }
    if (((int)uVar4 <= (int)uVar10) && (uVar10 = uVar4, (int)uVar4 < 0)) {
      uVar10 = 0;
    }
    fVar5 = *(float *)(uVar13 * 4 + *(int *)(param_1 + 0x325c));
    fVar6 = *(float *)(uVar12 * 4 + *(int *)(param_1 + 0x3260));
    fVar7 = *(float *)(uVar11 * 4 + *(int *)(param_1 + 0x3264));
    fVar8 = *(float *)(uVar10 * 4 + *(int *)(param_1 + 0x3268));
  }
  *(float *)(param_2 + 0x10) = fVar8;
  *(float *)(param_2 + 4) = fVar5;
  *(float *)(param_2 + 8) = fVar6;
  *(float *)(param_2 + 0xc) = fVar7;
  return;
}

/* _gleModifyPixelSignedRGB_UnsignedA @ 0xe71d8 (636 bytes) */
int _gleModifyPixelSignedRGB_UnsignedA(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  
  fVar5 = *(float *)(param_2 + 4) * *(float *)(param_1 + 0x31ec) + *(float *)(param_1 + 0x31e8);
  fVar6 = *(float *)(param_2 + 8) * *(float *)(param_1 + 0x31f4) + *(float *)(param_1 + 0x31f0);
  fVar7 = *(float *)(param_2 + 0xc) * *(float *)(param_1 + 0x31fc) + *(float *)(param_1 + 0x31f8);
  fVar8 = *(float *)(param_2 + 0x10) * *(float *)(param_1 + 0x3204) + *(float *)(param_1 + 0x3200);
  if ((*(uint *)(param_1 + 0x3414) & 1) == 0) {
    fVar9 = FLOAT_00108e58;
    if ((fVar5 < FLOAT_00108e58) || (fVar9 = FLOAT_00108e54, FLOAT_00108e54 < fVar5)) {
      fVar5 = fVar9;
    }
    fVar9 = FLOAT_00108e58;
    if ((fVar6 < FLOAT_00108e58) || (fVar9 = FLOAT_00108e54, FLOAT_00108e54 < fVar6)) {
      fVar6 = fVar9;
    }
    fVar9 = FLOAT_00108e58;
    if ((fVar7 < FLOAT_00108e58) || (fVar9 = FLOAT_00108e54, FLOAT_00108e54 < fVar7)) {
      fVar7 = fVar9;
    }
    fVar9 = FLOAT_00108e50;
    if ((fVar8 < FLOAT_00108e50) || (fVar9 = FLOAT_00108e54, FLOAT_00108e54 < fVar8)) {
      fVar8 = fVar9;
    }
  }
  else {
    uVar13 = *(int *)(param_1 + 0x3288) - 1;
    uVar12 = *(int *)(param_1 + 0x328c) - 1;
    uVar11 = *(int *)(param_1 + 0x3290) - 1;
    uVar10 = *(int *)(param_1 + 0x3294) - 1;
    uVar1 = (uint)(int)(fVar5 * (float)((double)CONCAT44(0x43300000,uVar13 ^ 0x80000000) -
                                  DOUBLE_00108d58) + FLOAT_00108e90);
    uVar2 = (uint)(int)(fVar6 * (float)((double)CONCAT44(0x43300000,uVar12 ^ 0x80000000) -
                                  DOUBLE_00108d58) + FLOAT_00108e90);
    uVar3 = (uint)(int)(fVar7 * (float)((double)CONCAT44(0x43300000,uVar11 ^ 0x80000000) -
                                  DOUBLE_00108d58) + FLOAT_00108e90);
    uVar4 = (uint)(int)(fVar8 * (float)((double)CONCAT44(0x43300000,uVar10 ^ 0x80000000) -
                                  DOUBLE_00108d58) + FLOAT_00108e90);
    if (((int)uVar1 <= (int)uVar13) && (uVar13 = uVar1, (int)uVar1 < 0)) {
      uVar13 = 0;
    }
    if (((int)uVar2 < (int)uVar12) && (uVar12 = uVar2, (int)uVar2 < 0)) {
      uVar12 = 0;
    }
    if (((int)uVar3 <= (int)uVar11) && (uVar11 = uVar3, (int)uVar3 < 0)) {
      uVar11 = 0;
    }
    if (((int)uVar4 <= (int)uVar10) && (uVar10 = uVar4, (int)uVar4 < 0)) {
      uVar10 = 0;
    }
    fVar5 = *(float *)(uVar13 * 4 + *(int *)(param_1 + 0x325c));
    fVar6 = *(float *)(uVar12 * 4 + *(int *)(param_1 + 0x3260));
    fVar7 = *(float *)(uVar11 * 4 + *(int *)(param_1 + 0x3264));
    fVar8 = *(float *)(uVar10 * 4 + *(int *)(param_1 + 0x3268));
  }
  *(float *)(param_2 + 0x10) = fVar8;
  *(float *)(param_2 + 4) = fVar5;
  *(float *)(param_2 + 8) = fVar6;
  *(float *)(param_2 + 0xc) = fVar7;
  return;
}

/* _gleSelectPixelInsertFunc @ 0xe7454 (2464 bytes) */
int _gleSelectPixelInsertFunc(param_1, param_2)
  uint param_1;
  uint param_2;
{
  if (param_1 == 0x1906) {
    switch(param_2) {
    case 0x1400:
      return PTR__gleInsertPixel_A_Byte_0011125c;
    case 0x1401:
      return PTR__gleInsertPixel_A_Ubyte_00111258;
    case 0x1402:
      return PTR__gleInsertPixel_A_Short_00111254;
    case 0x1403:
      return PTR__gleInsertPixel_A_Ushort_00111250;
    case 0x1404:
      return PTR__gleInsertPixel_A_Int_0011124c;
    case 0x1405:
      return PTR__gleInsertPixel_A_Uint_00111248;
    default:
      return PTR__gleInsertPixel_A_Float_00111244;
    }
  }
  if (param_1 < 0x1907) {
    if (param_1 == 0x1902) {
      switch(param_2) {
      case 0x1400:
        return PTR__gleInsertPixel_Depth_Byte_001113a8;
      case 0x1401:
        return PTR__gleInsertPixel_Depth_Ubyte_001113a4;
      case 0x1402:
        return PTR__gleInsertPixel_Depth_Short_001113a0;
      case 0x1403:
        return PTR__gleInsertPixel_Depth_Ushort_0011139c;
      case 0x1404:
        return PTR__gleInsertPixel_Depth_Int_00111398;
      case 0x1405:
        return PTR__gleInsertPixel_Depth_Uint_00111394;
      default:
        return PTR__gleInsertPixel_Depth_Float_00111390;
      }
    }
    if (0x1902 < param_1) {
      if (param_1 == 0x1904) {
        switch(param_2) {
        case 0x1400:
          return PTR__gleInsertPixel_G_Byte_00111294;
        case 0x1401:
          return PTR__gleInsertPixel_G_Ubyte_00111290;
        case 0x1402:
          return PTR__gleInsertPixel_G_Short_0011128c;
        case 0x1403:
          return PTR__gleInsertPixel_G_Ushort_00111288;
        case 0x1404:
          return PTR__gleInsertPixel_G_Int_00111284;
        case 0x1405:
          return PTR__gleInsertPixel_G_Uint_00111280;
        default:
          return PTR__gleInsertPixel_G_Float_0011127c;
        }
      }
      if (0x1904 < param_1) {
        switch(param_2) {
        case 0x1400:
          return PTR__gleInsertPixel_B_Byte_00111278;
        case 0x1401:
          return PTR__gleInsertPixel_B_Ubyte_00111274;
        case 0x1402:
          return PTR__gleInsertPixel_B_Short_00111270;
        case 0x1403:
          return PTR__gleInsertPixel_B_Ushort_0011126c;
        case 0x1404:
          return PTR__gleInsertPixel_B_Int_00111268;
        case 0x1405:
          return PTR__gleInsertPixel_B_Uint_00111264;
        default:
          return PTR__gleInsertPixel_B_Float_00111260;
        }
      }
      switch(param_2) {
      case 0x1400:
        return PTR__gleInsertPixel_R_Byte_001112b0;
      case 0x1401:
        return PTR__gleInsertPixel_R_Ubyte_001112ac;
      case 0x1402:
        return PTR__gleInsertPixel_R_Short_001112a8;
      case 0x1403:
        return PTR__gleInsertPixel_R_Ushort_001112a4;
      case 0x1404:
        return PTR__gleInsertPixel_R_Int_001112a0;
      case 0x1405:
        return PTR__gleInsertPixel_R_Uint_0011129c;
      default:
        return PTR__gleInsertPixel_R_Float_00111298;
      }
    }
    if (0x18ff < param_1) {
      switch(param_2) {
      case 0x1400:
        return PTR__gleInsertPixel_Index_Byte_001113c4;
      case 0x1401:
        return PTR__gleInsertPixel_Index_Ubyte_001113c0;
      case 0x1402:
        return PTR__gleInsertPixel_Index_Short_001113bc;
      case 0x1403:
        return PTR__gleInsertPixel_Index_Ushort_001113b8;
      case 0x1404:
        return PTR__gleInsertPixel_Index_Int_001113b4;
      case 0x1405:
        return PTR__gleInsertPixel_Index_Uint_001113b0;
      default:
        return PTR__gleInsertPixel_Index_Float_001113ac;
      }
    }
  }
  else {
    if (param_1 == 0x1909) {
      switch(param_2) {
      case 0x1400:
        return PTR__gleInsertPixel_L_Byte_00111240;
      case 0x1401:
        return PTR__gleInsertPixel_L_Ubyte_0011123c;
      case 0x1402:
        return PTR__gleInsertPixel_L_Short_00111238;
      case 0x1403:
        return PTR__gleInsertPixel_L_Ushort_00111234;
      case 0x1404:
        return PTR__gleInsertPixel_L_Int_00111230;
      case 0x1405:
        return PTR__gleInsertPixel_L_Uint_0011122c;
      default:
        return PTR__gleInsertPixel_L_Float_00111228;
      }
    }
    if (param_1 < 0x190a) {
      if (param_1 == 0x1907) {
        if (param_2 == 0x1404) {
          return PTR__gleInsertPixel_RGB_Int_001112cc;
        }
        if (param_2 < 0x1405) {
          if (param_2 == 0x1401) {
            return PTR__gleInsertPixel_RGB_Ubyte_001112d8;
          }
          if (param_2 < 0x1402) {
            if (param_2 == 0x1400) {
              return PTR__gleInsertPixel_RGB_Byte_001112dc;
            }
          }
          else {
            if (param_2 == 0x1402) {
              return PTR__gleInsertPixel_RGB_Short_001112d4;
            }
            if (param_2 == 0x1403) {
              return PTR__gleInsertPixel_RGB_Ushort_001112d0;
            }
          }
        }
        else {
          if (param_2 == 0x8032) {
            return PTR__gleInsertPixel_RGB_332_001112c0;
          }
          if (param_2 < 0x8033) {
            if (param_2 == 0x1405) {
              return PTR__gleInsertPixel_RGB_Uint_001112c8;
            }
            if (param_2 == 0x1406) {
              return PTR__gleInsertPixel_RGB_Float_001112c4;
            }
          }
          else {
            if (param_2 == 0x8362) {
              return PTR__gleInsertPixel_RGB_233Rev_001112bc;
            }
            if (param_2 == 0x8363) {
              return PTR__gleInsertPixel_RGB_565_001112b8;
            }
          }
        }
        return PTR__gleInsertPixel_RGB_565Rev_001112b4;
      }
      if (param_1 == 0x1908) {
        if (param_2 == 0x1406) {
          return PTR__gleInsertPixel_RGBA_Float_00111374;
        }
        if (param_2 < 0x1407) {
          if (param_2 == 0x1402) {
            return PTR__gleInsertPixel_RGBA_Short_00111384;
          }
          if (0x1402 < param_2) {
            if (param_2 == 0x1404) {
              return PTR__gleInsertPixel_RGBA_Int_0011137c;
            }
            if (0x1404 < param_2) {
              return PTR__gleInsertPixel_RGBA_Uint_00111378;
            }
            return PTR__gleInsertPixel_RGBA_Ushort_00111380;
          }
          if (param_2 == 0x1400) {
            return PTR__gleInsertPixel_RGBA_Byte_0011138c;
          }
          if (param_2 == 0x1401) {
            return PTR__gleInsertPixel_RGBA_Ubyte_00111388;
          }
        }
        else {
          if (param_2 == 0x8036) {
            return PTR__gleInsertPixel_RGBA_1010102_00111358;
          }
          if (param_2 < 0x8037) {
            if (param_2 == 0x8034) {
              return PTR__gleInsertPixel_RGBA_5551_00111368;
            }
            if (0x8034 < param_2) {
              return PTR__gleInsertPixel_RGBA_8888_00111360;
            }
            if (param_2 == 0x8033) {
              return PTR__gleInsertPixel_RGBA_4444_00111370;
            }
          }
          else {
            if (param_2 == 0x8366) {
              return PTR__gleInsertPixel_RGBA_1555Rev_00111364;
            }
            if (param_2 < 0x8367) {
              if (param_2 == 0x8365) {
                return PTR__gleInsertPixel_RGBA_4444Rev_0011136c;
              }
            }
            else if (param_2 == 0x8367) {
              return PTR__gleInsertPixel_RGBA_8888Rev_0011135c;
            }
          }
        }
        return PTR__gleInsertPixel_RGBA_2101010Rev_00111354;
      }
    }
    else {
      if (param_1 == 0x80e0) {
        switch(param_2) {
        case 0x1400:
          return PTR__gleInsertPixel_BGR_EXT_Byte_001112f8;
        case 0x1401:
          return PTR__gleInsertPixel_BGR_EXT_Ubyte_001112f4;
        case 0x1402:
          return PTR__gleInsertPixel_BGR_EXT_Short_001112f0;
        case 0x1403:
          return PTR__gleInsertPixel_BGR_EXT_Ushort_001112ec;
        case 0x1404:
          return PTR__gleInsertPixel_BGR_EXT_Int_001112e8;
        case 0x1405:
          return PTR__gleInsertPixel_BGR_EXT_Uint_001112e4;
        default:
          return PTR__gleInsertPixel_BGR_EXT_Float_001112e0;
        }
      }
      if (param_1 < 0x80e1) {
        if (param_1 == 0x8000) {
          switch(param_2) {
          case 0x1400:
            return PTR__gleInsertPixel_ABGR_EXT_Byte_00111350;
          case 0x1401:
            return PTR__gleInsertPixel_ABGR_EXT_Ubyte_0011134c;
          case 0x1402:
            return PTR__gleInsertPixel_ABGR_EXT_Short_00111348;
          case 0x1403:
            return PTR__gleInsertPixel_ABGR_EXT_Ushort_00111344;
          case 0x1404:
            return PTR__gleInsertPixel_ABGR_EXT_Int_00111340;
          case 0x1405:
            return PTR__gleInsertPixel_ABGR_EXT_Uint_0011133c;
          default:
            return PTR__gleInsertPixel_ABGR_EXT_Float_00111338;
          }
        }
      }
      else if (param_1 == 0x80e1) {
        if (param_2 == 0x1406) {
          return PTR__gleInsertPixel_BGRA_EXT_Float_0011131c;
        }
        if (param_2 < 0x1407) {
          if (param_2 == 0x1402) {
            return PTR__gleInsertPixel_BGRA_EXT_Short_0011132c;
          }
          if (0x1402 < param_2) {
            if (param_2 == 0x1404) {
              return PTR__gleInsertPixel_BGRA_EXT_Int_00111324;
            }
            if (0x1404 < param_2) {
              return PTR__gleInsertPixel_BGRA_EXT_Uint_00111320;
            }
            return PTR__gleInsertPixel_BGRA_EXT_Ushort_00111328;
          }
          if (param_2 == 0x1400) {
            return PTR__gleInsertPixel_BGRA_EXT_Byte_00111334;
          }
          if (param_2 == 0x1401) {
            return PTR__gleInsertPixel_BGRA_EXT_Ubyte_00111330;
          }
        }
        else {
          if (param_2 == 0x8036) {
            return PTR__gleInsertPixel_BGRA_1010102_00111300;
          }
          if (param_2 < 0x8037) {
            if (param_2 == 0x8034) {
              return PTR__gleInsertPixel_BGRA_5551_00111310;
            }
            if (0x8034 < param_2) {
              return PTR__gleInsertPixel_BGRA_8888_00111308;
            }
            if (param_2 == 0x8033) {
              return PTR__gleInsertPixel_BGRA_4444_00111318;
            }
          }
          else {
            if (param_2 == 0x8366) {
              return PTR__gleInsertPixel_BGRA_1555Rev_0011130c;
            }
            if (param_2 < 0x8367) {
              if (param_2 == 0x8365) {
                return PTR__gleInsertPixel_BGRA_4444Rev_00111314;
              }
            }
            else if (param_2 == 0x8367) {
              return PTR__gleInsertPixel_BGRA_8888Rev_00111304;
            }
          }
        }
        return PTR__gleInsertPixel_BGRA_2101010Rev_001112fc;
      }
    }
  }
  switch(param_2) {
  case 0x1400:
    return PTR__gleInsertPixel_LA_Byte_00111224;
  case 0x1401:
    return PTR__gleInsertPixel_LA_Ubyte_00111220;
  case 0x1402:
    return PTR__gleInsertPixel_LA_Short_0011121c;
  case 0x1403:
    return PTR__gleInsertPixel_LA_Ushort_00111218;
  case 0x1404:
    return PTR__gleInsertPixel_LA_Int_00111214;
  case 0x1405:
    return PTR__gleInsertPixel_LA_Uint_00111210;
  default:
    return PTR__gleInsertPixel_LA_Float_0011120c;
  }
}

/* _gleInsertPixel_RGBA_Byte @ 0xe7ee4 (124 bytes) */
int _gleInsertPixel_RGBA_Byte(param_1, param_2)
  int param_1;
  undefined1 *param_2;
{
  float fVar1;
  
  fVar1 = FLOAT_00108f6c;
  *param_2 = (char)(int)(*(float *)(param_1 + 4) * FLOAT_00108f6c);
  param_2[1] = (char)(int)(*(float *)(param_1 + 8) * fVar1);
  param_2[2] = (char)(int)(*(float *)(param_1 + 0xc) * fVar1);
  param_2[3] = (char)(int)(*(float *)(param_1 + 0x10) * fVar1);
  return;
}

/* _gleInsertPixel_RGBA_Ubyte @ 0xe7f60 (124 bytes) */
int _gleInsertPixel_RGBA_Ubyte(param_1, param_2)
  int param_1;
  undefined1 *param_2;
{
  float fVar1;
  
  fVar1 = FLOAT_00108f70;
  *param_2 = (char)(int)(*(float *)(param_1 + 4) * FLOAT_00108f70);
  param_2[1] = (char)(int)(*(float *)(param_1 + 8) * fVar1);
  param_2[2] = (char)(int)(*(float *)(param_1 + 0xc) * fVar1);
  param_2[3] = (char)(int)(*(float *)(param_1 + 0x10) * fVar1);
  return;
}

/* _gleInsertPixel_RGBA_Short @ 0xe7fdc (124 bytes) */
int _gleInsertPixel_RGBA_Short(param_1, param_2)
  int param_1;
  undefined2 *param_2;
{
  float fVar1;
  
  fVar1 = FLOAT_00108f74;
  *param_2 = (short)(int)(*(float *)(param_1 + 4) * FLOAT_00108f74);
  param_2[1] = (short)(int)(*(float *)(param_1 + 8) * fVar1);
  param_2[2] = (short)(int)(*(float *)(param_1 + 0xc) * fVar1);
  param_2[3] = (short)(int)(*(float *)(param_1 + 0x10) * fVar1);
  return;
}

/* _gleInsertPixel_RGBA_Ushort @ 0xe8058 (124 bytes) */
int _gleInsertPixel_RGBA_Ushort(param_1, param_2)
  int param_1;
  undefined2 *param_2;
{
  float fVar1;
  
  fVar1 = FLOAT_00108ea0;
  *param_2 = (short)(int)(*(float *)(param_1 + 4) * FLOAT_00108ea0);
  param_2[1] = (short)(int)(*(float *)(param_1 + 8) * fVar1);
  param_2[2] = (short)(int)(*(float *)(param_1 + 0xc) * fVar1);
  param_2[3] = (short)(int)(*(float *)(param_1 + 0x10) * fVar1);
  return;
}

/* FUN_000e80d8 @ 0xe80d8 (120 bytes) */
void FUN_000e80d8(int param_1,int *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  double dVar1;
  double in_f13;
  
  dVar1 = DOUBLE_00108d90;
  *param_2 = (int)(in_f13 * DOUBLE_00108d90);
  param_2[1] = (int)((double)*(float *)(param_1 + 8) * dVar1);
  param_2[2] = (int)((double)*(float *)(param_1 + 0xc) * dVar1);
  param_2[3] = (int)((double)*(float *)(param_1 + 0x10) * dVar1);
  return;
}

/* _gleInsertPixel_RGBA_Uint @ 0xe8150 (312 bytes) */
int _gleInsertPixel_RGBA_Uint(param_1, param_2)
  int param_1;
  uint *param_2;
{
  uint uVar1;
  double dVar2;
  
  dVar2 = (double)*(float *)(param_1 + 4) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= dVar2) {
    uVar1 = (int)(dVar2 - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    uVar1 = (uint)(int)dVar2;
  }
  *param_2 = uVar1;
  dVar2 = (double)*(float *)(param_1 + 8) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= dVar2) {
    uVar1 = (int)(dVar2 - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    uVar1 = (uint)(int)dVar2;
  }
  param_2[1] = uVar1;
  dVar2 = (double)*(float *)(param_1 + 0xc) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= dVar2) {
    uVar1 = (int)(dVar2 - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    uVar1 = (uint)(int)dVar2;
  }
  param_2[2] = uVar1;
  dVar2 = (double)*(float *)(param_1 + 0x10) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= dVar2) {
    uVar1 = (int)(dVar2 - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    uVar1 = (uint)(int)dVar2;
  }
  param_2[3] = uVar1;
  return;
}

/* _gleInsertPixel_RGBA_Float @ 0xe8288 (36 bytes) */
int _gleInsertPixel_RGBA_Float(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *param_2 = *(undefined4 *)(param_1 + 4);
  param_2[1] = *(undefined4 *)(param_1 + 8);
  param_2[2] = *(undefined4 *)(param_1 + 0xc);
  param_2[3] = *(undefined4 *)(param_1 + 0x10);
  return;
}

/* _gleInsertPixel_RGBA_4444 @ 0xe82ac (140 bytes) */
int _gleInsertPixel_RGBA_4444(param_1, param_2)
  int param_1;
  ushort *param_2;
{
  *param_2 = (ushort)(int)(*(float *)(param_1 + 4) * FLOAT_00108ea0) & 0xf000 |
             (ushort)((uint)(int)(*(float *)(param_1 + 8) * FLOAT_00108ea0) >> 4) & 0xf00 |
             (ushort)((uint)(int)(*(float *)(param_1 + 0xc) * FLOAT_00108ea0) >> 8) & 0xf0 |
             (ushort)((uint)(int)(*(float *)(param_1 + 0x10) * FLOAT_00108ea0) >> 0xc) & 0xf;
  return;
}

/* _gleInsertPixel_RGBA_4444Rev @ 0xe8338 (140 bytes) */
int _gleInsertPixel_RGBA_4444Rev(param_1, param_2)
  int param_1;
  ushort *param_2;
{
  *param_2 = (ushort)(int)(*(float *)(param_1 + 0x10) * FLOAT_00108ea0) & 0xf000 |
             (ushort)((uint)(int)(*(float *)(param_1 + 0xc) * FLOAT_00108ea0) >> 4) & 0xf00 |
             (ushort)((uint)(int)(*(float *)(param_1 + 8) * FLOAT_00108ea0) >> 8) & 0xf0 |
             (ushort)((uint)(int)(*(float *)(param_1 + 4) * FLOAT_00108ea0) >> 0xc) & 0xf;
  return;
}

/* _gleInsertPixel_RGBA_5551 @ 0xe83c4 (140 bytes) */
int _gleInsertPixel_RGBA_5551(param_1, param_2)
  int param_1;
  ushort *param_2;
{
  *param_2 = (ushort)(int)(*(float *)(param_1 + 4) * FLOAT_00108ea0) & 0xf800 |
             (ushort)((uint)(int)(*(float *)(param_1 + 8) * FLOAT_00108ea0) >> 5) & 0x7c0 |
             (ushort)((uint)(int)(*(float *)(param_1 + 0xc) * FLOAT_00108ea0) >> 10) & 0x3e |
             (ushort)((uint)(int)(*(float *)(param_1 + 0x10) * FLOAT_00108ea0) >> 0xf) & 1;
  return;
}

/* _gleInsertPixel_RGBA_1555Rev @ 0xe8450 (140 bytes) */
int _gleInsertPixel_RGBA_1555Rev(param_1, param_2)
  int param_1;
  ushort *param_2;
{
  *param_2 = (ushort)(int)(*(float *)(param_1 + 0x10) * FLOAT_00108ea0) & 0x8000 |
             (ushort)((uint)(int)(*(float *)(param_1 + 0xc) * FLOAT_00108ea0) >> 1) & 0x7c00 |
             (ushort)((uint)(int)(*(float *)(param_1 + 8) * FLOAT_00108ea0) >> 6) & 0x3e0 |
             (ushort)((uint)(int)(*(float *)(param_1 + 4) * FLOAT_00108ea0) >> 0xb) & 0x1f;
  return;
}

/* _gleInsertPixel_RGBA_8888 @ 0xe84dc (124 bytes) */
int _gleInsertPixel_RGBA_8888(param_1, param_2)
  int param_1;
  undefined1 *param_2;
{
  float fVar1;
  
  fVar1 = FLOAT_00108f70;
  *param_2 = (char)(int)(*(float *)(param_1 + 4) * FLOAT_00108f70);
  param_2[1] = (char)(int)(*(float *)(param_1 + 8) * fVar1);
  param_2[2] = (char)(int)(*(float *)(param_1 + 0xc) * fVar1);
  param_2[3] = (char)(int)(*(float *)(param_1 + 0x10) * fVar1);
  return;
}

/* _gleInsertPixel_RGBA_8888Rev @ 0xe8558 (124 bytes) */
int _gleInsertPixel_RGBA_8888Rev(param_1, param_2)
  int param_1;
  undefined1 *param_2;
{
  float fVar1;
  
  fVar1 = FLOAT_00108f70;
  *param_2 = (char)(int)(*(float *)(param_1 + 0x10) * FLOAT_00108f70);
  param_2[1] = (char)(int)(*(float *)(param_1 + 0xc) * fVar1);
  param_2[2] = (char)(int)(*(float *)(param_1 + 8) * fVar1);
  param_2[3] = (char)(int)(*(float *)(param_1 + 4) * fVar1);
  return;
}

/* _gleInsertPixel_RGBA_1010102 @ 0xe85d4 (328 bytes) */
int _gleInsertPixel_RGBA_1010102(param_1, param_2)
  int param_1;
  uint *param_2;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  double dVar5;
  
  dVar5 = (double)*(float *)(param_1 + 4) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= dVar5) {
    uVar1 = (int)(dVar5 - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    uVar1 = (uint)(int)dVar5;
  }
  dVar5 = (double)*(float *)(param_1 + 8) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= dVar5) {
    uVar2 = (int)(dVar5 - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    uVar2 = (uint)(int)dVar5;
  }
  dVar5 = (double)*(float *)(param_1 + 0xc) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= dVar5) {
    uVar3 = (int)(dVar5 - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    uVar3 = (uint)(int)dVar5;
  }
  dVar5 = (double)*(float *)(param_1 + 0x10) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= dVar5) {
    uVar4 = (int)(dVar5 - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    uVar4 = (uint)(int)dVar5;
  }
  *param_2 = uVar1 & 0xffc00000 | uVar2 >> 10 & 0x3ff000 | uVar3 >> 0x14 & 0xffc | uVar4 >> 0x1e;
  return;
}

/* _gleInsertPixel_RGBA_2101010Rev @ 0xe871c (328 bytes) */
int _gleInsertPixel_RGBA_2101010Rev(param_1, param_2)
  int param_1;
  uint *param_2;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  double dVar5;
  
  dVar5 = (double)*(float *)(param_1 + 0x10) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= dVar5) {
    uVar1 = (int)(dVar5 - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    uVar1 = (uint)(int)dVar5;
  }
  dVar5 = (double)*(float *)(param_1 + 0xc) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= dVar5) {
    uVar2 = (int)(dVar5 - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    uVar2 = (uint)(int)dVar5;
  }
  dVar5 = (double)*(float *)(param_1 + 8) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= dVar5) {
    uVar3 = (int)(dVar5 - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    uVar3 = (uint)(int)dVar5;
  }
  dVar5 = (double)*(float *)(param_1 + 4) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= dVar5) {
    uVar4 = (int)(dVar5 - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    uVar4 = (uint)(int)dVar5;
  }
  *param_2 = uVar1 & 0xc0000000 | uVar2 >> 2 & 0x3ff00000 | uVar3 >> 0xc & 0xffc00 | uVar4 >> 0x16;
  return;
}

/* _gleInsertPixel_ABGR_EXT_Byte @ 0xe8864 (124 bytes) */
int _gleInsertPixel_ABGR_EXT_Byte(param_1, param_2)
  int param_1;
  undefined1 *param_2;
{
  float fVar1;
  
  fVar1 = FLOAT_00108f6c;
  param_2[3] = (char)(int)(*(float *)(param_1 + 4) * FLOAT_00108f6c);
  param_2[2] = (char)(int)(*(float *)(param_1 + 8) * fVar1);
  param_2[1] = (char)(int)(*(float *)(param_1 + 0xc) * fVar1);
  *param_2 = (char)(int)(*(float *)(param_1 + 0x10) * fVar1);
  return;
}

/* _gleInsertPixel_ABGR_EXT_Ubyte @ 0xe88e0 (124 bytes) */
int _gleInsertPixel_ABGR_EXT_Ubyte(param_1, param_2)
  int param_1;
  undefined1 *param_2;
{
  float fVar1;
  
  fVar1 = FLOAT_00108f70;
  param_2[3] = (char)(int)(*(float *)(param_1 + 4) * FLOAT_00108f70);
  param_2[2] = (char)(int)(*(float *)(param_1 + 8) * fVar1);
  param_2[1] = (char)(int)(*(float *)(param_1 + 0xc) * fVar1);
  *param_2 = (char)(int)(*(float *)(param_1 + 0x10) * fVar1);
  return;
}

/* _gleInsertPixel_ABGR_EXT_Short @ 0xe895c (124 bytes) */
int _gleInsertPixel_ABGR_EXT_Short(param_1, param_2)
  int param_1;
  undefined2 *param_2;
{
  float fVar1;
  
  fVar1 = FLOAT_00108f74;
  param_2[3] = (short)(int)(*(float *)(param_1 + 4) * FLOAT_00108f74);
  param_2[2] = (short)(int)(*(float *)(param_1 + 8) * fVar1);
  param_2[1] = (short)(int)(*(float *)(param_1 + 0xc) * fVar1);
  *param_2 = (short)(int)(*(float *)(param_1 + 0x10) * fVar1);
  return;
}

