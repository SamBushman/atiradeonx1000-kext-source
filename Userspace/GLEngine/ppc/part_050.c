#include "decls.h"

/* _gleInsertPixel_ABGR_EXT_Ushort @ 0xe89d8 (124 bytes) */
void _gleInsertPixel_ABGR_EXT_Ushort(pixel, dst)
  int pixel;
  undefined2 *dst;
{
  float channelScale;
  
  channelScale = FLOAT_00108ea0;
  dst[3] = (short)(int)(*(float *)(pixel + 4) * FLOAT_00108ea0);
  dst[2] = (short)(int)(*(float *)(pixel + 8) * channelScale);
  dst[1] = (short)(int)(*(float *)(pixel + 0xc) * channelScale);
  *dst = (short)(int)(*(float *)(pixel + 0x10) * channelScale);
  return;
}

/* _gleInsertPixel_ABGR_EXT_Int @ 0xe8a54 (124 bytes) */
void _gleInsertPixel_ABGR_EXT_Int(int param_1,int *param_2,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  double scaledChannel;
  
  scaledChannel = DOUBLE_00108d90;
  param_2[3] = (int)((double)*(float *)(param_1 + 4) * DOUBLE_00108d90);
  param_2[2] = (int)((double)*(float *)(param_1 + 8) * scaledChannel);
  param_2[1] = (int)((double)*(float *)(param_1 + 0xc) * scaledChannel);
  *param_2 = (int)((double)*(float *)(param_1 + 0x10) * scaledChannel);
  return;
}

/* _gleInsertPixel_ABGR_EXT_Uint @ 0xe8ad0 (312 bytes) */
void _gleInsertPixel_ABGR_EXT_Uint(pixel, dst)
  int pixel;
  uint *dst;
{
  uint channelValue;
  double scaledChannel;
  
  scaledChannel = (double)*(float *)(pixel + 4) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= scaledChannel) {
    channelValue = (int)(scaledChannel - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    channelValue = (uint)(int)scaledChannel;
  }
  dst[3] = channelValue;
  scaledChannel = (double)*(float *)(pixel + 8) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= scaledChannel) {
    channelValue = (int)(scaledChannel - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    channelValue = (uint)(int)scaledChannel;
  }
  dst[2] = channelValue;
  scaledChannel = (double)*(float *)(pixel + 0xc) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= scaledChannel) {
    channelValue = (int)(scaledChannel - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    channelValue = (uint)(int)scaledChannel;
  }
  dst[1] = channelValue;
  scaledChannel = (double)*(float *)(pixel + 0x10) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= scaledChannel) {
    channelValue = (int)(scaledChannel - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    channelValue = (uint)(int)scaledChannel;
  }
  *dst = channelValue;
  return;
}

/* _gleInsertPixel_ABGR_EXT_Float @ 0xe8c08 (36 bytes) */
void _gleInsertPixel_ABGR_EXT_Float(pixel, dst)
  int pixel;
  undefined4 *dst;
{
  dst[3] = *(undefined4 *)(pixel + 4);
  dst[2] = *(undefined4 *)(pixel + 8);
  dst[1] = *(undefined4 *)(pixel + 0xc);
  *dst = *(undefined4 *)(pixel + 0x10);
  return;
}

/* _gleInsertPixel_BGRA_EXT_Byte @ 0xe8c2c (124 bytes) */
void _gleInsertPixel_BGRA_EXT_Byte(pixel, dst)
  int pixel;
  undefined1 *dst;
{
  float channelScale;
  
  channelScale = FLOAT_00108f6c;
  dst[2] = (char)(int)(*(float *)(pixel + 4) * FLOAT_00108f6c);
  dst[1] = (char)(int)(*(float *)(pixel + 8) * channelScale);
  *dst = (char)(int)(*(float *)(pixel + 0xc) * channelScale);
  dst[3] = (char)(int)(*(float *)(pixel + 0x10) * channelScale);
  return;
}

/* _gleInsertPixel_BGRA_EXT_Ubyte @ 0xe8ca8 (124 bytes) */
void _gleInsertPixel_BGRA_EXT_Ubyte(pixel, dst)
  int pixel;
  undefined1 *dst;
{
  float channelScale;
  
  channelScale = FLOAT_00108f70;
  dst[2] = (char)(int)(*(float *)(pixel + 4) * FLOAT_00108f70);
  dst[1] = (char)(int)(*(float *)(pixel + 8) * channelScale);
  *dst = (char)(int)(*(float *)(pixel + 0xc) * channelScale);
  dst[3] = (char)(int)(*(float *)(pixel + 0x10) * channelScale);
  return;
}

/* _gleInsertPixel_BGRA_EXT_Short @ 0xe8d24 (124 bytes) */
void _gleInsertPixel_BGRA_EXT_Short(pixel, dst)
  int pixel;
  undefined2 *dst;
{
  float channelScale;
  
  channelScale = FLOAT_00108f74;
  dst[2] = (short)(int)(*(float *)(pixel + 4) * FLOAT_00108f74);
  dst[1] = (short)(int)(*(float *)(pixel + 8) * channelScale);
  *dst = (short)(int)(*(float *)(pixel + 0xc) * channelScale);
  dst[3] = (short)(int)(*(float *)(pixel + 0x10) * channelScale);
  return;
}

/* _gleInsertPixel_BGRA_EXT_Ushort @ 0xe8da0 (124 bytes) */
void _gleInsertPixel_BGRA_EXT_Ushort(pixel, dst)
  int pixel;
  undefined2 *dst;
{
  float channelScale;
  
  channelScale = FLOAT_00108ea0;
  dst[2] = (short)(int)(*(float *)(pixel + 4) * FLOAT_00108ea0);
  dst[1] = (short)(int)(*(float *)(pixel + 8) * channelScale);
  *dst = (short)(int)(*(float *)(pixel + 0xc) * channelScale);
  dst[3] = (short)(int)(*(float *)(pixel + 0x10) * channelScale);
  return;
}

/* _gleInsertPixel_BGRA_EXT_Int @ 0xe8e1c (124 bytes) */
void _gleInsertPixel_BGRA_EXT_Int(int param_1,int *param_2,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  double scaledChannel;
  
  scaledChannel = DOUBLE_00108d90;
  param_2[2] = (int)((double)*(float *)(param_1 + 4) * DOUBLE_00108d90);
  param_2[1] = (int)((double)*(float *)(param_1 + 8) * scaledChannel);
  *param_2 = (int)((double)*(float *)(param_1 + 0xc) * scaledChannel);
  param_2[3] = (int)((double)*(float *)(param_1 + 0x10) * scaledChannel);
  return;
}

/* _gleInsertPixel_BGRA_EXT_Uint @ 0xe8e98 (312 bytes) */
void _gleInsertPixel_BGRA_EXT_Uint(pixel, dst)
  int pixel;
  uint *dst;
{
  uint channelValue;
  double scaledChannel;
  
  scaledChannel = (double)*(float *)(pixel + 4) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= scaledChannel) {
    channelValue = (int)(scaledChannel - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    channelValue = (uint)(int)scaledChannel;
  }
  dst[2] = channelValue;
  scaledChannel = (double)*(float *)(pixel + 8) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= scaledChannel) {
    channelValue = (int)(scaledChannel - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    channelValue = (uint)(int)scaledChannel;
  }
  dst[1] = channelValue;
  scaledChannel = (double)*(float *)(pixel + 0xc) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= scaledChannel) {
    channelValue = (int)(scaledChannel - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    channelValue = (uint)(int)scaledChannel;
  }
  *dst = channelValue;
  scaledChannel = (double)*(float *)(pixel + 0x10) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= scaledChannel) {
    channelValue = (int)(scaledChannel - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    channelValue = (uint)(int)scaledChannel;
  }
  dst[3] = channelValue;
  return;
}

/* _gleInsertPixel_BGRA_EXT_Float @ 0xe8fd0 (36 bytes) */
void _gleInsertPixel_BGRA_EXT_Float(pixel, dst)
  int pixel;
  undefined4 *dst;
{
  dst[2] = *(undefined4 *)(pixel + 4);
  dst[1] = *(undefined4 *)(pixel + 8);
  *dst = *(undefined4 *)(pixel + 0xc);
  dst[3] = *(undefined4 *)(pixel + 0x10);
  return;
}

/* _gleInsertPixel_BGRA_4444 @ 0xe8ff4 (140 bytes) */
void _gleInsertPixel_BGRA_4444(pixel, dst)
  int pixel;
  ushort *dst;
{
  *dst = (ushort)(int)(*(float *)(pixel + 0xc) * FLOAT_00108ea0) & 0xf000 |
             (ushort)((uint)(int)(*(float *)(pixel + 8) * FLOAT_00108ea0) >> 4) & 0xf00 |
             (ushort)((uint)(int)(*(float *)(pixel + 4) * FLOAT_00108ea0) >> 8) & 0xf0 |
             (ushort)((uint)(int)(*(float *)(pixel + 0x10) * FLOAT_00108ea0) >> 0xc) & 0xf;
  return;
}

/* _gleInsertPixel_BGRA_4444Rev @ 0xe9080 (140 bytes) */
void _gleInsertPixel_BGRA_4444Rev(pixel, dst)
  int pixel;
  ushort *dst;
{
  *dst = (ushort)(int)(*(float *)(pixel + 0x10) * FLOAT_00108ea0) & 0xf000 |
             (ushort)((uint)(int)(*(float *)(pixel + 4) * FLOAT_00108ea0) >> 4) & 0xf00 |
             (ushort)((uint)(int)(*(float *)(pixel + 8) * FLOAT_00108ea0) >> 8) & 0xf0 |
             (ushort)((uint)(int)(*(float *)(pixel + 0xc) * FLOAT_00108ea0) >> 0xc) & 0xf;
  return;
}

/* _gleInsertPixel_BGRA_5551 @ 0xe910c (140 bytes) */
void _gleInsertPixel_BGRA_5551(pixel, dst)
  int pixel;
  ushort *dst;
{
  *dst = (ushort)(int)(*(float *)(pixel + 0xc) * FLOAT_00108ea0) & 0xf800 |
             (ushort)((uint)(int)(*(float *)(pixel + 8) * FLOAT_00108ea0) >> 5) & 0x7c0 |
             (ushort)((uint)(int)(*(float *)(pixel + 4) * FLOAT_00108ea0) >> 10) & 0x3e |
             (ushort)((uint)(int)(*(float *)(pixel + 0x10) * FLOAT_00108ea0) >> 0xf) & 1;
  return;
}

/* _gleInsertPixel_BGRA_1555Rev @ 0xe9198 (140 bytes) */
void _gleInsertPixel_BGRA_1555Rev(pixel, dst)
  int pixel;
  ushort *dst;
{
  *dst = (ushort)(int)(*(float *)(pixel + 0x10) * FLOAT_00108ea0) & 0x8000 |
             (ushort)((uint)(int)(*(float *)(pixel + 4) * FLOAT_00108ea0) >> 1) & 0x7c00 |
             (ushort)((uint)(int)(*(float *)(pixel + 8) * FLOAT_00108ea0) >> 6) & 0x3e0 |
             (ushort)((uint)(int)(*(float *)(pixel + 0xc) * FLOAT_00108ea0) >> 0xb) & 0x1f;
  return;
}

/* _gleInsertPixel_BGRA_8888 @ 0xe9224 (124 bytes) */
void _gleInsertPixel_BGRA_8888(pixel, dst)
  int pixel;
  undefined1 *dst;
{
  float channelScale;
  
  channelScale = FLOAT_00108f70;
  *dst = (char)(int)(*(float *)(pixel + 0xc) * FLOAT_00108f70);
  dst[1] = (char)(int)(*(float *)(pixel + 8) * channelScale);
  dst[2] = (char)(int)(*(float *)(pixel + 4) * channelScale);
  dst[3] = (char)(int)(*(float *)(pixel + 0x10) * channelScale);
  return;
}

/* _gleInsertPixel_BGRA_8888Rev @ 0xe92a0 (124 bytes) */
void _gleInsertPixel_BGRA_8888Rev(pixel, dst)
  int pixel;
  undefined1 *dst;
{
  float channelScale;
  
  channelScale = FLOAT_00108f70;
  *dst = (char)(int)(*(float *)(pixel + 0x10) * FLOAT_00108f70);
  dst[1] = (char)(int)(*(float *)(pixel + 4) * channelScale);
  dst[2] = (char)(int)(*(float *)(pixel + 8) * channelScale);
  dst[3] = (char)(int)(*(float *)(pixel + 0xc) * channelScale);
  return;
}

/* _gleInsertPixel_BGRA_1010102 @ 0xe931c (328 bytes) */
void _gleInsertPixel_BGRA_1010102(pixel, dst)
  int pixel;
  uint *dst;
{
  uint blueBits;
  uint greenBits;
  uint redBits;
  uint alphaBits;
  double scaledChannel;
  
  scaledChannel = (double)*(float *)(pixel + 0xc) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= scaledChannel) {
    blueBits = (int)(scaledChannel - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    blueBits = (uint)(int)scaledChannel;
  }
  scaledChannel = (double)*(float *)(pixel + 8) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= scaledChannel) {
    greenBits = (int)(scaledChannel - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    greenBits = (uint)(int)scaledChannel;
  }
  scaledChannel = (double)*(float *)(pixel + 4) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= scaledChannel) {
    redBits = (int)(scaledChannel - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    redBits = (uint)(int)scaledChannel;
  }
  scaledChannel = (double)*(float *)(pixel + 0x10) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= scaledChannel) {
    alphaBits = (int)(scaledChannel - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    alphaBits = (uint)(int)scaledChannel;
  }
  *dst = blueBits & 0xffc00000 | greenBits >> 10 & 0x3ff000 | redBits >> 0x14 & 0xffc | alphaBits >> 0x1e;
  return;
}

/* _gleInsertPixel_BGRA_2101010Rev @ 0xe9464 (328 bytes) */
void _gleInsertPixel_BGRA_2101010Rev(pixel, dst)
  int pixel;
  uint *dst;
{
  uint alphaBits;
  uint redBits;
  uint greenBits;
  uint blueBits;
  double scaledChannel;
  
  scaledChannel = (double)*(float *)(pixel + 0x10) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= scaledChannel) {
    alphaBits = (int)(scaledChannel - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    alphaBits = (uint)(int)scaledChannel;
  }
  scaledChannel = (double)*(float *)(pixel + 4) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= scaledChannel) {
    redBits = (int)(scaledChannel - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    redBits = (uint)(int)scaledChannel;
  }
  scaledChannel = (double)*(float *)(pixel + 8) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= scaledChannel) {
    greenBits = (int)(scaledChannel - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    greenBits = (uint)(int)scaledChannel;
  }
  scaledChannel = (double)*(float *)(pixel + 0xc) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= scaledChannel) {
    blueBits = (int)(scaledChannel - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    blueBits = (uint)(int)scaledChannel;
  }
  *dst = alphaBits & 0xc0000000 | redBits >> 2 & 0x3ff00000 | greenBits >> 0xc & 0xffc00 | blueBits >> 0x16;
  return;
}

/* _gleInsertPixel_BGR_EXT_Byte @ 0xe95ac (100 bytes) */
void _gleInsertPixel_BGR_EXT_Byte(pixel, dst)
  int pixel;
  undefined1 *dst;
{
  float channelScale;
  
  channelScale = FLOAT_00108f6c;
  dst[2] = (char)(int)(*(float *)(pixel + 4) * FLOAT_00108f6c);
  dst[1] = (char)(int)(*(float *)(pixel + 8) * channelScale);
  *dst = (char)(int)(*(float *)(pixel + 0xc) * channelScale);
  return;
}

/* _gleInsertPixel_BGR_EXT_Ubyte @ 0xe9610 (100 bytes) */
void _gleInsertPixel_BGR_EXT_Ubyte(pixel, dst)
  int pixel;
  undefined1 *dst;
{
  float channelScale;
  
  channelScale = FLOAT_00108f70;
  dst[2] = (char)(int)(*(float *)(pixel + 4) * FLOAT_00108f70);
  dst[1] = (char)(int)(*(float *)(pixel + 8) * channelScale);
  *dst = (char)(int)(*(float *)(pixel + 0xc) * channelScale);
  return;
}

/* _gleInsertPixel_BGR_EXT_Short @ 0xe9674 (100 bytes) */
void _gleInsertPixel_BGR_EXT_Short(pixel, dst)
  int pixel;
  undefined2 *dst;
{
  float channelScale;
  
  channelScale = FLOAT_00108f74;
  dst[2] = (short)(int)(*(float *)(pixel + 4) * FLOAT_00108f74);
  dst[1] = (short)(int)(*(float *)(pixel + 8) * channelScale);
  *dst = (short)(int)(*(float *)(pixel + 0xc) * channelScale);
  return;
}

/* _gleInsertPixel_BGR_EXT_Ushort @ 0xe96d8 (100 bytes) */
void _gleInsertPixel_BGR_EXT_Ushort(pixel, dst)
  int pixel;
  undefined2 *dst;
{
  float channelScale;
  
  channelScale = FLOAT_00108ea0;
  dst[2] = (short)(int)(*(float *)(pixel + 4) * FLOAT_00108ea0);
  dst[1] = (short)(int)(*(float *)(pixel + 8) * channelScale);
  *dst = (short)(int)(*(float *)(pixel + 0xc) * channelScale);
  return;
}

/* _gleInsertPixel_BGR_EXT_Int @ 0xe973c (100 bytes) */
void _gleInsertPixel_BGR_EXT_Int(int param_1,int *param_2,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  double scaledChannel;
  
  scaledChannel = DOUBLE_00108d90;
  param_2[2] = (int)((double)*(float *)(param_1 + 4) * DOUBLE_00108d90);
  param_2[1] = (int)((double)*(float *)(param_1 + 8) * scaledChannel);
  *param_2 = (int)((double)*(float *)(param_1 + 0xc) * scaledChannel);
  return;
}

/* _gleInsertPixel_BGR_EXT_Uint @ 0xe97a0 (240 bytes) */
void _gleInsertPixel_BGR_EXT_Uint(pixel, dst)
  int pixel;
  uint *dst;
{
  uint channelValue;
  double scaledChannel;
  
  scaledChannel = (double)*(float *)(pixel + 4) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= scaledChannel) {
    channelValue = (int)(scaledChannel - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    channelValue = (uint)(int)scaledChannel;
  }
  dst[2] = channelValue;
  scaledChannel = (double)*(float *)(pixel + 8) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= scaledChannel) {
    channelValue = (int)(scaledChannel - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    channelValue = (uint)(int)scaledChannel;
  }
  dst[1] = channelValue;
  scaledChannel = (double)*(float *)(pixel + 0xc) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= scaledChannel) {
    channelValue = (int)(scaledChannel - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    channelValue = (uint)(int)scaledChannel;
  }
  *dst = channelValue;
  return;
}

/* _gleInsertPixel_BGR_EXT_Float @ 0xe9890 (28 bytes) */
void _gleInsertPixel_BGR_EXT_Float(pixel, dst)
  int pixel;
  undefined4 *dst;
{
  dst[2] = *(undefined4 *)(pixel + 4);
  dst[1] = *(undefined4 *)(pixel + 8);
  *dst = *(undefined4 *)(pixel + 0xc);
  return;
}

/* _gleInsertPixel_RGB_Byte @ 0xe98ac (100 bytes) */
void _gleInsertPixel_RGB_Byte(pixel, dst)
  int pixel;
  undefined1 *dst;
{
  float channelScale;
  
  channelScale = FLOAT_00108f6c;
  *dst = (char)(int)(*(float *)(pixel + 4) * FLOAT_00108f6c);
  dst[1] = (char)(int)(*(float *)(pixel + 8) * channelScale);
  dst[2] = (char)(int)(*(float *)(pixel + 0xc) * channelScale);
  return;
}

/* _gleInsertPixel_RGB_Ubyte @ 0xe9910 (100 bytes) */
void _gleInsertPixel_RGB_Ubyte(pixel, dst)
  int pixel;
  undefined1 *dst;
{
  float channelScale;
  
  channelScale = FLOAT_00108f70;
  *dst = (char)(int)(*(float *)(pixel + 4) * FLOAT_00108f70);
  dst[1] = (char)(int)(*(float *)(pixel + 8) * channelScale);
  dst[2] = (char)(int)(*(float *)(pixel + 0xc) * channelScale);
  return;
}

/* _gleInsertPixel_RGB_Short @ 0xe9974 (100 bytes) */
void _gleInsertPixel_RGB_Short(pixel, dst)
  int pixel;
  undefined2 *dst;
{
  float channelScale;
  
  channelScale = FLOAT_00108f74;
  *dst = (short)(int)(*(float *)(pixel + 4) * FLOAT_00108f74);
  dst[1] = (short)(int)(*(float *)(pixel + 8) * channelScale);
  dst[2] = (short)(int)(*(float *)(pixel + 0xc) * channelScale);
  return;
}

/* _gleInsertPixel_RGB_Ushort @ 0xe99d8 (100 bytes) */
void _gleInsertPixel_RGB_Ushort(pixel, dst)
  int pixel;
  undefined2 *dst;
{
  float channelScale;
  
  channelScale = FLOAT_00108ea0;
  *dst = (short)(int)(*(float *)(pixel + 4) * FLOAT_00108ea0);
  dst[1] = (short)(int)(*(float *)(pixel + 8) * channelScale);
  dst[2] = (short)(int)(*(float *)(pixel + 0xc) * channelScale);
  return;
}

/* _gleInsertPixel_RGB_Int @ 0xe9a3c (100 bytes) */
void _gleInsertPixel_RGB_Int(int param_1,int *param_2,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  double scaledChannel;
  
  scaledChannel = DOUBLE_00108d90;
  *param_2 = (int)((double)*(float *)(param_1 + 4) * DOUBLE_00108d90);
  param_2[1] = (int)((double)*(float *)(param_1 + 8) * scaledChannel);
  param_2[2] = (int)((double)*(float *)(param_1 + 0xc) * scaledChannel);
  return;
}

/* _gleInsertPixel_RGB_Uint @ 0xe9aa0 (240 bytes) */
void _gleInsertPixel_RGB_Uint(pixel, dst)
  int pixel;
  uint *dst;
{
  uint channelValue;
  double scaledChannel;
  
  scaledChannel = (double)*(float *)(pixel + 4) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= scaledChannel) {
    channelValue = (int)(scaledChannel - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    channelValue = (uint)(int)scaledChannel;
  }
  *dst = channelValue;
  scaledChannel = (double)*(float *)(pixel + 8) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= scaledChannel) {
    channelValue = (int)(scaledChannel - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    channelValue = (uint)(int)scaledChannel;
  }
  dst[1] = channelValue;
  scaledChannel = (double)*(float *)(pixel + 0xc) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= scaledChannel) {
    channelValue = (int)(scaledChannel - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    channelValue = (uint)(int)scaledChannel;
  }
  dst[2] = channelValue;
  return;
}

/* _gleInsertPixel_RGB_Float @ 0xe9b90 (28 bytes) */
void _gleInsertPixel_RGB_Float(pixel, dst)
  int pixel;
  undefined4 *dst;
{
  *dst = *(undefined4 *)(pixel + 4);
  dst[1] = *(undefined4 *)(pixel + 8);
  dst[2] = *(undefined4 *)(pixel + 0xc);
  return;
}

/* _gleInsertPixel_RGB_332 @ 0xe9bac (112 bytes) */
void _gleInsertPixel_RGB_332(pixel, dst)
  int pixel;
  byte *dst;
{
  *dst = (byte)(int)(*(float *)(pixel + 4) * FLOAT_00108f70) & 0xe0 |
             (byte)((uint)(int)(*(float *)(pixel + 8) * FLOAT_00108f70) >> 3) & 0x1c |
             (byte)((uint)(int)(*(float *)(pixel + 0xc) * FLOAT_00108f70) >> 6) & 3;
  return;
}

/* _gleInsertPixel_RGB_233Rev @ 0xe9c1c (112 bytes) */
void _gleInsertPixel_RGB_233Rev(pixel, dst)
  int pixel;
  byte *dst;
{
  *dst = (byte)(int)(*(float *)(pixel + 0xc) * FLOAT_00108f70) & 0xc0 |
             (byte)((uint)(int)(*(float *)(pixel + 8) * FLOAT_00108f70) >> 2) & 0x38 |
             (byte)((uint)(int)(*(float *)(pixel + 4) * FLOAT_00108f70) >> 5) & 7;
  return;
}

/* _gleInsertPixel_RGB_565 @ 0xe9c8c (112 bytes) */
void _gleInsertPixel_RGB_565(pixel, dst)
  int pixel;
  ushort *dst;
{
  *dst = (ushort)(int)(*(float *)(pixel + 4) * FLOAT_00108ea0) & 0xf800 |
             (ushort)((uint)(int)(*(float *)(pixel + 8) * FLOAT_00108ea0) >> 5) & 0x7e0 |
             (ushort)((uint)(int)(*(float *)(pixel + 0xc) * FLOAT_00108ea0) >> 0xb) & 0x1f;
  return;
}

/* _gleInsertPixel_RGB_565Rev @ 0xe9cfc (112 bytes) */
void _gleInsertPixel_RGB_565Rev(pixel, dst)
  int pixel;
  ushort *dst;
{
  *dst = (ushort)(int)(*(float *)(pixel + 0xc) * FLOAT_00108ea0) & 0xf800 |
             (ushort)((uint)(int)(*(float *)(pixel + 8) * FLOAT_00108ea0) >> 5) & 0x7e0 |
             (ushort)((uint)(int)(*(float *)(pixel + 4) * FLOAT_00108ea0) >> 0xb) & 0x1f;
  return;
}

/* _gleInsertPixel_R_Byte @ 0xe9d6c (52 bytes) */
void _gleInsertPixel_R_Byte(pixel, dst)
  int pixel;
  undefined1 *dst;
{
  *dst = (char)(int)(*(float *)(pixel + 4) * FLOAT_00108f6c);
  return;
}

/* _gleInsertPixel_R_Ubyte @ 0xe9da0 (52 bytes) */
void _gleInsertPixel_R_Ubyte(pixel, dst)
  int pixel;
  undefined1 *dst;
{
  *dst = (char)(int)(*(float *)(pixel + 4) * FLOAT_00108f70);
  return;
}

/* _gleInsertPixel_R_Short @ 0xe9dd4 (52 bytes) */
void _gleInsertPixel_R_Short(pixel, dst)
  int pixel;
  undefined2 *dst;
{
  *dst = (short)(int)(*(float *)(pixel + 4) * FLOAT_00108f74);
  return;
}

/* _gleInsertPixel_R_Ushort @ 0xe9e08 (52 bytes) */
void _gleInsertPixel_R_Ushort(pixel, dst)
  int pixel;
  undefined2 *dst;
{
  *dst = (short)(int)(*(float *)(pixel + 4) * FLOAT_00108ea0);
  return;
}

/* _gleInsertPixel_R_Int @ 0xe9e3c (52 bytes) */
void _gleInsertPixel_R_Int(pixel, dst)
  int pixel;
  int *dst;
{
  *dst = (int)((double)*(float *)(pixel + 4) * DOUBLE_00108d90);
  return;
}

/* _gleInsertPixel_R_Uint @ 0xe9e70 (96 bytes) */
void _gleInsertPixel_R_Uint(pixel, dst)
  int pixel;
  uint *dst;
{
  uint channelValue;
  double scaledChannel;
  
  scaledChannel = (double)*(float *)(pixel + 4) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= scaledChannel) {
    channelValue = (int)(scaledChannel - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    channelValue = (uint)(int)scaledChannel;
  }
  *dst = channelValue;
  return;
}

/* _gleInsertPixel_R_Float @ 0xe9ed0 (12 bytes) */
void _gleInsertPixel_R_Float(pixel, dst)
  int pixel;
  undefined4 *dst;
{
  *dst = *(undefined4 *)(pixel + 4);
  return;
}

/* _gleInsertPixel_G_Byte @ 0xe9edc (52 bytes) */
void _gleInsertPixel_G_Byte(pixel, dst)
  int pixel;
  undefined1 *dst;
{
  *dst = (char)(int)(*(float *)(pixel + 8) * FLOAT_00108f6c);
  return;
}

/* _gleInsertPixel_G_Ubyte @ 0xe9f10 (52 bytes) */
void _gleInsertPixel_G_Ubyte(pixel, dst)
  int pixel;
  undefined1 *dst;
{
  *dst = (char)(int)(*(float *)(pixel + 8) * FLOAT_00108f70);
  return;
}

/* _gleInsertPixel_G_Short @ 0xe9f44 (52 bytes) */
void _gleInsertPixel_G_Short(pixel, dst)
  int pixel;
  undefined2 *dst;
{
  *dst = (short)(int)(*(float *)(pixel + 8) * FLOAT_00108f74);
  return;
}

/* _gleInsertPixel_G_Ushort @ 0xe9f78 (52 bytes) */
void _gleInsertPixel_G_Ushort(pixel, dst)
  int pixel;
  undefined2 *dst;
{
  *dst = (short)(int)(*(float *)(pixel + 8) * FLOAT_00108ea0);
  return;
}

/* _gleInsertPixel_G_Int @ 0xe9fac (52 bytes) */
void _gleInsertPixel_G_Int(pixel, dst)
  int pixel;
  int *dst;
{
  *dst = (int)((double)*(float *)(pixel + 8) * DOUBLE_00108d90);
  return;
}

/* _gleInsertPixel_G_Uint @ 0xe9fe0 (96 bytes) */
void _gleInsertPixel_G_Uint(pixel, dst)
  int pixel;
  uint *dst;
{
  uint channelValue;
  double scaledChannel;
  
  scaledChannel = (double)*(float *)(pixel + 8) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= scaledChannel) {
    channelValue = (int)(scaledChannel - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    channelValue = (uint)(int)scaledChannel;
  }
  *dst = channelValue;
  return;
}

/* _gleInsertPixel_G_Float @ 0xea040 (12 bytes) */
void _gleInsertPixel_G_Float(pixel, dst)
  int pixel;
  undefined4 *dst;
{
  *dst = *(undefined4 *)(pixel + 8);
  return;
}

/* _gleInsertPixel_B_Byte @ 0xea04c (52 bytes) */
void _gleInsertPixel_B_Byte(pixel, dst)
  int pixel;
  undefined1 *dst;
{
  *dst = (char)(int)(*(float *)(pixel + 0xc) * FLOAT_00108f6c);
  return;
}

/* _gleInsertPixel_B_Ubyte @ 0xea080 (52 bytes) */
void _gleInsertPixel_B_Ubyte(pixel, dst)
  int pixel;
  undefined1 *dst;
{
  *dst = (char)(int)(*(float *)(pixel + 0xc) * FLOAT_00108f70);
  return;
}

/* _gleInsertPixel_B_Short @ 0xea0b4 (52 bytes) */
void _gleInsertPixel_B_Short(pixel, dst)
  int pixel;
  undefined2 *dst;
{
  *dst = (short)(int)(*(float *)(pixel + 0xc) * FLOAT_00108f74);
  return;
}

/* _gleInsertPixel_B_Ushort @ 0xea0e8 (52 bytes) */
void _gleInsertPixel_B_Ushort(pixel, dst)
  int pixel;
  undefined2 *dst;
{
  *dst = (short)(int)(*(float *)(pixel + 0xc) * FLOAT_00108ea0);
  return;
}

/* _gleInsertPixel_B_Int @ 0xea11c (52 bytes) */
void _gleInsertPixel_B_Int(pixel, dst)
  int pixel;
  int *dst;
{
  *dst = (int)((double)*(float *)(pixel + 0xc) * DOUBLE_00108d90);
  return;
}

/* _gleInsertPixel_B_Uint @ 0xea150 (96 bytes) */
void _gleInsertPixel_B_Uint(pixel, dst)
  int pixel;
  uint *dst;
{
  uint channelValue;
  double scaledChannel;
  
  scaledChannel = (double)*(float *)(pixel + 0xc) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= scaledChannel) {
    channelValue = (int)(scaledChannel - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    channelValue = (uint)(int)scaledChannel;
  }
  *dst = channelValue;
  return;
}

/* _gleInsertPixel_B_Float @ 0xea1b0 (12 bytes) */
void _gleInsertPixel_B_Float(pixel, dst)
  int pixel;
  undefined4 *dst;
{
  *dst = *(undefined4 *)(pixel + 0xc);
  return;
}

/* _gleInsertPixel_A_Byte @ 0xea1bc (52 bytes) */
void _gleInsertPixel_A_Byte(pixel, dst)
  int pixel;
  undefined1 *dst;
{
  *dst = (char)(int)(*(float *)(pixel + 0x10) * FLOAT_00108f6c);
  return;
}

/* _gleInsertPixel_A_Ubyte @ 0xea1f0 (52 bytes) */
void _gleInsertPixel_A_Ubyte(pixel, dst)
  int pixel;
  undefined1 *dst;
{
  *dst = (char)(int)(*(float *)(pixel + 0x10) * FLOAT_00108f70);
  return;
}

