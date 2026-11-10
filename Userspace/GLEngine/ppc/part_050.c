#include "decls.h"

/* _gleInsertPixel_ABGR_EXT_Ushort @ 0xe89d8 (124 bytes) */
void _gleInsertPixel_ABGR_EXT_Ushort(param_1, param_2)
  int param_1;
  undefined2 *param_2;
{
  float fVar1;
  
  fVar1 = FLOAT_00108ea0;
  param_2[3] = (short)(int)(*(float *)(param_1 + 4) * FLOAT_00108ea0);
  param_2[2] = (short)(int)(*(float *)(param_1 + 8) * fVar1);
  param_2[1] = (short)(int)(*(float *)(param_1 + 0xc) * fVar1);
  *param_2 = (short)(int)(*(float *)(param_1 + 0x10) * fVar1);
  return;
}

/* _gleInsertPixel_ABGR_EXT_Int @ 0xe8a54 (124 bytes) */
void _gleInsertPixel_ABGR_EXT_Int(int param_1,int *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  double dVar1;
  
  dVar1 = DOUBLE_00108d90;
  param_2[3] = (int)((double)*(float *)(param_1 + 4) * DOUBLE_00108d90);
  param_2[2] = (int)((double)*(float *)(param_1 + 8) * dVar1);
  param_2[1] = (int)((double)*(float *)(param_1 + 0xc) * dVar1);
  *param_2 = (int)((double)*(float *)(param_1 + 0x10) * dVar1);
  return;
}

/* _gleInsertPixel_ABGR_EXT_Uint @ 0xe8ad0 (312 bytes) */
void _gleInsertPixel_ABGR_EXT_Uint(param_1, param_2)
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
  param_2[3] = uVar1;
  dVar2 = (double)*(float *)(param_1 + 8) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= dVar2) {
    uVar1 = (int)(dVar2 - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    uVar1 = (uint)(int)dVar2;
  }
  param_2[2] = uVar1;
  dVar2 = (double)*(float *)(param_1 + 0xc) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= dVar2) {
    uVar1 = (int)(dVar2 - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    uVar1 = (uint)(int)dVar2;
  }
  param_2[1] = uVar1;
  dVar2 = (double)*(float *)(param_1 + 0x10) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= dVar2) {
    uVar1 = (int)(dVar2 - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    uVar1 = (uint)(int)dVar2;
  }
  *param_2 = uVar1;
  return;
}

/* _gleInsertPixel_ABGR_EXT_Float @ 0xe8c08 (36 bytes) */
void _gleInsertPixel_ABGR_EXT_Float(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  param_2[3] = *(undefined4 *)(param_1 + 4);
  param_2[2] = *(undefined4 *)(param_1 + 8);
  param_2[1] = *(undefined4 *)(param_1 + 0xc);
  *param_2 = *(undefined4 *)(param_1 + 0x10);
  return;
}

/* _gleInsertPixel_BGRA_EXT_Byte @ 0xe8c2c (124 bytes) */
void _gleInsertPixel_BGRA_EXT_Byte(param_1, param_2)
  int param_1;
  undefined1 *param_2;
{
  float fVar1;
  
  fVar1 = FLOAT_00108f6c;
  param_2[2] = (char)(int)(*(float *)(param_1 + 4) * FLOAT_00108f6c);
  param_2[1] = (char)(int)(*(float *)(param_1 + 8) * fVar1);
  *param_2 = (char)(int)(*(float *)(param_1 + 0xc) * fVar1);
  param_2[3] = (char)(int)(*(float *)(param_1 + 0x10) * fVar1);
  return;
}

/* _gleInsertPixel_BGRA_EXT_Ubyte @ 0xe8ca8 (124 bytes) */
void _gleInsertPixel_BGRA_EXT_Ubyte(param_1, param_2)
  int param_1;
  undefined1 *param_2;
{
  float fVar1;
  
  fVar1 = FLOAT_00108f70;
  param_2[2] = (char)(int)(*(float *)(param_1 + 4) * FLOAT_00108f70);
  param_2[1] = (char)(int)(*(float *)(param_1 + 8) * fVar1);
  *param_2 = (char)(int)(*(float *)(param_1 + 0xc) * fVar1);
  param_2[3] = (char)(int)(*(float *)(param_1 + 0x10) * fVar1);
  return;
}

/* _gleInsertPixel_BGRA_EXT_Short @ 0xe8d24 (124 bytes) */
void _gleInsertPixel_BGRA_EXT_Short(param_1, param_2)
  int param_1;
  undefined2 *param_2;
{
  float fVar1;
  
  fVar1 = FLOAT_00108f74;
  param_2[2] = (short)(int)(*(float *)(param_1 + 4) * FLOAT_00108f74);
  param_2[1] = (short)(int)(*(float *)(param_1 + 8) * fVar1);
  *param_2 = (short)(int)(*(float *)(param_1 + 0xc) * fVar1);
  param_2[3] = (short)(int)(*(float *)(param_1 + 0x10) * fVar1);
  return;
}

/* _gleInsertPixel_BGRA_EXT_Ushort @ 0xe8da0 (124 bytes) */
void _gleInsertPixel_BGRA_EXT_Ushort(param_1, param_2)
  int param_1;
  undefined2 *param_2;
{
  float fVar1;
  
  fVar1 = FLOAT_00108ea0;
  param_2[2] = (short)(int)(*(float *)(param_1 + 4) * FLOAT_00108ea0);
  param_2[1] = (short)(int)(*(float *)(param_1 + 8) * fVar1);
  *param_2 = (short)(int)(*(float *)(param_1 + 0xc) * fVar1);
  param_2[3] = (short)(int)(*(float *)(param_1 + 0x10) * fVar1);
  return;
}

/* _gleInsertPixel_BGRA_EXT_Int @ 0xe8e1c (124 bytes) */
void _gleInsertPixel_BGRA_EXT_Int(int param_1,int *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  double dVar1;
  
  dVar1 = DOUBLE_00108d90;
  param_2[2] = (int)((double)*(float *)(param_1 + 4) * DOUBLE_00108d90);
  param_2[1] = (int)((double)*(float *)(param_1 + 8) * dVar1);
  *param_2 = (int)((double)*(float *)(param_1 + 0xc) * dVar1);
  param_2[3] = (int)((double)*(float *)(param_1 + 0x10) * dVar1);
  return;
}

/* _gleInsertPixel_BGRA_EXT_Uint @ 0xe8e98 (312 bytes) */
void _gleInsertPixel_BGRA_EXT_Uint(param_1, param_2)
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
  param_2[2] = uVar1;
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
  *param_2 = uVar1;
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

/* _gleInsertPixel_BGRA_EXT_Float @ 0xe8fd0 (36 bytes) */
void _gleInsertPixel_BGRA_EXT_Float(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  param_2[2] = *(undefined4 *)(param_1 + 4);
  param_2[1] = *(undefined4 *)(param_1 + 8);
  *param_2 = *(undefined4 *)(param_1 + 0xc);
  param_2[3] = *(undefined4 *)(param_1 + 0x10);
  return;
}

/* _gleInsertPixel_BGRA_4444 @ 0xe8ff4 (140 bytes) */
void _gleInsertPixel_BGRA_4444(param_1, param_2)
  int param_1;
  ushort *param_2;
{
  *param_2 = (ushort)(int)(*(float *)(param_1 + 0xc) * FLOAT_00108ea0) & 0xf000 |
             (ushort)((uint)(int)(*(float *)(param_1 + 8) * FLOAT_00108ea0) >> 4) & 0xf00 |
             (ushort)((uint)(int)(*(float *)(param_1 + 4) * FLOAT_00108ea0) >> 8) & 0xf0 |
             (ushort)((uint)(int)(*(float *)(param_1 + 0x10) * FLOAT_00108ea0) >> 0xc) & 0xf;
  return;
}

/* _gleInsertPixel_BGRA_4444Rev @ 0xe9080 (140 bytes) */
void _gleInsertPixel_BGRA_4444Rev(param_1, param_2)
  int param_1;
  ushort *param_2;
{
  *param_2 = (ushort)(int)(*(float *)(param_1 + 0x10) * FLOAT_00108ea0) & 0xf000 |
             (ushort)((uint)(int)(*(float *)(param_1 + 4) * FLOAT_00108ea0) >> 4) & 0xf00 |
             (ushort)((uint)(int)(*(float *)(param_1 + 8) * FLOAT_00108ea0) >> 8) & 0xf0 |
             (ushort)((uint)(int)(*(float *)(param_1 + 0xc) * FLOAT_00108ea0) >> 0xc) & 0xf;
  return;
}

/* _gleInsertPixel_BGRA_5551 @ 0xe910c (140 bytes) */
void _gleInsertPixel_BGRA_5551(param_1, param_2)
  int param_1;
  ushort *param_2;
{
  *param_2 = (ushort)(int)(*(float *)(param_1 + 0xc) * FLOAT_00108ea0) & 0xf800 |
             (ushort)((uint)(int)(*(float *)(param_1 + 8) * FLOAT_00108ea0) >> 5) & 0x7c0 |
             (ushort)((uint)(int)(*(float *)(param_1 + 4) * FLOAT_00108ea0) >> 10) & 0x3e |
             (ushort)((uint)(int)(*(float *)(param_1 + 0x10) * FLOAT_00108ea0) >> 0xf) & 1;
  return;
}

/* _gleInsertPixel_BGRA_1555Rev @ 0xe9198 (140 bytes) */
void _gleInsertPixel_BGRA_1555Rev(param_1, param_2)
  int param_1;
  ushort *param_2;
{
  *param_2 = (ushort)(int)(*(float *)(param_1 + 0x10) * FLOAT_00108ea0) & 0x8000 |
             (ushort)((uint)(int)(*(float *)(param_1 + 4) * FLOAT_00108ea0) >> 1) & 0x7c00 |
             (ushort)((uint)(int)(*(float *)(param_1 + 8) * FLOAT_00108ea0) >> 6) & 0x3e0 |
             (ushort)((uint)(int)(*(float *)(param_1 + 0xc) * FLOAT_00108ea0) >> 0xb) & 0x1f;
  return;
}

/* _gleInsertPixel_BGRA_8888 @ 0xe9224 (124 bytes) */
void _gleInsertPixel_BGRA_8888(param_1, param_2)
  int param_1;
  undefined1 *param_2;
{
  float fVar1;
  
  fVar1 = FLOAT_00108f70;
  *param_2 = (char)(int)(*(float *)(param_1 + 0xc) * FLOAT_00108f70);
  param_2[1] = (char)(int)(*(float *)(param_1 + 8) * fVar1);
  param_2[2] = (char)(int)(*(float *)(param_1 + 4) * fVar1);
  param_2[3] = (char)(int)(*(float *)(param_1 + 0x10) * fVar1);
  return;
}

/* _gleInsertPixel_BGRA_8888Rev @ 0xe92a0 (124 bytes) */
void _gleInsertPixel_BGRA_8888Rev(param_1, param_2)
  int param_1;
  undefined1 *param_2;
{
  float fVar1;
  
  fVar1 = FLOAT_00108f70;
  *param_2 = (char)(int)(*(float *)(param_1 + 0x10) * FLOAT_00108f70);
  param_2[1] = (char)(int)(*(float *)(param_1 + 4) * fVar1);
  param_2[2] = (char)(int)(*(float *)(param_1 + 8) * fVar1);
  param_2[3] = (char)(int)(*(float *)(param_1 + 0xc) * fVar1);
  return;
}

/* _gleInsertPixel_BGRA_1010102 @ 0xe931c (328 bytes) */
void _gleInsertPixel_BGRA_1010102(param_1, param_2)
  int param_1;
  uint *param_2;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  double dVar5;
  
  dVar5 = (double)*(float *)(param_1 + 0xc) * DOUBLE_00108da8;
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
  dVar5 = (double)*(float *)(param_1 + 4) * DOUBLE_00108da8;
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

/* _gleInsertPixel_BGRA_2101010Rev @ 0xe9464 (328 bytes) */
void _gleInsertPixel_BGRA_2101010Rev(param_1, param_2)
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
  dVar5 = (double)*(float *)(param_1 + 4) * DOUBLE_00108da8;
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
  dVar5 = (double)*(float *)(param_1 + 0xc) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= dVar5) {
    uVar4 = (int)(dVar5 - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    uVar4 = (uint)(int)dVar5;
  }
  *param_2 = uVar1 & 0xc0000000 | uVar2 >> 2 & 0x3ff00000 | uVar3 >> 0xc & 0xffc00 | uVar4 >> 0x16;
  return;
}

/* _gleInsertPixel_BGR_EXT_Byte @ 0xe95ac (100 bytes) */
void _gleInsertPixel_BGR_EXT_Byte(param_1, param_2)
  int param_1;
  undefined1 *param_2;
{
  float fVar1;
  
  fVar1 = FLOAT_00108f6c;
  param_2[2] = (char)(int)(*(float *)(param_1 + 4) * FLOAT_00108f6c);
  param_2[1] = (char)(int)(*(float *)(param_1 + 8) * fVar1);
  *param_2 = (char)(int)(*(float *)(param_1 + 0xc) * fVar1);
  return;
}

/* _gleInsertPixel_BGR_EXT_Ubyte @ 0xe9610 (100 bytes) */
void _gleInsertPixel_BGR_EXT_Ubyte(param_1, param_2)
  int param_1;
  undefined1 *param_2;
{
  float fVar1;
  
  fVar1 = FLOAT_00108f70;
  param_2[2] = (char)(int)(*(float *)(param_1 + 4) * FLOAT_00108f70);
  param_2[1] = (char)(int)(*(float *)(param_1 + 8) * fVar1);
  *param_2 = (char)(int)(*(float *)(param_1 + 0xc) * fVar1);
  return;
}

/* _gleInsertPixel_BGR_EXT_Short @ 0xe9674 (100 bytes) */
void _gleInsertPixel_BGR_EXT_Short(param_1, param_2)
  int param_1;
  undefined2 *param_2;
{
  float fVar1;
  
  fVar1 = FLOAT_00108f74;
  param_2[2] = (short)(int)(*(float *)(param_1 + 4) * FLOAT_00108f74);
  param_2[1] = (short)(int)(*(float *)(param_1 + 8) * fVar1);
  *param_2 = (short)(int)(*(float *)(param_1 + 0xc) * fVar1);
  return;
}

/* _gleInsertPixel_BGR_EXT_Ushort @ 0xe96d8 (100 bytes) */
void _gleInsertPixel_BGR_EXT_Ushort(param_1, param_2)
  int param_1;
  undefined2 *param_2;
{
  float fVar1;
  
  fVar1 = FLOAT_00108ea0;
  param_2[2] = (short)(int)(*(float *)(param_1 + 4) * FLOAT_00108ea0);
  param_2[1] = (short)(int)(*(float *)(param_1 + 8) * fVar1);
  *param_2 = (short)(int)(*(float *)(param_1 + 0xc) * fVar1);
  return;
}

/* _gleInsertPixel_BGR_EXT_Int @ 0xe973c (100 bytes) */
void _gleInsertPixel_BGR_EXT_Int(int param_1,int *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  double dVar1;
  
  dVar1 = DOUBLE_00108d90;
  param_2[2] = (int)((double)*(float *)(param_1 + 4) * DOUBLE_00108d90);
  param_2[1] = (int)((double)*(float *)(param_1 + 8) * dVar1);
  *param_2 = (int)((double)*(float *)(param_1 + 0xc) * dVar1);
  return;
}

/* _gleInsertPixel_BGR_EXT_Uint @ 0xe97a0 (240 bytes) */
void _gleInsertPixel_BGR_EXT_Uint(param_1, param_2)
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
  param_2[2] = uVar1;
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
  *param_2 = uVar1;
  return;
}

/* _gleInsertPixel_BGR_EXT_Float @ 0xe9890 (28 bytes) */
void _gleInsertPixel_BGR_EXT_Float(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  param_2[2] = *(undefined4 *)(param_1 + 4);
  param_2[1] = *(undefined4 *)(param_1 + 8);
  *param_2 = *(undefined4 *)(param_1 + 0xc);
  return;
}

/* _gleInsertPixel_RGB_Byte @ 0xe98ac (100 bytes) */
void _gleInsertPixel_RGB_Byte(param_1, param_2)
  int param_1;
  undefined1 *param_2;
{
  float fVar1;
  
  fVar1 = FLOAT_00108f6c;
  *param_2 = (char)(int)(*(float *)(param_1 + 4) * FLOAT_00108f6c);
  param_2[1] = (char)(int)(*(float *)(param_1 + 8) * fVar1);
  param_2[2] = (char)(int)(*(float *)(param_1 + 0xc) * fVar1);
  return;
}

/* _gleInsertPixel_RGB_Ubyte @ 0xe9910 (100 bytes) */
void _gleInsertPixel_RGB_Ubyte(param_1, param_2)
  int param_1;
  undefined1 *param_2;
{
  float fVar1;
  
  fVar1 = FLOAT_00108f70;
  *param_2 = (char)(int)(*(float *)(param_1 + 4) * FLOAT_00108f70);
  param_2[1] = (char)(int)(*(float *)(param_1 + 8) * fVar1);
  param_2[2] = (char)(int)(*(float *)(param_1 + 0xc) * fVar1);
  return;
}

/* _gleInsertPixel_RGB_Short @ 0xe9974 (100 bytes) */
void _gleInsertPixel_RGB_Short(param_1, param_2)
  int param_1;
  undefined2 *param_2;
{
  float fVar1;
  
  fVar1 = FLOAT_00108f74;
  *param_2 = (short)(int)(*(float *)(param_1 + 4) * FLOAT_00108f74);
  param_2[1] = (short)(int)(*(float *)(param_1 + 8) * fVar1);
  param_2[2] = (short)(int)(*(float *)(param_1 + 0xc) * fVar1);
  return;
}

/* _gleInsertPixel_RGB_Ushort @ 0xe99d8 (100 bytes) */
void _gleInsertPixel_RGB_Ushort(param_1, param_2)
  int param_1;
  undefined2 *param_2;
{
  float fVar1;
  
  fVar1 = FLOAT_00108ea0;
  *param_2 = (short)(int)(*(float *)(param_1 + 4) * FLOAT_00108ea0);
  param_2[1] = (short)(int)(*(float *)(param_1 + 8) * fVar1);
  param_2[2] = (short)(int)(*(float *)(param_1 + 0xc) * fVar1);
  return;
}

/* _gleInsertPixel_RGB_Int @ 0xe9a3c (100 bytes) */
void _gleInsertPixel_RGB_Int(int param_1,int *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  double dVar1;
  
  dVar1 = DOUBLE_00108d90;
  *param_2 = (int)((double)*(float *)(param_1 + 4) * DOUBLE_00108d90);
  param_2[1] = (int)((double)*(float *)(param_1 + 8) * dVar1);
  param_2[2] = (int)((double)*(float *)(param_1 + 0xc) * dVar1);
  return;
}

/* _gleInsertPixel_RGB_Uint @ 0xe9aa0 (240 bytes) */
void _gleInsertPixel_RGB_Uint(param_1, param_2)
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
  return;
}

/* _gleInsertPixel_RGB_Float @ 0xe9b90 (28 bytes) */
void _gleInsertPixel_RGB_Float(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *param_2 = *(undefined4 *)(param_1 + 4);
  param_2[1] = *(undefined4 *)(param_1 + 8);
  param_2[2] = *(undefined4 *)(param_1 + 0xc);
  return;
}

/* _gleInsertPixel_RGB_332 @ 0xe9bac (112 bytes) */
void _gleInsertPixel_RGB_332(param_1, param_2)
  int param_1;
  byte *param_2;
{
  *param_2 = (byte)(int)(*(float *)(param_1 + 4) * FLOAT_00108f70) & 0xe0 |
             (byte)((uint)(int)(*(float *)(param_1 + 8) * FLOAT_00108f70) >> 3) & 0x1c |
             (byte)((uint)(int)(*(float *)(param_1 + 0xc) * FLOAT_00108f70) >> 6) & 3;
  return;
}

/* _gleInsertPixel_RGB_233Rev @ 0xe9c1c (112 bytes) */
void _gleInsertPixel_RGB_233Rev(param_1, param_2)
  int param_1;
  byte *param_2;
{
  *param_2 = (byte)(int)(*(float *)(param_1 + 0xc) * FLOAT_00108f70) & 0xc0 |
             (byte)((uint)(int)(*(float *)(param_1 + 8) * FLOAT_00108f70) >> 2) & 0x38 |
             (byte)((uint)(int)(*(float *)(param_1 + 4) * FLOAT_00108f70) >> 5) & 7;
  return;
}

/* _gleInsertPixel_RGB_565 @ 0xe9c8c (112 bytes) */
void _gleInsertPixel_RGB_565(param_1, param_2)
  int param_1;
  ushort *param_2;
{
  *param_2 = (ushort)(int)(*(float *)(param_1 + 4) * FLOAT_00108ea0) & 0xf800 |
             (ushort)((uint)(int)(*(float *)(param_1 + 8) * FLOAT_00108ea0) >> 5) & 0x7e0 |
             (ushort)((uint)(int)(*(float *)(param_1 + 0xc) * FLOAT_00108ea0) >> 0xb) & 0x1f;
  return;
}

/* _gleInsertPixel_RGB_565Rev @ 0xe9cfc (112 bytes) */
void _gleInsertPixel_RGB_565Rev(param_1, param_2)
  int param_1;
  ushort *param_2;
{
  *param_2 = (ushort)(int)(*(float *)(param_1 + 0xc) * FLOAT_00108ea0) & 0xf800 |
             (ushort)((uint)(int)(*(float *)(param_1 + 8) * FLOAT_00108ea0) >> 5) & 0x7e0 |
             (ushort)((uint)(int)(*(float *)(param_1 + 4) * FLOAT_00108ea0) >> 0xb) & 0x1f;
  return;
}

/* _gleInsertPixel_R_Byte @ 0xe9d6c (52 bytes) */
void _gleInsertPixel_R_Byte(param_1, param_2)
  int param_1;
  undefined1 *param_2;
{
  *param_2 = (char)(int)(*(float *)(param_1 + 4) * FLOAT_00108f6c);
  return;
}

/* _gleInsertPixel_R_Ubyte @ 0xe9da0 (52 bytes) */
void _gleInsertPixel_R_Ubyte(param_1, param_2)
  int param_1;
  undefined1 *param_2;
{
  *param_2 = (char)(int)(*(float *)(param_1 + 4) * FLOAT_00108f70);
  return;
}

/* _gleInsertPixel_R_Short @ 0xe9dd4 (52 bytes) */
void _gleInsertPixel_R_Short(param_1, param_2)
  int param_1;
  undefined2 *param_2;
{
  *param_2 = (short)(int)(*(float *)(param_1 + 4) * FLOAT_00108f74);
  return;
}

/* _gleInsertPixel_R_Ushort @ 0xe9e08 (52 bytes) */
void _gleInsertPixel_R_Ushort(param_1, param_2)
  int param_1;
  undefined2 *param_2;
{
  *param_2 = (short)(int)(*(float *)(param_1 + 4) * FLOAT_00108ea0);
  return;
}

/* _gleInsertPixel_R_Int @ 0xe9e3c (52 bytes) */
void _gleInsertPixel_R_Int(param_1, param_2)
  int param_1;
  int *param_2;
{
  *param_2 = (int)((double)*(float *)(param_1 + 4) * DOUBLE_00108d90);
  return;
}

/* _gleInsertPixel_R_Uint @ 0xe9e70 (96 bytes) */
void _gleInsertPixel_R_Uint(param_1, param_2)
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
  return;
}

/* _gleInsertPixel_R_Float @ 0xe9ed0 (12 bytes) */
void _gleInsertPixel_R_Float(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *param_2 = *(undefined4 *)(param_1 + 4);
  return;
}

/* _gleInsertPixel_G_Byte @ 0xe9edc (52 bytes) */
void _gleInsertPixel_G_Byte(param_1, param_2)
  int param_1;
  undefined1 *param_2;
{
  *param_2 = (char)(int)(*(float *)(param_1 + 8) * FLOAT_00108f6c);
  return;
}

/* _gleInsertPixel_G_Ubyte @ 0xe9f10 (52 bytes) */
void _gleInsertPixel_G_Ubyte(param_1, param_2)
  int param_1;
  undefined1 *param_2;
{
  *param_2 = (char)(int)(*(float *)(param_1 + 8) * FLOAT_00108f70);
  return;
}

/* _gleInsertPixel_G_Short @ 0xe9f44 (52 bytes) */
void _gleInsertPixel_G_Short(param_1, param_2)
  int param_1;
  undefined2 *param_2;
{
  *param_2 = (short)(int)(*(float *)(param_1 + 8) * FLOAT_00108f74);
  return;
}

/* _gleInsertPixel_G_Ushort @ 0xe9f78 (52 bytes) */
void _gleInsertPixel_G_Ushort(param_1, param_2)
  int param_1;
  undefined2 *param_2;
{
  *param_2 = (short)(int)(*(float *)(param_1 + 8) * FLOAT_00108ea0);
  return;
}

/* _gleInsertPixel_G_Int @ 0xe9fac (52 bytes) */
void _gleInsertPixel_G_Int(param_1, param_2)
  int param_1;
  int *param_2;
{
  *param_2 = (int)((double)*(float *)(param_1 + 8) * DOUBLE_00108d90);
  return;
}

/* _gleInsertPixel_G_Uint @ 0xe9fe0 (96 bytes) */
void _gleInsertPixel_G_Uint(param_1, param_2)
  int param_1;
  uint *param_2;
{
  uint uVar1;
  double dVar2;
  
  dVar2 = (double)*(float *)(param_1 + 8) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= dVar2) {
    uVar1 = (int)(dVar2 - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    uVar1 = (uint)(int)dVar2;
  }
  *param_2 = uVar1;
  return;
}

/* _gleInsertPixel_G_Float @ 0xea040 (12 bytes) */
void _gleInsertPixel_G_Float(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *param_2 = *(undefined4 *)(param_1 + 8);
  return;
}

/* _gleInsertPixel_B_Byte @ 0xea04c (52 bytes) */
void _gleInsertPixel_B_Byte(param_1, param_2)
  int param_1;
  undefined1 *param_2;
{
  *param_2 = (char)(int)(*(float *)(param_1 + 0xc) * FLOAT_00108f6c);
  return;
}

/* _gleInsertPixel_B_Ubyte @ 0xea080 (52 bytes) */
void _gleInsertPixel_B_Ubyte(param_1, param_2)
  int param_1;
  undefined1 *param_2;
{
  *param_2 = (char)(int)(*(float *)(param_1 + 0xc) * FLOAT_00108f70);
  return;
}

/* _gleInsertPixel_B_Short @ 0xea0b4 (52 bytes) */
void _gleInsertPixel_B_Short(param_1, param_2)
  int param_1;
  undefined2 *param_2;
{
  *param_2 = (short)(int)(*(float *)(param_1 + 0xc) * FLOAT_00108f74);
  return;
}

/* _gleInsertPixel_B_Ushort @ 0xea0e8 (52 bytes) */
void _gleInsertPixel_B_Ushort(param_1, param_2)
  int param_1;
  undefined2 *param_2;
{
  *param_2 = (short)(int)(*(float *)(param_1 + 0xc) * FLOAT_00108ea0);
  return;
}

/* _gleInsertPixel_B_Int @ 0xea11c (52 bytes) */
void _gleInsertPixel_B_Int(param_1, param_2)
  int param_1;
  int *param_2;
{
  *param_2 = (int)((double)*(float *)(param_1 + 0xc) * DOUBLE_00108d90);
  return;
}

/* _gleInsertPixel_B_Uint @ 0xea150 (96 bytes) */
void _gleInsertPixel_B_Uint(param_1, param_2)
  int param_1;
  uint *param_2;
{
  uint uVar1;
  double dVar2;
  
  dVar2 = (double)*(float *)(param_1 + 0xc) * DOUBLE_00108da8;
  if (DOUBLE_00108d80 <= dVar2) {
    uVar1 = (int)(dVar2 - DOUBLE_00108d80) ^ 0x80000000;
  }
  else {
    uVar1 = (uint)(int)dVar2;
  }
  *param_2 = uVar1;
  return;
}

/* _gleInsertPixel_B_Float @ 0xea1b0 (12 bytes) */
void _gleInsertPixel_B_Float(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *param_2 = *(undefined4 *)(param_1 + 0xc);
  return;
}

/* _gleInsertPixel_A_Byte @ 0xea1bc (52 bytes) */
void _gleInsertPixel_A_Byte(param_1, param_2)
  int param_1;
  undefined1 *param_2;
{
  *param_2 = (char)(int)(*(float *)(param_1 + 0x10) * FLOAT_00108f6c);
  return;
}

/* _gleInsertPixel_A_Ubyte @ 0xea1f0 (52 bytes) */
void _gleInsertPixel_A_Ubyte(param_1, param_2)
  int param_1;
  undefined1 *param_2;
{
  *param_2 = (char)(int)(*(float *)(param_1 + 0x10) * FLOAT_00108f70);
  return;
}

