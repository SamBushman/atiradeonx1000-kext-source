#include "decls.h"

/* _gleExtractPixel_R_Ubyte @ 0xe4090 (68 bytes) */
void _gleExtractPixel_R_Ubyte(param_1, param_2)
  int param_1;
  byte *param_2;
{
  *(float *)(param_1 + 4) = (GH_U2F((unsigned int)((*param_2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  return;
}

/* _gleExtractPixel_R_Short @ 0xe40d4 (76 bytes) */
void _gleExtractPixel_R_Short(param_1, param_2)
  int param_1;
  short *param_2;
{
  *(float *)(param_1 + 4) =
       (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e9c;
  return;
}

/* _gleExtractPixel_R_Ushort @ 0xe4120 (68 bytes) */
void _gleExtractPixel_R_Ushort(param_1, param_2)
  int param_1;
  ushort *param_2;
{
  *(float *)(param_1 + 4) = (GH_U2F((unsigned int)((*param_2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  return;
}

/* _gleExtractPixel_R_Int @ 0xe4164 (80 bytes) */
void _gleExtractPixel_R_Int(param_1, param_2)
  int param_1;
  uint *param_2;
{
  *(float *)(param_1 + 4) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) - DOUBLE_00108d58)
              * DOUBLE_00108d88);
  return;
}

/* _gleExtractPixel_R_Uint @ 0xe41b4 (76 bytes) */
void _gleExtractPixel_R_Uint(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *(float *)(param_1 + 4) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*param_2) - DOUBLE_00108d70) *
              DOUBLE_00108da0);
  return;
}

/* _gleExtractPixel_R_Float @ 0xe4200 (12 bytes) */
void _gleExtractPixel_R_Float(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *(undefined4 *)(param_1 + 4) = *param_2;
  return;
}

/* _gleExtractPixel_G_Byte @ 0xe420c (80 bytes) */
void _gleExtractPixel_G_Byte(param_1, param_2)
  int param_1;
  char *param_2;
{
  *(float *)(param_1 + 8) =
       (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e98;
  return;
}

/* _gleExtractPixel_G_Ubyte @ 0xe425c (68 bytes) */
void _gleExtractPixel_G_Ubyte(param_1, param_2)
  int param_1;
  byte *param_2;
{
  *(float *)(param_1 + 8) = (GH_U2F((unsigned int)((*param_2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  return;
}

/* _gleExtractPixel_G_Short @ 0xe42a0 (76 bytes) */
void _gleExtractPixel_G_Short(param_1, param_2)
  int param_1;
  short *param_2;
{
  *(float *)(param_1 + 8) =
       (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e9c;
  return;
}

/* _gleExtractPixel_G_Ushort @ 0xe42ec (68 bytes) */
void _gleExtractPixel_G_Ushort(param_1, param_2)
  int param_1;
  ushort *param_2;
{
  *(float *)(param_1 + 8) = (GH_U2F((unsigned int)((*param_2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  return;
}

/* _gleExtractPixel_G_Int @ 0xe4330 (80 bytes) */
void _gleExtractPixel_G_Int(param_1, param_2)
  int param_1;
  uint *param_2;
{
  *(float *)(param_1 + 8) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) - DOUBLE_00108d58)
              * DOUBLE_00108d88);
  return;
}

/* _gleExtractPixel_G_Uint @ 0xe4380 (76 bytes) */
void _gleExtractPixel_G_Uint(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *(float *)(param_1 + 8) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*param_2) - DOUBLE_00108d70) *
              DOUBLE_00108da0);
  return;
}

/* _gleExtractPixel_G_Float @ 0xe43cc (12 bytes) */
void _gleExtractPixel_G_Float(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *(undefined4 *)(param_1 + 8) = *param_2;
  return;
}

/* _gleExtractPixel_B_Byte @ 0xe43d8 (80 bytes) */
void _gleExtractPixel_B_Byte(param_1, param_2)
  int param_1;
  char *param_2;
{
  *(float *)(param_1 + 0xc) =
       (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e98;
  return;
}

/* _gleExtractPixel_B_Ubyte @ 0xe4428 (68 bytes) */
void _gleExtractPixel_B_Ubyte(param_1, param_2)
  int param_1;
  byte *param_2;
{
  *(float *)(param_1 + 0xc) = (GH_U2F((unsigned int)((*param_2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  return;
}

/* _gleExtractPixel_B_Short @ 0xe446c (76 bytes) */
void _gleExtractPixel_B_Short(param_1, param_2)
  int param_1;
  short *param_2;
{
  *(float *)(param_1 + 0xc) =
       (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e9c;
  return;
}

/* _gleExtractPixel_B_Ushort @ 0xe44b8 (68 bytes) */
void _gleExtractPixel_B_Ushort(param_1, param_2)
  int param_1;
  ushort *param_2;
{
  *(float *)(param_1 + 0xc) = (GH_U2F((unsigned int)((*param_2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  return;
}

/* _gleExtractPixel_B_Int @ 0xe44fc (80 bytes) */
void _gleExtractPixel_B_Int(param_1, param_2)
  int param_1;
  uint *param_2;
{
  *(float *)(param_1 + 0xc) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) - DOUBLE_00108d58)
              * DOUBLE_00108d88);
  return;
}

/* _gleExtractPixel_B_Uint @ 0xe454c (76 bytes) */
void _gleExtractPixel_B_Uint(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *(float *)(param_1 + 0xc) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*param_2) - DOUBLE_00108d70) *
              DOUBLE_00108da0);
  return;
}

/* _gleExtractPixel_B_Float @ 0xe4598 (12 bytes) */
void _gleExtractPixel_B_Float(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *(undefined4 *)(param_1 + 0xc) = *param_2;
  return;
}

/* _gleExtractPixel_A_Byte @ 0xe45a4 (80 bytes) */
void _gleExtractPixel_A_Byte(param_1, param_2)
  int param_1;
  char *param_2;
{
  *(float *)(param_1 + 0x10) =
       (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e98;
  return;
}

/* _gleExtractPixel_A_Ubyte @ 0xe45f4 (68 bytes) */
void _gleExtractPixel_A_Ubyte(param_1, param_2)
  int param_1;
  byte *param_2;
{
  *(float *)(param_1 + 0x10) = (GH_U2F((unsigned int)((*param_2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  return;
}

/* _gleExtractPixel_A_Short @ 0xe4638 (76 bytes) */
void _gleExtractPixel_A_Short(param_1, param_2)
  int param_1;
  short *param_2;
{
  *(float *)(param_1 + 0x10) =
       (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e9c;
  return;
}

/* _gleExtractPixel_A_Ushort @ 0xe4684 (68 bytes) */
void _gleExtractPixel_A_Ushort(param_1, param_2)
  int param_1;
  ushort *param_2;
{
  *(float *)(param_1 + 0x10) = (GH_U2F((unsigned int)((*param_2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  return;
}

/* _gleExtractPixel_A_Int @ 0xe46c8 (80 bytes) */
void _gleExtractPixel_A_Int(param_1, param_2)
  int param_1;
  uint *param_2;
{
  *(float *)(param_1 + 0x10) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) - DOUBLE_00108d58)
              * DOUBLE_00108d88);
  return;
}

/* _gleExtractPixel_A_Uint @ 0xe4718 (76 bytes) */
void _gleExtractPixel_A_Uint(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *(float *)(param_1 + 0x10) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*param_2) - DOUBLE_00108d70) *
              DOUBLE_00108da0);
  return;
}

/* _gleExtractPixel_A_Float @ 0xe4764 (12 bytes) */
void _gleExtractPixel_A_Float(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *(undefined4 *)(param_1 + 0x10) = *param_2;
  return;
}

/* _gleExtractPixel_L_Byte @ 0xe4770 (88 bytes) */
void _gleExtractPixel_L_Byte(param_1, param_2)
  int param_1;
  char *param_2;
{
  float fVar1;
  
  fVar1 = (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e98;
  *(float *)(param_1 + 0xc) = fVar1;
  *(float *)(param_1 + 4) = fVar1;
  *(float *)(param_1 + 8) = fVar1;
  return;
}

/* _gleExtractPixel_L_Ubyte @ 0xe47c8 (76 bytes) */
void _gleExtractPixel_L_Ubyte(param_1, param_2)
  int param_1;
  byte *param_2;
{
  float fVar1;
  
  fVar1 = (GH_U2F((unsigned int)((*param_2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  *(float *)(param_1 + 0xc) = fVar1;
  *(float *)(param_1 + 4) = fVar1;
  *(float *)(param_1 + 8) = fVar1;
  return;
}

/* _gleExtractPixel_L_Short @ 0xe4814 (84 bytes) */
void _gleExtractPixel_L_Short(param_1, param_2)
  int param_1;
  short *param_2;
{
  float fVar1;
  
  fVar1 = (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e9c;
  *(float *)(param_1 + 0xc) = fVar1;
  *(float *)(param_1 + 4) = fVar1;
  *(float *)(param_1 + 8) = fVar1;
  return;
}

/* _gleExtractPixel_L_Ushort @ 0xe4868 (76 bytes) */
void _gleExtractPixel_L_Ushort(param_1, param_2)
  int param_1;
  ushort *param_2;
{
  float fVar1;
  
  fVar1 = (GH_U2F((unsigned int)((*param_2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(float *)(param_1 + 0xc) = fVar1;
  *(float *)(param_1 + 4) = fVar1;
  *(float *)(param_1 + 8) = fVar1;
  return;
}

/* _gleExtractPixel_L_Int @ 0xe48b4 (88 bytes) */
void _gleExtractPixel_L_Int(param_1, param_2)
  int param_1;
  uint *param_2;
{
  float fVar1;
  
  fVar1 = (float)((double)(float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) -
                                 DOUBLE_00108d58) * DOUBLE_00108d88);
  *(float *)(param_1 + 0xc) = fVar1;
  *(float *)(param_1 + 4) = fVar1;
  *(float *)(param_1 + 8) = fVar1;
  return;
}

/* _gleExtractPixel_L_Uint @ 0xe490c (84 bytes) */
void _gleExtractPixel_L_Uint(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  float fVar1;
  
  fVar1 = (float)((double)(float)((double)CONCAT44(0x43300000,*param_2) - DOUBLE_00108d70) *
                 DOUBLE_00108da0);
  *(float *)(param_1 + 0xc) = fVar1;
  *(float *)(param_1 + 4) = fVar1;
  *(float *)(param_1 + 8) = fVar1;
  return;
}

/* _gleExtractPixel_L_Float @ 0xe4960 (20 bytes) */
void _gleExtractPixel_L_Float(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  
  uVar1 = *param_2;
  *(undefined4 *)(param_1 + 0xc) = uVar1;
  *(undefined4 *)(param_1 + 4) = uVar1;
  *(undefined4 *)(param_1 + 8) = uVar1;
  return;
}

/* _gleExtractPixel_LA_Byte @ 0xe4974 (124 bytes) */
void _gleExtractPixel_LA_Byte(param_1, param_2)
  int param_1;
  char *param_2;
{
  float fVar1;
  double dVar2;
  float fVar3;
  
  fVar3 = FLOAT_00108e98;
  dVar2 = DOUBLE_00108d58;
  fVar1 = (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e98;
  *(float *)(param_1 + 0xc) = fVar1;
  *(float *)(param_1 + 4) = fVar1;
  *(float *)(param_1 + 8) = fVar1;
  *(float *)(param_1 + 0x10) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - dVar2) * fVar3;
  return;
}

/* _gleExtractPixel_LA_Ubyte @ 0xe49f0 (112 bytes) */
void _gleExtractPixel_LA_Ubyte(param_1, param_2)
  int param_1;
  byte *param_2;
{
  float fVar1;
  float fVar2;
  
  fVar2 = FLOAT_00108e78;
  fVar1 = (GH_U2F((unsigned int)((*param_2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  *(float *)(param_1 + 0xc) = fVar1;
  *(float *)(param_1 + 4) = fVar1;
  *(float *)(param_1 + 8) = fVar1;
  *(float *)(param_1 + 0x10) = (GH_U2F((unsigned int)((param_2[1] | 0x4b000000))) - 8388608.0) * fVar2;
  return;
}

/* _gleExtractPixel_LA_Short @ 0xe4a60 (116 bytes) */
void _gleExtractPixel_LA_Short(param_1, param_2)
  int param_1;
  short *param_2;
{
  float fVar1;
  double dVar2;
  float fVar3;
  
  fVar3 = FLOAT_00108e9c;
  dVar2 = DOUBLE_00108d58;
  fVar1 = (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e9c;
  *(float *)(param_1 + 0xc) = fVar1;
  *(float *)(param_1 + 4) = fVar1;
  *(float *)(param_1 + 8) = fVar1;
  *(float *)(param_1 + 0x10) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - dVar2) * fVar3;
  return;
}

/* _gleExtractPixel_LA_Ushort @ 0xe4ad4 (112 bytes) */
void _gleExtractPixel_LA_Ushort(param_1, param_2)
  int param_1;
  ushort *param_2;
{
  float fVar1;
  float fVar2;
  
  fVar2 = FLOAT_00108e74;
  fVar1 = (GH_U2F((unsigned int)((*param_2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(float *)(param_1 + 0xc) = fVar1;
  *(float *)(param_1 + 4) = fVar1;
  *(float *)(param_1 + 8) = fVar1;
  *(float *)(param_1 + 0x10) = (GH_U2F((unsigned int)((param_2[1] | 0x4b000000))) - 8388608.0) * fVar2;
  return;
}

/* _gleExtractPixel_LA_Int @ 0xe4b44 (124 bytes) */
void _gleExtractPixel_LA_Int(param_1, param_2)
  int param_1;
  uint *param_2;
{
  float fVar1;
  double dVar2;
  double dVar3;
  
  dVar3 = DOUBLE_00108d88;
  dVar2 = DOUBLE_00108d58;
  fVar1 = (float)((double)(float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) -
                                 DOUBLE_00108d58) * DOUBLE_00108d88);
  *(float *)(param_1 + 0xc) = fVar1;
  *(float *)(param_1 + 4) = fVar1;
  *(float *)(param_1 + 8) = fVar1;
  *(float *)(param_1 + 0x10) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_2[1] ^ 0x80000000) - dVar2) * dVar3
              );
  return;
}

/* _gleExtractPixel_LA_Uint @ 0xe4bc0 (116 bytes) */
void _gleExtractPixel_LA_Uint(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  float fVar1;
  double dVar2;
  double dVar3;
  
  dVar3 = DOUBLE_00108da0;
  dVar2 = DOUBLE_00108d70;
  fVar1 = (float)((double)(float)((double)CONCAT44(0x43300000,*param_2) - DOUBLE_00108d70) *
                 DOUBLE_00108da0);
  *(float *)(param_1 + 0xc) = fVar1;
  *(float *)(param_1 + 4) = fVar1;
  *(float *)(param_1 + 8) = fVar1;
  *(float *)(param_1 + 0x10) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_2[1]) - dVar2) * dVar3);
  return;
}

/* _gleExtractPixel_LA_Float @ 0xe4c34 (28 bytes) */
void _gleExtractPixel_LA_Float(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  
  uVar1 = *param_2;
  *(undefined4 *)(param_1 + 0xc) = uVar1;
  *(undefined4 *)(param_1 + 4) = uVar1;
  *(undefined4 *)(param_1 + 8) = uVar1;
  *(undefined4 *)(param_1 + 0x10) = param_2[1];
  return;
}

/* _gleExtractPixel_Index_Byte @ 0xe4c50 (24 bytes) */
void _gleExtractPixel_Index_Byte(param_1, param_2)
  int param_1;
  char *param_2;
{
  char cVar1;
  
  cVar1 = *param_2;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(int *)(param_1 + 0x18) = (int)cVar1;
  return;
}

/* _gleExtractPixel_Index_Ubyte @ 0xe4c68 (20 bytes) */
void _gleExtractPixel_Index_Ubyte(param_1, param_2)
  int param_1;
  byte *param_2;
{
  byte bVar1;
  
  bVar1 = *param_2;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(uint *)(param_1 + 0x18) = (uint)bVar1;
  return;
}

/* _gleExtractPixel_Index_Short @ 0xe4c7c (20 bytes) */
void _gleExtractPixel_Index_Short(param_1, param_2)
  int param_1;
  short *param_2;
{
  short sVar1;
  
  sVar1 = *param_2;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}

/* _gleExtractPixel_Index_Ushort @ 0xe4c90 (20 bytes) */
void _gleExtractPixel_Index_Ushort(param_1, param_2)
  int param_1;
  ushort *param_2;
{
  ushort uVar1;
  
  uVar1 = *param_2;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(uint *)(param_1 + 0x18) = (uint)uVar1;
  return;
}

/* _gleExtractPixel_Index_Int @ 0xe4ca4 (20 bytes) */
void _gleExtractPixel_Index_Int(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  
  uVar1 = *param_2;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x18) = uVar1;
  return;
}

/* _gleExtractPixel_Index_Uint @ 0xe4cb8 (20 bytes) */
void _gleExtractPixel_Index_Uint(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  
  uVar1 = *param_2;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x18) = uVar1;
  return;
}

/* _gleExtractPixel_Index_Float @ 0xe4ccc (128 bytes) */
void _gleExtractPixel_Index_Float(param_1, param_2)
  int param_1;
  float *param_2;
{
  float fVar1;
  undefined4 uVar2;
  
  fVar1 = *param_2;
  if (fVar1 < FLOAT_00108e50) {
    fVar1 = fVar1 - FLOAT_00108f50;
  }
  *(int *)(param_1 + 0x18) = (int)fVar1;
  uVar2 = ((int (*)())_gleGetFrac)((double)*param_2);
  *(undefined4 *)(param_1 + 0x1c) = uVar2;
  return;
}

/* _gleExtractPixel_Depth_Byte @ 0xe4d4c (80 bytes) */
void _gleExtractPixel_Depth_Byte(param_1, param_2)
  int param_1;
  char *param_2;
{
  *(float *)(param_1 + 0x14) =
       (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e98;
  return;
}

/* _gleExtractPixel_Depth_Ubyte @ 0xe4d9c (68 bytes) */
void _gleExtractPixel_Depth_Ubyte(param_1, param_2)
  int param_1;
  byte *param_2;
{
  *(float *)(param_1 + 0x14) = (GH_U2F((unsigned int)((*param_2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  return;
}

/* _gleExtractPixel_Depth_Short @ 0xe4de0 (76 bytes) */
void _gleExtractPixel_Depth_Short(param_1, param_2)
  int param_1;
  short *param_2;
{
  *(float *)(param_1 + 0x14) =
       (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e9c;
  return;
}

/* _gleExtractPixel_Depth_Ushort @ 0xe4e2c (68 bytes) */
void _gleExtractPixel_Depth_Ushort(param_1, param_2)
  int param_1;
  ushort *param_2;
{
  *(float *)(param_1 + 0x14) = (GH_U2F((unsigned int)((*param_2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  return;
}

/* _gleExtractPixel_Depth_Int @ 0xe4e70 (80 bytes) */
void _gleExtractPixel_Depth_Int(param_1, param_2)
  int param_1;
  uint *param_2;
{
  *(float *)(param_1 + 0x14) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) - DOUBLE_00108d58)
              * DOUBLE_00108d88);
  return;
}

/* _gleExtractPixel_Depth_Uint @ 0xe4ec0 (76 bytes) */
void _gleExtractPixel_Depth_Uint(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *(float *)(param_1 + 0x14) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*param_2) - DOUBLE_00108d70) *
              DOUBLE_00108da0);
  return;
}

/* _gleExtractPixel_Depth_Float @ 0xe4f0c (12 bytes) */
void _gleExtractPixel_Depth_Float(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *(undefined4 *)(param_1 + 0x14) = *param_2;
  return;
}

/* _gleExtractPixel_HILO_Byte @ 0xe4f18 (116 bytes) */
void _gleExtractPixel_HILO_Byte(param_1, param_2)
  int param_1;
  char *param_2;
{
  double dVar1;
  float fVar2;
  
  fVar2 = FLOAT_00108e98;
  dVar1 = DOUBLE_00108d58;
  *(float *)(param_1 + 0x20) =
       (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e98;
  *(float *)(param_1 + 0x24) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - dVar1) * fVar2;
  return;
}

/* _gleExtractPixel_HILO_Ubyte @ 0xe4f8c (104 bytes) */
void _gleExtractPixel_HILO_Ubyte(param_1, param_2)
  int param_1;
  byte *param_2;
{
  float fVar1;
  
  fVar1 = FLOAT_00108e78;
  *(float *)(param_1 + 0x20) = (GH_U2F((unsigned int)((*param_2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  *(float *)(param_1 + 0x24) = (GH_U2F((unsigned int)((param_2[1] | 0x4b000000))) - 8388608.0) * fVar1;
  return;
}

/* _gleExtractPixel_HILO_Short @ 0xe4ff4 (108 bytes) */
void _gleExtractPixel_HILO_Short(param_1, param_2)
  int param_1;
  short *param_2;
{
  double dVar1;
  float fVar2;
  
  fVar2 = FLOAT_00108e9c;
  dVar1 = DOUBLE_00108d58;
  *(float *)(param_1 + 0x20) =
       (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e9c;
  *(float *)(param_1 + 0x24) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - dVar1) * fVar2;
  return;
}

/* _gleExtractPixel_HILO_Ushort @ 0xe5060 (104 bytes) */
void _gleExtractPixel_HILO_Ushort(param_1, param_2)
  int param_1;
  ushort *param_2;
{
  float fVar1;
  
  fVar1 = FLOAT_00108e74;
  *(float *)(param_1 + 0x20) = (GH_U2F((unsigned int)((*param_2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(float *)(param_1 + 0x24) = (GH_U2F((unsigned int)((param_2[1] | 0x4b000000))) - 8388608.0) * fVar1;
  return;
}

/* _gleExtractPixel_HILO_Int @ 0xe50c8 (116 bytes) */
void _gleExtractPixel_HILO_Int(param_1, param_2)
  int param_1;
  uint *param_2;
{
  double dVar1;
  double dVar2;
  
  dVar2 = DOUBLE_00108d88;
  dVar1 = DOUBLE_00108d58;
  *(float *)(param_1 + 0x20) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) - DOUBLE_00108d58)
              * DOUBLE_00108d88);
  *(float *)(param_1 + 0x24) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_2[1] ^ 0x80000000) - dVar1) * dVar2
              );
  return;
}

