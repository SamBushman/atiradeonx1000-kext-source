#include "decls.h"

/* _glePipelineProgramTargetExtactor @ 0xe1d34 (52 bytes) */
int _glePipelineProgramTargetExtactor(unusedArg1, param_2)
  undefined4 unusedArg1;
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
void _glePPRelocateOutput(param_1, param_2, param_3)
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
double _gleBytesPerElement(uint type)
{
  if (type < 0x1404) {
    if (0x1401 < type) {
LAB_000e1e14:
      return (double)FLOAT_00108ea4;
    }
    if (0x13ff < type) {
      return (double)FLOAT_00108e54;
    }
  }
  else {
    if (type == 0x140b) goto LAB_000e1e14;
    if (type < 0x140c) {
      if (type < 0x1407) {
        return (double)FLOAT_00108ea8;
      }
    }
    else if (type == 0x1a00) {
      return (double)FLOAT_00108f4c;
    }
  }
  return (double)FLOAT_00108e50;
}

/* _gleElementOffset @ 0xe1e44 (112 bytes) */
int _gleElementOffset(unusedArg1, param_2, param_3, param_4, format, param_6)
  undefined4 unusedArg1;
  int param_2;
  int param_3;
  int param_4;
  undefined4 format;
  int param_6;
{
  int iVar1;
  int iVar2;
  
  iVar2 = _gleComponents(format);
  iVar1 = iVar2 * param_6;
  if (param_4 == 0x1a00) {
    iVar1 = _gleRowBytes(format,0x1a00,param_6);
    iVar1 = iVar1 << 3;
  }
  return iVar1 * param_3 + iVar2 * param_2;
}

/* _gleGetFrac @ 0xe1eb4 (208 bytes) */
int _gleGetFrac(float floatArg1)
{
  if ((double)FLOAT_00108e50 <= floatArg1) {
    return (int)((floatArg1 - (float)((double)CONCAT44(0x43300000,(int)floatArg1 ^ 0x80000000) -
                                       DOUBLE_00108d58)) * FLOAT_00108f54);
  }
  return (int)((floatArg1 - (float)((double)CONCAT44(0x43300000,
                                                       (int)(floatArg1 - (double)FLOAT_00108f50) ^
                                                       0x80000000) - DOUBLE_00108d58)) *
              FLOAT_00108f54);
}

/* _gleExtractPixel_RGBA_Byte @ 0xe1f84 (188 bytes) */
void _gleExtractPixel_RGBA_Byte(pixel, src)
  int pixel;
  char *src;
{
  double intToDoubleBias;
  float channelScale;
  
  channelScale = FLOAT_00108e98;
  intToDoubleBias = DOUBLE_00108d58;
  *(float *)(pixel + 4) =
       (float)((double)CONCAT44(0x43300000,(int)*src ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e98;
  *(float *)(pixel + 8) =
       (float)((double)CONCAT44(0x43300000,(int)src[1] ^ 0x80000000) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 0xc) =
       (float)((double)CONCAT44(0x43300000,(int)src[2] ^ 0x80000000) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 0x10) =
       (float)((double)CONCAT44(0x43300000,(int)src[3] ^ 0x80000000) - intToDoubleBias) * channelScale;
  return;
}

/* _gleExtractPixel_RGBA_Short @ 0xe2040 (172 bytes) */
void _gleExtractPixel_RGBA_Short(pixel, src)
  int pixel;
  short *src;
{
  double intToDoubleBias;
  float channelScale;
  
  channelScale = FLOAT_00108e9c;
  intToDoubleBias = DOUBLE_00108d58;
  *(float *)(pixel + 4) =
       (float)((double)CONCAT44(0x43300000,(int)*src ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e9c;
  *(float *)(pixel + 8) =
       (float)((double)CONCAT44(0x43300000,(int)src[1] ^ 0x80000000) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 0xc) =
       (float)((double)CONCAT44(0x43300000,(int)src[2] ^ 0x80000000) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 0x10) =
       (float)((double)CONCAT44(0x43300000,(int)src[3] ^ 0x80000000) - intToDoubleBias) * channelScale;
  return;
}

/* _gleExtractPixel_RGBA_Ushort @ 0xe20ec (176 bytes) */
void _gleExtractPixel_RGBA_Ushort(pixel, src)
  int pixel;
  ushort *src;
{
  float channelScale;
  
  channelScale = FLOAT_00108e74;
  *(float *)(pixel + 4) = (GH_U2F((unsigned int)((*src | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(float *)(pixel + 8) = (GH_U2F((unsigned int)((src[1] | 0x4b000000))) - 8388608.0) * channelScale;
  *(float *)(pixel + 0xc) = (GH_U2F((unsigned int)((src[2] | 0x4b000000))) - 8388608.0) * channelScale;
  *(float *)(pixel + 0x10) = (GH_U2F((unsigned int)((src[3] | 0x4b000000))) - 8388608.0) * channelScale;
  return;
}

/* _gleExtractPixel_RGBA_Int @ 0xe219c (188 bytes) */
void _gleExtractPixel_RGBA_Int(pixel, src)
  int pixel;
  uint *src;
{
  double intToDoubleBias;
  double channelScale;
  
  channelScale = DOUBLE_00108d88;
  intToDoubleBias = DOUBLE_00108d58;
  *(float *)(pixel + 4) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*src ^ 0x80000000) - DOUBLE_00108d58)
              * DOUBLE_00108d88);
  *(float *)(pixel + 8) =
       (float)((double)(float)((double)CONCAT44(0x43300000,src[1] ^ 0x80000000) - intToDoubleBias) * channelScale
              );
  *(float *)(pixel + 0xc) =
       (float)((double)(float)((double)CONCAT44(0x43300000,src[2] ^ 0x80000000) - intToDoubleBias) * channelScale
              );
  *(float *)(pixel + 0x10) =
       (float)((double)(float)((double)CONCAT44(0x43300000,src[3] ^ 0x80000000) - intToDoubleBias) * channelScale
              );
  return;
}

/* _gleExtractPixel_RGBA_Uint @ 0xe2258 (172 bytes) */
void _gleExtractPixel_RGBA_Uint(pixel, src)
  int pixel;
  undefined4 *src;
{
  double intToDoubleBias;
  double channelScale;
  
  channelScale = DOUBLE_00108da0;
  intToDoubleBias = DOUBLE_00108d70;
  *(float *)(pixel + 4) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*src) - DOUBLE_00108d70) *
              DOUBLE_00108da0);
  *(float *)(pixel + 8) =
       (float)((double)(float)((double)CONCAT44(0x43300000,src[1]) - intToDoubleBias) * channelScale);
  *(float *)(pixel + 0xc) =
       (float)((double)(float)((double)CONCAT44(0x43300000,src[2]) - intToDoubleBias) * channelScale);
  *(float *)(pixel + 0x10) =
       (float)((double)(float)((double)CONCAT44(0x43300000,src[3]) - intToDoubleBias) * channelScale);
  return;
}

/* _gleExtractPixel_RGBA_Float @ 0xe2304 (36 bytes) */
void _gleExtractPixel_RGBA_Float(pixel, src)
  int pixel;
  undefined4 *src;
{
  *(undefined4 *)(pixel + 4) = *src;
  *(undefined4 *)(pixel + 8) = src[1];
  *(undefined4 *)(pixel + 0xc) = src[2];
  *(undefined4 *)(pixel + 0x10) = src[3];
  return;
}

/* _gleExtractPixel_RGBA_4444 @ 0xe2328 (188 bytes) */
void _gleExtractPixel_RGBA_4444(pixel, src)
  int pixel;
  ushort *src;
{
  double intToDoubleBias;
  float channelScale;
  
  channelScale = FLOAT_00108f58;
  intToDoubleBias = DOUBLE_00108d58;
  *(float *)(pixel + 4) =
       (float)((double)CONCAT44(0x43300000,*src >> 0xc ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108f58;
  *(float *)(pixel + 8) =
       (float)((double)CONCAT44(0x43300000,*src >> 8 & 0xf ^ 0x80000000) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 0xc) =
       (float)((double)CONCAT44(0x43300000,*src >> 4 & 0xf ^ 0x80000000) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 0x10) =
       (float)((double)CONCAT44(0x43300000,*src & 0xf ^ 0x80000000) - intToDoubleBias) * channelScale;
  return;
}

/* _gleExtractPixel_RGBA_4444Rev @ 0xe23e4 (188 bytes) */
void _gleExtractPixel_RGBA_4444Rev(pixel, src)
  int pixel;
  ushort *src;
{
  double intToDoubleBias;
  float channelScale;
  
  channelScale = FLOAT_00108f58;
  intToDoubleBias = DOUBLE_00108d58;
  *(float *)(pixel + 0x10) =
       (float)((double)CONCAT44(0x43300000,*src >> 0xc ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108f58;
  *(float *)(pixel + 0xc) =
       (float)((double)CONCAT44(0x43300000,*src >> 8 & 0xf ^ 0x80000000) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 8) =
       (float)((double)CONCAT44(0x43300000,*src >> 4 & 0xf ^ 0x80000000) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 4) =
       (float)((double)CONCAT44(0x43300000,*src & 0xf ^ 0x80000000) - intToDoubleBias) * channelScale;
  return;
}

/* _gleExtractPixel_RGBA_5551 @ 0xe24a0 (184 bytes) */
void _gleExtractPixel_RGBA_5551(pixel, src)
  int pixel;
  ushort *src;
{
  double intToDoubleBias;
  float channelScale;
  
  channelScale = FLOAT_00108f5c;
  intToDoubleBias = DOUBLE_00108d58;
  *(float *)(pixel + 4) =
       (float)((double)CONCAT44(0x43300000,*src >> 0xb ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108f5c;
  *(float *)(pixel + 8) =
       (float)((double)CONCAT44(0x43300000,*src >> 6 & 0x1f ^ 0x80000000) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 0xc) =
       (float)((double)CONCAT44(0x43300000,*src >> 1 & 0x1f ^ 0x80000000) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 0x10) =
       (float)((double)CONCAT44(0x43300000,*src & 1 ^ 0x80000000) - intToDoubleBias);
  return;
}

/* _gleExtractPixel_RGBA_1555Rev @ 0xe2558 (184 bytes) */
void _gleExtractPixel_RGBA_1555Rev(pixel, src)
  int pixel;
  ushort *src;
{
  double intToDoubleBias;
  float channelScale;
  
  channelScale = FLOAT_00108f5c;
  intToDoubleBias = DOUBLE_00108d58;
  *(float *)(pixel + 0x10) =
       (float)((double)CONCAT44(0x43300000,*src >> 0xf ^ 0x80000000) - DOUBLE_00108d58);
  *(float *)(pixel + 0xc) =
       (float)((double)CONCAT44(0x43300000,*src >> 10 & 0x1f ^ 0x80000000) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 8) =
       (float)((double)CONCAT44(0x43300000,*src >> 5 & 0x1f ^ 0x80000000) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 4) =
       (float)((double)CONCAT44(0x43300000,*src & 0x1f ^ 0x80000000) - intToDoubleBias) * channelScale;
  return;
}

/* _gleExtractPixel_RGBA_8888 @ 0xe2610 (156 bytes) */
void _gleExtractPixel_RGBA_8888(pixel, src)
  int pixel;
  byte *src;
{
  double intToDoubleBias;
  float channelScale;
  
  channelScale = FLOAT_00108e64;
  intToDoubleBias = DOUBLE_00108d70;
  *(float *)(pixel + 4) =
       (float)((double)CONCAT44(0x43300000,(uint)*src) - DOUBLE_00108d70) * FLOAT_00108e64;
  *(float *)(pixel + 8) = (float)((double)CONCAT44(0x43300000,(uint)src[1]) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 0xc) = (float)((double)CONCAT44(0x43300000,(uint)src[2]) - intToDoubleBias) * channelScale
  ;
  *(float *)(pixel + 0x10) =
       (float)((double)CONCAT44(0x43300000,(uint)src[3]) - intToDoubleBias) * channelScale;
  return;
}

/* _gleExtractPixel_RGBA_8888Rev @ 0xe26ac (156 bytes) */
void _gleExtractPixel_RGBA_8888Rev(pixel, src)
  int pixel;
  byte *src;
{
  double intToDoubleBias;
  float channelScale;
  
  channelScale = FLOAT_00108e64;
  intToDoubleBias = DOUBLE_00108d70;
  *(float *)(pixel + 0x10) =
       (float)((double)CONCAT44(0x43300000,(uint)*src) - DOUBLE_00108d70) * FLOAT_00108e64;
  *(float *)(pixel + 0xc) = (float)((double)CONCAT44(0x43300000,(uint)src[1]) - intToDoubleBias) * channelScale
  ;
  *(float *)(pixel + 8) = (float)((double)CONCAT44(0x43300000,(uint)src[2]) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 4) = (float)((double)CONCAT44(0x43300000,(uint)src[3]) - intToDoubleBias) * channelScale;
  return;
}

/* _gleExtractPixel_RGBA_1010102 @ 0xe2748 (180 bytes) */
void _gleExtractPixel_RGBA_1010102(pixel, src)
  int pixel;
  uint *src;
{
  double intToDoubleBias;
  float channelScale;
  
  channelScale = FLOAT_00108f60;
  intToDoubleBias = DOUBLE_00108d70;
  *(float *)(pixel + 4) =
       (float)((double)CONCAT44(0x43300000,*src >> 0x16) - DOUBLE_00108d70) * FLOAT_00108f60;
  *(float *)(pixel + 8) =
       (float)((double)CONCAT44(0x43300000,*src >> 0xc & 0x3ff) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 0xc) =
       (float)((double)CONCAT44(0x43300000,*src >> 2 & 0x3ff) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 0x10) =
       (float)((double)CONCAT44(0x43300000,*src & 3) - intToDoubleBias) * FLOAT_00108eb8;
  return;
}

/* _gleExtractPixel_RGBA_2101010Rev @ 0xe27fc (180 bytes) */
void _gleExtractPixel_RGBA_2101010Rev(pixel, src)
  int pixel;
  uint *src;
{
  double intToDoubleBias;
  float channelScale;
  
  channelScale = FLOAT_00108f60;
  intToDoubleBias = DOUBLE_00108d70;
  *(float *)(pixel + 0x10) =
       (float)((double)CONCAT44(0x43300000,*src >> 0x1e) - DOUBLE_00108d70) * FLOAT_00108eb8;
  *(float *)(pixel + 0xc) =
       (float)((double)CONCAT44(0x43300000,*src >> 0x14 & 0x3ff) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 8) =
       (float)((double)CONCAT44(0x43300000,*src >> 10 & 0x3ff) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 4) = (float)((double)CONCAT44(0x43300000,*src & 0x3ff) - intToDoubleBias) * channelScale;
  return;
}

/* _gleExtractPixel_ABGR_EXT_Byte @ 0xe28b0 (188 bytes) */
void _gleExtractPixel_ABGR_EXT_Byte(pixel, src)
  int pixel;
  char *src;
{
  double intToDoubleBias;
  float channelScale;
  
  channelScale = FLOAT_00108e98;
  intToDoubleBias = DOUBLE_00108d58;
  *(float *)(pixel + 4) =
       (float)((double)CONCAT44(0x43300000,(int)src[3] ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e98;
  *(float *)(pixel + 8) =
       (float)((double)CONCAT44(0x43300000,(int)src[2] ^ 0x80000000) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 0xc) =
       (float)((double)CONCAT44(0x43300000,(int)src[1] ^ 0x80000000) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 0x10) =
       (float)((double)CONCAT44(0x43300000,(int)*src ^ 0x80000000) - intToDoubleBias) * channelScale;
  return;
}

/* _gleExtractPixel_ABGR_EXT_Ubyte @ 0xe296c (172 bytes) */
void _gleExtractPixel_ABGR_EXT_Ubyte(pixel, src)
  int pixel;
  byte *src;
{
  float channelScale;
  
  channelScale = FLOAT_00108e78;
  *(float *)(pixel + 4) = (GH_U2F((unsigned int)((src[3] | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  *(float *)(pixel + 8) = (GH_U2F((unsigned int)((src[2] | 0x4b000000))) - 8388608.0) * channelScale;
  *(float *)(pixel + 0xc) = (GH_U2F((unsigned int)((src[1] | 0x4b000000))) - 8388608.0) * channelScale;
  *(float *)(pixel + 0x10) = (GH_U2F((unsigned int)((*src | 0x4b000000))) - 8388608.0) * channelScale;
  return;
}

/* _gleExtractPixel_ABGR_EXT_Short @ 0xe2a18 (172 bytes) */
void _gleExtractPixel_ABGR_EXT_Short(pixel, src)
  int pixel;
  short *src;
{
  double intToDoubleBias;
  float channelScale;
  
  channelScale = FLOAT_00108e9c;
  intToDoubleBias = DOUBLE_00108d58;
  *(float *)(pixel + 4) =
       (float)((double)CONCAT44(0x43300000,(int)src[3] ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e9c;
  *(float *)(pixel + 8) =
       (float)((double)CONCAT44(0x43300000,(int)src[2] ^ 0x80000000) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 0xc) =
       (float)((double)CONCAT44(0x43300000,(int)src[1] ^ 0x80000000) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 0x10) =
       (float)((double)CONCAT44(0x43300000,(int)*src ^ 0x80000000) - intToDoubleBias) * channelScale;
  return;
}

/* _gleExtractPixel_ABGR_EXT_Ushort @ 0xe2ac4 (172 bytes) */
void _gleExtractPixel_ABGR_EXT_Ushort(pixel, src)
  int pixel;
  ushort *src;
{
  float channelScale;
  
  channelScale = FLOAT_00108e74;
  *(float *)(pixel + 4) = (GH_U2F((unsigned int)((src[3] | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(float *)(pixel + 8) = (GH_U2F((unsigned int)((src[2] | 0x4b000000))) - 8388608.0) * channelScale;
  *(float *)(pixel + 0xc) = (GH_U2F((unsigned int)((src[1] | 0x4b000000))) - 8388608.0) * channelScale;
  *(float *)(pixel + 0x10) = (GH_U2F((unsigned int)((*src | 0x4b000000))) - 8388608.0) * channelScale;
  return;
}

/* _gleExtractPixel_ABGR_EXT_Int @ 0xe2b70 (188 bytes) */
void _gleExtractPixel_ABGR_EXT_Int(pixel, src)
  int pixel;
  uint *src;
{
  double intToDoubleBias;
  double channelScale;
  
  channelScale = DOUBLE_00108d88;
  intToDoubleBias = DOUBLE_00108d58;
  *(float *)(pixel + 4) =
       (float)((double)(float)((double)CONCAT44(0x43300000,src[3] ^ 0x80000000) -
                              DOUBLE_00108d58) * DOUBLE_00108d88);
  *(float *)(pixel + 8) =
       (float)((double)(float)((double)CONCAT44(0x43300000,src[2] ^ 0x80000000) - intToDoubleBias) * channelScale
              );
  *(float *)(pixel + 0xc) =
       (float)((double)(float)((double)CONCAT44(0x43300000,src[1] ^ 0x80000000) - intToDoubleBias) * channelScale
              );
  *(float *)(pixel + 0x10) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*src ^ 0x80000000) - intToDoubleBias) * channelScale);
  return;
}

/* _gleExtractPixel_ABGR_EXT_Uint @ 0xe2c2c (172 bytes) */
void _gleExtractPixel_ABGR_EXT_Uint(pixel, src)
  int pixel;
  undefined4 *src;
{
  double intToDoubleBias;
  double channelScale;
  
  channelScale = DOUBLE_00108da0;
  intToDoubleBias = DOUBLE_00108d70;
  *(float *)(pixel + 4) =
       (float)((double)(float)((double)CONCAT44(0x43300000,src[3]) - DOUBLE_00108d70) *
              DOUBLE_00108da0);
  *(float *)(pixel + 8) =
       (float)((double)(float)((double)CONCAT44(0x43300000,src[2]) - intToDoubleBias) * channelScale);
  *(float *)(pixel + 0xc) =
       (float)((double)(float)((double)CONCAT44(0x43300000,src[1]) - intToDoubleBias) * channelScale);
  *(float *)(pixel + 0x10) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*src) - intToDoubleBias) * channelScale);
  return;
}

/* _gleExtractPixel_ABGR_EXT_Float @ 0xe2cd8 (36 bytes) */
void _gleExtractPixel_ABGR_EXT_Float(pixel, src)
  int pixel;
  undefined4 *src;
{
  *(undefined4 *)(pixel + 4) = src[3];
  *(undefined4 *)(pixel + 8) = src[2];
  *(undefined4 *)(pixel + 0xc) = src[1];
  *(undefined4 *)(pixel + 0x10) = *src;
  return;
}

/* _gleExtractPixel_BGRA_EXT_Byte @ 0xe2cfc (188 bytes) */
void _gleExtractPixel_BGRA_EXT_Byte(pixel, src)
  int pixel;
  char *src;
{
  double intToDoubleBias;
  float channelScale;
  
  channelScale = FLOAT_00108e98;
  intToDoubleBias = DOUBLE_00108d58;
  *(float *)(pixel + 4) =
       (float)((double)CONCAT44(0x43300000,(int)src[2] ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e98;
  *(float *)(pixel + 8) =
       (float)((double)CONCAT44(0x43300000,(int)src[1] ^ 0x80000000) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 0xc) =
       (float)((double)CONCAT44(0x43300000,(int)*src ^ 0x80000000) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 0x10) =
       (float)((double)CONCAT44(0x43300000,(int)src[3] ^ 0x80000000) - intToDoubleBias) * channelScale;
  return;
}

/* _gleExtractPixel_BGRA_EXT_Ubyte @ 0xe2db8 (172 bytes) */
void _gleExtractPixel_BGRA_EXT_Ubyte(pixel, src)
  int pixel;
  byte *src;
{
  float channelScale;
  
  channelScale = FLOAT_00108e78;
  *(float *)(pixel + 4) = (GH_U2F((unsigned int)((src[2] | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  *(float *)(pixel + 8) = (GH_U2F((unsigned int)((src[1] | 0x4b000000))) - 8388608.0) * channelScale;
  *(float *)(pixel + 0xc) = (GH_U2F((unsigned int)((*src | 0x4b000000))) - 8388608.0) * channelScale;
  *(float *)(pixel + 0x10) = (GH_U2F((unsigned int)((src[3] | 0x4b000000))) - 8388608.0) * channelScale;
  return;
}

/* _gleExtractPixel_BGRA_EXT_Short @ 0xe2e64 (172 bytes) */
void _gleExtractPixel_BGRA_EXT_Short(pixel, src)
  int pixel;
  short *src;
{
  double intToDoubleBias;
  float channelScale;
  
  channelScale = FLOAT_00108e9c;
  intToDoubleBias = DOUBLE_00108d58;
  *(float *)(pixel + 4) =
       (float)((double)CONCAT44(0x43300000,(int)src[2] ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e9c;
  *(float *)(pixel + 8) =
       (float)((double)CONCAT44(0x43300000,(int)src[1] ^ 0x80000000) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 0xc) =
       (float)((double)CONCAT44(0x43300000,(int)*src ^ 0x80000000) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 0x10) =
       (float)((double)CONCAT44(0x43300000,(int)src[3] ^ 0x80000000) - intToDoubleBias) * channelScale;
  return;
}

/* _gleExtractPixel_BGRA_EXT_Ushort @ 0xe2f10 (172 bytes) */
void _gleExtractPixel_BGRA_EXT_Ushort(pixel, src)
  int pixel;
  ushort *src;
{
  float channelScale;
  
  channelScale = FLOAT_00108e74;
  *(float *)(pixel + 4) = (GH_U2F((unsigned int)((src[2] | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(float *)(pixel + 8) = (GH_U2F((unsigned int)((src[1] | 0x4b000000))) - 8388608.0) * channelScale;
  *(float *)(pixel + 0xc) = (GH_U2F((unsigned int)((*src | 0x4b000000))) - 8388608.0) * channelScale;
  *(float *)(pixel + 0x10) = (GH_U2F((unsigned int)((src[3] | 0x4b000000))) - 8388608.0) * channelScale;
  return;
}

/* _gleExtractPixel_BGRA_EXT_Int @ 0xe2fbc (188 bytes) */
void _gleExtractPixel_BGRA_EXT_Int(pixel, src)
  int pixel;
  uint *src;
{
  double intToDoubleBias;
  double channelScale;
  
  channelScale = DOUBLE_00108d88;
  intToDoubleBias = DOUBLE_00108d58;
  *(float *)(pixel + 4) =
       (float)((double)(float)((double)CONCAT44(0x43300000,src[2] ^ 0x80000000) -
                              DOUBLE_00108d58) * DOUBLE_00108d88);
  *(float *)(pixel + 8) =
       (float)((double)(float)((double)CONCAT44(0x43300000,src[1] ^ 0x80000000) - intToDoubleBias) * channelScale
              );
  *(float *)(pixel + 0xc) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*src ^ 0x80000000) - intToDoubleBias) * channelScale);
  *(float *)(pixel + 0x10) =
       (float)((double)(float)((double)CONCAT44(0x43300000,src[3] ^ 0x80000000) - intToDoubleBias) * channelScale
              );
  return;
}

/* _gleExtractPixel_BGRA_EXT_Uint @ 0xe3078 (172 bytes) */
void _gleExtractPixel_BGRA_EXT_Uint(pixel, src)
  int pixel;
  undefined4 *src;
{
  double intToDoubleBias;
  double channelScale;
  
  channelScale = DOUBLE_00108da0;
  intToDoubleBias = DOUBLE_00108d70;
  *(float *)(pixel + 4) =
       (float)((double)(float)((double)CONCAT44(0x43300000,src[2]) - DOUBLE_00108d70) *
              DOUBLE_00108da0);
  *(float *)(pixel + 8) =
       (float)((double)(float)((double)CONCAT44(0x43300000,src[1]) - intToDoubleBias) * channelScale);
  *(float *)(pixel + 0xc) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*src) - intToDoubleBias) * channelScale);
  *(float *)(pixel + 0x10) =
       (float)((double)(float)((double)CONCAT44(0x43300000,src[3]) - intToDoubleBias) * channelScale);
  return;
}

/* _gleExtractPixel_BGRA_EXT_Float @ 0xe3124 (36 bytes) */
void _gleExtractPixel_BGRA_EXT_Float(pixel, src)
  int pixel;
  undefined4 *src;
{
  *(undefined4 *)(pixel + 4) = src[2];
  *(undefined4 *)(pixel + 8) = src[1];
  *(undefined4 *)(pixel + 0xc) = *src;
  *(undefined4 *)(pixel + 0x10) = src[3];
  return;
}

/* _gleExtractPixel_BGRA_4444 @ 0xe3148 (188 bytes) */
void _gleExtractPixel_BGRA_4444(pixel, src)
  int pixel;
  ushort *src;
{
  double intToDoubleBias;
  float channelScale;
  
  channelScale = FLOAT_00108f58;
  intToDoubleBias = DOUBLE_00108d58;
  *(float *)(pixel + 0xc) =
       (float)((double)CONCAT44(0x43300000,*src >> 0xc ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108f58;
  *(float *)(pixel + 8) =
       (float)((double)CONCAT44(0x43300000,*src >> 8 & 0xf ^ 0x80000000) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 4) =
       (float)((double)CONCAT44(0x43300000,*src >> 4 & 0xf ^ 0x80000000) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 0x10) =
       (float)((double)CONCAT44(0x43300000,*src & 0xf ^ 0x80000000) - intToDoubleBias) * channelScale;
  return;
}

/* _gleExtractPixel_BGRA_4444Rev @ 0xe3204 (188 bytes) */
void _gleExtractPixel_BGRA_4444Rev(pixel, src)
  int pixel;
  ushort *src;
{
  double intToDoubleBias;
  float channelScale;
  
  channelScale = FLOAT_00108f58;
  intToDoubleBias = DOUBLE_00108d58;
  *(float *)(pixel + 0x10) =
       (float)((double)CONCAT44(0x43300000,*src >> 0xc ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108f58;
  *(float *)(pixel + 4) =
       (float)((double)CONCAT44(0x43300000,*src >> 8 & 0xf ^ 0x80000000) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 8) =
       (float)((double)CONCAT44(0x43300000,*src >> 4 & 0xf ^ 0x80000000) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 0xc) =
       (float)((double)CONCAT44(0x43300000,*src & 0xf ^ 0x80000000) - intToDoubleBias) * channelScale;
  return;
}

/* _gleExtractPixel_BGRA_5551 @ 0xe32c0 (184 bytes) */
void _gleExtractPixel_BGRA_5551(pixel, src)
  int pixel;
  ushort *src;
{
  double intToDoubleBias;
  float channelScale;
  
  channelScale = FLOAT_00108f5c;
  intToDoubleBias = DOUBLE_00108d58;
  *(float *)(pixel + 0xc) =
       (float)((double)CONCAT44(0x43300000,*src >> 0xb ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108f5c;
  *(float *)(pixel + 8) =
       (float)((double)CONCAT44(0x43300000,*src >> 6 & 0x1f ^ 0x80000000) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 4) =
       (float)((double)CONCAT44(0x43300000,*src >> 1 & 0x1f ^ 0x80000000) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 0x10) =
       (float)((double)CONCAT44(0x43300000,*src & 1 ^ 0x80000000) - intToDoubleBias);
  return;
}

/* _gleExtractPixel_BGRA_1555Rev @ 0xe3378 (184 bytes) */
void _gleExtractPixel_BGRA_1555Rev(pixel, src)
  int pixel;
  ushort *src;
{
  double intToDoubleBias;
  float channelScale;
  
  channelScale = FLOAT_00108f5c;
  intToDoubleBias = DOUBLE_00108d58;
  *(float *)(pixel + 0x10) =
       (float)((double)CONCAT44(0x43300000,*src >> 0xf ^ 0x80000000) - DOUBLE_00108d58);
  *(float *)(pixel + 4) =
       (float)((double)CONCAT44(0x43300000,*src >> 10 & 0x1f ^ 0x80000000) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 8) =
       (float)((double)CONCAT44(0x43300000,*src >> 5 & 0x1f ^ 0x80000000) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 0xc) =
       (float)((double)CONCAT44(0x43300000,*src & 0x1f ^ 0x80000000) - intToDoubleBias) * channelScale;
  return;
}

/* _gleExtractPixel_BGRA_8888 @ 0xe3430 (156 bytes) */
void _gleExtractPixel_BGRA_8888(pixel, src)
  int pixel;
  byte *src;
{
  double intToDoubleBias;
  float channelScale;
  
  channelScale = FLOAT_00108e64;
  intToDoubleBias = DOUBLE_00108d70;
  *(float *)(pixel + 0xc) =
       (float)((double)CONCAT44(0x43300000,(uint)*src) - DOUBLE_00108d70) * FLOAT_00108e64;
  *(float *)(pixel + 8) = (float)((double)CONCAT44(0x43300000,(uint)src[1]) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 4) = (float)((double)CONCAT44(0x43300000,(uint)src[2]) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 0x10) =
       (float)((double)CONCAT44(0x43300000,(uint)src[3]) - intToDoubleBias) * channelScale;
  return;
}

/* _gleExtractPixel_BGRA_8888Rev @ 0xe34cc (156 bytes) */
void _gleExtractPixel_BGRA_8888Rev(pixel, src)
  int pixel;
  byte *src;
{
  double intToDoubleBias;
  float channelScale;
  
  channelScale = FLOAT_00108e64;
  intToDoubleBias = DOUBLE_00108d70;
  *(float *)(pixel + 0x10) =
       (float)((double)CONCAT44(0x43300000,(uint)*src) - DOUBLE_00108d70) * FLOAT_00108e64;
  *(float *)(pixel + 4) = (float)((double)CONCAT44(0x43300000,(uint)src[1]) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 8) = (float)((double)CONCAT44(0x43300000,(uint)src[2]) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 0xc) = (float)((double)CONCAT44(0x43300000,(uint)src[3]) - intToDoubleBias) * channelScale
  ;
  return;
}

/* _gleExtractPixel_BGRA_1010102 @ 0xe3568 (180 bytes) */
void _gleExtractPixel_BGRA_1010102(pixel, src)
  int pixel;
  uint *src;
{
  double intToDoubleBias;
  float channelScale;
  
  channelScale = FLOAT_00108f60;
  intToDoubleBias = DOUBLE_00108d70;
  *(float *)(pixel + 0xc) =
       (float)((double)CONCAT44(0x43300000,*src >> 0x16) - DOUBLE_00108d70) * FLOAT_00108f60;
  *(float *)(pixel + 8) =
       (float)((double)CONCAT44(0x43300000,*src >> 0xc & 0x3ff) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 4) =
       (float)((double)CONCAT44(0x43300000,*src >> 2 & 0x3ff) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 0x10) =
       (float)((double)CONCAT44(0x43300000,*src & 3) - intToDoubleBias) * FLOAT_00108eb8;
  return;
}

/* _gleExtractPixel_BGRA_2101010Rev @ 0xe361c (180 bytes) */
void _gleExtractPixel_BGRA_2101010Rev(pixel, src)
  int pixel;
  uint *src;
{
  double intToDoubleBias;
  float channelScale;
  
  channelScale = FLOAT_00108f60;
  intToDoubleBias = DOUBLE_00108d70;
  *(float *)(pixel + 0x10) =
       (float)((double)CONCAT44(0x43300000,*src >> 0x1e) - DOUBLE_00108d70) * FLOAT_00108eb8;
  *(float *)(pixel + 4) =
       (float)((double)CONCAT44(0x43300000,*src >> 0x14 & 0x3ff) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 8) =
       (float)((double)CONCAT44(0x43300000,*src >> 10 & 0x3ff) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 0xc) = (float)((double)CONCAT44(0x43300000,*src & 0x3ff) - intToDoubleBias) * channelScale
  ;
  return;
}

/* _gleExtractPixel_BGR_EXT_Byte @ 0xe36d0 (152 bytes) */
void _gleExtractPixel_BGR_EXT_Byte(pixel, src)
  int pixel;
  char *src;
{
  double intToDoubleBias;
  float channelScale;
  
  channelScale = FLOAT_00108e98;
  intToDoubleBias = DOUBLE_00108d58;
  *(float *)(pixel + 4) =
       (float)((double)CONCAT44(0x43300000,(int)src[2] ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e98;
  *(float *)(pixel + 8) =
       (float)((double)CONCAT44(0x43300000,(int)src[1] ^ 0x80000000) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 0xc) =
       (float)((double)CONCAT44(0x43300000,(int)*src ^ 0x80000000) - intToDoubleBias) * channelScale;
  return;
}

/* _gleExtractPixel_BGR_EXT_Ubyte @ 0xe3768 (136 bytes) */
void _gleExtractPixel_BGR_EXT_Ubyte(pixel, src)
  int pixel;
  byte *src;
{
  float channelScale;
  
  channelScale = FLOAT_00108e78;
  *(float *)(pixel + 4) = (GH_U2F((unsigned int)((src[2] | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  *(float *)(pixel + 8) = (GH_U2F((unsigned int)((src[1] | 0x4b000000))) - 8388608.0) * channelScale;
  *(float *)(pixel + 0xc) = (GH_U2F((unsigned int)((*src | 0x4b000000))) - 8388608.0) * channelScale;
  return;
}

/* _gleExtractPixel_BGR_EXT_Short @ 0xe37f0 (140 bytes) */
void _gleExtractPixel_BGR_EXT_Short(pixel, src)
  int pixel;
  short *src;
{
  double intToDoubleBias;
  float channelScale;
  
  channelScale = FLOAT_00108e9c;
  intToDoubleBias = DOUBLE_00108d58;
  *(float *)(pixel + 4) =
       (float)((double)CONCAT44(0x43300000,(int)src[2] ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e9c;
  *(float *)(pixel + 8) =
       (float)((double)CONCAT44(0x43300000,(int)src[1] ^ 0x80000000) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 0xc) =
       (float)((double)CONCAT44(0x43300000,(int)*src ^ 0x80000000) - intToDoubleBias) * channelScale;
  return;
}

/* _gleExtractPixel_BGR_EXT_Ushort @ 0xe387c (136 bytes) */
void _gleExtractPixel_BGR_EXT_Ushort(pixel, src)
  int pixel;
  ushort *src;
{
  float channelScale;
  
  channelScale = FLOAT_00108e74;
  *(float *)(pixel + 4) = (GH_U2F((unsigned int)((src[2] | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(float *)(pixel + 8) = (GH_U2F((unsigned int)((src[1] | 0x4b000000))) - 8388608.0) * channelScale;
  *(float *)(pixel + 0xc) = (GH_U2F((unsigned int)((*src | 0x4b000000))) - 8388608.0) * channelScale;
  return;
}

/* _gleExtractPixel_BGR_EXT_Int @ 0xe3904 (152 bytes) */
void _gleExtractPixel_BGR_EXT_Int(pixel, src)
  int pixel;
  uint *src;
{
  double intToDoubleBias;
  double channelScale;
  
  channelScale = DOUBLE_00108d88;
  intToDoubleBias = DOUBLE_00108d58;
  *(float *)(pixel + 4) =
       (float)((double)(float)((double)CONCAT44(0x43300000,src[2] ^ 0x80000000) -
                              DOUBLE_00108d58) * DOUBLE_00108d88);
  *(float *)(pixel + 8) =
       (float)((double)(float)((double)CONCAT44(0x43300000,src[1] ^ 0x80000000) - intToDoubleBias) * channelScale
              );
  *(float *)(pixel + 0xc) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*src ^ 0x80000000) - intToDoubleBias) * channelScale);
  return;
}

/* _gleExtractPixel_BGR_EXT_Uint @ 0xe399c (140 bytes) */
void _gleExtractPixel_BGR_EXT_Uint(pixel, src)
  int pixel;
  undefined4 *src;
{
  double intToDoubleBias;
  double channelScale;
  
  channelScale = DOUBLE_00108da0;
  intToDoubleBias = DOUBLE_00108d70;
  *(float *)(pixel + 4) =
       (float)((double)(float)((double)CONCAT44(0x43300000,src[2]) - DOUBLE_00108d70) *
              DOUBLE_00108da0);
  *(float *)(pixel + 8) =
       (float)((double)(float)((double)CONCAT44(0x43300000,src[1]) - intToDoubleBias) * channelScale);
  *(float *)(pixel + 0xc) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*src) - intToDoubleBias) * channelScale);
  return;
}

/* _gleExtractPixel_BGR_EXT_Float @ 0xe3a28 (28 bytes) */
void _gleExtractPixel_BGR_EXT_Float(pixel, src)
  int pixel;
  undefined4 *src;
{
  *(undefined4 *)(pixel + 4) = src[2];
  *(undefined4 *)(pixel + 8) = src[1];
  *(undefined4 *)(pixel + 0xc) = *src;
  return;
}

/* _gleExtractPixel_RGB_Byte @ 0xe3a44 (152 bytes) */
void _gleExtractPixel_RGB_Byte(pixel, src)
  int pixel;
  char *src;
{
  double intToDoubleBias;
  float channelScale;
  
  channelScale = FLOAT_00108e98;
  intToDoubleBias = DOUBLE_00108d58;
  *(float *)(pixel + 4) =
       (float)((double)CONCAT44(0x43300000,(int)*src ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e98;
  *(float *)(pixel + 8) =
       (float)((double)CONCAT44(0x43300000,(int)src[1] ^ 0x80000000) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 0xc) =
       (float)((double)CONCAT44(0x43300000,(int)src[2] ^ 0x80000000) - intToDoubleBias) * channelScale;
  return;
}

/* _gleExtractPixel_RGB_Ubyte @ 0xe3adc (140 bytes) */
void _gleExtractPixel_RGB_Ubyte(pixel, src)
  int pixel;
  byte *src;
{
  float channelScale;
  
  channelScale = FLOAT_00108e78;
  *(float *)(pixel + 4) = (GH_U2F((unsigned int)((*src | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  *(float *)(pixel + 8) = (GH_U2F((unsigned int)((src[1] | 0x4b000000))) - 8388608.0) * channelScale;
  *(float *)(pixel + 0xc) = (GH_U2F((unsigned int)((src[2] | 0x4b000000))) - 8388608.0) * channelScale;
  return;
}

/* _gleExtractPixel_RGB_Short @ 0xe3b68 (140 bytes) */
void _gleExtractPixel_RGB_Short(pixel, src)
  int pixel;
  short *src;
{
  double intToDoubleBias;
  float channelScale;
  
  channelScale = FLOAT_00108e9c;
  intToDoubleBias = DOUBLE_00108d58;
  *(float *)(pixel + 4) =
       (float)((double)CONCAT44(0x43300000,(int)*src ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e9c;
  *(float *)(pixel + 8) =
       (float)((double)CONCAT44(0x43300000,(int)src[1] ^ 0x80000000) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 0xc) =
       (float)((double)CONCAT44(0x43300000,(int)src[2] ^ 0x80000000) - intToDoubleBias) * channelScale;
  return;
}

/* _gleExtractPixel_RGB_Ushort @ 0xe3bf4 (140 bytes) */
void _gleExtractPixel_RGB_Ushort(pixel, src)
  int pixel;
  ushort *src;
{
  float channelScale;
  
  channelScale = FLOAT_00108e74;
  *(float *)(pixel + 4) = (GH_U2F((unsigned int)((*src | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(float *)(pixel + 8) = (GH_U2F((unsigned int)((src[1] | 0x4b000000))) - 8388608.0) * channelScale;
  *(float *)(pixel + 0xc) = (GH_U2F((unsigned int)((src[2] | 0x4b000000))) - 8388608.0) * channelScale;
  return;
}

/* _gleExtractPixel_RGB_Int @ 0xe3c80 (152 bytes) */
void _gleExtractPixel_RGB_Int(pixel, src)
  int pixel;
  uint *src;
{
  double intToDoubleBias;
  double channelScale;
  
  channelScale = DOUBLE_00108d88;
  intToDoubleBias = DOUBLE_00108d58;
  *(float *)(pixel + 4) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*src ^ 0x80000000) - DOUBLE_00108d58)
              * DOUBLE_00108d88);
  *(float *)(pixel + 8) =
       (float)((double)(float)((double)CONCAT44(0x43300000,src[1] ^ 0x80000000) - intToDoubleBias) * channelScale
              );
  *(float *)(pixel + 0xc) =
       (float)((double)(float)((double)CONCAT44(0x43300000,src[2] ^ 0x80000000) - intToDoubleBias) * channelScale
              );
  return;
}

/* _gleExtractPixel_RGB_Uint @ 0xe3d18 (140 bytes) */
void _gleExtractPixel_RGB_Uint(pixel, src)
  int pixel;
  undefined4 *src;
{
  double intToDoubleBias;
  double channelScale;
  
  channelScale = DOUBLE_00108da0;
  intToDoubleBias = DOUBLE_00108d70;
  *(float *)(pixel + 4) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*src) - DOUBLE_00108d70) *
              DOUBLE_00108da0);
  *(float *)(pixel + 8) =
       (float)((double)(float)((double)CONCAT44(0x43300000,src[1]) - intToDoubleBias) * channelScale);
  *(float *)(pixel + 0xc) =
       (float)((double)(float)((double)CONCAT44(0x43300000,src[2]) - intToDoubleBias) * channelScale);
  return;
}

/* _gleExtractPixel_RGB_Float @ 0xe3da4 (28 bytes) */
void _gleExtractPixel_RGB_Float(pixel, src)
  int pixel;
  undefined4 *src;
{
  *(undefined4 *)(pixel + 4) = *src;
  *(undefined4 *)(pixel + 8) = src[1];
  *(undefined4 *)(pixel + 0xc) = src[2];
  return;
}

/* _gleExtractPixel_RGB_332 @ 0xe3dc0 (160 bytes) */
void _gleExtractPixel_RGB_332(pixel, src)
  int pixel;
  byte *src;
{
  double intToDoubleBias;
  float channelScale;
  
  channelScale = FLOAT_00108f64;
  intToDoubleBias = DOUBLE_00108d58;
  *(float *)(pixel + 4) =
       (float)((double)CONCAT44(0x43300000,*src >> 5 ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108f64;
  *(float *)(pixel + 8) =
       (float)((double)CONCAT44(0x43300000,*src >> 2 & 7 ^ 0x80000000) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 0xc) =
       (float)((double)CONCAT44(0x43300000,*src & 3 ^ 0x80000000) - intToDoubleBias) * FLOAT_00108eb8;
  return;
}

/* _gleExtractPixel_RGB_233Rev @ 0xe3e60 (160 bytes) */
void _gleExtractPixel_RGB_233Rev(pixel, src)
  int pixel;
  byte *src;
{
  double intToDoubleBias;
  float channelScale;
  
  channelScale = FLOAT_00108f64;
  intToDoubleBias = DOUBLE_00108d58;
  *(float *)(pixel + 0xc) =
       (float)((double)CONCAT44(0x43300000,*src >> 6 ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108eb8;
  *(float *)(pixel + 8) =
       (float)((double)CONCAT44(0x43300000,*src >> 3 & 7 ^ 0x80000000) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 4) =
       (float)((double)CONCAT44(0x43300000,*src & 7 ^ 0x80000000) - intToDoubleBias) * channelScale;
  return;
}

/* _gleExtractPixel_RGB_565 @ 0xe3f00 (160 bytes) */
void _gleExtractPixel_RGB_565(pixel, src)
  int pixel;
  ushort *src;
{
  double intToDoubleBias;
  float invMax31;
  float invMax63;
  
  invMax63 = FLOAT_00108f68;
  invMax31 = FLOAT_00108f5c;
  intToDoubleBias = DOUBLE_00108d58;
  *(float *)(pixel + 4) =
       (float)((double)CONCAT44(0x43300000,*src >> 0xb ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108f5c;
  *(float *)(pixel + 8) =
       (float)((double)CONCAT44(0x43300000,*src >> 5 & 0x3f ^ 0x80000000) - intToDoubleBias) * invMax63;
  *(float *)(pixel + 0xc) =
       (float)((double)CONCAT44(0x43300000,*src & 0x1f ^ 0x80000000) - intToDoubleBias) * invMax31;
  return;
}

/* _gleExtractPixel_RGB_565Rev @ 0xe3fa0 (160 bytes) */
void _gleExtractPixel_RGB_565Rev(pixel, src)
  int pixel;
  ushort *src;
{
  double intToDoubleBias;
  float invMax31;
  float invMax63;
  
  invMax63 = FLOAT_00108f68;
  invMax31 = FLOAT_00108f5c;
  intToDoubleBias = DOUBLE_00108d58;
  *(float *)(pixel + 0xc) =
       (float)((double)CONCAT44(0x43300000,*src >> 0xb ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108f5c;
  *(float *)(pixel + 8) =
       (float)((double)CONCAT44(0x43300000,*src >> 5 & 0x3f ^ 0x80000000) - intToDoubleBias) * invMax63;
  *(float *)(pixel + 4) =
       (float)((double)CONCAT44(0x43300000,*src & 0x1f ^ 0x80000000) - intToDoubleBias) * invMax31;
  return;
}

/* _gleExtractPixel_R_Byte @ 0xe4040 (80 bytes) */
void _gleExtractPixel_R_Byte(pixel, src)
  int pixel;
  char *src;
{
  *(float *)(pixel + 4) =
       (float)((double)CONCAT44(0x43300000,(int)*src ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e98;
  return;
}

