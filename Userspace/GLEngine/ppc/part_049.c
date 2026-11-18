#include "decls.h"

/* _gleExtractPixel_HILO_Uint @ 0xe513c (108 bytes) */
void _gleExtractPixel_HILO_Uint(pixel, src)
  int pixel;
  undefined4 *src;
{
  double intToDoubleBias;
  double channelScale;
  
  channelScale = DOUBLE_00108da0;
  intToDoubleBias = DOUBLE_00108d70;
  *(float *)(pixel + 0x20) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*src) - DOUBLE_00108d70) *
              DOUBLE_00108da0);
  *(float *)(pixel + 0x24) =
       (float)((double)(float)((double)CONCAT44(0x43300000,src[1]) - intToDoubleBias) * channelScale);
  return;
}

/* _gleExtractPixel_HILO_Float @ 0xe51a8 (20 bytes) */
void _gleExtractPixel_HILO_Float(pixel, src)
  int pixel;
  undefined4 *src;
{
  *(undefined4 *)(pixel + 0x20) = *src;
  *(undefined4 *)(pixel + 0x24) = src[1];
  return;
}

/* _gleExtractPixel_DSDT_Byte @ 0xe51bc (116 bytes) */
void _gleExtractPixel_DSDT_Byte(pixel, src)
  int pixel;
  char *src;
{
  double intToDoubleBias;
  float channelScale;
  
  channelScale = FLOAT_00108e98;
  intToDoubleBias = DOUBLE_00108d58;
  *(float *)(pixel + 0x28) =
       (float)((double)CONCAT44(0x43300000,(int)*src ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e98;
  *(float *)(pixel + 0x2c) =
       (float)((double)CONCAT44(0x43300000,(int)src[1] ^ 0x80000000) - intToDoubleBias) * channelScale;
  return;
}

/* _gleExtractPixel_DSDT_Ubyte @ 0xe5230 (104 bytes) */
void _gleExtractPixel_DSDT_Ubyte(pixel, src)
  int pixel;
  byte *src;
{
  float channelScale;
  
  channelScale = FLOAT_00108e78;
  *(float *)(pixel + 0x28) = (GH_U2F((unsigned int)((*src | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  *(float *)(pixel + 0x2c) = (GH_U2F((unsigned int)((src[1] | 0x4b000000))) - 8388608.0) * channelScale;
  return;
}

/* _gleExtractPixel_DSDT_Short @ 0xe5298 (108 bytes) */
void _gleExtractPixel_DSDT_Short(pixel, src)
  int pixel;
  short *src;
{
  double intToDoubleBias;
  float channelScale;
  
  channelScale = FLOAT_00108e9c;
  intToDoubleBias = DOUBLE_00108d58;
  *(float *)(pixel + 0x28) =
       (float)((double)CONCAT44(0x43300000,(int)*src ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e9c;
  *(float *)(pixel + 0x2c) =
       (float)((double)CONCAT44(0x43300000,(int)src[1] ^ 0x80000000) - intToDoubleBias) * channelScale;
  return;
}

/* _gleExtractPixel_DSDT_Ushort @ 0xe5304 (104 bytes) */
void _gleExtractPixel_DSDT_Ushort(pixel, src)
  int pixel;
  ushort *src;
{
  float channelScale;
  
  channelScale = FLOAT_00108e74;
  *(float *)(pixel + 0x28) = (GH_U2F((unsigned int)((*src | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(float *)(pixel + 0x2c) = (GH_U2F((unsigned int)((src[1] | 0x4b000000))) - 8388608.0) * channelScale;
  return;
}

/* _gleExtractPixel_DSDT_Int @ 0xe536c (116 bytes) */
void _gleExtractPixel_DSDT_Int(pixel, src)
  int pixel;
  uint *src;
{
  double intToDoubleBias;
  double channelScale;
  
  channelScale = DOUBLE_00108d88;
  intToDoubleBias = DOUBLE_00108d58;
  *(float *)(pixel + 0x28) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*src ^ 0x80000000) - DOUBLE_00108d58)
              * DOUBLE_00108d88);
  *(float *)(pixel + 0x2c) =
       (float)((double)(float)((double)CONCAT44(0x43300000,src[1] ^ 0x80000000) - intToDoubleBias) * channelScale
              );
  return;
}

/* _gleExtractPixel_DSDT_Uint @ 0xe53e0 (108 bytes) */
void _gleExtractPixel_DSDT_Uint(pixel, src)
  int pixel;
  undefined4 *src;
{
  double intToDoubleBias;
  double channelScale;
  
  channelScale = DOUBLE_00108da0;
  intToDoubleBias = DOUBLE_00108d70;
  *(float *)(pixel + 0x28) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*src) - DOUBLE_00108d70) *
              DOUBLE_00108da0);
  *(float *)(pixel + 0x2c) =
       (float)((double)(float)((double)CONCAT44(0x43300000,src[1]) - intToDoubleBias) * channelScale);
  return;
}

/* _gleExtractPixel_DSDT_Float @ 0xe544c (20 bytes) */
void _gleExtractPixel_DSDT_Float(pixel, src)
  int pixel;
  undefined4 *src;
{
  *(undefined4 *)(pixel + 0x28) = *src;
  *(undefined4 *)(pixel + 0x2c) = src[1];
  return;
}

/* _gleExtractPixel_DSDT_MAG_Byte @ 0xe5460 (160 bytes) */
void _gleExtractPixel_DSDT_MAG_Byte(pixel, src)
  int pixel;
  char *src;
{
  char magnitude;
  double intToDoubleBias;
  float channelScale;
  
  channelScale = FLOAT_00108e98;
  intToDoubleBias = DOUBLE_00108d58;
  *(float *)(pixel + 0x28) =
       (float)((double)CONCAT44(0x43300000,(int)*src ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e98;
  *(float *)(pixel + 0x2c) =
       (float)((double)CONCAT44(0x43300000,(int)src[1] ^ 0x80000000) - intToDoubleBias) * channelScale;
  magnitude = src[2];
  *(undefined4 *)(pixel + 4) = 0;
  *(float *)(pixel + 0x30) =
       (float)((double)CONCAT44(0x43300000,(int)magnitude ^ 0x80000000) - intToDoubleBias) * channelScale;
  return;
}

/* _gleExtractPixel_DSDT_MAG_Ubyte @ 0xe5500 (148 bytes) */
void _gleExtractPixel_DSDT_MAG_Ubyte(pixel, src)
  int pixel;
  byte *src;
{
  byte magnitude;
  float channelScale;
  
  channelScale = FLOAT_00108e78;
  *(float *)(pixel + 0x28) = (GH_U2F((unsigned int)((*src | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  *(float *)(pixel + 0x2c) = (GH_U2F((unsigned int)((src[1] | 0x4b000000))) - 8388608.0) * channelScale;
  magnitude = src[2];
  *(undefined4 *)(pixel + 4) = 0;
  *(float *)(pixel + 0x30) = (GH_U2F((unsigned int)((magnitude | 0x4b000000))) - 8388608.0) * channelScale;
  return;
}

/* _gleExtractPixel_DSDT_MAG_Short @ 0xe5594 (148 bytes) */
void _gleExtractPixel_DSDT_MAG_Short(pixel, src)
  int pixel;
  short *src;
{
  short magnitude;
  double intToDoubleBias;
  float channelScale;
  
  channelScale = FLOAT_00108e9c;
  intToDoubleBias = DOUBLE_00108d58;
  *(float *)(pixel + 0x28) =
       (float)((double)CONCAT44(0x43300000,(int)*src ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e9c;
  *(float *)(pixel + 0x2c) =
       (float)((double)CONCAT44(0x43300000,(int)src[1] ^ 0x80000000) - intToDoubleBias) * channelScale;
  magnitude = src[2];
  *(undefined4 *)(pixel + 4) = 0;
  *(float *)(pixel + 0x30) =
       (float)((double)CONCAT44(0x43300000,(int)magnitude ^ 0x80000000) - intToDoubleBias) * channelScale;
  return;
}

/* _gleExtractPixel_DSDT_MAG_Ushort @ 0xe5628 (148 bytes) */
void _gleExtractPixel_DSDT_MAG_Ushort(pixel, src)
  int pixel;
  ushort *src;
{
  ushort magnitude;
  float channelScale;
  
  channelScale = FLOAT_00108e74;
  *(float *)(pixel + 0x28) = (GH_U2F((unsigned int)((*src | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(float *)(pixel + 0x2c) = (GH_U2F((unsigned int)((src[1] | 0x4b000000))) - 8388608.0) * channelScale;
  magnitude = src[2];
  *(undefined4 *)(pixel + 4) = 0;
  *(float *)(pixel + 0x30) = (GH_U2F((unsigned int)((magnitude | 0x4b000000))) - 8388608.0) * channelScale;
  return;
}

/* _gleExtractPixel_DSDT_MAG_Int @ 0xe56bc (160 bytes) */
void _gleExtractPixel_DSDT_MAG_Int(pixel, src)
  int pixel;
  uint *src;
{
  double intToDoubleBias;
  double channelScale;
  uint magnitude;
  
  channelScale = DOUBLE_00108d88;
  intToDoubleBias = DOUBLE_00108d58;
  *(float *)(pixel + 0x28) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*src ^ 0x80000000) - DOUBLE_00108d58)
              * DOUBLE_00108d88);
  *(float *)(pixel + 0x2c) =
       (float)((double)(float)((double)CONCAT44(0x43300000,src[1] ^ 0x80000000) - intToDoubleBias) * channelScale
              );
  magnitude = src[2];
  *(undefined4 *)(pixel + 4) = 0;
  *(float *)(pixel + 0x30) =
       (float)((double)(float)((double)CONCAT44(0x43300000,magnitude ^ 0x80000000) - intToDoubleBias) * channelScale);
  return;
}

/* _gleExtractPixel_DSDT_MAG_Uint @ 0xe575c (148 bytes) */
void _gleExtractPixel_DSDT_MAG_Uint(pixel, src)
  int pixel;
  undefined4 *src;
{
  double intToDoubleBias;
  double channelScale;
  undefined4 magnitude;
  
  channelScale = DOUBLE_00108da0;
  intToDoubleBias = DOUBLE_00108d70;
  *(float *)(pixel + 0x28) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*src) - DOUBLE_00108d70) *
              DOUBLE_00108da0);
  *(float *)(pixel + 0x2c) =
       (float)((double)(float)((double)CONCAT44(0x43300000,src[1]) - intToDoubleBias) * channelScale);
  magnitude = src[2];
  *(undefined4 *)(pixel + 4) = 0;
  *(float *)(pixel + 0x30) =
       (float)((double)(float)((double)CONCAT44(0x43300000,magnitude) - intToDoubleBias) * channelScale);
  return;
}

/* _gleExtractPixel_DSDT_MAG_Float @ 0xe57f0 (36 bytes) */
void _gleExtractPixel_DSDT_MAG_Float(pixel, src)
  int pixel;
  undefined4 *src;
{
  undefined4 magnitude;
  
  *(undefined4 *)(pixel + 0x28) = *src;
  *(undefined4 *)(pixel + 0x2c) = src[1];
  magnitude = src[2];
  *(undefined4 *)(pixel + 4) = 0;
  *(undefined4 *)(pixel + 0x30) = magnitude;
  return;
}

/* _gleExtractPixel_DSDT_MAG_VIB_S8_S8_8_8 @ 0xe5814 (200 bytes) */
void _gleExtractPixel_DSDT_MAG_VIB_S8_S8_8_8(pixel, src)
  int pixel;
  char *src;
{
  double intToDoubleBias;
  float invMax255;
  float invMax127;
  
  invMax127 = FLOAT_00108e98;
  invMax255 = FLOAT_00108e78;
  intToDoubleBias = DOUBLE_00108d58;
  *(float *)(pixel + 0x28) =
       (float)((double)CONCAT44(0x43300000,(int)*src ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e98;
  *(float *)(pixel + 0x2c) =
       (float)((double)CONCAT44(0x43300000,(int)src[1] ^ 0x80000000) - intToDoubleBias) * invMax127;
  *(float *)(pixel + 0x30) = (GH_U2F((unsigned int)(((byte)src[2] | 0x4b000000))) - 8388608.0) * invMax255;
  *(float *)(pixel + 4) = (GH_U2F((unsigned int)(((byte)src[3] | 0x4b000000))) - 8388608.0) * invMax255;
  return;
}

/* _gleExtractPixel_DSDT_MAG_VIB_8_8_S8_S8_Rev @ 0xe58dc (196 bytes) */
void _gleExtractPixel_DSDT_MAG_VIB_8_8_S8_S8_Rev(pixel, src)
  int pixel;
  byte *src;
{
  double intToDoubleBias;
  float invMax255;
  float invMax127;
  
  invMax127 = FLOAT_00108e98;
  invMax255 = FLOAT_00108e78;
  intToDoubleBias = DOUBLE_00108d58;
  *(float *)(pixel + 0x28) =
       (float)((double)CONCAT44(0x43300000,(int)(char)src[3] ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e98;
  *(float *)(pixel + 0x2c) =
       (float)((double)CONCAT44(0x43300000,(int)(char)src[2] ^ 0x80000000) - intToDoubleBias) * invMax127;
  *(float *)(pixel + 0x30) = (GH_U2F((unsigned int)((src[1] | 0x4b000000))) - 8388608.0) * invMax255;
  *(float *)(pixel + 4) = (GH_U2F((unsigned int)((*src | 0x4b000000))) - 8388608.0) * invMax255;
  return;
}

/* _gleExtractPixel_DSDT_MAG_VIB_Byte @ 0xe59a0 (188 bytes) */
void _gleExtractPixel_DSDT_MAG_VIB_Byte(pixel, src)
  int pixel;
  char *src;
{
  double intToDoubleBias;
  float channelScale;
  
  channelScale = FLOAT_00108e98;
  intToDoubleBias = DOUBLE_00108d58;
  *(float *)(pixel + 0x28) =
       (float)((double)CONCAT44(0x43300000,(int)*src ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e98;
  *(float *)(pixel + 0x2c) =
       (float)((double)CONCAT44(0x43300000,(int)src[1] ^ 0x80000000) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 0x30) =
       (float)((double)CONCAT44(0x43300000,(int)src[2] ^ 0x80000000) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 4) =
       (float)((double)CONCAT44(0x43300000,(int)src[3] ^ 0x80000000) - intToDoubleBias) * channelScale;
  return;
}

/* _gleExtractPixel_DSDT_MAG_VIB_Ubyte @ 0xe5a5c (176 bytes) */
void _gleExtractPixel_DSDT_MAG_VIB_Ubyte(pixel, src)
  int pixel;
  byte *src;
{
  float channelScale;
  
  channelScale = FLOAT_00108e78;
  *(float *)(pixel + 0x28) = (GH_U2F((unsigned int)((*src | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  *(float *)(pixel + 0x2c) = (GH_U2F((unsigned int)((src[1] | 0x4b000000))) - 8388608.0) * channelScale;
  *(float *)(pixel + 0x30) = (GH_U2F((unsigned int)((src[2] | 0x4b000000))) - 8388608.0) * channelScale;
  *(float *)(pixel + 4) = (GH_U2F((unsigned int)((src[3] | 0x4b000000))) - 8388608.0) * channelScale;
  return;
}

/* _gleExtractPixel_DSDT_MAG_VIB_Short @ 0xe5b0c (172 bytes) */
void _gleExtractPixel_DSDT_MAG_VIB_Short(pixel, src)
  int pixel;
  short *src;
{
  double intToDoubleBias;
  float channelScale;
  
  channelScale = FLOAT_00108e9c;
  intToDoubleBias = DOUBLE_00108d58;
  *(float *)(pixel + 0x28) =
       (float)((double)CONCAT44(0x43300000,(int)*src ^ 0x80000000) - DOUBLE_00108d58) *
       FLOAT_00108e9c;
  *(float *)(pixel + 0x2c) =
       (float)((double)CONCAT44(0x43300000,(int)src[1] ^ 0x80000000) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 0x30) =
       (float)((double)CONCAT44(0x43300000,(int)src[2] ^ 0x80000000) - intToDoubleBias) * channelScale;
  *(float *)(pixel + 4) =
       (float)((double)CONCAT44(0x43300000,(int)src[3] ^ 0x80000000) - intToDoubleBias) * channelScale;
  return;
}

/* _gleExtractPixel_DSDT_MAG_VIB_Ushort @ 0xe5bb8 (176 bytes) */
void _gleExtractPixel_DSDT_MAG_VIB_Ushort(pixel, src)
  int pixel;
  ushort *src;
{
  float channelScale;
  
  channelScale = FLOAT_00108e74;
  *(float *)(pixel + 0x28) = (GH_U2F((unsigned int)((*src | 0x4b000000))) - 8388608.0) * FLOAT_00108e74;
  *(float *)(pixel + 0x2c) = (GH_U2F((unsigned int)((src[1] | 0x4b000000))) - 8388608.0) * channelScale;
  *(float *)(pixel + 0x30) = (GH_U2F((unsigned int)((src[2] | 0x4b000000))) - 8388608.0) * channelScale;
  *(float *)(pixel + 4) = (GH_U2F((unsigned int)((src[3] | 0x4b000000))) - 8388608.0) * channelScale;
  return;
}

/* _gleExtractPixel_DSDT_MAG_VIB_Int @ 0xe5c68 (188 bytes) */
void _gleExtractPixel_DSDT_MAG_VIB_Int(pixel, src)
  int pixel;
  uint *src;
{
  double intToDoubleBias;
  double channelScale;
  
  channelScale = DOUBLE_00108d88;
  intToDoubleBias = DOUBLE_00108d58;
  *(float *)(pixel + 0x28) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*src ^ 0x80000000) - DOUBLE_00108d58)
              * DOUBLE_00108d88);
  *(float *)(pixel + 0x2c) =
       (float)((double)(float)((double)CONCAT44(0x43300000,src[1] ^ 0x80000000) - intToDoubleBias) * channelScale
              );
  *(float *)(pixel + 0x30) =
       (float)((double)(float)((double)CONCAT44(0x43300000,src[2] ^ 0x80000000) - intToDoubleBias) * channelScale
              );
  *(float *)(pixel + 4) =
       (float)((double)(float)((double)CONCAT44(0x43300000,src[3] ^ 0x80000000) - intToDoubleBias) * channelScale
              );
  return;
}

/* _gleExtractPixel_DSDT_MAG_VIB_Uint @ 0xe5d24 (172 bytes) */
void _gleExtractPixel_DSDT_MAG_VIB_Uint(pixel, src)
  int pixel;
  undefined4 *src;
{
  double intToDoubleBias;
  double channelScale;
  
  channelScale = DOUBLE_00108da0;
  intToDoubleBias = DOUBLE_00108d70;
  *(float *)(pixel + 0x28) =
       (float)((double)(float)((double)CONCAT44(0x43300000,*src) - DOUBLE_00108d70) *
              DOUBLE_00108da0);
  *(float *)(pixel + 0x2c) =
       (float)((double)(float)((double)CONCAT44(0x43300000,src[1]) - intToDoubleBias) * channelScale);
  *(float *)(pixel + 0x30) =
       (float)((double)(float)((double)CONCAT44(0x43300000,src[2]) - intToDoubleBias) * channelScale);
  *(float *)(pixel + 4) =
       (float)((double)(float)((double)CONCAT44(0x43300000,src[3]) - intToDoubleBias) * channelScale);
  return;
}

/* _gleExtractPixel_DSDT_MAG_VIB_Float @ 0xe5dd0 (36 bytes) */
void _gleExtractPixel_DSDT_MAG_VIB_Float(pixel, src)
  int pixel;
  undefined4 *src;
{
  *(undefined4 *)(pixel + 0x28) = *src;
  *(undefined4 *)(pixel + 0x2c) = src[1];
  *(undefined4 *)(pixel + 0x30) = src[2];
  *(undefined4 *)(pixel + 4) = src[3];
  return;
}

/* _gleImageSize @ 0xe5df4 (48 bytes) */
int _gleImageSize(format, type, width, height)
  undefined4 format;
  undefined4 type;
  undefined4 width;
  int height;
{
  int iVar1;
  
  iVar1 = _gleRowBytes(format,type,width);
  return iVar1 * height;
}

/* _gleFillImage @ 0xe5e24 (732 bytes) */
int _gleFillImage(glContext, width, height, unusedArg4, format, type, image, dest)
  int glContext;
  int width;
  int height;
  undefined4 unusedArg4;
  undefined4 format;
  int type;
  int image;
  byte *dest;
{
  bool isMsbFirst;
  char lsbFirst;
  byte keepMask;
  byte nextByteMask;
  byte nextByte;
  int rowLengthThenRowStride;
  int bitsLeftInRow;
  int skipBytes;
  int alignRemainder;
  int strideRemainder;
  int byteCount;
  uint skipBitsThenBitShift;
  byte currentByte;
  byte *rowStart;
  byte *reverseSrcEnd;
  int componentCount;
  undefined4 rowByteCount;
  uint bitsRemainingInByte;
  int skipRowsThenRowStart;
  int bitsLeftNext;
  int skipPixels;
  int elementBytes;
  char swapBytes;
  int bitmapRowBytes;
  int elementCursor;
  int pixelBytes;
  byte *srcCursor;
  byte *reverseDest;
  int alignment;
  int elementsLeft;
  double elementBytesValue;
  
  rowLengthThenRowStride = *(int *)(glContext + 0x31cc);
  alignment = *(int *)(glContext + 0x31e0);
  swapBytes = *(char *)(glContext + 0x31e4);
  skipPixels = *(int *)(glContext + 0x31d8);
  skipRowsThenRowStart = *(int *)(glContext + 0x31d4);
  lsbFirst = *(char *)(glContext + 0x31e5);
  componentCount = _gleComponents(format);
  if (rowLengthThenRowStride < 1) {
    rowLengthThenRowStride = width;
  }
  if (type == 0x1a00) {
    bitmapRowBytes = rowLengthThenRowStride * componentCount + 7 >> 3;
    alignRemainder = bitmapRowBytes - (bitmapRowBytes / alignment) * alignment;
    if (alignRemainder != 0) {
      bitmapRowBytes = bitmapRowBytes + (alignment - alignRemainder);
    }
    skipBitsThenBitShift = skipPixels * componentCount;
    skipBytes = ((int)skipBitsThenBitShift >> 3) + (uint)((int)skipBitsThenBitShift < 0 && (skipBitsThenBitShift & 7) != 0);
    skipBitsThenBitShift = skipBitsThenBitShift + skipBytes * -8;
    bitsRemainingInByte = -skipBitsThenBitShift + 8;
    srcCursor = (byte *)(image + skipRowsThenRowStart * bitmapRowBytes + skipBytes);
    keepMask = *(byte *)(-skipBitsThenBitShift + 0x1111d0);
    nextByteMask = (&_HighBitsMask)[skipBitsThenBitShift];
    if (0 < height) {
      isMsbFirst = lsbFirst == '\0';
      bitsLeftInRow = width * componentCount;
      rowStart = srcCursor;
      do {
        while (bitsLeftInRow != 0) {
          if (isMsbFirst) {
            currentByte = *srcCursor;
          }
          else {
            currentByte = (&___glMsbToLsbTable)[*srcCursor];
          }
          if (skipBitsThenBitShift != 0) {
            if ((int)bitsRemainingInByte < bitsLeftInRow) {
              if (isMsbFirst) {
                nextByte = srcCursor[1];
              }
              else {
                nextByte = (&___glMsbToLsbTable)[srcCursor[1]];
              }
              currentByte = (currentByte & keepMask) << (skipBitsThenBitShift & 0x3f) |
                       (byte)((int)(uint)(nextByte & nextByteMask) >> (bitsRemainingInByte & 0x3f));
            }
            else {
              currentByte = (currentByte & keepMask) << (skipBitsThenBitShift & 0x3f);
            }
          }
          if (bitsLeftInRow < 8) {
            bitsLeftNext = 0;
            *dest = (&_HighBitsMask)[bitsLeftInRow] & currentByte;
          }
          else {
            *dest = currentByte;
            bitsLeftNext = bitsLeftInRow + -8;
          }
          dest = dest + 1;
          srcCursor = srcCursor + 1;
          bitsLeftInRow = bitsLeftNext;
        }
        height = height + -1;
        srcCursor = rowStart + bitmapRowBytes;
        bitsLeftInRow = width * componentCount;
        rowStart = srcCursor;
      } while (height != 0);
    }
  }
  else {
    pixelBytes = _glePixelBytes(format,type);
    if (type - 0x1400U < 2) {
      swapBytes = '\0';
    }
    rowLengthThenRowStride = rowLengthThenRowStride * pixelBytes;
    strideRemainder = rowLengthThenRowStride - (rowLengthThenRowStride / alignment) * alignment;
    if (strideRemainder != 0) {
      rowLengthThenRowStride = rowLengthThenRowStride + (alignment - strideRemainder);
    }
    skipRowsThenRowStart = skipRowsThenRowStart * rowLengthThenRowStride + skipPixels * pixelBytes + image;
    if (swapBytes == '\0') {
      rowByteCount = _gleRowBytes(format,type,width);
      _gleCopy(skipRowsThenRowStart,dest,rowByteCount,height,rowLengthThenRowStride,rowByteCount);
    }
    else {
      elementBytesValue = (double)((double (*)())_gleBytesPerElement)(type);
      elementBytes = (int)elementBytesValue;
      if (0 < height) {
        do {
          elementsLeft = width * componentCount;
          elementCursor = skipRowsThenRowStart;
          if (0 < width * componentCount) {
            do {
              if (0 < elementBytes) {
                reverseSrcEnd = (byte *)(elementBytes + elementCursor);
                reverseDest = dest;
                byteCount = elementBytes;
                do {
                  reverseSrcEnd = reverseSrcEnd + -1;
                  *reverseDest = *reverseSrcEnd;
                  reverseDest = reverseDest + 1;
                  byteCount = byteCount + -1;
                } while (byteCount != 0);
              }
              elementsLeft = elementsLeft + -1;
              dest = dest + elementBytes;
              elementCursor = elementCursor + elementBytes;
            } while (elementsLeft != 0);
          }
          height = height + -1;
          skipRowsThenRowStart = skipRowsThenRowStart + rowLengthThenRowStride;
        } while (height != 0);
      }
    }
  }
  return;
}

/* _gleEmptyImage @ 0xe6100 (840 bytes) */
void _gleEmptyImage(glContext, width, height, format, type, source, image)
  int glContext;
  int width;
  int height;
  undefined4 format;
  int type;
  byte *source;
  int image;
{
  char lsbFirst;
  byte leadMask;
  byte spillMask;
  byte destByte;
  uint mergedBits;
  int iVar6;
  int strideRemainder;
  uint skipBitsThenBitShift;
  byte *reverseSrcEnd;
  int componentCount;
  undefined4 rowByteCount;
  byte *bitmapDestCursor;
  byte *elementDestCursor;
  uint carryBits;
  byte *reverseDest;
  uint writeMask;
  int skipRows;
  int elementSize;
  int skipPixels;
  int componentsLeft;
  char swapBytes;
  int bitmapRowStride;
  int pixelBytes;
  byte *bitmapRowStart;
  byte *rowStart;
  int alignment;
  int swapBytesLeft;
  double elementBytesValue;
  
  iVar6 = *(int *)(glContext + 0x31cc);
  alignment = *(int *)(glContext + 0x31e0);
  swapBytes = *(char *)(glContext + 0x31e4);
  skipPixels = *(int *)(glContext + 0x31d8);
  skipRows = *(int *)(glContext + 0x31d4);
  lsbFirst = *(char *)(glContext + 0x31e5);
  componentCount = _gleComponents(format);
  if (iVar6 < 1) {
    iVar6 = width;
  }
  if (type == 0x1a00) {
    bitmapRowStride = iVar6 * componentCount + 7 >> 3;
    iVar6 = bitmapRowStride - (bitmapRowStride / alignment) * alignment;
    if (iVar6 != 0) {
      bitmapRowStride = bitmapRowStride + (alignment - iVar6);
    }
    skipBitsThenBitShift = skipPixels * componentCount;
    iVar6 = ((int)skipBitsThenBitShift >> 3) + (uint)((int)skipBitsThenBitShift < 0 && (skipBitsThenBitShift & 7) != 0);
    skipBitsThenBitShift = skipBitsThenBitShift + iVar6 * -8;
    bitmapRowStart = (byte *)(image + skipRows * bitmapRowStride + iVar6);
    leadMask = *(byte *)(-skipBitsThenBitShift + 0x1111d0);
    spillMask = (&_HighBitsMask)[skipBitsThenBitShift];
    if (0 < height) {
      do {
        carryBits = 0;
        if (width * componentCount != 0) {
          bitmapDestCursor = bitmapRowStart;
          iVar6 = width * componentCount;
          writeMask = (uint)leadMask;
          do {
            if ((int)(iVar6 + skipBitsThenBitShift) < 8) {
              writeMask = writeMask & (byte)(&_HighBitsMask)[iVar6 + skipBitsThenBitShift];
            }
            if (lsbFirst == '\0') {
              destByte = *bitmapDestCursor;
            }
            else {
              destByte = (&___glMsbToLsbTable)[*bitmapDestCursor];
            }
            if (skipBitsThenBitShift == 0) {
              writeMask = (uint)destByte & ~writeMask | *source & writeMask;
            }
            else {
              mergedBits = carryBits | (int)(uint)*source >> (skipBitsThenBitShift & 0x3f) & 0xffU;
              carryBits = (uint)*source << (-skipBitsThenBitShift + 8 & 0x3f) & 0xff;
              writeMask = (uint)destByte & ~writeMask | mergedBits & writeMask;
            }
            if (lsbFirst == '\0') {
              *bitmapDestCursor = (byte)writeMask;
            }
            else {
              *bitmapDestCursor = (&___glMsbToLsbTable)[writeMask];
            }
            if (iVar6 < 8) {
              iVar6 = 0;
            }
            else {
              iVar6 = iVar6 + -8;
            }
            source = source + 1;
            bitmapDestCursor = bitmapDestCursor + 1;
            writeMask = 0xff;
          } while (iVar6 != 0);
          if (carryBits != 0) {
            if (lsbFirst == '\0') {
              destByte = *bitmapDestCursor;
            }
            else {
              destByte = (&___glMsbToLsbTable)[*bitmapDestCursor];
            }
            carryBits = (uint)destByte & ~(uint)spillMask | carryBits & spillMask;
            if (lsbFirst == '\0') {
              *bitmapDestCursor = (byte)carryBits;
            }
            else {
              *bitmapDestCursor = (&___glMsbToLsbTable)[carryBits];
            }
          }
        }
        height = height + -1;
        bitmapRowStart = bitmapRowStart + bitmapRowStride;
      } while (height != 0);
    }
  }
  else {
    pixelBytes = _glePixelBytes(format,type);
    if (type - 0x1400U < 2) {
      swapBytes = '\0';
    }
    iVar6 = iVar6 * pixelBytes;
    strideRemainder = iVar6 - (iVar6 / alignment) * alignment;
    if (strideRemainder != 0) {
      iVar6 = iVar6 + (alignment - strideRemainder);
    }
    rowStart = (byte *)(skipRows * iVar6 + skipPixels * pixelBytes + image);
    if (swapBytes == '\0') {
      rowByteCount = _gleRowBytes(format,type,width);
      _gleCopy(source,rowStart,rowByteCount,height,rowByteCount,iVar6);
    }
    else {
      elementBytesValue = (double)((double (*)())_gleBytesPerElement)(type);
      elementSize = (int)elementBytesValue;
      if (0 < height) {
        do {
          elementDestCursor = rowStart;
          componentsLeft = width * componentCount;
          if (0 < width * componentCount) {
            do {
              if (0 < elementSize) {
                reverseSrcEnd = source + elementSize;
                reverseDest = elementDestCursor;
                swapBytesLeft = elementSize;
                do {
                  reverseSrcEnd = reverseSrcEnd + -1;
                  *reverseDest = *reverseSrcEnd;
                  reverseDest = reverseDest + 1;
                  swapBytesLeft = swapBytesLeft + -1;
                } while (swapBytesLeft != 0);
              }
              componentsLeft = componentsLeft + -1;
              source = source + elementSize;
              elementDestCursor = elementDestCursor + elementSize;
            } while (componentsLeft != 0);
          }
          height = height + -1;
          rowStart = rowStart + iVar6;
        } while (height != 0);
      }
    }
  }
  return;
}

/* _gleModifyPixelStencil @ 0xe6448 (196 bytes) */
void _gleModifyPixelStencil(glContext, pixel, unusedArg3, unusedArg4, unusedArg5, unusedArg6, unusedArg7, unusedArg8)
  int glContext;
  int pixel;
  undefined4 unusedArg3;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
  undefined4 unusedArg8;
{
  uint uVar1;
  uint uVar2;
  uint indexInteger;
  int stencilValue;
  uint indexFraction;
  
  uVar2 = *(uint *)(glContext + 0x3214);
  indexFraction = *(uint *)(pixel + 0x1c);
  indexInteger = *(uint *)(pixel + 0x18);
  if ((int)uVar2 < 1) {
    if ((int)uVar2 < 0) {
      uVar1 = -uVar2;
      if ((int)uVar1 < 0xf) {
        uVar2 = indexInteger << (uVar2 + 0xf & 0x3f);
      }
      else {
        uVar2 = (int)indexInteger >> (uVar1 - 0xf & 0x3f);
      }
      indexInteger = (int)indexInteger >> (uVar1 & 0x3f);
      indexFraction = ((int)indexFraction >> (uVar1 & 0x3f) | uVar2) & 0x7fff;
    }
  }
  else {
    if ((int)uVar2 < 0xf) {
      uVar1 = (int)indexFraction >> (0xf - uVar2 & 0x3f);
    }
    else {
      uVar1 = indexFraction << (uVar2 - 0xf & 0x3f);
    }
    indexInteger = indexInteger << (uVar2 & 0x3f) | uVar1;
    indexFraction = indexFraction << (uVar2 & 0x3f);
  }
  stencilValue = indexInteger + *(int *)(glContext + 0x3210);
  if ((*(uint *)(glContext + 0x3414) & 2) != 0) {
    if (stencilValue < *(int *)(glContext + 0x3274)) {
      stencilValue = *(int *)(stencilValue * 4 + *(int *)(glContext + 0x326c));
    }
    else {
      stencilValue = *(int *)(*(int *)(glContext + 0x3274) * 4 + *(int *)(glContext + 0x326c) + -4);
    }
  }
  *(uint *)(pixel + 0x1c) = indexFraction;
  *(int *)(pixel + 0x18) = stencilValue;
  return;
}

/* _gleModifyPixelDepth @ 0xe650c (84 bytes) */
void _gleModifyPixelDepth(glContext, pixel)
  int glContext;
  int pixel;
{
  float fVar1;
  float fVar2;
  
  fVar1 = *(float *)(pixel + 0x14) * *(float *)(glContext + 0x320c) + *(float *)(glContext + 0x3208);
  fVar2 = FLOAT_00108e50;
  if ((!(fVar1 < FLOAT_00108e50)) && (fVar2 = fVar1, FLOAT_00108e54 < fVar1)) {
    fVar2 = FLOAT_00108e54;
  }
  *(float *)(pixel + 0x14) = fVar2;
  return;
}

/* _gleModifyPixelR @ 0xe6560 (200 bytes) */
void _gleModifyPixelR(int glContext,int pixel,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11)
{
  uint uVar1;
  float red;
  float fVar3;
  uint uVar4;
  
  red = *(float *)(pixel + 4) * *(float *)(glContext + 0x31ec) + *(float *)(glContext + 0x31e8);
  if ((*(uint *)(glContext + 0x3414) & 1) == 0) {
    fVar3 = FLOAT_00108e50;
    if ((red < FLOAT_00108e50) || (fVar3 = FLOAT_00108e54, FLOAT_00108e54 < red)) {
      red = fVar3;
    }
  }
  else {
    uVar4 = *(int *)(glContext + 0x3288) - 1;
    uVar1 = (uint)(int)(red * (float)((double)CONCAT44(0x43300000,uVar4 ^ 0x80000000) - DOUBLE_00108d58
                                  ) + FLOAT_00108e90);
    if (((int)uVar1 <= (int)uVar4) && (uVar4 = uVar1, (int)uVar1 < 0)) {
      uVar4 = 0;
    }
    red = *(float *)(uVar4 * 4 + *(int *)(glContext + 0x325c));
  }
  *(float *)(pixel + 4) = red;
  return;
}

/* _gleModifyPixelG @ 0xe6628 (200 bytes) */
void _gleModifyPixelG(int glContext,int pixel,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11)
{
  uint uVar1;
  float green;
  float fVar3;
  uint uVar4;
  
  green = *(float *)(pixel + 8) * *(float *)(glContext + 0x31f4) + *(float *)(glContext + 0x31f0);
  if ((*(uint *)(glContext + 0x3414) & 1) == 0) {
    fVar3 = FLOAT_00108e50;
    if ((green < FLOAT_00108e50) || (fVar3 = FLOAT_00108e54, FLOAT_00108e54 < green)) {
      green = fVar3;
    }
  }
  else {
    uVar4 = *(int *)(glContext + 0x328c) - 1;
    uVar1 = (uint)(int)(green * (float)((double)CONCAT44(0x43300000,uVar4 ^ 0x80000000) - DOUBLE_00108d58
                                  ) + FLOAT_00108e90);
    if (((int)uVar1 <= (int)uVar4) && (uVar4 = uVar1, (int)uVar1 < 0)) {
      uVar4 = 0;
    }
    green = *(float *)(uVar4 * 4 + *(int *)(glContext + 0x3260));
  }
  *(float *)(pixel + 8) = green;
  return;
}

/* _gleModifyPixelB @ 0xe66f0 (200 bytes) */
void _gleModifyPixelB(int glContext,int pixel,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11)
{
  uint blueScaledIndex;
  float blue;
  float clampedBlue;
  uint blueMapIndex;
  
  blue = *(float *)(pixel + 0xc) * *(float *)(glContext + 0x31fc) + *(float *)(glContext + 0x31f8);
  if ((*(uint *)(glContext + 0x3414) & 1) == 0) {
    clampedBlue = FLOAT_00108e50;
    if ((blue < FLOAT_00108e50) || (clampedBlue = FLOAT_00108e54, FLOAT_00108e54 < blue)) {
      blue = clampedBlue;
    }
  }
  else {
    blueMapIndex = *(int *)(glContext + 0x3290) - 1;
    blueScaledIndex = (uint)(int)(blue * (float)((double)CONCAT44(0x43300000,blueMapIndex ^ 0x80000000) - DOUBLE_00108d58
                                  ) + FLOAT_00108e90);
    if (((int)blueScaledIndex <= (int)blueMapIndex) && (blueMapIndex = blueScaledIndex, (int)blueScaledIndex < 0)) {
      blueMapIndex = 0;
    }
    blue = *(float *)(blueMapIndex * 4 + *(int *)(glContext + 0x3264));
  }
  *(float *)(pixel + 0xc) = blue;
  return;
}

/* _gleModifyPixelA @ 0xe67b8 (200 bytes) */
void _gleModifyPixelA(int glContext,int pixel,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11)
{
  uint uVar1;
  float alpha;
  float fVar3;
  uint uVar4;
  
  alpha = *(float *)(pixel + 0x10) * *(float *)(glContext + 0x3204) + *(float *)(glContext + 0x3200);
  if ((*(uint *)(glContext + 0x3414) & 1) == 0) {
    fVar3 = FLOAT_00108e50;
    if ((alpha < FLOAT_00108e50) || (fVar3 = FLOAT_00108e54, FLOAT_00108e54 < alpha)) {
      alpha = fVar3;
    }
  }
  else {
    uVar4 = *(int *)(glContext + 0x3294) - 1;
    uVar1 = (uint)(int)(alpha * (float)((double)CONCAT44(0x43300000,uVar4 ^ 0x80000000) - DOUBLE_00108d58
                                  ) + FLOAT_00108e90);
    if (((int)uVar1 <= (int)uVar4) && (uVar4 = uVar1, (int)uVar1 < 0)) {
      uVar4 = 0;
    }
    alpha = *(float *)(uVar4 * 4 + *(int *)(glContext + 0x3268));
  }
  *(float *)(pixel + 0x10) = alpha;
  return;
}

/* _gleModifyPixelRGB @ 0xe6880 (488 bytes) */
void _gleModifyPixelRGB(glContext, pixel)
  int glContext;
  int pixel;
{
  uint uVar1;
  uint greenScaledIndex;
  uint uVar3;
  float red;
  float green;
  float blue;
  float fVar7;
  uint uVar8;
  uint uVar9;
  uint greenMapIndex;
  
  red = *(float *)(pixel + 4) * *(float *)(glContext + 0x31ec) + *(float *)(glContext + 0x31e8);
  green = *(float *)(pixel + 8) * *(float *)(glContext + 0x31f4) + *(float *)(glContext + 0x31f0);
  blue = *(float *)(pixel + 0xc) * *(float *)(glContext + 0x31fc) + *(float *)(glContext + 0x31f8);
  if ((*(uint *)(glContext + 0x3414) & 1) == 0) {
    fVar7 = FLOAT_00108e50;
    if ((red < FLOAT_00108e50) || (fVar7 = FLOAT_00108e54, FLOAT_00108e54 < red)) {
      red = fVar7;
    }
    fVar7 = FLOAT_00108e50;
    if ((green < FLOAT_00108e50) || (fVar7 = FLOAT_00108e54, FLOAT_00108e54 < green)) {
      green = fVar7;
    }
    fVar7 = FLOAT_00108e50;
    if ((blue < FLOAT_00108e50) || (fVar7 = FLOAT_00108e54, FLOAT_00108e54 < blue)) {
      blue = fVar7;
    }
  }
  else {
    uVar9 = *(int *)(glContext + 0x3288) - 1;
    greenMapIndex = *(int *)(glContext + 0x328c) - 1;
    uVar8 = *(int *)(glContext + 0x3290) - 1;
    uVar1 = (uint)(int)(red * (float)((double)CONCAT44(0x43300000,uVar9 ^ 0x80000000) - DOUBLE_00108d58
                                  ) + FLOAT_00108e90);
    greenScaledIndex = (uint)(int)(green * (float)((double)CONCAT44(0x43300000,greenMapIndex ^ 0x80000000) -
                                  DOUBLE_00108d58) + FLOAT_00108e90);
    uVar3 = (uint)(int)(blue * (float)((double)CONCAT44(0x43300000,uVar8 ^ 0x80000000) - DOUBLE_00108d58
                                  ) + FLOAT_00108e90);
    if (((int)uVar1 <= (int)uVar9) && (uVar9 = uVar1, (int)uVar1 < 0)) {
      uVar9 = 0;
    }
    if (((int)greenScaledIndex <= (int)greenMapIndex) && (greenMapIndex = greenScaledIndex, (int)greenScaledIndex < 0)) {
      greenMapIndex = 0;
    }
    if (((int)uVar3 <= (int)uVar8) && (uVar8 = uVar3, (int)uVar3 < 0)) {
      uVar8 = 0;
    }
    red = *(float *)(uVar9 * 4 + *(int *)(glContext + 0x325c));
    green = *(float *)(greenMapIndex * 4 + *(int *)(glContext + 0x3260));
    blue = *(float *)(uVar8 * 4 + *(int *)(glContext + 0x3264));
  }
  *(float *)(pixel + 0xc) = blue;
  *(float *)(pixel + 4) = red;
  *(float *)(pixel + 8) = green;
  return;
}

/* _gleModifyPixelRGBA @ 0xe6a68 (636 bytes) */
void _gleModifyPixelRGBA(glContext, pixel)
  int glContext;
  int pixel;
{
  uint redScaledIndex;
  uint greenScaledIndex;
  uint blueScaledIndex;
  uint alphaScaledIndex;
  float red;
  float green;
  float blue;
  float alpha;
  float clampedComponent;
  uint alphaMapIndex;
  uint blueMapIndex;
  uint greenMapIndex;
  uint redMapIndex;
  
  red = *(float *)(pixel + 4) * *(float *)(glContext + 0x31ec) + *(float *)(glContext + 0x31e8);
  green = *(float *)(pixel + 8) * *(float *)(glContext + 0x31f4) + *(float *)(glContext + 0x31f0);
  blue = *(float *)(pixel + 0xc) * *(float *)(glContext + 0x31fc) + *(float *)(glContext + 0x31f8);
  alpha = *(float *)(pixel + 0x10) * *(float *)(glContext + 0x3204) + *(float *)(glContext + 0x3200);
  if ((*(uint *)(glContext + 0x3414) & 1) == 0) {
    clampedComponent = FLOAT_00108e50;
    if ((red < FLOAT_00108e50) || (clampedComponent = FLOAT_00108e54, FLOAT_00108e54 < red)) {
      red = clampedComponent;
    }
    clampedComponent = FLOAT_00108e50;
    if ((green < FLOAT_00108e50) || (clampedComponent = FLOAT_00108e54, FLOAT_00108e54 < green)) {
      green = clampedComponent;
    }
    clampedComponent = FLOAT_00108e50;
    if ((blue < FLOAT_00108e50) || (clampedComponent = FLOAT_00108e54, FLOAT_00108e54 < blue)) {
      blue = clampedComponent;
    }
    clampedComponent = FLOAT_00108e50;
    if ((alpha < FLOAT_00108e50) || (clampedComponent = FLOAT_00108e54, FLOAT_00108e54 < alpha)) {
      alpha = clampedComponent;
    }
  }
  else {
    redMapIndex = *(int *)(glContext + 0x3288) - 1;
    greenMapIndex = *(int *)(glContext + 0x328c) - 1;
    blueMapIndex = *(int *)(glContext + 0x3290) - 1;
    alphaMapIndex = *(int *)(glContext + 0x3294) - 1;
    redScaledIndex = (uint)(int)(red * (float)((double)CONCAT44(0x43300000,redMapIndex ^ 0x80000000) -
                                  DOUBLE_00108d58) + FLOAT_00108e90);
    greenScaledIndex = (uint)(int)(green * (float)((double)CONCAT44(0x43300000,greenMapIndex ^ 0x80000000) -
                                  DOUBLE_00108d58) + FLOAT_00108e90);
    blueScaledIndex = (uint)(int)(blue * (float)((double)CONCAT44(0x43300000,blueMapIndex ^ 0x80000000) -
                                  DOUBLE_00108d58) + FLOAT_00108e90);
    alphaScaledIndex = (uint)(int)(alpha * (float)((double)CONCAT44(0x43300000,alphaMapIndex ^ 0x80000000) -
                                  DOUBLE_00108d58) + FLOAT_00108e90);
    if (((int)redScaledIndex <= (int)redMapIndex) && (redMapIndex = redScaledIndex, (int)redScaledIndex < 0)) {
      redMapIndex = 0;
    }
    if (((int)greenScaledIndex < (int)greenMapIndex) && (greenMapIndex = greenScaledIndex, (int)greenScaledIndex < 0)) {
      greenMapIndex = 0;
    }
    if (((int)blueScaledIndex <= (int)blueMapIndex) && (blueMapIndex = blueScaledIndex, (int)blueScaledIndex < 0)) {
      blueMapIndex = 0;
    }
    if (((int)alphaScaledIndex <= (int)alphaMapIndex) && (alphaMapIndex = alphaScaledIndex, (int)alphaScaledIndex < 0)) {
      alphaMapIndex = 0;
    }
    red = *(float *)(redMapIndex * 4 + *(int *)(glContext + 0x325c));
    green = *(float *)(greenMapIndex * 4 + *(int *)(glContext + 0x3260));
    blue = *(float *)(blueMapIndex * 4 + *(int *)(glContext + 0x3264));
    alpha = *(float *)(alphaMapIndex * 4 + *(int *)(glContext + 0x3268));
  }
  *(float *)(pixel + 0x10) = alpha;
  *(float *)(pixel + 4) = red;
  *(float *)(pixel + 8) = green;
  *(float *)(pixel + 0xc) = blue;
  return;
}

/* _gleModifyPixelRGBAIndex @ 0xe6ce4 (248 bytes) */
void _gleModifyPixelRGBAIndex(glContext, pixel)
  int glContext;
  int pixel;
{
  undefined4 mappedAlpha;
  uint shiftMagnitude;
  uint carryBits;
  uint indexShiftThenCarryBits;
  uint indexFraction;
  uint indexInteger;
  
  indexShiftThenCarryBits = *(uint *)(glContext + 0x3214);
  indexInteger = *(uint *)(pixel + 0x18);
  indexFraction = *(uint *)(pixel + 0x1c);
  if ((int)indexShiftThenCarryBits < 1) {
    if ((int)indexShiftThenCarryBits < 0) {
      shiftMagnitude = -indexShiftThenCarryBits;
      if ((int)shiftMagnitude < 0xf) {
        indexShiftThenCarryBits = indexInteger << (indexShiftThenCarryBits + 0xf & 0x3f);
      }
      else {
        indexShiftThenCarryBits = (int)indexInteger >> (shiftMagnitude - 0xf & 0x3f);
      }
      indexInteger = (int)indexInteger >> (shiftMagnitude & 0x3f);
      indexFraction = ((int)indexFraction >> (shiftMagnitude & 0x3f) | indexShiftThenCarryBits) & 0x7fff;
    }
  }
  else {
    if ((int)indexShiftThenCarryBits < 0xf) {
      carryBits = (int)indexFraction >> (0xf - indexShiftThenCarryBits & 0x3f);
    }
    else {
      carryBits = indexFraction << (indexShiftThenCarryBits - 0xf & 0x3f);
    }
    indexInteger = indexInteger << (indexShiftThenCarryBits & 0x3f) | carryBits;
    indexFraction = indexFraction << (indexShiftThenCarryBits & 0x3f);
  }
  indexInteger = indexInteger + *(int *)(glContext + 0x3210);
  *(undefined4 *)(pixel + 4) =
       *(undefined4 *)((indexInteger & *(int *)(glContext + 0x3278) - 1U) * 4 + *(int *)(glContext + 0x324c));
  *(undefined4 *)(pixel + 8) =
       *(undefined4 *)((indexInteger & *(int *)(glContext + 0x327c) - 1U) * 4 + *(int *)(glContext + 0x3250));
  *(undefined4 *)(pixel + 0xc) =
       *(undefined4 *)((indexInteger & *(int *)(glContext + 0x3280) - 1U) * 4 + *(int *)(glContext + 0x3254));
  mappedAlpha = *(undefined4 *)
           ((indexInteger & *(int *)(glContext + 0x3284) - 1U) * 4 + *(int *)(glContext + 0x3258));
  *(uint *)(pixel + 0x1c) = indexFraction;
  *(undefined4 *)(pixel + 0x10) = mappedAlpha;
  *(uint *)(pixel + 0x18) = indexInteger;
  return;
}

/* _gleModifyPixelHILO @ 0xe6ddc (132 bytes) */
void _gleModifyPixelHILO(int glContext,int pixel,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10)
{
  float hi;
  float lo;
  float clampedValue;
  
  hi = *(float *)(pixel + 0x20) * *(float *)(glContext + 0x321c) + *(float *)(glContext + 0x3218);
  lo = *(float *)(pixel + 0x24) * *(float *)(glContext + 0x3224) + *(float *)(glContext + 0x3220);
  clampedValue = FLOAT_00108e54;
  if ((FLOAT_00108e54 < hi) || (clampedValue = FLOAT_00108e58, hi < FLOAT_00108e58)) {
    hi = clampedValue;
  }
  clampedValue = FLOAT_00108e54;
  if ((FLOAT_00108e54 < lo) || (clampedValue = FLOAT_00108e58, lo < FLOAT_00108e58)) {
    lo = clampedValue;
  }
  *(float *)(pixel + 0x24) = lo;
  *(float *)(pixel + 0x20) = hi;
  return;
}

/* _gleModifyPixelDSDTMagVib @ 0xe6e60 (252 bytes) */
void _gleModifyPixelDSDTMagVib(int glContext,int pixel,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5)
{
  float scaledDsThenClampResult;
  float red;
  float clampedDs;
  float mag;
  float dt;
  
  scaledDsThenClampResult = *(float *)(pixel + 0x28) * *(float *)(glContext + 0x322c) + *(float *)(glContext + 0x3228);
  dt = *(float *)(pixel + 0x2c) * *(float *)(glContext + 0x3234) + *(float *)(glContext + 0x3230);
  mag = *(float *)(pixel + 0x30) * *(float *)(glContext + 0x323c) + *(float *)(glContext + 0x3238);
  red = *(float *)(pixel + 4) * *(float *)(glContext + 0x3244) + *(float *)(glContext + 0x3240);
  clampedDs = FLOAT_00108e54;
  if ((!(FLOAT_00108e54 < scaledDsThenClampResult)) && (clampedDs = scaledDsThenClampResult, scaledDsThenClampResult < FLOAT_00108e58)) {
    clampedDs = FLOAT_00108e58;
  }
  scaledDsThenClampResult = FLOAT_00108e54;
  if ((FLOAT_00108e54 < dt) || (scaledDsThenClampResult = FLOAT_00108e58, dt < FLOAT_00108e58)) {
    dt = scaledDsThenClampResult;
  }
  scaledDsThenClampResult = FLOAT_00108e54;
  if ((FLOAT_00108e54 < mag) || (scaledDsThenClampResult = FLOAT_00108e50, mag < FLOAT_00108e50)) {
    mag = scaledDsThenClampResult;
  }
  scaledDsThenClampResult = FLOAT_00108e54;
  if ((FLOAT_00108e54 < red) || (scaledDsThenClampResult = FLOAT_00108e50, red < FLOAT_00108e50)) {
    red = scaledDsThenClampResult;
  }
  *(float *)(pixel + 4) = red;
  *(float *)(pixel + 0x28) = clampedDs;
  *(float *)(pixel + 0x2c) = dt;
  *(float *)(pixel + 0x30) = mag;
  return;
}

/* _gleModifyPixelSignedRGBA @ 0xe6f5c (636 bytes) */
void _gleModifyPixelSignedRGBA(glContext, pixel)
  int glContext;
  int pixel;
{
  uint redScaledIndex;
  uint greenScaledIndex;
  uint blueScaledIndex;
  uint alphaScaledIndex;
  float red;
  float green;
  float blue;
  float alpha;
  float fVar9;
  uint alphaMapIndex;
  uint blueMapIndex;
  uint greenMapIndex;
  uint redMapIndex;
  
  red = *(float *)(pixel + 4) * *(float *)(glContext + 0x31ec) + *(float *)(glContext + 0x31e8);
  green = *(float *)(pixel + 8) * *(float *)(glContext + 0x31f4) + *(float *)(glContext + 0x31f0);
  blue = *(float *)(pixel + 0xc) * *(float *)(glContext + 0x31fc) + *(float *)(glContext + 0x31f8);
  alpha = *(float *)(pixel + 0x10) * *(float *)(glContext + 0x3204) + *(float *)(glContext + 0x3200);
  if ((*(uint *)(glContext + 0x3414) & 1) == 0) {
    fVar9 = FLOAT_00108e58;
    if ((red < FLOAT_00108e58) || (fVar9 = FLOAT_00108e54, FLOAT_00108e54 < red)) {
      red = fVar9;
    }
    fVar9 = FLOAT_00108e58;
    if ((green < FLOAT_00108e58) || (fVar9 = FLOAT_00108e54, FLOAT_00108e54 < green)) {
      green = fVar9;
    }
    fVar9 = FLOAT_00108e58;
    if ((blue < FLOAT_00108e58) || (fVar9 = FLOAT_00108e54, FLOAT_00108e54 < blue)) {
      blue = fVar9;
    }
    fVar9 = FLOAT_00108e58;
    if ((alpha < FLOAT_00108e58) || (fVar9 = FLOAT_00108e54, FLOAT_00108e54 < alpha)) {
      alpha = fVar9;
    }
  }
  else {
    redMapIndex = *(int *)(glContext + 0x3288) - 1;
    greenMapIndex = *(int *)(glContext + 0x328c) - 1;
    blueMapIndex = *(int *)(glContext + 0x3290) - 1;
    alphaMapIndex = *(int *)(glContext + 0x3294) - 1;
    redScaledIndex = (uint)(int)(red * (float)((double)CONCAT44(0x43300000,redMapIndex ^ 0x80000000) -
                                  DOUBLE_00108d58) + FLOAT_00108e90);
    greenScaledIndex = (uint)(int)(green * (float)((double)CONCAT44(0x43300000,greenMapIndex ^ 0x80000000) -
                                  DOUBLE_00108d58) + FLOAT_00108e90);
    blueScaledIndex = (uint)(int)(blue * (float)((double)CONCAT44(0x43300000,blueMapIndex ^ 0x80000000) -
                                  DOUBLE_00108d58) + FLOAT_00108e90);
    alphaScaledIndex = (uint)(int)(alpha * (float)((double)CONCAT44(0x43300000,alphaMapIndex ^ 0x80000000) -
                                  DOUBLE_00108d58) + FLOAT_00108e90);
    if (((int)redScaledIndex <= (int)redMapIndex) && (redMapIndex = redScaledIndex, (int)redScaledIndex < 0)) {
      redMapIndex = 0;
    }
    if (((int)greenScaledIndex < (int)greenMapIndex) && (greenMapIndex = greenScaledIndex, (int)greenScaledIndex < 0)) {
      greenMapIndex = 0;
    }
    if (((int)blueScaledIndex <= (int)blueMapIndex) && (blueMapIndex = blueScaledIndex, (int)blueScaledIndex < 0)) {
      blueMapIndex = 0;
    }
    if (((int)alphaScaledIndex <= (int)alphaMapIndex) && (alphaMapIndex = alphaScaledIndex, (int)alphaScaledIndex < 0)) {
      alphaMapIndex = 0;
    }
    red = *(float *)(redMapIndex * 4 + *(int *)(glContext + 0x325c));
    green = *(float *)(greenMapIndex * 4 + *(int *)(glContext + 0x3260));
    blue = *(float *)(blueMapIndex * 4 + *(int *)(glContext + 0x3264));
    alpha = *(float *)(alphaMapIndex * 4 + *(int *)(glContext + 0x3268));
  }
  *(float *)(pixel + 0x10) = alpha;
  *(float *)(pixel + 4) = red;
  *(float *)(pixel + 8) = green;
  *(float *)(pixel + 0xc) = blue;
  return;
}

/* _gleModifyPixelSignedRGB_UnsignedA @ 0xe71d8 (636 bytes) */
void _gleModifyPixelSignedRGB_UnsignedA(glContext, pixel)
  int glContext;
  int pixel;
{
  uint redScaledIndex;
  uint greenScaledIndex;
  uint blueScaledIndex;
  uint alphaScaledIndex;
  float red;
  float green;
  float blue;
  float alpha;
  float fVar9;
  uint alphaMapIndex;
  uint blueMapIndex;
  uint greenMapIndex;
  uint redMapIndex;
  
  red = *(float *)(pixel + 4) * *(float *)(glContext + 0x31ec) + *(float *)(glContext + 0x31e8);
  green = *(float *)(pixel + 8) * *(float *)(glContext + 0x31f4) + *(float *)(glContext + 0x31f0);
  blue = *(float *)(pixel + 0xc) * *(float *)(glContext + 0x31fc) + *(float *)(glContext + 0x31f8);
  alpha = *(float *)(pixel + 0x10) * *(float *)(glContext + 0x3204) + *(float *)(glContext + 0x3200);
  if ((*(uint *)(glContext + 0x3414) & 1) == 0) {
    fVar9 = FLOAT_00108e58;
    if ((red < FLOAT_00108e58) || (fVar9 = FLOAT_00108e54, FLOAT_00108e54 < red)) {
      red = fVar9;
    }
    fVar9 = FLOAT_00108e58;
    if ((green < FLOAT_00108e58) || (fVar9 = FLOAT_00108e54, FLOAT_00108e54 < green)) {
      green = fVar9;
    }
    fVar9 = FLOAT_00108e58;
    if ((blue < FLOAT_00108e58) || (fVar9 = FLOAT_00108e54, FLOAT_00108e54 < blue)) {
      blue = fVar9;
    }
    fVar9 = FLOAT_00108e50;
    if ((alpha < FLOAT_00108e50) || (fVar9 = FLOAT_00108e54, FLOAT_00108e54 < alpha)) {
      alpha = fVar9;
    }
  }
  else {
    redMapIndex = *(int *)(glContext + 0x3288) - 1;
    greenMapIndex = *(int *)(glContext + 0x328c) - 1;
    blueMapIndex = *(int *)(glContext + 0x3290) - 1;
    alphaMapIndex = *(int *)(glContext + 0x3294) - 1;
    redScaledIndex = (uint)(int)(red * (float)((double)CONCAT44(0x43300000,redMapIndex ^ 0x80000000) -
                                  DOUBLE_00108d58) + FLOAT_00108e90);
    greenScaledIndex = (uint)(int)(green * (float)((double)CONCAT44(0x43300000,greenMapIndex ^ 0x80000000) -
                                  DOUBLE_00108d58) + FLOAT_00108e90);
    blueScaledIndex = (uint)(int)(blue * (float)((double)CONCAT44(0x43300000,blueMapIndex ^ 0x80000000) -
                                  DOUBLE_00108d58) + FLOAT_00108e90);
    alphaScaledIndex = (uint)(int)(alpha * (float)((double)CONCAT44(0x43300000,alphaMapIndex ^ 0x80000000) -
                                  DOUBLE_00108d58) + FLOAT_00108e90);
    if (((int)redScaledIndex <= (int)redMapIndex) && (redMapIndex = redScaledIndex, (int)redScaledIndex < 0)) {
      redMapIndex = 0;
    }
    if (((int)greenScaledIndex < (int)greenMapIndex) && (greenMapIndex = greenScaledIndex, (int)greenScaledIndex < 0)) {
      greenMapIndex = 0;
    }
    if (((int)blueScaledIndex <= (int)blueMapIndex) && (blueMapIndex = blueScaledIndex, (int)blueScaledIndex < 0)) {
      blueMapIndex = 0;
    }
    if (((int)alphaScaledIndex <= (int)alphaMapIndex) && (alphaMapIndex = alphaScaledIndex, (int)alphaScaledIndex < 0)) {
      alphaMapIndex = 0;
    }
    red = *(float *)(redMapIndex * 4 + *(int *)(glContext + 0x325c));
    green = *(float *)(greenMapIndex * 4 + *(int *)(glContext + 0x3260));
    blue = *(float *)(blueMapIndex * 4 + *(int *)(glContext + 0x3264));
    alpha = *(float *)(alphaMapIndex * 4 + *(int *)(glContext + 0x3268));
  }
  *(float *)(pixel + 0x10) = alpha;
  *(float *)(pixel + 4) = red;
  *(float *)(pixel + 8) = green;
  *(float *)(pixel + 0xc) = blue;
  return;
}

/* _gleSelectPixelInsertFunc @ 0xe7454 (2464 bytes) */
int _gleSelectPixelInsertFunc(format, type)
  uint format;
  uint type;
{
  if (format == 0x1906) {
    switch(type) {
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
  if (format < 0x1907) {
    if (format == 0x1902) {
      switch(type) {
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
    if (0x1902 < format) {
      if (format == 0x1904) {
        switch(type) {
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
      if (0x1904 < format) {
        switch(type) {
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
      switch(type) {
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
    if (0x18ff < format) {
      switch(type) {
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
    if (format == 0x1909) {
      switch(type) {
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
    if (format < 0x190a) {
      if (format == 0x1907) {
        if (type == 0x1404) {
          return PTR__gleInsertPixel_RGB_Int_001112cc;
        }
        if (type < 0x1405) {
          if (type == 0x1401) {
            return PTR__gleInsertPixel_RGB_Ubyte_001112d8;
          }
          if (type < 0x1402) {
            if (type == 0x1400) {
              return PTR__gleInsertPixel_RGB_Byte_001112dc;
            }
          }
          else {
            if (type == 0x1402) {
              return PTR__gleInsertPixel_RGB_Short_001112d4;
            }
            if (type == 0x1403) {
              return PTR__gleInsertPixel_RGB_Ushort_001112d0;
            }
          }
        }
        else {
          if (type == 0x8032) {
            return PTR__gleInsertPixel_RGB_332_001112c0;
          }
          if (type < 0x8033) {
            if (type == 0x1405) {
              return PTR__gleInsertPixel_RGB_Uint_001112c8;
            }
            if (type == 0x1406) {
              return PTR__gleInsertPixel_RGB_Float_001112c4;
            }
          }
          else {
            if (type == 0x8362) {
              return PTR__gleInsertPixel_RGB_233Rev_001112bc;
            }
            if (type == 0x8363) {
              return PTR__gleInsertPixel_RGB_565_001112b8;
            }
          }
        }
        return PTR__gleInsertPixel_RGB_565Rev_001112b4;
      }
      if (format == 0x1908) {
        if (type == 0x1406) {
          return PTR__gleInsertPixel_RGBA_Float_00111374;
        }
        if (type < 0x1407) {
          if (type == 0x1402) {
            return PTR__gleInsertPixel_RGBA_Short_00111384;
          }
          if (0x1402 < type) {
            if (type == 0x1404) {
              return PTR__gleInsertPixel_RGBA_Int_0011137c;
            }
            if (0x1404 < type) {
              return PTR__gleInsertPixel_RGBA_Uint_00111378;
            }
            return PTR__gleInsertPixel_RGBA_Ushort_00111380;
          }
          if (type == 0x1400) {
            return PTR__gleInsertPixel_RGBA_Byte_0011138c;
          }
          if (type == 0x1401) {
            return PTR__gleInsertPixel_RGBA_Ubyte_00111388;
          }
        }
        else {
          if (type == 0x8036) {
            return PTR__gleInsertPixel_RGBA_1010102_00111358;
          }
          if (type < 0x8037) {
            if (type == 0x8034) {
              return PTR__gleInsertPixel_RGBA_5551_00111368;
            }
            if (0x8034 < type) {
              return PTR__gleInsertPixel_RGBA_8888_00111360;
            }
            if (type == 0x8033) {
              return PTR__gleInsertPixel_RGBA_4444_00111370;
            }
          }
          else {
            if (type == 0x8366) {
              return PTR__gleInsertPixel_RGBA_1555Rev_00111364;
            }
            if (type < 0x8367) {
              if (type == 0x8365) {
                return PTR__gleInsertPixel_RGBA_4444Rev_0011136c;
              }
            }
            else if (type == 0x8367) {
              return PTR__gleInsertPixel_RGBA_8888Rev_0011135c;
            }
          }
        }
        return PTR__gleInsertPixel_RGBA_2101010Rev_00111354;
      }
    }
    else {
      if (format == 0x80e0) {
        switch(type) {
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
      if (format < 0x80e1) {
        if (format == 0x8000) {
          switch(type) {
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
      else if (format == 0x80e1) {
        if (type == 0x1406) {
          return PTR__gleInsertPixel_BGRA_EXT_Float_0011131c;
        }
        if (type < 0x1407) {
          if (type == 0x1402) {
            return PTR__gleInsertPixel_BGRA_EXT_Short_0011132c;
          }
          if (0x1402 < type) {
            if (type == 0x1404) {
              return PTR__gleInsertPixel_BGRA_EXT_Int_00111324;
            }
            if (0x1404 < type) {
              return PTR__gleInsertPixel_BGRA_EXT_Uint_00111320;
            }
            return PTR__gleInsertPixel_BGRA_EXT_Ushort_00111328;
          }
          if (type == 0x1400) {
            return PTR__gleInsertPixel_BGRA_EXT_Byte_00111334;
          }
          if (type == 0x1401) {
            return PTR__gleInsertPixel_BGRA_EXT_Ubyte_00111330;
          }
        }
        else {
          if (type == 0x8036) {
            return PTR__gleInsertPixel_BGRA_1010102_00111300;
          }
          if (type < 0x8037) {
            if (type == 0x8034) {
              return PTR__gleInsertPixel_BGRA_5551_00111310;
            }
            if (0x8034 < type) {
              return PTR__gleInsertPixel_BGRA_8888_00111308;
            }
            if (type == 0x8033) {
              return PTR__gleInsertPixel_BGRA_4444_00111318;
            }
          }
          else {
            if (type == 0x8366) {
              return PTR__gleInsertPixel_BGRA_1555Rev_0011130c;
            }
            if (type < 0x8367) {
              if (type == 0x8365) {
                return PTR__gleInsertPixel_BGRA_4444Rev_00111314;
              }
            }
            else if (type == 0x8367) {
              return PTR__gleInsertPixel_BGRA_8888Rev_00111304;
            }
          }
        }
        return PTR__gleInsertPixel_BGRA_2101010Rev_001112fc;
      }
    }
  }
  switch(type) {
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
void _gleInsertPixel_RGBA_Byte(pixel, dst)
  int pixel;
  undefined1 *dst;
{
  float channelScale;
  
  channelScale = FLOAT_00108f6c;
  *dst = (char)(int)(*(float *)(pixel + 4) * FLOAT_00108f6c);
  dst[1] = (char)(int)(*(float *)(pixel + 8) * channelScale);
  dst[2] = (char)(int)(*(float *)(pixel + 0xc) * channelScale);
  dst[3] = (char)(int)(*(float *)(pixel + 0x10) * channelScale);
  return;
}

/* _gleInsertPixel_RGBA_Ubyte @ 0xe7f60 (124 bytes) */
void _gleInsertPixel_RGBA_Ubyte(pixel, dst)
  int pixel;
  undefined1 *dst;
{
  float channelScale;
  
  channelScale = FLOAT_00108f70;
  *dst = (char)(int)(*(float *)(pixel + 4) * FLOAT_00108f70);
  dst[1] = (char)(int)(*(float *)(pixel + 8) * channelScale);
  dst[2] = (char)(int)(*(float *)(pixel + 0xc) * channelScale);
  dst[3] = (char)(int)(*(float *)(pixel + 0x10) * channelScale);
  return;
}

/* _gleInsertPixel_RGBA_Short @ 0xe7fdc (124 bytes) */
void _gleInsertPixel_RGBA_Short(pixel, dst)
  int pixel;
  undefined2 *dst;
{
  float channelScale;
  
  channelScale = FLOAT_00108f74;
  *dst = (short)(int)(*(float *)(pixel + 4) * FLOAT_00108f74);
  dst[1] = (short)(int)(*(float *)(pixel + 8) * channelScale);
  dst[2] = (short)(int)(*(float *)(pixel + 0xc) * channelScale);
  dst[3] = (short)(int)(*(float *)(pixel + 0x10) * channelScale);
  return;
}

/* _gleInsertPixel_RGBA_Ushort @ 0xe8058 (124 bytes) */
void _gleInsertPixel_RGBA_Ushort(pixel, dst)
  int pixel;
  undefined2 *dst;
{
  float channelScale;
  
  channelScale = FLOAT_00108ea0;
  *dst = (short)(int)(*(float *)(pixel + 4) * FLOAT_00108ea0);
  dst[1] = (short)(int)(*(float *)(pixel + 8) * channelScale);
  dst[2] = (short)(int)(*(float *)(pixel + 0xc) * channelScale);
  dst[3] = (short)(int)(*(float *)(pixel + 0x10) * channelScale);
  return;
}

/* _gleInsertPixel_RGBA_Int @ 0xe80d4 (124 bytes) */
void _gleInsertPixel_RGBA_Int(int pixel,int *dst,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  double scaledChannel;
  
  scaledChannel = DOUBLE_00108d90;
  *dst = (int)((double)*(float *)(pixel + 4) * DOUBLE_00108d90);
  dst[1] = (int)((double)*(float *)(pixel + 8) * scaledChannel);
  dst[2] = (int)((double)*(float *)(pixel + 0xc) * scaledChannel);
  dst[3] = (int)((double)*(float *)(pixel + 0x10) * scaledChannel);
  return;
}

/* _gleInsertPixel_RGBA_Uint @ 0xe8150 (312 bytes) */
void _gleInsertPixel_RGBA_Uint(pixel, dst)
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

/* _gleInsertPixel_RGBA_Float @ 0xe8288 (36 bytes) */
void _gleInsertPixel_RGBA_Float(pixel, dst)
  int pixel;
  undefined4 *dst;
{
  *dst = *(undefined4 *)(pixel + 4);
  dst[1] = *(undefined4 *)(pixel + 8);
  dst[2] = *(undefined4 *)(pixel + 0xc);
  dst[3] = *(undefined4 *)(pixel + 0x10);
  return;
}

/* _gleInsertPixel_RGBA_4444 @ 0xe82ac (140 bytes) */
void _gleInsertPixel_RGBA_4444(pixel, dst)
  int pixel;
  ushort *dst;
{
  *dst = (ushort)(int)(*(float *)(pixel + 4) * FLOAT_00108ea0) & 0xf000 |
             (ushort)((uint)(int)(*(float *)(pixel + 8) * FLOAT_00108ea0) >> 4) & 0xf00 |
             (ushort)((uint)(int)(*(float *)(pixel + 0xc) * FLOAT_00108ea0) >> 8) & 0xf0 |
             (ushort)((uint)(int)(*(float *)(pixel + 0x10) * FLOAT_00108ea0) >> 0xc) & 0xf;
  return;
}

/* _gleInsertPixel_RGBA_4444Rev @ 0xe8338 (140 bytes) */
void _gleInsertPixel_RGBA_4444Rev(pixel, dst)
  int pixel;
  ushort *dst;
{
  *dst = (ushort)(int)(*(float *)(pixel + 0x10) * FLOAT_00108ea0) & 0xf000 |
             (ushort)((uint)(int)(*(float *)(pixel + 0xc) * FLOAT_00108ea0) >> 4) & 0xf00 |
             (ushort)((uint)(int)(*(float *)(pixel + 8) * FLOAT_00108ea0) >> 8) & 0xf0 |
             (ushort)((uint)(int)(*(float *)(pixel + 4) * FLOAT_00108ea0) >> 0xc) & 0xf;
  return;
}

/* _gleInsertPixel_RGBA_5551 @ 0xe83c4 (140 bytes) */
void _gleInsertPixel_RGBA_5551(pixel, dst)
  int pixel;
  ushort *dst;
{
  *dst = (ushort)(int)(*(float *)(pixel + 4) * FLOAT_00108ea0) & 0xf800 |
             (ushort)((uint)(int)(*(float *)(pixel + 8) * FLOAT_00108ea0) >> 5) & 0x7c0 |
             (ushort)((uint)(int)(*(float *)(pixel + 0xc) * FLOAT_00108ea0) >> 10) & 0x3e |
             (ushort)((uint)(int)(*(float *)(pixel + 0x10) * FLOAT_00108ea0) >> 0xf) & 1;
  return;
}

/* _gleInsertPixel_RGBA_1555Rev @ 0xe8450 (140 bytes) */
void _gleInsertPixel_RGBA_1555Rev(pixel, dst)
  int pixel;
  ushort *dst;
{
  *dst = (ushort)(int)(*(float *)(pixel + 0x10) * FLOAT_00108ea0) & 0x8000 |
             (ushort)((uint)(int)(*(float *)(pixel + 0xc) * FLOAT_00108ea0) >> 1) & 0x7c00 |
             (ushort)((uint)(int)(*(float *)(pixel + 8) * FLOAT_00108ea0) >> 6) & 0x3e0 |
             (ushort)((uint)(int)(*(float *)(pixel + 4) * FLOAT_00108ea0) >> 0xb) & 0x1f;
  return;
}

/* _gleInsertPixel_RGBA_8888 @ 0xe84dc (124 bytes) */
void _gleInsertPixel_RGBA_8888(pixel, dst)
  int pixel;
  undefined1 *dst;
{
  float channelScale;
  
  channelScale = FLOAT_00108f70;
  *dst = (char)(int)(*(float *)(pixel + 4) * FLOAT_00108f70);
  dst[1] = (char)(int)(*(float *)(pixel + 8) * channelScale);
  dst[2] = (char)(int)(*(float *)(pixel + 0xc) * channelScale);
  dst[3] = (char)(int)(*(float *)(pixel + 0x10) * channelScale);
  return;
}

/* _gleInsertPixel_RGBA_8888Rev @ 0xe8558 (124 bytes) */
void _gleInsertPixel_RGBA_8888Rev(pixel, dst)
  int pixel;
  undefined1 *dst;
{
  float channelScale;
  
  channelScale = FLOAT_00108f70;
  *dst = (char)(int)(*(float *)(pixel + 0x10) * FLOAT_00108f70);
  dst[1] = (char)(int)(*(float *)(pixel + 0xc) * channelScale);
  dst[2] = (char)(int)(*(float *)(pixel + 8) * channelScale);
  dst[3] = (char)(int)(*(float *)(pixel + 4) * channelScale);
  return;
}

/* _gleInsertPixel_RGBA_1010102 @ 0xe85d4 (328 bytes) */
void _gleInsertPixel_RGBA_1010102(pixel, dst)
  int pixel;
  uint *dst;
{
  uint redBits;
  uint greenBits;
  uint blueBits;
  uint alphaBits;
  double scaledChannel;
  
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
  scaledChannel = (double)*(float *)(pixel + 0x10) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= scaledChannel) {
    alphaBits = (int)(scaledChannel - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    alphaBits = (uint)(int)scaledChannel;
  }
  *dst = redBits & 0xffc00000 | greenBits >> 10 & 0x3ff000 | blueBits >> 0x14 & 0xffc | alphaBits >> 0x1e;
  return;
}

/* _gleInsertPixel_RGBA_2101010Rev @ 0xe871c (328 bytes) */
void _gleInsertPixel_RGBA_2101010Rev(pixel, dst)
  int pixel;
  uint *dst;
{
  uint alphaBits;
  uint blueBits;
  uint greenBits;
  uint redBits;
  double scaledChannel;
  
  scaledChannel = (double)*(float *)(pixel + 0x10) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= scaledChannel) {
    alphaBits = (int)(scaledChannel - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    alphaBits = (uint)(int)scaledChannel;
  }
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
  *dst = alphaBits & 0xc0000000 | blueBits >> 2 & 0x3ff00000 | greenBits >> 0xc & 0xffc00 | redBits >> 0x16;
  return;
}

/* _gleInsertPixel_ABGR_EXT_Byte @ 0xe8864 (124 bytes) */
void _gleInsertPixel_ABGR_EXT_Byte(pixel, dst)
  int pixel;
  undefined1 *dst;
{
  float channelScale;
  
  channelScale = FLOAT_00108f6c;
  dst[3] = (char)(int)(*(float *)(pixel + 4) * FLOAT_00108f6c);
  dst[2] = (char)(int)(*(float *)(pixel + 8) * channelScale);
  dst[1] = (char)(int)(*(float *)(pixel + 0xc) * channelScale);
  *dst = (char)(int)(*(float *)(pixel + 0x10) * channelScale);
  return;
}

/* _gleInsertPixel_ABGR_EXT_Ubyte @ 0xe88e0 (124 bytes) */
void _gleInsertPixel_ABGR_EXT_Ubyte(pixel, dst)
  int pixel;
  undefined1 *dst;
{
  float channelScale;
  
  channelScale = FLOAT_00108f70;
  dst[3] = (char)(int)(*(float *)(pixel + 4) * FLOAT_00108f70);
  dst[2] = (char)(int)(*(float *)(pixel + 8) * channelScale);
  dst[1] = (char)(int)(*(float *)(pixel + 0xc) * channelScale);
  *dst = (char)(int)(*(float *)(pixel + 0x10) * channelScale);
  return;
}

/* _gleInsertPixel_ABGR_EXT_Short @ 0xe895c (124 bytes) */
void _gleInsertPixel_ABGR_EXT_Short(pixel, dst)
  int pixel;
  undefined2 *dst;
{
  float channelScale;
  
  channelScale = FLOAT_00108f74;
  dst[3] = (short)(int)(*(float *)(pixel + 4) * FLOAT_00108f74);
  dst[2] = (short)(int)(*(float *)(pixel + 8) * channelScale);
  dst[1] = (short)(int)(*(float *)(pixel + 0xc) * channelScale);
  *dst = (short)(int)(*(float *)(pixel + 0x10) * channelScale);
  return;
}

