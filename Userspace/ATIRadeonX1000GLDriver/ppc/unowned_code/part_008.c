#include "decls.h"

/* orph_1d8e0c @ 0x1d8e0c (4 bytes) */
int orph_1d8e0c()
{
  return;
}

/* orph_1d8e10 @ 0x1d8e10 (20 bytes) */
int orph_1d8e10(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  *(undefined1 *)(param_2 * 0x48 + *(int *)(param_1 + 0xa8) + 0xe) = param_3;
  return;
}

/* orph_1d8e24 @ 0x1d8e24 (20 bytes) */
int orph_1d8e24(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  *(undefined1 *)(param_2 * 0x48 + *(int *)(param_1 + 0xa8) + 0xf) = param_3;
  return;
}

/* orph_1d8e38 @ 0x1d8e38 (12 bytes) */
int orph_1d8e38(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  return param_2 + 0x8000;
}

/* orph_1d8e44 @ 0x1d8e44 (24 bytes) */
int orph_1d8e44(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x31) = param_2;
  return;
}

/* orph_1d8e5c @ 0x1d8e5c (24 bytes) */
int orph_1d8e5c(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x30) = param_2;
  return;
}

/* orph_1d8e74 @ 0x1d8e74 (24 bytes) */
int orph_1d8e74(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x3f) = param_2;
  return;
}

/* orph_1d8e8c @ 0x1d8e8c (4 bytes) */
int orph_1d8e8c()
{
  return;
}

/* orph_1d8e90 @ 0x1d8e90 (60 bytes) */
int orph_1d8e90(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
  if (*(char *)(iVar1 + -0x14) == '\x01') {
    return 0;
  }
  *(undefined1 *)(iVar1 + -0x14) = 1;
  return 1;
}

/* orph_1d8ecc @ 0x1d8ecc (56 bytes) */
int orph_1d8ecc(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
  if (*(char *)(iVar1 + 0x34) == '\x01') {
    return 0;
  }
  *(undefined1 *)(iVar1 + 0x34) = 1;
  return 1;
}

/* orph_1d8f04 @ 0x1d8f04 (48 bytes) */
int orph_1d8f04(param_1)
  int param_1;
{
  *(undefined1 *)(*(int *)(param_1 + 0xb0) * 0x48 + *(int *)(param_1 + 0xa8) + 0x1b) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0xb0) * 0x48 + *(int *)(param_1 + 0xa8) + 4) = 1;
  return;
}

/* orph_1d8f34 @ 0x1d8f34 (28 bytes) */
int orph_1d8f34(param_1)
  int param_1;
{
  *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 4) = 1;
  return;
}

/* orph_1d8f50 @ 0x1d8f50 (4 bytes) */
int orph_1d8f50()
{
  return;
}

/* orph_1d8f54 @ 0x1d8f54 (4 bytes) */
int orph_1d8f54()
{
  return;
}

