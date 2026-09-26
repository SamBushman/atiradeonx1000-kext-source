#include "decls.h"

/* FUN_0002dcf0 @ 0x2dcf0 (236 bytes) */
int FUN_0002dcf0(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  
  iVar3 = *(int *)(param_1 + 0x30);
  bVar1 = *(byte *)(iVar3 + 1);
  bVar5 = bVar1 & 0xf;
  *(byte *)(param_1 + 0x6c) = bVar5;
  iVar3 = *(short *)(iVar3 + 0x3c) * 0x18 + iVar3;
  uVar4 = (uint)*(byte *)(iVar3 + 0xaa);
  uVar6 = (uint)*(ushort *)(iVar3 + 0xa4) + uVar4 * -2;
  if ((int)uVar6 < 1) {
    uVar6 = 1;
  }
  uVar2 = (uint)*(ushort *)(iVar3 + 0xa6) + uVar4 * -2;
  if ((int)uVar2 < 1) {
    uVar2 = 1;
  }
  uVar4 = (uint)*(ushort *)(iVar3 + 0xa8) + uVar4 * -2;
  if ((int)uVar4 < 1) {
    uVar4 = 1;
  }
  if (bVar5 == 1) {
    if ((uVar6 & uVar6 - 1) != 0) {
      return 1;
    }
    if ((uVar2 & uVar2 - 1) != 0) {
      return 1;
    }
    uVar6 = uVar4 & uVar4 - 1;
  }
  else if (((bVar1 & 0xf) == 0) || (bVar5 == 3)) {
    if ((uVar6 & uVar6 - 1) != 0) {
      return 1;
    }
    uVar6 = uVar2 & uVar2 - 1;
  }
  else {
    if (bVar5 != 4) {
      return 1;
    }
    uVar6 = uVar6 & uVar6 - 1;
  }
  if (uVar6 != 0) {
    return 1;
  }
  return 0;
}

/* FUN_0002ddf0 @ 0x2ddf0 (3396 bytes) */
int FUN_0002ddf0(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  ushort uVar8;
  ushort uVar9;
  short sVar10;
  undefined2 uVar11;
  float fVar12;
  undefined *puVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  char cVar24;
  byte bVar25;
  int iVar26;
  ushort *puVar27;
  char cVar29;
  int iVar28;
  int *piVar30;
  double dVar31;
  double dVar32;
  
  piVar30 = param_2 + 0xf;
  param_2[0x2e] = (int)param_2;
  dVar31 = DOUBLE_001aa240;
  puVar27 = (ushort *)param_2[0xc];
  *(byte *)((int)param_2 + 0x3d) = (byte)(-(uint)puVar27[0x2e] >> 0x1f);
  uVar15 = (uint)((double)*(float *)(puVar27 + 0x18) + dVar31);
  uVar17 = (uint)((double)*(float *)(puVar27 + 0x1a) + dVar31);
  uVar14 = (uint)*(byte *)(puVar27 + 0x2f);
  uVar16 = uVar15 + uVar14;
  if ((int)uVar16 < 0) {
    uVar16 = 0;
  }
  if ((int)uVar14 < (int)uVar16) {
    uVar14 = uVar16;
  }
  uVar22 = (uint)(short)puVar27[0x1e];
  uVar16 = uVar17 + uVar22;
  if (((int)uVar16 < (int)uVar14) && (uVar14 = uVar22, (int)uVar22 < (int)uVar16)) {
    uVar14 = uVar16;
  }
  uVar16 = (uint)*(byte *)((int)puVar27 + 0x5f);
  if ((int)uVar14 <= (int)(uint)*(byte *)((int)puVar27 + 0x5f)) {
    uVar16 = uVar14;
  }
  if ((int)uVar15 < 0) {
    uVar15 = 0;
  }
  if ((int)uVar15 < (int)uVar17) {
    uVar17 = uVar15;
  }
  if ((int)((int)(short)puVar27[0x1f] - uVar22) < (int)uVar17) {
    uVar17 = (int)(short)puVar27[0x1f] - uVar22;
  }
  uVar15 = uVar17;
  if ((int)(uint)*(byte *)(puVar27 + 0x32) < (int)uVar17) {
    uVar15 = (uint)*(byte *)(puVar27 + 0x32);
  }
  if ((int)uVar15 < 0) {
    uVar15 = 0;
  }
  uVar15 = uVar15 & 0xff;
  uVar14 = uVar17;
  if ((int)(uint)*(byte *)((int)puVar27 + 0x65) < (int)uVar17) {
    uVar14 = (uint)*(byte *)((int)puVar27 + 0x65);
  }
  if ((int)uVar14 < 0) {
    uVar14 = 0;
  }
  uVar14 = uVar14 & 0xff;
  if ((int)(uint)*(byte *)(puVar27 + 0x33) < (int)uVar17) {
    uVar17 = (uint)*(byte *)(puVar27 + 0x33);
  }
  if ((int)uVar17 < 0) {
    uVar17 = 0;
  }
  uVar4 = *(ushort *)(param_2 + 0x1d);
  bVar1 = *(byte *)((int)param_2 + 0x73);
  uVar5 = *(ushort *)((int)param_2 + 0x7a);
  uVar18 = (uint)*(ushort *)((int)param_2 + 0x3e);
  uVar6 = *(ushort *)(param_2 + 0x1f);
  uVar7 = *(ushort *)((int)param_2 + 0x76);
  uVar22 = (uint)uVar7;
  uVar8 = *(ushort *)(param_2 + 0x1e);
  uVar21 = (uint)uVar8;
  *(undefined1 *)((int)param_2 + 0x6e) = *(undefined1 *)(puVar27 + 0x35);
  bVar2 = *(byte *)(param_2 + 0x1b);
  *(ushort *)(param_2 + 0x1d) = puVar27[1];
  uVar20 = (uint)*(byte *)(param_2 + 0xe);
  *(byte *)((int)param_2 + 0x73) = *(byte *)(param_2 + 0xe);
  uVar17 = (uint)*(byte *)(puVar27 + 0x33) - (uVar17 & 0xff);
  *(short *)((int)param_2 + 0x7a) = (short)uVar17;
  uVar9 = puVar27[1];
  uVar19 = (uint)uVar9;
  *(ushort *)(param_2 + 0x1f) = *(ushort *)((int)param_2 + 0x3e);
  *(ushort *)(param_2 + 0x1d) = uVar9;
  bVar25 = *(byte *)(param_2[0xc] + 1) & 0xf;
  *(byte *)(param_2 + 0x1b) = bVar25;
  dVar31 = DOUBLE_001aa250;
  switch(bVar25) {
  case 0:
    uVar22 = 1 << (*(byte *)(puVar27 + 0x32) - uVar15 & 0x3f);
    *(short *)((int)param_2 + 0x76) = (short)uVar22;
    bVar3 = *(byte *)((int)puVar27 + 0x65);
    *(undefined1 *)((int)param_2 + 0x6d) = 2;
    uVar21 = 1 << (bVar3 - uVar14 & 0x3f);
    *(short *)(param_2 + 0x1e) = (short)uVar21;
    param_2[0x20] = (int)(float)((double)CONCAT44(0x43300000,uVar22 & 0xffff) - dVar31);
    param_2[0x21] = (int)(float)((double)CONCAT44(0x43300000,uVar21 & 0xffff) - dVar31);
    break;
  case 1:
    uVar22 = 1 << (*(byte *)(puVar27 + 0x32) - uVar15 & 0x3f);
    *(short *)((int)param_2 + 0x76) = (short)uVar22;
    bVar3 = *(byte *)((int)puVar27 + 0x65);
    *(undefined1 *)((int)param_2 + 0x6d) = 3;
    uVar21 = 1 << (bVar3 - uVar14 & 0x3f);
    *(short *)(param_2 + 0x1e) = (short)uVar21;
    param_2[0x20] = (int)(float)((double)CONCAT44(0x43300000,uVar22 & 0xffff) - dVar31);
    param_2[0x21] = (int)(float)((double)CONCAT44(0x43300000,uVar21 & 0xffff) - dVar31);
    break;
  case 2:
    uVar22 = (uint)puVar27[uVar16 * 0xc + 0x52] +
             (uint)*(byte *)(puVar27 + uVar16 * 0xc + 0x55) * -2;
    *(short *)((int)param_2 + 0x76) = (short)uVar22;
    bVar3 = *(byte *)(puVar27 + uVar16 * 0xc + 0x55);
    uVar9 = puVar27[uVar16 * 0xc + 0x53];
    *(undefined1 *)((int)param_2 + 0x6d) = 2;
    uVar21 = (uint)uVar9 + (uint)bVar3 * -2;
    *(short *)(param_2 + 0x1e) = (short)uVar21;
    param_2[0x20] = (int)(float)((double)CONCAT44(0x43300000,uVar22 & 0xffff) - dVar31);
    param_2[0x21] = (int)(float)((double)CONCAT44(0x43300000,uVar21 & 0xffff) - dVar31);
    break;
  case 3:
    iVar26 = ((int (*)())FUN_0002dcf0)(param_2,uVar18,uVar19,uVar22,uVar20,uVar21);
    if (iVar26 == 0) {
      *(short *)((int)param_2 + 0x76) = (short)(1 << (*(byte *)(puVar27 + 0x32) - uVar15 & 0x3f));
      *(short *)(param_2 + 0x1e) = (short)(1 << (*(byte *)((int)puVar27 + 0x65) - uVar14 & 0x3f));
    }
    else {
      *(ushort *)((int)param_2 + 0x76) =
           puVar27[uVar16 * 0xc + 0x52] + (ushort)*(byte *)(puVar27 + uVar16 * 0xc + 0x55) * -2;
      *(ushort *)(param_2 + 0x1e) =
           puVar27[uVar16 * 0xc + 0x53] + (ushort)*(byte *)(puVar27 + uVar16 * 0xc + 0x55) * -2;
    }
    dVar31 = DOUBLE_001aa250;
    uVar22 = (uint)*(ushort *)((int)param_2 + 0x76);
    uVar21 = (uint)*(ushort *)(param_2 + 0x1e);
    *(undefined1 *)((int)param_2 + 0x6d) = 2;
    uVar20 = (uint)*(byte *)((int)param_2 + 0x73);
    bVar25 = *(byte *)(param_2 + 0x1b);
    uVar17 = (uint)*(ushort *)((int)param_2 + 0x7a);
    uVar19 = (uint)*(ushort *)(param_2 + 0x1d);
    uVar18 = (uint)*(ushort *)(param_2 + 0x1f);
    param_2[0x21] =
         (int)(float)((double)CONCAT44(0x43300000,(uint)*(ushort *)(param_2 + 0x1e)) - dVar31);
    param_2[0x20] =
         (int)(float)((double)CONCAT44(0x43300000,(uint)*(ushort *)((int)param_2 + 0x76)) - dVar31);
    break;
  case 4:
    iVar26 = ((int (*)())FUN_0002dcf0)(param_2,uVar18,uVar19,uVar22,uVar20,uVar21);
    if (iVar26 == 0) {
      *(short *)((int)param_2 + 0x76) = (short)(1 << (*(byte *)(puVar27 + 0x32) - uVar15 & 0x3f));
    }
    else {
      *(ushort *)((int)param_2 + 0x76) =
           puVar27[uVar16 * 0xc + 0x52] + (ushort)*(byte *)(puVar27 + uVar16 * 0xc + 0x55) * -2;
    }
    uVar22 = (uint)*(ushort *)((int)param_2 + 0x76);
    uVar21 = 1;
    *(undefined2 *)(param_2 + 0x1e) = 1;
    param_2[0x21] = 0x3f800000;
    *(undefined1 *)((int)param_2 + 0x6d) = 1;
    uVar20 = (uint)*(byte *)((int)param_2 + 0x73);
    bVar25 = *(byte *)(param_2 + 0x1b);
    uVar17 = (uint)*(ushort *)((int)param_2 + 0x7a);
    uVar19 = (uint)*(ushort *)(param_2 + 0x1d);
    uVar18 = (uint)*(ushort *)(param_2 + 0x1f);
    param_2[0x20] =
         (int)(float)((double)CONCAT44(0x43300000,(uint)*(ushort *)((int)param_2 + 0x76)) -
                     DOUBLE_001aa250);
  }
  if (((((bVar1 != uVar20) || (bVar2 != bVar25)) || ((uint)uVar7 != (uVar22 & 0xffff))) ||
      (((uint)uVar8 != (uVar21 & 0xffff) || ((uint)uVar5 != (uVar17 & 0xffff))))) ||
     ((uVar4 != uVar19 || (uVar6 != uVar18)))) {
    *(undefined1 *)((int)param_2 + 0x71) = 0;
    uVar14 = param_2[0x17];
    param_2[0x15] = param_2[0x15] & 0xbfdfffff;
    uVar23 = ((uVar21 & 0xffff) - 1) * 0x20 & 0x10000 |
             ((uVar22 & 0xffff) - 1) * 0x10 & 0x8000 | uVar18 - 1 & 0x3fff;
    param_2[0x17] = uVar14 & 0xfffffe1f;
    param_2[0x18] = uVar23;
    puVar13 = PTR_DAT_001e88c8;
    param_2[0x16] =
         -uVar18 & 0x80000000 |
         (uVar17 & 0xf) << 0x16 |
         (uVar21 - 1) * 0x800 & 0x3ff800 | uVar22 - 1 & 0x7ff | param_2[0x16] & 0x40000000U;
    uVar15 = *(uint *)(puVar13 + uVar20 * 0x24 + 0x1c) >> 7 & 0x1f;
    param_2[0x17] = uVar15 | uVar14 & 0xfffffe00;
    if (uVar20 == 0x29) {
      param_2[0x18] = uVar23 | 0x4000;
      param_2[0x17] = uVar14 & 0xffe00000 | 6;
    }
    else {
      uVar17 = (*(uint *)(puVar13 + uVar20 * 0x24 + 0x1c) & 0x70) << 5;
      param_2[0x17] = uVar17 | uVar15 | uVar14 & 0xfffff000;
      uVar22 = (*(uint *)(puVar13 + uVar20 * 0x24 + 0x1c) & 0xe) << 0xb;
      param_2[0x17] = uVar22 | uVar17 | uVar15 | uVar14 & 0xffff8000;
      uVar18 = *(uint *)(puVar13 + uVar20 * 0x24 + 0x20) >> 0xe & 0x38000;
      param_2[0x17] = uVar18 | uVar22 | uVar17 | uVar15 | uVar14 & 0xfffc0000;
      param_2[0x17] =
           *(uint *)(puVar13 + uVar20 * 0x24 + 0x20) >> 8 & 0x1c0000 |
           uVar18 | uVar22 | uVar17 | uVar15 | uVar14 & 0xffe00000;
    }
    uVar17 = param_2[0x17];
    uVar15 = (*(uint *)(puVar13 + uVar20 * 0x24 + 0x20) >> 0x19 & 1) << 0x16;
    param_2[0x17] = uVar15 | uVar17 & 0xff3fffff;
    *(byte *)((int)param_2 + 0x71) = (puVar13[uVar20 * 0x24 + 0x20] ^ 1) & 1;
    if (bVar25 == 0) {
      param_2[0x17] = uVar15 | uVar17 & 0xf93fffff | 0x4000000;
    }
    else if (*(char *)((int)param_2 + 0x6d) == '\x03') {
      param_2[0x17] = uVar15 | uVar17 & 0xf93fffff | 0x2000000;
    }
    else {
      param_2[0x17] = uVar15 | uVar17 & 0xf93fffff;
    }
    if (uVar19 == 0x1907) {
      param_2[0x17] = param_2[0x17] & 0xfffff1ffU | 0xa00;
    }
  }
  uVar15 = (uint)param_2[0x32] >> 0x16;
  if (*param_2 == 0) {
    if ((*puVar27 & 0x400) == 0) {
      param_2[0x10] = uVar15 << 0x1e;
    }
    else {
      param_2[0x10] = uVar15 << 0x1e | uVar16;
    }
  }
  else {
    param_2[0x10] = uVar15 << 0x1e | *(uint *)(uVar16 * 0x20 + *param_2 + 0x48);
  }
  iVar26 = param_2[0xc];
  cVar29 = *(char *)((int)param_2 + 0x72);
  if (GH_U2F((unsigned int)(param_2[0x24])) != *(float *)(iVar26 + 0x2c)) {
    param_2[0x24] = (int)*(float *)(iVar26 + 0x2c);
    dVar31 = (double)*(float *)(iVar26 + 0x2c);
    if (DOUBLE_001aa1e8 <= dVar31) {
      iVar28 = (int)(dVar31 - DOUBLE_001aa1e8) + -0x80000000;
    }
    else {
      iVar28 = (int)*(float *)(iVar26 + 0x2c);
    }
    uVar15 = *(uint *)(&DAT_001aa510 + iVar28 * 4);
    if (((uint)param_2[0x14] >> 0x15 & 7) != uVar15) {
      *(undefined2 *)((int)param_2 + 0xa2) = 0xffff;
      *(undefined2 *)(param_2 + 0x28) = 0xffff;
      param_2[0x14] = (uVar15 & 7) << 0x15 | param_2[0x14] & 0xff1fffffU;
    }
  }
  uVar4 = *(ushort *)(iVar26 + 0x16);
  if ((uint)*(ushort *)(param_2 + 0x28) == (uint)uVar4) {
    uVar15 = (uint)*(ushort *)(iVar26 + 0x18);
    if (*(ushort *)((int)param_2 + 0xa2) == uVar15) {
      cVar24 = *(char *)((int)param_2 + 0x71);
      if (cVar24 == *(char *)(param_2 + 0x1c)) goto LAB_0002e708;
      goto LAB_0002e690;
    }
    if (*(char *)((int)param_2 + 0x71) != *(char *)(param_2 + 0x1c)) goto LAB_0002e690;
LAB_0002e6d8:
    *(short *)((int)param_2 + 0xa2) = (short)uVar15;
    FUN_0002d210(piVar30,uVar15);
    cVar24 = *(char *)((int)param_2 + 0x71);
  }
  else {
LAB_0002e690:
    *(ushort *)(param_2 + 0x28) = uVar4;
    FUN_0002d030(piVar30,(uint)uVar4);
    *(byte *)((int)param_2 + 0x3d) = (byte)(-(uint)*(ushort *)(param_2[0xc] + 0x5c) >> 0x1f);
    uVar15 = (uint)*(ushort *)(iVar26 + 0x18);
    if ((*(ushort *)((int)param_2 + 0xa2) != uVar15) ||
       (cVar24 = *(char *)((int)param_2 + 0x71), cVar24 != *(char *)(param_2 + 0x1c)))
    goto LAB_0002e6d8;
  }
  if (cVar29 != *(char *)((int)param_2 + 0x72)) {
    *(undefined2 *)((int)param_2 + 0x9e) = 0xffff;
    *(undefined2 *)((int)param_2 + 0x9a) = 0xffff;
    *(undefined2 *)(param_2 + 0x27) = 0xffff;
    cVar29 = *(char *)((int)param_2 + 0x72);
  }
LAB_0002e708:
  *(char *)(param_2 + 0x1c) = cVar24;
  uVar15 = (uint)*(ushort *)(iVar26 + 0x10);
  if (*(ushort *)((int)param_2 + 0x9a) != uVar15) {
    *(ushort *)((int)param_2 + 0x9a) = *(ushort *)(iVar26 + 0x10);
    if (cVar29 == '\0') {
      param_2[0x14] =
           (uVar15 * 0x29 >> 0x10 & 1 | uVar15 * 0x97 >> 9 & 2 | uVar15 * 0x113 >> 7 & 4) ^ 2 |
           param_2[0x14] & 0xfffffff8U;
    }
    else {
      param_2[0x14] =
           (uVar15 * 0x29 >> 0x10 & 1 | uVar15 * 0x73 >> 5 & 2 | uVar15 * 7 >> 3 & 4) ^ 2 |
           param_2[0x14] & 0xfffffff8U;
    }
  }
  uVar15 = (uint)*(ushort *)(iVar26 + 0x12);
  if (*(ushort *)(param_2 + 0x27) != uVar15) {
    *(ushort *)(param_2 + 0x27) = *(ushort *)(iVar26 + 0x12);
    if (*(char *)((int)param_2 + 0x6d) == '\x01') {
      param_2[0x14] = param_2[0x14] & 0xffffffc7;
    }
    else if (cVar29 == '\0') {
      param_2[0x14] =
           ((uVar15 * 0x29 >> 0x10 & 1 | uVar15 * 0x97 >> 9 & 2 | uVar15 * 0x113 >> 7 & 4) ^ 2) << 3
           | param_2[0x14] & 0xffffffc7U;
    }
    else {
      param_2[0x14] =
           ((uVar15 * 0x29 >> 0x10 & 1 | uVar15 * 0x73 >> 5 & 2 | uVar15 * 7 >> 3 & 4) ^ 2) << 3 |
           param_2[0x14] & 0xffffffc7U;
    }
  }
  uVar15 = (uint)*(ushort *)(iVar26 + 0x14);
  if (*(ushort *)((int)param_2 + 0x9e) != uVar15) {
    *(ushort *)((int)param_2 + 0x9e) = *(ushort *)(iVar26 + 0x14);
    if (*(char *)((int)param_2 + 0x6d) == '\x03') {
      if (cVar29 == '\0') {
        param_2[0x14] =
             ((uVar15 * 0x29 >> 0x10 & 1 | uVar15 * 0x97 >> 9 & 2 | uVar15 * 0x113 >> 7 & 4) ^ 2) <<
             6 | param_2[0x14] & 0xfffffe3fU;
      }
      else {
        param_2[0x14] =
             ((uVar15 * 0x29 >> 0x10 & 1 | uVar15 * 0x73 >> 5 & 2 | uVar15 * 7 >> 3 & 4) ^ 2) << 6 |
             param_2[0x14] & 0xfffffe3fU;
      }
    }
    else {
      param_2[0x14] = param_2[0x14] & 0xfffffe3f;
    }
  }
  iVar28 = param_2[0xc];
  sVar10 = *(short *)(iVar28 + 2);
  if (sVar10 == 0x1902) {
    if (*(short *)(iVar26 + 0x48) == -0x7fb7) {
      *(undefined1 *)((int)param_2 + 0x6b) = 5;
    }
    else if (*(short *)(iVar26 + 0x48) == 0x1906) {
      *(undefined1 *)((int)param_2 + 0x6b) = 0;
    }
    else {
      *(undefined1 *)((int)param_2 + 0x6b) = 1;
    }
    *(undefined2 *)(param_2 + 0x25) = *(undefined2 *)(iVar26 + 0x48);
    *(undefined2 *)((int)param_2 + 0x96) = *(undefined2 *)(iVar26 + 0x42);
    uVar11 = *(undefined2 *)(iVar26 + 0x40);
    *(undefined2 *)(param_2 + 0x26) = uVar11;
    param_2[0x23] = *(int *)(iVar26 + 0x44);
    sVar10 = *(short *)(iVar26 + 0x42);
    *(char *)((int)param_2 + 0x69) = (char)uVar11;
    fVar12 = FLOAT_001aa0d4;
    iVar28 = param_2[0xc];
    *(bool *)((int)param_2 + 0x6a) = sVar10 == -0x77b2;
    *(bool *)(param_2 + 0x1a) = *(float *)(iVar26 + 0x44) != fVar12;
  }
  else if (sVar10 == -0x7fb7) {
    *(undefined1 *)((int)param_2 + 0x6b) = 5;
  }
  else {
    *(char *)((int)param_2 + 0x6b) = (char)sVar10 + -6;
  }
  *(undefined1 *)(param_2 + 0x29) = 0;
  dVar31 = DOUBLE_001aa1e8;
  fVar12 = FLOAT_001aa10c;
  *(char *)((int)param_2 + 0xa5) = *(char *)(iVar28 + 0x5f) - *(char *)(iVar28 + 0x5e);
  param_2[0x12] = (uint)*(byte *)(iVar28 + 0x5f) << 0x10 | (uint)*(byte *)(iVar28 + 0x5e);
  fVar12 = *(float *)(iVar28 + 0x30) + fVar12;
  dVar32 = (double)fVar12;
  if (dVar31 <= dVar32) {
    iVar26 = (int)(dVar32 - dVar31) + -0x80000000;
  }
  else {
    iVar26 = (int)fVar12;
  }
  fVar12 = *(float *)(iVar28 + 0x34) + FLOAT_001aa10c;
  dVar31 = (double)fVar12;
  if (DOUBLE_001aa1e8 <= dVar31) {
    uVar15 = (int)(dVar31 - DOUBLE_001aa1e8) + 0x80000000;
  }
  else {
    uVar15 = (uint)fVar12;
  }
  param_2[0x13] = iVar26 << 0x10 | uVar15;
  ((void (*)())FUN_0002d2b0)(piVar30,(double)*(float *)(iVar28 + 0x1c),(double)*(float *)(iVar28 + 0x20),
               (double)*(float *)(iVar28 + 0x24),(double)*(float *)(iVar28 + 0x28));
  uVar14 = (uint)*(byte *)((int)param_2 + 0xa5);
  uVar15 = (uint)(*(float *)(iVar28 + 0x34) + FLOAT_001aa10c);
  uVar17 = (uint)(*(float *)(iVar28 + 0x30) + FLOAT_001aa10c);
  if ((int)uVar14 < (int)uVar15) {
    uVar15 = uVar14;
  }
  if ((int)uVar14 < (int)uVar17) {
    uVar17 = uVar14;
  }
  uVar16 = uVar14 + 1;
  if ((uint)*(byte *)((int)param_2 + 0x6e) < uVar14 + 1) {
    uVar16 = (uint)*(byte *)((int)param_2 + 0x6e);
  }
  uVar15 = (uVar15 - uVar17) + 1;
  if ((int)uVar16 <= (int)uVar15) {
    uVar15 = uVar16;
  }
  iVar26 = 1;
  if (0 < (int)uVar15) {
    iVar26 = (int)(char)uVar15;
  }
  param_2[0x16] = (iVar26 + -1) * 0x4000000 & 0x3c000000U | param_2[0x16] & 0xc3ffffffU;
  *(byte *)((int)param_2 + 0x39) = *(byte *)((int)param_2 + 0x39) & 0x7f;
  return;
}

/* FUN_0002ebc0 @ 0x2ebc0 (596 bytes) */
int FUN_0002ebc0(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  char cVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  if (*(int *)(param_1 + 0x2a90) != 0) {
    iVar5 = *(int *)(param_2 * 4 + param_1 + 0x18c);
    uVar4 = (uint)*(ushort *)(iVar5 + 0xa0);
    if ((((*(short *)(*(int *)(iVar5 + 0x30) + 0x18) != 0x2600) &&
         (sVar3 = *(short *)(*(int *)(iVar5 + 0x30) + 0x16), sVar3 != 0x2600)) && (sVar3 != 0x2702))
       && (sVar3 != 0x2700)) {
      *(uint *)(iVar5 + 0x50) =
           (*(uint *)(&DAT_001aa510 + *(int *)(param_1 + 0x2a90) * 4) & 7) << 0x15 |
           *(uint *)(iVar5 + 0x50) & 0xff1fffff;
      if (3 < *(uint *)(param_1 + 0x2a8c)) {
        if (uVar4 == 0x2703) {
          uVar4 = 0x2701;
        }
        else if (uVar4 == 0x2702) {
          uVar4 = 0x2700;
        }
      }
      cVar2 = *(char *)(iVar5 + 0x72);
      FUN_0002d030(iVar5 + 0x3c,uVar4);
      FUN_0002d210(iVar5 + 0x3c,(uint)*(ushort *)(iVar5 + 0xa2));
      if (cVar2 != *(char *)(iVar5 + 0x72)) {
        bVar1 = *(char *)(iVar5 + 0x72) == '\0';
        uVar4 = (uint)*(ushort *)(iVar5 + 0x9a);
        if (bVar1) {
          uVar4 = (uVar4 * 0x29 >> 0x10 & 1 | uVar4 * 0x97 >> 9 & 2 | uVar4 * 0x113 >> 7 & 4) ^ 2 |
                  *(uint *)(iVar5 + 0x50) & 0xfffffff8;
          *(uint *)(iVar5 + 0x50) = uVar4;
        }
        else {
          uVar4 = (uVar4 * 0x29 >> 0x10 & 1 | uVar4 * 0x73 >> 5 & 2 | uVar4 * 7 >> 3 & 4) ^ 2 |
                  *(uint *)(iVar5 + 0x50) & 0xfffffff8;
          *(uint *)(iVar5 + 0x50) = uVar4;
        }
        uVar6 = (uint)*(ushort *)(iVar5 + 0x9c);
        if (*(char *)(iVar5 + 0x6d) == '\x01') {
          uVar4 = uVar4 & 0xffffffc7;
          *(uint *)(iVar5 + 0x50) = uVar4;
        }
        else if (bVar1) {
          uVar4 = ((uVar6 * 0x29 >> 0x10 & 1 | uVar6 * 0x97 >> 9 & 2 | uVar6 * 0x113 >> 7 & 4) ^ 2)
                  << 3 | uVar4 & 0xffffffc7;
          *(uint *)(iVar5 + 0x50) = uVar4;
        }
        else {
          uVar4 = ((uVar6 * 0x29 >> 0x10 & 1 | uVar6 * 0x73 >> 5 & 2 | uVar6 * 7 >> 3 & 4) ^ 2) << 3
                  | uVar4 & 0xffffffc7;
          *(uint *)(iVar5 + 0x50) = uVar4;
        }
        uVar6 = (uint)*(ushort *)(iVar5 + 0x9e);
        if (*(char *)(iVar5 + 0x6d) == '\x03') {
          if (bVar1) {
            *(uint *)(iVar5 + 0x50) =
                 ((uVar6 * 0x29 >> 0x10 & 1 | uVar6 * 0x97 >> 9 & 2 | uVar6 * 0x113 >> 7 & 4) ^ 2)
                 << 6 | uVar4 & 0xfffffe3f;
          }
          else {
            *(uint *)(iVar5 + 0x50) =
                 ((uVar6 * 0x29 >> 0x10 & 1 | uVar6 * 0x73 >> 5 & 2 | uVar6 * 7 >> 3 & 4) ^ 2) << 6
                 | uVar4 & 0xfffffe3f;
          }
        }
        else {
          *(uint *)(iVar5 + 0x50) = uVar4 & 0xfffffe3f;
        }
      }
    }
  }
  return;
}

/* FUN_0002ee30 @ 0x2ee30 (1476 bytes) */
int FUN_0002ee30(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  float fVar1;
  float fVar2;
  float fVar3;
  ushort uVar4;
  short sVar5;
  undefined2 uVar6;
  uint uVar7;
  int iVar8;
  char cVar9;
  char cVar10;
  int iVar11;
  int iVar12;
  double dVar13;
  
  iVar12 = param_2 + 0x3c;
  iVar11 = *(int *)(param_2 + 0x30);
  fVar1 = *(float *)(iVar11 + 0x30) + FLOAT_001aa10c;
  dVar13 = (double)fVar1;
  if (DOUBLE_001aa1e8 <= dVar13) {
    iVar8 = (int)(dVar13 - DOUBLE_001aa1e8) + -0x80000000;
  }
  else {
    iVar8 = (int)fVar1;
  }
  fVar1 = *(float *)(iVar11 + 0x34) + FLOAT_001aa10c;
  dVar13 = (double)fVar1;
  if (DOUBLE_001aa1e8 <= dVar13) {
    uVar7 = (int)(dVar13 - DOUBLE_001aa1e8) + 0x80000000;
  }
  else {
    uVar7 = (uint)fVar1;
  }
  if ((((uint)*(byte *)(iVar11 + 0x5f) << 0x10 | (uint)*(byte *)(iVar11 + 0x5e)) !=
       *(uint *)(param_2 + 0x48)) || ((iVar8 << 0x10 | uVar7) != *(uint *)(param_2 + 0x4c))) {
    ((int (*)())FUN_0002ddf0)(param_1,param_2);
    return;
  }
  cVar10 = *(char *)(param_2 + 0x72);
  if (*(float *)(param_2 + 0x90) != *(float *)(iVar11 + 0x2c)) {
    *(float *)(param_2 + 0x90) = *(float *)(iVar11 + 0x2c);
    dVar13 = (double)*(float *)(iVar11 + 0x2c);
    if (DOUBLE_001aa1e8 <= dVar13) {
      iVar8 = (int)(dVar13 - DOUBLE_001aa1e8) + -0x80000000;
    }
    else {
      iVar8 = (int)*(float *)(iVar11 + 0x2c);
    }
    uVar7 = *(uint *)(&DAT_001aa510 + iVar8 * 4);
    if ((*(uint *)(param_2 + 0x50) >> 0x15 & 7) != uVar7) {
      *(undefined2 *)(param_2 + 0xa2) = 0xffff;
      *(undefined2 *)(param_2 + 0xa0) = 0xffff;
      *(uint *)(param_2 + 0x50) = (uVar7 & 7) << 0x15 | *(uint *)(param_2 + 0x50) & 0xff1fffff;
    }
  }
  uVar4 = *(ushort *)(iVar11 + 0x16);
  if ((uint)*(ushort *)(param_2 + 0xa0) == (uint)uVar4) {
    uVar7 = (uint)*(ushort *)(iVar11 + 0x18);
    if (*(ushort *)(param_2 + 0xa2) != uVar7) {
      if (*(char *)(param_2 + 0x70) != *(char *)(param_2 + 0x71)) goto LAB_0002f040;
      goto LAB_0002f088;
    }
    cVar9 = *(char *)(param_2 + 0x71);
    if (cVar9 != *(char *)(param_2 + 0x70)) goto LAB_0002f040;
  }
  else {
LAB_0002f040:
    *(ushort *)(param_2 + 0xa0) = uVar4;
    FUN_0002d030(iVar12,(uint)uVar4);
    *(byte *)(param_2 + 0x3d) = (byte)(-(uint)*(ushort *)(*(int *)(param_2 + 0x30) + 0x5c) >> 0x1f);
    uVar7 = (uint)*(ushort *)(iVar11 + 0x18);
    if ((*(ushort *)(param_2 + 0xa2) != uVar7) ||
       (cVar9 = *(char *)(param_2 + 0x71), cVar9 != *(char *)(param_2 + 0x70))) {
LAB_0002f088:
      *(short *)(param_2 + 0xa2) = (short)uVar7;
      FUN_0002d210(iVar12,uVar7);
      cVar9 = *(char *)(param_2 + 0x71);
    }
    if (cVar10 != *(char *)(param_2 + 0x72)) {
      *(undefined2 *)(param_2 + 0x9e) = 0xffff;
      *(undefined2 *)(param_2 + 0x9a) = 0xffff;
      *(undefined2 *)(param_2 + 0x9c) = 0xffff;
      cVar10 = *(char *)(param_2 + 0x72);
    }
  }
  *(char *)(param_2 + 0x70) = cVar9;
  uVar7 = (uint)*(ushort *)(iVar11 + 0x10);
  if (*(ushort *)(param_2 + 0x9a) != uVar7) {
    *(ushort *)(param_2 + 0x9a) = *(ushort *)(iVar11 + 0x10);
    if (cVar10 == '\0') {
      *(uint *)(param_2 + 0x50) =
           (uVar7 * 0x29 >> 0x10 & 1 | uVar7 * 0x97 >> 9 & 2 | uVar7 * 0x113 >> 7 & 4) ^ 2 |
           *(uint *)(param_2 + 0x50) & 0xfffffff8;
    }
    else {
      *(uint *)(param_2 + 0x50) =
           (uVar7 * 0x29 >> 0x10 & 1 | uVar7 * 0x73 >> 5 & 2 | uVar7 * 7 >> 3 & 4) ^ 2 |
           *(uint *)(param_2 + 0x50) & 0xfffffff8;
    }
  }
  uVar7 = (uint)*(ushort *)(iVar11 + 0x12);
  if (*(ushort *)(param_2 + 0x9c) != uVar7) {
    *(ushort *)(param_2 + 0x9c) = *(ushort *)(iVar11 + 0x12);
    if (*(char *)(param_2 + 0x6d) == '\x01') {
      *(uint *)(param_2 + 0x50) = *(uint *)(param_2 + 0x50) & 0xffffffc7;
    }
    else if (cVar10 == '\0') {
      *(uint *)(param_2 + 0x50) =
           ((uVar7 * 0x29 >> 0x10 & 1 | uVar7 * 0x97 >> 9 & 2 | uVar7 * 0x113 >> 7 & 4) ^ 2) << 3 |
           *(uint *)(param_2 + 0x50) & 0xffffffc7;
    }
    else {
      *(uint *)(param_2 + 0x50) =
           ((uVar7 * 0x29 >> 0x10 & 1 | uVar7 * 0x73 >> 5 & 2 | uVar7 * 7 >> 3 & 4) ^ 2) << 3 |
           *(uint *)(param_2 + 0x50) & 0xffffffc7;
    }
  }
  uVar7 = (uint)*(ushort *)(iVar11 + 0x14);
  if (*(ushort *)(param_2 + 0x9e) != uVar7) {
    *(ushort *)(param_2 + 0x9e) = *(ushort *)(iVar11 + 0x14);
    if (*(char *)(param_2 + 0x6d) == '\x03') {
      if (cVar10 == '\0') {
        *(uint *)(param_2 + 0x50) =
             ((uVar7 * 0x29 >> 0x10 & 1 | uVar7 * 0x97 >> 9 & 2 | uVar7 * 0x113 >> 7 & 4) ^ 2) << 6
             | *(uint *)(param_2 + 0x50) & 0xfffffe3f;
      }
      else {
        *(uint *)(param_2 + 0x50) =
             ((uVar7 * 0x29 >> 0x10 & 1 | uVar7 * 0x73 >> 5 & 2 | uVar7 * 7 >> 3 & 4) ^ 2) << 6 |
             *(uint *)(param_2 + 0x50) & 0xfffffe3f;
      }
    }
    else {
      *(uint *)(param_2 + 0x50) = *(uint *)(param_2 + 0x50) & 0xfffffe3f;
    }
  }
  sVar5 = *(short *)(*(int *)(param_2 + 0x30) + 2);
  if (sVar5 == 0x1902) {
    if (*(short *)(iVar11 + 0x48) == -0x7fb7) {
      *(undefined1 *)(param_2 + 0x6b) = 5;
    }
    else if (*(short *)(iVar11 + 0x48) == 0x1906) {
      *(undefined1 *)(param_2 + 0x6b) = 0;
    }
    else {
      *(undefined1 *)(param_2 + 0x6b) = 1;
    }
    *(undefined2 *)(param_2 + 0x94) = *(undefined2 *)(iVar11 + 0x48);
    *(undefined2 *)(param_2 + 0x96) = *(undefined2 *)(iVar11 + 0x42);
    uVar6 = *(undefined2 *)(iVar11 + 0x40);
    *(undefined2 *)(param_2 + 0x98) = uVar6;
    *(undefined4 *)(param_2 + 0x8c) = *(undefined4 *)(iVar11 + 0x44);
    sVar5 = *(short *)(iVar11 + 0x42);
    *(char *)(param_2 + 0x69) = (char)uVar6;
    fVar1 = FLOAT_001aa0d4;
    *(bool *)(param_2 + 0x6a) = sVar5 == -0x77b2;
    *(bool *)(param_2 + 0x68) = *(float *)(iVar11 + 0x44) != fVar1;
  }
  else if (sVar5 == -0x7fb7) {
    *(undefined1 *)(param_2 + 0x6b) = 5;
  }
  else {
    *(char *)(param_2 + 0x6b) = (char)sVar5 + -6;
  }
  if (*(float *)(param_2 + 0xa8) == *(float *)(iVar11 + 0x1c)) {
    fVar1 = *(float *)(iVar11 + 0x20);
    if (*(float *)(param_2 + 0xac) == fVar1) {
      fVar2 = *(float *)(iVar11 + 0x24);
      if (*(float *)(param_2 + 0xb0) == fVar2) {
        fVar3 = *(float *)(iVar11 + 0x28);
        if (*(float *)(param_2 + 0xb4) == fVar3) goto LAB_0002f3e8;
      }
      else {
        fVar3 = *(float *)(iVar11 + 0x28);
      }
    }
    else {
      fVar2 = *(float *)(iVar11 + 0x24);
      fVar3 = *(float *)(iVar11 + 0x28);
    }
  }
  else {
    fVar1 = *(float *)(iVar11 + 0x20);
    fVar2 = *(float *)(iVar11 + 0x24);
    fVar3 = *(float *)(iVar11 + 0x28);
  }
  *(float *)(param_2 + 0xa8) = *(float *)(iVar11 + 0x1c);
  *(float *)(param_2 + 0xac) = fVar1;
  *(float *)(param_2 + 0xb0) = fVar2;
  *(float *)(param_2 + 0xb4) = fVar3;
  ((void (*)())FUN_0002d2b0)(iVar12,(double)*(float *)(iVar11 + 0x1c),(double)*(float *)(iVar11 + 0x20),
               (double)*(float *)(iVar11 + 0x24),(double)*(float *)(iVar11 + 0x28));
LAB_0002f3e8:
  *(byte *)(param_2 + 0x39) = *(byte *)(param_2 + 0x39) & 0x7f;
  return;
}

/* FUN_0002f410 @ 0x2f410 (148 bytes) */
int FUN_0002f410(param_1)
  uint param_1;
{
  switch(param_1 & 0xf) {
  case 3:
    return 7;
  case 4:
    return 0xb;
  default:
    return 0;
  case 6:
    return 0x27;
  case 7:
    return 0x2b;
  case 8:
    return 0x2c;
  case 9:
    return 0x2a;
  case 10:
    return 8;
  case 0xb:
    return 0x18;
  case 0xc:
    return 0x1e;
  case 0xd:
    return 0x12;
  }
}

/* FUN_0002f4d0 @ 0x2f4d0 (708 bytes) */
int FUN_0002f4d0(param_1, param_2, param_3)
  uint param_1;
  undefined *param_2;
  int param_3;
{
  bool bVar1;
  
  if (param_1 == 0x1909) {
    if (param_3 == 1) {
LAB_0002f7a0:
      return param_2 == ((unsigned char *)0x00001401);
    }
    if (param_3 == 0x13) goto LAB_0002f790;
    if (param_3 == 0x1f) {
LAB_0002f6c0:
      if (param_2 == ((unsigned char *)0x0000140b)) {
        return true;
      }
      return false;
    }
    if (param_3 != 0x19) {
      return false;
    }
  }
  else if (param_1 < 0x190a) {
    if (param_1 == 0x1907) {
      if (param_3 == 5) {
        if (param_2 != (undefined *)0x8363) {
          return false;
        }
        return true;
      }
      if (param_3 == 0x28) {
        if (param_2 == (undefined *)0x8032) {
          return true;
        }
        return false;
      }
      return false;
    }
    if (param_1 < 0x1908) {
      if (param_1 != 0x1906) {
        return false;
      }
      if (param_3 == 2) goto LAB_0002f7a0;
      if (param_3 == 0x14) goto LAB_0002f790;
      if (param_3 == 0x20) goto LAB_0002f6c0;
      if (param_3 != 0x1a) {
        return false;
      }
    }
    else {
      if (param_3 == 0x12) {
LAB_0002f790:
        return param_2 == ((unsigned char *)0x00001406);
      }
      if (param_3 == 0x1e) {
        return param_2 == ((unsigned char *)0x0000140b);
      }
      if (param_3 == 10) {
        return param_2 == (undefined *)0x8367;
      }
      if (param_3 == 9) {
LAB_0002f5d0:
        if (param_2 == (undefined *)0x8035) {
          return true;
        }
        if (param_2 == ((unsigned char *)0x00001401)) {
          return true;
        }
        return false;
      }
      if (param_3 == 0x23) {
LAB_0002f5fc:
        if (param_2 == (undefined *)0x8368) {
          return true;
        }
        return false;
      }
      if (param_3 != 0x18) {
        return false;
      }
    }
  }
  else {
    if (param_1 == 0x80e1) {
      if (param_3 == 7) {
        bVar1 = param_2 == (undefined *)0x8366;
      }
      else if (param_3 == 6) {
        bVar1 = param_2 == (undefined *)0x8365;
      }
      else if (param_3 == 0xb) {
        bVar1 = param_2 == (undefined *)0x8367;
      }
      else {
        if (param_3 == 8) goto LAB_0002f5d0;
        bVar1 = false;
        if (param_3 == 0x24) goto LAB_0002f5fc;
        if (param_3 == 0x11) {
          if (param_2 == ((unsigned char *)0x00001406)) {
            return true;
          }
          return bVar1;
        }
        if (param_3 == 0x1d) {
          if (param_2 == ((unsigned char *)0x0000140b)) {
            return true;
          }
          return false;
        }
      }
      if (param_3 != 0x17) {
        return bVar1;
      }
      if (param_2 == ((unsigned char *)0x00001403)) {
        return true;
      }
      return bVar1;
    }
    if (param_1 == 0x85b9) {
      if (param_3 == 0x27) {
        if (param_2 == (undefined *)0x85ba) {
          return true;
        }
        return false;
      }
      if (param_3 != 0x26) {
        return false;
      }
      if (param_2 == (undefined *)0x85bb) {
        return true;
      }
      return false;
    }
    if (param_1 != 0x190a) {
      return false;
    }
    if (param_3 == 4) goto LAB_0002f7a0;
    if (param_3 == 0x16) {
      return param_2 == ((unsigned char *)0x00001406);
    }
    if (param_3 == 0x22) goto LAB_0002f6c0;
    if (param_3 != 0x1c) {
      return false;
    }
  }
  if (param_2 == ((unsigned char *)0x00001403)) {
    return true;
  }
  return false;
}

/* FUN_0002f7c0 @ 0x2f7c0 (716 bytes) */
int FUN_0002f7c0(param_1, param_2)
  uint param_1;
  undefined *param_2;
{
  undefined4 uVar1;
  
  if (param_1 == 0x1909) {
    uVar1 = 1;
    if (param_2 != ((unsigned char *)0x00001401)) {
      if (param_2 == ((unsigned char *)0x00001406)) {
        return 0x13;
      }
      uVar1 = 0;
      if (param_2 == ((unsigned char *)0x0000140b)) {
        return 0x1f;
      }
    }
    if (param_2 != ((unsigned char *)0x00001403)) {
      return uVar1;
    }
    return 0x19;
  }
  if (param_1 < 0x190a) {
    if (param_1 == 0x1907) {
      if (param_2 == (undefined *)0x8363) {
        return 5;
      }
      if (param_2 != (undefined *)0x8032) {
        return 0;
      }
      return 0x28;
    }
    if (param_1 < 0x1908) {
      if (param_1 != 0x1906) {
        return 0;
      }
      uVar1 = 2;
      if (param_2 != ((unsigned char *)0x00001401)) {
        if (param_2 == ((unsigned char *)0x00001406)) {
          return 0x14;
        }
        uVar1 = 0;
        if (param_2 == ((unsigned char *)0x0000140b)) {
          return 0x20;
        }
      }
      if (param_2 != ((unsigned char *)0x00001403)) {
        return uVar1;
      }
      return 0x1a;
    }
    uVar1 = 0x12;
    if ((param_2 == ((unsigned char *)0x00001406)) || (uVar1 = 0, param_2 != ((unsigned char *)0x0000140b))) {
      if (param_2 != (undefined *)0x8035) goto LAB_0002f8fc;
      uVar1 = 9;
    }
    else {
      uVar1 = 0x1e;
LAB_0002f8fc:
      if (param_2 == (undefined *)0x8367) {
        uVar1 = 10;
        goto LAB_0002f934;
      }
    }
    if (param_2 == ((unsigned char *)0x00001401)) {
      return 9;
    }
LAB_0002f934:
    if (param_2 == (undefined *)0x8368) {
      return 0x23;
    }
    if (param_2 != ((unsigned char *)0x00001403)) {
      return uVar1;
    }
    return 0x18;
  }
  if (param_1 != 0x80e1) {
    if (param_1 == 0x85b9) {
      if (param_2 == (undefined *)0x85ba) {
        return 0x27;
      }
      if (param_2 != (undefined *)0x85bb) {
        return 0;
      }
      return 0x26;
    }
    if (param_1 != 0x190a) {
      return 0;
    }
    uVar1 = 4;
    if (param_2 != ((unsigned char *)0x00001401)) {
      if (param_2 == ((unsigned char *)0x00001406)) {
        return 0x16;
      }
      uVar1 = 0;
      if (param_2 == ((unsigned char *)0x0000140b)) {
        return 0x22;
      }
    }
    if (param_2 != ((unsigned char *)0x00001403)) {
      return uVar1;
    }
    return 0x1c;
  }
  uVar1 = 7;
  if ((param_2 == (undefined *)0x8366) || (uVar1 = 0, param_2 != (undefined *)0x8365)) {
    if (param_2 != (undefined *)0x8035) goto LAB_0002f84c;
    uVar1 = 8;
  }
  else {
    uVar1 = 6;
LAB_0002f84c:
    if (param_2 == (undefined *)0x8367) {
      uVar1 = 0xb;
      goto LAB_0002f884;
    }
  }
  if (param_2 == ((unsigned char *)0x00001401)) {
    return 8;
  }
LAB_0002f884:
  if (param_2 == (undefined *)0x8368) {
    uVar1 = 0x24;
  }
  else if (param_2 == ((unsigned char *)0x00001406)) {
    return 0x11;
  }
  if (param_2 == ((unsigned char *)0x0000140b)) {
    return 0x1d;
  }
  if (param_2 != ((unsigned char *)0x00001403)) {
    return uVar1;
  }
  return 0x17;
}

/* FUN_0002fac0 @ 0x2fac0 (2252 bytes) */
int FUN_0002fac0(param_1, param_2)
  int param_1;
  int param_2;
{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  char cVar6;
  char cVar7;
  int iVar8;
  undefined1 uVar9;
  char cVar10;
  char cVar11;
  char cVar12;
  ushort *puVar13;
  undefined4 local_38;
  undefined4 local_34;
  uint local_30 [9];
  
  puVar13 = *(ushort **)(param_2 + 0x30);
  uVar1 = *puVar13;
  if ((uVar1 & 0x200) != 0) {
    return;
  }
  if ((uVar1 & 0x400) != 0) {
    local_38 = *(undefined4 *)(puVar13 + 4);
    *(undefined1 *)(param_2 + 0x38) = 0;
    local_34 = 3;
    iVar8 = _io_connect_method_scalarI_scalarO
                      (*(undefined4 *)(param_1 + 4),6,&local_38,1,local_30,&local_34);
    if (iVar8 != 0) {
      return;
    }
    uVar1 = puVar13[6];
    if (uVar1 == 0x409) {
      if ((local_30[0] & 0x300) < 0x100) {
        return;
      }
    }
    else if (uVar1 == 0x40a) {
      if ((local_30[0] & 0x300) < 0x200) {
        return;
      }
    }
    else if ((ushort)(uVar1 - 0x40b) < 2) {
      return;
    }
    uVar9 = ((int (*)())FUN_0002f410)(local_30[0]);
    *(undefined1 *)(param_2 + 0x38) = uVar9;
    return;
  }
  uVar2 = puVar13[0x2c];
  uVar3 = puVar13[0x2a];
  uVar4 = puVar13[0x2d];
  uVar5 = *(uint *)(param_1 + 0x154) & 0xf;
  if (uVar2 != 0x1900) {
    if (uVar2 != 0x85b9) {
      if (uVar4 == 0x8362) {
LAB_0002fcd4:
        cVar6 = '(';
        cVar11 = '(';
        cVar10 = '(';
      }
      else if (uVar4 < 0x8363) {
        if (uVar4 == 0x8034) {
LAB_0002fcf4:
          cVar6 = '\0';
          cVar11 = '\a';
          cVar10 = '\a';
        }
        else if (uVar4 < 0x8035) {
          if (uVar4 == 0x8032) goto LAB_0002fcd4;
          if (uVar4 == 0x8033) goto LAB_0002fcc4;
LAB_0002fc40:
          cVar6 = '\0';
          cVar11 = '\0';
          cVar10 = '\0';
        }
        else if (uVar4 == 0x8035) {
          if (uVar2 == 0x80e1) {
            cVar6 = '\0';
            cVar11 = '\0';
            cVar10 = '\b';
          }
          else {
            cVar6 = '\0';
            cVar11 = '\0';
            cVar10 = '\t';
          }
        }
        else {
          if (uVar4 != 0x8036) goto LAB_0002fc40;
LAB_0002fd64:
          if (uVar2 == 0x80e1) {
            cVar6 = '\0';
            cVar11 = '\0';
            cVar10 = '$';
          }
          else {
            cVar6 = '\0';
            cVar11 = '\0';
            cVar10 = '#';
          }
        }
      }
      else if (uVar4 == 0x8365) {
LAB_0002fcc4:
        cVar6 = '\0';
        cVar11 = '\x06';
        cVar10 = '\x06';
      }
      else if (uVar4 < 0x8365) {
        cVar6 = '\0';
        cVar11 = '\x05';
        cVar10 = '\x05';
      }
      else {
        if (uVar4 != 0x8367) {
          if (0x8366 < uVar4) {
            if (uVar4 == 0x8368) goto LAB_0002fd64;
            goto LAB_0002fc40;
          }
          goto LAB_0002fcf4;
        }
        if (uVar2 == 0x80e1) {
          cVar6 = '\0';
          cVar11 = '\0';
          cVar10 = '\v';
        }
        else {
          cVar6 = '\0';
          cVar11 = '\0';
          cVar10 = '\n';
        }
      }
      if (0x8056 < uVar3) {
        if (uVar3 == 0x84ec) {
          cVar11 = '\0';
          cVar7 = '\f';
          cVar12 = '\x03';
        }
        else if (uVar3 < 0x84ed) {
          if (uVar3 < 0x81a8) {
            if (uVar3 < 0x81a6) {
              if (uVar3 == 0x8059) {
                if (uVar2 == 0x80e1) {
                  cVar11 = '\0';
                  cVar7 = '\0';
                  cVar12 = '$';
                }
                else {
                  cVar11 = '\0';
                  cVar7 = '\0';
                  cVar12 = '#';
                }
              }
              else if (uVar3 < 0x805a) {
                if (uVar3 != 0x8057) {
                  if (uVar3 == 0x8058) goto LAB_0002fec0;
                  goto LAB_0002fde8;
                }
                cVar7 = '\0';
                cVar12 = '\a';
              }
              else {
                if (uVar3 < 0x805c) goto LAB_00030378;
                if (uVar3 != 0x81a5) goto LAB_0002fde8;
LAB_0003034c:
                cVar7 = '\0';
                cVar12 = '\x10';
                cVar11 = '\0';
              }
            }
            else {
LAB_0003009c:
              cVar11 = '\0';
              cVar7 = '\0';
              cVar12 = ')';
            }
          }
          else if (uVar3 == 0x83f3) {
            cVar7 = '\x0e';
            cVar12 = '\x06';
          }
          else if (uVar3 < 0x83f4) {
            if (uVar3 == 0x83f1) {
              cVar7 = '\f';
              cVar12 = '\x06';
            }
            else {
              if (uVar3 < 0x83f2) {
                if (uVar3 == 0x83f0) goto LAB_000301a0;
                goto LAB_0002fde8;
              }
LAB_0003017c:
              cVar7 = '\r';
              cVar12 = '\x06';
            }
          }
          else if (uVar3 == 0x84ea) {
            cVar11 = '\0';
            cVar7 = '\f';
            cVar12 = '\x01';
          }
          else if (uVar3 < 0x84eb) {
            if (uVar3 != 0x84e9) goto LAB_0002fde8;
            if (uVar2 == 0x1908) {
LAB_00030298:
              if ((uVar4 == 0x8034) || (uVar4 == 0x8366)) goto LAB_00030260;
            }
            else if (uVar2 < 0x1909) {
              if (uVar2 != 0x1906) {
LAB_00030260:
                cVar11 = '\0';
                cVar7 = '\f';
                cVar12 = '\x02';
                goto LAB_00030270;
              }
            }
            else if (uVar2 != 0x190a) {
              if (uVar2 == 0x80e1) goto LAB_00030298;
              goto LAB_00030260;
            }
LAB_000302b8:
            cVar7 = '\0';
            cVar12 = '\x02';
            cVar11 = '\0';
          }
          else {
            cVar7 = '\r';
            cVar12 = '\x04';
          }
        }
        else if (uVar3 == 0x8819) {
          cVar11 = '\0';
          cVar7 = '\0';
          cVar12 = '\x16';
        }
        else if (uVar3 < 0x881a) {
          if (uVar3 < 0x8816) {
            if (uVar3 < 0x8814) {
              if (uVar3 != 0x84ed) {
                if (uVar3 == 0x84ee) goto LAB_0003017c;
                goto LAB_0002fde8;
              }
LAB_000301a0:
              cVar7 = '\f';
              cVar12 = '\x05';
            }
            else if (uVar2 == 0x80e1) {
              cVar11 = '\0';
              cVar7 = '\0';
              cVar12 = '\x11';
            }
            else {
              cVar11 = '\0';
              cVar7 = '\0';
              cVar12 = '\x12';
            }
          }
          else if (uVar3 == 0x8817) {
            cVar11 = '\0';
            cVar7 = '\0';
            cVar12 = '\x15';
          }
          else if (uVar3 < 0x8818) {
            cVar11 = '\0';
            cVar7 = '\0';
            cVar12 = '\x14';
          }
          else {
            cVar11 = '\0';
            cVar7 = '\0';
            cVar12 = '\x13';
          }
        }
        else if (uVar3 == 0x881d) {
          cVar11 = '\0';
          cVar7 = '\0';
          cVar12 = '!';
        }
        else if (uVar3 < 0x881e) {
          if (uVar3 < 0x881c) {
            cVar11 = '\0';
            cVar7 = '\0';
            cVar12 = '\x1e';
          }
          else {
            cVar11 = '\0';
            cVar7 = '\0';
            cVar12 = ' ';
          }
        }
        else if (uVar3 == 0x881f) {
          cVar11 = '\0';
          cVar7 = '\0';
          cVar12 = '\"';
        }
        else if (uVar3 < 0x881f) {
          cVar11 = '\0';
          cVar7 = '\0';
          cVar12 = '\x1f';
        }
        else {
          if (uVar3 != 0x8837) {
            if (uVar3 == 0x88f0) goto LAB_0003009c;
            goto LAB_0002fde8;
          }
          cVar11 = '\0';
          cVar7 = '\x0f';
          cVar12 = '\x04';
        }
        goto LAB_00030270;
      }
      if (uVar3 < 0x8055) {
        if (uVar3 < 0x8041) {
          if (uVar3 < 0x803f) {
            if (uVar3 == 0x1908) {
LAB_000302e8:
              if (uVar2 == 0x1908) {
LAB_0003031c:
                if (uVar5 == 3) goto LAB_00030360;
              }
              else {
                if (uVar2 < 0x1909) {
                  if (uVar2 == 0x1906) goto LAB_0003031c;
                }
                else if ((uVar2 == 0x190a) || (uVar2 == 0x80e1)) goto LAB_0003031c;
LAB_00030340:
                if (uVar5 == 3) goto LAB_0003036c;
              }
LAB_0002fec0:
              cVar7 = '\0';
              cVar12 = '\t';
              cVar11 = cVar10;
            }
            else {
              if (uVar3 < 0x1909) {
                if (uVar3 == 4) goto LAB_000302e8;
                if (4 < uVar3) {
                  if (uVar3 == 0x1906) goto LAB_000302b8;
                  if (0x1906 < uVar3) goto LAB_00030328;
                  if (uVar3 == 0x1902) goto LAB_0003034c;
LAB_0002fde8:
                  cVar7 = '\0';
                  cVar12 = '\0';
                  cVar11 = '\0';
                  goto LAB_00030270;
                }
                if (uVar3 == 2) goto LAB_000301ec;
                if (uVar3 < 3) {
                  if (uVar3 == 1) goto LAB_00030218;
                  goto LAB_0002fde8;
                }
LAB_00030328:
                if (uVar2 == 0x1906) {
                  cVar7 = '\0';
                  cVar12 = '(';
                  cVar11 = '\0';
                  goto LAB_00030270;
                }
                goto LAB_00030340;
              }
              if (uVar3 < 0x803d) {
                if (0x803a < uVar3) goto LAB_000302b8;
                if (uVar3 == 0x190a) {
LAB_000301ec:
                  cVar7 = '\0';
                  cVar12 = '\x04';
                  cVar11 = '\0';
                }
                else {
                  if (uVar3 < 0x190a) goto LAB_00030218;
                  if (uVar3 != 0x2a10) goto LAB_0002fde8;
                  cVar7 = '\0';
                  cVar12 = '(';
                  cVar11 = cVar6;
                }
              }
              else {
                cVar7 = '\0';
                cVar12 = '\x1a';
                cVar11 = '\0';
              }
            }
          }
          else {
LAB_00030218:
            cVar7 = '\0';
            cVar12 = '\x01';
            cVar11 = '\0';
          }
        }
        else if (uVar3 < 0x804c) {
          if (uVar3 < 0x8049) {
            if (uVar3 < 0x8047) {
              if (0x8042 < uVar3) goto LAB_000301ec;
              cVar7 = '\0';
              cVar12 = '\x19';
              cVar11 = '\0';
            }
            else {
              cVar7 = '\0';
              cVar12 = '\x1c';
              cVar11 = '\0';
            }
          }
          else {
            cVar7 = '\0';
            cVar12 = '\x03';
            cVar11 = '\0';
          }
        }
        else if (uVar3 < 0x8051) {
          if (uVar3 < 0x804f) {
            if (0x804d < uVar3) goto LAB_0002fde8;
            cVar7 = '\0';
            cVar12 = '\x1b';
            cVar11 = '\0';
          }
          else {
LAB_0003036c:
            cVar7 = '\0';
            cVar12 = '\x05';
          }
        }
        else if (uVar3 == 0x8052) {
          cVar7 = '\0';
          cVar12 = '#';
          cVar11 = cVar10;
        }
        else {
          if (uVar3 < 0x8053) goto LAB_0002fec0;
LAB_00030378:
          cVar7 = '\0';
          cVar12 = '\x18';
          cVar11 = '\0';
        }
      }
      else {
LAB_00030360:
        cVar7 = '\0';
        cVar12 = '\x06';
      }
LAB_00030270:
      if ((((uVar1 & 0xf) == 2) || (cVar7 == '\0')) && (cVar7 = cVar11, cVar11 == '\0')) {
        cVar7 = cVar12;
      }
      goto LAB_000303b4;
    }
    cVar7 = '\'';
    if ((uVar4 == 0x85ba) || (cVar7 = '&', uVar4 == 0x85bb)) goto LAB_000303b4;
  }
  cVar7 = '\0';
LAB_000303b4:
  *(char *)(param_2 + 0x38) = cVar7;
  return;
}

/* FUN_000303d0 @ 0x303d0 (68 bytes) */
int FUN_000303d0(param_1, param_2, param_3, param_4)
  uint param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  
  iVar1 = (param_2 + 3 >> 2) * (param_3 + 3 >> 2) * param_4;
  if (param_1 == 0xc) {
    return iVar1 * 8;
  }
  if ((0xb < param_1) && (param_1 < 0x10)) {
    return iVar1 * 0x10;
  }
  return 0;
}

/* FUN_00030420 @ 0x30420 (392 bytes) */
int FUN_00030420(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  uint param_3;
  uint param_4;
  uint param_5;
  uint param_6;
  uint param_7;
{
  uint uVar1;
  uint uVar2;
  float fVar3;
  double dVar4;
  uint uVar5;
  uint uVar6;
  
  _memcpy(param_1,PTR_DAT_001e8998,0x74);
  dVar4 = DOUBLE_001aa250;
  fVar3 = FLOAT_001aa10c;
  uVar5 = *(uint *)(param_1 + 0xc);
  uVar2 = param_4 >> (*(uint *)(param_2 + 0x14) & 7) & 0x3ffe;
  uVar6 = (param_5 & 1) << 0x10;
  uVar1 = (param_5 & 6) << 0x10;
  *(uint *)(param_1 + 0xc) = uVar1 | uVar6 | uVar2 | uVar5 & 0xffe0c001;
  *(uint *)(param_1 + 0xc) =
       (*(uint *)(param_2 + 0x18) & 0x3c00) << 0xb | uVar1 | uVar6 | uVar2 | uVar5 & 0xfe00c001;
  uVar6 = *(uint *)(param_2 + 0x18);
  *(uint *)(param_1 + 0x1c) =
       (param_7 - 1 & 0x7ff) << 0xb | param_6 - 1 & 0x7ff | *(uint *)(param_1 + 0x1c) & 0x80000000 |
       0x80000000;
  *(uint *)(param_1 + 0x14) = uVar6 >> 0x1e;
  uVar6 = *(uint *)(param_2 + 0x14);
  *(uint *)(param_1 + 0x30) =
       (param_7 - 1 & 0x1fff) << 0xd | param_6 - 1 & 0x1fff | *(uint *)(param_1 + 0x30) & 0xfc000000
  ;
  *(uint *)(param_1 + 0x4c) = param_6 * 0x60000 | param_7 * 6;
  *(float *)(param_1 + 0x5c) = (float)((double)CONCAT44(0x43300000,param_7) - dVar4) * fVar3;
  *(float *)(param_1 + 0x58) = (float)((double)CONCAT44(0x43300000,param_6) - dVar4) * fVar3;
  *(uint *)(param_1 + 0x24) =
       (uint)(0x800 < param_7) * 0x10000 |
       (uint)(0x800 < param_6) * 0x8000 |
       (param_3 >> (uVar6 & 7)) - 1 & 0x3fff | *(uint *)(param_1 + 0x24) & 0xfff00000;
  return param_1 + 0x74;
}

/* FUN_000305b0 @ 0x305b0 (492 bytes) */
int FUN_000305b0(param_1, param_2, param_3, param_4)
  undefined1 *param_1;
  byte *param_2;
  int param_3;
  int param_4;
{
  bool bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  uint uVar9;
  byte *pbVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int local_58 [4];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  
  uVar4 = 0;
  uVar9 = 0xff;
  iVar6 = 0;
  pbVar10 = param_2;
  do {
    iVar14 = 4;
    pbVar8 = pbVar10;
    do {
      uVar3 = (uint)*pbVar8;
      pbVar8 = pbVar8 + param_3;
      if (uVar3 < uVar9) {
        uVar9 = uVar3;
      }
      if (uVar4 < uVar3) {
        uVar4 = uVar3;
      }
      iVar14 = iVar14 + -1;
    } while (iVar14 != 0);
    bVar1 = iVar6 != 3;
    pbVar10 = pbVar10 + param_4;
    iVar6 = iVar6 + 1;
  } while (bVar1);
  iVar6 = uVar4 * 0x100;
  iVar14 = uVar9 * 0x100;
  iVar12 = (int)(iVar6 + uVar9 * -0x100) / 7;
  iVar5 = iVar12 >> 1;
  if (iVar6 == iVar14) {
    if (uVar9 == 0) {
      iVar6 = 0x100;
      iVar5 = 0x7fff;
      iVar12 = 0xffff;
    }
    else {
      iVar14 = iVar14 + -0x100;
      iVar5 = 0x7fff;
      iVar12 = 0xffff;
    }
  }
  iVar13 = 0;
  uVar4 = 0x10;
  local_58[0] = DAT_001aa554;
  local_58[1] = DAT_001aa558;
  local_3c = DAT_001aa570;
  local_58[2] = DAT_001aa55c;
  local_58[3] = DAT_001aa560;
  local_48 = DAT_001aa564;
  local_44 = DAT_001aa568;
  local_40 = DAT_001aa56c;
  do {
    iVar15 = 4;
    pbVar10 = param_2;
    uVar9 = uVar4;
    do {
      bVar2 = *pbVar10;
      iVar11 = (int)uVar9 >> 3;
      uVar3 = uVar9 & 7;
      pbVar10 = pbVar10 + param_3;
      iVar7 = local_58[(int)(((uint)bVar2 * 0x100 + iVar5) - iVar14) / iVar12];
      param_1[iVar11] = (byte)(iVar7 << uVar3) | param_1[iVar11] & ~(byte)(7 << uVar3);
      if (5 < uVar3) {
        param_1[iVar11 + 1] =
             (byte)(iVar7 >> (8 - uVar3 & 0x3f)) |
             param_1[iVar11 + 1] & ~(byte)(7 >> (8 - uVar3 & 0x3f));
      }
      uVar9 = uVar9 + 3;
      iVar15 = iVar15 + -1;
    } while (iVar15 != 0);
    bVar1 = iVar13 != 3;
    param_2 = param_2 + param_4;
    uVar4 = uVar4 + 0xc;
    iVar13 = iVar13 + 1;
  } while (bVar1);
  *param_1 = (char)((uint)iVar6 >> 8);
  param_1[1] = (char)((uint)iVar14 >> 8);
  return;
}

/* FUN_000307a0 @ 0x307a0 (148 bytes) */
int FUN_000307a0(param_1, param_2)
  int param_1;
  int param_2;
{
  uint *puVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x1dc);
  if (*(int **)(param_1 + 0x1e0) <= piVar2 + 1) {
    FUN_0001a0f0(param_1,0x1000000);
    piVar2 = *(int **)(param_1 + 0x1dc);
  }
  puVar1 = *(uint **)(param_1 + 0x1d8);
  *(int **)(param_1 + 0x1dc) = piVar2 + 1;
  *puVar1 = (int)piVar2 - (int)puVar1 >> 2 | *puVar1;
  *(int **)(param_1 + 0x1d8) = piVar2;
  *piVar2 = param_2 * 0x1000000 + 0x16000000;
  FUN_000a8320(param_1,param_2);
  return;
}

/* FUN_00030840 @ 0x30840 (124 bytes) */
int FUN_00030840(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0xf;
  iVar3 = param_1;
  do {
    if (*(int *)(iVar3 + 0x1c8) != 0) {
      param_2 = FUN_0002cd50(param_1,0,iVar2,param_2);
    }
    iVar2 = iVar2 + -1;
    iVar3 = iVar3 + -4;
  } while (iVar2 != 0);
  uVar1 = FUN_0002cd50(param_1,param_3,0,param_2);
  return uVar1;
}

/* FUN_000308c0 @ 0x308c0 (192 bytes) */
int FUN_000308c0(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar5 = 0;
  iVar4 = 0;
  iVar6 = param_1;
  do {
    iVar3 = *(int *)(iVar6 + 0x18c);
    if (iVar3 != 0) {
      iVar7 = 5;
      piVar2 = (int *)(iVar4 + *(int *)(param_1 + 0x18));
      do {
        if (iVar3 == *piVar2) {
          if (*(int *)(iVar3 + 0x34) != 0) goto LAB_0003093c;
          break;
        }
        piVar2 = piVar2 + 1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      iVar3 = 0;
    }
LAB_0003093c:
    if ((iVar5 == 0) || (iVar3 != 0)) {
      param_2 = FUN_0002cd50(param_1,iVar3,iVar5,param_2);
    }
    bVar1 = iVar5 == 0xf;
    iVar4 = iVar4 + 0x14;
    iVar6 = iVar6 + 4;
    iVar5 = iVar5 + 1;
    if (bVar1) {
      return param_2;
    }
  } while( true );
}

/* FUN_00030990 @ 0x30990 (40 bytes) */
int FUN_00030990(param_1)
  uint param_1;
{
  int iVar1;
  
  iVar1 = 0;
  for (; 1 < param_1; param_1 = param_1 >> 1) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}

/* FUN_000309c0 @ 0x309c0 (136 bytes) */
int FUN_000309c0(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 4);
  *(undefined4 *)(param_3 * 4 + iVar2 + 0x18c) = param_2;
  uVar1 = (**(code **)(iVar2 + 0x2998))(param_1,0xe,param_3);
  *(undefined4 *)(iVar2 + 0x298c) = uVar1;
  uVar1 = FUN_0002cd50(iVar2,param_2,param_3,uVar1);
  *(undefined4 *)(iVar2 + 0x298c) = uVar1;
                    
                    
  (**(code **)(iVar2 + 0x299c))(param_1,uVar1);
  return;
}

/* FUN_00030a50 @ 0x30a50 (8 bytes) */
int FUN_00030a50(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  _gldDeleteTexture(*(undefined4 *)(param_1 + 4),param_2);
  return;
}

/* FUN_00030a60 @ 0x30a60 (240 bytes) */
int FUN_00030a60(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 *param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  *param_1 = 0xc0101000;
  param_1[1] = 0x51b;
  param_1[2] = (param_2 & 0xf) << 8 | 0x42cc30f3;
  param_1[3] = 0x1056b;
  param_1[4] = 0;
  param_1[5] = param_3;
  param_1[6] = 0x10501;
  param_1[7] = 0;
  param_1[8] = param_4;
  param_1[9] = 0x5c1;
  param_1[10] = 0;
  param_1[0xb] = 0x5c0;
  param_1[0xc] = param_5;
  param_1[0xd] = 0x50d;
  param_1[0xe] = param_6;
  param_1[0xf] = 0x1050e;
  param_1[0x10] = 0;
  param_1[0x11] = param_7;
  return param_1 + 0x12;
}

/* FUN_00030b50 @ 0x30b50 (236 bytes) */
int FUN_00030b50(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  
  iVar3 = *(int *)(param_1 + 0x30);
  bVar1 = *(byte *)(iVar3 + 1);
  bVar5 = bVar1 & 0xf;
  *(byte *)(param_1 + 0x6c) = bVar5;
  iVar3 = *(short *)(iVar3 + 0x3c) * 0x18 + iVar3;
  uVar4 = (uint)*(byte *)(iVar3 + 0xaa);
  uVar6 = (uint)*(ushort *)(iVar3 + 0xa4) + uVar4 * -2;
  if ((int)uVar6 < 1) {
    uVar6 = 1;
  }
  uVar2 = (uint)*(ushort *)(iVar3 + 0xa6) + uVar4 * -2;
  if ((int)uVar2 < 1) {
    uVar2 = 1;
  }
  uVar4 = (uint)*(ushort *)(iVar3 + 0xa8) + uVar4 * -2;
  if ((int)uVar4 < 1) {
    uVar4 = 1;
  }
  if (bVar5 == 1) {
    if ((uVar6 & uVar6 - 1) != 0) {
      return 1;
    }
    if ((uVar2 & uVar2 - 1) != 0) {
      return 1;
    }
    uVar6 = uVar4 & uVar4 - 1;
  }
  else if (((bVar1 & 0xf) == 0) || (bVar5 == 3)) {
    if ((uVar6 & uVar6 - 1) != 0) {
      return 1;
    }
    uVar6 = uVar2 & uVar2 - 1;
  }
  else {
    if (bVar5 != 4) {
      return 1;
    }
    uVar6 = uVar6 & uVar6 - 1;
  }
  if (uVar6 != 0) {
    return 1;
  }
  return 0;
}

/* FUN_00030c50 @ 0x30c50 (684 bytes) */
int FUN_00030c50(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  int param_8;
{
  undefined2 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int local_58 [9];
  
  uVar7 = *(undefined4 *)(param_1 + 4);
  local_58[0] = 0;
  puVar1 = (undefined2 *)_malloc(0x910);
  if (puVar1 != (undefined2 *)0x0) {
    puVar1[0x24] = 0;
    *(undefined4 *)(puVar1 + 0x26) = 0;
    *(undefined4 *)(puVar1 + 4) = 0;
    puVar1[6] = 0x405;
    *(undefined4 *)(puVar1 + 0x22) = 0;
    puVar1[10] = 0x2901;
    puVar1[8] = 0x2901;
    puVar1[9] = 0x2901;
    *(undefined4 *)(puVar1 + 0xe) = 0;
    *(undefined4 *)(puVar1 + 0x10) = 0;
    *(undefined4 *)(puVar1 + 0x12) = 0;
    *(undefined4 *)(puVar1 + 0x14) = 0;
    *(undefined4 *)(puVar1 + 0x1c) = 0;
    puVar1[0x1e] = 0;
    puVar1[0x1f] = 0;
    puVar1[0x20] = 0;
    puVar1[0x21] = 0;
    *puVar1 = (short)param_8;
    puVar1[0xd] = 0x85bd;
    *(undefined4 *)(puVar1 + 0x16) = 0x3f800000;
    *(undefined4 *)(puVar1 + 2) = 0x3f800000;
    *(undefined4 *)(puVar1 + 0x18) = 0xc47a0000;
    *(undefined4 *)(puVar1 + 0x1a) = 0x447a0000;
    puVar1[0x2e] = 0x2600;
    puVar1[0xb] = 0x2600;
    puVar1[0xc] = 0x2600;
    puVar1[1] = (*(unsigned short *)((unsigned char *)&(param_5) + 2));
    puVar1[0x2a] = (*(unsigned short *)((unsigned char *)&(param_5) + 2));
    puVar1[0x2c] = (*(unsigned short *)((unsigned char *)&(param_5) + 2));
    puVar1[0x2d] = (*(unsigned short *)((unsigned char *)&(param_7) + 2));
    *(undefined1 *)(puVar1 + 0x2f) = 0;
    *(uint *)(puVar1 + 0x24) = *(uint *)(puVar1 + 0x24) & 0xffff7f7f;
    *(undefined1 *)((int)puVar1 + 0x5f) = 0;
    iVar2 = ((int (*)())FUN_00030990)(param_2);
    iVar3 = ((int (*)())FUN_00030990)(param_3);
    iVar4 = ((int (*)())FUN_00030990)(param_4);
    *(char *)(puVar1 + 0x30) = (char)iVar2;
    *(char *)(puVar1 + 0x31) = (char)iVar4;
    *(char *)((int)puVar1 + 0x61) = (char)iVar3;
    iVar6 = iVar3;
    if (iVar3 < iVar4) {
      iVar6 = iVar4;
    }
    iVar5 = iVar2;
    if (iVar2 < iVar6) {
      iVar5 = iVar6;
    }
    *(char *)((int)puVar1 + 0x65) = (char)iVar3;
    *(char *)(puVar1 + 0x32) = (char)iVar2;
    *(undefined1 *)(puVar1 + 0x36) = 1;
    *(undefined1 *)(puVar1 + 0x35) = 1;
    *(char *)(puVar1 + 0x33) = (char)iVar4;
    *(char *)((int)puVar1 + 0x67) = (char)iVar5;
    *(undefined1 *)((int)puVar1 + 0x6d) = 0;
    puVar1[0x3e] = 1;
    *(char *)((int)puVar1 + 99) = (char)iVar5;
    *(undefined1 *)((int)puVar1 + 0x69) = 0;
    *(undefined1 *)((int)puVar1 + 0x6b) = 0;
    puVar1[0x38] = 1;
    *(char *)(puVar1 + 0x37) = (param_8 == 3) << 1;
    *(char *)((int)puVar1 + 0x6f) = (param_8 == 1) << 1;
    iVar2 = 1 << (*(uint *)(&DAT_001d9f48 + (uint)(byte)param_6 * 0x24) & 7);
    iVar6 = _malloc(iVar2 * param_4 * param_2 * param_3);
    if (iVar6 != 0) {
      *(int *)(puVar1 + 0x5a) = iVar6;
      puVar1[0x54] = (short)param_4;
      puVar1[0x57] = (short)param_3;
      *(undefined1 *)(puVar1 + 0x55) = 0;
      puVar1[0x58] = (*(unsigned short *)((unsigned char *)&(param_5) + 2));
      puVar1[0x56] = (short)param_2 * (short)iVar2;
      puVar1[0x59] = (*(unsigned short *)((unsigned char *)&(param_7) + 2));
      puVar1[0x52] = (short)param_2;
      puVar1[0x53] = (short)param_3;
      iVar6 = _gldCreateTexture(uVar7,local_58,puVar1);
      if ((iVar6 == 0) && (local_58[0] != 0)) {
        *(undefined1 *)(local_58[0] + 0x39) = 0xff;
        *(byte *)(local_58[0] + 0x38) = (byte)param_6;
        *(ushort *)(local_58[0] + 0x24) = *(ushort *)(local_58[0] + 0x24) | 1;
        return local_58[0];
      }
    }
    _free(puVar1);
  }
  return 0;
}

/* FUN_00030f00 @ 0x30f00 (88 bytes) */
int FUN_00030f00(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)(param_2 + 0x38);
  if (uVar1 == 0xc) {
    return -2;
  }
  if ((0xb < uVar1) && (uVar1 < 0x10)) {
    return 1;
  }
  return 1 << (*(uint *)(&DAT_001d9f48 + uVar1 * 0x24) & 7);
}

/* FUN_00030f60 @ 0x30f60 (492 bytes) */
int FUN_00030f60(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
  uint *param_5;
{
  ushort uVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar3 = (uint)*(byte *)(param_2 + 0x38);
  if (uVar3 == 0) {
    ((int (*)())FUN_0002fac0)(param_1,param_2);
    uVar3 = (uint)*(byte *)(param_2 + 0x38);
  }
  iVar4 = uVar3 * 0x24;
  uVar5 = *(uint *)(&DAT_001d9f44 + iVar4);
  if ((uVar5 & 0x3f0000) != 0) {
    if ((uVar5 & 0xfc00) != 0) {
      if ((((uVar5 & 0x3f0) != 0) && (*(uint *)(&DAT_001d9f48 + iVar4) >> 0x1a != 0)) &&
         (*(short *)(*(int *)(param_2 + 0x30) + 2) == 0x1907)) {
        uVar1 = *(ushort *)(&DAT_001d9f3e + iVar4);
        param_5[4] = 0;
        *param_5 = (uint)uVar1;
        param_5[7] = *(uint *)(&DAT_001d9f48 + iVar4) >> 8 & 0x3f;
        goto LAB_000310c0;
      }
    }
  }
  if (uVar3 == 0x29) {
    sVar2 = *(short *)(*(int *)(param_2 + 0x30) + 2);
    if (sVar2 == 0x1902) {
      *param_5 = 0x81a6;
      param_5[7] = (*(unsigned int *)&DAT_001da50c) >> 8 & 0x3f;
    }
    else if (sVar2 == 0x1901) {
      param_5[7] = 0;
      *param_5 = 0x81a6;
    }
    else {
      *param_5 = (uint)(*(unsigned int *)&DAT_001da500);
      param_5[7] = (*(unsigned int *)&DAT_001da50c) >> 8 & 0x3f;
    }
    param_5[4] = 0;
  }
  else {
    *param_5 = (uint)*(ushort *)(&DAT_001d9f3c + iVar4);
    param_5[4] = *(uint *)(&DAT_001d9f48 + iVar4) >> 0x1a;
    param_5[7] = *(uint *)(&DAT_001d9f48 + iVar4) >> 8 & 0x3f;
  }
LAB_000310c0:
  param_5[1] = *(ushort *)(&DAT_001d9f44 + iVar4) & 0x3f;
  param_5[2] = *(uint *)(&DAT_001d9f44 + iVar4) >> 10 & 0x3f;
  param_5[3] = *(uint *)(&DAT_001d9f44 + iVar4) >> 4 & 0x3f;
  param_5[5] = *(uint *)(&DAT_001d9f48 + iVar4) >> 0x14 & 0x3f;
  param_5[6] = *(uint *)(&DAT_001d9f48 + iVar4) >> 0xe & 0x3f;
  uVar3 = *(uint *)(&DAT_001d9f48 + iVar4) >> 3 & 1;
  *(char *)(param_5 + 9) = (char)uVar3;
  if (uVar3 == 0) {
    param_5[8] = 0;
  }
  else {
    iVar4 = *(int *)(param_2 + 0x30) + 0xa0 + param_4 * 0x18 + param_3 * 0x168;
    uVar3 = ((int (*)())FUN_000303d0)((uint)*(byte *)(param_2 + 0x38),(uint)*(ushort *)(iVar4 + 4),
                         (uint)*(ushort *)(iVar4 + 6),(uint)*(ushort *)(iVar4 + 8));
    param_5[8] = uVar3;
  }
  return;
}

/* FUN_00031170 @ 0x31170 (164 bytes) */
int FUN_00031170(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  uint param_1;
  undefined4 param_2;
  int param_3;
  uint *param_4;
  uint *param_5;
  uint *param_6;
  int *param_7;
  uint *param_8;
  uint *param_9;
{
  int iVar1;
  
  iVar1 = (param_1 & 0xff) * 0x24;
  *(uint *)(param_3 + 0x18) = *(uint *)(&DAT_001d9f44 + iVar1) >> 0x1b;
  *(uint *)(param_3 + 0x1c) = *(uint *)(&DAT_001d9f44 + iVar1) >> 0x16 & 0x1f;
  *param_8 = *(uint *)(&DAT_001d9f4c + iVar1) >> 0x17 & 0x1f;
  *param_9 = *(uint *)(&DAT_001d9f4c + iVar1) >> 0x1e;
  *param_4 = *(uint *)(&DAT_001d9f48 + iVar1) & 7;
  *param_5 = *(uint *)(&DAT_001d9f4c + iVar1) >> 0x14 & 7;
  *param_6 = *(uint *)(&DAT_001d9f4c + iVar1) >> 0x11 & 7;
  *param_7 = 1 << (*(uint *)(&DAT_001d9f48 + iVar1) & 7);
  *(uint *)(param_3 + 0x24) = *(uint *)(param_3 + 0x24) & *(uint *)(&DAT_001d9f40 + iVar1);
  return;
}

/* FUN_00031220 @ 0x31220 (280 bytes) */
int FUN_00031220(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  uint param_4;
  int param_5;
{
  bool bVar1;
  ushort uVar2;
  int iVar3;
  undefined *puVar4;
  ushort *puVar5;
  
  puVar5 = *(ushort **)(param_2 + 0x30);
  if (*(char *)(param_2 + 0x38) == '\0') {
    ((int (*)())FUN_0002fac0)(param_1,param_2);
  }
  bVar1 = param_5 == 0;
  if ((((!bVar1) ||
       ((((*(uint *)(((unsigned char *)0x000030b0) + *(int *)(param_1 + 0x10)) & 0x1ff) == 0 &&
         ((*(uint *)(((unsigned char *)0x000030b4) + *(int *)(param_1 + 0x10)) & 0xff0000) == 0)) &&
        ((*(uint *)(((unsigned char *)0x000030b4) + *(int *)(param_1 + 0x10)) & 0xff1) == 0)))) &&
      ((*(char *)(puVar5 + param_3 * 0xb4 + param_4 * 0xc + 0x55) == '\0' &&
       (uVar2 = *puVar5, (uVar2 & 0xf) != 4)))) && ((!bVar1 || ((uVar2 & 0x400) == 0)))) {
    iVar3 = (uint)*(byte *)(param_2 + 0x38) * 0x24;
    puVar4 = &DAT_001d9f34 + iVar3;
    if (((*(uint *)(*(int *)(param_2 + 0x30) + 0x48) & 0x8000) == 0) && (bVar1)) {
      return puVar4;
    }
    if (param_4 != *(byte *)(*(int *)(param_2 + 0x30) + 0x5e)) {
      return puVar4;
    }
    if ((*(uint *)(&DAT_001d9f54 + iVar3) & 0x1000000) != 0) {
      return puVar4;
    }
  }
  return (undefined *)0x0;
}

/* FUN_00031340 @ 0x31340 (1352 bytes) */
int FUN_00031340(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int *param_2;
  int param_3;
  uint param_4;
  undefined4 *param_5;
  undefined4 param_6;
  int param_7;
  undefined4 *param_8;
{
  byte bVar1;
  char cVar2;
  int iVar3;
  uint *puVar4;
  short sVar5;
  undefined4 *a6;
  int iVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined4 *a1;
  undefined4 uVar10;
  undefined1 *puVar11;
  undefined4 *a7;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined4 *puVar16;
  uint uVar17;
  undefined1 auStack_140 [4];
  undefined1 auStack_13c [4];
  undefined1 auStack_138 [4];
  undefined1 auStack_134 [4];
  undefined1 auStack_130 [4];
  undefined1 auStack_12c [4];
  int local_128;
  uint local_124;
  int local_120;
  undefined4 local_11c;
  int local_118;
  undefined4 *local_114;
  undefined1 auStack_110 [4];
  undefined1 auStack_10c [4];
  undefined4 local_108;
  uint local_104;
  undefined4 local_100;
  int local_fc;
  int local_f8;
  undefined1 local_bc;
  undefined4 local_b8;
  uint local_b4;
  int local_a0;
  undefined4 local_9c;
  
  puVar16 = (undefined4 *)param_2[0xd];
  iVar14 = *param_2;
  if ((puVar16 == (undefined4 *)0x0) || (*(char *)(param_2 + 0xe) == '\0')) {
    return 0x2717;
  }
  uVar17 = param_4;
  a1 = param_5;
  uVar10 = param_6;
  a7 = param_8;
  if ((*(short *)(param_2[0xc] + 2) == 0x1902) && (*(char *)(param_2 + 0x32) == '\x01')) {
    iVar13 = param_3;
    a6 = (undefined4 *)(**(code **)(param_1 + 0x2998))(param_1 + 0x240,0x3fa);
    *(undefined4 **)(param_1 + 0x298c) = a6;
    a7 = a6 + 0x3ed;
    uVar10 = 0x113c8;
    a1 = a6 + 0x3f8;
    puVar4 = *(uint **)(param_1 + 0x1d8);
    *puVar4 = (int)a6 - (int)puVar4 >> 2 | *puVar4;
    *(undefined4 **)(param_1 + 0x1d8) = a6;
    *a6 = 0x45000000;
    a6[1] = 0x3ed;
    a6[2] = 0xd;
    a6[3] = *(undefined4 *)param_2[0xd];
    bVar1 = *(byte *)(param_2 + 0xe);
    a6[0x3ed] = ((unsigned char *)0x000013c4U);
    a6[4] = (uint)bVar1;
    a6[0x3f6] = ((unsigned char *)0x000013caU);
    a6[0x3ef] = 0x113c8;
    a6[0x3f4] = ((unsigned char *)0x000013ccU);
    a6[0x3f2] = ((unsigned char *)0x000013cdU);
    *(undefined4 **)(param_1 + 0x298c) = a1;
    (**(code **)(param_1 + 0x299c))(param_1 + 0x240,a1,iVar13,uVar17,a1,0x113c8,a6,a7);
    if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
      FUN_0001a0f0(param_1,0x1000000);
    }
    *(undefined1 *)(param_2 + 0x32) = 0;
  }
  cVar2 = *(char *)((int)puVar16 + 0x16);
  if ((cVar2 != '\x03') && (cVar2 != '\a')) {
    if (cVar2 != '\x06') {
      return 0x2717;
    }
    if ((0x1ffff < (int)puVar16[4]) &&
       (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc))) {
      FUN_0001a0f0(param_1,0x1000000);
    }
    iVar14 = param_3 * 2;
    iVar13 = iVar14 + (int)puVar16;
    if ((((uint)*(ushort *)(iVar13 + 0x28) & ~(uint)*(ushort *)(iVar13 + 0x1c)) >> (param_4 & 0x3f)
        & 1) == 0) {
      return 0;
    }
    iVar6 = FUN_0001a0d0(param_1,puVar16[3]);
    if (iVar6 == 0) {
      uVar17 = 1;
      a1 = (undefined4 *)0x0;
      uVar10 = 0;
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),9,puVar16 + 3,1,0,0);
    }
    if ((param_7 != 0) && ((*(uint *)(param_1 + 0x24) & 0x82) != 0)) {
      FUN_0000b670(param_1,param_7,param_2[4],uVar17,a1,uVar10,iVar13,a7);
    }
    *(ushort *)((int)puVar16 + iVar14 + 0x1c) =
         *(ushort *)((int)puVar16 + iVar14 + 0x1c) | *(ushort *)((int)puVar16 + iVar14 + 0x28);
    return 0;
  }
  iVar13 = iVar14 + 0x40 + (param_3 * 0xd + param_4) * 0x20;
  if ((0x1ffff < (int)puVar16[4]) &&
     (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc))) {
    FUN_0001a0f0(param_1,0x1000000);
  }
  if ((((uint)*(ushort *)((int)puVar16 + param_3 * 2 + 0x28) &
       ~(uint)*(ushort *)((int)puVar16 + param_3 * 2 + 0x1c)) >> (param_4 & 0x3f) & 1) != 0) {
    local_b8 = *puVar16;
    local_b4 = param_4 | param_3 << 0x10;
    _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xd,&local_b8,2,0,0);
  }
  if ((*(uint *)(iVar14 + 0x20) & 0x10000000) != 0) {
    iVar6 = FUN_0001a0d0(param_1,*(undefined4 *)(iVar14 + 0x1c));
    if (iVar6 == 0) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),9,iVar14 + 0x1c,1,0,0);
    }
    *(uint *)(iVar14 + 0x20) = *(uint *)(iVar14 + 0x20) & 0xefffffff;
  }
  if (*(char *)((int)puVar16 + 0x16) == '\a') {
    return 0;
  }
  uVar17 = param_4 - *(byte *)((int)puVar16 + 0x17);
  iVar3 = (int)(uint)*(ushort *)(iVar14 + 0x14) >> (uVar17 & 0x3f);
  iVar15 = (int)(uint)*(ushort *)(iVar14 + 0x16) >> (uVar17 & 0x3f);
  iVar12 = (int)(uint)*(ushort *)(iVar14 + 0x18) >> (uVar17 & 0x3f);
  iVar6 = 1;
  if (0 < iVar3) {
    iVar6 = iVar3;
  }
  if (iVar15 < 1) {
    iVar15 = 1;
  }
  if (iVar12 < 1) {
    iVar12 = 1;
  }
  puVar9 = auStack_13c;
  iVar12 = iVar12 / (int)(uint)*(ushort *)(iVar13 + 2);
  puVar11 = auStack_138;
  ((int (*)())FUN_00031170)((uint)*(byte *)(param_2 + 0xe),param_2,&local_b8,auStack_140,puVar9,puVar11,
               auStack_134,auStack_130,auStack_12c);
  uVar10 = 0;
  local_108 = 2;
  local_120 = local_a0;
  local_11c = local_9c;
  local_104 = 0;
  local_100 = 0xffffefff;
  local_124 = *(uint *)(iVar14 + 0x10) >> (uVar17 & 0x3f);
  if ((int)local_124 < 0x20) {
    local_124 = 0x20;
  }
  local_bc = 0;
  puVar7 = auStack_110;
  puVar8 = auStack_10c;
  local_118 = param_7;
  local_114 = param_8;
  local_fc = iVar6;
  local_f8 = iVar15;
  _glgConvertType(param_5,param_6,puVar7,puVar8,puVar9,puVar11,local_a0,0);
  iVar14 = *(int *)(iVar13 + 0x1c);
  if (iVar14 == 0) {
    return 0x2717;
  }
  sVar5 = *(short *)(param_2[0xc] + 2);
  if ((sVar5 == 0x1909) || (uVar17 = local_104 | 0x20000, sVar5 == 0x1907)) {
    local_104 = local_104 | 0x28000;
    sVar5 = *(short *)(param_2[0xc] + 2);
    uVar17 = local_104;
    if (sVar5 != 0x1909) goto LAB_000316d8;
  }
  else {
LAB_000316d8:
    local_104 = uVar17;
    if ((sVar5 != -0x7fb7) && (sVar5 != 0x190a)) goto LAB_000316fc;
  }
  local_104 = local_104 | 0x40000;
LAB_000316fc:
  if (*(short *)(iVar13 + 2) != 0) {
    iVar6 = 0;
    do {
      if (0 < iVar12) {
        iVar3 = 0;
        local_128 = iVar14;
        do {
          iVar3 = iVar3 + 1;
          _glgProcessPixels(0,&local_128,puVar7,puVar8,puVar9,puVar11,local_a0,uVar10);
          local_128 = iVar15 * local_124 + local_128;
          local_a0 = iVar15 * (int)local_114 + local_118;
          local_118 = local_a0;
        } while (iVar12 != iVar3);
      }
      iVar6 = iVar6 + 1;
      iVar14 = iVar14 + *(int *)(iVar13 + 0xc);
    } while (iVar6 < (int)(uint)*(ushort *)(iVar13 + 2));
  }
  return 0;
}

/* _gldGetTextureLevel @ 0x31890 (176 bytes) */
int _gldGetTextureLevel(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar3 = 0x2717;
  if (*(int *)(param_2 + 0x30) != 0) {
    iVar4 = *(int *)(param_2 + 0x30) + 0xa0 + param_4 * 0x18 + param_3 * 0x168;
    uVar1 = *(ushort *)(iVar4 + 0xc);
    iVar2 = FUN_0000a3f0((uint)*(ushort *)(iVar4 + 0x10),(uint)*(ushort *)(iVar4 + 0x12));
    _pthread_mutex_lock(*(undefined4 *)(param_1 + 0xc));
    uVar3 = ((int (*)())FUN_00031340)(param_1,param_2,param_3,param_4,(uint)*(ushort *)(iVar4 + 0x10),
                         (uint)*(ushort *)(iVar4 + 0x12),*(undefined4 *)(iVar4 + 0x14),
                         (uint)uVar1 * iVar2);
    _pthread_mutex_unlock(*(undefined4 *)(param_1 + 0xc));
  }
  return uVar3;
}

/* FUN_00031940 @ 0x31940 (1972 bytes) */
int FUN_00031940(param_1, param_2)
  int param_1;
  int *param_2;
{
  bool bVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  uint uVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  uint uVar17;
  uint uVar18;
  undefined4 uVar19;
  int *piVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  int iVar26;
  int *piVar27;
  int *piVar28;
  undefined *puVar29;
  int iVar30;
  uint local_f8;
  uint local_f4;
  int local_f0;
  int local_ec;
  undefined1 auStack_e8 [4];
  int local_e4;
  int local_e0;
  undefined1 auStack_dc [4];
  undefined1 auStack_d8 [4];
  int *local_d4;
  uint local_d0;
  undefined4 local_c0;
  uint local_b8;
  uint local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  uint local_68;
  int local_64;
  int *local_60;
  int *local_5c;
  
  iVar9 = param_2[0xc];
  iVar7 = (uint)*(byte *)(param_2 + 0xe) * 0x24;
  bVar2 = *(byte *)(iVar9 + 0x5e);
  uVar21 = (uint)bVar2;
  uVar3 = *(ushort *)(iVar9 + 0x7c);
  local_5c = &local_e4;
  iVar30 = iVar9 + 0xa0 + uVar21 * 0x18;
  uVar23 = (uint)((*(uint *)(&DAT_001d9f48 + iVar7) & 7) == 4);
  iVar9 = FUN_0000a3f0((uint)*(ushort *)(iVar30 + 0x10),(uint)*(ushort *)(iVar30 + 0x12));
  puVar16 = auStack_e8;
  iVar26 = iVar9 * (uint)*(ushort *)(iVar30 + 0xc);
  uVar22 = uVar23 ^ 1;
  iVar9 = (uint)*(byte *)(iVar30 + 10) * (iVar9 + iVar26) + *(int *)(iVar30 + 0x14);
  ((int (*)())FUN_00031170)((uint)*(byte *)(param_2 + 0xe),param_2,local_5c,&local_f8,puVar16,puVar16,&local_ec,
               &local_f4,&local_f0);
  uVar25 = (uint)*(ushort *)(iVar30 + 4) + (uint)*(byte *)(iVar30 + 10) * -2;
  if ((int)uVar25 < 1) {
    uVar25 = 1;
  }
  uVar24 = (uint)*(ushort *)(iVar30 + 6) + (uint)*(byte *)(iVar30 + 10) * -2;
  if ((int)uVar24 < 1) {
    uVar24 = 1;
  }
  local_c0 = 0;
  if (uVar23 == 0) {
    uVar17 = *(uint *)(&DAT_001d9f4c + iVar7) >> 0x1c & 3;
    if (uVar17 == 0) {
      local_64 = 1;
      uVar18 = 0;
    }
    else {
      local_64 = 0;
      uVar18 = uVar17;
    }
  }
  else {
    uVar17 = 0;
    local_64 = 0;
    uVar18 = 0;
  }
  if (((uVar23 != 0) || ((*(uint *)(&DAT_001d9f4c + iVar7) & 0x30000000) != 0x20000000)) ||
     (local_68 = 1, (*(uint *)(&DAT_001d9f48 + iVar7) & 7) != 1)) {
    local_68 = 0;
  }
  uVar18 = 8 << uVar18;
  uVar23 = (0x20 >> (local_f8 + uVar17 & 0x3f)) * 8;
  if ((uVar25 <= uVar23) || (uVar17 = 1, uVar24 <= uVar18)) {
    uVar17 = 0;
  }
  uVar6 = (uVar25 << (local_f8 & 0x3f)) + 0x1f & 0xffffffe0;
  iVar7 = uVar6 * uVar24;
  if (uVar17 == 0) {
    uVar22 = 0;
    iVar11 = iVar7;
    uVar23 = uVar6;
  }
  else {
    uVar23 = uVar23 * (((uVar23 + uVar25) - 1) / uVar23) << (local_f8 & 0x3f);
    iVar11 = uVar18 * (((uVar18 + uVar24) - 1) / uVar18) * uVar23;
  }
  *(short *)((int)param_2 + 0x3e) = (short)(uVar23 >> (local_f8 & 0x3f));
  uVar18 = local_f8;
  iVar11 = FUN_0000acb0(param_1,param_2,iVar7 + 0x3a0,iVar11);
  uVar19 = 0;
  if (iVar11 == 0) {
    return 0;
  }
  iVar11 = param_2[0xd];
  *(byte *)(iVar11 + 0x15) = (byte)(uVar17 << 2) | (byte)((uVar22 << (local_68 & 0x3f)) << 3) & 0x18
  ;
  piVar27 = (int *)*param_2;
  if ((uVar3 & 1) != 0) {
    puVar15 = auStack_d8;
    piVar28 = piVar27 + 0x368;
    _glgConvertType((uint)*(ushort *)(iVar30 + 0x10),(uint)*(ushort *)(iVar30 + 0x12),auStack_dc,
                    puVar15,puVar16,uVar18,iVar11,0);
    local_ac = 0;
    local_b0 = 0;
    local_60 = piVar27 + 0x280;
    uVar14 = (uint)*(byte *)(param_2 + 0xe);
    local_e4 = iVar9;
    local_e0 = iVar26;
    local_d4 = piVar28;
    local_d0 = uVar6;
    local_b8 = uVar25;
    local_b4 = uVar24;
    iVar26 = ((int (*)())FUN_0002f4d0)((uint)*(ushort *)(iVar30 + 0x10),(uint)*(ushort *)(iVar30 + 0x12),uVar14);
    if (iVar26 == 0) {
      _glgProcessPixels(0,local_5c,uVar14,puVar15,puVar16,uVar18,iVar11,uVar19);
    }
    else if (uVar24 != 0) {
      uVar14 = 0;
      do {
        uVar14 = uVar14 + 1;
        _memcpy(piVar28,iVar9,local_ec * local_b8);
        piVar28 = (int *)((int)piVar28 + local_d0);
        iVar9 = iVar9 + local_e0;
      } while (uVar14 < local_b4);
    }
    if ((*(uint *)(param_1 + 0x24) & 0x82) != 0) {
      FUN_0000b620(param_1,local_60 + 0x20,iVar7,puVar15,puVar16,uVar18,local_60,uVar19);
    }
  }
  if ((*(byte *)((int)param_2 + 0x39) & 3) == 0) goto LAB_00032098;
  if ((local_f4 < 3) || ((iVar7 = 1, 4 < local_f4 && (iVar7 = 2, local_f4 != 6)))) {
    iVar7 = 0;
  }
  piVar28 = piVar27 + 0x280;
  *(byte *)(param_2[0xd] + 0x17) = bVar2;
  bVar1 = (int)(uVar25 << (local_f8 & 0x3f)) >> iVar7 < 0x2000;
  *(undefined1 *)(param_2[0xd] + 0x34) = 1;
  *(undefined1 *)(param_2[0xd] + 0x35) = 1;
  *(uint *)(*param_2 + 0x20) = (uint)bVar1 << 0x1f | *(uint *)(*param_2 + 0x20) & 0x7fffffff;
  *(uint *)(*param_2 + 0x20) = *(uint *)(*param_2 + 0x20) | 0x40000000;
  piVar27[1] = 0x20;
  piVar27[2] = 0;
  *piVar27 = 0;
  uVar18 = piVar27[8];
  piVar27[8] = uVar18 & 0xefffffff;
  *(char *)((int)piVar27 + 0x1a) = (char)local_f8;
  *(undefined2 *)(piVar27 + 6) = 1;
  *(short *)(piVar27 + 5) = (short)uVar25;
  *(short *)((int)piVar27 + 0x16) = (short)uVar24;
  piVar27[8] = uVar18 & 0xcfffffff;
  piVar27[3] = uVar23;
  piVar27[4] = uVar6;
  *(char *)((int)piVar27 + 0x1b) = (char)local_f0;
  iVar9 = (uint)*(byte *)(param_2 + 0xe) * 0x24;
  puVar29 = &DAT_001d9f34 + iVar9;
  if ((*(uint *)(&DAT_001d9f4c + iVar9) & 0x10000) == 0) {
    if ((*(uint *)(&DAT_001d9f48 + iVar9) & 8) == 0) {
      uVar18 = *(uint *)(&DAT_001d9f48 + iVar9) & 7;
      if (uVar18 == 1) {
        puVar29 = &DAT_001da00c;
      }
      else if (uVar18 < 2) {
        if (uVar18 == 0) {
          puVar29 = &DAT_001d9fa0;
        }
        else {
LAB_00031db8:
          puVar29 = &DAT_001da1bc;
        }
      }
      else {
        if (uVar18 == 2) goto LAB_00031eb4;
        if (uVar18 != 3) goto LAB_00031db8;
        puVar29 = &DAT_001da36c;
      }
    }
    else {
LAB_00031eb4:
      puVar29 = &DAT_001da054;
    }
  }
  _memcpy(piVar27 + 0x2a0,PTR_DAT_001e899c,0x23c);
  uVar8 = piVar27[0x306];
  uVar10 = piVar27[0x31c];
  piVar27[0x2ab] = 0;
  uVar18 = *(uint *)(puVar29 + 0x18) >> 5 & 0x1f;
  piVar27[0x306] = uVar18 | uVar8 & 0xffffffe0;
  uVar14 = (*(uint *)(puVar29 + 0x18) & 0x18) << 5;
  piVar27[0x306] = uVar14 | uVar18 | uVar8 & 0xfffffce0;
  uVar4 = (*(uint *)(puVar29 + 0x18) & 6) << 9;
  piVar27[0x306] = uVar4 | uVar14 | uVar18 | uVar8 & 0xfffff0e0;
  uVar5 = *(uint *)(puVar29 + 0x1c) >> 0x12 & 0x3000;
  piVar27[0x306] = uVar5 | uVar4 | uVar14 | uVar18 | uVar8 & 0xffffc0e0;
  piVar27[0x306] =
       *(uint *)(puVar29 + 0x1c) >> 0xe & 0xc000 |
       uVar5 | uVar4 | uVar14 | uVar18 | uVar8 & 0xfff000e0;
  uVar18 = *(uint *)(puVar29 + 0x1c) >> 7 & 0x1f;
  piVar27[0x31c] = uVar18 | uVar10 & 0xfffffe00;
  uVar14 = (*(uint *)(puVar29 + 0x1c) & 0x70) << 5;
  piVar27[0x31c] = uVar14 | uVar18 | uVar10 & 0xfffff000;
  uVar4 = (*(uint *)(puVar29 + 0x1c) & 0xe) << 0xb;
  piVar27[0x31c] = uVar4 | uVar14 | uVar18 | uVar10 & 0xffff8000;
  uVar5 = *(uint *)(puVar29 + 0x20) >> 0xe & 0x38000;
  piVar27[0x31c] = uVar5 | uVar4 | uVar14 | uVar18 | uVar10 & 0xfffc0000;
  uVar8 = *(uint *)(puVar29 + 0x20) >> 8 & 0x1c0000;
  piVar27[0x31c] = uVar8 | uVar5 | uVar4 | uVar14 | uVar18 | uVar10 & 0xffc00000;
  piVar27[0x31c] =
       (*(uint *)(puVar29 + 0x20) >> 0x19 & 1) << 0x16 |
       uVar8 | uVar5 | uVar4 | uVar14 | uVar18 | uVar10 & 0xf8000000;
  piVar20 = piVar28;
  if (bVar1) {
    *piVar28 = (int)((unsigned char *)0x00001393U);
    piVar27[0x281] = 10;
    piVar27[0x282] = 0x5c8;
    piVar27[0x283] = 0x20000;
    piVar27[0x284] = 0x575;
    piVar20 = piVar27 + 0x286;
    piVar27[0x285] = local_f0;
  }
  iVar26 = (int)piVar20 - (int)piVar28 >> 2;
  *(short *)(piVar27 + uVar21 * 8 + 0x10) = (short)iVar26;
  iVar9 = piVar27[1];
  piVar27[uVar21 * 8 + 0x17] = (int)(piVar27 + 0x368);
  piVar27[uVar21 * 8 + 0x11] = 0xda0;
  piVar27[uVar21 * 8 + 0x15] = 0;
  *(undefined2 *)((int)piVar27 + uVar21 * 0x20 + 0x42) = 1;
  piVar27[uVar21 * 8 + 0x12] = 0;
  piVar27[uVar21 * 8 + 0x13] = 0;
  piVar27[uVar21 * 8 + 0x14] = 0;
  *(short *)(piVar27 + uVar21 * 8 + 0x16) =
       (short)((int)(piVar27 + 0x32f) - (int)piVar28 >> 2) - (short)iVar9;
  if ((uVar22 == 0) || (uVar21 = 1, local_64 != 0)) {
    uVar21 = 0;
  }
  uVar17 = (local_68 << 1 | uVar21) << 1 | uVar17;
  puVar12 = (undefined4 *)
            ((int (*)())FUN_00030420)(piVar27 + 0x32f,puVar29,uVar6,uVar23,uVar17,
                         (int)(uVar25 << (local_f8 & 0x3f)) >> (*(uint *)(puVar29 + 0x14) & 7),
                         uVar24);
  *puVar12 = ((unsigned char *)0x00001393U);
  puVar12[1] = 10;
  puVar12[2] = 0x5c8;
  puVar12[3] = 0x20000;
  puVar12[4] = ((unsigned char *)0x00001040U);
  puVar12[5] = 0;
  if (bVar1) {
    puVar13 = (undefined4 *)
              ((int (*)())FUN_00030a60)(piVar20,local_f4,uVar6,uVar23,uVar17,0,
                           uVar24 << 0x10 | (int)(uVar25 << (local_f8 & 0x3f)) >> iVar7);
    *puVar13 = 0xd0b;
    puVar13[1] = 5;
    puVar13[2] = 0x5c8;
    puVar13[3] = 0x10000;
    puVar13[4] = ((unsigned char *)0x00001040U);
    puVar13[5] = 0;
    iVar26 = (int)puVar13 + (0x18 - (int)piVar28) >> 2;
  }
  *piVar27 = iVar26;
  piVar27[2] = ((int)puVar12 + (0x18 - (int)piVar28) >> 2) - piVar27[1];
LAB_00032098:
  *(ushort *)(param_2[0xd] + 0x1c) = uVar3 | *(ushort *)(param_2[0xd] + 0x1c);
  *(ushort *)(param_2[0xd] + 0x28) = ~uVar3 & *(ushort *)(param_2[0xd] + 0x28);
  *(byte *)((int)param_2 + 0x39) = *(byte *)((int)param_2 + 0x39) & 0xf8;
  *(ushort *)(param_2 + 9) = ~uVar3 & *(ushort *)(param_2 + 9);
  return 1;
}

/* FUN_00032100 @ 0x32100 (8252 bytes) */
int FUN_00032100(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int *param_2;
  uint param_3;
  undefined4 param_4;
  undefined4 param_5;
  uint param_6;
{
  bool bVar1;
  bool bVar2;
  byte bVar3;
  byte bVar4;
  short sVar5;
  ushort uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  undefined4 *puVar12;
  int *piVar13;
  undefined4 extraout_r4;
  int *piVar14;
  uint uVar15;
  undefined4 uVar16;
  uint *puVar17;
  undefined1 *puVar18;
  undefined4 uVar19;
  uint uVar20;
  int iVar21;
  uint uVar22;
  uint uVar23;
  int *piVar24;
  int iVar25;
  uint *puVar26;
  ushort uVar27;
  uint uVar28;
  int iVar29;
  uint uVar30;
  ushort *puVar31;
  uint uVar32;
  int iVar33;
  int *piVar34;
  int iVar35;
  uint uVar36;
  undefined *puVar37;
  undefined1 *puVar38;
  byte in_xer_so;
  bool bVar39;
  bool bVar40;
  byte in_cr1;
  byte unaff_cr2;
  byte unaff_cr3;
  byte unaff_cr4;
  byte in_cr5;
  byte bVar41;
  byte bVar42;
  byte bVar43;
  undefined8 uVar44;
  int iStack00000018;
  uint local_218;
  uint local_214;
  uint local_210;
  int local_20c;
  int local_208;
  int local_204;
  int aiStack_200 [14];
  int aiStack_1c8 [9];
  undefined4 local_1a4;
  uint local_158;
  uint local_154;
  undefined1 auStack_150 [4];
  undefined1 auStack_14c [4];
  uint local_148;
  int local_144;
  undefined4 local_138;
  uint local_134;
  undefined4 local_130;
  uint local_12c;
  uint local_128;
  undefined4 local_124;
  undefined4 local_120;
  int *local_e8;
  int local_e4;
  int local_e0;
  int *local_dc;
  int local_d8;
  int *local_d4;
  int local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  uint local_c0;
  int local_bc;
  uint local_b8;
  uint local_b4;
  uint local_b0;
  int local_ac;
  uint local_a8;
  uint local_a4;
  uint local_a0;
  uint local_9c;
  uint local_98;
  uint local_94;
  uint local_90;
  int *local_8c;
  uint local_88;
  int *local_84;
  uint local_80;
  uint local_7c;
  uint local_78;
  int local_74;
  uint local_70;
  uint local_6c;
  uint local_68;
  uint *local_64;
  uint local_60;
  int *local_5c;
  uint local_58;
  uint local_54;
  
  puVar31 = (ushort *)param_2[0xc];
  iStack00000018 = param_1;
  iVar11 = ((int (*)())FUN_00030b50)(param_2,param_2,param_3,param_4,param_5,param_6);
  if (iVar11 != 0) {
    iVar25 = param_2[0xc];
    bVar41 = *(byte *)(iVar25 + 1);
    bVar42 = bVar41 & 0xf;
    *(byte *)(param_2 + 0x1b) = bVar42;
    iVar11 = *(short *)(iVar25 + 0x3c) * 0x18 + iVar25;
    uVar22 = (uint)*(byte *)(iVar11 + 0xaa);
    if ((bVar41 & 0xf) == 0) {
      uVar28 = (uint)*(ushort *)(iVar11 + 0xa4) + uVar22 * -2;
      if ((int)uVar28 < 1) {
        uVar28 = 1;
      }
      uVar22 = (uint)*(ushort *)(iVar11 + 0xa6) + uVar22 * -2;
      if ((int)uVar22 < 1) {
        uVar22 = 1;
      }
      if (((uVar28 & uVar28 - 1) == 0) && (param_6 = uVar22 & uVar22 - 1, param_6 == 0))
      goto LAB_00032230;
      goto LAB_00032380;
    }
    if (bVar42 == 1) {
      uVar28 = (uint)*(ushort *)(iVar11 + 0xa4) + uVar22 * -2;
      if ((int)uVar28 < 1) {
        uVar28 = 1;
      }
      param_6 = (uint)*(ushort *)(iVar11 + 0xa6) + uVar22 * -2;
      if ((int)param_6 < 1) {
        param_6 = 1;
      }
      uVar22 = (uint)*(ushort *)(iVar11 + 0xa8) + uVar22 * -2;
      if ((int)uVar22 < 1) {
        uVar22 = 1;
      }
      if ((((uVar28 & uVar28 - 1) != 0) || ((param_6 & param_6 - 1) != 0)) ||
         ((uVar22 & uVar22 - 1) != 0)) goto LAB_00032380;
    }
LAB_00032230:
    bVar41 = *(byte *)(iVar25 + 1) & 0xf;
    *(byte *)(param_2 + 0x1b) = bVar41;
    iVar11 = *(short *)(iVar25 + 0x3c) * 0x18 + iVar25;
    uVar22 = (uint)*(byte *)(iVar11 + 0xaa);
    if (bVar41 == 3) {
      uVar28 = (uint)*(ushort *)(iVar11 + 0xa4) + uVar22 * -2;
      if ((int)uVar28 < 1) {
        uVar28 = 1;
      }
      uVar22 = (uint)*(ushort *)(iVar11 + 0xa6) + uVar22 * -2;
      if ((int)uVar22 < 1) {
        uVar22 = 1;
      }
      if (((uVar28 & uVar28 - 1) != 0) || ((uVar22 & uVar22 - 1) != 0)) {
        if ((ushort)(*(short *)(iVar25 + 0x16) + 0xda00U) < 2) {
          uVar27 = *(ushort *)(iVar25 + 0x10);
          if (uVar27 < 0x8744) {
            if (((uVar27 < 0x8742) && (uVar27 != 0x2901)) && (uVar27 != 0x8370)) {
LAB_00032340:
              uVar27 = *(ushort *)(iVar25 + 0x12);
              if (0x8743 < uVar27) goto LAB_00032370;
LAB_0003234c:
              if (((uVar27 < 0x8742) && (uVar27 != 0x2901)) && (uVar27 != 0x8370))
              goto LAB_00032390;
            }
          }
          else if (uVar27 != 0x8912) goto LAB_00032340;
        }
LAB_00032380:
        *(undefined1 *)(param_2 + 0x11) = 1;
        goto LAB_000323a0;
      }
    }
    else if (bVar41 == 4) {
      uVar22 = (uint)*(ushort *)(iVar11 + 0xa4) + uVar22 * -2;
      if ((int)uVar22 < 1) {
        uVar22 = 1;
      }
      param_6 = uVar22 & uVar22 - 1;
      if (param_6 != 0) {
        if (1 < (ushort)(*(short *)(iVar25 + 0x16) + 0xda00U)) goto LAB_00032380;
        uVar27 = *(ushort *)(iVar25 + 0x10);
        if (uVar27 < 0x8744) goto LAB_0003234c;
LAB_00032370:
        if (uVar27 == 0x8912) goto LAB_00032380;
      }
    }
LAB_00032390:
    *(undefined1 *)(param_2 + 0x11) = 0;
  }
LAB_000323a0:
  bVar41 = *(byte *)((int)param_2 + 0x39);
  *(byte *)((int)param_2 + 0x39) = bVar41 & 0x9f;
  if ((bVar41 & 0x1f) == 0) {
    ((int (*)())FUN_0002ee30)(iStack00000018,param_2);
    return 1;
  }
  ((int (*)())FUN_0002fac0)(iStack00000018,param_2);
  if (*(char *)(param_2 + 0xe) == '\0') {
    return 0;
  }
  bVar39 = *(char *)((int)puVar31 + 0x6f) == '\0';
  bVar41 = (*(char *)((int)puVar31 + 0x6f) != '\0') << 2 | bVar39 << 1 | in_xer_so & 1;
  if (!bVar39) {
    if (((unsigned char *)0x00001001) <= (undefined *)(1 << (*(byte *)(puVar31 + 0x32) & 0x3f))) {
      return 0;
    }
    if (((unsigned char *)0x00001001) <= (undefined *)(1 << (*(byte *)((int)puVar31 + 0x65) & 0x3f))) {
      return 0;
    }
    if (0x100 < (uint)(1 << (*(byte *)(puVar31 + 0x33) & 0x3f))) {
      return 0;
    }
  }
  uVar27 = *puVar31;
  uVar22 = (uint)*(byte *)(puVar31 + 0x2f);
  if ((uVar27 & 0x400) == 0) {
    if ((uVar27 & 0x800) != 0) {
      iVar11 = FUN_0000b4f0(iStack00000018,param_2,*(undefined4 *)(puVar31 + 4));
      if (iVar11 == 0) {
        return 0;
      }
      if (*(char *)((int)puVar31 + 0x6d) != '\0') {
        uVar22 = 1 << (*(uint *)(&DAT_001d9f48 + (uint)*(byte *)(param_2 + 0xe) * 0x24) & 7);
        *(short *)((int)param_2 + 0x3e) =
             (short)((uVar22 * ((uint)puVar31[0x52] + (uint)*(byte *)(puVar31 + 0x55) * -2) + 0x1f &
                     0xffffffe0) / uVar22);
      }
      goto LAB_00032600;
    }
    if ((uVar27 & 0x2000) != 0) {
      iVar11 = ((int (*)())FUN_00031940)(iStack00000018,param_2);
      if (iVar11 == 0) {
        return 0;
      }
      goto LAB_00032600;
    }
    uVar19 = 0x1a2114;
    uVar16 = extraout_r4;
    if ((((((*(float *)(param_2[0xc] + 4) == 0.0) ||
           (sVar5 = *(short *)(param_2[0xc] + 0x1a), sVar5 == -0x7a41)) || (sVar5 == -0x7a42)) &&
         ((*(char *)(puVar31 + 0x36) == '\x01' && (*(char *)(puVar31 + 0x35) == '\x01')))) &&
        (bVar39)) && (*(int *)(puVar31 + uVar22 * 0xc + 0x5a) != 0)) {
      iVar11 = FUN_0000a3f0((uint)puVar31[uVar22 * 0xc + 0x58],(uint)puVar31[uVar22 * 0xc + 0x59]);
      uVar27 = puVar31[uVar22 * 0xc + 0x56];
      uVar28 = iVar11 * (int)(uint)uVar27;
      uVar32 = *(int *)(puVar31 + uVar22 * 0xc + 0x5a) +
               iVar11 * (uint)*(byte *)(puVar31 + uVar22 * 0xc + 0x55);
      if (*(char *)(puVar31 + 0x37) != '\0') {
        uVar32 = uVar32 + uVar28 * *(byte *)(puVar31 + uVar22 * 0xc + 0x55);
      }
      bVar4 = *(byte *)(param_2 + 0xe);
      bVar42 = ((uVar32 & 0x1f) != 0) << 2 | ((uVar32 & 0x1f) == 0) << 1;
      bVar41 = bVar42 | in_xer_so & 1;
      param_3 = (uint)bVar4;
      uVar44 = ((int (*)())FUN_0002f4d0)((uint)puVar31[uVar22 * 0xc + 0x58],(uint)puVar31[uVar22 * 0xc + 0x59],
                            param_3);
      uVar16 = (undefined4)uVar44;
      iVar25 = param_2[0xc];
      if (*(short *)(iVar25 + 0x1a) == -0x7a41) {
        bVar39 = (undefined *)(uint)uVar27 < ((unsigned char *)0x00004001);
      }
      else {
        bVar39 = uVar28 <= *(uint *)(iStack00000018 + 0x29d8);
      }
      if (((uint)bVar39 &
          (uint)((uVar28 & 0x1f) == 0) & bVar42 >> 1 & 1 & (uint)((ulonglong)uVar44 >> 0x20)) == 0)
      goto LAB_00034128;
      bVar41 = *(byte *)(iVar25 + 0x5e);
      uVar30 = (uint)bVar41;
      local_1a4 = 0;
      puVar17 = &local_218;
      puVar26 = &local_214;
      ((int (*)())FUN_00031170)((uint)bVar4,param_2,aiStack_1c8,puVar17,&local_208,&local_208,&local_210,puVar26,
                   &local_20c);
      iVar33 = (uint)puVar31[uVar22 * 0xc + 0x52] +
               (uint)*(byte *)(puVar31 + uVar22 * 0xc + 0x55) * -2;
      if (iVar33 < 1) {
        iVar33 = 1;
      }
      uVar22 = (uint)puVar31[uVar22 * 0xc + 0x53] -
               (uint)*(byte *)(puVar31 + uVar22 * 0xc + 0x55) * (uint)*(byte *)(iVar25 + 0x6e);
      if ((int)uVar22 < 1) {
        uVar22 = 1;
      }
      uVar23 = *(uint *)(iStack00000018 + 0x24);
      uVar20 = uVar23 & 0x82;
      iVar25 = uVar28 * (uVar22 - 1) + iVar11 * (iVar33 + 1U & 0xfffffffe);
      if (uVar20 == 0) {
        iVar29 = param_2[0xc];
      }
      else {
        iVar29 = param_2[0xc];
        if (((*(uint *)(iVar29 + 0x48) & 0x40) == 0) && (uVar22 != 0)) {
          uVar36 = 0;
          uVar16 = 0;
          uVar8 = uVar32;
          do {
            uVar36 = uVar36 + 1;
            FUN_0000b620(iStack00000018,uVar8,iVar11 * iVar33,puVar17,uVar20,uVar16,uVar23,puVar26);
            uVar8 = uVar8 + uVar28;
          } while (uVar36 < uVar22);
          iVar29 = param_2[0xc];
        }
      }
      uVar23 = *(uint *)(iVar29 + 0x50);
      uVar20 = uVar32;
      if ((uVar23 <= uVar32) && (uVar8 = uVar23 + *(int *)(iVar29 + 0x4c), uVar32 + iVar25 <= uVar8)
         ) {
        iVar25 = uVar8 - uVar23;
        uVar20 = uVar23;
      }
      if ((*(short *)(iVar29 + 0x1a) == -0x7a41) &&
         ((*(char *)(iVar29 + 0x6d) != '\0' || (iVar33 * iVar11 == uVar28)))) {
        *(short *)((int)param_2 + 0x3e) = (short)(uVar28 >> (local_218 & 0x3f));
        iVar11 = FUN_0000b150(iStack00000018,param_2,uVar32,uVar20,iVar25);
        if (iVar11 == 0) {
          return 0;
        }
        uVar27 = (ushort)(-2 << (uVar30 & 0x1f)) | (ushort)(0xfffffffe >> 0x20 - (uVar30 & 0x1f));
        *(byte *)(param_2[0xd] + 0x15) = (byte)local_20c & 3;
      }
      else {
        uVar23 = (iVar33 << (local_218 & 0x3f)) + 0x1fU & 0xffffffe0;
        *(short *)((int)param_2 + 0x3e) = (short)(uVar23 >> (local_218 & 0x3f));
        if ((*(byte *)((int)param_2 + 0x39) & 3) != 0) {
          if ((local_214 < 3) || ((iVar11 = 1, 4 < local_214 && (iVar11 = 2, local_214 != 6)))) {
            iVar11 = 0;
          }
          bVar39 = (iVar33 << (local_218 & 0x3f)) >> iVar11 < 0x2000;
          iVar25 = FUN_0000b270(iStack00000018,param_2,0x348,uVar23 * uVar22,uVar20,iVar25);
          if (iVar25 == 0) {
            return 0;
          }
          *(undefined1 *)(param_2[0xd] + 0x15) = 0;
          piVar34 = (int *)*param_2;
          uVar8 = piVar34[8];
          piVar34[2] = 0;
          piVar14 = piVar34 + 0x280;
          *piVar34 = 0;
          piVar34[1] = 0x20;
          piVar34[8] = (uint)bVar39 << 0x1f | uVar8 & 0x6fffffff | 0x40000000;
          *(char *)((int)piVar34 + 0x1a) = (char)local_218;
          *(undefined2 *)(piVar34 + 6) = 1;
          *(short *)(piVar34 + 5) = (short)iVar33;
          *(short *)((int)piVar34 + 0x16) = (short)uVar22;
          piVar34[8] = (uint)bVar39 << 0x1f | uVar8 & 0x4fffffff | 0x40000000;
          piVar34[3] = uVar23;
          piVar34[4] = uVar28;
          *(char *)((int)piVar34 + 0x1b) = (char)local_20c;
          iVar25 = (uint)*(byte *)(param_2 + 0xe) * 0x24;
          puVar37 = &DAT_001d9f34 + iVar25;
          if ((*(uint *)(&DAT_001d9f4c + iVar25) & 0x10000) == 0) {
            if ((*(uint *)(&DAT_001d9f48 + iVar25) & 8) == 0) {
              uVar8 = *(uint *)(&DAT_001d9f48 + iVar25) & 7;
              if (uVar8 == 1) {
                puVar37 = &DAT_001da00c;
              }
              else if (uVar8 < 2) {
                if (uVar8 == 0) {
                  puVar37 = &DAT_001d9fa0;
                }
                else {
LAB_00032a20:
                  puVar37 = &DAT_001da1bc;
                }
              }
              else {
                if (uVar8 == 2) goto LAB_00032b08;
                if (uVar8 != 3) goto LAB_00032a20;
                puVar37 = &DAT_001da36c;
              }
            }
            else {
LAB_00032b08:
              puVar37 = &DAT_001da054;
            }
          }
          _memcpy(piVar34 + 0x2a0,PTR_DAT_001e899c,0x23c);
          uVar9 = piVar34[0x306];
          uVar10 = piVar34[0x31c];
          piVar34[0x2ab] = 0;
          uVar8 = *(uint *)(puVar37 + 0x18) >> 5 & 0x1f;
          piVar34[0x306] = uVar8 | uVar9 & 0xffffffe0;
          uVar36 = (*(uint *)(puVar37 + 0x18) & 0x18) << 5;
          piVar34[0x306] = uVar36 | uVar8 | uVar9 & 0xfffffce0;
          uVar15 = (*(uint *)(puVar37 + 0x18) & 6) << 9;
          piVar34[0x306] = uVar15 | uVar36 | uVar8 | uVar9 & 0xfffff0e0;
          uVar7 = *(uint *)(puVar37 + 0x1c) >> 0x12 & 0x3000;
          piVar34[0x306] = uVar7 | uVar15 | uVar36 | uVar8 | uVar9 & 0xffffc0e0;
          piVar34[0x306] =
               *(uint *)(puVar37 + 0x1c) >> 0xe & 0xc000 |
               uVar7 | uVar15 | uVar36 | uVar8 | uVar9 & 0xfff000e0;
          uVar8 = *(uint *)(puVar37 + 0x1c) >> 7 & 0x1f;
          piVar34[0x31c] = uVar8 | uVar10 & 0xfffffe00;
          uVar36 = (*(uint *)(puVar37 + 0x1c) & 0x70) << 5;
          piVar34[0x31c] = uVar36 | uVar8 | uVar10 & 0xfffff000;
          uVar15 = (*(uint *)(puVar37 + 0x1c) & 0xe) << 0xb;
          piVar34[0x31c] = uVar15 | uVar36 | uVar8 | uVar10 & 0xffff8000;
          uVar7 = *(uint *)(puVar37 + 0x20) >> 0xe & 0x38000;
          piVar34[0x31c] = uVar7 | uVar15 | uVar36 | uVar8 | uVar10 & 0xfffc0000;
          piVar34[0x31c] =
               *(uint *)(puVar37 + 0x20) >> 8 & 0x1c0000 |
               uVar7 | uVar15 | uVar36 | uVar8 | uVar10 & 0xf8000000;
          piVar13 = piVar14;
          if (bVar39) {
            *piVar14 = (int)((unsigned char *)0x00001393U);
            piVar34[0x281] = 10;
            piVar34[0x282] = 0x5c8;
            piVar34[0x283] = 0x20000;
            piVar34[0x284] = 0x575;
            piVar13 = piVar34 + 0x286;
            piVar34[0x285] = local_20c;
          }
          *(short *)(piVar34 + uVar30 * 8 + 0x10) = (short)((int)piVar13 - (int)piVar14 >> 2);
          iVar25 = piVar34[1];
          *(undefined2 *)((int)piVar34 + uVar30 * 0x20 + 0x42) = 1;
          piVar34[uVar30 * 8 + 0x17] = 0;
          piVar34[uVar30 * 8 + 0x11] = uVar32 - (uVar20 & 0xfffff000);
          piVar34[uVar30 * 8 + 0x12] = 0;
          piVar34[uVar30 * 8 + 0x13] = 0;
          piVar34[uVar30 * 8 + 0x14] = 0;
          piVar34[uVar30 * 8 + 0x15] = 0;
          *(short *)(piVar34 + uVar30 * 8 + 0x16) =
               (short)((int)(piVar34 + 0x32f) - (int)piVar14 >> 2) - (short)iVar25;
          iVar25 = (uint)*(byte *)(param_2 + 0xe) * 0x24;
          puVar37 = &DAT_001d9f34 + iVar25;
          if ((*(uint *)(&DAT_001d9f4c + iVar25) & 0x10000) == 0) {
            if ((*(uint *)(&DAT_001d9f48 + iVar25) & 8) == 0) {
              uVar32 = *(uint *)(&DAT_001d9f48 + iVar25) & 7;
              if (uVar32 == 1) {
                puVar37 = &DAT_001da00c;
              }
              else if (uVar32 < 2) {
                if (uVar32 == 0) {
                  puVar37 = &DAT_001d9fa0;
                }
                else {
LAB_00032bf4:
                  puVar37 = &DAT_001da1bc;
                }
              }
              else {
                if (uVar32 == 2) goto LAB_00032c54;
                if (uVar32 != 3) goto LAB_00032bf4;
                puVar37 = &DAT_001da36c;
              }
            }
            else {
LAB_00032c54:
              puVar37 = &DAT_001da054;
            }
          }
          puVar12 = (undefined4 *)
                    ((int (*)())FUN_00030420)(piVar34 + 0x32f,puVar37,uVar28,uVar23,0,
                                 (iVar33 << (local_218 & 0x3f)) >> (*(uint *)(puVar37 + 0x14) & 7),
                                 uVar22);
          if (bVar39) {
            piVar13 = (int *)((int (*)())FUN_00030a60)(piVar13,local_214,uVar28,uVar23,0,0,
                                          uVar22 << 0x10 | (iVar33 << (local_218 & 0x3f)) >> iVar11)
            ;
          }
          *puVar12 = ((unsigned char *)0x00001393U);
          puVar12[1] = 10;
          puVar12[2] = 0x5c8;
          puVar12[3] = 0x20000;
          puVar12[4] = ((unsigned char *)0x00001040U);
          puVar12[5] = 0;
          if (bVar39) {
            *piVar13 = 0xd0b;
            piVar13[1] = 5;
            piVar13[2] = 0x5c8;
            piVar13[3] = 0x10000;
            piVar24 = piVar13 + 5;
            piVar13[4] = (int)((unsigned char *)0x00001040U);
            piVar13 = piVar13 + 6;
            *piVar24 = 0;
          }
          *(uint *)(param_2[0xd] + 0x18) = uVar23 * uVar22;
          *(byte *)(param_2[0xd] + 0x14) = *(byte *)(param_2[0xd] + 0x14) | 2;
          *piVar34 = (int)piVar13 - (int)piVar14 >> 2;
          piVar34[2] = ((int)puVar12 + (0x18 - (int)piVar14) >> 2) - piVar34[1];
        }
        uVar6 = (ushort)(1 << (uVar30 & 0x3f));
        uVar27 = ~uVar6;
        *(byte *)(param_2[0xd] + 0x14) = *(byte *)(param_2[0xd] + 0x14) | 1;
        *(ushort *)(param_2[0xd] + 0x1c) = uVar6 | *(ushort *)(param_2[0xd] + 0x1c);
        *(ushort *)(param_2[0xd] + 0x28) = uVar27 & *(ushort *)(param_2[0xd] + 0x28);
        *(byte *)(param_2[0xd] + 0x17) = bVar41;
        *(undefined1 *)(param_2[0xd] + 0x34) = 1;
        *(undefined1 *)(param_2[0xd] + 0x35) = 1;
      }
      *(byte *)((int)param_2 + 0x39) = *(byte *)((int)param_2 + 0x39) & 0xf8;
      *(ushort *)(param_2 + 9) = uVar27 & *(ushort *)(param_2 + 9);
    }
    else {
LAB_00034128:
      if (*(char *)((int)puVar31 + 0x6d) == '\0') {
        iVar11 = ((int (*)())FUN_00030b50)(param_2,uVar16,param_3,param_4,uVar19,param_6);
        if (iVar11 == 0) {
          local_74 = param_2[0xc];
          local_78 = (uint)*(byte *)(local_74 + 0x6c);
          local_7c = (uint)*(byte *)(local_74 + 0x69);
          local_80 = (uint)*(byte *)(local_74 + 0x6b);
          uVar27 = *(ushort *)(local_74 + 2);
          local_134 = 0;
          if (0x1908 < uVar27) {
            local_134 = 0;
            if (0x190a < uVar27) {
              local_134 = 0;
              if (uVar27 != 0x8049) goto LAB_00032e78;
              local_134 = 0x4000;
            }
            local_134 = local_134 | 0x2000;
          }
LAB_00032e78:
          local_64 = &local_158;
          local_138 = 2;
          ((int (*)())FUN_00031170)((uint)*(byte *)(param_2 + 0xe),param_2,local_64,&local_214,&local_208,
                       &local_204,&local_218,&local_210,&local_20c);
          iVar11 = (uint)*(byte *)(param_2 + 0xe) * 0x24;
          puVar37 = &DAT_001d9f34 + iVar11;
          uVar22 = *(uint *)(&DAT_001d9f48 + iVar11) & 7;
          if (uVar22 == 4) {
            iVar25 = 0;
            bVar39 = false;
            local_a4 = 0;
            local_c0 = 5;
            local_60 = (uint)(in_xer_so & 1 | 2) << 0x1c | (uint)(in_cr1 & 0xf) << 0x18 |
                       (uint)(unaff_cr2 & 0xf) << 0x14 | (uint)(unaff_cr3 & 0xf) << 0x10 |
                       (uint)(unaff_cr4 & 0xf) << 0xc | (uint)(in_cr5 & 0xf) << 8 |
                       (uint)(bVar41 & 0xf) << 4 |
                       (uint)(byte)((uVar22 < 4) << 3 | (4 < uVar22) << 2 | (uVar22 == 4) << 1 |
                                   in_xer_so & 1);
LAB_00032f74:
            iVar11 = 0;
          }
          else {
            local_a4 = *(uint *)(&DAT_001d9f4c + iVar11) >> 0x1c & 3;
            bVar42 = (local_a4 != 0) << 2 | (local_a4 == 0) << 1 | in_xer_so & 1;
            bVar39 = local_a4 != 0;
            if (bVar39) {
              local_c0 = 5 - local_a4;
              local_60 = (uint)(in_xer_so & 1 | 4) << 0x1c | (uint)(in_cr1 & 0xf) << 0x18 |
                         (uint)(unaff_cr2 & 0xf) << 0x14 | (uint)(unaff_cr3 & 0xf) << 0x10 |
                         (uint)(unaff_cr4 & 0xf) << 0xc | (uint)(in_cr5 & 0xf) << 8 |
                         (uint)(bVar41 & 0xf) << 4 | (uint)bVar42;
            }
            else {
              local_c0 = 5;
              local_60 = (uint)(in_xer_so & 1 | 4) << 0x1c | (uint)(in_cr1 & 0xf) << 0x18 |
                         (uint)(unaff_cr2 & 0xf) << 0x14 | (uint)(unaff_cr3 & 0xf) << 0x10 |
                         (uint)(unaff_cr4 & 0xf) << 0xc | (uint)(in_cr5 & 0xf) << 8 |
                         (uint)(bVar41 & 0xf) << 4 | (uint)bVar42;
            }
            iVar25 = 1;
            bVar39 = !bVar39;
            if (((*(uint *)(&DAT_001d9f4c + iVar11) & 0x30000000) != 0x20000000) ||
               (iVar11 = 1, uVar22 != 1)) goto LAB_00032f74;
          }
          uVar28 = *(byte *)(local_74 + 0x62) - local_7c;
          uVar22 = uVar28;
          if ((int)uVar28 < 0) {
            uVar22 = 0;
          }
          iVar33 = *(byte *)(local_74 + 0x60) - local_7c;
          if (iVar33 < 0) {
            iVar33 = 0;
          }
          uVar32 = iVar33 - local_208;
          if ((int)uVar32 < 0) {
            uVar32 = 0;
          }
          iVar33 = *(byte *)(local_74 + 0x61) - local_7c;
          if (iVar33 < 0) {
            iVar33 = 0;
          }
          uVar30 = iVar33 - local_204;
          if ((int)uVar30 < 0) {
            uVar30 = 0;
          }
          bVar42 = (local_80 < local_7c) << 3 | (local_7c < local_80) << 2 |
                   (local_80 == local_7c) << 1 | in_xer_so & 1;
          bVar40 = (uint)((1 << (uVar32 & 0x3f)) << (local_214 & 0x3f)) <=
                   *(uint *)(iStack00000018 + 0x29d8);
          uVar20 = local_7c;
          local_a0 = uVar22;
          local_9c = uVar30;
          local_98 = uVar32;
          if (local_80 < local_7c) {
            iVar29 = 0;
            iVar35 = 0;
            iVar21 = 0;
            iVar33 = 0;
            local_88 = 0;
          }
          else {
            iVar29 = 0;
            iVar35 = 0;
            iVar33 = local_a4 + 3;
            uVar23 = local_c0 + 3;
            piVar14 = aiStack_1c8 + local_7c;
            piVar34 = aiStack_200 + local_7c;
            local_88 = 0;
            do {
              uVar36 = local_214 + uVar32;
              *piVar34 = iVar35;
              *piVar14 = iVar29;
              iVar21 = 1 << (uVar22 & 0x3f);
              uVar8 = uVar36;
              if ((int)uVar36 < 5) {
                uVar8 = 5;
              }
              iVar35 = iVar35 + iVar21 * (1 << (uVar8 & 0x3f)) * (1 << (uVar30 & 0x3f));
              uVar8 = local_c0;
              if ((int)local_c0 < (int)uVar36) {
                uVar8 = uVar36;
              }
              uVar36 = 1 << (uVar8 & 0x3f);
              uVar8 = uVar30;
              if ((int)uVar30 < (int)local_a4) {
                uVar8 = local_a4;
              }
              uVar8 = 1 << (uVar8 & 0x3f);
              iVar29 = iVar29 + iVar21 * uVar36 * uVar8;
              if ((uVar36 < (uint)(1 << (uVar23 & 0x3f))) || (uVar8 < (uint)(1 << iVar33))) {
                local_88 = local_88 & ~(1 << (uVar20 & 0x3f));
              }
              else {
                local_88 = local_88 | 1 << (uVar20 & 0x3f);
              }
              if (0 < (int)uVar32) {
                uVar32 = uVar32 - 1;
              }
              if (0 < (int)uVar30) {
                uVar30 = uVar30 - 1;
              }
              if (0 < (int)uVar22) {
                uVar22 = uVar22 - 1;
              }
              uVar20 = uVar20 + 1;
              piVar34 = piVar34 + 1;
              piVar14 = piVar14 + 1;
              bVar42 = (local_80 < uVar20) << 3 | (uVar20 < local_80) << 2 |
                       (local_80 == uVar20) << 1 | in_xer_so & 1;
            } while (local_80 >= uVar20);
            iVar21 = local_78 * iVar35;
            iVar33 = local_78 * iVar29;
          }
          uVar22 = 0;
          local_6c = (uint)(byte)(bVar40 << 2 | !bVar40 << 1 | in_xer_so & 1) << 0x1c |
                     (uint)(in_cr1 & 0xf) << 0x18 | (uint)(unaff_cr2 & 0xf) << 0x14 |
                     (uint)(unaff_cr3 & 0xf) << 0x10 | (uint)(unaff_cr4 & 0xf) << 0xc |
                     (uint)(in_cr5 & 0xf) << 8 | (uint)(bVar41 & 0xf) << 4 | (uint)bVar42;
          aiStack_1c8[uVar20] = iVar29;
          aiStack_200[uVar20] = iVar35;
          if (bVar40) {
            uVar22 = 0x15;
            if (local_7c <= local_80) {
              iVar29 = 0;
              uVar22 = uVar28;
              uVar32 = local_7c;
              do {
                uVar30 = uVar22;
                if ((int)uVar22 < 0) {
                  uVar30 = 0;
                }
                uVar32 = uVar32 + 1;
                uVar22 = uVar22 - 1;
                iVar29 = iVar29 + (local_78 * 0x12 << (uVar30 & 0x3f));
              } while (uVar32 <= local_80);
              uVar22 = iVar29 + 0x15;
            }
            uVar22 = uVar22 & 0xfffffff8;
          }
          uVar32 = 0x98;
          if (local_7c <= local_80) {
            iVar29 = 0x91;
            uVar32 = local_7c;
            do {
              uVar30 = uVar28;
              if ((int)uVar28 < 0) {
                uVar30 = 0;
              }
              uVar32 = uVar32 + 1;
              uVar28 = uVar28 - 1;
              iVar29 = iVar29 + (local_78 * 0x2a << (uVar30 & 0x3f));
            } while (uVar32 <= local_80);
            uVar32 = iVar29 + 7;
          }
          iVar33 = FUN_0000acb0(iStack00000018,param_2,
                                iVar21 + uVar22 * 4 + (uVar32 & 0xfffffff8) * 4,iVar33);
          if (iVar33 == 0) {
            return 0;
          }
          *(byte *)(param_2[0xd] + 0x15) = (byte)((iVar25 << iVar11) << 3) & 0x18 | 4;
          local_84 = (int *)*param_2;
          if ((*(byte *)((int)param_2 + 0x39) & 3) == 0) {
            local_8c = (int *)0x0;
            local_e8 = (int *)0x0;
          }
          else {
            *(char *)(param_2[0xd] + 0x17) = (char)local_7c;
            uVar30 = 1 << (local_98 & 0x3f);
            *(char *)(param_2[0xd] + 0x34) = (char)local_78;
            *(char *)(param_2[0xd] + 0x35) = ((char)local_80 - (char)local_7c) + '\x01';
            uVar28 = local_84[8];
            local_84[2] = 0;
            local_84[1] = uVar22;
            *local_84 = 0;
            local_84[8] = (uint)bVar40 << 0x1f | uVar28 & 0x6fffffff | 0x40000000;
            *(char *)((int)local_84 + 0x1a) = (char)local_214;
            *(short *)((int)local_84 + 0x16) = (short)(1 << (local_9c & 0x3f));
            *(short *)(local_84 + 6) = (short)(1 << (local_a0 & 0x3f));
            *(short *)(local_84 + 5) = (short)uVar30;
            *(char *)((int)local_84 + 0x1b) = (char)local_20c;
            uVar30 = (uVar30 & 0xffff) << (local_214 & 0x3f);
            local_84[3] = uVar30;
            if (uVar30 >> (local_c0 & 0x3f) == 0) {
              local_84[3] = 1 << (local_c0 & 0x3f);
            }
            uVar30 = (uint)*(ushort *)(local_84 + 5) << (local_214 & 0x3f);
            local_84[4] = uVar30;
            if (uVar30 >> 5 == 0) {
              local_84[4] = 0x20;
            }
            puVar37 = PTR_DAT_001e899c;
            local_84[8] = (uint)bVar40 << 0x1f | uVar28 & 0x4fffffff | 0x40000000;
            local_8c = local_84 + 0x280;
            piVar14 = local_8c + local_84[1];
            local_e8 = piVar14 + 0x8f;
            _memcpy(piVar14,puVar37,0x23c);
            iVar25 = (uint)*(byte *)(param_2 + 0xe) * 0x24;
            puVar37 = &DAT_001d9f34 + iVar25;
            if ((*(uint *)(&DAT_001d9f4c + iVar25) & 0x10000) == 0) {
              if ((*(uint *)(&DAT_001d9f48 + iVar25) & 8) == 0) {
                uVar28 = *(uint *)(&DAT_001d9f48 + iVar25) & 7;
                if (uVar28 == 1) {
                  puVar37 = &DAT_001da00c;
                }
                else if (uVar28 < 2) {
                  if (uVar28 == 0) {
                    puVar37 = &DAT_001d9fa0;
                  }
                  else {
LAB_000333f4:
                    puVar37 = &DAT_001da1bc;
                  }
                }
                else {
                  if (uVar28 == 2) goto LAB_000334dc;
                  if (uVar28 != 3) goto LAB_000333f4;
                  puVar37 = &DAT_001da36c;
                }
              }
              else {
LAB_000334dc:
                puVar37 = &DAT_001da054;
              }
            }
            uVar8 = piVar14[0x66];
            uVar36 = piVar14[0x7c];
            piVar14[0xb] = 0;
            uVar28 = *(uint *)(puVar37 + 0x18) >> 5 & 0x1f;
            piVar14[0x66] = uVar28 | uVar8 & 0xffffffe0;
            uVar30 = (*(uint *)(puVar37 + 0x18) & 0x18) << 5;
            piVar14[0x66] = uVar30 | uVar28 | uVar8 & 0xfffffce0;
            uVar20 = (*(uint *)(puVar37 + 0x18) & 6) << 9;
            piVar14[0x66] = uVar20 | uVar30 | uVar28 | uVar8 & 0xfffff0e0;
            uVar23 = *(uint *)(puVar37 + 0x1c) >> 0x12 & 0x3000;
            piVar14[0x66] = uVar23 | uVar20 | uVar30 | uVar28 | uVar8 & 0xffffc0e0;
            piVar14[0x66] =
                 *(uint *)(puVar37 + 0x1c) >> 0xe & 0xc000 |
                 uVar23 | uVar20 | uVar30 | uVar28 | uVar8 & 0xfff000e0;
            uVar28 = *(uint *)(puVar37 + 0x1c) >> 7 & 0x1f;
            piVar14[0x7c] = uVar28 | uVar36 & 0xfffffe00;
            uVar30 = (*(uint *)(puVar37 + 0x1c) & 0x70) << 5;
            piVar14[0x7c] = uVar30 | uVar28 | uVar36 & 0xfffff000;
            uVar20 = (*(uint *)(puVar37 + 0x1c) & 0xe) << 0xb;
            piVar14[0x7c] = uVar20 | uVar30 | uVar28 | uVar36 & 0xffff8000;
            uVar23 = *(uint *)(puVar37 + 0x20) >> 0xe & 0x38000;
            piVar14[0x7c] = uVar23 | uVar20 | uVar30 | uVar28 | uVar36 & 0xfffc0000;
            uVar8 = *(uint *)(puVar37 + 0x20) >> 8 & 0x1c0000;
            piVar14[0x7c] = uVar8 | uVar23 | uVar20 | uVar30 | uVar28 | uVar36 & 0xffc00000;
            piVar14[0x7c] =
                 (*(uint *)(puVar37 + 0x20) >> 0x19 & 1) << 0x16 |
                 uVar8 | uVar23 | uVar20 | uVar30 | uVar28 | uVar36 & 0xf8000000;
            if (!(bool)((byte)(local_6c >> 0x1d) & 1)) {
              *local_8c = (int)((unsigned char *)0x00001393U);
              local_8c[1] = 10;
              local_8c[2] = 0x5c8;
              piVar14 = local_8c + 5;
              local_8c[3] = 0x20000;
              local_8c[4] = 0x575;
              local_8c = local_8c + 6;
              *piVar14 = local_20c;
            }
          }
          bVar42 = ((int)local_78 < 0) << 3 | (0 < (int)local_78) << 2 | (local_78 == 0) << 1 |
                   in_xer_so & 1;
          if (local_78 != 0) {
            local_90 = 0;
            local_dc = param_2;
            local_58 = iVar11 << 1;
            local_94 = 0;
            local_e4 = local_7c * 0x18;
            local_54 = (uint)(byte)(bVar39 << 2 | !bVar39 << 1 | in_xer_so & 1) << 0x1c |
                       (uint)(in_cr1 & 0xf) << 0x18 | (uint)(unaff_cr2 & 0xf) << 0x14 |
                       (uint)(unaff_cr3 & 0xf) << 0x10 | (uint)(unaff_cr4 & 0xf) << 0xc |
                       (uint)(in_cr5 & 0xf) << 8 | (uint)(bVar41 & 0xf) << 4 | (uint)bVar42;
            local_c4 = (uVar22 + (uVar32 & 0xfffffff8)) * 4;
            local_e0 = local_7c << 5;
            local_68 = (uint)(in_xer_so & 1 | 2) << 0x1c | (uint)(in_cr1 & 0xf) << 0x18 |
                       (uint)(unaff_cr2 & 0xf) << 0x14 | (uint)(unaff_cr3 & 0xf) << 0x10 |
                       (uint)(unaff_cr4 & 0xf) << 0xc | (uint)(in_cr5 & 0xf) << 8 |
                       (uint)(bVar41 & 0xf) << 4 | (uint)bVar42;
            local_5c = local_84 + 0x10;
            local_d8 = local_74;
            do {
              local_a8 = (uint)*(ushort *)(local_d8 + 0x7c);
              if (local_7c <= local_80) {
                piVar14 = aiStack_200 + local_7c;
                local_c8 = local_e0;
                local_d0 = local_e0;
                local_d4 = aiStack_1c8 + local_7c;
                local_70 = 0x80e1;
                local_cc = local_e4;
                uVar22 = local_98;
                uVar28 = local_a0;
                uVar32 = local_9c;
                uVar30 = local_7c;
                do {
                  uVar23 = uVar22 + local_214;
                  uVar20 = uVar23;
                  if ((int)uVar23 < 5) {
                    uVar20 = 5;
                  }
                  iVar11 = 1 << (uVar20 & 0x3f);
                  local_b0 = 1;
                  bVar39 = 3 < *(byte *)(param_2 + 0xe) - 0xc;
                  local_ac = *piVar14 * local_78 + local_94 * (piVar14[1] - *piVar14) + local_c4 +
                             0xa00;
                  if (bVar39) {
                    local_b0 = 0;
                  }
                  local_b0 = (uint)!bVar39;
                  if ((*(byte *)((int)param_2 + 0x39) & 3) == 0) {
                    bVar42 = ((int)uVar28 < 0) << 3 | (0 < (int)uVar28) << 2 | (uVar28 == 0) << 1 |
                             in_xer_so & 1;
                    local_a8 = local_a8 & *(ushort *)(local_dc + 9);
                  }
                  else {
                    bVar42 = ((int)uVar28 < 0) << 3 | (0 < (int)uVar28) << 2 | (uVar28 == 0) << 1 |
                             in_xer_so & 1;
                    uVar8 = uVar28;
                    uVar20 = uVar32;
                    if ((((uVar32 != local_a4 + 3) && (local_a4 <= uVar32)) &&
                        (bVar42 = ((int)uVar28 < 0) << 3 | (0 < (int)uVar28) << 2 |
                                  (uVar28 == 0) << 1 | in_xer_so & 1, uVar28 != 0)) &&
                       (uVar36 = uVar28, uVar32 < 0xb)) {
                      do {
                        uVar8 = uVar8 - 1;
                        uVar20 = uVar20 + 1;
                        if (uVar36 - 1 == 0) goto LAB_00033700;
                        uVar36 = uVar36 - 1;
                      } while (uVar20 != 0xb);
                      uVar20 = 0xb;
                    }
LAB_00033700:
                    if ((int)uVar23 < (int)local_c0) {
                      uVar23 = local_c0;
                    }
                    iVar29 = 1 << (uVar23 & 0x3f);
                    *(short *)(local_d0 + (int)local_5c) =
                         (short)((int)local_8c - (int)(local_84 + 0x280) >> 2);
                    iVar25 = local_84[1];
                    *(int *)((int)local_5c + local_d0 + 4) = local_ac;
                    *(short *)((int)local_5c + local_d0 + 0x18) =
                         (short)((int)local_e8 - (int)(local_84 + 0x280) >> 2) - (short)iVar25;
                    iVar33 = *local_d4;
                    iVar25 = local_d4[1];
                    *(short *)((int)local_5c + local_d0 + 2) = (short)(1 << (uVar8 & 0x3f));
                    *(int *)((int)local_5c + local_d0 + 0xc) = iVar11 << (uVar20 & 0x3f);
                    *(uint *)((int)local_5c + local_d0 + 8) =
                         local_78 * iVar33 + local_94 * (iVar25 - iVar33);
                    uVar23 = uVar20;
                    if ((int)uVar20 < (int)local_a4) {
                      uVar23 = local_a4;
                    }
                    *(int *)((int)local_5c + local_d0 + 0x10) = (1 << (uVar23 & 0x3f)) * iVar29;
                    uVar23 = uVar32;
                    if ((int)uVar32 < (int)local_a4) {
                      uVar23 = local_a4;
                    }
                    *(int *)((int)local_5c + local_d0 + 0x14) = iVar29 << (uVar23 & 0x3f);
                    *(int *)((int)local_5c + local_d0 + 0x1c) = (int)local_84 + local_ac;
                    if ((local_210 < 3) ||
                       ((iVar25 = 1, 4 < local_210 && (iVar25 = 2, local_210 != 6)))) {
                      iVar25 = 0;
                    }
                    uVar23 = 1 << (uVar8 & 0x3f);
                    if (uVar23 != 0) {
                      iVar33 = 1 << (uVar20 & 0x3f);
                      iVar35 = 1 << (uVar22 & 0x3f);
                      uVar8 = 0;
                      uVar20 = local_88 >> (uVar30 & 0x3f);
                      do {
                        if (((bool)((byte)(local_60 >> 0x1d) & 1)) ||
                           (!(bool)((byte)(local_54 >> 0x1d) & 1))) {
                          uVar36 = 0;
                        }
                        else {
                          uVar36 = 1;
                        }
                        uVar36 = (uVar36 | local_58) << 1 | uVar20 & 1;
                        local_e8 = (int *)((int (*)())FUN_00030420)(local_e8,puVar37,iVar11,iVar29,uVar36,
                                                       (iVar35 << (local_214 & 0x3f)) >>
                                                       (*(uint *)(puVar37 + 0x14) & 7),iVar33);
                        if (!(bool)((byte)(local_6c >> 0x1d) & 1)) {
                          local_8c = (int *)((int (*)())FUN_00030a60)(local_8c,local_210,iVar11,iVar29,uVar36,0,
                                                         iVar33 << 0x10 |
                                                         (iVar35 << (local_214 & 0x3f)) >> iVar25);
                        }
                        uVar8 = uVar8 + 1;
                      } while (uVar8 < uVar23);
                    }
                  }
                  if ((local_a8 >> (uVar30 & 0x3f) & 1) != 0) {
                    iVar33 = local_cc + local_74 + 0xa0;
                    uVar20 = (uint)*(ushort *)(iVar33 + 0x12);
                    iVar25 = FUN_0000a3f0((uint)*(ushort *)(iVar33 + 0x10),uVar20);
                    uVar23 = (uint)*(ushort *)(iVar33 + 0xc);
                    bVar39 = uVar20 != 0;
                    bVar4 = in_xer_so & 1;
                    local_158 = *(uint *)(iVar33 + 0x14);
                    uVar8 = iVar25 * uVar23;
                    if ((*(char *)(iVar33 + 10) != '\0') && (bVar39)) {
                      iVar29 = 1;
                      if ((*(char *)(local_74 + 0x6e) != '\0') &&
                         (iVar29 = uVar23 + 1, *(char *)(local_74 + 0x6f) != '\0')) {
                        iVar29 = iVar29 + uVar23 * *(ushort *)(iVar33 + 0xe);
                      }
                      local_158 = local_158 + iVar25 * iVar29;
                    }
                    uVar23 = *(byte *)(local_74 + 0x60) - uVar30;
                    if ((int)uVar23 < 0) {
                      uVar23 = 0;
                    }
                    local_12c = 1 << (uVar23 & 0x3f);
                    iVar25 = *(byte *)(local_74 + 0x61) - uVar30;
                    if (iVar25 < 0) {
                      iVar25 = 0;
                    }
                    iVar29 = *(byte *)(local_74 + 0x62) - uVar30;
                    if (iVar29 < 0) {
                      iVar29 = 0;
                    }
                    local_128 = 1 << (iVar25 + iVar29 & 0x3fU);
                    puVar18 = auStack_14c;
                    bVar40 = (int)local_b0 < 0;
                    bVar1 = 0 < (int)local_b0;
                    bVar2 = local_b0 == 0;
                    bVar3 = in_xer_so & 1;
                    uVar23 = local_b0;
                    local_154 = uVar8;
                    _glgConvertType((uint)*(ushort *)(iVar33 + 0x10),
                                    (uint)*(ushort *)(iVar33 + 0x12),auStack_150,puVar18,local_74,
                                    local_b0,local_158,uVar8);
                    local_144 = iVar11;
                    if (!bVar2) {
                      local_144 = local_12c << 2;
                    }
                    local_148 = local_ac + *param_2;
                    local_130 = 0x7ffff;
                    uVar27 = *(short *)(iVar33 + 0x10) + 0xe6fa;
                    bVar43 = (uVar27 < 4) << 3 | (4 < uVar27) << 2 | (uVar27 == 4) << 1 |
                             in_xer_so & 1;
                    if ((4 >= uVar27) &&
                       (uVar23 = 1 << ((int)(short)uVar27 & 0x3fU) & 0x19, uVar23 != 0)) {
                      local_130 = 0x7dfff;
                    }
                    local_120 = 0;
                    local_124 = 0;
                    uVar36 = local_148;
                    if (((bVar39) && (!bVar2)) &&
                       (uVar36 = local_68, (bool)((byte)(local_68 >> 0x1d) & 1))) {
                      uVar23 = 1;
                      local_90 = _valloc(((1 << (*(byte *)(local_74 + 100) + 2 & 0x3f)) + 0x1fU &
                                         0xffffffe0) <<
                                         ((uint)*(byte *)(local_74 + 0x66) +
                                          (uint)*(byte *)(local_74 + 0x65) & 0x3f));
                      uVar36 = local_68;
                      local_68 = (uint)(byte)(((int)local_90 < 0) << 3 | (0 < (int)local_90) << 2 |
                                              (local_90 == 0) << 1 | in_xer_so & 1) << 0x1c |
                                 (uint)(in_cr1 & 0xf) << 0x18 | (uint)bVar42 << 0x14 |
                                 (uint)(byte)((uVar20 == 0) << 2 | bVar39 << 1 | bVar4) << 0x10 |
                                 (uint)(byte)(bVar40 << 3 | bVar1 << 2 | bVar2 << 1 | bVar3) << 0xc
                                 | (uint)(in_cr5 & 0xf) << 8 | (uint)(bVar41 & 0xf) << 4 |
                                 (uint)(bVar43 & 0xf);
                    }
                    uVar27 = *(ushort *)(iVar33 + 0x10);
                    uVar6 = *(ushort *)(iVar33 + 0x12);
                    uVar15 = (uint)*(byte *)(param_2 + 0xe);
                    iVar25 = 1 << (uVar28 + uVar22 + uVar32 + local_214 & 0x3f);
                    uVar20 = ((int (*)())FUN_0002f4d0)((uint)uVar27,(uint)uVar6,uVar15);
                    iVar11 = FUN_0000a3f0((uint)uVar27,(uint)uVar6);
                    uVar20 = local_154 == iVar11 * local_12c & uVar20;
                    if (((uVar20 == 0) || (uVar23 = local_158 & 0x1f, uVar23 != 0)) ||
                       (uVar36 = local_154 & 0x1f, uVar36 != 0)) {
                      if (bVar39) {
                        if (bVar2) {
                          _glgProcessPixels(0,local_64,uVar15,puVar18,uVar20,uVar23,uVar36,uVar8);
                        }
                        else {
                          uVar23 = (uint)*(ushort *)(iVar33 + 0x10);
                          local_b4 = local_148;
                          if (((local_12c != *(ushort *)(iVar33 + 0xc)) ||
                              ((*(short *)(iVar33 + 0x12) != 0x1401 &&
                               (*(short *)(iVar33 + 0x12) != -0x7fcb)))) ||
                             ((uVar15 = local_158, 1 < uVar23 - 0x1907 &&
                              ((uVar23 != local_70 && (uVar20 = local_70, uVar23 != 0x80e0)))))) {
                            local_148 = local_90;
                            _glgProcessPixels(0,local_64,uVar23,puVar18,uVar20,local_90,uVar36,uVar8
                                             );
                            uVar23 = 0x1908;
                            local_148 = local_b4;
                            uVar15 = local_90;
                          }
                          uVar20 = local_12c;
                          puVar18 = (undefined1 *)(uint)*(byte *)(param_2 + 0xe);
                          local_148 = local_b4;
                          if (puVar18 == (undefined1 *)((int)((unsigned char *)0xc) + 3)) {
                            bVar39 = uVar23 == 0x1908;
                            bVar41 = (uVar23 < 0x1908) << 3 | (0x1908 < uVar23) << 2 | bVar39 << 1 |
                                     in_xer_so & 1;
                            local_b8 = local_128;
                            if ((bVar39) || (iVar11 = 3, uVar23 == local_70)) {
                              iVar11 = 4;
                            }
                            puVar38 = (undefined1 *)(iVar11 * local_12c);
                            if ((bVar39) || (local_bc = 0, uVar23 == local_70)) {
                              local_bc = 3;
                            }
                            if (0 < (int)local_128) {
                              bVar39 = 0 < (int)local_12c;
                              iVar25 = 0;
                              do {
                                if (bVar39) {
                                  iVar33 = 0;
                                  iVar29 = local_b4 + iVar25 * uVar20;
                                  do {
                                    iVar35 = iVar11 * iVar33;
                                    iVar33 = iVar33 + 4;
                                    iVar21 = uVar15 + iVar35 + iVar25 * (int)puVar38;
                                    ((int (*)())FUN_000305b0)(iVar29,iVar21 + local_bc,iVar11,puVar38);
                                    iVar35 = iVar29 + 8;
                                    iVar29 = iVar29 + 0x10;
                                    puVar18 = puVar38;
                                    ((int (*)())FUN_000305b0)(iVar35,iVar21 + (uint)(1 < uVar23 - 0x1907) * 2,
                                                 iVar11,puVar38);
                                  } while (iVar33 < (int)uVar20);
                                }
                                iVar25 = iVar25 + 4;
                              } while (iVar25 < (int)local_b8);
                            }
                          }
                          else {
                            FUN_0001c380(local_12c,local_128,uVar23,puVar18,uVar15,local_b4);
                          }
                        }
                      }
                      else if (!bVar2) {
                        puVar18 = (undefined1 *)((int)((unsigned char *)0x0) + 1);
                        uVar20 = ((int (*)())FUN_000303d0)((uint)*(byte *)(param_2 + 0xe),local_12c,1,1);
                        if (uVar20 < 0x20) {
                          if (local_128 != 0) {
                            uVar15 = 0;
                            uVar23 = local_158;
                            uVar36 = local_148;
                            do {
                              uVar15 = uVar15 + 4;
                              uVar7 = uVar36 + 0x1f & 0xffffffe0;
                              uVar36 = uVar7 + uVar20;
                              _memcpy(uVar7,uVar23,uVar20);
                              uVar23 = uVar23 + uVar20;
                            } while (uVar15 < local_128);
                          }
                        }
                        else {
                          _memcpy(local_148,local_158,iVar25);
                        }
                      }
                    }
                    else {
                      _memcpy(local_148,local_158,iVar25);
                    }
                    uVar20 = *(uint *)(iStack00000018 + 0x24) & 0x82;
                    if (uVar20 != 0) {
                      FUN_0000b620(iStack00000018,local_ac + *param_2,
                                   (uint)*(ushort *)((int)local_5c + local_c8 + 2) *
                                   *(int *)((int)local_5c + local_c8 + 0xc),puVar18,local_c8,
                                   local_5c,uVar20,uVar8);
                    }
                  }
                  if (0 < (int)uVar22) {
                    uVar22 = uVar22 - 1;
                  }
                  if (0 < (int)uVar32) {
                    uVar32 = uVar32 - 1;
                  }
                  if ((bool)(bVar42 >> 2 & 1)) {
                    uVar28 = uVar28 - 1;
                  }
                  uVar30 = uVar30 + 1;
                  piVar14 = piVar14 + 1;
                  local_c8 = local_c8 + 0x20;
                  local_cc = local_cc + 0x18;
                  local_d0 = local_d0 + 0x20;
                  local_d4 = local_d4 + 1;
                } while (uVar30 <= local_80);
              }
              iVar11 = local_94 * 2;
              local_94 = local_94 + 1;
              uVar27 = ~(ushort)local_a8;
              iVar25 = iVar11 + param_2[0xd];
              local_d8 = local_d8 + 2;
              local_e0 = local_e0 + 0x1a0;
              local_e4 = local_e4 + 0x168;
              *(ushort *)(iVar25 + 0x1c) = (ushort)local_a8 | *(ushort *)(iVar25 + 0x1c);
              iVar11 = iVar11 + param_2[0xd];
              *(ushort *)(iVar11 + 0x28) = uVar27 & *(ushort *)(iVar11 + 0x28);
              *(ushort *)(local_dc + 9) = uVar27 & *(ushort *)(local_dc + 9);
              local_dc = (int *)((int)local_dc + 2);
            } while (local_94 < local_78);
            if (!(bool)((byte)(local_68 >> 0x1d) & 1)) {
              _free(local_90);
            }
          }
          bVar41 = *(byte *)((int)param_2 + 0x39);
          if ((bVar41 & 3) != 0) {
            *local_e8 = (int)((unsigned char *)0x00001393U);
            local_e8[1] = 10;
            local_e8[2] = 0x5c8;
            local_e8[3] = 0x20000;
            local_e8[4] = (int)((unsigned char *)0x00001040U);
            local_e8[5] = 0;
            if (!(bool)((byte)(local_6c >> 0x1d) & 1)) {
              *local_8c = 0xd0b;
              local_8c[1] = 5;
              local_8c[2] = 0x5c8;
              local_8c[3] = 0x10000;
              piVar14 = local_8c + 5;
              local_8c[4] = (int)((unsigned char *)0x00001040U);
              local_8c = local_8c + 6;
              *piVar14 = 0;
            }
            *local_84 = (int)local_8c - (int)(local_84 + 0x280) >> 2;
            local_84[2] = ((int)local_e8 + (0x18 - (int)(local_84 + 0x280)) >> 2) - local_84[1];
            bVar41 = *(byte *)((int)param_2 + 0x39);
          }
          *(byte *)((int)param_2 + 0x39) = bVar41 & 0xf8;
          goto LAB_00033ff0;
        }
        if (*(char *)(param_2 + 0x11) != '\0') {
          return 0;
        }
      }
      iVar11 = ((int (*)())FUN_00031940)(iStack00000018,param_2);
      if (iVar11 == 0) {
        return 0;
      }
    }
  }
  else {
    uVar27 = puVar31[6];
    if (uVar27 == 0x405) {
LAB_000324ac:
      uVar16 = 0;
    }
    else if (uVar27 < 0x406) {
      if (uVar27 == 0x402) goto LAB_000324ac;
      uVar16 = 2;
      if ((uVar27 != 0x403) && (uVar16 = 3, uVar27 != 0x401)) {
LAB_00032480:
        uVar16 = 1;
      }
    }
    else {
      uVar16 = 8;
      if ((uVar27 != 0x40a) && (uVar16 = 0x11, uVar27 != 0x1100)) {
        if (uVar27 != 0x409) goto LAB_00032480;
        uVar16 = 7;
      }
    }
    iVar11 = FUN_0000b3a0(iStack00000018,param_2,*(undefined4 *)(puVar31 + 4),uVar16,
                          (uint)*(byte *)(puVar31 + 0x36));
    if (iVar11 == 0) {
      return 0;
    }
    if (*(char *)((int)puVar31 + 0x6d) == '\0') {
      uVar22 = (uint)puVar31[0x52];
      if ((0x20 < uVar22) || (0x20 < puVar31[0x53])) goto LAB_00032600;
    }
    else {
      uVar22 = (uint)puVar31[0x52];
    }
    uVar28 = 1 << (*(uint *)(&DAT_001d9f48 + (uint)*(byte *)(param_2 + 0xe) * 0x24) & 7);
    *(short *)((int)param_2 + 0x3e) =
         (short)((uVar28 * (uVar22 + (uint)*(byte *)(puVar31 + 0x55) * -2) + 0xff & 0xffffff00) /
                uVar28);
LAB_00032600:
    *(byte *)((int)param_2 + 0x39) = *(byte *)((int)param_2 + 0x39) & 0xf8;
  }
LAB_00033ff0:
  if (*(char *)((int)puVar31 + 0x6d) != '\0') {
    if (0x1000 < puVar31[0x52]) {
      if (0x1000 < puVar31[0x53]) {
        return 0;
      }
      param_2[0x32] = param_2[0x32] & 0xff3fffffU | 0x400000;
      uVar27 = puVar31[0x52];
      uVar22 = uVar27 >> 1 & 0x7e00;
      sVar5 = (short)uVar22;
      *(short *)(param_2 + 0x35) = sVar5;
      *(ushort *)((int)param_2 + 0xd2) = uVar27 - sVar5;
      *(short *)(param_2 + 0x34) = sVar5 + 2;
      param_2[0x33] = uVar22 << 2 | param_2[0x33] & 3U;
      goto LAB_00034100;
    }
    if (0x1000 < puVar31[0x53]) {
      param_2[0x32] = param_2[0x32] & 0xff3fffffU | 0x800000;
      uVar27 = puVar31[0x53];
      uVar22 = uVar27 >> 1 & 0x7fc0;
      sVar5 = (short)uVar22;
      *(short *)(param_2 + 0x35) = sVar5;
      *(ushort *)((int)param_2 + 0xd2) = uVar27 - sVar5;
      *(short *)(param_2 + 0x34) = sVar5 + 1;
      if ((*(ushort *)param_2[0xc] & 0x400) == 0) {
        param_2[0x33] =
             ((*(ushort *)((int)param_2 + 0x3e) * uVar22 <<
              (*(uint *)(&DAT_001d9f48 + (uint)*(byte *)(param_2 + 0xe) * 0x24) & 7)) >> 5) << 2 |
             param_2[0x33] & 3U;
      }
      else {
        param_2[0x33] = uVar22 << 2 | param_2[0x33] & 3U;
      }
      goto LAB_00034100;
    }
  }
  param_2[0x32] = param_2[0x32] & 0xff3fffff;
LAB_00034100:
  ((int (*)())FUN_0002ddf0)(iStack00000018,param_2);
  return 1;
}

/* FUN_000341a0 @ 0x341a0 (92 bytes) */
int FUN_000341a0(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_1 + 4);
  iVar1 = ((int (*)())FUN_00032100)(uVar2,param_2,param_3,param_4,param_5,param_6);
  if (iVar1 == 0) {
    _gldDeleteTexture(uVar2,param_2);
  }
  return iVar1 != 0;
}

/* FUN_00034200 @ 0x34200 (4472 bytes) */
int FUN_00034200(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int *param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  bool bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  byte bVar8;
  ushort uVar9;
  uint a6;
  float fVar10;
  undefined *puVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  undefined4 *puVar18;
  undefined4 extraout_r4;
  int *piVar19;
  undefined4 uVar20;
  int *piVar21;
  undefined4 in_r8;
  uint uVar22;
  uint *puVar23;
  uint uVar24;
  int iVar25;
  int iVar26;
  uint uVar27;
  uint uVar28;
  int iVar29;
  int iVar30;
  int *piVar31;
  uint uVar32;
  uint uVar33;
  int a0;
  int *piVar34;
  uint uVar35;
  ushort *puVar36;
  uint uVar37;
  int *piVar38;
  uint uStack_88;
  uint uStack_84;
  uint uStack_80;
  
  iVar16 = param_3;
  _pthread_mutex_lock(*(undefined4 *)(param_1 + 0xc));
  puVar36 = (ushort *)param_2[0xc];
  uVar35 = (uint)*(byte *)(puVar36 + 0x2f);
  bVar8 = *(byte *)((int)puVar36 + 0x5f);
  if ((*(uint *)(puVar36 + 0x24) & 0x8000) != 0) {
    bVar8 = *(byte *)((int)puVar36 + 0x6b);
  }
  uVar37 = bVar8 - uVar35;
  iVar16 = ((int (*)())FUN_00030b50)(param_2,extraout_r4,iVar16,param_4,param_5,in_r8);
  if (iVar16 != 0) {
LAB_000342e0:
    _pthread_mutex_unlock(*(undefined4 *)(param_1 + 0xc));
    return 0;
  }
  if ((uVar37 == 0) || (*(char *)((int)puVar36 + 0x6d) != '\0')) goto LAB_00035340;
  uVar20 = 1;
  uVar33 = uVar35 + 1;
  iVar16 = param_3;
  uVar12 = uVar35;
  iVar17 = ((int (*)())FUN_00031220)(param_1,param_2,param_3,uVar35,1);
  if (((iVar17 == 0) || ((*(uint *)(iVar17 + 0x18) & 0x10000) == 0)) ||
     (((*(byte *)((int)param_2 + 0x39) & 7) != 0 &&
      (iVar16 = ((int (*)())FUN_00032100)(param_1,param_2,iVar16,uVar12,uVar20,in_r8), iVar16 == 0))))
  goto LAB_000342e0;
  uVar22 = *(byte *)(puVar36 + 0x30) - uVar35;
  if ((int)uVar22 < 0) {
    uVar22 = 0;
  }
  uVar22 = 1 << (uVar22 & 0x3f);
  uVar27 = *(byte *)((int)puVar36 + 0x61) - uVar35;
  if ((int)uVar27 < 0) {
    uVar27 = 0;
  }
  uVar28 = 1 << (uVar27 & 0x3f);
  uVar27 = *(byte *)(puVar36 + 0x31) - uVar35;
  uStack_80 = uVar27;
  if ((int)uVar27 < 0) {
    uStack_80 = 0;
  }
  uStack_84 = (int)uVar22 >> 1;
  if ((int)uStack_84 < 1) {
    uStack_84 = 1;
  }
  uStack_88 = (int)uVar28 >> 1;
  if ((int)uStack_88 < 1) {
    uStack_88 = 1;
  }
  uVar14 = uStack_80 - 1;
  if ((int)uVar14 < 0) {
    uVar14 = 0;
  }
  uVar14 = 1 << (uVar14 & 0x3f);
  if (*(char *)((int)puVar36 + 0x6f) == '\0') {
    uVar13 = uVar37;
    if (*(char *)(puVar36 + 0x36) != '\x06') {
      iVar15 = uVar37 * 0x1e;
      iVar16 = uVar37 + 1;
      goto LAB_0003440c;
    }
    iVar16 = uVar37 * 2;
    uVar32 = uVar37 * 0x10000;
    iVar15 = uVar37 * 0x2c + -0x16;
    uVar24 = uVar37;
  }
  else {
    if ((int)uVar37 < 1) {
      uVar13 = 0;
      iVar15 = 0;
      iVar16 = 1;
    }
    else {
      uVar24 = 0;
      uVar13 = 0;
      uVar32 = uVar37;
      do {
        iVar16 = (int)uVar14 >> (uVar24 & 0x3f);
        if (iVar16 < 1) {
          iVar16 = 1;
        }
        uVar13 = uVar13 + iVar16;
        uVar24 = uVar24 + 1;
        uVar32 = uVar32 - 1;
      } while (uVar32 != 0);
      iVar15 = uVar13 * 0x28;
      iVar16 = uVar13 + 1;
    }
LAB_0003440c:
    iVar15 = iVar15 + -0x12;
    uVar32 = 0x10000;
    uVar24 = 1;
  }
  a0 = param_1 + 0x240;
  a6 = param_3 << 0x10;
  uVar20 = (**(code **)(param_1 + 0x2998))
                     (a0,iVar15 + iVar16 + 0x340,uStack_80,uVar12,uVar20,in_r8,a6);
  *(undefined4 *)(param_1 + 0x298c) = uVar20;
  puVar18 = (undefined4 *)((int (*)())FUN_00030840)(param_1,uVar20,param_2);
  puVar11 = PTR_DAT_001e88d0;
  puVar23 = *(uint **)(param_1 + 0x1d8);
  piVar38 = puVar18 + 4 + uVar13;
  *puVar23 = (int)puVar18 - (int)puVar23 >> 2 | *puVar23;
  *(undefined4 **)(param_1 + 0x1d8) = puVar18;
  puVar18[2] = uVar37 | a6 | uVar33 * 0x100;
  puVar18[3] = uVar13 | uVar32;
  *puVar18 = 0x37000000;
  piVar34 = piVar38 + uVar24;
  _memcpy(piVar34,puVar11,0x2f4);
  piVar19 = piVar34 + 0xbd;
  if (*(char *)((int)puVar36 + 0x6f) != '\0') {
    piVar34[0x26] = 3;
    piVar34[0x22] = 0;
    piVar34[0x27] = 0x82d;
    piVar34[0x21] = (int)((unsigned char *)0x00001002U);
    piVar34[0x98] = piVar34[0x98] & 0xfffc0fffU | 0x2000;
    piVar34[0x25] = 0x825;
    piVar34[0x92] = piVar34[0x92] & 0xffffff80U | 3;
    piVar34[0x2a] = 0x26020001;
    piVar34[0x28] = 5;
    piVar34[0x2c] = -0x57704f8;
    piVar34[0x29] = 0x854;
    piVar34[0x2b] = 0x878;
  }
  uVar12 = piVar34[0xa2];
  piVar34[0xa2] = uVar12 & 0xffff81ff | 0x3400;
  if ((int)uVar27 < 1) {
    iVar16 = 0;
  }
  else {
    iVar16 = 2;
  }
  piVar34[0xa2] = iVar16 << 0xf | uVar12 & 0xfffe01ff | 0x3400;
  uVar24 = piVar34[0x8a];
  uVar13 = piVar34[0xa8];
  piVar34[0xa4] = piVar34[0xa4] & 0xffffe007U | 0x1f00;
  piVar34[0xa6] =
       uVar37 * 0x4000000 & 0x3c000000 |
       (uStack_80 & 0xf) << 0x16 |
       (uVar28 - 1) * 0x800 & 0x3ff800 | uVar22 - 1 & 0x7ff | piVar34[0xa6] & 0x40000000U;
  uVar37 = *(uint *)(iVar17 + 0x1c) >> 7 & 0x1f;
  piVar34[0xa8] = uVar37 | uVar13 & 0xffffffe0;
  uVar12 = (*(uint *)(iVar17 + 0x1c) & 0xe) << 0xb;
  piVar34[0xa8] = uVar12 | uVar37 | uVar13 & 0xffff8fe0;
  uVar27 = *(uint *)(iVar17 + 0x20) >> 0xe & 0x38000;
  piVar34[0xa8] = uVar27 | uVar12 | uVar37 | uVar13 & 0xfffc0fe0;
  uVar32 = *(uint *)(iVar17 + 0x20) >> 8 & 0x1c0000;
  piVar34[0xa8] = uVar32 | uVar27 | uVar12 | uVar37 | uVar13 & 0xffe00fe0;
  piVar34[0xa8] =
       (*(uint *)(iVar17 + 0x1c) & 0x70) << 5 |
       uVar32 | uVar27 | uVar12 | uVar37 | uVar13 & 0xffe001e0;
  uVar37 = (*(uint *)(iVar17 + 0x18) & 0x18) << 5;
  piVar34[0x8a] = uVar37 | uVar24 & 0xfffffcff;
  uVar12 = (*(uint *)(iVar17 + 0x18) & 6) << 9;
  piVar34[0x8a] = uVar12 | uVar37 | uVar24 & 0xfffff0ff;
  uVar27 = *(uint *)(iVar17 + 0x1c) >> 0x12 & 0x3000;
  piVar34[0x8a] = uVar27 | uVar12 | uVar37 | uVar24 & 0xffffc0ff;
  uVar32 = *(uint *)(iVar17 + 0x1c) >> 0xe & 0xc000;
  piVar34[0x8a] = uVar32 | uVar27 | uVar12 | uVar37 | uVar24 & 0xffff00ff;
  piVar34[0x8a] =
       *(uint *)(iVar17 + 0x18) >> 5 & 0x1f |
       uVar32 | uVar27 | uVar12 | uVar37 | uVar24 & 0xffff00e0;
  uVar9 = puVar36[1];
  if (((uVar9 != 0x1908) && (uVar9 != 0x1906)) && (uVar9 != 0x190a)) {
    piVar34[0x56] = piVar34[0x56] & 0xfffe3fffU | 0x18000;
  }
  if ((param_2[0xd] == 0) || ((*(byte *)(param_2[0xd] + 0x15) & 0x18) == 0)) {
    iVar16 = 0x20;
  }
  else {
    iVar16 = 0x20 / (1 << (*(uint *)(&DAT_001d9f4c + (uint)*(byte *)(param_2 + 0xe) * 0x24) >> 0x1c
                          & 3));
  }
  iVar16 = iVar16 >> (*(uint *)(iVar17 + 0x14) & 7);
  if ((*puVar36 & 0x400) == 0) {
    iVar15 = *param_2 + 0x40 + (param_3 * 0xd + uVar33) * 0x20;
  }
  else {
    iVar15 = 0;
  }
  bVar1 = iVar15 == 0;
  piVar21 = puVar18 + 5;
  puVar18[4] = (int)piVar34 + (0x268 - (int)puVar18) >> 2;
  if (bVar1) {
    piVar34[0x9a] = uVar33 | a6;
  }
  else {
    piVar34[0x9a] = *(int *)(iVar15 + 8);
  }
  piVar31 = piVar38 + 1;
  *piVar38 = (int)piVar34 + (0x280 - (int)puVar18) >> 2;
  if (bVar1) {
    piVar34[0xa0] = uVar35 | a6;
  }
  else {
    piVar34[0xa0] = *(int *)((param_3 * 0xd + uVar35) * 0x20 + *param_2 + 0x48);
    iVar29 = param_2[0xd];
    if ((iVar29 == 0) || ((*(byte *)(iVar29 + 0x15) & 4) == 0)) {
LAB_0003482c:
      iVar30 = 0;
    }
    else {
      uVar35 = uVar33 - *(byte *)(param_2[0xc] + 0x69);
      if ((*(byte *)(iVar29 + 0x15) & 0x18) == 0) {
        iVar25 = 1;
        iVar30 = 0x100;
      }
      else {
        iVar25 = 1 << (*(uint *)(&DAT_001d9f4c + (uint)*(byte *)(param_2 + 0xe) * 0x24) >> 0x1c & 3)
        ;
        iVar30 = 0x20 / iVar25 << 3;
      }
      if ((*(int *)(*param_2 + 0xc) >> (uVar35 & 0x3f) < iVar30) ||
         (iVar30 = 1, (int)(uint)*(ushort *)(*param_2 + 0x16) >> (uVar35 & 0x3f) < iVar25 << 3))
      goto LAB_0003482c;
    }
    if (iVar29 == 0) {
      uVar35 = 0;
    }
    else {
      uVar35 = (*(byte *)(iVar29 + 0x15) & 0x18) << 0xe;
    }
    piVar34[0x9c] =
         uVar35 | (uStack_84 + iVar16) - 1 & -iVar16 & 0x3ffe | iVar30 << 0x10 |
         (*(uint *)(iVar17 + 0x18) & 0x3c00) << 0xb;
  }
  piVar34[0xb3] = uStack_84 - 1 & 0x1fff | (uStack_88 - 1) * 0x2000 & 0x3ffe000;
  if ((*(uint *)(iVar17 + 0x20) & 0x400000) != 0) {
    piVar34[0x1e] = 0;
  }
  iVar29 = (uVar33 + param_3 * 0xd) * 0x20;
  fVar2 = (float)(0.0078125 /
                 ((double)CONCAT44(0x43300000,uVar22 ^ 0x80000000) - 4503601774854144.0));
  fVar3 = (float)(0.0078125 /
                 ((double)CONCAT44(0x43300000,uVar28 ^ 0x80000000) - 4503601774854144.0));
  fVar10 = fVar2 + 1.0;
  while( true ) {
    iVar29 = iVar29 + 0x20;
    if (*(char *)((int)puVar36 + 0x6f) == '\0') {
      piVar38 = piVar19 + 0xc;
      piVar19[2] = (int)(fVar3 + 1.0);
      *piVar19 = 0x31080;
      piVar19[1] = (int)fVar2;
      piVar19[3] = (int)fVar10;
      piVar19[5] = (int)((unsigned char *)0x00001087U);
      piVar19[4] = (int)fVar3;
      fVar4 = (float)((double)CONCAT44(0x43300000,uStack_84 ^ 0x80000000) - 4503601774854144.0);
      fVar7 = (float)((double)CONCAT44(0x43300000,uStack_88 ^ 0x80000000) - 4503601774854144.0);
      piVar19[7] = -0x3ffccb00;
      piVar19[8] = 0x10031;
      piVar19[9] = (int)((fVar4 + 0.0) * 0.5);
      piVar19[10] = (int)((fVar7 + 0.0) * 0.5);
      piVar19[0xb] = 0;
      piVar19[6] = (int)(fVar4 * 6.0) << 0x10 | (int)(fVar7 * 6.0);
    }
    else {
      fVar4 = (float)(1.0 / ((double)CONCAT44(0x43300000,uVar14 ^ 0x80000000) - 4503601774854144.0))
      ;
      fVar7 = fVar4 * 0.5 +
              (float)((1.0 / ((double)CONCAT44(0x43300000,1 << (uStack_80 & 0x3f) ^ 0x80000000) -
                             4503601774854144.0)) * 0.0078125);
      piVar38 = piVar19;
      if (0 < (int)uVar14) {
        uVar35 = 0;
        fVar5 = (float)((double)CONCAT44(0x43300000,uStack_88 ^ 0x80000000) - 4503601774854144.0);
        fVar6 = (float)((double)CONCAT44(0x43300000,uStack_84 ^ 0x80000000) - 4503601774854144.0);
        do {
          while( true ) {
            uVar35 = uVar35 + 1;
            piVar19[6] = (int)fVar7;
            piVar19[0xb] = (int)fVar7;
            piVar19[0x10] = (int)fVar7;
            piVar19[0x15] = (int)fVar7;
            piVar38 = piVar19 + 0x16;
            *piVar19 = -0x3febcb00;
            piVar19[1] = 0x4003d;
            piVar19[2] = 0;
            piVar19[3] = 0;
            fVar7 = fVar7 + fVar4;
            piVar19[4] = (int)fVar2;
            piVar19[5] = (int)fVar3;
            piVar19[7] = (int)fVar6;
            piVar19[8] = 0;
            piVar19[9] = (int)fVar10;
            piVar19[10] = (int)fVar3;
            piVar19[0xc] = (int)fVar6;
            piVar19[0xd] = (int)fVar5;
            piVar19[0xe] = (int)fVar10;
            piVar19[0xf] = (int)(fVar3 + 1.0);
            piVar19[0x11] = 0;
            piVar19[0x12] = (int)fVar5;
            piVar19[0x13] = (int)fVar2;
            piVar19[0x14] = (int)(fVar3 + 1.0);
            if ((int)uVar14 <= (int)uVar35) break;
            piVar19[0x16] = (int)((unsigned char *)0x00001393U);
            piVar19[0x17] = 10;
            piVar19[0x18] = (int)((unsigned char *)0x0000138aU);
            *piVar21 = (int)piVar19 + (100 - (int)puVar18) >> 2;
            piVar21 = piVar21 + 1;
            if (bVar1) {
              piVar19 = piVar19 + 0x1a;
            }
            else {
              piVar19[0x19] = uVar35 * *(int *)(iVar15 + 0x14) + *(int *)(iVar15 + 8);
              piVar19 = piVar19 + 0x1a;
            }
          }
          piVar19 = piVar38;
        } while (uVar14 != uVar35);
      }
    }
    if ((int)(uint)bVar8 <= (int)uVar33) break;
    piVar38[5] = 0;
    piVar19 = piVar38 + 6;
    *piVar38 = (int)((unsigned char *)0x00001393U);
    piVar38[1] = 10;
    piVar38[2] = 0x5c8;
    piVar38[3] = 0x20000;
    piVar38[4] = (int)((unsigned char *)0x00001040U);
    if (*(char *)(puVar36 + 0x36) == '\x06') {
      piVar38[6] = (int)(*(unsigned char *)0x00001150);
      *piVar31 = (int)piVar38 + (0x1c - (int)puVar18) >> 2;
      piVar31 = piVar31 + 1;
      if (bVar1) {
        piVar38[7] = uVar33 | a6;
      }
      else {
        piVar38[7] = *(int *)(iVar15 + 8);
      }
      piVar38[8] = (int)(*(unsigned char *)0x00001120);
      piVar19 = piVar38 + 10;
      piVar38[9] = (uStack_88 - 1) * 0x800 & 0x3ff800 |
                   uStack_84 - 1 & 0x7ff | piVar34[0xa6] & 0x40000000U;
    }
    uStack_80 = uStack_80 - 1;
    uVar33 = uVar33 + 1;
    if ((int)uStack_80 < 0) {
      uStack_80 = 0;
    }
    uStack_84 = (int)uStack_84 >> 1;
    if ((int)uStack_84 < 1) {
      uStack_84 = 1;
    }
    uStack_88 = (int)uStack_88 >> 1;
    if ((int)uStack_88 < 1) {
      uStack_88 = 1;
    }
    uVar14 = (int)uVar14 >> 1;
    if ((int)uVar14 < 1) {
      uVar14 = 1;
    }
    iVar15 = 0;
    if ((*puVar36 & 0x400) == 0) {
      iVar15 = iVar29 + *param_2 + 0x40;
    }
    bVar1 = iVar15 == 0;
    *piVar19 = (int)((unsigned char *)0x0000138aU);
    *piVar21 = (int)piVar19 + (4 - (int)puVar18) >> 2;
    piVar21 = piVar21 + 1;
    if (bVar1) {
      piVar19[1] = a6 | uVar33;
    }
    else {
      piVar19[1] = *(int *)(iVar15 + 8);
    }
    piVar19[2] = (int)((unsigned char *)0x0000138eU);
    if (!bVar1) {
      iVar30 = param_2[0xd];
      if ((iVar30 == 0) || ((*(byte *)(iVar30 + 0x15) & 4) == 0)) {
LAB_00034df0:
        iVar25 = 0;
      }
      else {
        uVar35 = uVar33 - *(byte *)(param_2[0xc] + 0x69);
        if ((*(byte *)(iVar30 + 0x15) & 0x18) == 0) {
          iVar26 = 1;
          iVar25 = 0x100;
        }
        else {
          iVar26 = 1 << (*(uint *)(&DAT_001d9f4c + (uint)*(byte *)(param_2 + 0xe) * 0x24) >> 0x1c &
                        3);
          iVar25 = 0x20 / iVar26 << 3;
        }
        if ((*(int *)(*param_2 + 0xc) >> (uVar35 & 0x3f) < iVar25) ||
           (iVar25 = 1, (int)(uint)*(ushort *)(*param_2 + 0x16) >> (uVar35 & 0x3f) < iVar26 << 3))
        goto LAB_00034df0;
      }
      if (iVar30 == 0) {
        uVar35 = 0;
      }
      else {
        uVar35 = (*(byte *)(iVar30 + 0x15) & 0x18) << 0xe;
      }
      piVar19[3] = uVar35 | (iVar16 + uStack_84) - 1 & -iVar16 & 0x3ffe | iVar25 << 0x10 |
                   (*(uint *)(iVar17 + 0x18) & 0x3c00) << 0xb;
    }
    piVar19 = piVar19 + 4;
  }
  puVar18[1] = (int)piVar38 - (int)puVar18 >> 2;
  puVar23 = *(uint **)(param_1 + 0x1d8);
  *puVar23 = (int)piVar38 - (int)puVar23 >> 2 | *puVar23;
  *(int **)(param_1 + 0x1d8) = piVar38;
  piVar38[1] = 0;
  *piVar38 = 0x33000000;
  piVar38[2] = (int)((unsigned char *)0x00001393U);
  piVar38[3] = 10;
  piVar38[4] = (int)((unsigned char *)0x000013c6U);
  piVar38[5] = 3;
  piVar38[6] = 0x5c8;
  piVar38[7] = 0x20000;
  piVar38[8] = (int)(*(unsigned char *)0x000010ea);
  iVar16 = *(int *)(param_1 + 0x1cfc);
  piVar38[10] = (int)((unsigned char *)0x000010faU);
  piVar38[9] = iVar16;
  iVar16 = *(int *)(param_1 + 0x1da0);
  piVar38[0xc] = -0x3ffff000;
  piVar38[0xe] = 0x11004;
  piVar38[0xb] = iVar16;
  piVar38[0xf] = *(int *)(param_1 + 0x1ca8);
  iVar16 = *(int *)(param_1 + 0x1cac);
  piVar38[0x11] = (int)((unsigned char *)0x00001008U);
  piVar38[0x10] = iVar16;
  iVar16 = *(int *)(param_1 + 0x1ca0);
  piVar38[0x13] = (int)(*(unsigned char *)0x000010e9);
  piVar38[0x12] = iVar16;
  iVar16 = *(int *)(param_1 + 0x1d20);
  piVar38[0x15] = (int)((unsigned char *)0x000013c7U);
  piVar38[0x14] = iVar16;
  iVar16 = *(int *)(param_1 + 0x1cf0);
  piVar38[0x17] = (int)((unsigned char *)0x000013c1U);
  piVar38[0x16] = iVar16;
  iVar16 = *(int *)(param_1 + 0x1ce4);
  piVar38[0x19] = 0x850;
  piVar38[0x18] = iVar16;
  iVar16 = *(int *)(param_1 + 0x1dc0);
  piVar38[0x1b] = 0x887;
  piVar38[0x1a] = iVar16;
  iVar16 = *(int *)(param_1 + 0x1db4);
  piVar38[0xbd] = 0x82c;
  piVar38[0x1c] = iVar16;
  iVar16 = *(int *)(0x00001dc4 + param_1);
  piVar38[0x1d] = (int)((unsigned char *)0x000010aeU);
  piVar38[0xbe] = iVar16;
  iVar16 = *(int *)(param_1 + 0x1d70);
  piVar38[0x1f] = (int)((unsigned char *)0x00001394U);
  piVar38[0x1e] = iVar16;
  iVar16 = *(int *)(param_1 + 0x1d30);
  piVar38[0x21] = (int)((unsigned char *)0x00001380U);
  piVar38[0x23] = (int)((unsigned char *)0x00001002U);
  piVar38[0x22] = 0;
  piVar38[0x20] = iVar16;
  piVar38[0x24] = *(int *)(param_1 + 0x1d90);
  iVar16 = *(int *)(param_1 + 0x1d90);
  piVar38[0x25] = 0x824;
  piVar38[0x24] = iVar16;
  iVar16 = *(int *)(param_1 + 0x1ddc);
  piVar38[0x27] = 0x825;
  piVar38[0x26] = iVar16;
  iVar16 = *(int *)(param_1 + 0x1de0);
  piVar38[0x29] = 0x82d;
  piVar38[0x28] = iVar16;
  iVar16 = *(int *)(0x000026c8 + param_1 + 4);
  piVar38[0x2b] = 0x854;
  piVar38[0x2a] = iVar16;
  iVar16 = **(int **)(param_1 + 0x2680);
  piVar38[0x2d] = 0x878;
  piVar38[0x2c] = iVar16;
  iVar16 = **(int **)(param_1 + 0x2684);
  piVar38[0x2f] = (int)((unsigned char *)0x000013c0U);
  piVar38[0x2e] = iVar16;
  iVar16 = *(int *)(param_1 + 0x1ce0);
  piVar38[0x31] = (int)((unsigned char *)0x000012f0U);
  piVar38[0x30] = iVar16;
  uVar35 = *(uint *)(param_1 + 0x1d2c);
  piVar38[0x32] = uVar35;
  if ((*(uint *)(&DAT_001d9f4c + (uint)(byte)((unsigned char *)0x00002b7f)[param_1] * 0x24) & 0x8000) == 0) {
    piVar38[0x32] = uVar35 & 0xfffffffe;
  }
  piVar38[0x33] = (int)((unsigned char *)0x000012f5U);
  uVar35 = *(uint *)(param_1 + 0x1c8c);
  piVar38[0x34] = uVar35;
  if ((*(uint *)(&DAT_001d9f4c + (uint)(byte)((unsigned char *)0x00002b7f)[param_1] * 0x24) & 0x8000) == 0) {
    piVar38[0x34] = uVar35 & 0xfffff7ff;
  }
  piVar38[0x35] = (int)((unsigned char *)0x000010a2U);
  iVar16 = *(int *)(param_1 + 0x1d7c);
  piVar38[0x37] = (int)((unsigned char *)0x00001381U);
  piVar38[0x36] = iVar16;
  uVar35 = *(uint *)(param_1 + 0x1cc0);
  piVar38[0x38] = uVar35;
  if ((*(uint *)(&DAT_001d9f4c + (uint)(byte)((unsigned char *)0x00002b7f)[param_1] * 0x24) & 0x4000) == 0) {
    piVar38[0x38] = uVar35 & 0xfffffffc;
  }
  piVar38[0x39] = (int)((unsigned char *)0x0000109eU);
  iVar16 = *(int *)(param_1 + 0x1d6c);
  piVar38[0x3b] = (int)((unsigned char *)0x00001096U);
  piVar38[0x3a] = iVar16;
  iVar16 = *(int *)(param_1 + 0x1df8);
  piVar38[0x3d] = (int)((unsigned char *)0x00001041U);
  piVar38[0x3a] = iVar16;
  iVar16 = *(int *)(param_1 + 0x29f0);
  piVar38[0x3f] = (int)((unsigned char *)0x00001046U);
  piVar38[0x3e] = iVar16;
  iVar16 = *(int *)(param_1 + 0x1dfc);
  piVar38[0x41] = (int)((unsigned char *)0x00001094U);
  piVar38[0x59] = (int)((unsigned char *)0x00001095U);
  piVar38[0x5b] = -0x3fddf000;
  piVar38[0x7f] = (int)((unsigned char *)0x00001180U);
  piVar38[0x43] = (int)((unsigned char *)0x00001095U);
  piVar38[0x45] = (int)((unsigned char *)0x00001095U);
  piVar38[0x47] = (int)((unsigned char *)0x00001095U);
  piVar38[0x40] = iVar16;
  piVar38[0x49] = (int)((unsigned char *)0x00001095U);
  piVar38[0x4b] = (int)((unsigned char *)0x00001095U);
  piVar38[0x4d] = (int)((unsigned char *)0x00001095U);
  piVar38[0x4f] = (int)((unsigned char *)0x00001095U);
  piVar38[0x51] = (int)((unsigned char *)0x00001095U);
  piVar38[0x53] = (int)((unsigned char *)0x00001095U);
  piVar38[0x55] = (int)((unsigned char *)0x00001095U);
  piVar38[0x57] = (int)((unsigned char *)0x00001095U);
  piVar38[0x42] = 0;
  piVar38[0x80] = 2;
  piVar38[0x81] = (int)((unsigned char *)0x00001189U);
  piVar38[0x83] = (int)((unsigned char *)0x00001181U);
  piVar38[0x85] = (int)((unsigned char *)0x0000118dU);
  piVar38[0x87] = (int)((unsigned char *)0x0000118eU);
  piVar38[0x89] = (int)((unsigned char *)0x0000118cU);
  piVar38[0x8b] = (int)((unsigned char *)0x000011a9U);
  iVar16 = *(int *)(param_1 + 0x257c);
  piVar38[0x8d] = (int)((unsigned char *)0x000011aaU);
  piVar38[0x8c] = iVar16;
  iVar16 = *(int *)(param_1 + 0x2580);
  piVar38[0x8f] = (int)((unsigned char *)0x000011abU);
  piVar38[0x8e] = iVar16;
  iVar16 = *(int *)(param_1 + 0x2584);
  piVar38[0x91] = (int)((unsigned char *)0x000011acU);
  piVar38[0x90] = iVar16;
  iVar16 = *(int *)(param_1 + 0x2588);
  piVar38[0x93] = (int)((unsigned char *)0x000010c0U);
  piVar38[0x92] = iVar16;
  iVar16 = *(int *)(param_1 + 0x216c);
  piVar38[0x95] = (int)((unsigned char *)0x000010c1U);
  piVar38[0x97] = (int)((unsigned char *)0x000010c8U);
  piVar38[0x99] = (int)((unsigned char *)0x0000101dU);
  piVar38[0x94] = iVar16;
  iVar16 = *(int *)(param_1 + 0x2128);
  piVar38[0x9b] = (int)((unsigned char *)0x0000138aU);
  piVar38[0x9d] = (int)((unsigned char *)0x0000138eU);
  piVar38[0xa2] = 0;
  piVar38[0x9f] = (int)((unsigned char *)0x00001040U);
  piVar38[0x9c] = 0;
  piVar38[0x9e] = 0;
  piVar38[0xa0] = 0;
  piVar38[0x9a] = iVar16;
  piVar38[0xa1] = (int)(*(unsigned char *)0x00001150);
  piVar38[0xa3] = (int)((unsigned char *)0x00001100U);
  iVar16 = *(int *)(param_1 + 0x1f1c);
  piVar38[0xa5] = (int)((unsigned char *)0x00001110U);
  piVar38[0xa4] = iVar16;
  piVar38[0xa6] = *(int *)(param_1 + 0x1f5c);
  piVar38[0xa7] = (int)(*(unsigned char *)0x00001120);
  iVar16 = *(int *)(param_1 + 0x1f9c);
  piVar38[0xa9] = (int)((unsigned char *)0x00001130U);
  piVar38[0xa8] = iVar16;
  iVar16 = *(int *)(param_1 + 0x1fdc);
  piVar38[0xab] = (int)((unsigned char *)0x00001140U);
  piVar38[0xaa] = iVar16;
  iVar16 = *(int *)(param_1 + 0x201c);
  piVar38[0xad] = (int)((unsigned char *)0x000010f4U);
  piVar38[0xae] = 0xaaaa;
  piVar38[0xaf] = (int)((unsigned char *)0x00001383U);
  piVar38[0xac] = iVar16;
  iVar16 = *(int *)(param_1 + 0x1d34);
  piVar38[0xb1] = (int)((unsigned char *)0x00001386U);
  piVar38[0xb0] = iVar16;
  iVar16 = *(int *)(param_1 + 0x1d38);
  piVar38[0xb3] = 0x110f8;
  piVar38[0xb2] = iVar16;
  piVar38[0xb4] = *(int *)(param_1 + 0x1d98);
  iVar16 = *(int *)(param_1 + 0x1d50);
  piVar38[0xb6] = (int)((unsigned char *)0x00001087U);
  piVar38[0xb5] = iVar16;
  iVar16 = *(int *)(param_1 + 0x1f0c);
  piVar38[0xb8] = 0x31080;
  piVar38[0xb7] = iVar16;
  piVar38[0xb9] = *(int *)(param_1 + 0x1efc);
  piVar38[0xba] = *(int *)(param_1 + 0x1f04);
  piVar38[0xbb] = *(int *)(param_1 + 0x1f00);
  piVar38[0xbc] = *(int *)(param_1 + 0x1f08);
  FUN_0004c100(piVar38 + 2,a0);
  uVar20 = ((int (*)())FUN_000308c0)(param_1,piVar38 + 0xbf);
  *(undefined4 *)(param_1 + 0x298c) = uVar20;
  (**(code **)(param_1 + 0x299c))(a0,uVar20);
LAB_00035340:
  _pthread_mutex_unlock(*(undefined4 *)(param_1 + 0xc));
  return 1;
}

/* FUN_000353a0 @ 0x353a0 (5656 bytes) */
int FUN_000353a0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11)
  int param_1;
  int *param_2;
  int param_3;
  uint param_4;
  uint param_5;
  uint param_6;
  int param_7;
  uint param_8;
  uint param_9;
  int param_10;
  int param_11;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  ushort uVar9;
  ushort uVar10;
  short sVar11;
  bool bVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  double dVar25;
  undefined *puVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint *puVar30;
  uint *puVar31;
  int iVar32;
  int iVar33;
  int iVar34;
  int iVar35;
  undefined4 uVar36;
  int iVar37;
  uint uVar38;
  undefined4 uVar39;
  uint uVar40;
  undefined4 uVar41;
  undefined4 uVar42;
  undefined4 uVar43;
  uint uVar44;
  uint uVar45;
  uint uVar46;
  int iVar47;
  uint uVar48;
  uint uVar49;
  uint uVar50;
  int iVar51;
  uint uVar52;
  int iVar53;
  uint uStack_dc;
  uint uStack_d8;
  uint uStack_d4;
  uint uStack_d0;
  
  uVar50 = param_6;
  iVar34 = param_7;
  _pthread_mutex_lock(*(undefined4 *)(param_1 + 0xc));
  iVar47 = param_2[0xc];
  uVar39 = 0;
  iVar35 = param_3;
  uVar49 = param_4;
  iVar32 = ((int (*)())FUN_00031220)(param_1,param_2,param_3,param_4,0);
  iVar53 = param_1 + 0x240;
  if ((iVar32 == 0) || ((*(uint *)(iVar32 + 0x18) & 0x10000) == 0)) {
LAB_00035740:
    _pthread_mutex_unlock(*(undefined4 *)(param_1 + 0xc));
    return 0;
  }
  iVar33 = FUN_0000a2f0((uint)*(ushort *)(((unsigned char *)0x00002db8) + *(int *)(param_1 + 0x10)),
                        *(undefined4 *)(param_1 + 0x154));
  bVar12 = *(short *)(iVar47 + 2) != 0x1902;
  if ((!bVar12) &&
     (((*(int *)(param_1 + 0x150) == 0 &&
       (iVar34 = FUN_0001a010(param_1,iVar33,iVar35,uVar49,uVar39,uVar50,iVar34), iVar34 != 0)) ||
      ((*(uint *)(param_1 + 0x154) & 0x30000) == 0)))) goto LAB_00035740;
  iVar34 = param_4 * 0x18 + param_3 * 0x168 + param_2[0xc];
  uVar48 = (uint)*(ushort *)(iVar34 + 0xa4);
  uVar46 = (uint)*(ushort *)(iVar34 + 0xa6);
  if (uVar48 == 0) {
    uVar48 = 1;
    fVar1 = FLOAT_001aa0e8;
  }
  else {
    fVar1 = (float)((double)CONCAT44(0x43300000,uVar48 ^ 0x80000000) - DOUBLE_001aa1e0);
  }
  if (uVar46 == 0) {
    uVar46 = 1;
    fVar8 = FLOAT_001aa0e8;
  }
  else {
    fVar8 = (float)((double)CONCAT44(0x43300000,uVar46 ^ 0x80000000) - DOUBLE_001aa1e0);
  }
  fVar2 = (float)((double)CONCAT44(0x43300000,*(uint *)(param_1 + 0x15c) ^ 0x80000000) -
                 DOUBLE_001aa1e0);
  fVar3 = (float)((double)CONCAT44(0x43300000,param_8 + param_10 ^ 0x80000000) - DOUBLE_001aa1e0);
  fVar13 = fVar3 - fVar2;
  fVar7 = fVar2;
  if (fVar13 < 0.0) {
    fVar7 = fVar3;
  }
  fVar3 = (float)((double)CONCAT44(0x43300000,param_9 + param_11 ^ 0x80000000) - DOUBLE_001aa1e0);
  fVar4 = (float)((double)CONCAT44(0x43300000,param_8 ^ 0x80000000) - DOUBLE_001aa1e0);
  if (-fVar13 < 0.0) {
    fVar7 = fVar2;
  }
  fVar2 = (float)((double)CONCAT44(0x43300000,*(uint *)(param_1 + 0x160) ^ 0x80000000) -
                 DOUBLE_001aa1e0);
  fVar13 = fVar4;
  if (fVar4 < 0.0) {
    fVar13 = FLOAT_001aa0d4;
  }
  fVar5 = (float)((double)CONCAT44(0x43300000,param_5 ^ 0x80000000) - DOUBLE_001aa1e0);
  fVar15 = fVar3 - fVar2;
  fVar6 = (float)((double)CONCAT44(0x43300000,param_9 ^ 0x80000000) - DOUBLE_001aa1e0);
  fVar14 = FLOAT_001aa0d4;
  if (-fVar4 < 0.0) {
    fVar14 = fVar13;
  }
  fVar13 = fVar5 + (fVar7 - fVar4);
  fVar7 = (float)((double)CONCAT44(0x43300000,param_6 ^ 0x80000000) - DOUBLE_001aa1e0);
  fVar17 = fVar2;
  if (fVar15 < 0.0) {
    fVar17 = fVar3;
  }
  fVar3 = fVar6;
  if (fVar6 < 0.0) {
    fVar3 = FLOAT_001aa0d4;
  }
  if (-fVar15 < 0.0) {
    fVar17 = fVar2;
  }
  fVar2 = fVar13 - fVar1;
  fVar15 = FLOAT_001aa0d4;
  if (-fVar6 < 0.0) {
    fVar15 = fVar3;
  }
  fVar5 = (fVar14 - fVar4) + fVar5;
  fVar3 = fVar1;
  if (fVar2 < 0.0) {
    fVar3 = fVar13;
  }
  fVar13 = fVar5;
  if (fVar5 < 0.0) {
    fVar13 = FLOAT_001aa0d4;
  }
  fVar4 = (float)((double)CONCAT44(0x43300000,param_8 - param_5 ^ 0x80000000) - DOUBLE_001aa1e0);
  fVar14 = fVar7 + (fVar17 - fVar6);
  fVar7 = (fVar15 - fVar6) + fVar7;
  if (-fVar2 < 0.0) {
    fVar3 = fVar1;
  }
  fVar1 = FLOAT_001aa0d4;
  if (-fVar5 < 0.0) {
    fVar1 = fVar13;
  }
  fVar2 = fVar8 - fVar14;
  fVar13 = fVar7;
  if (fVar7 < 0.0) {
    fVar13 = FLOAT_001aa0d4;
  }
  fVar5 = (float)((double)CONCAT44(0x43300000,param_9 - param_6 ^ 0x80000000) - DOUBLE_001aa1e0);
  fVar15 = fVar1 + fVar4;
  fVar6 = fVar3 + fVar4;
  if (fVar2 < 0.0) {
    fVar14 = fVar8;
  }
  fVar17 = FLOAT_001aa0d4;
  if (-fVar7 < 0.0) {
    fVar17 = fVar13;
  }
  if (-fVar2 < 0.0) {
    fVar8 = fVar14;
  }
  if ((fVar3 <= fVar1) || (fVar8 <= fVar17)) {
    _pthread_mutex_unlock(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
  if (((*(byte *)((int)param_2 + 0x39) & 7) != 0) &&
     (iVar34 = ((int (*)())FUN_00032100)(param_1,param_2,iVar35,uVar49,uVar39,uVar50), iVar34 == 0))
  goto LAB_00035740;
  iVar34 = *(int *)(param_1 + 0x150);
  if (iVar34 == 0) {
    iVar35 = FUN_0001a010(param_1,iVar33,iVar35,uVar49,uVar39,uVar50,0);
    if (iVar35 == 0) {
      iVar34 = *(int *)(param_1 + 0x150);
    }
    else {
      FUN_000230d0(param_1,0,iVar33,0,(int)fVar15,(int)(fVar17 + fVar5),(int)(fVar6 - fVar15),
                   (int)((fVar8 + fVar5) - (fVar17 + fVar5)));
      iVar34 = *(int *)(param_1 + 0x150);
    }
  }
  if (bVar12) {
    iVar35 = 0;
    iVar51 = 0;
  }
  else {
    iVar35 = 1000;
    iVar51 = 4000;
  }
  fVar2 = FLOAT_001aa0e8;
  if (((unsigned char *)0x00002b7c)[param_1] != '\0') {
    fVar5 = (float)((double)CONCAT44(0x43300000,*(uint *)(param_1 + 0x160) ^ 0x80000000) -
                   DOUBLE_001aa1e0) - fVar5;
    fVar2 = FLOAT_001aa114;
  }
  if (iVar34 == 0) {
    uVar9 = *(ushort *)(param_1 + 0x11e);
    uVar10 = *(ushort *)(param_1 + 0x122);
  }
  else {
    uVar9 = *(ushort *)(param_1 + 0x15e);
    uVar10 = *(ushort *)(param_1 + 0x162);
  }
  uVar50 = (uint)uVar9;
  uVar49 = (uint)uVar10;
  if ((uVar50 < 0x1001) && (uVar49 < 0x1001)) {
    uVar52 = 0;
    iVar34 = 0xc;
    uStack_d0 = 0;
    uStack_d4 = 0;
    uStack_d8 = 0;
    uStack_dc = 0;
    fVar14 = FLOAT_001aa0d4;
    fVar23 = FLOAT_001aa0d4;
    fVar7 = FLOAT_001aa0d4;
    fVar13 = FLOAT_001aa0d4;
  }
  else {
    fVar7 = fVar17 * fVar2 + fVar5;
    fVar14 = fVar8 * fVar2 + fVar5;
    fVar13 = fVar14;
    if (fVar14 < fVar7) {
      fVar13 = fVar7;
      fVar7 = fVar14;
    }
    fVar14 = fVar15;
    fVar23 = fVar6;
    if (fVar6 < fVar15) {
      fVar14 = fVar6;
      fVar23 = fVar15;
    }
    uStack_d8 = 0;
    uVar52 = (int)fVar14 - 1;
    uVar52 = (((int)uVar52 >> 9) + (uint)((int)uVar52 < 0 && (uVar52 & 0x1ff) != 0)) * 0x200;
    if ((-1 < (int)uVar52) && (uStack_d8 = uVar9 & 0xfe00, (int)uVar52 <= (int)(uVar9 & 0xfe00))) {
      uStack_d8 = uVar52 & 0xfe00;
    }
    uVar52 = 0x40;
    if ((0x40 < uVar49) && (uVar52 = uVar10 & 0xffc0, (int)(uVar49 - uVar52) < 0x40)) {
      uVar52 = uVar52 - 0x40;
    }
    uStack_dc = 0;
    uVar38 = (int)fVar7 - 1;
    uVar38 = (((int)uVar38 >> 6) + (uint)((int)uVar38 < 0 && (uVar38 & 0x3f) != 0)) * 0x40;
    if ((-1 < (int)uVar38) && (uStack_dc = uVar52 & 0xffff, (int)uVar38 <= (int)uVar52)) {
      uStack_dc = uVar38 & 0xffc0;
    }
    uVar52 = 0x200;
    if (0x1ff < uStack_d8) {
      uVar52 = uStack_d8;
    }
    uVar38 = uVar50 - 1;
    uVar28 = (((int)uVar38 >> 9) + (uint)((int)uVar38 < 0 && (uVar38 & 0x1ff) != 0)) * 0x200;
    uVar38 = (uint)fVar23;
    if ((FLOAT_001aa0d4 < fVar23) &&
       ((float)((double)CONCAT44(0x43300000,uVar38 ^ 0x80000000) - DOUBLE_001aa1e0) < fVar23)) {
      uVar38 = uVar38 + 1;
    }
    if ((int)uVar38 <= (int)uVar28) {
      uVar28 = uVar38;
    }
    uStack_d0 = 1;
    if ((int)uVar52 < (int)uVar28) {
      uStack_d0 = (int)((uVar28 - uVar52) + 0xbff) / 0xc00 & 0xff;
    }
    uVar52 = 0x40;
    if (0x3f < uStack_dc) {
      uVar52 = uStack_dc;
    }
    uVar38 = uVar49 - 1;
    uVar28 = (((int)uVar38 >> 6) + (uint)((int)uVar38 < 0 && (uVar38 & 0x3f) != 0)) * 0x40;
    uVar38 = (uint)fVar13;
    if ((FLOAT_001aa0d4 < fVar13) &&
       ((float)((double)CONCAT44(0x43300000,uVar38 ^ 0x80000000) - DOUBLE_001aa1e0) < fVar13)) {
      uVar38 = uVar38 + 1;
    }
    if ((int)uVar38 <= (int)uVar28) {
      uVar28 = uVar38;
    }
    uStack_d4 = 1;
    if ((int)uVar52 < (int)uVar28) {
      uStack_d4 = (int)((uVar28 - uVar52) + 0xf7f) / 0xf80 & 0xff;
    }
    uVar52 = uStack_d4 * uStack_d0 & 0xff;
    iVar34 = uVar52 << 4;
  }
  if (bVar12) {
    iVar37 = 0x343;
  }
  else {
    iVar37 = 0x34e;
  }
  uVar39 = (**(code **)(param_1 + 0x2998))(iVar53,iVar35 + iVar37 + iVar34);
  *(undefined4 *)(param_1 + 0x298c) = uVar39;
  iVar34 = ((int (*)())FUN_00030840)(param_1,uVar39,param_2);
  puVar30 = *(uint **)(param_1 + 0x1d8);
  iVar37 = iVar34 + iVar51;
  *puVar30 = iVar37 - (int)puVar30 >> 2 | *puVar30;
  *(int *)(param_1 + 0x1d8) = iVar37;
  *(undefined4 *)(iVar34 + iVar51) = 0x32000000;
  *(int *)(iVar37 + 8) = iVar35;
  if (bVar12) {
    *(int *)(iVar37 + 0xc) = iVar33;
  }
  else {
    if (((*(uint *)(param_1 + 0x154) & 0x2000) == 0) ||
       ((uVar39 = 10, iVar33 != 7 && (uVar39 = 0xb, iVar33 != 8)))) {
      uVar39 = 4;
    }
    *(undefined4 *)(iVar37 + 0xc) = uVar39;
  }
  *(uint *)(iVar37 + 0x14) = uVar52;
  puVar26 = PTR_DAT_001e88d0;
  *(uint *)(iVar37 + 0x10) = param_4 | param_3 << 0x10;
  *(uint *)(iVar37 + 0x18) = CONCAT22(uVar10,uVar9);
  puVar30 = (uint *)(iVar37 + 0x310);
  _memcpy(iVar37 + 0x1c,puVar26,0x2f4);
  uVar27 = *(uint *)(iVar37 + 0x244);
  uVar38 = (*(uint *)(iVar32 + 0x18) & 0x18) << 5;
  *(uint *)(iVar37 + 0x244) = uVar38 | uVar27 & 0xfffffcff;
  uVar28 = (*(uint *)(iVar32 + 0x18) & 6) << 9;
  *(uint *)(iVar37 + 0x244) = uVar28 | uVar38 | uVar27 & 0xfffff0ff;
  uVar40 = *(uint *)(iVar32 + 0x1c) >> 0x12 & 0x3000;
  *(uint *)(iVar37 + 0x244) = uVar40 | uVar28 | uVar38 | uVar27 & 0xffffc0ff;
  uVar44 = *(uint *)(iVar32 + 0x1c) >> 0xe & 0xc000;
  *(uint *)(iVar37 + 0x244) = uVar44 | uVar40 | uVar28 | uVar38 | uVar27 & 0xffff00ff;
  *(uint *)(iVar37 + 0x244) =
       *(uint *)(iVar32 + 0x18) >> 5 & 0x1f |
       uVar44 | uVar40 | uVar28 | uVar38 | uVar27 & 0xffff00e0;
  sVar11 = *(short *)(iVar47 + 2);
  if ((((sVar11 != 0x1908) && (sVar11 != 0x1906)) && (sVar11 != 0x190a)) && (sVar11 != 0x1902)) {
    *(uint *)(iVar37 + 0x174) = *(uint *)(iVar37 + 0x174) & 0xfffe3fff | 0x18000;
  }
  iVar35 = param_2[0xd];
  if ((iVar35 == 0) || ((*(byte *)(iVar35 + 0x15) & 0x18) == 0)) {
    iVar34 = 0x20;
  }
  else {
    iVar34 = 0x20 / (1 << (*(uint *)(&DAT_001d9f4c + (uint)*(byte *)(param_2 + 0xe) * 0x24) >> 0x1c
                          & 3));
  }
  iVar34 = iVar34 >> (*(uint *)(iVar32 + 0x14) & 7);
  if ((iVar35 == 0) || (*(char *)(iVar35 + 0x16) != '\x06')) {
    uVar38 = 0;
    iVar35 = *param_2 + 0x40 + (param_3 * 0xd + param_4) * 0x20;
    iVar35 = param_7 * *(int *)(iVar35 + 0x14) + *(int *)(iVar35 + 8);
  }
  else {
    iVar35 = 0;
    uVar38 = *(uint *)(iVar32 + 0x18) >> 0xb & 0x180000;
  }
  if (*(char *)(param_2[0xc] + 0x6d) == '\0') {
    uVar28 = (uVar48 + iVar34) - 1 & -iVar34;
  }
  else {
    uVar28 = (uint)*(ushort *)((int)param_2 + 0x3e);
  }
  *(int *)(iVar37 + 0x284) = iVar35;
  iVar35 = param_2[0xd];
  if ((iVar35 != 0) && ((*(byte *)(iVar35 + 0x15) & 4) != 0)) {
    uVar40 = param_4 - *(byte *)(param_2[0xc] + 0x69);
    if ((*(byte *)(iVar35 + 0x15) & 0x18) == 0) {
      iVar33 = 1;
      iVar34 = 0x100;
    }
    else {
      iVar33 = 1 << (*(uint *)(&DAT_001d9f4c + (uint)*(byte *)(param_2 + 0xe) * 0x24) >> 0x1c & 3);
      iVar34 = 0x20 / iVar33 << 3;
    }
    if ((iVar34 <= *(int *)(*param_2 + 0xc) >> (uVar40 & 0x3f)) &&
       (iVar34 = 1, iVar33 << 3 <= (int)(uint)*(ushort *)(*param_2 + 0x16) >> (uVar40 & 0x3f)))
    goto LAB_00035dd8;
  }
  iVar34 = 0;
LAB_00035dd8:
  if (iVar35 != 0) {
    uVar40 = (*(byte *)(iVar35 + 0x15) & 0x18) << 0xe;
  }
  else {
    uVar40 = 0;
  }
  uVar44 = *(uint *)(iVar32 + 0x18);
  *(uint *)(iVar37 + 0x2e8) = uVar48 - 1 & 0x1fff | (uVar46 - 1) * 0x2000 & 0x3ffe000;
  *(uint *)(iVar37 + 0x28c) =
       uVar40 | uVar28 & 0x3ffe | iVar34 << 0x10 | uVar38 | (uVar44 & 0x3c00) << 0xb;
  if ((*(uint *)(iVar32 + 0x20) & 0x400000) != 0) {
    *(undefined4 *)(iVar37 + 0x94) = 0;
  }
  fVar16 = FLOAT_001aa12c;
  if (uVar52 == 0) {
    fVar7 = FLOAT_001aa0d4;
    if (uVar50 != 0) {
      fVar7 = FLOAT_001aa0e8 /
              (float)((double)CONCAT44(0x43300000,uVar50 ^ 0x80000000) - DOUBLE_001aa1e0);
    }
    fVar13 = FLOAT_001aa0d4;
    if (uVar49 != 0) {
      fVar13 = FLOAT_001aa0e8 /
               (float)((double)CONCAT44(0x43300000,uVar49 ^ 0x80000000) - DOUBLE_001aa1e0);
    }
    *puVar30 = 0x31080;
    *(undefined **)(iVar37 + 0x324) = ((unsigned char *)0x00001087U);
    *(float *)(iVar37 + 0x31c) = fVar7 * fVar6;
    *(float *)(iVar37 + 0x318) = fVar13 * (fVar8 * fVar2 + fVar5);
    *(float *)(iVar37 + 800) = fVar13 * (fVar17 * fVar2 + fVar5);
    *(float *)(iVar37 + 0x314) = fVar7 * fVar15;
    fVar2 = (fVar1 + fVar3) * FLOAT_001aa10c;
    fVar7 = (fVar17 + fVar8) * FLOAT_001aa10c;
    *(undefined4 *)(iVar37 + 0x32c) = 0xc0033500;
    *(undefined4 *)(iVar37 + 0x330) = 0x10031;
    *(float *)(iVar37 + 0x334) = fVar2;
    *(float *)(iVar37 + 0x338) = fVar7;
    *(int *)(iVar37 + 0x328) =
         (int)((fVar3 - fVar1) * fVar16) << 0x10 | (int)((fVar8 - fVar17) * fVar16);
    *(undefined4 *)(iVar37 + 0x33c) = 0;
    puVar30 = (uint *)(iVar37 + 0x340);
  }
  else {
    fVar1 = FLOAT_001aa0d4;
    if (fVar2 != FLOAT_001aa0d4) {
      fVar1 = FLOAT_001aa0e8 / fVar2;
    }
    if (uStack_d4 != 0) {
      uVar38 = 0;
      iVar35 = 0;
      uVar52 = uVar49 - uStack_dc;
      uVar48 = uStack_dc;
      do {
        if (uStack_d0 != 0) {
          iVar34 = 0;
          uVar44 = iVar35 + uStack_dc;
          uVar27 = uVar50 - uStack_d8;
          fVar8 = (float)((double)CONCAT44(0x43300000,uVar44 ^ 0x80000000) - DOUBLE_001aa1e0);
          uVar28 = uStack_d8;
          uVar40 = uStack_d0;
          do {
            *puVar30 = uVar28;
            puVar30[1] = uVar48;
            uVar29 = uVar27;
            if ((int)(uVar28 + 0x1000) <= (int)uVar50) {
              uVar29 = 0x1000;
            }
            uVar45 = uVar52;
            if ((int)(uVar44 + 0x1000) <= (int)uVar49) {
              uVar45 = 0x1000;
            }
            puVar30[2] = uVar29;
            puVar30[3] = uVar45;
            dVar25 = DOUBLE_001aa1e0;
            fVar2 = fVar14;
            if (iVar34 != 0) {
              fVar2 = (float)((double)CONCAT44(0x43300000,uVar28 + 0x200 ^ 0x80000000) -
                             DOUBLE_001aa1e0);
            }
            fVar3 = fVar7;
            if (uVar38 != 0) {
              fVar3 = (float)((double)CONCAT44(0x43300000,uVar44 + 0x40 ^ 0x80000000) -
                             DOUBLE_001aa1e0);
            }
            fVar6 = fVar23;
            if (iVar34 != uStack_d0 - 1) {
              fVar6 = (float)((double)CONCAT44(0x43300000,uVar28 + 0xe00 ^ 0x80000000) -
                             DOUBLE_001aa1e0);
            }
            fVar15 = fVar13;
            if (uVar38 != uStack_d4 - 1) {
              fVar15 = (float)((double)CONCAT44(0x43300000,uVar44 + 0xfc0 ^ 0x80000000) -
                              DOUBLE_001aa1e0);
            }
            fVar17 = fVar7;
            if (fVar7 - fVar3 < 0.0) {
              fVar17 = fVar3;
            }
            fVar16 = fVar15;
            if (fVar13 - fVar15 < 0.0) {
              fVar16 = fVar13;
            }
            fVar18 = fVar6;
            if (fVar23 - fVar6 < 0.0) {
              fVar18 = fVar23;
            }
            fVar19 = fVar14;
            if (fVar14 - fVar2 < 0.0) {
              fVar19 = fVar2;
            }
            if (-(fVar7 - fVar3) < 0.0) {
              fVar3 = fVar17;
            }
            if (-(fVar13 - fVar15) < 0.0) {
              fVar16 = fVar15;
            }
            if (-(fVar14 - fVar2) < 0.0) {
              fVar2 = fVar19;
            }
            if (-(fVar23 - fVar6) < 0.0) {
              fVar18 = fVar6;
            }
            fVar22 = fVar1 * fVar16 + fVar1 * -fVar5;
            fVar15 = fVar1 * fVar3 + fVar1 * -fVar5;
            fVar19 = fVar2 + -fVar4;
            fVar17 = fVar18 + -fVar4;
            fVar6 = fVar22;
            fVar24 = fVar16;
            if (fVar22 < fVar15) {
              fVar6 = fVar15;
              fVar15 = fVar22;
              fVar24 = fVar3;
              fVar3 = fVar16;
            }
            fVar16 = fVar19;
            fVar22 = fVar18;
            if (fVar17 < fVar19) {
              fVar16 = fVar17;
              fVar17 = fVar19;
              fVar22 = fVar2;
              fVar2 = fVar18;
            }
            fVar18 = FLOAT_001aa0d4;
            if (uVar29 != 0) {
              fVar18 = FLOAT_001aa0e8 /
                       (float)((double)CONCAT44(0x43300000,uVar29 ^ 0x80000000) - DOUBLE_001aa1e0);
            }
            fVar19 = FLOAT_001aa0d4;
            if (uVar45 != 0) {
              fVar19 = FLOAT_001aa0e8 /
                       (float)((double)CONCAT44(0x43300000,uVar45 ^ 0x80000000) - DOUBLE_001aa1e0);
            }
            uVar29 = uVar28 ^ 0x80000000;
            iVar34 = iVar34 + 1;
            uVar28 = uVar28 + 0xc00;
            uVar27 = uVar27 - 0xc00;
            fVar20 = (fVar17 - fVar16) * FLOAT_001aa12c;
            fVar21 = (fVar6 - fVar15) * FLOAT_001aa12c;
            fVar17 = (fVar17 + fVar16) * FLOAT_001aa10c;
            fVar6 = (fVar6 + fVar15) * FLOAT_001aa10c;
            puVar30[4] = 0x31080;
            puVar30[6] = (uint)(fVar19 * (fVar24 - fVar8));
            puVar30[8] = (uint)(fVar19 * (fVar3 - fVar8));
            puVar30[9] = (uint)((unsigned char *)0x00001087U);
            fVar3 = (float)((double)CONCAT44(0x43300000,uVar29) - dVar25);
            puVar30[7] = (uint)(fVar18 * (fVar22 - fVar3));
            puVar30[5] = (uint)(fVar18 * (fVar2 - fVar3));
            puVar30[0xb] = 0xc0033500;
            puVar30[0xc] = 0x10031;
            puVar30[0xd] = (uint)fVar17;
            puVar30[0xe] = (uint)fVar6;
            puVar30[10] = (int)fVar20 << 0x10 | (int)fVar21;
            puVar30[0xf] = 0;
            puVar30 = puVar30 + 0x10;
            uVar40 = uVar40 - 1;
          } while (uVar40 != 0);
        }
        uVar38 = uVar38 + 1;
        iVar35 = iVar35 + 0xf80;
        uVar52 = uVar52 - 0xf80;
        uVar48 = uVar48 + 0xf80;
      } while (uVar38 != uStack_d4);
    }
  }
  *(int *)(iVar37 + 4) = (int)puVar30 - iVar37 >> 2;
  puVar31 = *(uint **)(param_1 + 0x1d8);
  *puVar31 = (int)puVar30 - (int)puVar31 >> 2 | *puVar31;
  *(uint **)(param_1 + 0x1d8) = puVar30;
  *puVar30 = 0x33000000;
  if (bVar12) {
    uVar49 = 0;
  }
  else {
    uVar49 = 2;
  }
  puVar30[1] = uVar49;
  puVar30[2] = (uint)((unsigned char *)0x00001393U);
  puVar30[3] = 10;
  puVar30[4] = (uint)((unsigned char *)0x000013c6U);
  puVar30[5] = 3;
  puVar30[6] = 0x5c8;
  puVar30[7] = 0x20000;
  puVar30[8] = (uint)(*(unsigned char *)0x000010ea);
  uVar49 = *(uint *)(param_1 + 0x1cfc);
  puVar30[10] = (uint)((unsigned char *)0x000010faU);
  puVar30[9] = uVar49;
  uVar49 = *(uint *)(param_1 + 0x1da0);
  puVar30[0xc] = 0xc0001000;
  puVar30[0xe] = 0x11004;
  puVar30[0xb] = uVar49;
  puVar30[0xf] = *(uint *)(param_1 + 0x1ca8);
  uVar49 = *(uint *)(param_1 + 0x1cac);
  puVar30[0x11] = (uint)((unsigned char *)0x00001008U);
  puVar30[0x10] = uVar49;
  uVar49 = *(uint *)(param_1 + 0x1ca0);
  puVar30[0x13] = (uint)(*(unsigned char *)0x000010e9);
  puVar30[0x12] = uVar49;
  uVar49 = *(uint *)(param_1 + 0x1d20);
  puVar30[0x15] = (uint)((unsigned char *)0x000013c7U);
  puVar30[0x14] = uVar49;
  uVar49 = *(uint *)(param_1 + 0x1cf0);
  puVar30[0x17] = (uint)((unsigned char *)0x000013c1U);
  puVar30[0x16] = uVar49;
  uVar49 = *(uint *)(param_1 + 0x1ce4);
  puVar30[0x19] = 0x850;
  puVar30[0x18] = uVar49;
  puVar30[0x1a] = *(uint *)(param_1 + 0x1dc0);
  puVar30[0x1b] = 0x887;
  uVar49 = *(uint *)(param_1 + 0x1db4);
  puVar30[0xbd] = 0x82c;
  puVar30[0x1c] = uVar49;
  uVar49 = *(uint *)(0x00001dc4 + param_1);
  puVar30[0x1d] = (uint)((unsigned char *)0x000010aeU);
  puVar30[0xbe] = uVar49;
  uVar49 = *(uint *)(param_1 + 0x1d70);
  puVar30[0x1f] = (uint)((unsigned char *)0x00001394U);
  puVar30[0x1e] = uVar49;
  uVar49 = *(uint *)(param_1 + 0x1d30);
  puVar30[0x21] = (uint)((unsigned char *)0x00001380U);
  puVar30[0x23] = (uint)((unsigned char *)0x00001002U);
  puVar30[0x22] = 0;
  puVar30[0x20] = uVar49;
  puVar30[0x24] = *(uint *)(param_1 + 0x1d90);
  uVar49 = *(uint *)(param_1 + 0x1d90);
  puVar30[0x25] = 0x824;
  puVar30[0x24] = uVar49;
  uVar49 = *(uint *)(param_1 + 0x1ddc);
  puVar30[0x27] = 0x825;
  puVar30[0x26] = uVar49;
  uVar49 = *(uint *)(param_1 + 0x1de0);
  puVar30[0x29] = 0x82d;
  puVar30[0x28] = uVar49;
  uVar49 = *(uint *)(0x000026c8 + param_1 + 4);
  puVar30[0x2b] = 0x854;
  puVar30[0x2a] = uVar49;
  uVar49 = **(uint **)(param_1 + 0x2680);
  puVar30[0x2d] = 0x878;
  puVar30[0x2c] = uVar49;
  uVar49 = **(uint **)(param_1 + 0x2684);
  puVar30[0x2f] = (uint)((unsigned char *)0x000013c0U);
  puVar30[0x2e] = uVar49;
  uVar49 = *(uint *)(param_1 + 0x1ce0);
  puVar30[0x31] = (uint)((unsigned char *)0x000012f0U);
  puVar30[0x30] = uVar49;
  uVar49 = *(uint *)(param_1 + 0x1d2c);
  puVar30[0x32] = uVar49;
  if ((*(uint *)(&DAT_001d9f4c + (uint)(byte)((unsigned char *)0x00002b7f)[param_1] * 0x24) & 0x8000) == 0) {
    puVar30[0x32] = uVar49 & 0xfffffffe;
  }
  puVar30[0x33] = (uint)((unsigned char *)0x000012f5U);
  uVar49 = *(uint *)(param_1 + 0x1c8c);
  puVar30[0x34] = uVar49;
  if ((*(uint *)(&DAT_001d9f4c + (uint)(byte)((unsigned char *)0x00002b7f)[param_1] * 0x24) & 0x8000) == 0) {
    puVar30[0x34] = uVar49 & 0xfffff7ff;
  }
  puVar30[0x35] = (uint)((unsigned char *)0x000010a2U);
  uVar49 = *(uint *)(param_1 + 0x1d7c);
  puVar30[0x37] = (uint)((unsigned char *)0x00001381U);
  puVar30[0x36] = uVar49;
  uVar49 = *(uint *)(param_1 + 0x1cc0);
  puVar30[0x38] = uVar49;
  if ((*(uint *)(&DAT_001d9f4c + (uint)(byte)((unsigned char *)0x00002b7f)[param_1] * 0x24) & 0x4000) == 0) {
    puVar30[0x38] = uVar49 & 0xfffffffc;
  }
  puVar30[0x39] = (uint)((unsigned char *)0x0000109eU);
  uVar43 = 0xc0221000;
  uVar42 = 0xaaaa;
  uVar41 = 0x110f8;
  uVar39 = 0x31080;
  uVar49 = *(uint *)(param_1 + 0x1d6c);
  puVar30[0x3b] = (uint)((unsigned char *)0x00001096U);
  puVar30[0x3a] = uVar49;
  uVar49 = *(uint *)(param_1 + 0x1df8);
  puVar30[0x3d] = (uint)((unsigned char *)0x00001041U);
  puVar30[0x3a] = uVar49;
  uVar49 = *(uint *)(param_1 + 0x29f0);
  puVar30[0x3f] = (uint)((unsigned char *)0x00001046U);
  puVar30[0x3e] = uVar49;
  uVar49 = *(uint *)(param_1 + 0x1dfc);
  puVar30[0x41] = (uint)((unsigned char *)0x00001094U);
  puVar30[0x59] = (uint)((unsigned char *)0x00001095U);
  puVar30[0x43] = (uint)((unsigned char *)0x00001095U);
  puVar30[0x7f] = (uint)((unsigned char *)0x00001180U);
  puVar30[0x45] = (uint)((unsigned char *)0x00001095U);
  puVar30[0x47] = (uint)((unsigned char *)0x00001095U);
  puVar30[0x49] = (uint)((unsigned char *)0x00001095U);
  puVar30[0x40] = uVar49;
  puVar30[0x4b] = (uint)((unsigned char *)0x00001095U);
  puVar30[0x4d] = (uint)((unsigned char *)0x00001095U);
  puVar30[0x4f] = (uint)((unsigned char *)0x00001095U);
  puVar30[0x51] = (uint)((unsigned char *)0x00001095U);
  puVar30[0x53] = (uint)((unsigned char *)0x00001095U);
  puVar30[0x55] = (uint)((unsigned char *)0x00001095U);
  puVar30[0x57] = (uint)((unsigned char *)0x00001095U);
  puVar30[0x5b] = 0xc0221000;
  puVar30[0x42] = 0;
  puVar30[0x80] = 2;
  puVar30[0x81] = (uint)((unsigned char *)0x00001189U);
  puVar30[0x83] = (uint)((unsigned char *)0x00001181U);
  puVar30[0x85] = (uint)((unsigned char *)0x0000118dU);
  puVar30[0x87] = (uint)((unsigned char *)0x0000118eU);
  puVar30[0x89] = (uint)((unsigned char *)0x0000118cU);
  puVar30[0x8b] = (uint)((unsigned char *)0x000011a9U);
  uVar49 = *(uint *)(param_1 + 0x257c);
  puVar30[0x8d] = (uint)((unsigned char *)0x000011aaU);
  puVar30[0x8c] = uVar49;
  uVar49 = *(uint *)(param_1 + 0x2580);
  puVar30[0x8f] = (uint)((unsigned char *)0x000011abU);
  puVar30[0x8e] = uVar49;
  uVar49 = *(uint *)(param_1 + 0x2584);
  puVar30[0x91] = (uint)((unsigned char *)0x000011acU);
  puVar30[0x90] = uVar49;
  uVar49 = *(uint *)(param_1 + 0x2588);
  puVar30[0x93] = (uint)((unsigned char *)0x000010c0U);
  puVar30[0x92] = uVar49;
  uVar49 = *(uint *)(param_1 + 0x216c);
  puVar30[0x95] = (uint)((unsigned char *)0x000010c1U);
  puVar30[0x97] = (uint)((unsigned char *)0x000010c8U);
  puVar30[0x99] = (uint)((unsigned char *)0x0000101dU);
  puVar30[0x94] = uVar49;
  uVar49 = *(uint *)(param_1 + 0x2128);
  puVar30[0x9b] = (uint)((unsigned char *)0x0000138aU);
  puVar30[0x9d] = (uint)((unsigned char *)0x0000138eU);
  puVar30[0xa2] = 0;
  puVar30[0x9f] = (uint)((unsigned char *)0x00001040U);
  puVar30[0x9c] = 0;
  puVar30[0x9e] = 0;
  puVar30[0xa0] = 0;
  puVar30[0x9a] = uVar49;
  puVar30[0xa1] = (uint)(*(unsigned char *)0x00001150);
  puVar30[0xa3] = (uint)((unsigned char *)0x00001100U);
  uVar49 = *(uint *)(param_1 + 0x1f1c);
  puVar30[0xa5] = (uint)((unsigned char *)0x00001110U);
  puVar30[0xa4] = uVar49;
  puVar30[0xa6] = *(uint *)(param_1 + 0x1f5c);
  puVar30[0xa7] = (uint)(*(unsigned char *)0x00001120);
  uVar49 = *(uint *)(param_1 + 0x1f9c);
  puVar30[0xa9] = (uint)((unsigned char *)0x00001130U);
  puVar30[0xa8] = uVar49;
  uVar49 = *(uint *)(param_1 + 0x1fdc);
  puVar30[0xab] = (uint)((unsigned char *)0x00001140U);
  puVar30[0xaa] = uVar49;
  uVar49 = *(uint *)(param_1 + 0x201c);
  puVar30[0xad] = (uint)((unsigned char *)0x000010f4U);
  puVar30[0xae] = 0xaaaa;
  puVar30[0xaf] = (uint)((unsigned char *)0x00001383U);
  puVar30[0xac] = uVar49;
  uVar49 = *(uint *)(param_1 + 0x1d34);
  puVar30[0xb1] = (uint)((unsigned char *)0x00001386U);
  puVar30[0xb0] = uVar49;
  uVar49 = *(uint *)(param_1 + 0x1d38);
  puVar30[0xb3] = 0x110f8;
  puVar30[0xb2] = uVar49;
  puVar30[0xb4] = *(uint *)(param_1 + 0x1d98);
  uVar50 = *(uint *)(param_1 + 0x1d50);
  puVar30[0xb6] = (uint)((unsigned char *)0x00001087U);
  puVar30[0xb5] = uVar50;
  uVar49 = *(uint *)(param_1 + 0x1f0c);
  puVar30[0xb8] = 0x31080;
  puVar30[0xb7] = uVar49;
  puVar30[0xb9] = *(uint *)(param_1 + 0x1efc);
  puVar30[0xba] = *(uint *)(param_1 + 0x1f04);
  puVar30[0xbb] = *(uint *)(param_1 + 0x1f00);
  puVar30[0xbc] = *(uint *)(param_1 + 0x1f08);
  FUN_0004c100(puVar30 + 2,iVar53);
  puVar31 = puVar30 + 0xbf;
  if (!bVar12) {
    puVar30[0xbf] = (uint)((unsigned char *)0x000013c4U);
    puVar30[0xc1] = 0x113c8;
    puVar30[200] = (uint)((unsigned char *)0x000013caU);
    puVar30[0xc4] = (uint)((unsigned char *)0x000013cdU);
    puVar30[0xc6] = (uint)((unsigned char *)0x000013ccU);
    puVar31 = puVar30 + 0xca;
  }
  uVar36 = ((int (*)())FUN_000308c0)(param_1,puVar31);
  *(undefined4 *)(param_1 + 0x298c) = uVar36;
  (**(code **)(param_1 + 0x299c))(iVar53,uVar36);
  _pthread_mutex_unlock(*(undefined4 *)(param_1 + 0xc));
  if ((((*(uint *)(param_1 + 0x24) & 0x82) != 0) && (param_2[0xd] != 0)) &&
     (*(char *)(param_2[0xd] + 0x16) == '\x06')) {
    iVar34 = iVar47 + 0xa0 + (uint)*(byte *)(iVar47 + 0x5e) * 0x18;
    uVar9 = *(ushort *)(iVar34 + 0xc);
    iVar35 = FUN_0000a3f0((uint)*(ushort *)(iVar34 + 0x10),(uint)*(ushort *)(iVar34 + 0x12));
    if (*(int *)(iVar34 + 0x14) != 0) {
      FUN_0000b670(param_1,*(int *)(iVar34 + 0x14),(uint)uVar9 * iVar35 * uVar46,uVar39,uVar41,
                   uVar42,uVar50,uVar43);
    }
  }
  if (((*(uint *)(param_2[0xc] + 0x48) & 0x8000) != 0) &&
     (param_4 == *(byte *)(param_2[0xc] + 0x5e))) {
    ((int (*)())FUN_00034200)(param_1,param_2,param_3,uVar39,uVar41);
    return 1;
  }
  return 1;
}

/* FUN_000369f0 @ 0x369f0 (9972 bytes) */
int FUN_000369f0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13, param_14, param_15)
  int param_1;
  int *param_2;
  int param_3;
  uint param_4;
  uint param_5;
  uint param_6;
  int param_7;
  uint param_8;
  uint param_9;
  int param_10;
  int param_11;
  undefined *param_12;
  uint param_13;
  undefined4 param_14;
  undefined4 *param_15;
{
  bool bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  short sVar8;
  ushort uVar9;
  ushort uVar10;
  short sVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  byte bVar19;
  int iVar20;
  uint uVar21;
  int iVar22;
  uint *puVar23;
  uint uVar24;
  undefined *puVar25;
  uint uVar26;
  int iVar27;
  undefined4 uVar28;
  uint *puVar29;
  undefined4 *puVar30;
  undefined *a2;
  undefined4 uVar31;
  int iVar32;
  uint *puVar33;
  int iVar34;
  uint uVar35;
  int *piVar36;
  uint *puVar37;
  uint *puVar38;
  int iVar39;
  undefined4 *puVar40;
  undefined *puVar41;
  uint uVar42;
  int iVar43;
  uint uVar44;
  int iVar45;
  char in_RESERVE;
  byte bVar46;
  uint uStack_248;
  int iStack_244;
  uint uStack_240;
  uint *puStack_23c;
  uint uStack_238;
  uint uStack_234;
  uint uStack_230;
  uint *puStack_22c;
  uint uStack_228;
  uint uStack_224;
  uint uStack_220;
  undefined4 uStack_21c;
  uint uStack_218;
  undefined *puStack_214;
  uint uStack_210;
  uint uStack_20c;
  undefined4 uStack_208;
  undefined4 uStack_204;
  undefined1 uStack_1d0;
  undefined4 uStack_1c8;
  uint uStack_1c4;
  undefined4 uStack_1c0;
  uint uStack_1bc;
  undefined4 uStack_1b8;
  uint uStack_1b4;
  undefined4 uStack_1b0;
  uint uStack_1ac;
  undefined4 uStack_1a8;
  uint uStack_1a4;
  undefined4 uStack_1a0;
  uint uStack_19c;
  longlong lStack_198;
  longlong lStack_190;
  longlong lStack_188;
  longlong lStack_180;
  longlong lStack_178;
  longlong lStack_170;
  longlong lStack_168;
  longlong lStack_160;
  longlong lStack_158;
  longlong lStack_150;
  undefined4 uStack_148;
  uint uStack_144;
  undefined4 uStack_140;
  uint uStack_13c;
  longlong lStack_138;
  undefined4 uStack_130;
  uint uStack_12c;
  undefined4 uStack_128;
  uint uStack_124;
  longlong lStack_120;
  uint uStack_118;
  int iStack_114;
  int iStack_110;
  uint *puStack_10c;
  uint uStack_108;
  uint uStack_104;
  uint uStack_100;
  int *piStack_fc;
  uint uStack_f8;
  int iStack_f4;
  uint uStack_f0;
  uint uStack_ec;
  uint uStack_e8;
  int iStack_e4;
  uint uStack_e0;
  int iStack_dc;
  int iStack_d8;
  code *pcStack_d4;
  code *pcStack_d0;
  int iStack_cc;
  int *piStack_c8;
  uint *puStack_c4;
  uint **ppuStack_c0;
  uint *puStack_bc;
  uint *puStack_b8;
  uint *puStack_b4;
  code *pcStack_b0;
  uint uStack_ac;
  code *pcStack_a8;
  int iStack_a4;
  uint uStack_a0;
  int iStack_9c;
  
  if (param_15 == (undefined4 *)0x0) {
    uVar42 = param_6;
    _pthread_mutex_lock(*(undefined4 *)(param_1 + 0xc));
    uVar44 = 0;
    iVar43 = param_3;
    uVar26 = param_4;
    iVar39 = ((int (*)())FUN_00031220)(param_1,param_2,param_3,param_4,0);
    if ((iVar39 != 0) &&
       ((iVar22 = param_2[0xd], iVar22 == 0 || (*(char *)(iVar22 + 0x16) != '\x06')))) {
      if ((*(byte *)((int)param_2 + 0x39) & 7) != 0) {
        iVar43 = ((int (*)())FUN_00032100)(param_1,param_2,iVar43,uVar26,uVar44,uVar42);
        if (iVar43 == 0) goto LAB_00037930;
        iVar22 = param_2[0xd];
      }
      if (*(char *)(iVar22 + 0x16) != '\x06') {
        uVar42 = *(uint *)(iVar39 + 0x14) & 7;
        uVar24 = (param_8 << uVar42) + 0x23 & 0xffffffe0;
        if ((((param_10 == 1) && ((int)param_8 < 0x1001)) &&
            ((0x800 >= (int)param_8 || (uVar42 < 4)))) && ((*(uint *)(iVar39 + 0x14) & 8) == 0)) {
          iVar43 = param_1 + 0x240;
          uVar28 = (**(code **)(param_1 + 0x2998))(iVar43,0xe0);
          *(undefined4 *)(param_1 + 0x298c) = uVar28;
          uVar28 = ((int (*)())FUN_00030840)(param_1,uVar28,param_2);
          *(undefined4 *)(param_1 + 0x298c) = uVar28;
          (**(code **)(param_1 + 0x299c))(iVar43,uVar28);
          uStack_e0 = 0x1e000 / uVar24;
          uVar42 = ((int (*)())FUN_0002f7c0)(param_11,param_12);
          if ((uVar42 == *(byte *)(param_2 + 0xe)) && ((*(uint *)(iVar39 + 0x14) & 7) < 3)) {
            uStack_118 = 0x10000 / uVar24;
            if (0 < (int)param_9) {
              iStack_a4 = param_4 * 0x18;
              iStack_cc = param_3 * 0x168;
              uStack_ac = param_4 & 0xffff;
              iStack_dc = (param_3 * 0xd + param_4) * 0x20;
              puStack_c4 = &uStack_240;
              piStack_c8 = &iStack_244;
              uStack_a0 = param_3 << 0x10;
              iStack_e4 = 0;
              puStack_bc = &uStack_238;
              do {
                iStack_114 = iStack_e4 + uStack_118;
                bVar1 = (int)param_9 <= iStack_114;
                if ((int)param_9 < iStack_114) {
                  uStack_ec = param_9 - iStack_e4;
                }
                else {
                  uStack_ec = uStack_118;
                }
                iStack_d8 = uVar24 * uStack_ec;
                puVar23 = *(uint **)(param_1 + 500);
                uVar26 = *(uint *)(iVar39 + 0x18) >> 0x1e ^ 2;
                if (*(undefined1 **)(param_1 + 0x1f8) <=
                    (undefined1 *)((int)puVar23 + iStack_d8 + 0x80)) {
                  iStack_244 = 2;
                  uVar44 = *(int *)(param_1 + 0x204) + 1;
                  *(uint *)(param_1 + 0x204) = uVar44;
                  if (2 < uVar44) {
                    if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
                      FUN_0001a0f0(param_1,0x1000000);
                      puVar23 = *(uint **)(param_1 + 500);
                    }
                    *(undefined4 *)(param_1 + 0x204) = 1;
                  }
                  *(int *)(*(int *)(param_1 + 0x208) + 0xc) =
                       (int)puVar23 - *(int *)(param_1 + 0x1fc) >> 2;
                  _io_connect_method_scalarI_scalarO
                            (*(undefined4 *)(param_1 + 4),0x12,0,0,&puStack_23c,piStack_c8);
                  uVar44 = *(uint *)(0x000026c8 + param_1);
                  *(uint **)(param_1 + 0x1fc) = puStack_23c;
                  *(uint **)(param_1 + 500) = puStack_23c;
                  *(undefined1 **)(param_1 + 0x1f8) =
                       (undefined1 *)((int)puStack_23c + (uStack_238 & 0xfffffffc));
                  uVar28 = *(undefined4 *)(*(int *)(param_1 + 0x208) + 8);
                  *(uint *)(0x000026c8 + param_1) = uVar44 | 1;
                  *(undefined4 *)(param_1 + 0x200) = uVar28;
                  puVar23 = puStack_23c;
                }
                uStack_1d0 = 0;
                puStack_22c = (uint *)((uint)((int)puVar23 + 0x7f) & 0xffffff80);
                *(uint **)(param_1 + 500) = puStack_22c;
                uStack_21c = 2;
                uStack_20c = uStack_ec;
                uStack_234 = *(uint *)(iVar39 + 0x10) >> 0x1b;
                uStack_204 = 0;
                uStack_208 = 0;
                puStack_214 = (undefined *)0x0;
                uStack_218 = 0;
                uStack_230 = *(uint *)(iVar39 + 0x10) >> 0x16 & 0x1f;
                if ((char)param_14 == '\0') {
                  iVar22 = *(int *)(param_1 + 0x10);
                  puVar25 = ((unsigned char *)0x00002e6c) + iVar22;
                  if (((unsigned char *)0x00002e84)[iVar22] != '\0') {
                    uStack_218 = 1;
                    if (param_12 < (undefined *)0x8037) {
                      if (param_12 < (undefined *)0x8035) {
                        if (((unsigned char *)0x00001406) < param_12) {
                          if ((param_12 != ((unsigned char *)0x0000140b)) &&
                             ((param_12 < ((unsigned char *)0x0000140b) || (param_12 < (undefined *)0x8033))))
                          goto LAB_00037c1c;
                        }
                        else {
                          if (((unsigned char *)0x00001404) < param_12) goto LAB_00037c68;
                          if (param_12 != ((unsigned char *)0x00001403)) goto LAB_00037c1c;
                        }
                        goto LAB_00037c60;
                      }
LAB_00037c68:
                      uVar44 = 2;
                    }
                    else {
                      if (param_12 < (undefined *)0x8369) {
                        if ((undefined *)0x8366 < param_12) goto LAB_00037c68;
                        if (param_12 < (undefined *)0x8363) goto LAB_00037c1c;
                      }
                      else if ((undefined *)((int)((unsigned char *)0x0) + 1) < param_12 + -0x85ba) {
LAB_00037c1c:
                        uVar44 = 0;
                        goto LAB_00037c6c;
                      }
LAB_00037c60:
                      uVar44 = 1;
                    }
LAB_00037c6c:
                    uVar26 = uVar26 ^ uVar44;
                  }
                  if (((unsigned char *)0x00002e85)[iVar22] != '\0') {
                    uStack_218 = uStack_218 | 4;
                  }
                }
                else {
                  puVar25 = (undefined *)0x0;
                }
                a2 = param_12;
                uStack_228 = uVar24;
                uStack_224 = uStack_234;
                uStack_220 = uStack_230;
                uStack_210 = param_8;
                puStack_10c = puStack_22c;
                FUN_0000a6e0(param_1,param_11,param_12,param_8,param_9,puStack_bc,puStack_c4,
                             piStack_c8,puVar25);
                uVar44 = uStack_238;
                puStack_23c = (uint *)(param_13 + iStack_244 + iStack_e4 * uStack_238);
                if (uVar26 == 2) {
                  a2 = (undefined *)(uStack_240 * uStack_210);
                  if (0 < (int)uStack_20c) {
                    puVar23 = puStack_23c;
                    puVar29 = puStack_22c;
                    uVar26 = uStack_20c;
                    do {
                      uVar26 = uVar26 - 1;
                      if (0 < (int)a2) {
                        iVar22 = ((uint)(a2 + -1) >> 2) + 1;
                        puVar33 = puVar23;
                        puVar37 = puVar29;
                        if ((int)(a2 + -4) < -3) {
                          iVar22 = 1;
                        }
                        do {
                          uVar44 = *puVar33;
                          puVar33 = puVar33 + 1;
                          *puVar37 = uVar44 >> 0x18 | uVar44 >> 8 & 0xff00 | (uVar44 & 0xff00) << 8
                                     | uVar44 << 0x18;
                          puVar37 = puVar37 + 1;
                          iVar22 = iVar22 + -1;
                        } while (iVar22 != 0);
                      }
                      puVar23 = (uint *)((int)puVar23 + uStack_238);
                      puVar29 = (uint *)((int)puVar29 + uStack_228);
                    } while (0 < (int)uVar26);
                  }
                }
                else if (uVar26 == 3) {
                  iVar22 = uStack_240 * uStack_210;
                  if (0 < (int)uStack_20c) {
                    puVar23 = puStack_23c;
                    puVar29 = puStack_22c;
                    uVar26 = uStack_20c;
                    do {
                      uVar26 = uVar26 - 1;
                      if (0 < iVar22) {
                        iVar45 = (iVar22 - 1U >> 2) + 1;
                        puVar33 = puVar23;
                        puVar37 = puVar29;
                        if (iVar22 + -4 < -3) {
                          iVar45 = 1;
                        }
                        do {
                          uVar44 = *puVar33;
                          puVar33 = puVar33 + 1;
                          *puVar37 = uVar44 << 0x10 | uVar44 >> 0x10;
                          puVar37 = puVar37 + 1;
                          iVar45 = iVar45 + -1;
                        } while (iVar45 != 0);
                      }
                      puVar23 = (uint *)((int)puVar23 + uStack_238);
                      puVar29 = (uint *)((int)puVar29 + uStack_228);
                    } while (0 < (int)uVar26);
                  }
                }
                else if (uVar26 == 1) {
                  iVar22 = uStack_240 * uStack_210;
                  if (0 < (int)uStack_20c) {
                    puVar23 = puStack_23c;
                    puVar29 = puStack_22c;
                    uVar26 = uStack_20c;
                    do {
                      uVar26 = uVar26 - 1;
                      if (0 < iVar22) {
                        iVar45 = (iVar22 - 1U >> 1) + 1;
                        puVar33 = puVar23;
                        puVar37 = puVar29;
                        if (iVar22 + -2 < -1) {
                          iVar45 = 1;
                        }
                        do {
                          uVar9 = *(ushort *)puVar33;
                          puVar33 = (uint *)((int)puVar33 + 2);
                          *(ushort *)puVar37 = uVar9 >> 8 | uVar9 << 8;
                          puVar37 = (uint *)((int)puVar37 + 2);
                          iVar45 = iVar45 + -1;
                        } while (iVar45 != 0);
                      }
                      puVar23 = (uint *)((int)puVar23 + uStack_238);
                      puVar29 = (uint *)((int)puVar29 + uStack_228);
                    } while (0 < (int)uVar26);
                  }
                }
                else {
                  puVar25 = (undefined *)(uStack_240 * uStack_210);
                  uStack_f0 = uStack_228;
                  puVar23 = puStack_23c;
                  puVar29 = puStack_22c;
                  uVar26 = uStack_20c;
                  if ((int)puVar25 < 0x11) {
                    while (0 < (int)uVar26) {
                      puVar33 = puVar23;
                      puVar37 = puVar29;
                      puVar41 = puVar25;
                      if ((((uint)puVar29 & 1) != 0) && (puVar25 != (undefined *)0x0)) {
                        *(undefined1 *)puVar29 = *(undefined1 *)puVar23;
                        puVar33 = (uint *)((int)puVar23 + 1);
                        puVar37 = (uint *)((int)puVar29 + 1);
                        puVar41 = puVar25 + -1;
                      }
                      if ((((uint)puVar37 & 2) != 0) && ((undefined *)0x1 < puVar41)) {
                        uVar9 = *(ushort *)puVar33;
                        puVar41 = puVar41 + -2;
                        puVar33 = (uint *)((int)puVar33 + 2);
                        *(ushort *)puVar37 = uVar9;
                        puVar37 = (uint *)((int)puVar37 + 2);
                      }
                      if ((undefined *)0x3 < puVar41) {
                        iVar45 = 0;
                        iVar22 = ((uint)(puVar41 + -4) >> 2) + 1;
                        do {
                          puVar41 = puVar41 + -4;
                          *(undefined4 *)((int)puVar37 + iVar45) =
                               *(undefined4 *)((int)puVar33 + iVar45);
                          iVar45 = iVar45 + 4;
                          iVar22 = iVar22 + -1;
                        } while (iVar22 != 0);
                        puVar37 = (uint *)((int)puVar37 + iVar45);
                        puVar33 = (uint *)((int)puVar33 + iVar45);
                      }
                      if ((undefined *)0x1 < puVar41) {
                        uVar9 = *(ushort *)puVar33;
                        puVar41 = puVar41 + -2;
                        puVar33 = (uint *)((int)puVar33 + 2);
                        *(ushort *)puVar37 = uVar9;
                        puVar37 = (uint *)((int)puVar37 + 2);
                      }
                      if (puVar41 != (undefined *)0x0) {
                        *(undefined1 *)puVar37 = *(undefined1 *)puVar33;
                      }
                      puVar23 = (uint *)((int)puVar23 + uStack_238);
                      puVar29 = (uint *)((int)puVar29 + uStack_228);
                      uVar26 = uVar26 - 1;
                    }
                  }
                  else {
                    for (; 0 < (int)uVar26; uVar26 = uVar26 - 1) {
                      a2 = puVar25;
                      _memcpy(puVar29,puVar23,puVar25);
                      puVar23 = (uint *)((int)puVar23 + uVar44);
                      puVar29 = (uint *)((int)puVar29 + uStack_f0);
                    }
                  }
                }
                iVar22 = (int)puStack_10c - *(int *)(param_1 + 0x1fc);
                *(int *)(param_1 + 500) = (int)puStack_10c + iStack_d8;
                puVar30 = (undefined4 *)
                          (**(code **)(param_1 + 0x2998))(iVar43,0x2a,a2,puStack_10c,iStack_d8);
                uVar42 = 0;
                *(undefined4 **)(param_1 + 0x298c) = puVar30;
                puVar23 = *(uint **)(param_1 + 0x1d8);
                *puVar23 = (int)puVar30 - (int)puVar23 >> 2 | *puVar23;
                *(undefined4 **)(param_1 + 0x1d8) = puVar30;
                puVar30[2] = uStack_a0 | uStack_ac;
                *puVar30 = 0x44000000;
                puVar30[1] = 0x2a;
                uVar28 = *(undefined4 *)(param_1 + 0x200);
                puVar30[9] = 0xd07;
                puVar30[4] = iVar22;
                puVar30[5] = ((unsigned char *)0x00001393U);
                puVar30[3] = uVar28;
                puVar30[6] = 10;
                puVar30[7] = 0x5c8;
                puVar30[8] = 0x20000;
                puVar30[0xb] = 0xc0001000;
                puVar30[0xc] = 0;
                puVar30[10] = 0xffffffff;
                puVar30[0xd] = 0x51b;
                uVar26 = *(uint *)(iVar39 + 0x18);
                puVar30[0xf] = 0x56b;
                puVar30[0x11] = 0x56c;
                puVar30[0x10] = 0;
                puVar30[0x13] = 0x5c1;
                puVar30[0x12] = uVar24;
                puVar30[0x14] = 0;
                puVar30[0x15] = 0x501;
                puVar30[0xe] = uVar26 >> 0xf & 0xf00 | 0x2cc30fb;
                if ((param_2[0xd] == 0) || (*(char *)(param_2[0xd] + 0x16) != '\x06')) {
                  iVar22 = *param_2 + 0x40 + iStack_dc;
                  puVar30[0x16] = param_7 * *(int *)(iVar22 + 0x14) + *(int *)(iVar22 + 8);
                }
                else {
                  puVar30[0x16] = 0;
                }
                iVar22 = iStack_a4 + iStack_cc + param_2[0xc];
                uVar9 = *(ushort *)(iVar22 + 0xa6);
                uVar44 = (uint)uVar9;
                uVar10 = *(ushort *)(iVar22 + 0xa4);
                if (*(char *)(param_2[0xc] + 0x6d) == '\0') {
                  if ((param_2[0xd] == 0) || ((*(byte *)(param_2[0xd] + 0x15) & 0x18) == 0)) {
                    iVar22 = 0x20;
                  }
                  else {
                    iVar22 = 0x20 / (1 << (*(uint *)(&DAT_001d9f4c +
                                                    (uint)*(byte *)(param_2 + 0xe) * 0x24) >> 0x1c &
                                          3));
                  }
                  uVar26 = *(uint *)(iVar39 + 0x14) & 7;
                  iVar22 = iVar22 >> uVar26;
                  iVar22 = (((uint)uVar10 + iVar22) - 1 & -iVar22) << uVar26;
                }
                else {
                  iVar22 = (uint)*(ushort *)((int)param_2 + 0x3e) << (*(uint *)(iVar39 + 0x14) & 7);
                }
                puVar30[0x18] = iVar22;
                uVar26 = 0;
                puVar30[0x17] = 0x502;
                puVar30[0x19] = 0x5c0;
                if (param_2[0xd] != 0) {
                  bVar46 = *(byte *)(param_2[0xd] + 0x15);
                  bVar19 = bVar46 >> 3;
                  uVar26 = (bVar19 & 3) << 1;
                  if ((bVar46 & 4) != 0) {
                    uVar42 = param_4 - *(byte *)(param_2[0xc] + 0x69);
                    if ((bVar19 & 3) == 0) {
                      iVar45 = 1;
                      iVar22 = 0x100;
                    }
                    else {
                      iVar45 = 1 << (*(uint *)(&DAT_001d9f4c + (uint)*(byte *)(param_2 + 0xe) * 0x24
                                              ) >> 0x1c & 3);
                      iVar22 = 0x20 / iVar45 << 3;
                    }
                    if ((iVar22 <= *(int *)(*param_2 + 0xc) >> (uVar42 & 0x3f)) &&
                       (iVar45 << 3 <= (int)(uint)*(ushort *)(*param_2 + 0x16) >> (uVar42 & 0x3f)))
                    {
                      uVar26 = uVar26 | 1;
                    }
                  }
                }
                puVar30[0x1a] = uVar26;
                puVar30[0x1b] = 0x5bb;
                puVar30[0x1d] = 0x5bc;
                puVar30[0x1e] = CONCAT22(uVar9,uVar10);
                puVar30[0x1c] = 0;
                uVar26 = *(uint *)(iVar39 + 0x18) >> 0x17 & 0x1f;
                if ((uVar26 < 3) || ((iVar22 = 1, 4 < uVar26 && (iVar22 = 2, uVar26 != 6)))) {
                  iVar22 = 0;
                }
                uVar35 = (*(uint *)(iVar39 + 0x14) & 7) - iVar22;
                uVar26 = 0;
                uVar21 = (iStack_e4 + param_6) * 0x10000 | param_5 << (uVar35 & 0x3f) & 0xffff;
                puVar30[0x24] = 0xd0b;
                puVar30[0x22] = uStack_ec << 0x10 | param_8 << (uVar35 & 0x3f) & 0xffff;
                puVar30[0x1f] = 0x50e;
                puVar30[0x20] = uVar21;
                puVar30[0x21] = 0x50f;
                puVar30[0x23] = 0x80000000;
                puVar30[0x26] = 0x5c8;
                puVar30[0x29] = 0;
                puVar30[0x25] = 5;
                puVar30[0x28] = ((unsigned char *)0x00001040U);
                puVar30[0x27] = 0x10000;
                *(undefined4 **)(param_1 + 0x298c) = puVar30 + 0x2a;
                (**(code **)(param_1 + 0x299c))
                          (iVar43,puVar30 + 0x2a,a2,0,uVar44,uVar42,uVar21,puVar30 + 0x24);
                if (bVar1) break;
                iStack_e4 = iStack_114;
              } while( true );
            }
          }
          else if (0 < (int)param_9) {
            uStack_12c = param_5 ^ 0x80000000;
            uStack_124 = param_8 + param_5 ^ 0x80000000;
            uStack_128 = 0x43300000;
            uStack_130 = 0x43300000;
            pcStack_a8 = FUN_001d6a08;
            iStack_9c = 0x1e6a08;
            iStack_a4 = param_4 * 0x18;
            iStack_cc = param_3 * 0x168;
            iStack_f4 = (param_3 * 0xd + param_4) * 0x20;
            uStack_104 = param_8 - 1 & 0x7ff;
            uStack_100 = param_4 | param_3 << 0x10;
            puStack_c4 = &uStack_240;
            puStack_b8 = &uStack_234;
            piStack_c8 = &iStack_244;
            ppuStack_c0 = &puStack_23c;
            puStack_bc = &uStack_238;
            pcStack_d0 = FUN_001d6a08;
            puStack_b4 = &uStack_230;
            pcStack_d4 = FUN_001d6a08;
            pcStack_b0 = FUN_001d6a08;
            fVar4 = (float)((double)CONCAT44(0x43300000,uStack_12c) - 4503601774854144.0);
            fVar5 = (float)((double)CONCAT44(0x43300000,uStack_124) - 4503601774854144.0);
            iVar22 = (int)((fVar5 - fVar4) * 6.0);
            lStack_120 = (longlong)iVar22;
            uStack_108 = iVar22 << 0x10;
            iVar22 = 0;
            do {
              iStack_110 = iVar22 + uStack_e0;
              bVar1 = iStack_110 < (int)param_9;
              uVar42 = uStack_e0;
              if ((int)param_9 < iStack_110) {
                uVar42 = param_9 - iVar22;
              }
              uVar26 = (param_8 << (*(uint *)(iVar39 + 0x14) & 7)) + 0x23 & 0xffffffe0;
              puVar30 = (undefined4 *)
                        (**(code **)(param_1 + 0x2998))(iVar43,(uVar26 * uVar42 >> 2) + 0x193);
              piStack_fc = puVar30 + 1;
              *(undefined4 **)(param_1 + 0x298c) = puVar30;
              puVar23 = *(uint **)(param_1 + 0x1d8);
              uVar28 = *(undefined4 *)(iStack_9c + 0x1ec8);
              iVar45 = iStack_a4 + iStack_cc + param_2[0xc];
              uStack_f8 = (uint)*(ushort *)(iVar45 + 0xa6);
              uVar9 = *(ushort *)(iVar45 + 0xa4);
              *puVar23 = (int)puVar30 - (int)puVar23 >> 2 | *puVar23;
              *(undefined4 **)(param_1 + 0x1d8) = puVar30;
              *puVar30 = 0x35000000;
              puVar30[2] = uStack_100;
              _memcpy(puVar30 + 3,uVar28,0x2f4);
              uVar44 = *(uint *)(iVar39 + 0x18);
              puVar30[0xa9] = (uVar42 - 1) * 0x800 & 0x3ff800 | uStack_104 | 0x80000000;
              puVar30[0xa3] = uVar44 >> 0x1e | puVar30[0xa3] & 0xfffffffc;
              uVar44 = *(uint *)(((unsigned char *)0x00003c14) +
                                (int)(pcStack_d0 + (*(uint *)(iVar39 + 0x14) & 7) * 4));
              puVar30[0xab] = uVar44 & 0x1f | 0xa600;
              uVar24 = *(uint *)(iVar39 + 0x14);
              if ((uVar24 & 7) == 0) {
                puVar30[0xab] = uVar44 & 0x1f | 0x8600;
                uVar24 = *(uint *)(iVar39 + 0x14);
              }
              puVar30[0xad] =
                   (uint)(0x800 < (int)uVar42) << 0x10 |
                   (uint)(0x800 < (int)param_8) << 0xf | (uVar26 >> (uVar24 & 7)) - 1 & 0x3fff;
              puVar30[0x8d] =
                   *(uint *)(pcStack_d4 + (*(uint *)(iVar39 + 0x14) & 7) * 4 + 0x3c00) & 0x1f |
                   puVar30[0x8d] & 0xffffffe0;
              iVar45 = param_2[0xd];
              if ((iVar45 == 0) || ((*(byte *)(iVar45 + 0x15) & 0x18) == 0)) {
                iVar27 = 0x20;
              }
              else {
                iVar27 = 0x20 / (1 << (*(uint *)(((unsigned char *)0x00003544) +
                                                (int)(pcStack_a8 +
                                                     (uint)*(byte *)(param_2 + 0xe) * 0x24)) >> 0x1c
                                      & 3));
              }
              iVar27 = iVar27 >> (*(uint *)(iVar39 + 0x14) & 7);
              if ((iVar45 == 0) || (*(char *)(iVar45 + 0x16) != '\x06')) {
                uVar44 = 0;
                iVar45 = *param_2 + 0x40 + iStack_f4;
                iVar45 = param_7 * *(int *)(iVar45 + 0x14) + *(int *)(iVar45 + 8);
              }
              else {
                iVar45 = 0;
                uVar44 = *(uint *)(iVar39 + 0x18) >> 0xb & 0x180000;
              }
              puVar30[0x9d] = iVar45;
              if (*(char *)(param_2[0xc] + 0x6d) != '\0') {
                uVar9 = *(ushort *)((int)param_2 + 0x3e);
              }
              iVar45 = param_2[0xd];
              uVar24 = ((uint)uVar9 + iVar27) - 1 & -iVar27;
              if ((iVar45 == 0) || ((*(byte *)(iVar45 + 0x15) & 4) == 0)) {
LAB_00038698:
                iVar27 = 0;
              }
              else {
                uVar35 = param_4 - *(byte *)(param_2[0xc] + 0x69);
                if ((*(byte *)(iVar45 + 0x15) & 0x18) == 0) {
                  iVar20 = 1;
                  iVar27 = 0x100;
                }
                else {
                  iVar20 = 1 << (*(uint *)(((unsigned char *)0x00003544) +
                                          (int)(pcStack_a8 + (uint)*(byte *)(param_2 + 0xe) * 0x24))
                                 >> 0x1c & 3);
                  iVar27 = 0x20 / iVar20 << 3;
                }
                if ((*(int *)(*param_2 + 0xc) >> (uVar35 & 0x3f) < iVar27) ||
                   (iVar27 = 1,
                   (int)(uint)*(ushort *)(*param_2 + 0x16) >> (uVar35 & 0x3f) < iVar20 << 3))
                goto LAB_00038698;
              }
              if (((*(uint *)(iVar39 + 0x18) & 0x30000000) == 0) || (iVar45 == 0)) {
                uVar35 = 0;
              }
              else {
                uVar35 = (*(byte *)(iVar45 + 0x15) & 0x18) << 0xe;
              }
              uVar21 = *(uint *)(((unsigned char *)0x00003bec) +
                                (int)(pcStack_b0 + (*(uint *)(iVar39 + 0x14) & 7) * 4));
              uStack_144 = iVar22 + param_6 ^ 0x80000000;
              uStack_13c = uVar42 + iVar22 + param_6 ^ 0x80000000;
              puVar30[0xb6] = uVar24 - 1 & 0x1fff | (uStack_f8 - 1) * 0x2000 & 0x3ffe000;
              puVar40 = puVar30 + 0xcc;
              puVar30[0x9f] =
                   uVar35 | uVar24 & 0x3ffe | iVar27 << 0x10 | uVar44 | (uVar21 & 0xf) << 0x15;
              uStack_140 = 0x43300000;
              uStack_148 = 0x43300000;
              puVar30[0xc0] = 0x31080;
              puVar30[0xc4] = 0;
              puVar30[0xc1] = 0;
              puVar30[0xc5] = ((unsigned char *)0x00001087U);
              puVar30[0xc3] = 0x3f800000;
              puVar30[0xc2] = 0x3f800000;
              fVar2 = (float)((double)CONCAT44(0x43300000,uStack_13c) - 4503601774854144.0);
              fVar3 = (float)((double)CONCAT44(0x43300000,uStack_144) - 4503601774854144.0);
              uVar44 = (uint)((fVar2 - fVar3) * 6.0);
              lStack_138 = (longlong)(int)uVar44;
              puVar30[199] = 0xc0033500;
              puVar30[200] = 0x10031;
              puVar30[0xca] = (fVar3 + fVar2) * 0.5;
              puVar30[0xc9] = (fVar5 + fVar4) * 0.5;
              puVar30[0xcb] = 0;
              puVar30[0xc6] = uVar44 | uStack_108;
              *piStack_fc = (int)puVar40 - (int)puVar30 >> 2;
              puVar23 = *(uint **)(param_1 + 0x1d8);
              *puVar23 = (int)puVar40 - (int)puVar23 >> 2 | *puVar23;
              *(undefined4 **)(param_1 + 0x1d8) = puVar40;
              puVar30[0xcd] = 0;
              puVar30[0xcc] = 0x33000000;
              puVar30[0xce] = ((unsigned char *)0x00001393U);
              puVar30[0xcf] = 10;
              puVar30[0xd0] = ((unsigned char *)0x000013c6U);
              puVar30[0xd1] = 3;
              puVar30[0xd2] = 0x5c8;
              puVar30[0xd3] = 0x20000;
              puVar30[0xd4] = (*(unsigned char *)0x000010ea);
              uVar28 = *(undefined4 *)(param_1 + 0x1cfc);
              puVar30[0xd6] = ((unsigned char *)0x000010faU);
              puVar30[0xd5] = uVar28;
              uVar28 = *(undefined4 *)(param_1 + 0x1da0);
              puVar30[0xd8] = 0xc0001000;
              puVar30[0xda] = 0x11004;
              puVar30[0xd7] = uVar28;
              puVar30[0xdb] = *(undefined4 *)(param_1 + 0x1ca8);
              uVar28 = *(undefined4 *)(param_1 + 0x1cac);
              puVar30[0xdd] = ((unsigned char *)0x00001008U);
              puVar30[0xdc] = uVar28;
              uVar28 = *(undefined4 *)(param_1 + 0x1ca0);
              puVar30[0xdf] = (*(unsigned char *)0x000010e9);
              puVar30[0xde] = uVar28;
              uVar28 = *(undefined4 *)(param_1 + 0x1d20);
              puVar30[0xe1] = ((unsigned char *)0x000013c7U);
              puVar30[0xe0] = uVar28;
              uVar28 = *(undefined4 *)(param_1 + 0x1cf0);
              puVar30[0xe3] = ((unsigned char *)0x000013c1U);
              puVar30[0xe2] = uVar28;
              uVar28 = *(undefined4 *)(param_1 + 0x1ce4);
              puVar30[0xe5] = 0x850;
              puVar30[0xe4] = uVar28;
              uVar28 = *(undefined4 *)(param_1 + 0x1dc0);
              puVar30[0xe7] = 0x887;
              puVar30[0xe6] = uVar28;
              uVar28 = *(undefined4 *)(param_1 + 0x1db4);
              puVar30[0x189] = 0x82c;
              puVar30[0xe8] = uVar28;
              uVar28 = *(undefined4 *)(0x00001dc4 + param_1);
              puVar30[0xe9] = ((unsigned char *)0x000010aeU);
              puVar30[0x18a] = uVar28;
              uVar28 = *(undefined4 *)(param_1 + 0x1d70);
              puVar30[0xeb] = ((unsigned char *)0x00001394U);
              puVar30[0xea] = uVar28;
              uVar28 = *(undefined4 *)(param_1 + 0x1d30);
              puVar30[0xed] = ((unsigned char *)0x00001380U);
              puVar30[0xef] = ((unsigned char *)0x00001002U);
              puVar30[0xee] = 0;
              puVar30[0xec] = uVar28;
              puVar30[0xf0] = *(undefined4 *)(param_1 + 0x1d90);
              uVar28 = *(undefined4 *)(param_1 + 0x1d90);
              puVar30[0xf1] = 0x824;
              puVar30[0xf0] = uVar28;
              uVar28 = *(undefined4 *)(param_1 + 0x1ddc);
              puVar30[0xf3] = 0x825;
              puVar30[0xf2] = uVar28;
              uVar28 = *(undefined4 *)(param_1 + 0x1de0);
              puVar30[0xf5] = 0x82d;
              puVar30[0xf4] = uVar28;
              uVar28 = *(undefined4 *)(param_1 + 0x26cc);
              puVar30[0xf7] = 0x854;
              puVar30[0xf6] = uVar28;
              uVar28 = **(undefined4 **)(param_1 + 0x2680);
              puVar30[0xf9] = 0x878;
              puVar30[0xf8] = uVar28;
              uVar28 = **(undefined4 **)(param_1 + 0x2684);
              puVar30[0xfb] = ((unsigned char *)0x000013c0U);
              puVar30[0xfa] = uVar28;
              uVar28 = *(undefined4 *)(param_1 + 0x1ce0);
              puVar30[0xfd] = ((unsigned char *)0x000012f0U);
              puVar30[0xfc] = uVar28;
              uVar44 = *(uint *)(param_1 + 0x1d2c);
              puVar30[0xfe] = uVar44;
              if ((*(uint *)(((unsigned char *)0x0000352c) +
                            (int)(pcStack_a8 + (uint)(byte)((unsigned char *)0x00002b7f)[param_1] * 0x24 + 0x18))
                  & 0x8000) == 0) {
                puVar30[0xfe] = uVar44 & 0xfffffffe;
              }
              puVar30[0xff] = ((unsigned char *)0x000012f5U);
              uVar44 = *(uint *)(param_1 + 0x1c8c);
              puVar30[0x100] = uVar44;
              if ((*(uint *)(((unsigned char *)0x0000352c) +
                            (int)(pcStack_a8 + (uint)(byte)((unsigned char *)0x00002b7f)[param_1] * 0x24 + 0x18))
                  & 0x8000) == 0) {
                puVar30[0x100] = uVar44 & 0xfffff7ff;
              }
              puVar30[0x101] = ((unsigned char *)0x000010a2U);
              uVar28 = *(undefined4 *)(param_1 + 0x1d7c);
              puVar30[0x103] = ((unsigned char *)0x00001381U);
              puVar30[0x102] = uVar28;
              uVar44 = *(uint *)(param_1 + 0x1cc0);
              puVar30[0x104] = uVar44;
              if ((*(uint *)(((unsigned char *)0x0000352c) +
                            (int)(pcStack_a8 + (uint)(byte)((unsigned char *)0x00002b7f)[param_1] * 0x24 + 0x18))
                  & 0x4000) == 0) {
                puVar30[0x104] = uVar44 & 0xfffffffc;
              }
              puVar30[0x105] = ((unsigned char *)0x0000109eU);
              uVar28 = *(undefined4 *)(param_1 + 0x1d6c);
              puVar30[0x107] = ((unsigned char *)0x00001096U);
              puVar30[0x106] = uVar28;
              uVar28 = *(undefined4 *)(param_1 + 0x1df8);
              puVar30[0x109] = ((unsigned char *)0x00001041U);
              puVar30[0x106] = uVar28;
              uVar28 = *(undefined4 *)(param_1 + 0x29f0);
              puVar30[0x10b] = ((unsigned char *)0x00001046U);
              puVar30[0x10a] = uVar28;
              uVar28 = *(undefined4 *)(param_1 + 0x1dfc);
              puVar30[0x10d] = ((unsigned char *)0x00001094U);
              puVar30[0x125] = ((unsigned char *)0x00001095U);
              puVar30[0x127] = 0xc0221000;
              puVar30[0x14b] = ((unsigned char *)0x00001180U);
              puVar30[0x10f] = ((unsigned char *)0x00001095U);
              puVar30[0x111] = ((unsigned char *)0x00001095U);
              puVar30[0x113] = ((unsigned char *)0x00001095U);
              puVar30[0x10c] = uVar28;
              puVar30[0x115] = ((unsigned char *)0x00001095U);
              puVar30[0x117] = ((unsigned char *)0x00001095U);
              puVar30[0x119] = ((unsigned char *)0x00001095U);
              puVar30[0x11b] = ((unsigned char *)0x00001095U);
              puVar30[0x11d] = ((unsigned char *)0x00001095U);
              puVar30[0x11f] = ((unsigned char *)0x00001095U);
              puVar30[0x121] = ((unsigned char *)0x00001095U);
              puVar30[0x123] = ((unsigned char *)0x00001095U);
              puVar30[0x10e] = 0;
              puVar30[0x14c] = 2;
              puVar30[0x14d] = ((unsigned char *)0x00001189U);
              puVar30[0x14f] = ((unsigned char *)0x00001181U);
              puVar30[0x151] = ((unsigned char *)0x0000118dU);
              puVar30[0x153] = ((unsigned char *)0x0000118eU);
              puVar30[0x155] = ((unsigned char *)0x0000118cU);
              puVar30[0x157] = ((unsigned char *)0x000011a9U);
              uVar28 = *(undefined4 *)(param_1 + 0x257c);
              puVar30[0x159] = ((unsigned char *)0x000011aaU);
              puVar30[0x158] = uVar28;
              uVar28 = *(undefined4 *)(param_1 + 0x2580);
              puVar30[0x15b] = ((unsigned char *)0x000011abU);
              puVar30[0x15a] = uVar28;
              uVar28 = *(undefined4 *)(param_1 + 0x2584);
              puVar30[0x15d] = ((unsigned char *)0x000011acU);
              puVar30[0x15c] = uVar28;
              uVar28 = *(undefined4 *)(param_1 + 0x2588);
              puVar30[0x15f] = ((unsigned char *)0x000010c0U);
              puVar30[0x15e] = uVar28;
              uVar28 = *(undefined4 *)(param_1 + 0x216c);
              puVar30[0x161] = ((unsigned char *)0x000010c1U);
              puVar30[0x163] = ((unsigned char *)0x000010c8U);
              puVar30[0x165] = ((unsigned char *)0x0000101dU);
              puVar30[0x160] = uVar28;
              uVar28 = *(undefined4 *)(param_1 + 0x2128);
              puVar30[0x167] = ((unsigned char *)0x0000138aU);
              puVar30[0x169] = ((unsigned char *)0x0000138eU);
              puVar30[0x16e] = 0;
              puVar30[0x16b] = ((unsigned char *)0x00001040U);
              puVar30[0x168] = 0;
              puVar30[0x16a] = 0;
              puVar30[0x16c] = 0;
              puVar30[0x166] = uVar28;
              puVar30[0x16d] = (*(unsigned char *)0x00001150);
              puVar30[0x16f] = ((unsigned char *)0x00001100U);
              uVar28 = *(undefined4 *)(param_1 + 0x1f1c);
              puVar30[0x171] = ((unsigned char *)0x00001110U);
              puVar30[0x170] = uVar28;
              puVar30[0x172] = *(undefined4 *)(param_1 + 0x1f5c);
              puVar30[0x173] = (*(unsigned char *)0x00001120);
              uVar28 = *(undefined4 *)(param_1 + 0x1f9c);
              puVar30[0x175] = ((unsigned char *)0x00001130U);
              puVar30[0x174] = uVar28;
              uVar28 = *(undefined4 *)(param_1 + 0x1fdc);
              puVar30[0x177] = ((unsigned char *)0x00001140U);
              puVar30[0x176] = uVar28;
              uVar28 = *(undefined4 *)(param_1 + 0x201c);
              puVar30[0x179] = ((unsigned char *)0x000010f4U);
              puVar30[0x17a] = 0xaaaa;
              puVar30[0x17b] = ((unsigned char *)0x00001383U);
              puVar30[0x178] = uVar28;
              uVar28 = *(undefined4 *)(param_1 + 0x1d34);
              puVar30[0x17d] = ((unsigned char *)0x00001386U);
              puVar30[0x17c] = uVar28;
              uVar28 = *(undefined4 *)(param_1 + 0x1d38);
              puVar30[0x17f] = 0x110f8;
              puVar30[0x17e] = uVar28;
              puVar30[0x180] = *(undefined4 *)(param_1 + 0x1d98);
              uVar28 = *(undefined4 *)(param_1 + 0x1d50);
              puVar30[0x182] = ((unsigned char *)0x00001087U);
              puVar30[0x181] = uVar28;
              uVar28 = *(undefined4 *)(param_1 + 0x1f0c);
              puVar30[0x184] = 0x31080;
              puVar30[0x183] = uVar28;
              puVar30[0x185] = *(undefined4 *)(param_1 + 0x1efc);
              puVar30[0x186] = *(undefined4 *)(param_1 + 0x1f04);
              puVar30[0x187] = *(undefined4 *)(param_1 + 0x1f00);
              puVar30[0x188] = *(undefined4 *)(param_1 + 0x1f08);
              FUN_0004c100(puVar30 + 0xce,iVar43);
              puVar29 = puVar30 + 0x18b;
              for (puVar23 = puVar30 + 0x18c; ((uint)puVar23 & 0x1f) != 0; puVar23 = puVar23 + 1) {
              }
              uVar44 = 0x80000000;
              puVar30[0xa3] = ((int)puVar23 - (int)puVar30) * 8 & 0xffffffe0U | puVar30[0xa3] & 0x1f
              ;
              iVar45 = ((int)((param_8 << (*(uint *)(iVar39 + 0x14) & 7)) + 3) >> 2) +
                       ((int)puVar23 - (int)puVar29 >> 2);
              if (iVar45 != 1) {
                uVar44 = (iVar45 + -2) * 0x10000 | 0xc0001000;
              }
              *puVar29 = uVar44;
              puVar29 = puVar29 + iVar45;
              if (1 < (int)uVar42) {
                uVar44 = uVar26 >> 2;
                iVar45 = uVar42 - 1;
                do {
                  if (uVar44 == 1) {
                    uVar24 = 0x80000000;
                  }
                  else {
                    uVar24 = (uVar44 - 2) * 0x10000 | 0xc0001000;
                  }
                  *puVar29 = uVar24;
                  puVar29 = puVar29 + uVar44;
                  iVar45 = iVar45 + -1;
                } while (iVar45 != 0);
              }
              uStack_224 = *(uint *)(iVar39 + 0x10) >> 0x1b;
              sVar8 = *(short *)(param_2[0xc] + 0x1a);
              sVar11 = *(short *)(param_2[0xc] + 2);
              uStack_204 = 0;
              uStack_218 = 0;
              puStack_214 = ((unsigned char *)0x0007efffU);
              uStack_208 = 0;
              uStack_220 = *(uint *)(iVar39 + 0x10) >> 0x16 & 0x1f;
              if ((char)param_14 == '\0') {
                iVar45 = *(int *)(param_1 + 0x10);
                puVar25 = ((unsigned char *)0x00002e6c) + iVar45;
                uStack_218 = (uint)(((unsigned char *)0x00002e84)[iVar45] != '\0');
                if (((unsigned char *)0x00002e85)[iVar45] != '\0') {
                  uStack_218 = uStack_218 | 4;
                }
              }
              else {
                puVar25 = (undefined *)0x0;
              }
              uVar44 = param_9;
              puVar37 = puStack_bc;
              piVar36 = piStack_c8;
              puVar38 = puStack_c4;
              uStack_228 = uVar26;
              FUN_0000a6e0(param_1,param_11,param_12,param_8,param_9,puStack_bc,piStack_c8,
                           puStack_c4,puVar25);
              puVar33 = puStack_b8;
              _glgConvertType(param_11,param_12,puStack_b8,puStack_b4,uVar44,puVar37,piVar36,puVar38
                             );
              if ((((sVar11 != 0x1908) && (sVar8 != -0x7a43)) && (sVar11 != 0x1906)) &&
                 ((sVar11 != 0x190a &&
                  ((0x15 < uStack_224 || ((1 << (uStack_224 & 0x3f) & 0x3ff707U) == 0)))))) {
                uStack_218 = uStack_218 | 0x8000;
              }
              uStack_21c = 2;
              uStack_1d0 = 0;
              puStack_23c = (uint *)(param_13 + uStack_240 + iVar22 * uStack_238);
              uVar26 = param_13;
              puStack_22c = puVar23;
              uStack_210 = param_8;
              uStack_20c = uVar42;
              _glgProcessPixels(((unsigned char *)0x00002e48) + *(int *)(param_1 + 0x10),ppuStack_c0,puVar33,
                                param_13,uVar44,puVar37,iVar22 * uStack_238,puVar38);
              *(uint **)(param_1 + 0x298c) = puVar29;
              (**(code **)(param_1 + 0x299c))(iVar43,puVar29);
              iVar22 = iStack_110;
            } while (bVar1);
          }
          uVar28 = (**(code **)(param_1 + 0x2998))(iVar43,0xe0);
          *(undefined4 *)(param_1 + 0x298c) = uVar28;
          uVar28 = ((int (*)())FUN_000308c0)(param_1,uVar28);
          *(undefined4 *)(param_1 + 0x298c) = uVar28;
          (**(code **)(param_1 + 0x299c))(iVar43,uVar28);
          _pthread_mutex_unlock(*(undefined4 *)(param_1 + 0xc));
          if ((*(uint *)(param_2[0xc] + 0x48) & 0x8000) == 0) {
            return 1;
          }
          if (param_4 != *(byte *)(param_2[0xc] + 0x5e)) {
            return 1;
          }
          ((int (*)())FUN_00034200)(param_1,param_2,param_3,uVar26,uVar44);
          return 1;
        }
      }
    }
LAB_00037930:
    _pthread_mutex_unlock(*(undefined4 *)(param_1 + 0xc));
    return 0;
  }
  iVar43 = param_2[0xc];
  uVar26 = ((int (*)())FUN_0002f7c0)(param_11,param_12);
  if (uVar26 == 0) {
    return 0;
  }
  puVar23 = &uStack_248;
  FUN_0000a6e0(param_1,param_11,param_12,param_8,param_9,puVar23,&uStack_240,&iStack_244,
               ((unsigned char *)0x00002e6c) + *(int *)(param_1 + 0x10));
  iVar39 = *(int *)*param_15;
  uVar44 = param_13 + iStack_244;
  if (0x1000 < (int)uStack_248 >> (uStack_240 & 0x3f)) {
    return 0;
  }
  if (0x1000 < (int)param_9) {
    return 0;
  }
  iVar45 = param_4 * 0x18 + param_3 * 0x168;
  iVar22 = iVar45 + param_2[0xc];
  if (0x1000 < *(ushort *)(iVar22 + 0xa4)) {
    return 0;
  }
  if (0x1000 < *(ushort *)(iVar22 + 0xa6)) {
    return 0;
  }
  _pthread_mutex_lock(*(undefined4 *)(param_1 + 0xc));
  iVar22 = param_3;
  iVar27 = ((int (*)())FUN_00031220)(param_1,param_2,param_3,param_4,0);
  if ((iVar27 == 0) || ((*(uint *)(iVar27 + 0x18) & 0x10000) == 0)) goto LAB_00037930;
  iVar45 = iVar45 + param_2[0xc];
  uStack_e8 = (uint)*(ushort *)(iVar45 + 0xa4);
  uVar42 = (uint)*(ushort *)(iVar45 + 0xa6);
  if (uStack_e8 == 0) {
    fVar4 = 1.0;
    uStack_e8 = 1;
  }
  else {
    uStack_1c8 = 0x43300000;
    uStack_1c4 = uStack_e8 ^ 0x80000000;
    fVar4 = (float)((double)CONCAT44(0x43300000,uStack_1c4) - 4503601774854144.0);
  }
  if (uVar42 == 0) {
    uVar42 = 1;
    fVar5 = 1.0;
  }
  else {
    uStack_1bc = uVar42 ^ 0x80000000;
    uStack_1c0 = 0x43300000;
    fVar5 = (float)((double)CONCAT44(0x43300000,uStack_1bc) - 4503601774854144.0);
  }
  uStack_1b4 = param_5 ^ 0x80000000;
  uStack_1a4 = param_8 ^ 0x80000000;
  uStack_1b8 = 0x43300000;
  uStack_1ac = param_6 ^ 0x80000000;
  uStack_1a0 = 0x43300000;
  uStack_1b0 = 0x43300000;
  uStack_1a8 = 0x43300000;
  uStack_19c = param_9 ^ 0x80000000;
  fVar6 = 0.0;
  fVar2 = (float)((double)CONCAT44(0x43300000,uStack_1b4) - 4503601774854144.0);
  fVar3 = (float)((double)CONCAT44(0x43300000,uStack_1ac) - 4503601774854144.0);
  fVar7 = fVar2 + 0.0;
  fVar16 = fVar3 + 0.0;
  fVar17 = (float)((double)CONCAT44(0x43300000,uStack_19c) - 4503601774854144.0) + fVar3;
  fVar14 = (float)((double)CONCAT44(0x43300000,uStack_1a4) - 4503601774854144.0) + fVar2;
  fVar15 = fVar7;
  if (0.0 < fVar7) {
    fVar15 = fVar2 + fVar7;
    fVar6 = fVar7;
  }
  fVar7 = 0.0;
  if (0.0 < fVar16) {
    fVar7 = fVar16;
    fVar16 = fVar3 + fVar16;
  }
  fVar12 = fVar14 - fVar4;
  fVar18 = fVar17 - fVar5;
  fVar13 = fVar4;
  if (fVar12 < 0.0) {
    fVar13 = fVar14;
  }
  fVar14 = fVar5;
  if (fVar18 < 0.0) {
    fVar14 = fVar17;
  }
  if (-fVar12 < 0.0) {
    fVar13 = fVar4;
  }
  if (-fVar18 < 0.0) {
    fVar14 = fVar5;
  }
  if ((fVar13 <= fVar6) || (fVar14 <= fVar7)) {
    _pthread_mutex_unlock(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
  if (((((*(byte *)((int)param_2 + 0x39) & 7) != 0) &&
       (iVar22 = ((int (*)())FUN_00032100)(param_1,param_2,iVar22,*(byte *)((int)param_2 + 0x39) & 7,"",puVar23),
       iVar22 == 0)) ||
      ((*(int *)param_15[1] != 0 && (iVar22 = FUN_0001e280(param_1,param_15,1), iVar22 == 0)))) ||
     (((int *)param_15[2] == (int *)0x0 || (iVar22 = *(int *)param_15[2], iVar22 == 0))))
  goto LAB_00037930;
  if (*(char *)(iVar22 + 0x16) != '\x06') {
    if (param_11 == 0x1908) {
      if (param_12 != ((unsigned char *)0x00001406)) goto LAB_00037930;
    }
    else if ((param_11 != 0x80e1) || (param_12 != (undefined *)0x8367)) goto LAB_00037930;
  }
  pcStack_a8 = FUN_001d6a08;
  iVar22 = (uVar26 & 0xff) * 0x24;
  bVar1 = ((uVar44 | uStack_248) & 0x1f) == 0;
  bVar46 = bVar1 << 1;
  if (!bVar1) goto LAB_00037930;
  iVar45 = param_1 + 0x240;
  uVar28 = (**(code **)(param_1 + 0x2998))(iVar45,0x343);
  *(undefined4 *)(param_1 + 0x298c) = uVar28;
  puVar29 = (uint *)((int (*)())FUN_00030840)(param_1,uVar28,param_2);
  puVar30 = (undefined4 *)((uint)(puVar29 + 0xb) & 0xffffffe0);
  *puVar29 = (((int)puVar30 - (int)puVar29) + -8) * 0x4000 | 0xc0001000;
  puVar30[-1] = (int)puVar30 - (int)puVar29;
  puVar23 = *(uint **)(param_1 + 0x1d8);
  *puVar23 = (int)puVar30 - (int)puVar23 >> 2 | *puVar23;
  *(undefined4 **)(param_1 + 0x1d8) = puVar30;
  *puVar30 = 0x3e000000;
  puVar40 = *(undefined4 **)param_15[2];
  piVar36 = puVar40 + 4;
  do {
    if (in_RESERVE != '\0') {
      iVar20 = storeWordConditionalIndexed(*piVar36 + 0x10000,0,piVar36);
      *piVar36 = iVar20;
      bVar46 = 2;
    }
    puVar25 = PTR_DAT_001e88d0;
  } while (!(bool)(bVar46 >> 1 & 1));
  puVar30[2] = *puVar40;
  iVar20 = *(int *)*param_15;
  puVar30[4] = param_4 | param_3 << 0x10;
  puVar30[3] = uVar44 - iVar20;
  _memcpy(puVar30 + 5,puVar25,0x2f4);
  iVar20 = param_2[0xd];
  if ((iVar20 == 0) || ((*(byte *)(iVar20 + 0x15) & 0x18) == 0)) {
    iVar34 = 0x20;
  }
  else {
    iVar34 = 0x20 / (1 << (*(uint *)(&DAT_001d9f4c + (uint)*(byte *)(param_2 + 0xe) * 0x24) >> 0x1c
                          & 3));
  }
  iVar34 = iVar34 >> (*(uint *)(iVar27 + 0x14) & 7);
  if ((iVar20 == 0) || (iVar32 = 0, *(char *)(iVar20 + 0x16) != '\x06')) {
    iVar20 = *param_2 + 0x40 + (param_3 * 0xd + param_4) * 0x20;
    iVar32 = param_7 * *(int *)(iVar20 + 0x14) + *(int *)(iVar20 + 8);
  }
  if (*(char *)(param_2[0xc] + 0x6d) == '\0') {
    uVar26 = (uStack_e8 + iVar34) - 1 & -iVar34;
  }
  else {
    uVar26 = (uint)*(ushort *)((int)param_2 + 0x3e);
  }
  fVar4 = (fVar13 + fVar2) - fVar15;
  fVar5 = (fVar14 + fVar3) - fVar16;
  fVar17 = fVar4 - 1.0;
  puVar30[0xa5] = *(uint *)(&DAT_001d9f4c + iVar22) >> 0x1e | puVar30[0xa5] & 0xfffffffc;
  if (2.1474836e+09 <= fVar17) {
    lStack_190 = (longlong)(int)(fVar17 - 2.1474836e+09);
    uVar24 = (int)(fVar17 - 2.1474836e+09) + 0x80000000;
  }
  else {
    uVar24 = (uint)fVar17;
    lStack_198 = (longlong)(int)uVar24;
  }
  fVar17 = fVar5 - 1.0;
  if (2.1474836e+09 <= fVar17) {
    lStack_180 = (longlong)(int)(fVar17 - 2.1474836e+09);
    uVar35 = (int)(fVar17 - 2.1474836e+09) + 0x80000000;
  }
  else {
    uVar35 = (uint)fVar17;
    lStack_188 = (longlong)(int)uVar35;
  }
  puVar30[0xab] = uVar24 & 0x7ff | (uVar35 & 0x7ff) << 0xb | 0x80000000;
  uVar24 = *(uint *)(&DAT_001d9f50 + iVar22);
  uVar35 = *(uint *)(&DAT_001d9f54 + iVar22);
  puVar30[0xad] =
       uVar24 >> 7 & 0x1f | uVar35 >> 3 & 0x400000 | (uVar24 & 0x70) << 5 | (uVar24 & 0xe) << 0xb |
       uVar35 >> 0xe & 0x38000 | uVar35 >> 8 & 0x1c0000;
  uVar24 = *(uint *)(&DAT_001d9f48 + iVar22);
  if (2.1474836e+09 <= fVar4) {
    lStack_170 = (longlong)(int)(fVar4 - 2.1474836e+09);
    iVar22 = (int)(fVar4 - 2.1474836e+09) + -0x80000000;
  }
  else {
    iVar22 = (int)fVar4;
    lStack_178 = (longlong)iVar22;
  }
  if (2.1474836e+09 <= fVar5) {
    lStack_160 = (longlong)(int)(fVar5 - 2.1474836e+09);
    iVar20 = (int)(fVar5 - 2.1474836e+09) + -0x80000000;
  }
  else {
    iVar20 = (int)fVar5;
    lStack_168 = (longlong)iVar20;
  }
  puVar30[0x9f] = iVar32;
  puVar30[0xaf] =
       ((int)uStack_248 >> (uVar24 & 7)) - 1U & 0x3fff | (iVar22 + -1) * 0x10 & 0xffff8000U |
       (iVar20 + -1) * 0x20 & 0xffff0000U;
  puVar30[0xa5] = (uVar44 - iVar39) * 0x20 | puVar30[0xa5] & 0x1f;
  iVar39 = param_2[0xd];
  if ((iVar39 != 0) && ((*(byte *)(iVar39 + 0x15) & 4) != 0)) {
    uVar44 = param_4 - *(byte *)(param_2[0xc] + 0x69);
    if ((*(byte *)(iVar39 + 0x15) & 0x18) == 0) {
      iVar20 = 1;
      iVar22 = 0x100;
    }
    else {
      iVar20 = 1 << (*(uint *)(((unsigned char *)0x00003544) +
                              (int)(pcStack_a8 + (uint)*(byte *)(param_2 + 0xe) * 0x24)) >> 0x1c & 3
                    );
      iVar22 = 0x20 / iVar20 << 3;
    }
    if ((iVar22 <= *(int *)(*param_2 + 0xc) >> (uVar44 & 0x3f)) &&
       (iVar22 = 1, iVar20 << 3 <= (int)(uint)*(ushort *)(*param_2 + 0x16) >> (uVar44 & 0x3f)))
    goto LAB_000371ac;
  }
  iVar22 = 0;
LAB_000371ac:
  if (iVar39 != 0) {
    uVar44 = (*(byte *)(iVar39 + 0x15) & 0x18) << 0xe;
  }
  else {
    uVar44 = 0;
  }
  uVar21 = puVar30[0x8f];
  puVar30[0xa1] =
       uVar44 | uVar26 & 0x3ffe | iVar22 << 0x10 | *(uint *)(iVar27 + 0x18) >> 0xb & 0x180000 |
       (*(uint *)(iVar27 + 0x18) & 0x3c00) << 0xb;
  uVar26 = (*(uint *)(iVar27 + 0x18) & 0x18) << 5;
  puVar30[0x8f] = uVar26 | uVar21 & 0xfffffcff;
  uVar44 = (*(uint *)(iVar27 + 0x18) & 6) << 9;
  puVar30[0x8f] = uVar44 | uVar26 | uVar21 & 0xfffff0ff;
  uVar24 = *(uint *)(iVar27 + 0x1c) >> 0x12 & 0x3000;
  puVar30[0x8f] = uVar24 | uVar44 | uVar26 | uVar21 & 0xffffc0ff;
  uVar35 = *(uint *)(iVar27 + 0x1c) >> 0xe & 0xc000;
  puVar30[0x8f] = uVar35 | uVar24 | uVar44 | uVar26 | uVar21 & 0xffff00ff;
  puVar30[0x8f] =
       *(uint *)(iVar27 + 0x18) >> 5 & 0x1f |
       uVar35 | uVar24 | uVar44 | uVar26 | uVar21 & 0xffff00e0;
  sVar8 = *(short *)(iVar43 + 2);
  if (((sVar8 != 0x1908) && (sVar8 != 0x1906)) && (sVar8 != 0x190a)) {
    puVar30[0x5b] = puVar30[0x5b] & 0xfffe3fff | 0x18000;
  }
  puVar30[0xb8] = uStack_e8 - 1 & 0x1fff | (uVar42 - 1) * 0x2000 & 0x3ffe000;
  if ((*(uint *)(iVar27 + 0x20) & 0x400000) != 0) {
    puVar30[0x23] = 0;
  }
  puVar40 = puVar30 + 0xce;
  puVar30[199] = ((unsigned char *)0x00001087U);
  puVar30[0xc2] = 0x31080;
  puVar30[0xc6] = (1.0 / fVar5) * fVar16;
  iVar43 = (int)((fVar13 - fVar6) * 6.0);
  lStack_158 = (longlong)iVar43;
  puVar30[0xc5] = (fVar13 + fVar2) * (1.0 / fVar4);
  puVar30[0xc3] = fVar15 * (1.0 / fVar4);
  puVar30[0xc4] = (fVar14 + fVar3) * (1.0 / fVar5);
  uVar26 = (uint)((fVar14 - fVar7) * 6.0);
  lStack_150 = (longlong)(int)uVar26;
  puVar30[0xca] = 0x10031;
  puVar30[0xc9] = 0xc0033500;
  puVar30[0xcb] = (fVar6 + fVar13) * 0.5;
  puVar30[0xcc] = (fVar7 + fVar14) * 0.5;
  puVar30[0xcd] = 0;
  puVar30[200] = iVar43 << 0x10 | uVar26;
  puVar30[1] = (int)puVar40 - (int)puVar29 >> 2;
  puVar23 = *(uint **)(param_1 + 0x1d8);
  *puVar23 = (int)puVar40 - (int)puVar23 >> 2 | *puVar23;
  *(undefined4 **)(param_1 + 0x1d8) = puVar40;
  puVar30[0xcf] = 0;
  puVar30[0xce] = 0x33000000;
  puVar30[0xd0] = ((unsigned char *)0x00001393U);
  puVar30[0xd1] = 10;
  puVar30[0xd2] = ((unsigned char *)0x000013c6U);
  puVar30[0xd3] = 3;
  puVar30[0xd4] = 0x5c8;
  puVar30[0xd5] = 0x20000;
  puVar30[0xd6] = (*(unsigned char *)0x000010ea);
  uVar28 = *(undefined4 *)(param_1 + 0x1cfc);
  puVar30[0xd8] = ((unsigned char *)0x000010faU);
  puVar30[0xd7] = uVar28;
  uVar28 = *(undefined4 *)(param_1 + 0x1da0);
  puVar30[0xda] = 0xc0001000;
  puVar30[0xdc] = 0x11004;
  puVar30[0xd9] = uVar28;
  puVar30[0xdd] = *(undefined4 *)(param_1 + 0x1ca8);
  uVar28 = *(undefined4 *)(param_1 + 0x1cac);
  puVar30[0xdf] = ((unsigned char *)0x00001008U);
  puVar30[0xde] = uVar28;
  uVar28 = *(undefined4 *)(param_1 + 0x1ca0);
  puVar30[0xe1] = (*(unsigned char *)0x000010e9);
  puVar30[0xe0] = uVar28;
  uVar28 = *(undefined4 *)(param_1 + 0x1d20);
  puVar30[0xe3] = ((unsigned char *)0x000013c7U);
  puVar30[0xe2] = uVar28;
  uVar28 = *(undefined4 *)(param_1 + 0x1cf0);
  puVar30[0xe5] = ((unsigned char *)0x000013c1U);
  puVar30[0xe4] = uVar28;
  uVar28 = *(undefined4 *)(param_1 + 0x1ce4);
  puVar30[0xe7] = 0x850;
  puVar30[0xe6] = uVar28;
  uVar28 = *(undefined4 *)(param_1 + 0x1dc0);
  puVar30[0xe9] = 0x887;
  puVar30[0xe8] = uVar28;
  uVar28 = *(undefined4 *)(param_1 + 0x1db4);
  puVar30[0x18b] = 0x82c;
  puVar30[0xea] = uVar28;
  uVar28 = *(undefined4 *)(0x00001dc4 + param_1);
  puVar30[0xeb] = ((unsigned char *)0x000010aeU);
  puVar30[0x18c] = uVar28;
  uVar28 = *(undefined4 *)(param_1 + 0x1d70);
  puVar30[0xed] = ((unsigned char *)0x00001394U);
  puVar30[0xec] = uVar28;
  uVar28 = *(undefined4 *)(param_1 + 0x1d30);
  puVar30[0xef] = ((unsigned char *)0x00001380U);
  puVar30[0xf1] = ((unsigned char *)0x00001002U);
  puVar30[0xf0] = 0;
  puVar30[0xee] = uVar28;
  puVar30[0xf2] = *(undefined4 *)(param_1 + 0x1d90);
  uVar28 = *(undefined4 *)(param_1 + 0x1d90);
  puVar30[0xf3] = 0x824;
  puVar30[0xf2] = uVar28;
  uVar28 = *(undefined4 *)(param_1 + 0x1ddc);
  puVar30[0xf5] = 0x825;
  puVar30[0xf4] = uVar28;
  uVar28 = *(undefined4 *)(param_1 + 0x1de0);
  puVar30[0xf7] = 0x82d;
  puVar30[0xf6] = uVar28;
  uVar28 = *(undefined4 *)(param_1 + 0x26cc);
  puVar30[0xf9] = 0x854;
  puVar30[0xf8] = uVar28;
  uVar28 = **(undefined4 **)(param_1 + 0x2680);
  puVar30[0xfb] = 0x878;
  puVar30[0xfa] = uVar28;
  uVar28 = **(undefined4 **)(param_1 + 0x2684);
  puVar30[0xfd] = ((unsigned char *)0x000013c0U);
  puVar30[0xfc] = uVar28;
  uVar28 = *(undefined4 *)(param_1 + 0x1ce0);
  puVar30[0xff] = ((unsigned char *)0x000012f0U);
  puVar30[0xfe] = uVar28;
  uVar26 = *(uint *)(param_1 + 0x1d2c);
  puVar30[0x100] = uVar26;
  if ((*(uint *)(((unsigned char *)0x0000352c) +
                (int)(pcStack_a8 + (uint)(byte)((unsigned char *)0x00002b7f)[param_1] * 0x24 + 0x18)) & 0x8000) ==
      0) {
    puVar30[0x100] = uVar26 & 0xfffffffe;
  }
  puVar30[0x101] = ((unsigned char *)0x000012f5U);
  uVar44 = *(uint *)(param_1 + 0x1c8c);
  puVar30[0x102] = uVar44;
  uVar26 = *(uint *)(((unsigned char *)0x0000352c) +
                    (int)(pcStack_a8 + (uint)(byte)((unsigned char *)0x00002b7f)[param_1] * 0x24 + 0x18)) & 0x8000
  ;
  if (uVar26 == 0) {
    puVar30[0x102] = uVar44 & 0xfffff7ff;
  }
  puVar30[0x103] = ((unsigned char *)0x000010a2U);
  uVar28 = *(undefined4 *)(param_1 + 0x1d7c);
  puVar30[0x105] = ((unsigned char *)0x00001381U);
  puVar30[0x104] = uVar28;
  uVar44 = *(uint *)(param_1 + 0x1cc0);
  puVar30[0x106] = uVar44;
  if ((*(uint *)(((unsigned char *)0x0000352c) +
                (int)(pcStack_a8 + (uint)(byte)((unsigned char *)0x00002b7f)[param_1] * 0x24 + 0x18)) & 0x4000) ==
      0) {
    puVar30[0x106] = uVar44 & 0xfffffffc;
  }
  puVar30[0x107] = ((unsigned char *)0x0000109eU);
  uVar31 = 0x110f8;
  uVar28 = *(undefined4 *)(param_1 + 0x1d6c);
  puVar30[0x109] = ((unsigned char *)0x00001096U);
  puVar30[0x108] = uVar28;
  uVar28 = *(undefined4 *)(param_1 + 0x1df8);
  puVar30[0x10b] = ((unsigned char *)0x00001041U);
  puVar30[0x108] = uVar28;
  uVar28 = *(undefined4 *)(param_1 + 0x29f0);
  puVar30[0x10d] = ((unsigned char *)0x00001046U);
  puVar30[0x10c] = uVar28;
  uVar28 = *(undefined4 *)(param_1 + 0x1dfc);
  puVar30[0x10f] = ((unsigned char *)0x00001094U);
  puVar30[0x14e] = 2;
  puVar30[0x129] = 0xc0221000;
  puVar30[0x14d] = ((unsigned char *)0x00001180U);
  puVar30[0x127] = ((unsigned char *)0x00001095U);
  puVar30[0x151] = ((unsigned char *)0x00001181U);
  puVar30[0x111] = ((unsigned char *)0x00001095U);
  puVar30[0x10e] = uVar28;
  puVar30[0x113] = ((unsigned char *)0x00001095U);
  puVar30[0x115] = ((unsigned char *)0x00001095U);
  puVar30[0x117] = ((unsigned char *)0x00001095U);
  puVar30[0x119] = ((unsigned char *)0x00001095U);
  puVar30[0x11b] = ((unsigned char *)0x00001095U);
  puVar30[0x11d] = ((unsigned char *)0x00001095U);
  puVar30[0x11f] = ((unsigned char *)0x00001095U);
  puVar30[0x121] = ((unsigned char *)0x00001095U);
  puVar30[0x123] = ((unsigned char *)0x00001095U);
  puVar30[0x125] = ((unsigned char *)0x00001095U);
  puVar30[0x110] = 0;
  puVar30[0x14f] = ((unsigned char *)0x00001189U);
  puVar30[0x155] = ((unsigned char *)0x0000118eU);
  puVar30[0x153] = ((unsigned char *)0x0000118dU);
  puVar30[0x157] = ((unsigned char *)0x0000118cU);
  puVar30[0x159] = ((unsigned char *)0x000011a9U);
  uVar28 = *(undefined4 *)(param_1 + 0x257c);
  puVar30[0x15b] = ((unsigned char *)0x000011aaU);
  puVar30[0x15a] = uVar28;
  uVar28 = *(undefined4 *)(param_1 + 0x2580);
  puVar30[0x15d] = ((unsigned char *)0x000011abU);
  puVar30[0x15c] = uVar28;
  uVar28 = *(undefined4 *)(param_1 + 0x2584);
  puVar30[0x15f] = ((unsigned char *)0x000011acU);
  puVar30[0x15e] = uVar28;
  uVar28 = *(undefined4 *)(param_1 + 0x2588);
  puVar30[0x161] = ((unsigned char *)0x000010c0U);
  puVar30[0x160] = uVar28;
  uVar28 = *(undefined4 *)(param_1 + 0x216c);
  puVar30[0x163] = ((unsigned char *)0x000010c1U);
  puVar30[0x165] = ((unsigned char *)0x000010c8U);
  puVar30[0x167] = ((unsigned char *)0x0000101dU);
  puVar30[0x162] = uVar28;
  uVar28 = *(undefined4 *)(param_1 + 0x2128);
  puVar30[0x169] = ((unsigned char *)0x0000138aU);
  puVar30[0x16b] = ((unsigned char *)0x0000138eU);
  puVar30[0x170] = 0;
  puVar30[0x16d] = ((unsigned char *)0x00001040U);
  puVar30[0x16a] = 0;
  puVar30[0x16c] = 0;
  puVar30[0x16e] = 0;
  puVar30[0x168] = uVar28;
  puVar30[0x16f] = (*(unsigned char *)0x00001150);
  puVar30[0x171] = ((unsigned char *)0x00001100U);
  uVar28 = *(undefined4 *)(param_1 + 0x1f1c);
  puVar30[0x173] = ((unsigned char *)0x00001110U);
  puVar30[0x172] = uVar28;
  puVar30[0x174] = *(undefined4 *)(param_1 + 0x1f5c);
  puVar30[0x175] = (*(unsigned char *)0x00001120);
  uVar28 = *(undefined4 *)(param_1 + 0x1f9c);
  puVar30[0x177] = ((unsigned char *)0x00001130U);
  puVar30[0x176] = uVar28;
  uVar28 = *(undefined4 *)(param_1 + 0x1fdc);
  puVar30[0x179] = ((unsigned char *)0x00001140U);
  puVar30[0x178] = uVar28;
  uVar28 = *(undefined4 *)(param_1 + 0x201c);
  puVar30[0x17b] = ((unsigned char *)0x000010f4U);
  puVar30[0x17c] = 0xaaaa;
  puVar30[0x17d] = ((unsigned char *)0x00001383U);
  puVar30[0x17a] = uVar28;
  uVar28 = *(undefined4 *)(param_1 + 0x1d34);
  puVar30[0x17f] = ((unsigned char *)0x00001386U);
  puVar30[0x17e] = uVar28;
  uVar28 = *(undefined4 *)(param_1 + 0x1d38);
  puVar30[0x181] = 0x110f8;
  puVar30[0x180] = uVar28;
  puVar30[0x182] = *(undefined4 *)(param_1 + 0x1d98);
  uVar28 = *(undefined4 *)(param_1 + 0x1d50);
  puVar30[0x184] = ((unsigned char *)0x00001087U);
  puVar30[0x183] = uVar28;
  uVar28 = *(undefined4 *)(param_1 + 0x1f0c);
  puVar30[0x186] = 0x31080;
  puVar30[0x185] = uVar28;
  puVar30[0x187] = *(undefined4 *)(param_1 + 0x1efc);
  puVar30[0x188] = *(undefined4 *)(param_1 + 0x1f04);
  puVar30[0x189] = *(undefined4 *)(param_1 + 0x1f00);
  puVar30[0x18a] = *(undefined4 *)(param_1 + 0x1f08);
  FUN_0004c100(puVar30 + 0xd0,iVar45);
  uVar28 = ((int (*)())FUN_000308c0)(param_1,puVar30 + 0x18d);
  *(undefined4 *)(param_1 + 0x298c) = uVar28;
  (**(code **)(param_1 + 0x299c))(iVar45,uVar28);
  _pthread_mutex_unlock(*(undefined4 *)(param_1 + 0xc));
  if (((*(uint *)(param_2[0xc] + 0x48) & 0x8000) != 0) &&
     (param_4 == *(byte *)(param_2[0xc] + 0x5e))) {
    ((int (*)())FUN_00034200)(param_1,param_2,param_3,uVar26,uVar31);
    return 1;
  }
  return 1;
}

/* FUN_00039100 @ 0x39100 (188 bytes) */
int FUN_00039100(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_38;
  undefined4 local_34;
  undefined1 auStack_30 [44];
  
  local_38 = 0;
  local_34 = 3;
  iVar2 = _IOServiceOpen(*(undefined4 *)(param_1 * 4 + *(int *)(PTR_DAT_001e88ac + 8)),
                         *(undefined4 *)PTR_001e88b4,1,&local_38);
  uVar1 = 0;
  if (iVar2 == 0) {
    iVar2 = _io_connect_method_scalarI_scalarO(local_38,3,0,0,auStack_30,&local_34);
    if (iVar2 == 0) {
      _IOServiceClose(local_38);
      uVar1 = 1;
    }
    else {
      _IOServiceClose(local_38);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* FUN_000391d0 @ 0x391d0 (28 bytes) */
int FUN_000391d0()
{
  return "ATIR500";
}

/* _gldGetVersion @ 0x391f0 (84 bytes) */
int _gldGetVersion(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  undefined4 *param_2;
  undefined4 *param_3;
  undefined4 *param_4;
{
  if (*(int *)PTR_DAT_001e88ac == 0) {
    return 0;
  }
  *param_1 = 2;
  *param_2 = 4;
  *param_3 = 0xb;
  *param_4 = 0x1900;
  return 1;
}

/* _gldGetString @ 0x39250 (204 bytes) */
int _gldGetString(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  uint uVar1;
  
  switch(param_2) {
  case 0x1f00:
    return "ATI Technologies Inc.";
  case 0x1f01:
    break;
  case 0x1f02:
    return "1.5 ATI-1.4.19";
  case 0x1f03:
    return "";
  case 0x1f04:
    return "ATIRadeonX1000GLDriver";
  default:
    return (char *)0x0;
  }
  uVar1 = *(uint *)(param_1 + 0x24) & 0x7ff00000;
  if (uVar1 == 0x100000) {
    return "ATI Radeon X1800 OpenGL Engine";
  }
  if (uVar1 != 0x200000) {
    if (uVar1 != 0x800000) {
      return "ATI Radeon X1000 OpenGL Engine";
    }
    return "ATI Radeon X1900 OpenGL Engine";
  }
  return "ATI Radeon X1600 OpenGL Engine";
}

/* FUN_00039330 @ 0x39330 (724 bytes) */
void FUN_00039330(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9)
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  undefined4 *puVar12;
  int iVar13;
  int iVar14;
  double in_stack_ffffffa8;
  
  uVar8 = 3;
  iVar5 = ((uint (*)())FUN_0002cc30)(param_1,param_4,3,param_3,param_5,param_6,fparam_1,fparam_2,fparam_3,fparam_4
                       ,fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffffa8);
  if (iVar5 != 0) {
    iVar13 = *(int *)(param_1 + 0x29e8);
    iVar11 = *(int *)(**(int **)(param_1 + 0x1cc) + 4);
    iVar14 = *(int *)(iVar11 + 0x20);
    puVar6 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (param_1 + 0x240,
                        iVar14 * iVar5 * 5 + iVar5 * 2 +
                        (*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe) + 0x16,uVar8,param_3,param_5,
                        iVar5 * 2,iVar11,iVar13);
    *(undefined4 **)(param_1 + 0x298c) = puVar6;
    if (*(code **)(param_1 + 0x2680) != 0x00001e24 + param_1) {
      *(code **)(param_1 + 0x2680) = 0x00001e24 + param_1;
      *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
      *(undefined4 *)(0x000026c8 + param_1 + 4) = *(undefined4 *)(param_1 + 0x1ee4);
      puVar6 = (undefined4 *)FUN_0002c0c0(param_1,puVar6);
    }
    if (*(char *)(param_1 + 0x2a42) == '\0') {
      *puVar6 = 0x5c8;
      puVar6[1] = 0x10000000;
      puVar6 = puVar6 + 2;
      *(undefined1 *)(param_1 + 0x2a42) = 1;
    }
    puVar7 = puVar6 + 4;
    *puVar6 = 0x82c;
    uVar10 = param_2 + iVar5 * iVar14 * 4 * 4;
    uVar8 = *(undefined4 *)(0x00001dc4 + param_1);
    puVar6[2] = 0x821;
    puVar6[3] = 3;
    puVar6[1] = uVar8;
    iVar5 = *(int *)(iVar13 + 0x2c);
    *(undefined1 *)(param_1 + 0x2a5e) = 1;
    if (param_2 < uVar10) {
      iVar11 = iVar14 + -1;
      uVar9 = 0;
      do {
        *puVar7 = 0x917;
        if (uVar9 < 0x20) {
          puVar7[1] = (uint)((1 << (uVar9 & 0x3f) &
                             **(uint **)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8)) != 0);
        }
        else if (uVar9 < 0x40) {
          puVar7[1] = (uint)((1 << (uVar9 - 0x20 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8) + 4
                                      )) != 0);
        }
        else if (uVar9 < 0x60) {
          puVar7[1] = (uint)((1 << (uVar9 - 0x40 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8) + 8
                                      )) != 0);
        }
        else {
          puVar7[1] = (uint)((1 << (uVar9 - 0x60 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8) +
                                      0xc)) != 0);
        }
        puVar7 = puVar7 + 2;
        if (-1 < iVar11) {
          puVar12 = (undefined4 *)(iVar5 + iVar11 * 4);
          puVar6 = (undefined4 *)(param_2 + iVar11 * 0x10);
          iVar13 = iVar14;
          do {
            uVar8 = *puVar6;
            uVar1 = puVar6[1];
            uVar2 = puVar6[2];
            uVar3 = puVar6[3];
            puVar6 = puVar6 + -4;
            uVar4 = *puVar12;
            puVar12 = puVar12 + -1;
            puVar7[1] = uVar8;
            puVar7[2] = uVar1;
            puVar7[3] = uVar2;
            *puVar7 = uVar4;
            puVar7[4] = uVar3;
            puVar7 = puVar7 + 5;
            iVar13 = iVar13 + -1;
          } while (iVar13 != 0);
        }
        param_2 = param_2 + iVar14 * 0x10;
        uVar9 = uVar9 + 1;
      } while (param_2 < uVar10);
    }
    *puVar7 = 0x92b;
    puVar7[3] = 0;
    puVar7[2] = ((unsigned char *)0x00001393U);
    puVar7[1] = 0;
    *(undefined4 **)(param_1 + 0x298c) = puVar7 + 4;
                    
                    
    (**(code **)(param_1 + 0x299c))(param_1 + 0x240);
    return;
  }
  return;
}

/* FUN_00039610 @ 0x39610 (1092 bytes) */
void FUN_00039610(int param_1,uint param_2,uint param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9)
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  undefined4 *puVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  double in_stack_ffffff98;
  
  uVar9 = 6;
  iVar6 = ((uint (*)())FUN_0002cc30)(param_1,0,6,param_4,param_5,param_6,fparam_1,fparam_2,fparam_3,fparam_4,
                       fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffff98);
  if (iVar6 != 0) {
    iVar11 = *(int *)(param_1 + 0x29e8);
    iVar15 = *(int *)(**(int **)(param_1 + 0x1cc) + 4);
    iVar16 = *(int *)(iVar15 + 0x20);
    iVar13 = iVar16 * (iVar6 * 5 + 5);
    puVar7 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (param_1 + 0x240,
                        iVar6 * 2 + iVar13 + (*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe) + 0x18,
                        uVar9,param_4,param_5,iVar11,iVar13,iVar15);
    *(undefined4 **)(param_1 + 0x298c) = puVar7;
    if (*(code **)(param_1 + 0x2680) != 0x00001e24 + param_1) {
      *(code **)(param_1 + 0x2680) = 0x00001e24 + param_1;
      *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
      *(undefined4 *)(0x000026c8 + param_1 + 4) = *(undefined4 *)(param_1 + 0x1ee4);
      puVar7 = (undefined4 *)FUN_0002c0c0(param_1,puVar7);
    }
    if (*(char *)(param_1 + 0x2a42) == '\0') {
      *puVar7 = 0x5c8;
      puVar7[1] = 0x10000000;
      puVar7 = puVar7 + 2;
      *(undefined1 *)(param_1 + 0x2a42) = 1;
    }
    iVar13 = iVar16 * 0x10;
    puVar8 = puVar7 + 4;
    *puVar7 = 0x82c;
    uVar10 = param_2 + iVar13;
    uVar9 = *(undefined4 *)(0x00001dc4 + param_1);
    puVar7[2] = 0x821;
    puVar7[3] = 5;
    puVar7[1] = uVar9;
    iVar15 = *(int *)(iVar11 + 0x2c);
    *(undefined1 *)(param_1 + 0x2a5e) = 1;
    if (param_2 < uVar10) {
      iVar4 = iVar16 + -1;
      uVar12 = 0;
      do {
        *puVar8 = 0x917;
        if (uVar12 < 0x20) {
          puVar8[1] = (uint)((1 << (uVar12 & 0x3f) &
                             **(uint **)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8)) != 0);
        }
        else if (uVar12 < 0x40) {
          puVar8[1] = (uint)((1 << (uVar12 - 0x20 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8) + 4
                                      )) != 0);
        }
        else if (uVar12 < 0x60) {
          puVar8[1] = (uint)((1 << (uVar12 - 0x40 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8) + 8
                                      )) != 0);
        }
        else {
          puVar8[1] = (uint)((1 << (uVar12 - 0x60 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8) +
                                      0xc)) != 0);
        }
        puVar8 = puVar8 + 2;
        if (-1 < iVar4) {
          puVar14 = (undefined4 *)(iVar15 + iVar4 * 4);
          puVar7 = (undefined4 *)(param_2 + iVar4 * 0x10);
          iVar17 = iVar16;
          do {
            uVar9 = *puVar7;
            uVar1 = puVar7[1];
            uVar2 = puVar7[2];
            uVar3 = puVar7[3];
            puVar7 = puVar7 + -4;
            uVar5 = *puVar14;
            puVar14 = puVar14 + -1;
            puVar8[1] = uVar9;
            puVar8[2] = uVar1;
            puVar8[3] = uVar2;
            *puVar8 = uVar5;
            puVar8[4] = uVar3;
            puVar8 = puVar8 + 5;
            iVar17 = iVar17 + -1;
          } while (iVar17 != 0);
        }
        param_2 = param_2 + iVar13;
        uVar12 = uVar12 + 1;
      } while (param_2 < uVar10);
    }
    iVar11 = *(int *)(iVar11 + 0x2c);
    *(undefined1 *)(param_1 + 0x2a5e) = 1;
    uVar10 = param_3 + iVar16 * 4 * iVar6 * 4;
    if (param_3 < uVar10) {
      iVar6 = iVar16 + -1;
      uVar12 = 1;
      do {
        *puVar8 = 0x917;
        if (uVar12 < 0x20) {
          puVar8[1] = (uint)((1 << (uVar12 & 0x3f) &
                             **(uint **)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8)) != 0);
        }
        else if (uVar12 < 0x40) {
          puVar8[1] = (uint)((1 << (uVar12 - 0x20 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8) + 4
                                      )) != 0);
        }
        else if (uVar12 < 0x60) {
          puVar8[1] = (uint)((1 << (uVar12 - 0x40 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8) + 8
                                      )) != 0);
        }
        else {
          puVar8[1] = (uint)((1 << (uVar12 - 0x60 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8) +
                                      0xc)) != 0);
        }
        puVar8 = puVar8 + 2;
        if (-1 < iVar6) {
          puVar14 = (undefined4 *)(iVar11 + iVar6 * 4);
          puVar7 = (undefined4 *)(param_3 + iVar6 * 0x10);
          iVar15 = iVar16;
          do {
            uVar9 = *puVar7;
            uVar1 = puVar7[1];
            uVar2 = puVar7[2];
            uVar3 = puVar7[3];
            puVar7 = puVar7 + -4;
            uVar5 = *puVar14;
            puVar14 = puVar14 + -1;
            puVar8[1] = uVar9;
            puVar8[2] = uVar1;
            puVar8[3] = uVar2;
            *puVar8 = uVar5;
            puVar8[4] = uVar3;
            puVar8 = puVar8 + 5;
            iVar15 = iVar15 + -1;
          } while (iVar15 != 0);
        }
        param_3 = param_3 + iVar13;
        uVar12 = uVar12 + 1;
      } while (param_3 < uVar10);
    }
    *puVar8 = 0x92b;
    puVar8[3] = 0;
    puVar8[2] = ((unsigned char *)0x00001393U);
    puVar8[1] = 0;
    *(undefined4 **)(param_1 + 0x298c) = puVar8 + 4;
                    
                    
    (**(code **)(param_1 + 0x299c))(param_1 + 0x240);
    return;
  }
  return;
}

/* FUN_00039a60 @ 0x39a60 (724 bytes) */
void FUN_00039a60(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9)
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  undefined4 *puVar12;
  int iVar13;
  int iVar14;
  double in_stack_ffffffa8;
  
  uVar8 = 4;
  iVar5 = ((uint (*)())FUN_0002cc30)(param_1,0,4,param_3,param_5,param_6,fparam_1,fparam_2,fparam_3,fparam_4,
                       fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffffa8);
  if (iVar5 != 0) {
    iVar13 = *(int *)(param_1 + 0x29e8);
    iVar11 = *(int *)(**(int **)(param_1 + 0x1cc) + 4);
    iVar14 = *(int *)(iVar11 + 0x20);
    puVar6 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (param_1 + 0x240,
                        iVar14 * iVar5 * 5 + iVar5 * 2 +
                        (*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe) + 0x16,uVar8,param_3,param_5,
                        iVar5 * 2,iVar11,iVar13);
    *(undefined4 **)(param_1 + 0x298c) = puVar6;
    if (*(code **)(param_1 + 0x2680) != 0x00001e24 + param_1) {
      *(code **)(param_1 + 0x2680) = 0x00001e24 + param_1;
      *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
      *(undefined4 *)(0x000026c8 + param_1 + 4) = *(undefined4 *)(param_1 + 0x1ee4);
      puVar6 = (undefined4 *)FUN_0002c0c0(param_1,puVar6);
    }
    if (*(char *)(param_1 + 0x2a42) == '\0') {
      *puVar6 = 0x5c8;
      puVar6[1] = 0x10000000;
      puVar6 = puVar6 + 2;
      *(undefined1 *)(param_1 + 0x2a42) = 1;
    }
    puVar7 = puVar6 + 4;
    *puVar6 = 0x82c;
    uVar10 = param_2 + iVar5 * iVar14 * 4 * 4;
    uVar8 = *(undefined4 *)(0x00001dc4 + param_1);
    puVar6[2] = 0x821;
    puVar6[3] = 4;
    puVar6[1] = uVar8;
    iVar5 = *(int *)(iVar13 + 0x2c);
    *(undefined1 *)(param_1 + 0x2a5e) = 1;
    if (param_2 < uVar10) {
      iVar11 = iVar14 + -1;
      uVar9 = 0;
      do {
        *puVar7 = 0x917;
        if (uVar9 < 0x20) {
          puVar7[1] = (uint)((1 << (uVar9 & 0x3f) &
                             **(uint **)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8)) != 0);
        }
        else if (uVar9 < 0x40) {
          puVar7[1] = (uint)((1 << (uVar9 - 0x20 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8) + 4
                                      )) != 0);
        }
        else if (uVar9 < 0x60) {
          puVar7[1] = (uint)((1 << (uVar9 - 0x40 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8) + 8
                                      )) != 0);
        }
        else {
          puVar7[1] = (uint)((1 << (uVar9 - 0x60 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8) +
                                      0xc)) != 0);
        }
        puVar7 = puVar7 + 2;
        if (-1 < iVar11) {
          puVar12 = (undefined4 *)(iVar5 + iVar11 * 4);
          puVar6 = (undefined4 *)(param_2 + iVar11 * 0x10);
          iVar13 = iVar14;
          do {
            uVar8 = *puVar6;
            uVar1 = puVar6[1];
            uVar2 = puVar6[2];
            uVar3 = puVar6[3];
            puVar6 = puVar6 + -4;
            uVar4 = *puVar12;
            puVar12 = puVar12 + -1;
            puVar7[1] = uVar8;
            puVar7[2] = uVar1;
            puVar7[3] = uVar2;
            *puVar7 = uVar4;
            puVar7[4] = uVar3;
            puVar7 = puVar7 + 5;
            iVar13 = iVar13 + -1;
          } while (iVar13 != 0);
        }
        param_2 = param_2 + iVar14 * 0x10;
        uVar9 = uVar9 + 1;
      } while (param_2 < uVar10);
    }
    *puVar7 = 0x92b;
    puVar7[3] = 0;
    puVar7[2] = ((unsigned char *)0x00001393U);
    puVar7[1] = 0;
    *(undefined4 **)(param_1 + 0x298c) = puVar7 + 4;
                    
                    
    (**(code **)(param_1 + 0x299c))(param_1 + 0x240);
    return;
  }
  return;
}

/* FUN_00039d40 @ 0x39d40 (724 bytes) */
void FUN_00039d40(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9)
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  undefined4 *puVar12;
  int iVar13;
  int iVar14;
  double in_stack_ffffffa8;
  
  uVar8 = 5;
  iVar5 = ((uint (*)())FUN_0002cc30)(param_1,0,5,param_3,param_5,param_6,fparam_1,fparam_2,fparam_3,fparam_4,
                       fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffffa8);
  if (iVar5 != 0) {
    iVar13 = *(int *)(param_1 + 0x29e8);
    iVar11 = *(int *)(**(int **)(param_1 + 0x1cc) + 4);
    iVar14 = *(int *)(iVar11 + 0x20);
    puVar6 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (param_1 + 0x240,
                        iVar14 * iVar5 * 5 + iVar5 * 2 +
                        (*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe) + 0x16,uVar8,param_3,param_5,
                        iVar5 * 2,iVar11,iVar13);
    *(undefined4 **)(param_1 + 0x298c) = puVar6;
    if (*(code **)(param_1 + 0x2680) != 0x00001e24 + param_1) {
      *(code **)(param_1 + 0x2680) = 0x00001e24 + param_1;
      *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
      *(undefined4 *)(0x000026c8 + param_1 + 4) = *(undefined4 *)(param_1 + 0x1ee4);
      puVar6 = (undefined4 *)FUN_0002c0c0(param_1,puVar6);
    }
    if (*(char *)(param_1 + 0x2a42) == '\0') {
      *puVar6 = 0x5c8;
      puVar6[1] = 0x10000000;
      puVar6 = puVar6 + 2;
      *(undefined1 *)(param_1 + 0x2a42) = 1;
    }
    puVar7 = puVar6 + 4;
    *puVar6 = 0x82c;
    uVar10 = param_2 + iVar5 * iVar14 * 4 * 4;
    uVar8 = *(undefined4 *)(0x00001dc4 + param_1);
    puVar6[2] = 0x821;
    puVar6[3] = 6;
    puVar6[1] = uVar8;
    iVar5 = *(int *)(iVar13 + 0x2c);
    *(undefined1 *)(param_1 + 0x2a5e) = 1;
    if (param_2 < uVar10) {
      iVar11 = iVar14 + -1;
      uVar9 = 0;
      do {
        *puVar7 = 0x917;
        if (uVar9 < 0x20) {
          puVar7[1] = (uint)((1 << (uVar9 & 0x3f) &
                             **(uint **)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8)) != 0);
        }
        else if (uVar9 < 0x40) {
          puVar7[1] = (uint)((1 << (uVar9 - 0x20 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8) + 4
                                      )) != 0);
        }
        else if (uVar9 < 0x60) {
          puVar7[1] = (uint)((1 << (uVar9 - 0x40 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8) + 8
                                      )) != 0);
        }
        else {
          puVar7[1] = (uint)((1 << (uVar9 - 0x60 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8) +
                                      0xc)) != 0);
        }
        puVar7 = puVar7 + 2;
        if (-1 < iVar11) {
          puVar12 = (undefined4 *)(iVar5 + iVar11 * 4);
          puVar6 = (undefined4 *)(param_2 + iVar11 * 0x10);
          iVar13 = iVar14;
          do {
            uVar8 = *puVar6;
            uVar1 = puVar6[1];
            uVar2 = puVar6[2];
            uVar3 = puVar6[3];
            puVar6 = puVar6 + -4;
            uVar4 = *puVar12;
            puVar12 = puVar12 + -1;
            puVar7[1] = uVar8;
            puVar7[2] = uVar1;
            puVar7[3] = uVar2;
            *puVar7 = uVar4;
            puVar7[4] = uVar3;
            puVar7 = puVar7 + 5;
            iVar13 = iVar13 + -1;
          } while (iVar13 != 0);
        }
        param_2 = param_2 + iVar14 * 0x10;
        uVar9 = uVar9 + 1;
      } while (param_2 < uVar10);
    }
    *puVar7 = 0x92b;
    puVar7[3] = 0;
    puVar7[2] = ((unsigned char *)0x00001393U);
    puVar7[1] = 0;
    *(undefined4 **)(param_1 + 0x298c) = puVar7 + 4;
                    
                    
    (**(code **)(param_1 + 0x299c))(param_1 + 0x240);
    return;
  }
  return;
}

/* FUN_0003a020 @ 0x3a020 (724 bytes) */
void FUN_0003a020(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9)
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  undefined4 *puVar12;
  int iVar13;
  int iVar14;
  double in_stack_ffffffa8;
  
  uVar8 = 7;
  iVar5 = ((uint (*)())FUN_0002cc30)(param_1,0,7,param_3,param_5,param_6,fparam_1,fparam_2,fparam_3,fparam_4,
                       fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffffa8);
  if (iVar5 != 0) {
    iVar13 = *(int *)(param_1 + 0x29e8);
    iVar11 = *(int *)(**(int **)(param_1 + 0x1cc) + 4);
    iVar14 = *(int *)(iVar11 + 0x20);
    puVar6 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (param_1 + 0x240,
                        iVar14 * iVar5 * 5 + iVar5 * 2 +
                        (*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe) + 0x16,uVar8,param_3,param_5,
                        iVar5 * 2,iVar11,iVar13);
    *(undefined4 **)(param_1 + 0x298c) = puVar6;
    if (*(code **)(param_1 + 0x2680) != 0x00001e24 + param_1) {
      *(code **)(param_1 + 0x2680) = 0x00001e24 + param_1;
      *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
      *(undefined4 *)(0x000026c8 + param_1 + 4) = *(undefined4 *)(param_1 + 0x1ee4);
      puVar6 = (undefined4 *)FUN_0002c0c0(param_1,puVar6);
    }
    if (*(char *)(param_1 + 0x2a42) == '\0') {
      *puVar6 = 0x5c8;
      puVar6[1] = 0x10000000;
      puVar6 = puVar6 + 2;
      *(undefined1 *)(param_1 + 0x2a42) = 1;
    }
    puVar7 = puVar6 + 4;
    *puVar6 = 0x82c;
    uVar10 = param_2 + iVar5 * iVar14 * 4 * 4;
    uVar8 = *(undefined4 *)(0x00001dc4 + param_1);
    puVar6[2] = 0x821;
    puVar6[3] = 0xd;
    puVar6[1] = uVar8;
    iVar5 = *(int *)(iVar13 + 0x2c);
    *(undefined1 *)(param_1 + 0x2a5e) = 1;
    if (param_2 < uVar10) {
      iVar11 = iVar14 + -1;
      uVar9 = 0;
      do {
        *puVar7 = 0x917;
        if (uVar9 < 0x20) {
          puVar7[1] = (uint)((1 << (uVar9 & 0x3f) &
                             **(uint **)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8)) != 0);
        }
        else if (uVar9 < 0x40) {
          puVar7[1] = (uint)((1 << (uVar9 - 0x20 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8) + 4
                                      )) != 0);
        }
        else if (uVar9 < 0x60) {
          puVar7[1] = (uint)((1 << (uVar9 - 0x40 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8) + 8
                                      )) != 0);
        }
        else {
          puVar7[1] = (uint)((1 << (uVar9 - 0x60 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8) +
                                      0xc)) != 0);
        }
        puVar7 = puVar7 + 2;
        if (-1 < iVar11) {
          puVar12 = (undefined4 *)(iVar5 + iVar11 * 4);
          puVar6 = (undefined4 *)(param_2 + iVar11 * 0x10);
          iVar13 = iVar14;
          do {
            uVar8 = *puVar6;
            uVar1 = puVar6[1];
            uVar2 = puVar6[2];
            uVar3 = puVar6[3];
            puVar6 = puVar6 + -4;
            uVar4 = *puVar12;
            puVar12 = puVar12 + -1;
            puVar7[1] = uVar8;
            puVar7[2] = uVar1;
            puVar7[3] = uVar2;
            *puVar7 = uVar4;
            puVar7[4] = uVar3;
            puVar7 = puVar7 + 5;
            iVar13 = iVar13 + -1;
          } while (iVar13 != 0);
        }
        param_2 = param_2 + iVar14 * 0x10;
        uVar9 = uVar9 + 1;
      } while (param_2 < uVar10);
    }
    *puVar7 = 0x92b;
    puVar7[3] = 0;
    puVar7[2] = ((unsigned char *)0x00001393U);
    puVar7[1] = 0;
    *(undefined4 **)(param_1 + 0x298c) = puVar7 + 4;
                    
                    
    (**(code **)(param_1 + 0x299c))(param_1 + 0x240);
    return;
  }
  return;
}

/* FUN_0003a300 @ 0x3a300 (724 bytes) */
void FUN_0003a300(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9)
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  undefined4 *puVar12;
  int iVar13;
  int iVar14;
  double in_stack_ffffffa8;
  
  uVar8 = 8;
  iVar5 = ((uint (*)())FUN_0002cc30)(param_1,0,8,param_3,param_5,param_6,fparam_1,fparam_2,fparam_3,fparam_4,
                       fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffffa8);
  if (iVar5 != 0) {
    iVar13 = *(int *)(param_1 + 0x29e8);
    iVar11 = *(int *)(**(int **)(param_1 + 0x1cc) + 4);
    iVar14 = *(int *)(iVar11 + 0x20);
    puVar6 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (param_1 + 0x240,
                        iVar14 * iVar5 * 5 + iVar5 * 2 +
                        (*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe) + 0x16,uVar8,param_3,param_5,
                        iVar5 * 2,iVar11,iVar13);
    *(undefined4 **)(param_1 + 0x298c) = puVar6;
    if (*(code **)(param_1 + 0x2680) != 0x00001e24 + param_1) {
      *(code **)(param_1 + 0x2680) = 0x00001e24 + param_1;
      *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
      *(undefined4 *)(0x000026c8 + param_1 + 4) = *(undefined4 *)(param_1 + 0x1ee4);
      puVar6 = (undefined4 *)FUN_0002c0c0(param_1,puVar6);
    }
    if (*(char *)(param_1 + 0x2a42) == '\0') {
      *puVar6 = 0x5c8;
      puVar6[1] = 0x10000000;
      puVar6 = puVar6 + 2;
      *(undefined1 *)(param_1 + 0x2a42) = 1;
    }
    puVar7 = puVar6 + 4;
    *puVar6 = 0x82c;
    uVar10 = param_2 + iVar5 * iVar14 * 4 * 4;
    uVar8 = *(undefined4 *)(0x00001dc4 + param_1);
    puVar6[2] = 0x821;
    puVar6[3] = 0xe;
    puVar6[1] = uVar8;
    iVar5 = *(int *)(iVar13 + 0x2c);
    *(undefined1 *)(param_1 + 0x2a5e) = 1;
    if (param_2 < uVar10) {
      iVar11 = iVar14 + -1;
      uVar9 = 0;
      do {
        *puVar7 = 0x917;
        if (uVar9 < 0x20) {
          puVar7[1] = (uint)((1 << (uVar9 & 0x3f) &
                             **(uint **)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8)) != 0);
        }
        else if (uVar9 < 0x40) {
          puVar7[1] = (uint)((1 << (uVar9 - 0x20 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8) + 4
                                      )) != 0);
        }
        else if (uVar9 < 0x60) {
          puVar7[1] = (uint)((1 << (uVar9 - 0x40 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8) + 8
                                      )) != 0);
        }
        else {
          puVar7[1] = (uint)((1 << (uVar9 - 0x60 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8) +
                                      0xc)) != 0);
        }
        puVar7 = puVar7 + 2;
        if (-1 < iVar11) {
          puVar12 = (undefined4 *)(iVar5 + iVar11 * 4);
          puVar6 = (undefined4 *)(param_2 + iVar11 * 0x10);
          iVar13 = iVar14;
          do {
            uVar8 = *puVar6;
            uVar1 = puVar6[1];
            uVar2 = puVar6[2];
            uVar3 = puVar6[3];
            puVar6 = puVar6 + -4;
            uVar4 = *puVar12;
            puVar12 = puVar12 + -1;
            puVar7[1] = uVar8;
            puVar7[2] = uVar1;
            puVar7[3] = uVar2;
            *puVar7 = uVar4;
            puVar7[4] = uVar3;
            puVar7 = puVar7 + 5;
            iVar13 = iVar13 + -1;
          } while (iVar13 != 0);
        }
        param_2 = param_2 + iVar14 * 0x10;
        uVar9 = uVar9 + 1;
      } while (param_2 < uVar10);
    }
    *puVar7 = 0x92b;
    puVar7[3] = 0;
    puVar7[2] = ((unsigned char *)0x00001393U);
    puVar7[1] = 0;
    *(undefined4 **)(param_1 + 0x298c) = puVar7 + 4;
                    
                    
    (**(code **)(param_1 + 0x299c))(param_1 + 0x240);
    return;
  }
  return;
}

/* FUN_0003a5e0 @ 0x3a5e0 (724 bytes) */
void FUN_0003a5e0(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9)
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  undefined4 *puVar12;
  int iVar13;
  int iVar14;
  double in_stack_ffffffa8;
  
  uVar8 = 9;
  iVar5 = ((uint (*)())FUN_0002cc30)(param_1,0,9,param_3,param_5,param_6,fparam_1,fparam_2,fparam_3,fparam_4,
                       fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffffa8);
  if (iVar5 != 0) {
    iVar13 = *(int *)(param_1 + 0x29e8);
    iVar11 = *(int *)(**(int **)(param_1 + 0x1cc) + 4);
    iVar14 = *(int *)(iVar11 + 0x20);
    puVar6 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (param_1 + 0x240,
                        iVar14 * iVar5 * 5 + iVar5 * 2 +
                        (*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe) + 0x16,uVar8,param_3,param_5,
                        iVar5 * 2,iVar11,iVar13);
    *(undefined4 **)(param_1 + 0x298c) = puVar6;
    if (*(code **)(param_1 + 0x2680) != 0x00001e24 + param_1) {
      *(code **)(param_1 + 0x2680) = 0x00001e24 + param_1;
      *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
      *(undefined4 *)(0x000026c8 + param_1 + 4) = *(undefined4 *)(param_1 + 0x1ee4);
      puVar6 = (undefined4 *)FUN_0002c0c0(param_1,puVar6);
    }
    if (*(char *)(param_1 + 0x2a42) == '\0') {
      *puVar6 = 0x5c8;
      puVar6[1] = 0x10000000;
      puVar6 = puVar6 + 2;
      *(undefined1 *)(param_1 + 0x2a42) = 1;
    }
    puVar7 = puVar6 + 4;
    *puVar6 = 0x82c;
    uVar10 = param_2 + iVar5 * iVar14 * 4 * 4;
    uVar8 = *(undefined4 *)(0x00001dc4 + param_1);
    puVar6[2] = 0x821;
    puVar6[3] = 0xf;
    puVar6[1] = uVar8;
    iVar5 = *(int *)(iVar13 + 0x2c);
    *(undefined1 *)(param_1 + 0x2a5e) = 1;
    if (param_2 < uVar10) {
      iVar11 = iVar14 + -1;
      uVar9 = 0;
      do {
        *puVar7 = 0x917;
        if (uVar9 < 0x20) {
          puVar7[1] = (uint)((1 << (uVar9 & 0x3f) &
                             **(uint **)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8)) != 0);
        }
        else if (uVar9 < 0x40) {
          puVar7[1] = (uint)((1 << (uVar9 - 0x20 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8) + 4
                                      )) != 0);
        }
        else if (uVar9 < 0x60) {
          puVar7[1] = (uint)((1 << (uVar9 - 0x40 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8) + 8
                                      )) != 0);
        }
        else {
          puVar7[1] = (uint)((1 << (uVar9 - 0x60 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8) +
                                      0xc)) != 0);
        }
        puVar7 = puVar7 + 2;
        if (-1 < iVar11) {
          puVar12 = (undefined4 *)(iVar5 + iVar11 * 4);
          puVar6 = (undefined4 *)(param_2 + iVar11 * 0x10);
          iVar13 = iVar14;
          do {
            uVar8 = *puVar6;
            uVar1 = puVar6[1];
            uVar2 = puVar6[2];
            uVar3 = puVar6[3];
            puVar6 = puVar6 + -4;
            uVar4 = *puVar12;
            puVar12 = puVar12 + -1;
            puVar7[1] = uVar8;
            puVar7[2] = uVar1;
            puVar7[3] = uVar2;
            *puVar7 = uVar4;
            puVar7[4] = uVar3;
            puVar7 = puVar7 + 5;
            iVar13 = iVar13 + -1;
          } while (iVar13 != 0);
        }
        param_2 = param_2 + iVar14 * 0x10;
        uVar9 = uVar9 + 1;
      } while (param_2 < uVar10);
    }
    *puVar7 = 0x92b;
    puVar7[3] = 0;
    puVar7[2] = ((unsigned char *)0x00001393U);
    puVar7[1] = 0;
    *(undefined4 **)(param_1 + 0x298c) = puVar7 + 4;
                    
                    
    (**(code **)(param_1 + 0x299c))(param_1 + 0x240);
    return;
  }
  return;
}

/* FUN_0003a8c0 @ 0x3a8c0 (724 bytes) */
void FUN_0003a8c0(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9)
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  undefined4 *puVar12;
  int iVar13;
  int iVar14;
  double in_stack_ffffffa8;
  
  uVar8 = 0;
  iVar5 = ((uint (*)())FUN_0002cc30)(param_1,0,0,param_3,param_5,param_6,fparam_1,fparam_2,fparam_3,fparam_4,
                       fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffffa8);
  if (iVar5 != 0) {
    iVar13 = *(int *)(param_1 + 0x29e8);
    iVar11 = *(int *)(**(int **)(param_1 + 0x1cc) + 4);
    iVar14 = *(int *)(iVar11 + 0x20);
    puVar6 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (param_1 + 0x240,
                        iVar14 * iVar5 * 5 + iVar5 * 2 +
                        (*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe) + 0x16,uVar8,param_3,param_5,
                        iVar5 * 2,iVar11,iVar13);
    *(undefined4 **)(param_1 + 0x298c) = puVar6;
    if (*(code **)(param_1 + 0x2680) != 0x00001e24 + param_1) {
      *(code **)(param_1 + 0x2680) = 0x00001e24 + param_1;
      *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
      *(undefined4 *)(0x000026c8 + param_1 + 4) = *(undefined4 *)(param_1 + 0x1ee4);
      puVar6 = (undefined4 *)FUN_0002c0c0(param_1,puVar6);
    }
    if (*(char *)(param_1 + 0x2a42) == '\0') {
      *puVar6 = 0x5c8;
      puVar6[1] = 0x10000000;
      puVar6 = puVar6 + 2;
      *(undefined1 *)(param_1 + 0x2a42) = 1;
    }
    *puVar6 = 0x82c;
    puVar7 = puVar6 + 4;
    uVar10 = param_2 + iVar5 * iVar14 * 4 * 4;
    uVar8 = *(undefined4 *)(0x00001dc4 + param_1);
    puVar6[2] = 0x821;
    puVar6[3] = 1;
    puVar6[1] = uVar8;
    iVar5 = *(int *)(iVar13 + 0x2c);
    *(undefined1 *)(param_1 + 0x2a5e) = 1;
    if (param_2 < uVar10) {
      iVar11 = iVar14 + -1;
      uVar9 = 0;
      do {
        *puVar7 = 0x917;
        if (uVar9 < 0x20) {
          puVar7[1] = (uint)((1 << (uVar9 & 0x3f) &
                             **(uint **)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8)) != 0);
        }
        else if (uVar9 < 0x40) {
          puVar7[1] = (uint)((1 << (uVar9 - 0x20 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8) + 4
                                      )) != 0);
        }
        else if (uVar9 < 0x60) {
          puVar7[1] = (uint)((1 << (uVar9 - 0x40 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8) + 8
                                      )) != 0);
        }
        else {
          puVar7[1] = (uint)((1 << (uVar9 - 0x60 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8) +
                                      0xc)) != 0);
        }
        puVar7 = puVar7 + 2;
        if (-1 < iVar11) {
          puVar12 = (undefined4 *)(iVar5 + iVar11 * 4);
          puVar6 = (undefined4 *)(param_2 + iVar11 * 0x10);
          iVar13 = iVar14;
          do {
            uVar8 = *puVar6;
            uVar1 = puVar6[1];
            uVar2 = puVar6[2];
            uVar3 = puVar6[3];
            puVar6 = puVar6 + -4;
            uVar4 = *puVar12;
            puVar12 = puVar12 + -1;
            puVar7[1] = uVar8;
            puVar7[2] = uVar1;
            puVar7[3] = uVar2;
            *puVar7 = uVar4;
            puVar7[4] = uVar3;
            puVar7 = puVar7 + 5;
            iVar13 = iVar13 + -1;
          } while (iVar13 != 0);
        }
        param_2 = param_2 + iVar14 * 0x10;
        uVar9 = uVar9 + 1;
      } while (param_2 < uVar10);
    }
    *puVar7 = 0x92b;
    puVar7[3] = 0;
    puVar7[2] = ((unsigned char *)0x00001393U);
    puVar7[1] = 0;
    *(undefined4 **)(param_1 + 0x298c) = puVar7 + 4;
                    
                    
    (**(code **)(param_1 + 0x299c))(param_1 + 0x240);
    return;
  }
  return;
}

/* FUN_0003aba0 @ 0x3aba0 (724 bytes) */
void FUN_0003aba0(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9)
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  undefined4 *puVar12;
  int iVar13;
  int iVar14;
  double in_stack_ffffffa8;
  
  uVar8 = 1;
  iVar5 = ((uint (*)())FUN_0002cc30)(param_1,0,1,param_3,param_5,param_6,fparam_1,fparam_2,fparam_3,fparam_4,
                       fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffffa8);
  if (iVar5 != 0) {
    iVar13 = *(int *)(param_1 + 0x29e8);
    iVar11 = *(int *)(**(int **)(param_1 + 0x1cc) + 4);
    iVar14 = *(int *)(iVar11 + 0x20);
    puVar6 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (param_1 + 0x240,
                        iVar14 * iVar5 * 5 + iVar5 * 2 +
                        (*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe) + 0x16,uVar8,param_3,param_5,
                        iVar5 * 2,iVar11,iVar13);
    *(undefined4 **)(param_1 + 0x298c) = puVar6;
    if (*(code **)(param_1 + 0x2680) != 0x00001e24 + param_1) {
      *(code **)(param_1 + 0x2680) = 0x00001e24 + param_1;
      *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
      *(undefined4 *)(0x000026c8 + param_1 + 4) = *(undefined4 *)(param_1 + 0x1ee4);
      puVar6 = (undefined4 *)FUN_0002c0c0(param_1,puVar6);
    }
    if (*(char *)(param_1 + 0x2a42) == '\0') {
      *puVar6 = 0x5c8;
      puVar6[1] = 0x10000000;
      puVar6 = puVar6 + 2;
      *(undefined1 *)(param_1 + 0x2a42) = 1;
    }
    puVar7 = puVar6 + 4;
    *puVar6 = 0x82c;
    uVar10 = param_2 + iVar5 * iVar14 * 4 * 4;
    uVar8 = *(undefined4 *)(0x00001dc4 + param_1);
    puVar6[2] = 0x821;
    puVar6[3] = 2;
    puVar6[1] = uVar8;
    iVar5 = *(int *)(iVar13 + 0x2c);
    *(undefined1 *)(param_1 + 0x2a5e) = 1;
    if (param_2 < uVar10) {
      iVar11 = iVar14 + -1;
      uVar9 = 0;
      do {
        *puVar7 = 0x917;
        if (uVar9 < 0x20) {
          puVar7[1] = (uint)((1 << (uVar9 & 0x3f) &
                             **(uint **)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8)) != 0);
        }
        else if (uVar9 < 0x40) {
          puVar7[1] = (uint)((1 << (uVar9 - 0x20 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8) + 4
                                      )) != 0);
        }
        else if (uVar9 < 0x60) {
          puVar7[1] = (uint)((1 << (uVar9 - 0x40 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8) + 8
                                      )) != 0);
        }
        else {
          puVar7[1] = (uint)((1 << (uVar9 - 0x60 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8) +
                                      0xc)) != 0);
        }
        puVar7 = puVar7 + 2;
        if (-1 < iVar11) {
          puVar12 = (undefined4 *)(iVar5 + iVar11 * 4);
          puVar6 = (undefined4 *)(param_2 + iVar11 * 0x10);
          iVar13 = iVar14;
          do {
            uVar8 = *puVar6;
            uVar1 = puVar6[1];
            uVar2 = puVar6[2];
            uVar3 = puVar6[3];
            puVar6 = puVar6 + -4;
            uVar4 = *puVar12;
            puVar12 = puVar12 + -1;
            puVar7[1] = uVar8;
            puVar7[2] = uVar1;
            puVar7[3] = uVar2;
            *puVar7 = uVar4;
            puVar7[4] = uVar3;
            puVar7 = puVar7 + 5;
            iVar13 = iVar13 + -1;
          } while (iVar13 != 0);
        }
        param_2 = param_2 + iVar14 * 0x10;
        uVar9 = uVar9 + 1;
      } while (param_2 < uVar10);
    }
    *puVar7 = 0x92b;
    puVar7[3] = 0;
    puVar7[2] = ((unsigned char *)0x00001393U);
    puVar7[1] = 0;
    *(undefined4 **)(param_1 + 0x298c) = puVar7 + 4;
                    
                    
    (**(code **)(param_1 + 0x299c))(param_1 + 0x240);
    return;
  }
  return;
}

/* FUN_0003ae80 @ 0x3ae80 (724 bytes) */
void FUN_0003ae80(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9)
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  undefined4 *puVar12;
  int iVar13;
  int iVar14;
  double in_stack_ffffffa8;
  
  uVar8 = 2;
  iVar5 = ((uint (*)())FUN_0002cc30)(param_1,param_4,2,param_3,param_5,param_6,fparam_1,fparam_2,fparam_3,fparam_4
                       ,fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffffa8);
  if (iVar5 != 0) {
    iVar13 = *(int *)(param_1 + 0x29e8);
    iVar11 = *(int *)(**(int **)(param_1 + 0x1cc) + 4);
    iVar14 = *(int *)(iVar11 + 0x20);
    puVar6 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (param_1 + 0x240,
                        iVar14 * iVar5 * 5 + iVar5 * 2 +
                        (*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe) + 0x16,uVar8,param_3,param_5,
                        iVar5 * 2,iVar11,iVar13);
    *(undefined4 **)(param_1 + 0x298c) = puVar6;
    if (*(code **)(param_1 + 0x2680) != 0x00001e24 + param_1) {
      *(code **)(param_1 + 0x2680) = 0x00001e24 + param_1;
      *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
      *(undefined4 *)(0x000026c8 + param_1 + 4) = *(undefined4 *)(param_1 + 0x1ee4);
      puVar6 = (undefined4 *)FUN_0002c0c0(param_1,puVar6);
    }
    if (*(char *)(param_1 + 0x2a42) == '\0') {
      *puVar6 = 0x5c8;
      puVar6[1] = 0x10000000;
      puVar6 = puVar6 + 2;
      *(undefined1 *)(param_1 + 0x2a42) = 1;
    }
    puVar7 = puVar6 + 4;
    *puVar6 = 0x82c;
    uVar10 = param_2 + iVar5 * iVar14 * 4 * 4;
    uVar8 = *(undefined4 *)(0x00001dc4 + param_1);
    puVar6[2] = 0x821;
    puVar6[3] = 0xc;
    puVar6[1] = uVar8;
    iVar5 = *(int *)(iVar13 + 0x2c);
    *(undefined1 *)(param_1 + 0x2a5e) = 1;
    if (param_2 < uVar10) {
      iVar11 = iVar14 + -1;
      uVar9 = 0;
      do {
        *puVar7 = 0x917;
        if (uVar9 < 0x20) {
          puVar7[1] = (uint)((1 << (uVar9 & 0x3f) &
                             **(uint **)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8)) != 0);
        }
        else if (uVar9 < 0x40) {
          puVar7[1] = (uint)((1 << (uVar9 - 0x20 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8) + 4
                                      )) != 0);
        }
        else if (uVar9 < 0x60) {
          puVar7[1] = (uint)((1 << (uVar9 - 0x40 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8) + 8
                                      )) != 0);
        }
        else {
          puVar7[1] = (uint)((1 << (uVar9 - 0x60 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(param_1 + 0x10) + 8) +
                                      0xc)) != 0);
        }
        puVar7 = puVar7 + 2;
        if (-1 < iVar11) {
          puVar12 = (undefined4 *)(iVar5 + iVar11 * 4);
          puVar6 = (undefined4 *)(param_2 + iVar11 * 0x10);
          iVar13 = iVar14;
          do {
            uVar8 = *puVar6;
            uVar1 = puVar6[1];
            uVar2 = puVar6[2];
            uVar3 = puVar6[3];
            puVar6 = puVar6 + -4;
            uVar4 = *puVar12;
            puVar12 = puVar12 + -1;
            puVar7[1] = uVar8;
            puVar7[2] = uVar1;
            puVar7[3] = uVar2;
            *puVar7 = uVar4;
            puVar7[4] = uVar3;
            puVar7 = puVar7 + 5;
            iVar13 = iVar13 + -1;
          } while (iVar13 != 0);
        }
        param_2 = param_2 + iVar14 * 0x10;
        uVar9 = uVar9 + 1;
      } while (param_2 < uVar10);
    }
    *puVar7 = 0x92b;
    puVar7[3] = 0;
    puVar7[2] = ((unsigned char *)0x00001393U);
    puVar7[1] = 0;
    *(undefined4 **)(param_1 + 0x298c) = puVar7 + 4;
                    
                    
    (**(code **)(param_1 + 0x299c))(param_1 + 0x240);
    return;
  }
  return;
}

/* FUN_0003b160 @ 0x3b160 (284 bytes) */
int FUN_0003b160(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  
  piVar5 = *(int **)(param_1 + 0x1cc);
  if ((param_2 == 0) || (uVar4 = 0, (*(uint *)(param_2 + 0xc) & 0x4400000) != 0)) {
    uVar4 = 2;
  }
  if ((piVar5 != (int *)0x0) &&
     (((param_2 == 0 || ((*(uint *)(param_2 + 8) & 0xff00) != 0)) ||
      ((*(uint *)(param_2 + 0xc) & 0x4c00000) != 0)))) {
    uVar4 = uVar4 | 1;
  }
  FUN_00053000(param_1 + 0x240,uVar4);
  iVar1 = *(int *)(param_1 + 0x29e8) + 0x14;
  if ((uVar4 & 1) != 0) {
    iVar2 = piVar5[0xd];
    if (((iVar2 == 0) && (iVar2 = piVar5[0xc], iVar2 == 0)) && (iVar2 = piVar5[0xb], iVar2 == 0)) {
      iVar3 = *piVar5;
      iVar2 = *(int *)(iVar3 + 4);
    }
    else {
      iVar3 = *piVar5;
    }
    if ((uVar4 & 2) == 0) {
      ((int (*)())FUN_0003d590)(param_1,iVar1,*(undefined4 *)(iVar2 + 0x28),iVar2 + *(int *)(iVar2 + 0x2c) * 8,
                   *(undefined4 *)(iVar3 + 0x18),param_2 + 0x14);
    }
    else {
      ((int (*)())FUN_0003b870)(param_1,iVar1,*(undefined4 *)(iVar2 + 0x28),iVar2 + *(int *)(iVar2 + 0x2c) * 8,
                   *(undefined4 *)(iVar3 + 0x18));
    }
  }
  return param_3;
}

/* FUN_0003b280 @ 0x3b280 (772 bytes) */
int FUN_0003b280(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  uint param_3;
  int param_4;
  uint param_5;
  int param_6;
  undefined4 param_7;
  int param_8;
{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  uint uVar10;
  uint *puVar11;
  uint *puVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  undefined4 *puVar16;
  int iVar17;
  uint *puVar18;
  uint local_50 [4];
  
  if (*(uint *)(param_2 + 0x24) != param_3) {
    if (*(int *)(param_2 + 0x28) != 0) {
      (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x28));
      *(undefined4 *)(param_2 + 0x28) = 0;
    }
    if (param_3 != 0) {
      uVar7 = (**(code **)(param_1 + 0x10))(param_3,4);
      *(undefined4 *)(param_2 + 0x28) = uVar7;
    }
  }
  *(uint *)(param_2 + 0x24) = param_3;
  if (*(char *)(param_2 + 0x8c) != '\0') {
    iVar15 = 0;
    iVar17 = param_2;
    do {
      uVar7 = FUN_00054460(param_1,0x87bf,0x87c2,0x87e1,1);
      bVar1 = iVar15 != 3;
      iVar15 = iVar15 + 1;
      *(undefined4 *)(iVar17 + 0x68) = uVar7;
      iVar17 = iVar17 + 4;
    } while (bVar1);
  }
  if (param_3 != 0) {
    iVar17 = *(int *)(param_2 + 0x28);
    uVar14 = 0;
    uVar13 = 0;
    puVar9 = (undefined1 *)((unsigned int)__builtin_frame_address(0));
    do {
      if (uVar13 < param_5) {
        local_50[0] = *(uint *)(uVar13 * 8 + param_6);
        local_50[1] = *(uint *)(uVar13 * 8 + param_6 + 4);
        if ((uVar14 < (local_50[0] & 0xffff)) || ((local_50[1] & 0xffff) <= uVar14))
        goto LAB_0003b3e0;
        uVar13 = uVar13 + 1;
        iVar15 = ((local_50[1] & 0xffff) - (local_50[0] & 0xffff)) + 1;
      }
      else {
LAB_0003b3e0:
        iVar15 = 1;
      }
      puVar18 = (uint *)(uVar14 * 8 + param_4);
      if ((*(uint *)(param_4 + uVar14 * 8) & 0x1f0000) != 0) {
        iVar4 = -(iVar15 + 0x1eU & 0xfffffff0);
        *(undefined1 **)(&STACKARG(0xffffff70) + iVar4) = puVar9;
        iVar6 = -(iVar15 * 4 + 0x1eU & 0xfffffff0);
        puVar8 = (undefined1 *)((int)local_50 + iVar4);
        puVar2 = (undefined4 *)((int)(&STACKARG(0xffffff70) + iVar4) + iVar6);
        *puVar2 = puVar9;
        puVar3 = (undefined4 *)((int)puVar2 + iVar6);
        *puVar3 = puVar9;
        puVar16 = puVar3 + 0x10;
        puVar12 = puVar18;
        bVar1 = iVar15 != 0;
        puVar9 = puVar8;
        puVar11 = puVar2 + 0x10;
        iVar4 = iVar15;
        while (bVar1) {
          uVar5 = *puVar12;
          uVar10 = uVar5 >> 0x10 & 0x1f;
          if (uVar10 == 2) {
            *puVar9 = 0;
            *puVar11 = uVar5 & 0xffff;
          }
          else if (uVar10 == 0x11) {
            *puVar9 = 1;
            *puVar11 = 0;
          }
          else {
            *puVar9 = 2;
            *puVar11 = 0;
          }
          puVar12 = puVar12 + 2;
          puVar9 = puVar9 + 1;
          puVar11 = puVar11 + 1;
          iVar4 = iVar4 + -1;
          bVar1 = iVar4 != 0;
        }
        FUN_000534c0(param_1,iVar15,puVar8,puVar2 + 0x10,puVar16);
        if (iVar15 != 0) {
          iVar4 = 0;
          do {
            uVar5 = *puVar18;
            uVar7 = *puVar16;
            *(undefined4 *)(iVar17 + (puVar18[1] & 0xffff) * 4) = uVar7;
            if ((uVar5 >> 0x10 & 0x1f) == 0x11) {
              FUN_000547f0(param_1,uVar7,((unsigned char *)0x00001406U),(uVar5 & 0xffff) * 0x10 + param_8);
            }
            iVar4 = iVar4 + 1;
            puVar18 = puVar18 + 2;
            puVar16 = puVar16 + 1;
          } while (iVar15 != iVar4);
          uVar14 = uVar14 + iVar4;
        }
        puVar9 = (undefined1 *)*puVar3;
        uVar14 = uVar14 - 1;
      }
      uVar14 = uVar14 + 1;
    } while (uVar14 < param_3);
  }
  return;
}

/* FUN_0003b5b0 @ 0x3b5b0 (100 bytes) */
int FUN_0003b5b0(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int iVar1;
  
  iVar1 = *param_2;
  if (iVar1 == 0) {
    iVar1 = FUN_00053dc0(param_1,1);
    *param_2 = iVar1;
    if (iVar1 == 0) {
      return 0;
    }
  }
  thunk_FUN_00053b60(param_1,iVar1);
  return 1;
}

/* FUN_0003b620 @ 0x3b620 (592 bytes) */
int FUN_0003b620(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  uint *param_5;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  short sVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined4 local_418 [258];
  
  if (*(char *)(param_3 + 0x8c) == '\0') {
    *(undefined4 *)(param_2 + 0x800) = 0;
  }
  else {
    *(undefined2 *)(param_2 + 2) = 0;
    *(undefined2 *)(param_2 + 10) = 1;
    *(undefined4 *)(param_2 + 0x800) = 4;
    *(undefined2 *)(param_2 + 0x12) = 2;
    *(undefined2 *)(param_2 + 0x1a) = 3;
    local_418[0] = *(undefined4 *)(param_3 + 0x68);
    local_418[1] = *(undefined4 *)(param_3 + 0x6c);
    local_418[2] = *(undefined4 *)(param_3 + 0x70);
    local_418[3] = *(undefined4 *)(param_3 + 0x74);
  }
  if (param_4 == 0) {
    iVar7 = *(int *)(param_2 + 0x800);
    *(int *)(param_2 + 0x804) = iVar7;
    *(int *)(param_2 + 0x808) = iVar7;
  }
  else {
    iVar3 = *(int *)(param_3 + 0x28);
    iVar7 = *(int *)(param_2 + 0x800);
    puVar4 = param_5;
    iVar8 = param_4;
    do {
      if ((*puVar4 & 0x1fc700) == 0x100000) {
        iVar1 = param_2 + iVar7 * 8;
        uVar6 = *(undefined4 *)(iVar3 + (uint)*(ushort *)((int)puVar4 + 6) * 4);
        *(char *)(iVar1 + 1) = (char)*(ushort *)((int)puVar4 + 6);
        local_418[iVar7] = uVar6;
        *(ushort *)(iVar1 + 2) = *(byte *)((int)puVar4 + 2) >> 4 & 3;
        iVar7 = *(int *)(param_2 + 0x800) + 1;
        *(int *)(param_2 + 0x800) = iVar7;
      }
      puVar4 = puVar4 + 2;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    *(int *)(param_2 + 0x804) = iVar7;
    iVar3 = *(int *)(param_3 + 0x28);
    puVar4 = param_5;
    iVar8 = param_4;
    do {
      if ((*puVar4 & 0x1f0000) == 0x20000) {
        iVar1 = param_2 + iVar7 * 8;
        uVar6 = *(undefined4 *)(iVar3 + (uint)*(ushort *)((int)puVar4 + 6) * 4);
        *(char *)(iVar1 + 1) = (char)*(ushort *)((int)puVar4 + 6);
        local_418[iVar7] = uVar6;
        *(short *)(iVar1 + 2) = (short)*puVar4;
        iVar7 = *(int *)(param_2 + 0x804) + 1;
        *(int *)(param_2 + 0x804) = iVar7;
      }
      puVar4 = puVar4 + 2;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    *(int *)(param_2 + 0x808) = iVar7;
    sVar5 = 0;
    do {
      uVar2 = *param_5 >> 0x10 & 0x1f;
      if ((((uVar2 != 0) && (uVar2 != 0x11)) && (uVar2 != 2)) && ((*param_5 & 0x1fc700) != 0x100000)
         ) {
        iVar8 = param_2 + iVar7 * 8;
        uVar6 = *(undefined4 *)(iVar3 + (uint)*(ushort *)((int)param_5 + 6) * 4);
        *(char *)(iVar8 + 1) = (char)*(ushort *)((int)param_5 + 6);
        *(short *)(iVar8 + 2) = sVar5;
        local_418[iVar7] = uVar6;
        iVar7 = *(int *)(param_2 + 0x808) + 1;
        *(int *)(param_2 + 0x808) = iVar7;
      }
      sVar5 = sVar5 + 1;
      param_5 = param_5 + 2;
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  FUN_00054590(param_1 + 0x240,param_2,iVar7,local_418);
  return;
}

/* FUN_0003b870 @ 0x3b870 (2500 bytes) */
int FUN_0003b870(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
{
  ushort *puVar1;
  byte bVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  undefined4 uVar9;
  float fVar10;
  int iVar11;
  undefined *puVar12;
  dword *pdVar13;
  undefined8 *puVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  float *pfVar21;
  undefined4 *puVar22;
  dword *pdVar23;
  int iVar24;
  dword *pdVar25;
  uint uVar26;
  float *pfVar27;
  byte *pbVar28;
  double dVar29;
  undefined8 uVar30;
  double dVar31;
  byte *local_68;
  int local_64;
  undefined1 auStack_60 [8];
  uint local_58;
  undefined4 local_54;
  uint local_50;
  undefined4 local_4c;
  
  iVar15 = FUN_00054470(param_1 + 0x240,&local_68,&local_64,auStack_60);
  if (iVar15 != 0) {
    ((int (*)())FUN_0003b620)(param_1,local_68,param_2,param_3,param_4);
  }
  iVar15 = *(int *)(local_68 + 0x800);
  pbVar28 = local_68;
  if (local_68 < local_68 + iVar15 * 8) {
    iVar16 = *(int *)(param_1 + 0x10) + 0x1860;
    do {
      puVar1 = (ushort *)(pbVar28 + 2);
      bVar2 = *pbVar28;
      puVar22 = *(undefined4 **)(pbVar28 + 4);
      pbVar28 = pbVar28 + 8;
      iVar19 = iVar16 + (uint)*puVar1 * 4;
      uVar9 = *(undefined4 *)(iVar16 + (uint)*puVar1 * 4);
      iVar11 = local_64 + (uint)bVar2 * 0x10;
      uVar3 = *(undefined4 *)(iVar19 + 0x30);
      uVar4 = *(undefined4 *)(iVar19 + 0x10);
      uVar5 = *(undefined4 *)(iVar19 + 0x20);
      *(undefined4 *)(local_64 + (uint)bVar2 * 0x10) = uVar9;
      *(undefined4 *)(iVar11 + 0xc) = uVar3;
      *(undefined4 *)(iVar11 + 4) = uVar4;
      *(undefined4 *)(iVar11 + 8) = uVar5;
      puVar22[3] = uVar3;
      *puVar22 = uVar9;
      puVar22[1] = uVar4;
      puVar22[2] = uVar5;
    } while (pbVar28 < local_68 + iVar15 * 8);
  }
  iVar15 = *(int *)(local_68 + 0x804);
  for (; pbVar28 < local_68 + iVar15 * 8; pbVar28 = pbVar28 + 8) {
    bVar2 = *pbVar28;
    uVar30 = (*(undefined8 **)(pbVar28 + 4))[1];
    *(undefined8 *)(local_64 + (uint)bVar2 * 0x10) = **(undefined8 **)(pbVar28 + 4);
    *(undefined8 *)(local_64 + (uint)bVar2 * 0x10 + 8) = uVar30;
  }
  iVar15 = *(int *)(local_68 + 0x808);
joined_r0x0003b9b0:
  if (local_68 + iVar15 * 8 <= pbVar28) {
    return;
  }
  local_58 = *(uint *)((uint)*(ushort *)(pbVar28 + 2) * 8 + param_4);
  pfVar27 = (float *)(local_64 + (uint)*pbVar28 * 0x10);
  local_54 = *(undefined4 *)((uint)*(ushort *)(pbVar28 + 2) * 8 + param_4 + 4);
  uVar20 = local_58 >> 0x10 & 0x1f;
  if (uVar20 == 1) {
    iVar16 = (local_58 & 0xffff) * 0x10;
    iVar11 = iVar16 + param_5;
    if (*(int *)(*(int *)(param_1 + 0x18) + 0x198) == 0) {
      fVar6 = *(float *)(iVar11 + 0xc);
      fVar7 = *(float *)(iVar11 + 4);
      fVar8 = *(float *)(iVar11 + 8);
      *(undefined4 *)(local_64 + (uint)*pbVar28 * 0x10) = *(undefined4 *)(iVar16 + param_5);
      pfVar27[3] = fVar6;
      pfVar27[1] = fVar7;
      pfVar27[2] = fVar8;
    }
    else {
      _glpUniformToFloat(*(undefined4 *)(**(int **)(param_1 + 0x1cc) + 4),local_58 & 0xffff,iVar11,
                         pfVar27);
    }
    goto LAB_0003c2d0;
  }
  local_50 = local_58;
  local_4c = local_54;
  if ((local_58 & 0x1f0000) == 0x100000) {
    uVar20 = local_58 >> 0xc & 3;
    uVar26 = local_58 & 0xff;
    switch(local_58 >> 8 & 7) {
    default:
      iVar16 = 0;
      break;
    case 1:
      iVar16 = 0xc0;
      break;
    case 2:
      iVar16 = 0x80;
      break;
    case 3:
      iVar16 = (uVar26 + 4) * 0x40;
      break;
    case 4:
      iVar16 = (uVar26 + 0x10) * 0x40;
      break;
    case 5:
      iVar16 = (uVar26 + 8) * 0x40;
    }
    uVar26 = local_58 >> 0xe & 3;
    iVar11 = *(int *)(param_1 + 0x10) + 0x1860 + iVar16;
    if ((1 < uVar26) && (iVar11 = iVar16 + *(int *)(param_1 + 0x10) + 0x1e60, 3 < uVar26)) {
      iVar11 = 0;
    }
    if (uVar26 < 3) {
      if (uVar26 == 0) {
LAB_0003bef8:
        iVar16 = uVar20 * 4;
        iVar19 = iVar11 + iVar16;
        *pfVar27 = *(float *)(iVar11 + iVar16);
        pfVar27[1] = *(float *)(iVar19 + 0x10);
        pfVar27[2] = *(float *)(iVar19 + 0x20);
        pfVar27[3] = *(float *)(iVar19 + 0x30);
      }
      else {
        iVar16 = uVar20 * 0x10;
        iVar19 = iVar11 + iVar16;
        *pfVar27 = *(float *)(iVar11 + iVar16);
        pfVar27[1] = *(float *)(iVar19 + 4);
        pfVar27[2] = *(float *)(iVar19 + 8);
        pfVar27[3] = *(float *)(iVar19 + 0xc);
      }
    }
    else if (uVar26 == 3) goto LAB_0003bef8;
    goto LAB_0003c2d0;
  }
  switch(uVar20) {
  case 0:
    pdVar25 = (dword *)(pfVar27 + 1);
    pdVar13 = (dword *)(pfVar27 + 2);
    pdVar23 = (dword *)(pfVar27 + 3);
    pfVar21 = pfVar27;
    break;
  default:
    goto switchD_0003bf70_caseD_1;
  case 2:
    pfVar21 = (float *)((local_58 & 0xffff) * 0x10 +
                       *(int *)(((unsigned char *)0x00004308) + *(int *)(param_1 + 0x10)));
    pdVar25 = (dword *)(pfVar21 + 1);
    pdVar13 = (dword *)(pfVar21 + 2);
    pdVar23 = (dword *)(pfVar21 + 3);
    break;
  case 3:
    uVar20 = local_58 & 0xff;
    switch(local_58 >> 8 & 0xf) {
    case 0:
      pfVar21 = (float *)(uVar20 * 0x80 + 0x24c0 + *(int *)(param_1 + 0x10));
      pdVar25 = (dword *)(pfVar21 + 1);
      pdVar13 = (dword *)(pfVar21 + 2);
      pdVar23 = (dword *)(pfVar21 + 3);
      break;
    case 1:
      pfVar21 = (float *)(uVar20 * 0x80 + 0x24d0 + *(int *)(param_1 + 0x10));
      pdVar25 = (dword *)(pfVar21 + 1);
      pdVar13 = (dword *)(pfVar21 + 2);
      pdVar23 = (dword *)(pfVar21 + 3);
      break;
    case 2:
      pfVar21 = (float *)(uVar20 * 0x80 + 0x24e0 + *(int *)(param_1 + 0x10));
      pdVar25 = (dword *)(pfVar21 + 1);
      pdVar13 = (dword *)(pfVar21 + 2);
      pdVar23 = (dword *)(pfVar21 + 3);
      break;
    case 3:
      pfVar21 = (float *)(uVar20 * 0x80 + 0x24f0 + *(int *)(param_1 + 0x10));
      pdVar25 = (dword *)(pfVar21 + 1);
      pdVar13 = (dword *)(pfVar21 + 2);
      pdVar23 = (dword *)(pfVar21 + 3);
      break;
    case 4:
      pfVar21 = (float *)(uVar20 * 0x80 + 0x2500 + *(int *)(param_1 + 0x10));
      pdVar25 = (dword *)(pfVar21 + 1);
      pdVar13 = (dword *)(pfVar21 + 2);
      pdVar23 = (dword *)(pfVar21 + 3);
      break;
    case 5:
      pfVar21 = (float *)(uVar20 * 0x80 + 0x2510 + *(int *)(param_1 + 0x10));
      pdVar25 = (dword *)(pfVar21 + 1);
      pdVar13 = (dword *)(pfVar21 + 2);
      pdVar23 = (dword *)(pfVar21 + 3);
      break;
    case 6:
      iVar16 = uVar20 * 0x80 + *(int *)(param_1 + 0x10);
      fVar7 = *(float *)(iVar16 + 0x24f4);
      fVar8 = *(float *)(iVar16 + 0x24f0);
      fVar10 = *(float *)(iVar16 + 0x24f8) + 1.0;
      dVar29 = _sqrt((double)(fVar10 * fVar10 + fVar8 * fVar8 + fVar7 * fVar7));
      pfVar27[3] = 1.0;
      fVar6 = (float)(1.0 / dVar29);
      pfVar27[2] = fVar10 * fVar6;
      *pfVar27 = fVar8 * fVar6;
      pfVar27[1] = fVar7 * fVar6;
      goto LAB_0003c2d0;
    case 7:
      pfVar21 = (float *)(uVar20 * 0x80 + 0x2530 + *(int *)(param_1 + 0x10));
      pdVar25 = (dword *)(pfVar21 + 1);
      pdVar13 = (dword *)(pfVar21 + 2);
      pdVar23 = (dword *)(pfVar21 + 3);
      break;
    default:
      goto switchD_0003bf70_caseD_1;
    }
    break;
  case 4:
    uVar20 = local_58 >> 9 & 3;
    iVar17 = *(int *)(param_1 + 0x10) + 0x24c0;
    iVar16 = (local_58 & 0xff) * 0x80;
    iVar11 = (local_58 >> 8 & 1) * 0x240;
    iVar19 = *(int *)(param_1 + 0x10) + 0x28c0;
    iVar24 = iVar17 + iVar16;
    iVar18 = iVar19 + iVar11;
    if (uVar20 == 1) {
      *pfVar27 = *(float *)(iVar24 + 0x10) * *(float *)(iVar18 + 0x10);
      pfVar27[1] = *(float *)(iVar24 + 0x14) * *(float *)(iVar18 + 0x14);
      pfVar27[2] = *(float *)(iVar24 + 0x18) * *(float *)(iVar18 + 0x18);
      pfVar27[3] = *(float *)(iVar18 + 0x1c);
    }
    else if (uVar20 == 2) {
      *pfVar27 = *(float *)(iVar24 + 0x20) * *(float *)(iVar18 + 0x20);
      pfVar27[1] = *(float *)(iVar24 + 0x24) * *(float *)(iVar18 + 0x24);
      pfVar27[2] = *(float *)(iVar24 + 0x28) * *(float *)(iVar18 + 0x28);
      pfVar27[3] = *(float *)(iVar18 + 0x2c);
    }
    else {
      if (uVar20 != 0) goto switchD_0003bf70_caseD_1;
      *pfVar27 = *(float *)(iVar17 + iVar16) * *(float *)(iVar19 + iVar11);
      pfVar27[1] = *(float *)(iVar24 + 4) * *(float *)(iVar18 + 4);
      pfVar27[2] = *(float *)(iVar24 + 8) * *(float *)(iVar18 + 8);
      pfVar27[3] = *(float *)(iVar18 + 0xc);
    }
    goto LAB_0003c2d0;
  case 5:
    uVar20 = local_58 & 1;
    switch(local_58 >> 1 & 7) {
    case 0:
      pfVar21 = (float *)(uVar20 * 0x240 + 0x28c0 + *(int *)(param_1 + 0x10));
      pdVar25 = (dword *)(pfVar21 + 1);
      pdVar13 = (dword *)(pfVar21 + 2);
      pdVar23 = (dword *)(pfVar21 + 3);
      break;
    case 1:
      pfVar21 = (float *)(uVar20 * 0x240 + 0x28d0 + *(int *)(param_1 + 0x10));
      pdVar25 = (dword *)(pfVar21 + 1);
      pdVar13 = (dword *)(pfVar21 + 2);
      pdVar23 = (dword *)(pfVar21 + 3);
      break;
    case 2:
      pfVar21 = (float *)(uVar20 * 0x240 + 0x28e0 + *(int *)(param_1 + 0x10));
      pdVar25 = (dword *)(pfVar21 + 1);
      pdVar13 = (dword *)(pfVar21 + 2);
      pdVar23 = (dword *)(pfVar21 + 3);
      break;
    case 3:
      pfVar21 = (float *)(uVar20 * 0x240 + 0x28f0 + *(int *)(param_1 + 0x10));
      pdVar25 = (dword *)(pfVar21 + 1);
      pdVar13 = (dword *)(pfVar21 + 2);
      pdVar23 = (dword *)(pfVar21 + 3);
      break;
    case 4:
      pfVar21 = (float *)(uVar20 * 0x240 + 0x2900 + *(int *)(param_1 + 0x10));
      pdVar25 = (dword *)(pfVar21 + 1);
      pdVar13 = (dword *)(pfVar21 + 2);
      pdVar23 = (dword *)(pfVar21 + 3);
      break;
    case 5:
      iVar16 = *(int *)(param_1 + 0x10);
      iVar11 = iVar16 + 0x28c0 + uVar20 * 0x240;
      *pfVar27 = *(float *)(iVar16 + 0x24b0) * *(float *)(iVar16 + 0x28c0 + uVar20 * 0x240) +
                 *(float *)(iVar11 + 0x30);
      pfVar27[1] = *(float *)(iVar16 + 0x24b4) * *(float *)(iVar11 + 4) + *(float *)(iVar11 + 0x34);
      pfVar27[2] = *(float *)(iVar16 + 0x24b8) * *(float *)(iVar11 + 8) + *(float *)(iVar11 + 0x38);
      pfVar27[3] = *(float *)(iVar11 + 0x1c);
      goto LAB_0003c2d0;
    default:
      goto switchD_0003bf70_caseD_1;
    }
    break;
  case 6:
    iVar16 = *(int *)(param_1 + 0x10);
    pdVar23 = (dword *)(iVar16 + 0x24bc);
    pdVar25 = (dword *)(iVar16 + 0x24b4);
    pdVar13 = (dword *)(iVar16 + 0x24b8);
    pfVar21 = (float *)(iVar16 + 0x24b0);
    break;
  case 7:
    uVar20 = local_58 >> 5 & 7;
    local_58 = local_58 & 0x1f;
    if (uVar20 == 1) {
      iVar16 = *(int *)(param_1 + 0x10);
      puVar12 = ((unsigned char *)0x000039a0) + local_58 * 0x94;
LAB_0003bae4:
      pdVar23 = (dword *)(puVar12 + iVar16 + 0x1c);
      pdVar25 = (dword *)(puVar12 + iVar16 + 0x14);
      pdVar13 = (dword *)(puVar12 + iVar16 + 0x18);
      pfVar21 = (float *)(puVar12 + iVar16 + 0x10);
    }
    else {
      if (uVar20 < 2) {
        if (uVar20 == 0) {
          iVar16 = *(int *)(param_1 + 0x10);
          puVar12 = ((unsigned char *)0x00003980) + local_58 * 0x94;
          goto LAB_0003bac0;
        }
        goto switchD_0003bf70_caseD_1;
      }
      if (uVar20 == 2) {
        iVar16 = *(int *)(param_1 + 0x10);
        puVar12 = ((unsigned char *)0x000039c0) + local_58 * 0x94;
LAB_0003bb08:
        pdVar23 = (dword *)(puVar12 + iVar16 + 0x20);
        pdVar25 = (dword *)(puVar12 + iVar16 + 0x18);
        pdVar13 = (dword *)(puVar12 + iVar16 + 0x1c);
        pfVar21 = (float *)(puVar12 + iVar16 + 0x14);
      }
      else {
        if (uVar20 != 3) goto switchD_0003bf70_caseD_1;
        iVar16 = *(int *)(param_1 + 0x10);
        puVar12 = ((unsigned char *)0x000039e0) + local_58 * 0x94;
LAB_0003bb2c:
        pdVar23 = (dword *)(puVar12 + iVar16 + 0x24);
        pdVar25 = (dword *)(puVar12 + iVar16 + 0x1c);
        pdVar13 = (dword *)(puVar12 + iVar16 + 0x20);
        pfVar21 = (float *)(puVar12 + iVar16 + 0x18);
      }
    }
    break;
  case 8:
    uVar20 = local_58 >> 5 & 7;
    local_58 = local_58 & 0x1f;
    if (uVar20 == 1) {
      iVar16 = *(int *)(param_1 + 0x10);
      puVar12 = ((unsigned char *)0x000039b0) + local_58 * 0x94;
      goto LAB_0003bae4;
    }
    if (uVar20 < 2) {
      if (uVar20 == 0) {
        iVar16 = *(int *)(param_1 + 0x10);
        puVar12 = ((unsigned char *)0x00003990) + local_58 * 0x94;
        goto LAB_0003bac0;
      }
    }
    else {
      if (uVar20 == 2) {
        iVar16 = *(int *)(param_1 + 0x10);
        puVar12 = ((unsigned char *)0x000039d0) + local_58 * 0x94;
        goto LAB_0003bb08;
      }
      if (uVar20 == 3) {
        iVar16 = *(int *)(param_1 + 0x10);
        puVar12 = ((unsigned char *)0x000039f0) + local_58 * 0x94;
        goto LAB_0003bb2c;
      }
    }
    goto switchD_0003bf70_caseD_1;
  case 9:
    iVar16 = *(int *)(param_1 + 0x10) + (local_58 & 0x1f) * 0x7c;
    pdVar23 = (dword *)(((unsigned char *)0x000031c0) + iVar16 + 0x10);
    pdVar13 = (dword *)(((unsigned char *)0x000031c0) + iVar16 + 0xc);
    pdVar25 = (dword *)(((unsigned char *)0x000031c0) + iVar16 + 8);
    pfVar21 = (float *)(((unsigned char *)0x000031c0) + iVar16 + 4);
    break;
  case 10:
    iVar16 = *(int *)(param_1 + 0x10);
    puVar12 = ((unsigned char *)0x00003e20) + (local_58 & 0xff) * 0x10;
LAB_0003bac0:
    pdVar23 = (dword *)(puVar12 + iVar16 + 0x18);
    pdVar25 = (dword *)(puVar12 + iVar16 + 0x10);
    pdVar13 = (dword *)(puVar12 + iVar16 + 0x14);
    pfVar21 = (float *)(puVar12 + iVar16 + 0xc);
    break;
  case 0xb:
    iVar16 = *(int *)(param_1 + 0x10);
    pdVar23 = (dword *)(((unsigned char *)0x00002dec) + iVar16);
    pdVar25 = (dword *)(((unsigned char *)0x00002de4) + iVar16);
    pdVar13 = (dword *)(((unsigned char *)0x00002de8) + iVar16);
    pfVar21 = (float *)(((unsigned char *)0x00002de0) + iVar16);
    break;
  case 0xc:
    iVar16 = *(int *)(param_1 + 0x10);
    pdVar23 = (dword *)(((unsigned char *)0x00002dfc) + iVar16);
    pdVar25 = (dword *)(((unsigned char *)0x00002df4) + iVar16);
    pdVar13 = (dword *)(((unsigned char *)0x00002df8) + iVar16);
    pfVar21 = (float *)(((unsigned char *)0x00002df0) + iVar16);
    break;
  case 0xd:
    iVar16 = *(int *)(param_1 + 0x10);
    pdVar23 = (dword *)(((unsigned char *)0x000030c8) + iVar16);
    pdVar25 = (dword *)(((unsigned char *)0x000030c0) + iVar16);
    pdVar13 = (dword *)(((unsigned char *)0x000030c4) + iVar16);
    pfVar21 = (float *)(((unsigned char *)0x000030bc) + iVar16);
    break;
  case 0xe:
    iVar16 = *(int *)(param_1 + 0x10);
    pdVar23 = (dword *)(((unsigned char *)0x000030d8) + iVar16);
    pdVar25 = (dword *)(((unsigned char *)0x000030d0) + iVar16);
    pdVar13 = (dword *)(((unsigned char *)0x000030d4) + iVar16);
    pfVar21 = (float *)(((unsigned char *)0x000030cc) + iVar16);
    break;
  case 0xf:
    *pfVar27 = (float)*(double *)(0x00001830 + *(int *)(param_1 + 0x10));
    pfVar27[1] = (float)*(double *)(*(int *)(param_1 + 0x10) + 0x1838);
    dVar31 = *(double *)(0x00001830 + *(int *)(param_1 + 0x10));
    dVar29 = *(double *)(*(int *)(param_1 + 0x10) + 0x1838);
    pfVar27[3] = 1.0;
    pfVar27[2] = (float)(dVar29 - dVar31);
    goto LAB_0003c2d0;
  case 0x12:
    fVar6 = *(float *)(*(int *)(param_1 + 0x10) + 0x24a4);
    pfVar27[3] = fVar6;
    *pfVar27 = fVar6;
    pfVar27[1] = fVar6;
    pfVar27[2] = fVar6;
    goto LAB_0003c2d0;
  }
LAB_0003c2b0:
  *pfVar27 = *pfVar21;
  pfVar27[1] = (float)*pdVar25;
  pfVar27[2] = (float)*pdVar13;
  pfVar27[3] = (float)*pdVar23;
LAB_0003c2d0:
  puVar14 = *(undefined8 **)(pbVar28 + 4);
  pbVar28 = pbVar28 + 8;
  uVar30 = *(undefined8 *)(pfVar27 + 2);
  *puVar14 = *(undefined8 *)pfVar27;
  puVar14[1] = uVar30;
  goto joined_r0x0003b9b0;
switchD_0003bf70_caseD_1:
  pdVar25 = ((unsigned char *)0x4);
  pdVar13 = ((unsigned char *)0x8);
  pdVar23 = ((unsigned char *)0xc);
  pfVar21 = (float *)0x0;
  goto LAB_0003c2b0;
}

/* FUN_0003c310 @ 0x3c310 (236 bytes) */
int FUN_0003c310(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  if (param_2[2] != 0) {
    (**(code **)(param_1 + 0x18))(param_2[2]);
    param_2[2] = 0;
  }
  if (param_2[4] != 0) {
    (**(code **)(param_1 + 0x18))(param_2[4]);
    param_2[4] = 0;
  }
  if (param_2[6] != 0) {
    (**(code **)(param_1 + 0x18))(param_2[6]);
    param_2[6] = 0;
  }
  if (param_2[8] != 0) {
    (**(code **)(param_1 + 0x18))(param_2[8]);
    param_2[8] = 0;
  }
  if (param_2[10] != 0) {
    (**(code **)(param_1 + 0x18))(param_2[10]);
    param_2[10] = 0;
  }
  FUN_00053ef0(param_1,*param_2);
  return;
}

/* FUN_0003c400 @ 0x3c400 (4136 bytes) */
int FUN_0003c400(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  undefined4 *param_3;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  undefined4 *puVar19;
  int iVar20;
  uint *puVar21;
  uint *puVar22;
  int iVar23;
  uint uVar24;
  undefined4 *puVar25;
  undefined4 uVar26;
  char cStack_95;
  char cStack_75;
  undefined4 local_70 [11];
  
  if (param_2[8] != 0) {
    bVar2 = *param_2 - 0x8b30U < 2;
    FUN_000538e0(param_1);
    FUN_00053060(param_1);
    iVar12 = param_2[0x12];
    iVar5 = param_2[0x13];
    *(undefined1 *)(param_3 + 0x23) = 0;
    if (iVar12 != 0) {
      iVar14 = 0;
      do {
        cStack_95 = (char)param_2[iVar5 * 2 + iVar14 * 2];
        if (cStack_95 == '\0') {
          *(undefined1 *)(param_3 + 0x23) = 1;
        }
        iVar14 = iVar14 + 1;
        iVar12 = iVar12 + -1;
      } while (iVar12 != 0);
    }
    iVar5 = 0;
    puVar19 = param_3;
    do {
      uVar7 = FUN_00054460(param_1,0x87bf,0x87c4,0x87e1,1);
      puVar19[0xd] = uVar7;
      uVar7 = FUN_00054460(param_1,0x87be,0x87c4,0x87e1,1);
      puVar19[0x10] = uVar7;
      uVar7 = FUN_00054460(param_1,0x87bf,0x87c4,0x87e1,1);
      bVar1 = iVar5 != 2;
      iVar5 = iVar5 + 1;
      puVar19[0x13] = uVar7;
      puVar19 = puVar19 + 1;
    } while (bVar1);
    iVar5 = 0;
    uVar7 = FUN_00054460(param_1,0x87bf,0x87c4,0x87e1,1);
    param_3[0x16] = uVar7;
    uVar7 = FUN_00054460(param_1,0x87be,0x87c4,0x87e1,1);
    param_3[0x17] = uVar7;
    puVar19 = param_3;
    do {
      uVar7 = FUN_00054460(param_1,0x87bf,0x87c4,0x87e1,1);
      bVar1 = iVar5 != 1;
      iVar5 = iVar5 + 1;
      puVar19[0x18] = uVar7;
      puVar19 = puVar19 + 1;
    } while (bVar1);
    iVar5 = param_2[4];
    if (iVar5 != param_3[1]) {
      if (param_3[2] != 0) {
        (**(code **)(param_1 + 0x18))(param_3[2]);
        param_3[2] = 0;
      }
      if (iVar5 != 0) {
        uVar7 = (**(code **)(param_1 + 0x10))(iVar5,4);
        param_3[2] = uVar7;
      }
    }
    param_3[1] = iVar5;
    if (iVar5 != 0) {
      iVar12 = FUN_00054460(param_1,0x87bf,0x87c4,0x87e1,iVar5);
      iVar14 = 0;
      do {
        iVar17 = iVar14 * 4;
        iVar3 = iVar14 + iVar12;
        iVar14 = iVar14 + 1;
        *(int *)(iVar17 + param_3[2]) = iVar3;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
    iVar12 = param_2[8];
    iVar5 = param_2[9];
    if (iVar12 != param_3[3]) {
      if (param_3[4] != 0) {
        (**(code **)(param_1 + 0x18))(param_3[4]);
        param_3[4] = 0;
      }
      if (iVar12 != 0) {
        uVar7 = (**(code **)(param_1 + 0x10))(iVar12,4);
        param_3[4] = uVar7;
      }
    }
    param_3[3] = iVar12;
    if (iVar12 != 0) {
      puVar19 = (undefined4 *)param_3[4];
      iVar14 = 0;
      do {
        uVar15 = param_2[iVar5 * 2 + iVar14 * 2 + 1];
        if (((uint)param_2[iVar5 * 2 + iVar14 * 2] >> 0x10 & 0xf) - 1 < 10) {
          if ((uVar15 & 0xffff) == 0) {
            uVar7 = FUN_00054940(param_1,0x87e2);
            *puVar19 = uVar7;
          }
          else {
            uVar7 = FUN_00054460(param_1,0x87bf,0x87c1,0x87e1,1);
            puVar19[uVar15 & 0xffff] = uVar7;
          }
        }
        iVar14 = iVar14 + 1;
      } while (iVar12 != iVar14);
    }
    ((int (*)())FUN_0003b280)(param_1,param_3,param_2[10],param_2 + param_2[0xb] * 2,param_2[0xe],
                 param_2 + param_2[0xf] * 2,param_2[0x1a],param_2 + param_2[0x1b] * 2);
    iVar12 = param_2[0x14];
    iVar5 = param_2[0xd];
    if (iVar12 != 0) {
      iVar14 = 0;
      puVar21 = (uint *)(param_2 + param_2[0x15] * 2);
      do {
        puVar22 = puVar21 + 2;
        uVar15 = *puVar21 >> 0x12 & 0xff;
        if ((*puVar21 & 0x3fc0000) == 0x1340000) goto LAB_0003d23c;
        uVar24 = puVar21[2];
        if (0x4d < uVar15) goto switchD_0003cbec_caseD_3;
        bVar1 = uVar15 == 0x48;
        if (bVar1) {
          iVar17 = param_3[0x17];
          goto LAB_0003c9b8;
        }
        if ((bVar2) && ((uVar24 & 0x7000) != 0x3000)) goto switchD_0003cbec_caseD_3;
        uVar6 = uVar24 >> 0x11 & 7;
        if (uVar6 == 1) {
          iVar17 = *(int *)((puVar21[3] & 0xffff) * 4 + param_3[2]);
          goto LAB_0003c9b8;
        }
        if (uVar6 != 3) {
switchD_0003cbec_caseD_3:
          bVar2 = false;
          goto LAB_0003d254;
        }
        uVar6 = param_2[iVar5 * 2 + (puVar21[3] & 0xffff) * 2];
        switch(uVar6 >> 0x10 & 0xf) {
        case 0:
          iVar17 = 0;
          break;
        case 1:
          iVar17 = 0x879a;
          break;
        case 2:
          iVar17 = 0x87bd;
          break;
        case 3:
          iVar17 = 0x610e;
          break;
        case 4:
          iVar17 = 0x610f;
          if ((uVar6 & 1) == 0) {
            iVar17 = 0x879b;
          }
          break;
        case 5:
          iVar17 = 0x6110;
          if ((uVar6 & 1) == 0) {
            iVar17 = 0x879c;
          }
          break;
        case 6:
          iVar17 = (uVar6 & 0x1f) + 0x879d;
          break;
        default:
          goto switchD_0003cbec_caseD_3;
        }
LAB_0003c9b8:
        iVar3 = iVar17;
        if (((uVar24 & 0x1e000) != 0x1e000) && (!bVar1)) {
          iVar3 = param_3[0x16];
        }
        if ((uVar15 < 0x1f) || ((iVar18 = 2, 0x3a < uVar15 && (iVar18 = 3, 0x40 < uVar15)))) {
          iVar18 = 1;
        }
        iVar20 = 0;
        iVar23 = 0;
        puVar22 = puVar21 + 4;
        puVar19 = param_3;
        do {
          puVar21 = puVar22;
          uVar6 = *puVar21;
          puVar22 = puVar21 + 2;
          uVar16 = puVar21[1] & 0xffff;
          if ((bVar2) && ((uVar6 & 0x7000) != 0x3000)) goto switchD_0003cbec_caseD_3;
          uVar4 = uVar6 >> 0x17 & 7;
          if (uVar4 == 1) {
            uVar7 = *(undefined4 *)(uVar16 * 4 + param_3[2]);
          }
          else if (uVar4 == 2) {
            if ((int)uVar6 < 0) {
              cStack_75 = (char)uVar6;
              FUN_00053f80(param_1,0x8782,puVar19[0x13],param_3[0x17],
                           *(undefined4 *)((uVar16 + (int)cStack_75) * 4 + param_3[10]));
              uVar7 = puVar19[0x13];
            }
            else {
              uVar7 = *(undefined4 *)(uVar16 * 4 + param_3[10]);
            }
          }
          else {
            uVar7 = 0;
            if (uVar4 == 0) {
              uVar7 = *(undefined4 *)(uVar16 * 4 + param_3[4]);
            }
          }
          *(undefined4 *)((int)local_70 + iVar23) = uVar7;
          if ((uVar6 & 0x8000000) == 0) {
            iVar8 = (uVar6 >> 0x15 & 3) + 0x87d5;
            iVar10 = (uVar6 >> 0x13 & 3) + 0x87d5;
            iVar11 = (uVar6 >> 0x11 & 3) + 0x87d5;
            iVar13 = (uVar6 >> 0xf & 3) + 0x87d5;
          }
          else {
            iVar8 = (uVar6 >> 0x15 & 3) + 0x87d9;
            iVar10 = (uVar6 >> 0x13 & 3) + 0x87d9;
            iVar11 = (uVar6 >> 0x11 & 3) + 0x87d9;
            iVar13 = (uVar6 >> 0xf & 3) + 0x87d9;
          }
          if ((((iVar8 != 0x87d5) || (iVar10 != 0x87d6)) || (iVar11 != 0x87d7)) ||
             (iVar13 != 0x87d8)) {
            FUN_00054080(param_1,puVar19[0xd],*(undefined4 *)((int)local_70 + iVar23),iVar8,iVar10,
                         iVar11,iVar13);
            *(undefined4 *)((int)local_70 + iVar23) = puVar19[0xd];
          }
          uVar7 = local_70[1];
          iVar20 = iVar20 + 1;
          iVar23 = iVar23 + 4;
          puVar19 = puVar19 + 1;
        } while (iVar18 != iVar20);
        switch(uVar15) {
        case 0:
          FUN_00053f00(param_1,0x8799,iVar3,local_70[0]);
          break;
        case 1:
          FUN_00053f00(param_1,0x879e,iVar3,local_70[0]);
          break;
        case 2:
          FUN_00054080(param_1,param_3[0x18],local_70[0],0x87d9,0x87da,0x87db,0x87dc);
          FUN_00053f80(param_1,0x878a,iVar3,local_70[0],param_3[0x18]);
          break;
        default:
          goto switchD_0003cbec_caseD_3;
        case 4:
          FUN_00053f00(param_1,0x8789,iVar3,local_70[0]);
          break;
        case 5:
          FUN_00053f00(param_1,0x878f,iVar3,local_70[0]);
          break;
        case 0xd:
          FUN_00054080(param_1,param_3[0x18],local_70[0],0x87d9,0x87da,0x87db,0x87dc);
          FUN_00053f80(param_1,0x878a,param_3[0x19],local_70[0],param_3[0x18]);
          FUN_000543b0(param_1,param_3[0x10],param_3[0x19],0);
          uVar26 = param_3[0x11];
          uVar9 = param_3[0x10];
          uVar7 = 0x8795;
          goto LAB_0003cdec;
        case 0xe:
          FUN_000543b0(param_1,param_3[0x10],local_70[0],0);
          uVar26 = param_3[0x11];
          uVar9 = param_3[0x10];
          uVar7 = 0x8794;
          goto LAB_0003cdec;
        case 0x10:
          FUN_000543b0(param_1,param_3[0x10],local_70[0],0);
          uVar26 = param_3[0x11];
          uVar9 = param_3[0x10];
          uVar7 = 0x8791;
          goto LAB_0003cdec;
        case 0x11:
          FUN_00053f00(param_1,0x87a0,iVar3,local_70[0]);
          break;
        case 0x13:
          FUN_000543b0(param_1,param_3[0x10],local_70[0],0);
          uVar26 = param_3[0x11];
          uVar9 = param_3[0x10];
          uVar7 = 0x8792;
LAB_0003cdec:
          FUN_00053f00(param_1,uVar7,uVar26,uVar9);
          FUN_00053f00(param_1,0x8799,iVar3,param_3[0x11]);
          break;
        case 0x14:
          FUN_00053f00(param_1,0x87a1,iVar3,local_70[0]);
          break;
        case 0x1f:
          FUN_00053f80(param_1,0x8787,iVar3,local_70[0],local_70[1]);
          break;
        case 0x20:
          FUN_00053f80(param_1,0x8796,iVar3,local_70[0],local_70[1]);
          break;
        case 0x22:
          FUN_00053f80(param_1,0x8786,iVar3,local_70[0],local_70[1]);
          break;
        case 0x28:
          FUN_00053f80(param_1,0x8784,iVar3,local_70[0],local_70[1]);
          break;
        case 0x29:
          FUN_00053f80(param_1,0x8785,iVar3,local_70[0],local_70[1]);
          break;
        case 0x2a:
          FUN_00054080(param_1,param_3[0x18],local_70[0],0x87d5,0x87d6,0x87d7,0x87de);
          FUN_00053f80(param_1,0x8785,iVar3,param_3[0x18],local_70[1]);
          break;
        case 0x2b:
          FUN_00053f80(param_1,0x879f,iVar3,local_70[0],local_70[1]);
          break;
        case 0x2c:
          FUN_00053f80(param_1,0x878b,iVar3,local_70[0],local_70[1]);
          break;
        case 0x2d:
          FUN_00053f80(param_1,0x878a,iVar3,local_70[0],local_70[1]);
          break;
        case 0x2e:
          FUN_00053f80(param_1,0x8797,iVar3,local_70[0],local_70[1]);
          break;
        case 0x32:
          FUN_00053f80(param_1,0x878c,iVar3,local_70[0],local_70[1]);
          break;
        case 0x35:
          FUN_00053f80(param_1,0x878d,iVar3,local_70[0],local_70[1]);
          break;
        case 0x38:
          FUN_000543b0(param_1,param_3[0x10],local_70[0],0);
          FUN_000543b0(param_1,param_3[0x11],uVar7,0);
          FUN_00053f80(param_1,0x8793,param_3[0x12],param_3[0x10],param_3[0x11]);
          FUN_00053f00(param_1,0x8799,iVar3,param_3[0x12]);
          break;
        case 0x3f:
          FUN_00054000(param_1,0x8788,iVar3,local_70[0],local_70[1],local_70[2]);
          break;
        case 0x41:
          uVar15 = *puVar22;
          puVar22 = puVar21 + 4;
          if (((*(int *)(&DAT_001da630 + (uVar15 >> 10 & 0x3c)) != 0x87d5) ||
              (*(int *)(&DAT_001da630 + (uVar15 >> 6 & 0x3c)) != 0x87d6)) ||
             ((*(int *)(&DAT_001da630 + (uVar15 >> 2 & 0x3c)) != 0x87d7 ||
              (*(int *)(&DAT_001da630 + (uVar15 & 0xf) * 4) != 0x87d8)))) {
            FUN_00054080(param_1,iVar3,local_70[0],*(int *)(&DAT_001da630 + (uVar15 >> 10 & 0x3c)),
                         *(int *)(&DAT_001da630 + (uVar15 >> 6 & 0x3c)),
                         *(int *)(&DAT_001da630 + (uVar15 >> 2 & 0x3c)),
                         *(int *)(&DAT_001da630 + (uVar15 & 0xf) * 4));
          }
          break;
        case 0x48:
          FUN_000543b0(param_1,iVar3,local_70[0],0);
        }
        if (((uVar24 & 0x1e000) != 0x1e000) && (!bVar1)) {
          FUN_000541a0(param_1,iVar17,iVar3,uVar24 >> 0xd & 1,uVar24 >> 0xe & 1,uVar24 >> 0xf & 1,
                       uVar24 >> 0x10 & 1);
        }
LAB_0003d23c:
        iVar14 = iVar14 + 1;
        puVar21 = puVar22;
      } while (iVar12 != iVar14);
    }
    bVar2 = true;
LAB_0003d254:
    if (*(char *)(param_3 + 0x23) != '\0') {
      uVar26 = param_3[0x16];
      uVar7 = *(undefined4 *)param_3[4];
      FUN_00053f80(param_1,0x8785,uVar26,uVar7,param_3[0x1a]);
      FUN_000541a0(param_1,0x879a,uVar26,1,0,0,0);
      FUN_00053f80(param_1,0x8785,uVar26,uVar7,param_3[0x1b]);
      FUN_000541a0(param_1,0x879a,uVar26,0,1,0,0);
      FUN_00053f80(param_1,0x8785,uVar26,uVar7,param_3[0x1c]);
      FUN_000541a0(param_1,0x879a,uVar26,0,0,1,0);
      FUN_00053f80(param_1,0x8785,uVar26,uVar7,param_3[0x1d]);
      FUN_000541a0(param_1,0x879a,uVar26,0,0,0,1);
    }
    FUN_00053990(param_1);
    if (!bVar2) {
      FUN_000530a0(param_1);
      return 0;
    }
    iVar5 = FUN_00053070(param_1);
    if (iVar5 != 0) {
      uVar15 = param_3[3];
      if (uVar15 != param_3[5]) {
        if (param_3[6] != 0) {
          (**(code **)(param_1 + 0x18))(param_3[6]);
          param_3[6] = 0;
        }
        if (uVar15 != 0) {
          uVar7 = (**(code **)(param_1 + 0x10))(uVar15,4);
          param_3[6] = uVar7;
        }
      }
      param_3[5] = uVar15;
      if (uVar15 != 0) {
        puVar19 = (undefined4 *)param_3[6];
        *puVar19 = 0x000308c0;
        if (1 < uVar15) {
          uVar24 = 1;
          iVar5 = 4;
          do {
            uVar24 = uVar24 + 1;
            uVar7 = FUN_00052ee0(param_1,*(undefined4 *)(param_3[4] + iVar5));
            *(undefined4 *)((int)puVar19 + iVar5) = uVar7;
            iVar5 = iVar5 + 4;
          } while (uVar15 != uVar24);
        }
      }
      uVar15 = param_3[3];
      if (uVar15 != param_3[7]) {
        if (param_3[8] != 0) {
          (**(code **)(param_1 + 0x18))(param_3[8]);
          param_3[8] = 0;
        }
        if (uVar15 != 0) {
          uVar7 = (**(code **)(param_1 + 0x10))(uVar15,4);
          param_3[8] = uVar7;
        }
      }
      param_3[7] = uVar15;
      if (uVar15 != 0) {
        puVar25 = (undefined4 *)param_3[8];
        puVar19 = puVar25;
        uVar24 = uVar15;
        do {
          *puVar19 = 0x80;
          puVar19 = puVar19 + 1;
          uVar24 = uVar24 - 1;
        } while (uVar24 != 0);
        *puVar25 = 0;
        if (1 < uVar15) {
          uVar24 = 1;
          do {
            iVar5 = FUN_00052f60(param_1,*(undefined4 *)(uVar24 * 4 + param_3[4]));
            if (iVar5 != 0x81) {
              puVar25[iVar5 + -1] = uVar24;
            }
            uVar24 = uVar24 + 1;
          } while (uVar15 != uVar24);
        }
      }
      FUN_000530c0(param_1,*param_3,param_3 + 0x1e);
      return 1;
    }
  }
  return 0;
}

/* FUN_0003d590 @ 0x3d590 (2944 bytes) */
int FUN_0003d590(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
  int param_6;
{
  ushort *puVar1;
  byte bVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  undefined4 uVar9;
  float fVar10;
  uint uVar11;
  int iVar12;
  undefined *puVar13;
  dword *pdVar14;
  int iVar15;
  undefined4 *puVar16;
  int iVar17;
  int iVar18;
  undefined4 *puVar19;
  int iVar20;
  undefined4 *puVar21;
  undefined8 *puVar22;
  float *pfVar23;
  undefined4 *puVar24;
  int iVar25;
  dword *pdVar26;
  int iVar27;
  uint uVar28;
  uint uVar29;
  dword *pdVar30;
  int iVar31;
  float *pfVar32;
  byte *pbVar33;
  byte *pbVar34;
  undefined8 uVar35;
  double dVar36;
  undefined8 uVar37;
  double dVar38;
  byte *local_88;
  int local_84;
  int local_80 [2];
  uint local_78;
  undefined4 local_74;
  uint local_70;
  undefined4 local_6c;
  
  iVar31 = param_1 + 0x240;
  iVar15 = FUN_00054470(iVar31,&local_88,&local_84,local_80);
  if (iVar15 != 0) {
    ((int (*)())FUN_0003b620)(param_1,local_88,param_2,param_3,param_4);
  }
  puVar16 = (undefined4 *)(**(code **)(param_1 + 0x2998))(iVar31,*(int *)(local_88 + 0x808) * 7 + 2)
  ;
  puVar21 = *(undefined4 **)(param_1 + 0x2834);
  *(undefined4 **)(param_1 + 0x298c) = puVar16;
  puVar19 = puVar16 + *(int *)(local_88 + 0x808) * 7 + 2;
  puVar24 = puVar16;
  if ((puVar21 <= puVar16) || (puVar24 = puVar21, puVar21 < puVar19)) {
    uVar28 = *(byte *)(param_1 + 8) - 1;
    dataCacheBlockTouch(puVar24);
    dataCacheBlockTouch((int)puVar19 + -1);
    uVar29 = ~uVar28;
    uVar11 = uVar29 & (uint)puVar19;
    for (uVar29 = uVar28 + (int)puVar24 & uVar29; uVar29 < uVar11;
        uVar29 = uVar29 + *(byte *)(param_1 + 8)) {
      dataCacheBlockClearToZero(uVar29);
    }
    *(uint *)(param_1 + 0x2834) = uVar11;
  }
  iVar15 = *(int *)(local_88 + 0x800);
  puVar24 = puVar16 + 2;
  *puVar16 = 0x8a1;
  puVar16[1] = 0;
  pbVar33 = local_88;
  if (local_88 < local_88 + iVar15 * 8) {
    iVar25 = *(int *)(param_1 + 0x10) + 0x1860;
    do {
      puVar1 = (ushort *)(pbVar33 + 2);
      bVar2 = *pbVar33;
      puVar16 = *(undefined4 **)(pbVar33 + 4);
      pbVar33 = pbVar33 + 8;
      iVar12 = iVar25 + (uint)*puVar1 * 4;
      uVar9 = *(undefined4 *)(iVar25 + (uint)*puVar1 * 4);
      iVar17 = (uint)bVar2 * 0x10;
      uVar3 = *(undefined4 *)(iVar12 + 0x30);
      uVar4 = *(undefined4 *)(iVar12 + 0x10);
      uVar5 = *(undefined4 *)(iVar12 + 0x20);
      iVar12 = local_84 + iVar17;
      *(undefined4 *)(local_84 + iVar17) = uVar9;
      *(undefined4 *)(iVar12 + 0xc) = uVar3;
      *(undefined4 *)(iVar12 + 4) = uVar4;
      *(undefined4 *)(iVar12 + 8) = uVar5;
      puVar16[3] = uVar3;
      *puVar16 = uVar9;
      puVar16[1] = uVar4;
      puVar16[2] = uVar5;
      puVar24[1] = local_80[0] + (uint)bVar2;
      puVar24[3] = uVar9;
      puVar24[4] = uVar4;
      puVar24[5] = uVar5;
      puVar24[6] = uVar3;
      *puVar24 = 0x880;
      puVar24[2] = 0x38882;
      puVar24 = puVar24 + 7;
    } while (pbVar33 < local_88 + iVar15 * 8);
  }
  iVar15 = *(int *)(local_88 + 0x804);
  while (pbVar34 = pbVar33, pbVar34 < local_88 + iVar15 * 8) {
    pbVar33 = pbVar34 + 8;
    if ((*(uint *)((pbVar34[1] >> 3 & 0x1c) + param_6) >> (pbVar34[1] & 0x1f) & 1) != 0) {
      puVar22 = *(undefined8 **)(pbVar34 + 4);
      bVar2 = *pbVar34;
      *puVar24 = 0x880;
      puVar24[2] = 0x38882;
      iVar25 = (uint)bVar2 * 0x10;
      uVar37 = puVar22[1];
      uVar35 = *puVar22;
      puVar24[1] = local_80[0] + (uint)bVar2;
      *(undefined8 *)(puVar24 + 3) = uVar35;
      *(undefined8 *)(local_84 + iVar25) = uVar35;
      *(undefined8 *)(puVar24 + 5) = uVar37;
      *(undefined8 *)(local_84 + iVar25 + 8) = uVar37;
      puVar24 = puVar24 + 7;
    }
  }
  iVar15 = *(int *)(local_88 + 0x808);
LAB_0003d820:
  while( true ) {
    if (local_88 + iVar15 * 8 <= pbVar34) {
      *(undefined4 **)(param_1 + 0x298c) = puVar24;
      (**(code **)(param_1 + 0x299c))(iVar31,puVar24);
      return;
    }
    if ((*(uint *)((pbVar34[1] >> 3 & 0x1c) + param_6) >> (pbVar34[1] & 0x1f) & 1) != 0) break;
    pbVar34 = pbVar34 + 8;
  }
  bVar2 = *pbVar34;
  pfVar32 = (float *)(puVar24 + 3);
  local_78 = *(uint *)((uint)*(ushort *)(pbVar34 + 2) * 8 + param_4);
  local_74 = *(undefined4 *)((uint)*(ushort *)(pbVar34 + 2) * 8 + param_4 + 4);
  puVar24[1] = local_80[0] + (uint)bVar2;
  puVar24[2] = 0x38882;
  *puVar24 = 0x880;
  if ((local_78 >> 0x10 & 0x1f) == 1) {
    iVar25 = (local_78 & 0xffff) * 0x10;
    iVar17 = iVar25 + param_5;
    if (*(int *)(*(int *)(param_1 + 0x18) + 0x198) == 0) {
      uVar3 = *(undefined4 *)(iVar17 + 0xc);
      uVar4 = *(undefined4 *)(iVar17 + 4);
      uVar5 = *(undefined4 *)(iVar17 + 8);
      puVar24[3] = *(undefined4 *)(iVar25 + param_5);
      puVar24[6] = uVar3;
      puVar24[4] = uVar4;
      puVar24[5] = uVar5;
    }
    else {
      _glpUniformToFloat(*(undefined4 *)(**(int **)(param_1 + 0x1cc) + 4),local_78 & 0xffff,iVar17,
                         pfVar32);
    }
    goto LAB_0003e170;
  }
  local_70 = local_78;
  local_6c = local_74;
  if ((local_78 & 0x1f0000) == 0x100000) {
    uVar29 = local_78 >> 0xc & 3;
    uVar11 = local_78 & 0xff;
    switch(local_78 >> 8 & 7) {
    default:
      iVar25 = 0;
      break;
    case 1:
      iVar25 = 0xc0;
      break;
    case 2:
      iVar25 = 0x80;
      break;
    case 3:
      iVar25 = (uVar11 + 4) * 0x40;
      break;
    case 4:
      iVar25 = (uVar11 + 0x10) * 0x40;
      break;
    case 5:
      iVar25 = (uVar11 + 8) * 0x40;
    }
    uVar11 = local_78 >> 0xe & 3;
    iVar17 = *(int *)(param_1 + 0x10) + 0x1860 + iVar25;
    if ((1 < uVar11) && (iVar17 = iVar25 + *(int *)(param_1 + 0x10) + 0x1e60, 3 < uVar11)) {
      iVar17 = 0;
    }
    if (uVar11 < 3) {
      if (uVar11 == 0) {
LAB_0003dd8c:
        iVar25 = uVar29 * 4;
        iVar12 = iVar17 + iVar25;
        *pfVar32 = *(float *)(iVar17 + iVar25);
        puVar24[4] = *(undefined4 *)(iVar12 + 0x10);
        puVar24[5] = *(undefined4 *)(iVar12 + 0x20);
        puVar24[6] = *(undefined4 *)(iVar12 + 0x30);
      }
      else {
        iVar25 = uVar29 * 0x10;
        iVar12 = iVar17 + iVar25;
        *pfVar32 = *(float *)(iVar17 + iVar25);
        puVar24[4] = *(undefined4 *)(iVar12 + 4);
        puVar24[5] = *(undefined4 *)(iVar12 + 8);
        puVar24[6] = *(undefined4 *)(iVar12 + 0xc);
      }
    }
    else if (uVar11 == 3) goto LAB_0003dd8c;
    goto LAB_0003e170;
  }
  switch(local_78 >> 0x10 & 0x1f) {
  case 0:
    pdVar30 = puVar24 + 4;
    pdVar14 = puVar24 + 5;
    pdVar26 = puVar24 + 6;
    pfVar23 = pfVar32;
    break;
  default:
    goto switchD_0003de14_caseD_1;
  case 2:
    pfVar23 = (float *)((local_78 & 0xffff) * 0x10 +
                       *(int *)(((unsigned char *)0x00004308) + *(int *)(param_1 + 0x10)));
    pdVar30 = (dword *)(pfVar23 + 1);
    pdVar14 = (dword *)(pfVar23 + 2);
    pdVar26 = (dword *)(pfVar23 + 3);
    break;
  case 3:
    uVar29 = local_78 & 0xff;
    switch(local_78 >> 8 & 0xf) {
    case 0:
      pfVar23 = (float *)(uVar29 * 0x80 + 0x24c0 + *(int *)(param_1 + 0x10));
      pdVar30 = (dword *)(pfVar23 + 1);
      pdVar14 = (dword *)(pfVar23 + 2);
      pdVar26 = (dword *)(pfVar23 + 3);
      break;
    case 1:
      pfVar23 = (float *)(uVar29 * 0x80 + 0x24d0 + *(int *)(param_1 + 0x10));
      pdVar30 = (dword *)(pfVar23 + 1);
      pdVar14 = (dword *)(pfVar23 + 2);
      pdVar26 = (dword *)(pfVar23 + 3);
      break;
    case 2:
      pfVar23 = (float *)(uVar29 * 0x80 + 0x24e0 + *(int *)(param_1 + 0x10));
      pdVar30 = (dword *)(pfVar23 + 1);
      pdVar14 = (dword *)(pfVar23 + 2);
      pdVar26 = (dword *)(pfVar23 + 3);
      break;
    case 3:
      pfVar23 = (float *)(uVar29 * 0x80 + 0x24f0 + *(int *)(param_1 + 0x10));
      pdVar30 = (dword *)(pfVar23 + 1);
      pdVar14 = (dword *)(pfVar23 + 2);
      pdVar26 = (dword *)(pfVar23 + 3);
      break;
    case 4:
      pfVar23 = (float *)(uVar29 * 0x80 + 0x2500 + *(int *)(param_1 + 0x10));
      pdVar30 = (dword *)(pfVar23 + 1);
      pdVar14 = (dword *)(pfVar23 + 2);
      pdVar26 = (dword *)(pfVar23 + 3);
      break;
    case 5:
      pfVar23 = (float *)(uVar29 * 0x80 + 0x2510 + *(int *)(param_1 + 0x10));
      pdVar30 = (dword *)(pfVar23 + 1);
      pdVar14 = (dword *)(pfVar23 + 2);
      pdVar26 = (dword *)(pfVar23 + 3);
      break;
    case 6:
      iVar25 = uVar29 * 0x80 + *(int *)(param_1 + 0x10);
      fVar7 = *(float *)(iVar25 + 0x24f4);
      fVar8 = *(float *)(iVar25 + 0x24f0);
      fVar10 = *(float *)(iVar25 + 0x24f8) + 1.0;
      dVar36 = _sqrt((double)(fVar10 * fVar10 + fVar8 * fVar8 + fVar7 * fVar7));
      puVar24[6] = 1.0;
      fVar6 = (float)(1.0 / dVar36);
      puVar24[5] = fVar10 * fVar6;
      *pfVar32 = fVar8 * fVar6;
      puVar24[4] = fVar7 * fVar6;
      goto LAB_0003e170;
    case 7:
      pfVar23 = (float *)(uVar29 * 0x80 + 0x2530 + *(int *)(param_1 + 0x10));
      pdVar30 = (dword *)(pfVar23 + 1);
      pdVar14 = (dword *)(pfVar23 + 2);
      pdVar26 = (dword *)(pfVar23 + 3);
      break;
    default:
      goto switchD_0003de14_caseD_1;
    }
    break;
  case 4:
    uVar29 = local_78 >> 9 & 3;
    iVar18 = *(int *)(param_1 + 0x10) + 0x24c0;
    iVar25 = (local_78 & 0xff) * 0x80;
    iVar17 = (local_78 >> 8 & 1) * 0x240;
    iVar12 = *(int *)(param_1 + 0x10) + 0x28c0;
    iVar27 = iVar18 + iVar25;
    iVar20 = iVar12 + iVar17;
    if (uVar29 == 1) {
      *pfVar32 = *(float *)(iVar27 + 0x10) * *(float *)(iVar20 + 0x10);
      puVar24[4] = *(float *)(iVar27 + 0x14) * *(float *)(iVar20 + 0x14);
      puVar24[5] = *(float *)(iVar27 + 0x18) * *(float *)(iVar20 + 0x18);
      puVar24[6] = *(undefined4 *)(iVar20 + 0x1c);
    }
    else if (uVar29 == 2) {
      *pfVar32 = *(float *)(iVar27 + 0x20) * *(float *)(iVar20 + 0x20);
      puVar24[4] = *(float *)(iVar27 + 0x24) * *(float *)(iVar20 + 0x24);
      puVar24[5] = *(float *)(iVar27 + 0x28) * *(float *)(iVar20 + 0x28);
      puVar24[6] = *(undefined4 *)(iVar20 + 0x2c);
    }
    else {
      if (uVar29 != 0) goto switchD_0003de14_caseD_1;
      *pfVar32 = *(float *)(iVar18 + iVar25) * *(float *)(iVar12 + iVar17);
      puVar24[4] = *(float *)(iVar27 + 4) * *(float *)(iVar20 + 4);
      puVar24[5] = *(float *)(iVar27 + 8) * *(float *)(iVar20 + 8);
      puVar24[6] = *(undefined4 *)(iVar20 + 0xc);
    }
    goto LAB_0003e170;
  case 5:
    uVar29 = local_78 & 1;
    switch(local_78 >> 1 & 7) {
    case 0:
      pfVar23 = (float *)(uVar29 * 0x240 + 0x28c0 + *(int *)(param_1 + 0x10));
      pdVar30 = (dword *)(pfVar23 + 1);
      pdVar14 = (dword *)(pfVar23 + 2);
      pdVar26 = (dword *)(pfVar23 + 3);
      break;
    case 1:
      pfVar23 = (float *)(uVar29 * 0x240 + 0x28d0 + *(int *)(param_1 + 0x10));
      pdVar30 = (dword *)(pfVar23 + 1);
      pdVar14 = (dword *)(pfVar23 + 2);
      pdVar26 = (dword *)(pfVar23 + 3);
      break;
    case 2:
      pfVar23 = (float *)(uVar29 * 0x240 + 0x28e0 + *(int *)(param_1 + 0x10));
      pdVar30 = (dword *)(pfVar23 + 1);
      pdVar14 = (dword *)(pfVar23 + 2);
      pdVar26 = (dword *)(pfVar23 + 3);
      break;
    case 3:
      pfVar23 = (float *)(uVar29 * 0x240 + 0x28f0 + *(int *)(param_1 + 0x10));
      pdVar30 = (dword *)(pfVar23 + 1);
      pdVar14 = (dword *)(pfVar23 + 2);
      pdVar26 = (dword *)(pfVar23 + 3);
      break;
    case 4:
      pfVar23 = (float *)(uVar29 * 0x240 + 0x2900 + *(int *)(param_1 + 0x10));
      pdVar30 = (dword *)(pfVar23 + 1);
      pdVar14 = (dword *)(pfVar23 + 2);
      pdVar26 = (dword *)(pfVar23 + 3);
      break;
    case 5:
      iVar25 = *(int *)(param_1 + 0x10);
      iVar17 = iVar25 + 0x28c0 + uVar29 * 0x240;
      *pfVar32 = *(float *)(iVar25 + 0x24b0) * *(float *)(iVar25 + 0x28c0 + uVar29 * 0x240) +
                 *(float *)(iVar17 + 0x30);
      puVar24[4] = *(float *)(iVar25 + 0x24b4) * *(float *)(iVar17 + 4) + *(float *)(iVar17 + 0x34);
      puVar24[5] = *(float *)(iVar25 + 0x24b8) * *(float *)(iVar17 + 8) + *(float *)(iVar17 + 0x38);
      puVar24[6] = *(undefined4 *)(iVar17 + 0x1c);
      goto LAB_0003e170;
    default:
      goto switchD_0003de14_caseD_1;
    }
    break;
  case 6:
    iVar25 = *(int *)(param_1 + 0x10);
    pdVar26 = (dword *)(iVar25 + 0x24bc);
    pdVar30 = (dword *)(iVar25 + 0x24b4);
    pdVar14 = (dword *)(iVar25 + 0x24b8);
    pfVar23 = (float *)(iVar25 + 0x24b0);
    break;
  case 7:
    uVar11 = local_78 >> 5 & 7;
    uVar29 = local_78 & 0x1f;
    if (uVar11 == 1) {
      iVar25 = *(int *)(param_1 + 0x10);
      puVar13 = ((unsigned char *)0x000039a0) + uVar29 * 0x94;
LAB_0003d908:
      pdVar26 = (dword *)(puVar13 + iVar25 + 0x1c);
      pdVar30 = (dword *)(puVar13 + iVar25 + 0x14);
      pdVar14 = (dword *)(puVar13 + iVar25 + 0x18);
      pfVar23 = (float *)(puVar13 + iVar25 + 0x10);
    }
    else {
      if (uVar11 < 2) {
        if (uVar11 == 0) {
          iVar25 = *(int *)(param_1 + 0x10);
          puVar13 = ((unsigned char *)0x00003980) + uVar29 * 0x94;
          goto LAB_0003d8e4;
        }
        goto switchD_0003de14_caseD_1;
      }
      if (uVar11 == 2) {
        iVar25 = *(int *)(param_1 + 0x10);
        puVar13 = ((unsigned char *)0x000039c0) + uVar29 * 0x94;
LAB_0003d92c:
        pdVar26 = (dword *)(puVar13 + iVar25 + 0x20);
        pdVar30 = (dword *)(puVar13 + iVar25 + 0x18);
        pdVar14 = (dword *)(puVar13 + iVar25 + 0x1c);
        pfVar23 = (float *)(puVar13 + iVar25 + 0x14);
      }
      else {
        if (uVar11 != 3) goto switchD_0003de14_caseD_1;
        iVar25 = *(int *)(param_1 + 0x10);
        puVar13 = ((unsigned char *)0x000039e0) + uVar29 * 0x94;
LAB_0003d950:
        pdVar26 = (dword *)(puVar13 + iVar25 + 0x24);
        pdVar30 = (dword *)(puVar13 + iVar25 + 0x1c);
        pdVar14 = (dword *)(puVar13 + iVar25 + 0x20);
        pfVar23 = (float *)(puVar13 + iVar25 + 0x18);
      }
    }
    break;
  case 8:
    uVar11 = local_78 >> 5 & 7;
    uVar29 = local_78 & 0x1f;
    if (uVar11 == 1) {
      iVar25 = *(int *)(param_1 + 0x10);
      puVar13 = ((unsigned char *)0x000039b0) + uVar29 * 0x94;
      goto LAB_0003d908;
    }
    if (uVar11 < 2) {
      if (uVar11 == 0) {
        iVar25 = *(int *)(param_1 + 0x10);
        puVar13 = ((unsigned char *)0x00003990) + uVar29 * 0x94;
        goto LAB_0003d8e4;
      }
    }
    else {
      if (uVar11 == 2) {
        iVar25 = *(int *)(param_1 + 0x10);
        puVar13 = ((unsigned char *)0x000039d0) + uVar29 * 0x94;
        goto LAB_0003d92c;
      }
      if (uVar11 == 3) {
        iVar25 = *(int *)(param_1 + 0x10);
        puVar13 = ((unsigned char *)0x000039f0) + uVar29 * 0x94;
        goto LAB_0003d950;
      }
    }
    goto switchD_0003de14_caseD_1;
  case 9:
    iVar25 = *(int *)(param_1 + 0x10) + (local_78 & 0x1f) * 0x7c;
    pdVar26 = (dword *)(((unsigned char *)0x000031c0) + iVar25 + 0x10);
    pdVar14 = (dword *)(((unsigned char *)0x000031c0) + iVar25 + 0xc);
    pdVar30 = (dword *)(((unsigned char *)0x000031c0) + iVar25 + 8);
    pfVar23 = (float *)(((unsigned char *)0x000031c0) + iVar25 + 4);
    break;
  case 10:
    iVar25 = *(int *)(param_1 + 0x10);
    puVar13 = ((unsigned char *)0x00003e20) + (local_78 & 0xff) * 0x10;
LAB_0003d8e4:
    pdVar26 = (dword *)(puVar13 + iVar25 + 0x18);
    pdVar30 = (dword *)(puVar13 + iVar25 + 0x10);
    pdVar14 = (dword *)(puVar13 + iVar25 + 0x14);
    pfVar23 = (float *)(puVar13 + iVar25 + 0xc);
    break;
  case 0xb:
    iVar25 = *(int *)(param_1 + 0x10);
    pdVar26 = (dword *)(((unsigned char *)0x00002dec) + iVar25);
    pdVar30 = (dword *)(((unsigned char *)0x00002de4) + iVar25);
    pdVar14 = (dword *)(((unsigned char *)0x00002de8) + iVar25);
    pfVar23 = (float *)(((unsigned char *)0x00002de0) + iVar25);
    break;
  case 0xc:
    iVar25 = *(int *)(param_1 + 0x10);
    pdVar26 = (dword *)(((unsigned char *)0x00002dfc) + iVar25);
    pdVar30 = (dword *)(((unsigned char *)0x00002df4) + iVar25);
    pdVar14 = (dword *)(((unsigned char *)0x00002df8) + iVar25);
    pfVar23 = (float *)(((unsigned char *)0x00002df0) + iVar25);
    break;
  case 0xd:
    iVar25 = *(int *)(param_1 + 0x10);
    pdVar26 = (dword *)(((unsigned char *)0x000030c8) + iVar25);
    pdVar30 = (dword *)(((unsigned char *)0x000030c0) + iVar25);
    pdVar14 = (dword *)(((unsigned char *)0x000030c4) + iVar25);
    pfVar23 = (float *)(((unsigned char *)0x000030bc) + iVar25);
    break;
  case 0xe:
    iVar25 = *(int *)(param_1 + 0x10);
    pdVar26 = (dword *)(((unsigned char *)0x000030d8) + iVar25);
    pdVar30 = (dword *)(((unsigned char *)0x000030d0) + iVar25);
    pdVar14 = (dword *)(((unsigned char *)0x000030d4) + iVar25);
    pfVar23 = (float *)(((unsigned char *)0x000030cc) + iVar25);
    break;
  case 0xf:
    *pfVar32 = (float)*(double *)(0x00001830 + *(int *)(param_1 + 0x10));
    puVar24[4] = (float)*(double *)(*(int *)(param_1 + 0x10) + 0x1838);
    dVar38 = *(double *)(0x00001830 + *(int *)(param_1 + 0x10));
    dVar36 = *(double *)(*(int *)(param_1 + 0x10) + 0x1838);
    puVar24[6] = 0x3f800000;
    puVar24[5] = (float)(dVar36 - dVar38);
    goto LAB_0003e170;
  case 0x12:
    fVar6 = *(float *)(*(int *)(param_1 + 0x10) + 0x24a4);
    puVar24[6] = fVar6;
    *pfVar32 = fVar6;
    puVar24[4] = fVar6;
    puVar24[5] = fVar6;
    goto LAB_0003e170;
  }
LAB_0003e150:
  *pfVar32 = *pfVar23;
  puVar24[4] = *pdVar30;
  puVar24[5] = *pdVar14;
  puVar24[6] = *pdVar26;
LAB_0003e170:
  uVar37 = *(undefined8 *)(puVar24 + 5);
  uVar35 = *(undefined8 *)pfVar32;
  iVar25 = (uint)bVar2 * 0x10;
  puVar24 = puVar24 + 7;
  *(undefined8 *)(local_84 + iVar25) = uVar35;
  *(undefined8 *)(local_84 + iVar25 + 8) = uVar37;
  puVar22 = *(undefined8 **)(pbVar34 + 4);
  pbVar34 = pbVar34 + 8;
  puVar22[1] = uVar37;
  *puVar22 = uVar35;
  goto LAB_0003d820;
switchD_0003de14_caseD_1:
  pdVar30 = ((unsigned char *)0x4);
  pdVar14 = ((unsigned char *)0x8);
  pdVar26 = ((unsigned char *)0xc);
  pfVar23 = (float *)0x0;
  goto LAB_0003e150;
}

/* FUN_0003e1d0 @ 0x3e1d0 (124 bytes) */
int FUN_0003e1d0(param_1)
  int param_1;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  uVar3 = *(uint *)(param_1 + 0x29fc);
  uVar1 = 0;
  iVar5 = 0x10;
  iVar4 = param_1;
  do {
    uVar2 = 0xff;
    if (*(int *)(iVar4 + 0x18c) != 0) {
      uVar2 = **(ushort **)(*(int *)(iVar4 + 0x18c) + 0x30) & 0xf;
    }
    if (uVar2 == *(uint *)(iVar4 + 0x2a00)) {
      uVar3 = uVar3 & ~(1 << (uVar1 & 0x3f));
      *(uint *)(param_1 + 0x29fc) = uVar3;
    }
    else {
      *(uint *)(iVar4 + 0x2a00) = uVar2;
      uVar3 = 1 << (uVar1 & 0x3f) | uVar3;
      *(uint *)(param_1 + 0x29fc) = uVar3;
    }
    uVar1 = uVar1 + 1;
    iVar4 = iVar4 + 4;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  return;
}

/* FUN_0003e250 @ 0x3e250 (188 bytes) */
int FUN_0003e250(param_1)
  int param_1;
{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 local_68 [16];
  undefined4 local_58 [22];
  
  if (*(int *)(param_1 + 0x29fc) != 0) {
    iVar3 = 0;
    iVar4 = 0;
    iVar5 = 0x10;
    iVar2 = param_1;
    do {
      if (*(int *)(iVar2 + 0x18c) == 0) {
        *(undefined4 *)(iVar4 + (int)local_58) = 0;
        local_68[iVar3] = 0;
      }
      else {
        uVar1 = **(ushort **)(*(int *)(iVar2 + 0x18c) + 0x30);
        local_68[iVar3] = 1;
        if ((uVar1 & 0xf) == 0) {
          *(undefined4 *)(iVar4 + (int)local_58) = 2;
        }
        else if ((uVar1 & 0xf) == 1) {
          *(undefined4 *)(iVar4 + (int)local_58) = 1;
        }
        else {
          *(undefined4 *)(iVar4 + (int)local_58) = 0;
        }
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 4;
      iVar2 = iVar2 + 4;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    FUN_000a1090(param_1 + 0x240,local_68,local_58);
  }
  return;
}

/* FUN_0003e320 @ 0x3e320 (120 bytes) */
int FUN_0003e320(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  int *piVar4;
  
  piVar4 = *(int **)(param_1 + 0x1d0);
  ((int (*)())FUN_0003e250)(param_1);
  if (piVar4 != (int *)0x0) {
    iVar1 = *piVar4;
    puVar3 = *(uint **)(iVar1 + 4);
    uVar2 = *puVar3;
    ((int (*)())FUN_0003e420)(param_1 + 0x240,*(int *)(param_1 + 0x29ec) + 0x14,uVar2 >> 0x10 & 0xff,
                 puVar3 + (uVar2 & 0xffff),((unsigned char *)0x00001010) + *(int *)(param_1 + 0x10),
                 *(undefined4 *)(iVar1 + 0x18));
  }
  return param_3;
}

/* FUN_0003e3a0 @ 0x3e3a0 (116 bytes) */
int FUN_0003e3a0(param_1, param_2)
  int param_1;
  int *param_2;
{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *param_2;
  if (iVar2 == 0) {
    iVar2 = FUN_000a12b0(param_1,1);
    *param_2 = iVar2;
    if (iVar2 == 0) {
      return 0;
    }
  }
  FUN_000a12f0(param_1,iVar2);
  uVar1 = FUN_000a11a0(param_1);
  *(undefined4 *)(param_1 + 0x27b8) = uVar1;
  return 1;
}

/* FUN_0003e420 @ 0x3e420 (152 bytes) */
int FUN_0003e420(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  uint *param_4;
  int param_5;
  int param_6;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  if (param_3 != 0) {
    iVar4 = 0;
    do {
      uVar1 = *param_4;
      param_4 = param_4 + 1;
      if ((uVar1 & 3) != 1) {
        uVar2 = uVar1 >> 0xc & 0xff;
        if ((uVar1 & 3) == 0) {
          iVar3 = uVar2 * 0x10 + param_5;
        }
        else {
          iVar3 = uVar2 * 0x10 + param_6;
        }
        FUN_000a2100(param_1,(uVar1 >> 0x14 & 0xff) + 0x8941,iVar3);
      }
      iVar4 = iVar4 + 1;
    } while (param_3 != iVar4);
  }
  return;
}

/* FUN_0003e4c0 @ 0x3e4c0 (8 bytes) */
int FUN_0003e4c0(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  FUN_000a1570(param_1,*param_2);
  return;
}

