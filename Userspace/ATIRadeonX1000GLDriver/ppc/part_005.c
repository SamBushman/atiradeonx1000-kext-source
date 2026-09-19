#include "decls.h"

/* FUN_0004dc30 @ 0x4dc30 (220 bytes) */
int FUN_0004dc30(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  if ((*(uint *)(param_1 + 0x44) & 0x20000) != 0) {
    return;
  }
  uVar6 = (uint)(byte)((unsigned char *)0x000013b2)[param_1];
  if ((uint)*(byte *)(param_1 + 0x2b) <= (uint)(byte)((unsigned char *)0x000013b2)[param_1]) {
    uVar6 = (uint)*(byte *)(param_1 + 0x2b);
  }
  if (uVar6 != 0) {
    uVar2 = 0;
    iVar3 = param_1;
    iVar5 = param_1;
    do {
      *(undefined4 *)(iVar5 + 0x1f38) = *(undefined4 *)(iVar3 + 0x47c);
      *(undefined4 *)(iVar5 + 0x1f3c) = *(undefined4 *)(iVar3 + 0x480);
      *(undefined4 *)(iVar5 + 8000) = *(undefined4 *)(iVar3 + 0x484);
      *(undefined4 *)(iVar5 + 0x1f44) = *(undefined4 *)(iVar3 + 0x488);
      iVar4 = *(int *)(param_1 + 0x1e68);
      if (iVar4 != 0) {
        if ((1 << (uVar2 & 0x3f) & *(uint *)(((unsigned char *)0x000010d8) + iVar4)) != 0) {
          iVar1 = uVar2 * 0x10;
          *(undefined4 *)(iVar1 + iVar4 + 0x8c) = *(undefined4 *)(iVar5 + 0x1f38);
          *(undefined4 *)(iVar1 + *(int *)(param_1 + 0x1e68) + 0x90) =
               *(undefined4 *)(iVar5 + 0x1f3c);
          *(undefined4 *)(iVar1 + *(int *)(param_1 + 0x1e68) + 0x94) = *(undefined4 *)(iVar5 + 8000)
          ;
          *(undefined4 *)(iVar1 + *(int *)(param_1 + 0x1e68) + 0x98) =
               *(undefined4 *)(iVar5 + 0x1f44);
        }
      }
      uVar2 = uVar2 + 1;
      iVar3 = iVar3 + 0xcc;
      iVar5 = iVar5 + 0x10;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x4000000;
  return;
}

/* FUN_0004dd10 @ 0x4dd10 (40 bytes) */
int FUN_0004dd10(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *param_2 = 0x110f8;
  param_2[1] = *(undefined4 *)(param_1 + 7000);
  param_2[2] = *(undefined4 *)(param_1 + 0x1b10);
  return param_2 + 3;
}

/* FUN_0004dd40 @ 0x4dd40 (116 bytes) */
int FUN_0004dd40(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  
  *param_2 = 0x50766;
  param_2[1] = *(undefined4 *)(param_1 + 0x1c8c);
  param_2[2] = *(undefined4 *)(param_1 + 0x1c88);
  param_2[3] = *(undefined4 *)(param_1 + 0x1c94);
  param_2[4] = *(undefined4 *)(param_1 + 0x1c90);
  param_2[5] = *(undefined4 *)(param_1 + 0x1c9c);
  uVar1 = *(undefined4 *)(param_1 + 0x1c98);
  param_2[7] = 0x30888;
  param_2[6] = uVar1;
  param_2[8] = *(undefined4 *)(param_1 + 0x1ca8);
  param_2[9] = *(undefined4 *)(param_1 + 0x1cac);
  param_2[10] = *(undefined4 *)(param_1 + 0x1cb0);
  param_2[0xb] = *(undefined4 *)(param_1 + 0x1cb4);
  return param_2 + 0xc;
}

/* FUN_0004de30 @ 0x4de30 (180 bytes) */
int FUN_0004de30(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
  undefined4 *param_5;
  int param_6;
{
  undefined4 *puVar1;
  char *pcVar2;
  
  if (param_2 == 0) {
    if (((*(uint *)(param_1 + 0x44) & 0x20000) == 0) ||
       (param_2 = *(int *)(param_1 + 0x1e70), param_2 == 0)) {
      param_2 = *(int *)(param_1 + 0x1e5c);
    }
  }
  else {
    param_2 = param_2 + 0x124;
  }
  if (0 < param_6) {
    pcVar2 = (*(unsigned char *)0x00002ddc) + param_4 + param_2;
    puVar1 = (undefined4 *)(param_4 * 0x10 + param_2 + 0x8c);
    do {
      if ((*pcVar2 != '\0') && (pcVar2[0x100] == '\0')) {
        *puVar1 = *param_5;
        puVar1[1] = param_5[1];
        puVar1[2] = param_5[2];
        puVar1[3] = param_5[3];
      }
      pcVar2 = pcVar2 + 1;
      param_5 = param_5 + 4;
      puVar1 = puVar1 + 4;
      param_6 = param_6 + -1;
    } while (param_6 != 0);
  }
  ((unsigned char *)0x000010eb)[param_2] = 0;
  return;
}

/* FUN_0004def0 @ 0x4def0 (2428 bytes) */
int FUN_0004def0(param_1)
  int param_1;
{
  int *piVar1;
  float fVar2;
  short sVar3;
  ushort uVar4;
  float fVar5;
  bool bVar6;
  double dVar7;
  char cVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  int iVar20;
  int iVar21;
  undefined4 uVar22;
  uint uVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  int iVar28;
  uint uVar29;
  int iVar30;
  
  uVar4 = *(ushort *)(param_1 + 0x32) | *(ushort *)(param_1 + 0x34);
  uVar23 = (uint)uVar4;
  if ((uVar4 != 0) && (*(char *)(param_1 + 0x121) != '\0')) {
    uVar9 = (uint)(byte)((unsigned char *)0x000013b0)[param_1];
    if (uVar9 == 0) {
LAB_0004df78:
      *(undefined1 *)(param_1 + 0x120) = 0xff;
    }
    else {
      uVar29 = 0;
      if (*(int *)(param_1 + 0x48) != 0) {
        uVar29 = 0;
        iVar17 = param_1;
        do {
          uVar29 = uVar29 + 1;
          uVar9 = uVar9 - 1;
          if (uVar9 == 0) goto LAB_0004df78;
          piVar1 = (int *)(iVar17 + 0x4c);
          iVar17 = iVar17 + 4;
        } while (*piVar1 != 0);
        uVar29 = uVar29 & 0xff;
      }
      *(char *)(param_1 + 0x120) = (char)uVar29;
      *(uint *)(param_1 + 0x1878) = (uVar29 & 7) << 0x15 | *(uint *)(param_1 + 0x1878) & 0xff1fffff;
      *(uint *)(param_1 + 0x18a4) = (uVar29 & 7) << 0x1a | *(uint *)(param_1 + 0x18a4) & 0xe3ffffff;
    }
  }
  iVar17 = *(int *)(param_1 + 0x27b4);
  iVar24 = *(int *)(param_1 + 0x1808);
  uVar9 = *(uint *)(param_1 + 0x27b0) & ~(iVar17 << 8);
  *(uint *)(param_1 + 0x27b0) = uVar9;
  dVar7 = DOUBLE_001aa1e0;
  if (uVar4 != 0) {
    iVar10 = param_1 + 0x28b4;
    uVar29 = 0;
    uVar9 = 0;
    iVar28 = param_1 + 0x20;
    iVar17 = param_1;
    iVar25 = param_1;
    iVar26 = param_1;
    iVar27 = param_1;
    iVar30 = param_1;
    do {
      if ((uVar23 & 1) != 0) {
        if (iVar24 == 0) {
          iVar20 = *(int *)(((unsigned char *)0x000013f8) + iVar25);
          if (iVar20 == 0) {
            *(uint *)(param_1 + 0x27b0) = *(uint *)(param_1 + 0x27b0) & ~(1 << (uVar29 & 0x3f));
          }
          else {
            uVar11 = 1 << (uVar29 & 0x3f);
            *(uint *)(param_1 + 0x1934) = uVar11 | *(uint *)(param_1 + 0x1934);
            *(uint *)(param_1 + 0x27b0) = uVar11 | *(uint *)(param_1 + 0x27b0);
            *(undefined4 *)(iVar30 + 0x1d5c) = *(undefined4 *)(iVar20 + 0x1c);
            *(undefined4 *)(((unsigned char *)0x00001d9c) + iVar30) = *(undefined4 *)(iVar20 + 0x20);
            *(undefined4 *)(((unsigned char *)0x00001ddc) + iVar30) = *(undefined4 *)(iVar20 + 0x24);
            *(undefined4 *)(((unsigned char *)0x00001dfc) + iVar28) = *(undefined4 *)(iVar20 + 0x28);
            *(uint *)(iVar30 + 0x1cdc) = uVar9 << 0x1c | *(uint *)(iVar20 + 0x14) & 0xfffffff;
            *(uint *)(iVar30 + 0x1d1c) =
                 (*(ushort *)(iVar27 + 0x46e) & 0x3ff) << 3 | *(uint *)(iVar20 + 0x18) & 0xffffe007;
            FUN_000b6f20(param_1,iVar20,uVar29,
                         *(undefined4 *)(&DAT_001db98c + (uint)*(byte *)(param_1 + 0x2941) * 4));
          }
        }
        else {
          uVar11 = 1 << (uVar29 & 0x3f);
          *(uint *)(param_1 + 0x1934) = uVar11 | *(uint *)(param_1 + 0x1934);
          if ((uVar29 == *(uint *)(param_1 + 0x276c)) && (*(int *)(param_1 + 0x2768) != 0)) {
            iVar20 = *(int *)(*(int *)(param_1 + 0x2768) + 0xbc);
          }
          else {
            iVar20 = *(int *)(((unsigned char *)0x000013f8) + iVar25);
            if (iVar20 == 0) {
              *(uint *)(param_1 + 0x27b0) = ~uVar11 & *(uint *)(param_1 + 0x27b0);
              *(uint *)(param_1 + 0x27b4) = ~uVar11 & *(uint *)(param_1 + 0x27b4);
              goto LAB_0004e760;
            }
          }
          if ((*(uint *)(param_1 + 0x44) & 0x20000) == 0) {
            if (((int)(uint)*(byte *)(param_1 + 0x20) >> (uVar29 & 0x3f) & 1U) == 0) {
              bVar6 = false;
              iVar16 = uVar29 << 2;
              *(uint *)(param_1 + 0x27b4) = *(uint *)(param_1 + 0x27b4) & ~uVar11;
            }
            else {
              iVar16 = uVar29 * 0x10;
              uVar13 = *(uint *)(iVar26 + 0x2854);
              uVar12 = *(uint *)(iVar26 + 0x2858);
              iVar15 = iVar10 + iVar16;
              if (*(char *)(iVar17 + 0x21) == '\x01') {
                fVar2 = (float)((double)CONCAT44(0x43300000,*(uint *)(iVar26 + 0x285c) ^ 0x80000000)
                               - dVar7);
                *(float *)(iVar10 + iVar16) =
                     *(float *)(iVar20 + 0x44) /
                     (float)((double)CONCAT44(0x43300000,uVar13 ^ 0x80000000) - dVar7);
                *(float *)(iVar15 + 4) = *(float *)(iVar20 + 0x44) / fVar2;
                fVar5 = (float)((double)CONCAT44(0x43300000,uVar13 + uVar12 ^ 0x80000000) - dVar7) *
                        FLOAT_001aa10c;
                *(float *)(iVar15 + 8) =
                     -(float)((double)CONCAT44(0x43300000,uVar12 ^ 0x80000000) - dVar7) / fVar2;
                *(float *)(iVar15 + 0xc) = fVar5 / *(float *)(iVar20 + 0x44);
              }
              else {
                fVar2 = (float)((double)CONCAT44(0x43300000,*(uint *)(iVar26 + 0x285c) ^ 0x80000000)
                               - dVar7);
                *(float *)(iVar10 + iVar16) =
                     *(float *)(iVar20 + 0x48) /
                     (float)((double)CONCAT44(0x43300000,uVar13 ^ 0x80000000) - dVar7);
                *(float *)(iVar15 + 4) = *(float *)(iVar20 + 0x48) / fVar2;
                fVar5 = (float)((double)CONCAT44(0x43300000,uVar13 + uVar12 ^ 0x80000000) - dVar7) *
                        FLOAT_001aa10c;
                *(float *)(iVar15 + 8) =
                     -(float)((double)CONCAT44(0x43300000,uVar12 ^ 0x80000000) - dVar7) / fVar2;
                *(float *)(iVar15 + 0xc) = fVar5 / *(float *)(iVar20 + 0x48);
              }
              iVar16 = uVar29 << 2;
              ((int (*)())FUN_0004de30)(param_1,0,uVar29 + 0x14,uVar29 + 0x14,iVar15,1,0);
              bVar6 = false;
              *(uint *)(param_1 + 0x27b4) = uVar11 | *(uint *)(param_1 + 0x27b4);
            }
          }
          else {
            iVar16 = uVar29 * 4;
            sVar3 = *(short *)(iVar20 + 0x38);
            *(uint *)(iVar16 + *(int *)(((unsigned char *)0x00001144) + param_1) + 0x2c) =
                 (uint)*(byte *)(iVar20 + 0x30);
            iVar15 = *(int *)(((unsigned char *)0x00001154) + param_1);
            if (*(int *)(iVar15 + 4) != 0) {
              uVar13 = 0;
              iVar14 = 0;
              do {
                iVar21 = *(int *)(*(int *)(((unsigned char *)0x0000113c) + param_1) * 4 +
                                 *(int *)(iVar14 + *(int *)(iVar15 + 0x88) + 0x70));
                if ((iVar21 != 0) &&
                   ((bool)((unsigned char *)0x00002eb0)[uVar29 + iVar21] != (*(char *)(iVar20 + 0x30) == '\x02')))
                {
                  *(undefined4 *)(((unsigned char *)0x000016f0) + iVar21) = 1;
                  *(undefined1 *)(iVar21 + 0x119) = 1;
                  iVar15 = *(int *)(((unsigned char *)0x00001154) + param_1);
                }
                uVar13 = uVar13 + 1;
                iVar14 = iVar14 + 0x78;
              } while (uVar13 < *(uint *)(iVar15 + 4));
            }
            if ((*(uint *)(param_1 + 0x44) & 0x2000) == 0) {
LAB_0004e294:
              bVar6 = false;
            }
            else {
              iVar15 = *(int *)(*(int *)(((unsigned char *)0x00001130) + param_1) * 4 +
                               *(int *)(*(int *)(((unsigned char *)0x0000121c) + param_1) + 0x70));
              if (iVar15 != 0) {
                iVar14 = iVar15 + 0x124;
              }
              else {
                iVar14 = 0;
              }
              uVar13 = 0;
              if (sVar3 == 0x1902) {
                uVar12 = (*(ushort *)(iVar20 + 0x5c) - 0x200) * 2;
                uVar13 = uVar12 | 1;
                if (*(short *)(iVar20 + 0x58) == 0x1909) {
                  uVar13 = uVar12 | 0x11;
                }
                else if (*(short *)(iVar20 + 0x58) == -0x7fb7) {
                  uVar13 = uVar12 | 0x21;
                }
              }
              if (iVar14 == 0) goto LAB_0004e294;
              if ((uVar13 != *(uint *)(((unsigned char *)0x000015d0) + iVar16 + iVar14)) &&
                 (*(undefined4 *)(((unsigned char *)0x000015cc) + iVar14) = 1, iVar15 != 0)) {
                *(undefined1 *)(iVar15 + 0x119) = 1;
              }
              if (((unsigned char *)0x00001610)[uVar29 + iVar14] == '\0') goto LAB_0004e294;
              bVar6 = true;
              if (*(float *)(((unsigned char *)0x00001620) + iVar16 + iVar14) !=
                  *(float *)(iVar20 + 0x4c) + *(float *)(iVar27 + 0x470)) {
                iVar15 = *(int *)(*(int *)(((unsigned char *)0x00001130) + param_1) * 4 +
                                 *(int *)(*(int *)(((unsigned char *)0x0000121c) + param_1) + 0x70));
                if (iVar15 != 0) {
                  *(undefined1 *)(iVar15 + 0x119) = 1;
                }
                bVar6 = true;
                *(undefined4 *)(((unsigned char *)0x000015cc) + iVar14) = 1;
              }
            }
            *(uint *)(param_1 + 0x27b4) = *(uint *)(param_1 + 0x27b4) & ~uVar11;
          }
          *(uint *)(param_1 + 0x27b0) = uVar11 | *(uint *)(param_1 + 0x27b0);
          *(undefined4 *)(iVar30 + 0x1d5c) = *(undefined4 *)(iVar20 + 0x1c);
          *(undefined4 *)(((unsigned char *)0x00001d9c) + iVar30) = *(undefined4 *)(iVar20 + 0x20);
          *(undefined4 *)(((unsigned char *)0x00001ddc) + iVar30) = *(undefined4 *)(iVar20 + 0x24);
          *(undefined4 *)(((unsigned char *)0x00001e1c) + iVar16 + param_1) = *(undefined4 *)(iVar20 + 0x28);
          *(uint *)(iVar30 + 0x1cdc) = uVar9 << 0x1c | *(uint *)(iVar20 + 0x14) & 0xfffffff;
          uVar13 = *(uint *)(iVar20 + 0x18);
          if (bVar6) {
            uVar13 = uVar13 & 0xffffe007;
          }
          else if (*(float *)(iVar20 + 0x4c) == FLOAT_001aa0d4) {
            uVar13 = (*(ushort *)(iVar27 + 0x46e) & 0x3ff) << 3 | uVar13 & 0xffffe007;
          }
          else {
            uVar12 = ((int (*)())FUN_00086930)((double)*(float *)(iVar27 + 0x470),param_1);
            uVar13 = (uVar12 & 0x3ff) << 3 | uVar13 & 0xffffe007;
          }
          *(uint *)(iVar30 + 0x1d1c) = uVar13;
          FUN_000b6f20(param_1,iVar20,uVar29,
                       *(undefined4 *)(&DAT_001db98c + (uint)*(byte *)(param_1 + 0x2941) * 4));
          uVar13 = *(uint *)(iVar20 + 0x14);
          if ((uVar13 & 0x1e00) == 0xa00) {
            if ((uVar13 & 7) == 4) {
              *(uint *)(iVar16 + param_1 + 0x1cdc) =
                   *(uint *)(iVar16 + param_1 + 0x1cdc) & 0xfffffff8 | 2;
              uVar13 = *(uint *)(iVar20 + 0x14);
            }
            else if ((uVar13 & 7) == 5) {
              *(uint *)(iVar16 + param_1 + 0x1cdc) =
                   *(uint *)(iVar16 + param_1 + 0x1cdc) & 0xfffffff8 | 3;
              uVar13 = *(uint *)(iVar20 + 0x14);
            }
            if ((uVar13 & 0x38) == 0x20) {
              *(uint *)(iVar16 + param_1 + 0x1cdc) =
                   *(uint *)(iVar16 + param_1 + 0x1cdc) & 0xffffffc7 | 0x10;
              uVar13 = *(uint *)(iVar20 + 0x14);
            }
            else if ((uVar13 & 0x38) == 0x28) {
              *(uint *)(iVar16 + param_1 + 0x1cdc) =
                   *(uint *)(iVar16 + param_1 + 0x1cdc) & 0xffffffc7 | 0x18;
              uVar13 = *(uint *)(iVar20 + 0x14);
            }
            if ((uVar13 & 0x1c0) == 0x100) {
              *(uint *)(iVar16 + param_1 + 0x1cdc) =
                   *(uint *)(iVar16 + param_1 + 0x1cdc) & 0xfffffe3f | 0x80;
            }
            else if ((uVar13 & 0x1c0) == 0x140) {
              *(uint *)(iVar16 + param_1 + 0x1cdc) =
                   *(uint *)(iVar16 + param_1 + 0x1cdc) & 0xfffffe3f | 0xc0;
            }
          }
          cVar8 = *(char *)(iVar20 + 0x31);
          if (cVar8 != '\x03') {
            *(uint *)(iVar16 + param_1 + 0x1cdc) = *(uint *)(iVar16 + param_1 + 0x1cdc) & 0xfffffe3f
            ;
            cVar8 = *(char *)(iVar20 + 0x31);
          }
          if (cVar8 == '\x01') {
            *(uint *)(iVar16 + param_1 + 0x1cdc) = *(uint *)(iVar16 + param_1 + 0x1cdc) & 0xffffffc7
            ;
          }
          iVar16 = iVar16 + param_1;
          *(uint *)(iVar16 + 0x1d1c) =
               (*(ushort *)(iVar27 + 0x46e) & 0x3ff) << 3 | *(uint *)(iVar16 + 0x1d1c) & 0xffffe007;
          if ((uVar11 & *(uint *)(param_1 + 0x27b4)) != 0) {
            *(undefined4 *)(iVar30 + 0x1cfc) = *(undefined4 *)(iVar30 + 0x1cdc);
            *(uint *)(iVar28 + 0x1cdc) =
                 (uVar9 + 8) * 0x10000000 | *(uint *)(iVar28 + 0x1cdc) & 0xfffffff;
            uVar18 = *(undefined4 *)(((unsigned char *)0x00001d9c) + iVar30);
            uVar22 = *(undefined4 *)(((unsigned char *)0x00001ddc) + iVar30);
            uVar19 = *(undefined4 *)(((unsigned char *)0x00001e1c) + iVar30);
            *(undefined4 *)(iVar30 + 0x1d3c) = *(undefined4 *)(iVar30 + 0x1d1c);
            *(undefined4 *)(((unsigned char *)0x00001d7c) + iVar30) = *(undefined4 *)(iVar30 + 0x1d5c);
            *(undefined4 *)(((unsigned char *)0x00001dbc) + iVar30) = uVar18;
            *(undefined4 *)(((unsigned char *)0x00001dfc) + iVar30) = uVar22;
            *(undefined4 *)(iVar30 + 0x1e3c) = uVar19;
            if (*(char *)(iVar17 + 0x21) == '\x01') {
              *(uint *)(iVar16 + 0x1d5c) =
                   *(int *)(iVar26 + 0x2854) - 1U & 0x7ff | *(uint *)(iVar16 + 0x1d5c) & 0xfffff800;
              *(uint *)(iVar28 + 0x1d5c) =
                   *(int *)(iVar26 + 0x285c) - 1U & 0x7ff | *(uint *)(iVar28 + 0x1d5c) & 0xfffff800;
            }
            else {
              *(uint *)(iVar16 + 0x1d5c) =
                   (*(int *)(iVar26 + 0x2854) + -1) * 0x800 & 0x3ff800U |
                   *(uint *)(iVar16 + 0x1d5c) & 0xffc007ff;
              *(uint *)(iVar28 + 0x1d5c) =
                   (*(int *)(iVar26 + 0x285c) + -1) * 0x800 & 0x3ff800U |
                   *(uint *)(iVar28 + 0x1d5c) & 0xffc007ff;
            }
          }
        }
      }
LAB_0004e760:
      uVar23 = uVar23 >> 1;
      uVar29 = uVar29 + 1;
      uVar9 = uVar9 + 1 & 0xf;
      iVar28 = iVar28 + 4;
      iVar30 = iVar30 + 4;
      iVar27 = iVar27 + 0xcc;
      iVar26 = iVar26 + 0xc;
      iVar25 = iVar25 + 4;
      iVar17 = iVar17 + 1;
    } while (uVar23 != 0);
    iVar17 = *(int *)(param_1 + 0x27b4);
    uVar9 = *(uint *)(param_1 + 0x27b0);
  }
  uVar23 = *(uint *)(param_1 + 0x44);
  *(uint *)(param_1 + 0x27b0) = iVar17 << 8 | uVar9;
  if (((uVar23 & 0x100000) != 0) && (*(code **)((int)((unsigned char *)0x000011cc) + param_1) != (code *)0x0)) {
    (**(code **)((int)((unsigned char *)0x000011cc) + param_1))(param_1);
    uVar23 = *(uint *)(param_1 + 0x44);
  }
  if ((uVar23 & 0x20000) == 0) {
    FUN_000b6580(param_1,0);
                    
                    
    (**(code **)(param_1 + 0x294c))(param_1,*(undefined4 *)(param_1 + 0x1e5c));
    return;
  }
  if ((uVar23 & 0x2000) == 0) {
    FUN_000b3630(param_1);
    return;
  }
  FUN_000afe40(param_1,0);
  return;
}

/* FUN_0004e880 @ 0x4e880 (252 bytes) */
int FUN_0004e880(param_1)
  int param_1;
{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
  if (*(int *)(param_1 + 0x243c) != 0) {
    uVar1 = *(int *)(param_1 + 0x243c) + 1U >> 1;
    puVar2 = (uint *)(**(code **)(param_1 + 0x2758))(param_1,uVar1 * 2 + 2);
    *(uint **)(FUN_00002748 + param_1 + 4) = puVar2;
    uVar4 = (uVar1 - 1) * 0x10000;
    *puVar2 = uVar4 | 0x854;
    puVar2[uVar1 + 1] = uVar4 | 0x878;
    if (uVar1 != 0) {
      iVar3 = 0;
      uVar4 = uVar1;
      do {
        *(undefined4 *)((int)puVar2 + iVar3 + 4) =
             *(undefined4 *)(iVar3 + *(int *)(param_1 + 0x2440));
        *(undefined4 *)((int)puVar2 + iVar3 + uVar1 * 4 + 8) =
             *(undefined4 *)(iVar3 + *(int *)(param_1 + 0x2444));
        iVar3 = iVar3 + 4;
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
    }
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
    *(uint *)(FUN_00002748 + param_1 + 4) = uVar1 * 8 + *(int *)(FUN_00002748 + param_1 + 4) + 8;
                    
                    
    (*UNRECOVERED_JUMPTABLE)(param_1);
    return;
  }
  return;
}

/* FUN_0004e990 @ 0x4e990 (208 bytes) */
int FUN_0004e990(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  double dVar3;
  
  uVar1 = *(uint *)(*(int *)(param_1 + 4) + 0x154) & 0x30000;
  dVar3 = DOUBLE_001aa288;
  if (((uVar1 != 0x20000) && (uVar1 != 0x30000)) && (dVar3 = DOUBLE_001aa280, uVar1 == 0x10000)) {
    dVar3 = DOUBLE_001aa278;
  }
  dVar3 = dVar3 * *(double *)(((unsigned char *)0x00002d88) + *(int *)(*(int *)(param_1 + 4) + 0x10));
  if (DOUBLE_001aa1e8 <= dVar3) {
    iVar2 = (int)(dVar3 - DOUBLE_001aa1e8) + -0x80000000;
  }
  else {
    iVar2 = (int)dVar3;
  }
  return iVar2;
}

/* FUN_0004ea70 @ 0x4ea70 (260 bytes) */
int FUN_0004ea70(param_1)
  int param_1;
{
  short sVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(param_1 + 0x1b3c);
  iVar3 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (*(int *)(((unsigned char *)0x00003170) + iVar3) == 0x1b021b02) {
    uVar2 = uVar4 & 0xfffffffc;
    *(uint *)(param_1 + 0x1b3c) = uVar2;
  }
  else {
    *(uint *)(param_1 + 0x1b3c) = uVar4 & 0xfffffffc | 1;
    sVar1 = *(short *)(((unsigned char *)0x00003170) + iVar3);
    if (sVar1 == 0x1b01) {
      *(uint *)(param_1 + 0x1b3c) = uVar4 & 0xffffff8c | 0x11;
    }
    else if (sVar1 == 0x1b02) {
      *(uint *)(param_1 + 0x1b3c) = uVar4 & 0xffffff8c | 0x21;
    }
    else if (sVar1 == 0x1b00) {
      *(uint *)(param_1 + 0x1b3c) = uVar4 & 0xffffff8c | 1;
    }
    sVar1 = *(short *)(((unsigned char *)0x00003172) + iVar3);
    if (sVar1 == 0x1b01) {
      uVar2 = *(uint *)(param_1 + 0x1b3c) & 0xfffffc7f | 0x80;
      *(uint *)(param_1 + 0x1b3c) = uVar2;
    }
    else if (sVar1 == 0x1b02) {
      uVar2 = *(uint *)(param_1 + 0x1b3c) & 0xfffffc7f | 0x100;
      *(uint *)(param_1 + 0x1b3c) = uVar2;
    }
    else if (sVar1 == 0x1b00) {
      uVar2 = *(uint *)(param_1 + 0x1b3c) & 0xfffffc7f;
      *(uint *)(param_1 + 0x1b3c) = uVar2;
    }
    else {
      uVar2 = *(uint *)(param_1 + 0x1b3c);
    }
  }
  if (uVar4 != uVar2) {
    *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x2000;
  }
  FUN_0004d770();
  return;
}

/* FUN_0004eba0 @ 0x4eba0 (476 bytes) */
int FUN_0004eba0(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 4);
  iVar4 = *(int *)(param_1 + 0x2768);
  iVar3 = *(int *)(param_1 + 8);
  if ((((((unsigned char *)0x00002e2d)[*(int *)(iVar1 + 0x10)] == '\0') ||
       ((*(uint *)(param_1 + 0x44) & 0x20000) != 0)) ||
      (iVar1 = FUN_0001a010(iVar1,*(undefined4 *)(((unsigned char *)0x000026a0) + iVar1)), iVar1 != 0)) ||
     (iVar4 == 0)) {
    iVar1 = ((uint (*)())FUN_000a3560)((double)*(float *)(((unsigned char *)0x00002e20) + *(int *)(*(int *)(param_1 + 4) + 0x10)),
                         param_1);
    uVar2 = *(undefined4 *)(((unsigned char *)0x000026a0) + *(int *)(param_1 + 4));
    *(short *)(param_1 + 0x1b42) = (short)((uint)(iVar3 * iVar1) >> 1);
    iVar1 = FUN_0001a010(*(int *)(param_1 + 4),uVar2);
    if (iVar1 == 0) {
      *(uint *)(param_1 + 0x1b40) = *(uint *)(param_1 + 0x1b40) & 0xfffcffff | 0x20000;
    }
    else {
      *(uint *)(param_1 + 0x1b40) = *(uint *)(param_1 + 0x1b40) & 0xfffcffff | 0x30000;
    }
  }
  else {
    *(short *)(param_1 + 0x1b42) = (short)*(undefined4 *)(iVar4 + 0x18);
    *(uint *)(param_1 + 0x1b40) = *(uint *)(param_1 + 0x1b40) & 0xfffcffff | 0x30000;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (((((unsigned char *)0x00002e2c)[iVar1] != '\0') && ((*(uint *)(param_1 + 0x44) & 0x20000) == 0)) &&
     (*(short *)(((unsigned char *)0x00002e28) + iVar1) != -1)) {
    *(uint *)(param_1 + 0x1b64) =
         (uint)(FLOAT_001aa0e8 /
               ((float)((double)CONCAT44(0x43300000,*(uint *)(((unsigned char *)0x00002e24) + iVar1) ^ 0x80000000) -
                       DOUBLE_001aa1e0) * FLOAT_001aa0fc *
               (float)((double)CONCAT44(0x43300000,iVar3) - DOUBLE_001aa250))) & 0xfffffffc |
         *(uint *)(param_1 + 0x1b64) & 3;
  }
  if (iVar4 != 0) {
    *(undefined4 *)(param_1 + 0x1b70) = *(undefined4 *)(iVar4 + 0x24);
  }
  *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x4000;
  FUN_0004d770(param_1);
  return;
}

/* FUN_0004ed90 @ 0x4ed90 (692 bytes) */
int FUN_0004ed90(param_1)
  int param_1;
{
  float fVar1;
  float fVar2;
  undefined2 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = *(int *)(param_1 + 0x2768);
  iVar6 = *(int *)(param_1 + 8);
  iVar4 = FUN_000a3670();
  uVar5 = *(uint *)(param_1 + 0x44);
  if (((uVar5 & 0x60020000) == 0x40000000) && (iVar7 != 0)) {
    *(short *)(param_1 + 0x1ccc) = (short)*(undefined4 *)(iVar7 + 4);
    *(short *)(param_1 + 0x1cce) = (short)*(undefined4 *)(iVar7 + 4);
    *(undefined4 *)(param_1 + 0x1cc0) = *(undefined4 *)(iVar7 + 0xc);
    *(undefined4 *)(param_1 + 0x1cc8) = *(undefined4 *)(iVar7 + 0x10);
  }
  else {
    if (iVar4 == 0) {
      uVar3 = (undefined2)((uint)(iVar6 * *(int *)(param_1 + 0xe4)) >> 1);
    }
    else {
      uVar3 = (undefined2)((uint)(iVar6 * (int)(*(float *)(param_1 + 0xf0) + FLOAT_001aa10c)) >> 1);
    }
    *(undefined2 *)(param_1 + 0x1cce) = uVar3;
    *(undefined2 *)(param_1 + 0x1ccc) = uVar3;
  }
  if ((uVar5 & 0x60020000) == 0x40000000) {
    if (iVar4 == 0) {
      fVar1 = *(float *)(param_1 + 0x100) + FLOAT_001aa0e8;
      fVar2 = *(float *)(param_1 + 0x104) + FLOAT_001aa0e8;
    }
    else {
      if ((uVar5 & 0x80) != 0) {
        fVar2 = *(float *)(((unsigned char *)0x000013c4) + param_1);
        fVar1 = (float)((double)CONCAT44(0x43300000,iVar6) - DOUBLE_001aa250);
        *(short *)(param_1 + 0x1cd0) =
             (short)((int)(fVar1 * *(float *)((*(unsigned char *)0x000013c8) + param_1)) >> 1);
        *(short *)(param_1 + 0x1cd2) = (short)((int)(fVar1 * fVar2) >> 1);
        goto LAB_0004efc0;
      }
      fVar1 = *(float *)(param_1 + 0x100);
      fVar2 = *(float *)(param_1 + 0x104);
    }
    *(short *)(param_1 + 0x1cd2) = (short)((uint)(iVar6 * (int)fVar1) >> 1);
    *(short *)(param_1 + 0x1cd0) = (short)((uint)(iVar6 * (int)fVar2) >> 1);
  }
  else if ((uVar5 & 0x80) == 0) {
    *(short *)(param_1 + 0x1cd2) = (short)((uint)(iVar6 * *(int *)(param_1 + 0x108)) >> 1);
    *(short *)(param_1 + 0x1cd0) = (short)((uint)(iVar6 * *(int *)(param_1 + 0x10c)) >> 1);
  }
  else {
    iVar4 = *(int *)(((unsigned char *)0x000013d4) + param_1);
    *(short *)(param_1 + 0x1cd2) = (short)(iVar6 * *(int *)(((unsigned char *)0x000013d0) + param_1) >> 1);
    *(short *)(param_1 + 0x1cd0) = (short)(iVar6 * iVar4 >> 1);
  }
LAB_0004efc0:
  *(uint *)(param_1 + 0x1b74) = *(uint *)(param_1 + 0x1b74) & 0xffff3fff;
  if ((uVar5 & 0x20000000) == 0) {
    *(undefined4 *)(param_1 + 0x1cbc) = 0;
    *(undefined4 *)(param_1 + 0x1cc4) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x1cc0) = 0x3f800000;
    *(undefined4 *)(param_1 + 0x1cbc) = 0;
    *(undefined4 *)(param_1 + 0x1cc4) = 0x3f800000;
    *(undefined4 *)(param_1 + 0x1cc8) = 0;
  }
  if (*(int *)(param_1 + 0x2768) == 0) {
    if ((uVar5 & 0x20000000) == 0) {
      *(undefined4 *)(param_1 + 0x1b50) = 7;
      if ((*(uint *)(param_1 + 0x1a64) & 0x10) != 0) {
        *(uint *)(param_1 + 0x1a64) = *(uint *)(param_1 + 0x1a64) & 0xffffffef;
        uVar5 = *(uint *)(param_1 + 0x1930) | 0x2000;
        *(uint *)(param_1 + 0x1930) = uVar5;
        goto LAB_0004f054;
      }
    }
  }
  uVar5 = *(uint *)(param_1 + 0x1930);
LAB_0004f054:
  *(uint *)(param_1 + 0x1930) = uVar5 | 0xc08000;
  FUN_0004d770(param_1);
  return;
}

/* FUN_0004f080 @ 0x4f080 (192 bytes) */
int FUN_0004f080(param_1)
  int param_1;
{
  short sVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (((unsigned char *)0x000013b8)[param_1] == '\0') {
    if (*(short *)(((unsigned char *)0x00003174) + iVar3) == 0x900) goto LAB_0004f0c0;
  }
  else if (*(short *)(((unsigned char *)0x00003174) + iVar3) != 0x900) {
LAB_0004f0c0:
    uVar2 = *(uint *)(((unsigned char *)0x00001b30) + param_1) & 0xfffffffb;
    *(uint *)(((unsigned char *)0x00001b30) + param_1) = uVar2;
    goto LAB_0004f0dc;
  }
  uVar2 = *(uint *)(((unsigned char *)0x00001b30) + param_1) | 4;
  *(uint *)(((unsigned char *)0x00001b30) + param_1) = uVar2;
LAB_0004f0dc:
  if (((unsigned char *)0x0000317a)[iVar3] == '\0') {
    *(uint *)(((unsigned char *)0x00001b30) + param_1) = uVar2 & 0xfffffffc;
  }
  else {
    sVar1 = *(short *)(((unsigned char *)0x00003176) + iVar3);
    if (sVar1 == 0x405) {
      *(uint *)(((unsigned char *)0x00001b30) + param_1) = uVar2 & 0xfffffffe | 2;
    }
    else if (sVar1 == 0x408) {
      *(uint *)(((unsigned char *)0x00001b30) + param_1) = uVar2 | 3;
    }
    else if (sVar1 == 0x404) {
      *(uint *)(((unsigned char *)0x00001b30) + param_1) = uVar2 & 0xfffffffd | 1;
    }
  }
  *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x400;
  return;
}

/* FUN_0004f160 @ 0x4f160 (352 bytes) */
int FUN_0004f160(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  double dVar4;
  
  iVar2 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (param_2 == 2) {
    dVar4 = (double)(*(float *)(((unsigned char *)0x00002de4) + iVar2) * FLOAT_001aa0f0);
    if (DOUBLE_001aa1e8 <= dVar4) {
      uVar1 = (int)(dVar4 - DOUBLE_001aa1e8) + 0x80000000;
    }
    else {
      uVar1 = (uint)(*(float *)(((unsigned char *)0x00002de4) + iVar2) * FLOAT_001aa0f0);
    }
  }
  else if (param_2 == 3) {
    dVar4 = (double)(*(float *)(((unsigned char *)0x00002de8) + iVar2) * FLOAT_001aa0f0);
    if (DOUBLE_001aa1e8 <= dVar4) {
      uVar1 = (int)(dVar4 - DOUBLE_001aa1e8) + 0x80000000;
    }
    else {
      uVar1 = (uint)(*(float *)(((unsigned char *)0x00002de8) + iVar2) * FLOAT_001aa0f0);
    }
  }
  else {
    if (param_2 != 1) {
      uVar1 = 0;
      uVar3 = 0;
      goto LAB_0004f2c8;
    }
    dVar4 = (double)(*(float *)(((unsigned char *)0x00002de0) + iVar2) * FLOAT_001aa0f0);
    if (DOUBLE_001aa1e8 <= dVar4) {
      uVar1 = (int)(dVar4 - DOUBLE_001aa1e8) + 0x80000000;
    }
    else {
      uVar1 = (uint)(*(float *)(((unsigned char *)0x00002de0) + iVar2) * FLOAT_001aa0f0);
    }
  }
  uVar3 = uVar1 >> 6;
  uVar1 = uVar1 << 2;
LAB_0004f2c8:
  return uVar3 & 3 | uVar1;
}

/* FUN_0004f2e0 @ 0x4f2e0 (616 bytes) */
int FUN_0004f2e0(param_1)
  int param_1;
{
  byte bVar1;
  short sVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  
  puVar3 = PTR_DAT_001e88c8;
  bVar1 = *(byte *)(param_1 + 0x293f);
  if ((*(uint *)(param_1 + 0x44) & 0x1002000) == 0x1000000) {
    iVar4 = *(int *)(*(int *)(param_1 + 4) + 0x10);
    sVar2 = *(short *)(((unsigned char *)0x00002e04) + iVar4);
    if (sVar2 == 0x801) {
      *(undefined4 *)(param_1 + 0x134) = 0;
      *(float *)(param_1 + 0x138) =
           -(*(float *)(((unsigned char *)0x00002df0) + iVar4) * *(float *)(((unsigned char *)0x00002df0) + iVar4));
    }
    else if (sVar2 == 0x2601) {
      *(float *)(param_1 + 0x134) =
           *(float *)(((unsigned char *)0x00002df8) + iVar4) * *(float *)(((unsigned char *)0x00002dfc) + iVar4);
      *(float *)(param_1 + 0x138) = -*(float *)(((unsigned char *)0x00002dfc) + iVar4);
    }
    else if (sVar2 == 0x800) {
      *(undefined4 *)(param_1 + 0x134) = 0;
      *(float *)(param_1 + 0x138) = -*(float *)(((unsigned char *)0x00002df0) + iVar4);
    }
    *(uint *)(param_1 + 0x18a4) = *(uint *)(param_1 + 0x18a4) & 0xfdffffff;
    *(uint *)(param_1 + 0x1a64) = *(uint *)(param_1 + 0x1a64) & 0xfffffff8 | 1;
    *(uint *)(param_1 + 0x1878) = *(uint *)(param_1 + 0x1878) & 0xffefffff;
    *(uint *)(param_1 + 0x1aec) = *(uint *)(param_1 + 0x1aec) & 0xfffffff9 | 1;
    *(undefined4 *)(param_1 + 0x1a78) = 0x3f800000;
    *(undefined4 *)(param_1 + 0x1a7c) = 0xbf800000;
    if (*(char *)(param_1 + 0x121) != '\0') {
      *(undefined1 *)(param_1 + 0x121) = 0;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
    }
  }
  else {
    *(uint *)(param_1 + 0x1aec) = *(uint *)(param_1 + 0x1aec) & 0xfffffffe;
    *(uint *)(param_1 + 0x18a4) = *(uint *)(param_1 + 0x18a4) & 0xfdffffff;
    *(uint *)(param_1 + 0x1878) = *(uint *)(param_1 + 0x1878) & 0xffefffff;
    if (*(char *)(param_1 + 0x121) != '\0') {
      *(undefined1 *)(param_1 + 0x121) = 0;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
    }
  }
  if ((*(uint *)(param_1 + 0x44) & 0x20000) == 0) {
    FUN_000b6580(param_1,0);
    (**(code **)(param_1 + 0x294c))(param_1,*(undefined4 *)(param_1 + 0x1e5c));
  }
  else if ((*(uint *)(param_1 + 0x44) & 0x2000) == 0) {
    FUN_000b3630(param_1);
  }
  else {
    FUN_000afe40(param_1,0);
  }
  uVar5 = ((int (*)())FUN_0004f160)(param_1,*(uint *)(puVar3 + (uint)bVar1 * 0x24 + 0x1c) >> 0x1e);
  *(uint *)(param_1 + 0x1a54) = uVar5 & 0x3ff | *(uint *)(param_1 + 0x1a54) & 0xfffffc00;
  uVar5 = ((int (*)())FUN_0004f160)(param_1,*(uint *)(puVar3 + (uint)bVar1 * 0x24 + 0x18) >> 1 & 3);
  *(uint *)(param_1 + 0x1a58) = uVar5 & 0x3ff | *(uint *)(param_1 + 0x1a58) & 0xfffffc00;
  uVar5 = ((int (*)())FUN_0004f160)(param_1,*(uint *)(puVar3 + (uint)bVar1 * 0x24 + 0x18) >> 3 & 3);
  *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 1;
  *(uint *)(param_1 + 0x1a5c) = uVar5 & 0x3ff | *(uint *)(param_1 + 0x1a5c) & 0xfffffc00;
  return;
}

/* FUN_0004f550 @ 0x4f550 (452 bytes) */
int FUN_0004f550(param_1)
  int param_1;
{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar3 = 0;
  uVar4 = (uint)((float)((double)CONCAT44(0x43300000,*(uint *)(((unsigned char *)0x00001358) + param_1) ^ 0x80000000
                                         ) - DOUBLE_001aa1e0) * *(float *)(param_1 + 0x2814));
  uVar2 = (uint)(*(float *)(param_1 + 0x2818) *
                 (float)((double)CONCAT44(0x43300000,*(uint *)(((unsigned char *)0x00001364) + param_1) ^ 0x80000000
                                         ) - DOUBLE_001aa1e0) - FLOAT_001aa0e8);
  uVar5 = (uint)((float)((double)CONCAT44(0x43300000,*(uint *)(((unsigned char *)0x0000135c) + param_1) ^ 0x80000000
                                         ) - DOUBLE_001aa1e0) * *(float *)(param_1 + 0x2818));
  uVar7 = (uint)(*(float *)(param_1 + 0x2814) *
                 (float)((double)CONCAT44(0x43300000,*(uint *)(((unsigned char *)0x00001360) + param_1) ^ 0x80000000
                                         ) - DOUBLE_001aa1e0) - FLOAT_001aa0e8);
  if (-1 < (int)uVar4) {
    uVar3 = uVar4 & 0xffff;
  }
  if ((int)(uint)*(ushort *)(((unsigned char *)0x000013bc) + param_1) < (int)uVar7) {
    uVar7 = (uint)*(ushort *)(((unsigned char *)0x000013bc) + param_1);
  }
  if (((unsigned char *)0x000013b8)[param_1] == '\0') {
    uVar4 = 0;
    if (-1 < (int)uVar5) {
      uVar4 = uVar5 & 0xffff;
    }
    if ((int)(*(ushort *)(((unsigned char *)0x000013ba) + param_1) - 1) < (int)uVar2) {
      uVar2 = *(ushort *)(((unsigned char *)0x000013ba) + param_1) - 1;
    }
  }
  else {
    uVar4 = 0xffff;
    if (-2 < (int)uVar5) {
      uVar4 = uVar5 & 0xffff;
    }
    if ((int)(uint)*(ushort *)(((unsigned char *)0x000013ba) + param_1) < (int)uVar2) {
      uVar2 = (uint)*(ushort *)(((unsigned char *)0x000013ba) + param_1);
    }
  }
  uVar6 = *(uint *)(param_1 + 7000);
  uVar5 = *(uint *)(param_1 + 0x1b10);
  uVar4 = (uVar4 & 0x1fff) << 0xd | uVar3 & 0x1fff | uVar6 & 0xfc000000;
  uVar2 = (uVar2 & 0x1fff) << 0xd | uVar7 & 0x1fff | uVar5 & 0xfc000000;
  *(uint *)(param_1 + 7000) = uVar4;
  *(uint *)(param_1 + 0x1b10) = uVar2;
  if ((uVar6 != uVar4) || (bVar1 = false, uVar5 != uVar2)) {
    bVar1 = true;
  }
  if (bVar1) {
    *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 2;
    return;
  }
  return;
}

/* FUN_0004f720 @ 0x4f720 (1348 bytes) */
int FUN_0004f720(param_1)
  int param_1;
{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  *(undefined4 *)(param_1 + 0x1bd0) = 0;
  *(undefined4 *)(param_1 + 0x1930) = 0;
  *(undefined4 *)(param_1 + 0x1934) = 0;
  *(undefined4 *)(param_1 + 0x1938) = 0;
  *(undefined4 *)(param_1 + 0x193c) = 0;
  *(undefined4 *)(param_1 + 0x1a4c) = 0;
  *(undefined4 *)(param_1 + 0x1a50) = 0;
  *(undefined4 *)(param_1 + 0x1a54) = 0;
  *(undefined4 *)(param_1 + 0x1a58) = 0;
  *(undefined4 *)(param_1 + 0x1a5c) = 0;
  *(undefined4 *)(param_1 + 0x1aec) = 0;
  *(undefined4 *)(param_1 + 0x1bcc) = 0;
  if ((*(uint *)(param_1 + 0x2454) & 0x8000000) != 0) {
    *(undefined4 *)(param_1 + 0x1bcc) = 1;
  }
  if (*(int *)(param_1 + 0x23dc) == 2) {
    *(uint *)(param_1 + 0x1bd0) = *(uint *)(param_1 + 0x1bd0) & 0xfffffffc | 3;
  }
  else {
    *(uint *)(param_1 + 0x1bd0) = *(uint *)(param_1 + 0x1bd0) & 0xfffffffc | 1;
  }
  uVar5 = *(uint *)(FUN_00001af4 + param_1);
  uVar4 = *(uint *)(param_1 + 0x1af8);
  *(undefined4 *)(param_1 + 0x1b70) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x1cc0) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x1cc8) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x1b4c) = 2;
  *(undefined4 *)(param_1 + 0x1a64) = 0;
  *(undefined4 *)(param_1 + 0x1cbc) = 0;
  *(undefined4 *)(param_1 + 0x1cc4) = 0;
  *(undefined4 *)(param_1 + 0x1ccc) = 0;
  *(undefined4 *)(param_1 + 0x1cd0) = 0;
  *(undefined4 *)(param_1 + 0x1b64) = 0;
  *(undefined4 *)(param_1 + 0x1b68) = 0;
  *(undefined4 *)(param_1 + 0x1b6c) = 0;
  *(undefined4 *)(param_1 + 0x1a70) = 0;
  *(undefined4 *)(param_1 + 0x1a74) = 0;
  *(undefined4 *)(param_1 + 0x1b3c) = 0;
  *(undefined4 *)(param_1 + 0x1b44) = 0;
  *(undefined4 *)(param_1 + 0x1a78) = 0;
  *(undefined4 *)(param_1 + 0x1a7c) = 0;
  *(undefined4 *)(param_1 + 0x1a60) = 0;
  *(undefined4 *)(param_1 + 0x1b54) = 0x50005;
  *(undefined4 *)(param_1 + 0x1b40) = 0x20000;
  *(undefined4 *)(param_1 + 0x1b50) = 7;
  *(undefined4 *)(((unsigned char *)0x00001b2c) + param_1) = 0x30000;
  *(undefined4 *)(param_1 + 0x1a6c) = 0x5666666;
  *(undefined4 *)(param_1 + 0x1a68) = 0x55666666;
  *(undefined4 *)(param_1 + 0x1a80) = 0x20220000;
  *(undefined1 *)(param_1 + 0x247c) = 1;
  *(undefined4 *)(param_1 + 0x1b48) = 1;
  *(uint *)(FUN_00001af4 + param_1) = uVar5 | 0xf;
  *(undefined4 *)(param_1 + 8) = 0xc;
  *(undefined4 *)(param_1 + 0x23c0) = 0;
  uVar5 = *(uint *)(param_1 + 0x1abc);
  *(undefined4 *)(param_1 + 0x1af0) = 0;
  *(uint *)(param_1 + 0x1af8) = uVar4 & 0xfffffffb;
  *(undefined4 *)(param_1 + 0x1ae0) = 0;
  *(undefined4 *)(param_1 + 7000) = 0;
  *(undefined4 *)(param_1 + 0x1b10) = 0;
  *(undefined4 *)(param_1 + 0x1b60) = 0xffffff;
  *(undefined4 *)(param_1 + 0x1bd4) = 0;
  *(undefined4 *)(((unsigned char *)0x00001b30) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x00001b14) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x00001b28) + param_1) = 0;
  *(undefined4 *)(param_1 + 0x27b0) = 0;
  *(uint *)(param_1 + 0x1abc) = uVar5 & 0xc0000000 | 0x2da49525;
  _memset((void *)(param_1 + 0x1cdc),0,0x40);
  *(undefined4 *)(FUN_00002348 + param_1) = 0x1b0f;
  *(undefined4 *)(param_1 + 0x233c) = 0x1b0f;
  *(undefined4 *)(param_1 + 0x2340) = 0x1b0f;
  *(undefined4 *)(param_1 + 0x2344) = 0x1b0f;
  FUN_0004ab60(param_1);
  uVar5 = *(uint *)(param_1 + 0x2454);
  *(undefined4 *)(param_1 + 0x1b7c) = 0x80006a;
  if ((int)uVar5 < 0) {
    *(undefined4 *)(param_1 + 0x1b7c) = 0x80086a;
  }
  else if ((uVar5 & 0x8000000) == 0) {
    if ((uVar5 & 0x2000000) == 0) {
      *(undefined4 *)(param_1 + 0x1b7c) = 0x80046a;
    }
    else {
      *(undefined4 *)(param_1 + 0x1b7c) = 0x80026a;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x1b7c) = 0x80056a;
  }
  *(undefined4 *)(param_1 + 0x1b80) = 2;
  *(undefined4 *)(param_1 + 0x1ca0) = 0;
  *(undefined4 *)(param_1 + 0x1b9c) = 0;
  *(undefined4 *)(param_1 + 0x1ba0) = 0;
  *(undefined4 *)(param_1 + 0x1cb4) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x1ca8) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x1cac) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x1cb0) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x1b74) = 0;
  *(undefined4 *)(param_1 + 0x1b98) = 0;
  *(undefined4 *)(param_1 + 0x1bc8) = 0;
  *(undefined4 *)(param_1 + 0x1ab0) = 0xc0800;
  *(undefined1 *)(param_1 + 0x23ec) = 1;
  *(undefined4 *)(param_1 + 0x1b84) = 0x43f;
  *(uint *)(param_1 + 0x1b7c) = *(uint *)(param_1 + 0x1b7c) & 0xffc3ffff | 0x300000;
  *(undefined4 *)(param_1 + 0x1b88) = 0xffff;
  *(undefined4 *)(param_1 + 0x1aa0) = 0x10;
  if (*(char *)(param_1 + 0x2451) != '\0') {
    *(undefined1 **)(param_1 + 0x1ab0) = ((unsigned char *)0x000c3800);
  }
  *(undefined4 *)(param_1 + 0x1aa8) = 0;
  *(undefined1 *)(param_1 + 0x1aab) = 0;
  *(undefined1 *)(param_1 + 0x1aa9) = 0xff;
  *(undefined1 *)(param_1 + 0x1aaa) = 0xff;
  *(undefined4 *)(param_1 + 0x1ae4) = 0;
  fVar1 = FLOAT_001aa150;
  *(undefined4 *)(param_1 + 0x1a98) = 0;
  *(undefined4 *)(param_1 + 0x1a9c) = 0;
  *(undefined4 *)(param_1 + 0x1afc) = 0;
  *(undefined4 *)(param_1 + 0x1ae8) = 0;
  *(undefined4 *)(param_1 + 0x1ab4) = 0;
  *(undefined4 *)(param_1 + 0x1aa4) = 0;
  *(float *)(param_1 + 0x1b38) = fVar1;
  *(undefined4 *)(param_1 + 0x1bd8) = 1;
  *(uint *)(param_1 + 0x1cd4) = *(uint *)(param_1 + 0x1cd4) & 0xfffc0003;
  *(undefined4 *)(param_1 + 0x2358) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x235c) = 0;
  *(uint *)(param_1 + 0x1cd8) = *(uint *)(param_1 + 0x1cd8) & 0xffffc00f;
  *(uint *)(param_1 + 0x1ab8) = *(uint *)(param_1 + 0x1ab8) | 1;
  *(undefined4 *)(FUN_00001b34 + param_1) = 0;
  iVar2 = *(int *)(param_1 + 0x23d0);
  iVar6 = iVar2 * 0xb4;
  *(undefined4 *)(param_1 + 0x2360) = DAT_001db928;
  *(undefined4 *)(param_1 + 0x2364) = DAT_001db92c;
  *(undefined4 *)(((unsigned char *)0x0000236c) + param_1) = DAT_001db934;
  *(undefined4 *)(((unsigned char *)0x00002368) + param_1) = DAT_001db930;
  *(undefined4 *)(((unsigned char *)0x00002370) + param_1) = DAT_001db938;
  *(undefined4 *)(((unsigned char *)0x00002374) + param_1) = *(undefined4 *)(&DAT_001db5b8 + iVar6);
  *(undefined4 *)(((unsigned char *)0x0000237c) + param_1) = *(undefined4 *)(&DAT_001db5c0 + iVar6);
  *(undefined4 *)(((unsigned char *)0x00002378) + param_1) = *(undefined4 *)(&DAT_001db5bc + iVar6);
  *(undefined4 *)(((unsigned char *)0x00002380) + param_1) = *(undefined4 *)(&DAT_001db5c4 + iVar6);
  *(undefined4 *)(((unsigned char *)0x00002384) + param_1) = *(undefined4 *)(&DAT_001db2d4 + iVar6);
  *(undefined4 *)(((unsigned char *)0x00002388) + param_1) = *(undefined4 *)(&DAT_001db2d8 + iVar6);
  *(undefined4 *)(((unsigned char *)0x00002398) + param_1) = *(undefined4 *)(&DAT_001db2e0 + iVar6);
  *(undefined **)(((unsigned char *)0x0000238c) + param_1) = (PTR_LAB_001db2dc)[iVar2 * 0x2d];
  *(undefined4 *)(((unsigned char *)0x0000239c) + param_1) = *(undefined4 *)(&DAT_001db2e4 + iVar6);
  *(undefined4 *)(((unsigned char *)0x00002390) + param_1) = *(undefined4 *)(&DAT_001db2e8 + iVar6);
  *(undefined4 *)(((unsigned char *)0x000023a0) + param_1) = *(undefined4 *)(&DAT_001db2f0 + iVar6);
  *(undefined **)(((unsigned char *)0x00002394) + param_1) = (PTR_LAB_001db2ec)[iVar2 * 0x2d];
  uVar3 = *(undefined4 *)(&DAT_001db2f4 + iVar6);
  *(undefined4 *)(param_1 + 0x23c4) = 0;
  *(undefined4 *)(param_1 + 0x23c8) = 0;
  *(undefined4 *)(param_1 + 0x23cc) = 0;
  *(undefined4 *)(((unsigned char *)0x000023a4) + param_1) = uVar3;
  if (iVar2 == 4) {
    *(undefined4 *)(param_1 + 0x23c8) = 0x101fe;
    *(undefined4 *)(param_1 + 0x23cc) = 0x101fe;
    *(undefined4 *)(param_1 + 0x23c4) = 0x111;
  }
  *(undefined1 *)(param_1 + 0x29) = 1;
  *(undefined2 *)(param_1 + 0x34) = 0xffff;
  *(undefined1 *)(param_1 + 0x2e) = 3;
  *(undefined1 *)(param_1 + 0x2a) = 1;
  *(undefined2 *)(param_1 + 0x32) = 0xffff;
  *(undefined4 *)(param_1 + 0x23e0) = 0;
  *(undefined4 *)(param_1 + 0x1bac) = 0;
  *(undefined4 *)(param_1 + 0x1bb0) = 0;
  *(undefined4 *)(param_1 + 0x1bbc) = 0;
  *(undefined4 *)(param_1 + 0x1bc0) = 0;
  *(undefined4 *)(param_1 + 0x1bc4) = 0;
  *(undefined4 *)(param_1 + 0x2354) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0x800015ff;
  *(undefined1 *)(param_1 + 0x2d) = 0xf;
  *(undefined1 *)(param_1 + 0x2c) = 0xff;
  *(undefined4 *)(param_1 + 0x38) = 0x7ffff;
  *(undefined4 *)(param_1 + 0x40) = 0x7ffff;
  *(undefined1 *)(param_1 + 0x30) = 7;
  *(undefined4 *)(param_1 + 0x1bb8) = 0xaaaaa;
  return;
}

/* FUN_0004fc80 @ 0x4fc80 (252 bytes) */
int FUN_0004fc80(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
  uint param_5;
  uint param_6;
  uint param_7;
  uint param_8;
{
  int iVar1;
  
  if (*(char *)(param_1 + 0x1868) != '\0') {
    iVar1 = 0;
    param_5 = *(uint *)(param_5 * 4 + *(int *)(param_1 + 0x1864));
    if (param_5 == 0x16) goto LAB_0004fcb4;
  }
  iVar1 = 0xf;
LAB_0004fcb4:
  if ((param_2 & 1) == 0) {
    param_1 = (param_2 >> 1) * 4 + param_1;
    *(uint *)(param_1 + 0x1be4) =
         (param_8 & 1) << 0xf |
         (param_7 & 1) << 0xe |
         (param_6 & 1) << 0xd |
         (param_5 & 0x1f) << 8 |
         (param_4 & 0xf) << 4 | param_3 & 0xf | *(uint *)(param_1 + 0x1be4) & 0xffff0000;
    *(uint *)(param_1 + 0x1c04) = iVar1 << 0xc | *(uint *)(param_1 + 0x1c04) & 0xffff0000 | 0x688;
  }
  else {
    param_1 = (param_2 >> 1) * 4 + param_1;
    *(uint *)(param_1 + 0x1be4) =
         param_8 << 0x1f |
         (param_7 & 1) << 0x1e |
         (param_6 & 1) << 0x1d |
         (param_5 & 0x1f) << 0x18 |
         (param_4 & 0xf) << 0x14 | (param_3 & 0xf) << 0x10 | *(uint *)(param_1 + 0x1be4) & 0xffff;
    *(uint *)(param_1 + 0x1c04) = iVar1 << 0x1c | *(uint *)(param_1 + 0x1c04) & 0xffff | 0x6880000;
  }
  return;
}

/* FUN_0004fd80 @ 0x4fd80 (492 bytes) */
int FUN_0004fd80(param_1)
  int param_1;
{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  code *pcVar7;
  uint *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined *puVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  
  iVar12 = *(int *)(((unsigned char *)0x00001154) + param_1);
  iVar11 = iVar12 + 0x10;
  if (((unsigned char *)0x00001134)[param_1] == '\0') {
    iVar11 = *(int *)(((unsigned char *)0x00001144) + param_1);
  }
  uVar14 = 0;
  puVar13 = ((unsigned char *)0x00001300);
  iVar16 = 0;
  iVar15 = param_1;
  do {
    iVar9 = *(int *)(param_1 + 0x1e70);
    if ((((1 << (uVar14 & 0x3f) & *(uint *)(((unsigned char *)0x000010b8) + iVar9)) != 0) &&
        (*(char *)(*(int *)(iVar11 + 0x28) + iVar16) == '\0')) &&
       (*(char *)(iVar16 + *(int *)(iVar12 + 0xc)) != '\0')) {
      uVar2 = *(uint *)(iVar16 + *(int *)(iVar12 + 0xc) + 4);
      iVar6 = uVar14 * 0x10;
      iVar10 = iVar6 + iVar9;
      uVar3 = *(uint *)(*(int *)(iVar12 + 0xc) + iVar16 + 8);
      uVar4 = *(uint *)(iVar16 + *(int *)(iVar12 + 0xc) + 0xc);
      uVar5 = *(uint *)(iVar16 + *(int *)(iVar12 + 0xc) + 0x10);
      if (((uVar2 != *(uint *)(iVar10 + 0x8c)) || (uVar3 != *(uint *)(iVar10 + 0x90))) ||
         ((uVar4 != *(uint *)(iVar10 + 0x94) || (uVar5 != *(uint *)(iVar10 + 0x98))))) {
        *(uint *)(iVar6 + iVar9 + 0x8c) = uVar2;
        *(uint *)(iVar6 + *(int *)(param_1 + 0x1e70) + 0x90) = uVar3;
        *(uint *)(iVar6 + *(int *)(param_1 + 0x1e70) + 0x94) = uVar4;
        *(uint *)(iVar6 + *(int *)(param_1 + 0x1e70) + 0x98) = uVar5;
        *(uint *)(iVar15 + 0x1f38) = uVar2;
        *(uint *)(iVar15 + 0x1f3c) = uVar3;
        *(uint *)(iVar15 + 8000) = uVar4;
        *(uint *)(iVar15 + 0x1f44) = uVar5;
        puVar8 = (uint *)(**(code **)(param_1 + 0x2758))(param_1,5);
        *(uint **)(FUN_00002748 + param_1 + 4) = puVar8;
        puVar8[4] = uVar5;
        *puVar8 = (uint)puVar13 | 0x30000;
        puVar8[1] = uVar2;
        puVar8[2] = uVar3;
        puVar8[3] = uVar4;
        pcVar7 = *(code **)(param_1 + 0x275c);
        *(int *)(FUN_00002748 + param_1 + 4) = *(int *)(FUN_00002748 + param_1 + 4) + 0x14;
        (*pcVar7)(param_1);
        *(undefined4 *)(param_1 + 0x1e68) = 0;
      }
    }
    bVar1 = uVar14 != 7;
    iVar16 = iVar16 + 0x14;
    iVar15 = iVar15 + 0x10;
    puVar13 = puVar13 + 4;
    uVar14 = uVar14 + 1;
  } while (bVar1);
  return;
}

/* FUN_0004ff70 @ 0x4ff70 (416 bytes) */
int FUN_0004ff70(param_1)
  int param_1;
{
  float fVar1;
  int iVar2;
  undefined2 uVar3;
  undefined1 uVar4;
  int iVar5;
  uint uVar6;
  
  fVar1 = FLOAT_001aa168;
  iVar5 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (((unsigned char *)0x00002d66)[iVar5] == '\0') {
    *(uint *)(param_1 + 0x1a4c) = *(uint *)(param_1 + 0x1a4c) & 0xfffff7ff;
  }
  else {
    switch(*(undefined2 *)(((unsigned char *)0x00002d64) + iVar5)) {
    case 0x201:
      uVar6 = 1;
      iVar2 = 1;
      break;
    case 0x202:
      uVar6 = 2;
      iVar2 = 2;
      break;
    case 0x203:
      uVar6 = 3;
      iVar2 = 3;
      break;
    case 0x204:
      uVar6 = 4;
      iVar2 = 4;
      break;
    case 0x205:
      uVar6 = 5;
      iVar2 = 5;
      break;
    case 0x206:
      uVar6 = 6;
      iVar2 = 6;
      break;
    case 0x207:
      uVar6 = 7;
      iVar2 = 7;
      break;
    default:
      uVar6 = 0;
      iVar2 = 0;
    }
    uVar4 = 0xff;
    *(uint *)(param_1 + 0x1a4c) = iVar2 << 8 | *(uint *)(param_1 + 0x1a4c) & 0xfffff8ff;
    if ((uint)(int)(*(float *)(((unsigned char *)0x00002d60) + iVar5) * fVar1) < 0x100) {
      uVar4 = (undefined1)(int)(*(float *)(((unsigned char *)0x00002d60) + iVar5) * fVar1);
    }
    *(undefined1 *)(param_1 + 0x1a4f) = uVar4;
    if ((*(uint *)(PTR_DAT_001e88c8 + (uint)*(byte *)(param_1 + 0x293f) * 0x24 + 0x18) & 0x3c00) ==
        0x2800) {
      uVar3 = ((uint (*)())FUN_0001d7c0)((double)*(float *)(((unsigned char *)0x00002d60) + iVar5));
      *(undefined2 *)(param_1 + 0x1bde) = uVar3;
    }
    else {
      *(short *)(param_1 + 0x1bde) =
           (short)(int)(*(float *)(((unsigned char *)0x00002d60) + iVar5) * FLOAT_001aa154 + FLOAT_001aa10c);
    }
    *(uint *)(param_1 + 0x1a4c) =
         -(uVar6 ^ 7) >> 0x14 & 0x800 | *(uint *)(param_1 + 0x1a4c) & 0xfffff7ff | 0x1000;
  }
  *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x200;
  return;
}

/* FUN_00050140 @ 0x50140 (424 bytes) */
int FUN_00050140(param_1)
  int param_1;
{
  byte bVar1;
  undefined *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  puVar2 = PTR_DAT_001e88c8;
  bVar1 = *(byte *)(param_1 + 0x293f);
  iVar5 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if ((*(uint *)(param_1 + 0x18a4) & 0x3fffc0) == 0) {
    *(undefined4 *)(FUN_00001af4 + param_1) = 0;
  }
  else {
    uVar3 = (uint)(((unsigned char *)0x00002e40)[iVar5] == '\x01') *
            ((byte)PTR_DAT_001e88c8[(uint)bVar1 * 0x24 + 0x1c] & 0xf);
    *(uint *)(FUN_00001af4 + param_1) = uVar3;
    uVar3 = uVar3 | (uint)(((unsigned char *)0x00002e41)[iVar5] == '\x01') *
                    (*(uint *)(puVar2 + (uint)bVar1 * 0x24 + 0x1c) >> 0x14 & 0xf);
    *(uint *)(FUN_00001af4 + param_1) = uVar3;
    uVar3 = uVar3 | (uint)(((unsigned char *)0x00002e42)[iVar5] == '\x01') *
                    (*(ushort *)(puVar2 + (uint)bVar1 * 0x24 + 0x1c) & 0xf);
    *(uint *)(FUN_00001af4 + param_1) = uVar3;
    *(uint *)(FUN_00001af4 + param_1) =
         uVar3 | (uint)(((unsigned char *)0x00002e43)[iVar5] == '\x01') *
                 (*(uint *)(puVar2 + (uint)bVar1 * 0x24 + 0x1c) >> 0xc & 0xf);
  }
  uVar3 = *(uint *)(((unsigned char *)0x00001b2c) + param_1);
  *(uint *)(((unsigned char *)0x00001b2c) + param_1) = uVar3 & 0xfffcffff | 0x30000;
  if (*(int *)(((unsigned char *)0x00003194) + iVar5) == 0x1d01) {
    *(uint *)(param_1 + 0x1bb8) = *(uint *)(param_1 + 0x1bb8) & 0xfff0ffff | 0xa0000;
    *(uint *)(((unsigned char *)0x00001b2c) + param_1) = uVar3 & 0xfffc0000 | 0x3aaaa;
  }
  else {
    uVar4 = *(uint *)(param_1 + 0x44);
    *(uint *)(((unsigned char *)0x00001b2c) + param_1) = uVar3 & 0xfffcc0c0 | 0x31515;
    if ((uVar4 & 0x2000) == 0) {
      *(uint *)(((unsigned char *)0x00001b2c) + param_1) = uVar3 & 0xfffc0000 | 0x39595;
    }
    else {
      *(uint *)(((unsigned char *)0x00001b2c) + param_1) = uVar3 & 0xfffc0000 | 0x35555;
    }
    *(uint *)(param_1 + 0x1bb8) = *(uint *)(param_1 + 0x1bb8) & 0xfff0ffff | 0x50000;
  }
  *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x10;
  return;
}

/* FUN_00050300 @ 0x50300 (3048 bytes) */
int FUN_00050300(param_1)
  int param_1;
{
  undefined *puVar1;
  code *pcVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  uint uVar13;
  undefined4 uVar14;
  
  iVar8 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  puVar3 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,6);
  puVar3[1] = 0;
  *puVar3 = ((unsigned char *)0x000010a4);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar3 + 2;
  (**(code **)(param_1 + 0x275c))(param_1,puVar3 + 2);
  puVar3 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,4);
  *puVar3 = ((unsigned char *)0x00001393);
  puVar3[1] = 10;
  puVar3[2] = ((unsigned char *)0x000013c6);
  puVar3[3] = 3;
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar3 + 4;
  (**(code **)(param_1 + 0x275c))(param_1,puVar3 + 4);
  puVar3 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0x1b4);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar3;
  *puVar3 = ((unsigned char *)0x00001394);
  puVar4 = puVar3 + 0x5a;
  uVar7 = *(undefined4 *)(param_1 + 0x1af0);
  puVar3[2] = 0x850;
  puVar3[1] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1b80);
  puVar3[4] = 0x110ad;
  puVar3[3] = uVar7;
  puVar3[5] = *(undefined4 *)(((unsigned char *)0x00001b14) + param_1);
  uVar7 = *(undefined4 *)(((unsigned char *)0x00001b30) + param_1);
  puVar3[7] = 0x110a2;
  puVar3[6] = uVar7;
  puVar3[8] = *(undefined4 *)(param_1 + 0x1b3c);
  uVar7 = *(undefined4 *)(param_1 + 0x1b48);
  puVar3[10] = ((unsigned char *)0x0000108d);
  puVar3[9] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1b40);
  puVar3[0xc] = ((unsigned char *)0x00001002);
  puVar3[0xb] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1b50);
  puVar3[0xe] = ((unsigned char *)0x00001085);
  puVar3[0xd] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1b54);
  puVar3[0x10] = ((unsigned char *)0x0000108e);
  puVar3[0xf] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1b64);
  puVar3[0x12] = ((unsigned char *)0x00001098);
  puVar3[0x11] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1b68);
  puVar3[0x14] = 0x11099;
  puVar3[0x13] = uVar7;
  puVar3[0x15] = *(undefined4 *)(param_1 + 0x1b6c);
  uVar7 = *(undefined4 *)(param_1 + 0x1b70);
  puVar3[0x19] = 0x11007;
  puVar3[0x18] = 0;
  puVar3[0x17] = 0x823;
  puVar3[0x16] = uVar7;
  puVar3[0x1a] = *(undefined4 *)(param_1 + 0x1a64);
  uVar7 = *(undefined4 *)(param_1 + 0x1a60);
  puVar3[0x1c] = 0x11004;
  puVar3[0x1b] = uVar7;
  puVar3[0x1d] = *(undefined4 *)(param_1 + 0x1a68);
  uVar7 = *(undefined4 *)(param_1 + 0x1a6c);
  puVar3[0x1f] = ((unsigned char *)0x000010fa);
  puVar3[0x1e] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1b60);
  puVar3[0x21] = ((unsigned char *)0x000013a2);
  puVar3[0x20] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x23c0);
  puVar3[0x23] = ((unsigned char *)0x0000109d);
  puVar3[0x22] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1b4c);
  puVar3[0x25] = ((unsigned char *)0x000010a8);
  puVar3[0x24] = uVar7;
  uVar7 = *(undefined4 *)(((unsigned char *)0x00001b28) + param_1);
  puVar3[0x27] = 0x311a9;
  puVar3[0x26] = uVar7;
  puVar3[0x28] = *(undefined4 *)(param_1 + 0x233c);
  puVar3[0x29] = *(undefined4 *)(param_1 + 0x2340);
  puVar3[0x2a] = *(undefined4 *)(param_1 + 0x2344);
  puVar3[0x2b] = *(undefined4 *)(FUN_00002348 + param_1);
  puVar3[0x2c] = ((unsigned char *)0x00001385);
  uVar7 = *(undefined4 *)(param_1 + 0x1a94);
  puVar3[0x2e] = 0x110a5;
  puVar3[0x2d] = uVar7;
  puVar3[0x2f] = *(undefined4 *)(param_1 + 0x1a7c);
  uVar7 = *(undefined4 *)(param_1 + 0x1a78);
  puVar3[0x31] = ((unsigned char *)0x0000109e);
  puVar3[0x30] = uVar7;
  uVar7 = *(undefined4 *)(((unsigned char *)0x00001b2c) + param_1);
  puVar3[0x33] = 0x861;
  puVar3[0x32] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1ca0);
  puVar3[0x35] = 0x10824;
  puVar3[0x34] = uVar7;
  puVar3[0x36] = *(undefined4 *)(param_1 + 0x1b9c);
  uVar7 = *(undefined4 *)(param_1 + 0x1ba0);
  puVar3[0x38] = 0x1082c;
  puVar3[0x37] = uVar7;
  puVar3[0x39] = *(undefined4 *)(param_1 + 0x1b84);
  uVar7 = *(undefined4 *)(param_1 + 0x248c);
  puVar3[0x3b] = 0x860;
  puVar3[0x3a] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1b78);
  puVar3[0x3d] = 0x887;
  puVar3[0x3c] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1b74);
  puVar3[0x3f] = 0x8a2;
  puVar3[0x3e] = uVar7;
  puVar3[0x40] = *(undefined4 *)(param_1 + 0x1b88);
  puVar3[0x41] = 0x877;
  uVar7 = *(undefined4 *)(param_1 + 0x1cb8);
  puVar3[0x43] = 0x1084d;
  puVar3[0x46] = 0x5c8;
  puVar3[0x44] = 0xffffff;
  puVar3[0x47] = 0x8000;
  puVar3[0x48] = 0xc0001000;
  puVar3[0x4a] = (*(unsigned char *)0x000010ea);
  puVar3[0x49] = 0;
  puVar3[0x42] = uVar7;
  puVar3[0x45] = 0;
  uVar7 = *(undefined4 *)(param_1 + 0x1abc);
  puVar3[0x4c] = ((unsigned char *)0x00001096);
  puVar3[0x4b] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1bb8);
  puVar3[0x4e] = ((unsigned char *)0x00001046);
  puVar3[0x4d] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1bbc);
  puVar3[0x50] = ((unsigned char *)0x00001048);
  puVar3[0x4f] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1bc0);
  puVar3[0x52] = ((unsigned char *)0x00001047);
  puVar3[0x51] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1bb0);
  puVar3[0x54] = ((unsigned char *)0x00001045);
  puVar3[0x53] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1bc4);
  puVar3[0x56] = 0x886;
  puVar3[0x55] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1bc8);
  puVar3[0x59] = 2;
  puVar3[0x58] = ((unsigned char *)0x00001180);
  puVar3[0x57] = uVar7;
  if ((*(uint *)(param_1 + 0x2454) & 0x8000000) != 0) {
    puVar4 = puVar3 + 0x62;
    puVar3[0x5a] = ((unsigned char *)0x000012fb);
    uVar7 = *(undefined4 *)(param_1 + 0x1bcc);
    puVar3[0x5c] = ((unsigned char *)0x000012fa);
    puVar3[0x5b] = uVar7;
    uVar7 = *(undefined4 *)(param_1 + 0x1bd0);
    puVar3[0x5e] = ((unsigned char *)0x000010e6);
    puVar3[0x5d] = uVar7;
    uVar7 = *(undefined4 *)(param_1 + 0x1bd4);
    puVar3[0x60] = ((unsigned char *)0x000011f2);
    puVar3[0x5f] = uVar7;
    puVar3[0x61] = *(undefined4 *)(param_1 + 0x1bd8);
  }
  pcVar2 = *(code **)(param_1 + 0x275c);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar4;
  (*pcVar2)(param_1,puVar4);
  ((int (*)())FUN_0004e880)(param_1);
  uVar13 = *(uint *)(param_1 + 0x27b0) |
           (*(uint *)(param_1 + 0x27b0) & *(uint *)(param_1 + 0x27b4)) << 8;
  if (uVar13 != 0) {
    puVar9 = (undefined4 *)(param_1 + 0x1cdc);
    puVar10 = (undefined4 *)(param_1 + 0x1d1c);
    puVar11 = (undefined4 *)(param_1 + 0x1d5c);
    puVar12 = (undefined4 *)(((unsigned char *)0x00001d9c) + param_1);
    puVar3 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0xe0);
    iVar6 = *(int *)(param_1 + 0x1938);
    puVar4 = (undefined4 *)(((unsigned char *)0x00001ddc) + param_1);
    puVar5 = (undefined4 *)(((unsigned char *)0x00001e1c) + param_1);
    *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar3;
    do {
      if ((uVar13 & 1) != 0) {
        *puVar3 = ((unsigned char *)0x00001100) + iVar6;
        uVar7 = *puVar9;
        puVar3[2] = ((unsigned char *)0x00001110) + iVar6;
        puVar3[1] = uVar7;
        uVar7 = *puVar10;
        puVar3[4] = (*(unsigned char *)0x00001120) + iVar6;
        puVar3[3] = uVar7;
        uVar7 = *puVar11;
        puVar3[6] = ((unsigned char *)0x00001130) + iVar6;
        puVar3[5] = uVar7;
        uVar7 = *puVar12;
        puVar3[8] = (*(unsigned char *)0x00001170) + iVar6;
        puVar3[7] = uVar7;
        uVar7 = *puVar5;
        puVar3[10] = ((unsigned char *)0x00001160) + iVar6;
        puVar3[0xc] = ((unsigned char *)0x00001140) + iVar6;
        puVar3[0xb] = 0;
        puVar3[9] = uVar7;
        puVar3[0xd] = *puVar4;
        puVar3 = puVar3 + 0xe;
      }
      uVar13 = uVar13 >> 1;
      iVar6 = iVar6 + 1;
      puVar9 = puVar9 + 1;
      puVar10 = puVar10 + 1;
      puVar11 = puVar11 + 1;
      puVar12 = puVar12 + 1;
      puVar5 = puVar5 + 1;
      puVar4 = puVar4 + 1;
    } while (uVar13 != 0);
    pcVar2 = *(code **)(param_1 + 0x275c);
    *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar3;
    (*pcVar2)(param_1,puVar3);
  }
  if ((*(uint *)(param_1 + 0x44) & 0x100) != 0) {
    if ((*(uint *)(param_1 + 0x27b0) & 1) == 0) {
      puVar3 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,4);
      puVar4 = puVar3 + 4;
      *puVar3 = ((unsigned char *)0x00001041);
      puVar3[1] = (*(uint *)(param_1 + 0x27b0) | 1) << (*(uint *)(param_1 + 0x1938) & 0x3f);
      iVar6 = *(int *)(param_1 + 0x1938);
      puVar3[3] = 0;
      puVar3[2] = ((unsigned char *)0x00001100) + iVar6;
      goto LAB_00050920;
    }
  }
  puVar3 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
  puVar4 = puVar3 + 2;
  *puVar3 = ((unsigned char *)0x00001041);
  puVar3[1] = *(int *)(param_1 + 0x27b0) << (*(uint *)(param_1 + 0x1938) & 0x3f);
LAB_00050920:
  pcVar2 = *(code **)(param_1 + 0x275c);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar4;
  (*pcVar2)(param_1,puVar4);
  uVar7 = (**(code **)(param_1 + 0x2758))(param_1,0x90);
  *(undefined4 *)(FUN_00002748 + param_1 + 4) = uVar7;
  puVar3 = (undefined4 *)((int (*)())FUN_0004dd40)(param_1);
  puVar4 = puVar3 + 9;
  *puVar3 = ((unsigned char *)0x0000108c);
  uVar7 = *(undefined4 *)(param_1 + 0x1cd0);
  puVar3[2] = ((unsigned char *)0x00001087);
  puVar3[1] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1ccc);
  puVar3[4] = 0x31080;
  puVar3[3] = uVar7;
  puVar3[5] = *(undefined4 *)(param_1 + 0x1cbc);
  puVar3[6] = *(undefined4 *)(param_1 + 0x1cc4);
  puVar3[7] = *(undefined4 *)(param_1 + 0x1cc0);
  puVar3[8] = *(undefined4 *)(param_1 + 0x1cc8);
  if ((*(int *)(((unsigned char *)0x000031c0) + iVar8) != 0) && (((unsigned char *)0x00001491)[param_1] != '\0')) {
    puVar4 = puVar3 + 0xb;
    puVar3[9] = ((unsigned char *)0x000013c2);
    puVar3[10] = *(undefined4 *)(param_1 + 0x1aa8);
  }
  puVar3 = puVar4 + 4;
  *puVar4 = ((unsigned char *)0x00001386);
  uVar7 = *(undefined4 *)(param_1 + 0x1af8);
  puVar4[2] = ((unsigned char *)0x00001383);
  puVar4[1] = uVar7;
  puVar4[3] = *(undefined4 *)(FUN_00001af4 + param_1);
  if ((*(uint *)(((unsigned char *)0x00001b14) + param_1) & 3) != 0) {
    puVar3 = puVar4 + 9;
    puVar4[4] = 0x310a9;
    puVar4[5] = *(undefined4 *)(((unsigned char *)0x00001b1c) + param_1);
    puVar4[6] = *(undefined4 *)(((unsigned char *)0x00001b18) + param_1);
    puVar4[7] = *(undefined4 *)(((unsigned char *)0x00001b24) + param_1);
    puVar4[8] = *(undefined4 *)(((unsigned char *)0x00001b20) + param_1);
  }
  puVar3 = (undefined4 *)((int (*)())FUN_0004dd10)(param_1,puVar3);
  puVar1 = PTR_DAT_001e88c8;
  *puVar3 = 0x112f5;
  uVar13 = *(uint *)(param_1 + 0x1a4c);
  puVar3[1] = uVar13;
  if ((*(uint *)(puVar1 + (uint)*(byte *)(param_1 + 0x293f) * 0x24 + 0x18) & 0x8000) == 0) {
    puVar3[1] = uVar13 & 0xfffff7ff;
  }
  uVar7 = *(undefined4 *)(param_1 + 0x1a50);
  puVar3[3] = ((unsigned char *)0x000012f8);
  puVar3[2] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1bdc);
  puVar3[5] = ((unsigned char *)0x000212f2);
  puVar3[4] = uVar7;
  puVar3[6] = *(undefined4 *)(param_1 + 0x1a54);
  puVar3[7] = *(undefined4 *)(param_1 + 0x1a58);
  uVar7 = *(undefined4 *)(param_1 + 0x1a5c);
  puVar3[9] = ((unsigned char *)0x00001007);
  puVar3[8] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1a64);
  puVar3[0xb] = ((unsigned char *)0x000012f0);
  puVar3[10] = uVar7;
  uVar13 = *(uint *)(param_1 + 0x1aec);
  puVar3[0xc] = uVar13;
  if ((*(uint *)(puVar1 + (uint)*(byte *)(param_1 + 0x293f) * 0x24 + 0x18) & 0x8000) == 0) {
    puVar3[0xc] = uVar13 & 0xfffffffe;
  }
  puVar3[0xd] = 0x1109f;
  puVar3[0xe] = *(undefined4 *)(param_1 + 0x1a70);
  uVar7 = *(undefined4 *)(param_1 + 0x1a74);
  puVar3[0x10] = 0x11381;
  puVar3[0xf] = uVar7;
  uVar13 = *(uint *)(param_1 + 0x1a80);
  puVar3[0x11] = uVar13;
  if ((*(uint *)(puVar1 + (uint)*(byte *)(param_1 + 0x293f) * 0x24 + 0x18) & 0x4000) == 0) {
    puVar3[0x11] = uVar13 & 0xfffffffc;
  }
  uVar7 = *(undefined4 *)(param_1 + 0x1a84);
  puVar3[0x13] = ((unsigned char *)0x00001384);
  puVar3[0x12] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1a88);
  puVar3[0x15] = ((unsigned char *)0x000013be);
  puVar3[0x14] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1a8c);
  puVar3[0x17] = ((unsigned char *)0x000013bf);
  puVar3[0x16] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1a90);
  puVar3[0x19] = ((unsigned char *)0x000013c5);
  puVar3[0x18] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1ab8);
  puVar3[0x1b] = 0x113c0;
  puVar3[0x1a] = uVar7;
  puVar3[0x1c] = *(undefined4 *)(param_1 + 0x1aa0);
  uVar7 = *(undefined4 *)(param_1 + 0x1aa4);
  puVar3[0x1e] = 0x110b0;
  puVar3[0x1d] = uVar7;
  puVar3[0x1f] = *(undefined4 *)(param_1 + 0x1b38);
  uVar7 = *(undefined4 *)(FUN_00001b34 + param_1);
  puVar3[0x21] = ((unsigned char *)0x0000100a);
  puVar3[0x20] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x2354);
  puVar3[0x23] = 0x113a8;
  puVar3[0x22] = uVar7;
  puVar3[0x24] = *(undefined4 *)(param_1 + 0x235c);
  uVar7 = *(undefined4 *)(param_1 + 0x2358);
  puVar3[0x26] = ((unsigned char *)0x000413de);
  puVar3[0x25] = uVar7;
  puVar3[0x27] = *(undefined4 *)(param_1 + 0x2360);
  puVar3[0x28] = *(undefined4 *)(param_1 + 0x2364);
  puVar3[0x29] = *(undefined4 *)(((unsigned char *)0x00002368) + param_1);
  puVar3[0x2a] = *(undefined4 *)(((unsigned char *)0x0000236c) + param_1);
  uVar7 = *(undefined4 *)(((unsigned char *)0x00002370) + param_1);
  puVar3[0x2c] = 0x313e9;
  puVar3[0x2b] = uVar7;
  puVar3[0x2d] = *(undefined4 *)(((unsigned char *)0x00002374) + param_1);
  puVar3[0x2e] = *(undefined4 *)(((unsigned char *)0x00002378) + param_1);
  puVar3[0x2f] = *(undefined4 *)(((unsigned char *)0x0000237c) + param_1);
  uVar7 = *(undefined4 *)(((unsigned char *)0x00002380) + param_1);
  puVar3[0x31] = ((unsigned char *)0x000813ad);
  puVar3[0x30] = uVar7;
  puVar3[0x32] = *(undefined4 *)(((unsigned char *)0x00002384) + param_1);
  puVar3[0x33] = *(undefined4 *)(((unsigned char *)0x00002388) + param_1);
  puVar3[0x34] = *(undefined4 *)(((unsigned char *)0x0000238c) + param_1);
  puVar3[0x35] = *(undefined4 *)(((unsigned char *)0x00002390) + param_1);
  puVar3[0x36] = *(undefined4 *)(((unsigned char *)0x00002394) + param_1);
  puVar3[0x37] = *(undefined4 *)(((unsigned char *)0x00002398) + param_1);
  puVar3[0x38] = *(undefined4 *)(((unsigned char *)0x0000239c) + param_1);
  puVar3[0x39] = *(undefined4 *)(((unsigned char *)0x000023a0) + param_1);
  uVar7 = *(undefined4 *)(((unsigned char *)0x000023a4) + param_1);
  puVar3[0x3b] = ((unsigned char *)0x000013e6);
  puVar3[0x3a] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x23c4);
  puVar3[0x3d] = ((unsigned char *)0x000013e7);
  puVar3[0x3c] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x23c8);
  puVar3[0x3f] = ((unsigned char *)0x000013e8);
  puVar3[0x3e] = uVar7;
  puVar3[0x40] = *(undefined4 *)(param_1 + 0x23cc);
  if ((*(uint *)(param_1 + 0x44) & 0x20000) == 0) {
    *(undefined4 *)(param_1 + 0x1e68) = 0;
  }
  pcVar2 = *(code **)(param_1 + 0x275c);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar3 + 0x41;
  (*pcVar2)(param_1);
  if (*(int *)(param_1 + 0x2494) != 0) {
    puVar3 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0x12);
    *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar3;
    *puVar3 = 0x830;
    uVar7 = *(undefined4 *)(param_1 + 0x2490);
    puVar3[2] = 0x831;
    puVar3[1] = uVar7;
    uVar7 = **(undefined4 **)(param_1 + 0x2494);
    puVar3[4] = 0x834;
    puVar3[3] = uVar7;
    uVar7 = *(undefined4 *)(*(int *)(param_1 + 0x2494) + 4);
    puVar3[6] = 0x837;
    puVar3[5] = uVar7;
    uVar7 = *(undefined4 *)(*(int *)(param_1 + 0x2494) + 8);
    puVar3[8] = 0x83a;
    puVar3[7] = uVar7;
    uVar7 = *(undefined4 *)(*(int *)(param_1 + 0x2494) + 0xc);
    puVar3[10] = 0x83d;
    puVar3[9] = uVar7;
    uVar7 = *(undefined4 *)(*(int *)(param_1 + 0x2494) + 0x10);
    puVar3[0xc] = 0x840;
    puVar3[0xb] = uVar7;
    uVar7 = *(undefined4 *)(*(int *)(param_1 + 0x2494) + 0x14);
    puVar3[0xe] = 0x843;
    puVar3[0xd] = uVar7;
    uVar7 = *(undefined4 *)(*(int *)(param_1 + 0x2494) + 0x18);
    puVar3[0x10] = 0x846;
    puVar3[0xf] = uVar7;
    puVar3[0x11] = *(undefined4 *)(*(int *)(param_1 + 0x2494) + 0x1c);
    pcVar2 = *(code **)(param_1 + 0x275c);
    *(int *)(FUN_00002748 + param_1 + 4) = *(int *)(FUN_00002748 + param_1 + 4) + 0x48;
    (*pcVar2)(param_1);
  }
  iVar8 = FUN_0004aa00(param_1,1);
  if (iVar8 == 0) {
    (**(code **)(((unsigned char *)0x00001330) + param_1))(param_1,0xc0100000);
    (**(code **)(((unsigned char *)0x00001338) + param_1))(param_1);
    FUN_00086710(param_1);
  }
  uVar13 = *(uint *)(param_1 + 0x8c);
  *(undefined1 *)(param_1 + 0x23ec) = 1;
  *(uint *)(param_1 + 0x8c) = uVar13 | 0x58000;
  if ((((uVar13 & 0x50000000) == 0) && (*(code **)(((unsigned char *)0x000012b0) + param_1) != (code *)0x0)) &&
     ((uVar13 & 0x200000) != 0)) {
    uVar14 = *(undefined4 *)(param_1 + 0x38);
    uVar7 = *(undefined4 *)(param_1 + 0x3c);
    (**(code **)(((unsigned char *)0x000012b0) + param_1))(param_1);
    *(undefined4 *)(param_1 + 0x38) = uVar14;
    *(undefined4 *)(param_1 + 0x3c) = uVar7;
  }
  else {
    *(undefined1 *)(param_1 + 0x23ec) = 1;
    FUN_0009d2e0(param_1);
  }
  *(undefined1 *)(param_1 + 0x23ec) = 1;
  return;
}

/* FUN_00050ef0 @ 0x50ef0 (284 bytes) */
int FUN_00050ef0(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  code *pcVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = 0x80 / param_2;
  if (0x80 / param_3 < 0x80 / param_2) {
    uVar4 = 0x80 / param_3;
  }
  if (10 < uVar4) {
    uVar4 = 10;
  }
  uVar5 = 6;
  if ((param_4 != 0) && (uVar5 = 0x80 / param_4, 6 < uVar5)) {
    uVar5 = 6;
  }
  uVar2 = *(uint *)(param_1 + 0x1b7c);
  if ((uVar4 != (uVar2 & 0xf)) || (uVar5 != (uVar2 >> 4 & 0xf))) {
    *(undefined1 *)(param_1 + 0x23ec) = 1;
    *(uint *)(param_1 + 0x1b7c) = (uVar5 & 0xf) << 4 | uVar4 & 0xf | uVar2 & 0xffffff00;
  }
  if (*(char *)(param_1 + 0x23ec) != '\0') {
    puVar3 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,4);
    *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar3;
    puVar3[1] = 0;
    *puVar3 = 0x8a1;
    puVar3[2] = 0x820;
    puVar3[3] = *(undefined4 *)(param_1 + 0x1b7c);
    pcVar1 = *(code **)(param_1 + 0x275c);
    *(int *)(FUN_00002748 + param_1 + 4) = *(int *)(FUN_00002748 + param_1 + 4) + 0x10;
    (*pcVar1)(param_1);
    *(undefined1 *)(param_1 + 0x23ec) = 0;
  }
  return;
}

/* FUN_00051010 @ 0x51010 (1024 bytes) */
int FUN_00051010(param_1)
  int param_1;
{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  
  iVar7 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if ((*(int *)(((unsigned char *)0x000031c0) + iVar7) == 0) || (((unsigned char *)0x00001491)[param_1] == '\0')) {
    *(undefined1 *)(param_1 + 0x23ed) = 0;
    *(uint *)(param_1 + 0x1aa0) = *(uint *)(param_1 + 0x1aa0) & 0xfffffffe;
    goto LAB_00051404;
  }
  iVar2 = 3;
  *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) | 0x20000000;
  uVar1 = *(ushort *)(((unsigned char *)0x000031a2) + iVar7);
  uVar10 = *(uint *)(&DAT_001db348 + (*(ushort *)(((unsigned char *)0x000031a0) + iVar7) & 7) * 4);
  if (uVar1 != 0x1e02) {
    if (uVar1 < 0x1e03) {
      iVar2 = 5;
      if (((uVar1 != 0x150a) && (iVar2 = 2, uVar1 != 0x1e01)) && (iVar2 = 1, uVar1 != 0)) {
LAB_000510a0:
        iVar2 = 0;
      }
    }
    else {
      iVar2 = 6;
      if ((uVar1 != 0x8507) && (iVar2 = 7, uVar1 != 0x8508)) {
        if (uVar1 != 0x1e03) goto LAB_000510a0;
        iVar2 = 4;
      }
    }
  }
  uVar1 = *(ushort *)(((unsigned char *)0x000031a6) + iVar7);
  iVar3 = 3;
  if (uVar1 != 0x1e02) {
    if (uVar1 < 0x1e03) {
      iVar3 = 5;
      if (((uVar1 != 0x150a) && (iVar3 = 2, uVar1 != 0x1e01)) && (iVar3 = 1, uVar1 != 0)) {
LAB_0005111c:
        iVar3 = 0;
      }
    }
    else {
      iVar3 = 6;
      if ((uVar1 != 0x8507) && (iVar3 = 7, uVar1 != 0x8508)) {
        if (uVar1 != 0x1e03) goto LAB_0005111c;
        iVar3 = 4;
      }
    }
  }
  uVar1 = *(ushort *)(((unsigned char *)0x000031a4) + iVar7);
  iVar4 = 3;
  if (uVar1 != 0x1e02) {
    if (uVar1 < 0x1e03) {
      iVar4 = 5;
      if (((uVar1 != 0x150a) && (iVar4 = 2, uVar1 != 0x1e01)) && (iVar4 = 1, uVar1 != 0)) {
LAB_0005119c:
        iVar4 = 0;
      }
    }
    else {
      iVar4 = 6;
      if ((uVar1 != 0x8507) && (iVar4 = 7, uVar1 != 0x8508)) {
        if (uVar1 != 0x1e03) goto LAB_0005119c;
        iVar4 = 4;
      }
    }
  }
  iVar5 = 3;
  *(char *)(param_1 + 0x1aab) = (char)*(undefined4 *)(((unsigned char *)0x0000319c) + iVar7);
  *(char *)(param_1 + 0x1aaa) = (char)*(undefined4 *)(((unsigned char *)0x00003198) + iVar7);
  *(char *)(param_1 + 0x1aa9) = (char)*(undefined4 *)(((unsigned char *)0x00002e38) + iVar7);
  uVar1 = *(ushort *)(((unsigned char *)0x000031ba) + iVar7);
  uVar9 = *(uint *)(&DAT_001db348 + (*(ushort *)(((unsigned char *)0x000031b8) + iVar7) & 7) * 4);
  if (uVar1 != 0x1e02) {
    if (uVar1 < 0x1e03) {
      iVar5 = 5;
      if (((uVar1 != 0x150a) && (iVar5 = 2, uVar1 != 0x1e01)) && (iVar5 = 1, uVar1 != 0)) {
LAB_00051244:
        iVar5 = 0;
      }
    }
    else {
      iVar5 = 6;
      if ((uVar1 != 0x8507) && (iVar5 = 7, uVar1 != 0x8508)) {
        if (uVar1 != 0x1e03) goto LAB_00051244;
        iVar5 = 4;
      }
    }
  }
  uVar1 = *(ushort *)(((unsigned char *)0x000031be) + iVar7);
  iVar6 = 3;
  if (uVar1 != 0x1e02) {
    if (uVar1 < 0x1e03) {
      iVar6 = 5;
      if (((uVar1 != 0x150a) && (iVar6 = 2, uVar1 != 0x1e01)) && (iVar6 = 1, uVar1 != 0)) {
LAB_000512bc:
        iVar6 = 0;
      }
    }
    else {
      iVar6 = 6;
      if ((uVar1 != 0x8507) && (iVar6 = 7, uVar1 != 0x8508)) {
        if (uVar1 != 0x1e03) goto LAB_000512bc;
        iVar6 = 4;
      }
    }
  }
  uVar1 = *(ushort *)(((unsigned char *)0x000031bc) + iVar7);
  iVar8 = 3;
  if (uVar1 != 0x1e02) {
    if (uVar1 < 0x1e03) {
      iVar8 = 5;
      if (((uVar1 != 0x150a) && (iVar8 = 2, uVar1 != 0x1e01)) && (iVar8 = 1, uVar1 != 0)) {
LAB_0005133c:
        iVar8 = 0;
      }
    }
    else {
      iVar8 = 6;
      if ((uVar1 != 0x8507) && (iVar8 = 7, uVar1 != 0x8508)) {
        if (uVar1 != 0x1e03) goto LAB_0005133c;
        iVar8 = 4;
      }
    }
  }
  *(undefined1 *)(param_1 + 0x23ed) = 1;
  *(uint *)(param_1 + 0x1aa0) = *(uint *)(param_1 + 0x1aa0) | 1;
  *(uint *)(param_1 + 0x1aa4) =
       iVar8 << 0x18 |
       iVar6 << 0x15 |
       iVar4 << 0xc |
       iVar3 << 9 |
       iVar5 << 0x12 |
       (uVar9 & 7) << 0xf |
       iVar2 << 6 | (uVar10 & 7) << 3 | *(uint *)(param_1 + 0x1aa4) & 0xf8000007;
  if ((*(int *)(((unsigned char *)0x00002e38) + iVar7) == 0) ||
     (iVar8 == 0 && (iVar6 == 0 && (iVar4 == 0 && (iVar3 == 0 && (iVar5 == 0 && iVar2 == 0)))))) {
    *(undefined1 *)(param_1 + 0x23ed) = 0;
  }
LAB_00051404:
  *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x808;
  return;
}

/* FUN_00051420 @ 0x51420 (3152 bytes) */
int FUN_00051420(param_1)
  int param_1;
{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  bool bVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  undefined2 uVar13;
  int iVar14;
  bool bVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  int iVar21;
  double dVar22;
  double dVar23;
  
  uVar17 = *(uint *)(param_1 + 0x1a80);
  uVar20 = *(uint *)(FUN_00001af4 + param_1 + 4);
  iVar21 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  *(uint *)(param_1 + 0x1a80) = uVar17 & 0x3ffffffe;
  if (((((unsigned char *)0x00002d84)[iVar21] == '\0') || (((unsigned char *)0x00002e33)[iVar21] != '\0')) ||
     ((*(int *)(((unsigned char *)0x00002d80) + iVar21) == -0x7ff97ffa &&
      ((((*(short *)(((unsigned char *)0x00002d68) + iVar21) == 1 && (*(short *)(((unsigned char *)0x00002d6c) + iVar21) == 1)) &&
        (*(short *)(((unsigned char *)0x00002d6a) + iVar21) == 0)) && (*(short *)(((unsigned char *)0x00002d6e) + iVar21) == 0))))))
  goto LAB_00051ee0;
  uVar1 = *(ushort *)(((unsigned char *)0x00002d80) + iVar21);
  if (uVar1 == 0x8008) {
    bVar4 = true;
    iVar19 = 5;
  }
  else if (uVar1 < 0x8009) {
    if (uVar1 == 0x8007) {
      bVar4 = true;
      iVar19 = 4;
    }
    else {
LAB_000514ec:
      bVar4 = false;
      iVar19 = 0;
    }
  }
  else if (uVar1 == 0x800a) {
    bVar4 = false;
    iVar19 = 2;
  }
  else {
    if (uVar1 != 0x800b) goto LAB_000514ec;
    bVar4 = false;
    iVar19 = 6;
  }
  uVar2 = *(ushort *)(((unsigned char *)0x00002d82) + iVar21);
  if (uVar2 == 0x8008) {
    bVar15 = true;
    iVar12 = 5;
  }
  else if (uVar2 < 0x8009) {
    if (uVar2 == 0x8007) {
      bVar15 = true;
      iVar12 = 4;
    }
    else {
LAB_0005157c:
      bVar15 = false;
      iVar12 = 0;
    }
  }
  else if (uVar2 == 0x800a) {
    bVar15 = false;
    iVar12 = 2;
  }
  else {
    if (uVar2 != 0x800b) goto LAB_0005157c;
    bVar15 = false;
    iVar12 = 6;
  }
  uVar2 = *(ushort *)(((unsigned char *)0x00002d68) + iVar21);
  if (uVar2 == 0x305) {
    iVar7 = 0x29;
    bVar4 = true;
    iVar14 = 0x29;
  }
  else if (uVar2 < 0x306) {
    if (uVar2 == 0x301) {
      iVar7 = 0x23;
      iVar14 = 0x23;
    }
    else if (uVar2 < 0x302) {
      if (uVar2 == 0) {
        iVar7 = 0x20;
        iVar14 = 0x20;
      }
      else {
        if (uVar2 != 0x300) goto LAB_00051614;
        iVar7 = 0x22;
        iVar14 = 0x22;
      }
    }
    else if (uVar2 == 0x303) {
      iVar7 = 0x27;
      iVar14 = 0x27;
    }
    else if (uVar2 < 0x304) {
      iVar7 = 0x26;
      iVar14 = 0x26;
    }
    else {
      iVar7 = 0x28;
      bVar4 = true;
      iVar14 = 0x28;
    }
  }
  else if (uVar2 == 0x8001) {
    iVar7 = 0x2b;
    iVar14 = 0x2b;
  }
  else if (uVar2 < 0x8002) {
    if (uVar2 == 0x307) {
      iVar7 = 0x25;
      bVar4 = true;
      iVar14 = 0x25;
    }
    else if (uVar2 < 0x307) {
      iVar7 = 0x24;
      bVar4 = true;
      iVar14 = 0x24;
    }
    else if (uVar2 == 0x308) {
      iVar7 = 0x2a;
      bVar4 = true;
      iVar14 = 0x2a;
    }
    else {
LAB_00051614:
      iVar7 = 0x21;
      iVar14 = 0x21;
    }
  }
  else if (uVar2 == 0x8003) {
    iVar14 = 0x2d;
    iVar7 = 0x2d;
  }
  else if (uVar2 < 0x8003) {
    iVar7 = 0x2c;
    iVar14 = 0x2c;
  }
  else {
    if (uVar2 != 0x8004) goto LAB_00051614;
    iVar7 = 0x2e;
    iVar14 = 0x2e;
  }
  uVar3 = *(ushort *)(((unsigned char *)0x00002d6c) + iVar21);
  if (uVar2 != uVar3) {
    if (uVar3 == 0x305) {
      bVar15 = true;
      iVar7 = 0x29;
    }
    else if (uVar3 < 0x306) {
      iVar7 = 0x23;
      if (uVar3 != 0x301) {
        if (uVar3 < 0x302) {
          iVar7 = 0x20;
          if ((uVar3 != 0) && (iVar7 = 0x22, uVar3 != 0x300)) goto LAB_0005179c;
        }
        else {
          iVar7 = 0x27;
          if ((uVar3 != 0x303) && (iVar7 = 0x26, 0x303 < uVar3)) {
            bVar15 = true;
            iVar7 = 0x28;
          }
        }
      }
    }
    else {
      iVar7 = 0x2b;
      if (uVar3 != 0x8001) {
        if (uVar3 < 0x8002) {
          if (uVar3 == 0x307) {
            bVar15 = true;
            iVar7 = 0x25;
          }
          else if (uVar3 < 0x307) {
            bVar15 = true;
            iVar7 = 0x24;
          }
          else {
            if (uVar3 != 0x308) goto LAB_0005179c;
            bVar15 = true;
            iVar7 = 0x2a;
          }
        }
        else {
          iVar7 = 0x2d;
          if (((uVar3 != 0x8003) && (iVar7 = 0x2c, 0x8002 < uVar3)) &&
             (iVar7 = 0x2e, uVar3 != 0x8004)) {
LAB_0005179c:
            iVar7 = 0x21;
          }
        }
      }
    }
  }
  uVar2 = *(ushort *)(((unsigned char *)0x00002d6a) + iVar21);
  if (uVar2 == 0x305) {
    iVar8 = 0x29;
    bVar4 = true;
    iVar16 = 0x29;
  }
  else if (uVar2 < 0x306) {
    if (uVar2 == 0x301) {
      iVar8 = 0x23;
      bVar4 = true;
      iVar16 = 0x23;
    }
    else if (uVar2 < 0x302) {
      if (uVar2 == 1) {
        iVar8 = 0x21;
        bVar4 = true;
        iVar16 = 0x21;
      }
      else {
        if (uVar2 != 0x300) goto LAB_000518a4;
        iVar8 = 0x22;
        bVar4 = true;
        iVar16 = 0x22;
      }
    }
    else if (uVar2 == 0x303) {
      iVar8 = 0x27;
      bVar4 = true;
      iVar16 = 0x27;
    }
    else if (uVar2 < 0x304) {
      iVar8 = 0x26;
      bVar4 = true;
      iVar16 = 0x26;
    }
    else {
      iVar8 = 0x28;
      bVar4 = true;
      iVar16 = 0x28;
    }
  }
  else if (uVar2 == 0x8001) {
    iVar8 = 0x2b;
    bVar4 = true;
    iVar16 = 0x2b;
  }
  else if (uVar2 < 0x8002) {
    if (uVar2 == 0x306) {
      iVar8 = 0x24;
      bVar4 = true;
      iVar16 = 0x24;
    }
    else if (uVar2 == 0x307) {
      iVar8 = 0x25;
      bVar4 = true;
      iVar16 = 0x25;
    }
    else {
LAB_000518a4:
      iVar8 = 0x20;
      iVar16 = 0x20;
    }
  }
  else if (uVar2 == 0x8003) {
    iVar8 = 0x2d;
    bVar4 = true;
    iVar16 = 0x2d;
  }
  else if (uVar2 < 0x8003) {
    iVar8 = 0x2c;
    bVar4 = true;
    iVar16 = 0x2c;
  }
  else {
    if (uVar2 != 0x8004) goto LAB_000518a4;
    iVar8 = 0x2e;
    bVar4 = true;
    iVar16 = 0x2e;
  }
  uVar3 = *(ushort *)(((unsigned char *)0x00002d6e) + iVar21);
  if (uVar2 != uVar3) {
    if (uVar3 == 0x305) {
      bVar15 = true;
      iVar8 = 0x29;
    }
    else if (uVar3 < 0x306) {
      if (uVar3 == 0x301) {
        bVar15 = true;
        iVar8 = 0x23;
      }
      else if (uVar3 < 0x302) {
        if (uVar3 == 1) {
          bVar15 = true;
          iVar8 = 0x21;
        }
        else {
          if (uVar3 != 0x300) goto LAB_00051a20;
          bVar15 = true;
          iVar8 = 0x22;
        }
      }
      else if (uVar3 == 0x303) {
        bVar15 = true;
        iVar8 = 0x27;
      }
      else if (uVar3 < 0x304) {
        bVar15 = true;
        iVar8 = 0x26;
      }
      else {
        bVar15 = true;
        iVar8 = 0x28;
      }
    }
    else if (uVar3 == 0x8001) {
      bVar15 = true;
      iVar8 = 0x2b;
    }
    else if (uVar3 < 0x8002) {
      if (uVar3 == 0x306) {
        bVar15 = true;
        iVar8 = 0x24;
      }
      else if (uVar3 == 0x307) {
        bVar15 = true;
        iVar8 = 0x25;
      }
      else {
LAB_00051a20:
        iVar8 = 0x20;
      }
    }
    else if (uVar3 == 0x8003) {
      bVar15 = true;
      iVar8 = 0x2d;
    }
    else if (uVar3 < 0x8003) {
      bVar15 = true;
      iVar8 = 0x2c;
    }
    else {
      if (uVar3 != 0x8004) goto LAB_00051a20;
      bVar15 = true;
      iVar8 = 0x2e;
    }
  }
  if ((uVar1 == 0x8006) &&
     (iVar10 = *(int *)(((unsigned char *)0x00002d68) + iVar21), iVar10 == *(int *)(((unsigned char *)0x00002d6c) + iVar21))) {
    if ((iVar10 == 0x3020303) || ((iVar10 == 0x3020001 || (iVar10 == 0x303)))) {
      iVar18 = 1;
    }
    else if ((((iVar10 == 0x301) || (iVar10 == 0x10001)) || (iVar10 == 0x3060001)) ||
            (iVar10 == 0x3040001)) {
      iVar18 = 2;
      if ((*(uint *)(param_1 + 0x8c) & 0x400000) == 0) goto LAB_00051c10;
    }
    else if (iVar10 == 0x3070001) {
LAB_00051c10:
      iVar18 = 3;
    }
    else {
      iVar18 = 4;
      if ((iVar10 != 0x3030001) && (iVar18 = 6, iVar10 != 0x3060000)) goto LAB_00051c00;
    }
  }
  else {
LAB_00051c00:
    iVar18 = 0;
  }
  uVar9 = *(uint *)(param_1 + 0x1a80);
  *(uint *)(param_1 + 0x1a80) = uVar9 | 3;
  dVar22 = DOUBLE_001aa258;
  dVar23 = DOUBLE_001aa1e8;
  if ((bVar4) || (iVar10 = 0, bVar15)) {
    iVar10 = 1;
  }
  *(uint *)(param_1 + 0x1a84) =
       iVar8 << 0x18 | iVar7 << 0x10 | iVar12 << 0xc | *(uint *)(param_1 + 0x1a84) & 0xc0c08fff;
  *(uint *)(param_1 + 0x1a80) =
       iVar16 << 0x18 |
       iVar14 << 0x10 | iVar19 << 0xc | iVar18 << 3 | iVar10 << 2 | uVar9 & 0xc0c08fc3 | 3;
  dVar22 = (double)*(float *)(((unsigned char *)0x00002d7c) + iVar21) * dVar22;
  if (dVar23 <= dVar22) {
    iVar19 = (int)(dVar22 - dVar23) + -0x80000000;
  }
  else {
    iVar19 = (int)dVar22;
  }
  dVar23 = (double)*(float *)(((unsigned char *)0x00002d70) + iVar21) * DOUBLE_001aa258;
  if (DOUBLE_001aa1e8 <= dVar23) {
    iVar12 = (int)(dVar23 - DOUBLE_001aa1e8) + -0x80000000;
  }
  else {
    iVar12 = (int)dVar23;
  }
  dVar23 = (double)*(float *)(((unsigned char *)0x00002d74) + iVar21) * DOUBLE_001aa258;
  if (DOUBLE_001aa1e8 <= dVar23) {
    iVar7 = (int)(dVar23 - DOUBLE_001aa1e8) + -0x80000000;
  }
  else {
    iVar7 = (int)dVar23;
  }
  dVar23 = (double)*(float *)(((unsigned char *)0x00002d78) + iVar21) * DOUBLE_001aa258;
  if (DOUBLE_001aa1e8 <= dVar23) {
    uVar9 = (int)(dVar23 - DOUBLE_001aa1e8) + 0x80000000;
  }
  else {
    uVar9 = (uint)dVar23;
  }
  *(uint *)(param_1 + 0x1a88) = iVar19 << 0x18 | iVar12 << 0x10 | iVar7 << 8 | uVar9;
  fVar6 = FLOAT_001aa154;
  fVar5 = FLOAT_001aa10c;
  if ((*(uint *)(PTR_DAT_001e88c8 + (uint)*(byte *)(param_1 + 0x293f) * 0x24 + 0x18) & 0x3c00) ==
      0x2800) {
    uVar13 = ((uint (*)())FUN_0001d7c0)((double)*(float *)(((unsigned char *)0x00002d70) + iVar21));
    *(undefined2 *)(param_1 + 0x1a8e) = uVar13;
    uVar13 = ((uint (*)())FUN_0001d7c0)((double)*(float *)(((unsigned char *)0x00002d7c) + iVar21));
    *(undefined2 *)(param_1 + 0x1a8c) = uVar13;
    uVar13 = ((uint (*)())FUN_0001d7c0)((double)*(float *)(((unsigned char *)0x00002d78) + iVar21));
    *(undefined2 *)(param_1 + 0x1a92) = uVar13;
    uVar13 = ((uint (*)())FUN_0001d7c0)((double)*(float *)(((unsigned char *)0x00002d74) + iVar21));
    *(undefined2 *)(param_1 + 0x1a90) = uVar13;
  }
  else {
    *(short *)(param_1 + 0x1a8e) =
         (short)(int)(*(float *)(((unsigned char *)0x00002d70) + iVar21) * FLOAT_001aa154 + FLOAT_001aa10c);
    *(short *)(param_1 + 0x1a8c) = (short)(int)(*(float *)(((unsigned char *)0x00002d7c) + iVar21) * fVar6 + fVar5);
    *(short *)(param_1 + 0x1a92) = (short)(int)(*(float *)(((unsigned char *)0x00002d78) + iVar21) * fVar6 + fVar5);
    *(short *)(param_1 + 0x1a90) = (short)(int)(*(float *)(((unsigned char *)0x00002d74) + iVar21) * fVar6 + fVar5);
  }
LAB_00051ee0:
  if ((((unsigned char *)0x00002ddc)[iVar21] == '\0') || ((*(uint *)(*(int *)(param_1 + 4) + 0x154) & 0xf) != 3))
  {
    *(uint *)(param_1 + 0x1af0) = *(uint *)(param_1 + 0x1af0) & 0xfffffff0 | 5;
  }
  else {
    *(uint *)(param_1 + 0x1af0) = *(uint *)(param_1 + 0x1af0) & 0xfffffff0 | 6;
  }
  if ((((unsigned char *)0x00002e33)[iVar21] == '\0') || (((unsigned char *)0x00001492)[param_1] != '\0')) {
    uVar9 = *(uint *)(FUN_00001af4 + param_1 + 4) & 0xfffffffb;
    *(uint *)(FUN_00001af4 + param_1 + 4) = uVar9;
  }
  else {
    switch(*(undefined2 *)(((unsigned char *)0x00002e30) + iVar21)) {
    case 0x1500:
      iVar21 = 0;
      break;
    case 0x1501:
      iVar21 = 8;
      break;
    case 0x1502:
      iVar21 = 4;
      break;
    default:
      iVar21 = 0xc;
      break;
    case 0x1504:
      iVar21 = 2;
      break;
    case 0x1505:
      iVar21 = 10;
      break;
    case 0x1506:
      iVar21 = 6;
      break;
    case 0x1507:
      iVar21 = 0xe;
      break;
    case 0x1508:
      iVar21 = 1;
      break;
    case 0x1509:
      iVar21 = 9;
      break;
    case 0x150a:
      iVar21 = 5;
      break;
    case 0x150b:
      iVar21 = 0xd;
      break;
    case 0x150c:
      iVar21 = 3;
      break;
    case 0x150d:
      iVar21 = 0xb;
      break;
    case 0x150e:
      iVar21 = 7;
      break;
    case 0x150f:
      iVar21 = 0xf;
    }
    uVar9 = iVar21 << 8 | *(uint *)(FUN_00001af4 + param_1 + 4) & 0xfffff0ff | 4;
    *(uint *)(FUN_00001af4 + param_1 + 4) = uVar9;
  }
  uVar11 = *(uint *)(param_1 + 0x1930);
  *(uint *)(param_1 + 0x1930) = uVar11 | 4;
  if (uVar20 != uVar9) {
    *(uint *)(param_1 + 0x1930) = uVar11 | 0x10004;
  }
  if (((uVar17 & 1) == 0) && ((*(uint *)(param_1 + 0x1a80) & 1) != 0)) {
    *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x100;
  }
  return;
}

/* FUN_000520c0 @ 0x520c0 (436 bytes) */
int FUN_000520c0(param_1)
  int param_1;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  double dVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  
  dVar6 = DOUBLE_001aa1e0;
  fVar4 = FLOAT_001aa10c;
  iVar8 = *(int *)(param_1 + 4);
  iVar10 = *(int *)(param_1 + 0x1c9c);
  iVar9 = *(int *)(param_1 + 0x1c98);
  iVar13 = *(int *)(param_1 + 0x1c88);
  iVar12 = *(int *)(param_1 + 0x1c94);
  iVar11 = *(int *)(param_1 + 0x1c90);
  iVar15 = *(int *)(param_1 + 0x1c8c);
  iVar14 = *(int *)(iVar8 + 0x10);
  fVar1 = *(float *)(iVar8 + 0x2a58);
  fVar2 = *(float *)(iVar8 + 0x2a54);
  *(undefined4 *)(param_1 + 0x1c9c) = *(undefined4 *)(iVar14 + 0x1818);
  *(undefined4 *)(param_1 + 0x1c98) = *(undefined4 *)(iVar14 + 0x1828);
  uVar7 = *(uint *)(iVar14 + 0x1840);
  fVar3 = fVar1 * (float)((double)CONCAT44(0x43300000,*(uint *)(iVar14 + 0x184c) ^ 0x80000000) -
                         dVar6) * fVar4;
  fVar5 = fVar1 * (float)((double)CONCAT44(0x43300000,*(uint *)(iVar14 + 0x1844) ^ 0x80000000) -
                         dVar6) + fVar3;
  fVar4 = fVar2 * (float)((double)CONCAT44(0x43300000,*(uint *)(iVar14 + 0x1848) ^ 0x80000000) -
                         dVar6) * fVar4;
  if (*(char *)(param_1 + 0x293c) != '\0') {
    fVar5 = fVar1 * (float)((double)CONCAT44(0x43300000,*(uint *)(iVar8 + 0x160) ^ 0x80000000) -
                           dVar6) - fVar5;
    fVar3 = -fVar3;
  }
  *(float *)(param_1 + 0x1c8c) = fVar4;
  *(float *)(param_1 + 0x1c88) =
       fVar2 * (float)((double)CONCAT44(0x43300000,uVar7 ^ 0x80000000) - dVar6) + fVar4;
  *(float *)(param_1 + 0x1c94) = fVar3;
  *(float *)(param_1 + 0x1c90) = fVar5;
  if (*(char *)(param_1 + 0x124) != '\0') {
    *(undefined4 *)(param_1 + 0x1c8c) = *(undefined4 *)(param_1 + 0x2814);
    *(undefined4 *)(param_1 + 0x1c94) = *(undefined4 *)(param_1 + 0x2818);
  }
  *(undefined4 *)(param_1 + 0x1ca8) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x1cb0) = 0x3f800000;
  if ((((iVar15 != *(int *)(param_1 + 0x1c8c)) || (iVar13 != *(int *)(param_1 + 0x1c88))) ||
      (iVar12 != *(int *)(param_1 + 0x1c94))) ||
     (((iVar11 != *(int *)(param_1 + 0x1c90) || (iVar10 != *(int *)(param_1 + 0x1c9c))) ||
      (iVar9 != *(int *)(param_1 + 0x1c98))))) {
    *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x80;
  }
  ((int (*)())FUN_0004f550)();
  return;
}

/* FUN_00052280 @ 0x52280 (2608 bytes) */
int FUN_00052280(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined4 uVar2;
  code *pcVar3;
  uint uVar4;
  uint *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  uint uVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  int iVar16;
  
  uVar12 = *(uint *)(param_1 + 0x1930);
  uVar4 = *(uint *)(param_1 + 0x1934) & *(uint *)(param_1 + 0x27b0);
  uVar4 = uVar4 | (uVar4 & *(uint *)(param_1 + 0x27b4)) << 8;
  if (uVar4 != 0) {
    puVar13 = (undefined4 *)(param_1 + 0x1cdc);
    puVar14 = (undefined4 *)(param_1 + 0x1d1c);
    puVar15 = (undefined4 *)(param_1 + 0x1d5c);
    puVar6 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0xe0);
    iVar9 = *(int *)(param_1 + 0x1938);
    puVar11 = (undefined4 *)(((unsigned char *)0x00001d9c) + param_1);
    puVar7 = (undefined4 *)(((unsigned char *)0x00001ddc) + param_1);
    *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar6;
    puVar8 = (undefined4 *)(((unsigned char *)0x00001e1c) + param_1);
    do {
      if ((uVar4 & 1) != 0) {
        *puVar6 = ((unsigned char *)0x00001100) + iVar9;
        uVar2 = *puVar13;
        puVar6[2] = ((unsigned char *)0x00001110) + iVar9;
        puVar6[1] = uVar2;
        uVar2 = *puVar14;
        puVar6[4] = (*(unsigned char *)0x00001120) + iVar9;
        puVar6[3] = uVar2;
        uVar2 = *puVar15;
        puVar6[6] = ((unsigned char *)0x00001130) + iVar9;
        puVar6[5] = uVar2;
        uVar2 = *puVar11;
        puVar6[8] = (*(unsigned char *)0x00001170) + iVar9;
        puVar6[7] = uVar2;
        uVar2 = *puVar8;
        puVar6[10] = ((unsigned char *)0x00001160) + iVar9;
        puVar6[0xc] = ((unsigned char *)0x00001140) + iVar9;
        puVar6[0xb] = 0;
        puVar6[9] = uVar2;
        puVar6[0xd] = *puVar7;
        puVar6 = puVar6 + 0xe;
      }
      uVar4 = uVar4 >> 1;
      iVar9 = iVar9 + 1;
      puVar13 = puVar13 + 1;
      puVar14 = puVar14 + 1;
      puVar15 = puVar15 + 1;
      puVar11 = puVar11 + 1;
      puVar8 = puVar8 + 1;
      puVar7 = puVar7 + 1;
    } while (uVar4 != 0);
    pcVar3 = *(code **)(param_1 + 0x275c);
    *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar6;
    (*pcVar3)(param_1,puVar6);
  }
  if (((*(uint *)(param_1 + 0x44) & 0x100) == 0) || ((*(uint *)(param_1 + 0x27b0) & 1) != 0)) {
    puVar6 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
    puVar7 = puVar6 + 2;
    *puVar6 = ((unsigned char *)0x00001041);
    puVar6[1] = *(int *)(param_1 + 0x27b0) << (*(uint *)(param_1 + 0x1938) & 0x3f);
  }
  else {
    puVar6 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,4);
    puVar7 = puVar6 + 4;
    *puVar6 = ((unsigned char *)0x00001041);
    puVar6[1] = (*(uint *)(param_1 + 0x27b0) | 1) << (*(uint *)(param_1 + 0x1938) & 0x3f);
    iVar9 = *(int *)(param_1 + 0x1938);
    puVar6[3] = 0;
    puVar6[2] = ((unsigned char *)0x00001100) + iVar9;
  }
  pcVar3 = *(code **)(param_1 + 0x275c);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar7;
  (*pcVar3)(param_1,puVar7);
  if (uVar12 == 0) {
    *(undefined4 *)(param_1 + 0x1934) = 0;
  }
  else {
    puVar7 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0xde);
    *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar7;
    puVar6 = puVar7;
    if ((uVar12 & 0x100) != 0) {
      puVar6 = puVar7 + 2;
      *puVar7 = ((unsigned char *)0x00001393);
      puVar7[1] = 10;
    }
    if ((uVar12 & 0x2000000) != 0) {
      *puVar6 = ((unsigned char *)0x000013c6);
      puVar6[1] = 3;
      puVar6 = puVar6 + 2;
    }
    if ((uVar12 & 1) != 0) {
      *puVar6 = ((unsigned char *)0x000212f2);
      puVar6[1] = *(undefined4 *)(param_1 + 0x1a54);
      puVar6[2] = *(undefined4 *)(param_1 + 0x1a58);
      puVar1 = PTR_DAT_001e88c8;
      uVar2 = *(undefined4 *)(param_1 + 0x1a5c);
      puVar6[4] = ((unsigned char *)0x000012f0);
      puVar6[3] = uVar2;
      uVar4 = *(uint *)(param_1 + 0x1aec);
      puVar6[5] = uVar4;
      if ((*(uint *)(puVar1 + (uint)*(byte *)(param_1 + 0x293f) * 0x24 + 0x18) & 0x8000) == 0) {
        puVar6[5] = uVar4 & 0xfffffffe;
      }
      puVar6[6] = 0x110a5;
      puVar6[7] = *(undefined4 *)(param_1 + 0x1a7c);
      uVar2 = *(undefined4 *)(param_1 + 0x1a78);
      puVar6[9] = ((unsigned char *)0x00001007);
      puVar6[8] = uVar2;
      puVar6[10] = *(undefined4 *)(param_1 + 0x1a64);
      puVar6 = puVar6 + 0xb;
    }
    puVar1 = PTR_DAT_001e88c8;
    if ((uVar12 & 4) != 0) {
      *puVar6 = 0x11381;
      uVar4 = *(uint *)(param_1 + 0x1a80);
      puVar6[1] = uVar4;
      if ((*(uint *)(puVar1 + (uint)*(byte *)(param_1 + 0x293f) * 0x24 + 0x18) & 0x4000) == 0) {
        puVar6[1] = uVar4 & 0xfffffffc;
      }
      uVar2 = *(undefined4 *)(param_1 + 0x1a84);
      puVar6[3] = ((unsigned char *)0x00001384);
      puVar6[2] = uVar2;
      uVar2 = *(undefined4 *)(param_1 + 0x1a88);
      puVar6[5] = ((unsigned char *)0x00001394);
      puVar6[4] = uVar2;
      uVar2 = *(undefined4 *)(param_1 + 0x1af0);
      puVar6[7] = ((unsigned char *)0x000013be);
      puVar6[6] = uVar2;
      uVar2 = *(undefined4 *)(param_1 + 0x1a8c);
      puVar6[9] = ((unsigned char *)0x000013bf);
      puVar6[8] = uVar2;
      puVar6[10] = *(undefined4 *)(param_1 + 0x1a90);
      puVar6 = puVar6 + 0xb;
    }
    if ((uVar12 & 0x10000) != 0) {
      *puVar6 = ((unsigned char *)0x00001386);
      puVar6[1] = *(undefined4 *)(param_1 + 0x1af8);
      puVar6 = puVar6 + 2;
    }
    if ((uVar12 & 0x200) != 0) {
      *puVar6 = ((unsigned char *)0x000012f5);
      puVar1 = PTR_DAT_001e88c8;
      uVar4 = *(uint *)(param_1 + 0x1a4c);
      puVar6[1] = uVar4;
      if ((*(uint *)(puVar1 + (uint)*(byte *)(param_1 + 0x293f) * 0x24 + 0x18) & 0x8000) == 0) {
        puVar6[1] = uVar4 & 0xfffff7ff;
      }
      puVar6[2] = ((unsigned char *)0x000012f8);
      puVar6[3] = *(undefined4 *)(param_1 + 0x1bdc);
      puVar6 = puVar6 + 4;
    }
    if ((uVar12 & 0x8000000) != 0) {
      *puVar6 = ((unsigned char *)0x000012f6);
      puVar6[1] = *(undefined4 *)(param_1 + 0x1a50);
      puVar6 = puVar6 + 2;
    }
    puVar7 = puVar6;
    if ((uVar12 & 0x20000) != 0) {
      puVar7 = puVar6 + 2;
      *puVar6 = ((unsigned char *)0x000013c5);
      puVar6[1] = *(undefined4 *)(param_1 + 0x1ab8);
      if (1 < *(int *)(param_1 + 0x23dc)) {
        puVar7 = puVar6 + 4;
        puVar6[2] = ((unsigned char *)0x000010e6);
        puVar6[3] = *(undefined4 *)(param_1 + 0x1bd4);
      }
    }
    if ((uVar12 & 0x800) != 0) {
      *puVar7 = 0x113c0;
      puVar7[1] = *(undefined4 *)(param_1 + 0x1aa0);
      puVar7[2] = *(undefined4 *)(param_1 + 0x1aa4);
      puVar7 = puVar7 + 3;
    }
    if ((uVar12 & 8) != 0) {
      *puVar7 = ((unsigned char *)0x000013c2);
      puVar7[1] = *(undefined4 *)(param_1 + 0x1aa8);
      puVar7 = puVar7 + 2;
    }
    if ((uVar12 & 0x1000) != 0) {
      iVar9 = *(int *)(param_1 + 4);
      puVar5 = *(uint **)(iVar9 + 0x1d8);
      *puVar5 = (int)puVar7 - (int)puVar5 >> 2 | *puVar5;
      *(undefined4 **)(iVar9 + 0x1d8) = puVar7;
      *puVar7 = 0x2f000000;
      puVar7[1] = (*(unsigned char *)0x000010e9);
      uVar2 = *(undefined4 *)(param_1 + 0x1ae0);
      puVar7[3] = ((unsigned char *)0x000013c7);
      puVar7[2] = uVar2;
      puVar7[4] = *(undefined4 *)(param_1 + 0x1ab0);
      puVar7 = puVar7 + 5;
    }
    if ((uVar12 & 0x20) != 0) {
      *puVar7 = ((unsigned char *)0x000410a9);
      puVar7[1] = *(undefined4 *)(((unsigned char *)0x00001b1c) + param_1);
      puVar7[2] = *(undefined4 *)(((unsigned char *)0x00001b18) + param_1);
      puVar7[3] = *(undefined4 *)(((unsigned char *)0x00001b24) + param_1);
      puVar7[4] = *(undefined4 *)(((unsigned char *)0x00001b20) + param_1);
      puVar7[5] = *(undefined4 *)(((unsigned char *)0x00001b14) + param_1);
      puVar7 = puVar7 + 6;
    }
    if ((uVar12 & 0x2000) != 0) {
      *puVar7 = ((unsigned char *)0x000010a2);
      uVar2 = *(undefined4 *)(param_1 + 0x1b3c);
      puVar7[2] = ((unsigned char *)0x00001002);
      puVar7[1] = uVar2;
      uVar2 = *(undefined4 *)(param_1 + 0x1b50);
      puVar7[4] = ((unsigned char *)0x00001007);
      puVar7[3] = uVar2;
      uVar2 = *(undefined4 *)(param_1 + 0x1a64);
      puVar7[6] = 0x825;
      puVar7[5] = uVar2;
      uVar2 = *(undefined4 *)(param_1 + 0x1ba0);
      puVar7[8] = ((unsigned char *)0x00001048);
      puVar7[7] = uVar2;
      puVar7[9] = *(undefined4 *)(param_1 + 0x1bc0);
      puVar7 = puVar7 + 10;
    }
    if ((uVar12 & 0x8000) != 0) {
      *puVar7 = ((unsigned char *)0x00001087);
      uVar2 = *(undefined4 *)(param_1 + 0x1ccc);
      puVar7[2] = 0x31080;
      puVar7[1] = uVar2;
      puVar7[3] = *(undefined4 *)(param_1 + 0x1cbc);
      puVar7[4] = *(undefined4 *)(param_1 + 0x1cc4);
      puVar7[5] = *(undefined4 *)(param_1 + 0x1cc0);
      uVar2 = *(undefined4 *)(param_1 + 0x1cc8);
      puVar7[7] = ((unsigned char *)0x0000108c);
      puVar7[6] = uVar2;
      puVar7[8] = *(undefined4 *)(param_1 + 0x1cd0);
      puVar7 = puVar7 + 9;
    }
    if ((uVar12 & 0x4000) != 0) {
      *puVar7 = 0x1108d;
      puVar7[1] = *(undefined4 *)(param_1 + 0x1b40);
      uVar2 = *(undefined4 *)(param_1 + 0x1b64);
      puVar7[3] = ((unsigned char *)0x0000109a);
      puVar7[2] = uVar2;
      puVar7[4] = *(undefined4 *)(param_1 + 0x1b70);
      puVar7 = puVar7 + 5;
    }
    if ((uVar12 & 0x10) != 0) {
      *puVar7 = ((unsigned char *)0x00001383);
      uVar2 = *(undefined4 *)(FUN_00001af4 + param_1);
      puVar7[2] = ((unsigned char *)0x0000109e);
      puVar7[1] = uVar2;
      puVar7[3] = *(undefined4 *)(((unsigned char *)0x00001b2c) + param_1);
      puVar7 = puVar7 + 4;
    }
    if ((uVar12 & 0x40) != 0) {
      *puVar7 = 0x311a9;
      puVar7[1] = *(undefined4 *)(param_1 + 0x233c);
      puVar7[2] = *(undefined4 *)(param_1 + 0x2340);
      puVar7[3] = *(undefined4 *)(param_1 + 0x2344);
      uVar2 = *(undefined4 *)(FUN_00002348 + param_1);
      puVar7[5] = ((unsigned char *)0x000010b1);
      puVar7[4] = uVar2;
      uVar2 = *(undefined4 *)(FUN_00001b34 + param_1);
      puVar7[7] = ((unsigned char *)0x000010b0);
      puVar7[6] = uVar2;
      puVar7[8] = *(undefined4 *)(param_1 + 0x1b38);
      puVar7 = puVar7 + 9;
    }
    if ((uVar12 & 0x400) != 0) {
      *puVar7 = ((unsigned char *)0x000010ae);
      puVar7[1] = *(undefined4 *)(((unsigned char *)0x00001b30) + param_1);
      puVar7 = puVar7 + 2;
    }
    if ((uVar12 & 0x80000) != 0) {
      *puVar7 = ((unsigned char *)0x00001008);
      uVar2 = *(undefined4 *)(param_1 + 0x1a60);
      puVar7[2] = 0x11004;
      puVar7[1] = uVar2;
      puVar7[3] = *(undefined4 *)(param_1 + 0x1a68);
      uVar2 = *(undefined4 *)(param_1 + 0x1a6c);
      puVar7[5] = ((unsigned char *)0x000010fa);
      puVar7[4] = uVar2;
      puVar7[6] = *(undefined4 *)(param_1 + 0x1b60);
      puVar7 = puVar7 + 7;
    }
    if ((uVar12 & 2) != 0) {
      puVar7 = (undefined4 *)((int (*)())FUN_0004dd10)(param_1,puVar7);
    }
    if ((uVar12 & 0x80) != 0) {
      puVar7 = (undefined4 *)((int (*)())FUN_0004dd40)(param_1,puVar7);
    }
    puVar6 = puVar7;
    if ((uVar12 & 0x40000) != 0) {
      puVar6 = puVar7 + 10;
      *puVar7 = 0x10860;
      puVar7[1] = *(undefined4 *)(param_1 + 0x1b78);
      uVar2 = *(undefined4 *)(param_1 + 0x1ca0);
      puVar7[3] = 0x82d;
      puVar7[2] = uVar2;
      uVar2 = *(undefined4 *)(param_1 + 0x1ca4);
      puVar7[5] = 0x10824;
      puVar7[4] = uVar2;
      puVar7[6] = *(undefined4 *)(param_1 + 0x1b9c);
      uVar2 = *(undefined4 *)(param_1 + 0x1ba0);
      puVar7[8] = ((unsigned char *)0x00001047);
      puVar7[7] = uVar2;
      puVar7[9] = *(undefined4 *)(param_1 + 0x1bb0);
      if ((-1 < (int)uVar12) || (*(char *)(param_1 + 0x1868) != '\0')) {
        iVar16 = 8;
        puVar7[10] = ((unsigned char *)0x000010c0);
        iVar10 = 0;
        puVar7[0xb] = *(undefined4 *)(param_1 + 0x1f2c);
        puVar7[0xc] = *(uint *)(param_1 + 0x1f28) | 0x70000;
        iVar9 = param_1;
        do {
          puVar6 = (undefined4 *)(iVar9 + 0x1ee8);
          iVar9 = iVar9 + 4;
          *(undefined4 *)((int)puVar7 + iVar10 + 0x34) = *puVar6;
          iVar10 = iVar10 + 4;
          iVar16 = iVar16 + -1;
        } while (iVar16 != 0);
        puVar6 = puVar7 + 0x15;
      }
    }
    if ((uVar12 & 0x400000) != 0) {
      *puVar6 = 0x887;
      puVar6[1] = *(undefined4 *)(param_1 + 0x1b74);
      puVar6 = puVar6 + 2;
    }
    if ((uVar12 & 0x800000) != 0) {
      *puVar6 = ((unsigned char *)0x00001002);
      uVar2 = *(undefined4 *)(param_1 + 0x1b50);
      puVar6[2] = 0x825;
      puVar6[1] = uVar2;
      uVar2 = *(undefined4 *)(param_1 + 0x1ba0);
      puVar6[4] = ((unsigned char *)0x00001048);
      puVar6[3] = uVar2;
      puVar6[5] = *(undefined4 *)(param_1 + 0x1bc0);
      puVar6 = puVar6 + 6;
    }
    if ((uVar12 & 0x4000000) != 0) {
      *(undefined4 *)(param_1 + 0x1e68) = 0;
    }
    if ((uVar12 & 0x10000000) != 0) {
      *puVar6 = ((unsigned char *)0x000413de);
      puVar6[1] = *(undefined4 *)(param_1 + 0x2360);
      puVar6[2] = *(undefined4 *)(param_1 + 0x2364);
      puVar6[3] = *(undefined4 *)(((unsigned char *)0x00002368) + param_1);
      puVar6[4] = *(undefined4 *)(((unsigned char *)0x0000236c) + param_1);
      uVar2 = *(undefined4 *)(((unsigned char *)0x00002370) + param_1);
      puVar6[6] = 0x313e9;
      puVar6[5] = uVar2;
      puVar6[7] = *(undefined4 *)(((unsigned char *)0x00002374) + param_1);
      puVar6[8] = *(undefined4 *)(((unsigned char *)0x00002378) + param_1);
      puVar6[9] = *(undefined4 *)(((unsigned char *)0x0000237c) + param_1);
      puVar6[10] = *(undefined4 *)(((unsigned char *)0x00002380) + param_1);
      puVar6 = puVar6 + 0xb;
    }
    if ((uVar12 & 0x20000000) != 0) {
      *puVar6 = ((unsigned char *)0x000813ad);
      puVar6[1] = *(undefined4 *)(((unsigned char *)0x00002384) + param_1);
      puVar6[2] = *(undefined4 *)(((unsigned char *)0x00002388) + param_1);
      puVar6[3] = *(undefined4 *)(((unsigned char *)0x0000238c) + param_1);
      puVar6[4] = *(undefined4 *)(((unsigned char *)0x00002390) + param_1);
      puVar6[5] = *(undefined4 *)(((unsigned char *)0x00002394) + param_1);
      puVar6[6] = *(undefined4 *)(((unsigned char *)0x00002398) + param_1);
      puVar6[7] = *(undefined4 *)(((unsigned char *)0x0000239c) + param_1);
      puVar6[8] = *(undefined4 *)(((unsigned char *)0x000023a0) + param_1);
      puVar6[9] = *(undefined4 *)(((unsigned char *)0x000023a4) + param_1);
      puVar6 = puVar6 + 10;
    }
    uVar12 = (uint)-(int)puVar6 >> 2 & 0xf;
    puVar7 = puVar6;
    for (uVar4 = uVar12; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar7 = 0x80000000;
      puVar7 = puVar7 + 1;
    }
    pcVar3 = *(code **)(param_1 + 0x275c);
    *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar6 + uVar12;
    (*pcVar3)(param_1);
    uVar4 = *(uint *)(param_1 + 0x1930);
    if ((uVar4 & 0xc0100000) != 0) {
      (**(code **)(((unsigned char *)0x00001330) + param_1))(param_1,0xc0100000);
      uVar4 = *(uint *)(param_1 + 0x1930);
    }
    if ((uVar4 & 0x200000) != 0) {
      FUN_00086710(param_1);
      uVar4 = *(uint *)(param_1 + 0x1930);
    }
    if ((uVar4 & 0x1000000) != 0) {
      FUN_00086840(param_1);
    }
    *(undefined4 *)(param_1 + 0x1934) = 0;
    *(undefined4 *)(param_1 + 0x1930) = 0;
  }
  return;
}

/* FUN_00052cc0 @ 0x52cc0 (372 bytes) */
int FUN_00052cc0(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  
  puVar2 = PTR_LAB_001e89b8;
  puVar1 = PTR_LAB_001e89b0;
  uVar3 = 0;
  if (param_1 != -0x1168) {
    if (*(char *)(param_1 + 0x1868) == '\0') {
      *(undefined **)(((unsigned char *)0x000011a0) + param_1) = PTR_LAB_001e89c4;
      *(undefined **)(((unsigned char *)0x000011a8) + param_1) = puVar2;
      puVar1 = PTR_LAB_001e89d8;
      *(undefined **)(((unsigned char *)0x000011a4) + param_1) = PTR_LAB_001e89c8;
      *(undefined **)(((unsigned char *)0x000011b0) + param_1) = puVar1;
      puVar1 = PTR_DAT_001e89a8;
      *(undefined **)(((unsigned char *)0x000011ac) + param_1) = PTR_LAB_001e89cc;
      *(undefined **)(((unsigned char *)0x00001190) + param_1) = puVar1;
      puVar1 = PTR_LAB_001e89e8;
      *(undefined **)(((unsigned char *)0x00001194) + param_1) = PTR_LAB_001e89b4;
      *(undefined **)(((unsigned char *)0x0000119c) + param_1) = puVar1;
      *(undefined **)(((unsigned char *)0x00001198) + param_1) = PTR_FUN_001e89a4;
    }
    else {
      *(undefined **)(((unsigned char *)0x000011a0) + param_1) = PTR_LAB_001e89bc;
      *(undefined **)(((unsigned char *)0x000011a8) + param_1) = puVar1;
      puVar1 = PTR_LAB_001e89d8;
      *(undefined **)(((unsigned char *)0x000011a4) + param_1) = PTR_LAB_001e89d0;
      *(undefined **)(((unsigned char *)0x000011b0) + param_1) = puVar1;
      puVar1 = PTR_DAT_001e89a0;
      *(undefined **)(((unsigned char *)0x000011ac) + param_1) = PTR_LAB_001e89d4;
      *(undefined **)(((unsigned char *)0x00001190) + param_1) = puVar1;
      puVar1 = PTR_DAT_001e89dc;
      *(undefined **)(((unsigned char *)0x00001194) + param_1) = PTR_LAB_001e89e4;
      *(undefined **)(((unsigned char *)0x0000119c) + param_1) = puVar1;
      *(undefined **)(((unsigned char *)0x00001198) + param_1) = PTR_FUN_001e89c0;
    }
    puVar1 = PTR_LAB_001e89ac;
    if (*(char *)(param_1 + 0x1868) == '\0') {
      *(undefined4 *)(((unsigned char *)0x00001354) + param_1) = 0;
      *(undefined4 *)(((unsigned char *)0x0000134c) + param_1) = 0;
      *(undefined **)(((unsigned char *)0x00001350) + param_1) = PTR_LAB_001e89e0;
    }
    else {
      *(undefined4 *)(((unsigned char *)0x00001354) + param_1) = 0;
      *(undefined4 *)(((unsigned char *)0x0000134c) + param_1) = 0;
      *(undefined **)(((unsigned char *)0x00001350) + param_1) = puVar1;
    }
    ((unsigned char *)0x000013b0)[param_1] = 8;
    ((int (*)())FUN_00054b20)(param_1);
    uVar3 = 1;
  }
  return uVar3;
}

/* FUN_00052ee0 @ 0x52ee0 (128 bytes) */
int FUN_00052ee0(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(((unsigned char *)0x00001168) + param_1) + 0x1c;
  iVar1 = FUN_00054da0(iVar2);
  if (iVar1 == 0) {
    iVar2 = *(int *)(((unsigned char *)0x0000116c) + param_1) + 0x14;
    iVar1 = FUN_00054da0(iVar2,param_2);
    if (iVar1 == 0) {
      return -0x3ffcf000;
    }
  }
  iVar1 = *(int *)(iVar1 * 0x54 + *(int *)(iVar2 + 4));
  if (iVar1 == 0) {
    return -0x3ffcf000;
  }
  return iVar1;
}

/* FUN_00052f60 @ 0x52f60 (148 bytes) */
int FUN_00052f60(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(((unsigned char *)0x00001168) + param_1) + 0x1c;
  iVar1 = FUN_00054da0(iVar2);
  if (iVar1 == 0) {
    iVar2 = *(int *)(((unsigned char *)0x0000116c) + param_1) + 0x14;
    iVar1 = FUN_00054da0(iVar2,param_2);
    if (iVar1 == 0) {
      return 0;
    }
  }
  iVar1 = *(int *)(iVar1 * 0x54 + *(int *)(iVar2 + 4) + 4);
  if (iVar1 == 0) {
    iVar1 = 0x81;
  }
  return iVar1;
}

/* FUN_00053000 @ 0x53000 (52 bytes) */
int FUN_00053000(param_1, param_2)
  int param_1;
  uint param_2;
{
  byte bVar1;
  
  bVar1 = 0xc;
  if ((param_2 & 2) == 0) {
    bVar1 = 0;
  }
  *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
  *(byte *)(param_1 + 0x2d) = bVar1 | *(byte *)(param_1 + 0x2d);
  *(undefined1 *)(param_1 + 0x29) = 1;
  return;
}

/* FUN_00053060 @ 0x53060 (4 bytes) */
int FUN_00053060()
{
  return;
}

/* FUN_00053070 @ 0x53070 (36 bytes) */
int FUN_00053070(param_1)
  int param_1;
{
  if ((*(int *)(((unsigned char *)0x00001168) + param_1) != 0) &&
     (*(char *)(*(int *)(((unsigned char *)0x00001168) + param_1) + 0x10) != '\0')) {
    return 1;
  }
  return 0;
}

/* FUN_000530a0 @ 0x530a0 (24 bytes) */
int FUN_000530a0(param_1)
  int param_1;
{
  if (*(int *)(((unsigned char *)0x00001168) + param_1) == 0) {
    return;
  }
  *(undefined1 *)(*(int *)(((unsigned char *)0x00001168) + param_1) + 0x10) = 0;
  return;
}

/* FUN_000530c0 @ 0x530c0 (184 bytes) */
int FUN_000530c0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 *param_3;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(((unsigned char *)0x00001168) + param_1);
  if ((iVar2 == 0) || (param_2 != *(int *)(iVar2 + 8))) {
    iVar1 = *(int *)(*(int *)(((unsigned char *)0x0000116c) + param_1) + 4);
    if (iVar1 == 0) {
LAB_00053150:
      param_3[4] = 0;
      *param_3 = 0;
      param_3[1] = 0;
      param_3[2] = 0;
      param_3[3] = 0;
      return;
    }
    iVar3 = *(int *)(*(int *)(((unsigned char *)0x0000116c) + param_1) + 0xc);
    do {
      iVar2 = iVar3;
      if (*(int *)(iVar3 + 8) != param_2) {
        iVar2 = 0;
      }
      iVar1 = iVar1 + -1;
      if (iVar1 == 0) {
        if (iVar2 == 0) goto LAB_00053150;
        break;
      }
      iVar3 = iVar3 + 0x7c;
    } while (iVar2 == 0);
  }
  *param_3 = *(undefined4 *)(iVar2 + 0x54);
  param_3[1] = *(int *)(iVar2 + 0x5c) + *(int *)(iVar2 + 0x60);
  param_3[2] = *(undefined4 *)(iVar2 + 100);
  param_3[3] = *(undefined4 *)(iVar2 + 0x58);
  param_3[4] = *(undefined4 *)(iVar2 + 0x68);
  return;
}

/* FUN_00053220 @ 0x53220 (284 bytes) */
int FUN_00053220(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = (param_2 + param_3) * 4 & 0x7c;
  piVar1 = *(int **)(uVar3 + *(int *)(((unsigned char *)0x0000116c) + param_1) + 0x28);
  while( true ) {
    if (piVar1 == (int *)0x0) {
      iVar4 = *(int *)(((unsigned char *)0x0000116c) + param_1) + 0x14;
      iVar2 = FUN_00055610(param_1,iVar4,param_4,param_5,0x87e1,0,0,param_3);
      if (iVar2 != 0) {
        iVar4 = FUN_00055a30(iVar4,iVar2);
        *(undefined4 *)(iVar4 + 0x50) = param_6;
        *(int *)(iVar4 + 0x48) = param_2;
        *(undefined1 *)(iVar4 + 0x44) = 1;
        *(int *)(iVar4 + 0x4c) = param_3;
        piVar1 = (int *)(**(code **)(param_1 + 0xc))(0x10);
        *piVar1 = param_2;
        piVar1[1] = param_3;
        piVar1[2] = iVar2;
        piVar1[3] = *(int *)(uVar3 + *(int *)(((unsigned char *)0x0000116c) + param_1) + 0x28);
        *(int **)(uVar3 + *(int *)(((unsigned char *)0x0000116c) + param_1) + 0x28) = piVar1;
      }
      return iVar2;
    }
    if ((param_2 == *piVar1) && (param_3 == piVar1[1])) break;
    piVar1 = (int *)piVar1[3];
  }
  return piVar1[2];
}

/* FUN_00053340 @ 0x53340 (368 bytes) */
int FUN_00053340(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  uint param_5;
  int param_6;
{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
  if (((param_2 - 0x87beU < 3) &&
      (((((param_3 - 0x87c1U < 2 || (param_3 == 0x87c4)) || (param_3 == 0x87c3)) ||
        ((param_3 == -3 || (param_3 == -2)))) || (param_3 == -1)))) && (param_4 - 0x87e0U < 2)) {
    if (((param_3 - 0x87c3U < 2) || (param_3 == -3)) || ((param_3 == -2 || (param_3 == -1)))) {
      iVar3 = *(int *)(((unsigned char *)0x00001168) + param_1) + 0x1c;
      if (((unsigned char *)0x00001170)[param_1] == '\0') goto LAB_000534a0;
    }
    else {
      iVar3 = *(int *)(((unsigned char *)0x0000116c) + param_1) + 0x14;
    }
    uVar5 = FUN_00055610(param_1,iVar3,param_2,param_3,param_4,0,param_5,param_6);
    if (1 < param_5) {
      uVar4 = 1;
      do {
        iVar1 = param_5 - uVar4;
        iVar2 = uVar4 + param_6;
        uVar4 = uVar4 + 1;
        FUN_00055610(param_1,iVar3,param_2,param_3,param_4,uVar5,iVar1,iVar2);
      } while (param_5 != uVar4);
    }
  }
  else {
LAB_000534a0:
    uVar5 = 0;
  }
  return uVar5;
}

/* FUN_000534c0 @ 0x534c0 (260 bytes) */
int FUN_000534c0(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  byte *param_3;
  undefined4 *param_4;
  undefined4 *param_5;
{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 local_48 [8];
  
  local_48[0] = DAT_001aa584;
  local_48[2] = DAT_001aa58c;
  local_48[1] = DAT_001aa588;
  iVar1 = *(int *)(((unsigned char *)0x00001168) + param_1);
  uVar2 = FUN_00055610(param_1,iVar1 + 0x1c,0x87bf,local_48[*param_3],0x87e1,0,param_2,*param_4);
  *param_5 = uVar2;
  if (1 < param_2) {
    uVar3 = 1;
    do {
      uVar4 = uVar3 + 1;
      uVar2 = FUN_00055610(param_1,iVar1 + 0x1c,0x87bf,local_48[param_3[uVar3]],0x87e1,*param_5,
                           param_2 - uVar3,param_4[uVar3]);
      param_5[uVar3] = uVar2;
      uVar3 = uVar4;
    } while (param_2 != uVar4);
  }
  return;
}

/* FUN_00053730 @ 0x53730 (132 bytes) */
int FUN_00053730(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  if (((unsigned char *)0x00001170)[param_1] != '\0') {
    FUN_000553c0(param_1,*(undefined4 *)(((unsigned char *)0x00001168) + param_1),param_2,param_3,param_4,param_5,
                 param_6,param_7);
  }
  return;
}

/* FUN_000538e0 @ 0x538e0 (164 bytes) */
int FUN_000538e0(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  if (((unsigned char *)0x00001170)[param_1] == '\0') {
    uVar1 = *(undefined4 *)(((unsigned char *)0x00001168) + param_1);
    ((unsigned char *)0x00001170)[param_1] = 1;
    FUN_00055300(param_1,uVar1);
    FUN_00055b50(param_1,uVar1);
    *(undefined4 *)(((unsigned char *)0x00001184) + param_1) = 0;
    *(undefined4 *)(((unsigned char *)0x00001174) + param_1) = 0;
    *(undefined4 *)(((unsigned char *)0x0000117c) + param_1) = 0;
    *(undefined4 *)(((unsigned char *)0x00001178) + param_1) = 0;
    *(undefined4 *)(((unsigned char *)0x00001180) + param_1) = 0;
    if ((*(uint *)(param_1 + 0x44) & 0x100000) != 0) {
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
      *(byte *)(param_1 + 0x2d) = *(byte *)(param_1 + 0x2d) | 7;
    }
  }
  return;
}

/* FUN_00053990 @ 0x53990 (244 bytes) */
int FUN_00053990(param_1)
  int param_1;
{
  int iVar1;
  
  if (((unsigned char *)0x00001170)[param_1] != '\0') {
    iVar1 = *(int *)(((unsigned char *)0x00001168) + param_1);
    ((unsigned char *)0x00001170)[param_1] = 0;
    FUN_000b9f10(param_1,iVar1);
    (**(code **)(((unsigned char *)0x00001190) + param_1))(param_1,iVar1);
    (**(code **)(((unsigned char *)0x00001194) + param_1))(param_1,iVar1);
    (**(code **)(((unsigned char *)0x0000119c) + param_1))(param_1,iVar1);
    *(undefined4 *)(((unsigned char *)0x00001174) + param_1) = *(undefined4 *)(iVar1 + 0x54);
    *(undefined4 *)(((unsigned char *)0x0000117c) + param_1) = *(undefined4 *)(iVar1 + 0x58);
    *(undefined4 *)(((unsigned char *)0x00001178) + param_1) = *(undefined4 *)(iVar1 + 0x5c);
    *(undefined4 *)(((unsigned char *)0x00001180) + param_1) = *(undefined4 *)(iVar1 + 0x60);
    *(undefined4 *)(((unsigned char *)0x00001184) + param_1) = *(undefined4 *)(iVar1 + 100);
    if ((*(uint *)(param_1 + 0x44) & 0x100000) != 0) {
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
      *(byte *)(param_1 + 0x2d) = *(byte *)(param_1 + 0x2d) | 7;
      *(undefined1 *)(param_1 + 0x29) = 1;
    }
  }
  return;
}

/* FUN_00053a90 @ 0x53a90 (100 bytes) */
int FUN_00053a90(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 4);
  if (iVar4 != 0) {
    if (param_2 == *(int *)(*(int *)(param_1 + 0xc) + 8)) {
      return 0;
    }
    piVar3 = (int *)(*(int *)(param_1 + 0xc) + 0x84);
    iVar2 = 0;
    while( true ) {
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + -1;
      if (iVar4 == 0) break;
      iVar1 = *piVar3;
      piVar3 = piVar3 + 0x1f;
      if (param_2 == iVar1) {
        return iVar2;
      }
    }
  }
  return -1;
}

/* FUN_00053b00 @ 0x53b00 (84 bytes) */
int FUN_00053b00(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(((unsigned char *)0x0000116c) + param_1);
  iVar2 = ((int (*)())FUN_00053a90)(iVar3);
  iVar1 = 0;
  if (-1 < iVar2) {
    iVar1 = iVar2 * 0x7c + *(int *)(iVar3 + 0xc);
  }
  return iVar1;
}

/* FUN_00053b60 @ 0x53b60 (568 bytes) */
int FUN_00053b60(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  iVar6 = *(int *)(((unsigned char *)0x0000116c) + param_1);
  iVar2 = *(int *)(*(int *)(((unsigned char *)0x00001168) + param_1) + 0xc);
  if (iVar2 != 0) {
    *(int *)(*(int *)(((unsigned char *)0x00001168) + param_1) + 0xc) = iVar2 + -1;
  }
  if (((unsigned char *)0x00001170)[param_1] == '\0') {
    iVar2 = ((int (*)())FUN_00053a90)(iVar6);
    if (iVar2 < 0) {
      uVar1 = *(uint *)(iVar6 + 4);
      if ((uVar1 & 0xf) == 0) {
        iVar2 = (**(code **)(param_1 + 0xc))(uVar1 * 0x7c + 0x7c0);
        if (iVar2 == 0) {
          return;
        }
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (iVar2,*(undefined4 *)(iVar6 + 0xc),*(int *)(iVar6 + 4) * 0x7c);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar6 + 0xc));
        *(int *)(iVar6 + 0xc) = iVar2;
        FUN_00055d00(param_1);
        uVar1 = *(uint *)(iVar6 + 4);
      }
      FUN_00055b50(param_1,uVar1 * 0x7c + *(int *)(iVar6 + 0xc));
      *(undefined4 *)(*(int *)(iVar6 + 4) * 0x7c + *(int *)(iVar6 + 0xc) + 8) = param_2;
      *(undefined4 *)(((unsigned char *)0x00001188) + param_1) = *(undefined4 *)(iVar6 + 4);
      *(int *)(iVar6 + 4) = *(int *)(iVar6 + 4) + 1;
      *(undefined4 *)(((unsigned char *)0x00001184) + param_1) = 0;
      *(undefined4 *)(((unsigned char *)0x00001174) + param_1) = 0;
      *(undefined4 *)(((unsigned char *)0x0000117c) + param_1) = 0;
      *(undefined4 *)(((unsigned char *)0x00001178) + param_1) = 0;
      *(undefined4 *)(((unsigned char *)0x00001180) + param_1) = 0;
    }
    else {
      iVar3 = *(int *)(iVar6 + 0xc);
      *(int *)(((unsigned char *)0x00001188) + param_1) = iVar2;
      iVar3 = iVar2 * 0x7c + iVar3;
      *(undefined4 *)(((unsigned char *)0x00001174) + param_1) = *(undefined4 *)(iVar3 + 0x54);
      *(undefined4 *)(((unsigned char *)0x0000117c) + param_1) = *(undefined4 *)(iVar3 + 0x58);
      *(undefined4 *)(((unsigned char *)0x00001178) + param_1) = *(undefined4 *)(iVar3 + 0x5c);
      *(undefined4 *)(((unsigned char *)0x00001180) + param_1) = *(undefined4 *)(iVar3 + 0x60);
      *(undefined4 *)(((unsigned char *)0x00001184) + param_1) = *(undefined4 *)(iVar3 + 100);
    }
    iVar2 = *(int *)(((unsigned char *)0x00001188) + param_1) * 0x7c + *(int *)(iVar6 + 0xc);
    *(int *)(((unsigned char *)0x00001168) + param_1) = iVar2;
    *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;
    uVar1 = *(uint *)(param_1 + 0x44);
    if ((uVar1 & 0x800000) != 0) {
      uVar5 = *(uint *)(param_1 + 0x18a4);
      if ((uVar1 & 0x100000) == 0) {
        if ((((int)uVar1 < 0) &&
            (*(short *)("}J3x})+x|B;x}k" + *(int *)(*(int *)(param_1 + 4) + 0x10)) == -0x7e06)) ||
           (uVar4 = 0, (uVar1 & 0x80800000) == 0x800000)) {
          uVar4 = 1;
        }
      }
      else {
        uVar4 = *(char *)(*(int *)(((unsigned char *)0x00001168) + param_1) + 0x6e) == '\0' ^ 1;
      }
      *(uint *)(param_1 + 0x18a4) = uVar4 << 2 | uVar5 & 0xfffffffb;
      if ((uVar5 >> 2 & 1) != uVar4) {
        *(undefined1 *)(param_1 + 0x29) = 1;
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
      }
    }
  }
  return;
}

/* FUN_00053dc0 @ 0x53dc0 (20 bytes) */
int FUN_00053dc0(param_1, param_2)
  int param_1;
  int param_2;
{
  *(int *)(*(int *)(((unsigned char *)0x0000116c) + param_1) + 8) =
       *(int *)(*(int *)(((unsigned char *)0x0000116c) + param_1) + 8) + param_2;
  return;
}

/* FUN_00053de0 @ 0x53de0 (268 bytes) */
int FUN_00053de0(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar4 = *(int *)(((unsigned char *)0x0000116c) + param_1);
  if (*(int *)(*(int *)(((unsigned char *)0x00001168) + param_1) + 8) == param_2) {
    ((int (*)())FUN_00053b60)(param_1,0);
  }
  uVar5 = 0;
  iVar3 = 0;
  bVar1 = true;
  while (uVar5 < *(uint *)(iVar4 + 4)) {
    if (!bVar1) goto LAB_00053e6c;
    if (param_2 == *(int *)(iVar3 + *(int *)(iVar4 + 0xc) + 8)) {
      bVar1 = false;
    }
    else {
      uVar5 = uVar5 + 1;
      iVar3 = iVar3 + 0x7c;
    }
  }
  if (!bVar1) {
LAB_00053e6c:
    if (*(int *)(uVar5 * 0x7c + *(int *)(iVar4 + 0xc) + 0xc) == 0) {
      FUN_00055300(param_1);
      pvVar2 = (void *)(uVar5 * 0x7c + *(int *)(iVar4 + 0xc));
      _memmove(pvVar2,(void *)((int)pvVar2 + 0x7c),(*(int *)(iVar4 + 4) - uVar5) * 0x7c - 0x7c);
      *(int *)(iVar4 + 4) = *(int *)(iVar4 + 4) + -1;
      if (uVar5 < *(uint *)(((unsigned char *)0x00001188) + param_1)) {
        iVar3 = *(uint *)(((unsigned char *)0x00001188) + param_1) - 1;
        *(int *)(((unsigned char *)0x00001188) + param_1) = iVar3;
        *(int *)(((unsigned char *)0x00001168) + param_1) = iVar3 * 0x7c + *(int *)(iVar4 + 0xc);
      }
    }
  }
  return;
}

/* FUN_00053ef0 @ 0x53ef0 (12 bytes) */
int FUN_00053ef0(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  if (param_2 == 0) {
    return;
  }
  ((int (*)())FUN_00053de0)();
  return;
}

/* FUN_00053f00 @ 0x53f00 (124 bytes) */
int FUN_00053f00(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  if (((unsigned char *)0x00001170)[param_1] != '\0') {
    FUN_000553c0(param_1,*(undefined4 *)(((unsigned char *)0x00001168) + param_1),param_2,param_3,&DAT_001db9a8,
                 param_4,&DAT_001db998,0);
  }
  return;
}

/* FUN_00053f80 @ 0x53f80 (124 bytes) */
int FUN_00053f80(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  if (((unsigned char *)0x00001170)[param_1] != '\0') {
    FUN_000553c0(param_1,*(undefined4 *)(((unsigned char *)0x00001168) + param_1),param_2,param_3,&DAT_001db9a8,
                 param_4,&DAT_001db998,param_5);
  }
  return;
}

/* FUN_00054000 @ 0x54000 (128 bytes) */
int FUN_00054000(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  if (((unsigned char *)0x00001170)[param_1] != '\0') {
    FUN_000553c0(param_1,*(undefined4 *)(((unsigned char *)0x00001168) + param_1),param_2,param_3,&DAT_001db9a8,
                 param_4,&DAT_001db998,param_5);
  }
  return;
}

/* FUN_00054080 @ 0x54080 (276 bytes) */
int FUN_00054080(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
  uint param_5;
  uint param_6;
  uint param_7;
{
  int iVar1;
  int iVar2;
  int local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  
  if (((((((unsigned char *)0x00001170)[param_1] != '\0') && (param_4 - 0x87d5U < 0xb)) && (0x87d4 < param_5)) &&
      ((param_5 < 0x87e0 && (0x87d4 < param_6)))) &&
     ((param_6 < 0x87e0 && ((0x87d4 < param_7 && (param_7 < 0x87e0)))))) {
    iVar2 = *(int *)(((unsigned char *)0x00001168) + param_1);
    local_28 = param_4;
    local_24 = param_5;
    local_20 = param_6;
    local_1c = param_7;
    iVar1 = FUN_000553c0(param_1,iVar2,0x879a,param_2,&DAT_001db9a8,param_3,&local_28,0);
    if ((iVar1 != 0) && (param_2 - 0x879dU < 0x10)) {
      *(undefined1 *)((param_2 - 0x879dU) + iVar2 + 0x44) = 1;
    }
  }
  return;
}

/* FUN_000541a0 @ 0x541a0 (196 bytes) */
int FUN_000541a0(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  uint param_4;
  uint param_5;
  uint param_6;
  uint param_7;
{
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  
  if ((((((unsigned char *)0x00001170)[param_1] != '\0') && (param_4 < 2)) && (param_5 < 2)) &&
     ((param_6 < 2 && (param_7 < 2)))) {
    local_28 = param_4;
    local_24 = param_5;
    local_20 = param_6;
    local_1c = param_7;
    FUN_000553c0(param_1,*(undefined4 *)(((unsigned char *)0x00001168) + param_1),0x879b,param_2,&local_28,param_3,
                 &DAT_001db998,0);
  }
  return;
}

/* FUN_000543b0 @ 0x543b0 (164 bytes) */
int FUN_000543b0(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  uint param_4;
{
  int iVar1;
  int iVar2;
  
  if ((((unsigned char *)0x00001170)[param_1] != '\0') && (param_4 < 4)) {
    iVar2 = *(int *)(((unsigned char *)0x00001168) + param_1);
    iVar1 = FUN_000553c0(param_1,iVar2,0x879d,param_2,&DAT_001db9a8,param_3,&DAT_001db998,0);
    if (iVar1 != 0) {
      *(uint *)(*(int *)(iVar2 + 0x14) * 0x74 + *(int *)(iVar2 + 0x18) + -0x34) = param_4;
    }
  }
  return;
}

/* FUN_00054460 @ 0x54460 (8 bytes) */
int FUN_00054460()
{
  ((int (*)())FUN_00053340)();
  return;
}

/* FUN_00054470 @ 0x54470 (272 bytes) */
int FUN_00054470(param_1, param_2, param_3, param_4)
  int param_1;
  int *param_2;
  int *param_3;
  int *param_4;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if (*(char *)(param_1 + 0x1868) == '\0') {
    piVar2 = *(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + **(int **)(((unsigned char *)0x00001168) + param_1));
    iVar3 = *piVar2;
    *param_3 = piVar2[0x22];
    *param_4 = *(int *)(param_1 + 0x2448) + *(int *)(iVar3 + 0x14);
    iVar1 = *(int *)(iVar3 + 0x2b8);
    if (iVar1 == 0) {
      iVar1 = (**(code **)(param_1 + 0xc))(0x80c);
      *(int *)(iVar3 + 0x2b8) = iVar1;
      *param_2 = iVar1;
      return 1;
    }
  }
  else {
    piVar2 = (int *)**(undefined4 **)
                      (*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + **(int **)(((unsigned char *)0x00001168) + param_1));
    *param_3 = piVar2[0x49];
    *param_4 = *(int *)(param_1 + 0x2448) + *piVar2;
    iVar1 = piVar2[0x4f6];
    if (iVar1 == 0) {
      iVar1 = (**(code **)(param_1 + 0xc))(0x80c);
      piVar2[0x4f6] = iVar1;
      *param_2 = iVar1;
      return 1;
    }
  }
  *param_2 = iVar1;
  return 0;
}

/* FUN_00054590 @ 0x54590 (288 bytes) */
int FUN_00054590(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 *param_2;
  int param_3;
  int *param_4;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar1 = *(int *)(((unsigned char *)0x00001168) + param_1);
  if (param_3 == 0) {
    iVar9 = 0;
    iVar8 = 0;
    iVar7 = 0;
  }
  else {
    iVar4 = 0;
    iVar5 = 0;
    iVar7 = 0;
    iVar9 = 0;
    iVar8 = 0;
    puVar6 = param_2;
    do {
      iVar2 = *param_4;
      param_4 = param_4 + 1;
      iVar2 = *(int *)(iVar2 * 4 + *(int *)(iVar1 + 0x24)) * 0x54 + *(int *)(iVar1 + 0x20);
      if (*(char *)(iVar2 + 0x3d) == '\0') {
        if (iVar5 < (int)param_2[0x200]) {
          iVar9 = iVar9 + 1;
        }
        else if (iVar5 < (int)param_2[0x201]) {
          iVar7 = iVar7 + 1;
        }
        else {
          iVar8 = iVar8 + 1;
        }
      }
      else {
        uVar3 = puVar6[1];
        param_2[iVar4 * 2] = *puVar6;
        param_2[iVar4 * 2 + 1] = uVar3;
        *(char *)(param_2 + iVar4 * 2) = (char)*(undefined4 *)(iVar2 + 4);
        param_2[iVar4 * 2 + 1] = *(undefined4 *)(iVar2 + 0x38);
        iVar4 = iVar4 + 1;
      }
      iVar5 = iVar5 + 1;
      puVar6 = puVar6 + 2;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
    iVar7 = iVar7 + iVar9;
  }
  param_2[0x200] = param_2[0x200] - iVar9;
  param_2[0x201] = param_2[0x201] - iVar7;
  param_2[0x202] = param_2[0x202] - (iVar8 + iVar7);
  return;
}

/* FUN_000546d0 @ 0x546d0 (284 bytes) */
int FUN_000546d0(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  (**(code **)(((unsigned char *)0x000011ac) + param_1))(param_1,param_2,0);
  (**(code **)(((unsigned char *)0x000011a4) + param_1))(param_1,param_2,*(undefined4 *)(((unsigned char *)0x0000118c) + param_1));
  *(undefined4 *)(param_2 + 100) = 0;
  *(undefined4 *)(param_2 + 0x54) = 0;
  *(undefined4 *)(param_2 + 0x58) = 0;
  *(undefined4 *)(param_2 + 0x5c) = 0;
  *(undefined4 *)(param_2 + 0x60) = 0;
  if (*(int *)(param_2 + 0x1c) != 0) {
    uVar3 = 0;
    iVar2 = 0;
    do {
      uVar3 = uVar3 + 1;
      iVar1 = iVar2 + *(int *)(param_2 + 0x20);
      iVar2 = iVar2 + 0x54;
      *(undefined1 *)(iVar1 + 0x3d) = 0;
    } while (uVar3 < *(uint *)(param_2 + 0x1c));
  }
  (**(code **)(((unsigned char *)0x00001194) + param_1))(param_1,param_2);
  (**(code **)(((unsigned char *)0x0000119c) + param_1))(param_1,param_2);
  *(undefined4 *)(((unsigned char *)0x00001174) + param_1) = *(undefined4 *)(param_2 + 0x54);
  *(undefined4 *)(((unsigned char *)0x0000117c) + param_1) = *(undefined4 *)(param_2 + 0x58);
  *(undefined4 *)(((unsigned char *)0x00001178) + param_1) = *(undefined4 *)(param_2 + 0x5c);
  *(undefined4 *)(((unsigned char *)0x00001180) + param_1) = *(undefined4 *)(param_2 + 0x60);
  *(undefined4 *)(((unsigned char *)0x00001184) + param_1) = *(undefined4 *)(param_2 + 100);
  return;
}

/* FUN_000547f0 @ 0x547f0 (324 bytes) */
int FUN_000547f0(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int param_3;
  undefined4 *param_4;
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  if (param_3 - 0x1400U < 0xb) {
    iVar3 = *(int *)(((unsigned char *)0x00001168) + param_1);
    if ((*(char *)(param_1 + 0x31) != '\0') &&
       (*(char *)(*(int *)(iVar3 + 4) + *(int *)(((unsigned char *)0x0000118c) + param_1)) != '\0')) {
      ((int (*)())FUN_000546d0)(param_1,iVar3);
    }
    iVar2 = FUN_00055a30(iVar3 + 0x1c,param_2);
    if (((iVar2 != 0) && (*(int *)(iVar2 + 0x28) == 0x87c3)) && (*(char *)(iVar2 + 0x44) == '\0')) {
      puVar1 = *(undefined4 **)(iVar2 + 0x38);
      *puVar1 = *param_4;
      puVar1[1] = param_4[1];
      puVar1[2] = param_4[2];
      puVar1[3] = param_4[3];
      *(undefined1 *)(iVar2 + 0x44) = 1;
      iVar2 = FUN_00055a30(iVar3 + 0x1c,param_2);
      if ((iVar2 != 0) && (*(char *)(iVar2 + 0x3d) != '\0')) {
        (**(code **)(*(int *)(iVar2 + 0x24) * 4 + param_1 + -0x20bac))(param_1,iVar3,iVar2);
      }
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
      *(byte *)(param_1 + 0x2d) = *(byte *)(param_1 + 0x2d) | 1;
      *(undefined1 *)(param_1 + 0x29) = 1;
    }
  }
  return;
}

/* FUN_00054940 @ 0x54940 (56 bytes) */
int FUN_00054940(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  
  if (param_2 == 0x87e2) {
    uVar1 = ((int (*)())FUN_00053220)(param_1,0,0,0x87bf,0x87c1,0);
    return uVar1;
  }
  return 0;
}

/* FUN_00054980 @ 0x54980 (260 bytes) */
int FUN_00054980(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  iVar4 = *(int *)(((unsigned char *)0x0000116c) + param_1);
  if (*(int *)(iVar4 + 4) != 0) {
    uVar5 = 0;
    iVar6 = 0;
    do {
      uVar5 = uVar5 + 1;
      iVar3 = iVar6 + *(int *)(iVar4 + 0xc);
      iVar6 = iVar6 + 0x7c;
      FUN_00055300(param_1,iVar3);
    } while (uVar5 < *(uint *)(iVar4 + 4));
  }
  iVar3 = 0;
  (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar4 + 0xc));
  *(undefined4 *)(iVar4 + 4) = 0;
  FUN_000551f0(param_1,iVar4 + 0x14);
  iVar6 = iVar4;
  do {
    iVar2 = *(int *)(iVar6 + 0x28);
    while (iVar2 != 0) {
      *(int *)(iVar6 + 0x28) = *(int *)(iVar2 + 0xc);
      (**(code **)(param_1 + 0x18))();
      iVar2 = *(int *)(iVar6 + 0x28);
    }
    bVar1 = iVar3 != 0x1f;
    iVar6 = iVar6 + 4;
    iVar3 = iVar3 + 1;
  } while (bVar1);
  (**(code **)(param_1 + 0x18))(iVar4);
  *(undefined4 *)(((unsigned char *)0x0000116c) + param_1) = 0;
  return;
}

/* FUN_00054a90 @ 0x54a90 (120 bytes) */
int FUN_00054a90(param_1)
  int param_1;
{
  (**(code **)(((unsigned char *)0x000011a8) + param_1))();
  **(int **)(((unsigned char *)0x0000116c) + param_1) = **(int **)(((unsigned char *)0x0000116c) + param_1) + -1;
  if (**(int **)(((unsigned char *)0x0000116c) + param_1) == 0) {
    ((int (*)())FUN_00054980)(param_1);
    return;
  }
  return;
}

/* FUN_00054b20 @ 0x54b20 (240 bytes) */
int FUN_00054b20(param_1)
  int param_1;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = *(undefined4 **)(((unsigned char *)0x0000116c) + param_1);
  uVar1 = (**(code **)(param_1 + 0xc))(0x7c0);
  puVar2[9] = 0;
  puVar2[3] = uVar1;
  *puVar2 = 1;
  puVar2[1] = 1;
  puVar2[2] = 1;
  puVar2[4] = 1;
  FUN_00055b50(param_1,uVar1);
  *(undefined4 *)(puVar2[3] + 8) = 0;
  ((unsigned char *)0x00001170)[param_1] = 0;
  *(undefined4 *)(((unsigned char *)0x000011b4) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x00001188) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x00001174) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x0000117c) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x00001178) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x00001180) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x00001184) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x0000118c) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x00001168) + param_1) = puVar2[3];
  (**(code **)(((unsigned char *)0x000011a0) + param_1))(param_1);
  puVar2[9] = 0;
  FUN_00055a60(param_1,puVar2 + 5);
  iVar3 = 0x20;
  do {
    puVar2[10] = 0;
    puVar2 = puVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

