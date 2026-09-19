#include "decls.h"

/* orph_1d0174 @ 0x1d0174 (8 bytes) */
int orph_1d0174()
{
  return 0;
}

/* orph_1d017c @ 0x1d017c (8 bytes) */
int orph_1d017c()
{
  return 0;
}

/* orph_1d0184 @ 0x1d0184 (8 bytes) */
int orph_1d0184()
{
  return 0;
}

/* orph_1d018c @ 0x1d018c (4 bytes) */
int orph_1d018c()
{
  return;
}

/* orph_1d0190 @ 0x1d0190 (8 bytes) */
int orph_1d0190()
{
  return 0;
}

/* orph_1d0198 @ 0x1d0198 (4 bytes) */
int orph_1d0198()
{
  return;
}

/* orph_1d019c @ 0x1d019c (8 bytes) */
int orph_1d019c()
{
  return 0x30;
}

/* orph_1d01a4 @ 0x1d01a4 (4 bytes) */
int orph_1d01a4()
{
  return;
}

/* orph_1d01a8 @ 0x1d01a8 (4 bytes) */
int orph_1d01a8()
{
  return;
}

/* orph_1d01ac @ 0x1d01ac (4 bytes) */
int orph_1d01ac()
{
  return;
}

/* orph_1d01f8 @ 0x1d01f8 (4 bytes) */
int orph_1d01f8()
{
  return;
}

/* orph_1d01fc @ 0x1d01fc (8 bytes) */
int orph_1d01fc()
{
  return 0;
}

/* orph_1d0204 @ 0x1d0204 (4 bytes) */
int orph_1d0204()
{
  return;
}

/* orph_1d0250 @ 0x1d0250 (8 bytes) */
int orph_1d0250()
{
  return 2;
}

/* orph_1d0258 @ 0x1d0258 (8 bytes) */
int orph_1d0258()
{
  return 0;
}

/* orph_1d0260 @ 0x1d0260 (24 bytes) */
int orph_1d0260(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  int param_3;
{
  *param_2 = *(float *)(param_3 + 4) + *(float *)(param_3 + 8);
  return 1;
}

/* orph_1d0398 @ 0x1d0398 (24 bytes) */
int orph_1d0398(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  int param_3;
{
  *param_2 = *(int *)(param_3 + 4) + *(int *)(param_3 + 8);
  return 1;
}

/* orph_1d03b0 @ 0x1d03b0 (24 bytes) */
int orph_1d03b0(param_1, param_2, param_3)
  undefined4 param_1;
  uint *param_2;
  int param_3;
{
  *param_2 = *(uint *)(param_3 + 4) | *(uint *)(param_3 + 8);
  return 1;
}

/* orph_1d03c8 @ 0x1d03c8 (20 bytes) */
int orph_1d03c8(param_1, param_2, param_3)
  undefined4 param_1;
  uint *param_2;
  int param_3;
{
  *param_2 = ~*(uint *)(param_3 + 4);
  return 1;
}

/* orph_1d03dc @ 0x1d03dc (24 bytes) */
int orph_1d03dc(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  int param_3;
{
  *param_2 = *(int *)(param_3 + 4) >> (*(uint *)(param_3 + 8) & 0x3f);
  return 1;
}

/* orph_1d03f4 @ 0x1d03f4 (24 bytes) */
int orph_1d03f4(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  int param_3;
{
  *param_2 = *(int *)(param_3 + 4) << (*(uint *)(param_3 + 8) & 0x3f);
  return 1;
}

/* orph_1d040c @ 0x1d040c (28 bytes) */
int orph_1d040c(param_1, param_2, param_3)
  undefined4 param_1;
  uint *param_2;
  int param_3;
{
  *param_2 = (*(uint *)(param_3 + 4) & 0x7fffffff) >> (*(uint *)(param_3 + 8) & 0x3f);
  return 1;
}

/* orph_1d0428 @ 0x1d0428 (24 bytes) */
int orph_1d0428(param_1, param_2, param_3)
  undefined4 param_1;
  uint *param_2;
  int param_3;
{
  *param_2 = *(uint *)(param_3 + 4) ^ *(uint *)(param_3 + 8);
  return 1;
}

/* orph_1d0440 @ 0x1d0440 (24 bytes) */
int orph_1d0440(param_1, param_2, param_3)
  undefined4 param_1;
  uint *param_2;
  int param_3;
{
  *param_2 = *(uint *)(param_3 + 4) & *(uint *)(param_3 + 8);
  return 1;
}

/* orph_1d0458 @ 0x1d0458 (24 bytes) */
int orph_1d0458(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  int param_3;
{
  *param_2 = *(int *)(param_3 + 8) - *(int *)(param_3 + 4);
  return 1;
}

/* orph_1d0470 @ 0x1d0470 (24 bytes) */
int orph_1d0470(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  int param_3;
{
  *param_2 = *(int *)(param_3 + 4) * *(int *)(param_3 + 8);
  return 1;
}

/* orph_1d0488 @ 0x1d0488 (24 bytes) */
int orph_1d0488(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  int param_3;
{
  *param_2 = *(int *)(param_3 + 4) * *(int *)(param_3 + 8);
  return 1;
}

/* orph_1d04a0 @ 0x1d04a0 (32 bytes) */
int orph_1d04a0(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  int param_3;
{
  int iVar1;
  
  iVar1 = *(int *)(param_3 + 4);
  if (*(int *)(param_3 + 4) < *(int *)(param_3 + 8)) {
    iVar1 = *(int *)(param_3 + 8);
  }
  *param_2 = iVar1;
  return 1;
}

/* orph_1d04c0 @ 0x1d04c0 (32 bytes) */
int orph_1d04c0(param_1, param_2, param_3)
  undefined4 param_1;
  uint *param_2;
  int param_3;
{
  uint uVar1;
  
  uVar1 = *(uint *)(param_3 + 4);
  if (*(uint *)(param_3 + 4) < *(uint *)(param_3 + 8)) {
    uVar1 = *(uint *)(param_3 + 8);
  }
  *param_2 = uVar1;
  return 1;
}

/* orph_1d04e0 @ 0x1d04e0 (36 bytes) */
int orph_1d04e0(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  int param_3;
{
  float fVar1;
  
  fVar1 = *(float *)(param_3 + 4);
  if (*(float *)(param_3 + 4) < *(float *)(param_3 + 8)) {
    fVar1 = *(float *)(param_3 + 8);
  }
  *param_2 = fVar1;
  return 1;
}

/* orph_1d0504 @ 0x1d0504 (36 bytes) */
int orph_1d0504(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  int param_3;
{
  float fVar1;
  
  fVar1 = *(float *)(param_3 + 4);
  if (*(float *)(param_3 + 8) < *(float *)(param_3 + 4)) {
    fVar1 = *(float *)(param_3 + 8);
  }
  *param_2 = fVar1;
  return 1;
}

/* orph_1d0528 @ 0x1d0528 (32 bytes) */
int orph_1d0528(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  int param_3;
{
  int iVar1;
  
  iVar1 = *(int *)(param_3 + 4);
  if (*(int *)(param_3 + 8) <= *(int *)(param_3 + 4)) {
    iVar1 = *(int *)(param_3 + 8);
  }
  *param_2 = iVar1;
  return 1;
}

/* orph_1d0548 @ 0x1d0548 (32 bytes) */
int orph_1d0548(param_1, param_2, param_3)
  undefined4 param_1;
  uint *param_2;
  int param_3;
{
  uint uVar1;
  
  uVar1 = *(uint *)(param_3 + 4);
  if (*(uint *)(param_3 + 8) <= *(uint *)(param_3 + 4)) {
    uVar1 = *(uint *)(param_3 + 8);
  }
  *param_2 = uVar1;
  return 1;
}

/* orph_1d0568 @ 0x1d0568 (28 bytes) */
int orph_1d0568(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  int param_3;
{
  *param_2 = (int)*(float *)(param_3 + 4);
  return 1;
}

/* orph_1d0584 @ 0x1d0584 (28 bytes) */
int orph_1d0584(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  int param_3;
{
  *param_2 = (int)*(float *)(param_3 + 4);
  return 1;
}

/* orph_1d05a0 @ 0x1d05a0 (16 bytes) */
int orph_1d05a0(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 *param_2;
  int param_3;
{
  *param_2 = *(undefined4 *)(param_3 + 4);
  return 1;
}

/* orph_1d096c @ 0x1d096c (24 bytes) */
int orph_1d096c(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  int param_3;
{
  *param_2 = *(float *)(param_3 + 4) * *(float *)(param_3 + 8);
  return 1;
}

/* orph_1d0984 @ 0x1d0984 (24 bytes) */
int orph_1d0984(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 *param_2;
  int param_3;
{
  *param_2 = (int)((ulonglong)((longlong)*(int *)(param_3 + 4) * (longlong)*(int *)(param_3 + 8)) >>
                  0x20);
  return 1;
}

/* orph_1d099c @ 0x1d099c (24 bytes) */
int orph_1d099c(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 *param_2;
  int param_3;
{
  *param_2 = (int)((ulonglong)*(uint *)(param_3 + 4) * (ulonglong)*(uint *)(param_3 + 8) >> 0x20);
  return 1;
}

/* orph_1d0b6c @ 0x1d0b6c (40 bytes) */
int orph_1d0b6c(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  float *param_2;
  float *param_3;
  float *param_4;
  int param_5;
{
  *param_2 = *param_3 * *param_4 + param_3[1] * param_4[1] + *(float *)(param_5 + 8);
  return;
}

/* orph_1d0cb4 @ 0x1d0cb4 (36 bytes) */
int orph_1d0cb4(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 *param_2;
  int param_3;
{
  undefined4 uVar1;
  
  uVar1 = 0x3f800000;
  if (*(float *)(param_3 + 4) != *(float *)(param_3 + 8)) {
    uVar1 = 0;
  }
  *param_2 = uVar1;
  return 1;
}

/* orph_1d0d1c @ 0x1d0d1c (44 bytes) */
int orph_1d0d1c(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 *param_2;
  int param_3;
{
  undefined4 uVar1;
  
  if (*(float *)(param_3 + 4) < *(float *)(param_3 + 8)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x3f800000;
  }
  *param_2 = uVar1;
  return 1;
}

/* orph_1d0d38 @ 0x1d0d38 (16 bytes) */
int orph_1d0d38(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  *param_2 = 0;
  return 1;
}

/* orph_1d0d48 @ 0x1d0d48 (36 bytes) */
int orph_1d0d48(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 *param_2;
  int param_3;
{
  undefined4 uVar1;
  
  uVar1 = 0x3f800000;
  if (*(float *)(param_3 + 4) == *(float *)(param_3 + 8)) {
    uVar1 = 0;
  }
  *param_2 = uVar1;
  return 1;
}

/* orph_1d0d6c @ 0x1d0d6c (8 bytes) */
int orph_1d0d6c()
{
  return 1;
}

/* orph_1d0d74 @ 0x1d0d74 (8 bytes) */
int orph_1d0d74()
{
  return 1;
}

/* orph_1d0d7c @ 0x1d0d7c (56 bytes) */
int orph_1d0d7c(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  float *param_2;
  float *param_3;
  float *param_4;
{
  *param_2 = param_3[3] * param_4[3] +
             param_3[2] * param_4[2] + *param_3 * *param_4 + param_3[1] * param_4[1];
  return;
}

/* orph_1d0db4 @ 0x1d0db4 (4 bytes) */
int orph_1d0db4(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 0x84) = 3;
  *(undefined4 *)(param_2 + 0x80) = 1;
  *(undefined4 *)(param_1 + 4) = 9;
  return;
}

/* orph_1d0db8 @ 0x1d0db8 (4 bytes) */
int orph_1d0db8(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 0x84) = 1;
  *(undefined4 *)(param_2 + 0x80) = 1;
  *(undefined4 *)(param_1 + 4) = 6;
  return;
}

/* orph_1d0dbc @ 0x1d0dbc (4 bytes) */
int orph_1d0dbc(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 0x84) = 1;
  *(undefined4 *)(param_2 + 0x80) = 1;
  *(undefined4 *)(param_1 + 4) = 6;
  return;
}

/* orph_1d0dc0 @ 0x1d0dc0 (4 bytes) */
int orph_1d0dc0(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 0x84) = 1;
  *(undefined4 *)(param_2 + 0x80) = 1;
  *(undefined4 *)(param_1 + 4) = 6;
  return;
}

/* orph_1d0dc4 @ 0x1d0dc4 (4 bytes) */
int orph_1d0dc4(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 0x84) = 1;
  *(undefined4 *)(param_2 + 0x80) = 1;
  *(undefined4 *)(param_1 + 4) = 6;
  return;
}

/* orph_1d0dc8 @ 0x1d0dc8 (4 bytes) */
int orph_1d0dc8(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 0x84) = 1;
  *(undefined4 *)(param_2 + 0x80) = 1;
  *(undefined4 *)(param_1 + 4) = 6;
  return;
}

/* orph_1d0dcc @ 0x1d0dcc (4 bytes) */
int orph_1d0dcc(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 0x84) = 1;
  *(undefined4 *)(param_2 + 0x80) = 1;
  *(undefined4 *)(param_1 + 4) = 6;
  return;
}

/* orph_1d0dd0 @ 0x1d0dd0 (4 bytes) */
int orph_1d0dd0(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 0x84) = 0;
  *(undefined4 *)(param_2 + 300) = 0;
  *(undefined4 *)(param_2 + 0x80) = 1;
  *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) | 0x18000;
  *(undefined4 *)(param_1 + 4) = 1;
  return;
}

/* orph_1d0dd4 @ 0x1d0dd4 (4 bytes) */
int orph_1d0dd4(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 0x84) = 0;
  *(undefined4 *)(param_2 + 300) = 0;
  *(undefined4 *)(param_2 + 0x80) = 1;
  *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) | 0x18000;
  *(undefined4 *)(param_1 + 4) = 1;
  return;
}

/* orph_1d0dd8 @ 0x1d0dd8 (4 bytes) */
int orph_1d0dd8(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 0x84) = 0;
  *(undefined4 *)(param_2 + 300) = 0;
  *(undefined4 *)(param_2 + 0x80) = 1;
  *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) | 0x18000;
  *(undefined4 *)(param_1 + 4) = 1;
  return;
}

/* orph_1d0ddc @ 0x1d0ddc (4 bytes) */
int orph_1d0ddc(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 0x84) = 0;
  *(undefined4 *)(param_2 + 300) = 0;
  *(undefined4 *)(param_2 + 0x80) = 1;
  *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) | 0x18000;
  *(undefined4 *)(param_1 + 4) = 1;
  return;
}

/* orph_1d0de0 @ 0x1d0de0 (4 bytes) */
int orph_1d0de0()
{
  FUN_001135ec();
  return;
}

/* orph_1d0de4 @ 0x1d0de4 (4 bytes) */
int orph_1d0de4()
{
  FUN_001135ec();
  return;
}

