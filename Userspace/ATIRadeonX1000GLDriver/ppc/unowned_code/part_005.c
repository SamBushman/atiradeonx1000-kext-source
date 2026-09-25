#include "decls.h"

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
int orph_1d0de0(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  FUN_001135ec(param_1,param_2,param_3);
  return;
}

/* orph_1d0de4 @ 0x1d0de4 (4 bytes) */
int orph_1d0de4(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  FUN_001135ec(param_1,param_2,param_3);
  return;
}

/* orph_1d0de8 @ 0x1d0de8 (4 bytes) */
int orph_1d0de8(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  FUN_001135ec(param_1,param_2,param_3);
  return;
}

/* orph_1d0dec @ 0x1d0dec (4 bytes) */
int orph_1d0dec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  FUN_001135ec(param_1,param_2,param_3);
  return;
}

/* orph_1d0df0 @ 0x1d0df0 (4 bytes) */
int orph_1d0df0(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  FUN_001135ec(param_1,param_2,param_3);
  return;
}

/* orph_1d0df4 @ 0x1d0df4 (4 bytes) */
int orph_1d0df4(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  FUN_0011363c(param_1,param_2,param_3);
  return;
}

/* orph_1d0df8 @ 0x1d0df8 (4 bytes) */
int orph_1d0df8(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  FUN_00113690(param_1,param_2,param_3);
  return;
}

/* orph_1d0dfc @ 0x1d0dfc (4 bytes) */
int orph_1d0dfc(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 0x84) = 1;
  *(undefined4 *)(param_2 + 0x80) = 1;
  *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) | 0x18000;
  *(undefined4 *)(param_1 + 4) = 3;
  return;
}

/* orph_1d0e00 @ 0x1d0e00 (4 bytes) */
int orph_1d0e00(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 0x84) = 0;
  *(undefined4 *)(param_2 + 0x80) = 0;
  *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) | 0x18000;
  *(undefined4 *)(param_1 + 4) = 2;
  return;
}

/* orph_1d0e04 @ 0x1d0e04 (4 bytes) */
int orph_1d0e04(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 0x84) = 0;
  *(undefined4 *)(param_2 + 0x80) = 0;
  *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) | 0x18000;
  *(undefined4 *)(param_1 + 4) = 2;
  return;
}

/* orph_1d0e08 @ 0x1d0e08 (4 bytes) */
int orph_1d0e08(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 0x84) = 0;
  *(undefined4 *)(param_2 + 0x80) = 0;
  *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) | 0x18000;
  *(undefined4 *)(param_1 + 4) = 2;
  return;
}

/* orph_1d78a8 @ 0x1d78a8 (8 bytes) */
int orph_1d78a8()
{
  return 0;
}

/* orph_1d78b0 @ 0x1d78b0 (8 bytes) */
int orph_1d78b0()
{
  return 0;
}

/* orph_1d78b8 @ 0x1d78b8 (8 bytes) */
int orph_1d78b8()
{
  return 0;
}

/* orph_1d78c0 @ 0x1d78c0 (8 bytes) */
int orph_1d78c0()
{
  return 0;
}

/* orph_1d78c8 @ 0x1d78c8 (8 bytes) */
int orph_1d78c8()
{
  return 0;
}

/* orph_1d78d0 @ 0x1d78d0 (8 bytes) */
int orph_1d78d0()
{
  return 0;
}

/* orph_1d78d8 @ 0x1d78d8 (8 bytes) */
int orph_1d78d8()
{
  return 0;
}

/* orph_1d78e0 @ 0x1d78e0 (8 bytes) */
int orph_1d78e0()
{
  return 0;
}

/* orph_1d78e8 @ 0x1d78e8 (8 bytes) */
int orph_1d78e8()
{
  return 0;
}

/* orph_1d78f0 @ 0x1d78f0 (8 bytes) */
int orph_1d78f0()
{
  return 0;
}

/* orph_1d78f8 @ 0x1d78f8 (8 bytes) */
int orph_1d78f8()
{
  return 1;
}

/* orph_1d7900 @ 0x1d7900 (8 bytes) */
int orph_1d7900(param_1)
  int param_1;
{
  return *(undefined4 *)(param_1 + 0x30);
}

/* orph_1d7908 @ 0x1d7908 (8 bytes) */
int orph_1d7908()
{
  return 1;
}

/* orph_1d7910 @ 0x1d7910 (8 bytes) */
int orph_1d7910()
{
  return 1;
}

/* orph_1d7918 @ 0x1d7918 (8 bytes) */
int orph_1d7918()
{
  return 1;
}

/* orph_1d7920 @ 0x1d7920 (8 bytes) */
int orph_1d7920()
{
  return 1;
}

/* orph_1d7928 @ 0x1d7928 (8 bytes) */
int orph_1d7928(param_1)
  int param_1;
{
  return *(undefined4 *)(param_1 + 0x30);
}

/* orph_1d7930 @ 0x1d7930 (8 bytes) */
int orph_1d7930()
{
  return 1;
}

/* orph_1d7938 @ 0x1d7938 (8 bytes) */
int orph_1d7938(param_1)
  int param_1;
{
  return *(undefined4 *)(param_1 + 0x30);
}

/* orph_1d7940 @ 0x1d7940 (8 bytes) */
int orph_1d7940()
{
  return 1;
}

/* orph_1d7948 @ 0x1d7948 (8 bytes) */
int orph_1d7948(param_1)
  int param_1;
{
  return *(undefined4 *)(param_1 + 0x30);
}

/* orph_1d82c4 @ 0x1d82c4 (4 bytes) */
int orph_1d82c4()
{
  return;
}

