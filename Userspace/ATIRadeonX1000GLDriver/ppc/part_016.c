#include "decls.h"

/* FUN_000a7d10 @ 0xa7d10 (344 bytes) */
int FUN_000a7d10(param_1)
  int param_1;
{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  
  uVar6 = *(uint *)(param_1 + 0x44);
  if ((((int)uVar6 < 0) &&
      (*(short *)("}J3x})+x|B;x}k" + *(int *)(*(int *)(param_1 + 4) + 0x10)) == -0x7e06)) ||
     (iVar5 = 0, (uVar6 & 0xa10000) != 0)) {
    iVar5 = 1;
  }
  if ((uVar6 & 0x1000000) != 0) {
    iVar5 = 5;
  }
  if ((uVar6 & 0x20000) == 0) {
    bVar1 = *(byte *)(param_1 + 0x2b);
    if (bVar1 != 0) {
      uVar6 = (uint)bVar1;
      iVar3 = 0;
      iVar7 = 0;
      iVar8 = param_1;
      if ((bVar1 == 0) || (uVar6 == 0x80000000)) {
        uVar6 = 1;
      }
      do {
        if (*(int *)(((unsigned char *)0x000013f8) + iVar8) != 0) {
          iVar2 = iVar3 * 4;
          iVar3 = iVar3 + 1;
          *(int *)(iVar2 + param_1 + 0x1824) = iVar7;
        }
        iVar7 = iVar7 + 1;
        iVar8 = iVar8 + 4;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
LAB_000a7de8:
      iVar3 = iVar3 << 4;
      goto LAB_000a7df4;
    }
  }
  else {
    uVar4 = (uint)(byte)((unsigned char *)0x000013b0)[param_1];
    if (uVar4 != 0) {
      iVar3 = 0;
      uVar9 = 0;
      if ((uVar4 == 0) || (uVar4 == 0x80000000)) {
        uVar4 = 1;
      }
      while( true ) {
        if ((uVar6 & 0x2000) == 0) {
          uVar6 = (int)(uint)(byte)((unsigned char *)0x00001135)[param_1] >> (uVar9 & 0x3f);
        }
        else {
          uVar6 = (int)(uint)(byte)((unsigned char *)0x000011d3)[param_1] >> (uVar9 & 0x3f);
        }
        if ((uVar6 & 1) != 0) {
          iVar8 = iVar3 * 4;
          iVar3 = iVar3 + 1;
          *(uint *)(iVar8 + param_1 + 0x1824) = uVar9;
        }
        uVar9 = uVar9 + 1;
        uVar4 = uVar4 - 1;
        if (uVar4 == 0) break;
        uVar6 = *(uint *)(param_1 + 0x44);
      }
      goto LAB_000a7de8;
    }
  }
  iVar3 = 0;
LAB_000a7df4:
  *(int *)(param_1 + 0x1804) = iVar5 + iVar3;
  return;
}

/* FUN_000a7e80 @ 0xa7e80 (24 bytes) */
int FUN_000a7e80(param_1)
  int param_1;
{
  *(undefined1 *)(param_1 + 0x29) = 1;
  *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x10;
  return;
}

/* FUN_000a7ea0 @ 0xa7ea0 (48 bytes) */
int FUN_000a7ea0(param_1)
  int param_1;
{
  *(undefined1 *)(param_1 + 0x29) = 1;
  *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) & 0xefffffff;
  *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x400;
  *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x1018;
  return;
}

/* FUN_000a7ed0 @ 0xa7ed0 (4 bytes) */
int FUN_000a7ed0()
{
  return;
}

/* FUN_000a7ee0 @ 0xa7ee0 (980 bytes) */
int FUN_000a7ee0(param_1, param_2)
  int param_1;
  uint param_2;
{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  ushort uVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  
  if (param_2 != 0) {
    uVar14 = 0;
    iVar15 = param_1 + 0x240;
    iVar13 = param_1;
    do {
      if ((param_2 & 1) != 0) {
        iVar6 = uVar14 * 4;
        uVar7 = *(uint *)(param_1 + 0x278);
        iVar11 = 1 << (uVar14 & 0x3f);
        uVar9 = *(uint *)(iVar6 + iVar15 + 0x48);
        uVar12 = (ushort)iVar11;
        uVar8 = uVar9 & 0xffffffe0 |
                *(uint *)(((unsigned char *)0x000031d4) + uVar14 * 0x7c + *(int *)(param_1 + 0x10)) & 0x1f;
        *(ushort *)(param_1 + 0x272) = uVar12 | *(ushort *)(param_1 + 0x272);
        *(uint *)(param_1 + 0x278) = uVar7 | 0x200;
        if (uVar9 != uVar8) {
          *(undefined1 *)(param_1 + 0x269) = 1;
          *(ushort *)(param_1 + 0x274) = uVar12 | *(ushort *)(param_1 + 0x274);
          iVar10 = *(int *)(param_1 + 0x10);
          if ((("}J3x})+x|B;x}k"[iVar10 + 2] != '\0') && (*(int *)(iVar13 + 0x18c) != 0)) &&
             ((**(ushort **)(*(int *)(iVar13 + 0x18c) + 0x30) & 0xf) == 0)) {
            *(uint *)(param_1 + 0x278) = uVar7 | 0x220;
            iVar10 = *(int *)(param_1 + 0x10);
          }
          if (((unsigned char *)0x00002e0a)[iVar10] != '\0') {
            *(uint *)(param_1 + 0x278) = *(uint *)(param_1 + 0x278) | 0x100;
          }
          *(uint *)(iVar6 + iVar15 + 0x48) = uVar8;
          *(undefined1 *)(param_1 + 0x26b5) = 1;
        }
        iVar10 = *(int *)(iVar13 + 0x18c);
        bVar5 = (byte)iVar11;
        if (iVar10 == 0) {
          if (((unsigned char *)0x00001438)[uVar14 + iVar15] != '\0') {
            *(undefined1 *)(param_1 + 0x269) = 1;
            *(ushort *)(param_1 + 0x274) = uVar12 | *(ushort *)(param_1 + 0x274);
          }
          ((unsigned char *)0x00001438)[uVar14 + iVar15] = 0;
          *(undefined4 *)(((unsigned char *)0x000013f8) + iVar6 + iVar15) = 0;
          iVar6 = uVar14 * 8 + iVar15;
          iVar11 = uVar14 * 2 + iVar15;
          *(uint *)(iVar6 + 0x18ac) = *(uint *)(iVar6 + 0x18ac) & 0xfffffffe;
          *(ushort *)(iVar11 + 0x187c) = *(ushort *)(iVar11 + 0x187c) & 0x7fff;
          *(byte *)(param_1 + 0x260) = *(byte *)(param_1 + 0x260) & ~bVar5;
        }
        else {
          iVar11 = *(int *)(((unsigned char *)0x000013f8) + iVar6 + iVar15);
          bVar1 = *(byte *)(iVar10 + 0x6b);
          bVar2 = *(byte *)(iVar10 + 0x6a);
          bVar3 = *(byte *)(iVar10 + 0x69);
          uVar7 = *(uint *)(iVar10 + 200) >> 0x16 & 3;
          bVar4 = *(byte *)(iVar10 + 0x68);
          if ((iVar10 + 0x3c != iVar11) && (*(undefined1 *)(param_1 + 0x269) = 1, iVar11 == 0)) {
            *(ushort *)(param_1 + 0x274) = uVar12 | *(ushort *)(param_1 + 0x274);
          }
          ((unsigned char *)0x00001438)[uVar14 + iVar15] = 1;
          *(int *)(((unsigned char *)0x000013f8) + iVar6 + iVar15) = iVar10 + 0x3c;
          iVar6 = uVar14 * 8 + iVar15;
          iVar11 = uVar14 * 2 + iVar15;
          *(uint *)(iVar6 + 0x18ac) = *(uint *)(iVar6 + 0x18ac) | 1;
          *(uint *)(iVar6 + 0x18a8) =
               (uint)*(byte *)(iVar10 + 0x6c) << 0x1d | *(uint *)(iVar6 + 0x18a8) & 0x1fffffff;
          *(ushort *)(iVar11 + 0x187c) = *(ushort *)(iVar11 + 0x187c) | 0x8000;
          if (*(byte *)(param_1 + 0x26b) <= uVar14) {
            *(undefined1 *)(param_1 + 0x26b5) = 1;
            *(char *)(param_1 + 0x26b) = (char)uVar14 + '\x01';
            *(undefined1 *)(param_1 + 0x269) = 1;
            *(uint *)(param_1 + 0x27c) = *(uint *)(param_1 + 0x27c) | 0x400;
          }
          FUN_0002ebc0(param_1,uVar14);
          *(undefined4 *)(iVar10 + 0x88) = *(undefined4 *)(*(int *)(iVar10 + 0x30) + 0x38);
          *(uint *)(iVar6 + 0x18ac) =
               (bVar4 & 1) << 0x14 |
               (bVar3 & 7) << 0x15 |
               (bVar2 & 1) << 0x13 | (bVar1 & 7) << 4 | *(uint *)(iVar6 + 0x18ac) & 0xff07ff8f;
          if (*(short *)(iVar10 + 0x74) == 0x1902) {
            *(uint *)(param_1 + 0x1a48) = *(uint *)(param_1 + 0x1a48) | 0x80000000;
          }
          if ((**(ushort **)(iVar10 + 0x30) & 0xf) == 2) {
            *(uint *)(param_1 + 0x1a48) = *(uint *)(param_1 + 0x1a48) | 0x40000000;
          }
          if (*(float *)(iVar10 + 0x88) != FLOAT_001aa0d4) {
            *(uint *)(param_1 + 0x1a48) = *(uint *)(param_1 + 0x1a48) | 0x10000000;
          }
          if ((uVar14 < 8) && (uVar7 != 0)) {
            if ((*(uint *)(param_1 + 0x284) & 0x20000) != 0) goto LAB_000a81e0;
            if (((int)(uint)*(byte *)(param_1 + 0x260) >> (uVar14 & 0x3f) & 1U) == 0) {
              *(undefined1 *)(param_1 + 0x269) = 1;
              *(byte *)(param_1 + 0x260) = *(byte *)(param_1 + 0x260) | bVar5;
              *(ushort *)(param_1 + 0x274) = uVar12 | *(ushort *)(param_1 + 0x274);
            }
            *(char *)(uVar14 + iVar15 + 0x21) = (char)uVar7;
            iVar6 = uVar14 * 0xc + iVar15;
            *(uint *)(iVar6 + 0x2854) = (uint)*(ushort *)(iVar10 + 0xd0);
            *(uint *)(iVar6 + 0x2858) = (uint)*(ushort *)(iVar10 + 0xd4);
            *(uint *)(iVar6 + 0x285c) = (uint)*(ushort *)(iVar10 + 0xd2);
          }
          else {
LAB_000a81e0:
            if (((int)(uint)*(byte *)(param_1 + 0x260) >> (uVar14 & 0x3f) & 1U) != 0) {
              *(undefined1 *)(param_1 + 0x269) = 1;
              *(byte *)(param_1 + 0x260) = *(byte *)(param_1 + 0x260) & ~bVar5;
              *(ushort *)(param_1 + 0x274) = uVar12 | *(ushort *)(param_1 + 0x274);
            }
          }
          iVar6 = uVar14 * 8 + iVar15;
          *(uint *)(iVar6 + 0x18a8) = uVar7 << 2 | *(uint *)(iVar6 + 0x18a8) & 0xfffffff3;
        }
      }
      uVar14 = uVar14 + 1;
      param_2 = param_2 >> 1;
      iVar13 = iVar13 + 4;
    } while (param_2 != 0);
  }
  return;
}

/* FUN_000a82c0 @ 0xa82c0 (96 bytes) */
int FUN_000a82c0(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  int iVar2;
  
  if (*(int *)(((unsigned char *)0x000013f8) + param_2 * 4 + param_1 + 0x240) == 0) {
    return;
  }
  iVar2 = 5;
  piVar1 = (int *)(param_2 * 0x14 + *(int *)(param_1 + 0x18));
  while ((*piVar1 == 0 ||
         (*(int *)(((unsigned char *)0x000013f8) + param_2 * 4 + param_1 + 0x240) != *piVar1 + 0x3c))) {
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
    if (iVar2 == 0) {
      *(undefined4 *)(((unsigned char *)0x000013f8) + param_2 * 4 + param_1 + 0x240) = 0;
      return;
    }
  }
  return;
}

/* FUN_000a8320 @ 0xa8320 (20 bytes) */
int FUN_000a8320(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(((unsigned char *)0x00001638) + param_2 * 4 + param_1) = 0;
  return;
}

/* FUN_000a8340 @ 0xa8340 (720 bytes) */
int FUN_000a8340(param_1, param_2)
  int param_1;
  uint param_2;
{
  int iVar1;
  short *psVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  int iVar9;
  int iVar10;
  
  uVar3 = param_2 >> 0x10 & 0xff;
  if (uVar3 != 0) {
    uVar5 = 0;
    iVar6 = param_1 + 0x288;
    iVar10 = 0;
    iVar4 = 0;
    do {
      if ((uVar3 & 1) != 0) {
        iVar1 = uVar5 * 4;
        iVar9 = iVar10 + param_1 + 0x690;
        puVar8 = (uint *)(iVar6 + iVar1);
        psVar2 = (short *)(((unsigned char *)0x00003988) + iVar4 + *(int *)(param_1 + 0x10));
        if (*(char *)(psVar2 + 0x48) == '\0') {
          *(uint *)(iVar6 + iVar1) = *(uint *)(iVar6 + iVar1) & 0xffffffdf;
        }
        else {
          *(uint *)(iVar6 + iVar1) = *(uint *)(iVar6 + iVar1) | 0x20;
        }
        if (*(char *)((int)psVar2 + 0x91) == '\0') {
          uVar7 = *puVar8 & 0xffffffbf;
          *puVar8 = uVar7;
        }
        else {
          uVar7 = *puVar8 | 0x40;
          *puVar8 = uVar7;
        }
        if (*(char *)(psVar2 + 0x49) == '\0') {
          uVar7 = uVar7 & 0xffffff7f;
          *puVar8 = uVar7;
        }
        else {
          uVar7 = uVar7 | 0x80;
          *puVar8 = uVar7;
        }
        if (*(char *)((int)psVar2 + 0x93) == '\0') {
          uVar7 = uVar7 & 0xfffffeff;
          *puVar8 = uVar7;
        }
        else {
          uVar7 = uVar7 | 0x100;
          *puVar8 = uVar7;
        }
        if ((uVar7 & 0x1e0) != 0) {
          if ((uVar7 & 0x20) != 0) {
            if (*(short *)(iVar9 + 0x3c) != *psVar2) {
              *(short *)(iVar9 + 0x3c) = *psVar2;
            }
            *(undefined4 *)(iVar9 + 0x50) = *(undefined4 *)(psVar2 + 10);
            *(undefined4 *)(iVar9 + 0x54) = *(undefined4 *)(psVar2 + 0xc);
            *(undefined4 *)(iVar9 + 0x58) = *(undefined4 *)(psVar2 + 0xe);
            *(undefined4 *)(iVar9 + 0x5c) = *(undefined4 *)(psVar2 + 0x10);
            *(undefined4 *)(iVar9 + 0x40) = *(undefined4 *)(psVar2 + 2);
            *(undefined4 *)(iVar9 + 0x44) = *(undefined4 *)(psVar2 + 4);
            *(undefined4 *)(iVar9 + 0x48) = *(undefined4 *)(psVar2 + 6);
            *(undefined4 *)(iVar9 + 0x4c) = *(undefined4 *)(psVar2 + 8);
            uVar7 = *puVar8;
          }
          if ((uVar7 & 0x40) != 0) {
            if (*(short *)(iVar9 + 0x60) != psVar2[0x12]) {
              *(short *)(iVar9 + 0x60) = psVar2[0x12];
            }
            *(undefined4 *)(iVar9 + 0x74) = *(undefined4 *)(psVar2 + 0x1c);
            *(undefined4 *)(iVar9 + 0x78) = *(undefined4 *)(psVar2 + 0x1e);
            *(undefined4 *)(iVar9 + 0x7c) = *(undefined4 *)(psVar2 + 0x20);
            *(undefined4 *)(iVar9 + 0x80) = *(undefined4 *)(psVar2 + 0x22);
            *(undefined4 *)(iVar9 + 100) = *(undefined4 *)(psVar2 + 0x14);
            *(undefined4 *)(iVar9 + 0x68) = *(undefined4 *)(psVar2 + 0x16);
            *(undefined4 *)(iVar9 + 0x6c) = *(undefined4 *)(psVar2 + 0x18);
            *(undefined4 *)(iVar9 + 0x70) = *(undefined4 *)(psVar2 + 0x1a);
            uVar7 = *puVar8;
          }
          if ((uVar7 & 0x80) != 0) {
            if (*(short *)(iVar9 + 0x84) != psVar2[0x24]) {
              *(short *)(iVar9 + 0x84) = psVar2[0x24];
            }
            *(undefined4 *)(iVar9 + 0x98) = *(undefined4 *)(psVar2 + 0x2e);
            *(undefined4 *)(iVar9 + 0x9c) = *(undefined4 *)(psVar2 + 0x30);
            *(undefined4 *)(iVar9 + 0xa0) = *(undefined4 *)(psVar2 + 0x32);
            *(undefined4 *)(iVar9 + 0xa4) = *(undefined4 *)(psVar2 + 0x34);
            *(undefined4 *)(iVar9 + 0x88) = *(undefined4 *)(psVar2 + 0x26);
            *(undefined4 *)(iVar9 + 0x8c) = *(undefined4 *)(psVar2 + 0x28);
            *(undefined4 *)(iVar9 + 0x90) = *(undefined4 *)(psVar2 + 0x2a);
            *(undefined4 *)(iVar9 + 0x94) = *(undefined4 *)(psVar2 + 0x2c);
            uVar7 = *puVar8;
          }
          if ((uVar7 & 0x100) != 0) {
            if (*(short *)(iVar9 + 0xa8) != psVar2[0x36]) {
              *(short *)(iVar9 + 0xa8) = psVar2[0x36];
            }
            *(undefined4 *)(iVar9 + 0xbc) = *(undefined4 *)(psVar2 + 0x40);
            *(undefined4 *)(iVar9 + 0xc0) = *(undefined4 *)(psVar2 + 0x42);
            *(undefined4 *)(iVar9 + 0xc4) = *(undefined4 *)(psVar2 + 0x44);
            *(undefined4 *)(iVar9 + 200) = *(undefined4 *)(psVar2 + 0x46);
            *(undefined4 *)(iVar9 + 0xac) = *(undefined4 *)(psVar2 + 0x38);
            *(undefined4 *)(iVar9 + 0xb0) = *(undefined4 *)(psVar2 + 0x3a);
            *(undefined4 *)(iVar9 + 0xb4) = *(undefined4 *)(psVar2 + 0x3c);
            *(undefined4 *)(iVar9 + 0xb8) = *(undefined4 *)(psVar2 + 0x3e);
          }
        }
        *(undefined1 *)(param_1 + 0x269) = 1;
        uVar7 = *(uint *)(param_1 + 0x278);
        *(byte *)(param_1 + 0x26c) = (byte)(1 << (uVar5 & 0x3f)) | *(byte *)(param_1 + 0x26c);
        *(uint *)(param_1 + 0x278) = uVar7 | 0x8000;
        if ("}J3x})+x|B;x}k"[*(int *)(param_1 + 0x10) + 2] != '\0') {
          *(uint *)(param_1 + 0x278) = uVar7 | 0x8020;
        }
      }
      uVar3 = uVar3 >> 1;
      uVar5 = uVar5 + 1;
      iVar4 = iVar4 + 0x94;
      iVar10 = iVar10 + 0xcc;
    } while (uVar3 != 0);
  }
  *(undefined1 *)(param_1 + 0x26b5) = 1;
  return;
}

/* FUN_000a8630 @ 0xa8630 (968 bytes) */
int FUN_000a8630(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  uint param_3;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
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
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  uint uVar32;
  uint uVar33;
  int iVar34;
  int iVar35;
  undefined1 uVar36;
  undefined8 uVar37;
  
  uVar37 = FUN_001a322c();
  iVar34 = (int)((ulonglong)uVar37 >> 0x20);
  iVar35 = (int)uVar37;
  if ((param_3 & 8) != 0) {
    *(uint *)(iVar34 + 0x38) = *(uint *)(iVar34 + 0x38) | 0x80;
    *(uint *)(iVar34 + 0x40) = *(uint *)(iVar34 + 0x40) | 0x20000;
    *(undefined1 *)(iVar34 + 0x29) = 1;
  }
  if (((param_3 & 0x3f000008) != 0) && (*(int *)(((unsigned char *)0x00003e28) + iVar35) != 0)) {
    fVar1 = *(float *)(iVar35 + 0x1920);
    fVar2 = *(float *)(iVar35 + 0x192c);
    fVar3 = *(float *)(iVar35 + 0x1958);
    fVar4 = *(float *)(iVar35 + 0x195c);
    fVar5 = *(float *)(iVar35 + 0x1928);
    fVar6 = *(float *)(iVar35 + 0x1938);
    fVar7 = *(float *)(iVar35 + 0x1948);
    fVar8 = *(float *)(iVar35 + 0x193c);
    fVar9 = *(float *)(iVar35 + 0x1934);
    fVar27 = fVar5 * fVar4 - fVar2 * fVar3;
    fVar26 = fVar5 * fVar8 - fVar2 * fVar6;
    fVar30 = fVar6 * fVar4 - fVar8 * fVar3;
    fVar10 = *(float *)(iVar35 + 0x1924);
    fVar11 = *(float *)(iVar35 + 0x1944);
    fVar12 = *(float *)(iVar35 + 0x194c);
    fVar13 = *(float *)(iVar35 + 0x1954);
    fVar14 = *(float *)(iVar35 + 0x1940);
    fVar25 = fVar5 * fVar12 - fVar2 * fVar7;
    fVar18 = fVar13 * fVar26 + (fVar10 * fVar30 - fVar9 * fVar27);
    fVar29 = fVar6 * fVar12 - fVar8 * fVar7;
    fVar28 = fVar7 * fVar4 - fVar12 * fVar3;
    fVar24 = fVar1 * fVar11 - fVar10 * fVar14;
    fVar31 = -(fVar10 * fVar29 - (fVar9 * fVar25 - fVar11 * fVar26));
    fVar19 = -(fVar10 * fVar28 - (fVar11 * fVar27 - fVar13 * fVar25));
    fVar15 = *(float *)(iVar35 + 0x1950);
    fVar16 = *(float *)(iVar35 + 0x1930);
    fVar17 = fVar13 * fVar29 + (fVar9 * fVar28 - fVar11 * fVar30);
    fVar23 = fVar1 * fVar13 - fVar10 * fVar15;
    fVar20 = fVar16 * fVar13 - fVar9 * fVar15;
    fVar22 = fVar1 * fVar9 - fVar10 * fVar16;
    fVar9 = fVar16 * fVar11 - fVar9 * fVar14;
    fVar21 = fVar1 * fVar17 + fVar16 * fVar19 + fVar15 * fVar31 + fVar14 * fVar18;
    fVar10 = fVar14 * fVar13 - fVar11 * fVar15;
    if ((fVar21 < FLOAT_001aa198) || (uVar36 = 0, FLOAT_001aa19c < fVar21)) {
      uVar36 = 1;
      fVar21 = FLOAT_001aa0e8 / fVar21;
      *(float *)(((unsigned char *)0x000013a4) + iVar34) =
           (fVar22 * fVar7 + (fVar9 * fVar5 - fVar24 * fVar6)) * fVar21;
      *(float *)(((unsigned char *)0x0000136c) + iVar34) =
           fVar21 * -(fVar16 * fVar28 - (fVar14 * fVar30 - fVar15 * fVar29));
      *(float *)(((unsigned char *)0x00001370) + iVar34) =
           (fVar9 * fVar4 + (fVar10 * fVar8 - fVar20 * fVar12)) * fVar21;
      *(float *)(((unsigned char *)0x00001388) + iVar34) = fVar18 * fVar21;
      *(float *)(((unsigned char *)0x00001374) + iVar34) =
           -(fVar10 * fVar6 - (fVar20 * fVar7 - fVar9 * fVar3)) * fVar21;
      *(float *)(((unsigned char *)0x0000137c) + iVar34) =
           fVar21 * (fVar15 * fVar25 + (fVar1 * fVar28 - fVar14 * fVar27));
      *(float *)(((unsigned char *)0x00001380) + iVar34) =
           -(fVar10 * fVar2 - (fVar23 * fVar12 - fVar24 * fVar4)) * fVar21;
      *(float *)(((unsigned char *)0x0000138c) + iVar34) =
           fVar21 * -(fVar1 * fVar30 - (fVar16 * fVar27 - fVar15 * fVar26));
      *(float *)(((unsigned char *)0x00001384) + iVar34) =
           (fVar24 * fVar3 + (fVar10 * fVar5 - fVar23 * fVar7)) * fVar21;
      *(float *)(((unsigned char *)0x0000139c) + iVar34) =
           fVar21 * (fVar14 * fVar26 + (fVar1 * fVar29 - fVar16 * fVar25));
      *(float *)((*(unsigned char *)0x00001390) + iVar34) =
           (fVar22 * fVar4 + (fVar20 * fVar2 - fVar23 * fVar8)) * fVar21;
      *(float *)(((unsigned char *)0x00001368) + iVar34) = fVar17 * fVar21;
      *(float *)(((unsigned char *)0x00001378) + iVar34) = fVar19 * fVar21;
      *(float *)(((unsigned char *)0x00001394) + iVar34) =
           -(fVar20 * fVar5 - (fVar23 * fVar6 - fVar22 * fVar3)) * fVar21;
      *(float *)(((unsigned char *)0x00001398) + iVar34) = fVar31 * fVar21;
      *(float *)(((unsigned char *)0x000013a0) + iVar34) =
           -(fVar9 * fVar2 - (fVar24 * fVar8 - fVar22 * fVar12)) * fVar21;
    }
    uVar32 = *(uint *)(iVar34 + 0x38);
    uVar33 = *(uint *)(iVar34 + 0x40);
    ((unsigned char *)0x000013a8)[iVar34] = uVar36;
    *(uint *)(iVar34 + 0x40) = uVar33 | 0x20000;
    *(uint *)(iVar34 + 0x38) = uVar32 | 0x20080;
    *(undefined1 *)(iVar34 + 0x29) = 1;
    *(undefined2 *)(iVar34 + 0x36) = 0x3f;
  }
  if ((param_3 & 0xf8) != 0) {
    if ((param_3 & 0x10) == 0) {
      uVar32 = *(uint *)(iVar34 + 0x40);
    }
    else {
      uVar32 = *(uint *)(iVar34 + 0x40) | 0x10000;
      *(uint *)(iVar34 + 0x40) = uVar32;
    }
    if (((unsigned char *)0x00004301)[iVar35] != '\0') {
      uVar33 = (uint)(byte)((unsigned char *)0x00004300)[iVar35];
      if ((uint)(byte)((unsigned char *)0x000013b4)[iVar34] < (uint)(byte)((unsigned char *)0x00004300)[iVar35]) {
        uVar33 = (uint)(byte)((unsigned char *)0x000013b4)[iVar34];
      }
      if (1 < uVar33) {
        if ((param_3 & 0x20) == 0) {
          iVar35 = uVar33 - 1;
          uVar33 = 1;
          do {
            uVar33 = uVar33 + 1;
            iVar35 = iVar35 + -1;
            if (iVar35 == 0) goto LAB_000a89c0;
          } while ((param_3 & 0x10 << (uVar33 & 0x3f)) == 0);
        }
        uVar32 = uVar32 | 0x10000;
        *(uint *)(iVar34 + 0x40) = uVar32;
      }
    }
LAB_000a89c0:
    *(uint *)(iVar34 + 0x40) = uVar32 | 0x30000;
    *(undefined1 *)(iVar34 + 0x29) = 1;
    *(uint *)(iVar34 + 0x38) = *(uint *)(iVar34 + 0x38) | 0x80;
  }
  FUN_001a327c();
  return;
}

/* FUN_000a8a00 @ 0xa8a00 (488 bytes) */
int FUN_000a8a00(param_1, param_2)
  int param_1;
  uint param_2;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  undefined *puVar11;
  uint uVar12;
  int iVar13;
  
  fVar6 = FLOAT_001aa0e8;
  uVar12 = 0;
  iVar13 = 6;
  iVar8 = *(int *)(param_1 + 0x10);
  iVar7 = param_1 + 0x618;
  puVar11 = ((unsigned char *)0x00003e20) + iVar8;
  do {
    if (((0x1000000 << (uVar12 & 0x3f) | 8U) & param_2) != 0) {
      uVar9 = 1 << (uVar12 & 0x3f);
      if ((uVar9 & *(uint *)(((unsigned char *)0x00003e28) + iVar8)) != 0) {
        fVar1 = *(float *)(puVar11 + 0x18);
        iVar5 = uVar12 * 0x10;
        fVar2 = *(float *)(puVar11 + 0xc);
        fVar3 = *(float *)(puVar11 + 0x10);
        fVar4 = *(float *)(puVar11 + 0x14);
        iVar10 = iVar5 + iVar7;
        if (fVar1 == fVar6) {
          *(float *)(iVar7 + iVar5) =
               fVar4 * *(float *)(((unsigned char *)0x000015c8) + param_1) +
               fVar2 * *(float *)(((unsigned char *)0x000015a8) + param_1) +
               fVar3 * *(float *)(((unsigned char *)0x000015b8) + param_1) + *(float *)(((unsigned char *)0x000015d8) + param_1);
          *(float *)(iVar10 + 4) =
               fVar4 * *(float *)(((unsigned char *)0x000015cc) + param_1) +
               fVar2 * *(float *)(((unsigned char *)0x000015ac) + param_1) +
               fVar3 * *(float *)(((unsigned char *)0x000015bc) + param_1) + *(float *)(((unsigned char *)0x000015dc) + param_1);
          *(float *)(iVar10 + 8) =
               fVar4 * *(float *)(((unsigned char *)0x000015d0) + param_1) +
               fVar2 * *(float *)(((unsigned char *)0x000015b0) + param_1) +
               fVar3 * *(float *)(((unsigned char *)0x000015c0) + param_1) + *(float *)(((unsigned char *)0x000015e0) + param_1);
          *(float *)(iVar10 + 0xc) =
               fVar4 * *(float *)((int)((unsigned char *)0x000015d4) + param_1) +
               fVar2 * *(float *)(((unsigned char *)0x000015b4) + param_1) +
               fVar3 * *(float *)(((unsigned char *)0x000015c4) + param_1) + *(float *)(((unsigned char *)0x000015e4) + param_1);
        }
        else {
          *(float *)(iVar7 + iVar5) =
               fVar1 * *(float *)(((unsigned char *)0x000015d8) + param_1) +
               fVar4 * *(float *)(((unsigned char *)0x000015c8) + param_1) +
               fVar2 * *(float *)(((unsigned char *)0x000015a8) + param_1) +
               fVar3 * *(float *)(((unsigned char *)0x000015b8) + param_1);
          *(float *)(iVar10 + 4) =
               fVar1 * *(float *)(((unsigned char *)0x000015dc) + param_1) +
               fVar4 * *(float *)(((unsigned char *)0x000015cc) + param_1) +
               fVar2 * *(float *)(((unsigned char *)0x000015ac) + param_1) +
               fVar3 * *(float *)(((unsigned char *)0x000015bc) + param_1);
          *(float *)(iVar10 + 8) =
               fVar1 * *(float *)(((unsigned char *)0x000015e0) + param_1) +
               fVar4 * *(float *)(((unsigned char *)0x000015d0) + param_1) +
               fVar2 * *(float *)(((unsigned char *)0x000015b0) + param_1) +
               fVar3 * *(float *)(((unsigned char *)0x000015c0) + param_1);
          *(float *)(iVar10 + 0xc) =
               fVar1 * *(float *)(((unsigned char *)0x000015e4) + param_1) +
               fVar4 * *(float *)((int)((unsigned char *)0x000015d4) + param_1) +
               fVar2 * *(float *)(((unsigned char *)0x000015b4) + param_1) +
               fVar3 * *(float *)(((unsigned char *)0x000015c4) + param_1);
        }
      }
      *(ushort *)(param_1 + 0x276) = (ushort)uVar9 | *(ushort *)(param_1 + 0x276);
    }
    uVar12 = uVar12 + 1;
    puVar11 = puVar11 + 0x10;
    iVar13 = iVar13 + -1;
  } while (iVar13 != 0);
  *(undefined1 *)(param_1 + 0x269) = 1;
  *(uint *)(param_1 + 0x278) = *(uint *)(param_1 + 0x278) | 0x20000;
  return;
}

/* FUN_000a8c00 @ 0xa8c00 (356 bytes) */
int FUN_000a8c00(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  if (((unsigned char *)0x00002e2d)[param_2] != '\0') {
    *(undefined1 *)(param_1 + 0x2f) = 0;
    *(undefined1 *)(param_1 + 0x2940) = 1;
    *(uint *)(param_1 + 0x1808) = *(uint *)(param_1 + 0x1808) | 0x20000000;
  }
  if (((unsigned char *)0x00002e2c)[param_2] != '\0') {
    *(undefined1 *)(param_1 + 0x2f) = 0;
    *(undefined1 *)(param_1 + 0x2940) = 1;
    *(uint *)(param_1 + 0x1808) = *(uint *)(param_1 + 0x1808) | 0x20000000;
  }
  iVar3 = *(int *)(param_1 + 4);
  if ((((unsigned char *)0x00002e2d)[*(int *)(iVar3 + 0x10)] != '\0') &&
     ((*(uint *)(param_1 + 0x44) & 0x20000) == 0)) {
    iVar3 = FUN_0001a010(iVar3,*(undefined4 *)(iVar3 + 0x26a0));
    if (iVar3 == 0) {
      iVar3 = *(int *)(param_1 + 4);
      uVar4 = 1;
      goto LAB_000a8cb4;
    }
    iVar3 = *(int *)(param_1 + 4);
  }
  uVar4 = 0;
LAB_000a8cb4:
  uVar2 = *(uint *)(param_1 + 0x1928);
  uVar1 = uVar2 >> 4 & 1 ^ uVar4;
  *(uint *)(param_1 + 0x1928) = uVar2 & 0xffffffef | uVar1 | uVar4 << 4;
  if (((((unsigned char *)0x00002e2c)[*(int *)(iVar3 + 0x10)] == '\0') ||
      ((*(uint *)(param_1 + 0x44) & 0x20000) != 0)) ||
     (uVar5 = 1, *(short *)(((unsigned char *)0x00002e28) + *(int *)(iVar3 + 0x10)) == -1)) {
    uVar5 = 0;
  }
  *(undefined1 *)(param_1 + 0x29) = 1;
  *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 6;
  *(uint *)(param_1 + 0x1928) =
       uVar2 & 0xffffffe7 | uVar1 | uVar4 << 4 | (uVar2 & 8) >> 3 ^ uVar5 | uVar5 << 3;
  return;
}

/* FUN_000a8d70 @ 0xa8d70 (168 bytes) */
int FUN_000a8d70(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  uint uVar2;
  
  if (((unsigned char *)0x00003178)[param_2] != '\0') {
    *(undefined1 *)(param_1 + 0x2f) = 0;
    *(undefined1 *)(param_1 + 0x2940) = 1;
    *(uint *)(param_1 + 0x1808) = *(uint *)(param_1 + 0x1808) | 0x20000000;
  }
  *(undefined1 *)(param_1 + 0x29) = 1;
  *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 4;
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (((((unsigned char *)0x00003178)[iVar1] == '\0') || ((*(uint *)(param_1 + 0x44) & 0x20000) != 0)) ||
     ((*(short *)(((unsigned char *)0x00003170) + iVar1) != 0x1b02 && (*(short *)(((unsigned char *)0x00003172) + iVar1) != 0x1b02))
     )) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  *(uint *)(param_1 + 0x1928) =
       *(uint *)(param_1 + 0x1928) & 0xfffffffb | *(uint *)(param_1 + 0x1928) >> 2 & 1 ^ uVar2 |
       uVar2 << 2;
  return;
}

/* FUN_000a8e20 @ 0xa8e20 (544 bytes) */
int FUN_000a8e20(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint param_3;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if ((param_3 & 0x1000) == 0) {
    uVar4 = *(uint *)(param_1 + 0x44);
    uVar2 = (uint)(byte)((unsigned char *)0x00002e0b)[param_2];
    goto LAB_000a8ee8;
  }
  if (((unsigned char *)0x00002e0a)[param_2] == '\0') {
    uVar3 = *(uint *)(param_1 + 0x44);
LAB_000a8e54:
    uVar2 = 0;
  }
  else {
    uVar3 = *(uint *)(param_1 + 0x44);
    uVar2 = 1;
    if ((uVar3 & 0x2000) != 0) goto LAB_000a8e54;
  }
  uVar1 = *(uint *)(param_1 + 0x38);
  uVar4 = uVar2 << 0x18 | uVar3 & 0xfeffffff;
  *(uint *)(param_1 + 0x44) = uVar4;
  *(uint *)(param_1 + 0x38) = uVar1 | 0x100;
  *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x40;
  *(uint *)(param_1 + 0x18a4) = uVar2 | *(uint *)(param_1 + 0x18a4) & 0xfffffffe;
  *(undefined1 *)(param_1 + 0x29) = 1;
  uVar2 = (uint)(byte)((unsigned char *)0x00002e0b)[param_2];
  if ((("}J3x})+x|B;x}k"[param_2 + 2] != '\0' || ((unsigned char *)0x00002e0b)[param_2] != 0) ||
      (uVar3 & 0x200000) != 0) || (uVar3 & 0x10000) != 0) {
    *(uint *)(param_1 + 0x38) = uVar1 | 0x120;
    uVar2 = (uint)(byte)((unsigned char *)0x00002e0b)[param_2];
  }
LAB_000a8ee8:
  if ((uVar4 >> 0x17 & 1) != uVar2) {
    uVar3 = *(uint *)(param_1 + 0x38);
    *(uint *)(param_1 + 0x44) = (uVar2 & 1) << 0x17 | uVar4 & 0xff7fffff;
    *(undefined1 *)(param_1 + 0x29) = 1;
    *(uint *)(param_1 + 0x38) = uVar3 | 0x120;
    if (*(int *)(param_1 + -0x70) != 0) {
      *(uint *)(param_1 + 0x38) = uVar3 | 0x2320;
      *(byte *)(param_1 + 0x2e) = *(byte *)(param_1 + 0x2e) | 2;
    }
    if (((unsigned char *)0x00004304)[param_2] == '\0') {
      if ((int)*(uint *)(param_1 + 0x44) < 0) {
        uVar2 = *(uint *)(param_1 + 0x18a4);
        uVar4 = (uint)(*(short *)("}J3x})+x|B;x}k" + param_2) == -0x7e06) << 2;
        *(uint *)(param_1 + 0x18a4) = uVar4 | uVar2 & 0xfffffffb;
        *(uint *)(param_1 + 0x18a4) =
             ((byte)"}J3x})+x|B;x}k"[param_2 + 4] & 1) << 1 | uVar4 | uVar2 & 0xfffffff9;
      }
      else {
        *(uint *)(param_1 + 0x18a4) =
             *(uint *)(param_1 + 0x44) >> 0x15 & 4 | *(uint *)(param_1 + 0x18a4) & 0xfffffff9;
      }
    }
    else {
      *(uint *)(param_1 + 0x18a4) =
           (uint)((undefined1 *)(*(uint *)(param_1 + 0x44) & 0x80040) == ((unsigned char *)0x00080040)) << 1 |
           *(uint *)(param_1 + 0x44) >> 0x15 & 4 | *(uint *)(param_1 + 0x18a4) & 0xfffffff9;
    }
  }
  if ((param_3 & 0x800) != 0) {
    uVar4 = *(uint *)(param_1 + 0x38);
    *(undefined1 *)(param_1 + 0x29) = 1;
    *(uint *)(param_1 + 0x38) = uVar4 | 0x100;
    if ("}J3x})+x|B;x}k"[param_2 + 2] != '\0') {
      *(uint *)(param_1 + 0x38) = uVar4 | 0x120;
    }
    if (*(int *)(param_1 + -0x70) == 0) {
      if (*(int *)(param_1 + -0x74) != 0) {
        *(undefined1 *)(param_1 + 0x29) = 1;
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
        *(byte *)(param_1 + 0x2d) = *(byte *)(param_1 + 0x2d) | 3;
        return;
      }
      return;
    }
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x2200;
    *(byte *)(param_1 + 0x2e) = *(byte *)(param_1 + 0x2e) | 2;
    return;
  }
  return;
}

/* FUN_000a9070 @ 0xa9070 (1476 bytes) */
int FUN_000a9070(param_1, param_2)
  int param_1;
  uint param_2;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  ushort uVar8;
  uint uVar9;
  int iVar10;
  uint *puVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  undefined4 *puVar18;
  undefined2 *puVar19;
  
  uVar9 = param_2 | param_2 >> 0x10;
  uVar9 = (uVar9 | uVar9 >> 8) & 0xff;
  *(ushort *)(param_1 + 0x272) = (ushort)uVar9 | *(ushort *)(param_1 + 0x272);
  if (uVar9 != 0) {
    uVar16 = 0;
    iVar17 = 0;
    iVar15 = param_1 + 0x240;
    do {
      if ((uVar9 & 1) != 0) {
        puVar18 = (undefined4 *)(((unsigned char *)0x000031c4) + uVar16 * 0x7c + *(int *)(param_1 + 0x10));
        puVar19 = (undefined2 *)(param_1 + 0x690 + uVar16 * 0xcc);
        if ((uVar16 == *(uint *)(param_1 + 0x29ac)) && (*(int *)(param_1 + 0x29a8) != 0)) {
          iVar10 = *(int *)(*(int *)(param_1 + 0x29a8) + 0xbc);
          uVar13 = 1 << (uVar16 & 0x3f);
        }
        else {
          iVar10 = *(int *)(((unsigned char *)0x000013f8) + iVar15);
          uVar13 = 1 << (uVar16 & 0x3f);
          if (iVar10 == 0) {
            *(uint *)(param_1 + 0x29f4) = ~uVar13 & *(uint *)(param_1 + 0x29f4);
            *(uint *)(param_1 + 0x29f0) = ~uVar13 & *(uint *)(param_1 + 0x29f0);
          }
        }
        if ((param_2 & uVar13) != 0) {
          iVar14 = iVar17 + param_1 + 0x1ae4;
          *puVar19 = *(undefined2 *)(puVar18 + 5);
          uVar5 = *(ushort *)(puVar18 + 5);
          *(uint *)(iVar14 + 8) =
               (((uint)uVar5 * 0x3b >> 0xd & 1 | (uint)uVar5 * 0x107 >> 10 & 2 | uVar5 >> 3 & 4) ^ 1
               ) << 1 | *(uint *)(iVar14 + 8) & 0xfffffff1;
        }
        if ((param_2 & 0x10000 << (uVar16 & 0x3f)) != 0) {
          *(undefined4 *)(puVar19 + 0x10) = puVar18[0xf];
          if (iVar10 != 0) {
            iVar10 = iVar10 + 0x4c;
          }
          FUN_00086a10(param_1 + 0x240,puVar19,iVar10);
        }
        if ((param_2 & 0x100 << (uVar16 & 0x3f)) != 0) {
          *(undefined4 *)(puVar19 + 0x16) = *puVar18;
          *(undefined4 *)(puVar19 + 0x18) = puVar18[1];
          *(undefined4 *)(puVar19 + 0x1a) = puVar18[2];
          *(undefined4 *)(puVar19 + 0x1c) = puVar18[3];
          *(undefined1 *)(param_1 + 0x269) = 1;
          *(uint *)(param_1 + 0x27c) = *(uint *)(param_1 + 0x27c) | 0x400;
        }
        if ((param_2 & 0x1000000 << (uVar16 & 0x3f)) != 0) {
          uVar13 = (uint)*(ushort *)(puVar18 + 6);
          iVar10 = param_1 + 0x1ae8;
          uVar5 = *(ushort *)((int)puVar18 + 0x1a);
          uVar12 = (uint)uVar5;
          uVar6 = puVar19[1];
          puVar11 = (uint *)(iVar10 + iVar17);
          if (uVar13 != (ushort)puVar19[2]) {
            puVar19[2] = *(ushort *)(puVar18 + 6);
            puVar11[1] = ((uVar13 * 0xb5 >> 7 & 1 | uVar13 * 0x177 >> 8 & 2 |
                           uVar13 * 0x19f >> 6 & 4 | uVar13 * 0x1bb >> 5 & 8) ^ 0xf) << 7 |
                         puVar11[1] & 0xfffff87f;
          }
          uVar7 = puVar19[3];
          uVar8 = *(ushort *)(puVar18 + 7);
          uVar13 = (uint)uVar8;
          if (uVar12 != uVar6) {
            puVar19[1] = uVar5;
            puVar11[1] = ((uVar12 * 0xc3 >> 8 & 1 | uVar12 * 0x165 >> 9 & 2 | uVar12 * 0xb >> 8 & 4
                          | uVar12 * 0xcb >> 6 & 8) ^ 10) << 0xd | puVar11[1] & 0xfffe1fff;
          }
          uVar5 = *(ushort *)((int)puVar18 + 0x22);
          uVar12 = (uint)uVar5;
          uVar6 = puVar19[6];
          if (uVar13 != uVar7) {
            puVar19[3] = uVar8;
            puVar11[1] = ((uVar13 * 0x11 >> 4 & 1 | uVar13 * 0x37 >> 6 & 2 | uVar13 * 0x51 >> 7 & 4
                          | uVar13 * 0x15 >> 6 & 8) ^ 0xc) << 0x18 | puVar11[1] & 0xf0ffffff;
          }
          uVar7 = *(ushort *)(puVar18 + 10);
          uVar8 = puVar19[9];
          if (uVar12 != uVar6) {
            puVar19[6] = uVar5;
            *(uint *)(iVar10 + iVar17) =
                 ((uVar12 * 0x11 >> 4 & 1 | uVar12 * 0x37 >> 6 & 2 | uVar12 * 0x51 >> 7 & 4 |
                  uVar12 * 0x15 >> 6 & 8) ^ 0xc) << 8 | *(uint *)(iVar10 + iVar17) & 0xfffff0ff;
          }
          uVar5 = *(ushort *)((int)puVar18 + 0x2e);
          uVar6 = puVar19[0xc];
          if ((uint)uVar7 != (uint)uVar8) {
            puVar19[9] = uVar7;
            *(uint *)(iVar10 + iVar17) =
                 (uVar7 & 3) << 0x14 | *(uint *)(iVar10 + iVar17) & 0xffcfffff;
          }
          uVar7 = puVar19[4];
          uVar8 = *(ushort *)((int)puVar18 + 0x1e);
          uVar13 = (uint)uVar8;
          if ((uint)uVar5 != (uint)uVar6) {
            puVar19[0xc] = uVar5;
            *(uint *)(iVar10 + iVar17) =
                 (uVar5 & 1) << 0x1a | *(uint *)(iVar10 + iVar17) & 0xfbffffff;
          }
          uVar5 = *(ushort *)(puVar18 + 9);
          uVar12 = (uint)uVar5;
          uVar6 = puVar19[7];
          if (uVar13 != uVar7) {
            puVar19[4] = uVar8;
            puVar11[1] = ((uVar13 * 0x11 >> 4 & 1 | uVar13 * 0x37 >> 6 & 2 | uVar13 * 0x51 >> 7 & 4
                          | uVar13 * 0x15 >> 6 & 8) ^ 0xc) << 0x1c | puVar11[1] & 0xfffffff;
          }
          uVar7 = puVar19[10];
          uVar8 = *(ushort *)((int)puVar18 + 0x2a);
          if (uVar12 != uVar6) {
            puVar19[7] = uVar5;
            *(uint *)(iVar10 + iVar17) =
                 ((uVar12 * 0x11 >> 4 & 1 | uVar12 * 0x37 >> 6 & 2 | uVar12 * 0x51 >> 7 & 4 |
                  uVar12 * 0x15 >> 6 & 8) ^ 0xc) << 0xc | *(uint *)(iVar10 + iVar17) & 0xffff0fff;
          }
          uVar5 = *(ushort *)(puVar18 + 0xc);
          uVar6 = puVar19[0xd];
          if ((uint)uVar8 != (uint)uVar7) {
            puVar19[10] = uVar8;
            *(uint *)(iVar10 + iVar17) =
                 (uVar8 & 3) << 0x16 | *(uint *)(iVar10 + iVar17) & 0xff3fffff;
          }
          uVar7 = puVar19[5];
          uVar8 = *(ushort *)(puVar18 + 8);
          uVar13 = (uint)uVar8;
          if ((uint)uVar5 != (uint)uVar6) {
            puVar19[0xd] = uVar5;
            *(uint *)(iVar10 + iVar17) =
                 (uVar5 & 1) << 0x1b | *(uint *)(iVar10 + iVar17) & 0xf7ffffff;
          }
          uVar5 = *(ushort *)((int)puVar18 + 0x26);
          uVar12 = (uint)uVar5;
          uVar6 = puVar19[8];
          if (uVar13 != uVar7) {
            puVar19[5] = uVar8;
            *puVar11 = ((uVar13 * 0x11 >> 4 & 1 | uVar13 * 0x37 >> 6 & 2 | uVar13 * 0x51 >> 7 & 4 |
                        uVar13 * 0x15 >> 6 & 8) ^ 0xc) << 4 | *puVar11 & 0xffffff0f;
          }
          uVar7 = puVar19[0xb];
          uVar8 = *(ushort *)(puVar18 + 0xb);
          if (uVar12 != uVar6) {
            puVar19[8] = uVar5;
            *puVar11 = ((uVar12 * 0x11 >> 4 & 1 | uVar12 * 0x37 >> 6 & 2 | uVar12 * 0x51 >> 7 & 4 |
                        uVar12 * 0x15 >> 6 & 8) ^ 0xc) << 0x10 | *puVar11 & 0xfff0ffff;
          }
          uVar5 = *(ushort *)((int)puVar18 + 0x32);
          uVar6 = puVar19[0xe];
          if ((uint)uVar8 != (uint)uVar7) {
            puVar19[0xb] = uVar8;
            *puVar11 = (uVar8 & 3) << 0x18 | *puVar11 & 0xfcffffff;
          }
          fVar1 = (float)puVar18[0xd];
          fVar2 = *(float *)(puVar19 + 0x12);
          if ((uint)uVar5 != (uint)uVar6) {
            puVar19[0xe] = uVar5;
            *puVar11 = (uVar5 & 1) << 0x1c | *puVar11 & 0xefffffff;
          }
          fVar3 = (float)puVar18[0xe];
          fVar4 = *(float *)(puVar19 + 0x14);
          if (fVar1 != fVar2) {
            *(float *)(puVar19 + 0x12) = fVar1;
            uVar13 = 1;
            if (FLOAT_001aa128 < fVar1) {
              uVar13 = 3 - (fVar1 <= FLOAT_001aa158);
            }
            puVar11[1] = (uVar13 & 3) << 0xb | puVar11[1] & 0xffffe7ff;
          }
          if (fVar3 != fVar4) {
            *(float *)(puVar19 + 0x14) = fVar3;
            uVar13 = 1;
            if (FLOAT_001aa128 < fVar3) {
              uVar13 = 3 - (fVar3 <= FLOAT_001aa158);
            }
            puVar11[1] = (uVar13 & 3) << 0x11 | puVar11[1] & 0xfff9ffff;
          }
        }
      }
      uVar9 = uVar9 >> 1;
      uVar16 = uVar16 + 1;
      iVar17 = iVar17 + 8;
      iVar15 = iVar15 + 4;
    } while (uVar9 != 0);
  }
  *(uint *)(param_1 + 0x278) = *(uint *)(param_1 + 0x278) | 0x200;
  return;
}

/* FUN_000a9640 @ 0xa9640 (1116 bytes) */
int FUN_000a9640(param_1, param_2)
  int param_1;
  int param_2;
{
  byte bVar1;
  byte bVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  bool bVar8;
  float fVar9;
  uint uVar10;
  undefined4 uVar11;
  uint uVar12;
  double dVar13;
  
  bVar1 = ((unsigned char *)0x000030dc)[param_2];
  uVar10 = *(uint *)(param_1 + 0x44);
  uVar12 = (bVar1 & 1) << 0x1e;
  *(uint *)(param_1 + 0x44) = uVar12 | uVar10 & 0xbfffffff;
  bVar2 = ((unsigned char *)0x000030dd)[param_2];
  *(uint *)(param_1 + 0x44) = (bVar2 & 1) << 0x1d | uVar12 | uVar10 & 0x9fffffff;
  if ((bVar2 & 1) != 0 || (bVar1 & 1) != 0) {
    *(undefined1 *)(param_1 + 0x2f) = 0;
    *(undefined1 *)(param_1 + 0x2940) = 1;
    *(uint *)(param_1 + 0x1808) = *(uint *)(param_1 + 0x1808) | 0x20000000;
  }
  uVar11 = *(undefined4 *)((*(unsigned char *)0x000013d0) + param_1);
  *(undefined4 *)(param_1 + 0xec) = *(undefined4 *)(((unsigned char *)0x000030e4) + param_2);
  dVar13 = DOUBLE_001aa250;
  fVar3 = *(float *)(((unsigned char *)0x000030c0) + param_2);
  fVar4 = *(float *)(((unsigned char *)0x000013c4) + param_1);
  *(float *)(param_1 + 0xf4) = fVar3;
  fVar5 = fVar3;
  if (fVar3 - fVar4 < 0.0) {
    fVar5 = fVar4;
  }
  fVar6 = fVar4;
  if (-(fVar3 - fVar4) < 0.0) {
    fVar6 = fVar5;
  }
  *(float *)(param_1 + 0x100) = fVar6;
  if (fVar3 <= (float)((double)CONCAT44(0x43300000,uVar11) - dVar13)) {
    *(undefined4 *)(param_1 + 0x108) = uVar11;
  }
  else {
    *(int *)(param_1 + 0x108) = (int)fVar3;
  }
  uVar11 = *(undefined4 *)(((unsigned char *)0x000013d4) + param_1);
  fVar3 = *(float *)(((unsigned char *)0x000030c4) + param_2);
  *(float *)(param_1 + 0xf8) = fVar3;
  fVar5 = *(float *)((*(unsigned char *)0x000013c8) + param_1);
  fVar6 = fVar5;
  if (fVar3 - fVar5 < 0.0) {
    fVar6 = fVar3;
  }
  if (-(fVar3 - fVar5) < 0.0) {
    fVar6 = fVar5;
  }
  *(float *)(param_1 + 0x104) = fVar6;
  if ((float)((double)CONCAT44(0x43300000,uVar11) - DOUBLE_001aa250) <= fVar3) {
    *(undefined4 *)(param_1 + 0x10c) = uVar11;
  }
  else {
    *(int *)(param_1 + 0x10c) = (int)fVar3;
  }
  fVar3 = *(float *)(((unsigned char *)0x000013cc) + param_1);
  *(undefined4 *)(param_1 + 0xf0) = *(undefined4 *)(((unsigned char *)0x000030bc) + param_2);
  fVar6 = *(float *)(((unsigned char *)0x000030bc) + param_2);
  fVar7 = fVar4;
  if ((fVar4 < fVar6) && (fVar7 = fVar5, fVar6 < fVar5)) {
    fVar7 = fVar3 * (float)((double)CONCAT44(0x43300000,
                                             (int)((fVar6 - fVar4) / fVar3 + FLOAT_001aa10c) ^
                                             0x80000000) - DOUBLE_001aa1e0) + fVar4;
  }
  *(float *)(param_1 + 0xe0) = fVar7;
  fVar9 = FLOAT_001aa0e8;
  fVar6 = *(float *)(((unsigned char *)0x000030bc) + param_2);
  fVar7 = fVar4;
  if ((fVar4 < fVar6) && (fVar7 = fVar5, fVar6 < fVar5)) {
    fVar7 = fVar3 * (float)((double)CONCAT44(0x43300000,
                                             (int)((fVar6 - fVar4) / fVar3 + FLOAT_001aa10c) ^
                                             0x80000000) - DOUBLE_001aa1e0) + fVar4;
  }
  *(int *)(param_1 + 0xe4) = (int)fVar7;
  *(undefined4 *)(param_1 + 0xfc) = *(undefined4 *)(((unsigned char *)0x000030c8) + param_2);
  *(undefined4 *)(param_1 + 0x110) = *(undefined4 *)(((unsigned char *)0x000030cc) + param_2);
  *(undefined4 *)(param_1 + 0x114) = *(undefined4 *)(((unsigned char *)0x000030d0) + param_2);
  uVar11 = *(undefined4 *)(((unsigned char *)0x000030d4) + param_2);
  *(float *)(param_1 + 0x11c) = fVar9;
  *(undefined4 *)(param_1 + 0x118) = uVar11;
  if (((*(float *)(((unsigned char *)0x000030cc) + param_2) == fVar9) &&
      (*(float *)(((unsigned char *)0x000030d0) + param_2) == FLOAT_001aa0d4)) &&
     (*(float *)(((unsigned char *)0x000030d4) + param_2) == FLOAT_001aa0d4)) {
    uVar12 = *(uint *)(param_1 + 0xe8) & 0xfffffffe;
    *(uint *)(param_1 + 0xe8) = uVar12;
    *(uint *)(param_1 + 0x1874) = *(uint *)(param_1 + 0x1874) & 0xff7fffff;
    *(uint *)(param_1 + 0x1928) =
         *(uint *)(param_1 + 0x1928) & 0xfffffffd | *(uint *)(param_1 + 0x1928) >> 1 & 1;
  }
  else {
    uVar12 = *(uint *)(param_1 + 0xe8) | 1;
    *(uint *)(param_1 + 0xe8) = uVar12;
    *(uint *)(param_1 + 0x1874) = *(uint *)(param_1 + 0x1874) | 0x800000;
    if (*(int *)(*(int *)(param_1 + 4) + 0x1cc) == 0) {
      *(uint *)(param_1 + 0x1928) =
           *(uint *)(param_1 + 0x1928) & 0xfffffffd | (*(uint *)(param_1 + 0x1928) ^ 2) >> 1 & 1 | 2
      ;
    }
  }
  if (*(short *)(((unsigned char *)0x000030e2) + param_2) == 0x60b4) {
    uVar12 = uVar12 & 0xfffffff7;
    *(uint *)(param_1 + 0xe8) = uVar12;
  }
  else {
    uVar12 = uVar12 | 8;
    *(uint *)(param_1 + 0xe8) = uVar12;
  }
  if ((*(int *)(param_1 + 0xe4) < 2) && ((uVar12 & 1) == 0)) {
    bVar8 = false;
    uVar11 = 0;
    if (*(int *)(param_1 + 0xec) == 0) goto LAB_000a99e8;
  }
  bVar8 = true;
  uVar11 = 1;
LAB_000a99e8:
  *(undefined4 *)(param_1 + 0x1940) = uVar11;
  if (bVar8) {
    fVar3 = *(float *)(*(int *)(param_1 + 4) + 0x2a54);
    fVar4 = *(float *)(*(int *)(param_1 + 4) + 0x2a58);
    fVar3 = (fVar3 + fVar3) * *(float *)(param_2 + 0x1810);
    fVar4 = (fVar4 + fVar4) * *(float *)(param_2 + 0x1814);
    if (fVar3 == FLOAT_001aa0d4) {
      *(float *)(param_1 + 400) = FLOAT_001aa0d4;
    }
    else {
      *(float *)(param_1 + 400) = FLOAT_001aa0e8 / fVar3;
    }
    if (fVar4 == FLOAT_001aa0d4) {
      *(float *)(param_1 + 0x194) = FLOAT_001aa0d4;
    }
    else {
      *(float *)(param_1 + 0x194) = FLOAT_001aa0e8 / fVar4;
    }
    dVar13 = (double)_sqrt((double)(*(float *)(param_1 + 400) * *(float *)(param_1 + 400) +
                                   *(float *)(param_1 + 0x194) * *(float *)(param_1 + 0x194)));
    *(float *)(param_1 + 0x198) = (float)dVar13;
  }
  *(undefined1 *)(param_1 + 0x29) = 1;
  *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0xc;
  return;
}

/* FUN_000a9ac0 @ 0xa9ac0 (7656 bytes) */
int FUN_000a9ac0(param_1, param_2)
  int param_1;
  uint *param_2;
{
  bool bVar1;
  byte bVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  int iVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  double dVar16;
  int iVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  uint uVar21;
  code *pcVar22;
  uint uVar23;
  char cVar25;
  int iVar24;
  int iVar26;
  undefined *puVar27;
  uint uVar28;
  uint uVar29;
  int iVar30;
  int iVar31;
  uint uVar32;
  char cVar33;
  int unaff_r20;
  float unaff_r21;
  int iVar34;
  uint uVar35;
  int iVar36;
  uint uVar37;
  byte bVar39;
  int iVar38;
  int iVar40;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  float local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  float local_40;
  int local_3c;
  int local_38;
  int local_34;
  
  uVar37 = *param_2;
  iVar36 = *(int *)(param_1 + 4);
  uVar35 = param_2[2];
  if ((((uVar37 & 0x20000180) != 0) || (*(int *)(iVar36 + 0x2a48) != *(int *)(iVar36 + 0x15c))) ||
     (*(int *)(iVar36 + 0x2a4c) != *(int *)(iVar36 + 0x160))) {
    FUN_00019c50(iVar36);
  }
  if (*(char *)(iVar36 + 0x2a43) != '\0') {
    uVar35 = uVar35 | 1;
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x400;
    *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x1002;
    *(undefined1 *)(param_1 + 0x29) = 1;
  }
  if (((unsigned char *)0x00002b7d)[iVar36] != '\0') {
    iVar31 = *(int *)(param_1 + 4);
    uVar21 = *(uint *)(iVar31 + 0x154) >> 6 & 1;
    ((unsigned char *)0x00001490)[param_1] = (char)uVar21;
    ((unsigned char *)0x00001491)[param_1] = (byte)(*(uint *)(iVar31 + 0x154) >> 7) & 1;
    if (uVar21 != 0) {
      uVar37 = uVar37 | 0x200;
    }
    uVar35 = uVar35 | 1;
    *(undefined1 *)(param_1 + 0x29) = 1;
    uVar37 = uVar37 | 0x4000001;
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x4000;
  }
  iVar34 = *(int *)(iVar36 + 0x10);
  uVar21 = param_2[3];
  iVar31 = *(int *)(((unsigned char *)0x00003e28) + iVar34);
  if (*(int *)(iVar36 + 0x1cc) == 0) {
    *(undefined4 *)(iVar36 + 0x26c4) = 0;
    *(undefined4 *)(iVar36 + 0x26c0) = 0;
    if (uVar35 == 0 && uVar21 == 0) goto LAB_000aaa50;
    if ((uVar21 & 0x4400000) != 0) {
      iVar17 = *(int *)(param_1 + -0x74);
      uVar28 = *(uint *)(param_1 + 0x44);
      iVar31 = iVar17 + -1 + (uint)(iVar17 == 0);
      if (iVar17 - iVar31 == (uVar28 >> 0x14 & 1)) {
        if (((iVar17 != iVar31) || (uVar28 >> 0x1f == (uint)(byte)"}J3x})+x|B;x}k"[iVar34 + 2])) ||
           (((unsigned char *)0x00004304)[iVar34] != '\0')) goto LAB_000a9de4;
LAB_000a9c74:
        uVar23 = *(uint *)(param_1 + 0x1874) >> 0x17 & 1;
        *(uint *)(param_1 + 0x1928) =
             *(uint *)(param_1 + 0x1928) & 0xfffffffd |
             *(uint *)(param_1 + 0x1928) >> 1 & 1 ^ uVar23 | uVar23 << 1;
        if (((unsigned char *)0x00004304)[iVar34] == '\0') {
          *(undefined1 *)(param_1 + 0x2475) = 1;
          uVar28 = (uint)(byte)"}J3x})+x|B;x}k"[iVar34 + 2] << 0x1f | uVar28 & 0x7fffffff;
          *(uint *)(param_1 + 0x44) = uVar28;
        }
        else if ((int)uVar28 < 0) {
          uVar28 = uVar28 & 0x7fffffff;
          *(uint *)(param_1 + 0x44) = uVar28;
          *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
        }
        pcVar22 = *(code **)(((unsigned char *)0x000012b0) + param_1);
        *(uint *)(param_1 + 0x44) = uVar28 & 0xffe7ffff;
        *(undefined1 *)(param_1 + 299) = 1;
        (*pcVar22)(param_1);
        bVar39 = ((unsigned char *)0x000013b6)[param_1];
        *(undefined1 *)(param_1 + 0x29) = 1;
        uVar23 = *(uint *)(param_1 + 0x38) | 0x58a60;
        *(uint *)(param_1 + 0x38) = uVar23;
        *(ushort *)(param_1 + 0x34) =
             (short)(1 << (bVar39 & 0x3f)) - 1U | *(ushort *)(param_1 + 0x34);
      }
      else {
        if (iVar17 == iVar31) goto LAB_000a9c74;
        uVar23 = *(uint *)(param_1 + 0x38);
        *(uint *)(param_1 + 0x44) = uVar28 | 0x180000;
        *(undefined1 *)(param_1 + 299) = 1;
        *(uint *)(param_1 + 0x1928) =
             *(uint *)(param_1 + 0x1928) & 0xfffffffd | *(uint *)(param_1 + 0x1928) >> 1 & 1;
      }
      if (((unsigned char *)0x00004304)[iVar34] == '\0') {
        if ((int)*(uint *)(param_1 + 0x44) < 0) {
          uVar29 = *(uint *)(param_1 + 0x18a4);
          uVar28 = (uint)(*(short *)("}J3x})+x|B;x}k" + iVar34) == -0x7e06) << 2;
          *(uint *)(param_1 + 0x18a4) = uVar28 | uVar29 & 0xfffffffb;
          *(uint *)(param_1 + 0x18a4) =
               ((byte)"}J3x})+x|B;x}k"[iVar34 + 4] & 1) << 1 | uVar28 | uVar29 & 0xfffffff9;
        }
        else {
          *(uint *)(param_1 + 0x18a4) =
               *(uint *)(param_1 + 0x44) >> 0x15 & 4 | *(uint *)(param_1 + 0x18a4) & 0xfffffff9;
        }
      }
      else {
        *(uint *)(param_1 + 0x18a4) =
             (uint)((undefined1 *)(*(uint *)(param_1 + 0x44) & 0x80040) == ((unsigned char *)0x00080040)) << 1 |
             *(uint *)(param_1 + 0x44) >> 0x15 & 4 | *(uint *)(param_1 + 0x18a4) & 0xfffffff9;
      }
      *(uint *)(param_1 + 0x38) = uVar23 | 0x1000;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(byte *)(param_1 + 0x2d) = *(byte *)(param_1 + 0x2d) | 0xf;
    }
LAB_000a9de4:
    if ((uVar21 & 0x7000000) != 0) {
      *(undefined1 *)(param_1 + 0x29) = 1;
      bVar39 = *(byte *)(param_1 + 0x2e) | 2;
      if ((uVar21 & 0x5000000) != 0) {
        uVar29 = *(uint *)(param_1 + 0x44);
        bVar39 = *(byte *)(param_1 + 0x2e) | 3;
        uVar23 = uVar29 >> 0xf & 1;
        uVar28 = uVar29 >> 0xd & 1;
        if (*(int *)(param_1 + -0x70) == 0) {
          if (uVar28 == 0) {
            if (uVar23 != 0) {
              *(uint *)(param_1 + 0x44) = uVar29 & 0xfffd7fff;
              *(uint *)(param_1 + 0x1874) = *(uint *)(param_1 + 0x1874) & 0xffffbfff;
              if ((uVar29 & 0x4000) != 0) {
                *(undefined1 *)(param_1 + 0x29) = 1;
                *(uint *)(param_1 + 0x44) = uVar29 & 0xfffc3fff;
                *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
              }
            }
          }
          else {
            *(uint *)(param_1 + 0x44) = uVar29 & 0xfffddfff;
            *(uint *)(param_1 + 0x1874) = *(uint *)(param_1 + 0x1874) & 0xffffbfff;
            FUN_0008d470(param_1);
          }
        }
        else if (*(char *)(param_1 + 0x279c) == '\0') {
          if (uVar23 == 0) {
            if (uVar28 != 0) {
              *(uint *)(param_1 + 0x44) = uVar29 & 0xfffddfff;
              *(uint *)(param_1 + 0x1874) = *(uint *)(param_1 + 0x1874) & 0xffffbfff;
              FUN_0008d470(param_1);
              uVar29 = *(uint *)(param_1 + 0x44);
            }
            iVar31 = *(int *)(((unsigned char *)0x00001144) + param_1);
            *(uint *)(param_1 + 0x44) = uVar29 | 0x28000;
            *(uint *)(param_1 + 0x1874) = *(uint *)(param_1 + 0x1874) | 0x4000;
            bVar2 = *(byte *)(iVar31 + 0x6c);
            uVar28 = (bVar2 & 1) << 0xe | uVar29 & 0xffffbfff | 0x28000;
            *(uint *)(param_1 + 0x44) = uVar28;
            if ((bVar2 & 1) != 0) {
              *(undefined1 *)(param_1 + 0x29) = 1;
              *(uint *)(param_1 + 0x44) = uVar28 | 0x10000;
              *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
            }
          }
          FUN_0003e320(param_1 + -0x240,param_2,0);
        }
        else if (uVar28 == 0) {
          if (uVar23 == 0) {
            uVar28 = *(uint *)(param_1 + 0x1874);
            uVar23 = uVar29;
          }
          else {
            uVar28 = *(uint *)(param_1 + 0x1874) & 0xffffbfff;
            *(uint *)(param_1 + 0x44) = uVar29 & 0xfffd7fff;
            *(uint *)(param_1 + 0x1874) = uVar28;
            uVar23 = uVar29 & 0xfffd7fff;
            if ((uVar29 & 0x4000) != 0) {
              *(undefined1 *)(param_1 + 0x29) = 1;
              *(uint *)(param_1 + 0x44) = uVar29 & 0xfffc3fff;
              *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
              uVar23 = uVar29 & 0xfffc3fff;
            }
          }
          *(uint *)(param_1 + 0x1874) = uVar28 | 0x4000;
          *(uint *)(param_1 + 0x44) = uVar23 | 0x22000;
          *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) | 0x80000000;
          FUN_0008d470(param_1);
        }
        *(undefined1 *)(param_1 + 0x2475) = 1;
      }
      iVar31 = *(int *)(param_1 + 4);
      if ((((unsigned char *)0x00002e2d)[*(int *)(iVar31 + 0x10)] == '\0') ||
         ((*(uint *)(param_1 + 0x44) & 0x20000) != 0)) {
LAB_000a9ffc:
        uVar28 = 0;
      }
      else {
        iVar31 = FUN_0001a010(iVar31,*(undefined4 *)(iVar31 + 0x26a0));
        if (iVar31 != 0) {
          iVar31 = *(int *)(param_1 + 4);
          goto LAB_000a9ffc;
        }
        iVar31 = *(int *)(param_1 + 4);
        uVar28 = 1;
      }
      uVar29 = *(uint *)(param_1 + 0x1928);
      uVar23 = uVar29 >> 4 & 1 ^ uVar28;
      *(uint *)(param_1 + 0x1928) = uVar29 & 0xffffffef | uVar23 | uVar28 << 4;
      if (((((unsigned char *)0x00002e2c)[*(int *)(iVar31 + 0x10)] == '\0') ||
          ((*(uint *)(param_1 + 0x44) & 0x20000) != 0)) ||
         (uVar32 = 1, *(short *)(((unsigned char *)0x00002e28) + *(int *)(iVar31 + 0x10)) == -1)) {
        uVar32 = 0;
      }
      *(byte *)(param_1 + 0x2e) = bVar39;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x2000;
      *(uint *)(param_1 + 0x1928) =
           uVar29 & 0xffffffe7 | uVar23 | uVar28 << 4 | (uVar29 & 8) >> 3 ^ uVar32 | uVar32 << 3;
    }
    dVar16 = DOUBLE_001aa200;
    if ((uVar35 & 1) != 0) {
      bVar39 = *(byte *)(iVar36 + 0x2a5c);
      iVar31 = *(int *)(iVar36 + 0x10);
      bVar2 = *(byte *)(iVar36 + 0x2a5d);
      *(ushort *)(((unsigned char *)0x000015fc) + iVar36) = (ushort)bVar39 * (short)*(undefined4 *)(iVar36 + 0x15c);
      *(ushort *)(((unsigned char *)0x000015fa) + iVar36) = (ushort)bVar2 * (short)*(undefined4 *)(iVar36 + 0x160);
      if ((*(double *)(FUN_00001830 + iVar31) == dVar16) && (*(double *)(iVar31 + 0x1838) == dVar16)
         ) {
        *(uint *)(iVar36 + 0x2cc) = *(uint *)(iVar36 + 0x2cc) | 0x400000;
      }
      if ((bVar39 < 2) || (bVar2 < 2)) {
        *(undefined1 *)(iVar36 + 0x2690) = 0;
      }
      else {
        *(undefined1 *)(iVar36 + 0x2690) = 1;
      }
      *(uint *)(iVar36 + 0x278) = *(uint *)(iVar36 + 0x278) | 0x400;
      *(uint *)(iVar36 + 0x27c) = *(uint *)(iVar36 + 0x27c) | 3;
      *(undefined1 *)(iVar36 + 0x269) = 1;
    }
    if ((uVar21 & 0x200000) != 0) {
      if (((unsigned char *)0x00004301)[iVar34] != '\0') {
        uVar35 = uVar35 | 0xf0;
      }
      iVar31 = *(int *)(iVar36 + 0x10);
      if ((((unsigned char *)0x00004301)[iVar31] == '\0') ||
         (uVar28 = (uint)(byte)((unsigned char *)0x000015f4)[iVar36], uVar28 == 0)) {
        iVar17 = 0;
        cVar25 = '\0';
      }
      else {
        iVar17 = 0;
        uVar23 = 0;
        if (uVar28 == 0) {
          uVar28 = 1;
        }
        do {
          if (((1 << ((byte)((unsigned char *)0x00004300)[iVar31] & 0x3f)) - 1U & 1 << (uVar23 & 0x3f)) != 0) {
            iVar17 = iVar17 + 1;
          }
          uVar23 = uVar23 + 1;
          uVar28 = uVar28 - 1;
        } while (uVar28 != 0);
        cVar25 = (char)iVar17;
      }
      *(char *)(iVar36 + 0x2d0) = cVar25;
      if ((iVar17 == 0) || (cVar33 = '\x01', ((unsigned char *)0x00004302)[iVar31] == '\0')) {
        cVar33 = '\0';
      }
      uVar28 = *(uint *)(iVar36 + 0x278);
      *(char *)(iVar36 + 0x2d1) = cVar25 - cVar33;
      *(undefined1 *)(iVar36 + 0x269) = 1;
      *(uint *)(iVar36 + 0x278) = uVar28 | 0x800;
      if ("}J3x})+x|B;x}k"[*(int *)(iVar36 + 0x10) + 2] != '\0') {
        *(uint *)(iVar36 + 0x278) = uVar28 | 0x820;
      }
    }
    bVar1 = (int)uVar35 < 0;
    if (uVar35 != 0) {
      if ((uVar35 & 0xff0000) != 0) {
        uVar28 = uVar35 >> 0x10 & 0xff;
        if (uVar28 != 0) {
          uVar23 = 0;
          do {
            if ((uVar28 & 1) != 0) {
              bVar1 = FLOAT_001aa0e8 == (float)(*(int *)(iVar36 + 0x10) + uVar23 * 0x40 + 0x1c60);
              if (((((((local_64 == 0 && local_60 == 0) && local_5c == 0) && bVar1) &&
                    (((local_58 == 0 && local_50 == 0) && local_4c == 0) &&
                    FLOAT_001aa0e8 == local_54)) &&
                   (((local_48 == 0 && local_44 == 0) && local_3c == 0) &&
                   FLOAT_001aa0e8 == local_40)) &&
                   (((local_38 == 0 && local_34 == 0) && unaff_r20 == 0) &&
                   FLOAT_001aa0e8 == unaff_r21)) &&
                 (*(char *)(uVar23 + *(int *)(iVar36 + 0x25c) + 0x2784) != '\0')) {
                uVar32 = ~(0x10000 << (uVar23 & 0x3f));
              }
              else {
                *(bool *)(uVar23 + *(int *)(iVar36 + 0x25c) + 0x2784) =
                     (((((local_64 == 0 && local_60 == 0) && local_5c == 0) && bVar1) &&
                      (((local_58 == 0 && local_50 == 0) && local_4c == 0) &&
                      FLOAT_001aa0e8 == local_54)) &&
                     (((local_48 == 0 && local_44 == 0) && local_3c == 0) &&
                     FLOAT_001aa0e8 == local_40)) &&
                     (((local_38 == 0 && local_34 == 0) && unaff_r20 == 0) &&
                     FLOAT_001aa0e8 == unaff_r21);
                uVar29 = 1 << (uVar23 & 0x3f);
                *(undefined1 *)(iVar36 + 0x269) = 1;
                uVar32 = 0xffffffff;
                *(ushort *)(iVar36 + 0x272) = (ushort)uVar29 | *(ushort *)(iVar36 + 0x272);
                *(uint *)(iVar36 + 0x278) = *(uint *)(iVar36 + 0x278) | 0x80;
                *(uint *)(iVar36 + 0x280) = uVar29 | *(uint *)(iVar36 + 0x280);
              }
              uVar35 = uVar35 & uVar32;
            }
            uVar28 = uVar28 >> 1;
            uVar23 = uVar23 + 1;
          } while (uVar28 != 0);
          bVar1 = (int)uVar35 < 0;
          if (uVar35 == 0) goto LAB_000aa35c;
        }
        *(undefined1 *)(iVar36 + 0x26b5) = 1;
      }
LAB_000aa35c:
      if (((uVar35 & 0x40000000) != 0) && ("}J3x})+x|B;x}k"[iVar34 + 2] != '\0')) {
        *(undefined1 *)(param_1 + 0x29) = 1;
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
      }
      if ((uVar35 & 0x3f0000f8) != 0) {
        ((int (*)())FUN_000a8630)(param_1,iVar34,uVar35);
      }
      if (((uVar35 & 0x800000f0) != 0) &&
         (((*(char *)(iVar34 + 0x24ae) != '\0' || (bVar1)) && ("}J3x})+x|B;x}k"[iVar34 + 2] != '\0')
          ))) {
        *(undefined1 *)(param_1 + 0x29) = 1;
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
      }
      if ((uVar35 & 0x3f000008) != 0) {
        ((int (*)())FUN_000a8a00)(iVar36,uVar35);
      }
    }
    if ((uVar21 & 0x1007ffff) != 0) {
      if ((uVar21 & 0x7ffff) != 0) {
        if ((((unsigned char *)0x00004304)[iVar34] == '\0') || (*(int *)(param_1 + -0x74) != 0)) {
          uVar28 = (uint)(byte)"}J3x})+x|B;x}k"[iVar34 + 2] << 0x1f |
                   *(uint *)(param_1 + 0x44) & 0x7fffffff;
          *(uint *)(param_1 + 0x44) = uVar28;
        }
        else {
          uVar28 = *(uint *)(param_1 + 0x44) & 0x7fffffff;
          *(uint *)(param_1 + 0x44) = uVar28;
        }
        if (((unsigned char *)0x00004304)[iVar34] == '\0') {
          if ((int)uVar28 < 0) {
            uVar29 = *(uint *)(param_1 + 0x18a4);
            uVar23 = (uint)(*(short *)("}J3x})+x|B;x}k" + iVar34) == -0x7e06) << 2;
            *(uint *)(param_1 + 0x18a4) = uVar23 | uVar29 & 0xfffffffb;
            uVar23 = ((byte)"}J3x})+x|B;x}k"[iVar34 + 4] & 1) << 1 | uVar23 | uVar29 & 0xfffffff9;
            *(uint *)(param_1 + 0x18a4) = uVar23;
          }
          else {
            uVar23 = uVar28 >> 0x15 & 4 | *(uint *)(param_1 + 0x18a4) & 0xfffffff9;
            *(uint *)(param_1 + 0x18a4) = uVar23;
          }
        }
        else {
          uVar23 = (uint)((undefined1 *)(uVar28 & 0x80040) == ((unsigned char *)0x00080040)) << 1 |
                   uVar28 >> 0x15 & 4 | *(uint *)(param_1 + 0x18a4) & 0xfffffff9;
          *(uint *)(param_1 + 0x18a4) = uVar23;
        }
        bVar1 = (uVar28 & 0x80000000) == 0;
        if (!bVar1) {
          *(undefined1 *)(param_1 + 0x2f) = 0;
        }
        if ((uVar21 & 1) != 0) {
          *(undefined4 *)(param_1 + 0x1810) = 0x1f;
          *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x10000;
          *(uint *)(param_1 + 0x180c) = *(uint *)(param_1 + 0x180c) | 7;
          *(undefined1 *)(param_1 + 0x29) = 1;
          if (((unsigned char *)0x00004304)[iVar34] == '\0') {
            if (bVar1) {
              *(uint *)(param_1 + 0x18a4) = uVar28 >> 0x15 & 4 | uVar23 & 0xfffffff9;
            }
            else {
              uVar28 = (uint)(*(short *)("}J3x})+x|B;x}k" + iVar34) == -0x7e06) << 2;
              *(uint *)(param_1 + 0x18a4) = uVar28 | uVar23 & 0xfffffffb;
              *(uint *)(param_1 + 0x18a4) =
                   ((byte)"}J3x})+x|B;x}k"[iVar34 + 4] & 1) << 1 | uVar28 | uVar23 & 0xfffffff9;
            }
          }
          else {
            *(uint *)(param_1 + 0x18a4) =
                 (uint)((undefined1 *)(*(uint *)(param_1 + 0x44) & 0x80040) == ((unsigned char *)0x00080040)) << 1 |
                 uVar28 >> 0x15 & 4 | uVar23 & 0xfffffff9;
          }
        }
        *(undefined4 *)(param_1 + 0x88) = 0;
        fVar15 = FLOAT_001aa1a4;
        fVar14 = FLOAT_001aa1a0;
        fVar13 = FLOAT_001aa158;
        fVar12 = FLOAT_001aa114;
        fVar11 = FLOAT_001aa0e8;
        iVar40 = 8;
        uVar28 = 0;
        iVar26 = 0x2500;
        puVar27 = ((unsigned char *)0x000014b0) + param_1;
        iVar38 = 0;
        iVar31 = param_1;
        iVar17 = iVar34;
        iVar30 = param_1;
        do {
          *(uint *)(param_1 + 0x88) =
               1 << (uVar28 & 0x3f) & *(uint *)(((unsigned char *)0x00002d40) + iVar34) | *(uint *)(param_1 + 0x88);
          fVar3 = FLOAT_001aa0d4;
          if ((uVar21 & (0xc << ((uVar28 & 0x1f) << 1) | 1U)) != 0) {
            iVar24 = iVar34 + iVar26;
            *(undefined4 *)(((unsigned char *)0x000014a4) + iVar30) = *(undefined4 *)(iVar17 + 0x24f0);
            *(undefined4 *)(((unsigned char *)0x000014a8) + iVar30) = *(undefined4 *)(iVar17 + 0x24f4);
            *(undefined4 *)(((unsigned char *)0x000014ac) + iVar30) = *(undefined4 *)(iVar17 + 0x24f8);
            *(undefined4 *)(((unsigned char *)0x000014b0) + iVar30) = *(undefined4 *)(iVar17 + 0x24fc);
            fVar4 = *(float *)(iVar34 + iVar26);
            fVar19 = *(float *)(iVar24 + 8) * *(float *)(iVar24 + 8) +
                     fVar4 * fVar4 + *(float *)(iVar24 + 4) * *(float *)(iVar24 + 4);
            if (fVar3 < fVar19) {
              if (fVar19 == fVar11) {
                *(float *)(puVar27 + 4) = fVar4;
                *(undefined4 *)(puVar27 + 8) = *(undefined4 *)(iVar24 + 4);
                *(undefined4 *)(puVar27 + 0xc) = *(undefined4 *)(iVar24 + 8);
              }
              else {
                fVar20 = (float)(0x5f375a00 - ((uint)fVar19 >> 1));
                fVar3 = fVar20 * fVar19 * fVar20;
                fVar19 = fVar13 - fVar3;
                fVar3 = fVar19 * fVar20 * fVar14 * -(fVar19 * fVar3 * fVar19 - fVar15);
                *(float *)(puVar27 + 4) = fVar4 * fVar3;
                *(float *)(puVar27 + 8) = fVar3 * *(float *)(iVar24 + 4);
                *(float *)(puVar27 + 0xc) = fVar3 * *(float *)(iVar24 + 8);
              }
            }
            else {
              *(float *)(puVar27 + 0xc) = fVar3;
              *(float *)(puVar27 + 4) = fVar3;
              *(float *)(puVar27 + 8) = fVar3;
            }
            fVar3 = FLOAT_001aa0d4;
            ((unsigned char *)0x0000150c)[iVar30] = *(float *)(iVar17 + 0x250c) != fVar12;
            *(undefined4 *)(((unsigned char *)0x00001504) + iVar30) = *(undefined4 *)(iVar17 + 0x250c);
            if (*(float *)(iVar17 + 0x2510) != fVar3) {
              *(float *)(((unsigned char *)0x00001508) + iVar30) = fVar11 / *(float *)(iVar17 + 0x2510);
            }
            fVar4 = FLOAT_001aa0d4;
            if (("}J3x})+x|B;x}k"[iVar34 + 5] == '\0') && (((unsigned char *)0x0000150c)[iVar30] == '\0')) {
              if (*(float *)(((unsigned char *)0x000014b0) + iVar30) == fVar3) {
                iVar24 = param_1 + iVar38;
                fVar4 = *(float *)(((unsigned char *)0x000014a0) + iVar24 + 4);
                fVar19 = *(float *)(((unsigned char *)0x000014a0) + iVar24 + 8);
                fVar20 = *(float *)(((unsigned char *)0x000014a0) + iVar24 + 0xc);
                fVar9 = fVar4 * fVar4 + fVar19 * fVar19;
                fVar8 = fVar20 * fVar20 + fVar9;
                fVar18 = fVar3;
                fVar5 = fVar3;
                fVar6 = FLOAT_001aa0e8;
                fVar7 = fVar3;
                if (fVar3 < fVar8) {
                  if (fVar8 == FLOAT_001aa0e8) {
                    fVar3 = fVar20;
                    fVar18 = fVar4;
                    fVar5 = fVar19;
                    fVar6 = fVar20 + FLOAT_001aa0e8;
                    fVar7 = fVar9;
                  }
                  else {
                    fVar18 = (float)(0x5f375a00 - ((uint)fVar8 >> 1));
                    fVar3 = fVar18 * fVar8 * fVar18;
                    fVar5 = fVar13 - fVar3;
                    fVar18 = fVar5 * fVar18 * fVar14 * -(fVar5 * fVar3 * fVar5 - fVar15);
                    fVar5 = fVar19 * fVar18;
                    fVar3 = fVar20 * fVar18;
                    fVar18 = fVar4 * fVar18;
                    fVar6 = fVar3 + FLOAT_001aa0e8;
                    fVar7 = fVar18 * fVar18 + fVar5 * fVar5;
                  }
                }
                fVar7 = fVar6 * fVar6 + fVar7;
                *(float *)(((unsigned char *)0x000014fc) + iVar30) = fVar3;
                *(float *)(((unsigned char *)0x000014f4) + iVar30) = fVar18;
                *(float *)(((unsigned char *)0x000014f8) + iVar30) = fVar5;
                fVar3 = FLOAT_001aa0d4;
                iVar24 = param_1 + iVar38;
                if (FLOAT_001aa0d4 < fVar7) {
                  if (fVar7 == fVar11) {
                    *(float *)(((unsigned char *)0x000014e0) + iVar24 + 4) = fVar18;
                    *(float *)(((unsigned char *)0x000014e0) + iVar24 + 0xc) = fVar6;
                    *(float *)(((unsigned char *)0x000014e0) + iVar24 + 8) = fVar5;
                  }
                  else {
                    fVar19 = (float)(0x5f375a00 - ((uint)fVar7 >> 1));
                    fVar3 = fVar19 * fVar7 * fVar19;
                    fVar4 = fVar13 - fVar3;
                    fVar3 = fVar4 * fVar19 * fVar14 * -(fVar4 * fVar3 * fVar4 - fVar15);
                    *(float *)(((unsigned char *)0x000014e0) + iVar24 + 4) = fVar3 * fVar18;
                    *(float *)(((unsigned char *)0x000014e0) + iVar24 + 0xc) = fVar6 * fVar3;
                    *(float *)(((unsigned char *)0x000014e0) + iVar24 + 8) = fVar3 * fVar5;
                  }
                }
                else {
                  *(float *)(((unsigned char *)0x000014e0) + iVar24 + 4) = FLOAT_001aa0d4;
                  *(float *)(((unsigned char *)0x000014e0) + iVar24 + 0xc) = fVar3;
                  *(float *)(((unsigned char *)0x000014e0) + iVar24 + 8) = fVar3;
                }
              }
            }
            else if (*(float *)(((unsigned char *)0x000014b0) + iVar30) == FLOAT_001aa0d4) {
              iVar24 = param_1 + iVar38;
              iVar10 = param_1 + iVar38;
              fVar3 = *(float *)(((unsigned char *)0x000014a0) + iVar24 + 4);
              fVar19 = *(float *)(((unsigned char *)0x000014a0) + iVar24 + 0xc);
              fVar20 = *(float *)(((unsigned char *)0x000014a0) + iVar24 + 8);
              fVar19 = fVar19 * fVar19 + fVar3 * fVar3 + fVar20 * fVar20;
              if (FLOAT_001aa0d4 < fVar19) {
                if (fVar19 == fVar11) {
                  *(float *)(((unsigned char *)0x000014f0) + iVar10 + 4) = fVar3;
                  *(undefined4 *)(((unsigned char *)0x000014f0) + iVar10 + 8) =
                       *(undefined4 *)(((unsigned char *)0x000014a0) + iVar24 + 8);
                  *(undefined4 *)(((unsigned char *)0x000014f0) + iVar10 + 0xc) =
                       *(undefined4 *)(((unsigned char *)0x000014a0) + iVar24 + 0xc);
                }
                else {
                  fVar20 = (float)(0x5f375a00 - ((uint)fVar19 >> 1));
                  fVar4 = fVar20 * fVar19 * fVar20;
                  fVar19 = fVar13 - fVar4;
                  fVar4 = fVar19 * fVar20 * fVar14 * -(fVar19 * fVar4 * fVar19 - fVar15);
                  *(float *)(((unsigned char *)0x000014f0) + iVar10 + 4) = fVar3 * fVar4;
                  *(float *)(((unsigned char *)0x000014f0) + iVar10 + 8) =
                       fVar4 * *(float *)(((unsigned char *)0x000014a0) + iVar24 + 8);
                  *(float *)(((unsigned char *)0x000014f0) + iVar10 + 0xc) =
                       fVar4 * *(float *)(((unsigned char *)0x000014a0) + iVar24 + 0xc);
                }
              }
              else {
                *(float *)(((unsigned char *)0x000014f0) + iVar10 + 4) = FLOAT_001aa0d4;
                *(float *)(((unsigned char *)0x000014f0) + iVar10 + 0xc) = fVar4;
                *(float *)(((unsigned char *)0x000014f0) + iVar10 + 8) = fVar4;
              }
            }
            bVar39 = *(byte *)(iVar31 + 0x1814);
            bVar2 = *(byte *)(iVar31 + 0x181c);
            *(undefined1 *)(param_1 + 0x29) = 1;
            *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
            *(byte *)(iVar31 + 0x1814) = bVar39 | 0x3f;
            *(byte *)(iVar31 + 0x181c) = bVar2 | 3;
          }
          uVar28 = uVar28 + 1;
          iVar38 = iVar38 + 0x6c;
          puVar27 = puVar27 + 0x6c;
          iVar26 = iVar26 + 0x80;
          iVar31 = iVar31 + 1;
          iVar30 = iVar30 + 0x6c;
          iVar17 = iVar17 + 0x80;
          iVar40 = iVar40 + -1;
        } while (iVar40 != 0);
        *(undefined1 *)(param_1 + 0x29) = 1;
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
      }
      if ((uVar21 & 0x10000000) != 0) {
        *(undefined1 *)(param_1 + 0x29) = 1;
      }
    }
LAB_000aaa50:
    uVar28 = param_2[1];
    uVar23 = param_2[4];
    if (uVar23 != 0 || (uVar28 & 0xff0000) != 0) {
      if ((uVar28 & 0xff0000) != 0) {
        ((int (*)())FUN_000a8340)(iVar36,uVar28);
      }
      if (uVar23 != 0) {
        ((int (*)())FUN_000a9070)(iVar36,uVar23);
      }
    }
    if (uVar37 != 0) {
      if ((uVar37 & 1) != 0) {
        *(undefined1 *)(param_1 + 0x29) = 1;
        *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x1010;
      }
      if ((uVar37 & 6) != 0) {
        *(undefined1 *)(param_1 + 0x29) = 1;
        *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x1018;
      }
      if ((uVar37 & 0x200) != 0) {
        *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 1;
      }
      if ((uVar37 & 0x10000000) != 0) {
        *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x20;
      }
      if ((uVar37 & 0x8000000) != 0) {
        *(undefined1 *)(param_1 + 0x29) = 1;
        *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x40;
      }
      if ((uVar37 & 0x4000000) != 0) {
        iVar38 = *(int *)(((unsigned char *)0x00003180) + iVar34);
        iVar26 = *(int *)(((unsigned char *)0x00003184) + iVar34);
        iVar30 = *(int *)(((unsigned char *)0x00003188) + iVar34);
        iVar40 = *(int *)(((unsigned char *)0x0000318c) + iVar34);
        iVar17 = *(int *)(param_1 + -0xe0);
        iVar31 = *(int *)(param_1 + -0xe4);
        *(int *)(param_1 + 0x440) = iVar38;
        *(int *)(param_1 + 0x444) = iVar26;
        *(int *)(param_1 + 0x448) = iVar30;
        *(int *)(param_1 + 0x44c) = iVar40;
        if (((unsigned char *)0x00003190)[iVar34] == '\0') {
          *(undefined4 *)(((unsigned char *)0x0000135c) + param_1) = 0;
          *(int *)(((unsigned char *)0x00001360) + param_1) = iVar31;
          *(int *)(((unsigned char *)0x00001364) + param_1) = iVar17;
          *(undefined4 *)(((unsigned char *)0x00001358) + param_1) = 0;
        }
        else {
          if (*(char *)(param_1 + 0x293c) != '\0') {
            iVar26 = iVar17 - (iVar26 + iVar40);
          }
          iVar30 = iVar38 + iVar30;
          iVar40 = iVar26 + iVar40;
          if (iVar38 < 0) {
            iVar38 = 0;
          }
          if (iVar26 < 0) {
            iVar26 = 0;
          }
          if (iVar30 <= iVar31) {
            iVar31 = iVar30;
          }
          if (iVar40 <= iVar17) {
            iVar17 = iVar40;
          }
          *(int *)(((unsigned char *)0x00001358) + param_1) = iVar38;
          *(int *)(((unsigned char *)0x0000135c) + param_1) = iVar26;
          *(int *)(((unsigned char *)0x00001360) + param_1) = iVar31;
          *(int *)(((unsigned char *)0x00001364) + param_1) = iVar17;
        }
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 2;
      }
      if ((uVar37 & 0x800000) != 0) {
        iVar31 = *(int *)(*(int *)(param_1 + 4) + 0x10);
        if (((((unsigned char *)0x00003178)[iVar31] == '\0') || ((*(uint *)(param_1 + 0x44) & 0x20000) != 0)) ||
           ((*(short *)(((unsigned char *)0x00003170) + iVar31) != 0x1b02 &&
            (*(short *)(((unsigned char *)0x00003172) + iVar31) != 0x1b02)))) {
          uVar23 = 0;
        }
        else {
          uVar23 = 1;
        }
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x4004;
        *(uint *)(param_1 + 0x1928) =
             *(uint *)(param_1 + 0x1928) & 0xfffffffb |
             *(uint *)(param_1 + 0x1928) >> 2 & 1 ^ uVar23 | uVar23 << 2;
      }
      if ((uVar37 & 0x1c0080) != 0) {
        if ((uVar37 & 0x40080) != 0) {
          *(undefined1 *)(param_1 + 0x29) = 1;
          *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x40;
        }
        if ((uVar37 & 0x80000) != 0) {
          *(undefined1 *)(param_1 + 0x29) = 1;
          *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 1;
        }
        if ((uVar37 & 0x100000) != 0) {
          *(undefined1 *)(param_1 + 0x29) = 1;
          *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x20;
        }
      }
      uVar23 = uVar37 & 0xe363fd78;
      if (uVar23 != 0) {
        if ((uVar37 & 0x1800) != 0) {
          ((int (*)())FUN_000a8e20)(param_1,iVar34,uVar23);
        }
        if ((uVar37 & 0x3000000) != 0) {
          ((int (*)())FUN_000a8d70)(param_1,iVar34,uVar23);
        }
        if ((uVar37 & 0x38) != 0) {
          *(undefined1 *)(param_1 + 0x29) = 1;
        }
        if ((uVar37 & 0x100) != 0) {
          ((int (*)())FUN_000a7e80)(param_1,iVar34);
        }
        if ((uVar37 & 0x400) != 0) {
          *(undefined1 *)(param_1 + 0x29) = 1;
          *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 8;
        }
        if ((uVar37 & 0x2000) != 0) {
          *(undefined1 *)(param_1 + 0x29) = 1;
        }
        if ((uVar37 & 0x1c000) != 0) {
          ((int (*)())FUN_000a8c00)(param_1,iVar34);
        }
        if ((uVar37 & 0x20000) != 0) {
          *(undefined1 *)(param_1 + 0x29) = 1;
          *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 8;
        }
        if ((uVar37 & 0x400000) != 0) {
          ((int (*)())FUN_000a9640)(param_1,iVar34);
        }
        if ((uVar37 & 0x20000000) != 0) {
          ((int (*)())FUN_000a7ea0)(param_1,iVar34);
        }
      }
    }
    if (*(char *)(iVar36 + 0x26b5) != '\0') {
      FUN_000bda40(param_1);
      *(undefined1 *)(iVar36 + 0x26b5) = 0;
    }
    if ((((uVar37 & 0x401800) == 0 && (uVar28 & 0xffffff) == 0) && (uVar35 & 0x3fff0008) == 0) &&
        (uVar21 & 0x5400002) == 0) {
      return;
    }
    uVar35 = *(uint *)(iVar36 + 0x2cc);
    iVar31 = *(int *)(iVar36 + 0x10);
    if (((*(uint *)(iVar36 + 0x284) & 0x80000800) != 0) ||
       (((((*(uint *)(iVar36 + 0x284) & 0x1000000) != 0 &&
          (*(short *)(((unsigned char *)0x00002e06) + iVar31) == -0x7bae)) || ((*(uint *)(iVar36 + 0x328) & 1) != 0)
         ) || ((*(int *)(((unsigned char *)0x00003e28) + iVar31) != 0 || (uVar37 = 0, (uVar35 & 0xe000000) != 0)))))
       ) {
      uVar37 = 1;
    }
    *(uint *)(iVar36 + 0x2cc) = uVar37 << 0x13 | uVar35 & 0xfff7ffff;
    if ((uVar35 >> 0x13 & 1) == uVar37) {
      return;
    }
    if (((unsigned char *)0x00004301)[iVar31] == '\0') {
      return;
    }
    uVar35 = *(uint *)(iVar36 + 0x278);
    *(undefined1 *)(iVar36 + 0x269) = 1;
    *(uint *)(iVar36 + 0x278) = uVar35 | 0x800;
    if ("}J3x})+x|B;x}k"[iVar31 + 2] == '\0') {
      return;
    }
    *(uint *)(iVar36 + 0x278) = uVar35 | 0x820;
    return;
  }
  *(uint *)(iVar36 + 0x26c4) = uVar21 & 0x1027ffff;
  if (iVar31 == 0 && (uVar35 & 0x3f000000) == 0) {
    uVar23 = 0xc0ff00f8;
    uVar28 = 0x3f00ff07;
  }
  else {
    uVar23 = 0xc0ff00f0;
    uVar28 = 0x3f00ff0f;
  }
  uVar28 = uVar35 & uVar28;
  *(uint *)(iVar36 + 0x26c0) = uVar35 & uVar23;
  if ((uVar28 & 0xff00) != 0 || (uVar21 & 0x4c00000) != 0) {
    if ((uVar21 & 0x800000) != 0) {
      iVar31 = *(int *)(iVar36 + 0x10);
      uVar35 = *(uint *)(param_1 + 0x44);
      if ((uint)(byte)((unsigned char *)0x00004305)[iVar31] != (uVar35 >> 7 & 1)) {
        uVar35 = ((byte)((unsigned char *)0x00004305)[iVar31] & 1) << 7 | uVar35 & 0xffffff7f;
        *(uint *)(param_1 + 0x44) = uVar35;
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1008;
        iVar31 = *(int *)(iVar36 + 0x10);
      }
      if ((uint)(byte)((unsigned char *)0x00004306)[iVar31] != (uVar35 >> 6 & 1)) {
        *(uint *)(param_1 + 0x44) = ((byte)((unsigned char *)0x00004306)[iVar31] & 1) << 6 | uVar35 & 0xffffffbf;
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
      }
    }
    if ((uVar21 & 0x4400000) != 0) {
      uVar23 = *(uint *)(param_1 + 0x44);
      uVar35 = (uint)(*(int *)(param_1 + -0x74) != 0);
      if (uVar35 == (uVar23 >> 0x14 & 1)) {
        if (((uVar35 != 0) || (uVar23 >> 0x1f == (uint)(byte)"}J3x})+x|B;x}k"[iVar34 + 2])) ||
           (((unsigned char *)0x00004304)[iVar34] != '\0')) goto LAB_000ab18c;
LAB_000ab014:
        uVar35 = *(uint *)(param_1 + 0x1874) >> 0x17 & 1;
        *(uint *)(param_1 + 0x1928) =
             *(uint *)(param_1 + 0x1928) & 0xfffffffd |
             *(uint *)(param_1 + 0x1928) >> 1 & 1 ^ uVar35 | uVar35 << 1;
        if (((unsigned char *)0x00004304)[iVar34] == '\0') {
          *(undefined1 *)(param_1 + 0x2475) = 1;
          uVar23 = (uint)(byte)"}J3x})+x|B;x}k"[iVar34 + 2] << 0x1f | uVar23 & 0x7fffffff;
          *(uint *)(param_1 + 0x44) = uVar23;
        }
        else if ((int)uVar23 < 0) {
          uVar23 = uVar23 & 0x7fffffff;
          *(uint *)(param_1 + 0x44) = uVar23;
          *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
        }
        pcVar22 = *(code **)(((unsigned char *)0x000012b0) + param_1);
        *(uint *)(param_1 + 0x44) = uVar23 & 0xffe7ffff;
        *(undefined1 *)(param_1 + 299) = 1;
        (*pcVar22)(param_1);
        bVar39 = ((unsigned char *)0x000013b6)[param_1];
        *(undefined1 *)(param_1 + 0x29) = 1;
        uVar35 = *(uint *)(param_1 + 0x38) | 0x58a60;
        *(uint *)(param_1 + 0x38) = uVar35;
        *(ushort *)(param_1 + 0x34) =
             (short)(1 << (bVar39 & 0x3f)) - 1U | *(ushort *)(param_1 + 0x34);
      }
      else {
        if (uVar35 == 0) goto LAB_000ab014;
        uVar35 = *(uint *)(param_1 + 0x38);
        *(uint *)(param_1 + 0x44) = uVar23 | 0x180000;
        *(undefined1 *)(param_1 + 299) = 1;
        *(uint *)(param_1 + 0x1928) =
             *(uint *)(param_1 + 0x1928) & 0xfffffffd | *(uint *)(param_1 + 0x1928) >> 1 & 1;
      }
      if (((unsigned char *)0x00004304)[iVar34] == '\0') {
        if ((int)*(uint *)(param_1 + 0x44) < 0) {
          uVar29 = *(uint *)(param_1 + 0x18a4);
          uVar23 = (uint)(*(short *)("}J3x})+x|B;x}k" + iVar34) == -0x7e06) << 2;
          *(uint *)(param_1 + 0x18a4) = uVar23 | uVar29 & 0xfffffffb;
          *(uint *)(param_1 + 0x18a4) =
               ((byte)"}J3x})+x|B;x}k"[iVar34 + 4] & 1) << 1 | uVar23 | uVar29 & 0xfffffff9;
        }
        else {
          *(uint *)(param_1 + 0x18a4) =
               *(uint *)(param_1 + 0x44) >> 0x15 & 4 | *(uint *)(param_1 + 0x18a4) & 0xfffffff9;
        }
      }
      else {
        *(uint *)(param_1 + 0x18a4) =
             (uint)((undefined1 *)(*(uint *)(param_1 + 0x44) & 0x80040) == ((unsigned char *)0x00080040)) << 1 |
             *(uint *)(param_1 + 0x44) >> 0x15 & 4 | *(uint *)(param_1 + 0x18a4) & 0xfffffff9;
      }
      *(uint *)(param_1 + 0x38) = uVar35 | 0x1000;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(byte *)(param_1 + 0x2d) = *(byte *)(param_1 + 0x2d) | 0xf;
    }
LAB_000ab18c:
    FUN_0003b160(iVar36,param_2,0);
  }
  if ((uVar21 & 0x7000000) == 0) goto LAB_000ab460;
  *(undefined1 *)(param_1 + 0x29) = 1;
  bVar39 = *(byte *)(param_1 + 0x2e) | 2;
  if ((uVar21 & 0x5000000) != 0) {
    uVar23 = *(uint *)(param_1 + 0x44);
    bVar39 = *(byte *)(param_1 + 0x2e) | 3;
    uVar21 = uVar23 >> 0xf & 1;
    uVar35 = uVar23 >> 0xd & 1;
    if (*(int *)(param_1 + -0x70) == 0) {
      if (uVar35 == 0) {
        if (uVar21 != 0) {
          *(uint *)(param_1 + 0x44) = uVar23 & 0xfffd7fff;
          *(uint *)(param_1 + 0x1874) = *(uint *)(param_1 + 0x1874) & 0xffffbfff;
          if ((uVar23 & 0x4000) != 0) {
            *(undefined1 *)(param_1 + 0x29) = 1;
            *(uint *)(param_1 + 0x44) = uVar23 & 0xfffc3fff;
            *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
          }
        }
      }
      else {
        *(uint *)(param_1 + 0x44) = uVar23 & 0xfffddfff;
        *(uint *)(param_1 + 0x1874) = *(uint *)(param_1 + 0x1874) & 0xffffbfff;
        FUN_0008d470(param_1);
      }
    }
    else if (*(char *)(param_1 + 0x279c) == '\0') {
      if (uVar21 == 0) {
        if (uVar35 != 0) {
          *(uint *)(param_1 + 0x44) = uVar23 & 0xfffddfff;
          *(uint *)(param_1 + 0x1874) = *(uint *)(param_1 + 0x1874) & 0xffffbfff;
          FUN_0008d470(param_1);
          uVar23 = *(uint *)(param_1 + 0x44);
        }
        iVar31 = *(int *)(((unsigned char *)0x00001144) + param_1);
        *(uint *)(param_1 + 0x44) = uVar23 | 0x28000;
        *(uint *)(param_1 + 0x1874) = *(uint *)(param_1 + 0x1874) | 0x4000;
        bVar2 = *(byte *)(iVar31 + 0x6c);
        uVar35 = (bVar2 & 1) << 0xe | uVar23 & 0xffffbfff | 0x28000;
        *(uint *)(param_1 + 0x44) = uVar35;
        if ((bVar2 & 1) != 0) {
          *(undefined1 *)(param_1 + 0x29) = 1;
          *(uint *)(param_1 + 0x44) = uVar35 | 0x10000;
          *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
        }
      }
      FUN_0003e320(param_1 + -0x240,param_2,0);
    }
    else if (uVar35 == 0) {
      if (uVar21 == 0) {
        uVar35 = *(uint *)(param_1 + 0x1874);
        uVar21 = uVar23;
      }
      else {
        uVar35 = *(uint *)(param_1 + 0x1874) & 0xffffbfff;
        *(uint *)(param_1 + 0x44) = uVar23 & 0xfffd7fff;
        *(uint *)(param_1 + 0x1874) = uVar35;
        uVar21 = uVar23 & 0xfffd7fff;
        if ((uVar23 & 0x4000) != 0) {
          *(undefined1 *)(param_1 + 0x29) = 1;
          *(uint *)(param_1 + 0x44) = uVar23 & 0xfffc3fff;
          *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
          uVar21 = uVar23 & 0xfffc3fff;
        }
      }
      *(uint *)(param_1 + 0x1874) = uVar35 | 0x4000;
      *(uint *)(param_1 + 0x44) = uVar21 | 0x22000;
      *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) | 0x80000000;
      FUN_0008d470(param_1);
    }
    *(undefined1 *)(param_1 + 0x2475) = 1;
  }
  iVar31 = *(int *)(param_1 + 4);
  if ((((unsigned char *)0x00002e2d)[*(int *)(iVar31 + 0x10)] == '\0') ||
     ((*(uint *)(param_1 + 0x44) & 0x20000) != 0)) {
LAB_000ab3d0:
    uVar35 = 0;
  }
  else {
    iVar31 = FUN_0001a010(iVar31,*(undefined4 *)(iVar31 + 0x26a0));
    if (iVar31 != 0) {
      iVar31 = *(int *)(param_1 + 4);
      goto LAB_000ab3d0;
    }
    iVar31 = *(int *)(param_1 + 4);
    uVar35 = 1;
  }
  uVar23 = *(uint *)(param_1 + 0x1928);
  uVar21 = uVar23 >> 4 & 1 ^ uVar35;
  *(uint *)(param_1 + 0x1928) = uVar23 & 0xffffffef | uVar21 | uVar35 << 4;
  if (((((unsigned char *)0x00002e2c)[*(int *)(iVar31 + 0x10)] == '\0') ||
      ((*(uint *)(param_1 + 0x44) & 0x20000) != 0)) ||
     (uVar29 = 1, *(short *)(((unsigned char *)0x00002e28) + *(int *)(iVar31 + 0x10)) == -1)) {
    uVar29 = 0;
  }
  *(byte *)(param_1 + 0x2e) = bVar39;
  *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x2000;
  *(uint *)(param_1 + 0x1928) =
       uVar23 & 0xffffffe7 | uVar21 | uVar35 << 4 | (uVar23 & 8) >> 3 ^ uVar29 | uVar29 << 3;
LAB_000ab460:
  dVar16 = DOUBLE_001aa200;
  if (uVar28 != 0) {
    if ((uVar28 & 1) != 0) {
      bVar39 = *(byte *)(iVar36 + 0x2a5c);
      iVar31 = *(int *)(iVar36 + 0x10);
      bVar2 = *(byte *)(iVar36 + 0x2a5d);
      *(ushort *)(((unsigned char *)0x000015fc) + iVar36) = (ushort)bVar39 * (short)*(undefined4 *)(iVar36 + 0x15c);
      *(ushort *)(((unsigned char *)0x000015fa) + iVar36) = (ushort)bVar2 * (short)*(undefined4 *)(iVar36 + 0x160);
      if ((*(double *)(FUN_00001830 + iVar31) == dVar16) && (*(double *)(iVar31 + 0x1838) == dVar16)
         ) {
        *(uint *)(iVar36 + 0x2cc) = *(uint *)(iVar36 + 0x2cc) | 0x400000;
      }
      if ((bVar39 < 2) || (bVar2 < 2)) {
        *(undefined1 *)(iVar36 + 0x2690) = 0;
      }
      else {
        *(undefined1 *)(iVar36 + 0x2690) = 1;
      }
      *(undefined1 *)(iVar36 + 0x269) = 1;
      *(uint *)(iVar36 + 0x278) = *(uint *)(iVar36 + 0x278) | 0x400;
      *(uint *)(iVar36 + 0x27c) = *(uint *)(iVar36 + 0x27c) | 3;
    }
    if ((uVar28 & 0x3f000008) != 0) {
      ((int (*)())FUN_000a8630)(param_1,iVar34,uVar28);
      ((int (*)())FUN_000a8a00)(iVar36,uVar28);
    }
  }
  uVar35 = param_2[4];
  if (uVar35 != 0 || (param_2[1] & 0xff0000) != 0) {
    if ((param_2[1] & 0xff0000) != 0) {
      ((int (*)())FUN_000a8340)(iVar36);
    }
    if (uVar35 != 0) {
      ((int (*)())FUN_000a9070)(iVar36,uVar35);
    }
  }
  if (uVar37 != 0) {
    if ((uVar37 & 1) != 0) {
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x1010;
    }
    if ((uVar37 & 6) != 0) {
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x1018;
    }
    if ((uVar37 & 0x200) != 0) {
      *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 1;
    }
    if ((uVar37 & 0x10000000) != 0) {
      *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x20;
    }
    if ((uVar37 & 0x8000000) != 0) {
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x40;
    }
    if ((uVar37 & 0x4000000) != 0) {
      iVar26 = *(int *)(((unsigned char *)0x00003180) + iVar34);
      iVar30 = *(int *)(((unsigned char *)0x00003184) + iVar34);
      iVar17 = *(int *)(((unsigned char *)0x00003188) + iVar34);
      iVar38 = *(int *)(((unsigned char *)0x0000318c) + iVar34);
      iVar31 = *(int *)(param_1 + -0xe0);
      iVar36 = *(int *)(param_1 + -0xe4);
      *(int *)(param_1 + 0x440) = iVar26;
      *(int *)(param_1 + 0x444) = iVar30;
      *(int *)(param_1 + 0x448) = iVar17;
      *(int *)(param_1 + 0x44c) = iVar38;
      if (((unsigned char *)0x00003190)[iVar34] == '\0') {
        *(undefined4 *)(((unsigned char *)0x0000135c) + param_1) = 0;
        *(int *)(((unsigned char *)0x00001360) + param_1) = iVar36;
        *(int *)(((unsigned char *)0x00001364) + param_1) = iVar31;
        *(undefined4 *)(((unsigned char *)0x00001358) + param_1) = 0;
      }
      else {
        if (*(char *)(param_1 + 0x293c) != '\0') {
          iVar30 = iVar31 - (iVar30 + iVar38);
        }
        iVar17 = iVar26 + iVar17;
        iVar38 = iVar30 + iVar38;
        if (iVar26 < 0) {
          iVar26 = 0;
        }
        if (iVar30 < 0) {
          iVar30 = 0;
        }
        if (iVar17 <= iVar36) {
          iVar36 = iVar17;
        }
        if (iVar38 <= iVar31) {
          iVar31 = iVar38;
        }
        *(int *)(((unsigned char *)0x00001358) + param_1) = iVar26;
        *(int *)(((unsigned char *)0x0000135c) + param_1) = iVar30;
        *(int *)(((unsigned char *)0x00001360) + param_1) = iVar36;
        *(int *)(((unsigned char *)0x00001364) + param_1) = iVar31;
      }
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 2;
    }
    if ((uVar37 & 0x800000) != 0) {
      iVar36 = *(int *)(*(int *)(param_1 + 4) + 0x10);
      if (((((unsigned char *)0x00003178)[iVar36] == '\0') || ((*(uint *)(param_1 + 0x44) & 0x20000) != 0)) ||
         ((*(short *)(((unsigned char *)0x00003170) + iVar36) != 0x1b02 &&
          (*(short *)(((unsigned char *)0x00003172) + iVar36) != 0x1b02)))) {
        uVar35 = 0;
      }
      else {
        uVar35 = 1;
      }
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x4004;
      *(uint *)(param_1 + 0x1928) =
           *(uint *)(param_1 + 0x1928) & 0xfffffffb | *(uint *)(param_1 + 0x1928) >> 2 & 1 ^ uVar35
           | uVar35 << 2;
    }
    if ((uVar37 & 0x1c0080) != 0) {
      if ((uVar37 & 0x40080) != 0) {
        *(undefined1 *)(param_1 + 0x29) = 1;
        *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x40;
      }
      if ((uVar37 & 0x80000) != 0) {
        *(undefined1 *)(param_1 + 0x29) = 1;
        *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 1;
      }
      if ((uVar37 & 0x100000) != 0) {
        *(undefined1 *)(param_1 + 0x29) = 1;
        *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x20;
      }
    }
    uVar35 = uVar37 & 0xe363fd78;
    if (uVar35 != 0) {
      if ((uVar37 & 0x1800) != 0) {
        ((int (*)())FUN_000a8e20)(param_1,iVar34,uVar35);
      }
      if ((uVar37 & 0x3000000) != 0) {
        ((int (*)())FUN_000a8d70)(param_1,iVar34,uVar35);
      }
      if ((uVar37 & 0x38) != 0) {
        *(undefined1 *)(param_1 + 0x29) = 1;
      }
      if ((uVar37 & 0x100) != 0) {
        ((int (*)())FUN_000a7e80)(param_1,iVar34);
      }
      if ((uVar37 & 0x400) != 0) {
        *(undefined1 *)(param_1 + 0x29) = 1;
        *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 8;
      }
      if ((uVar37 & 0x2000) != 0) {
        *(undefined1 *)(param_1 + 0x29) = 1;
      }
      if ((uVar37 & 0x1c000) != 0) {
        ((int (*)())FUN_000a8c00)(param_1,iVar34);
      }
      if ((uVar37 & 0x20000) != 0) {
        *(undefined1 *)(param_1 + 0x29) = 1;
        *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 8;
      }
      if ((uVar37 & 0x400000) != 0) {
        ((int (*)())FUN_000a9640)(param_1,iVar34);
      }
      if ((uVar37 & 0x20000000) != 0) {
        ((int (*)())FUN_000a7ea0)(param_1,iVar34);
      }
    }
  }
  return;
}

/* FUN_000ab900 @ 0xab900 (60 bytes) */
int FUN_000ab900(param_1)
  int param_1;
{
  if (*(char *)(param_1 + 0x1868) != '\0') {
    *(undefined **)((int)((unsigned char *)0x000011cc) + param_1) = PTR_FUN_001e8b40;
    return;
  }
  *(undefined **)((int)((unsigned char *)0x000011cc) + param_1) = PTR_FUN_001e8b3c;
  return;
}

/* FUN_000ab940 @ 0xab940 (96 bytes) */
int FUN_000ab940(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  undefined4 param_3;
  int *param_4;
  undefined1 *param_5;
  int param_6;
{
  if (param_1 == 3) {
    if (param_2 == 1) {
      param_4[1] = 0x18;
      *param_4 = 0;
    }
    else {
      *param_4 = param_6;
      param_4[1] = 0x17;
    }
    *param_5 = 1;
    return;
  }
  *param_4 = param_2;
  param_4[1] = 4;
  *param_5 = 0;
  return;
}

/* FUN_000ab9b0 @ 0xab9b0 (240 bytes) */
int FUN_000ab9b0(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int in_stack_00000038;
  int *in_stack_0000003c;
  
  if (param_1 == 1) {
    in_stack_00000038 = param_2 * 0x14 + in_stack_00000038;
    iVar1 = *(int *)(in_stack_00000038 + 8);
    iVar2 = *(int *)(in_stack_00000038 + 0xc);
    if (iVar1 == 1) {
      if (iVar2 == 0) {
        *in_stack_0000003c = 0;
        in_stack_0000003c[1] = 0x12;
        return;
      }
      in_stack_0000003c[1] = 0x13;
      *in_stack_0000003c = 0;
      return;
    }
    if (iVar1 == 3) {
      in_stack_0000003c[1] = 0x10;
      *in_stack_0000003c = 0;
      return;
    }
    if (iVar1 == 4) {
      in_stack_0000003c[1] = 0x16;
      *in_stack_0000003c = 0;
      return;
    }
    *in_stack_0000003c = iVar2;
    in_stack_0000003c[1] = 0x11;
    return;
  }
  if (param_1 == 0) {
    *in_stack_0000003c = param_2;
    in_stack_0000003c[1] = 4;
    return;
  }
  if (param_1 != 2) {
    return;
  }
  *in_stack_0000003c = param_2;
  in_stack_0000003c[1] = 1;
  return;
}

/* FUN_000abab0 @ 0xabab0 (164 bytes) */
int FUN_000abab0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  int iVar1;
  undefined1 auStack_70 [16];
  undefined1 auStack_30 [20];
  
  iVar1 = *(int *)(*(int *)(param_2 + 0x74) + 0x84) * -0x10;
  *(unsigned char **)(auStack_70 + iVar1) = ((unsigned int)__builtin_frame_address(0));
  FUN_00024fe0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(*(int *)(param_2 + 0x74) + 0x84),
               auStack_30 + iVar1);
  (**(code **)(((unsigned char *)0x00001280) + param_1))
            (param_1,param_3,0,0,auStack_30 + iVar1,*(undefined4 *)(*(int *)(param_2 + 0x74) + 0x84)
             ,1);
  return;
}

/* FUN_000abb60 @ 0xabb60 (96 bytes) */
int FUN_000abb60(param_1)
  int param_1;
{
  int iVar1;
  
  if (*(int *)(((unsigned char *)0x0000121c) + param_1) != 0) {
    iVar1 = *(int *)(*(int *)(((unsigned char *)0x0000121c) + param_1) + 0x74);
    if (*(char *)(iVar1 + 0x54) == '\0') {
      iVar1 = *(int *)(*(int *)(((unsigned char *)0x00001220) + param_1) * 0x18 +
                       *(int *)(*(int *)(((unsigned char *)0x0000112c) + param_1) + 8) + 0x14);
      if (iVar1 == 0) {
        return 0;
      }
      iVar1 = *(int *)(iVar1 + 0x74);
    }
    if (iVar1 != 0) {
      return *(undefined4 *)(iVar1 + 8);
    }
  }
  return 0;
}

/* FUN_000abbd0 @ 0xabbd0 (312 bytes) */
int FUN_000abbd0(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  
  puVar3 = (uint *)(param_1 + 4);
  if (param_2 != 0) {
    uVar4 = *(uint *)(param_1 + 4);
    puVar3 = (uint *)(param_1 + 8);
    if ((uVar4 & 0x3f0000) == 0x180000) {
      *(undefined1 *)(*(int *)(param_4 + 0x74) + 4) = 1;
    }
    if ((uVar4 & 0x400000) != 0) {
      puVar3 = (uint *)(param_1 + 0xc);
    }
  }
  puVar2 = puVar3;
  if (0 < param_3) {
    uVar4 = *puVar3;
    puVar2 = puVar3 + 1;
    if ((uVar4 & 0x400000) != 0) {
      puVar2 = puVar3 + 2;
    }
    if ((uVar4 >> 0x10 & 0x3f) - 1 < 2) {
      iVar1 = (uVar4 & 0xffff) + 1;
      if (*(int *)(*(int *)(param_4 + 0x74) + 0x84) < iVar1) {
        *(int *)(*(int *)(param_4 + 0x74) + 0x84) = iVar1;
      }
    }
  }
  puVar3 = puVar2;
  if (1 < param_3) {
    uVar4 = *puVar2;
    puVar3 = puVar2 + 1;
    if ((uVar4 & 0x400000) != 0) {
      puVar3 = puVar2 + 2;
    }
    if ((uVar4 >> 0x10 & 0x3f) - 1 < 2) {
      iVar1 = (uVar4 & 0xffff) + 1;
      if (*(int *)(*(int *)(param_4 + 0x74) + 0x84) < iVar1) {
        *(int *)(*(int *)(param_4 + 0x74) + 0x84) = iVar1;
      }
    }
  }
  if (param_3 < 3) {
    return puVar3;
  }
  uVar4 = *puVar3;
  puVar2 = puVar3 + 2;
  if ((uVar4 & 0x400000) == 0) {
    puVar2 = puVar3 + 1;
  }
  if (1 < (uVar4 >> 0x10 & 0x3f) - 1) {
    return puVar2;
  }
  iVar1 = (uVar4 & 0xffff) + 1;
  if (iVar1 <= *(int *)(*(int *)(param_4 + 0x74) + 0x84)) {
    return puVar2;
  }
  *(int *)(*(int *)(param_4 + 0x74) + 0x84) = iVar1;
  return puVar2;
}

/* FUN_000abd10 @ 0xabd10 (1640 bytes) */
int FUN_000abd10(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint *param_3;
{
  uint uVar1;
  undefined4 uVar2;
  void *pvVar3;
  uint uVar4;
  float *pfVar5;
  int iVar6;
  float fVar7;
  float *pfVar8;
  undefined4 uVar9;
  int iVar10;
  size_t sVar11;
  float *pfVar12;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  undefined4 local_48;
  float fStack_44;
  undefined4 local_40;
  float fStack_3c;
  undefined4 local_38;
  float fStack_34;
  undefined4 local_30;
  float fStack_2c;
  
  iVar10 = *(int *)(param_2 + 0x74);
  sVar11 = *(int *)(iVar10 + 0x5c) - 10;
  pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(int *)(iVar10 + 0x5c) + -6);
  param_3[2] = (uint)pvVar3;
  _memcpy(pvVar3,(void *)(*(int *)(iVar10 + 0x58) + 10),sVar11);
  uVar4 = param_3[2];
  pfVar12 = (float *)(uVar4 + 8);
  uVar1 = *(int *)(iVar10 + 0x5c) - 10U >> 2;
  *param_3 = uVar1;
  param_3[1] = uVar1 + 1;
  uVar9 = *(undefined4 *)(*(int *)(((unsigned char *)0x00001130) + param_1) * 4 + *(int *)(param_2 + 0x70));
  *(undefined1 *)(*(int *)(param_2 + 0x74) + 4) = 0;
  *(undefined1 *)(*(int *)(param_2 + 0x74) + 3) = 0;
  *(undefined1 *)(*(int *)(param_2 + 0x74) + 5) = 0;
  *(undefined4 *)(*(int *)(param_2 + 0x74) + 0xc) = 0;
  *(undefined4 *)(*(int *)(param_2 + 0x74) + 0x10) = 0;
  **(undefined1 **)(param_2 + 0x74) = 0;
  *(undefined1 *)(*(int *)(param_2 + 0x74) + 1) = 0;
  *(undefined1 *)(*(int *)(param_2 + 0x74) + 2) = 0;
  *(undefined1 *)(param_2 + 0x6c) = 1;
  while (pfVar12 < (float *)(uVar4 + sVar11)) {
    fVar7 = *pfVar12;
    switch((uint)fVar7 & 0xffff) {
    default:
      goto switchD_000abe1c_caseD_0;
    case 1:
    case 2:
    case 4:
    case 5:
    case 0xb:
    case 0xe:
    case 0x12:
    case 0x1e:
    case 0x25:
    case 0x26:
    case 0x2c:
    case 0x2d:
    case 0x2e:
    case 0x30:
    case 0x31:
    case 0x33:
    case 0x38:
    case 0x39:
    case 0x3a:
    case 0x3c:
    case 0x3d:
    case 0x47:
    case 0x48:
    case 0x4a:
    case 0x4c:
    case 0x4d:
    case 0x50:
    case 0x51:
    case 0x54:
    case 0x55:
    case 0x57:
    case 0x58:
    case 0x59:
    case 0x5a:
    case 0x5c:
    case 0x62:
    case 99:
      pfVar12 = (float *)((int (*)())FUN_000abbd0)(pfVar12,1,1,param_2);
      break;
    case 3:
    case 0xc:
    case 0x13:
    case 0x1f:
    case 0x20:
    case 0x22:
    case 0x23:
    case 0x24:
    case 0x41:
    case 0x44:
    case 0x45:
    case 0x46:
    case 0x49:
    case 0x4e:
    case 0x52:
    case 0x56:
    case 0x5b:
      pfVar12 = (float *)((int (*)())FUN_000abbd0)(pfVar12,1,2,param_2);
      break;
    case 10:
    case 0xd:
    case 0x21:
    case 0x2f:
    case 0x3f:
    case 0x40:
    case 100:
      pfVar12 = (float *)((int (*)())FUN_000abbd0)(pfVar12,1,3,param_2);
      break;
    case 0xf:
      pfVar12 = pfVar12 + *(ushort *)((int)pfVar12 + 6) + 2;
      break;
    case 0x14:
      pfVar12 = pfVar12 + 3;
      break;
    case 0x16:
      pfVar5 = pfVar12 + 1;
      pfVar12 = pfVar12 + 2;
      uVar1 = (uint)*pfVar5 >> 0x10 & 0x3f;
      if (uVar1 == 0x11) {
        *(uint *)(*(int *)(param_2 + 0x74) + 0xc) =
             1 << ((uint)*pfVar5 & 0x3f) | *(uint *)(*(int *)(param_2 + 0x74) + 0xc);
      }
      else if (uVar1 < 0x12) {
        if (uVar1 == 0x10) {
          *(undefined1 *)(*(int *)(param_2 + 0x74) + 1) = 1;
        }
      }
      else if (uVar1 == 0x13) {
        **(undefined1 **)(param_2 + 0x74) = 1;
      }
      else if (uVar1 == 0x16) {
        *(undefined1 *)(*(int *)(param_2 + 0x74) + 2) = 1;
      }
      break;
    case 0x18:
      break;
    case 0x19:
      uVar1 = (uint)fVar7 >> 0x10 & 0xff;
      pfVar12 = pfVar12 + 1;
      *(uint *)(*(int *)(param_2 + 0x74) + 0x10) =
           1 << ((uint)fVar7 >> 0x10 & 0x3f) | *(uint *)(*(int *)(param_2 + 0x74) + 0x10);
      switch((uint)fVar7 >> 0x18 & 7) {
      case 0:
        iVar10 = uVar1 * 4;
        if (*(int *)(((unsigned char *)0x000013f8) + iVar10 + param_1) == 0) {
switchD_000ac280_caseD_4:
          *(undefined4 *)(iVar10 + *(int *)(param_2 + 0x74) + 0x14) = 1;
        }
        else {
          switch(*(undefined1 *)(*(int *)(((unsigned char *)0x000013f8) + iVar10 + param_1) + 0x30)) {
          case 0:
            *(undefined4 *)(iVar10 + *(int *)(param_2 + 0x74) + 0x14) = 4;
            break;
          case 1:
            *(undefined4 *)(iVar10 + *(int *)(param_2 + 0x74) + 0x14) = 3;
            break;
          case 2:
            *(undefined4 *)(iVar10 + *(int *)(param_2 + 0x74) + 0x14) = 5;
            break;
          case 3:
            *(undefined4 *)(iVar10 + *(int *)(param_2 + 0x74) + 0x14) = 2;
            break;
          case 4:
            goto switchD_000ac280_caseD_4;
          }
        }
        break;
      case 1:
        *(undefined4 *)(uVar1 * 4 + *(int *)(param_2 + 0x74) + 0x14) = 1;
        break;
      case 2:
        uVar2 = 5;
        if (((uint)fVar7 & 0x18000000) != 0x10000000) {
          uVar2 = 2;
        }
        *(undefined4 *)(uVar1 * 4 + *(int *)(param_2 + 0x74) + 0x14) = uVar2;
        break;
      case 3:
        *(undefined4 *)(uVar1 * 4 + *(int *)(param_2 + 0x74) + 0x14) = 3;
        break;
      case 4:
        *(undefined4 *)(uVar1 * 4 + *(int *)(param_2 + 0x74) + 0x14) = 4;
      }
      break;
    case 0x1c:
      fVar7 = pfVar12[1];
      uVar1 = (uint)fVar7 >> 0x10 & 0x3f;
      if (uVar1 == 1) {
        (**(code **)(((unsigned char *)0x00001280) + param_1))
                  (param_1,uVar9,(uint)fVar7 & 0xffff,(uint)fVar7 & 0xffff,pfVar12 + 2,1,0);
        pfVar5 = pfVar12 + 6;
      }
      else {
        pfVar5 = pfVar12 + 1;
        if (uVar1 == 2) {
          local_48 = 0x43300000;
          fStack_44 = -pfVar12[2];
          local_58 = (float)((double)CONCAT44(0x43300000,fStack_44) - DOUBLE_001aa1e0);
          local_40 = 0x43300000;
          fStack_3c = -pfVar12[3];
          local_54 = (float)((double)CONCAT44(0x43300000,fStack_3c) - DOUBLE_001aa1e0);
          local_38 = 0x43300000;
          fStack_34 = -pfVar12[4];
          local_50 = (float)((double)CONCAT44(0x43300000,fStack_34) - DOUBLE_001aa1e0);
          local_30 = 0x43300000;
          fStack_2c = -pfVar12[5];
          local_4c = (float)((double)CONCAT44(0x43300000,fStack_2c) - DOUBLE_001aa1e0);
          (**(code **)(((unsigned char *)0x00001280) + param_1))
                    (param_1,uVar9,(uint)fVar7 & 0xffff,(uint)fVar7 & 0xffff,&local_58,1,0);
          pfVar5 = pfVar12 + 6;
        }
      }
      pfVar12 = pfVar5;
      iVar10 = ((uint)fVar7 & 0xffff) + 1;
      if (*(int *)(*(int *)(param_2 + 0x74) + 0x84) < iVar10) {
        *(int *)(*(int *)(param_2 + 0x74) + 0x84) = iVar10;
      }
      break;
    case 0x37:
      pfVar12 = (float *)((int (*)())FUN_000abbd0)(pfVar12,0,1,param_2);
      *(undefined1 *)(*(int *)(param_2 + 0x74) + 3) = 1;
      break;
    case 0x4b:
      pfVar12 = pfVar12 + 1;
      break;
    case 0x5d:
      pfVar5 = pfVar12 + 1;
      if ((int)fVar7 < 0) {
        pfVar5 = pfVar12 + 2;
      }
      if (((uint)fVar7 & 0x40000000) != 0) {
        pfVar5 = pfVar5 + 1;
      }
      fVar7 = *pfVar5;
      pfVar8 = pfVar5 + 1;
      if (((uint)fVar7 & 0x3f0000) == 0x180000) {
        *(undefined1 *)(*(int *)(param_2 + 0x74) + 4) = 1;
      }
      if (((uint)fVar7 & 0x400000) != 0) {
        pfVar8 = pfVar5 + 2;
      }
      local_58 = *pfVar8;
      pfVar12 = pfVar8 + 1;
      if (((uint)local_58 & 0x400000) != 0) {
        pfVar12 = pfVar8 + 2;
      }
      if (((uint)local_58 >> 0x10 & 0x3f) - 1 < 2) {
        iVar6 = *(int *)(param_2 + 0x74);
        iVar10 = ((uint)local_58 & 0xffff) + 1;
        if (*(int *)(iVar6 + 0x84) < iVar10) {
LAB_000ac4f8:
          *(int *)(iVar6 + 0x84) = iVar10;
        }
      }
      break;
    case 0x5e:
      pfVar5 = pfVar12 + 1;
      if ((int)fVar7 < 0) {
        pfVar5 = pfVar12 + 2;
      }
      if (((uint)fVar7 & 0x40000000) != 0) {
        pfVar5 = pfVar5 + 1;
      }
      fVar7 = *pfVar5;
      pfVar12 = pfVar5 + 1;
      if (((uint)fVar7 & 0x3f0000) == 0x180000) {
        *(undefined1 *)(*(int *)(param_2 + 0x74) + 4) = 1;
      }
      if (((uint)fVar7 & 0x400000) != 0) {
        pfVar12 = pfVar5 + 2;
      }
      local_58 = *pfVar12;
      pfVar5 = pfVar12 + 1;
      if (((uint)local_58 & 0x400000) != 0) {
        pfVar5 = pfVar12 + 2;
      }
      if (((uint)local_58 >> 0x10 & 0x3f) - 1 < 2) {
        iVar10 = ((uint)local_58 & 0xffff) + 1;
        if (*(int *)(*(int *)(param_2 + 0x74) + 0x84) < iVar10) {
          *(int *)(*(int *)(param_2 + 0x74) + 0x84) = iVar10;
        }
      }
      local_54 = *pfVar5;
      pfVar12 = pfVar5 + 1;
      if (((uint)local_54 & 0x400000) != 0) {
        pfVar12 = pfVar5 + 2;
      }
      if (((uint)local_54 >> 0x10 & 0x3f) - 1 < 2) {
        iVar6 = *(int *)(param_2 + 0x74);
        iVar10 = ((uint)local_54 & 0xffff) + 1;
        if (*(int *)(iVar6 + 0x84) < iVar10) goto LAB_000ac4f8;
      }
    }
  }
switchD_000abe1c_caseD_0:
  return 1;
}

/* FUN_000ac540 @ 0xac540 (476 bytes) */
int FUN_000ac540(param_1, param_2, param_3, param_4)
  int param_1;
  uint *param_2;
  uint param_3;
  uint param_4;
{
  void *pvVar1;
  uint uVar2;
  
  uVar2 = *param_2;
  if (param_2[1] <= uVar2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar2 * 4 + param_2[2]) = 0xe;
  uVar2 = *param_2 + 1;
  *param_2 = uVar2;
  if (param_2[1] <= uVar2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(uint *)(uVar2 * 4 + param_2[2]) = param_4 & 0xffff | 0x170000;
  uVar2 = *param_2 + 1;
  *param_2 = uVar2;
  if (param_2[1] <= uVar2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(uint *)(uVar2 * 4 + param_2[2]) = param_3 & 0xffff | 0x40000;
  *param_2 = *param_2 + 1;
  return;
}

/* FUN_000ac720 @ 0xac720 (7944 bytes) */
int FUN_000ac720(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  uint *param_3;
  int param_4;
  uint *param_5;
  uint param_6;
  uint *param_7;
  uint *param_8;
{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  void *pvVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  undefined4 uVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  uint *puVar18;
  uint uVar19;
  uint uVar20;
  int iVar21;
  uint *in_stack_00000038;
  char in_stack_0000003f;
  char in_stack_00000043;
  char in_stack_00000047;
  undefined4 in_stack_00000048;
  undefined4 in_stack_0000004c;
  undefined4 in_stack_00000050;
  undefined4 in_stack_00000054;
  undefined4 in_stack_00000058;
  undefined4 in_stack_0000005c;
  undefined4 in_stack_00000060;
  undefined4 in_stack_00000064;
  undefined4 in_stack_00000068;
  undefined4 in_stack_0000006c;
  undefined4 in_stack_00000070;
  undefined4 in_stack_00000074;
  undefined4 in_stack_00000078;
  undefined4 local_88;
  uint local_84;
  uint local_80;
  uint local_7c [9];
  int local_58;
  undefined4 local_54;
  
  uVar19 = 0;
  uVar14 = 0;
  local_58 = param_2;
  local_88 = 0;
  local_84 = 0;
  local_80 = 0;
  local_7c[0] = 0;
  local_7c[1] = 0;
  local_7c[2] = 0;
  local_54 = in_stack_00000078;
  if ((param_4 - 0x21U < 0x20) && ((1 << (param_4 - 0x21U & 0x3f) & 0x8fffffffU) != 0)) {
    uVar19 = 0x100;
  }
  if (param_5[1] == 0x18) {
    uVar19 = 0x100;
  }
  uVar13 = param_6 >> 2 & 1;
  uVar2 = (param_6 >> 1 & 1) << 2;
  uVar3 = uVar13 << 4;
  uVar17 = (param_5[1] & 0x3f) << 0x10 | *param_5 & 0xffff | 0x400000;
  uVar4 = (param_6 >> 3 & 1) << 6;
  uVar20 = uVar4 | uVar3 | uVar2 | param_6 & 1 | uVar19;
  switch(param_4) {
  case 0:
  case 3:
  case 8:
  case 9:
  case 10:
  case 0xc:
  case 0x12:
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x19:
  case 0x1c:
  case 0x21:
  case 0x24:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x2c:
  case 0x32:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x39:
  case 0x3c:
    iVar15 = 1;
    goto LAB_000ad33c;
  case 1:
  case 4:
  case 5:
  case 6:
  case 7:
  case 0x10:
  case 0x11:
  case 0x13:
  case 0x14:
  case 0x18:
  case 0x1a:
  case 0x1b:
  case 0x20:
  case 0x22:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x30:
  case 0x31:
  case 0x33:
  case 0x34:
  case 0x38:
  case 0x3a:
  case 0x3b:
  case 0x40:
    iVar15 = 1;
    goto LAB_000ace5c;
  case 2:
  case 0xe:
  case 0xf:
  case 0x23:
  case 0x2e:
  case 0x2f:
    local_7c[6] = in_stack_00000074;
    local_7c[5] = in_stack_00000070;
    local_7c[4] = in_stack_0000006c;
    local_7c[3] = in_stack_00000068;
    local_80 = *in_stack_00000038 & 0xffff;
    local_80 = (in_stack_00000038[1] & 0x3f) << 0x10 | local_80 | 0x400000;
    if (in_stack_00000038[1] == 0x10) {
      iVar16 = 0;
      iVar15 = 4;
      do {
        switch(*(undefined4 *)((int)local_7c + iVar16 + 0xc)) {
        default:
          uVar5 = 0;
          break;
        case 1:
        case 2:
        case 4:
        case 7:
        case 8:
          uVar5 = 4;
          break;
        case 3:
        case 5:
          uVar5 = 5;
          break;
        case 6:
          uVar5 = 6;
          break;
        case 9:
        case 10:
          uVar5 = 10;
        }
        iVar15 = iVar15 + -1;
        *(undefined4 *)((int)local_7c + iVar16 + 0xc) = uVar5;
        iVar16 = iVar16 + 4;
      } while (iVar15 != 0);
    }
    switch(local_7c[3]) {
    default:
      bVar1 = false;
      local_7c[2] = 0;
      break;
    case 1:
      bVar1 = false;
      local_7c[2] = 1;
      break;
    case 2:
      bVar1 = false;
      local_7c[2] = 2;
      break;
    case 3:
      bVar1 = false;
      local_7c[2] = 3;
      break;
    case 4:
      bVar1 = false;
      local_7c[2] = 4;
      break;
    case 5:
      bVar1 = false;
      local_7c[2] = 5;
      break;
    case 6:
      bVar1 = true;
      local_7c[2] = 0;
      break;
    case 7:
      bVar1 = true;
      local_7c[2] = 1;
      break;
    case 8:
      bVar1 = true;
      local_7c[2] = 2;
      break;
    case 9:
      bVar1 = true;
      local_7c[2] = 3;
      break;
    case 10:
      bVar1 = true;
      local_7c[2] = 5;
    }
    if (bVar1) {
      local_7c[2] = local_7c[2] | 8;
    }
    switch(local_7c[4]) {
    default:
      bVar1 = false;
      iVar15 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar15 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar15 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar15 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar15 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar15 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar15 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar15 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar15 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar15 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar15 = 5;
    }
    local_7c[2] = iVar15 << 4 | local_7c[2];
    if (bVar1) {
      local_7c[2] = local_7c[2] | 0x80;
    }
    switch(local_7c[5]) {
    default:
      bVar1 = false;
      iVar15 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar15 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar15 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar15 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar15 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar15 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar15 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar15 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar15 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar15 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar15 = 5;
    }
    local_7c[2] = iVar15 << 8 | local_7c[2];
    if (bVar1) {
      local_7c[2] = local_7c[2] | 0x800;
    }
    switch(local_7c[6]) {
    default:
      bVar1 = false;
      iVar15 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar15 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar15 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar15 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar15 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar15 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar15 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar15 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar15 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar15 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar15 = 5;
    }
    local_7c[2] = iVar15 << 0xc | local_7c[2];
    if (bVar1) {
      local_7c[2] = local_7c[2] | 0x8000;
    }
    iVar15 = 2;
    if (in_stack_00000047 != '\0') {
      local_7c[2] = (local_7c[2] & 0xfffff777 ^ 0x8000) & 0x8000 |
                    (local_7c[2] & 0xffffff77 ^ 0x800) & 0x800 |
                    (local_7c[2] & 0xfffffff7 ^ 0x80) & 0x80 |
                    (local_7c[2] ^ 8) & 8 | local_7c[2] & 0xffff7777;
    }
LAB_000ace5c:
    local_7c[6] = in_stack_00000064;
    local_7c[5] = in_stack_00000060;
    local_7c[4] = in_stack_0000005c;
    local_7c[3] = in_stack_00000058;
    local_84 = (param_8[1] & 0x3f) << 0x10 | *param_8 & 0xffff | 0x400000;
    if (param_8[1] == 0x10) {
      iVar21 = 0;
      iVar16 = 4;
      do {
        switch(*(undefined4 *)((int)local_7c + iVar21 + 0xc)) {
        default:
          uVar5 = 0;
          break;
        case 1:
        case 2:
        case 4:
        case 7:
        case 8:
          uVar5 = 4;
          break;
        case 3:
        case 5:
          uVar5 = 5;
          break;
        case 6:
          uVar5 = 6;
          break;
        case 9:
        case 10:
          uVar5 = 10;
        }
        iVar16 = iVar16 + -1;
        *(undefined4 *)((int)local_7c + iVar21 + 0xc) = uVar5;
        iVar21 = iVar21 + 4;
      } while (iVar16 != 0);
    }
    switch(local_7c[3]) {
    default:
      bVar1 = false;
      local_7c[1] = 0;
      break;
    case 1:
      bVar1 = false;
      local_7c[1] = 1;
      break;
    case 2:
      bVar1 = false;
      local_7c[1] = 2;
      break;
    case 3:
      bVar1 = false;
      local_7c[1] = 3;
      break;
    case 4:
      bVar1 = false;
      local_7c[1] = 4;
      break;
    case 5:
      bVar1 = false;
      local_7c[1] = 5;
      break;
    case 6:
      bVar1 = true;
      local_7c[1] = 0;
      break;
    case 7:
      bVar1 = true;
      local_7c[1] = 1;
      break;
    case 8:
      bVar1 = true;
      local_7c[1] = 2;
      break;
    case 9:
      bVar1 = true;
      local_7c[1] = 3;
      break;
    case 10:
      bVar1 = true;
      local_7c[1] = 5;
    }
    if (bVar1) {
      local_7c[1] = local_7c[1] | 8;
    }
    switch(local_7c[4]) {
    default:
      bVar1 = false;
      iVar16 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar16 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar16 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar16 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar16 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar16 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar16 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar16 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar16 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar16 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar16 = 5;
    }
    local_7c[1] = iVar16 << 4 | local_7c[1];
    if (bVar1) {
      local_7c[1] = local_7c[1] | 0x80;
    }
    switch(local_7c[5]) {
    default:
      bVar1 = false;
      iVar16 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar16 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar16 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar16 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar16 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar16 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar16 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar16 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar16 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar16 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar16 = 5;
    }
    local_7c[1] = iVar16 << 8 | local_7c[1];
    if (bVar1) {
      local_7c[1] = local_7c[1] | 0x800;
    }
    switch(local_7c[6]) {
    default:
      bVar1 = false;
      iVar16 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar16 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar16 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar16 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar16 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar16 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar16 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar16 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar16 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar16 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar16 = 5;
    }
    local_7c[1] = iVar16 << 0xc | local_7c[1];
    if (bVar1) {
      local_7c[1] = local_7c[1] | 0x8000;
    }
    iVar15 = iVar15 + 1;
    if (in_stack_00000043 != '\0') {
      local_7c[1] = (local_7c[1] & 0xfffff777 ^ 0x8000) & 0x8000 |
                    (local_7c[1] & 0xffffff77 ^ 0x800) & 0x800 |
                    (local_7c[1] & 0xfffffff7 ^ 0x80) & 0x80 |
                    (local_7c[1] ^ 8) & 8 | local_7c[1] & 0xffff7777;
    }
LAB_000ad33c:
    local_7c[6] = in_stack_00000054;
    local_7c[5] = in_stack_00000050;
    local_7c[4] = in_stack_0000004c;
    local_7c[3] = in_stack_00000048;
    local_88 = (param_7[1] & 0x3f) << 0x10 | *param_7 & 0xffff | 0x400000;
    if (param_7[1] == 0x10) {
      iVar21 = 0;
      iVar16 = 4;
      do {
        switch(*(undefined4 *)((int)local_7c + iVar21 + 0xc)) {
        default:
          uVar5 = 0;
          break;
        case 1:
        case 2:
        case 4:
        case 7:
        case 8:
          uVar5 = 4;
          break;
        case 3:
        case 5:
          uVar5 = 5;
          break;
        case 6:
          uVar5 = 6;
          break;
        case 9:
        case 10:
          uVar5 = 10;
        }
        iVar16 = iVar16 + -1;
        *(undefined4 *)((int)local_7c + iVar21 + 0xc) = uVar5;
        iVar21 = iVar21 + 4;
      } while (iVar16 != 0);
    }
    switch(local_7c[3]) {
    default:
      bVar1 = false;
      local_7c[0] = 0;
      break;
    case 1:
      bVar1 = false;
      local_7c[0] = 1;
      break;
    case 2:
      bVar1 = false;
      local_7c[0] = 2;
      break;
    case 3:
      bVar1 = false;
      local_7c[0] = 3;
      break;
    case 4:
      bVar1 = false;
      local_7c[0] = 4;
      break;
    case 5:
      bVar1 = false;
      local_7c[0] = 5;
      break;
    case 6:
      bVar1 = true;
      local_7c[0] = 0;
      break;
    case 7:
      bVar1 = true;
      local_7c[0] = 1;
      break;
    case 8:
      bVar1 = true;
      local_7c[0] = 2;
      break;
    case 9:
      bVar1 = true;
      local_7c[0] = 3;
      break;
    case 10:
      bVar1 = true;
      local_7c[0] = 5;
    }
    if (bVar1) {
      local_7c[0] = local_7c[0] | 8;
    }
    switch(local_7c[4]) {
    default:
      bVar1 = false;
      iVar16 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar16 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar16 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar16 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar16 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar16 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar16 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar16 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar16 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar16 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar16 = 5;
    }
    local_7c[0] = iVar16 << 4 | local_7c[0];
    if (bVar1) {
      local_7c[0] = local_7c[0] | 0x80;
    }
    switch(local_7c[5]) {
    default:
      bVar1 = false;
      iVar16 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar16 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar16 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar16 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar16 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar16 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar16 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar16 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar16 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar16 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar16 = 5;
    }
    local_7c[0] = iVar16 << 8 | local_7c[0];
    if (bVar1) {
      local_7c[0] = local_7c[0] | 0x800;
    }
    switch(local_7c[6]) {
    default:
      bVar1 = false;
      iVar16 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar16 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar16 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar16 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar16 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar16 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar16 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar16 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar16 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar16 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar16 = 5;
    }
    local_7c[0] = iVar16 << 0xc | local_7c[0];
    if (bVar1) {
      local_7c[0] = local_7c[0] | 0x8000;
    }
    if (in_stack_0000003f != '\0') {
      local_7c[0] = (local_7c[0] & 0xfffff777 ^ 0x8000) & 0x8000 |
                    (local_7c[0] & 0xffffff77 ^ 0x800) & 0x800 |
                    (local_7c[0] & 0xfffffff7 ^ 0x80) & 0x80 |
                    (local_7c[0] ^ 8) & 8 | local_7c[0] & 0xffff7777;
    }
    break;
  default:
    iVar15 = 0;
    break;
  case 0xd:
  case 0x2d:
    uVar6 = *param_7;
    uVar10 = param_7[1];
    local_7c[6] = in_stack_00000054;
    local_7c[5] = in_stack_00000050;
    local_7c[4] = in_stack_0000004c;
    local_7c[3] = in_stack_00000048;
    uVar8 = *(int *)(param_2 + 0x88) + 2;
    uVar12 = uVar8 & 0xffff;
    if (uVar10 == 0x10) {
      iVar16 = 0;
      iVar15 = 4;
      do {
        switch(*(undefined4 *)((int)local_7c + iVar16 + 0xc)) {
        default:
          uVar5 = 0;
          break;
        case 1:
        case 2:
        case 4:
        case 7:
        case 8:
          uVar5 = 4;
          break;
        case 3:
        case 5:
          uVar5 = 5;
          break;
        case 6:
          uVar5 = 6;
          break;
        case 9:
        case 10:
          uVar5 = 10;
        }
        iVar15 = iVar15 + -1;
        *(undefined4 *)((int)local_7c + iVar16 + 0xc) = uVar5;
        iVar16 = iVar16 + 4;
      } while (iVar15 != 0);
    }
    switch(local_7c[3]) {
    default:
      bVar1 = false;
      uVar7 = 0;
      break;
    case 1:
      bVar1 = false;
      uVar7 = 1;
      break;
    case 2:
      bVar1 = false;
      uVar7 = 2;
      break;
    case 3:
      bVar1 = false;
      uVar7 = 3;
      break;
    case 4:
      bVar1 = false;
      uVar7 = 4;
      break;
    case 5:
      bVar1 = false;
      uVar7 = 5;
      break;
    case 6:
      bVar1 = true;
      uVar7 = 0;
      break;
    case 7:
      bVar1 = true;
      uVar7 = 1;
      break;
    case 8:
      bVar1 = true;
      uVar7 = 2;
      break;
    case 9:
      bVar1 = true;
      uVar7 = 3;
      break;
    case 10:
      bVar1 = true;
      uVar7 = 5;
    }
    if (bVar1) {
      uVar7 = uVar7 | 8;
    }
    switch(local_7c[4]) {
    default:
      bVar1 = false;
      iVar15 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar15 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar15 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar15 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar15 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar15 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar15 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar15 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar15 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar15 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar15 = 5;
    }
    uVar7 = iVar15 << 4 | uVar7;
    if (bVar1) {
      uVar7 = uVar7 | 0x80;
    }
    switch(local_7c[5]) {
    default:
      bVar1 = false;
      iVar15 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar15 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar15 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar15 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar15 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar15 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar15 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar15 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar15 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar15 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar15 = 5;
    }
    uVar7 = iVar15 << 8 | uVar7;
    if (bVar1) {
      uVar7 = uVar7 | 0x800;
    }
    switch(local_7c[6]) {
    default:
      bVar1 = false;
      iVar15 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar15 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar15 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar15 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar15 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar15 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar15 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar15 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar15 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar15 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar15 = 5;
    }
    uVar7 = iVar15 << 0xc | uVar7;
    if (bVar1) {
      uVar7 = uVar7 | 0x8000;
    }
    if (in_stack_0000003f != '\0') {
      uVar7 = (uVar7 & 0xfffff777 ^ 0x8000) & 0x8000 |
              (uVar7 & 0xffffff77 ^ 0x800) & 0x800 |
              (uVar7 & 0xfffffff7 ^ 0x80) & 0x80 | (uVar7 ^ 8) & 8 | uVar7 & 0xffff7777;
    }
    uVar11 = *param_3;
    if (param_3[1] <= uVar11) {
      pvVar9 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar9,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar9;
      uVar11 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    *(undefined4 *)(uVar11 * 4 + param_3[2]) = 0x47;
    uVar11 = *param_3 + 1;
    *param_3 = uVar11;
    if (param_3[1] <= uVar11) {
      pvVar9 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar9,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar9;
      uVar11 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    *(uint *)(uVar11 * 4 + param_3[2]) = uVar12 | 0x40000;
    uVar11 = *param_3 + 1;
    *param_3 = uVar11;
    if (param_3[1] <= uVar11) {
      pvVar9 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar9,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar9;
      uVar11 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    *(uint *)(uVar11 * 4 + param_3[2]) = (uVar10 & 0x3f) << 0x10 | uVar6 & 0xffff | 0x400000;
    uVar6 = *param_3 + 1;
    *param_3 = uVar6;
    if (param_3[1] <= uVar6) {
      pvVar9 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar9,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar9;
      uVar6 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    *(uint *)(uVar6 * 4 + param_3[2]) = uVar7;
    uVar6 = *param_3 + 1;
    *param_3 = uVar6;
    if (param_3[1] <= uVar6) {
      pvVar9 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar9,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar9;
      uVar6 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    *(undefined4 *)(uVar6 * 4 + param_3[2]) = 0x2000d;
    uVar6 = *param_3 + 1;
    *param_3 = uVar6;
    if (param_3[1] <= uVar6) {
      pvVar9 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar9,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar9;
      uVar6 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    *(uint *)(uVar6 * 4 + param_3[2]) = uVar12 | 0x440000;
    uVar6 = *param_3 + 1;
    *param_3 = uVar6;
    if (param_3[1] <= uVar6) {
      pvVar9 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar9,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar9;
      uVar6 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    *(undefined4 *)(uVar6 * 4 + param_3[2]) = 4;
    uVar6 = *param_3 + 1;
    *param_3 = uVar6;
    if (param_3[1] <= uVar6) {
      pvVar9 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar9,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar9;
      uVar6 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    *(uint *)(uVar6 * 4 + param_3[2]) = uVar12 | 0x40000;
    uVar6 = *param_3 + 1;
    *param_3 = uVar6;
    if (param_3[1] <= uVar6) {
      pvVar9 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar9,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar9;
      uVar6 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    *(uint *)(uVar6 * 4 + param_3[2]) = uVar12 | 0x40000;
    uVar6 = *param_3 + 1;
    *param_3 = uVar6;
    if (param_3[1] <= uVar6) {
      pvVar9 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar9,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar9;
      uVar6 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    *(uint *)(uVar6 * 4 + param_3[2]) = uVar12 | 0x440000;
    uVar12 = *param_3 + 1;
    *param_3 = uVar12;
    if (param_3[1] <= uVar12) {
      pvVar9 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar9,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar9;
      uVar12 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    iVar15 = 1;
    *(undefined **)(uVar12 * 4 + param_3[2]) = ((unsigned char *)0x00004444);
    local_88 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_88) + 0)),(short)uVar8);
    *param_3 = *param_3 + 1;
    local_88 = local_88 & 0xff80ffff | 0x40000;
  }
  switch(param_4) {
  case 0:
  case 0x21:
    uVar14 = 1;
    break;
  case 1:
  case 0x22:
    uVar14 = 3;
    break;
  case 2:
  case 0x23:
    uVar14 = 0x5000d;
    break;
  case 3:
  case 0x24:
    uVar14 = 0x12;
    goto LAB_000ae47c;
  case 4:
  case 0x25:
    uVar14 = 0x22;
    break;
  case 5:
  case 0x26:
    uVar14 = 0x23;
    break;
  case 6:
  case 0x27:
    uVar14 = 0x23;
    local_7c[0] = local_7c[0] & 0xffff0fff | 0x5000;
    break;
  case 7:
  case 0x28:
    uVar14 = 0x24;
    break;
  case 8:
  case 0x29:
    uVar14 = 0x2d;
    break;
  case 9:
  case 0x2a:
    uVar14 = 0x30;
    break;
  case 10:
  case 0x2b:
    uVar14 = 0x31;
    break;
  case 0xc:
  case 0x2c:
    uVar14 = 0x3c;
    break;
  case 0xd:
  case 0x2d:
    uVar14 = 0x39;
    break;
  case 0xe:
  case 0x2e:
    uVar14 = 0x3f;
    break;
  case 0xf:
  case 0x2f:
    uVar14 = 0x40;
    break;
  case 0x10:
  case 0x30:
    uVar14 = 0x41;
    break;
  case 0x11:
  case 0x31:
    uVar14 = 0x44;
    break;
  case 0x12:
  case 0x1c:
  case 0x32:
  case 0x3c:
    uVar14 = 0x47;
    break;
  case 0x13:
  case 0x33:
    uVar14 = 0x49;
    break;
  case 0x14:
  case 0x34:
    uVar14 = 0x4e;
    break;
  case 0x15:
  case 0x35:
    uVar14 = 0x51;
    break;
  case 0x16:
  case 0x36:
    uVar14 = 0x55;
    local_7c[0] = local_7c[0] & 0xffff7777 | 0x100000;
    break;
  case 0x17:
  case 0x37:
    uVar14 = 0x59;
    break;
  case 0x18:
  case 0x38:
    uVar14 = 0x20056;
    break;
  case 0x19:
  case 0x39:
    uVar14 = 0x58;
LAB_000ae47c:
    uVar12 = *param_3;
    if (param_3[1] <= uVar12) {
      pvVar9 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar9,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar9;
      uVar12 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    *(undefined4 *)(uVar12 * 4 + param_3[2]) = 0x4d;
    uVar12 = *param_3 + 1;
    *param_3 = uVar12;
    iVar16 = *(int *)(((unsigned char *)0x000011e0) + param_1);
    if (param_3[1] <= uVar12) {
      pvVar9 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar9,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar9;
      uVar12 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    uVar6 = local_88;
    *(uint *)(uVar12 * 4 + param_3[2]) = iVar16 + 1U & 0xffff | 0x40000;
    uVar12 = *param_3 + 1;
    *param_3 = uVar12;
    if (param_3[1] <= uVar12) {
      pvVar9 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar9,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar9;
      uVar12 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    uVar8 = local_7c[0];
    *(uint *)(uVar12 * 4 + param_3[2]) = uVar6;
    uVar12 = *param_3 + 1;
    *param_3 = uVar12;
    if ((local_88 & 0x400000) != 0) {
      if (param_3[1] <= uVar12) {
        pvVar9 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
        if ((void *)param_3[2] != (void *)0x0) {
          _memcpy(pvVar9,(void *)param_3[2],*param_3 << 2);
          (**(code **)(param_1 + 0x18))(param_3[2]);
        }
        param_3[2] = (uint)pvVar9;
        uVar12 = *param_3;
        param_3[1] = param_3[1] + 0x80;
      }
      *(uint *)(uVar12 * 4 + param_3[2]) = uVar8;
      *param_3 = *param_3 + 1;
    }
    local_88 = CONCAT22((short)(local_88 >> 0x10),
                        (short)*(undefined4 *)(((unsigned char *)0x000011e0) + param_1) + 1) & 0xffc0ffff | 0x40000;
    break;
  case 0x1a:
  case 0x3a:
    uVar14 = 0x50056;
    break;
  case 0x1b:
  case 0x3b:
    uVar14 = 0x5b;
    break;
  case 0x20:
  case 0x40:
    uVar14 = 0x13;
  }
  if (param_5[1] == 0x18) {
    if (iVar15 != 0) {
      iVar21 = 0;
      iVar16 = iVar15;
      do {
        if (((&local_88)[iVar21] & 0x400000) != 0) {
          uVar20 = local_7c[iVar21];
          local_7c[iVar21] = uVar20 >> 8 & 7 | uVar20 >> 8 & 8 | uVar20 & 0xfffffff0;
        }
        iVar21 = iVar21 + 1;
        iVar16 = iVar16 + -1;
      } while (iVar16 != 0);
    }
    uVar20 = uVar13 | uVar4 | uVar3 | uVar2 | uVar19;
    bVar1 = false;
  }
  else if (param_5[1] == 0x17) {
    bVar1 = true;
    uVar17 = *(uint *)(local_58 + 0x88) & 0xffff | 0x440000;
  }
  else {
    bVar1 = false;
  }
  uVar19 = *param_3;
  if (param_3[1] <= uVar19) {
    pvVar9 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
    if ((void *)param_3[2] != (void *)0x0) {
      _memcpy(pvVar9,(void *)param_3[2],*param_3 << 2);
      (**(code **)(param_1 + 0x18))(param_3[2]);
    }
    param_3[2] = (uint)pvVar9;
    uVar19 = *param_3;
    param_3[1] = param_3[1] + 0x80;
  }
  *(undefined4 *)(uVar19 * 4 + param_3[2]) = uVar14;
  uVar19 = *param_3 + 1;
  *param_3 = uVar19;
  if (param_3[1] <= uVar19) {
    pvVar9 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
    if ((void *)param_3[2] != (void *)0x0) {
      _memcpy(pvVar9,(void *)param_3[2],*param_3 << 2);
      (**(code **)(param_1 + 0x18))(param_3[2]);
    }
    param_3[2] = (uint)pvVar9;
    uVar19 = *param_3;
    param_3[1] = param_3[1] + 0x80;
  }
  *(uint *)(uVar19 * 4 + param_3[2]) = uVar17;
  uVar19 = *param_3 + 1;
  *param_3 = uVar19;
  if ((uVar17 & 0x400000) != 0) {
    if (param_3[1] <= uVar19) {
      pvVar9 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar9,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar9;
      uVar19 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    *(uint *)(uVar19 * 4 + param_3[2]) = uVar20;
    uVar19 = *param_3 + 1;
    *param_3 = uVar19;
  }
  if (iVar15 != 0) {
    iVar16 = 0;
    iVar21 = 0;
    puVar18 = &local_88;
    do {
      uVar14 = *(undefined4 *)(iVar21 + (int)&local_88);
      if (param_3[1] <= uVar19) {
        pvVar9 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
        if ((void *)param_3[2] != (void *)0x0) {
          _memcpy(pvVar9,(void *)param_3[2],*param_3 << 2);
          (**(code **)(param_1 + 0x18))(param_3[2]);
        }
        param_3[2] = (uint)pvVar9;
        uVar19 = *param_3;
        param_3[1] = param_3[1] + 0x80;
      }
      *(undefined4 *)(uVar19 * 4 + param_3[2]) = uVar14;
      uVar19 = *param_3 + 1;
      *param_3 = uVar19;
      if ((*puVar18 & 0x400000) != 0) {
        uVar14 = *(undefined4 *)((int)local_7c + iVar21);
        if (param_3[1] <= uVar19) {
          pvVar9 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
          if ((void *)param_3[2] != (void *)0x0) {
            _memcpy(pvVar9,(void *)param_3[2],*param_3 << 2);
            (**(code **)(param_1 + 0x18))(param_3[2]);
          }
          param_3[2] = (uint)pvVar9;
          uVar19 = *param_3;
          param_3[1] = param_3[1] + 0x80;
        }
        *(undefined4 *)(uVar19 * 4 + param_3[2]) = uVar14;
        uVar19 = *param_3 + 1;
        *param_3 = uVar19;
      }
      iVar16 = iVar16 + 1;
      puVar18 = puVar18 + 1;
      iVar21 = iVar21 + 4;
    } while (iVar15 != iVar16);
  }
  if (bVar1) {
    ((int (*)())FUN_000ac540)(param_1,param_3,*(undefined4 *)(local_58 + 0x88),local_54);
    return;
  }
  return;
}

/* FUN_000aec40 @ 0xaec40 (3872 bytes) */
int FUN_000aec40(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  uint *param_3;
  int param_4;
  uint *param_5;
  uint param_6;
  uint *param_7;
  undefined4 param_8;
{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  void *pvVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint *puVar15;
  undefined4 uStack00000034;
  undefined4 in_stack_00000038;
  undefined4 in_stack_0000003c;
  undefined4 in_stack_00000040;
  char in_stack_00000047;
  uint in_stack_00000048;
  int in_stack_0000004c;
  uint local_88;
  undefined4 local_84;
  uint local_80;
  uint local_7c [14];
  
  uVar13 = 0;
  uVar10 = param_5[1];
  local_88 = 0;
  local_84 = 0;
  local_7c[0] = 0;
  local_80 = 0;
  local_7c[1] = 0;
  if (uVar10 != 0x17) {
    uVar12 = (uVar10 & 0x3f) << 0x10 | *param_5 & 0xffff;
  }
  else {
    uVar12 = *(uint *)(param_2 + 0x88) & 0xffff | 0x40000;
  }
  if (param_4 - 0x3dU < 3) {
    uVar13 = 0x100;
  }
  if (uVar10 == 0x18) {
    uVar13 = 0x100;
  }
  uStack00000034 = param_8;
  if ((param_4 == 0x1f) && (in_stack_00000047 != '\0')) {
    uVar2 = *param_7;
    uVar7 = param_7[1];
    local_7c[5] = in_stack_00000040;
    local_7c[4] = in_stack_0000003c;
    local_7c[3] = in_stack_00000038;
    local_7c[2] = param_8;
    uVar5 = *(int *)(param_2 + 0x88) + 1;
    if (uVar7 == 0x10) {
      iVar11 = 0;
      iVar8 = 4;
      do {
        switch(*(undefined4 *)((int)local_7c + iVar11 + 8)) {
        default:
          uVar3 = 0;
          break;
        case 1:
        case 2:
        case 4:
        case 7:
        case 8:
          uVar3 = 4;
          break;
        case 3:
        case 5:
          uVar3 = 5;
          break;
        case 6:
          uVar3 = 6;
          break;
        case 9:
        case 10:
          uVar3 = 10;
        }
        iVar8 = iVar8 + -1;
        *(undefined4 *)((int)local_7c + iVar11 + 8) = uVar3;
        iVar11 = iVar11 + 4;
      } while (iVar8 != 0);
    }
    switch(local_7c[2]) {
    default:
      bVar1 = false;
      uVar4 = 0;
      break;
    case 1:
      bVar1 = false;
      uVar4 = 1;
      break;
    case 2:
      bVar1 = false;
      uVar4 = 2;
      break;
    case 3:
      bVar1 = false;
      uVar4 = 3;
      break;
    case 4:
      bVar1 = false;
      uVar4 = 4;
      break;
    case 5:
      bVar1 = false;
      uVar4 = 5;
      break;
    case 6:
      bVar1 = true;
      uVar4 = 0;
      break;
    case 7:
      bVar1 = true;
      uVar4 = 1;
      break;
    case 8:
      bVar1 = true;
      uVar4 = 2;
      break;
    case 9:
      bVar1 = true;
      uVar4 = 3;
      break;
    case 10:
      bVar1 = true;
      uVar4 = 5;
    }
    if (bVar1) {
      uVar4 = uVar4 | 8;
    }
    switch(local_7c[3]) {
    default:
      bVar1 = false;
      iVar8 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar8 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar8 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar8 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar8 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar8 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar8 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar8 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar8 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar8 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar8 = 5;
    }
    uVar4 = iVar8 << 4 | uVar4;
    if (bVar1) {
      uVar4 = uVar4 | 0x80;
    }
    switch(local_7c[4]) {
    default:
      bVar1 = false;
      iVar8 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar8 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar8 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar8 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar8 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar8 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar8 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar8 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar8 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar8 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar8 = 5;
    }
    uVar4 = iVar8 << 8 | uVar4;
    if (bVar1) {
      uVar4 = uVar4 | 0x800;
    }
    switch(local_7c[5]) {
    default:
      bVar1 = false;
      iVar8 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar8 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar8 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar8 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar8 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar8 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar8 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar8 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar8 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar8 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar8 = 5;
    }
    uVar4 = iVar8 << 0xc | uVar4;
    if (bVar1) {
      uVar4 = uVar4 | 0x8000;
    }
    uVar9 = *param_3;
    if (param_3[1] <= uVar9) {
      pvVar6 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar6,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar6;
      uVar9 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    *(undefined4 *)(uVar9 * 4 + param_3[2]) = 0x47;
    uVar9 = *param_3 + 1;
    *param_3 = uVar9;
    if (param_3[1] <= uVar9) {
      pvVar6 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar6,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar6;
      uVar9 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    *(uint *)(uVar9 * 4 + param_3[2]) = uVar5 & 0xffff | 0x40000;
    uVar9 = *param_3 + 1;
    *param_3 = uVar9;
    if (param_3[1] <= uVar9) {
      pvVar6 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar6,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar6;
      uVar9 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    *(uint *)(uVar9 * 4 + param_3[2]) = (uVar7 & 0x3f) << 0x10 | uVar2 & 0xffff | 0x400000;
    uVar2 = *param_3 + 1;
    *param_3 = uVar2;
    if (param_3[1] <= uVar2) {
      pvVar6 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar6,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar6;
      uVar2 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    *(uint *)(uVar2 * 4 + param_3[2]) =
         (uVar4 & 0xfffff777 ^ 0x8000) & 0x8000 |
         (uVar4 & 0xffffff77 ^ 0x800) & 0x800 |
         (uVar4 & 0xfffffff7 ^ 0x80) & 0x80 | (uVar4 ^ 8) & 8 | uVar4 & 0xffff7777;
    local_84 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_84) + 0)),(short)uVar5);
    local_7c[0] = local_7c[0] & 0xffff8888 | 0x3210;
    uVar2 = *param_3 + 1;
    *param_3 = uVar2;
    local_84 = local_84 & 0xffc0ffff | 0x40000;
LAB_000af474:
    iVar8 = 1;
    local_88 = 0x5d;
    local_84 = local_84 | 0x400000;
    local_7c[0] = local_7c[0] & 0xff1fffff | 0x600000;
    goto LAB_000afabc;
  }
  local_7c[5] = in_stack_00000040;
  local_7c[4] = in_stack_0000003c;
  local_7c[3] = in_stack_00000038;
  local_7c[2] = param_8;
  local_84 = *param_7 & 0xffff;
  local_84 = (param_7[1] & 0x3f) << 0x10 | local_84 | 0x400000;
  if (param_7[1] == 0x10) {
    iVar11 = 0;
    iVar8 = 4;
    do {
      switch(*(undefined4 *)((int)local_7c + iVar11 + 8)) {
      default:
        uVar3 = 0;
        break;
      case 1:
      case 2:
      case 4:
      case 7:
      case 8:
        uVar3 = 4;
        break;
      case 3:
      case 5:
        uVar3 = 5;
        break;
      case 6:
        uVar3 = 6;
        break;
      case 9:
      case 10:
        uVar3 = 10;
      }
      iVar8 = iVar8 + -1;
      *(undefined4 *)((int)local_7c + iVar11 + 8) = uVar3;
      iVar11 = iVar11 + 4;
    } while (iVar8 != 0);
  }
  switch(local_7c[2]) {
  default:
    bVar1 = false;
    local_7c[0] = 0;
    break;
  case 1:
    bVar1 = false;
    local_7c[0] = 1;
    break;
  case 2:
    bVar1 = false;
    local_7c[0] = 2;
    break;
  case 3:
    bVar1 = false;
    local_7c[0] = 3;
    break;
  case 4:
    bVar1 = false;
    local_7c[0] = 4;
    break;
  case 5:
    bVar1 = false;
    local_7c[0] = 5;
    break;
  case 6:
    bVar1 = true;
    local_7c[0] = 0;
    break;
  case 7:
    bVar1 = true;
    local_7c[0] = 1;
    break;
  case 8:
    bVar1 = true;
    local_7c[0] = 2;
    break;
  case 9:
    bVar1 = true;
    local_7c[0] = 3;
    break;
  case 10:
    bVar1 = true;
    local_7c[0] = 5;
  }
  if (bVar1) {
    local_7c[0] = local_7c[0] | 8;
  }
  switch(local_7c[3]) {
  default:
    bVar1 = false;
    iVar8 = 0;
    break;
  case 1:
    bVar1 = false;
    iVar8 = 1;
    break;
  case 2:
    bVar1 = false;
    iVar8 = 2;
    break;
  case 3:
    bVar1 = false;
    iVar8 = 3;
    break;
  case 4:
    bVar1 = false;
    iVar8 = 4;
    break;
  case 5:
    bVar1 = false;
    iVar8 = 5;
    break;
  case 6:
    bVar1 = true;
    iVar8 = 0;
    break;
  case 7:
    bVar1 = true;
    iVar8 = 1;
    break;
  case 8:
    bVar1 = true;
    iVar8 = 2;
    break;
  case 9:
    bVar1 = true;
    iVar8 = 3;
    break;
  case 10:
    bVar1 = true;
    iVar8 = 5;
  }
  local_7c[0] = iVar8 << 4 | local_7c[0];
  if (bVar1) {
    local_7c[0] = local_7c[0] | 0x80;
  }
  switch(local_7c[4]) {
  default:
    bVar1 = false;
    iVar8 = 0;
    break;
  case 1:
    bVar1 = false;
    iVar8 = 1;
    break;
  case 2:
    bVar1 = false;
    iVar8 = 2;
    break;
  case 3:
    bVar1 = false;
    iVar8 = 3;
    break;
  case 4:
    bVar1 = false;
    iVar8 = 4;
    break;
  case 5:
    bVar1 = false;
    iVar8 = 5;
    break;
  case 6:
    bVar1 = true;
    iVar8 = 0;
    break;
  case 7:
    bVar1 = true;
    iVar8 = 1;
    break;
  case 8:
    bVar1 = true;
    iVar8 = 2;
    break;
  case 9:
    bVar1 = true;
    iVar8 = 3;
    break;
  case 10:
    bVar1 = true;
    iVar8 = 5;
  }
  local_7c[0] = iVar8 << 8 | local_7c[0];
  if (bVar1) {
    local_7c[0] = local_7c[0] | 0x800;
  }
  switch(local_7c[5]) {
  default:
    bVar1 = false;
    iVar8 = 0;
    break;
  case 1:
    bVar1 = false;
    iVar8 = 1;
    break;
  case 2:
    bVar1 = false;
    iVar8 = 2;
    break;
  case 3:
    bVar1 = false;
    iVar8 = 3;
    break;
  case 4:
    bVar1 = false;
    iVar8 = 4;
    break;
  case 5:
    bVar1 = false;
    iVar8 = 5;
    break;
  case 6:
    bVar1 = true;
    iVar8 = 0;
    break;
  case 7:
    bVar1 = true;
    iVar8 = 1;
    break;
  case 8:
    bVar1 = true;
    iVar8 = 2;
    break;
  case 9:
    bVar1 = true;
    iVar8 = 3;
    break;
  case 10:
    bVar1 = true;
    iVar8 = 5;
  }
  local_7c[0] = iVar8 << 0xc | local_7c[0];
  if (bVar1) {
    local_7c[0] = local_7c[0] | 0x8000;
  }
  if (in_stack_00000047 != '\0') {
    local_7c[0] = (local_7c[0] & 0xfffff777 ^ 0x8000) & 0x8000 |
                  (local_7c[0] & 0xffffff77 ^ 0x800) & 0x800 |
                  (local_7c[0] & 0xfffffff7 ^ 0x80) & 0x80 |
                  (local_7c[0] ^ 8) & 8 | local_7c[0] & 0xffff7777;
  }
  switch(param_4) {
  case 0xb:
    uVar2 = *param_3;
    iVar8 = 1;
    local_88 = 0x37;
    goto LAB_000afb10;
  default:
    uVar2 = *param_3;
    iVar8 = 0;
    goto LAB_000afb10;
  case 0x1d:
  case 0x3d:
    uVar2 = *param_3;
    iVar8 = 1;
    local_88 = 0x5d;
    break;
  case 0x1e:
  case 0x3e:
    iVar8 = 2;
    local_88 = 0x5e;
    uVar2 = *param_3;
    local_80 = local_84;
    local_7c[1] = local_7c[0];
    break;
  case 0x1f:
  case 0x3f:
    uVar2 = *param_3;
    goto LAB_000af474;
  }
LAB_000afabc:
  local_88 = (uint)(in_stack_0000004c - 6U < 3) << 0x1a |
             (in_stack_00000048 & 0x33ff) << 0x10 | local_88;
LAB_000afb10:
  if (param_3[1] <= uVar2) {
    pvVar6 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
    if ((void *)param_3[2] != (void *)0x0) {
      _memcpy(pvVar6,(void *)param_3[2],*param_3 << 2);
      (**(code **)(param_1 + 0x18))(param_3[2]);
    }
    param_3[2] = (uint)pvVar6;
    uVar2 = *param_3;
    param_3[1] = param_3[1] + 0x80;
  }
  *(uint *)(uVar2 * 4 + param_3[2]) = local_88;
  uVar2 = *param_3 + 1;
  *param_3 = uVar2;
  if (param_4 != 0xb) {
    if (param_3[1] <= uVar2) {
      pvVar6 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar6,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar6;
      uVar2 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    *(uint *)(uVar2 * 4 + param_3[2]) = uVar12 | 0x400000;
    uVar12 = *param_3 + 1;
    *param_3 = uVar12;
    if (param_3[1] <= uVar12) {
      pvVar6 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar6,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar6;
      uVar12 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    *(uint *)(uVar12 * 4 + param_3[2]) =
         (param_6 >> 3 & 1) << 6 |
         (param_6 >> 2 & 1) << 4 | (param_6 >> 1 & 1) << 2 | param_6 & 1 | uVar13;
    uVar2 = *param_3 + 1;
    *param_3 = uVar2;
  }
  if (iVar8 != 0) {
    puVar15 = &local_84;
    iVar11 = 0;
    iVar14 = 0;
    do {
      uVar3 = *(undefined4 *)((int)&local_84 + iVar14);
      if (param_3[1] <= uVar2) {
        pvVar6 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
        if ((void *)param_3[2] != (void *)0x0) {
          _memcpy(pvVar6,(void *)param_3[2],*param_3 << 2);
          (**(code **)(param_1 + 0x18))(param_3[2]);
        }
        param_3[2] = (uint)pvVar6;
        uVar2 = *param_3;
        param_3[1] = param_3[1] + 0x80;
      }
      *(undefined4 *)(uVar2 * 4 + param_3[2]) = uVar3;
      uVar2 = *param_3 + 1;
      *param_3 = uVar2;
      if ((*puVar15 & 0x400000) != 0) {
        uVar3 = *(undefined4 *)((int)local_7c + iVar14);
        if (param_3[1] <= uVar2) {
          pvVar6 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
          if ((void *)param_3[2] != (void *)0x0) {
            _memcpy(pvVar6,(void *)param_3[2],*param_3 << 2);
            (**(code **)(param_1 + 0x18))(param_3[2]);
          }
          param_3[2] = (uint)pvVar6;
          uVar2 = *param_3;
          param_3[1] = param_3[1] + 0x80;
        }
        *(undefined4 *)(uVar2 * 4 + param_3[2]) = uVar3;
        uVar2 = *param_3 + 1;
        *param_3 = uVar2;
      }
      iVar11 = iVar11 + 1;
      puVar15 = puVar15 + 1;
      iVar14 = iVar14 + 4;
    } while (iVar8 != iVar11);
  }
  if (uVar10 == 0x17) {
    ((int (*)())FUN_000ac540)(param_1,param_3,*(undefined4 *)(param_2 + 0x88),*param_5);
  }
  return;
}

/* FUN_000afe40 @ 0xafe40 (5932 bytes) */
int FUN_000afe40(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  void *pvVar5;
  size_t sVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  char *pcVar10;
  int iVar11;
  uint uVar12;
  char *pcVar13;
  undefined4 uVar14;
  int iVar15;
  code *pcVar16;
  uint uVar17;
  undefined4 uVar18;
  int iVar19;
  uint uVar20;
  int iVar21;
  undefined4 uVar22;
  char *pcVar23;
  int iVar24;
  char local_208 [4];
  undefined1 auStack_204 [8];
  undefined1 auStack_1fc [8];
  undefined1 auStack_1f4 [8];
  uint local_1ec;
  uint local_1e8;
  void *local_1e4;
  undefined4 local_1e0;
  undefined4 local_1dc;
  undefined4 local_1d8;
  undefined4 local_1d0;
  undefined4 local_1cc;
  undefined4 local_1c8;
  undefined4 local_1c4;
  undefined4 local_1c0;
  undefined4 local_1bc;
  undefined4 local_1b8;
  undefined4 local_1b4;
  undefined4 local_1b0;
  undefined4 local_1ac;
  undefined4 local_1a8;
  undefined4 local_1a4;
  undefined4 local_1a0;
  undefined4 local_19c;
  undefined4 local_198;
  undefined4 local_194;
  undefined4 local_190;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined4 local_17c;
  undefined4 local_178;
  undefined4 local_174;
  char acStack_170 [264];
  int local_68;
  undefined1 *local_64;
  char *local_60;
  uint *local_5c;
  
  iVar11 = *(int *)(((unsigned char *)0x0000121c) + param_1);
  pcVar23 = *(char **)(iVar11 + 0x74);
  if (pcVar23[0x54] == '\0') {
    iVar11 = *(int *)(*(int *)(((unsigned char *)0x00001220) + param_1) * 0x18 +
                      *(int *)(*(int *)(((unsigned char *)0x0000112c) + param_1) + 8) + 0x14);
    pcVar23 = *(char **)(iVar11 + 0x74);
  }
  uVar12 = *(uint *)(iVar11 + 0x70);
  iVar15 = *(int *)(((unsigned char *)0x00001130) + param_1) * 4;
  pcVar10 = *(char **)(iVar15 + uVar12);
  if (pcVar10 == (char *)0x0) {
    pcVar16 = *(code **)(param_1 + 0x10);
    uVar4 = (**(code **)(((unsigned char *)0x00001284) + param_1))();
    uVar4 = (*pcVar16)(1,uVar4);
    *(undefined4 *)(iVar15 + uVar12) = uVar4;
  }
  else {
    if ((param_2 != 1) && (pcVar10[0x119] == '\0')) goto LAB_000b0028;
    *(undefined4 *)(iVar15 + uVar12) = 0;
    (**(code **)(((unsigned char *)0x00001224) + param_1))(param_1,pcVar10);
    pcVar16 = *(code **)(param_1 + 0x10);
    iVar15 = *(int *)(((unsigned char *)0x00001130) + param_1);
    uVar12 = *(uint *)(iVar11 + 0x70);
    uVar4 = (**(code **)(((unsigned char *)0x00001284) + param_1))(param_1);
    uVar4 = (*pcVar16)(1,uVar4);
    *(undefined4 *)(iVar15 * 4 + uVar12) = uVar4;
  }
  pcVar10 = *(char **)(*(int *)(((unsigned char *)0x00001130) + param_1) * 4 + *(int *)(iVar11 + 0x70));
  *pcVar10 = '\0';
  if (pcVar23[0x55] == '\0') {
    local_1e4 = (void *)0x0;
    local_1ec = 0;
    local_1e8 = 0;
    pvVar5 = (void *)(**(code **)(param_1 + 0xc))(0x200);
    if (local_1e4 != (void *)0x0) {
      _memcpy(pvVar5,local_1e4,local_1ec << 2);
      (**(code **)(param_1 + 0x18))(local_1e4);
    }
    local_1e8 = local_1e8 + 0x80;
    *(undefined4 *)((int)pvVar5 + local_1ec * 4) = 1;
    local_1ec = local_1ec + 1;
    local_1e4 = pvVar5;
    if (local_1e8 <= local_1ec) {
      pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
      if (local_1e4 != (void *)0x0) {
        _memcpy(pvVar5,local_1e4,local_1ec << 2);
        (**(code **)(param_1 + 0x18))(local_1e4);
      }
      local_1e8 = local_1e8 + 0x80;
      local_1e4 = pvVar5;
    }
    *(undefined4 *)(local_1ec * 4 + (int)local_1e4) = 0x10200;
    local_1ec = local_1ec + 1;
    if (local_1e8 <= local_1ec) {
      pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
      if (local_1e4 != (void *)0x0) {
        _memcpy(pvVar5,local_1e4,local_1ec << 2);
        (**(code **)(param_1 + 0x18))(local_1e4);
      }
      local_1e8 = local_1e8 + 0x80;
      local_1e4 = pvVar5;
    }
    *(undefined4 *)(local_1ec * 4 + (int)local_1e4) = 0x1ff0016;
    local_1ec = local_1ec + 1;
    if (local_1e8 <= local_1ec) {
      pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
      if (local_1e4 != (void *)0x0) {
        _memcpy(pvVar5,local_1e4,local_1ec << 2);
        (**(code **)(param_1 + 0x18))(local_1e4);
      }
      local_1e8 = local_1e8 + 0x80;
      local_1e4 = pvVar5;
    }
    *(undefined4 *)(local_1ec * 4 + (int)local_1e4) = 0x120000;
    local_1ec = local_1ec + 1;
    if (*pcVar23 != '\0') {
      if (local_1e8 <= local_1ec) {
        pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
        if (local_1e4 != (void *)0x0) {
          _memcpy(pvVar5,local_1e4,local_1ec << 2);
          (**(code **)(param_1 + 0x18))(local_1e4);
        }
        local_1e8 = local_1e8 + 0x80;
        local_1e4 = pvVar5;
      }
      *(undefined4 *)(local_1ec * 4 + (int)local_1e4) = 0x1ff0016;
      local_1ec = local_1ec + 1;
      if (local_1e8 <= local_1ec) {
        pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
        if (local_1e4 != (void *)0x0) {
          _memcpy(pvVar5,local_1e4,local_1ec << 2);
          (**(code **)(param_1 + 0x18))(local_1e4);
        }
        local_1e8 = local_1e8 + 0x80;
        local_1e4 = pvVar5;
      }
      *(undefined4 *)(local_1ec * 4 + (int)local_1e4) = 0x130000;
      local_1ec = local_1ec + 1;
    }
    if (pcVar23[1] != '\0') {
      if (local_1e8 <= local_1ec) {
        pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
        if (local_1e4 != (void *)0x0) {
          _memcpy(pvVar5,local_1e4,local_1ec << 2);
          (**(code **)(param_1 + 0x18))(local_1e4);
        }
        local_1e8 = local_1e8 + 0x80;
        local_1e4 = pvVar5;
      }
      *(undefined4 *)(local_1ec * 4 + (int)local_1e4) = 0x1ff0016;
      local_1ec = local_1ec + 1;
      if (local_1e8 <= local_1ec) {
        pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
        if (local_1e4 != (void *)0x0) {
          _memcpy(pvVar5,local_1e4,local_1ec << 2);
          (**(code **)(param_1 + 0x18))(local_1e4);
        }
        local_1e8 = local_1e8 + 0x80;
        local_1e4 = pvVar5;
      }
      *(undefined4 *)(local_1ec * 4 + (int)local_1e4) = 0x100000;
      local_1ec = local_1ec + 1;
    }
    if (pcVar23[2] != '\0') {
      uVar12 = 0x3ff0016;
      if (local_1e8 <= local_1ec) {
        pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
        if (local_1e4 != (void *)0x0) {
          _memcpy(pvVar5,local_1e4,local_1ec << 2);
          (**(code **)(param_1 + 0x18))(local_1e4);
        }
        local_1e8 = local_1e8 + 0x80;
        local_1e4 = pvVar5;
      }
      *(undefined4 *)(local_1ec * 4 + (int)local_1e4) = 0x3ff0016;
      local_1ec = local_1ec + 1;
      if (local_1e8 <= local_1ec) {
        pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
        if (local_1e4 != (void *)0x0) {
          _memcpy(pvVar5,local_1e4,local_1ec << 2);
          (**(code **)(param_1 + 0x18))(local_1e4);
        }
        local_1e8 = local_1e8 + 0x80;
        local_1e4 = pvVar5;
      }
      *(undefined4 *)(local_1ec * 4 + (int)local_1e4) = 0x160000;
      local_1ec = local_1ec + 1;
    }
    uVar7 = local_1ec;
    if (((unsigned char *)0x000013b1)[param_1] != '\0') {
      uVar20 = 0;
      pcVar13 = pcVar23;
      do {
        uVar17 = 1 << (uVar20 & 0x3f);
        if ((uVar17 & *(uint *)(pcVar23 + 0x10)) != 0) {
          switch(*(undefined4 *)(pcVar13 + 0x14)) {
          case 0:
            uVar12 = uVar20 << 0x10 | 0x8000019;
            break;
          case 1:
          case 6:
            uVar12 = uVar20 << 0x10 | 0x9000019;
            break;
          case 2:
          case 7:
            uVar12 = uVar20 << 0x10 | 0xa000019;
            break;
          case 3:
            uVar12 = uVar20 << 0x10 | 0xb000019;
            break;
          case 4:
            uVar12 = uVar20 << 0x10 | 0xc000019;
            break;
          case 5:
          case 8:
            uVar12 = uVar20 << 0x10 | 0x12000019;
          }
          if (local_1e8 <= uVar7) {
            pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
            if (local_1e4 != (void *)0x0) {
              _memcpy(pvVar5,local_1e4,local_1ec << 2);
              (**(code **)(param_1 + 0x18))(local_1e4);
            }
            local_1e8 = local_1e8 + 0x80;
            uVar7 = local_1ec;
            local_1e4 = pvVar5;
          }
          *(uint *)(uVar7 * 4 + (int)local_1e4) = uVar12;
          uVar7 = local_1ec + 1;
          local_1ec = uVar7;
        }
        if (((int)uVar20 < (int)(uint)(byte)((unsigned char *)0x000013b0)[param_1]) &&
           ((uVar17 & *(uint *)(pcVar23 + 0xc)) != 0)) {
          if (local_1e8 <= uVar7) {
            pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
            if (local_1e4 != (void *)0x0) {
              _memcpy(pvVar5,local_1e4,local_1ec << 2);
              (**(code **)(param_1 + 0x18))(local_1e4);
            }
            local_1e8 = local_1e8 + 0x80;
            uVar7 = local_1ec;
            local_1e4 = pvVar5;
          }
          *(undefined4 *)(uVar7 * 4 + (int)local_1e4) = 0x1ff0016;
          local_1ec = local_1ec + 1;
          if (local_1e8 <= local_1ec) {
            pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
            if (local_1e4 != (void *)0x0) {
              _memcpy(pvVar5,local_1e4,local_1ec << 2);
              (**(code **)(param_1 + 0x18))(local_1e4);
            }
            local_1e8 = local_1e8 + 0x80;
            local_1e4 = pvVar5;
          }
          *(uint *)(local_1ec * 4 + (int)local_1e4) = uVar20 & 0xffff | 0x110000;
          uVar7 = local_1ec + 1;
          local_1ec = uVar7;
        }
        uVar20 = uVar20 + 1;
        pcVar13 = pcVar13 + 4;
      } while ((int)uVar20 < (int)(uint)(byte)((unsigned char *)0x000013b1)[param_1]);
    }
    iVar15 = *(int *)(pcVar23 + 0x84);
    uVar12 = 0x10000;
    if (0 < iVar15) {
      iVar19 = 0;
      iVar24 = 0;
      do {
        iVar21 = iVar24 + *(int *)(pcVar23 + 0x80);
        if (*(int *)(iVar21 + 8) == 0x34) {
          uVar12 = *(uint *)(iVar21 + 4) & 0xffff | uVar12 & 0xffff0000;
          if (local_1e8 <= uVar7) {
            pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
            if (local_1e4 != (void *)0x0) {
              _memcpy(pvVar5,local_1e4,local_1ec << 2);
              (**(code **)(param_1 + 0x18))(local_1e4);
            }
            local_1e8 = local_1e8 + 0x80;
            uVar7 = local_1ec;
            local_1e4 = pvVar5;
          }
          *(undefined4 *)(uVar7 * 4 + (int)local_1e4) = 0x1c;
          local_1ec = local_1ec + 1;
          if (local_1e8 <= local_1ec) {
            pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
            if (local_1e4 != (void *)0x0) {
              _memcpy(pvVar5,local_1e4,local_1ec << 2);
              (**(code **)(param_1 + 0x18))(local_1e4);
            }
            local_1e8 = local_1e8 + 0x80;
            local_1e4 = pvVar5;
          }
          *(uint *)(local_1ec * 4 + (int)local_1e4) = uVar12;
          local_1ec = local_1ec + 1;
          uVar4 = *(undefined4 *)(*(int *)(iVar21 + 0xc) * 0x10 + *(int *)(pcVar23 + 0x8c));
          if (local_1e8 <= local_1ec) {
            pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
            if (local_1e4 != (void *)0x0) {
              _memcpy(pvVar5,local_1e4,local_1ec << 2);
              (**(code **)(param_1 + 0x18))(local_1e4);
            }
            local_1e8 = local_1e8 + 0x80;
            local_1e4 = pvVar5;
          }
          *(undefined4 *)(local_1ec * 4 + (int)local_1e4) = uVar4;
          local_1ec = local_1ec + 1;
          uVar4 = *(undefined4 *)(*(int *)(iVar21 + 0xc) * 0x10 + *(int *)(pcVar23 + 0x8c) + 4);
          if (local_1e8 <= local_1ec) {
            pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
            if (local_1e4 != (void *)0x0) {
              _memcpy(pvVar5,local_1e4,local_1ec << 2);
              (**(code **)(param_1 + 0x18))(local_1e4);
            }
            local_1e8 = local_1e8 + 0x80;
            local_1e4 = pvVar5;
          }
          *(undefined4 *)(local_1ec * 4 + (int)local_1e4) = uVar4;
          local_1ec = local_1ec + 1;
          uVar4 = *(undefined4 *)(*(int *)(iVar21 + 0xc) * 0x10 + *(int *)(pcVar23 + 0x8c) + 8);
          if (local_1e8 <= local_1ec) {
            pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
            if (local_1e4 != (void *)0x0) {
              _memcpy(pvVar5,local_1e4,local_1ec << 2);
              (**(code **)(param_1 + 0x18))(local_1e4);
            }
            local_1e8 = local_1e8 + 0x80;
            local_1e4 = pvVar5;
          }
          *(undefined4 *)(local_1ec * 4 + (int)local_1e4) = uVar4;
          local_1ec = local_1ec + 1;
          uVar4 = *(undefined4 *)(*(int *)(iVar21 + 0xc) * 0x10 + *(int *)(pcVar23 + 0x8c) + 0xc);
          if (local_1e8 <= local_1ec) {
            pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
            if (local_1e4 != (void *)0x0) {
              _memcpy(pvVar5,local_1e4,local_1ec << 2);
              (**(code **)(param_1 + 0x18))(local_1e4);
            }
            local_1e8 = local_1e8 + 0x80;
            local_1e4 = pvVar5;
          }
          *(undefined4 *)(local_1ec * 4 + (int)local_1e4) = uVar4;
          uVar7 = local_1ec + 1;
          iVar15 = *(int *)(pcVar23 + 0x84);
          local_1ec = uVar7;
        }
        iVar19 = iVar19 + 1;
        iVar24 = iVar24 + 0x14;
      } while (iVar19 < iVar15);
    }
    if (**(int **)(pcVar23 + 100) == 0x41) {
      local_5c = &local_1ec;
LAB_000b10a0:
      if (local_1e8 <= uVar7) {
        pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
        if (local_1e4 != (void *)0x0) {
          _memcpy(pvVar5,local_1e4,local_1ec << 2);
          (**(code **)(param_1 + 0x18))(local_1e4);
        }
        local_1e8 = local_1e8 + 0x80;
        uVar7 = local_1ec;
        local_1e4 = pvVar5;
      }
      *(undefined4 *)(uVar7 * 4 + (int)local_1e4) = 0x47;
      local_1ec = local_1ec + 1;
      if (local_1e8 <= local_1ec) {
        pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
        if (local_1e4 != (void *)0x0) {
          _memcpy(pvVar5,local_1e4,local_1ec << 2);
          (**(code **)(param_1 + 0x18))(local_1e4);
        }
        local_1e8 = local_1e8 + 0x80;
        local_1e4 = pvVar5;
      }
      *(undefined4 *)(local_1ec * 4 + (int)local_1e4) = 0x570000;
      local_1ec = local_1ec + 1;
      if (local_1e8 <= local_1ec) {
        pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
        if (local_1e4 != (void *)0x0) {
          _memcpy(pvVar5,local_1e4,local_1ec << 2);
          (**(code **)(param_1 + 0x18))(local_1e4);
        }
        local_1e8 = local_1e8 + 0x80;
        local_1e4 = pvVar5;
      }
      *(undefined4 *)(local_1ec * 4 + (int)local_1e4) = 0;
      local_1ec = local_1ec + 1;
      if (local_1e8 <= local_1ec) {
        pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
        if (local_1e4 != (void *)0x0) {
          _memcpy(pvVar5,local_1e4,local_1ec << 2);
          (**(code **)(param_1 + 0x18))(local_1e4);
        }
        local_1e8 = local_1e8 + 0x80;
        local_1e4 = pvVar5;
      }
      *(undefined4 *)(local_1ec * 4 + (int)local_1e4) = 0x40000;
      local_1ec = local_1ec + 1;
    }
    else {
      local_5c = &local_1ec;
      iVar15 = 0;
      local_68 = 0;
      local_64 = auStack_1f4;
      local_60 = acStack_170;
      iVar24 = 0;
      do {
        local_208[0] = '\0';
        iVar19 = iVar24 + *(int *)(pcVar23 + 100);
        uVar12 = *(uint *)(iVar24 + *(int *)(pcVar23 + 100));
        local_1e0 = *(undefined4 *)(iVar19 + 4);
        local_1dc = *(undefined4 *)(iVar19 + 8);
        uVar22 = *(undefined4 *)(iVar19 + 0xc);
        local_190 = *(undefined4 *)(iVar19 + 0x10);
        local_18c = *(undefined4 *)(iVar19 + 0x14);
        local_188 = *(undefined4 *)(iVar19 + 0x18);
        local_184 = *(undefined4 *)(iVar19 + 0x1c);
        local_180 = *(undefined4 *)(iVar19 + 0x20);
        local_17c = *(undefined4 *)(iVar19 + 0x24);
        uVar8 = *(undefined4 *)(iVar19 + 0x28);
        local_174 = *(undefined4 *)(iVar19 + 0x2c);
        local_1b0 = *(undefined4 *)(iVar19 + 0x30);
        local_1ac = *(undefined4 *)(iVar19 + 0x34);
        local_1a8 = *(undefined4 *)(iVar19 + 0x38);
        local_1a4 = *(undefined4 *)(iVar19 + 0x3c);
        (*(unsigned char *)((unsigned char *)&(local_178) + 0)) = (undefined1)((uint)uVar8 >> 0x18);
        uVar3 = (*(unsigned char *)((unsigned char *)&(local_178) + 0));
        local_1a0 = *(undefined4 *)(iVar19 + 0x40);
        local_19c = *(undefined4 *)(iVar19 + 0x44);
        uVar9 = *(undefined4 *)(iVar19 + 0x48);
        uVar18 = *(undefined4 *)(iVar19 + 0x4c);
        local_1d0 = *(undefined4 *)(iVar19 + 0x50);
        local_1cc = *(undefined4 *)(iVar19 + 0x54);
        local_1c8 = *(undefined4 *)(iVar19 + 0x58);
        local_1c4 = *(undefined4 *)(iVar19 + 0x5c);
        (*(unsigned char *)((unsigned char *)&(local_198) + 0)) = (undefined1)((uint)uVar9 >> 0x18);
        uVar2 = (*(unsigned char *)((unsigned char *)&(local_198) + 0));
        uVar4 = *(undefined4 *)(iVar19 + 0x68);
        uVar14 = *(undefined4 *)(iVar19 + 0x6c);
        local_1c0 = *(undefined4 *)(iVar19 + 0x60);
        local_1bc = *(undefined4 *)(iVar19 + 100);
        (*(unsigned char *)((unsigned char *)&(local_1b8) + 0)) = (undefined1)((uint)uVar4 >> 0x18);
        uVar1 = (*(unsigned char *)((unsigned char *)&(local_1b8) + 0));
        local_1d8 = uVar22;
        local_1b8 = uVar4;
        local_1b4 = uVar14;
        local_198 = uVar9;
        local_194 = uVar18;
        local_178 = uVar8;
        if (uVar12 < 0x20) {
          if ((0x1c < uVar12) || (uVar12 == 0xb)) goto LAB_000b0fbc;
LAB_000b0e20:
          ((int (*)())FUN_000ab940)(local_1e0,local_1dc,uVar22,auStack_204,local_208,
                       *(undefined1 *)(*(int *)(pcVar23 + 0x94) + iVar15));
          local_178 = CONCAT13(uVar3,(*(unsigned int *)((unsigned char *)&(local_178) + 1)));
          ((int (*)())FUN_000ab9b0)(local_190,local_18c,local_188,local_184,local_180,local_17c,local_178,
                       local_174);
          local_198 = CONCAT13(uVar2,(*(unsigned int *)((unsigned char *)&(local_198) + 1)));
          local_194 = uVar18;
          ((int (*)())FUN_000ab9b0)(local_1b0,local_1ac,local_1a8,local_1a4,local_1a0,local_19c,local_198,uVar18)
          ;
          local_1b8 = CONCAT13(uVar1,(*(unsigned int *)((unsigned char *)&(local_1b8) + 1)));
          local_1b4 = uVar14;
          ((int (*)())FUN_000ab9b0)(local_1d0,local_1cc,local_1c8,local_1c4,local_1c0,local_1bc,local_1b8,uVar14)
          ;
          ((int (*)())FUN_000ac720)(param_1,pcVar23,local_5c,uVar12,auStack_204,uVar22,local_64,auStack_1fc);
        }
        else {
          if (2 < uVar12 - 0x3d) goto LAB_000b0e20;
LAB_000b0fbc:
          ((int (*)())FUN_000ab940)(local_1e0,local_1dc,uVar22,auStack_1fc,local_208,0);
          local_178 = CONCAT13(uVar3,(*(unsigned int *)((unsigned char *)&(local_178) + 1)));
          ((int (*)())FUN_000ab9b0)(local_190,local_18c,local_188,local_184,local_180,local_17c,local_178,
                       local_174);
          ((int (*)())FUN_000aec40)(param_1,pcVar23,local_5c,uVar12,auStack_1fc,uVar22,auStack_204,local_188);
        }
        if (local_208[0] != '\0') {
          local_68 = 1;
        }
        iVar24 = iVar24 + 0x70;
        iVar15 = iVar15 + 1;
      } while (*(int *)(*(int *)(pcVar23 + 100) + iVar24) != 0x41);
      uVar7 = local_1ec;
      if (local_68 == 0) goto LAB_000b10a0;
    }
    if (local_1e8 <= local_1ec) {
      pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
      if (local_1e4 != (void *)0x0) {
        _memcpy(pvVar5,local_1e4,local_1ec << 2);
        (**(code **)(param_1 + 0x18))(local_1e4);
      }
      local_1e8 = local_1e8 + 0x80;
      local_1e4 = pvVar5;
    }
    *(undefined4 *)(local_1ec * 4 + (int)local_1e4) = 0x28;
    local_1ec = local_1ec + 1;
    iVar15 = (**(code **)(((unsigned char *)0x00001288) + param_1))(param_1,iVar11,pcVar10,local_5c);
    if (iVar15 < 0) {
      iVar24 = *(int *)(((unsigned char *)0x00001130) + param_1);
      iVar19 = *(int *)(iVar11 + 0x70);
      uVar4 = *(undefined4 *)(iVar24 * 4 + iVar19);
      if (iVar15 == -1) {
        FUN_001a32d0(acStack_170,
                     "Fragment program exceeded native resources:\n  Temporaries          - %d\n  Parameters           - %d\n  Attributes           - %d\n  ALU instructions     - %d\n  Texture instructions - %d\n  Texture indirections - %d\n"
                     ,*(undefined4 *)(iVar11 + 0x68),*(undefined4 *)(iVar11 + 100),
                     *(undefined4 *)(iVar11 + 0x60),*(undefined4 *)(iVar11 + 0x54),
                     *(undefined4 *)(iVar11 + 0x58),*(undefined4 *)(iVar11 + 0x5c));
        if (*(int *)(((unsigned char *)0x00001128) + param_1) != 0) {
          (**(code **)(param_1 + 0x18))();
        }
        sVar6 = _strlen(acStack_170);
        pcVar23 = (char *)(**(code **)(param_1 + 0xc))(sVar6 + 1);
        *(char **)(((unsigned char *)0x00001128) + param_1) = pcVar23;
        _strcpy(pcVar23,acStack_170);
        iVar24 = *(int *)(((unsigned char *)0x00001130) + param_1);
        iVar19 = *(int *)(iVar11 + 0x70);
      }
      *(undefined4 *)(iVar24 * 4 + iVar19) = 0;
LAB_000b1448:
      (**(code **)(((unsigned char *)0x00001224) + param_1))(param_1,uVar4);
      return 0;
    }
  }
  else {
    iVar15 = ((int (*)())FUN_000abd10)(param_1,iVar11,acStack_170);
    if (iVar15 == 0) {
      if (*(int *)(((unsigned char *)0x00001128) + param_1) != 0) {
        (**(code **)(param_1 + 0x18))();
      }
      pvVar5 = (void *)(**(code **)(param_1 + 0xc))(0x22);
      *(void **)(((unsigned char *)0x00001128) + param_1) = pvVar5;
      _memcpy(pvVar5,"program had bad or unsupported IL",0x22);
      return 0;
    }
    iVar15 = (**(code **)(((unsigned char *)0x00001288) + param_1))(param_1,iVar11,pcVar10,acStack_170);
    if (iVar15 == -1) {
      *(undefined1 *)(iVar11 + 0x6c) = 0;
    }
    else {
      if (iVar15 == -2) {
        uVar4 = *(undefined4 *)(*(int *)(((unsigned char *)0x00001130) + param_1) * 4 + *(int *)(iVar11 + 0x70));
        *(undefined4 *)(*(int *)(((unsigned char *)0x00001130) + param_1) * 4 + *(int *)(iVar11 + 0x70)) = 0;
        goto LAB_000b1448;
      }
      *(undefined1 *)(iVar11 + 0x6c) = 1;
    }
  }
  pcVar10[0x119] = '\0';
LAB_000b0028:
  ((unsigned char *)0x000011d0)[param_1] = 0;
  if (pcVar23[0x55] == '\0') {
    iVar24 = *(int *)(iVar11 + 0x74);
    iVar15 = 0;
    if (0 < *(int *)(iVar24 + 0x84)) {
      do {
        iVar19 = iVar15 * 0x14 + *(int *)(iVar24 + 0x80);
        if (*(int *)(iVar19 + 8) == 0x34) {
          if (*pcVar10 == '\0') {
            (**(code **)(((unsigned char *)0x00001280) + param_1))
                      (param_1,pcVar10,iVar15,*(undefined4 *)(iVar19 + 4),
                       *(int *)(iVar19 + 0xc) * 0x10 + *(int *)(iVar24 + 0x8c),1,1);
            iVar24 = *(int *)(iVar11 + 0x74);
          }
        }
        else {
          FUN_0008ebb0(param_1,iVar19,&local_1e0);
          (**(code **)(((unsigned char *)0x00001280) + param_1))
                    (param_1,pcVar10,iVar15,*(undefined4 *)(iVar19 + 4),&local_1e0,1,1);
          iVar24 = *(int *)(iVar11 + 0x74);
        }
        iVar15 = iVar15 + 1;
      } while (iVar15 < *(int *)(iVar24 + 0x84));
    }
  }
  else {
    ((int (*)())FUN_000abab0)(param_1,iVar11,pcVar10);
  }
  if (((*(uint *)(param_1 + 0x44) & 0x2000) != 0) && (*(char *)(iVar11 + 0x6c) != '\0')) {
    (**(code **)(((unsigned char *)0x00001290) + param_1))(param_1,pcVar10);
  }
  return 1;
}

/* FUN_000b15d0 @ 0xb15d0 (180 bytes) */
int FUN_000b15d0(param_1, param_2, param_3)
  int param_1;
  uint *param_2;
  undefined4 param_3;
{
  void *pvVar1;
  uint uVar2;
  
  uVar2 = *param_2;
  if (param_2[1] <= uVar2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar2 * 4 + param_2[2]) = param_3;
  *param_2 = *param_2 + 1;
  return;
}

/* FUN_000b1690 @ 0xb1690 (476 bytes) */
int FUN_000b1690(param_1, param_2)
  int param_1;
  uint *param_2;
{
  void *pvVar1;
  uint uVar2;
  
  uVar2 = *param_2;
  if (param_2[1] <= uVar2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar2 * 4 + param_2[2]) = 0xe;
  uVar2 = *param_2 + 1;
  *param_2 = uVar2;
  if (param_2[1] <= uVar2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar2 * 4 + param_2[2]) = 0x170000;
  uVar2 = *param_2 + 1;
  *param_2 = uVar2;
  if (param_2[1] <= uVar2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar2 * 4 + param_2[2]) = 0x40000;
  *param_2 = *param_2 + 1;
  return;
}

/* FUN_000b1870 @ 0xb1870 (800 bytes) */
int FUN_000b1870(param_1, param_2)
  int param_1;
  uint *param_2;
{
  void *pvVar1;
  uint uVar2;
  
  uVar2 = *param_2;
  if (param_2[1] <= uVar2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar2 * 4 + param_2[2]) = 3;
  uVar2 = *param_2 + 1;
  *param_2 = uVar2;
  if (param_2[1] <= uVar2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar2 * 4 + param_2[2]) = 0x40000;
  uVar2 = *param_2 + 1;
  *param_2 = uVar2;
  if (param_2[1] <= uVar2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar2 * 4 + param_2[2]) = 0x40000;
  uVar2 = *param_2 + 1;
  *param_2 = uVar2;
  if (param_2[1] <= uVar2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar2 * 4 + param_2[2]) = 0x530000;
  uVar2 = *param_2 + 1;
  *param_2 = uVar2;
  if (param_2[1] <= uVar2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined **)(uVar2 * 4 + param_2[2]) = ((unsigned char *)0x00004210);
  *param_2 = *param_2 + 1;
  return;
}

/* FUN_000b1b90 @ 0xb1b90 (748 bytes) */
int FUN_000b1b90(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint *param_2;
  int param_3;
  uint param_4;
  uint param_5;
{
  void *pvVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *param_2;
  if (param_2[1] <= uVar2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar2 * 4 + param_2[2]) = 0x47;
  uVar3 = 0;
  uVar2 = *param_2 + 1;
  *param_2 = uVar2;
  if ((param_5 & 7) == 0) {
    uVar3 = 0x15;
  }
  if ((param_5 & 1) != 0) {
    uVar3 = uVar3 & 0xfffffffc | 1;
  }
  if ((param_5 & 2) != 0) {
    uVar3 = uVar3 & 0xfffffff3 | 4;
  }
  if ((param_5 & 4) != 0) {
    uVar3 = uVar3 & 0xffffffcf | 0x10;
  }
  if ((param_5 & 8) != 0) {
    uVar3 = uVar3 | 0x40;
  }
  if (param_2[1] <= uVar2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(uint *)(uVar2 * 4 + param_2[2]) = param_3 + 0x76dfU & 0xffff | 0x440000;
  uVar2 = *param_2 + 1;
  *param_2 = uVar2;
  if (param_2[1] <= uVar2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(uint *)(uVar2 * 4 + param_2[2]) = uVar3;
  uVar2 = *param_2 + 1;
  *param_2 = uVar2;
  if (param_2[1] <= uVar2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(uint *)(uVar2 * 4 + param_2[2]) = param_4 & 0xffff | 0x40000;
  *param_2 = *param_2 + 1;
  return;
}

/* FUN_000b1e80 @ 0xb1e80 (932 bytes) */
int FUN_000b1e80(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  uint *param_2;
  uint *param_3;
  undefined4 param_4;
  undefined4 param_5;
  int param_6;
{
  uint uVar1;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined *puVar6;
  
  uVar5 = 0;
  puVar6 = (undefined *)0x0;
  uVar4 = *param_3;
  if ((uVar4 - 0x8921 < 6) && (*(char *)(uVar4 + param_6 + -0x8921) == '\0')) {
    uVar4 = 0;
    *param_3 = 0;
LAB_000b1f80:
    uVar5 = 0x410000;
    puVar6 = ((unsigned char *)0x00004444);
  }
  else if (uVar4 < 0x8927) {
    if (uVar4 < 0x8921) {
      if (uVar4 == 1) {
        uVar5 = 0x410000;
        puVar6 = ((unsigned char *)0x00005555);
      }
      else {
        if (uVar4 == 0) goto LAB_000b1f80;
        if (uVar4 == 0x8577) {
          uVar5 = 0x120000;
        }
      }
    }
    else {
      uVar5 = uVar4 + 0x76df & 0xffff | 0x40000;
    }
  }
  else if (0x8940 < uVar4) {
    if (uVar4 < 0x8949) {
      uVar5 = uVar4 + 0x76bf & 0xffff | 0x10000;
    }
    else if (uVar4 == 0x896d) {
      uVar5 = 0x130000;
    }
  }
  uVar1 = param_3[3];
  if (uVar1 == 0) {
    uVar3 = param_3[2];
    if (uVar3 == 0) goto LAB_000b2028;
  }
  else {
    uVar3 = param_3[2];
  }
  uVar5 = uVar5 | 0x400000;
LAB_000b2028:
  if ((uVar3 & 1) != 0) {
    puVar6 = (undefined *)((uint)puVar6 | 0x40000);
  }
  if ((uVar3 & 2) != 0) {
    puVar6 = (undefined *)((uint)puVar6 | 0x10000);
  }
  if ((uVar3 & 4) != 0) {
    puVar6 = (undefined *)((uint)puVar6 | 0x8888);
  }
  if ((uVar3 & 8) != 0) {
    puVar6 = (undefined *)((uint)puVar6 | 0x20000);
  }
  if (1 < uVar4) {
    if (uVar1 == 0x1904) {
      puVar6 = (undefined *)((uint)puVar6 & 0xffff8888 | 0x1111);
    }
    else if (uVar1 < 0x1905) {
      if (uVar1 == 0) {
        puVar6 = (undefined *)((uint)puVar6 & 0xffff8888 | 0x3210);
      }
      else if (uVar1 == 0x1903) {
        puVar6 = (undefined *)((uint)puVar6 & 0xffff8888);
      }
    }
    else if (uVar1 == 0x1905) {
      puVar6 = (undefined *)((uint)puVar6 & 0xffff8888 | 0x2222);
    }
    else if (uVar1 == 0x1906) {
      puVar6 = (undefined *)((uint)puVar6 & 0xffff8888 | 0x3333);
    }
  }
  uVar4 = *param_2;
  if (param_2[1] <= uVar4) {
    pvVar2 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar2,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar2;
    uVar4 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(uint *)(uVar4 * 4 + param_2[2]) = uVar5;
  uVar4 = *param_2 + 1;
  *param_2 = uVar4;
  if ((uVar5 & 0x400000) != 0) {
    if (param_2[1] <= uVar4) {
      pvVar2 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
      if ((void *)param_2[2] != (void *)0x0) {
        _memcpy(pvVar2,(void *)param_2[2],*param_2 << 2);
        (**(code **)(param_1 + 0x18))(param_2[2]);
      }
      param_2[2] = (uint)pvVar2;
      uVar4 = *param_2;
      param_2[1] = param_2[1] + 0x80;
    }
    *(undefined **)(uVar4 * 4 + param_2[2]) = puVar6;
    *param_2 = *param_2 + 1;
  }
  return 1;
}

/* FUN_000b2260 @ 0xb2260 (692 bytes) */
int FUN_000b2260(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  uint *param_2;
  uint *param_3;
  undefined4 param_4;
  int param_5;
  int param_6;
{
  uint uVar1;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = 0;
  uVar3 = *param_3;
  if (uVar3 - 0x8921 < 6) {
    *(undefined1 *)(uVar3 + param_6 + -0x8921) = 1;
    uVar3 = uVar3 + 0x76df;
  }
  uVar5 = uVar3 & 0xffff | 0x40000;
  if (param_5 != 0) {
    uVar1 = param_3[1];
    uVar4 = 0;
    if ((uVar1 & 7) == 0) {
      uVar5 = uVar3 & 0xffff | 0x440000;
      uVar4 = 0x15;
    }
    if ((uVar1 & 1) != 0) {
      uVar5 = uVar5 | 0x400000;
      uVar4 = uVar4 & 0xfffffffc | 1;
    }
    if ((uVar1 & 2) != 0) {
      uVar5 = uVar5 | 0x400000;
      uVar4 = uVar4 & 0xfffffff3 | 4;
    }
    if ((uVar1 & 4) != 0) {
      uVar5 = uVar5 | 0x400000;
      uVar4 = uVar4 & 0xffffffcf | 0x10;
    }
    if ((uVar1 & 8) == 0) goto LAB_000b2364;
  }
  uVar5 = uVar5 | 0x400000;
  uVar4 = uVar4 | 0x40;
LAB_000b2364:
  uVar3 = param_3[2];
  if (uVar3 != 0) {
    uVar5 = uVar5 | 0x400000;
    if ((uVar3 & 0x40) != 0) {
      uVar4 = uVar4 | 0x100;
    }
    switch(uVar3 & 0x3f) {
    case 1:
      uVar4 = uVar4 | 0x200;
      break;
    case 2:
      uVar4 = uVar4 | 0x400;
      break;
    case 4:
      uVar4 = uVar4 | 0x600;
      break;
    case 8:
      uVar4 = uVar4 | 0x800;
      break;
    case 0x10:
      uVar4 = uVar4 | 0xa00;
      break;
    case 0x20:
      uVar4 = uVar4 | 0xc00;
    }
  }
  uVar3 = *param_2;
  if (param_2[1] <= uVar3) {
    pvVar2 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar2,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar2;
    uVar3 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(uint *)(uVar3 * 4 + param_2[2]) = uVar5;
  uVar3 = *param_2 + 1;
  *param_2 = uVar3;
  if ((uVar5 & 0x400000) != 0) {
    if (param_2[1] <= uVar3) {
      pvVar2 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
      if ((void *)param_2[2] != (void *)0x0) {
        _memcpy(pvVar2,(void *)param_2[2],*param_2 << 2);
        (**(code **)(param_1 + 0x18))(param_2[2]);
      }
      param_2[2] = (uint)pvVar2;
      uVar3 = *param_2;
      param_2[1] = param_2[1] + 0x80;
    }
    *(uint *)(uVar3 * 4 + param_2[2]) = uVar4;
    *param_2 = *param_2 + 1;
  }
  return 1;
}

/* FUN_000b25a0 @ 0xb25a0 (2216 bytes) */
int FUN_000b25a0(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  uint *param_2;
  int param_3;
  int param_4;
  undefined4 param_5;
  int param_6;
{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined *puVar8;
  int iVar9;
  
  uVar4 = (uint)*(ushort *)(param_3 + 0x14);
  iVar5 = *(int *)(param_3 + 0x10);
  if (*(ushort *)(param_3 + 0x14) != 0) {
    uVar6 = 0;
    do {
      iVar9 = (uVar6 + uVar4 * param_4) * 0xc;
      iVar2 = iVar9 + *(int *)(iVar5 + 0xc);
      if (*(char *)(iVar9 + *(int *)(iVar5 + 0xc)) != '\0') {
        uVar7 = *(uint *)(iVar2 + 4);
        puVar8 = (undefined *)0x0;
        if (*(char *)(iVar2 + 1) == '\0') {
          if ((uVar7 == 0x8976) && (uVar6 == *(int *)(iVar2 + 8) - 0x8921U)) goto LAB_000b2c0c;
          uVar4 = *param_2;
          if (param_2[1] <= uVar4) {
            pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
            if ((void *)param_2[2] != (void *)0x0) {
              _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
              (**(code **)(param_1 + 0x18))(param_2[2]);
            }
            param_2[2] = (uint)pvVar1;
            uVar4 = *param_2;
            param_2[1] = param_2[1] + 0x80;
          }
          *(undefined4 *)(uVar4 * 4 + param_2[2]) = 0x47;
          uVar4 = *param_2 + 1;
          *param_2 = uVar4;
          if (param_2[1] <= uVar4) {
            pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
            if ((void *)param_2[2] != (void *)0x0) {
              _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
              (**(code **)(param_1 + 0x18))(param_2[2]);
            }
            param_2[2] = (uint)pvVar1;
            uVar4 = *param_2;
            param_2[1] = param_2[1] + 0x80;
          }
          *(uint *)(uVar4 * 4 + param_2[2]) = uVar6 + 6 & 0xffff | 0x40000;
          *param_2 = *param_2 + 1;
          *(undefined1 *)(param_6 + uVar6) = 1;
          iVar2 = *(int *)(iVar9 + *(int *)(iVar5 + 0xc) + 8);
          if (iVar2 - 0x84c0U < 6) {
            uVar4 = iVar2 + 0x7b40U & 0xffff | 0x110000;
          }
          else {
            uVar4 = iVar2 + 0x76dfU & 0xffff | 0x40000;
          }
          uVar3 = *param_2;
          if (param_2[1] <= uVar3) {
            pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
            if ((void *)param_2[2] != (void *)0x0) {
              _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
              (**(code **)(param_1 + 0x18))(param_2[2]);
            }
            param_2[2] = (uint)pvVar1;
            uVar3 = *param_2;
            param_2[1] = param_2[1] + 0x80;
          }
          *(uint *)(uVar3 * 4 + param_2[2]) = uVar4 | 0x400000;
          uVar4 = *param_2 + 1;
          *param_2 = uVar4;
        }
        else {
          uVar4 = *param_2;
          if (param_2[1] <= uVar4) {
            pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
            if ((void *)param_2[2] != (void *)0x0) {
              _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
              (**(code **)(param_1 + 0x18))(param_2[2]);
            }
            param_2[2] = (uint)pvVar1;
            uVar4 = *param_2;
            param_2[1] = param_2[1] + 0x80;
          }
          *(uint *)(uVar4 * 4 + param_2[2]) = (uVar6 & 0x3fff) << 0x10 | 0x5d;
          uVar4 = *param_2 + 1;
          *param_2 = uVar4;
          if (param_2[1] <= uVar4) {
            pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
            if ((void *)param_2[2] != (void *)0x0) {
              _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
              (**(code **)(param_1 + 0x18))(param_2[2]);
            }
            param_2[2] = (uint)pvVar1;
            uVar4 = *param_2;
            param_2[1] = param_2[1] + 0x80;
          }
          *(uint *)(uVar4 * 4 + param_2[2]) = uVar6 + 6 & 0xffff | 0x40000;
          *param_2 = *param_2 + 1;
          iVar2 = *(int *)(iVar9 + *(int *)(iVar5 + 0xc) + 8);
          if (iVar2 - 0x84c0U < 6) {
            uVar4 = iVar2 + 0x7b40U & 0xffff | 0x110000;
          }
          else if (*(char *)(param_6 + iVar2 + -0x8921) == '\0') {
            uVar7 = 0;
            uVar4 = iVar2 + 0x76dfU & 0xffff | 0x10000;
          }
          else {
            uVar4 = iVar2 + 0x76dfU & 0xffff | 0x40000;
          }
          *(undefined1 *)(uVar6 + param_6) = 1;
          uVar3 = *param_2;
          if (param_2[1] <= uVar3) {
            pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
            if ((void *)param_2[2] != (void *)0x0) {
              _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
              (**(code **)(param_1 + 0x18))(param_2[2]);
            }
            param_2[2] = (uint)pvVar1;
            uVar3 = *param_2;
            param_2[1] = param_2[1] + 0x80;
          }
          *(uint *)(uVar3 * 4 + param_2[2]) = uVar4 | 0x400000;
          uVar4 = *param_2 + 1;
          *param_2 = uVar4;
        }
        if (uVar7 == 0x8977) {
          puVar8 = ((unsigned char *)0x00003310);
        }
        else if (uVar7 < 0x8978) {
          if (uVar7 == 0) {
            puVar8 = ((unsigned char *)0x00004444);
          }
          else if (uVar7 == 0x8976) {
            puVar8 = ((unsigned char *)0x00003210);
          }
        }
        else if (uVar7 == 0x8978) {
          puVar8 = (undefined *)0x602510;
        }
        else if (uVar7 == 0x8979) {
          puVar8 = (undefined *)0x603510;
        }
        if (param_2[1] <= uVar4) {
          pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
          if ((void *)param_2[2] != (void *)0x0) {
            _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
            (**(code **)(param_1 + 0x18))(param_2[2]);
          }
          param_2[2] = (uint)pvVar1;
          uVar4 = *param_2;
          param_2[1] = param_2[1] + 0x80;
        }
        *(undefined **)(uVar4 * 4 + param_2[2]) = puVar8;
        *param_2 = *param_2 + 1;
        uVar4 = (uint)*(ushort *)(param_3 + 0x14);
      }
LAB_000b2c0c:
      uVar6 = uVar6 + 1;
    } while ((int)uVar6 < (int)uVar4);
    if (uVar4 != 0) {
      uVar6 = 0;
      do {
        iVar2 = (uVar6 + uVar4 * param_4) * 0xc;
        iVar9 = iVar2 + *(int *)(iVar5 + 0xc);
        if ((*(char *)(iVar2 + *(int *)(iVar5 + 0xc)) != '\0') &&
           (((*(char *)(iVar9 + 1) != '\0' || (*(int *)(iVar9 + 4) != 0x8976)) ||
            (uVar6 != *(int *)(iVar9 + 8) - 0x8921U)))) {
          uVar4 = *param_2;
          if (param_2[1] <= uVar4) {
            pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
            if ((void *)param_2[2] != (void *)0x0) {
              _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
              (**(code **)(param_1 + 0x18))(param_2[2]);
            }
            param_2[2] = (uint)pvVar1;
            uVar4 = *param_2;
            param_2[1] = param_2[1] + 0x80;
          }
          *(undefined4 *)(uVar4 * 4 + param_2[2]) = 0x47;
          uVar4 = *param_2 + 1;
          *param_2 = uVar4;
          if (param_2[1] <= uVar4) {
            pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
            if ((void *)param_2[2] != (void *)0x0) {
              _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
              (**(code **)(param_1 + 0x18))(param_2[2]);
            }
            param_2[2] = (uint)pvVar1;
            uVar4 = *param_2;
            param_2[1] = param_2[1] + 0x80;
          }
          *(uint *)(uVar4 * 4 + param_2[2]) = uVar6 & 0xffff | 0x40000;
          uVar4 = *param_2 + 1;
          *param_2 = uVar4;
          if (param_2[1] <= uVar4) {
            pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
            if ((void *)param_2[2] != (void *)0x0) {
              _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
              (**(code **)(param_1 + 0x18))(param_2[2]);
            }
            param_2[2] = (uint)pvVar1;
            uVar4 = *param_2;
            param_2[1] = param_2[1] + 0x80;
          }
          *(uint *)(uVar4 * 4 + param_2[2]) = (uVar6 & 0xffff) + 6 & 0xffff | 0x40000;
          *param_2 = *param_2 + 1;
          uVar4 = (uint)*(ushort *)(param_3 + 0x14);
        }
        uVar6 = uVar6 + 1;
      } while ((int)uVar6 < (int)uVar4);
    }
  }
  return;
}

/* FUN_000b2e60 @ 0xb2e60 (636 bytes) */
int FUN_000b2e60(param_1, param_2)
  int param_1;
  uint *param_2;
{
  void *pvVar1;
  uint uVar2;
  
  uVar2 = *param_2;
  if (param_2[1] <= uVar2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar2 * 4 + param_2[2]) = 0x47;
  uVar2 = *param_2 + 1;
  *param_2 = uVar2;
  if (param_2[1] <= uVar2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar2 * 4 + param_2[2]) = 0x40000;
  uVar2 = *param_2 + 1;
  *param_2 = uVar2;
  if (param_2[1] <= uVar2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar2 * 4 + param_2[2]) = 0x410000;
  uVar2 = *param_2 + 1;
  *param_2 = uVar2;
  if (param_2[1] <= uVar2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined **)(uVar2 * 4 + param_2[2]) = ((unsigned char *)0x00004444);
  *param_2 = *param_2 + 1;
  return;
}

/* FUN_000b30e0 @ 0xb30e0 (1352 bytes) */
int FUN_000b30e0(param_1, param_2, param_3, param_4)
  int param_1;
  uint *param_2;
  int param_3;
  int param_4;
{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  uVar5 = *param_2;
  iVar6 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (param_2[1] <= uVar5) {
    pvVar3 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar3,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar3;
    uVar5 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar5 * 4 + param_2[2]) = 0x1ff0016;
  uVar5 = *param_2 + 1;
  *param_2 = uVar5;
  if (param_2[1] <= uVar5) {
    pvVar3 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar3,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar3;
    uVar5 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar5 * 4 + param_2[2]) = 0x120000;
  uVar5 = *param_2 + 1;
  *param_2 = uVar5;
  if (*(char *)(param_4 + 0x6c) == '\0') {
    if ((*(uint *)(param_1 + 0x44) & 0x80100000) == 0x80000000) {
      if (*(short *)("}J3x})+x|B;x}k" + iVar6) != -0x7e06) goto LAB_000b3398;
    }
    else if ((*(uint *)(param_1 + 0x44) & 0x800000) == 0) goto LAB_000b3398;
  }
  if (param_2[1] <= uVar5) {
    pvVar3 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar3,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar3;
    uVar5 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar5 * 4 + param_2[2]) = 0x1ff0016;
  uVar5 = *param_2 + 1;
  *param_2 = uVar5;
  if (param_2[1] <= uVar5) {
    pvVar3 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar3,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar3;
    uVar5 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar5 * 4 + param_2[2]) = 0x130000;
  uVar5 = *param_2 + 1;
  *param_2 = uVar5;
LAB_000b3398:
  uVar1 = (uint)(byte)((unsigned char *)0x000013b0)[param_1];
  if (uVar1 != 0) {
    uVar7 = 0;
    do {
      if (((int)(uint)*(byte *)(param_3 + 1) >> (uVar7 & 0x3f) & 1U) != 0) {
        if (param_2[1] <= uVar5) {
          pvVar3 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
          if ((void *)param_2[2] != (void *)0x0) {
            _memcpy(pvVar3,(void *)param_2[2],*param_2 << 2);
            (**(code **)(param_1 + 0x18))(param_2[2]);
          }
          param_2[2] = (uint)pvVar3;
          uVar5 = *param_2;
          param_2[1] = param_2[1] + 0x80;
        }
        *(undefined4 *)(uVar5 * 4 + param_2[2]) = 0x1ff0016;
        uVar5 = *param_2 + 1;
        *param_2 = uVar5;
        if (param_2[1] <= uVar5) {
          pvVar3 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
          if ((void *)param_2[2] != (void *)0x0) {
            _memcpy(pvVar3,(void *)param_2[2],*param_2 << 2);
            (**(code **)(param_1 + 0x18))(param_2[2]);
          }
          param_2[2] = (uint)pvVar3;
          uVar5 = *param_2;
          param_2[1] = param_2[1] + 0x80;
        }
        *(uint *)(uVar5 * 4 + param_2[2]) = uVar7 & 0xffff | 0x110000;
        uVar5 = *param_2 + 1;
        *param_2 = uVar5;
        uVar1 = (uint)(byte)((unsigned char *)0x000013b0)[param_1];
      }
      uVar7 = uVar7 + 1;
    } while ((int)uVar7 < (int)uVar1);
  }
  uVar1 = (uint)*(ushort *)(param_3 + 0x14);
  if (*(ushort *)(param_3 + 0x14) != 0) {
    iVar8 = 0;
    iVar6 = 0;
    do {
      iVar4 = *(int *)(param_4 + 0xc);
      if (((*(char *)(iVar4 + iVar6) != '\0') && (*(char *)(iVar4 + iVar6 + 1) != '\0')) ||
         ((iVar2 = (iVar8 + uVar1) * 0xc, *(char *)(iVar4 + iVar2) != '\0' &&
          (*(char *)(iVar4 + iVar2 + 1) != '\0')))) {
        if (param_2[1] <= uVar5) {
          pvVar3 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
          if ((void *)param_2[2] != (void *)0x0) {
            _memcpy(pvVar3,(void *)param_2[2],*param_2 << 2);
            (**(code **)(param_1 + 0x18))(param_2[2]);
          }
          param_2[2] = (uint)pvVar3;
          uVar5 = *param_2;
          param_2[1] = param_2[1] + 0x80;
        }
        *(uint *)(uVar5 * 4 + param_2[2]) = iVar8 << 0x10 | 0x19;
        uVar5 = *param_2 + 1;
        *param_2 = uVar5;
        uVar1 = (uint)*(ushort *)(param_3 + 0x14);
      }
      iVar8 = iVar8 + 1;
      iVar6 = iVar6 + 0xc;
    } while (iVar8 < (int)uVar1);
  }
  return;
}

/* FUN_000b3630 @ 0xb3630 (3316 bytes) */
int FUN_000b3630(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  undefined2 uVar4;
  code *pcVar3;
  char cVar7;
  int iVar5;
  int iVar6;
  undefined4 uVar8;
  undefined1 *puVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  undefined1 *puVar18;
  code *pcVar19;
  int *piVar20;
  undefined1 *puVar21;
  int *piVar22;
  int iVar23;
  int iVar24;
  undefined1 local_74 [8];
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  int local_58;
  int local_54;
  
  local_54 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (((unsigned char *)0x00001134)[param_1] == '\0') {
    iVar23 = *(int *)(((unsigned char *)0x00001144) + param_1);
  }
  else {
    iVar23 = *(int *)(((unsigned char *)0x00001154) + param_1) + 0x10;
  }
  puVar18 = *(undefined1 **)(*(int *)(((unsigned char *)0x0000113c) + param_1) * 4 + *(int *)(iVar23 + 0x70));
  if (puVar18 != (undefined1 *)0x0) {
    uVar11 = *(uint *)(param_1 + 0x44);
    if ((uVar11 & 0x100000) == 0) {
      if ((((int)uVar11 < 0) && (*(short *)("}J3x})+x|B;x}k" + local_54) == -0x7e06)) ||
         (cVar7 = '\0', (uVar11 & 0x80800000) == 0x800000)) {
        cVar7 = '\x01';
      }
    }
    else if (((uVar11 & 0x800000) == 0) ||
            (cVar7 = '\x01', *(char *)(*(int *)(((unsigned char *)0x00001168) + param_1) + 0x6e) == '\0')) {
      cVar7 = '\0';
    }
    if (puVar18[0x118] == cVar7) {
      if (((unsigned char *)0x00001136)[param_1] != '\0') {
        *puVar18 = 0;
      }
    }
    else {
      puVar18[0x119] = 1;
    }
    if (puVar18[0x119] == '\0') goto LAB_000b42ec;
  }
  local_64 = 0;
  local_6c = 0;
  local_68 = 0;
  ((int (*)())FUN_000b15d0)(param_1,&local_6c,1);
  ((int (*)())FUN_000b15d0)(param_1,&local_6c,0x10200);
  iVar5 = 0;
  iVar24 = 8;
  do {
    local_74[iVar5] = 0;
    iVar5 = iVar5 + 1;
    iVar24 = iVar24 + -1;
  } while (iVar24 != 0);
  if (puVar18 != (undefined1 *)0x0) {
    uVar8 = *(undefined4 *)(*(int *)(((unsigned char *)0x0000113c) + param_1) * 4 + *(int *)(iVar23 + 0x70));
    *(undefined4 *)(*(int *)(((unsigned char *)0x0000113c) + param_1) * 4 + *(int *)(iVar23 + 0x70)) = 0;
    (**(code **)(((unsigned char *)0x00001158) + param_1))(param_1,uVar8);
    pcVar3 = *(code **)(((unsigned char *)0x00001284) + param_1);
    iVar24 = *(int *)(((unsigned char *)0x0000113c) + param_1);
    pcVar19 = *(code **)(param_1 + 0x10);
    iVar5 = *(int *)(iVar23 + 0x70);
  }
  else {
    pcVar3 = *(code **)(((unsigned char *)0x00001284) + param_1);
    iVar24 = *(int *)(((unsigned char *)0x0000113c) + param_1);
    pcVar19 = *(code **)(param_1 + 0x10);
    iVar5 = *(int *)(iVar23 + 0x70);
  }
  uVar8 = (*pcVar3)(param_1);
  uVar8 = (*pcVar19)(1,uVar8);
  *(undefined4 *)(iVar24 * 4 + iVar5) = uVar8;
  puVar18 = *(undefined1 **)(*(int *)(((unsigned char *)0x0000113c) + param_1) * 4 + *(int *)(iVar23 + 0x70));
  *puVar18 = 0;
  local_58 = *(int *)(iVar23 + 4);
  ((int (*)())FUN_000b30e0)(param_1,&local_6c,(*(unsigned char *)0x00001134) + param_1,iVar23);
  ((int (*)())FUN_000b2e60)(param_1,&local_6c);
  if (0 < local_58) {
    iVar15 = 0;
    iVar16 = 0;
    iVar24 = 0;
    iVar5 = 0;
    do {
      iVar13 = 0;
      iVar14 = 0;
      iVar17 = 0;
      ((int (*)())FUN_000b25a0)(param_1,&local_6c,(*(unsigned char *)0x00001134) + param_1,iVar5,local_58,local_74);
      while( true ) {
        iVar6 = *(int *)(*(int *)(iVar23 + 0x14) + iVar5 * 4);
        iVar12 = *(int *)(*(int *)(iVar23 + 0x20) + iVar5 * 4);
        if (iVar6 + iVar12 <= iVar17) break;
        if (((iVar15 < *(int *)(iVar23 + 0x18)) && (iVar13 < iVar6)) &&
           (piVar20 = (int *)(iVar15 * 0x4c + *(int *)(iVar23 + 0x10)), iVar24 == piVar20[0x11])) {
          iVar15 = iVar15 + 1;
          iVar13 = iVar13 + 1;
          iVar17 = iVar17 + 1;
          iVar24 = iVar24 + 1;
        }
        else {
          piVar20 = (int *)0x0;
        }
        if (((iVar16 < *(int *)(iVar23 + 0x24)) && (iVar14 < iVar12)) &&
           (piVar22 = (int *)(iVar16 * 0x4c + *(int *)(iVar23 + 0x1c)), iVar24 == piVar22[0x11])) {
          iVar14 = iVar14 + 1;
          iVar17 = iVar17 + 1;
          iVar16 = iVar16 + 1;
          iVar24 = iVar24 + 1;
        }
        else {
          piVar22 = (int *)0x0;
        }
        if ((piVar20 == (int *)0x0) || (piVar22 == (int *)0x0)) goto LAB_000b3a90;
        switch(*piVar22) {
        case 0x8961:
          uVar11 = 1;
          break;
        default:
          uVar11 = 0;
          break;
        case 0x8966:
        case 0x8967:
          if (*piVar22 == *piVar20) goto LAB_000b3a90;
        case 0x8963:
        case 0x8964:
        case 0x8965:
          uVar11 = 2;
          break;
        case 0x896c:
          if (*piVar20 == 0x896c) goto LAB_000b3a90;
        case 0x8968:
        case 0x8969:
        case 0x896a:
        case 0x896b:
          uVar11 = 3;
        }
        iVar6 = piVar20[1];
        if (((iVar6 != piVar22[5]) && ((iVar6 != piVar22[9] || (uVar11 < 2)))) &&
           ((iVar6 != piVar22[0xd] || (uVar11 < 3)))) {
LAB_000b3a90:
          if (piVar20 != (int *)0x0) {
            bVar1 = false;
            iVar6 = 0;
            goto LAB_000b3aa8;
          }
          bVar1 = false;
          iVar6 = 0;
          goto switchD_000b3adc_caseD_8962;
        }
        iVar6 = piVar20[1];
        bVar1 = true;
        piVar20[1] = 6;
LAB_000b3aa8:
        bVar2 = piVar22 != (int *)0x0;
        switch(*piVar20) {
        case 0x8961:
          ((int (*)())FUN_000b15d0)(param_1,&local_6c,0x47);
          ((int (*)())FUN_000b2260)(param_1,&local_6c,piVar20 + 1,0,1,local_74);
          ((int (*)())FUN_000b1e80)(param_1,&local_6c,piVar20 + 5,0,1,local_74);
        default:
          goto switchD_000b3adc_caseD_8962;
        case 0x8963:
          uVar4 = 3;
          break;
        case 0x8964:
          uVar4 = 0x49;
          break;
        case 0x8965:
          uVar4 = 0x5b;
          break;
        case 0x8966:
          if ((bVar2) && (*piVar22 == 0x8966)) {
            piVar20[2] = piVar20[2] | 8;
          }
          uVar4 = 0x22;
          break;
        case 0x8967:
          if ((bVar2) && (*piVar22 == 0x8967)) {
            piVar20[2] = piVar20[2] | 8;
          }
          uVar4 = 0x23;
          break;
        case 0x8968:
          uVar4 = 0x40;
          goto LAB_000b3c70;
        case 0x8969:
          uVar4 = 0x3f;
LAB_000b3c70:
          ((int (*)())FUN_000b15d0)(param_1,&local_6c,uVar4);
          ((int (*)())FUN_000b2260)(param_1,&local_6c,piVar20 + 1,0,1,local_74);
          ((int (*)())FUN_000b1e80)(param_1,&local_6c,piVar20 + 5,0,1,local_74);
LAB_000b3e14:
          ((int (*)())FUN_000b1e80)(param_1,&local_6c,piVar20 + 9,0,1,local_74);
          ((int (*)())FUN_000b1e80)(param_1,&local_6c,piVar20 + 0xd,0,1,local_74);
          goto switchD_000b3adc_caseD_8962;
        case 0x896a:
          uVar11 = 0x3000d;
          iVar12 = 1;
          goto LAB_000b3d3c;
        case 0x896b:
          uVar11 = 0x2000d;
          iVar12 = 0;
LAB_000b3d3c:
          ((int (*)())FUN_000b15d0)(param_1,&local_6c,iVar12 << 0x16 | uVar11);
          ((int (*)())FUN_000b2260)(param_1,&local_6c,piVar20 + 1,0,1,local_74);
          ((int (*)())FUN_000b1e80)(param_1,&local_6c,piVar20 + 0xd,0,1,local_74);
          goto LAB_000b3bb4;
        case 0x896c:
          if ((bVar2) && (*piVar22 == 0x896c)) {
            piVar20[2] = piVar20[2] | 8;
          }
          ((int (*)())FUN_000b15d0)(param_1,&local_6c,0x21);
          ((int (*)())FUN_000b2260)(param_1,&local_6c,piVar20 + 1,0,1,local_74);
          ((int (*)())FUN_000b1e80)(param_1,&local_6c,piVar20 + 5,0,1,local_74);
          goto LAB_000b3e14;
        }
        ((int (*)())FUN_000b15d0)(param_1,&local_6c,uVar4);
        ((int (*)())FUN_000b2260)(param_1,&local_6c,piVar20 + 1,0,1,local_74);
LAB_000b3bb4:
        ((int (*)())FUN_000b1e80)(param_1,&local_6c,piVar20 + 5,0,1,local_74);
        ((int (*)())FUN_000b1e80)(param_1,&local_6c,piVar20 + 9,0,1,local_74);
switchD_000b3adc_caseD_8962:
        if (piVar22 == (int *)0x0) goto switchD_000b3e78_caseD_8962;
        switch(*piVar22) {
        case 0x8961:
          ((int (*)())FUN_000b15d0)(param_1,&local_6c,0x47);
          ((int (*)())FUN_000b2260)(param_1,&local_6c,piVar22 + 1,0,0,local_74);
          ((int (*)())FUN_000b1e80)(param_1,&local_6c,piVar22 + 5,0,0,local_74);
          break;
        case 0x8963:
          uVar4 = 3;
          goto LAB_000b3f1c;
        case 0x8964:
          uVar4 = 0x49;
          goto LAB_000b3f1c;
        case 0x8965:
          uVar4 = 0x5b;
LAB_000b3f1c:
          ((int (*)())FUN_000b15d0)(param_1,&local_6c,uVar4);
          ((int (*)())FUN_000b2260)(param_1,&local_6c,piVar22 + 1,0,0,local_74);
LAB_000b4120:
          ((int (*)())FUN_000b1e80)(param_1,&local_6c,piVar22 + 5,0,0,local_74);
          ((int (*)())FUN_000b1e80)(param_1,&local_6c,piVar22 + 9,0,0,local_74);
          break;
        case 0x8968:
          uVar4 = 0x40;
          goto LAB_000b3f68;
        case 0x8969:
          uVar4 = 0x3f;
LAB_000b3f68:
          ((int (*)())FUN_000b15d0)(param_1,&local_6c,uVar4);
          ((int (*)())FUN_000b2260)(param_1,&local_6c,piVar22 + 1,0,0,local_74);
          ((int (*)())FUN_000b1e80)(param_1,&local_6c,piVar22 + 5,0,0,local_74);
          ((int (*)())FUN_000b1e80)(param_1,&local_6c,piVar22 + 9,0,0,local_74);
          ((int (*)())FUN_000b1e80)(param_1,&local_6c,piVar22 + 0xd,0,0,local_74);
          break;
        case 0x896a:
          ((int (*)())FUN_000b15d0)(param_1,&local_6c,0x43000d);
          ((int (*)())FUN_000b2260)(param_1,&local_6c,piVar22 + 1,0,0,local_74);
          ((int (*)())FUN_000b1e80)(param_1,&local_6c,piVar22 + 0xd,0,0,local_74);
          goto LAB_000b4120;
        case 0x896b:
          ((int (*)())FUN_000b15d0)(param_1,&local_6c,0x2000d);
          ((int (*)())FUN_000b2260)(param_1,&local_6c,piVar22 + 1,0,0,local_74);
          ((int (*)())FUN_000b1e80)(param_1,&local_6c,piVar22 + 0xd,0,0,local_74);
          goto LAB_000b4120;
        }
switchD_000b3e78_caseD_8962:
        if (bVar1) {
          ((int (*)())FUN_000b1b90)(param_1,&local_6c,iVar6,piVar20[1],piVar20[2]);
          piVar20[1] = iVar6;
        }
      }
      iVar5 = iVar5 + 1;
    } while (local_58 != iVar5);
  }
  if ((*(uint *)(param_1 + 0x44) & 0x80100000) == 0x80000000) {
    if (*(short *)("}J3x})+x|B;x}k" + local_54) == -0x7e06) goto LAB_000b420c;
LAB_000b41b8:
    puVar18[0x118] = 0;
  }
  else {
    if ((*(uint *)(param_1 + 0x44) & 0x800000) == 0) goto LAB_000b41b8;
LAB_000b420c:
    ((int (*)())FUN_000b1870)(param_1,&local_6c);
    puVar18[0x118] = 1;
  }
  ((int (*)())FUN_000b1690)(param_1,&local_6c);
  ((int (*)())FUN_000b15d0)(param_1,&local_6c,0x28);
  *(undefined4 *)(puVar18 + 0x11c) = 0;
  uVar11 = (uint)*(ushort *)(((unsigned char *)0x0000114a) + param_1);
  if (uVar11 != 0) {
    uVar10 = 0;
    iVar5 = 0;
    puVar21 = puVar18;
    do {
      if (*(char *)(*(int *)(iVar23 + 0x28) + iVar5) != '\0') {
        *(uint *)(puVar18 + 0x11c) = 1 << (uVar10 & 0x3f) | *(uint *)(puVar18 + 0x11c);
        *(undefined4 *)(puVar21 + 0x98) = *(undefined4 *)(*(int *)(iVar23 + 0x28) + iVar5 + 4);
        *(undefined4 *)(puVar21 + 0x9c) = *(undefined4 *)(*(int *)(iVar23 + 0x28) + iVar5 + 8);
        *(undefined4 *)(puVar21 + 0xa0) = *(undefined4 *)(*(int *)(iVar23 + 0x28) + iVar5 + 0xc);
        *(undefined4 *)(puVar21 + 0xa4) = *(undefined4 *)(*(int *)(iVar23 + 0x28) + iVar5 + 0x10);
        uVar11 = (uint)*(ushort *)(((unsigned char *)0x0000114a) + param_1);
      }
      uVar10 = uVar10 + 1;
      iVar5 = iVar5 + 0x14;
      puVar21 = puVar21 + 0x10;
    } while ((int)uVar10 < (int)uVar11);
  }
  puVar18[0x120] = 1;
  (**(code **)(((unsigned char *)0x00001288) + param_1))(param_1,0,puVar18,&local_6c);
  puVar18[0x119] = 0;
LAB_000b42ec:
  uVar11 = 0;
  iVar23 = 0;
  ((unsigned char *)0x00001136)[param_1] = 0;
  puVar21 = puVar18 + 0x98;
  do {
    if ((1 << (uVar11 & 0x3f) & *(uint *)(puVar18 + 0x11c)) == 0) {
      if (*(char *)(iVar23 + *(int *)(*(int *)(((unsigned char *)0x00001154) + param_1) + 0xc)) != '\0') {
        pcVar3 = *(code **)(((unsigned char *)0x00001280) + param_1);
        puVar9 = (undefined1 *)(iVar23 + *(int *)(*(int *)(((unsigned char *)0x00001154) + param_1) + 0xc) + 4);
        goto LAB_000b4370;
      }
    }
    else {
      pcVar3 = *(code **)(((unsigned char *)0x00001280) + param_1);
      puVar9 = puVar21;
LAB_000b4370:
      (*pcVar3)(param_1,puVar18,uVar11,uVar11,puVar9,1,0);
    }
    bVar1 = uVar11 == 7;
    puVar21 = puVar21 + 0x10;
    iVar23 = iVar23 + 0x14;
    uVar11 = uVar11 + 1;
    if (bVar1) {
      if ((*(uint *)(param_1 + 0x44) & 0x22000) == 0x20000) {
        (**(code **)(((unsigned char *)0x00001290) + param_1))(param_1,puVar18);
      }
      return 1;
    }
  } while( true );
}

/* FUN_000b43f0 @ 0xb43f0 (4 bytes) */
int FUN_000b43f0()
{
  return;
}

/* FUN_000b4400 @ 0xb4400 (2136 bytes) */
int FUN_000b4400(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int *param_2;
  int *param_3;
  int *param_4;
  int param_5;
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int *piVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  undefined1 local_38 [28];
  
  if ((((param_2 == (int *)0x0) || (param_3 == (int *)0x0)) || (param_4 == (int *)0x0)) ||
     (param_5 == 0)) {
    return 1;
  }
  *param_2 = param_1;
  param_2[0xe] = 0;
  param_2[1] = 0;
  iVar8 = 0;
  param_2[2] = 0;
  *(undefined1 *)(param_2 + 3) = 0;
  *(undefined1 *)((int)param_2 + 0xd) = 0;
  *(undefined1 *)((int)param_2 + 0xe) = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  param_2[7] = 0;
  param_2[9] = 0;
  param_2[10] = 0;
  param_2[0xb] = 0;
  param_2[0xc] = 0;
  *(undefined1 *)(param_2 + 0xd) = 0;
  param_2[8] = 0;
  param_2[6] = 0x21;
  piVar4 = param_2;
  piVar7 = param_2;
  piVar9 = param_2;
  do {
    bVar1 = iVar8 != 2;
    piVar4[0xf] = 0x21;
    piVar4[0x12] = 0;
    piVar9[0x15] = 0;
    piVar9[0x16] = 1;
    piVar9[0x17] = 2;
    piVar9[0x18] = 3;
    *(undefined1 *)(piVar4 + 0x21) = 0;
    *(undefined1 *)((int)piVar4 + 0x85) = 0;
    *(undefined1 *)((int)piVar4 + 0x86) = 0;
    *(undefined1 *)((int)piVar4 + 0x87) = 0;
    *(undefined1 *)(piVar7 + 0x24) = 0;
    *(undefined1 *)((int)piVar7 + 0x93) = 0;
    *(undefined1 *)((int)piVar7 + 0x96) = 0;
    *(undefined1 *)((int)piVar7 + 0x99) = 0;
    *(undefined1 *)(piVar7 + 0x27) = 0;
    piVar4[0x28] = 0;
    piVar9 = piVar9 + 4;
    piVar4 = piVar4 + 1;
    piVar7 = (int *)((int)piVar7 + 1);
    iVar8 = iVar8 + 1;
  } while (bVar1);
  param_2[0x2d] = 0;
  *(undefined1 *)(param_2 + 0x2b) = 0;
  param_2[0x2c] = 0;
  iVar8 = 0x10;
  piVar4 = param_2;
  piVar7 = param_2;
  do {
    *(undefined1 *)(piVar4 + 0x56e) = 0;
    piVar7[0x572] = 0;
    *(undefined1 *)(piVar4 + 0x582) = 0;
    *(undefined1 *)(piVar4 + 0x586) = 0;
    piVar7[0x7aa] = 0;
    piVar4 = (int *)((int)piVar4 + 1);
    piVar7 = piVar7 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  iVar8 = 0x30;
  piVar4 = param_2;
  piVar7 = param_2;
  do {
    *(undefined1 *)(piVar7 + 0x58a) = 0;
    piVar4[0x658] = 0;
    piVar7 = (int *)((int)piVar7 + 1);
    piVar4 = piVar4 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  param_2[0x788] = 0;
  param_2[0x656] = 0;
  param_2[0x78a] = 0x100;
  iVar8 = 0;
  piVar4 = param_2;
  piVar7 = param_2;
  piVar9 = param_2;
  do {
    *(undefined1 *)(piVar7 + 0x596) = 0;
    *(undefined1 *)(piVar7 + 0x5d6) = 0;
    iVar8 = iVar8 + 1;
    piVar9[0x688] = 0;
    piVar4[0x6e] = 0;
    piVar4[0x6f] = 0;
    piVar4[0x70] = 0;
    piVar4[0x71] = 0;
    *(undefined1 *)(piVar7 + 0x2e) = 0;
    piVar9 = piVar9 + 1;
    piVar7 = (int *)((int)piVar7 + 1);
    piVar4 = piVar4 + 5;
  } while (iVar8 < param_2[0x78a]);
  param_2[0x7a5] = 0;
  param_2[0x657] = 0;
  param_2[0x789] = 0;
  *(undefined1 *)(param_2 + 0x78b) = 0;
  iVar8 = 8;
  *(undefined1 *)((int)param_2 + 0x1e2d) = 0;
  *(undefined1 *)((int)param_2 + 0x1e2e) = 0;
  *(undefined1 *)((int)param_2 + 0x1e2f) = 0;
  *(undefined1 *)(param_2 + 0x78c) = 0;
  param_2[0x7a3] = 0;
  param_2[0x7a4] = 0;
  piVar4 = param_2;
  piVar7 = param_2;
  do {
    *(undefined1 *)((int)piVar7 + 0x1e31) = 0;
    *(undefined1 *)((int)piVar7 + 0x1e39) = 0;
    piVar7 = (int *)((int)piVar7 + 1);
    piVar4[0x793] = 0;
    piVar4[0x79b] = 0;
    piVar4 = piVar4 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  param_2[0x7a9] = 0;
  param_2[0x791] = 0;
  param_2[0x792] = 0;
  *(undefined1 *)(param_2 + 0x7a6) = 0;
  iVar8 = 4;
  *(undefined1 *)((int)param_2 + 0x1e99) = 0;
  *(undefined1 *)((int)param_2 + 0x1e9a) = 0;
  *(undefined1 *)((int)param_2 + 0x1e9b) = 0;
  *(undefined1 *)(param_2 + 0x7a7) = 0;
  *(undefined1 *)((int)param_2 + 0x1e9d) = 0;
  *(undefined1 *)((int)param_2 + 0x1e9e) = 0;
  *(undefined1 *)((int)param_2 + 0x1e9f) = 0;
  *(undefined1 *)(param_2 + 0x7a8) = 0;
  *(undefined1 *)((int)param_2 + 0x1ea1) = 0;
  *(undefined1 *)(param_2 + 0x7ba) = 0;
  param_2[0x7bb] = 0;
  param_2[0x7bc] = 0;
  param_2[0x7bd] = 0;
  piVar4 = param_2;
  do {
    *(undefined1 *)(piVar4 + 0x7be) = 0;
    piVar4 = (int *)((int)piVar4 + 1);
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  *(undefined1 *)(param_2 + 0x7c1) = 0;
  *(undefined1 *)(param_2 + 0x7bf) = 0;
  *(undefined1 *)((int)param_2 + 0x1efd) = 0;
  param_2[0x7c5] = 0;
  param_2[0x7c3] = 0;
  param_2[0x7c2] = 1;
  param_2[0x7c6] = 0;
  param_2[0x7c4] = 0;
  param_2[0x7c7] = 0x8000;
  *param_3 = param_5;
  param_3[1] = (int)(((unsigned char *)0x000010ec) + param_5);
  *(undefined4 *)(((unsigned char *)0x000012fc) + param_5) = 0;
  iVar10 = 0x10;
  *(undefined4 *)(((unsigned char *)0x000010e4) + *param_3) = 0xffffffff;
  iVar8 = param_5;
  do {
    *(undefined4 *)(((unsigned char *)0x000015d0) + iVar8) = 0;
    ((unsigned char *)0x00001610)[param_5] = 0;
    param_5 = param_5 + 1;
    *(undefined4 *)(((unsigned char *)0x00001620) + iVar8) = 0;
    iVar8 = iVar8 + 4;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  iVar8 = 8;
  *(undefined4 *)(((unsigned char *)0x000010e0) + *param_3) = 0;
  *(undefined4 *)(((unsigned char *)0x000015cc) + *param_3) = 0;
  ((unsigned char *)0x000010e9)[*param_3] = 0;
  ((unsigned char *)0x000010ea)[*param_3] = 0;
  param_3[0x12] = 1;
  param_3[0x1a] = 0;
  param_3[0x18] = 0;
  param_3[0x17] = 0;
  param_3[0x19] = 0;
  param_3[0x15] = 0;
  param_3[0x16] = 0;
  param_3[0x13] = 0;
  param_3[0x14] = 0;
  piVar4 = param_3;
  do {
    piVar4[0x1b] = 0;
    piVar4[0x23] = 0;
    piVar4 = piVar4 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  iVar8 = 0;
  iVar10 = 4;
  do {
    iVar2 = iVar8 * 4;
    iVar8 = iVar8 + 1;
    *(undefined4 *)(((unsigned char *)0x000010a8) + iVar2 + *param_3) = 0;
    *(undefined4 *)(((unsigned char *)0x00001098) + iVar2 + *param_3) = 0;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  iVar8 = 8;
  piVar4 = param_3;
  do {
    *(undefined1 *)(piVar4 + 0x2c) = 0;
    piVar4 = (int *)((int)piVar4 + 1);
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  iVar8 = 4;
  param_3[0x36] = 0;
  param_3[0x3a] = 0;
  param_3[0x37] = 0x8000;
  param_3[0x2e] = 0x8000;
  param_3[0x2f] = 0x8000;
  param_3[0x30] = 0x8000;
  param_3[0x31] = 0x8000;
  param_3[0x32] = 0x8000;
  param_3[0x33] = 0x8000;
  param_3[0x34] = 0x8000;
  param_3[0x35] = 0x8000;
  param_3[0x3b] = 0;
  param_3[0x3c] = 0;
  param_3[0x3d] = 0;
  param_3[0x42] = 0;
  piVar4 = param_3;
  do {
    piVar4[0x3e] = 0;
    piVar4 = piVar4 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  *(undefined1 *)(param_3 + 0x44) = 0;
  *(undefined1 *)(param_3 + 0x43) = 0;
  *(undefined1 *)((int)param_3 + 0x10d) = 0;
  *(undefined1 *)((int)param_3 + 0x10e) = 0;
  *(undefined1 *)((int)param_3 + 0x10f) = 0;
  param_2[2] = *param_4;
  *(byte *)((int)param_2 + 0x1f05) = (byte)param_4[3] & 1;
  *(byte *)((int)param_2 + 0x1f06) = (byte)param_4[3] & 2;
  uVar3 = (uint)param_4[3] >> 2 & 3;
  param_3[0x45] = uVar3;
  if (uVar3 != 0) {
    *(undefined1 *)(param_2 + 0x7a8) = 1;
  }
  if ((param_4[3] & 0x100U) == 0) {
    *(undefined1 *)(param_3 + 0x46) = 0;
    param_3[1] = (int)(((unsigned char *)0x000010ec) + *param_3);
  }
  else {
    *(undefined1 *)(param_3 + 0x46) = 1;
    param_3[1] = (int)(((unsigned char *)0x00001318) + *param_3);
  }
  if ((param_4[3] & 0x400U) == 0) {
    param_3[0x47] = 0;
  }
  else {
    param_3[0x47] = param_4[4];
  }
  if ((param_4[3] & 0x200U) == 0) {
    *(undefined1 *)((int)param_3 + 0x119) = 0;
  }
  else {
    *(undefined1 *)((int)param_3 + 0x119) = 1;
  }
  iVar8 = 0;
  iVar10 = 8;
  do {
    local_38[iVar8] = 0;
    iVar8 = iVar8 + 1;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  puVar5 = (undefined4 *)FUN_000a6f70(0x48000);
  param_3[3] = (int)puVar5;
  _memset(puVar5,0,0x48);
  *(undefined1 *)(puVar5 + 3) = 0;
  *(undefined1 *)((int)puVar5 + 0xd) = 0;
  *(undefined2 *)(puVar5 + 5) = 0;
  *(undefined2 *)((int)puVar5 + 0x22) = 0;
  puVar5[1] = 0x1000;
  *puVar5 = 0;
  puVar5[2] = 0;
  param_3[2] = (int)(puVar5 + 0x12);
  iVar8 = FUN_000879f0(param_1,param_2,param_3,param_3[1],puVar5 + 0x12,local_38,0,0);
  iVar10 = 0;
  param_3[2] = iVar8;
  *(undefined1 *)(param_2 + 0x7c8) = 1;
  iVar8 = 0x10;
  do {
    iVar2 = iVar10 * 0x10;
    iVar10 = iVar10 + 1;
    *(undefined4 *)(iVar2 + param_3[1] + 0x108) = 0;
    *(undefined4 *)(iVar2 + param_3[1] + 0x10c) = 1;
    *(undefined4 *)(iVar2 + param_3[1] + 0x110) = 2;
    *(undefined4 *)(iVar2 + param_3[1] + 0x114) = 3;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  if (param_1 == 0) {
    iVar8 = param_4[6];
  }
  else {
    if (*(int *)(param_1 + 0x186c) == 0) {
      FUN_000c6ff0(param_1,*(undefined4 *)(param_1 + 0x2454));
    }
    iVar8 = param_1 + 0x186c;
  }
  iVar8 = FUN_000cae90(param_1,param_2,param_3,param_4,iVar8);
  if (iVar8 != 0) {
    return 2;
  }
  FUN_000c5e60(param_3[3]);
  iVar8 = param_3[3];
  FUN_000c5e60(iVar8);
  if ((param_4[3] & 0x100U) == 0) {
    iVar10 = *param_3 + 4;
  }
  else {
    iVar10 = *param_3 + 0x20;
  }
  uVar6 = FUN_000a6f70(((uint)*(ushort *)(iVar8 + 0x1c) + (uint)*(ushort *)(iVar8 + 0x1a) +
                       (uint)*(ushort *)(iVar8 + 0x20)) * 0x18);
  *(undefined4 *)(iVar10 + 0x10) = uVar6;
  iVar8 = FUN_000bfed0(param_3[3],param_3[1] + 0x44,iVar10);
  if ((param_4[3] & 0x100U) == 0) {
    *(uint *)(((unsigned char *)0x000036a8) + *param_3) =
         ((*(uint *)(iVar10 + 8) >> 0x10 & 0x1ff) - (*(uint *)(iVar10 + 8) & 0x1ff)) + 1;
    *(uint *)(((unsigned char *)0x000036b0) + *param_3) = (*(uint *)(param_3[1] + 0x44) & 0xf) + 1;
  }
  else {
    *(uint *)(((unsigned char *)0x000036b4) + *param_3) =
         ((*(uint *)(iVar10 + 8) >> 0x10 & 0x1ff) - (*(uint *)(iVar10 + 8) & 0x1ff)) + 1;
    *(uint *)(((unsigned char *)0x000036bc) + *param_3) = (*(uint *)(param_3[1] + 0x44) & 0xf) + 1;
  }
  ((unsigned char *)0x000036c5)[*param_3] = 1;
  _free((void *)param_3[3]);
  if (8 < (uint)(((param_2[0x791] + param_2[0x792]) -
                 ((int)-(uint)*(byte *)((int)param_2 + 0x1e2e) >> 0x1f)) -
                ((int)-(uint)*(byte *)((int)param_2 + 0x1e2f) >> 0x1f))) {
    param_2[1] = 6;
    return 6;
  }
  if (iVar8 == 0) {
switchD_000b4be8_caseD_80000007:
    uVar6 = 0;
  }
  else {
    switch(iVar8) {
    case -0x7fffffff:
    case -0x7ffffff0:
      uVar6 = 3;
      break;
    case -0x7ffffffe:
    case -0x7fffffee:
      uVar6 = 4;
      break;
    case -0x7ffffffd:
    case -0x7fffffec:
      uVar6 = 6;
      break;
    case -0x7ffffffc:
    case -0x7fffffea:
      uVar6 = 9;
      break;
    case -0x7ffffffb:
    case -0x7fffffeb:
      uVar6 = 10;
      break;
    case -0x7ffffffa:
    case -0x7fffffef:
      uVar6 = 8;
      break;
    default:
      goto switchD_000b4be8_caseD_80000007;
    case -0x7fffffed:
      uVar6 = 5;
      break;
    case -0x7fffffe9:
      uVar6 = 0xb;
      break;
    case -0x7fffffe8:
      uVar6 = 0xc;
    }
  }
  return uVar6;
}

/* FUN_000b4cd0 @ 0xb4cd0 (608 bytes) */
int FUN_000b4cd0(param_1, param_2)
  int param_1;
  int param_2;
{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  int iStack_2088;
  int iStack_2084;
  undefined4 uStack_2080;
  undefined4 uStack_207c;
  undefined1 auStack_206c [176];
  char acStack_1fbc [116];
  undefined1 auStack_1f48 [5560];
  char acStack_990 [16];
  uint auStack_980 [16];
  char acStack_940 [2085];
  undefined1 uStack_11b;
  undefined1 uStack_11a;
  undefined1 uStack_119;
  undefined1 uStack_4b;
  undefined1 uStack_44;
  
  iStack_2088 = *(int *)(*(int *)(param_2 + 0x74) + 0x58) + 10;
  uStack_2080 = 0;
  uStack_207c = 0;
  iStack_2084 = *(int *)(*(int *)(param_2 + 0x74) + 0x5c) + -10 >> 2;
  iVar2 = ((int (*)())FUN_000b4400)(param_1,auStack_1f48,auStack_206c,&iStack_2088,
                       *(undefined4 *)
                        (*(int *)(((unsigned char *)0x00001130) + param_1) * 4 + *(int *)(param_2 + 0x70)));
  *(undefined4 *)(*(int *)(param_2 + 0x74) + 0xc) = 0;
  *(undefined4 *)(*(int *)(param_2 + 0x74) + 0x10) = 0;
  *(undefined1 *)(*(int *)(param_2 + 0x74) + 4) = 0;
  **(undefined1 **)(param_2 + 0x74) = 0;
  *(undefined1 *)(*(int *)(param_2 + 0x74) + 1) = 0;
  *(undefined1 *)(*(int *)(param_2 + 0x74) + 2) = 0;
  *(undefined1 *)(*(int *)(param_2 + 0x74) + 3) = 0;
  *(undefined1 *)(*(int *)(param_2 + 0x74) + 5) = 0;
  *(undefined4 *)(param_2 + 0x54) = 0;
  *(undefined4 *)(param_2 + 0x58) = 0;
  *(undefined4 *)(param_2 + 0x50) = 0;
  *(undefined4 *)(param_2 + 0x5c) = 0;
  *(undefined4 *)(param_2 + 0x60) = 0;
  *(undefined4 *)(param_2 + 100) = 0;
  *(undefined4 *)(param_2 + 0x68) = 0;
  if (iVar2 == 0) {
    uVar6 = 0;
    pcVar7 = acStack_1fbc;
    *(undefined1 *)(*(int *)(param_2 + 0x74) + 4) = uStack_4b;
    iVar2 = 8;
    **(undefined1 **)(param_2 + 0x74) = uStack_11b;
    *(undefined1 *)(*(int *)(param_2 + 0x74) + 1) = uStack_11a;
    *(undefined1 *)(*(int *)(param_2 + 0x74) + 2) = uStack_119;
    *(undefined1 *)(*(int *)(param_2 + 0x74) + 3) = uStack_44;
    *(undefined1 *)(*(int *)(param_2 + 0x74) + 5) = 0;
    do {
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      if (cVar1 != '\0') {
        *(uint *)(*(int *)(param_2 + 0x74) + 0xc) =
             1 << (uVar6 & 0x3f) | *(uint *)(*(int *)(param_2 + 0x74) + 0xc);
      }
      uVar6 = uVar6 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    uVar6 = 0;
    pcVar7 = acStack_990;
    puVar4 = auStack_980;
    iVar2 = 0x10;
    do {
      if (*pcVar7 != '\0') {
        *(uint *)(*(int *)(param_2 + 0x74) + 0x10) =
             1 << (uVar6 & 0x3f) | *(uint *)(*(int *)(param_2 + 0x74) + 0x10);
        uVar5 = *puVar4;
        if (uVar5 == 2) {
          uVar3 = 5;
          if (pcVar7[0x50] == '\0') {
            uVar3 = 2;
          }
          *(undefined4 *)(uVar6 * 4 + *(int *)(param_2 + 0x74) + 0x14) = uVar3;
        }
        else if (uVar5 < 3) {
          if (uVar5 == 1) {
LAB_000b4ee0:
            *(uint *)(uVar6 * 4 + *(int *)(param_2 + 0x74) + 0x14) = uVar5;
          }
        }
        else if ((uVar5 == 3) || (uVar5 == 4)) goto LAB_000b4ee0;
      }
      uVar6 = uVar6 + 1;
      pcVar7 = pcVar7 + 1;
      puVar4 = puVar4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    uVar3 = 1;
    *(undefined1 *)(param_2 + 0x6c) = 1;
  }
  else if (iVar2 == 1) {
    *(undefined1 *)(param_2 + 0x6c) = 0;
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
    *(undefined1 *)(param_2 + 0x6c) = 0;
  }
  return uVar3;
}

/* FUN_000b4f50 @ 0xb4f50 (180 bytes) */
void FUN_000b4f50(double param_1,double param_2,double param_3,double param_4,int param_5,
                 int param_6)

{
  undefined4 uVar1;
  int in_r9;
  
  if (in_r9 == 0) {
    uVar1 = ((uint (*)())FUN_0004a7d0)();
    param_5 = param_6 * 0x10 + param_5;
    *(undefined4 *)(param_5 + 0x8c) = uVar1;
    uVar1 = ((uint (*)())FUN_0004a7d0)(param_2);
    *(undefined4 *)(param_5 + 0x90) = uVar1;
    uVar1 = ((uint (*)())FUN_0004a7d0)(param_3);
    *(undefined4 *)(param_5 + 0x94) = uVar1;
    uVar1 = ((uint (*)())FUN_0004a7d0)(param_4);
    *(undefined4 *)(param_5 + 0x98) = uVar1;
  }
  else {
    param_5 = param_6 * 0x10 + param_5;
    *(float *)(param_5 + 0x98) = (float)param_4;
    *(float *)(param_5 + 0x8c) = (float)param_1;
    *(float *)(param_5 + 0x90) = (float)param_2;
    *(float *)(param_5 + 0x94) = (float)param_3;
  }
  return;
}

/* FUN_000b5010 @ 0xb5010 (132 bytes) */
int FUN_000b5010(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int *param_3;
  int param_4;
{
  if ((param_4 < 0x100) && (((unsigned char *)0x00001658)[param_4 + param_2] != '\0')) {
    if (*(char *)(param_4 + param_2 + 0x1758) == '\0') {
      ((void (*)())FUN_000b4f50)(*param_3,*(int *)(param_4 * 4 + param_2 + 0x1a20) - *(int *)(param_2 + 0x1f1c));
      *(undefined4 *)(param_1 + 0x1e64) = 0;
      ((unsigned char *)0x000010eb)[*param_3] = 0;
    }
  }
  return;
}

/* FUN_000b50a0 @ 0xb50a0 (228 bytes) */
int FUN_000b50a0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int *param_3;
{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  fVar1 = FLOAT_001aa0e8;
  if (((unsigned char *)0x000013b1)[param_1] != '\0') {
    iVar3 = 0;
    iVar4 = param_1;
    iVar5 = param_2;
    iVar6 = param_2;
    do {
      if (((unsigned char *)0x00001618)[iVar6] != '\0') {
        iVar2 = *(int *)(((unsigned char *)0x000013f8) + iVar4);
        if (iVar2 != 0) {
          ((void (*)())FUN_000b4f50)((double)(fVar1 / *(float *)(iVar2 + 0x44)),
                       (double)(fVar1 / *(float *)(iVar2 + 0x48)),(double)*(float *)(iVar2 + 0x50),
                       (double)*(float *)(((unsigned char *)0x00001620) + iVar3 * 4 + *param_3),*param_3,
                       (*(int *)(iVar5 + 0x1ea8) - *(int *)(param_2 + 0x1f1c)) + param_3[0x36]);
        }
      }
      iVar3 = iVar3 + 1;
      iVar6 = iVar6 + 1;
      iVar4 = iVar4 + 4;
      iVar5 = iVar5 + 4;
    } while (iVar3 < (int)(uint)(byte)((unsigned char *)0x000013b1)[param_1]);
  }
  return;
}

/* FUN_000b5190 @ 0xb5190 (4 bytes) */
int FUN_000b5190()
{
  return;
}

/* FUN_000b51a0 @ 0xb51a0 (376 bytes) */
int FUN_000b51a0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 *param_3;
{
  float fVar1;
  float fVar2;
  double dVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  undefined8 uVar11;
  
  puVar5 = param_3;
  uVar11 = FUN_001a3260();
  dVar3 = DOUBLE_001aa240;
  iVar4 = *(int *)((int)((ulonglong)uVar11 >> 0x20) + 4);
  iVar6 = *(int *)(iVar4 + 0x10);
  if (*(char *)((int)uVar11 + 0x1e2f) != '\0') {
    fVar1 = *(float *)(iVar4 + 0x2a58);
    fVar2 = *(float *)(iVar4 + 0x2a54);
    dVar9 = (double)CONCAT44(0x43300000,*(uint *)(iVar6 + 0x1840) ^ 0x80000000) - DOUBLE_001aa1e0;
    dVar10 = (double)CONCAT44(0x43300000,*(uint *)(iVar6 + 0x1844) ^ 0x80000000) - DOUBLE_001aa1e0;
    dVar8 = (double)(fVar2 * (float)((double)CONCAT44(0x43300000,
                                                      *(uint *)(iVar6 + 0x1848) ^ 0x80000000) -
                                    DOUBLE_001aa1e0) * FLOAT_001aa10c);
    dVar7 = (double)(fVar1 * (float)((double)CONCAT44(0x43300000,
                                                      *(uint *)(iVar6 + 0x184c) ^ 0x80000000) -
                                    DOUBLE_001aa1e0) * FLOAT_001aa10c);
    ((void (*)())FUN_000b4f50)(dVar8,dVar7,
                 (double)(float)((*(double *)(iVar6 + 0x1838) - *(double *)(FUN_00001830 + iVar6)) *
                                DOUBLE_001aa240),(double)FLOAT_001aa0d4,*puVar5,
                 puVar5[0x2e] - *(int *)((int)uVar11 + 0x1f1c));
    ((void (*)())FUN_000b4f50)((double)(float)((double)(fVar2 * (float)dVar9) + dVar8),
                 (double)(float)((double)(fVar1 * (float)dVar10) + dVar7),
                 (double)(float)((*(double *)(iVar6 + 0x1838) + *(double *)(FUN_00001830 + iVar6)) *
                                dVar3),(double)FLOAT_001aa0d4,*param_3,
                 param_3[0x2f] - *(int *)(param_2 + 0x1f1c));
    *(undefined4 *)(param_1 + 0x1e64) = 0;
  }
  return;
}

/* FUN_000b5320 @ 0xb5320 (204 bytes) */
int FUN_000b5320(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 *param_3;
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (*(char *)(param_2 + 0x1ea0) != '\0') {
    ((void (*)())FUN_000b4f50)(-(double)*(float *)(((unsigned char *)0x00002dfc) + iVar1),
                 (double)(float)((double)*(float *)(((unsigned char *)0x00002dfc) + iVar1) *
                                (double)*(float *)(((unsigned char *)0x00002df8) + iVar1)),
                 (double)(float)((double)*(float *)(((unsigned char *)0x00002df0) + iVar1) / DOUBLE_001aa268),
                 (double)(float)((double)*(float *)(((unsigned char *)0x00002df0) + iVar1) / DOUBLE_001aa270),
                 *param_3,param_3[0x38] - *(int *)(param_2 + 0x1f1c));
    ((void (*)())FUN_000b4f50)((double)*(float *)(((unsigned char *)0x00002de0) + iVar1),(double)*(float *)(((unsigned char *)0x00002de4) + iVar1)
                 ,(double)*(float *)(((unsigned char *)0x00002de8) + iVar1),(double)FLOAT_001aa0d4,*param_3,
                 param_3[0x39] - *(int *)(param_2 + 0x1f1c));
    *(undefined4 *)(param_1 + 0x1e64) = 0;
  }
  return;
}

/* FUN_000b53f0 @ 0xb53f0 (4 bytes) */
int FUN_000b53f0()
{
  return;
}

/* FUN_000b5400 @ 0xb5400 (928 bytes) */
int FUN_000b5400(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  uint *puVar6;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uVar7;
  uint *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  
  iVar9 = *(int *)(param_2 + 0x14);
  iVar10 = *(int *)(((unsigned char *)0x00004024) + iVar9);
  puVar5 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar5;
  iVar11 = iVar10 * 4;
  puVar5[1] = 0;
  *puVar5 = 0x8a1;
  iVar4 = *(int *)(FUN_00002748 + param_1 + 4);
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
  *(int *)(FUN_00002748 + param_1 + 4) = iVar4 + 8;
  (*UNRECOVERED_JUMPTABLE)(param_1,iVar4 + 8);
  puVar5 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,6);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar5;
  *puVar5 = 0x208b4;
  puVar5[1] = *(undefined4 *)(param_1 + 0x1b90);
  puVar5[2] = *(undefined4 *)(param_1 + 0x1b8c);
  uVar7 = *(undefined4 *)(param_1 + 0x1b94);
  puVar5[4] = 0x820;
  puVar5[3] = uVar7;
  puVar5[5] = *(undefined4 *)(param_1 + 0x1b7c);
  iVar4 = *(int *)(FUN_00002748 + param_1 + 4);
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
  *(int *)(FUN_00002748 + param_1 + 4) = iVar4 + 0x18;
  (*UNRECOVERED_JUMPTABLE)(param_1,iVar4 + 0x18);
  puVar5 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar5;
  *puVar5 = 0x8b7;
  puVar5[1] = *(undefined4 *)(param_1 + 0x1b98);
  iVar4 = *(int *)(FUN_00002748 + param_1 + 4);
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
  *(int *)(FUN_00002748 + param_1 + 4) = iVar4 + 8;
  (*UNRECOVERED_JUMPTABLE)(param_1,iVar4 + 8);
  puVar5 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,iVar11 + 3);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar5;
  *puVar5 = 0x880;
  uVar3 = *(uint *)(((unsigned char *)0x0000548c) + iVar9);
  puVar5[2] = (iVar11 + -1) * 0x10000 | 0x8882;
  puVar5[1] = uVar3 & 0x3ff;
  _memcpy(puVar5 + 3,(void *)(iVar9 + 0x24),*(int *)(((unsigned char *)0x00004024) + iVar9) << 4);
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
  iVar11 = iVar10 * 0x10 + *(int *)(FUN_00002748 + param_1 + 4) + 0xc;
  *(int *)(FUN_00002748 + param_1 + 4) = iVar11;
  (*UNRECOVERED_JUMPTABLE)(param_1,iVar11);
  puVar5 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0x15);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar5;
  *puVar5 = 0x82d;
  iVar9 = 8;
  uVar7 = *(undefined4 *)(param_1 + 0x1ca4);
  puVar5[2] = 0x861;
  puVar5[1] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1ca0);
  puVar5[4] = 0x824;
  puVar5[3] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1b9c);
  puVar5[6] = 0x825;
  puVar5[5] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1ba0);
  puVar5[8] = ((unsigned char *)0x000010c0);
  puVar5[7] = uVar7;
  puVar5[9] = *(undefined4 *)(param_1 + 0x1f2c);
  puVar5[10] = *(uint *)(param_1 + 0x1f28) | 0x70000;
  iVar11 = 0;
  iVar4 = param_1;
  do {
    puVar1 = (undefined4 *)(iVar4 + 0x1ee8);
    iVar4 = iVar4 + 4;
    *(undefined4 *)((int)puVar5 + iVar11 + 0x2c) = *puVar1;
    iVar9 = iVar9 + -1;
    iVar11 = iVar11 + 4;
  } while (iVar9 != 0);
  puVar5[0x13] = ((unsigned char *)0x00001047);
  puVar5[0x14] = *(undefined4 *)(param_1 + 0x1bb0);
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
  *(int *)(FUN_00002748 + param_1 + 4) = *(int *)(FUN_00002748 + param_1 + 4) + 0x54;
  (*UNRECOVERED_JUMPTABLE)(param_1);
  if (*(int *)(param_1 + 0x243c) != 0) {
    uVar2 = *(int *)(param_1 + 0x243c) + 1U >> 1;
    puVar6 = (uint *)(**(code **)(param_1 + 0x2758))(param_1,uVar2 * 2 + 2);
    *(uint **)(FUN_00002748 + param_1 + 4) = puVar6;
    puVar8 = puVar6 + 1;
    uVar3 = (uVar2 - 1) * 0x10000;
    *puVar6 = uVar3 | 0x854;
    if (uVar2 != 0) {
      iVar11 = 0;
      uVar12 = uVar2;
      do {
        iVar4 = iVar11 * 4;
        iVar11 = iVar11 + 1;
        *puVar8 = *(uint *)(iVar4 + *(int *)(param_1 + 0x2440));
        puVar8 = puVar8 + 1;
        uVar12 = uVar12 - 1;
      } while (uVar12 != 0);
    }
    *puVar8 = uVar3 | 0x878;
    if (uVar2 != 0) {
      iVar11 = 0;
      uVar3 = uVar2;
      do {
        *(undefined4 *)((int)puVar8 + iVar11 + 4) =
             *(undefined4 *)(iVar11 + *(int *)(param_1 + 0x2444));
        iVar11 = iVar11 + 4;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
    }
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
    *(uint *)(FUN_00002748 + param_1 + 4) = uVar2 * 8 + *(int *)(FUN_00002748 + param_1 + 4) + 8;
                    
                    
    (*UNRECOVERED_JUMPTABLE)(param_1);
    return;
  }
  return;
}

/* FUN_000b57a0 @ 0xb57a0 (688 bytes) */
int FUN_000b57a0(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  
  if (*(int *)(param_2 + 0x14) != 0) {
    (**(code **)(param_1 + 0x18))();
  }
  puVar4 = (undefined4 *)(**(code **)(param_1 + 0xc))(0x569c);
  *(undefined4 **)(param_2 + 0x14) = puVar4;
  puVar4[2] = 0;
  iVar5 = 0xe;
  *puVar4 = *(undefined4 *)(param_2 + 0xc);
  puVar4[1] = *(undefined4 *)(param_2 + 4);
  puVar4[3] = *(undefined4 *)(param_1 + 0x2454);
  puVar4[4] = *(undefined4 *)(param_1 + 0x2454);
  uVar1 = *(uint *)(param_1 + 0x44);
  puVar4[8] = 1;
  puVar4[7] = 1;
  puVar4[6] = uVar1 >> 7 & 1;
  if (*(char *)(param_1 + 0x1869) != '\0') {
    puVar7 = puVar4 + 9;
    iVar5 = FUN_000c8e50(param_1,puVar4,puVar7);
    if (iVar5 == 0) {
      iVar5 = puVar4[0x150b];
      *(undefined1 *)((int)puVar4 + 0x5497) = 0;
      iVar9 = puVar4[0x1009];
      *(char *)((int)puVar4 + 0x5495) = (char)iVar5;
      uVar1 = (iVar9 + -1) * 0x100000 & 0x3ff00000U | puVar4[0x1523] & 0xc00ffc00;
      puVar4[0x1523] = uVar1;
      if (*(int *)(((unsigned char *)0x00001240) + param_2) < (int)puVar4[0x1590]) {
        *(undefined4 *)(((unsigned char *)0x00001240) + param_2) = puVar4[0x1590];
        uVar1 = puVar4[0x1523];
        iVar9 = puVar4[0x1009];
        iVar5 = puVar4[0x150b];
      }
      uVar3 = 0;
      iVar8 = iVar9;
      if (iVar9 != 0) {
        do {
          uVar3 = puVar7[iVar8 * 4 + -4] & 0xf00;
          if (((uVar3 == 0x200) || (uVar3 == 0x300)) && ((puVar7[iVar8 * 4 + -4] & 0xfe000) == 0)) {
            uVar3 = iVar8 - 1;
          }
          else {
            uVar3 = 0;
          }
        } while ((iVar8 + -1 != 0) && (iVar8 = iVar8 + -1, uVar3 == 0));
        uVar3 = uVar3 & 0xffff;
      }
      uVar6 = 0;
      puVar4[0x1523] = (uVar3 & 0x3ff) << 10 | uVar1 & 0xfff003ff;
      if (iVar9 != 0) {
        puVar7 = puVar7 + iVar9 * 4;
        do {
          if ((((puVar7[-3] & 7) == 1) || ((puVar7[-2] & 7) == 1)) || ((puVar7[-1] & 7) == 1)) {
            uVar6 = iVar9 - 1;
          }
          else {
            uVar6 = 0;
          }
          iVar9 = iVar9 + -1;
        } while ((iVar9 != 0) && (puVar7 = puVar7 + -4, uVar6 == 0));
      }
      *(int *)(((unsigned char *)0x00001038) + param_2) = iVar5;
      if (0 < iVar5) {
        pcVar10 = (char *)(puVar4 + 0x100e);
        puVar7 = puVar4 + 0x100a;
        iVar8 = 0;
        iVar9 = param_2;
        do {
          if (*pcVar10 != '\0') {
            iVar2 = *(int *)(((unsigned char *)0x00001240) + param_2);
            *(undefined4 *)(iVar9 + 0x18) = *puVar7;
            *(undefined4 *)(iVar9 + 0x1c) = puVar7[1];
            *(undefined4 *)(iVar9 + 0x20) = puVar7[2];
            *(undefined4 *)(iVar9 + 0x24) = puVar7[3];
            if (iVar2 < iVar8) {
              *(int *)(((unsigned char *)0x00001240) + param_2) = iVar8;
            }
          }
          iVar8 = iVar8 + 1;
          pcVar10 = pcVar10 + 0x14;
          puVar7 = puVar7 + 5;
          iVar9 = iVar9 + 0x10;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
      iVar5 = 0;
      puVar4[0x1524] = uVar6 & 0x3ff | puVar4[0x1524] & 0xfffffc00;
      *(undefined1 *)(param_2 + 1) = 1;
    }
  }
  return iVar5;
}

/* FUN_000b5a60 @ 0xb5a60 (244 bytes) */
int FUN_000b5a60(param_1, param_2)
  int param_1;
  int param_2;
{
  byte bVar1;
  int iVar2;
  code *pcVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = *(int *)(param_2 + 0x14);
  iVar7 = *(int *)(((unsigned char *)0x00005428) + iVar6);
  if (*(int *)(((unsigned char *)0x00001240) + param_2) + 1 < *(int *)(((unsigned char *)0x00005428) + iVar6)) {
    iVar7 = *(int *)(((unsigned char *)0x00001240) + param_2) + 1;
  }
  iVar2 = iVar7 * 4;
  if (iVar2 != 0) {
    puVar4 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,iVar2 + 5);
    *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar4;
    *puVar4 = 0x8a1;
    puVar4[1] = 0;
    puVar4[2] = 0x880;
    bVar1 = ((unsigned char *)0x00005497)[iVar6];
    iVar5 = *(int *)(param_1 + 0x2448);
    puVar4[4] = (iVar2 + -1) * 0x10000 | 0x8882;
    puVar4[3] = (uint)bVar1 + iVar5;
    _memcpy(puVar4 + 5,(void *)(param_2 + 0x18),iVar7 * 0x10);
    pcVar3 = *(code **)(param_1 + 0x275c);
    iVar7 = iVar7 * 0x10 + *(int *)(FUN_00002748 + param_1 + 4) + 0x14;
    *(int *)(FUN_00002748 + param_1 + 4) = iVar7;
    (*pcVar3)(param_1,iVar7);
  }
  ((unsigned char *)0x00005495)[iVar6] = (char)*(undefined4 *)(((unsigned char *)0x00001038) + param_2);
  return;
}

/* FUN_000b5b60 @ 0xb5b60 (64 bytes) */
int FUN_000b5b60(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_000b5400)();
  ((int (*)())FUN_000b5a60)(param_1,param_2);
  return 0;
}

/* FUN_000b5ba0 @ 0xb5ba0 (36 bytes) */
int FUN_000b5ba0()
{
  ((int (*)())FUN_000b5400)();
  return 0;
}

/* FUN_000b5bd0 @ 0xb5bd0 (36 bytes) */
int FUN_000b5bd0()
{
  ((int (*)())FUN_000b5a60)();
  return 0;
}

/* FUN_000b5c00 @ 0xb5c00 (828 bytes) */
int FUN_000b5c00(param_1, param_2, param_3)
  int param_1;
  uint *param_2;
  undefined4 param_3;
{
  char cVar1;
  byte bVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  
  uVar4 = 0;
  if (*(char *)(param_1 + 0x3d4) == '\0') {
    cVar1 = *(char *)(param_1 + 0x124);
    *(uint **)(((unsigned char *)0x0000148c) + param_1) = param_2;
    if ((cVar1 == '\0') || ((*(uint *)(param_1 + 0x44) & 0x100000) == 0)) {
      *(uint **)(((unsigned char *)0x0000148c) + param_1) = param_2;
    }
    uVar4 = 1;
    if (param_2[1] != 0) {
      if ((*param_2 & 0xffff00) == 0) {
        ((int (*)())FUN_000b57a0)(param_1,param_2);
        if (*(char *)((int)param_2 + 1) == '\0') {
          *(undefined1 *)((int)param_2 + 2) = 1;
        }
        else {
          *(undefined1 *)((int)param_2 + 2) = 0;
        }
      }
      uVar10 = param_2[5];
      iVar7 = 0;
      iVar11 = 0x16;
      puVar5 = (undefined4 *)(((unsigned char *)0x000055e8) + uVar10);
      do {
        uVar4 = *puVar5;
        puVar5 = puVar5 + 1;
        *(undefined4 *)(*(int *)(param_1 + 0x1864) + iVar7) = uVar4;
        iVar7 = iVar7 + 4;
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
      *(undefined4 *)(param_1 + 0x1b90) = *(undefined4 *)(((unsigned char *)0x0000548c) + uVar10);
      *(undefined4 *)(param_1 + 0x1b94) = *(undefined4 *)(((unsigned char *)0x00005490) + uVar10);
      *(undefined4 *)(param_1 + 0x1b8c) = *(undefined4 *)(((unsigned char *)0x00005494) + uVar10);
      *(undefined4 *)(param_1 + 0x1b98) = *(undefined4 *)(((unsigned char *)0x000054a4) + uVar10);
      FUN_00050ef0(param_1,param_3,*(undefined4 *)(((unsigned char *)0x00005434) + uVar10),
                   *(undefined4 *)(((unsigned char *)0x00005438) + uVar10));
      uVar8 = *(uint *)(param_1 + 0x44);
      *(undefined4 *)(param_1 + 0x1b9c) = *(undefined4 *)(((unsigned char *)0x00005498) + uVar10);
      *(undefined4 *)(param_1 + 0x1ba0) = *(undefined4 *)(((unsigned char *)0x0000549c) + uVar10);
      if ((uVar8 & 0x100000) == 0) {
        iVar7 = *(int *)(*(int *)(param_1 + 4) + 0x10);
        *(undefined4 *)(param_1 + 0x1ca0) = 1;
        if ((int)uVar8 < 0) {
          uVar6 = 3;
          *(undefined4 *)(param_1 + 0x1ca0) = 3;
          if ("}J3x})+x|B;x}k"[iVar7 + 3] != '\0') {
            uVar6 = 7;
            *(undefined4 *)(param_1 + 0x1ca0) = 7;
          }
        }
        else {
          uVar3 = *(uint *)(param_1 + 0x8c);
          if (((uVar3 >> 0x14 & 1) != 0 || (uVar3 >> 0x1a & 1) != 0) || (uVar3 >> 0x1b & 1) != 0) {
            *(undefined4 *)(param_1 + 0x1ca0) = 3;
          }
          uVar3 = *(uint *)(param_1 + 0x1ca0);
          uVar6 = uVar3 | 4;
          *(uint *)(param_1 + 0x1ca0) = uVar6;
          if ((uVar8 & 0xa10000) != 0) {
            uVar6 = uVar3 | 0xc;
            *(uint *)(param_1 + 0x1ca0) = uVar6;
          }
        }
        if (((uVar8 & 0x1000800) != 0) && (*(short *)(((unsigned char *)0x00002e06) + iVar7) == -0x7baf)) {
          uVar6 = uVar6 | 0x40000;
          *(uint *)(param_1 + 0x1ca0) = uVar6;
        }
        if (((unsigned char *)0x00004301)[iVar7] != '\0') {
          uVar6 = uVar6 | 0x80000;
          *(uint *)(param_1 + 0x1ca0) = uVar6;
        }
        if ((uVar8 & 0x20000) == 0) {
          uVar8 = (uint)(byte)((unsigned char *)0x000013b0)[param_1];
          if ((uint)*(byte *)(param_1 + 0x2b) <= (uint)(byte)((unsigned char *)0x000013b0)[param_1]) {
            uVar8 = (uint)*(byte *)(param_1 + 0x2b);
          }
          if (uVar8 != 0) {
            iVar9 = 0;
            iVar7 = param_1;
            iVar11 = param_1;
            do {
              if ((((unsigned char *)0x00001438)[iVar7] != '\0') && (*(int *)(((unsigned char *)0x000013f8) + iVar11) != 0)) {
                uVar6 = 1 << (iVar9 + 10U & 0x3f) | uVar6;
                *(uint *)(param_1 + 0x1ca0) = uVar6;
              }
              iVar9 = iVar9 + 1;
              iVar7 = iVar7 + 1;
              iVar11 = iVar11 + 4;
              uVar8 = uVar8 - 1;
            } while (uVar8 != 0);
          }
        }
        else {
          if ((uVar8 & 0x2000) == 0) {
            bVar2 = ((unsigned char *)0x00001135)[param_1];
          }
          else {
            bVar2 = ((unsigned char *)0x000011d3)[param_1];
          }
          uVar8 = (uint)(byte)((unsigned char *)0x000013b0)[param_1];
          if (uVar8 != 0) {
            uVar3 = 0;
            if (uVar8 == 0) {
              uVar8 = 1;
            }
            do {
              if (((uint)bVar2 & 1 << (uVar3 & 0x3f)) != 0) {
                uVar6 = 1 << (uVar3 + 10 & 0x3f) | uVar6;
                *(uint *)(param_1 + 0x1ca0) = uVar6;
              }
              uVar3 = uVar3 + 1;
              uVar8 = uVar8 - 1;
            } while (uVar8 != 0);
          }
        }
        *(uint *)(((unsigned char *)0x00005444) + uVar10) = uVar6;
      }
      (**(code **)(((unsigned char *)0x00001334) + param_1))(param_1,1);
      *(undefined4 *)(uVar10 + 0x5650) = *(undefined4 *)(param_1 + 0x1ba4);
      *(undefined4 *)(uVar10 + 0x5658) = *(undefined4 *)(param_1 + 0x1b50);
      if ((*(char *)(param_1 + 0x124) == '\0') && ((*(uint *)(param_1 + 0x44) & 0x100000) == 0)) {
        (**(code **)(((unsigned char *)0x00001340) + param_1))(param_1);
        FUN_0008fc70(param_1);
      }
      ((int (*)())FUN_000b5400)(param_1,param_2);
      ((int (*)())FUN_000b5a60)(param_1,param_2);
      uVar4 = 0;
    }
  }
  return uVar4;
}

/* FUN_000b5f40 @ 0xb5f40 (100 bytes) */
int FUN_000b5f40(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  void *pvVar1;
  
  pvVar1 = *(void **)(param_2 + 0x14);
  if (pvVar1 != (void *)0x0) {
    if (*(int *)((int)pvVar1 + 0x5648) != 0) {
      FUN_000c71e0(*(int *)((int)pvVar1 + 0x5648));
      pvVar1 = *(void **)(param_2 + 0x14);
    }
    _free(pvVar1);
    *(undefined4 *)(param_2 + 0x14) = 0;
  }
  return 0;
}

/* FUN_000b5fb0 @ 0xb5fb0 (100 bytes) */
int FUN_000b5fb0(param_1)
  int param_1;
{
  code *pcVar1;
  int iVar2;
  
  iVar2 = param_1;
  do {
    if (*(int *)(((unsigned char *)0x00001448) + iVar2) != 0) {
      pcVar1 = *(code **)(((unsigned char *)0x00001224) + param_1);
      *(undefined4 *)(((unsigned char *)0x00001448) + iVar2) = 0;
      (*pcVar1)(param_1);
    }
    iVar2 = iVar2 + 4;
  } while (iVar2 != param_1 + 0x10);
  return;
}

/* FUN_000b6020 @ 0xb6020 (1360 bytes) */
int FUN_000b6020(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint param_3;
{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  void *pvVar5;
  uint uVar6;
  int iVar7;
  code *pcVar8;
  uint *puVar9;
  uint uVar10;
  
  iVar7 = param_3 * 4 + param_1;
  if (*(int *)(((unsigned char *)0x00001448) + iVar7) == 0) {
    pcVar8 = *(code **)(param_1 + 0x10);
    uVar3 = (**(code **)(((unsigned char *)0x00001284) + param_1))();
    iVar4 = (*pcVar8)(1,uVar3);
    puVar9 = (uint *)(iVar4 + 4);
    *(int *)(((unsigned char *)0x00001448) + iVar7) = iVar4;
    *(undefined4 *)(iVar4 + 4) = 0;
    *(undefined4 *)(iVar4 + 0xc) = 0;
    *(undefined4 *)(iVar4 + 8) = 0;
    pvVar5 = (void *)(**(code **)(param_1 + 0xc))(0x200);
    if (*(void **)(iVar4 + 0xc) != (void *)0x0) {
      _memcpy(pvVar5,*(void **)(iVar4 + 0xc),*(int *)(iVar4 + 4) << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar4 + 0xc));
    }
    *(void **)(iVar4 + 0xc) = pvVar5;
    *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + 0x80;
    *(undefined4 *)(*(int *)(iVar4 + 4) * 4 + (int)pvVar5) = 1;
    uVar2 = *(int *)(iVar4 + 4) + 1;
    *(uint *)(iVar4 + 4) = uVar2;
    if (*(uint *)(iVar4 + 8) <= uVar2) {
      pvVar5 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(iVar4 + 8) * 4 + 0x200);
      if (*(void **)(iVar4 + 0xc) != (void *)0x0) {
        _memcpy(pvVar5,*(void **)(iVar4 + 0xc),*(int *)(iVar4 + 4) << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar4 + 0xc));
      }
      *(void **)(iVar4 + 0xc) = pvVar5;
      *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + 0x80;
    }
    *(undefined4 *)(*puVar9 * 4 + *(int *)(iVar4 + 0xc)) = 0x10200;
    uVar2 = *puVar9 + 1;
    *puVar9 = uVar2;
    if (*(uint *)(iVar4 + 8) <= uVar2) {
      pvVar5 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(iVar4 + 8) * 4 + 0x200);
      if (*(void **)(iVar4 + 0xc) != (void *)0x0) {
        _memcpy(pvVar5,*(void **)(iVar4 + 0xc),*puVar9 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar4 + 0xc));
      }
      *(void **)(iVar4 + 0xc) = pvVar5;
      uVar2 = *puVar9;
      *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + 0x80;
    }
    *(undefined4 *)(uVar2 * 4 + *(int *)(iVar4 + 0xc)) = 0x1ff0016;
    uVar2 = *puVar9 + 1;
    *puVar9 = uVar2;
    if (*(uint *)(iVar4 + 8) <= uVar2) {
      pvVar5 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(iVar4 + 8) * 4 + 0x200);
      if (*(void **)(iVar4 + 0xc) != (void *)0x0) {
        _memcpy(pvVar5,*(void **)(iVar4 + 0xc),*puVar9 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar4 + 0xc));
      }
      *(void **)(iVar4 + 0xc) = pvVar5;
      uVar2 = *puVar9;
      *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + 0x80;
    }
    *(undefined4 *)(uVar2 * 4 + *(int *)(iVar4 + 0xc)) = 0x120000;
    uVar2 = *puVar9 + 1;
    *puVar9 = uVar2;
    if (param_2 == 0) {
      uVar3 = 0x47;
    }
    else {
      uVar3 = 0xe;
    }
    uVar10 = 0;
    uVar6 = 0x170000;
    do {
      if ((param_3 & 1 << (uVar10 & 0x3f)) != 0) {
        uVar6 = uVar10 & 0xffff | uVar6 & 0xffff0000;
        if (*(uint *)(iVar4 + 8) <= uVar2) {
          pvVar5 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(iVar4 + 8) * 4 + 0x200);
          if (*(void **)(iVar4 + 0xc) != (void *)0x0) {
            _memcpy(pvVar5,*(void **)(iVar4 + 0xc),*puVar9 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar4 + 0xc));
          }
          *(void **)(iVar4 + 0xc) = pvVar5;
          uVar2 = *puVar9;
          *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + 0x80;
        }
        *(undefined4 *)(uVar2 * 4 + *(int *)(iVar4 + 0xc)) = uVar3;
        uVar2 = *puVar9 + 1;
        *puVar9 = uVar2;
        if (*(uint *)(iVar4 + 8) <= uVar2) {
          pvVar5 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(iVar4 + 8) * 4 + 0x200);
          if (*(void **)(iVar4 + 0xc) != (void *)0x0) {
            _memcpy(pvVar5,*(void **)(iVar4 + 0xc),*puVar9 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar4 + 0xc));
          }
          *(void **)(iVar4 + 0xc) = pvVar5;
          uVar2 = *puVar9;
          *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + 0x80;
        }
        *(uint *)(uVar2 * 4 + *(int *)(iVar4 + 0xc)) = uVar6;
        uVar2 = *puVar9 + 1;
        *puVar9 = uVar2;
        if (*(uint *)(iVar4 + 8) <= uVar2) {
          pvVar5 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(iVar4 + 8) * 4 + 0x200);
          if (*(void **)(iVar4 + 0xc) != (void *)0x0) {
            _memcpy(pvVar5,*(void **)(iVar4 + 0xc),*puVar9 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar4 + 0xc));
          }
          *(void **)(iVar4 + 0xc) = pvVar5;
          uVar2 = *puVar9;
          *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + 0x80;
        }
        *(undefined4 *)(uVar2 * 4 + *(int *)(iVar4 + 0xc)) = 0x120000;
        uVar2 = *puVar9 + 1;
        *puVar9 = uVar2;
      }
      bVar1 = uVar10 != 3;
      uVar10 = uVar10 + 1;
    } while (bVar1);
    if (*(uint *)(iVar4 + 8) <= uVar2) {
      pvVar5 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(iVar4 + 8) * 4 + 0x200);
      if (*(void **)(iVar4 + 0xc) != (void *)0x0) {
        _memcpy(pvVar5,*(void **)(iVar4 + 0xc),*puVar9 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar4 + 0xc));
      }
      *(void **)(iVar4 + 0xc) = pvVar5;
      uVar2 = *puVar9;
      *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + 0x80;
    }
    *(undefined4 *)(uVar2 * 4 + *(int *)(iVar4 + 0xc)) = 0x28;
    *puVar9 = *puVar9 + 1;
                    
                    
    (**(code **)(((unsigned char *)0x00001288) + param_1))(param_1,0,iVar4,puVar9);
    return;
  }
  return;
}

/* FUN_000b6580 @ 0xb6580 (2448 bytes) */
int FUN_000b6580(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  bool bVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  void *pvVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  uint uVar12;
  short *psVar13;
  uint *puVar14;
  uint uVar15;
  int iVar16;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  uint local_5c;
  uint local_58;
  undefined4 local_54;
  undefined4 local_50;
  
  bVar1 = param_2 == 0;
  iVar11 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (bVar1) {
    iVar6 = FUN_0004bbf0();
    if (iVar6 == 0) goto LAB_000b66b8;
    iVar6 = *(int *)(param_1 + 0x1e5c);
    if ((*(int *)(((unsigned char *)0x000036c0) + iVar6) == 0) ||
       (*(int *)(((unsigned char *)0x00001488) + param_1) != *(int *)(((unsigned char *)0x000036c0) + iVar6))) {
      if (*(char *)(param_1 + 0x1868) == '\0') {
        (**(code **)(((unsigned char *)0x00001334) + param_1))(param_1,0);
      }
      FUN_0004ac90(param_1);
      iVar6 = *(int *)(param_1 + 0x1e5c);
      if (*(int *)(((unsigned char *)0x000036c0) + iVar6) == 0) {
        *(undefined4 *)(((unsigned char *)0x00001488) + param_1) = 0;
      }
      else {
        *(int *)(((unsigned char *)0x00001488) + param_1) = *(int *)(((unsigned char *)0x000036c0) + iVar6);
      }
      ((unsigned char *)0x000010eb)[iVar6] = 0;
      *(undefined4 *)(((unsigned char *)0x00001300) + *(int *)(param_1 + 0x1e5c)) = 0;
      **(undefined4 **)(param_1 + 0x1e5c) = 0;
      iVar6 = *(int *)(param_1 + 0x1e5c);
    }
    *(undefined4 *)(((unsigned char *)0x000010e4) + iVar6) = 0xffffffff;
    if (*(int *)(param_1 + 0x23e0) == 0) {
      return;
    }
    iVar6 = *(int *)(param_1 + 0x1e5c);
    if (((unsigned char *)0x000036c4)[iVar6] != '\0') {
      ((unsigned char *)0x000010eb)[iVar6] = 0;
      *(undefined4 *)(((unsigned char *)0x0000152c) + *(int *)(param_1 + 0x1e5c)) = 0;
      *(undefined4 *)(*(int *)(param_1 + 0x1e5c) + 0x1c) = 0;
      return;
    }
    bVar1 = false;
  }
  else {
    iVar6 = *(int *)(param_1 + 0x1e5c);
  }
  ((unsigned char *)0x000036c4)[iVar6] = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x1e5c) + 0x1c) = 0;
LAB_000b66b8:
  *(undefined4 *)(((unsigned char *)0x000010e4) + *(int *)(param_1 + 0x1e5c)) = 0xffffffff;
  puVar7 = (undefined1 *)(**(code **)(param_1 + 0xc))(((unsigned char *)0x00003880));
  iVar6 = *(int *)(param_1 + 0x1e5c);
  if (*(int *)(((unsigned char *)0x000036c0) + iVar6) != 0) {
    pvVar8 = *(void **)(*(int *)(((unsigned char *)0x000036c0) + iVar6) + 0xc);
    if (pvVar8 != (void *)0x0) {
      _free(pvVar8);
      *(undefined4 *)(*(int *)(((unsigned char *)0x000036c0) + *(int *)(param_1 + 0x1e5c)) + 0xc) = 0;
      iVar6 = *(int *)(param_1 + 0x1e5c);
    }
    _free(*(void **)(((unsigned char *)0x000036c0) + iVar6));
    iVar6 = *(int *)(param_1 + 0x1e5c);
  }
  *(undefined1 **)(((unsigned char *)0x000036c0) + iVar6) = puVar7;
  puVar14 = (uint *)(puVar7 + 4);
  **(undefined4 **)(param_1 + 0x1e5c) = 0;
  *puVar7 = 0;
  uVar4 = *(uint *)(param_1 + 0x18a4);
  *(undefined4 *)(puVar7 + 4) = 0;
  *(uint *)(puVar7 + 0x1668) = uVar4 & 0x3fffc0 | *(uint *)(puVar7 + 0x1668) & 0xffc0003f;
  *(undefined4 *)(puVar7 + 0xc) = 0;
  *(undefined4 *)(puVar7 + 8) = 0;
  pvVar8 = (void *)(**(code **)(param_1 + 0xc))(0x200);
  if (*(void **)(puVar7 + 0xc) != (void *)0x0) {
    _memcpy(pvVar8,*(void **)(puVar7 + 0xc),*(int *)(puVar7 + 4) << 2);
    (**(code **)(param_1 + 0x18))(*(undefined4 *)(puVar7 + 0xc));
  }
  *(void **)(puVar7 + 0xc) = pvVar8;
  *(int *)(puVar7 + 8) = *(int *)(puVar7 + 8) + 0x80;
  *(undefined4 *)(*(int *)(puVar7 + 4) * 4 + (int)pvVar8) = 1;
  iVar6 = *(int *)(puVar7 + 4);
  *(uint *)(puVar7 + 4) = iVar6 + 1U;
  if (*(uint *)(puVar7 + 8) <= iVar6 + 1U) {
    pvVar8 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(puVar7 + 8) * 4 + 0x200);
    if (*(void **)(puVar7 + 0xc) != (void *)0x0) {
      _memcpy(pvVar8,*(void **)(puVar7 + 0xc),*(int *)(puVar7 + 4) << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(puVar7 + 0xc));
    }
    *(void **)(puVar7 + 0xc) = pvVar8;
    *(int *)(puVar7 + 8) = *(int *)(puVar7 + 8) + 0x80;
  }
  iVar6 = 0;
  *(undefined4 *)(*puVar14 * 4 + *(int *)(puVar7 + 0xc)) = 0x10200;
  iVar16 = 0x14;
  *puVar14 = *puVar14 + 1;
  do {
    iVar5 = iVar6 + *(int *)(param_1 + 0x1e5c);
    iVar6 = iVar6 + 1;
    ((unsigned char *)0x00002ddc)[iVar5] = 1;
    iVar16 = iVar16 + -1;
  } while (iVar16 != 0);
  uVar4 = (uint)*(byte *)(param_1 + 0x2b);
  if ((uint)(byte)((unsigned char *)0x000013b2)[param_1] < (uint)*(byte *)(param_1 + 0x2b)) {
    uVar4 = (uint)(byte)((unsigned char *)0x000013b2)[param_1];
  }
  FUN_000d5900(param_1,puVar7);
  FUN_000d8450(param_1,puVar7,0);
  iVar6 = *(int *)(puVar7 + 4);
  if (uVar4 == 0) {
    uVar10 = 1;
    uVar12 = 0;
  }
  else {
    uVar15 = 0;
    uVar10 = 1;
    uVar12 = 0;
    psVar13 = (short *)(param_1 + 0x454);
    iVar16 = param_1;
    iVar5 = param_1;
    do {
      iVar9 = *(int *)(((unsigned char *)0x000013f8) + iVar5);
      if (iVar9 != 0) {
        if (*(short *)(iVar16 + 0x450) == -0x7a90) {
          if (*psVar13 != -0x7885) {
            FUN_000d6340(param_1,puVar7,*(undefined2 *)(iVar9 + 0x38),uVar15,iVar9,uVar10,uVar12);
            uVar10 = 0;
            uVar12 = uVar15;
          }
        }
        else {
          FUN_000d7520(param_1,puVar7,*(undefined2 *)(iVar9 + 0x38),*(short *)(iVar16 + 0x450),
                       uVar15,iVar9,uVar10,uVar12);
          uVar10 = 0;
          uVar12 = uVar15;
        }
      }
      uVar15 = uVar15 + 1;
      psVar13 = psVar13 + 0x66;
      iVar5 = iVar5 + 4;
      iVar16 = iVar16 + 0xcc;
    } while (uVar4 != uVar15);
  }
  uVar4 = *(uint *)(param_1 + 0x44);
  if ((uVar4 & 0x100000) == 0) {
    if ((((int)uVar4 < 0) &&
        (*(short *)("}J3x})+x|B;x}k" + *(int *)(*(int *)(param_1 + 4) + 0x10)) == -0x7e06)) ||
       (bVar2 = false, (uVar4 & 0x80800000) == 0x800000)) {
      bVar2 = true;
    }
  }
  else if (((uVar4 & 0x800000) == 0) ||
          (bVar2 = true, *(char *)(*(int *)(((unsigned char *)0x00001168) + param_1) + 0x6e) == '\0')) {
    bVar2 = false;
  }
  if ((bVar2) || ((uVar4 & 0x200000) != 0)) {
    FUN_000d55c0(param_1,puVar14,uVar10,uVar12);
  }
  if (iVar6 == *(int *)(puVar7 + 4)) {
    uVar4 = *puVar14;
    uVar12 = 0x170000;
    uVar15 = 0;
    do {
      if (((int)(*(uint *)(puVar7 + 0x1668) >> 6 & 0xffff) >> (uVar15 & 0x3f) & 1U) != 0) {
        uVar12 = uVar15 & 0xffff | uVar12 & 0xffff0000;
        if (*(uint *)(puVar7 + 8) <= uVar4) {
          pvVar8 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(puVar7 + 8) * 4 + 0x200);
          if (*(void **)(puVar7 + 0xc) != (void *)0x0) {
            _memcpy(pvVar8,*(void **)(puVar7 + 0xc),*puVar14 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(puVar7 + 0xc));
          }
          *(void **)(puVar7 + 0xc) = pvVar8;
          uVar4 = *puVar14;
          *(int *)(puVar7 + 8) = *(int *)(puVar7 + 8) + 0x80;
        }
        *(undefined4 *)(uVar4 * 4 + *(int *)(puVar7 + 0xc)) = 0x47;
        uVar4 = *puVar14 + 1;
        *puVar14 = uVar4;
        if (*(uint *)(puVar7 + 8) <= uVar4) {
          pvVar8 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(puVar7 + 8) * 4 + 0x200);
          if (*(void **)(puVar7 + 0xc) != (void *)0x0) {
            _memcpy(pvVar8,*(void **)(puVar7 + 0xc),*puVar14 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(puVar7 + 0xc));
          }
          *(void **)(puVar7 + 0xc) = pvVar8;
          uVar4 = *puVar14;
          *(int *)(puVar7 + 8) = *(int *)(puVar7 + 8) + 0x80;
        }
        *(uint *)(uVar4 * 4 + *(int *)(puVar7 + 0xc)) = uVar12;
        uVar4 = *puVar14 + 1;
        *puVar14 = uVar4;
        if (*(uint *)(puVar7 + 8) <= uVar4) {
          pvVar8 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(puVar7 + 8) * 4 + 0x200);
          if (*(void **)(puVar7 + 0xc) != (void *)0x0) {
            _memcpy(pvVar8,*(void **)(puVar7 + 0xc),*puVar14 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(puVar7 + 0xc));
          }
          *(void **)(puVar7 + 0xc) = pvVar8;
          uVar4 = *puVar14;
          *(int *)(puVar7 + 8) = *(int *)(puVar7 + 8) + 0x80;
        }
        *(undefined4 *)(uVar4 * 4 + *(int *)(puVar7 + 0xc)) = 0x120000;
        uVar4 = *puVar14 + 1;
        *puVar14 = uVar4;
      }
      bVar2 = uVar15 != 3;
      uVar15 = uVar15 + 1;
    } while (bVar2);
  }
  else {
    FUN_000d5390(param_1,puVar14,0,uVar12,*(uint *)(puVar7 + 0x1668) >> 6 & 0xffff);
    uVar4 = *puVar14;
  }
  if (*(uint *)(puVar7 + 8) <= uVar4) {
    pvVar8 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(puVar7 + 8) * 4 + 0x200);
    if (*(void **)(puVar7 + 0xc) != (void *)0x0) {
      _memcpy(pvVar8,*(void **)(puVar7 + 0xc),*puVar14 << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(puVar7 + 0xc));
    }
    *(void **)(puVar7 + 0xc) = pvVar8;
    uVar4 = *puVar14;
    *(int *)(puVar7 + 8) = *(int *)(puVar7 + 8) + 0x80;
  }
  *(undefined4 *)(uVar4 * 4 + *(int *)(puVar7 + 0xc)) = 0x28;
  *puVar14 = *puVar14 + 1;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_68 = *(undefined4 *)(puVar7 + 0xc);
  local_64 = *(undefined4 *)(puVar7 + 4);
  local_5c = 0x83;
  local_54 = 2;
  _memset((*(unsigned char *)0x00002fdc) + *(int *)(param_1 + 0x1e5c),0,0x100);
  iVar6 = 0;
  iVar16 = 0x14;
  do {
    iVar5 = iVar6 + *(int *)(param_1 + 0x1e5c);
    iVar6 = iVar6 + 1;
    ((unsigned char *)0x00002fdc)[iVar5] = 1;
    iVar16 = iVar16 + -1;
  } while (iVar16 != 0);
  *(undefined4 *)(*(int *)(param_1 + 0x1e5c) + 0x1780) = 0;
  if (!bVar1) {
    *(undefined4 *)(((unsigned char *)0x0000170c) + *(int *)(param_1 + 0x1e5c)) = *(undefined4 *)(param_1 + 0x276c);
    local_5c = local_5c | 0x100;
  }
  if (*(char *)(param_1 + 0x121) != '\0') {
    sVar3 = *(short *)(((unsigned char *)0x00002e04) + iVar11);
    if (sVar3 == 0x801) {
      local_5c = local_5c | 0xc;
    }
    else if (sVar3 == 0x2601) {
      local_5c = local_5c | 4;
    }
    else if (sVar3 == 0x800) {
      local_5c = local_5c | 8;
    }
  }
  iVar11 = *(int *)(param_1 + 0x245c);
  if (iVar11 != 0) {
    local_58 = 0;
    do {
      local_58 = local_58 << 1 | 1;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    local_5c = local_5c | 0x400;
  }
  *(undefined4 *)(((unsigned char *)0x000010d8) + *(int *)(param_1 + 0x1e5c)) = 0xff;
  iVar11 = *(int *)(param_1 + 0x1e5c);
  ((int (*)())FUN_000b4400)(param_1,iVar11 + 0x1784,((unsigned char *)0x00001660) + iVar11,&local_68,iVar11);
  (**(code **)(((unsigned char *)0x00001334) + param_1))(param_1,0);
  if ((bVar1) && (*(int *)(param_1 + 0x23e0) != 0)) {
    *(undefined4 *)(((unsigned char *)0x0000170c) + *(int *)(param_1 + 0x1e5c)) = *(undefined4 *)(param_1 + 0x276c);
    iVar11 = *(int *)(param_1 + 0x1e5c);
    local_5c = local_5c | 0x100;
    ((int (*)())FUN_000b4400)(param_1,iVar11 + 0x1784,((unsigned char *)0x00001660) + iVar11,&local_68,iVar11);
    if (*(char *)(param_1 + 0x1868) == '\0') {
      (**(code **)(((unsigned char *)0x00001334) + param_1))(param_1,0);
    }
  }
  if (*(char *)(param_1 + 0x121) != '\0') {
    iVar11 = *(int *)(param_1 + 0x1e5c);
    *(int *)(((unsigned char *)0x00003878) + *(int *)(((unsigned char *)0x000036c0) + iVar11)) =
         *(int *)(iVar11 + 0x1744) - *(int *)(((unsigned char *)0x000036a0) + iVar11);
    iVar11 = *(int *)(param_1 + 0x1e5c);
    *(int *)(((unsigned char *)0x0000387c) + *(int *)(((unsigned char *)0x000036c0) + iVar11)) =
         *(int *)(FUN_00001740 + iVar11) - *(int *)(((unsigned char *)0x000036a0) + iVar11);
    ((unsigned char *)0x00002ddc)[*(int *)(((unsigned char *)0x00003878) + *(int *)(((unsigned char *)0x000036c0) + *(int *)(param_1 + 0x1e5c))) +
     *(int *)(param_1 + 0x1e5c)] = 1;
    ((unsigned char *)0x00002ddc)[*(int *)(((unsigned char *)0x0000387c) + *(int *)(((unsigned char *)0x000036c0) + *(int *)(param_1 + 0x1e5c))) +
     *(int *)(param_1 + 0x1e5c)] = 1;
  }
  ((int (*)())FUN_000b5190)(param_1,*(int *)(param_1 + 0x1e5c) + 0x1784,
               ((unsigned char *)0x00001660) + *(int *)(param_1 + 0x1e5c));
  *(undefined1 **)(((unsigned char *)0x00001488) + param_1) = puVar7;
  FUN_0004ac90(param_1);
  return;
}

/* FUN_000b6f20 @ 0xb6f20 (928 bytes) */
int FUN_000b6f20(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  float fVar1;
  float fVar2;
  int iVar3;
  double dVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  
  dVar12 = DOUBLE_001aa1e0;
  if (param_4 == 0) {
    return;
  }
  iVar3 = param_3 * 4;
  fVar1 = *(float *)(param_2 + 0x4c);
  iVar9 = iVar3 + param_1;
  uVar8 = *(uint *)(iVar9 + 0x1cdc);
  iVar10 = *(int *)(param_1 + 4);
  fVar2 = *(float *)(param_3 * 0xcc + param_1 + 0x470);
  dVar11 = (double)FLOAT_001aa0d4;
  *(uint *)(iVar9 + 0x1d1c) = *(uint *)(iVar9 + 0x1d1c) & 0xa0705fff | 0x20100000;
  dVar4 = DOUBLE_001aa1e8;
  uVar6 = uVar8 >> 0xd & 3;
  uVar7 = 1 << (uVar8 >> 0x15 & 7);
  dVar13 = (double)(float)((double)(fVar1 + fVar2) + dVar11);
  dVar14 = (double)((float)((double)CONCAT44(0x43300000,*(uint *)(iVar10 + 0x15c) ^ 0x80000000) -
                           dVar12) / FLOAT_001aa1b4);
  dVar12 = (double)((float)((double)CONCAT44(0x43300000,*(uint *)(iVar10 + 0x160) ^ 0x80000000) -
                           dVar12) / FLOAT_001aa1b8);
  fVar1 = (float)(dVar14 - dVar12);
  if (fVar1 < 0.0) {
    dVar12 = dVar14;
  }
  if (-fVar1 < 0.0) {
    dVar14 = dVar12;
  }
  fVar1 = (float)((double)(float)(dVar14 * dVar13) * (double)FLOAT_001aa1a8 + dVar14);
  if (uVar6 == 2) {
    dVar11 = (double)(fVar1 * FLOAT_001aa1ac);
  }
  if (param_4 != 1) {
    return;
  }
  if ((uVar8 >> 0xb & 3) == 3) {
    if (3 < uVar7) {
      uVar5 = 3;
      dVar12 = (double)(float)(dVar11 * (double)FLOAT_001aa128);
      if ((dVar12 <= (double)FLOAT_001aa158) && (uVar5 = 0, (double)FLOAT_001aa0d4 <= dVar12)) {
        if (DOUBLE_001aa1e8 <= dVar12) {
          uVar5 = (int)(dVar12 - DOUBLE_001aa1e8) + 0x80000000;
        }
        else {
          uVar5 = (uint)(dVar11 * (double)FLOAT_001aa128);
        }
      }
      if (((uVar6 == 0) && ((uVar8 >> 9 & 3) == 2)) &&
         (dVar12 = (double)FLOAT_001aa0d4, dVar13 == dVar12)) {
        uVar6 = 0;
      }
      else {
        dVar14 = (double)(fVar1 * FLOAT_001aa1bc);
        dVar12 = (double)(fVar1 * FLOAT_001aa1b0 * FLOAT_001aa0f8);
        if (DOUBLE_001aa1e8 <= dVar14) {
          uVar6 = (int)(dVar14 - DOUBLE_001aa1e8) + 0x80000000;
        }
        else {
          uVar6 = (uint)(fVar1 * FLOAT_001aa1bc);
        }
      }
      goto LAB_000b7220;
    }
    if (DOUBLE_001aa1e8 <= dVar11) {
      uVar5 = (int)(dVar11 - DOUBLE_001aa1e8) + 0x80000000;
    }
    else {
      uVar5 = (uint)dVar11;
    }
  }
  else if (DOUBLE_001aa1e8 <= dVar11) {
    uVar5 = (int)(dVar11 - DOUBLE_001aa1e8) + 0x80000000;
  }
  else {
    uVar5 = (uint)dVar11;
  }
  uVar6 = 0;
  dVar12 = (double)FLOAT_001aa0d4;
LAB_000b7220:
  iVar9 = iVar3 + param_1;
  *(uint *)(iVar9 + 0x1cdc) =
       (*(uint *)(&DAT_001dbf2c + uVar7 * 4) & 7) << 0x15 | *(uint *)(iVar9 + 0x1cdc) & 0xff1fffff;
  *(uint *)(iVar9 + 0x1d1c) = (uVar5 & 3) << 0xf | *(uint *)(iVar9 + 0x1d1c) & 0xfffe7fff;
  if (dVar4 <= dVar12) {
    uVar7 = (int)(dVar12 - dVar4) + 0x80000000;
  }
  else {
    uVar7 = (uint)dVar12;
  }
  *(uint *)(iVar9 + 0x1d1c) = (uVar7 & 0x3f) << 0x17 | *(uint *)(iVar9 + 0x1d1c) & 0xe07fffff;
  *(uint *)(iVar3 + param_1 + 0x1d1c) =
       (uVar6 & 7) << 0x11 | *(uint *)(iVar3 + param_1 + 0x1d1c) & 0xfff1ffff;
  return;
}

/* FUN_000b72d0 @ 0xb72d0 (11108 bytes) */
int FUN_000b72d0(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 *param_2;
  int param_3;
  undefined1 *param_4;
  undefined1 *param_5;
  undefined1 *param_6;
  undefined1 *param_7;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  bool bVar15;
  bool bVar16;
  undefined1 uVar18;
  int iVar17;
  
  cVar4 = *(char *)((int)param_2 + 0xf);
  cVar5 = *(char *)((int)param_2 + 0x13);
  cVar6 = *(char *)((int)param_2 + 0x17);
  cVar7 = *(char *)((int)param_2 + 0x1b);
  switch(*param_2) {
  case 0x8782:
  case 0x8791:
  case 0x8792:
  case 0x8793:
  case 0x8794:
  case 0x8795:
switchD_000b7340_caseD_8782:
    *param_4 = 1;
    *param_5 = 1;
    *param_6 = 1;
    *param_7 = 1;
    return;
  case 0x8783:
  case 0x8789:
  case 0x878f:
  case 0x8790:
  case 0x8799:
  case 0x879c:
    iVar17 = FUN_000550e0(param_1,param_2 + 8);
    if (iVar17 != 0x87bf) goto switchD_000b7340_caseD_8782;
  case 0x879a:
  case 0x879b:
    bVar3 = cVar4 == '\0';
    if ((((bVar3) || ((param_2[10] != 0x87d5 && (param_2[10] != 0x87d9)))) &&
        (((cVar5 == '\0' || ((param_2[0xb] != 0x87d5 && (param_2[0xb] != 0x87d9)))) &&
         ((cVar6 == '\0' || ((param_2[0xc] != 0x87d5 && (param_2[0xc] != 0x87d9)))))))) &&
       ((cVar7 == '\0' || ((param_2[0xd] != 0x87d5 && (param_2[0xd] != 0x87d9)))))) {
      uVar18 = 0;
    }
    else {
      uVar18 = 1;
    }
    *param_4 = uVar18;
    if (((((bVar3) || ((param_2[10] != 0x87d6 && (param_2[10] != 0x87da)))) &&
         ((cVar5 == '\0' || ((param_2[0xb] != 0x87d6 && (param_2[0xb] != 0x87da)))))) &&
        ((cVar6 == '\0' || ((param_2[0xc] != 0x87d6 && (param_2[0xc] != 0x87da)))))) &&
       ((cVar7 == '\0' || ((param_2[0xd] != 0x87d6 && (param_2[0xd] != 0x87da)))))) {
      uVar18 = 0;
    }
    else {
      uVar18 = 1;
    }
    *param_5 = uVar18;
    if ((((bVar3) || ((param_2[10] != 0x87d7 && (param_2[10] != 0x87db)))) &&
        ((cVar5 == '\0' || ((param_2[0xb] != 0x87d7 && (param_2[0xb] != 0x87db)))))) &&
       (((cVar6 == '\0' || ((param_2[0xc] != 0x87d7 && (param_2[0xc] != 0x87db)))) &&
        ((cVar7 == '\0' || ((param_2[0xd] != 0x87d7 && (param_2[0xd] != 0x87db)))))))) {
      uVar18 = 0;
    }
    else {
      uVar18 = 1;
    }
    *param_6 = uVar18;
    if ((((bVar3) || ((param_2[10] != 0x87d8 && (param_2[10] != 0x87dc)))) &&
        ((cVar5 == '\0' || ((param_2[0xb] != 0x87d8 && (param_2[0xb] != 0x87dc)))))) &&
       ((cVar6 == '\0' || ((param_2[0xc] != 0x87d8 && (param_2[0xc] != 0x87dc)))))) {
      if (cVar7 == '\0') {
LAB_000b9970:
        uVar18 = 0;
        goto LAB_000b9ef0;
      }
LAB_000b99c0:
      iVar17 = param_2[0xd];
      if (iVar17 != 0x87d8) {
LAB_000b9960:
        if (iVar17 != 0x87dc) goto LAB_000b9970;
      }
    }
    break;
  case 0x8784:
    if ((param_2[8] == 2) && (param_3 == param_2[9])) {
      iVar17 = param_2[10];
      if ((((iVar17 == 0x87d5) || (iVar17 == 0x87d9)) || (param_2[0xb] == 0x87d5)) ||
         (((param_2[0xb] == 0x87d9 || (param_2[0xc] == 0x87d5)) ||
          (bVar3 = false, param_2[0xc] == 0x87d9)))) {
        bVar3 = true;
      }
      if (((iVar17 == 0x87d6) || (iVar17 == 0x87da)) ||
         ((param_2[0xb] == 0x87d6 ||
          (((param_2[0xb] == 0x87da || (param_2[0xc] == 0x87d6)) ||
           (bVar9 = false, param_2[0xc] == 0x87da)))))) {
        bVar9 = true;
      }
      if (((iVar17 == 0x87d7) || (iVar17 == 0x87db)) ||
         (((param_2[0xb] == 0x87d7 || ((param_2[0xb] == 0x87db || (param_2[0xc] == 0x87d7)))) ||
          (bVar11 = false, param_2[0xc] == 0x87db)))) {
        bVar11 = true;
      }
      if (((((iVar17 == 0x87d8) || (iVar17 == 0x87dc)) || (param_2[0xb] == 0x87d8)) ||
          ((param_2[0xb] == 0x87dc || (param_2[0xc] == 0x87d8)))) ||
         (bVar1 = false, param_2[0xc] == 0x87dc)) {
        bVar1 = true;
      }
    }
    else {
      bVar3 = false;
      bVar9 = false;
      bVar11 = false;
      bVar1 = false;
    }
    if ((param_2[0xf] == 2) && (param_3 == param_2[0x10])) {
      iVar17 = param_2[0x11];
      if ((((iVar17 == 0x87d5) || (iVar17 == 0x87d9)) || (param_2[0x12] == 0x87d5)) ||
         (((param_2[0x12] == 0x87d9 || (param_2[0x13] == 0x87d5)) ||
          (bVar8 = false, param_2[0x13] == 0x87d9)))) {
        bVar8 = true;
      }
      if (((iVar17 == 0x87d6) || (iVar17 == 0x87da)) ||
         ((param_2[0x12] == 0x87d6 ||
          (((param_2[0x12] == 0x87da || (param_2[0x13] == 0x87d6)) ||
           (bVar10 = false, param_2[0x13] == 0x87da)))))) {
        bVar10 = true;
      }
      if (((iVar17 == 0x87d7) || (iVar17 == 0x87db)) ||
         (((param_2[0x12] == 0x87d7 || ((param_2[0x12] == 0x87db || (param_2[0x13] == 0x87d7)))) ||
          (bVar12 = false, param_2[0x13] == 0x87db)))) {
        bVar12 = true;
      }
      if (((((iVar17 == 0x87d8) || (iVar17 == 0x87dc)) || (param_2[0x12] == 0x87d8)) ||
          ((param_2[0x12] == 0x87dc || (param_2[0x13] == 0x87d8)))) ||
         (bVar2 = false, param_2[0x13] == 0x87dc)) {
        bVar2 = true;
      }
    }
    else {
      bVar8 = false;
      bVar10 = false;
      bVar12 = false;
      bVar2 = false;
    }
    if ((bVar3) || (uVar18 = 0, bVar8)) {
      uVar18 = 1;
    }
    *param_4 = uVar18;
    if ((bVar9) || (uVar18 = 0, bVar10)) {
      uVar18 = 1;
    }
    *param_5 = uVar18;
    if ((bVar11) || (uVar18 = 0, bVar12)) {
      uVar18 = 1;
    }
    *param_6 = uVar18;
    if (bVar1) break;
    goto LAB_000b9dfc;
  case 0x8785:
    if ((param_2[8] == 2) && (param_3 == param_2[9])) {
      iVar17 = param_2[10];
      if ((((((iVar17 == 0x87d5) || (iVar17 == 0x87d9)) || (param_2[0xb] == 0x87d5)) ||
           ((param_2[0xb] == 0x87d9 || (param_2[0xc] == 0x87d5)))) || (param_2[0xc] == 0x87d9)) ||
         ((param_2[0xd] == 0x87d5 || (bVar3 = false, param_2[0xd] == 0x87d9)))) {
        bVar3 = true;
      }
      if ((((iVar17 == 0x87d6) || (iVar17 == 0x87da)) || (param_2[0xb] == 0x87d6)) ||
         (((param_2[0xb] == 0x87da || (param_2[0xc] == 0x87d6)) ||
          ((param_2[0xc] == 0x87da ||
           ((param_2[0xd] == 0x87d6 || (bVar9 = false, param_2[0xd] == 0x87da)))))))) {
        bVar9 = true;
      }
      if ((((iVar17 == 0x87d7) || (iVar17 == 0x87db)) || (param_2[0xb] == 0x87d7)) ||
         (((param_2[0xb] == 0x87db || (param_2[0xc] == 0x87d7)) ||
          ((param_2[0xc] == 0x87db ||
           ((param_2[0xd] == 0x87d7 || (bVar11 = false, param_2[0xd] == 0x87db)))))))) {
        bVar11 = true;
      }
      if (((((iVar17 == 0x87d8) || (iVar17 == 0x87dc)) || (param_2[0xb] == 0x87d8)) ||
          ((param_2[0xb] == 0x87dc || (param_2[0xc] == 0x87d8)))) ||
         ((param_2[0xc] == 0x87dc ||
          ((param_2[0xd] == 0x87d8 || (bVar1 = false, param_2[0xd] == 0x87dc)))))) {
        bVar1 = true;
      }
    }
    else {
      bVar3 = false;
      bVar9 = false;
      bVar11 = false;
      bVar1 = false;
    }
    if ((param_2[0xf] == 2) && (param_3 == param_2[0x10])) {
      iVar17 = param_2[0x11];
      if ((((iVar17 == 0x87d5) || (iVar17 == 0x87d9)) || (param_2[0x12] == 0x87d5)) ||
         (((param_2[0x12] == 0x87d9 || (param_2[0x13] == 0x87d5)) ||
          ((param_2[0x13] == 0x87d9 ||
           ((param_2[0x14] == 0x87d5 || (bVar8 = false, param_2[0x14] == 0x87d9)))))))) {
        bVar8 = true;
      }
      if ((((iVar17 == 0x87d6) || (iVar17 == 0x87da)) || (param_2[0x12] == 0x87d6)) ||
         (((param_2[0x12] == 0x87da || (param_2[0x13] == 0x87d6)) ||
          ((param_2[0x13] == 0x87da ||
           ((param_2[0x14] == 0x87d6 || (bVar10 = false, param_2[0x14] == 0x87da)))))))) {
        bVar10 = true;
      }
      if (((((iVar17 == 0x87d7) || (iVar17 == 0x87db)) || (param_2[0x12] == 0x87d7)) ||
          ((param_2[0x12] == 0x87db || (param_2[0x13] == 0x87d7)))) ||
         ((param_2[0x13] == 0x87db ||
          ((param_2[0x14] == 0x87d7 || (bVar12 = false, param_2[0x14] == 0x87db)))))) {
        bVar12 = true;
      }
      if ((((iVar17 == 0x87d8) || (iVar17 == 0x87dc)) || (param_2[0x12] == 0x87d8)) ||
         (((param_2[0x12] == 0x87dc || (param_2[0x13] == 0x87d8)) ||
          ((param_2[0x13] == 0x87dc ||
           ((param_2[0x14] == 0x87d8 || (bVar2 = false, param_2[0x14] == 0x87dc)))))))) {
        bVar2 = true;
      }
    }
    else {
      bVar8 = false;
      bVar10 = false;
      bVar12 = false;
      bVar2 = false;
    }
    if ((bVar3) || (uVar18 = 0, bVar8)) {
      uVar18 = 1;
    }
    *param_4 = uVar18;
    if (bVar9) goto LAB_000b92a0;
LAB_000b9294:
    uVar18 = 0;
    if (bVar10) goto LAB_000b92a0;
    goto LAB_000b92a4;
  case 0x8786:
  case 0x8787:
  case 0x878a:
  case 0x878b:
  case 0x878c:
  case 0x878d:
  case 0x8796:
    if ((param_2[8] == 2) && (param_3 == param_2[9])) {
      iVar17 = FUN_000550e0(param_1,param_2 + 8);
      if (iVar17 == 0x87bf) {
        bVar3 = cVar4 == '\0';
        if (((((bVar3) || ((param_2[10] != 0x87d5 && (param_2[10] != 0x87d9)))) &&
             ((cVar5 == '\0' || ((param_2[0xb] != 0x87d5 && (param_2[0xb] != 0x87d9)))))) &&
            ((cVar6 == '\0' || ((param_2[0xc] != 0x87d5 && (param_2[0xc] != 0x87d9)))))) &&
           ((cVar7 == '\0' || ((param_2[0xd] != 0x87d5 && (param_2[0xd] != 0x87d9)))))) {
          bVar9 = false;
        }
        else {
          bVar9 = true;
        }
        if ((((bVar3) || ((param_2[10] != 0x87d6 && (param_2[10] != 0x87da)))) &&
            ((cVar5 == '\0' || ((param_2[0xb] != 0x87d6 && (param_2[0xb] != 0x87da)))))) &&
           (((cVar6 == '\0' || ((param_2[0xc] != 0x87d6 && (param_2[0xc] != 0x87da)))) &&
            ((cVar7 == '\0' || ((param_2[0xd] != 0x87d6 && (param_2[0xd] != 0x87da)))))))) {
          bVar11 = false;
        }
        else {
          bVar11 = true;
        }
        if ((((bVar3) || ((param_2[10] != 0x87d7 && (param_2[10] != 0x87db)))) &&
            ((cVar5 == '\0' || ((param_2[0xb] != 0x87d7 && (param_2[0xb] != 0x87db)))))) &&
           (((cVar6 == '\0' || ((param_2[0xc] != 0x87d7 && (param_2[0xc] != 0x87db)))) &&
            ((cVar7 == '\0' || ((param_2[0xd] != 0x87d7 && (param_2[0xd] != 0x87db)))))))) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if (((((bVar3) || ((param_2[10] != 0x87d8 && (param_2[10] != 0x87dc)))) &&
             ((cVar5 == '\0' || ((param_2[0xb] != 0x87d8 && (param_2[0xb] != 0x87dc)))))) &&
            ((cVar6 == '\0' || ((param_2[0xc] != 0x87d8 && (param_2[0xc] != 0x87dc)))))) &&
           ((cVar7 == '\0' || ((param_2[0xd] != 0x87d8 && (param_2[0xd] != 0x87dc))))))
        goto LAB_000b7dec;
        bVar3 = true;
      }
      else {
        bVar9 = true;
        bVar11 = true;
        bVar1 = true;
        bVar3 = true;
      }
    }
    else {
      bVar9 = false;
      bVar11 = false;
      bVar1 = false;
LAB_000b7dec:
      bVar3 = false;
    }
    if ((param_2[0xf] == 2) && (param_3 == param_2[0x10])) {
      iVar17 = FUN_000550e0(param_1,param_2 + 0xf);
      if (iVar17 == 0x87bf) {
        bVar2 = cVar4 == '\0';
        if ((((bVar2) || ((param_2[0x11] != 0x87d5 && (param_2[0x11] != 0x87d9)))) &&
            ((cVar5 == '\0' || ((param_2[0x12] != 0x87d5 && (param_2[0x12] != 0x87d9)))))) &&
           (((cVar6 == '\0' || ((param_2[0x13] != 0x87d5 && (param_2[0x13] != 0x87d9)))) &&
            ((cVar7 == '\0' || ((param_2[0x14] != 0x87d5 && (param_2[0x14] != 0x87d9)))))))) {
          bVar8 = false;
        }
        else {
          bVar8 = true;
        }
        if ((((bVar2) || ((param_2[0x11] != 0x87d6 && (param_2[0x11] != 0x87da)))) &&
            ((cVar5 == '\0' || ((param_2[0x12] != 0x87d6 && (param_2[0x12] != 0x87da)))))) &&
           (((cVar6 == '\0' || ((param_2[0x13] != 0x87d6 && (param_2[0x13] != 0x87da)))) &&
            ((cVar7 == '\0' || ((param_2[0x14] != 0x87d6 && (param_2[0x14] != 0x87da)))))))) {
          bVar10 = false;
        }
        else {
          bVar10 = true;
        }
        if (((((bVar2) || ((param_2[0x11] != 0x87d7 && (param_2[0x11] != 0x87db)))) &&
             ((cVar5 == '\0' || ((param_2[0x12] != 0x87d7 && (param_2[0x12] != 0x87db)))))) &&
            ((cVar6 == '\0' || ((param_2[0x13] != 0x87d7 && (param_2[0x13] != 0x87db)))))) &&
           ((cVar7 == '\0' || ((param_2[0x14] != 0x87d7 && (param_2[0x14] != 0x87db)))))) {
          bVar12 = false;
        }
        else {
          bVar12 = true;
        }
        if ((((bVar2) || ((param_2[0x11] != 0x87d8 && (param_2[0x11] != 0x87dc)))) &&
            ((cVar5 == '\0' || ((param_2[0x12] != 0x87d8 && (param_2[0x12] != 0x87dc)))))) &&
           (((cVar6 == '\0' || ((param_2[0x13] != 0x87d8 && (param_2[0x13] != 0x87dc)))) &&
            ((cVar7 == '\0' || ((param_2[0x14] != 0x87d8 && (param_2[0x14] != 0x87dc))))))))
        goto LAB_000b812c;
        bVar2 = true;
      }
      else {
        bVar8 = true;
        bVar10 = true;
        bVar12 = true;
        bVar2 = true;
      }
    }
    else {
      bVar8 = false;
      bVar10 = false;
      bVar12 = false;
LAB_000b812c:
      bVar2 = false;
    }
    if ((bVar9) || (uVar18 = 0, bVar8)) {
      uVar18 = 1;
    }
    *param_4 = uVar18;
    if ((bVar11) || (uVar18 = 0, bVar10)) {
      uVar18 = 1;
    }
    *param_5 = uVar18;
    if ((bVar1) || (uVar18 = 0, bVar12)) {
      uVar18 = 1;
    }
    *param_6 = uVar18;
    goto joined_r0x000b9df8;
  case 0x8788:
  case 0x878e:
    if ((param_2[8] == 2) && (param_3 == param_2[9])) {
      iVar17 = FUN_000550e0(param_1,param_2 + 8);
      if (iVar17 == 0x87bf) {
        bVar1 = cVar4 == '\0';
        if (((((bVar1) || ((param_2[10] != 0x87d5 && (param_2[10] != 0x87d9)))) &&
             ((cVar5 == '\0' || ((param_2[0xb] != 0x87d5 && (param_2[0xb] != 0x87d9)))))) &&
            ((cVar6 == '\0' || ((param_2[0xc] != 0x87d5 && (param_2[0xc] != 0x87d9)))))) &&
           ((cVar7 == '\0' || ((param_2[0xd] != 0x87d5 && (param_2[0xd] != 0x87d9)))))) {
          bVar3 = false;
        }
        else {
          bVar3 = true;
        }
        if ((((bVar1) || ((param_2[10] != 0x87d6 && (param_2[10] != 0x87da)))) &&
            ((cVar5 == '\0' || ((param_2[0xb] != 0x87d6 && (param_2[0xb] != 0x87da)))))) &&
           (((cVar6 == '\0' || ((param_2[0xc] != 0x87d6 && (param_2[0xc] != 0x87da)))) &&
            ((cVar7 == '\0' || ((param_2[0xd] != 0x87d6 && (param_2[0xd] != 0x87da)))))))) {
          bVar9 = false;
        }
        else {
          bVar9 = true;
        }
        if ((((bVar1) || ((param_2[10] != 0x87d7 && (param_2[10] != 0x87db)))) &&
            ((cVar5 == '\0' || ((param_2[0xb] != 0x87d7 && (param_2[0xb] != 0x87db)))))) &&
           (((cVar6 == '\0' || ((param_2[0xc] != 0x87d7 && (param_2[0xc] != 0x87db)))) &&
            ((cVar7 == '\0' || ((param_2[0xd] != 0x87d7 && (param_2[0xd] != 0x87db)))))))) {
          bVar11 = false;
        }
        else {
          bVar11 = true;
        }
        if (((((bVar1) || ((param_2[10] != 0x87d8 && (param_2[10] != 0x87dc)))) &&
             ((cVar5 == '\0' || ((param_2[0xb] != 0x87d8 && (param_2[0xb] != 0x87dc)))))) &&
            ((cVar6 == '\0' || ((param_2[0xc] != 0x87d8 && (param_2[0xc] != 0x87dc)))))) &&
           ((cVar7 == '\0' || ((param_2[0xd] != 0x87d8 && (param_2[0xd] != 0x87dc))))))
        goto LAB_000b84cc;
        bVar8 = true;
      }
      else {
        bVar3 = true;
        bVar9 = true;
        bVar11 = true;
        bVar8 = true;
      }
    }
    else {
      bVar3 = false;
      bVar9 = false;
      bVar11 = false;
LAB_000b84cc:
      bVar8 = false;
    }
    if ((param_2[0xf] == 2) && (param_3 == param_2[0x10])) {
      iVar17 = FUN_000550e0(param_1,param_2 + 0xf);
      if (iVar17 == 0x87bf) {
        bVar1 = cVar4 == '\0';
        if ((((bVar1) || ((param_2[0x11] != 0x87d5 && (param_2[0x11] != 0x87d9)))) &&
            ((cVar5 == '\0' || ((param_2[0x12] != 0x87d5 && (param_2[0x12] != 0x87d9)))))) &&
           (((cVar6 == '\0' || ((param_2[0x13] != 0x87d5 && (param_2[0x13] != 0x87d9)))) &&
            ((cVar7 == '\0' || ((param_2[0x14] != 0x87d5 && (param_2[0x14] != 0x87d9)))))))) {
          bVar10 = false;
        }
        else {
          bVar10 = true;
        }
        if (((((bVar1) || ((param_2[0x11] != 0x87d6 && (param_2[0x11] != 0x87da)))) &&
             ((cVar5 == '\0' || ((param_2[0x12] != 0x87d6 && (param_2[0x12] != 0x87da)))))) &&
            ((cVar6 == '\0' || ((param_2[0x13] != 0x87d6 && (param_2[0x13] != 0x87da)))))) &&
           ((cVar7 == '\0' || ((param_2[0x14] != 0x87d6 && (param_2[0x14] != 0x87da)))))) {
          bVar12 = false;
        }
        else {
          bVar12 = true;
        }
        if (((((bVar1) || ((param_2[0x11] != 0x87d7 && (param_2[0x11] != 0x87db)))) &&
             ((cVar5 == '\0' || ((param_2[0x12] != 0x87d7 && (param_2[0x12] != 0x87db)))))) &&
            ((cVar6 == '\0' || ((param_2[0x13] != 0x87d7 && (param_2[0x13] != 0x87db)))))) &&
           ((cVar7 == '\0' || ((param_2[0x14] != 0x87d7 && (param_2[0x14] != 0x87db)))))) {
          bVar16 = false;
        }
        else {
          bVar16 = true;
        }
        if ((((bVar1) || ((param_2[0x11] != 0x87d8 && (param_2[0x11] != 0x87dc)))) &&
            ((cVar5 == '\0' || ((param_2[0x12] != 0x87d8 && (param_2[0x12] != 0x87dc)))))) &&
           (((cVar6 == '\0' || ((param_2[0x13] != 0x87d8 && (param_2[0x13] != 0x87dc)))) &&
            ((cVar7 == '\0' || ((param_2[0x14] != 0x87d8 && (param_2[0x14] != 0x87dc))))))))
        goto LAB_000b880c;
        bVar1 = true;
      }
      else {
        bVar10 = true;
        bVar12 = true;
        bVar16 = true;
        bVar1 = true;
      }
    }
    else {
      bVar10 = false;
      bVar12 = false;
      bVar16 = false;
LAB_000b880c:
      bVar1 = false;
    }
    if ((param_2[0x16] == 2) && (param_3 == param_2[0x17])) {
      iVar17 = FUN_000550e0(param_1,param_2 + 0x16);
      if (iVar17 == 0x87bf) {
        bVar2 = cVar4 == '\0';
        if ((((bVar2) || ((param_2[0x18] != 0x87d5 && (param_2[0x18] != 0x87d9)))) &&
            ((cVar5 == '\0' || ((param_2[0x19] != 0x87d5 && (param_2[0x19] != 0x87d9)))))) &&
           (((cVar6 == '\0' || ((param_2[0x1a] != 0x87d5 && (param_2[0x1a] != 0x87d9)))) &&
            ((cVar7 == '\0' || ((param_2[0x1b] != 0x87d5 && (param_2[0x1b] != 0x87d9)))))))) {
          bVar13 = false;
        }
        else {
          bVar13 = true;
        }
        if (((((bVar2) || ((param_2[0x18] != 0x87d6 && (param_2[0x18] != 0x87da)))) &&
             ((cVar5 == '\0' || ((param_2[0x19] != 0x87d6 && (param_2[0x19] != 0x87da)))))) &&
            ((cVar6 == '\0' || ((param_2[0x1a] != 0x87d6 && (param_2[0x1a] != 0x87da)))))) &&
           ((cVar7 == '\0' || ((param_2[0x1b] != 0x87d6 && (param_2[0x1b] != 0x87da)))))) {
          bVar14 = false;
        }
        else {
          bVar14 = true;
        }
        if ((((bVar2) || ((param_2[0x18] != 0x87d7 && (param_2[0x18] != 0x87db)))) &&
            ((cVar5 == '\0' || ((param_2[0x19] != 0x87d7 && (param_2[0x19] != 0x87db)))))) &&
           (((cVar6 == '\0' || ((param_2[0x1a] != 0x87d7 && (param_2[0x1a] != 0x87db)))) &&
            ((cVar7 == '\0' || ((param_2[0x1b] != 0x87d7 && (param_2[0x1b] != 0x87db)))))))) {
          bVar15 = false;
        }
        else {
          bVar15 = true;
        }
        if ((((bVar2) || ((param_2[0x18] != 0x87d8 && (param_2[0x18] != 0x87dc)))) &&
            ((cVar5 == '\0' || ((param_2[0x19] != 0x87d8 && (param_2[0x19] != 0x87dc)))))) &&
           (((cVar6 == '\0' || ((param_2[0x1a] != 0x87d8 && (param_2[0x1a] != 0x87dc)))) &&
            ((cVar7 == '\0' || ((param_2[0x1b] != 0x87d8 && (param_2[0x1b] != 0x87dc))))))))
        goto LAB_000b8b4c;
        bVar2 = true;
      }
      else {
        bVar13 = true;
        bVar14 = true;
        bVar15 = true;
        bVar2 = true;
      }
    }
    else {
      bVar13 = false;
      bVar14 = false;
      bVar15 = false;
LAB_000b8b4c:
      bVar2 = false;
    }
    if (((bVar3) || (bVar10)) || (uVar18 = 0, bVar13)) {
      uVar18 = 1;
    }
    *param_4 = uVar18;
    if (((bVar9) || (bVar12)) || (uVar18 = 0, bVar14)) {
      uVar18 = 1;
    }
    *param_5 = uVar18;
    if (((bVar11) || (bVar16)) || (uVar18 = 0, bVar15)) {
      uVar18 = 1;
    }
    *param_6 = uVar18;
    if (bVar8) break;
    goto joined_r0x000b8bc8;
  case 0x8797:
    if ((param_2[8] == 2) && (param_3 == param_2[9])) {
      bVar1 = cVar4 == '\0';
      if ((((bVar1) ||
           ((((param_2[0xb] != 0x87d5 && (param_2[0xb] != 0x87d9)) && (param_2[0xc] != 0x87d5)) &&
            (param_2[0xc] != 0x87d9)))) &&
          ((cVar5 == '\0' ||
           (((param_2[10] != 0x87d5 && (param_2[10] != 0x87d9)) &&
            ((param_2[0xc] != 0x87d5 && (param_2[0xc] != 0x87d9)))))))) &&
         ((cVar6 == '\0' ||
          (((param_2[10] != 0x87d5 && (param_2[10] != 0x87d9)) &&
           ((param_2[0xb] != 0x87d5 && (param_2[0xb] != 0x87d9)))))))) {
        bVar3 = false;
      }
      else {
        bVar3 = true;
      }
      if (((bVar1) ||
          ((((param_2[0xb] != 0x87d6 && (param_2[0xb] != 0x87da)) && (param_2[0xc] != 0x87d6)) &&
           (param_2[0xc] != 0x87da)))) &&
         (((cVar5 == '\0' ||
           (((param_2[10] != 0x87d6 && (param_2[10] != 0x87da)) &&
            ((param_2[0xc] != 0x87d6 && (param_2[0xc] != 0x87da)))))) &&
          ((cVar6 == '\0' ||
           (((param_2[10] != 0x87d6 && (param_2[10] != 0x87da)) &&
            ((param_2[0xb] != 0x87d6 && (param_2[0xb] != 0x87da)))))))))) {
        bVar9 = false;
      }
      else {
        bVar9 = true;
      }
      if ((((bVar1) ||
           ((((param_2[0xb] != 0x87d7 && (param_2[0xb] != 0x87db)) && (param_2[0xc] != 0x87d7)) &&
            (param_2[0xc] != 0x87db)))) &&
          ((cVar5 == '\0' ||
           (((param_2[10] != 0x87d7 && (param_2[10] != 0x87db)) &&
            ((param_2[0xc] != 0x87d7 && (param_2[0xc] != 0x87db)))))))) &&
         ((cVar6 == '\0' ||
          (((param_2[10] != 0x87d7 && (param_2[10] != 0x87db)) &&
           ((param_2[0xb] != 0x87d7 && (param_2[0xb] != 0x87db)))))))) {
        bVar11 = false;
      }
      else {
        bVar11 = true;
      }
      if (((bVar1) ||
          ((((param_2[0xb] != 0x87d8 && (param_2[0xb] != 0x87dc)) && (param_2[0xc] != 0x87d8)) &&
           (param_2[0xc] != 0x87dc)))) &&
         (((cVar5 == '\0' ||
           (((param_2[10] != 0x87d8 && (param_2[10] != 0x87dc)) &&
            ((param_2[0xc] != 0x87d8 && (param_2[0xc] != 0x87dc)))))) &&
          ((cVar6 == '\0' ||
           (((param_2[10] != 0x87d8 && (param_2[10] != 0x87dc)) &&
            ((param_2[0xb] != 0x87d8 && (param_2[0xb] != 0x87dc)))))))))) goto LAB_000b8f1c;
      bVar1 = true;
    }
    else {
      bVar3 = false;
      bVar9 = false;
      bVar11 = false;
LAB_000b8f1c:
      bVar1 = false;
    }
    if ((param_2[0xf] == 2) && (param_3 == param_2[0x10])) {
      bVar2 = cVar4 == '\0';
      if ((((bVar2) ||
           ((((param_2[0x12] != 0x87d5 && (param_2[0x12] != 0x87d9)) && (param_2[0x13] != 0x87d5))
            && (param_2[0x13] != 0x87d9)))) &&
          ((cVar5 == '\0' ||
           (((param_2[0x11] != 0x87d5 && (param_2[0x11] != 0x87d9)) &&
            ((param_2[0x13] != 0x87d5 && (param_2[0x13] != 0x87d9)))))))) &&
         ((cVar6 == '\0' ||
          (((param_2[0x11] != 0x87d5 && (param_2[0x11] != 0x87d9)) &&
           ((param_2[0x12] != 0x87d5 && (param_2[0x12] != 0x87d9)))))))) {
        bVar8 = false;
      }
      else {
        bVar8 = true;
      }
      if ((((bVar2) ||
           ((((param_2[0x12] != 0x87d6 && (param_2[0x12] != 0x87da)) && (param_2[0x13] != 0x87d6))
            && (param_2[0x13] != 0x87da)))) &&
          ((cVar5 == '\0' ||
           (((param_2[0x11] != 0x87d6 && (param_2[0x11] != 0x87da)) &&
            ((param_2[0x13] != 0x87d6 && (param_2[0x13] != 0x87da)))))))) &&
         ((cVar6 == '\0' ||
          (((param_2[0x11] != 0x87d6 && (param_2[0x11] != 0x87da)) &&
           ((param_2[0x12] != 0x87d6 && (param_2[0x12] != 0x87da)))))))) {
        bVar10 = false;
      }
      else {
        bVar10 = true;
      }
      if (((bVar2) ||
          ((((param_2[0x12] != 0x87d7 && (param_2[0x12] != 0x87db)) && (param_2[0x13] != 0x87d7)) &&
           (param_2[0x13] != 0x87db)))) &&
         (((cVar5 == '\0' ||
           (((param_2[0x11] != 0x87d7 && (param_2[0x11] != 0x87db)) &&
            ((param_2[0x13] != 0x87d7 && (param_2[0x13] != 0x87db)))))) &&
          ((cVar6 == '\0' ||
           (((param_2[0x11] != 0x87d7 && (param_2[0x11] != 0x87db)) &&
            ((param_2[0x12] != 0x87d7 && (param_2[0x12] != 0x87db)))))))))) {
        bVar12 = false;
      }
      else {
        bVar12 = true;
      }
      if ((((bVar2) ||
           ((((param_2[0x12] != 0x87d8 && (param_2[0x12] != 0x87dc)) && (param_2[0x13] != 0x87d8))
            && (param_2[0x13] != 0x87dc)))) &&
          ((cVar5 == '\0' ||
           (((param_2[0x11] != 0x87d8 && (param_2[0x11] != 0x87dc)) &&
            ((param_2[0x13] != 0x87d8 && (param_2[0x13] != 0x87dc)))))))) &&
         ((cVar6 == '\0' ||
          (((param_2[0x11] != 0x87d8 && (param_2[0x11] != 0x87dc)) &&
           ((param_2[0x12] != 0x87d8 && (param_2[0x12] != 0x87dc)))))))) goto LAB_000b926c;
      bVar2 = true;
    }
    else {
      bVar8 = false;
      bVar10 = false;
      bVar12 = false;
LAB_000b926c:
      bVar2 = false;
    }
    if ((bVar3) || (uVar18 = 0, bVar8)) {
      uVar18 = 1;
    }
    *param_4 = uVar18;
    if (!bVar9) goto LAB_000b9294;
LAB_000b92a0:
    uVar18 = 1;
LAB_000b92a4:
    *param_5 = uVar18;
    if ((bVar11) || (uVar18 = 0, bVar12)) {
      uVar18 = 1;
    }
    *param_6 = uVar18;
joined_r0x000b8bc8:
    if (!bVar1) {
LAB_000b9dfc:
      uVar18 = 0;
      if (!bVar2) goto LAB_000b9ef0;
    }
    break;
  case 0x8798:
    if ((((((param_2[0x11] == 0x87d5) || (param_2[0x11] == 0x87d9)) || (param_2[0x12] == 0x87d5)) ||
         ((param_2[0x12] == 0x87d9 || (param_2[0x13] == 0x87d5)))) || (param_2[0x13] == 0x87d9)) ||
       ((param_2[0x14] == 0x87d5 || (uVar18 = 0, param_2[0x14] == 0x87d9)))) {
      uVar18 = 1;
    }
    *param_4 = uVar18;
    if ((((param_2[0x11] == 0x87d6) || (param_2[0x11] == 0x87da)) || (param_2[0x12] == 0x87d6)) ||
       (((param_2[0x12] == 0x87da || (param_2[0x13] == 0x87d6)) ||
        ((param_2[0x13] == 0x87da ||
         ((param_2[0x14] == 0x87d6 || (uVar18 = 0, param_2[0x14] == 0x87da)))))))) {
      uVar18 = 1;
    }
    *param_5 = uVar18;
    if ((((param_2[0x11] == 0x87d7) || (param_2[0x11] == 0x87db)) || (param_2[0x12] == 0x87d7)) ||
       (((param_2[0x12] == 0x87db || (param_2[0x13] == 0x87d7)) ||
        ((param_2[0x13] == 0x87db ||
         ((param_2[0x14] == 0x87d7 || (uVar18 = 0, param_2[0x14] == 0x87db)))))))) {
      uVar18 = 1;
    }
    *param_6 = uVar18;
    if (((((param_2[0x11] != 0x87d8) && (param_2[0x11] != 0x87dc)) && (param_2[0x12] != 0x87d8)) &&
        ((param_2[0x12] != 0x87dc && (param_2[0x13] != 0x87d8)))) && (param_2[0x13] != 0x87dc)) {
      iVar17 = param_2[0x14];
joined_r0x000b9b40:
      if ((iVar17 != 0x87d8) && (uVar18 = 0, iVar17 != 0x87dc)) goto LAB_000b9ef0;
    }
    break;
  case 0x879d:
    iVar17 = FUN_000550e0(param_1,param_2 + 8);
    if (iVar17 != 0x87bf) goto switchD_000b7340_caseD_8782;
    iVar17 = param_2[0x10];
    if (iVar17 == 0) {
      iVar17 = param_2[10];
joined_r0x000b97e0:
      if ((iVar17 != 0x87d5) && (iVar17 != 0x87d9)) goto LAB_000b9790;
      uVar18 = 1;
    }
    else {
      if (iVar17 == 1) {
        iVar17 = param_2[0xb];
        goto joined_r0x000b97e0;
      }
      if (iVar17 == 2) {
        iVar17 = param_2[0xc];
        goto joined_r0x000b97e0;
      }
      if (iVar17 == 3) {
        iVar17 = param_2[0xd];
        goto joined_r0x000b97e0;
      }
LAB_000b9790:
      uVar18 = 0;
    }
    *param_4 = uVar18;
    iVar17 = param_2[0x10];
    if (iVar17 == 0) {
      iVar17 = param_2[10];
joined_r0x000b9880:
      if ((iVar17 != 0x87d6) && (iVar17 != 0x87da)) goto LAB_000b9830;
      uVar18 = 1;
    }
    else {
      if (iVar17 == 1) {
        iVar17 = param_2[0xb];
        goto joined_r0x000b9880;
      }
      if (iVar17 == 2) {
        iVar17 = param_2[0xc];
        goto joined_r0x000b9880;
      }
      if (iVar17 == 3) {
        iVar17 = param_2[0xd];
        goto joined_r0x000b9880;
      }
LAB_000b9830:
      uVar18 = 0;
    }
    *param_5 = uVar18;
    iVar17 = param_2[0x10];
    if (iVar17 == 0) {
      iVar17 = param_2[10];
joined_r0x000b9920:
      if ((iVar17 != 0x87d7) && (iVar17 != 0x87db)) goto LAB_000b98d0;
      uVar18 = 1;
    }
    else {
      if (iVar17 == 1) {
        iVar17 = param_2[0xb];
        goto joined_r0x000b9920;
      }
      if (iVar17 == 2) {
        iVar17 = param_2[0xc];
        goto joined_r0x000b9920;
      }
      if (iVar17 == 3) {
        iVar17 = param_2[0xd];
        goto joined_r0x000b9920;
      }
LAB_000b98d0:
      uVar18 = 0;
    }
    *param_6 = uVar18;
    iVar17 = param_2[0x10];
    if (iVar17 == 0) {
      iVar17 = param_2[10];
joined_r0x000b9990:
      if (iVar17 == 0x87d8) break;
      goto LAB_000b9960;
    }
    if (iVar17 == 1) {
      iVar17 = param_2[0xb];
      goto joined_r0x000b9990;
    }
    if (iVar17 == 2) {
      iVar17 = param_2[0xc];
      goto joined_r0x000b9990;
    }
    if (iVar17 == 3) goto LAB_000b99c0;
    goto LAB_000b9970;
  case 0x879e:
    if (((((param_2[10] == 0x87d5) || (param_2[10] == 0x87d9)) || (param_2[0xb] == 0x87d5)) ||
        ((param_2[0xb] == 0x87d9 || (param_2[0xd] == 0x87d5)))) ||
       (uVar18 = 0, param_2[0xd] == 0x87d9)) {
      uVar18 = 1;
    }
    *param_4 = uVar18;
    if (((param_2[10] == 0x87d6) || (param_2[10] == 0x87da)) ||
       ((param_2[0xb] == 0x87d6 ||
        (((param_2[0xb] == 0x87da || (param_2[0xd] == 0x87d6)) ||
         (uVar18 = 0, param_2[0xd] == 0x87da)))))) {
      uVar18 = 1;
    }
    *param_5 = uVar18;
    if (((param_2[10] == 0x87d7) || (param_2[10] == 0x87db)) ||
       (((param_2[0xb] == 0x87d7 || ((param_2[0xb] == 0x87db || (param_2[0xd] == 0x87d7)))) ||
        (uVar18 = 0, param_2[0xd] == 0x87db)))) {
      uVar18 = 1;
    }
    *param_6 = uVar18;
    if ((((param_2[10] != 0x87d8) && (param_2[10] != 0x87dc)) && (param_2[0xb] != 0x87d8)) &&
       (param_2[0xb] != 0x87dc)) {
      iVar17 = param_2[0xd];
      goto joined_r0x000b9b40;
    }
    break;
  case 0x879f:
    if ((param_2[8] == 2) && (param_3 == param_2[9])) {
      iVar17 = param_2[0xb];
      if ((((iVar17 == 0x87d5) || (iVar17 == 0x87d9)) || (param_2[0xc] == 0x87d5)) ||
         (bVar9 = false, param_2[0xc] == 0x87d9)) {
        bVar9 = true;
      }
      if (((iVar17 == 0x87d6) || (iVar17 == 0x87da)) ||
         ((param_2[0xc] == 0x87d6 || (bVar11 = false, param_2[0xc] == 0x87da)))) {
        bVar11 = true;
      }
      if (((iVar17 == 0x87d7) || (iVar17 == 0x87db)) ||
         ((param_2[0xc] == 0x87d7 || (bVar1 = false, param_2[0xc] == 0x87db)))) {
        bVar1 = true;
      }
      if ((((iVar17 == 0x87d8) || (iVar17 == 0x87dc)) || (param_2[0xc] == 0x87d8)) ||
         (bVar3 = false, param_2[0xc] == 0x87dc)) {
        bVar3 = true;
      }
    }
    else {
      bVar9 = false;
      bVar11 = false;
      bVar1 = false;
      bVar3 = false;
    }
    if ((param_2[0xf] == 2) && (param_2[0x10] == param_3)) {
      iVar17 = param_2[0x12];
      if (((iVar17 == 0x87d5) || (iVar17 == 0x87d9)) ||
         ((param_2[0x14] == 0x87d5 || (bVar8 = false, param_2[0x14] == 0x87d9)))) {
        bVar8 = true;
      }
      if ((((iVar17 == 0x87d6) || (iVar17 == 0x87da)) || (param_2[0x14] == 0x87d6)) ||
         (bVar10 = false, param_2[0x14] == 0x87da)) {
        bVar10 = true;
      }
      if (((iVar17 == 0x87d7) || (iVar17 == 0x87db)) ||
         ((param_2[0x14] == 0x87d7 || (bVar12 = false, param_2[0x14] == 0x87db)))) {
        bVar12 = true;
      }
      if (((iVar17 == 0x87d8) || (iVar17 == 0x87dc)) ||
         ((param_2[0x14] == 0x87d8 || (bVar2 = false, param_2[0x14] == 0x87dc)))) {
        bVar2 = true;
      }
    }
    else {
      bVar8 = false;
      bVar10 = false;
      bVar12 = false;
      bVar2 = false;
    }
    if ((bVar9) || (uVar18 = 0, bVar8)) {
      uVar18 = 1;
    }
    *param_4 = uVar18;
    if ((bVar11) || (uVar18 = 0, bVar10)) {
      uVar18 = 1;
    }
    *param_5 = uVar18;
    if ((bVar1) || (uVar18 = 0, bVar12)) {
      uVar18 = 1;
    }
    *param_6 = uVar18;
joined_r0x000b9df8:
    if (bVar3) break;
    goto LAB_000b9dfc;
  case 0x87a0:
  case 0x87a1:
  case 0x87a2:
    if ((param_2[10] == 0x87d5) || (uVar18 = 0, param_2[10] == 0x87d9)) {
      uVar18 = 1;
    }
    *param_4 = uVar18;
    if ((param_2[10] == 0x87d6) || (uVar18 = 0, param_2[10] == 0x87da)) {
      uVar18 = 1;
    }
    *param_5 = uVar18;
    if ((param_2[10] == 0x87d7) || (uVar18 = 0, param_2[10] == 0x87db)) {
      uVar18 = 1;
    }
    *param_6 = uVar18;
    if ((param_2[10] == 0x87d8) || (uVar18 = 0, param_2[10] == 0x87dc)) {
      uVar18 = 1;
    }
    *param_7 = uVar18;
    return;
  default:
    uVar18 = 0;
    *param_4 = 0;
    *param_5 = 0;
    *param_6 = 0;
    goto LAB_000b9ef0;
  }
  uVar18 = 1;
LAB_000b9ef0:
  *param_7 = uVar18;
  return;
}

