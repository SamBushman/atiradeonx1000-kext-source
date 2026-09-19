#include "decls.h"

/* FUN_000a1d35 @ 0xa1d35 (38 bytes) */
int FUN_000a1d35(param_1)
  int param_1;
{
  byte bVar1;
  
  if ((*(byte *)(param_1 + 0x45) & 8) == 0) {
    bVar1 = *(byte *)(param_1 + 0xe8);
  }
  else {
    bVar1 = *(byte *)(param_1 + 0x47);
  }
  if ((bVar1 & 1) != 0) {
    return 1;
  }
  return 0;
}

/* FUN_000a1d5b @ 0xa1d5b (165 bytes) */
int FUN_000a1d5b(param_1, param_2)
  int param_1;
  int param_2;
{
  float fVar1;
  
  if (param_2 != '\0') {
    fVar1 = FLOAT_001c5bd0;
    if (*(short *)(*(int *)(*(int *)(param_1 + 4) + 0x10) + 0x2e0e) != 0x1102) {
      fVar1 = FLOAT_001c5ba4;
    }
    return (int)((float)*(uint *)(param_1 + 8) * FLOAT_001c5bd4 *
                (fVar1 + *(float *)(param_1 + 0xe0)));
  }
  return (int)((float)*(uint *)(param_1 + 8) * FLOAT_001c5bd4 * *(float *)(param_1 + 0xe0));
}

/* FUN_000a1e00 @ 0xa1e00 (407 bytes) */
int FUN_000a1e00(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int param_3;
  int *param_4;
{
  char cVar1;
  int iVar2;
  int iVar3;
  float in_XMM0_Da;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  
  if ((FLOAT_001c5ba4 <= in_XMM0_Da) ||
     (fVar9 = FLOAT_001c5ba4, NAN(in_XMM0_Da) || NAN(FLOAT_001c5ba4))) {
    fVar9 = (float)(int)in_XMM0_Da;
  }
  fVar10 = (float)param_2;
  fVar7 = (float)(int)(fVar10 / (fVar9 + FLOAT_001c5bd0));
  fVar9 = FLOAT_001c5ba4;
  if (in_XMM0_Da <= FLOAT_001c5ba4) {
    fVar9 = in_XMM0_Da;
  }
  fVar9 = fVar9 * (FLOAT_001c5ba4 / ((fVar7 - FLOAT_001c5ba4) * fVar7));
  if (param_2 / 2 < 1) {
    *param_4 = 0;
    return;
  }
  iVar2 = 0;
  do {
    fVar8 = 0.0;
    if (fVar7 <= 0.0) {
LAB_000a1e8e:
      cVar1 = (char)(int)(fVar8 * FLOAT_001c5bb8 + FLOAT_001c5bd4);
      *(char *)(iVar2 + param_3) = cVar1;
    }
    else {
      iVar3 = 0;
      fVar5 = 0.0;
      fVar6 = fVar5;
      fVar8 = fVar5;
      do {
        fVar4 = (float)(int)((float)(iVar3 + iVar2) - fVar7);
        if ((fVar7 <= fVar4) && (fVar4 < fVar10 - fVar7)) {
          fVar8 = fVar8 + fVar6 * fVar9;
        }
        iVar3 = iVar3 + 1;
        fVar6 = (float)iVar3;
      } while (fVar6 < fVar7);
      iVar3 = 0;
      do {
        if ((fVar7 <= (float)(iVar3 + iVar2)) && ((float)(iVar3 + iVar2) < fVar10 - fVar7)) {
          fVar8 = fVar8 + ((fVar7 - fVar5) - FLOAT_001c5ba4) * fVar9;
        }
        iVar3 = iVar3 + 1;
        fVar5 = (float)iVar3;
      } while (fVar5 < fVar7);
      if (fVar8 <= FLOAT_001c5ba4) goto LAB_000a1e8e;
      cVar1 = (char)(int)(FLOAT_001c5bb8 + FLOAT_001c5bd4);
      *(char *)(iVar2 + param_3) = cVar1;
    }
    if ((cVar1 == -1) || (iVar2 = iVar2 + 1, param_2 / 2 == iVar2)) {
      *param_4 = iVar2;
      return;
    }
  } while( true );
}

/* FUN_000a1f97 @ 0xa1f97 (175 bytes) */
int FUN_000a1f97(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int param_3;
  int *param_4;
{
  float fVar1;
  int iVar2;
  float in_XMM0_Da;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  fVar1 = FLOAT_001c5bd4;
  fVar5 = FLOAT_001c5ba4;
  if (FLOAT_001c5ba4 <= in_XMM0_Da) {
    fVar5 = (float)(int)in_XMM0_Da;
  }
  fVar6 = (float)(int)(((float)param_2 * FLOAT_001c5bd4) / (fVar5 + FLOAT_001c5ba4));
  fVar6 = fVar6 + fVar6;
  fVar3 = FLOAT_001c5bb8 / fVar6;
  fVar5 = FLOAT_001c5ba4;
  if (in_XMM0_Da <= FLOAT_001c5ba4) {
    fVar5 = in_XMM0_Da;
  }
  fVar4 = 0.0;
  if (fVar6 <= 0.0) {
    iVar2 = 0;
  }
  else {
    iVar2 = 0;
    do {
      *(char *)(param_3 + iVar2) = (char)(int)(fVar4 * fVar5 * fVar3 + fVar1);
      iVar2 = iVar2 + 1;
      fVar4 = (float)iVar2;
    } while (fVar4 < fVar6);
  }
  if (iVar2 < param_2 / 2) {
    *(undefined1 *)(iVar2 + param_3) = 0xff;
  }
  *param_4 = iVar2;
  return;
}

/* FUN_000a2046 @ 0xa2046 (2337 bytes) */
int FUN_000a2046(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  byte bVar2;
  undefined4 *puVar3;
  int iVar4;
  byte bVar5;
  int iVar6;
  byte bVar7;
  uint uVar8;
  byte *pbVar9;
  byte local_70;
  int local_5c;
  uint local_58;
  uint local_4c;
  int local_40;
  int local_30;
  uint local_28;
  uint local_24;
  int local_20;
  
  if (*(int *)(param_1 + 0x277c) == param_2) {
    return;
  }
  *(int *)(param_1 + 0x277c) = param_2;
  iVar1 = *(int *)(param_1 + 0x2768);
  uVar8 = (uint)*(ushort *)(param_1 + 0x1b50);
  *(uint *)(param_1 + 0x1b50) = uVar8;
  if (iVar1 == 0) {
    if ((*(byte *)(param_1 + 0x44) & 4) == 0) {
      return;
    }
  }
  else if ((param_2 != 0) || ((*(byte *)(param_1 + 0x44) & 4) == 0)) {
    *(uint *)(param_1 + 0x1b50) = uVar8;
    local_70 = (char)*(undefined4 *)(param_1 + 0x276c) * '\x02' + 0x10;
    *(uint *)(param_1 + 0x1b50) = uVar8 | *(int *)(iVar1 + 0xe8 + param_2 * 4) << (local_70 & 0x1f);
    *(byte *)(param_1 + 0x1a64) =
         *(byte *)(param_1 + 0x1a64) & 0xef | *(byte *)(iVar1 + 0x110 + param_2 * 4) & 0x10;
    *(byte *)(param_1 + 0x1b64) =
         *(byte *)(param_1 + 0x1b64) & 0xfc | (DAT_001c6400)[param_2 * 4] & 3;
    *(undefined4 *)(param_1 + 0x1b68) = 0;
    FUN_00049f1d(param_1,*(undefined4 *)(iVar1 + 0xc0 + param_2 * 4));
  }
  *(undefined4 *)(param_1 + 0x1ba8) = *(undefined4 *)(param_1 + 0x1ba0);
  if (iVar1 != 0) goto LAB_000a2132;
  if ((*(byte *)(param_1 + 0x45) & 8) == 0) {
    FUN_0008b06b(param_1);
  }
  else {
    FUN_00062539(param_1);
  }
  (**(code **)(param_1 + 0x1334))(param_1,1);
  local_4c = *(uint *)(param_1 + 0x1ba4);
  *(uint *)(param_1 + 0x1ba0) = local_4c;
  *(byte *)(param_1 + 0x1a64) = *(byte *)(param_1 + 0x1a64) & 0xef;
  bVar7 = *(byte *)(param_1 + 0x44) & 4;
  if ((bVar7 == 0) || ((*(byte *)(param_1 + 0x8c) & 2) != 0)) {
    if ((*(byte *)(param_1 + 0x44) & 2) == 0) {
      *(uint *)(param_1 + 0x1b50) = (uint)*(ushort *)(param_1 + 0x1b50);
    }
    else if ((bVar7 != 0) && ((*(byte *)(param_1 + 0x8c) & 2) != 0)) {
      *(uint *)(param_1 + 0x1b50) = (uint)*(ushort *)(param_1 + 0x1b50);
      *(undefined4 *)(param_1 + 0x1bc0) = 0;
    }
  }
  else {
    if (param_2 == 0) {
      if ((*(byte *)(param_1 + 0x45) & 0x40) == 0) {
        if (*(char *)(param_1 + 0x13b2) == '\0') goto LAB_000a24fb;
        local_40 = param_1;
        local_24 = 0;
        iVar4 = 0;
        bVar7 = 0;
        bVar2 = 0x10;
        do {
          bVar5 = (byte)iVar4;
          if ((((*(byte *)(local_40 + 0x48) & 0x1f) == 0) ||
              ((*(uint *)(param_1 + 0xec) & 1 << (bVar5 & 0x1f)) == 0)) ||
             (*(int *)(local_40 + 0x13f8) == 0)) {
            *(byte *)(param_1 + 0x1ee8 + iVar4 * 4) =
                 *(byte *)(param_1 + 0x1ee8 + iVar4 * 4) & 0xc0 | (byte)local_24 & 0x3f;
            *(ushort *)(param_1 + 0x1ee8 + iVar4 * 4) =
                 *(ushort *)(param_1 + 0x1ee8 + iVar4 * 4) & 0xf03f |
                 (ushort)(((local_24 & 0xff) + 1 & 0x3f) << 6);
            *(uint *)(param_1 + 0x1ee8 + iVar4 * 4) =
                 *(uint *)(param_1 + 0x1ee8 + iVar4 * 4) & 0xfffc0fff |
                 ((local_24 & 0xff) + 2 & 0x3f) << 0xc;
            *(byte *)(param_1 + 0x1eea + iVar4 * 4) =
                 *(byte *)(param_1 + 0x1eea + iVar4 * 4) & 3 | (byte)local_24 * '\x04' + 0xc;
            *(uint *)(param_1 + 0x1b50) = *(uint *)(param_1 + 0x1b50) & ~(1 << (bVar2 & 0x1f));
            *(uint *)(param_1 + 0x1bc0) =
                 *(uint *)(param_1 + 0x1bc0) & ~(1 << (bVar5 * '\x02' & 0x1f));
            local_24 = local_24 + (*(uint *)(param_1 + 0x1ba0) >> (bVar7 & 0x1f) & 7);
          }
          else {
            *(byte *)(param_1 + 0x1a64) = *(byte *)(param_1 + 0x1a64) | 0x10;
            local_4c = local_4c & ~(7 << (bVar7 & 0x1f));
            *(uint *)(param_1 + 0x1b50) = *(uint *)(param_1 + 0x1b50) | 1 << (bVar2 & 0x1f);
            *(uint *)(param_1 + 0x1bc0) = *(uint *)(param_1 + 0x1bc0) | 1 << (bVar5 * '\x02' & 0x1f)
            ;
            *(byte *)(param_1 + 0x1ee8 + iVar4 * 4) =
                 *(byte *)(param_1 + 0x1ee8 + iVar4 * 4) & 0xc0 | (byte)local_24 & 0x3f;
            *(ushort *)(param_1 + 0x1ee8 + iVar4 * 4) =
                 *(ushort *)(param_1 + 0x1ee8 + iVar4 * 4) & 0xf03f |
                 ((byte)((byte)local_24 + 1) & 0x3f) << 6;
            *(uint *)(param_1 + 0x1ee8 + iVar4 * 4) =
                 *(uint *)(param_1 + 0x1ee8 + iVar4 * 4) & 0xfffc0fff | 0x3e000;
            pbVar9 = (byte *)(param_1 + 0x1eea + iVar4 * 4);
            *pbVar9 = *pbVar9 | 0xfc;
            local_24 = local_24 + 2;
          }
          iVar4 = iVar4 + 1;
          local_40 = local_40 + 4;
          bVar7 = bVar7 + 3;
          bVar2 = bVar2 + 2;
        } while (iVar4 < (int)(uint)*(byte *)(param_1 + 0x13b2));
        (*(unsigned char *)((unsigned char *)&(local_58) + 0)) = (byte)local_24;
      }
      else {
        if ((*(byte *)(param_1 + 0x46) & 4) == 0) {
          bVar7 = *(byte *)(param_1 + 0x1135);
        }
        else {
          bVar7 = *(byte *)(param_1 + 0x11d3);
        }
        uVar8 = *(uint *)(param_1 + 0xec);
        if (*(char *)(param_1 + 0x13b2) == '\0') {
LAB_000a24fb:
          (*(unsigned char *)((unsigned char *)&(local_58) + 0)) = 0;
        }
        else {
          local_58 = 0;
          local_5c = 0;
          bVar2 = 0;
          bVar5 = 0x10;
          pbVar9 = (byte *)(param_1 + 0x1eea);
          do {
            if (((bVar7 & uVar8) >> ((byte)local_5c & 0x1f) & 1) == 0) {
              pbVar9[-2] = pbVar9[-2] & 0xc0 | (byte)local_58 & 0x3f;
              *(ushort *)(pbVar9 + -2) =
                   *(ushort *)(pbVar9 + -2) & 0xf03f | (ushort)(((local_58 & 0xff) + 1 & 0x3f) << 6)
              ;
              *(uint *)(pbVar9 + -2) =
                   *(uint *)(pbVar9 + -2) & 0xfffc0fff | ((local_58 & 0xff) + 2 & 0x3f) << 0xc;
              *pbVar9 = *pbVar9 & 3 | (byte)local_58 * '\x04' + 0xc;
              *(uint *)(param_1 + 0x1b50) = *(uint *)(param_1 + 0x1b50) & ~(1 << (bVar5 & 0x1f));
              *(uint *)(param_1 + 0x1bc0) =
                   *(uint *)(param_1 + 0x1bc0) & ~(1 << ((byte)local_5c * '\x02' & 0x1f));
              local_58 = local_58 + (*(uint *)(param_1 + 0x1ba0) >> (bVar2 & 0x1f) & 7);
            }
            else {
              *(byte *)(param_1 + 0x1a64) = *(byte *)(param_1 + 0x1a64) | 0x10;
              local_4c = local_4c & ~(7 << (bVar2 & 0x1f));
              *(uint *)(param_1 + 0x1b50) = *(uint *)(param_1 + 0x1b50) | 1 << (bVar5 & 0x1f);
              *(uint *)(param_1 + 0x1bc0) =
                   *(uint *)(param_1 + 0x1bc0) | 1 << ((byte)local_5c * '\x02' & 0x1f);
              pbVar9[-2] = pbVar9[-2] & 0xc0 | (byte)local_58 & 0x3f;
              *(ushort *)(pbVar9 + -2) =
                   *(ushort *)(pbVar9 + -2) & 0xf03f | ((byte)((byte)local_58 + 1) & 0x3f) << 6;
              *(uint *)(pbVar9 + -2) = *(uint *)(pbVar9 + -2) & 0xfffc0fff | 0x3e000;
              *pbVar9 = *pbVar9 | 0xfc;
              local_58 = local_58 + 2;
            }
            local_5c = local_5c + 1;
            pbVar9 = pbVar9 + 4;
            bVar2 = bVar2 + 3;
            bVar5 = bVar5 + 2;
          } while (local_5c < (int)(uint)*(byte *)(param_1 + 0x13b2));
        }
      }
    }
    else {
      if (*(int *)(param_1 + 0x2768) != 0) goto LAB_000a24fb;
      if ((*(byte *)(param_1 + 0x45) & 0x40) == 0) {
        if (*(char *)(param_1 + 0x13b2) == '\0') goto LAB_000a294c;
        local_30 = param_1;
        local_28 = 0;
        iVar4 = 0;
        bVar7 = 0;
        do {
          if (((*(byte *)(local_30 + 0x48) & 0x1f) != 0) && (*(int *)(local_30 + 0x13f8) != 0)) {
            *(byte *)(param_1 + 0x1ee8 + iVar4 * 4) =
                 *(byte *)(param_1 + 0x1ee8 + iVar4 * 4) & 0xc0 | (byte)local_28 & 0x3f;
            *(ushort *)(param_1 + 0x1ee8 + iVar4 * 4) =
                 *(ushort *)(param_1 + 0x1ee8 + iVar4 * 4) & 0xf03f |
                 (ushort)(((local_28 & 0xff) + 1 & 0x3f) << 6);
            *(uint *)(param_1 + 0x1ee8 + iVar4 * 4) =
                 *(uint *)(param_1 + 0x1ee8 + iVar4 * 4) & 0xfffc0fff |
                 ((local_28 & 0xff) + 2 & 0x3f) << 0xc;
            *(byte *)(param_1 + 0x1eea + iVar4 * 4) =
                 *(byte *)(param_1 + 0x1eea + iVar4 * 4) & 3 | (byte)local_28 * '\x04' + 0xc;
          }
          local_28 = local_28 + (*(uint *)(param_1 + 0x1ba0) >> (bVar7 & 0x1f) & 7);
          iVar4 = iVar4 + 1;
          local_30 = local_30 + 4;
          bVar7 = bVar7 + 3;
        } while (iVar4 < (int)(uint)*(byte *)(param_1 + 0x13b2));
      }
      else {
        if ((*(byte *)(param_1 + 0x46) & 4) == 0) {
          bVar7 = *(byte *)(param_1 + 0x1135);
        }
        else {
          bVar7 = *(byte *)(param_1 + 0x11d3);
        }
        if (*(char *)(param_1 + 0x13b2) == '\0') {
LAB_000a294c:
          (*(unsigned char *)((unsigned char *)&(local_28) + 0)) = 0;
        }
        else {
          local_28 = 0;
          local_20 = 0;
          bVar2 = 0;
          pbVar9 = (byte *)(param_1 + 0x1eea);
          do {
            if ((bVar7 >> ((byte)local_20 & 0x1f) & 1) != 0) {
              pbVar9[-2] = pbVar9[-2] & 0xc0 | (byte)local_28 & 0x3f;
              *(ushort *)(pbVar9 + -2) =
                   *(ushort *)(pbVar9 + -2) & 0xf03f | (ushort)(((local_28 & 0xff) + 1 & 0x3f) << 6)
              ;
              *(uint *)(pbVar9 + -2) =
                   *(uint *)(pbVar9 + -2) & 0xfffc0fff | ((local_28 & 0xff) + 2 & 0x3f) << 0xc;
              *pbVar9 = *pbVar9 & 3 | (byte)local_28 * '\x04' + 0xc;
            }
            local_28 = local_28 + (*(uint *)(param_1 + 0x1ba0) >> (bVar2 & 0x1f) & 7);
            local_20 = local_20 + 1;
            pbVar9 = pbVar9 + 4;
            bVar2 = bVar2 + 3;
          } while (local_20 < (int)(uint)*(byte *)(param_1 + 0x13b2));
        }
      }
      *(uint *)(param_1 + 0x1b50) = (uint)*(ushort *)(param_1 + 0x1b50);
      *(undefined4 *)(param_1 + 0x1bc0) = 0;
      (*(unsigned char *)((unsigned char *)&(local_58) + 0)) = (byte)local_28;
    }
    *(byte *)(param_1 + 0x1f2c) = *(byte *)(param_1 + 0x1f2c) & 0x80 | (byte)local_58 & 0x7f;
    puVar3 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0xd);
    *(undefined4 **)(param_1 + 0x274c) = puVar3;
    *puVar3 = 0x10c0;
    puVar3[1] = *(undefined4 *)(param_1 + 0x1f2c);
    puVar3[2] = 0x825;
    puVar3[3] = *(undefined4 *)(param_1 + 0x1ba0);
    puVar3[4] = *(uint *)(param_1 + 0x1f28) | 0x70000;
    iVar6 = 1;
    iVar4 = param_1;
    do {
      puVar3[iVar6 + 4] = *(undefined4 *)(iVar4 + 0x1ee8);
      iVar6 = iVar6 + 1;
      iVar4 = iVar4 + 4;
    } while (iVar6 != 9);
    iVar4 = *(int *)(param_1 + 0x274c) + 0x34;
    *(int *)(param_1 + 0x274c) = iVar4;
    (**(code **)(param_1 + 0x275c))(param_1,iVar4);
  }
  *(uint *)(param_1 + 0x1ba8) = local_4c;
LAB_000a2132:
  puVar3 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0xc);
  *(undefined4 **)(param_1 + 0x274c) = puVar3;
  *puVar3 = 0x1002;
  puVar3[1] = *(undefined4 *)(param_1 + 0x1b50);
  puVar3[2] = 0x825;
  puVar3[3] = *(undefined4 *)(param_1 + 0x1ba0);
  puVar3[4] = 0x1007;
  puVar3[5] = *(undefined4 *)(param_1 + 0x1a64);
  puVar3[6] = FUN_0000108e;
  puVar3[7] = *(undefined4 *)(param_1 + 0x1b64);
  puVar3[8] = 0x1098;
  puVar3[9] = *(undefined4 *)(param_1 + 0x1b68);
  puVar3[10] = 0x10c0;
  puVar3[0xb] = *(undefined4 *)(param_1 + 0x1f2c);
  iVar4 = *(int *)(param_1 + 0x274c) + 0x30;
  *(int *)(param_1 + 0x274c) = iVar4;
  (**(code **)(param_1 + 0x275c))(param_1,iVar4);
  if (*(char *)(param_1 + 0x1868) != '\0') {
    puVar3 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,9);
    *puVar3 = 0x7101d;
    *(undefined4 **)(param_1 + 0x274c) = puVar3 + 1;
    iVar4 = param_1;
    do {
      puVar3 = *(undefined4 **)(param_1 + 0x274c);
      *puVar3 = *(undefined4 *)(iVar4 + 0x1ee8);
      puVar3 = puVar3 + 1;
      *(undefined4 **)(param_1 + 0x274c) = puVar3;
      iVar4 = iVar4 + 4;
    } while (iVar4 != param_1 + 0x20);
    (**(code **)(param_1 + 0x275c))(param_1,puVar3);
  }
  if (iVar1 == 0) {
    (**(code **)(param_1 + 0x1330))(param_1,0xc0100000);
  }
  if (*(int *)(param_1 + 0x1ba8) == *(int *)(param_1 + 0x1ba0)) {
    return;
  }
  puVar3 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
  *(undefined4 **)(param_1 + 0x274c) = puVar3;
  *puVar3 = 0x1001;
  *(undefined4 *)(*(int *)(param_1 + 0x274c) + 4) = *(undefined4 *)(param_1 + 0x1ba8);
  *(int *)(param_1 + 0x274c) = *(int *)(param_1 + 0x274c) + 8;
                    
                    
  (**(code **)(param_1 + 0x275c))();
  return;
}

/* FUN_000a2967 @ 0xa2967 (113 bytes) */
int FUN_000a2967(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x2764);
  while (iVar2 != 0) {
    if (*(int *)(iVar2 + 0xbc) != 0) {
      FUN_0002e539(param_1,*(undefined4 *)(*(int *)(iVar2 + 0xbc) + 0x7c));
    }
    iVar1 = *(int *)(iVar2 + 0x138);
    (**(code **)(param_1 + 0x18))(iVar2);
    iVar2 = iVar1;
  }
  *(undefined4 *)(param_1 + 0x2764) = 0;
  *(undefined4 *)(param_1 + 0x2768) = 0;
  *(undefined4 *)(param_1 + 0x2778) = 0;
  return;
}

/* FUN_000a29d8 @ 0xa29d8 (131 bytes) */
int FUN_000a29d8(param_1)
  int param_1;
{
  int iVar1;
  
  for (iVar1 = *(int *)(param_1 + 0x2764); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x138)) {
    if ((*(int *)(iVar1 + 0xbc) != 0) && (-1 < *(int *)(param_1 + 0x276c))) {
      FUN_0002e4b8(param_1,0,*(int *)(param_1 + 0x276c));
    }
  }
  *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x200;
  *(ushort *)(param_1 + 0x32) =
       *(ushort *)(param_1 + 0x32) | (ushort)(1 << ((byte)*(undefined4 *)(param_1 + 0x276c) & 0x1f))
  ;
  *(ushort *)(param_1 + 0x34) =
       *(ushort *)(param_1 + 0x34) | (ushort)(1 << ((byte)*(undefined4 *)(param_1 + 0x276c) & 0x1f))
  ;
  return;
}

/* FUN_000a2a5b @ 0xa2a5b (313 bytes) */
int FUN_000a2a5b(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 local_14;
  undefined4 local_10;
  
  iVar1 = *(int *)(param_1 + 0x1154);
  if (*(int *)(iVar1 + 4) != 0) {
    local_14 = 0;
    iVar3 = 0;
    do {
      iVar2 = *(int *)(*(int *)(iVar3 + 0x70 + *(int *)(iVar1 + 0x88)) +
                      *(int *)(param_1 + 0x113c) * 4);
      if (iVar2 != 0) {
        *(undefined4 *)(iVar2 + 0x15d0) = 1;
      }
      local_14 = local_14 + 1;
      iVar3 = iVar3 + 0x78;
    } while (local_14 < *(uint *)(iVar1 + 4));
  }
  iVar1 = *(int *)(param_1 + 0x112c);
  if (*(int *)(iVar1 + 4) != 0) {
    local_10 = 0;
    iVar3 = 0;
    do {
      while ((iVar2 = iVar3 + *(int *)(iVar1 + 8), *(int *)(iVar2 + 4) == 0x8804 &&
             (iVar2 = *(int *)(*(int *)(*(int *)(iVar2 + 0x14) + 0x70) +
                              *(int *)(param_1 + 0x1130) * 4), iVar2 != 0))) {
        *(undefined4 *)(iVar2 + 0x15d0) = 1;
        local_10 = local_10 + 1;
        iVar3 = iVar3 + 0x18;
        if (*(uint *)(iVar1 + 4) <= local_10) goto LAB_000a2b2d;
      }
      local_10 = local_10 + 1;
      iVar3 = iVar3 + 0x18;
    } while (local_10 < *(uint *)(iVar1 + 4));
  }
LAB_000a2b2d:
  FUN_00049f1d(param_1,0);
  *(uint *)(param_1 + 0x1b50) = (uint)*(ushort *)(param_1 + 0x1b50);
  *(byte *)(param_1 + 0x1a64) = *(byte *)(param_1 + 0x1a64) & 0xef;
  *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x2000;
  ((int (*)())FUN_000a29d8)(param_1);
  *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x200;
  *(ushort *)(param_1 + 0x34) =
       *(ushort *)(param_1 + 0x34) | (ushort)(1 << ((byte)*(undefined4 *)(param_1 + 0x276c) & 0x1f))
  ;
  *(undefined1 *)(param_1 + 0x29) = 1;
  *(undefined4 *)(param_1 + 0x2768) = 0;
  *(undefined4 *)(param_1 + 0x276c) = 0xffffffff;
  return;
}

/* FUN_000a2b94 @ 0xa2b94 (102 bytes) */
int FUN_000a2b94(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 0x2768) != 0) {
    FUN_0002e4b8(param_1,*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x2768) + 0xbc) + 0x7c),
                 *(undefined4 *)(param_1 + 0x276c));
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x200;
    *(ushort *)(param_1 + 0x32) =
         *(ushort *)(param_1 + 0x32) |
         (ushort)(1 << ((byte)*(undefined4 *)(param_1 + 0x276c) & 0x1f));
    *(ushort *)(param_1 + 0x34) =
         *(ushort *)(param_1 + 0x34) |
         (ushort)(1 << ((byte)*(undefined4 *)(param_1 + 0x276c) & 0x1f));
  }
  return 1;
}

/* FUN_000a2bfa @ 0xa2bfa (19 bytes) */
int FUN_000a2bfa(param_1)
  int param_1;
{
  return *(undefined4 *)(param_1 + 0x29ac);
}

/* FUN_000a2c0d @ 0xa2c0d (344 bytes) */
int FUN_000a2c0d(param_1)
  int param_1;
{
  float fVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  
  iVar5 = *(int *)(param_1 + 4);
  iVar2 = *(int *)(iVar5 + 0x10);
  uVar4 = *(uint *)(param_1 + 8);
  if (((*(char *)(iVar2 + 0x2e2d) == '\0') || ((*(byte *)(param_1 + 0x45) & 0x40) != 0)) ||
     (cVar3 = FUN_00017bd8(iVar5,*(undefined4 *)(iVar5 + 0x26a0)), cVar3 != '\0')) {
    fVar7 = *(float *)(iVar2 + 0x2e20);
    iVar5 = *(int *)(param_1 + 0x13e0);
    if (((float)iVar5 < fVar7) &&
       (iVar5 = *(int *)(param_1 + 0x13e4), fVar7 < (float)*(int *)(param_1 + 0x13e4))) {
      iVar5 = (int)(fVar7 + FLOAT_001c5bd4);
    }
    uVar4 = iVar5 * uVar4 >> 1;
  }
  else {
    fVar7 = *(float *)(iVar2 + 0x2e20);
    fVar1 = *(float *)(param_1 + 0x13e8);
    fVar6 = fVar1;
    if ((fVar1 < fVar7) &&
       (fVar6 = *(float *)(param_1 + 0x13ec), fVar7 < *(float *)(param_1 + 0x13ec))) {
      fVar6 = fVar1 + *(float *)(param_1 + 0x13f0) *
                      (float)(int)((fVar7 - fVar1) / *(float *)(param_1 + 0x13f0) + FLOAT_001c5bd4);
    }
    fVar7 = FLOAT_001c5bd0;
    if (*(short *)(iVar2 + 0x2e10) != 0x1102) {
      fVar7 = FLOAT_001c5ba4;
    }
    uVar4 = (uint)((float)uVar4 * FLOAT_001c5bd4 *
                  ((float)(~-(uint)(fVar6 < FLOAT_001c5ba4) & (uint)fVar6 |
                          -(uint)(fVar6 < FLOAT_001c5ba4) & (uint)FLOAT_001c5ba4) + fVar7));
  }
  return uVar4;
}

/* FUN_000a2d65 @ 0xa2d65 (5373 bytes) */
int FUN_000a2d65(param_1)
  int param_1;
{
  byte bVar1;
  short sVar2;
  undefined4 uVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  undefined2 uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  void *pvVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  byte *pbVar19;
  char *pcVar20;
  char *pcVar21;
  ushort uVar22;
  char *pcVar23;
  char *pcVar24;
  uint uVar25;
  void *pvVar26;
  int iVar27;
  bool bVar28;
  bool bVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  float fVar33;
  float fVar34;
  float fVar35;
  float fVar36;
  float fVar37;
  uint local_d0;
  int local_cc;
  char *local_b4;
  char local_ae;
  char local_ad;
  uint local_88;
  void *local_84;
  int local_70;
  void *local_6c;
  int local_58;
  uint local_50;
  uint local_4c;
  void *local_44;
  int local_40;
  char local_39;
  int local_34;
  int local_30;
  int local_20 [4];
  
  if ((*(ushort *)(param_1 + 0x44) & 0x4006) != 2) {
    local_d0 = *(int *)(param_1 + 4);
    if ((*(char *)(*(int *)(local_d0 + 0x10) + 0x2e2d) != '\0') &&
       ((*(byte *)(param_1 + 0x45) & 0x40) == 0)) {
      cVar4 = FUN_00017bd8(local_d0,*(undefined4 *)(local_d0 + 0x26a0));
      if (cVar4 == '\0') goto LAB_000a2e2b;
      local_d0 = *(int *)(param_1 + 4);
    }
    iVar9 = *(int *)(local_d0 + 0x10);
    if ((((*(char *)(iVar9 + 0x2e2c) == '\0') || ((*(byte *)(param_1 + 0x45) & 0x40) != 0)) ||
        (*(short *)(iVar9 + 0x2e28) == -1)) &&
       (((*(char *)(iVar9 + 0x3178) == '\0' || ((*(byte *)(param_1 + 0x45) & 0x40) != 0)) ||
        ((*(short *)(iVar9 + 0x3170) != 0x1b02 && (*(short *)(iVar9 + 0x3172) != 0x1b02)))))) {
      if (*(int *)(param_1 + 0x2768) == 0) {
        return 0;
      }
      ((int (*)())FUN_000a2a5b)();
      return 0;
    }
  }
LAB_000a2e2b:
  iVar9 = *(int *)(param_1 + 0x276c);
  if (iVar9 < 0) {
    uVar8 = 1;
  }
  else {
    uVar8 = (int)(uint)*(ushort *)(param_1 + 0x34) >> ((byte)iVar9 & 0x1f) & 1U |
            *(uint *)(param_1 + 0x38) & 0x10310e;
  }
  if (uVar8 == 0 && *(int *)(param_1 + 0x2458) == 0) {
    return 0;
  }
  local_d0 = *(byte *)(param_1 + 0x13b2) - 1;
  if (-1 < (int)local_d0) {
    pbVar19 = (byte *)(param_1 + 0x48 + local_d0 * 4);
    do {
      if ((((*pbVar19 & 0x1f) == 0) || (*(int *)(pbVar19 + 0x13b0) == 0)) &&
         ((bVar1 = *(byte *)(param_1 + 0x46), (bVar1 & 4) == 0 ||
          (((((int)(uint)*(byte *)(param_1 + 0x11d3) >> ((byte)local_d0 & 0x1f) & 1U) == 0 &&
            (((bVar1 & 0x10) == 0 || (*(byte *)(param_1 + 0x11d1) != local_d0)))) &&
           (((bVar1 & 0x20) == 0 || (*(byte *)(param_1 + 0x11d2) != local_d0)))))))) break;
      local_d0 = local_d0 - 1;
      pbVar19 = pbVar19 + -4;
    } while (local_d0 != 0xffffffff);
  }
  if (iVar9 < 0) {
    uVar8 = 0;
  }
  else {
    uVar8 = 1 << ((byte)iVar9 & 0x1f);
  }
  if (-1 < (int)local_d0) {
    uVar8 = uVar8 | 1 << ((byte)local_d0 & 0x1f);
  }
  if (uVar8 != 0) {
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x200;
    *(ushort *)(param_1 + 0x32) = *(ushort *)(param_1 + 0x32) | (ushort)uVar8;
    *(ushort *)(param_1 + 0x34) = *(ushort *)(param_1 + 0x34) | (ushort)uVar8;
  }
  *(uint *)(param_1 + 0x276c) = local_d0;
  if ((int)local_d0 < 0) goto LAB_000a307d;
  cVar4 = *(char *)(param_1 + 0x2458);
  iVar9 = *(int *)(param_1 + 4);
  iVar27 = *(int *)(iVar9 + 0x10);
  bVar28 = (*(ushort *)(param_1 + 0x44) & 0x4006) == 2;
  cVar5 = FUN_00017bd8(iVar9,*(undefined4 *)(iVar9 + 0x26a0));
  iVar9 = ((int (*)())FUN_000a1d5b)();
  sVar2 = *(short *)(iVar27 + 0x2e0e);
  local_d0 = *(int *)(param_1 + 4);
  if ((*(char *)(*(int *)(local_d0 + 0x10) + 0x2e2d) == '\0') ||
     ((*(byte *)(param_1 + 0x45) & 0x40) != 0)) {
LAB_000a3043:
    local_39 = '\0';
  }
  else {
    cVar6 = FUN_00017bd8(local_d0,*(undefined4 *)(local_d0 + 0x26a0));
    if (cVar6 != '\0') {
      local_d0 = *(int *)(param_1 + 4);
      goto LAB_000a3043;
    }
    local_39 = '\x01';
    local_d0 = *(int *)(param_1 + 4);
  }
  if (((*(char *)(*(int *)(local_d0 + 0x10) + 0x2e2c) == '\0') ||
      ((*(byte *)(param_1 + 0x45) & 0x40) != 0)) ||
     (*(short *)(*(int *)(local_d0 + 0x10) + 0x2e28) == -1)) {
    local_ae = '\0';
  }
  else {
    local_ae = '\x01';
  }
  iVar10 = ((int (*)())FUN_000a2c0d)();
  fVar30 = *(float *)(iVar27 + 0x2e20);
  fVar36 = *(float *)(param_1 + 0x13e8);
  fVar34 = fVar36;
  if ((fVar36 < fVar30) &&
     (fVar34 = *(float *)(param_1 + 0x13ec), fVar30 < *(float *)(param_1 + 0x13ec))) {
    fVar34 = fVar36 + *(float *)(param_1 + 0x13f0) *
                      (float)(int)((fVar30 - fVar36) / *(float *)(param_1 + 0x13f0) + FLOAT_001c5bd4
                                  );
  }
  local_d0 = *(int *)(param_1 + 4);
  iVar15 = *(int *)(local_d0 + 0x10);
  if (((*(char *)(iVar15 + 0x3178) == '\0') || ((*(byte *)(param_1 + 0x45) & 0x40) != 0)) ||
     ((*(short *)(iVar15 + 0x3170) != 0x1b02 && (*(short *)(iVar15 + 0x3172) != 0x1b02)))) {
    local_ad = '\0';
  }
  else {
    local_ad = '\x01';
  }
  if (cVar4 != '\0') {
    local_ae = '\x01';
    local_ad = '\x01';
  }
  for (local_b4 = *(char **)(param_1 + 0x2764); local_b4 != (char *)0x0;
      local_b4 = *(char **)(local_b4 + 0x138)) {
    if ((bVar28 == (bool)*local_b4) &&
       (((!bVar28 ||
         ((((cVar5 == '\0') == (bool)local_b4[1] && (iVar9 == *(int *)(local_b4 + 4))) &&
          ((sVar2 == 0x1102) == (bool)local_b4[8])))) &&
        ((local_39 == local_b4[0x14] && (local_ae == local_b4[0x15])))))) {
      if ((local_39 == '\0') && (local_ae == '\0')) {
LAB_000a3287:
        if (((((uint)*(ushort *)(iVar27 + 0x3170) == *(uint *)(local_b4 + 0xb4)) &&
             ((uint)*(ushort *)(iVar27 + 0x3172) == *(uint *)(local_b4 + 0xb8))) ||
            (((uint)*(ushort *)(iVar27 + 0x3170) == *(uint *)(local_b4 + 0xb8) &&
             ((uint)*(ushort *)(iVar27 + 0x3172) == *(uint *)(local_b4 + 0xb4))))) &&
           (local_ad == local_b4[0x2a])) {
          if (local_ad == '\0') goto LAB_000a3e64;
          bVar29 = local_b4 + 0x2c == (char *)0x0;
          iVar15 = 0x80;
          pcVar20 = local_b4 + 0x2c;
          pcVar23 = (char *)(iVar27 + 0x30e8);
          do {
            pcVar21 = pcVar20;
            pcVar24 = pcVar23;
            if (iVar15 == 0) break;
            iVar15 = iVar15 + -1;
            pcVar24 = pcVar23 + 1;
            pcVar21 = pcVar20 + 1;
            bVar29 = *pcVar20 == *pcVar23;
            pcVar20 = pcVar21;
            pcVar23 = pcVar24;
          } while (bVar29);
          iVar15 = 0;
          if (!bVar29) {
            iVar15 = (uint)(byte)pcVar21[-1] - (uint)(byte)pcVar24[-1];
          }
          if (iVar15 == 0) goto LAB_000a3e64;
        }
      }
      else if ((iVar10 == *(int *)(local_b4 + 0x18)) &&
              ((*(short *)(iVar27 + 0x2e10) == 0x1102) == (bool)local_b4[0x1c])) {
        if ((local_39 != '\0') && (fVar30 = *(float *)(local_b4 + 0x20), fVar30 < FLOAT_001c5bd0)) {
          if ((fVar34 != fVar30) || (NAN(fVar34) || NAN(fVar30))) goto LAB_000a31ae;
        }
        if ((local_ae == '\0') || (*(short *)(iVar27 + 0x2e28) == *(short *)(local_b4 + 0x28)))
        goto LAB_000a3287;
      }
    }
LAB_000a31ae: ;
  }
  if (*(int *)(param_1 + 0x2778) == 0x100) {
    ((int (*)())FUN_000a2967)(param_1);
    local_d0 = *(int *)(param_1 + 4);
  }
  cVar4 = *(char *)(param_1 + 0x2458);
  iVar9 = *(int *)(local_d0 + 0x10);
  local_b4 = (char *)(**(code **)(param_1 + 0x10))(1,0x13c);
  if (local_b4 == (char *)0x0) goto LAB_000a307d;
  *local_b4 = (*(ushort *)(param_1 + 0x44) & 0x4006) == 2;
  cVar5 = FUN_00017bd8(*(int *)(param_1 + 4),*(undefined4 *)(*(int *)(param_1 + 4) + 0x26a0));
  local_b4[1] = cVar5 == '\0';
  local_b4[8] = *(short *)(iVar9 + 0x2e0e) == 0x1102;
  iVar27 = *(int *)(param_1 + 4);
  if (((*(char *)(*(int *)(iVar27 + 0x10) + 0x2e2d) == '\0') ||
      ((*(byte *)(param_1 + 0x45) & 0x40) != 0)) ||
     (cVar5 = FUN_00017bd8(iVar27,*(undefined4 *)(iVar27 + 0x26a0)), cVar5 != '\0')) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  local_b4[0x14] = cVar5;
  local_b4[0x1c] = *(short *)(iVar9 + 0x2e10) == 0x1102;
  fVar30 = *(float *)(iVar9 + 0x2e20);
  fVar36 = *(float *)(param_1 + 0x13e8);
  fVar34 = fVar36;
  if ((fVar36 < fVar30) &&
     (fVar34 = *(float *)(param_1 + 0x13ec), fVar30 < *(float *)(param_1 + 0x13ec))) {
    fVar34 = fVar36 + *(float *)(param_1 + 0x13f0) *
                      (float)(int)((fVar30 - fVar36) / *(float *)(param_1 + 0x13f0) + FLOAT_001c5bd4
                                  );
  }
  *(float *)(local_b4 + 0x20) = fVar34;
  iVar27 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (((*(char *)(iVar27 + 0x2e2c) == '\0') || ((*(byte *)(param_1 + 0x45) & 0x40) != 0)) ||
     (*(short *)(iVar27 + 0x2e28) == -1)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  local_b4[0x15] = cVar5;
  iVar27 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (((*(char *)(iVar27 + 0x3178) == '\0') || ((*(byte *)(param_1 + 0x45) & 0x40) != 0)) ||
     ((*(short *)(iVar27 + 0x3170) != 0x1b02 && (*(short *)(iVar27 + 0x3172) != 0x1b02)))) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  local_b4[0x2a] = cVar5;
  *(uint *)(local_b4 + 0xb4) = (uint)*(ushort *)(iVar9 + 0x3170);
  *(uint *)(local_b4 + 0xb8) = (uint)*(ushort *)(iVar9 + 0x3172);
  if (cVar4 != '\0') {
    local_b4[0x15] = '\x01';
    local_b4[0x2a] = '\x01';
  }
  if (*local_b4 == '\0') {
    if ((*(int *)(local_b4 + 0xb4) == 0x1b00) || (*(int *)(local_b4 + 0xb8) == 0x1b00)) {
LAB_000a41ca:
      local_88 = 1;
    }
    else {
      local_88 = 0;
    }
  }
  else {
    iVar27 = ((int (*)())FUN_000a1d5b)();
    *(int *)(local_b4 + 4) = iVar27;
    if (iVar27 * 4 < 1) goto LAB_000a41ca;
    local_88 = 1;
  }
  if (*(short *)(local_b4 + 0x14) == 0) {
    if ((*(int *)(local_b4 + 0xb4) == 0x1b01) || (*(int *)(local_b4 + 0xb8) == 0x1b01)) {
      local_88 = local_88 + 1;
    }
  }
  else {
    if (*(char *)(iVar9 + 0x2e2c) == '\0') {
      uVar7 = 0xffff;
    }
    else {
      uVar7 = *(undefined2 *)(iVar9 + 0x2e28);
    }
    *(undefined2 *)(local_b4 + 0x28) = uVar7;
    uVar11 = ((int (*)())FUN_000a2c0d)();
    *(undefined4 *)(local_b4 + 0x18) = uVar11;
    local_88 = local_88 + 1;
  }
  if (local_b4[0x2a] != '\0') {
    (**(code **)(param_1 + 0x1344))(local_b4 + 0x2c,iVar9 + 0x30e8,0x80);
    *(undefined4 *)(local_b4 + 0xac) = *(undefined4 *)(param_1 + 0x2770);
    *(undefined4 *)(local_b4 + 0xb0) = *(undefined4 *)(param_1 + 0x2774);
    local_88 = local_88 + 1;
  }
  uVar11 = FUN_000a1cdb();
  uVar12 = FUN_000a1cdb();
  uVar8 = 4;
  if (local_88 < 2) {
    uVar8 = local_88;
  }
  uVar3 = *(undefined4 *)(param_1 + 4);
  iVar9 = FUN_0002e69b(param_1,uVar11,uVar12,uVar8,0x1909,1,0x1401,(uVar8 < 2) * '\x02' + '\x01');
  if (iVar9 == 0) {
    iVar27 = 0;
  }
  else {
    FUN_0002bd2c(uVar3,iVar9);
    *(undefined1 *)(iVar9 + 0x39) = 0xff;
    iVar27 = iVar9 + 0x3c;
    iVar10 = *(int *)(iVar9 + 0x30);
    *(undefined2 *)(iVar9 + 0x74) = *(undefined2 *)(iVar10 + 0xb0);
    *(undefined2 *)(iVar9 + 0x7c) = *(undefined2 *)(iVar10 + 0xac);
    *(uint *)(iVar9 + 0xc0) = (uint)*(ushort *)(iVar10 + 0xae) * (uint)*(ushort *)(iVar10 + 0xac);
    *(undefined4 *)(iVar9 + 0xbc) = *(undefined4 *)(iVar10 + 0xb4);
    *(undefined2 *)(iVar9 + 0xa0) = 0x2600;
    *(undefined2 *)(iVar9 + 0xa2) = 0x2600;
    *(byte *)(iVar9 + 0x51) = *(byte *)(iVar9 + 0x51) & 0x81 | 10;
    *(uint *)(iVar9 + 0x50) = *(uint *)(iVar9 + 0x50) & 0xfffe7fff | 0x8000;
    *(byte *)(iVar9 + 0x54) = *(byte *)(iVar9 + 0x54) & 0xfc | 1;
  }
  *(int *)(local_b4 + 0xbc) = iVar27;
  if (iVar27 == 0) {
    _free(local_b4);
  }
  else {
    local_84 = *(void **)(iVar27 + 0x80);
    if (*local_b4 == '\0') {
      if (1 < uVar8) {
        _memset(local_84,0xff,*(size_t *)(iVar27 + 0x84));
      }
    }
    else {
      uVar25 = (uint)*(ushort *)(iVar27 + 0x3a);
      uVar17 = (uint)*(ushort *)(iVar27 + 0x3c);
      iVar9 = *(int *)(local_b4 + 4);
      iVar27 = iVar9 * 2;
      fVar30 = (float)iVar27;
      if (local_b4[1] == '\0') {
        fVar36 = 0.0;
        local_70 = 0;
      }
      else {
        local_70 = (**(code **)(param_1 + 0xc))(iVar27);
        if (local_70 == 0) {
          fVar36 = 0.0;
        }
        else {
          if (((*(byte *)(param_1 + 0xe8) & 1) == 0) && (local_b4[8] == '\0')) {
            ((int (*)())FUN_000a1f97)(local_20);
          }
          else {
            ((int (*)())FUN_000a1e00)(local_20);
          }
          fVar36 = (float)(iVar27 - local_20[0]) - FLOAT_001c5bd4;
          fVar36 = fVar36 * fVar36;
        }
      }
      fVar33 = FLOAT_001c5bd4;
      fVar34 = FLOAT_001c5ba4;
      fVar37 = FLOAT_001c5bd4 - fVar30;
      if (local_70 == 0) {
        if (uVar17 != 0) {
          uVar16 = 0;
          fVar36 = fVar37;
          do {
            if (uVar25 != 0) {
              uVar18 = 0;
              fVar33 = fVar37;
              do {
                *(char *)((int)local_84 + uVar18) =
                     (fVar30 * fVar30 <= fVar33 * fVar33 + fVar36 * fVar36) + -1;
                fVar33 = fVar33 + fVar34;
                uVar18 = uVar18 + 1;
              } while (uVar25 != uVar18);
            }
            fVar36 = fVar36 + fVar34;
            local_84 = (void *)((int)local_84 + uVar25);
            uVar16 = uVar16 + 1;
          } while (uVar17 != uVar16);
        }
      }
      else {
        if (uVar17 != 0) {
          uVar16 = 0;
          fVar35 = fVar37;
          do {
            if (uVar25 != 0) {
              uVar18 = 0;
              fVar32 = fVar37;
              do {
                fVar31 = fVar32 * fVar32 + fVar35 * fVar35;
                if (fVar31 < fVar36) {
                  *(undefined1 *)((int)local_84 + uVar18) = 0xff;
                }
                else if (fVar31 < fVar30 * fVar30) {
                  *(undefined1 *)((int)local_84 + uVar18) =
                       *(undefined1 *)(local_70 + (int)((fVar30 - SQRT(fVar31)) + fVar33));
                }
                else {
                  *(undefined1 *)((int)local_84 + uVar18) = 0;
                }
                fVar32 = fVar32 + fVar34;
                uVar18 = uVar18 + 1;
              } while (uVar25 != uVar18);
            }
            fVar35 = fVar35 + fVar34;
            local_84 = (void *)((int)local_84 + uVar25);
            uVar16 = uVar16 + 1;
          } while (uVar17 != uVar16);
        }
        (**(code **)(param_1 + 0x18))(local_70);
      }
      fVar30 = (float)(iVar9 << 2);
      *(float *)(local_b4 + 0xc) = fVar30 / (float)uVar25;
      *(float *)(local_b4 + 0x10) = fVar30 / (float)uVar17;
    }
    iVar9 = *(int *)(local_b4 + 0xbc);
    local_6c = *(void **)(iVar9 + 0x80);
    if (1 < uVar8) {
      local_6c = (void *)((int)local_6c + *(int *)(iVar9 + 0x84));
    }
    if (*(short *)(local_b4 + 0x14) == 0) {
      if (1 < uVar8) {
        _memset(local_6c,0xff,*(size_t *)(iVar9 + 0x84));
        iVar9 = *(int *)(local_b4 + 0xbc);
      }
    }
    else {
      uVar17 = (uint)*(ushort *)(iVar9 + 0x3a);
      iVar27 = *(int *)(local_b4 + 0x18);
      iVar10 = iVar27 * 4;
      iVar15 = (int)(uint)*(ushort *)(iVar9 + 0x3c) >> 4;
      pvVar13 = (void *)((*(ushort *)(iVar9 + 0x3c) - 1) * uVar17 + (int)local_6c);
      if (local_b4[0x14] == '\0') {
        _memset(pvVar13,0xff,uVar17);
        local_b4[0x24] = '\0';
        local_b4[0x25] = '\0';
        local_b4[0x26] = -0x80;
        local_b4[0x27] = '?';
      }
      else {
        if (local_b4[0x1c] == '\0') {
          ((int (*)())FUN_000a1f97)(local_20);
        }
        else {
          ((int (*)())FUN_000a1e00)(local_20);
        }
        if (0 < local_20[0]) {
          pvVar26 = (void *)((int)pvVar13 + iVar10);
          iVar9 = 0;
          do {
            *(undefined1 *)((int)pvVar26 + -1) = *(undefined1 *)(iVar9 + (int)pvVar13);
            iVar9 = iVar9 + 1;
            pvVar26 = (void *)((int)pvVar26 + -1);
          } while (iVar9 < local_20[0]);
        }
        _memset((void *)((int)pvVar13 + local_20[0]),0xff,iVar10 + local_20[0] * -2);
        _memset((void *)((int)pvVar13 + iVar10),0,uVar17 + iVar27 * -4);
        *(float *)(local_b4 + 0x24) = (float)iVar10 / (float)uVar17;
      }
      iVar9 = *(int *)(*(int *)(param_1 + 4) + 0x10);
      if (((*(char *)(iVar9 + 0x2e2c) == '\0') || ((*(byte *)(param_1 + 0x45) & 0x40) != 0)) ||
         (uVar22 = *(ushort *)(iVar9 + 0x2e28), uVar22 == 0xffff)) {
        uVar22 = 0xffff;
      }
      local_30 = 0;
      do {
        if ((uVar22 & 1) == 0) {
          _memset(local_6c,0,uVar17 * iVar15);
          local_6c = (void *)((int)local_6c + uVar17 * iVar15);
        }
        else {
          iVar9 = iVar15;
          if (local_30 == 0xf) {
            iVar9 = iVar15 + -1;
          }
          if (0 < iVar9) {
            local_58 = 0;
            do {
              (**(code **)(param_1 + 0x1344))(local_6c,pvVar13,uVar17);
              local_6c = (void *)((int)local_6c + uVar17);
              local_58 = local_58 + 1;
            } while (iVar9 != local_58);
          }
        }
        uVar22 = uVar22 >> 1;
        local_30 = local_30 + 1;
      } while (local_30 != 0x10);
      iVar9 = *(int *)(local_b4 + 0xbc);
    }
    local_44 = *(void **)(iVar9 + 0x80);
    if (1 < uVar8) {
      local_44 = (void *)((int)local_44 + *(int *)(iVar9 + 0x84) * 2);
    }
    if (local_b4[0x2a] == '\0') {
      if (1 < uVar8) {
        _memset(local_44,0xff,*(size_t *)(iVar9 + 0x84));
      }
    }
    else {
      local_50 = *(uint *)(local_b4 + 0xac);
      local_4c = *(uint *)(local_b4 + 0xb0);
      uVar8 = (uint)*(ushort *)(iVar9 + 0x3a);
      iVar27 = (int)uVar8 >> 5;
      iVar9 = (int)(uint)*(ushort *)(iVar9 + 0x3c) >> 5;
      local_34 = 0x20;
      do {
        local_40 = 0;
        local_cc = 0;
        do {
          uVar17 = *(uint *)(local_b4 + (0x1f - local_4c) * 4 + 0x2c);
          iVar10 = local_cc + (int)local_44;
          if (iVar9 != 0) {
            iVar15 = 0;
            do {
              if (iVar27 != 0) {
                iVar14 = 0;
                do {
                  *(char *)(iVar10 + iVar14) =
                       ~-(((uVar17 >> 0x18 | (uVar17 & 0xff0000) >> 8 | (uVar17 & 0xff00) << 8 |
                           uVar17 << 0x18) & 1 << ((byte)local_50 & 0x1f)) == 0);
                  iVar14 = iVar14 + 1;
                } while (iVar27 != iVar14);
              }
              iVar10 = iVar10 + uVar8;
              iVar15 = iVar15 + 1;
            } while (iVar9 != iVar15);
          }
          local_50 = local_50 + 1 & 0x1f;
          local_40 = local_40 + 1;
          local_cc = local_cc + iVar27;
        } while (local_40 != 0x20);
        local_44 = (void *)((int)local_44 + uVar8 * iVar9);
        local_4c = local_4c + 1 & 0x1f;
        local_34 = local_34 + -1;
      } while (local_34 != 0);
    }
    iVar9 = FUN_000326f2(param_1,*(undefined4 *)(*(int *)(local_b4 + 0xbc) + 0x7c),
                         *(undefined4 *)(param_1 + 0x276c));
    if (iVar9 != 0) {
      bVar1 = *(byte *)(*(int *)(local_b4 + 0xbc) + 0x31);
      uVar8 = (uint)bVar1;
      iVar9 = (bVar1 != 2) + 1;
      local_b4[0xd0] = '\0';
      local_b4[0xd1] = '\0';
      local_b4[0xd2] = '\0';
      local_b4[0xd3] = '\0';
      local_b4[0xf8] = '\0';
      local_b4[0xf9] = '\0';
      local_b4[0xfa] = '\0';
      local_b4[0xfb] = '\0';
      if ((*local_b4 == '\0') && (bVar1 != 3)) {
        local_b4[0xc0] = '\0';
        local_b4[0xc1] = '\0';
        local_b4[0xc2] = '\0';
        local_b4[0xc3] = '\0';
        local_b4[0xe8] = '\0';
        local_b4[0xe9] = '\0';
        local_b4[0xea] = '\0';
        local_b4[0xeb] = '\0';
      }
      else {
        local_b4[0xc0] = '\x02';
        local_b4[0xc1] = '\0';
        local_b4[0xc2] = '\0';
        local_b4[0xc3] = '\0';
        local_b4[0xe8] = '\x01';
        local_b4[0xe9] = '\0';
        local_b4[0xea] = '\0';
        local_b4[0xeb] = '\0';
        if ((*(int *)(local_b4 + 0xb4) == 0x1b00) || (*(int *)(local_b4 + 0xb8) == 0x1b00)) {
          *(uint *)(local_b4 + 0xd0) = uVar8;
          *(int *)(local_b4 + 0xf8) = iVar9;
        }
      }
      if ((*(short *)(local_b4 + 0x14) == 0) && (bVar1 != 3)) {
        local_b4[0xc4] = '\0';
        local_b4[0xc5] = '\0';
        local_b4[0xc6] = '\0';
        local_b4[199] = '\0';
        local_b4[0xec] = '\0';
        local_b4[0xed] = '\0';
        local_b4[0xee] = '\0';
        local_b4[0xef] = '\0';
      }
      else {
        *(uint *)(local_b4 + 0xc4) = uVar8;
        *(int *)(local_b4 + 0xec) = iVar9;
        if ((*(int *)(local_b4 + 0xb4) == 0x1b01) || (*(int *)(local_b4 + 0xb8) == 0x1b01)) {
          *(uint *)(local_b4 + 0xd0) = uVar8;
          *(int *)(local_b4 + 0xf8) = iVar9;
        }
      }
      if ((local_b4[0x2a] != '\0') || (bVar1 == 3)) {
        *(uint *)(local_b4 + 0xd0) = uVar8;
        *(int *)(local_b4 + 0xf8) = iVar9;
      }
      *(undefined4 *)(local_b4 + 200) = *(undefined4 *)(local_b4 + 0xc4);
      *(undefined4 *)(local_b4 + 0xf0) = *(undefined4 *)(local_b4 + 0xec);
      *(undefined4 *)(local_b4 + 0xcc) = *(undefined4 *)(local_b4 + 0xc4);
      *(undefined4 *)(local_b4 + 0xf4) = *(undefined4 *)(local_b4 + 0xec);
      uVar11 = *(undefined4 *)(local_b4 + 0xd0);
      *(undefined4 *)(local_b4 + 0xd4) = uVar11;
      uVar12 = *(undefined4 *)(local_b4 + 0xf8);
      *(undefined4 *)(local_b4 + 0xfc) = uVar12;
      *(undefined4 *)(local_b4 + 0xd8) = uVar11;
      *(undefined4 *)(local_b4 + 0x100) = uVar12;
      *(undefined4 *)(local_b4 + 0xdc) = uVar11;
      *(undefined4 *)(local_b4 + 0x104) = uVar12;
      *(undefined4 *)(local_b4 + 0xe0) = uVar11;
      *(undefined4 *)(local_b4 + 0x108) = uVar12;
      *(undefined4 *)(local_b4 + 0xe4) = uVar11;
      *(undefined4 *)(local_b4 + 0x10c) = uVar12;
      local_b4[0x110] = local_b4[0x110] & 0xef;
      local_b4[0x114] = local_b4[0x114] & 0xefU | (*(short *)(local_b4 + 0x14) != 0) << 4;
      *(undefined4 *)(local_b4 + 0x118) = *(undefined4 *)(local_b4 + 0x114);
      *(undefined4 *)(local_b4 + 0x11c) = *(undefined4 *)(local_b4 + 0x114);
      local_b4[0x120] = local_b4[0x120] & 0xefU | (local_b4[0x2a] != '\0') << 4;
      uVar11 = *(undefined4 *)(local_b4 + 0x120);
      *(undefined4 *)(local_b4 + 0x124) = uVar11;
      *(undefined4 *)(local_b4 + 0x128) = uVar11;
      *(undefined4 *)(local_b4 + 300) = uVar11;
      *(undefined4 *)(local_b4 + 0x130) = uVar11;
      *(undefined4 *)(local_b4 + 0x134) = uVar11;
      *(undefined4 *)(local_b4 + 0x138) = *(undefined4 *)(param_1 + 0x2764);
      *(undefined4 *)(param_1 + 0x2764) = local_b4;
      *(int *)(param_1 + 0x2778) = *(int *)(param_1 + 0x2778) + 1;
LAB_000a3e64:
      *(char **)(param_1 + 0x2768) = local_b4;
      ((int (*)())FUN_000a2b94)(param_1);
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x200;
      *(ushort *)(param_1 + 0x34) =
           *(ushort *)(param_1 + 0x34) |
           (ushort)(1 << ((byte)*(undefined4 *)(param_1 + 0x276c) & 0x1f));
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(undefined4 *)(param_1 + 0x277c) = 0xffffffff;
      return 0;
    }
    _free(local_b4);
  }
LAB_000a307d:
  ((int (*)())FUN_000a2a5b)();
  return 1;
}

/* FUN_000a4262 @ 0xa4262 (511 bytes) */
int FUN_000a4262(param_1)
  int param_1;
{
  int iVar1;
  uint *puVar2;
  undefined4 *puVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  fVar4 = *(float *)(iVar1 + 0x2da8) * FLOAT_001c5bb8;
  if (fVar4 <= 0.0) {
    fVar4 = 0.0;
  }
  fVar5 = *(float *)(iVar1 + 0x2dac) * FLOAT_001c5bb8;
  if (fVar5 <= 0.0) {
    fVar5 = 0.0;
  }
  fVar6 = *(float *)(iVar1 + 0x2da0) * FLOAT_001c5bb8;
  if (fVar6 <= 0.0) {
    fVar6 = 0.0;
  }
  fVar7 = FLOAT_001c5bb8 * *(float *)(iVar1 + 0x2da4);
  if (fVar7 <= 0.0) {
    fVar7 = 0.0;
  }
  *(uint *)(param_1 + 0x1a94) =
       ((int)(fVar5 - (float)(-(uint)(DAT_001c6460 <= fVar5) & (uint)DAT_001c6460)) |
       -(uint)(DAT_001c6470 <= fVar5)) << 0x18 |
       ((int)(fVar6 - (float)(-(uint)(DAT_001c6460 <= fVar6) & (uint)DAT_001c6460)) |
       -(uint)(DAT_001c6470 <= fVar6)) << 0x10 |
       ((int)(fVar7 - (float)((uint)DAT_001c6460 & -(uint)(DAT_001c6460 <= fVar7))) |
       -(uint)(DAT_001c6470 <= fVar7)) << 8 |
       (int)(fVar4 - (float)(-(uint)(DAT_001c6460 <= fVar4) & (uint)DAT_001c6460)) +
       (uint)(DAT_001c6460 <= fVar4) * -0x80000000 | -(uint)(DAT_001c6470 <= fVar4);
  puVar3 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0xd);
  *(undefined4 **)(param_1 + 0x274c) = puVar3;
  iVar1 = *(int *)(param_1 + 4);
  puVar2 = *(uint **)(iVar1 + 0x1d8);
  *puVar2 = *puVar2 | (int)puVar3 - (int)puVar2 >> 2;
  *(undefined4 **)(iVar1 + 0x1d8) = puVar3;
  *puVar3 = 0x4000000;
  puVar3[3] = 0x1393;
  puVar3[4] = 10;
  puVar3[5] = 0x1385;
  puVar3[6] = *(undefined4 *)(param_1 + 0x1a94);
  puVar3[7] = 0xc0023800;
  puVar3[8] = 0;
  puVar3[9] = 0;
  puVar3[10] = 0;
  puVar3[0xb] = 0x1380;
  puVar3[0xc] = 0;
  *(undefined4 **)(param_1 + 0x274c) = puVar3 + 0xd;
                    
                    
  (**(code **)(param_1 + 0x275c))();
  return;
}

/* FUN_000a4461 @ 0xa4461 (651 bytes) */
int FUN_000a4461(param_1)
  int param_1;
{
  int iVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  byte bVar8;
  byte local_20;
  byte local_1c;
  byte local_18;
  
  iVar4 = *(int *)(param_1 + 0x1a60);
  bVar2 = *(byte *)(param_1 + 0x1a4e);
  *(byte *)(param_1 + 0x1a4e) = bVar2 & 0xfe;
  *(undefined4 *)(param_1 + 0x1a60) = 0;
  iVar6 = *(int *)(param_1 + 4);
  if (*(int *)(iVar6 + 0x2a50) == 1) {
    bVar3 = *(byte *)(param_1 + 0x44);
    if ((bVar3 & 8) == 0) {
      *(undefined4 *)(param_1 + 0x1a68) = 0x66666666;
      *(undefined4 *)(param_1 + 0x1a6c) = 0x6666666;
      *(undefined4 *)(param_1 + 0x1b60) = 0xffffff;
      goto LAB_000a4571;
    }
  }
  else {
    bVar3 = *(byte *)(param_1 + 0x44);
  }
  iVar1 = (*(int *)(iVar6 + 0x2a50) >> 1) + -1;
  *(byte *)(param_1 + 0x2354) = *(byte *)(param_1 + 0x2354) & 0xfe;
  bVar8 = bVar2 & 0xfc | (iVar1 == 2) * '\x02';
  *(byte *)(param_1 + 0x1a4e) = bVar8;
  bVar2 = *(byte *)(param_1 + 0x1a60);
  *(byte *)(param_1 + 0x1a60) = bVar2 | 1;
  *(byte *)(param_1 + 0x1a60) = bVar2 & 0xf9 | 1 | ((DAT_001c6448)[iVar1 * 4] & 3) * '\x02';
  *(undefined4 *)(param_1 + 0x1a68) = *(undefined4 *)(&DAT_001c643c + iVar1 * 4);
  *(undefined4 *)(param_1 + 0x1a6c) = *(undefined4 *)(&DAT_001c6430 + iVar1 * 4);
  if ((bVar3 & 8) == 0) {
    iVar6 = *(int *)(iVar6 + 0x2a50);
LAB_000a454c:
    uVar5 = (1 << ((byte)iVar6 & 0x1f)) - 1;
    uVar5 = uVar5 * 0x40000 | uVar5 * 0x1000 | uVar5 * 0x40 | uVar5;
  }
  else {
    *(byte *)(param_1 + 0x1a4e) = bVar8 | bVar3 >> 4 & 1;
    iVar6 = *(int *)(iVar6 + 0x2a50);
    if ((bVar3 >> 6 & 1) == 0) goto LAB_000a454c;
    uVar5 = (uint)(*(float *)(param_1 + 0x438) * FLOAT_001c5bcc * (float)iVar6 + FLOAT_001c5bd4);
    uVar7 = uVar5 & 3;
    bVar2 = (byte)((int)uVar5 >> 2);
    local_20 = (uVar7 != 0) + bVar2;
    local_1c = (2 < uVar7) + bVar2;
    local_18 = (1 < uVar7) + bVar2;
    if (*(char *)(param_1 + 0x43c) == '\0') {
      uVar5 = 0;
    }
    else {
      uVar5 = (1 << ((byte)iVar6 & 0x1f)) - 1;
    }
    uVar5 = (1 << (local_20 & 0x1f)) - 1U ^ uVar5 |
            ((1 << (bVar2 & 0x1f)) - 1U ^ uVar5) << 0x12 |
            ((1 << (local_18 & 0x1f)) - 1U ^ uVar5) << 0xc |
            (uVar5 ^ (1 << (local_1c & 0x1f)) - 1U) << 6;
  }
  *(uint *)(param_1 + 0x1b60) = uVar5;
LAB_000a4571:
  uVar5 = *(uint *)(param_1 + 0x1930);
  *(uint *)(param_1 + 0x1930) = uVar5 | 0x80200;
  if (iVar4 != *(int *)(param_1 + 0x1a60)) {
    *(uint *)(param_1 + 0x1930) = uVar5 | 0x2080340;
  }
  return;
}

/* FUN_000a46ec @ 0xa46ec (845 bytes) */
int FUN_000a46ec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  undefined4 param_3;
{
  byte *pbVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  FUN_00082663(param_1,param_3);
  *(undefined4 *)(param_1 + 0x1b74) = 0;
  *(byte *)(param_1 + 0x1b76) = *(byte *)(param_1 + 0x1b76) | 1;
  *(byte *)(param_1 + 0x1b75) = *(byte *)(param_1 + 0x1b75) | 0xc0;
  *(undefined4 *)(param_1 + 0x1b84) = 0;
  *(undefined4 *)(param_1 + 0x1b9c) = 3;
  *(undefined4 *)(param_1 + 0x1ba0) = 3;
  *(undefined4 *)(param_1 + 0x248c) = 8;
  *(undefined4 *)(param_1 + 0x1b50) = 0;
  *(undefined4 *)(param_1 + 0x1b30) = 0;
  *(undefined4 *)(param_1 + 0x1b60) = 0xffffff;
  if ((param_2 & 1) == 0) {
    *(undefined4 *)(param_1 + 0x1ab8) = 1;
    *(undefined4 *)(param_1 + 0x1a50) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x1ab8) = 0;
  }
  if ((param_2 & 0x1000) != 0) {
    *(undefined4 *)(param_1 + 0x1aec) = 0;
  }
  **(undefined4 **)(param_1 + 0x2440) = 0;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xfffffff0 | 3;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xffffff0f;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xffffe0ff;
  pbVar1 = (byte *)(*(int *)(param_1 + 0x2440) + 1);
  *pbVar1 = *pbVar1 & 0xdf;
  pbVar1 = (byte *)(*(int *)(param_1 + 0x2440) + 1);
  *pbVar1 = *pbVar1 & 0xbf;
  pbVar1 = (byte *)(*(int *)(param_1 + 0x2440) + 1);
  *pbVar1 = *pbVar1 & 0x7f;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xfff0ffff | 0x30000;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xff0fffff;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xe0ffffff | 0x1000000;
  pbVar1 = (byte *)(*(int *)(param_1 + 0x2440) + 3);
  *pbVar1 = *pbVar1 | 0x20;
  pbVar1 = (byte *)(*(int *)(param_1 + 0x2440) + 3);
  *pbVar1 = *pbVar1 & 0xbf;
  pbVar1 = (byte *)(*(int *)(param_1 + 0x2440) + 3);
  *pbVar1 = *pbVar1 & 0x7f;
  **(undefined4 **)(param_1 + 0x2444) = 0;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xfffffff8;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xffffffc7 | 8;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xfffffe3f | 0x80;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xfffff1ff | 0x600;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) | 0xf000;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xfff8ffff;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xffc7ffff | 0x80000;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xfe3fffff | 0x800000;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xf1ffffff | 0x6000000;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) | 0xf0000000;
  puVar2 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0x20);
  *(undefined4 **)(param_1 + 0x274c) = puVar2;
  *puVar2 = 0x887;
  puVar2[1] = *(undefined4 *)(param_1 + 0x1b74);
  puVar2[2] = 0x82c;
  puVar2[3] = *(undefined4 *)(param_1 + 0x1b84);
  puVar2[4] = 0x10ae;
  puVar2[5] = *(undefined4 *)(param_1 + 0x1b30);
  puVar2[6] = 0x1002;
  puVar2[7] = *(undefined4 *)(param_1 + 0x1b50);
  puVar2[8] = 0x824;
  puVar2[9] = *(undefined4 *)(param_1 + 0x1b9c);
  puVar2[10] = 0x825;
  puVar2[0xb] = *(undefined4 *)(param_1 + 0x1ba0);
  puVar2[0xc] = 0x82d;
  puVar2[0xd] = *(undefined4 *)(param_1 + 0x248c);
  puVar2[0xe] = 0x854;
  puVar2[0xf] = **(undefined4 **)(param_1 + 0x2440);
  puVar2[0x10] = 0x878;
  puVar2[0x11] = **(undefined4 **)(param_1 + 0x2444);
  puVar2[0x12] = 0x12f0;
  puVar2[0x13] = *(undefined4 *)(param_1 + 0x1aec);
  puVar2[0x14] = 0x12f6;
  puVar2[0x15] = *(undefined4 *)(param_1 + 0x1a50);
  puVar2[0x16] = 0x10fa;
  puVar2[0x17] = *(undefined4 *)(param_1 + 0x1b60);
  puVar2[0x18] = 0x13c5;
  puVar2[0x19] = *(undefined4 *)(param_1 + 0x1ab8);
  puVar3 = puVar2 + 0x1a;
  if ((*(byte *)(param_1 + 0x2454) & 0x10) != 0) {
    puVar2[0x1a] = 0x13c5;
    puVar2[0x1b] = *(undefined4 *)(param_1 + 0x1ab8);
    puVar3 = puVar2 + 0x1c;
  }
  *puVar3 = 0x1048;
  puVar3[1] = *(undefined4 *)(param_1 + 0x1bc0);
  puVar3[2] = 0x1047;
  puVar3[3] = *(undefined4 *)(param_1 + 0x1bb0);
  *(undefined4 **)(param_1 + 0x274c) = puVar3 + 4;
                    
                    
  (**(code **)(param_1 + 0x275c))();
  return;
}

/* FUN_000a4a39 @ 0xa4a39 (32 bytes) */
int FUN_000a4a39(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x150);
  iVar2 = *(int *)(param_1 + 4) + 0x30;
  if (iVar1 != 0) {
    iVar2 = iVar1;
  }
  *(undefined1 *)(iVar2 + 0xc5) = 1;
  return;
}

/* FUN_000a4a59 @ 0xa4a59 (905 bytes) */
int FUN_000a4a59(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  uint *puVar3;
  char cVar4;
  uint uVar5;
  undefined4 *puVar6;
  byte bVar7;
  byte bVar8;
  undefined4 *puVar9;
  uint uVar10;
  uint local_60;
  uint local_24;
  uint local_20;
  uint local_1c;
  undefined4 *local_18;
  
  iVar1 = *(int *)(param_1 + 4);
  iVar2 = *(int *)(iVar1 + 0x10);
  local_60 = FUN_0004d60c(param_1);
  uVar5 = *(uint *)(iVar1 + 0x154) & 0x30000;
  if ((uVar5 == 0x20000) || (uVar5 == 0x30000)) {
    cVar4 = '\x18';
LAB_000a4ab5:
    *(uint *)(param_1 + 0x1ae4) = local_60 << 8;
  }
  else {
    if (uVar5 != 0x10000) {
      cVar4 = '\0';
      goto LAB_000a4ab5;
    }
    *(uint *)(param_1 + 0x1ae4) = local_60 << 0x10 | local_60;
    cVar4 = '\x10';
  }
  *(uint *)(param_1 + 0x1ae4) = *(uint *)(param_1 + 0x1ae4) | *(uint *)(iVar2 + 0x2db4);
  puVar6 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0x1a);
  *(undefined4 **)(param_1 + 0x274c) = puVar6;
  puVar3 = *(uint **)(iVar1 + 0x1d8);
  *puVar3 = *puVar3 | (int)puVar6 - (int)puVar3 >> 2;
  *(undefined4 **)(iVar1 + 0x1d8) = puVar6;
  *puVar6 = 0x5000000;
  puVar6[1] = (uint)param_2;
  puVar6[2] = 0;
  puVar6[3] = 0;
  puVar6[4] = 0;
  puVar6[5] = 0;
  puVar6[6] = 0x13c6;
  puVar6[7] = 3;
  puVar6[8] = 0xc0023200;
  puVar6[9] = 0;
  puVar6[10] = 0;
  puVar6[0xb] = 0;
  local_18 = puVar6 + 0xc;
  if (param_2 == 0) goto LAB_000a4c4f;
  if (*(char *)(param_1 + 0x2451) == '\0') {
    local_60 = local_60 >> (cVar4 - 8U & 0x1f);
    local_60 = local_60 << 0x18 | local_60 << 0x10 | local_60 << 8 | local_60;
  }
  else if (local_60 < 0xffffff) {
    if (local_60 == 0) {
      local_60 = 0;
    }
    else {
      bVar7 = *(byte *)(param_1 + 0x1ab1) >> 4 & 7;
      local_24 = (1 << bVar7) - 1;
      bVar8 = cVar4 - 1;
      if ((char)*(byte *)(param_1 + 0x1ab1) < '\0') {
        uVar5 = local_60 * local_24;
        if ((1 << (bVar8 & 0x1f) & uVar5) == 0) {
          local_1c = 0;
          do {
            local_1c = local_1c + 1;
            bVar8 = bVar8 - 1;
          } while ((uVar5 & 1 << (bVar8 & 0x1f)) == 0);
        }
        else {
          local_1c = 0;
        }
        if (local_1c < local_24) {
          uVar5 = uVar5 * 2;
          local_24 = local_1c;
        }
        else {
LAB_000a4dc2:
          uVar5 = local_60 * local_24;
        }
      }
      else {
        uVar5 = local_60 * local_24;
        if ((1 << (bVar8 & 0x1f) & uVar5) == 0) {
          local_20 = 0;
        }
        else {
          local_20 = 0;
          do {
            local_20 = local_20 + 1;
            bVar8 = bVar8 - 1;
          } while ((uVar5 & 1 << (bVar8 & 0x1f)) != 0);
        }
        if (local_24 <= local_20) goto LAB_000a4dc2;
        uVar5 = uVar5 * 2;
        local_24 = local_20;
      }
      uVar10 = (uVar5 & ~((1 << ((byte)local_24 & 0x1f)) + -1 << (cVar4 - (byte)local_24 & 0x1f)))
               >> ((bVar7 - 8) + (cVar4 - (byte)local_24) & 0x1f) | local_24 << (8 - bVar7 & 0x1f);
      uVar5 = uVar10 & 0xff;
      local_60 = uVar5 << 8 | uVar5 | uVar5 << 0x10 | uVar10 << 0x18;
    }
  }
  else {
    local_60 = 0xffffffff;
  }
  uVar5 = *(uint *)(param_1 + 0x1ab8) | 1;
  *local_18 = 0x13c5;
  puVar6[0xd] = uVar5;
  puVar9 = puVar6 + 0xe;
  if ((*(byte *)(param_1 + 0x2454) & 0x10) != 0) {
    puVar6[0xe] = 0x13c5;
    puVar6[0xf] = uVar5;
    puVar9 = puVar6 + 0x10;
  }
  puVar6[2] = (int)puVar9 - (int)puVar6 >> 2;
  *puVar9 = 0xc0023700;
  puVar9[1] = 0;
  puVar9[2] = 0;
  puVar9[3] = local_60;
  puVar9[4] = 0x13c5;
  puVar9[5] = *(undefined4 *)(param_1 + 0x1ab8);
  local_18 = puVar9 + 6;
  if ((*(byte *)(param_1 + 0x2454) & 0x10) != 0) {
    puVar9[6] = 0x13c5;
    puVar9[7] = *(undefined4 *)(param_1 + 0x1ab8);
    local_18 = puVar9 + 8;
  }
LAB_000a4c4f:
  puVar6[3] = (int)local_18 + (4 - (int)puVar6) >> 2;
  *local_18 = 0x13ca;
  local_18[1] = *(undefined4 *)(param_1 + 0x1ae4);
  *(undefined4 **)(param_1 + 0x274c) = local_18 + 2;
                    
                    
  (**(code **)(param_1 + 0x275c))();
  return;
}

/* FUN_000a4de2 @ 0xa4de2 (693 bytes) */
int FUN_000a4de2(param_1, param_2)
  int param_1;
  uint param_2;
{
  double dVar1;
  uint uVar2;
  float fVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  undefined4 local_b0;
  undefined1 local_a8 [152];
  
  fVar6 = (float)(*(int *)(param_1 + 0x1358) - *(int *)(param_1 + 0x13d8));
  fVar7 = (float)(*(int *)(param_1 + 0x1360) - *(int *)(param_1 + 0x13d8));
  fVar8 = (float)(*(int *)(param_1 + 0x135c) - *(int *)(param_1 + 0x13dc));
  fVar9 = (float)(*(int *)(param_1 + 0x1364) - *(int *)(param_1 + 0x13dc));
  dVar1 = *(double *)(*(int *)(*(int *)(param_1 + 4) + 0x10) + 0x2d88);
  if (((param_2 & 0x400) == 0) || (*(char *)(param_1 + 0x1491) == '\0')) {
    local_b0 = 0;
  }
  else {
    local_b0 = 1;
  }
  if (((param_2 & 0x100) == 0) || (*(char *)(param_1 + 0x1490) == '\0')) {
    uVar5 = 0;
  }
  else {
    uVar5 = 1;
  }
  FUN_000827ac(param_1,0,uVar5,local_b0,local_a8);
  puVar4 = (undefined4 *)
           (**(code **)(param_1 + 0x2758))
                     (param_1,(-(*(char *)(param_1 + 0x2802) == '\0') & 2U) + 0x23);
  *(undefined4 **)(param_1 + 0x274c) = puVar4;
  if (*(char *)(param_1 + 0x2802) == '\0') {
    *puVar4 = 0x5c8;
    puVar4[1] = 0x10000000;
    puVar4 = puVar4 + 2;
    *(undefined1 *)(param_1 + 0x2802) = 1;
  }
  puVar4 = (undefined4 *)FUN_0007edb0(param_1,puVar4);
  *(undefined4 **)(param_1 + 0x2794) = puVar4;
  fVar3 = FLOAT_001c5bd4;
  uVar2 = *(uint *)(param_1 + 8);
  fVar10 = *(float *)(param_1 + 0x2818) * FLOAT_001c5bd4;
  fVar11 = *(float *)(param_1 + 0x2814) * FLOAT_001c5bd4;
  *puVar4 = 0x1087;
  puVar4[1] = (int)(fVar10 * (float)uVar2 * (fVar9 - fVar8)) & 0xffffU |
              (int)((float)uVar2 * fVar11 * (fVar7 - fVar6)) << 0x10;
  puVar4[2] = 0x82c;
  puVar4[3] = *(undefined4 *)(param_1 + 0x1b84);
  puVar4[4] = 0xc0083500;
  puVar4[5] = ((unsigned char *)0x00010031);
  puVar4[6] = (fVar6 + fVar7) * fVar3;
  puVar4[7] = fVar3 * (fVar8 + fVar9);
  puVar4[8] = (float)dVar1;
  puVar4[9] = 0x3f800000;
  puVar4[10] = 0x3dcccccd;
  puVar4[0xb] = 0x3e4ccccd;
  puVar4[0xc] = 0x3e99999a;
  puVar4[0xd] = 0x3ecccccd;
  puVar4[0xe] = 0x1087;
  puVar4[0xf] = *(undefined4 *)(param_1 + 0x1ccc);
  *(undefined4 **)(param_1 + 0x274c) = puVar4 + 0x10;
  (**(code **)(param_1 + 0x275c))(param_1,puVar4 + 0x10);
  FUN_0009b2d9(param_1);
  FUN_00082e73(param_1,local_a8);
  return;
}

/* FUN_000a5097 @ 0xa5097 (619 bytes) */
int FUN_000a5097(param_1, param_2)
  int param_1;
  uint param_2;
{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  char cVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  uint local_14;
  undefined4 local_10;
  
  iVar2 = *(int *)(param_1 + 4);
  cVar1 = *(char *)(*(int *)(iVar2 + 0x10) + 0x3190);
  cVar5 = cVar1;
  if (cVar1 != '\0') {
    if ((((*(int *)(param_1 + 0x440) == 0) && (*(int *)(param_1 + 0x444) == 0)) &&
        (*(int *)(iVar2 + 0x160) == *(int *)(param_1 + 0x44c))) &&
       (cVar5 = '\0', *(int *)(iVar2 + 0x15c) != *(int *)(param_1 + 0x448))) {
      cVar5 = cVar1;
    }
  }
  uVar3 = *(uint *)(iVar2 + 0x154);
  iVar7 = iVar2 + 0x30;
  if (*(int *)(iVar2 + 0x150) != 0) {
    iVar7 = *(int *)(iVar2 + 0x150);
  }
  if ((uVar3 & 0x40) == 0) {
    uVar8 = param_2 >> 8 & 1;
LAB_000a5105:
    if ((uVar3 & 0x80) == 0) {
      local_14 = param_2 >> 10 & 1;
LAB_000a511c:
      if (cVar5 == '\0') {
        if (uVar8 == 0) {
LAB_000a5290:
          local_10 = 0;
        }
        else {
          if (((*(char *)(param_1 + 0x247c) == '\0') || ((uVar3 & 0x40) == 0)) ||
             (((uVar3 & 0x30000) == 0x10000 && ((uVar3 & 0x1000) != 0)))) {
            *(undefined1 *)(iVar7 + 0xc5) = 1;
            goto LAB_000a5290;
          }
          *(undefined1 *)(iVar7 + 0xc5) = 0;
          *(undefined1 *)(iVar7 + 0xc4) = 1;
          local_10 = 1;
        }
        iVar7 = (**(code **)(param_1 + 0x2758))(param_1,3000);
        *(int *)(param_1 + 0x274c) = iVar7;
        (**(code **)(param_1 + 0x275c))(param_1,iVar7);
        iVar2 = *(int *)(param_1 + 0x274c);
        ((int (*)())FUN_000a4a59)(param_1,local_10);
        *(int *)(iVar7 + 0x10) = *(int *)(param_1 + 0x274c) - iVar2 >> 2;
        ((int (*)())FUN_000a4de2)();
        *(int *)(iVar7 + 0x14) = *(int *)(param_1 + 0x2794) - iVar2 >> 2;
        goto LAB_000a5194;
      }
    }
    else {
      local_14 = param_2 >> 10 & 1;
      if ((local_14 != 0) || ((*(byte *)(param_1 + 0x8c) & 4) == 0)) goto LAB_000a511c;
    }
    if (uVar8 != 0) {
      *(undefined1 *)(iVar7 + 0xc5) = 1;
    }
  }
  else {
    uVar8 = param_2 >> 8 & 1;
    if (uVar8 != 0) goto LAB_000a5105;
  }
  ((int (*)())FUN_000a4de2)();
  local_14 = param_2 >> 10 & 1;
LAB_000a5194:
  if (local_14 != 0) {
    *(byte *)(param_1 + 0x8c) = *(byte *)(param_1 + 0x8c) | 4;
  }
  iVar2 = *(int *)(param_1 + 4);
  FUN_0004bb08(param_1);
  puVar6 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,5);
  *(undefined4 **)(param_1 + 0x274c) = puVar6;
  puVar4 = *(uint **)(iVar2 + 0x1d8);
  *puVar4 = *puVar4 | (int)puVar6 - (int)puVar4 >> 2;
  *(undefined4 **)(iVar2 + 0x1d8) = puVar6;
  *puVar6 = 0x2f000000;
  puVar6[1] = 0x10e9;
  puVar6[2] = *(undefined4 *)(param_1 + 0x1ae0);
  puVar6[3] = 0x13c7;
  puVar6[4] = *(undefined4 *)(param_1 + 0x1ab0);
  *(undefined4 **)(param_1 + 0x274c) = puVar6 + 5;
                    
                    
  (**(code **)(param_1 + 0x275c))();
  return;
}

/* FUN_000a5302 @ 0xa5302 (27 bytes) */
int FUN_000a5302(param_1)
  size_t param_1;
{
  _calloc(param_1,1);
  return;
}

/* FUN_000a531d @ 0xa531d (5 bytes) */
int FUN_000a531d()
{
  return;
}

/* FUN_000a5322 @ 0xa5322 (133 bytes) */
int FUN_000a5322(param_1, param_2)
  float *param_1;
  float *param_2;
{
  float fVar1;
  float fVar2;
  
  fVar1 = *param_2;
  fVar2 = fVar1 * fVar1 + param_2[1] * param_2[1] + param_2[2] * param_2[2];
  if (0.0 < fVar2) {
    fVar2 = (float)(DOUBLE_001cf330 / SQRT((double)fVar2));
    *param_1 = fVar1 * fVar2;
    param_1[1] = fVar2 * param_2[1];
    param_1[2] = fVar2 * param_2[2];
    return;
  }
  *param_1 = 0.0;
  param_1[1] = 0.0;
  param_1[2] = 0.0;
  return;
}

/* FUN_000a53a7 @ 0xa53a7 (2440 bytes) */
int FUN_000a53a7(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = param_1 + 0x240;
  *(int *)(param_1 + 0x244) = param_1;
  *(int *)(param_1 + 0x25c) = iVar6;
  *(code **)(param_1 + 0x24c) = FUN_000a5302;
  *(undefined **)(param_1 + 0x250) = PTR_0021340d;
  *(undefined **)(param_1 + 0x254) = PTR_00213351;
  *(undefined **)(param_1 + 600) = PTR_00213335;
  *(undefined **)(param_1 + 0x1584) = PTR_0021339d;
  *(undefined1 *)(param_1 + 0x26b) = 0;
  *(undefined4 *)(param_1 + 0x145c) = 0;
  *(undefined **)(param_1 + 0x2998) = PTR_FUN_002133a9;
  *(undefined **)(param_1 + 0x299c) = PTR_LAB_002133a1;
  *(undefined **)(param_1 + 0x14c0) = PTR_LAB_0004ca47_1_002133c5;
  *(undefined **)(param_1 + 0x14c8) = PTR_FUN_002133d9;
  *(undefined **)(param_1 + 0x14d0) = PTR_FUN_002133b5;
  *(undefined **)(param_1 + 0x14c4) = PTR_FUN_002133e1;
  *(undefined **)(param_1 + 0x14cc) = PTR_FUN_00213325;
  *(undefined **)(param_1 + 0x14d4) = PTR_LAB_00213431;
  *(undefined **)(param_1 + 0x14e8) = PTR_LAB_00061ff6_4_00213341;
  *(undefined **)(param_1 + 0x14d8) = PTR_FUN_00213421;
  *(undefined **)(param_1 + 0x14dc) = PTR_LAB_00213399;
  *(undefined **)(param_1 + 0x14e0) = PTR_FUN_002133f9;
  *(undefined **)(param_1 + 0x14e4) = PTR_LAB_00213311;
  *(undefined **)(param_1 + 0x14ec) = PTR_FUN_00213301;
  *(undefined4 *)(param_1 + 0x1604) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x1608) = 0x42800000;
  *(undefined4 *)(param_1 + 0x1628) = 0x3e000000;
  *(undefined4 *)(param_1 + 0x162c) = 0x42800000;
  *(undefined4 *)(param_1 + 0x1624) = 0x80;
  *(undefined1 *)(param_1 + 0x15f4) = 4;
  *(undefined1 *)(param_1 + 0x15f8) = *(undefined1 *)(param_1 + 0x2b7c);
  *(undefined4 *)(param_1 + 0x1618) = 0;
  *(undefined4 *)(param_1 + 0x161c) = 0;
  *(undefined1 *)(param_1 + 0x15f5) = 8;
  *(undefined1 *)(param_1 + 0x15f7) = 0xc;
  *(undefined4 *)(param_1 + 0x160c) = 0x3e000000;
  *(undefined4 *)(param_1 + 0x1630) = 0x3e000000;
  *(undefined4 *)(param_1 + 0x1610) = 1;
  *(undefined4 *)(param_1 + 0x1614) = 0x40;
  *(undefined4 *)(param_1 + 0x1620) = 1;
  *(undefined2 *)(param_1 + 0x15fe) = 0x100;
  *(undefined1 *)(param_1 + 0x15f3) = 1;
  *(undefined4 *)(param_1 + 0x13f8) = 0xffff;
  *(undefined4 *)(param_1 + 0x13fc) = 0x20;
  *(undefined4 *)(param_1 + 0x1400) = 0xffff;
  *(undefined4 *)(param_1 + 0x1404) = 0xffff;
  *(undefined4 *)(param_1 + 0x1408) = 0xffff;
  uVar1 = ((int (*)())FUN_000a5302)(0xa8);
  *(undefined4 *)(param_1 + 0x13ac) = uVar1;
  *(undefined4 *)(param_1 + 0x16dc) = 0x20;
  uVar1 = (**(code **)(param_1 + 0x24c))(0x90);
  *(undefined4 *)(param_1 + 0x1394) = uVar1;
  *(undefined2 *)(param_1 + 5000) = 6;
  *(undefined2 *)(param_1 + 0x138a) = 8;
  *(undefined1 *)(param_1 + 0x1390) = 2;
  *(undefined2 *)(param_1 + 0x138e) = 8;
  *(undefined2 *)(param_1 + 0x138c) = 0x10;
  uVar1 = (**(code **)(param_1 + 0x24c))(0x14);
  *(undefined4 *)(FUN_0000136c + param_1) = uVar1;
  *(undefined1 *)(param_1 + 0x15f2) = 8;
  *(undefined1 *)(param_1 + 0x15f0) = 8;
  *(undefined1 *)(param_1 + 0x15f1) = 0x10;
  *(undefined1 *)(param_1 + 0x15f6) = 0x10;
  *(undefined4 *)(param_1 + 0x1600) = 3;
  *(undefined4 *)(param_1 + 0x29a8) = 0;
  *(undefined4 *)(param_1 + 0x29a4) = 0;
  *(undefined4 *)(param_1 + 0x29b0) = 0;
  *(undefined4 *)(param_1 + 0x29b4) = 0;
  *(undefined4 *)(param_1 + 0x29ac) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x29b8) = 0;
  *(undefined4 *)(param_1 + 0x29bc) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x248) = 0xc;
  *(undefined1 *)(param_1 + 0x1ef8) = 0xaa;
  *(undefined1 *)(param_1 + 0x1ef9) = 0xaa;
  *(undefined1 *)(param_1 + 0x1efa) = 0xaa;
  *(undefined1 *)(param_1 + 0x1efb) = 0xaa;
  *(undefined1 *)(param_1 + 0x262d) = 0;
  *(undefined1 *)(param_1 + 0x2690) = 0;
  *(undefined4 *)(param_1 + 0x1a48) = 0;
  *(undefined4 *)(param_1 + 0x1b70) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1b74) = 0xffffffff;
  *(byte *)(param_1 + 0x2cc) = *(byte *)(param_1 + 0x2cc) & 3 | 2;
  *(byte *)(param_1 + 0x2cd) = *(byte *)(param_1 + 0x2cd) & 0xf4 | 4;
  *(undefined4 *)(param_1 + 0x2d4) = 0;
  iVar5 = 0x10;
  iVar2 = iVar6;
  do {
    *(undefined4 *)(iVar2 + 0x98) = 0;
    iVar2 = iVar2 + 4;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  *(undefined1 *)(param_1 + 0x2d0) = 0;
  *(undefined1 *)(param_1 + 0x2d1) = 0;
  *(byte *)(param_1 + 0x2cd) = *(byte *)(param_1 + 0x2cd) & 0xaf;
  *(byte *)(param_1 + 0x1ae4) = *(byte *)(param_1 + 0x1ae4) & 0xef;
  *(byte *)(param_1 + 0x16d0) = (byte)(*(uint *)(param_1 + 0x154) >> 6) & 1;
  *(byte *)(param_1 + 0x16d1) = (byte)(*(uint *)(param_1 + 0x154) >> 7) & 1;
  *(byte *)(param_1 + 0x285) = *(byte *)(param_1 + 0x285) & 0x41;
  *(byte *)(param_1 + 0x286) = *(byte *)(param_1 + 0x286) & 4;
  *(undefined1 *)(*(int *)(param_1 + 0x244) + 0xf6) = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x244) + 0xf4) = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x244) + 0xf5) = 1;
  *(undefined1 *)(param_1 + 0x269) = 0;
  *(undefined4 *)(param_1 + 0x2694) = 0;
  *(undefined4 *)(param_1 + 0x2168) = 0x101d;
  *(undefined4 *)(param_1 + 0x1634) = 0x100;
  *(undefined4 *)(param_1 + 0x2688) = 0x200;
  *(undefined4 *)(param_1 + 0x1e20) = 0x400;
  *(undefined4 *)(param_1 + 0x268c) = 0x406;
  uVar3 = *(uint *)(*(int *)(param_1 + 0x244) + 0x24) & 0x7ff00000;
  if ((((uVar3 == 0x800000) || (uVar3 == 0x100000)) || (uVar3 == 0x200000)) || (uVar3 == 0x400000))
  {
    *(undefined4 *)(param_1 + 0x1634) = 0x400;
    *(undefined4 *)(param_1 + 0x2688) = 0x400;
    *(undefined4 *)(param_1 + 0x1e20) = 0x600;
    *(undefined4 *)(param_1 + 0x268c) = 0x606;
    *(undefined4 *)(param_1 + 0x2168) = 0x101d;
    uVar3 = *(uint *)(*(int *)(param_1 + 0x244) + 0x24) & 0x7ff00000;
    if (uVar3 == 0x800000) {
      *(byte *)(param_1 + 0x2694) = *(byte *)(param_1 + 0x2694) | 1;
    }
    else if (uVar3 == 0x100000) {
      *(byte *)(param_1 + 0x2694) = *(byte *)(param_1 + 0x2694) | 2;
    }
    else if (uVar3 == 0x200000) {
      *(byte *)(param_1 + 0x2694) = *(byte *)(param_1 + 0x2694) | 0x10;
    }
    else if (uVar3 == 0x400000) {
      *(byte *)(param_1 + 0x2694) = *(byte *)(param_1 + 0x2694) | 0x40;
    }
  }
  FUN_000b432e(iVar6,0,0);
  *(undefined1 *)(param_1 + 0x1aa8) = 0;
  *(undefined1 *)(param_1 + 0x1aa9) = 0;
  *(undefined4 *)(param_1 + 0x1aa4) = 0;
  ((int (*)())FUN_000aa683)(iVar6);
  *(undefined **)(param_1 + 0x14f0) = PTR_LAB_0008aa24_4_00213319;
  *(undefined **)(param_1 + 0x14f4) = PTR_LAB_0008b066_4_00213411;
  if (*(char *)(param_1 + 0x1aa8) == '\0') {
    *(undefined **)(param_1 + 0x14f8) = PTR_LAB_00213359;
  }
  else {
    *(undefined **)(param_1 + 0x14f8) = PTR_LAB_002133ed;
  }
  *(undefined **)(param_1 + 0x157c) = PTR_FUN_0021333d;
  *(undefined **)(param_1 + 0x1580) = PTR_FUN_002133bd;
  if (*(char *)(param_1 + 0x1aa8) == '\0') {
    *(undefined4 *)(param_1 + 0x14fc) = 0;
    *(undefined **)(param_1 + 0x1500) = PTR_FUN_0021337d;
    *(undefined **)(param_1 + 0x1510) = PTR_FUN_00213419;
    *(undefined **)(param_1 + 0x1504) = PTR_FUN_0021330d;
    *(undefined4 *)(param_1 + 0x1514) = 0;
    *(undefined4 *)(param_1 + 0x1518) = 0;
    *(undefined4 *)(param_1 + 0x151c) = 0;
    *(undefined **)(param_1 + 0x1520) = PTR_LAB_0007e9ba_4_00213405;
    *(undefined **)(param_1 + 0x1524) = PTR_FUN_00213345;
    *(undefined **)(param_1 + 0x1528) = PTR_LAB_0007f599_1_002133f1;
    *(undefined **)(param_1 + 0x152c) = PTR_LAB_0007f7db_1_00213429;
    *(undefined **)(param_1 + 0x1530) = PTR_FUN_00213379;
    *(undefined **)(param_1 + 0x1534) = PTR_LAB_0007fd89_1_00213329;
    *(undefined **)(param_1 + 0x1538) = PTR_FUN_002133e5;
    *(undefined **)(param_1 + 0x153c) = PTR_LAB_000804c7_1_00213355;
    *(undefined **)(param_1 + 0x1540) = PTR_FUN_00213389;
    *(undefined **)(param_1 + 0x1544) = PTR_LAB_00080b3d_1_00213321;
    *(undefined **)(param_1 + 0x1548) = PTR_FUN_0021331d;
    *(undefined **)(param_1 + 0x154c) = PTR_LAB_000810eb_1_00213315;
    *(undefined **)(param_1 + 0x1550) = PTR_FUN_00213371;
    *(undefined **)(param_1 + 0x1554) = PTR_FUN_0021332d;
    *(undefined **)(param_1 + 0x1558) = PTR_FUN_00213425;
    *(undefined **)(param_1 + 0x155c) = PTR_FUN_002132f9;
    *(undefined **)(param_1 + 0x1560) = PTR_FUN_00213385;
    *(undefined **)(param_1 + 0x1564) = PTR_FUN_0021341d;
    *(undefined **)(param_1 + 0x1568) = PTR_LAB_000820d5_1_002132f1;
    *(undefined **)(param_1 + 0x156c) = PTR_LAB_0007ef20_4_002133cd;
  }
  else {
    *(undefined **)(param_1 + 0x14fc) = PTR_FUN_002133a5;
    *(undefined **)(param_1 + 0x1500) = PTR_FUN_00213331;
    *(undefined **)(param_1 + 0x1510) = PTR_FUN_002133c9;
    *(undefined **)(param_1 + 0x1504) = PTR_LAB_0006378b_1_00213349;
    *(undefined **)(param_1 + 0x1514) = PTR_LAB_00213401;
    *(undefined **)(param_1 + 0x1518) = PTR_LAB_00063aee_4_0021342d;
    *(undefined **)(param_1 + 0x151c) = PTR_LAB_0007e91b_1_00213369;
    *(undefined4 *)(param_1 + 0x1520) = 0;
    *(undefined **)(param_1 + 0x1524) = PTR_FUN_00213309;
    *(undefined **)(param_1 + 0x1528) = PTR_FUN_0021335d;
    *(undefined **)(param_1 + 0x152c) = PTR_FUN_0021336d;
    *(undefined **)(param_1 + 0x1530) = PTR_FUN_002133b9;
    *(undefined **)(param_1 + 0x1534) = PTR_FUN_002133e9;
    *(undefined **)(param_1 + 0x1538) = PTR_LAB_00065b1e_4_00213375;
    *(undefined **)(param_1 + 0x153c) = PTR_LAB_00066842_4_00213305;
    *(undefined **)(param_1 + 0x1540) = PTR_FUN_002133ad;
    *(undefined **)(param_1 + 0x1544) = PTR_FUN_00213339;
    *(undefined **)(param_1 + 0x1548) = PTR_FUN_002133d5;
    *(undefined **)(param_1 + 0x154c) = PTR_FUN_00213409;
    *(undefined **)(param_1 + 0x1550) = PTR_FUN_00213391;
    *(undefined **)(param_1 + 0x1554) = PTR_FUN_0021334d;
    *(undefined **)(param_1 + 0x1558) = PTR_FUN_00213395;
    *(undefined **)(param_1 + 0x155c) = PTR_FUN_002133fd;
    *(undefined **)(param_1 + 0x1560) = PTR_FUN_002133b1;
    *(undefined **)(param_1 + 0x1564) = PTR_FUN_0021338d;
    *(undefined **)(param_1 + 0x1568) = PTR_FUN_002133d1;
    *(undefined **)(param_1 + 0x156c) = PTR_LAB_0006b4b2_4_00213415;
  }
  *(code **)(param_1 + 0x1588) = FUN_000a5322;
  FUN_00099e52(iVar6,0x80);
  *(undefined1 *)(param_1 + 0x366) = 1;
  *(undefined1 *)(param_1 + 0x364) = 1;
  *(undefined1 *)(param_1 + 0x365) = 0;
  *(undefined1 *)(param_1 + 0x36b) = 1;
  *(undefined4 *)(param_1 + 0x37c) = 1;
  *(undefined1 *)(param_1 + 0x2b81) = 1;
  *(undefined1 *)(param_1 + 0x2691) = 0;
  *(undefined2 *)(param_1 + 0x20ac) = 1;
  uVar1 = (**(code **)(param_1 + 0x250))(1,0x3760);
  *(undefined4 *)(param_1 + 0x20a0) = uVar1;
  FUN_000497eb(iVar6);
  *(undefined2 *)(*(int *)(param_1 + 0x20a0) + 0x15cc) = 0xffff;
  *(undefined4 *)(param_1 + 0x135c) = 5;
  uVar1 = (**(code **)(param_1 + 0x250))(1,0x14);
  *(undefined4 *)(param_1 + 0x1358) = uVar1;
  *(undefined2 *)(param_1 + 0x1350) = 5;
  pvVar4 = (void *)(**(code **)(param_1 + 0x24c))(10);
  *(void **)(param_1 + 0x1354) = pvVar4;
  _memset(pvVar4,0xff,(uint)*(ushort *)(param_1 + 0x1350) * 2);
  *(undefined4 *)(param_1 + 0x20b4) = 0;
  *(undefined4 *)(param_1 + 0x20b8) = 0x10;
  uVar1 = (**(code **)(param_1 + 0x24c))(0x40);
  *(undefined4 *)(param_1 + 0x20bc) = uVar1;
  FUN_0004e1da(iVar6);
  *(code **)(param_1 + 0x139c) = FUN_000a531d;
  *(undefined **)(param_1 + 0x13e0) = PTR_LAB_002132bd;
  *(undefined **)(param_1 + 0x1398) = PTR_LAB_000839ca_4_002133f5;
  *(undefined **)(param_1 + 0x14b4) = PTR_LAB_002132f5;
  *(undefined **)(param_1 + 0x14b8) = PTR_FUN_00213365;
  *(undefined **)(param_1 + 0x14bc) = PTR_DAT_00213361;
  *(undefined **)(param_1 + 0x1464) = PTR_FUN_00213381;
  FUN_000a0efc(iVar6);
  FUN_0009fccb(iVar6);
  FUN_0008a67f(iVar6);
  *(undefined1 *)(param_1 + 0x26f) = 1;
  *(undefined **)(param_1 + 0x1570) = PTR_LAB_0004ae42_4_002133c1;
  *(undefined **)(param_1 + 0x1574) = PTR_LAB_0004b37e_4_002132fd;
  *(undefined **)(param_1 + 0x2b8c) = PTR_FUN_002132ed;
  *(undefined **)(param_1 + 0x1578) = PTR_FUN_002133dd;
  return;
}

/* FUN_000a5d2f @ 0xa5d2f (194 bytes) */
int FUN_000a5d2f(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = param_1 + 0x240;
  ((int (*)())FUN_000a29d8)(iVar1);
  ((int (*)())FUN_000a2967)(iVar1);
  FUN_000b42eb(iVar1);
  FUN_0004a357(iVar1);
  FUN_0009a6ed(iVar1);
  if (*(int *)(param_1 + 0x1358) != 0) {
    (**(code **)(param_1 + 600))(*(int *)(param_1 + 0x1358));
    *(undefined4 *)(param_1 + 0x1358) = 0;
  }
  if (*(int *)(param_1 + 0x1354) != 0) {
    (**(code **)(param_1 + 600))(*(int *)(param_1 + 0x1354));
    *(undefined4 *)(param_1 + 0x1354) = 0;
  }
  if (*(int *)(param_1 + 0x20bc) != 0) {
    (**(code **)(param_1 + 600))(*(int *)(param_1 + 0x20bc));
    *(undefined4 *)(param_1 + 0x20bc) = 0;
    *(undefined4 *)(param_1 + 0x20b4) = 0;
    *(undefined4 *)(param_1 + 0x20b8) = 0;
  }
  FUN_0009fa86(iVar1);
  if (*(int *)(param_1 + 0x1aa4) != 0) {
    (**(code **)(param_1 + 600))(*(int *)(param_1 + 0x1aa4));
    *(undefined4 *)(param_1 + 0x1aa4) = 0;
  }
  return;
}

/* FUN_000a5df1 @ 0xa5df1 (619 bytes) */
int FUN_000a5df1(param_1)
  int param_1;
{
  byte bVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  iVar4 = param_1 + 0x240;
  *(undefined1 *)(param_1 + 0x15f8) = *(undefined1 *)(param_1 + 0x2b7c);
  bVar1 = *(byte *)(param_1 + 0x2b7f);
  uVar7 = *(ushort *)(PTR_DAT_002131c9 + (uint)bVar1 * 0x24 + 0x1a) >> 6 & 0x1f |
          ((byte)PTR_DAT_002131c9[(uint)bVar1 * 0x24 + 0x1b] >> 3 & 3) << 8 |
          ((byte)PTR_DAT_002131c9[(uint)bVar1 * 0x24 + 0x1b] >> 5 & 3) << 10 |
          ((byte)PTR_DAT_002131c9[(uint)bVar1 * 0x24 + 0x1c] & 3) << 0xc |
          ((byte)PTR_DAT_002131c9[(uint)bVar1 * 0x24 + 0x1c] >> 2 & 3) << 0xe;
  uVar2 = *(uint *)(param_1 + 0x1ae4);
  *(uint *)(param_1 + 0x1ae4) = uVar2 & 0xffc0003f;
  piVar3 = *(int **)(*(int *)(param_1 + 0x18) + 0x1a0);
  if (piVar3 != (int *)0x0) {
    iVar8 = 0;
    iVar6 = iVar4;
    do {
      if (*(short *)(*piVar3 + 0x90 + iVar8 * 2) == 0) {
        *(undefined4 *)(iVar6 + 0x233c) = 0xf;
      }
      else {
        *(uint *)(iVar6 + 0x233c) = uVar7;
        *(uint *)(param_1 + 0x1ae4) =
             *(uint *)(param_1 + 0x1ae4) & 0xffc0003f |
             (uint)(ushort)((ushort)(*(uint *)(param_1 + 0x1ae4) >> 6) |
                           (ushort)(1 << ((byte)iVar8 & 0x1f))) << 6;
      }
      iVar8 = iVar8 + 1;
      iVar6 = iVar6 + 4;
    } while (iVar8 != 4);
LAB_000a5f1f:
    uVar7 = *(uint *)(param_1 + 0x1ae4);
    uVar5 = uVar7 >> 6 & 0xffff;
    if (*(int *)(param_1 + 0x1688 + uVar5 * 4) == 0) {
      FUN_000b432e(iVar4,0,uVar5);
      uVar7 = *(uint *)(param_1 + 0x1ae4);
    }
    if ((((uVar2 >> 6 & 0xffff) != (uVar7 >> 6 & 0xffff)) && ((uVar7 & 0x3fffc0) != 0)) &&
       (*(char *)(*(int *)(param_1 + 0x10) + 0x430c) == '\0')) {
      FUN_000b4709(iVar4,0);
      (**(code **)(param_1 + 0x2b8c))(iVar4,*(undefined4 *)(param_1 + 0x209c));
      *(uint *)(param_1 + 0x1b70) = *(uint *)(param_1 + 0x1b70) | 0x40;
      return;
    }
    *(uint *)(param_1 + 0x1b70) = *(uint *)(param_1 + 0x1b70) | 0x40;
    return;
  }
  iVar8 = 0;
  iVar6 = iVar4;
  if (*(short *)(*(int *)(param_1 + 0x10) + 0x2dba) == 0) goto LAB_000a6031;
  do {
    *(uint *)(iVar6 + 0x233c) = uVar7;
    *(uint *)(param_1 + 0x1ae4) =
         *(uint *)(param_1 + 0x1ae4) & 0xffc0003f |
         (uint)(ushort)((ushort)(*(uint *)(param_1 + 0x1ae4) >> 6) |
                       (ushort)(1 << ((byte)iVar8 & 0x1f))) << 6;
    while( true ) {
      iVar8 = iVar8 + 1;
      iVar6 = iVar6 + 4;
      if (iVar8 == 4) goto LAB_000a5f1f;
      if (*(short *)(*(int *)(param_1 + 0x10) + 0x2dba + iVar8 * 2) != 0) break;
LAB_000a6031:
      *(undefined4 *)(iVar6 + 0x233c) = 0xf;
    }
  } while( true );
}

/* FUN_000a605c @ 0xa605c (137 bytes) */
int FUN_000a605c(param_1)
  int param_1;
{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  *(undefined1 *)(param_1 + 0x2a) = 1;
  *(undefined4 *)(param_1 + 0x40) = 0x7ffff;
  *(undefined4 *)(param_1 + 0x38) = 0x7ffff;
  *(undefined1 *)(param_1 + 0x29) = 1;
  *(undefined2 *)(param_1 + 0x32) = 0xffff;
  *(undefined2 *)(param_1 + 0x34) = 0xffff;
  *(undefined1 *)(param_1 + 0x2c) = 0xff;
  *(undefined1 *)(param_1 + 0x2d) = 0xf;
  *(undefined1 *)(param_1 + 0x2e) = 3;
  *(undefined1 *)(param_1 + 0x30) = 7;
  *(undefined4 *)(param_1 + 0x3c) = 0x800015ff;
  *(undefined4 *)(param_1 + 0x180c) = 5;
  *(undefined4 *)(param_1 + 0x1810) = 0x1f;
  bVar1 = *(byte *)(param_1 + 0x13b5);
  if (bVar1 != 0) {
    iVar3 = 0;
    iVar2 = param_1;
    do {
      *(undefined1 *)(iVar2 + 0x1814) = 0x3f;
      *(undefined1 *)(iVar2 + 0x181c) = 3;
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 1;
    } while (iVar3 < (int)(uint)bVar1);
  }
  *(undefined1 *)(param_1 + 0x23ec) = 1;
  *(undefined1 *)(param_1 + 0x29) = 1;
  return;
}

/* FUN_000a60e5 @ 0xa60e5 (297 bytes) */
int FUN_000a60e5(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  undefined4 local_10;
  
  if (((*(byte *)(param_1 + 0x44) & 1) == 0) ||
     (*(short *)(*(int *)(*(int *)(param_1 + 4) + 0x10) + 0x2d48) != -0x7e06)) {
    bVar3 = *(byte *)(param_1 + 0x45);
    if ((bVar3 & 0x85) == 0) {
      local_10 = 0;
      goto LAB_000a6122;
    }
  }
  else {
    bVar3 = *(byte *)(param_1 + 0x45);
  }
  local_10 = 1;
LAB_000a6122:
  iVar1 = 5;
  if (-1 < (char)*(byte *)(param_1 + 0x44)) {
    iVar1 = local_10;
  }
  if ((bVar3 & 0x40) == 0) {
    if (*(char *)(param_1 + 0x2b) != '\0') {
      iVar5 = 0;
      iVar4 = 0;
      iVar2 = param_1;
      do {
        if (*(int *)(iVar2 + 0x13f8) != 0) {
          *(int *)(param_1 + 0x1824 + iVar5 * 4) = iVar4;
          iVar5 = iVar5 + 1;
        }
        iVar4 = iVar4 + 1;
        iVar2 = iVar2 + 4;
      } while (iVar4 < (int)(uint)*(byte *)(param_1 + 0x2b));
      *(int *)(param_1 + 0x1804) = iVar5 * 0x10 + iVar1;
      return;
    }
  }
  else if (*(char *)(param_1 + 0x13b0) != '\0') {
    iVar4 = 0;
    iVar2 = 0;
    do {
      while ((*(byte *)(param_1 + 0x46) & 4) != 0) {
        if (((int)(uint)*(byte *)(param_1 + 0x11d3) >> ((byte)iVar2 & 0x1f) & 1U) == 0)
        goto LAB_000a6199;
LAB_000a61ba:
        *(int *)(param_1 + 0x1824 + iVar4 * 4) = iVar2;
        iVar4 = iVar4 + 1;
        iVar2 = iVar2 + 1;
        if ((int)(uint)*(byte *)(param_1 + 0x13b0) <= iVar2) goto LAB_000a61d2;
      }
      if (((int)(uint)*(byte *)(param_1 + 0x1135) >> ((byte)iVar2 & 0x1f) & 1U) != 0)
      goto LAB_000a61ba;
LAB_000a6199:
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)(uint)*(byte *)(param_1 + 0x13b0));
LAB_000a61d2:
    *(int *)(param_1 + 0x1804) = iVar4 * 0x10 + iVar1;
    return;
  }
  *(int *)(param_1 + 0x1804) = iVar1;
  return;
}

/* FUN_000a620e @ 0xa620e (13 bytes) */
int FUN_000a620e(param_1)
  int param_1;
{
  *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x10;
  *(undefined1 *)(param_1 + 0x29) = 1;
  return;
}

/* FUN_000a621b @ 0xa621b (27 bytes) */
int FUN_000a621b(param_1)
  int param_1;
{
  *(byte *)(param_1 + 0x44) = *(byte *)(param_1 + 0x44) & 0xf7;
  *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x400;
  *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x1018;
  *(undefined1 *)(param_1 + 0x29) = 1;
  return;
}

/* FUN_000a6236 @ 0xa6236 (5 bytes) */
int FUN_000a6236()
{
  return;
}

/* FUN_000a623b @ 0xa623b (968 bytes) */
int FUN_000a623b(param_1, param_2)
  int param_1;
  uint param_2;
{
  byte *pbVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  ushort uVar9;
  byte bVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int local_40;
  uint local_3c;
  byte local_38;
  undefined4 local_34;
  int local_24;
  int local_20;
  
  if (param_2 != 0) {
    local_24 = param_1;
    local_3c = 0;
    local_20 = 0;
    iVar13 = param_1 + 0x240;
    local_40 = 0;
    do {
      if ((param_2 & 1) != 0) {
        uVar7 = *(uint *)(param_1 + 0x288 + local_3c * 4);
        uVar2 = uVar7 & 0xffffffe0 | *(uint *)(*(int *)(param_1 + 0x10) + 0x31d4 + local_20) & 0x1f;
        uVar8 = *(uint *)(param_1 + 0x278);
        *(uint *)(param_1 + 0x278) = uVar8 | 0x200;
        iVar12 = 1 << ((byte)local_3c & 0x1f);
        uVar9 = (ushort)iVar12;
        *(ushort *)(param_1 + 0x272) = *(ushort *)(param_1 + 0x272) | uVar9;
        if (uVar7 != uVar2) {
          *(ushort *)(param_1 + 0x274) = *(ushort *)(param_1 + 0x274) | uVar9;
          *(undefined1 *)(param_1 + 0x269) = 1;
          iVar11 = *(int *)(param_1 + 0x10);
          if (((*(char *)(iVar11 + 0x2d4a) != '\0') && (*(int *)(local_24 + 0x18c) != 0)) &&
             ((**(byte **)(*(int *)(local_24 + 0x18c) + 0x30) & 0xf) == 0)) {
            *(uint *)(param_1 + 0x278) = uVar8 | 0x220;
            iVar11 = *(int *)(param_1 + 0x10);
          }
          if (*(char *)(iVar11 + 0x2e0a) != '\0') {
            *(uint *)(param_1 + 0x278) = *(uint *)(param_1 + 0x278) | 0x100;
          }
          *(uint *)(param_1 + 0x288 + local_3c * 4) = uVar2;
          *(undefined1 *)(param_1 + 0x26b5) = 1;
        }
        iVar11 = *(int *)(local_24 + 0x18c);
        local_38 = (byte)iVar12;
        if (iVar11 == 0) {
          if (*(char *)(local_3c + 0x1438 + iVar13) != '\0') {
            *(ushort *)(param_1 + 0x274) = *(ushort *)(param_1 + 0x274) | uVar9;
            *(undefined1 *)(param_1 + 0x269) = 1;
          }
          *(undefined1 *)(local_3c + 0x1438 + iVar13) = 0;
          *(undefined4 *)(param_1 + 0x1638 + local_3c * 4) = 0;
          pbVar1 = (byte *)(param_1 + 0x1ae8 + local_3c * 8);
          *pbVar1 = *pbVar1 & 0xfe;
          pbVar1 = (byte *)(param_1 + 0x1abc + local_3c * 2);
          *pbVar1 = *pbVar1 & 0xfe;
          *(byte *)(param_1 + 0x260) = *(byte *)(param_1 + 0x260) & ~local_38;
        }
        else {
          bVar3 = *(byte *)(iVar11 + 0x6b);
          bVar4 = *(byte *)(iVar11 + 0x6a);
          cVar5 = *(char *)(iVar11 + 0x69);
          bVar6 = *(byte *)(iVar11 + 0x68);
          bVar10 = *(byte *)(iVar11 + 0xc9) & 3;
          local_34 = CONCAT13(*(byte *)(iVar11 + 0xc9),(int3)iVar12) & 0x300ffff;
          uVar9 = (ushort)local_34;
          if ((iVar11 + 0x3c != *(int *)(param_1 + 0x1638 + local_3c * 4)) &&
             (*(undefined1 *)(param_1 + 0x269) = 1, *(int *)(param_1 + 0x1638 + local_3c * 4) == 0))
          {
            *(ushort *)(param_1 + 0x274) = *(ushort *)(param_1 + 0x274) | uVar9;
          }
          *(undefined1 *)(local_3c + 0x1438 + iVar13) = 1;
          *(int *)(param_1 + 0x1638 + local_3c * 4) = iVar11 + 0x3c;
          pbVar1 = (byte *)(param_1 + 0x1ae8 + local_3c * 8);
          *pbVar1 = *pbVar1 | 1;
          *(byte *)(param_1 + 0x1aef + local_3c * 8) =
               *(byte *)(param_1 + 0x1aef + local_3c * 8) & 0x1f | *(char *)(iVar11 + 0x6c) << 5;
          pbVar1 = (byte *)(param_1 + 0x1abc + local_3c * 2);
          *pbVar1 = *pbVar1 | 1;
          if (*(byte *)(param_1 + 0x26b) <= local_3c) {
            *(byte *)(param_1 + 0x26b) = (byte)local_3c + 1;
            *(undefined1 *)(param_1 + 0x26b5) = 1;
            *(uint *)(param_1 + 0x27c) = *(uint *)(param_1 + 0x27c) | 0x400;
            *(undefined1 *)(param_1 + 0x269) = 1;
          }
          FUN_0002c8e0(param_1,local_3c);
          *(undefined4 *)(iVar11 + 0x88) = *(undefined4 *)(*(int *)(iVar11 + 0x30) + 0x38);
          *(byte *)(param_1 + 0x1ae8 + local_3c * 8) =
               *(byte *)(param_1 + 0x1ae8 + local_3c * 8) & 0x8f | (bVar3 & 7) << 4;
          *(byte *)(param_1 + 0x1aea + local_3c * 8) =
               *(byte *)(param_1 + 0x1aea + local_3c * 8) & 7 | (bVar4 & 1) << 3 | cVar5 << 5 |
               (bVar6 & 1) << 4;
          if (*(short *)(iVar11 + 0x74) == 0x1902) {
            *(byte *)(param_1 + 0x1a48) = *(byte *)(param_1 + 0x1a48) | 1;
          }
          if ((**(ushort **)(iVar11 + 0x30) & 0xf) == 2) {
            *(byte *)(param_1 + 0x1a48) = *(byte *)(param_1 + 0x1a48) | 2;
          }
          if (*(float *)(iVar11 + 0x88) != 0.0) {
            *(byte *)(param_1 + 0x1a48) = *(byte *)(param_1 + 0x1a48) | 8;
          }
          if (((local_3c < 8) && ((*(unsigned char *)((unsigned char *)&(local_34) + 3)) != '\0')) &&
             ((*(byte *)(param_1 + 0x285) & 0x40) == 0)) {
            if (((int)(uint)*(byte *)(param_1 + 0x260) >> ((byte)local_3c & 0x1f) & 1U) == 0) {
              *(byte *)(param_1 + 0x260) = *(byte *)(param_1 + 0x260) | local_38;
              *(ushort *)(param_1 + 0x274) = *(ushort *)(param_1 + 0x274) | uVar9;
              *(undefined1 *)(param_1 + 0x269) = 1;
            }
            *(byte *)(local_3c + 0x21 + iVar13) = bVar10;
            iVar12 = local_40 + iVar13;
            *(uint *)(iVar12 + 0x2854) = (uint)*(ushort *)(iVar11 + 0xd0);
            *(uint *)(iVar12 + 0x2858) = (uint)*(ushort *)(iVar11 + 0xd4);
            *(uint *)(iVar12 + 0x285c) = (uint)*(ushort *)(iVar11 + 0xd2);
          }
          else if (((int)(uint)*(byte *)(param_1 + 0x260) >> ((byte)local_3c & 0x1f) & 1U) != 0) {
            *(byte *)(param_1 + 0x260) = *(byte *)(param_1 + 0x260) & ~local_38;
            *(ushort *)(param_1 + 0x274) = *(ushort *)(param_1 + 0x274) | uVar9;
            *(undefined1 *)(param_1 + 0x269) = 1;
          }
          *(byte *)(param_1 + 0x1aec + local_3c * 8) =
               *(byte *)(param_1 + 0x1aec + local_3c * 8) & 0xf3 | bVar10 * '\x04';
        }
      }
      local_3c = local_3c + 1;
      local_40 = local_40 + 0xc;
      local_24 = local_24 + 4;
      local_20 = local_20 + 0x7c;
      param_2 = param_2 >> 1;
    } while (param_2 != 0);
  }
  return;
}

/* FUN_000a6603 @ 0xa6603 (90 bytes) */
int FUN_000a6603(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = *(int *)(param_1 + 0x1638 + param_2 * 4);
  if (iVar1 != 0) {
    piVar3 = (int *)(*(int *)(param_1 + 0x18) + param_2 * 0x14);
    iVar2 = 5;
    do {
      if ((*piVar3 != 0) && (iVar1 == *piVar3 + 0x3c)) {
        return;
      }
      piVar3 = piVar3 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    *(undefined4 *)(param_1 + 0x1638 + param_2 * 4) = 0;
  }
  return;
}

/* FUN_000a665d @ 0xa665d (22 bytes) */
int FUN_000a665d(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_1 + 0x1638 + param_2 * 4) = 0;
  return;
}

/* FUN_000a6673 @ 0xa6673 (727 bytes) */
int FUN_000a6673(param_1, param_2)
  int param_1;
  uint param_2;
{
  short *psVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  int local_1c;
  uint local_18;
  int local_14;
  int local_10;
  
  local_18 = param_2 >> 0x10 & 0xff;
  if (local_18 != 0) {
    local_1c = 0;
    local_14 = 0;
    local_10 = 0;
    do {
      if ((local_18 & 1) != 0) {
        psVar1 = (short *)(*(int *)(param_1 + 0x10) + 0x3988 + local_14);
        iVar2 = param_1 + 0x690 + local_10;
        puVar3 = (uint *)(param_1 + 0x288 + local_1c * 4);
        if ((char)psVar1[0x48] == '\0') {
          uVar5 = *puVar3 & 0xffffffdf;
          *puVar3 = uVar5;
          if (*(char *)((int)psVar1 + 0x91) != '\0') goto LAB_000a66c6;
LAB_000a679a:
          uVar5 = uVar5 & 0xffffffbf;
          *puVar3 = uVar5;
          if ((char)psVar1[0x49] != '\0') goto LAB_000a66d8;
LAB_000a67ac:
          uVar5 = uVar5 & 0xffffff7f;
          *puVar3 = uVar5;
          if (*(char *)((int)psVar1 + 0x93) != '\0') goto LAB_000a66e9;
LAB_000a67bd:
          uVar4 = uVar5 & 0xfffffeff;
          *puVar3 = uVar4;
          if ((uVar5 & 0xe0) != 0) goto LAB_000a67cd;
          uVar5 = *(uint *)(param_1 + 0x278);
        }
        else {
          uVar5 = *puVar3 | 0x20;
          *puVar3 = uVar5;
          if (*(char *)((int)psVar1 + 0x91) == '\0') goto LAB_000a679a;
LAB_000a66c6:
          uVar5 = uVar5 | 0x40;
          *puVar3 = uVar5;
          if ((char)psVar1[0x49] == '\0') goto LAB_000a67ac;
LAB_000a66d8:
          uVar5 = uVar5 | 0x80;
          *puVar3 = uVar5;
          if (*(char *)((int)psVar1 + 0x93) == '\0') goto LAB_000a67bd;
LAB_000a66e9:
          uVar4 = uVar5 | 0x100;
          *puVar3 = uVar4;
LAB_000a67cd:
          if ((uVar4 & 0x20) != 0) {
            if (*(short *)(iVar2 + 0x3c) != *psVar1) {
              *(short *)(iVar2 + 0x3c) = *psVar1;
            }
            *(undefined4 *)(iVar2 + 0x50) = *(undefined4 *)(psVar1 + 10);
            *(undefined4 *)(iVar2 + 0x54) = *(undefined4 *)(psVar1 + 0xc);
            *(undefined4 *)(iVar2 + 0x58) = *(undefined4 *)(psVar1 + 0xe);
            *(undefined4 *)(iVar2 + 0x5c) = *(undefined4 *)(psVar1 + 0x10);
            *(undefined4 *)(iVar2 + 0x40) = *(undefined4 *)(psVar1 + 2);
            *(undefined4 *)(iVar2 + 0x44) = *(undefined4 *)(psVar1 + 4);
            *(undefined4 *)(iVar2 + 0x48) = *(undefined4 *)(psVar1 + 6);
            *(undefined4 *)(iVar2 + 0x4c) = *(undefined4 *)(psVar1 + 8);
            uVar4 = *puVar3;
          }
          if ((uVar4 & 0x40) != 0) {
            if (*(short *)(iVar2 + 0x60) != psVar1[0x12]) {
              *(short *)(iVar2 + 0x60) = psVar1[0x12];
            }
            *(undefined4 *)(iVar2 + 0x74) = *(undefined4 *)(psVar1 + 0x1c);
            *(undefined4 *)(iVar2 + 0x78) = *(undefined4 *)(psVar1 + 0x1e);
            *(undefined4 *)(iVar2 + 0x7c) = *(undefined4 *)(psVar1 + 0x20);
            *(undefined4 *)(iVar2 + 0x80) = *(undefined4 *)(psVar1 + 0x22);
            *(undefined4 *)(iVar2 + 100) = *(undefined4 *)(psVar1 + 0x14);
            *(undefined4 *)(iVar2 + 0x68) = *(undefined4 *)(psVar1 + 0x16);
            *(undefined4 *)(iVar2 + 0x6c) = *(undefined4 *)(psVar1 + 0x18);
            *(undefined4 *)(iVar2 + 0x70) = *(undefined4 *)(psVar1 + 0x1a);
            uVar4 = *puVar3;
          }
          if ((char)uVar4 < '\0') {
            if (*(short *)(iVar2 + 0x84) != psVar1[0x24]) {
              *(short *)(iVar2 + 0x84) = psVar1[0x24];
            }
            *(undefined4 *)(iVar2 + 0x98) = *(undefined4 *)(psVar1 + 0x2e);
            *(undefined4 *)(iVar2 + 0x9c) = *(undefined4 *)(psVar1 + 0x30);
            *(undefined4 *)(iVar2 + 0xa0) = *(undefined4 *)(psVar1 + 0x32);
            *(undefined4 *)(iVar2 + 0xa4) = *(undefined4 *)(psVar1 + 0x34);
            *(undefined4 *)(iVar2 + 0x88) = *(undefined4 *)(psVar1 + 0x26);
            *(undefined4 *)(iVar2 + 0x8c) = *(undefined4 *)(psVar1 + 0x28);
            *(undefined4 *)(iVar2 + 0x90) = *(undefined4 *)(psVar1 + 0x2a);
            *(undefined4 *)(iVar2 + 0x94) = *(undefined4 *)(psVar1 + 0x2c);
            uVar4 = *puVar3;
          }
          if ((uVar4 & 0x100) != 0) {
            if (*(short *)(iVar2 + 0xa8) != psVar1[0x36]) {
              *(short *)(iVar2 + 0xa8) = psVar1[0x36];
            }
            *(undefined4 *)(iVar2 + 0xbc) = *(undefined4 *)(psVar1 + 0x40);
            *(undefined4 *)(iVar2 + 0xc0) = *(undefined4 *)(psVar1 + 0x42);
            *(undefined4 *)(iVar2 + 0xc4) = *(undefined4 *)(psVar1 + 0x44);
            *(undefined4 *)(iVar2 + 200) = *(undefined4 *)(psVar1 + 0x46);
            *(undefined4 *)(iVar2 + 0xac) = *(undefined4 *)(psVar1 + 0x38);
            *(undefined4 *)(iVar2 + 0xb0) = *(undefined4 *)(psVar1 + 0x3a);
            *(undefined4 *)(iVar2 + 0xb4) = *(undefined4 *)(psVar1 + 0x3c);
            *(undefined4 *)(iVar2 + 0xb8) = *(undefined4 *)(psVar1 + 0x3e);
          }
          uVar5 = *(uint *)(param_1 + 0x278);
        }
        *(uint *)(param_1 + 0x278) = uVar5 | 0x8000;
        *(byte *)(param_1 + 0x26c) =
             *(byte *)(param_1 + 0x26c) | (byte)(1 << ((byte)local_1c & 0x1f));
        *(undefined1 *)(param_1 + 0x269) = 1;
        if (*(char *)(*(int *)(param_1 + 0x10) + 0x2d4a) != '\0') {
          *(uint *)(param_1 + 0x278) = uVar5 | 0x8020;
        }
      }
      local_1c = local_1c + 1;
      local_14 = local_14 + 0x94;
      local_10 = local_10 + 0xcc;
      local_18 = local_18 >> 1;
    } while (local_18 != 0);
  }
  *(undefined1 *)(param_1 + 0x26b5) = 1;
  return;
}

/* FUN_000a694a @ 0xa694a (1830 bytes) */
int FUN_000a694a(param_1, param_2, param_3)
  int param_1;
  int param_2;
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
  undefined1 uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
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
  float fVar32;
  float fVar33;
  
  if ((param_3 & 8) != 0) {
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x80;
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x20000;
    *(undefined1 *)(param_1 + 0x29) = 1;
  }
  if (((param_3 & 0x3f000008) != 0) && (*(int *)(param_2 + 0x3e28) != 0)) {
    fVar1 = *(float *)(param_2 + 0x1920);
    fVar17 = *(float *)(param_2 + 0x1924);
    fVar2 = *(float *)(param_2 + 0x1930);
    fVar20 = *(float *)(param_2 + 0x1934);
    fVar3 = *(float *)(param_2 + 0x1940);
    fVar21 = *(float *)(param_2 + 0x1944);
    fVar4 = *(float *)(param_2 + 0x1950);
    fVar22 = *(float *)(param_2 + 0x1954);
    fVar23 = fVar1 * fVar20 - fVar17 * fVar2;
    fVar26 = fVar1 * fVar21 - fVar17 * fVar3;
    fVar18 = fVar1 * fVar22 - fVar17 * fVar4;
    fVar30 = fVar2 * fVar21 - fVar20 * fVar3;
    fVar19 = fVar2 * fVar22 - fVar20 * fVar4;
    fVar28 = fVar3 * fVar22 - fVar21 * fVar4;
    fVar5 = *(float *)(param_2 + 0x1928);
    fVar6 = *(float *)(param_2 + 0x192c);
    fVar7 = *(float *)(param_2 + 0x1938);
    fVar8 = *(float *)(param_2 + 0x193c);
    fVar9 = *(float *)(param_2 + 0x1948);
    fVar10 = *(float *)(param_2 + 0x194c);
    fVar11 = *(float *)(param_2 + 0x1958);
    fVar12 = *(float *)(param_2 + 0x195c);
    fVar20 = fVar5 * fVar8 - fVar7 * fVar6;
    fVar24 = fVar5 * fVar10 - fVar9 * fVar6;
    fVar17 = fVar5 * fVar12 - fVar6 * fVar11;
    fVar21 = fVar7 * fVar10 - fVar9 * fVar8;
    fVar25 = fVar7 * fVar12 - fVar8 * fVar11;
    fVar31 = fVar9 * fVar12 - fVar10 * fVar11;
    fVar33 = (fVar20 * fVar24 - fVar21 * fVar20) - fVar17 * fVar21;
    fVar32 = (fVar17 * fVar25 - fVar20 * fVar17) + fVar22 * fVar20;
    fVar29 = (fVar21 * fVar17 - fVar22 * fVar24) - fVar17 * fVar31;
    fVar27 = (fVar20 * fVar31 - fVar21 * fVar25) + fVar22 * fVar21;
    fVar22 = fVar4 * fVar33 + fVar3 * fVar32 + fVar2 * fVar29 + fVar1 * fVar27;
    if ((fVar22 < FLOAT_001c5c40) ||
       ((FLOAT_001c5c44 < fVar22 || (NAN(fVar22) || NAN(FLOAT_001c5c44))))) {
      fVar22 = FLOAT_001c5ba4 / fVar22;
      *(float *)(param_1 + 0x1368) = fVar27 * fVar22;
      *(float *)(FUN_0000136c + param_1) =
           ((fVar3 * fVar25 - fVar4 * fVar21) - fVar2 * fVar31) * fVar22;
      *(float *)(param_1 + 0x1378) = fVar29 * fVar22;
      *(float *)(param_1 + 0x1370) = (fVar30 * fVar12 + (fVar28 * fVar8 - fVar19 * fVar10)) * fVar22
      ;
      *(float *)(param_1 + 5000) = fVar32 * fVar22;
      *(float *)(param_1 + 0x1374) = ((fVar9 * fVar19 - fVar11 * fVar30) - fVar28 * fVar7) * fVar22;
      *(float *)(param_1 + 0x1398) = fVar33 * fVar22;
      *(float *)(param_1 + 0x137c) = ((fVar31 * fVar1 - fVar3 * fVar17) + fVar4 * fVar24) * fVar22;
      *(float *)(param_1 + 0x1380) = ((fVar18 * fVar10 - fVar26 * fVar12) - fVar28 * fVar6) * fVar22
      ;
      *(float *)(param_1 + 0x138c) = ((fVar2 * fVar17 - fVar4 * fVar20) - fVar1 * fVar25) * fVar22;
      *(float *)(param_1 + 0x1384) = (fVar11 * fVar26 + (fVar28 * fVar5 - fVar18 * fVar9)) * fVar22;
      *(float *)(param_1 + 0x139c) = ((fVar1 * fVar21 - fVar2 * fVar24) + fVar3 * fVar20) * fVar22;
      *(float *)(param_1 + 0x1390) = (fVar23 * fVar12 + (fVar19 * fVar6 - fVar18 * fVar8)) * fVar22;
      *(float *)(param_1 + 0x1394) = ((fVar18 * fVar7 - fVar11 * fVar23) - fVar5 * fVar19) * fVar22;
      *(float *)(param_1 + 0x13a0) = ((fVar26 * fVar8 - fVar23 * fVar10) - fVar30 * fVar6) * fVar22;
      *(float *)(param_1 + 0x13a4) = fVar22 * (fVar9 * fVar23 + (fVar5 * fVar30 - fVar7 * fVar26));
      uVar13 = 1;
    }
    else {
      uVar13 = 0;
    }
    *(undefined1 *)(param_1 + 0x13a8) = uVar13;
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20080;
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x20000;
    *(undefined2 *)(param_1 + 0x36) = 0x3f;
    *(undefined1 *)(param_1 + 0x29) = 1;
  }
  if ((param_3 & 0xf8) != 0) {
    if ((param_3 & 0x10) == 0) {
      uVar15 = *(uint *)(param_1 + 0x40);
    }
    else {
      uVar15 = *(uint *)(param_1 + 0x40) | 0x10000;
      *(uint *)(param_1 + 0x40) = uVar15;
    }
    if (*(char *)(param_2 + 0x4301) != '\0') {
      uVar16 = (uint)*(byte *)(param_2 + 0x4300);
      if ((uint)*(byte *)(param_1 + 0x13b4) < (uint)*(byte *)(param_2 + 0x4300)) {
        uVar16 = (uint)*(byte *)(param_1 + 0x13b4);
      }
      if (1 < uVar16) {
        if ((param_3 & 0x20) == 0) {
          uVar14 = 1;
          do {
            uVar14 = uVar14 + 1;
            if (uVar16 == uVar14) goto LAB_000a69eb;
          } while ((param_3 & 0x10 << ((byte)uVar14 & 0x1f)) == 0);
        }
        uVar15 = uVar15 | 0x10000;
        *(uint *)(param_1 + 0x40) = uVar15;
      }
    }
LAB_000a69eb:
    *(uint *)(param_1 + 0x40) = uVar15 | 0x30000;
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x80;
    *(undefined1 *)(param_1 + 0x29) = 1;
  }
  return;
}

/* FUN_000a7070 @ 0xa7070 (544 bytes) */
int FUN_000a7070(param_1, param_2)
  int param_1;
  uint param_2;
{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  uint uVar7;
  float fVar8;
  int iVar9;
  int iVar10;
  
  fVar8 = FLOAT_001c5ba4;
  iVar6 = *(int *)(param_1 + 0x10);
  iVar10 = 0;
  iVar9 = iVar6 + 0x3e20;
  do {
    if ((param_2 & (0x1000000 << ((byte)iVar10 & 0x1f) | 8U)) != 0) {
      uVar7 = 1 << ((byte)iVar10 & 0x1f);
      if ((*(uint *)(iVar6 + 0x3e28) & uVar7) != 0) {
        pfVar1 = (float *)(param_1 + 0x618 + iVar10 * 0x10);
        fVar2 = *(float *)(iVar9 + 0xc);
        fVar3 = *(float *)(iVar9 + 0x10);
        fVar4 = *(float *)(iVar9 + 0x14);
        fVar5 = *(float *)(iVar9 + 0x18);
        if ((fVar5 != fVar8) || (NAN(fVar5) || NAN(fVar8))) {
          *pfVar1 = fVar2 * *(float *)(param_1 + 0x15a8) + fVar3 * *(float *)(param_1 + 0x15b8) +
                    fVar4 * *(float *)(param_1 + 0x15c8) + fVar5 * *(float *)(param_1 + 0x15d8);
          pfVar1[1] = fVar2 * *(float *)(param_1 + 0x15ac) + fVar3 * *(float *)(param_1 + 0x15bc) +
                      fVar4 * *(float *)(param_1 + 0x15cc) + fVar5 * *(float *)(param_1 + 0x15dc);
          pfVar1[2] = fVar2 * *(float *)(param_1 + 0x15b0) + fVar3 * *(float *)(param_1 + 0x15c0) +
                      fVar4 * *(float *)(param_1 + 0x15d0) + fVar5 * *(float *)(param_1 + 0x15e0);
          pfVar1[3] = fVar2 * *(float *)(param_1 + 0x15b4) + fVar3 * *(float *)(param_1 + 0x15c4) +
                      fVar4 * *(float *)(param_1 + 0x15d4) + fVar5 * *(float *)(param_1 + 0x15e4);
        }
        else {
          *pfVar1 = fVar2 * *(float *)(param_1 + 0x15a8) + fVar3 * *(float *)(param_1 + 0x15b8) +
                    fVar4 * *(float *)(param_1 + 0x15c8) + *(float *)(param_1 + 0x15d8);
          pfVar1[1] = fVar2 * *(float *)(param_1 + 0x15ac) + fVar3 * *(float *)(param_1 + 0x15bc) +
                      fVar4 * *(float *)(param_1 + 0x15cc) + *(float *)(param_1 + 0x15dc);
          pfVar1[2] = fVar2 * *(float *)(param_1 + 0x15b0) + fVar3 * *(float *)(param_1 + 0x15c0) +
                      fVar4 * *(float *)(param_1 + 0x15d0) + *(float *)(param_1 + 0x15e0);
          pfVar1[3] = fVar2 * *(float *)(param_1 + 0x15b4) + fVar3 * *(float *)(param_1 + 0x15c4) +
                      fVar4 * *(float *)(param_1 + 0x15d4) + *(float *)(param_1 + 0x15e4);
        }
      }
      *(ushort *)(param_1 + 0x276) = *(ushort *)(param_1 + 0x276) | (ushort)uVar7;
    }
    iVar10 = iVar10 + 1;
    iVar9 = iVar9 + 0x10;
  } while (iVar10 != 6);
  *(uint *)(param_1 + 0x278) = *(uint *)(param_1 + 0x278) | 0x20000;
  *(undefined1 *)(param_1 + 0x269) = 1;
  return;
}

/* FUN_000a7290 @ 0xa7290 (244 bytes) */
int FUN_000a7290(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  if (*(char *)(param_2 + 0x2e2d) != '\0') {
    *(undefined1 *)(param_1 + 0x2f) = 0;
    *(byte *)(param_1 + 0x1808) = *(byte *)(param_1 + 0x1808) | 4;
    *(undefined1 *)(param_1 + 0x2940) = 1;
  }
  if (*(char *)(param_2 + 0x2e2c) != '\0') {
    *(undefined1 *)(param_1 + 0x2f) = 0;
    *(byte *)(param_1 + 0x1808) = *(byte *)(param_1 + 0x1808) | 4;
    *(undefined1 *)(param_1 + 0x2940) = 1;
  }
  iVar7 = *(int *)(param_1 + 4);
  if ((*(char *)(*(int *)(iVar7 + 0x10) + 0x2e2d) != '\0') &&
     ((*(byte *)(param_1 + 0x45) & 0x40) == 0)) {
    cVar2 = FUN_00017bd8(iVar7,*(undefined4 *)(iVar7 + 0x26a0));
    if (cVar2 == '\0') {
      uVar3 = 1;
      iVar7 = *(int *)(param_1 + 4);
      goto LAB_000a72e7;
    }
    iVar7 = *(int *)(param_1 + 4);
  }
  uVar3 = 0;
LAB_000a72e7:
  uVar1 = *(uint *)(param_1 + 0x1928);
  uVar5 = (uVar1 >> 4 ^ uVar3) & 1;
  uVar6 = uVar5 | uVar1 & 0xffffffef | uVar3 << 4;
  *(uint *)(param_1 + 0x1928) = uVar6;
  if (((*(char *)(*(int *)(iVar7 + 0x10) + 0x2e2c) == '\0') ||
      ((*(byte *)(param_1 + 0x45) & 0x40) != 0)) ||
     (*(short *)(*(int *)(iVar7 + 0x10) + 0x2e28) == -1)) {
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
  }
  *(uint *)(param_1 + 0x1928) =
       uVar5 | uVar1 & 0xffffffe7 | uVar3 << 4 | (uVar6 >> 3 ^ uVar4) & 1 | uVar4 * 8;
  *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 6;
  *(undefined1 *)(param_1 + 0x29) = 1;
  return;
}

/* FUN_000a7384 @ 0xa7384 (169 bytes) */
int FUN_000a7384(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  if (*(char *)(param_2 + 0x3178) != '\0') {
    *(undefined1 *)(param_1 + 0x2f) = 0;
    *(byte *)(param_1 + 0x1808) = *(byte *)(param_1 + 0x1808) | 4;
    *(undefined1 *)(param_1 + 0x2940) = 1;
  }
  *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 4;
  *(undefined1 *)(param_1 + 0x29) = 1;
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (((*(char *)(iVar1 + 0x3178) != '\0') && ((*(byte *)(param_1 + 0x45) & 0x40) == 0)) &&
     ((*(short *)(iVar1 + 0x3170) == 0x1b02 || (*(short *)(iVar1 + 0x3172) == 0x1b02)))) {
    *(uint *)(param_1 + 0x1928) =
         *(uint *)(param_1 + 0x1928) & 0xfffffffb | (*(uint *)(param_1 + 0x1928) >> 2 ^ 1) & 1 | 4;
    return;
  }
  *(uint *)(param_1 + 0x1928) =
       *(uint *)(param_1 + 0x1928) & 0xfffffffb | *(uint *)(param_1 + 0x1928) >> 2 & 1;
  return;
}

/* FUN_000a742d @ 0xa742d (594 bytes) */
int FUN_000a742d(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint param_3;
{
  uint uVar1;
  int iVar2;
  byte bVar3;
  byte bVar4;
  
  if ((param_3 & 0x1000) == 0) {
    bVar4 = *(byte *)(param_2 + 0x2e0b);
    bVar3 = *(byte *)(param_1 + 0x45);
LAB_000a7540:
    if ((bVar3 & 1) == bVar4) goto LAB_000a74e4;
  }
  else {
    if ((*(char *)(param_2 + 0x2e0a) == '\0') || ((*(byte *)(param_1 + 0x46) & 4) != 0)) {
      bVar3 = 0;
    }
    else {
      bVar3 = 1;
    }
    *(byte *)(param_1 + 0x44) = *(byte *)(param_1 + 0x44) & 0x7f | bVar3 << 7;
    *(byte *)(param_1 + 0x18a4) = *(byte *)(param_1 + 0x18a4) & 0xfe | bVar3;
    uVar1 = *(uint *)(param_1 + 0x38);
    *(uint *)(param_1 + 0x38) = uVar1 | 0x100;
    *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x40;
    *(undefined1 *)(param_1 + 0x29) = 1;
    bVar4 = *(byte *)(param_2 + 0x2e0b);
    bVar3 = *(byte *)(param_1 + 0x45);
    if (((*(char *)(param_2 + 0x2d4a) == '\0' && bVar4 == 0) && (bVar3 >> 2 & 1) == 0) &&
        -1 < (char)bVar3) goto LAB_000a7540;
    *(uint *)(param_1 + 0x38) = uVar1 | 0x120;
    bVar4 = *(byte *)(param_2 + 0x2e0b);
    if ((bVar3 & 1) == bVar4) goto LAB_000a74e4;
  }
  *(byte *)(param_1 + 0x45) = bVar3 & 0xfe | bVar4 & 1;
  uVar1 = *(uint *)(param_1 + 0x38);
  *(undefined1 *)(param_1 + 0x29) = 1;
  *(uint *)(param_1 + 0x38) = uVar1 | 0x120;
  if (*(int *)(param_1 + -0x70) != 0) {
    *(uint *)(param_1 + 0x38) = uVar1 | 0x2320;
    *(byte *)(param_1 + 0x2e) = *(byte *)(param_1 + 0x2e) | 2;
  }
  if (*(char *)(param_2 + 0x4304) == '\0') {
    if ((*(byte *)(param_1 + 0x44) & 1) == 0) {
      *(byte *)(param_1 + 0x18a4) =
           *(byte *)(param_1 + 0x18a4) & 0xf9 | (*(byte *)(param_1 + 0x45) & 1) << 2;
    }
    else {
      bVar4 = (*(short *)(param_2 + 0x2d48) == -0x7e06) << 2;
      bVar3 = *(byte *)(param_1 + 0x18a4);
      *(byte *)(param_1 + 0x18a4) = bVar3 & 0xfb | bVar4;
      *(byte *)(param_1 + 0x18a4) =
           bVar3 & 0xf9 | bVar4 | (*(byte *)(param_2 + 0x2d4c) & 1) * '\x02';
    }
  }
  else {
    *(byte *)(param_1 + 0x18a4) =
         *(byte *)(param_1 + 0x18a4) & 0xf9 | (*(byte *)(param_1 + 0x45) & 1) << 2 |
         ((*(uint *)(param_1 + 0x44) & 0x2001000) == 0x2001000) * '\x02';
  }
LAB_000a74e4:
  if ((param_3 & 0x800) != 0) {
    uVar1 = *(uint *)(param_1 + 0x38);
    *(uint *)(param_1 + 0x38) = uVar1 | 0x100;
    *(undefined1 *)(param_1 + 0x29) = 1;
    if (*(char *)(param_2 + 0x2d4a) == '\0') {
      iVar2 = *(int *)(param_1 + -0x70);
    }
    else {
      *(uint *)(param_1 + 0x38) = uVar1 | 0x120;
      iVar2 = *(int *)(param_1 + -0x70);
    }
    if (iVar2 == 0) {
      if (*(int *)(param_1 + -0x74) != 0) {
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
        *(undefined1 *)(param_1 + 0x29) = 1;
        *(byte *)(param_1 + 0x2d) = *(byte *)(param_1 + 0x2d) | 3;
        return;
      }
    }
    else {
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x2200;
      *(byte *)(param_1 + 0x2e) = *(byte *)(param_1 + 0x2e) | 2;
    }
  }
  return;
}

/* FUN_000a767f @ 0xa767f (1928 bytes) */
int FUN_000a767f(param_1, param_2)
  int param_1;
  uint param_2;
{
  undefined2 *puVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  ushort uVar6;
  ushort uVar7;
  ushort uVar8;
  ushort uVar9;
  short sVar10;
  short sVar11;
  short sVar12;
  short sVar13;
  char cVar14;
  int iVar15;
  uint uVar16;
  undefined4 *puVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  int local_70;
  uint local_6c;
  int local_28;
  int local_24;
  int local_20;
  
  iVar15 = param_1 + 0x240;
  uVar16 = param_2 >> 0x10 | param_2;
  local_6c = (uVar16 | uVar16 >> 8) & 0xff;
  *(ushort *)(param_1 + 0x272) = *(ushort *)(param_1 + 0x272) | (ushort)local_6c;
  if (local_6c != 0) {
    local_70 = 0;
    local_24 = 0;
    local_20 = 0;
    local_28 = iVar15;
    do {
      if ((local_6c & 1) != 0) {
        puVar17 = (undefined4 *)(*(int *)(param_1 + 0x10) + 0x31c4 + local_24);
        puVar1 = (undefined2 *)(param_1 + 0x690 + local_20);
        if ((local_70 == *(int *)(param_1 + 0x29ac)) && (*(int *)(param_1 + 0x29a8) != 0)) {
          iVar18 = *(int *)(*(int *)(param_1 + 0x29a8) + 0xbc);
LAB_000a7735:
          uVar16 = 1 << ((byte)local_70 & 0x1f);
        }
        else {
          iVar18 = *(int *)(local_28 + 0x13f8);
          if (iVar18 != 0) goto LAB_000a7735;
          uVar16 = 1 << ((byte)local_70 & 0x1f);
          *(uint *)(param_1 + 0x29f0) = *(uint *)(param_1 + 0x29f0) & ~uVar16;
          *(uint *)(param_1 + 0x29f4) = *(uint *)(param_1 + 0x29f4) & ~uVar16;
        }
        if ((param_2 & uVar16) != 0) {
          *puVar1 = *(undefined2 *)(puVar17 + 5);
          uVar6 = *(ushort *)(puVar17 + 5);
          *(byte *)(param_1 + 0x1ae8 + local_70 * 8) =
               *(byte *)(param_1 + 0x1ae8 + local_70 * 8) & 0xf1 |
               (((byte)((uint)uVar6 * 0x3b >> 0xd) & 1 | (byte)((uint)uVar6 * 0x107 >> 10) & 2 |
                (byte)(uVar6 >> 3) & 4) ^ 1) * '\x02';
        }
        if ((param_2 & 0x10000 << ((byte)local_70 & 0x1f)) != 0) {
          *(undefined4 *)(puVar1 + 0x10) = puVar17[0xf];
          if (iVar18 == 0) {
            FUN_0008260c(iVar15,puVar1,0);
          }
          else {
            FUN_0008260c(iVar15,puVar1,iVar18 + 0x4c);
          }
        }
        if ((param_2 & 0x100 << ((byte)local_70 & 0x1f)) != 0) {
          *(undefined4 *)(puVar1 + 0x16) = *puVar17;
          *(undefined4 *)(puVar1 + 0x18) = puVar17[1];
          *(undefined4 *)(puVar1 + 0x1a) = puVar17[2];
          *(undefined4 *)(puVar1 + 0x1c) = puVar17[3];
          *(uint *)(param_1 + 0x27c) = *(uint *)(param_1 + 0x27c) | 0x400;
          *(undefined1 *)(param_1 + 0x269) = 1;
        }
        if ((param_2 & 0x1000000 << ((byte)local_70 & 0x1f)) != 0) {
          iVar19 = local_70 * 8;
          iVar18 = param_1 + 0x1ae8 + iVar19;
          uVar20 = (uint)*(ushort *)(puVar17 + 6);
          uVar6 = *(ushort *)((int)puVar17 + 0x1a);
          uVar16 = (uint)uVar6;
          uVar7 = puVar1[1];
          if (uVar20 != (ushort)puVar1[2]) {
            puVar1[2] = *(ushort *)(puVar17 + 6);
            *(ushort *)(param_1 + 0x1ae8 + iVar19) =
                 *(ushort *)(param_1 + 0x1ae8 + iVar19) & 0xf87f |
                 (ushort)(((uVar20 * 0xb5 >> 7 & 1 | uVar20 * 0x177 >> 8 & 2 |
                            uVar20 * 0x19f >> 6 & 4 | uVar20 * 0x1bb >> 5 & 8) ^ 0xf) << 7);
          }
          uVar8 = *(ushort *)(puVar17 + 7);
          uVar20 = (uint)uVar8;
          uVar9 = puVar1[3];
          if (uVar16 != uVar7) {
            puVar1[1] = uVar6;
            *(uint *)(param_1 + 0x1ae8 + iVar19) =
                 *(uint *)(param_1 + 0x1ae8 + iVar19) & 0xfffe1fff |
                 ((uVar16 * 0xc3 >> 8 & 1 | uVar16 * 0x165 >> 9 & 2 | uVar16 * 0xb >> 8 & 4 |
                  uVar16 * 0xcb >> 6 & 8) ^ 10) << 0xd;
          }
          uVar6 = *(ushort *)((int)puVar17 + 0x22);
          uVar16 = (uint)uVar6;
          uVar7 = puVar1[6];
          if (uVar20 != uVar9) {
            puVar1[3] = uVar8;
            *(byte *)(iVar18 + 3) =
                 *(byte *)(iVar18 + 3) & 0xf0 |
                 ((byte)(uVar20 * 0x11 >> 4) & 1 | (byte)(uVar20 * 0x37 >> 6) & 2 |
                  (byte)(uVar20 * 0x51 >> 7) & 4 | (byte)(uVar20 * 0x15 >> 6) & 8) ^ 0xc;
          }
          sVar10 = *(short *)(puVar17 + 10);
          sVar11 = puVar1[9];
          if (uVar16 != uVar7) {
            puVar1[6] = uVar6;
            *(byte *)(iVar18 + 5) =
                 *(byte *)(iVar18 + 5) & 0xf0 |
                 ((byte)(uVar16 * 0x11 >> 4) & 1 | (byte)(uVar16 * 0x37 >> 6) & 2 |
                  (byte)(uVar16 * 0x51 >> 7) & 4 | (byte)(uVar16 * 0x15 >> 6) & 8) ^ 0xc;
          }
          sVar12 = *(short *)((int)puVar17 + 0x2e);
          sVar13 = puVar1[0xc];
          if (sVar10 != sVar11) {
            puVar1[9] = sVar10;
            *(byte *)(iVar18 + 6) = *(byte *)(iVar18 + 6) & 0xcf | ((byte)sVar10 & 3) << 4;
          }
          uVar6 = *(ushort *)((int)puVar17 + 0x1e);
          uVar16 = (uint)uVar6;
          uVar7 = puVar1[4];
          if (sVar12 != sVar13) {
            puVar1[0xc] = sVar12;
            *(byte *)(iVar18 + 7) = *(byte *)(iVar18 + 7) & 0xfb | ((byte)sVar12 & 1) << 2;
          }
          uVar8 = *(ushort *)(puVar17 + 9);
          uVar20 = (uint)uVar8;
          uVar9 = puVar1[7];
          if (uVar16 != uVar7) {
            puVar1[4] = uVar6;
            *(byte *)(iVar18 + 3) =
                 *(byte *)(iVar18 + 3) & 0xf |
                 (((byte)(uVar16 * 0x11 >> 4) & 1 | (byte)(uVar16 * 0x37 >> 6) & 2 |
                   (byte)(uVar16 * 0x51 >> 7) & 4 | (byte)(uVar16 * 0x15 >> 6) & 8) ^ 0xc) << 4;
          }
          sVar10 = *(short *)((int)puVar17 + 0x2a);
          sVar11 = puVar1[10];
          if (uVar20 != uVar9) {
            puVar1[7] = uVar8;
            *(byte *)(iVar18 + 5) =
                 *(byte *)(iVar18 + 5) & 0xf |
                 (((byte)(uVar20 * 0x11 >> 4) & 1 | (byte)(uVar20 * 0x37 >> 6) & 2 |
                   (byte)(uVar20 * 0x51 >> 7) & 4 | (byte)(uVar20 * 0x15 >> 6) & 8) ^ 0xc) << 4;
          }
          sVar12 = *(short *)(puVar17 + 0xc);
          sVar13 = puVar1[0xd];
          if (sVar10 != sVar11) {
            puVar1[10] = sVar10;
            *(byte *)(iVar18 + 6) = *(byte *)(iVar18 + 6) & 0x3f | (char)sVar10 << 6;
          }
          uVar6 = *(ushort *)(puVar17 + 8);
          uVar16 = (uint)uVar6;
          uVar7 = puVar1[5];
          if (sVar12 != sVar13) {
            puVar1[0xd] = sVar12;
            *(byte *)(iVar18 + 7) = *(byte *)(iVar18 + 7) & 0xf7 | ((byte)sVar12 & 1) << 3;
          }
          uVar8 = *(ushort *)((int)puVar17 + 0x26);
          uVar20 = (uint)uVar8;
          uVar9 = puVar1[8];
          if (uVar16 != uVar7) {
            puVar1[5] = uVar6;
            *(byte *)(iVar18 + 4) =
                 *(byte *)(iVar18 + 4) & 0xf |
                 (((byte)(uVar16 * 0x11 >> 4) & 1 | (byte)(uVar16 * 0x37 >> 6) & 2 |
                   (byte)(uVar16 * 0x51 >> 7) & 4 | (byte)(uVar16 * 0x15 >> 6) & 8) ^ 0xc) << 4;
          }
          sVar10 = *(short *)(puVar17 + 0xb);
          sVar11 = puVar1[0xb];
          if (uVar20 != uVar9) {
            puVar1[8] = uVar8;
            *(byte *)(iVar18 + 6) =
                 *(byte *)(iVar18 + 6) & 0xf0 |
                 ((byte)(uVar20 * 0x11 >> 4) & 1 | (byte)(uVar20 * 0x37 >> 6) & 2 |
                  (byte)(uVar20 * 0x51 >> 7) & 4 | (byte)(uVar20 * 0x15 >> 6) & 8) ^ 0xc;
          }
          sVar12 = *(short *)((int)puVar17 + 0x32);
          sVar13 = puVar1[0xe];
          if (sVar10 != sVar11) {
            puVar1[0xb] = sVar10;
            *(byte *)(iVar18 + 7) = *(byte *)(iVar18 + 7) & 0xfc | (byte)sVar10 & 3;
          }
          fVar2 = (float)puVar17[0xd];
          fVar3 = *(float *)(puVar1 + 0x12);
          if (sVar12 != sVar13) {
            puVar1[0xe] = sVar12;
            *(byte *)(iVar18 + 7) = *(byte *)(iVar18 + 7) & 0xef | ((byte)sVar12 & 1) << 4;
          }
          fVar4 = (float)puVar17[0xe];
          fVar5 = *(float *)(puVar1 + 0x14);
          if (fVar2 != fVar3) {
            *(float *)(puVar1 + 0x12) = fVar2;
            if (FLOAT_001c5bf0 < fVar2) {
              cVar14 = (FLOAT_001c5c10 < fVar2) + '\x02';
            }
            else {
              cVar14 = '\x01';
            }
            *(byte *)(iVar18 + 1) = *(byte *)(iVar18 + 1) & 0xe7 | cVar14 * '\b';
          }
          if (fVar4 != fVar5) {
            *(float *)(puVar1 + 0x14) = fVar4;
            if (FLOAT_001c5bf0 < fVar4) {
              cVar14 = (FLOAT_001c5c10 < fVar4) + '\x02';
            }
            else {
              cVar14 = '\x01';
            }
            *(byte *)(iVar18 + 2) = *(byte *)(iVar18 + 2) & 0xf9 | cVar14 * '\x02';
          }
        }
      }
      local_70 = local_70 + 1;
      local_28 = local_28 + 4;
      local_24 = local_24 + 0x7c;
      local_20 = local_20 + 0xcc;
      local_6c = local_6c >> 1;
    } while (local_6c != 0);
  }
  *(uint *)(param_1 + 0x278) = *(uint *)(param_1 + 0x278) | 0x200;
  return;
}

/* FUN_000a7e07 @ 0xa7e07 (1006 bytes) */
int FUN_000a7e07(param_1, param_2)
  int param_1;
  int param_2;
{
  float fVar1;
  float fVar2;
  byte bVar3;
  short sVar4;
  int iVar5;
  byte bVar6;
  bool bVar7;
  byte bVar8;
  byte bVar9;
  undefined4 uVar10;
  uint uVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  
  bVar8 = *(byte *)(param_2 + 0x30dc) & 1;
  bVar6 = bVar8 * '\x02';
  bVar3 = *(byte *)(param_1 + 0x44);
  *(byte *)(param_1 + 0x44) = bVar3 & 0xfd | bVar6;
  bVar9 = *(byte *)(param_2 + 0x30dd) & 1;
  *(byte *)(param_1 + 0x44) = bVar3 & 0xf9 | bVar6 | bVar9 << 2;
  if (bVar8 != 0 || bVar9 != 0) {
    *(undefined1 *)(param_1 + 0x2f) = 0;
    *(byte *)(param_1 + 0x1808) = *(byte *)(param_1 + 0x1808) | 4;
    *(undefined1 *)(param_1 + 0x2940) = 1;
  }
  *(undefined4 *)(param_1 + 0xec) = *(undefined4 *)(param_2 + 0x30e4);
  fVar1 = *(float *)(param_2 + 0x30c0);
  *(float *)(param_1 + 0xf4) = fVar1;
  fVar14 = *(float *)((int)&UINT_000013c4 + param_1);
  fVar12 = fVar1;
  if (fVar1 <= fVar14) {
    fVar12 = fVar14;
  }
  *(float *)(param_1 + 0x100) = fVar12;
  if (fVar1 <= (float)*(uint *)((int)&UINT_000013d0 + param_1)) {
    *(uint *)(param_1 + 0x108) = *(uint *)((int)&UINT_000013d0 + param_1);
  }
  else {
    *(int *)(param_1 + 0x108) = (int)fVar1;
  }
  fVar1 = *(float *)(param_2 + 0x30c4);
  *(float *)(param_1 + 0xf8) = fVar1;
  fVar12 = *(float *)((int)&UINT_000013c8 + param_1);
  fVar2 = fVar1;
  if (fVar12 <= fVar1) {
    fVar2 = fVar12;
  }
  *(float *)(param_1 + 0x104) = fVar2;
  if ((float)*(uint *)(param_1 + 0x13d4) <= fVar1) {
    *(uint *)(param_1 + 0x10c) = *(uint *)(param_1 + 0x13d4);
  }
  else {
    *(int *)(param_1 + 0x10c) = (int)fVar1;
  }
  *(undefined4 *)(param_1 + 0xf0) = *(undefined4 *)(param_2 + 0x30bc);
  fVar1 = *(float *)(param_2 + 0x30bc);
  fVar2 = *(float *)((int)&UINT_000013cc + param_1);
  fVar13 = fVar14;
  if ((fVar14 < fVar1) && (fVar13 = fVar12, fVar1 < fVar12)) {
    fVar13 = (float)(int)((fVar1 - fVar14) / fVar2 + FLOAT_001c5bd4) * fVar2 + fVar14;
  }
  *(float *)(param_1 + 0xe0) = fVar13;
  fVar1 = *(float *)(param_2 + 0x30bc);
  fVar13 = fVar14;
  if ((fVar14 < fVar1) && (fVar13 = fVar12, fVar1 < fVar12)) {
    fVar13 = fVar14 + fVar2 * (float)(int)((fVar1 - fVar14) / fVar2 + FLOAT_001c5bd4);
  }
  *(int *)(param_1 + 0xe4) = (int)fVar13;
  *(undefined4 *)(param_1 + 0xfc) = *(undefined4 *)(param_2 + 0x30c8);
  *(undefined4 *)(param_1 + 0x110) = *(undefined4 *)(param_2 + 0x30cc);
  *(undefined4 *)(param_1 + 0x114) = *(undefined4 *)(param_2 + 0x30d0);
  *(undefined4 *)(param_1 + 0x118) = *(undefined4 *)(param_2 + 0x30d4);
  fVar1 = FLOAT_001c5ba4;
  *(float *)(param_1 + 0x11c) = FLOAT_001c5ba4;
  if (((((fVar1 != *(float *)(param_2 + 0x30cc)) ||
        (NAN(fVar1) || NAN(*(float *)(param_2 + 0x30cc)))) || (*(float *)(param_2 + 0x30d0) != 0.0))
      || ((NAN(*(float *)(param_2 + 0x30d0)) || (*(float *)(param_2 + 0x30d4) != 0.0)))) ||
     (NAN(*(float *)(param_2 + 0x30d4)))) {
    uVar11 = *(uint *)(param_1 + 0xe8) | 1;
    *(uint *)(param_1 + 0xe8) = uVar11;
    *(byte *)(param_1 + 0x1875) = *(byte *)(param_1 + 0x1875) | 1;
    if (*(int *)(*(int *)(param_1 + 4) + 0x1cc) == 0) {
      *(uint *)(param_1 + 0x1928) =
           *(uint *)(param_1 + 0x1928) & 0xfffffffd | (*(uint *)(param_1 + 0x1928) >> 1 ^ 1) & 1 | 2
      ;
    }
    sVar4 = *(short *)(param_2 + 0x30e2);
  }
  else {
    uVar11 = *(uint *)(param_1 + 0xe8) & 0xfffffffe;
    *(uint *)(param_1 + 0xe8) = uVar11;
    *(byte *)(param_1 + 0x1875) = *(byte *)(param_1 + 0x1875) & 0xfe;
    *(uint *)(param_1 + 0x1928) =
         *(uint *)(param_1 + 0x1928) & 0xfffffffd | *(uint *)(param_1 + 0x1928) >> 1 & 1;
    sVar4 = *(short *)(param_2 + 0x30e2);
  }
  if (sVar4 == 0x60b4) {
    uVar11 = uVar11 & 0xfffffff7;
    *(uint *)(param_1 + 0xe8) = uVar11;
    iVar5 = *(int *)(param_1 + 0xe4);
  }
  else {
    uVar11 = uVar11 | 8;
    *(uint *)(param_1 + 0xe8) = uVar11;
    iVar5 = *(int *)(param_1 + 0xe4);
  }
  if (((iVar5 < 2) && ((uVar11 & 1) == 0)) && (*(int *)(param_1 + 0xec) == 0)) {
    bVar7 = false;
    uVar10 = 0;
  }
  else {
    bVar7 = true;
    uVar10 = 1;
  }
  *(undefined4 *)(param_1 + 0x1940) = uVar10;
  if (bVar7) {
    fVar14 = *(float *)(*(int *)(param_1 + 4) + 0x2a54);
    fVar12 = (fVar14 + fVar14) * *(float *)(param_2 + 0x1810);
    fVar14 = *(float *)(*(int *)(param_1 + 4) + 0x2a58);
    fVar14 = (fVar14 + fVar14) * *(float *)(param_2 + 0x1814);
    if (fVar12 == 0.0) {
      *(undefined4 *)(param_1 + 400) = 0;
    }
    else {
      *(float *)(param_1 + 400) = fVar1 / fVar12;
    }
    if (fVar14 == 0.0) {
      *(undefined4 *)(param_1 + 0x194) = 0;
    }
    else {
      *(float *)(param_1 + 0x194) = fVar1 / fVar14;
    }
    *(float *)(param_1 + 0x198) =
         SQRT(*(float *)(param_1 + 400) * *(float *)(param_1 + 400) +
              *(float *)(param_1 + 0x194) * *(float *)(param_1 + 0x194));
  }
  *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0xc;
  *(undefined1 *)(param_1 + 0x29) = 1;
  return;
}

/* FUN_000a81f5 @ 0xa81f5 (9358 bytes) */
void FUN_000a81f5(int param_1,uint *param_2,int param_3,int param_4,int param_5,int param_6,
                 float param_7)

{
  double *pdVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  char cVar7;
  byte bVar8;
  uint uVar9;
  int iVar10;
  byte bVar11;
  byte bVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  float fVar18;
  uint uVar19;
  uint uVar20;
  float *pfVar21;
  int unaff_EBX;
  int unaff_EBP;
  float unaff_ESI;
  uint uVar22;
  int iVar23;
  int unaff_EDI;
  bool bVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  float fVar33;
  int unaff_retaddr;
  int local_e8;
  undefined4 *local_dc;
  float *local_d4;
  int local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  byte local_bd;
  byte local_bc;
  uint local_9c;
  int local_80;
  int local_78;
  uint local_74;
  int local_70;
  int local_3c;
  uint local_30;
  int local_1c;
  int local_18;
  int local_14;
  
  iVar16 = *(int *)(param_1 + 4);
  local_9c = *param_2;
  local_30 = param_2[2];
  if ((((local_9c & 0x20000180) != 0) || (*(int *)(iVar16 + 0x2a48) != *(int *)(iVar16 + 0x15c))) ||
     (*(int *)(iVar16 + 0x2a4c) != *(int *)(iVar16 + 0x160))) {
    FUN_00017873(iVar16);
  }
  if (*(char *)(iVar16 + 0x2a43) != '\0') {
    local_30 = local_30 | 1;
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x400;
    *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x1002;
    *(undefined1 *)(param_1 + 0x29) = 1;
  }
  if (*(char *)(iVar16 + 0x2b7d) != '\0') {
    *(byte *)(param_1 + 0x1490) = (byte)(*(uint *)(*(int *)(param_1 + 4) + 0x154) >> 6) & 1;
    *(byte *)(param_1 + 0x1491) = (byte)(*(uint *)(*(int *)(param_1 + 4) + 0x154) >> 7) & 1;
    uVar13 = local_9c | 0x200;
    if (*(char *)(param_1 + 0x1490) == '\0') {
      uVar13 = local_9c;
    }
    local_9c = uVar13 | 0x4000001;
    local_30 = local_30 | 1;
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x4000;
    *(undefined1 *)(param_1 + 0x29) = 1;
  }
  uVar13 = param_2[3];
  iVar3 = *(int *)(iVar16 + 0x10);
  iVar10 = *(int *)(iVar3 + 0x3e28);
  if (*(int *)(iVar16 + 0x1cc) == 0) {
    *(undefined4 *)(iVar16 + 0x26c0) = 0;
    *(undefined4 *)(iVar16 + 0x26c4) = 0;
    if (local_30 == 0 && uVar13 == 0) goto LAB_000a9664;
    if ((uVar13 & 0x4400000) != 0) {
      bVar24 = *(int *)(param_1 + -0x74) != 0;
      bVar11 = *(byte *)(param_1 + 0x45);
      if (bVar24 == (bool)(bVar11 >> 3 & 1)) {
        if (((!bVar24) &&
            (local_bc = *(byte *)(param_1 + 0x44), (local_bc & 1) != *(byte *)(iVar3 + 0x2d4a))) &&
           (*(char *)(iVar3 + 0x4304) == '\0')) goto LAB_000aa083;
      }
      else {
        if (bVar24) {
          *(uint *)(param_1 + 0x1928) =
               *(uint *)(param_1 + 0x1928) & 0xfffffffd | *(uint *)(param_1 + 0x1928) >> 1 & 1;
          *(undefined1 *)(param_1 + 299) = 1;
          *(byte *)(param_1 + 0x45) = bVar11 | 0x18;
          uVar9 = *(uint *)(param_1 + 0x38);
        }
        else {
          local_bc = *(byte *)(param_1 + 0x44);
LAB_000aa083:
          uVar9 = (uint)(*(byte *)(param_1 + 0x1875) & 1);
          *(uint *)(param_1 + 0x1928) =
               *(uint *)(param_1 + 0x1928) & 0xfffffffd |
               (*(uint *)(param_1 + 0x1928) >> 1 ^ uVar9) & 1 | uVar9 * 2;
          if (*(char *)(iVar3 + 0x4304) == '\0') {
            *(undefined1 *)(param_1 + 0x2475) = 1;
            *(byte *)(param_1 + 0x44) = local_bc & 0xfe | *(byte *)(iVar3 + 0x2d4a) & 1;
          }
          else if ((local_bc & 1) != 0) {
            *(byte *)(param_1 + 0x44) = local_bc & 0xfe;
            *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
          }
          *(byte *)(param_1 + 0x45) = bVar11 & 0xe7;
          *(undefined1 *)(param_1 + 299) = 1;
          (**(code **)(param_1 + 0x12b0))(param_1);
          uVar9 = *(uint *)(param_1 + 0x38) | 0x58a60;
          *(uint *)(param_1 + 0x38) = uVar9;
          *(ushort *)(param_1 + 0x34) =
               *(ushort *)(param_1 + 0x34) | (short)(1 << (*(byte *)(param_1 + 0x13b6) & 0x1f)) - 1U
          ;
          *(undefined1 *)(param_1 + 0x29) = 1;
        }
        if (*(char *)(iVar3 + 0x4304) == '\0') {
          if ((*(byte *)(param_1 + 0x44) & 1) == 0) {
            *(byte *)(param_1 + 0x18a4) =
                 *(byte *)(param_1 + 0x18a4) & 0xf9 | (*(byte *)(param_1 + 0x45) & 1) << 2;
          }
          else {
            bVar8 = (*(short *)(iVar3 + 0x2d48) == -0x7e06) << 2;
            bVar11 = *(byte *)(param_1 + 0x18a4);
            *(byte *)(param_1 + 0x18a4) = bVar11 & 0xfb | bVar8;
            *(byte *)(param_1 + 0x18a4) =
                 bVar11 & 0xf9 | bVar8 | (*(byte *)(iVar3 + 0x2d4c) & 1) * '\x02';
          }
        }
        else {
          *(byte *)(param_1 + 0x18a4) =
               (*(byte *)(param_1 + 0x45) & 1) << 2 | *(byte *)(param_1 + 0x18a4) & 0xf9 |
               ((*(uint *)(param_1 + 0x44) & 0x2001000) == 0x2001000) * '\x02';
        }
        *(uint *)(param_1 + 0x38) = uVar9 | 0x1000;
        *(undefined1 *)(param_1 + 0x29) = 1;
        *(byte *)(param_1 + 0x2d) = *(byte *)(param_1 + 0x2d) | 0xf;
      }
    }
    if ((uVar13 & 0x7000000) != 0) {
      bVar11 = *(byte *)(param_1 + 0x2e) | 2;
      *(undefined1 *)(param_1 + 0x29) = 1;
      if ((uVar13 & 0x5000000) != 0) {
        bVar8 = *(byte *)(param_1 + 0x46);
        bVar6 = bVar8 >> 2 & 1;
        bVar12 = bVar8 & 1;
        bVar11 = *(byte *)(param_1 + 0x2e) | 3;
        if (*(int *)(param_1 + -0x70) == 0) {
          if (bVar6 == 0) {
            if (bVar12 != 0) {
              *(byte *)(param_1 + 0x1876) = *(byte *)(param_1 + 0x1876) & 0xfd;
              bVar6 = *(byte *)(param_1 + 0x45);
              *(byte *)(param_1 + 0x45) = bVar6 & 0xbf;
              *(byte *)(param_1 + 0x46) = bVar8 & 0xfe;
              if ((bVar8 & 2) != 0) {
                *(byte *)(param_1 + 0x46) = bVar8 & 0xfc;
                *(byte *)(param_1 + 0x45) = bVar6 & 0x3f;
                *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
                *(undefined1 *)(param_1 + 0x29) = 1;
              }
            }
          }
          else {
            *(byte *)(param_1 + 0x1876) = *(byte *)(param_1 + 0x1876) & 0xfd;
            *(byte *)(param_1 + 0x45) = *(byte *)(param_1 + 0x45) & 0xbf;
            *(byte *)(param_1 + 0x46) = bVar8 & 0xfb;
            FUN_00088206(param_1);
          }
        }
        else {
          local_bd = bVar8;
          if (*(char *)(param_1 + 0x279c) == '\0') {
            if (bVar12 == 0) {
              if (bVar6 != 0) {
                *(byte *)(param_1 + 0x1876) = *(byte *)(param_1 + 0x1876) & 0xfd;
                *(byte *)(param_1 + 0x45) = *(byte *)(param_1 + 0x45) & 0xbf;
                *(byte *)(param_1 + 0x46) = bVar8 & 0xfb;
                FUN_00088206(param_1);
                local_bd = *(byte *)(param_1 + 0x46);
              }
              *(byte *)(param_1 + 0x1876) = *(byte *)(param_1 + 0x1876) | 2;
              bVar8 = *(byte *)(param_1 + 0x45);
              *(byte *)(param_1 + 0x45) = bVar8 | 0x40;
              *(byte *)(param_1 + 0x46) = local_bd | 1;
              bVar6 = *(byte *)(*(int *)(param_1 + 0x1144) + 0x6c) & 1;
              *(byte *)(param_1 + 0x46) = local_bd & 0xfd | 1 | bVar6 * '\x02';
              if (bVar6 != 0) {
                *(byte *)(param_1 + 0x45) = bVar8 | 0xc0;
                *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
                *(undefined1 *)(param_1 + 0x29) = 1;
              }
            }
            FUN_0003da3d(param_1 + -0x240,param_2,0);
          }
          else if (bVar6 == 0) {
            if (bVar12 == 0) {
              bVar6 = *(byte *)(param_1 + 0x45);
              bVar12 = *(byte *)(param_1 + 0x1876);
            }
            else {
              bVar12 = *(byte *)(param_1 + 0x1876) & 0xfd;
              *(byte *)(param_1 + 0x1876) = bVar12;
              bVar2 = *(byte *)(param_1 + 0x45);
              bVar6 = bVar2 & 0xbf;
              *(byte *)(param_1 + 0x45) = bVar6;
              *(byte *)(param_1 + 0x46) = bVar8 & 0xfe;
              local_bd = bVar8 & 0xfe;
              if ((bVar8 & 2) != 0) {
                *(byte *)(param_1 + 0x46) = bVar8 & 0xfc;
                bVar6 = bVar2 & 0x3f;
                *(byte *)(param_1 + 0x45) = bVar6;
                *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
                *(undefined1 *)(param_1 + 0x29) = 1;
                local_bd = bVar8 & 0xfc;
              }
            }
            *(byte *)(param_1 + 0x8c) = *(byte *)(param_1 + 0x8c) | 1;
            *(byte *)(param_1 + 0x1876) = bVar12 | 2;
            *(byte *)(param_1 + 0x45) = bVar6 | 0x40;
            *(byte *)(param_1 + 0x46) = local_bd | 4;
            FUN_00088206(param_1);
          }
        }
        *(undefined1 *)(param_1 + 0x2475) = 1;
      }
      iVar10 = *(int *)(param_1 + 4);
      if ((*(char *)(*(int *)(iVar10 + 0x10) + 0x2e2d) == '\0') ||
         ((*(byte *)(param_1 + 0x45) & 0x40) != 0)) {
LAB_000a8e0b:
        uVar9 = 0;
      }
      else {
        cVar7 = FUN_00017bd8(iVar10,*(undefined4 *)(iVar10 + 0x26a0));
        if (cVar7 != '\0') {
          iVar10 = *(int *)(param_1 + 4);
          goto LAB_000a8e0b;
        }
        uVar9 = 1;
        iVar10 = *(int *)(param_1 + 4);
      }
      uVar22 = *(uint *)(param_1 + 0x1928);
      uVar19 = (uVar22 >> 4 ^ uVar9) & 1;
      uVar20 = uVar19 | uVar22 & 0xffffffef | uVar9 << 4;
      *(uint *)(param_1 + 0x1928) = uVar20;
      if (((*(char *)(*(int *)(iVar10 + 0x10) + 0x2e2c) == '\0') ||
          ((*(byte *)(param_1 + 0x45) & 0x40) != 0)) ||
         (*(short *)(*(int *)(iVar10 + 0x10) + 0x2e28) == -1)) {
        uVar14 = 0;
      }
      else {
        uVar14 = 1;
      }
      *(uint *)(param_1 + 0x1928) =
           uVar19 | uVar22 & 0xffffffe7 | uVar9 << 4 | (uVar20 >> 3 ^ uVar14) & 1 | uVar14 * 8;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x2000;
      *(byte *)(param_1 + 0x2e) = bVar11;
    }
    if ((local_30 & 1) != 0) {
      *(ushort *)(iVar16 + 0x15fc) =
           (ushort)*(byte *)(iVar16 + 0x2a5c) * (short)*(undefined4 *)(iVar16 + 0x15c);
      *(ushort *)(iVar16 + 0x15fa) =
           (ushort)*(byte *)(iVar16 + 0x2a5d) * (short)*(undefined4 *)(iVar16 + 0x160);
      if (DOUBLE_001cf330 == *(double *)(*(int *)(iVar16 + 0x10) + 0x1830)) {
        pdVar1 = (double *)(*(int *)(iVar16 + 0x10) + 0x1838);
        if ((DOUBLE_001cf330 == *pdVar1) && (!NAN(DOUBLE_001cf330) && !NAN(*pdVar1))) {
          *(byte *)(iVar16 + 0x2cd) = *(byte *)(iVar16 + 0x2cd) | 2;
        }
      }
      if ((*(byte *)(iVar16 + 0x2a5c) < 2) || (*(byte *)(iVar16 + 0x2a5d) < 2)) {
        *(undefined1 *)(iVar16 + 0x2690) = 0;
      }
      else {
        *(undefined1 *)(iVar16 + 0x2690) = 1;
      }
      *(uint *)(iVar16 + 0x278) = *(uint *)(iVar16 + 0x278) | 0x400;
      *(uint *)(iVar16 + 0x27c) = *(uint *)(iVar16 + 0x27c) | 3;
      *(undefined1 *)(iVar16 + 0x269) = 1;
    }
    if ((uVar13 & 0x200000) != 0) {
      uVar9 = local_30 | 0xf0;
      if (*(char *)(iVar3 + 0x4301) == '\0') {
        uVar9 = local_30;
      }
      iVar10 = *(int *)(iVar16 + 0x10);
      if ((*(char *)(iVar10 + 0x4301) == '\0') || (*(byte *)(iVar16 + 0x15f4) == 0)) {
        local_80 = 0;
        (*(unsigned char *)((unsigned char *)&(local_80) + 0)) = '\0';
      }
      else {
        local_80 = 0;
        uVar22 = 0;
        do {
          local_80 = (local_80 + 1) -
                     (uint)((1 << ((byte)uVar22 & 0x1f) &
                            (1 << (*(byte *)(iVar10 + 0x4300) & 0x1f)) - 1U) == 0);
          uVar22 = uVar22 + 1;
        } while (uVar22 < *(byte *)(iVar16 + 0x15f4));
      }
      *(char *)(iVar16 + 0x2d0) = (char)local_80;
      if ((local_80 == 0) || (*(char *)(iVar10 + 0x4302) == '\0')) {
        cVar7 = '\0';
      }
      else {
        cVar7 = '\x01';
      }
      *(char *)(iVar16 + 0x2d1) = (char)local_80 - cVar7;
      uVar22 = *(uint *)(iVar16 + 0x278);
      *(uint *)(iVar16 + 0x278) = uVar22 | 0x800;
      *(undefined1 *)(iVar16 + 0x269) = 1;
      local_30 = uVar9;
      if (*(char *)(*(int *)(iVar16 + 0x10) + 0x2d4a) != '\0') {
        *(uint *)(iVar16 + 0x278) = uVar22 | 0x820;
      }
    }
    if (local_30 != 0) {
      if ((local_30 & 0xff0000) != 0) {
        local_74 = local_30 >> 0x10 & 0xff;
        if (local_74 != 0) {
          local_78 = 0;
          do {
            if ((local_74 & 1) != 0) {
              bVar24 = (float)(local_78 * 0x40 + *(int *)(iVar16 + 0x10) + 0x1c60) == FLOAT_001c5ba4
              ;
              if (((((((local_1c == 0 && local_18 == 0) && local_14 == 0) && bVar24) &&
                    (((unaff_EBX == 0 && unaff_EDI == 0) && unaff_EBP == 0) &&
                    FLOAT_001c5ba4 == unaff_ESI)) &&
                   (((unaff_retaddr == 0 && param_1 == 0) && param_3 == 0) &&
                   (uint *)&FLOAT_001c5ba4 == param_2)) &&
                   (((param_4 == 0 && param_5 == 0) && param_6 == 0) && FLOAT_001c5ba4 == param_7))
                 && (*(char *)(local_78 + 0x2784 + *(int *)(iVar16 + 0x25c)) != '\0')) {
                uVar9 = ~(0x10000 << ((byte)local_78 & 0x1f));
              }
              else {
                *(bool *)(local_78 + 0x2784 + *(int *)(iVar16 + 0x25c)) =
                     (((((local_1c == 0 && local_18 == 0) && local_14 == 0) && bVar24) &&
                      (((unaff_EBX == 0 && unaff_EDI == 0) && unaff_EBP == 0) &&
                      FLOAT_001c5ba4 == unaff_ESI)) &&
                     (((unaff_retaddr == 0 && param_1 == 0) && param_3 == 0) &&
                     (uint *)&FLOAT_001c5ba4 == param_2)) &&
                     (((param_4 == 0 && param_5 == 0) && param_6 == 0) && FLOAT_001c5ba4 == param_7)
                ;
                *(uint *)(iVar16 + 0x278) = *(uint *)(iVar16 + 0x278) | 0x80;
                uVar9 = 1 << ((byte)local_78 & 0x1f);
                *(ushort *)(iVar16 + 0x272) = *(ushort *)(iVar16 + 0x272) | (ushort)uVar9;
                *(uint *)(iVar16 + 0x280) = *(uint *)(iVar16 + 0x280) | uVar9;
                *(undefined1 *)(iVar16 + 0x269) = 1;
                uVar9 = 0xffffffff;
              }
              local_30 = local_30 & uVar9;
            }
            local_78 = local_78 + 1;
            local_74 = local_74 >> 1;
          } while (local_74 != 0);
          if (local_30 == 0) goto LAB_000a90e4;
        }
        *(undefined1 *)(iVar16 + 0x26b5) = 1;
      }
LAB_000a90e4:
      if (((local_30 & 0x40000000) != 0) && (*(char *)(iVar3 + 0x2d4a) != '\0')) {
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
        *(undefined1 *)(param_1 + 0x29) = 1;
      }
      if ((local_30 & 0x3f0000f8) != 0) {
        ((int (*)())FUN_000a694a)();
      }
      if (((local_30 & 0x800000f0) != 0) &&
         (((*(char *)(iVar3 + 0x24ae) != '\0' || ((int)local_30 < 0)) &&
          (*(char *)(iVar3 + 0x2d4a) != '\0')))) {
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
        *(undefined1 *)(param_1 + 0x29) = 1;
      }
      if ((local_30 & 0x3f000008) != 0) {
        ((int (*)())FUN_000a7070)();
      }
    }
    if ((uVar13 & 0x1007ffff) != 0) {
      if ((uVar13 & 0x7ffff) != 0) {
        if ((*(char *)(iVar3 + 0x4304) == '\0') || (*(int *)(param_1 + -0x74) != 0)) {
          local_bc = *(byte *)(param_1 + 0x44) & 0xfe | *(byte *)(iVar3 + 0x2d4a) & 1;
          *(byte *)(param_1 + 0x44) = local_bc;
        }
        else {
          local_bc = *(byte *)(param_1 + 0x44) & 0xfe;
          *(byte *)(param_1 + 0x44) = local_bc;
        }
        if (*(char *)(iVar3 + 0x4304) == '\0') {
          if ((local_bc & 1) == 0) {
            bVar11 = *(byte *)(param_1 + 0x18a4) & 0xf9 | (*(byte *)(param_1 + 0x45) & 1) << 2;
            *(byte *)(param_1 + 0x18a4) = bVar11;
          }
          else {
            bVar8 = (*(short *)(iVar3 + 0x2d48) == -0x7e06) << 2;
            bVar11 = *(byte *)(param_1 + 0x18a4);
            *(byte *)(param_1 + 0x18a4) = bVar11 & 0xfb | bVar8;
            bVar11 = bVar11 & 0xf9 | bVar8 | (*(byte *)(iVar3 + 0x2d4c) & 1) * '\x02';
            *(byte *)(param_1 + 0x18a4) = bVar11;
          }
        }
        else {
          bVar11 = *(byte *)(param_1 + 0x18a4) & 0xf9 | (*(byte *)(param_1 + 0x45) & 1) << 2 |
                   ((*(uint *)(param_1 + 0x44) & 0x2001000) == 0x2001000) * '\x02';
          *(byte *)(param_1 + 0x18a4) = bVar11;
        }
        if ((local_bc & 1) != 0) {
          *(undefined1 *)(param_1 + 0x2f) = 0;
        }
        if ((uVar13 & 1) != 0) {
          *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x10000;
          *(undefined4 *)(param_1 + 0x1810) = 0x1f;
          *(uint *)(param_1 + 0x180c) = *(uint *)(param_1 + 0x180c) | 7;
          *(undefined1 *)(param_1 + 0x29) = 1;
          if (*(char *)(iVar3 + 0x4304) == '\0') {
            if ((local_bc & 1) == 0) {
              *(byte *)(param_1 + 0x18a4) = bVar11 & 0xf9 | (*(byte *)(param_1 + 0x45) & 1) << 2;
            }
            else {
              bVar8 = (*(short *)(iVar3 + 0x2d48) == -0x7e06) << 2;
              *(byte *)(param_1 + 0x18a4) = bVar11 & 0xfb | bVar8;
              *(byte *)(param_1 + 0x18a4) =
                   bVar11 & 0xf9 | bVar8 | (*(byte *)(iVar3 + 0x2d4c) & 1) * '\x02';
            }
          }
          else {
            *(byte *)(param_1 + 0x18a4) =
                 bVar11 & 0xf9 | (*(byte *)(param_1 + 0x45) & 1) << 2 |
                 ((*(uint *)(param_1 + 0x44) & 0x2001000) == 0x2001000) * '\x02';
          }
        }
        *(undefined4 *)(param_1 + 0x88) = 0;
        local_3c = param_1;
        local_e8 = param_1;
        local_70 = 0;
        local_c4 = param_1 + 0x14a0;
        local_c8 = param_1 + 0x14f0;
        local_cc = param_1 + 0x14e0;
        local_d0 = param_1 + 0x14b0;
        local_d4 = (float *)(iVar3 + 0x2500);
        bVar11 = 0;
        local_dc = (undefined4 *)(param_1 + 0x14fc);
        iVar10 = iVar3;
        do {
          *(uint *)(param_1 + 0x88) =
               *(uint *)(param_1 + 0x88) | 1 << ((byte)local_70 & 0x1f) & *(uint *)(iVar3 + 0x2d40);
          if ((uVar13 & (0xc << (bVar11 & 0x1f) | 1U)) != 0) {
            *(undefined4 *)(local_e8 + 0x14a4) = *(undefined4 *)(iVar10 + 0x24f0);
            *(undefined4 *)(local_e8 + 0x14a8) = *(undefined4 *)(iVar10 + 0x24f4);
            *(undefined4 *)(local_e8 + 0x14ac) = *(undefined4 *)(iVar10 + 0x24f8);
            pfVar21 = (float *)(local_e8 + 0x14b0);
            *(undefined4 *)(local_e8 + 0x14b0) = *(undefined4 *)(iVar10 + 0x24fc);
            fVar18 = *local_d4;
            fVar27 = fVar18 * fVar18 + local_d4[1] * local_d4[1] + local_d4[2] * local_d4[2];
            fVar28 = 0.0;
            if (fVar27 <= 0.0) {
              local_dc[-0x12] = 0;
              local_dc[-0x11] = 0;
              local_dc[-0x10] = 0;
            }
            else if ((fVar27 != FLOAT_001c5ba4) || (NAN(fVar27) || NAN(FLOAT_001c5ba4))) {
              fVar30 = (float)(0x5f375a00 - ((uint)fVar27 >> 1));
              fVar27 = fVar27 * fVar30 * fVar30;
              fVar29 = FLOAT_001c5c10 - fVar27;
              fVar27 = fVar30 * FLOAT_001c5c48 * fVar29 *
                       (FLOAT_001c5c4c - fVar27 * fVar29 * fVar29);
              *(float *)(local_d0 + 4) = fVar18 * fVar27;
              *(float *)(local_d0 + 8) = fVar27 * local_d4[1];
              *(float *)(local_d0 + 0xc) = fVar27 * local_d4[2];
            }
            else {
              *(float *)(local_d0 + 4) = fVar18;
              *(float *)(local_d0 + 8) = local_d4[1];
              *(float *)(local_d0 + 0xc) = local_d4[2];
            }
            *(bool *)(local_e8 + 0x150c) = FLOAT_001c5bdc != *(float *)(iVar10 + 0x250c);
            *(undefined4 *)(local_e8 + 0x1504) = *(undefined4 *)(iVar10 + 0x250c);
            if (*(float *)(iVar10 + 0x2510) != 0.0) {
              *(float *)(local_e8 + 0x1508) = FLOAT_001c5ba4 / *(float *)(iVar10 + 0x2510);
            }
            fVar18 = 0.0;
            if ((*(char *)(iVar3 + 0x2d4d) == '\0') && (*(char *)(local_e8 + 0x150c) == '\0')) {
              if ((*pfVar21 == 0.0) && (!NAN(*pfVar21))) {
                fVar27 = (float)local_dc[-0x16];
                fVar30 = (float)local_dc[-0x15];
                fVar26 = fVar27 * fVar27 + fVar30 * fVar30;
                fVar29 = (float)local_dc[-0x14];
                fVar25 = fVar29 * fVar29 + fVar26;
                fVar31 = fVar18;
                fVar32 = fVar18;
                fVar33 = FLOAT_001c5ba4;
                if (0.0 < fVar25) {
                  if ((fVar25 != FLOAT_001c5ba4) || (NAN(fVar25) || NAN(FLOAT_001c5ba4))) {
                    fVar18 = (float)(0x5f375a00 - ((uint)fVar25 >> 1));
                    fVar28 = fVar25 * fVar18 * fVar18;
                    fVar31 = FLOAT_001c5c10 - fVar28;
                    fVar18 = fVar18 * FLOAT_001c5c48 * fVar31 *
                             (FLOAT_001c5c4c - fVar28 * fVar31 * fVar31);
                    fVar31 = fVar27 * fVar18;
                    fVar32 = fVar30 * fVar18;
                    fVar18 = fVar29 * fVar18;
                    fVar28 = fVar31 * fVar31 + fVar32 * fVar32;
                    fVar33 = fVar18 + FLOAT_001c5ba4;
                  }
                  else {
                    fVar28 = fVar26;
                    fVar18 = fVar29;
                    fVar31 = fVar27;
                    fVar32 = fVar30;
                    fVar33 = fVar29 + FLOAT_001c5ba4;
                  }
                }
                *(float *)(local_e8 + 0x14f4) = fVar31;
                *(float *)(local_e8 + 0x14f8) = fVar32;
                *(float *)(local_e8 + 0x14fc) = fVar18;
                fVar28 = fVar33 * fVar33 + fVar28;
                if (fVar28 <= 0.0) {
                  local_dc[-6] = 0;
                  local_dc[-5] = 0;
                  local_dc[-4] = 0;
                }
                else if ((fVar28 != FLOAT_001c5ba4) || (NAN(fVar28) || NAN(FLOAT_001c5ba4))) {
                  fVar18 = (float)(0x5f375a00 - ((uint)fVar28 >> 1));
                  fVar28 = fVar28 * fVar18 * fVar18;
                  fVar27 = FLOAT_001c5c10 - fVar28;
                  fVar18 = fVar18 * FLOAT_001c5c48 * fVar27 *
                           (FLOAT_001c5c4c - fVar28 * fVar27 * fVar27);
                  *(float *)(local_cc + 4) = fVar31 * fVar18;
                  *(float *)(local_cc + 8) = fVar32 * fVar18;
                  *(float *)(local_cc + 0xc) = fVar33 * fVar18;
                }
                else {
                  *(float *)(local_cc + 4) = fVar31;
                  *(float *)(local_cc + 8) = fVar32;
                  *(float *)(local_cc + 0xc) = fVar33;
                }
              }
            }
            else if ((*pfVar21 == 0.0) && (!NAN(*pfVar21))) {
              fVar18 = (float)local_dc[-0x16];
              fVar28 = fVar18 * fVar18 + (float)local_dc[-0x15] * (float)local_dc[-0x15] +
                       (float)local_dc[-0x14] * (float)local_dc[-0x14];
              if (fVar28 <= 0.0) {
                local_dc[-2] = 0;
                local_dc[-1] = 0;
                *local_dc = 0;
              }
              else if ((fVar28 != FLOAT_001c5ba4) || (NAN(fVar28) || NAN(FLOAT_001c5ba4))) {
                fVar27 = (float)(0x5f375a00 - ((uint)fVar28 >> 1));
                fVar28 = fVar28 * fVar27 * fVar27;
                fVar30 = FLOAT_001c5c10 - fVar28;
                fVar28 = fVar27 * FLOAT_001c5c48 * fVar30 *
                         (FLOAT_001c5c4c - fVar28 * fVar30 * fVar30);
                *(float *)(local_c8 + 4) = fVar18 * fVar28;
                *(float *)(local_c8 + 8) = fVar28 * *(float *)(local_c4 + 8);
                *(float *)(local_c8 + 0xc) = fVar28 * *(float *)(local_c4 + 0xc);
              }
              else {
                *(float *)(local_c8 + 4) = fVar18;
                *(undefined4 *)(local_c8 + 8) = *(undefined4 *)(local_c4 + 8);
                *(undefined4 *)(local_c8 + 0xc) = *(undefined4 *)(local_c4 + 0xc);
              }
            }
            *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
            *(byte *)(local_3c + 0x1814) = *(byte *)(local_3c + 0x1814) | 0x3f;
            *(byte *)(local_3c + 0x181c) = *(byte *)(local_3c + 0x181c) | 3;
            *(undefined1 *)(param_1 + 0x29) = 1;
          }
          local_70 = local_70 + 1;
          bVar11 = bVar11 + 2;
          local_d4 = local_d4 + 0x20;
          local_d0 = local_d0 + 0x6c;
          local_cc = local_cc + 0x6c;
          local_dc = local_dc + 0x1b;
          local_c8 = local_c8 + 0x6c;
          local_c4 = local_c4 + 0x6c;
          local_3c = local_3c + 1;
          local_e8 = local_e8 + 0x6c;
          iVar10 = iVar10 + 0x80;
        } while (local_70 != 8);
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
        *(undefined1 *)(param_1 + 0x29) = 1;
      }
      if ((uVar13 & 0x10000000) != 0) {
        *(undefined1 *)(param_1 + 0x29) = 1;
      }
    }
LAB_000a9664:
    uVar9 = param_2[1];
    uVar22 = param_2[4];
    uVar19 = uVar9 & 0xff0000;
    if (uVar22 != 0 || uVar19 != 0) {
      if (uVar19 != 0) {
        ((int (*)())FUN_000a6673)();
      }
      if (uVar22 != 0) {
        ((int (*)())FUN_000a767f)();
      }
    }
    if (local_9c != 0) {
      if ((local_9c & 1) != 0) {
        *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x1010;
        *(undefined1 *)(param_1 + 0x29) = 1;
      }
      if ((local_9c & 6) != 0) {
        *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x1018;
        *(undefined1 *)(param_1 + 0x29) = 1;
      }
      if ((local_9c & 0x200) != 0) {
        *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 1;
      }
      if ((local_9c & 0x10000000) != 0) {
        *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x20;
      }
      if ((local_9c & 0x8000000) != 0) {
        *(undefined1 *)(param_1 + 0x29) = 1;
        *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x40;
      }
      if ((local_9c & 0x4000000) != 0) {
        iVar23 = *(int *)(iVar3 + 0x3180);
        iVar15 = *(int *)(iVar3 + 0x3184);
        iVar17 = *(int *)(iVar3 + 0x3188);
        iVar10 = *(int *)(iVar3 + 0x318c);
        iVar4 = *(int *)(param_1 + -0xe4);
        iVar5 = *(int *)(param_1 + -0xe0);
        *(int *)(param_1 + 0x440) = iVar23;
        *(int *)(param_1 + 0x444) = iVar15;
        *(int *)(param_1 + 0x448) = iVar17;
        *(int *)(param_1 + 0x44c) = iVar10;
        if (*(char *)(iVar3 + 0x3190) == '\0') {
          *(undefined4 *)(param_1 + 0x1358) = 0;
          *(undefined4 *)(param_1 + 0x135c) = 0;
          *(int *)(param_1 + 0x1360) = iVar4;
          *(int *)(param_1 + 0x1364) = iVar5;
          *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 2;
        }
        else {
          if (*(char *)(param_1 + 0x293c) != '\0') {
            iVar15 = iVar5 - (iVar15 + iVar10);
          }
          iVar17 = iVar23 + iVar17;
          iVar10 = iVar15 + iVar10;
          if (iVar23 < 0) {
            iVar23 = 0;
          }
          if (iVar15 < 0) {
            iVar15 = 0;
          }
          if (iVar4 < iVar17) {
            iVar17 = iVar4;
          }
          if (iVar5 < iVar10) {
            iVar10 = iVar5;
          }
          *(int *)(param_1 + 0x1358) = iVar23;
          *(int *)(param_1 + 0x135c) = iVar15;
          *(int *)(param_1 + 0x1360) = iVar17;
          *(int *)(param_1 + 0x1364) = iVar10;
          *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 2;
        }
      }
      if ((local_9c & 0x800000) != 0) {
        iVar3 = *(int *)(*(int *)(param_1 + 4) + 0x10);
        if (((*(char *)(iVar3 + 0x3178) == '\0') || ((*(byte *)(param_1 + 0x45) & 0x40) != 0)) ||
           ((*(short *)(iVar3 + 0x3170) != 0x1b02 && (*(short *)(iVar3 + 0x3172) != 0x1b02)))) {
          uVar22 = 0;
        }
        else {
          uVar22 = 1;
        }
        *(uint *)(param_1 + 0x1928) =
             *(uint *)(param_1 + 0x1928) & 0xfffffffb |
             (*(uint *)(param_1 + 0x1928) >> 2 ^ uVar22) & 1 | uVar22 * 4;
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x4004;
      }
      if ((local_9c & 0x1c0080) != 0) {
        if ((local_9c & 0x40080) != 0) {
          *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x40;
          *(undefined1 *)(param_1 + 0x29) = 1;
        }
        if ((local_9c & 0x80000) != 0) {
          *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 1;
          *(undefined1 *)(param_1 + 0x29) = 1;
        }
        if ((local_9c & 0x100000) != 0) {
          *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x20;
          *(undefined1 *)(param_1 + 0x29) = 1;
        }
      }
      if ((local_9c & 0xe363fd78) != 0) {
        if ((local_9c & 0x1800) != 0) {
          ((int (*)())FUN_000a742d)();
        }
        if ((local_9c & 0x3000000) != 0) {
          ((int (*)())FUN_000a7384)();
        }
        if ((local_9c & 0x38) != 0) {
          *(undefined1 *)(param_1 + 0x29) = 1;
        }
        if ((local_9c & 0x100) != 0) {
          ((int (*)())FUN_000a620e)();
        }
        if ((local_9c & 0x400) != 0) {
          *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 8;
          *(undefined1 *)(param_1 + 0x29) = 1;
        }
        if ((local_9c & 0x2000) != 0) {
          *(undefined1 *)(param_1 + 0x29) = 1;
        }
        if ((local_9c & 0x1c000) != 0) {
          ((int (*)())FUN_000a7290)();
        }
        if ((local_9c & 0x20000) != 0) {
          *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 8;
          *(undefined1 *)(param_1 + 0x29) = 1;
        }
        if ((local_9c & 0x400000) != 0) {
          ((int (*)())FUN_000a7e07)();
        }
        if ((local_9c & 0x20000000) != 0) {
          ((int (*)())FUN_000a621b)();
        }
      }
    }
    if (*(char *)(iVar16 + 0x26b5) != '\0') {
      FUN_000baffd(param_1);
      *(undefined1 *)(iVar16 + 0x26b5) = 0;
    }
    if ((((local_9c & 0x401800) == 0 && (uVar9 & 0xffffff) == 0) && (local_30 & 0x3fff0008) == 0) &&
        (uVar13 & 0x5400002) == 0) {
      return;
    }
    iVar3 = *(int *)(iVar16 + 0x10);
    bVar11 = *(byte *)(iVar16 + 0x2cd);
    if (((*(uint *)(iVar16 + 0x284) & 0x100001) == 0) &&
       ((((-1 < *(char *)(iVar16 + 0x284) || (*(short *)(iVar3 + 0x2e06) != -0x7bae)) &&
         ((*(byte *)(iVar16 + 0x328) & 1) == 0)) &&
        ((*(int *)(iVar3 + 0x3e28) == 0 && ((*(byte *)(iVar16 + 0x2cc) & 0x70) == 0)))))) {
      bVar8 = 0;
    }
    else {
      bVar8 = 1;
    }
    *(byte *)(iVar16 + 0x2cd) = bVar11 & 0xef | bVar8 << 4;
    if ((bVar11 >> 4 & 1) == bVar8) {
      return;
    }
    if (*(char *)(iVar3 + 0x4301) == '\0') {
      return;
    }
    uVar13 = *(uint *)(iVar16 + 0x278);
    *(uint *)(iVar16 + 0x278) = uVar13 | 0x800;
    *(undefined1 *)(iVar16 + 0x269) = 1;
    if (*(char *)(iVar3 + 0x2d4a) == '\0') {
      return;
    }
    *(uint *)(iVar16 + 0x278) = uVar13 | 0x820;
    return;
  }
  *(uint *)(iVar16 + 0x26c4) = uVar13 & 0x1027ffff;
  if (iVar10 == 0 && (local_30 & 0x3f000000) == 0) {
    uVar22 = 0xc0ff00f8;
    uVar9 = 0x3f00ff07;
  }
  else {
    uVar22 = 0xc0ff00f0;
    uVar9 = 0x3f00ff0f;
  }
  *(uint *)(iVar16 + 0x26c0) = uVar22 & local_30;
  uVar9 = uVar9 & local_30;
  if ((uVar9 & 0xff00) != 0 || (uVar13 & 0x4c00000) != 0) {
    if ((uVar13 & 0x800000) != 0) {
      iVar10 = *(int *)(iVar16 + 0x10);
      uVar22 = (uint)*(byte *)(param_1 + 0x47);
      if ((uint)*(byte *)(iVar10 + 0x4305) != (uVar22 & 1)) {
        bVar11 = *(byte *)(param_1 + 0x47) & 0xfe | *(byte *)(iVar10 + 0x4305) & 1;
        uVar22 = (uint)bVar11;
        *(byte *)(param_1 + 0x47) = bVar11;
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1008;
        iVar10 = *(int *)(iVar16 + 0x10);
      }
      if ((uint)*(byte *)(iVar10 + 0x4306) != (uVar22 >> 1 & 1)) {
        *(byte *)(param_1 + 0x47) = (byte)uVar22 & 0xfd | (*(byte *)(iVar10 + 0x4306) & 1) * '\x02';
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
      }
    }
    if ((uVar13 & 0x4400000) != 0) {
      bVar24 = *(int *)(param_1 + -0x74) != 0;
      bVar11 = *(byte *)(param_1 + 0x45);
      if (bVar24 == (bool)(bVar11 >> 3 & 1)) {
        if (((!bVar24) &&
            (local_bc = *(byte *)(param_1 + 0x44), (local_bc & 1) != *(byte *)(iVar3 + 0x2d4a))) &&
           (*(char *)(iVar3 + 0x4304) == '\0')) goto LAB_000a9b8a;
      }
      else {
        if (bVar24) {
          *(uint *)(param_1 + 0x1928) =
               *(uint *)(param_1 + 0x1928) & 0xfffffffd | *(uint *)(param_1 + 0x1928) >> 1 & 1;
          *(undefined1 *)(param_1 + 299) = 1;
          *(byte *)(param_1 + 0x45) = bVar11 | 0x18;
          uVar22 = *(uint *)(param_1 + 0x38);
        }
        else {
          local_bc = *(byte *)(param_1 + 0x44);
LAB_000a9b8a:
          uVar22 = (uint)(*(byte *)(param_1 + 0x1875) & 1);
          *(uint *)(param_1 + 0x1928) =
               *(uint *)(param_1 + 0x1928) & 0xfffffffd |
               (*(uint *)(param_1 + 0x1928) >> 1 ^ uVar22) & 1 | uVar22 * 2;
          if (*(char *)(iVar3 + 0x4304) == '\0') {
            *(undefined1 *)(param_1 + 0x2475) = 1;
            *(byte *)(param_1 + 0x44) = local_bc & 0xfe | *(byte *)(iVar3 + 0x2d4a) & 1;
          }
          else if ((local_bc & 1) != 0) {
            *(byte *)(param_1 + 0x44) = local_bc & 0xfe;
            *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
          }
          *(byte *)(param_1 + 0x45) = bVar11 & 0xe7;
          *(undefined1 *)(param_1 + 299) = 1;
          (**(code **)(param_1 + 0x12b0))(param_1);
          uVar22 = *(uint *)(param_1 + 0x38) | 0x58a60;
          *(uint *)(param_1 + 0x38) = uVar22;
          *(ushort *)(param_1 + 0x34) =
               *(ushort *)(param_1 + 0x34) | (short)(1 << (*(byte *)(param_1 + 0x13b6) & 0x1f)) - 1U
          ;
          *(undefined1 *)(param_1 + 0x29) = 1;
        }
        if (*(char *)(iVar3 + 0x4304) == '\0') {
          if ((*(byte *)(param_1 + 0x44) & 1) == 0) {
            *(byte *)(param_1 + 0x18a4) =
                 *(byte *)(param_1 + 0x18a4) & 0xf9 | (*(byte *)(param_1 + 0x45) & 1) << 2;
          }
          else {
            bVar8 = (*(short *)(iVar3 + 0x2d48) == -0x7e06) << 2;
            bVar11 = *(byte *)(param_1 + 0x18a4);
            *(byte *)(param_1 + 0x18a4) = bVar11 & 0xfb | bVar8;
            *(byte *)(param_1 + 0x18a4) =
                 bVar11 & 0xf9 | bVar8 | (*(byte *)(iVar3 + 0x2d4c) & 1) * '\x02';
          }
        }
        else {
          *(byte *)(param_1 + 0x18a4) =
               (*(byte *)(param_1 + 0x45) & 1) << 2 | *(byte *)(param_1 + 0x18a4) & 0xf9 |
               ((*(uint *)(param_1 + 0x44) & 0x2001000) == 0x2001000) * '\x02';
        }
        *(uint *)(param_1 + 0x38) = uVar22 | 0x1000;
        *(undefined1 *)(param_1 + 0x29) = 1;
        *(byte *)(param_1 + 0x2d) = *(byte *)(param_1 + 0x2d) | 0xf;
      }
    }
    FUN_0003a5dd(iVar16,param_2,0);
  }
  if ((uVar13 & 0x7000000) == 0) goto LAB_000a864d;
  bVar11 = *(byte *)(param_1 + 0x2e) | 2;
  *(undefined1 *)(param_1 + 0x29) = 1;
  if ((uVar13 & 0x5000000) != 0) {
    bVar8 = *(byte *)(param_1 + 0x46);
    bVar6 = bVar8 >> 2 & 1;
    bVar12 = bVar8 & 1;
    bVar11 = *(byte *)(param_1 + 0x2e) | 3;
    if (*(int *)(param_1 + -0x70) == 0) {
      if (bVar6 == 0) {
        if (bVar12 != 0) {
          *(byte *)(param_1 + 0x1876) = *(byte *)(param_1 + 0x1876) & 0xfd;
          bVar6 = *(byte *)(param_1 + 0x45);
          *(byte *)(param_1 + 0x45) = bVar6 & 0xbf;
          *(byte *)(param_1 + 0x46) = bVar8 & 0xfe;
          if ((bVar8 & 2) != 0) {
            *(byte *)(param_1 + 0x46) = bVar8 & 0xfc;
            *(byte *)(param_1 + 0x45) = bVar6 & 0x3f;
            *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
            *(undefined1 *)(param_1 + 0x29) = 1;
          }
        }
      }
      else {
        *(byte *)(param_1 + 0x1876) = *(byte *)(param_1 + 0x1876) & 0xfd;
        *(byte *)(param_1 + 0x45) = *(byte *)(param_1 + 0x45) & 0xbf;
        *(byte *)(param_1 + 0x46) = bVar8 & 0xfb;
        FUN_00088206(param_1);
      }
    }
    else {
      local_bd = bVar8;
      if (*(char *)(param_1 + 0x279c) == '\0') {
        if (bVar12 == 0) {
          if (bVar6 != 0) {
            *(byte *)(param_1 + 0x1876) = *(byte *)(param_1 + 0x1876) & 0xfd;
            *(byte *)(param_1 + 0x45) = *(byte *)(param_1 + 0x45) & 0xbf;
            *(byte *)(param_1 + 0x46) = bVar8 & 0xfb;
            FUN_00088206(param_1);
            local_bd = *(byte *)(param_1 + 0x46);
          }
          *(byte *)(param_1 + 0x1876) = *(byte *)(param_1 + 0x1876) | 2;
          bVar8 = *(byte *)(param_1 + 0x45);
          *(byte *)(param_1 + 0x45) = bVar8 | 0x40;
          *(byte *)(param_1 + 0x46) = local_bd | 1;
          bVar6 = *(byte *)(*(int *)(param_1 + 0x1144) + 0x6c) & 1;
          *(byte *)(param_1 + 0x46) = local_bd & 0xfd | 1 | bVar6 * '\x02';
          if (bVar6 != 0) {
            *(byte *)(param_1 + 0x45) = bVar8 | 0xc0;
            *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
            *(undefined1 *)(param_1 + 0x29) = 1;
          }
        }
        FUN_0003da3d(param_1 + -0x240,param_2,0);
      }
      else if (bVar6 == 0) {
        if (bVar12 == 0) {
          bVar6 = *(byte *)(param_1 + 0x45);
          bVar12 = *(byte *)(param_1 + 0x1876);
        }
        else {
          bVar12 = *(byte *)(param_1 + 0x1876) & 0xfd;
          *(byte *)(param_1 + 0x1876) = bVar12;
          bVar2 = *(byte *)(param_1 + 0x45);
          bVar6 = bVar2 & 0xbf;
          *(byte *)(param_1 + 0x45) = bVar6;
          *(byte *)(param_1 + 0x46) = bVar8 & 0xfe;
          local_bd = bVar8 & 0xfe;
          if ((bVar8 & 2) != 0) {
            *(byte *)(param_1 + 0x46) = bVar8 & 0xfc;
            bVar6 = bVar2 & 0x3f;
            *(byte *)(param_1 + 0x45) = bVar6;
            *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
            *(undefined1 *)(param_1 + 0x29) = 1;
            local_bd = bVar8 & 0xfc;
          }
        }
        *(byte *)(param_1 + 0x8c) = *(byte *)(param_1 + 0x8c) | 1;
        *(byte *)(param_1 + 0x1876) = bVar12 | 2;
        *(byte *)(param_1 + 0x45) = bVar6 | 0x40;
        *(byte *)(param_1 + 0x46) = local_bd | 4;
        FUN_00088206(param_1);
      }
    }
    *(undefined1 *)(param_1 + 0x2475) = 1;
  }
  iVar10 = *(int *)(param_1 + 4);
  if ((*(char *)(*(int *)(iVar10 + 0x10) + 0x2e2d) == '\0') ||
     ((*(byte *)(param_1 + 0x45) & 0x40) != 0)) {
LAB_000a85e7:
    uVar13 = 0;
  }
  else {
    cVar7 = FUN_00017bd8(iVar10,*(undefined4 *)(iVar10 + 0x26a0));
    if (cVar7 != '\0') {
      iVar10 = *(int *)(param_1 + 4);
      goto LAB_000a85e7;
    }
    uVar13 = 1;
    iVar10 = *(int *)(param_1 + 4);
  }
  uVar22 = *(uint *)(param_1 + 0x1928);
  uVar19 = (uVar22 >> 4 ^ uVar13) & 1;
  uVar20 = uVar19 | uVar22 & 0xffffffef | uVar13 << 4;
  *(uint *)(param_1 + 0x1928) = uVar20;
  if (((*(char *)(*(int *)(iVar10 + 0x10) + 0x2e2c) == '\0') ||
      ((*(byte *)(param_1 + 0x45) & 0x40) != 0)) ||
     (*(short *)(*(int *)(iVar10 + 0x10) + 0x2e28) == -1)) {
    uVar14 = 0;
  }
  else {
    uVar14 = 1;
  }
  *(uint *)(param_1 + 0x1928) =
       uVar19 | uVar22 & 0xffffffe7 | uVar13 << 4 | (uVar20 >> 3 ^ uVar14) & 1 | uVar14 * 8;
  *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x2000;
  *(byte *)(param_1 + 0x2e) = bVar11;
LAB_000a864d:
  if (uVar9 != 0) {
    if ((uVar9 & 1) != 0) {
      *(ushort *)(iVar16 + 0x15fc) =
           (ushort)*(byte *)(iVar16 + 0x2a5c) * (short)*(undefined4 *)(iVar16 + 0x15c);
      *(ushort *)(iVar16 + 0x15fa) =
           (ushort)*(byte *)(iVar16 + 0x2a5d) * (short)*(undefined4 *)(iVar16 + 0x160);
      if (DOUBLE_001cf330 == *(double *)(*(int *)(iVar16 + 0x10) + 0x1830)) {
        pdVar1 = (double *)(*(int *)(iVar16 + 0x10) + 0x1838);
        if ((DOUBLE_001cf330 == *pdVar1) && (!NAN(DOUBLE_001cf330) && !NAN(*pdVar1))) {
          *(byte *)(iVar16 + 0x2cd) = *(byte *)(iVar16 + 0x2cd) | 2;
        }
      }
      if ((*(byte *)(iVar16 + 0x2a5c) < 2) || (*(byte *)(iVar16 + 0x2a5d) < 2)) {
        *(undefined1 *)(iVar16 + 0x2690) = 0;
      }
      else {
        *(undefined1 *)(iVar16 + 0x2690) = 1;
      }
      *(uint *)(iVar16 + 0x278) = *(uint *)(iVar16 + 0x278) | 0x400;
      *(uint *)(iVar16 + 0x27c) = *(uint *)(iVar16 + 0x27c) | 3;
      *(undefined1 *)(iVar16 + 0x269) = 1;
    }
    if ((uVar9 & 0x3f000008) != 0) {
      ((int (*)())FUN_000a694a)();
      ((int (*)())FUN_000a7070)();
    }
  }
  uVar13 = param_2[4];
  if (uVar13 != 0 || (param_2[1] & 0xff0000) != 0) {
    if ((param_2[1] & 0xff0000) != 0) {
      ((int (*)())FUN_000a6673)();
    }
    if (uVar13 != 0) {
      ((int (*)())FUN_000a767f)();
    }
  }
  if (local_9c != 0) {
    if ((local_9c & 1) != 0) {
      *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x1010;
      *(undefined1 *)(param_1 + 0x29) = 1;
    }
    if ((local_9c & 6) != 0) {
      *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x1018;
      *(undefined1 *)(param_1 + 0x29) = 1;
    }
    if ((local_9c & 0x200) != 0) {
      *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 1;
    }
    if ((local_9c & 0x10000000) != 0) {
      *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x20;
    }
    if ((local_9c & 0x8000000) != 0) {
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x40;
    }
    if ((local_9c & 0x4000000) != 0) {
      iVar10 = *(int *)(iVar3 + 0x3180);
      iVar23 = *(int *)(iVar3 + 0x3184);
      iVar15 = *(int *)(iVar3 + 0x3188);
      iVar16 = *(int *)(iVar3 + 0x318c);
      iVar17 = *(int *)(param_1 + -0xe4);
      iVar4 = *(int *)(param_1 + -0xe0);
      *(int *)(param_1 + 0x440) = iVar10;
      *(int *)(param_1 + 0x444) = iVar23;
      *(int *)(param_1 + 0x448) = iVar15;
      *(int *)(param_1 + 0x44c) = iVar16;
      if (*(char *)(iVar3 + 0x3190) == '\0') {
        *(undefined4 *)(param_1 + 0x1358) = 0;
        *(undefined4 *)(param_1 + 0x135c) = 0;
        *(int *)(param_1 + 0x1360) = iVar17;
        *(int *)(param_1 + 0x1364) = iVar4;
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 2;
      }
      else {
        if (*(char *)(param_1 + 0x293c) != '\0') {
          iVar23 = iVar4 - (iVar23 + iVar16);
        }
        iVar15 = iVar10 + iVar15;
        iVar16 = iVar23 + iVar16;
        if (iVar10 < 0) {
          iVar10 = 0;
        }
        if (iVar23 < 0) {
          iVar23 = 0;
        }
        if (iVar17 < iVar15) {
          iVar15 = iVar17;
        }
        if (iVar4 < iVar16) {
          iVar16 = iVar4;
        }
        *(int *)(param_1 + 0x1358) = iVar10;
        *(int *)(param_1 + 0x135c) = iVar23;
        *(int *)(param_1 + 0x1360) = iVar15;
        *(int *)(param_1 + 0x1364) = iVar16;
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 2;
      }
    }
    if ((local_9c & 0x800000) != 0) {
      iVar16 = *(int *)(*(int *)(param_1 + 4) + 0x10);
      if (((*(char *)(iVar16 + 0x3178) == '\0') || ((*(byte *)(param_1 + 0x45) & 0x40) != 0)) ||
         ((*(short *)(iVar16 + 0x3170) != 0x1b02 && (*(short *)(iVar16 + 0x3172) != 0x1b02)))) {
        uVar13 = 0;
      }
      else {
        uVar13 = 1;
      }
      *(uint *)(param_1 + 0x1928) =
           *(uint *)(param_1 + 0x1928) & 0xfffffffb |
           (*(uint *)(param_1 + 0x1928) >> 2 ^ uVar13) & 1 | uVar13 * 4;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x4004;
    }
    if ((local_9c & 0x1c0080) != 0) {
      if ((local_9c & 0x40080) != 0) {
        *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x40;
        *(undefined1 *)(param_1 + 0x29) = 1;
      }
      if ((local_9c & 0x80000) != 0) {
        *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 1;
        *(undefined1 *)(param_1 + 0x29) = 1;
      }
      if ((local_9c & 0x100000) != 0) {
        *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x20;
        *(undefined1 *)(param_1 + 0x29) = 1;
      }
    }
    if ((local_9c & 0xe363fd78) != 0) {
      if ((local_9c & 0x1800) != 0) {
        ((int (*)())FUN_000a742d)();
      }
      if ((local_9c & 0x3000000) != 0) {
        ((int (*)())FUN_000a7384)();
      }
      if ((local_9c & 0x38) != 0) {
        *(undefined1 *)(param_1 + 0x29) = 1;
      }
      if ((local_9c & 0x100) != 0) {
        ((int (*)())FUN_000a620e)();
      }
      if ((local_9c & 0x400) != 0) {
        *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 8;
        *(undefined1 *)(param_1 + 0x29) = 1;
      }
      if ((local_9c & 0x2000) != 0) {
        *(undefined1 *)(param_1 + 0x29) = 1;
      }
      if ((local_9c & 0x1c000) != 0) {
        ((int (*)())FUN_000a7290)();
      }
      if ((local_9c & 0x20000) != 0) {
        *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 8;
        *(undefined1 *)(param_1 + 0x29) = 1;
      }
      if ((local_9c & 0x400000) != 0) {
        ((int (*)())FUN_000a7e07)();
      }
      if ((local_9c & 0x20000000) != 0) {
        ((int (*)())FUN_000a621b)();
        return;
      }
    }
  }
  return;
}

/* FUN_000aa683 @ 0xaa683 (48 bytes) */
int FUN_000aa683(param_1)
  int param_1;
{
  if (*(char *)(param_1 + 0x1868) != '\0') {
    *(undefined **)(param_1 + 0x11cc) = PTR_LAB_00213439;
    return;
  }
  *(undefined **)(param_1 + 0x11cc) = PTR_FUN_00213435;
  return;
}

/* FUN_000aa6b4 @ 0xaa6b4 (94 bytes) */
int FUN_000aa6b4(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  uint *param_3;
  undefined1 *param_4;
  int param_5;
{
  if (param_1 != 3) {
    param_3[1] = 4;
    *param_3 = param_2;
    *param_4 = 0;
    return;
  }
  if (param_2 == 1) {
    param_3[1] = 0x18;
    *param_3 = 0;
    *param_4 = 1;
  }
  else {
    param_3[1] = 0x17;
    *param_3 = (uint)param_5;
    *param_4 = 1;
  }
  return;
}

/* FUN_000aa712 @ 0xaa712 (151 bytes) */
int FUN_000aa712(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int in_stack_00000024;
  int *in_stack_00000028;
  
  if (param_1 != 1) {
    if (param_1 == 0) {
      in_stack_00000028[1] = 4;
      *in_stack_00000028 = param_2;
    }
    else if (param_1 == 2) {
      in_stack_00000028[1] = 1;
      *in_stack_00000028 = param_2;
      return;
    }
    return;
  }
  in_stack_00000024 = in_stack_00000024 + param_2 * 0x14;
  iVar1 = *(int *)(in_stack_00000024 + 0xc);
  iVar2 = *(int *)(in_stack_00000024 + 8);
  if (iVar2 == 1) {
    if (iVar1 != 0) {
      in_stack_00000028[1] = 0x13;
      *in_stack_00000028 = 0;
      return;
    }
    in_stack_00000028[1] = 0x12;
    *in_stack_00000028 = 0;
    return;
  }
  if (iVar2 != 3) {
    if (iVar2 != 4) {
      in_stack_00000028[1] = 0x11;
      *in_stack_00000028 = iVar1;
      return;
    }
    in_stack_00000028[1] = 0x16;
    *in_stack_00000028 = 0;
    return;
  }
  in_stack_00000028[1] = 0x10;
  *in_stack_00000028 = 0;
  return;
}

/* FUN_000aa7a9 @ 0xaa7a9 (141 bytes) */
int FUN_000aa7a9(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  code *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 uStack_40;
  int aiStack_3c [8];
  undefined1 auStack_1c [4];
  int local_18;
  undefined4 local_14;
  int local_10;
  
  local_18 = (int)aiStack_3c;
  iVar2 = -(*(int *)(*(int *)(param_2 + 0x74) + 0x84) * 0x10 + 0x10);
  local_14 = param_3;
  local_10 = param_1;
  *(undefined1 **)((int)aiStack_3c + iVar2 + 8U) = auStack_1c + iVar2;
  *(undefined4 *)((int)aiStack_3c + iVar2 + 4U) = *(undefined4 *)(*(int *)(param_2 + 0x74) + 0x84);
  *(undefined4 *)((int)aiStack_3c + iVar2) = *(undefined4 *)(local_10 + 4);
  *(undefined4 *)((int)&uStack_40 + iVar2) = 0xaa7f0;
  FUN_000229cb();
  *(undefined4 *)((int)aiStack_3c + iVar2 + 0x18U) = 1;
  *(undefined4 *)((int)aiStack_3c + iVar2 + 0x14U) =
       *(undefined4 *)(*(int *)(param_2 + 0x74) + 0x84);
  *(undefined1 **)((int)aiStack_3c + iVar2 + 0x10U) = auStack_1c + iVar2;
  *(undefined4 *)((int)aiStack_3c + iVar2 + 0xcU) = 0;
  *(undefined4 *)((int)aiStack_3c + iVar2 + 8U) = 0;
  *(undefined4 *)((int)aiStack_3c + iVar2 + 4U) = local_14;
  iVar3 = local_10;
  *(int *)((int)aiStack_3c + iVar2) = local_10;
  pcVar1 = *(code **)(iVar3 + 0x1280);
  *(undefined4 *)((int)&uStack_40 + iVar2) = 0xaa82c;
  (*pcVar1)();
  return;
}

/* FUN_000aa836 @ 0xaa836 (69 bytes) */
int FUN_000aa836(param_1)
  int param_1;
{
  int iVar1;
  
  if (*(int *)(param_1 + 0x121c) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x121c) + 0x74);
    if (*(char *)(iVar1 + 0x54) == '\0') {
      iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x112c) + 8) + 0x14 +
                      *(int *)(param_1 + 0x1220) * 0x18);
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

/* FUN_000aa87b @ 0xaa87b (306 bytes) */
int FUN_000aa87b(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  
  puVar4 = (uint *)(param_1 + 4);
  if (param_2 != 0) {
    bVar1 = *(byte *)(param_1 + 6);
    if ((bVar1 & 0x3f) == 0x18) {
      *(undefined1 *)(*(int *)(param_4 + 0x74) + 4) = 1;
    }
    puVar4 = (uint *)(param_1 + 8);
    if ((bVar1 & 0x40) != 0) {
      puVar4 = (uint *)(param_1 + 0xc);
    }
  }
  if (0 < param_3) {
    uVar2 = *puVar4;
    puVar5 = puVar4 + 2;
    puVar4 = puVar4 + 1;
    if ((uVar2 & 0x400000) != 0) {
      puVar4 = puVar5;
    }
    if ((uVar2 >> 0x10 & 0x3f) - 1 < 2) {
      iVar3 = (uVar2 & 0xffff) + 1;
      if (*(int *)(*(int *)(param_4 + 0x74) + 0x84) < iVar3) {
        *(int *)(*(int *)(param_4 + 0x74) + 0x84) = iVar3;
      }
    }
  }
  if (1 < param_3) {
    uVar2 = *puVar4;
    puVar5 = puVar4 + 2;
    puVar4 = puVar4 + 1;
    if ((uVar2 & 0x400000) != 0) {
      puVar4 = puVar5;
    }
    if ((uVar2 >> 0x10 & 0x3f) - 1 < 2) {
      iVar3 = (uVar2 & 0xffff) + 1;
      if (*(int *)(*(int *)(param_4 + 0x74) + 0x84) < iVar3) {
        *(int *)(*(int *)(param_4 + 0x74) + 0x84) = iVar3;
      }
    }
  }
  puVar5 = puVar4;
  if (2 < param_3) {
    uVar2 = *puVar4;
    puVar5 = puVar4 + 1;
    if ((uVar2 & 0x400000) != 0) {
      puVar5 = puVar4 + 2;
    }
    if ((uVar2 >> 0x10 & 0x3f) - 1 < 2) {
      iVar3 = (uVar2 & 0xffff) + 1;
      if (*(int *)(*(int *)(param_4 + 0x74) + 0x84) < iVar3) {
        *(int *)(*(int *)(param_4 + 0x74) + 0x84) = iVar3;
      }
    }
  }
  return puVar5;
}

/* FUN_000aa9ad @ 0xaa9ad (1337 bytes) */
int FUN_000aa9ad(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint *param_3;
{
  size_t sVar1;
  uint *puVar2;
  ushort uVar3;
  undefined4 uVar4;
  float fVar5;
  void *pvVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  float *pfVar10;
  float *pfVar11;
  float *pfVar12;
  byte local_50;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
  iVar9 = *(int *)(param_2 + 0x74);
  sVar1 = *(int *)(iVar9 + 0x5c) - 10;
  pvVar6 = (void *)(**(code **)(param_1 + 0xc))(*(int *)(iVar9 + 0x5c) + -6);
  param_3[2] = (uint)pvVar6;
  _memcpy(pvVar6,(void *)(*(int *)(iVar9 + 0x58) + 10),sVar1);
  uVar7 = *(int *)(iVar9 + 0x5c) - 10U >> 2;
  param_3[1] = uVar7 + 1;
  *param_3 = uVar7;
  uVar7 = param_3[2];
  uVar4 = *(undefined4 *)(*(int *)(param_2 + 0x70) + *(int *)(param_1 + 0x1130) * 4);
  pfVar10 = (float *)(uVar7 + 8);
  *(undefined1 *)(*(int *)(param_2 + 0x74) + 4) = 0;
  *(undefined1 *)(*(int *)(param_2 + 0x74) + 3) = 0;
  *(undefined1 *)(*(int *)(param_2 + 0x74) + 5) = 0;
  *(undefined4 *)(*(int *)(param_2 + 0x74) + 0xc) = 0;
  *(undefined4 *)(*(int *)(param_2 + 0x74) + 0x10) = 0;
  **(undefined1 **)(param_2 + 0x74) = 0;
  *(undefined1 *)(*(int *)(param_2 + 0x74) + 1) = 0;
  *(undefined1 *)(*(int *)(param_2 + 0x74) + 2) = 0;
  *(undefined1 *)(param_2 + 0x6c) = 1;
  while (pfVar10 < (float *)(sVar1 + uVar7)) {
    fVar5 = *pfVar10;
    switch((uint)fVar5 & 0xffff) {
    default:
      goto switchD_000aaa92_caseD_0;
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
      pfVar10 = (float *)((int (*)())FUN_000aa87b)(param_2);
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
      pfVar10 = (float *)((int (*)())FUN_000aa87b)(param_2);
      break;
    case 10:
    case 0xd:
    case 0x21:
    case 0x2f:
    case 0x3f:
    case 0x40:
    case 100:
      pfVar10 = (float *)((int (*)())FUN_000aa87b)(param_2);
      break;
    case 0xf:
      pfVar10 = pfVar10 + *(ushort *)(pfVar10 + 1) + 2;
      break;
    case 0x14:
      pfVar10 = pfVar10 + 3;
      break;
    case 0x16:
      pfVar11 = pfVar10 + 1;
      pfVar10 = pfVar10 + 2;
      uVar8 = (uint)*pfVar11 >> 0x10 & 0x3f;
      if (uVar8 == 0x11) {
        puVar2 = (uint *)(*(int *)(param_2 + 0x74) + 0xc);
        *puVar2 = *puVar2 | 1 << (SUB41(*pfVar11,0) & 0x1f);
      }
      else if (uVar8 < 0x12) {
        if (uVar8 == 0x10) {
          *(undefined1 *)(*(int *)(param_2 + 0x74) + 1) = 1;
        }
      }
      else if (uVar8 == 0x13) {
        **(undefined1 **)(param_2 + 0x74) = 1;
      }
      else if (uVar8 == 0x16) {
        *(undefined1 *)(*(int *)(param_2 + 0x74) + 2) = 1;
      }
      break;
    case 0x18:
      break;
    case 0x19:
      pfVar10 = pfVar10 + 1;
      uVar8 = (uint)fVar5 >> 0x10 & 0xff;
      puVar2 = (uint *)(*(int *)(param_2 + 0x74) + 0x10);
      *puVar2 = *puVar2 | 1 << ((byte)((uint)fVar5 >> 0x10) & 0x1f);
      switch((uint)fVar5 >> 0x18 & 7) {
      case 0:
        iVar9 = *(int *)(param_1 + 0x13f8 + uVar8 * 4);
        if (iVar9 == 0) goto switchD_000aacec_caseD_1;
        switch(*(undefined1 *)(iVar9 + 0x30)) {
        case 0:
          *(undefined4 *)(*(int *)(param_2 + 0x74) + 0x14 + uVar8 * 4) = 4;
          break;
        case 1:
          *(undefined4 *)(*(int *)(param_2 + 0x74) + 0x14 + uVar8 * 4) = 3;
          break;
        case 2:
          *(undefined4 *)(*(int *)(param_2 + 0x74) + 0x14 + uVar8 * 4) = 5;
          break;
        case 3:
          *(undefined4 *)(*(int *)(param_2 + 0x74) + 0x14 + uVar8 * 4) = 2;
          break;
        case 4:
          *(undefined4 *)(*(int *)(param_2 + 0x74) + 0x14 + uVar8 * 4) = 1;
        }
        break;
      case 1:
switchD_000aacec_caseD_1:
        *(undefined4 *)(*(int *)(param_2 + 0x74) + 0x14 + uVar8 * 4) = 1;
        break;
      case 2:
        local_50 = (byte)((uint)fVar5 >> 0x18);
        *(uint *)(*(int *)(param_2 + 0x74) + 0x14 + uVar8 * 4) =
             (uint)((local_50 & 0x18) == 0x10) * 3 + 2;
        break;
      case 3:
        *(undefined4 *)(*(int *)(param_2 + 0x74) + 0x14 + uVar8 * 4) = 3;
        break;
      case 4:
        *(undefined4 *)(*(int *)(param_2 + 0x74) + 0x14 + uVar8 * 4) = 4;
      }
      break;
    case 0x1c:
      fVar5 = pfVar10[1];
      uVar8 = (uint)fVar5 >> 0x10 & 0x3f;
      if (uVar8 == 1) {
        (**(code **)(param_1 + 0x1280))
                  (param_1,uVar4,(uint)fVar5 & 0xffff,(uint)fVar5 & 0xffff,pfVar10 + 2,1,0);
        pfVar11 = pfVar10 + 6;
      }
      else {
        pfVar11 = pfVar10 + 1;
        if (uVar8 == 2) {
          local_2c = (float)(int)pfVar10[2];
          local_28 = (float)(int)pfVar10[3];
          local_24 = (float)(int)pfVar10[4];
          local_20 = (float)(int)pfVar10[5];
          (**(code **)(param_1 + 0x1280))
                    (param_1,uVar4,(uint)fVar5 & 0xffff,(uint)fVar5 & 0xffff,&local_2c,1,0);
          pfVar11 = pfVar10 + 6;
        }
      }
      pfVar10 = pfVar11;
      iVar9 = ((uint)fVar5 & 0xffff) + 1;
      if (*(int *)(*(int *)(param_2 + 0x74) + 0x84) < iVar9) {
        *(int *)(*(int *)(param_2 + 0x74) + 0x84) = iVar9;
      }
      break;
    case 0x37:
      pfVar10 = (float *)((int (*)())FUN_000aa87b)(param_2);
      *(undefined1 *)(*(int *)(param_2 + 0x74) + 3) = 1;
      break;
    case 0x4b:
      pfVar10 = pfVar10 + 1;
      break;
    case 0x5d:
      pfVar11 = pfVar10 + 1;
      if ((char)*(byte *)((int)pfVar10 + 3) < '\0') {
        pfVar11 = pfVar10 + 2;
      }
      if ((*(byte *)((int)pfVar10 + 3) & 0x40) != 0) {
        pfVar11 = pfVar11 + 1;
      }
      fVar5 = *pfVar11;
      if (((byte)((uint)fVar5 >> 0x10) & 0x3f) == 0x18) {
        *(undefined1 *)(*(int *)(param_2 + 0x74) + 4) = 1;
      }
      pfVar12 = pfVar11 + 1;
      if (((uint)fVar5 & 0x400000) != 0) {
        pfVar12 = pfVar11 + 2;
      }
      local_2c = *pfVar12;
      pfVar10 = pfVar12 + 1;
      if (((uint)local_2c & 0x400000) != 0) {
        pfVar10 = pfVar12 + 2;
      }
      if (((uint)local_2c >> 0x10 & 0x3f) - 1 < 2) {
        uVar3 = (*(unsigned short *)((unsigned char *)&(local_2c) + 0));
LAB_000aad62:
        if (*(int *)(*(int *)(param_2 + 0x74) + 0x84) < (int)(uVar3 + 1)) {
          *(uint *)(*(int *)(param_2 + 0x74) + 0x84) = uVar3 + 1;
        }
      }
      break;
    case 0x5e:
      pfVar11 = pfVar10 + 1;
      if ((char)*(byte *)((int)pfVar10 + 3) < '\0') {
        pfVar11 = pfVar10 + 2;
      }
      if ((*(byte *)((int)pfVar10 + 3) & 0x40) != 0) {
        pfVar11 = pfVar11 + 1;
      }
      fVar5 = *pfVar11;
      if (((byte)((uint)fVar5 >> 0x10) & 0x3f) == 0x18) {
        *(undefined1 *)(*(int *)(param_2 + 0x74) + 4) = 1;
      }
      pfVar10 = pfVar11 + 1;
      if (((uint)fVar5 & 0x400000) != 0) {
        pfVar10 = pfVar11 + 2;
      }
      local_2c = *pfVar10;
      pfVar11 = pfVar10 + 1;
      if (((uint)local_2c & 0x400000) != 0) {
        pfVar11 = pfVar10 + 2;
      }
      if (((uint)local_2c >> 0x10 & 0x3f) - 1 < 2) {
        iVar9 = ((uint)local_2c & 0xffff) + 1;
        if (*(int *)(*(int *)(param_2 + 0x74) + 0x84) < iVar9) {
          *(int *)(*(int *)(param_2 + 0x74) + 0x84) = iVar9;
        }
      }
      local_28 = *pfVar11;
      pfVar10 = pfVar11 + 1;
      if (((uint)local_28 & 0x400000) != 0) {
        pfVar10 = pfVar11 + 2;
      }
      if (((uint)local_28 >> 0x10 & 0x3f) - 1 < 2) {
        uVar3 = (*(unsigned short *)((unsigned char *)&(local_28) + 0));
        goto LAB_000aad62;
      }
    }
  }
switchD_000aaa92_caseD_0:
  return 1;
}

/* FUN_000ab0a5 @ 0xab0a5 (358 bytes) */
int FUN_000ab0a5(param_1, param_2, param_3, param_4)
  int param_1;
  uint *param_2;
  int param_3;
  int param_4;
{
  uint uVar1;
  void *pvVar2;
  undefined4 local_18;
  
  local_18 = CONCAT22(4,param_3);
  if (param_2[1] <= *param_2) {
    pvVar2 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar2,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(param_2[2] + *param_2 * 4) = 0xe;
  uVar1 = *param_2;
  *param_2 = uVar1 + 1;
  if (param_2[1] <= uVar1 + 1) {
    pvVar2 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar2,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(uint *)(param_2[2] + *param_2 * 4) = CONCAT22(0x17,param_4);
  uVar1 = *param_2;
  *param_2 = uVar1 + 1;
  if (uVar1 + 1 < param_2[1]) {
    *(undefined4 *)(param_2[2] + *param_2 * 4) = local_18;
    *param_2 = *param_2 + 1;
    return;
  }
  pvVar2 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
  if ((void *)param_2[2] != (void *)0x0) {
    _memcpy(pvVar2,(void *)param_2[2],*param_2 << 2);
    (**(code **)(param_1 + 0x18))(param_2[2]);
  }
  param_2[2] = (uint)pvVar2;
  param_2[1] = param_2[1] + 0x80;
  *(undefined4 *)(param_2[2] + *param_2 * 4) = local_18;
  *param_2 = *param_2 + 1;
  return;
}

/* FUN_000ab20b @ 0xab20b (8383 bytes) */
int FUN_000ab20b(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13, param_14, param_15, param_16, param_17, param_18, param_19, param_20, param_21, param_22, param_23, param_24)
  int param_1;
  int param_2;
  uint *param_3;
  int param_4;
  ushort *param_5;
  uint param_6;
  ushort *param_7;
  undefined4 *param_8;
  undefined4 *param_9;
  int param_10;
  int param_11;
  int param_12;
  undefined4 param_13;
  undefined4 param_14;
  undefined4 param_15;
  undefined4 param_16;
  undefined4 param_17;
  undefined4 param_18;
  undefined4 param_19;
  undefined4 param_20;
  undefined4 param_21;
  undefined4 param_22;
  undefined4 param_23;
  undefined4 param_24;
{
  short sVar1;
  ushort uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  char cVar7;
  ushort uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  void *pvVar12;
  uint uVar13;
  byte bVar14;
  byte bVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  undefined4 *puVar19;
  uint local_e4;
  uint local_e0;
  uint local_dc;
  uint local_d4;
  undefined4 local_d0;
  int local_c8;
  int local_54;
  int local_50;
  uint auStack_48 [5];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  uint local_24;
  uint local_20;
  
  local_d0 = 0;
  uVar17 = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  if ((param_4 - 0x21U < 0x20) && ((1 << ((byte)(param_4 - 0x21U) & 0x1f) & 0x8fffffffU) != 0)) {
    uVar17 = 0x100;
  }
  if (*(uint *)(param_5 + 2) == 0x18) {
    uVar17 = 0x100;
  }
  local_d4 = (uint)*param_5 | (*(uint *)(param_5 + 2) & 0x3f) << 0x10 | 0x400000;
  uVar9 = param_6 * 2 & 4;
  uVar10 = param_6 * 4 & 0x10;
  uVar11 = param_6 * 8 & 0x40;
  uVar18 = uVar17 | param_6 & 1 | uVar9 | uVar10 | uVar11;
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
    local_c8 = 1;
    goto LAB_000abcfe;
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
    local_54 = 1;
    goto LAB_000abc67;
  case 2:
  case 0xe:
  case 0xf:
  case 0x23:
  case 0x2e:
  case 0x2f:
    local_20 = CONCAT12((char)param_9[1],(short)*param_9) & 0xff3fffff | 0x400000;
    auStack_48[4] = param_24;
    auStack_48[3] = param_23;
    auStack_48[2] = param_22;
    auStack_48[1] = param_21;
    if (param_9[1] == 0x10) {
      iVar16 = 1;
      do {
        if (auStack_48[iVar16] < 0xb) {
                    
                    
          (*(code *)(*(int *)(((unsigned char *)0x000ad650) + auStack_48[iVar16] * 4) + 0xab21c))();
          return;
        }
        auStack_48[iVar16] = 0;
        iVar16 = iVar16 + 1;
      } while (iVar16 != 5);
    }
    switch(param_21) {
    default:
      bVar6 = false;
      bVar14 = 0;
      break;
    case 1:
      bVar6 = false;
      bVar14 = 1;
      break;
    case 2:
      bVar6 = false;
      bVar14 = 2;
      break;
    case 3:
      bVar6 = false;
      bVar14 = 3;
      break;
    case 4:
      bVar6 = false;
      bVar14 = 4;
      break;
    case 5:
      bVar6 = false;
      bVar14 = 5;
      break;
    case 6:
      bVar6 = true;
      bVar14 = 0;
      break;
    case 7:
      bVar6 = true;
      bVar14 = 1;
      break;
    case 8:
      bVar6 = true;
      bVar14 = 2;
      break;
    case 9:
      bVar6 = true;
      bVar14 = 3;
      break;
    case 10:
      bVar6 = true;
      bVar14 = 5;
    }
    if (bVar6) {
      bVar14 = bVar14 | 8;
    }
    switch(param_22) {
    default:
      bVar6 = false;
      cVar7 = '\0';
      break;
    case 1:
      bVar6 = false;
      cVar7 = '\x01';
      break;
    case 2:
      bVar6 = false;
      cVar7 = '\x02';
      break;
    case 3:
      bVar6 = false;
      cVar7 = '\x03';
      break;
    case 4:
      bVar6 = false;
      cVar7 = '\x04';
      break;
    case 5:
      bVar6 = false;
      cVar7 = '\x05';
      break;
    case 6:
      bVar6 = true;
      cVar7 = '\0';
      break;
    case 7:
      bVar6 = true;
      cVar7 = '\x01';
      break;
    case 8:
      bVar6 = true;
      cVar7 = '\x02';
      break;
    case 9:
      bVar6 = true;
      cVar7 = '\x03';
      break;
    case 10:
      bVar6 = true;
      cVar7 = '\x05';
    }
    bVar14 = bVar14 | cVar7 << 4;
    if (bVar6) {
      bVar14 = bVar14 | 0x80;
    }
    switch(param_23) {
    default:
      bVar6 = false;
      bVar15 = 0;
      break;
    case 1:
      bVar6 = false;
      bVar15 = 1;
      break;
    case 2:
      bVar6 = false;
      bVar15 = 2;
      break;
    case 3:
      bVar6 = false;
      bVar15 = 3;
      break;
    case 4:
      bVar6 = false;
      bVar15 = 4;
      break;
    case 5:
      bVar6 = false;
      bVar15 = 5;
      break;
    case 6:
      bVar6 = true;
      bVar15 = 0;
      break;
    case 7:
      bVar6 = true;
      bVar15 = 1;
      break;
    case 8:
      bVar6 = true;
      bVar15 = 2;
      break;
    case 9:
      bVar6 = true;
      bVar15 = 3;
      break;
    case 10:
      bVar6 = true;
      bVar15 = 5;
    }
    if (bVar6) {
      bVar15 = bVar15 | 8;
    }
    switch(param_24) {
    default:
      bVar6 = false;
      cVar7 = '\0';
      break;
    case 1:
      bVar6 = false;
      cVar7 = '\x01';
      break;
    case 2:
      bVar6 = false;
      cVar7 = '\x02';
      break;
    case 3:
      bVar6 = false;
      cVar7 = '\x03';
      break;
    case 4:
      bVar6 = false;
      cVar7 = '\x04';
      break;
    case 5:
      bVar6 = false;
      cVar7 = '\x05';
      break;
    case 6:
      bVar6 = true;
      cVar7 = '\0';
      break;
    case 7:
      bVar6 = true;
      cVar7 = '\x01';
      break;
    case 8:
      bVar6 = true;
      cVar7 = '\x02';
      break;
    case 9:
      bVar6 = true;
      cVar7 = '\x03';
      break;
    case 10:
      bVar6 = true;
      cVar7 = '\x05';
    }
    bVar15 = bVar15 | cVar7 << 4;
    (*(unsigned short *)((unsigned char *)&(local_2c) + 0)) = CONCAT11(bVar15,bVar14);
    local_2c = (uint)(ushort)local_2c;
    if (bVar6) {
      local_2c = CONCAT11(bVar15,bVar14) | 0x8000;
    }
    if (param_12 != '\0') {
      (*(unsigned short *)((unsigned char *)&(local_2c) + 0)) =
           CONCAT11((*(unsigned char *)((unsigned char *)&(local_2c) + 1)) & 0x77 | (((*(unsigned char *)((unsigned char *)&(local_2c) + 1)) >> 3 ^ 1) & 1) << 3 |
                    ~((*(unsigned char *)((unsigned char *)&(local_2c) + 1)) & 0xf7) & 0x80,
                    (byte)local_2c & 0x77 | (((byte)local_2c >> 3 ^ 1) & 1) << 3 |
                    ~((byte)local_2c & 0xf7) & 0x80);
      local_2c = (uint)(ushort)local_2c;
    }
    local_54 = 2;
LAB_000abc67:
    local_24 = CONCAT12((char)param_8[1],(short)*param_8) & 0xff3fffff | 0x400000;
    auStack_48[4] = param_20;
    auStack_48[3] = param_19;
    auStack_48[2] = param_18;
    auStack_48[1] = param_17;
    if (param_8[1] == 0x10) {
      iVar16 = 1;
      do {
        if (auStack_48[iVar16] < 0xb) {
                    
                    
          (*(code *)(*(int *)(((unsigned char *)0x000ac6f8) + auStack_48[iVar16] * 4) + 0xab21c))();
          return;
        }
        auStack_48[iVar16] = 0;
        iVar16 = iVar16 + 1;
      } while (iVar16 != 5);
    }
    switch(param_17) {
    default:
      bVar6 = false;
      bVar14 = 0;
      break;
    case 1:
      bVar6 = false;
      bVar14 = 1;
      break;
    case 2:
      bVar6 = false;
      bVar14 = 2;
      break;
    case 3:
      bVar6 = false;
      bVar14 = 3;
      break;
    case 4:
      bVar6 = false;
      bVar14 = 4;
      break;
    case 5:
      bVar6 = false;
      bVar14 = 5;
      break;
    case 6:
      bVar6 = true;
      bVar14 = 0;
      break;
    case 7:
      bVar6 = true;
      bVar14 = 1;
      break;
    case 8:
      bVar6 = true;
      bVar14 = 2;
      break;
    case 9:
      bVar6 = true;
      bVar14 = 3;
      break;
    case 10:
      bVar6 = true;
      bVar14 = 5;
    }
    if (bVar6) {
      bVar14 = bVar14 | 8;
    }
    switch(param_18) {
    default:
      bVar6 = false;
      cVar7 = '\0';
      break;
    case 1:
      bVar6 = false;
      cVar7 = '\x01';
      break;
    case 2:
      bVar6 = false;
      cVar7 = '\x02';
      break;
    case 3:
      bVar6 = false;
      cVar7 = '\x03';
      break;
    case 4:
      bVar6 = false;
      cVar7 = '\x04';
      break;
    case 5:
      bVar6 = false;
      cVar7 = '\x05';
      break;
    case 6:
      bVar6 = true;
      cVar7 = '\0';
      break;
    case 7:
      bVar6 = true;
      cVar7 = '\x01';
      break;
    case 8:
      bVar6 = true;
      cVar7 = '\x02';
      break;
    case 9:
      bVar6 = true;
      cVar7 = '\x03';
      break;
    case 10:
      bVar6 = true;
      cVar7 = '\x05';
    }
    bVar14 = bVar14 | cVar7 << 4;
    if (bVar6) {
      bVar14 = bVar14 | 0x80;
    }
    switch(param_19) {
    default:
      bVar6 = false;
      bVar15 = 0;
      break;
    case 1:
      bVar6 = false;
      bVar15 = 1;
      break;
    case 2:
      bVar6 = false;
      bVar15 = 2;
      break;
    case 3:
      bVar6 = false;
      bVar15 = 3;
      break;
    case 4:
      bVar6 = false;
      bVar15 = 4;
      break;
    case 5:
      bVar6 = false;
      bVar15 = 5;
      break;
    case 6:
      bVar6 = true;
      bVar15 = 0;
      break;
    case 7:
      bVar6 = true;
      bVar15 = 1;
      break;
    case 8:
      bVar6 = true;
      bVar15 = 2;
      break;
    case 9:
      bVar6 = true;
      bVar15 = 3;
      break;
    case 10:
      bVar6 = true;
      bVar15 = 5;
    }
    if (bVar6) {
      bVar15 = bVar15 | 8;
    }
    switch(param_20) {
    default:
      bVar6 = false;
      cVar7 = '\0';
      break;
    case 1:
      bVar6 = false;
      cVar7 = '\x01';
      break;
    case 2:
      bVar6 = false;
      cVar7 = '\x02';
      break;
    case 3:
      bVar6 = false;
      cVar7 = '\x03';
      break;
    case 4:
      bVar6 = false;
      cVar7 = '\x04';
      break;
    case 5:
      bVar6 = false;
      cVar7 = '\x05';
      break;
    case 6:
      bVar6 = true;
      cVar7 = '\0';
      break;
    case 7:
      bVar6 = true;
      cVar7 = '\x01';
      break;
    case 8:
      bVar6 = true;
      cVar7 = '\x02';
      break;
    case 9:
      bVar6 = true;
      cVar7 = '\x03';
      break;
    case 10:
      bVar6 = true;
      cVar7 = '\x05';
    }
    bVar15 = bVar15 | cVar7 << 4;
    (*(unsigned short *)((unsigned char *)&(local_30) + 0)) = CONCAT11(bVar15,bVar14);
    local_30 = (uint)(ushort)local_30;
    if (bVar6) {
      local_30 = CONCAT11(bVar15,bVar14) | 0x8000;
    }
    if (param_11 == '\0') {
      local_c8 = local_54 + 1;
    }
    else {
      (*(unsigned short *)((unsigned char *)&(local_30) + 0)) =
           CONCAT11((*(unsigned char *)((unsigned char *)&(local_30) + 1)) & 0x77 | (((*(unsigned char *)((unsigned char *)&(local_30) + 1)) >> 3 ^ 1) & 1) << 3 |
                    ~((*(unsigned char *)((unsigned char *)&(local_30) + 1)) & 0xf7) & 0x80,
                    (byte)local_30 & 0x77 | (((byte)local_30 >> 3 ^ 1) & 1) << 3 |
                    ~((byte)local_30 & 0xf7) & 0x80);
      local_30 = (uint)(ushort)local_30;
      local_c8 = local_54 + 1;
    }
LAB_000abcfe:
    local_28 = CONCAT12((char)*(int *)(param_7 + 2),(short)*(undefined4 *)param_7) & 0xff3fffff |
               0x400000;
    auStack_48[4] = param_16;
    auStack_48[3] = param_15;
    auStack_48[2] = param_14;
    auStack_48[1] = param_13;
    if (*(int *)(param_7 + 2) == 0x10) {
      iVar16 = 1;
      do {
        if (auStack_48[iVar16] < 0xb) {
                    
                    
          (*(code *)(*(int *)(((unsigned char *)0x000ac68c) + auStack_48[iVar16] * 4) + 0xab21c))();
          return;
        }
        auStack_48[iVar16] = 0;
        iVar16 = iVar16 + 1;
      } while (iVar16 != 5);
    }
    switch(param_13) {
    default:
      bVar6 = false;
      bVar14 = 0;
      break;
    case 1:
      bVar6 = false;
      bVar14 = 1;
      break;
    case 2:
      bVar6 = false;
      bVar14 = 2;
      break;
    case 3:
      bVar6 = false;
      bVar14 = 3;
      break;
    case 4:
      bVar6 = false;
      bVar14 = 4;
      break;
    case 5:
      bVar6 = false;
      bVar14 = 5;
      break;
    case 6:
      bVar6 = true;
      bVar14 = 0;
      break;
    case 7:
      bVar6 = true;
      bVar14 = 1;
      break;
    case 8:
      bVar6 = true;
      bVar14 = 2;
      break;
    case 9:
      bVar6 = true;
      bVar14 = 3;
      break;
    case 10:
      bVar6 = true;
      bVar14 = 5;
    }
    if (bVar6) {
      bVar14 = bVar14 | 8;
    }
    switch(param_14) {
    default:
      bVar6 = false;
      cVar7 = '\0';
      break;
    case 1:
      bVar6 = false;
      cVar7 = '\x01';
      break;
    case 2:
      bVar6 = false;
      cVar7 = '\x02';
      break;
    case 3:
      bVar6 = false;
      cVar7 = '\x03';
      break;
    case 4:
      bVar6 = false;
      cVar7 = '\x04';
      break;
    case 5:
      bVar6 = false;
      cVar7 = '\x05';
      break;
    case 6:
      bVar6 = true;
      cVar7 = '\0';
      break;
    case 7:
      bVar6 = true;
      cVar7 = '\x01';
      break;
    case 8:
      bVar6 = true;
      cVar7 = '\x02';
      break;
    case 9:
      bVar6 = true;
      cVar7 = '\x03';
      break;
    case 10:
      bVar6 = true;
      cVar7 = '\x05';
    }
    bVar14 = bVar14 | cVar7 << 4;
    if (bVar6) {
      bVar14 = bVar14 | 0x80;
    }
    switch(param_15) {
    default:
      bVar6 = false;
      bVar15 = 0;
      break;
    case 1:
      bVar6 = false;
      bVar15 = 1;
      break;
    case 2:
      bVar6 = false;
      bVar15 = 2;
      break;
    case 3:
      bVar6 = false;
      bVar15 = 3;
      break;
    case 4:
      bVar6 = false;
      bVar15 = 4;
      break;
    case 5:
      bVar6 = false;
      bVar15 = 5;
      break;
    case 6:
      bVar6 = true;
      bVar15 = 0;
      break;
    case 7:
      bVar6 = true;
      bVar15 = 1;
      break;
    case 8:
      bVar6 = true;
      bVar15 = 2;
      break;
    case 9:
      bVar6 = true;
      bVar15 = 3;
      break;
    case 10:
      bVar6 = true;
      bVar15 = 5;
    }
    if (bVar6) {
      bVar15 = bVar15 | 8;
    }
    switch(param_16) {
    default:
      bVar6 = false;
      cVar7 = '\0';
      break;
    case 1:
      bVar6 = false;
      cVar7 = '\x01';
      break;
    case 2:
      bVar6 = false;
      cVar7 = '\x02';
      break;
    case 3:
      bVar6 = false;
      cVar7 = '\x03';
      break;
    case 4:
      bVar6 = false;
      cVar7 = '\x04';
      break;
    case 5:
      bVar6 = false;
      cVar7 = '\x05';
      break;
    case 6:
      bVar6 = true;
      cVar7 = '\0';
      break;
    case 7:
      bVar6 = true;
      cVar7 = '\x01';
      break;
    case 8:
      bVar6 = true;
      cVar7 = '\x02';
      break;
    case 9:
      bVar6 = true;
      cVar7 = '\x03';
      break;
    case 10:
      bVar6 = true;
      cVar7 = '\x05';
    }
    bVar15 = bVar15 | cVar7 << 4;
    (*(unsigned short *)((unsigned char *)&(local_34) + 0)) = CONCAT11(bVar15,bVar14);
    local_34 = (uint)(ushort)local_34;
    if (bVar6) {
      local_34 = CONCAT11(bVar15,bVar14) | 0x8000;
    }
    if (param_10 != '\0') {
      (*(unsigned short *)((unsigned char *)&(local_34) + 0)) =
           CONCAT11((*(unsigned char *)((unsigned char *)&(local_34) + 1)) & 0x77 | (((*(unsigned char *)((unsigned char *)&(local_34) + 1)) >> 3 ^ 1) & 1) << 3 |
                    ~((*(unsigned char *)((unsigned char *)&(local_34) + 1)) & 0xf7) & 0x80,
                    (byte)local_34 & 0x77 | (((byte)local_34 >> 3 ^ 1) & 1) << 3 |
                    ~((byte)local_34 & 0xf7) & 0x80);
      local_34 = (uint)(ushort)local_34;
    }
    break;
  default:
    local_c8 = 0;
    break;
  case 0xd:
  case 0x2d:
    uVar8 = (short)*(undefined4 *)(param_2 + 0x88) + 2;
    uVar4 = *(uint *)(param_7 + 2);
    local_e4 = (uint)uVar8;
    uVar2 = *param_7;
    auStack_48[4] = param_16;
    auStack_48[3] = param_15;
    auStack_48[2] = param_14;
    auStack_48[1] = param_13;
    if (uVar4 == 0x10) {
      iVar16 = 1;
      do {
        if (auStack_48[iVar16] < 0xb) {
                    
                    
          (*(code *)(*(int *)(((unsigned char *)0x000ad6d4) + auStack_48[iVar16] * 4) + 0xab21c))();
          return;
        }
        auStack_48[iVar16] = 0;
        iVar16 = iVar16 + 1;
      } while (iVar16 != 5);
    }
    switch(param_13) {
    default:
      bVar6 = false;
      uVar13 = 0;
      break;
    case 1:
      bVar6 = false;
      uVar13 = 1;
      break;
    case 2:
      bVar6 = false;
      uVar13 = 2;
      break;
    case 3:
      bVar6 = false;
      uVar13 = 3;
      break;
    case 4:
      bVar6 = false;
      uVar13 = 4;
      break;
    case 5:
      bVar6 = false;
      uVar13 = 5;
      break;
    case 6:
      bVar6 = true;
      uVar13 = 0;
      break;
    case 7:
      bVar6 = true;
      uVar13 = 1;
      break;
    case 8:
      bVar6 = true;
      uVar13 = 2;
      break;
    case 9:
      bVar6 = true;
      uVar13 = 3;
      break;
    case 10:
      bVar6 = true;
      uVar13 = 5;
    }
    if (bVar6) {
      uVar13 = uVar13 | 8;
    }
    switch(param_14) {
    default:
      bVar6 = false;
      iVar16 = 0;
      break;
    case 1:
      bVar6 = false;
      iVar16 = 1;
      break;
    case 2:
      bVar6 = false;
      iVar16 = 2;
      break;
    case 3:
      bVar6 = false;
      iVar16 = 3;
      break;
    case 4:
      bVar6 = false;
      iVar16 = 4;
      break;
    case 5:
      bVar6 = false;
      iVar16 = 5;
      break;
    case 6:
      bVar6 = true;
      iVar16 = 0;
      break;
    case 7:
      bVar6 = true;
      iVar16 = 1;
      break;
    case 8:
      bVar6 = true;
      iVar16 = 2;
      break;
    case 9:
      bVar6 = true;
      iVar16 = 3;
      break;
    case 10:
      bVar6 = true;
      iVar16 = 5;
    }
    uVar13 = uVar13 | iVar16 << 4;
    if (bVar6) {
      uVar13 = uVar13 | 0x80;
    }
    switch(param_15) {
    default:
      bVar6 = false;
      iVar16 = 0;
      break;
    case 1:
      bVar6 = false;
      iVar16 = 1;
      break;
    case 2:
      bVar6 = false;
      iVar16 = 2;
      break;
    case 3:
      bVar6 = false;
      iVar16 = 3;
      break;
    case 4:
      bVar6 = false;
      iVar16 = 4;
      break;
    case 5:
      bVar6 = false;
      iVar16 = 5;
      break;
    case 6:
      bVar6 = true;
      iVar16 = 0;
      break;
    case 7:
      bVar6 = true;
      iVar16 = 1;
      break;
    case 8:
      bVar6 = true;
      iVar16 = 2;
      break;
    case 9:
      bVar6 = true;
      iVar16 = 3;
      break;
    case 10:
      bVar6 = true;
      iVar16 = 5;
    }
    uVar13 = uVar13 | iVar16 << 8;
    if (bVar6) {
      uVar13 = uVar13 | 0x800;
    }
    switch(param_16) {
    default:
      bVar6 = false;
      iVar16 = 0;
      break;
    case 1:
      bVar6 = false;
      iVar16 = 1;
      break;
    case 2:
      bVar6 = false;
      iVar16 = 2;
      break;
    case 3:
      bVar6 = false;
      iVar16 = 3;
      break;
    case 4:
      bVar6 = false;
      iVar16 = 4;
      break;
    case 5:
      bVar6 = false;
      iVar16 = 5;
      break;
    case 6:
      bVar6 = true;
      iVar16 = 0;
      break;
    case 7:
      bVar6 = true;
      iVar16 = 1;
      break;
    case 8:
      bVar6 = true;
      iVar16 = 2;
      break;
    case 9:
      bVar6 = true;
      iVar16 = 3;
      break;
    case 10:
      bVar6 = true;
      iVar16 = 5;
    }
    uVar13 = uVar13 | iVar16 << 0xc;
    if (bVar6) {
      uVar13 = uVar13 | 0x8000;
    }
    if (param_10 != '\0') {
      bVar14 = (byte)(uVar13 >> 8);
      uVar13 = uVar13 & 0xffff7777 | (((byte)(uVar13 >> 3) & 0x1f ^ 1) & 1) << 3 |
               (uint)((byte)~((byte)uVar13 & 0xf7) >> 7) << 7 | ((byte)(bVar14 >> 3 ^ 1) & 1) << 0xb
               | (uint)((byte)~(bVar14 & 0xf7) >> 7) << 0xf;
    }
    if (param_3[1] <= *param_3) {
      pvVar12 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar12,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar12;
      param_3[1] = param_3[1] + 0x80;
    }
    *(undefined4 *)(param_3[2] + *param_3 * 4) = 0x47;
    uVar5 = *param_3;
    *param_3 = uVar5 + 1;
    if (param_3[1] <= uVar5 + 1) {
      pvVar12 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar12,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar12;
      param_3[1] = param_3[1] + 0x80;
    }
    *(uint *)(param_3[2] + *param_3 * 4) = local_e4 | 0x40000;
    uVar5 = *param_3;
    *param_3 = uVar5 + 1;
    if (param_3[1] <= uVar5 + 1) {
      pvVar12 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar12,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar12;
      param_3[1] = param_3[1] + 0x80;
    }
    *(uint *)(param_3[2] + *param_3 * 4) = (uint)uVar2 | (uVar4 & 0x3f) << 0x10 | 0x400000;
    uVar4 = *param_3;
    *param_3 = uVar4 + 1;
    if (param_3[1] <= uVar4 + 1) {
      pvVar12 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar12,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar12;
      param_3[1] = param_3[1] + 0x80;
    }
    *(uint *)(param_3[2] + *param_3 * 4) = uVar13;
    uVar4 = *param_3;
    *param_3 = uVar4 + 1;
    local_e4 = (uint)uVar8;
    local_dc = (uint)uVar8;
    local_e0 = (uint)uVar8;
    if (param_3[1] <= uVar4 + 1) {
      pvVar12 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar12,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar12;
      param_3[1] = param_3[1] + 0x80;
    }
    *(undefined4 *)(param_3[2] + *param_3 * 4) = 0x2000d;
    uVar4 = *param_3;
    *param_3 = uVar4 + 1;
    if (param_3[1] <= uVar4 + 1) {
      pvVar12 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar12,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar12;
      param_3[1] = param_3[1] + 0x80;
    }
    *(uint *)(param_3[2] + *param_3 * 4) = local_e4 | 0x440000;
    uVar4 = *param_3;
    *param_3 = uVar4 + 1;
    if (param_3[1] <= uVar4 + 1) {
      pvVar12 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar12,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar12;
      param_3[1] = param_3[1] + 0x80;
    }
    *(undefined4 *)(param_3[2] + *param_3 * 4) = 4;
    uVar4 = *param_3;
    *param_3 = uVar4 + 1;
    if (param_3[1] <= uVar4 + 1) {
      pvVar12 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar12,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar12;
      param_3[1] = param_3[1] + 0x80;
    }
    *(uint *)(param_3[2] + *param_3 * 4) = local_dc | 0x40000;
    uVar4 = *param_3;
    *param_3 = uVar4 + 1;
    if (param_3[1] <= uVar4 + 1) {
      pvVar12 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar12,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar12;
      param_3[1] = param_3[1] + 0x80;
    }
    *(uint *)(param_3[2] + *param_3 * 4) = uVar8 | 0x40000;
    uVar4 = *param_3;
    *param_3 = uVar4 + 1;
    if (param_3[1] <= uVar4 + 1) {
      pvVar12 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar12,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar12;
      param_3[1] = param_3[1] + 0x80;
    }
    *(uint *)(param_3[2] + *param_3 * 4) = local_e0 | 0x440000;
    uVar4 = *param_3;
    *param_3 = uVar4 + 1;
    if (param_3[1] <= uVar4 + 1) {
      pvVar12 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar12,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar12;
      param_3[1] = param_3[1] + 0x80;
    }
    *(undefined4 *)(param_3[2] + *param_3 * 4) = 0x4444;
    *param_3 = *param_3 + 1;
    local_28 = CONCAT13((*(unsigned char *)((unsigned char *)&(local_28) + 3)),CONCAT12((*(unsigned char *)((unsigned char *)&(local_28) + 2)),uVar8)) & 0xff80ffff | 0x40000;
    local_c8 = 1;
  }
  switch(param_4) {
  case 0:
  case 0x21:
    local_d0 = 1;
    break;
  case 1:
  case 0x22:
    local_d0 = 3;
    break;
  case 2:
  case 0x23:
    local_d0 = 0x5000d;
    break;
  case 3:
  case 0x24:
    local_d0 = 0x12;
    goto LAB_000ab5f9;
  case 4:
  case 0x25:
    local_d0 = 0x22;
    break;
  case 5:
  case 0x26:
    local_d0 = 0x23;
    break;
  case 6:
  case 0x27:
    local_d0 = 0x23;
    local_34 = local_34 & 0xffff0fff | 0x5000;
    break;
  case 7:
  case 0x28:
    local_d0 = 0x24;
    break;
  case 8:
  case 0x29:
    local_d0 = 0x2d;
    break;
  case 9:
  case 0x2a:
    local_d0 = 0x30;
    break;
  case 10:
  case 0x2b:
    local_d0 = 0x31;
    break;
  case 0xc:
  case 0x2c:
    local_d0 = 0x3c;
    break;
  case 0xd:
  case 0x2d:
    local_d0 = 0x39;
    break;
  case 0xe:
  case 0x2e:
    local_d0 = 0x3f;
    break;
  case 0xf:
  case 0x2f:
    local_d0 = 0x40;
    break;
  case 0x10:
  case 0x30:
    local_d0 = 0x41;
    break;
  case 0x11:
  case 0x31:
    local_d0 = 0x44;
    break;
  case 0x12:
  case 0x1c:
  case 0x32:
  case 0x3c:
    local_d0 = 0x47;
    break;
  case 0x13:
  case 0x33:
    local_d0 = 0x49;
    break;
  case 0x14:
  case 0x34:
    local_d0 = 0x4e;
    break;
  case 0x15:
  case 0x35:
    local_d0 = 0x51;
    break;
  case 0x16:
  case 0x36:
    local_d0 = 0x55;
    local_34 = local_34 & 0xffff7777;
    local_34 = local_34 | 0x100000;
    break;
  case 0x17:
  case 0x37:
    local_d0 = 0x59;
    break;
  case 0x18:
  case 0x38:
    local_d0 = 0x20056;
    break;
  case 0x19:
  case 0x39:
    local_d0 = 0x58;
LAB_000ab5f9:
    if (param_3[1] <= *param_3) {
      pvVar12 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar12,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar12;
      param_3[1] = param_3[1] + 0x80;
    }
    *(undefined4 *)(param_3[2] + *param_3 * 4) = 0x4d;
    uVar4 = *param_3;
    *param_3 = uVar4 + 1;
    sVar1 = *(short *)(param_1 + 0x11e0);
    if (param_3[1] <= uVar4 + 1) {
      pvVar12 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar12,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar12;
      param_3[1] = param_3[1] + 0x80;
    }
    uVar13 = local_28;
    *(uint *)(param_3[2] + *param_3 * 4) = CONCAT22(4,sVar1 + 1);
    uVar4 = *param_3;
    *param_3 = uVar4 + 1;
    if (param_3[1] <= uVar4 + 1) {
      pvVar12 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar12,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar12;
      param_3[1] = param_3[1] + 0x80;
    }
    uVar5 = local_34;
    *(uint *)(param_3[2] + *param_3 * 4) = uVar13;
    uVar4 = *param_3;
    *param_3 = uVar4 + 1;
    if ((local_28 & 0x400000) != 0) {
      if (param_3[1] <= uVar4 + 1) {
        pvVar12 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
        if ((void *)param_3[2] != (void *)0x0) {
          _memcpy(pvVar12,(void *)param_3[2],*param_3 << 2);
          (**(code **)(param_1 + 0x18))(param_3[2]);
        }
        param_3[2] = (uint)pvVar12;
        param_3[1] = param_3[1] + 0x80;
      }
      *(uint *)(param_3[2] + *param_3 * 4) = uVar5;
      *param_3 = *param_3 + 1;
    }
    local_28 = CONCAT22(CONCAT11((*(unsigned char *)((unsigned char *)&(local_28) + 3)),(*(unsigned char *)((unsigned char *)&(local_28) + 2))),*(short *)(param_1 + 0x11e0) + 1) &
               0xffc0ffff | 0x40000;
    break;
  case 0x1a:
  case 0x3a:
    local_d0 = 0x50056;
    break;
  case 0x1b:
  case 0x3b:
    local_d0 = 0x5b;
    break;
  case 0x20:
  case 0x40:
    local_d0 = 0x13;
  }
  if (*(int *)(param_5 + 2) == 0x18) {
    if (local_c8 != 0) {
      iVar16 = 0;
      do {
        if ((*(byte *)((int)&local_28 + iVar16 * 4 + 2) & 0x40) != 0) {
          bVar14 = *(byte *)((int)&local_34 + iVar16 * 4 + 1);
          *(byte *)(&local_34 + iVar16) =
               *(byte *)(&local_34 + iVar16) & 0xf0 | bVar14 & 8 | bVar14 & 7;
        }
        iVar16 = iVar16 + 1;
      } while (local_c8 != iVar16);
    }
    uVar18 = uVar17 | uVar9 | uVar10 | uVar11 | uVar10 >> 4;
    bVar6 = false;
  }
  else if (*(int *)(param_5 + 2) == 0x17) {
    local_d4 = CONCAT22((short)(local_d4 >> 0x10),*(undefined2 *)(param_2 + 0x88)) & 0xffc0ffff |
               0x40000;
    bVar6 = true;
  }
  else {
    bVar6 = false;
  }
  if (param_3[1] <= *param_3) {
    pvVar12 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
    if ((void *)param_3[2] != (void *)0x0) {
      _memcpy(pvVar12,(void *)param_3[2],*param_3 << 2);
      (**(code **)(param_1 + 0x18))(param_3[2]);
    }
    param_3[2] = (uint)pvVar12;
    param_3[1] = param_3[1] + 0x80;
  }
  *(undefined4 *)(param_3[2] + *param_3 * 4) = local_d0;
  uVar17 = *param_3;
  *param_3 = uVar17 + 1;
  if (param_3[1] <= uVar17 + 1) {
    pvVar12 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
    if ((void *)param_3[2] != (void *)0x0) {
      _memcpy(pvVar12,(void *)param_3[2],*param_3 << 2);
      (**(code **)(param_1 + 0x18))(param_3[2]);
    }
    param_3[2] = (uint)pvVar12;
    param_3[1] = param_3[1] + 0x80;
  }
  *(uint *)(param_3[2] + *param_3 * 4) = local_d4;
  uVar17 = *param_3;
  *param_3 = uVar17 + 1;
  if ((local_d4 & 0x400000) != 0) {
    if (param_3[1] <= uVar17 + 1) {
      pvVar12 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar12,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar12;
      param_3[1] = param_3[1] + 0x80;
    }
    *(uint *)(param_3[2] + *param_3 * 4) = uVar18;
    *param_3 = *param_3 + 1;
  }
  if (local_c8 != 0) {
    local_50 = 0;
    puVar19 = &local_34;
    do {
      uVar3 = puVar19[3];
      if (param_3[1] <= *param_3) {
        pvVar12 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
        if ((void *)param_3[2] != (void *)0x0) {
          _memcpy(pvVar12,(void *)param_3[2],*param_3 << 2);
          (**(code **)(param_1 + 0x18))(param_3[2]);
        }
        param_3[2] = (uint)pvVar12;
        param_3[1] = param_3[1] + 0x80;
      }
      *(undefined4 *)(param_3[2] + *param_3 * 4) = uVar3;
      uVar17 = *param_3;
      *param_3 = uVar17 + 1;
      if ((*(byte *)((int)puVar19 + 0xe) & 0x40) != 0) {
        uVar3 = *puVar19;
        if (param_3[1] <= uVar17 + 1) {
          pvVar12 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
          if ((void *)param_3[2] != (void *)0x0) {
            _memcpy(pvVar12,(void *)param_3[2],*param_3 << 2);
            (**(code **)(param_1 + 0x18))(param_3[2]);
          }
          param_3[2] = (uint)pvVar12;
          param_3[1] = param_3[1] + 0x80;
        }
        *(undefined4 *)(param_3[2] + *param_3 * 4) = uVar3;
        *param_3 = *param_3 + 1;
      }
      local_50 = local_50 + 1;
      puVar19 = puVar19 + 1;
    } while (local_c8 != local_50);
  }
  if (!bVar6) {
    return;
  }
  ((int (*)())FUN_000ab0a5)();
  return;
}

/* FUN_000ad8d5 @ 0xad8d5 (3814 bytes) */
int FUN_000ad8d5(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13, param_14)
  int param_1;
  int param_2;
  uint *param_3;
  int param_4;
  ushort *param_5;
  uint param_6;
  ushort *param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
  undefined4 param_11;
  int param_12;
  uint param_13;
  int param_14;
{
  ushort uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  bool bVar5;
  char cVar6;
  ushort uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  void *pvVar11;
  uint uVar12;
  byte bVar13;
  byte bVar14;
  int iVar15;
  undefined4 *local_b4;
  uint local_a0;
  uint local_90;
  int local_8c;
  int local_88;
  uint auStack_44 [5];
  undefined4 local_30;
  uint local_2c;
  undefined4 local_28;
  uint local_24;
  uint local_20;
  
  local_20 = 0;
  local_28 = 0;
  local_30 = 0;
  local_24 = 0;
  local_2c = 0;
  uVar2 = *(uint *)(param_5 + 2);
  if (uVar2 == 0x17) {
    local_90 = *(ushort *)(param_2 + 0x88) | 0x440000;
  }
  else {
    local_90 = (uint)*param_5 | (uVar2 & 0x3f) << 0x10 | 0x400000;
  }
  uVar8 = 0x100;
  if (2 < param_4 - 0x3dU) {
    uVar8 = 0;
  }
  uVar9 = (uint)(param_14 - 6U < 3);
  uVar10 = 0x100;
  if (uVar2 != 0x18) {
    uVar10 = uVar8;
  }
  if ((param_4 == 0x1f) && (param_12 != '\0')) {
    uVar7 = (short)*(undefined4 *)(param_2 + 0x88) + 1;
    uVar8 = *(uint *)(param_7 + 2);
    local_a0 = (uint)uVar7;
    uVar1 = *param_7;
    auStack_44[4] = param_11;
    auStack_44[3] = param_10;
    auStack_44[2] = param_9;
    auStack_44[1] = param_8;
    if (uVar8 == 0x10) {
      iVar15 = 1;
      do {
        if (auStack_44[iVar15] < 0xb) {
                    
                    
          (*(code *)(*(int *)(((unsigned char *)0x000aea34) + auStack_44[iVar15] * 4) + 0xad8e6))();
          return;
        }
        auStack_44[iVar15] = 0;
        iVar15 = iVar15 + 1;
      } while (iVar15 != 5);
    }
    switch(auStack_44[1]) {
    default:
      bVar5 = false;
      uVar12 = 0;
      break;
    case 1:
      bVar5 = false;
      uVar12 = 1;
      break;
    case 2:
      bVar5 = false;
      uVar12 = 2;
      break;
    case 3:
      bVar5 = false;
      uVar12 = 3;
      break;
    case 4:
      bVar5 = false;
      uVar12 = 4;
      break;
    case 5:
      bVar5 = false;
      uVar12 = 5;
      break;
    case 6:
      bVar5 = true;
      uVar12 = 0;
      break;
    case 7:
      bVar5 = true;
      uVar12 = 1;
      break;
    case 8:
      bVar5 = true;
      uVar12 = 2;
      break;
    case 9:
      bVar5 = true;
      uVar12 = 3;
      break;
    case 10:
      bVar5 = true;
      uVar12 = 5;
    }
    if (bVar5) {
      uVar12 = uVar12 | 8;
    }
    switch(auStack_44[2]) {
    default:
      bVar5 = false;
      iVar15 = 0;
      break;
    case 1:
      bVar5 = false;
      iVar15 = 1;
      break;
    case 2:
      bVar5 = false;
      iVar15 = 2;
      break;
    case 3:
      bVar5 = false;
      iVar15 = 3;
      break;
    case 4:
      bVar5 = false;
      iVar15 = 4;
      break;
    case 5:
      bVar5 = false;
      iVar15 = 5;
      break;
    case 6:
      bVar5 = true;
      iVar15 = 0;
      break;
    case 7:
      bVar5 = true;
      iVar15 = 1;
      break;
    case 8:
      bVar5 = true;
      iVar15 = 2;
      break;
    case 9:
      bVar5 = true;
      iVar15 = 3;
      break;
    case 10:
      bVar5 = true;
      iVar15 = 5;
    }
    uVar12 = uVar12 | iVar15 << 4;
    if (bVar5) {
      uVar12 = uVar12 | 0x80;
    }
    switch(auStack_44[3]) {
    default:
      bVar5 = false;
      iVar15 = 0;
      break;
    case 1:
      bVar5 = false;
      iVar15 = 1;
      break;
    case 2:
      bVar5 = false;
      iVar15 = 2;
      break;
    case 3:
      bVar5 = false;
      iVar15 = 3;
      break;
    case 4:
      bVar5 = false;
      iVar15 = 4;
      break;
    case 5:
      bVar5 = false;
      iVar15 = 5;
      break;
    case 6:
      bVar5 = true;
      iVar15 = 0;
      break;
    case 7:
      bVar5 = true;
      iVar15 = 1;
      break;
    case 8:
      bVar5 = true;
      iVar15 = 2;
      break;
    case 9:
      bVar5 = true;
      iVar15 = 3;
      break;
    case 10:
      bVar5 = true;
      iVar15 = 5;
    }
    uVar12 = uVar12 | iVar15 << 8;
    if (bVar5) {
      uVar12 = uVar12 | 0x800;
    }
    switch(auStack_44[4]) {
    default:
      bVar5 = false;
      iVar15 = 0;
      break;
    case 1:
      bVar5 = false;
      iVar15 = 1;
      break;
    case 2:
      bVar5 = false;
      iVar15 = 2;
      break;
    case 3:
      bVar5 = false;
      iVar15 = 3;
      break;
    case 4:
      bVar5 = false;
      iVar15 = 4;
      break;
    case 5:
      bVar5 = false;
      iVar15 = 5;
      break;
    case 6:
      bVar5 = true;
      iVar15 = 0;
      break;
    case 7:
      bVar5 = true;
      iVar15 = 1;
      break;
    case 8:
      bVar5 = true;
      iVar15 = 2;
      break;
    case 9:
      bVar5 = true;
      iVar15 = 3;
      break;
    case 10:
      bVar5 = true;
      iVar15 = 5;
    }
    uVar12 = uVar12 | iVar15 << 0xc;
    if (bVar5) {
      uVar12 = uVar12 | 0x8000;
    }
    bVar13 = (byte)(uVar12 >> 8);
    if (param_3[1] <= *param_3) {
      pvVar11 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar11,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar11;
      param_3[1] = param_3[1] + 0x80;
    }
    *(undefined4 *)(param_3[2] + *param_3 * 4) = 0x47;
    uVar4 = *param_3;
    *param_3 = uVar4 + 1;
    if (param_3[1] <= uVar4 + 1) {
      pvVar11 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar11,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar11;
      param_3[1] = param_3[1] + 0x80;
    }
    *(uint *)(param_3[2] + *param_3 * 4) = local_a0 | 0x40000;
    uVar4 = *param_3;
    *param_3 = uVar4 + 1;
    if (param_3[1] <= uVar4 + 1) {
      pvVar11 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar11,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar11;
      param_3[1] = param_3[1] + 0x80;
    }
    *(uint *)(param_3[2] + *param_3 * 4) = (uint)uVar1 | (uVar8 & 0x3f) << 0x10 | 0x400000;
    uVar8 = *param_3;
    *param_3 = uVar8 + 1;
    if (param_3[1] <= uVar8 + 1) {
      pvVar11 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar11,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar11;
      param_3[1] = param_3[1] + 0x80;
    }
    *(uint *)(param_3[2] + *param_3 * 4) =
         uVar12 & 0xffff7777 | (((byte)(uVar12 >> 3) & 0x1f ^ 1) & 1) << 3 |
         (uint)((byte)~((byte)uVar12 & 0xf7) >> 7) << 7 | ((byte)(bVar13 >> 3 ^ 1) & 1) << 0xb |
         (uint)((byte)~(bVar13 & 0xf7) >> 7) << 0xf;
    *param_3 = *param_3 + 1;
    bVar13 = (*(unsigned char *)((unsigned char *)&(local_28) + 2)) & 0xc0;
    local_28 = CONCAT13((*(unsigned char *)((unsigned char *)&(local_28) + 3)),CONCAT12((*(unsigned char *)((unsigned char *)&(local_28) + 2)),uVar7)) & 0xffc0ffff;
    local_30 = local_30 & 0xffff8888 | 0x3210;
    bVar13 = bVar13 | 4;
LAB_000ae1dc:
    local_20 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_20) + 2)),0x5d);
    local_28 = CONCAT13((*(unsigned char *)((unsigned char *)&(local_28) + 3)),CONCAT12(bVar13,(undefined2)local_28)) | 0x400000;
    local_30 = local_30 & 0xff1fffff | 0x600000;
    local_20 = local_20 & 0xc000ffff | (param_13 & 0x33ff) << 0x10 | uVar9 << 0x1a;
    local_8c = 1;
  }
  else {
    local_28 = CONCAT12((char)*(int *)(param_7 + 2),(short)*(undefined4 *)param_7) & 0xff3fffff |
               0x400000;
    auStack_44[4] = param_11;
    auStack_44[3] = param_10;
    auStack_44[2] = param_9;
    auStack_44[1] = param_8;
    if (*(int *)(param_7 + 2) == 0x10) {
      iVar15 = 1;
      do {
        if (auStack_44[iVar15] < 0xb) {
                    
                    
          (*(code *)(*(int *)(((unsigned char *)0x000ae084) + auStack_44[iVar15] * 4) + 0xad8e6))();
          return;
        }
        auStack_44[iVar15] = 0;
        iVar15 = iVar15 + 1;
      } while (iVar15 != 5);
    }
    switch(auStack_44[1]) {
    default:
      bVar5 = false;
      bVar13 = 0;
      break;
    case 1:
      bVar5 = false;
      bVar13 = 1;
      break;
    case 2:
      bVar5 = false;
      bVar13 = 2;
      break;
    case 3:
      bVar5 = false;
      bVar13 = 3;
      break;
    case 4:
      bVar5 = false;
      bVar13 = 4;
      break;
    case 5:
      bVar5 = false;
      bVar13 = 5;
      break;
    case 6:
      bVar5 = true;
      bVar13 = 0;
      break;
    case 7:
      bVar5 = true;
      bVar13 = 1;
      break;
    case 8:
      bVar5 = true;
      bVar13 = 2;
      break;
    case 9:
      bVar5 = true;
      bVar13 = 3;
      break;
    case 10:
      bVar5 = true;
      bVar13 = 5;
    }
    if (bVar5) {
      bVar13 = bVar13 | 8;
    }
    switch(auStack_44[2]) {
    default:
      bVar5 = false;
      cVar6 = '\0';
      break;
    case 1:
      bVar5 = false;
      cVar6 = '\x01';
      break;
    case 2:
      bVar5 = false;
      cVar6 = '\x02';
      break;
    case 3:
      bVar5 = false;
      cVar6 = '\x03';
      break;
    case 4:
      bVar5 = false;
      cVar6 = '\x04';
      break;
    case 5:
      bVar5 = false;
      cVar6 = '\x05';
      break;
    case 6:
      bVar5 = true;
      cVar6 = '\0';
      break;
    case 7:
      bVar5 = true;
      cVar6 = '\x01';
      break;
    case 8:
      bVar5 = true;
      cVar6 = '\x02';
      break;
    case 9:
      bVar5 = true;
      cVar6 = '\x03';
      break;
    case 10:
      bVar5 = true;
      cVar6 = '\x05';
    }
    bVar13 = bVar13 | cVar6 << 4;
    if (bVar5) {
      bVar13 = bVar13 | 0x80;
    }
    switch(auStack_44[3]) {
    default:
      bVar5 = false;
      bVar14 = 0;
      break;
    case 1:
      bVar5 = false;
      bVar14 = 1;
      break;
    case 2:
      bVar5 = false;
      bVar14 = 2;
      break;
    case 3:
      bVar5 = false;
      bVar14 = 3;
      break;
    case 4:
      bVar5 = false;
      bVar14 = 4;
      break;
    case 5:
      bVar5 = false;
      bVar14 = 5;
      break;
    case 6:
      bVar5 = true;
      bVar14 = 0;
      break;
    case 7:
      bVar5 = true;
      bVar14 = 1;
      break;
    case 8:
      bVar5 = true;
      bVar14 = 2;
      break;
    case 9:
      bVar5 = true;
      bVar14 = 3;
      break;
    case 10:
      bVar5 = true;
      bVar14 = 5;
    }
    if (bVar5) {
      bVar14 = bVar14 | 8;
    }
    switch(auStack_44[4]) {
    default:
      bVar5 = false;
      cVar6 = '\0';
      break;
    case 1:
      bVar5 = false;
      cVar6 = '\x01';
      break;
    case 2:
      bVar5 = false;
      cVar6 = '\x02';
      break;
    case 3:
      bVar5 = false;
      cVar6 = '\x03';
      break;
    case 4:
      bVar5 = false;
      cVar6 = '\x04';
      break;
    case 5:
      bVar5 = false;
      cVar6 = '\x05';
      break;
    case 6:
      bVar5 = true;
      cVar6 = '\0';
      break;
    case 7:
      bVar5 = true;
      cVar6 = '\x01';
      break;
    case 8:
      bVar5 = true;
      cVar6 = '\x02';
      break;
    case 9:
      bVar5 = true;
      cVar6 = '\x03';
      break;
    case 10:
      bVar5 = true;
      cVar6 = '\x05';
    }
    bVar14 = bVar14 | cVar6 << 4;
    (*(unsigned short *)((unsigned char *)&(local_30) + 0)) = CONCAT11(bVar14,bVar13);
    local_30 = (uint)(ushort)local_30;
    if (bVar5) {
      local_30 = CONCAT11(bVar14,bVar13) | 0x8000;
    }
    if (param_12 != '\0') {
      (*(unsigned short *)((unsigned char *)&(local_30) + 0)) =
           CONCAT11((*(unsigned char *)((unsigned char *)&(local_30) + 1)) & 0x77 | (((*(unsigned char *)((unsigned char *)&(local_30) + 1)) >> 3 ^ 1) & 1) << 3 |
                    ~((*(unsigned char *)((unsigned char *)&(local_30) + 1)) & 0xf7) & 0x80,
                    (byte)local_30 & 0x77 | (((byte)local_30 >> 3 ^ 1) & 1) << 3 |
                    ~((byte)local_30 & 0xf7) & 0x80);
      local_30 = (uint)(ushort)local_30;
    }
    switch(param_4) {
    case 0xb:
      local_20 = 0x37;
      local_8c = 1;
      break;
    default:
      local_8c = 0;
      break;
    case 0x1d:
    case 0x3d:
      local_20 = (param_13 & 0x33ff) << 0x10 | 0x5d | uVar9 << 0x1a;
      local_8c = 1;
      break;
    case 0x1e:
    case 0x3e:
      local_20 = (param_13 & 0x33ff) << 0x10 | 0x5e | uVar9 << 0x1a;
      local_24 = local_28;
      local_2c = local_30;
      local_8c = 2;
      break;
    case 0x1f:
    case 0x3f:
      bVar13 = (*(unsigned char *)((unsigned char *)&(local_28) + 2));
      goto LAB_000ae1dc;
    }
  }
  uVar8 = local_20;
  if (param_3[1] <= *param_3) {
    pvVar11 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
    if ((void *)param_3[2] != (void *)0x0) {
      _memcpy(pvVar11,(void *)param_3[2],*param_3 << 2);
      (**(code **)(param_1 + 0x18))(param_3[2]);
    }
    param_3[2] = (uint)pvVar11;
    param_3[1] = param_3[1] + 0x80;
  }
  *(uint *)(param_3[2] + *param_3 * 4) = uVar8;
  uVar8 = *param_3;
  *param_3 = uVar8 + 1;
  if (param_4 != 0xb) {
    if (param_3[1] <= uVar8 + 1) {
      pvVar11 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar11,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar11;
      param_3[1] = param_3[1] + 0x80;
    }
    *(uint *)(param_3[2] + *param_3 * 4) = local_90;
    uVar8 = *param_3;
    *param_3 = uVar8 + 1;
    if ((local_90 & 0x400000) != 0) {
      if (param_3[1] <= uVar8 + 1) {
        pvVar11 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
        if ((void *)param_3[2] != (void *)0x0) {
          _memcpy(pvVar11,(void *)param_3[2],*param_3 << 2);
          (**(code **)(param_1 + 0x18))(param_3[2]);
        }
        param_3[2] = (uint)pvVar11;
        param_3[1] = param_3[1] + 0x80;
      }
      *(uint *)(param_3[2] + *param_3 * 4) =
           uVar10 | param_6 & 1 | param_6 * 2 & 4 | param_6 * 4 & 0x10 | param_6 * 8 & 0x40;
      *param_3 = *param_3 + 1;
    }
  }
  if (local_8c != 0) {
    local_88 = 0;
    local_b4 = &local_30;
    do {
      uVar3 = local_b4[2];
      if (param_3[1] <= *param_3) {
        pvVar11 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
        if ((void *)param_3[2] != (void *)0x0) {
          _memcpy(pvVar11,(void *)param_3[2],*param_3 << 2);
          (**(code **)(param_1 + 0x18))(param_3[2]);
        }
        param_3[2] = (uint)pvVar11;
        param_3[1] = param_3[1] + 0x80;
      }
      *(undefined4 *)(param_3[2] + *param_3 * 4) = uVar3;
      uVar8 = *param_3;
      *param_3 = uVar8 + 1;
      if ((*(byte *)((int)local_b4 + 10) & 0x40) != 0) {
        uVar3 = *local_b4;
        if (param_3[1] <= uVar8 + 1) {
          pvVar11 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
          if ((void *)param_3[2] != (void *)0x0) {
            _memcpy(pvVar11,(void *)param_3[2],*param_3 << 2);
            (**(code **)(param_1 + 0x18))(param_3[2]);
          }
          param_3[2] = (uint)pvVar11;
          param_3[1] = param_3[1] + 0x80;
        }
        *(undefined4 *)(param_3[2] + *param_3 * 4) = uVar3;
        *param_3 = *param_3 + 1;
      }
      local_88 = local_88 + 1;
      local_b4 = local_b4 + 1;
    } while (local_8c != local_88);
  }
  if (uVar2 == 0x17) {
    ((int (*)())FUN_000ab0a5)(*(undefined4 *)param_5);
  }
  return;
}

/* FUN_000aea8d @ 0xaea8d (5877 bytes) */
int FUN_000aea8d(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  code *pcVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  undefined1 uVar10;
  undefined1 uVar11;
  undefined1 uVar12;
  char cVar13;
  undefined4 uVar14;
  undefined4 *puVar15;
  void *pvVar16;
  uint *puVar17;
  int iVar18;
  int iVar19;
  char *pcVar20;
  int iVar21;
  uint uVar22;
  char *local_248;
  uint *local_238;
  undefined4 local_220;
  int local_20c;
  int local_208;
  char *local_204;
  int local_1ec;
  int local_1d8;
  uint local_1d0;
  int local_1cc;
  int local_1c8;
  int local_1c4;
  char *local_1c0;
  char local_1b4 [256];
  uint local_b4;
  uint local_b0;
  uint local_ac;
  uint local_a8;
  uint local_a4;
  uint local_a0;
  uint local_9c;
  uint local_98;
  uint local_94;
  uint local_90;
  uint local_8c;
  uint local_88;
  uint local_84;
  uint local_80;
  uint local_7c;
  uint local_78;
  uint local_74;
  uint local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_44;
  uint local_40;
  void *local_3c;
  undefined1 local_38 [8];
  undefined1 local_30 [8];
  undefined1 local_28 [11];
  char local_1d [13];
  
  local_20c = *(int *)(param_1 + 0x121c);
  local_248 = *(char **)(local_20c + 0x74);
  if (local_248[0x54] == '\0') {
    local_20c = *(int *)(*(int *)(*(int *)(param_1 + 0x112c) + 8) + 0x14 +
                        *(int *)(param_1 + 0x1220) * 0x18);
    local_248 = *(char **)(local_20c + 0x74);
  }
  puVar15 = (undefined4 *)(*(int *)(local_20c + 0x70) + *(int *)(param_1 + 0x1130) * 4);
  local_204 = (char *)*puVar15;
  if (local_204 == (char *)0x0) {
    pcVar2 = *(code **)(param_1 + 0x10);
    uVar14 = (**(code **)(param_1 + 0x1284))(param_1);
    uVar14 = (*pcVar2)(1,uVar14);
    *puVar15 = uVar14;
  }
  else {
    if ((param_2 != 1) && (local_204[0x119] == '\0')) goto LAB_000aed45;
    *puVar15 = 0;
    (**(code **)(param_1 + 0x1224))(param_1,local_204);
    iVar18 = *(int *)(param_1 + 0x1130);
    iVar21 = *(int *)(local_20c + 0x70);
    pcVar2 = *(code **)(param_1 + 0x10);
    uVar14 = (**(code **)(param_1 + 0x1284))(param_1);
    uVar14 = (*pcVar2)(1,uVar14);
    *(undefined4 *)(iVar21 + iVar18 * 4) = uVar14;
  }
  local_204 = *(char **)(*(int *)(local_20c + 0x70) + *(int *)(param_1 + 0x1130) * 4);
  *local_204 = '\0';
  if (local_248[0x55] == '\0') {
    local_44 = 0;
    local_40 = 0;
    local_3c = (void *)0x0;
    pvVar16 = (void *)(**(code **)(param_1 + 0xc))(0x200);
    if (local_3c != (void *)0x0) {
      _memcpy(pvVar16,local_3c,local_44 << 2);
      (**(code **)(param_1 + 0x18))(local_3c);
    }
    local_40 = local_40 + 0x80;
    *(undefined4 *)((int)pvVar16 + local_44 * 4) = 1;
    local_44 = local_44 + 1;
    local_3c = pvVar16;
    if (local_40 <= local_44) {
      pvVar16 = (void *)(**(code **)(param_1 + 0xc))(local_40 * 4 + 0x200);
      if (local_3c != (void *)0x0) {
        _memcpy(pvVar16,local_3c,local_44 << 2);
        (**(code **)(param_1 + 0x18))(local_3c);
      }
      local_40 = local_40 + 0x80;
      local_3c = pvVar16;
    }
    *(undefined **)((int)local_3c + local_44 * 4) = ((unsigned char *)0x00010200);
    local_44 = local_44 + 1;
    if (local_40 <= local_44) {
      pvVar16 = (void *)(**(code **)(param_1 + 0xc))(local_40 * 4 + 0x200);
      if (local_3c != (void *)0x0) {
        _memcpy(pvVar16,local_3c,local_44 << 2);
        (**(code **)(param_1 + 0x18))(local_3c);
      }
      local_40 = local_40 + 0x80;
      local_3c = pvVar16;
    }
    *(undefined4 *)((int)local_3c + local_44 * 4) = 0x1ff0016;
    local_44 = local_44 + 1;
    if (local_40 <= local_44) {
      pvVar16 = (void *)(**(code **)(param_1 + 0xc))(local_40 * 4 + 0x200);
      if (local_3c != (void *)0x0) {
        _memcpy(pvVar16,local_3c,local_44 << 2);
        (**(code **)(param_1 + 0x18))(local_3c);
      }
      local_40 = local_40 + 0x80;
      local_3c = pvVar16;
    }
    *(undefined4 *)((int)local_3c + local_44 * 4) = 0x120000;
    local_44 = local_44 + 1;
    if (*local_248 != '\0') {
      if (local_40 <= local_44) {
        pvVar16 = (void *)(**(code **)(param_1 + 0xc))(local_40 * 4 + 0x200);
        if (local_3c != (void *)0x0) {
          _memcpy(pvVar16,local_3c,local_44 << 2);
          (**(code **)(param_1 + 0x18))(local_3c);
        }
        local_40 = local_40 + 0x80;
        local_3c = pvVar16;
      }
      *(undefined4 *)((int)local_3c + local_44 * 4) = 0x1ff0016;
      local_44 = local_44 + 1;
      if (local_40 <= local_44) {
        pvVar16 = (void *)(**(code **)(param_1 + 0xc))(local_40 * 4 + 0x200);
        if (local_3c != (void *)0x0) {
          _memcpy(pvVar16,local_3c,local_44 << 2);
          (**(code **)(param_1 + 0x18))(local_3c);
        }
        local_40 = local_40 + 0x80;
        local_3c = pvVar16;
      }
      *(undefined4 *)((int)local_3c + local_44 * 4) = 0x130000;
      local_44 = local_44 + 1;
    }
    if (local_248[1] != '\0') {
      if (local_40 <= local_44) {
        pvVar16 = (void *)(**(code **)(param_1 + 0xc))(local_40 * 4 + 0x200);
        if (local_3c != (void *)0x0) {
          _memcpy(pvVar16,local_3c,local_44 << 2);
          (**(code **)(param_1 + 0x18))(local_3c);
        }
        local_40 = local_40 + 0x80;
        local_3c = pvVar16;
      }
      *(undefined4 *)((int)local_3c + local_44 * 4) = 0x1ff0016;
      local_44 = local_44 + 1;
      if (local_40 <= local_44) {
        pvVar16 = (void *)(**(code **)(param_1 + 0xc))(local_40 * 4 + 0x200);
        if (local_3c != (void *)0x0) {
          _memcpy(pvVar16,local_3c,local_44 << 2);
          (**(code **)(param_1 + 0x18))(local_3c);
        }
        local_40 = local_40 + 0x80;
        local_3c = pvVar16;
      }
      *(undefined4 *)((int)local_3c + local_44 * 4) = 0x100000;
      local_44 = local_44 + 1;
    }
    if (local_248[2] != '\0') {
      if (local_40 <= local_44) {
        pvVar16 = (void *)(**(code **)(param_1 + 0xc))(local_40 * 4 + 0x200);
        if (local_3c != (void *)0x0) {
          _memcpy(pvVar16,local_3c,local_44 << 2);
          (**(code **)(param_1 + 0x18))(local_3c);
        }
        local_40 = local_40 + 0x80;
        local_3c = pvVar16;
      }
      *(undefined4 *)((int)local_3c + local_44 * 4) = 0x3ff0016;
      local_44 = local_44 + 1;
      if (local_40 <= local_44) {
        pvVar16 = (void *)(**(code **)(param_1 + 0xc))(local_40 * 4 + 0x200);
        if (local_3c != (void *)0x0) {
          _memcpy(pvVar16,local_3c,local_44 << 2);
          (**(code **)(param_1 + 0x18))(local_3c);
        }
        local_40 = local_40 + 0x80;
        local_3c = pvVar16;
      }
      *(undefined4 *)((int)local_3c + local_44 * 4) = 0x160000;
      local_44 = local_44 + 1;
    }
    if (*(char *)(param_1 + 0x13b1) != '\0') {
      local_1d0 = 0x3ff0016;
      local_1c0 = local_248;
      iVar18 = 0;
      do {
        uVar22 = 1 << ((byte)iVar18 & 0x1f);
        if ((*(uint *)(local_248 + 0x10) & uVar22) != 0) {
          switch(*(undefined4 *)(local_1c0 + 0x14)) {
          case 0:
            local_1d0 = iVar18 << 0x10 | 0x8000019;
            break;
          case 1:
          case 6:
            local_1d0 = iVar18 << 0x10 | 0x9000019;
            break;
          case 2:
          case 7:
            local_1d0 = iVar18 << 0x10 | 0xa000019;
            break;
          case 3:
            local_1d0 = iVar18 << 0x10 | 0xb000019;
            break;
          case 4:
            local_1d0 = iVar18 << 0x10 | 0xc000019;
            break;
          case 5:
          case 8:
            local_1d0 = iVar18 << 0x10 | 0x12000019;
          }
          if (local_40 <= local_44) {
            pvVar16 = (void *)(**(code **)(param_1 + 0xc))(local_40 * 4 + 0x200);
            if (local_3c != (void *)0x0) {
              _memcpy(pvVar16,local_3c,local_44 << 2);
              (**(code **)(param_1 + 0x18))(local_3c);
            }
            local_40 = local_40 + 0x80;
            local_3c = pvVar16;
          }
          *(uint *)((int)local_3c + local_44 * 4) = local_1d0;
          local_44 = local_44 + 1;
        }
        if ((iVar18 < (int)(uint)*(byte *)(param_1 + 0x13b0)) &&
           ((*(uint *)(local_248 + 0xc) & uVar22) != 0)) {
          if (local_40 <= local_44) {
            pvVar16 = (void *)(**(code **)(param_1 + 0xc))(local_40 * 4 + 0x200);
            if (local_3c != (void *)0x0) {
              _memcpy(pvVar16,local_3c,local_44 << 2);
              (**(code **)(param_1 + 0x18))(local_3c);
            }
            local_40 = local_40 + 0x80;
            local_3c = pvVar16;
          }
          *(undefined4 *)((int)local_3c + local_44 * 4) = 0x1ff0016;
          local_44 = local_44 + 1;
          if (local_40 <= local_44) {
            pvVar16 = (void *)(**(code **)(param_1 + 0xc))(local_40 * 4 + 0x200);
            if (local_3c != (void *)0x0) {
              _memcpy(pvVar16,local_3c,local_44 << 2);
              (**(code **)(param_1 + 0x18))(local_3c);
            }
            local_40 = local_40 + 0x80;
            local_3c = pvVar16;
          }
          *(uint *)((int)local_3c + local_44 * 4) = CONCAT22(0x11,(short)iVar18);
          local_44 = local_44 + 1;
        }
        iVar18 = iVar18 + 1;
        local_1c0 = local_1c0 + 4;
      } while (iVar18 < (int)(uint)*(byte *)(param_1 + 0x13b1));
    }
    local_220 = 0x10000;
    if (0 < *(int *)(local_248 + 0x84)) {
      local_1ec = 0;
      local_1c4 = 0;
      do {
        iVar18 = local_1c4 + *(int *)(local_248 + 0x80);
        if (*(int *)(iVar18 + 8) == 0x34) {
          local_220 = CONCAT22((short)((uint)local_220 >> 0x10),*(undefined2 *)(iVar18 + 4));
          if (local_40 <= local_44) {
            pvVar16 = (void *)(**(code **)(param_1 + 0xc))(local_40 * 4 + 0x200);
            if (local_3c != (void *)0x0) {
              _memcpy(pvVar16,local_3c,local_44 << 2);
              (**(code **)(param_1 + 0x18))(local_3c);
            }
            local_40 = local_40 + 0x80;
            local_3c = pvVar16;
          }
          *(undefined4 *)((int)local_3c + local_44 * 4) = 0x1c;
          local_44 = local_44 + 1;
          if (local_40 <= local_44) {
            pvVar16 = (void *)(**(code **)(param_1 + 0xc))(local_40 * 4 + 0x200);
            if (local_3c != (void *)0x0) {
              _memcpy(pvVar16,local_3c,local_44 << 2);
              (**(code **)(param_1 + 0x18))(local_3c);
            }
            local_40 = local_40 + 0x80;
            local_3c = pvVar16;
          }
          *(undefined4 *)((int)local_3c + local_44 * 4) = local_220;
          local_44 = local_44 + 1;
          uVar14 = *(undefined4 *)(*(int *)(iVar18 + 0xc) * 0x10 + *(int *)(local_248 + 0x8c));
          if (local_40 <= local_44) {
            pvVar16 = (void *)(**(code **)(param_1 + 0xc))(local_40 * 4 + 0x200);
            if (local_3c != (void *)0x0) {
              _memcpy(pvVar16,local_3c,local_44 << 2);
              (**(code **)(param_1 + 0x18))(local_3c);
            }
            local_40 = local_40 + 0x80;
            local_3c = pvVar16;
          }
          *(undefined4 *)((int)local_3c + local_44 * 4) = uVar14;
          local_44 = local_44 + 1;
          uVar14 = *(undefined4 *)(*(int *)(iVar18 + 0xc) * 0x10 + *(int *)(local_248 + 0x8c) + 4);
          if (local_40 <= local_44) {
            pvVar16 = (void *)(**(code **)(param_1 + 0xc))(local_40 * 4 + 0x200);
            if (local_3c != (void *)0x0) {
              _memcpy(pvVar16,local_3c,local_44 << 2);
              (**(code **)(param_1 + 0x18))(local_3c);
            }
            local_40 = local_40 + 0x80;
            local_3c = pvVar16;
          }
          *(undefined4 *)((int)local_3c + local_44 * 4) = uVar14;
          local_44 = local_44 + 1;
          uVar14 = *(undefined4 *)(*(int *)(iVar18 + 0xc) * 0x10 + *(int *)(local_248 + 0x8c) + 8);
          if (local_40 <= local_44) {
            pvVar16 = (void *)(**(code **)(param_1 + 0xc))(local_40 * 4 + 0x200);
            if (local_3c != (void *)0x0) {
              _memcpy(pvVar16,local_3c,local_44 << 2);
              (**(code **)(param_1 + 0x18))(local_3c);
            }
            local_40 = local_40 + 0x80;
            local_3c = pvVar16;
          }
          *(undefined4 *)((int)local_3c + local_44 * 4) = uVar14;
          local_44 = local_44 + 1;
          uVar14 = *(undefined4 *)(*(int *)(iVar18 + 0xc) * 0x10 + *(int *)(local_248 + 0x8c) + 0xc)
          ;
          if (local_40 <= local_44) {
            pvVar16 = (void *)(**(code **)(param_1 + 0xc))(local_40 * 4 + 0x200);
            if (local_3c != (void *)0x0) {
              _memcpy(pvVar16,local_3c,local_44 << 2);
              (**(code **)(param_1 + 0x18))(local_3c);
            }
            local_40 = local_40 + 0x80;
            local_3c = pvVar16;
          }
          *(undefined4 *)((int)local_3c + local_44 * 4) = uVar14;
          local_44 = local_44 + 1;
        }
        local_1ec = local_1ec + 1;
        local_1c4 = local_1c4 + 0x14;
      } while (local_1ec < *(int *)(local_248 + 0x84));
    }
    if (**(int **)(local_248 + 100) == 0x41) {
LAB_000aec50:
      if (local_40 <= local_44) {
        pvVar16 = (void *)(**(code **)(param_1 + 0xc))(local_40 * 4 + 0x200);
        if (local_3c != (void *)0x0) {
          _memcpy(pvVar16,local_3c,local_44 << 2);
          (**(code **)(param_1 + 0x18))(local_3c);
        }
        local_40 = local_40 + 0x80;
        local_3c = pvVar16;
      }
      *(undefined4 *)((int)local_3c + local_44 * 4) = 0x47;
      local_44 = local_44 + 1;
      if (local_40 <= local_44) {
        pvVar16 = (void *)(**(code **)(param_1 + 0xc))(local_40 * 4 + 0x200);
        if (local_3c != (void *)0x0) {
          _memcpy(pvVar16,local_3c,local_44 << 2);
          (**(code **)(param_1 + 0x18))(local_3c);
        }
        local_40 = local_40 + 0x80;
        local_3c = pvVar16;
      }
      *(undefined4 *)((int)local_3c + local_44 * 4) = 0x570000;
      local_44 = local_44 + 1;
      if (local_40 <= local_44) {
        pvVar16 = (void *)(**(code **)(param_1 + 0xc))(local_40 * 4 + 0x200);
        if (local_3c != (void *)0x0) {
          _memcpy(pvVar16,local_3c,local_44 << 2);
          (**(code **)(param_1 + 0x18))(local_3c);
        }
        local_40 = local_40 + 0x80;
        local_3c = pvVar16;
      }
      *(undefined4 *)((int)local_3c + local_44 * 4) = 0;
      local_44 = local_44 + 1;
      if (local_40 <= local_44) {
        pvVar16 = (void *)(**(code **)(param_1 + 0xc))(local_40 * 4 + 0x200);
        if (local_3c != (void *)0x0) {
          _memcpy(pvVar16,local_3c,local_44 << 2);
          (**(code **)(param_1 + 0x18))(local_3c);
        }
        local_40 = local_40 + 0x80;
        local_3c = pvVar16;
      }
      *(undefined4 *)((int)local_3c + local_44 * 4) = 0x40000;
      local_44 = local_44 + 1;
    }
    else {
      local_208 = 0;
      bVar9 = false;
      local_1c8 = 0x70;
      iVar18 = 0;
      do {
        local_1d[0] = '\0';
        puVar17 = (uint *)(iVar18 + *(int *)(local_248 + 100));
        uVar22 = *puVar17;
        local_54 = puVar17[1];
        local_50 = puVar17[2];
        uVar3 = puVar17[3];
        local_b4 = puVar17[4];
        local_b0 = puVar17[5];
        local_ac = puVar17[6];
        local_a8 = puVar17[7];
        local_a4 = puVar17[8];
        local_a0 = puVar17[9];
        uVar4 = puVar17[10];
        local_98 = puVar17[0xb];
        (*(unsigned char *)((unsigned char *)&(local_9c) + 0)) = (undefined1)uVar4;
        uVar10 = (undefined1)local_9c;
        local_94 = puVar17[0xc];
        local_90 = puVar17[0xd];
        local_8c = puVar17[0xe];
        local_88 = puVar17[0xf];
        local_84 = puVar17[0x10];
        local_80 = puVar17[0x11];
        uVar5 = puVar17[0x12];
        uVar6 = puVar17[0x13];
        (*(unsigned char *)((unsigned char *)&(local_7c) + 0)) = (undefined1)uVar5;
        uVar11 = (undefined1)local_7c;
        local_74 = puVar17[0x14];
        local_70 = puVar17[0x15];
        local_6c = puVar17[0x16];
        local_68 = puVar17[0x17];
        local_64 = puVar17[0x18];
        local_60 = puVar17[0x19];
        uVar7 = puVar17[0x1a];
        uVar8 = puVar17[0x1b];
        (*(unsigned char *)((unsigned char *)&(local_5c) + 0)) = (undefined1)uVar7;
        uVar12 = (undefined1)local_5c;
        local_9c = uVar4;
        local_7c = uVar5;
        local_78 = uVar6;
        local_5c = uVar7;
        local_58 = uVar8;
        local_4c = uVar3;
        if (uVar22 < 0x20) {
          if ((uVar22 < 0x1d) && (uVar22 != 0xb)) goto LAB_000af291;
LAB_000af65b:
          ((int (*)())FUN_000aa6b4)(local_30,local_1d,0);
          local_9c = CONCAT31((*(unsigned int *)((unsigned char *)&(local_9c) + 1)),uVar10);
          ((int (*)())FUN_000aa712)(local_b4,local_b0,local_ac,local_a8,local_a4,local_a0,local_9c,local_98,
                       *(undefined4 *)(local_248 + 0x78),local_28);
          ((int (*)())FUN_000ad8d5)(uVar22,local_30,uVar3,local_28,local_ac,local_a8,local_a4,local_a0,
                       uVar4 & 0xff,uVar6,uVar8);
        }
        else {
          if (uVar22 - 0x3d < 3) goto LAB_000af65b;
LAB_000af291:
          ((int (*)())FUN_000aa6b4)(local_28,local_1d,*(undefined1 *)(*(int *)(local_248 + 0x94) + local_208));
          local_9c = CONCAT31((*(unsigned int *)((unsigned char *)&(local_9c) + 1)),uVar10);
          ((int (*)())FUN_000aa712)(local_b4,local_b0,local_ac,local_a8,local_a4,local_a0,local_9c,local_98,
                       *(undefined4 *)(local_248 + 0x78),local_38);
          local_7c = CONCAT31((*(unsigned int *)((unsigned char *)&(local_7c) + 1)),uVar11);
          local_78 = uVar6;
          ((int (*)())FUN_000aa712)(local_94,local_90,local_8c,local_88,local_84,local_80,local_7c,uVar6,
                       *(undefined4 *)(local_248 + 0x78),local_30);
          local_5c = CONCAT31((*(unsigned int *)((unsigned char *)&(local_5c) + 1)),uVar12);
          local_58 = uVar8;
          ((int (*)())FUN_000aa712)(local_74,local_70,local_6c,local_68,local_64,local_60,local_5c,uVar8,
                       *(undefined4 *)(local_248 + 0x78),local_1b4);
          ((int (*)())FUN_000ab20b)(uVar22,local_28,uVar3,local_38,local_30,local_1b4,uVar4 & 0xff,uVar5 & 0xff,
                       uVar7 & 0xff,local_ac,local_a8,local_a4,local_a0,local_8c,local_88,local_84,
                       local_80,local_6c,local_68,local_64,local_60,
                       *(undefined1 *)(local_208 + *(int *)(local_248 + 0x94)));
        }
        if (local_1d[0] != '\0') {
          bVar9 = true;
        }
        local_208 = local_208 + 1;
        piVar1 = (int *)(*(int *)(local_248 + 100) + local_1c8);
        iVar18 = local_1c8;
        local_1c8 = local_1c8 + 0x70;
      } while (*piVar1 != 0x41);
      if (!bVar9) goto LAB_000aec50;
    }
    local_238 = &local_44;
    if (local_40 <= local_44) {
      pvVar16 = (void *)(**(code **)(param_1 + 0xc))(local_40 * 4 + 0x200);
      if (local_3c != (void *)0x0) {
        _memcpy(pvVar16,local_3c,local_44 << 2);
        (**(code **)(param_1 + 0x18))(local_3c);
      }
      local_40 = local_40 + 0x80;
      local_3c = pvVar16;
    }
    *(undefined4 *)((int)local_3c + local_44 * 4) = 0x28;
    local_44 = local_44 + 1;
    iVar18 = (**(code **)(param_1 + 0x1288))(param_1,local_20c,local_204,local_238);
    if (iVar18 < 0) {
      iVar21 = *(int *)(param_1 + 0x1130);
      iVar19 = *(int *)(local_20c + 0x70);
      uVar14 = *(undefined4 *)(iVar19 + iVar21 * 4);
      if (iVar18 == -1) {
        _sprintf(local_1b4,
                 "Fragment program exceeded native resources:\n  Temporaries          - %d\n  Parameters           - %d\n  Attributes           - %d\n  ALU instructions     - %d\n  Texture instructions - %d\n  Texture indirections - %d\n"
                 ,*(undefined4 *)(local_20c + 0x68),*(undefined4 *)(local_20c + 100),
                 *(undefined4 *)(local_20c + 0x60),*(undefined4 *)(local_20c + 0x54),
                 *(undefined4 *)(local_20c + 0x58),*(undefined4 *)(local_20c + 0x5c));
        if (*(int *)(param_1 + 0x1128) != 0) {
          (**(code **)(param_1 + 0x18))(*(int *)(param_1 + 0x1128));
        }
        uVar22 = 0xffffffff;
        pcVar20 = local_1b4;
        do {
          if (uVar22 == 0) break;
          uVar22 = uVar22 - 1;
          cVar13 = *pcVar20;
          pcVar20 = pcVar20 + 1;
        } while (cVar13 != '\0');
        pcVar20 = (char *)(**(code **)(param_1 + 0xc))(~uVar22);
        *(char **)(param_1 + 0x1128) = pcVar20;
        _strcpy(pcVar20,local_1b4);
        iVar21 = *(int *)(param_1 + 0x1130);
        iVar19 = *(int *)(local_20c + 0x70);
      }
      *(undefined4 *)(iVar19 + iVar21 * 4) = 0;
      (**(code **)(param_1 + 0x1224))(param_1,uVar14);
      return 0;
    }
  }
  else {
    cVar13 = ((int (*)())FUN_000aa9ad)();
    if (cVar13 == '\0') {
      if (*(int *)(param_1 + 0x1128) != 0) {
        (**(code **)(param_1 + 0x18))(*(int *)(param_1 + 0x1128));
      }
      puVar15 = (undefined4 *)(**(code **)(param_1 + 0xc))(0x22);
      *(undefined4 **)(param_1 + 0x1128) = puVar15;
      *puVar15 = 0x676f7270;
      puVar15[1] = 0x206d6172;
      puVar15[2] = 0x20646168;
      puVar15[3] = 0x20646162;
      puVar15[4] = 0x7520726f;
      puVar15[5] = 0x7075736e;
      puVar15[6] = 0x74726f70;
      puVar15[7] = 0x49206465;
      *(undefined2 *)(puVar15 + 8) = 0x4c;
      return 0;
    }
    iVar18 = (**(code **)(param_1 + 0x1288))(param_1,local_20c,local_204,local_1b4);
    if (iVar18 == -1) {
      *(undefined1 *)(local_20c + 0x6c) = 0;
    }
    else {
      if (iVar18 == -2) {
        puVar15 = (undefined4 *)(*(int *)(local_20c + 0x70) + *(int *)(param_1 + 0x1130) * 4);
        uVar14 = *puVar15;
        *puVar15 = 0;
        (**(code **)(param_1 + 0x1224))(param_1,uVar14);
        return 0;
      }
      *(undefined1 *)(local_20c + 0x6c) = 1;
    }
  }
  local_204[0x119] = '\0';
LAB_000aed45:
  *(undefined1 *)(param_1 + 0x11d0) = 0;
  if (local_248[0x55] == '\0') {
    local_248 = *(char **)(local_20c + 0x74);
    if (0 < *(int *)((int)local_248 + 0x84)) {
      local_1d8 = 0;
      local_1cc = 0;
      do {
        iVar18 = local_1cc + *(int *)((int)local_248 + 0x80);
        if (*(int *)(iVar18 + 8) == 0x34) {
          if (*local_204 == '\0') {
            (**(code **)(param_1 + 0x1280))
                      (param_1,local_204,local_1d8,*(undefined4 *)(iVar18 + 4),
                       *(int *)(iVar18 + 0xc) * 0x10 + *(int *)((int)local_248 + 0x8c),1,1);
            local_248 = *(char **)(local_20c + 0x74);
          }
        }
        else {
          FUN_00089a08(param_1,iVar18,&local_54);
          (**(code **)(param_1 + 0x1280))
                    (param_1,local_204,local_1d8,*(undefined4 *)(iVar18 + 4),&local_54,1,1);
          local_248 = *(char **)(local_20c + 0x74);
        }
        local_1d8 = local_1d8 + 1;
        local_1cc = local_1cc + 0x14;
      } while (local_1d8 < *(int *)((int)local_248 + 0x84));
    }
  }
  else {
    ((int (*)())FUN_000aa7a9)();
  }
  if (((*(byte *)(param_1 + 0x46) & 4) != 0) && (*(char *)(local_20c + 0x6c) != '\0')) {
    (**(code **)(param_1 + 0x1290))(param_1,local_204);
    return 1;
  }
  return 1;
}

/* FUN_000b01a8 @ 0xb01a8 (130 bytes) */
int FUN_000b01a8(param_1, param_2, param_3)
  int param_1;
  uint *param_2;
  undefined4 param_3;
{
  void *pvVar1;
  
  if (*param_2 < param_2[1]) {
    *(undefined4 *)(param_2[2] + *param_2 * 4) = param_3;
    *param_2 = *param_2 + 1;
    return;
  }
  pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
  if ((void *)param_2[2] != (void *)0x0) {
    _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
    (**(code **)(param_1 + 0x18))(param_2[2]);
  }
  param_2[2] = (uint)pvVar1;
  param_2[1] = param_2[1] + 0x80;
  *(undefined4 *)(param_2[2] + *param_2 * 4) = param_3;
  *param_2 = *param_2 + 1;
  return;
}

/* FUN_000b022a @ 0xb022a (338 bytes) */
int FUN_000b022a(param_1, param_2)
  int param_1;
  uint *param_2;
{
  uint uVar1;
  void *pvVar2;
  
  if (param_2[1] <= *param_2) {
    pvVar2 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar2,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(param_2[2] + *param_2 * 4) = 0xe;
  uVar1 = *param_2;
  *param_2 = uVar1 + 1;
  if (param_2[1] <= uVar1 + 1) {
    pvVar2 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar2,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(param_2[2] + *param_2 * 4) = 0x170000;
  uVar1 = *param_2;
  *param_2 = uVar1 + 1;
  if (uVar1 + 1 < param_2[1]) {
    *(undefined4 *)(param_2[2] + *param_2 * 4) = 0x40000;
    *param_2 = *param_2 + 1;
    return;
  }
  pvVar2 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
  if ((void *)param_2[2] != (void *)0x0) {
    _memcpy(pvVar2,(void *)param_2[2],*param_2 << 2);
    (**(code **)(param_1 + 0x18))(param_2[2]);
  }
  param_2[2] = (uint)pvVar2;
  param_2[1] = param_2[1] + 0x80;
  *(undefined4 *)(param_2[2] + *param_2 * 4) = 0x40000;
  *param_2 = *param_2 + 1;
  return;
}

/* FUN_000b037c @ 0xb037c (560 bytes) */
int FUN_000b037c(param_1, param_2)
  int param_1;
  uint *param_2;
{
  uint uVar1;
  void *pvVar2;
  
  if (param_2[1] <= *param_2) {
    pvVar2 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar2,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(param_2[2] + *param_2 * 4) = 3;
  uVar1 = *param_2;
  *param_2 = uVar1 + 1;
  if (param_2[1] <= uVar1 + 1) {
    pvVar2 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar2,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(param_2[2] + *param_2 * 4) = 0x40000;
  uVar1 = *param_2;
  *param_2 = uVar1 + 1;
  if (param_2[1] <= uVar1 + 1) {
    pvVar2 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar2,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(param_2[2] + *param_2 * 4) = 0x40000;
  uVar1 = *param_2;
  *param_2 = uVar1 + 1;
  if (param_2[1] <= uVar1 + 1) {
    pvVar2 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar2,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(param_2[2] + *param_2 * 4) = 0x530000;
  uVar1 = *param_2;
  *param_2 = uVar1 + 1;
  if (uVar1 + 1 < param_2[1]) {
    *(undefined4 *)(param_2[2] + *param_2 * 4) = 0x4210;
    *param_2 = *param_2 + 1;
    return;
  }
  pvVar2 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
  if ((void *)param_2[2] != (void *)0x0) {
    _memcpy(pvVar2,(void *)param_2[2],*param_2 << 2);
    (**(code **)(param_1 + 0x18))(param_2[2]);
  }
  param_2[2] = (uint)pvVar2;
  param_2[1] = param_2[1] + 0x80;
  *(undefined4 *)(param_2[2] + *param_2 * 4) = 0x4210;
  *param_2 = *param_2 + 1;
  return;
}

/* FUN_000b05ac @ 0xb05ac (563 bytes) */
int FUN_000b05ac(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint *param_2;
  int param_3;
  int param_4;
  int param_5;
{
  uint uVar1;
  void *pvVar2;
  uint local_1c;
  
  if (param_2[1] <= *param_2) {
    pvVar2 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar2,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(param_2[2] + *param_2 * 4) = 0x47;
  uVar1 = *param_2;
  *param_2 = uVar1 + 1;
  local_1c = 0;
  if ((param_5 & 7) == 0) {
    local_1c = 0x15;
  }
  if ((param_5 & 1) != 0) {
    local_1c = local_1c & 0xfffffffc | 1;
  }
  if ((param_5 & 2) != 0) {
    local_1c = local_1c & 0xfffffff3 | 4;
  }
  if ((param_5 & 4) != 0) {
    local_1c = local_1c & 0xffffffcf | 0x10;
  }
  if ((param_5 & 8) != 0) {
    local_1c = local_1c | 0x40;
  }
  if (param_2[1] <= uVar1 + 1) {
    pvVar2 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar2,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(uint *)(param_2[2] + *param_2 * 4) = (ushort)(param_3 + 0x76df) | 0x440000;
  uVar1 = *param_2;
  *param_2 = uVar1 + 1;
  if (param_2[1] <= uVar1 + 1) {
    pvVar2 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar2,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(uint *)(param_2[2] + *param_2 * 4) = local_1c;
  uVar1 = *param_2;
  *param_2 = uVar1 + 1;
  if (uVar1 + 1 < param_2[1]) {
    *(uint *)(param_2[2] + *param_2 * 4) = param_4 | 0x40000;
    *param_2 = *param_2 + 1;
    return;
  }
  pvVar2 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
  if ((void *)param_2[2] != (void *)0x0) {
    _memcpy(pvVar2,(void *)param_2[2],*param_2 << 2);
    (**(code **)(param_1 + 0x18))(param_2[2]);
  }
  param_2[2] = (uint)pvVar2;
  param_2[1] = param_2[1] + 0x80;
  *(uint *)(param_2[2] + *param_2 * 4) = param_4 | 0x40000;
  *param_2 = *param_2 + 1;
  return;
}

/* FUN_000b07df @ 0xb07df (828 bytes) */
int FUN_000b07df(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  uint *param_2;
  uint *param_3;
  undefined4 param_4;
  undefined4 param_5;
  int param_6;
{
  uint uVar1;
  uint uVar2;
  void *pvVar3;
  uint *puVar4;
  uint uVar5;
  uint local_1c;
  
  local_1c = 0;
  uVar5 = 0;
  puVar4 = (uint *)*param_3;
  if (((int)puVar4 - 0x8921U < 6) && (*(char *)((int)puVar4 + param_6 + -0x8921) == '\0')) {
    *param_3 = 0;
    puVar4 = (uint *)0x0;
  }
  else {
    if ((uint *)0x8926 < puVar4) {
      if (&UINT_00008940 < puVar4) {
        if (puVar4 < (uint *)0x8949) {
          local_1c = (uint)(ushort)((short)puVar4 + 0x76bf);
          local_1c = local_1c | 0x10000;
        }
        else if (puVar4 == (uint *)0x896d) {
          local_1c = 0x130000;
        }
      }
      goto LAB_000b0834;
    }
    if ((uint *)0x8920 < puVar4) {
      local_1c = (uint)(ushort)((short)puVar4 + 0x76df);
      local_1c = local_1c | 0x40000;
      goto LAB_000b0834;
    }
    if (puVar4 == (uint *)0x1) {
      local_1c = 0x410000;
      uVar5 = 0x5555;
      goto LAB_000b0834;
    }
    if (puVar4 != (uint *)0x0) {
      if (puVar4 == (uint *)0x8577) {
        local_1c = 0x120000;
      }
      goto LAB_000b0834;
    }
  }
  local_1c = 0x410000;
  uVar5 = 0x4444;
LAB_000b0834:
  uVar1 = param_3[3];
  if ((uVar1 != 0) || (param_3[2] != 0)) {
    local_1c = local_1c | 0x400000;
  }
  uVar2 = param_3[2];
  if ((uVar2 & 1) != 0) {
    uVar5 = uVar5 | 0x40000;
  }
  if ((uVar2 & 2) != 0) {
    uVar5 = uVar5 | 0x10000;
  }
  if ((uVar2 & 4) != 0) {
    uVar5 = uVar5 | 0x8888;
  }
  if ((uVar2 & 8) != 0) {
    uVar5 = uVar5 | 0x20000;
  }
  if ((uint *)0x1 < puVar4) {
    if (uVar1 == 0x1904) {
      uVar5 = uVar5 & 0xffff8888 | 0x1111;
    }
    else if (uVar1 < 0x1905) {
      if (uVar1 == 0) {
        uVar5 = uVar5 & 0xffff8888 | 0x3210;
      }
      else if (uVar1 == 0x1903) {
        uVar5 = uVar5 & 0xffff8888;
      }
    }
    else if (uVar1 == 0x1905) {
      uVar5 = uVar5 & 0xffff8888 | 0x2222;
    }
    else if (uVar1 == 0x1906) {
      uVar5 = uVar5 & 0xffff8888 | 0x3333;
    }
  }
  if (param_2[1] <= *param_2) {
    pvVar3 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar3,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar3;
    param_2[1] = param_2[1] + 0x80;
  }
  *(uint *)(param_2[2] + *param_2 * 4) = local_1c;
  uVar1 = *param_2;
  *param_2 = uVar1 + 1;
  if ((local_1c & 0x400000) != 0) {
    if (param_2[1] <= uVar1 + 1) {
      pvVar3 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
      if ((void *)param_2[2] != (void *)0x0) {
        _memcpy(pvVar3,(void *)param_2[2],*param_2 << 2);
        (**(code **)(param_1 + 0x18))(param_2[2]);
      }
      param_2[2] = (uint)pvVar3;
      param_2[1] = param_2[1] + 0x80;
    }
    *(uint *)(param_2[2] + *param_2 * 4) = uVar5;
    *param_2 = *param_2 + 1;
  }
  return 1;
}

/* FUN_000b0b1b @ 0xb0b1b (672 bytes) */
int FUN_000b0b1b(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  uint *param_2;
  int *param_3;
  undefined4 param_4;
  int param_5;
  int param_6;
{
  int iVar1;
  ushort uVar2;
  uint uVar3;
  void *pvVar4;
  uint uVar5;
  uint uVar6;
  uint local_24;
  
  iVar1 = *param_3;
  uVar2 = (ushort)iVar1;
  if (iVar1 - 0x8921U < 6) {
    uVar2 = uVar2 + 0x76df;
    *(undefined1 *)(iVar1 + -0x8921 + param_6) = 1;
  }
  uVar5 = (uint)uVar2;
  uVar6 = uVar5 | 0x40000;
  if (param_5 == '\0') {
    uVar6 = uVar5 | 0x440000;
    local_24 = 0x40;
  }
  else {
    local_24 = 0;
    uVar3 = param_3[1];
    if ((uVar3 & 7) == 0) {
      uVar6 = uVar5 | 0x440000;
      local_24 = 0x15;
    }
    if ((uVar3 & 1) != 0) {
      uVar6 = uVar6 | 0x400000;
      local_24 = local_24 & 0xfffffffc | 1;
    }
    if ((uVar3 & 2) != 0) {
      uVar6 = uVar6 | 0x400000;
      local_24 = local_24 & 0xfffffff3 | 4;
    }
    if ((uVar3 & 4) != 0) {
      uVar6 = uVar6 | 0x400000;
      local_24 = local_24 & 0xffffffcf | 0x10;
    }
    if ((uVar3 & 8) != 0) {
      uVar6 = uVar6 | 0x400000;
      local_24 = local_24 | 0x40;
    }
  }
  uVar5 = param_3[2];
  if (uVar5 != 0) {
    uVar6 = uVar6 | 0x400000;
    uVar3 = local_24 | 0x100;
    if ((uVar5 & 0x40) == 0) {
      uVar3 = local_24;
    }
    local_24 = uVar3;
    switch(uVar5 & 0x3f) {
    case 1:
      local_24 = uVar3 | 0x200;
      break;
    case 2:
      local_24 = uVar3 | 0x400;
      break;
    case 4:
      local_24 = uVar3 | 0x600;
      break;
    case 8:
      local_24 = uVar3 | 0x800;
      break;
    case 0x10:
      local_24 = uVar3 | 0xa00;
      break;
    case 0x20:
      local_24 = uVar3 | 0xc00;
    }
  }
  if (param_2[1] <= *param_2) {
    pvVar4 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar4,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar4;
    param_2[1] = param_2[1] + 0x80;
  }
  *(uint *)(param_2[2] + *param_2 * 4) = uVar6;
  uVar5 = *param_2;
  *param_2 = uVar5 + 1;
  if ((uVar6 & 0x400000) != 0) {
    if (param_2[1] <= uVar5 + 1) {
      pvVar4 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
      if ((void *)param_2[2] != (void *)0x0) {
        _memcpy(pvVar4,(void *)param_2[2],*param_2 << 2);
        (**(code **)(param_1 + 0x18))(param_2[2]);
      }
      param_2[2] = (uint)pvVar4;
      param_2[1] = param_2[1] + 0x80;
    }
    *(uint *)(param_2[2] + *param_2 * 4) = local_24;
    *param_2 = *param_2 + 1;
  }
  return 1;
}

/* FUN_000b0e42 @ 0xb0e42 (1816 bytes) */
int FUN_000b0e42(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  uint *param_2;
  int param_3;
  int param_4;
  undefined4 param_5;
  int param_6;
{
  int iVar1;
  short sVar2;
  int iVar3;
  char *pcVar4;
  void *pvVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_40;
  uint local_3c;
  uint local_34;
  
  iVar1 = *(int *)(param_3 + 0x10);
  uVar7 = (uint)*(ushort *)(param_3 + 0x14);
  if (uVar7 != 0) {
    local_3c = 0;
    do {
      iVar3 = (param_4 * uVar7 + local_3c) * 0xc;
      pcVar4 = (char *)(iVar3 + *(int *)(iVar1 + 0xc));
      if (*pcVar4 != '\0') {
        local_34 = *(uint *)(pcVar4 + 4);
        local_40 = 0;
        sVar2 = (short)local_3c;
        if (pcVar4[1] == '\0') {
          if (local_34 == 0x8976) {
            if (local_3c == *(int *)(pcVar4 + 8) - 0x8921U) goto LAB_000b0f8f;
            uVar7 = param_2[1];
            if (*param_2 < uVar7) goto LAB_000b1198;
LAB_000b1491:
            pvVar5 = (void *)(**(code **)(param_1 + 0xc))(uVar7 * 4 + 0x200);
            if ((void *)param_2[2] != (void *)0x0) {
              _memcpy(pvVar5,(void *)param_2[2],*param_2 << 2);
              (**(code **)(param_1 + 0x18))(param_2[2]);
            }
            param_2[2] = (uint)pvVar5;
            param_2[1] = param_2[1] + 0x80;
            *(undefined4 *)(param_2[2] + *param_2 * 4) = 0x47;
            uVar7 = *param_2;
            *param_2 = uVar7 + 1;
            uVar8 = CONCAT22(4,sVar2 + 6);
            uVar6 = param_2[1];
            if (uVar6 <= uVar7 + 1) {
LAB_000b1501:
              pvVar5 = (void *)(**(code **)(param_1 + 0xc))(uVar6 * 4 + 0x200);
              if ((void *)param_2[2] != (void *)0x0) {
                _memcpy(pvVar5,(void *)param_2[2],*param_2 << 2);
                (**(code **)(param_1 + 0x18))(param_2[2]);
              }
              param_2[2] = (uint)pvVar5;
              param_2[1] = param_2[1] + 0x80;
            }
          }
          else {
            uVar7 = param_2[1];
            if (uVar7 <= *param_2) goto LAB_000b1491;
LAB_000b1198:
            *(undefined4 *)(param_2[2] + *param_2 * 4) = 0x47;
            uVar7 = *param_2;
            *param_2 = uVar7 + 1;
            uVar8 = CONCAT22(4,sVar2 + 6);
            uVar6 = param_2[1];
            if (uVar6 <= uVar7 + 1) goto LAB_000b1501;
          }
          *(undefined4 *)(param_2[2] + *param_2 * 4) = uVar8;
          *param_2 = *param_2 + 1;
          *(undefined1 *)(param_6 + local_3c) = 1;
          iVar3 = *(int *)(iVar3 + 8 + *(int *)(iVar1 + 0xc));
          sVar2 = (short)iVar3;
          if (iVar3 - 0x84c0U < 6) {
            uVar7 = CONCAT22(0x11,sVar2 + 0x7b40);
          }
          else {
            uVar7 = CONCAT22(4,sVar2 + 0x76df);
          }
          uVar7 = uVar7 | 0x400000;
          if (*param_2 < param_2[1]) goto LAB_000b0f3f;
          pvVar5 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
          if ((void *)param_2[2] != (void *)0x0) {
            _memcpy(pvVar5,(void *)param_2[2],*param_2 << 2);
            (**(code **)(param_1 + 0x18))(param_2[2]);
          }
          param_2[2] = (uint)pvVar5;
          param_2[1] = param_2[1] + 0x80;
          *(uint *)(param_2[2] + *param_2 * 4) = uVar7;
          *param_2 = *param_2 + 1;
          if (local_34 != 0x8977) goto LAB_000b0f57;
LAB_000b1270:
          local_40 = 0x3310;
          uVar7 = param_2[1];
          if (uVar7 <= *param_2) {
LAB_000b1282:
            pvVar5 = (void *)(**(code **)(param_1 + 0xc))(uVar7 * 4 + 0x200);
            if ((void *)param_2[2] != (void *)0x0) {
              _memcpy(pvVar5,(void *)param_2[2],*param_2 << 2);
              (**(code **)(param_1 + 0x18))(param_2[2]);
            }
            param_2[2] = (uint)pvVar5;
            param_2[1] = param_2[1] + 0x80;
          }
        }
        else {
          if (param_2[1] <= *param_2) {
            pvVar5 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
            if ((void *)param_2[2] != (void *)0x0) {
              _memcpy(pvVar5,(void *)param_2[2],*param_2 << 2);
              (**(code **)(param_1 + 0x18))(param_2[2]);
            }
            param_2[2] = (uint)pvVar5;
            param_2[1] = param_2[1] + 0x80;
          }
          *(uint *)(param_2[2] + *param_2 * 4) = (local_3c & 0x3fff) << 0x10 | 0x5d;
          uVar7 = *param_2;
          *param_2 = uVar7 + 1;
          if (param_2[1] <= uVar7 + 1) {
            pvVar5 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
            if ((void *)param_2[2] != (void *)0x0) {
              _memcpy(pvVar5,(void *)param_2[2],*param_2 << 2);
              (**(code **)(param_1 + 0x18))(param_2[2]);
            }
            param_2[2] = (uint)pvVar5;
            param_2[1] = param_2[1] + 0x80;
          }
          *(uint *)(param_2[2] + *param_2 * 4) = CONCAT22(4,sVar2 + 6);
          *param_2 = *param_2 + 1;
          iVar3 = *(int *)(iVar3 + 8 + *(int *)(iVar1 + 0xc));
          sVar2 = (short)iVar3;
          if (iVar3 - 0x84c0U < 6) {
            uVar7 = CONCAT22(0x11,sVar2 + 0x7b40);
LAB_000b0f24:
            *(undefined1 *)(local_3c + param_6) = 1;
            uVar7 = uVar7 | 0x400000;
            uVar6 = param_2[1];
            if (*param_2 < uVar6) goto LAB_000b0f3f;
          }
          else {
            if (*(char *)(param_6 + -0x8921 + iVar3) != '\0') {
              uVar7 = CONCAT22(4,sVar2 + 0x76df);
              goto LAB_000b0f24;
            }
            local_34 = 0;
            *(undefined1 *)(local_3c + param_6) = 1;
            uVar7 = CONCAT22(1,sVar2 + 0x76df) | 0x400000;
            uVar6 = param_2[1];
            if (*param_2 < uVar6) goto LAB_000b0f3f;
          }
          pvVar5 = (void *)(**(code **)(param_1 + 0xc))(uVar6 * 4 + 0x200);
          if ((void *)param_2[2] != (void *)0x0) {
            _memcpy(pvVar5,(void *)param_2[2],*param_2 << 2);
            (**(code **)(param_1 + 0x18))(param_2[2]);
          }
          param_2[2] = (uint)pvVar5;
          param_2[1] = param_2[1] + 0x80;
LAB_000b0f3f:
          *(uint *)(param_2[2] + *param_2 * 4) = uVar7;
          *param_2 = *param_2 + 1;
          if (local_34 == 0x8977) goto LAB_000b1270;
LAB_000b0f57:
          if (local_34 < 0x8977) {
            if (local_34 == 0) {
              local_40 = 0x4444;
            }
            else if (local_34 == 0x8976) {
              local_40 = 0x3210;
            }
          }
          else if (local_34 == 0x8978) {
            local_40 = 0x602510;
          }
          else if (local_34 == 0x8979) {
            local_40 = 0x603510;
          }
          uVar7 = param_2[1];
          if (uVar7 <= *param_2) goto LAB_000b1282;
        }
        *(undefined4 *)(param_2[2] + *param_2 * 4) = local_40;
        *param_2 = *param_2 + 1;
        uVar7 = (uint)*(ushort *)(param_3 + 0x14);
      }
LAB_000b0f8f:
      local_3c = local_3c + 1;
    } while ((int)local_3c < (int)uVar7);
    if (uVar7 != 0) {
      iVar3 = 0;
      do {
        pcVar4 = (char *)(*(int *)(iVar1 + 0xc) + (iVar3 + param_4 * uVar7) * 0xc);
        if ((*pcVar4 != '\0') &&
           (((pcVar4[1] != '\0' || (*(int *)(pcVar4 + 4) != 0x8976)) ||
            (iVar3 != *(int *)(pcVar4 + 8) + -0x8921)))) {
          local_4c = CONCAT22(4,(short)iVar3 + 6);
          local_48 = CONCAT22(4,(short)iVar3);
          if (*param_2 < param_2[1]) {
            *(undefined4 *)(param_2[2] + *param_2 * 4) = 0x47;
            uVar7 = *param_2;
            *param_2 = uVar7 + 1;
            uVar6 = param_2[1];
            if (uVar6 <= uVar7 + 1) goto LAB_000b10ca;
LAB_000b0fc5:
            *(undefined4 *)(param_2[2] + *param_2 * 4) = local_48;
            uVar7 = *param_2;
            *param_2 = uVar7 + 1;
            uVar6 = param_2[1];
            if (uVar6 <= uVar7 + 1) {
LAB_000b112f:
              pvVar5 = (void *)(**(code **)(param_1 + 0xc))(uVar6 * 4 + 0x200);
              if ((void *)param_2[2] != (void *)0x0) {
                _memcpy(pvVar5,(void *)param_2[2],*param_2 << 2);
                (**(code **)(param_1 + 0x18))(param_2[2]);
              }
              param_2[2] = (uint)pvVar5;
              param_2[1] = param_2[1] + 0x80;
            }
          }
          else {
            pvVar5 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
            if ((void *)param_2[2] != (void *)0x0) {
              _memcpy(pvVar5,(void *)param_2[2],*param_2 << 2);
              (**(code **)(param_1 + 0x18))(param_2[2]);
            }
            param_2[2] = (uint)pvVar5;
            param_2[1] = param_2[1] + 0x80;
            *(undefined4 *)(param_2[2] + *param_2 * 4) = 0x47;
            uVar7 = *param_2;
            *param_2 = uVar7 + 1;
            uVar6 = param_2[1];
            if (uVar7 + 1 < uVar6) goto LAB_000b0fc5;
LAB_000b10ca:
            pvVar5 = (void *)(**(code **)(param_1 + 0xc))(uVar6 * 4 + 0x200);
            if ((void *)param_2[2] != (void *)0x0) {
              _memcpy(pvVar5,(void *)param_2[2],*param_2 << 2);
              (**(code **)(param_1 + 0x18))(param_2[2]);
            }
            param_2[2] = (uint)pvVar5;
            param_2[1] = param_2[1] + 0x80;
            *(undefined4 *)(param_2[2] + *param_2 * 4) = local_48;
            uVar7 = *param_2;
            *param_2 = uVar7 + 1;
            uVar6 = param_2[1];
            if (uVar6 <= uVar7 + 1) goto LAB_000b112f;
          }
          *(undefined4 *)(param_2[2] + *param_2 * 4) = local_4c;
          *param_2 = *param_2 + 1;
          uVar7 = (uint)*(ushort *)(param_3 + 0x14);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < (int)uVar7);
    }
  }
  return;
}

