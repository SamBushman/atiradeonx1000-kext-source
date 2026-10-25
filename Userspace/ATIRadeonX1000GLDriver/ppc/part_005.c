#include "decls.h"

/* gldTextureHasNonPowerOfTwoSize2 @ 0x2dcf0 (236 bytes) */
int gldTextureHasNonPowerOfTwoSize2(texture, unusedArg2, unusedArg3, unusedArg4, unusedArg5, unusedArg6)
  int texture;
  undefined4 unusedArg2;
  undefined4 unusedArg3;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
{
  uint leftoverBits;
  uint levelDepth;
  int levelRecord;
  byte targetByte;
  uint levelHeight;
  int texImages;
  uint borderWidth;
  byte targetKind;
  uint levelWidth;
  
  texImages = *(int *)(texture + 0x30);
  targetByte = *(byte *)(texImages + 1);
  targetKind = targetByte & 0xf;
  *(byte *)(texture + 0x6c) = targetKind;
  levelRecord = *(short *)(texImages + 0x3c) * 0x18 + texImages;
  borderWidth = (uint)*(byte *)(levelRecord + 0xaa);
  levelWidth = (uint)*(ushort *)(levelRecord + 0xa4) + borderWidth * -2;
  if ((int)levelWidth < 1) {
    levelWidth = 1;
  }
  levelHeight = (uint)*(ushort *)(levelRecord + 0xa6) + borderWidth * -2;
  if ((int)levelHeight < 1) {
    levelHeight = 1;
  }
  levelDepth = (uint)*(ushort *)(levelRecord + 0xa8) + borderWidth * -2;
  if ((int)levelDepth < 1) {
    levelDepth = 1;
  }
  if (targetKind == 1) {
    if ((levelWidth & levelWidth - 1) != 0) {
      return 1;
    }
    if ((levelHeight & levelHeight - 1) != 0) {
      return 1;
    }
    leftoverBits = levelDepth & levelDepth - 1;
  }
  else if (((targetByte & 0xf) == 0) || (targetKind == 3)) {
    if ((levelWidth & levelWidth - 1) != 0) {
      return 1;
    }
    leftoverBits = levelHeight & levelHeight - 1;
  }
  else {
    if (targetKind != 4) {
      return 1;
    }
    leftoverBits = levelWidth & levelWidth - 1;
  }
  if (leftoverBits != 0) {
    return 1;
  }
  return 0;
}

/* FUN_0002ddf0 @ 0x2ddf0 (3396 bytes) */
int FUN_0002ddf0(ctxSaved, texture)
  undefined4 ctxSaved;
  int *texture;
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
  byte textureTarget;
  int iVar26;
  ushort *texImages;
  char cVar29;
  int iVar28;
  int *hwState;
  double dVar31;
  double dVar32;
  
  hwState = texture + 0xf;
  texture[0x2e] = (int)texture;
  dVar31 = DOUBLE_001aa240;
  texImages = (ushort *)texture[0xc];
  *(byte *)((int)texture + 0x3d) = (byte)(-(uint)texImages[0x2e] >> 0x1f);
  uVar15 = (uint)(int)((double)*(float *)(texImages + 0x18) + dVar31);
  uVar17 = (uint)(int)((double)*(float *)(texImages + 0x1a) + dVar31);
  uVar14 = (uint)*(byte *)(texImages + 0x2f);
  uVar16 = uVar15 + uVar14;
  if ((int)uVar16 < 0) {
    uVar16 = 0;
  }
  if ((int)uVar14 < (int)uVar16) {
    uVar14 = uVar16;
  }
  uVar22 = (uint)(short)texImages[0x1e];
  uVar16 = uVar17 + uVar22;
  if (((int)uVar16 < (int)uVar14) && (uVar14 = uVar22, (int)uVar22 < (int)uVar16)) {
    uVar14 = uVar16;
  }
  uVar16 = (uint)*(byte *)((int)texImages + 0x5f);
  if ((int)uVar14 <= (int)(uint)*(byte *)((int)texImages + 0x5f)) {
    uVar16 = uVar14;
  }
  if ((int)uVar15 < 0) {
    uVar15 = 0;
  }
  if ((int)uVar15 < (int)uVar17) {
    uVar17 = uVar15;
  }
  if ((int)((int)(short)texImages[0x1f] - uVar22) < (int)uVar17) {
    uVar17 = (int)(short)texImages[0x1f] - uVar22;
  }
  uVar15 = uVar17;
  if ((int)(uint)*(byte *)(texImages + 0x32) < (int)uVar17) {
    uVar15 = (uint)*(byte *)(texImages + 0x32);
  }
  if ((int)uVar15 < 0) {
    uVar15 = 0;
  }
  uVar15 = uVar15 & 0xff;
  uVar14 = uVar17;
  if ((int)(uint)*(byte *)((int)texImages + 0x65) < (int)uVar17) {
    uVar14 = (uint)*(byte *)((int)texImages + 0x65);
  }
  if ((int)uVar14 < 0) {
    uVar14 = 0;
  }
  uVar14 = uVar14 & 0xff;
  if ((int)(uint)*(byte *)(texImages + 0x33) < (int)uVar17) {
    uVar17 = (uint)*(byte *)(texImages + 0x33);
  }
  if ((int)uVar17 < 0) {
    uVar17 = 0;
  }
  uVar4 = *(ushort *)(texture + 0x1d);
  bVar1 = *(byte *)((int)texture + 0x73);
  uVar5 = *(ushort *)((int)texture + 0x7a);
  uVar18 = (uint)*(ushort *)((int)texture + 0x3e);
  uVar6 = *(ushort *)(texture + 0x1f);
  uVar7 = *(ushort *)((int)texture + 0x76);
  uVar22 = (uint)uVar7;
  uVar8 = *(ushort *)(texture + 0x1e);
  uVar21 = (uint)uVar8;
  *(undefined1 *)((int)texture + 0x6e) = *(undefined1 *)(texImages + 0x35);
  bVar2 = *(byte *)(texture + 0x1b);
  *(ushort *)(texture + 0x1d) = texImages[1];
  uVar20 = (uint)*(byte *)(texture + 0xe);
  *(byte *)((int)texture + 0x73) = *(byte *)(texture + 0xe);
  uVar17 = (uint)*(byte *)(texImages + 0x33) - (uVar17 & 0xff);
  *(short *)((int)texture + 0x7a) = (short)uVar17;
  uVar9 = texImages[1];
  uVar19 = (uint)uVar9;
  *(ushort *)(texture + 0x1f) = *(ushort *)((int)texture + 0x3e);
  *(ushort *)(texture + 0x1d) = uVar9;
  textureTarget = *(byte *)(texture[0xc] + 1) & 0xf;
  *(byte *)(texture + 0x1b) = textureTarget;
  dVar31 = DOUBLE_001aa250;
  switch(textureTarget) {
  case 0:
    uVar22 = 1 << (*(byte *)(texImages + 0x32) - uVar15 & 0x3f);
    *(short *)((int)texture + 0x76) = (short)uVar22;
    bVar3 = *(byte *)((int)texImages + 0x65);
    *(undefined1 *)((int)texture + 0x6d) = 2;
    uVar21 = 1 << (bVar3 - uVar14 & 0x3f);
    *(short *)(texture + 0x1e) = (short)uVar21;
    texture[0x20] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,uVar22 & 0xffff) - dVar31));
    texture[0x21] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,uVar21 & 0xffff) - dVar31));
    break;
  case 1:
    uVar22 = 1 << (*(byte *)(texImages + 0x32) - uVar15 & 0x3f);
    *(short *)((int)texture + 0x76) = (short)uVar22;
    bVar3 = *(byte *)((int)texImages + 0x65);
    *(undefined1 *)((int)texture + 0x6d) = 3;
    uVar21 = 1 << (bVar3 - uVar14 & 0x3f);
    *(short *)(texture + 0x1e) = (short)uVar21;
    texture[0x20] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,uVar22 & 0xffff) - dVar31));
    texture[0x21] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,uVar21 & 0xffff) - dVar31));
    break;
  case 2:
    uVar22 = (uint)texImages[uVar16 * 0xc + 0x52] +
             (uint)*(byte *)(texImages + uVar16 * 0xc + 0x55) * -2;
    *(short *)((int)texture + 0x76) = (short)uVar22;
    bVar3 = *(byte *)(texImages + uVar16 * 0xc + 0x55);
    uVar9 = texImages[uVar16 * 0xc + 0x53];
    *(undefined1 *)((int)texture + 0x6d) = 2;
    uVar21 = (uint)uVar9 + (uint)bVar3 * -2;
    *(short *)(texture + 0x1e) = (short)uVar21;
    texture[0x20] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,uVar22 & 0xffff) - dVar31));
    texture[0x21] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,uVar21 & 0xffff) - dVar31));
    break;
  case 3:
    iVar26 = ((int (*)())gldTextureHasNonPowerOfTwoSize2)(texture,uVar18,uVar19,uVar22,uVar20,uVar21);
    if (iVar26 == 0) {
      *(short *)((int)texture + 0x76) = (short)(1 << (*(byte *)(texImages + 0x32) - uVar15 & 0x3f));
      *(short *)(texture + 0x1e) = (short)(1 << (*(byte *)((int)texImages + 0x65) - uVar14 & 0x3f));
    }
    else {
      *(ushort *)((int)texture + 0x76) =
           texImages[uVar16 * 0xc + 0x52] + (ushort)*(byte *)(texImages + uVar16 * 0xc + 0x55) * -2;
      *(ushort *)(texture + 0x1e) =
           texImages[uVar16 * 0xc + 0x53] + (ushort)*(byte *)(texImages + uVar16 * 0xc + 0x55) * -2;
    }
    dVar31 = DOUBLE_001aa250;
    uVar22 = (uint)*(ushort *)((int)texture + 0x76);
    uVar21 = (uint)*(ushort *)(texture + 0x1e);
    *(undefined1 *)((int)texture + 0x6d) = 2;
    uVar20 = (uint)*(byte *)((int)texture + 0x73);
    textureTarget = *(byte *)(texture + 0x1b);
    uVar17 = (uint)*(ushort *)((int)texture + 0x7a);
    uVar19 = (uint)*(ushort *)(texture + 0x1d);
    uVar18 = (uint)*(ushort *)(texture + 0x1f);
    texture[0x21] =
         (int)GH_F2U((float)((double)CONCAT44(0x43300000,(uint)*(ushort *)(texture + 0x1e)) - dVar31));
    texture[0x20] =
         (int)GH_F2U((float)((double)CONCAT44(0x43300000,(uint)*(ushort *)((int)texture + 0x76)) - dVar31));
    break;
  case 4:
    iVar26 = ((int (*)())gldTextureHasNonPowerOfTwoSize2)(texture,uVar18,uVar19,uVar22,uVar20,uVar21);
    if (iVar26 == 0) {
      *(short *)((int)texture + 0x76) = (short)(1 << (*(byte *)(texImages + 0x32) - uVar15 & 0x3f));
    }
    else {
      *(ushort *)((int)texture + 0x76) =
           texImages[uVar16 * 0xc + 0x52] + (ushort)*(byte *)(texImages + uVar16 * 0xc + 0x55) * -2;
    }
    uVar22 = (uint)*(ushort *)((int)texture + 0x76);
    uVar21 = 1;
    *(undefined2 *)(texture + 0x1e) = 1;
    texture[0x21] = 0x3f800000;
    *(undefined1 *)((int)texture + 0x6d) = 1;
    uVar20 = (uint)*(byte *)((int)texture + 0x73);
    textureTarget = *(byte *)(texture + 0x1b);
    uVar17 = (uint)*(ushort *)((int)texture + 0x7a);
    uVar19 = (uint)*(ushort *)(texture + 0x1d);
    uVar18 = (uint)*(ushort *)(texture + 0x1f);
    texture[0x20] =
         (int)GH_F2U((float)((double)CONCAT44(0x43300000,(uint)*(ushort *)((int)texture + 0x76)) -
                     DOUBLE_001aa250));
  }
  if (((((bVar1 != uVar20) || (bVar2 != textureTarget)) || ((uint)uVar7 != (uVar22 & 0xffff))) ||
      (((uint)uVar8 != (uVar21 & 0xffff) || ((uint)uVar5 != (uVar17 & 0xffff))))) ||
     ((uVar4 != uVar19 || (uVar6 != uVar18)))) {
    *(undefined1 *)((int)texture + 0x71) = 0;
    uVar14 = texture[0x17];
    texture[0x15] = texture[0x15] & 0xbfdfffff;
    uVar23 = ((uVar21 & 0xffff) - 1) * 0x20 & 0x10000 |
             ((uVar22 & 0xffff) - 1) * 0x10 & 0x8000 | uVar18 - 1 & 0x3fff;
    texture[0x17] = uVar14 & 0xfffffe1f;
    texture[0x18] = uVar23;
    puVar13 = PTR_DAT_001e88c8;
    texture[0x16] =
         -uVar18 & 0x80000000 |
         (uVar17 & 0xf) << 0x16 |
         (uVar21 - 1) * 0x800 & 0x3ff800 | uVar22 - 1 & 0x7ff | texture[0x16] & 0x40000000U;
    uVar15 = *(uint *)(puVar13 + uVar20 * 0x24 + 0x1c) >> 7 & 0x1f;
    texture[0x17] = uVar15 | uVar14 & 0xfffffe00;
    if (uVar20 == 0x29) {
      texture[0x18] = uVar23 | 0x4000;
      texture[0x17] = uVar14 & 0xffe00000 | 6;
    }
    else {
      uVar17 = (*(uint *)(puVar13 + uVar20 * 0x24 + 0x1c) & 0x70) << 5;
      texture[0x17] = uVar17 | uVar15 | uVar14 & 0xfffff000;
      uVar22 = (*(uint *)(puVar13 + uVar20 * 0x24 + 0x1c) & 0xe) << 0xb;
      texture[0x17] = uVar22 | uVar17 | uVar15 | uVar14 & 0xffff8000;
      uVar18 = *(uint *)(puVar13 + uVar20 * 0x24 + 0x20) >> 0xe & 0x38000;
      texture[0x17] = uVar18 | uVar22 | uVar17 | uVar15 | uVar14 & 0xfffc0000;
      texture[0x17] =
           *(uint *)(puVar13 + uVar20 * 0x24 + 0x20) >> 8 & 0x1c0000 |
           uVar18 | uVar22 | uVar17 | uVar15 | uVar14 & 0xffe00000;
    }
    uVar17 = texture[0x17];
    uVar15 = (*(uint *)(puVar13 + uVar20 * 0x24 + 0x20) >> 0x19 & 1) << 0x16;
    texture[0x17] = uVar15 | uVar17 & 0xff3fffff;
    *(byte *)((int)texture + 0x71) = (puVar13[uVar20 * 0x24 + 0x20] ^ 1) & 1;
    if (textureTarget == 0) {
      texture[0x17] = uVar15 | uVar17 & 0xf93fffff | 0x4000000;
    }
    else if (*(char *)((int)texture + 0x6d) == '\x03') {
      texture[0x17] = uVar15 | uVar17 & 0xf93fffff | 0x2000000;
    }
    else {
      texture[0x17] = uVar15 | uVar17 & 0xf93fffff;
    }
    if (uVar19 == 0x1907) {
      texture[0x17] = texture[0x17] & 0xfffff1ffU | 0xa00;
    }
  }
  uVar15 = (uint)texture[0x32] >> 0x16;
  if (*texture == 0) {
    if ((*texImages & 0x400) == 0) {
      texture[0x10] = uVar15 << 0x1e;
    }
    else {
      texture[0x10] = uVar15 << 0x1e | uVar16;
    }
  }
  else {
    texture[0x10] = uVar15 << 0x1e | *(uint *)(uVar16 * 0x20 + *texture + 0x48);
  }
  iVar26 = texture[0xc];
  cVar29 = *(char *)((int)texture + 0x72);
  if (GH_U2F((unsigned int)(texture[0x24])) != *(float *)(iVar26 + 0x2c)) {
    texture[0x24] = (int)GH_F2U(*(float *)(iVar26 + 0x2c));
    dVar31 = (double)*(float *)(iVar26 + 0x2c);
    if (DOUBLE_001aa1e8 <= dVar31) {
      iVar28 = (int)(dVar31 - DOUBLE_001aa1e8) + -0x80000000;
    }
    else {
      iVar28 = (int)*(float *)(iVar26 + 0x2c);
    }
    uVar15 = *(uint *)(&DAT_001aa510 + iVar28 * 4);
    if (((uint)texture[0x14] >> 0x15 & 7) != uVar15) {
      *(undefined2 *)((int)texture + 0xa2) = 0xffff;
      *(undefined2 *)(texture + 0x28) = 0xffff;
      texture[0x14] = (uVar15 & 7) << 0x15 | texture[0x14] & 0xff1fffffU;
    }
  }
  uVar4 = *(ushort *)(iVar26 + 0x16);
  if ((uint)*(ushort *)(texture + 0x28) == (uint)uVar4) {
    uVar15 = (uint)*(ushort *)(iVar26 + 0x18);
    if (*(ushort *)((int)texture + 0xa2) == uVar15) {
      cVar24 = *(char *)((int)texture + 0x71);
      if (cVar24 == *(char *)(texture + 0x1c)) goto LAB_0002e708;
      goto LAB_0002e690;
    }
    if (*(char *)((int)texture + 0x71) != *(char *)(texture + 0x1c)) goto LAB_0002e690;
LAB_0002e6d8:
    *(short *)((int)texture + 0xa2) = (short)uVar15;
    FUN_0002d210(hwState,uVar15);
    cVar24 = *(char *)((int)texture + 0x71);
  }
  else {
LAB_0002e690:
    *(ushort *)(texture + 0x28) = uVar4;
    FUN_0002d030(hwState,(uint)uVar4);
    *(byte *)((int)texture + 0x3d) = (byte)(-(uint)*(ushort *)(texture[0xc] + 0x5c) >> 0x1f);
    uVar15 = (uint)*(ushort *)(iVar26 + 0x18);
    if ((*(ushort *)((int)texture + 0xa2) != uVar15) ||
       (cVar24 = *(char *)((int)texture + 0x71), cVar24 != *(char *)(texture + 0x1c)))
    goto LAB_0002e6d8;
  }
  if (cVar29 != *(char *)((int)texture + 0x72)) {
    *(undefined2 *)((int)texture + 0x9e) = 0xffff;
    *(undefined2 *)((int)texture + 0x9a) = 0xffff;
    *(undefined2 *)(texture + 0x27) = 0xffff;
    cVar29 = *(char *)((int)texture + 0x72);
  }
LAB_0002e708:
  *(char *)(texture + 0x1c) = cVar24;
  uVar15 = (uint)*(ushort *)(iVar26 + 0x10);
  if (*(ushort *)((int)texture + 0x9a) != uVar15) {
    *(ushort *)((int)texture + 0x9a) = *(ushort *)(iVar26 + 0x10);
    if (cVar29 == '\0') {
      texture[0x14] =
           (uVar15 * 0x29 >> 0x10 & 1 | uVar15 * 0x97 >> 9 & 2 | uVar15 * 0x113 >> 7 & 4) ^ 2 |
           texture[0x14] & 0xfffffff8U;
    }
    else {
      texture[0x14] =
           (uVar15 * 0x29 >> 0x10 & 1 | uVar15 * 0x73 >> 5 & 2 | uVar15 * 7 >> 3 & 4) ^ 2 |
           texture[0x14] & 0xfffffff8U;
    }
  }
  uVar15 = (uint)*(ushort *)(iVar26 + 0x12);
  if (*(ushort *)(texture + 0x27) != uVar15) {
    *(ushort *)(texture + 0x27) = *(ushort *)(iVar26 + 0x12);
    if (*(char *)((int)texture + 0x6d) == '\x01') {
      texture[0x14] = texture[0x14] & 0xffffffc7;
    }
    else if (cVar29 == '\0') {
      texture[0x14] =
           ((uVar15 * 0x29 >> 0x10 & 1 | uVar15 * 0x97 >> 9 & 2 | uVar15 * 0x113 >> 7 & 4) ^ 2) << 3
           | texture[0x14] & 0xffffffc7U;
    }
    else {
      texture[0x14] =
           ((uVar15 * 0x29 >> 0x10 & 1 | uVar15 * 0x73 >> 5 & 2 | uVar15 * 7 >> 3 & 4) ^ 2) << 3 |
           texture[0x14] & 0xffffffc7U;
    }
  }
  uVar15 = (uint)*(ushort *)(iVar26 + 0x14);
  if (*(ushort *)((int)texture + 0x9e) != uVar15) {
    *(ushort *)((int)texture + 0x9e) = *(ushort *)(iVar26 + 0x14);
    if (*(char *)((int)texture + 0x6d) == '\x03') {
      if (cVar29 == '\0') {
        texture[0x14] =
             ((uVar15 * 0x29 >> 0x10 & 1 | uVar15 * 0x97 >> 9 & 2 | uVar15 * 0x113 >> 7 & 4) ^ 2) <<
             6 | texture[0x14] & 0xfffffe3fU;
      }
      else {
        texture[0x14] =
             ((uVar15 * 0x29 >> 0x10 & 1 | uVar15 * 0x73 >> 5 & 2 | uVar15 * 7 >> 3 & 4) ^ 2) << 6 |
             texture[0x14] & 0xfffffe3fU;
      }
    }
    else {
      texture[0x14] = texture[0x14] & 0xfffffe3f;
    }
  }
  iVar28 = texture[0xc];
  sVar10 = *(short *)(iVar28 + 2);
  if (sVar10 == 0x1902) {
    if (*(short *)(iVar26 + 0x48) == -0x7fb7) {
      *(undefined1 *)((int)texture + 0x6b) = 5;
    }
    else if (*(short *)(iVar26 + 0x48) == 0x1906) {
      *(undefined1 *)((int)texture + 0x6b) = 0;
    }
    else {
      *(undefined1 *)((int)texture + 0x6b) = 1;
    }
    *(undefined2 *)(texture + 0x25) = *(undefined2 *)(iVar26 + 0x48);
    *(undefined2 *)((int)texture + 0x96) = *(undefined2 *)(iVar26 + 0x42);
    uVar11 = *(undefined2 *)(iVar26 + 0x40);
    *(undefined2 *)(texture + 0x26) = uVar11;
    texture[0x23] = *(int *)(iVar26 + 0x44);
    sVar10 = *(short *)(iVar26 + 0x42);
    *(char *)((int)texture + 0x69) = (char)uVar11;
    fVar12 = FLOAT_001aa0d4;
    iVar28 = texture[0xc];
    *(bool *)((int)texture + 0x6a) = sVar10 == -0x77b2;
    *(bool *)(texture + 0x1a) = *(float *)(iVar26 + 0x44) != fVar12;
  }
  else if (sVar10 == -0x7fb7) {
    *(undefined1 *)((int)texture + 0x6b) = 5;
  }
  else {
    *(char *)((int)texture + 0x6b) = (char)sVar10 + -6;
  }
  *(undefined1 *)(texture + 0x29) = 0;
  dVar31 = DOUBLE_001aa1e8;
  fVar12 = FLOAT_001aa10c;
  *(char *)((int)texture + 0xa5) = *(char *)(iVar28 + 0x5f) - *(char *)(iVar28 + 0x5e);
  texture[0x12] = (uint)*(byte *)(iVar28 + 0x5f) << 0x10 | (uint)*(byte *)(iVar28 + 0x5e);
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
    uVar15 = (uint)(int)fVar12;
  }
  texture[0x13] = iVar26 << 0x10 | uVar15;
  ((void (*)())gldPackColorForSurfaceFormat)(hwState,(double)*(float *)(iVar28 + 0x1c),(double)*(float *)(iVar28 + 0x20),
               (double)*(float *)(iVar28 + 0x24),(double)*(float *)(iVar28 + 0x28));
  uVar14 = (uint)*(byte *)((int)texture + 0xa5);
  uVar15 = (uint)(int)(*(float *)(iVar28 + 0x34) + FLOAT_001aa10c);
  uVar17 = (uint)(int)(*(float *)(iVar28 + 0x30) + FLOAT_001aa10c);
  if ((int)uVar14 < (int)uVar15) {
    uVar15 = uVar14;
  }
  if ((int)uVar14 < (int)uVar17) {
    uVar17 = uVar14;
  }
  uVar16 = uVar14 + 1;
  if ((uint)*(byte *)((int)texture + 0x6e) < uVar14 + 1) {
    uVar16 = (uint)*(byte *)((int)texture + 0x6e);
  }
  uVar15 = (uVar15 - uVar17) + 1;
  if ((int)uVar16 <= (int)uVar15) {
    uVar15 = uVar16;
  }
  iVar26 = 1;
  if (0 < (int)uVar15) {
    iVar26 = (int)(char)uVar15;
  }
  texture[0x16] = (iVar26 + -1) * 0x4000000 & 0x3c000000U | texture[0x16] & 0xc3ffffffU;
  *(byte *)((int)texture + 0x39) = *(byte *)((int)texture + 0x39) & 0x7f;
  return;
}

/* FUN_0002ebc0 @ 0x2ebc0 (596 bytes) */
int FUN_0002ebc0(ctx, loopIndex)
  int ctx;
  int loopIndex;
{
  bool bVar1;
  char cVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  if (*(int *)(ctx + 0x2a90) != 0) {
    iVar5 = *(int *)(loopIndex * 4 + ctx + 0x18c);
    uVar4 = (uint)*(ushort *)(iVar5 + 0xa0);
    if ((((*(short *)(*(int *)(iVar5 + 0x30) + 0x18) != 0x2600) &&
         (sVar3 = *(short *)(*(int *)(iVar5 + 0x30) + 0x16), sVar3 != 0x2600)) && (sVar3 != 0x2702))
       && (sVar3 != 0x2700)) {
      *(uint *)(iVar5 + 0x50) =
           (*(uint *)(&DAT_001aa510 + *(int *)(ctx + 0x2a90) * 4) & 7) << 0x15 |
           *(uint *)(iVar5 + 0x50) & 0xff1fffff;
      if (3 < *(uint *)(ctx + 0x2a8c)) {
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
int FUN_0002ee30(ctxSaved, texture)
  undefined4 ctxSaved;
  int texture;
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
  
  iVar12 = texture + 0x3c;
  iVar11 = *(int *)(texture + 0x30);
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
    uVar7 = (uint)(int)fVar1;
  }
  if ((((uint)*(byte *)(iVar11 + 0x5f) << 0x10 | (uint)*(byte *)(iVar11 + 0x5e)) !=
       *(uint *)(texture + 0x48)) || ((iVar8 << 0x10 | uVar7) != *(uint *)(texture + 0x4c))) {
    ((int (*)())FUN_0002ddf0)(ctxSaved,texture);
    return;
  }
  cVar10 = *(char *)(texture + 0x72);
  if (*(float *)(texture + 0x90) != *(float *)(iVar11 + 0x2c)) {
    *(float *)(texture + 0x90) = *(float *)(iVar11 + 0x2c);
    dVar13 = (double)*(float *)(iVar11 + 0x2c);
    if (DOUBLE_001aa1e8 <= dVar13) {
      iVar8 = (int)(dVar13 - DOUBLE_001aa1e8) + -0x80000000;
    }
    else {
      iVar8 = (int)*(float *)(iVar11 + 0x2c);
    }
    uVar7 = *(uint *)(&DAT_001aa510 + iVar8 * 4);
    if ((*(uint *)(texture + 0x50) >> 0x15 & 7) != uVar7) {
      *(undefined2 *)(texture + 0xa2) = 0xffff;
      *(undefined2 *)(texture + 0xa0) = 0xffff;
      *(uint *)(texture + 0x50) = (uVar7 & 7) << 0x15 | *(uint *)(texture + 0x50) & 0xff1fffff;
    }
  }
  uVar4 = *(ushort *)(iVar11 + 0x16);
  if ((uint)*(ushort *)(texture + 0xa0) == (uint)uVar4) {
    uVar7 = (uint)*(ushort *)(iVar11 + 0x18);
    if (*(ushort *)(texture + 0xa2) != uVar7) {
      if (*(char *)(texture + 0x70) != *(char *)(texture + 0x71)) goto LAB_0002f040;
      goto LAB_0002f088;
    }
    cVar9 = *(char *)(texture + 0x71);
    if (cVar9 != *(char *)(texture + 0x70)) goto LAB_0002f040;
  }
  else {
LAB_0002f040:
    *(ushort *)(texture + 0xa0) = uVar4;
    FUN_0002d030(iVar12,(uint)uVar4);
    *(byte *)(texture + 0x3d) = (byte)(-(uint)*(ushort *)(*(int *)(texture + 0x30) + 0x5c) >> 0x1f);
    uVar7 = (uint)*(ushort *)(iVar11 + 0x18);
    if ((*(ushort *)(texture + 0xa2) != uVar7) ||
       (cVar9 = *(char *)(texture + 0x71), cVar9 != *(char *)(texture + 0x70))) {
LAB_0002f088:
      *(short *)(texture + 0xa2) = (short)uVar7;
      FUN_0002d210(iVar12,uVar7);
      cVar9 = *(char *)(texture + 0x71);
    }
    if (cVar10 != *(char *)(texture + 0x72)) {
      *(undefined2 *)(texture + 0x9e) = 0xffff;
      *(undefined2 *)(texture + 0x9a) = 0xffff;
      *(undefined2 *)(texture + 0x9c) = 0xffff;
      cVar10 = *(char *)(texture + 0x72);
    }
  }
  *(char *)(texture + 0x70) = cVar9;
  uVar7 = (uint)*(ushort *)(iVar11 + 0x10);
  if (*(ushort *)(texture + 0x9a) != uVar7) {
    *(ushort *)(texture + 0x9a) = *(ushort *)(iVar11 + 0x10);
    if (cVar10 == '\0') {
      *(uint *)(texture + 0x50) =
           (uVar7 * 0x29 >> 0x10 & 1 | uVar7 * 0x97 >> 9 & 2 | uVar7 * 0x113 >> 7 & 4) ^ 2 |
           *(uint *)(texture + 0x50) & 0xfffffff8;
    }
    else {
      *(uint *)(texture + 0x50) =
           (uVar7 * 0x29 >> 0x10 & 1 | uVar7 * 0x73 >> 5 & 2 | uVar7 * 7 >> 3 & 4) ^ 2 |
           *(uint *)(texture + 0x50) & 0xfffffff8;
    }
  }
  uVar7 = (uint)*(ushort *)(iVar11 + 0x12);
  if (*(ushort *)(texture + 0x9c) != uVar7) {
    *(ushort *)(texture + 0x9c) = *(ushort *)(iVar11 + 0x12);
    if (*(char *)(texture + 0x6d) == '\x01') {
      *(uint *)(texture + 0x50) = *(uint *)(texture + 0x50) & 0xffffffc7;
    }
    else if (cVar10 == '\0') {
      *(uint *)(texture + 0x50) =
           ((uVar7 * 0x29 >> 0x10 & 1 | uVar7 * 0x97 >> 9 & 2 | uVar7 * 0x113 >> 7 & 4) ^ 2) << 3 |
           *(uint *)(texture + 0x50) & 0xffffffc7;
    }
    else {
      *(uint *)(texture + 0x50) =
           ((uVar7 * 0x29 >> 0x10 & 1 | uVar7 * 0x73 >> 5 & 2 | uVar7 * 7 >> 3 & 4) ^ 2) << 3 |
           *(uint *)(texture + 0x50) & 0xffffffc7;
    }
  }
  uVar7 = (uint)*(ushort *)(iVar11 + 0x14);
  if (*(ushort *)(texture + 0x9e) != uVar7) {
    *(ushort *)(texture + 0x9e) = *(ushort *)(iVar11 + 0x14);
    if (*(char *)(texture + 0x6d) == '\x03') {
      if (cVar10 == '\0') {
        *(uint *)(texture + 0x50) =
             ((uVar7 * 0x29 >> 0x10 & 1 | uVar7 * 0x97 >> 9 & 2 | uVar7 * 0x113 >> 7 & 4) ^ 2) << 6
             | *(uint *)(texture + 0x50) & 0xfffffe3f;
      }
      else {
        *(uint *)(texture + 0x50) =
             ((uVar7 * 0x29 >> 0x10 & 1 | uVar7 * 0x73 >> 5 & 2 | uVar7 * 7 >> 3 & 4) ^ 2) << 6 |
             *(uint *)(texture + 0x50) & 0xfffffe3f;
      }
    }
    else {
      *(uint *)(texture + 0x50) = *(uint *)(texture + 0x50) & 0xfffffe3f;
    }
  }
  sVar5 = *(short *)(*(int *)(texture + 0x30) + 2);
  if (sVar5 == 0x1902) {
    if (*(short *)(iVar11 + 0x48) == -0x7fb7) {
      *(undefined1 *)(texture + 0x6b) = 5;
    }
    else if (*(short *)(iVar11 + 0x48) == 0x1906) {
      *(undefined1 *)(texture + 0x6b) = 0;
    }
    else {
      *(undefined1 *)(texture + 0x6b) = 1;
    }
    *(undefined2 *)(texture + 0x94) = *(undefined2 *)(iVar11 + 0x48);
    *(undefined2 *)(texture + 0x96) = *(undefined2 *)(iVar11 + 0x42);
    uVar6 = *(undefined2 *)(iVar11 + 0x40);
    *(undefined2 *)(texture + 0x98) = uVar6;
    *(undefined4 *)(texture + 0x8c) = *(undefined4 *)(iVar11 + 0x44);
    sVar5 = *(short *)(iVar11 + 0x42);
    *(char *)(texture + 0x69) = (char)uVar6;
    fVar1 = FLOAT_001aa0d4;
    *(bool *)(texture + 0x6a) = sVar5 == -0x77b2;
    *(bool *)(texture + 0x68) = *(float *)(iVar11 + 0x44) != fVar1;
  }
  else if (sVar5 == -0x7fb7) {
    *(undefined1 *)(texture + 0x6b) = 5;
  }
  else {
    *(char *)(texture + 0x6b) = (char)sVar5 + -6;
  }
  if (*(float *)(texture + 0xa8) == *(float *)(iVar11 + 0x1c)) {
    fVar1 = *(float *)(iVar11 + 0x20);
    if (*(float *)(texture + 0xac) == fVar1) {
      fVar2 = *(float *)(iVar11 + 0x24);
      if (*(float *)(texture + 0xb0) == fVar2) {
        fVar3 = *(float *)(iVar11 + 0x28);
        if (*(float *)(texture + 0xb4) == fVar3) goto LAB_0002f3e8;
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
  *(float *)(texture + 0xa8) = *(float *)(iVar11 + 0x1c);
  *(float *)(texture + 0xac) = fVar1;
  *(float *)(texture + 0xb0) = fVar2;
  *(float *)(texture + 0xb4) = fVar3;
  ((void (*)())gldPackColorForSurfaceFormat)(iVar12,(double)*(float *)(iVar11 + 0x1c),(double)*(float *)(iVar11 + 0x20),
               (double)*(float *)(iVar11 + 0x24),(double)*(float *)(iVar11 + 0x28));
LAB_0002f3e8:
  *(byte *)(texture + 0x39) = *(byte *)(texture + 0x39) & 0x7f;
  return;
}

/* window_mode_to_ati_format @ 0x2f410 (148 bytes) */
int window_mode_to_ati_format(param_1)
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

/* gldTextureFormatCodeMatchesType @ 0x2f4d0 (708 bytes) */
int gldTextureFormatCodeMatchesType(glFormat, glType, formatCode)
  uint glFormat;
  undefined *glType;
  int formatCode;
{
  bool typeMatches;
  
  if (glFormat == 0x1909) {
    if (formatCode == 1) {
LAB_0002f7a0:
      return glType == ((unsigned char *)0x00001401);
    }
    if (formatCode == 0x13) goto LAB_0002f790;
    if (formatCode == 0x1f) {
LAB_0002f6c0:
      if (glType == ((unsigned char *)0x0000140b)) {
        return true;
      }
      return false;
    }
    if (formatCode != 0x19) {
      return false;
    }
  }
  else if (glFormat < 0x190a) {
    if (glFormat == 0x1907) {
      if (formatCode == 5) {
        if (glType != (undefined *)0x8363) {
          return false;
        }
        return true;
      }
      if (formatCode == 0x28) {
        if (glType == (undefined *)0x8032) {
          return true;
        }
        return false;
      }
      return false;
    }
    if (glFormat < 0x1908) {
      if (glFormat != 0x1906) {
        return false;
      }
      if (formatCode == 2) goto LAB_0002f7a0;
      if (formatCode == 0x14) goto LAB_0002f790;
      if (formatCode == 0x20) goto LAB_0002f6c0;
      if (formatCode != 0x1a) {
        return false;
      }
    }
    else {
      if (formatCode == 0x12) {
LAB_0002f790:
        return glType == ((unsigned char *)0x00001406);
      }
      if (formatCode == 0x1e) {
        return glType == ((unsigned char *)0x0000140b);
      }
      if (formatCode == 10) {
        return glType == (undefined *)0x8367;
      }
      if (formatCode == 9) {
LAB_0002f5d0:
        if (glType == (undefined *)0x8035) {
          return true;
        }
        if (glType == ((unsigned char *)0x00001401)) {
          return true;
        }
        return false;
      }
      if (formatCode == 0x23) {
LAB_0002f5fc:
        if (glType == (undefined *)0x8368) {
          return true;
        }
        return false;
      }
      if (formatCode != 0x18) {
        return false;
      }
    }
  }
  else {
    if (glFormat == 0x80e1) {
      if (formatCode == 7) {
        typeMatches = glType == (undefined *)0x8366;
      }
      else if (formatCode == 6) {
        typeMatches = glType == (undefined *)0x8365;
      }
      else if (formatCode == 0xb) {
        typeMatches = glType == (undefined *)0x8367;
      }
      else {
        if (formatCode == 8) goto LAB_0002f5d0;
        typeMatches = false;
        if (formatCode == 0x24) goto LAB_0002f5fc;
        if (formatCode == 0x11) {
          if (glType == ((unsigned char *)0x00001406)) {
            return true;
          }
          return typeMatches;
        }
        if (formatCode == 0x1d) {
          if (glType == ((unsigned char *)0x0000140b)) {
            return true;
          }
          return false;
        }
      }
      if (formatCode != 0x17) {
        return typeMatches;
      }
      if (glType == ((unsigned char *)0x00001403)) {
        return true;
      }
      return typeMatches;
    }
    if (glFormat == 0x85b9) {
      if (formatCode == 0x27) {
        if (glType == (undefined *)0x85ba) {
          return true;
        }
        return false;
      }
      if (formatCode != 0x26) {
        return false;
      }
      if (glType == (undefined *)0x85bb) {
        return true;
      }
      return false;
    }
    if (glFormat != 0x190a) {
      return false;
    }
    if (formatCode == 4) goto LAB_0002f7a0;
    if (formatCode == 0x16) {
      return glType == ((unsigned char *)0x00001406);
    }
    if (formatCode == 0x22) goto LAB_0002f6c0;
    if (formatCode != 0x1c) {
      return false;
    }
  }
  if (glType == ((unsigned char *)0x00001403)) {
    return true;
  }
  return false;
}

/* gldTextureFormatCodeFromFormatType @ 0x2f7c0 (716 bytes) */
int gldTextureFormatCodeFromFormatType(glFormat, glType)
  uint glFormat;
  undefined *glType;
{
  undefined4 formatCode;
  
  if (glFormat == 0x1909) {
    formatCode = 1;
    if (glType != ((unsigned char *)0x00001401)) {
      if (glType == ((unsigned char *)0x00001406)) {
        return 0x13;
      }
      formatCode = 0;
      if (glType == ((unsigned char *)0x0000140b)) {
        return 0x1f;
      }
    }
    if (glType != ((unsigned char *)0x00001403)) {
      return formatCode;
    }
    return 0x19;
  }
  if (glFormat < 0x190a) {
    if (glFormat == 0x1907) {
      if (glType == (undefined *)0x8363) {
        return 5;
      }
      if (glType != (undefined *)0x8032) {
        return 0;
      }
      return 0x28;
    }
    if (glFormat < 0x1908) {
      if (glFormat != 0x1906) {
        return 0;
      }
      formatCode = 2;
      if (glType != ((unsigned char *)0x00001401)) {
        if (glType == ((unsigned char *)0x00001406)) {
          return 0x14;
        }
        formatCode = 0;
        if (glType == ((unsigned char *)0x0000140b)) {
          return 0x20;
        }
      }
      if (glType != ((unsigned char *)0x00001403)) {
        return formatCode;
      }
      return 0x1a;
    }
    formatCode = 0x12;
    if ((glType == ((unsigned char *)0x00001406)) || (formatCode = 0, glType != ((unsigned char *)0x0000140b))) {
      if (glType != (undefined *)0x8035) goto LAB_0002f8fc;
      formatCode = 9;
    }
    else {
      formatCode = 0x1e;
LAB_0002f8fc:
      if (glType == (undefined *)0x8367) {
        formatCode = 10;
        goto LAB_0002f934;
      }
    }
    if (glType == ((unsigned char *)0x00001401)) {
      return 9;
    }
LAB_0002f934:
    if (glType == (undefined *)0x8368) {
      return 0x23;
    }
    if (glType != ((unsigned char *)0x00001403)) {
      return formatCode;
    }
    return 0x18;
  }
  if (glFormat != 0x80e1) {
    if (glFormat == 0x85b9) {
      if (glType == (undefined *)0x85ba) {
        return 0x27;
      }
      if (glType != (undefined *)0x85bb) {
        return 0;
      }
      return 0x26;
    }
    if (glFormat != 0x190a) {
      return 0;
    }
    formatCode = 4;
    if (glType != ((unsigned char *)0x00001401)) {
      if (glType == ((unsigned char *)0x00001406)) {
        return 0x16;
      }
      formatCode = 0;
      if (glType == ((unsigned char *)0x0000140b)) {
        return 0x22;
      }
    }
    if (glType != ((unsigned char *)0x00001403)) {
      return formatCode;
    }
    return 0x1c;
  }
  formatCode = 7;
  if ((glType == (undefined *)0x8366) || (formatCode = 0, glType != (undefined *)0x8365)) {
    if (glType != (undefined *)0x8035) goto LAB_0002f84c;
    formatCode = 8;
  }
  else {
    formatCode = 6;
LAB_0002f84c:
    if (glType == (undefined *)0x8367) {
      formatCode = 0xb;
      goto LAB_0002f884;
    }
  }
  if (glType == ((unsigned char *)0x00001401)) {
    return 8;
  }
LAB_0002f884:
  if (glType == (undefined *)0x8368) {
    formatCode = 0x24;
  }
  else if (glType == ((unsigned char *)0x00001406)) {
    return 0x11;
  }
  if (glType == ((unsigned char *)0x0000140b)) {
    return 0x1d;
  }
  if (glType != ((unsigned char *)0x00001403)) {
    return formatCode;
  }
  return 0x17;
}

/* FUN_0002fac0 @ 0x2fac0 (2252 bytes) */
int FUN_0002fac0(param_1, texture)
  int param_1;
  int texture;
{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  char cVar6;
  char cVar7;
  int iVar8;
  undefined1 window_mode_to_ati_formatResult;
  char cVar10;
  char cVar11;
  char cVar12;
  ushort *puVar13;
  undefined4 local_38;
  undefined4 local_34;
  uint local_30 [9];
  
  puVar13 = *(ushort **)(texture + 0x30);
  uVar1 = *puVar13;
  if ((uVar1 & 0x200) != 0) {
    return;
  }
  if ((uVar1 & 0x400) != 0) {
    local_38 = *(undefined4 *)(puVar13 + 4);
    *(undefined1 *)(texture + 0x38) = 0;
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
    window_mode_to_ati_formatResult = ((int (*)())window_mode_to_ati_format)(local_30[0]);
    *(undefined1 *)(texture + 0x38) = window_mode_to_ati_formatResult;
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
  *(char *)(texture + 0x38) = cVar7;
  return;
}

/* gldCompressedImageBytes @ 0x303d0 (68 bytes) */
int gldCompressedImageBytes(format, width, height, depth)
  uint format;
  int width;
  int height;
  int depth;
{
  int iVar1;
  
  iVar1 = (width + 3 >> 2) * (height + 3 >> 2) * depth;
  if (format == 0xc) {
    return iVar1 * 8;
  }
  if ((0xb < format) && (format < 0x10)) {
    return iVar1 * 0x10;
  }
  return 0;
}

/* FUN_00030420 @ 0x30420 (392 bytes) */
int FUN_00030420(param_1, formatInfo, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int formatInfo;
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
  uVar2 = param_4 >> (*(uint *)(formatInfo + 0x14) & 7) & 0x3ffe;
  uVar6 = (param_5 & 1) << 0x10;
  uVar1 = (param_5 & 6) << 0x10;
  *(uint *)(param_1 + 0xc) = uVar1 | uVar6 | uVar2 | uVar5 & 0xffe0c001;
  *(uint *)(param_1 + 0xc) =
       (*(uint *)(formatInfo + 0x18) & 0x3c00) << 0xb | uVar1 | uVar6 | uVar2 | uVar5 & 0xfe00c001;
  uVar6 = *(uint *)(formatInfo + 0x18);
  *(uint *)(param_1 + 0x1c) =
       (param_7 - 1 & 0x7ff) << 0xb | param_6 - 1 & 0x7ff | *(uint *)(param_1 + 0x1c) & 0x80000000 |
       0x80000000;
  *(uint *)(param_1 + 0x14) = uVar6 >> 0x1e;
  uVar6 = *(uint *)(formatInfo + 0x14);
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
int FUN_000307a0(ctx, packetIndex)
  int ctx;
  int packetIndex;
{
  uint *headerWord;
  int *cursor;
  
  cursor = *(int **)(ctx + GLD_writeCursor);
  if (*(int **)(ctx + GLD_ringLimit) <= cursor + 1) {
    gld_submitRing(ctx,0x1000000);
    cursor = *(int **)(ctx + GLD_writeCursor);
  }
  headerWord = *(uint **)(ctx + GLD_lastHeader);
  *(int **)(ctx + GLD_writeCursor) = cursor + 1;
  *headerWord = (int)cursor - (int)headerWord >> 2 | *headerWord;
  *(int **)(ctx + GLD_lastHeader) = cursor;
  *cursor = packetIndex * 0x1000000 + 0x16000000;
  return FUN_000a8320(ctx,packetIndex);
}

/* FUN_00030840 @ 0x30840 (124 bytes) */
int FUN_00030840(ctx, param_2, texture)
  int ctx;
  undefined4 param_2;
  undefined4 texture;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0xf;
  iVar3 = ctx;
  do {
    if (*(int *)(iVar3 + 0x1c8) != 0) {
      param_2 = gld_emitUnitObjectPacket(ctx,0,iVar2,param_2);
    }
    iVar2 = iVar2 + -1;
    iVar3 = iVar3 + -4;
  } while (iVar2 != 0);
  uVar1 = gld_emitUnitObjectPacket(ctx,texture,0,param_2);
  return uVar1;
}

/* FUN_000308c0 @ 0x308c0 (192 bytes) */
int FUN_000308c0(ctx, param_2)
  int ctx;
  undefined4 param_2;
{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int loopIndex;
  int iVar6;
  int iVar7;
  
  loopIndex = 0;
  iVar4 = 0;
  iVar6 = ctx;
  do {
    iVar3 = *(int *)(iVar6 + 0x18c);
    if (iVar3 != 0) {
      iVar7 = 5;
      piVar2 = (int *)(iVar4 + *(int *)(ctx + 0x18));
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
    if ((loopIndex == 0) || (iVar3 != 0)) {
      param_2 = gld_emitUnitObjectPacket(ctx,iVar3,loopIndex,param_2);
    }
    bVar1 = loopIndex == 0xf;
    iVar4 = iVar4 + 0x14;
    iVar6 = iVar6 + 4;
    loopIndex = loopIndex + 1;
    if (bVar1) {
      return param_2;
    }
  } while( true );
}

/* floorLog2 @ 0x30990 (40 bytes) */
int floorLog2(value)
  uint value;
{
  int iVar1;
  
  iVar1 = 0;
  for (; 1 < value; value = value >> 1) {
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
  uVar1 = gld_emitUnitObjectPacket(iVar2,param_2,param_3,uVar1);
  *(undefined4 *)(iVar2 + 0x298c) = uVar1;
                    
                    
  (**(code **)(iVar2 + 0x299c))(param_1,uVar1);
  return;
}

/* FUN_00030a50 @ 0x30a50 (8 bytes) */
int FUN_00030a50(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  return _gldDeleteTexture(*(undefined4 *)(param_1 + 4),param_2);
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

/* gldTextureHasNonPowerOfTwoSize @ 0x30b50 (236 bytes) */
int gldTextureHasNonPowerOfTwoSize(texture, unusedArg2, unusedArg3, unusedArg4, unusedArg5, unusedArg6)
  int texture;
  undefined4 unusedArg2;
  undefined4 unusedArg3;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
{
  uint leftoverBits;
  uint levelDepth;
  int levelRecord;
  byte targetByte;
  uint levelHeight;
  int texImages;
  uint borderWidth;
  byte targetKind;
  uint levelWidth;
  
  texImages = *(int *)(texture + 0x30);
  targetByte = *(byte *)(texImages + 1);
  targetKind = targetByte & 0xf;
  *(byte *)(texture + 0x6c) = targetKind;
  levelRecord = *(short *)(texImages + 0x3c) * 0x18 + texImages;
  borderWidth = (uint)*(byte *)(levelRecord + 0xaa);
  levelWidth = (uint)*(ushort *)(levelRecord + 0xa4) + borderWidth * -2;
  if ((int)levelWidth < 1) {
    levelWidth = 1;
  }
  levelHeight = (uint)*(ushort *)(levelRecord + 0xa6) + borderWidth * -2;
  if ((int)levelHeight < 1) {
    levelHeight = 1;
  }
  levelDepth = (uint)*(ushort *)(levelRecord + 0xa8) + borderWidth * -2;
  if ((int)levelDepth < 1) {
    levelDepth = 1;
  }
  if (targetKind == 1) {
    if ((levelWidth & levelWidth - 1) != 0) {
      return 1;
    }
    if ((levelHeight & levelHeight - 1) != 0) {
      return 1;
    }
    leftoverBits = levelDepth & levelDepth - 1;
  }
  else if (((targetByte & 0xf) == 0) || (targetKind == 3)) {
    if ((levelWidth & levelWidth - 1) != 0) {
      return 1;
    }
    leftoverBits = levelHeight & levelHeight - 1;
  }
  else {
    if (targetKind != 4) {
      return 1;
    }
    leftoverBits = levelWidth & levelWidth - 1;
  }
  if (leftoverBits != 0) {
    return 1;
  }
  return 0;
}

/* FUN_00030c50 @ 0x30c50 (684 bytes) */
int FUN_00030c50(glContext, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int glContext;
  int param_2;
  int param_3;
  int param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  int param_8;
{
  int allocation2;
  undefined2 *allocation;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int local_58 [9];
  
  uVar7 = *(undefined4 *)(glContext + 4);
  local_58[0] = 0;
  allocation = (undefined2 *)_malloc(0x910);
  if (allocation != (undefined2 *)0x0) {
    allocation[0x24] = 0;
    *(undefined4 *)(allocation + 0x26) = 0;
    *(undefined4 *)(allocation + 4) = 0;
    allocation[6] = 0x405;
    *(undefined4 *)(allocation + 0x22) = 0;
    allocation[10] = 0x2901;
    allocation[8] = 0x2901;
    allocation[9] = 0x2901;
    *(undefined4 *)(allocation + 0xe) = 0;
    *(undefined4 *)(allocation + 0x10) = 0;
    *(undefined4 *)(allocation + 0x12) = 0;
    *(undefined4 *)(allocation + 0x14) = 0;
    *(undefined4 *)(allocation + 0x1c) = 0;
    allocation[0x1e] = 0;
    allocation[0x1f] = 0;
    allocation[0x20] = 0;
    allocation[0x21] = 0;
    *allocation = (short)param_8;
    allocation[0xd] = 0x85bd;
    *(undefined4 *)(allocation + 0x16) = 0x3f800000;
    *(undefined4 *)(allocation + 2) = 0x3f800000;
    *(undefined4 *)(allocation + 0x18) = 0xc47a0000;
    *(undefined4 *)(allocation + 0x1a) = 0x447a0000;
    allocation[0x2e] = 0x2600;
    allocation[0xb] = 0x2600;
    allocation[0xc] = 0x2600;
    allocation[1] = (*(unsigned short *)((unsigned char *)&(param_5) + 2));
    allocation[0x2a] = (*(unsigned short *)((unsigned char *)&(param_5) + 2));
    allocation[0x2c] = (*(unsigned short *)((unsigned char *)&(param_5) + 2));
    allocation[0x2d] = (*(unsigned short *)((unsigned char *)&(param_7) + 2));
    *(undefined1 *)(allocation + 0x2f) = 0;
    *(uint *)(allocation + 0x24) = *(uint *)(allocation + 0x24) & 0xffff7f7f;
    *(undefined1 *)((int)allocation + 0x5f) = 0;
    iVar2 = ((int (*)())floorLog2)(param_2);
    iVar3 = ((int (*)())floorLog2)(param_3);
    iVar4 = ((int (*)())floorLog2)(param_4);
    *(char *)(allocation + 0x30) = (char)iVar2;
    *(char *)(allocation + 0x31) = (char)iVar4;
    *(char *)((int)allocation + 0x61) = (char)iVar3;
    iVar6 = iVar3;
    if (iVar3 < iVar4) {
      iVar6 = iVar4;
    }
    iVar5 = iVar2;
    if (iVar2 < iVar6) {
      iVar5 = iVar6;
    }
    *(char *)((int)allocation + 0x65) = (char)iVar3;
    *(char *)(allocation + 0x32) = (char)iVar2;
    *(undefined1 *)(allocation + 0x36) = 1;
    *(undefined1 *)(allocation + 0x35) = 1;
    *(char *)(allocation + 0x33) = (char)iVar4;
    *(char *)((int)allocation + 0x67) = (char)iVar5;
    *(undefined1 *)((int)allocation + 0x6d) = 0;
    allocation[0x3e] = 1;
    *(char *)((int)allocation + 99) = (char)iVar5;
    *(undefined1 *)((int)allocation + 0x69) = 0;
    *(undefined1 *)((int)allocation + 0x6b) = 0;
    allocation[0x38] = 1;
    *(char *)(allocation + 0x37) = (param_8 == 3) << 1;
    *(char *)((int)allocation + 0x6f) = (param_8 == 1) << 1;
    iVar2 = 1 << (*(uint *)(&DAT_001d9f48 + (uint)(byte)param_6 * 0x24) & 7);
    allocation2 = _malloc(iVar2 * param_4 * param_2 * param_3);
    if (allocation2 != 0) {
      *(int *)(allocation + 0x5a) = allocation2;
      allocation[0x54] = (short)param_4;
      allocation[0x57] = (short)param_3;
      *(undefined1 *)(allocation + 0x55) = 0;
      allocation[0x58] = (*(unsigned short *)((unsigned char *)&(param_5) + 2));
      allocation[0x56] = (short)param_2 * (short)iVar2;
      allocation[0x59] = (*(unsigned short *)((unsigned char *)&(param_7) + 2));
      allocation[0x52] = (short)param_2;
      allocation[0x53] = (short)param_3;
      iVar6 = _gldCreateTexture(uVar7,local_58,allocation);
      if ((iVar6 == 0) && (local_58[0] != 0)) {
        *(undefined1 *)(local_58[0] + 0x39) = 0xff;
        *(byte *)(local_58[0] + 0x38) = (byte)param_6;
        *(ushort *)(local_58[0] + 0x24) = *(ushort *)(local_58[0] + 0x24) | 1;
        return local_58[0];
      }
    }
    _free(allocation);
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
int FUN_00030f60(ctx, texture, face, level, param_5)
  undefined4 ctx;
  int texture;
  int face;
  int level;
  uint *param_5;
{
  ushort uVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar3 = (uint)*(byte *)(texture + 0x38);
  if (uVar3 == 0) {
    ((int (*)())FUN_0002fac0)(ctx,texture);
    uVar3 = (uint)*(byte *)(texture + 0x38);
  }
  iVar4 = uVar3 * 0x24;
  uVar5 = *(uint *)(&DAT_001d9f44 + iVar4);
  if ((uVar5 & 0x3f0000) != 0) {
    if ((uVar5 & 0xfc00) != 0) {
      if ((((uVar5 & 0x3f0) != 0) && (*(uint *)(&DAT_001d9f48 + iVar4) >> 0x1a != 0)) &&
         (*(short *)(*(int *)(texture + 0x30) + 2) == 0x1907)) {
        uVar1 = *(ushort *)(&DAT_001d9f3e + iVar4);
        param_5[4] = 0;
        *param_5 = (uint)uVar1;
        param_5[7] = *(uint *)(&DAT_001d9f48 + iVar4) >> 8 & 0x3f;
        goto LAB_000310c0;
      }
    }
  }
  if (uVar3 == 0x29) {
    sVar2 = *(short *)(*(int *)(texture + 0x30) + 2);
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
    iVar4 = *(int *)(texture + 0x30) + 0xa0 + level * 0x18 + face * 0x168;
    uVar3 = ((int (*)())gldCompressedImageBytes)((uint)*(byte *)(texture + 0x38),(uint)*(ushort *)(iVar4 + 4),
                         (uint)*(ushort *)(iVar4 + 6),(uint)*(ushort *)(iVar4 + 8));
    param_5[8] = uVar3;
  }
  return;
}

/* gldTextureFormatLookup @ 0x31170 (164 bytes) */
int gldTextureFormatLookup(formatIndex, unusedArg2, outDesc, outSizeLog2, outBits20, outBits17, outBytesPerTexel, outBits23, outBits30)
  uint formatIndex;
  undefined4 unusedArg2;
  int outDesc;
  uint *outSizeLog2;
  uint *outBits20;
  uint *outBits17;
  int *outBytesPerTexel;
  uint *outBits23;
  uint *outBits30;
{
  int entryOffset;
  
  entryOffset = (formatIndex & 0xff) * 0x24;
  *(uint *)(outDesc + 0x18) = *(uint *)(&DAT_001d9f44 + entryOffset) >> 0x1b;
  *(uint *)(outDesc + 0x1c) = *(uint *)(&DAT_001d9f44 + entryOffset) >> 0x16 & 0x1f;
  *outBits23 = *(uint *)(&DAT_001d9f4c + entryOffset) >> 0x17 & 0x1f;
  *outBits30 = *(uint *)(&DAT_001d9f4c + entryOffset) >> 0x1e;
  *outSizeLog2 = *(uint *)(&DAT_001d9f48 + entryOffset) & 7;
  *outBits20 = *(uint *)(&DAT_001d9f4c + entryOffset) >> 0x14 & 7;
  *outBits17 = *(uint *)(&DAT_001d9f4c + entryOffset) >> 0x11 & 7;
  *outBytesPerTexel = 1 << (*(uint *)(&DAT_001d9f48 + entryOffset) & 7);
  *(uint *)(outDesc + 0x24) = *(uint *)(outDesc + 0x24) & *(uint *)(&DAT_001d9f40 + entryOffset);
  return;
}

/* gldTextureFormatEntryForLevel @ 0x31220 (280 bytes) */
int gldTextureFormatEntryForLevel(ctx, texture, faceIndex, levelIndex, modeFlag)
  int ctx;
  int texture;
  int faceIndex;
  uint levelIndex;
  int modeFlag;
{
  bool modeFlagIsZero;
  ushort imagesFlags;
  int formatEntryOffset;
  undefined *formatEntry;
  ushort *texImages;
  
  texImages = *(ushort **)(texture + 0x30);
  if (*(char *)(texture + 0x38) == '\0') {
    ((int (*)())FUN_0002fac0)(ctx,texture);
  }
  modeFlagIsZero = modeFlag == 0;
  if ((((!modeFlagIsZero) ||
       ((((*(uint *)(((unsigned char *)0x000030b0) + *(int *)(ctx + 0x10)) & 0x1ff) == 0 &&
         ((*(uint *)(((unsigned char *)0x000030b4) + *(int *)(ctx + 0x10)) & 0xff0000) == 0)) &&
        ((*(uint *)(((unsigned char *)0x000030b4) + *(int *)(ctx + 0x10)) & 0xff1) == 0)))) &&
      ((*(char *)(texImages + faceIndex * 0xb4 + levelIndex * 0xc + 0x55) == '\0' &&
       (imagesFlags = *texImages, (imagesFlags & 0xf) != 4)))) && ((!modeFlagIsZero || ((imagesFlags & 0x400) == 0)))) {
    formatEntryOffset = (uint)*(byte *)(texture + 0x38) * 0x24;
    formatEntry = &DAT_001d9f34 + formatEntryOffset;
    if (((*(uint *)(*(int *)(texture + 0x30) + 0x48) & 0x8000) == 0) && (modeFlagIsZero)) {
      return formatEntry;
    }
    if (levelIndex != *(byte *)(*(int *)(texture + 0x30) + 0x5e)) {
      return formatEntry;
    }
    if ((*(uint *)(&DAT_001d9f54 + formatEntryOffset) & 0x1000000) != 0) {
      return formatEntry;
    }
  }
  return (undefined *)0x0;
}

/* FUN_00031340 @ 0x31340 (1352 bytes) */
int FUN_00031340(ctx, param_2, param_3, param_4, surfaceFormat, surfaceType, levelBuffer, procPitch)
  int ctx;
  int *param_2;
  int param_3;
  uint param_4;
  undefined4 *surfaceFormat;
  undefined4 surfaceType;
  int levelBuffer;
  undefined4 *procPitch;
{
  int gld_isStampRetiredResult;
  int loopIndex;
  int loopIndex2;
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
  a1 = surfaceFormat;
  uVar10 = surfaceType;
  a7 = procPitch;
  if ((*(short *)(param_2[0xc] + 2) == 0x1902) && (*(char *)(param_2 + 0x32) == '\x01')) {
    iVar13 = param_3;
    a6 = (undefined4 *)(**(code **)(ctx + 0x2998))(ctx + 0x240,0x3fa);
    *(undefined4 **)(ctx + 0x298c) = a6;
    a7 = a6 + 0x3ed;
    uVar10 = 0x113c8;
    a1 = a6 + 0x3f8;
    puVar4 = *(uint **)(ctx + 0x1d8);
    *puVar4 = (int)a6 - (int)puVar4 >> 2 | *puVar4;
    *(undefined4 **)(ctx + 0x1d8) = a6;
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
    *(undefined4 **)(ctx + 0x298c) = a1;
    (**(code **)(ctx + 0x299c))(ctx + 0x240,a1,iVar13,uVar17,a1,0x113c8,a6,a7);
    if (*(int *)(ctx + 0x1e4) + 0x28U < *(uint *)(ctx + 0x1dc)) {
      gld_submitRing(ctx,0x1000000);
    }
    *(undefined1 *)(param_2 + 0x32) = 0;
  }
  cVar2 = *(char *)((int)puVar16 + 0x16);
  if ((cVar2 != '\x03') && (cVar2 != '\a')) {
    if (cVar2 != '\x06') {
      return 0x2717;
    }
    if ((0x1ffff < (int)puVar16[4]) &&
       (*(int *)(ctx + 0x1e4) + 0x28U < *(uint *)(ctx + 0x1dc))) {
      gld_submitRing(ctx,0x1000000);
    }
    iVar14 = param_3 * 2;
    iVar13 = iVar14 + (int)puVar16;
    if ((((uint)*(ushort *)(iVar13 + 0x28) & ~(uint)*(ushort *)(iVar13 + 0x1c)) >> (param_4 & 0x3f)
        & 1) == 0) {
      return 0;
    }
    gld_isStampRetiredResult = gld_isStampRetired(ctx,puVar16[3]);
    if (gld_isStampRetiredResult == 0) {
      uVar17 = 1;
      a1 = (undefined4 *)0x0;
      uVar10 = 0;
      _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + 4),9,puVar16 + 3,1,0,0);
    }
    if ((levelBuffer != 0) && ((*(uint *)(ctx + 0x24) & 0x82) != 0)) {
      gldFlushDataCacheRangeSync(ctx,levelBuffer,param_2[4],uVar17,a1,uVar10,iVar13,a7);
    }
    *(ushort *)((int)puVar16 + iVar14 + 0x1c) =
         *(ushort *)((int)puVar16 + iVar14 + 0x1c) | *(ushort *)((int)puVar16 + iVar14 + 0x28);
    return 0;
  }
  iVar13 = iVar14 + 0x40 + (param_3 * 0xd + param_4) * 0x20;
  if ((0x1ffff < (int)puVar16[4]) &&
     (*(int *)(ctx + 0x1e4) + 0x28U < *(uint *)(ctx + 0x1dc))) {
    gld_submitRing(ctx,0x1000000);
  }
  if ((((uint)*(ushort *)((int)puVar16 + param_3 * 2 + 0x28) &
       ~(uint)*(ushort *)((int)puVar16 + param_3 * 2 + 0x1c)) >> (param_4 & 0x3f) & 1) != 0) {
    local_b8 = *puVar16;
    local_b4 = param_4 | param_3 << 0x10;
    _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + 4),0xd,&local_b8,2,0,0);
  }
  if ((*(uint *)(iVar14 + 0x20) & 0x10000000) != 0) {
    gld_isStampRetiredResult = gld_isStampRetired(ctx,*(undefined4 *)(iVar14 + 0x1c));
    if (gld_isStampRetiredResult == 0) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + 4),9,iVar14 + 0x1c,1,0,0);
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
  ((int (*)())gldTextureFormatLookup)((uint)*(byte *)(param_2 + 0xe),param_2,&local_b8,auStack_140,puVar9,puVar11,
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
  local_118 = levelBuffer;
  local_114 = procPitch;
  local_fc = iVar6;
  local_f8 = iVar15;
  _glgConvertType(surfaceFormat,surfaceType,puVar7,puVar8,puVar9,puVar11,local_a0,0);
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
    loopIndex = 0;
    do {
      if (0 < iVar12) {
        loopIndex2 = 0;
        local_128 = iVar14;
        do {
          loopIndex2 = loopIndex2 + 1;
          _glgProcessPixels(0,&local_128,puVar7,puVar8,puVar9,puVar11,local_a0,uVar10);
          local_128 = iVar15 * local_124 + local_128;
          local_a0 = iVar15 * (int)local_114 + local_118;
          local_118 = local_a0;
        } while (iVar12 != loopIndex2);
      }
      loopIndex = loopIndex + 1;
      iVar14 = iVar14 + *(int *)(iVar13 + 0xc);
    } while (loopIndex < (int)(uint)*(ushort *)(iVar13 + 2));
  }
  return 0;
}

/* _gldGetTextureLevel @ 0x31890 (176 bytes) */
int _gldGetTextureLevel(ctx, texture, face, level)
  int ctx;
  int texture;
  int face;
  int level;
{
  ushort levelFormat;
  int bytesPerElement;
  undefined4 returnCode;
  int levelEntry;
  
  returnCode = 0x2717;
  if (*(int *)(texture + 0x30) != 0) {
    levelEntry = *(int *)(texture + 0x30) + 0xa0 + level * 0x18 + face * 0x168;
    levelFormat = *(ushort *)(levelEntry + 0xc);
    bytesPerElement = gldPixelUnitBytes((uint)*(ushort *)(levelEntry + 0x10),(uint)*(ushort *)(levelEntry + 0x12));
    _pthread_mutex_lock(*(undefined4 *)(ctx + GLD_mutex));
    returnCode = ((int (*)())FUN_00031340)(ctx,texture,face,level,(uint)*(ushort *)(levelEntry + 0x10),
                         (uint)*(ushort *)(levelEntry + 0x12),*(undefined4 *)(levelEntry + 0x14),
                         (uint)levelFormat * bytesPerElement);
    _pthread_mutex_unlock(*(undefined4 *)(ctx + GLD_mutex));
  }
  return returnCode;
}

/* FUN_00031940 @ 0x31940 (1972 bytes) */
int FUN_00031940(ctxSaved, texture)
  int ctxSaved;
  int *texture;
{
  int gld_ensureTextureBackingSized2Result;
  uint loopIndex;
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
  
  iVar9 = texture[0xc];
  iVar7 = (uint)*(byte *)(texture + 0xe) * 0x24;
  bVar2 = *(byte *)(iVar9 + 0x5e);
  uVar21 = (uint)bVar2;
  uVar3 = *(ushort *)(iVar9 + 0x7c);
  local_5c = &local_e4;
  iVar30 = iVar9 + 0xa0 + uVar21 * 0x18;
  uVar23 = (uint)((*(uint *)(&DAT_001d9f48 + iVar7) & 7) == 4);
  iVar9 = gldPixelUnitBytes((uint)*(ushort *)(iVar30 + 0x10),(uint)*(ushort *)(iVar30 + 0x12));
  puVar16 = auStack_e8;
  iVar26 = iVar9 * (uint)*(ushort *)(iVar30 + 0xc);
  uVar22 = uVar23 ^ 1;
  iVar9 = (uint)*(byte *)(iVar30 + 10) * (iVar9 + iVar26) + *(int *)(iVar30 + 0x14);
  ((int (*)())gldTextureFormatLookup)((uint)*(byte *)(texture + 0xe),texture,local_5c,&local_f8,puVar16,puVar16,&local_ec,
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
  *(short *)((int)texture + 0x3e) = (short)(uVar23 >> (local_f8 & 0x3f));
  uVar18 = local_f8;
  gld_ensureTextureBackingSized2Result = gld_ensureTextureBackingSized2(ctxSaved,texture,iVar7 + 0x3a0,iVar11);
  uVar19 = 0;
  if (gld_ensureTextureBackingSized2Result == 0) {
    return 0;
  }
  iVar11 = texture[0xd];
  *(byte *)(iVar11 + 0x15) = (byte)(uVar17 << 2) | (byte)((uVar22 << (local_68 & 0x3f)) << 3) & 0x18
  ;
  piVar27 = (int *)*texture;
  if ((uVar3 & 1) != 0) {
    puVar15 = auStack_d8;
    piVar28 = piVar27 + 0x368;
    _glgConvertType((uint)*(ushort *)(iVar30 + 0x10),(uint)*(ushort *)(iVar30 + 0x12),auStack_dc,
                    puVar15,puVar16,uVar18,iVar11,0);
    local_ac = 0;
    local_b0 = 0;
    local_60 = piVar27 + 0x280;
    uVar14 = (uint)*(byte *)(texture + 0xe);
    local_e4 = iVar9;
    local_e0 = iVar26;
    local_d4 = piVar28;
    local_d0 = uVar6;
    local_b8 = uVar25;
    local_b4 = uVar24;
    iVar26 = ((int (*)())gldTextureFormatCodeMatchesType)((uint)*(ushort *)(iVar30 + 0x10),(uint)*(ushort *)(iVar30 + 0x12),uVar14);
    if (iVar26 == 0) {
      _glgProcessPixels(0,local_5c,uVar14,puVar15,puVar16,uVar18,iVar11,uVar19);
    }
    else if (uVar24 != 0) {
      loopIndex = 0;
      do {
        loopIndex = loopIndex + 1;
        _memcpy(piVar28,iVar9,local_ec * local_b8);
        piVar28 = (int *)((int)piVar28 + local_d0);
        iVar9 = iVar9 + local_e0;
      } while (loopIndex < local_b4);
    }
    if ((*(uint *)(ctxSaved + 0x24) & 0x82) != 0) {
      gldFlushDataCacheRange(ctxSaved,local_60 + 0x20,iVar7,puVar15,puVar16,uVar18,local_60,uVar19);
    }
  }
  if ((*(byte *)((int)texture + 0x39) & 3) == 0) goto LAB_00032098;
  if ((local_f4 < 3) || ((iVar7 = 1, 4 < local_f4 && (iVar7 = 2, local_f4 != 6)))) {
    iVar7 = 0;
  }
  piVar28 = piVar27 + 0x280;
  *(byte *)(texture[0xd] + 0x17) = bVar2;
  bVar1 = (int)(uVar25 << (local_f8 & 0x3f)) >> iVar7 < 0x2000;
  *(undefined1 *)(texture[0xd] + 0x34) = 1;
  *(undefined1 *)(texture[0xd] + 0x35) = 1;
  *(uint *)(*texture + 0x20) = (uint)bVar1 << 0x1f | *(uint *)(*texture + 0x20) & 0x7fffffff;
  *(uint *)(*texture + 0x20) = *(uint *)(*texture + 0x20) | 0x40000000;
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
  iVar9 = (uint)*(byte *)(texture + 0xe) * 0x24;
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
  *(ushort *)(texture[0xd] + 0x1c) = uVar3 | *(ushort *)(texture[0xd] + 0x1c);
  *(ushort *)(texture[0xd] + 0x28) = ~uVar3 & *(ushort *)(texture[0xd] + 0x28);
  *(byte *)((int)texture + 0x39) = *(byte *)((int)texture + 0x39) & 0xf8;
  *(ushort *)(texture + 9) = ~uVar3 & *(ushort *)(texture + 9);
  return 1;
}

/* gldTextureMakeResident @ 0x32100 (8252 bytes) */
int gldTextureMakeResident(ctx, texture, param_3, param_4, param_5, param_6)
  int ctx;
  int *texture;
  uint param_3;
  undefined4 param_4;
  undefined4 param_5;
  uint param_6;
{
  int gld_ensureTextureBackingSized2Result;
  int gld_setTextureNewTextureBackingResult;
  int gld_ensureTextureSurfaceBackingResult;
  int gld_setTextureAgpRefBackingResult;
  int gld_ensureTextureGlobalBackingResult;
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
  undefined4 r4AfterCall;
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
  ushort *texImages;
  uint uVar32;
  int iVar33;
  int *piVar34;
  int iVar35;
  uint uVar36;
  undefined *formatInfo;
  undefined1 *puVar38;
  byte xerSummaryOverflow = 0;
  bool bVar39;
  bool bVar40;
  byte crField1;
  byte calleeSavedCrField2;
  byte calleeSavedCrField3;
  byte calleeSavedCrField4;
  byte crField5;
  byte bVar41;
  byte bVar42;
  byte bVar43;
  undefined8 uVar44;
  int ctxSaved;
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
  
  texImages = (ushort *)texture[0xc];
  ctxSaved = ctx;
  iVar11 = ((int (*)())gldTextureHasNonPowerOfTwoSize)(texture,texture,param_3,param_4,param_5,param_6);
  if (iVar11 != 0) {
    iVar25 = texture[0xc];
    bVar41 = *(byte *)(iVar25 + 1);
    bVar42 = bVar41 & 0xf;
    *(byte *)(texture + 0x1b) = bVar42;
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
    *(byte *)(texture + 0x1b) = bVar41;
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
        *(undefined1 *)(texture + 0x11) = 1;
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
    *(undefined1 *)(texture + 0x11) = 0;
  }
LAB_000323a0:
  bVar41 = *(byte *)((int)texture + 0x39);
  *(byte *)((int)texture + 0x39) = bVar41 & 0x9f;
  if ((bVar41 & 0x1f) == 0) {
    ((int (*)())FUN_0002ee30)(ctxSaved,texture);
    return 1;
  }
  ((int (*)())FUN_0002fac0)(ctxSaved,texture);
  if (*(char *)(texture + 0xe) == '\0') {
    return 0;
  }
  bVar39 = *(char *)((int)texImages + 0x6f) == '\0';
  bVar41 = (*(char *)((int)texImages + 0x6f) != '\0') << 2 | bVar39 << 1 | xerSummaryOverflow & 1;
  if (!bVar39) {
    if (((unsigned char *)0x00001001) <= (undefined *)(1 << (*(byte *)(texImages + 0x32) & 0x3f))) {
      return 0;
    }
    if (((unsigned char *)0x00001001) <= (undefined *)(1 << (*(byte *)((int)texImages + 0x65) & 0x3f))) {
      return 0;
    }
    if (0x100 < (uint)(1 << (*(byte *)(texImages + 0x33) & 0x3f))) {
      return 0;
    }
  }
  uVar27 = *texImages;
  uVar22 = (uint)*(byte *)(texImages + 0x2f);
  if ((uVar27 & 0x400) == 0) {
    if ((uVar27 & 0x800) != 0) {
      gld_ensureTextureGlobalBackingResult = gld_ensureTextureGlobalBacking(ctxSaved,texture,*(undefined4 *)(texImages + 4));
      if (gld_ensureTextureGlobalBackingResult == 0) {
        return 0;
      }
      if (*(char *)((int)texImages + 0x6d) != '\0') {
        uVar22 = 1 << (*(uint *)(&DAT_001d9f48 + (uint)*(byte *)(texture + 0xe) * 0x24) & 7);
        *(short *)((int)texture + 0x3e) =
             (short)((uVar22 * ((uint)texImages[0x52] + (uint)*(byte *)(texImages + 0x55) * -2) + 0x1f &
                     0xffffffe0) / uVar22);
      }
      goto LAB_00032600;
    }
    if ((uVar27 & 0x2000) != 0) {
      iVar11 = ((int (*)())FUN_00031940)(ctxSaved,texture);
      if (iVar11 == 0) {
        return 0;
      }
      goto LAB_00032600;
    }
    uVar19 = 0x1a2114;
    uVar16 = r4AfterCall;
    if ((((((*(float *)(texture[0xc] + 4) == 0.0) ||
           (sVar5 = *(short *)(texture[0xc] + 0x1a), sVar5 == -0x7a41)) || (sVar5 == -0x7a42)) &&
         ((*(char *)(texImages + 0x36) == '\x01' && (*(char *)(texImages + 0x35) == '\x01')))) &&
        (bVar39)) && (*(int *)(texImages + uVar22 * 0xc + 0x5a) != 0)) {
      iVar11 = gldPixelUnitBytes((uint)texImages[uVar22 * 0xc + 0x58],(uint)texImages[uVar22 * 0xc + 0x59]);
      uVar27 = texImages[uVar22 * 0xc + 0x56];
      uVar28 = iVar11 * (int)(uint)uVar27;
      uVar32 = *(int *)(texImages + uVar22 * 0xc + 0x5a) +
               iVar11 * (uint)*(byte *)(texImages + uVar22 * 0xc + 0x55);
      if (*(char *)(texImages + 0x37) != '\0') {
        uVar32 = uVar32 + uVar28 * *(byte *)(texImages + uVar22 * 0xc + 0x55);
      }
      bVar4 = *(byte *)(texture + 0xe);
      bVar42 = ((uVar32 & 0x1f) != 0) << 2 | ((uVar32 & 0x1f) == 0) << 1;
      bVar41 = bVar42 | xerSummaryOverflow & 1;
      param_3 = (uint)bVar4;
      uVar44 = ((int (*)())gldTextureFormatCodeMatchesType)((uint)texImages[uVar22 * 0xc + 0x58],(uint)texImages[uVar22 * 0xc + 0x59],
                            param_3);
      uVar16 = (undefined4)uVar44;
      iVar25 = texture[0xc];
      if (*(short *)(iVar25 + 0x1a) == -0x7a41) {
        bVar39 = (undefined *)(uint)uVar27 < ((unsigned char *)0x00004001);
      }
      else {
        bVar39 = uVar28 <= *(uint *)(ctxSaved + 0x29d8);
      }
      if (((uint)bVar39 &
          (uint)((uVar28 & 0x1f) == 0) & bVar42 >> 1 & 1 & (uint)((ulonglong)uVar44 >> 0x20)) == 0)
      goto LAB_00034128;
      bVar41 = *(byte *)(iVar25 + 0x5e);
      uVar30 = (uint)bVar41;
      local_1a4 = 0;
      puVar17 = &local_218;
      puVar26 = &local_214;
      ((int (*)())gldTextureFormatLookup)((uint)bVar4,texture,aiStack_1c8,puVar17,&local_208,&local_208,&local_210,puVar26,
                   &local_20c);
      iVar33 = (uint)texImages[uVar22 * 0xc + 0x52] +
               (uint)*(byte *)(texImages + uVar22 * 0xc + 0x55) * -2;
      if (iVar33 < 1) {
        iVar33 = 1;
      }
      uVar22 = (uint)texImages[uVar22 * 0xc + 0x53] -
               (uint)*(byte *)(texImages + uVar22 * 0xc + 0x55) * (uint)*(byte *)(iVar25 + 0x6e);
      if ((int)uVar22 < 1) {
        uVar22 = 1;
      }
      uVar23 = *(uint *)(ctxSaved + 0x24);
      uVar20 = uVar23 & 0x82;
      iVar25 = uVar28 * (uVar22 - 1) + iVar11 * (iVar33 + 1U & 0xfffffffe);
      if (uVar20 == 0) {
        iVar29 = texture[0xc];
      }
      else {
        iVar29 = texture[0xc];
        if (((*(uint *)(iVar29 + 0x48) & 0x40) == 0) && (uVar22 != 0)) {
          uVar36 = 0;
          uVar16 = 0;
          uVar8 = uVar32;
          do {
            uVar36 = uVar36 + 1;
            gldFlushDataCacheRange(ctxSaved,uVar8,iVar11 * iVar33,puVar17,uVar20,uVar16,uVar23,puVar26);
            uVar8 = uVar8 + uVar28;
          } while (uVar36 < uVar22);
          iVar29 = texture[0xc];
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
        *(short *)((int)texture + 0x3e) = (short)(uVar28 >> (local_218 & 0x3f));
        gld_setTextureAgpRefBackingResult = gld_setTextureAgpRefBacking(ctxSaved,texture,uVar32,uVar20,iVar25);
        if (gld_setTextureAgpRefBackingResult == 0) {
          return 0;
        }
        uVar27 = (ushort)(-2 << (uVar30 & 0x1f)) | (ushort)(0xfffffffe >> 0x20 - (uVar30 & 0x1f));
        *(byte *)(texture[0xd] + 0x15) = (byte)local_20c & 3;
      }
      else {
        uVar23 = (iVar33 << (local_218 & 0x3f)) + 0x1fU & 0xffffffe0;
        *(short *)((int)texture + 0x3e) = (short)(uVar23 >> (local_218 & 0x3f));
        if ((*(byte *)((int)texture + 0x39) & 3) != 0) {
          if ((local_214 < 3) || ((iVar11 = 1, 4 < local_214 && (iVar11 = 2, local_214 != 6)))) {
            iVar11 = 0;
          }
          bVar39 = (iVar33 << (local_218 & 0x3f)) >> iVar11 < 0x2000;
          gld_setTextureNewTextureBackingResult = gld_setTextureNewTextureBacking(ctxSaved,texture,0x348,uVar23 * uVar22,uVar20,iVar25);
          if (gld_setTextureNewTextureBackingResult == 0) {
            return 0;
          }
          *(undefined1 *)(texture[0xd] + 0x15) = 0;
          piVar34 = (int *)*texture;
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
          iVar25 = (uint)*(byte *)(texture + 0xe) * 0x24;
          formatInfo = &DAT_001d9f34 + iVar25;
          if ((*(uint *)(&DAT_001d9f4c + iVar25) & 0x10000) == 0) {
            if ((*(uint *)(&DAT_001d9f48 + iVar25) & 8) == 0) {
              uVar8 = *(uint *)(&DAT_001d9f48 + iVar25) & 7;
              if (uVar8 == 1) {
                formatInfo = &DAT_001da00c;
              }
              else if (uVar8 < 2) {
                if (uVar8 == 0) {
                  formatInfo = &DAT_001d9fa0;
                }
                else {
LAB_00032a20:
                  formatInfo = &DAT_001da1bc;
                }
              }
              else {
                if (uVar8 == 2) goto LAB_00032b08;
                if (uVar8 != 3) goto LAB_00032a20;
                formatInfo = &DAT_001da36c;
              }
            }
            else {
LAB_00032b08:
              formatInfo = &DAT_001da054;
            }
          }
          _memcpy(piVar34 + 0x2a0,PTR_DAT_001e899c,0x23c);
          uVar9 = piVar34[0x306];
          uVar10 = piVar34[0x31c];
          piVar34[0x2ab] = 0;
          uVar8 = *(uint *)(formatInfo + 0x18) >> 5 & 0x1f;
          piVar34[0x306] = uVar8 | uVar9 & 0xffffffe0;
          uVar36 = (*(uint *)(formatInfo + 0x18) & 0x18) << 5;
          piVar34[0x306] = uVar36 | uVar8 | uVar9 & 0xfffffce0;
          uVar15 = (*(uint *)(formatInfo + 0x18) & 6) << 9;
          piVar34[0x306] = uVar15 | uVar36 | uVar8 | uVar9 & 0xfffff0e0;
          uVar7 = *(uint *)(formatInfo + 0x1c) >> 0x12 & 0x3000;
          piVar34[0x306] = uVar7 | uVar15 | uVar36 | uVar8 | uVar9 & 0xffffc0e0;
          piVar34[0x306] =
               *(uint *)(formatInfo + 0x1c) >> 0xe & 0xc000 |
               uVar7 | uVar15 | uVar36 | uVar8 | uVar9 & 0xfff000e0;
          uVar8 = *(uint *)(formatInfo + 0x1c) >> 7 & 0x1f;
          piVar34[0x31c] = uVar8 | uVar10 & 0xfffffe00;
          uVar36 = (*(uint *)(formatInfo + 0x1c) & 0x70) << 5;
          piVar34[0x31c] = uVar36 | uVar8 | uVar10 & 0xfffff000;
          uVar15 = (*(uint *)(formatInfo + 0x1c) & 0xe) << 0xb;
          piVar34[0x31c] = uVar15 | uVar36 | uVar8 | uVar10 & 0xffff8000;
          uVar7 = *(uint *)(formatInfo + 0x20) >> 0xe & 0x38000;
          piVar34[0x31c] = uVar7 | uVar15 | uVar36 | uVar8 | uVar10 & 0xfffc0000;
          piVar34[0x31c] =
               *(uint *)(formatInfo + 0x20) >> 8 & 0x1c0000 |
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
          iVar25 = (uint)*(byte *)(texture + 0xe) * 0x24;
          formatInfo = &DAT_001d9f34 + iVar25;
          if ((*(uint *)(&DAT_001d9f4c + iVar25) & 0x10000) == 0) {
            if ((*(uint *)(&DAT_001d9f48 + iVar25) & 8) == 0) {
              uVar32 = *(uint *)(&DAT_001d9f48 + iVar25) & 7;
              if (uVar32 == 1) {
                formatInfo = &DAT_001da00c;
              }
              else if (uVar32 < 2) {
                if (uVar32 == 0) {
                  formatInfo = &DAT_001d9fa0;
                }
                else {
LAB_00032bf4:
                  formatInfo = &DAT_001da1bc;
                }
              }
              else {
                if (uVar32 == 2) goto LAB_00032c54;
                if (uVar32 != 3) goto LAB_00032bf4;
                formatInfo = &DAT_001da36c;
              }
            }
            else {
LAB_00032c54:
              formatInfo = &DAT_001da054;
            }
          }
          puVar12 = (undefined4 *)
                    ((int (*)())FUN_00030420)(piVar34 + 0x32f,formatInfo,uVar28,uVar23,0,
                                 (iVar33 << (local_218 & 0x3f)) >> (*(uint *)(formatInfo + 0x14) & 7),
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
          *(uint *)(texture[0xd] + 0x18) = uVar23 * uVar22;
          *(byte *)(texture[0xd] + 0x14) = *(byte *)(texture[0xd] + 0x14) | 2;
          *piVar34 = (int)piVar13 - (int)piVar14 >> 2;
          piVar34[2] = ((int)puVar12 + (0x18 - (int)piVar14) >> 2) - piVar34[1];
        }
        uVar6 = (ushort)(1 << (uVar30 & 0x3f));
        uVar27 = ~uVar6;
        *(byte *)(texture[0xd] + 0x14) = *(byte *)(texture[0xd] + 0x14) | 1;
        *(ushort *)(texture[0xd] + 0x1c) = uVar6 | *(ushort *)(texture[0xd] + 0x1c);
        *(ushort *)(texture[0xd] + 0x28) = uVar27 & *(ushort *)(texture[0xd] + 0x28);
        *(byte *)(texture[0xd] + 0x17) = bVar41;
        *(undefined1 *)(texture[0xd] + 0x34) = 1;
        *(undefined1 *)(texture[0xd] + 0x35) = 1;
      }
      *(byte *)((int)texture + 0x39) = *(byte *)((int)texture + 0x39) & 0xf8;
      *(ushort *)(texture + 9) = uVar27 & *(ushort *)(texture + 9);
    }
    else {
LAB_00034128:
      if (*(char *)((int)texImages + 0x6d) == '\0') {
        iVar11 = ((int (*)())gldTextureHasNonPowerOfTwoSize)(texture,uVar16,param_3,param_4,uVar19,param_6);
        if (iVar11 == 0) {
          local_74 = texture[0xc];
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
          ((int (*)())gldTextureFormatLookup)((uint)*(byte *)(texture + 0xe),texture,local_64,&local_214,&local_208,
                       &local_204,&local_218,&local_210,&local_20c);
          iVar11 = (uint)*(byte *)(texture + 0xe) * 0x24;
          formatInfo = &DAT_001d9f34 + iVar11;
          uVar22 = *(uint *)(&DAT_001d9f48 + iVar11) & 7;
          if (uVar22 == 4) {
            iVar25 = 0;
            bVar39 = false;
            local_a4 = 0;
            local_c0 = 5;
            local_60 = (uint)(xerSummaryOverflow & 1 | 2) << 0x1c | (uint)(crField1 & 0xf) << 0x18 |
                       (uint)(calleeSavedCrField2 & 0xf) << 0x14 | (uint)(calleeSavedCrField3 & 0xf) << 0x10 |
                       (uint)(calleeSavedCrField4 & 0xf) << 0xc | (uint)(crField5 & 0xf) << 8 |
                       (uint)(bVar41 & 0xf) << 4 |
                       (uint)(byte)((uVar22 < 4) << 3 | (4 < uVar22) << 2 | (uVar22 == 4) << 1 |
                                   xerSummaryOverflow & 1);
LAB_00032f74:
            iVar11 = 0;
          }
          else {
            local_a4 = *(uint *)(&DAT_001d9f4c + iVar11) >> 0x1c & 3;
            bVar42 = (local_a4 != 0) << 2 | (local_a4 == 0) << 1 | xerSummaryOverflow & 1;
            bVar39 = local_a4 != 0;
            if (bVar39) {
              local_c0 = 5 - local_a4;
              local_60 = (uint)(xerSummaryOverflow & 1 | 4) << 0x1c | (uint)(crField1 & 0xf) << 0x18 |
                         (uint)(calleeSavedCrField2 & 0xf) << 0x14 | (uint)(calleeSavedCrField3 & 0xf) << 0x10 |
                         (uint)(calleeSavedCrField4 & 0xf) << 0xc | (uint)(crField5 & 0xf) << 8 |
                         (uint)(bVar41 & 0xf) << 4 | (uint)bVar42;
            }
            else {
              local_c0 = 5;
              local_60 = (uint)(xerSummaryOverflow & 1 | 4) << 0x1c | (uint)(crField1 & 0xf) << 0x18 |
                         (uint)(calleeSavedCrField2 & 0xf) << 0x14 | (uint)(calleeSavedCrField3 & 0xf) << 0x10 |
                         (uint)(calleeSavedCrField4 & 0xf) << 0xc | (uint)(crField5 & 0xf) << 8 |
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
                   (local_80 == local_7c) << 1 | xerSummaryOverflow & 1;
          bVar40 = (uint)((1 << (uVar32 & 0x3f)) << (local_214 & 0x3f)) <=
                   *(uint *)(ctxSaved + 0x29d8);
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
                       (local_80 == uVar20) << 1 | xerSummaryOverflow & 1;
            } while (local_80 >= uVar20);
            iVar21 = local_78 * iVar35;
            iVar33 = local_78 * iVar29;
          }
          uVar22 = 0;
          local_6c = (uint)(byte)(bVar40 << 2 | !bVar40 << 1 | xerSummaryOverflow & 1) << 0x1c |
                     (uint)(crField1 & 0xf) << 0x18 | (uint)(calleeSavedCrField2 & 0xf) << 0x14 |
                     (uint)(calleeSavedCrField3 & 0xf) << 0x10 | (uint)(calleeSavedCrField4 & 0xf) << 0xc |
                     (uint)(crField5 & 0xf) << 8 | (uint)(bVar41 & 0xf) << 4 | (uint)bVar42;
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
          gld_ensureTextureBackingSized2Result = gld_ensureTextureBackingSized2(ctxSaved,texture,
                                iVar21 + uVar22 * 4 + (uVar32 & 0xfffffff8) * 4,iVar33);
          if (gld_ensureTextureBackingSized2Result == 0) {
            return 0;
          }
          *(byte *)(texture[0xd] + 0x15) = (byte)((iVar25 << iVar11) << 3) & 0x18 | 4;
          local_84 = (int *)*texture;
          if ((*(byte *)((int)texture + 0x39) & 3) == 0) {
            local_8c = (int *)0x0;
            local_e8 = (int *)0x0;
          }
          else {
            *(char *)(texture[0xd] + 0x17) = (char)local_7c;
            uVar30 = 1 << (local_98 & 0x3f);
            *(char *)(texture[0xd] + 0x34) = (char)local_78;
            *(char *)(texture[0xd] + 0x35) = ((char)local_80 - (char)local_7c) + '\x01';
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
            formatInfo = PTR_DAT_001e899c;
            local_84[8] = (uint)bVar40 << 0x1f | uVar28 & 0x4fffffff | 0x40000000;
            local_8c = local_84 + 0x280;
            piVar14 = local_8c + local_84[1];
            local_e8 = piVar14 + 0x8f;
            _memcpy(piVar14,formatInfo,0x23c);
            iVar25 = (uint)*(byte *)(texture + 0xe) * 0x24;
            formatInfo = &DAT_001d9f34 + iVar25;
            if ((*(uint *)(&DAT_001d9f4c + iVar25) & 0x10000) == 0) {
              if ((*(uint *)(&DAT_001d9f48 + iVar25) & 8) == 0) {
                uVar28 = *(uint *)(&DAT_001d9f48 + iVar25) & 7;
                if (uVar28 == 1) {
                  formatInfo = &DAT_001da00c;
                }
                else if (uVar28 < 2) {
                  if (uVar28 == 0) {
                    formatInfo = &DAT_001d9fa0;
                  }
                  else {
LAB_000333f4:
                    formatInfo = &DAT_001da1bc;
                  }
                }
                else {
                  if (uVar28 == 2) goto LAB_000334dc;
                  if (uVar28 != 3) goto LAB_000333f4;
                  formatInfo = &DAT_001da36c;
                }
              }
              else {
LAB_000334dc:
                formatInfo = &DAT_001da054;
              }
            }
            uVar8 = piVar14[0x66];
            uVar36 = piVar14[0x7c];
            piVar14[0xb] = 0;
            uVar28 = *(uint *)(formatInfo + 0x18) >> 5 & 0x1f;
            piVar14[0x66] = uVar28 | uVar8 & 0xffffffe0;
            uVar30 = (*(uint *)(formatInfo + 0x18) & 0x18) << 5;
            piVar14[0x66] = uVar30 | uVar28 | uVar8 & 0xfffffce0;
            uVar20 = (*(uint *)(formatInfo + 0x18) & 6) << 9;
            piVar14[0x66] = uVar20 | uVar30 | uVar28 | uVar8 & 0xfffff0e0;
            uVar23 = *(uint *)(formatInfo + 0x1c) >> 0x12 & 0x3000;
            piVar14[0x66] = uVar23 | uVar20 | uVar30 | uVar28 | uVar8 & 0xffffc0e0;
            piVar14[0x66] =
                 *(uint *)(formatInfo + 0x1c) >> 0xe & 0xc000 |
                 uVar23 | uVar20 | uVar30 | uVar28 | uVar8 & 0xfff000e0;
            uVar28 = *(uint *)(formatInfo + 0x1c) >> 7 & 0x1f;
            piVar14[0x7c] = uVar28 | uVar36 & 0xfffffe00;
            uVar30 = (*(uint *)(formatInfo + 0x1c) & 0x70) << 5;
            piVar14[0x7c] = uVar30 | uVar28 | uVar36 & 0xfffff000;
            uVar20 = (*(uint *)(formatInfo + 0x1c) & 0xe) << 0xb;
            piVar14[0x7c] = uVar20 | uVar30 | uVar28 | uVar36 & 0xffff8000;
            uVar23 = *(uint *)(formatInfo + 0x20) >> 0xe & 0x38000;
            piVar14[0x7c] = uVar23 | uVar20 | uVar30 | uVar28 | uVar36 & 0xfffc0000;
            uVar8 = *(uint *)(formatInfo + 0x20) >> 8 & 0x1c0000;
            piVar14[0x7c] = uVar8 | uVar23 | uVar20 | uVar30 | uVar28 | uVar36 & 0xffc00000;
            piVar14[0x7c] =
                 (*(uint *)(formatInfo + 0x20) >> 0x19 & 1) << 0x16 |
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
                   xerSummaryOverflow & 1;
          if (local_78 != 0) {
            local_90 = 0;
            local_dc = texture;
            local_58 = iVar11 << 1;
            local_94 = 0;
            local_e4 = local_7c * 0x18;
            local_54 = (uint)(byte)(bVar39 << 2 | !bVar39 << 1 | xerSummaryOverflow & 1) << 0x1c |
                       (uint)(crField1 & 0xf) << 0x18 | (uint)(calleeSavedCrField2 & 0xf) << 0x14 |
                       (uint)(calleeSavedCrField3 & 0xf) << 0x10 | (uint)(calleeSavedCrField4 & 0xf) << 0xc |
                       (uint)(crField5 & 0xf) << 8 | (uint)(bVar41 & 0xf) << 4 | (uint)bVar42;
            local_c4 = (uVar22 + (uVar32 & 0xfffffff8)) * 4;
            local_e0 = local_7c << 5;
            local_68 = (uint)(xerSummaryOverflow & 1 | 2) << 0x1c | (uint)(crField1 & 0xf) << 0x18 |
                       (uint)(calleeSavedCrField2 & 0xf) << 0x14 | (uint)(calleeSavedCrField3 & 0xf) << 0x10 |
                       (uint)(calleeSavedCrField4 & 0xf) << 0xc | (uint)(crField5 & 0xf) << 8 |
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
                  bVar39 = 3 < *(byte *)(texture + 0xe) - 0xc;
                  local_ac = *piVar14 * local_78 + local_94 * (piVar14[1] - *piVar14) + local_c4 +
                             0xa00;
                  if (bVar39) {
                    local_b0 = 0;
                  }
                  local_b0 = (uint)!bVar39;
                  if ((*(byte *)((int)texture + 0x39) & 3) == 0) {
                    bVar42 = ((int)uVar28 < 0) << 3 | (0 < (int)uVar28) << 2 | (uVar28 == 0) << 1 |
                             xerSummaryOverflow & 1;
                    local_a8 = local_a8 & *(ushort *)(local_dc + 9);
                  }
                  else {
                    bVar42 = ((int)uVar28 < 0) << 3 | (0 < (int)uVar28) << 2 | (uVar28 == 0) << 1 |
                             xerSummaryOverflow & 1;
                    uVar8 = uVar28;
                    uVar20 = uVar32;
                    if ((((uVar32 != local_a4 + 3) && (local_a4 <= uVar32)) &&
                        (bVar42 = ((int)uVar28 < 0) << 3 | (0 < (int)uVar28) << 2 |
                                  (uVar28 == 0) << 1 | xerSummaryOverflow & 1, uVar28 != 0)) &&
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
                        local_e8 = (int *)((int (*)())FUN_00030420)(local_e8,formatInfo,iVar11,iVar29,uVar36,
                                                       (iVar35 << (local_214 & 0x3f)) >>
                                                       (*(uint *)(formatInfo + 0x14) & 7),iVar33);
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
                    iVar25 = gldPixelUnitBytes((uint)*(ushort *)(iVar33 + 0x10),uVar20);
                    uVar23 = (uint)*(ushort *)(iVar33 + 0xc);
                    bVar39 = uVar20 != 0;
                    bVar4 = xerSummaryOverflow & 1;
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
                    bVar3 = xerSummaryOverflow & 1;
                    uVar23 = local_b0;
                    local_154 = uVar8;
                    _glgConvertType((uint)*(ushort *)(iVar33 + 0x10),
                                    (uint)*(ushort *)(iVar33 + 0x12),auStack_150,puVar18,local_74,
                                    local_b0,local_158,uVar8);
                    local_144 = iVar11;
                    if (!bVar2) {
                      local_144 = local_12c << 2;
                    }
                    local_148 = local_ac + *texture;
                    local_130 = 0x7ffff;
                    uVar27 = *(short *)(iVar33 + 0x10) + 0xe6fa;
                    bVar43 = (uVar27 < 4) << 3 | (4 < uVar27) << 2 | (uVar27 == 4) << 1 |
                             xerSummaryOverflow & 1;
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
                                              (local_90 == 0) << 1 | xerSummaryOverflow & 1) << 0x1c |
                                 (uint)(crField1 & 0xf) << 0x18 | (uint)bVar42 << 0x14 |
                                 (uint)(byte)((uVar20 == 0) << 2 | bVar39 << 1 | bVar4) << 0x10 |
                                 (uint)(byte)(bVar40 << 3 | bVar1 << 2 | bVar2 << 1 | bVar3) << 0xc
                                 | (uint)(crField5 & 0xf) << 8 | (uint)(bVar41 & 0xf) << 4 |
                                 (uint)(bVar43 & 0xf);
                    }
                    uVar27 = *(ushort *)(iVar33 + 0x10);
                    uVar6 = *(ushort *)(iVar33 + 0x12);
                    uVar15 = (uint)*(byte *)(texture + 0xe);
                    iVar25 = 1 << (uVar28 + uVar22 + uVar32 + local_214 & 0x3f);
                    uVar20 = ((int (*)())gldTextureFormatCodeMatchesType)((uint)uVar27,(uint)uVar6,uVar15);
                    iVar11 = gldPixelUnitBytes((uint)uVar27,(uint)uVar6);
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
                          puVar18 = (undefined1 *)(uint)*(byte *)(texture + 0xe);
                          local_148 = local_b4;
                          if (puVar18 == (undefined1 *)((int)((unsigned char *)0xc) + 3)) {
                            bVar39 = uVar23 == 0x1908;
                            bVar41 = (uVar23 < 0x1908) << 3 | (0x1908 < uVar23) << 2 | bVar39 << 1 |
                                     xerSummaryOverflow & 1;
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
                        uVar20 = ((int (*)())gldCompressedImageBytes)((uint)*(byte *)(texture + 0xe),local_12c,1,1);
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
                    uVar20 = *(uint *)(ctxSaved + 0x24) & 0x82;
                    if (uVar20 != 0) {
                      gldFlushDataCacheRange(ctxSaved,local_ac + *texture,
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
              iVar25 = iVar11 + texture[0xd];
              local_d8 = local_d8 + 2;
              local_e0 = local_e0 + 0x1a0;
              local_e4 = local_e4 + 0x168;
              *(ushort *)(iVar25 + 0x1c) = (ushort)local_a8 | *(ushort *)(iVar25 + 0x1c);
              iVar11 = iVar11 + texture[0xd];
              *(ushort *)(iVar11 + 0x28) = uVar27 & *(ushort *)(iVar11 + 0x28);
              *(ushort *)(local_dc + 9) = uVar27 & *(ushort *)(local_dc + 9);
              local_dc = (int *)((int)local_dc + 2);
            } while (local_94 < local_78);
            if (!(bool)((byte)(local_68 >> 0x1d) & 1)) {
              _free(local_90);
            }
          }
          bVar41 = *(byte *)((int)texture + 0x39);
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
            bVar41 = *(byte *)((int)texture + 0x39);
          }
          *(byte *)((int)texture + 0x39) = bVar41 & 0xf8;
          goto LAB_00033ff0;
        }
        if (*(char *)(texture + 0x11) != '\0') {
          return 0;
        }
      }
      iVar11 = ((int (*)())FUN_00031940)(ctxSaved,texture);
      if (iVar11 == 0) {
        return 0;
      }
    }
  }
  else {
    uVar27 = texImages[6];
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
    gld_ensureTextureSurfaceBackingResult = gld_ensureTextureSurfaceBacking(ctxSaved,texture,*(undefined4 *)(texImages + 4),uVar16,
                          (uint)*(byte *)(texImages + 0x36));
    if (gld_ensureTextureSurfaceBackingResult == 0) {
      return 0;
    }
    if (*(char *)((int)texImages + 0x6d) == '\0') {
      uVar22 = (uint)texImages[0x52];
      if ((0x20 < uVar22) || (0x20 < texImages[0x53])) goto LAB_00032600;
    }
    else {
      uVar22 = (uint)texImages[0x52];
    }
    uVar28 = 1 << (*(uint *)(&DAT_001d9f48 + (uint)*(byte *)(texture + 0xe) * 0x24) & 7);
    *(short *)((int)texture + 0x3e) =
         (short)((uVar28 * (uVar22 + (uint)*(byte *)(texImages + 0x55) * -2) + 0xff & 0xffffff00) /
                uVar28);
LAB_00032600:
    *(byte *)((int)texture + 0x39) = *(byte *)((int)texture + 0x39) & 0xf8;
  }
LAB_00033ff0:
  if (*(char *)((int)texImages + 0x6d) != '\0') {
    if (0x1000 < texImages[0x52]) {
      if (0x1000 < texImages[0x53]) {
        return 0;
      }
      texture[0x32] = texture[0x32] & 0xff3fffffU | 0x400000;
      uVar27 = texImages[0x52];
      uVar22 = uVar27 >> 1 & 0x7e00;
      sVar5 = (short)uVar22;
      *(short *)(texture + 0x35) = sVar5;
      *(ushort *)((int)texture + 0xd2) = uVar27 - sVar5;
      *(short *)(texture + 0x34) = sVar5 + 2;
      texture[0x33] = uVar22 << 2 | texture[0x33] & 3U;
      goto LAB_00034100;
    }
    if (0x1000 < texImages[0x53]) {
      texture[0x32] = texture[0x32] & 0xff3fffffU | 0x800000;
      uVar27 = texImages[0x53];
      uVar22 = uVar27 >> 1 & 0x7fc0;
      sVar5 = (short)uVar22;
      *(short *)(texture + 0x35) = sVar5;
      *(ushort *)((int)texture + 0xd2) = uVar27 - sVar5;
      *(short *)(texture + 0x34) = sVar5 + 1;
      if ((*(ushort *)texture[0xc] & 0x400) == 0) {
        texture[0x33] =
             ((*(ushort *)((int)texture + 0x3e) * uVar22 <<
              (*(uint *)(&DAT_001d9f48 + (uint)*(byte *)(texture + 0xe) * 0x24) & 7)) >> 5) << 2 |
             texture[0x33] & 3U;
      }
      else {
        texture[0x33] = uVar22 << 2 | texture[0x33] & 3U;
      }
      goto LAB_00034100;
    }
  }
  texture[0x32] = texture[0x32] & 0xff3fffff;
LAB_00034100:
  ((int (*)())FUN_0002ddf0)(ctxSaved,texture);
  return 1;
}

/* FUN_000341a0 @ 0x341a0 (92 bytes) */
int FUN_000341a0(glContext, param_2, param_3, param_4, param_5, param_6)
  int glContext;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  int gldTextureMakeResidentResult;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(glContext + 4);
  gldTextureMakeResidentResult = ((int (*)())gldTextureMakeResident)(uVar2,param_2,param_3,param_4,param_5,param_6);
  if (gldTextureMakeResidentResult == 0) {
    _gldDeleteTexture(uVar2,param_2);
  }
  return gldTextureMakeResidentResult != 0;
}

/* glGenerateMipmap_impl @ 0x34200 (4472 bytes) */
int glGenerateMipmap_impl(ctx, texture, face, passThroughArg4, passThroughArg5)
  int ctx;
  int *texture;
  int face;
  undefined4 passThroughArg4;
  undefined4 passThroughArg5;
{
  int vap_vte_cntl;
  float sliceCoord;
  float sliceStep;
  int storageRecordB;
  int mappingOffset;
  int levelMappingRec;
  int pitchAlign;
  int sliceCount;
  int levelCountPlus1;
  int faceArg;
  int ga_point_size;
  int sc_scissor1;
  int rb3d_ropcntl;
  int rb3d_color_channel_mask;
  int tx_format2;
  int tx_format1;
  int tx_format0;
  int tx_filter0;
  int rs_ip_0;
  int rs_count;
  int us_out_fmt_3;
  int us_out_fmt_2;
  int us_out_fmt_1;
  int us_out_fmt_0;
  int gb_ps3_enable;
  int tx_enable;
  int ga_color_control;
  int ga_poly_mode;
  int zb_cntl;
  int vap_prog_stream_cntl_ext_0_ptr;
  int vap_prog_stream_cntl_0_ptr;
  int vap_out_vtx_fmt_1;
  int vap_out_vtx_fmt_0;
  int gb_enable;
  int rb3d_dither_ctl;
  int su_cull_mode;
  int vap_clip_cntl;
  int vap_cntl_status;
  int zb_zstencilcntl;
  int zb_bw_cntl;
  int sc_hyperz_en;
  int gb_aa_config;
  int gb_mspos1;
  int sc_screendoor;
  int sc_edgerule;
  bool noMapping;
  float texelBiasX;
  float texelBiasY;
  float halfWidthF;
  float halfHeightFB;
  float halfWidthFB;
  float halfHeightF;
  byte lastLevel;
  ushort uVar9;
  uint a6;
  float texelBiasXPlusOne;
  undefined *stateTemplate;
  uint uVar12;
  uint uVar13;
  uint halfDepth;
  int drawWords;
  int iVar16;
  int levelRecord;
  undefined4 *packet;
  undefined4 r4AfterCall;
  int *drawCursor;
  undefined4 uVar20;
  int *levelOffsetTable;
  undefined4 staleArgR8;
  uint baseWidth;
  uint *lastHeader;
  uint uVar24;
  int iVar25;
  int iVar26;
  uint uVar27;
  uint baseHeight;
  int storageRecord;
  int iVar30;
  int *passOffsetTable;
  uint uVar32;
  uint nextLevel;
  int a0;
  int *packetState;
  uint baseLevel;
  ushort *levelTable;
  uint levelCount;
  int *tailCursor;
  uint halfHeight;
  uint halfWidth;
  uint depthLevelCount;
  
  faceArg = face;
  _pthread_mutex_lock(*(undefined4 *)(ctx + GLD_mutex));
  levelTable = (ushort *)texture[0xc];
  baseLevel = (uint)*(byte *)(levelTable + 0x2f);
  lastLevel = *(byte *)((int)levelTable + 0x5f);
  if ((*(uint *)(levelTable + 0x24) & 0x8000) != 0) {
    lastLevel = *(byte *)((int)levelTable + 0x6b);
  }
  levelCount = lastLevel - baseLevel;
  faceArg = ((int (*)())gldTextureHasNonPowerOfTwoSize)(texture,r4AfterCall,faceArg,passThroughArg4,passThroughArg5,staleArgR8);
  if (faceArg != 0) {
LAB_000342e0:
    _pthread_mutex_unlock(*(undefined4 *)(ctx + GLD_mutex));
    return 0;
  }
  if ((levelCount == 0) || (*(char *)((int)levelTable + 0x6d) != '\0')) goto LAB_00035340;
  uVar20 = 1;
  nextLevel = baseLevel + 1;
  faceArg = face;
  uVar12 = baseLevel;
  levelRecord = ((int (*)())gldTextureFormatEntryForLevel)(ctx,texture,face,baseLevel,1);
  if (((levelRecord == 0) || ((*(uint *)(levelRecord + 0x18) & 0x10000) == 0)) ||
     (((*(byte *)((int)texture + 0x39) & 7) != 0 &&
      (faceArg = ((int (*)())gldTextureMakeResident)(ctx,texture,faceArg,uVar12,uVar20,staleArgR8), faceArg == 0))))
  goto LAB_000342e0;
  baseWidth = *(byte *)(levelTable + 0x30) - baseLevel;
  if ((int)baseWidth < 0) {
    baseWidth = 0;
  }
  baseWidth = 1 << (baseWidth & 0x3f);
  uVar27 = *(byte *)((int)levelTable + 0x61) - baseLevel;
  if ((int)uVar27 < 0) {
    uVar27 = 0;
  }
  baseHeight = 1 << (uVar27 & 0x3f);
  uVar27 = *(byte *)(levelTable + 0x31) - baseLevel;
  depthLevelCount = uVar27;
  if ((int)uVar27 < 0) {
    depthLevelCount = 0;
  }
  halfWidth = (int)baseWidth >> 1;
  if ((int)halfWidth < 1) {
    halfWidth = 1;
  }
  halfHeight = (int)baseHeight >> 1;
  if ((int)halfHeight < 1) {
    halfHeight = 1;
  }
  halfDepth = depthLevelCount - 1;
  if ((int)halfDepth < 0) {
    halfDepth = 0;
  }
  halfDepth = 1 << (halfDepth & 0x3f);
  if (*(char *)((int)levelTable + 0x6f) == '\0') {
    uVar13 = levelCount;
    if (*(char *)(levelTable + 0x36) != '\x06') {
      drawWords = levelCount * 0x1e;
      levelCountPlus1 = levelCount + 1;
      goto LAB_0003440c;
    }
    levelCountPlus1 = levelCount * 2;
    uVar32 = levelCount * 0x10000;
    drawWords = levelCount * 0x2c + -0x16;
    uVar24 = levelCount;
  }
  else {
    if ((int)levelCount < 1) {
      uVar13 = 0;
      drawWords = 0;
      levelCountPlus1 = 1;
    }
    else {
      uVar24 = 0;
      uVar13 = 0;
      uVar32 = levelCount;
      do {
        sliceCount = (int)halfDepth >> (uVar24 & 0x3f);
        if (sliceCount < 1) {
          sliceCount = 1;
        }
        uVar13 = uVar13 + sliceCount;
        uVar24 = uVar24 + 1;
        uVar32 = uVar32 - 1;
      } while (uVar32 != 0);
      drawWords = uVar13 * 0x28;
      levelCountPlus1 = uVar13 + 1;
    }
LAB_0003440c:
    drawWords = drawWords + -0x12;
    uVar32 = 0x10000;
    uVar24 = 1;
  }
  a0 = ctx + GLD_commandStream;
  a6 = face << 0x10;
  uVar20 = (**(code **)(ctx + GLD_streamAllocate))
                     (a0,drawWords + levelCountPlus1 + 0x340,depthLevelCount,uVar12,uVar20,staleArgR8,a6);
  *(undefined4 *)(ctx + GLD_streamCurrent) = uVar20;
  packet = (undefined4 *)((int (*)())FUN_00030840)(ctx,uVar20,texture);
  stateTemplate = PTR_DAT_001e88d0;
  lastHeader = *(uint **)(ctx + GLD_lastHeader);
  tailCursor = packet + 4 + uVar13;
  *lastHeader = (int)packet - (int)lastHeader >> 2 | *lastHeader;
  *(undefined4 **)(ctx + GLD_lastHeader) = packet;
  packet[2] = levelCount | a6 | nextLevel * 0x100;
  packet[3] = uVar13 | uVar32;
  *packet = 0x37000000;
  packetState = tailCursor + uVar24;
  _memcpy(packetState,stateTemplate,0x2f4);
  drawCursor = packetState + 0xbd;
  if (*(char *)((int)levelTable + 0x6f) != '\0') {
    packetState[0x26] = 3;
    packetState[0x22] = 0;
    packetState[0x27] = 0x82d;
    packetState[0x21] = (int)((unsigned char *)0x00001002U);
    packetState[0x98] = packetState[0x98] & 0xfffc0fffU | 0x2000;
    packetState[0x25] = 0x825;
    packetState[0x92] = packetState[0x92] & 0xffffff80U | 3;
    packetState[0x2a] = 0x26020001;
    packetState[0x28] = 5;
    packetState[0x2c] = -0x57704f8;
    packetState[0x29] = 0x854;
    packetState[0x2b] = 0x878;
  }
  uVar12 = packetState[0xa2];
  packetState[0xa2] = uVar12 & 0xffff81ff | 0x3400;
  if ((int)uVar27 < 1) {
    iVar16 = 0;
  }
  else {
    iVar16 = 2;
  }
  packetState[0xa2] = iVar16 << 0xf | uVar12 & 0xfffe01ff | 0x3400;
  uVar24 = packetState[0x8a];
  uVar13 = packetState[0xa8];
  packetState[0xa4] = packetState[0xa4] & 0xffffe007U | 0x1f00;
  packetState[0xa6] =
       levelCount * 0x4000000 & 0x3c000000 |
       (depthLevelCount & 0xf) << 0x16 |
       (baseHeight - 1) * 0x800 & 0x3ff800 | baseWidth - 1 & 0x7ff | packetState[0xa6] & 0x40000000U;
  levelCount = *(uint *)(levelRecord + 0x1c) >> 7 & 0x1f;
  packetState[0xa8] = levelCount | uVar13 & 0xffffffe0;
  uVar12 = (*(uint *)(levelRecord + 0x1c) & 0xe) << 0xb;
  packetState[0xa8] = uVar12 | levelCount | uVar13 & 0xffff8fe0;
  uVar27 = *(uint *)(levelRecord + 0x20) >> 0xe & 0x38000;
  packetState[0xa8] = uVar27 | uVar12 | levelCount | uVar13 & 0xfffc0fe0;
  uVar32 = *(uint *)(levelRecord + 0x20) >> 8 & 0x1c0000;
  packetState[0xa8] = uVar32 | uVar27 | uVar12 | levelCount | uVar13 & 0xffe00fe0;
  packetState[0xa8] =
       (*(uint *)(levelRecord + 0x1c) & 0x70) << 5 |
       uVar32 | uVar27 | uVar12 | levelCount | uVar13 & 0xffe001e0;
  levelCount = (*(uint *)(levelRecord + 0x18) & 0x18) << 5;
  packetState[0x8a] = levelCount | uVar24 & 0xfffffcff;
  uVar12 = (*(uint *)(levelRecord + 0x18) & 6) << 9;
  packetState[0x8a] = uVar12 | levelCount | uVar24 & 0xfffff0ff;
  uVar27 = *(uint *)(levelRecord + 0x1c) >> 0x12 & 0x3000;
  packetState[0x8a] = uVar27 | uVar12 | levelCount | uVar24 & 0xffffc0ff;
  uVar32 = *(uint *)(levelRecord + 0x1c) >> 0xe & 0xc000;
  packetState[0x8a] = uVar32 | uVar27 | uVar12 | levelCount | uVar24 & 0xffff00ff;
  packetState[0x8a] =
       *(uint *)(levelRecord + 0x18) >> 5 & 0x1f |
       uVar32 | uVar27 | uVar12 | levelCount | uVar24 & 0xffff00e0;
  uVar9 = levelTable[1];
  if (((uVar9 != 0x1908) && (uVar9 != 0x1906)) && (uVar9 != 0x190a)) {
    packetState[0x56] = packetState[0x56] & 0xfffe3fffU | 0x18000;
  }
  if ((texture[0xd] == 0) || ((*(byte *)(texture[0xd] + 0x15) & 0x18) == 0)) {
    pitchAlign = 0x20;
  }
  else {
    pitchAlign = 0x20 / (1 << (*(uint *)(&DAT_001d9f4c + (uint)*(byte *)(texture + 0xe) * 0x24) >> 0x1c
                          & 3));
  }
  pitchAlign = pitchAlign >> (*(uint *)(levelRecord + 0x14) & 7);
  if ((*levelTable & 0x400) == 0) {
    levelMappingRec = *texture + 0x40 + (face * 0xd + nextLevel) * 0x20;
  }
  else {
    levelMappingRec = 0;
  }
  noMapping = levelMappingRec == 0;
  levelOffsetTable = packet + 5;
  packet[4] = (int)packetState + (0x268 - (int)packet) >> 2;
  if (noMapping) {
    packetState[0x9a] = nextLevel | a6;
  }
  else {
    packetState[0x9a] = *(int *)(levelMappingRec + 8);
  }
  passOffsetTable = tailCursor + 1;
  *tailCursor = (int)packetState + (0x280 - (int)packet) >> 2;
  if (noMapping) {
    packetState[0xa0] = baseLevel | a6;
  }
  else {
    packetState[0xa0] = *(int *)((face * 0xd + baseLevel) * 0x20 + *texture + 0x48);
    storageRecord = texture[0xd];
    if ((storageRecord == 0) || ((*(byte *)(storageRecord + 0x15) & 4) == 0)) {
LAB_0003482c:
      iVar30 = 0;
    }
    else {
      baseLevel = nextLevel - *(byte *)(texture[0xc] + 0x69);
      if ((*(byte *)(storageRecord + 0x15) & 0x18) == 0) {
        iVar25 = 1;
        iVar30 = 0x100;
      }
      else {
        iVar25 = 1 << (*(uint *)(&DAT_001d9f4c + (uint)*(byte *)(texture + 0xe) * 0x24) >> 0x1c & 3)
        ;
        iVar30 = 0x20 / iVar25 << 3;
      }
      if ((*(int *)(*texture + 0xc) >> (baseLevel & 0x3f) < iVar30) ||
         (iVar30 = 1, (int)(uint)*(ushort *)(*texture + 0x16) >> (baseLevel & 0x3f) < iVar25 << 3))
      goto LAB_0003482c;
    }
    if (storageRecord == 0) {
      baseLevel = 0;
    }
    else {
      baseLevel = (*(byte *)(storageRecord + 0x15) & 0x18) << 0xe;
    }
    packetState[0x9c] =
         baseLevel | (halfWidth + pitchAlign) - 1 & -pitchAlign & 0x3ffe | iVar30 << 0x10 |
         (*(uint *)(levelRecord + 0x18) & 0x3c00) << 0xb;
  }
  packetState[0xb3] = halfWidth - 1 & 0x1fff | (halfHeight - 1) * 0x2000 & 0x3ffe000;
  if ((*(uint *)(levelRecord + 0x20) & 0x400000) != 0) {
    packetState[0x1e] = 0;
  }
  mappingOffset = (nextLevel + face * 0xd) * 0x20;
  texelBiasX = (float)(0.0078125 /
                 ((double)CONCAT44(0x43300000,baseWidth ^ 0x80000000) - 4503601774854144.0));
  texelBiasY = (float)(0.0078125 /
                 ((double)CONCAT44(0x43300000,baseHeight ^ 0x80000000) - 4503601774854144.0));
  texelBiasXPlusOne = texelBiasX + 1.0;
  while( true ) {
    mappingOffset = mappingOffset + 0x20;
    if (*(char *)((int)levelTable + 0x6f) == '\0') {
      tailCursor = drawCursor + 0xc;
      drawCursor[2] = (int)GH_F2U((float)((texelBiasY + 1.0)));
      *drawCursor = 0x31080;
      drawCursor[1] = (int)GH_F2U((float)(texelBiasX));
      drawCursor[3] = (int)GH_F2U((float)(texelBiasXPlusOne));
      drawCursor[5] = (int)((unsigned char *)0x00001087U);
      drawCursor[4] = (int)GH_F2U((float)(texelBiasY));
      halfWidthF = (float)((double)CONCAT44(0x43300000,halfWidth ^ 0x80000000) - 4503601774854144.0);
      halfHeightF = (float)((double)CONCAT44(0x43300000,halfHeight ^ 0x80000000) - 4503601774854144.0);
      drawCursor[7] = -0x3ffccb00;
      drawCursor[8] = 0x10031;
      drawCursor[9] = (int)GH_F2U((float)(((halfWidthF + 0.0) * 0.5)));
      drawCursor[10] = (int)GH_F2U((float)(((halfHeightF + 0.0) * 0.5)));
      drawCursor[0xb] = 0;
      drawCursor[6] = (int)(halfWidthF * 6.0) << 0x10 | (int)(halfHeightF * 6.0);
    }
    else {
      sliceStep = (float)(1.0 / ((double)CONCAT44(0x43300000,halfDepth ^ 0x80000000) - 4503601774854144.0))
      ;
      sliceCoord = sliceStep * 0.5 +
              (float)((1.0 / ((double)CONCAT44(0x43300000,1 << (depthLevelCount & 0x3f) ^ 0x80000000) -
                             4503601774854144.0)) * 0.0078125);
      tailCursor = drawCursor;
      if (0 < (int)halfDepth) {
        baseLevel = 0;
        halfHeightFB = (float)((double)CONCAT44(0x43300000,halfHeight ^ 0x80000000) - 4503601774854144.0);
        halfWidthFB = (float)((double)CONCAT44(0x43300000,halfWidth ^ 0x80000000) - 4503601774854144.0);
        do {
          while( true ) {
            baseLevel = baseLevel + 1;
            drawCursor[6] = (int)GH_F2U((float)(sliceCoord));
            drawCursor[0xb] = (int)GH_F2U((float)(sliceCoord));
            drawCursor[0x10] = (int)GH_F2U((float)(sliceCoord));
            drawCursor[0x15] = (int)GH_F2U((float)(sliceCoord));
            tailCursor = drawCursor + 0x16;
            *drawCursor = -0x3febcb00;
            drawCursor[1] = 0x4003d;
            drawCursor[2] = 0;
            drawCursor[3] = 0;
            sliceCoord = sliceCoord + sliceStep;
            drawCursor[4] = (int)GH_F2U((float)(texelBiasX));
            drawCursor[5] = (int)GH_F2U((float)(texelBiasY));
            drawCursor[7] = (int)GH_F2U((float)(halfWidthFB));
            drawCursor[8] = 0;
            drawCursor[9] = (int)GH_F2U((float)(texelBiasXPlusOne));
            drawCursor[10] = (int)GH_F2U((float)(texelBiasY));
            drawCursor[0xc] = (int)GH_F2U((float)(halfWidthFB));
            drawCursor[0xd] = (int)GH_F2U((float)(halfHeightFB));
            drawCursor[0xe] = (int)GH_F2U((float)(texelBiasXPlusOne));
            drawCursor[0xf] = (int)GH_F2U((float)((texelBiasY + 1.0)));
            drawCursor[0x11] = 0;
            drawCursor[0x12] = (int)GH_F2U((float)(halfHeightFB));
            drawCursor[0x13] = (int)GH_F2U((float)(texelBiasX));
            drawCursor[0x14] = (int)GH_F2U((float)((texelBiasY + 1.0)));
            if ((int)halfDepth <= (int)baseLevel) break;
            drawCursor[0x16] = (int)((unsigned char *)0x00001393U);
            drawCursor[0x17] = 10;
            drawCursor[0x18] = (int)((unsigned char *)0x0000138aU);
            *levelOffsetTable = (int)drawCursor + (100 - (int)packet) >> 2;
            levelOffsetTable = levelOffsetTable + 1;
            if (noMapping) {
              drawCursor = drawCursor + 0x1a;
            }
            else {
              drawCursor[0x19] = baseLevel * *(int *)(levelMappingRec + 0x14) + *(int *)(levelMappingRec + 8);
              drawCursor = drawCursor + 0x1a;
            }
          }
          drawCursor = tailCursor;
        } while (halfDepth != baseLevel);
      }
    }
    if ((int)(uint)lastLevel <= (int)nextLevel) break;
    tailCursor[5] = 0;
    drawCursor = tailCursor + 6;
    *tailCursor = (int)((unsigned char *)0x00001393U);
    tailCursor[1] = 10;
    tailCursor[2] = 0x5c8;
    tailCursor[3] = 0x20000;
    tailCursor[4] = (int)((unsigned char *)0x00001040U);
    if (*(char *)(levelTable + 0x36) == '\x06') {
      tailCursor[6] = (int)((unsigned char *)0x00001150U);
      *passOffsetTable = (int)tailCursor + (0x1c - (int)packet) >> 2;
      passOffsetTable = passOffsetTable + 1;
      if (noMapping) {
        tailCursor[7] = nextLevel | a6;
      }
      else {
        tailCursor[7] = *(int *)(levelMappingRec + 8);
      }
      tailCursor[8] = (int)((unsigned char *)0x00001120U);
      drawCursor = tailCursor + 10;
      tailCursor[9] = (halfHeight - 1) * 0x800 & 0x3ff800 |
                   halfWidth - 1 & 0x7ff | packetState[0xa6] & 0x40000000U;
    }
    depthLevelCount = depthLevelCount - 1;
    nextLevel = nextLevel + 1;
    if ((int)depthLevelCount < 0) {
      depthLevelCount = 0;
    }
    halfWidth = (int)halfWidth >> 1;
    if ((int)halfWidth < 1) {
      halfWidth = 1;
    }
    halfHeight = (int)halfHeight >> 1;
    if ((int)halfHeight < 1) {
      halfHeight = 1;
    }
    halfDepth = (int)halfDepth >> 1;
    if ((int)halfDepth < 1) {
      halfDepth = 1;
    }
    levelMappingRec = 0;
    if ((*levelTable & 0x400) == 0) {
      levelMappingRec = mappingOffset + *texture + 0x40;
    }
    noMapping = levelMappingRec == 0;
    *drawCursor = (int)((unsigned char *)0x0000138aU);
    *levelOffsetTable = (int)drawCursor + (4 - (int)packet) >> 2;
    levelOffsetTable = levelOffsetTable + 1;
    if (noMapping) {
      drawCursor[1] = a6 | nextLevel;
    }
    else {
      drawCursor[1] = *(int *)(levelMappingRec + 8);
    }
    drawCursor[2] = (int)((unsigned char *)0x0000138eU);
    if (!noMapping) {
      storageRecordB = texture[0xd];
      if ((storageRecordB == 0) || ((*(byte *)(storageRecordB + 0x15) & 4) == 0)) {
LAB_00034df0:
        iVar25 = 0;
      }
      else {
        baseLevel = nextLevel - *(byte *)(texture[0xc] + 0x69);
        if ((*(byte *)(storageRecordB + 0x15) & 0x18) == 0) {
          iVar26 = 1;
          iVar25 = 0x100;
        }
        else {
          iVar26 = 1 << (*(uint *)(&DAT_001d9f4c + (uint)*(byte *)(texture + 0xe) * 0x24) >> 0x1c &
                        3);
          iVar25 = 0x20 / iVar26 << 3;
        }
        if ((*(int *)(*texture + 0xc) >> (baseLevel & 0x3f) < iVar25) ||
           (iVar25 = 1, (int)(uint)*(ushort *)(*texture + 0x16) >> (baseLevel & 0x3f) < iVar26 << 3))
        goto LAB_00034df0;
      }
      if (storageRecordB == 0) {
        baseLevel = 0;
      }
      else {
        baseLevel = (*(byte *)(storageRecordB + 0x15) & 0x18) << 0xe;
      }
      drawCursor[3] = baseLevel | (pitchAlign + halfWidth) - 1 & -pitchAlign & 0x3ffe | iVar25 << 0x10 |
                   (*(uint *)(levelRecord + 0x18) & 0x3c00) << 0xb;
    }
    drawCursor = drawCursor + 4;
  }
  packet[1] = (int)tailCursor - (int)packet >> 2;
  lastHeader = *(uint **)(ctx + GLD_lastHeader);
  *lastHeader = (int)tailCursor - (int)lastHeader >> 2 | *lastHeader;
  *(int **)(ctx + GLD_lastHeader) = tailCursor;
  tailCursor[1] = 0;
  *tailCursor = 0x33000000;
  tailCursor[2] = (int)((unsigned char *)0x00001393U);
  tailCursor[3] = 10;
  tailCursor[4] = (int)((unsigned char *)0x000013c6U);
  tailCursor[5] = 3;
  tailCursor[6] = 0x5c8;
  tailCursor[7] = 0x20000;
  tailCursor[8] = (int)((unsigned char *)0x000010eaU);
  sc_edgerule = *(int *)(ctx + GLD_sc_edgerule);
  tailCursor[10] = (int)((unsigned char *)0x000010faU);
  tailCursor[9] = sc_edgerule;
  sc_screendoor = *(int *)(ctx + GLD_sc_screendoor);
  tailCursor[0xc] = -0x3ffff000;
  tailCursor[0xe] = 0x11004;
  tailCursor[0xb] = sc_screendoor;
  tailCursor[0xf] = *(int *)(ctx + GLD_gb_mspos0);
  gb_mspos1 = *(int *)(ctx + GLD_gb_mspos1);
  tailCursor[0x11] = (int)((unsigned char *)0x00001008U);
  tailCursor[0x10] = gb_mspos1;
  gb_aa_config = *(int *)(ctx + GLD_gb_aa_config);
  tailCursor[0x13] = (int)((unsigned char *)0x000010e9U);
  tailCursor[0x12] = gb_aa_config;
  sc_hyperz_en = *(int *)(ctx + GLD_sc_hyperz_en);
  tailCursor[0x15] = (int)((unsigned char *)0x000013c7U);
  tailCursor[0x14] = sc_hyperz_en;
  zb_bw_cntl = *(int *)(ctx + GLD_zb_bw_cntl);
  tailCursor[0x17] = (int)((unsigned char *)0x000013c1U);
  tailCursor[0x16] = zb_bw_cntl;
  zb_zstencilcntl = *(int *)(ctx + GLD_zb_zstencilcntl);
  tailCursor[0x19] = 0x850;
  tailCursor[0x18] = zb_zstencilcntl;
  vap_cntl_status = *(int *)(ctx + GLD_vap_cntl_status);
  tailCursor[0x1b] = 0x887;
  tailCursor[0x1a] = vap_cntl_status;
  vap_clip_cntl = *(int *)(ctx + GLD_vap_clip_cntl);
  tailCursor[0xbd] = 0x82c;
  tailCursor[0x1c] = vap_clip_cntl;
  vap_vte_cntl = *(int *)(GLD_vap_vte_cntl + ctx);
  tailCursor[0x1d] = (int)((unsigned char *)0x000010aeU);
  tailCursor[0xbe] = vap_vte_cntl;
  su_cull_mode = *(int *)(ctx + GLD_su_cull_mode);
  tailCursor[0x1f] = (int)((unsigned char *)0x00001394U);
  tailCursor[0x1e] = su_cull_mode;
  rb3d_dither_ctl = *(int *)(ctx + GLD_rb3d_dither_ctl);
  tailCursor[0x21] = (int)((unsigned char *)0x00001380U);
  tailCursor[0x23] = (int)((unsigned char *)0x00001002U);
  tailCursor[0x22] = 0;
  tailCursor[0x20] = rb3d_dither_ctl;
  tailCursor[0x24] = *(int *)(ctx + GLD_gb_enable);
  gb_enable = *(int *)(ctx + GLD_gb_enable);
  tailCursor[0x25] = 0x824;
  tailCursor[0x24] = gb_enable;
  vap_out_vtx_fmt_0 = *(int *)(ctx + GLD_vap_out_vtx_fmt_0);
  tailCursor[0x27] = 0x825;
  tailCursor[0x26] = vap_out_vtx_fmt_0;
  vap_out_vtx_fmt_1 = *(int *)(ctx + GLD_vap_out_vtx_fmt_1);
  tailCursor[0x29] = 0x82d;
  tailCursor[0x28] = vap_out_vtx_fmt_1;
  iVar16 = *(int *)(0x000026c8 + ctx + GLD_connect);
  tailCursor[0x2b] = 0x854;
  tailCursor[0x2a] = iVar16;
  vap_prog_stream_cntl_0_ptr = **(int **)(ctx + GLD_vap_prog_stream_cntl_0_ptr);
  tailCursor[0x2d] = 0x878;
  tailCursor[0x2c] = vap_prog_stream_cntl_0_ptr;
  vap_prog_stream_cntl_ext_0_ptr = **(int **)(ctx + GLD_vap_prog_stream_cntl_ext_0_ptr);
  tailCursor[0x2f] = (int)((unsigned char *)0x000013c0U);
  tailCursor[0x2e] = vap_prog_stream_cntl_ext_0_ptr;
  zb_cntl = *(int *)(ctx + GLD_zb_cntl);
  tailCursor[0x31] = (int)((unsigned char *)0x000012f0U);
  tailCursor[0x30] = zb_cntl;
  baseLevel = *(uint *)(ctx + GLD_fg_fog_blend);
  tailCursor[0x32] = baseLevel;
  if ((*(uint *)(&DAT_001d9f4c + (uint)(byte)((unsigned char *)GLD_colorFormatIndex)[ctx] * 0x24) & 0x8000) == 0) {
    tailCursor[0x32] = baseLevel & 0xfffffffe;
  }
  tailCursor[0x33] = (int)((unsigned char *)0x000012f5U);
  baseLevel = *(uint *)(ctx + GLD_fg_alpha_func);
  tailCursor[0x34] = baseLevel;
  if ((*(uint *)(&DAT_001d9f4c + (uint)(byte)((unsigned char *)GLD_colorFormatIndex)[ctx] * 0x24) & 0x8000) == 0) {
    tailCursor[0x34] = baseLevel & 0xfffff7ff;
  }
  tailCursor[0x35] = (int)((unsigned char *)0x000010a2U);
  ga_poly_mode = *(int *)(ctx + GLD_ga_poly_mode);
  tailCursor[0x37] = (int)((unsigned char *)0x00001381U);
  tailCursor[0x36] = ga_poly_mode;
  baseLevel = *(uint *)(ctx + GLD_rb3d_blendcntl);
  tailCursor[0x38] = baseLevel;
  if ((*(uint *)(&DAT_001d9f4c + (uint)(byte)((unsigned char *)GLD_colorFormatIndex)[ctx] * 0x24) & 0x4000) == 0) {
    tailCursor[0x38] = baseLevel & 0xfffffffc;
  }
  tailCursor[0x39] = (int)((unsigned char *)0x0000109eU);
  iVar16 = *(int *)(ctx + 0x1d6c);
  tailCursor[0x3b] = (int)((unsigned char *)0x00001096U);
  tailCursor[0x3a] = iVar16;
  ga_color_control = *(int *)(ctx + GLD_ga_color_control);
  tailCursor[0x3d] = (int)((unsigned char *)0x00001041U);
  tailCursor[0x3a] = ga_color_control;
  tx_enable = *(int *)(ctx + GLD_tx_enable);
  tailCursor[0x3f] = (int)((unsigned char *)0x00001046U);
  tailCursor[0x3e] = tx_enable;
  gb_ps3_enable = *(int *)(ctx + GLD_gb_ps3_enable);
  tailCursor[0x41] = (int)((unsigned char *)0x00001094U);
  tailCursor[0x59] = (int)((unsigned char *)0x00001095U);
  tailCursor[0x5b] = -0x3fddf000;
  tailCursor[0x7f] = (int)((unsigned char *)0x00001180U);
  tailCursor[0x43] = (int)((unsigned char *)0x00001095U);
  tailCursor[0x45] = (int)((unsigned char *)0x00001095U);
  tailCursor[0x47] = (int)((unsigned char *)0x00001095U);
  tailCursor[0x40] = gb_ps3_enable;
  tailCursor[0x49] = (int)((unsigned char *)0x00001095U);
  tailCursor[0x4b] = (int)((unsigned char *)0x00001095U);
  tailCursor[0x4d] = (int)((unsigned char *)0x00001095U);
  tailCursor[0x4f] = (int)((unsigned char *)0x00001095U);
  tailCursor[0x51] = (int)((unsigned char *)0x00001095U);
  tailCursor[0x53] = (int)((unsigned char *)0x00001095U);
  tailCursor[0x55] = (int)((unsigned char *)0x00001095U);
  tailCursor[0x57] = (int)((unsigned char *)0x00001095U);
  tailCursor[0x42] = 0;
  tailCursor[0x80] = 2;
  tailCursor[0x81] = (int)((unsigned char *)0x00001189U);
  tailCursor[0x83] = (int)((unsigned char *)0x00001181U);
  tailCursor[0x85] = (int)((unsigned char *)0x0000118dU);
  tailCursor[0x87] = (int)((unsigned char *)0x0000118eU);
  tailCursor[0x89] = (int)((unsigned char *)0x0000118cU);
  tailCursor[0x8b] = (int)((unsigned char *)0x000011a9U);
  us_out_fmt_0 = *(int *)(ctx + GLD_us_out_fmt_0);
  tailCursor[0x8d] = (int)((unsigned char *)0x000011aaU);
  tailCursor[0x8c] = us_out_fmt_0;
  us_out_fmt_1 = *(int *)(ctx + GLD_us_out_fmt_1);
  tailCursor[0x8f] = (int)((unsigned char *)0x000011abU);
  tailCursor[0x8e] = us_out_fmt_1;
  us_out_fmt_2 = *(int *)(ctx + GLD_us_out_fmt_2);
  tailCursor[0x91] = (int)((unsigned char *)0x000011acU);
  tailCursor[0x90] = us_out_fmt_2;
  us_out_fmt_3 = *(int *)(ctx + GLD_us_out_fmt_3);
  tailCursor[0x93] = (int)((unsigned char *)0x000010c0U);
  tailCursor[0x92] = us_out_fmt_3;
  rs_count = *(int *)(ctx + GLD_rs_count);
  tailCursor[0x95] = (int)((unsigned char *)0x000010c1U);
  tailCursor[0x97] = (int)((unsigned char *)0x000010c8U);
  tailCursor[0x99] = (int)((unsigned char *)0x0000101dU);
  tailCursor[0x94] = rs_count;
  rs_ip_0 = *(int *)(ctx + GLD_rs_ip_0);
  tailCursor[0x9b] = (int)((unsigned char *)0x0000138aU);
  tailCursor[0x9d] = (int)((unsigned char *)0x0000138eU);
  tailCursor[0xa2] = 0;
  tailCursor[0x9f] = (int)((unsigned char *)0x00001040U);
  tailCursor[0x9c] = 0;
  tailCursor[0x9e] = 0;
  tailCursor[0xa0] = 0;
  tailCursor[0x9a] = rs_ip_0;
  tailCursor[0xa1] = (int)((unsigned char *)0x00001150U);
  tailCursor[0xa3] = (int)((unsigned char *)0x00001100U);
  tx_filter0 = *(int *)(ctx + GLD_tx_filter0);
  tailCursor[0xa5] = (int)((unsigned char *)0x00001110U);
  tailCursor[0xa4] = tx_filter0;
  tailCursor[0xa6] = *(int *)(ctx + GLD_tx_filter1);
  tailCursor[0xa7] = (int)((unsigned char *)0x00001120U);
  tx_format0 = *(int *)(ctx + GLD_tx_format0);
  tailCursor[0xa9] = (int)((unsigned char *)0x00001130U);
  tailCursor[0xa8] = tx_format0;
  tx_format1 = *(int *)(ctx + GLD_tx_format1);
  tailCursor[0xab] = (int)((unsigned char *)0x00001140U);
  tailCursor[0xaa] = tx_format1;
  tx_format2 = *(int *)(ctx + GLD_tx_format2);
  tailCursor[0xad] = (int)((unsigned char *)0x000010f4U);
  tailCursor[0xae] = 0xaaaa;
  tailCursor[0xaf] = (int)((unsigned char *)0x00001383U);
  tailCursor[0xac] = tx_format2;
  rb3d_color_channel_mask = *(int *)(ctx + GLD_rb3d_color_channel_mask);
  tailCursor[0xb1] = (int)((unsigned char *)0x00001386U);
  tailCursor[0xb0] = rb3d_color_channel_mask;
  rb3d_ropcntl = *(int *)(ctx + GLD_rb3d_ropcntl);
  tailCursor[0xb3] = 0x110f8;
  tailCursor[0xb2] = rb3d_ropcntl;
  tailCursor[0xb4] = *(int *)(ctx + GLD_sc_scissor0);
  sc_scissor1 = *(int *)(ctx + GLD_sc_scissor1);
  tailCursor[0xb6] = (int)((unsigned char *)0x00001087U);
  tailCursor[0xb5] = sc_scissor1;
  ga_point_size = *(int *)(ctx + GLD_ga_point_size);
  tailCursor[0xb8] = 0x31080;
  tailCursor[0xb7] = ga_point_size;
  tailCursor[0xb9] = *(int *)(ctx + GLD_ga_point_s0);
  tailCursor[0xba] = *(int *)(ctx + GLD_ga_point_t0);
  tailCursor[0xbb] = *(int *)(ctx + GLD_ga_point_s1);
  tailCursor[0xbc] = *(int *)(ctx + GLD_ga_point_t1);
  FUN_0004c100(tailCursor + 2,a0);
  uVar20 = ((int (*)())FUN_000308c0)(ctx,tailCursor + 0xbf);
  *(undefined4 *)(ctx + GLD_streamCurrent) = uVar20;
  (**(code **)(ctx + GLD_streamSetCurrent))(a0,uVar20);
LAB_00035340:
  _pthread_mutex_unlock(*(undefined4 *)(ctx + GLD_mutex));
  return 1;
}

/* FUN_000353a0 @ 0x353a0 (5656 bytes) */
int FUN_000353a0(ctx, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11)
  int ctx;
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
  uint sc_scissor1;
  uint ga_point_size;
  uint rb3d_ropcntl;
  uint rb3d_color_channel_mask;
  uint tx_format2;
  uint tx_format1;
  uint tx_format0;
  uint tx_filter0;
  uint rs_ip_0;
  uint rs_count;
  uint us_out_fmt_3;
  uint us_out_fmt_2;
  uint us_out_fmt_1;
  uint us_out_fmt_0;
  uint gb_ps3_enable;
  uint tx_enable;
  uint ga_color_control;
  uint rb3d_blendcntl;
  uint ga_poly_mode;
  uint fg_alpha_func;
  uint fg_fog_blend;
  uint zb_cntl;
  uint vap_out_vtx_fmt_1;
  uint vap_out_vtx_fmt_0;
  uint gb_enable;
  uint rb3d_dither_ctl;
  uint su_cull_mode;
  uint vap_vte_cntl;
  uint vap_clip_cntl;
  uint zb_zstencilcntl;
  uint zb_bw_cntl;
  uint sc_hyperz_en;
  uint gb_aa_config;
  uint gb_mspos1;
  uint sc_screendoor;
  uint sc_edgerule;
  int boundFramebuffer;
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
  _pthread_mutex_lock(*(undefined4 *)(ctx + 0xc));
  iVar47 = param_2[0xc];
  uVar39 = 0;
  iVar35 = param_3;
  uVar49 = param_4;
  iVar32 = ((int (*)())gldTextureFormatEntryForLevel)(ctx,param_2,param_3,param_4,0);
  iVar53 = ctx + 0x240;
  if ((iVar32 == 0) || ((*(uint *)(iVar32 + 0x18) & 0x10000) == 0)) {
LAB_00035740:
    _pthread_mutex_unlock(*(undefined4 *)(ctx + 0xc));
    return 0;
  }
  iVar33 = gld_textureVariantClass((uint)*(ushort *)(((unsigned char *)0x00002db8) + *(int *)(ctx + 0x10)),
                        *(undefined4 *)(ctx + 0x154));
  bVar12 = *(short *)(iVar47 + 2) != 0x1902;
  if ((!bVar12) &&
     (((*(int *)(ctx + 0x150) == 0 &&
       (iVar34 = FUN_0001a010(ctx,iVar33,iVar35,uVar49,uVar39,uVar50,iVar34), iVar34 != 0)) ||
      ((*(uint *)(ctx + 0x154) & 0x30000) == 0)))) goto LAB_00035740;
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
  fVar2 = (float)((double)CONCAT44(0x43300000,*(uint *)(ctx + 0x15c) ^ 0x80000000) -
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
  fVar2 = (float)((double)CONCAT44(0x43300000,*(uint *)(ctx + 0x160) ^ 0x80000000) -
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
    _pthread_mutex_unlock(*(undefined4 *)(ctx + 0xc));
    return 1;
  }
  if (((*(byte *)((int)param_2 + 0x39) & 7) != 0) &&
     (iVar34 = ((int (*)())gldTextureMakeResident)(ctx,param_2,iVar35,uVar49,uVar39,uVar50), iVar34 == 0))
  goto LAB_00035740;
  boundFramebuffer = *(int *)(ctx + 0x150);
  if (boundFramebuffer == 0) {
    iVar35 = FUN_0001a010(ctx,iVar33,iVar35,uVar49,uVar39,uVar50,0);
    if (iVar35 == 0) {
      boundFramebuffer = *(int *)(ctx + 0x150);
    }
    else {
      gld_emitSurfaceCopyPacket(ctx,0,iVar33,0,(int)fVar15,(int)(fVar17 + fVar5),(int)(fVar6 - fVar15),
                   (int)((fVar8 + fVar5) - (fVar17 + fVar5)));
      boundFramebuffer = *(int *)(ctx + 0x150);
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
  if (((unsigned char *)0x00002b7c)[ctx] != '\0') {
    fVar5 = (float)((double)CONCAT44(0x43300000,*(uint *)(ctx + 0x160) ^ 0x80000000) -
                   DOUBLE_001aa1e0) - fVar5;
    fVar2 = FLOAT_001aa114;
  }
  if (boundFramebuffer == 0) {
    uVar9 = *(ushort *)(ctx + 0x11e);
    uVar10 = *(ushort *)(ctx + 0x122);
  }
  else {
    uVar9 = *(ushort *)(ctx + 0x15e);
    uVar10 = *(ushort *)(ctx + 0x162);
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
    uVar38 = (uint)(int)fVar23;
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
    uVar38 = (uint)(int)fVar13;
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
  uVar39 = (**(code **)(ctx + 0x2998))(iVar53,iVar35 + iVar37 + iVar34);
  *(undefined4 *)(ctx + 0x298c) = uVar39;
  iVar34 = ((int (*)())FUN_00030840)(ctx,uVar39,param_2);
  puVar30 = *(uint **)(ctx + 0x1d8);
  iVar37 = iVar34 + iVar51;
  *puVar30 = iVar37 - (int)puVar30 >> 2 | *puVar30;
  *(int *)(ctx + 0x1d8) = iVar37;
  *(undefined4 *)(iVar34 + iVar51) = 0x32000000;
  *(int *)(iVar37 + 8) = iVar35;
  if (bVar12) {
    *(int *)(iVar37 + 0xc) = iVar33;
  }
  else {
    if (((*(uint *)(ctx + 0x154) & 0x2000) == 0) ||
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
            puVar30[6] = (uint)GH_F2U((float)((fVar19 * (fVar24 - fVar8))));
            puVar30[8] = (uint)GH_F2U((float)((fVar19 * (fVar3 - fVar8))));
            puVar30[9] = (uint)((unsigned char *)0x00001087U);
            fVar3 = (float)((double)CONCAT44(0x43300000,uVar29) - dVar25);
            puVar30[7] = (uint)GH_F2U((float)((fVar18 * (fVar22 - fVar3))));
            puVar30[5] = (uint)GH_F2U((float)((fVar18 * (fVar2 - fVar3))));
            puVar30[0xb] = 0xc0033500;
            puVar30[0xc] = 0x10031;
            puVar30[0xd] = (uint)GH_F2U((float)(fVar17));
            puVar30[0xe] = (uint)GH_F2U((float)(fVar6));
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
  puVar31 = *(uint **)(ctx + 0x1d8);
  *puVar31 = (int)puVar30 - (int)puVar31 >> 2 | *puVar31;
  *(uint **)(ctx + 0x1d8) = puVar30;
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
  puVar30[8] = (uint)((unsigned char *)0x000010eaU);
  sc_edgerule = *(uint *)(ctx + 0x1cfc);
  puVar30[10] = (uint)((unsigned char *)0x000010faU);
  puVar30[9] = sc_edgerule;
  sc_screendoor = *(uint *)(ctx + 0x1da0);
  puVar30[0xc] = 0xc0001000;
  puVar30[0xe] = 0x11004;
  puVar30[0xb] = sc_screendoor;
  puVar30[0xf] = *(uint *)(ctx + 0x1ca8);
  gb_mspos1 = *(uint *)(ctx + 0x1cac);
  puVar30[0x11] = (uint)((unsigned char *)0x00001008U);
  puVar30[0x10] = gb_mspos1;
  gb_aa_config = *(uint *)(ctx + 0x1ca0);
  puVar30[0x13] = (uint)((unsigned char *)0x000010e9U);
  puVar30[0x12] = gb_aa_config;
  sc_hyperz_en = *(uint *)(ctx + 0x1d20);
  puVar30[0x15] = (uint)((unsigned char *)0x000013c7U);
  puVar30[0x14] = sc_hyperz_en;
  zb_bw_cntl = *(uint *)(ctx + 0x1cf0);
  puVar30[0x17] = (uint)((unsigned char *)0x000013c1U);
  puVar30[0x16] = zb_bw_cntl;
  zb_zstencilcntl = *(uint *)(ctx + 0x1ce4);
  puVar30[0x19] = 0x850;
  puVar30[0x18] = zb_zstencilcntl;
  puVar30[0x1a] = *(uint *)(ctx + 0x1dc0);
  puVar30[0x1b] = 0x887;
  vap_clip_cntl = *(uint *)(ctx + 0x1db4);
  puVar30[0xbd] = 0x82c;
  puVar30[0x1c] = vap_clip_cntl;
  vap_vte_cntl = *(uint *)(0x00001dc4 + ctx);
  puVar30[0x1d] = (uint)((unsigned char *)0x000010aeU);
  puVar30[0xbe] = vap_vte_cntl;
  su_cull_mode = *(uint *)(ctx + 0x1d70);
  puVar30[0x1f] = (uint)((unsigned char *)0x00001394U);
  puVar30[0x1e] = su_cull_mode;
  rb3d_dither_ctl = *(uint *)(ctx + 0x1d30);
  puVar30[0x21] = (uint)((unsigned char *)0x00001380U);
  puVar30[0x23] = (uint)((unsigned char *)0x00001002U);
  puVar30[0x22] = 0;
  puVar30[0x20] = rb3d_dither_ctl;
  puVar30[0x24] = *(uint *)(ctx + 0x1d90);
  gb_enable = *(uint *)(ctx + 0x1d90);
  puVar30[0x25] = 0x824;
  puVar30[0x24] = gb_enable;
  vap_out_vtx_fmt_0 = *(uint *)(ctx + 0x1ddc);
  puVar30[0x27] = 0x825;
  puVar30[0x26] = vap_out_vtx_fmt_0;
  vap_out_vtx_fmt_1 = *(uint *)(ctx + 0x1de0);
  puVar30[0x29] = 0x82d;
  puVar30[0x28] = vap_out_vtx_fmt_1;
  uVar49 = *(uint *)(0x000026c8 + ctx + 4);
  puVar30[0x2b] = 0x854;
  puVar30[0x2a] = uVar49;
  uVar49 = **(uint **)(ctx + 0x2680);
  puVar30[0x2d] = 0x878;
  puVar30[0x2c] = uVar49;
  uVar49 = **(uint **)(ctx + 0x2684);
  puVar30[0x2f] = (uint)((unsigned char *)0x000013c0U);
  puVar30[0x2e] = uVar49;
  zb_cntl = *(uint *)(ctx + 0x1ce0);
  puVar30[0x31] = (uint)((unsigned char *)0x000012f0U);
  puVar30[0x30] = zb_cntl;
  fg_fog_blend = *(uint *)(ctx + 0x1d2c);
  puVar30[0x32] = fg_fog_blend;
  if ((*(uint *)(&DAT_001d9f4c + (uint)(byte)((unsigned char *)0x00002b7f)[ctx] * 0x24) & 0x8000) == 0) {
    puVar30[0x32] = fg_fog_blend & 0xfffffffe;
  }
  puVar30[0x33] = (uint)((unsigned char *)0x000012f5U);
  fg_alpha_func = *(uint *)(ctx + 0x1c8c);
  puVar30[0x34] = fg_alpha_func;
  if ((*(uint *)(&DAT_001d9f4c + (uint)(byte)((unsigned char *)0x00002b7f)[ctx] * 0x24) & 0x8000) == 0) {
    puVar30[0x34] = fg_alpha_func & 0xfffff7ff;
  }
  puVar30[0x35] = (uint)((unsigned char *)0x000010a2U);
  ga_poly_mode = *(uint *)(ctx + 0x1d7c);
  puVar30[0x37] = (uint)((unsigned char *)0x00001381U);
  puVar30[0x36] = ga_poly_mode;
  rb3d_blendcntl = *(uint *)(ctx + 0x1cc0);
  puVar30[0x38] = rb3d_blendcntl;
  if ((*(uint *)(&DAT_001d9f4c + (uint)(byte)((unsigned char *)0x00002b7f)[ctx] * 0x24) & 0x4000) == 0) {
    puVar30[0x38] = rb3d_blendcntl & 0xfffffffc;
  }
  puVar30[0x39] = (uint)((unsigned char *)0x0000109eU);
  uVar43 = 0xc0221000;
  uVar42 = 0xaaaa;
  uVar41 = 0x110f8;
  uVar39 = 0x31080;
  uVar49 = *(uint *)(ctx + 0x1d6c);
  puVar30[0x3b] = (uint)((unsigned char *)0x00001096U);
  puVar30[0x3a] = uVar49;
  ga_color_control = *(uint *)(ctx + 0x1df8);
  puVar30[0x3d] = (uint)((unsigned char *)0x00001041U);
  puVar30[0x3a] = ga_color_control;
  tx_enable = *(uint *)(ctx + 0x29f0);
  puVar30[0x3f] = (uint)((unsigned char *)0x00001046U);
  puVar30[0x3e] = tx_enable;
  gb_ps3_enable = *(uint *)(ctx + 0x1dfc);
  puVar30[0x41] = (uint)((unsigned char *)0x00001094U);
  puVar30[0x59] = (uint)((unsigned char *)0x00001095U);
  puVar30[0x43] = (uint)((unsigned char *)0x00001095U);
  puVar30[0x7f] = (uint)((unsigned char *)0x00001180U);
  puVar30[0x45] = (uint)((unsigned char *)0x00001095U);
  puVar30[0x47] = (uint)((unsigned char *)0x00001095U);
  puVar30[0x49] = (uint)((unsigned char *)0x00001095U);
  puVar30[0x40] = gb_ps3_enable;
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
  us_out_fmt_0 = *(uint *)(ctx + 0x257c);
  puVar30[0x8d] = (uint)((unsigned char *)0x000011aaU);
  puVar30[0x8c] = us_out_fmt_0;
  us_out_fmt_1 = *(uint *)(ctx + 0x2580);
  puVar30[0x8f] = (uint)((unsigned char *)0x000011abU);
  puVar30[0x8e] = us_out_fmt_1;
  us_out_fmt_2 = *(uint *)(ctx + 0x2584);
  puVar30[0x91] = (uint)((unsigned char *)0x000011acU);
  puVar30[0x90] = us_out_fmt_2;
  us_out_fmt_3 = *(uint *)(ctx + 0x2588);
  puVar30[0x93] = (uint)((unsigned char *)0x000010c0U);
  puVar30[0x92] = us_out_fmt_3;
  rs_count = *(uint *)(ctx + 0x216c);
  puVar30[0x95] = (uint)((unsigned char *)0x000010c1U);
  puVar30[0x97] = (uint)((unsigned char *)0x000010c8U);
  puVar30[0x99] = (uint)((unsigned char *)0x0000101dU);
  puVar30[0x94] = rs_count;
  rs_ip_0 = *(uint *)(ctx + 0x2128);
  puVar30[0x9b] = (uint)((unsigned char *)0x0000138aU);
  puVar30[0x9d] = (uint)((unsigned char *)0x0000138eU);
  puVar30[0xa2] = 0;
  puVar30[0x9f] = (uint)((unsigned char *)0x00001040U);
  puVar30[0x9c] = 0;
  puVar30[0x9e] = 0;
  puVar30[0xa0] = 0;
  puVar30[0x9a] = rs_ip_0;
  puVar30[0xa1] = (uint)((unsigned char *)0x00001150U);
  puVar30[0xa3] = (uint)((unsigned char *)0x00001100U);
  tx_filter0 = *(uint *)(ctx + 0x1f1c);
  puVar30[0xa5] = (uint)((unsigned char *)0x00001110U);
  puVar30[0xa4] = tx_filter0;
  puVar30[0xa6] = *(uint *)(ctx + 0x1f5c);
  puVar30[0xa7] = (uint)((unsigned char *)0x00001120U);
  tx_format0 = *(uint *)(ctx + 0x1f9c);
  puVar30[0xa9] = (uint)((unsigned char *)0x00001130U);
  puVar30[0xa8] = tx_format0;
  tx_format1 = *(uint *)(ctx + 0x1fdc);
  puVar30[0xab] = (uint)((unsigned char *)0x00001140U);
  puVar30[0xaa] = tx_format1;
  tx_format2 = *(uint *)(ctx + 0x201c);
  puVar30[0xad] = (uint)((unsigned char *)0x000010f4U);
  puVar30[0xae] = 0xaaaa;
  puVar30[0xaf] = (uint)((unsigned char *)0x00001383U);
  puVar30[0xac] = tx_format2;
  rb3d_color_channel_mask = *(uint *)(ctx + 0x1d34);
  puVar30[0xb1] = (uint)((unsigned char *)0x00001386U);
  puVar30[0xb0] = rb3d_color_channel_mask;
  rb3d_ropcntl = *(uint *)(ctx + 0x1d38);
  puVar30[0xb3] = 0x110f8;
  puVar30[0xb2] = rb3d_ropcntl;
  puVar30[0xb4] = *(uint *)(ctx + 0x1d98);
  sc_scissor1 = *(uint *)(ctx + 0x1d50);
  puVar30[0xb6] = (uint)((unsigned char *)0x00001087U);
  puVar30[0xb5] = sc_scissor1;
  ga_point_size = *(uint *)(ctx + 0x1f0c);
  puVar30[0xb8] = 0x31080;
  puVar30[0xb7] = ga_point_size;
  puVar30[0xb9] = *(uint *)(ctx + 0x1efc);
  puVar30[0xba] = *(uint *)(ctx + 0x1f04);
  puVar30[0xbb] = *(uint *)(ctx + 0x1f00);
  puVar30[0xbc] = *(uint *)(ctx + 0x1f08);
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
  uVar36 = ((int (*)())FUN_000308c0)(ctx,puVar31);
  *(undefined4 *)(ctx + 0x298c) = uVar36;
  (**(code **)(ctx + 0x299c))(iVar53,uVar36);
  _pthread_mutex_unlock(*(undefined4 *)(ctx + 0xc));
  if ((((*(uint *)(ctx + 0x24) & 0x82) != 0) && (param_2[0xd] != 0)) &&
     (*(char *)(param_2[0xd] + 0x16) == '\x06')) {
    iVar34 = iVar47 + 0xa0 + (uint)*(byte *)(iVar47 + 0x5e) * 0x18;
    uVar9 = *(ushort *)(iVar34 + 0xc);
    iVar35 = gldPixelUnitBytes((uint)*(ushort *)(iVar34 + 0x10),(uint)*(ushort *)(iVar34 + 0x12));
    if (*(int *)(iVar34 + 0x14) != 0) {
      gldFlushDataCacheRangeSync(ctx,*(int *)(iVar34 + 0x14),(uint)uVar9 * iVar35 * uVar46,uVar39,uVar41,
                   uVar42,sc_scissor1,uVar43);
    }
  }
  if (((*(uint *)(param_2[0xc] + 0x48) & 0x8000) != 0) &&
     (param_4 == *(byte *)(param_2[0xc] + 0x5e))) {
    ((int (*)())glGenerateMipmap_impl)(ctx,param_2,param_3,uVar39,uVar41);
    return 1;
  }
  return 1;
}

/* glTexSubImage_impl @ 0x369f0 (9972 bytes) */
int glTexSubImage_impl(ctx, texture, face, level, xOffset, yOffset, zOffset, width, height, depth, pixelFormat, pixelType, pixels, rawTransfer, sourceSurface)
  int ctx;
  int *texture;
  int face;
  uint level;
  uint xOffset;
  uint yOffset;
  int zOffset;
  uint width;
  uint height;
  int depth;
  int pixelFormat;
  undefined *pixelType;
  uint pixels;
  undefined4 rawTransfer;
  undefined4 *sourceSurface;
{
  uint fg_fog_blendC;
  undefined4 vap_vte_cntlB;
  undefined4 vap_vte_cntl;
  float yoffsetF;
  float xoffsetF;
  float xEndF;
  float xBeginF;
  ushort levelWidthC;
  ushort levelHeightB;
  bool alignedOk;
  bool lastChunkB;
  int *surfaceRefPtr;
  undefined4 *packetEndB;
  undefined4 *surfaceObjectRef;
  undefined *hwContextTemplate;
  undefined *rowBytesTotal;
  uint *dstCursor;
  uint *srcCursor;
  uint *packetWrite;
  uint *dstRow;
  uint *sizeOutPtr;
  uint *alignedPtr;
  uint *dataCursorPtr;
  uint srcData;
  uint srcWord;
  uint srcRowBytesCopy;
  uint srcHwFormatB;
  uint bppShiftB;
  uint yoffsetArg;
  uint srcHwFormat;
  uint rowPitchB;
  uint bppShift;
  uint rowsLeft;
  uint swapMode;
  uint levelArg;
  uint alignedPitchPixels;
  uint rowPitch;
  int levelRecordB;
  int tiledFlag;
  int levelStateRecC;
  int rowStart;
  int levelStateRecB;
  int levelMappingRecB;
  int dataOffset;
  int headerRowsLeft;
  int rowWords;
  int levelMappingRec;
  int levelStateRec;
  int engineStateB;
  int levelOffset;
  int commandStreamB;
  int textureState;
  int commandStream;
  int faceArg;
  int storageRecord;
  int sourceBase;
  undefined4 *packet;
  uint fg_alpha_func;
  undefined4 ga_point_size;
  undefined4 sc_scissor1;
  undefined4 rb3d_ropcntl;
  undefined4 rb3d_color_channel_mask;
  undefined4 tx_format2;
  undefined4 tx_format1;
  undefined4 tx_format0;
  undefined4 tx_filter0;
  undefined4 rs_ip_0;
  undefined4 rs_count;
  undefined4 us_out_fmt_3;
  undefined4 us_out_fmt_2;
  undefined4 us_out_fmt_1;
  undefined4 us_out_fmt_0;
  undefined4 gb_ps3_enable;
  undefined4 tx_enable;
  undefined4 ga_color_control;
  undefined4 ga_poly_mode;
  undefined4 zb_cntl;
  undefined4 vap_prog_stream_cntl_ext_0_ptr;
  undefined4 vap_prog_stream_cntl_0_ptr;
  undefined4 vap_vtx_size;
  undefined4 vap_out_vtx_fmt_1;
  undefined4 vap_out_vtx_fmt_0;
  undefined4 gb_enable;
  undefined4 rb3d_dither_ctl;
  undefined4 su_cull_mode;
  undefined4 vap_clip_cntl;
  undefined4 vap_cntl_status;
  undefined4 zb_zstencilcntl;
  undefined4 zb_bw_cntl;
  undefined4 sc_hyperz_en;
  undefined4 gb_aa_config;
  undefined4 gb_mspos1;
  undefined4 sc_screendoor;
  undefined4 sc_edgerule;
  undefined4 dataBufferId;
  uint fg_fog_blend;
  uint *lastHeader;
  int engineState;
  bool lastChunk;
  float yEndF;
  float yBeginF;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  short sVar8;
  ushort uVar9;
  ushort levelWidthB;
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
  uint *srcRow;
  uint uVar24;
  undefined *unpackState;
  uint uVar26;
  int alignPixels;
  undefined4 uVar28;
  uint *puVar29;
  undefined4 *texPacket;
  undefined *a2;
  undefined4 uVar31;
  int iVar32;
  uint *puVar33;
  int iVar34;
  uint uVar35;
  int *piVar36;
  uint *puVar37;
  uint *puVar38;
  int levelRecord;
  undefined4 *packetEndA;
  undefined *bytesLeft;
  uint uVar42;
  int iVar43;
  uint uVar44;
  int iVar45;
  char reservation;
  byte bVar46;
  uint uStack_248;
  int srcSkipBytes;
  uint srcBytesPerPixel;
  uint *puStack_23c;
  uint srcRowBytes;
  uint uStack_234;
  uint uStack_230;
  uint *puStack_22c;
  uint procPitch;
  uint procChannelFormat;
  uint procChannelSize;
  undefined4 uStack_21c;
  uint procFlags;
  undefined *puStack_214;
  uint procWidth;
  uint procHeight;
  undefined4 uStack_208;
  undefined4 uStack_204;
  undefined1 uStack_1d0;
  undefined4 uStack_1c8;
  uint uStack_1c4;
  undefined4 uStack_1c0;
  uint uStack_1bc;
  undefined4 xoffsetI2dHiB;
  uint xoffsetI2dLoB;
  undefined4 yoffsetI2dHiB;
  uint yoffsetI2dLoB;
  undefined4 widthI2dHiB;
  uint widthI2dLoB;
  undefined4 heightI2dHiB;
  uint heightI2dLoB;
  longlong fctiwzSlot0;
  longlong fctiwzSlot1;
  longlong fctiwzSlot2;
  longlong fctiwzSlot3;
  longlong fctiwzSlot4;
  longlong fctiwzSlot5;
  longlong fctiwzSlot6;
  longlong fctiwzSlot7;
  longlong fctiwzSlot8;
  longlong fctiwzSlot9;
  undefined4 yStartI2dHi;
  uint yStartI2dLo;
  undefined4 yEndI2dHi;
  uint yEndI2dLo;
  longlong fctiwzSlot10;
  undefined4 xoffsetI2dHi;
  uint xoffsetI2dLo;
  undefined4 xEndI2dHi;
  uint xEndI2dLo;
  longlong fctiwzSlot11;
  uint chunkRowsHw;
  int rowEnd;
  int rowEndB;
  uint *puStack_10c;
  uint uStack_108;
  uint widthMask;
  uint levelFaceWord;
  int *piStack_fc;
  uint levelHeight;
  int mappingOffsetB;
  uint dstPitchCopy;
  uint chunkHeight;
  uint levelWidth;
  int rowsDone;
  uint chunkRows;
  int mappingOffset;
  int chunkBytes;
  code *pcStack_d4;
  code *pcStack_d0;
  int faceByteOffset;
  int *piStack_c8;
  uint *puStack_c4;
  uint **ppuStack_c0;
  uint *puStack_bc;
  uint *puStack_b8;
  uint *puStack_b4;
  code *pcStack_b0;
  uint levelId;
  code *pcStack_a8;
  int levelByteOffset;
  uint faceId;
  int iStack_9c;
  
  if (sourceSurface == (undefined4 *)0x0) {
    yoffsetArg = yOffset;
    _pthread_mutex_lock(*(undefined4 *)(ctx + GLD_mutex));
    uVar44 = 0;
    faceArg = face;
    levelArg = level;
    levelRecord = ((int (*)())gldTextureFormatEntryForLevel)(ctx,texture,face,level,0);
    if ((levelRecord != 0) &&
       ((iVar22 = texture[0xd], iVar22 == 0 || (*(char *)(iVar22 + 0x16) != '\x06')))) {
      if ((*(byte *)((int)texture + 0x39) & 7) != 0) {
        faceArg = ((int (*)())gldTextureMakeResident)(ctx,texture,faceArg,levelArg,uVar44,yoffsetArg);
        if (faceArg == 0) goto LAB_00037930;
        iVar22 = texture[0xd];
      }
      if (*(char *)(iVar22 + 0x16) != '\x06') {
        bppShiftB = *(uint *)(levelRecord + 0x14) & 7;
        rowPitch = (width << bppShiftB) + 0x23 & 0xffffffe0;
        if ((((depth == 1) && ((int)width < 0x1001)) &&
            ((0x800 >= (int)width || (bppShiftB < 4)))) && ((*(uint *)(levelRecord + 0x14) & 8) == 0)) {
          commandStream = ctx + GLD_commandStream;
          uVar28 = (**(code **)(ctx + GLD_streamAllocate))(commandStream,0xe0);
          *(undefined4 *)(ctx + GLD_streamCurrent) = uVar28;
          uVar28 = ((int (*)())FUN_00030840)(ctx,uVar28,texture);
          *(undefined4 *)(ctx + GLD_streamCurrent) = uVar28;
          (**(code **)(ctx + GLD_streamSetCurrent))(commandStream,uVar28);
          chunkRows = 0x1e000 / rowPitch;
          srcHwFormatB = ((int (*)())gldTextureFormatCodeFromFormatType)(pixelFormat,pixelType);
          if ((srcHwFormatB == *(byte *)(texture + 0xe)) && ((*(uint *)(levelRecord + 0x14) & 7) < 3)) {
            chunkRowsHw = 0x10000 / rowPitch;
            if (0 < (int)height) {
              levelByteOffset = level * 0x18;
              faceByteOffset = face * 0x168;
              levelId = level & 0xffff;
              mappingOffset = (face * 0xd + level) * 0x20;
              puStack_c4 = &srcBytesPerPixel;
              piStack_c8 = &srcSkipBytes;
              faceId = face << 0x10;
              rowsDone = 0;
              puStack_bc = &srcRowBytes;
              do {
                rowEnd = rowsDone + chunkRowsHw;
                lastChunk = (int)height <= rowEnd;
                if ((int)height < rowEnd) {
                  chunkHeight = height - rowsDone;
                }
                else {
                  chunkHeight = chunkRowsHw;
                }
                chunkBytes = rowPitch * chunkHeight;
                dataCursorPtr = *(uint **)(ctx + GLD_dataCursor);
                swapMode = *(uint *)(levelRecord + 0x18) >> 0x1e ^ 2;
                if (*(undefined1 **)(ctx + GLD_dataLimit) <=
                    (undefined1 *)((int)dataCursorPtr + chunkBytes + 0x80)) {
                  srcSkipBytes = 2;
                  uVar44 = *(int *)(ctx + GLD_dataRefillCount) + 1;
                  *(uint *)(ctx + GLD_dataRefillCount) = uVar44;
                  if (2 < uVar44) {
                    if (*(int *)(ctx + GLD_ringMap) + 0x28U < *(uint *)(ctx + GLD_writeCursor)) {
                      gld_submitRing(ctx,0x1000000);
                      dataCursorPtr = *(uint **)(ctx + GLD_dataCursor);
                    }
                    *(undefined4 *)(ctx + GLD_dataRefillCount) = 1;
                  }
                  *(int *)(*(int *)(ctx + GLD_contextBufferMap) + 0xc) =
                       (int)dataCursorPtr - *(int *)(ctx + GLD_dataBase) >> 2;
                  _io_connect_method_scalarI_scalarO
                            (*(undefined4 *)(ctx + GLD_connect),0x12,0,0,&puStack_23c,piStack_c8);
                  uVar44 = *(uint *)(GLD_updateFlags + ctx);
                  *(uint **)(ctx + GLD_dataBase) = puStack_23c;
                  *(uint **)(ctx + GLD_dataCursor) = puStack_23c;
                  *(undefined1 **)(ctx + GLD_dataLimit) =
                       (undefined1 *)((int)puStack_23c + (srcRowBytes & 0xfffffffc));
                  uVar28 = *(undefined4 *)(*(int *)(ctx + GLD_contextBufferMap) + 8);
                  *(uint *)(GLD_updateFlags + ctx) = uVar44 | 1;
                  *(undefined4 *)(ctx + GLD_dataBufferId) = uVar28;
                  dataCursorPtr = puStack_23c;
                }
                uStack_1d0 = 0;
                puStack_22c = (uint *)((uint)((int)dataCursorPtr + 0x7f) & 0xffffff80);
                *(uint **)(ctx + GLD_dataCursor) = puStack_22c;
                uStack_21c = 2;
                procHeight = chunkHeight;
                uStack_234 = *(uint *)(levelRecord + 0x10) >> 0x1b;
                uStack_204 = 0;
                uStack_208 = 0;
                puStack_214 = (undefined *)0x0;
                procFlags = 0;
                uStack_230 = *(uint *)(levelRecord + 0x10) >> 0x16 & 0x1f;
                if ((char)rawTransfer == '\0') {
                  engineState = *(int *)(ctx + GLD_engineState);
                  unpackState = ((unsigned char *)0x00002e6c) + engineState;
                  if (((unsigned char *)0x00002e84)[engineState] != '\0') {
                    procFlags = 1;
                    if (pixelType < (undefined *)0x8037) {
                      if (pixelType < (undefined *)0x8035) {
                        if (((unsigned char *)0x00001406) < pixelType) {
                          if ((pixelType != ((unsigned char *)0x0000140b)) &&
                             ((pixelType < ((unsigned char *)0x0000140b) || (pixelType < (undefined *)0x8033))))
                          goto LAB_00037c1c;
                        }
                        else {
                          if (((unsigned char *)0x00001404) < pixelType) goto LAB_00037c68;
                          if (pixelType != ((unsigned char *)0x00001403)) goto LAB_00037c1c;
                        }
                        goto LAB_00037c60;
                      }
LAB_00037c68:
                      uVar44 = 2;
                    }
                    else {
                      if (pixelType < (undefined *)0x8369) {
                        if ((undefined *)0x8366 < pixelType) goto LAB_00037c68;
                        if (pixelType < (undefined *)0x8363) goto LAB_00037c1c;
                      }
                      else if ((undefined *)((int)((unsigned char *)0x0) + 1) < pixelType + -0x85ba) {
LAB_00037c1c:
                        uVar44 = 0;
                        goto LAB_00037c6c;
                      }
LAB_00037c60:
                      uVar44 = 1;
                    }
LAB_00037c6c:
                    swapMode = swapMode ^ uVar44;
                  }
                  if (((unsigned char *)0x00002e85)[engineState] != '\0') {
                    procFlags = procFlags | 4;
                  }
                }
                else {
                  unpackState = (undefined *)0x0;
                }
                a2 = pixelType;
                procPitch = rowPitch;
                procChannelFormat = uStack_234;
                procChannelSize = uStack_230;
                procWidth = width;
                puStack_10c = puStack_22c;
                gld_computePixelStoreLayout(ctx,pixelFormat,pixelType,width,height,puStack_bc,puStack_c4,
                             piStack_c8,unpackState);
                srcRowBytesCopy = srcRowBytes;
                puStack_23c = (uint *)(pixels + srcSkipBytes + rowsDone * srcRowBytes);
                if (swapMode == 2) {
                  a2 = (undefined *)(srcBytesPerPixel * procWidth);
                  if (0 < (int)procHeight) {
                    srcRow = puStack_23c;
                    dstRow = puStack_22c;
                    rowsLeft = procHeight;
                    do {
                      rowsLeft = rowsLeft - 1;
                      if (0 < (int)a2) {
                        iVar22 = ((uint)(a2 + -1) >> 2) + 1;
                        srcCursor = srcRow;
                        dstCursor = dstRow;
                        if ((int)(a2 + -4) < -3) {
                          iVar22 = 1;
                        }
                        do {
                          srcWord = *srcCursor;
                          srcCursor = srcCursor + 1;
                          *dstCursor = srcWord >> 0x18 | srcWord >> 8 & 0xff00 | (srcWord & 0xff00) << 8
                                     | srcWord << 0x18;
                          dstCursor = dstCursor + 1;
                          iVar22 = iVar22 + -1;
                        } while (iVar22 != 0);
                      }
                      srcRow = (uint *)((int)srcRow + srcRowBytes);
                      dstRow = (uint *)((int)dstRow + procPitch);
                    } while (0 < (int)rowsLeft);
                  }
                }
                else if (swapMode == 3) {
                  iVar22 = srcBytesPerPixel * procWidth;
                  if (0 < (int)procHeight) {
                    srcRow = puStack_23c;
                    dstRow = puStack_22c;
                    rowsLeft = procHeight;
                    do {
                      rowsLeft = rowsLeft - 1;
                      if (0 < iVar22) {
                        iVar45 = (iVar22 - 1U >> 2) + 1;
                        srcCursor = srcRow;
                        dstCursor = dstRow;
                        if (iVar22 + -4 < -3) {
                          iVar45 = 1;
                        }
                        do {
                          srcWord = *srcCursor;
                          srcCursor = srcCursor + 1;
                          *dstCursor = srcWord << 0x10 | srcWord >> 0x10;
                          dstCursor = dstCursor + 1;
                          iVar45 = iVar45 + -1;
                        } while (iVar45 != 0);
                      }
                      srcRow = (uint *)((int)srcRow + srcRowBytes);
                      dstRow = (uint *)((int)dstRow + procPitch);
                    } while (0 < (int)rowsLeft);
                  }
                }
                else if (swapMode == 1) {
                  iVar22 = srcBytesPerPixel * procWidth;
                  if (0 < (int)procHeight) {
                    srcRow = puStack_23c;
                    dstRow = puStack_22c;
                    rowsLeft = procHeight;
                    do {
                      rowsLeft = rowsLeft - 1;
                      if (0 < iVar22) {
                        iVar45 = (iVar22 - 1U >> 1) + 1;
                        srcCursor = srcRow;
                        dstCursor = dstRow;
                        if (iVar22 + -2 < -1) {
                          iVar45 = 1;
                        }
                        do {
                          uVar9 = *(ushort *)srcCursor;
                          srcCursor = (uint *)((int)srcCursor + 2);
                          *(ushort *)dstCursor = uVar9 >> 8 | uVar9 << 8;
                          dstCursor = (uint *)((int)dstCursor + 2);
                          iVar45 = iVar45 + -1;
                        } while (iVar45 != 0);
                      }
                      srcRow = (uint *)((int)srcRow + srcRowBytes);
                      dstRow = (uint *)((int)dstRow + procPitch);
                    } while (0 < (int)rowsLeft);
                  }
                }
                else {
                  rowBytesTotal = (undefined *)(srcBytesPerPixel * procWidth);
                  dstPitchCopy = procPitch;
                  srcRow = puStack_23c;
                  dstRow = puStack_22c;
                  rowsLeft = procHeight;
                  if ((int)rowBytesTotal < 0x11) {
                    while (0 < (int)rowsLeft) {
                      srcCursor = srcRow;
                      dstCursor = dstRow;
                      bytesLeft = rowBytesTotal;
                      if ((((uint)dstRow & 1) != 0) && (rowBytesTotal != (undefined *)0x0)) {
                        *(undefined1 *)dstRow = *(undefined1 *)srcRow;
                        srcCursor = (uint *)((int)srcRow + 1);
                        dstCursor = (uint *)((int)dstRow + 1);
                        bytesLeft = rowBytesTotal + -1;
                      }
                      if ((((uint)dstCursor & 2) != 0) && ((undefined *)0x1 < bytesLeft)) {
                        uVar9 = *(ushort *)srcCursor;
                        bytesLeft = bytesLeft + -2;
                        srcCursor = (uint *)((int)srcCursor + 2);
                        *(ushort *)dstCursor = uVar9;
                        dstCursor = (uint *)((int)dstCursor + 2);
                      }
                      if ((undefined *)0x3 < bytesLeft) {
                        iVar45 = 0;
                        iVar22 = ((uint)(bytesLeft + -4) >> 2) + 1;
                        do {
                          bytesLeft = bytesLeft + -4;
                          *(undefined4 *)((int)dstCursor + iVar45) =
                               *(undefined4 *)((int)srcCursor + iVar45);
                          iVar45 = iVar45 + 4;
                          iVar22 = iVar22 + -1;
                        } while (iVar22 != 0);
                        dstCursor = (uint *)((int)dstCursor + iVar45);
                        srcCursor = (uint *)((int)srcCursor + iVar45);
                      }
                      if ((undefined *)0x1 < bytesLeft) {
                        uVar9 = *(ushort *)srcCursor;
                        bytesLeft = bytesLeft + -2;
                        srcCursor = (uint *)((int)srcCursor + 2);
                        *(ushort *)dstCursor = uVar9;
                        dstCursor = (uint *)((int)dstCursor + 2);
                      }
                      if (bytesLeft != (undefined *)0x0) {
                        *(undefined1 *)dstCursor = *(undefined1 *)srcCursor;
                      }
                      srcRow = (uint *)((int)srcRow + srcRowBytes);
                      dstRow = (uint *)((int)dstRow + procPitch);
                      rowsLeft = rowsLeft - 1;
                    }
                  }
                  else {
                    for (; 0 < (int)rowsLeft; rowsLeft = rowsLeft - 1) {
                      a2 = rowBytesTotal;
                      _memcpy(dstRow,srcRow,rowBytesTotal);
                      srcRow = (uint *)((int)srcRow + srcRowBytesCopy);
                      dstRow = (uint *)((int)dstRow + dstPitchCopy);
                    }
                  }
                }
                dataOffset = (int)puStack_10c - *(int *)(ctx + GLD_dataBase);
                *(int *)(ctx + GLD_dataCursor) = (int)puStack_10c + chunkBytes;
                packet = (undefined4 *)
                          (**(code **)(ctx + GLD_streamAllocate))(commandStream,0x2a,a2,puStack_10c,chunkBytes);
                uVar42 = 0;
                *(undefined4 **)(ctx + GLD_streamCurrent) = packet;
                lastHeader = *(uint **)(ctx + GLD_lastHeader);
                *lastHeader = (int)packet - (int)lastHeader >> 2 | *lastHeader;
                *(undefined4 **)(ctx + GLD_lastHeader) = packet;
                packet[2] = faceId | levelId;
                *packet = 0x44000000;
                packet[1] = 0x2a;
                dataBufferId = *(undefined4 *)(ctx + GLD_dataBufferId);
                packet[9] = 0xd07;
                packet[4] = dataOffset;
                packet[5] = ((unsigned char *)0x00001393U);
                packet[3] = dataBufferId;
                packet[6] = 10;
                packet[7] = 0x5c8;
                packet[8] = 0x20000;
                packet[0xb] = 0xc0001000;
                packet[0xc] = 0;
                packet[10] = 0xffffffff;
                packet[0xd] = 0x51b;
                uVar26 = *(uint *)(levelRecord + 0x18);
                packet[0xf] = 0x56b;
                packet[0x11] = 0x56c;
                packet[0x10] = 0;
                packet[0x13] = 0x5c1;
                packet[0x12] = rowPitch;
                packet[0x14] = 0;
                packet[0x15] = 0x501;
                packet[0xe] = uVar26 >> 0xf & 0xf00 | 0x2cc30fb;
                if ((texture[0xd] == 0) || (*(char *)(texture[0xd] + 0x16) != '\x06')) {
                  levelMappingRecB = *texture + 0x40 + mappingOffset;
                  packet[0x16] = zOffset * *(int *)(levelMappingRecB + 0x14) + *(int *)(levelMappingRecB + 8);
                }
                else {
                  packet[0x16] = 0;
                }
                levelStateRecB = levelByteOffset + faceByteOffset + texture[0xc];
                levelHeightB = *(ushort *)(levelStateRecB + 0xa6);
                uVar44 = (uint)levelHeightB;
                levelWidthB = *(ushort *)(levelStateRecB + 0xa4);
                if (*(char *)(texture[0xc] + 0x6d) == '\0') {
                  if ((texture[0xd] == 0) || ((*(byte *)(texture[0xd] + 0x15) & 0x18) == 0)) {
                    iVar22 = 0x20;
                  }
                  else {
                    iVar22 = 0x20 / (1 << (*(uint *)(&DAT_001d9f4c +
                                                    (uint)*(byte *)(texture + 0xe) * 0x24) >> 0x1c &
                                          3));
                  }
                  bppShift = *(uint *)(levelRecord + 0x14) & 7;
                  iVar22 = iVar22 >> bppShift;
                  iVar22 = (((uint)levelWidthB + iVar22) - 1 & -iVar22) << bppShift;
                }
                else {
                  iVar22 = (uint)*(ushort *)((int)texture + 0x3e) << (*(uint *)(levelRecord + 0x14) & 7);
                }
                packet[0x18] = iVar22;
                uVar26 = 0;
                packet[0x17] = 0x502;
                packet[0x19] = 0x5c0;
                if (texture[0xd] != 0) {
                  bVar46 = *(byte *)(texture[0xd] + 0x15);
                  bVar19 = bVar46 >> 3;
                  uVar26 = (bVar19 & 3) << 1;
                  if ((bVar46 & 4) != 0) {
                    uVar42 = level - *(byte *)(texture[0xc] + 0x69);
                    if ((bVar19 & 3) == 0) {
                      iVar45 = 1;
                      iVar22 = 0x100;
                    }
                    else {
                      iVar45 = 1 << (*(uint *)(&DAT_001d9f4c + (uint)*(byte *)(texture + 0xe) * 0x24
                                              ) >> 0x1c & 3);
                      iVar22 = 0x20 / iVar45 << 3;
                    }
                    if ((iVar22 <= *(int *)(*texture + 0xc) >> (uVar42 & 0x3f)) &&
                       (iVar45 << 3 <= (int)(uint)*(ushort *)(*texture + 0x16) >> (uVar42 & 0x3f)))
                    {
                      uVar26 = uVar26 | 1;
                    }
                  }
                }
                packet[0x1a] = uVar26;
                packet[0x1b] = 0x5bb;
                packet[0x1d] = 0x5bc;
                packet[0x1e] = CONCAT22(levelHeightB,levelWidthB);
                packet[0x1c] = 0;
                uVar26 = *(uint *)(levelRecord + 0x18) >> 0x17 & 0x1f;
                if ((uVar26 < 3) || ((iVar22 = 1, 4 < uVar26 && (iVar22 = 2, uVar26 != 6)))) {
                  iVar22 = 0;
                }
                uVar35 = (*(uint *)(levelRecord + 0x14) & 7) - iVar22;
                levelArg = 0;
                uVar21 = (rowsDone + yOffset) * 0x10000 | xOffset << (uVar35 & 0x3f) & 0xffff;
                packet[0x24] = 0xd0b;
                packet[0x22] = chunkHeight << 0x10 | width << (uVar35 & 0x3f) & 0xffff;
                packet[0x1f] = 0x50e;
                packet[0x20] = uVar21;
                packet[0x21] = 0x50f;
                packet[0x23] = 0x80000000;
                packet[0x26] = 0x5c8;
                packet[0x29] = 0;
                packet[0x25] = 5;
                packet[0x28] = ((unsigned char *)0x00001040U);
                packet[0x27] = 0x10000;
                *(undefined4 **)(ctx + GLD_streamCurrent) = packet + 0x2a;
                (**(code **)(ctx + GLD_streamSetCurrent))
                          (commandStream,packet + 0x2a,a2,0,uVar44,uVar42,uVar21,packet + 0x24);
                if (lastChunk) break;
                rowsDone = rowEnd;
              } while( true );
            }
          }
          else if (0 < (int)height) {
            xoffsetI2dLo = xOffset ^ 0x80000000;
            xEndI2dLo = width + xOffset ^ 0x80000000;
            xEndI2dHi = 0x43300000;
            xoffsetI2dHi = 0x43300000;
            pcStack_a8 = IrInt2F__dtor;
            iStack_9c = 0x1e6a08;
            levelByteOffset = level * 0x18;
            faceByteOffset = face * 0x168;
            mappingOffsetB = (face * 0xd + level) * 0x20;
            widthMask = width - 1 & 0x7ff;
            levelFaceWord = level | face << 0x10;
            puStack_c4 = &srcBytesPerPixel;
            puStack_b8 = &uStack_234;
            piStack_c8 = &srcSkipBytes;
            ppuStack_c0 = &puStack_23c;
            puStack_bc = &srcRowBytes;
            pcStack_d0 = IrInt2F__dtor;
            puStack_b4 = &uStack_230;
            pcStack_d4 = IrInt2F__dtor;
            pcStack_b0 = IrInt2F__dtor;
            xBeginF = (float)((double)CONCAT44(0x43300000,xoffsetI2dLo) - 4503601774854144.0);
            xEndF = (float)((double)CONCAT44(0x43300000,xEndI2dLo) - 4503601774854144.0);
            iVar22 = (int)((xEndF - xBeginF) * 6.0);
            fctiwzSlot11 = (longlong)iVar22;
            uStack_108 = iVar22 << 0x10;
            rowStart = 0;
            do {
              rowEndB = rowStart + chunkRows;
              lastChunkB = rowEndB < (int)height;
              uVar42 = chunkRows;
              if ((int)height < rowEndB) {
                uVar42 = height - rowStart;
              }
              rowPitchB = (width << (*(uint *)(levelRecord + 0x14) & 7)) + 0x23 & 0xffffffe0;
              packet = (undefined4 *)
                        (**(code **)(ctx + GLD_streamAllocate))(commandStream,(rowPitchB * uVar42 >> 2) + 0x193);
              piStack_fc = packet + 1;
              *(undefined4 **)(ctx + GLD_streamCurrent) = packet;
              lastHeader = *(uint **)(ctx + GLD_lastHeader);
              uVar28 = *(undefined4 *)(iStack_9c + 0x1ec8);
              levelStateRec = levelByteOffset + faceByteOffset + texture[0xc];
              levelHeight = (uint)*(ushort *)(levelStateRec + 0xa6);
              levelWidthC = *(ushort *)(levelStateRec + 0xa4);
              *lastHeader = (int)packet - (int)lastHeader >> 2 | *lastHeader;
              *(undefined4 **)(ctx + GLD_lastHeader) = packet;
              *packet = 0x35000000;
              packet[2] = levelFaceWord;
              _memcpy(packet + 3,uVar28,0x2f4);
              uVar44 = *(uint *)(levelRecord + 0x18);
              packet[0xa9] = (uVar42 - 1) * 0x800 & 0x3ff800 | widthMask | 0x80000000;
              packet[0xa3] = uVar44 >> 0x1e | packet[0xa3] & 0xfffffffc;
              uVar44 = *(uint *)(((unsigned char *)0x00003c14) +
                                (int)(pcStack_d0 + (*(uint *)(levelRecord + 0x14) & 7) * 4));
              packet[0xab] = uVar44 & 0x1f | 0xa600;
              uVar24 = *(uint *)(levelRecord + 0x14);
              if ((uVar24 & 7) == 0) {
                packet[0xab] = uVar44 & 0x1f | 0x8600;
                uVar24 = *(uint *)(levelRecord + 0x14);
              }
              packet[0xad] =
                   (uint)(0x800 < (int)uVar42) << 0x10 |
                   (uint)(0x800 < (int)width) << 0xf | (rowPitchB >> (uVar24 & 7)) - 1 & 0x3fff;
              packet[0x8d] =
                   *(uint *)(pcStack_d4 + (*(uint *)(levelRecord + 0x14) & 7) * 4 + 0x3c00) & 0x1f |
                   packet[0x8d] & 0xffffffe0;
              iVar45 = texture[0xd];
              if ((iVar45 == 0) || ((*(byte *)(iVar45 + 0x15) & 0x18) == 0)) {
                alignPixels = 0x20;
              }
              else {
                alignPixels = 0x20 / (1 << (*(uint *)(((unsigned char *)0x00003544) +
                                                (int)(pcStack_a8 +
                                                     (uint)*(byte *)(texture + 0xe) * 0x24)) >> 0x1c
                                      & 3));
              }
              alignPixels = alignPixels >> (*(uint *)(levelRecord + 0x14) & 7);
              if ((iVar45 == 0) || (*(char *)(iVar45 + 0x16) != '\x06')) {
                uVar44 = 0;
                levelMappingRec = *texture + 0x40 + mappingOffsetB;
                levelMappingRec = zOffset * *(int *)(levelMappingRec + 0x14) + *(int *)(levelMappingRec + 8);
              }
              else {
                levelMappingRec = 0;
                uVar44 = *(uint *)(levelRecord + 0x18) >> 0xb & 0x180000;
              }
              packet[0x9d] = levelMappingRec;
              if (*(char *)(texture[0xc] + 0x6d) != '\0') {
                levelWidthC = *(ushort *)((int)texture + 0x3e);
              }
              iVar45 = texture[0xd];
              alignedPitchPixels = ((uint)levelWidthC + alignPixels) - 1 & -alignPixels;
              if ((iVar45 == 0) || ((*(byte *)(iVar45 + 0x15) & 4) == 0)) {
LAB_00038698:
                tiledFlag = 0;
              }
              else {
                uVar35 = level - *(byte *)(texture[0xc] + 0x69);
                if ((*(byte *)(iVar45 + 0x15) & 0x18) == 0) {
                  iVar20 = 1;
                  tiledFlag = 0x100;
                }
                else {
                  iVar20 = 1 << (*(uint *)(((unsigned char *)0x00003544) +
                                          (int)(pcStack_a8 + (uint)*(byte *)(texture + 0xe) * 0x24))
                                 >> 0x1c & 3);
                  tiledFlag = 0x20 / iVar20 << 3;
                }
                if ((*(int *)(*texture + 0xc) >> (uVar35 & 0x3f) < tiledFlag) ||
                   (tiledFlag = 1,
                   (int)(uint)*(ushort *)(*texture + 0x16) >> (uVar35 & 0x3f) < iVar20 << 3))
                goto LAB_00038698;
              }
              if (((*(uint *)(levelRecord + 0x18) & 0x30000000) == 0) || (iVar45 == 0)) {
                uVar35 = 0;
              }
              else {
                uVar35 = (*(byte *)(iVar45 + 0x15) & 0x18) << 0xe;
              }
              uVar21 = *(uint *)(((unsigned char *)0x00003bec) +
                                (int)(pcStack_b0 + (*(uint *)(levelRecord + 0x14) & 7) * 4));
              yStartI2dLo = rowStart + yOffset ^ 0x80000000;
              yEndI2dLo = uVar42 + rowStart + yOffset ^ 0x80000000;
              packet[0xb6] = alignedPitchPixels - 1 & 0x1fff | (levelHeight - 1) * 0x2000 & 0x3ffe000;
              packetEndA = packet + 0xcc;
              packet[0x9f] =
                   uVar35 | alignedPitchPixels & 0x3ffe | tiledFlag << 0x10 | uVar44 | (uVar21 & 0xf) << 0x15;
              yEndI2dHi = 0x43300000;
              yStartI2dHi = 0x43300000;
              packet[0xc0] = 0x31080;
              packet[0xc4] = 0;
              packet[0xc1] = 0;
              packet[0xc5] = ((unsigned char *)0x00001087U);
              packet[0xc3] = 0x3f800000;
              packet[0xc2] = 0x3f800000;
              yEndF = (float)((double)CONCAT44(0x43300000,yEndI2dLo) - 4503601774854144.0);
              yBeginF = (float)((double)CONCAT44(0x43300000,yStartI2dLo) - 4503601774854144.0);
              uVar44 = (uint)(int)((yEndF - yBeginF) * 6.0);
              fctiwzSlot10 = (longlong)(int)uVar44;
              packet[199] = 0xc0033500;
              packet[200] = 0x10031;
              packet[0xca] = (yBeginF + yEndF) * 0.5;
              packet[0xc9] = (xEndF + xBeginF) * 0.5;
              packet[0xcb] = 0;
              packet[0xc6] = uVar44 | uStack_108;
              *piStack_fc = (int)packetEndA - (int)packet >> 2;
              lastHeader = *(uint **)(ctx + GLD_lastHeader);
              *lastHeader = (int)packetEndA - (int)lastHeader >> 2 | *lastHeader;
              *(undefined4 **)(ctx + GLD_lastHeader) = packetEndA;
              packet[0xcd] = 0;
              packet[0xcc] = 0x33000000;
              packet[0xce] = ((unsigned char *)0x00001393U);
              packet[0xcf] = 10;
              packet[0xd0] = ((unsigned char *)0x000013c6U);
              packet[0xd1] = 3;
              packet[0xd2] = 0x5c8;
              packet[0xd3] = 0x20000;
              packet[0xd4] = ((unsigned char *)0x000010eaU);
              sc_edgerule = *(undefined4 *)(ctx + GLD_sc_edgerule);
              packet[0xd6] = ((unsigned char *)0x000010faU);
              packet[0xd5] = sc_edgerule;
              sc_screendoor = *(undefined4 *)(ctx + GLD_sc_screendoor);
              packet[0xd8] = 0xc0001000;
              packet[0xda] = 0x11004;
              packet[0xd7] = sc_screendoor;
              packet[0xdb] = *(undefined4 *)(ctx + GLD_gb_mspos0);
              gb_mspos1 = *(undefined4 *)(ctx + GLD_gb_mspos1);
              packet[0xdd] = ((unsigned char *)0x00001008U);
              packet[0xdc] = gb_mspos1;
              gb_aa_config = *(undefined4 *)(ctx + GLD_gb_aa_config);
              packet[0xdf] = ((unsigned char *)0x000010e9U);
              packet[0xde] = gb_aa_config;
              sc_hyperz_en = *(undefined4 *)(ctx + GLD_sc_hyperz_en);
              packet[0xe1] = ((unsigned char *)0x000013c7U);
              packet[0xe0] = sc_hyperz_en;
              zb_bw_cntl = *(undefined4 *)(ctx + GLD_zb_bw_cntl);
              packet[0xe3] = ((unsigned char *)0x000013c1U);
              packet[0xe2] = zb_bw_cntl;
              zb_zstencilcntl = *(undefined4 *)(ctx + GLD_zb_zstencilcntl);
              packet[0xe5] = 0x850;
              packet[0xe4] = zb_zstencilcntl;
              vap_cntl_status = *(undefined4 *)(ctx + GLD_vap_cntl_status);
              packet[0xe7] = 0x887;
              packet[0xe6] = vap_cntl_status;
              vap_clip_cntl = *(undefined4 *)(ctx + GLD_vap_clip_cntl);
              packet[0x189] = 0x82c;
              packet[0xe8] = vap_clip_cntl;
              vap_vte_cntl = *(undefined4 *)(GLD_vap_vte_cntl + ctx);
              packet[0xe9] = ((unsigned char *)0x000010aeU);
              packet[0x18a] = vap_vte_cntl;
              su_cull_mode = *(undefined4 *)(ctx + GLD_su_cull_mode);
              packet[0xeb] = ((unsigned char *)0x00001394U);
              packet[0xea] = su_cull_mode;
              rb3d_dither_ctl = *(undefined4 *)(ctx + GLD_rb3d_dither_ctl);
              packet[0xed] = ((unsigned char *)0x00001380U);
              packet[0xef] = ((unsigned char *)0x00001002U);
              packet[0xee] = 0;
              packet[0xec] = rb3d_dither_ctl;
              packet[0xf0] = *(undefined4 *)(ctx + GLD_gb_enable);
              gb_enable = *(undefined4 *)(ctx + GLD_gb_enable);
              packet[0xf1] = 0x824;
              packet[0xf0] = gb_enable;
              vap_out_vtx_fmt_0 = *(undefined4 *)(ctx + GLD_vap_out_vtx_fmt_0);
              packet[0xf3] = 0x825;
              packet[0xf2] = vap_out_vtx_fmt_0;
              vap_out_vtx_fmt_1 = *(undefined4 *)(ctx + GLD_vap_out_vtx_fmt_1);
              packet[0xf5] = 0x82d;
              packet[0xf4] = vap_out_vtx_fmt_1;
              vap_vtx_size = *(undefined4 *)(ctx + GLD_vap_vtx_size);
              packet[0xf7] = 0x854;
              packet[0xf6] = vap_vtx_size;
              vap_prog_stream_cntl_0_ptr = **(undefined4 **)(ctx + GLD_vap_prog_stream_cntl_0_ptr);
              packet[0xf9] = 0x878;
              packet[0xf8] = vap_prog_stream_cntl_0_ptr;
              vap_prog_stream_cntl_ext_0_ptr = **(undefined4 **)(ctx + GLD_vap_prog_stream_cntl_ext_0_ptr);
              packet[0xfb] = ((unsigned char *)0x000013c0U);
              packet[0xfa] = vap_prog_stream_cntl_ext_0_ptr;
              zb_cntl = *(undefined4 *)(ctx + GLD_zb_cntl);
              packet[0xfd] = ((unsigned char *)0x000012f0U);
              packet[0xfc] = zb_cntl;
              fg_fog_blendC = *(uint *)(ctx + GLD_fg_fog_blend);
              packet[0xfe] = fg_fog_blendC;
              if ((*(uint *)(((unsigned char *)0x0000352c) +
                            (int)(pcStack_a8 + (uint)(byte)((unsigned char *)GLD_colorFormatIndex)[ctx] * 0x24 + 0x18))
                  & 0x8000) == 0) {
                packet[0xfe] = fg_fog_blendC & 0xfffffffe;
              }
              packet[0xff] = ((unsigned char *)0x000012f5U);
              fg_alpha_func = *(uint *)(ctx + GLD_fg_alpha_func);
              packet[0x100] = fg_alpha_func;
              if ((*(uint *)(((unsigned char *)0x0000352c) +
                            (int)(pcStack_a8 + (uint)(byte)((unsigned char *)GLD_colorFormatIndex)[ctx] * 0x24 + 0x18))
                  & 0x8000) == 0) {
                packet[0x100] = fg_alpha_func & 0xfffff7ff;
              }
              packet[0x101] = ((unsigned char *)0x000010a2U);
              ga_poly_mode = *(undefined4 *)(ctx + GLD_ga_poly_mode);
              packet[0x103] = ((unsigned char *)0x00001381U);
              packet[0x102] = ga_poly_mode;
              uVar44 = *(uint *)(ctx + GLD_rb3d_blendcntl);
              packet[0x104] = uVar44;
              if ((*(uint *)(((unsigned char *)0x0000352c) +
                            (int)(pcStack_a8 + (uint)(byte)((unsigned char *)GLD_colorFormatIndex)[ctx] * 0x24 + 0x18))
                  & 0x4000) == 0) {
                packet[0x104] = uVar44 & 0xfffffffc;
              }
              packet[0x105] = ((unsigned char *)0x0000109eU);
              uVar28 = *(undefined4 *)(ctx + 0x1d6c);
              packet[0x107] = ((unsigned char *)0x00001096U);
              packet[0x106] = uVar28;
              ga_color_control = *(undefined4 *)(ctx + GLD_ga_color_control);
              packet[0x109] = ((unsigned char *)0x00001041U);
              packet[0x106] = ga_color_control;
              tx_enable = *(undefined4 *)(ctx + GLD_tx_enable);
              packet[0x10b] = ((unsigned char *)0x00001046U);
              packet[0x10a] = tx_enable;
              gb_ps3_enable = *(undefined4 *)(ctx + GLD_gb_ps3_enable);
              packet[0x10d] = ((unsigned char *)0x00001094U);
              packet[0x125] = ((unsigned char *)0x00001095U);
              packet[0x127] = 0xc0221000;
              packet[0x14b] = ((unsigned char *)0x00001180U);
              packet[0x10f] = ((unsigned char *)0x00001095U);
              packet[0x111] = ((unsigned char *)0x00001095U);
              packet[0x113] = ((unsigned char *)0x00001095U);
              packet[0x10c] = gb_ps3_enable;
              packet[0x115] = ((unsigned char *)0x00001095U);
              packet[0x117] = ((unsigned char *)0x00001095U);
              packet[0x119] = ((unsigned char *)0x00001095U);
              packet[0x11b] = ((unsigned char *)0x00001095U);
              packet[0x11d] = ((unsigned char *)0x00001095U);
              packet[0x11f] = ((unsigned char *)0x00001095U);
              packet[0x121] = ((unsigned char *)0x00001095U);
              packet[0x123] = ((unsigned char *)0x00001095U);
              packet[0x10e] = 0;
              packet[0x14c] = 2;
              packet[0x14d] = ((unsigned char *)0x00001189U);
              packet[0x14f] = ((unsigned char *)0x00001181U);
              packet[0x151] = ((unsigned char *)0x0000118dU);
              packet[0x153] = ((unsigned char *)0x0000118eU);
              packet[0x155] = ((unsigned char *)0x0000118cU);
              packet[0x157] = ((unsigned char *)0x000011a9U);
              us_out_fmt_0 = *(undefined4 *)(ctx + GLD_us_out_fmt_0);
              packet[0x159] = ((unsigned char *)0x000011aaU);
              packet[0x158] = us_out_fmt_0;
              us_out_fmt_1 = *(undefined4 *)(ctx + GLD_us_out_fmt_1);
              packet[0x15b] = ((unsigned char *)0x000011abU);
              packet[0x15a] = us_out_fmt_1;
              us_out_fmt_2 = *(undefined4 *)(ctx + GLD_us_out_fmt_2);
              packet[0x15d] = ((unsigned char *)0x000011acU);
              packet[0x15c] = us_out_fmt_2;
              us_out_fmt_3 = *(undefined4 *)(ctx + GLD_us_out_fmt_3);
              packet[0x15f] = ((unsigned char *)0x000010c0U);
              packet[0x15e] = us_out_fmt_3;
              rs_count = *(undefined4 *)(ctx + GLD_rs_count);
              packet[0x161] = ((unsigned char *)0x000010c1U);
              packet[0x163] = ((unsigned char *)0x000010c8U);
              packet[0x165] = ((unsigned char *)0x0000101dU);
              packet[0x160] = rs_count;
              rs_ip_0 = *(undefined4 *)(ctx + GLD_rs_ip_0);
              packet[0x167] = ((unsigned char *)0x0000138aU);
              packet[0x169] = ((unsigned char *)0x0000138eU);
              packet[0x16e] = 0;
              packet[0x16b] = ((unsigned char *)0x00001040U);
              packet[0x168] = 0;
              packet[0x16a] = 0;
              packet[0x16c] = 0;
              packet[0x166] = rs_ip_0;
              packet[0x16d] = ((unsigned char *)0x00001150U);
              packet[0x16f] = ((unsigned char *)0x00001100U);
              tx_filter0 = *(undefined4 *)(ctx + GLD_tx_filter0);
              packet[0x171] = ((unsigned char *)0x00001110U);
              packet[0x170] = tx_filter0;
              packet[0x172] = *(undefined4 *)(ctx + GLD_tx_filter1);
              packet[0x173] = ((unsigned char *)0x00001120U);
              tx_format0 = *(undefined4 *)(ctx + GLD_tx_format0);
              packet[0x175] = ((unsigned char *)0x00001130U);
              packet[0x174] = tx_format0;
              tx_format1 = *(undefined4 *)(ctx + GLD_tx_format1);
              packet[0x177] = ((unsigned char *)0x00001140U);
              packet[0x176] = tx_format1;
              tx_format2 = *(undefined4 *)(ctx + GLD_tx_format2);
              packet[0x179] = ((unsigned char *)0x000010f4U);
              packet[0x17a] = 0xaaaa;
              packet[0x17b] = ((unsigned char *)0x00001383U);
              packet[0x178] = tx_format2;
              rb3d_color_channel_mask = *(undefined4 *)(ctx + GLD_rb3d_color_channel_mask);
              packet[0x17d] = ((unsigned char *)0x00001386U);
              packet[0x17c] = rb3d_color_channel_mask;
              rb3d_ropcntl = *(undefined4 *)(ctx + GLD_rb3d_ropcntl);
              packet[0x17f] = 0x110f8;
              packet[0x17e] = rb3d_ropcntl;
              packet[0x180] = *(undefined4 *)(ctx + GLD_sc_scissor0);
              sc_scissor1 = *(undefined4 *)(ctx + GLD_sc_scissor1);
              packet[0x182] = ((unsigned char *)0x00001087U);
              packet[0x181] = sc_scissor1;
              ga_point_size = *(undefined4 *)(ctx + GLD_ga_point_size);
              packet[0x184] = 0x31080;
              packet[0x183] = ga_point_size;
              packet[0x185] = *(undefined4 *)(ctx + GLD_ga_point_s0);
              packet[0x186] = *(undefined4 *)(ctx + GLD_ga_point_t0);
              packet[0x187] = *(undefined4 *)(ctx + GLD_ga_point_s1);
              packet[0x188] = *(undefined4 *)(ctx + GLD_ga_point_t1);
              FUN_0004c100(packet + 0xce,commandStream);
              packetWrite = packet + 0x18b;
              for (alignedPtr = packet + 0x18c; ((uint)alignedPtr & 0x1f) != 0; alignedPtr = alignedPtr + 1) {
              }
              uVar44 = 0x80000000;
              packet[0xa3] = ((int)alignedPtr - (int)packet) * 8 & 0xffffffe0U | packet[0xa3] & 0x1f
              ;
              rowWords = ((int)((width << (*(uint *)(levelRecord + 0x14) & 7)) + 3) >> 2) +
                       ((int)alignedPtr - (int)packetWrite >> 2);
              if (rowWords != 1) {
                uVar44 = (rowWords + -2) * 0x10000 | 0xc0001000;
              }
              *packetWrite = uVar44;
              packetWrite = packetWrite + rowWords;
              if (1 < (int)uVar42) {
                uVar44 = rowPitchB >> 2;
                headerRowsLeft = uVar42 - 1;
                do {
                  if (uVar44 == 1) {
                    uVar24 = 0x80000000;
                  }
                  else {
                    uVar24 = (uVar44 - 2) * 0x10000 | 0xc0001000;
                  }
                  *packetWrite = uVar24;
                  packetWrite = packetWrite + uVar44;
                  headerRowsLeft = headerRowsLeft + -1;
                } while (headerRowsLeft != 0);
              }
              procChannelFormat = *(uint *)(levelRecord + 0x10) >> 0x1b;
              sVar8 = *(short *)(texture[0xc] + 0x1a);
              sVar11 = *(short *)(texture[0xc] + 2);
              uStack_204 = 0;
              procFlags = 0;
              puStack_214 = ((unsigned char *)0x0007efffU);
              uStack_208 = 0;
              procChannelSize = *(uint *)(levelRecord + 0x10) >> 0x16 & 0x1f;
              if ((char)rawTransfer == '\0') {
                engineStateB = *(int *)(ctx + GLD_engineState);
                unpackState = ((unsigned char *)0x00002e6c) + engineStateB;
                procFlags = (uint)(((unsigned char *)0x00002e84)[engineStateB] != '\0');
                if (((unsigned char *)0x00002e85)[engineStateB] != '\0') {
                  procFlags = procFlags | 4;
                }
              }
              else {
                unpackState = (undefined *)0x0;
              }
              uVar44 = height;
              puVar37 = puStack_bc;
              piVar36 = piStack_c8;
              puVar38 = puStack_c4;
              procPitch = rowPitchB;
              gld_computePixelStoreLayout(ctx,pixelFormat,pixelType,width,height,puStack_bc,piStack_c8,
                           puStack_c4,unpackState);
              puVar33 = puStack_b8;
              _glgConvertType(pixelFormat,pixelType,puStack_b8,puStack_b4,uVar44,puVar37,piVar36,puVar38
                             );
              if ((((sVar11 != 0x1908) && (sVar8 != -0x7a43)) && (sVar11 != 0x1906)) &&
                 ((sVar11 != 0x190a &&
                  ((0x15 < procChannelFormat || ((1 << (procChannelFormat & 0x3f) & 0x3ff707U) == 0)))))) {
                procFlags = procFlags | 0x8000;
              }
              uStack_21c = 2;
              uStack_1d0 = 0;
              puStack_23c = (uint *)(pixels + srcBytesPerPixel + rowStart * srcRowBytes);
              levelArg = pixels;
              puStack_22c = alignedPtr;
              procWidth = width;
              procHeight = uVar42;
              _glgProcessPixels(((unsigned char *)0x00002e48) + *(int *)(ctx + GLD_engineState),ppuStack_c0,puVar33,
                                pixels,uVar44,puVar37,rowStart * srcRowBytes,puVar38);
              *(uint **)(ctx + GLD_streamCurrent) = packetWrite;
              (**(code **)(ctx + GLD_streamSetCurrent))(commandStream,packetWrite);
              rowStart = rowEndB;
            } while (lastChunkB);
          }
          uVar28 = (**(code **)(ctx + GLD_streamAllocate))(commandStream,0xe0);
          *(undefined4 *)(ctx + GLD_streamCurrent) = uVar28;
          uVar28 = ((int (*)())FUN_000308c0)(ctx,uVar28);
          *(undefined4 *)(ctx + GLD_streamCurrent) = uVar28;
          (**(code **)(ctx + GLD_streamSetCurrent))(commandStream,uVar28);
          _pthread_mutex_unlock(*(undefined4 *)(ctx + GLD_mutex));
          if ((*(uint *)(texture[0xc] + 0x48) & 0x8000) == 0) {
            return 1;
          }
          if (level != *(byte *)(texture[0xc] + 0x5e)) {
            return 1;
          }
          ((int (*)())glGenerateMipmap_impl)(ctx,texture,face,levelArg,uVar44);
          return 1;
        }
      }
    }
LAB_00037930:
    _pthread_mutex_unlock(*(undefined4 *)(ctx + GLD_mutex));
    return 0;
  }
  textureState = texture[0xc];
  srcHwFormat = ((int (*)())gldTextureFormatCodeFromFormatType)(pixelFormat,pixelType);
  if (srcHwFormat == 0) {
    return 0;
  }
  sizeOutPtr = &uStack_248;
  gld_computePixelStoreLayout(ctx,pixelFormat,pixelType,width,height,sizeOutPtr,&srcBytesPerPixel,&srcSkipBytes,
               ((unsigned char *)0x00002e6c) + *(int *)(ctx + GLD_engineState));
  sourceBase = *(int *)*sourceSurface;
  srcData = pixels + srcSkipBytes;
  if (0x1000 < (int)uStack_248 >> (srcBytesPerPixel & 0x3f)) {
    return 0;
  }
  if (0x1000 < (int)height) {
    return 0;
  }
  levelOffset = level * 0x18 + face * 0x168;
  levelStateRecC = levelOffset + texture[0xc];
  if (0x1000 < *(ushort *)(levelStateRecC + 0xa4)) {
    return 0;
  }
  if (0x1000 < *(ushort *)(levelStateRecC + 0xa6)) {
    return 0;
  }
  _pthread_mutex_lock(*(undefined4 *)(ctx + GLD_mutex));
  iVar22 = face;
  levelRecordB = ((int (*)())gldTextureFormatEntryForLevel)(ctx,texture,face,level,0);
  if ((levelRecordB == 0) || ((*(uint *)(levelRecordB + 0x18) & 0x10000) == 0)) goto LAB_00037930;
  levelOffset = levelOffset + texture[0xc];
  levelWidth = (uint)*(ushort *)(levelOffset + 0xa4);
  uVar42 = (uint)*(ushort *)(levelOffset + 0xa6);
  if (levelWidth == 0) {
    fVar4 = 1.0;
    levelWidth = 1;
  }
  else {
    uStack_1c8 = 0x43300000;
    uStack_1c4 = levelWidth ^ 0x80000000;
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
  xoffsetI2dLoB = xOffset ^ 0x80000000;
  widthI2dLoB = width ^ 0x80000000;
  xoffsetI2dHiB = 0x43300000;
  yoffsetI2dLoB = yOffset ^ 0x80000000;
  heightI2dHiB = 0x43300000;
  yoffsetI2dHiB = 0x43300000;
  widthI2dHiB = 0x43300000;
  heightI2dLoB = height ^ 0x80000000;
  fVar6 = 0.0;
  xoffsetF = (float)((double)CONCAT44(0x43300000,xoffsetI2dLoB) - 4503601774854144.0);
  yoffsetF = (float)((double)CONCAT44(0x43300000,yoffsetI2dLoB) - 4503601774854144.0);
  fVar7 = xoffsetF + 0.0;
  fVar16 = yoffsetF + 0.0;
  fVar17 = (float)((double)CONCAT44(0x43300000,heightI2dLoB) - 4503601774854144.0) + yoffsetF;
  fVar14 = (float)((double)CONCAT44(0x43300000,widthI2dLoB) - 4503601774854144.0) + xoffsetF;
  fVar15 = fVar7;
  if (0.0 < fVar7) {
    fVar15 = xoffsetF + fVar7;
    fVar6 = fVar7;
  }
  fVar7 = 0.0;
  if (0.0 < fVar16) {
    fVar7 = fVar16;
    fVar16 = yoffsetF + fVar16;
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
    _pthread_mutex_unlock(*(undefined4 *)(ctx + GLD_mutex));
    return 1;
  }
  if (((((*(byte *)((int)texture + 0x39) & 7) != 0) &&
       (iVar22 = ((int (*)())gldTextureMakeResident)(ctx,texture,iVar22,*(byte *)((int)texture + 0x39) & 7,"",sizeOutPtr),
       iVar22 == 0)) ||
      ((*(int *)sourceSurface[1] != 0 && (iVar22 = gld_prepareBufferBacking(ctx,sourceSurface,1), iVar22 == 0)))) ||
     (((int *)sourceSurface[2] == (int *)0x0 || (iVar22 = *(int *)sourceSurface[2], iVar22 == 0))))
  goto LAB_00037930;
  if (*(char *)(iVar22 + 0x16) != '\x06') {
    if (pixelFormat == 0x1908) {
      if (pixelType != ((unsigned char *)0x00001406)) goto LAB_00037930;
    }
    else if ((pixelFormat != 0x80e1) || (pixelType != (undefined *)0x8367)) goto LAB_00037930;
  }
  pcStack_a8 = IrInt2F__dtor;
  iVar22 = (srcHwFormat & 0xff) * 0x24;
  alignedOk = ((srcData | uStack_248) & 0x1f) == 0;
  bVar46 = alignedOk << 1;
  if (!alignedOk) goto LAB_00037930;
  commandStreamB = ctx + GLD_commandStream;
  uVar28 = (**(code **)(ctx + GLD_streamAllocate))(commandStreamB,0x343);
  *(undefined4 *)(ctx + GLD_streamCurrent) = uVar28;
  puVar29 = (uint *)((int (*)())FUN_00030840)(ctx,uVar28,texture);
  texPacket = (undefined4 *)((uint)(puVar29 + 0xb) & 0xffffffe0);
  *puVar29 = (((int)texPacket - (int)puVar29) + -8) * 0x4000 | 0xc0001000;
  texPacket[-1] = (int)texPacket - (int)puVar29;
  lastHeader = *(uint **)(ctx + GLD_lastHeader);
  *lastHeader = (int)texPacket - (int)lastHeader >> 2 | *lastHeader;
  *(undefined4 **)(ctx + GLD_lastHeader) = texPacket;
  *texPacket = 0x3e000000;
  surfaceObjectRef = *(undefined4 **)sourceSurface[2];
  surfaceRefPtr = surfaceObjectRef + 4;
  do {
    if (reservation != '\0') {
      iVar20 = storeWordConditionalIndexed(*surfaceRefPtr + 0x10000,0,surfaceRefPtr);
      *surfaceRefPtr = iVar20;
      bVar46 = 2;
    }
    hwContextTemplate = PTR_DAT_001e88d0;
  } while (!(bool)(bVar46 >> 1 & 1));
  texPacket[2] = *surfaceObjectRef;
  iVar20 = *(int *)*sourceSurface;
  texPacket[4] = level | face << 0x10;
  texPacket[3] = srcData - iVar20;
  _memcpy(texPacket + 5,hwContextTemplate,0x2f4);
  iVar20 = texture[0xd];
  if ((iVar20 == 0) || ((*(byte *)(iVar20 + 0x15) & 0x18) == 0)) {
    iVar34 = 0x20;
  }
  else {
    iVar34 = 0x20 / (1 << (*(uint *)(&DAT_001d9f4c + (uint)*(byte *)(texture + 0xe) * 0x24) >> 0x1c
                          & 3));
  }
  iVar34 = iVar34 >> (*(uint *)(levelRecordB + 0x14) & 7);
  if ((iVar20 == 0) || (iVar32 = 0, *(char *)(iVar20 + 0x16) != '\x06')) {
    iVar20 = *texture + 0x40 + (face * 0xd + level) * 0x20;
    iVar32 = zOffset * *(int *)(iVar20 + 0x14) + *(int *)(iVar20 + 8);
  }
  if (*(char *)(texture[0xc] + 0x6d) == '\0') {
    uVar26 = (levelWidth + iVar34) - 1 & -iVar34;
  }
  else {
    uVar26 = (uint)*(ushort *)((int)texture + 0x3e);
  }
  fVar4 = (fVar13 + xoffsetF) - fVar15;
  fVar5 = (fVar14 + yoffsetF) - fVar16;
  fVar17 = fVar4 - 1.0;
  texPacket[0xa5] = *(uint *)(&DAT_001d9f4c + iVar22) >> 0x1e | texPacket[0xa5] & 0xfffffffc;
  if (2.1474836e+09 <= fVar17) {
    fctiwzSlot1 = (longlong)(int)(fVar17 - 2.1474836e+09);
    uVar24 = (int)(fVar17 - 2.1474836e+09) + 0x80000000;
  }
  else {
    uVar24 = (uint)(int)fVar17;
    fctiwzSlot0 = (longlong)(int)uVar24;
  }
  fVar17 = fVar5 - 1.0;
  if (2.1474836e+09 <= fVar17) {
    fctiwzSlot3 = (longlong)(int)(fVar17 - 2.1474836e+09);
    uVar35 = (int)(fVar17 - 2.1474836e+09) + 0x80000000;
  }
  else {
    uVar35 = (uint)(int)fVar17;
    fctiwzSlot2 = (longlong)(int)uVar35;
  }
  texPacket[0xab] = uVar24 & 0x7ff | (uVar35 & 0x7ff) << 0xb | 0x80000000;
  uVar24 = *(uint *)(&DAT_001d9f50 + iVar22);
  uVar35 = *(uint *)(&DAT_001d9f54 + iVar22);
  texPacket[0xad] =
       uVar24 >> 7 & 0x1f | uVar35 >> 3 & 0x400000 | (uVar24 & 0x70) << 5 | (uVar24 & 0xe) << 0xb |
       uVar35 >> 0xe & 0x38000 | uVar35 >> 8 & 0x1c0000;
  uVar24 = *(uint *)(&DAT_001d9f48 + iVar22);
  if (2.1474836e+09 <= fVar4) {
    fctiwzSlot5 = (longlong)(int)(fVar4 - 2.1474836e+09);
    iVar22 = (int)(fVar4 - 2.1474836e+09) + -0x80000000;
  }
  else {
    iVar22 = (int)fVar4;
    fctiwzSlot4 = (longlong)iVar22;
  }
  if (2.1474836e+09 <= fVar5) {
    fctiwzSlot7 = (longlong)(int)(fVar5 - 2.1474836e+09);
    iVar20 = (int)(fVar5 - 2.1474836e+09) + -0x80000000;
  }
  else {
    iVar20 = (int)fVar5;
    fctiwzSlot6 = (longlong)iVar20;
  }
  texPacket[0x9f] = iVar32;
  texPacket[0xaf] =
       ((int)uStack_248 >> (uVar24 & 7)) - 1U & 0x3fff | (iVar22 + -1) * 0x10 & 0xffff8000U |
       (iVar20 + -1) * 0x20 & 0xffff0000U;
  texPacket[0xa5] = (srcData - sourceBase) * 0x20 | texPacket[0xa5] & 0x1f;
  storageRecord = texture[0xd];
  if ((storageRecord != 0) && ((*(byte *)(storageRecord + 0x15) & 4) != 0)) {
    uVar44 = level - *(byte *)(texture[0xc] + 0x69);
    if ((*(byte *)(storageRecord + 0x15) & 0x18) == 0) {
      iVar20 = 1;
      iVar22 = 0x100;
    }
    else {
      iVar20 = 1 << (*(uint *)(((unsigned char *)0x00003544) +
                              (int)(pcStack_a8 + (uint)*(byte *)(texture + 0xe) * 0x24)) >> 0x1c & 3
                    );
      iVar22 = 0x20 / iVar20 << 3;
    }
    if ((iVar22 <= *(int *)(*texture + 0xc) >> (uVar44 & 0x3f)) &&
       (iVar22 = 1, iVar20 << 3 <= (int)(uint)*(ushort *)(*texture + 0x16) >> (uVar44 & 0x3f)))
    goto LAB_000371ac;
  }
  iVar22 = 0;
LAB_000371ac:
  if (storageRecord != 0) {
    uVar44 = (*(byte *)(storageRecord + 0x15) & 0x18) << 0xe;
  }
  else {
    uVar44 = 0;
  }
  uVar21 = texPacket[0x8f];
  texPacket[0xa1] =
       uVar44 | uVar26 & 0x3ffe | iVar22 << 0x10 | *(uint *)(levelRecordB + 0x18) >> 0xb & 0x180000 |
       (*(uint *)(levelRecordB + 0x18) & 0x3c00) << 0xb;
  uVar26 = (*(uint *)(levelRecordB + 0x18) & 0x18) << 5;
  texPacket[0x8f] = uVar26 | uVar21 & 0xfffffcff;
  uVar44 = (*(uint *)(levelRecordB + 0x18) & 6) << 9;
  texPacket[0x8f] = uVar44 | uVar26 | uVar21 & 0xfffff0ff;
  uVar24 = *(uint *)(levelRecordB + 0x1c) >> 0x12 & 0x3000;
  texPacket[0x8f] = uVar24 | uVar44 | uVar26 | uVar21 & 0xffffc0ff;
  uVar35 = *(uint *)(levelRecordB + 0x1c) >> 0xe & 0xc000;
  texPacket[0x8f] = uVar35 | uVar24 | uVar44 | uVar26 | uVar21 & 0xffff00ff;
  texPacket[0x8f] =
       *(uint *)(levelRecordB + 0x18) >> 5 & 0x1f |
       uVar35 | uVar24 | uVar44 | uVar26 | uVar21 & 0xffff00e0;
  sVar8 = *(short *)(textureState + 2);
  if (((sVar8 != 0x1908) && (sVar8 != 0x1906)) && (sVar8 != 0x190a)) {
    texPacket[0x5b] = texPacket[0x5b] & 0xfffe3fff | 0x18000;
  }
  texPacket[0xb8] = levelWidth - 1 & 0x1fff | (uVar42 - 1) * 0x2000 & 0x3ffe000;
  if ((*(uint *)(levelRecordB + 0x20) & 0x400000) != 0) {
    texPacket[0x23] = 0;
  }
  packetEndB = texPacket + 0xce;
  texPacket[199] = ((unsigned char *)0x00001087U);
  texPacket[0xc2] = 0x31080;
  texPacket[0xc6] = (1.0 / fVar5) * fVar16;
  iVar43 = (int)((fVar13 - fVar6) * 6.0);
  fctiwzSlot8 = (longlong)iVar43;
  texPacket[0xc5] = (fVar13 + xoffsetF) * (1.0 / fVar4);
  texPacket[0xc3] = fVar15 * (1.0 / fVar4);
  texPacket[0xc4] = (fVar14 + yoffsetF) * (1.0 / fVar5);
  uVar26 = (uint)(int)((fVar14 - fVar7) * 6.0);
  fctiwzSlot9 = (longlong)(int)uVar26;
  texPacket[0xca] = 0x10031;
  texPacket[0xc9] = 0xc0033500;
  texPacket[0xcb] = (fVar6 + fVar13) * 0.5;
  texPacket[0xcc] = (fVar7 + fVar14) * 0.5;
  texPacket[0xcd] = 0;
  texPacket[200] = iVar43 << 0x10 | uVar26;
  texPacket[1] = (int)packetEndB - (int)puVar29 >> 2;
  lastHeader = *(uint **)(ctx + GLD_lastHeader);
  *lastHeader = (int)packetEndB - (int)lastHeader >> 2 | *lastHeader;
  *(undefined4 **)(ctx + GLD_lastHeader) = packetEndB;
  texPacket[0xcf] = 0;
  texPacket[0xce] = 0x33000000;
  texPacket[0xd0] = ((unsigned char *)0x00001393U);
  texPacket[0xd1] = 10;
  texPacket[0xd2] = ((unsigned char *)0x000013c6U);
  texPacket[0xd3] = 3;
  texPacket[0xd4] = 0x5c8;
  texPacket[0xd5] = 0x20000;
  texPacket[0xd6] = ((unsigned char *)0x000010eaU);
  sc_edgerule = *(undefined4 *)(ctx + GLD_sc_edgerule);
  texPacket[0xd8] = ((unsigned char *)0x000010faU);
  texPacket[0xd7] = sc_edgerule;
  sc_screendoor = *(undefined4 *)(ctx + GLD_sc_screendoor);
  texPacket[0xda] = 0xc0001000;
  texPacket[0xdc] = 0x11004;
  texPacket[0xd9] = sc_screendoor;
  texPacket[0xdd] = *(undefined4 *)(ctx + GLD_gb_mspos0);
  gb_mspos1 = *(undefined4 *)(ctx + GLD_gb_mspos1);
  texPacket[0xdf] = ((unsigned char *)0x00001008U);
  texPacket[0xde] = gb_mspos1;
  gb_aa_config = *(undefined4 *)(ctx + GLD_gb_aa_config);
  texPacket[0xe1] = ((unsigned char *)0x000010e9U);
  texPacket[0xe0] = gb_aa_config;
  sc_hyperz_en = *(undefined4 *)(ctx + GLD_sc_hyperz_en);
  texPacket[0xe3] = ((unsigned char *)0x000013c7U);
  texPacket[0xe2] = sc_hyperz_en;
  zb_bw_cntl = *(undefined4 *)(ctx + GLD_zb_bw_cntl);
  texPacket[0xe5] = ((unsigned char *)0x000013c1U);
  texPacket[0xe4] = zb_bw_cntl;
  zb_zstencilcntl = *(undefined4 *)(ctx + GLD_zb_zstencilcntl);
  texPacket[0xe7] = 0x850;
  texPacket[0xe6] = zb_zstencilcntl;
  vap_cntl_status = *(undefined4 *)(ctx + GLD_vap_cntl_status);
  texPacket[0xe9] = 0x887;
  texPacket[0xe8] = vap_cntl_status;
  vap_clip_cntl = *(undefined4 *)(ctx + GLD_vap_clip_cntl);
  texPacket[0x18b] = 0x82c;
  texPacket[0xea] = vap_clip_cntl;
  vap_vte_cntlB = *(undefined4 *)(GLD_vap_vte_cntl + ctx);
  texPacket[0xeb] = ((unsigned char *)0x000010aeU);
  texPacket[0x18c] = vap_vte_cntlB;
  su_cull_mode = *(undefined4 *)(ctx + GLD_su_cull_mode);
  texPacket[0xed] = ((unsigned char *)0x00001394U);
  texPacket[0xec] = su_cull_mode;
  rb3d_dither_ctl = *(undefined4 *)(ctx + GLD_rb3d_dither_ctl);
  texPacket[0xef] = ((unsigned char *)0x00001380U);
  texPacket[0xf1] = ((unsigned char *)0x00001002U);
  texPacket[0xf0] = 0;
  texPacket[0xee] = rb3d_dither_ctl;
  texPacket[0xf2] = *(undefined4 *)(ctx + GLD_gb_enable);
  gb_enable = *(undefined4 *)(ctx + GLD_gb_enable);
  texPacket[0xf3] = 0x824;
  texPacket[0xf2] = gb_enable;
  vap_out_vtx_fmt_0 = *(undefined4 *)(ctx + GLD_vap_out_vtx_fmt_0);
  texPacket[0xf5] = 0x825;
  texPacket[0xf4] = vap_out_vtx_fmt_0;
  vap_out_vtx_fmt_1 = *(undefined4 *)(ctx + GLD_vap_out_vtx_fmt_1);
  texPacket[0xf7] = 0x82d;
  texPacket[0xf6] = vap_out_vtx_fmt_1;
  vap_vtx_size = *(undefined4 *)(ctx + GLD_vap_vtx_size);
  texPacket[0xf9] = 0x854;
  texPacket[0xf8] = vap_vtx_size;
  vap_prog_stream_cntl_0_ptr = **(undefined4 **)(ctx + GLD_vap_prog_stream_cntl_0_ptr);
  texPacket[0xfb] = 0x878;
  texPacket[0xfa] = vap_prog_stream_cntl_0_ptr;
  vap_prog_stream_cntl_ext_0_ptr = **(undefined4 **)(ctx + GLD_vap_prog_stream_cntl_ext_0_ptr);
  texPacket[0xfd] = ((unsigned char *)0x000013c0U);
  texPacket[0xfc] = vap_prog_stream_cntl_ext_0_ptr;
  zb_cntl = *(undefined4 *)(ctx + GLD_zb_cntl);
  texPacket[0xff] = ((unsigned char *)0x000012f0U);
  texPacket[0xfe] = zb_cntl;
  fg_fog_blend = *(uint *)(ctx + GLD_fg_fog_blend);
  texPacket[0x100] = fg_fog_blend;
  if ((*(uint *)(((unsigned char *)0x0000352c) +
                (int)(pcStack_a8 + (uint)(byte)((unsigned char *)GLD_colorFormatIndex)[ctx] * 0x24 + 0x18)) & 0x8000) ==
      0) {
    texPacket[0x100] = fg_fog_blend & 0xfffffffe;
  }
  texPacket[0x101] = ((unsigned char *)0x000012f5U);
  fg_alpha_func = *(uint *)(ctx + GLD_fg_alpha_func);
  texPacket[0x102] = fg_alpha_func;
  uVar26 = *(uint *)(((unsigned char *)0x0000352c) +
                    (int)(pcStack_a8 + (uint)(byte)((unsigned char *)GLD_colorFormatIndex)[ctx] * 0x24 + 0x18)) & 0x8000
  ;
  if (uVar26 == 0) {
    texPacket[0x102] = fg_alpha_func & 0xfffff7ff;
  }
  texPacket[0x103] = ((unsigned char *)0x000010a2U);
  ga_poly_mode = *(undefined4 *)(ctx + GLD_ga_poly_mode);
  texPacket[0x105] = ((unsigned char *)0x00001381U);
  texPacket[0x104] = ga_poly_mode;
  uVar44 = *(uint *)(ctx + GLD_rb3d_blendcntl);
  texPacket[0x106] = uVar44;
  if ((*(uint *)(((unsigned char *)0x0000352c) +
                (int)(pcStack_a8 + (uint)(byte)((unsigned char *)GLD_colorFormatIndex)[ctx] * 0x24 + 0x18)) & 0x4000) ==
      0) {
    texPacket[0x106] = uVar44 & 0xfffffffc;
  }
  texPacket[0x107] = ((unsigned char *)0x0000109eU);
  uVar31 = 0x110f8;
  uVar28 = *(undefined4 *)(ctx + 0x1d6c);
  texPacket[0x109] = ((unsigned char *)0x00001096U);
  texPacket[0x108] = uVar28;
  ga_color_control = *(undefined4 *)(ctx + GLD_ga_color_control);
  texPacket[0x10b] = ((unsigned char *)0x00001041U);
  texPacket[0x108] = ga_color_control;
  tx_enable = *(undefined4 *)(ctx + GLD_tx_enable);
  texPacket[0x10d] = ((unsigned char *)0x00001046U);
  texPacket[0x10c] = tx_enable;
  gb_ps3_enable = *(undefined4 *)(ctx + GLD_gb_ps3_enable);
  texPacket[0x10f] = ((unsigned char *)0x00001094U);
  texPacket[0x14e] = 2;
  texPacket[0x129] = 0xc0221000;
  texPacket[0x14d] = ((unsigned char *)0x00001180U);
  texPacket[0x127] = ((unsigned char *)0x00001095U);
  texPacket[0x151] = ((unsigned char *)0x00001181U);
  texPacket[0x111] = ((unsigned char *)0x00001095U);
  texPacket[0x10e] = gb_ps3_enable;
  texPacket[0x113] = ((unsigned char *)0x00001095U);
  texPacket[0x115] = ((unsigned char *)0x00001095U);
  texPacket[0x117] = ((unsigned char *)0x00001095U);
  texPacket[0x119] = ((unsigned char *)0x00001095U);
  texPacket[0x11b] = ((unsigned char *)0x00001095U);
  texPacket[0x11d] = ((unsigned char *)0x00001095U);
  texPacket[0x11f] = ((unsigned char *)0x00001095U);
  texPacket[0x121] = ((unsigned char *)0x00001095U);
  texPacket[0x123] = ((unsigned char *)0x00001095U);
  texPacket[0x125] = ((unsigned char *)0x00001095U);
  texPacket[0x110] = 0;
  texPacket[0x14f] = ((unsigned char *)0x00001189U);
  texPacket[0x155] = ((unsigned char *)0x0000118eU);
  texPacket[0x153] = ((unsigned char *)0x0000118dU);
  texPacket[0x157] = ((unsigned char *)0x0000118cU);
  texPacket[0x159] = ((unsigned char *)0x000011a9U);
  us_out_fmt_0 = *(undefined4 *)(ctx + GLD_us_out_fmt_0);
  texPacket[0x15b] = ((unsigned char *)0x000011aaU);
  texPacket[0x15a] = us_out_fmt_0;
  us_out_fmt_1 = *(undefined4 *)(ctx + GLD_us_out_fmt_1);
  texPacket[0x15d] = ((unsigned char *)0x000011abU);
  texPacket[0x15c] = us_out_fmt_1;
  us_out_fmt_2 = *(undefined4 *)(ctx + GLD_us_out_fmt_2);
  texPacket[0x15f] = ((unsigned char *)0x000011acU);
  texPacket[0x15e] = us_out_fmt_2;
  us_out_fmt_3 = *(undefined4 *)(ctx + GLD_us_out_fmt_3);
  texPacket[0x161] = ((unsigned char *)0x000010c0U);
  texPacket[0x160] = us_out_fmt_3;
  rs_count = *(undefined4 *)(ctx + GLD_rs_count);
  texPacket[0x163] = ((unsigned char *)0x000010c1U);
  texPacket[0x165] = ((unsigned char *)0x000010c8U);
  texPacket[0x167] = ((unsigned char *)0x0000101dU);
  texPacket[0x162] = rs_count;
  rs_ip_0 = *(undefined4 *)(ctx + GLD_rs_ip_0);
  texPacket[0x169] = ((unsigned char *)0x0000138aU);
  texPacket[0x16b] = ((unsigned char *)0x0000138eU);
  texPacket[0x170] = 0;
  texPacket[0x16d] = ((unsigned char *)0x00001040U);
  texPacket[0x16a] = 0;
  texPacket[0x16c] = 0;
  texPacket[0x16e] = 0;
  texPacket[0x168] = rs_ip_0;
  texPacket[0x16f] = ((unsigned char *)0x00001150U);
  texPacket[0x171] = ((unsigned char *)0x00001100U);
  tx_filter0 = *(undefined4 *)(ctx + GLD_tx_filter0);
  texPacket[0x173] = ((unsigned char *)0x00001110U);
  texPacket[0x172] = tx_filter0;
  texPacket[0x174] = *(undefined4 *)(ctx + GLD_tx_filter1);
  texPacket[0x175] = ((unsigned char *)0x00001120U);
  tx_format0 = *(undefined4 *)(ctx + GLD_tx_format0);
  texPacket[0x177] = ((unsigned char *)0x00001130U);
  texPacket[0x176] = tx_format0;
  tx_format1 = *(undefined4 *)(ctx + GLD_tx_format1);
  texPacket[0x179] = ((unsigned char *)0x00001140U);
  texPacket[0x178] = tx_format1;
  tx_format2 = *(undefined4 *)(ctx + GLD_tx_format2);
  texPacket[0x17b] = ((unsigned char *)0x000010f4U);
  texPacket[0x17c] = 0xaaaa;
  texPacket[0x17d] = ((unsigned char *)0x00001383U);
  texPacket[0x17a] = tx_format2;
  rb3d_color_channel_mask = *(undefined4 *)(ctx + GLD_rb3d_color_channel_mask);
  texPacket[0x17f] = ((unsigned char *)0x00001386U);
  texPacket[0x17e] = rb3d_color_channel_mask;
  rb3d_ropcntl = *(undefined4 *)(ctx + GLD_rb3d_ropcntl);
  texPacket[0x181] = 0x110f8;
  texPacket[0x180] = rb3d_ropcntl;
  texPacket[0x182] = *(undefined4 *)(ctx + GLD_sc_scissor0);
  sc_scissor1 = *(undefined4 *)(ctx + GLD_sc_scissor1);
  texPacket[0x184] = ((unsigned char *)0x00001087U);
  texPacket[0x183] = sc_scissor1;
  ga_point_size = *(undefined4 *)(ctx + GLD_ga_point_size);
  texPacket[0x186] = 0x31080;
  texPacket[0x185] = ga_point_size;
  texPacket[0x187] = *(undefined4 *)(ctx + GLD_ga_point_s0);
  texPacket[0x188] = *(undefined4 *)(ctx + GLD_ga_point_t0);
  texPacket[0x189] = *(undefined4 *)(ctx + GLD_ga_point_s1);
  texPacket[0x18a] = *(undefined4 *)(ctx + GLD_ga_point_t1);
  FUN_0004c100(texPacket + 0xd0,commandStreamB);
  uVar28 = ((int (*)())FUN_000308c0)(ctx,texPacket + 0x18d);
  *(undefined4 *)(ctx + GLD_streamCurrent) = uVar28;
  (**(code **)(ctx + GLD_streamSetCurrent))(commandStreamB,uVar28);
  _pthread_mutex_unlock(*(undefined4 *)(ctx + GLD_mutex));
  if (((*(uint *)(texture[0xc] + 0x48) & 0x8000) != 0) &&
     (level == *(byte *)(texture[0xc] + 0x5e))) {
    ((int (*)())glGenerateMipmap_impl)(ctx,texture,face,uVar26,uVar31);
    return 1;
  }
  return 1;
}

/* gld_testRendererAvailable @ 0x39100 (188 bytes) */
int gld_testRendererAvailable(rendererIndex)
  int rendererIndex;
{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_38;
  undefined4 local_34;
  undefined1 auStack_30 [44];
  
  local_38 = 0;
  local_34 = 3;
  iVar2 = _IOServiceOpen(*(undefined4 *)(rendererIndex * 4 + *(int *)(PTR_DAT_001e88ac + 8)),
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

/* gldRendererFamilyString @ 0x391d0 (28 bytes) */
int gldRendererFamilyString()
{
  return "ATIR500";
}

/* _gldGetVersion @ 0x391f0 (84 bytes) */
int _gldGetVersion(majorOut, minorOut, patchOut, buildOut)
  undefined4 *majorOut;
  undefined4 *minorOut;
  undefined4 *patchOut;
  undefined4 *buildOut;
{
  if (*(int *)PTR_DAT_001e88ac == 0) {
    return 0;
  }
  *majorOut = 2;
  *minorOut = 4;
  *patchOut = 0xb;
  *buildOut = 0x1900;
  return 1;
}

/* _gldGetString @ 0x39250 (204 bytes) */
int _gldGetString(ctx, name)
  int ctx;
  undefined4 name;
{
  uint chipClass;
  
  switch(name) {
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
  chipClass = *(uint *)(ctx + GLD_hwConfig0) & 0x7ff00000;
  if (chipClass == 0x100000) {
    return "ATI Radeon X1800 OpenGL Engine";
  }
  if (chipClass != 0x200000) {
    if (chipClass != 0x800000) {
      return "ATI Radeon X1000 OpenGL Engine";
    }
    return "ATI Radeon X1900 OpenGL Engine";
  }
  return "ATI Radeon X1600 OpenGL Engine";
}

/* gldPrimInlineLineStrip @ 0x39330 (724 bytes) */
void gldPrimInlineLineStrip(int ctx,uint data,undefined4 elementCount,undefined4 primFlag,undefined4 extraArg4,undefined4 extraArg5,double staleFprArg1,double staleFprArg2,double staleFprArg3,double staleFprArg4,double staleFprArg5,double staleFprArg6,double staleFprArg7,double staleFprArg8,double staleFprArg9)
{
  undefined4 vap_vte_cntl;
  undefined4 element1;
  undefined4 element2;
  undefined4 element3;
  undefined4 weightWord;
  int unitCount;
  undefined4 *ringStart;
  undefined4 *ringCursor;
  undefined4 topology;
  uint loopIndex;
  uint dataEnd;
  int vertexArrayInfo;
  undefined4 *weightCursor;
  int programState;
  int vertexStride;
  double staleStackArg_ffffffa8;
  undefined4 staleArgR9;
  
  topology = 3;
  unitCount = ((uint (*)())gld_prepareDrawCount)(ctx,primFlag,3,elementCount,extraArg4,extraArg5,staleArgR9,staleFprArg1,staleFprArg2,staleFprArg3,staleFprArg4
                       ,staleFprArg5,staleFprArg6,staleFprArg7,staleFprArg8,staleStackArg_ffffffa8);
  if (unitCount != 0) {
    programState = *(int *)(ctx + 0x29e8);
    vertexArrayInfo = *(int *)(**(int **)(ctx + 0x1cc) + 4);
    vertexStride = *(int *)(vertexArrayInfo + 0x20);
    ringStart = (undefined4 *)
             (**(code **)(ctx + 0x2998))
                       (ctx + 0x240,
                        vertexStride * unitCount * 5 + unitCount * 2 +
                        (*(int *)(ctx + 0x267c) + 1U & 0xfffffffe) + 0x16,topology,elementCount,extraArg4,
                        unitCount * 2,vertexArrayInfo,programState);
    *(undefined4 **)(ctx + 0x298c) = ringStart;
    if (*(code **)(ctx + 0x2680) != 0x00001e24 + ctx) {
      *(code **)(ctx + 0x2680) = 0x00001e24 + ctx;
      *(int *)(ctx + 0x2684) = ctx + 0x1e44;
      *(undefined4 *)(0x000026c8 + ctx + 4) = *(undefined4 *)(ctx + 0x1ee4);
      ringStart = (undefined4 *)gld_emitVapStreamControl(ctx,ringStart);
    }
    if (*(char *)(ctx + 0x2a42) == '\0') {
      *ringStart = 0x5c8;
      ringStart[1] = 0x10000000;
      ringStart = ringStart + 2;
      *(undefined1 *)(ctx + 0x2a42) = 1;
    }
    ringCursor = ringStart + 4;
    *ringStart = 0x82c;
    dataEnd = data + unitCount * vertexStride * 4 * 4;
    vap_vte_cntl = *(undefined4 *)(0x00001dc4 + ctx);
    ringStart[2] = 0x821;
    ringStart[3] = 3;
    ringStart[1] = vap_vte_cntl;
    unitCount = *(int *)(programState + 0x2c);
    *(undefined1 *)(ctx + 0x2a5e) = 1;
    if (data < dataEnd) {
      vertexArrayInfo = vertexStride + -1;
      loopIndex = 0;
      do {
        *ringCursor = 0x917;
        if (loopIndex < 0x20) {
          ringCursor[1] = (uint)((1 << (loopIndex & 0x3f) &
                             **(uint **)(((unsigned char *)0x00002d48) + *(int *)(ctx + 0x10) + 8)) != 0);
        }
        else if (loopIndex < 0x40) {
          ringCursor[1] = (uint)((1 << (loopIndex - 0x20 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(ctx + 0x10) + 8) + 4
                                      )) != 0);
        }
        else if (loopIndex < 0x60) {
          ringCursor[1] = (uint)((1 << (loopIndex - 0x40 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(ctx + 0x10) + 8) + 8
                                      )) != 0);
        }
        else {
          ringCursor[1] = (uint)((1 << (loopIndex - 0x60 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(ctx + 0x10) + 8) +
                                      0xc)) != 0);
        }
        ringCursor = ringCursor + 2;
        if (-1 < vertexArrayInfo) {
          weightCursor = (undefined4 *)(unitCount + vertexArrayInfo * 4);
          ringStart = (undefined4 *)(data + vertexArrayInfo * 0x10);
          programState = vertexStride;
          do {
            topology = *ringStart;
            element1 = ringStart[1];
            element2 = ringStart[2];
            element3 = ringStart[3];
            ringStart = ringStart + -4;
            weightWord = *weightCursor;
            weightCursor = weightCursor + -1;
            ringCursor[1] = topology;
            ringCursor[2] = element1;
            ringCursor[3] = element2;
            *ringCursor = weightWord;
            ringCursor[4] = element3;
            ringCursor = ringCursor + 5;
            programState = programState + -1;
          } while (programState != 0);
        }
        data = data + vertexStride * 0x10;
        loopIndex = loopIndex + 1;
      } while (data < dataEnd);
    }
    *ringCursor = 0x92b;
    ringCursor[3] = 0;
    ringCursor[2] = ((unsigned char *)0x00001393U);
    ringCursor[1] = 0;
    *(undefined4 **)(ctx + 0x298c) = ringCursor + 4;
                    
                    
    (**(code **)(ctx + 0x299c))(ctx + 0x240,ringCursor + 4);
    return;
  }
  return;
}

/* gldPrimInlineTriangleFan @ 0x39610 (1092 bytes) */
void gldPrimInlineTriangleFan(int ctx,uint fanCenterData,uint data,undefined4 elementCount,undefined4 extraArg4,undefined4 extraArg5,double staleFprArg1,double staleFprArg2,double staleFprArg3,double staleFprArg4,double staleFprArg5,double staleFprArg6,double staleFprArg7,double staleFprArg8,double staleFprArg9)
{
  undefined4 *elementPtr;
  int innerLeft2;
  int weightTable;
  int strideBytes;
  int weightTableRest;
  int unitCount;
  int lastElementRest;
  undefined4 vap_vte_cntl;
  undefined4 element1;
  undefined4 element2;
  undefined4 element3;
  int lastElementCenter;
  undefined4 weightWord;
  undefined4 *ringStart;
  undefined4 *ringCursor;
  undefined4 topology;
  uint rangeEnd;
  int programState;
  uint loopIndex;
  int allocWords;
  undefined4 *weightCursor;
  int vertexArrayInfo;
  int vertexStride;
  int innerLeft;
  double staleStackArg_ffffff98;
  undefined4 staleArgR9;
  
  topology = 6;
  unitCount = ((uint (*)())gld_prepareDrawCount)(ctx,0,6,elementCount,extraArg4,extraArg5,staleArgR9,staleFprArg1,staleFprArg2,staleFprArg3,staleFprArg4,
                       staleFprArg5,staleFprArg6,staleFprArg7,staleFprArg8,staleStackArg_ffffff98);
  if (unitCount != 0) {
    programState = *(int *)(ctx + 0x29e8);
    vertexArrayInfo = *(int *)(**(int **)(ctx + 0x1cc) + 4);
    vertexStride = *(int *)(vertexArrayInfo + 0x20);
    allocWords = vertexStride * (unitCount * 5 + 5);
    ringStart = (undefined4 *)
             (**(code **)(ctx + 0x2998))
                       (ctx + 0x240,
                        unitCount * 2 + allocWords + (*(int *)(ctx + 0x267c) + 1U & 0xfffffffe) + 0x18,
                        topology,elementCount,extraArg4,programState,allocWords,vertexArrayInfo);
    *(undefined4 **)(ctx + 0x298c) = ringStart;
    if (*(code **)(ctx + 0x2680) != 0x00001e24 + ctx) {
      *(code **)(ctx + 0x2680) = 0x00001e24 + ctx;
      *(int *)(ctx + 0x2684) = ctx + 0x1e44;
      *(undefined4 *)(0x000026c8 + ctx + 4) = *(undefined4 *)(ctx + 0x1ee4);
      ringStart = (undefined4 *)gld_emitVapStreamControl(ctx,ringStart);
    }
    if (*(char *)(ctx + 0x2a42) == '\0') {
      *ringStart = 0x5c8;
      ringStart[1] = 0x10000000;
      ringStart = ringStart + 2;
      *(undefined1 *)(ctx + 0x2a42) = 1;
    }
    strideBytes = vertexStride * 0x10;
    ringCursor = ringStart + 4;
    *ringStart = 0x82c;
    rangeEnd = fanCenterData + strideBytes;
    vap_vte_cntl = *(undefined4 *)(0x00001dc4 + ctx);
    ringStart[2] = 0x821;
    ringStart[3] = 5;
    ringStart[1] = vap_vte_cntl;
    weightTable = *(int *)(programState + 0x2c);
    *(undefined1 *)(ctx + 0x2a5e) = 1;
    if (fanCenterData < rangeEnd) {
      lastElementCenter = vertexStride + -1;
      loopIndex = 0;
      do {
        *ringCursor = 0x917;
        if (loopIndex < 0x20) {
          ringCursor[1] = (uint)((1 << (loopIndex & 0x3f) &
                             **(uint **)(((unsigned char *)0x00002d48) + *(int *)(ctx + 0x10) + 8)) != 0);
        }
        else if (loopIndex < 0x40) {
          ringCursor[1] = (uint)((1 << (loopIndex - 0x20 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(ctx + 0x10) + 8) + 4
                                      )) != 0);
        }
        else if (loopIndex < 0x60) {
          ringCursor[1] = (uint)((1 << (loopIndex - 0x40 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(ctx + 0x10) + 8) + 8
                                      )) != 0);
        }
        else {
          ringCursor[1] = (uint)((1 << (loopIndex - 0x60 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(ctx + 0x10) + 8) +
                                      0xc)) != 0);
        }
        ringCursor = ringCursor + 2;
        if (-1 < lastElementCenter) {
          weightCursor = (undefined4 *)(weightTable + lastElementCenter * 4);
          elementPtr = (undefined4 *)(fanCenterData + lastElementCenter * 0x10);
          innerLeft = vertexStride;
          do {
            topology = *elementPtr;
            element1 = elementPtr[1];
            element2 = elementPtr[2];
            element3 = elementPtr[3];
            elementPtr = elementPtr + -4;
            weightWord = *weightCursor;
            weightCursor = weightCursor + -1;
            ringCursor[1] = topology;
            ringCursor[2] = element1;
            ringCursor[3] = element2;
            *ringCursor = weightWord;
            ringCursor[4] = element3;
            ringCursor = ringCursor + 5;
            innerLeft = innerLeft + -1;
          } while (innerLeft != 0);
        }
        fanCenterData = fanCenterData + strideBytes;
        loopIndex = loopIndex + 1;
      } while (fanCenterData < rangeEnd);
    }
    weightTableRest = *(int *)(programState + 0x2c);
    *(undefined1 *)(ctx + 0x2a5e) = 1;
    rangeEnd = data + vertexStride * 4 * unitCount * 4;
    if (data < rangeEnd) {
      lastElementRest = vertexStride + -1;
      loopIndex = 1;
      do {
        *ringCursor = 0x917;
        if (loopIndex < 0x20) {
          ringCursor[1] = (uint)((1 << (loopIndex & 0x3f) &
                             **(uint **)(((unsigned char *)0x00002d48) + *(int *)(ctx + 0x10) + 8)) != 0);
        }
        else if (loopIndex < 0x40) {
          ringCursor[1] = (uint)((1 << (loopIndex - 0x20 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(ctx + 0x10) + 8) + 4
                                      )) != 0);
        }
        else if (loopIndex < 0x60) {
          ringCursor[1] = (uint)((1 << (loopIndex - 0x40 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(ctx + 0x10) + 8) + 8
                                      )) != 0);
        }
        else {
          ringCursor[1] = (uint)((1 << (loopIndex - 0x60 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(ctx + 0x10) + 8) +
                                      0xc)) != 0);
        }
        ringCursor = ringCursor + 2;
        if (-1 < lastElementRest) {
          weightCursor = (undefined4 *)(weightTableRest + lastElementRest * 4);
          elementPtr = (undefined4 *)(data + lastElementRest * 0x10);
          innerLeft2 = vertexStride;
          do {
            topology = *elementPtr;
            element1 = elementPtr[1];
            element2 = elementPtr[2];
            element3 = elementPtr[3];
            elementPtr = elementPtr + -4;
            weightWord = *weightCursor;
            weightCursor = weightCursor + -1;
            ringCursor[1] = topology;
            ringCursor[2] = element1;
            ringCursor[3] = element2;
            *ringCursor = weightWord;
            ringCursor[4] = element3;
            ringCursor = ringCursor + 5;
            innerLeft2 = innerLeft2 + -1;
          } while (innerLeft2 != 0);
        }
        data = data + strideBytes;
        loopIndex = loopIndex + 1;
      } while (data < rangeEnd);
    }
    *ringCursor = 0x92b;
    ringCursor[3] = 0;
    ringCursor[2] = ((unsigned char *)0x00001393U);
    ringCursor[1] = 0;
    *(undefined4 **)(ctx + 0x298c) = ringCursor + 4;
                    
                    
    (**(code **)(ctx + 0x299c))(ctx + 0x240,ringCursor + 4);
    return;
  }
  return;
}

/* gldPrimInlineTriangles @ 0x39a60 (724 bytes) */
void gldPrimInlineTriangles(int ctx,uint data,undefined4 elementCount,undefined4 extraArg3,undefined4 extraArg4,undefined4 extraArg5,double staleFprArg1,double staleFprArg2,double staleFprArg3,double staleFprArg4,double staleFprArg5,double staleFprArg6,double staleFprArg7,double staleFprArg8,double staleFprArg9)
{
  undefined4 element1;
  undefined4 element2;
  undefined4 element3;
  undefined4 weightWord;
  int unitCount;
  undefined4 *ringStart;
  undefined4 *ringCursor;
  undefined4 topology;
  uint slotIndex;
  uint dataEnd;
  int vertexArrayInfo;
  undefined4 *weightCursor;
  int programState;
  int vertexStride;
  double staleStackArg_ffffffa8;
  undefined4 staleArgR9;
  
  topology = 4;
  unitCount = ((uint (*)())gld_prepareDrawCount)(ctx,0,4,elementCount,extraArg4,extraArg5,staleArgR9,staleFprArg1,staleFprArg2,staleFprArg3,staleFprArg4,
                       staleFprArg5,staleFprArg6,staleFprArg7,staleFprArg8,staleStackArg_ffffffa8);
  if (unitCount != 0) {
    programState = *(int *)(ctx + 0x29e8);
    vertexArrayInfo = *(int *)(**(int **)(ctx + GLD_currentProgram) + 4);
    vertexStride = *(int *)(vertexArrayInfo + 0x20);
    ringStart = (undefined4 *)
             (**(code **)(ctx + GLD_streamAllocate))
                       (ctx + GLD_commandStream,
                        vertexStride * unitCount * 5 + unitCount * 2 +
                        (*(int *)(ctx + 0x267c) + 1U & 0xfffffffe) + 0x16,topology,elementCount,extraArg4,
                        unitCount * 2,vertexArrayInfo,programState);
    *(undefined4 **)(ctx + GLD_streamCurrent) = ringStart;
    if (*(code **)(ctx + GLD_vap_prog_stream_cntl_0_ptr) != 0x00001e24 + ctx) {
      *(code **)(ctx + GLD_vap_prog_stream_cntl_0_ptr) = 0x00001e24 + ctx;
      *(int *)(ctx + GLD_vap_prog_stream_cntl_ext_0_ptr) = ctx + 0x1e44;
      *(undefined4 *)(0x000026c8 + ctx + GLD_connect) = *(undefined4 *)(ctx + 0x1ee4);
      ringStart = (undefined4 *)gld_emitVapStreamControl(ctx,ringStart);
    }
    if (*(char *)(ctx + GLD_needsWaitIdle) == '\0') {
      *ringStart = 0x5c8;
      ringStart[1] = 0x10000000;
      ringStart = ringStart + 2;
      *(undefined1 *)(ctx + GLD_needsWaitIdle) = 1;
    }
    ringCursor = ringStart + 4;
    *ringStart = 0x82c;
    dataEnd = data + unitCount * vertexStride * 4 * 4;
    topology = *(undefined4 *)(GLD_vap_vte_cntl + ctx);
    ringStart[2] = 0x821;
    ringStart[3] = 4;
    ringStart[1] = topology;
    unitCount = *(int *)(programState + 0x2c);
    *(undefined1 *)(ctx + GLD_inDrawPixels) = 1;
    if (data < dataEnd) {
      vertexArrayInfo = vertexStride + -1;
      slotIndex = 0;
      do {
        *ringCursor = 0x917;
        if (slotIndex < 0x20) {
          ringCursor[1] = (uint)((1 << (slotIndex & 0x3f) &
                             **(uint **)(((unsigned char *)0x00002d48) + *(int *)(ctx + GLD_engineState) + 8)) != 0);
        }
        else if (slotIndex < 0x40) {
          ringCursor[1] = (uint)((1 << (slotIndex - 0x20 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(ctx + GLD_engineState) + 8) + 4
                                      )) != 0);
        }
        else if (slotIndex < 0x60) {
          ringCursor[1] = (uint)((1 << (slotIndex - 0x40 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(ctx + GLD_engineState) + 8) + 8
                                      )) != 0);
        }
        else {
          ringCursor[1] = (uint)((1 << (slotIndex - 0x60 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(ctx + GLD_engineState) + 8) +
                                      0xc)) != 0);
        }
        ringCursor = ringCursor + 2;
        if (-1 < vertexArrayInfo) {
          weightCursor = (undefined4 *)(unitCount + vertexArrayInfo * 4);
          ringStart = (undefined4 *)(data + vertexArrayInfo * 0x10);
          programState = vertexStride;
          do {
            topology = *ringStart;
            element1 = ringStart[1];
            element2 = ringStart[2];
            element3 = ringStart[3];
            ringStart = ringStart + -4;
            weightWord = *weightCursor;
            weightCursor = weightCursor + -1;
            ringCursor[1] = topology;
            ringCursor[2] = element1;
            ringCursor[3] = element2;
            *ringCursor = weightWord;
            ringCursor[4] = element3;
            ringCursor = ringCursor + 5;
            programState = programState + -1;
          } while (programState != 0);
        }
        data = data + vertexStride * 0x10;
        slotIndex = slotIndex + 1;
      } while (data < dataEnd);
    }
    *ringCursor = 0x92b;
    ringCursor[3] = 0;
    ringCursor[2] = ((unsigned char *)0x00001393U);
    ringCursor[1] = 0;
    *(undefined4 **)(ctx + GLD_streamCurrent) = ringCursor + 4;
                    
                    
    (**(code **)(ctx + GLD_streamSetCurrent))(ctx + GLD_commandStream,ringCursor + 4);
    return;
  }
  return;
}

/* gldPrimInlineTriangleStrip @ 0x39d40 (724 bytes) */
void gldPrimInlineTriangleStrip(int ctx,uint data,undefined4 elementCount,undefined4 extraArg3,undefined4 extraArg4,undefined4 extraArg5,double staleFprArg1,double staleFprArg2,double staleFprArg3,double staleFprArg4,double staleFprArg5,double staleFprArg6,double staleFprArg7,double staleFprArg8,double staleFprArg9)
{
  undefined4 element1;
  undefined4 element2;
  undefined4 element3;
  undefined4 weightWord;
  int unitCount;
  undefined4 *ringStart;
  undefined4 *ringCursor;
  undefined4 topology;
  uint slotIndex;
  uint dataEnd;
  int vertexArrayInfo;
  undefined4 *weightCursor;
  int programState;
  int vertexStride;
  double staleStackArg_ffffffa8;
  undefined4 staleArgR9;
  
  topology = 5;
  unitCount = ((uint (*)())gld_prepareDrawCount)(ctx,0,5,elementCount,extraArg4,extraArg5,staleArgR9,staleFprArg1,staleFprArg2,staleFprArg3,staleFprArg4,
                       staleFprArg5,staleFprArg6,staleFprArg7,staleFprArg8,staleStackArg_ffffffa8);
  if (unitCount != 0) {
    programState = *(int *)(ctx + 0x29e8);
    vertexArrayInfo = *(int *)(**(int **)(ctx + GLD_currentProgram) + 4);
    vertexStride = *(int *)(vertexArrayInfo + 0x20);
    ringStart = (undefined4 *)
             (**(code **)(ctx + GLD_streamAllocate))
                       (ctx + GLD_commandStream,
                        vertexStride * unitCount * 5 + unitCount * 2 +
                        (*(int *)(ctx + 0x267c) + 1U & 0xfffffffe) + 0x16,topology,elementCount,extraArg4,
                        unitCount * 2,vertexArrayInfo,programState);
    *(undefined4 **)(ctx + GLD_streamCurrent) = ringStart;
    if (*(code **)(ctx + GLD_vap_prog_stream_cntl_0_ptr) != 0x00001e24 + ctx) {
      *(code **)(ctx + GLD_vap_prog_stream_cntl_0_ptr) = 0x00001e24 + ctx;
      *(int *)(ctx + GLD_vap_prog_stream_cntl_ext_0_ptr) = ctx + 0x1e44;
      *(undefined4 *)(0x000026c8 + ctx + GLD_connect) = *(undefined4 *)(ctx + 0x1ee4);
      ringStart = (undefined4 *)gld_emitVapStreamControl(ctx,ringStart);
    }
    if (*(char *)(ctx + GLD_needsWaitIdle) == '\0') {
      *ringStart = 0x5c8;
      ringStart[1] = 0x10000000;
      ringStart = ringStart + 2;
      *(undefined1 *)(ctx + GLD_needsWaitIdle) = 1;
    }
    ringCursor = ringStart + 4;
    *ringStart = 0x82c;
    dataEnd = data + unitCount * vertexStride * 4 * 4;
    topology = *(undefined4 *)(GLD_vap_vte_cntl + ctx);
    ringStart[2] = 0x821;
    ringStart[3] = 6;
    ringStart[1] = topology;
    unitCount = *(int *)(programState + 0x2c);
    *(undefined1 *)(ctx + GLD_inDrawPixels) = 1;
    if (data < dataEnd) {
      vertexArrayInfo = vertexStride + -1;
      slotIndex = 0;
      do {
        *ringCursor = 0x917;
        if (slotIndex < 0x20) {
          ringCursor[1] = (uint)((1 << (slotIndex & 0x3f) &
                             **(uint **)(((unsigned char *)0x00002d48) + *(int *)(ctx + GLD_engineState) + 8)) != 0);
        }
        else if (slotIndex < 0x40) {
          ringCursor[1] = (uint)((1 << (slotIndex - 0x20 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(ctx + GLD_engineState) + 8) + 4
                                      )) != 0);
        }
        else if (slotIndex < 0x60) {
          ringCursor[1] = (uint)((1 << (slotIndex - 0x40 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(ctx + GLD_engineState) + 8) + 8
                                      )) != 0);
        }
        else {
          ringCursor[1] = (uint)((1 << (slotIndex - 0x60 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(ctx + GLD_engineState) + 8) +
                                      0xc)) != 0);
        }
        ringCursor = ringCursor + 2;
        if (-1 < vertexArrayInfo) {
          weightCursor = (undefined4 *)(unitCount + vertexArrayInfo * 4);
          ringStart = (undefined4 *)(data + vertexArrayInfo * 0x10);
          programState = vertexStride;
          do {
            topology = *ringStart;
            element1 = ringStart[1];
            element2 = ringStart[2];
            element3 = ringStart[3];
            ringStart = ringStart + -4;
            weightWord = *weightCursor;
            weightCursor = weightCursor + -1;
            ringCursor[1] = topology;
            ringCursor[2] = element1;
            ringCursor[3] = element2;
            *ringCursor = weightWord;
            ringCursor[4] = element3;
            ringCursor = ringCursor + 5;
            programState = programState + -1;
          } while (programState != 0);
        }
        data = data + vertexStride * 0x10;
        slotIndex = slotIndex + 1;
      } while (data < dataEnd);
    }
    *ringCursor = 0x92b;
    ringCursor[3] = 0;
    ringCursor[2] = ((unsigned char *)0x00001393U);
    ringCursor[1] = 0;
    *(undefined4 **)(ctx + GLD_streamCurrent) = ringCursor + 4;
                    
                    
    (**(code **)(ctx + GLD_streamSetCurrent))(ctx + GLD_commandStream,ringCursor + 4);
    return;
  }
  return;
}

/* gldPrimInlineQuads @ 0x3a020 (724 bytes) */
void gldPrimInlineQuads(int ctx,uint data,undefined4 elementCount,undefined4 extraArg3,undefined4 extraArg4,undefined4 extraArg5,double staleFprArg1,double staleFprArg2,double staleFprArg3,double staleFprArg4,double staleFprArg5,double staleFprArg6,double staleFprArg7,double staleFprArg8,double staleFprArg9)
{
  undefined4 element1;
  undefined4 element2;
  undefined4 element3;
  undefined4 weightWord;
  int unitCount;
  undefined4 *ringStart;
  undefined4 *ringCursor;
  undefined4 topology;
  uint slotIndex;
  uint dataEnd;
  int vertexArrayInfo;
  undefined4 *weightCursor;
  int programState;
  int vertexStride;
  double staleStackArg_ffffffa8;
  undefined4 staleArgR9;
  
  topology = 7;
  unitCount = ((uint (*)())gld_prepareDrawCount)(ctx,0,7,elementCount,extraArg4,extraArg5,staleArgR9,staleFprArg1,staleFprArg2,staleFprArg3,staleFprArg4,
                       staleFprArg5,staleFprArg6,staleFprArg7,staleFprArg8,staleStackArg_ffffffa8);
  if (unitCount != 0) {
    programState = *(int *)(ctx + 0x29e8);
    vertexArrayInfo = *(int *)(**(int **)(ctx + GLD_currentProgram) + 4);
    vertexStride = *(int *)(vertexArrayInfo + 0x20);
    ringStart = (undefined4 *)
             (**(code **)(ctx + GLD_streamAllocate))
                       (ctx + GLD_commandStream,
                        vertexStride * unitCount * 5 + unitCount * 2 +
                        (*(int *)(ctx + 0x267c) + 1U & 0xfffffffe) + 0x16,topology,elementCount,extraArg4,
                        unitCount * 2,vertexArrayInfo,programState);
    *(undefined4 **)(ctx + GLD_streamCurrent) = ringStart;
    if (*(code **)(ctx + GLD_vap_prog_stream_cntl_0_ptr) != 0x00001e24 + ctx) {
      *(code **)(ctx + GLD_vap_prog_stream_cntl_0_ptr) = 0x00001e24 + ctx;
      *(int *)(ctx + GLD_vap_prog_stream_cntl_ext_0_ptr) = ctx + 0x1e44;
      *(undefined4 *)(0x000026c8 + ctx + GLD_connect) = *(undefined4 *)(ctx + 0x1ee4);
      ringStart = (undefined4 *)gld_emitVapStreamControl(ctx,ringStart);
    }
    if (*(char *)(ctx + GLD_needsWaitIdle) == '\0') {
      *ringStart = 0x5c8;
      ringStart[1] = 0x10000000;
      ringStart = ringStart + 2;
      *(undefined1 *)(ctx + GLD_needsWaitIdle) = 1;
    }
    ringCursor = ringStart + 4;
    *ringStart = 0x82c;
    dataEnd = data + unitCount * vertexStride * 4 * 4;
    topology = *(undefined4 *)(GLD_vap_vte_cntl + ctx);
    ringStart[2] = 0x821;
    ringStart[3] = 0xd;
    ringStart[1] = topology;
    unitCount = *(int *)(programState + 0x2c);
    *(undefined1 *)(ctx + GLD_inDrawPixels) = 1;
    if (data < dataEnd) {
      vertexArrayInfo = vertexStride + -1;
      slotIndex = 0;
      do {
        *ringCursor = 0x917;
        if (slotIndex < 0x20) {
          ringCursor[1] = (uint)((1 << (slotIndex & 0x3f) &
                             **(uint **)(((unsigned char *)0x00002d48) + *(int *)(ctx + GLD_engineState) + 8)) != 0);
        }
        else if (slotIndex < 0x40) {
          ringCursor[1] = (uint)((1 << (slotIndex - 0x20 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(ctx + GLD_engineState) + 8) + 4
                                      )) != 0);
        }
        else if (slotIndex < 0x60) {
          ringCursor[1] = (uint)((1 << (slotIndex - 0x40 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(ctx + GLD_engineState) + 8) + 8
                                      )) != 0);
        }
        else {
          ringCursor[1] = (uint)((1 << (slotIndex - 0x60 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(ctx + GLD_engineState) + 8) +
                                      0xc)) != 0);
        }
        ringCursor = ringCursor + 2;
        if (-1 < vertexArrayInfo) {
          weightCursor = (undefined4 *)(unitCount + vertexArrayInfo * 4);
          ringStart = (undefined4 *)(data + vertexArrayInfo * 0x10);
          programState = vertexStride;
          do {
            topology = *ringStart;
            element1 = ringStart[1];
            element2 = ringStart[2];
            element3 = ringStart[3];
            ringStart = ringStart + -4;
            weightWord = *weightCursor;
            weightCursor = weightCursor + -1;
            ringCursor[1] = topology;
            ringCursor[2] = element1;
            ringCursor[3] = element2;
            *ringCursor = weightWord;
            ringCursor[4] = element3;
            ringCursor = ringCursor + 5;
            programState = programState + -1;
          } while (programState != 0);
        }
        data = data + vertexStride * 0x10;
        slotIndex = slotIndex + 1;
      } while (data < dataEnd);
    }
    *ringCursor = 0x92b;
    ringCursor[3] = 0;
    ringCursor[2] = ((unsigned char *)0x00001393U);
    ringCursor[1] = 0;
    *(undefined4 **)(ctx + GLD_streamCurrent) = ringCursor + 4;
                    
                    
    (**(code **)(ctx + GLD_streamSetCurrent))(ctx + GLD_commandStream,ringCursor + 4);
    return;
  }
  return;
}

/* gldPrimInlineQuadStrip @ 0x3a300 (724 bytes) */
void gldPrimInlineQuadStrip(int ctx,uint data,undefined4 elementCount,undefined4 extraArg3,undefined4 extraArg4,undefined4 extraArg5,double staleFprArg1,double staleFprArg2,double staleFprArg3,double staleFprArg4,double staleFprArg5,double staleFprArg6,double staleFprArg7,double staleFprArg8,double staleFprArg9)
{
  undefined4 element1;
  undefined4 element2;
  undefined4 element3;
  undefined4 weightWord;
  int unitCount;
  undefined4 *ringStart;
  undefined4 *ringCursor;
  undefined4 topology;
  uint slotIndex;
  uint dataEnd;
  int vertexArrayInfo;
  undefined4 *weightCursor;
  int programState;
  int vertexStride;
  double staleStackArg_ffffffa8;
  undefined4 staleArgR9;
  
  topology = 8;
  unitCount = ((uint (*)())gld_prepareDrawCount)(ctx,0,8,elementCount,extraArg4,extraArg5,staleArgR9,staleFprArg1,staleFprArg2,staleFprArg3,staleFprArg4,
                       staleFprArg5,staleFprArg6,staleFprArg7,staleFprArg8,staleStackArg_ffffffa8);
  if (unitCount != 0) {
    programState = *(int *)(ctx + 0x29e8);
    vertexArrayInfo = *(int *)(**(int **)(ctx + GLD_currentProgram) + 4);
    vertexStride = *(int *)(vertexArrayInfo + 0x20);
    ringStart = (undefined4 *)
             (**(code **)(ctx + GLD_streamAllocate))
                       (ctx + GLD_commandStream,
                        vertexStride * unitCount * 5 + unitCount * 2 +
                        (*(int *)(ctx + 0x267c) + 1U & 0xfffffffe) + 0x16,topology,elementCount,extraArg4,
                        unitCount * 2,vertexArrayInfo,programState);
    *(undefined4 **)(ctx + GLD_streamCurrent) = ringStart;
    if (*(code **)(ctx + GLD_vap_prog_stream_cntl_0_ptr) != 0x00001e24 + ctx) {
      *(code **)(ctx + GLD_vap_prog_stream_cntl_0_ptr) = 0x00001e24 + ctx;
      *(int *)(ctx + GLD_vap_prog_stream_cntl_ext_0_ptr) = ctx + 0x1e44;
      *(undefined4 *)(0x000026c8 + ctx + GLD_connect) = *(undefined4 *)(ctx + 0x1ee4);
      ringStart = (undefined4 *)gld_emitVapStreamControl(ctx,ringStart);
    }
    if (*(char *)(ctx + GLD_needsWaitIdle) == '\0') {
      *ringStart = 0x5c8;
      ringStart[1] = 0x10000000;
      ringStart = ringStart + 2;
      *(undefined1 *)(ctx + GLD_needsWaitIdle) = 1;
    }
    ringCursor = ringStart + 4;
    *ringStart = 0x82c;
    dataEnd = data + unitCount * vertexStride * 4 * 4;
    topology = *(undefined4 *)(GLD_vap_vte_cntl + ctx);
    ringStart[2] = 0x821;
    ringStart[3] = 0xe;
    ringStart[1] = topology;
    unitCount = *(int *)(programState + 0x2c);
    *(undefined1 *)(ctx + GLD_inDrawPixels) = 1;
    if (data < dataEnd) {
      vertexArrayInfo = vertexStride + -1;
      slotIndex = 0;
      do {
        *ringCursor = 0x917;
        if (slotIndex < 0x20) {
          ringCursor[1] = (uint)((1 << (slotIndex & 0x3f) &
                             **(uint **)(((unsigned char *)0x00002d48) + *(int *)(ctx + GLD_engineState) + 8)) != 0);
        }
        else if (slotIndex < 0x40) {
          ringCursor[1] = (uint)((1 << (slotIndex - 0x20 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(ctx + GLD_engineState) + 8) + 4
                                      )) != 0);
        }
        else if (slotIndex < 0x60) {
          ringCursor[1] = (uint)((1 << (slotIndex - 0x40 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(ctx + GLD_engineState) + 8) + 8
                                      )) != 0);
        }
        else {
          ringCursor[1] = (uint)((1 << (slotIndex - 0x60 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(ctx + GLD_engineState) + 8) +
                                      0xc)) != 0);
        }
        ringCursor = ringCursor + 2;
        if (-1 < vertexArrayInfo) {
          weightCursor = (undefined4 *)(unitCount + vertexArrayInfo * 4);
          ringStart = (undefined4 *)(data + vertexArrayInfo * 0x10);
          programState = vertexStride;
          do {
            topology = *ringStart;
            element1 = ringStart[1];
            element2 = ringStart[2];
            element3 = ringStart[3];
            ringStart = ringStart + -4;
            weightWord = *weightCursor;
            weightCursor = weightCursor + -1;
            ringCursor[1] = topology;
            ringCursor[2] = element1;
            ringCursor[3] = element2;
            *ringCursor = weightWord;
            ringCursor[4] = element3;
            ringCursor = ringCursor + 5;
            programState = programState + -1;
          } while (programState != 0);
        }
        data = data + vertexStride * 0x10;
        slotIndex = slotIndex + 1;
      } while (data < dataEnd);
    }
    *ringCursor = 0x92b;
    ringCursor[3] = 0;
    ringCursor[2] = ((unsigned char *)0x00001393U);
    ringCursor[1] = 0;
    *(undefined4 **)(ctx + GLD_streamCurrent) = ringCursor + 4;
                    
                    
    (**(code **)(ctx + GLD_streamSetCurrent))(ctx + GLD_commandStream,ringCursor + 4);
    return;
  }
  return;
}

/* gldPrimInlinePolygon @ 0x3a5e0 (724 bytes) */
void gldPrimInlinePolygon(int ctx,uint data,undefined4 elementCount,undefined4 extraArg3,undefined4 extraArg4,undefined4 extraArg5,double staleFprArg1,double staleFprArg2,double staleFprArg3,double staleFprArg4,double staleFprArg5,double staleFprArg6,double staleFprArg7,double staleFprArg8,double staleFprArg9)
{
  undefined4 element1;
  undefined4 element2;
  undefined4 element3;
  undefined4 weightWord;
  int unitCount;
  undefined4 *ringStart;
  undefined4 *ringCursor;
  undefined4 topology;
  uint slotIndex;
  uint dataEnd;
  int vertexArrayInfo;
  undefined4 *weightCursor;
  int programState;
  int vertexStride;
  double staleStackArg_ffffffa8;
  undefined4 staleArgR9;
  
  topology = 9;
  unitCount = ((uint (*)())gld_prepareDrawCount)(ctx,0,9,elementCount,extraArg4,extraArg5,staleArgR9,staleFprArg1,staleFprArg2,staleFprArg3,staleFprArg4,
                       staleFprArg5,staleFprArg6,staleFprArg7,staleFprArg8,staleStackArg_ffffffa8);
  if (unitCount != 0) {
    programState = *(int *)(ctx + 0x29e8);
    vertexArrayInfo = *(int *)(**(int **)(ctx + GLD_currentProgram) + 4);
    vertexStride = *(int *)(vertexArrayInfo + 0x20);
    ringStart = (undefined4 *)
             (**(code **)(ctx + GLD_streamAllocate))
                       (ctx + GLD_commandStream,
                        vertexStride * unitCount * 5 + unitCount * 2 +
                        (*(int *)(ctx + 0x267c) + 1U & 0xfffffffe) + 0x16,topology,elementCount,extraArg4,
                        unitCount * 2,vertexArrayInfo,programState);
    *(undefined4 **)(ctx + GLD_streamCurrent) = ringStart;
    if (*(code **)(ctx + GLD_vap_prog_stream_cntl_0_ptr) != 0x00001e24 + ctx) {
      *(code **)(ctx + GLD_vap_prog_stream_cntl_0_ptr) = 0x00001e24 + ctx;
      *(int *)(ctx + GLD_vap_prog_stream_cntl_ext_0_ptr) = ctx + 0x1e44;
      *(undefined4 *)(0x000026c8 + ctx + GLD_connect) = *(undefined4 *)(ctx + 0x1ee4);
      ringStart = (undefined4 *)gld_emitVapStreamControl(ctx,ringStart);
    }
    if (*(char *)(ctx + GLD_needsWaitIdle) == '\0') {
      *ringStart = 0x5c8;
      ringStart[1] = 0x10000000;
      ringStart = ringStart + 2;
      *(undefined1 *)(ctx + GLD_needsWaitIdle) = 1;
    }
    ringCursor = ringStart + 4;
    *ringStart = 0x82c;
    dataEnd = data + unitCount * vertexStride * 4 * 4;
    topology = *(undefined4 *)(GLD_vap_vte_cntl + ctx);
    ringStart[2] = 0x821;
    ringStart[3] = 0xf;
    ringStart[1] = topology;
    unitCount = *(int *)(programState + 0x2c);
    *(undefined1 *)(ctx + GLD_inDrawPixels) = 1;
    if (data < dataEnd) {
      vertexArrayInfo = vertexStride + -1;
      slotIndex = 0;
      do {
        *ringCursor = 0x917;
        if (slotIndex < 0x20) {
          ringCursor[1] = (uint)((1 << (slotIndex & 0x3f) &
                             **(uint **)(((unsigned char *)0x00002d48) + *(int *)(ctx + GLD_engineState) + 8)) != 0);
        }
        else if (slotIndex < 0x40) {
          ringCursor[1] = (uint)((1 << (slotIndex - 0x20 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(ctx + GLD_engineState) + 8) + 4
                                      )) != 0);
        }
        else if (slotIndex < 0x60) {
          ringCursor[1] = (uint)((1 << (slotIndex - 0x40 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(ctx + GLD_engineState) + 8) + 8
                                      )) != 0);
        }
        else {
          ringCursor[1] = (uint)((1 << (slotIndex - 0x60 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(ctx + GLD_engineState) + 8) +
                                      0xc)) != 0);
        }
        ringCursor = ringCursor + 2;
        if (-1 < vertexArrayInfo) {
          weightCursor = (undefined4 *)(unitCount + vertexArrayInfo * 4);
          ringStart = (undefined4 *)(data + vertexArrayInfo * 0x10);
          programState = vertexStride;
          do {
            topology = *ringStart;
            element1 = ringStart[1];
            element2 = ringStart[2];
            element3 = ringStart[3];
            ringStart = ringStart + -4;
            weightWord = *weightCursor;
            weightCursor = weightCursor + -1;
            ringCursor[1] = topology;
            ringCursor[2] = element1;
            ringCursor[3] = element2;
            *ringCursor = weightWord;
            ringCursor[4] = element3;
            ringCursor = ringCursor + 5;
            programState = programState + -1;
          } while (programState != 0);
        }
        data = data + vertexStride * 0x10;
        slotIndex = slotIndex + 1;
      } while (data < dataEnd);
    }
    *ringCursor = 0x92b;
    ringCursor[3] = 0;
    ringCursor[2] = ((unsigned char *)0x00001393U);
    ringCursor[1] = 0;
    *(undefined4 **)(ctx + GLD_streamCurrent) = ringCursor + 4;
                    
                    
    (**(code **)(ctx + GLD_streamSetCurrent))(ctx + GLD_commandStream,ringCursor + 4);
    return;
  }
  return;
}

/* gldPrimInlinePoints @ 0x3a8c0 (724 bytes) */
void gldPrimInlinePoints(int ctx,uint data,undefined4 elementCount,undefined4 primFlag,undefined4 extraArg4,undefined4 extraArg5,double staleFprArg1,double staleFprArg2,double staleFprArg3,double staleFprArg4,double staleFprArg5,double staleFprArg6,double staleFprArg7,double staleFprArg8,double staleFprArg9)
{
  undefined4 vap_vte_cntl;
  undefined4 element1;
  undefined4 element2;
  undefined4 element3;
  undefined4 weightWord;
  int unitCount;
  undefined4 *ringStart;
  undefined4 *ringCursor;
  undefined4 topology;
  uint loopIndex;
  uint dataEnd;
  int vertexArrayInfo;
  undefined4 *weightCursor;
  int programState;
  int vertexStride;
  double staleStackArg_ffffffa8;
  undefined4 staleArgR9;
  
  topology = 0;
  unitCount = ((uint (*)())gld_prepareDrawCount)(ctx,0,0,elementCount,extraArg4,extraArg5,staleArgR9,staleFprArg1,staleFprArg2,staleFprArg3,staleFprArg4,
                       staleFprArg5,staleFprArg6,staleFprArg7,staleFprArg8,staleStackArg_ffffffa8);
  if (unitCount != 0) {
    programState = *(int *)(ctx + 0x29e8);
    vertexArrayInfo = *(int *)(**(int **)(ctx + 0x1cc) + 4);
    vertexStride = *(int *)(vertexArrayInfo + 0x20);
    ringStart = (undefined4 *)
             (**(code **)(ctx + 0x2998))
                       (ctx + 0x240,
                        vertexStride * unitCount * 5 + unitCount * 2 +
                        (*(int *)(ctx + 0x267c) + 1U & 0xfffffffe) + 0x16,topology,elementCount,extraArg4,
                        unitCount * 2,vertexArrayInfo,programState);
    *(undefined4 **)(ctx + 0x298c) = ringStart;
    if (*(code **)(ctx + 0x2680) != 0x00001e24 + ctx) {
      *(code **)(ctx + 0x2680) = 0x00001e24 + ctx;
      *(int *)(ctx + 0x2684) = ctx + 0x1e44;
      *(undefined4 *)(0x000026c8 + ctx + 4) = *(undefined4 *)(ctx + 0x1ee4);
      ringStart = (undefined4 *)gld_emitVapStreamControl(ctx,ringStart);
    }
    if (*(char *)(ctx + 0x2a42) == '\0') {
      *ringStart = 0x5c8;
      ringStart[1] = 0x10000000;
      ringStart = ringStart + 2;
      *(undefined1 *)(ctx + 0x2a42) = 1;
    }
    *ringStart = 0x82c;
    ringCursor = ringStart + 4;
    dataEnd = data + unitCount * vertexStride * 4 * 4;
    vap_vte_cntl = *(undefined4 *)(0x00001dc4 + ctx);
    ringStart[2] = 0x821;
    ringStart[3] = 1;
    ringStart[1] = vap_vte_cntl;
    unitCount = *(int *)(programState + 0x2c);
    *(undefined1 *)(ctx + 0x2a5e) = 1;
    if (data < dataEnd) {
      vertexArrayInfo = vertexStride + -1;
      loopIndex = 0;
      do {
        *ringCursor = 0x917;
        if (loopIndex < 0x20) {
          ringCursor[1] = (uint)((1 << (loopIndex & 0x3f) &
                             **(uint **)(((unsigned char *)0x00002d48) + *(int *)(ctx + 0x10) + 8)) != 0);
        }
        else if (loopIndex < 0x40) {
          ringCursor[1] = (uint)((1 << (loopIndex - 0x20 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(ctx + 0x10) + 8) + 4
                                      )) != 0);
        }
        else if (loopIndex < 0x60) {
          ringCursor[1] = (uint)((1 << (loopIndex - 0x40 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(ctx + 0x10) + 8) + 8
                                      )) != 0);
        }
        else {
          ringCursor[1] = (uint)((1 << (loopIndex - 0x60 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(ctx + 0x10) + 8) +
                                      0xc)) != 0);
        }
        ringCursor = ringCursor + 2;
        if (-1 < vertexArrayInfo) {
          weightCursor = (undefined4 *)(unitCount + vertexArrayInfo * 4);
          ringStart = (undefined4 *)(data + vertexArrayInfo * 0x10);
          programState = vertexStride;
          do {
            topology = *ringStart;
            element1 = ringStart[1];
            element2 = ringStart[2];
            element3 = ringStart[3];
            ringStart = ringStart + -4;
            weightWord = *weightCursor;
            weightCursor = weightCursor + -1;
            ringCursor[1] = topology;
            ringCursor[2] = element1;
            ringCursor[3] = element2;
            *ringCursor = weightWord;
            ringCursor[4] = element3;
            ringCursor = ringCursor + 5;
            programState = programState + -1;
          } while (programState != 0);
        }
        data = data + vertexStride * 0x10;
        loopIndex = loopIndex + 1;
      } while (data < dataEnd);
    }
    *ringCursor = 0x92b;
    ringCursor[3] = 0;
    ringCursor[2] = ((unsigned char *)0x00001393U);
    ringCursor[1] = 0;
    *(undefined4 **)(ctx + 0x298c) = ringCursor + 4;
                    
                    
    (**(code **)(ctx + 0x299c))(ctx + 0x240,ringCursor + 4);
    return;
  }
  return;
}

/* gldPrimInlineLines @ 0x3aba0 (724 bytes) */
void gldPrimInlineLines(int ctx,uint data,undefined4 elementCount,undefined4 extraArg3,undefined4 extraArg4,undefined4 extraArg5,double staleFprArg1,double staleFprArg2,double staleFprArg3,double staleFprArg4,double staleFprArg5,double staleFprArg6,double staleFprArg7,double staleFprArg8,double staleFprArg9)
{
  undefined4 element1;
  undefined4 element2;
  undefined4 element3;
  undefined4 weightWord;
  int unitCount;
  undefined4 *ringStart;
  undefined4 *ringCursor;
  undefined4 topology;
  uint slotIndex;
  uint dataEnd;
  int vertexArrayInfo;
  undefined4 *weightCursor;
  int programState;
  int vertexStride;
  double staleStackArg_ffffffa8;
  undefined4 staleArgR9;
  
  topology = 1;
  unitCount = ((uint (*)())gld_prepareDrawCount)(ctx,0,1,elementCount,extraArg4,extraArg5,staleArgR9,staleFprArg1,staleFprArg2,staleFprArg3,staleFprArg4,
                       staleFprArg5,staleFprArg6,staleFprArg7,staleFprArg8,staleStackArg_ffffffa8);
  if (unitCount != 0) {
    programState = *(int *)(ctx + 0x29e8);
    vertexArrayInfo = *(int *)(**(int **)(ctx + GLD_currentProgram) + 4);
    vertexStride = *(int *)(vertexArrayInfo + 0x20);
    ringStart = (undefined4 *)
             (**(code **)(ctx + GLD_streamAllocate))
                       (ctx + GLD_commandStream,
                        vertexStride * unitCount * 5 + unitCount * 2 +
                        (*(int *)(ctx + 0x267c) + 1U & 0xfffffffe) + 0x16,topology,elementCount,extraArg4,
                        unitCount * 2,vertexArrayInfo,programState);
    *(undefined4 **)(ctx + GLD_streamCurrent) = ringStart;
    if (*(code **)(ctx + GLD_vap_prog_stream_cntl_0_ptr) != 0x00001e24 + ctx) {
      *(code **)(ctx + GLD_vap_prog_stream_cntl_0_ptr) = 0x00001e24 + ctx;
      *(int *)(ctx + GLD_vap_prog_stream_cntl_ext_0_ptr) = ctx + 0x1e44;
      *(undefined4 *)(0x000026c8 + ctx + GLD_connect) = *(undefined4 *)(ctx + 0x1ee4);
      ringStart = (undefined4 *)gld_emitVapStreamControl(ctx,ringStart);
    }
    if (*(char *)(ctx + GLD_needsWaitIdle) == '\0') {
      *ringStart = 0x5c8;
      ringStart[1] = 0x10000000;
      ringStart = ringStart + 2;
      *(undefined1 *)(ctx + GLD_needsWaitIdle) = 1;
    }
    ringCursor = ringStart + 4;
    *ringStart = 0x82c;
    dataEnd = data + unitCount * vertexStride * 4 * 4;
    topology = *(undefined4 *)(GLD_vap_vte_cntl + ctx);
    ringStart[2] = 0x821;
    ringStart[3] = 2;
    ringStart[1] = topology;
    unitCount = *(int *)(programState + 0x2c);
    *(undefined1 *)(ctx + GLD_inDrawPixels) = 1;
    if (data < dataEnd) {
      vertexArrayInfo = vertexStride + -1;
      slotIndex = 0;
      do {
        *ringCursor = 0x917;
        if (slotIndex < 0x20) {
          ringCursor[1] = (uint)((1 << (slotIndex & 0x3f) &
                             **(uint **)(((unsigned char *)0x00002d48) + *(int *)(ctx + GLD_engineState) + 8)) != 0);
        }
        else if (slotIndex < 0x40) {
          ringCursor[1] = (uint)((1 << (slotIndex - 0x20 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(ctx + GLD_engineState) + 8) + 4
                                      )) != 0);
        }
        else if (slotIndex < 0x60) {
          ringCursor[1] = (uint)((1 << (slotIndex - 0x40 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(ctx + GLD_engineState) + 8) + 8
                                      )) != 0);
        }
        else {
          ringCursor[1] = (uint)((1 << (slotIndex - 0x60 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(ctx + GLD_engineState) + 8) +
                                      0xc)) != 0);
        }
        ringCursor = ringCursor + 2;
        if (-1 < vertexArrayInfo) {
          weightCursor = (undefined4 *)(unitCount + vertexArrayInfo * 4);
          ringStart = (undefined4 *)(data + vertexArrayInfo * 0x10);
          programState = vertexStride;
          do {
            topology = *ringStart;
            element1 = ringStart[1];
            element2 = ringStart[2];
            element3 = ringStart[3];
            ringStart = ringStart + -4;
            weightWord = *weightCursor;
            weightCursor = weightCursor + -1;
            ringCursor[1] = topology;
            ringCursor[2] = element1;
            ringCursor[3] = element2;
            *ringCursor = weightWord;
            ringCursor[4] = element3;
            ringCursor = ringCursor + 5;
            programState = programState + -1;
          } while (programState != 0);
        }
        data = data + vertexStride * 0x10;
        slotIndex = slotIndex + 1;
      } while (data < dataEnd);
    }
    *ringCursor = 0x92b;
    ringCursor[3] = 0;
    ringCursor[2] = ((unsigned char *)0x00001393U);
    ringCursor[1] = 0;
    *(undefined4 **)(ctx + GLD_streamCurrent) = ringCursor + 4;
                    
                    
    (**(code **)(ctx + GLD_streamSetCurrent))(ctx + GLD_commandStream,ringCursor + 4);
    return;
  }
  return;
}

/* gldPrimInlineLineLoop @ 0x3ae80 (724 bytes) */
void gldPrimInlineLineLoop(int ctx,uint data,undefined4 elementCount,undefined4 primFlag,undefined4 extraArg4,undefined4 extraArg5,double staleFprArg1,double staleFprArg2,double staleFprArg3,double staleFprArg4,double staleFprArg5,double staleFprArg6,double staleFprArg7,double staleFprArg8,double staleFprArg9)
{
  undefined4 vap_vte_cntl;
  undefined4 element1;
  undefined4 element2;
  undefined4 element3;
  undefined4 weightWord;
  int unitCount;
  undefined4 *ringStart;
  undefined4 *ringCursor;
  undefined4 topology;
  uint loopIndex;
  uint dataEnd;
  int vertexArrayInfo;
  undefined4 *weightCursor;
  int programState;
  int vertexStride;
  double staleStackArg_ffffffa8;
  undefined4 staleArgR9;
  
  topology = 2;
  unitCount = ((uint (*)())gld_prepareDrawCount)(ctx,primFlag,2,elementCount,extraArg4,extraArg5,staleArgR9,staleFprArg1,staleFprArg2,staleFprArg3,staleFprArg4
                       ,staleFprArg5,staleFprArg6,staleFprArg7,staleFprArg8,staleStackArg_ffffffa8);
  if (unitCount != 0) {
    programState = *(int *)(ctx + 0x29e8);
    vertexArrayInfo = *(int *)(**(int **)(ctx + 0x1cc) + 4);
    vertexStride = *(int *)(vertexArrayInfo + 0x20);
    ringStart = (undefined4 *)
             (**(code **)(ctx + 0x2998))
                       (ctx + 0x240,
                        vertexStride * unitCount * 5 + unitCount * 2 +
                        (*(int *)(ctx + 0x267c) + 1U & 0xfffffffe) + 0x16,topology,elementCount,extraArg4,
                        unitCount * 2,vertexArrayInfo,programState);
    *(undefined4 **)(ctx + 0x298c) = ringStart;
    if (*(code **)(ctx + 0x2680) != 0x00001e24 + ctx) {
      *(code **)(ctx + 0x2680) = 0x00001e24 + ctx;
      *(int *)(ctx + 0x2684) = ctx + 0x1e44;
      *(undefined4 *)(0x000026c8 + ctx + 4) = *(undefined4 *)(ctx + 0x1ee4);
      ringStart = (undefined4 *)gld_emitVapStreamControl(ctx,ringStart);
    }
    if (*(char *)(ctx + 0x2a42) == '\0') {
      *ringStart = 0x5c8;
      ringStart[1] = 0x10000000;
      ringStart = ringStart + 2;
      *(undefined1 *)(ctx + 0x2a42) = 1;
    }
    ringCursor = ringStart + 4;
    *ringStart = 0x82c;
    dataEnd = data + unitCount * vertexStride * 4 * 4;
    vap_vte_cntl = *(undefined4 *)(0x00001dc4 + ctx);
    ringStart[2] = 0x821;
    ringStart[3] = 0xc;
    ringStart[1] = vap_vte_cntl;
    unitCount = *(int *)(programState + 0x2c);
    *(undefined1 *)(ctx + 0x2a5e) = 1;
    if (data < dataEnd) {
      vertexArrayInfo = vertexStride + -1;
      loopIndex = 0;
      do {
        *ringCursor = 0x917;
        if (loopIndex < 0x20) {
          ringCursor[1] = (uint)((1 << (loopIndex & 0x3f) &
                             **(uint **)(((unsigned char *)0x00002d48) + *(int *)(ctx + 0x10) + 8)) != 0);
        }
        else if (loopIndex < 0x40) {
          ringCursor[1] = (uint)((1 << (loopIndex - 0x20 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(ctx + 0x10) + 8) + 4
                                      )) != 0);
        }
        else if (loopIndex < 0x60) {
          ringCursor[1] = (uint)((1 << (loopIndex - 0x40 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(ctx + 0x10) + 8) + 8
                                      )) != 0);
        }
        else {
          ringCursor[1] = (uint)((1 << (loopIndex - 0x60 & 0x3f) &
                             *(uint *)(*(int *)(((unsigned char *)0x00002d48) + *(int *)(ctx + 0x10) + 8) +
                                      0xc)) != 0);
        }
        ringCursor = ringCursor + 2;
        if (-1 < vertexArrayInfo) {
          weightCursor = (undefined4 *)(unitCount + vertexArrayInfo * 4);
          ringStart = (undefined4 *)(data + vertexArrayInfo * 0x10);
          programState = vertexStride;
          do {
            topology = *ringStart;
            element1 = ringStart[1];
            element2 = ringStart[2];
            element3 = ringStart[3];
            ringStart = ringStart + -4;
            weightWord = *weightCursor;
            weightCursor = weightCursor + -1;
            ringCursor[1] = topology;
            ringCursor[2] = element1;
            ringCursor[3] = element2;
            *ringCursor = weightWord;
            ringCursor[4] = element3;
            ringCursor = ringCursor + 5;
            programState = programState + -1;
          } while (programState != 0);
        }
        data = data + vertexStride * 0x10;
        loopIndex = loopIndex + 1;
      } while (data < dataEnd);
    }
    *ringCursor = 0x92b;
    ringCursor[3] = 0;
    ringCursor[2] = ((unsigned char *)0x00001393U);
    ringCursor[1] = 0;
    *(undefined4 **)(ctx + 0x298c) = ringCursor + 4;
                    
                    
    (**(code **)(ctx + 0x299c))(ctx + 0x240,ringCursor + 4);
    return;
  }
  return;
}

/* FUN_0003b160 @ 0x3b160 (284 bytes) */
int FUN_0003b160(param_1, dirtyBits, param_3)
  int param_1;
  int dirtyBits;
  undefined4 param_3;
{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  
  piVar5 = *(int **)(param_1 + 0x1cc);
  if ((dirtyBits == 0) || (uVar4 = 0, (*(uint *)(dirtyBits + 0xc) & 0x4400000) != 0)) {
    uVar4 = 2;
  }
  if ((piVar5 != (int *)0x0) &&
     (((dirtyBits == 0 || ((*(uint *)(dirtyBits + 8) & 0xff00) != 0)) ||
      ((*(uint *)(dirtyBits + 0xc) & 0x4c00000) != 0)))) {
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
                   *(undefined4 *)(iVar3 + 0x18),dirtyBits + 0x14);
    }
    else {
      ((int (*)())FUN_0003b870)(param_1,iVar1,*(undefined4 *)(iVar2 + 0x28),iVar2 + *(int *)(iVar2 + 0x2c) * 8,
                   *(undefined4 *)(iVar3 + 0x18));
    }
  }
  return param_3;
}

/* FUN_0003b280 @ 0x3b280 (772 bytes) */
int FUN_0003b280(ctx, hwProgram, param_3, param_4, param_5, param_6, param_7, param_8)
  int ctx;
  int hwProgram;
  uint param_3;
  int param_4;
  uint param_5;
  int param_6;
  undefined4 param_7;
  int param_8;
{
  int loopIndex2;
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
  uint loopIndex;
  uint uVar14;
  int iVar15;
  undefined4 *puVar16;
  int iVar17;
  uint *puVar18;
  uint local_50 [4];
  
  if (*(uint *)(hwProgram + 0x24) != param_3) {
    if (*(int *)(hwProgram + 0x28) != 0) {
      (**(code **)(ctx + 0x18))(*(int *)(hwProgram + 0x28));
      *(undefined4 *)(hwProgram + 0x28) = 0;
    }
    if (param_3 != 0) {
      uVar7 = (**(code **)(ctx + 0x10))(param_3,4);
      *(undefined4 *)(hwProgram + 0x28) = uVar7;
    }
  }
  *(uint *)(hwProgram + 0x24) = param_3;
  if (*(char *)(hwProgram + 0x8c) != '\0') {
    iVar15 = 0;
    iVar17 = hwProgram;
    do {
      uVar7 = glGenSymbolsEXT_impl5(ctx,0x87bf,0x87c2,0x87e1,1);
      bVar1 = iVar15 != 3;
      iVar15 = iVar15 + 1;
      *(undefined4 *)(iVar17 + 0x68) = uVar7;
      iVar17 = iVar17 + 4;
    } while (bVar1);
  }
  if (param_3 != 0) {
    iVar17 = *(int *)(hwProgram + 0x28);
    uVar14 = 0;
    loopIndex = 0;
    puVar9 = (undefined1 *)((unsigned int)__builtin_frame_address(0));
    do {
      if (loopIndex < param_5) {
        local_50[0] = *(uint *)(loopIndex * 8 + param_6);
        local_50[1] = *(uint *)(loopIndex * 8 + param_6 + 4);
        if ((uVar14 < (local_50[0] & 0xffff)) || ((local_50[1] & 0xffff) <= uVar14))
        goto LAB_0003b3e0;
        loopIndex = loopIndex + 1;
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
        FUN_000534c0(ctx,iVar15,puVar8,puVar2 + 0x10,puVar16);
        if (iVar15 != 0) {
          loopIndex2 = 0;
          do {
            uVar5 = *puVar18;
            uVar7 = *puVar16;
            *(undefined4 *)(iVar17 + (puVar18[1] & 0xffff) * 4) = uVar7;
            if ((uVar5 >> 0x10 & 0x1f) == 0x11) {
              glSetLocalConstantEXT_impl(ctx,uVar7,((unsigned char *)0x00001406U),(uVar5 & 0xffff) * 0x10 + param_8);
            }
            loopIndex2 = loopIndex2 + 1;
            puVar18 = puVar18 + 2;
            puVar16 = puVar16 + 1;
          } while (iVar15 != loopIndex2);
          uVar14 = uVar14 + loopIndex2;
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
    iVar1 = extvsReserveSymbolIds(param_1,1);
    *param_2 = iVar1;
    if (iVar1 == 0) {
      return 0;
    }
  }
  thunk_FUN_00053b60(param_1,iVar1);
  return 1;
}

/* FUN_0003b620 @ 0x3b620 (592 bytes) */
int FUN_0003b620(ctx, program, passThroughArg2, passThroughArg3, operandTable)
  int ctx;
  int program;
  int passThroughArg2;
  int passThroughArg3;
  uint *operandTable;
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
  
  if (*(char *)(passThroughArg2 + 0x8c) == '\0') {
    *(undefined4 *)(program + 0x800) = 0;
  }
  else {
    *(undefined2 *)(program + 2) = 0;
    *(undefined2 *)(program + 10) = 1;
    *(undefined4 *)(program + 0x800) = 4;
    *(undefined2 *)(program + 0x12) = 2;
    *(undefined2 *)(program + 0x1a) = 3;
    local_418[0] = *(undefined4 *)(passThroughArg2 + 0x68);
    local_418[1] = *(undefined4 *)(passThroughArg2 + 0x6c);
    local_418[2] = *(undefined4 *)(passThroughArg2 + 0x70);
    local_418[3] = *(undefined4 *)(passThroughArg2 + 0x74);
  }
  if (passThroughArg3 == 0) {
    iVar7 = *(int *)(program + 0x800);
    *(int *)(program + 0x804) = iVar7;
    *(int *)(program + 0x808) = iVar7;
  }
  else {
    iVar3 = *(int *)(passThroughArg2 + 0x28);
    iVar7 = *(int *)(program + 0x800);
    puVar4 = operandTable;
    iVar8 = passThroughArg3;
    do {
      if ((*puVar4 & 0x1fc700) == 0x100000) {
        iVar1 = program + iVar7 * 8;
        uVar6 = *(undefined4 *)(iVar3 + (uint)*(ushort *)((int)puVar4 + 6) * 4);
        *(char *)(iVar1 + 1) = (char)*(ushort *)((int)puVar4 + 6);
        local_418[iVar7] = uVar6;
        *(ushort *)(iVar1 + 2) = *(byte *)((int)puVar4 + 2) >> 4 & 3;
        iVar7 = *(int *)(program + 0x800) + 1;
        *(int *)(program + 0x800) = iVar7;
      }
      puVar4 = puVar4 + 2;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    *(int *)(program + 0x804) = iVar7;
    iVar3 = *(int *)(passThroughArg2 + 0x28);
    puVar4 = operandTable;
    iVar8 = passThroughArg3;
    do {
      if ((*puVar4 & 0x1f0000) == 0x20000) {
        iVar1 = program + iVar7 * 8;
        uVar6 = *(undefined4 *)(iVar3 + (uint)*(ushort *)((int)puVar4 + 6) * 4);
        *(char *)(iVar1 + 1) = (char)*(ushort *)((int)puVar4 + 6);
        local_418[iVar7] = uVar6;
        *(short *)(iVar1 + 2) = (short)*puVar4;
        iVar7 = *(int *)(program + 0x804) + 1;
        *(int *)(program + 0x804) = iVar7;
      }
      puVar4 = puVar4 + 2;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    *(int *)(program + 0x808) = iVar7;
    sVar5 = 0;
    do {
      uVar2 = *operandTable >> 0x10 & 0x1f;
      if ((((uVar2 != 0) && (uVar2 != 0x11)) && (uVar2 != 2)) && ((*operandTable & 0x1fc700) != 0x100000)
         ) {
        iVar8 = program + iVar7 * 8;
        uVar6 = *(undefined4 *)(iVar3 + (uint)*(ushort *)((int)operandTable + 6) * 4);
        *(char *)(iVar8 + 1) = (char)*(ushort *)((int)operandTable + 6);
        *(short *)(iVar8 + 2) = sVar5;
        local_418[iVar7] = uVar6;
        iVar7 = *(int *)(program + 0x808) + 1;
        *(int *)(program + 0x808) = iVar7;
      }
      sVar5 = sVar5 + 1;
      operandTable = operandTable + 2;
      passThroughArg3 = passThroughArg3 + -1;
    } while (passThroughArg3 != 0);
  }
  return FUN_00054590(ctx + 0x240,program,iVar7,local_418);
}

/* FUN_0003b870 @ 0x3b870 (2500 bytes) */
int FUN_0003b870(ctx, passThroughArg2, passThroughArg3, operandTable, literalConstants)
  int ctx;
  undefined4 passThroughArg2;
  undefined4 passThroughArg3;
  int operandTable;
  int literalConstants;
{
  uint matrixMode;
  uint fileSelect;
  ushort *entryStateIndexPtr;
  byte destSlot;
  undefined4 constW;
  undefined4 constY;
  undefined4 constZ;
  float fVar6;
  float fVar7;
  float fVar8;
  undefined4 constX;
  float fVar10;
  int iVar11;
  undefined *stateRecord;
  dword *srcZPtr;
  undefined8 *puVar14;
  int entryCount;
  int stateConstants;
  int iVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  float *srcVec;
  undefined4 *destPtr;
  dword *srcWPtr;
  int iVar24;
  dword *srcYPtr;
  uint operandIndex;
  float *outSlot;
  byte *entryCursor;
  double dVar29;
  undefined8 uVar30;
  double dVar31;
  byte *program;
  int constantTable;
  undefined1 auStack_60 [8];
  uint operandWord;
  undefined4 operandWord2;
  uint operandWordCopy;
  undefined4 operandWord2Copy;
  
  entryCount = FUN_00054470(ctx + GLD_commandStream,&program,&constantTable,auStack_60);
  if (entryCount != 0) {
    ((int (*)())FUN_0003b620)(ctx,program,passThroughArg2,passThroughArg3,operandTable);
  }
  entryCount = *(int *)(program + 0x800);
  entryCursor = program;
  if (program < program + entryCount * 8) {
    stateConstants = *(int *)(ctx + GLD_engineState) + 0x1860;
    do {
      entryStateIndexPtr = (ushort *)(entryCursor + 2);
      destSlot = *entryCursor;
      destPtr = *(undefined4 **)(entryCursor + 4);
      entryCursor = entryCursor + 8;
      iVar19 = stateConstants + (uint)*entryStateIndexPtr * 4;
      constX = *(undefined4 *)(stateConstants + (uint)*entryStateIndexPtr * 4);
      iVar11 = constantTable + (uint)destSlot * 0x10;
      constW = *(undefined4 *)(iVar19 + 0x30);
      constY = *(undefined4 *)(iVar19 + 0x10);
      constZ = *(undefined4 *)(iVar19 + 0x20);
      *(undefined4 *)(constantTable + (uint)destSlot * 0x10) = constX;
      *(undefined4 *)(iVar11 + 0xc) = constW;
      *(undefined4 *)(iVar11 + 4) = constY;
      *(undefined4 *)(iVar11 + 8) = constZ;
      destPtr[3] = constW;
      *destPtr = constX;
      destPtr[1] = constY;
      destPtr[2] = constZ;
    } while (entryCursor < program + entryCount * 8);
  }
  entryCount = *(int *)(program + 0x804);
  for (; entryCursor < program + entryCount * 8; entryCursor = entryCursor + 8) {
    destSlot = *entryCursor;
    uVar30 = (*(undefined8 **)(entryCursor + 4))[1];
    *(undefined8 *)(constantTable + (uint)destSlot * 0x10) = **(undefined8 **)(entryCursor + 4);
    *(undefined8 *)(constantTable + (uint)destSlot * 0x10 + 8) = uVar30;
  }
  entryCount = *(int *)(program + 0x808);
joined_r0x0003b9b0:
  if (program + entryCount * 8 <= entryCursor) {
    return;
  }
  operandWord = *(uint *)((uint)*(ushort *)(entryCursor + 2) * 8 + operandTable);
  outSlot = (float *)(constantTable + (uint)*entryCursor * 0x10);
  operandWord2 = *(undefined4 *)((uint)*(ushort *)(entryCursor + 2) * 8 + operandTable + 4);
  fileSelect = operandWord >> 0x10 & 0x1f;
  if (fileSelect == 1) {
    stateConstants = (operandWord & 0xffff) * 0x10;
    iVar11 = stateConstants + literalConstants;
    if (*(int *)(*(int *)(ctx + GLD_engineObjects) + 0x198) == 0) {
      fVar6 = *(float *)(iVar11 + 0xc);
      fVar7 = *(float *)(iVar11 + 4);
      fVar8 = *(float *)(iVar11 + 8);
      *(undefined4 *)(constantTable + (uint)*entryCursor * 0x10) = *(undefined4 *)(stateConstants + literalConstants);
      outSlot[3] = fVar6;
      outSlot[1] = fVar7;
      outSlot[2] = fVar8;
    }
    else {
      _glpUniformToFloat(*(undefined4 *)(**(int **)(ctx + GLD_currentProgram) + 4),operandWord & 0xffff,iVar11,
                         outSlot);
    }
    goto LAB_0003c2d0;
  }
  operandWordCopy = operandWord;
  operandWord2Copy = operandWord2;
  if ((operandWord & 0x1f0000) == 0x100000) {
    uVar20 = operandWord >> 0xc & 3;
    operandIndex = operandWord & 0xff;
    switch(operandWord >> 8 & 7) {
    default:
      stateConstants = 0;
      break;
    case 1:
      stateConstants = 0xc0;
      break;
    case 2:
      stateConstants = 0x80;
      break;
    case 3:
      stateConstants = (operandIndex + 4) * 0x40;
      break;
    case 4:
      stateConstants = (operandIndex + 0x10) * 0x40;
      break;
    case 5:
      stateConstants = (operandIndex + 8) * 0x40;
    }
    matrixMode = operandWord >> 0xe & 3;
    iVar11 = *(int *)(ctx + GLD_engineState) + 0x1860 + stateConstants;
    if ((1 < matrixMode) && (iVar11 = stateConstants + *(int *)(ctx + GLD_engineState) + 0x1e60, 3 < matrixMode)) {
      iVar11 = 0;
    }
    if (matrixMode < 3) {
      if (matrixMode == 0) {
LAB_0003bef8:
        stateConstants = uVar20 * 4;
        iVar19 = iVar11 + stateConstants;
        *outSlot = *(float *)(iVar11 + stateConstants);
        outSlot[1] = *(float *)(iVar19 + 0x10);
        outSlot[2] = *(float *)(iVar19 + 0x20);
        outSlot[3] = *(float *)(iVar19 + 0x30);
      }
      else {
        stateConstants = uVar20 * 0x10;
        iVar19 = iVar11 + stateConstants;
        *outSlot = *(float *)(iVar11 + stateConstants);
        outSlot[1] = *(float *)(iVar19 + 4);
        outSlot[2] = *(float *)(iVar19 + 8);
        outSlot[3] = *(float *)(iVar19 + 0xc);
      }
    }
    else if (matrixMode == 3) goto LAB_0003bef8;
    goto LAB_0003c2d0;
  }
  switch(fileSelect) {
  case 0:
    srcYPtr = (dword *)(outSlot + 1);
    srcZPtr = (dword *)(outSlot + 2);
    srcWPtr = (dword *)(outSlot + 3);
    srcVec = outSlot;
    break;
  default:
    goto switchD_0003bf70_caseD_1;
  case 2:
    srcVec = (float *)((operandWord & 0xffff) * 0x10 +
                       *(int *)(((unsigned char *)0x00004308) + *(int *)(ctx + GLD_engineState)));
    srcYPtr = (dword *)(srcVec + 1);
    srcZPtr = (dword *)(srcVec + 2);
    srcWPtr = (dword *)(srcVec + 3);
    break;
  case 3:
    uVar20 = operandWord & 0xff;
    switch(operandWord >> 8 & 0xf) {
    case 0:
      srcVec = (float *)(uVar20 * 0x80 + 0x24c0 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(srcVec + 1);
      srcZPtr = (dword *)(srcVec + 2);
      srcWPtr = (dword *)(srcVec + 3);
      break;
    case 1:
      srcVec = (float *)(uVar20 * 0x80 + 0x24d0 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(srcVec + 1);
      srcZPtr = (dword *)(srcVec + 2);
      srcWPtr = (dword *)(srcVec + 3);
      break;
    case 2:
      srcVec = (float *)(uVar20 * 0x80 + 0x24e0 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(srcVec + 1);
      srcZPtr = (dword *)(srcVec + 2);
      srcWPtr = (dword *)(srcVec + 3);
      break;
    case 3:
      srcVec = (float *)(uVar20 * 0x80 + 0x24f0 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(srcVec + 1);
      srcZPtr = (dword *)(srcVec + 2);
      srcWPtr = (dword *)(srcVec + 3);
      break;
    case 4:
      srcVec = (float *)(uVar20 * 0x80 + 0x2500 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(srcVec + 1);
      srcZPtr = (dword *)(srcVec + 2);
      srcWPtr = (dword *)(srcVec + 3);
      break;
    case 5:
      srcVec = (float *)(uVar20 * 0x80 + 0x2510 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(srcVec + 1);
      srcZPtr = (dword *)(srcVec + 2);
      srcWPtr = (dword *)(srcVec + 3);
      break;
    case 6:
      stateConstants = uVar20 * 0x80 + *(int *)(ctx + GLD_engineState);
      fVar7 = *(float *)(stateConstants + 0x24f4);
      fVar8 = *(float *)(stateConstants + 0x24f0);
      fVar10 = *(float *)(stateConstants + 0x24f8) + 1.0;
      dVar29 = _sqrt((double)(fVar10 * fVar10 + fVar8 * fVar8 + fVar7 * fVar7));
      outSlot[3] = 1.0;
      fVar6 = (float)(1.0 / dVar29);
      outSlot[2] = fVar10 * fVar6;
      *outSlot = fVar8 * fVar6;
      outSlot[1] = fVar7 * fVar6;
      goto LAB_0003c2d0;
    case 7:
      srcVec = (float *)(uVar20 * 0x80 + 0x2530 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(srcVec + 1);
      srcZPtr = (dword *)(srcVec + 2);
      srcWPtr = (dword *)(srcVec + 3);
      break;
    default:
      goto switchD_0003bf70_caseD_1;
    }
    break;
  case 4:
    uVar20 = operandWord >> 9 & 3;
    iVar17 = *(int *)(ctx + GLD_engineState) + 0x24c0;
    stateConstants = (operandWord & 0xff) * 0x80;
    iVar11 = (operandWord >> 8 & 1) * 0x240;
    iVar19 = *(int *)(ctx + GLD_engineState) + 0x28c0;
    iVar24 = iVar17 + stateConstants;
    iVar18 = iVar19 + iVar11;
    if (uVar20 == 1) {
      *outSlot = *(float *)(iVar24 + 0x10) * *(float *)(iVar18 + 0x10);
      outSlot[1] = *(float *)(iVar24 + 0x14) * *(float *)(iVar18 + 0x14);
      outSlot[2] = *(float *)(iVar24 + 0x18) * *(float *)(iVar18 + 0x18);
      outSlot[3] = *(float *)(iVar18 + 0x1c);
    }
    else if (uVar20 == 2) {
      *outSlot = *(float *)(iVar24 + 0x20) * *(float *)(iVar18 + 0x20);
      outSlot[1] = *(float *)(iVar24 + 0x24) * *(float *)(iVar18 + 0x24);
      outSlot[2] = *(float *)(iVar24 + 0x28) * *(float *)(iVar18 + 0x28);
      outSlot[3] = *(float *)(iVar18 + 0x2c);
    }
    else {
      if (uVar20 != 0) goto switchD_0003bf70_caseD_1;
      *outSlot = *(float *)(iVar17 + stateConstants) * *(float *)(iVar19 + iVar11);
      outSlot[1] = *(float *)(iVar24 + 4) * *(float *)(iVar18 + 4);
      outSlot[2] = *(float *)(iVar24 + 8) * *(float *)(iVar18 + 8);
      outSlot[3] = *(float *)(iVar18 + 0xc);
    }
    goto LAB_0003c2d0;
  case 5:
    uVar20 = operandWord & 1;
    switch(operandWord >> 1 & 7) {
    case 0:
      srcVec = (float *)(uVar20 * 0x240 + 0x28c0 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(srcVec + 1);
      srcZPtr = (dword *)(srcVec + 2);
      srcWPtr = (dword *)(srcVec + 3);
      break;
    case 1:
      srcVec = (float *)(uVar20 * 0x240 + 0x28d0 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(srcVec + 1);
      srcZPtr = (dword *)(srcVec + 2);
      srcWPtr = (dword *)(srcVec + 3);
      break;
    case 2:
      srcVec = (float *)(uVar20 * 0x240 + 0x28e0 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(srcVec + 1);
      srcZPtr = (dword *)(srcVec + 2);
      srcWPtr = (dword *)(srcVec + 3);
      break;
    case 3:
      srcVec = (float *)(uVar20 * 0x240 + 0x28f0 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(srcVec + 1);
      srcZPtr = (dword *)(srcVec + 2);
      srcWPtr = (dword *)(srcVec + 3);
      break;
    case 4:
      srcVec = (float *)(uVar20 * 0x240 + 0x2900 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(srcVec + 1);
      srcZPtr = (dword *)(srcVec + 2);
      srcWPtr = (dword *)(srcVec + 3);
      break;
    case 5:
      stateConstants = *(int *)(ctx + GLD_engineState);
      iVar11 = stateConstants + 0x28c0 + uVar20 * 0x240;
      *outSlot = *(float *)(stateConstants + 0x24b0) * *(float *)(stateConstants + 0x28c0 + uVar20 * 0x240) +
                 *(float *)(iVar11 + 0x30);
      outSlot[1] = *(float *)(stateConstants + 0x24b4) * *(float *)(iVar11 + 4) + *(float *)(iVar11 + 0x34);
      outSlot[2] = *(float *)(stateConstants + 0x24b8) * *(float *)(iVar11 + 8) + *(float *)(iVar11 + 0x38);
      outSlot[3] = *(float *)(iVar11 + 0x1c);
      goto LAB_0003c2d0;
    default:
      goto switchD_0003bf70_caseD_1;
    }
    break;
  case 6:
    stateConstants = *(int *)(ctx + GLD_engineState);
    srcWPtr = (dword *)(stateConstants + 0x24bc);
    srcYPtr = (dword *)(stateConstants + 0x24b4);
    srcZPtr = (dword *)(stateConstants + 0x24b8);
    srcVec = (float *)(stateConstants + 0x24b0);
    break;
  case 7:
    uVar20 = operandWord >> 5 & 7;
    operandWord = operandWord & 0x1f;
    if (uVar20 == 1) {
      stateConstants = *(int *)(ctx + GLD_engineState);
      stateRecord = ((unsigned char *)0x000039a0) + operandWord * 0x94;
LAB_0003bae4:
      srcWPtr = (dword *)(stateRecord + stateConstants + 0x1c);
      srcYPtr = (dword *)(stateRecord + stateConstants + 0x14);
      srcZPtr = (dword *)(stateRecord + stateConstants + 0x18);
      srcVec = (float *)(stateRecord + stateConstants + 0x10);
    }
    else {
      if (uVar20 < 2) {
        if (uVar20 == 0) {
          stateConstants = *(int *)(ctx + GLD_engineState);
          stateRecord = ((unsigned char *)0x00003980) + operandWord * 0x94;
          goto LAB_0003bac0;
        }
        goto switchD_0003bf70_caseD_1;
      }
      if (uVar20 == 2) {
        stateConstants = *(int *)(ctx + GLD_engineState);
        stateRecord = ((unsigned char *)0x000039c0) + operandWord * 0x94;
LAB_0003bb08:
        srcWPtr = (dword *)(stateRecord + stateConstants + 0x20);
        srcYPtr = (dword *)(stateRecord + stateConstants + 0x18);
        srcZPtr = (dword *)(stateRecord + stateConstants + 0x1c);
        srcVec = (float *)(stateRecord + stateConstants + 0x14);
      }
      else {
        if (uVar20 != 3) goto switchD_0003bf70_caseD_1;
        stateConstants = *(int *)(ctx + GLD_engineState);
        stateRecord = ((unsigned char *)0x000039e0) + operandWord * 0x94;
LAB_0003bb2c:
        srcWPtr = (dword *)(stateRecord + stateConstants + 0x24);
        srcYPtr = (dword *)(stateRecord + stateConstants + 0x1c);
        srcZPtr = (dword *)(stateRecord + stateConstants + 0x20);
        srcVec = (float *)(stateRecord + stateConstants + 0x18);
      }
    }
    break;
  case 8:
    uVar20 = operandWord >> 5 & 7;
    operandWord = operandWord & 0x1f;
    if (uVar20 == 1) {
      stateConstants = *(int *)(ctx + GLD_engineState);
      stateRecord = ((unsigned char *)0x000039b0) + operandWord * 0x94;
      goto LAB_0003bae4;
    }
    if (uVar20 < 2) {
      if (uVar20 == 0) {
        stateConstants = *(int *)(ctx + GLD_engineState);
        stateRecord = ((unsigned char *)0x00003990) + operandWord * 0x94;
        goto LAB_0003bac0;
      }
    }
    else {
      if (uVar20 == 2) {
        stateConstants = *(int *)(ctx + GLD_engineState);
        stateRecord = ((unsigned char *)0x000039d0) + operandWord * 0x94;
        goto LAB_0003bb08;
      }
      if (uVar20 == 3) {
        stateConstants = *(int *)(ctx + GLD_engineState);
        stateRecord = ((unsigned char *)0x000039f0) + operandWord * 0x94;
        goto LAB_0003bb2c;
      }
    }
    goto switchD_0003bf70_caseD_1;
  case 9:
    stateConstants = *(int *)(ctx + GLD_engineState) + (operandWord & 0x1f) * 0x7c;
    srcWPtr = (dword *)(((unsigned char *)0x000031c0) + stateConstants + 0x10);
    srcZPtr = (dword *)(((unsigned char *)0x000031c0) + stateConstants + 0xc);
    srcYPtr = (dword *)(((unsigned char *)0x000031c0) + stateConstants + 8);
    srcVec = (float *)(((unsigned char *)0x000031c0) + stateConstants + 4);
    break;
  case 10:
    stateConstants = *(int *)(ctx + GLD_engineState);
    stateRecord = ((unsigned char *)0x00003e20) + (operandWord & 0xff) * 0x10;
LAB_0003bac0:
    srcWPtr = (dword *)(stateRecord + stateConstants + 0x18);
    srcYPtr = (dword *)(stateRecord + stateConstants + 0x10);
    srcZPtr = (dword *)(stateRecord + stateConstants + 0x14);
    srcVec = (float *)(stateRecord + stateConstants + 0xc);
    break;
  case 0xb:
    stateConstants = *(int *)(ctx + GLD_engineState);
    srcWPtr = (dword *)(((unsigned char *)0x00002dec) + stateConstants);
    srcYPtr = (dword *)(((unsigned char *)0x00002de4) + stateConstants);
    srcZPtr = (dword *)(((unsigned char *)0x00002de8) + stateConstants);
    srcVec = (float *)(((unsigned char *)0x00002de0) + stateConstants);
    break;
  case 0xc:
    stateConstants = *(int *)(ctx + GLD_engineState);
    srcWPtr = (dword *)(((unsigned char *)0x00002dfc) + stateConstants);
    srcYPtr = (dword *)(((unsigned char *)0x00002df4) + stateConstants);
    srcZPtr = (dword *)(((unsigned char *)0x00002df8) + stateConstants);
    srcVec = (float *)(((unsigned char *)0x00002df0) + stateConstants);
    break;
  case 0xd:
    stateConstants = *(int *)(ctx + GLD_engineState);
    srcWPtr = (dword *)(((unsigned char *)0x000030c8) + stateConstants);
    srcYPtr = (dword *)(((unsigned char *)0x000030c0) + stateConstants);
    srcZPtr = (dword *)(((unsigned char *)0x000030c4) + stateConstants);
    srcVec = (float *)(((unsigned char *)0x000030bc) + stateConstants);
    break;
  case 0xe:
    stateConstants = *(int *)(ctx + GLD_engineState);
    srcWPtr = (dword *)(((unsigned char *)0x000030d8) + stateConstants);
    srcYPtr = (dword *)(((unsigned char *)0x000030d0) + stateConstants);
    srcZPtr = (dword *)(((unsigned char *)0x000030d4) + stateConstants);
    srcVec = (float *)(((unsigned char *)0x000030cc) + stateConstants);
    break;
  case 0xf:
    *outSlot = (float)*(double *)(0x00001830 + *(int *)(ctx + GLD_engineState));
    outSlot[1] = (float)*(double *)(*(int *)(ctx + GLD_engineState) + 0x1838);
    dVar31 = *(double *)(0x00001830 + *(int *)(ctx + GLD_engineState));
    dVar29 = *(double *)(*(int *)(ctx + GLD_engineState) + 0x1838);
    outSlot[3] = 1.0;
    outSlot[2] = (float)(dVar29 - dVar31);
    goto LAB_0003c2d0;
  case 0x12:
    fVar6 = *(float *)(*(int *)(ctx + GLD_engineState) + 0x24a4);
    outSlot[3] = fVar6;
    *outSlot = fVar6;
    outSlot[1] = fVar6;
    outSlot[2] = fVar6;
    goto LAB_0003c2d0;
  }
LAB_0003c2b0:
  *outSlot = *srcVec;
  outSlot[1] = (float)*srcYPtr;
  outSlot[2] = (float)*srcZPtr;
  outSlot[3] = (float)*srcWPtr;
LAB_0003c2d0:
  puVar14 = *(undefined8 **)(entryCursor + 4);
  entryCursor = entryCursor + 8;
  uVar30 = *(undefined8 *)(outSlot + 2);
  *puVar14 = *(undefined8 *)outSlot;
  puVar14[1] = uVar30;
  goto joined_r0x0003b9b0;
switchD_0003bf70_caseD_1:
  srcYPtr = ((unsigned char *)0x4);
  srcZPtr = ((unsigned char *)0x8);
  srcWPtr = ((unsigned char *)0xc);
  srcVec = (float *)0x0;
  goto LAB_0003c2b0;
}

/* gldDeleteVertexShaderObject @ 0x3c310 (236 bytes) */
int gldDeleteVertexShaderObject(param_1, param_2)
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
  return glDeleteVertexShaderEXT_impl(param_1,*param_2);
}

/* FUN_0003c400 @ 0x3c400 (4136 bytes) */
int FUN_0003c400(ctx, shaderObject, hwProgram)
  int ctx;
  int *shaderObject;
  undefined4 *hwProgram;
{
  uint instructionWord;
  uint operandWord;
  uint opcode;
  uint *instructionPtr;
  bool isGLSLShader;
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
  int loopIndex;
  uint uVar15;
  uint dstIndex;
  int iVar17;
  int iVar18;
  undefined4 *puVar19;
  int iVar20;
  uint *puVar21;
  uint *nextInstruction;
  int iVar23;
  uint uVar24;
  undefined4 *puVar25;
  undefined4 uVar26;
  char cStack_95;
  char cStack_75;
  undefined4 local_70 [11];
  
  if (shaderObject[8] != 0) {
    isGLSLShader = *shaderObject - 0x8b30U < 2;
    extvsBeginShader(ctx);
    noop_53060(ctx);
    iVar12 = shaderObject[0x12];
    iVar5 = shaderObject[0x13];
    *(undefined1 *)(hwProgram + 0x23) = 0;
    if (iVar12 != 0) {
      loopIndex = 0;
      do {
        cStack_95 = (char)shaderObject[iVar5 * 2 + loopIndex * 2];
        if (cStack_95 == '\0') {
          *(undefined1 *)(hwProgram + 0x23) = 1;
        }
        loopIndex = loopIndex + 1;
        iVar12 = iVar12 + -1;
      } while (iVar12 != 0);
    }
    iVar5 = 0;
    puVar19 = hwProgram;
    do {
      uVar7 = glGenSymbolsEXT_impl5(ctx,0x87bf,0x87c4,0x87e1,1);
      puVar19[0xd] = uVar7;
      uVar7 = glGenSymbolsEXT_impl5(ctx,0x87be,0x87c4,0x87e1,1);
      puVar19[0x10] = uVar7;
      uVar7 = glGenSymbolsEXT_impl5(ctx,0x87bf,0x87c4,0x87e1,1);
      bVar1 = iVar5 != 2;
      iVar5 = iVar5 + 1;
      puVar19[0x13] = uVar7;
      puVar19 = puVar19 + 1;
    } while (bVar1);
    iVar5 = 0;
    uVar7 = glGenSymbolsEXT_impl5(ctx,0x87bf,0x87c4,0x87e1,1);
    hwProgram[0x16] = uVar7;
    uVar7 = glGenSymbolsEXT_impl5(ctx,0x87be,0x87c4,0x87e1,1);
    hwProgram[0x17] = uVar7;
    puVar19 = hwProgram;
    do {
      uVar7 = glGenSymbolsEXT_impl5(ctx,0x87bf,0x87c4,0x87e1,1);
      bVar1 = iVar5 != 1;
      iVar5 = iVar5 + 1;
      puVar19[0x18] = uVar7;
      puVar19 = puVar19 + 1;
    } while (bVar1);
    iVar5 = shaderObject[4];
    if (iVar5 != hwProgram[1]) {
      if (hwProgram[2] != 0) {
        (**(code **)(ctx + GLD_engineObjects))(hwProgram[2]);
        hwProgram[2] = 0;
      }
      if (iVar5 != 0) {
        uVar7 = (**(code **)(ctx + GLD_engineState))(iVar5,4);
        hwProgram[2] = uVar7;
      }
    }
    hwProgram[1] = iVar5;
    if (iVar5 != 0) {
      iVar12 = glGenSymbolsEXT_impl5(ctx,0x87bf,0x87c4,0x87e1,iVar5);
      loopIndex = 0;
      do {
        iVar17 = loopIndex * 4;
        iVar3 = loopIndex + iVar12;
        loopIndex = loopIndex + 1;
        *(int *)(iVar17 + hwProgram[2]) = iVar3;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
    iVar12 = shaderObject[8];
    iVar5 = shaderObject[9];
    if (iVar12 != hwProgram[3]) {
      if (hwProgram[4] != 0) {
        (**(code **)(ctx + GLD_engineObjects))(hwProgram[4]);
        hwProgram[4] = 0;
      }
      if (iVar12 != 0) {
        uVar7 = (**(code **)(ctx + GLD_engineState))(iVar12,4);
        hwProgram[4] = uVar7;
      }
    }
    hwProgram[3] = iVar12;
    if (iVar12 != 0) {
      puVar19 = (undefined4 *)hwProgram[4];
      loopIndex = 0;
      do {
        uVar15 = shaderObject[iVar5 * 2 + loopIndex * 2 + 1];
        if (((uint)shaderObject[iVar5 * 2 + loopIndex * 2] >> 0x10 & 0xf) - 1 < 10) {
          if ((uVar15 & 0xffff) == 0) {
            uVar7 = extvsBindCurrentVertexParameter(ctx,0x87e2);
            *puVar19 = uVar7;
          }
          else {
            uVar7 = glGenSymbolsEXT_impl5(ctx,0x87bf,0x87c1,0x87e1,1);
            puVar19[uVar15 & 0xffff] = uVar7;
          }
        }
        loopIndex = loopIndex + 1;
      } while (iVar12 != loopIndex);
    }
    ((int (*)())FUN_0003b280)(ctx,hwProgram,shaderObject[10],shaderObject + shaderObject[0xb] * 2,shaderObject[0xe],
                 shaderObject + shaderObject[0xf] * 2,shaderObject[0x1a],shaderObject + shaderObject[0x1b] * 2);
    iVar12 = shaderObject[0x14];
    iVar5 = shaderObject[0xd];
    if (iVar12 != 0) {
      loopIndex = 0;
      instructionPtr = (uint *)(shaderObject + shaderObject[0x15] * 2);
      do {
        nextInstruction = instructionPtr + 2;
        opcode = *instructionPtr >> 0x12 & 0xff;
        if ((*instructionPtr & 0x3fc0000) == 0x1340000) goto LAB_0003d23c;
        operandWord = instructionPtr[2];
        if (0x4d < opcode) goto switchD_0003cbec_caseD_3;
        bVar1 = opcode == 0x48;
        if (bVar1) {
          iVar17 = hwProgram[0x17];
          goto LAB_0003c9b8;
        }
        if ((isGLSLShader) && ((operandWord & 0x7000) != 0x3000)) goto switchD_0003cbec_caseD_3;
        uVar6 = operandWord >> 0x11 & 7;
        if (uVar6 == 1) {
          iVar17 = *(int *)((instructionPtr[3] & 0xffff) * 4 + hwProgram[2]);
          goto LAB_0003c9b8;
        }
        if (uVar6 != 3) {
switchD_0003cbec_caseD_3:
          bVar2 = false;
          goto LAB_0003d254;
        }
        uVar6 = shaderObject[iVar5 * 2 + (instructionPtr[3] & 0xffff) * 2];
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
        if (((operandWord & 0x1e000) != 0x1e000) && (!bVar1)) {
          iVar3 = hwProgram[0x16];
        }
        if ((opcode < 0x1f) || ((iVar18 = 2, 0x3a < opcode && (iVar18 = 3, 0x40 < opcode)))) {
          iVar18 = 1;
        }
        iVar20 = 0;
        iVar23 = 0;
        nextInstruction = instructionPtr + 4;
        puVar19 = hwProgram;
        do {
          puVar21 = nextInstruction;
          instructionWord = *puVar21;
          nextInstruction = puVar21 + 2;
          dstIndex = puVar21[1] & 0xffff;
          if ((isGLSLShader) && ((instructionWord & 0x7000) != 0x3000)) goto switchD_0003cbec_caseD_3;
          uVar4 = instructionWord >> 0x17 & 7;
          if (uVar4 == 1) {
            uVar7 = *(undefined4 *)(dstIndex * 4 + hwProgram[2]);
          }
          else if (uVar4 == 2) {
            if ((int)instructionWord < 0) {
              cStack_75 = (char)instructionWord;
              glShaderOp2EXT_impl(ctx,0x8782,puVar19[0x13],hwProgram[0x17],
                           *(undefined4 *)((dstIndex + (int)cStack_75) * 4 + hwProgram[10]));
              uVar7 = puVar19[0x13];
            }
            else {
              uVar7 = *(undefined4 *)(dstIndex * 4 + hwProgram[10]);
            }
          }
          else {
            uVar7 = 0;
            if (uVar4 == 0) {
              uVar7 = *(undefined4 *)(dstIndex * 4 + hwProgram[4]);
            }
          }
          *(undefined4 *)((int)local_70 + iVar23) = uVar7;
          if ((instructionWord & 0x8000000) == 0) {
            iVar8 = (instructionWord >> 0x15 & 3) + 0x87d5;
            iVar10 = (instructionWord >> 0x13 & 3) + 0x87d5;
            iVar11 = (instructionWord >> 0x11 & 3) + 0x87d5;
            iVar13 = (instructionWord >> 0xf & 3) + 0x87d5;
          }
          else {
            iVar8 = (instructionWord >> 0x15 & 3) + 0x87d9;
            iVar10 = (instructionWord >> 0x13 & 3) + 0x87d9;
            iVar11 = (instructionWord >> 0x11 & 3) + 0x87d9;
            iVar13 = (instructionWord >> 0xf & 3) + 0x87d9;
          }
          if ((((iVar8 != 0x87d5) || (iVar10 != 0x87d6)) || (iVar11 != 0x87d7)) ||
             (iVar13 != 0x87d8)) {
            FUN_00054080(ctx,puVar19[0xd],*(undefined4 *)((int)local_70 + iVar23),iVar8,iVar10,
                         iVar11,iVar13);
            *(undefined4 *)((int)local_70 + iVar23) = puVar19[0xd];
          }
          uVar7 = local_70[1];
          iVar20 = iVar20 + 1;
          iVar23 = iVar23 + 4;
          puVar19 = puVar19 + 1;
        } while (iVar18 != iVar20);
        switch(opcode) {
        case 0:
          glShaderOp1EXT_impl(ctx,0x8799,iVar3,local_70[0]);
          break;
        case 1:
          glShaderOp1EXT_impl(ctx,0x879e,iVar3,local_70[0]);
          break;
        case 2:
          FUN_00054080(ctx,hwProgram[0x18],local_70[0],0x87d9,0x87da,0x87db,0x87dc);
          glShaderOp2EXT_impl(ctx,0x878a,iVar3,local_70[0],hwProgram[0x18]);
          break;
        default:
          goto switchD_0003cbec_caseD_3;
        case 4:
          glShaderOp1EXT_impl(ctx,0x8789,iVar3,local_70[0]);
          break;
        case 5:
          glShaderOp1EXT_impl(ctx,0x878f,iVar3,local_70[0]);
          break;
        case 0xd:
          FUN_00054080(ctx,hwProgram[0x18],local_70[0],0x87d9,0x87da,0x87db,0x87dc);
          glShaderOp2EXT_impl(ctx,0x878a,hwProgram[0x19],local_70[0],hwProgram[0x18]);
          glExtractComponentEXT_impl(ctx,hwProgram[0x10],hwProgram[0x19],0);
          uVar26 = hwProgram[0x11];
          uVar9 = hwProgram[0x10];
          uVar7 = 0x8795;
          goto LAB_0003cdec;
        case 0xe:
          glExtractComponentEXT_impl(ctx,hwProgram[0x10],local_70[0],0);
          uVar26 = hwProgram[0x11];
          uVar9 = hwProgram[0x10];
          uVar7 = 0x8794;
          goto LAB_0003cdec;
        case 0x10:
          glExtractComponentEXT_impl(ctx,hwProgram[0x10],local_70[0],0);
          uVar26 = hwProgram[0x11];
          uVar9 = hwProgram[0x10];
          uVar7 = 0x8791;
          goto LAB_0003cdec;
        case 0x11:
          glShaderOp1EXT_impl(ctx,0x87a0,iVar3,local_70[0]);
          break;
        case 0x13:
          glExtractComponentEXT_impl(ctx,hwProgram[0x10],local_70[0],0);
          uVar26 = hwProgram[0x11];
          uVar9 = hwProgram[0x10];
          uVar7 = 0x8792;
LAB_0003cdec:
          glShaderOp1EXT_impl(ctx,uVar7,uVar26,uVar9);
          glShaderOp1EXT_impl(ctx,0x8799,iVar3,hwProgram[0x11]);
          break;
        case 0x14:
          glShaderOp1EXT_impl(ctx,0x87a1,iVar3,local_70[0]);
          break;
        case 0x1f:
          glShaderOp2EXT_impl(ctx,0x8787,iVar3,local_70[0],local_70[1]);
          break;
        case 0x20:
          glShaderOp2EXT_impl(ctx,0x8796,iVar3,local_70[0],local_70[1]);
          break;
        case 0x22:
          glShaderOp2EXT_impl(ctx,0x8786,iVar3,local_70[0],local_70[1]);
          break;
        case 0x28:
          glShaderOp2EXT_impl(ctx,0x8784,iVar3,local_70[0],local_70[1]);
          break;
        case 0x29:
          glShaderOp2EXT_impl(ctx,0x8785,iVar3,local_70[0],local_70[1]);
          break;
        case 0x2a:
          FUN_00054080(ctx,hwProgram[0x18],local_70[0],0x87d5,0x87d6,0x87d7,0x87de);
          glShaderOp2EXT_impl(ctx,0x8785,iVar3,hwProgram[0x18],local_70[1]);
          break;
        case 0x2b:
          glShaderOp2EXT_impl(ctx,0x879f,iVar3,local_70[0],local_70[1]);
          break;
        case 0x2c:
          glShaderOp2EXT_impl(ctx,0x878b,iVar3,local_70[0],local_70[1]);
          break;
        case 0x2d:
          glShaderOp2EXT_impl(ctx,0x878a,iVar3,local_70[0],local_70[1]);
          break;
        case 0x2e:
          glShaderOp2EXT_impl(ctx,0x8797,iVar3,local_70[0],local_70[1]);
          break;
        case 0x32:
          glShaderOp2EXT_impl(ctx,0x878c,iVar3,local_70[0],local_70[1]);
          break;
        case 0x35:
          glShaderOp2EXT_impl(ctx,0x878d,iVar3,local_70[0],local_70[1]);
          break;
        case 0x38:
          glExtractComponentEXT_impl(ctx,hwProgram[0x10],local_70[0],0);
          glExtractComponentEXT_impl(ctx,hwProgram[0x11],uVar7,0);
          glShaderOp2EXT_impl(ctx,0x8793,hwProgram[0x12],hwProgram[0x10],hwProgram[0x11]);
          glShaderOp1EXT_impl(ctx,0x8799,iVar3,hwProgram[0x12]);
          break;
        case 0x3f:
          glShaderOp3EXT_impl(ctx,0x8788,iVar3,local_70[0],local_70[1],local_70[2]);
          break;
        case 0x41:
          uVar15 = *nextInstruction;
          nextInstruction = puVar21 + 4;
          if (((*(int *)(&DAT_001da630 + (uVar15 >> 10 & 0x3c)) != 0x87d5) ||
              (*(int *)(&DAT_001da630 + (uVar15 >> 6 & 0x3c)) != 0x87d6)) ||
             ((*(int *)(&DAT_001da630 + (uVar15 >> 2 & 0x3c)) != 0x87d7 ||
              (*(int *)(&DAT_001da630 + (uVar15 & 0xf) * 4) != 0x87d8)))) {
            FUN_00054080(ctx,iVar3,local_70[0],*(int *)(&DAT_001da630 + (uVar15 >> 10 & 0x3c)),
                         *(int *)(&DAT_001da630 + (uVar15 >> 6 & 0x3c)),
                         *(int *)(&DAT_001da630 + (uVar15 >> 2 & 0x3c)),
                         *(int *)(&DAT_001da630 + (uVar15 & 0xf) * 4));
          }
          break;
        case 0x48:
          glExtractComponentEXT_impl(ctx,iVar3,local_70[0],0);
        }
        if (((operandWord & 0x1e000) != 0x1e000) && (!bVar1)) {
          glWriteMaskEXT_impl(ctx,iVar17,iVar3,operandWord >> 0xd & 1,operandWord >> 0xe & 1,operandWord >> 0xf & 1,
                       operandWord >> 0x10 & 1);
        }
LAB_0003d23c:
        loopIndex = loopIndex + 1;
        instructionPtr = nextInstruction;
      } while (iVar12 != loopIndex);
    }
    bVar2 = true;
LAB_0003d254:
    if (*(char *)(hwProgram + 0x23) != '\0') {
      uVar26 = hwProgram[0x16];
      uVar7 = *(undefined4 *)hwProgram[4];
      glShaderOp2EXT_impl(ctx,0x8785,uVar26,uVar7,hwProgram[0x1a]);
      glWriteMaskEXT_impl(ctx,0x879a,uVar26,1,0,0,0);
      glShaderOp2EXT_impl(ctx,0x8785,uVar26,uVar7,hwProgram[0x1b]);
      glWriteMaskEXT_impl(ctx,0x879a,uVar26,0,1,0,0);
      glShaderOp2EXT_impl(ctx,0x8785,uVar26,uVar7,hwProgram[0x1c]);
      glWriteMaskEXT_impl(ctx,0x879a,uVar26,0,0,1,0);
      glShaderOp2EXT_impl(ctx,0x8785,uVar26,uVar7,hwProgram[0x1d]);
      glWriteMaskEXT_impl(ctx,0x879a,uVar26,0,0,0,1);
    }
    extvsEndShader(ctx);
    if (!bVar2) {
      extvsClearConstantsDirty(ctx);
      return 0;
    }
    iVar5 = extvsConstantsDirty(ctx);
    if (iVar5 != 0) {
      uVar15 = hwProgram[3];
      if (uVar15 != hwProgram[5]) {
        if (hwProgram[6] != 0) {
          (**(code **)(ctx + GLD_engineObjects))(hwProgram[6]);
          hwProgram[6] = 0;
        }
        if (uVar15 != 0) {
          uVar7 = (**(code **)(ctx + GLD_engineState))(uVar15,4);
          hwProgram[6] = uVar7;
        }
      }
      hwProgram[5] = uVar15;
      if (uVar15 != 0) {
        puVar19 = (undefined4 *)hwProgram[6];
        *puVar19 = 0x000308c0;
        if (1 < uVar15) {
          uVar24 = 1;
          iVar5 = 4;
          do {
            uVar24 = uVar24 + 1;
            uVar7 = FUN_00052ee0(ctx,*(undefined4 *)(hwProgram[4] + iVar5));
            *(undefined4 *)((int)puVar19 + iVar5) = uVar7;
            iVar5 = iVar5 + 4;
          } while (uVar15 != uVar24);
        }
      }
      uVar15 = hwProgram[3];
      if (uVar15 != hwProgram[7]) {
        if (hwProgram[8] != 0) {
          (**(code **)(ctx + GLD_engineObjects))(hwProgram[8]);
          hwProgram[8] = 0;
        }
        if (uVar15 != 0) {
          uVar7 = (**(code **)(ctx + GLD_engineState))(uVar15,4);
          hwProgram[8] = uVar7;
        }
      }
      hwProgram[7] = uVar15;
      if (uVar15 != 0) {
        puVar25 = (undefined4 *)hwProgram[8];
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
            iVar5 = FUN_00052f60(ctx,*(undefined4 *)(uVar24 * 4 + hwProgram[4]));
            if (iVar5 != 0x81) {
              puVar25[iVar5 + -1] = uVar24;
            }
            uVar24 = uVar24 + 1;
          } while (uVar15 != uVar24);
        }
      }
      FUN_000530c0(ctx,*hwProgram,hwProgram + 0x1e);
      return 1;
    }
  }
  return 0;
}

/* FUN_0003d590 @ 0x3d590 (2944 bytes) */
int FUN_0003d590(ctx, passThroughArg2, passThroughArg3, operandTable, literalConstants, updateMask)
  int ctx;
  undefined4 passThroughArg2;
  undefined4 passThroughArg3;
  int operandTable;
  int literalConstants;
  int updateMask;
{
  undefined4 constZ;
  undefined4 constY;
  undefined4 constW;
  int entryCountC;
  int entryCountB;
  int entryCountA;
  ushort *entryStateIndexPtr;
  byte destSlot;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  undefined4 uVar9;
  float fVar10;
  uint cmdEndAligned;
  int iVar12;
  undefined *stateRecord;
  dword *srcZPtr;
  int status;
  undefined4 *cmdStart;
  int iVar17;
  int iVar18;
  undefined4 *cmdEnd;
  int iVar20;
  undefined4 *cacheClearedUpTo;
  undefined8 *puVar22;
  float *srcVec;
  undefined4 *cmdCursor;
  int stateConstants;
  dword *srcWPtr;
  int iVar27;
  uint cacheLineMask;
  uint cacheLineAddr;
  dword *srcYPtr;
  int ring;
  float *outSlot;
  byte *entryCursor;
  byte *pbVar34;
  undefined8 uVar35;
  double dVar36;
  undefined8 uVar37;
  double dVar38;
  byte *program;
  int constantTable;
  int local_80 [2];
  uint operandWord;
  undefined4 operandWord2;
  uint operandWordCopy;
  undefined4 operandWord2Copy;
  
  ring = ctx + GLD_commandStream;
  status = FUN_00054470(ring,&program,&constantTable,local_80);
  if (status != 0) {
    ((int (*)())FUN_0003b620)(ctx,program,passThroughArg2,passThroughArg3,operandTable);
  }
  cmdStart = (undefined4 *)(**(code **)(ctx + GLD_streamAllocate))(ring,*(int *)(program + 0x808) * 7 + 2)
  ;
  cacheClearedUpTo = *(undefined4 **)(ctx + 0x2834);
  *(undefined4 **)(ctx + GLD_streamCurrent) = cmdStart;
  cmdEnd = cmdStart + *(int *)(program + 0x808) * 7 + 2;
  cmdCursor = cmdStart;
  if ((cacheClearedUpTo <= cmdStart) || (cmdCursor = cacheClearedUpTo, cacheClearedUpTo < cmdEnd)) {
    cacheLineMask = *(byte *)(ctx + GLD_cacheLineSize) - 1;
    dataCacheBlockTouch(cmdCursor);
    dataCacheBlockTouch((int)cmdEnd + -1);
    cacheLineAddr = ~cacheLineMask;
    cmdEndAligned = cacheLineAddr & (uint)cmdEnd;
    for (cacheLineAddr = cacheLineMask + (int)cmdCursor & cacheLineAddr; cacheLineAddr < cmdEndAligned;
        cacheLineAddr = cacheLineAddr + *(byte *)(ctx + GLD_cacheLineSize)) {
      dataCacheBlockClearToZero(cacheLineAddr);
    }
    *(uint *)(ctx + 0x2834) = cmdEndAligned;
  }
  entryCountA = *(int *)(program + 0x800);
  cmdCursor = cmdStart + 2;
  *cmdStart = 0x8a1;
  cmdStart[1] = 0;
  entryCursor = program;
  if (program < program + entryCountA * 8) {
    stateConstants = *(int *)(ctx + GLD_engineState) + 0x1860;
    do {
      entryStateIndexPtr = (ushort *)(entryCursor + 2);
      destSlot = *entryCursor;
      cmdStart = *(undefined4 **)(entryCursor + 4);
      entryCursor = entryCursor + 8;
      iVar12 = stateConstants + (uint)*entryStateIndexPtr * 4;
      uVar9 = *(undefined4 *)(stateConstants + (uint)*entryStateIndexPtr * 4);
      iVar17 = (uint)destSlot * 0x10;
      constW = *(undefined4 *)(iVar12 + 0x30);
      constY = *(undefined4 *)(iVar12 + 0x10);
      constZ = *(undefined4 *)(iVar12 + 0x20);
      iVar12 = constantTable + iVar17;
      *(undefined4 *)(constantTable + iVar17) = uVar9;
      *(undefined4 *)(iVar12 + 0xc) = constW;
      *(undefined4 *)(iVar12 + 4) = constY;
      *(undefined4 *)(iVar12 + 8) = constZ;
      cmdStart[3] = constW;
      *cmdStart = uVar9;
      cmdStart[1] = constY;
      cmdStart[2] = constZ;
      cmdCursor[1] = local_80[0] + (uint)destSlot;
      cmdCursor[3] = uVar9;
      cmdCursor[4] = constY;
      cmdCursor[5] = constZ;
      cmdCursor[6] = constW;
      *cmdCursor = 0x880;
      cmdCursor[2] = 0x38882;
      cmdCursor = cmdCursor + 7;
    } while (entryCursor < program + entryCountA * 8);
  }
  entryCountB = *(int *)(program + 0x804);
  while (pbVar34 = entryCursor, pbVar34 < program + entryCountB * 8) {
    entryCursor = pbVar34 + 8;
    if ((*(uint *)((pbVar34[1] >> 3 & 0x1c) + updateMask) >> (pbVar34[1] & 0x1f) & 1) != 0) {
      puVar22 = *(undefined8 **)(pbVar34 + 4);
      destSlot = *pbVar34;
      *cmdCursor = 0x880;
      cmdCursor[2] = 0x38882;
      stateConstants = (uint)destSlot * 0x10;
      uVar37 = puVar22[1];
      uVar35 = *puVar22;
      cmdCursor[1] = local_80[0] + (uint)destSlot;
      *(undefined8 *)(cmdCursor + 3) = uVar35;
      *(undefined8 *)(constantTable + stateConstants) = uVar35;
      *(undefined8 *)(cmdCursor + 5) = uVar37;
      *(undefined8 *)(constantTable + stateConstants + 8) = uVar37;
      cmdCursor = cmdCursor + 7;
    }
  }
  entryCountC = *(int *)(program + 0x808);
LAB_0003d820:
  while( true ) {
    if (program + entryCountC * 8 <= pbVar34) {
      *(undefined4 **)(ctx + GLD_streamCurrent) = cmdCursor;
      (**(code **)(ctx + GLD_streamSetCurrent))(ring,cmdCursor);
      return;
    }
    if ((*(uint *)((pbVar34[1] >> 3 & 0x1c) + updateMask) >> (pbVar34[1] & 0x1f) & 1) != 0) break;
    pbVar34 = pbVar34 + 8;
  }
  destSlot = *pbVar34;
  outSlot = (float *)(cmdCursor + 3);
  operandWord = *(uint *)((uint)*(ushort *)(pbVar34 + 2) * 8 + operandTable);
  operandWord2 = *(undefined4 *)((uint)*(ushort *)(pbVar34 + 2) * 8 + operandTable + 4);
  cmdCursor[1] = local_80[0] + (uint)destSlot;
  cmdCursor[2] = 0x38882;
  *cmdCursor = 0x880;
  if ((operandWord >> 0x10 & 0x1f) == 1) {
    stateConstants = (operandWord & 0xffff) * 0x10;
    iVar17 = stateConstants + literalConstants;
    if (*(int *)(*(int *)(ctx + GLD_engineObjects) + 0x198) == 0) {
      uVar3 = *(undefined4 *)(iVar17 + 0xc);
      uVar4 = *(undefined4 *)(iVar17 + 4);
      uVar5 = *(undefined4 *)(iVar17 + 8);
      cmdCursor[3] = *(undefined4 *)(stateConstants + literalConstants);
      cmdCursor[6] = uVar3;
      cmdCursor[4] = uVar4;
      cmdCursor[5] = uVar5;
    }
    else {
      _glpUniformToFloat(*(undefined4 *)(**(int **)(ctx + GLD_currentProgram) + 4),operandWord & 0xffff,iVar17,
                         outSlot);
    }
    goto LAB_0003e170;
  }
  operandWordCopy = operandWord;
  operandWord2Copy = operandWord2;
  if ((operandWord & 0x1f0000) == 0x100000) {
    cacheLineAddr = operandWord >> 0xc & 3;
    cmdEndAligned = operandWord & 0xff;
    switch(operandWord >> 8 & 7) {
    default:
      stateConstants = 0;
      break;
    case 1:
      stateConstants = 0xc0;
      break;
    case 2:
      stateConstants = 0x80;
      break;
    case 3:
      stateConstants = (cmdEndAligned + 4) * 0x40;
      break;
    case 4:
      stateConstants = (cmdEndAligned + 0x10) * 0x40;
      break;
    case 5:
      stateConstants = (cmdEndAligned + 8) * 0x40;
    }
    cmdEndAligned = operandWord >> 0xe & 3;
    iVar17 = *(int *)(ctx + GLD_engineState) + 0x1860 + stateConstants;
    if ((1 < cmdEndAligned) && (iVar17 = stateConstants + *(int *)(ctx + GLD_engineState) + 0x1e60, 3 < cmdEndAligned)) {
      iVar17 = 0;
    }
    if (cmdEndAligned < 3) {
      if (cmdEndAligned == 0) {
LAB_0003dd8c:
        stateConstants = cacheLineAddr * 4;
        iVar12 = iVar17 + stateConstants;
        *outSlot = *(float *)(iVar17 + stateConstants);
        cmdCursor[4] = *(undefined4 *)(iVar12 + 0x10);
        cmdCursor[5] = *(undefined4 *)(iVar12 + 0x20);
        cmdCursor[6] = *(undefined4 *)(iVar12 + 0x30);
      }
      else {
        stateConstants = cacheLineAddr * 0x10;
        iVar12 = iVar17 + stateConstants;
        *outSlot = *(float *)(iVar17 + stateConstants);
        cmdCursor[4] = *(undefined4 *)(iVar12 + 4);
        cmdCursor[5] = *(undefined4 *)(iVar12 + 8);
        cmdCursor[6] = *(undefined4 *)(iVar12 + 0xc);
      }
    }
    else if (cmdEndAligned == 3) goto LAB_0003dd8c;
    goto LAB_0003e170;
  }
  switch(operandWord >> 0x10 & 0x1f) {
  case 0:
    srcYPtr = cmdCursor + 4;
    srcZPtr = cmdCursor + 5;
    srcWPtr = cmdCursor + 6;
    srcVec = outSlot;
    break;
  default:
    goto switchD_0003de14_caseD_1;
  case 2:
    srcVec = (float *)((operandWord & 0xffff) * 0x10 +
                       *(int *)(((unsigned char *)0x00004308) + *(int *)(ctx + GLD_engineState)));
    srcYPtr = (dword *)(srcVec + 1);
    srcZPtr = (dword *)(srcVec + 2);
    srcWPtr = (dword *)(srcVec + 3);
    break;
  case 3:
    cacheLineAddr = operandWord & 0xff;
    switch(operandWord >> 8 & 0xf) {
    case 0:
      srcVec = (float *)(cacheLineAddr * 0x80 + 0x24c0 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(srcVec + 1);
      srcZPtr = (dword *)(srcVec + 2);
      srcWPtr = (dword *)(srcVec + 3);
      break;
    case 1:
      srcVec = (float *)(cacheLineAddr * 0x80 + 0x24d0 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(srcVec + 1);
      srcZPtr = (dword *)(srcVec + 2);
      srcWPtr = (dword *)(srcVec + 3);
      break;
    case 2:
      srcVec = (float *)(cacheLineAddr * 0x80 + 0x24e0 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(srcVec + 1);
      srcZPtr = (dword *)(srcVec + 2);
      srcWPtr = (dword *)(srcVec + 3);
      break;
    case 3:
      srcVec = (float *)(cacheLineAddr * 0x80 + 0x24f0 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(srcVec + 1);
      srcZPtr = (dword *)(srcVec + 2);
      srcWPtr = (dword *)(srcVec + 3);
      break;
    case 4:
      srcVec = (float *)(cacheLineAddr * 0x80 + 0x2500 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(srcVec + 1);
      srcZPtr = (dword *)(srcVec + 2);
      srcWPtr = (dword *)(srcVec + 3);
      break;
    case 5:
      srcVec = (float *)(cacheLineAddr * 0x80 + 0x2510 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(srcVec + 1);
      srcZPtr = (dword *)(srcVec + 2);
      srcWPtr = (dword *)(srcVec + 3);
      break;
    case 6:
      stateConstants = cacheLineAddr * 0x80 + *(int *)(ctx + GLD_engineState);
      fVar7 = *(float *)(stateConstants + 0x24f4);
      fVar8 = *(float *)(stateConstants + 0x24f0);
      fVar10 = *(float *)(stateConstants + 0x24f8) + 1.0;
      dVar36 = _sqrt((double)(fVar10 * fVar10 + fVar8 * fVar8 + fVar7 * fVar7));
      cmdCursor[6] = 1.0;
      fVar6 = (float)(1.0 / dVar36);
      cmdCursor[5] = fVar10 * fVar6;
      *outSlot = fVar8 * fVar6;
      cmdCursor[4] = fVar7 * fVar6;
      goto LAB_0003e170;
    case 7:
      srcVec = (float *)(cacheLineAddr * 0x80 + 0x2530 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(srcVec + 1);
      srcZPtr = (dword *)(srcVec + 2);
      srcWPtr = (dword *)(srcVec + 3);
      break;
    default:
      goto switchD_0003de14_caseD_1;
    }
    break;
  case 4:
    cacheLineAddr = operandWord >> 9 & 3;
    iVar18 = *(int *)(ctx + GLD_engineState) + 0x24c0;
    stateConstants = (operandWord & 0xff) * 0x80;
    iVar17 = (operandWord >> 8 & 1) * 0x240;
    iVar12 = *(int *)(ctx + GLD_engineState) + 0x28c0;
    iVar27 = iVar18 + stateConstants;
    iVar20 = iVar12 + iVar17;
    if (cacheLineAddr == 1) {
      *outSlot = *(float *)(iVar27 + 0x10) * *(float *)(iVar20 + 0x10);
      cmdCursor[4] = *(float *)(iVar27 + 0x14) * *(float *)(iVar20 + 0x14);
      cmdCursor[5] = *(float *)(iVar27 + 0x18) * *(float *)(iVar20 + 0x18);
      cmdCursor[6] = *(undefined4 *)(iVar20 + 0x1c);
    }
    else if (cacheLineAddr == 2) {
      *outSlot = *(float *)(iVar27 + 0x20) * *(float *)(iVar20 + 0x20);
      cmdCursor[4] = *(float *)(iVar27 + 0x24) * *(float *)(iVar20 + 0x24);
      cmdCursor[5] = *(float *)(iVar27 + 0x28) * *(float *)(iVar20 + 0x28);
      cmdCursor[6] = *(undefined4 *)(iVar20 + 0x2c);
    }
    else {
      if (cacheLineAddr != 0) goto switchD_0003de14_caseD_1;
      *outSlot = *(float *)(iVar18 + stateConstants) * *(float *)(iVar12 + iVar17);
      cmdCursor[4] = *(float *)(iVar27 + 4) * *(float *)(iVar20 + 4);
      cmdCursor[5] = *(float *)(iVar27 + 8) * *(float *)(iVar20 + 8);
      cmdCursor[6] = *(undefined4 *)(iVar20 + 0xc);
    }
    goto LAB_0003e170;
  case 5:
    cacheLineAddr = operandWord & 1;
    switch(operandWord >> 1 & 7) {
    case 0:
      srcVec = (float *)(cacheLineAddr * 0x240 + 0x28c0 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(srcVec + 1);
      srcZPtr = (dword *)(srcVec + 2);
      srcWPtr = (dword *)(srcVec + 3);
      break;
    case 1:
      srcVec = (float *)(cacheLineAddr * 0x240 + 0x28d0 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(srcVec + 1);
      srcZPtr = (dword *)(srcVec + 2);
      srcWPtr = (dword *)(srcVec + 3);
      break;
    case 2:
      srcVec = (float *)(cacheLineAddr * 0x240 + 0x28e0 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(srcVec + 1);
      srcZPtr = (dword *)(srcVec + 2);
      srcWPtr = (dword *)(srcVec + 3);
      break;
    case 3:
      srcVec = (float *)(cacheLineAddr * 0x240 + 0x28f0 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(srcVec + 1);
      srcZPtr = (dword *)(srcVec + 2);
      srcWPtr = (dword *)(srcVec + 3);
      break;
    case 4:
      srcVec = (float *)(cacheLineAddr * 0x240 + 0x2900 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(srcVec + 1);
      srcZPtr = (dword *)(srcVec + 2);
      srcWPtr = (dword *)(srcVec + 3);
      break;
    case 5:
      stateConstants = *(int *)(ctx + GLD_engineState);
      iVar17 = stateConstants + 0x28c0 + cacheLineAddr * 0x240;
      *outSlot = *(float *)(stateConstants + 0x24b0) * *(float *)(stateConstants + 0x28c0 + cacheLineAddr * 0x240) +
                 *(float *)(iVar17 + 0x30);
      cmdCursor[4] = *(float *)(stateConstants + 0x24b4) * *(float *)(iVar17 + 4) + *(float *)(iVar17 + 0x34);
      cmdCursor[5] = *(float *)(stateConstants + 0x24b8) * *(float *)(iVar17 + 8) + *(float *)(iVar17 + 0x38);
      cmdCursor[6] = *(undefined4 *)(iVar17 + 0x1c);
      goto LAB_0003e170;
    default:
      goto switchD_0003de14_caseD_1;
    }
    break;
  case 6:
    stateConstants = *(int *)(ctx + GLD_engineState);
    srcWPtr = (dword *)(stateConstants + 0x24bc);
    srcYPtr = (dword *)(stateConstants + 0x24b4);
    srcZPtr = (dword *)(stateConstants + 0x24b8);
    srcVec = (float *)(stateConstants + 0x24b0);
    break;
  case 7:
    cmdEndAligned = operandWord >> 5 & 7;
    cacheLineAddr = operandWord & 0x1f;
    if (cmdEndAligned == 1) {
      stateConstants = *(int *)(ctx + GLD_engineState);
      stateRecord = ((unsigned char *)0x000039a0) + cacheLineAddr * 0x94;
LAB_0003d908:
      srcWPtr = (dword *)(stateRecord + stateConstants + 0x1c);
      srcYPtr = (dword *)(stateRecord + stateConstants + 0x14);
      srcZPtr = (dword *)(stateRecord + stateConstants + 0x18);
      srcVec = (float *)(stateRecord + stateConstants + 0x10);
    }
    else {
      if (cmdEndAligned < 2) {
        if (cmdEndAligned == 0) {
          stateConstants = *(int *)(ctx + GLD_engineState);
          stateRecord = ((unsigned char *)0x00003980) + cacheLineAddr * 0x94;
          goto LAB_0003d8e4;
        }
        goto switchD_0003de14_caseD_1;
      }
      if (cmdEndAligned == 2) {
        stateConstants = *(int *)(ctx + GLD_engineState);
        stateRecord = ((unsigned char *)0x000039c0) + cacheLineAddr * 0x94;
LAB_0003d92c:
        srcWPtr = (dword *)(stateRecord + stateConstants + 0x20);
        srcYPtr = (dword *)(stateRecord + stateConstants + 0x18);
        srcZPtr = (dword *)(stateRecord + stateConstants + 0x1c);
        srcVec = (float *)(stateRecord + stateConstants + 0x14);
      }
      else {
        if (cmdEndAligned != 3) goto switchD_0003de14_caseD_1;
        stateConstants = *(int *)(ctx + GLD_engineState);
        stateRecord = ((unsigned char *)0x000039e0) + cacheLineAddr * 0x94;
LAB_0003d950:
        srcWPtr = (dword *)(stateRecord + stateConstants + 0x24);
        srcYPtr = (dword *)(stateRecord + stateConstants + 0x1c);
        srcZPtr = (dword *)(stateRecord + stateConstants + 0x20);
        srcVec = (float *)(stateRecord + stateConstants + 0x18);
      }
    }
    break;
  case 8:
    cmdEndAligned = operandWord >> 5 & 7;
    cacheLineAddr = operandWord & 0x1f;
    if (cmdEndAligned == 1) {
      stateConstants = *(int *)(ctx + GLD_engineState);
      stateRecord = ((unsigned char *)0x000039b0) + cacheLineAddr * 0x94;
      goto LAB_0003d908;
    }
    if (cmdEndAligned < 2) {
      if (cmdEndAligned == 0) {
        stateConstants = *(int *)(ctx + GLD_engineState);
        stateRecord = ((unsigned char *)0x00003990) + cacheLineAddr * 0x94;
        goto LAB_0003d8e4;
      }
    }
    else {
      if (cmdEndAligned == 2) {
        stateConstants = *(int *)(ctx + GLD_engineState);
        stateRecord = ((unsigned char *)0x000039d0) + cacheLineAddr * 0x94;
        goto LAB_0003d92c;
      }
      if (cmdEndAligned == 3) {
        stateConstants = *(int *)(ctx + GLD_engineState);
        stateRecord = ((unsigned char *)0x000039f0) + cacheLineAddr * 0x94;
        goto LAB_0003d950;
      }
    }
    goto switchD_0003de14_caseD_1;
  case 9:
    stateConstants = *(int *)(ctx + GLD_engineState) + (operandWord & 0x1f) * 0x7c;
    srcWPtr = (dword *)(((unsigned char *)0x000031c0) + stateConstants + 0x10);
    srcZPtr = (dword *)(((unsigned char *)0x000031c0) + stateConstants + 0xc);
    srcYPtr = (dword *)(((unsigned char *)0x000031c0) + stateConstants + 8);
    srcVec = (float *)(((unsigned char *)0x000031c0) + stateConstants + 4);
    break;
  case 10:
    stateConstants = *(int *)(ctx + GLD_engineState);
    stateRecord = ((unsigned char *)0x00003e20) + (operandWord & 0xff) * 0x10;
LAB_0003d8e4:
    srcWPtr = (dword *)(stateRecord + stateConstants + 0x18);
    srcYPtr = (dword *)(stateRecord + stateConstants + 0x10);
    srcZPtr = (dword *)(stateRecord + stateConstants + 0x14);
    srcVec = (float *)(stateRecord + stateConstants + 0xc);
    break;
  case 0xb:
    stateConstants = *(int *)(ctx + GLD_engineState);
    srcWPtr = (dword *)(((unsigned char *)0x00002dec) + stateConstants);
    srcYPtr = (dword *)(((unsigned char *)0x00002de4) + stateConstants);
    srcZPtr = (dword *)(((unsigned char *)0x00002de8) + stateConstants);
    srcVec = (float *)(((unsigned char *)0x00002de0) + stateConstants);
    break;
  case 0xc:
    stateConstants = *(int *)(ctx + GLD_engineState);
    srcWPtr = (dword *)(((unsigned char *)0x00002dfc) + stateConstants);
    srcYPtr = (dword *)(((unsigned char *)0x00002df4) + stateConstants);
    srcZPtr = (dword *)(((unsigned char *)0x00002df8) + stateConstants);
    srcVec = (float *)(((unsigned char *)0x00002df0) + stateConstants);
    break;
  case 0xd:
    stateConstants = *(int *)(ctx + GLD_engineState);
    srcWPtr = (dword *)(((unsigned char *)0x000030c8) + stateConstants);
    srcYPtr = (dword *)(((unsigned char *)0x000030c0) + stateConstants);
    srcZPtr = (dword *)(((unsigned char *)0x000030c4) + stateConstants);
    srcVec = (float *)(((unsigned char *)0x000030bc) + stateConstants);
    break;
  case 0xe:
    stateConstants = *(int *)(ctx + GLD_engineState);
    srcWPtr = (dword *)(((unsigned char *)0x000030d8) + stateConstants);
    srcYPtr = (dword *)(((unsigned char *)0x000030d0) + stateConstants);
    srcZPtr = (dword *)(((unsigned char *)0x000030d4) + stateConstants);
    srcVec = (float *)(((unsigned char *)0x000030cc) + stateConstants);
    break;
  case 0xf:
    *outSlot = (float)*(double *)(0x00001830 + *(int *)(ctx + GLD_engineState));
    cmdCursor[4] = (float)*(double *)(*(int *)(ctx + GLD_engineState) + 0x1838);
    dVar38 = *(double *)(0x00001830 + *(int *)(ctx + GLD_engineState));
    dVar36 = *(double *)(*(int *)(ctx + GLD_engineState) + 0x1838);
    cmdCursor[6] = 0x3f800000;
    cmdCursor[5] = (float)(dVar36 - dVar38);
    goto LAB_0003e170;
  case 0x12:
    fVar6 = *(float *)(*(int *)(ctx + GLD_engineState) + 0x24a4);
    cmdCursor[6] = fVar6;
    *outSlot = fVar6;
    cmdCursor[4] = fVar6;
    cmdCursor[5] = fVar6;
    goto LAB_0003e170;
  }
LAB_0003e150:
  *outSlot = *srcVec;
  cmdCursor[4] = *srcYPtr;
  cmdCursor[5] = *srcZPtr;
  cmdCursor[6] = *srcWPtr;
LAB_0003e170:
  uVar37 = *(undefined8 *)(cmdCursor + 5);
  uVar35 = *(undefined8 *)outSlot;
  stateConstants = (uint)destSlot * 0x10;
  cmdCursor = cmdCursor + 7;
  *(undefined8 *)(constantTable + stateConstants) = uVar35;
  *(undefined8 *)(constantTable + stateConstants + 8) = uVar37;
  puVar22 = *(undefined8 **)(pbVar34 + 4);
  pbVar34 = pbVar34 + 8;
  puVar22[1] = uVar37;
  *puVar22 = uVar35;
  goto LAB_0003d820;
switchD_0003de14_caseD_1:
  srcYPtr = ((unsigned char *)0x4);
  srcZPtr = ((unsigned char *)0x8);
  srcWPtr = ((unsigned char *)0xc);
  srcVec = (float *)0x0;
  goto LAB_0003e150;
}

/* gldUpdateTextureTargetDirtyMask @ 0x3e1d0 (124 bytes) */
int gldUpdateTextureTargetDirtyMask(param_1)
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
int FUN_0003e320(param_1, dirtyBits, param_3)
  int param_1;
  undefined4 dirtyBits;
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
    iVar2 = glGenFragmentShadersATI_impl(param_1,1);
    *param_2 = iVar2;
    if (iVar2 == 0) {
      return 0;
    }
  }
  glBindFragmentShaderATI_impl(param_1,iVar2);
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
  int loopIndex;
  
  if (param_3 != 0) {
    loopIndex = 0;
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
        glSetFragmentShaderConstantATI_impl(param_1,(uVar1 >> 0x14 & 0xff) + 0x8941,iVar3);
      }
      loopIndex = loopIndex + 1;
    } while (param_3 != loopIndex);
  }
  return;
}

/* gldDeleteFragmentShaderObject @ 0x3e4c0 (8 bytes) */
int gldDeleteFragmentShaderObject(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  return glDeleteFragmentShaderATI_impl(param_1,*param_2);
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl glGenerateMipmap_impl");
asm(".set glGenerateMipmap_impl, _glGenerateMipmap_impl");
asm(".globl FUN_000353a0");
asm(".set FUN_000353a0, _FUN_000353a0");
asm(".globl glTexSubImage_impl");
asm(".set glTexSubImage_impl, _glTexSubImage_impl");
asm(".globl FUN_00039330");
asm(".set FUN_00039330, _gldPrimInlineLineStrip");
asm(".globl FUN_00039610");
asm(".set FUN_00039610, _gldPrimInlineTriangleFan");
asm(".globl FUN_00039a60");
asm(".set FUN_00039a60, _gldPrimInlineTriangles");
asm(".globl FUN_00039d40");
asm(".set FUN_00039d40, _gldPrimInlineTriangleStrip");
asm(".globl FUN_0003a020");
asm(".set FUN_0003a020, _gldPrimInlineQuads");
asm(".globl FUN_0003a300");
asm(".set FUN_0003a300, _gldPrimInlineQuadStrip");
asm(".globl FUN_0003a5e0");
asm(".set FUN_0003a5e0, _gldPrimInlinePolygon");
asm(".globl FUN_0003a8c0");
asm(".set FUN_0003a8c0, _gldPrimInlinePoints");
asm(".globl FUN_0003aba0");
asm(".set FUN_0003aba0, _gldPrimInlineLines");
asm(".globl FUN_0003ae80");
asm(".set FUN_0003ae80, _gldPrimInlineLineLoop");
