#include "decls.h"

/* _glePipelineProgramTargetExtactor @ 0xe1d34 (52 bytes) */
int _glePipelineProgramTargetExtactor(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  if (*(short *)(param_2 + 0x4ca) == 0) {
    return 0x8620;
  }
  if (*(short *)(param_2 + 0x4ca) != 1) {
    return 0;
  }
  return 0x8804;
}

/* _glePPRelocateOutput @ 0xe1d68 (80 bytes) */
int _glePPRelocateOutput(param_1, param_2, param_3)
  uint param_1;
  undefined4 param_2;
  int *param_3;
{
  int iVar1;
  
  iVar1 = *param_3;
  if (iVar1 != 0) {
    do {
      if ((((*(uint *)(iVar1 + 0xc) >> 0x12 & 0xff) < 0x4b) &&
          ((*(uint *)(iVar1 + 0x14) >> 0x11 & 7) == 3)) && (*(ushort *)(iVar1 + 0x1a) == param_1)) {
        *(undefined2 *)(iVar1 + 0x1a) = (*(unsigned short *)((unsigned char *)&(param_2) + 2));
      }
      iVar1 = *(int *)(iVar1 + 8);
    } while (iVar1 != 0);
    return;
  }
  return;
}

/* _gleBytesPerElement @ 0xe1db8 (140 bytes) */
double _gleBytesPerElement(uint param_1)
{
  if (param_1 < 0x1404) {
    if (0x1401 < param_1) {
LAB_000e1e14:
      return (double)FLOAT_00108ea4;
    }
    if (0x13ff < param_1) {
      return (double)FLOAT_00108e54;
    }
  }
  else {
    if (param_1 == 0x140b) goto LAB_000e1e14;
    if (param_1 < 0x140c) {
      if (param_1 < 0x1407) {
        return (double)FLOAT_00108ea8;
      }
    }
    else if (param_1 == 0x1a00) {
      return (double)FLOAT_00108f4c;
    }
  }
  return (double)FLOAT_00108e50;
}

/* _gleElementOffset @ 0xe1e44 (112 bytes) */
int _gleElementOffset(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
  undefined4 param_5;
  int param_6;
{
  int iVar1;
  int iVar2;
  
  iVar2 = _gleComponents(param_5);
  iVar1 = iVar2 * param_6;
  if (param_4 == 0x1a00) {
    iVar1 = _gleRowBytes(param_5,0x1a00,param_6);
    iVar1 = iVar1 << 3;
  }
  return iVar1 * param_3 + iVar2 * param_2;
}

/* _gleGetFrac @ 0xe1eb4 (208 bytes) */
int _gleGetFrac(float fparam_1)
{
  if ((double)FLOAT_00108e50 <= fparam_1) {
    return (int)((float)(fparam_1 -
                        (double)(float)((double)CONCAT44(0x43300000,(int)fparam_1 ^ 0x80000000) -
                                       DOUBLE_00108d58)) * FLOAT_00108f54);
  }
  return (int)((float)(fparam_1 -
                      (double)(float)((double)CONCAT44(0x43300000,
                                                       (int)(fparam_1 - (double)FLOAT_00108f50) ^
                                                       0x80000000) - DOUBLE_00108d58)) *
              FLOAT_00108f54);
}

/* _gleExtractPixel_RGBA_Byte @ 0xe1f84 (188 bytes) */
int _gleExtractPixel_RGBA_Byte(param_1, param_2)
  int param_1;
  char *param_2;
{
  double dVar1;
  float fVar2;
  
  fVar2 = FLOAT_00108e98;
  dVar1 = DOUBLE_00108d58;
  *(float *)(param_1 + 4) =
       (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e98;
  *(float *)(param_1 + 8) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - dVar1) * fVar2;
  *(float *)(param_1 + 0xc) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[2] ^ 0x80000000) - dVar1) * fVar2;
  *(float *)(param_1 + 0x10) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[3] ^ 0x80000000) - dVar1) * fVar2;
  return;
}

/* _gleExtractPixel_RGBA_Short @ 0xe2040 (172 bytes) */
int _gleExtractPixel_RGBA_Short(param_1, param_2)
  int param_1;
  short *param_2;
{
  double dVar1;
  float fVar2;
  
  fVar2 = FLOAT_00108e9c;
  dVar1 = DOUBLE_00108d58;
  *(float *)(param_1 + 4) =
       (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e9c;
  *(float *)(param_1 + 8) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - dVar1) * fVar2;
  *(float *)(param_1 + 0xc) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[2] ^ 0x80000000) - dVar1) * fVar2;
  *(float *)(param_1 + 0x10) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[3] ^ 0x80000000) - dVar1) * fVar2;
  return;
}

/* _gleExtractPixel_RGBA_Ushort @ 0xe20ec (176 bytes) */
int _gleExtractPixel_RGBA_Ushort(param_1, param_2)
  int param_1;
  ushort *param_2;
{
  float fVar1;
  
  fVar1 = FLOAT_00108e74;
  *(float *)(param_1 + 4) = (GH_U2F((unsigned int)((*param_2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(float *)(param_1 + 8) = (GH_U2F((unsigned int)((param_2[1] | 0x4b000000))) - 8388608.0) * fVar1;
  *(float *)(param_1 + 0xc) = (GH_U2F((unsigned int)((param_2[2] | 0x4b000000))) - 8388608.0) * fVar1;
  *(float *)(param_1 + 0x10) = (GH_U2F((unsigned int)((param_2[3] | 0x4b000000))) - 8388608.0) * fVar1;
  return;
}

/* _gleExtractPixel_RGBA_Int @ 0xe219c (188 bytes) */
int _gleExtractPixel_RGBA_Int(param_1, param_2)
  int param_1;
  uint *param_2;
{
  double dVar1;
  double dVar2;
  
  dVar2 = DOUBLE_00108d88;
  dVar1 = DOUBLE_00108d58;
  *(float *)(param_1 + 4) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) - DOUBLE_00108d58)
              * DOUBLE_00108d88);
  *(float *)(param_1 + 8) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_2[1] ^ 0x80000000) - dVar1) * dVar2
              );
  *(float *)(param_1 + 0xc) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_2[2] ^ 0x80000000) - dVar1) * dVar2
              );
  *(float *)(param_1 + 0x10) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_2[3] ^ 0x80000000) - dVar1) * dVar2
              );
  return;
}

/* _gleExtractPixel_RGBA_Uint @ 0xe2258 (172 bytes) */
int _gleExtractPixel_RGBA_Uint(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  double dVar1;
  double dVar2;
  
  dVar2 = DOUBLE_00108da0;
  dVar1 = DOUBLE_00108d70;
  *(float *)(param_1 + 4) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*param_2) - DOUBLE_00108d70) *
              DOUBLE_00108da0);
  *(float *)(param_1 + 8) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_2[1]) - dVar1) * dVar2);
  *(float *)(param_1 + 0xc) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_2[2]) - dVar1) * dVar2);
  *(float *)(param_1 + 0x10) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_2[3]) - dVar1) * dVar2);
  return;
}

/* _gleExtractPixel_RGBA_Float @ 0xe2304 (36 bytes) */
int _gleExtractPixel_RGBA_Float(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *(undefined4 *)(param_1 + 4) = *param_2;
  *(undefined4 *)(param_1 + 8) = param_2[1];
  *(undefined4 *)(param_1 + 0xc) = param_2[2];
  *(undefined4 *)(param_1 + 0x10) = param_2[3];
  return;
}

/* _gleExtractPixel_RGBA_4444 @ 0xe2328 (188 bytes) */
int _gleExtractPixel_RGBA_4444(param_1, param_2)
  int param_1;
  ushort *param_2;
{
  double dVar1;
  float fVar2;
  
  fVar2 = FLOAT_00108f58;
  dVar1 = DOUBLE_00108d58;
  *(float *)(param_1 + 4) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 0xc ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108f58;
  *(float *)(param_1 + 8) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 8 & 0xf ^ 0x80000000) - dVar1) * fVar2;
  *(float *)(param_1 + 0xc) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 4 & 0xf ^ 0x80000000) - dVar1) * fVar2;
  *(float *)(param_1 + 0x10) =
       (float)((double)CONCAT44(0x43300000,*param_2 & 0xf ^ 0x80000000) - dVar1) * fVar2;
  return;
}

/* _gleExtractPixel_RGBA_4444Rev @ 0xe23e4 (188 bytes) */
int _gleExtractPixel_RGBA_4444Rev(param_1, param_2)
  int param_1;
  ushort *param_2;
{
  double dVar1;
  float fVar2;
  
  fVar2 = FLOAT_00108f58;
  dVar1 = DOUBLE_00108d58;
  *(float *)(param_1 + 0x10) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 0xc ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108f58;
  *(float *)(param_1 + 0xc) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 8 & 0xf ^ 0x80000000) - dVar1) * fVar2;
  *(float *)(param_1 + 8) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 4 & 0xf ^ 0x80000000) - dVar1) * fVar2;
  *(float *)(param_1 + 4) =
       (float)((double)CONCAT44(0x43300000,*param_2 & 0xf ^ 0x80000000) - dVar1) * fVar2;
  return;
}

/* _gleExtractPixel_RGBA_5551 @ 0xe24a0 (184 bytes) */
int _gleExtractPixel_RGBA_5551(param_1, param_2)
  int param_1;
  ushort *param_2;
{
  double dVar1;
  float fVar2;
  
  fVar2 = FLOAT_00108f5c;
  dVar1 = DOUBLE_00108d58;
  *(float *)(param_1 + 4) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 0xb ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108f5c;
  *(float *)(param_1 + 8) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 6 & 0x1f ^ 0x80000000) - dVar1) * fVar2;
  *(float *)(param_1 + 0xc) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 1 & 0x1f ^ 0x80000000) - dVar1) * fVar2;
  *(float *)(param_1 + 0x10) =
       (float)((double)CONCAT44(0x43300000,*param_2 & 1 ^ 0x80000000) - dVar1);
  return;
}

/* _gleExtractPixel_RGBA_1555Rev @ 0xe2558 (184 bytes) */
int _gleExtractPixel_RGBA_1555Rev(param_1, param_2)
  int param_1;
  ushort *param_2;
{
  double dVar1;
  float fVar2;
  
  fVar2 = FLOAT_00108f5c;
  dVar1 = DOUBLE_00108d58;
  *(float *)(param_1 + 0x10) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 0xf ^ 0x80000000) - DOUBLE_00108d58);
  *(float *)(param_1 + 0xc) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 10 & 0x1f ^ 0x80000000) - dVar1) * fVar2;
  *(float *)(param_1 + 8) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 5 & 0x1f ^ 0x80000000) - dVar1) * fVar2;
  *(float *)(param_1 + 4) =
       (float)((double)CONCAT44(0x43300000,*param_2 & 0x1f ^ 0x80000000) - dVar1) * fVar2;
  return;
}

/* _gleExtractPixel_RGBA_8888 @ 0xe2610 (156 bytes) */
int _gleExtractPixel_RGBA_8888(param_1, param_2)
  int param_1;
  byte *param_2;
{
  double dVar1;
  float fVar2;
  
  fVar2 = FLOAT_00108e64;
  dVar1 = DOUBLE_00108d70;
  *(float *)(param_1 + 4) =
       (float)((double)CONCAT44(0x43300000,(uint)*param_2) - DOUBLE_00108d70) * FLOAT_00108e64;
  *(float *)(param_1 + 8) = (float)((double)CONCAT44(0x43300000,(uint)param_2[1]) - dVar1) * fVar2;
  *(float *)(param_1 + 0xc) = (float)((double)CONCAT44(0x43300000,(uint)param_2[2]) - dVar1) * fVar2
  ;
  *(float *)(param_1 + 0x10) =
       (float)((double)CONCAT44(0x43300000,(uint)param_2[3]) - dVar1) * fVar2;
  return;
}

/* _gleExtractPixel_RGBA_8888Rev @ 0xe26ac (156 bytes) */
int _gleExtractPixel_RGBA_8888Rev(param_1, param_2)
  int param_1;
  byte *param_2;
{
  double dVar1;
  float fVar2;
  
  fVar2 = FLOAT_00108e64;
  dVar1 = DOUBLE_00108d70;
  *(float *)(param_1 + 0x10) =
       (float)((double)CONCAT44(0x43300000,(uint)*param_2) - DOUBLE_00108d70) * FLOAT_00108e64;
  *(float *)(param_1 + 0xc) = (float)((double)CONCAT44(0x43300000,(uint)param_2[1]) - dVar1) * fVar2
  ;
  *(float *)(param_1 + 8) = (float)((double)CONCAT44(0x43300000,(uint)param_2[2]) - dVar1) * fVar2;
  *(float *)(param_1 + 4) = (float)((double)CONCAT44(0x43300000,(uint)param_2[3]) - dVar1) * fVar2;
  return;
}

/* _gleExtractPixel_RGBA_1010102 @ 0xe2748 (180 bytes) */
int _gleExtractPixel_RGBA_1010102(param_1, param_2)
  int param_1;
  uint *param_2;
{
  double dVar1;
  float fVar2;
  
  fVar2 = FLOAT_00108f60;
  dVar1 = DOUBLE_00108d70;
  *(float *)(param_1 + 4) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 0x16) - DOUBLE_00108d70) * FLOAT_00108f60;
  *(float *)(param_1 + 8) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 0xc & 0x3ff) - dVar1) * fVar2;
  *(float *)(param_1 + 0xc) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 2 & 0x3ff) - dVar1) * fVar2;
  *(float *)(param_1 + 0x10) =
       (float)((double)CONCAT44(0x43300000,*param_2 & 3) - dVar1) * FLOAT_00108eb8;
  return;
}

/* _gleExtractPixel_RGBA_2101010Rev @ 0xe27fc (180 bytes) */
int _gleExtractPixel_RGBA_2101010Rev(param_1, param_2)
  int param_1;
  uint *param_2;
{
  double dVar1;
  float fVar2;
  
  fVar2 = FLOAT_00108f60;
  dVar1 = DOUBLE_00108d70;
  *(float *)(param_1 + 0x10) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 0x1e) - DOUBLE_00108d70) * FLOAT_00108eb8;
  *(float *)(param_1 + 0xc) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 0x14 & 0x3ff) - dVar1) * fVar2;
  *(float *)(param_1 + 8) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 10 & 0x3ff) - dVar1) * fVar2;
  *(float *)(param_1 + 4) = (float)((double)CONCAT44(0x43300000,*param_2 & 0x3ff) - dVar1) * fVar2;
  return;
}

/* _gleExtractPixel_ABGR_EXT_Byte @ 0xe28b0 (188 bytes) */
int _gleExtractPixel_ABGR_EXT_Byte(param_1, param_2)
  int param_1;
  char *param_2;
{
  double dVar1;
  float fVar2;
  
  fVar2 = FLOAT_00108e98;
  dVar1 = DOUBLE_00108d58;
  *(float *)(param_1 + 4) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[3] ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e98;
  *(float *)(param_1 + 8) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[2] ^ 0x80000000) - dVar1) * fVar2;
  *(float *)(param_1 + 0xc) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - dVar1) * fVar2;
  *(float *)(param_1 + 0x10) =
       (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - dVar1) * fVar2;
  return;
}

/* _gleExtractPixel_ABGR_EXT_Ubyte @ 0xe296c (172 bytes) */
int _gleExtractPixel_ABGR_EXT_Ubyte(param_1, param_2)
  int param_1;
  byte *param_2;
{
  float fVar1;
  
  fVar1 = FLOAT_00108e78;
  *(float *)(param_1 + 4) = (GH_U2F((unsigned int)((param_2[3] | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  *(float *)(param_1 + 8) = (GH_U2F((unsigned int)((param_2[2] | 0x4b000000))) - 8388608.0) * fVar1;
  *(float *)(param_1 + 0xc) = (GH_U2F((unsigned int)((param_2[1] | 0x4b000000))) - 8388608.0) * fVar1;
  *(float *)(param_1 + 0x10) = (GH_U2F((unsigned int)((*param_2 | 0x4b000000))) - 8388608.0) * fVar1;
  return;
}

/* _gleExtractPixel_ABGR_EXT_Short @ 0xe2a18 (172 bytes) */
int _gleExtractPixel_ABGR_EXT_Short(param_1, param_2)
  int param_1;
  short *param_2;
{
  double dVar1;
  float fVar2;
  
  fVar2 = FLOAT_00108e9c;
  dVar1 = DOUBLE_00108d58;
  *(float *)(param_1 + 4) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[3] ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e9c;
  *(float *)(param_1 + 8) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[2] ^ 0x80000000) - dVar1) * fVar2;
  *(float *)(param_1 + 0xc) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - dVar1) * fVar2;
  *(float *)(param_1 + 0x10) =
       (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - dVar1) * fVar2;
  return;
}

/* _gleExtractPixel_ABGR_EXT_Ushort @ 0xe2ac4 (172 bytes) */
int _gleExtractPixel_ABGR_EXT_Ushort(param_1, param_2)
  int param_1;
  ushort *param_2;
{
  float fVar1;
  
  fVar1 = FLOAT_00108e74;
  *(float *)(param_1 + 4) = (GH_U2F((unsigned int)((param_2[3] | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(float *)(param_1 + 8) = (GH_U2F((unsigned int)((param_2[2] | 0x4b000000))) - 8388608.0) * fVar1;
  *(float *)(param_1 + 0xc) = (GH_U2F((unsigned int)((param_2[1] | 0x4b000000))) - 8388608.0) * fVar1;
  *(float *)(param_1 + 0x10) = (GH_U2F((unsigned int)((*param_2 | 0x4b000000))) - 8388608.0) * fVar1;
  return;
}

/* _gleExtractPixel_ABGR_EXT_Int @ 0xe2b70 (188 bytes) */
int _gleExtractPixel_ABGR_EXT_Int(param_1, param_2)
  int param_1;
  uint *param_2;
{
  double dVar1;
  double dVar2;
  
  dVar2 = DOUBLE_00108d88;
  dVar1 = DOUBLE_00108d58;
  *(float *)(param_1 + 4) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_2[3] ^ 0x80000000) -
                              DOUBLE_00108d58) * DOUBLE_00108d88);
  *(float *)(param_1 + 8) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_2[2] ^ 0x80000000) - dVar1) * dVar2
              );
  *(float *)(param_1 + 0xc) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_2[1] ^ 0x80000000) - dVar1) * dVar2
              );
  *(float *)(param_1 + 0x10) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) - dVar1) * dVar2);
  return;
}

/* _gleExtractPixel_ABGR_EXT_Uint @ 0xe2c2c (172 bytes) */
int _gleExtractPixel_ABGR_EXT_Uint(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  double dVar1;
  double dVar2;
  
  dVar2 = DOUBLE_00108da0;
  dVar1 = DOUBLE_00108d70;
  *(float *)(param_1 + 4) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_2[3]) - DOUBLE_00108d70) *
              DOUBLE_00108da0);
  *(float *)(param_1 + 8) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_2[2]) - dVar1) * dVar2);
  *(float *)(param_1 + 0xc) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_2[1]) - dVar1) * dVar2);
  *(float *)(param_1 + 0x10) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*param_2) - dVar1) * dVar2);
  return;
}

/* _gleExtractPixel_ABGR_EXT_Float @ 0xe2cd8 (36 bytes) */
int _gleExtractPixel_ABGR_EXT_Float(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *(undefined4 *)(param_1 + 4) = param_2[3];
  *(undefined4 *)(param_1 + 8) = param_2[2];
  *(undefined4 *)(param_1 + 0xc) = param_2[1];
  *(undefined4 *)(param_1 + 0x10) = *param_2;
  return;
}

/* _gleExtractPixel_BGRA_EXT_Byte @ 0xe2cfc (188 bytes) */
int _gleExtractPixel_BGRA_EXT_Byte(param_1, param_2)
  int param_1;
  char *param_2;
{
  double dVar1;
  float fVar2;
  
  fVar2 = FLOAT_00108e98;
  dVar1 = DOUBLE_00108d58;
  *(float *)(param_1 + 4) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[2] ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e98;
  *(float *)(param_1 + 8) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - dVar1) * fVar2;
  *(float *)(param_1 + 0xc) =
       (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - dVar1) * fVar2;
  *(float *)(param_1 + 0x10) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[3] ^ 0x80000000) - dVar1) * fVar2;
  return;
}

/* _gleExtractPixel_BGRA_EXT_Ubyte @ 0xe2db8 (172 bytes) */
int _gleExtractPixel_BGRA_EXT_Ubyte(param_1, param_2)
  int param_1;
  byte *param_2;
{
  float fVar1;
  
  fVar1 = FLOAT_00108e78;
  *(float *)(param_1 + 4) = (GH_U2F((unsigned int)((param_2[2] | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  *(float *)(param_1 + 8) = (GH_U2F((unsigned int)((param_2[1] | 0x4b000000))) - 8388608.0) * fVar1;
  *(float *)(param_1 + 0xc) = (GH_U2F((unsigned int)((*param_2 | 0x4b000000))) - 8388608.0) * fVar1;
  *(float *)(param_1 + 0x10) = (GH_U2F((unsigned int)((param_2[3] | 0x4b000000))) - 8388608.0) * fVar1;
  return;
}

/* _gleExtractPixel_BGRA_EXT_Short @ 0xe2e64 (172 bytes) */
int _gleExtractPixel_BGRA_EXT_Short(param_1, param_2)
  int param_1;
  short *param_2;
{
  double dVar1;
  float fVar2;
  
  fVar2 = FLOAT_00108e9c;
  dVar1 = DOUBLE_00108d58;
  *(float *)(param_1 + 4) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[2] ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e9c;
  *(float *)(param_1 + 8) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - dVar1) * fVar2;
  *(float *)(param_1 + 0xc) =
       (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - dVar1) * fVar2;
  *(float *)(param_1 + 0x10) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[3] ^ 0x80000000) - dVar1) * fVar2;
  return;
}

/* _gleExtractPixel_BGRA_EXT_Ushort @ 0xe2f10 (172 bytes) */
int _gleExtractPixel_BGRA_EXT_Ushort(param_1, param_2)
  int param_1;
  ushort *param_2;
{
  float fVar1;
  
  fVar1 = FLOAT_00108e74;
  *(float *)(param_1 + 4) = (GH_U2F((unsigned int)((param_2[2] | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(float *)(param_1 + 8) = (GH_U2F((unsigned int)((param_2[1] | 0x4b000000))) - 8388608.0) * fVar1;
  *(float *)(param_1 + 0xc) = (GH_U2F((unsigned int)((*param_2 | 0x4b000000))) - 8388608.0) * fVar1;
  *(float *)(param_1 + 0x10) = (GH_U2F((unsigned int)((param_2[3] | 0x4b000000))) - 8388608.0) * fVar1;
  return;
}

/* _gleExtractPixel_BGRA_EXT_Int @ 0xe2fbc (188 bytes) */
int _gleExtractPixel_BGRA_EXT_Int(param_1, param_2)
  int param_1;
  uint *param_2;
{
  double dVar1;
  double dVar2;
  
  dVar2 = DOUBLE_00108d88;
  dVar1 = DOUBLE_00108d58;
  *(float *)(param_1 + 4) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_2[2] ^ 0x80000000) -
                              DOUBLE_00108d58) * DOUBLE_00108d88);
  *(float *)(param_1 + 8) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_2[1] ^ 0x80000000) - dVar1) * dVar2
              );
  *(float *)(param_1 + 0xc) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) - dVar1) * dVar2);
  *(float *)(param_1 + 0x10) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_2[3] ^ 0x80000000) - dVar1) * dVar2
              );
  return;
}

/* _gleExtractPixel_BGRA_EXT_Uint @ 0xe3078 (172 bytes) */
int _gleExtractPixel_BGRA_EXT_Uint(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  double dVar1;
  double dVar2;
  
  dVar2 = DOUBLE_00108da0;
  dVar1 = DOUBLE_00108d70;
  *(float *)(param_1 + 4) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_2[2]) - DOUBLE_00108d70) *
              DOUBLE_00108da0);
  *(float *)(param_1 + 8) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_2[1]) - dVar1) * dVar2);
  *(float *)(param_1 + 0xc) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*param_2) - dVar1) * dVar2);
  *(float *)(param_1 + 0x10) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_2[3]) - dVar1) * dVar2);
  return;
}

/* _gleExtractPixel_BGRA_EXT_Float @ 0xe3124 (36 bytes) */
int _gleExtractPixel_BGRA_EXT_Float(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *(undefined4 *)(param_1 + 4) = param_2[2];
  *(undefined4 *)(param_1 + 8) = param_2[1];
  *(undefined4 *)(param_1 + 0xc) = *param_2;
  *(undefined4 *)(param_1 + 0x10) = param_2[3];
  return;
}

/* _gleExtractPixel_BGRA_4444 @ 0xe3148 (188 bytes) */
int _gleExtractPixel_BGRA_4444(param_1, param_2)
  int param_1;
  ushort *param_2;
{
  double dVar1;
  float fVar2;
  
  fVar2 = FLOAT_00108f58;
  dVar1 = DOUBLE_00108d58;
  *(float *)(param_1 + 0xc) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 0xc ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108f58;
  *(float *)(param_1 + 8) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 8 & 0xf ^ 0x80000000) - dVar1) * fVar2;
  *(float *)(param_1 + 4) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 4 & 0xf ^ 0x80000000) - dVar1) * fVar2;
  *(float *)(param_1 + 0x10) =
       (float)((double)CONCAT44(0x43300000,*param_2 & 0xf ^ 0x80000000) - dVar1) * fVar2;
  return;
}

/* _gleExtractPixel_BGRA_4444Rev @ 0xe3204 (188 bytes) */
int _gleExtractPixel_BGRA_4444Rev(param_1, param_2)
  int param_1;
  ushort *param_2;
{
  double dVar1;
  float fVar2;
  
  fVar2 = FLOAT_00108f58;
  dVar1 = DOUBLE_00108d58;
  *(float *)(param_1 + 0x10) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 0xc ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108f58;
  *(float *)(param_1 + 4) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 8 & 0xf ^ 0x80000000) - dVar1) * fVar2;
  *(float *)(param_1 + 8) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 4 & 0xf ^ 0x80000000) - dVar1) * fVar2;
  *(float *)(param_1 + 0xc) =
       (float)((double)CONCAT44(0x43300000,*param_2 & 0xf ^ 0x80000000) - dVar1) * fVar2;
  return;
}

/* _gleExtractPixel_BGRA_5551 @ 0xe32c0 (184 bytes) */
int _gleExtractPixel_BGRA_5551(param_1, param_2)
  int param_1;
  ushort *param_2;
{
  double dVar1;
  float fVar2;
  
  fVar2 = FLOAT_00108f5c;
  dVar1 = DOUBLE_00108d58;
  *(float *)(param_1 + 0xc) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 0xb ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108f5c;
  *(float *)(param_1 + 8) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 6 & 0x1f ^ 0x80000000) - dVar1) * fVar2;
  *(float *)(param_1 + 4) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 1 & 0x1f ^ 0x80000000) - dVar1) * fVar2;
  *(float *)(param_1 + 0x10) =
       (float)((double)CONCAT44(0x43300000,*param_2 & 1 ^ 0x80000000) - dVar1);
  return;
}

/* _gleExtractPixel_BGRA_1555Rev @ 0xe3378 (184 bytes) */
int _gleExtractPixel_BGRA_1555Rev(param_1, param_2)
  int param_1;
  ushort *param_2;
{
  double dVar1;
  float fVar2;
  
  fVar2 = FLOAT_00108f5c;
  dVar1 = DOUBLE_00108d58;
  *(float *)(param_1 + 0x10) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 0xf ^ 0x80000000) - DOUBLE_00108d58);
  *(float *)(param_1 + 4) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 10 & 0x1f ^ 0x80000000) - dVar1) * fVar2;
  *(float *)(param_1 + 8) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 5 & 0x1f ^ 0x80000000) - dVar1) * fVar2;
  *(float *)(param_1 + 0xc) =
       (float)((double)CONCAT44(0x43300000,*param_2 & 0x1f ^ 0x80000000) - dVar1) * fVar2;
  return;
}

/* _gleExtractPixel_BGRA_8888 @ 0xe3430 (156 bytes) */
int _gleExtractPixel_BGRA_8888(param_1, param_2)
  int param_1;
  byte *param_2;
{
  double dVar1;
  float fVar2;
  
  fVar2 = FLOAT_00108e64;
  dVar1 = DOUBLE_00108d70;
  *(float *)(param_1 + 0xc) =
       (float)((double)CONCAT44(0x43300000,(uint)*param_2) - DOUBLE_00108d70) * FLOAT_00108e64;
  *(float *)(param_1 + 8) = (float)((double)CONCAT44(0x43300000,(uint)param_2[1]) - dVar1) * fVar2;
  *(float *)(param_1 + 4) = (float)((double)CONCAT44(0x43300000,(uint)param_2[2]) - dVar1) * fVar2;
  *(float *)(param_1 + 0x10) =
       (float)((double)CONCAT44(0x43300000,(uint)param_2[3]) - dVar1) * fVar2;
  return;
}

/* _gleExtractPixel_BGRA_8888Rev @ 0xe34cc (156 bytes) */
int _gleExtractPixel_BGRA_8888Rev(param_1, param_2)
  int param_1;
  byte *param_2;
{
  double dVar1;
  float fVar2;
  
  fVar2 = FLOAT_00108e64;
  dVar1 = DOUBLE_00108d70;
  *(float *)(param_1 + 0x10) =
       (float)((double)CONCAT44(0x43300000,(uint)*param_2) - DOUBLE_00108d70) * FLOAT_00108e64;
  *(float *)(param_1 + 4) = (float)((double)CONCAT44(0x43300000,(uint)param_2[1]) - dVar1) * fVar2;
  *(float *)(param_1 + 8) = (float)((double)CONCAT44(0x43300000,(uint)param_2[2]) - dVar1) * fVar2;
  *(float *)(param_1 + 0xc) = (float)((double)CONCAT44(0x43300000,(uint)param_2[3]) - dVar1) * fVar2
  ;
  return;
}

/* _gleExtractPixel_BGRA_1010102 @ 0xe3568 (180 bytes) */
int _gleExtractPixel_BGRA_1010102(param_1, param_2)
  int param_1;
  uint *param_2;
{
  double dVar1;
  float fVar2;
  
  fVar2 = FLOAT_00108f60;
  dVar1 = DOUBLE_00108d70;
  *(float *)(param_1 + 0xc) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 0x16) - DOUBLE_00108d70) * FLOAT_00108f60;
  *(float *)(param_1 + 8) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 0xc & 0x3ff) - dVar1) * fVar2;
  *(float *)(param_1 + 4) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 2 & 0x3ff) - dVar1) * fVar2;
  *(float *)(param_1 + 0x10) =
       (float)((double)CONCAT44(0x43300000,*param_2 & 3) - dVar1) * FLOAT_00108eb8;
  return;
}

/* _gleExtractPixel_BGRA_2101010Rev @ 0xe361c (180 bytes) */
int _gleExtractPixel_BGRA_2101010Rev(param_1, param_2)
  int param_1;
  uint *param_2;
{
  double dVar1;
  float fVar2;
  
  fVar2 = FLOAT_00108f60;
  dVar1 = DOUBLE_00108d70;
  *(float *)(param_1 + 0x10) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 0x1e) - DOUBLE_00108d70) * FLOAT_00108eb8;
  *(float *)(param_1 + 4) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 0x14 & 0x3ff) - dVar1) * fVar2;
  *(float *)(param_1 + 8) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 10 & 0x3ff) - dVar1) * fVar2;
  *(float *)(param_1 + 0xc) = (float)((double)CONCAT44(0x43300000,*param_2 & 0x3ff) - dVar1) * fVar2
  ;
  return;
}

/* _gleExtractPixel_BGR_EXT_Byte @ 0xe36d0 (152 bytes) */
int _gleExtractPixel_BGR_EXT_Byte(param_1, param_2)
  int param_1;
  char *param_2;
{
  double dVar1;
  float fVar2;
  
  fVar2 = FLOAT_00108e98;
  dVar1 = DOUBLE_00108d58;
  *(float *)(param_1 + 4) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[2] ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e98;
  *(float *)(param_1 + 8) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - dVar1) * fVar2;
  *(float *)(param_1 + 0xc) =
       (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - dVar1) * fVar2;
  return;
}

/* _gleExtractPixel_BGR_EXT_Ubyte @ 0xe3768 (136 bytes) */
int _gleExtractPixel_BGR_EXT_Ubyte(param_1, param_2)
  int param_1;
  byte *param_2;
{
  float fVar1;
  
  fVar1 = FLOAT_00108e78;
  *(float *)(param_1 + 4) = (GH_U2F((unsigned int)((param_2[2] | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  *(float *)(param_1 + 8) = (GH_U2F((unsigned int)((param_2[1] | 0x4b000000))) - 8388608.0) * fVar1;
  *(float *)(param_1 + 0xc) = (GH_U2F((unsigned int)((*param_2 | 0x4b000000))) - 8388608.0) * fVar1;
  return;
}

/* _gleExtractPixel_BGR_EXT_Short @ 0xe37f0 (140 bytes) */
int _gleExtractPixel_BGR_EXT_Short(param_1, param_2)
  int param_1;
  short *param_2;
{
  double dVar1;
  float fVar2;
  
  fVar2 = FLOAT_00108e9c;
  dVar1 = DOUBLE_00108d58;
  *(float *)(param_1 + 4) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[2] ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e9c;
  *(float *)(param_1 + 8) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - dVar1) * fVar2;
  *(float *)(param_1 + 0xc) =
       (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - dVar1) * fVar2;
  return;
}

/* _gleExtractPixel_BGR_EXT_Ushort @ 0xe387c (136 bytes) */
int _gleExtractPixel_BGR_EXT_Ushort(param_1, param_2)
  int param_1;
  ushort *param_2;
{
  float fVar1;
  
  fVar1 = FLOAT_00108e74;
  *(float *)(param_1 + 4) = (GH_U2F((unsigned int)((param_2[2] | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(float *)(param_1 + 8) = (GH_U2F((unsigned int)((param_2[1] | 0x4b000000))) - 8388608.0) * fVar1;
  *(float *)(param_1 + 0xc) = (GH_U2F((unsigned int)((*param_2 | 0x4b000000))) - 8388608.0) * fVar1;
  return;
}

/* _gleExtractPixel_BGR_EXT_Int @ 0xe3904 (152 bytes) */
int _gleExtractPixel_BGR_EXT_Int(param_1, param_2)
  int param_1;
  uint *param_2;
{
  double dVar1;
  double dVar2;
  
  dVar2 = DOUBLE_00108d88;
  dVar1 = DOUBLE_00108d58;
  *(float *)(param_1 + 4) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_2[2] ^ 0x80000000) -
                              DOUBLE_00108d58) * DOUBLE_00108d88);
  *(float *)(param_1 + 8) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_2[1] ^ 0x80000000) - dVar1) * dVar2
              );
  *(float *)(param_1 + 0xc) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) - dVar1) * dVar2);
  return;
}

/* _gleExtractPixel_BGR_EXT_Uint @ 0xe399c (140 bytes) */
int _gleExtractPixel_BGR_EXT_Uint(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  double dVar1;
  double dVar2;
  
  dVar2 = DOUBLE_00108da0;
  dVar1 = DOUBLE_00108d70;
  *(float *)(param_1 + 4) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_2[2]) - DOUBLE_00108d70) *
              DOUBLE_00108da0);
  *(float *)(param_1 + 8) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_2[1]) - dVar1) * dVar2);
  *(float *)(param_1 + 0xc) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*param_2) - dVar1) * dVar2);
  return;
}

/* _gleExtractPixel_BGR_EXT_Float @ 0xe3a28 (28 bytes) */
int _gleExtractPixel_BGR_EXT_Float(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *(undefined4 *)(param_1 + 4) = param_2[2];
  *(undefined4 *)(param_1 + 8) = param_2[1];
  *(undefined4 *)(param_1 + 0xc) = *param_2;
  return;
}

/* _gleExtractPixel_RGB_Byte @ 0xe3a44 (152 bytes) */
int _gleExtractPixel_RGB_Byte(param_1, param_2)
  int param_1;
  char *param_2;
{
  double dVar1;
  float fVar2;
  
  fVar2 = FLOAT_00108e98;
  dVar1 = DOUBLE_00108d58;
  *(float *)(param_1 + 4) =
       (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e98;
  *(float *)(param_1 + 8) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - dVar1) * fVar2;
  *(float *)(param_1 + 0xc) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[2] ^ 0x80000000) - dVar1) * fVar2;
  return;
}

/* _gleExtractPixel_RGB_Ubyte @ 0xe3adc (140 bytes) */
int _gleExtractPixel_RGB_Ubyte(param_1, param_2)
  int param_1;
  byte *param_2;
{
  float fVar1;
  
  fVar1 = FLOAT_00108e78;
  *(float *)(param_1 + 4) = (GH_U2F((unsigned int)((*param_2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  *(float *)(param_1 + 8) = (GH_U2F((unsigned int)((param_2[1] | 0x4b000000))) - 8388608.0) * fVar1;
  *(float *)(param_1 + 0xc) = (GH_U2F((unsigned int)((param_2[2] | 0x4b000000))) - 8388608.0) * fVar1;
  return;
}

/* _gleExtractPixel_RGB_Short @ 0xe3b68 (140 bytes) */
int _gleExtractPixel_RGB_Short(param_1, param_2)
  int param_1;
  short *param_2;
{
  double dVar1;
  float fVar2;
  
  fVar2 = FLOAT_00108e9c;
  dVar1 = DOUBLE_00108d58;
  *(float *)(param_1 + 4) =
       (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e9c;
  *(float *)(param_1 + 8) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - dVar1) * fVar2;
  *(float *)(param_1 + 0xc) =
       (float)((double)CONCAT44(0x43300000,(int)param_2[2] ^ 0x80000000) - dVar1) * fVar2;
  return;
}

/* _gleExtractPixel_RGB_Ushort @ 0xe3bf4 (140 bytes) */
int _gleExtractPixel_RGB_Ushort(param_1, param_2)
  int param_1;
  ushort *param_2;
{
  float fVar1;
  
  fVar1 = FLOAT_00108e74;
  *(float *)(param_1 + 4) = (GH_U2F((unsigned int)((*param_2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(float *)(param_1 + 8) = (GH_U2F((unsigned int)((param_2[1] | 0x4b000000))) - 8388608.0) * fVar1;
  *(float *)(param_1 + 0xc) = (GH_U2F((unsigned int)((param_2[2] | 0x4b000000))) - 8388608.0) * fVar1;
  return;
}

/* _gleExtractPixel_RGB_Int @ 0xe3c80 (152 bytes) */
int _gleExtractPixel_RGB_Int(param_1, param_2)
  int param_1;
  uint *param_2;
{
  double dVar1;
  double dVar2;
  
  dVar2 = DOUBLE_00108d88;
  dVar1 = DOUBLE_00108d58;
  *(float *)(param_1 + 4) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) - DOUBLE_00108d58)
              * DOUBLE_00108d88);
  *(float *)(param_1 + 8) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_2[1] ^ 0x80000000) - dVar1) * dVar2
              );
  *(float *)(param_1 + 0xc) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_2[2] ^ 0x80000000) - dVar1) * dVar2
              );
  return;
}

/* _gleExtractPixel_RGB_Uint @ 0xe3d18 (140 bytes) */
int _gleExtractPixel_RGB_Uint(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  double dVar1;
  double dVar2;
  
  dVar2 = DOUBLE_00108da0;
  dVar1 = DOUBLE_00108d70;
  *(float *)(param_1 + 4) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*param_2) - DOUBLE_00108d70) *
              DOUBLE_00108da0);
  *(float *)(param_1 + 8) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_2[1]) - dVar1) * dVar2);
  *(float *)(param_1 + 0xc) =
       (float)((double)(float)((double)CONCAT44(0x43300000,param_2[2]) - dVar1) * dVar2);
  return;
}

/* _gleExtractPixel_RGB_Float @ 0xe3da4 (28 bytes) */
int _gleExtractPixel_RGB_Float(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *(undefined4 *)(param_1 + 4) = *param_2;
  *(undefined4 *)(param_1 + 8) = param_2[1];
  *(undefined4 *)(param_1 + 0xc) = param_2[2];
  return;
}

/* _gleExtractPixel_RGB_332 @ 0xe3dc0 (160 bytes) */
int _gleExtractPixel_RGB_332(param_1, param_2)
  int param_1;
  byte *param_2;
{
  double dVar1;
  float fVar2;
  
  fVar2 = FLOAT_00108f64;
  dVar1 = DOUBLE_00108d58;
  *(float *)(param_1 + 4) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 5 ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108f64;
  *(float *)(param_1 + 8) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 2 & 7 ^ 0x80000000) - dVar1) * fVar2;
  *(float *)(param_1 + 0xc) =
       (float)((double)CONCAT44(0x43300000,*param_2 & 3 ^ 0x80000000) - dVar1) * FLOAT_00108eb8;
  return;
}

/* _gleExtractPixel_RGB_233Rev @ 0xe3e60 (160 bytes) */
int _gleExtractPixel_RGB_233Rev(param_1, param_2)
  int param_1;
  byte *param_2;
{
  double dVar1;
  float fVar2;
  
  fVar2 = FLOAT_00108f64;
  dVar1 = DOUBLE_00108d58;
  *(float *)(param_1 + 0xc) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 6 ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108eb8;
  *(float *)(param_1 + 8) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 3 & 7 ^ 0x80000000) - dVar1) * fVar2;
  *(float *)(param_1 + 4) =
       (float)((double)CONCAT44(0x43300000,*param_2 & 7 ^ 0x80000000) - dVar1) * fVar2;
  return;
}

/* _gleExtractPixel_RGB_565 @ 0xe3f00 (160 bytes) */
int _gleExtractPixel_RGB_565(param_1, param_2)
  int param_1;
  ushort *param_2;
{
  double dVar1;
  float fVar2;
  float fVar3;
  
  fVar3 = FLOAT_00108f68;
  fVar2 = FLOAT_00108f5c;
  dVar1 = DOUBLE_00108d58;
  *(float *)(param_1 + 4) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 0xb ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108f5c;
  *(float *)(param_1 + 8) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 5 & 0x3f ^ 0x80000000) - dVar1) * fVar3;
  *(float *)(param_1 + 0xc) =
       (float)((double)CONCAT44(0x43300000,*param_2 & 0x1f ^ 0x80000000) - dVar1) * fVar2;
  return;
}

/* _gleExtractPixel_RGB_565Rev @ 0xe3fa0 (160 bytes) */
int _gleExtractPixel_RGB_565Rev(param_1, param_2)
  int param_1;
  ushort *param_2;
{
  double dVar1;
  float fVar2;
  float fVar3;
  
  fVar3 = FLOAT_00108f68;
  fVar2 = FLOAT_00108f5c;
  dVar1 = DOUBLE_00108d58;
  *(float *)(param_1 + 0xc) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 0xb ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108f5c;
  *(float *)(param_1 + 8) =
       (float)((double)CONCAT44(0x43300000,*param_2 >> 5 & 0x3f ^ 0x80000000) - dVar1) * fVar3;
  *(float *)(param_1 + 4) =
       (float)((double)CONCAT44(0x43300000,*param_2 & 0x1f ^ 0x80000000) - dVar1) * fVar2;
  return;
}

/* _gleExtractPixel_R_Byte @ 0xe4040 (80 bytes) */
int _gleExtractPixel_R_Byte(param_1, param_2)
  int param_1;
  char *param_2;
{
  *(float *)(param_1 + 4) =
       (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e98;
  return;
}

