#include "decls.h"

/* FUN_0001e5bd @ 0x1e5bd (534 bytes) */
int FUN_0001e5bd(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
  int param_7;
  undefined4 param_8;
  int param_9;
{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  uVar1 = *(uint *)(param_1 + 0x154);
  *(undefined1 *)(param_1 + 0x2a5e) = 1;
  puVar5 = *(undefined4 **)(param_1 + 0x1dc);
  if (*(undefined4 **)(param_1 + 0x1e0) <= puVar5 + 0x10) {
    FUN_00017c77(param_1,0x1000000);
    puVar5 = *(undefined4 **)(param_1 + 0x1dc);
  }
  *(undefined4 **)(param_1 + 0x1dc) = puVar5 + 0x10;
  *puVar5 = 0xd07;
  iVar2 = *(int *)(param_1 + 0x10);
  if (*(short *)(iVar2 + 0x2dba) == 0) {
    uVar4 = 0;
  }
  else if ((*(uint *)(param_1 + 0x154) & 0xf) == 3) {
    uVar4 = ~-(uint)(*(char *)(iVar2 + 0x2e42) == '\0') & 0x1f |
            ~-(uint)(*(char *)(iVar2 + 0x2e41) == '\0') & 0x3e0 |
            ~-(uint)(*(char *)(iVar2 + 0x2e43) == '\0') & 0x8000 |
            ~-(uint)(*(char *)(iVar2 + 0x2e40) == '\0') & 0x7c00;
    uVar4 = uVar4 << 0x10 | uVar4;
  }
  else {
    uVar4 = ~-(uint)(*(char *)(iVar2 + 0x2e42) == '\0') & 0xff |
            ~-(uint)(*(char *)(iVar2 + 0x2e41) == '\0') & 0xff00 |
            ~-(uint)(*(char *)(iVar2 + 0x2e43) == '\0') & 0xff000000 |
            ~-(uint)(*(char *)(iVar2 + 0x2e40) == '\0') & 0xff0000;
  }
  puVar5[1] = uVar4;
  puVar5[2] = 0xc0089b00;
  puVar5[3] = ((uint)((uVar1 & 0xf) != 3) * 3 + 3) * 0x100 | (uint)param_9 << 0x10 | 0x20030ff;
  puVar3 = *(uint **)(param_1 + 0x1d8);
  *puVar3 = *puVar3 | (int)(puVar5 + 4) - (int)puVar3 >> 2;
  *(undefined4 **)(param_1 + 0x1d8) = puVar5 + 4;
  puVar5[4] = 0x2a000000;
  puVar5[5] = param_8;
  puVar5[6] = 0;
  puVar5[7] = 0;
  puVar5[8] = 0;
  puVar5[9] = param_2 << 0x10 | (uint)param_3;
  puVar5[10] = param_6 << 0x10 | (uint)param_7;
  puVar5[0xb] = param_4 << 0x10 | (uint)param_5;
  puVar5[0xc] = 0xd0b;
  puVar5[0xd] = 5;
  puVar5[0xe] = 0x5c8;
  puVar5[0xf] = 0x10000;
  return;
}

/* FUN_0001e7d3 @ 0x1e7d3 (4176 bytes) */
int FUN_0001e7d3(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
  int param_7;
  undefined4 param_8;
{
  ushort uVar1;
  ushort uVar2;
  uint *puVar3;
  undefined *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  int iVar12;
  uint uVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  uint local_b4;
  uint local_a8;
  uint local_a4;
  byte local_9f;
  byte local_9e;
  byte local_9d;
  ushort local_9c;
  ushort local_8c;
  float local_74;
  float local_5c;
  float local_58;
  float local_54;
  uint local_50;
  uint local_3c;
  uint local_38;
  uint local_34;
  int local_30;
  float local_28;
  float local_24;
  float local_20;
  
  fVar20 = (float)param_6;
  fVar21 = (float)param_7;
  fVar14 = (float)(param_6 + param_4);
  fVar17 = (float)(param_7 + param_5);
  fVar18 = (float)(param_2 - param_6);
  fVar15 = (float)(param_3 - param_7);
  uVar1 = *(ushort *)(param_1 + 0x11c);
  uVar2 = *(ushort *)(param_1 + 0x120);
  if ((uVar1 < 0x1001) && (uVar2 < 0x1001)) {
    local_9f = 0;
    local_9e = 0;
    local_9d = 0;
    local_9c = 0;
    local_8c = 0;
    local_20 = 0.0;
    local_74 = 0.0;
    local_28 = 0.0;
    local_24 = 0.0;
    iVar12 = 0xc;
    uVar5 = 0;
    goto LAB_0001ea25;
  }
  local_24 = fVar18 + fVar20;
  fVar19 = fVar14 + fVar18;
  fVar16 = fVar15 + fVar21;
  local_20 = fVar17 + fVar15;
  if (local_20 < fVar16) {
    local_28 = fVar16;
    if (local_24 <= fVar19) goto LAB_0001e8d2;
LAB_0001f320:
    uVar5 = (uint)(uVar1 >> 9) << 9;
    iVar12 = (int)fVar19;
    uVar9 = iVar12 - 1;
    local_74 = fVar19;
    if (-1 < (int)uVar9) goto LAB_0001e8f0;
LAB_0001f352:
    uVar9 = iVar12 + 0x1feU & 0xfffffe00;
    if (-1 < (int)uVar9) goto LAB_0001e8fe;
LAB_0001f366:
    local_9c = 0;
  }
  else {
    local_28 = local_20;
    local_20 = fVar16;
    if (fVar19 < local_24) goto LAB_0001f320;
LAB_0001e8d2:
    uVar5 = (uint)(uVar1 >> 9) << 9;
    iVar12 = (int)local_24;
    uVar9 = iVar12 - 1;
    local_74 = local_24;
    local_24 = fVar19;
    if ((int)uVar9 < 0) goto LAB_0001f352;
LAB_0001e8f0:
    uVar9 = uVar9 & 0xfffffe00;
    if ((int)uVar9 < 0) goto LAB_0001f366;
LAB_0001e8fe:
    if ((int)uVar9 <= (int)uVar5) {
      uVar5 = uVar9;
    }
    local_9c = (ushort)uVar5;
  }
  if (uVar2 < 0x41) {
    uVar5 = 0x40;
    uVar9 = (int)local_20 - 1;
    if ((int)uVar9 < 0) goto LAB_0001f2d7;
LAB_0001e931:
    uVar9 = uVar9 & 0xffffffc0;
    if ((int)uVar9 < 0) goto LAB_0001f2e5;
LAB_0001e93c:
    if ((int)uVar9 <= (int)uVar5) {
      uVar5 = uVar9;
    }
    local_8c = (ushort)uVar5;
    if (0x1ff < local_9c) goto LAB_0001f2fd;
LAB_0001e957:
    uVar5 = 0x200;
  }
  else {
    uVar5 = (uint)(uVar2 >> 6) * 0x40;
    if ((int)((uint)uVar2 + (uint)(uVar2 >> 6) * -0x40) < 0x40) {
      uVar5 = uVar5 - 0x40;
    }
    uVar9 = (int)local_20 - 1;
    if (-1 < (int)uVar9) goto LAB_0001e931;
LAB_0001f2d7:
    uVar9 = (int)local_20 + 0x3eU & 0xffffffc0;
    if (-1 < (int)uVar9) goto LAB_0001e93c;
LAB_0001f2e5:
    local_8c = 0;
    if (local_9c < 0x200) goto LAB_0001e957;
LAB_0001f2fd:
    uVar5 = (uint)local_9c;
  }
  uVar9 = uVar1 - 1;
  if ((int)uVar9 < 0) {
    uVar9 = uVar1 + 0x1fe;
  }
  local_38 = (uint)uVar2;
  uVar10 = (uint)local_24;
  if ((0.0 < local_24) && ((float)(int)uVar10 < local_24)) {
    uVar10 = uVar10 + 1;
  }
  uVar8 = uVar9 & 0xfffffe00;
  if ((int)uVar10 <= (int)(uVar9 & 0xfffffe00)) {
    uVar8 = uVar10;
  }
  if ((int)uVar5 < (int)uVar8) {
    local_9e = (byte)((int)((uVar8 - uVar5) + 0xbff) / 0xc00);
  }
  else {
    local_9e = 1;
  }
  if (local_8c < 0x40) {
    uVar5 = 0x40;
  }
  else {
    uVar5 = (uint)local_8c;
  }
  uVar9 = local_38 - 1;
  if ((int)uVar9 < 0) {
    uVar9 = local_38 + 0x3e;
  }
  uVar10 = (uint)local_28;
  if ((0.0 < local_28) && ((float)(int)uVar10 < local_28)) {
    uVar10 = uVar10 + 1;
  }
  uVar8 = uVar9 & 0xffffffc0;
  if ((int)uVar10 <= (int)(uVar9 & 0xffffffc0)) {
    uVar8 = uVar10;
  }
  if ((int)uVar5 < (int)uVar8) {
    local_9d = (byte)((int)((uVar8 - uVar5) + 0xf7f) / 0xf80);
  }
  else {
    local_9d = 1;
  }
  local_9f = local_9e * local_9d;
  uVar5 = (uint)local_9f;
  iVar12 = uVar5 << 4;
LAB_0001ea25:
  local_38 = (uint)uVar2;
  local_50 = (uint)uVar1;
  *(undefined1 *)(param_1 + 0x2a5e) = 1;
  iVar6 = iVar12 + 0x56f;
  if (*(char *)(param_1 + 0x2a42) == '\0') {
    iVar6 = iVar12 + 0x571;
  }
  puVar7 = (undefined4 *)(**(code **)(param_1 + 0x2998))(param_1 + 0x240,iVar6);
  *(undefined4 **)(param_1 + 0x298c) = puVar7;
  if (*(char *)(param_1 + 0x2a42) == '\0') {
    *puVar7 = 0x5c8;
    puVar7[1] = 0x10000000;
    puVar7 = puVar7 + 2;
    *(undefined1 *)(param_1 + 0x2a42) = 1;
  }
  puVar11 = *(uint **)(param_1 + 0x1d8);
  *puVar11 = *puVar11 | (int)puVar7 - (int)puVar11 >> 2;
  *(undefined4 **)(param_1 + 0x1d8) = puVar7;
  *puVar7 = 0x31000000;
  puVar7[1] = 1000;
  puVar7[2] = param_8;
  puVar7[3] = uVar5;
  puVar7[4] = CONCAT22(uVar2,uVar1);
  _memcpy(puVar7 + 1000,PTR_DAT_002131cd,0x2f4);
  puVar11 = puVar7 + 0x4a5;
  puVar7[0x496] = ((*(uint *)(param_1 + 0x154) & 0x30000) != 0x30000) + 0xe;
  if (local_9f == 0) {
    fVar16 = 0.0;
    if (uVar1 != 0) {
      fVar16 = FLOAT_001c5ba4 / (float)local_50;
    }
    fVar19 = 0.0;
    if (uVar2 != 0) {
      fVar19 = FLOAT_001c5ba4 / (float)local_38;
    }
    *puVar11 = 0x31080;
    puVar7[0x4a6] = (fVar18 + fVar20) * fVar16;
    puVar7[0x4a7] = (fVar17 + fVar15) * fVar19;
    puVar7[0x4a8] = fVar16 * (fVar14 + fVar18);
    puVar7[0x4a9] = fVar19 * (fVar15 + fVar21);
    puVar7[0x4aa] = 0x1087;
    puVar7[0x4ab] =
         (int)((fVar14 - fVar20) * FLOAT_001c5bf4) << 0x10 |
         (int)((fVar17 - fVar21) * FLOAT_001c5bf4);
    puVar7[0x4ac] = 0xc0033500;
    puVar7[0x4ad] = ((unsigned char *)0x00010031);
    fVar15 = FLOAT_001c5bd4;
    puVar7[0x4ae] = (fVar20 + fVar14) * FLOAT_001c5bd4;
    puVar7[0x4af] = (fVar21 + fVar17) * fVar15;
    puVar7[0x4b0] = 0;
    puVar11 = puVar7 + 0x4b1;
  }
  else {
    fVar18 = (float)((uint)fVar18 ^ DAT_001c5fb0);
    fVar15 = (float)((uint)fVar15 ^ DAT_001c5fb0);
    uVar5 = (uint)local_9d;
    if (uVar5 != 0) {
      uVar10 = (uint)local_9e;
      uVar9 = (uint)local_8c;
      local_3c = local_38 - uVar9;
      local_b4 = 0;
      local_30 = 0;
      do {
        if (uVar10 != 0) {
          uVar8 = (uint)local_9c;
          iVar12 = local_30 + uVar9;
          local_34 = local_50 - uVar8;
          uVar13 = 0;
          do {
            *puVar11 = uVar8;
            puVar11[1] = local_30 + uVar9;
            if ((int)local_50 < (int)(uVar8 + 0x1000)) {
              local_a8 = local_34;
              if (iVar12 + 0x1000 <= (int)local_38) goto LAB_0001f4d3;
LAB_0001f72b:
              puVar11[2] = local_a8;
              puVar11[3] = local_3c;
              local_a4 = local_3c;
            }
            else {
              local_a8 = 0x1000;
              if ((int)local_38 < iVar12 + 0x1000) goto LAB_0001f72b;
LAB_0001f4d3:
              local_a4 = 0x1000;
              puVar11[2] = local_a8;
              puVar11[3] = 0x1000;
            }
            fVar14 = local_74;
            if (uVar13 != 0) {
              fVar14 = (float)(int)(uVar8 + 0x200);
            }
            fVar17 = local_20;
            if (local_b4 != 0) {
              fVar17 = (float)(iVar12 + 0x40);
            }
            fVar20 = local_24;
            if (uVar13 != uVar10 - 1) {
              fVar20 = (float)(int)(uVar8 + 0xe00);
            }
            fVar21 = local_28;
            if (local_b4 != uVar5 - 1) {
              fVar21 = (float)(iVar12 + 0xfc0);
            }
            fVar16 = local_74;
            if (local_74 <= fVar14) {
              fVar16 = fVar14;
            }
            local_5c = local_20;
            if (local_20 <= fVar17) {
              local_5c = fVar17;
            }
            fVar14 = local_24;
            if (fVar20 <= local_24) {
              fVar14 = fVar20;
            }
            fVar17 = local_28;
            if (fVar21 <= local_28) {
              fVar17 = fVar21;
            }
            local_54 = fVar18 + fVar16;
            fVar19 = fVar18 + fVar14;
            local_58 = local_5c + fVar15;
            fVar22 = fVar15 + fVar17;
            fVar21 = fVar22;
            fVar20 = fVar17;
            if (fVar22 < local_58) {
              fVar21 = local_58;
              fVar20 = local_5c;
              local_5c = fVar17;
              local_58 = fVar22;
            }
            fVar17 = fVar19;
            fVar22 = fVar14;
            if (fVar19 < local_54) {
              fVar17 = local_54;
              fVar22 = fVar16;
              fVar16 = fVar14;
              local_54 = fVar19;
            }
            fVar14 = 0.0;
            if (local_a8 != 0) {
              fVar14 = FLOAT_001c5ba4 / (float)(int)local_a8;
            }
            fVar19 = 0.0;
            if (local_a4 != 0) {
              fVar19 = FLOAT_001c5ba4 / (float)(int)local_a4;
            }
            puVar11[4] = 0x31080;
            puVar11[5] = (uint)((fVar16 - (float)(int)uVar8) * fVar14);
            puVar11[6] = (uint)((fVar20 - (float)iVar12) * fVar19);
            puVar11[7] = (uint)(fVar14 * (fVar22 - (float)(int)uVar8));
            puVar11[8] = (uint)(fVar19 * (local_5c - (float)iVar12));
            puVar11[9] = 0x1087;
            puVar11[10] = (int)((fVar17 - local_54) * FLOAT_001c5bf4) << 0x10 |
                          (int)((fVar21 - local_58) * FLOAT_001c5bf4);
            puVar11[0xb] = 0xc0033500;
            puVar11[0xc] = (uint)((unsigned char *)0x00010031);
            puVar11[0xd] = (uint)((fVar17 + local_54) * FLOAT_001c5bd4);
            puVar11[0xe] = (uint)((fVar21 + local_58) * FLOAT_001c5bd4);
            puVar11[0xf] = 0;
            puVar11 = puVar11 + 0x10;
            uVar13 = uVar13 + 1;
            uVar8 = uVar8 + 0xc00;
            local_34 = local_34 - 0xc00;
          } while (uVar10 != uVar13);
        }
        local_b4 = local_b4 + 1;
        local_30 = local_30 + 0xf80;
        local_3c = local_3c - 0xf80;
      } while (local_b4 != uVar5);
    }
  }
  puVar3 = *(uint **)(param_1 + 0x1d8);
  *puVar3 = *puVar3 | (int)puVar11 - (int)puVar3 >> 2;
  *(uint **)(param_1 + 0x1d8) = puVar11;
  *puVar11 = 0x33000000;
  puVar11[1] = 2;
  puVar11[2] = 0x1393;
  puVar11[3] = 10;
  puVar11[4] = 0x13c6;
  puVar11[5] = 3;
  puVar11[6] = 0x5c8;
  puVar11[7] = 0x20000;
  puVar11[8] = 0x10ea;
  puVar11[9] = *(uint *)(param_1 + 0x1cfc);
  puVar11[10] = 0x10fa;
  puVar11[0xb] = *(uint *)(param_1 + 0x1da0);
  puVar11[0xc] = 0xc0001000;
  puVar11[0xe] = 0x11004;
  puVar11[0xf] = *(uint *)(param_1 + 0x1ca8);
  puVar11[0x10] = *(uint *)(param_1 + 0x1cac);
  puVar11[0x11] = 0x1008;
  puVar11[0x12] = *(uint *)(param_1 + 0x1ca0);
  puVar11[0x13] = 0x10e9;
  puVar11[0x14] = *(uint *)(param_1 + 0x1d20);
  puVar11[0x15] = 0x13c7;
  puVar11[0x16] = *(uint *)(param_1 + 0x1cf0);
  puVar11[0x17] = 0x13c1;
  puVar11[0x18] = *(uint *)(param_1 + 0x1ce4);
  puVar11[0x19] = 0x850;
  puVar11[0x1a] = *(uint *)(param_1 + 0x1dc0);
  puVar11[0x1b] = 0x887;
  puVar11[0x1c] = *(uint *)(param_1 + 0x1db4);
  puVar11[0xbd] = 0x82c;
  puVar11[0xbe] = *(uint *)(param_1 + 0x1dc4);
  puVar11[0x1d] = 0x10ae;
  puVar11[0x1e] = *(uint *)(param_1 + 0x1d70);
  puVar11[0x1f] = 0x1394;
  puVar11[0x20] = *(uint *)(param_1 + 0x1d30);
  puVar11[0x21] = 0x1380;
  puVar11[0x22] = 0;
  puVar11[0x23] = 0x1002;
  puVar11[0x24] = *(uint *)(param_1 + 0x1d90);
  puVar11[0x24] = *(uint *)(param_1 + 0x1d90);
  puVar11[0x25] = 0x824;
  puVar11[0x26] = *(uint *)(param_1 + 0x1ddc);
  puVar11[0x27] = 0x825;
  puVar11[0x28] = *(uint *)(param_1 + 0x1de0);
  puVar11[0x29] = 0x82d;
  puVar11[0x2a] = *(uint *)(param_1 + 0x26cc);
  puVar11[0x2b] = 0x854;
  puVar11[0x2c] = **(uint **)(param_1 + 0x2680);
  puVar11[0x2d] = 0x878;
  puVar11[0x2e] = **(uint **)(param_1 + 0x2684);
  puVar11[0x2f] = (uint)&switchdataD_000013c0;
  puVar11[0x30] = *(uint *)(param_1 + 0x1ce0);
  puVar11[0x31] = 0x12f0;
  puVar11[0x32] = *(uint *)(param_1 + 0x1d2c);
  puVar4 = PTR_DAT_002131c9;
  if ((PTR_DAT_002131c9[(uint)*(byte *)(param_1 + 0x2b7f) * 0x24 + 0x1a] & 1) == 0) {
    *(byte *)(puVar11 + 0x32) = (byte)puVar11[0x32] & 0xfe;
  }
  puVar11[0x33] = 0x12f5;
  puVar11[0x34] = *(uint *)(param_1 + 0x1c8c);
  if ((puVar4[(uint)*(byte *)(param_1 + 0x2b7f) * 0x24 + 0x1a] & 1) == 0) {
    *(byte *)((int)puVar11 + 0xd1) = *(byte *)((int)puVar11 + 0xd1) & 0xf7;
  }
  puVar11[0x35] = 0x10a2;
  puVar11[0x36] = *(uint *)(param_1 + 0x1d7c);
  puVar11[0x37] = 0x1381;
  puVar11[0x38] = *(uint *)(param_1 + 0x1cc0);
  if ((puVar4[(uint)*(byte *)(param_1 + 0x2b7f) * 0x24 + 0x1a] & 2) == 0) {
    *(byte *)(puVar11 + 0x38) = (byte)puVar11[0x38] & 0xfc;
  }
  puVar11[0x39] = 0x109e;
  puVar11[0x3a] = *(uint *)(param_1 + 0x1d6c);
  puVar11[0x3b] = 0x1096;
  puVar11[0x3a] = *(uint *)(param_1 + 0x1df8);
  puVar11[0x3d] = 0x1041;
  puVar11[0x3e] = *(uint *)(param_1 + 0x29f0);
  puVar11[0x3f] = 0x1046;
  puVar11[0x40] = *(uint *)(param_1 + 0x1dfc);
  puVar11[0x41] = 0x1094;
  puVar11[0x42] = 0;
  puVar11[0x43] = 0x1095;
  puVar11[0x45] = 0x1095;
  puVar11[0x47] = 0x1095;
  puVar11[0x49] = 0x1095;
  puVar11[0x4b] = 0x1095;
  puVar11[0x4d] = 0x1095;
  puVar11[0x4f] = 0x1095;
  puVar11[0x51] = 0x1095;
  puVar11[0x53] = 0x1095;
  puVar11[0x55] = 0x1095;
  puVar11[0x57] = 0x1095;
  puVar11[0x59] = 0x1095;
  puVar11[0x5b] = 0xc0221000;
  puVar11[0x7f] = 0x1180;
  puVar11[0x80] = 2;
  puVar11[0x81] = 0x1189;
  puVar11[0x83] = 0x1181;
  puVar11[0x85] = 0x118d;
  puVar11[0x87] = 0x118e;
  puVar11[0x89] = 0x118c;
  puVar11[0x8b] = 0x11a9;
  puVar11[0x8c] = *(uint *)(param_1 + 0x257c);
  puVar11[0x8d] = 0x11aa;
  puVar11[0x8e] = *(uint *)(param_1 + 0x2580);
  puVar11[0x8f] = 0x11ab;
  puVar11[0x90] = *(uint *)(param_1 + 0x2584);
  puVar11[0x91] = 0x11ac;
  puVar11[0x92] = *(uint *)(param_1 + 0x2588);
  puVar11[0x93] = 0x10c0;
  puVar11[0x94] = *(uint *)(param_1 + 0x216c);
  puVar11[0x95] = 0x10c1;
  puVar11[0x97] = 0x10c8;
  puVar11[0x99] = 0x101d;
  puVar11[0x9a] = *(uint *)(param_1 + 0x2128);
  puVar11[0x9b] = 0x138a;
  puVar11[0x9c] = 0;
  puVar11[0x9d] = 0x138e;
  puVar11[0x9e] = 0;
  puVar11[0x9f] = 0x1040;
  puVar11[0xa0] = 0;
  puVar11[0xa1] = 0x1150;
  puVar11[0xa2] = 0;
  puVar11[0xa3] = 0x1100;
  puVar11[0xa4] = *(uint *)(param_1 + 0x1f1c);
  puVar11[0xa5] = 0x1110;
  puVar11[0xa6] = *(uint *)(param_1 + 0x1f5c);
  puVar11[0xa7] = 0x1120;
  puVar11[0xa8] = *(uint *)(param_1 + 0x1f9c);
  puVar11[0xa9] = 0x1130;
  puVar11[0xaa] = *(uint *)(param_1 + 0x1fdc);
  puVar11[0xab] = 0x1140;
  puVar11[0xac] = *(uint *)(param_1 + 0x201c);
  puVar11[0xad] = 0x10f4;
  puVar11[0xae] = 0xaaaa;
  puVar11[0xaf] = 0x1383;
  puVar11[0xb0] = *(uint *)(param_1 + 0x1d34);
  puVar11[0xb1] = 0x1386;
  puVar11[0xb2] = *(uint *)(param_1 + 0x1d38);
  puVar11[0xb3] = 0x110f8;
  puVar11[0xb4] = *(uint *)(param_1 + 0x1d98);
  puVar11[0xb5] = *(uint *)(param_1 + 0x1d50);
  puVar11[0xb6] = 0x1087;
  puVar11[0xb7] = *(uint *)(param_1 + 0x1f0c);
  puVar11[0xb8] = 0x31080;
  puVar11[0xb9] = *(uint *)(param_1 + 0x1efc);
  puVar11[0xba] = *(uint *)(param_1 + 0x1f04);
  puVar11[0xbb] = *(uint *)(param_1 + 0x1f00);
  puVar11[0xbc] = *(uint *)(param_1 + 0x1f08);
  FUN_0004acbc(puVar11 + 2,param_1 + 0x240);
  puVar11[0xbf] = (uint)&UINT_000013c4;
  puVar11[0xc1] = 0x113c8;
  puVar11[0xc4] = 0x13cd;
  puVar11[0xc6] = (uint)&UINT_000013cc;
  puVar11[200] = 0x13ca;
  *(uint **)(param_1 + 0x298c) = puVar11 + 0xca;
                    
                    
  (**(code **)(param_1 + 0x299c))();
  return;
}

/* FUN_0001f823 @ 0x1f823 (1788 bytes) */
int FUN_0001f823(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
{
  int iVar1;
  uint *puVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  int iVar5;
  
  iVar1 = param_1 + 0x240;
  *(undefined1 *)(param_1 + 0x2a5e) = 1;
  puVar4 = (undefined4 *)(**(code **)(param_1 + 0x2998))(iVar1,0x406);
  *(undefined4 **)(param_1 + 0x298c) = puVar4;
  if (*(char *)(param_1 + 0x2a42) == '\0') {
    *puVar4 = 0x5c8;
    puVar4[1] = 0x10000000;
    puVar4 = puVar4 + 2;
    *(undefined1 *)(param_1 + 0x2a42) = 1;
  }
  puVar2 = *(uint **)(param_1 + 0x1d8);
  *puVar2 = *puVar2 | (int)puVar4 - (int)puVar2 >> 2;
  *(undefined4 **)(param_1 + 0x1d8) = puVar4;
  *puVar4 = 0x2d000000;
  puVar4[1] = 0x404;
  puVar4[2] = param_9;
  puVar4[3] = param_2;
  puVar4[4] = param_3;
  puVar4[5] = param_4;
  puVar4[6] = param_5;
  puVar4[7] = param_6;
  puVar4[8] = param_7;
  *(undefined4 **)(param_1 + 0x298c) = puVar4 + 0x404;
  (**(code **)(param_1 + 0x299c))(iVar1,puVar4 + 0x404);
  iVar5 = (**(code **)(param_1 + 0x2998))(iVar1,0xbf);
  *(int *)(param_1 + 0x298c) = iVar5;
  puVar2 = *(uint **)(param_1 + 0x1d8);
  *puVar2 = *puVar2 | iVar5 - (int)puVar2 >> 2;
  *(undefined4 *)(param_1 + 0x1d8) = *(undefined4 *)(param_1 + 0x298c);
  puVar4 = *(undefined4 **)(param_1 + 0x298c);
  *puVar4 = 0x33000000;
  puVar4[1] = 0;
  *(undefined4 **)(param_1 + 0x298c) = puVar4 + 2;
  puVar4[2] = 0x1393;
  puVar4[3] = 10;
  puVar4[4] = 0x13c6;
  puVar4[5] = 3;
  puVar4[6] = 0x5c8;
  puVar4[7] = 0x20000;
  puVar4[8] = 0x10ea;
  puVar4[9] = *(undefined4 *)(param_1 + 0x1cfc);
  puVar4[10] = 0x10fa;
  puVar4[0xb] = *(undefined4 *)(param_1 + 0x1da0);
  puVar4[0xc] = 0xc0001000;
  puVar4[0xe] = 0x11004;
  puVar4[0xf] = *(undefined4 *)(param_1 + 0x1ca8);
  puVar4[0x10] = *(undefined4 *)(param_1 + 0x1cac);
  puVar4[0x11] = 0x1008;
  puVar4[0x12] = *(undefined4 *)(param_1 + 0x1ca0);
  puVar4[0x13] = 0x10e9;
  puVar4[0x14] = *(undefined4 *)(param_1 + 0x1d20);
  puVar4[0x15] = 0x13c7;
  puVar4[0x16] = *(undefined4 *)(param_1 + 0x1cf0);
  puVar4[0x17] = 0x13c1;
  puVar4[0x18] = *(undefined4 *)(param_1 + 0x1ce4);
  puVar4[0x19] = 0x850;
  puVar4[0x1a] = *(undefined4 *)(param_1 + 0x1dc0);
  puVar4[0x1b] = 0x887;
  puVar4[0x1c] = *(undefined4 *)(param_1 + 0x1db4);
  puVar4[0xbd] = 0x82c;
  puVar4[0xbe] = *(undefined4 *)(param_1 + 0x1dc4);
  puVar4[0x1d] = 0x10ae;
  puVar4[0x1e] = *(undefined4 *)(param_1 + 0x1d70);
  puVar4[0x1f] = 0x1394;
  puVar4[0x20] = *(undefined4 *)(param_1 + 0x1d30);
  puVar4[0x21] = 0x1380;
  puVar4[0x22] = 0;
  puVar4[0x23] = 0x1002;
  puVar4[0x24] = *(undefined4 *)(param_1 + 0x1d90);
  puVar4[0x24] = *(undefined4 *)(param_1 + 0x1d90);
  puVar4[0x25] = 0x824;
  puVar4[0x26] = *(undefined4 *)(param_1 + 0x1ddc);
  puVar4[0x27] = 0x825;
  puVar4[0x28] = *(undefined4 *)(param_1 + 0x1de0);
  puVar4[0x29] = 0x82d;
  puVar4[0x2a] = *(undefined4 *)(param_1 + 0x26cc);
  puVar4[0x2b] = 0x854;
  puVar4[0x2c] = **(undefined4 **)(param_1 + 0x2680);
  puVar4[0x2d] = 0x878;
  puVar4[0x2e] = **(undefined4 **)(param_1 + 0x2684);
  puVar4[0x2f] = &switchdataD_000013c0;
  puVar4[0x30] = *(undefined4 *)(param_1 + 0x1ce0);
  puVar4[0x31] = 0x12f0;
  puVar4[0x32] = *(undefined4 *)(param_1 + 0x1d2c);
  puVar3 = PTR_DAT_002131c9;
  if ((PTR_DAT_002131c9[(uint)*(byte *)(param_1 + 0x2b7f) * 0x24 + 0x1a] & 1) == 0) {
    *(byte *)(puVar4 + 0x32) = *(byte *)(puVar4 + 0x32) & 0xfe;
  }
  puVar4[0x33] = 0x12f5;
  puVar4[0x34] = *(undefined4 *)(param_1 + 0x1c8c);
  if ((puVar3[(uint)*(byte *)(param_1 + 0x2b7f) * 0x24 + 0x1a] & 1) == 0) {
    *(byte *)((int)puVar4 + 0xd1) = *(byte *)((int)puVar4 + 0xd1) & 0xf7;
  }
  puVar4[0x35] = 0x10a2;
  puVar4[0x36] = *(undefined4 *)(param_1 + 0x1d7c);
  puVar4[0x37] = 0x1381;
  puVar4[0x38] = *(undefined4 *)(param_1 + 0x1cc0);
  if ((puVar3[(uint)*(byte *)(param_1 + 0x2b7f) * 0x24 + 0x1a] & 2) == 0) {
    *(byte *)(puVar4 + 0x38) = *(byte *)(puVar4 + 0x38) & 0xfc;
  }
  puVar4[0x39] = 0x109e;
  puVar4[0x3a] = *(undefined4 *)(param_1 + 0x1d6c);
  puVar4[0x3b] = 0x1096;
  puVar4[0x3a] = *(undefined4 *)(param_1 + 0x1df8);
  puVar4[0x3d] = 0x1041;
  puVar4[0x3e] = *(undefined4 *)(param_1 + 0x29f0);
  puVar4[0x3f] = 0x1046;
  puVar4[0x40] = *(undefined4 *)(param_1 + 0x1dfc);
  puVar4[0x41] = 0x1094;
  puVar4[0x42] = 0;
  puVar4[0x43] = 0x1095;
  puVar4[0x45] = 0x1095;
  puVar4[0x47] = 0x1095;
  puVar4[0x49] = 0x1095;
  puVar4[0x4b] = 0x1095;
  puVar4[0x4d] = 0x1095;
  puVar4[0x4f] = 0x1095;
  puVar4[0x51] = 0x1095;
  puVar4[0x53] = 0x1095;
  puVar4[0x55] = 0x1095;
  puVar4[0x57] = 0x1095;
  puVar4[0x59] = 0x1095;
  puVar4[0x5b] = 0xc0221000;
  puVar4[0x7f] = 0x1180;
  puVar4[0x80] = 2;
  puVar4[0x81] = 0x1189;
  puVar4[0x83] = 0x1181;
  puVar4[0x85] = 0x118d;
  puVar4[0x87] = 0x118e;
  puVar4[0x89] = 0x118c;
  puVar4[0x8b] = 0x11a9;
  puVar4[0x8c] = *(undefined4 *)(param_1 + 0x257c);
  puVar4[0x8d] = 0x11aa;
  puVar4[0x8e] = *(undefined4 *)(param_1 + 0x2580);
  puVar4[0x8f] = 0x11ab;
  puVar4[0x90] = *(undefined4 *)(param_1 + 0x2584);
  puVar4[0x91] = 0x11ac;
  puVar4[0x92] = *(undefined4 *)(param_1 + 0x2588);
  puVar4[0x93] = 0x10c0;
  puVar4[0x94] = *(undefined4 *)(param_1 + 0x216c);
  puVar4[0x95] = 0x10c1;
  puVar4[0x97] = 0x10c8;
  puVar4[0x99] = 0x101d;
  puVar4[0x9a] = *(undefined4 *)(param_1 + 0x2128);
  puVar4[0x9b] = 0x138a;
  puVar4[0x9c] = 0;
  puVar4[0x9d] = 0x138e;
  puVar4[0x9e] = 0;
  puVar4[0x9f] = 0x1040;
  puVar4[0xa0] = 0;
  puVar4[0xa1] = 0x1150;
  puVar4[0xa2] = 0;
  puVar4[0xa3] = 0x1100;
  puVar4[0xa4] = *(undefined4 *)(param_1 + 0x1f1c);
  puVar4[0xa5] = 0x1110;
  puVar4[0xa6] = *(undefined4 *)(param_1 + 0x1f5c);
  puVar4[0xa7] = 0x1120;
  puVar4[0xa8] = *(undefined4 *)(param_1 + 0x1f9c);
  puVar4[0xa9] = 0x1130;
  puVar4[0xaa] = *(undefined4 *)(param_1 + 0x1fdc);
  puVar4[0xab] = 0x1140;
  puVar4[0xac] = *(undefined4 *)(param_1 + 0x201c);
  puVar4[0xad] = 0x10f4;
  puVar4[0xae] = 0xaaaa;
  puVar4[0xaf] = 0x1383;
  puVar4[0xb0] = *(undefined4 *)(param_1 + 0x1d34);
  puVar4[0xb1] = 0x1386;
  puVar4[0xb2] = *(undefined4 *)(param_1 + 0x1d38);
  puVar4[0xb3] = 0x110f8;
  puVar4[0xb4] = *(undefined4 *)(param_1 + 0x1d98);
  puVar4[0xb5] = *(undefined4 *)(param_1 + 0x1d50);
  puVar4[0xb6] = 0x1087;
  puVar4[0xb7] = *(undefined4 *)(param_1 + 0x1f0c);
  puVar4[0xb8] = 0x31080;
  puVar4[0xb9] = *(undefined4 *)(param_1 + 0x1efc);
  puVar4[0xba] = *(undefined4 *)(param_1 + 0x1f04);
  puVar4[0xbb] = *(undefined4 *)(param_1 + 0x1f00);
  puVar4[0xbc] = *(undefined4 *)(param_1 + 0x1f08);
  FUN_0004acbc(puVar4 + 2,iVar1);
  *(undefined4 **)(param_1 + 0x298c) = puVar4 + 0xbf;
                    
                    
  (**(code **)(param_1 + 0x299c))();
  return;
}

/* _gldUpdateDispatch @ 0x1ff24 (2725 bytes) */
int _gldUpdateDispatch(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint *param_3;
{
  byte bVar1;
  int *piVar2;
  bool bVar3;
  undefined *puVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  uint uVar12;
  uint *puVar13;
  int iVar14;
  uint uVar15;
  int local_68;
  uint *local_64;
  uint local_54;
  uint local_50;
  char local_49;
  uint local_44;
  uint local_40;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  
  if (*(char *)(param_1 + 0x2a69) == '\0') {
    if (*(char *)(param_1 + 0x2a44) == '\0') goto LAB_0001ff99;
    *param_3 = 0xffffffff;
    param_3[1] = param_3[1] | 0x3ffffff;
    param_3[2] = param_3[2] | 0xfffffffd;
    param_3[3] = param_3[3] | 0x7ffffff;
    param_3[4] = 0xffffffff;
    *(undefined1 *)(param_1 + 0x26bd) = 1;
    *(undefined1 *)(param_1 + 0x2a43) = 1;
    *(undefined4 *)(param_1 + 0x29fc) = 0xffffffff;
    *(uint *)(param_1 + 0x26c8) = *(uint *)(param_1 + 0x26c8) | 7;
    *(undefined1 *)(param_1 + 0x2a44) = 0;
    uVar15 = *param_3;
  }
  else {
    *param_3 = 0xffffffff;
    param_3[1] = param_3[1] | 0x3ffffff;
    param_3[2] = param_3[2] | 0xfffffffd;
    param_3[3] = param_3[3] | 0x7ffffff;
    param_3[4] = 0xffffffff;
    *(undefined1 *)(param_1 + 0x26bd) = 1;
    *(undefined1 *)(param_1 + 0x2a43) = 1;
    *(undefined4 *)(param_1 + 0x29fc) = 0xffffffff;
    *(uint *)(param_1 + 0x26c8) = *(uint *)(param_1 + 0x26c8) | 7;
    *(undefined1 *)(param_1 + 0x2a69) = 0;
    *(undefined1 *)(param_1 + 0x2a44) = 0;
LAB_0001ff99:
    uVar15 = *param_3;
  }
  if ((int)uVar15 < 0) {
    FUN_00006ee5(param_1);
  }
  piVar2 = *(int **)(param_1 + 0x150);
  if (((piVar2 == (int *)0x0) || (*(ushort *)(*piVar2 + 0x90) == 0)) ||
     (iVar14 = *(int *)(piVar2[1] + -0x23380 + (uint)*(ushort *)(*piVar2 + 0x90) * 4), iVar14 == 0))
  {
LAB_0001ffff:
    if ((*param_3 & 0x180) == 0) {
      local_50 = 4;
      local_54 = (uint)(ushort)param_3[1];
      iVar14 = *(int *)(param_1 + 0x18);
      puVar8 = *(undefined4 **)(iVar14 + 0x19c);
      if (puVar8 == (undefined4 *)0x0) goto LAB_00020078;
LAB_00020155:
      if ((*(int *)((short *)*puVar8 + 2) == 0) || (*(short *)*puVar8 == -0x7e00)) {
LAB_00020169:
        local_49 = '\0';
      }
      else {
        local_49 = '\x01';
        iVar14 = puVar8[0xe];
        if (((iVar14 != 0) && (*(char *)(iVar14 + 0x20) < '\0')) &&
           (*(byte *)(param_1 + 0x2b7c) != (*(byte *)(iVar14 + 0x21) & 1))) {
          param_3[3] = param_3[3] | 0x1000000;
        }
      }
    }
    else {
      if (piVar2 != (int *)0x0) {
        FUN_00019607(param_1,piVar2);
      }
      if ((*(int *)(*(int *)(param_1 + 0x18) + 0x1a0) == 0) || (*(int *)(param_1 + 0x150) != 0)) {
        local_50 = 4;
      }
      else {
        local_50 = 0xc;
      }
      FUN_00014da2(param_1);
      local_54 = (uint)(ushort)param_3[1];
      iVar14 = *(int *)(param_1 + 0x18);
      puVar8 = *(undefined4 **)(iVar14 + 0x19c);
      if (puVar8 != (undefined4 *)0x0) goto LAB_00020155;
LAB_00020078:
      if (((*(char *)(*(int *)(param_1 + 0x10) + 0x430c) == '\0') ||
          (*(int *)((short *)**(undefined4 **)(iVar14 + 400) + 2) == 0)) ||
         (*(short *)**(undefined4 **)(iVar14 + 400) == -0x7e00)) goto LAB_00020169;
      local_49 = '\x01';
    }
    local_64 = param_3 + 1;
    if ((local_49 == *(char *)(param_1 + 0x29dc)) &&
       (uVar15 = param_3[3], (uVar15 & 0x5000000) == 0)) {
      if (local_54 != 0) goto LAB_0002019d;
      bVar3 = false;
    }
    else {
      *(char *)(param_1 + 0x29dc) = local_49;
      *local_64 = *local_64 | 0xffff;
      local_54 = 0xffff;
LAB_0002019d:
      _pthread_mutex_lock(*(pthread_mutex_t **)(param_1 + 0xc));
      iVar14 = *(int *)(param_1 + 0x18);
      if (*(int **)(iVar14 + 0x19c) == (int *)0x0) {
        if (((*(char *)(*(int *)(param_1 + 0x10) + 0x430c) != '\0') &&
            (*(undefined4 **)(iVar14 + 400) != (undefined4 *)0x0)) &&
           (*(short *)**(undefined4 **)(iVar14 + 400) != -0x7e00)) {
          local_44 = *(uint *)(**(int **)(iVar14 + 400) + 8);
          local_40 = *(uint *)(**(int **)(iVar14 + 400) + 0xc);
          goto LAB_000201ca;
        }
        local_28 = param_1;
        bVar1 = 0;
        local_24 = 0;
        local_68 = 0;
        uVar15 = local_54;
        do {
          if ((uVar15 & 1) != 0) {
            iVar14 = 0;
            do {
              if ((*(uint *)(local_68 + *(int *)(param_1 + 0x10) + 0x31d4) &
                  1 << ((byte)iVar14 & 0x1f)) != 0) {
                uVar6 = *(uint *)(local_24 + *(int *)(param_1 + 0x18) + iVar14 * 4);
                if ((*(byte *)(uVar6 + 0x39) & 0x87) == 0) {
                  uVar12 = uVar6 & -(uint)*(byte *)(uVar6 + 0x3d);
                }
                else {
                  cVar5 = FUN_0002fdb4(param_1,uVar6);
                  if ((cVar5 == '\0') || (uVar12 = uVar6, *(char *)(uVar6 + 0x3d) == '\0')) {
                    uVar12 = 0;
                  }
                }
                uVar9 = (-2 << (bVar1 & 0x1f) | 0xfffffffeU >> 0x20 - (bVar1 & 0x1f)) &
                        *(uint *)(param_1 + 0x26b8);
                *(uint *)(param_1 + 0x26b8) = uVar9;
                *(uint *)(param_1 + 0x26b8) =
                     uVar9 | (uint)*(byte *)(uVar6 + 0x44) << (bVar1 & 0x1f);
                goto LAB_00020308;
              }
              iVar14 = iVar14 + 1;
            } while (iVar14 != 5);
            *(uint *)(param_1 + 0x26b8) = *(uint *)(param_1 + 0x26b8) & ~(1 << (bVar1 & 0x1f));
            uVar12 = 0;
LAB_00020308:
            *(uint *)(local_28 + 0x18c) = uVar12;
          }
          bVar1 = bVar1 + 1;
          local_68 = local_68 + 0x7c;
          local_28 = local_28 + 4;
          local_24 = local_24 + 0x14;
          uVar15 = uVar15 >> 1;
        } while (uVar15 != 0);
      }
      else {
        iVar14 = **(int **)(iVar14 + 0x19c);
        local_44 = *(uint *)(iVar14 + 8);
        local_40 = *(uint *)(iVar14 + 0xc);
LAB_000201ca:
        local_30 = param_1;
        bVar1 = 0;
        local_2c = 0;
        uVar15 = local_54;
        do {
          if ((uVar15 & 1) != 0) {
            if ((local_44 & 0xf) < 5) {
              uVar6 = *(uint *)(local_2c + *(int *)(param_1 + 0x18) + (local_44 & 0xf) * 4);
              if ((*(byte *)(uVar6 + 0x39) & 0x87) == 0) {
                uVar12 = uVar6 & -(uint)*(byte *)(uVar6 + 0x3d);
              }
              else {
                cVar5 = FUN_0002fdb4(param_1,uVar6);
                if ((cVar5 == '\0') || (uVar12 = uVar6, *(char *)(uVar6 + 0x3d) == '\0')) {
                  uVar12 = 0;
                }
              }
              uVar9 = ~(1 << (bVar1 & 0x1f)) & *(uint *)(param_1 + 0x26b8);
              *(uint *)(param_1 + 0x26b8) = uVar9;
              *(uint *)(param_1 + 0x26b8) = uVar9 | (uint)*(byte *)(uVar6 + 0x44) << (bVar1 & 0x1f);
            }
            else {
              *(uint *)(param_1 + 0x26b8) = *(uint *)(param_1 + 0x26b8) & ~(1 << (bVar1 & 0x1f));
              uVar12 = 0;
            }
            *(uint *)(local_30 + 0x18c) = uVar12;
          }
          bVar1 = bVar1 + 1;
          local_44 = local_44 >> 4 | local_40 << 0x1c;
          local_40 = local_40 >> 4;
          local_30 = local_30 + 4;
          local_2c = local_2c + 0x14;
          uVar15 = uVar15 >> 1;
        } while (uVar15 != 0);
      }
      FUN_000a623b(param_1,local_54);
      if (*(int *)(param_1 + 0x26b8) != 0) {
        iVar14 = 0;
        do {
          iVar7 = 0;
          uVar15 = *(uint *)(param_1 + 0x26b8);
          do {
            if ((uVar15 & 1) != 0) {
              *(undefined1 *)(*(int *)(iVar14 + iVar7 + *(int *)(param_1 + 0x18)) + 0x44) = 0;
              uVar15 = *(uint *)(param_1 + 0x26b8);
            }
            iVar7 = iVar7 + 4;
          } while (iVar7 != 0x14);
          *(uint *)(param_1 + 0x26b8) = uVar15 >> 1;
          iVar14 = iVar14 + 0x14;
        } while (uVar15 >> 1 != 0);
        goto LAB_00020675;
      }
      bVar3 = true;
      uVar15 = param_3[3];
    }
    puVar13 = param_3 + 3;
    if ((uVar15 & 0x5400000) != 0) {
      if ((*(int *)(*(int *)(param_1 + 0x18) + 0x198) == 0) &&
         (*(int *)(*(int *)(param_1 + 0x18) + 0x18c) == 0)) {
        bVar11 = false;
      }
      else {
        bVar11 = true;
      }
      if (!bVar3) {
        _pthread_mutex_lock(*(pthread_mutex_t **)(param_1 + 0xc));
        bVar3 = true;
      }
      FUN_00008612(param_1);
      if ((*(int *)(param_1 + 0x1cc) != 0) != bVar11) {
        *(undefined1 *)(param_1 + 0x26bd) = 1;
      }
      if (*(int *)(param_1 + 0x1cc) == 0) {
        *(undefined4 *)(param_1 + 0x29e8) = 0;
      }
      if ((*(int *)(param_1 + 0x1d0) == 0) &&
         (*(undefined4 *)(param_1 + 0x29ec) = 0, local_49 != '\0')) {
        *(undefined1 *)(param_1 + 0x2a69) = 1;
        *puVar13 = *puVar13 | 0x10000000;
        *(undefined4 *)(param_1 + 0x1cc) = 0;
        *(undefined4 *)(param_1 + 0x29e8) = 0;
        local_50 = 0;
      }
    }
    uVar15 = *puVar13;
    if ((uVar15 & 0x4500000) != 0) {
      if (!bVar3) {
        _pthread_mutex_lock(*(pthread_mutex_t **)(param_1 + 0xc));
        bVar3 = true;
      }
      FUN_0000a33c(param_1);
      uVar15 = *puVar13;
    }
    uVar10 = *(uint *)(param_1 + 0x26c0) | param_3[2];
    uVar15 = uVar15 | *(uint *)(param_1 + 0x26c4);
    uVar6 = *param_3;
    uVar12 = *local_64;
    uVar9 = param_3[4];
    if ((uVar15 & 0xffefffff) != 0 || (((uVar6 != 0 || uVar12 != 0) || uVar10 != 0) || uVar9 != 0))
    {
      param_3[2] = uVar10;
      *puVar13 = uVar15;
      ((void (*)())FUN_000a81f5)(param_1 + 0x240,param_3);
    }
    if ((uVar15 & 0x10000000) != *(uint *)(param_1 + 0x29c0) ||
        (uVar15 != 0 || (((uVar6 != 0 || uVar12 != 0) || uVar10 != 0) || uVar9 != 0))) {
      FUN_0002a251(param_1 + 0x240,param_3);
    }
    uVar6 = local_50 | 2;
    if ((*(byte *)(param_1 + 0x26c8) & 2) == 0) {
      uVar6 = local_50;
    }
    if ((char)*param_3 < '\0') {
      if (*(int *)(param_1 + 0x150) == 0) {
        uVar12 = *(uint *)(param_1 + 0x154);
        if ((uVar12 & 0x20) == 0) {
          if ((uVar12 & 0x400) == 0) {
            *(undefined1 **)(param_2 + 0x60) = ((unsigned char *)0x0001ff1f);
          }
          else {
            *(undefined **)(param_2 + 0x60) = PTR_LAB_00017de2_4_00213231;
          }
          *(undefined **)(param_2 + 0x58) = PTR_LAB_00213275;
          *(undefined **)(param_2 + 0x5c) = PTR_LAB_00018142_4_00213279;
        }
        else if ((uVar12 & 0x400) == 0) {
          *(undefined **)(param_2 + 0x58) = PTR_FUN_0021327d;
          puVar4 = PTR_LAB_0001852e_4_00213235;
          *(undefined **)(param_2 + 0x5c) = PTR_LAB_0001852e_4_00213235;
          *(undefined **)(param_2 + 0x60) = puVar4;
        }
        else if ((uVar12 & 0x800) == 0) {
          *(undefined **)(param_2 + 0x58) = PTR_LAB_00213275;
          *(undefined **)(param_2 + 0x5c) = PTR_LAB_00018142_4_00213279;
          *(undefined **)(param_2 + 0x60) = PTR_LAB_00017de2_4_00213231;
        }
        else if (*(int *)(param_1 + 0x26a0) == 0) {
          FUN_00018533(param_1);
          *(undefined **)(param_2 + 0x58) = PTR_LAB_00213275;
          *(undefined **)(param_2 + 0x5c) = PTR_LAB_00018142_4_00213279;
          *(undefined **)(param_2 + 0x60) = PTR_FUN_00213245;
        }
        else {
          *(undefined **)(param_2 + 0x58) = PTR_FUN_0021327d;
          *(undefined **)(param_2 + 0x5c) = PTR_LAB_0001852e_4_00213235;
          *(undefined **)(param_2 + 0x60) = PTR_FUN_00213245;
        }
      }
      else {
        *(undefined1 **)(param_2 + 0x60) = ((unsigned char *)0x0001ff1f);
        *(undefined **)(param_2 + 0x58) = PTR_LAB_00213275;
        *(undefined **)(param_2 + 0x5c) = PTR_LAB_00018142_4_00213279;
      }
    }
    if ((*(char *)(param_1 + 0x20) == '\0') || (*(int *)(param_1 + 0x1cc) == 0)) {
      *(undefined **)(param_2 + 0x18) = PTR_LAB_000221dc_4_00213241;
      *(undefined **)(param_2 + 0x1c) = PTR_FUN_0021320d;
      *(undefined **)(param_2 + 0x24) = PTR_LAB_00022352_4_00213219;
      *(undefined **)(param_2 + 0x20) = PTR_LAB_000223b2_4_002131d1;
      *(undefined **)(param_2 + 0x2c) = PTR_LAB_00021f21_1_0021323d;
      *(undefined **)(param_2 + 0x34) = PTR_LAB_00021f82_4_002131dd;
      *(undefined **)(param_2 + 0x30) = PTR_LAB_00021fe6_4_00213249;
      *(undefined **)(param_2 + 0x38) = PTR_FUN_002131e1;
      *(undefined **)(param_2 + 0x3c) = PTR_FUN_00213239;
      *(undefined **)(param_2 + 0x28) = PTR_FUN_00213211;
      if (*(char *)(param_1 + 0x20) == '\0') {
        *(undefined **)(param_2 + 0x40) = PTR_FUN_002131f5;
        *(undefined **)(param_2 + 0x44) = PTR_LAB_000222f6_4_0021328d;
        *(undefined **)(param_2 + 0x48) = PTR_FUN_00213259;
      }
      else {
        *(undefined1 **)(param_2 + 0x40) = ((unsigned char *)0x0001ff1f);
        *(undefined1 **)(param_2 + 0x44) = ((unsigned char *)0x0001ff1f);
        *(undefined1 **)(param_2 + 0x48) = ((unsigned char *)0x0001ff1f);
      }
    }
    else {
      *(undefined **)(param_2 + 0x18) = PTR_FUN_00213215;
      *(undefined **)(param_2 + 0x1c) = PTR_FUN_002131e9;
      *(undefined **)(param_2 + 0x24) = PTR_FUN_00213205;
      *(undefined **)(param_2 + 0x20) = PTR_FUN_0021322d;
      *(undefined **)(param_2 + 0x2c) = PTR_FUN_002131f1;
      *(undefined **)(param_2 + 0x34) = PTR_FUN_0021325d;
      *(undefined **)(param_2 + 0x30) = PTR_LAB_00038943_1_00213221;
      *(undefined **)(param_2 + 0x38) = PTR_FUN_00213229;
      *(undefined **)(param_2 + 0x3c) = PTR_FUN_00213265;
      *(undefined **)(param_2 + 0x28) = PTR_FUN_00213251;
    }
    *(uint *)(param_1 + 0x26c8) = *(uint *)(param_1 + 0x26c8) & 0xfffffff9;
    *(undefined1 *)(param_1 + 0x26bd) = 0;
    *(undefined1 *)(param_1 + 0x2a43) = 0;
    *(undefined1 *)(param_1 + 0x2675) = 0;
    *(uint *)(param_1 + 0x29c0) = uVar15 & 0x10000000;
    *(undefined1 *)(param_1 + 0x2b7d) = 0;
    if ((*(int *)(param_1 + 0x150) != 0) &&
       (iVar14 = *(int *)(*(int *)(*(int *)(param_1 + 0x150) + 4) + 0x10), iVar14 != 0)) {
      *(undefined1 *)(iVar14 + 200) = 1;
    }
    if (bVar3) {
      _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
    }
    local_50 = uVar6;
    if (*(char *)(param_1 + 0x20) != '\0') {
      return uVar6 | 1;
    }
  }
  else {
    bVar1 = *(byte *)(iVar14 + 0x38);
    iVar14 = *(int *)(param_1 + 0x10);
    if (*(char *)(iVar14 + 0x2d84) == '\0') {
      cVar5 = *(char *)(iVar14 + 0x2e0a);
joined_r0x0001fff9:
      if ((cVar5 == '\0') || ((PTR_DAT_002131c9[(uint)bVar1 * 0x24 + 0x1a] & 1) != 0))
      goto LAB_0001ffff;
    }
    else if ((PTR_DAT_002131c9[(uint)bVar1 * 0x24 + 0x1a] & 2) != 0) {
      cVar5 = *(char *)(iVar14 + 0x2e0a);
      goto joined_r0x0001fff9;
    }
LAB_00020675:
    local_50 = 0;
  }
  return local_50;
}

/* _gldInitDispatch @ 0x209c9 (356 bytes) */
int _gldInitDispatch(param_1, param_2, param_3)
  int param_1;
  undefined4 *param_2;
  undefined4 *param_3;
{
  int iVar1;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_30 = 0xffffffff;
  local_2c = 0x3ffffff;
  local_28 = 0xfffffffd;
  local_24 = 0x7ffffff;
  local_20 = 0xffffffff;
  *param_3 = *(undefined4 *)(param_1 + 0x104);
  param_3[1] = *(undefined4 *)(param_1 + 0x108);
  param_3[2] = *(undefined4 *)(param_1 + 0x10c);
  param_3[3] = *(undefined4 *)(param_1 + 0x110);
  param_3[4] = *(undefined4 *)(param_1 + 0x114);
  param_3[5] = *(undefined4 *)(param_1 + 0x118);
  *(undefined4 **)(param_1 + 0x1c) = param_2;
  iVar1 = 0;
  do {
    FUN_000a6603(param_1,iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 != 0x10);
  param_2[5] = PTR_FUN_002131d9;
  *param_2 = PTR_FUN_0021324d;
  param_2[4] = PTR_LAB_00015bd3_1_00213285;
  param_2[2] = PTR_LAB_00026edc_4_00213289;
  param_2[3] = PTR_FUN_002131fd;
  param_2[1] = PTR_LAB_0001ddac_4_00213255;
  param_2[0x19] = PTR_FUN_00213261;
  param_2[0x1d] = PTR_LAB_00033c48_4_00213209;
  param_2[0x1e] = PTR_LAB_000355cc_4_002131f9;
  param_2[0x1f] = PTR_FUN_002131ed;
  if (*(char *)(param_1 + 0x2b82) == '\0') {
    param_2[0x14] = PTR_FUN_002131e5;
    param_2[0x15] = PTR_FUN_0021321d;
  }
  else {
    param_2[0x14] = PTR_LAB_00024890_4_00213271;
    param_2[0x15] = PTR_LAB_00024a6f_1_0021326d;
  }
  param_2[0x1c] = PTR_FUN_00213281;
  param_2[0x13] = PTR_LAB_00022412_4_00213225;
  param_2[0x1a] = PTR_LAB_00029967_1_00213269;
  param_2[0x1b] = PTR_FUN_00213201;
  param_2[0x20] = PTR_LAB_0001c236_4_002131d5;
  ((int (*)())_gldUpdateDispatch)(param_1,param_2,&local_30);
  return;
}

/* FUN_00020b2d @ 0x20b2d (482 bytes) */
int FUN_00020b2d(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  uint uVar1;
  int iVar2;
  bool bVar3;
  
  iVar2 = param_1 + 0x240;
  FUN_000a4461(iVar2);
  bVar3 = param_2 == (undefined4 *)0x0;
  if (bVar3) {
    param_2 = (undefined4 *)(**(code **)(param_1 + 0x2998))(iVar2,0x23);
    *(undefined4 **)(param_1 + 0x298c) = param_2;
  }
  uVar1 = *(uint *)(param_1 + 0x1b70);
  if ((uVar1 & 0x100) != 0) {
    *param_2 = 0x1393;
    param_2[1] = 10;
    param_2 = param_2 + 2;
    uVar1 = *(uint *)(param_1 + 0x1b70);
  }
  if ((uVar1 & 0x2000000) != 0) {
    *param_2 = 0x13c6;
    param_2[1] = 3;
    param_2 = param_2 + 2;
    uVar1 = *(uint *)(param_1 + 0x1b70);
  }
  if ((uVar1 & 0x200) != 0) {
    *param_2 = 0x12f5;
    param_2[1] = *(undefined4 *)(param_1 + 0x1c8c);
    param_2 = param_2 + 2;
    uVar1 = *(uint *)(param_1 + 0x1b70);
  }
  if ((uVar1 & 0x80000) != 0) {
    *param_2 = 0x1008;
    param_2[1] = *(undefined4 *)(param_1 + 0x1ca0);
    param_2[2] = 0x1004;
    param_2[3] = *(undefined4 *)(param_1 + 0x1ca8);
    param_2[4] = 0x1005;
    param_2[5] = *(undefined4 *)(param_1 + 0x1cac);
    param_2[6] = 0x10fa;
    param_2[7] = *(undefined4 *)(param_1 + 0x1da0);
    param_2 = param_2 + 8;
    uVar1 = *(uint *)(param_1 + 0x1b70);
  }
  if ((uVar1 & 0x10000000) != 0) {
    *param_2 = 0x413de;
    param_2[1] = *(undefined4 *)(param_1 + 0x25a0);
    param_2[2] = *(undefined4 *)(param_1 + 0x25a4);
    param_2[3] = *(undefined4 *)(param_1 + 0x25a8);
    param_2[4] = *(undefined4 *)(param_1 + 0x25ac);
    param_2[5] = *(undefined4 *)(param_1 + 0x25b0);
    param_2[6] = 0x313e9;
    param_2[7] = *(undefined4 *)(param_1 + 0x25b4);
    param_2[8] = *(undefined4 *)(param_1 + 0x25b8);
    param_2[9] = *(undefined4 *)(param_1 + 0x25bc);
    param_2[10] = *(undefined4 *)(param_1 + 0x25c0);
    param_2 = param_2 + 0xb;
    uVar1 = *(uint *)(param_1 + 0x1b70);
  }
  if ((uVar1 & 0x20000000) != 0) {
    *param_2 = 0x813ad;
    param_2[1] = *(undefined4 *)(param_1 + 0x25c4);
    param_2[2] = *(undefined4 *)(param_1 + 0x25c8);
    param_2[3] = *(undefined4 *)(param_1 + 0x25cc);
    param_2[4] = *(undefined4 *)(param_1 + 0x25d0);
    param_2[5] = *(undefined4 *)(param_1 + 0x25d4);
    param_2[6] = *(undefined4 *)(param_1 + 0x25d8);
    param_2[7] = *(undefined4 *)(param_1 + 0x25dc);
    param_2[8] = *(undefined4 *)(param_1 + 0x25e0);
    param_2[9] = *(undefined4 *)(param_1 + 0x25e4);
    param_2 = param_2 + 10;
  }
  if (bVar3) {
    *(undefined4 **)(param_1 + 0x298c) = param_2;
    (**(code **)(param_1 + 0x299c))(iVar2,param_2);
  }
  return param_2;
}

/* FUN_00020d0f @ 0x20d0f (1795 bytes) */
int FUN_00020d0f(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  undefined4 *param_2;
  undefined4 param_3;
  int param_4;
  undefined4 param_5;
  int param_6;
  undefined4 param_7;
  int param_8;
{
  uint *puVar1;
  undefined *puVar2;
  int iVar3;
  bool bVar4;
  uint local_20;
  
  iVar3 = param_1 + 0x240;
  if (*(char *)(param_1 + 0x2a5e) != '\0') {
    if ((*(int *)(param_1 + 0x154) < 0) || (param_4 == 0)) {
      local_20 = 0;
    }
    else {
      *(undefined1 *)(param_1 + 0x2a5e) = 0;
      local_20 = (uint)param_4;
    }
    bVar4 = param_2 == (undefined4 *)0x0;
    if (bVar4) {
      param_2 = (undefined4 *)(**(code **)(param_1 + 0x2998))(iVar3,500);
      *(undefined4 **)(param_1 + 0x298c) = param_2;
    }
    puVar1 = *(uint **)(param_1 + 0x1d8);
    *puVar1 = *puVar1 | (int)param_2 - (int)puVar1 >> 2;
    *(undefined4 **)(param_1 + 0x1d8) = param_2;
    *param_2 = 0x30000000;
    param_2[1] = 0xfa;
    param_2[2] = param_3;
    param_2[3] = local_20;
    param_2[4] = param_5;
    if (*(char *)(param_1 + 0x2b7c) != '\0') {
      param_6 = (*(int *)(param_1 + 0x160) - param_8) - param_6;
    }
    param_2[5] = param_6;
    param_2[6] = param_7;
    param_2[7] = param_8;
    puVar1 = *(uint **)(param_1 + 0x1d8);
    *puVar1 = *puVar1 | (int)(param_2 + 0xfa) - (int)puVar1 >> 2;
    *(undefined4 **)(param_1 + 0x1d8) = param_2 + 0xfa;
    param_2[0xfa] = 0x33000000;
    param_2[0xfb] = 0;
    param_2[0xfc] = 0x1393;
    param_2[0xfd] = 10;
    param_2[0xfe] = 0x13c6;
    param_2[0xff] = 3;
    param_2[0x100] = 0x5c8;
    param_2[0x101] = 0x20000;
    param_2[0x102] = 0x10ea;
    param_2[0x103] = *(undefined4 *)(param_1 + 0x1cfc);
    param_2[0x104] = 0x10fa;
    param_2[0x105] = *(undefined4 *)(param_1 + 0x1da0);
    param_2[0x106] = 0xc0001000;
    param_2[0x108] = 0x11004;
    param_2[0x109] = *(undefined4 *)(param_1 + 0x1ca8);
    param_2[0x10a] = *(undefined4 *)(param_1 + 0x1cac);
    param_2[0x10b] = 0x1008;
    param_2[0x10c] = *(undefined4 *)(param_1 + 0x1ca0);
    param_2[0x10d] = 0x10e9;
    param_2[0x10e] = *(undefined4 *)(param_1 + 0x1d20);
    param_2[0x10f] = 0x13c7;
    param_2[0x110] = *(undefined4 *)(param_1 + 0x1cf0);
    param_2[0x111] = 0x13c1;
    param_2[0x112] = *(undefined4 *)(param_1 + 0x1ce4);
    param_2[0x113] = 0x850;
    param_2[0x114] = *(undefined4 *)(param_1 + 0x1dc0);
    param_2[0x115] = 0x887;
    param_2[0x116] = *(undefined4 *)(param_1 + 0x1db4);
    param_2[0x1b7] = 0x82c;
    param_2[0x1b8] = *(undefined4 *)(param_1 + 0x1dc4);
    param_2[0x117] = 0x10ae;
    param_2[0x118] = *(undefined4 *)(param_1 + 0x1d70);
    param_2[0x119] = 0x1394;
    param_2[0x11a] = *(undefined4 *)(param_1 + 0x1d30);
    param_2[0x11b] = 0x1380;
    param_2[0x11c] = 0;
    param_2[0x11d] = 0x1002;
    param_2[0x11e] = *(undefined4 *)(param_1 + 0x1d90);
    param_2[0x11e] = *(undefined4 *)(param_1 + 0x1d90);
    param_2[0x11f] = 0x824;
    param_2[0x120] = *(undefined4 *)(param_1 + 0x1ddc);
    param_2[0x121] = 0x825;
    param_2[0x122] = *(undefined4 *)(param_1 + 0x1de0);
    param_2[0x123] = 0x82d;
    param_2[0x124] = *(undefined4 *)(param_1 + 0x26cc);
    param_2[0x125] = 0x854;
    param_2[0x126] = **(undefined4 **)(param_1 + 0x2680);
    param_2[0x127] = 0x878;
    param_2[0x128] = **(undefined4 **)(param_1 + 0x2684);
    param_2[0x129] = &switchdataD_000013c0;
    param_2[0x12a] = *(undefined4 *)(param_1 + 0x1ce0);
    param_2[299] = 0x12f0;
    param_2[300] = *(undefined4 *)(param_1 + 0x1d2c);
    puVar2 = PTR_DAT_002131c9;
    if ((PTR_DAT_002131c9[(uint)*(byte *)(param_1 + 0x2b7f) * 0x24 + 0x1a] & 1) == 0) {
      *(byte *)(param_2 + 300) = *(byte *)(param_2 + 300) & 0xfe;
    }
    param_2[0x12d] = 0x12f5;
    param_2[0x12e] = *(undefined4 *)(param_1 + 0x1c8c);
    if ((puVar2[(uint)*(byte *)(param_1 + 0x2b7f) * 0x24 + 0x1a] & 1) == 0) {
      *(byte *)((int)param_2 + 0x4b9) = *(byte *)((int)param_2 + 0x4b9) & 0xf7;
    }
    param_2[0x12f] = 0x10a2;
    param_2[0x130] = *(undefined4 *)(param_1 + 0x1d7c);
    param_2[0x131] = 0x1381;
    param_2[0x132] = *(undefined4 *)(param_1 + 0x1cc0);
    if ((puVar2[(uint)*(byte *)(param_1 + 0x2b7f) * 0x24 + 0x1a] & 2) == 0) {
      *(byte *)(param_2 + 0x132) = *(byte *)(param_2 + 0x132) & 0xfc;
    }
    param_2[0x133] = 0x109e;
    param_2[0x134] = *(undefined4 *)(param_1 + 0x1d6c);
    param_2[0x135] = 0x1096;
    param_2[0x134] = *(undefined4 *)(param_1 + 0x1df8);
    param_2[0x137] = 0x1041;
    param_2[0x138] = *(undefined4 *)(param_1 + 0x29f0);
    param_2[0x139] = 0x1046;
    param_2[0x13a] = *(undefined4 *)(param_1 + 0x1dfc);
    param_2[0x13b] = 0x1094;
    param_2[0x13c] = 0;
    param_2[0x13d] = 0x1095;
    param_2[0x13f] = 0x1095;
    param_2[0x141] = 0x1095;
    param_2[0x143] = 0x1095;
    param_2[0x145] = 0x1095;
    param_2[0x147] = 0x1095;
    param_2[0x149] = 0x1095;
    param_2[0x14b] = 0x1095;
    param_2[0x14d] = 0x1095;
    param_2[0x14f] = 0x1095;
    param_2[0x151] = 0x1095;
    param_2[0x153] = 0x1095;
    param_2[0x155] = 0xc0221000;
    param_2[0x179] = 0x1180;
    param_2[0x17a] = 2;
    param_2[0x17b] = 0x1189;
    param_2[0x17d] = 0x1181;
    param_2[0x17f] = 0x118d;
    param_2[0x181] = 0x118e;
    param_2[0x183] = 0x118c;
    param_2[0x185] = 0x11a9;
    param_2[0x186] = *(undefined4 *)(param_1 + 0x257c);
    param_2[0x187] = 0x11aa;
    param_2[0x188] = *(undefined4 *)(param_1 + 0x2580);
    param_2[0x189] = 0x11ab;
    param_2[0x18a] = *(undefined4 *)(param_1 + 0x2584);
    param_2[0x18b] = 0x11ac;
    param_2[0x18c] = *(undefined4 *)(param_1 + 0x2588);
    param_2[0x18d] = 0x10c0;
    param_2[0x18e] = *(undefined4 *)(param_1 + 0x216c);
    param_2[399] = 0x10c1;
    param_2[0x191] = 0x10c8;
    param_2[0x193] = 0x101d;
    param_2[0x194] = *(undefined4 *)(param_1 + 0x2128);
    param_2[0x195] = 0x138a;
    param_2[0x196] = 0;
    param_2[0x197] = 0x138e;
    param_2[0x198] = 0;
    param_2[0x199] = 0x1040;
    param_2[0x19a] = 0;
    param_2[0x19b] = 0x1150;
    param_2[0x19c] = 0;
    param_2[0x19d] = 0x1100;
    param_2[0x19e] = *(undefined4 *)(param_1 + 0x1f1c);
    param_2[0x19f] = 0x1110;
    param_2[0x1a0] = *(undefined4 *)(param_1 + 0x1f5c);
    param_2[0x1a1] = 0x1120;
    param_2[0x1a2] = *(undefined4 *)(param_1 + 0x1f9c);
    param_2[0x1a3] = 0x1130;
    param_2[0x1a4] = *(undefined4 *)(param_1 + 0x1fdc);
    param_2[0x1a5] = 0x1140;
    param_2[0x1a6] = *(undefined4 *)(param_1 + 0x201c);
    param_2[0x1a7] = 0x10f4;
    param_2[0x1a8] = 0xaaaa;
    param_2[0x1a9] = 0x1383;
    param_2[0x1aa] = *(undefined4 *)(param_1 + 0x1d34);
    param_2[0x1ab] = 0x1386;
    param_2[0x1ac] = *(undefined4 *)(param_1 + 0x1d38);
    param_2[0x1ad] = 0x110f8;
    param_2[0x1ae] = *(undefined4 *)(param_1 + 0x1d98);
    param_2[0x1af] = *(undefined4 *)(param_1 + 0x1d50);
    param_2[0x1b0] = 0x1087;
    param_2[0x1b1] = *(undefined4 *)(param_1 + 0x1f0c);
    param_2[0x1b2] = 0x31080;
    param_2[0x1b3] = *(undefined4 *)(param_1 + 0x1efc);
    param_2[0x1b4] = *(undefined4 *)(param_1 + 0x1f04);
    param_2[0x1b5] = *(undefined4 *)(param_1 + 0x1f00);
    param_2[0x1b6] = *(undefined4 *)(param_1 + 0x1f08);
    FUN_0004acbc(param_2 + 0xfc,iVar3);
    param_2 = param_2 + 0x1b9;
    if (bVar4) {
      *(undefined4 **)(param_1 + 0x298c) = param_2;
      (**(code **)(param_1 + 0x299c))(iVar3,param_2);
    }
  }
  return param_2;
}

/* FUN_00021412 @ 0x21412 (8 bytes) */
int FUN_00021412(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  return param_2;
}

/* FUN_0002141a @ 0x2141a (349 bytes) */
int FUN_0002141a(param_1, param_2, param_3)
  int param_1;
  uint *param_2;
  undefined4 *param_3;
{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint *local_1c;
  uint local_10;
  
  *param_3 = 0x308c8;
  param_3[1] = param_2[0xc];
  param_3[2] = param_2[0xd];
  param_3[3] = param_2[0xe];
  param_3[4] = param_2[0xf];
  puVar1 = param_3 + 5;
  uVar2 = *(uint *)(param_1 + 0x1ca0);
  if ((uVar2 & 8) != 0) {
    if (*(char *)(*(int *)(*(int *)(param_1 + 4) + 0x10) + 0x2e0a) == '\0') {
      param_3[5] = 0x208cc;
      param_3[6] = param_2[0x14];
      param_3[7] = param_2[0x15];
      param_3[8] = param_2[0x16];
      puVar1 = param_3 + 9;
      uVar2 = *(uint *)(param_1 + 0x1ca0);
    }
    else {
      param_3[5] = 0x308cc;
      param_3[6] = param_2[0x14];
      param_3[7] = param_2[0x15];
      param_3[8] = param_2[0x16];
      param_3[9] = param_2[0x13];
      puVar1 = param_3 + 10;
      uVar2 = *(uint *)(param_1 + 0x1ca0);
    }
  }
  iVar3 = 10;
  local_10 = 0x8e8;
  local_1c = param_2;
  while( true ) {
    if ((1 << ((byte)iVar3 & 0x1f) & uVar2) != 0) {
      *puVar1 = local_10 | 0x30000;
      puVar1[1] = local_1c[0x20];
      puVar1[2] = local_1c[0x21];
      puVar1[3] = local_1c[0x22];
      puVar1[4] = local_1c[0x23];
      puVar1 = puVar1 + 5;
    }
    iVar3 = iVar3 + 1;
    local_10 = local_10 + 4;
    local_1c = local_1c + 4;
    if (iVar3 == 0x12) break;
    uVar2 = *(uint *)(param_1 + 0x1ca0);
  }
  *puVar1 = 0x917;
  puVar1[1] = (uint)((char)param_2[0x1f] != '\0');
  puVar1[2] = 0x308c0;
  puVar1[3] = *param_2;
  puVar1[4] = param_2[1];
  puVar1[5] = param_2[2];
  puVar1[6] = param_2[3];
  return puVar1 + 7;
}

/* FUN_00021577 @ 0x21577 (388 bytes) */
int FUN_00021577(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  uint param_2;
  int param_3;
  uint *param_4;
{
  uint uVar1;
  int local_1c;
  int local_14;
  uint local_10;
  
  if ((param_2 & 2) != 0) {
    *param_4 = 0x208c4;
    param_4[1] = *(uint *)(param_3 + 0x40);
    param_4[2] = *(uint *)(param_3 + 0x44);
    param_4[3] = *(uint *)(param_3 + 0x48);
    param_4 = param_4 + 4;
  }
  if ((param_2 & 4) != 0) {
    *param_4 = 0x308c8;
    param_4[1] = *(uint *)(param_3 + 0x30);
    param_4[2] = *(uint *)(param_3 + 0x34);
    param_4[3] = *(uint *)(param_3 + 0x38);
    param_4[4] = *(uint *)(param_3 + 0x3c);
    param_4 = param_4 + 5;
  }
  if ((param_2 & 8) != 0) {
    *param_4 = 0x208cc;
    param_4[1] = *(uint *)(param_3 + 0x50);
    param_4[2] = *(uint *)(param_3 + 0x54);
    param_4[3] = *(uint *)(param_3 + 0x58);
    param_4 = param_4 + 4;
  }
  local_14 = 0;
  local_10 = 0x8e8;
  local_1c = param_3;
  do {
    uVar1 = 0x400 << ((byte)local_14 & 0x1f);
    if ((uVar1 & param_2) != 0) {
      *param_4 = local_10 | 0x30000;
      param_4[1] = *(uint *)(local_1c + 0x80);
      param_4[2] = *(uint *)(local_1c + 0x84);
      param_4[3] = *(uint *)(local_1c + 0x88);
      param_4[4] = *(uint *)(local_1c + 0x8c);
      param_4 = param_4 + 5;
      param_2 = param_2 & ~uVar1;
    }
    if ((param_2 & 0x3fc00) == 0) break;
    local_14 = local_14 + 1;
    local_10 = local_10 + 4;
    local_1c = local_1c + 0x10;
  } while (local_14 != 8);
  if ((param_2 & 0x40000) != 0) {
    *param_4 = 0x908;
    param_4[1] = *(uint *)(param_3 + 0x5c);
    param_4 = param_4 + 2;
  }
  if ((param_2 & 0x80000) != 0) {
    *param_4 = 0x3090c;
    param_4[1] = *(uint *)(param_3 + 0x60);
    param_4[2] = *(uint *)(param_3 + 100);
    param_4[3] = *(uint *)(param_3 + 0x68);
    param_4[4] = *(uint *)(param_3 + 0x6c);
    param_4 = param_4 + 5;
  }
  *param_4 = 0x917;
  param_4[1] = (uint)(*(char *)(param_3 + 0x7c) != '\0');
  param_4[2] = 0x308c0;
  param_4[3] = *(uint *)(param_3 + 0x20);
  param_4[4] = *(uint *)(param_3 + 0x24);
  param_4[5] = *(uint *)(param_3 + 0x28);
  param_4[6] = *(uint *)(param_3 + 0x2c);
  return param_4 + 7;
}

/* FUN_000216fb @ 0x216fb (1803 bytes) */
int FUN_000216fb(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = *(undefined4 *)(param_1 + 4);
  iVar3 = param_4;
  if (param_2 == 5) {
    iVar3 = param_4 + 1;
  }
  puVar1 = (undefined4 *)
           (**(code **)(param_1 + 0x2758))
                     (param_1,(*(int *)(param_1 + 0x243c) + 1U & 0xfffffffe) +
                              *(int *)(param_1 + 0x243c) * iVar3 * 5 + 0x16 + iVar3 * 2);
  *(undefined4 **)(param_1 + 0x274c) = puVar1;
  if (*(int *)(param_1 + 0x2440) != param_1 + 0x1be4) {
    *(int *)(param_1 + 0x2440) = param_1 + 0x1be4;
    *(int *)(param_1 + 0x2444) = param_1 + 0x1c04;
    *(undefined4 *)(param_1 + 0x248c) = *(undefined4 *)(param_1 + 0x1ca4);
    puVar1 = (undefined4 *)FUN_0002a122(uVar2,puVar1);
  }
  if (*(char *)(param_1 + 0x2802) == '\0') {
    *puVar1 = 0x5c8;
    puVar1[1] = 0x10000000;
    puVar1 = puVar1 + 2;
    *(undefined1 *)(param_1 + 0x2802) = 1;
  }
  *puVar1 = 0x82c;
  puVar1[1] = *(undefined4 *)(param_1 + 0x1b84);
  puVar1[2] = 0x821;
  puVar1[3] = param_2;
  puVar1 = puVar1 + 4;
  if (*(char *)(*(int *)(param_1 + 4) + 0x20) == '\0') {
    if (param_2 == 5) {
      puVar1 = (undefined4 *)((int (*)())FUN_0002141a)();
    }
    if (param_4 == 0x24) {
      ((int (*)())FUN_0002141a)();
      ((int (*)())FUN_0002141a)();
      ((int (*)())FUN_0002141a)();
      ((int (*)())FUN_0002141a)();
      ((int (*)())FUN_0002141a)();
      ((int (*)())FUN_0002141a)();
      ((int (*)())FUN_0002141a)();
      ((int (*)())FUN_0002141a)();
      ((int (*)())FUN_0002141a)();
      ((int (*)())FUN_0002141a)();
      ((int (*)())FUN_0002141a)();
      ((int (*)())FUN_0002141a)();
      ((int (*)())FUN_0002141a)();
      ((int (*)())FUN_0002141a)();
      ((int (*)())FUN_0002141a)();
      ((int (*)())FUN_0002141a)();
      ((int (*)())FUN_0002141a)();
      ((int (*)())FUN_0002141a)();
      ((int (*)())FUN_0002141a)();
      ((int (*)())FUN_0002141a)();
      ((int (*)())FUN_0002141a)();
      ((int (*)())FUN_0002141a)();
      ((int (*)())FUN_0002141a)();
      ((int (*)())FUN_0002141a)();
      ((int (*)())FUN_0002141a)();
      ((int (*)())FUN_0002141a)();
      ((int (*)())FUN_0002141a)();
      ((int (*)())FUN_0002141a)();
      ((int (*)())FUN_0002141a)();
      ((int (*)())FUN_0002141a)();
      ((int (*)())FUN_0002141a)();
      ((int (*)())FUN_0002141a)();
      ((int (*)())FUN_0002141a)();
      ((int (*)())FUN_0002141a)();
      ((int (*)())FUN_0002141a)();
      puVar1 = (undefined4 *)((int (*)())FUN_0002141a)();
    }
    else if (0 < param_4) {
      iVar3 = 0;
      do {
        puVar1 = (undefined4 *)((int (*)())FUN_0002141a)();
        iVar3 = iVar3 + 1;
      } while (param_4 != iVar3);
    }
  }
  else {
    if (param_2 == 5) {
      puVar1 = (undefined4 *)((int (*)())FUN_00021577)(puVar1);
    }
    if (param_4 == 0x24) {
      uVar2 = ((int (*)())FUN_00021577)(puVar1);
      uVar2 = ((int (*)())FUN_00021577)(uVar2);
      uVar2 = ((int (*)())FUN_00021577)(uVar2);
      uVar2 = ((int (*)())FUN_00021577)(uVar2);
      uVar2 = ((int (*)())FUN_00021577)(uVar2);
      uVar2 = ((int (*)())FUN_00021577)(uVar2);
      uVar2 = ((int (*)())FUN_00021577)(uVar2);
      uVar2 = ((int (*)())FUN_00021577)(uVar2);
      uVar2 = ((int (*)())FUN_00021577)(uVar2);
      uVar2 = ((int (*)())FUN_00021577)(uVar2);
      uVar2 = ((int (*)())FUN_00021577)(uVar2);
      uVar2 = ((int (*)())FUN_00021577)(uVar2);
      uVar2 = ((int (*)())FUN_00021577)(uVar2);
      uVar2 = ((int (*)())FUN_00021577)(uVar2);
      uVar2 = ((int (*)())FUN_00021577)(uVar2);
      uVar2 = ((int (*)())FUN_00021577)(uVar2);
      uVar2 = ((int (*)())FUN_00021577)(uVar2);
      uVar2 = ((int (*)())FUN_00021577)(uVar2);
      uVar2 = ((int (*)())FUN_00021577)(uVar2);
      uVar2 = ((int (*)())FUN_00021577)(uVar2);
      uVar2 = ((int (*)())FUN_00021577)(uVar2);
      uVar2 = ((int (*)())FUN_00021577)(uVar2);
      uVar2 = ((int (*)())FUN_00021577)(uVar2);
      uVar2 = ((int (*)())FUN_00021577)(uVar2);
      uVar2 = ((int (*)())FUN_00021577)(uVar2);
      uVar2 = ((int (*)())FUN_00021577)(uVar2);
      uVar2 = ((int (*)())FUN_00021577)(uVar2);
      uVar2 = ((int (*)())FUN_00021577)(uVar2);
      uVar2 = ((int (*)())FUN_00021577)(uVar2);
      uVar2 = ((int (*)())FUN_00021577)(uVar2);
      uVar2 = ((int (*)())FUN_00021577)(uVar2);
      uVar2 = ((int (*)())FUN_00021577)(uVar2);
      uVar2 = ((int (*)())FUN_00021577)(uVar2);
      uVar2 = ((int (*)())FUN_00021577)(uVar2);
      uVar2 = ((int (*)())FUN_00021577)(uVar2);
      puVar1 = (undefined4 *)((int (*)())FUN_00021577)(uVar2);
    }
    else if (0 < param_4) {
      iVar3 = 0;
      do {
        puVar1 = (undefined4 *)((int (*)())FUN_00021577)(puVar1);
        iVar3 = iVar3 + 1;
      } while (param_4 != iVar3);
    }
  }
  *puVar1 = 0x92b;
  puVar1[1] = 0;
  puVar1[2] = 0x1393;
  puVar1[3] = 0;
  *(undefined4 **)(param_1 + 0x274c) = puVar1 + 4;
                    
                    
  (**(code **)(param_1 + 0x275c))();
  return;
}

/* FUN_00021e06 @ 0x21e06 (285 bytes) */
int FUN_00021e06(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  uVar1 = *(undefined4 *)(param_1 + 4);
  puVar2 = (undefined4 *)
           (**(code **)(param_1 + 0x2758))
                     (param_1,(*(int *)(param_1 + 0x243c) + 1U & 0xfffffffe) +
                              *(int *)(param_1 + 0x243c) * param_3 * 5 + 0x16 + param_3 * 2);
  *(undefined4 **)(param_1 + 0x274c) = puVar2;
  if (*(int *)(param_1 + 0x2440) != param_1 + 0x1be4) {
    *(int *)(param_1 + 0x2440) = param_1 + 0x1be4;
    *(int *)(param_1 + 0x2444) = param_1 + 0x1c04;
    *(undefined4 *)(param_1 + 0x248c) = *(undefined4 *)(param_1 + 0x1ca4);
    puVar2 = (undefined4 *)FUN_0002a122(uVar1,puVar2);
  }
  if (*(char *)(param_1 + 0x2802) == '\0') {
    *puVar2 = 0x5c8;
    puVar2[1] = 0x10000000;
    puVar2 = puVar2 + 2;
    *(undefined1 *)(param_1 + 0x2802) = 1;
  }
  *puVar2 = 0x82c;
  puVar2[1] = *(undefined4 *)(param_1 + 0x1b84);
  puVar2[2] = 0x821;
  puVar2[3] = param_2;
  puVar2 = puVar2 + 4;
  if (param_3 != 0) {
    uVar3 = 0;
    do {
      puVar2 = (undefined4 *)((int (*)())FUN_0002141a)();
      uVar3 = uVar3 + 1;
    } while (uVar3 < param_3);
  }
  *puVar2 = 0x92b;
  puVar2[1] = 0;
  puVar2[2] = 0x1393;
  puVar2[3] = 0;
  *(undefined4 **)(param_1 + 0x274c) = puVar2 + 4;
                    
                    
  (**(code **)(param_1 + 0x275c))();
  return;
}

/* FUN_00021f23 @ 0x21f23 (100 bytes) */
int FUN_00021f23(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  
  iVar1 = FUN_0002ab76(param_1,0,4,param_3);
  if (iVar1 == 0) {
    return;
  }
  ((int (*)())FUN_000216fb)();
  return;
}

/* FUN_00021f87 @ 0x21f87 (100 bytes) */
int FUN_00021f87(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  
  iVar1 = FUN_0002ab76(param_1,0,5,param_3);
  if (iVar1 == 0) {
    return;
  }
  ((int (*)())FUN_000216fb)();
  return;
}

/* FUN_00021feb @ 0x21feb (107 bytes) */
int FUN_00021feb(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  int iVar1;
  
  iVar1 = FUN_0002ab76(param_1,0,6,param_4);
  if (iVar1 == 0) {
    return;
  }
  ((int (*)())FUN_000216fb)();
  return;
}

/* FUN_00022056 @ 0x22056 (100 bytes) */
int FUN_00022056(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  
  iVar1 = FUN_0002ab76(param_1,0,7,param_3);
  if (iVar1 == 0) {
    return;
  }
  ((int (*)())FUN_000216fb)();
  return;
}

/* FUN_000220ba @ 0x220ba (100 bytes) */
int FUN_000220ba(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  
  iVar1 = FUN_0002ab76(param_1,0,8,param_3);
  if (iVar1 == 0) {
    return;
  }
  ((int (*)())FUN_000216fb)();
  return;
}

/* FUN_0002211e @ 0x2211e (100 bytes) */
int FUN_0002211e(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  
  iVar1 = FUN_0002ab76(param_1,0,9,param_3);
  if (iVar1 == 0) {
    return;
  }
  ((int (*)())FUN_000216fb)();
  return;
}

/* FUN_00022182 @ 0x22182 (95 bytes) */
int FUN_00022182(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  
  iVar1 = FUN_0002ab76(param_1,0,9,param_3);
  if (iVar1 == 0) {
    return;
  }
  ((int (*)())FUN_00021e06)();
  return;
}

/* FUN_000221e1 @ 0x221e1 (95 bytes) */
int FUN_000221e1(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  
  iVar1 = FUN_0002ab76(param_1,0,0,param_3);
  if (iVar1 == 0) {
    return;
  }
  ((int (*)())FUN_000216fb)();
  return;
}

/* FUN_00022240 @ 0x22240 (92 bytes) */
int FUN_00022240(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  
  iVar1 = FUN_0002ab76(param_1,0,0,param_3);
  if (iVar1 == 0) {
    return;
  }
  ((int (*)())FUN_00021e06)();
  return;
}

/* FUN_0002229c @ 0x2229c (95 bytes) */
int FUN_0002229c(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  
  iVar1 = FUN_0002ab76(param_1,0,1,param_3);
  if (iVar1 == 0) {
    return;
  }
  ((int (*)())FUN_000216fb)();
  return;
}

/* FUN_000222fb @ 0x222fb (92 bytes) */
int FUN_000222fb(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  
  iVar1 = FUN_0002ab76(param_1,0,1,param_3);
  if (iVar1 == 0) {
    return;
  }
  ((int (*)())FUN_00021e06)();
  return;
}

/* FUN_00022357 @ 0x22357 (96 bytes) */
int FUN_00022357(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  int iVar1;
  
  iVar1 = FUN_0002ab76(param_1,param_4,2,param_3);
  if (iVar1 == 0) {
    return;
  }
  ((int (*)())FUN_000216fb)();
  return;
}

/* FUN_000223b7 @ 0x223b7 (96 bytes) */
int FUN_000223b7(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  int iVar1;
  
  iVar1 = FUN_0002ab76(param_1,param_4,3,param_3);
  if (iVar1 == 0) {
    return;
  }
  ((int (*)())FUN_000216fb)();
  return;
}

/* FUN_00022417 @ 0x22417 (1430 bytes) */
int FUN_00022417(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  undefined4 param_5;
  int param_6;
  uint *param_7;
{
  int iVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  uint *puVar7;
  int iVar8;
  undefined4 *puVar9;
  uint uVar10;
  undefined4 *puVar11;
  uint uVar12;
  uint local_38;
  uint *local_30;
  uint local_2c;
  
  bVar2 = *(byte *)(param_1 + 8);
  iVar5 = FUN_0002ab76(param_1,1,param_3,param_5);
  if (iVar5 == 0) {
    return;
  }
  *(undefined4 *)(param_2 + -0x68) = *(undefined4 *)(*(int *)(param_1 + 0x244) + 0x23c);
  iVar8 = iVar5 + 1 >> 1;
  uVar12 = iVar8 + 0x1f;
  puVar6 = (uint *)(**(code **)(param_1 + 0x2998))(param_1 + 0x240,uVar12);
  *(uint **)(param_1 + 0x298c) = puVar6;
  uVar12 = uVar12 >> (bVar2 != 0x20) * '\x02' + 5;
  if (1 < uVar12) {
    uVar10 = 1;
    puVar7 = puVar6;
    do {
      puVar7 = (uint *)((uint)bVar2 + (int)puVar7);
      *puVar7 = 0;
      puVar7[1] = 0;
      puVar7[2] = 0;
      puVar7[3] = 0;
      puVar7[4] = 0;
      puVar7[5] = 0;
      puVar7[6] = 0;
      puVar7[7] = 0;
      uVar10 = uVar10 + 1;
    } while (uVar12 != uVar10);
  }
  puVar11 = (undefined4 *)((uint)(puVar6 + 0xb) & 0xffffffe0);
  *puVar6 = (((int)puVar11 - (int)puVar6) + -8) * 0x4000 | 0xc0001000;
  puVar11[-1] = (int)puVar11 - (int)puVar6;
  iVar1 = *(int *)(param_2 + -0x74) * 0x14;
  puVar6 = *(uint **)(param_1 + 0x1d8);
  *puVar6 = *puVar6 | (int)puVar11 - (int)puVar6 >> 2;
  *(undefined4 **)(param_1 + 0x1d8) = puVar11;
  *puVar11 = 0x26000000;
  puVar11[1] = **(undefined4 **)(param_2 + -100);
  puVar11[2] = 0x20830;
  puVar11[3] = 0x21;
  puVar11[4] = *(undefined4 *)(&DAT_001ec4cc + iVar1);
  puVar11[5] = 0;
  puVar11[6] = 0x10854;
  puVar11[7] = *(undefined4 *)(&DAT_001ec4d0 + iVar1);
  puVar11[8] = *(undefined4 *)(&DAT_001ec4d4 + iVar1);
  puVar11[9] = 0x10878;
  puVar11[10] = *(undefined4 *)(&DAT_001ec4d8 + iVar1);
  puVar11[0xb] = *(undefined4 *)(&DAT_001ec4dc + iVar1);
  puVar9 = puVar11 + 0xc;
  if (*(char *)(param_1 + 0x2a42) != '\0') {
    puVar11[0xc] = 0x5c8;
    puVar11[0xd] = 0x10000000;
    puVar9 = puVar11 + 0xe;
    *(undefined1 *)(param_1 + 0x2a42) = 0;
  }
  bVar2 = (DAT_001ec540)[param_3 * 4];
  *puVar9 = 0x82c;
  puVar9[1] = *(undefined4 *)(param_1 + 0x1dc4);
  puVar9[2] = iVar8 << 0x10 | 0xc0003600;
  puVar9[3] = bVar2 & 0xf | 0x10 | iVar5 << 0x10;
  local_30 = puVar9 + 4;
  uVar12 = iVar5 - 1;
  if (param_6 == 0x1403) {
    if (uVar12 == 0) {
      uVar10 = 0;
    }
    else {
      uVar10 = 0;
      puVar6 = param_7;
      do {
        *(uint *)((int)local_30 + uVar10 * 2) =
             (uint)(ushort)*puVar6 - param_4 & 0xffff |
             ((uint)*(ushort *)((int)puVar6 + 2) - param_4) * 0x10000;
        uVar10 = uVar10 + 2;
        puVar6 = puVar6 + 1;
      } while (uVar10 < uVar12);
      local_30 = (uint *)((int)local_30 + uVar10 * 2);
    }
    if ((uVar12 & 1) != 0) goto LAB_00022641;
    uVar12 = (uint)*(ushort *)((int)param_7 + uVar10 * 2);
  }
  else if (param_6 == 0x1405) {
    uVar10 = (int)uVar12 >> 4;
    if (param_4 == 0) {
      if (uVar10 != 0) {
        local_2c = 0;
        do {
          uVar3 = param_7[2];
          uVar4 = param_7[3];
          *local_30 = param_7[1] << 0x10 | *param_7;
          local_30[1] = uVar3 | uVar4 << 0x10;
          uVar3 = param_7[6];
          uVar4 = param_7[7];
          local_30[2] = param_7[5] << 0x10 | param_7[4];
          local_30[3] = uVar3 | uVar4 << 0x10;
          uVar3 = param_7[10];
          uVar4 = param_7[0xb];
          local_30[4] = param_7[9] << 0x10 | param_7[8];
          local_30[5] = uVar3 | uVar4 << 0x10;
          puVar6 = param_7 + 0xc;
          puVar7 = param_7 + 0xd;
          uVar3 = param_7[0xe];
          uVar4 = param_7[0xf];
          param_7 = param_7 + 0x10;
          local_30[6] = *puVar6 | *puVar7 << 0x10;
          local_30[7] = uVar3 | uVar4 << 0x10;
          local_30 = local_30 + 8;
          local_2c = local_2c + 1;
        } while (local_2c < uVar10);
      }
      if ((uVar12 & 0xf) != 0) {
        uVar10 = 0;
        do {
          uVar3 = *param_7;
          puVar6 = param_7 + 1;
          param_7 = param_7 + 2;
          *local_30 = uVar3 | *puVar6 << 0x10;
          local_30 = local_30 + 1;
          uVar10 = uVar10 + 2;
        } while (uVar10 < (uVar12 & 0xf));
      }
      if ((uVar12 & 1) == 0) {
        *local_30 = (uint)(ushort)*param_7;
        local_30 = local_30 + 1;
      }
      goto LAB_00022641;
    }
    if (uVar10 != 0) {
      local_38 = 0;
      do {
        uVar3 = param_7[2];
        uVar4 = param_7[3];
        *local_30 = *param_7 - param_4 | (param_7[1] - param_4) * 0x10000;
        local_30[1] = uVar3 - param_4 | (uVar4 - param_4) * 0x10000;
        uVar3 = param_7[6];
        uVar4 = param_7[7];
        local_30[2] = (param_7[5] - param_4) * 0x10000 | param_7[4] - param_4 & 0xffff;
        local_30[3] = (uVar4 - param_4) * 0x10000 | uVar3 - param_4 & 0xffff;
        uVar3 = param_7[10];
        uVar4 = param_7[0xb];
        local_30[4] = (param_7[9] - param_4) * 0x10000 | param_7[8] - param_4 & 0xffff;
        local_30[5] = (uVar4 - param_4) * 0x10000 | uVar3 - param_4 & 0xffff;
        puVar6 = param_7 + 0xc;
        puVar7 = param_7 + 0xd;
        uVar3 = param_7[0xe];
        uVar4 = param_7[0xf];
        param_7 = param_7 + 0x10;
        local_30[6] = (*puVar7 - param_4) * 0x10000 | *puVar6 - param_4 & 0xffff;
        local_30[7] = (uVar4 - param_4) * 0x10000 | uVar3 - param_4 & 0xffff;
        local_30 = local_30 + 8;
        local_38 = local_38 + 1;
      } while (local_38 < uVar10);
    }
    if ((uVar12 & 0xf) != 0) {
      uVar10 = 0;
      do {
        uVar3 = *param_7;
        puVar6 = param_7 + 1;
        param_7 = param_7 + 2;
        *local_30 = (*puVar6 - param_4) * 0x10000 | uVar3 - param_4 & 0xffff;
        local_30 = local_30 + 1;
        uVar10 = uVar10 + 2;
      } while (uVar10 < (uVar12 & 0xf));
    }
    if ((uVar12 & 1) != 0) goto LAB_00022641;
    uVar12 = *param_7;
  }
  else {
    if (param_6 != 0x1401) goto LAB_00022641;
    uVar10 = 0;
    if (uVar12 != 0) {
      uVar10 = 0;
      do {
        *(uint *)((int)local_30 + uVar10 * 2) =
             (uint)*(byte *)((int)param_7 + uVar10) - param_4 & 0xffff |
             ((uint)((byte *)((int)param_7 + uVar10))[1] - param_4) * 0x10000;
        uVar10 = uVar10 + 2;
      } while (uVar10 < uVar12);
      local_30 = (uint *)((int)local_30 + uVar10 * 2);
    }
    if ((uVar12 & 1) != 0) goto LAB_00022641;
    uVar12 = (uint)*(byte *)((int)param_7 + uVar10);
  }
  *local_30 = uVar12 - param_4 & 0xffff;
  local_30 = local_30 + 1;
LAB_00022641:
  *local_30 = 0x1393;
  local_30[1] = 0;
  *(uint **)(param_1 + 0x298c) = local_30 + 2;
  (**(code **)(param_1 + 0x299c))(param_1 + 0x240,local_30 + 2);
  *(undefined4 *)(param_1 + 0x26d4) = 0;
  *(int *)(param_1 + 0x2680) = param_1 + 0x26dc;
  *(int *)(param_1 + 0x2684) = param_1 + 0x26fc;
  *(undefined1 *)(param_1 + 0x27d5) = 1;
  *(undefined1 *)(param_1 + 0x2a5e) = 1;
  return;
}

/* FUN_000229b0 @ 0x229b0 (17 bytes) */
int FUN_000229b0(param_1)
  int param_1;
{
  *(int *)(param_1 + 0x2c) = param_1 + 0x2c;
  *(int *)(param_1 + 0x30) = param_1 + 0x2c;
  return;
}

/* FUN_000229c1 @ 0x229c1 (5 bytes) */
int FUN_000229c1()
{
  return;
}

/* FUN_000229c6 @ 0x229c6 (5 bytes) */
int FUN_000229c6()
{
  return;
}

/* FUN_000229cb @ 0x229cb (3072 bytes) */
int FUN_000229cb(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 *param_3;
{
  float *pfVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  uint uVar9;
  float *pfVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  dword *pdVar14;
  int *piVar15;
  uint uVar16;
  int iVar17;
  dword *pdVar18;
  dword *pdVar19;
  bool bVar20;
  float fVar21;
  float fVar22;
  int *local_58;
  uint *local_50;
  int local_40;
  int local_3c;
  undefined4 *local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20 [4];
  
  local_58 = *(int **)(*(int *)(param_1 + 0x18) + 0x19c);
  bVar20 = local_58 == (int *)0x0;
  if (bVar20) {
    local_58 = *(int **)(*(int *)(param_1 + 0x18) + 400);
  }
  iVar13 = local_58[0xd];
  if (((iVar13 == 0) && (iVar13 = local_58[0xc], iVar13 == 0)) &&
     (iVar13 = local_58[0xb], iVar13 == 0)) {
    iVar17 = *local_58;
    iVar13 = *(int *)(iVar17 + 4);
  }
  else {
    iVar17 = *local_58;
  }
  local_50 = (uint *)(iVar13 + *(int *)(iVar13 + 0x2c) * 8);
  iVar4 = *(int *)(iVar13 + 0x6c);
  iVar17 = *(int *)(iVar17 + 0x18);
  if (*(int *)(iVar13 + 0x28) <= param_2) {
    param_2 = *(int *)(iVar13 + 0x28);
  }
  if (0 < param_2) {
    local_40 = 0;
    local_30 = param_3 + 4;
    do {
      while( true ) {
        bVar6 = *(byte *)((int)local_50 + 1) & 0xf8;
        param_3 = local_30;
        if (bVar6 == 0) goto LAB_00022acd;
        if (bVar6 != 0x88) break;
        piVar15 = (int *)(iVar13 + iVar4 * 8 + (uint)*(ushort *)((int)local_50 + 2) * 0x10);
LAB_00022b9f:
        if ((bVar20) || (bVar6 = (byte)*local_50 & 0x38, bVar6 == 8)) {
          local_30[-4] = *piVar15;
          local_30[-3] = piVar15[1];
          local_30[-2] = piVar15[2];
          local_30[-1] = piVar15[3];
        }
        else if (bVar6 == 0x18) {
          local_30[-4] = (float)*piVar15;
          local_30[-3] = (float)piVar15[1];
          local_30[-2] = (float)piVar15[2];
          local_30[-1] = (float)piVar15[3];
        }
        else {
          if (*piVar15 == 0) {
            local_30[-4] = 0;
            if (piVar15[1] == 0) goto LAB_00022e2f;
LAB_00022be2:
            local_30[-3] = 0x3f800000;
            if (piVar15[2] != 0) goto LAB_00022bf8;
LAB_00022e1b:
            local_30[-2] = 0;
            if (piVar15[3] == 0) goto LAB_00022e14;
LAB_00022c09:
            uVar7 = 0x3f800000;
          }
          else {
            local_30[-4] = 0x3f800000;
            if (piVar15[1] != 0) goto LAB_00022be2;
LAB_00022e2f:
            local_30[-3] = 0;
            if (piVar15[2] == 0) goto LAB_00022e1b;
LAB_00022bf8:
            local_30[-2] = 0x3f800000;
            if (piVar15[3] != 0) goto LAB_00022c09;
LAB_00022e14:
            uVar7 = 0;
          }
          local_30[-1] = uVar7;
        }
joined_r0x00022d3e:
        local_50 = local_50 + 2;
        local_40 = local_40 + 1;
        local_30 = local_30 + 4;
        if (param_2 == local_40) goto LAB_00022aeb;
      }
      if (bVar6 == 8) {
        piVar15 = (int *)(iVar17 + (uint)*(ushort *)((int)local_50 + 2) * 0x10);
        goto LAB_00022b9f;
      }
      if (bVar6 == 0x10) {
        puVar8 = (undefined4 *)
                 ((uint)*(ushort *)((int)local_50 + 2) * 0x10 +
                 *(int *)(*(int *)(param_1 + 0x10) + 0x4310));
        local_30[-4] = *puVar8;
        local_30[-3] = puVar8[1];
        local_30[-2] = puVar8[2];
        local_30[-1] = puVar8[3];
        goto joined_r0x00022d3e;
      }
      uVar9 = *local_50;
      if (((byte)(uVar9 >> 8) & 0xf8) == 0x80) {
        uVar16 = uVar9 >> 0x12 & 3;
        uVar11 = uVar9 >> 0x18;
        switch(uVar9 >> 0x15 & 7) {
        default:
          iVar12 = 0;
          break;
        case 1:
          iVar12 = 0xc0;
          break;
        case 2:
          iVar12 = 0x80;
          break;
        case 3:
          iVar12 = (uVar11 + 4) * 0x40;
          break;
        case 4:
          iVar12 = (uVar11 + 0x10) * 0x40;
          break;
        case 5:
          iVar12 = (uVar11 + 8) * 0x40;
        }
        uVar9 = uVar9 >> 0x10 & 3;
        local_3c = *(int *)(param_1 + 0x10) + 0x1860 + iVar12;
        if ((1 < uVar9) && (local_3c = *(int *)(param_1 + 0x10) + 0x1e60 + iVar12, 3 < uVar9)) {
          local_3c = 0;
        }
        if (uVar9 < 3) {
          if (uVar9 == 0) {
LAB_00022e87:
            iVar12 = uVar16 * 4;
            local_2c = *(float *)(local_3c + iVar12);
            iVar12 = iVar12 + local_3c;
            local_28 = *(float *)(iVar12 + 0x10);
            local_24 = *(float *)(iVar12 + 0x20);
            local_20[0] = *(float *)(iVar12 + 0x30);
          }
          else {
            iVar12 = uVar16 * 0x10;
            local_2c = *(float *)(local_3c + iVar12);
            iVar12 = iVar12 + local_3c;
            local_28 = *(float *)(iVar12 + 4);
            local_24 = *(float *)(iVar12 + 8);
            local_20[0] = *(float *)(iVar12 + 0xc);
          }
        }
        else if (uVar9 == 3) goto LAB_00022e87;
        goto LAB_00022ab2;
      }
      switch(uVar9 >> 0xb & 0x1f) {
      case 0:
        pdVar19 = (dword *)&local_28;
        pdVar18 = (dword *)&local_24;
        pdVar14 = (dword *)local_20;
        pfVar10 = &local_2c;
        break;
      default:
switchD_00022c98_caseD_1:
        pfVar10 = (float *)0x0;
        pdVar19 = &MACH_HEADER.cputype;
        pdVar18 = &MACH_HEADER.cpusubtype;
        pdVar14 = &MACH_HEADER.filetype;
        break;
      case 2:
        pfVar10 = (float *)((uVar9 >> 0x10) * 0x10 + *(int *)(*(int *)(param_1 + 0x10) + 0x4308));
        pdVar19 = (dword *)(pfVar10 + 1);
        pdVar18 = (dword *)(pfVar10 + 2);
        pdVar14 = (dword *)(pfVar10 + 3);
        break;
      case 3:
        uVar11 = uVar9 >> 0x18;
        switch(uVar9 >> 0x14 & 0xf) {
        case 0:
          pfVar10 = (float *)(uVar11 * 0x80 + 0x24c0 + *(int *)(param_1 + 0x10));
          pdVar19 = (dword *)(pfVar10 + 1);
          pdVar18 = (dword *)(pfVar10 + 2);
          pdVar14 = (dword *)(pfVar10 + 3);
          break;
        case 1:
          pfVar10 = (float *)(uVar11 * 0x80 + 0x24d0 + *(int *)(param_1 + 0x10));
          pdVar19 = (dword *)(pfVar10 + 1);
          pdVar18 = (dword *)(pfVar10 + 2);
          pdVar14 = (dword *)(pfVar10 + 3);
          break;
        case 2:
          pfVar10 = (float *)(uVar11 * 0x80 + 0x24e0 + *(int *)(param_1 + 0x10));
          pdVar19 = (dword *)(pfVar10 + 1);
          pdVar18 = (dword *)(pfVar10 + 2);
          pdVar14 = (dword *)(pfVar10 + 3);
          break;
        case 3:
          pfVar10 = (float *)(uVar11 * 0x80 + 0x24f0 + *(int *)(param_1 + 0x10));
          pdVar19 = (dword *)(pfVar10 + 1);
          pdVar18 = (dword *)(pfVar10 + 2);
          pdVar14 = (dword *)(pfVar10 + 3);
          break;
        case 4:
          pfVar10 = (float *)(uVar11 * 0x80 + 0x2500 + *(int *)(param_1 + 0x10));
          pdVar19 = (dword *)(pfVar10 + 1);
          pdVar18 = (dword *)(pfVar10 + 2);
          pdVar14 = (dword *)(pfVar10 + 3);
          break;
        case 5:
          pfVar10 = (float *)(uVar11 * 0x80 + 0x2510 + *(int *)(param_1 + 0x10));
          pdVar19 = (dword *)(pfVar10 + 1);
          pdVar18 = (dword *)(pfVar10 + 2);
          pdVar14 = (dword *)(pfVar10 + 3);
          break;
        case 6:
          iVar12 = uVar11 * 0x80 + *(int *)(param_1 + 0x10);
          fVar2 = *(float *)(iVar12 + 0x24f0);
          fVar3 = *(float *)(iVar12 + 0x24f4);
          fVar22 = *(float *)(iVar12 + 0x24f8) + FLOAT_001c5ba4;
          fVar21 = (float)(DOUBLE_001cf330 /
                          SQRT((double)(fVar2 * fVar2 + fVar3 * fVar3 + fVar22 * fVar22)));
          local_2c = fVar2 * fVar21;
          local_28 = fVar3 * fVar21;
          local_24 = fVar22 * fVar21;
          local_20[0] = FLOAT_001c5ba4;
          goto LAB_00022ab2;
        case 7:
          pfVar10 = (float *)(uVar11 * 0x80 + 0x2530 + *(int *)(param_1 + 0x10));
          pdVar19 = (dword *)(pfVar10 + 1);
          pdVar18 = (dword *)(pfVar10 + 2);
          pdVar14 = (dword *)(pfVar10 + 3);
          break;
        default:
          goto switchD_00022c98_caseD_1;
        }
        break;
      case 4:
        pfVar10 = (float *)(*(int *)(param_1 + 0x10) + 0x28c0 + (uVar9 >> 0x17 & 1) * 0x240);
        pfVar1 = (float *)(*(int *)(param_1 + 0x10) + 0x24c0 + (uVar9 >> 0x18) * 0x80);
        uVar9 = uVar9 >> 0x15 & 3;
        if (uVar9 == 1) {
          local_2c = pfVar1[4] * pfVar10[4];
          local_28 = pfVar1[5] * pfVar10[5];
          local_24 = pfVar1[6] * pfVar10[6];
          local_20[0] = pfVar10[7];
        }
        else if (uVar9 == 2) {
          local_2c = pfVar1[8] * pfVar10[8];
          local_28 = pfVar1[9] * pfVar10[9];
          local_24 = pfVar1[10] * pfVar10[10];
          local_20[0] = pfVar10[0xb];
        }
        else {
          if (uVar9 != 0) goto switchD_00022c98_caseD_1;
          local_2c = *pfVar1 * *pfVar10;
          local_28 = pfVar1[1] * pfVar10[1];
          local_24 = pfVar1[2] * pfVar10[2];
          local_20[0] = pfVar10[3];
        }
        goto LAB_00022ab2;
      case 5:
        iVar12 = (int)uVar9 >> 0x1f;
        switch(uVar9 >> 0x1c & 7) {
        case 0:
          pfVar10 = (float *)(iVar12 * -0x240 + 0x28c0 + *(int *)(param_1 + 0x10));
          pdVar19 = (dword *)(pfVar10 + 1);
          pdVar18 = (dword *)(pfVar10 + 2);
          pdVar14 = (dword *)(pfVar10 + 3);
          break;
        case 1:
          pfVar10 = (float *)(iVar12 * -0x240 + 0x28d0 + *(int *)(param_1 + 0x10));
          pdVar19 = (dword *)(pfVar10 + 1);
          pdVar18 = (dword *)(pfVar10 + 2);
          pdVar14 = (dword *)(pfVar10 + 3);
          break;
        case 2:
          pfVar10 = (float *)(iVar12 * -0x240 + 0x28e0 + *(int *)(param_1 + 0x10));
          pdVar19 = (dword *)(pfVar10 + 1);
          pdVar18 = (dword *)(pfVar10 + 2);
          pdVar14 = (dword *)(pfVar10 + 3);
          break;
        case 3:
          pfVar10 = (float *)(iVar12 * -0x240 + 0x28f0 + *(int *)(param_1 + 0x10));
          pdVar19 = (dword *)(pfVar10 + 1);
          pdVar18 = (dword *)(pfVar10 + 2);
          pdVar14 = (dword *)(pfVar10 + 3);
          break;
        case 4:
          pfVar10 = (float *)(iVar12 * -0x240 + 0x2900 + *(int *)(param_1 + 0x10));
          pdVar19 = (dword *)(pfVar10 + 1);
          pdVar18 = (dword *)(pfVar10 + 2);
          pdVar14 = (dword *)(pfVar10 + 3);
          break;
        case 5:
          iVar5 = *(int *)(param_1 + 0x10);
          pfVar10 = (float *)(iVar5 + 0x28c0 + iVar12 * -0x240);
          local_2c = *(float *)(iVar5 + 0x24b0) * *pfVar10 + pfVar10[0xc];
          local_28 = *(float *)(iVar5 + 0x24b4) * pfVar10[1] + pfVar10[0xd];
          local_24 = *(float *)(iVar5 + 0x24b8) * pfVar10[2] + pfVar10[0xe];
          local_20[0] = pfVar10[7];
          goto LAB_00022ab2;
        default:
          goto switchD_00022c98_caseD_1;
        }
        break;
      case 6:
        iVar12 = *(int *)(param_1 + 0x10);
        pfVar10 = (float *)(iVar12 + 0x24b0);
        pdVar19 = (dword *)(iVar12 + 0x24b4);
        pdVar18 = (dword *)(iVar12 + 0x24b8);
        pdVar14 = (dword *)(iVar12 + 0x24bc);
        break;
      case 7:
        uVar11 = uVar9 >> 0x1b;
        uVar9 = uVar9 >> 0x18 & 7;
        if (uVar9 == 1) {
          iVar12 = *(int *)(param_1 + 0x10) + 0x39a0 + uVar11 * 0x94;
          pfVar10 = (float *)(iVar12 + 0x10);
          pdVar19 = (dword *)(iVar12 + 0x14);
          pdVar18 = (dword *)(iVar12 + 0x18);
          pdVar14 = (dword *)(iVar12 + 0x1c);
        }
        else if (uVar9 < 2) {
          if (uVar9 != 0) goto switchD_00022c98_caseD_1;
          iVar12 = *(int *)(param_1 + 0x10) + 0x3980 + uVar11 * 0x94;
          pfVar10 = (float *)(iVar12 + 0xc);
          pdVar19 = (dword *)(iVar12 + 0x10);
          pdVar18 = (dword *)(iVar12 + 0x14);
          pdVar14 = (dword *)(iVar12 + 0x18);
        }
        else if (uVar9 == 2) {
          iVar12 = *(int *)(param_1 + 0x10) + 0x39c0 + uVar11 * 0x94;
          pfVar10 = (float *)(iVar12 + 0x14);
          pdVar19 = (dword *)(iVar12 + 0x18);
          pdVar18 = (dword *)(iVar12 + 0x1c);
          pdVar14 = (dword *)(iVar12 + 0x20);
        }
        else {
          if (uVar9 != 3) goto switchD_00022c98_caseD_1;
          iVar12 = *(int *)(param_1 + 0x10) + 0x39e0 + uVar11 * 0x94;
          pfVar10 = (float *)(iVar12 + 0x18);
          pdVar19 = (dword *)(iVar12 + 0x1c);
          pdVar18 = (dword *)(iVar12 + 0x20);
          pdVar14 = (dword *)(iVar12 + 0x24);
        }
        break;
      case 8:
        uVar11 = uVar9 >> 0x1b;
        uVar9 = uVar9 >> 0x18 & 7;
        if (uVar9 == 1) {
          iVar12 = *(int *)(param_1 + 0x10) + 0x39b0 + uVar11 * 0x94;
          pfVar10 = (float *)(iVar12 + 0x10);
          pdVar19 = (dword *)(iVar12 + 0x14);
          pdVar18 = (dword *)(iVar12 + 0x18);
          pdVar14 = (dword *)(iVar12 + 0x1c);
        }
        else if (uVar9 < 2) {
          if (uVar9 != 0) goto switchD_00022c98_caseD_1;
          iVar12 = *(int *)(param_1 + 0x10) + 0x3990 + uVar11 * 0x94;
          pfVar10 = (float *)(iVar12 + 0xc);
          pdVar19 = (dword *)(iVar12 + 0x10);
          pdVar18 = (dword *)(iVar12 + 0x14);
          pdVar14 = (dword *)(iVar12 + 0x18);
        }
        else if (uVar9 == 2) {
          iVar12 = *(int *)(param_1 + 0x10) + 0x39d0 + uVar11 * 0x94;
          pfVar10 = (float *)(iVar12 + 0x14);
          pdVar19 = (dword *)(iVar12 + 0x18);
          pdVar18 = (dword *)(iVar12 + 0x1c);
          pdVar14 = (dword *)(iVar12 + 0x20);
        }
        else {
          if (uVar9 != 3) goto switchD_00022c98_caseD_1;
          iVar12 = *(int *)(param_1 + 0x10) + 0x39f0 + uVar11 * 0x94;
          pfVar10 = (float *)(iVar12 + 0x18);
          pdVar19 = (dword *)(iVar12 + 0x1c);
          pdVar18 = (dword *)(iVar12 + 0x20);
          pdVar14 = (dword *)(iVar12 + 0x24);
        }
        break;
      case 9:
        iVar12 = (uVar9 >> 0x1b) * 0x7c + 0x31c0 + *(int *)(param_1 + 0x10);
        pfVar10 = (float *)(iVar12 + 4);
        pdVar19 = (dword *)(iVar12 + 8);
        pdVar18 = (dword *)(iVar12 + 0xc);
        pdVar14 = (dword *)(iVar12 + 0x10);
        break;
      case 10:
        iVar12 = (uVar9 >> 0x18) * 0x10 + 0x3e20 + *(int *)(param_1 + 0x10);
        pfVar10 = (float *)(iVar12 + 0xc);
        pdVar19 = (dword *)(iVar12 + 0x10);
        pdVar18 = (dword *)(iVar12 + 0x14);
        pdVar14 = (dword *)(iVar12 + 0x18);
        break;
      case 0xb:
        iVar12 = *(int *)(param_1 + 0x10);
        pfVar10 = (float *)(iVar12 + 0x2de0);
        pdVar19 = (dword *)(iVar12 + 0x2de4);
        pdVar18 = (dword *)(iVar12 + 0x2de8);
        pdVar14 = (dword *)(iVar12 + 0x2dec);
        break;
      case 0xc:
        iVar12 = *(int *)(param_1 + 0x10);
        pfVar10 = (float *)(iVar12 + 0x2df0);
        pdVar19 = (dword *)(iVar12 + 0x2df4);
        pdVar18 = (dword *)(iVar12 + 0x2df8);
        pdVar14 = (dword *)(iVar12 + 0x2dfc);
        break;
      case 0xd:
        iVar12 = *(int *)(param_1 + 0x10);
        pfVar10 = (float *)(iVar12 + 0x30bc);
        pdVar19 = (dword *)(iVar12 + 0x30c0);
        pdVar18 = (dword *)(iVar12 + 0x30c4);
        pdVar14 = (dword *)(iVar12 + 0x30c8);
        break;
      case 0xe:
        iVar12 = *(int *)(param_1 + 0x10);
        pfVar10 = (float *)(iVar12 + 0x30cc);
        pdVar19 = (dword *)(iVar12 + 0x30d0);
        pdVar18 = (dword *)(iVar12 + 0x30d4);
        pdVar14 = (dword *)(iVar12 + 0x30d8);
        break;
      case 0xf:
        iVar12 = *(int *)(param_1 + 0x10);
        local_2c = (float)*(double *)(iVar12 + 0x1830);
        local_28 = (float)*(double *)(iVar12 + 0x1838);
        local_24 = (float)(*(double *)(iVar12 + 0x1838) - *(double *)(iVar12 + 0x1830));
        local_20[0] = 1.0;
        goto LAB_00022ab2;
      case 0x12:
        local_2c = *(float *)(*(int *)(param_1 + 0x10) + 0x24a4);
        local_28 = local_2c;
        local_24 = local_2c;
        local_20[0] = local_2c;
        goto LAB_00022ab2;
      }
      local_2c = *pfVar10;
      local_28 = (float)*pdVar19;
      local_24 = (float)*pdVar18;
      local_20[0] = (float)*pdVar14;
LAB_00022ab2:
      local_30[-4] = local_2c;
      local_30[-3] = local_28;
      local_30[-2] = local_24;
      local_30[-1] = local_20[0];
LAB_00022acd:
      local_40 = local_40 + 1;
      local_50 = local_50 + 2;
      local_30 = local_30 + 4;
    } while (param_2 != local_40);
  }
LAB_00022aeb:
  iVar13 = local_58[0xe];
  if (iVar13 != 0) {
    bVar6 = *(byte *)(iVar13 + 0x20);
    if ((bVar6 & 0x20) != 0) {
      *param_3 = 0x40490fdb;
      param_3[1] = 0x3fc90fdb;
      param_3[2] = 0x3c8efa35;
      param_3[3] = 0x42652ee1;
      param_3 = param_3 + 4;
      bVar6 = *(byte *)(iVar13 + 0x20);
    }
    if ((bVar6 & 0x40) != 0) {
      *param_3 = *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x2de0);
      param_3[1] = *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x2de4);
      param_3[2] = *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x2de8);
      param_3[4] = *(uint *)(*(int *)(param_1 + 0x10) + 0x2dfc) ^ 0x80000000;
      param_3[5] = *(float *)(*(int *)(param_1 + 0x10) + 0x2df8) *
                   *(float *)(*(int *)(param_1 + 0x10) + 0x2dfc);
      param_3[6] = FLOAT_001c5bf8 * *(float *)(*(int *)(param_1 + 0x10) + 0x2df0);
      param_3[7] = FLOAT_001c5bfc * *(float *)(*(int *)(param_1 + 0x10) + 0x2df0);
    }
  }
  return;
}

/* FUN_0002366c @ 0x2366c (417 bytes) */
int FUN_0002366c(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  if (*(int *)(param_2 + 0x1c) == 0) {
    return;
  }
  _pthread_mutex_lock(*(pthread_mutex_t **)(param_1 + 0xc));
  if (*(int *)(param_2 + 0x2c) != 0) {
    _glpFreePPShaderLinearize(*(int *)(param_2 + 0x2c));
    *(undefined4 *)(param_2 + 0x2c) = 0;
  }
  if (*(int *)(param_2 + 0x30) != 0) {
    _glpFreePPShaderToProgram(*(int *)(param_2 + 0x30));
    *(undefined4 *)(param_2 + 0x30) = 0;
  }
  if (*(int *)(param_2 + 0x34) != 0) {
    *(undefined4 *)(param_2 + 0x34) = 0;
  }
  FUN_0003eda2(*(undefined4 *)(param_2 + 0x38));
  *(undefined4 *)(param_2 + 0x38) = 0;
  piVar3 = *(int **)(param_2 + 0x24);
  while (piVar3 != (int *)(param_2 + 0x20)) {
    piVar1 = (int *)piVar3[1];
    iVar2 = *(int *)(param_2 + 0x1c);
    if (iVar2 == 2) {
      FUN_0009fb51(piVar3[2] + 0x240,1,piVar3 + 5);
      piVar3[2] = 0;
      iVar2 = *piVar3;
      *(int *)(iVar2 + 4) = piVar3[1];
      *(int *)piVar3[1] = iVar2;
      _free(piVar3);
      piVar3 = piVar1;
    }
    else {
      if (iVar2 == 3) {
        FUN_0003db7a(piVar3[2] + 0x240,piVar3 + 5);
        piVar4 = (int *)piVar3[1];
      }
      else {
        piVar4 = piVar1;
        if (iVar2 == 1) {
          FUN_0003b82e(piVar3[2] + 0x240,piVar3 + 5);
          piVar4 = (int *)piVar3[1];
        }
      }
      piVar3[2] = 0;
      iVar2 = *piVar3;
      *(int **)(iVar2 + 4) = piVar4;
      *(int *)piVar3[1] = iVar2;
      _free(piVar3);
      piVar3 = piVar1;
    }
  }
  iVar2 = *(int *)(param_2 + 0xc);
  if (iVar2 != 0) {
    *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(param_2 + 0x10);
    **(int **)(param_2 + 0x10) = iVar2;
    *(undefined4 *)(param_2 + 0xc) = 0;
    *(undefined4 *)(param_2 + 0x10) = 0;
  }
  _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
  return;
}

/* FUN_0002380d @ 0x2380d (229 bytes) */
int FUN_0002380d(param_1)
  int param_1;
{
  int *piVar1;
  int iVar2;
  pthread_mutex_t *ppVar3;
  undefined1 *puVar4;
  
  _pthread_mutex_lock(*(pthread_mutex_t **)(param_1 + 0xc));
  ppVar3 = *(pthread_mutex_t **)(param_1 + 0xc);
  puVar4 = *(undefined1 **)(ppVar3->__opaque + 0x2c);
  if (ppVar3->__opaque + 0x28 != puVar4) {
    do {
      for (piVar1 = *(int **)(puVar4 + 0x18); piVar1 != (int *)(puVar4 + 0x14);
          piVar1 = (int *)piVar1[1]) {
        if (param_1 == piVar1[2]) {
          iVar2 = *(int *)(puVar4 + 0x10);
          if (iVar2 == 2) {
            FUN_0009fb51(piVar1[2] + 0x240,1,piVar1 + 5);
          }
          else if (iVar2 == 3) {
            FUN_0003db7a(piVar1[2] + 0x240,piVar1 + 5);
          }
          else if (iVar2 == 1) {
            FUN_0003b82e(piVar1[2] + 0x240,piVar1 + 5);
          }
          piVar1[2] = 0;
          iVar2 = *piVar1;
          *(int *)(iVar2 + 4) = piVar1[1];
          *(int *)piVar1[1] = iVar2;
          _free(piVar1);
          break;
        }
      }
      puVar4 = *(undefined1 **)(puVar4 + 4);
    } while (ppVar3->__opaque + 0x28 != puVar4);
    ppVar3 = *(pthread_mutex_t **)(param_1 + 0xc);
  }
  _pthread_mutex_unlock(ppVar3);
  return;
}

/* FUN_000238f2 @ 0x238f2 (1443 bytes) */
int FUN_000238f2(param_1, param_2)
  int param_1;
  int *param_2;
{
  byte *pbVar1;
  byte *pbVar2;
  char cVar3;
  byte bVar4;
  byte *pbVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  char *pcVar9;
  int *piVar10;
  uint uVar11;
  char *pcVar12;
  bool bVar13;
  uint local_70;
  int *local_38;
  uint local_2c;
  byte *local_20;
  
  piVar6 = (int *)(param_1 + 0x240);
  for (local_38 = (int *)param_2[9]; local_38 != param_2 + 8; local_38 = (int *)local_38[1]) {
    if (param_1 == local_38[2]) goto LAB_00023935;
  }
  local_38 = _calloc(1,*(int *)(&DAT_001c5fc0 + param_2[7] * 4) + 0x14);
  local_38[3] = param_2[5] + -1;
  local_38[4] = param_2[6] + -1;
  local_38[2] = param_1;
  *local_38 = param_2[8];
  local_38[1] = (int)(param_2 + 8);
  param_2[8] = (int)local_38;
  *(int **)(*local_38 + 4) = local_38;
LAB_00023935:
  piVar10 = local_38 + 5;
  iVar8 = local_38[5];
  if (iVar8 == 0) {
    FUN_0009f436(piVar6,1,piVar10);
    iVar8 = local_38[5];
    if (iVar8 == 0) {
      return 0;
    }
  }
  FUN_0009f2a3(piVar6,0x8804,iVar8);
  if (local_38[3] == param_2[5]) {
    pbVar5 = (byte *)param_2[0xe];
    if (pbVar5 != (byte *)0x0) {
      bVar4 = pbVar5[0x20];
      if ((bVar4 & 0x1f) == 0) {
LAB_00023ae6:
        bVar13 = false;
        if (-1 < (char)bVar4) goto LAB_00023af2;
LAB_00023cb6:
        uVar11 = (uint)pbVar5[0x21];
        if ((uVar11 & 1) == (uint)*(byte *)(param_1 + 0x2b7c)) goto LAB_00023af6;
      }
      else {
        if ((uint)pbVar5[1] == *(uint *)((uint)*pbVar5 * 0x10 + *(int *)(*param_2 + 0x18))) {
          local_70 = 0;
          local_20 = pbVar5;
          do {
            local_70 = local_70 + 1;
            if ((bVar4 & 0x1f) == local_70) goto LAB_00023ae6;
            pbVar1 = local_20 + 3;
            pbVar2 = local_20 + 2;
            local_20 = local_20 + 2;
          } while ((uint)*pbVar1 == *(uint *)((uint)*pbVar2 * 0x10 + *(int *)(*param_2 + 0x18)));
        }
        bVar13 = true;
        if ((char)bVar4 < '\0') goto LAB_00023cb6;
LAB_00023af2:
        uVar11 = (uint)pbVar5[0x21];
LAB_00023af6:
        if ((((uVar11 & 2) != 0) ||
            ((uVar11 >> 2 & 0xf) == (*(uint *)(param_1 + 0x1ae4) >> 6 & 0xffff))) && (!bVar13))
        goto LAB_00023b6f;
      }
      uVar11 = param_2[0xf];
      param_2[0xf] = uVar11 | 1;
      param_2[5] = param_2[5] + 1;
      if ((uVar11 & 2) != 0) {
        param_2[6] = param_2[6] + 1;
      }
      param_2[0xf] = 0;
      if (local_38[3] != param_2[5]) {
        local_38[3] = param_2[5];
        goto LAB_000239a6;
      }
    }
LAB_00023b6f:
    if ((char)param_2[10] != '\0') {
      return 0;
    }
  }
  else {
    local_38[3] = param_2[5];
LAB_000239a6:
    *(undefined1 *)(param_2 + 10) = 0;
    if (param_2[0xb] != 0) {
      _glpFreePPShaderLinearize(param_2[0xb]);
      param_2[0xb] = 0;
    }
    if (param_2[0xc] != 0) {
      _glpFreePPShaderToProgram(param_2[0xc]);
      param_2[0xc] = 0;
    }
    if (param_2[0xd] != 0) {
      param_2[0xd] = 0;
    }
    FUN_0003eda2(param_2[0xe]);
    param_2[0xe] = 0;
    bVar13 = false;
    local_2c = 0x1f9;
    while( true ) {
      if (*(short *)*param_2 == -0x74d0) {
        iVar8 = _glpPPShaderLinearize(*(undefined4 *)((short *)*param_2 + 2),local_2c);
        param_2[0xb] = iVar8;
      }
      piVar7 = (int *)FUN_0003edf3();
      iVar8 = param_2[0xd];
      if (((iVar8 == 0) && (iVar8 = param_2[0xc], iVar8 == 0)) && (iVar8 = param_2[0xb], iVar8 == 0)
         ) {
        iVar8 = *(int *)(*param_2 + 4);
      }
      *piVar7 = iVar8;
      iVar8 = *(int *)(*param_2 + 0xc);
      piVar7[1] = *(int *)(*param_2 + 8);
      piVar7[2] = iVar8;
      piVar7[3] = *(int *)(*param_2 + 0x18);
      *(byte *)(piVar7[0xd] + 0x21) =
           *(byte *)(piVar7[0xd] + 0x21) & 0xfe | *(byte *)(param_1 + 0x2b7c) & 1;
      *(byte *)(piVar7[0xd] + 0x21) =
           *(byte *)(piVar7[0xd] + 0x21) & 0xc3 |
           ((byte)(*(uint *)(param_1 + 0x1ae4) >> 6) & 0xf) << 2;
      iVar8 = FUN_00047b03(piVar7);
      if (iVar8 == 0) {
        *piVar6 = 0;
        FUN_00088d77(piVar6,piVar7[0xb],0,piVar7[10]);
        bVar13 = *piVar6 == 0;
        if (bVar13) {
          iVar8 = piVar7[0xd];
          piVar7[0xd] = 0;
          param_2[0xe] = iVar8;
          goto LAB_00023a98;
        }
      }
      else if (bVar13) goto LAB_00023a98;
      if ((*(short *)*param_2 != -0x74d0) || ((local_2c & 6) == 6)) break;
      if ((local_2c & 4) == 0) {
        local_2c = local_2c | 4;
      }
      else if ((local_2c & 2) == 0) {
        local_2c = local_2c & 0xfffffffb | 2;
      }
      if (param_2[0xb] != 0) {
        _glpFreePPShaderLinearize(param_2[0xb]);
        param_2[0xb] = 0;
      }
      if (param_2[0xc] != 0) {
        _glpFreePPShaderToProgram(param_2[0xc]);
        param_2[0xc] = 0;
      }
      if (param_2[0xd] != 0) {
        param_2[0xd] = 0;
      }
      FUN_0003eda2(param_2[0xe]);
      param_2[0xe] = 0;
      FUN_0003edb4(piVar7);
    }
    if (!bVar13) {
      if (*(short *)*param_2 == -0x74d0) {
        bVar13 = false;
      }
      else {
        *piVar6 = 0;
        iVar8 = param_2[0xd];
        if (((iVar8 == 0) && (iVar8 = param_2[0xc], iVar8 == 0)) &&
           (iVar8 = param_2[0xb], iVar8 == 0)) {
          iVar8 = *(int *)(*param_2 + 4);
        }
        pcVar9 = (char *)FUN_0000d1c2(iVar8);
        if (pcVar9 == (char *)0x0) {
          FUN_0009fb51(piVar6,1,piVar10);
          *piVar10 = 0;
          return 0;
        }
        uVar11 = 0xffffffff;
        pcVar12 = pcVar9;
        do {
          if (uVar11 == 0) break;
          uVar11 = uVar11 - 1;
          cVar3 = *pcVar12;
          pcVar12 = pcVar12 + 1;
        } while (cVar3 != '\0');
        FUN_0009f20c(piVar6,0x8804,0x8875,~uVar11 - 1,pcVar9);
        _free(pcVar9);
        bVar13 = *piVar6 == 0;
      }
    }
LAB_00023a98:
    FUN_0003edb4(piVar7);
    if (!bVar13) {
      *(undefined1 *)(param_2 + 10) = 1;
      return 0;
    }
  }
  *(int **)(param_1 + 0x29ec) = local_38;
  return 1;
}

/* FUN_00023e95 @ 0x23e95 (462 bytes) */
int FUN_00023e95(param_1, param_2)
  int param_1;
  int *param_2;
{
  char cVar1;
  int iVar2;
  int iVar3;
  int *local_24;
  
  for (local_24 = (int *)param_2[9]; local_24 != param_2 + 8; local_24 = (int *)local_24[1]) {
    if (param_1 == local_24[2]) goto LAB_00023ecd;
  }
  local_24 = _calloc(1,*(int *)(&DAT_001c5fc0 + param_2[7] * 4) + 0x14);
  local_24[3] = param_2[5] + -1;
  local_24[4] = param_2[6] + -1;
  local_24[2] = param_1;
  *local_24 = param_2[8];
  local_24[1] = (int)(param_2 + 8);
  param_2[8] = (int)local_24;
  *(int **)(*local_24 + 4) = local_24;
LAB_00023ecd:
  iVar3 = param_1 + 0x240;
  cVar1 = FUN_0003aa02(iVar3,local_24 + 5);
  if (cVar1 != '\0') {
    if (local_24[3] == param_2[5]) {
      cVar1 = FUN_00051e7e(iVar3);
    }
    else {
      local_24[3] = param_2[5];
      if (param_2[0xb] != 0) {
        _glpFreePPShaderLinearize(param_2[0xb]);
        param_2[0xb] = 0;
      }
      if (param_2[0xc] != 0) {
        _glpFreePPShaderToProgram(param_2[0xc]);
        param_2[0xc] = 0;
      }
      if (param_2[0xd] != 0) {
        param_2[0xd] = 0;
      }
      FUN_0003eda2(param_2[0xe]);
      param_2[0xe] = 0;
      if (*(short *)*param_2 == -0x74cf) {
        iVar2 = _glpPPShaderLinearize(*(undefined4 *)((short *)*param_2 + 2),0xff);
        param_2[0xb] = iVar2;
        if (iVar2 != 0) {
          iVar2 = _glpPPShaderToProgram(iVar2,*(undefined4 *)(*param_2 + 0x18),0);
          param_2[0xc] = iVar2;
        }
      }
      iVar2 = param_2[0xd];
      if (((iVar2 == 0) && (iVar2 = param_2[0xc], iVar2 == 0)) && (iVar2 = param_2[0xb], iVar2 == 0)
         ) {
        iVar2 = *(int *)(*param_2 + 4);
      }
      cVar1 = FUN_0003b8b3(iVar3,iVar2,local_24 + 5);
    }
    if (cVar1 != '\0') {
      *(int **)(param_1 + 0x29e8) = local_24;
      return 1;
    }
  }
  return 0;
}

/* FUN_00024063 @ 0x24063 (578 bytes) */
int FUN_00024063(param_1, param_2)
  int param_1;
  int *param_2;
{
  int *piVar1;
  short sVar2;
  short *psVar3;
  uint uVar4;
  char cVar5;
  undefined1 uVar6;
  int iVar7;
  int *piVar8;
  
  if (param_2[7] != 0) goto LAB_000240d1;
  psVar3 = (short *)*param_2;
  if (psVar3[1] == 0) {
    if ((*psVar3 == -0x79e0) || (*psVar3 == -0x74cf)) {
      iVar7 = 1;
      goto LAB_000240a3;
    }
LAB_000240a1:
    iVar7 = 0;
  }
  else {
    if (psVar3[1] != 1) goto LAB_000240a1;
    sVar2 = *psVar3;
    if ((sVar2 == -0x77fc) || (sVar2 == -0x74d0)) {
      iVar7 = 2;
    }
    else {
      if (sVar2 != -0x7e00) goto LAB_000240a1;
      iVar7 = 3;
    }
  }
LAB_000240a3:
  param_2[7] = iVar7;
  if (iVar7 == 0) {
    return 0;
  }
  param_2[9] = (int)(param_2 + 8);
  param_2[8] = (int)(param_2 + 8);
  iVar7 = *(int *)(param_1 + 0xc);
  param_2[3] = *(int *)(iVar7 + 0x2c);
  param_2[4] = iVar7 + 0x2c;
  *(int **)(iVar7 + 0x2c) = param_2 + 3;
  *(int **)(param_2[3] + 4) = param_2 + 3;
LAB_000240d1:
  uVar4 = param_2[0xf];
  if (uVar4 != 0) {
    if ((uVar4 & 1) != 0) {
      param_2[5] = param_2[5] + 1;
    }
    if ((uVar4 & 2) != 0) {
      param_2[6] = param_2[6] + 1;
    }
    param_2[0xf] = 0;
  }
  psVar3 = (short *)*param_2;
  if (psVar3[1] == 0) {
    if ((*psVar3 == -0x79e0) || (*psVar3 == -0x74cf)) {
      uVar6 = ((int (*)())FUN_00023e95)();
      return uVar6;
    }
  }
  else if (psVar3[1] == 1) {
    sVar2 = *psVar3;
    if ((sVar2 == -0x77fc) || (sVar2 == -0x74d0)) {
      uVar6 = ((int (*)())FUN_000238f2)();
      return uVar6;
    }
    if (sVar2 == -0x7e00) {
      piVar8 = (int *)param_2[9];
      piVar1 = param_2 + 8;
      if (piVar8 == piVar1) {
LAB_00024256:
        piVar8 = _calloc(1,*(int *)(&DAT_001c5fc0 + param_2[7] * 4) + 0x14);
        piVar8[3] = param_2[5] + -1;
        piVar8[4] = param_2[6] + -1;
        piVar8[2] = param_1;
        *piVar8 = param_2[8];
        piVar8[1] = (int)piVar1;
        param_2[8] = (int)piVar8;
        *(int **)(*piVar8 + 4) = piVar8;
      }
      else {
        iVar7 = piVar8[2];
        while (iVar7 != param_1) {
          piVar8 = (int *)piVar8[1];
          if (piVar1 == piVar8) goto LAB_00024256;
          iVar7 = piVar8[2];
        }
      }
      cVar5 = FUN_0003dab0(param_1 + 0x240,piVar8 + 5);
      if (cVar5 == '\0') {
        return 0;
      }
      if (piVar8[3] != param_2[5]) {
        piVar8[3] = param_2[5];
        cVar5 = FUN_0003e351(param_1 + 0x240,*(undefined4 *)(*param_2 + 4),piVar8 + 5);
        if (cVar5 == '\0') {
          return 0;
        }
      }
      *(int **)(param_1 + 0x29ec) = piVar8;
      return 1;
    }
  }
  return 0;
}

/* FUN_000242a5 @ 0x242a5 (354 bytes) */
int FUN_000242a5(param_1, param_2, param_3, param_4)
  int param_1;
  int *param_2;
  undefined4 param_3;
  int *param_4;
{
  short *psVar1;
  int *piVar2;
  
  _pthread_mutex_lock(*(pthread_mutex_t **)(param_1 + 0xc));
  if (((param_2 != (int *)0x0) && (*param_2 != 0)) && (*(int *)(*param_2 + 4) != 0)) {
    FUN_000096f8(param_1,0xffff);
    FUN_000a623b(param_1,0xffff);
    ((int (*)())FUN_00024063)(param_1,param_2);
    psVar1 = (short *)*param_2;
    if (psVar1[1] == 0) {
      if (*psVar1 == -0x79e0) {
        for (piVar2 = (int *)param_2[9]; piVar2 != param_2 + 8; piVar2 = (int *)piVar2[1]) {
          if (param_1 == piVar2[2]) goto LAB_00024355;
        }
        piVar2 = _calloc(1,*(int *)(&DAT_001c5fc0 + param_2[7] * 4) + 0x14);
        piVar2[3] = param_2[5] + -1;
        piVar2[4] = param_2[6] + -1;
        piVar2[2] = param_1;
        *piVar2 = param_2[8];
        piVar2[1] = (int)(param_2 + 8);
        param_2[8] = (int)piVar2;
        *(int **)(*piVar2 + 4) = piVar2;
LAB_00024355:
        switch(param_3) {
        case 0x88a2:
          *param_4 = piVar2[0x23];
          break;
        case 0x88a6:
          *param_4 = piVar2[0x25];
          break;
        case 0x88aa:
          *param_4 = piVar2[0x24];
          break;
        case 0x88ae:
          *param_4 = piVar2[0x26];
          break;
        case 0x88b2:
          *param_4 = piVar2[0x27];
        }
      }
    }
    else if (((psVar1[1] == 1) && (*psVar1 != -0x7e00)) && (*psVar1 == -0x77fc)) {
      FUN_0009f48c(param_1 + 0x240,0x8804,param_3,param_4);
      _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
      return;
    }
  }
  _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
  return;
}

/* FUN_00024498 @ 0x24498 (1021 bytes) */
int FUN_00024498(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
{
  byte bVar1;
  byte bVar2;
  int iVar3;
  uint *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  uint local_24;
  int local_20;
  
  if (param_4 < 4) {
    local_20 = ((int (*)())FUN_0002a011)(param_1,param_3,param_4);
  }
  else {
    local_20 = ((int (*)())FUN_00029fa4)(param_1,param_3,param_4);
  }
  if (local_20 == 0) {
    return;
  }
  if ((*(byte *)(param_1 + 0x27d8) & 6) != 0) {
    bVar1 = *(byte *)(param_1 + 0x283c);
    if (*(char *)(param_1 + 0x27d4) == '\0') {
      bVar2 = *(byte *)(*(int *)(param_1 + 0x27cc) + 2);
    }
    else {
      bVar2 = *(byte *)(*(int *)(param_1 + 0x27d0) + 2);
    }
    iVar3 = *(int *)(param_1 + 0x1ec);
    iVar6 = (uint)bVar2 * local_20 * 4;
    *(int *)(param_1 + 0x1ec) = iVar3 + iVar6;
    puVar5 = *(undefined4 **)(param_1 + 0x1dc);
    *(undefined4 **)(param_1 + 0x298c) = puVar5;
    puVar4 = *(uint **)(param_1 + 0x1d8);
    *puVar4 = *puVar4 | (int)puVar5 - (int)puVar4 >> 2;
    *(undefined4 **)(param_1 + 0x1d8) = puVar5;
    *puVar5 = 0x38000000;
    puVar5[1] = (uint)(bVar1 & 0x1f);
    puVar5[2] = iVar3 - (int)puVar5 >> 2;
    puVar5[3] = 0;
    if (*(char *)(param_1 + 0x27d4) == '\0') {
      *(int *)(param_1 + 0x26d4) = param_1 + 0x2880;
      *(int *)(param_1 + 0x26d8) = param_1 + 0x28a0;
      *(undefined4 *)(param_1 + 0x26d0) = *(undefined4 *)(param_1 + 0x283c);
      puVar5 = (undefined4 *)FUN_0002a1bf(param_1,puVar5 + 4);
      if (*(int *)(param_1 + 0x2680) != param_1 + 0x2840) {
        *(int *)(param_1 + 0x2680) = param_1 + 0x2840;
        iVar7 = param_1 + 0x2860;
        goto LAB_00024700;
      }
    }
    else {
      *(int *)(param_1 + 0x26d4) = param_1 + 0x2924;
      *(int *)(param_1 + 0x26d8) = param_1 + 0x2944;
      *(undefined4 *)(param_1 + 0x26d0) = *(undefined4 *)(param_1 + 0x283c);
      puVar5 = (undefined4 *)FUN_0002a1bf(param_1,puVar5 + 4);
      if (*(int *)(param_1 + 0x2680) != param_1 + 0x28e4) {
        *(int *)(param_1 + 0x2680) = param_1 + 0x28e4;
        iVar7 = param_1 + 0x2904;
LAB_00024700:
        *(int *)(param_1 + 0x2684) = iVar7;
        puVar5 = (undefined4 *)FUN_0002a122(param_1,puVar5);
      }
    }
    if (*(char *)(param_1 + 0x2a42) != '\0') {
      *puVar5 = 0x5c8;
      puVar5[1] = 0x10000000;
      puVar5 = puVar5 + 2;
      *(undefined1 *)(param_1 + 0x2a42) = 0;
    }
    bVar1 = (DAT_001ec600)[param_3 * 4];
    *puVar5 = 0x82c;
    puVar5[1] = *(undefined4 *)(param_1 + 0x1dc4);
    puVar5[2] = 0xc0003400;
    puVar5[3] = bVar1 & 0xf | 0x820 | local_20 << 0x10;
    puVar5[4] = 0x1393;
    puVar5[5] = 0;
    *(undefined4 **)(param_1 + 0x298c) = puVar5 + 6;
    *(undefined4 **)(param_1 + 0x1dc) = puVar5 + 6;
    if (((*(byte *)(param_1 + 0x27d8) & 2) != 0) && ((*(byte *)(param_1 + 0x24) & 2) != 0)) {
      FUN_00009943(param_1,iVar3,iVar6);
    }
    goto LAB_000245e0;
  }
  if (*(char *)(param_1 + 0x27d4) == '\0') {
    local_24 = (uint)*(byte *)(*(int *)(param_1 + 0x27cc) + 2);
    puVar5 = *(undefined4 **)(param_1 + 0x1dc);
    *(undefined4 **)(param_1 + 0x298c) = puVar5;
    if (*(char *)(param_1 + 0x27d4) != '\0') goto LAB_00024525;
LAB_000247e8:
    if (*(int *)(param_1 + 0x2680) != param_1 + 0x2840) {
      *(int *)(param_1 + 0x2680) = param_1 + 0x2840;
      *(int *)(param_1 + 0x2684) = param_1 + 0x2860;
      *(undefined4 *)(param_1 + 0x26cc) = *(undefined4 *)(param_1 + 0x28e0);
      puVar5 = (undefined4 *)FUN_0002a122(param_1,puVar5);
    }
  }
  else {
    local_24 = (uint)*(byte *)(*(int *)(param_1 + 0x27d0) + 2);
    puVar5 = *(undefined4 **)(param_1 + 0x1dc);
    *(undefined4 **)(param_1 + 0x298c) = puVar5;
    if (*(char *)(param_1 + 0x27d4) == '\0') goto LAB_000247e8;
LAB_00024525:
    if (*(int *)(param_1 + 0x2680) != param_1 + 0x28e4) {
      *(int *)(param_1 + 0x2680) = param_1 + 0x28e4;
      *(int *)(param_1 + 0x2684) = param_1 + 0x2904;
      *(undefined4 *)(param_1 + 0x26cc) = *(undefined4 *)(param_1 + 0x2984);
      puVar5 = (undefined4 *)FUN_0002a122(param_1,puVar5);
    }
  }
  if (*(char *)(param_1 + 0x2a42) == '\0') {
    *puVar5 = 0x5c8;
    puVar5[1] = 0x10000000;
    puVar5 = puVar5 + 2;
    *(undefined1 *)(param_1 + 0x2a42) = 1;
  }
  *puVar5 = 0x82c;
  puVar5[1] = *(undefined4 *)(param_1 + 0x1dc4);
  bVar1 = (DAT_001ec600)[param_3 * 4];
  puVar5[2] = local_24 * local_20 * 0x10000 | 0xc0003500;
  puVar5[3] = bVar1 & 0xf | 0x30 | local_20 << 0x10;
  puVar5 = puVar5 + local_24 * local_20 + 4;
  *puVar5 = 0x1393;
  puVar5[1] = 0;
  *(undefined4 **)(param_1 + 0x298c) = puVar5 + 2;
  *(undefined4 **)(param_1 + 0x1dc) = puVar5 + 2;
LAB_000245e0:
  *(undefined1 *)(param_1 + 0x2a5e) = 1;
  return;
}

/* FUN_00024895 @ 0x24895 (476 bytes) */
int FUN_00024895(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint *param_3;
{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint local_20;
  int local_18;
  uint local_14;
  undefined4 local_10;
  
  if (*(char *)(param_1 + 0x2b80) != '\0') {
    ((int (*)())FUN_00029f8a)(param_1,1,param_2);
  }
  if (*(int *)(param_1 + 0x1b68) != 0) {
    ((int (*)())FUN_0002a0bb)(param_1 + 0x240,param_2);
  }
  if ((*param_3 == 0) || (*(int *)(*(int *)(param_1 + 0x14) + 0x120) == 0)) {
    bVar1 = *(byte *)(*(int *)(param_1 + 0x27cc) + 2);
    *(undefined1 *)(param_1 + 0x27d4) = 0;
  }
  else {
    bVar1 = *(byte *)(*(int *)(param_1 + 0x27d0) + 2);
    *(undefined1 *)(param_1 + 0x27d4) = 1;
  }
  local_20 = (uint)bVar1;
  iVar4 = *(int *)(param_1 + 500);
  if (*(uint *)(param_1 + 0x1f8) <= local_20 * 0x90 + 0x80 + iVar4) {
    local_10 = 2;
    uVar2 = *(int *)(param_1 + 0x204) + 1;
    *(uint *)(param_1 + 0x204) = uVar2;
    if (2 < uVar2) {
      if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
        FUN_00017c77(param_1,0x1000000);
        iVar4 = *(int *)(param_1 + 500);
      }
      *(undefined4 *)(param_1 + 0x204) = 1;
    }
    *(int *)(*(int *)(param_1 + 0x208) + 0xc) = iVar4 - *(int *)(param_1 + 0x1fc) >> 2;
    _io_connect_method_scalarI_scalarO(*(undefined4 *)(param_1 + 4),0x12,0,0,&local_18,&local_10);
    *(int *)(param_1 + 0x1fc) = local_18;
    *(int *)(param_1 + 500) = local_18;
    *(uint *)(param_1 + 0x1f8) = local_18 + (local_14 & 0xfffffffc);
    *(undefined4 *)(param_1 + 0x200) = *(undefined4 *)(*(int *)(param_1 + 0x208) + 8);
    *(uint *)(param_1 + 0x26c8) = *(uint *)(param_1 + 0x26c8) | 1;
    iVar4 = local_18;
  }
  uVar5 = iVar4 + 0x7fU & 0xffffff80;
  *(uint *)(param_1 + 500) = uVar5;
  uVar2 = (int)(((ulonglong)(uint)((int)(*(int *)(param_1 + 0x1f8) - uVar5) >> 2) /
                (ulonglong)local_20) / 0xc) * 0xc;
  uVar3 = 0xfffc;
  if (uVar2 < 0x10000) {
    uVar3 = uVar2;
  }
  *param_3 = uVar3;
  return uVar5;
}

/* FUN_00024a71 @ 0x24a71 (625 bytes) */
int FUN_00024a71(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
{
  byte bVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  int local_20;
  
  if (param_4 < 4) {
    local_20 = ((int (*)())FUN_0002a011)(param_1,param_3,param_4);
  }
  else {
    local_20 = ((int (*)())FUN_00029fa4)(param_1,param_3,param_4);
  }
  if (local_20 != 0) {
    uVar3 = (uint)(*(byte *)(param_1 + 0x283c) & 0x1f);
    if (*(char *)(param_1 + 0x27d4) == '\0') {
      bVar1 = *(byte *)(*(int *)(param_1 + 0x27cc) + 2);
    }
    else {
      bVar1 = *(byte *)(*(int *)(param_1 + 0x27d0) + 2);
    }
    iVar5 = *(int *)(param_1 + 500) - *(int *)(param_1 + 0x1fc);
    *(uint *)(param_1 + 500) = *(int *)(param_1 + 500) + (uint)bVar1 * local_20 * 4;
    puVar4 = *(undefined4 **)(param_1 + 0x1dc);
    if (*(undefined4 **)(param_1 + 0x1e0) <= puVar4 + 0x53) {
      FUN_00017c77(param_1,0x1000000);
      puVar4 = *(undefined4 **)(param_1 + 0x1dc);
    }
    if (*(char *)(param_1 + 0x2a42) != '\0') {
      *puVar4 = 0x5c8;
      puVar4[1] = 0x10000000;
      puVar4 = puVar4 + 2;
      *(undefined1 *)(param_1 + 0x2a42) = 0;
    }
    if (*(char *)(param_1 + 0x27d4) == '\0') {
      if (*(int *)(param_1 + 0x2680) != param_1 + 0x2840) {
        *(int *)(param_1 + 0x2680) = param_1 + 0x2840;
        *(int *)(param_1 + 0x2684) = param_1 + 0x2860;
        puVar4 = (undefined4 *)FUN_0002a122(param_1,puVar4);
      }
      puVar2 = *(uint **)(param_1 + 0x1d8);
      *puVar2 = *puVar2 | (int)puVar4 - (int)puVar2 >> 2;
      *(undefined4 **)(param_1 + 0x1d8) = puVar4;
      *puVar4 = 0x36000000;
      puVar4[1] = *(undefined4 *)(param_1 + 0x200);
      puVar4[2] = uVar3;
      puVar4[3] = iVar5;
      *(int *)(param_1 + 0x26d4) = param_1 + 0x2880;
      iVar5 = param_1 + 0x28a0;
    }
    else {
      if (*(int *)(param_1 + 0x2680) != param_1 + 0x28e4) {
        *(int *)(param_1 + 0x2680) = param_1 + 0x28e4;
        *(int *)(param_1 + 0x2684) = param_1 + 0x2904;
        puVar4 = (undefined4 *)FUN_0002a122(param_1,puVar4);
      }
      puVar2 = *(uint **)(param_1 + 0x1d8);
      *puVar2 = *puVar2 | (int)puVar4 - (int)puVar2 >> 2;
      *(undefined4 **)(param_1 + 0x1d8) = puVar4;
      *puVar4 = 0x36000000;
      puVar4[1] = *(undefined4 *)(param_1 + 0x200);
      puVar4[2] = uVar3;
      puVar4[3] = iVar5;
      *(int *)(param_1 + 0x26d4) = param_1 + 0x2924;
      iVar5 = param_1 + 0x2944;
    }
    *(int *)(param_1 + 0x26d8) = iVar5;
    *(undefined4 *)(param_1 + 0x26d0) = *(undefined4 *)(param_1 + 0x283c);
    puVar4 = (undefined4 *)FUN_0002a1bf(param_1,puVar4 + 4);
    bVar1 = (DAT_001ec600)[param_3 * 4];
    *puVar4 = 0x82c;
    puVar4[1] = *(undefined4 *)(param_1 + 0x1dc4);
    puVar4[2] = 0xc0003400;
    puVar4[3] = bVar1 & 0xf | 0x820 | local_20 << 0x10;
    puVar4[4] = 0x1393;
    puVar4[5] = 0;
    *(undefined4 **)(param_1 + 0x1dc) = puVar4 + 6;
  }
  return;
}

/* FUN_00024ce2 @ 0x24ce2 (1430 bytes) */
int FUN_00024ce2(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint *param_3;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  undefined *puVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  uint uVar12;
  byte local_31;
  int local_30;
  uint local_24;
  uint local_20;
  uint local_1c;
  int local_18;
  uint local_10;
  
  if (*(char *)(param_1 + 0x2b80) != '\0') {
    ((int (*)())FUN_00029f8a)(param_1,1,param_2);
  }
  if (*(int *)(param_1 + 0x1b68) != 0) {
    ((int (*)())FUN_0002a0bb)(param_1 + 0x240,param_2);
  }
  if ((*param_3 == 0) || (*(int *)(*(int *)(param_1 + 0x14) + 0x120) == 0)) {
    local_24 = (uint)*(byte *)(*(int *)(param_1 + 0x27cc) + 2);
    *(undefined1 *)(param_1 + 0x27d4) = 0;
    uVar7 = *(uint *)(param_1 + 0x27d8);
    bVar1 = false;
    bVar2 = bVar1;
    if ((uVar7 & 0x10) != 0) goto LAB_00024f4c;
LAB_00024d70:
    bVar1 = bVar2;
    uVar6 = 1;
  }
  else {
    local_24 = (uint)*(byte *)(*(int *)(param_1 + 0x27d0) + 2);
    *(undefined1 *)(param_1 + 0x27d4) = 1;
    uVar7 = *(uint *)(param_1 + 0x27d8);
    bVar1 = true;
    bVar2 = true;
    if ((uVar7 & 8) == 0) goto LAB_00024d70;
LAB_00024f4c:
    uVar6 = 2;
  }
  uVar9 = uVar7 & 0x18 | uVar6;
  if (uVar7 != uVar9) {
    *(int *)(param_1 + 0x2680) = param_1 + 0x26dc;
  }
  if ((uVar6 & 2) == 0) {
    if (*(char *)(param_1 + 0x27d4) == '\0') {
      if (*(int *)(param_1 + 0x2680) == param_1 + 0x2840) goto LAB_000251c1;
      uVar7 = *(int *)(param_1 + 0x267c) + 1U & 0xfffffffe;
      iVar3 = uVar7 + 8;
      if (*(char *)(param_1 + 0x2a42) == '\0') {
        iVar3 = uVar7 + 10;
      }
      local_18 = iVar3 + 2;
      uVar7 = *param_3;
      if ((int)uVar7 < 0xc) goto LAB_00024fb0;
LAB_000250d4:
      local_20 = ((int)uVar7 / 0xc) * 0xc;
      uVar7 = local_24 * local_20;
      if (0x3fff < uVar7) {
        local_20 = (int)((0x3fff / (ulonglong)local_24) / 0xc) * 0xc;
        uVar7 = local_24 * local_20;
      }
    }
    else {
      if (*(int *)(param_1 + 0x2680) == param_1 + 0x28e4) {
LAB_000251c1:
        iVar8 = 2;
        iVar3 = 4;
      }
      else {
        uVar7 = *(int *)(param_1 + 0x267c) + 1U & 0xfffffffe;
        iVar8 = uVar7 + 6;
        iVar3 = uVar7 + 8;
      }
      if (*(char *)(param_1 + 0x2a42) == '\0') {
        iVar3 = iVar8 + 4;
      }
      local_18 = iVar3 + 2;
      uVar7 = *param_3;
      if (0xb < (int)uVar7) goto LAB_000250d4;
LAB_00024fb0:
      uVar7 = local_24 * 0xc;
      local_20 = 0xc;
    }
    puVar10 = *(undefined4 **)(param_1 + 0x1dc);
    if (*(undefined4 **)(param_1 + 0x1e0) <=
        puVar10 + local_18 + uVar7 + (uint)(*(byte *)(param_1 + 8) >> 1) + 4) {
      FUN_00017c77(param_1,0x1000000);
      puVar10 = *(undefined4 **)(param_1 + 0x1dc);
    }
    uVar7 = (int)puVar10 + iVar3 * 4 + 0xf & 0xfffffff0;
    puVar11 = (undefined4 *)(uVar7 + iVar3 * -4);
    *(undefined4 **)(param_1 + 0x1dc) = puVar11;
    for (; puVar10 < puVar11; puVar10 = puVar10 + 1) {
      *puVar10 = 0x80000000;
    }
    if (*param_3 != 0) goto LAB_0002506a;
    uVar6 = (((*(int *)(param_1 + 0x1e0) - *(int *)(param_1 + 0x1dc) >> 2) + -1) -
            (uint)(*(byte *)(param_1 + 8) >> 1)) - local_18;
    if (0x600 < uVar6) {
      uVar6 = 0x600;
    }
  }
  else {
    uVar7 = *param_3;
    if (uVar7 == 0) {
      puVar5 = (undefined *)0x8b;
    }
    else if (uVar7 < 0x10000) {
      puVar5 = (undefined *)(uVar7 + 0xb);
    }
    else {
      puVar5 = ((unsigned char *)0x0001000a);
    }
    local_20 = ((uint)puVar5 / 0xc) * 0xc;
    local_31 = *(byte *)(param_1 + 8);
    uVar6 = local_24 * local_20 + 0x20 + (uint)(local_31 >> 1);
    local_10 = (-(uint)(*(char *)(param_1 + 0x2a42) == '\0') & 0xfffffffe) + 0xf +
               ((*(byte *)(param_1 + 0x283c) & 0x1f) + 1 >> 1) * 3;
    if (bVar1) {
      if (*(int *)(param_1 + 0x2680) != param_1 + 0x28e4) {
        local_10 = local_10 + 4 + (*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe);
      }
    }
    else if (*(int *)(param_1 + 0x2680) != param_1 + 0x2840) {
      local_10 = local_10 + 4 + (*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe);
    }
    uVar7 = *(uint *)(param_1 + 0x1ec);
    if (uVar7 == 0) {
      uVar12 = *(uint *)(param_1 + 0x1dc);
      local_30 = *(int *)(param_1 + 0x1e0);
      uVar7 = ((int)(local_30 - uVar12) >> 2) - 1;
      local_1c = uVar6;
      if (uVar7 < local_10 + uVar6) {
        if (*(int *)(param_1 + 0x1e4) + 0x28U < uVar12) {
          FUN_00017c77(param_1,0x1000000);
          local_31 = *(byte *)(param_1 + 8);
          uVar12 = *(uint *)(param_1 + 0x1dc);
          local_30 = *(int *)(param_1 + 0x1e0);
        }
        iVar3 = local_30 - uVar12;
        goto LAB_00024ea3;
      }
LAB_00024eb1:
      uVar6 = uVar7 >> 2;
      if (uVar7 >> 2 < local_1c) {
        uVar6 = local_1c;
      }
      uVar4 = uVar7 - uVar6;
      if (uVar7 - uVar6 < local_10) {
        uVar4 = local_10;
      }
      iVar3 = local_30 + 0x94;
      *(int *)(param_1 + 0x1f0) = iVar3;
      uVar7 = uVar12 + 0x9f + uVar4 * 4 & 0xfffffff8;
      *(uint *)(param_1 + 0x1e0) = uVar7;
      uVar7 = uVar7 + 0x7f & 0xffffff80;
      *(uint *)(param_1 + 0x1ec) = uVar7;
    }
    else {
      uVar12 = *(uint *)(param_1 + 0x1dc);
      iVar3 = *(int *)(param_1 + 0x1f0);
      local_30 = *(int *)(param_1 + 0x1e0);
      if ((((int)(local_30 - uVar12) >> 2) - 1U < local_10) ||
         ((uint)((int)(iVar3 - uVar7) >> 2) < uVar6)) {
        if (*(int *)(param_1 + 0x1e4) + 0x28U < uVar12) {
          FUN_00017c77(param_1,0x1000000);
          local_31 = *(byte *)(param_1 + 8);
          uVar12 = *(uint *)(param_1 + 0x1dc);
          local_30 = *(int *)(param_1 + 0x1e0);
        }
        iVar3 = local_30 - uVar12;
LAB_00024ea3:
        uVar7 = (iVar3 >> 2) - 1;
        local_1c = uVar7 - local_10;
        if (local_10 + uVar6 <= uVar7) {
          local_1c = uVar6;
        }
        goto LAB_00024eb1;
      }
    }
    uVar6 = ((int)(iVar3 - uVar7) >> 2) - (uint)(local_31 >> 1);
    if (local_24 * local_20 <= uVar6) goto LAB_0002506a;
  }
  local_20 = (int)(((ulonglong)uVar6 / (ulonglong)local_24) / 0xc) * 0xc;
LAB_0002506a:
  *param_3 = local_20;
  *(uint *)(param_1 + 0x27d8) = uVar9;
  return uVar7;
}

/* FUN_00025278 @ 0x25278 (2678 bytes) */
int FUN_00025278(param_1)
  int param_1;
{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  byte bVar12;
  int iVar13;
  uint uVar14;
  short sVar15;
  int *piVar16;
  short local_ae;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  byte local_74;
  int local_70;
  uint local_6c;
  int local_68;
  int local_64;
  byte local_60;
  uint local_5c;
  int local_58;
  int local_54;
  uint local_50;
  undefined2 uStack_42;
  byte local_40;
  byte local_2d;
  byte local_2c;
  byte local_1b;
  ushort local_1a;
  short *local_18;
  uint *local_14;
  
  iVar2 = *(int *)(param_1 + 4);
  *(undefined4 *)(param_1 + 0x2494) = 0;
  *(int *)(param_1 + 0x2440) = param_1 + 0x249c;
  *(int *)(param_1 + 0x2444) = param_1 + 0x24bc;
  uVar3 = *(uint *)(param_1 + 0x243c);
  if ((((*(char *)(iVar2 + 0x20) == '\0') ||
       (*(int *)(*(int *)(iVar2 + 0x10) + 0x3170) != 0x1b021b02)) || (uVar3 < 2)) || (0x10 < uVar3))
  {
    if ((*(int *)(*(int *)(iVar2 + 0x14) + 0x11c) != 0) ||
       (*(int *)(*(int *)(iVar2 + 0x14) + 0x120) != 0)) {
      *(uint *)(param_1 + 0x2488) = *(uint *)(param_1 + 0x2488) | 2;
      *(undefined4 *)(*(int *)(iVar2 + 0x14) + 0x11c) = 0;
      *(undefined4 *)(*(int *)(iVar2 + 0x14) + 0x120) = 0;
    }
    return;
  }
  if (*(int **)(iVar2 + 0x1cc) == (int *)0x0) {
    local_84 = 0;
    local_80 = 0;
    local_7c = 0;
    local_78 = 0;
  }
  else {
    local_84 = *(int *)(iVar2 + 0x29e8) + 0x14;
    local_80 = *(int *)(*(int *)(iVar2 + 0x29e8) + 0x34);
    local_7c = *(int *)(**(int **)(iVar2 + 0x1cc) + 4);
    local_78 = *(int *)(local_7c + 0x24);
  }
  iVar4 = **(int **)(*(int *)(iVar2 + 0x18) + 0x194);
  pbVar5 = *(byte **)(param_1 + 0x258c);
  *(byte **)(*(int *)(iVar2 + 0x14) + 0x11c) = pbVar5;
  pbVar6 = *(byte **)(param_1 + 0x2590);
  *(byte **)(*(int *)(iVar2 + 0x14) + 0x120) = pbVar6;
  if (*(char *)(param_1 + 0x2595) != '\0') {
    *(undefined4 *)(*(int *)(iVar2 + 0x14) + 0x120) = 0;
  }
  *(uint *)(param_1 + 0x2488) = *(uint *)(param_1 + 0x2488) | 2;
  uVar14 = uVar3 + 1 >> 1;
  if (uVar14 != 0) {
    uVar11 = 0;
    iVar13 = param_1;
    do {
      *(undefined4 *)(iVar13 + 0x2600) = *(undefined4 *)(iVar13 + 0x1be4);
      *(undefined4 *)(iVar13 + 0x26a4) = *(undefined4 *)(iVar13 + 0x1be4);
      *(undefined4 *)(iVar13 + 0x2620) = *(undefined4 *)(iVar13 + 0x1c04);
      *(undefined4 *)(iVar13 + 0x26c4) = *(undefined4 *)(iVar13 + 0x1c04);
      uVar11 = uVar11 + 1;
      iVar13 = iVar13 + 4;
    } while (uVar14 != uVar11);
  }
  *(undefined4 *)(param_1 + 0x26a0) = *(undefined4 *)(param_1 + 0x1ca4);
  *(undefined4 *)(param_1 + 0x25fc) = 0;
  local_60 = (byte)uVar3;
  *(byte *)(param_1 + 0x25fc) = *(byte *)(param_1 + 0x25fc) & 0xe0 | 0x20 | local_60 & 0x1f;
  if (*(int *)(iVar2 + 0x1cc) == 0) {
    iVar13 = *(int *)(param_1 + 4);
  }
  else {
    iVar13 = *(int *)(param_1 + 4);
    uVar14 = 0;
    piVar16 = (int *)&DAT_001ec9a0;
    do {
      if (*(int *)(iVar13 + 0x1cc) == 0) {
        if ((*(uint *)(param_1 + 0x1ca0) & 1 << ((byte)uVar14 & 0x1f)) != 0) goto LAB_00025495;
      }
      else if ((*(int *)(*(int *)(local_84 + 0x20) + uVar14 * 4) != 0x80) ||
              (*(uint *)(local_84 + 0x1c) <= uVar14)) {
LAB_00025495:
        if (*(int *)(iVar13 + 0x1cc) == 0) {
          iVar8 = *piVar16;
        }
        else {
          if (*(uint *)(local_84 + 0x1c) <= uVar14) goto LAB_000254fc;
          iVar10 = local_7c + (local_78 + *(int *)(local_80 + uVar14 * 4)) * 8;
          iVar8 = *(int *)(&DAT_001eca00 + (uint)(*(byte *)(iVar10 + 1) >> 4) * 4);
          if (iVar8 == 8) {
            iVar8 = (*(byte *)(iVar10 + 3) >> 3) + 8;
          }
          else if (iVar8 == 0x10) {
            iVar8 = (*(byte *)(iVar10 + 3) >> 3) + 0x10;
          }
          else if (iVar8 == 0x2f) {
            switch(*(byte *)(iVar10 + 2) & 0xf) {
            case 0:
              iVar8 = (*(byte *)(iVar10 + 3) >> 7) + 0x20;
              break;
            case 1:
              iVar8 = (*(byte *)(iVar10 + 3) >> 7) + 0x22;
              break;
            case 2:
              iVar8 = (*(byte *)(iVar10 + 3) >> 7) + 0x24;
              break;
            case 3:
              iVar8 = (*(byte *)(iVar10 + 3) >> 7) + 0x26;
              break;
            case 4:
              iVar8 = (*(byte *)(iVar10 + 3) >> 7) + 0x28;
              break;
            default:
              goto LAB_000254fc;
            }
          }
        }
        if ((iVar8 == 0) || (iVar8 == 0x10)) {
          bVar7 = true;
          goto LAB_000255c5;
        }
      }
LAB_000254fc:
      uVar14 = uVar14 + 1;
      piVar16 = piVar16 + 1;
    } while (uVar14 != 0x16);
  }
  bVar7 = false;
LAB_000255c5:
  local_70 = 0;
  local_6c = 0;
  local_68 = 0;
  local_64 = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = 1;
  local_50 = 0;
  local_18 = (short *)&DAT_001eca40;
  local_14 = (uint *)&DAT_001ec9a0;
  do {
    iVar13 = *(int *)(iVar13 + 0x1cc);
    local_74 = (byte)(uVar3 << 2);
    if (iVar13 == 0) {
      if ((*(uint *)(param_1 + 0x1ca0) & 1 << ((byte)local_5c & 0x1f)) != 0) goto LAB_0002587b;
    }
    else if ((*(int *)(*(int *)(local_84 + 0x20) + local_5c * 4) != 0x80) ||
            (*(uint *)(local_84 + 0x1c) <= local_5c)) {
LAB_0002587b:
      if (iVar13 == 0) {
        uVar14 = *local_14;
LAB_000258d3:
        if (uVar14 == 0x30) {
LAB_00025d12:
          *(uint *)(param_1 + 0x2488) = *(uint *)(param_1 + 0x2488) | 2;
          *(undefined4 *)(*(int *)(iVar2 + 0x14) + 0x11c) = 0;
          *(undefined4 *)(*(int *)(iVar2 + 0x14) + 0x120) = 0;
          return;
        }
        sVar15 = (short)uVar14;
      }
      else {
        if (local_5c < *(uint *)(local_84 + 0x1c)) {
          iVar8 = local_7c + (local_78 + *(int *)(local_80 + local_5c * 4)) * 8;
          uVar14 = *(uint *)(&DAT_001eca00 + (uint)(*(byte *)(iVar8 + 1) >> 4) * 4);
          if (uVar14 == 8) {
            uVar14 = (*(byte *)(iVar8 + 3) >> 3) + 8;
          }
          else if (uVar14 == 0x10) {
            uVar14 = (*(byte *)(iVar8 + 3) >> 3) + 0x10;
          }
          else if (uVar14 == 0x2f) {
            switch(*(byte *)(iVar8 + 2) & 0xf) {
            case 0:
              uVar14 = (*(byte *)(iVar8 + 3) >> 7) + 0x20;
              break;
            case 1:
              uVar14 = (*(byte *)(iVar8 + 3) >> 7) + 0x22;
              break;
            case 2:
              uVar14 = (*(byte *)(iVar8 + 3) >> 7) + 0x24;
              break;
            case 3:
              uVar14 = (*(byte *)(iVar8 + 3) >> 7) + 0x26;
              break;
            case 4:
              uVar14 = (*(byte *)(iVar8 + 3) >> 7) + 0x28;
              break;
            default:
              goto LAB_00025d12;
            }
          }
          goto LAB_000258d3;
        }
        uVar14 = 2;
        sVar15 = 2;
      }
      if (bVar7) {
        if ((uVar14 == 0) || (uVar14 == 0x10)) {
          local_58 = 0;
        }
        else {
          local_58 = local_54;
        }
      }
      uVar11 = local_50 >> 1;
      if (iVar13 == 0) {
        local_ae = *local_18;
      }
      else {
        local_ae = 3;
      }
      if ((local_50 & 1) == 0) {
        *(byte *)(param_1 + 0x2641 + uVar11 * 4) =
             *(byte *)(param_1 + 0x2641 + uVar11 * 4) & 0x80 | local_74 & 0x7f;
        *(byte *)(param_1 + 0x2640 + uVar11 * 4) =
             *(byte *)(param_1 + 0x2640 + uVar11 * 4) & 0x80 | 4;
      }
      else {
        *(byte *)(param_1 + 0x2643 + uVar11 * 4) =
             *(byte *)(param_1 + 0x2643 + uVar11 * 4) & 0x80 | local_74 & 0x7f;
        *(byte *)(param_1 + 0x2642 + uVar11 * 4) =
             *(byte *)(param_1 + 0x2642 + uVar11 * 4) & 0x80 | 4;
      }
      *(int *)(param_1 + 0x2660 + local_50 * 4) = local_70;
      local_1a = local_ae << 8 | sVar15 << 10;
      *(ushort *)(pbVar5 + local_58 * 2 + 4) = local_1a | (ushort)local_70;
      if (*(char *)(param_1 + 0x2595) == '\0') {
        uVar1 = *(ushort *)(iVar4 + 8 + uVar14 * 0x18);
        if (uVar14 < 0x10) {
          uVar9 = *(uint *)(iVar4 + 0x300);
        }
        else {
          uVar9 = *(uint *)(iVar4 + 0x304);
        }
        if ((*(uint *)(&DAT_001ec920 + uVar14 * 4) & uVar9) == 0) {
          local_68 = 4;
          (*(unsigned char *)((unsigned char *)&(local_68) + 0)) = 4;
          uStack_42 = 3;
          local_40 = 0;
          local_2d = 1;
          local_2c = 2;
          local_1b = 3;
          sVar15 = 0;
        }
        else {
          iVar13 = (uVar1 & 0x7fff) - 0x1400;
          iVar10 = *(short *)(iVar4 + 10 + uVar14 * 0x18) + -1;
          iVar8 = iVar10 + iVar13 * 4;
          local_68 = *(int *)(&DAT_001ec760 + iVar8 * 4);
          uStack_42 = CONCAT11((DAT_001ec660)[iVar13 * 4],(DAT_001ec6a0)[iVar8 * 4]);
          local_40 = (byte)(uVar1 >> 0xf);
          local_2d = (DAT_001ec648)[iVar10 * 4];
          local_2c = (DAT_001ec638)[iVar10 * 4];
          local_1b = (DAT_001ec628)[iVar10 * 4];
          local_1a = (ushort)(*(int *)(&DAT_001ec820 + iVar8 * 4) << 8) | sVar15 << 10;
          sVar15 = *(short *)(&DAT_001ec8e0 + iVar13 * 4);
        }
        if ((local_50 & 1) == 0) {
          *(byte *)(param_1 + 0x26e4 + uVar11 * 4) =
               *(byte *)(param_1 + 0x26e4 + uVar11 * 4) & 0x80 | (byte)local_68 & 0x7f;
        }
        else {
          *(byte *)(param_1 + 0x26e6 + uVar11 * 4) =
               *(byte *)(param_1 + 0x26e6 + uVar11 * 4) & 0x80 | (byte)local_68 & 0x7f;
        }
        *(int *)(param_1 + 0x2704 + local_50 * 4) = local_64;
        if ((local_50 & 1) == 0) {
          uStack_42 = uStack_42 & 0xff0f;
          *(byte *)(param_1 + 0x26a4 + uVar11 * 4) =
               *(byte *)(param_1 + 0x26a4 + uVar11 * 4) & 0xf0 | (byte)uStack_42;
          (*(unsigned char *)((unsigned char *)&(uStack_42) + 1)) = (byte)(uStack_42 >> 8);
          *(byte *)(param_1 + 0x26a5 + uVar11 * 4) =
               *(byte *)(param_1 + 0x26a5 + uVar11 * 4) & 0x3f | ((*(unsigned char *)((unsigned char *)&(uStack_42) + 1)) & 1) << 6 |
               local_40 << 7;
          *(byte *)(param_1 + 0x26c4 + uVar11 * 4) =
               *(byte *)(param_1 + 0x26c4 + uVar11 * 4) & 0xc0 | (local_2d & 7) << 3;
          *(ushort *)(param_1 + 0x26c4 + uVar11 * 4) =
               *(ushort *)(param_1 + 0x26c4 + uVar11 * 4) & 0xfe3f | (local_2c & 7) << 6;
          *(byte *)(param_1 + 0x26c5 + uVar11 * 4) =
               *(byte *)(param_1 + 0x26c5 + uVar11 * 4) & 0xf1 | (local_1b & 7) * '\x02';
        }
        else {
          uStack_42 = uStack_42 & 0xff0f;
          *(byte *)(param_1 + 0x26a6 + uVar11 * 4) =
               *(byte *)(param_1 + 0x26a6 + uVar11 * 4) & 0xf0 | (byte)uStack_42;
          (*(unsigned char *)((unsigned char *)&(uStack_42) + 1)) = (byte)(uStack_42 >> 8);
          *(byte *)(param_1 + 0x26a7 + uVar11 * 4) =
               *(byte *)(param_1 + 0x26a7 + uVar11 * 4) & 0x3f | ((*(unsigned char *)((unsigned char *)&(uStack_42) + 1)) & 1) << 6 |
               local_40 << 7;
          *(byte *)(param_1 + 0x26c6 + uVar11 * 4) =
               *(byte *)(param_1 + 0x26c6 + uVar11 * 4) & 0xc0 | (local_2d & 7) << 3;
          *(ushort *)(param_1 + 0x26c6 + uVar11 * 4) =
               *(ushort *)(param_1 + 0x26c6 + uVar11 * 4) & 0xfe3f | (local_2c & 7) << 6;
          *(byte *)(param_1 + 0x26c7 + uVar11 * 4) =
               *(byte *)(param_1 + 0x26c7 + uVar11 * 4) & 0xf1 | (local_1b & 7) * '\x02';
        }
        *(ushort *)(pbVar6 + local_58 * 2 + 4) = sVar15 << 6 | local_1a | (ushort)local_64;
      }
      *(uint *)(param_1 + 0x259c + local_5c * 4) = local_50;
      local_70 = local_70 + 4;
      local_64 = local_64 + local_68;
      local_6c = local_6c + local_68;
      local_50 = local_50 + 1;
      if (bVar7) {
        if (local_58 != 0) {
          local_54 = local_54 + 1;
        }
      }
      else {
        local_58 = local_58 + 1;
      }
    }
    if (local_50 == uVar3) {
LAB_00025b50:
      if (*(char *)(param_1 + 0x2595) == '\0') {
        bVar12 = (byte)local_6c & 0x7f;
        *(byte *)(param_1 + 0x2744) = *(byte *)(param_1 + 0x2744) & 0x80 | bVar12;
        uVar14 = 0;
        do {
          if ((uVar14 & 1) == 0) {
            *(byte *)(param_1 + 0x26e5 + (uVar14 >> 1) * 4) =
                 *(byte *)(param_1 + 0x26e5 + (uVar14 >> 1) * 4) & 0x80 | bVar12;
          }
          else {
            *(byte *)(param_1 + 0x26e7 + (uVar14 >> 1) * 4) =
                 *(byte *)(param_1 + 0x26e7 + (uVar14 >> 1) * 4) & 0x80 | bVar12;
          }
          uVar14 = uVar14 + 1;
        } while (uVar3 != uVar14);
      }
      *pbVar5 = local_60;
      *pbVar6 = local_60;
      pbVar5[2] = local_74;
      pbVar6[2] = (byte)local_6c;
      pbVar5[1] = 0;
      pbVar6[1] = 0;
      if (*(char *)(iVar2 + 8) == ' ') {
        if (7 < uVar3 << 2) {
          pbVar5[1] = pbVar5[1] | 0x40;
        }
        if (*(byte *)(iVar2 + 8) >> 2 <= local_6c) {
          pbVar6[1] = pbVar6[1] | 0x40;
        }
      }
      *(uint *)(param_1 + 0x2598) = *(uint *)(param_1 + 0x2598) & 0xffffffe7;
      return;
    }
    local_5c = local_5c + 1;
    local_18 = local_18 + 2;
    local_14 = local_14 + 1;
    if (local_5c == 0x16) goto LAB_00025b50;
    iVar13 = *(int *)(param_1 + 4);
  } while( true );
}

/* FUN_00025ded @ 0x25ded (4340 bytes) */
int FUN_00025ded(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
  int param_1;
  int param_2;
  int param_3;
  uint param_4;
  int param_5;
  uint param_6;
  int param_7;
  int param_8;
  undefined4 param_9;
  undefined4 *param_10;
{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  undefined4 *puVar4;
  undefined *puVar5;
  char cVar6;
  undefined4 uVar7;
  uint *puVar8;
  int iVar9;
  uint uVar10;
  byte bVar11;
  byte bVar12;
  byte bVar13;
  int iVar14;
  int iVar15;
  int iVar16;
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
  int local_7c;
  int local_70;
  uint local_6c;
  int local_68;
  float local_54;
  undefined4 *local_38;
  float local_34;
  int local_28;
  undefined1 local_24 [4];
  uint local_20 [4];
  
  if (param_6 == 0x1909) {
    if (param_7 == 0x1401) {
      local_70 = 1;
      goto LAB_00025eec;
    }
    if (param_7 == 0x1406) {
      local_70 = 0x13;
    }
    else if (param_7 == 0x140b) {
      local_70 = 0x1f;
    }
    else {
      local_70 = 0;
      if (param_7 != 0x1403) goto LAB_00025eec;
      local_70 = 0x19;
    }
  }
  else if (param_6 < 0x190a) {
    if (param_6 == 0x1907) {
      if (param_7 == 0x8363) {
        local_70 = 5;
      }
      else {
        if (param_7 != 0x8032) {
          return 0;
        }
        local_70 = 0x28;
      }
    }
    else if (param_6 < 0x1908) {
      if (param_6 != 0x1906) {
        return 0;
      }
      if (param_7 == 0x1401) {
        local_70 = 2;
        goto LAB_00025eec;
      }
      if (param_7 == 0x1406) {
        local_70 = 0x14;
      }
      else if (param_7 == 0x140b) {
        local_70 = 0x20;
      }
      else {
        local_70 = 0;
        if (param_7 != 0x1403) goto LAB_00025eec;
        local_70 = 0x1a;
      }
    }
    else if (param_7 == 0x1406) {
      local_70 = 0x12;
LAB_00025e8c:
      if (param_7 == 0x1401) {
        local_70 = 9;
      }
      else if (param_7 == 0x8036) {
        local_70 = 0x23;
      }
      else {
        if (param_7 != 0x1403) goto LAB_00025eec;
        local_70 = 0x18;
      }
    }
    else {
      if (param_7 == 0x140b) {
        local_70 = 0x1e;
      }
      else if (param_7 == 0x8035) {
        local_70 = 10;
      }
      else {
        local_70 = 0;
        if (param_7 != 0x8367) goto LAB_00025e8c;
        local_70 = 9;
      }
LAB_00025eec:
      if (local_70 == 0) {
        return 0;
      }
    }
  }
  else {
    if (param_6 == 0x80e1) {
      if (param_7 == 0x8034) {
        local_70 = 7;
LAB_000261de:
        if (param_7 == 0x1401) {
LAB_00026276:
          local_70 = 8;
        }
        else {
          if (param_7 != 0x8036) {
            if (param_7 == 0x1406) {
              local_70 = 0x11;
            }
            else if (param_7 == 0x140b) {
              local_70 = 0x1d;
            }
            else {
              if (param_7 != 0x1403) goto LAB_00025eec;
              local_70 = 0x17;
            }
            goto LAB_00025ef7;
          }
          local_70 = 0x24;
        }
      }
      else if (param_7 == 0x8365) {
        local_70 = 6;
      }
      else {
        if (param_7 == 0x8367) goto LAB_00026276;
        local_70 = 0;
        if (param_7 != 0x8035) goto LAB_000261de;
        local_70 = 0xb;
      }
      goto LAB_00025eec;
    }
    if (param_6 == 0x85b9) {
      if (param_7 == 0x85ba) {
        local_70 = 0x27;
      }
      else {
        if (param_7 != 0x85bb) {
          return 0;
        }
        local_70 = 0x26;
      }
    }
    else {
      if (param_6 != 0x190a) {
        return 0;
      }
      if (param_7 == 0x1401) {
        local_70 = 4;
        goto LAB_00025eec;
      }
      if (param_7 == 0x1406) {
        local_70 = 0x16;
      }
      else if (param_7 == 0x140b) {
        local_70 = 0x22;
      }
      else {
        local_70 = 0;
        if (param_7 != 0x1403) goto LAB_00025eec;
        local_70 = 0x1c;
      }
    }
  }
LAB_00025ef7:
  if ((((0x1000 < (int)param_4) || (0x1000 < param_5)) || (0x1000 < *(int *)(param_1 + 0x15c))) ||
     (0x1000 < *(int *)(param_1 + 0x160))) {
    return 0;
  }
  _pthread_mutex_lock(*(pthread_mutex_t **)(param_1 + 0xc));
  FUN_000095f0(param_1,param_6,param_7,param_4,param_5,local_20,local_24,&local_28,
               *(int *)(param_1 + 0x10) + 0x2e50);
  uVar10 = param_8 + local_28;
  if ((int)param_4 < 1) {
    local_6c = 1;
    fVar20 = FLOAT_001c5ba4;
  }
  else {
    local_6c = param_4;
    fVar20 = (float)(int)param_4;
  }
  if (param_5 < 1) {
    local_68 = 1;
    local_34 = FLOAT_001c5ba4;
  }
  else {
    local_34 = (float)param_5;
    local_68 = param_5;
  }
  fVar17 = (float)*(int *)(param_1 + 0x15c);
  fVar21 = (float)*(int *)(param_1 + 0x160);
  fVar18 = (float)(int)(param_4 + param_2) + 0.0;
  local_54 = local_34 - (float)(param_5 + param_3);
  fVar22 = (float)param_2 + 0.0;
  if ((float)param_2 + 0.0 <= 0.0) {
    fVar22 = 0.0;
  }
  if (0.0 < local_54) {
    fVar23 = (float)((uint)local_54 ^ _DAT_001c5fe0);
  }
  else {
    local_54 = 0.0;
    fVar23 = FLOAT_001c5c00;
  }
  if (fVar17 <= fVar18) {
    fVar18 = fVar17;
  }
  fVar24 = local_34 - (float)param_3;
  if (fVar21 <= local_34 - (float)param_3) {
    fVar24 = fVar21;
  }
  fVar19 = fVar22 + (float)-param_2;
  fVar25 = (float)-param_2 + fVar18;
  fVar23 = fVar23 + (float)(local_68 - param_3);
  fVar26 = (float)(local_68 - param_3) - fVar24;
  if (fVar19 <= 0.0) {
    fVar19 = 0.0;
  }
  if (fVar26 <= 0.0) {
    fVar26 = 0.0;
  }
  if (fVar20 <= fVar25) {
    fVar25 = fVar20;
  }
  if (local_34 <= fVar23) {
    fVar23 = local_34;
  }
  if ((fVar25 <= fVar19) || (fVar23 <= fVar26)) {
    _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
    return 1;
  }
  if ((*(int *)param_10[1] != 0) && (cVar6 = FUN_0001c242(param_1,param_10,1), cVar6 == '\0')) {
LAB_00026341:
    _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
    return 0;
  }
  puVar5 = PTR_DAT_002131c9;
  if (((int *)param_10[2] == (int *)0x0) || (iVar14 = *(int *)param_10[2], iVar14 == 0)) {
    _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
    return 0;
  }
  if (uVar10 == *(uint *)*param_10) {
    if ((*(char *)(iVar14 + 0x16) != '\x06') && ((param_6 != 0x1908 || (param_7 != 0x1406))))
    goto LAB_00026341;
    if (((uVar10 | local_20[0]) & 0x1f) == 0) {
      uVar2 = *(uint *)*param_10;
      if (uVar2 != 0) {
        FUN_00009948(param_1,uVar2,local_68 * local_20[0]);
      }
      iVar14 = param_1 + 0x240;
      uVar7 = (**(code **)(param_1 + 0x2998))(iVar14,0x343);
      *(undefined4 *)(param_1 + 0x298c) = uVar7;
      iVar16 = 0xf;
      do {
        if (*(int *)(param_1 + 0x18c + iVar16 * 4) != 0) {
          uVar7 = FUN_0002ac68(param_1,0,iVar16,uVar7);
        }
        iVar16 = iVar16 + -1;
      } while (iVar16 != 0);
      puVar8 = (uint *)FUN_0002ac68(param_1,0,0,uVar7);
      local_38 = (undefined4 *)((uint)(puVar8 + 0xb) & 0xffffffe0);
      *puVar8 = (((int)local_38 - (int)puVar8) + -8) * 0x4000 | 0xc0001000;
      local_38[-1] = (int)local_38 - (int)puVar8;
      puVar3 = *(uint **)(param_1 + 0x1d8);
      *puVar3 = *puVar3 | (int)local_38 - (int)puVar3 >> 2;
      *(undefined4 **)(param_1 + 0x1d8) = local_38;
      *local_38 = 0x40000000;
      puVar4 = *(undefined4 **)param_10[2];
      puVar4[4] = puVar4[4] + 0x10000;
      local_38[2] = *puVar4;
      local_38[3] = uVar10 - *(int *)*param_10;
      uVar7 = FUN_000092a0(*(undefined2 *)(*(int *)(param_1 + 0x10) + 0x2db8),
                           *(undefined4 *)(param_1 + 0x154));
      local_38[4] = uVar7;
      _memcpy(local_38 + 5,PTR_DAT_002131cd,0x2f4);
      local_38[0x23] = 0;
      local_38[0x9f] = 0;
      local_38[0xa1] =
           param_4 & 0x3ffe | (uint)(puVar5[local_70 * 0x24 + 0x18] & 3) << 0x13 |
           ((byte)puVar5[local_70 * 0x24 + 0x1a] >> 2 & 0xf) << 0x15;
      *(byte *)(local_38 + 0x8f) =
           *(byte *)(local_38 + 0x8f) & 0xe0 |
           (byte)(*(ushort *)(puVar5 + local_70 * 0x24 + 0x1a) >> 6) & 0x1f;
      bVar11 = (byte)puVar5[local_70 * 0x24 + 0x1b] >> 3 & 3;
      bVar1 = *(byte *)((int)local_38 + 0x23d);
      *(byte *)((int)local_38 + 0x23d) = bVar1 & 0xfc | bVar11;
      bVar12 = (byte)puVar5[local_70 * 0x24 + 0x1b] >> 3 & 0xc;
      *(byte *)((int)local_38 + 0x23d) = bVar1 & 0xf0 | bVar11 | bVar12;
      bVar13 = (puVar5[local_70 * 0x24 + 0x1c] & 3) << 4;
      *(byte *)((int)local_38 + 0x23d) = bVar1 & 0xc0 | bVar11 | bVar12 | bVar13;
      *(byte *)((int)local_38 + 0x23d) =
           bVar11 | bVar12 | bVar13 | ((byte)puVar5[local_70 * 0x24 + 0x1c] >> 2) << 6;
      if ((puVar5[local_70 * 0x24 + 0x14] & 0x3f) == 0) {
        local_38[0x5b] = local_38[0x5b] & 0xfffe3fff | 0x18000;
      }
      local_38[0xb8] = local_6c - 1 & 0x1fff | (local_68 - 1U & 0x1fff) << 0xd;
      fVar17 = FLOAT_001c5ba4 / fVar17;
      fVar20 = FLOAT_001c5ba4 / fVar21;
      fVar26 = (float)param_5 - fVar26;
      fVar23 = (float)param_5 - fVar23;
      local_38[0xc2] = 0x31080;
      local_38[0xc3] = fVar17 * fVar22;
      local_38[0xc4] = (fVar21 - fVar24) * fVar20;
      local_38[0xc5] = fVar18 * fVar17;
      local_38[0xc6] = fVar20 * (fVar21 - local_54);
      local_38[199] = 0x1087;
      local_38[200] =
           (int)((fVar25 - fVar19) * FLOAT_001c5bf4) << 0x10 |
           (int)((fVar26 - fVar23) * FLOAT_001c5bf4);
      local_38[0xc9] = 0xc0033500;
      local_38[0xca] = ((unsigned char *)0x00010031);
      fVar20 = FLOAT_001c5bd4;
      local_38[0xcb] = (fVar19 + fVar25) * FLOAT_001c5bd4;
      local_38[0xcc] = (fVar26 + fVar23) * fVar20;
      local_38[0xcd] = 0;
      puVar4 = local_38 + 0xce;
      local_38[1] = (int)puVar4 - (int)puVar8 >> 2;
      puVar3 = *(uint **)(param_1 + 0x1d8);
      *puVar3 = *puVar3 | (int)puVar4 - (int)puVar3 >> 2;
      *(undefined4 **)(param_1 + 0x1d8) = puVar4;
      local_38[0xce] = 0x33000000;
      local_38[0xcf] = 0;
      local_38[0xd0] = 0x1393;
      local_38[0xd1] = 10;
      local_38[0xd2] = 0x13c6;
      local_38[0xd3] = 3;
      local_38[0xd4] = 0x5c8;
      local_38[0xd5] = 0x20000;
      local_38[0xd6] = 0x10ea;
      local_38[0xd7] = *(undefined4 *)(param_1 + 0x1cfc);
      local_38[0xd8] = 0x10fa;
      local_38[0xd9] = *(undefined4 *)(param_1 + 0x1da0);
      local_38[0xda] = 0xc0001000;
      local_38[0xdc] = 0x11004;
      local_38[0xdd] = *(undefined4 *)(param_1 + 0x1ca8);
      local_38[0xde] = *(undefined4 *)(param_1 + 0x1cac);
      local_38[0xdf] = 0x1008;
      local_38[0xe0] = *(undefined4 *)(param_1 + 0x1ca0);
      local_38[0xe1] = 0x10e9;
      local_38[0xe2] = *(undefined4 *)(param_1 + 0x1d20);
      local_38[0xe3] = 0x13c7;
      local_38[0xe4] = *(undefined4 *)(param_1 + 0x1cf0);
      local_38[0xe5] = 0x13c1;
      local_38[0xe6] = *(undefined4 *)(param_1 + 0x1ce4);
      local_38[0xe7] = 0x850;
      local_38[0xe8] = *(undefined4 *)(param_1 + 0x1dc0);
      local_38[0xe9] = 0x887;
      local_38[0xea] = *(undefined4 *)(param_1 + 0x1db4);
      local_38[0x18b] = 0x82c;
      local_38[0x18c] = *(undefined4 *)(param_1 + 0x1dc4);
      local_38[0xeb] = 0x10ae;
      local_38[0xec] = *(undefined4 *)(param_1 + 0x1d70);
      local_38[0xed] = 0x1394;
      local_38[0xee] = *(undefined4 *)(param_1 + 0x1d30);
      local_38[0xef] = 0x1380;
      local_38[0xf0] = 0;
      local_38[0xf1] = 0x1002;
      local_38[0xf2] = *(undefined4 *)(param_1 + 0x1d90);
      local_38[0xf2] = *(undefined4 *)(param_1 + 0x1d90);
      local_38[0xf3] = 0x824;
      local_38[0xf4] = *(undefined4 *)(param_1 + 0x1ddc);
      local_38[0xf5] = 0x825;
      local_38[0xf6] = *(undefined4 *)(param_1 + 0x1de0);
      local_38[0xf7] = 0x82d;
      local_38[0xf8] = *(undefined4 *)(param_1 + 0x26cc);
      local_38[0xf9] = 0x854;
      local_38[0xfa] = **(undefined4 **)(param_1 + 0x2680);
      local_38[0xfb] = 0x878;
      local_38[0xfc] = **(undefined4 **)(param_1 + 0x2684);
      local_38[0xfd] = &switchdataD_000013c0;
      local_38[0xfe] = *(undefined4 *)(param_1 + 0x1ce0);
      local_38[0xff] = 0x12f0;
      local_38[0x100] = *(undefined4 *)(param_1 + 0x1d2c);
      puVar5 = PTR_DAT_002131c9;
      if ((PTR_DAT_002131c9[(uint)*(byte *)(param_1 + 0x2b7f) * 0x24 + 0x1a] & 1) == 0) {
        *(byte *)(local_38 + 0x100) = *(byte *)(local_38 + 0x100) & 0xfe;
      }
      local_38[0x101] = 0x12f5;
      local_38[0x102] = *(undefined4 *)(param_1 + 0x1c8c);
      if ((puVar5[(uint)*(byte *)(param_1 + 0x2b7f) * 0x24 + 0x1a] & 1) == 0) {
        *(byte *)((int)local_38 + 0x409) = *(byte *)((int)local_38 + 0x409) & 0xf7;
      }
      local_38[0x103] = 0x10a2;
      local_38[0x104] = *(undefined4 *)(param_1 + 0x1d7c);
      local_38[0x105] = 0x1381;
      local_38[0x106] = *(undefined4 *)(param_1 + 0x1cc0);
      if ((puVar5[(uint)*(byte *)(param_1 + 0x2b7f) * 0x24 + 0x1a] & 2) == 0) {
        *(byte *)(local_38 + 0x106) = *(byte *)(local_38 + 0x106) & 0xfc;
      }
      local_38[0x107] = 0x109e;
      local_38[0x108] = *(undefined4 *)(param_1 + 0x1d6c);
      local_38[0x109] = 0x1096;
      local_38[0x108] = *(undefined4 *)(param_1 + 0x1df8);
      local_38[0x10b] = 0x1041;
      local_38[0x10c] = *(undefined4 *)(param_1 + 0x29f0);
      local_38[0x10d] = 0x1046;
      local_38[0x10e] = *(undefined4 *)(param_1 + 0x1dfc);
      local_38[0x10f] = 0x1094;
      local_38[0x110] = 0;
      local_38[0x111] = 0x1095;
      local_38[0x113] = 0x1095;
      local_38[0x115] = 0x1095;
      local_38[0x117] = 0x1095;
      local_38[0x119] = 0x1095;
      local_38[0x11b] = 0x1095;
      local_38[0x11d] = 0x1095;
      local_38[0x11f] = 0x1095;
      local_38[0x121] = 0x1095;
      local_38[0x123] = 0x1095;
      local_38[0x125] = 0x1095;
      local_38[0x127] = 0x1095;
      local_38[0x129] = 0xc0221000;
      local_38[0x14d] = 0x1180;
      local_38[0x14e] = 2;
      local_38[0x14f] = 0x1189;
      local_38[0x151] = 0x1181;
      local_38[0x153] = 0x118d;
      local_38[0x155] = 0x118e;
      local_38[0x157] = 0x118c;
      local_38[0x159] = 0x11a9;
      local_38[0x15a] = *(undefined4 *)(param_1 + 0x257c);
      local_38[0x15b] = 0x11aa;
      local_38[0x15c] = *(undefined4 *)(param_1 + 0x2580);
      local_38[0x15d] = 0x11ab;
      local_38[0x15e] = *(undefined4 *)(param_1 + 0x2584);
      local_38[0x15f] = 0x11ac;
      local_38[0x160] = *(undefined4 *)(param_1 + 0x2588);
      local_38[0x161] = 0x10c0;
      local_38[0x162] = *(undefined4 *)(param_1 + 0x216c);
      local_38[0x163] = 0x10c1;
      local_38[0x165] = 0x10c8;
      local_38[0x167] = 0x101d;
      local_38[0x168] = *(undefined4 *)(param_1 + 0x2128);
      local_38[0x169] = 0x138a;
      local_38[0x16a] = 0;
      local_38[0x16b] = 0x138e;
      local_38[0x16c] = 0;
      local_38[0x16d] = 0x1040;
      local_38[0x16e] = 0;
      local_38[0x16f] = 0x1150;
      local_38[0x170] = 0;
      local_38[0x171] = 0x1100;
      local_38[0x172] = *(undefined4 *)(param_1 + 0x1f1c);
      local_38[0x173] = 0x1110;
      local_38[0x174] = *(undefined4 *)(param_1 + 0x1f5c);
      local_38[0x175] = 0x1120;
      local_38[0x176] = *(undefined4 *)(param_1 + 0x1f9c);
      local_38[0x177] = 0x1130;
      local_38[0x178] = *(undefined4 *)(param_1 + 0x1fdc);
      local_38[0x179] = 0x1140;
      local_38[0x17a] = *(undefined4 *)(param_1 + 0x201c);
      local_38[0x17b] = 0x10f4;
      local_38[0x17c] = 0xaaaa;
      local_38[0x17d] = 0x1383;
      local_38[0x17e] = *(undefined4 *)(param_1 + 0x1d34);
      local_38[0x17f] = 0x1386;
      local_38[0x180] = *(undefined4 *)(param_1 + 0x1d38);
      local_38[0x181] = 0x110f8;
      local_38[0x182] = *(undefined4 *)(param_1 + 0x1d98);
      local_38[0x183] = *(undefined4 *)(param_1 + 0x1d50);
      local_38[0x184] = 0x1087;
      local_38[0x185] = *(undefined4 *)(param_1 + 0x1f0c);
      local_38[0x186] = 0x31080;
      local_38[0x187] = *(undefined4 *)(param_1 + 0x1efc);
      local_38[0x188] = *(undefined4 *)(param_1 + 0x1f04);
      local_38[0x189] = *(undefined4 *)(param_1 + 0x1f00);
      local_38[0x18a] = *(undefined4 *)(param_1 + 0x1f08);
      FUN_0004acbc(local_38 + 0xd0,iVar14);
      local_38 = local_38 + 0x18d;
      iVar16 = 0;
      local_7c = 0;
      do {
        iVar9 = *(int *)(param_1 + 0x18c + iVar16 * 4);
        if (iVar9 != 0) {
          iVar15 = 0;
          do {
            if (iVar9 == *(int *)(*(int *)(param_1 + 0x18) + (local_7c + iVar15) * 4)) {
              if (*(int *)(iVar9 + 0x34) != 0) goto LAB_00026e16;
              break;
            }
            iVar15 = iVar15 + 1;
          } while (iVar15 != 5);
          iVar9 = 0;
        }
LAB_00026e16:
        if ((iVar16 == 0) || (iVar9 != 0)) {
          local_38 = (undefined4 *)FUN_0002ac68(param_1,iVar9,iVar16,local_38);
        }
        iVar16 = iVar16 + 1;
        local_7c = local_7c + 5;
        if (iVar16 == 0x10) {
          *(undefined4 **)(param_1 + 0x298c) = local_38;
          (**(code **)(param_1 + 0x299c))(iVar14,local_38);
          _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
          if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
            FUN_00017c77(param_1,0x1000000);
          }
          if (*(int *)*param_10 == 0) {
            return 1;
          }
          FUN_00009948(param_1,*(int *)*param_10,local_68 * local_20[0]);
          return 1;
        }
      } while( true );
    }
  }
  _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
  return 0;
}

/* FUN_00026ee1 @ 0x26ee1 (3037 bytes) */
int FUN_00026ee1(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
  int param_7;
  int param_8;
  int param_9;
  int param_10;
{
  byte bVar1;
  ushort uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  int *piVar5;
  int *piVar6;
  bool bVar7;
  bool bVar8;
  undefined1 uVar9;
  char cVar10;
  int iVar11;
  int iVar12;
  void *pvVar13;
  int iVar14;
  undefined4 *puVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  uint local_e4;
  int local_e0;
  uint local_b8;
  uint local_b4;
  uint local_b0;
  uint local_ac;
  uint local_a8;
  uint local_a4;
  undefined1 local_a0 [4];
  undefined1 local_9c [4];
  undefined4 local_98;
  uint local_94;
  uint local_90;
  int local_8c;
  int local_88;
  undefined4 local_84;
  undefined4 local_80;
  uint local_7c;
  uint local_78;
  uint local_74;
  undefined4 local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  undefined4 local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  undefined4 local_50;
  undefined1 local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  uint local_34;
  uint local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  uint local_20 [4];
  
  iVar16 = param_1 + 0x240;
  local_2c = 0;
  iVar14 = *(int *)(param_1 + 0x10);
  local_84 = 0;
  local_80 = 0;
  iVar11 = FUN_000092a0(*(undefined2 *)(iVar14 + 0x2db8),*(undefined4 *)(param_1 + 0x154));
  if (((((*(ushort *)(iVar14 + 0x30b0) & 0x1ff) == 0) &&
       ((*(uint *)(iVar14 + 0x30b4) & 0xff0000) == 0)) || (param_6 - 0x1901U < 2)) ||
     (param_9 == '\x02')) {
    iVar17 = 0;
    bVar8 = false;
  }
  else if ((*(uint *)(iVar14 + 0x30b0) & 2) == 0) {
    if (((*(uint *)(iVar14 + 0x30b0) & 4) == 0) || (*(short *)(iVar14 + 0x2fe8) != -0x7fea))
    goto LAB_00026fb9;
    iVar17 = *(int *)(iVar14 + 0x2ff0) + -1;
    bVar8 = true;
  }
  else if (*(short *)(iVar14 + 0x2fa8) == -0x7fea) {
    iVar17 = *(int *)(iVar14 + 0x2fb0) + -1;
    bVar8 = true;
  }
  else {
LAB_00026fb9:
    iVar17 = 0;
    bVar8 = true;
  }
  if (param_10 != 0) {
    if (bVar8) {
      return 0;
    }
    uVar9 = ((int (*)())FUN_00025ded)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                         param_10);
    return uVar9;
  }
  if (param_9 == '\x02') {
    iVar12 = 0;
  }
  else {
    iVar12 = iVar14 + 0x2e50;
  }
  FUN_000095f0(param_1,param_6,param_7,param_4 - iVar17,param_5,local_20,&local_24,&local_28,iVar12)
  ;
  local_e4 = param_8 + local_28;
  if (param_3 < 0) {
    param_5 = param_5 + param_3;
    local_e4 = local_e4 - param_3 * local_20[0];
    param_3 = 0;
  }
  if (param_2 < 0) {
    param_4 = param_4 + param_2;
    local_e4 = local_e4 - param_2 * local_24;
    param_2 = 0;
  }
  iVar17 = *(int *)(param_1 + 0x160) - param_3;
  if (param_3 + param_5 <= *(int *)(param_1 + 0x160)) {
    iVar17 = param_5;
  }
  if (*(int *)(param_1 + 0x15c) < param_2 + param_4) {
    param_4 = *(int *)(param_1 + 0x15c) - param_2;
  }
  if (param_4 < 1) {
    return 1;
  }
  if (iVar17 < 1) {
    return 1;
  }
  if (param_9 == '\x02') {
    local_94 = 0;
    local_90 = 0;
    local_e0 = 0;
  }
  else {
    local_94 = -(uint)(param_9 == '\0') & 0x20000;
    local_90 = 0x7efff;
    local_e0 = iVar14 + 0x2e48;
    if (*(char *)(iVar14 + 0x2e68) != '\0') {
      local_94 = local_94 | 2;
    }
    if (*(char *)(iVar14 + 0x2e69) != '\0') {
      local_94 = local_94 | 8;
    }
  }
  local_98 = 2;
  local_4c = 0;
  local_a8 = local_e4;
  local_a4 = local_20[0];
  local_8c = param_4;
  local_88 = iVar17;
  _glgConvertType(param_6,param_7,local_a0,local_9c);
  piVar5 = *(int **)(param_1 + 0x150);
  if (piVar5 != (int *)0x0) {
    if (param_6 == 0x1901) {
      iVar14 = 5;
    }
    else if (param_6 == 0x1902) {
      iVar14 = 4;
    }
    else {
      iVar14 = *(ushort *)(*piVar5 + 0x98) - 0x8ce0;
      local_94 = local_94 | 0x60000;
      local_90 = local_90 | 0x68002;
      if ((param_9 != '\x02') &&
         (((*(ushort *)(local_e0 + 0x268) & 0x1ff) != 0 ||
          ((*(uint *)(local_e0 + 0x26c) & 0xff0000) != 0)))) {
        iVar11 = *(int *)(param_1 + 0x18);
        iVar16 = *(int *)(*(int *)(iVar11 + 0x140) + 0x30);
        local_7c = (uint)*(ushort *)(iVar16 + 0x98);
        local_78 = (uint)*(ushort *)(iVar16 + 0x9a);
        local_74 = (uint)*(ushort *)(iVar16 + 0x8c);
        local_70 = *(undefined4 *)(iVar16 + 0x9c);
        iVar16 = *(int *)(*(int *)(iVar11 + 0x148) + 0x30);
        local_6c = (uint)*(ushort *)(iVar16 + 0x98);
        local_68 = (uint)*(ushort *)(iVar16 + 0x9a);
        local_64 = (uint)*(ushort *)(iVar16 + 0x8c);
        local_60 = *(undefined4 *)(iVar16 + 0x9c);
        iVar11 = *(int *)(*(int *)(iVar11 + 0x144) + 0x30);
        local_5c = (uint)*(ushort *)(iVar11 + 0x98);
        local_58 = (uint)*(ushort *)(iVar11 + 0x9a);
        local_54 = (uint)*(ushort *)(iVar11 + 0x8c);
        local_50 = *(undefined4 *)(iVar11 + 0x9c);
      }
    }
    piVar6 = *(int **)(piVar5[1] + iVar14 * 4);
    if (piVar6 == (int *)0x0) {
      return 1;
    }
    iVar16 = iVar14 * 0x18 + *piVar5;
    iVar14 = *(int *)(iVar16 + 4);
    iVar11 = *(int *)(iVar16 + 8);
    iVar16 = *(int *)(iVar16 + 0xc);
    uVar2 = *(ushort *)(*piVar6 + 0x18);
    iVar17 = iVar14 * 0x168 + iVar11 * 0x18 + piVar6[0xc];
    uVar3 = *(undefined2 *)(iVar17 + 0xb0);
    uVar4 = *(undefined2 *)(iVar17 + 0xb2);
    _glgConvertType(uVar3,uVar4,&local_b0,&local_ac);
    iVar17 = *(int *)(param_1 + 0x15c);
    iVar12 = FUN_00009369(uVar3,uVar4);
    local_b4 = iVar17 * iVar12;
    iVar17 = local_b4 * *(int *)(param_1 + 0x160);
    pvVar13 = _valloc((uint)uVar2 * iVar17);
    FUN_0002ec62(param_1,piVar6,iVar14,iVar11,uVar3,uVar4,pvVar13,local_b4);
    param_3 = param_3 * local_b4;
    iVar14 = FUN_00009369(uVar3,uVar4);
    local_b8 = (int)pvVar13 + iVar14 * param_2 + iVar16 * iVar17 + param_3;
    _glgProcessPixels(local_e0,&local_b8);
    _vfree(pvVar13);
    return 1;
  }
  local_48 = param_2;
  local_44 = param_3;
  local_40 = param_4;
  local_3c = iVar17;
  if (param_6 == 0x1901) {
    uVar18 = *(uint *)(param_1 + 0x154);
    if ((uVar18 & 0x30000) != 0x30000) {
      return 1;
    }
    if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
      FUN_00017c77(param_1,0x1000000);
      uVar18 = *(uint *)(param_1 + 0x154);
    }
    local_b4 = (param_4 + 0xfU & 0xfffffff0) << 2;
    local_ac = 0x14;
    local_b0 = 0xf;
LAB_00027866:
    if ((uVar18 & 0x2000) == 0) {
LAB_00027885:
      local_38 = 4;
    }
    else if (iVar11 == 7) {
      local_38 = 10;
    }
    else {
      if (iVar11 != 8) goto LAB_00027885;
      local_38 = 0xb;
    }
  }
  else {
    if (param_6 == 0x1902) {
      uVar18 = *(uint *)(param_1 + 0x154);
      if ((uVar18 & 0x30000) == 0) {
        return 1;
      }
      if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
        FUN_00017c77(param_1,0x1000000);
        uVar18 = *(uint *)(param_1 + 0x154);
      }
      if ((uVar18 & 0x20000) == 0) {
        local_b4 = (param_4 + 0x1fU & 0xffffffe0) * 2;
        local_b0 = 0xd;
        local_ac = 2;
      }
      else {
        local_b4 = (param_4 + 0xfU & 0xfffffff0) << 2;
        if ((uVar18 & 0x30000) == 0x30000) {
          local_b0 = 0xf;
          local_ac = 0x14;
        }
        else {
          local_b0 = 0xd;
          local_ac = 4;
        }
      }
      goto LAB_00027866;
    }
    cVar10 = FUN_00017bd8(param_1,iVar11);
    if (cVar10 != '\0') {
      ((int (*)())FUN_00020d0f)(param_1,0,iVar11,0,0,0,*(undefined4 *)(param_1 + 0x15c),
                   *(undefined4 *)(param_1 + 0x160));
    }
    if (*(int *)(param_1 + 0x1d38) != 0) {
      puVar15 = (undefined4 *)(**(code **)(param_1 + 0x2998))(iVar16,2);
      *puVar15 = 0x1386;
      puVar15[1] = 0;
      *(undefined4 **)(param_1 + 0x298c) = puVar15 + 2;
      (**(code **)(param_1 + 0x299c))(iVar16,puVar15 + 2);
    }
    if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
      FUN_00017c77(param_1,0x1000000);
    }
    if (*(int *)(param_1 + 0x1d38) != 0) {
      puVar15 = (undefined4 *)(**(code **)(param_1 + 0x2998))(iVar16,2);
      *puVar15 = 0x1386;
      puVar15[1] = *(undefined4 *)(param_1 + 0x1d38);
      *(undefined4 **)(param_1 + 0x298c) = puVar15 + 2;
      (**(code **)(param_1 + 0x299c))(iVar16,puVar15 + 2);
    }
    bVar1 = *(byte *)(param_1 + 0x2b7f);
    local_b4 = (param_4 << ((byte)PTR_DAT_002131c9[(uint)bVar1 * 0x24 + 0x17] >> 5)) + 0x1fU &
               0xffffffe0;
    local_ac = *(ushort *)(PTR_DAT_002131c9 + (uint)bVar1 * 0x24 + 0x10) >> 5 & 0x1f;
    local_b0 = (uint)(PTR_DAT_002131c9[(uint)bVar1 * 0x24 + 0x10] & 0x1f);
    uVar18 = *(uint *)(param_1 + 0x154);
    local_38 = iVar11;
  }
  if (((bVar8) ||
      (((param_9 != '\x02' &&
        (((*(uint *)(iVar14 + 0x30b4) & 0xff1) != 0 || (*(short *)(iVar14 + 0x2e68) != 0)))) ||
       (param_6 - 0x1901U < 2)))) ||
     (((local_30 = local_a4, (local_a4 & 0x3f) != 0 || (0x1fff < (int)local_a4)) ||
      ((local_a8 & 0x1f) != 0)))) {
LAB_00027676:
    uVar18 = iVar17 * local_b4 + 0xfff & 0xfffff000;
    local_30 = local_b4;
    if (*(uint *)(param_1 + 0x2b78) < uVar18) {
      if (*(int *)(param_1 + 0x2b74) != 0) {
        _vfree(*(int *)(param_1 + 0x2b74));
      }
      pvVar13 = _valloc(uVar18);
      *(void **)(param_1 + 0x2b74) = pvVar13;
      *(uint *)(param_1 + 0x2b78) = uVar18;
    }
    local_34 = *(uint *)(param_1 + 0x2b74);
    if (local_34 == 0) {
      return 0;
    }
    bVar7 = false;
  }
  else {
    if ((uVar18 & 0xf) == 4) {
      if ((param_6 != 0x80e1) || (param_7 != 0x8367)) goto LAB_00027676;
    }
    else if (((uVar18 & 0xf) != 3) || ((param_6 != 0x80e1 || (param_7 != 0x8366))))
    goto LAB_00027676;
    local_34 = local_a8;
    bVar7 = true;
  }
  local_b8 = local_34;
  if (bVar8) {
    iVar14 = *(int *)(param_1 + 0x18);
    iVar11 = *(int *)(*(int *)(iVar14 + 0x140) + 0x30);
    local_7c = (uint)*(ushort *)(iVar11 + 0x98);
    local_78 = (uint)*(ushort *)(iVar11 + 0x9a);
    local_74 = (uint)*(ushort *)(iVar11 + 0x8c);
    local_70 = *(undefined4 *)(iVar11 + 0x9c);
    iVar11 = *(int *)(*(int *)(iVar14 + 0x148) + 0x30);
    local_6c = (uint)*(ushort *)(iVar11 + 0x98);
    local_68 = (uint)*(ushort *)(iVar11 + 0x9a);
    local_64 = (uint)*(ushort *)(iVar11 + 0x8c);
    local_60 = *(undefined4 *)(iVar11 + 0x9c);
    iVar14 = *(int *)(*(int *)(iVar14 + 0x144) + 0x30);
    local_5c = (uint)*(ushort *)(iVar14 + 0x98);
    local_58 = (uint)*(ushort *)(iVar14 + 0x9a);
    local_54 = (uint)*(ushort *)(iVar14 + 0x8c);
    local_50 = *(undefined4 *)(iVar14 + 0x9c);
  }
  iVar14 = _io_connect_method_structureI_structureO
                     (*(undefined4 *)(param_1 + 4),7,&local_48,0x1c,0,&local_2c);
  if (iVar14 != 0) {
    return 0;
  }
  if (bVar7) {
    return 1;
  }
  _glgProcessPixels(local_e0,&local_b8);
  return 1;
}

/* FUN_00027abe @ 0x27abe (2035 bytes) */
int FUN_00027abe(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11)
  int param_1;
  float *param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
  int param_7;
  int param_8;
  int param_9;
  int param_10;
  int param_11;
{
  undefined4 uVar1;
  float fVar2;
  undefined1 auVar3 [12];
  undefined1 auVar4 [12];
  float fVar5;
  float fVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  int iVar10;
  undefined4 *puVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  float *pfVar15;
  float *pfVar16;
  float fVar17;
  undefined1 *local_130;
  float local_104;
  int local_fc;
  float local_f8;
  int local_dc;
  int local_d8;
  float *local_d4;
  int local_d0;
  undefined1 local_c8 [140];
  float local_3c;
  float local_38;
  float local_34;
  undefined4 local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
  iVar10 = param_1 + 0x240;
  uVar1 = *(undefined4 *)(param_1 + 0x248);
  iVar14 = *(int *)(*(int *)(param_1 + 0x244) + 0x10);
  pfVar16 = (float *)(iVar14 + 0x2e48);
  if (*pfVar16 <= 0.0 && *pfVar16 != 0.0) {
    local_f8 = FLOAT_001c5bdc;
  }
  else {
    local_f8 = FLOAT_001c5ba4;
  }
  pfVar16 = (float *)(iVar14 + 0x2e4c);
  fVar5 = FLOAT_001c5bdc;
  if (0.0 < *pfVar16 || *pfVar16 == 0.0) {
    fVar5 = FLOAT_001c5ba4;
  }
  if (param_10 == 0x1901) {
    FUN_000827ac(iVar10,0,0,1,local_c8);
    iVar14 = param_3 * param_4 * 0x10 + 0x19;
  }
  else {
    if (param_11 == '\0') {
      uVar13 = 0;
      if (param_10 == 0x1902) {
        uVar13 = 0x1000;
      }
      FUN_000a46ec(iVar10,(*(byte *)(param_1 + 0x1cf8) ^ 1) & 1 | uVar13,local_c8);
      FUN_0004a17c(iVar10,*(uint *)(param_1 + 0x1ae4) >> 6 & 0xffff);
      *(ushort *)(param_1 + 0x216c) = *(ushort *)(param_1 + 0x216c) & 0xf87f | 0x80;
      *(byte *)(param_1 + 0x216c) = *(byte *)(param_1 + 0x216c) & 0x80;
    }
    else {
      FUN_000827ac(iVar10,1,0,0,local_c8);
    }
    iVar14 = param_3 * param_4 * 8 + 0x1b;
  }
  local_130 = local_c8;
  if (*(char *)(param_1 + 0x2a42) == '\0') {
    iVar14 = iVar14 + 2;
  }
  puVar11 = (undefined4 *)(**(code **)(param_1 + 0x2998))(iVar10,iVar14);
  *(undefined4 **)(param_1 + 0x298c) = puVar11;
  if (*(char *)(param_1 + 0x2a42) == '\0') {
    *puVar11 = 0x5c8;
    puVar11[1] = 0x10000000;
    puVar11 = puVar11 + 2;
    *(undefined1 *)(param_1 + 0x2a42) = 1;
  }
  *puVar11 = 0x10c0;
  puVar11[1] = *(undefined4 *)(param_1 + 0x216c);
  puVar11 = (undefined4 *)FUN_0007edb0(iVar10,puVar11 + 2);
  dVar9 = DOUBLE_001cf368;
  dVar8 = _UNK_001c6008;
  dVar7 = _DAT_001c6000;
  (*(unsigned int *)((unsigned char *)&(auVar3) + 4)) = uVar1;
  (*(unsigned int *)((unsigned char *)&(auVar3) + 0)) = uVar1;
  (*(unsigned int *)((unsigned char *)&(auVar3) + 8)) = _UNK_001c5ff4;
  uVar13 = (uint)((((double)((ulonglong)_DAT_001c5ff0 << 0x20) - _DAT_001c6000) +
                  ((*(unsigned long long *)((unsigned char *)&(auVar3) + 4)) - _UNK_001c6008)) * DOUBLE_001cf368);
  *puVar11 = 0x1087;
  puVar11[1] = uVar13 & 0xffff | uVar13 << 0x10;
  uVar1 = _UNK_001c5ff4;
  uVar13 = _DAT_001c5ff0;
  fVar17 = FLOAT_001c5bd4;
  pfVar16 = (float *)(puVar11 + 2);
  local_30 = 0x3f800000;
  local_28 = FLOAT_001c5bd4 / *(float *)(param_1 + 0x2a58) + (float)param_8;
  if (param_10 == 0x1901) {
    local_104 = (float)CONCAT22((short)((uint)*(undefined4 *)(param_1 + 0x1ce8) >> 0x10),0xff00);
    if (param_4 != 0) {
      fVar17 = (float)param_7 + FLOAT_001c5bd4 / *(float *)(param_1 + 0x2a54);
      local_fc = 0;
      do {
        local_24 = fVar17;
        if (param_3 != 0) {
          local_d4 = param_2;
          local_dc = 1;
          do {
            local_2c = *(float *)(param_9 + 8);
            local_34 = *(float *)(param_9 + 0x30);
            local_38 = *(float *)(param_9 + 0x34);
            local_3c = *(float *)(param_9 + 0x38);
            local_20 = *(float *)(param_9 + 0x3c);
            local_104 = (float)CONCAT31((int3)((uint)local_104 >> 8),*(undefined1 *)local_d4);
            *pfVar16 = 7.08777e-42;
            pfVar16[1] = local_104;
            (*(unsigned int *)((unsigned char *)&(auVar4) + 4)) = *(undefined4 *)(param_1 + 0x248);
            (*(unsigned int *)((unsigned char *)&(auVar4) + 0)) = *(undefined4 *)(param_1 + 0x248);
            (*(unsigned int *)((unsigned char *)&(auVar4) + 8)) = uVar1;
            uVar12 = (uint)((((double)((ulonglong)uVar13 << 0x20) - dVar7) + ((*(unsigned long long *)((unsigned char *)&(auVar4) + 4)) - dVar8))
                           * dVar9);
            pfVar16[2] = 5.92889e-42;
            pfVar16[3] = (float)(uVar12 & 0xffff | uVar12 << 0x10);
            pfVar16[4] = -2.1282349;
            pfVar16[5] = (float)0x00010031;
            pfVar16[6] = local_24;
            pfVar16[7] = local_28;
            pfVar16[8] = local_2c;
            pfVar16[9] = 1.0;
            pfVar16[10] = local_34;
            pfVar16[0xb] = local_38;
            pfVar16[0xc] = local_3c;
            pfVar16[0xd] = local_20;
            pfVar16[0xe] = 5.92889e-42;
            pfVar16[0xf] = *(float *)(param_1 + 0x1f0c);
            pfVar16 = pfVar16 + 0x10;
            local_24 = local_f8 + local_24;
            local_d4 = (float *)((int)local_d4 + param_6);
            local_dc = local_dc + 1;
          } while (param_3 + 1 != local_dc);
        }
        local_28 = fVar5 + local_28;
        param_2 = (float *)((int)param_2 + param_5);
        local_fc = local_fc + 1;
      } while (param_4 != local_fc);
    }
  }
  else {
    puVar11[2] = param_3 * param_4 * 0x80000 | 0xc0003500;
    puVar11[3] = param_3 * param_4 * 0x10000 | 0x31;
    pfVar16 = (float *)(puVar11 + 4);
    if (param_4 != 0) {
      local_d0 = 0;
      do {
        fVar6 = FLOAT_001c5bb8;
        local_24 = (float)param_7 + fVar17;
        if (param_3 != 0) {
          local_d8 = 1;
          pfVar15 = param_2;
          do {
            if (param_10 == 0x1902) {
              local_2c = *pfVar15;
              local_34 = *(float *)(param_9 + 0x30);
              local_38 = *(float *)(param_9 + 0x34);
              local_3c = *(float *)(param_9 + 0x38);
              local_20 = *(float *)(param_9 + 0x3c);
            }
            else {
              local_2c = *(float *)(param_9 + 8);
              fVar2 = *pfVar15;
              local_20 = (float)((uint)fVar2 >> 0x18) / fVar6;
              local_34 = (float)((uint)fVar2 >> 0x10 & 0xff) / fVar6;
              local_38 = (float)((uint)fVar2 >> 8 & 0xff) / fVar6;
              local_3c = (float)((uint)fVar2 & 0xff) / fVar6;
            }
            *pfVar16 = local_24;
            pfVar16[1] = local_28;
            pfVar16[2] = local_2c;
            pfVar16[3] = 1.0;
            pfVar16[4] = local_34;
            pfVar16[5] = local_38;
            pfVar16[6] = local_3c;
            pfVar16[7] = local_20;
            pfVar16 = pfVar16 + 8;
            local_24 = local_f8 + local_24;
            pfVar15 = (float *)((int)pfVar15 + param_6);
            local_d8 = local_d8 + 1;
          } while (local_d8 != param_3 + 1);
        }
        local_28 = fVar5 + local_28;
        param_2 = (float *)((int)param_2 + param_5);
        local_d0 = local_d0 + 1;
      } while (param_4 != local_d0);
    }
  }
  *pfVar16 = 5.92889e-42;
  pfVar16[1] = *(float *)(param_1 + 0x1f0c);
  *(float **)(param_1 + 0x298c) = pfVar16 + 2;
  (**(code **)(param_1 + 0x299c))(iVar10,pfVar16 + 2);
  FUN_0009b2d9(iVar10);
  FUN_00082e73(iVar10,local_130);
  return;
}

/* FUN_000282b1 @ 0x282b1 (354 bytes) */
int FUN_000282b1(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 uVar1;
  undefined1 auVar2 [12];
  undefined4 uVar3;
  undefined4 *puVar4;
  uint uVar5;
  
  uVar1 = *(undefined4 *)(param_1 + 8);
  FUN_000a46ec(param_1,(*(byte *)(param_1 + 0x1ab8) ^ 1) & 1,param_2);
  FUN_0004a17c(param_1,*(uint *)(param_1 + 0x18a4) >> 6 & 0xffff);
  uVar3 = (**(code **)(param_1 + 0x2758))(param_1,0x1f);
  *(undefined4 *)(param_1 + 0x274c) = uVar3;
  puVar4 = (undefined4 *)FUN_0007edb0(param_1,uVar3);
  *puVar4 = 0x10c0;
  puVar4[1] = 0x80;
  *(undefined4 **)(param_1 + 0x274c) = puVar4 + 2;
  (*(unsigned int *)((unsigned char *)&(auVar2) + 4)) = uVar1;
  (*(unsigned int *)((unsigned char *)&(auVar2) + 0)) = uVar1;
  (*(unsigned int *)((unsigned char *)&(auVar2) + 8)) = _UNK_001c6014;
  uVar5 = (uint)((((double)((ulonglong)_DAT_001c6010 << 0x20) - _DAT_001c6020) +
                 ((*(unsigned long long *)((unsigned char *)&(auVar2) + 4)) - _UNK_001c6028)) * DOUBLE_001cf368);
  puVar4[2] = 0x1087;
  puVar4[3] = uVar5 & 0xffff | uVar5 << 0x10;
  puVar4[4] = 0x12f0;
  puVar4[5] = 0;
  *(undefined4 *)(param_1 + 0x1b84) = 0;
  *(byte *)(param_1 + 0x1b84) = *(byte *)(param_1 + 0x1b84) | 5;
  *(undefined4 *)(param_1 + 0x1c8c) = *(undefined4 *)(param_1 + 0x2814);
  *(undefined4 *)(param_1 + 0x1c94) = *(undefined4 *)(param_1 + 0x2818);
  puVar4[6] = 0x82c;
  puVar4[7] = *(undefined4 *)(param_1 + 0x1b84);
  puVar4[8] = 0x766;
  puVar4[9] = *(undefined4 *)(param_1 + 0x1c8c);
  puVar4[10] = 0x768;
  puVar4[0xb] = *(undefined4 *)(param_1 + 0x1c94);
  *(undefined4 **)(param_1 + 0x274c) = puVar4 + 0xc;
                    
                    
  (**(code **)(param_1 + 0x275c))();
  return;
}

/* FUN_00028413 @ 0x28413 (4760 bytes) */
int FUN_00028413(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  uint param_5;
  int param_6;
  int param_7;
  int param_8;
  undefined4 *param_9;
{
  float fVar1;
  byte bVar2;
  byte bVar3;
  uint *puVar4;
  undefined4 *puVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  undefined *puVar9;
  char cVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  undefined4 uVar14;
  uint *puVar15;
  byte bVar16;
  byte bVar17;
  byte bVar18;
  int iVar19;
  int iVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float local_140;
  int local_124;
  int local_64;
  int local_60;
  int local_5c;
  float local_48;
  undefined4 *local_44;
  float local_40;
  int local_28;
  undefined1 local_24 [4];
  uint local_20 [4];
  
  if (param_5 == 0x1909) {
    if (param_6 == 0x1401) {
      local_64 = 1;
      goto LAB_00028510;
    }
    if (param_6 == 0x1406) {
      local_64 = 0x13;
    }
    else if (param_6 == 0x140b) {
      local_64 = 0x1f;
    }
    else {
      local_64 = 0;
      if (param_6 != 0x1403) goto LAB_00028510;
      local_64 = 0x19;
    }
  }
  else if (param_5 < 0x190a) {
    if (param_5 == 0x1907) {
      if (param_6 == 0x8363) {
        local_64 = 5;
      }
      else {
        if (param_6 != 0x8032) {
          return 0;
        }
        local_64 = 0x28;
      }
    }
    else if (param_5 < 0x1908) {
      if (param_5 != 0x1906) {
        return 0;
      }
      if (param_6 == 0x1401) {
        local_64 = 2;
        goto LAB_00028510;
      }
      if (param_6 == 0x1406) {
        local_64 = 0x14;
      }
      else if (param_6 == 0x140b) {
        local_64 = 0x20;
      }
      else {
        local_64 = 0;
        if (param_6 != 0x1403) goto LAB_00028510;
        local_64 = 0x1a;
      }
    }
    else {
      if (param_6 != 0x1406) {
        if (param_6 == 0x8035) {
          local_64 = 10;
        }
        else {
          if (param_6 != 0x8367) {
            local_64 = 0;
            if (param_6 == 0x1401) {
              local_64 = 9;
              goto LAB_0002851b;
            }
            goto LAB_000284bc;
          }
          local_64 = 9;
        }
        goto LAB_00028510;
      }
      local_64 = 0x12;
LAB_000284bc:
      if (param_6 == 0x8036) {
        local_64 = 0x23;
      }
      else {
        if (param_6 != 0x1403) goto LAB_00028510;
        local_64 = 0x18;
      }
    }
  }
  else if (param_5 == 0x80e1) {
    if (param_6 == 0x8366) {
      local_64 = 7;
LAB_000288cb:
      if (param_6 != 0x8036) {
        if (param_6 == 0x1406) {
          local_64 = 0x11;
        }
        else if (param_6 == 0x140b) {
          local_64 = 0x1d;
        }
        else {
          if (param_6 != 0x1403) goto LAB_00028510;
          local_64 = 0x17;
        }
        goto LAB_0002851b;
      }
      local_64 = 0x24;
    }
    else if (param_6 == 0x8365) {
      local_64 = 6;
    }
    else if (param_6 == 0x8367) {
      local_64 = 8;
    }
    else {
      local_64 = 0;
      if (param_6 != 0x8035) goto LAB_000288cb;
      local_64 = 0xb;
    }
LAB_00028510:
    if (local_64 == 0) {
      return 0;
    }
  }
  else if (param_5 == 0x85b9) {
    if (param_6 == 0x85ba) {
      local_64 = 0x27;
    }
    else {
      if (param_6 != 0x85bb) {
        return 0;
      }
      local_64 = 0x26;
    }
  }
  else {
    if (param_5 != 0x190a) {
      return 0;
    }
    if (param_6 == 0x1401) {
      local_64 = 4;
      goto LAB_00028510;
    }
    if (param_6 == 0x1406) {
      local_64 = 0x16;
    }
    else if (param_6 == 0x140b) {
      local_64 = 0x22;
    }
    else {
      local_64 = 0;
      if (param_6 != 0x1403) goto LAB_00028510;
      local_64 = 0x1c;
    }
  }
LAB_0002851b:
  _pthread_mutex_lock(*(pthread_mutex_t **)(param_1 + 0xc));
  if (param_8 == '\0') {
    iVar11 = *(int *)(param_1 + 0x10) + 0x2e6c;
  }
  else {
    iVar11 = 0;
  }
  FUN_000095f0(param_1,param_5,param_6,param_3,param_4,local_20,local_24,&local_28,iVar11);
  uVar12 = param_7 + local_28;
  iVar11 = *(int *)*param_9;
  if (((((int)local_20[0] < 0x1001) && (param_4 < 0x1001)) &&
      (local_60 = *(int *)(param_1 + 0x15c), local_60 < 0x1001)) &&
     (local_5c = *(int *)(param_1 + 0x160), local_5c < 0x1001)) {
    if (local_60 < 1) {
      local_60 = 1;
      fVar24 = FLOAT_001c5ba4;
    }
    else {
      fVar24 = (float)local_60;
    }
    if (local_5c < 1) {
      local_5c = 1;
      local_40 = FLOAT_001c5ba4;
      iVar13 = -1;
    }
    else {
      local_40 = (float)local_5c;
      iVar13 = -local_5c;
    }
    fVar25 = *(float *)(param_2 + 0x20);
    fVar1 = *(float *)(param_2 + 0x24);
    local_48 = fVar25 + 0.0 + 0.0;
    fVar22 = (float)param_3 + fVar25 + 0.0;
    fVar23 = local_40 - (fVar1 + 0.0);
    fVar27 = local_40 - ((float)param_4 + fVar1);
    if (0.0 < local_48) {
      local_140 = local_48 + 0.0;
    }
    else {
      local_48 = 0.0;
      local_140 = 0.0;
    }
    fVar27 = (float)(~-(uint)(fVar27 <= 0.0) & (uint)fVar27);
    if (fVar24 <= fVar22) {
      fVar22 = fVar24;
    }
    if (local_40 <= fVar23) {
      fVar23 = local_40;
    }
    fVar26 = local_140 + 0.0 + (float)((uint)fVar25 ^ DAT_001c6030);
    fVar24 = (float)((uint)fVar25 ^ DAT_001c6030) + fVar22 + 0.0 + 0.0;
    fVar28 = (0.0 - (fVar27 + (float)iVar13)) + (float)((uint)fVar1 ^ DAT_001c6030);
    fVar25 = (float)((uint)fVar1 ^ DAT_001c6030) + (0.0 - ((float)iVar13 + fVar23));
    if ((local_48 < fVar22) && (fVar27 < fVar23)) {
      if (((*(int *)param_9[1] != 0) && (cVar10 = FUN_0001c242(param_1,param_9,1), cVar10 == '\0'))
         || ((puVar9 = PTR_DAT_002131c9, (int *)param_9[2] == (int *)0x0 ||
             (iVar13 = *(int *)param_9[2], iVar13 == 0)))) goto LAB_0002882f;
      if (((*(char *)(iVar13 + 0x16) != '\x06') &&
          ((param_5 != 0x1908 || ((param_6 != 0x1406 && (param_6 != 0x8366)))))) ||
         (((uVar12 | local_20[0]) & 0x1f) != 0)) {
        _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
        return 0;
      }
      iVar13 = param_1 + 0x240;
      uVar14 = (**(code **)(param_1 + 0x2998))(iVar13,0x343);
      *(undefined4 *)(param_1 + 0x298c) = uVar14;
      iVar20 = 0xf;
      do {
        if (*(int *)(param_1 + 0x18c + iVar20 * 4) != 0) {
          uVar14 = FUN_0002ac68(param_1,0,iVar20,uVar14);
        }
        iVar20 = iVar20 + -1;
      } while (iVar20 != 0);
      puVar15 = (uint *)FUN_0002ac68(param_1,0,0,uVar14);
      local_44 = (undefined4 *)((uint)(puVar15 + 0xb) & 0xffffffe0);
      *puVar15 = (((int)local_44 - (int)puVar15) + -8) * 0x4000 | 0xc0001000;
      local_44[-1] = (int)local_44 - (int)puVar15;
      puVar4 = *(uint **)(param_1 + 0x1d8);
      *puVar4 = *puVar4 | (int)local_44 - (int)puVar4 >> 2;
      *(undefined4 **)(param_1 + 0x1d8) = local_44;
      *local_44 = 0x3f000000;
      puVar5 = *(undefined4 **)param_9[2];
      puVar5[4] = puVar5[4] + 0x10000;
      local_44[2] = *puVar5;
      local_44[3] = uVar12 - *(int *)*param_9;
      _memcpy(local_44 + 4,PTR_DAT_002131cd,0x2f4);
      local_44[0x22] = 0;
      *(byte *)(local_44 + 0xa4) =
           *(byte *)(local_44 + 0xa4) & 0xfc | puVar9[local_64 * 0x24 + 0x18] & 3;
      fVar8 = DAT_001c6050;
      fVar7 = DAT_001c6040;
      fVar21 = fVar24 - fVar26;
      fVar29 = fVar28 - fVar25;
      fVar1 = fVar21 - FLOAT_001c5ba4;
      if (fVar21 - FLOAT_001c5ba4 <= 0.0) {
        fVar1 = 0.0;
      }
      fVar6 = fVar29 - FLOAT_001c5ba4;
      if (fVar29 - FLOAT_001c5ba4 <= 0.0) {
        fVar6 = 0.0;
      }
      local_44[0xaa] =
           ((int)(fVar1 - (float)(-(uint)(DAT_001c6040 <= fVar1) & (uint)DAT_001c6040)) |
           -(uint)(DAT_001c6050 <= fVar1)) & 0x7ff |
           (((int)(fVar6 - (float)(-(uint)(DAT_001c6040 <= fVar6) & (uint)DAT_001c6040)) |
            -(uint)(DAT_001c6050 <= fVar6)) & 0x7ff) << 0xb | 0x80000000;
      bVar2 = puVar9[local_64 * 0x24 + 0x20];
      local_44[0xac] =
           *(ushort *)(puVar9 + local_64 * 0x24 + 0x1e) >> 4 & 0x1f | (bVar2 >> 6 & 1) << 0x16 |
           ((byte)puVar9[local_64 * 0x24 + 0x1f] >> 1 & 7) << 9 |
           ((byte)puVar9[local_64 * 0x24 + 0x1f] >> 4 & 7) << 0xc | (bVar2 & 7) << 0xf |
           (bVar2 >> 3 & 7) << 0x12;
      fVar1 = fVar21;
      if (fVar21 <= 0.0) {
        fVar1 = 0.0;
      }
      fVar6 = fVar29;
      if (fVar29 <= 0.0) {
        fVar6 = 0.0;
      }
      local_44[0xae] =
           ((int)local_20[0] >> ((byte)puVar9[local_64 * 0x24 + 0x17] >> 5)) - 1U & 0x3fff |
           (((int)(fVar1 - (float)(-(uint)(fVar7 <= fVar1) & (uint)fVar7)) | -(uint)(fVar8 <= fVar1)
            ) - 1 >> 0xb) << 0xf |
           (((int)(fVar6 - (float)((uint)fVar7 & -(uint)(fVar7 <= fVar6))) | -(uint)(fVar8 <= fVar6)
            ) - 1 >> 0xb) << 0x10;
      local_44[0xa4] = local_44[0xa4] & 0x1f | (uVar12 - iVar11) * 0x20;
      puVar9 = PTR_DAT_002131c9;
      bVar2 = *(byte *)(param_1 + 0x2b7f);
      bVar16 = (byte)PTR_DAT_002131c9[(uint)bVar2 * 0x24 + 0x1b] >> 3 & 3;
      bVar3 = *(byte *)((int)local_44 + 0x239);
      *(byte *)((int)local_44 + 0x239) = bVar3 & 0xfc | bVar16;
      bVar17 = (byte)puVar9[(uint)bVar2 * 0x24 + 0x1b] >> 3 & 0xc;
      *(byte *)((int)local_44 + 0x239) = bVar3 & 0xf0 | bVar16 | bVar17;
      bVar18 = (puVar9[(uint)bVar2 * 0x24 + 0x1c] & 3) << 4;
      *(byte *)((int)local_44 + 0x239) = bVar3 & 0xc0 | bVar16 | bVar17 | bVar18;
      *(byte *)((int)local_44 + 0x239) =
           bVar16 | bVar17 | bVar18 | ((byte)puVar9[(uint)bVar2 * 0x24 + 0x1c] >> 2) << 6;
      *(byte *)(local_44 + 0x8e) =
           *(byte *)(local_44 + 0x8e) & 0xe0 |
           (byte)(*(ushort *)(puVar9 + (uint)bVar2 * 0x24 + 0x1a) >> 6) & 0x1f;
      if ((puVar9[(uint)bVar2 * 0x24 + 0x14] & 0x3f) == 0) {
        local_44[0x5a] = local_44[0x5a] & 0xfffe3fff | 0x18000;
      }
      local_44[0xb7] = local_60 - 1U & 0x1fff | (local_5c - 1U & 0x1fff) << 0xd;
      fVar21 = FLOAT_001c5ba4 / fVar21;
      fVar29 = FLOAT_001c5ba4 / fVar29;
      local_44[0xc1] = 0x31080;
      local_44[0xc2] = fVar21 * fVar26;
      local_44[0xc3] = fVar25 * fVar29;
      local_44[0xc4] = fVar24 * fVar21;
      local_44[0xc5] = fVar29 * fVar28;
      local_44[0xc6] = 0x1087;
      local_44[199] =
           (int)((fVar22 - local_48) * FLOAT_001c5bf4) << 0x10 |
           (int)((fVar23 - fVar27) * FLOAT_001c5bf4);
      local_44[200] = 0xc0033500;
      local_44[0xc9] = ((unsigned char *)0x00010031);
      fVar24 = FLOAT_001c5bd4;
      local_44[0xca] = (local_48 + fVar22) * FLOAT_001c5bd4;
      local_44[0xcb] = fVar24 * (fVar27 + fVar23);
      local_44[0xcc] = 0;
      puVar5 = local_44 + 0xcd;
      local_44[1] = (int)puVar5 - (int)puVar15 >> 2;
      puVar4 = *(uint **)(param_1 + 0x1d8);
      *puVar4 = *puVar4 | (int)puVar5 - (int)puVar4 >> 2;
      *(undefined4 **)(param_1 + 0x1d8) = puVar5;
      local_44[0xcd] = 0x33000000;
      local_44[0xce] = 0;
      local_44[0xcf] = 0x1393;
      local_44[0xd0] = 10;
      local_44[0xd1] = 0x13c6;
      local_44[0xd2] = 3;
      local_44[0xd3] = 0x5c8;
      local_44[0xd4] = 0x20000;
      local_44[0xd5] = 0x10ea;
      local_44[0xd6] = *(undefined4 *)(param_1 + 0x1cfc);
      local_44[0xd7] = 0x10fa;
      local_44[0xd8] = *(undefined4 *)(param_1 + 0x1da0);
      local_44[0xd9] = 0xc0001000;
      local_44[0xdb] = 0x11004;
      local_44[0xdc] = *(undefined4 *)(param_1 + 0x1ca8);
      local_44[0xdd] = *(undefined4 *)(param_1 + 0x1cac);
      local_44[0xde] = 0x1008;
      local_44[0xdf] = *(undefined4 *)(param_1 + 0x1ca0);
      local_44[0xe0] = 0x10e9;
      local_44[0xe1] = *(undefined4 *)(param_1 + 0x1d20);
      local_44[0xe2] = 0x13c7;
      local_44[0xe3] = *(undefined4 *)(param_1 + 0x1cf0);
      local_44[0xe4] = 0x13c1;
      local_44[0xe5] = *(undefined4 *)(param_1 + 0x1ce4);
      local_44[0xe6] = 0x850;
      local_44[0xe7] = *(undefined4 *)(param_1 + 0x1dc0);
      local_44[0xe8] = 0x887;
      local_44[0xe9] = *(undefined4 *)(param_1 + 0x1db4);
      local_44[0x18a] = 0x82c;
      local_44[0x18b] = *(undefined4 *)(param_1 + 0x1dc4);
      local_44[0xea] = 0x10ae;
      local_44[0xeb] = *(undefined4 *)(param_1 + 0x1d70);
      local_44[0xec] = 0x1394;
      local_44[0xed] = *(undefined4 *)(param_1 + 0x1d30);
      local_44[0xee] = 0x1380;
      local_44[0xef] = 0;
      local_44[0xf0] = 0x1002;
      local_44[0xf1] = *(undefined4 *)(param_1 + 0x1d90);
      local_44[0xf1] = *(undefined4 *)(param_1 + 0x1d90);
      local_44[0xf2] = 0x824;
      local_44[0xf3] = *(undefined4 *)(param_1 + 0x1ddc);
      local_44[0xf4] = 0x825;
      local_44[0xf5] = *(undefined4 *)(param_1 + 0x1de0);
      local_44[0xf6] = 0x82d;
      local_44[0xf7] = *(undefined4 *)(param_1 + 0x26cc);
      local_44[0xf8] = 0x854;
      local_44[0xf9] = **(undefined4 **)(param_1 + 0x2680);
      local_44[0xfa] = 0x878;
      local_44[0xfb] = **(undefined4 **)(param_1 + 0x2684);
      local_44[0xfc] = &switchdataD_000013c0;
      local_44[0xfd] = *(undefined4 *)(param_1 + 0x1ce0);
      local_44[0xfe] = 0x12f0;
      local_44[0xff] = *(undefined4 *)(param_1 + 0x1d2c);
      if ((puVar9[(uint)*(byte *)(param_1 + 0x2b7f) * 0x24 + 0x1a] & 1) == 0) {
        *(byte *)(local_44 + 0xff) = *(byte *)(local_44 + 0xff) & 0xfe;
      }
      local_44[0x100] = 0x12f5;
      local_44[0x101] = *(undefined4 *)(param_1 + 0x1c8c);
      if ((puVar9[(uint)*(byte *)(param_1 + 0x2b7f) * 0x24 + 0x1a] & 1) == 0) {
        *(byte *)((int)local_44 + 0x405) = *(byte *)((int)local_44 + 0x405) & 0xf7;
      }
      local_44[0x102] = 0x10a2;
      local_44[0x103] = *(undefined4 *)(param_1 + 0x1d7c);
      local_44[0x104] = 0x1381;
      local_44[0x105] = *(undefined4 *)(param_1 + 0x1cc0);
      if ((puVar9[(uint)*(byte *)(param_1 + 0x2b7f) * 0x24 + 0x1a] & 2) == 0) {
        *(byte *)(local_44 + 0x105) = *(byte *)(local_44 + 0x105) & 0xfc;
      }
      local_44[0x106] = 0x109e;
      local_44[0x107] = *(undefined4 *)(param_1 + 0x1d6c);
      local_44[0x108] = 0x1096;
      local_44[0x107] = *(undefined4 *)(param_1 + 0x1df8);
      local_44[0x10a] = 0x1041;
      local_44[0x10b] = *(undefined4 *)(param_1 + 0x29f0);
      local_44[0x10c] = 0x1046;
      local_44[0x10d] = *(undefined4 *)(param_1 + 0x1dfc);
      local_44[0x10e] = 0x1094;
      local_44[0x10f] = 0;
      local_44[0x110] = 0x1095;
      local_44[0x112] = 0x1095;
      local_44[0x114] = 0x1095;
      local_44[0x116] = 0x1095;
      local_44[0x118] = 0x1095;
      local_44[0x11a] = 0x1095;
      local_44[0x11c] = 0x1095;
      local_44[0x11e] = 0x1095;
      local_44[0x120] = 0x1095;
      local_44[0x122] = 0x1095;
      local_44[0x124] = 0x1095;
      local_44[0x126] = 0x1095;
      local_44[0x128] = 0xc0221000;
      local_44[0x14c] = 0x1180;
      local_44[0x14d] = 2;
      local_44[0x14e] = 0x1189;
      local_44[0x150] = 0x1181;
      local_44[0x152] = 0x118d;
      local_44[0x154] = 0x118e;
      local_44[0x156] = 0x118c;
      local_44[0x158] = 0x11a9;
      local_44[0x159] = *(undefined4 *)(param_1 + 0x257c);
      local_44[0x15a] = 0x11aa;
      local_44[0x15b] = *(undefined4 *)(param_1 + 0x2580);
      local_44[0x15c] = 0x11ab;
      local_44[0x15d] = *(undefined4 *)(param_1 + 0x2584);
      local_44[0x15e] = 0x11ac;
      local_44[0x15f] = *(undefined4 *)(param_1 + 0x2588);
      local_44[0x160] = 0x10c0;
      local_44[0x161] = *(undefined4 *)(param_1 + 0x216c);
      local_44[0x162] = 0x10c1;
      local_44[0x164] = 0x10c8;
      local_44[0x166] = 0x101d;
      local_44[0x167] = *(undefined4 *)(param_1 + 0x2128);
      local_44[0x168] = 0x138a;
      local_44[0x169] = 0;
      local_44[0x16a] = 0x138e;
      local_44[0x16b] = 0;
      local_44[0x16c] = 0x1040;
      local_44[0x16d] = 0;
      local_44[0x16e] = 0x1150;
      local_44[0x16f] = 0;
      local_44[0x170] = 0x1100;
      local_44[0x171] = *(undefined4 *)(param_1 + 0x1f1c);
      local_44[0x172] = 0x1110;
      local_44[0x173] = *(undefined4 *)(param_1 + 0x1f5c);
      local_44[0x174] = 0x1120;
      local_44[0x175] = *(undefined4 *)(param_1 + 0x1f9c);
      local_44[0x176] = 0x1130;
      local_44[0x177] = *(undefined4 *)(param_1 + 0x1fdc);
      local_44[0x178] = 0x1140;
      local_44[0x179] = *(undefined4 *)(param_1 + 0x201c);
      local_44[0x17a] = 0x10f4;
      local_44[0x17b] = 0xaaaa;
      local_44[0x17c] = 0x1383;
      local_44[0x17d] = *(undefined4 *)(param_1 + 0x1d34);
      local_44[0x17e] = 0x1386;
      local_44[0x17f] = *(undefined4 *)(param_1 + 0x1d38);
      local_44[0x180] = 0x110f8;
      local_44[0x181] = *(undefined4 *)(param_1 + 0x1d98);
      local_44[0x182] = *(undefined4 *)(param_1 + 0x1d50);
      local_44[0x183] = 0x1087;
      local_44[0x184] = *(undefined4 *)(param_1 + 0x1f0c);
      local_44[0x185] = 0x31080;
      local_44[0x186] = *(undefined4 *)(param_1 + 0x1efc);
      local_44[0x187] = *(undefined4 *)(param_1 + 0x1f04);
      local_44[0x188] = *(undefined4 *)(param_1 + 0x1f00);
      local_44[0x189] = *(undefined4 *)(param_1 + 0x1f08);
      FUN_0004acbc(local_44 + 0xcf,iVar13);
      local_44 = local_44 + 0x18c;
      iVar11 = 0;
      local_124 = 0;
      do {
        iVar20 = *(int *)(param_1 + 0x18c + iVar11 * 4);
        if (iVar20 != 0) {
          iVar19 = 0;
          do {
            if (iVar20 == *(int *)(*(int *)(param_1 + 0x18) + (local_124 + iVar19) * 4)) {
              if (*(int *)(iVar20 + 0x34) != 0) goto LAB_0002950f;
              break;
            }
            iVar19 = iVar19 + 1;
          } while (iVar19 != 5);
          iVar20 = 0;
        }
LAB_0002950f:
        if ((iVar11 == 0) || (iVar20 != 0)) {
          local_44 = (undefined4 *)FUN_0002ac68(param_1,iVar20,iVar11,local_44);
        }
        iVar11 = iVar11 + 1;
        local_124 = local_124 + 5;
      } while (iVar11 != 0x10);
      *(undefined4 **)(param_1 + 0x298c) = local_44;
      (**(code **)(param_1 + 0x299c))(iVar13,local_44);
    }
    _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
    return 1;
  }
LAB_0002882f:
  _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
  return 0;
}

/* FUN_000296ab @ 0x296ab (5 bytes) */
int FUN_000296ab()
{
  return;
}

/* FUN_000296b0 @ 0x296b0 (322 bytes) */
int FUN_000296b0(param_1, param_2)
  int param_1;
  int *param_2;
{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  uint local_34;
  uint local_30;
  uint local_28;
  int local_1c;
  
  uVar3 = *(uint *)(param_1 + 0x2610);
  piVar1 = *(int **)(param_1 + 0x224);
  puVar2 = (uint *)(piVar1 + *param_2 * 8 + 0x84);
  local_28 = uVar3;
  if ((uVar3 == 1) && (local_28 = 2, *(int *)(param_1 + 0x261c) != 2)) {
    local_28 = uVar3;
  }
  local_34 = *puVar2;
  uVar3 = puVar2[1];
  local_30 = 0;
  if (1 < local_28) {
    bVar5 = CARRY4(local_34,puVar2[4]);
    local_34 = local_34 + puVar2[4];
    local_30 = (uint)bVar5;
  }
  if (2 < local_28) {
    bVar5 = CARRY4(local_34,puVar2[2]);
    local_34 = local_34 + puVar2[2];
    local_30 = local_30 + bVar5;
  }
  if (3 < local_28) {
    bVar5 = CARRY4(local_34,puVar2[3]);
    local_34 = local_34 + puVar2[3];
    local_30 = local_30 + bVar5;
  }
  if (uVar3 != 0) {
    bVar5 = CARRY4(local_34,uVar3);
    local_34 = local_34 + uVar3;
    local_30 = local_30 + bVar5;
  }
  if (*piVar1 != 0) {
    puVar2 = (uint *)(piVar1 + 4);
    uVar3 = 0;
    iVar4 = 0;
    local_1c = 0x10;
    do {
      bVar5 = CARRY4(uVar3,*puVar2);
      uVar3 = uVar3 + *puVar2;
      iVar4 = iVar4 + (uint)bVar5;
      if (1 < local_28) {
        bVar5 = CARRY4(uVar3,puVar2[4]);
        uVar3 = uVar3 + puVar2[4];
        iVar4 = iVar4 + (uint)bVar5;
      }
      if (2 < local_28) {
        bVar5 = CARRY4(uVar3,puVar2[2]);
        uVar3 = uVar3 + puVar2[2];
        iVar4 = iVar4 + (uint)bVar5;
      }
      if (3 < local_28) {
        bVar5 = CARRY4(uVar3,puVar2[3]);
        uVar3 = uVar3 + puVar2[3];
        iVar4 = iVar4 + (uint)bVar5;
      }
      puVar2 = puVar2 + 8;
      local_1c = local_1c + -1;
    } while (local_1c != 0);
    bVar5 = CARRY4(local_34,uVar3);
    local_34 = local_34 + uVar3;
    local_30 = local_30 + iVar4 + (uint)bVar5;
  }
  *piVar1 = 0;
  uVar3 = 0xffffffff;
  if (local_30 == 0) {
    uVar3 = local_34;
  }
  return uVar3;
}

/* _gldGetQueryInfo @ 0x297f2 (375 bytes) */
int _gldGetQueryInfo(param_1, param_2, param_3, param_4)
  int param_1;
  int *param_2;
  int param_3;
  int *param_4;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  uVar4 = *(uint *)(param_1 + 0x2610);
  piVar1 = (int *)(*(int *)(param_1 + 0x224) + 0x210 + *param_2 * 0x20);
  iVar2 = *piVar1;
  iVar3 = piVar1[4];
  local_1c = piVar1[2];
  local_18 = piVar1[3];
  if ((uVar4 == 1) && (*(int *)(param_1 + 0x261c) == 2)) {
    uVar4 = 2;
  }
  if ((((iVar2 == -1) || ((1 < uVar4 && (iVar3 == -1)))) || ((2 < uVar4 && (local_1c == -1)))) ||
     ((3 < uVar4 && (local_18 == -1)))) {
    local_10 = 0;
  }
  else {
    local_10 = 1;
  }
  if (param_3 != 0x8866) {
    if (param_3 != 0x8867) {
      return 0;
    }
    if (local_10 == 0) {
      _gldFlush(param_1);
    }
    *param_4 = local_10;
    return 0;
  }
  local_14 = 0;
  while ((((iVar2 == -1 || ((1 < uVar4 && (iVar3 == -1)))) ||
          (((2 < uVar4 && (local_1c == -1)) || ((3 < uVar4 && (local_18 == -1)))))) &&
         (local_14 = local_14 + 1, local_14 != 0x2711))) {
    FUN_00008bea(param_1);
    _usleep(100);
    iVar2 = *piVar1;
    iVar3 = piVar1[4];
    local_1c = piVar1[2];
    local_18 = piVar1[3];
  }
  iVar2 = ((int (*)())FUN_000296b0)(param_1,param_2);
  *param_4 = iVar2;
  return 0;
}

/* FUN_00029969 @ 0x29969 (159 bytes) */
int FUN_00029969(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = *(int *)(param_1 + 0x224);
  puVar2 = (undefined4 *)(iVar1 + 0x210 + *param_2 * 0x20);
  *puVar2 = 0xffffffff;
  puVar2[4] = 0xffffffff;
  puVar2[2] = 0xffffffff;
  puVar2[3] = 0xffffffff;
  puVar2[1] = 0;
  *(int *)(iVar1 + 8) = *param_2;
  puVar2 = *(undefined4 **)(param_1 + 0x1dc);
  if (*(undefined4 **)(param_1 + 0x1e0) <= puVar2 + 2) {
    FUN_00017c77(param_1,0x1000000);
    puVar2 = *(undefined4 **)(param_1 + 0x1dc);
  }
  *(undefined4 **)(param_1 + 0x1dc) = puVar2 + 2;
  *puVar2 = 0x13d6;
  puVar2[1] = 0;
  *(undefined1 *)(param_1 + 0x2b7e) = 1;
  FUN_0008b3f0();
  return;
}

/* FUN_00029a08 @ 0x29a08 (828 bytes) */
int FUN_00029a08(param_1, param_2)
  int param_1;
  uint *param_2;
{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  int *piVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  undefined4 *puVar11;
  uint uVar12;
  bool bVar13;
  int local_10;
  
  piVar1 = *(int **)(param_1 + 0x224);
  puVar11 = (undefined4 *)**(int **)(param_1 + 0x234);
  uVar2 = *(undefined4 *)(param_1 + 0x1cf8);
  uVar9 = *(uint *)(param_1 + 0x2610);
  iVar3 = *(int *)(param_1 + 0x261c);
  uVar8 = *(uint *)(param_1 + 0x154);
  if (piVar1 == (int *)0x0) {
    return param_2;
  }
  if (*(char *)(param_1 + 0x2b7e) != '\0') {
    if (uVar9 == 1) {
      uVar12 = 2;
      if (iVar3 != 2) {
        uVar12 = uVar9;
      }
      iVar10 = *piVar1;
      uVar9 = uVar12;
    }
    else {
      iVar10 = *piVar1;
    }
    if (iVar10 == 0) {
      iVar10 = 0;
      piVar6 = piVar1;
      do {
        piVar6[4] = 0;
        piVar6[8] = 0;
        piVar6[6] = 0;
        piVar6[7] = 0;
        iVar10 = iVar10 + 1;
        piVar6 = piVar6 + 8;
      } while (iVar10 != 0x10);
      piVar1[1] = 1;
      local_10 = 0;
    }
    else {
      local_10 = piVar1[1];
      piVar1[1] = local_10 + 1U & 0xf;
      uVar12 = piVar1[piVar1[2] * 8 + 0x85];
      if ((uVar8 & 0x30000) == 0x10000) {
        uVar8 = piVar1[local_10 * 8 + 4];
      }
      else {
        uVar8 = piVar1[local_10 * 8 + 4];
      }
      if ((uVar8 != 0) && (bVar13 = CARRY4(uVar12,uVar8), uVar12 = uVar12 + uVar8, bVar13)) {
        uVar12 = 0xffffffff;
      }
      if (((1 < uVar9) && (uVar8 = piVar1[local_10 * 8 + 8], uVar8 != 0)) &&
         (bVar13 = CARRY4(uVar12,uVar8), uVar12 = uVar12 + uVar8, bVar13)) {
        uVar12 = 0xffffffff;
      }
      if (((2 < uVar9) && (uVar8 = piVar1[local_10 * 8 + 6], uVar8 != 0)) &&
         (bVar13 = CARRY4(uVar12,uVar8), uVar12 = uVar12 + uVar8, bVar13)) {
        uVar12 = 0xffffffff;
      }
      uVar8 = uVar12;
      if ((3 < uVar9) && (uVar4 = piVar1[local_10 * 8 + 7], uVar4 != 0)) {
        uVar8 = 0xffffffff;
        if (!CARRY4(uVar4,uVar12)) {
          uVar8 = uVar4 + uVar12;
        }
      }
      piVar1[piVar1[2] * 8 + 0x85] = uVar8;
    }
    piVar1[local_10 * 8 + 4] = 0;
    piVar1[local_10 * 8 + 8] = 0;
    piVar1[local_10 * 8 + 6] = 0;
    piVar1[local_10 * 8 + 7] = 0;
    puVar11[4] = puVar11[4] + 0x10000;
    puVar7 = (undefined4 *)((uint)(param_2 + 0xb) & 0xffffffe0);
    *param_2 = (((int)puVar7 - (int)param_2) + -8) * 0x4000 | 0xc0001000;
    puVar7[-1] = (int)puVar7 - (int)param_2;
    puVar5 = *(uint **)(param_1 + 0x1d8);
    *puVar5 = *puVar5 | (int)puVar7 - (int)puVar5 >> 2;
    *(undefined4 **)(param_1 + 0x1d8) = puVar7;
    *puVar7 = 0x3b000000;
    puVar7[1] = *puVar11;
    puVar7[2] = 1;
    puVar7[3] = local_10;
    puVar11 = puVar7 + 4;
    if (iVar3 == 2) {
      puVar7[4] = 0x13c5;
      puVar7[5] = 0;
      uVar9 = 0;
      puVar11 = puVar7 + 6;
      do {
        puVar7 = puVar11;
        *puVar7 = 0x12fa;
        puVar7[1] = 1 << ((byte)uVar9 & 0x1f);
        puVar7[2] = 0x13d7;
        puVar7[3] = 0;
        uVar9 = uVar9 + 1;
        puVar11 = puVar7 + 4;
      } while (uVar9 < 2);
      puVar7[4] = 0x12fa;
      puVar7[5] = 3;
      puVar7[6] = 0x13c5;
      puVar7[7] = uVar2;
      param_2 = puVar7 + 8;
    }
    else {
      if (uVar9 != 0) {
        uVar8 = 0;
        do {
          *puVar11 = 0x10b2;
          puVar11[1] = 1 << ((byte)uVar8 & 0x1f);
          puVar11[2] = 0x13d7;
          puVar11[3] = 0;
          puVar11 = puVar11 + 4;
          uVar8 = uVar8 + 1;
        } while (uVar9 != uVar8);
      }
      *puVar11 = 0x10b2;
      puVar11[1] = 0xf;
      param_2 = puVar11 + 2;
    }
    *piVar1 = 1;
    return param_2;
  }
  return param_2;
}

/* FUN_00029d44 @ 0x29d44 (480 bytes) */
int FUN_00029d44(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  uint *puVar7;
  int local_18;
  
  local_18 = *(int *)(param_1 + 0x2610);
  iVar3 = *(int *)(param_1 + 0x261c);
  uVar1 = *(undefined4 *)(param_1 + 0x1cf8);
  puVar6 = (undefined4 *)**(int **)(param_1 + 0x234);
  if (local_18 == 1) {
    if (iVar3 == 2) {
      local_18 = 2;
      iVar5 = 8;
    }
    else {
      iVar5 = 4;
    }
  }
  else {
    iVar5 = local_18 << 2;
  }
  puVar6[4] = puVar6[4] + 0x10000;
  puVar7 = *(uint **)(param_1 + 0x1dc);
  if (*(uint **)(param_1 + 0x1e0) <= puVar7 + iVar5 + 0x15) {
    FUN_00017c77(param_1,0x1000000);
    puVar7 = *(uint **)(param_1 + 0x1dc);
  }
  puVar2 = (undefined4 *)((uint)(puVar7 + 0xb) & 0xffffffe0);
  *puVar7 = (((int)puVar2 - (int)puVar7) + -8) * 0x4000 | 0xc0001000;
  puVar2[-1] = (int)puVar2 - (int)puVar7;
  puVar7 = *(uint **)(param_1 + 0x1d8);
  *puVar7 = *puVar7 | (int)puVar2 - (int)puVar7 >> 2;
  *(undefined4 **)(param_1 + 0x1d8) = puVar2;
  *puVar2 = 0x3b000000;
  puVar2[1] = *puVar6;
  puVar2[2] = 0;
  puVar2[3] = *param_2;
  puVar6 = puVar2 + 4;
  if (iVar3 != 2) {
    if (local_18 != 0) {
      iVar3 = 0;
      do {
        *puVar6 = 0x10b2;
        puVar6[1] = 1 << ((byte)iVar3 & 0x1f);
        puVar6[2] = 0x13d7;
        puVar6[3] = 0;
        puVar6 = puVar6 + 4;
        iVar3 = iVar3 + 1;
      } while (local_18 != iVar3);
    }
    *puVar6 = 0x10b2;
    puVar6[1] = 0xf;
    *(undefined4 **)(param_1 + 0x1dc) = puVar6 + 2;
    *(undefined1 *)(param_1 + 0x2b7e) = 0;
    FUN_0008b3f0();
    return;
  }
  puVar2[4] = 0x13c5;
  puVar2[5] = 0;
  uVar4 = 0;
  puVar6 = puVar2 + 6;
  do {
    puVar2 = puVar6;
    *puVar2 = 0x12fa;
    puVar2[1] = 1 << ((byte)uVar4 & 0x1f);
    puVar2[2] = 0x13d7;
    puVar2[3] = 0;
    uVar4 = uVar4 + 1;
    puVar6 = puVar2 + 4;
  } while (uVar4 < 2);
  puVar2[4] = 0x12fa;
  puVar2[5] = 3;
  puVar2[6] = 0x13c5;
  puVar2[7] = uVar1;
  *(undefined4 **)(param_1 + 0x1dc) = puVar2 + 8;
  *(undefined1 *)(param_1 + 0x2b7e) = 0;
  FUN_0008b3f0();
  return;
}

/* FUN_00029f24 @ 0x29f24 (63 bytes) */
int FUN_00029f24(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  iVar2 = *(int *)(iVar1 + 0x1dc);
  if (*(uint *)(iVar1 + 0x1e0) <= (uint)(iVar2 + param_2 * 4)) {
    FUN_00017c77(iVar1,0x1000000);
    iVar2 = *(int *)(iVar1 + 0x1dc);
  }
  return iVar2;
}

/* FUN_00029f63 @ 0x29f63 (20 bytes) */
int FUN_00029f63(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(*(int *)(param_1 + 4) + 0x1dc) = param_2;
  return;
}

/* FUN_00029f77 @ 0x29f77 (14 bytes) */
int FUN_00029f77(param_1)
  int param_1;
{
  return *(undefined4 *)(param_1 + 0x274c);
}

/* FUN_00029f85 @ 0x29f85 (5 bytes) */
int FUN_00029f85()
{
  return;
}

/* FUN_00029f8a @ 0x29f8a (26 bytes) */
int FUN_00029f8a(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  param_2 = param_3;
  FUN_000a2046();
  return;
}

/* FUN_00029fa4 @ 0x29fa4 (109 bytes) */
int FUN_00029fa4(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  uint param_3;
{
  int iVar1;
  
  iVar1 = (param_2 >> 3 & 1) + (param_2 >> 2 & 1) + (param_2 >> 1 & 1) + (param_2 & 1);
  if (((iVar1 != 2) && (iVar1 != 0)) && (param_2 != 2)) {
    if (iVar1 == 3) {
      return param_3 & 0xfffffffc;
    }
    if (param_2 == 4) {
      return ((int)param_3 / 3) * 3;
    }
    param_3 = param_3 & 0xfffffffe;
  }
  return param_3;
}

/* FUN_0002a011 @ 0x2a011 (130 bytes) */
int FUN_0002a011(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  uint param_3;
{
  uint uVar1;
  
  switch(param_2) {
  case 0:
    if (param_3 != 0) {
      return param_3;
    }
    break;
  case 1:
    if (1 < (int)(param_3 & 0xfffffffe)) {
      return param_3 & 0xfffffffe;
    }
    break;
  case 2:
  case 3:
    if (1 < (int)param_3) {
      return param_3;
    }
    break;
  case 4:
    uVar1 = ((int)param_3 / 3) * 3;
    if (2 < (int)uVar1) {
      return uVar1;
    }
    break;
  case 5:
  case 6:
  case 9:
    if (2 < (int)param_3) {
      return param_3;
    }
    break;
  case 7:
    if (3 < (int)(param_3 & 0xfffffffc)) {
      return param_3 & 0xfffffffc;
    }
    break;
  case 8:
    if (3 < (int)(param_3 & 0xfffffffe)) {
      return param_3 & 0xfffffffe;
    }
  }
  return 0;
}

/* FUN_0002a0bb @ 0x2a0bb (103 bytes) */
int FUN_0002a0bb(param_1, param_2)
  int param_1;
  int param_2;
{
  byte bVar1;
  int iVar2;
  
  bVar1 = *(byte *)(param_1 + 0x1874) & 0xfc;
  *(byte *)(param_1 + 0x1874) = bVar1;
  if ((param_2 == 0) && ((*(byte *)(param_1 + 0x1928) & 2) != 0)) {
    *(byte *)(param_1 + 0x1874) = bVar1 | 2;
    iVar2 = 1;
  }
  else {
    iVar2 = 0;
  }
  if (iVar2 != *(int *)(param_1 + 0x192c)) {
    FUN_0007ed9d(param_1);
    FUN_0008b868(param_1);
    *(int *)(param_1 + 0x192c) = iVar2;
  }
  *(uint *)(param_1 + 0x1928) = *(uint *)(param_1 + 0x1928) & 0xfffffffe;
  return;
}

