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
  byte scratchFlag1;
  byte scratchFlag2;
  byte scratchFlag3;
  ushort scratchUint4;
  ushort scratchUint5;
  ushort scratchUint6;
  ushort scratchUint7;
  ushort scratchUint8;
  ushort scratchUint9;
  short scratchShort10;
  undefined2 scratchUint11;
  float scratchFloat12;
  undefined *scratchPtr13;
  uint scratchUint14;
  uint scratchUint15;
  uint scratchUint16;
  uint scratchUint17;
  uint scratchUint18;
  uint scratchUint19;
  uint scratchUint20;
  uint scratchUint21;
  uint scratchUint22;
  uint scratchUint23;
  char scratchChar24;
  byte textureTarget;
  int scratchInt26;
  ushort *texImages;
  char scratchChar29;
  int scratchInt28;
  int *hwState;
  double scratchDouble31;
  double scratchDouble32;
  
  hwState = texture + 0xf;
  texture[0x2e] = (int)texture;
  scratchDouble31 = DOUBLE_001aa240;
  texImages = (ushort *)texture[0xc];
  *(byte *)((int)texture + 0x3d) = (byte)(-(uint)texImages[0x2e] >> 0x1f);
  scratchUint15 = (uint)(int)((double)*(float *)(texImages + 0x18) + scratchDouble31);
  scratchUint17 = (uint)(int)((double)*(float *)(texImages + 0x1a) + scratchDouble31);
  scratchUint14 = (uint)*(byte *)(texImages + 0x2f);
  scratchUint16 = scratchUint15 + scratchUint14;
  if ((int)scratchUint16 < 0) {
    scratchUint16 = 0;
  }
  if ((int)scratchUint14 < (int)scratchUint16) {
    scratchUint14 = scratchUint16;
  }
  scratchUint22 = (uint)(short)texImages[0x1e];
  scratchUint16 = scratchUint17 + scratchUint22;
  if (((int)scratchUint16 < (int)scratchUint14) && (scratchUint14 = scratchUint22, (int)scratchUint22 < (int)scratchUint16)) {
    scratchUint14 = scratchUint16;
  }
  scratchUint16 = (uint)*(byte *)((int)texImages + 0x5f);
  if ((int)scratchUint14 <= (int)(uint)*(byte *)((int)texImages + 0x5f)) {
    scratchUint16 = scratchUint14;
  }
  if ((int)scratchUint15 < 0) {
    scratchUint15 = 0;
  }
  if ((int)scratchUint15 < (int)scratchUint17) {
    scratchUint17 = scratchUint15;
  }
  if ((int)((int)(short)texImages[0x1f] - scratchUint22) < (int)scratchUint17) {
    scratchUint17 = (int)(short)texImages[0x1f] - scratchUint22;
  }
  scratchUint15 = scratchUint17;
  if ((int)(uint)*(byte *)(texImages + 0x32) < (int)scratchUint17) {
    scratchUint15 = (uint)*(byte *)(texImages + 0x32);
  }
  if ((int)scratchUint15 < 0) {
    scratchUint15 = 0;
  }
  scratchUint15 = scratchUint15 & 0xff;
  scratchUint14 = scratchUint17;
  if ((int)(uint)*(byte *)((int)texImages + 0x65) < (int)scratchUint17) {
    scratchUint14 = (uint)*(byte *)((int)texImages + 0x65);
  }
  if ((int)scratchUint14 < 0) {
    scratchUint14 = 0;
  }
  scratchUint14 = scratchUint14 & 0xff;
  if ((int)(uint)*(byte *)(texImages + 0x33) < (int)scratchUint17) {
    scratchUint17 = (uint)*(byte *)(texImages + 0x33);
  }
  if ((int)scratchUint17 < 0) {
    scratchUint17 = 0;
  }
  scratchUint4 = *(ushort *)(texture + 0x1d);
  scratchFlag1 = *(byte *)((int)texture + 0x73);
  scratchUint5 = *(ushort *)((int)texture + 0x7a);
  scratchUint18 = (uint)*(ushort *)((int)texture + 0x3e);
  scratchUint6 = *(ushort *)(texture + 0x1f);
  scratchUint7 = *(ushort *)((int)texture + 0x76);
  scratchUint22 = (uint)scratchUint7;
  scratchUint8 = *(ushort *)(texture + 0x1e);
  scratchUint21 = (uint)scratchUint8;
  *(undefined1 *)((int)texture + 0x6e) = *(undefined1 *)(texImages + 0x35);
  scratchFlag2 = *(byte *)(texture + 0x1b);
  *(ushort *)(texture + 0x1d) = texImages[1];
  scratchUint20 = (uint)*(byte *)(texture + 0xe);
  *(byte *)((int)texture + 0x73) = *(byte *)(texture + 0xe);
  scratchUint17 = (uint)*(byte *)(texImages + 0x33) - (scratchUint17 & 0xff);
  *(short *)((int)texture + 0x7a) = (short)scratchUint17;
  scratchUint9 = texImages[1];
  scratchUint19 = (uint)scratchUint9;
  *(ushort *)(texture + 0x1f) = *(ushort *)((int)texture + 0x3e);
  *(ushort *)(texture + 0x1d) = scratchUint9;
  textureTarget = *(byte *)(texture[0xc] + 1) & 0xf;
  *(byte *)(texture + 0x1b) = textureTarget;
  scratchDouble31 = DOUBLE_001aa250;
  switch(textureTarget) {
  case 0:
    scratchUint22 = 1 << (*(byte *)(texImages + 0x32) - scratchUint15 & 0x3f);
    *(short *)((int)texture + 0x76) = (short)scratchUint22;
    scratchFlag3 = *(byte *)((int)texImages + 0x65);
    *(undefined1 *)((int)texture + 0x6d) = 2;
    scratchUint21 = 1 << (scratchFlag3 - scratchUint14 & 0x3f);
    *(short *)(texture + 0x1e) = (short)scratchUint21;
    texture[0x20] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,scratchUint22 & 0xffff) - scratchDouble31));
    texture[0x21] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,scratchUint21 & 0xffff) - scratchDouble31));
    break;
  case 1:
    scratchUint22 = 1 << (*(byte *)(texImages + 0x32) - scratchUint15 & 0x3f);
    *(short *)((int)texture + 0x76) = (short)scratchUint22;
    scratchFlag3 = *(byte *)((int)texImages + 0x65);
    *(undefined1 *)((int)texture + 0x6d) = 3;
    scratchUint21 = 1 << (scratchFlag3 - scratchUint14 & 0x3f);
    *(short *)(texture + 0x1e) = (short)scratchUint21;
    texture[0x20] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,scratchUint22 & 0xffff) - scratchDouble31));
    texture[0x21] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,scratchUint21 & 0xffff) - scratchDouble31));
    break;
  case 2:
    scratchUint22 = (uint)texImages[scratchUint16 * 0xc + 0x52] +
             (uint)*(byte *)(texImages + scratchUint16 * 0xc + 0x55) * -2;
    *(short *)((int)texture + 0x76) = (short)scratchUint22;
    scratchFlag3 = *(byte *)(texImages + scratchUint16 * 0xc + 0x55);
    scratchUint9 = texImages[scratchUint16 * 0xc + 0x53];
    *(undefined1 *)((int)texture + 0x6d) = 2;
    scratchUint21 = (uint)scratchUint9 + (uint)scratchFlag3 * -2;
    *(short *)(texture + 0x1e) = (short)scratchUint21;
    texture[0x20] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,scratchUint22 & 0xffff) - scratchDouble31));
    texture[0x21] = (int)GH_F2U((float)((double)CONCAT44(0x43300000,scratchUint21 & 0xffff) - scratchDouble31));
    break;
  case 3:
    scratchInt26 = ((int (*)())gldTextureHasNonPowerOfTwoSize2)(texture,scratchUint18,scratchUint19,scratchUint22,scratchUint20,scratchUint21);
    if (scratchInt26 == 0) {
      *(short *)((int)texture + 0x76) = (short)(1 << (*(byte *)(texImages + 0x32) - scratchUint15 & 0x3f));
      *(short *)(texture + 0x1e) = (short)(1 << (*(byte *)((int)texImages + 0x65) - scratchUint14 & 0x3f));
    }
    else {
      *(ushort *)((int)texture + 0x76) =
           texImages[scratchUint16 * 0xc + 0x52] + (ushort)*(byte *)(texImages + scratchUint16 * 0xc + 0x55) * -2;
      *(ushort *)(texture + 0x1e) =
           texImages[scratchUint16 * 0xc + 0x53] + (ushort)*(byte *)(texImages + scratchUint16 * 0xc + 0x55) * -2;
    }
    scratchDouble31 = DOUBLE_001aa250;
    scratchUint22 = (uint)*(ushort *)((int)texture + 0x76);
    scratchUint21 = (uint)*(ushort *)(texture + 0x1e);
    *(undefined1 *)((int)texture + 0x6d) = 2;
    scratchUint20 = (uint)*(byte *)((int)texture + 0x73);
    textureTarget = *(byte *)(texture + 0x1b);
    scratchUint17 = (uint)*(ushort *)((int)texture + 0x7a);
    scratchUint19 = (uint)*(ushort *)(texture + 0x1d);
    scratchUint18 = (uint)*(ushort *)(texture + 0x1f);
    texture[0x21] =
         (int)GH_F2U((float)((double)CONCAT44(0x43300000,(uint)*(ushort *)(texture + 0x1e)) - scratchDouble31));
    texture[0x20] =
         (int)GH_F2U((float)((double)CONCAT44(0x43300000,(uint)*(ushort *)((int)texture + 0x76)) - scratchDouble31));
    break;
  case 4:
    scratchInt26 = ((int (*)())gldTextureHasNonPowerOfTwoSize2)(texture,scratchUint18,scratchUint19,scratchUint22,scratchUint20,scratchUint21);
    if (scratchInt26 == 0) {
      *(short *)((int)texture + 0x76) = (short)(1 << (*(byte *)(texImages + 0x32) - scratchUint15 & 0x3f));
    }
    else {
      *(ushort *)((int)texture + 0x76) =
           texImages[scratchUint16 * 0xc + 0x52] + (ushort)*(byte *)(texImages + scratchUint16 * 0xc + 0x55) * -2;
    }
    scratchUint22 = (uint)*(ushort *)((int)texture + 0x76);
    scratchUint21 = 1;
    *(undefined2 *)(texture + 0x1e) = 1;
    texture[0x21] = 0x3f800000;
    *(undefined1 *)((int)texture + 0x6d) = 1;
    scratchUint20 = (uint)*(byte *)((int)texture + 0x73);
    textureTarget = *(byte *)(texture + 0x1b);
    scratchUint17 = (uint)*(ushort *)((int)texture + 0x7a);
    scratchUint19 = (uint)*(ushort *)(texture + 0x1d);
    scratchUint18 = (uint)*(ushort *)(texture + 0x1f);
    texture[0x20] =
         (int)GH_F2U((float)((double)CONCAT44(0x43300000,(uint)*(ushort *)((int)texture + 0x76)) -
                     DOUBLE_001aa250));
  }
  if (((((scratchFlag1 != scratchUint20) || (scratchFlag2 != textureTarget)) || ((uint)scratchUint7 != (scratchUint22 & 0xffff))) ||
      (((uint)scratchUint8 != (scratchUint21 & 0xffff) || ((uint)scratchUint5 != (scratchUint17 & 0xffff))))) ||
     ((scratchUint4 != scratchUint19 || (scratchUint6 != scratchUint18)))) {
    *(undefined1 *)((int)texture + 0x71) = 0;
    scratchUint14 = texture[0x17];
    texture[0x15] = texture[0x15] & 0xbfdfffff;
    scratchUint23 = ((scratchUint21 & 0xffff) - 1) * 0x20 & 0x10000 |
             ((scratchUint22 & 0xffff) - 1) * 0x10 & 0x8000 | scratchUint18 - 1 & 0x3fff;
    texture[0x17] = scratchUint14 & 0xfffffe1f;
    texture[0x18] = scratchUint23;
    scratchPtr13 = PTR_DAT_001e88c8;
    texture[0x16] =
         -scratchUint18 & 0x80000000 |
         (scratchUint17 & 0xf) << 0x16 |
         (scratchUint21 - 1) * 0x800 & 0x3ff800 | scratchUint22 - 1 & 0x7ff | texture[0x16] & 0x40000000U;
    scratchUint15 = *(uint *)(scratchPtr13 + scratchUint20 * 0x24 + 0x1c) >> 7 & 0x1f;
    texture[0x17] = scratchUint15 | scratchUint14 & 0xfffffe00;
    if (scratchUint20 == 0x29) {
      texture[0x18] = scratchUint23 | 0x4000;
      texture[0x17] = scratchUint14 & 0xffe00000 | 6;
    }
    else {
      scratchUint17 = (*(uint *)(scratchPtr13 + scratchUint20 * 0x24 + 0x1c) & 0x70) << 5;
      texture[0x17] = scratchUint17 | scratchUint15 | scratchUint14 & 0xfffff000;
      scratchUint22 = (*(uint *)(scratchPtr13 + scratchUint20 * 0x24 + 0x1c) & 0xe) << 0xb;
      texture[0x17] = scratchUint22 | scratchUint17 | scratchUint15 | scratchUint14 & 0xffff8000;
      scratchUint18 = *(uint *)(scratchPtr13 + scratchUint20 * 0x24 + 0x20) >> 0xe & 0x38000;
      texture[0x17] = scratchUint18 | scratchUint22 | scratchUint17 | scratchUint15 | scratchUint14 & 0xfffc0000;
      texture[0x17] =
           *(uint *)(scratchPtr13 + scratchUint20 * 0x24 + 0x20) >> 8 & 0x1c0000 |
           scratchUint18 | scratchUint22 | scratchUint17 | scratchUint15 | scratchUint14 & 0xffe00000;
    }
    scratchUint17 = texture[0x17];
    scratchUint15 = (*(uint *)(scratchPtr13 + scratchUint20 * 0x24 + 0x20) >> 0x19 & 1) << 0x16;
    texture[0x17] = scratchUint15 | scratchUint17 & 0xff3fffff;
    *(byte *)((int)texture + 0x71) = (scratchPtr13[scratchUint20 * 0x24 + 0x20] ^ 1) & 1;
    if (textureTarget == 0) {
      texture[0x17] = scratchUint15 | scratchUint17 & 0xf93fffff | 0x4000000;
    }
    else if (*(char *)((int)texture + 0x6d) == '\x03') {
      texture[0x17] = scratchUint15 | scratchUint17 & 0xf93fffff | 0x2000000;
    }
    else {
      texture[0x17] = scratchUint15 | scratchUint17 & 0xf93fffff;
    }
    if (scratchUint19 == 0x1907) {
      texture[0x17] = texture[0x17] & 0xfffff1ffU | 0xa00;
    }
  }
  scratchUint15 = (uint)texture[0x32] >> 0x16;
  if (*texture == 0) {
    if ((*texImages & 0x400) == 0) {
      texture[0x10] = scratchUint15 << 0x1e;
    }
    else {
      texture[0x10] = scratchUint15 << 0x1e | scratchUint16;
    }
  }
  else {
    texture[0x10] = scratchUint15 << 0x1e | *(uint *)(scratchUint16 * 0x20 + *texture + 0x48);
  }
  scratchInt26 = texture[0xc];
  scratchChar29 = *(char *)((int)texture + 0x72);
  if (GH_U2F((unsigned int)(texture[0x24])) != *(float *)(scratchInt26 + 0x2c)) {
    texture[0x24] = (int)GH_F2U(*(float *)(scratchInt26 + 0x2c));
    scratchDouble31 = (double)*(float *)(scratchInt26 + 0x2c);
    if (DOUBLE_001aa1e8 <= scratchDouble31) {
      scratchInt28 = (int)(scratchDouble31 - DOUBLE_001aa1e8) + -0x80000000;
    }
    else {
      scratchInt28 = (int)*(float *)(scratchInt26 + 0x2c);
    }
    scratchUint15 = *(uint *)(&DAT_001aa510 + scratchInt28 * 4);
    if (((uint)texture[0x14] >> 0x15 & 7) != scratchUint15) {
      *(undefined2 *)((int)texture + 0xa2) = 0xffff;
      *(undefined2 *)(texture + 0x28) = 0xffff;
      texture[0x14] = (scratchUint15 & 7) << 0x15 | texture[0x14] & 0xff1fffffU;
    }
  }
  scratchUint4 = *(ushort *)(scratchInt26 + 0x16);
  if ((uint)*(ushort *)(texture + 0x28) == (uint)scratchUint4) {
    scratchUint15 = (uint)*(ushort *)(scratchInt26 + 0x18);
    if (*(ushort *)((int)texture + 0xa2) == scratchUint15) {
      scratchChar24 = *(char *)((int)texture + 0x71);
      if (scratchChar24 == *(char *)(texture + 0x1c)) goto LAB_0002e708;
      goto LAB_0002e690;
    }
    if (*(char *)((int)texture + 0x71) != *(char *)(texture + 0x1c)) goto LAB_0002e690;
LAB_0002e6d8:
    *(short *)((int)texture + 0xa2) = (short)scratchUint15;
    FUN_0002d210(hwState,scratchUint15);
    scratchChar24 = *(char *)((int)texture + 0x71);
  }
  else {
LAB_0002e690:
    *(ushort *)(texture + 0x28) = scratchUint4;
    FUN_0002d030(hwState,(uint)scratchUint4);
    *(byte *)((int)texture + 0x3d) = (byte)(-(uint)*(ushort *)(texture[0xc] + 0x5c) >> 0x1f);
    scratchUint15 = (uint)*(ushort *)(scratchInt26 + 0x18);
    if ((*(ushort *)((int)texture + 0xa2) != scratchUint15) ||
       (scratchChar24 = *(char *)((int)texture + 0x71), scratchChar24 != *(char *)(texture + 0x1c)))
    goto LAB_0002e6d8;
  }
  if (scratchChar29 != *(char *)((int)texture + 0x72)) {
    *(undefined2 *)((int)texture + 0x9e) = 0xffff;
    *(undefined2 *)((int)texture + 0x9a) = 0xffff;
    *(undefined2 *)(texture + 0x27) = 0xffff;
    scratchChar29 = *(char *)((int)texture + 0x72);
  }
LAB_0002e708:
  *(char *)(texture + 0x1c) = scratchChar24;
  scratchUint15 = (uint)*(ushort *)(scratchInt26 + 0x10);
  if (*(ushort *)((int)texture + 0x9a) != scratchUint15) {
    *(ushort *)((int)texture + 0x9a) = *(ushort *)(scratchInt26 + 0x10);
    if (scratchChar29 == '\0') {
      texture[0x14] =
           (scratchUint15 * 0x29 >> 0x10 & 1 | scratchUint15 * 0x97 >> 9 & 2 | scratchUint15 * 0x113 >> 7 & 4) ^ 2 |
           texture[0x14] & 0xfffffff8U;
    }
    else {
      texture[0x14] =
           (scratchUint15 * 0x29 >> 0x10 & 1 | scratchUint15 * 0x73 >> 5 & 2 | scratchUint15 * 7 >> 3 & 4) ^ 2 |
           texture[0x14] & 0xfffffff8U;
    }
  }
  scratchUint15 = (uint)*(ushort *)(scratchInt26 + 0x12);
  if (*(ushort *)(texture + 0x27) != scratchUint15) {
    *(ushort *)(texture + 0x27) = *(ushort *)(scratchInt26 + 0x12);
    if (*(char *)((int)texture + 0x6d) == '\x01') {
      texture[0x14] = texture[0x14] & 0xffffffc7;
    }
    else if (scratchChar29 == '\0') {
      texture[0x14] =
           ((scratchUint15 * 0x29 >> 0x10 & 1 | scratchUint15 * 0x97 >> 9 & 2 | scratchUint15 * 0x113 >> 7 & 4) ^ 2) << 3
           | texture[0x14] & 0xffffffc7U;
    }
    else {
      texture[0x14] =
           ((scratchUint15 * 0x29 >> 0x10 & 1 | scratchUint15 * 0x73 >> 5 & 2 | scratchUint15 * 7 >> 3 & 4) ^ 2) << 3 |
           texture[0x14] & 0xffffffc7U;
    }
  }
  scratchUint15 = (uint)*(ushort *)(scratchInt26 + 0x14);
  if (*(ushort *)((int)texture + 0x9e) != scratchUint15) {
    *(ushort *)((int)texture + 0x9e) = *(ushort *)(scratchInt26 + 0x14);
    if (*(char *)((int)texture + 0x6d) == '\x03') {
      if (scratchChar29 == '\0') {
        texture[0x14] =
             ((scratchUint15 * 0x29 >> 0x10 & 1 | scratchUint15 * 0x97 >> 9 & 2 | scratchUint15 * 0x113 >> 7 & 4) ^ 2) <<
             6 | texture[0x14] & 0xfffffe3fU;
      }
      else {
        texture[0x14] =
             ((scratchUint15 * 0x29 >> 0x10 & 1 | scratchUint15 * 0x73 >> 5 & 2 | scratchUint15 * 7 >> 3 & 4) ^ 2) << 6 |
             texture[0x14] & 0xfffffe3fU;
      }
    }
    else {
      texture[0x14] = texture[0x14] & 0xfffffe3f;
    }
  }
  scratchInt28 = texture[0xc];
  scratchShort10 = *(short *)(scratchInt28 + 2);
  if (scratchShort10 == 0x1902) {
    if (*(short *)(scratchInt26 + 0x48) == -0x7fb7) {
      *(undefined1 *)((int)texture + 0x6b) = 5;
    }
    else if (*(short *)(scratchInt26 + 0x48) == 0x1906) {
      *(undefined1 *)((int)texture + 0x6b) = 0;
    }
    else {
      *(undefined1 *)((int)texture + 0x6b) = 1;
    }
    *(undefined2 *)(texture + 0x25) = *(undefined2 *)(scratchInt26 + 0x48);
    *(undefined2 *)((int)texture + 0x96) = *(undefined2 *)(scratchInt26 + 0x42);
    scratchUint11 = *(undefined2 *)(scratchInt26 + 0x40);
    *(undefined2 *)(texture + 0x26) = scratchUint11;
    texture[0x23] = *(int *)(scratchInt26 + 0x44);
    scratchShort10 = *(short *)(scratchInt26 + 0x42);
    *(char *)((int)texture + 0x69) = (char)scratchUint11;
    scratchFloat12 = FLOAT_001aa0d4;
    scratchInt28 = texture[0xc];
    *(bool *)((int)texture + 0x6a) = scratchShort10 == -0x77b2;
    *(bool *)(texture + 0x1a) = *(float *)(scratchInt26 + 0x44) != scratchFloat12;
  }
  else if (scratchShort10 == -0x7fb7) {
    *(undefined1 *)((int)texture + 0x6b) = 5;
  }
  else {
    *(char *)((int)texture + 0x6b) = (char)scratchShort10 + -6;
  }
  *(undefined1 *)(texture + 0x29) = 0;
  scratchDouble31 = DOUBLE_001aa1e8;
  scratchFloat12 = FLOAT_001aa10c;
  *(char *)((int)texture + 0xa5) = *(char *)(scratchInt28 + 0x5f) - *(char *)(scratchInt28 + 0x5e);
  texture[0x12] = (uint)*(byte *)(scratchInt28 + 0x5f) << 0x10 | (uint)*(byte *)(scratchInt28 + 0x5e);
  scratchFloat12 = *(float *)(scratchInt28 + 0x30) + scratchFloat12;
  scratchDouble32 = (double)scratchFloat12;
  if (scratchDouble31 <= scratchDouble32) {
    scratchInt26 = (int)(scratchDouble32 - scratchDouble31) + -0x80000000;
  }
  else {
    scratchInt26 = (int)scratchFloat12;
  }
  scratchFloat12 = *(float *)(scratchInt28 + 0x34) + FLOAT_001aa10c;
  scratchDouble31 = (double)scratchFloat12;
  if (DOUBLE_001aa1e8 <= scratchDouble31) {
    scratchUint15 = (int)(scratchDouble31 - DOUBLE_001aa1e8) + 0x80000000;
  }
  else {
    scratchUint15 = (uint)(int)scratchFloat12;
  }
  texture[0x13] = scratchInt26 << 0x10 | scratchUint15;
  ((void (*)())gldPackColorForSurfaceFormat)(hwState,(double)*(float *)(scratchInt28 + 0x1c),(double)*(float *)(scratchInt28 + 0x20),
               (double)*(float *)(scratchInt28 + 0x24),(double)*(float *)(scratchInt28 + 0x28));
  scratchUint14 = (uint)*(byte *)((int)texture + 0xa5);
  scratchUint15 = (uint)(int)(*(float *)(scratchInt28 + 0x34) + FLOAT_001aa10c);
  scratchUint17 = (uint)(int)(*(float *)(scratchInt28 + 0x30) + FLOAT_001aa10c);
  if ((int)scratchUint14 < (int)scratchUint15) {
    scratchUint15 = scratchUint14;
  }
  if ((int)scratchUint14 < (int)scratchUint17) {
    scratchUint17 = scratchUint14;
  }
  scratchUint16 = scratchUint14 + 1;
  if ((uint)*(byte *)((int)texture + 0x6e) < scratchUint14 + 1) {
    scratchUint16 = (uint)*(byte *)((int)texture + 0x6e);
  }
  scratchUint15 = (scratchUint15 - scratchUint17) + 1;
  if ((int)scratchUint16 <= (int)scratchUint15) {
    scratchUint15 = scratchUint16;
  }
  scratchInt26 = 1;
  if (0 < (int)scratchUint15) {
    scratchInt26 = (int)(char)scratchUint15;
  }
  texture[0x16] = (scratchInt26 + -1) * 0x4000000 & 0x3c000000U | texture[0x16] & 0xc3ffffffU;
  *(byte *)((int)texture + 0x39) = *(byte *)((int)texture + 0x39) & 0x7f;
  return;
}

/* gld_applyAnisotropyOverride @ 0x2ebc0 (596 bytes) */
int gld_applyAnisotropyOverride(ctx, unitIndex)
  int ctx;
  int unitIndex;
{
  bool flag72Unset;
  char flag72Before;
  short filterKind;
  uint filterWord;
  int texture;
  uint wrapWord;
  
  if (*(int *)(ctx + 0x2a90) != 0) {
    texture = *(int *)(unitIndex * 4 + ctx + 0x18c);
    filterWord = (uint)*(ushort *)(texture + 0xa0);
    if ((((*(short *)(*(int *)(texture + 0x30) + 0x18) != 0x2600) &&
         (filterKind = *(short *)(*(int *)(texture + 0x30) + 0x16), filterKind != 0x2600)) && (filterKind != 0x2702))
       && (filterKind != 0x2700)) {
      *(uint *)(texture + 0x50) =
           (*(uint *)(&DAT_001aa510 + *(int *)(ctx + 0x2a90) * 4) & 7) << 0x15 |
           *(uint *)(texture + 0x50) & 0xff1fffff;
      if (3 < *(uint *)(ctx + 0x2a8c)) {
        if (filterWord == 0x2703) {
          filterWord = 0x2701;
        }
        else if (filterWord == 0x2702) {
          filterWord = 0x2700;
        }
      }
      flag72Before = *(char *)(texture + 0x72);
      FUN_0002d030(texture + 0x3c,filterWord);
      FUN_0002d210(texture + 0x3c,(uint)*(ushort *)(texture + 0xa2));
      if (flag72Before != *(char *)(texture + 0x72)) {
        flag72Unset = *(char *)(texture + 0x72) == '\0';
        filterWord = (uint)*(ushort *)(texture + 0x9a);
        if (flag72Unset) {
          filterWord = (filterWord * 0x29 >> 0x10 & 1 | filterWord * 0x97 >> 9 & 2 | filterWord * 0x113 >> 7 & 4) ^ 2 |
                  *(uint *)(texture + 0x50) & 0xfffffff8;
          *(uint *)(texture + 0x50) = filterWord;
        }
        else {
          filterWord = (filterWord * 0x29 >> 0x10 & 1 | filterWord * 0x73 >> 5 & 2 | filterWord * 7 >> 3 & 4) ^ 2 |
                  *(uint *)(texture + 0x50) & 0xfffffff8;
          *(uint *)(texture + 0x50) = filterWord;
        }
        wrapWord = (uint)*(ushort *)(texture + 0x9c);
        if (*(char *)(texture + 0x6d) == '\x01') {
          filterWord = filterWord & 0xffffffc7;
          *(uint *)(texture + 0x50) = filterWord;
        }
        else if (flag72Unset) {
          filterWord = ((wrapWord * 0x29 >> 0x10 & 1 | wrapWord * 0x97 >> 9 & 2 | wrapWord * 0x113 >> 7 & 4) ^ 2)
                  << 3 | filterWord & 0xffffffc7;
          *(uint *)(texture + 0x50) = filterWord;
        }
        else {
          filterWord = ((wrapWord * 0x29 >> 0x10 & 1 | wrapWord * 0x73 >> 5 & 2 | wrapWord * 7 >> 3 & 4) ^ 2) << 3
                  | filterWord & 0xffffffc7;
          *(uint *)(texture + 0x50) = filterWord;
        }
        wrapWord = (uint)*(ushort *)(texture + 0x9e);
        if (*(char *)(texture + 0x6d) == '\x03') {
          if (flag72Unset) {
            *(uint *)(texture + 0x50) =
                 ((wrapWord * 0x29 >> 0x10 & 1 | wrapWord * 0x97 >> 9 & 2 | wrapWord * 0x113 >> 7 & 4) ^ 2)
                 << 6 | filterWord & 0xfffffe3f;
          }
          else {
            *(uint *)(texture + 0x50) =
                 ((wrapWord * 0x29 >> 0x10 & 1 | wrapWord * 0x73 >> 5 & 2 | wrapWord * 7 >> 3 & 4) ^ 2) << 6
                 | filterWord & 0xfffffe3f;
          }
        }
        else {
          *(uint *)(texture + 0x50) = filterWord & 0xfffffe3f;
        }
      }
    }
  }
  return;
}

/* gld_updateTextureSamplerState @ 0x2ee30 (1476 bytes) */
int gld_updateTextureSamplerState(ctxSaved, texture)
  undefined4 ctxSaved;
  int texture;
{
  float scratchFloat1;
  float fVar2;
  float fVar3;
  ushort minFilterField;
  short baseFormatCode;
  undefined2 depthCompareWord;
  uint scratchUint7;
  int scratchInt8;
  char flag71;
  char flag72;
  int texImages;
  int hwState;
  double doubleConst;
  
  hwState = texture + 0x3c;
  texImages = *(int *)(texture + 0x30);
  scratchFloat1 = *(float *)(texImages + 0x30) + FLOAT_001aa10c;
  doubleConst = (double)scratchFloat1;
  if (DOUBLE_001aa1e8 <= doubleConst) {
    scratchInt8 = (int)(doubleConst - DOUBLE_001aa1e8) + -0x80000000;
  }
  else {
    scratchInt8 = (int)scratchFloat1;
  }
  scratchFloat1 = *(float *)(texImages + 0x34) + FLOAT_001aa10c;
  doubleConst = (double)scratchFloat1;
  if (DOUBLE_001aa1e8 <= doubleConst) {
    scratchUint7 = (int)(doubleConst - DOUBLE_001aa1e8) + 0x80000000;
  }
  else {
    scratchUint7 = (uint)(int)scratchFloat1;
  }
  if ((((uint)*(byte *)(texImages + 0x5f) << 0x10 | (uint)*(byte *)(texImages + 0x5e)) !=
       *(uint *)(texture + 0x48)) || ((scratchInt8 << 0x10 | scratchUint7) != *(uint *)(texture + 0x4c))) {
    ((int (*)())FUN_0002ddf0)(ctxSaved,texture);
    return;
  }
  flag72 = *(char *)(texture + 0x72);
  if (*(float *)(texture + 0x90) != *(float *)(texImages + 0x2c)) {
    *(float *)(texture + 0x90) = *(float *)(texImages + 0x2c);
    doubleConst = (double)*(float *)(texImages + 0x2c);
    if (DOUBLE_001aa1e8 <= doubleConst) {
      scratchInt8 = (int)(doubleConst - DOUBLE_001aa1e8) + -0x80000000;
    }
    else {
      scratchInt8 = (int)*(float *)(texImages + 0x2c);
    }
    scratchUint7 = *(uint *)(&DAT_001aa510 + scratchInt8 * 4);
    if ((*(uint *)(texture + 0x50) >> 0x15 & 7) != scratchUint7) {
      *(undefined2 *)(texture + 0xa2) = 0xffff;
      *(undefined2 *)(texture + 0xa0) = 0xffff;
      *(uint *)(texture + 0x50) = (scratchUint7 & 7) << 0x15 | *(uint *)(texture + 0x50) & 0xff1fffff;
    }
  }
  minFilterField = *(ushort *)(texImages + 0x16);
  if ((uint)*(ushort *)(texture + 0xa0) == (uint)minFilterField) {
    scratchUint7 = (uint)*(ushort *)(texImages + 0x18);
    if (*(ushort *)(texture + 0xa2) != scratchUint7) {
      if (*(char *)(texture + 0x70) != *(char *)(texture + 0x71)) goto LAB_0002f040;
      goto LAB_0002f088;
    }
    flag71 = *(char *)(texture + 0x71);
    if (flag71 != *(char *)(texture + 0x70)) goto LAB_0002f040;
  }
  else {
LAB_0002f040:
    *(ushort *)(texture + 0xa0) = minFilterField;
    FUN_0002d030(hwState,(uint)minFilterField);
    *(byte *)(texture + 0x3d) = (byte)(-(uint)*(ushort *)(*(int *)(texture + 0x30) + 0x5c) >> 0x1f);
    scratchUint7 = (uint)*(ushort *)(texImages + 0x18);
    if ((*(ushort *)(texture + 0xa2) != scratchUint7) ||
       (flag71 = *(char *)(texture + 0x71), flag71 != *(char *)(texture + 0x70))) {
LAB_0002f088:
      *(short *)(texture + 0xa2) = (short)scratchUint7;
      FUN_0002d210(hwState,scratchUint7);
      flag71 = *(char *)(texture + 0x71);
    }
    if (flag72 != *(char *)(texture + 0x72)) {
      *(undefined2 *)(texture + 0x9e) = 0xffff;
      *(undefined2 *)(texture + 0x9a) = 0xffff;
      *(undefined2 *)(texture + 0x9c) = 0xffff;
      flag72 = *(char *)(texture + 0x72);
    }
  }
  *(char *)(texture + 0x70) = flag71;
  scratchUint7 = (uint)*(ushort *)(texImages + 0x10);
  if (*(ushort *)(texture + 0x9a) != scratchUint7) {
    *(ushort *)(texture + 0x9a) = *(ushort *)(texImages + 0x10);
    if (flag72 == '\0') {
      *(uint *)(texture + 0x50) =
           (scratchUint7 * 0x29 >> 0x10 & 1 | scratchUint7 * 0x97 >> 9 & 2 | scratchUint7 * 0x113 >> 7 & 4) ^ 2 |
           *(uint *)(texture + 0x50) & 0xfffffff8;
    }
    else {
      *(uint *)(texture + 0x50) =
           (scratchUint7 * 0x29 >> 0x10 & 1 | scratchUint7 * 0x73 >> 5 & 2 | scratchUint7 * 7 >> 3 & 4) ^ 2 |
           *(uint *)(texture + 0x50) & 0xfffffff8;
    }
  }
  scratchUint7 = (uint)*(ushort *)(texImages + 0x12);
  if (*(ushort *)(texture + 0x9c) != scratchUint7) {
    *(ushort *)(texture + 0x9c) = *(ushort *)(texImages + 0x12);
    if (*(char *)(texture + 0x6d) == '\x01') {
      *(uint *)(texture + 0x50) = *(uint *)(texture + 0x50) & 0xffffffc7;
    }
    else if (flag72 == '\0') {
      *(uint *)(texture + 0x50) =
           ((scratchUint7 * 0x29 >> 0x10 & 1 | scratchUint7 * 0x97 >> 9 & 2 | scratchUint7 * 0x113 >> 7 & 4) ^ 2) << 3 |
           *(uint *)(texture + 0x50) & 0xffffffc7;
    }
    else {
      *(uint *)(texture + 0x50) =
           ((scratchUint7 * 0x29 >> 0x10 & 1 | scratchUint7 * 0x73 >> 5 & 2 | scratchUint7 * 7 >> 3 & 4) ^ 2) << 3 |
           *(uint *)(texture + 0x50) & 0xffffffc7;
    }
  }
  scratchUint7 = (uint)*(ushort *)(texImages + 0x14);
  if (*(ushort *)(texture + 0x9e) != scratchUint7) {
    *(ushort *)(texture + 0x9e) = *(ushort *)(texImages + 0x14);
    if (*(char *)(texture + 0x6d) == '\x03') {
      if (flag72 == '\0') {
        *(uint *)(texture + 0x50) =
             ((scratchUint7 * 0x29 >> 0x10 & 1 | scratchUint7 * 0x97 >> 9 & 2 | scratchUint7 * 0x113 >> 7 & 4) ^ 2) << 6
             | *(uint *)(texture + 0x50) & 0xfffffe3f;
      }
      else {
        *(uint *)(texture + 0x50) =
             ((scratchUint7 * 0x29 >> 0x10 & 1 | scratchUint7 * 0x73 >> 5 & 2 | scratchUint7 * 7 >> 3 & 4) ^ 2) << 6 |
             *(uint *)(texture + 0x50) & 0xfffffe3f;
      }
    }
    else {
      *(uint *)(texture + 0x50) = *(uint *)(texture + 0x50) & 0xfffffe3f;
    }
  }
  baseFormatCode = *(short *)(*(int *)(texture + 0x30) + 2);
  if (baseFormatCode == 0x1902) {
    if (*(short *)(texImages + 0x48) == -0x7fb7) {
      *(undefined1 *)(texture + 0x6b) = 5;
    }
    else if (*(short *)(texImages + 0x48) == 0x1906) {
      *(undefined1 *)(texture + 0x6b) = 0;
    }
    else {
      *(undefined1 *)(texture + 0x6b) = 1;
    }
    *(undefined2 *)(texture + 0x94) = *(undefined2 *)(texImages + 0x48);
    *(undefined2 *)(texture + 0x96) = *(undefined2 *)(texImages + 0x42);
    depthCompareWord = *(undefined2 *)(texImages + 0x40);
    *(undefined2 *)(texture + 0x98) = depthCompareWord;
    *(undefined4 *)(texture + 0x8c) = *(undefined4 *)(texImages + 0x44);
    baseFormatCode = *(short *)(texImages + 0x42);
    *(char *)(texture + 0x69) = (char)depthCompareWord;
    scratchFloat1 = FLOAT_001aa0d4;
    *(bool *)(texture + 0x6a) = baseFormatCode == -0x77b2;
    *(bool *)(texture + 0x68) = *(float *)(texImages + 0x44) != scratchFloat1;
  }
  else if (baseFormatCode == -0x7fb7) {
    *(undefined1 *)(texture + 0x6b) = 5;
  }
  else {
    *(char *)(texture + 0x6b) = (char)baseFormatCode + -6;
  }
  if (*(float *)(texture + 0xa8) == *(float *)(texImages + 0x1c)) {
    scratchFloat1 = *(float *)(texImages + 0x20);
    if (*(float *)(texture + 0xac) == scratchFloat1) {
      fVar2 = *(float *)(texImages + 0x24);
      if (*(float *)(texture + 0xb0) == fVar2) {
        fVar3 = *(float *)(texImages + 0x28);
        if (*(float *)(texture + 0xb4) == fVar3) goto LAB_0002f3e8;
      }
      else {
        fVar3 = *(float *)(texImages + 0x28);
      }
    }
    else {
      fVar2 = *(float *)(texImages + 0x24);
      fVar3 = *(float *)(texImages + 0x28);
    }
  }
  else {
    scratchFloat1 = *(float *)(texImages + 0x20);
    fVar2 = *(float *)(texImages + 0x24);
    fVar3 = *(float *)(texImages + 0x28);
  }
  *(float *)(texture + 0xa8) = *(float *)(texImages + 0x1c);
  *(float *)(texture + 0xac) = scratchFloat1;
  *(float *)(texture + 0xb0) = fVar2;
  *(float *)(texture + 0xb4) = fVar3;
  ((void (*)())gldPackColorForSurfaceFormat)(hwState,(double)*(float *)(texImages + 0x1c),(double)*(float *)(texImages + 0x20),
               (double)*(float *)(texImages + 0x24),(double)*(float *)(texImages + 0x28));
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

/* gld_selectTextureHardwareFormat @ 0x2fac0 (2252 bytes) */
int gld_selectTextureHardwareFormat(ctx, texture)
  int ctx;
  int texture;
{
  ushort imageFlags;
  ushort externalFormat;
  ushort internalFormat;
  ushort dataType;
  uint surfaceFormatNibble;
  char typeFormatAlt;
  char hwFormatIndex;
  int ioStatus;
  undefined1 window_mode_to_ati_formatResult;
  char typeFormatB;
  char typeFormatA;
  char internalFormatCode;
  ushort *texImages;
  undefined4 scalarIn0;
  undefined4 outputCount;
  uint surfaceInfoOut [9];
  
  texImages = *(ushort **)(texture + 0x30);
  imageFlags = *texImages;
  if ((imageFlags & 0x200) != 0) {
    return;
  }
  if ((imageFlags & 0x400) != 0) {
    scalarIn0 = *(undefined4 *)(texImages + 4);
    *(undefined1 *)(texture + 0x38) = 0;
    outputCount = 3;
    ioStatus = _io_connect_method_scalarI_scalarO
                      (*(undefined4 *)(ctx + 4),6,&scalarIn0,1,surfaceInfoOut,&outputCount);
    if (ioStatus != 0) {
      return;
    }
    imageFlags = texImages[6];
    if (imageFlags == 0x409) {
      if ((surfaceInfoOut[0] & 0x300) < 0x100) {
        return;
      }
    }
    else if (imageFlags == 0x40a) {
      if ((surfaceInfoOut[0] & 0x300) < 0x200) {
        return;
      }
    }
    else if ((ushort)(imageFlags - 0x40b) < 2) {
      return;
    }
    window_mode_to_ati_formatResult = ((int (*)())window_mode_to_ati_format)(surfaceInfoOut[0]);
    *(undefined1 *)(texture + 0x38) = window_mode_to_ati_formatResult;
    return;
  }
  externalFormat = texImages[0x2c];
  internalFormat = texImages[0x2a];
  dataType = texImages[0x2d];
  surfaceFormatNibble = *(uint *)(ctx + 0x154) & 0xf;
  if (externalFormat != 0x1900) {
    if (externalFormat != 0x85b9) {
      if (dataType == 0x8362) {
LAB_0002fcd4:
        typeFormatAlt = '(';
        typeFormatA = '(';
        typeFormatB = '(';
      }
      else if (dataType < 0x8363) {
        if (dataType == 0x8034) {
LAB_0002fcf4:
          typeFormatAlt = '\0';
          typeFormatA = '\a';
          typeFormatB = '\a';
        }
        else if (dataType < 0x8035) {
          if (dataType == 0x8032) goto LAB_0002fcd4;
          if (dataType == 0x8033) goto LAB_0002fcc4;
LAB_0002fc40:
          typeFormatAlt = '\0';
          typeFormatA = '\0';
          typeFormatB = '\0';
        }
        else if (dataType == 0x8035) {
          if (externalFormat == 0x80e1) {
            typeFormatAlt = '\0';
            typeFormatA = '\0';
            typeFormatB = '\b';
          }
          else {
            typeFormatAlt = '\0';
            typeFormatA = '\0';
            typeFormatB = '\t';
          }
        }
        else {
          if (dataType != 0x8036) goto LAB_0002fc40;
LAB_0002fd64:
          if (externalFormat == 0x80e1) {
            typeFormatAlt = '\0';
            typeFormatA = '\0';
            typeFormatB = '$';
          }
          else {
            typeFormatAlt = '\0';
            typeFormatA = '\0';
            typeFormatB = '#';
          }
        }
      }
      else if (dataType == 0x8365) {
LAB_0002fcc4:
        typeFormatAlt = '\0';
        typeFormatA = '\x06';
        typeFormatB = '\x06';
      }
      else if (dataType < 0x8365) {
        typeFormatAlt = '\0';
        typeFormatA = '\x05';
        typeFormatB = '\x05';
      }
      else {
        if (dataType != 0x8367) {
          if (0x8366 < dataType) {
            if (dataType == 0x8368) goto LAB_0002fd64;
            goto LAB_0002fc40;
          }
          goto LAB_0002fcf4;
        }
        if (externalFormat == 0x80e1) {
          typeFormatAlt = '\0';
          typeFormatA = '\0';
          typeFormatB = '\v';
        }
        else {
          typeFormatAlt = '\0';
          typeFormatA = '\0';
          typeFormatB = '\n';
        }
      }
      if (0x8056 < internalFormat) {
        if (internalFormat == 0x84ec) {
          typeFormatA = '\0';
          hwFormatIndex = '\f';
          internalFormatCode = '\x03';
        }
        else if (internalFormat < 0x84ed) {
          if (internalFormat < 0x81a8) {
            if (internalFormat < 0x81a6) {
              if (internalFormat == 0x8059) {
                if (externalFormat == 0x80e1) {
                  typeFormatA = '\0';
                  hwFormatIndex = '\0';
                  internalFormatCode = '$';
                }
                else {
                  typeFormatA = '\0';
                  hwFormatIndex = '\0';
                  internalFormatCode = '#';
                }
              }
              else if (internalFormat < 0x805a) {
                if (internalFormat != 0x8057) {
                  if (internalFormat == 0x8058) goto LAB_0002fec0;
                  goto LAB_0002fde8;
                }
                hwFormatIndex = '\0';
                internalFormatCode = '\a';
              }
              else {
                if (internalFormat < 0x805c) goto LAB_00030378;
                if (internalFormat != 0x81a5) goto LAB_0002fde8;
LAB_0003034c:
                hwFormatIndex = '\0';
                internalFormatCode = '\x10';
                typeFormatA = '\0';
              }
            }
            else {
LAB_0003009c:
              typeFormatA = '\0';
              hwFormatIndex = '\0';
              internalFormatCode = ')';
            }
          }
          else if (internalFormat == 0x83f3) {
            hwFormatIndex = '\x0e';
            internalFormatCode = '\x06';
          }
          else if (internalFormat < 0x83f4) {
            if (internalFormat == 0x83f1) {
              hwFormatIndex = '\f';
              internalFormatCode = '\x06';
            }
            else {
              if (internalFormat < 0x83f2) {
                if (internalFormat == 0x83f0) goto LAB_000301a0;
                goto LAB_0002fde8;
              }
LAB_0003017c:
              hwFormatIndex = '\r';
              internalFormatCode = '\x06';
            }
          }
          else if (internalFormat == 0x84ea) {
            typeFormatA = '\0';
            hwFormatIndex = '\f';
            internalFormatCode = '\x01';
          }
          else if (internalFormat < 0x84eb) {
            if (internalFormat != 0x84e9) goto LAB_0002fde8;
            if (externalFormat == 0x1908) {
LAB_00030298:
              if ((dataType == 0x8034) || (dataType == 0x8366)) goto LAB_00030260;
            }
            else if (externalFormat < 0x1909) {
              if (externalFormat != 0x1906) {
LAB_00030260:
                typeFormatA = '\0';
                hwFormatIndex = '\f';
                internalFormatCode = '\x02';
                goto LAB_00030270;
              }
            }
            else if (externalFormat != 0x190a) {
              if (externalFormat == 0x80e1) goto LAB_00030298;
              goto LAB_00030260;
            }
LAB_000302b8:
            hwFormatIndex = '\0';
            internalFormatCode = '\x02';
            typeFormatA = '\0';
          }
          else {
            hwFormatIndex = '\r';
            internalFormatCode = '\x04';
          }
        }
        else if (internalFormat == 0x8819) {
          typeFormatA = '\0';
          hwFormatIndex = '\0';
          internalFormatCode = '\x16';
        }
        else if (internalFormat < 0x881a) {
          if (internalFormat < 0x8816) {
            if (internalFormat < 0x8814) {
              if (internalFormat != 0x84ed) {
                if (internalFormat == 0x84ee) goto LAB_0003017c;
                goto LAB_0002fde8;
              }
LAB_000301a0:
              hwFormatIndex = '\f';
              internalFormatCode = '\x05';
            }
            else if (externalFormat == 0x80e1) {
              typeFormatA = '\0';
              hwFormatIndex = '\0';
              internalFormatCode = '\x11';
            }
            else {
              typeFormatA = '\0';
              hwFormatIndex = '\0';
              internalFormatCode = '\x12';
            }
          }
          else if (internalFormat == 0x8817) {
            typeFormatA = '\0';
            hwFormatIndex = '\0';
            internalFormatCode = '\x15';
          }
          else if (internalFormat < 0x8818) {
            typeFormatA = '\0';
            hwFormatIndex = '\0';
            internalFormatCode = '\x14';
          }
          else {
            typeFormatA = '\0';
            hwFormatIndex = '\0';
            internalFormatCode = '\x13';
          }
        }
        else if (internalFormat == 0x881d) {
          typeFormatA = '\0';
          hwFormatIndex = '\0';
          internalFormatCode = '!';
        }
        else if (internalFormat < 0x881e) {
          if (internalFormat < 0x881c) {
            typeFormatA = '\0';
            hwFormatIndex = '\0';
            internalFormatCode = '\x1e';
          }
          else {
            typeFormatA = '\0';
            hwFormatIndex = '\0';
            internalFormatCode = ' ';
          }
        }
        else if (internalFormat == 0x881f) {
          typeFormatA = '\0';
          hwFormatIndex = '\0';
          internalFormatCode = '\"';
        }
        else if (internalFormat < 0x881f) {
          typeFormatA = '\0';
          hwFormatIndex = '\0';
          internalFormatCode = '\x1f';
        }
        else {
          if (internalFormat != 0x8837) {
            if (internalFormat == 0x88f0) goto LAB_0003009c;
            goto LAB_0002fde8;
          }
          typeFormatA = '\0';
          hwFormatIndex = '\x0f';
          internalFormatCode = '\x04';
        }
        goto LAB_00030270;
      }
      if (internalFormat < 0x8055) {
        if (internalFormat < 0x8041) {
          if (internalFormat < 0x803f) {
            if (internalFormat == 0x1908) {
LAB_000302e8:
              if (externalFormat == 0x1908) {
LAB_0003031c:
                if (surfaceFormatNibble == 3) goto LAB_00030360;
              }
              else {
                if (externalFormat < 0x1909) {
                  if (externalFormat == 0x1906) goto LAB_0003031c;
                }
                else if ((externalFormat == 0x190a) || (externalFormat == 0x80e1)) goto LAB_0003031c;
LAB_00030340:
                if (surfaceFormatNibble == 3) goto LAB_0003036c;
              }
LAB_0002fec0:
              hwFormatIndex = '\0';
              internalFormatCode = '\t';
              typeFormatA = typeFormatB;
            }
            else {
              if (internalFormat < 0x1909) {
                if (internalFormat == 4) goto LAB_000302e8;
                if (4 < internalFormat) {
                  if (internalFormat == 0x1906) goto LAB_000302b8;
                  if (0x1906 < internalFormat) goto LAB_00030328;
                  if (internalFormat == 0x1902) goto LAB_0003034c;
LAB_0002fde8:
                  hwFormatIndex = '\0';
                  internalFormatCode = '\0';
                  typeFormatA = '\0';
                  goto LAB_00030270;
                }
                if (internalFormat == 2) goto LAB_000301ec;
                if (internalFormat < 3) {
                  if (internalFormat == 1) goto LAB_00030218;
                  goto LAB_0002fde8;
                }
LAB_00030328:
                if (externalFormat == 0x1906) {
                  hwFormatIndex = '\0';
                  internalFormatCode = '(';
                  typeFormatA = '\0';
                  goto LAB_00030270;
                }
                goto LAB_00030340;
              }
              if (internalFormat < 0x803d) {
                if (0x803a < internalFormat) goto LAB_000302b8;
                if (internalFormat == 0x190a) {
LAB_000301ec:
                  hwFormatIndex = '\0';
                  internalFormatCode = '\x04';
                  typeFormatA = '\0';
                }
                else {
                  if (internalFormat < 0x190a) goto LAB_00030218;
                  if (internalFormat != 0x2a10) goto LAB_0002fde8;
                  hwFormatIndex = '\0';
                  internalFormatCode = '(';
                  typeFormatA = typeFormatAlt;
                }
              }
              else {
                hwFormatIndex = '\0';
                internalFormatCode = '\x1a';
                typeFormatA = '\0';
              }
            }
          }
          else {
LAB_00030218:
            hwFormatIndex = '\0';
            internalFormatCode = '\x01';
            typeFormatA = '\0';
          }
        }
        else if (internalFormat < 0x804c) {
          if (internalFormat < 0x8049) {
            if (internalFormat < 0x8047) {
              if (0x8042 < internalFormat) goto LAB_000301ec;
              hwFormatIndex = '\0';
              internalFormatCode = '\x19';
              typeFormatA = '\0';
            }
            else {
              hwFormatIndex = '\0';
              internalFormatCode = '\x1c';
              typeFormatA = '\0';
            }
          }
          else {
            hwFormatIndex = '\0';
            internalFormatCode = '\x03';
            typeFormatA = '\0';
          }
        }
        else if (internalFormat < 0x8051) {
          if (internalFormat < 0x804f) {
            if (0x804d < internalFormat) goto LAB_0002fde8;
            hwFormatIndex = '\0';
            internalFormatCode = '\x1b';
            typeFormatA = '\0';
          }
          else {
LAB_0003036c:
            hwFormatIndex = '\0';
            internalFormatCode = '\x05';
          }
        }
        else if (internalFormat == 0x8052) {
          hwFormatIndex = '\0';
          internalFormatCode = '#';
          typeFormatA = typeFormatB;
        }
        else {
          if (internalFormat < 0x8053) goto LAB_0002fec0;
LAB_00030378:
          hwFormatIndex = '\0';
          internalFormatCode = '\x18';
          typeFormatA = '\0';
        }
      }
      else {
LAB_00030360:
        hwFormatIndex = '\0';
        internalFormatCode = '\x06';
      }
LAB_00030270:
      if ((((imageFlags & 0xf) == 2) || (hwFormatIndex == '\0')) && (hwFormatIndex = typeFormatA, typeFormatA == '\0')) {
        hwFormatIndex = internalFormatCode;
      }
      goto LAB_000303b4;
    }
    hwFormatIndex = '\'';
    if ((dataType == 0x85ba) || (hwFormatIndex = '&', dataType == 0x85bb)) goto LAB_000303b4;
  }
  hwFormatIndex = '\0';
LAB_000303b4:
  *(char *)(texture + 0x38) = hwFormatIndex;
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

/* gld_buildTextureStatePacket @ 0x30420 (392 bytes) */
int gld_buildTextureStatePacket(packet, formatEntry, pitchBytes, blockPitchBytes, tileFlags, widthTexels, heightTexels)
  int packet;
  int formatEntry;
  uint pitchBytes;
  uint blockPitchBytes;
  uint tileFlags;
  uint widthTexels;
  uint heightTexels;
{
  uint tileModeBits;
  uint pitchBlocks;
  float half;
  double i2dBias;
  uint oldWord0c;
  uint scratchUint6;
  
  _memcpy(packet,PTR_DAT_001e8998,0x74);
  i2dBias = DOUBLE_001aa250;
  half = FLOAT_001aa10c;
  oldWord0c = *(uint *)(packet + 0xc);
  pitchBlocks = blockPitchBytes >> (*(uint *)(formatEntry + 0x14) & 7) & 0x3ffe;
  scratchUint6 = (tileFlags & 1) << 0x10;
  tileModeBits = (tileFlags & 6) << 0x10;
  *(uint *)(packet + 0xc) = tileModeBits | scratchUint6 | pitchBlocks | oldWord0c & 0xffe0c001;
  *(uint *)(packet + 0xc) =
       (*(uint *)(formatEntry + 0x18) & 0x3c00) << 0xb | tileModeBits | scratchUint6 | pitchBlocks | oldWord0c & 0xfe00c001;
  scratchUint6 = *(uint *)(formatEntry + 0x18);
  *(uint *)(packet + 0x1c) =
       (heightTexels - 1 & 0x7ff) << 0xb | widthTexels - 1 & 0x7ff | *(uint *)(packet + 0x1c) & 0x80000000 |
       0x80000000;
  *(uint *)(packet + 0x14) = scratchUint6 >> 0x1e;
  scratchUint6 = *(uint *)(formatEntry + 0x14);
  *(uint *)(packet + 0x30) =
       (heightTexels - 1 & 0x1fff) << 0xd | widthTexels - 1 & 0x1fff | *(uint *)(packet + 0x30) & 0xfc000000
  ;
  *(uint *)(packet + 0x4c) = widthTexels * 0x60000 | heightTexels * 6;
  *(float *)(packet + 0x5c) = (float)((double)CONCAT44(0x43300000,heightTexels) - i2dBias) * half;
  *(float *)(packet + 0x58) = (float)((double)CONCAT44(0x43300000,widthTexels) - i2dBias) * half;
  *(uint *)(packet + 0x24) =
       (uint)(0x800 < heightTexels) * 0x10000 |
       (uint)(0x800 < widthTexels) * 0x8000 |
       (pitchBytes >> (scratchUint6 & 7)) - 1 & 0x3fff | *(uint *)(packet + 0x24) & 0xfff00000;
  return packet + 0x74;
}

/* gld_compressAlphaBlock @ 0x305b0 (492 bytes) */
int gld_compressAlphaBlock(dstBlock, srcPixels, pixelStride, rowStride)
  undefined1 *dstBlock;
  byte *srcPixels;
  int pixelStride;
  int rowStride;
{
  bool scratchFlag1;
  byte pixelValue;
  uint scratchUint3;
  uint scratchUint4;
  int halfInterval;
  int scratchInt6;
  int indexCode;
  byte *pixelCursor;
  uint scratchUint9;
  byte *scratchPtr10;
  int byteIndex;
  int intervalSize;
  int blockRow;
  int scratchInt14;
  int blockColumn;
  int indexRemapTable [4];
  undefined4 indexRemapTable4;
  undefined4 indexRemapTable5;
  undefined4 indexRemapTable6;
  undefined4 indexRemapTable7;
  
  scratchUint4 = 0;
  scratchUint9 = 0xff;
  scratchInt6 = 0;
  scratchPtr10 = srcPixels;
  do {
    scratchInt14 = 4;
    pixelCursor = scratchPtr10;
    do {
      scratchUint3 = (uint)*pixelCursor;
      pixelCursor = pixelCursor + pixelStride;
      if (scratchUint3 < scratchUint9) {
        scratchUint9 = scratchUint3;
      }
      if (scratchUint4 < scratchUint3) {
        scratchUint4 = scratchUint3;
      }
      scratchInt14 = scratchInt14 + -1;
    } while (scratchInt14 != 0);
    scratchFlag1 = scratchInt6 != 3;
    scratchPtr10 = scratchPtr10 + rowStride;
    scratchInt6 = scratchInt6 + 1;
  } while (scratchFlag1);
  scratchInt6 = scratchUint4 * 0x100;
  scratchInt14 = scratchUint9 * 0x100;
  intervalSize = (int)(scratchInt6 + scratchUint9 * -0x100) / 7;
  halfInterval = intervalSize >> 1;
  if (scratchInt6 == scratchInt14) {
    if (scratchUint9 == 0) {
      scratchInt6 = 0x100;
      halfInterval = 0x7fff;
      intervalSize = 0xffff;
    }
    else {
      scratchInt14 = scratchInt14 + -0x100;
      halfInterval = 0x7fff;
      intervalSize = 0xffff;
    }
  }
  blockRow = 0;
  scratchUint4 = 0x10;
  indexRemapTable[0] = DAT_001aa554;
  indexRemapTable[1] = DAT_001aa558;
  indexRemapTable7 = DAT_001aa570;
  indexRemapTable[2] = DAT_001aa55c;
  indexRemapTable[3] = DAT_001aa560;
  indexRemapTable4 = DAT_001aa564;
  indexRemapTable5 = DAT_001aa568;
  indexRemapTable6 = DAT_001aa56c;
  do {
    blockColumn = 4;
    scratchPtr10 = srcPixels;
    scratchUint9 = scratchUint4;
    do {
      pixelValue = *scratchPtr10;
      byteIndex = (int)scratchUint9 >> 3;
      scratchUint3 = scratchUint9 & 7;
      scratchPtr10 = scratchPtr10 + pixelStride;
      indexCode = indexRemapTable[(int)(((uint)pixelValue * 0x100 + halfInterval) - scratchInt14) / intervalSize];
      dstBlock[byteIndex] = (byte)(indexCode << scratchUint3) | dstBlock[byteIndex] & ~(byte)(7 << scratchUint3);
      if (5 < scratchUint3) {
        dstBlock[byteIndex + 1] =
             (byte)(indexCode >> (8 - scratchUint3 & 0x3f)) |
             dstBlock[byteIndex + 1] & ~(byte)(7 >> (8 - scratchUint3 & 0x3f));
      }
      scratchUint9 = scratchUint9 + 3;
      blockColumn = blockColumn + -1;
    } while (blockColumn != 0);
    scratchFlag1 = blockRow != 3;
    srcPixels = srcPixels + rowStride;
    scratchUint4 = scratchUint4 + 0xc;
    blockRow = blockRow + 1;
  } while (scratchFlag1);
  *dstBlock = (char)((uint)scratchInt6 >> 8);
  dstBlock[1] = (char)((uint)scratchInt14 >> 8);
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

/* gld_emitBoundUnitObjects @ 0x308c0 (192 bytes) */
int gld_emitBoundUnitObjects(ctx, streamCursor)
  int ctx;
  undefined4 streamCursor;
{
  bool lastUnit;
  int *objectTableCursor;
  int unitObject;
  int tableByteOffset;
  int loopIndex;
  int unitSlotPtr;
  int tableEntriesLeft;
  
  loopIndex = 0;
  tableByteOffset = 0;
  unitSlotPtr = ctx;
  do {
    unitObject = *(int *)(unitSlotPtr + 0x18c);
    if (unitObject != 0) {
      tableEntriesLeft = 5;
      objectTableCursor = (int *)(tableByteOffset + *(int *)(ctx + 0x18));
      do {
        if (unitObject == *objectTableCursor) {
          if (*(int *)(unitObject + 0x34) != 0) goto LAB_0003093c;
          break;
        }
        objectTableCursor = objectTableCursor + 1;
        tableEntriesLeft = tableEntriesLeft + -1;
      } while (tableEntriesLeft != 0);
      unitObject = 0;
    }
LAB_0003093c:
    if ((loopIndex == 0) || (unitObject != 0)) {
      streamCursor = gld_emitUnitObjectPacket(ctx,unitObject,loopIndex,streamCursor);
    }
    lastUnit = loopIndex == 0xf;
    tableByteOffset = tableByteOffset + 0x14;
    unitSlotPtr = unitSlotPtr + 4;
    loopIndex = loopIndex + 1;
    if (lastUnit) {
      return streamCursor;
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

/* gld_bindUnitObject @ 0x309c0 (136 bytes) */
int gld_bindUnitObject(stream, unitObject, unitIndex)
  int stream;
  undefined4 unitObject;
  int unitIndex;
{
  undefined4 streamCursor;
  int glContext;
  
  glContext = *(int *)(stream + 4);
  *(undefined4 *)(unitIndex * 4 + glContext + 0x18c) = unitObject;
  streamCursor = (**(code **)(glContext + 0x2998))(stream,0xe,unitIndex);
  *(undefined4 *)(glContext + 0x298c) = streamCursor;
  streamCursor = gld_emitUnitObjectPacket(glContext,unitObject,unitIndex,streamCursor);
  *(undefined4 *)(glContext + 0x298c) = streamCursor;
                    
                    
  (**(code **)(glContext + 0x299c))(stream,streamCursor);
  return;
}

/* FUN_00030a50 @ 0x30a50 (8 bytes) */
int FUN_00030a50(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  return _gldDeleteTexture(*(undefined4 *)(param_1 + 4),param_2);
}

/* gld_emitRenderTargetPacket @ 0x30a60 (240 bytes) */
int gld_emitRenderTargetPacket(cmd, colorFormat, colorPitch, blockPitch, tileFlags, colorOffset, colorSize)
  undefined4 *cmd;
  uint colorFormat;
  undefined4 colorPitch;
  undefined4 blockPitch;
  undefined4 tileFlags;
  undefined4 colorOffset;
  undefined4 colorSize;
{
  *cmd = 0xc0101000;
  cmd[1] = 0x51b;
  cmd[2] = (colorFormat & 0xf) << 8 | 0x42cc30f3;
  cmd[3] = 0x1056b;
  cmd[4] = 0;
  cmd[5] = colorPitch;
  cmd[6] = 0x10501;
  cmd[7] = 0;
  cmd[8] = blockPitch;
  cmd[9] = 0x5c1;
  cmd[10] = 0;
  cmd[0xb] = 0x5c0;
  cmd[0xc] = tileFlags;
  cmd[0xd] = 0x50d;
  cmd[0xe] = colorOffset;
  cmd[0xf] = 0x1050e;
  cmd[0x10] = 0;
  cmd[0x11] = colorSize;
  return cmd + 0x12;
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

/* gld_createInternalTexture @ 0x30c50 (684 bytes) */
int gld_createInternalTexture(glContext, width, height, depth, enumParam5, formatIndex, enumParam7, dimension)
  int glContext;
  int width;
  int height;
  int depth;
  undefined4 enumParam5;
  undefined4 formatIndex;
  undefined4 enumParam7;
  int dimension;
{
  int texelStorage;
  undefined2 *texDesc;
  int scratchInt2;
  int log2Height;
  int log2Depth;
  int log2Max;
  int scratchInt6;
  undefined4 connection;
  int createdTexture [9];
  
  connection = *(undefined4 *)(glContext + 4);
  createdTexture[0] = 0;
  texDesc = (undefined2 *)_malloc(0x910);
  if (texDesc != (undefined2 *)0x0) {
    texDesc[0x24] = 0;
    *(undefined4 *)(texDesc + 0x26) = 0;
    *(undefined4 *)(texDesc + 4) = 0;
    texDesc[6] = 0x405;
    *(undefined4 *)(texDesc + 0x22) = 0;
    texDesc[10] = 0x2901;
    texDesc[8] = 0x2901;
    texDesc[9] = 0x2901;
    *(undefined4 *)(texDesc + 0xe) = 0;
    *(undefined4 *)(texDesc + 0x10) = 0;
    *(undefined4 *)(texDesc + 0x12) = 0;
    *(undefined4 *)(texDesc + 0x14) = 0;
    *(undefined4 *)(texDesc + 0x1c) = 0;
    texDesc[0x1e] = 0;
    texDesc[0x1f] = 0;
    texDesc[0x20] = 0;
    texDesc[0x21] = 0;
    *texDesc = (short)dimension;
    texDesc[0xd] = 0x85bd;
    *(undefined4 *)(texDesc + 0x16) = 0x3f800000;
    *(undefined4 *)(texDesc + 2) = 0x3f800000;
    *(undefined4 *)(texDesc + 0x18) = 0xc47a0000;
    *(undefined4 *)(texDesc + 0x1a) = 0x447a0000;
    texDesc[0x2e] = 0x2600;
    texDesc[0xb] = 0x2600;
    texDesc[0xc] = 0x2600;
    texDesc[1] = (*(unsigned short *)((unsigned char *)&(enumParam5) + 2));
    texDesc[0x2a] = (*(unsigned short *)((unsigned char *)&(enumParam5) + 2));
    texDesc[0x2c] = (*(unsigned short *)((unsigned char *)&(enumParam5) + 2));
    texDesc[0x2d] = (*(unsigned short *)((unsigned char *)&(enumParam7) + 2));
    *(undefined1 *)(texDesc + 0x2f) = 0;
    *(uint *)(texDesc + 0x24) = *(uint *)(texDesc + 0x24) & 0xffff7f7f;
    *(undefined1 *)((int)texDesc + 0x5f) = 0;
    scratchInt2 = ((int (*)())floorLog2)(width);
    log2Height = ((int (*)())floorLog2)(height);
    log2Depth = ((int (*)())floorLog2)(depth);
    *(char *)(texDesc + 0x30) = (char)scratchInt2;
    *(char *)(texDesc + 0x31) = (char)log2Depth;
    *(char *)((int)texDesc + 0x61) = (char)log2Height;
    scratchInt6 = log2Height;
    if (log2Height < log2Depth) {
      scratchInt6 = log2Depth;
    }
    log2Max = scratchInt2;
    if (scratchInt2 < scratchInt6) {
      log2Max = scratchInt6;
    }
    *(char *)((int)texDesc + 0x65) = (char)log2Height;
    *(char *)(texDesc + 0x32) = (char)scratchInt2;
    *(undefined1 *)(texDesc + 0x36) = 1;
    *(undefined1 *)(texDesc + 0x35) = 1;
    *(char *)(texDesc + 0x33) = (char)log2Depth;
    *(char *)((int)texDesc + 0x67) = (char)log2Max;
    *(undefined1 *)((int)texDesc + 0x6d) = 0;
    texDesc[0x3e] = 1;
    *(char *)((int)texDesc + 99) = (char)log2Max;
    *(undefined1 *)((int)texDesc + 0x69) = 0;
    *(undefined1 *)((int)texDesc + 0x6b) = 0;
    texDesc[0x38] = 1;
    *(char *)(texDesc + 0x37) = (dimension == 3) << 1;
    *(char *)((int)texDesc + 0x6f) = (dimension == 1) << 1;
    scratchInt2 = 1 << (*(uint *)(&DAT_001d9f48 + (uint)(byte)formatIndex * 0x24) & 7);
    texelStorage = _malloc(scratchInt2 * depth * width * height);
    if (texelStorage != 0) {
      *(int *)(texDesc + 0x5a) = texelStorage;
      texDesc[0x54] = (short)depth;
      texDesc[0x57] = (short)height;
      *(undefined1 *)(texDesc + 0x55) = 0;
      texDesc[0x58] = (*(unsigned short *)((unsigned char *)&(enumParam5) + 2));
      texDesc[0x56] = (short)width * (short)scratchInt2;
      texDesc[0x59] = (*(unsigned short *)((unsigned char *)&(enumParam7) + 2));
      texDesc[0x52] = (short)width;
      texDesc[0x53] = (short)height;
      scratchInt6 = _gldCreateTexture(connection,createdTexture,texDesc);
      if ((scratchInt6 == 0) && (createdTexture[0] != 0)) {
        *(undefined1 *)(createdTexture[0] + 0x39) = 0xff;
        *(byte *)(createdTexture[0] + 0x38) = (byte)formatIndex;
        *(ushort *)(createdTexture[0] + 0x24) = *(ushort *)(createdTexture[0] + 0x24) | 1;
        return createdTexture[0];
      }
    }
    _free(texDesc);
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

/* gld_getTextureFormatInfo @ 0x30f60 (492 bytes) */
int gld_getTextureFormatInfo(ctx, texture, face, level, formatInfoOut)
  undefined4 ctx;
  int texture;
  int face;
  int level;
  uint *formatInfoOut;
{
  ushort hwFormatCode;
  short baseFormat;
  uint scratchUint3;
  int scratchInt4;
  uint formatFlags;
  
  scratchUint3 = (uint)*(byte *)(texture + 0x38);
  if (scratchUint3 == 0) {
    ((int (*)())gld_selectTextureHardwareFormat)(ctx,texture);
    scratchUint3 = (uint)*(byte *)(texture + 0x38);
  }
  scratchInt4 = scratchUint3 * 0x24;
  formatFlags = *(uint *)(&DAT_001d9f44 + scratchInt4);
  if ((formatFlags & 0x3f0000) != 0) {
    if ((formatFlags & 0xfc00) != 0) {
      if ((((formatFlags & 0x3f0) != 0) && (*(uint *)(&DAT_001d9f48 + scratchInt4) >> 0x1a != 0)) &&
         (*(short *)(*(int *)(texture + 0x30) + 2) == 0x1907)) {
        hwFormatCode = *(ushort *)(&DAT_001d9f3e + scratchInt4);
        formatInfoOut[4] = 0;
        *formatInfoOut = (uint)hwFormatCode;
        formatInfoOut[7] = *(uint *)(&DAT_001d9f48 + scratchInt4) >> 8 & 0x3f;
        goto LAB_000310c0;
      }
    }
  }
  if (scratchUint3 == 0x29) {
    baseFormat = *(short *)(*(int *)(texture + 0x30) + 2);
    if (baseFormat == 0x1902) {
      *formatInfoOut = 0x81a6;
      formatInfoOut[7] = (*(unsigned int *)&DAT_001da50c) >> 8 & 0x3f;
    }
    else if (baseFormat == 0x1901) {
      formatInfoOut[7] = 0;
      *formatInfoOut = 0x81a6;
    }
    else {
      *formatInfoOut = (uint)(*(unsigned int *)&DAT_001da500);
      formatInfoOut[7] = (*(unsigned int *)&DAT_001da50c) >> 8 & 0x3f;
    }
    formatInfoOut[4] = 0;
  }
  else {
    *formatInfoOut = (uint)*(ushort *)(&DAT_001d9f3c + scratchInt4);
    formatInfoOut[4] = *(uint *)(&DAT_001d9f48 + scratchInt4) >> 0x1a;
    formatInfoOut[7] = *(uint *)(&DAT_001d9f48 + scratchInt4) >> 8 & 0x3f;
  }
LAB_000310c0:
  formatInfoOut[1] = *(ushort *)(&DAT_001d9f44 + scratchInt4) & 0x3f;
  formatInfoOut[2] = *(uint *)(&DAT_001d9f44 + scratchInt4) >> 10 & 0x3f;
  formatInfoOut[3] = *(uint *)(&DAT_001d9f44 + scratchInt4) >> 4 & 0x3f;
  formatInfoOut[5] = *(uint *)(&DAT_001d9f48 + scratchInt4) >> 0x14 & 0x3f;
  formatInfoOut[6] = *(uint *)(&DAT_001d9f48 + scratchInt4) >> 0xe & 0x3f;
  scratchUint3 = *(uint *)(&DAT_001d9f48 + scratchInt4) >> 3 & 1;
  *(char *)(formatInfoOut + 9) = (char)scratchUint3;
  if (scratchUint3 == 0) {
    formatInfoOut[8] = 0;
  }
  else {
    scratchInt4 = *(int *)(texture + 0x30) + 0xa0 + level * 0x18 + face * 0x168;
    scratchUint3 = ((int (*)())gldCompressedImageBytes)((uint)*(byte *)(texture + 0x38),(uint)*(ushort *)(scratchInt4 + 4),
                         (uint)*(ushort *)(scratchInt4 + 6),(uint)*(ushort *)(scratchInt4 + 8));
    formatInfoOut[8] = scratchUint3;
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
    ((int (*)())gld_selectTextureHardwareFormat)(ctx,texture);
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

/* gld_readbackTextureLevel @ 0x31340 (1352 bytes) */
int gld_readbackTextureLevel(ctx, texture, face, mipLevel, surfaceFormat, surfaceType, levelBuffer, procPitch)
  int ctx;
  int *texture;
  int face;
  uint mipLevel;
  undefined4 *surfaceFormat;
  undefined4 surfaceType;
  int levelBuffer;
  undefined4 *procPitch;
{
  int gld_isStampRetiredResult;
  int loopIndex;
  int loopIndex2;
  byte formatByte;
  char storageKind;
  int scratchInt3;
  uint *ringTail;
  short baseFormat;
  undefined4 *packet;
  int scratchInt6;
  undefined1 *convertOutAPtr;
  undefined1 *convertOutBPtr;
  undefined1 *lookupOut1Ptr;
  undefined4 *scratchArgA1;
  undefined4 scratchUint10;
  undefined1 *lookupOut2Ptr;
  undefined4 *scratchArgA7;
  int blockRows;
  int scratchInt13;
  int scratchInt14;
  int levelHeight;
  undefined4 *storage;
  uint scratchUint17;
  undefined1 lookupOut0 [4];
  undefined1 lookupOut1 [4];
  undefined1 lookupOut2 [4];
  undefined1 lookupOut3 [4];
  undefined1 lookupOut4 [4];
  undefined1 lookupOut5 [4];
  int srcAddress;
  uint srcRowStride;
  int convertDest;
  undefined4 convertField;
  int destRow;
  undefined4 *destPitch;
  undefined1 convertOutA [4];
  undefined1 convertOutB [4];
  undefined4 convertMode;
  uint convertFlags;
  undefined4 convertMask;
  int convertWidth;
  int convertHeight;
  undefined1 convertByte;
  undefined4 requestHandle;
  uint requestFaceLevel;
  int destAddress;
  undefined4 lookupField9c;
  
  storage = (undefined4 *)texture[0xd];
  scratchInt14 = *texture;
  if ((storage == (undefined4 *)0x0) || (*(char *)(texture + 0xe) == '\0')) {
    return 0x2717;
  }
  scratchUint17 = mipLevel;
  scratchArgA1 = surfaceFormat;
  scratchUint10 = surfaceType;
  scratchArgA7 = procPitch;
  if ((*(short *)(texture[0xc] + 2) == 0x1902) && (*(char *)(texture + 0x32) == '\x01')) {
    scratchInt13 = face;
    packet = (undefined4 *)(**(code **)(ctx + 0x2998))(ctx + 0x240,0x3fa);
    *(undefined4 **)(ctx + 0x298c) = packet;
    scratchArgA7 = packet + 0x3ed;
    scratchUint10 = 0x113c8;
    scratchArgA1 = packet + 0x3f8;
    ringTail = *(uint **)(ctx + 0x1d8);
    *ringTail = (int)packet - (int)ringTail >> 2 | *ringTail;
    *(undefined4 **)(ctx + 0x1d8) = packet;
    *packet = 0x45000000;
    packet[1] = 0x3ed;
    packet[2] = 0xd;
    packet[3] = *(undefined4 *)texture[0xd];
    formatByte = *(byte *)(texture + 0xe);
    packet[0x3ed] = ((unsigned char *)0x000013c4U);
    packet[4] = (uint)formatByte;
    packet[0x3f6] = ((unsigned char *)0x000013caU);
    packet[0x3ef] = 0x113c8;
    packet[0x3f4] = ((unsigned char *)0x000013ccU);
    packet[0x3f2] = ((unsigned char *)0x000013cdU);
    *(undefined4 **)(ctx + 0x298c) = scratchArgA1;
    (**(code **)(ctx + 0x299c))(ctx + 0x240,scratchArgA1,scratchInt13,scratchUint17,scratchArgA1,0x113c8,packet,scratchArgA7);
    if (*(int *)(ctx + 0x1e4) + 0x28U < *(uint *)(ctx + 0x1dc)) {
      gld_submitRing(ctx,0x1000000);
    }
    *(undefined1 *)(texture + 0x32) = 0;
  }
  storageKind = *(char *)((int)storage + 0x16);
  if ((storageKind != '\x03') && (storageKind != '\a')) {
    if (storageKind != '\x06') {
      return 0x2717;
    }
    if ((0x1ffff < (int)storage[4]) &&
       (*(int *)(ctx + 0x1e4) + 0x28U < *(uint *)(ctx + 0x1dc))) {
      gld_submitRing(ctx,0x1000000);
    }
    scratchInt14 = face * 2;
    scratchInt13 = scratchInt14 + (int)storage;
    if ((((uint)*(ushort *)(scratchInt13 + 0x28) & ~(uint)*(ushort *)(scratchInt13 + 0x1c)) >> (mipLevel & 0x3f)
        & 1) == 0) {
      return 0;
    }
    gld_isStampRetiredResult = gld_isStampRetired(ctx,storage[3]);
    if (gld_isStampRetiredResult == 0) {
      scratchUint17 = 1;
      scratchArgA1 = (undefined4 *)0x0;
      scratchUint10 = 0;
      _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + 4),9,storage + 3,1,0,0);
    }
    if ((levelBuffer != 0) && ((*(uint *)(ctx + 0x24) & 0x82) != 0)) {
      gldFlushDataCacheRangeSync(ctx,levelBuffer,texture[4],scratchUint17,scratchArgA1,scratchUint10,scratchInt13,scratchArgA7);
    }
    *(ushort *)((int)storage + scratchInt14 + 0x1c) =
         *(ushort *)((int)storage + scratchInt14 + 0x1c) | *(ushort *)((int)storage + scratchInt14 + 0x28);
    return 0;
  }
  scratchInt13 = scratchInt14 + 0x40 + (face * 0xd + mipLevel) * 0x20;
  if ((0x1ffff < (int)storage[4]) &&
     (*(int *)(ctx + 0x1e4) + 0x28U < *(uint *)(ctx + 0x1dc))) {
    gld_submitRing(ctx,0x1000000);
  }
  if ((((uint)*(ushort *)((int)storage + face * 2 + 0x28) &
       ~(uint)*(ushort *)((int)storage + face * 2 + 0x1c)) >> (mipLevel & 0x3f) & 1) != 0) {
    requestHandle = *storage;
    requestFaceLevel = mipLevel | face << 0x10;
    _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + 4),0xd,&requestHandle,2,0,0);
  }
  if ((*(uint *)(scratchInt14 + 0x20) & 0x10000000) != 0) {
    gld_isStampRetiredResult = gld_isStampRetired(ctx,*(undefined4 *)(scratchInt14 + 0x1c));
    if (gld_isStampRetiredResult == 0) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + 4),9,scratchInt14 + 0x1c,1,0,0);
    }
    *(uint *)(scratchInt14 + 0x20) = *(uint *)(scratchInt14 + 0x20) & 0xefffffff;
  }
  if (*(char *)((int)storage + 0x16) == '\a') {
    return 0;
  }
  scratchUint17 = mipLevel - *(byte *)((int)storage + 0x17);
  scratchInt3 = (int)(uint)*(ushort *)(scratchInt14 + 0x14) >> (scratchUint17 & 0x3f);
  levelHeight = (int)(uint)*(ushort *)(scratchInt14 + 0x16) >> (scratchUint17 & 0x3f);
  blockRows = (int)(uint)*(ushort *)(scratchInt14 + 0x18) >> (scratchUint17 & 0x3f);
  scratchInt6 = 1;
  if (0 < scratchInt3) {
    scratchInt6 = scratchInt3;
  }
  if (levelHeight < 1) {
    levelHeight = 1;
  }
  if (blockRows < 1) {
    blockRows = 1;
  }
  lookupOut1Ptr = lookupOut1;
  blockRows = blockRows / (int)(uint)*(ushort *)(scratchInt13 + 2);
  lookupOut2Ptr = lookupOut2;
  ((int (*)())gldTextureFormatLookup)((uint)*(byte *)(texture + 0xe),texture,&requestHandle,lookupOut0,lookupOut1Ptr,lookupOut2Ptr,
               lookupOut3,lookupOut4,lookupOut5);
  scratchUint10 = 0;
  convertMode = 2;
  convertDest = destAddress;
  convertField = lookupField9c;
  convertFlags = 0;
  convertMask = 0xffffefff;
  srcRowStride = *(uint *)(scratchInt14 + 0x10) >> (scratchUint17 & 0x3f);
  if ((int)srcRowStride < 0x20) {
    srcRowStride = 0x20;
  }
  convertByte = 0;
  convertOutAPtr = convertOutA;
  convertOutBPtr = convertOutB;
  destRow = levelBuffer;
  destPitch = procPitch;
  convertWidth = scratchInt6;
  convertHeight = levelHeight;
  _glgConvertType(surfaceFormat,surfaceType,convertOutAPtr,convertOutBPtr,lookupOut1Ptr,lookupOut2Ptr,destAddress,0);
  scratchInt14 = *(int *)(scratchInt13 + 0x1c);
  if (scratchInt14 == 0) {
    return 0x2717;
  }
  baseFormat = *(short *)(texture[0xc] + 2);
  if ((baseFormat == 0x1909) || (scratchUint17 = convertFlags | 0x20000, baseFormat == 0x1907)) {
    convertFlags = convertFlags | 0x28000;
    baseFormat = *(short *)(texture[0xc] + 2);
    scratchUint17 = convertFlags;
    if (baseFormat != 0x1909) goto LAB_000316d8;
  }
  else {
LAB_000316d8:
    convertFlags = scratchUint17;
    if ((baseFormat != -0x7fb7) && (baseFormat != 0x190a)) goto LAB_000316fc;
  }
  convertFlags = convertFlags | 0x40000;
LAB_000316fc:
  if (*(short *)(scratchInt13 + 2) != 0) {
    loopIndex = 0;
    do {
      if (0 < blockRows) {
        loopIndex2 = 0;
        srcAddress = scratchInt14;
        do {
          loopIndex2 = loopIndex2 + 1;
          _glgProcessPixels(0,&srcAddress,convertOutAPtr,convertOutBPtr,lookupOut1Ptr,lookupOut2Ptr,destAddress,scratchUint10);
          srcAddress = levelHeight * srcRowStride + srcAddress;
          destAddress = levelHeight * (int)destPitch + destRow;
          destRow = destAddress;
        } while (blockRows != loopIndex2);
      }
      loopIndex = loopIndex + 1;
      scratchInt14 = scratchInt14 + *(int *)(scratchInt13 + 0xc);
    } while (loopIndex < (int)(uint)*(ushort *)(scratchInt13 + 2));
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
    returnCode = ((int (*)())gld_readbackTextureLevel)(ctx,texture,face,level,(uint)*(ushort *)(levelEntry + 0x10),
                         (uint)*(ushort *)(levelEntry + 0x12),*(undefined4 *)(levelEntry + 0x14),
                         (uint)levelFormat * bytesPerElement);
    _pthread_mutex_unlock(*(undefined4 *)(ctx + GLD_mutex));
  }
  return returnCode;
}

/* gld_uploadTextureLevel @ 0x31940 (1972 bytes) */
int gld_uploadTextureLevel(ctxSaved, texture)
  int ctxSaved;
  int *texture;
{
  int gld_ensureTextureBackingSized2Result;
  uint loopIndex;
  bool fitsSizeLimit;
  byte baseLevelByte;
  ushort dirtyLevelMask;
  uint scratchUint4;
  uint scratchUint5;
  uint alignedRowBytes;
  int scratchInt7;
  uint scratchUint8;
  int scratchInt9;
  uint oldSamplerWord31c;
  int scratchInt11;
  undefined4 *packetEndB;
  undefined4 *packetEndC;
  uint scratchUint14;
  undefined1 *convertBlockPtr;
  undefined1 *outputBlockPtr;
  uint scratchUint17;
  uint scratchUint18;
  undefined4 staleArgR10;
  int *packetEndA;
  uint levelNumber;
  uint tileModeFlag;
  uint scratchUint23;
  uint levelHeight;
  uint levelWidth;
  int scratchInt26;
  int *backing;
  int *uploadPtr;
  undefined *formatEntry;
  int levelRecord;
  uint texelShift;
  uint formatClass;
  int hwFormatCode;
  int bytesPerTexel;
  undefined1 lookupOutScratch [4];
  int descSrc;
  int descSrcPitch;
  undefined1 convertOutA [4];
  undefined1 convertOutB [4];
  int *descDst;
  uint descDstPitch;
  undefined4 descZeroC0;
  uint descWidth;
  uint descHeight;
  undefined4 descZeroB0;
  undefined4 descZeroAC;
  uint packedFormatFlag;
  int tileBitsZero;
  int *cacheFlushStart;
  int *formatLookupBlockPtr;
  
  scratchInt9 = texture[0xc];
  scratchInt7 = (uint)*(byte *)(texture + 0xe) * 0x24;
  baseLevelByte = *(byte *)(scratchInt9 + 0x5e);
  levelNumber = (uint)baseLevelByte;
  dirtyLevelMask = *(ushort *)(scratchInt9 + 0x7c);
  formatLookupBlockPtr = &descSrc;
  levelRecord = scratchInt9 + 0xa0 + levelNumber * 0x18;
  scratchUint23 = (uint)((*(uint *)(&DAT_001d9f48 + scratchInt7) & 7) == 4);
  scratchInt9 = gldPixelUnitBytes((uint)*(ushort *)(levelRecord + 0x10),(uint)*(ushort *)(levelRecord + 0x12));
  outputBlockPtr = lookupOutScratch;
  scratchInt26 = scratchInt9 * (uint)*(ushort *)(levelRecord + 0xc);
  tileModeFlag = scratchUint23 ^ 1;
  scratchInt9 = (uint)*(byte *)(levelRecord + 10) * (scratchInt9 + scratchInt26) + *(int *)(levelRecord + 0x14);
  ((int (*)())gldTextureFormatLookup)((uint)*(byte *)(texture + 0xe),texture,formatLookupBlockPtr,&texelShift,outputBlockPtr,outputBlockPtr,&bytesPerTexel,
               &formatClass,&hwFormatCode);
  levelWidth = (uint)*(ushort *)(levelRecord + 4) + (uint)*(byte *)(levelRecord + 10) * -2;
  if ((int)levelWidth < 1) {
    levelWidth = 1;
  }
  levelHeight = (uint)*(ushort *)(levelRecord + 6) + (uint)*(byte *)(levelRecord + 10) * -2;
  if ((int)levelHeight < 1) {
    levelHeight = 1;
  }
  descZeroC0 = 0;
  if (scratchUint23 == 0) {
    scratchUint17 = *(uint *)(&DAT_001d9f4c + scratchInt7) >> 0x1c & 3;
    if (scratchUint17 == 0) {
      tileBitsZero = 1;
      scratchUint18 = 0;
    }
    else {
      tileBitsZero = 0;
      scratchUint18 = scratchUint17;
    }
  }
  else {
    scratchUint17 = 0;
    tileBitsZero = 0;
    scratchUint18 = 0;
  }
  if (((scratchUint23 != 0) || ((*(uint *)(&DAT_001d9f4c + scratchInt7) & 0x30000000) != 0x20000000)) ||
     (packedFormatFlag = 1, (*(uint *)(&DAT_001d9f48 + scratchInt7) & 7) != 1)) {
    packedFormatFlag = 0;
  }
  scratchUint18 = 8 << scratchUint18;
  scratchUint23 = (0x20 >> (texelShift + scratchUint17 & 0x3f)) * 8;
  if ((levelWidth <= scratchUint23) || (scratchUint17 = 1, levelHeight <= scratchUint18)) {
    scratchUint17 = 0;
  }
  alignedRowBytes = (levelWidth << (texelShift & 0x3f)) + 0x1f & 0xffffffe0;
  scratchInt7 = alignedRowBytes * levelHeight;
  if (scratchUint17 == 0) {
    tileModeFlag = 0;
    scratchInt11 = scratchInt7;
    scratchUint23 = alignedRowBytes;
  }
  else {
    scratchUint23 = scratchUint23 * (((scratchUint23 + levelWidth) - 1) / scratchUint23) << (texelShift & 0x3f);
    scratchInt11 = scratchUint18 * (((scratchUint18 + levelHeight) - 1) / scratchUint18) * scratchUint23;
  }
  *(short *)((int)texture + 0x3e) = (short)(scratchUint23 >> (texelShift & 0x3f));
  scratchUint18 = texelShift;
  gld_ensureTextureBackingSized2Result = gld_ensureTextureBackingSized2(ctxSaved,texture,scratchInt7 + 0x3a0,scratchInt11);
  staleArgR10 = 0;
  if (gld_ensureTextureBackingSized2Result == 0) {
    return 0;
  }
  scratchInt11 = texture[0xd];
  *(byte *)(scratchInt11 + 0x15) = (byte)(scratchUint17 << 2) | (byte)((tileModeFlag << (packedFormatFlag & 0x3f)) << 3) & 0x18
  ;
  backing = (int *)*texture;
  if ((dirtyLevelMask & 1) != 0) {
    convertBlockPtr = convertOutB;
    uploadPtr = backing + 0x368;
    _glgConvertType((uint)*(ushort *)(levelRecord + 0x10),(uint)*(ushort *)(levelRecord + 0x12),convertOutA,
                    convertBlockPtr,outputBlockPtr,scratchUint18,scratchInt11,0);
    descZeroAC = 0;
    descZeroB0 = 0;
    cacheFlushStart = backing + 0x280;
    scratchUint14 = (uint)*(byte *)(texture + 0xe);
    descSrc = scratchInt9;
    descSrcPitch = scratchInt26;
    descDst = uploadPtr;
    descDstPitch = alignedRowBytes;
    descWidth = levelWidth;
    descHeight = levelHeight;
    scratchInt26 = ((int (*)())gldTextureFormatCodeMatchesType)((uint)*(ushort *)(levelRecord + 0x10),(uint)*(ushort *)(levelRecord + 0x12),scratchUint14);
    if (scratchInt26 == 0) {
      _glgProcessPixels(0,formatLookupBlockPtr,scratchUint14,convertBlockPtr,outputBlockPtr,scratchUint18,scratchInt11,staleArgR10);
    }
    else if (levelHeight != 0) {
      loopIndex = 0;
      do {
        loopIndex = loopIndex + 1;
        _memcpy(uploadPtr,scratchInt9,bytesPerTexel * descWidth);
        uploadPtr = (int *)((int)uploadPtr + descDstPitch);
        scratchInt9 = scratchInt9 + descSrcPitch;
      } while (loopIndex < descHeight);
    }
    if ((*(uint *)(ctxSaved + 0x24) & 0x82) != 0) {
      gldFlushDataCacheRange(ctxSaved,cacheFlushStart + 0x20,scratchInt7,convertBlockPtr,outputBlockPtr,scratchUint18,cacheFlushStart,staleArgR10);
    }
  }
  if ((*(byte *)((int)texture + 0x39) & 3) == 0) goto LAB_00032098;
  if ((formatClass < 3) || ((scratchInt7 = 1, 4 < formatClass && (scratchInt7 = 2, formatClass != 6)))) {
    scratchInt7 = 0;
  }
  uploadPtr = backing + 0x280;
  *(byte *)(texture[0xd] + 0x17) = baseLevelByte;
  fitsSizeLimit = (int)(levelWidth << (texelShift & 0x3f)) >> scratchInt7 < 0x2000;
  *(undefined1 *)(texture[0xd] + 0x34) = 1;
  *(undefined1 *)(texture[0xd] + 0x35) = 1;
  *(uint *)(*texture + 0x20) = (uint)fitsSizeLimit << 0x1f | *(uint *)(*texture + 0x20) & 0x7fffffff;
  *(uint *)(*texture + 0x20) = *(uint *)(*texture + 0x20) | 0x40000000;
  backing[1] = 0x20;
  backing[2] = 0;
  *backing = 0;
  scratchUint18 = backing[8];
  backing[8] = scratchUint18 & 0xefffffff;
  *(char *)((int)backing + 0x1a) = (char)texelShift;
  *(undefined2 *)(backing + 6) = 1;
  *(short *)(backing + 5) = (short)levelWidth;
  *(short *)((int)backing + 0x16) = (short)levelHeight;
  backing[8] = scratchUint18 & 0xcfffffff;
  backing[3] = scratchUint23;
  backing[4] = alignedRowBytes;
  *(char *)((int)backing + 0x1b) = (char)hwFormatCode;
  scratchInt9 = (uint)*(byte *)(texture + 0xe) * 0x24;
  formatEntry = &DAT_001d9f34 + scratchInt9;
  if ((*(uint *)(&DAT_001d9f4c + scratchInt9) & 0x10000) == 0) {
    if ((*(uint *)(&DAT_001d9f48 + scratchInt9) & 8) == 0) {
      scratchUint18 = *(uint *)(&DAT_001d9f48 + scratchInt9) & 7;
      if (scratchUint18 == 1) {
        formatEntry = &DAT_001da00c;
      }
      else if (scratchUint18 < 2) {
        if (scratchUint18 == 0) {
          formatEntry = &DAT_001d9fa0;
        }
        else {
LAB_00031db8:
          formatEntry = &DAT_001da1bc;
        }
      }
      else {
        if (scratchUint18 == 2) goto LAB_00031eb4;
        if (scratchUint18 != 3) goto LAB_00031db8;
        formatEntry = &DAT_001da36c;
      }
    }
    else {
LAB_00031eb4:
      formatEntry = &DAT_001da054;
    }
  }
  _memcpy(backing + 0x2a0,PTR_DAT_001e899c,0x23c);
  scratchUint8 = backing[0x306];
  oldSamplerWord31c = backing[0x31c];
  backing[0x2ab] = 0;
  scratchUint18 = *(uint *)(formatEntry + 0x18) >> 5 & 0x1f;
  backing[0x306] = scratchUint18 | scratchUint8 & 0xffffffe0;
  scratchUint14 = (*(uint *)(formatEntry + 0x18) & 0x18) << 5;
  backing[0x306] = scratchUint14 | scratchUint18 | scratchUint8 & 0xfffffce0;
  scratchUint4 = (*(uint *)(formatEntry + 0x18) & 6) << 9;
  backing[0x306] = scratchUint4 | scratchUint14 | scratchUint18 | scratchUint8 & 0xfffff0e0;
  scratchUint5 = *(uint *)(formatEntry + 0x1c) >> 0x12 & 0x3000;
  backing[0x306] = scratchUint5 | scratchUint4 | scratchUint14 | scratchUint18 | scratchUint8 & 0xffffc0e0;
  backing[0x306] =
       *(uint *)(formatEntry + 0x1c) >> 0xe & 0xc000 |
       scratchUint5 | scratchUint4 | scratchUint14 | scratchUint18 | scratchUint8 & 0xfff000e0;
  scratchUint18 = *(uint *)(formatEntry + 0x1c) >> 7 & 0x1f;
  backing[0x31c] = scratchUint18 | oldSamplerWord31c & 0xfffffe00;
  scratchUint14 = (*(uint *)(formatEntry + 0x1c) & 0x70) << 5;
  backing[0x31c] = scratchUint14 | scratchUint18 | oldSamplerWord31c & 0xfffff000;
  scratchUint4 = (*(uint *)(formatEntry + 0x1c) & 0xe) << 0xb;
  backing[0x31c] = scratchUint4 | scratchUint14 | scratchUint18 | oldSamplerWord31c & 0xffff8000;
  scratchUint5 = *(uint *)(formatEntry + 0x20) >> 0xe & 0x38000;
  backing[0x31c] = scratchUint5 | scratchUint4 | scratchUint14 | scratchUint18 | oldSamplerWord31c & 0xfffc0000;
  scratchUint8 = *(uint *)(formatEntry + 0x20) >> 8 & 0x1c0000;
  backing[0x31c] = scratchUint8 | scratchUint5 | scratchUint4 | scratchUint14 | scratchUint18 | oldSamplerWord31c & 0xffc00000;
  backing[0x31c] =
       (*(uint *)(formatEntry + 0x20) >> 0x19 & 1) << 0x16 |
       scratchUint8 | scratchUint5 | scratchUint4 | scratchUint14 | scratchUint18 | oldSamplerWord31c & 0xf8000000;
  packetEndA = uploadPtr;
  if (fitsSizeLimit) {
    *uploadPtr = (int)((unsigned char *)0x00001393U);
    backing[0x281] = 10;
    backing[0x282] = 0x5c8;
    backing[0x283] = 0x20000;
    backing[0x284] = 0x575;
    packetEndA = backing + 0x286;
    backing[0x285] = hwFormatCode;
  }
  scratchInt26 = (int)packetEndA - (int)uploadPtr >> 2;
  *(short *)(backing + levelNumber * 8 + 0x10) = (short)scratchInt26;
  scratchInt9 = backing[1];
  backing[levelNumber * 8 + 0x17] = (int)(backing + 0x368);
  backing[levelNumber * 8 + 0x11] = 0xda0;
  backing[levelNumber * 8 + 0x15] = 0;
  *(undefined2 *)((int)backing + levelNumber * 0x20 + 0x42) = 1;
  backing[levelNumber * 8 + 0x12] = 0;
  backing[levelNumber * 8 + 0x13] = 0;
  backing[levelNumber * 8 + 0x14] = 0;
  *(short *)(backing + levelNumber * 8 + 0x16) =
       (short)((int)(backing + 0x32f) - (int)uploadPtr >> 2) - (short)scratchInt9;
  if ((tileModeFlag == 0) || (levelNumber = 1, tileBitsZero != 0)) {
    levelNumber = 0;
  }
  scratchUint17 = (packedFormatFlag << 1 | levelNumber) << 1 | scratchUint17;
  packetEndB = (undefined4 *)
            ((int (*)())gld_buildTextureStatePacket)(backing + 0x32f,formatEntry,alignedRowBytes,scratchUint23,scratchUint17,
                         (int)(levelWidth << (texelShift & 0x3f)) >> (*(uint *)(formatEntry + 0x14) & 7),
                         levelHeight);
  *packetEndB = ((unsigned char *)0x00001393U);
  packetEndB[1] = 10;
  packetEndB[2] = 0x5c8;
  packetEndB[3] = 0x20000;
  packetEndB[4] = ((unsigned char *)0x00001040U);
  packetEndB[5] = 0;
  if (fitsSizeLimit) {
    packetEndC = (undefined4 *)
              ((int (*)())gld_emitRenderTargetPacket)(packetEndA,formatClass,alignedRowBytes,scratchUint23,scratchUint17,0,
                           levelHeight << 0x10 | (int)(levelWidth << (texelShift & 0x3f)) >> scratchInt7);
    *packetEndC = 0xd0b;
    packetEndC[1] = 5;
    packetEndC[2] = 0x5c8;
    packetEndC[3] = 0x10000;
    packetEndC[4] = ((unsigned char *)0x00001040U);
    packetEndC[5] = 0;
    scratchInt26 = (int)packetEndC + (0x18 - (int)uploadPtr) >> 2;
  }
  *backing = scratchInt26;
  backing[2] = ((int)packetEndB + (0x18 - (int)uploadPtr) >> 2) - backing[1];
LAB_00032098:
  *(ushort *)(texture[0xd] + 0x1c) = dirtyLevelMask | *(ushort *)(texture[0xd] + 0x1c);
  *(ushort *)(texture[0xd] + 0x28) = ~dirtyLevelMask & *(ushort *)(texture[0xd] + 0x28);
  *(byte *)((int)texture + 0x39) = *(byte *)((int)texture + 0x39) & 0xf8;
  *(ushort *)(texture + 9) = ~dirtyLevelMask & *(ushort *)(texture + 9);
  return 1;
}

/* gldTextureMakeResident @ 0x32100 (8252 bytes) */
int gldTextureMakeResident(ctx, texture, scratchArg3, staleArgR6, staleArgR7, scratchArg6)
  int ctx;
  int *texture;
  uint scratchArg3;
  undefined4 staleArgR6;
  undefined4 staleArgR7;
  uint scratchArg6;
{
  int gld_ensureTextureBackingSized2Result;
  int gld_setTextureNewTextureBackingResult;
  int gld_ensureTextureSurfaceBackingResult;
  int gld_setTextureAgpRefBackingResult;
  int gld_ensureTextureGlobalBackingResult;
  bool scratchFlag1;
  bool scratchFlag2;
  byte scratchFlag3;
  byte scratchFlag4;
  short scratchShort5;
  ushort scratchUint6;
  uint scratchUint7;
  uint scratchUint8;
  uint scratchUint9;
  uint scratchUint10;
  int scratchInt11;
  undefined4 *scratchPtr12;
  int *scratchPtr13;
  undefined4 r4AfterCall;
  int *scratchPtr14;
  uint scratchUint15;
  undefined4 scratchUint16;
  uint *scratchPtr17;
  undefined1 *scratchPtr18;
  undefined4 scratchUint19;
  uint scratchUint20;
  int scratchInt21;
  uint scratchUint22;
  uint scratchUint23;
  int *scratchPtr24;
  int scratchInt25;
  uint *scratchPtr26;
  ushort scratchUint27;
  uint scratchUint28;
  int scratchInt29;
  uint scratchUint30;
  ushort *texImages;
  uint scratchUint32;
  int scratchInt33;
  int *scratchPtr34;
  int scratchInt35;
  uint scratchUint36;
  undefined *formatInfo;
  undefined1 *scratchPtr38;
  byte xerSummaryOverflow = 0;
  bool scratchFlag39;
  bool scratchFlag40;
  byte crField1;
  byte calleeSavedCrField2;
  byte calleeSavedCrField3;
  byte calleeSavedCrField4;
  byte crField5;
  byte scratchFlag41;
  byte scratchFlag42;
  byte scratchFlag43;
  undefined8 scratchUint44;
  int ctxSaved;
  uint scratchStack218;
  uint scratchStack214;
  uint scratchStack210;
  int scratchStack20c;
  int scratchStack208;
  int scratchStack204;
  int scratchStackArr200 [14];
  int scratchStackArr1c8 [9];
  undefined4 scratchStack1a4;
  uint scratchStack158;
  uint scratchStack154;
  undefined1 scratchStackArr150 [4];
  undefined1 scratchStackArr14c [4];
  uint scratchStack148;
  int scratchStack144;
  undefined4 scratchStack138;
  uint scratchStack134;
  undefined4 scratchStack130;
  uint scratchStack12c;
  uint scratchStack128;
  undefined4 scratchStack124;
  undefined4 scratchStack120;
  int *scratchStacke8;
  int scratchStacke4;
  int scratchStacke0;
  int *scratchStackdc;
  int scratchStackd8;
  int *scratchStackd4;
  int scratchStackd0;
  int scratchStackcc;
  int scratchStackc8;
  int scratchStackc4;
  uint scratchStackc0;
  int scratchStackbc;
  uint scratchStackb8;
  uint scratchStackb4;
  uint scratchStackb0;
  int scratchStackac;
  uint scratchStacka8;
  uint scratchStacka4;
  uint scratchStacka0;
  uint scratchStack9c;
  uint scratchStack98;
  uint scratchStack94;
  uint scratchStack90;
  int *scratchStack8c;
  uint scratchStack88;
  int *scratchStack84;
  uint scratchStack80;
  uint scratchStack7c;
  uint scratchStack78;
  int scratchStack74;
  uint scratchStack70;
  uint scratchStack6c;
  uint scratchStack68;
  uint *scratchStack64;
  uint scratchStack60;
  int *scratchStack5c;
  uint scratchStack58;
  uint scratchStack54;
  
  texImages = (ushort *)texture[0xc];
  ctxSaved = ctx;
  scratchInt11 = ((int (*)())gldTextureHasNonPowerOfTwoSize)(texture,texture,scratchArg3,staleArgR6,staleArgR7,scratchArg6);
  if (scratchInt11 != 0) {
    scratchInt25 = texture[0xc];
    scratchFlag41 = *(byte *)(scratchInt25 + 1);
    scratchFlag42 = scratchFlag41 & 0xf;
    *(byte *)(texture + 0x1b) = scratchFlag42;
    scratchInt11 = *(short *)(scratchInt25 + 0x3c) * 0x18 + scratchInt25;
    scratchUint22 = (uint)*(byte *)(scratchInt11 + 0xaa);
    if ((scratchFlag41 & 0xf) == 0) {
      scratchUint28 = (uint)*(ushort *)(scratchInt11 + 0xa4) + scratchUint22 * -2;
      if ((int)scratchUint28 < 1) {
        scratchUint28 = 1;
      }
      scratchUint22 = (uint)*(ushort *)(scratchInt11 + 0xa6) + scratchUint22 * -2;
      if ((int)scratchUint22 < 1) {
        scratchUint22 = 1;
      }
      if (((scratchUint28 & scratchUint28 - 1) == 0) && (scratchArg6 = scratchUint22 & scratchUint22 - 1, scratchArg6 == 0))
      goto LAB_00032230;
      goto LAB_00032380;
    }
    if (scratchFlag42 == 1) {
      scratchUint28 = (uint)*(ushort *)(scratchInt11 + 0xa4) + scratchUint22 * -2;
      if ((int)scratchUint28 < 1) {
        scratchUint28 = 1;
      }
      scratchArg6 = (uint)*(ushort *)(scratchInt11 + 0xa6) + scratchUint22 * -2;
      if ((int)scratchArg6 < 1) {
        scratchArg6 = 1;
      }
      scratchUint22 = (uint)*(ushort *)(scratchInt11 + 0xa8) + scratchUint22 * -2;
      if ((int)scratchUint22 < 1) {
        scratchUint22 = 1;
      }
      if ((((scratchUint28 & scratchUint28 - 1) != 0) || ((scratchArg6 & scratchArg6 - 1) != 0)) ||
         ((scratchUint22 & scratchUint22 - 1) != 0)) goto LAB_00032380;
    }
LAB_00032230:
    scratchFlag41 = *(byte *)(scratchInt25 + 1) & 0xf;
    *(byte *)(texture + 0x1b) = scratchFlag41;
    scratchInt11 = *(short *)(scratchInt25 + 0x3c) * 0x18 + scratchInt25;
    scratchUint22 = (uint)*(byte *)(scratchInt11 + 0xaa);
    if (scratchFlag41 == 3) {
      scratchUint28 = (uint)*(ushort *)(scratchInt11 + 0xa4) + scratchUint22 * -2;
      if ((int)scratchUint28 < 1) {
        scratchUint28 = 1;
      }
      scratchUint22 = (uint)*(ushort *)(scratchInt11 + 0xa6) + scratchUint22 * -2;
      if ((int)scratchUint22 < 1) {
        scratchUint22 = 1;
      }
      if (((scratchUint28 & scratchUint28 - 1) != 0) || ((scratchUint22 & scratchUint22 - 1) != 0)) {
        if ((ushort)(*(short *)(scratchInt25 + 0x16) + 0xda00U) < 2) {
          scratchUint27 = *(ushort *)(scratchInt25 + 0x10);
          if (scratchUint27 < 0x8744) {
            if (((scratchUint27 < 0x8742) && (scratchUint27 != 0x2901)) && (scratchUint27 != 0x8370)) {
LAB_00032340:
              scratchUint27 = *(ushort *)(scratchInt25 + 0x12);
              if (0x8743 < scratchUint27) goto LAB_00032370;
LAB_0003234c:
              if (((scratchUint27 < 0x8742) && (scratchUint27 != 0x2901)) && (scratchUint27 != 0x8370))
              goto LAB_00032390;
            }
          }
          else if (scratchUint27 != 0x8912) goto LAB_00032340;
        }
LAB_00032380:
        *(undefined1 *)(texture + 0x11) = 1;
        goto LAB_000323a0;
      }
    }
    else if (scratchFlag41 == 4) {
      scratchUint22 = (uint)*(ushort *)(scratchInt11 + 0xa4) + scratchUint22 * -2;
      if ((int)scratchUint22 < 1) {
        scratchUint22 = 1;
      }
      scratchArg6 = scratchUint22 & scratchUint22 - 1;
      if (scratchArg6 != 0) {
        if (1 < (ushort)(*(short *)(scratchInt25 + 0x16) + 0xda00U)) goto LAB_00032380;
        scratchUint27 = *(ushort *)(scratchInt25 + 0x10);
        if (scratchUint27 < 0x8744) goto LAB_0003234c;
LAB_00032370:
        if (scratchUint27 == 0x8912) goto LAB_00032380;
      }
    }
LAB_00032390:
    *(undefined1 *)(texture + 0x11) = 0;
  }
LAB_000323a0:
  scratchFlag41 = *(byte *)((int)texture + 0x39);
  *(byte *)((int)texture + 0x39) = scratchFlag41 & 0x9f;
  if ((scratchFlag41 & 0x1f) == 0) {
    ((int (*)())gld_updateTextureSamplerState)(ctxSaved,texture);
    return 1;
  }
  ((int (*)())gld_selectTextureHardwareFormat)(ctxSaved,texture);
  if (*(char *)(texture + 0xe) == '\0') {
    return 0;
  }
  scratchFlag39 = *(char *)((int)texImages + 0x6f) == '\0';
  scratchFlag41 = (*(char *)((int)texImages + 0x6f) != '\0') << 2 | scratchFlag39 << 1 | xerSummaryOverflow & 1;
  if (!scratchFlag39) {
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
  scratchUint27 = *texImages;
  scratchUint22 = (uint)*(byte *)(texImages + 0x2f);
  if ((scratchUint27 & 0x400) == 0) {
    if ((scratchUint27 & 0x800) != 0) {
      gld_ensureTextureGlobalBackingResult = gld_ensureTextureGlobalBacking(ctxSaved,texture,*(undefined4 *)(texImages + 4));
      if (gld_ensureTextureGlobalBackingResult == 0) {
        return 0;
      }
      if (*(char *)((int)texImages + 0x6d) != '\0') {
        scratchUint22 = 1 << (*(uint *)(&DAT_001d9f48 + (uint)*(byte *)(texture + 0xe) * 0x24) & 7);
        *(short *)((int)texture + 0x3e) =
             (short)((scratchUint22 * ((uint)texImages[0x52] + (uint)*(byte *)(texImages + 0x55) * -2) + 0x1f &
                     0xffffffe0) / scratchUint22);
      }
      goto LAB_00032600;
    }
    if ((scratchUint27 & 0x2000) != 0) {
      scratchInt11 = ((int (*)())gld_uploadTextureLevel)(ctxSaved,texture);
      if (scratchInt11 == 0) {
        return 0;
      }
      goto LAB_00032600;
    }
    scratchUint19 = 0x1a2114;
    scratchUint16 = r4AfterCall;
    if ((((((*(float *)(texture[0xc] + 4) == 0.0) ||
           (scratchShort5 = *(short *)(texture[0xc] + 0x1a), scratchShort5 == -0x7a41)) || (scratchShort5 == -0x7a42)) &&
         ((*(char *)(texImages + 0x36) == '\x01' && (*(char *)(texImages + 0x35) == '\x01')))) &&
        (scratchFlag39)) && (*(int *)(texImages + scratchUint22 * 0xc + 0x5a) != 0)) {
      scratchInt11 = gldPixelUnitBytes((uint)texImages[scratchUint22 * 0xc + 0x58],(uint)texImages[scratchUint22 * 0xc + 0x59]);
      scratchUint27 = texImages[scratchUint22 * 0xc + 0x56];
      scratchUint28 = scratchInt11 * (int)(uint)scratchUint27;
      scratchUint32 = *(int *)(texImages + scratchUint22 * 0xc + 0x5a) +
               scratchInt11 * (uint)*(byte *)(texImages + scratchUint22 * 0xc + 0x55);
      if (*(char *)(texImages + 0x37) != '\0') {
        scratchUint32 = scratchUint32 + scratchUint28 * *(byte *)(texImages + scratchUint22 * 0xc + 0x55);
      }
      scratchFlag4 = *(byte *)(texture + 0xe);
      scratchFlag42 = ((scratchUint32 & 0x1f) != 0) << 2 | ((scratchUint32 & 0x1f) == 0) << 1;
      scratchFlag41 = scratchFlag42 | xerSummaryOverflow & 1;
      scratchArg3 = (uint)scratchFlag4;
      scratchUint44 = ((int (*)())gldTextureFormatCodeMatchesType)((uint)texImages[scratchUint22 * 0xc + 0x58],(uint)texImages[scratchUint22 * 0xc + 0x59],
                            scratchArg3);
      scratchUint16 = (undefined4)scratchUint44;
      scratchInt25 = texture[0xc];
      if (*(short *)(scratchInt25 + 0x1a) == -0x7a41) {
        scratchFlag39 = (undefined *)(uint)scratchUint27 < ((unsigned char *)0x00004001);
      }
      else {
        scratchFlag39 = scratchUint28 <= *(uint *)(ctxSaved + 0x29d8);
      }
      if (((uint)scratchFlag39 &
          (uint)((scratchUint28 & 0x1f) == 0) & scratchFlag42 >> 1 & 1 & (uint)((ulonglong)scratchUint44 >> 0x20)) == 0)
      goto LAB_00034128;
      scratchFlag41 = *(byte *)(scratchInt25 + 0x5e);
      scratchUint30 = (uint)scratchFlag41;
      scratchStack1a4 = 0;
      scratchPtr17 = &scratchStack218;
      scratchPtr26 = &scratchStack214;
      ((int (*)())gldTextureFormatLookup)((uint)scratchFlag4,texture,scratchStackArr1c8,scratchPtr17,&scratchStack208,&scratchStack208,&scratchStack210,scratchPtr26,
                   &scratchStack20c);
      scratchInt33 = (uint)texImages[scratchUint22 * 0xc + 0x52] +
               (uint)*(byte *)(texImages + scratchUint22 * 0xc + 0x55) * -2;
      if (scratchInt33 < 1) {
        scratchInt33 = 1;
      }
      scratchUint22 = (uint)texImages[scratchUint22 * 0xc + 0x53] -
               (uint)*(byte *)(texImages + scratchUint22 * 0xc + 0x55) * (uint)*(byte *)(scratchInt25 + 0x6e);
      if ((int)scratchUint22 < 1) {
        scratchUint22 = 1;
      }
      scratchUint23 = *(uint *)(ctxSaved + 0x24);
      scratchUint20 = scratchUint23 & 0x82;
      scratchInt25 = scratchUint28 * (scratchUint22 - 1) + scratchInt11 * (scratchInt33 + 1U & 0xfffffffe);
      if (scratchUint20 == 0) {
        scratchInt29 = texture[0xc];
      }
      else {
        scratchInt29 = texture[0xc];
        if (((*(uint *)(scratchInt29 + 0x48) & 0x40) == 0) && (scratchUint22 != 0)) {
          scratchUint36 = 0;
          scratchUint16 = 0;
          scratchUint8 = scratchUint32;
          do {
            scratchUint36 = scratchUint36 + 1;
            gldFlushDataCacheRange(ctxSaved,scratchUint8,scratchInt11 * scratchInt33,scratchPtr17,scratchUint20,scratchUint16,scratchUint23,scratchPtr26);
            scratchUint8 = scratchUint8 + scratchUint28;
          } while (scratchUint36 < scratchUint22);
          scratchInt29 = texture[0xc];
        }
      }
      scratchUint23 = *(uint *)(scratchInt29 + 0x50);
      scratchUint20 = scratchUint32;
      if ((scratchUint23 <= scratchUint32) && (scratchUint8 = scratchUint23 + *(int *)(scratchInt29 + 0x4c), scratchUint32 + scratchInt25 <= scratchUint8)
         ) {
        scratchInt25 = scratchUint8 - scratchUint23;
        scratchUint20 = scratchUint23;
      }
      if ((*(short *)(scratchInt29 + 0x1a) == -0x7a41) &&
         ((*(char *)(scratchInt29 + 0x6d) != '\0' || (scratchInt33 * scratchInt11 == scratchUint28)))) {
        *(short *)((int)texture + 0x3e) = (short)(scratchUint28 >> (scratchStack218 & 0x3f));
        gld_setTextureAgpRefBackingResult = gld_setTextureAgpRefBacking(ctxSaved,texture,scratchUint32,scratchUint20,scratchInt25);
        if (gld_setTextureAgpRefBackingResult == 0) {
          return 0;
        }
        scratchUint27 = (ushort)(-2 << (scratchUint30 & 0x1f)) | (ushort)(0xfffffffe >> 0x20 - (scratchUint30 & 0x1f));
        *(byte *)(texture[0xd] + 0x15) = (byte)scratchStack20c & 3;
      }
      else {
        scratchUint23 = (scratchInt33 << (scratchStack218 & 0x3f)) + 0x1fU & 0xffffffe0;
        *(short *)((int)texture + 0x3e) = (short)(scratchUint23 >> (scratchStack218 & 0x3f));
        if ((*(byte *)((int)texture + 0x39) & 3) != 0) {
          if ((scratchStack214 < 3) || ((scratchInt11 = 1, 4 < scratchStack214 && (scratchInt11 = 2, scratchStack214 != 6)))) {
            scratchInt11 = 0;
          }
          scratchFlag39 = (scratchInt33 << (scratchStack218 & 0x3f)) >> scratchInt11 < 0x2000;
          gld_setTextureNewTextureBackingResult = gld_setTextureNewTextureBacking(ctxSaved,texture,0x348,scratchUint23 * scratchUint22,scratchUint20,scratchInt25);
          if (gld_setTextureNewTextureBackingResult == 0) {
            return 0;
          }
          *(undefined1 *)(texture[0xd] + 0x15) = 0;
          scratchPtr34 = (int *)*texture;
          scratchUint8 = scratchPtr34[8];
          scratchPtr34[2] = 0;
          scratchPtr14 = scratchPtr34 + 0x280;
          *scratchPtr34 = 0;
          scratchPtr34[1] = 0x20;
          scratchPtr34[8] = (uint)scratchFlag39 << 0x1f | scratchUint8 & 0x6fffffff | 0x40000000;
          *(char *)((int)scratchPtr34 + 0x1a) = (char)scratchStack218;
          *(undefined2 *)(scratchPtr34 + 6) = 1;
          *(short *)(scratchPtr34 + 5) = (short)scratchInt33;
          *(short *)((int)scratchPtr34 + 0x16) = (short)scratchUint22;
          scratchPtr34[8] = (uint)scratchFlag39 << 0x1f | scratchUint8 & 0x4fffffff | 0x40000000;
          scratchPtr34[3] = scratchUint23;
          scratchPtr34[4] = scratchUint28;
          *(char *)((int)scratchPtr34 + 0x1b) = (char)scratchStack20c;
          scratchInt25 = (uint)*(byte *)(texture + 0xe) * 0x24;
          formatInfo = &DAT_001d9f34 + scratchInt25;
          if ((*(uint *)(&DAT_001d9f4c + scratchInt25) & 0x10000) == 0) {
            if ((*(uint *)(&DAT_001d9f48 + scratchInt25) & 8) == 0) {
              scratchUint8 = *(uint *)(&DAT_001d9f48 + scratchInt25) & 7;
              if (scratchUint8 == 1) {
                formatInfo = &DAT_001da00c;
              }
              else if (scratchUint8 < 2) {
                if (scratchUint8 == 0) {
                  formatInfo = &DAT_001d9fa0;
                }
                else {
LAB_00032a20:
                  formatInfo = &DAT_001da1bc;
                }
              }
              else {
                if (scratchUint8 == 2) goto LAB_00032b08;
                if (scratchUint8 != 3) goto LAB_00032a20;
                formatInfo = &DAT_001da36c;
              }
            }
            else {
LAB_00032b08:
              formatInfo = &DAT_001da054;
            }
          }
          _memcpy(scratchPtr34 + 0x2a0,PTR_DAT_001e899c,0x23c);
          scratchUint9 = scratchPtr34[0x306];
          scratchUint10 = scratchPtr34[0x31c];
          scratchPtr34[0x2ab] = 0;
          scratchUint8 = *(uint *)(formatInfo + 0x18) >> 5 & 0x1f;
          scratchPtr34[0x306] = scratchUint8 | scratchUint9 & 0xffffffe0;
          scratchUint36 = (*(uint *)(formatInfo + 0x18) & 0x18) << 5;
          scratchPtr34[0x306] = scratchUint36 | scratchUint8 | scratchUint9 & 0xfffffce0;
          scratchUint15 = (*(uint *)(formatInfo + 0x18) & 6) << 9;
          scratchPtr34[0x306] = scratchUint15 | scratchUint36 | scratchUint8 | scratchUint9 & 0xfffff0e0;
          scratchUint7 = *(uint *)(formatInfo + 0x1c) >> 0x12 & 0x3000;
          scratchPtr34[0x306] = scratchUint7 | scratchUint15 | scratchUint36 | scratchUint8 | scratchUint9 & 0xffffc0e0;
          scratchPtr34[0x306] =
               *(uint *)(formatInfo + 0x1c) >> 0xe & 0xc000 |
               scratchUint7 | scratchUint15 | scratchUint36 | scratchUint8 | scratchUint9 & 0xfff000e0;
          scratchUint8 = *(uint *)(formatInfo + 0x1c) >> 7 & 0x1f;
          scratchPtr34[0x31c] = scratchUint8 | scratchUint10 & 0xfffffe00;
          scratchUint36 = (*(uint *)(formatInfo + 0x1c) & 0x70) << 5;
          scratchPtr34[0x31c] = scratchUint36 | scratchUint8 | scratchUint10 & 0xfffff000;
          scratchUint15 = (*(uint *)(formatInfo + 0x1c) & 0xe) << 0xb;
          scratchPtr34[0x31c] = scratchUint15 | scratchUint36 | scratchUint8 | scratchUint10 & 0xffff8000;
          scratchUint7 = *(uint *)(formatInfo + 0x20) >> 0xe & 0x38000;
          scratchPtr34[0x31c] = scratchUint7 | scratchUint15 | scratchUint36 | scratchUint8 | scratchUint10 & 0xfffc0000;
          scratchPtr34[0x31c] =
               *(uint *)(formatInfo + 0x20) >> 8 & 0x1c0000 |
               scratchUint7 | scratchUint15 | scratchUint36 | scratchUint8 | scratchUint10 & 0xf8000000;
          scratchPtr13 = scratchPtr14;
          if (scratchFlag39) {
            *scratchPtr14 = (int)((unsigned char *)0x00001393U);
            scratchPtr34[0x281] = 10;
            scratchPtr34[0x282] = 0x5c8;
            scratchPtr34[0x283] = 0x20000;
            scratchPtr34[0x284] = 0x575;
            scratchPtr13 = scratchPtr34 + 0x286;
            scratchPtr34[0x285] = scratchStack20c;
          }
          *(short *)(scratchPtr34 + scratchUint30 * 8 + 0x10) = (short)((int)scratchPtr13 - (int)scratchPtr14 >> 2);
          scratchInt25 = scratchPtr34[1];
          *(undefined2 *)((int)scratchPtr34 + scratchUint30 * 0x20 + 0x42) = 1;
          scratchPtr34[scratchUint30 * 8 + 0x17] = 0;
          scratchPtr34[scratchUint30 * 8 + 0x11] = scratchUint32 - (scratchUint20 & 0xfffff000);
          scratchPtr34[scratchUint30 * 8 + 0x12] = 0;
          scratchPtr34[scratchUint30 * 8 + 0x13] = 0;
          scratchPtr34[scratchUint30 * 8 + 0x14] = 0;
          scratchPtr34[scratchUint30 * 8 + 0x15] = 0;
          *(short *)(scratchPtr34 + scratchUint30 * 8 + 0x16) =
               (short)((int)(scratchPtr34 + 0x32f) - (int)scratchPtr14 >> 2) - (short)scratchInt25;
          scratchInt25 = (uint)*(byte *)(texture + 0xe) * 0x24;
          formatInfo = &DAT_001d9f34 + scratchInt25;
          if ((*(uint *)(&DAT_001d9f4c + scratchInt25) & 0x10000) == 0) {
            if ((*(uint *)(&DAT_001d9f48 + scratchInt25) & 8) == 0) {
              scratchUint32 = *(uint *)(&DAT_001d9f48 + scratchInt25) & 7;
              if (scratchUint32 == 1) {
                formatInfo = &DAT_001da00c;
              }
              else if (scratchUint32 < 2) {
                if (scratchUint32 == 0) {
                  formatInfo = &DAT_001d9fa0;
                }
                else {
LAB_00032bf4:
                  formatInfo = &DAT_001da1bc;
                }
              }
              else {
                if (scratchUint32 == 2) goto LAB_00032c54;
                if (scratchUint32 != 3) goto LAB_00032bf4;
                formatInfo = &DAT_001da36c;
              }
            }
            else {
LAB_00032c54:
              formatInfo = &DAT_001da054;
            }
          }
          scratchPtr12 = (undefined4 *)
                    ((int (*)())gld_buildTextureStatePacket)(scratchPtr34 + 0x32f,formatInfo,scratchUint28,scratchUint23,0,
                                 (scratchInt33 << (scratchStack218 & 0x3f)) >> (*(uint *)(formatInfo + 0x14) & 7),
                                 scratchUint22);
          if (scratchFlag39) {
            scratchPtr13 = (int *)((int (*)())gld_emitRenderTargetPacket)(scratchPtr13,scratchStack214,scratchUint28,scratchUint23,0,0,
                                          scratchUint22 << 0x10 | (scratchInt33 << (scratchStack218 & 0x3f)) >> scratchInt11)
            ;
          }
          *scratchPtr12 = ((unsigned char *)0x00001393U);
          scratchPtr12[1] = 10;
          scratchPtr12[2] = 0x5c8;
          scratchPtr12[3] = 0x20000;
          scratchPtr12[4] = ((unsigned char *)0x00001040U);
          scratchPtr12[5] = 0;
          if (scratchFlag39) {
            *scratchPtr13 = 0xd0b;
            scratchPtr13[1] = 5;
            scratchPtr13[2] = 0x5c8;
            scratchPtr13[3] = 0x10000;
            scratchPtr24 = scratchPtr13 + 5;
            scratchPtr13[4] = (int)((unsigned char *)0x00001040U);
            scratchPtr13 = scratchPtr13 + 6;
            *scratchPtr24 = 0;
          }
          *(uint *)(texture[0xd] + 0x18) = scratchUint23 * scratchUint22;
          *(byte *)(texture[0xd] + 0x14) = *(byte *)(texture[0xd] + 0x14) | 2;
          *scratchPtr34 = (int)scratchPtr13 - (int)scratchPtr14 >> 2;
          scratchPtr34[2] = ((int)scratchPtr12 + (0x18 - (int)scratchPtr14) >> 2) - scratchPtr34[1];
        }
        scratchUint6 = (ushort)(1 << (scratchUint30 & 0x3f));
        scratchUint27 = ~scratchUint6;
        *(byte *)(texture[0xd] + 0x14) = *(byte *)(texture[0xd] + 0x14) | 1;
        *(ushort *)(texture[0xd] + 0x1c) = scratchUint6 | *(ushort *)(texture[0xd] + 0x1c);
        *(ushort *)(texture[0xd] + 0x28) = scratchUint27 & *(ushort *)(texture[0xd] + 0x28);
        *(byte *)(texture[0xd] + 0x17) = scratchFlag41;
        *(undefined1 *)(texture[0xd] + 0x34) = 1;
        *(undefined1 *)(texture[0xd] + 0x35) = 1;
      }
      *(byte *)((int)texture + 0x39) = *(byte *)((int)texture + 0x39) & 0xf8;
      *(ushort *)(texture + 9) = scratchUint27 & *(ushort *)(texture + 9);
    }
    else {
LAB_00034128:
      if (*(char *)((int)texImages + 0x6d) == '\0') {
        scratchInt11 = ((int (*)())gldTextureHasNonPowerOfTwoSize)(texture,scratchUint16,scratchArg3,staleArgR6,scratchUint19,scratchArg6);
        if (scratchInt11 == 0) {
          scratchStack74 = texture[0xc];
          scratchStack78 = (uint)*(byte *)(scratchStack74 + 0x6c);
          scratchStack7c = (uint)*(byte *)(scratchStack74 + 0x69);
          scratchStack80 = (uint)*(byte *)(scratchStack74 + 0x6b);
          scratchUint27 = *(ushort *)(scratchStack74 + 2);
          scratchStack134 = 0;
          if (0x1908 < scratchUint27) {
            scratchStack134 = 0;
            if (0x190a < scratchUint27) {
              scratchStack134 = 0;
              if (scratchUint27 != 0x8049) goto LAB_00032e78;
              scratchStack134 = 0x4000;
            }
            scratchStack134 = scratchStack134 | 0x2000;
          }
LAB_00032e78:
          scratchStack64 = &scratchStack158;
          scratchStack138 = 2;
          ((int (*)())gldTextureFormatLookup)((uint)*(byte *)(texture + 0xe),texture,scratchStack64,&scratchStack214,&scratchStack208,
                       &scratchStack204,&scratchStack218,&scratchStack210,&scratchStack20c);
          scratchInt11 = (uint)*(byte *)(texture + 0xe) * 0x24;
          formatInfo = &DAT_001d9f34 + scratchInt11;
          scratchUint22 = *(uint *)(&DAT_001d9f48 + scratchInt11) & 7;
          if (scratchUint22 == 4) {
            scratchInt25 = 0;
            scratchFlag39 = false;
            scratchStacka4 = 0;
            scratchStackc0 = 5;
            scratchStack60 = (uint)(xerSummaryOverflow & 1 | 2) << 0x1c | (uint)(crField1 & 0xf) << 0x18 |
                       (uint)(calleeSavedCrField2 & 0xf) << 0x14 | (uint)(calleeSavedCrField3 & 0xf) << 0x10 |
                       (uint)(calleeSavedCrField4 & 0xf) << 0xc | (uint)(crField5 & 0xf) << 8 |
                       (uint)(scratchFlag41 & 0xf) << 4 |
                       (uint)(byte)((scratchUint22 < 4) << 3 | (4 < scratchUint22) << 2 | (scratchUint22 == 4) << 1 |
                                   xerSummaryOverflow & 1);
LAB_00032f74:
            scratchInt11 = 0;
          }
          else {
            scratchStacka4 = *(uint *)(&DAT_001d9f4c + scratchInt11) >> 0x1c & 3;
            scratchFlag42 = (scratchStacka4 != 0) << 2 | (scratchStacka4 == 0) << 1 | xerSummaryOverflow & 1;
            scratchFlag39 = scratchStacka4 != 0;
            if (scratchFlag39) {
              scratchStackc0 = 5 - scratchStacka4;
              scratchStack60 = (uint)(xerSummaryOverflow & 1 | 4) << 0x1c | (uint)(crField1 & 0xf) << 0x18 |
                         (uint)(calleeSavedCrField2 & 0xf) << 0x14 | (uint)(calleeSavedCrField3 & 0xf) << 0x10 |
                         (uint)(calleeSavedCrField4 & 0xf) << 0xc | (uint)(crField5 & 0xf) << 8 |
                         (uint)(scratchFlag41 & 0xf) << 4 | (uint)scratchFlag42;
            }
            else {
              scratchStackc0 = 5;
              scratchStack60 = (uint)(xerSummaryOverflow & 1 | 4) << 0x1c | (uint)(crField1 & 0xf) << 0x18 |
                         (uint)(calleeSavedCrField2 & 0xf) << 0x14 | (uint)(calleeSavedCrField3 & 0xf) << 0x10 |
                         (uint)(calleeSavedCrField4 & 0xf) << 0xc | (uint)(crField5 & 0xf) << 8 |
                         (uint)(scratchFlag41 & 0xf) << 4 | (uint)scratchFlag42;
            }
            scratchInt25 = 1;
            scratchFlag39 = !scratchFlag39;
            if (((*(uint *)(&DAT_001d9f4c + scratchInt11) & 0x30000000) != 0x20000000) ||
               (scratchInt11 = 1, scratchUint22 != 1)) goto LAB_00032f74;
          }
          scratchUint28 = *(byte *)(scratchStack74 + 0x62) - scratchStack7c;
          scratchUint22 = scratchUint28;
          if ((int)scratchUint28 < 0) {
            scratchUint22 = 0;
          }
          scratchInt33 = *(byte *)(scratchStack74 + 0x60) - scratchStack7c;
          if (scratchInt33 < 0) {
            scratchInt33 = 0;
          }
          scratchUint32 = scratchInt33 - scratchStack208;
          if ((int)scratchUint32 < 0) {
            scratchUint32 = 0;
          }
          scratchInt33 = *(byte *)(scratchStack74 + 0x61) - scratchStack7c;
          if (scratchInt33 < 0) {
            scratchInt33 = 0;
          }
          scratchUint30 = scratchInt33 - scratchStack204;
          if ((int)scratchUint30 < 0) {
            scratchUint30 = 0;
          }
          scratchFlag42 = (scratchStack80 < scratchStack7c) << 3 | (scratchStack7c < scratchStack80) << 2 |
                   (scratchStack80 == scratchStack7c) << 1 | xerSummaryOverflow & 1;
          scratchFlag40 = (uint)((1 << (scratchUint32 & 0x3f)) << (scratchStack214 & 0x3f)) <=
                   *(uint *)(ctxSaved + 0x29d8);
          scratchUint20 = scratchStack7c;
          scratchStacka0 = scratchUint22;
          scratchStack9c = scratchUint30;
          scratchStack98 = scratchUint32;
          if (scratchStack80 < scratchStack7c) {
            scratchInt29 = 0;
            scratchInt35 = 0;
            scratchInt21 = 0;
            scratchInt33 = 0;
            scratchStack88 = 0;
          }
          else {
            scratchInt29 = 0;
            scratchInt35 = 0;
            scratchInt33 = scratchStacka4 + 3;
            scratchUint23 = scratchStackc0 + 3;
            scratchPtr14 = scratchStackArr1c8 + scratchStack7c;
            scratchPtr34 = scratchStackArr200 + scratchStack7c;
            scratchStack88 = 0;
            do {
              scratchUint36 = scratchStack214 + scratchUint32;
              *scratchPtr34 = scratchInt35;
              *scratchPtr14 = scratchInt29;
              scratchInt21 = 1 << (scratchUint22 & 0x3f);
              scratchUint8 = scratchUint36;
              if ((int)scratchUint36 < 5) {
                scratchUint8 = 5;
              }
              scratchInt35 = scratchInt35 + scratchInt21 * (1 << (scratchUint8 & 0x3f)) * (1 << (scratchUint30 & 0x3f));
              scratchUint8 = scratchStackc0;
              if ((int)scratchStackc0 < (int)scratchUint36) {
                scratchUint8 = scratchUint36;
              }
              scratchUint36 = 1 << (scratchUint8 & 0x3f);
              scratchUint8 = scratchUint30;
              if ((int)scratchUint30 < (int)scratchStacka4) {
                scratchUint8 = scratchStacka4;
              }
              scratchUint8 = 1 << (scratchUint8 & 0x3f);
              scratchInt29 = scratchInt29 + scratchInt21 * scratchUint36 * scratchUint8;
              if ((scratchUint36 < (uint)(1 << (scratchUint23 & 0x3f))) || (scratchUint8 < (uint)(1 << scratchInt33))) {
                scratchStack88 = scratchStack88 & ~(1 << (scratchUint20 & 0x3f));
              }
              else {
                scratchStack88 = scratchStack88 | 1 << (scratchUint20 & 0x3f);
              }
              if (0 < (int)scratchUint32) {
                scratchUint32 = scratchUint32 - 1;
              }
              if (0 < (int)scratchUint30) {
                scratchUint30 = scratchUint30 - 1;
              }
              if (0 < (int)scratchUint22) {
                scratchUint22 = scratchUint22 - 1;
              }
              scratchUint20 = scratchUint20 + 1;
              scratchPtr34 = scratchPtr34 + 1;
              scratchPtr14 = scratchPtr14 + 1;
              scratchFlag42 = (scratchStack80 < scratchUint20) << 3 | (scratchUint20 < scratchStack80) << 2 |
                       (scratchStack80 == scratchUint20) << 1 | xerSummaryOverflow & 1;
            } while (scratchStack80 >= scratchUint20);
            scratchInt21 = scratchStack78 * scratchInt35;
            scratchInt33 = scratchStack78 * scratchInt29;
          }
          scratchUint22 = 0;
          scratchStack6c = (uint)(byte)(scratchFlag40 << 2 | !scratchFlag40 << 1 | xerSummaryOverflow & 1) << 0x1c |
                     (uint)(crField1 & 0xf) << 0x18 | (uint)(calleeSavedCrField2 & 0xf) << 0x14 |
                     (uint)(calleeSavedCrField3 & 0xf) << 0x10 | (uint)(calleeSavedCrField4 & 0xf) << 0xc |
                     (uint)(crField5 & 0xf) << 8 | (uint)(scratchFlag41 & 0xf) << 4 | (uint)scratchFlag42;
          scratchStackArr1c8[scratchUint20] = scratchInt29;
          scratchStackArr200[scratchUint20] = scratchInt35;
          if (scratchFlag40) {
            scratchUint22 = 0x15;
            if (scratchStack7c <= scratchStack80) {
              scratchInt29 = 0;
              scratchUint22 = scratchUint28;
              scratchUint32 = scratchStack7c;
              do {
                scratchUint30 = scratchUint22;
                if ((int)scratchUint22 < 0) {
                  scratchUint30 = 0;
                }
                scratchUint32 = scratchUint32 + 1;
                scratchUint22 = scratchUint22 - 1;
                scratchInt29 = scratchInt29 + (scratchStack78 * 0x12 << (scratchUint30 & 0x3f));
              } while (scratchUint32 <= scratchStack80);
              scratchUint22 = scratchInt29 + 0x15;
            }
            scratchUint22 = scratchUint22 & 0xfffffff8;
          }
          scratchUint32 = 0x98;
          if (scratchStack7c <= scratchStack80) {
            scratchInt29 = 0x91;
            scratchUint32 = scratchStack7c;
            do {
              scratchUint30 = scratchUint28;
              if ((int)scratchUint28 < 0) {
                scratchUint30 = 0;
              }
              scratchUint32 = scratchUint32 + 1;
              scratchUint28 = scratchUint28 - 1;
              scratchInt29 = scratchInt29 + (scratchStack78 * 0x2a << (scratchUint30 & 0x3f));
            } while (scratchUint32 <= scratchStack80);
            scratchUint32 = scratchInt29 + 7;
          }
          gld_ensureTextureBackingSized2Result = gld_ensureTextureBackingSized2(ctxSaved,texture,
                                scratchInt21 + scratchUint22 * 4 + (scratchUint32 & 0xfffffff8) * 4,scratchInt33);
          if (gld_ensureTextureBackingSized2Result == 0) {
            return 0;
          }
          *(byte *)(texture[0xd] + 0x15) = (byte)((scratchInt25 << scratchInt11) << 3) & 0x18 | 4;
          scratchStack84 = (int *)*texture;
          if ((*(byte *)((int)texture + 0x39) & 3) == 0) {
            scratchStack8c = (int *)0x0;
            scratchStacke8 = (int *)0x0;
          }
          else {
            *(char *)(texture[0xd] + 0x17) = (char)scratchStack7c;
            scratchUint30 = 1 << (scratchStack98 & 0x3f);
            *(char *)(texture[0xd] + 0x34) = (char)scratchStack78;
            *(char *)(texture[0xd] + 0x35) = ((char)scratchStack80 - (char)scratchStack7c) + '\x01';
            scratchUint28 = scratchStack84[8];
            scratchStack84[2] = 0;
            scratchStack84[1] = scratchUint22;
            *scratchStack84 = 0;
            scratchStack84[8] = (uint)scratchFlag40 << 0x1f | scratchUint28 & 0x6fffffff | 0x40000000;
            *(char *)((int)scratchStack84 + 0x1a) = (char)scratchStack214;
            *(short *)((int)scratchStack84 + 0x16) = (short)(1 << (scratchStack9c & 0x3f));
            *(short *)(scratchStack84 + 6) = (short)(1 << (scratchStacka0 & 0x3f));
            *(short *)(scratchStack84 + 5) = (short)scratchUint30;
            *(char *)((int)scratchStack84 + 0x1b) = (char)scratchStack20c;
            scratchUint30 = (scratchUint30 & 0xffff) << (scratchStack214 & 0x3f);
            scratchStack84[3] = scratchUint30;
            if (scratchUint30 >> (scratchStackc0 & 0x3f) == 0) {
              scratchStack84[3] = 1 << (scratchStackc0 & 0x3f);
            }
            scratchUint30 = (uint)*(ushort *)(scratchStack84 + 5) << (scratchStack214 & 0x3f);
            scratchStack84[4] = scratchUint30;
            if (scratchUint30 >> 5 == 0) {
              scratchStack84[4] = 0x20;
            }
            formatInfo = PTR_DAT_001e899c;
            scratchStack84[8] = (uint)scratchFlag40 << 0x1f | scratchUint28 & 0x4fffffff | 0x40000000;
            scratchStack8c = scratchStack84 + 0x280;
            scratchPtr14 = scratchStack8c + scratchStack84[1];
            scratchStacke8 = scratchPtr14 + 0x8f;
            _memcpy(scratchPtr14,formatInfo,0x23c);
            scratchInt25 = (uint)*(byte *)(texture + 0xe) * 0x24;
            formatInfo = &DAT_001d9f34 + scratchInt25;
            if ((*(uint *)(&DAT_001d9f4c + scratchInt25) & 0x10000) == 0) {
              if ((*(uint *)(&DAT_001d9f48 + scratchInt25) & 8) == 0) {
                scratchUint28 = *(uint *)(&DAT_001d9f48 + scratchInt25) & 7;
                if (scratchUint28 == 1) {
                  formatInfo = &DAT_001da00c;
                }
                else if (scratchUint28 < 2) {
                  if (scratchUint28 == 0) {
                    formatInfo = &DAT_001d9fa0;
                  }
                  else {
LAB_000333f4:
                    formatInfo = &DAT_001da1bc;
                  }
                }
                else {
                  if (scratchUint28 == 2) goto LAB_000334dc;
                  if (scratchUint28 != 3) goto LAB_000333f4;
                  formatInfo = &DAT_001da36c;
                }
              }
              else {
LAB_000334dc:
                formatInfo = &DAT_001da054;
              }
            }
            scratchUint8 = scratchPtr14[0x66];
            scratchUint36 = scratchPtr14[0x7c];
            scratchPtr14[0xb] = 0;
            scratchUint28 = *(uint *)(formatInfo + 0x18) >> 5 & 0x1f;
            scratchPtr14[0x66] = scratchUint28 | scratchUint8 & 0xffffffe0;
            scratchUint30 = (*(uint *)(formatInfo + 0x18) & 0x18) << 5;
            scratchPtr14[0x66] = scratchUint30 | scratchUint28 | scratchUint8 & 0xfffffce0;
            scratchUint20 = (*(uint *)(formatInfo + 0x18) & 6) << 9;
            scratchPtr14[0x66] = scratchUint20 | scratchUint30 | scratchUint28 | scratchUint8 & 0xfffff0e0;
            scratchUint23 = *(uint *)(formatInfo + 0x1c) >> 0x12 & 0x3000;
            scratchPtr14[0x66] = scratchUint23 | scratchUint20 | scratchUint30 | scratchUint28 | scratchUint8 & 0xffffc0e0;
            scratchPtr14[0x66] =
                 *(uint *)(formatInfo + 0x1c) >> 0xe & 0xc000 |
                 scratchUint23 | scratchUint20 | scratchUint30 | scratchUint28 | scratchUint8 & 0xfff000e0;
            scratchUint28 = *(uint *)(formatInfo + 0x1c) >> 7 & 0x1f;
            scratchPtr14[0x7c] = scratchUint28 | scratchUint36 & 0xfffffe00;
            scratchUint30 = (*(uint *)(formatInfo + 0x1c) & 0x70) << 5;
            scratchPtr14[0x7c] = scratchUint30 | scratchUint28 | scratchUint36 & 0xfffff000;
            scratchUint20 = (*(uint *)(formatInfo + 0x1c) & 0xe) << 0xb;
            scratchPtr14[0x7c] = scratchUint20 | scratchUint30 | scratchUint28 | scratchUint36 & 0xffff8000;
            scratchUint23 = *(uint *)(formatInfo + 0x20) >> 0xe & 0x38000;
            scratchPtr14[0x7c] = scratchUint23 | scratchUint20 | scratchUint30 | scratchUint28 | scratchUint36 & 0xfffc0000;
            scratchUint8 = *(uint *)(formatInfo + 0x20) >> 8 & 0x1c0000;
            scratchPtr14[0x7c] = scratchUint8 | scratchUint23 | scratchUint20 | scratchUint30 | scratchUint28 | scratchUint36 & 0xffc00000;
            scratchPtr14[0x7c] =
                 (*(uint *)(formatInfo + 0x20) >> 0x19 & 1) << 0x16 |
                 scratchUint8 | scratchUint23 | scratchUint20 | scratchUint30 | scratchUint28 | scratchUint36 & 0xf8000000;
            if (!(bool)((byte)(scratchStack6c >> 0x1d) & 1)) {
              *scratchStack8c = (int)((unsigned char *)0x00001393U);
              scratchStack8c[1] = 10;
              scratchStack8c[2] = 0x5c8;
              scratchPtr14 = scratchStack8c + 5;
              scratchStack8c[3] = 0x20000;
              scratchStack8c[4] = 0x575;
              scratchStack8c = scratchStack8c + 6;
              *scratchPtr14 = scratchStack20c;
            }
          }
          scratchFlag42 = ((int)scratchStack78 < 0) << 3 | (0 < (int)scratchStack78) << 2 | (scratchStack78 == 0) << 1 |
                   xerSummaryOverflow & 1;
          if (scratchStack78 != 0) {
            scratchStack90 = 0;
            scratchStackdc = texture;
            scratchStack58 = scratchInt11 << 1;
            scratchStack94 = 0;
            scratchStacke4 = scratchStack7c * 0x18;
            scratchStack54 = (uint)(byte)(scratchFlag39 << 2 | !scratchFlag39 << 1 | xerSummaryOverflow & 1) << 0x1c |
                       (uint)(crField1 & 0xf) << 0x18 | (uint)(calleeSavedCrField2 & 0xf) << 0x14 |
                       (uint)(calleeSavedCrField3 & 0xf) << 0x10 | (uint)(calleeSavedCrField4 & 0xf) << 0xc |
                       (uint)(crField5 & 0xf) << 8 | (uint)(scratchFlag41 & 0xf) << 4 | (uint)scratchFlag42;
            scratchStackc4 = (scratchUint22 + (scratchUint32 & 0xfffffff8)) * 4;
            scratchStacke0 = scratchStack7c << 5;
            scratchStack68 = (uint)(xerSummaryOverflow & 1 | 2) << 0x1c | (uint)(crField1 & 0xf) << 0x18 |
                       (uint)(calleeSavedCrField2 & 0xf) << 0x14 | (uint)(calleeSavedCrField3 & 0xf) << 0x10 |
                       (uint)(calleeSavedCrField4 & 0xf) << 0xc | (uint)(crField5 & 0xf) << 8 |
                       (uint)(scratchFlag41 & 0xf) << 4 | (uint)scratchFlag42;
            scratchStack5c = scratchStack84 + 0x10;
            scratchStackd8 = scratchStack74;
            do {
              scratchStacka8 = (uint)*(ushort *)(scratchStackd8 + 0x7c);
              if (scratchStack7c <= scratchStack80) {
                scratchPtr14 = scratchStackArr200 + scratchStack7c;
                scratchStackc8 = scratchStacke0;
                scratchStackd0 = scratchStacke0;
                scratchStackd4 = scratchStackArr1c8 + scratchStack7c;
                scratchStack70 = 0x80e1;
                scratchStackcc = scratchStacke4;
                scratchUint22 = scratchStack98;
                scratchUint28 = scratchStacka0;
                scratchUint32 = scratchStack9c;
                scratchUint30 = scratchStack7c;
                do {
                  scratchUint23 = scratchUint22 + scratchStack214;
                  scratchUint20 = scratchUint23;
                  if ((int)scratchUint23 < 5) {
                    scratchUint20 = 5;
                  }
                  scratchInt11 = 1 << (scratchUint20 & 0x3f);
                  scratchStackb0 = 1;
                  scratchFlag39 = 3 < *(byte *)(texture + 0xe) - 0xc;
                  scratchStackac = *scratchPtr14 * scratchStack78 + scratchStack94 * (scratchPtr14[1] - *scratchPtr14) + scratchStackc4 +
                             0xa00;
                  if (scratchFlag39) {
                    scratchStackb0 = 0;
                  }
                  scratchStackb0 = (uint)!scratchFlag39;
                  if ((*(byte *)((int)texture + 0x39) & 3) == 0) {
                    scratchFlag42 = ((int)scratchUint28 < 0) << 3 | (0 < (int)scratchUint28) << 2 | (scratchUint28 == 0) << 1 |
                             xerSummaryOverflow & 1;
                    scratchStacka8 = scratchStacka8 & *(ushort *)(scratchStackdc + 9);
                  }
                  else {
                    scratchFlag42 = ((int)scratchUint28 < 0) << 3 | (0 < (int)scratchUint28) << 2 | (scratchUint28 == 0) << 1 |
                             xerSummaryOverflow & 1;
                    scratchUint8 = scratchUint28;
                    scratchUint20 = scratchUint32;
                    if ((((scratchUint32 != scratchStacka4 + 3) && (scratchStacka4 <= scratchUint32)) &&
                        (scratchFlag42 = ((int)scratchUint28 < 0) << 3 | (0 < (int)scratchUint28) << 2 |
                                  (scratchUint28 == 0) << 1 | xerSummaryOverflow & 1, scratchUint28 != 0)) &&
                       (scratchUint36 = scratchUint28, scratchUint32 < 0xb)) {
                      do {
                        scratchUint8 = scratchUint8 - 1;
                        scratchUint20 = scratchUint20 + 1;
                        if (scratchUint36 - 1 == 0) goto LAB_00033700;
                        scratchUint36 = scratchUint36 - 1;
                      } while (scratchUint20 != 0xb);
                      scratchUint20 = 0xb;
                    }
LAB_00033700:
                    if ((int)scratchUint23 < (int)scratchStackc0) {
                      scratchUint23 = scratchStackc0;
                    }
                    scratchInt29 = 1 << (scratchUint23 & 0x3f);
                    *(short *)(scratchStackd0 + (int)scratchStack5c) =
                         (short)((int)scratchStack8c - (int)(scratchStack84 + 0x280) >> 2);
                    scratchInt25 = scratchStack84[1];
                    *(int *)((int)scratchStack5c + scratchStackd0 + 4) = scratchStackac;
                    *(short *)((int)scratchStack5c + scratchStackd0 + 0x18) =
                         (short)((int)scratchStacke8 - (int)(scratchStack84 + 0x280) >> 2) - (short)scratchInt25;
                    scratchInt33 = *scratchStackd4;
                    scratchInt25 = scratchStackd4[1];
                    *(short *)((int)scratchStack5c + scratchStackd0 + 2) = (short)(1 << (scratchUint8 & 0x3f));
                    *(int *)((int)scratchStack5c + scratchStackd0 + 0xc) = scratchInt11 << (scratchUint20 & 0x3f);
                    *(uint *)((int)scratchStack5c + scratchStackd0 + 8) =
                         scratchStack78 * scratchInt33 + scratchStack94 * (scratchInt25 - scratchInt33);
                    scratchUint23 = scratchUint20;
                    if ((int)scratchUint20 < (int)scratchStacka4) {
                      scratchUint23 = scratchStacka4;
                    }
                    *(int *)((int)scratchStack5c + scratchStackd0 + 0x10) = (1 << (scratchUint23 & 0x3f)) * scratchInt29;
                    scratchUint23 = scratchUint32;
                    if ((int)scratchUint32 < (int)scratchStacka4) {
                      scratchUint23 = scratchStacka4;
                    }
                    *(int *)((int)scratchStack5c + scratchStackd0 + 0x14) = scratchInt29 << (scratchUint23 & 0x3f);
                    *(int *)((int)scratchStack5c + scratchStackd0 + 0x1c) = (int)scratchStack84 + scratchStackac;
                    if ((scratchStack210 < 3) ||
                       ((scratchInt25 = 1, 4 < scratchStack210 && (scratchInt25 = 2, scratchStack210 != 6)))) {
                      scratchInt25 = 0;
                    }
                    scratchUint23 = 1 << (scratchUint8 & 0x3f);
                    if (scratchUint23 != 0) {
                      scratchInt33 = 1 << (scratchUint20 & 0x3f);
                      scratchInt35 = 1 << (scratchUint22 & 0x3f);
                      scratchUint8 = 0;
                      scratchUint20 = scratchStack88 >> (scratchUint30 & 0x3f);
                      do {
                        if (((bool)((byte)(scratchStack60 >> 0x1d) & 1)) ||
                           (!(bool)((byte)(scratchStack54 >> 0x1d) & 1))) {
                          scratchUint36 = 0;
                        }
                        else {
                          scratchUint36 = 1;
                        }
                        scratchUint36 = (scratchUint36 | scratchStack58) << 1 | scratchUint20 & 1;
                        scratchStacke8 = (int *)((int (*)())gld_buildTextureStatePacket)(scratchStacke8,formatInfo,scratchInt11,scratchInt29,scratchUint36,
                                                       (scratchInt35 << (scratchStack214 & 0x3f)) >>
                                                       (*(uint *)(formatInfo + 0x14) & 7),scratchInt33);
                        if (!(bool)((byte)(scratchStack6c >> 0x1d) & 1)) {
                          scratchStack8c = (int *)((int (*)())gld_emitRenderTargetPacket)(scratchStack8c,scratchStack210,scratchInt11,scratchInt29,scratchUint36,0,
                                                         scratchInt33 << 0x10 |
                                                         (scratchInt35 << (scratchStack214 & 0x3f)) >> scratchInt25);
                        }
                        scratchUint8 = scratchUint8 + 1;
                      } while (scratchUint8 < scratchUint23);
                    }
                  }
                  if ((scratchStacka8 >> (scratchUint30 & 0x3f) & 1) != 0) {
                    scratchInt33 = scratchStackcc + scratchStack74 + 0xa0;
                    scratchUint20 = (uint)*(ushort *)(scratchInt33 + 0x12);
                    scratchInt25 = gldPixelUnitBytes((uint)*(ushort *)(scratchInt33 + 0x10),scratchUint20);
                    scratchUint23 = (uint)*(ushort *)(scratchInt33 + 0xc);
                    scratchFlag39 = scratchUint20 != 0;
                    scratchFlag4 = xerSummaryOverflow & 1;
                    scratchStack158 = *(uint *)(scratchInt33 + 0x14);
                    scratchUint8 = scratchInt25 * scratchUint23;
                    if ((*(char *)(scratchInt33 + 10) != '\0') && (scratchFlag39)) {
                      scratchInt29 = 1;
                      if ((*(char *)(scratchStack74 + 0x6e) != '\0') &&
                         (scratchInt29 = scratchUint23 + 1, *(char *)(scratchStack74 + 0x6f) != '\0')) {
                        scratchInt29 = scratchInt29 + scratchUint23 * *(ushort *)(scratchInt33 + 0xe);
                      }
                      scratchStack158 = scratchStack158 + scratchInt25 * scratchInt29;
                    }
                    scratchUint23 = *(byte *)(scratchStack74 + 0x60) - scratchUint30;
                    if ((int)scratchUint23 < 0) {
                      scratchUint23 = 0;
                    }
                    scratchStack12c = 1 << (scratchUint23 & 0x3f);
                    scratchInt25 = *(byte *)(scratchStack74 + 0x61) - scratchUint30;
                    if (scratchInt25 < 0) {
                      scratchInt25 = 0;
                    }
                    scratchInt29 = *(byte *)(scratchStack74 + 0x62) - scratchUint30;
                    if (scratchInt29 < 0) {
                      scratchInt29 = 0;
                    }
                    scratchStack128 = 1 << (scratchInt25 + scratchInt29 & 0x3fU);
                    scratchPtr18 = scratchStackArr14c;
                    scratchFlag40 = (int)scratchStackb0 < 0;
                    scratchFlag1 = 0 < (int)scratchStackb0;
                    scratchFlag2 = scratchStackb0 == 0;
                    scratchFlag3 = xerSummaryOverflow & 1;
                    scratchUint23 = scratchStackb0;
                    scratchStack154 = scratchUint8;
                    _glgConvertType((uint)*(ushort *)(scratchInt33 + 0x10),
                                    (uint)*(ushort *)(scratchInt33 + 0x12),scratchStackArr150,scratchPtr18,scratchStack74,
                                    scratchStackb0,scratchStack158,scratchUint8);
                    scratchStack144 = scratchInt11;
                    if (!scratchFlag2) {
                      scratchStack144 = scratchStack12c << 2;
                    }
                    scratchStack148 = scratchStackac + *texture;
                    scratchStack130 = 0x7ffff;
                    scratchUint27 = *(short *)(scratchInt33 + 0x10) + 0xe6fa;
                    scratchFlag43 = (scratchUint27 < 4) << 3 | (4 < scratchUint27) << 2 | (scratchUint27 == 4) << 1 |
                             xerSummaryOverflow & 1;
                    if ((4 >= scratchUint27) &&
                       (scratchUint23 = 1 << ((int)(short)scratchUint27 & 0x3fU) & 0x19, scratchUint23 != 0)) {
                      scratchStack130 = 0x7dfff;
                    }
                    scratchStack120 = 0;
                    scratchStack124 = 0;
                    scratchUint36 = scratchStack148;
                    if (((scratchFlag39) && (!scratchFlag2)) &&
                       (scratchUint36 = scratchStack68, (bool)((byte)(scratchStack68 >> 0x1d) & 1))) {
                      scratchUint23 = 1;
                      scratchStack90 = _valloc(((1 << (*(byte *)(scratchStack74 + 100) + 2 & 0x3f)) + 0x1fU &
                                         0xffffffe0) <<
                                         ((uint)*(byte *)(scratchStack74 + 0x66) +
                                          (uint)*(byte *)(scratchStack74 + 0x65) & 0x3f));
                      scratchUint36 = scratchStack68;
                      scratchStack68 = (uint)(byte)(((int)scratchStack90 < 0) << 3 | (0 < (int)scratchStack90) << 2 |
                                              (scratchStack90 == 0) << 1 | xerSummaryOverflow & 1) << 0x1c |
                                 (uint)(crField1 & 0xf) << 0x18 | (uint)scratchFlag42 << 0x14 |
                                 (uint)(byte)((scratchUint20 == 0) << 2 | scratchFlag39 << 1 | scratchFlag4) << 0x10 |
                                 (uint)(byte)(scratchFlag40 << 3 | scratchFlag1 << 2 | scratchFlag2 << 1 | scratchFlag3) << 0xc
                                 | (uint)(crField5 & 0xf) << 8 | (uint)(scratchFlag41 & 0xf) << 4 |
                                 (uint)(scratchFlag43 & 0xf);
                    }
                    scratchUint27 = *(ushort *)(scratchInt33 + 0x10);
                    scratchUint6 = *(ushort *)(scratchInt33 + 0x12);
                    scratchUint15 = (uint)*(byte *)(texture + 0xe);
                    scratchInt25 = 1 << (scratchUint28 + scratchUint22 + scratchUint32 + scratchStack214 & 0x3f);
                    scratchUint20 = ((int (*)())gldTextureFormatCodeMatchesType)((uint)scratchUint27,(uint)scratchUint6,scratchUint15);
                    scratchInt11 = gldPixelUnitBytes((uint)scratchUint27,(uint)scratchUint6);
                    scratchUint20 = scratchStack154 == scratchInt11 * scratchStack12c & scratchUint20;
                    if (((scratchUint20 == 0) || (scratchUint23 = scratchStack158 & 0x1f, scratchUint23 != 0)) ||
                       (scratchUint36 = scratchStack154 & 0x1f, scratchUint36 != 0)) {
                      if (scratchFlag39) {
                        if (scratchFlag2) {
                          _glgProcessPixels(0,scratchStack64,scratchUint15,scratchPtr18,scratchUint20,scratchUint23,scratchUint36,scratchUint8);
                        }
                        else {
                          scratchUint23 = (uint)*(ushort *)(scratchInt33 + 0x10);
                          scratchStackb4 = scratchStack148;
                          if (((scratchStack12c != *(ushort *)(scratchInt33 + 0xc)) ||
                              ((*(short *)(scratchInt33 + 0x12) != 0x1401 &&
                               (*(short *)(scratchInt33 + 0x12) != -0x7fcb)))) ||
                             ((scratchUint15 = scratchStack158, 1 < scratchUint23 - 0x1907 &&
                              ((scratchUint23 != scratchStack70 && (scratchUint20 = scratchStack70, scratchUint23 != 0x80e0)))))) {
                            scratchStack148 = scratchStack90;
                            _glgProcessPixels(0,scratchStack64,scratchUint23,scratchPtr18,scratchUint20,scratchStack90,scratchUint36,scratchUint8
                                             );
                            scratchUint23 = 0x1908;
                            scratchStack148 = scratchStackb4;
                            scratchUint15 = scratchStack90;
                          }
                          scratchUint20 = scratchStack12c;
                          scratchPtr18 = (undefined1 *)(uint)*(byte *)(texture + 0xe);
                          scratchStack148 = scratchStackb4;
                          if (scratchPtr18 == (undefined1 *)((int)((unsigned char *)0xc) + 3)) {
                            scratchFlag39 = scratchUint23 == 0x1908;
                            scratchFlag41 = (scratchUint23 < 0x1908) << 3 | (0x1908 < scratchUint23) << 2 | scratchFlag39 << 1 |
                                     xerSummaryOverflow & 1;
                            scratchStackb8 = scratchStack128;
                            if ((scratchFlag39) || (scratchInt11 = 3, scratchUint23 == scratchStack70)) {
                              scratchInt11 = 4;
                            }
                            scratchPtr38 = (undefined1 *)(scratchInt11 * scratchStack12c);
                            if ((scratchFlag39) || (scratchStackbc = 0, scratchUint23 == scratchStack70)) {
                              scratchStackbc = 3;
                            }
                            if (0 < (int)scratchStack128) {
                              scratchFlag39 = 0 < (int)scratchStack12c;
                              scratchInt25 = 0;
                              do {
                                if (scratchFlag39) {
                                  scratchInt33 = 0;
                                  scratchInt29 = scratchStackb4 + scratchInt25 * scratchUint20;
                                  do {
                                    scratchInt35 = scratchInt11 * scratchInt33;
                                    scratchInt33 = scratchInt33 + 4;
                                    scratchInt21 = scratchUint15 + scratchInt35 + scratchInt25 * (int)scratchPtr38;
                                    ((int (*)())gld_compressAlphaBlock)(scratchInt29,scratchInt21 + scratchStackbc,scratchInt11,scratchPtr38);
                                    scratchInt35 = scratchInt29 + 8;
                                    scratchInt29 = scratchInt29 + 0x10;
                                    scratchPtr18 = scratchPtr38;
                                    ((int (*)())gld_compressAlphaBlock)(scratchInt35,scratchInt21 + (uint)(1 < scratchUint23 - 0x1907) * 2,
                                                 scratchInt11,scratchPtr38);
                                  } while (scratchInt33 < (int)scratchUint20);
                                }
                                scratchInt25 = scratchInt25 + 4;
                              } while (scratchInt25 < (int)scratchStackb8);
                            }
                          }
                          else {
                            dxtCompressImage(scratchStack12c,scratchStack128,scratchUint23,scratchPtr18,scratchUint15,scratchStackb4);
                          }
                        }
                      }
                      else if (!scratchFlag2) {
                        scratchPtr18 = (undefined1 *)((int)((unsigned char *)0x0) + 1);
                        scratchUint20 = ((int (*)())gldCompressedImageBytes)((uint)*(byte *)(texture + 0xe),scratchStack12c,1,1);
                        if (scratchUint20 < 0x20) {
                          if (scratchStack128 != 0) {
                            scratchUint15 = 0;
                            scratchUint23 = scratchStack158;
                            scratchUint36 = scratchStack148;
                            do {
                              scratchUint15 = scratchUint15 + 4;
                              scratchUint7 = scratchUint36 + 0x1f & 0xffffffe0;
                              scratchUint36 = scratchUint7 + scratchUint20;
                              _memcpy(scratchUint7,scratchUint23,scratchUint20);
                              scratchUint23 = scratchUint23 + scratchUint20;
                            } while (scratchUint15 < scratchStack128);
                          }
                        }
                        else {
                          _memcpy(scratchStack148,scratchStack158,scratchInt25);
                        }
                      }
                    }
                    else {
                      _memcpy(scratchStack148,scratchStack158,scratchInt25);
                    }
                    scratchUint20 = *(uint *)(ctxSaved + 0x24) & 0x82;
                    if (scratchUint20 != 0) {
                      gldFlushDataCacheRange(ctxSaved,scratchStackac + *texture,
                                   (uint)*(ushort *)((int)scratchStack5c + scratchStackc8 + 2) *
                                   *(int *)((int)scratchStack5c + scratchStackc8 + 0xc),scratchPtr18,scratchStackc8,
                                   scratchStack5c,scratchUint20,scratchUint8);
                    }
                  }
                  if (0 < (int)scratchUint22) {
                    scratchUint22 = scratchUint22 - 1;
                  }
                  if (0 < (int)scratchUint32) {
                    scratchUint32 = scratchUint32 - 1;
                  }
                  if ((bool)(scratchFlag42 >> 2 & 1)) {
                    scratchUint28 = scratchUint28 - 1;
                  }
                  scratchUint30 = scratchUint30 + 1;
                  scratchPtr14 = scratchPtr14 + 1;
                  scratchStackc8 = scratchStackc8 + 0x20;
                  scratchStackcc = scratchStackcc + 0x18;
                  scratchStackd0 = scratchStackd0 + 0x20;
                  scratchStackd4 = scratchStackd4 + 1;
                } while (scratchUint30 <= scratchStack80);
              }
              scratchInt11 = scratchStack94 * 2;
              scratchStack94 = scratchStack94 + 1;
              scratchUint27 = ~(ushort)scratchStacka8;
              scratchInt25 = scratchInt11 + texture[0xd];
              scratchStackd8 = scratchStackd8 + 2;
              scratchStacke0 = scratchStacke0 + 0x1a0;
              scratchStacke4 = scratchStacke4 + 0x168;
              *(ushort *)(scratchInt25 + 0x1c) = (ushort)scratchStacka8 | *(ushort *)(scratchInt25 + 0x1c);
              scratchInt11 = scratchInt11 + texture[0xd];
              *(ushort *)(scratchInt11 + 0x28) = scratchUint27 & *(ushort *)(scratchInt11 + 0x28);
              *(ushort *)(scratchStackdc + 9) = scratchUint27 & *(ushort *)(scratchStackdc + 9);
              scratchStackdc = (int *)((int)scratchStackdc + 2);
            } while (scratchStack94 < scratchStack78);
            if (!(bool)((byte)(scratchStack68 >> 0x1d) & 1)) {
              _free(scratchStack90);
            }
          }
          scratchFlag41 = *(byte *)((int)texture + 0x39);
          if ((scratchFlag41 & 3) != 0) {
            *scratchStacke8 = (int)((unsigned char *)0x00001393U);
            scratchStacke8[1] = 10;
            scratchStacke8[2] = 0x5c8;
            scratchStacke8[3] = 0x20000;
            scratchStacke8[4] = (int)((unsigned char *)0x00001040U);
            scratchStacke8[5] = 0;
            if (!(bool)((byte)(scratchStack6c >> 0x1d) & 1)) {
              *scratchStack8c = 0xd0b;
              scratchStack8c[1] = 5;
              scratchStack8c[2] = 0x5c8;
              scratchStack8c[3] = 0x10000;
              scratchPtr14 = scratchStack8c + 5;
              scratchStack8c[4] = (int)((unsigned char *)0x00001040U);
              scratchStack8c = scratchStack8c + 6;
              *scratchPtr14 = 0;
            }
            *scratchStack84 = (int)scratchStack8c - (int)(scratchStack84 + 0x280) >> 2;
            scratchStack84[2] = ((int)scratchStacke8 + (0x18 - (int)(scratchStack84 + 0x280)) >> 2) - scratchStack84[1];
            scratchFlag41 = *(byte *)((int)texture + 0x39);
          }
          *(byte *)((int)texture + 0x39) = scratchFlag41 & 0xf8;
          goto LAB_00033ff0;
        }
        if (*(char *)(texture + 0x11) != '\0') {
          return 0;
        }
      }
      scratchInt11 = ((int (*)())gld_uploadTextureLevel)(ctxSaved,texture);
      if (scratchInt11 == 0) {
        return 0;
      }
    }
  }
  else {
    scratchUint27 = texImages[6];
    if (scratchUint27 == 0x405) {
LAB_000324ac:
      scratchUint16 = 0;
    }
    else if (scratchUint27 < 0x406) {
      if (scratchUint27 == 0x402) goto LAB_000324ac;
      scratchUint16 = 2;
      if ((scratchUint27 != 0x403) && (scratchUint16 = 3, scratchUint27 != 0x401)) {
LAB_00032480:
        scratchUint16 = 1;
      }
    }
    else {
      scratchUint16 = 8;
      if ((scratchUint27 != 0x40a) && (scratchUint16 = 0x11, scratchUint27 != 0x1100)) {
        if (scratchUint27 != 0x409) goto LAB_00032480;
        scratchUint16 = 7;
      }
    }
    gld_ensureTextureSurfaceBackingResult = gld_ensureTextureSurfaceBacking(ctxSaved,texture,*(undefined4 *)(texImages + 4),scratchUint16,
                          (uint)*(byte *)(texImages + 0x36));
    if (gld_ensureTextureSurfaceBackingResult == 0) {
      return 0;
    }
    if (*(char *)((int)texImages + 0x6d) == '\0') {
      scratchUint22 = (uint)texImages[0x52];
      if ((0x20 < scratchUint22) || (0x20 < texImages[0x53])) goto LAB_00032600;
    }
    else {
      scratchUint22 = (uint)texImages[0x52];
    }
    scratchUint28 = 1 << (*(uint *)(&DAT_001d9f48 + (uint)*(byte *)(texture + 0xe) * 0x24) & 7);
    *(short *)((int)texture + 0x3e) =
         (short)((scratchUint28 * (scratchUint22 + (uint)*(byte *)(texImages + 0x55) * -2) + 0xff & 0xffffff00) /
                scratchUint28);
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
      scratchUint27 = texImages[0x52];
      scratchUint22 = scratchUint27 >> 1 & 0x7e00;
      scratchShort5 = (short)scratchUint22;
      *(short *)(texture + 0x35) = scratchShort5;
      *(ushort *)((int)texture + 0xd2) = scratchUint27 - scratchShort5;
      *(short *)(texture + 0x34) = scratchShort5 + 2;
      texture[0x33] = scratchUint22 << 2 | texture[0x33] & 3U;
      goto LAB_00034100;
    }
    if (0x1000 < texImages[0x53]) {
      texture[0x32] = texture[0x32] & 0xff3fffffU | 0x800000;
      scratchUint27 = texImages[0x53];
      scratchUint22 = scratchUint27 >> 1 & 0x7fc0;
      scratchShort5 = (short)scratchUint22;
      *(short *)(texture + 0x35) = scratchShort5;
      *(ushort *)((int)texture + 0xd2) = scratchUint27 - scratchShort5;
      *(short *)(texture + 0x34) = scratchShort5 + 1;
      if ((*(ushort *)texture[0xc] & 0x400) == 0) {
        texture[0x33] =
             ((*(ushort *)((int)texture + 0x3e) * scratchUint22 <<
              (*(uint *)(&DAT_001d9f48 + (uint)*(byte *)(texture + 0xe) * 0x24) & 7)) >> 5) << 2 |
             texture[0x33] & 3U;
      }
      else {
        texture[0x33] = scratchUint22 << 2 | texture[0x33] & 3U;
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
  uint scratchUint12;
  uint scratchUint13;
  uint halfDepth;
  int drawWords;
  int scratchInt16;
  int levelRecord;
  undefined4 *packet;
  undefined4 r4AfterCall;
  int *drawCursor;
  undefined4 scratchUint20;
  int *levelOffsetTable;
  undefined4 staleArgR8;
  uint baseWidth;
  uint *lastHeader;
  uint scratchUint24;
  int scratchInt25;
  int iVar26;
  uint scratchUint27;
  uint baseHeight;
  int storageRecord;
  int scratchInt30;
  int *passOffsetTable;
  uint scratchUint32;
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
  scratchUint20 = 1;
  nextLevel = baseLevel + 1;
  faceArg = face;
  scratchUint12 = baseLevel;
  levelRecord = ((int (*)())gldTextureFormatEntryForLevel)(ctx,texture,face,baseLevel,1);
  if (((levelRecord == 0) || ((*(uint *)(levelRecord + 0x18) & 0x10000) == 0)) ||
     (((*(byte *)((int)texture + 0x39) & 7) != 0 &&
      (faceArg = ((int (*)())gldTextureMakeResident)(ctx,texture,faceArg,scratchUint12,scratchUint20,staleArgR8), faceArg == 0))))
  goto LAB_000342e0;
  baseWidth = *(byte *)(levelTable + 0x30) - baseLevel;
  if ((int)baseWidth < 0) {
    baseWidth = 0;
  }
  baseWidth = 1 << (baseWidth & 0x3f);
  scratchUint27 = *(byte *)((int)levelTable + 0x61) - baseLevel;
  if ((int)scratchUint27 < 0) {
    scratchUint27 = 0;
  }
  baseHeight = 1 << (scratchUint27 & 0x3f);
  scratchUint27 = *(byte *)(levelTable + 0x31) - baseLevel;
  depthLevelCount = scratchUint27;
  if ((int)scratchUint27 < 0) {
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
    scratchUint13 = levelCount;
    if (*(char *)(levelTable + 0x36) != '\x06') {
      drawWords = levelCount * 0x1e;
      levelCountPlus1 = levelCount + 1;
      goto LAB_0003440c;
    }
    levelCountPlus1 = levelCount * 2;
    scratchUint32 = levelCount * 0x10000;
    drawWords = levelCount * 0x2c + -0x16;
    scratchUint24 = levelCount;
  }
  else {
    if ((int)levelCount < 1) {
      scratchUint13 = 0;
      drawWords = 0;
      levelCountPlus1 = 1;
    }
    else {
      scratchUint24 = 0;
      scratchUint13 = 0;
      scratchUint32 = levelCount;
      do {
        sliceCount = (int)halfDepth >> (scratchUint24 & 0x3f);
        if (sliceCount < 1) {
          sliceCount = 1;
        }
        scratchUint13 = scratchUint13 + sliceCount;
        scratchUint24 = scratchUint24 + 1;
        scratchUint32 = scratchUint32 - 1;
      } while (scratchUint32 != 0);
      drawWords = scratchUint13 * 0x28;
      levelCountPlus1 = scratchUint13 + 1;
    }
LAB_0003440c:
    drawWords = drawWords + -0x12;
    scratchUint32 = 0x10000;
    scratchUint24 = 1;
  }
  a0 = ctx + GLD_commandStream;
  a6 = face << 0x10;
  scratchUint20 = (**(code **)(ctx + GLD_streamAllocate))
                     (a0,drawWords + levelCountPlus1 + 0x340,depthLevelCount,scratchUint12,scratchUint20,staleArgR8,a6);
  *(undefined4 *)(ctx + GLD_streamCurrent) = scratchUint20;
  packet = (undefined4 *)((int (*)())FUN_00030840)(ctx,scratchUint20,texture);
  stateTemplate = PTR_DAT_001e88d0;
  lastHeader = *(uint **)(ctx + GLD_lastHeader);
  tailCursor = packet + 4 + scratchUint13;
  *lastHeader = (int)packet - (int)lastHeader >> 2 | *lastHeader;
  *(undefined4 **)(ctx + GLD_lastHeader) = packet;
  packet[2] = levelCount | a6 | nextLevel * 0x100;
  packet[3] = scratchUint13 | scratchUint32;
  *packet = 0x37000000;
  packetState = tailCursor + scratchUint24;
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
  scratchUint12 = packetState[0xa2];
  packetState[0xa2] = scratchUint12 & 0xffff81ff | 0x3400;
  if ((int)scratchUint27 < 1) {
    scratchInt16 = 0;
  }
  else {
    scratchInt16 = 2;
  }
  packetState[0xa2] = scratchInt16 << 0xf | scratchUint12 & 0xfffe01ff | 0x3400;
  scratchUint24 = packetState[0x8a];
  scratchUint13 = packetState[0xa8];
  packetState[0xa4] = packetState[0xa4] & 0xffffe007U | 0x1f00;
  packetState[0xa6] =
       levelCount * 0x4000000 & 0x3c000000 |
       (depthLevelCount & 0xf) << 0x16 |
       (baseHeight - 1) * 0x800 & 0x3ff800 | baseWidth - 1 & 0x7ff | packetState[0xa6] & 0x40000000U;
  levelCount = *(uint *)(levelRecord + 0x1c) >> 7 & 0x1f;
  packetState[0xa8] = levelCount | scratchUint13 & 0xffffffe0;
  scratchUint12 = (*(uint *)(levelRecord + 0x1c) & 0xe) << 0xb;
  packetState[0xa8] = scratchUint12 | levelCount | scratchUint13 & 0xffff8fe0;
  scratchUint27 = *(uint *)(levelRecord + 0x20) >> 0xe & 0x38000;
  packetState[0xa8] = scratchUint27 | scratchUint12 | levelCount | scratchUint13 & 0xfffc0fe0;
  scratchUint32 = *(uint *)(levelRecord + 0x20) >> 8 & 0x1c0000;
  packetState[0xa8] = scratchUint32 | scratchUint27 | scratchUint12 | levelCount | scratchUint13 & 0xffe00fe0;
  packetState[0xa8] =
       (*(uint *)(levelRecord + 0x1c) & 0x70) << 5 |
       scratchUint32 | scratchUint27 | scratchUint12 | levelCount | scratchUint13 & 0xffe001e0;
  levelCount = (*(uint *)(levelRecord + 0x18) & 0x18) << 5;
  packetState[0x8a] = levelCount | scratchUint24 & 0xfffffcff;
  scratchUint12 = (*(uint *)(levelRecord + 0x18) & 6) << 9;
  packetState[0x8a] = scratchUint12 | levelCount | scratchUint24 & 0xfffff0ff;
  scratchUint27 = *(uint *)(levelRecord + 0x1c) >> 0x12 & 0x3000;
  packetState[0x8a] = scratchUint27 | scratchUint12 | levelCount | scratchUint24 & 0xffffc0ff;
  scratchUint32 = *(uint *)(levelRecord + 0x1c) >> 0xe & 0xc000;
  packetState[0x8a] = scratchUint32 | scratchUint27 | scratchUint12 | levelCount | scratchUint24 & 0xffff00ff;
  packetState[0x8a] =
       *(uint *)(levelRecord + 0x18) >> 5 & 0x1f |
       scratchUint32 | scratchUint27 | scratchUint12 | levelCount | scratchUint24 & 0xffff00e0;
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
      scratchInt30 = 0;
    }
    else {
      baseLevel = nextLevel - *(byte *)(texture[0xc] + 0x69);
      if ((*(byte *)(storageRecord + 0x15) & 0x18) == 0) {
        scratchInt25 = 1;
        scratchInt30 = 0x100;
      }
      else {
        scratchInt25 = 1 << (*(uint *)(&DAT_001d9f4c + (uint)*(byte *)(texture + 0xe) * 0x24) >> 0x1c & 3)
        ;
        scratchInt30 = 0x20 / scratchInt25 << 3;
      }
      if ((*(int *)(*texture + 0xc) >> (baseLevel & 0x3f) < scratchInt30) ||
         (scratchInt30 = 1, (int)(uint)*(ushort *)(*texture + 0x16) >> (baseLevel & 0x3f) < scratchInt25 << 3))
      goto LAB_0003482c;
    }
    if (storageRecord == 0) {
      baseLevel = 0;
    }
    else {
      baseLevel = (*(byte *)(storageRecord + 0x15) & 0x18) << 0xe;
    }
    packetState[0x9c] =
         baseLevel | (halfWidth + pitchAlign) - 1 & -pitchAlign & 0x3ffe | scratchInt30 << 0x10 |
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
        scratchInt25 = 0;
      }
      else {
        baseLevel = nextLevel - *(byte *)(texture[0xc] + 0x69);
        if ((*(byte *)(storageRecordB + 0x15) & 0x18) == 0) {
          iVar26 = 1;
          scratchInt25 = 0x100;
        }
        else {
          iVar26 = 1 << (*(uint *)(&DAT_001d9f4c + (uint)*(byte *)(texture + 0xe) * 0x24) >> 0x1c &
                        3);
          scratchInt25 = 0x20 / iVar26 << 3;
        }
        if ((*(int *)(*texture + 0xc) >> (baseLevel & 0x3f) < scratchInt25) ||
           (scratchInt25 = 1, (int)(uint)*(ushort *)(*texture + 0x16) >> (baseLevel & 0x3f) < iVar26 << 3))
        goto LAB_00034df0;
      }
      if (storageRecordB == 0) {
        baseLevel = 0;
      }
      else {
        baseLevel = (*(byte *)(storageRecordB + 0x15) & 0x18) << 0xe;
      }
      drawCursor[3] = baseLevel | (pitchAlign + halfWidth) - 1 & -pitchAlign & 0x3ffe | scratchInt25 << 0x10 |
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
  scratchInt16 = *(int *)(0x000026c8 + ctx + GLD_connect);
  tailCursor[0x2b] = 0x854;
  tailCursor[0x2a] = scratchInt16;
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
  scratchInt16 = *(int *)(ctx + 0x1d6c);
  tailCursor[0x3b] = (int)((unsigned char *)0x00001096U);
  tailCursor[0x3a] = scratchInt16;
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
  scratchUint20 = ((int (*)())gld_emitBoundUnitObjects)(ctx,tailCursor + 0xbf);
  *(undefined4 *)(ctx + GLD_streamCurrent) = scratchUint20;
  (**(code **)(ctx + GLD_streamSetCurrent))(a0,scratchUint20);
LAB_00035340:
  _pthread_mutex_unlock(*(undefined4 *)(ctx + GLD_mutex));
  return 1;
}

/* glCopyTexSubImage_impl @ 0x353a0 (5656 bytes) */
int glCopyTexSubImage_impl(ctx, texture, face, level, xOffset, yOffset, zOffset, srcX, srcY, copyWidth, copyHeight)
  int ctx;
  int *texture;
  int face;
  uint level;
  uint xOffset;
  uint yOffset;
  int zOffset;
  uint srcX;
  uint srcY;
  int copyWidth;
  int copyHeight;
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
  float scratchFloat1;
  float scratchFloat2;
  float scratchFloat3;
  float scratchFloat4;
  float scratchFloat5;
  float scratchFloat6;
  float scratchFloat7;
  float scratchFloat8;
  ushort scratchUint9;
  ushort scratchUint10;
  short scratchShort11;
  bool scratchFlag12;
  float scratchFloat13;
  float scratchFloat14;
  float scratchFloat15;
  float scratchFloat16;
  float scratchFloat17;
  float scratchFloat18;
  float scratchFloat19;
  float scratchFloat20;
  float scratchFloat21;
  float scratchFloat22;
  float scratchFloat23;
  float scratchFloat24;
  double scratchDouble25;
  undefined *scratchPtr26;
  uint scratchUint27;
  uint scratchUint28;
  uint scratchUint29;
  uint *scratchPtr30;
  uint *scratchPtr31;
  int scratchInt32;
  int scratchInt33;
  int scratchInt34;
  int scratchInt35;
  undefined4 scratchUint36;
  int scratchInt37;
  uint scratchUint38;
  undefined4 scratchUint39;
  uint scratchUint40;
  undefined4 scratchUint41;
  undefined4 scratchUint42;
  undefined4 scratchUint43;
  uint scratchUint44;
  uint scratchUint45;
  uint scratchUint46;
  int scratchInt47;
  uint scratchUint48;
  uint scratchUint49;
  uint scratchUint50;
  int scratchInt51;
  uint scratchUint52;
  int scratchInt53;
  uint scratchStackdc;
  uint scratchStackd8;
  uint scratchStackd4;
  uint scratchStackd0;
  
  scratchUint50 = yOffset;
  scratchInt34 = zOffset;
  _pthread_mutex_lock(*(undefined4 *)(ctx + 0xc));
  scratchInt47 = texture[0xc];
  scratchUint39 = 0;
  scratchInt35 = face;
  scratchUint49 = level;
  scratchInt32 = ((int (*)())gldTextureFormatEntryForLevel)(ctx,texture,face,level,0);
  scratchInt53 = ctx + 0x240;
  if ((scratchInt32 == 0) || ((*(uint *)(scratchInt32 + 0x18) & 0x10000) == 0)) {
LAB_00035740:
    _pthread_mutex_unlock(*(undefined4 *)(ctx + 0xc));
    return 0;
  }
  scratchInt33 = gld_textureVariantClass((uint)*(ushort *)(((unsigned char *)0x00002db8) + *(int *)(ctx + 0x10)),
                        *(undefined4 *)(ctx + 0x154));
  scratchFlag12 = *(short *)(scratchInt47 + 2) != 0x1902;
  if ((!scratchFlag12) &&
     (((*(int *)(ctx + 0x150) == 0 &&
       (scratchInt34 = FUN_0001a010(ctx,scratchInt33,scratchInt35,scratchUint49,scratchUint39,scratchUint50,scratchInt34), scratchInt34 != 0)) ||
      ((*(uint *)(ctx + 0x154) & 0x30000) == 0)))) goto LAB_00035740;
  scratchInt34 = level * 0x18 + face * 0x168 + texture[0xc];
  scratchUint48 = (uint)*(ushort *)(scratchInt34 + 0xa4);
  scratchUint46 = (uint)*(ushort *)(scratchInt34 + 0xa6);
  if (scratchUint48 == 0) {
    scratchUint48 = 1;
    scratchFloat1 = FLOAT_001aa0e8;
  }
  else {
    scratchFloat1 = (float)((double)CONCAT44(0x43300000,scratchUint48 ^ 0x80000000) - DOUBLE_001aa1e0);
  }
  if (scratchUint46 == 0) {
    scratchUint46 = 1;
    scratchFloat8 = FLOAT_001aa0e8;
  }
  else {
    scratchFloat8 = (float)((double)CONCAT44(0x43300000,scratchUint46 ^ 0x80000000) - DOUBLE_001aa1e0);
  }
  scratchFloat2 = (float)((double)CONCAT44(0x43300000,*(uint *)(ctx + 0x15c) ^ 0x80000000) -
                 DOUBLE_001aa1e0);
  scratchFloat3 = (float)((double)CONCAT44(0x43300000,srcX + copyWidth ^ 0x80000000) - DOUBLE_001aa1e0);
  scratchFloat13 = scratchFloat3 - scratchFloat2;
  scratchFloat7 = scratchFloat2;
  if (scratchFloat13 < 0.0) {
    scratchFloat7 = scratchFloat3;
  }
  scratchFloat3 = (float)((double)CONCAT44(0x43300000,srcY + copyHeight ^ 0x80000000) - DOUBLE_001aa1e0);
  scratchFloat4 = (float)((double)CONCAT44(0x43300000,srcX ^ 0x80000000) - DOUBLE_001aa1e0);
  if (-scratchFloat13 < 0.0) {
    scratchFloat7 = scratchFloat2;
  }
  scratchFloat2 = (float)((double)CONCAT44(0x43300000,*(uint *)(ctx + 0x160) ^ 0x80000000) -
                 DOUBLE_001aa1e0);
  scratchFloat13 = scratchFloat4;
  if (scratchFloat4 < 0.0) {
    scratchFloat13 = FLOAT_001aa0d4;
  }
  scratchFloat5 = (float)((double)CONCAT44(0x43300000,xOffset ^ 0x80000000) - DOUBLE_001aa1e0);
  scratchFloat15 = scratchFloat3 - scratchFloat2;
  scratchFloat6 = (float)((double)CONCAT44(0x43300000,srcY ^ 0x80000000) - DOUBLE_001aa1e0);
  scratchFloat14 = FLOAT_001aa0d4;
  if (-scratchFloat4 < 0.0) {
    scratchFloat14 = scratchFloat13;
  }
  scratchFloat13 = scratchFloat5 + (scratchFloat7 - scratchFloat4);
  scratchFloat7 = (float)((double)CONCAT44(0x43300000,yOffset ^ 0x80000000) - DOUBLE_001aa1e0);
  scratchFloat17 = scratchFloat2;
  if (scratchFloat15 < 0.0) {
    scratchFloat17 = scratchFloat3;
  }
  scratchFloat3 = scratchFloat6;
  if (scratchFloat6 < 0.0) {
    scratchFloat3 = FLOAT_001aa0d4;
  }
  if (-scratchFloat15 < 0.0) {
    scratchFloat17 = scratchFloat2;
  }
  scratchFloat2 = scratchFloat13 - scratchFloat1;
  scratchFloat15 = FLOAT_001aa0d4;
  if (-scratchFloat6 < 0.0) {
    scratchFloat15 = scratchFloat3;
  }
  scratchFloat5 = (scratchFloat14 - scratchFloat4) + scratchFloat5;
  scratchFloat3 = scratchFloat1;
  if (scratchFloat2 < 0.0) {
    scratchFloat3 = scratchFloat13;
  }
  scratchFloat13 = scratchFloat5;
  if (scratchFloat5 < 0.0) {
    scratchFloat13 = FLOAT_001aa0d4;
  }
  scratchFloat4 = (float)((double)CONCAT44(0x43300000,srcX - xOffset ^ 0x80000000) - DOUBLE_001aa1e0);
  scratchFloat14 = scratchFloat7 + (scratchFloat17 - scratchFloat6);
  scratchFloat7 = (scratchFloat15 - scratchFloat6) + scratchFloat7;
  if (-scratchFloat2 < 0.0) {
    scratchFloat3 = scratchFloat1;
  }
  scratchFloat1 = FLOAT_001aa0d4;
  if (-scratchFloat5 < 0.0) {
    scratchFloat1 = scratchFloat13;
  }
  scratchFloat2 = scratchFloat8 - scratchFloat14;
  scratchFloat13 = scratchFloat7;
  if (scratchFloat7 < 0.0) {
    scratchFloat13 = FLOAT_001aa0d4;
  }
  scratchFloat5 = (float)((double)CONCAT44(0x43300000,srcY - yOffset ^ 0x80000000) - DOUBLE_001aa1e0);
  scratchFloat15 = scratchFloat1 + scratchFloat4;
  scratchFloat6 = scratchFloat3 + scratchFloat4;
  if (scratchFloat2 < 0.0) {
    scratchFloat14 = scratchFloat8;
  }
  scratchFloat17 = FLOAT_001aa0d4;
  if (-scratchFloat7 < 0.0) {
    scratchFloat17 = scratchFloat13;
  }
  if (-scratchFloat2 < 0.0) {
    scratchFloat8 = scratchFloat14;
  }
  if ((scratchFloat3 <= scratchFloat1) || (scratchFloat8 <= scratchFloat17)) {
    _pthread_mutex_unlock(*(undefined4 *)(ctx + 0xc));
    return 1;
  }
  if (((*(byte *)((int)texture + 0x39) & 7) != 0) &&
     (scratchInt34 = ((int (*)())gldTextureMakeResident)(ctx,texture,scratchInt35,scratchUint49,scratchUint39,scratchUint50), scratchInt34 == 0))
  goto LAB_00035740;
  boundFramebuffer = *(int *)(ctx + 0x150);
  if (boundFramebuffer == 0) {
    scratchInt35 = FUN_0001a010(ctx,scratchInt33,scratchInt35,scratchUint49,scratchUint39,scratchUint50,0);
    if (scratchInt35 == 0) {
      boundFramebuffer = *(int *)(ctx + 0x150);
    }
    else {
      gld_emitSurfaceCopyPacket(ctx,0,scratchInt33,0,(int)scratchFloat15,(int)(scratchFloat17 + scratchFloat5),(int)(scratchFloat6 - scratchFloat15),
                   (int)((scratchFloat8 + scratchFloat5) - (scratchFloat17 + scratchFloat5)));
      boundFramebuffer = *(int *)(ctx + 0x150);
    }
  }
  if (scratchFlag12) {
    scratchInt35 = 0;
    scratchInt51 = 0;
  }
  else {
    scratchInt35 = 1000;
    scratchInt51 = 4000;
  }
  scratchFloat2 = FLOAT_001aa0e8;
  if (((unsigned char *)0x00002b7c)[ctx] != '\0') {
    scratchFloat5 = (float)((double)CONCAT44(0x43300000,*(uint *)(ctx + 0x160) ^ 0x80000000) -
                   DOUBLE_001aa1e0) - scratchFloat5;
    scratchFloat2 = FLOAT_001aa114;
  }
  if (boundFramebuffer == 0) {
    scratchUint9 = *(ushort *)(ctx + 0x11e);
    scratchUint10 = *(ushort *)(ctx + 0x122);
  }
  else {
    scratchUint9 = *(ushort *)(ctx + 0x15e);
    scratchUint10 = *(ushort *)(ctx + 0x162);
  }
  scratchUint50 = (uint)scratchUint9;
  scratchUint49 = (uint)scratchUint10;
  if ((scratchUint50 < 0x1001) && (scratchUint49 < 0x1001)) {
    scratchUint52 = 0;
    scratchInt34 = 0xc;
    scratchStackd0 = 0;
    scratchStackd4 = 0;
    scratchStackd8 = 0;
    scratchStackdc = 0;
    scratchFloat14 = FLOAT_001aa0d4;
    scratchFloat23 = FLOAT_001aa0d4;
    scratchFloat7 = FLOAT_001aa0d4;
    scratchFloat13 = FLOAT_001aa0d4;
  }
  else {
    scratchFloat7 = scratchFloat17 * scratchFloat2 + scratchFloat5;
    scratchFloat14 = scratchFloat8 * scratchFloat2 + scratchFloat5;
    scratchFloat13 = scratchFloat14;
    if (scratchFloat14 < scratchFloat7) {
      scratchFloat13 = scratchFloat7;
      scratchFloat7 = scratchFloat14;
    }
    scratchFloat14 = scratchFloat15;
    scratchFloat23 = scratchFloat6;
    if (scratchFloat6 < scratchFloat15) {
      scratchFloat14 = scratchFloat6;
      scratchFloat23 = scratchFloat15;
    }
    scratchStackd8 = 0;
    scratchUint52 = (int)scratchFloat14 - 1;
    scratchUint52 = (((int)scratchUint52 >> 9) + (uint)((int)scratchUint52 < 0 && (scratchUint52 & 0x1ff) != 0)) * 0x200;
    if ((-1 < (int)scratchUint52) && (scratchStackd8 = scratchUint9 & 0xfe00, (int)scratchUint52 <= (int)(scratchUint9 & 0xfe00))) {
      scratchStackd8 = scratchUint52 & 0xfe00;
    }
    scratchUint52 = 0x40;
    if ((0x40 < scratchUint49) && (scratchUint52 = scratchUint10 & 0xffc0, (int)(scratchUint49 - scratchUint52) < 0x40)) {
      scratchUint52 = scratchUint52 - 0x40;
    }
    scratchStackdc = 0;
    scratchUint38 = (int)scratchFloat7 - 1;
    scratchUint38 = (((int)scratchUint38 >> 6) + (uint)((int)scratchUint38 < 0 && (scratchUint38 & 0x3f) != 0)) * 0x40;
    if ((-1 < (int)scratchUint38) && (scratchStackdc = scratchUint52 & 0xffff, (int)scratchUint38 <= (int)scratchUint52)) {
      scratchStackdc = scratchUint38 & 0xffc0;
    }
    scratchUint52 = 0x200;
    if (0x1ff < scratchStackd8) {
      scratchUint52 = scratchStackd8;
    }
    scratchUint38 = scratchUint50 - 1;
    scratchUint28 = (((int)scratchUint38 >> 9) + (uint)((int)scratchUint38 < 0 && (scratchUint38 & 0x1ff) != 0)) * 0x200;
    scratchUint38 = (uint)(int)scratchFloat23;
    if ((FLOAT_001aa0d4 < scratchFloat23) &&
       ((float)((double)CONCAT44(0x43300000,scratchUint38 ^ 0x80000000) - DOUBLE_001aa1e0) < scratchFloat23)) {
      scratchUint38 = scratchUint38 + 1;
    }
    if ((int)scratchUint38 <= (int)scratchUint28) {
      scratchUint28 = scratchUint38;
    }
    scratchStackd0 = 1;
    if ((int)scratchUint52 < (int)scratchUint28) {
      scratchStackd0 = (int)((scratchUint28 - scratchUint52) + 0xbff) / 0xc00 & 0xff;
    }
    scratchUint52 = 0x40;
    if (0x3f < scratchStackdc) {
      scratchUint52 = scratchStackdc;
    }
    scratchUint38 = scratchUint49 - 1;
    scratchUint28 = (((int)scratchUint38 >> 6) + (uint)((int)scratchUint38 < 0 && (scratchUint38 & 0x3f) != 0)) * 0x40;
    scratchUint38 = (uint)(int)scratchFloat13;
    if ((FLOAT_001aa0d4 < scratchFloat13) &&
       ((float)((double)CONCAT44(0x43300000,scratchUint38 ^ 0x80000000) - DOUBLE_001aa1e0) < scratchFloat13)) {
      scratchUint38 = scratchUint38 + 1;
    }
    if ((int)scratchUint38 <= (int)scratchUint28) {
      scratchUint28 = scratchUint38;
    }
    scratchStackd4 = 1;
    if ((int)scratchUint52 < (int)scratchUint28) {
      scratchStackd4 = (int)((scratchUint28 - scratchUint52) + 0xf7f) / 0xf80 & 0xff;
    }
    scratchUint52 = scratchStackd4 * scratchStackd0 & 0xff;
    scratchInt34 = scratchUint52 << 4;
  }
  if (scratchFlag12) {
    scratchInt37 = 0x343;
  }
  else {
    scratchInt37 = 0x34e;
  }
  scratchUint39 = (**(code **)(ctx + 0x2998))(scratchInt53,scratchInt35 + scratchInt37 + scratchInt34);
  *(undefined4 *)(ctx + 0x298c) = scratchUint39;
  scratchInt34 = ((int (*)())FUN_00030840)(ctx,scratchUint39,texture);
  scratchPtr30 = *(uint **)(ctx + 0x1d8);
  scratchInt37 = scratchInt34 + scratchInt51;
  *scratchPtr30 = scratchInt37 - (int)scratchPtr30 >> 2 | *scratchPtr30;
  *(int *)(ctx + 0x1d8) = scratchInt37;
  *(undefined4 *)(scratchInt34 + scratchInt51) = 0x32000000;
  *(int *)(scratchInt37 + 8) = scratchInt35;
  if (scratchFlag12) {
    *(int *)(scratchInt37 + 0xc) = scratchInt33;
  }
  else {
    if (((*(uint *)(ctx + 0x154) & 0x2000) == 0) ||
       ((scratchUint39 = 10, scratchInt33 != 7 && (scratchUint39 = 0xb, scratchInt33 != 8)))) {
      scratchUint39 = 4;
    }
    *(undefined4 *)(scratchInt37 + 0xc) = scratchUint39;
  }
  *(uint *)(scratchInt37 + 0x14) = scratchUint52;
  scratchPtr26 = PTR_DAT_001e88d0;
  *(uint *)(scratchInt37 + 0x10) = level | face << 0x10;
  *(uint *)(scratchInt37 + 0x18) = CONCAT22(scratchUint10,scratchUint9);
  scratchPtr30 = (uint *)(scratchInt37 + 0x310);
  _memcpy(scratchInt37 + 0x1c,scratchPtr26,0x2f4);
  scratchUint27 = *(uint *)(scratchInt37 + 0x244);
  scratchUint38 = (*(uint *)(scratchInt32 + 0x18) & 0x18) << 5;
  *(uint *)(scratchInt37 + 0x244) = scratchUint38 | scratchUint27 & 0xfffffcff;
  scratchUint28 = (*(uint *)(scratchInt32 + 0x18) & 6) << 9;
  *(uint *)(scratchInt37 + 0x244) = scratchUint28 | scratchUint38 | scratchUint27 & 0xfffff0ff;
  scratchUint40 = *(uint *)(scratchInt32 + 0x1c) >> 0x12 & 0x3000;
  *(uint *)(scratchInt37 + 0x244) = scratchUint40 | scratchUint28 | scratchUint38 | scratchUint27 & 0xffffc0ff;
  scratchUint44 = *(uint *)(scratchInt32 + 0x1c) >> 0xe & 0xc000;
  *(uint *)(scratchInt37 + 0x244) = scratchUint44 | scratchUint40 | scratchUint28 | scratchUint38 | scratchUint27 & 0xffff00ff;
  *(uint *)(scratchInt37 + 0x244) =
       *(uint *)(scratchInt32 + 0x18) >> 5 & 0x1f |
       scratchUint44 | scratchUint40 | scratchUint28 | scratchUint38 | scratchUint27 & 0xffff00e0;
  scratchShort11 = *(short *)(scratchInt47 + 2);
  if ((((scratchShort11 != 0x1908) && (scratchShort11 != 0x1906)) && (scratchShort11 != 0x190a)) && (scratchShort11 != 0x1902)) {
    *(uint *)(scratchInt37 + 0x174) = *(uint *)(scratchInt37 + 0x174) & 0xfffe3fff | 0x18000;
  }
  scratchInt35 = texture[0xd];
  if ((scratchInt35 == 0) || ((*(byte *)(scratchInt35 + 0x15) & 0x18) == 0)) {
    scratchInt34 = 0x20;
  }
  else {
    scratchInt34 = 0x20 / (1 << (*(uint *)(&DAT_001d9f4c + (uint)*(byte *)(texture + 0xe) * 0x24) >> 0x1c
                          & 3));
  }
  scratchInt34 = scratchInt34 >> (*(uint *)(scratchInt32 + 0x14) & 7);
  if ((scratchInt35 == 0) || (*(char *)(scratchInt35 + 0x16) != '\x06')) {
    scratchUint38 = 0;
    scratchInt35 = *texture + 0x40 + (face * 0xd + level) * 0x20;
    scratchInt35 = zOffset * *(int *)(scratchInt35 + 0x14) + *(int *)(scratchInt35 + 8);
  }
  else {
    scratchInt35 = 0;
    scratchUint38 = *(uint *)(scratchInt32 + 0x18) >> 0xb & 0x180000;
  }
  if (*(char *)(texture[0xc] + 0x6d) == '\0') {
    scratchUint28 = (scratchUint48 + scratchInt34) - 1 & -scratchInt34;
  }
  else {
    scratchUint28 = (uint)*(ushort *)((int)texture + 0x3e);
  }
  *(int *)(scratchInt37 + 0x284) = scratchInt35;
  scratchInt35 = texture[0xd];
  if ((scratchInt35 != 0) && ((*(byte *)(scratchInt35 + 0x15) & 4) != 0)) {
    scratchUint40 = level - *(byte *)(texture[0xc] + 0x69);
    if ((*(byte *)(scratchInt35 + 0x15) & 0x18) == 0) {
      scratchInt33 = 1;
      scratchInt34 = 0x100;
    }
    else {
      scratchInt33 = 1 << (*(uint *)(&DAT_001d9f4c + (uint)*(byte *)(texture + 0xe) * 0x24) >> 0x1c & 3);
      scratchInt34 = 0x20 / scratchInt33 << 3;
    }
    if ((scratchInt34 <= *(int *)(*texture + 0xc) >> (scratchUint40 & 0x3f)) &&
       (scratchInt34 = 1, scratchInt33 << 3 <= (int)(uint)*(ushort *)(*texture + 0x16) >> (scratchUint40 & 0x3f)))
    goto LAB_00035dd8;
  }
  scratchInt34 = 0;
LAB_00035dd8:
  if (scratchInt35 != 0) {
    scratchUint40 = (*(byte *)(scratchInt35 + 0x15) & 0x18) << 0xe;
  }
  else {
    scratchUint40 = 0;
  }
  scratchUint44 = *(uint *)(scratchInt32 + 0x18);
  *(uint *)(scratchInt37 + 0x2e8) = scratchUint48 - 1 & 0x1fff | (scratchUint46 - 1) * 0x2000 & 0x3ffe000;
  *(uint *)(scratchInt37 + 0x28c) =
       scratchUint40 | scratchUint28 & 0x3ffe | scratchInt34 << 0x10 | scratchUint38 | (scratchUint44 & 0x3c00) << 0xb;
  if ((*(uint *)(scratchInt32 + 0x20) & 0x400000) != 0) {
    *(undefined4 *)(scratchInt37 + 0x94) = 0;
  }
  scratchFloat16 = FLOAT_001aa12c;
  if (scratchUint52 == 0) {
    scratchFloat7 = FLOAT_001aa0d4;
    if (scratchUint50 != 0) {
      scratchFloat7 = FLOAT_001aa0e8 /
              (float)((double)CONCAT44(0x43300000,scratchUint50 ^ 0x80000000) - DOUBLE_001aa1e0);
    }
    scratchFloat13 = FLOAT_001aa0d4;
    if (scratchUint49 != 0) {
      scratchFloat13 = FLOAT_001aa0e8 /
               (float)((double)CONCAT44(0x43300000,scratchUint49 ^ 0x80000000) - DOUBLE_001aa1e0);
    }
    *scratchPtr30 = 0x31080;
    *(undefined **)(scratchInt37 + 0x324) = ((unsigned char *)0x00001087U);
    *(float *)(scratchInt37 + 0x31c) = scratchFloat7 * scratchFloat6;
    *(float *)(scratchInt37 + 0x318) = scratchFloat13 * (scratchFloat8 * scratchFloat2 + scratchFloat5);
    *(float *)(scratchInt37 + 800) = scratchFloat13 * (scratchFloat17 * scratchFloat2 + scratchFloat5);
    *(float *)(scratchInt37 + 0x314) = scratchFloat7 * scratchFloat15;
    scratchFloat2 = (scratchFloat1 + scratchFloat3) * FLOAT_001aa10c;
    scratchFloat7 = (scratchFloat17 + scratchFloat8) * FLOAT_001aa10c;
    *(undefined4 *)(scratchInt37 + 0x32c) = 0xc0033500;
    *(undefined4 *)(scratchInt37 + 0x330) = 0x10031;
    *(float *)(scratchInt37 + 0x334) = scratchFloat2;
    *(float *)(scratchInt37 + 0x338) = scratchFloat7;
    *(int *)(scratchInt37 + 0x328) =
         (int)((scratchFloat3 - scratchFloat1) * scratchFloat16) << 0x10 | (int)((scratchFloat8 - scratchFloat17) * scratchFloat16);
    *(undefined4 *)(scratchInt37 + 0x33c) = 0;
    scratchPtr30 = (uint *)(scratchInt37 + 0x340);
  }
  else {
    scratchFloat1 = FLOAT_001aa0d4;
    if (scratchFloat2 != FLOAT_001aa0d4) {
      scratchFloat1 = FLOAT_001aa0e8 / scratchFloat2;
    }
    if (scratchStackd4 != 0) {
      scratchUint38 = 0;
      scratchInt35 = 0;
      scratchUint52 = scratchUint49 - scratchStackdc;
      scratchUint48 = scratchStackdc;
      do {
        if (scratchStackd0 != 0) {
          scratchInt34 = 0;
          scratchUint44 = scratchInt35 + scratchStackdc;
          scratchUint27 = scratchUint50 - scratchStackd8;
          scratchFloat8 = (float)((double)CONCAT44(0x43300000,scratchUint44 ^ 0x80000000) - DOUBLE_001aa1e0);
          scratchUint28 = scratchStackd8;
          scratchUint40 = scratchStackd0;
          do {
            *scratchPtr30 = scratchUint28;
            scratchPtr30[1] = scratchUint48;
            scratchUint29 = scratchUint27;
            if ((int)(scratchUint28 + 0x1000) <= (int)scratchUint50) {
              scratchUint29 = 0x1000;
            }
            scratchUint45 = scratchUint52;
            if ((int)(scratchUint44 + 0x1000) <= (int)scratchUint49) {
              scratchUint45 = 0x1000;
            }
            scratchPtr30[2] = scratchUint29;
            scratchPtr30[3] = scratchUint45;
            scratchDouble25 = DOUBLE_001aa1e0;
            scratchFloat2 = scratchFloat14;
            if (scratchInt34 != 0) {
              scratchFloat2 = (float)((double)CONCAT44(0x43300000,scratchUint28 + 0x200 ^ 0x80000000) -
                             DOUBLE_001aa1e0);
            }
            scratchFloat3 = scratchFloat7;
            if (scratchUint38 != 0) {
              scratchFloat3 = (float)((double)CONCAT44(0x43300000,scratchUint44 + 0x40 ^ 0x80000000) -
                             DOUBLE_001aa1e0);
            }
            scratchFloat6 = scratchFloat23;
            if (scratchInt34 != scratchStackd0 - 1) {
              scratchFloat6 = (float)((double)CONCAT44(0x43300000,scratchUint28 + 0xe00 ^ 0x80000000) -
                             DOUBLE_001aa1e0);
            }
            scratchFloat15 = scratchFloat13;
            if (scratchUint38 != scratchStackd4 - 1) {
              scratchFloat15 = (float)((double)CONCAT44(0x43300000,scratchUint44 + 0xfc0 ^ 0x80000000) -
                              DOUBLE_001aa1e0);
            }
            scratchFloat17 = scratchFloat7;
            if (scratchFloat7 - scratchFloat3 < 0.0) {
              scratchFloat17 = scratchFloat3;
            }
            scratchFloat16 = scratchFloat15;
            if (scratchFloat13 - scratchFloat15 < 0.0) {
              scratchFloat16 = scratchFloat13;
            }
            scratchFloat18 = scratchFloat6;
            if (scratchFloat23 - scratchFloat6 < 0.0) {
              scratchFloat18 = scratchFloat23;
            }
            scratchFloat19 = scratchFloat14;
            if (scratchFloat14 - scratchFloat2 < 0.0) {
              scratchFloat19 = scratchFloat2;
            }
            if (-(scratchFloat7 - scratchFloat3) < 0.0) {
              scratchFloat3 = scratchFloat17;
            }
            if (-(scratchFloat13 - scratchFloat15) < 0.0) {
              scratchFloat16 = scratchFloat15;
            }
            if (-(scratchFloat14 - scratchFloat2) < 0.0) {
              scratchFloat2 = scratchFloat19;
            }
            if (-(scratchFloat23 - scratchFloat6) < 0.0) {
              scratchFloat18 = scratchFloat6;
            }
            scratchFloat22 = scratchFloat1 * scratchFloat16 + scratchFloat1 * -scratchFloat5;
            scratchFloat15 = scratchFloat1 * scratchFloat3 + scratchFloat1 * -scratchFloat5;
            scratchFloat19 = scratchFloat2 + -scratchFloat4;
            scratchFloat17 = scratchFloat18 + -scratchFloat4;
            scratchFloat6 = scratchFloat22;
            scratchFloat24 = scratchFloat16;
            if (scratchFloat22 < scratchFloat15) {
              scratchFloat6 = scratchFloat15;
              scratchFloat15 = scratchFloat22;
              scratchFloat24 = scratchFloat3;
              scratchFloat3 = scratchFloat16;
            }
            scratchFloat16 = scratchFloat19;
            scratchFloat22 = scratchFloat18;
            if (scratchFloat17 < scratchFloat19) {
              scratchFloat16 = scratchFloat17;
              scratchFloat17 = scratchFloat19;
              scratchFloat22 = scratchFloat2;
              scratchFloat2 = scratchFloat18;
            }
            scratchFloat18 = FLOAT_001aa0d4;
            if (scratchUint29 != 0) {
              scratchFloat18 = FLOAT_001aa0e8 /
                       (float)((double)CONCAT44(0x43300000,scratchUint29 ^ 0x80000000) - DOUBLE_001aa1e0);
            }
            scratchFloat19 = FLOAT_001aa0d4;
            if (scratchUint45 != 0) {
              scratchFloat19 = FLOAT_001aa0e8 /
                       (float)((double)CONCAT44(0x43300000,scratchUint45 ^ 0x80000000) - DOUBLE_001aa1e0);
            }
            scratchUint29 = scratchUint28 ^ 0x80000000;
            scratchInt34 = scratchInt34 + 1;
            scratchUint28 = scratchUint28 + 0xc00;
            scratchUint27 = scratchUint27 - 0xc00;
            scratchFloat20 = (scratchFloat17 - scratchFloat16) * FLOAT_001aa12c;
            scratchFloat21 = (scratchFloat6 - scratchFloat15) * FLOAT_001aa12c;
            scratchFloat17 = (scratchFloat17 + scratchFloat16) * FLOAT_001aa10c;
            scratchFloat6 = (scratchFloat6 + scratchFloat15) * FLOAT_001aa10c;
            scratchPtr30[4] = 0x31080;
            scratchPtr30[6] = (uint)GH_F2U((float)((scratchFloat19 * (scratchFloat24 - scratchFloat8))));
            scratchPtr30[8] = (uint)GH_F2U((float)((scratchFloat19 * (scratchFloat3 - scratchFloat8))));
            scratchPtr30[9] = (uint)((unsigned char *)0x00001087U);
            scratchFloat3 = (float)((double)CONCAT44(0x43300000,scratchUint29) - scratchDouble25);
            scratchPtr30[7] = (uint)GH_F2U((float)((scratchFloat18 * (scratchFloat22 - scratchFloat3))));
            scratchPtr30[5] = (uint)GH_F2U((float)((scratchFloat18 * (scratchFloat2 - scratchFloat3))));
            scratchPtr30[0xb] = 0xc0033500;
            scratchPtr30[0xc] = 0x10031;
            scratchPtr30[0xd] = (uint)GH_F2U((float)(scratchFloat17));
            scratchPtr30[0xe] = (uint)GH_F2U((float)(scratchFloat6));
            scratchPtr30[10] = (int)scratchFloat20 << 0x10 | (int)scratchFloat21;
            scratchPtr30[0xf] = 0;
            scratchPtr30 = scratchPtr30 + 0x10;
            scratchUint40 = scratchUint40 - 1;
          } while (scratchUint40 != 0);
        }
        scratchUint38 = scratchUint38 + 1;
        scratchInt35 = scratchInt35 + 0xf80;
        scratchUint52 = scratchUint52 - 0xf80;
        scratchUint48 = scratchUint48 + 0xf80;
      } while (scratchUint38 != scratchStackd4);
    }
  }
  *(int *)(scratchInt37 + 4) = (int)scratchPtr30 - scratchInt37 >> 2;
  scratchPtr31 = *(uint **)(ctx + 0x1d8);
  *scratchPtr31 = (int)scratchPtr30 - (int)scratchPtr31 >> 2 | *scratchPtr31;
  *(uint **)(ctx + 0x1d8) = scratchPtr30;
  *scratchPtr30 = 0x33000000;
  if (scratchFlag12) {
    scratchUint49 = 0;
  }
  else {
    scratchUint49 = 2;
  }
  scratchPtr30[1] = scratchUint49;
  scratchPtr30[2] = (uint)((unsigned char *)0x00001393U);
  scratchPtr30[3] = 10;
  scratchPtr30[4] = (uint)((unsigned char *)0x000013c6U);
  scratchPtr30[5] = 3;
  scratchPtr30[6] = 0x5c8;
  scratchPtr30[7] = 0x20000;
  scratchPtr30[8] = (uint)((unsigned char *)0x000010eaU);
  sc_edgerule = *(uint *)(ctx + 0x1cfc);
  scratchPtr30[10] = (uint)((unsigned char *)0x000010faU);
  scratchPtr30[9] = sc_edgerule;
  sc_screendoor = *(uint *)(ctx + 0x1da0);
  scratchPtr30[0xc] = 0xc0001000;
  scratchPtr30[0xe] = 0x11004;
  scratchPtr30[0xb] = sc_screendoor;
  scratchPtr30[0xf] = *(uint *)(ctx + 0x1ca8);
  gb_mspos1 = *(uint *)(ctx + 0x1cac);
  scratchPtr30[0x11] = (uint)((unsigned char *)0x00001008U);
  scratchPtr30[0x10] = gb_mspos1;
  gb_aa_config = *(uint *)(ctx + 0x1ca0);
  scratchPtr30[0x13] = (uint)((unsigned char *)0x000010e9U);
  scratchPtr30[0x12] = gb_aa_config;
  sc_hyperz_en = *(uint *)(ctx + 0x1d20);
  scratchPtr30[0x15] = (uint)((unsigned char *)0x000013c7U);
  scratchPtr30[0x14] = sc_hyperz_en;
  zb_bw_cntl = *(uint *)(ctx + 0x1cf0);
  scratchPtr30[0x17] = (uint)((unsigned char *)0x000013c1U);
  scratchPtr30[0x16] = zb_bw_cntl;
  zb_zstencilcntl = *(uint *)(ctx + 0x1ce4);
  scratchPtr30[0x19] = 0x850;
  scratchPtr30[0x18] = zb_zstencilcntl;
  scratchPtr30[0x1a] = *(uint *)(ctx + 0x1dc0);
  scratchPtr30[0x1b] = 0x887;
  vap_clip_cntl = *(uint *)(ctx + 0x1db4);
  scratchPtr30[0xbd] = 0x82c;
  scratchPtr30[0x1c] = vap_clip_cntl;
  vap_vte_cntl = *(uint *)(0x00001dc4 + ctx);
  scratchPtr30[0x1d] = (uint)((unsigned char *)0x000010aeU);
  scratchPtr30[0xbe] = vap_vte_cntl;
  su_cull_mode = *(uint *)(ctx + 0x1d70);
  scratchPtr30[0x1f] = (uint)((unsigned char *)0x00001394U);
  scratchPtr30[0x1e] = su_cull_mode;
  rb3d_dither_ctl = *(uint *)(ctx + 0x1d30);
  scratchPtr30[0x21] = (uint)((unsigned char *)0x00001380U);
  scratchPtr30[0x23] = (uint)((unsigned char *)0x00001002U);
  scratchPtr30[0x22] = 0;
  scratchPtr30[0x20] = rb3d_dither_ctl;
  scratchPtr30[0x24] = *(uint *)(ctx + 0x1d90);
  gb_enable = *(uint *)(ctx + 0x1d90);
  scratchPtr30[0x25] = 0x824;
  scratchPtr30[0x24] = gb_enable;
  vap_out_vtx_fmt_0 = *(uint *)(ctx + 0x1ddc);
  scratchPtr30[0x27] = 0x825;
  scratchPtr30[0x26] = vap_out_vtx_fmt_0;
  vap_out_vtx_fmt_1 = *(uint *)(ctx + 0x1de0);
  scratchPtr30[0x29] = 0x82d;
  scratchPtr30[0x28] = vap_out_vtx_fmt_1;
  scratchUint49 = *(uint *)(0x000026c8 + ctx + 4);
  scratchPtr30[0x2b] = 0x854;
  scratchPtr30[0x2a] = scratchUint49;
  scratchUint49 = **(uint **)(ctx + 0x2680);
  scratchPtr30[0x2d] = 0x878;
  scratchPtr30[0x2c] = scratchUint49;
  scratchUint49 = **(uint **)(ctx + 0x2684);
  scratchPtr30[0x2f] = (uint)((unsigned char *)0x000013c0U);
  scratchPtr30[0x2e] = scratchUint49;
  zb_cntl = *(uint *)(ctx + 0x1ce0);
  scratchPtr30[0x31] = (uint)((unsigned char *)0x000012f0U);
  scratchPtr30[0x30] = zb_cntl;
  fg_fog_blend = *(uint *)(ctx + 0x1d2c);
  scratchPtr30[0x32] = fg_fog_blend;
  if ((*(uint *)(&DAT_001d9f4c + (uint)(byte)((unsigned char *)0x00002b7f)[ctx] * 0x24) & 0x8000) == 0) {
    scratchPtr30[0x32] = fg_fog_blend & 0xfffffffe;
  }
  scratchPtr30[0x33] = (uint)((unsigned char *)0x000012f5U);
  fg_alpha_func = *(uint *)(ctx + 0x1c8c);
  scratchPtr30[0x34] = fg_alpha_func;
  if ((*(uint *)(&DAT_001d9f4c + (uint)(byte)((unsigned char *)0x00002b7f)[ctx] * 0x24) & 0x8000) == 0) {
    scratchPtr30[0x34] = fg_alpha_func & 0xfffff7ff;
  }
  scratchPtr30[0x35] = (uint)((unsigned char *)0x000010a2U);
  ga_poly_mode = *(uint *)(ctx + 0x1d7c);
  scratchPtr30[0x37] = (uint)((unsigned char *)0x00001381U);
  scratchPtr30[0x36] = ga_poly_mode;
  rb3d_blendcntl = *(uint *)(ctx + 0x1cc0);
  scratchPtr30[0x38] = rb3d_blendcntl;
  if ((*(uint *)(&DAT_001d9f4c + (uint)(byte)((unsigned char *)0x00002b7f)[ctx] * 0x24) & 0x4000) == 0) {
    scratchPtr30[0x38] = rb3d_blendcntl & 0xfffffffc;
  }
  scratchPtr30[0x39] = (uint)((unsigned char *)0x0000109eU);
  scratchUint43 = 0xc0221000;
  scratchUint42 = 0xaaaa;
  scratchUint41 = 0x110f8;
  scratchUint39 = 0x31080;
  scratchUint49 = *(uint *)(ctx + 0x1d6c);
  scratchPtr30[0x3b] = (uint)((unsigned char *)0x00001096U);
  scratchPtr30[0x3a] = scratchUint49;
  ga_color_control = *(uint *)(ctx + 0x1df8);
  scratchPtr30[0x3d] = (uint)((unsigned char *)0x00001041U);
  scratchPtr30[0x3a] = ga_color_control;
  tx_enable = *(uint *)(ctx + 0x29f0);
  scratchPtr30[0x3f] = (uint)((unsigned char *)0x00001046U);
  scratchPtr30[0x3e] = tx_enable;
  gb_ps3_enable = *(uint *)(ctx + 0x1dfc);
  scratchPtr30[0x41] = (uint)((unsigned char *)0x00001094U);
  scratchPtr30[0x59] = (uint)((unsigned char *)0x00001095U);
  scratchPtr30[0x43] = (uint)((unsigned char *)0x00001095U);
  scratchPtr30[0x7f] = (uint)((unsigned char *)0x00001180U);
  scratchPtr30[0x45] = (uint)((unsigned char *)0x00001095U);
  scratchPtr30[0x47] = (uint)((unsigned char *)0x00001095U);
  scratchPtr30[0x49] = (uint)((unsigned char *)0x00001095U);
  scratchPtr30[0x40] = gb_ps3_enable;
  scratchPtr30[0x4b] = (uint)((unsigned char *)0x00001095U);
  scratchPtr30[0x4d] = (uint)((unsigned char *)0x00001095U);
  scratchPtr30[0x4f] = (uint)((unsigned char *)0x00001095U);
  scratchPtr30[0x51] = (uint)((unsigned char *)0x00001095U);
  scratchPtr30[0x53] = (uint)((unsigned char *)0x00001095U);
  scratchPtr30[0x55] = (uint)((unsigned char *)0x00001095U);
  scratchPtr30[0x57] = (uint)((unsigned char *)0x00001095U);
  scratchPtr30[0x5b] = 0xc0221000;
  scratchPtr30[0x42] = 0;
  scratchPtr30[0x80] = 2;
  scratchPtr30[0x81] = (uint)((unsigned char *)0x00001189U);
  scratchPtr30[0x83] = (uint)((unsigned char *)0x00001181U);
  scratchPtr30[0x85] = (uint)((unsigned char *)0x0000118dU);
  scratchPtr30[0x87] = (uint)((unsigned char *)0x0000118eU);
  scratchPtr30[0x89] = (uint)((unsigned char *)0x0000118cU);
  scratchPtr30[0x8b] = (uint)((unsigned char *)0x000011a9U);
  us_out_fmt_0 = *(uint *)(ctx + 0x257c);
  scratchPtr30[0x8d] = (uint)((unsigned char *)0x000011aaU);
  scratchPtr30[0x8c] = us_out_fmt_0;
  us_out_fmt_1 = *(uint *)(ctx + 0x2580);
  scratchPtr30[0x8f] = (uint)((unsigned char *)0x000011abU);
  scratchPtr30[0x8e] = us_out_fmt_1;
  us_out_fmt_2 = *(uint *)(ctx + 0x2584);
  scratchPtr30[0x91] = (uint)((unsigned char *)0x000011acU);
  scratchPtr30[0x90] = us_out_fmt_2;
  us_out_fmt_3 = *(uint *)(ctx + 0x2588);
  scratchPtr30[0x93] = (uint)((unsigned char *)0x000010c0U);
  scratchPtr30[0x92] = us_out_fmt_3;
  rs_count = *(uint *)(ctx + 0x216c);
  scratchPtr30[0x95] = (uint)((unsigned char *)0x000010c1U);
  scratchPtr30[0x97] = (uint)((unsigned char *)0x000010c8U);
  scratchPtr30[0x99] = (uint)((unsigned char *)0x0000101dU);
  scratchPtr30[0x94] = rs_count;
  rs_ip_0 = *(uint *)(ctx + 0x2128);
  scratchPtr30[0x9b] = (uint)((unsigned char *)0x0000138aU);
  scratchPtr30[0x9d] = (uint)((unsigned char *)0x0000138eU);
  scratchPtr30[0xa2] = 0;
  scratchPtr30[0x9f] = (uint)((unsigned char *)0x00001040U);
  scratchPtr30[0x9c] = 0;
  scratchPtr30[0x9e] = 0;
  scratchPtr30[0xa0] = 0;
  scratchPtr30[0x9a] = rs_ip_0;
  scratchPtr30[0xa1] = (uint)((unsigned char *)0x00001150U);
  scratchPtr30[0xa3] = (uint)((unsigned char *)0x00001100U);
  tx_filter0 = *(uint *)(ctx + 0x1f1c);
  scratchPtr30[0xa5] = (uint)((unsigned char *)0x00001110U);
  scratchPtr30[0xa4] = tx_filter0;
  scratchPtr30[0xa6] = *(uint *)(ctx + 0x1f5c);
  scratchPtr30[0xa7] = (uint)((unsigned char *)0x00001120U);
  tx_format0 = *(uint *)(ctx + 0x1f9c);
  scratchPtr30[0xa9] = (uint)((unsigned char *)0x00001130U);
  scratchPtr30[0xa8] = tx_format0;
  tx_format1 = *(uint *)(ctx + 0x1fdc);
  scratchPtr30[0xab] = (uint)((unsigned char *)0x00001140U);
  scratchPtr30[0xaa] = tx_format1;
  tx_format2 = *(uint *)(ctx + 0x201c);
  scratchPtr30[0xad] = (uint)((unsigned char *)0x000010f4U);
  scratchPtr30[0xae] = 0xaaaa;
  scratchPtr30[0xaf] = (uint)((unsigned char *)0x00001383U);
  scratchPtr30[0xac] = tx_format2;
  rb3d_color_channel_mask = *(uint *)(ctx + 0x1d34);
  scratchPtr30[0xb1] = (uint)((unsigned char *)0x00001386U);
  scratchPtr30[0xb0] = rb3d_color_channel_mask;
  rb3d_ropcntl = *(uint *)(ctx + 0x1d38);
  scratchPtr30[0xb3] = 0x110f8;
  scratchPtr30[0xb2] = rb3d_ropcntl;
  scratchPtr30[0xb4] = *(uint *)(ctx + 0x1d98);
  sc_scissor1 = *(uint *)(ctx + 0x1d50);
  scratchPtr30[0xb6] = (uint)((unsigned char *)0x00001087U);
  scratchPtr30[0xb5] = sc_scissor1;
  ga_point_size = *(uint *)(ctx + 0x1f0c);
  scratchPtr30[0xb8] = 0x31080;
  scratchPtr30[0xb7] = ga_point_size;
  scratchPtr30[0xb9] = *(uint *)(ctx + 0x1efc);
  scratchPtr30[0xba] = *(uint *)(ctx + 0x1f04);
  scratchPtr30[0xbb] = *(uint *)(ctx + 0x1f00);
  scratchPtr30[0xbc] = *(uint *)(ctx + 0x1f08);
  FUN_0004c100(scratchPtr30 + 2,scratchInt53);
  scratchPtr31 = scratchPtr30 + 0xbf;
  if (!scratchFlag12) {
    scratchPtr30[0xbf] = (uint)((unsigned char *)0x000013c4U);
    scratchPtr30[0xc1] = 0x113c8;
    scratchPtr30[200] = (uint)((unsigned char *)0x000013caU);
    scratchPtr30[0xc4] = (uint)((unsigned char *)0x000013cdU);
    scratchPtr30[0xc6] = (uint)((unsigned char *)0x000013ccU);
    scratchPtr31 = scratchPtr30 + 0xca;
  }
  scratchUint36 = ((int (*)())gld_emitBoundUnitObjects)(ctx,scratchPtr31);
  *(undefined4 *)(ctx + 0x298c) = scratchUint36;
  (**(code **)(ctx + 0x299c))(scratchInt53,scratchUint36);
  _pthread_mutex_unlock(*(undefined4 *)(ctx + 0xc));
  if ((((*(uint *)(ctx + 0x24) & 0x82) != 0) && (texture[0xd] != 0)) &&
     (*(char *)(texture[0xd] + 0x16) == '\x06')) {
    scratchInt34 = scratchInt47 + 0xa0 + (uint)*(byte *)(scratchInt47 + 0x5e) * 0x18;
    scratchUint9 = *(ushort *)(scratchInt34 + 0xc);
    scratchInt35 = gldPixelUnitBytes((uint)*(ushort *)(scratchInt34 + 0x10),(uint)*(ushort *)(scratchInt34 + 0x12));
    if (*(int *)(scratchInt34 + 0x14) != 0) {
      gldFlushDataCacheRangeSync(ctx,*(int *)(scratchInt34 + 0x14),(uint)scratchUint9 * scratchInt35 * scratchUint46,scratchUint39,scratchUint41,
                   scratchUint42,sc_scissor1,scratchUint43);
    }
  }
  if (((*(uint *)(texture[0xc] + 0x48) & 0x8000) != 0) &&
     (level == *(byte *)(texture[0xc] + 0x5e))) {
    ((int (*)())glGenerateMipmap_impl)(ctx,texture,face,scratchUint39,scratchUint41);
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
  float scratchFloat4;
  float scratchFloat5;
  float scratchFloat6;
  float scratchFloat7;
  short scratchShort8;
  ushort scratchUint9;
  ushort levelWidthB;
  short scratchShort11;
  float scratchFloat12;
  float scratchFloat13;
  float scratchFloat14;
  float scratchFloat15;
  float scratchFloat16;
  float scratchFloat17;
  float scratchFloat18;
  byte scratchFlag19;
  int scratchInt20;
  uint scratchUint21;
  int scratchInt22;
  uint *srcRow;
  uint scratchUint24;
  undefined *unpackState;
  uint scratchUint26;
  int alignPixels;
  undefined4 scratchUint28;
  uint *scratchPtr29;
  undefined4 *texPacket;
  undefined *a2;
  undefined4 scratchUint31;
  int scratchInt32;
  uint *scratchPtr33;
  int scratchInt34;
  uint scratchUint35;
  int *scratchPtr36;
  uint *scratchPtr37;
  uint *scratchPtr38;
  int levelRecord;
  undefined4 *packetEndA;
  undefined *bytesLeft;
  uint scratchUint42;
  int scratchInt43;
  uint scratchUint44;
  int scratchInt45;
  char reservation;
  byte scratchFlag46;
  uint scratchStack248;
  int srcSkipBytes;
  uint srcBytesPerPixel;
  uint *scratchStack23c;
  uint srcRowBytes;
  uint scratchStack234;
  uint scratchStack230;
  uint *scratchStack22c;
  uint procPitch;
  uint procChannelFormat;
  uint procChannelSize;
  undefined4 scratchStack21c;
  uint procFlags;
  undefined *scratchStack214;
  uint procWidth;
  uint procHeight;
  undefined4 scratchStack208;
  undefined4 scratchStack204;
  undefined1 scratchStack1d0;
  undefined4 scratchStack1c8;
  uint scratchStack1c4;
  undefined4 scratchStack1c0;
  uint scratchStack1bc;
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
  uint *scratchStack10c;
  uint scratchStack108;
  uint widthMask;
  uint levelFaceWord;
  int *scratchStackfc;
  uint levelHeight;
  int mappingOffsetB;
  uint dstPitchCopy;
  uint chunkHeight;
  uint levelWidth;
  int rowsDone;
  uint chunkRows;
  int mappingOffset;
  int chunkBytes;
  code *scratchStackd4;
  code *scratchStackd0;
  int faceByteOffset;
  int *scratchStackc8;
  uint *scratchStackc4;
  uint **scratchStackc0;
  uint *scratchStackbc;
  uint *scratchStackb8;
  uint *scratchStackb4;
  code *scratchStackb0;
  uint levelId;
  code *scratchStacka8;
  int levelByteOffset;
  uint faceId;
  int scratchStack9c;
  
  if (sourceSurface == (undefined4 *)0x0) {
    yoffsetArg = yOffset;
    _pthread_mutex_lock(*(undefined4 *)(ctx + GLD_mutex));
    scratchUint44 = 0;
    faceArg = face;
    levelArg = level;
    levelRecord = ((int (*)())gldTextureFormatEntryForLevel)(ctx,texture,face,level,0);
    if ((levelRecord != 0) &&
       ((scratchInt22 = texture[0xd], scratchInt22 == 0 || (*(char *)(scratchInt22 + 0x16) != '\x06')))) {
      if ((*(byte *)((int)texture + 0x39) & 7) != 0) {
        faceArg = ((int (*)())gldTextureMakeResident)(ctx,texture,faceArg,levelArg,scratchUint44,yoffsetArg);
        if (faceArg == 0) goto LAB_00037930;
        scratchInt22 = texture[0xd];
      }
      if (*(char *)(scratchInt22 + 0x16) != '\x06') {
        bppShiftB = *(uint *)(levelRecord + 0x14) & 7;
        rowPitch = (width << bppShiftB) + 0x23 & 0xffffffe0;
        if ((((depth == 1) && ((int)width < 0x1001)) &&
            ((0x800 >= (int)width || (bppShiftB < 4)))) && ((*(uint *)(levelRecord + 0x14) & 8) == 0)) {
          commandStream = ctx + GLD_commandStream;
          scratchUint28 = (**(code **)(ctx + GLD_streamAllocate))(commandStream,0xe0);
          *(undefined4 *)(ctx + GLD_streamCurrent) = scratchUint28;
          scratchUint28 = ((int (*)())FUN_00030840)(ctx,scratchUint28,texture);
          *(undefined4 *)(ctx + GLD_streamCurrent) = scratchUint28;
          (**(code **)(ctx + GLD_streamSetCurrent))(commandStream,scratchUint28);
          chunkRows = 0x1e000 / rowPitch;
          srcHwFormatB = ((int (*)())gldTextureFormatCodeFromFormatType)(pixelFormat,pixelType);
          if ((srcHwFormatB == *(byte *)(texture + 0xe)) && ((*(uint *)(levelRecord + 0x14) & 7) < 3)) {
            chunkRowsHw = 0x10000 / rowPitch;
            if (0 < (int)height) {
              levelByteOffset = level * 0x18;
              faceByteOffset = face * 0x168;
              levelId = level & 0xffff;
              mappingOffset = (face * 0xd + level) * 0x20;
              scratchStackc4 = &srcBytesPerPixel;
              scratchStackc8 = &srcSkipBytes;
              faceId = face << 0x10;
              rowsDone = 0;
              scratchStackbc = &srcRowBytes;
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
                  scratchUint44 = *(int *)(ctx + GLD_dataRefillCount) + 1;
                  *(uint *)(ctx + GLD_dataRefillCount) = scratchUint44;
                  if (2 < scratchUint44) {
                    if (*(int *)(ctx + GLD_ringMap) + 0x28U < *(uint *)(ctx + GLD_writeCursor)) {
                      gld_submitRing(ctx,0x1000000);
                      dataCursorPtr = *(uint **)(ctx + GLD_dataCursor);
                    }
                    *(undefined4 *)(ctx + GLD_dataRefillCount) = 1;
                  }
                  *(int *)(*(int *)(ctx + GLD_contextBufferMap) + 0xc) =
                       (int)dataCursorPtr - *(int *)(ctx + GLD_dataBase) >> 2;
                  _io_connect_method_scalarI_scalarO
                            (*(undefined4 *)(ctx + GLD_connect),0x12,0,0,&scratchStack23c,scratchStackc8);
                  scratchUint44 = *(uint *)(GLD_updateFlags + ctx);
                  *(uint **)(ctx + GLD_dataBase) = scratchStack23c;
                  *(uint **)(ctx + GLD_dataCursor) = scratchStack23c;
                  *(undefined1 **)(ctx + GLD_dataLimit) =
                       (undefined1 *)((int)scratchStack23c + (srcRowBytes & 0xfffffffc));
                  scratchUint28 = *(undefined4 *)(*(int *)(ctx + GLD_contextBufferMap) + 8);
                  *(uint *)(GLD_updateFlags + ctx) = scratchUint44 | 1;
                  *(undefined4 *)(ctx + GLD_dataBufferId) = scratchUint28;
                  dataCursorPtr = scratchStack23c;
                }
                scratchStack1d0 = 0;
                scratchStack22c = (uint *)((uint)((int)dataCursorPtr + 0x7f) & 0xffffff80);
                *(uint **)(ctx + GLD_dataCursor) = scratchStack22c;
                scratchStack21c = 2;
                procHeight = chunkHeight;
                scratchStack234 = *(uint *)(levelRecord + 0x10) >> 0x1b;
                scratchStack204 = 0;
                scratchStack208 = 0;
                scratchStack214 = (undefined *)0x0;
                procFlags = 0;
                scratchStack230 = *(uint *)(levelRecord + 0x10) >> 0x16 & 0x1f;
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
                      scratchUint44 = 2;
                    }
                    else {
                      if (pixelType < (undefined *)0x8369) {
                        if ((undefined *)0x8366 < pixelType) goto LAB_00037c68;
                        if (pixelType < (undefined *)0x8363) goto LAB_00037c1c;
                      }
                      else if ((undefined *)((int)((unsigned char *)0x0) + 1) < pixelType + -0x85ba) {
LAB_00037c1c:
                        scratchUint44 = 0;
                        goto LAB_00037c6c;
                      }
LAB_00037c60:
                      scratchUint44 = 1;
                    }
LAB_00037c6c:
                    swapMode = swapMode ^ scratchUint44;
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
                procChannelFormat = scratchStack234;
                procChannelSize = scratchStack230;
                procWidth = width;
                scratchStack10c = scratchStack22c;
                gld_computePixelStoreLayout(ctx,pixelFormat,pixelType,width,height,scratchStackbc,scratchStackc4,
                             scratchStackc8,unpackState);
                srcRowBytesCopy = srcRowBytes;
                scratchStack23c = (uint *)(pixels + srcSkipBytes + rowsDone * srcRowBytes);
                if (swapMode == 2) {
                  a2 = (undefined *)(srcBytesPerPixel * procWidth);
                  if (0 < (int)procHeight) {
                    srcRow = scratchStack23c;
                    dstRow = scratchStack22c;
                    rowsLeft = procHeight;
                    do {
                      rowsLeft = rowsLeft - 1;
                      if (0 < (int)a2) {
                        scratchInt22 = ((uint)(a2 + -1) >> 2) + 1;
                        srcCursor = srcRow;
                        dstCursor = dstRow;
                        if ((int)(a2 + -4) < -3) {
                          scratchInt22 = 1;
                        }
                        do {
                          srcWord = *srcCursor;
                          srcCursor = srcCursor + 1;
                          *dstCursor = srcWord >> 0x18 | srcWord >> 8 & 0xff00 | (srcWord & 0xff00) << 8
                                     | srcWord << 0x18;
                          dstCursor = dstCursor + 1;
                          scratchInt22 = scratchInt22 + -1;
                        } while (scratchInt22 != 0);
                      }
                      srcRow = (uint *)((int)srcRow + srcRowBytes);
                      dstRow = (uint *)((int)dstRow + procPitch);
                    } while (0 < (int)rowsLeft);
                  }
                }
                else if (swapMode == 3) {
                  scratchInt22 = srcBytesPerPixel * procWidth;
                  if (0 < (int)procHeight) {
                    srcRow = scratchStack23c;
                    dstRow = scratchStack22c;
                    rowsLeft = procHeight;
                    do {
                      rowsLeft = rowsLeft - 1;
                      if (0 < scratchInt22) {
                        scratchInt45 = (scratchInt22 - 1U >> 2) + 1;
                        srcCursor = srcRow;
                        dstCursor = dstRow;
                        if (scratchInt22 + -4 < -3) {
                          scratchInt45 = 1;
                        }
                        do {
                          srcWord = *srcCursor;
                          srcCursor = srcCursor + 1;
                          *dstCursor = srcWord << 0x10 | srcWord >> 0x10;
                          dstCursor = dstCursor + 1;
                          scratchInt45 = scratchInt45 + -1;
                        } while (scratchInt45 != 0);
                      }
                      srcRow = (uint *)((int)srcRow + srcRowBytes);
                      dstRow = (uint *)((int)dstRow + procPitch);
                    } while (0 < (int)rowsLeft);
                  }
                }
                else if (swapMode == 1) {
                  scratchInt22 = srcBytesPerPixel * procWidth;
                  if (0 < (int)procHeight) {
                    srcRow = scratchStack23c;
                    dstRow = scratchStack22c;
                    rowsLeft = procHeight;
                    do {
                      rowsLeft = rowsLeft - 1;
                      if (0 < scratchInt22) {
                        scratchInt45 = (scratchInt22 - 1U >> 1) + 1;
                        srcCursor = srcRow;
                        dstCursor = dstRow;
                        if (scratchInt22 + -2 < -1) {
                          scratchInt45 = 1;
                        }
                        do {
                          scratchUint9 = *(ushort *)srcCursor;
                          srcCursor = (uint *)((int)srcCursor + 2);
                          *(ushort *)dstCursor = scratchUint9 >> 8 | scratchUint9 << 8;
                          dstCursor = (uint *)((int)dstCursor + 2);
                          scratchInt45 = scratchInt45 + -1;
                        } while (scratchInt45 != 0);
                      }
                      srcRow = (uint *)((int)srcRow + srcRowBytes);
                      dstRow = (uint *)((int)dstRow + procPitch);
                    } while (0 < (int)rowsLeft);
                  }
                }
                else {
                  rowBytesTotal = (undefined *)(srcBytesPerPixel * procWidth);
                  dstPitchCopy = procPitch;
                  srcRow = scratchStack23c;
                  dstRow = scratchStack22c;
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
                        scratchUint9 = *(ushort *)srcCursor;
                        bytesLeft = bytesLeft + -2;
                        srcCursor = (uint *)((int)srcCursor + 2);
                        *(ushort *)dstCursor = scratchUint9;
                        dstCursor = (uint *)((int)dstCursor + 2);
                      }
                      if ((undefined *)0x3 < bytesLeft) {
                        scratchInt45 = 0;
                        scratchInt22 = ((uint)(bytesLeft + -4) >> 2) + 1;
                        do {
                          bytesLeft = bytesLeft + -4;
                          *(undefined4 *)((int)dstCursor + scratchInt45) =
                               *(undefined4 *)((int)srcCursor + scratchInt45);
                          scratchInt45 = scratchInt45 + 4;
                          scratchInt22 = scratchInt22 + -1;
                        } while (scratchInt22 != 0);
                        dstCursor = (uint *)((int)dstCursor + scratchInt45);
                        srcCursor = (uint *)((int)srcCursor + scratchInt45);
                      }
                      if ((undefined *)0x1 < bytesLeft) {
                        scratchUint9 = *(ushort *)srcCursor;
                        bytesLeft = bytesLeft + -2;
                        srcCursor = (uint *)((int)srcCursor + 2);
                        *(ushort *)dstCursor = scratchUint9;
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
                dataOffset = (int)scratchStack10c - *(int *)(ctx + GLD_dataBase);
                *(int *)(ctx + GLD_dataCursor) = (int)scratchStack10c + chunkBytes;
                packet = (undefined4 *)
                          (**(code **)(ctx + GLD_streamAllocate))(commandStream,0x2a,a2,scratchStack10c,chunkBytes);
                scratchUint42 = 0;
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
                scratchUint26 = *(uint *)(levelRecord + 0x18);
                packet[0xf] = 0x56b;
                packet[0x11] = 0x56c;
                packet[0x10] = 0;
                packet[0x13] = 0x5c1;
                packet[0x12] = rowPitch;
                packet[0x14] = 0;
                packet[0x15] = 0x501;
                packet[0xe] = scratchUint26 >> 0xf & 0xf00 | 0x2cc30fb;
                if ((texture[0xd] == 0) || (*(char *)(texture[0xd] + 0x16) != '\x06')) {
                  levelMappingRecB = *texture + 0x40 + mappingOffset;
                  packet[0x16] = zOffset * *(int *)(levelMappingRecB + 0x14) + *(int *)(levelMappingRecB + 8);
                }
                else {
                  packet[0x16] = 0;
                }
                levelStateRecB = levelByteOffset + faceByteOffset + texture[0xc];
                levelHeightB = *(ushort *)(levelStateRecB + 0xa6);
                scratchUint44 = (uint)levelHeightB;
                levelWidthB = *(ushort *)(levelStateRecB + 0xa4);
                if (*(char *)(texture[0xc] + 0x6d) == '\0') {
                  if ((texture[0xd] == 0) || ((*(byte *)(texture[0xd] + 0x15) & 0x18) == 0)) {
                    scratchInt22 = 0x20;
                  }
                  else {
                    scratchInt22 = 0x20 / (1 << (*(uint *)(&DAT_001d9f4c +
                                                    (uint)*(byte *)(texture + 0xe) * 0x24) >> 0x1c &
                                          3));
                  }
                  bppShift = *(uint *)(levelRecord + 0x14) & 7;
                  scratchInt22 = scratchInt22 >> bppShift;
                  scratchInt22 = (((uint)levelWidthB + scratchInt22) - 1 & -scratchInt22) << bppShift;
                }
                else {
                  scratchInt22 = (uint)*(ushort *)((int)texture + 0x3e) << (*(uint *)(levelRecord + 0x14) & 7);
                }
                packet[0x18] = scratchInt22;
                scratchUint26 = 0;
                packet[0x17] = 0x502;
                packet[0x19] = 0x5c0;
                if (texture[0xd] != 0) {
                  scratchFlag46 = *(byte *)(texture[0xd] + 0x15);
                  scratchFlag19 = scratchFlag46 >> 3;
                  scratchUint26 = (scratchFlag19 & 3) << 1;
                  if ((scratchFlag46 & 4) != 0) {
                    scratchUint42 = level - *(byte *)(texture[0xc] + 0x69);
                    if ((scratchFlag19 & 3) == 0) {
                      scratchInt45 = 1;
                      scratchInt22 = 0x100;
                    }
                    else {
                      scratchInt45 = 1 << (*(uint *)(&DAT_001d9f4c + (uint)*(byte *)(texture + 0xe) * 0x24
                                              ) >> 0x1c & 3);
                      scratchInt22 = 0x20 / scratchInt45 << 3;
                    }
                    if ((scratchInt22 <= *(int *)(*texture + 0xc) >> (scratchUint42 & 0x3f)) &&
                       (scratchInt45 << 3 <= (int)(uint)*(ushort *)(*texture + 0x16) >> (scratchUint42 & 0x3f)))
                    {
                      scratchUint26 = scratchUint26 | 1;
                    }
                  }
                }
                packet[0x1a] = scratchUint26;
                packet[0x1b] = 0x5bb;
                packet[0x1d] = 0x5bc;
                packet[0x1e] = CONCAT22(levelHeightB,levelWidthB);
                packet[0x1c] = 0;
                scratchUint26 = *(uint *)(levelRecord + 0x18) >> 0x17 & 0x1f;
                if ((scratchUint26 < 3) || ((scratchInt22 = 1, 4 < scratchUint26 && (scratchInt22 = 2, scratchUint26 != 6)))) {
                  scratchInt22 = 0;
                }
                scratchUint35 = (*(uint *)(levelRecord + 0x14) & 7) - scratchInt22;
                levelArg = 0;
                scratchUint21 = (rowsDone + yOffset) * 0x10000 | xOffset << (scratchUint35 & 0x3f) & 0xffff;
                packet[0x24] = 0xd0b;
                packet[0x22] = chunkHeight << 0x10 | width << (scratchUint35 & 0x3f) & 0xffff;
                packet[0x1f] = 0x50e;
                packet[0x20] = scratchUint21;
                packet[0x21] = 0x50f;
                packet[0x23] = 0x80000000;
                packet[0x26] = 0x5c8;
                packet[0x29] = 0;
                packet[0x25] = 5;
                packet[0x28] = ((unsigned char *)0x00001040U);
                packet[0x27] = 0x10000;
                *(undefined4 **)(ctx + GLD_streamCurrent) = packet + 0x2a;
                (**(code **)(ctx + GLD_streamSetCurrent))
                          (commandStream,packet + 0x2a,a2,0,scratchUint44,scratchUint42,scratchUint21,packet + 0x24);
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
            scratchStacka8 = IrInt2F__dtor;
            scratchStack9c = 0x1e6a08;
            levelByteOffset = level * 0x18;
            faceByteOffset = face * 0x168;
            mappingOffsetB = (face * 0xd + level) * 0x20;
            widthMask = width - 1 & 0x7ff;
            levelFaceWord = level | face << 0x10;
            scratchStackc4 = &srcBytesPerPixel;
            scratchStackb8 = &scratchStack234;
            scratchStackc8 = &srcSkipBytes;
            scratchStackc0 = &scratchStack23c;
            scratchStackbc = &srcRowBytes;
            scratchStackd0 = IrInt2F__dtor;
            scratchStackb4 = &scratchStack230;
            scratchStackd4 = IrInt2F__dtor;
            scratchStackb0 = IrInt2F__dtor;
            xBeginF = (float)((double)CONCAT44(0x43300000,xoffsetI2dLo) - 4503601774854144.0);
            xEndF = (float)((double)CONCAT44(0x43300000,xEndI2dLo) - 4503601774854144.0);
            scratchInt22 = (int)((xEndF - xBeginF) * 6.0);
            fctiwzSlot11 = (longlong)scratchInt22;
            scratchStack108 = scratchInt22 << 0x10;
            rowStart = 0;
            do {
              rowEndB = rowStart + chunkRows;
              lastChunkB = rowEndB < (int)height;
              scratchUint42 = chunkRows;
              if ((int)height < rowEndB) {
                scratchUint42 = height - rowStart;
              }
              rowPitchB = (width << (*(uint *)(levelRecord + 0x14) & 7)) + 0x23 & 0xffffffe0;
              packet = (undefined4 *)
                        (**(code **)(ctx + GLD_streamAllocate))(commandStream,(rowPitchB * scratchUint42 >> 2) + 0x193);
              scratchStackfc = packet + 1;
              *(undefined4 **)(ctx + GLD_streamCurrent) = packet;
              lastHeader = *(uint **)(ctx + GLD_lastHeader);
              scratchUint28 = *(undefined4 *)(scratchStack9c + 0x1ec8);
              levelStateRec = levelByteOffset + faceByteOffset + texture[0xc];
              levelHeight = (uint)*(ushort *)(levelStateRec + 0xa6);
              levelWidthC = *(ushort *)(levelStateRec + 0xa4);
              *lastHeader = (int)packet - (int)lastHeader >> 2 | *lastHeader;
              *(undefined4 **)(ctx + GLD_lastHeader) = packet;
              *packet = 0x35000000;
              packet[2] = levelFaceWord;
              _memcpy(packet + 3,scratchUint28,0x2f4);
              scratchUint44 = *(uint *)(levelRecord + 0x18);
              packet[0xa9] = (scratchUint42 - 1) * 0x800 & 0x3ff800 | widthMask | 0x80000000;
              packet[0xa3] = scratchUint44 >> 0x1e | packet[0xa3] & 0xfffffffc;
              scratchUint44 = *(uint *)(((unsigned char *)0x00003c14) +
                                (int)(scratchStackd0 + (*(uint *)(levelRecord + 0x14) & 7) * 4));
              packet[0xab] = scratchUint44 & 0x1f | 0xa600;
              scratchUint24 = *(uint *)(levelRecord + 0x14);
              if ((scratchUint24 & 7) == 0) {
                packet[0xab] = scratchUint44 & 0x1f | 0x8600;
                scratchUint24 = *(uint *)(levelRecord + 0x14);
              }
              packet[0xad] =
                   (uint)(0x800 < (int)scratchUint42) << 0x10 |
                   (uint)(0x800 < (int)width) << 0xf | (rowPitchB >> (scratchUint24 & 7)) - 1 & 0x3fff;
              packet[0x8d] =
                   *(uint *)(scratchStackd4 + (*(uint *)(levelRecord + 0x14) & 7) * 4 + 0x3c00) & 0x1f |
                   packet[0x8d] & 0xffffffe0;
              scratchInt45 = texture[0xd];
              if ((scratchInt45 == 0) || ((*(byte *)(scratchInt45 + 0x15) & 0x18) == 0)) {
                alignPixels = 0x20;
              }
              else {
                alignPixels = 0x20 / (1 << (*(uint *)(((unsigned char *)0x00003544) +
                                                (int)(scratchStacka8 +
                                                     (uint)*(byte *)(texture + 0xe) * 0x24)) >> 0x1c
                                      & 3));
              }
              alignPixels = alignPixels >> (*(uint *)(levelRecord + 0x14) & 7);
              if ((scratchInt45 == 0) || (*(char *)(scratchInt45 + 0x16) != '\x06')) {
                scratchUint44 = 0;
                levelMappingRec = *texture + 0x40 + mappingOffsetB;
                levelMappingRec = zOffset * *(int *)(levelMappingRec + 0x14) + *(int *)(levelMappingRec + 8);
              }
              else {
                levelMappingRec = 0;
                scratchUint44 = *(uint *)(levelRecord + 0x18) >> 0xb & 0x180000;
              }
              packet[0x9d] = levelMappingRec;
              if (*(char *)(texture[0xc] + 0x6d) != '\0') {
                levelWidthC = *(ushort *)((int)texture + 0x3e);
              }
              scratchInt45 = texture[0xd];
              alignedPitchPixels = ((uint)levelWidthC + alignPixels) - 1 & -alignPixels;
              if ((scratchInt45 == 0) || ((*(byte *)(scratchInt45 + 0x15) & 4) == 0)) {
LAB_00038698:
                tiledFlag = 0;
              }
              else {
                scratchUint35 = level - *(byte *)(texture[0xc] + 0x69);
                if ((*(byte *)(scratchInt45 + 0x15) & 0x18) == 0) {
                  scratchInt20 = 1;
                  tiledFlag = 0x100;
                }
                else {
                  scratchInt20 = 1 << (*(uint *)(((unsigned char *)0x00003544) +
                                          (int)(scratchStacka8 + (uint)*(byte *)(texture + 0xe) * 0x24))
                                 >> 0x1c & 3);
                  tiledFlag = 0x20 / scratchInt20 << 3;
                }
                if ((*(int *)(*texture + 0xc) >> (scratchUint35 & 0x3f) < tiledFlag) ||
                   (tiledFlag = 1,
                   (int)(uint)*(ushort *)(*texture + 0x16) >> (scratchUint35 & 0x3f) < scratchInt20 << 3))
                goto LAB_00038698;
              }
              if (((*(uint *)(levelRecord + 0x18) & 0x30000000) == 0) || (scratchInt45 == 0)) {
                scratchUint35 = 0;
              }
              else {
                scratchUint35 = (*(byte *)(scratchInt45 + 0x15) & 0x18) << 0xe;
              }
              scratchUint21 = *(uint *)(((unsigned char *)0x00003bec) +
                                (int)(scratchStackb0 + (*(uint *)(levelRecord + 0x14) & 7) * 4));
              yStartI2dLo = rowStart + yOffset ^ 0x80000000;
              yEndI2dLo = scratchUint42 + rowStart + yOffset ^ 0x80000000;
              packet[0xb6] = alignedPitchPixels - 1 & 0x1fff | (levelHeight - 1) * 0x2000 & 0x3ffe000;
              packetEndA = packet + 0xcc;
              packet[0x9f] =
                   scratchUint35 | alignedPitchPixels & 0x3ffe | tiledFlag << 0x10 | scratchUint44 | (scratchUint21 & 0xf) << 0x15;
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
              scratchUint44 = (uint)(int)((yEndF - yBeginF) * 6.0);
              fctiwzSlot10 = (longlong)(int)scratchUint44;
              packet[199] = 0xc0033500;
              packet[200] = 0x10031;
              packet[0xca] = (yBeginF + yEndF) * 0.5;
              packet[0xc9] = (xEndF + xBeginF) * 0.5;
              packet[0xcb] = 0;
              packet[0xc6] = scratchUint44 | scratchStack108;
              *scratchStackfc = (int)packetEndA - (int)packet >> 2;
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
                            (int)(scratchStacka8 + (uint)(byte)((unsigned char *)GLD_colorFormatIndex)[ctx] * 0x24 + 0x18))
                  & 0x8000) == 0) {
                packet[0xfe] = fg_fog_blendC & 0xfffffffe;
              }
              packet[0xff] = ((unsigned char *)0x000012f5U);
              fg_alpha_func = *(uint *)(ctx + GLD_fg_alpha_func);
              packet[0x100] = fg_alpha_func;
              if ((*(uint *)(((unsigned char *)0x0000352c) +
                            (int)(scratchStacka8 + (uint)(byte)((unsigned char *)GLD_colorFormatIndex)[ctx] * 0x24 + 0x18))
                  & 0x8000) == 0) {
                packet[0x100] = fg_alpha_func & 0xfffff7ff;
              }
              packet[0x101] = ((unsigned char *)0x000010a2U);
              ga_poly_mode = *(undefined4 *)(ctx + GLD_ga_poly_mode);
              packet[0x103] = ((unsigned char *)0x00001381U);
              packet[0x102] = ga_poly_mode;
              scratchUint44 = *(uint *)(ctx + GLD_rb3d_blendcntl);
              packet[0x104] = scratchUint44;
              if ((*(uint *)(((unsigned char *)0x0000352c) +
                            (int)(scratchStacka8 + (uint)(byte)((unsigned char *)GLD_colorFormatIndex)[ctx] * 0x24 + 0x18))
                  & 0x4000) == 0) {
                packet[0x104] = scratchUint44 & 0xfffffffc;
              }
              packet[0x105] = ((unsigned char *)0x0000109eU);
              scratchUint28 = *(undefined4 *)(ctx + 0x1d6c);
              packet[0x107] = ((unsigned char *)0x00001096U);
              packet[0x106] = scratchUint28;
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
              scratchUint44 = 0x80000000;
              packet[0xa3] = ((int)alignedPtr - (int)packet) * 8 & 0xffffffe0U | packet[0xa3] & 0x1f
              ;
              rowWords = ((int)((width << (*(uint *)(levelRecord + 0x14) & 7)) + 3) >> 2) +
                       ((int)alignedPtr - (int)packetWrite >> 2);
              if (rowWords != 1) {
                scratchUint44 = (rowWords + -2) * 0x10000 | 0xc0001000;
              }
              *packetWrite = scratchUint44;
              packetWrite = packetWrite + rowWords;
              if (1 < (int)scratchUint42) {
                scratchUint44 = rowPitchB >> 2;
                headerRowsLeft = scratchUint42 - 1;
                do {
                  if (scratchUint44 == 1) {
                    scratchUint24 = 0x80000000;
                  }
                  else {
                    scratchUint24 = (scratchUint44 - 2) * 0x10000 | 0xc0001000;
                  }
                  *packetWrite = scratchUint24;
                  packetWrite = packetWrite + scratchUint44;
                  headerRowsLeft = headerRowsLeft + -1;
                } while (headerRowsLeft != 0);
              }
              procChannelFormat = *(uint *)(levelRecord + 0x10) >> 0x1b;
              scratchShort8 = *(short *)(texture[0xc] + 0x1a);
              scratchShort11 = *(short *)(texture[0xc] + 2);
              scratchStack204 = 0;
              procFlags = 0;
              scratchStack214 = ((unsigned char *)0x0007efffU);
              scratchStack208 = 0;
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
              scratchUint44 = height;
              scratchPtr37 = scratchStackbc;
              scratchPtr36 = scratchStackc8;
              scratchPtr38 = scratchStackc4;
              procPitch = rowPitchB;
              gld_computePixelStoreLayout(ctx,pixelFormat,pixelType,width,height,scratchStackbc,scratchStackc8,
                           scratchStackc4,unpackState);
              scratchPtr33 = scratchStackb8;
              _glgConvertType(pixelFormat,pixelType,scratchStackb8,scratchStackb4,scratchUint44,scratchPtr37,scratchPtr36,scratchPtr38
                             );
              if ((((scratchShort11 != 0x1908) && (scratchShort8 != -0x7a43)) && (scratchShort11 != 0x1906)) &&
                 ((scratchShort11 != 0x190a &&
                  ((0x15 < procChannelFormat || ((1 << (procChannelFormat & 0x3f) & 0x3ff707U) == 0)))))) {
                procFlags = procFlags | 0x8000;
              }
              scratchStack21c = 2;
              scratchStack1d0 = 0;
              scratchStack23c = (uint *)(pixels + srcBytesPerPixel + rowStart * srcRowBytes);
              levelArg = pixels;
              scratchStack22c = alignedPtr;
              procWidth = width;
              procHeight = scratchUint42;
              _glgProcessPixels(((unsigned char *)0x00002e48) + *(int *)(ctx + GLD_engineState),scratchStackc0,scratchPtr33,
                                pixels,scratchUint44,scratchPtr37,rowStart * srcRowBytes,scratchPtr38);
              *(uint **)(ctx + GLD_streamCurrent) = packetWrite;
              (**(code **)(ctx + GLD_streamSetCurrent))(commandStream,packetWrite);
              rowStart = rowEndB;
            } while (lastChunkB);
          }
          scratchUint28 = (**(code **)(ctx + GLD_streamAllocate))(commandStream,0xe0);
          *(undefined4 *)(ctx + GLD_streamCurrent) = scratchUint28;
          scratchUint28 = ((int (*)())gld_emitBoundUnitObjects)(ctx,scratchUint28);
          *(undefined4 *)(ctx + GLD_streamCurrent) = scratchUint28;
          (**(code **)(ctx + GLD_streamSetCurrent))(commandStream,scratchUint28);
          _pthread_mutex_unlock(*(undefined4 *)(ctx + GLD_mutex));
          if ((*(uint *)(texture[0xc] + 0x48) & 0x8000) == 0) {
            return 1;
          }
          if (level != *(byte *)(texture[0xc] + 0x5e)) {
            return 1;
          }
          ((int (*)())glGenerateMipmap_impl)(ctx,texture,face,levelArg,scratchUint44);
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
  sizeOutPtr = &scratchStack248;
  gld_computePixelStoreLayout(ctx,pixelFormat,pixelType,width,height,sizeOutPtr,&srcBytesPerPixel,&srcSkipBytes,
               ((unsigned char *)0x00002e6c) + *(int *)(ctx + GLD_engineState));
  sourceBase = *(int *)*sourceSurface;
  srcData = pixels + srcSkipBytes;
  if (0x1000 < (int)scratchStack248 >> (srcBytesPerPixel & 0x3f)) {
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
  scratchInt22 = face;
  levelRecordB = ((int (*)())gldTextureFormatEntryForLevel)(ctx,texture,face,level,0);
  if ((levelRecordB == 0) || ((*(uint *)(levelRecordB + 0x18) & 0x10000) == 0)) goto LAB_00037930;
  levelOffset = levelOffset + texture[0xc];
  levelWidth = (uint)*(ushort *)(levelOffset + 0xa4);
  scratchUint42 = (uint)*(ushort *)(levelOffset + 0xa6);
  if (levelWidth == 0) {
    scratchFloat4 = 1.0;
    levelWidth = 1;
  }
  else {
    scratchStack1c8 = 0x43300000;
    scratchStack1c4 = levelWidth ^ 0x80000000;
    scratchFloat4 = (float)((double)CONCAT44(0x43300000,scratchStack1c4) - 4503601774854144.0);
  }
  if (scratchUint42 == 0) {
    scratchUint42 = 1;
    scratchFloat5 = 1.0;
  }
  else {
    scratchStack1bc = scratchUint42 ^ 0x80000000;
    scratchStack1c0 = 0x43300000;
    scratchFloat5 = (float)((double)CONCAT44(0x43300000,scratchStack1bc) - 4503601774854144.0);
  }
  xoffsetI2dLoB = xOffset ^ 0x80000000;
  widthI2dLoB = width ^ 0x80000000;
  xoffsetI2dHiB = 0x43300000;
  yoffsetI2dLoB = yOffset ^ 0x80000000;
  heightI2dHiB = 0x43300000;
  yoffsetI2dHiB = 0x43300000;
  widthI2dHiB = 0x43300000;
  heightI2dLoB = height ^ 0x80000000;
  scratchFloat6 = 0.0;
  xoffsetF = (float)((double)CONCAT44(0x43300000,xoffsetI2dLoB) - 4503601774854144.0);
  yoffsetF = (float)((double)CONCAT44(0x43300000,yoffsetI2dLoB) - 4503601774854144.0);
  scratchFloat7 = xoffsetF + 0.0;
  scratchFloat16 = yoffsetF + 0.0;
  scratchFloat17 = (float)((double)CONCAT44(0x43300000,heightI2dLoB) - 4503601774854144.0) + yoffsetF;
  scratchFloat14 = (float)((double)CONCAT44(0x43300000,widthI2dLoB) - 4503601774854144.0) + xoffsetF;
  scratchFloat15 = scratchFloat7;
  if (0.0 < scratchFloat7) {
    scratchFloat15 = xoffsetF + scratchFloat7;
    scratchFloat6 = scratchFloat7;
  }
  scratchFloat7 = 0.0;
  if (0.0 < scratchFloat16) {
    scratchFloat7 = scratchFloat16;
    scratchFloat16 = yoffsetF + scratchFloat16;
  }
  scratchFloat12 = scratchFloat14 - scratchFloat4;
  scratchFloat18 = scratchFloat17 - scratchFloat5;
  scratchFloat13 = scratchFloat4;
  if (scratchFloat12 < 0.0) {
    scratchFloat13 = scratchFloat14;
  }
  scratchFloat14 = scratchFloat5;
  if (scratchFloat18 < 0.0) {
    scratchFloat14 = scratchFloat17;
  }
  if (-scratchFloat12 < 0.0) {
    scratchFloat13 = scratchFloat4;
  }
  if (-scratchFloat18 < 0.0) {
    scratchFloat14 = scratchFloat5;
  }
  if ((scratchFloat13 <= scratchFloat6) || (scratchFloat14 <= scratchFloat7)) {
    _pthread_mutex_unlock(*(undefined4 *)(ctx + GLD_mutex));
    return 1;
  }
  if (((((*(byte *)((int)texture + 0x39) & 7) != 0) &&
       (scratchInt22 = ((int (*)())gldTextureMakeResident)(ctx,texture,scratchInt22,*(byte *)((int)texture + 0x39) & 7,"",sizeOutPtr),
       scratchInt22 == 0)) ||
      ((*(int *)sourceSurface[1] != 0 && (scratchInt22 = gld_prepareBufferBacking(ctx,sourceSurface,1), scratchInt22 == 0)))) ||
     (((int *)sourceSurface[2] == (int *)0x0 || (scratchInt22 = *(int *)sourceSurface[2], scratchInt22 == 0))))
  goto LAB_00037930;
  if (*(char *)(scratchInt22 + 0x16) != '\x06') {
    if (pixelFormat == 0x1908) {
      if (pixelType != ((unsigned char *)0x00001406)) goto LAB_00037930;
    }
    else if ((pixelFormat != 0x80e1) || (pixelType != (undefined *)0x8367)) goto LAB_00037930;
  }
  scratchStacka8 = IrInt2F__dtor;
  scratchInt22 = (srcHwFormat & 0xff) * 0x24;
  alignedOk = ((srcData | scratchStack248) & 0x1f) == 0;
  scratchFlag46 = alignedOk << 1;
  if (!alignedOk) goto LAB_00037930;
  commandStreamB = ctx + GLD_commandStream;
  scratchUint28 = (**(code **)(ctx + GLD_streamAllocate))(commandStreamB,0x343);
  *(undefined4 *)(ctx + GLD_streamCurrent) = scratchUint28;
  scratchPtr29 = (uint *)((int (*)())FUN_00030840)(ctx,scratchUint28,texture);
  texPacket = (undefined4 *)((uint)(scratchPtr29 + 0xb) & 0xffffffe0);
  *scratchPtr29 = (((int)texPacket - (int)scratchPtr29) + -8) * 0x4000 | 0xc0001000;
  texPacket[-1] = (int)texPacket - (int)scratchPtr29;
  lastHeader = *(uint **)(ctx + GLD_lastHeader);
  *lastHeader = (int)texPacket - (int)lastHeader >> 2 | *lastHeader;
  *(undefined4 **)(ctx + GLD_lastHeader) = texPacket;
  *texPacket = 0x3e000000;
  surfaceObjectRef = *(undefined4 **)sourceSurface[2];
  surfaceRefPtr = surfaceObjectRef + 4;
  do {
    if (reservation != '\0') {
      scratchInt20 = storeWordConditionalIndexed(*surfaceRefPtr + 0x10000,0,surfaceRefPtr);
      *surfaceRefPtr = scratchInt20;
      scratchFlag46 = 2;
    }
    hwContextTemplate = PTR_DAT_001e88d0;
  } while (!(bool)(scratchFlag46 >> 1 & 1));
  texPacket[2] = *surfaceObjectRef;
  scratchInt20 = *(int *)*sourceSurface;
  texPacket[4] = level | face << 0x10;
  texPacket[3] = srcData - scratchInt20;
  _memcpy(texPacket + 5,hwContextTemplate,0x2f4);
  scratchInt20 = texture[0xd];
  if ((scratchInt20 == 0) || ((*(byte *)(scratchInt20 + 0x15) & 0x18) == 0)) {
    scratchInt34 = 0x20;
  }
  else {
    scratchInt34 = 0x20 / (1 << (*(uint *)(&DAT_001d9f4c + (uint)*(byte *)(texture + 0xe) * 0x24) >> 0x1c
                          & 3));
  }
  scratchInt34 = scratchInt34 >> (*(uint *)(levelRecordB + 0x14) & 7);
  if ((scratchInt20 == 0) || (scratchInt32 = 0, *(char *)(scratchInt20 + 0x16) != '\x06')) {
    scratchInt20 = *texture + 0x40 + (face * 0xd + level) * 0x20;
    scratchInt32 = zOffset * *(int *)(scratchInt20 + 0x14) + *(int *)(scratchInt20 + 8);
  }
  if (*(char *)(texture[0xc] + 0x6d) == '\0') {
    scratchUint26 = (levelWidth + scratchInt34) - 1 & -scratchInt34;
  }
  else {
    scratchUint26 = (uint)*(ushort *)((int)texture + 0x3e);
  }
  scratchFloat4 = (scratchFloat13 + xoffsetF) - scratchFloat15;
  scratchFloat5 = (scratchFloat14 + yoffsetF) - scratchFloat16;
  scratchFloat17 = scratchFloat4 - 1.0;
  texPacket[0xa5] = *(uint *)(&DAT_001d9f4c + scratchInt22) >> 0x1e | texPacket[0xa5] & 0xfffffffc;
  if (2.1474836e+09 <= scratchFloat17) {
    fctiwzSlot1 = (longlong)(int)(scratchFloat17 - 2.1474836e+09);
    scratchUint24 = (int)(scratchFloat17 - 2.1474836e+09) + 0x80000000;
  }
  else {
    scratchUint24 = (uint)(int)scratchFloat17;
    fctiwzSlot0 = (longlong)(int)scratchUint24;
  }
  scratchFloat17 = scratchFloat5 - 1.0;
  if (2.1474836e+09 <= scratchFloat17) {
    fctiwzSlot3 = (longlong)(int)(scratchFloat17 - 2.1474836e+09);
    scratchUint35 = (int)(scratchFloat17 - 2.1474836e+09) + 0x80000000;
  }
  else {
    scratchUint35 = (uint)(int)scratchFloat17;
    fctiwzSlot2 = (longlong)(int)scratchUint35;
  }
  texPacket[0xab] = scratchUint24 & 0x7ff | (scratchUint35 & 0x7ff) << 0xb | 0x80000000;
  scratchUint24 = *(uint *)(&DAT_001d9f50 + scratchInt22);
  scratchUint35 = *(uint *)(&DAT_001d9f54 + scratchInt22);
  texPacket[0xad] =
       scratchUint24 >> 7 & 0x1f | scratchUint35 >> 3 & 0x400000 | (scratchUint24 & 0x70) << 5 | (scratchUint24 & 0xe) << 0xb |
       scratchUint35 >> 0xe & 0x38000 | scratchUint35 >> 8 & 0x1c0000;
  scratchUint24 = *(uint *)(&DAT_001d9f48 + scratchInt22);
  if (2.1474836e+09 <= scratchFloat4) {
    fctiwzSlot5 = (longlong)(int)(scratchFloat4 - 2.1474836e+09);
    scratchInt22 = (int)(scratchFloat4 - 2.1474836e+09) + -0x80000000;
  }
  else {
    scratchInt22 = (int)scratchFloat4;
    fctiwzSlot4 = (longlong)scratchInt22;
  }
  if (2.1474836e+09 <= scratchFloat5) {
    fctiwzSlot7 = (longlong)(int)(scratchFloat5 - 2.1474836e+09);
    scratchInt20 = (int)(scratchFloat5 - 2.1474836e+09) + -0x80000000;
  }
  else {
    scratchInt20 = (int)scratchFloat5;
    fctiwzSlot6 = (longlong)scratchInt20;
  }
  texPacket[0x9f] = scratchInt32;
  texPacket[0xaf] =
       ((int)scratchStack248 >> (scratchUint24 & 7)) - 1U & 0x3fff | (scratchInt22 + -1) * 0x10 & 0xffff8000U |
       (scratchInt20 + -1) * 0x20 & 0xffff0000U;
  texPacket[0xa5] = (srcData - sourceBase) * 0x20 | texPacket[0xa5] & 0x1f;
  storageRecord = texture[0xd];
  if ((storageRecord != 0) && ((*(byte *)(storageRecord + 0x15) & 4) != 0)) {
    scratchUint44 = level - *(byte *)(texture[0xc] + 0x69);
    if ((*(byte *)(storageRecord + 0x15) & 0x18) == 0) {
      scratchInt20 = 1;
      scratchInt22 = 0x100;
    }
    else {
      scratchInt20 = 1 << (*(uint *)(((unsigned char *)0x00003544) +
                              (int)(scratchStacka8 + (uint)*(byte *)(texture + 0xe) * 0x24)) >> 0x1c & 3
                    );
      scratchInt22 = 0x20 / scratchInt20 << 3;
    }
    if ((scratchInt22 <= *(int *)(*texture + 0xc) >> (scratchUint44 & 0x3f)) &&
       (scratchInt22 = 1, scratchInt20 << 3 <= (int)(uint)*(ushort *)(*texture + 0x16) >> (scratchUint44 & 0x3f)))
    goto LAB_000371ac;
  }
  scratchInt22 = 0;
LAB_000371ac:
  if (storageRecord != 0) {
    scratchUint44 = (*(byte *)(storageRecord + 0x15) & 0x18) << 0xe;
  }
  else {
    scratchUint44 = 0;
  }
  scratchUint21 = texPacket[0x8f];
  texPacket[0xa1] =
       scratchUint44 | scratchUint26 & 0x3ffe | scratchInt22 << 0x10 | *(uint *)(levelRecordB + 0x18) >> 0xb & 0x180000 |
       (*(uint *)(levelRecordB + 0x18) & 0x3c00) << 0xb;
  scratchUint26 = (*(uint *)(levelRecordB + 0x18) & 0x18) << 5;
  texPacket[0x8f] = scratchUint26 | scratchUint21 & 0xfffffcff;
  scratchUint44 = (*(uint *)(levelRecordB + 0x18) & 6) << 9;
  texPacket[0x8f] = scratchUint44 | scratchUint26 | scratchUint21 & 0xfffff0ff;
  scratchUint24 = *(uint *)(levelRecordB + 0x1c) >> 0x12 & 0x3000;
  texPacket[0x8f] = scratchUint24 | scratchUint44 | scratchUint26 | scratchUint21 & 0xffffc0ff;
  scratchUint35 = *(uint *)(levelRecordB + 0x1c) >> 0xe & 0xc000;
  texPacket[0x8f] = scratchUint35 | scratchUint24 | scratchUint44 | scratchUint26 | scratchUint21 & 0xffff00ff;
  texPacket[0x8f] =
       *(uint *)(levelRecordB + 0x18) >> 5 & 0x1f |
       scratchUint35 | scratchUint24 | scratchUint44 | scratchUint26 | scratchUint21 & 0xffff00e0;
  scratchShort8 = *(short *)(textureState + 2);
  if (((scratchShort8 != 0x1908) && (scratchShort8 != 0x1906)) && (scratchShort8 != 0x190a)) {
    texPacket[0x5b] = texPacket[0x5b] & 0xfffe3fff | 0x18000;
  }
  texPacket[0xb8] = levelWidth - 1 & 0x1fff | (scratchUint42 - 1) * 0x2000 & 0x3ffe000;
  if ((*(uint *)(levelRecordB + 0x20) & 0x400000) != 0) {
    texPacket[0x23] = 0;
  }
  packetEndB = texPacket + 0xce;
  texPacket[199] = ((unsigned char *)0x00001087U);
  texPacket[0xc2] = 0x31080;
  texPacket[0xc6] = (1.0 / scratchFloat5) * scratchFloat16;
  scratchInt43 = (int)((scratchFloat13 - scratchFloat6) * 6.0);
  fctiwzSlot8 = (longlong)scratchInt43;
  texPacket[0xc5] = (scratchFloat13 + xoffsetF) * (1.0 / scratchFloat4);
  texPacket[0xc3] = scratchFloat15 * (1.0 / scratchFloat4);
  texPacket[0xc4] = (scratchFloat14 + yoffsetF) * (1.0 / scratchFloat5);
  scratchUint26 = (uint)(int)((scratchFloat14 - scratchFloat7) * 6.0);
  fctiwzSlot9 = (longlong)(int)scratchUint26;
  texPacket[0xca] = 0x10031;
  texPacket[0xc9] = 0xc0033500;
  texPacket[0xcb] = (scratchFloat6 + scratchFloat13) * 0.5;
  texPacket[0xcc] = (scratchFloat7 + scratchFloat14) * 0.5;
  texPacket[0xcd] = 0;
  texPacket[200] = scratchInt43 << 0x10 | scratchUint26;
  texPacket[1] = (int)packetEndB - (int)scratchPtr29 >> 2;
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
                (int)(scratchStacka8 + (uint)(byte)((unsigned char *)GLD_colorFormatIndex)[ctx] * 0x24 + 0x18)) & 0x8000) ==
      0) {
    texPacket[0x100] = fg_fog_blend & 0xfffffffe;
  }
  texPacket[0x101] = ((unsigned char *)0x000012f5U);
  fg_alpha_func = *(uint *)(ctx + GLD_fg_alpha_func);
  texPacket[0x102] = fg_alpha_func;
  scratchUint26 = *(uint *)(((unsigned char *)0x0000352c) +
                    (int)(scratchStacka8 + (uint)(byte)((unsigned char *)GLD_colorFormatIndex)[ctx] * 0x24 + 0x18)) & 0x8000
  ;
  if (scratchUint26 == 0) {
    texPacket[0x102] = fg_alpha_func & 0xfffff7ff;
  }
  texPacket[0x103] = ((unsigned char *)0x000010a2U);
  ga_poly_mode = *(undefined4 *)(ctx + GLD_ga_poly_mode);
  texPacket[0x105] = ((unsigned char *)0x00001381U);
  texPacket[0x104] = ga_poly_mode;
  scratchUint44 = *(uint *)(ctx + GLD_rb3d_blendcntl);
  texPacket[0x106] = scratchUint44;
  if ((*(uint *)(((unsigned char *)0x0000352c) +
                (int)(scratchStacka8 + (uint)(byte)((unsigned char *)GLD_colorFormatIndex)[ctx] * 0x24 + 0x18)) & 0x4000) ==
      0) {
    texPacket[0x106] = scratchUint44 & 0xfffffffc;
  }
  texPacket[0x107] = ((unsigned char *)0x0000109eU);
  scratchUint31 = 0x110f8;
  scratchUint28 = *(undefined4 *)(ctx + 0x1d6c);
  texPacket[0x109] = ((unsigned char *)0x00001096U);
  texPacket[0x108] = scratchUint28;
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
  scratchUint28 = ((int (*)())gld_emitBoundUnitObjects)(ctx,texPacket + 0x18d);
  *(undefined4 *)(ctx + GLD_streamCurrent) = scratchUint28;
  (**(code **)(ctx + GLD_streamSetCurrent))(commandStreamB,scratchUint28);
  _pthread_mutex_unlock(*(undefined4 *)(ctx + GLD_mutex));
  if (((*(uint *)(texture[0xc] + 0x48) & 0x8000) != 0) &&
     (level == *(byte *)(texture[0xc] + 0x5e))) {
    ((int (*)())glGenerateMipmap_impl)(ctx,texture,face,scratchUint26,scratchUint31);
    return 1;
  }
  return 1;
}

/* gld_testRendererAvailable @ 0x39100 (188 bytes) */
int gld_testRendererAvailable(rendererIndex)
  int rendererIndex;
{
  undefined4 uVar1;
  int scratchInt2;
  undefined4 local_38;
  undefined4 local_34;
  undefined1 auStack_30 [44];
  
  local_38 = 0;
  local_34 = 3;
  scratchInt2 = _IOServiceOpen(*(undefined4 *)(rendererIndex * 4 + *(int *)(PTR_DAT_001e88ac + 8)),
                         *(undefined4 *)PTR_001e88b4,1,&local_38);
  uVar1 = 0;
  if (scratchInt2 == 0) {
    scratchInt2 = _io_connect_method_scalarI_scalarO(local_38,3,0,0,auStack_30,&local_34);
    if (scratchInt2 == 0) {
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
int FUN_0003b160(ctx, dirtyBits, passThroughResult)
  int ctx;
  int dirtyBits;
  undefined4 passThroughResult;
{
  int constantBank;
  int programRecord;
  int programHeader;
  uint updateFlags;
  int *currentProgram;
  
  currentProgram = *(int **)(ctx + 0x1cc);
  if ((dirtyBits == 0) || (updateFlags = 0, (*(uint *)(dirtyBits + 0xc) & 0x4400000) != 0)) {
    updateFlags = 2;
  }
  if ((currentProgram != (int *)0x0) &&
     (((dirtyBits == 0 || ((*(uint *)(dirtyBits + 8) & 0xff00) != 0)) ||
      ((*(uint *)(dirtyBits + 0xc) & 0x4c00000) != 0)))) {
    updateFlags = updateFlags | 1;
  }
  FUN_00053000(ctx + 0x240,updateFlags);
  constantBank = *(int *)(ctx + 0x29e8) + 0x14;
  if ((updateFlags & 1) != 0) {
    programRecord = currentProgram[0xd];
    if (((programRecord == 0) && (programRecord = currentProgram[0xc], programRecord == 0)) && (programRecord = currentProgram[0xb], programRecord == 0)) {
      programHeader = *currentProgram;
      programRecord = *(int *)(programHeader + 4);
    }
    else {
      programHeader = *currentProgram;
    }
    if ((updateFlags & 2) == 0) {
      ((int (*)())gld_emitProgramConstantUpdates)(ctx,constantBank,*(undefined4 *)(programRecord + 0x28),programRecord + *(int *)(programRecord + 0x2c) * 8,
                   *(undefined4 *)(programHeader + 0x18),dirtyBits + 0x14);
    }
    else {
      ((int (*)())FUN_0003b870)(ctx,constantBank,*(undefined4 *)(programRecord + 0x28),programRecord + *(int *)(programRecord + 0x2c) * 8,
                   *(undefined4 *)(programHeader + 0x18));
    }
  }
  return passThroughResult;
}

/* extvsDeclareProgramVariables @ 0x3b280 (772 bytes) */
int extvsDeclareProgramVariables(ctx, hwProgram, variableCount, variableRecords, rangeCount, rangeRecords, unusedArg7, literalConstants)
  int ctx;
  int hwProgram;
  uint variableCount;
  int variableRecords;
  uint rangeCount;
  int rangeRecords;
  undefined4 unusedArg7;
  int literalConstants;
{
  int loopIndex2;
  bool scratchFlag1;
  undefined4 *indexFrameLink;
  undefined4 *symbolFrameLink;
  int scratchInt4;
  uint scratchUint5;
  int indexAllocBytes;
  undefined4 scratchUint7;
  undefined1 *kindArray;
  undefined1 *scratchPtr9;
  uint recordKind;
  uint *indexCursor;
  uint *recordCursor;
  uint loopIndex;
  uint variableIndex;
  int scratchInt15;
  undefined4 *symbolOut;
  int scratchInt17;
  uint *groupRecords;
  uint rangeRecord [4];
  
  if (*(uint *)(hwProgram + 0x24) != variableCount) {
    if (*(int *)(hwProgram + 0x28) != 0) {
      (**(code **)(ctx + 0x18))(*(int *)(hwProgram + 0x28));
      *(undefined4 *)(hwProgram + 0x28) = 0;
    }
    if (variableCount != 0) {
      scratchUint7 = (**(code **)(ctx + 0x10))(variableCount,4);
      *(undefined4 *)(hwProgram + 0x28) = scratchUint7;
    }
  }
  *(uint *)(hwProgram + 0x24) = variableCount;
  if (*(char *)(hwProgram + 0x8c) != '\0') {
    scratchInt15 = 0;
    scratchInt17 = hwProgram;
    do {
      scratchUint7 = glGenSymbolsEXT_impl5(ctx,0x87bf,0x87c2,0x87e1,1);
      scratchFlag1 = scratchInt15 != 3;
      scratchInt15 = scratchInt15 + 1;
      *(undefined4 *)(scratchInt17 + 0x68) = scratchUint7;
      scratchInt17 = scratchInt17 + 4;
    } while (scratchFlag1);
  }
  if (variableCount != 0) {
    scratchInt17 = *(int *)(hwProgram + 0x28);
    variableIndex = 0;
    loopIndex = 0;
    scratchPtr9 = (undefined1 *)((unsigned int)__builtin_frame_address(0));
    do {
      if (loopIndex < rangeCount) {
        rangeRecord[0] = *(uint *)(loopIndex * 8 + rangeRecords);
        rangeRecord[1] = *(uint *)(loopIndex * 8 + rangeRecords + 4);
        if ((variableIndex < (rangeRecord[0] & 0xffff)) || ((rangeRecord[1] & 0xffff) <= variableIndex))
        goto LAB_0003b3e0;
        loopIndex = loopIndex + 1;
        scratchInt15 = ((rangeRecord[1] & 0xffff) - (rangeRecord[0] & 0xffff)) + 1;
      }
      else {
LAB_0003b3e0:
        scratchInt15 = 1;
      }
      groupRecords = (uint *)(variableIndex * 8 + variableRecords);
      if ((*(uint *)(variableRecords + variableIndex * 8) & 0x1f0000) != 0) {
        scratchInt4 = -(scratchInt15 + 0x1eU & 0xfffffff0);
        *(undefined1 **)(&STACKARG(0xffffff70) + scratchInt4) = scratchPtr9;
        indexAllocBytes = -(scratchInt15 * 4 + 0x1eU & 0xfffffff0);
        kindArray = (undefined1 *)((int)rangeRecord + scratchInt4);
        indexFrameLink = (undefined4 *)((int)(&STACKARG(0xffffff70) + scratchInt4) + indexAllocBytes);
        *indexFrameLink = scratchPtr9;
        symbolFrameLink = (undefined4 *)((int)indexFrameLink + indexAllocBytes);
        *symbolFrameLink = scratchPtr9;
        symbolOut = symbolFrameLink + 0x10;
        recordCursor = groupRecords;
        scratchFlag1 = scratchInt15 != 0;
        scratchPtr9 = kindArray;
        indexCursor = indexFrameLink + 0x10;
        scratchInt4 = scratchInt15;
        while (scratchFlag1) {
          scratchUint5 = *recordCursor;
          recordKind = scratchUint5 >> 0x10 & 0x1f;
          if (recordKind == 2) {
            *scratchPtr9 = 0;
            *indexCursor = scratchUint5 & 0xffff;
          }
          else if (recordKind == 0x11) {
            *scratchPtr9 = 1;
            *indexCursor = 0;
          }
          else {
            *scratchPtr9 = 2;
            *indexCursor = 0;
          }
          recordCursor = recordCursor + 2;
          scratchPtr9 = scratchPtr9 + 1;
          indexCursor = indexCursor + 1;
          scratchInt4 = scratchInt4 + -1;
          scratchFlag1 = scratchInt4 != 0;
        }
        FUN_000534c0(ctx,scratchInt15,kindArray,indexFrameLink + 0x10,symbolOut);
        if (scratchInt15 != 0) {
          loopIndex2 = 0;
          do {
            scratchUint5 = *groupRecords;
            scratchUint7 = *symbolOut;
            *(undefined4 *)(scratchInt17 + (groupRecords[1] & 0xffff) * 4) = scratchUint7;
            if ((scratchUint5 >> 0x10 & 0x1f) == 0x11) {
              glSetLocalConstantEXT_impl(ctx,scratchUint7,((unsigned char *)0x00001406U),(scratchUint5 & 0xffff) * 0x10 + literalConstants);
            }
            loopIndex2 = loopIndex2 + 1;
            groupRecords = groupRecords + 2;
            symbolOut = symbolOut + 1;
          } while (scratchInt15 != loopIndex2);
          variableIndex = variableIndex + loopIndex2;
        }
        scratchPtr9 = (undefined1 *)*symbolFrameLink;
        variableIndex = variableIndex - 1;
      }
      variableIndex = variableIndex + 1;
    } while (variableIndex < variableCount);
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
int FUN_0003b620(ctx, program, hwProgram, operandCount, operandTable)
  int ctx;
  int program;
  int hwProgram;
  int operandCount;
  uint *operandTable;
{
  int entryPtr;
  uint operandFile;
  int scratchInt3;
  uint *scratchPtr4;
  short operandOrdinal;
  undefined4 scratchUint6;
  int entryTotal;
  int scratchInt8;
  undefined4 entrySymbols [258];
  
  if (*(char *)(hwProgram + 0x8c) == '\0') {
    *(undefined4 *)(program + 0x800) = 0;
  }
  else {
    *(undefined2 *)(program + 2) = 0;
    *(undefined2 *)(program + 10) = 1;
    *(undefined4 *)(program + 0x800) = 4;
    *(undefined2 *)(program + 0x12) = 2;
    *(undefined2 *)(program + 0x1a) = 3;
    entrySymbols[0] = *(undefined4 *)(hwProgram + 0x68);
    entrySymbols[1] = *(undefined4 *)(hwProgram + 0x6c);
    entrySymbols[2] = *(undefined4 *)(hwProgram + 0x70);
    entrySymbols[3] = *(undefined4 *)(hwProgram + 0x74);
  }
  if (operandCount == 0) {
    entryTotal = *(int *)(program + 0x800);
    *(int *)(program + 0x804) = entryTotal;
    *(int *)(program + 0x808) = entryTotal;
  }
  else {
    scratchInt3 = *(int *)(hwProgram + 0x28);
    entryTotal = *(int *)(program + 0x800);
    scratchPtr4 = operandTable;
    scratchInt8 = operandCount;
    do {
      if ((*scratchPtr4 & 0x1fc700) == 0x100000) {
        entryPtr = program + entryTotal * 8;
        scratchUint6 = *(undefined4 *)(scratchInt3 + (uint)*(ushort *)((int)scratchPtr4 + 6) * 4);
        *(char *)(entryPtr + 1) = (char)*(ushort *)((int)scratchPtr4 + 6);
        entrySymbols[entryTotal] = scratchUint6;
        *(ushort *)(entryPtr + 2) = *(byte *)((int)scratchPtr4 + 2) >> 4 & 3;
        entryTotal = *(int *)(program + 0x800) + 1;
        *(int *)(program + 0x800) = entryTotal;
      }
      scratchPtr4 = scratchPtr4 + 2;
      scratchInt8 = scratchInt8 + -1;
    } while (scratchInt8 != 0);
    *(int *)(program + 0x804) = entryTotal;
    scratchInt3 = *(int *)(hwProgram + 0x28);
    scratchPtr4 = operandTable;
    scratchInt8 = operandCount;
    do {
      if ((*scratchPtr4 & 0x1f0000) == 0x20000) {
        entryPtr = program + entryTotal * 8;
        scratchUint6 = *(undefined4 *)(scratchInt3 + (uint)*(ushort *)((int)scratchPtr4 + 6) * 4);
        *(char *)(entryPtr + 1) = (char)*(ushort *)((int)scratchPtr4 + 6);
        entrySymbols[entryTotal] = scratchUint6;
        *(short *)(entryPtr + 2) = (short)*scratchPtr4;
        entryTotal = *(int *)(program + 0x804) + 1;
        *(int *)(program + 0x804) = entryTotal;
      }
      scratchPtr4 = scratchPtr4 + 2;
      scratchInt8 = scratchInt8 + -1;
    } while (scratchInt8 != 0);
    *(int *)(program + 0x808) = entryTotal;
    operandOrdinal = 0;
    do {
      operandFile = *operandTable >> 0x10 & 0x1f;
      if ((((operandFile != 0) && (operandFile != 0x11)) && (operandFile != 2)) && ((*operandTable & 0x1fc700) != 0x100000)
         ) {
        scratchInt8 = program + entryTotal * 8;
        scratchUint6 = *(undefined4 *)(scratchInt3 + (uint)*(ushort *)((int)operandTable + 6) * 4);
        *(char *)(scratchInt8 + 1) = (char)*(ushort *)((int)operandTable + 6);
        *(short *)(scratchInt8 + 2) = operandOrdinal;
        entrySymbols[entryTotal] = scratchUint6;
        entryTotal = *(int *)(program + 0x808) + 1;
        *(int *)(program + 0x808) = entryTotal;
      }
      operandOrdinal = operandOrdinal + 1;
      operandTable = operandTable + 2;
      operandCount = operandCount + -1;
    } while (operandCount != 0);
  }
  return FUN_00054590(ctx + 0x240,program,entryTotal,entrySymbols);
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
  float scratchFloat6;
  float scratchFloat7;
  float scratchFloat8;
  undefined4 constX;
  float vecZPlusOne;
  int scratchInt11;
  undefined *stateRecord;
  dword *srcZPtr;
  undefined8 *destVec;
  int entryCount;
  int stateConstants;
  int lightArrayBase;
  int materialRecord;
  int scratchInt19;
  uint scratchUint20;
  float *srcVec;
  undefined4 *destPtr;
  dword *srcWPtr;
  int lightRecord;
  dword *srcYPtr;
  uint operandIndex;
  float *outSlot;
  byte *entryCursor;
  double scratchDouble29;
  undefined8 scratchUint30;
  double depthRangeNear;
  byte *program;
  int constantTable;
  undefined1 registerBase [8];
  uint operandWord;
  undefined4 operandWord2;
  uint operandWordCopy;
  undefined4 operandWord2Copy;
  
  entryCount = FUN_00054470(ctx + GLD_commandStream,&program,&constantTable,registerBase);
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
      scratchInt19 = stateConstants + (uint)*entryStateIndexPtr * 4;
      constX = *(undefined4 *)(stateConstants + (uint)*entryStateIndexPtr * 4);
      scratchInt11 = constantTable + (uint)destSlot * 0x10;
      constW = *(undefined4 *)(scratchInt19 + 0x30);
      constY = *(undefined4 *)(scratchInt19 + 0x10);
      constZ = *(undefined4 *)(scratchInt19 + 0x20);
      *(undefined4 *)(constantTable + (uint)destSlot * 0x10) = constX;
      *(undefined4 *)(scratchInt11 + 0xc) = constW;
      *(undefined4 *)(scratchInt11 + 4) = constY;
      *(undefined4 *)(scratchInt11 + 8) = constZ;
      destPtr[3] = constW;
      *destPtr = constX;
      destPtr[1] = constY;
      destPtr[2] = constZ;
    } while (entryCursor < program + entryCount * 8);
  }
  entryCount = *(int *)(program + 0x804);
  for (; entryCursor < program + entryCount * 8; entryCursor = entryCursor + 8) {
    destSlot = *entryCursor;
    scratchUint30 = (*(undefined8 **)(entryCursor + 4))[1];
    *(undefined8 *)(constantTable + (uint)destSlot * 0x10) = **(undefined8 **)(entryCursor + 4);
    *(undefined8 *)(constantTable + (uint)destSlot * 0x10 + 8) = scratchUint30;
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
    scratchInt11 = stateConstants + literalConstants;
    if (*(int *)(*(int *)(ctx + GLD_engineObjects) + 0x198) == 0) {
      scratchFloat6 = *(float *)(scratchInt11 + 0xc);
      scratchFloat7 = *(float *)(scratchInt11 + 4);
      scratchFloat8 = *(float *)(scratchInt11 + 8);
      *(undefined4 *)(constantTable + (uint)*entryCursor * 0x10) = *(undefined4 *)(stateConstants + literalConstants);
      outSlot[3] = scratchFloat6;
      outSlot[1] = scratchFloat7;
      outSlot[2] = scratchFloat8;
    }
    else {
      _glpUniformToFloat(*(undefined4 *)(**(int **)(ctx + GLD_currentProgram) + 4),operandWord & 0xffff,scratchInt11,
                         outSlot);
    }
    goto LAB_0003c2d0;
  }
  operandWordCopy = operandWord;
  operandWord2Copy = operandWord2;
  if ((operandWord & 0x1f0000) == 0x100000) {
    scratchUint20 = operandWord >> 0xc & 3;
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
    scratchInt11 = *(int *)(ctx + GLD_engineState) + 0x1860 + stateConstants;
    if ((1 < matrixMode) && (scratchInt11 = stateConstants + *(int *)(ctx + GLD_engineState) + 0x1e60, 3 < matrixMode)) {
      scratchInt11 = 0;
    }
    if (matrixMode < 3) {
      if (matrixMode == 0) {
LAB_0003bef8:
        stateConstants = scratchUint20 * 4;
        scratchInt19 = scratchInt11 + stateConstants;
        *outSlot = *(float *)(scratchInt11 + stateConstants);
        outSlot[1] = *(float *)(scratchInt19 + 0x10);
        outSlot[2] = *(float *)(scratchInt19 + 0x20);
        outSlot[3] = *(float *)(scratchInt19 + 0x30);
      }
      else {
        stateConstants = scratchUint20 * 0x10;
        scratchInt19 = scratchInt11 + stateConstants;
        *outSlot = *(float *)(scratchInt11 + stateConstants);
        outSlot[1] = *(float *)(scratchInt19 + 4);
        outSlot[2] = *(float *)(scratchInt19 + 8);
        outSlot[3] = *(float *)(scratchInt19 + 0xc);
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
    scratchUint20 = operandWord & 0xff;
    switch(operandWord >> 8 & 0xf) {
    case 0:
      srcVec = (float *)(scratchUint20 * 0x80 + 0x24c0 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(srcVec + 1);
      srcZPtr = (dword *)(srcVec + 2);
      srcWPtr = (dword *)(srcVec + 3);
      break;
    case 1:
      srcVec = (float *)(scratchUint20 * 0x80 + 0x24d0 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(srcVec + 1);
      srcZPtr = (dword *)(srcVec + 2);
      srcWPtr = (dword *)(srcVec + 3);
      break;
    case 2:
      srcVec = (float *)(scratchUint20 * 0x80 + 0x24e0 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(srcVec + 1);
      srcZPtr = (dword *)(srcVec + 2);
      srcWPtr = (dword *)(srcVec + 3);
      break;
    case 3:
      srcVec = (float *)(scratchUint20 * 0x80 + 0x24f0 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(srcVec + 1);
      srcZPtr = (dword *)(srcVec + 2);
      srcWPtr = (dword *)(srcVec + 3);
      break;
    case 4:
      srcVec = (float *)(scratchUint20 * 0x80 + 0x2500 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(srcVec + 1);
      srcZPtr = (dword *)(srcVec + 2);
      srcWPtr = (dword *)(srcVec + 3);
      break;
    case 5:
      srcVec = (float *)(scratchUint20 * 0x80 + 0x2510 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(srcVec + 1);
      srcZPtr = (dword *)(srcVec + 2);
      srcWPtr = (dword *)(srcVec + 3);
      break;
    case 6:
      stateConstants = scratchUint20 * 0x80 + *(int *)(ctx + GLD_engineState);
      scratchFloat7 = *(float *)(stateConstants + 0x24f4);
      scratchFloat8 = *(float *)(stateConstants + 0x24f0);
      vecZPlusOne = *(float *)(stateConstants + 0x24f8) + 1.0;
      scratchDouble29 = _sqrt((double)(vecZPlusOne * vecZPlusOne + scratchFloat8 * scratchFloat8 + scratchFloat7 * scratchFloat7));
      outSlot[3] = 1.0;
      scratchFloat6 = (float)(1.0 / scratchDouble29);
      outSlot[2] = vecZPlusOne * scratchFloat6;
      *outSlot = scratchFloat8 * scratchFloat6;
      outSlot[1] = scratchFloat7 * scratchFloat6;
      goto LAB_0003c2d0;
    case 7:
      srcVec = (float *)(scratchUint20 * 0x80 + 0x2530 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(srcVec + 1);
      srcZPtr = (dword *)(srcVec + 2);
      srcWPtr = (dword *)(srcVec + 3);
      break;
    default:
      goto switchD_0003bf70_caseD_1;
    }
    break;
  case 4:
    scratchUint20 = operandWord >> 9 & 3;
    lightArrayBase = *(int *)(ctx + GLD_engineState) + 0x24c0;
    stateConstants = (operandWord & 0xff) * 0x80;
    scratchInt11 = (operandWord >> 8 & 1) * 0x240;
    scratchInt19 = *(int *)(ctx + GLD_engineState) + 0x28c0;
    lightRecord = lightArrayBase + stateConstants;
    materialRecord = scratchInt19 + scratchInt11;
    if (scratchUint20 == 1) {
      *outSlot = *(float *)(lightRecord + 0x10) * *(float *)(materialRecord + 0x10);
      outSlot[1] = *(float *)(lightRecord + 0x14) * *(float *)(materialRecord + 0x14);
      outSlot[2] = *(float *)(lightRecord + 0x18) * *(float *)(materialRecord + 0x18);
      outSlot[3] = *(float *)(materialRecord + 0x1c);
    }
    else if (scratchUint20 == 2) {
      *outSlot = *(float *)(lightRecord + 0x20) * *(float *)(materialRecord + 0x20);
      outSlot[1] = *(float *)(lightRecord + 0x24) * *(float *)(materialRecord + 0x24);
      outSlot[2] = *(float *)(lightRecord + 0x28) * *(float *)(materialRecord + 0x28);
      outSlot[3] = *(float *)(materialRecord + 0x2c);
    }
    else {
      if (scratchUint20 != 0) goto switchD_0003bf70_caseD_1;
      *outSlot = *(float *)(lightArrayBase + stateConstants) * *(float *)(scratchInt19 + scratchInt11);
      outSlot[1] = *(float *)(lightRecord + 4) * *(float *)(materialRecord + 4);
      outSlot[2] = *(float *)(lightRecord + 8) * *(float *)(materialRecord + 8);
      outSlot[3] = *(float *)(materialRecord + 0xc);
    }
    goto LAB_0003c2d0;
  case 5:
    scratchUint20 = operandWord & 1;
    switch(operandWord >> 1 & 7) {
    case 0:
      srcVec = (float *)(scratchUint20 * 0x240 + 0x28c0 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(srcVec + 1);
      srcZPtr = (dword *)(srcVec + 2);
      srcWPtr = (dword *)(srcVec + 3);
      break;
    case 1:
      srcVec = (float *)(scratchUint20 * 0x240 + 0x28d0 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(srcVec + 1);
      srcZPtr = (dword *)(srcVec + 2);
      srcWPtr = (dword *)(srcVec + 3);
      break;
    case 2:
      srcVec = (float *)(scratchUint20 * 0x240 + 0x28e0 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(srcVec + 1);
      srcZPtr = (dword *)(srcVec + 2);
      srcWPtr = (dword *)(srcVec + 3);
      break;
    case 3:
      srcVec = (float *)(scratchUint20 * 0x240 + 0x28f0 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(srcVec + 1);
      srcZPtr = (dword *)(srcVec + 2);
      srcWPtr = (dword *)(srcVec + 3);
      break;
    case 4:
      srcVec = (float *)(scratchUint20 * 0x240 + 0x2900 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(srcVec + 1);
      srcZPtr = (dword *)(srcVec + 2);
      srcWPtr = (dword *)(srcVec + 3);
      break;
    case 5:
      stateConstants = *(int *)(ctx + GLD_engineState);
      scratchInt11 = stateConstants + 0x28c0 + scratchUint20 * 0x240;
      *outSlot = *(float *)(stateConstants + 0x24b0) * *(float *)(stateConstants + 0x28c0 + scratchUint20 * 0x240) +
                 *(float *)(scratchInt11 + 0x30);
      outSlot[1] = *(float *)(stateConstants + 0x24b4) * *(float *)(scratchInt11 + 4) + *(float *)(scratchInt11 + 0x34);
      outSlot[2] = *(float *)(stateConstants + 0x24b8) * *(float *)(scratchInt11 + 8) + *(float *)(scratchInt11 + 0x38);
      outSlot[3] = *(float *)(scratchInt11 + 0x1c);
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
    scratchUint20 = operandWord >> 5 & 7;
    operandWord = operandWord & 0x1f;
    if (scratchUint20 == 1) {
      stateConstants = *(int *)(ctx + GLD_engineState);
      stateRecord = ((unsigned char *)0x000039a0) + operandWord * 0x94;
LAB_0003bae4:
      srcWPtr = (dword *)(stateRecord + stateConstants + 0x1c);
      srcYPtr = (dword *)(stateRecord + stateConstants + 0x14);
      srcZPtr = (dword *)(stateRecord + stateConstants + 0x18);
      srcVec = (float *)(stateRecord + stateConstants + 0x10);
    }
    else {
      if (scratchUint20 < 2) {
        if (scratchUint20 == 0) {
          stateConstants = *(int *)(ctx + GLD_engineState);
          stateRecord = ((unsigned char *)0x00003980) + operandWord * 0x94;
          goto LAB_0003bac0;
        }
        goto switchD_0003bf70_caseD_1;
      }
      if (scratchUint20 == 2) {
        stateConstants = *(int *)(ctx + GLD_engineState);
        stateRecord = ((unsigned char *)0x000039c0) + operandWord * 0x94;
LAB_0003bb08:
        srcWPtr = (dword *)(stateRecord + stateConstants + 0x20);
        srcYPtr = (dword *)(stateRecord + stateConstants + 0x18);
        srcZPtr = (dword *)(stateRecord + stateConstants + 0x1c);
        srcVec = (float *)(stateRecord + stateConstants + 0x14);
      }
      else {
        if (scratchUint20 != 3) goto switchD_0003bf70_caseD_1;
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
    scratchUint20 = operandWord >> 5 & 7;
    operandWord = operandWord & 0x1f;
    if (scratchUint20 == 1) {
      stateConstants = *(int *)(ctx + GLD_engineState);
      stateRecord = ((unsigned char *)0x000039b0) + operandWord * 0x94;
      goto LAB_0003bae4;
    }
    if (scratchUint20 < 2) {
      if (scratchUint20 == 0) {
        stateConstants = *(int *)(ctx + GLD_engineState);
        stateRecord = ((unsigned char *)0x00003990) + operandWord * 0x94;
        goto LAB_0003bac0;
      }
    }
    else {
      if (scratchUint20 == 2) {
        stateConstants = *(int *)(ctx + GLD_engineState);
        stateRecord = ((unsigned char *)0x000039d0) + operandWord * 0x94;
        goto LAB_0003bb08;
      }
      if (scratchUint20 == 3) {
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
    depthRangeNear = *(double *)(0x00001830 + *(int *)(ctx + GLD_engineState));
    scratchDouble29 = *(double *)(*(int *)(ctx + GLD_engineState) + 0x1838);
    outSlot[3] = 1.0;
    outSlot[2] = (float)(scratchDouble29 - depthRangeNear);
    goto LAB_0003c2d0;
  case 0x12:
    scratchFloat6 = *(float *)(*(int *)(ctx + GLD_engineState) + 0x24a4);
    outSlot[3] = scratchFloat6;
    *outSlot = scratchFloat6;
    outSlot[1] = scratchFloat6;
    outSlot[2] = scratchFloat6;
    goto LAB_0003c2d0;
  }
LAB_0003c2b0:
  *outSlot = *srcVec;
  outSlot[1] = (float)*srcYPtr;
  outSlot[2] = (float)*srcZPtr;
  outSlot[3] = (float)*srcWPtr;
LAB_0003c2d0:
  destVec = *(undefined8 **)(entryCursor + 4);
  entryCursor = entryCursor + 8;
  scratchUint30 = *(undefined8 *)(outSlot + 2);
  *destVec = *(undefined8 *)outSlot;
  destVec[1] = scratchUint30;
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

/* extvsTranslateShaderObject @ 0x3c400 (4136 bytes) */
int extvsTranslateShaderObject(ctx, shaderObject, hwProgram)
  int ctx;
  int *shaderObject;
  undefined4 *hwProgram;
{
  uint instructionWord;
  uint operandWord;
  uint opcode;
  uint *instructionPtr;
  bool isGLSLShader;
  bool scratchFlag1;
  bool scratchFlag2;
  int scratchInt3;
  uint srcRegisterFile;
  int scratchInt5;
  uint scratchUint6;
  undefined4 scratchUint7;
  int swizzleX;
  undefined4 componentTemp;
  int swizzleY;
  int swizzleZ;
  int scratchInt12;
  int swizzleW;
  int loopIndex;
  uint scratchUint15;
  uint dstIndex;
  int scratchInt17;
  int sourceCount;
  undefined4 *scratchPtr19;
  int sourceIndex;
  uint *scratchPtr21;
  uint *nextInstruction;
  int sourceByteOffset;
  uint scratchUint24;
  undefined4 *symbolRemapTable;
  undefined4 scratchUint26;
  char symbolKindByte;
  char relativeOffset;
  undefined4 sourceSymbols [11];
  
  if (shaderObject[8] != 0) {
    isGLSLShader = *shaderObject - 0x8b30U < 2;
    extvsBeginShader(ctx);
    noop_53060(ctx);
    scratchInt12 = shaderObject[0x12];
    scratchInt5 = shaderObject[0x13];
    *(undefined1 *)(hwProgram + 0x23) = 0;
    if (scratchInt12 != 0) {
      loopIndex = 0;
      do {
        symbolKindByte = (char)shaderObject[scratchInt5 * 2 + loopIndex * 2];
        if (symbolKindByte == '\0') {
          *(undefined1 *)(hwProgram + 0x23) = 1;
        }
        loopIndex = loopIndex + 1;
        scratchInt12 = scratchInt12 + -1;
      } while (scratchInt12 != 0);
    }
    scratchInt5 = 0;
    scratchPtr19 = hwProgram;
    do {
      scratchUint7 = glGenSymbolsEXT_impl5(ctx,0x87bf,0x87c4,0x87e1,1);
      scratchPtr19[0xd] = scratchUint7;
      scratchUint7 = glGenSymbolsEXT_impl5(ctx,0x87be,0x87c4,0x87e1,1);
      scratchPtr19[0x10] = scratchUint7;
      scratchUint7 = glGenSymbolsEXT_impl5(ctx,0x87bf,0x87c4,0x87e1,1);
      scratchFlag1 = scratchInt5 != 2;
      scratchInt5 = scratchInt5 + 1;
      scratchPtr19[0x13] = scratchUint7;
      scratchPtr19 = scratchPtr19 + 1;
    } while (scratchFlag1);
    scratchInt5 = 0;
    scratchUint7 = glGenSymbolsEXT_impl5(ctx,0x87bf,0x87c4,0x87e1,1);
    hwProgram[0x16] = scratchUint7;
    scratchUint7 = glGenSymbolsEXT_impl5(ctx,0x87be,0x87c4,0x87e1,1);
    hwProgram[0x17] = scratchUint7;
    scratchPtr19 = hwProgram;
    do {
      scratchUint7 = glGenSymbolsEXT_impl5(ctx,0x87bf,0x87c4,0x87e1,1);
      scratchFlag1 = scratchInt5 != 1;
      scratchInt5 = scratchInt5 + 1;
      scratchPtr19[0x18] = scratchUint7;
      scratchPtr19 = scratchPtr19 + 1;
    } while (scratchFlag1);
    scratchInt5 = shaderObject[4];
    if (scratchInt5 != hwProgram[1]) {
      if (hwProgram[2] != 0) {
        (**(code **)(ctx + GLD_engineObjects))(hwProgram[2]);
        hwProgram[2] = 0;
      }
      if (scratchInt5 != 0) {
        scratchUint7 = (**(code **)(ctx + GLD_engineState))(scratchInt5,4);
        hwProgram[2] = scratchUint7;
      }
    }
    hwProgram[1] = scratchInt5;
    if (scratchInt5 != 0) {
      scratchInt12 = glGenSymbolsEXT_impl5(ctx,0x87bf,0x87c4,0x87e1,scratchInt5);
      loopIndex = 0;
      do {
        scratchInt17 = loopIndex * 4;
        scratchInt3 = loopIndex + scratchInt12;
        loopIndex = loopIndex + 1;
        *(int *)(scratchInt17 + hwProgram[2]) = scratchInt3;
        scratchInt5 = scratchInt5 + -1;
      } while (scratchInt5 != 0);
    }
    scratchInt12 = shaderObject[8];
    scratchInt5 = shaderObject[9];
    if (scratchInt12 != hwProgram[3]) {
      if (hwProgram[4] != 0) {
        (**(code **)(ctx + GLD_engineObjects))(hwProgram[4]);
        hwProgram[4] = 0;
      }
      if (scratchInt12 != 0) {
        scratchUint7 = (**(code **)(ctx + GLD_engineState))(scratchInt12,4);
        hwProgram[4] = scratchUint7;
      }
    }
    hwProgram[3] = scratchInt12;
    if (scratchInt12 != 0) {
      scratchPtr19 = (undefined4 *)hwProgram[4];
      loopIndex = 0;
      do {
        scratchUint15 = shaderObject[scratchInt5 * 2 + loopIndex * 2 + 1];
        if (((uint)shaderObject[scratchInt5 * 2 + loopIndex * 2] >> 0x10 & 0xf) - 1 < 10) {
          if ((scratchUint15 & 0xffff) == 0) {
            scratchUint7 = extvsBindCurrentVertexParameter(ctx,0x87e2);
            *scratchPtr19 = scratchUint7;
          }
          else {
            scratchUint7 = glGenSymbolsEXT_impl5(ctx,0x87bf,0x87c1,0x87e1,1);
            scratchPtr19[scratchUint15 & 0xffff] = scratchUint7;
          }
        }
        loopIndex = loopIndex + 1;
      } while (scratchInt12 != loopIndex);
    }
    ((int (*)())extvsDeclareProgramVariables)(ctx,hwProgram,shaderObject[10],shaderObject + shaderObject[0xb] * 2,shaderObject[0xe],
                 shaderObject + shaderObject[0xf] * 2,shaderObject[0x1a],shaderObject + shaderObject[0x1b] * 2);
    scratchInt12 = shaderObject[0x14];
    scratchInt5 = shaderObject[0xd];
    if (scratchInt12 != 0) {
      loopIndex = 0;
      instructionPtr = (uint *)(shaderObject + shaderObject[0x15] * 2);
      do {
        nextInstruction = instructionPtr + 2;
        opcode = *instructionPtr >> 0x12 & 0xff;
        if ((*instructionPtr & 0x3fc0000) == 0x1340000) goto LAB_0003d23c;
        operandWord = instructionPtr[2];
        if (0x4d < opcode) goto switchD_0003cbec_caseD_3;
        scratchFlag1 = opcode == 0x48;
        if (scratchFlag1) {
          scratchInt17 = hwProgram[0x17];
          goto LAB_0003c9b8;
        }
        if ((isGLSLShader) && ((operandWord & 0x7000) != 0x3000)) goto switchD_0003cbec_caseD_3;
        scratchUint6 = operandWord >> 0x11 & 7;
        if (scratchUint6 == 1) {
          scratchInt17 = *(int *)((instructionPtr[3] & 0xffff) * 4 + hwProgram[2]);
          goto LAB_0003c9b8;
        }
        if (scratchUint6 != 3) {
switchD_0003cbec_caseD_3:
          scratchFlag2 = false;
          goto LAB_0003d254;
        }
        scratchUint6 = shaderObject[scratchInt5 * 2 + (instructionPtr[3] & 0xffff) * 2];
        switch(scratchUint6 >> 0x10 & 0xf) {
        case 0:
          scratchInt17 = 0;
          break;
        case 1:
          scratchInt17 = 0x879a;
          break;
        case 2:
          scratchInt17 = 0x87bd;
          break;
        case 3:
          scratchInt17 = 0x610e;
          break;
        case 4:
          scratchInt17 = 0x610f;
          if ((scratchUint6 & 1) == 0) {
            scratchInt17 = 0x879b;
          }
          break;
        case 5:
          scratchInt17 = 0x6110;
          if ((scratchUint6 & 1) == 0) {
            scratchInt17 = 0x879c;
          }
          break;
        case 6:
          scratchInt17 = (scratchUint6 & 0x1f) + 0x879d;
          break;
        default:
          goto switchD_0003cbec_caseD_3;
        }
LAB_0003c9b8:
        scratchInt3 = scratchInt17;
        if (((operandWord & 0x1e000) != 0x1e000) && (!scratchFlag1)) {
          scratchInt3 = hwProgram[0x16];
        }
        if ((opcode < 0x1f) || ((sourceCount = 2, 0x3a < opcode && (sourceCount = 3, 0x40 < opcode)))) {
          sourceCount = 1;
        }
        sourceIndex = 0;
        sourceByteOffset = 0;
        nextInstruction = instructionPtr + 4;
        scratchPtr19 = hwProgram;
        do {
          scratchPtr21 = nextInstruction;
          instructionWord = *scratchPtr21;
          nextInstruction = scratchPtr21 + 2;
          dstIndex = scratchPtr21[1] & 0xffff;
          if ((isGLSLShader) && ((instructionWord & 0x7000) != 0x3000)) goto switchD_0003cbec_caseD_3;
          srcRegisterFile = instructionWord >> 0x17 & 7;
          if (srcRegisterFile == 1) {
            scratchUint7 = *(undefined4 *)(dstIndex * 4 + hwProgram[2]);
          }
          else if (srcRegisterFile == 2) {
            if ((int)instructionWord < 0) {
              relativeOffset = (char)instructionWord;
              glShaderOp2EXT_impl(ctx,0x8782,scratchPtr19[0x13],hwProgram[0x17],
                           *(undefined4 *)((dstIndex + (int)relativeOffset) * 4 + hwProgram[10]));
              scratchUint7 = scratchPtr19[0x13];
            }
            else {
              scratchUint7 = *(undefined4 *)(dstIndex * 4 + hwProgram[10]);
            }
          }
          else {
            scratchUint7 = 0;
            if (srcRegisterFile == 0) {
              scratchUint7 = *(undefined4 *)(dstIndex * 4 + hwProgram[4]);
            }
          }
          *(undefined4 *)((int)sourceSymbols + sourceByteOffset) = scratchUint7;
          if ((instructionWord & 0x8000000) == 0) {
            swizzleX = (instructionWord >> 0x15 & 3) + 0x87d5;
            swizzleY = (instructionWord >> 0x13 & 3) + 0x87d5;
            swizzleZ = (instructionWord >> 0x11 & 3) + 0x87d5;
            swizzleW = (instructionWord >> 0xf & 3) + 0x87d5;
          }
          else {
            swizzleX = (instructionWord >> 0x15 & 3) + 0x87d9;
            swizzleY = (instructionWord >> 0x13 & 3) + 0x87d9;
            swizzleZ = (instructionWord >> 0x11 & 3) + 0x87d9;
            swizzleW = (instructionWord >> 0xf & 3) + 0x87d9;
          }
          if ((((swizzleX != 0x87d5) || (swizzleY != 0x87d6)) || (swizzleZ != 0x87d7)) ||
             (swizzleW != 0x87d8)) {
            FUN_00054080(ctx,scratchPtr19[0xd],*(undefined4 *)((int)sourceSymbols + sourceByteOffset),swizzleX,swizzleY,
                         swizzleZ,swizzleW);
            *(undefined4 *)((int)sourceSymbols + sourceByteOffset) = scratchPtr19[0xd];
          }
          scratchUint7 = sourceSymbols[1];
          sourceIndex = sourceIndex + 1;
          sourceByteOffset = sourceByteOffset + 4;
          scratchPtr19 = scratchPtr19 + 1;
        } while (sourceCount != sourceIndex);
        switch(opcode) {
        case 0:
          glShaderOp1EXT_impl(ctx,0x8799,scratchInt3,sourceSymbols[0]);
          break;
        case 1:
          glShaderOp1EXT_impl(ctx,0x879e,scratchInt3,sourceSymbols[0]);
          break;
        case 2:
          FUN_00054080(ctx,hwProgram[0x18],sourceSymbols[0],0x87d9,0x87da,0x87db,0x87dc);
          glShaderOp2EXT_impl(ctx,0x878a,scratchInt3,sourceSymbols[0],hwProgram[0x18]);
          break;
        default:
          goto switchD_0003cbec_caseD_3;
        case 4:
          glShaderOp1EXT_impl(ctx,0x8789,scratchInt3,sourceSymbols[0]);
          break;
        case 5:
          glShaderOp1EXT_impl(ctx,0x878f,scratchInt3,sourceSymbols[0]);
          break;
        case 0xd:
          FUN_00054080(ctx,hwProgram[0x18],sourceSymbols[0],0x87d9,0x87da,0x87db,0x87dc);
          glShaderOp2EXT_impl(ctx,0x878a,hwProgram[0x19],sourceSymbols[0],hwProgram[0x18]);
          glExtractComponentEXT_impl(ctx,hwProgram[0x10],hwProgram[0x19],0);
          scratchUint26 = hwProgram[0x11];
          componentTemp = hwProgram[0x10];
          scratchUint7 = 0x8795;
          goto LAB_0003cdec;
        case 0xe:
          glExtractComponentEXT_impl(ctx,hwProgram[0x10],sourceSymbols[0],0);
          scratchUint26 = hwProgram[0x11];
          componentTemp = hwProgram[0x10];
          scratchUint7 = 0x8794;
          goto LAB_0003cdec;
        case 0x10:
          glExtractComponentEXT_impl(ctx,hwProgram[0x10],sourceSymbols[0],0);
          scratchUint26 = hwProgram[0x11];
          componentTemp = hwProgram[0x10];
          scratchUint7 = 0x8791;
          goto LAB_0003cdec;
        case 0x11:
          glShaderOp1EXT_impl(ctx,0x87a0,scratchInt3,sourceSymbols[0]);
          break;
        case 0x13:
          glExtractComponentEXT_impl(ctx,hwProgram[0x10],sourceSymbols[0],0);
          scratchUint26 = hwProgram[0x11];
          componentTemp = hwProgram[0x10];
          scratchUint7 = 0x8792;
LAB_0003cdec:
          glShaderOp1EXT_impl(ctx,scratchUint7,scratchUint26,componentTemp);
          glShaderOp1EXT_impl(ctx,0x8799,scratchInt3,hwProgram[0x11]);
          break;
        case 0x14:
          glShaderOp1EXT_impl(ctx,0x87a1,scratchInt3,sourceSymbols[0]);
          break;
        case 0x1f:
          glShaderOp2EXT_impl(ctx,0x8787,scratchInt3,sourceSymbols[0],sourceSymbols[1]);
          break;
        case 0x20:
          glShaderOp2EXT_impl(ctx,0x8796,scratchInt3,sourceSymbols[0],sourceSymbols[1]);
          break;
        case 0x22:
          glShaderOp2EXT_impl(ctx,0x8786,scratchInt3,sourceSymbols[0],sourceSymbols[1]);
          break;
        case 0x28:
          glShaderOp2EXT_impl(ctx,0x8784,scratchInt3,sourceSymbols[0],sourceSymbols[1]);
          break;
        case 0x29:
          glShaderOp2EXT_impl(ctx,0x8785,scratchInt3,sourceSymbols[0],sourceSymbols[1]);
          break;
        case 0x2a:
          FUN_00054080(ctx,hwProgram[0x18],sourceSymbols[0],0x87d5,0x87d6,0x87d7,0x87de);
          glShaderOp2EXT_impl(ctx,0x8785,scratchInt3,hwProgram[0x18],sourceSymbols[1]);
          break;
        case 0x2b:
          glShaderOp2EXT_impl(ctx,0x879f,scratchInt3,sourceSymbols[0],sourceSymbols[1]);
          break;
        case 0x2c:
          glShaderOp2EXT_impl(ctx,0x878b,scratchInt3,sourceSymbols[0],sourceSymbols[1]);
          break;
        case 0x2d:
          glShaderOp2EXT_impl(ctx,0x878a,scratchInt3,sourceSymbols[0],sourceSymbols[1]);
          break;
        case 0x2e:
          glShaderOp2EXT_impl(ctx,0x8797,scratchInt3,sourceSymbols[0],sourceSymbols[1]);
          break;
        case 0x32:
          glShaderOp2EXT_impl(ctx,0x878c,scratchInt3,sourceSymbols[0],sourceSymbols[1]);
          break;
        case 0x35:
          glShaderOp2EXT_impl(ctx,0x878d,scratchInt3,sourceSymbols[0],sourceSymbols[1]);
          break;
        case 0x38:
          glExtractComponentEXT_impl(ctx,hwProgram[0x10],sourceSymbols[0],0);
          glExtractComponentEXT_impl(ctx,hwProgram[0x11],scratchUint7,0);
          glShaderOp2EXT_impl(ctx,0x8793,hwProgram[0x12],hwProgram[0x10],hwProgram[0x11]);
          glShaderOp1EXT_impl(ctx,0x8799,scratchInt3,hwProgram[0x12]);
          break;
        case 0x3f:
          glShaderOp3EXT_impl(ctx,0x8788,scratchInt3,sourceSymbols[0],sourceSymbols[1],sourceSymbols[2]);
          break;
        case 0x41:
          scratchUint15 = *nextInstruction;
          nextInstruction = scratchPtr21 + 4;
          if (((*(int *)(&DAT_001da630 + (scratchUint15 >> 10 & 0x3c)) != 0x87d5) ||
              (*(int *)(&DAT_001da630 + (scratchUint15 >> 6 & 0x3c)) != 0x87d6)) ||
             ((*(int *)(&DAT_001da630 + (scratchUint15 >> 2 & 0x3c)) != 0x87d7 ||
              (*(int *)(&DAT_001da630 + (scratchUint15 & 0xf) * 4) != 0x87d8)))) {
            FUN_00054080(ctx,scratchInt3,sourceSymbols[0],*(int *)(&DAT_001da630 + (scratchUint15 >> 10 & 0x3c)),
                         *(int *)(&DAT_001da630 + (scratchUint15 >> 6 & 0x3c)),
                         *(int *)(&DAT_001da630 + (scratchUint15 >> 2 & 0x3c)),
                         *(int *)(&DAT_001da630 + (scratchUint15 & 0xf) * 4));
          }
          break;
        case 0x48:
          glExtractComponentEXT_impl(ctx,scratchInt3,sourceSymbols[0],0);
        }
        if (((operandWord & 0x1e000) != 0x1e000) && (!scratchFlag1)) {
          glWriteMaskEXT_impl(ctx,scratchInt17,scratchInt3,operandWord >> 0xd & 1,operandWord >> 0xe & 1,operandWord >> 0xf & 1,
                       operandWord >> 0x10 & 1);
        }
LAB_0003d23c:
        loopIndex = loopIndex + 1;
        instructionPtr = nextInstruction;
      } while (scratchInt12 != loopIndex);
    }
    scratchFlag2 = true;
LAB_0003d254:
    if (*(char *)(hwProgram + 0x23) != '\0') {
      scratchUint26 = hwProgram[0x16];
      scratchUint7 = *(undefined4 *)hwProgram[4];
      glShaderOp2EXT_impl(ctx,0x8785,scratchUint26,scratchUint7,hwProgram[0x1a]);
      glWriteMaskEXT_impl(ctx,0x879a,scratchUint26,1,0,0,0);
      glShaderOp2EXT_impl(ctx,0x8785,scratchUint26,scratchUint7,hwProgram[0x1b]);
      glWriteMaskEXT_impl(ctx,0x879a,scratchUint26,0,1,0,0);
      glShaderOp2EXT_impl(ctx,0x8785,scratchUint26,scratchUint7,hwProgram[0x1c]);
      glWriteMaskEXT_impl(ctx,0x879a,scratchUint26,0,0,1,0);
      glShaderOp2EXT_impl(ctx,0x8785,scratchUint26,scratchUint7,hwProgram[0x1d]);
      glWriteMaskEXT_impl(ctx,0x879a,scratchUint26,0,0,0,1);
    }
    extvsEndShader(ctx);
    if (!scratchFlag2) {
      extvsClearConstantsDirty(ctx);
      return 0;
    }
    scratchInt5 = extvsConstantsDirty(ctx);
    if (scratchInt5 != 0) {
      scratchUint15 = hwProgram[3];
      if (scratchUint15 != hwProgram[5]) {
        if (hwProgram[6] != 0) {
          (**(code **)(ctx + GLD_engineObjects))(hwProgram[6]);
          hwProgram[6] = 0;
        }
        if (scratchUint15 != 0) {
          scratchUint7 = (**(code **)(ctx + GLD_engineState))(scratchUint15,4);
          hwProgram[6] = scratchUint7;
        }
      }
      hwProgram[5] = scratchUint15;
      if (scratchUint15 != 0) {
        scratchPtr19 = (undefined4 *)hwProgram[6];
        *scratchPtr19 = 0x000308c0;
        if (1 < scratchUint15) {
          scratchUint24 = 1;
          scratchInt5 = 4;
          do {
            scratchUint24 = scratchUint24 + 1;
            scratchUint7 = FUN_00052ee0(ctx,*(undefined4 *)(hwProgram[4] + scratchInt5));
            *(undefined4 *)((int)scratchPtr19 + scratchInt5) = scratchUint7;
            scratchInt5 = scratchInt5 + 4;
          } while (scratchUint15 != scratchUint24);
        }
      }
      scratchUint15 = hwProgram[3];
      if (scratchUint15 != hwProgram[7]) {
        if (hwProgram[8] != 0) {
          (**(code **)(ctx + GLD_engineObjects))(hwProgram[8]);
          hwProgram[8] = 0;
        }
        if (scratchUint15 != 0) {
          scratchUint7 = (**(code **)(ctx + GLD_engineState))(scratchUint15,4);
          hwProgram[8] = scratchUint7;
        }
      }
      hwProgram[7] = scratchUint15;
      if (scratchUint15 != 0) {
        symbolRemapTable = (undefined4 *)hwProgram[8];
        scratchPtr19 = symbolRemapTable;
        scratchUint24 = scratchUint15;
        do {
          *scratchPtr19 = 0x80;
          scratchPtr19 = scratchPtr19 + 1;
          scratchUint24 = scratchUint24 - 1;
        } while (scratchUint24 != 0);
        *symbolRemapTable = 0;
        if (1 < scratchUint15) {
          scratchUint24 = 1;
          do {
            scratchInt5 = FUN_00052f60(ctx,*(undefined4 *)(scratchUint24 * 4 + hwProgram[4]));
            if (scratchInt5 != 0x81) {
              symbolRemapTable[scratchInt5 + -1] = scratchUint24;
            }
            scratchUint24 = scratchUint24 + 1;
          } while (scratchUint15 != scratchUint24);
        }
      }
      FUN_000530c0(ctx,*hwProgram,hwProgram + 0x1e);
      return 1;
    }
  }
  return 0;
}

/* gld_emitProgramConstantUpdates @ 0x3d590 (2944 bytes) */
int gld_emitProgramConstantUpdates(ctx, passThroughArg2, passThroughArg3, operandTable, literalConstants, updateMask)
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
  undefined4 scratchUint3;
  undefined4 scratchUint4;
  undefined4 scratchUint5;
  float scratchFloat6;
  float vecY;
  float vecX;
  undefined4 constX;
  float vecZPlusOne;
  uint cmdEndAligned;
  int scratchInt12;
  undefined *stateRecord;
  dword *srcZPtr;
  int status;
  undefined4 *cmdStart;
  int scratchInt17;
  int lightArrayBase;
  undefined4 *cmdEnd;
  int materialRecord;
  undefined4 *cacheClearedUpTo;
  undefined8 *scratchPtr22;
  float *srcVec;
  undefined4 *cmdCursor;
  int stateConstants;
  dword *srcWPtr;
  int lightRecord;
  uint cacheLineMask;
  uint cacheLineAddr;
  dword *srcYPtr;
  int ring;
  float *outSlot;
  byte *entryCursor;
  byte *entryCursorB;
  undefined8 scratchUint35;
  double scratchDouble36;
  undefined8 scratchUint37;
  double depthRangeNear;
  byte *program;
  int constantTable;
  int registerBase [2];
  uint operandWord;
  undefined4 operandWord2;
  uint operandWordCopy;
  undefined4 operandWord2Copy;
  
  ring = ctx + GLD_commandStream;
  status = FUN_00054470(ring,&program,&constantTable,registerBase);
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
      scratchInt12 = stateConstants + (uint)*entryStateIndexPtr * 4;
      constX = *(undefined4 *)(stateConstants + (uint)*entryStateIndexPtr * 4);
      scratchInt17 = (uint)destSlot * 0x10;
      constW = *(undefined4 *)(scratchInt12 + 0x30);
      constY = *(undefined4 *)(scratchInt12 + 0x10);
      constZ = *(undefined4 *)(scratchInt12 + 0x20);
      scratchInt12 = constantTable + scratchInt17;
      *(undefined4 *)(constantTable + scratchInt17) = constX;
      *(undefined4 *)(scratchInt12 + 0xc) = constW;
      *(undefined4 *)(scratchInt12 + 4) = constY;
      *(undefined4 *)(scratchInt12 + 8) = constZ;
      cmdStart[3] = constW;
      *cmdStart = constX;
      cmdStart[1] = constY;
      cmdStart[2] = constZ;
      cmdCursor[1] = registerBase[0] + (uint)destSlot;
      cmdCursor[3] = constX;
      cmdCursor[4] = constY;
      cmdCursor[5] = constZ;
      cmdCursor[6] = constW;
      *cmdCursor = 0x880;
      cmdCursor[2] = 0x38882;
      cmdCursor = cmdCursor + 7;
    } while (entryCursor < program + entryCountA * 8);
  }
  entryCountB = *(int *)(program + 0x804);
  while (entryCursorB = entryCursor, entryCursorB < program + entryCountB * 8) {
    entryCursor = entryCursorB + 8;
    if ((*(uint *)((entryCursorB[1] >> 3 & 0x1c) + updateMask) >> (entryCursorB[1] & 0x1f) & 1) != 0) {
      scratchPtr22 = *(undefined8 **)(entryCursorB + 4);
      destSlot = *entryCursorB;
      *cmdCursor = 0x880;
      cmdCursor[2] = 0x38882;
      stateConstants = (uint)destSlot * 0x10;
      scratchUint37 = scratchPtr22[1];
      scratchUint35 = *scratchPtr22;
      cmdCursor[1] = registerBase[0] + (uint)destSlot;
      *(undefined8 *)(cmdCursor + 3) = scratchUint35;
      *(undefined8 *)(constantTable + stateConstants) = scratchUint35;
      *(undefined8 *)(cmdCursor + 5) = scratchUint37;
      *(undefined8 *)(constantTable + stateConstants + 8) = scratchUint37;
      cmdCursor = cmdCursor + 7;
    }
  }
  entryCountC = *(int *)(program + 0x808);
LAB_0003d820:
  while( true ) {
    if (program + entryCountC * 8 <= entryCursorB) {
      *(undefined4 **)(ctx + GLD_streamCurrent) = cmdCursor;
      (**(code **)(ctx + GLD_streamSetCurrent))(ring,cmdCursor);
      return;
    }
    if ((*(uint *)((entryCursorB[1] >> 3 & 0x1c) + updateMask) >> (entryCursorB[1] & 0x1f) & 1) != 0) break;
    entryCursorB = entryCursorB + 8;
  }
  destSlot = *entryCursorB;
  outSlot = (float *)(cmdCursor + 3);
  operandWord = *(uint *)((uint)*(ushort *)(entryCursorB + 2) * 8 + operandTable);
  operandWord2 = *(undefined4 *)((uint)*(ushort *)(entryCursorB + 2) * 8 + operandTable + 4);
  cmdCursor[1] = registerBase[0] + (uint)destSlot;
  cmdCursor[2] = 0x38882;
  *cmdCursor = 0x880;
  if ((operandWord >> 0x10 & 0x1f) == 1) {
    stateConstants = (operandWord & 0xffff) * 0x10;
    scratchInt17 = stateConstants + literalConstants;
    if (*(int *)(*(int *)(ctx + GLD_engineObjects) + 0x198) == 0) {
      scratchUint3 = *(undefined4 *)(scratchInt17 + 0xc);
      scratchUint4 = *(undefined4 *)(scratchInt17 + 4);
      scratchUint5 = *(undefined4 *)(scratchInt17 + 8);
      cmdCursor[3] = *(undefined4 *)(stateConstants + literalConstants);
      cmdCursor[6] = scratchUint3;
      cmdCursor[4] = scratchUint4;
      cmdCursor[5] = scratchUint5;
    }
    else {
      _glpUniformToFloat(*(undefined4 *)(**(int **)(ctx + GLD_currentProgram) + 4),operandWord & 0xffff,scratchInt17,
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
    scratchInt17 = *(int *)(ctx + GLD_engineState) + 0x1860 + stateConstants;
    if ((1 < cmdEndAligned) && (scratchInt17 = stateConstants + *(int *)(ctx + GLD_engineState) + 0x1e60, 3 < cmdEndAligned)) {
      scratchInt17 = 0;
    }
    if (cmdEndAligned < 3) {
      if (cmdEndAligned == 0) {
LAB_0003dd8c:
        stateConstants = cacheLineAddr * 4;
        scratchInt12 = scratchInt17 + stateConstants;
        *outSlot = *(float *)(scratchInt17 + stateConstants);
        cmdCursor[4] = *(undefined4 *)(scratchInt12 + 0x10);
        cmdCursor[5] = *(undefined4 *)(scratchInt12 + 0x20);
        cmdCursor[6] = *(undefined4 *)(scratchInt12 + 0x30);
      }
      else {
        stateConstants = cacheLineAddr * 0x10;
        scratchInt12 = scratchInt17 + stateConstants;
        *outSlot = *(float *)(scratchInt17 + stateConstants);
        cmdCursor[4] = *(undefined4 *)(scratchInt12 + 4);
        cmdCursor[5] = *(undefined4 *)(scratchInt12 + 8);
        cmdCursor[6] = *(undefined4 *)(scratchInt12 + 0xc);
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
      vecY = *(float *)(stateConstants + 0x24f4);
      vecX = *(float *)(stateConstants + 0x24f0);
      vecZPlusOne = *(float *)(stateConstants + 0x24f8) + 1.0;
      scratchDouble36 = _sqrt((double)(vecZPlusOne * vecZPlusOne + vecX * vecX + vecY * vecY));
      cmdCursor[6] = 1.0;
      scratchFloat6 = (float)(1.0 / scratchDouble36);
      cmdCursor[5] = vecZPlusOne * scratchFloat6;
      *outSlot = vecX * scratchFloat6;
      cmdCursor[4] = vecY * scratchFloat6;
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
    lightArrayBase = *(int *)(ctx + GLD_engineState) + 0x24c0;
    stateConstants = (operandWord & 0xff) * 0x80;
    scratchInt17 = (operandWord >> 8 & 1) * 0x240;
    scratchInt12 = *(int *)(ctx + GLD_engineState) + 0x28c0;
    lightRecord = lightArrayBase + stateConstants;
    materialRecord = scratchInt12 + scratchInt17;
    if (cacheLineAddr == 1) {
      *outSlot = *(float *)(lightRecord + 0x10) * *(float *)(materialRecord + 0x10);
      cmdCursor[4] = *(float *)(lightRecord + 0x14) * *(float *)(materialRecord + 0x14);
      cmdCursor[5] = *(float *)(lightRecord + 0x18) * *(float *)(materialRecord + 0x18);
      cmdCursor[6] = *(undefined4 *)(materialRecord + 0x1c);
    }
    else if (cacheLineAddr == 2) {
      *outSlot = *(float *)(lightRecord + 0x20) * *(float *)(materialRecord + 0x20);
      cmdCursor[4] = *(float *)(lightRecord + 0x24) * *(float *)(materialRecord + 0x24);
      cmdCursor[5] = *(float *)(lightRecord + 0x28) * *(float *)(materialRecord + 0x28);
      cmdCursor[6] = *(undefined4 *)(materialRecord + 0x2c);
    }
    else {
      if (cacheLineAddr != 0) goto switchD_0003de14_caseD_1;
      *outSlot = *(float *)(lightArrayBase + stateConstants) * *(float *)(scratchInt12 + scratchInt17);
      cmdCursor[4] = *(float *)(lightRecord + 4) * *(float *)(materialRecord + 4);
      cmdCursor[5] = *(float *)(lightRecord + 8) * *(float *)(materialRecord + 8);
      cmdCursor[6] = *(undefined4 *)(materialRecord + 0xc);
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
      scratchInt17 = stateConstants + 0x28c0 + cacheLineAddr * 0x240;
      *outSlot = *(float *)(stateConstants + 0x24b0) * *(float *)(stateConstants + 0x28c0 + cacheLineAddr * 0x240) +
                 *(float *)(scratchInt17 + 0x30);
      cmdCursor[4] = *(float *)(stateConstants + 0x24b4) * *(float *)(scratchInt17 + 4) + *(float *)(scratchInt17 + 0x34);
      cmdCursor[5] = *(float *)(stateConstants + 0x24b8) * *(float *)(scratchInt17 + 8) + *(float *)(scratchInt17 + 0x38);
      cmdCursor[6] = *(undefined4 *)(scratchInt17 + 0x1c);
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
    depthRangeNear = *(double *)(0x00001830 + *(int *)(ctx + GLD_engineState));
    scratchDouble36 = *(double *)(*(int *)(ctx + GLD_engineState) + 0x1838);
    cmdCursor[6] = 0x3f800000;
    cmdCursor[5] = (float)(scratchDouble36 - depthRangeNear);
    goto LAB_0003e170;
  case 0x12:
    scratchFloat6 = *(float *)(*(int *)(ctx + GLD_engineState) + 0x24a4);
    cmdCursor[6] = scratchFloat6;
    *outSlot = scratchFloat6;
    cmdCursor[4] = scratchFloat6;
    cmdCursor[5] = scratchFloat6;
    goto LAB_0003e170;
  }
LAB_0003e150:
  *outSlot = *srcVec;
  cmdCursor[4] = *srcYPtr;
  cmdCursor[5] = *srcZPtr;
  cmdCursor[6] = *srcWPtr;
LAB_0003e170:
  scratchUint37 = *(undefined8 *)(cmdCursor + 5);
  scratchUint35 = *(undefined8 *)outSlot;
  stateConstants = (uint)destSlot * 0x10;
  cmdCursor = cmdCursor + 7;
  *(undefined8 *)(constantTable + stateConstants) = scratchUint35;
  *(undefined8 *)(constantTable + stateConstants + 8) = scratchUint37;
  scratchPtr22 = *(undefined8 **)(entryCursorB + 4);
  entryCursorB = entryCursorB + 8;
  scratchPtr22[1] = scratchUint37;
  *scratchPtr22 = scratchUint35;
  goto LAB_0003d820;
switchD_0003de14_caseD_1:
  srcYPtr = ((unsigned char *)0x4);
  srcZPtr = ((unsigned char *)0x8);
  srcWPtr = ((unsigned char *)0xc);
  srcVec = (float *)0x0;
  goto LAB_0003e150;
}

/* gldUpdateTextureTargetDirtyMask @ 0x3e1d0 (124 bytes) */
int gldUpdateTextureTargetDirtyMask(ctx)
  int ctx;
{
  uint unitIndex;
  uint targetKind;
  uint dirtyMask;
  int unitSlotPtr;
  int unitsLeft;
  
  dirtyMask = *(uint *)(ctx + 0x29fc);
  unitIndex = 0;
  unitsLeft = 0x10;
  unitSlotPtr = ctx;
  do {
    targetKind = 0xff;
    if (*(int *)(unitSlotPtr + 0x18c) != 0) {
      targetKind = **(ushort **)(*(int *)(unitSlotPtr + 0x18c) + 0x30) & 0xf;
    }
    if (targetKind == *(uint *)(unitSlotPtr + 0x2a00)) {
      dirtyMask = dirtyMask & ~(1 << (unitIndex & 0x3f));
      *(uint *)(ctx + 0x29fc) = dirtyMask;
    }
    else {
      *(uint *)(unitSlotPtr + 0x2a00) = targetKind;
      dirtyMask = 1 << (unitIndex & 0x3f) | dirtyMask;
      *(uint *)(ctx + 0x29fc) = dirtyMask;
    }
    unitIndex = unitIndex + 1;
    unitSlotPtr = unitSlotPtr + 4;
    unitsLeft = unitsLeft + -1;
  } while (unitsLeft != 0);
  return;
}

/* gld_updateUnitKindTable @ 0x3e250 (188 bytes) */
int gld_updateUnitKindTable(ctx)
  int ctx;
{
  ushort unitFormatFlags;
  int unitSlotPtr;
  int unitIndex;
  int kindByteOffset;
  int unitsLeft;
  undefined1 unitPresent [16];
  undefined4 unitKind [22];
  
  if (*(int *)(ctx + 0x29fc) != 0) {
    unitIndex = 0;
    kindByteOffset = 0;
    unitsLeft = 0x10;
    unitSlotPtr = ctx;
    do {
      if (*(int *)(unitSlotPtr + 0x18c) == 0) {
        *(undefined4 *)(kindByteOffset + (int)unitKind) = 0;
        unitPresent[unitIndex] = 0;
      }
      else {
        unitFormatFlags = **(ushort **)(*(int *)(unitSlotPtr + 0x18c) + 0x30);
        unitPresent[unitIndex] = 1;
        if ((unitFormatFlags & 0xf) == 0) {
          *(undefined4 *)(kindByteOffset + (int)unitKind) = 2;
        }
        else if ((unitFormatFlags & 0xf) == 1) {
          *(undefined4 *)(kindByteOffset + (int)unitKind) = 1;
        }
        else {
          *(undefined4 *)(kindByteOffset + (int)unitKind) = 0;
        }
      }
      unitIndex = unitIndex + 1;
      kindByteOffset = kindByteOffset + 4;
      unitSlotPtr = unitSlotPtr + 4;
      unitsLeft = unitsLeft + -1;
    } while (unitsLeft != 0);
    FUN_000a1090(ctx + 0x240,unitPresent,unitKind);
  }
  return;
}

/* gld_updateFragmentProgramState @ 0x3e320 (120 bytes) */
int gld_updateFragmentProgramState(ctx, dirtyBits, passThroughResult)
  int ctx;
  undefined4 dirtyBits;
  undefined4 passThroughResult;
{
  int programHeader;
  uint constantBlockHeader;
  uint *constantBlock;
  int *currentFragmentProgram;
  
  currentFragmentProgram = *(int **)(ctx + 0x1d0);
  ((int (*)())gld_updateUnitKindTable)(ctx);
  if (currentFragmentProgram != (int *)0x0) {
    programHeader = *currentFragmentProgram;
    constantBlock = *(uint **)(programHeader + 4);
    constantBlockHeader = *constantBlock;
    ((int (*)())gld_setFragmentShaderConstants)(ctx + 0x240,*(int *)(ctx + 0x29ec) + 0x14,constantBlockHeader >> 0x10 & 0xff,
                 constantBlock + (constantBlockHeader & 0xffff),((unsigned char *)0x00001010) + *(int *)(ctx + 0x10),
                 *(undefined4 *)(programHeader + 0x18));
  }
  return passThroughResult;
}

/* gld_bindFragmentShaderSlot @ 0x3e3a0 (116 bytes) */
int gld_bindFragmentShaderSlot(ctx, shaderIdPtr)
  int ctx;
  int *shaderIdPtr;
{
  undefined4 boundShaderState;
  int shaderId;
  
  shaderId = *shaderIdPtr;
  if (shaderId == 0) {
    shaderId = glGenFragmentShadersATI_impl(ctx,1);
    *shaderIdPtr = shaderId;
    if (shaderId == 0) {
      return 0;
    }
  }
  glBindFragmentShaderATI_impl(ctx,shaderId);
  boundShaderState = FUN_000a11a0(ctx);
  *(undefined4 *)(ctx + 0x27b8) = boundShaderState;
  return 1;
}

/* gld_setFragmentShaderConstants @ 0x3e420 (152 bytes) */
int gld_setFragmentShaderConstants(stream, unusedArg2, entryCount, entries, literalConstants, stateConstants)
  undefined4 stream;
  undefined4 unusedArg2;
  int entryCount;
  uint *entries;
  int literalConstants;
  int stateConstants;
{
  uint entryWord;
  uint vectorIndex;
  int constantPtr;
  int loopIndex;
  
  if (entryCount != 0) {
    loopIndex = 0;
    do {
      entryWord = *entries;
      entries = entries + 1;
      if ((entryWord & 3) != 1) {
        vectorIndex = entryWord >> 0xc & 0xff;
        if ((entryWord & 3) == 0) {
          constantPtr = vectorIndex * 0x10 + literalConstants;
        }
        else {
          constantPtr = vectorIndex * 0x10 + stateConstants;
        }
        glSetFragmentShaderConstantATI_impl(stream,(entryWord >> 0x14 & 0xff) + 0x8941,constantPtr);
      }
      loopIndex = loopIndex + 1;
    } while (entryCount != loopIndex);
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
asm(".globl glCopyTexSubImage_impl");
asm(".set glCopyTexSubImage_impl, _glCopyTexSubImage_impl");
asm(".globl glTexSubImage_impl");
asm(".set glTexSubImage_impl, _glTexSubImage_impl");
asm(".globl gldPrimInlineLineStrip");
asm(".set gldPrimInlineLineStrip, _gldPrimInlineLineStrip");
asm(".globl gldPrimInlineTriangleFan");
asm(".set gldPrimInlineTriangleFan, _gldPrimInlineTriangleFan");
asm(".globl gldPrimInlineTriangles");
asm(".set gldPrimInlineTriangles, _gldPrimInlineTriangles");
asm(".globl gldPrimInlineTriangleStrip");
asm(".set gldPrimInlineTriangleStrip, _gldPrimInlineTriangleStrip");
asm(".globl gldPrimInlineQuads");
asm(".set gldPrimInlineQuads, _gldPrimInlineQuads");
asm(".globl gldPrimInlineQuadStrip");
asm(".set gldPrimInlineQuadStrip, _gldPrimInlineQuadStrip");
asm(".globl gldPrimInlinePolygon");
asm(".set gldPrimInlinePolygon, _gldPrimInlinePolygon");
asm(".globl gldPrimInlinePoints");
asm(".set gldPrimInlinePoints, _gldPrimInlinePoints");
asm(".globl gldPrimInlineLines");
asm(".set gldPrimInlineLines, _gldPrimInlineLines");
asm(".globl gldPrimInlineLineLoop");
asm(".set gldPrimInlineLineLoop, _gldPrimInlineLineLoop");
