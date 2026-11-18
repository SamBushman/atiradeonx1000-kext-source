#include "decls.h"

/* _gleExtractPixel_R_Ubyte @ 0xe4090 (68 bytes) */
void _gleExtractPixel_R_Ubyte(pixel, src)
  int pixel;
  byte *src;
{
  *(float *)(pixel + 4) = (GH_U2F((unsigned int)((*src | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  return;
}

/* _gleExtractPixel_R_Short @ 0xe40d4 (76 bytes) */
void _gleExtractPixel_R_Short(pixel, src)
  int pixel;
  short *src;
{
  *(float *)(pixel + 4) =
       (float)((double)CONCAT44(0x43300000,(int)*src ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e9c;
  return;
}

/* _gleExtractPixel_R_Ushort @ 0xe4120 (68 bytes) */
void _gleExtractPixel_R_Ushort(pixel, src)
  int pixel;
  ushort *src;
{
  *(float *)(pixel + 4) = (GH_U2F((unsigned int)((*src | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  return;
}

/* _gleExtractPixel_R_Int @ 0xe4164 (80 bytes) */
void _gleExtractPixel_R_Int(pixel, src)
  int pixel;
  uint *src;
{
  *(float *)(pixel + 4) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*src ^ 0x80000000) - DOUBLE_00108d58)
              * DOUBLE_00108d88);
  return;
}

/* _gleExtractPixel_R_Uint @ 0xe41b4 (76 bytes) */
void _gleExtractPixel_R_Uint(pixel, src)
  int pixel;
  undefined4 *src;
{
  *(float *)(pixel + 4) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*src) - DOUBLE_00108d70) *
              DOUBLE_00108da0);
  return;
}

/* _gleExtractPixel_R_Float @ 0xe4200 (12 bytes) */
void _gleExtractPixel_R_Float(pixel, src)
  int pixel;
  undefined4 *src;
{
  *(undefined4 *)(pixel + 4) = *src;
  return;
}

/* _gleExtractPixel_G_Byte @ 0xe420c (80 bytes) */
void _gleExtractPixel_G_Byte(pixel, src)
  int pixel;
  char *src;
{
  *(float *)(pixel + 8) =
       (float)((double)CONCAT44(0x43300000,(int)*src ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e98;
  return;
}

/* _gleExtractPixel_G_Ubyte @ 0xe425c (68 bytes) */
void _gleExtractPixel_G_Ubyte(pixel, src)
  int pixel;
  byte *src;
{
  *(float *)(pixel + 8) = (GH_U2F((unsigned int)((*src | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  return;
}

/* _gleExtractPixel_G_Short @ 0xe42a0 (76 bytes) */
void _gleExtractPixel_G_Short(pixel, src)
  int pixel;
  short *src;
{
  *(float *)(pixel + 8) =
       (float)((double)CONCAT44(0x43300000,(int)*src ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e9c;
  return;
}

/* _gleExtractPixel_G_Ushort @ 0xe42ec (68 bytes) */
void _gleExtractPixel_G_Ushort(pixel, src)
  int pixel;
  ushort *src;
{
  *(float *)(pixel + 8) = (GH_U2F((unsigned int)((*src | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  return;
}

/* _gleExtractPixel_G_Int @ 0xe4330 (80 bytes) */
void _gleExtractPixel_G_Int(pixel, src)
  int pixel;
  uint *src;
{
  *(float *)(pixel + 8) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*src ^ 0x80000000) - DOUBLE_00108d58)
              * DOUBLE_00108d88);
  return;
}

/* _gleExtractPixel_G_Uint @ 0xe4380 (76 bytes) */
void _gleExtractPixel_G_Uint(pixel, src)
  int pixel;
  undefined4 *src;
{
  *(float *)(pixel + 8) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*src) - DOUBLE_00108d70) *
              DOUBLE_00108da0);
  return;
}

/* _gleExtractPixel_G_Float @ 0xe43cc (12 bytes) */
void _gleExtractPixel_G_Float(pixel, src)
  int pixel;
  undefined4 *src;
{
  *(undefined4 *)(pixel + 8) = *src;
  return;
}

/* _gleExtractPixel_B_Byte @ 0xe43d8 (80 bytes) */
void _gleExtractPixel_B_Byte(pixel, src)
  int pixel;
  char *src;
{
  *(float *)(pixel + 0xc) =
       (float)((double)CONCAT44(0x43300000,(int)*src ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e98;
  return;
}

/* _gleExtractPixel_B_Ubyte @ 0xe4428 (68 bytes) */
void _gleExtractPixel_B_Ubyte(pixel, src)
  int pixel;
  byte *src;
{
  *(float *)(pixel + 0xc) = (GH_U2F((unsigned int)((*src | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  return;
}

/* _gleExtractPixel_B_Short @ 0xe446c (76 bytes) */
void _gleExtractPixel_B_Short(pixel, src)
  int pixel;
  short *src;
{
  *(float *)(pixel + 0xc) =
       (float)((double)CONCAT44(0x43300000,(int)*src ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e9c;
  return;
}

/* _gleExtractPixel_B_Ushort @ 0xe44b8 (68 bytes) */
void _gleExtractPixel_B_Ushort(pixel, src)
  int pixel;
  ushort *src;
{
  *(float *)(pixel + 0xc) = (GH_U2F((unsigned int)((*src | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  return;
}

/* _gleExtractPixel_B_Int @ 0xe44fc (80 bytes) */
void _gleExtractPixel_B_Int(pixel, src)
  int pixel;
  uint *src;
{
  *(float *)(pixel + 0xc) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*src ^ 0x80000000) - DOUBLE_00108d58)
              * DOUBLE_00108d88);
  return;
}

/* _gleExtractPixel_B_Uint @ 0xe454c (76 bytes) */
void _gleExtractPixel_B_Uint(pixel, src)
  int pixel;
  undefined4 *src;
{
  *(float *)(pixel + 0xc) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*src) - DOUBLE_00108d70) *
              DOUBLE_00108da0);
  return;
}

/* _gleExtractPixel_B_Float @ 0xe4598 (12 bytes) */
void _gleExtractPixel_B_Float(pixel, src)
  int pixel;
  undefined4 *src;
{
  *(undefined4 *)(pixel + 0xc) = *src;
  return;
}

/* _gleExtractPixel_A_Byte @ 0xe45a4 (80 bytes) */
void _gleExtractPixel_A_Byte(pixel, src)
  int pixel;
  char *src;
{
  *(float *)(pixel + 0x10) =
       (float)((double)CONCAT44(0x43300000,(int)*src ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e98;
  return;
}

/* _gleExtractPixel_A_Ubyte @ 0xe45f4 (68 bytes) */
void _gleExtractPixel_A_Ubyte(pixel, src)
  int pixel;
  byte *src;
{
  *(float *)(pixel + 0x10) = (GH_U2F((unsigned int)((*src | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  return;
}

/* _gleExtractPixel_A_Short @ 0xe4638 (76 bytes) */
void _gleExtractPixel_A_Short(pixel, src)
  int pixel;
  short *src;
{
  *(float *)(pixel + 0x10) =
       (float)((double)CONCAT44(0x43300000,(int)*src ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e9c;
  return;
}

/* _gleExtractPixel_A_Ushort @ 0xe4684 (68 bytes) */
void _gleExtractPixel_A_Ushort(pixel, src)
  int pixel;
  ushort *src;
{
  *(float *)(pixel + 0x10) = (GH_U2F((unsigned int)((*src | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  return;
}

/* _gleExtractPixel_A_Int @ 0xe46c8 (80 bytes) */
void _gleExtractPixel_A_Int(pixel, src)
  int pixel;
  uint *src;
{
  *(float *)(pixel + 0x10) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*src ^ 0x80000000) - DOUBLE_00108d58)
              * DOUBLE_00108d88);
  return;
}

/* _gleExtractPixel_A_Uint @ 0xe4718 (76 bytes) */
void _gleExtractPixel_A_Uint(pixel, src)
  int pixel;
  undefined4 *src;
{
  *(float *)(pixel + 0x10) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*src) - DOUBLE_00108d70) *
              DOUBLE_00108da0);
  return;
}

/* _gleExtractPixel_A_Float @ 0xe4764 (12 bytes) */
void _gleExtractPixel_A_Float(pixel, src)
  int pixel;
  undefined4 *src;
{
  *(undefined4 *)(pixel + 0x10) = *src;
  return;
}

/* _gleExtractPixel_L_Byte @ 0xe4770 (88 bytes) */
void _gleExtractPixel_L_Byte(pixel, src)
  int pixel;
  char *src;
{
  float luminance;
  
  luminance = (float)((double)CONCAT44(0x43300000,(int)*src ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e98;
  *(float *)(pixel + 0xc) = luminance;
  *(float *)(pixel + 4) = luminance;
  *(float *)(pixel + 8) = luminance;
  return;
}

/* _gleExtractPixel_L_Ubyte @ 0xe47c8 (76 bytes) */
void _gleExtractPixel_L_Ubyte(pixel, src)
  int pixel;
  byte *src;
{
  float luminance;
  
  luminance = (GH_U2F((unsigned int)((*src | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  *(float *)(pixel + 0xc) = luminance;
  *(float *)(pixel + 4) = luminance;
  *(float *)(pixel + 8) = luminance;
  return;
}

/* _gleExtractPixel_L_Short @ 0xe4814 (84 bytes) */
void _gleExtractPixel_L_Short(pixel, src)
  int pixel;
  short *src;
{
  float luminance;
  
  luminance = (float)((double)CONCAT44(0x43300000,(int)*src ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e9c;
  *(float *)(pixel + 0xc) = luminance;
  *(float *)(pixel + 4) = luminance;
  *(float *)(pixel + 8) = luminance;
  return;
}

/* _gleExtractPixel_L_Ushort @ 0xe4868 (76 bytes) */
void _gleExtractPixel_L_Ushort(pixel, src)
  int pixel;
  ushort *src;
{
  float luminance;
  
  luminance = (GH_U2F((unsigned int)((*src | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(float *)(pixel + 0xc) = luminance;
  *(float *)(pixel + 4) = luminance;
  *(float *)(pixel + 8) = luminance;
  return;
}

/* _gleExtractPixel_L_Int @ 0xe48b4 (88 bytes) */
void _gleExtractPixel_L_Int(pixel, src)
  int pixel;
  uint *src;
{
  float luminance;
  
  luminance = (float)((double)(float)((double)CONCAT44(0x43300000,*src ^ 0x80000000) -
                                 DOUBLE_00108d58) * DOUBLE_00108d88);
  *(float *)(pixel + 0xc) = luminance;
  *(float *)(pixel + 4) = luminance;
  *(float *)(pixel + 8) = luminance;
  return;
}

/* _gleExtractPixel_L_Uint @ 0xe490c (84 bytes) */
void _gleExtractPixel_L_Uint(pixel, src)
  int pixel;
  undefined4 *src;
{
  float luminance;
  
  luminance = (float)((double)(float)((double)CONCAT44(0x43300000,*src) - DOUBLE_00108d70) *
                 DOUBLE_00108da0);
  *(float *)(pixel + 0xc) = luminance;
  *(float *)(pixel + 4) = luminance;
  *(float *)(pixel + 8) = luminance;
  return;
}

/* _gleExtractPixel_L_Float @ 0xe4960 (20 bytes) */
void _gleExtractPixel_L_Float(pixel, src)
  int pixel;
  undefined4 *src;
{
  undefined4 luminance;
  
  luminance = *src;
  *(undefined4 *)(pixel + 0xc) = luminance;
  *(undefined4 *)(pixel + 4) = luminance;
  *(undefined4 *)(pixel + 8) = luminance;
  return;
}

/* _gleExtractPixel_LA_Byte @ 0xe4974 (124 bytes) */
void _gleExtractPixel_LA_Byte(pixel, src)
  int pixel;
  char *src;
{
  float luminance;
  double intToDoubleBias;
  float channelScale;
  
  channelScale = FLOAT_00108e98;
  intToDoubleBias = DOUBLE_00108d58;
  luminance = (float)((double)CONCAT44(0x43300000,(int)*src ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e98;
  *(float *)(pixel + 0xc) = luminance;
  *(float *)(pixel + 4) = luminance;
  *(float *)(pixel + 8) = luminance;
  *(float *)(pixel + 0x10) =
       (float)((double)CONCAT44(0x43300000,(int)src[1] ^ 0x80000000) - intToDoubleBias) * channelScale;
  return;
}

/* _gleExtractPixel_LA_Ubyte @ 0xe49f0 (112 bytes) */
void _gleExtractPixel_LA_Ubyte(pixel, src)
  int pixel;
  byte *src;
{
  float luminance;
  float channelScale;
  
  channelScale = FLOAT_00108e78;
  luminance = (GH_U2F((unsigned int)((*src | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  *(float *)(pixel + 0xc) = luminance;
  *(float *)(pixel + 4) = luminance;
  *(float *)(pixel + 8) = luminance;
  *(float *)(pixel + 0x10) = (GH_U2F((unsigned int)((src[1] | 0x4b000000))) - 8388608.0) * channelScale;
  return;
}

/* _gleExtractPixel_LA_Short @ 0xe4a60 (116 bytes) */
void _gleExtractPixel_LA_Short(pixel, src)
  int pixel;
  short *src;
{
  float luminance;
  double intToDoubleBias;
  float channelScale;
  
  channelScale = FLOAT_00108e9c;
  intToDoubleBias = DOUBLE_00108d58;
  luminance = (float)((double)CONCAT44(0x43300000,(int)*src ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e9c;
  *(float *)(pixel + 0xc) = luminance;
  *(float *)(pixel + 4) = luminance;
  *(float *)(pixel + 8) = luminance;
  *(float *)(pixel + 0x10) =
       (float)((double)CONCAT44(0x43300000,(int)src[1] ^ 0x80000000) - intToDoubleBias) * channelScale;
  return;
}

/* _gleExtractPixel_LA_Ushort @ 0xe4ad4 (112 bytes) */
void _gleExtractPixel_LA_Ushort(pixel, src)
  int pixel;
  ushort *src;
{
  float luminance;
  float channelScale;
  
  channelScale = FLOAT_00108e74;
  luminance = (GH_U2F((unsigned int)((*src | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(float *)(pixel + 0xc) = luminance;
  *(float *)(pixel + 4) = luminance;
  *(float *)(pixel + 8) = luminance;
  *(float *)(pixel + 0x10) = (GH_U2F((unsigned int)((src[1] | 0x4b000000))) - 8388608.0) * channelScale;
  return;
}

/* _gleExtractPixel_LA_Int @ 0xe4b44 (124 bytes) */
void _gleExtractPixel_LA_Int(pixel, src)
  int pixel;
  uint *src;
{
  float luminance;
  double intToDoubleBias;
  double channelScale;
  
  channelScale = DOUBLE_00108d88;
  intToDoubleBias = DOUBLE_00108d58;
  luminance = (float)((double)(float)((double)CONCAT44(0x43300000,*src ^ 0x80000000) -
                                 DOUBLE_00108d58) * DOUBLE_00108d88);
  *(float *)(pixel + 0xc) = luminance;
  *(float *)(pixel + 4) = luminance;
  *(float *)(pixel + 8) = luminance;
  *(float *)(pixel + 0x10) =
       (float)((double)(float)((double)CONCAT44(0x43300000,src[1] ^ 0x80000000) - intToDoubleBias) * channelScale
              );
  return;
}

/* _gleExtractPixel_LA_Uint @ 0xe4bc0 (116 bytes) */
void _gleExtractPixel_LA_Uint(pixel, src)
  int pixel;
  undefined4 *src;
{
  float luminance;
  double intToDoubleBias;
  double channelScale;
  
  channelScale = DOUBLE_00108da0;
  intToDoubleBias = DOUBLE_00108d70;
  luminance = (float)((double)(float)((double)CONCAT44(0x43300000,*src) - DOUBLE_00108d70) *
                 DOUBLE_00108da0);
  *(float *)(pixel + 0xc) = luminance;
  *(float *)(pixel + 4) = luminance;
  *(float *)(pixel + 8) = luminance;
  *(float *)(pixel + 0x10) =
       (float)((double)(float)((double)CONCAT44(0x43300000,src[1]) - intToDoubleBias) * channelScale);
  return;
}

/* _gleExtractPixel_LA_Float @ 0xe4c34 (28 bytes) */
void _gleExtractPixel_LA_Float(pixel, src)
  int pixel;
  undefined4 *src;
{
  undefined4 luminance;
  
  luminance = *src;
  *(undefined4 *)(pixel + 0xc) = luminance;
  *(undefined4 *)(pixel + 4) = luminance;
  *(undefined4 *)(pixel + 8) = luminance;
  *(undefined4 *)(pixel + 0x10) = src[1];
  return;
}

/* _gleExtractPixel_Index_Byte @ 0xe4c50 (24 bytes) */
void _gleExtractPixel_Index_Byte(pixel, src)
  int pixel;
  char *src;
{
  char index;
  
  index = *src;
  *(undefined4 *)(pixel + 0x1c) = 0;
  *(int *)(pixel + 0x18) = (int)index;
  return;
}

/* _gleExtractPixel_Index_Ubyte @ 0xe4c68 (20 bytes) */
void _gleExtractPixel_Index_Ubyte(pixel, src)
  int pixel;
  byte *src;
{
  byte index;
  
  index = *src;
  *(undefined4 *)(pixel + 0x1c) = 0;
  *(uint *)(pixel + 0x18) = (uint)index;
  return;
}

/* _gleExtractPixel_Index_Short @ 0xe4c7c (20 bytes) */
void _gleExtractPixel_Index_Short(pixel, src)
  int pixel;
  short *src;
{
  short index;
  
  index = *src;
  *(undefined4 *)(pixel + 0x1c) = 0;
  *(int *)(pixel + 0x18) = (int)index;
  return;
}

/* _gleExtractPixel_Index_Ushort @ 0xe4c90 (20 bytes) */
void _gleExtractPixel_Index_Ushort(pixel, src)
  int pixel;
  ushort *src;
{
  ushort index;
  
  index = *src;
  *(undefined4 *)(pixel + 0x1c) = 0;
  *(uint *)(pixel + 0x18) = (uint)index;
  return;
}

/* _gleExtractPixel_Index_Int @ 0xe4ca4 (20 bytes) */
void _gleExtractPixel_Index_Int(pixel, src)
  int pixel;
  undefined4 *src;
{
  undefined4 index;
  
  index = *src;
  *(undefined4 *)(pixel + 0x1c) = 0;
  *(undefined4 *)(pixel + 0x18) = index;
  return;
}

/* _gleExtractPixel_Index_Uint @ 0xe4cb8 (20 bytes) */
void _gleExtractPixel_Index_Uint(pixel, src)
  int pixel;
  undefined4 *src;
{
  undefined4 index;
  
  index = *src;
  *(undefined4 *)(pixel + 0x1c) = 0;
  *(undefined4 *)(pixel + 0x18) = index;
  return;
}

/* _gleExtractPixel_Index_Float @ 0xe4ccc (128 bytes) */
void _gleExtractPixel_Index_Float(pixel, src)
  int pixel;
  float *src;
{
  float index;
  undefined4 indexFraction;
  
  index = *src;
  if (!(FLOAT_00108e50 <= index)) {
    index = index - FLOAT_00108f50;
  }
  *(int *)(pixel + 0x18) = (int)index;
  indexFraction = ((int (*)())_gleGetFrac)((double)*src);
  *(undefined4 *)(pixel + 0x1c) = indexFraction;
  return;
}

/* _gleExtractPixel_Depth_Byte @ 0xe4d4c (80 bytes) */
void _gleExtractPixel_Depth_Byte(pixel, src)
  int pixel;
  char *src;
{
  *(float *)(pixel + 0x14) =
       (float)((double)CONCAT44(0x43300000,(int)*src ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e98;
  return;
}

/* _gleExtractPixel_Depth_Ubyte @ 0xe4d9c (68 bytes) */
void _gleExtractPixel_Depth_Ubyte(pixel, src)
  int pixel;
  byte *src;
{
  *(float *)(pixel + 0x14) = (GH_U2F((unsigned int)((*src | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  return;
}

/* _gleExtractPixel_Depth_Short @ 0xe4de0 (76 bytes) */
void _gleExtractPixel_Depth_Short(pixel, src)
  int pixel;
  short *src;
{
  *(float *)(pixel + 0x14) =
       (float)((double)CONCAT44(0x43300000,(int)*src ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e9c;
  return;
}

/* _gleExtractPixel_Depth_Ushort @ 0xe4e2c (68 bytes) */
void _gleExtractPixel_Depth_Ushort(pixel, src)
  int pixel;
  ushort *src;
{
  *(float *)(pixel + 0x14) = (GH_U2F((unsigned int)((*src | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  return;
}

/* _gleExtractPixel_Depth_Int @ 0xe4e70 (80 bytes) */
void _gleExtractPixel_Depth_Int(pixel, src)
  int pixel;
  uint *src;
{
  *(float *)(pixel + 0x14) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*src ^ 0x80000000) - DOUBLE_00108d58)
              * DOUBLE_00108d88);
  return;
}

/* _gleExtractPixel_Depth_Uint @ 0xe4ec0 (76 bytes) */
void _gleExtractPixel_Depth_Uint(pixel, src)
  int pixel;
  undefined4 *src;
{
  *(float *)(pixel + 0x14) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*src) - DOUBLE_00108d70) *
              DOUBLE_00108da0);
  return;
}

/* _gleExtractPixel_Depth_Float @ 0xe4f0c (12 bytes) */
void _gleExtractPixel_Depth_Float(pixel, src)
  int pixel;
  undefined4 *src;
{
  *(undefined4 *)(pixel + 0x14) = *src;
  return;
}

/* _gleExtractPixel_HILO_Byte @ 0xe4f18 (116 bytes) */
void _gleExtractPixel_HILO_Byte(pixel, src)
  int pixel;
  char *src;
{
  double intToDoubleBias;
  float channelScale;
  
  channelScale = FLOAT_00108e98;
  intToDoubleBias = DOUBLE_00108d58;
  *(float *)(pixel + 0x20) =
       (float)((double)CONCAT44(0x43300000,(int)*src ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e98;
  *(float *)(pixel + 0x24) =
       (float)((double)CONCAT44(0x43300000,(int)src[1] ^ 0x80000000) - intToDoubleBias) * channelScale;
  return;
}

/* _gleExtractPixel_HILO_Ubyte @ 0xe4f8c (104 bytes) */
void _gleExtractPixel_HILO_Ubyte(pixel, src)
  int pixel;
  byte *src;
{
  float channelScale;
  
  channelScale = FLOAT_00108e78;
  *(float *)(pixel + 0x20) = (GH_U2F((unsigned int)((*src | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  *(float *)(pixel + 0x24) = (GH_U2F((unsigned int)((src[1] | 0x4b000000))) - 8388608.0) * channelScale;
  return;
}

/* _gleExtractPixel_HILO_Short @ 0xe4ff4 (108 bytes) */
void _gleExtractPixel_HILO_Short(pixel, src)
  int pixel;
  short *src;
{
  double intToDoubleBias;
  float channelScale;
  
  channelScale = FLOAT_00108e9c;
  intToDoubleBias = DOUBLE_00108d58;
  *(float *)(pixel + 0x20) =
       (float)((double)CONCAT44(0x43300000,(int)*src ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e9c;
  *(float *)(pixel + 0x24) =
       (float)((double)CONCAT44(0x43300000,(int)src[1] ^ 0x80000000) - intToDoubleBias) * channelScale;
  return;
}

/* _gleExtractPixel_HILO_Ushort @ 0xe5060 (104 bytes) */
void _gleExtractPixel_HILO_Ushort(pixel, src)
  int pixel;
  ushort *src;
{
  float channelScale;
  
  channelScale = FLOAT_00108e74;
  *(float *)(pixel + 0x20) = (GH_U2F((unsigned int)((*src | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(float *)(pixel + 0x24) = (GH_U2F((unsigned int)((src[1] | 0x4b000000))) - 8388608.0) * channelScale;
  return;
}

/* _gleExtractPixel_HILO_Int @ 0xe50c8 (116 bytes) */
void _gleExtractPixel_HILO_Int(pixel, src)
  int pixel;
  uint *src;
{
  double intToDoubleBias;
  double channelScale;
  
  channelScale = DOUBLE_00108d88;
  intToDoubleBias = DOUBLE_00108d58;
  *(float *)(pixel + 0x20) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*src ^ 0x80000000) - DOUBLE_00108d58)
              * DOUBLE_00108d88);
  *(float *)(pixel + 0x24) =
       (float)((double)(float)((double)CONCAT44(0x43300000,src[1] ^ 0x80000000) - intToDoubleBias) * channelScale
              );
  return;
}

