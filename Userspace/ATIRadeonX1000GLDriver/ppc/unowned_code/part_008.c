#include "decls.h"

/* orph_1d8af0 @ 0x1d8af0 (4 bytes) */
int orph_1d8af0()
{
  return;
}

/* orph_1d8c04 @ 0x1d8c04 (8 bytes) */
int orph_1d8c04()
{
  return 1;
}

/* orph_1d8c0c @ 0x1d8c0c (4 bytes) */
int orph_1d8c0c()
{
  return;
}

/* orph_1d8c10 @ 0x1d8c10 (8 bytes) */
int orph_1d8c10()
{
  return 1;
}

/* orph_1d8cb4 @ 0x1d8cb4 (4 bytes) */
int orph_1d8cb4()
{
  return;
}

/* orph_1d8cb8 @ 0x1d8cb8 (4 bytes) */
int orph_1d8cb8()
{
  return;
}

/* orph_1d8cbc @ 0x1d8cbc (4 bytes) */
int orph_1d8cbc()
{
  return;
}

/* orph_1d8cc0 @ 0x1d8cc0 (4 bytes) */
int orph_1d8cc0()
{
  return;
}

/* orph_1d8cc4 @ 0x1d8cc4 (4 bytes) */
int orph_1d8cc4()
{
  return;
}

/* orph_1d8cc8 @ 0x1d8cc8 (4 bytes) */
int orph_1d8cc8()
{
  return;
}

/* orph_1d8ccc @ 0x1d8ccc (4 bytes) */
int orph_1d8ccc()
{
  return;
}

/* orph_1d8cd0 @ 0x1d8cd0 (4 bytes) */
int orph_1d8cd0()
{
  return;
}

/* orph_1d8cd4 @ 0x1d8cd4 (4 bytes) */
int orph_1d8cd4()
{
  return;
}

/* orph_1d8cd8 @ 0x1d8cd8 (20 bytes) */
int orph_1d8cd8(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  *(undefined1 *)(param_2 * 0x48 + *(int *)(param_1 + 0x58) + 0xe) = param_3;
  return;
}

/* orph_1d8cec @ 0x1d8cec (20 bytes) */
int orph_1d8cec(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  *(undefined1 *)(param_2 * 0x48 + *(int *)(param_1 + 0x58) + 0xf) = param_3;
  return;
}

/* orph_1d8d00 @ 0x1d8d00 (8 bytes) */
int orph_1d8d00()
{
  return 0;
}

/* orph_1d8d08 @ 0x1d8d08 (12 bytes) */
int orph_1d8d08(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  return param_2 + 0x8000;
}

/* orph_1d8d14 @ 0x1d8d14 (24 bytes) */
int orph_1d8d14(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x30) = param_2;
  return;
}

/* orph_1d8d2c @ 0x1d8d2c (24 bytes) */
int orph_1d8d2c(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x3f) = param_2;
  return;
}

/* orph_1d8d44 @ 0x1d8d44 (4 bytes) */
int orph_1d8d44()
{
  return;
}

/* orph_1d8d48 @ 0x1d8d48 (4 bytes) */
int orph_1d8d48()
{
  return;
}

/* orph_1d8d4c @ 0x1d8d4c (60 bytes) */
int orph_1d8d4c(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58);
  if (*(char *)(iVar1 + -0x14) == '\x01') {
    return 0;
  }
  *(undefined1 *)(iVar1 + -0x14) = 1;
  return 1;
}

/* orph_1d8d88 @ 0x1d8d88 (56 bytes) */
int orph_1d8d88(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58);
  if (*(char *)(iVar1 + 0x34) == '\x01') {
    return 0;
  }
  *(undefined1 *)(iVar1 + 0x34) = 1;
  return 1;
}

/* orph_1d8dc0 @ 0x1d8dc0 (4 bytes) */
int orph_1d8dc0()
{
  return;
}

/* orph_1d8dc4 @ 0x1d8dc4 (4 bytes) */
int orph_1d8dc4()
{
  return;
}

/* orph_1d8dc8 @ 0x1d8dc8 (4 bytes) */
int orph_1d8dc8()
{
  return;
}

/* orph_1d8dcc @ 0x1d8dcc (4 bytes) */
int orph_1d8dcc()
{
  return;
}

/* orph_1d8dd0 @ 0x1d8dd0 (4 bytes) */
int orph_1d8dd0()
{
  return;
}

/* orph_1d8dd4 @ 0x1d8dd4 (24 bytes) */
int orph_1d8dd4(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x31) = param_2;
  return;
}

/* orph_1d8dec @ 0x1d8dec (12 bytes) */
int orph_1d8dec(param_1)
  int param_1;
{
  return *(int *)(param_1 + 0x58) << 4;
}

/* orph_1d8df8 @ 0x1d8df8 (24 bytes) */
int orph_1d8df8()
{
  return;
}

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

