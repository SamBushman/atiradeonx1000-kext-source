#include "decls.h"

/* FUN_00007179 @ 0x7179 (326 bytes) */
int FUN_00007179(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  undefined4 *param_3;
  uint param_4;
  undefined4 param_5;
{
  uint *puVar1;
  int iVar2;
  uint *local_14;
  int local_10;
  
  local_14 = (uint *)*param_3;
  local_10 = 0;
  iVar2 = 0;
  do {
    local_10 = local_10 + (uint)*(byte *)(iVar2 + 0x16 + param_2);
    iVar2 = iVar2 + 1;
  } while (iVar2 != 6);
  if (local_10 == 0) {
    *(undefined1 *)(param_1 + 0x590) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 0x590) = 0;
  puVar1 = (uint *)FUN_00007054(param_1,local_10 + 2,param_5);
  *puVar1 = ~-(uint)(*(char *)(param_2 + 0x1b) == '\0') & 0x40 |
            ~-(uint)(*(char *)(param_2 + 0x1a) == '\0') & 0x80 |
            ~-(uint)(*(char *)(param_2 + 0x19) == '\0') & 0x100 |
            ~-(uint)(*(char *)(param_2 + 0x18) == '\0') & 0x200 |
            ~-(uint)(*(char *)(param_2 + 0x17) == '\0') & 0x400 |
            ~-(uint)(*(char *)(param_2 + 0x16) == '\0') & 0x800 |
            ~-(uint)(*(char *)(param_2 + 0x15) == '\0') & 0x80000000 |
            (uint)*(byte *)(param_1 + 0x564) << 0x19;
  puVar1[1] = param_4 / *(uint *)(param_1 + 0x580) << 0x14 |
              param_4 % *(uint *)(param_1 + 0x580) << 4;
  puVar1 = puVar1 + 2;
  iVar2 = 0;
  do {
    *puVar1 = *local_14;
    local_14 = local_14 + 1;
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 1;
  } while (local_10 != iVar2);
  *param_3 = local_14;
  return;
}

/* FUN_000072bf @ 0x72bf (230 bytes) */
int FUN_000072bf(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  undefined4 *param_3;
  int param_4;
  int param_5;
{
  uint uVar1;
  
  if (param_5 == 3) {
    param_3[7] = *(undefined4 *)(param_2 + 0x18);
    *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + param_4 * 4;
    param_3[5] = 1;
    param_3[8] = param_3[7];
    param_3[9] = *(int *)(param_2 + 0x18) + -8;
    return param_3 + 8;
  }
  if (param_5 != 4) {
    if (param_5 != 1) {
      return (undefined4 *)0x0;
    }
    param_3[2] = *(undefined4 *)(param_2 + 0x10);
    uVar1 = param_4 * 4 + *(int *)(param_2 + 0x10);
    *(uint *)(param_2 + 0x10) = uVar1;
    if (*(uint *)(param_2 + 0x14) <= uVar1) {
      *(uint *)(param_2 + 0x10) = uVar1 + param_4 * -4;
      FUN_00006c3c(param_1);
      param_3[2] = *(undefined4 *)(param_2 + 0x10);
      *(int *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) + param_4 * 4;
    }
    *param_3 = 1;
    param_3[1] = 1;
    param_3[3] = param_3[2];
    param_3[4] = *(int *)(param_2 + 0x10) + -8;
    return param_3 + 3;
  }
  param_3[0xc] = *(undefined4 *)(param_2 + 0x20);
  *(int *)(param_2 + 0x20) = *(int *)(param_2 + 0x20) + param_4 * 4;
  param_3[10] = 1;
  param_3[0xd] = param_3[0xc];
  param_3[0xe] = *(int *)(param_2 + 0x20) + -8;
  return param_3 + 0xd;
}

/* FUN_000073a5 @ 0x73a5 (26 bytes) */
int FUN_000073a5(param_1)
  int param_1;
{
  *(undefined4 *)(*(int *)(param_1 + 0x15138) + -0xc) = 0;
  return;
}

/* FUN_000073bf @ 0x73bf (3836 bytes) */
int FUN_000073bf(param_1, param_2, param_3)
  int param_1;
  short *param_2;
  uint param_3;
{
  int *piVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  
  iVar15 = param_1 + 0x55c;
  iVar8 = *(int *)(param_1 + 0x568);
  uVar12 = param_3 / *(uint *)(param_1 + 0x580);
  uVar14 = param_3 % *(uint *)(param_1 + 0x580);
  iVar13 = (*(uint *)(param_1 + 0x58c) >> 2) * uVar12 + uVar14;
  iVar16 = param_3 * 4;
  if (*(int *)(param_1 + 0x55c) != 3) {
    switch((char)param_2[10]) {
    default:
      return;
    case '\x01':
      iVar15 = iVar8 * 0x10 + iVar15;
      *(undefined4 *)(*(int *)(iVar15 + 0x14c6c) + iVar13 * 4) = *(undefined4 *)param_2;
      *(uint *)(iVar13 * 4 + *(int *)(iVar15 + 0x14cbc)) =
           (int)param_2[1] / 2 << 0x10 | (int)*param_2 / 2 & 0xffffU;
      piVar1 = (int *)(param_1 + 0x143fc + (uint)*(byte *)(param_2 + 8) * 0xc);
      if (*(char *)(param_1 + 0x590) == '\0') {
        iVar15 = *piVar1;
        *(int *)(piVar1[2] + iVar15 * 4) = iVar16;
        *piVar1 = iVar15 + -1;
        return;
      }
      iVar15 = piVar1[1];
      *(int *)(piVar1[2] + iVar15 * 4) = iVar16;
      piVar1[1] = iVar15 + 1;
      return;
    case '\x02':
      iVar15 = iVar8 * 0x10 + iVar15;
      *(undefined4 *)(*(int *)(iVar15 + 0x14c70) + iVar13 * 4) = *(undefined4 *)(param_2 + 2);
      *(uint *)(iVar13 * 4 + *(int *)(iVar15 + 0x14cc0)) =
           (int)param_2[3] / 2 << 0x10 | (int)param_2[2] / 2 & 0xffffU;
      iVar8 = param_1 + 0x143fc + (uint)*(byte *)((int)param_2 + 0x11) * 0xc;
      iVar15 = iVar8 + 0x18;
      if (*(char *)(param_1 + 0x590) == '\0') {
        iVar15 = *(int *)(iVar8 + 0x18);
        *(int *)(*(int *)(iVar8 + 0x20) + iVar15 * 4) = iVar16;
        *(int *)(iVar8 + 0x18) = iVar15 + -1;
        return;
      }
      goto LAB_00007b88;
    case '\x03':
      iVar13 = iVar13 * 4;
      iVar15 = iVar8 * 0x10 + iVar15;
      *(undefined4 *)(*(int *)(iVar15 + 0x14c6c) + iVar13) = *(undefined4 *)param_2;
      *(undefined4 *)(iVar13 + *(int *)(iVar15 + 0x14c70)) = *(undefined4 *)(param_2 + 2);
      *(uint *)(iVar13 + *(int *)(iVar15 + 0x14cbc)) =
           (int)param_2[1] / 2 << 0x10 | (int)*param_2 / 2 & 0xffffU;
      *(uint *)(iVar13 + *(int *)(iVar15 + 0x14cc0)) =
           (int)param_2[3] / 2 << 0x10 | (int)param_2[2] / 2 & 0xffffU;
      iVar8 = param_1 + 0x143fc +
              ((uint)*(byte *)(param_2 + 8) + (uint)*(byte *)((int)param_2 + 0x11) * 2) * 0xc;
      iVar15 = iVar8 + 0x30;
      if (*(char *)(param_1 + 0x590) == '\0') {
        iVar15 = *(int *)(iVar8 + 0x30);
        *(int *)(*(int *)(iVar8 + 0x38) + iVar15 * 4) = iVar16;
        *(int *)(iVar8 + 0x30) = iVar15 + -1;
        return;
      }
LAB_00007b88:
      iVar8 = *(int *)(iVar15 + 4);
      *(int *)(*(int *)(iVar15 + 8) + iVar8 * 4) = iVar16;
      *(int *)(iVar15 + 4) = iVar8 + 1;
      return;
    case '\x05':
      uVar9 = *(undefined4 *)(param_2 + 4);
      iVar13 = iVar13 * 4;
      iVar15 = iVar8 * 0x10 + iVar15;
      *(undefined4 *)(*(int *)(iVar15 + 0x14c6c) + iVar13) = *(undefined4 *)param_2;
      *(undefined4 *)(iVar13 + *(int *)(iVar15 + 0x14c74)) = uVar9;
      sVar2 = param_2[5];
      sVar3 = param_2[4];
      *(uint *)(iVar13 + *(int *)(iVar15 + 0x14cbc)) =
           (int)param_2[1] / 2 << 0x10 | (int)*param_2 / 2 & 0xffffU;
      *(uint *)(iVar13 + *(int *)(iVar15 + 0x14cc4)) =
           (int)sVar2 / 2 << 0x10 | (int)sVar3 / 2 & 0xffffU;
      iVar16 = *(int *)(param_1 + 0x153d0) + (uVar14 + uVar12 * *(int *)(param_1 + 0x580) * 2) * 4;
      iVar15 = param_1 + 0x143fc + (uint)*(byte *)(param_2 + 8) * 0xc;
      if (*(char *)(param_1 + 0x590) == '\0') {
        iVar8 = *(int *)(iVar15 + 0x60);
        *(int *)(*(int *)(iVar15 + 0x68) + iVar8 * 4) = iVar16;
        *(int *)(iVar15 + 0x60) = iVar8 + -1;
      }
      else {
        iVar8 = *(int *)(iVar15 + 100);
        *(int *)(*(int *)(iVar15 + 0x68) + iVar8 * 4) = iVar16;
        *(int *)(iVar15 + 100) = iVar8 + 1;
      }
      iVar16 = iVar16 + *(int *)(param_1 + 0x580) * 4;
      iVar8 = param_1 + 0x143fc + (uint)*(byte *)(param_2 + 9) * 0xc;
      iVar15 = iVar8 + 0x78;
      if (*(char *)(param_1 + 0x590) == '\0') {
        iVar15 = *(int *)(iVar8 + 0x78);
        *(int *)(*(int *)(iVar8 + 0x80) + iVar15 * 4) = iVar16;
        *(int *)(iVar8 + 0x78) = iVar15 + -1;
        return;
      }
      break;
    case '\x06':
      uVar9 = *(undefined4 *)(param_2 + 6);
      iVar13 = iVar13 * 4;
      iVar15 = iVar8 * 0x10 + iVar15;
      *(undefined4 *)(*(int *)(iVar15 + 0x14c70) + iVar13) = *(undefined4 *)(param_2 + 2);
      *(undefined4 *)(iVar13 + *(int *)(iVar15 + 0x14c78)) = uVar9;
      sVar2 = param_2[7];
      sVar3 = param_2[6];
      *(uint *)(iVar13 + *(int *)(iVar15 + 0x14cc0)) =
           (int)param_2[3] / 2 << 0x10 | (int)param_2[2] / 2 & 0xffffU;
      *(uint *)(iVar13 + *(int *)(iVar15 + 0x14cc8)) =
           (int)sVar2 / 2 << 0x10 | (int)sVar3 / 2 & 0xffffU;
      iVar16 = *(int *)(param_1 + 0x153d0) + (uVar14 + uVar12 * *(int *)(param_1 + 0x580) * 2) * 4;
      iVar15 = param_1 + 0x143fc + (uint)*(byte *)((int)param_2 + 0x11) * 0xc;
      if (*(char *)(param_1 + 0x590) == '\0') {
        iVar8 = *(int *)(iVar15 + 0x90);
        *(int *)(*(int *)(iVar15 + 0x98) + iVar8 * 4) = iVar16;
        *(int *)(iVar15 + 0x90) = iVar8 + -1;
      }
      else {
        iVar8 = *(int *)(iVar15 + 0x94);
        *(int *)(*(int *)(iVar15 + 0x98) + iVar8 * 4) = iVar16;
        *(int *)(iVar15 + 0x94) = iVar8 + 1;
      }
      iVar16 = iVar16 + *(int *)(param_1 + 0x580) * 4;
      iVar8 = param_1 + 0x143fc + (uint)*(byte *)((int)param_2 + 0x13) * 0xc;
      iVar15 = iVar8 + 0xa8;
      if (*(char *)(param_1 + 0x590) == '\0') {
        iVar15 = *(int *)(iVar8 + 0xa8);
        *(int *)(*(int *)(iVar8 + 0xb0) + iVar15 * 4) = iVar16;
        *(int *)(iVar8 + 0xa8) = iVar15 + -1;
        return;
      }
      break;
    case '\a':
      uVar9 = *(undefined4 *)(param_2 + 2);
      uVar10 = *(undefined4 *)(param_2 + 4);
      uVar11 = *(undefined4 *)(param_2 + 6);
      iVar13 = iVar13 * 4;
      iVar15 = iVar8 * 0x10 + iVar15;
      *(undefined4 *)(*(int *)(iVar15 + 0x14c6c) + iVar13) = *(undefined4 *)param_2;
      *(undefined4 *)(iVar13 + *(int *)(iVar15 + 0x14c70)) = uVar9;
      *(undefined4 *)(iVar13 + *(int *)(iVar15 + 0x14c74)) = uVar10;
      *(undefined4 *)(iVar13 + *(int *)(iVar15 + 0x14c78)) = uVar11;
      sVar2 = param_2[3];
      sVar3 = param_2[2];
      sVar4 = param_2[5];
      sVar5 = param_2[4];
      sVar6 = param_2[7];
      sVar7 = param_2[6];
      *(uint *)(iVar13 + *(int *)(iVar15 + 0x14cbc)) =
           (int)param_2[1] / 2 << 0x10 | (int)*param_2 / 2 & 0xffffU;
      *(uint *)(iVar13 + *(int *)(iVar15 + 0x14cc0)) =
           (int)sVar2 / 2 << 0x10 | (int)sVar3 / 2 & 0xffffU;
      *(uint *)(iVar13 + *(int *)(iVar15 + 0x14cc4)) =
           (int)sVar4 / 2 << 0x10 | (int)sVar5 / 2 & 0xffffU;
      *(uint *)(iVar13 + *(int *)(iVar15 + 0x14cc8)) =
           (int)sVar6 / 2 << 0x10 | (int)sVar7 / 2 & 0xffffU;
      iVar16 = *(int *)(param_1 + 0x153d0) + (uVar14 + uVar12 * *(int *)(param_1 + 0x580) * 2) * 4;
      iVar15 = param_1 + 0x143fc +
               ((uint)*(byte *)(param_2 + 8) + (uint)*(byte *)((int)param_2 + 0x11) * 2) * 0xc;
      if (*(char *)(param_1 + 0x590) == '\0') {
        iVar8 = *(int *)(iVar15 + 0xc0);
        *(int *)(*(int *)(iVar15 + 200) + iVar8 * 4) = iVar16;
        *(int *)(iVar15 + 0xc0) = iVar8 + -1;
      }
      else {
        iVar8 = *(int *)(iVar15 + 0xc4);
        *(int *)(*(int *)(iVar15 + 200) + iVar8 * 4) = iVar16;
        *(int *)(iVar15 + 0xc4) = iVar8 + 1;
      }
      iVar16 = iVar16 + *(int *)(param_1 + 0x580) * 4;
      iVar8 = param_1 + 0x143fc +
              ((uint)*(byte *)(param_2 + 9) + (uint)*(byte *)((int)param_2 + 0x13) * 2) * 0xc;
      iVar15 = iVar8 + 0xf0;
      if (*(char *)(param_1 + 0x590) == '\0') {
        iVar15 = *(int *)(iVar8 + 0xf0);
        *(int *)(*(int *)(iVar8 + 0xf8) + iVar15 * 4) = iVar16;
        *(int *)(iVar8 + 0xf0) = iVar15 + -1;
        return;
      }
    }
LAB_00007a1e:
    iVar8 = *(int *)(iVar15 + 4);
    *(int *)(*(int *)(iVar15 + 8) + iVar8 * 4) = iVar16;
    *(int *)(iVar15 + 4) = iVar8 + 1;
    return;
  }
  switch((char)param_2[10]) {
  case '\x01':
    iVar15 = iVar8 * 0x10 + iVar15;
    *(undefined4 *)(*(int *)(iVar15 + 0x14c6c) + iVar13 * 4) = *(undefined4 *)param_2;
    *(uint *)(iVar13 * 4 + *(int *)(iVar15 + 0x14cbc)) =
         (int)param_2[1] / 2 << 0x10 | (int)*param_2 / 2 & 0xffffU;
    iVar15 = param_1 + 0x143fc;
    if (*(char *)(param_1 + 0x590) == '\0') {
      iVar15 = *(int *)(param_1 + 0x143fc);
      *(int *)(*(int *)(param_1 + 0x14404) + iVar15 * 4) = iVar16;
      *(int *)(param_1 + 0x143fc) = iVar15 + -1;
      return;
    }
    goto LAB_00007dd7;
  case '\x02':
    iVar15 = iVar8 * 0x10 + iVar15;
    *(undefined4 *)(*(int *)(iVar15 + 0x14c70) + iVar13 * 4) = *(undefined4 *)(param_2 + 2);
    *(uint *)(iVar13 * 4 + *(int *)(iVar15 + 0x14cc0)) =
         (int)param_2[3] / 2 << 0x10 | (int)param_2[2] / 2 & 0xffffU;
    iVar15 = param_1 + 0x14408;
    if (*(char *)(param_1 + 0x590) == '\0') {
      iVar15 = *(int *)(param_1 + 0x14408);
      *(int *)(*(int *)(param_1 + 0x14410) + iVar15 * 4) = iVar16;
      *(int *)(param_1 + 0x14408) = iVar15 + -1;
      return;
    }
    goto LAB_00007dd7;
  case '\x03':
    iVar13 = iVar13 * 4;
    iVar15 = iVar8 * 0x10 + iVar15;
    *(undefined4 *)(*(int *)(iVar15 + 0x14c6c) + iVar13) = *(undefined4 *)param_2;
    *(undefined4 *)(iVar13 + *(int *)(iVar15 + 0x14c70)) = *(undefined4 *)(param_2 + 2);
    *(uint *)(iVar13 + *(int *)(iVar15 + 0x14cbc)) =
         (int)param_2[1] / 2 << 0x10 | (int)*param_2 / 2 & 0xffffU;
    *(uint *)(iVar13 + *(int *)(iVar15 + 0x14cc0)) =
         (int)param_2[3] / 2 << 0x10 | (int)param_2[2] / 2 & 0xffffU;
    iVar15 = param_1 + 0x14414;
    if (*(char *)(param_1 + 0x590) == '\0') {
      iVar15 = *(int *)(param_1 + 0x14414);
      *(int *)(*(int *)(param_1 + 0x1441c) + iVar15 * 4) = iVar16;
      *(int *)(param_1 + 0x14414) = iVar15 + -1;
      return;
    }
LAB_00007dd7:
    iVar8 = *(int *)(iVar15 + 4);
    *(int *)(*(int *)(iVar15 + 8) + iVar8 * 4) = iVar16;
    *(int *)(iVar15 + 4) = iVar8 + 1;
    break;
  case '\x05':
    uVar9 = *(undefined4 *)(param_2 + 4);
    iVar13 = iVar13 * 4;
    iVar15 = iVar8 * 0x10 + iVar15;
    *(undefined4 *)(*(int *)(iVar15 + 0x14c6c) + iVar13) = *(undefined4 *)param_2;
    *(undefined4 *)(iVar13 + *(int *)(iVar15 + 0x14c74)) = uVar9;
    sVar2 = param_2[5];
    sVar3 = param_2[4];
    *(uint *)(iVar13 + *(int *)(iVar15 + 0x14cbc)) =
         (int)param_2[1] / 2 << 0x10 | (int)*param_2 / 2 & 0xffffU;
    *(uint *)(iVar13 + *(int *)(iVar15 + 0x14cc4)) =
         (int)sVar2 / 2 << 0x10 | (int)sVar3 / 2 & 0xffffU;
    iVar16 = iVar16 + *(int *)(param_1 + 0x153d0);
    iVar15 = param_1 + 0x143fc + (uint)*(byte *)(param_2 + 8) * 0xc;
    if (*(char *)(param_1 + 0x590) == '\0') {
      iVar8 = *(int *)(iVar15 + 0x24);
      *(int *)(*(int *)(iVar15 + 0x2c) + iVar8 * 4) = iVar16;
      *(int *)(iVar15 + 0x24) = iVar8 + -1;
    }
    else {
      iVar8 = *(int *)(iVar15 + 0x28);
      *(int *)(*(int *)(iVar15 + 0x2c) + iVar8 * 4) = iVar16;
      *(int *)(iVar15 + 0x28) = iVar8 + 1;
    }
    iVar8 = param_1 + 0x143fc + (uint)*(byte *)(param_2 + 9) * 0xc;
    iVar15 = iVar8 + 0x3c;
    if (*(char *)(param_1 + 0x590) != '\0') goto LAB_00007a1e;
    iVar15 = *(int *)(iVar8 + 0x3c);
    *(int *)(*(int *)(iVar8 + 0x44) + iVar15 * 4) = iVar16;
    *(int *)(iVar8 + 0x3c) = iVar15 + -1;
    break;
  case '\x06':
    uVar9 = *(undefined4 *)(param_2 + 6);
    iVar13 = iVar13 * 4;
    iVar15 = iVar8 * 0x10 + iVar15;
    *(undefined4 *)(*(int *)(iVar15 + 0x14c70) + iVar13) = *(undefined4 *)(param_2 + 2);
    *(undefined4 *)(iVar13 + *(int *)(iVar15 + 0x14c78)) = uVar9;
    sVar2 = param_2[7];
    sVar3 = param_2[6];
    *(uint *)(iVar13 + *(int *)(iVar15 + 0x14cc0)) =
         (int)param_2[3] / 2 << 0x10 | (int)param_2[2] / 2 & 0xffffU;
    *(uint *)(iVar13 + *(int *)(iVar15 + 0x14cc8)) =
         (int)sVar2 / 2 << 0x10 | (int)sVar3 / 2 & 0xffffU;
    iVar16 = iVar16 + *(int *)(param_1 + 0x153d0);
    iVar15 = param_1 + 0x143fc + (uint)*(byte *)((int)param_2 + 0x11) * 0xc;
    if (*(char *)(param_1 + 0x590) == '\0') {
      iVar8 = *(int *)(iVar15 + 0x54);
      *(int *)(*(int *)(iVar15 + 0x5c) + iVar8 * 4) = iVar16;
      *(int *)(iVar15 + 0x54) = iVar8 + -1;
    }
    else {
      iVar8 = *(int *)(iVar15 + 0x58);
      *(int *)(*(int *)(iVar15 + 0x5c) + iVar8 * 4) = iVar16;
      *(int *)(iVar15 + 0x58) = iVar8 + 1;
    }
    iVar8 = param_1 + 0x143fc + (uint)*(byte *)((int)param_2 + 0x13) * 0xc;
    iVar15 = iVar8 + 0x6c;
    if (*(char *)(param_1 + 0x590) != '\0') goto LAB_00007a1e;
    iVar15 = *(int *)(iVar8 + 0x6c);
    *(int *)(*(int *)(iVar8 + 0x74) + iVar15 * 4) = iVar16;
    *(int *)(iVar8 + 0x6c) = iVar15 + -1;
    break;
  case '\a':
    uVar9 = *(undefined4 *)(param_2 + 2);
    uVar10 = *(undefined4 *)(param_2 + 4);
    uVar11 = *(undefined4 *)(param_2 + 6);
    iVar13 = iVar13 * 4;
    iVar15 = iVar8 * 0x10 + iVar15;
    *(undefined4 *)(*(int *)(iVar15 + 0x14c6c) + iVar13) = *(undefined4 *)param_2;
    *(undefined4 *)(iVar13 + *(int *)(iVar15 + 0x14c70)) = uVar9;
    *(undefined4 *)(iVar13 + *(int *)(iVar15 + 0x14c74)) = uVar10;
    *(undefined4 *)(iVar13 + *(int *)(iVar15 + 0x14c78)) = uVar11;
    sVar2 = param_2[3];
    sVar3 = param_2[2];
    sVar4 = param_2[5];
    sVar5 = param_2[4];
    sVar6 = param_2[7];
    sVar7 = param_2[6];
    *(uint *)(iVar13 + *(int *)(iVar15 + 0x14cbc)) =
         (int)param_2[1] / 2 << 0x10 | (int)*param_2 / 2 & 0xffffU;
    *(uint *)(iVar13 + *(int *)(iVar15 + 0x14cc0)) =
         (int)sVar2 / 2 << 0x10 | (int)sVar3 / 2 & 0xffffU;
    *(uint *)(iVar13 + *(int *)(iVar15 + 0x14cc4)) =
         (int)sVar4 / 2 << 0x10 | (int)sVar5 / 2 & 0xffffU;
    *(uint *)(iVar13 + *(int *)(iVar15 + 0x14cc8)) =
         (int)sVar6 / 2 << 0x10 | (int)sVar7 / 2 & 0xffffU;
    iVar16 = iVar16 + *(int *)(param_1 + 0x153d0);
    iVar15 = param_1 + 0x143fc +
             ((uint)*(byte *)(param_2 + 8) + (uint)*(byte *)((int)param_2 + 0x11) * 2) * 0xc;
    if (*(char *)(param_1 + 0x590) == '\0') {
      iVar8 = *(int *)(iVar15 + 0x84);
      *(int *)(*(int *)(iVar15 + 0x8c) + iVar8 * 4) = iVar16;
      *(int *)(iVar15 + 0x84) = iVar8 + -1;
    }
    else {
      iVar8 = *(int *)(iVar15 + 0x88);
      *(int *)(*(int *)(iVar15 + 0x8c) + iVar8 * 4) = iVar16;
      *(int *)(iVar15 + 0x88) = iVar8 + 1;
    }
    iVar8 = param_1 + 0x143fc +
            ((uint)*(byte *)(param_2 + 9) + (uint)*(byte *)((int)param_2 + 0x13) * 2) * 0xc;
    iVar15 = iVar8 + 0xb4;
    if (*(char *)(param_1 + 0x590) != '\0') goto LAB_00007a1e;
    iVar15 = *(int *)(iVar8 + 0xb4);
    *(int *)(*(int *)(iVar8 + 0xbc) + iVar15 * 4) = iVar16;
    *(int *)(iVar8 + 0xb4) = iVar15 + -1;
  }
  return;
}

/* FUN_000082ff @ 0x82ff (16 bytes) */
int FUN_000082ff()
{
  return "ATIRadeonX1000";
}

/* FUN_0000830f @ 0x830f (5 bytes) */
int FUN_0000830f()
{
  return;
}

/* FUN_00008314 @ 0x8314 (42 bytes) */
int FUN_00008314(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  undefined1 *puVar1;
  
  for (puVar1 = (undefined1 *)(-*(int *)(param_1 + 0x144) & param_2);
      puVar1 < (undefined1 *)(param_2 + param_3); puVar1 = puVar1 + *(int *)(param_1 + 0x144)) {
    clflush(*puVar1);
  }
  return;
}

/* FUN_0000833e @ 0x833e (66 bytes) */
int FUN_0000833e(param_1)
  undefined4 *param_1;
{
  *param_1 = 0x5c8;
  param_1[1] = 0x10030000;
  param_1[2] = 0x1002;
  param_1[3] = 0;
  param_1[4] = 0x1381;
  param_1[5] = 0;
  param_1[6] = 0x1040;
  param_1[7] = 0;
  return param_1 + 8;
}

/* FUN_00008380 @ 0x8380 (381 bytes) */
int FUN_00008380(param_1, param_2)
  undefined4 *param_1;
  uint param_2;
{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  
  *param_1 = 0x850;
  param_1[1] = 0x100;
  param_1[2] = 0x854;
  uVar4 = 0x26010001;
  if (param_2 != 1) {
    uVar4 = 0x6010001;
  }
  param_1[3] = uVar4;
  param_1[4] = 0x878;
  piVar2 = param_1 + 6;
  param_1[5] = 0xf688f688;
  if (1 < (int)param_2) {
    piVar3 = piVar2;
    uVar1 = 1;
    do {
      uVar5 = uVar1 + 2;
      *piVar3 = (int)uVar1 / 2 + 0x855;
      piVar3[1] = (uint)(param_2 == uVar1 + 1) << 0xd | (uVar1 + 6) * 0x100 |
                  (uint)(param_2 == uVar5) << 0x1d | (uVar1 + 7) * 0x1000000 | 0x10001;
      piVar3[2] = (int)uVar1 / 2 + 0x879;
      piVar2 = piVar3 + 4;
      piVar3[3] = -0x9770978;
      piVar3 = piVar2;
      uVar1 = uVar5;
    } while ((int)uVar5 < (int)param_2);
  }
  *piVar2 = 0x824;
  piVar2[1] = 1;
  if ((int)param_2 < 1) {
    uVar1 = 0;
  }
  else {
    uVar5 = 0;
    uVar1 = 0;
    do {
      uVar1 = uVar1 | uVar1 * 8 | 2;
      uVar5 = uVar5 + 1;
    } while (param_2 != uVar5);
  }
  piVar2[2] = 0x825;
  piVar2[3] = uVar1;
  piVar2[4] = 0x10c0;
  piVar2[5] = param_2 * 2 | 0x40000;
  piVar2[6] = 0x10c1;
  piVar3 = piVar2 + 8;
  piVar2[7] = param_2 - 1;
  if (0 < (int)param_2) {
    uVar1 = 0;
    iVar6 = 1;
    piVar2 = piVar3;
    do {
      *piVar2 = uVar1 + 0x101d;
      piVar2[1] = uVar1 * 2 | iVar6 << 6 | 0x28ffe000;
      piVar2[2] = uVar1 + 0x10c8;
      piVar3 = piVar2 + 4;
      piVar2[3] = uVar1 << 5 | uVar1 | 0x10;
      uVar1 = uVar1 + 1;
      iVar6 = iVar6 + 2;
      piVar2 = piVar3;
    } while (param_2 != uVar1);
  }
  return piVar3;
}

/* FUN_000084fd @ 0x84fd (64 bytes) */
int FUN_000084fd(param_1, param_2, param_3, param_4)
  uint *param_1;
  uint param_2;
  uint *param_3;
  int param_4;
{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  
  puVar3 = param_1 + 1;
  *param_1 = (param_4 + -1) * 0x10000 | param_2 | 0x8000;
  if (param_4 != 0) {
    iVar2 = 0;
    do {
      uVar1 = *param_3;
      param_3 = param_3 + 1;
      *puVar3 = uVar1;
      iVar2 = iVar2 + 1;
      puVar3 = puVar3 + 1;
    } while (param_4 != iVar2);
  }
  return puVar3;
}

/* FUN_0000853d @ 0x853d (49 bytes) */
int FUN_0000853d(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  *param_1 = 0x1094;
  param_1[1] = param_2;
  ((int (*)())FUN_000084fd)();
  return;
}

/* FUN_0000856e @ 0x856e (202 bytes) */
int FUN_0000856e(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 *param_1;
  int param_2;
  int param_3;
  int param_4;
  uint param_5;
  undefined4 param_6;
{
  int iVar1;
  
  if (param_4 != 0) {
    param_1 = (undefined4 *)((int (*)())FUN_0000853d)(param_1,0x10000,(param_5 & 0xfffffff) << 2,param_4);
  }
  if (param_2 != 0) {
    param_1 = (undefined4 *)((int (*)())FUN_0000853d)(param_1,0,(param_3 * 3 & 0x1fffffffU) << 1,param_2);
  }
  *param_1 = 0x1180;
  param_1[1] = 0;
  param_1[2] = 0x11ad;
  param_1[3] = 0;
  param_1[4] = 0x1181;
  param_1[5] = param_6;
  param_1[6] = 0x118c;
  iVar1 = (param_3 + -1) * 0x10000;
  param_1[7] = iVar1;
  param_1[8] = 0x118d;
  param_1[9] = iVar1;
  param_1[10] = 0x118e;
  param_1[0xb] = 0;
  param_1[0xc] = 0x1189;
  param_1[0xd] = 0;
  return param_1 + 0xe;
}

/* FUN_00008638 @ 0x8638 (361 bytes) */
int FUN_00008638(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  float *param_2;
  undefined4 *param_3;
  uint param_4;
  uint param_5;
{
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
  *param_1 = 0x82d;
  param_1[1] = 4;
  param_1[2] = 0xc0103500;
  param_1[3] = 0x4083d;
  if (param_2 == (float *)0x0) {
    local_20 = 0.0;
    local_24 = 1.0;
    local_28 = 0.0;
    local_2c = 1.0;
  }
  else {
    if ((int)param_4 < 0) {
      local_20 = (float)param_4;
      local_24 = param_2[1] / local_20;
      local_28 = param_2[2];
    }
    else {
      local_20 = (float)(int)param_4;
      local_24 = param_2[1] / local_20;
      local_28 = param_2[2];
    }
    local_20 = *param_2 / local_20;
    local_28 = local_28 / (float)param_5;
    local_2c = param_2[3] / (float)param_5;
  }
  param_1[4] = *param_3;
  param_1[5] = param_3[2];
  param_1[6] = local_20;
  param_1[7] = local_28;
  param_1[8] = *param_3;
  param_1[9] = param_3[3];
  param_1[10] = local_20;
  param_1[0xb] = local_2c;
  param_1[0xc] = param_3[1];
  param_1[0xd] = param_3[3];
  param_1[0xe] = local_24;
  param_1[0xf] = local_2c;
  param_1[0x10] = param_3[1];
  param_1[0x11] = param_3[2];
  param_1[0x12] = local_24;
  param_1[0x13] = local_28;
  param_1[0x14] = 0x1393;
  param_1[0x15] = 10;
  return param_1 + 0x16;
}

/* FUN_000087a1 @ 0x87a1 (1065 bytes) */
int FUN_000087a1(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  uint *puVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  longdouble lVar12;
  float fVar13;
  int local_4c;
  int local_48;
  undefined4 local_2c;
  float local_28;
  undefined4 local_24;
  float local_20;
  
  uVar9 = *(uint *)(param_1 + 0x578) >> 2;
  uVar10 = *(uint *)(param_1 + 0x57c) >> 1;
  uVar4 = *(uint *)(param_1 + 0x588);
  puVar7 = *(undefined4 **)(param_1 + 0x34);
  if (*(undefined4 **)(param_1 + 0x38) <= puVar7 + 0x90) {
    puVar5 = *(uint **)(param_1 + 0x30);
    *puVar5 = *puVar5 | (int)puVar7 - (int)puVar5 >> 2;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)PTR_0000e0e6,param_1 + 0x40
                        ,param_1 + 0x44,1);
    iVar11 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x30) = iVar11 + 0x1c;
    *(int *)(param_1 + 0x34) = iVar11 + 0x20;
    *(int *)(param_1 + 0x38) = iVar11 + 0x20 + *(int *)(iVar11 + 0x10) * 4;
    *(undefined4 *)(iVar11 + 0x1c) = 0;
    puVar7 = *(undefined4 **)(param_1 + 0x34);
  }
  local_48 = param_1 + 0x40;
  local_4c = param_1 + 0x44;
  *(undefined4 **)(param_1 + 0x34) = puVar7 + 0x90;
  puVar5 = *(uint **)(param_1 + 0x30);
  *puVar5 = *puVar5 | (int)puVar7 - (int)puVar5 >> 2;
  *(undefined4 **)(param_1 + 0x30) = puVar7;
  *puVar7 = 0x42000000;
  puVar7[1] = param_2;
  puVar7[2] = (uint)(param_3 != '\0');
  puVar7 = puVar7 + 3;
  iVar11 = 7;
  do {
    *puVar7 = 0x80000000;
    puVar7 = puVar7 + 1;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  uVar6 = ((int (*)())FUN_0000833e)(puVar7);
  puVar7 = (undefined4 *)((int (*)())FUN_00008380)(uVar6,1);
  *puVar7 = 0x1041;
  puVar7[1] = 3;
  puVar7[2] = 0x1100;
  puVar7[3] = 0xa92;
  puVar7[4] = 0x1110;
  puVar7[5] = 0;
  puVar7[6] = 0x1120;
  uVar8 = uVar9 - 1 | (uVar10 - 1) * 0x800 | 0x80000000;
  puVar7[7] = uVar8;
  puVar7[8] = 0x1130;
  puVar7[9] = 0xa60c;
  puVar7[10] = 0x1140;
  iVar11 = (uVar4 >> 2) - 1;
  puVar7[0xb] = iVar11;
  puVar7[0xc] = 0x1101;
  puVar7[0xd] = 0x10000a92;
  puVar7[0xe] = 0x1111;
  puVar7[0xf] = 0;
  puVar7[0x10] = 0x1121;
  puVar7[0x11] = uVar8;
  puVar7[0x12] = 0x1131;
  puVar7[0x13] = 0x4340c;
  puVar7[0x14] = 0x1141;
  puVar7[0x15] = iVar11;
  fVar1 = *(float *)(param_1 + 300);
  lVar12 = (longdouble)_cos((double)fVar1);
  fVar2 = *(float *)(param_1 + 0x138);
  fVar3 = *(float *)(param_1 + 0x130);
  fVar13 = (float)((double)lVar12 * (double)fVar2 * (double)fVar3);
  lVar12 = (longdouble)_sin((double)fVar1);
  DAT_0000d040 = (float)((double)fVar3 *
                        (double)fVar2 * (double)((ulonglong)(double)lVar12 ^ _DAT_0000ccd0));
  DAT_0000d030 = (((FLOAT_0000b368 - fVar13) - DAT_0000d040) * FLOAT_0000b384) / FLOAT_0000b388;
  DAT_0000d034 = ((DAT_0000d040 + (FLOAT_0000b368 - fVar13)) * FLOAT_0000b384) / FLOAT_0000b388;
  DAT_0000d044 = (uint)DAT_0000d040 ^ _DAT_0000cce0;
  DAT_0000d020 = fVar13;
  DAT_0000d024 = fVar13;
  DAT_0000d028 = fVar13;
  DAT_0000d02c = fVar13;
  DAT_0000d038 = DAT_0000d030;
  DAT_0000d03c = DAT_0000d034;
  DAT_0000d048 = DAT_0000d040;
  DAT_0000d04c = DAT_0000d044;
  puVar7 = (undefined4 *)((int (*)())FUN_0000856e)(puVar7 + 0x16,&DAT_0000ca40,4,&DAT_0000d020,3,3);
  *puVar7 = 0x11a9;
  puVar7[1] = 0x1b00;
  puVar7[2] = 0x11aa;
  puVar7[3] = 0xf;
  puVar7[4] = 0x11ab;
  puVar7[5] = 0xf;
  puVar7[6] = 0x11ac;
  puVar7[7] = 0xf;
  local_2c = 0;
  local_24 = 0;
  local_28 = (float)uVar9;
  local_20 = (float)uVar10;
  ((int (*)())FUN_00008638)(puVar7 + 8,0,&local_2c,uVar9,uVar10);
  puVar5 = *(uint **)(param_1 + 0x30);
  *puVar5 = *puVar5 | *(int *)(param_1 + 0x34) - (int)puVar5 >> 2;
  *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
  **(undefined4 **)(param_1 + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)PTR_0000e0e6,local_48,
                      local_4c,1);
  iVar11 = *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x30) = iVar11 + 0x1c;
  *(int *)(param_1 + 0x34) = iVar11 + 0x20;
  *(int *)(param_1 + 0x38) = iVar11 + 0x20 + *(int *)(iVar11 + 0x10) * 4;
  *(undefined4 *)(iVar11 + 0x1c) = 0;
  return;
}

/* FUN_00008bca @ 0x8bca (804 bytes) */
int FUN_00008bca(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  int local_44;
  int local_40;
  undefined4 local_2c;
  float local_28;
  undefined4 local_24;
  float local_20;
  
  uVar6 = *(uint *)(param_1 + 0x578) >> 2;
  iVar1 = *(int *)(param_1 + 0x57c);
  uVar2 = *(uint *)(param_1 + 0x588);
  puVar5 = *(undefined4 **)(param_1 + 0x34);
  if (*(undefined4 **)(param_1 + 0x38) <= puVar5 + 0x78) {
    puVar3 = *(uint **)(param_1 + 0x30);
    *puVar3 = *puVar3 | (int)puVar5 - (int)puVar3 >> 2;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)PTR_0000e0e6,param_1 + 0x40
                        ,param_1 + 0x44,1);
    iVar7 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x30) = iVar7 + 0x1c;
    *(int *)(param_1 + 0x34) = iVar7 + 0x20;
    *(int *)(param_1 + 0x38) = iVar7 + 0x20 + *(int *)(iVar7 + 0x10) * 4;
    *(undefined4 *)(iVar7 + 0x1c) = 0;
    puVar5 = *(undefined4 **)(param_1 + 0x34);
  }
  local_40 = param_1 + 0x40;
  local_44 = param_1 + 0x44;
  *(undefined4 **)(param_1 + 0x34) = puVar5 + 0x78;
  puVar3 = *(uint **)(param_1 + 0x30);
  *puVar3 = *puVar3 | (int)puVar5 - (int)puVar3 >> 2;
  *(undefined4 **)(param_1 + 0x30) = puVar5;
  *puVar5 = 0x3f000000;
  puVar5[1] = param_2;
  puVar5[2] = (uint)(param_3 != '\0');
  puVar5 = puVar5 + 3;
  iVar7 = 9;
  do {
    *puVar5 = 0x80000000;
    puVar5 = puVar5 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  uVar4 = ((int (*)())FUN_0000833e)(puVar5);
  puVar5 = (undefined4 *)((int (*)())FUN_00008380)(uVar4,1);
  *puVar5 = 0x1041;
  puVar5[1] = 1;
  puVar5[2] = 0x1100;
  puVar5[3] = 0xa92;
  puVar5[4] = 0x1110;
  puVar5[5] = 0;
  puVar5[6] = 0x1120;
  puVar5[7] = uVar6 - 1 | (iVar1 + -1) * 0x800 | 0x80000000;
  puVar5[8] = 0x1130;
  puVar5[9] = 0xa60c;
  puVar5[10] = 0x1140;
  puVar5[0xb] = (uVar2 >> 2) - 1;
  DAT_0000d060 = *(undefined4 *)(param_1 + 0x138);
  DAT_0000d070 = ((FLOAT_0000b368 - *(float *)(param_1 + 0x138)) * FLOAT_0000b384) / FLOAT_0000b388
                 + *(float *)(param_1 + 0x134);
  DAT_0000d064 = DAT_0000d060;
  DAT_0000d068 = DAT_0000d060;
  DAT_0000d06c = DAT_0000d060;
  DAT_0000d074 = DAT_0000d070;
  DAT_0000d078 = DAT_0000d070;
  DAT_0000d07c = DAT_0000d070;
  puVar5 = (undefined4 *)((int (*)())FUN_0000856e)(puVar5 + 0xc,&DAT_0000caa0,2,&DAT_0000d060,2,2);
  *puVar5 = 0x11a9;
  puVar5[1] = 0x1b00;
  puVar5[2] = 0x11aa;
  puVar5[3] = 0xf;
  puVar5[4] = 0x11ab;
  puVar5[5] = 0xf;
  puVar5[6] = 0x11ac;
  puVar5[7] = 0xf;
  local_2c = 0;
  local_24 = 0;
  local_28 = (float)uVar6;
  local_20 = (float)iVar1;
  ((int (*)())FUN_00008638)(puVar5 + 8,0,&local_2c,uVar6,iVar1);
  puVar3 = *(uint **)(param_1 + 0x30);
  *puVar3 = *puVar3 | *(int *)(param_1 + 0x34) - (int)puVar3 >> 2;
  *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
  **(undefined4 **)(param_1 + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)PTR_0000e0e6,local_40,
                      local_44,1);
  iVar1 = *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x30) = iVar1 + 0x1c;
  *(int *)(param_1 + 0x34) = iVar1 + 0x20;
  *(int *)(param_1 + 0x38) = iVar1 + 0x20 + *(int *)(iVar1 + 0x10) * 4;
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  return;
}

/* FUN_00008eee @ 0x8eee (1097 bytes) */
int FUN_00008eee(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  int local_40;
  int local_3c;
  undefined4 *local_30;
  undefined4 local_2c;
  float local_28;
  undefined4 local_24;
  float local_20;
  
  puVar5 = *(undefined4 **)(param_1 + 0x34);
  if (*(undefined4 **)(param_1 + 0x38) <= puVar5 + 0xb0) {
    puVar1 = *(uint **)(param_1 + 0x30);
    *puVar1 = *puVar1 | (int)puVar5 - (int)puVar1 >> 2;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)PTR_0000e0e6,param_1 + 0x40
                        ,param_1 + 0x44,1);
    iVar6 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x30) = iVar6 + 0x1c;
    *(int *)(param_1 + 0x34) = iVar6 + 0x20;
    *(int *)(param_1 + 0x38) = iVar6 + 0x20 + *(int *)(iVar6 + 0x10) * 4;
    *(undefined4 *)(iVar6 + 0x1c) = 0;
    puVar5 = *(undefined4 **)(param_1 + 0x34);
  }
  local_3c = param_1 + 0x44;
  local_40 = param_1 + 0x40;
  *(undefined4 **)(param_1 + 0x34) = puVar5 + 0xb0;
  puVar1 = *(uint **)(param_1 + 0x30);
  *puVar1 = *puVar1 | (int)puVar5 - (int)puVar1 >> 2;
  *(undefined4 **)(param_1 + 0x30) = puVar5;
  *puVar5 = 0x44000000;
  puVar5[1] = (int)param_2;
  puVar5[2] = 0x11;
  puVar5[3] = (uint)(*(char *)((int)param_2 + param_1 + 0xa92) != '\0');
  puVar5[4] = *(undefined4 *)(param_1 + 0x11c);
  puVar5 = puVar5 + 5;
  iVar6 = 5;
  do {
    *puVar5 = 0x80000000;
    puVar5 = puVar5 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  uVar4 = ((int (*)())FUN_0000833e)(puVar5);
  puVar5 = (undefined4 *)((int (*)())FUN_00008380)(uVar4,1);
  *puVar5 = 0x1100;
  puVar5[1] = 0xa92;
  puVar5[2] = 0x1110;
  puVar5[3] = 0;
  puVar5[4] = 0x1120;
  puVar5[5] = (*(int *)(param_1 + 0x57c) + -1) * 0x800 | *(int *)(param_1 + 0x578) - 1U | 0x80000000
  ;
  puVar5[6] = 0x1130;
  puVar5[7] = 0x10120800;
  puVar5[8] = 0x1140;
  puVar5[9] = *(int *)(param_1 + 0x588) + -1;
  puVar5[10] = 0x1101;
  puVar5[0xb] = 0x10000a92;
  puVar5[0xc] = 0x1111;
  puVar5[0xd] = 0;
  puVar5[0xe] = 0x1121;
  puVar5[0xf] = ((*(uint *)(param_1 + 0x57c) >> 1) - 1) * 0x800 |
                (*(uint *)(param_1 + 0x578) >> 1) - 1 | 0x80000000;
  puVar5[0x10] = 0x1131;
  puVar5[0x11] = 0x18044803;
  puVar5[0x12] = 0x1141;
  puVar5[0x13] = (*(uint *)(param_1 + 0x588) >> 1) - 1;
  puVar5[0x14] = 0x1041;
  puVar5[0x15] = 3;
  local_30 = (undefined4 *)((int (*)())FUN_0000856e)(puVar5 + 0x16,&DAT_0000cb40,7,&DAT_0000cae0,5,3);
  iVar6 = *(int *)(param_3 + 0xc);
  if (((iVar6 == 0x61726762) || (iVar6 == 0x61723135)) || (iVar6 != 0x72676261)) {
    *local_30 = 0x11a9;
    local_30[1] = 0x1b00;
  }
  else {
    *local_30 = 0x11a9;
    local_30[1] = 0x6c00;
  }
  local_30[2] = 0x11aa;
  local_30[3] = 0xf;
  local_30[4] = 0x11ab;
  local_30[5] = 0xf;
  local_30[6] = 0x11ac;
  local_30[7] = 0xf;
  local_30[8] = 0x1393;
  local_30[9] = 10;
  if (*(int *)(param_3 + 0xc) == 0x61723135) {
    local_30[10] = 0x138e;
    local_30[0xb] = *(uint *)(param_3 + 8) >> 1 & 0x3ffe | 0x680000;
    uVar2 = *(uint *)(param_1 + 0x578);
  }
  else {
    local_30[10] = 0x138e;
    local_30[0xb] = *(uint *)(param_3 + 8) >> 2 & 0x3ffe | 0xd00000;
    uVar2 = *(uint *)(param_1 + 0x578);
  }
  if ((int)uVar2 < 0) {
    uVar3 = *(uint *)(param_1 + 0x57c);
  }
  else {
    uVar3 = *(uint *)(param_1 + 0x57c);
  }
  local_28 = (float)uVar2;
  local_20 = (float)uVar3;
  local_30 = local_30 + 0xc;
  local_24 = 0;
  local_2c = 0;
  puVar5 = (undefined4 *)((int (*)())FUN_00008638)(local_30,0,&local_2c,uVar2,uVar3);
  *puVar5 = 0x5c8;
  puVar5[1] = 0x10030000;
  puVar1 = *(uint **)(param_1 + 0x30);
  *puVar1 = *puVar1 | *(int *)(param_1 + 0x34) - (int)puVar1 >> 2;
  *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
  **(undefined4 **)(param_1 + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)PTR_0000e0e6,local_40,
                      local_3c,1);
  iVar6 = *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x30) = iVar6 + 0x1c;
  *(int *)(param_1 + 0x34) = iVar6 + 0x20;
  *(int *)(param_1 + 0x38) = iVar6 + 0x20 + *(int *)(iVar6 + 0x10) * 4;
  *(undefined4 *)(iVar6 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0xaa0 + *(int *)(param_1 + 0xa98) * 8) =
       *(undefined4 *)(*(int *)(param_1 + 0x40) + 0x18);
  return;
}

/* FUN_00009337 @ 0x9337 (890 bytes) */
int FUN_00009337(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  int local_48;
  int local_44;
  undefined4 local_2c;
  float local_28;
  undefined4 local_24;
  float local_20;
  
  uVar6 = *(uint *)(param_1 + 0x578) >> 1;
  iVar1 = *(int *)(param_1 + 0x57c);
  uVar2 = *(uint *)(param_1 + 0x588);
  puVar5 = *(undefined4 **)(param_1 + 0x34);
  if (*(undefined4 **)(param_1 + 0x38) <= puVar5 + 0x88) {
    puVar3 = *(uint **)(param_1 + 0x30);
    *puVar3 = *puVar3 | (int)puVar5 - (int)puVar3 >> 2;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)PTR_0000e0e6,param_1 + 0x40
                        ,param_1 + 0x44,1);
    iVar7 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x30) = iVar7 + 0x1c;
    *(int *)(param_1 + 0x34) = iVar7 + 0x20;
    *(int *)(param_1 + 0x38) = iVar7 + 0x20 + *(int *)(iVar7 + 0x10) * 4;
    *(undefined4 *)(iVar7 + 0x1c) = 0;
    puVar5 = *(undefined4 **)(param_1 + 0x34);
  }
  local_44 = param_1 + 0x44;
  local_48 = param_1 + 0x40;
  *(undefined4 **)(param_1 + 0x34) = puVar5 + 0x88;
  puVar3 = *(uint **)(param_1 + 0x30);
  *puVar3 = *puVar3 | (int)puVar5 - (int)puVar3 >> 2;
  *(undefined4 **)(param_1 + 0x30) = puVar5;
  *puVar5 = 0x43000000;
  puVar5[1] = (int)param_2;
  puVar5[2] = 0x11;
  puVar5[3] = (uint)(*(char *)((int)param_2 + param_1 + 0xa92) != '\0');
  puVar5[4] = *(undefined4 *)(param_1 + 0x11c);
  puVar5 = puVar5 + 5;
  iVar7 = 6;
  do {
    *puVar5 = 0x80000000;
    puVar5 = puVar5 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  uVar4 = ((int (*)())FUN_0000833e)(puVar5);
  puVar5 = (undefined4 *)((int (*)())FUN_00008380)(uVar4,1);
  *puVar5 = 0x1041;
  puVar5[1] = 3;
  puVar5[2] = 0x1100;
  puVar5[3] = 0xa92;
  puVar5[4] = 0x1110;
  puVar5[5] = 0;
  puVar5[6] = 0x1120;
  puVar5[7] = (iVar1 + -1) * 0x800 | uVar6 - 1 | 0x80000000;
  puVar5[8] = 0x1130;
  puVar5[9] = 0x10060803;
  puVar5[10] = 0x1140;
  iVar7 = (uVar2 >> 1) - 1;
  puVar5[0xb] = iVar7;
  puVar5[0xc] = 0x1101;
  puVar5[0xd] = 0x10000a92;
  puVar5[0xe] = 0x1111;
  puVar5[0xf] = 0;
  puVar5[0x10] = 0x1121;
  puVar5[0x11] = uVar6 - 1 | (iVar1 / 2 + -1) * 0x800 | 0x80000000;
  puVar5[0x12] = 0x1131;
  puVar5[0x13] = 0x1810c003;
  puVar5[0x14] = 0x1141;
  puVar5[0x15] = iVar7;
  puVar5 = (undefined4 *)((int (*)())FUN_0000856e)(puVar5 + 0x16,&DAT_0000cc00,4,0,0,3);
  *puVar5 = 0x11a9;
  puVar5[1] = 0x1b00;
  puVar5[2] = 0x11aa;
  puVar5[3] = 0xf;
  puVar5[4] = 0x11ab;
  puVar5[5] = 0xf;
  puVar5[6] = 0x11ac;
  puVar5[7] = 0xf;
  puVar5[8] = 0x1393;
  puVar5[9] = 10;
  puVar5[10] = 0x138e;
  puVar5[0xb] = *(uint *)(param_3 + 8) >> 2 & 0x3ffe | 0xd00000;
  local_2c = 0;
  local_24 = 0;
  local_28 = (float)uVar6;
  local_20 = (float)iVar1;
  puVar5 = (undefined4 *)((int (*)())FUN_00008638)(puVar5 + 0xc,0,&local_2c,uVar6,iVar1);
  *puVar5 = 0x5c8;
  puVar5[1] = 0x10030000;
  puVar3 = *(uint **)(param_1 + 0x30);
  *puVar3 = *puVar3 | *(int *)(param_1 + 0x34) - (int)puVar3 >> 2;
  *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
  **(undefined4 **)(param_1 + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)PTR_0000e0e6,local_48,
                      local_44,1);
  iVar1 = *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x30) = iVar1 + 0x1c;
  *(int *)(param_1 + 0x34) = iVar1 + 0x20;
  *(int *)(param_1 + 0x38) = iVar1 + 0x20 + *(int *)(iVar1 + 0x10) * 4;
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0xaa0 + *(int *)(param_1 + 0xa98) * 8) =
       *(undefined4 *)(*(int *)(param_1 + 0x40) + 0x18);
  return;
}

/* FUN_000096b1 @ 0x96b1 (2611 bytes) */
int FUN_000096b1(param_1)
  int param_1;
{
  short sVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  uint *puVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  short sVar8;
  int iVar9;
  uint uVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  short local_5e;
  uint local_5c;
  short local_52;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
  sVar1 = *(short *)(param_1 + 0x126);
  if (sVar1 == 0) {
    uVar10 = *(uint *)(param_1 + 0x578);
    if (((int)*(short *)(param_1 + 0x12a) == uVar10) && (*(short *)(param_1 + 0x124) == 0)) {
      local_5c = *(uint *)(param_1 + 0x57c);
      if ((int)*(short *)(param_1 + 0x128) == local_5c) {
        local_2c = ((float)(int)*(short *)(param_1 + 0x10e) * (float)uVar10) /
                   (float)*(uint *)(param_1 + 0x60);
        local_28 = ((float)(int)*(short *)(param_1 + 0x112) * (float)uVar10) /
                   (float)*(uint *)(param_1 + 0x60);
        local_24 = ((float)(int)*(short *)(param_1 + 0x10c) * (float)local_5c) /
                   (float)*(uint *)(param_1 + 100);
        local_20 = ((float)(int)*(short *)(param_1 + 0x110) * (float)local_5c) /
                   (float)*(uint *)(param_1 + 100);
        local_3c = 0.0;
        local_38 = (float)((int)*(short *)(param_1 + 0x112) - (int)*(short *)(param_1 + 0x10e));
        local_34 = 0.0;
        local_30 = (float)((int)*(short *)(param_1 + 0x110) - (int)*(short *)(param_1 + 0x10c));
        goto LAB_00009b1f;
      }
      goto LAB_000097b7;
    }
    local_5c = *(uint *)(param_1 + 0x57c);
    sVar2 = *(short *)(param_1 + 0x10e);
    uVar4 = *(uint *)(param_1 + 0x60);
  }
  else {
    uVar10 = *(uint *)(param_1 + 0x578);
    local_5c = *(uint *)(param_1 + 0x57c);
LAB_000097b7:
    sVar2 = *(short *)(param_1 + 0x10e);
    uVar4 = *(uint *)(param_1 + 0x60);
  }
  if ((int)uVar10 < 0) {
    local_4c = (float)(int)sVar2 * (float)uVar10;
    if (-1 < (int)uVar4) goto LAB_000097eb;
LAB_00009740:
    local_4c = local_4c / (float)uVar4;
    local_52 = *(short *)(param_1 + 0x112);
    fVar11 = (float)(int)local_52;
    if (-1 < (int)uVar10) goto LAB_00009815;
LAB_00009779:
    fVar11 = fVar11 * (float)uVar10;
  }
  else {
    local_4c = (float)(int)sVar2 * (float)(int)uVar10;
    if ((int)uVar4 < 0) goto LAB_00009740;
LAB_000097eb:
    local_4c = local_4c / (float)(int)uVar4;
    local_52 = *(short *)(param_1 + 0x112);
    fVar11 = (float)(int)local_52;
    if ((int)uVar10 < 0) goto LAB_00009779;
LAB_00009815:
    fVar11 = fVar11 * (float)(int)uVar10;
  }
  fVar11 = fVar11 / (float)uVar4;
  fVar15 = ((float)(int)*(short *)(param_1 + 0x10c) * (float)local_5c) /
           (float)*(uint *)(param_1 + 100);
  fVar13 = ((float)(int)*(short *)(param_1 + 0x110) * (float)local_5c) /
           (float)*(uint *)(param_1 + 100);
  local_48 = (float)(int)sVar1;
  if (fVar11 <= local_48) {
    return;
  }
  if (local_48 < fVar11) {
    local_5e = *(short *)(param_1 + 0x12a);
    if ((float)(int)local_5e <= fVar11) goto LAB_000098d6;
    local_44 = fVar11;
    if (local_48 <= local_4c) {
      local_48 = local_4c;
    }
  }
  else {
    local_5e = *(short *)(param_1 + 0x12a);
LAB_000098d6:
    local_44 = (float)(int)local_5e;
    if (local_44 <= local_4c) {
      return;
    }
    local_48 = (float)(int)sVar1;
    if (local_48 <= local_4c) {
      local_48 = local_4c;
    }
  }
  sVar3 = *(short *)(param_1 + 0x124);
  fVar12 = (float)(int)sVar3;
  if (fVar13 <= fVar12) {
    return;
  }
  if (fVar12 < fVar13) {
    sVar8 = *(short *)(param_1 + 0x128);
    if ((float)(int)sVar8 <= fVar13) goto LAB_00009934;
    fVar14 = fVar15;
    local_40 = fVar13;
    if (fVar15 < fVar12) {
      fVar14 = fVar12;
    }
  }
  else {
    sVar8 = *(short *)(param_1 + 0x128);
LAB_00009934:
    local_40 = (float)(int)sVar8;
    if (local_40 <= fVar15) {
      return;
    }
    fVar14 = (float)(int)sVar3;
    if ((float)(int)sVar3 <= fVar15) {
      fVar14 = fVar15;
    }
  }
  local_3c = ((local_48 - local_4c) / (fVar11 - local_4c)) * (float)((int)local_52 - (int)sVar2);
  local_38 = (FLOAT_0000b368 - (fVar11 - local_44) / (fVar11 - local_4c)) *
             (float)((int)local_52 - (int)sVar2);
  local_30 = (float)((int)*(short *)(param_1 + 0x110) - (int)*(short *)(param_1 + 0x10c));
  local_34 = ((fVar14 - fVar15) / (fVar13 - fVar15)) * local_30;
  local_30 = (FLOAT_0000b368 - (fVar13 - local_40) / (fVar13 - fVar15)) * local_30;
  fVar15 = (float)uVar10 / (float)((int)local_5e - (int)sVar1);
  fVar13 = (float)local_5c / (float)((int)sVar8 - (int)sVar3);
  local_28 = (float)((int)local_5e + (int)sVar1) * FLOAT_0000b38c;
  fVar11 = (float)((int)sVar8 + (int)sVar3) * FLOAT_0000b38c;
  local_2c = (local_48 - local_28) * fVar15 + local_28;
  local_2c = (float)((uint)local_2c & -(uint)(0.0 <= local_2c));
  local_28 = (local_44 - local_28) * fVar15 + local_28;
  if ((float)uVar10 < local_28) {
    local_28 = (float)uVar10;
  }
  local_24 = (float)(int)((fVar14 - fVar11) * fVar13 + fVar11);
  local_24 = (float)((uint)local_24 & -(uint)(0.0 <= local_24));
  local_20 = (float)(int)(fVar11 + fVar13 * (local_40 - fVar11));
  if ((float)local_5c < local_20) {
    local_20 = (float)local_5c;
  }
LAB_00009b1f:
  puVar7 = *(undefined4 **)(param_1 + 0x34);
  if (*(undefined4 **)(param_1 + 0x38) <= puVar7 + 0x70) {
    puVar5 = *(uint **)(param_1 + 0x30);
    *puVar5 = *puVar5 | (int)puVar7 - (int)puVar5 >> 2;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)PTR_0000e0e6,param_1 + 0x40
                        ,param_1 + 0x44,1);
    iVar9 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x30) = iVar9 + 0x1c;
    *(int *)(param_1 + 0x34) = iVar9 + 0x20;
    *(int *)(param_1 + 0x38) = iVar9 + 0x20 + *(int *)(iVar9 + 0x10) * 4;
    *(undefined4 *)(iVar9 + 0x1c) = 0;
    puVar7 = *(undefined4 **)(param_1 + 0x34);
  }
  *(undefined4 **)(param_1 + 0x34) = puVar7 + 0x70;
  puVar5 = *(uint **)(param_1 + 0x30);
  *puVar5 = *puVar5 | (int)puVar7 - (int)puVar5 >> 2;
  *(undefined4 **)(param_1 + 0x30) = puVar7;
  *puVar7 = 0xb000000;
  puVar7[1] = 2;
  puVar7[2] = 1;
  puVar7 = puVar7 + 3;
  iVar9 = 10;
  do {
    *puVar7 = 0x80000000;
    puVar7 = puVar7 + 1;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  uVar6 = ((int (*)())FUN_0000833e)(puVar7);
  puVar7 = (undefined4 *)((int (*)())FUN_00008380)(uVar6,1);
  *puVar7 = 0x1100;
  puVar7[1] = 0xa92;
  puVar7[2] = 0x1110;
  puVar7[3] = 0;
  puVar7[4] = 0x1120;
  puVar7[5] = ((int)*(short *)(param_1 + 0x112) - (int)*(short *)(param_1 + 0x10e)) - 1U |
              (((int)*(short *)(param_1 + 0x110) - (int)*(short *)(param_1 + 0x10c)) + -1) * 0x800 |
              0x80000000;
  puVar7[6] = 0x1130;
  puVar7[7] = 0xa60c;
  puVar7[8] = 0x1140;
  puVar7[9] = *(int *)(param_1 + 0x68) + -1;
  puVar7[10] = 0x1041;
  puVar7[0xb] = 1;
  puVar7 = (undefined4 *)((int (*)())FUN_0000856e)(puVar7 + 0xc,&DAT_0000cc60,2,0,0,1);
  *puVar7 = 0x11a9;
  puVar7[1] = 0x1b00;
  puVar7[2] = 0x11aa;
  puVar7[3] = 0xf;
  puVar7[4] = 0x11ab;
  puVar7[5] = 0xf;
  puVar7[6] = 0x11ac;
  puVar7[7] = 0xf;
  puVar7[8] = 0x1381;
  puVar7[9] = 0x27260005;
  ((int (*)())FUN_00008638)(puVar7 + 10,&local_3c,&local_2c,
               (int)*(short *)(param_1 + 0x112) - (int)*(short *)(param_1 + 0x10e),
               (int)*(short *)(param_1 + 0x110) - (int)*(short *)(param_1 + 0x10c));
  return;
}

/* FUN_0000a0e4 @ 0xa0e4 (749 bytes) */
int FUN_0000a0e4(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  uint *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 local_3c;
  float local_38;
  undefined4 local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
  puVar3 = *(undefined4 **)(param_1 + 0x34);
  if (*(undefined4 **)(param_1 + 0x38) <= puVar3 + 0xb0) {
    puVar1 = *(uint **)(param_1 + 0x30);
    *puVar1 = *puVar1 | (int)puVar3 - (int)puVar1 >> 2;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)PTR_0000e0e6,param_1 + 0x40
                        ,param_1 + 0x44,1);
    iVar4 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x30) = iVar4 + 0x1c;
    *(int *)(param_1 + 0x34) = iVar4 + 0x20;
    *(int *)(param_1 + 0x38) = iVar4 + 0x20 + *(int *)(iVar4 + 0x10) * 4;
    *(undefined4 *)(iVar4 + 0x1c) = 0;
    puVar3 = *(undefined4 **)(param_1 + 0x34);
  }
  *(undefined4 **)(param_1 + 0x34) = puVar3 + 0xb0;
  puVar1 = *(uint **)(param_1 + 0x30);
  *puVar1 = *puVar1 | (int)puVar3 - (int)puVar1 >> 2;
  *(undefined4 **)(param_1 + 0x30) = puVar3;
  *puVar3 = 0xa000000;
  puVar3[1] = param_2;
  puVar3[2] = (uint)(param_3 != '\0');
  puVar3[3] = *(undefined4 *)(param_1 + 0x11c);
  puVar3 = puVar3 + 4;
  iVar4 = 0x10;
  do {
    *puVar3 = 0x80000000;
    puVar3 = puVar3 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  uVar2 = ((int (*)())FUN_0000833e)(puVar3);
  puVar3 = (undefined4 *)((int (*)())FUN_00008380)(uVar2,1);
  *puVar3 = 0x1100;
  puVar3[1] = 0x1492;
  puVar3[2] = 0x1110;
  puVar3[3] = 0;
  puVar3[4] = 0x1120;
  puVar3[5] = (*(int *)(param_1 + 0x57c) + -1) * 0x800 | *(int *)(param_1 + 0x578) - 1U | 0x80000000
  ;
  puVar3[6] = 0x1130;
  puVar3[7] = 0x10120800;
  puVar3[8] = 0x1101;
  puVar3[9] = 0x10001492;
  puVar3[10] = 0x1111;
  puVar3[0xb] = 0;
  puVar3[0xc] = 0x1121;
  puVar3[0xd] = ((*(uint *)(param_1 + 0x57c) >> 1) - 1) * 0x800 |
                (*(uint *)(param_1 + 0x578) >> 1) - 1 | 0x80000000;
  puVar3[0xe] = 0x1131;
  puVar3[0xf] = 0x18044803;
  puVar3[0x10] = 0x1041;
  puVar3[0x11] = 3;
  puVar3 = (undefined4 *)((int (*)())FUN_0000856e)(puVar3 + 0x12,&DAT_0000cb40,7,&DAT_0000cae0,5,3);
  *puVar3 = 0x11a9;
  puVar3[1] = 0x1b00;
  puVar3[2] = 0x11aa;
  puVar3[3] = 0xf;
  puVar3[4] = 0x11ab;
  puVar3[5] = 0xf;
  puVar3[6] = 0x11ac;
  puVar3[7] = 0xf;
  local_2c = (float)(int)*(short *)(param_1 + 0x126);
  local_28 = (float)(int)*(short *)(param_1 + 0x12a);
  local_24 = (float)(int)*(short *)(param_1 + 0x124);
  local_20 = (float)(int)*(short *)(param_1 + 0x128);
  local_3c = 0;
  local_34 = 0;
  local_38 = (float)*(uint *)(param_1 + 0x578);
  local_30 = (float)*(uint *)(param_1 + 0x57c);
  ((int (*)())FUN_00008638)(puVar3 + 8,&local_2c,&local_3c,*(uint *)(param_1 + 0x578),*(uint *)(param_1 + 0x57c))
  ;
  return;
}

/* FUN_0000a3d1 @ 0xa3d1 (715 bytes) */
int FUN_0000a3d1(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
  int param_6;
{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int local_38;
  int local_34;
  int local_30;
  undefined4 local_2c;
  float local_28;
  undefined4 local_24;
  float local_20;
  
  if (param_6 < 5) {
    iVar2 = (int)(4 / (longlong)param_6);
    local_30 = param_4 / iVar2 + (uint)(param_4 % iVar2 != 0);
    puVar4 = *(undefined4 **)(param_1 + 0x34);
    if (puVar4 + 0x70 < *(undefined4 **)(param_1 + 0x38)) goto LAB_0000a42f;
  }
  else {
    local_30 = (param_6 >> 2) * param_4;
    puVar4 = *(undefined4 **)(param_1 + 0x34);
    if (puVar4 + 0x70 < *(undefined4 **)(param_1 + 0x38)) goto LAB_0000a42f;
  }
  puVar1 = *(uint **)(param_1 + 0x30);
  *puVar1 = *puVar1 | (int)puVar4 - (int)puVar1 >> 2;
  *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
  **(undefined4 **)(param_1 + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)PTR_0000e0e6,param_1 + 0x40,
                      param_1 + 0x44,1);
  iVar2 = *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x30) = iVar2 + 0x1c;
  *(int *)(param_1 + 0x34) = iVar2 + 0x20;
  *(int *)(param_1 + 0x38) = iVar2 + 0x20 + *(int *)(iVar2 + 0x10) * 4;
  *(undefined4 *)(iVar2 + 0x1c) = 0;
  puVar4 = *(undefined4 **)(param_1 + 0x34);
LAB_0000a42f:
  local_34 = param_1 + 0x40;
  local_38 = param_1 + 0x44;
  *(undefined4 **)(param_1 + 0x34) = puVar4 + 0x70;
  puVar1 = *(uint **)(param_1 + 0x30);
  *puVar1 = *puVar1 | (int)puVar4 - (int)puVar1 >> 2;
  *(undefined4 **)(param_1 + 0x30) = puVar4;
  *puVar4 = 0x47000000;
  puVar4[1] = param_2;
  puVar4[2] = param_3;
  puVar4 = puVar4 + 3;
  iVar2 = 0xe;
  do {
    *puVar4 = 0x80000000;
    puVar4 = puVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  uVar3 = ((int (*)())FUN_0000833e)(puVar4);
  puVar4 = (undefined4 *)((int (*)())FUN_00008380)(uVar3,1);
  *puVar4 = 0x1100;
  puVar4[1] = 0xa92;
  puVar4[2] = 0x1110;
  puVar4[3] = 0;
  puVar4[4] = 0x1120;
  puVar4[5] = (param_5 + -1) * 0x800 | local_30 - 1U | 0x80000000;
  puVar4[6] = 0x1130;
  puVar4[7] = 0xa60c;
  puVar4[8] = 0x1041;
  puVar4[9] = 1;
  puVar4 = (undefined4 *)((int (*)())FUN_0000856e)(puVar4 + 10,&DAT_0000cca0,2,0,0,1);
  *puVar4 = 0x11a9;
  puVar4[1] = 0x1b00;
  puVar4[2] = 0x11aa;
  puVar4[3] = 0xf;
  puVar4[4] = 0x11ab;
  puVar4[5] = 0xf;
  puVar4[6] = 0x11ac;
  puVar4[7] = 0xf;
  local_2c = 0;
  local_24 = 0;
  local_28 = (float)local_30;
  local_20 = (float)param_5;
  ((int (*)())FUN_00008638)(puVar4 + 8,0,&local_2c,local_30,param_5);
  puVar1 = *(uint **)(param_1 + 0x30);
  *puVar1 = *puVar1 | *(int *)(param_1 + 0x34) - (int)puVar1 >> 2;
  *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
  **(undefined4 **)(param_1 + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)PTR_0000e0e6,local_34,
                      local_38,1);
  iVar2 = *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x30) = iVar2 + 0x1c;
  *(int *)(param_1 + 0x34) = iVar2 + 0x20;
  *(int *)(param_1 + 0x38) = iVar2 + 0x20 + *(int *)(iVar2 + 0x10) * 4;
  *(undefined4 *)(iVar2 + 0x1c) = 0;
  return;
}

/* FUN_0000a69c @ 0xa69c (42 bytes) */
int FUN_0000a69c(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  undefined1 *puVar1;
  
  for (puVar1 = (undefined1 *)(-*(int *)(param_1 + 0x144) & param_2);
      puVar1 < (undefined1 *)(param_2 + param_3); puVar1 = puVar1 + *(int *)(param_1 + 0x144)) {
    clflush(*puVar1);
  }
  return;
}

/* FUN_0000a6c6 @ 0xa6c6 (323 bytes) */
int FUN_0000a6c6(param_1)
  int param_1;
{
  uint *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int local_24;
  int local_20;
  
  puVar3 = *(undefined4 **)(param_1 + 0x34);
  if (*(undefined4 **)(param_1 + 0x38) <= puVar3 + 0x10) {
    puVar1 = *(uint **)(param_1 + 0x30);
    *puVar1 = *puVar1 | (int)puVar3 - (int)puVar1 >> 2;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)PTR_0000e0e6,param_1 + 0x40
                        ,param_1 + 0x44,1);
    iVar2 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x30) = iVar2 + 0x1c;
    *(int *)(param_1 + 0x34) = iVar2 + 0x20;
    *(int *)(param_1 + 0x38) = iVar2 + 0x20 + *(int *)(iVar2 + 0x10) * 4;
    *(undefined4 *)(iVar2 + 0x1c) = 0;
    puVar3 = *(undefined4 **)(param_1 + 0x34);
  }
  local_20 = param_1 + 0x40;
  local_24 = param_1 + 0x44;
  *(undefined4 **)(param_1 + 0x34) = puVar3 + 0x10;
  puVar1 = *(uint **)(param_1 + 0x30);
  *puVar1 = *puVar1 | (int)puVar3 - (int)puVar1 >> 2;
  *(undefined4 **)(param_1 + 0x30) = puVar3;
  *puVar3 = 0x15000000;
  puVar3[1] = 0x20202020;
  puVar1 = *(uint **)(param_1 + 0x30);
  *puVar1 = *puVar1 | *(int *)(param_1 + 0x34) - (int)puVar1 >> 2;
  *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
  **(undefined4 **)(param_1 + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)PTR_0000e0e6,local_20,
                      local_24,1);
  iVar2 = *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x30) = iVar2 + 0x1c;
  *(int *)(param_1 + 0x34) = iVar2 + 0x20;
  *(int *)(param_1 + 0x38) = iVar2 + 0x20 + *(int *)(iVar2 + 0x10) * 4;
  *(undefined4 *)(iVar2 + 0x1c) = 0;
  return;
}

/* FUN_0000a809 @ 0xa809 (554 bytes) */
int FUN_0000a809(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 *param_2;
  int param_3;
  int param_4;
  int param_5;
{
  uint uVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  float fVar6;
  float fVar7;
  uint local_34;
  uint local_30;
  
  if (param_4 == 1) {
    local_34 = *(uint *)(param_1 + 0x578);
    local_30 = *(uint *)(param_1 + 0x57c) >> 1;
    uVar1 = *(uint *)(param_1 + 0x588);
  }
  else {
    local_34 = *(uint *)(param_1 + 0x578);
    local_30 = *(uint *)(param_1 + 0x57c) >> 2;
    uVar1 = *(uint *)(param_1 + 0x588);
  }
  local_34 = local_34 >> 2;
  iVar3 = 0x18;
  puVar5 = param_2;
  do {
    *puVar5 = 0x80000000;
    puVar5 = puVar5 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  param_2[0x18] = 0x1120;
  uVar4 = local_34 - 1 | (local_30 - 1) * 0x800 | 0x80000000;
  param_2[0x19] = uVar4;
  param_2[0x1a] = 0x1140;
  iVar3 = (uVar1 >> 2) * 2 + -1;
  param_2[0x1b] = iVar3;
  param_2[0x1c] = 0x1121;
  param_2[0x1d] = uVar4;
  param_2[0x1e] = 0x1141;
  param_2[0x1f] = iVar3;
  param_2[0x20] = 0x1122;
  param_2[0x21] = uVar4;
  param_2[0x22] = 0x1142;
  param_2[0x23] = iVar3;
  param_2[0x24] = 0x1123;
  param_2[0x25] = uVar4;
  param_2[0x26] = 0x1143;
  param_2[0x27] = iVar3;
  param_2[0x28] = 0x1124;
  param_2[0x29] = uVar4;
  param_2[0x2a] = 0x1144;
  param_2[0x2b] = iVar3;
  param_2[0x2c] = 0x82d;
  param_2[0x2d] = 4;
  param_2[0x2e] = 0xc0103500;
  param_2[0x2f] = 0x4003d;
  fVar2 = FLOAT_0000b368;
  fVar7 = FLOAT_0000b368;
  if (param_5 == 1) {
    if (*(int *)(param_3 + 8) == 0) goto LAB_0000a946;
  }
  else if (*(int *)(param_3 + 8) != 0) goto LAB_0000a946;
  fVar7 = FLOAT_0000b364;
LAB_0000a946:
  fVar6 = fVar7 / (float)local_30 + 0.0;
  fVar7 = fVar7 / (float)local_30 + FLOAT_0000b368;
  param_2[0x30] = 0;
  param_2[0x31] = 0;
  param_2[0x32] = 0;
  param_2[0x33] = fVar6;
  param_2[0x34] = local_30 << 0x10;
  param_2[0x35] = 0x10000;
  param_2[0x36] = 0;
  param_2[0x37] = fVar7;
  param_2[0x38] = local_30 << 0x10 | local_34;
  param_2[0x39] = &DAT_00010001;
  param_2[0x3a] = fVar2;
  param_2[0x3b] = fVar7;
  param_2[0x3c] = local_34;
  param_2[0x3d] = 1;
  param_2[0x3e] = fVar2;
  param_2[0x3f] = fVar6;
  param_2[0x40] = 0x1393;
  param_2[0x41] = 10;
  return param_2 + 0x42;
}

/* FUN_0000aa33 @ 0xaa33 (1205 bytes) */
int FUN_0000aa33(param_1, param_2, param_3, param_4)
  int param_1;
  char *param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  uint *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  uint uVar7;
  int local_30;
  int local_2c;
  int local_20;
  
  puVar5 = *(undefined4 **)(param_1 + 0x34);
  if (*(undefined4 **)(param_1 + 0x38) <= puVar5 + 0x188) {
    puVar1 = *(uint **)(param_1 + 0x30);
    *puVar1 = *puVar1 | (int)puVar5 - (int)puVar1 >> 2;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)PTR_0000e0e6,param_1 + 0x40
                        ,param_1 + 0x44,1);
    iVar4 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x30) = iVar4 + 0x1c;
    *(int *)(param_1 + 0x34) = iVar4 + 0x20;
    *(int *)(param_1 + 0x38) = iVar4 + 0x20 + *(int *)(iVar4 + 0x10) * 4;
    *(undefined4 *)(iVar4 + 0x1c) = 0;
    puVar5 = *(undefined4 **)(param_1 + 0x34);
  }
  local_2c = param_1 + 0x44;
  local_30 = param_1 + 0x40;
  *(undefined4 **)(param_1 + 0x34) = puVar5 + 0x188;
  puVar1 = *(uint **)(param_1 + 0x30);
  *puVar1 = *puVar1 | (int)puVar5 - (int)puVar1 >> 2;
  *(undefined4 **)(param_1 + 0x30) = puVar5;
  *puVar5 = 0x3d000000;
  puVar5[1] = (int)*param_2;
  puVar5[2] = (int)param_2[1];
  puVar5[3] = *(undefined4 *)(param_2 + 8);
  puVar5[4] = param_4;
  puVar5[5] = 0x80000000;
  puVar5[6] = 0x80000000;
  puVar5[7] = 0x80000000;
  puVar5[8] = 0x80000000;
  puVar5[9] = 0x80000000;
  puVar3 = (undefined4 *)((int (*)())FUN_0000833e)(puVar5 + 10);
  *puVar3 = 0x850;
  puVar3[1] = 0x100;
  puVar3[2] = 0x854;
  puVar3[3] = 0x6060006;
  puVar3[4] = 0x855;
  puVar3[5] = 0x2701;
  puVar3[6] = 0x878;
  puVar3[7] = 0xf688f688;
  puVar3[8] = 0x879;
  puVar3[9] = 0xf688f688;
  puVar3[10] = 0x824;
  puVar3[0xb] = 1;
  puVar3[0xc] = 0x825;
  puVar3[0xd] = 0x12;
  puVar3[0xe] = 0x10c0;
  puVar3[0xf] = 0x40004;
  puVar3[0x10] = 0x10c1;
  puVar3[0x11] = 1;
  uVar7 = 0;
  local_20 = 1;
  piVar2 = puVar3 + 0x12;
  do {
    piVar6 = piVar2;
    *piVar6 = uVar7 + 0x101d;
    piVar6[1] = uVar7 * 2 | local_20 << 6 | 0x28ffe000;
    piVar6[2] = uVar7 + 0x10c8;
    piVar6[3] = uVar7 << 5 | uVar7 | 0x10;
    uVar7 = uVar7 + 1;
    local_20 = local_20 + 2;
    piVar2 = piVar6 + 4;
  } while (uVar7 != 2);
  piVar6[4] = 0x1100;
  piVar6[5] = 0xa92;
  piVar6[6] = 0x1110;
  piVar6[7] = 0;
  piVar6[8] = 0x1130;
  piVar6[9] = 0x4000a60c;
  piVar6[10] = 0x1101;
  piVar6[0xb] = 0x10000a92;
  piVar6[0xc] = 0x1111;
  piVar6[0xd] = 0;
  piVar6[0xe] = 0x1131;
  piVar6[0xf] = 0x4800a60c;
  piVar6[0x10] = 0x1102;
  piVar6[0x11] = 0x20000a92;
  piVar6[0x12] = 0x1112;
  piVar6[0x13] = 0;
  piVar6[0x14] = 0x1132;
  piVar6[0x15] = 0x2800a60c;
  piVar6[0x16] = 0x1103;
  piVar6[0x17] = 0x30000a92;
  piVar6[0x18] = 0x1113;
  piVar6[0x19] = 0;
  piVar6[0x1a] = 0x1133;
  piVar6[0x1b] = 0x3000a60c;
  piVar6[0x1c] = 0x1104;
  piVar6[0x1d] = 0x40000a92;
  piVar6[0x1e] = 0x1114;
  piVar6[0x1f] = 0;
  piVar6[0x20] = 0x1134;
  piVar6[0x21] = 0x3800a60c;
  piVar6[0x22] = 0x1041;
  piVar6[0x23] = 0x1f;
  DAT_0000d080 = 0x3f109091;
  DAT_0000d084 = 0x3f109091;
  DAT_0000d088 = 0x3f109091;
  DAT_0000d08c = 0x3f109091;
  DAT_0000d090 = 0x3d40c0c1;
  DAT_0000d094 = 0x3d40c0c1;
  DAT_0000d098 = 0x3d40c0c1;
  DAT_0000d09c = 0x3d40c0c1;
  DAT_0000d0a0 = 0x3e008081;
  DAT_0000d0a4 = 0x3e008081;
  DAT_0000d0a8 = 0x3e008081;
  DAT_0000d0ac = 0x3e008081;
  DAT_0000d0b0 = 0x3e008081;
  DAT_0000d0b4 = 0x3e008081;
  DAT_0000d0b8 = 0x3e008081;
  DAT_0000d0bc = 0x3e008081;
  puVar3 = (undefined4 *)((int (*)())FUN_0000856e)(piVar6 + 0x24,&DAT_0000cd00,0x16,&DAT_0000d080,6,9);
  *puVar3 = 0x11a9;
  puVar3[1] = 0x1b00;
  puVar3[2] = 0x11aa;
  puVar3[3] = 0x1b00;
  puVar3[4] = 0x11ab;
  puVar3[5] = 0x1b00;
  puVar3[6] = 0x11ac;
  puVar3[7] = 0xf;
  puVar5[5] = (int)(puVar3 + 8) - (int)puVar5 >> 2;
  iVar4 = ((int (*)())FUN_0000a809)(param_1,puVar3 + 8,param_2,1,param_4);
  puVar5[6] = iVar4 - (int)puVar5 >> 2;
  ((int (*)())FUN_0000a809)(param_1,iVar4,param_2,2,param_4);
  puVar1 = *(uint **)(param_1 + 0x30);
  *puVar1 = *puVar1 | *(int *)(param_1 + 0x34) - (int)puVar1 >> 2;
  *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
  **(undefined4 **)(param_1 + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)PTR_0000e0e6,local_30,
                      local_2c,1);
  iVar4 = *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x30) = iVar4 + 0x1c;
  *(int *)(param_1 + 0x34) = iVar4 + 0x20;
  *(int *)(param_1 + 0x38) = iVar4 + 0x20 + *(int *)(iVar4 + 0x10) * 4;
  *(undefined4 *)(iVar4 + 0x1c) = 0;
  return;
}

/* FUN_0000aee8 @ 0xaee8 (107 bytes) */
int FUN_0000aee8(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  if (*(int *)(param_1 + 0x120) != 4) {
    *(undefined4 *)(param_1 + 0xaa0 + *(int *)(param_1 + 0xa98) * 8) =
         *(undefined4 *)(*(int *)(param_1 + 0x40) + 0x18);
    return;
  }
  ((int (*)())FUN_0000aa33)(param_1,param_2,param_3,param_4);
  *(undefined4 *)(param_1 + 0xaa0 + *(int *)(param_1 + 0xa98) * 8) =
       *(undefined4 *)(*(int *)(param_1 + 0x40) + 0x18);
  return;
}

/* FUN_0000af53 @ 0xaf53 (855 bytes) */
int FUN_0000af53(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  int local_4c;
  int local_48;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
  uVar1 = *(uint *)(param_1 + 0x60);
  uVar4 = uVar1 >> 1;
  iVar2 = *(int *)(param_1 + 100);
  local_34 = (float)(int)(short)param_2;
  local_3c = (float)(param_2 >> 0x10) * FLOAT_0000b38c;
  local_30 = (float)(int)(short)param_3;
  local_38 = (float)(param_3 >> 0x10) * FLOAT_0000b38c;
  puVar6 = *(undefined4 **)(param_1 + 0x34);
  local_2c = local_3c;
  local_28 = local_38;
  local_24 = local_34;
  local_20 = local_30;
  if (*(undefined4 **)(param_1 + 0x38) <= puVar6 + 0xa8) {
    puVar3 = *(uint **)(param_1 + 0x30);
    *puVar3 = *puVar3 | (int)puVar6 - (int)puVar3 >> 2;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)PTR_0000e0e6,param_1 + 0x40
                        ,param_1 + 0x44,1);
    iVar7 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x30) = iVar7 + 0x1c;
    *(int *)(param_1 + 0x34) = iVar7 + 0x20;
    *(int *)(param_1 + 0x38) = iVar7 + 0x20 + *(int *)(iVar7 + 0x10) * 4;
    *(undefined4 *)(iVar7 + 0x1c) = 0;
    puVar6 = *(undefined4 **)(param_1 + 0x34);
  }
  local_48 = param_1 + 0x40;
  local_4c = param_1 + 0x44;
  *(undefined4 **)(param_1 + 0x34) = puVar6 + 0xa8;
  puVar3 = *(uint **)(param_1 + 0x30);
  *puVar3 = *puVar3 | (int)puVar6 - (int)puVar3 >> 2;
  *(undefined4 **)(param_1 + 0x30) = puVar6;
  *puVar6 = 0x18000000;
  puVar6[1] = param_4;
  puVar6[2] = 3;
  puVar6[3] = param_5;
  puVar6 = puVar6 + 4;
  iVar7 = 8;
  do {
    *puVar6 = 0x80000000;
    puVar6 = puVar6 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  uVar5 = ((int (*)())FUN_0000833e)(puVar6);
  puVar6 = (undefined4 *)((int (*)())FUN_00008380)(uVar5,1);
  *puVar6 = 0x1100;
  puVar6[1] = 0xa92;
  puVar6[2] = 0x1110;
  puVar6[3] = 0;
  puVar6[4] = 0x1120;
  puVar6[5] = (iVar2 + -1) * 0x800 | (uVar1 >> 2) - 1 | 0x80000000;
  puVar6[6] = 0x1130;
  puVar6[7] = 0x10108802;
  puVar6[8] = 0x1140;
  puVar6[9] = 0xbf;
  puVar6[10] = 0x1101;
  puVar6[0xb] = 0x10000a92;
  puVar6[0xc] = 0x1111;
  puVar6[0xd] = 0;
  puVar6[0xe] = 0x1121;
  puVar6[0xf] = 0x8000000f;
  puVar6[0x10] = 0x1131;
  puVar6[0x11] = 0x1800a60e;
  puVar6[0x12] = 0x1141;
  puVar6[0x13] = 0xf;
  puVar6[0x14] = 0x1041;
  puVar6[0x15] = 3;
  DAT_0000d0e0 = (float)uVar4;
  DAT_0000d0e4 = DAT_0000d0e0;
  DAT_0000d0e8 = DAT_0000d0e0;
  DAT_0000d0ec = DAT_0000d0e0;
  puVar6 = (undefined4 *)((int (*)())FUN_0000856e)(puVar6 + 0x16,&DAT_0000cf20,9,&DAT_0000d0e0,1,4);
  *puVar6 = 0x11a9;
  puVar6[1] = FUN_00001b05;
  puVar6[2] = 0x11aa;
  puVar6[3] = 0xf;
  puVar6[4] = 0x11ab;
  puVar6[5] = 0xf;
  puVar6[6] = 0x11ac;
  puVar6[7] = 0xf;
  ((int (*)())FUN_00008638)(puVar6 + 8,&local_2c,&local_3c,uVar4,iVar2);
  puVar3 = *(uint **)(param_1 + 0x30);
  *puVar3 = *puVar3 | *(int *)(param_1 + 0x34) - (int)puVar3 >> 2;
  *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
  **(undefined4 **)(param_1 + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)PTR_0000e0e6,local_48,
                      local_4c,1);
  iVar2 = *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x30) = iVar2 + 0x1c;
  *(int *)(param_1 + 0x34) = iVar2 + 0x20;
  *(int *)(param_1 + 0x38) = iVar2 + 0x20 + *(int *)(iVar2 + 0x10) * 4;
  *(undefined4 *)(iVar2 + 0x1c) = 0;
  return;
}

/* __i686_get_pc_thunk_bx @ 0xb344 (4 bytes) */
int __i686_get_pc_thunk_bx()
{
  return;
}

/* __i686_get_pc_thunk_cx @ 0xb348 (4 bytes) */
int __i686_get_pc_thunk_cx()
{
  return;
}

