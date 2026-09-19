#include "decls.h"

/* FUN_000c1d91 @ 0xc1d91 (190 bytes) */
longlong FUN_000c1d91(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  uint param_3;
  int param_4;
  uint param_5;
{
  float *pfVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar4 = (uint)param_4;
  bVar2 = (byte)param_4 & 0x1f;
  uVar5 = param_3 >> ((byte)param_4 & 0x1f);
  uVar3 = param_2 >> bVar2 | param_3 << 0x20 - bVar2;
  uVar6 = uVar5;
  if ((param_4 & 0x20) != 0) {
    uVar6 = 0;
    uVar3 = uVar5;
  }
  if ((uVar3 & 1) != 0) {
    if ((param_5 & 1) != 0) {
      pfVar1 = (float *)(uVar4 * 0x10 + param_1);
      if ((FLOAT_001c5bd0 != *pfVar1) || (NAN(FLOAT_001c5bd0) || NAN(*pfVar1))) goto LAB_000c1e26;
    }
    if ((param_5 & 2) != 0) {
      pfVar1 = (float *)(uVar4 * 0x10 + 4 + param_1);
      if ((FLOAT_001c5bd0 != *pfVar1) || (NAN(FLOAT_001c5bd0) || NAN(*pfVar1))) goto LAB_000c1e26;
    }
    if ((param_5 & 4) != 0) {
      pfVar1 = (float *)(uVar4 * 0x10 + 8 + param_1);
      if ((FLOAT_001c5bd0 != *pfVar1) || (NAN(FLOAT_001c5bd0) || NAN(*pfVar1))) goto LAB_000c1e26;
    }
    if ((param_5 & 8) != 0) {
      pfVar1 = (float *)(uVar4 * 0x10 + 0xc + param_1);
      if ((FLOAT_001c5bd0 != *pfVar1) || (NAN(FLOAT_001c5bd0) || NAN(*pfVar1))) goto LAB_000c1e26;
    }
    if ((param_5 & 0xfffffff0) == 0) {
      return CONCAT44(uVar6,1);
    }
  }
LAB_000c1e26:
  return (ulonglong)uVar6 << 0x20;
}

/* FUN_000c1e4f @ 0xc1e4f (412 bytes) */
int FUN_000c1e4f(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int local_30;
  int local_14;
  int local_10;
  
  iVar8 = *(int *)(param_1 + 8);
  iVar5 = param_3 * 0xa0 + iVar8;
  uVar1 = *(undefined2 *)(iVar5 + 4);
  uVar2 = *(undefined2 *)(iVar5 + 6);
  uVar3 = *(undefined2 *)(iVar5 + 0x44);
  uVar4 = *(undefined2 *)(iVar5 + 0x46);
  local_30 = param_3 + -1;
  if (local_30 < param_2) {
    return 0;
  }
  local_10 = local_30 * 0xa0;
  do {
    iVar8 = iVar8 + local_10;
    iVar6 = FUN_000c151d(iVar8,uVar1,uVar2);
    if ((((iVar6 != 0) || (iVar6 = FUN_000c151d(iVar8,uVar3,uVar4), iVar6 != 0)) ||
        (iVar6 = FUN_000c15fa(iVar8,uVar1,uVar2), iVar6 != 0)) ||
       (iVar6 = FUN_000c15fa(iVar8,uVar3,uVar4), iVar6 != 0)) {
      return 1;
    }
    iVar6 = iVar5 + param_4 * 0x40;
    local_14 = 3;
    do {
      uVar9 = *(ushort *)(iVar6 + 8) & 3;
      if (uVar9 == 3) {
        return 1;
      }
      if (((*(ushort *)(iVar6 + 8) & 0x100) != 0) &&
         (iVar7 = FUN_000c15fa(iVar8,*(undefined2 *)(iVar5 + 0x80 + uVar9 * 2),7), iVar7 != 0)) {
        return 1;
      }
      if (((*(byte *)(iVar6 + 9) & 2) != 0) &&
         (iVar7 = FUN_000c15fa(iVar8,*(undefined2 *)(iVar5 + 0x86 + uVar9 * 2),8), iVar7 != 0)) {
        return 1;
      }
      iVar6 = iVar6 + 4;
      local_14 = local_14 + -1;
    } while (local_14 != 0);
    local_30 = local_30 + -1;
    local_10 = local_10 + -0xa0;
    if (local_30 < param_2) {
      return 0;
    }
    iVar8 = *(int *)(param_1 + 8);
  } while( true );
}

/* FUN_000c1feb @ 0xc1feb (909 bytes) */
int FUN_000c1feb(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  undefined4 *puVar1;
  undefined2 uVar2;
  bool bVar3;
  short *psVar4;
  int iVar5;
  ushort *puVar6;
  int iVar7;
  int iVar8;
  int local_50;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  if ((*(int *)(param_1 + 0x8c) == 2) && (*(int *)(param_2 + 0x8c) == 2)) {
    iVar5 = param_1;
    iVar7 = param_2;
    if (param_3 != 0) {
      iVar5 = param_2;
      iVar7 = param_1;
    }
    iVar8 = 0;
    local_18 = 0;
    local_1c = 0;
    do {
      iVar8 = ((iVar8 - (uint)((*(ushort *)(iVar7 + 8) & 0x200) == 0)) + 2) -
              (uint)((*(ushort *)(iVar5 + 0x48) & 0x200) == 0);
      local_18 = ((local_18 - (uint)((*(ushort *)(iVar7 + 8) & 0x100) == 0)) + 2) -
                 (uint)((*(ushort *)(iVar5 + 0x48) & 0x100) == 0);
      local_1c = local_1c + 1;
      iVar7 = iVar7 + 4;
      iVar5 = iVar5 + 4;
    } while (local_1c != 3);
    if ((iVar8 < 4) && (local_18 < 4)) {
      iVar7 = 0;
      iVar5 = param_1 + 0x10;
      do {
        psVar4 = (short *)(iVar5 + 4);
        iVar8 = 3;
        do {
          if ((*psVar4 == 0) && (psVar4[0x20] == 0)) {
            psVar4[0x36] = -1;
          }
          psVar4 = psVar4 + 1;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
        iVar7 = iVar7 + 1;
        iVar5 = iVar5 + 6;
      } while (iVar7 != 2);
      iVar5 = (uint)(param_3 != 0) * 0x40;
      local_10 = param_2 + iVar5;
      local_14 = 3;
      do {
        puVar6 = (ushort *)(local_10 + 8);
        if ((*(byte *)(local_10 + 9) & 1) != 0) {
          local_50 = param_1 + iVar5;
          iVar8 = 0;
          iVar7 = param_1;
          do {
            if (*(short *)(iVar7 + 0x80) == -1) {
              if ((*puVar6 & 3) == 3) {
                return 0;
              }
              *(undefined2 *)(iVar7 + 0x80) = *(undefined2 *)(param_2 + 0x80 + (*puVar6 & 3) * 2);
              *(undefined2 *)(local_50 + 0x14) = 7;
              *puVar6 = *puVar6 & 0xfffc | (ushort)iVar8;
              bVar3 = true;
            }
            else {
              bVar3 = false;
            }
            iVar8 = iVar8 + 1;
            if (iVar8 == 3) {
              if (!bVar3) {
                return 0;
              }
              break;
            }
            iVar7 = iVar7 + 2;
            local_50 = local_50 + 2;
          } while (!bVar3);
        }
        if ((*(byte *)(local_10 + 9) & 2) != 0) {
          local_50 = param_1 + iVar5;
          iVar8 = 0;
          iVar7 = param_1;
          do {
            if (*(short *)(iVar7 + 0x86) == -1) {
              if ((*puVar6 & 3) == 3) {
                return 0;
              }
              *(undefined2 *)(iVar7 + 0x86) = *(undefined2 *)(param_2 + 0x86 + (*puVar6 & 3) * 2);
              *(undefined2 *)(local_50 + 0x1a) = 8;
              *puVar6 = *puVar6 & 0xfffc | (ushort)iVar8;
              bVar3 = true;
            }
            else {
              bVar3 = false;
            }
            iVar8 = iVar8 + 1;
            if (iVar8 == 3) {
              if (!bVar3) {
                return 0;
              }
              break;
            }
            iVar7 = iVar7 + 2;
            local_50 = local_50 + 2;
          } while (!bVar3);
        }
        local_10 = local_10 + 4;
        local_14 = local_14 + -1;
        if (local_14 == 0) {
          iVar5 = (uint)(param_3 != 0) * 0x40;
          puVar1 = (undefined4 *)(iVar5 + param_1);
          uVar2 = *(undefined2 *)((int)puVar1 + 0x2a);
          *puVar1 = *(undefined4 *)(iVar5 + param_2);
          *(undefined4 *)(iVar5 + 4 + param_1) = *(undefined4 *)(iVar5 + 4 + param_2);
          *(undefined4 *)(iVar5 + 8 + param_1) = *(undefined4 *)(iVar5 + 8 + param_2);
          *(undefined4 *)(iVar5 + 0xc + param_1) = *(undefined4 *)(iVar5 + 0xc + param_2);
          *(undefined4 *)(iVar5 + 0x10 + param_1) = *(undefined4 *)(iVar5 + 0x10 + param_2);
          *(undefined4 *)(iVar5 + 0x14 + param_1) = *(undefined4 *)(iVar5 + 0x14 + param_2);
          *(undefined4 *)(iVar5 + 0x18 + param_1) = *(undefined4 *)(iVar5 + 0x18 + param_2);
          *(undefined4 *)(iVar5 + 0x1c + param_1) = *(undefined4 *)(iVar5 + 0x1c + param_2);
          *(undefined4 *)(iVar5 + 0x20 + param_1) = *(undefined4 *)(iVar5 + 0x20 + param_2);
          *(undefined4 *)(iVar5 + 0x24 + param_1) = *(undefined4 *)(iVar5 + 0x24 + param_2);
          *(undefined4 *)(iVar5 + 0x28 + param_1) = *(undefined4 *)(iVar5 + 0x28 + param_2);
          *(undefined4 *)(iVar5 + 0x2c + param_1) = *(undefined4 *)(iVar5 + 0x2c + param_2);
          *(undefined4 *)(iVar5 + 0x30 + param_1) = *(undefined4 *)(iVar5 + 0x30 + param_2);
          *(undefined4 *)(iVar5 + 0x34 + param_1) = *(undefined4 *)(iVar5 + 0x34 + param_2);
          *(undefined4 *)(iVar5 + 0x38 + param_1) = *(undefined4 *)(iVar5 + 0x38 + param_2);
          *(undefined4 *)(iVar5 + 0x3c + param_1) = *(undefined4 *)(iVar5 + 0x3c + param_2);
          *(undefined2 *)((int)puVar1 + 0x2a) = uVar2;
          *(undefined2 *)(iVar5 + 2 + param_2) = 0;
          *(undefined2 *)(iVar5 + 6 + param_2) = 0;
          iVar5 = iVar5 + param_2;
          iVar7 = 3;
          do {
            *(undefined2 *)(iVar5 + 8) = 0;
            *(undefined2 *)(iVar5 + 10) = 0;
            iVar5 = iVar5 + 4;
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
          FUN_000be6b4(param_1);
          FUN_000becfb(param_1);
          FUN_000be6b4(param_2);
          FUN_000becfb(param_2);
          return 1;
        }
      } while( true );
    }
  }
  return 0;
}

/* FUN_000c2378 @ 0xc2378 (1441 bytes) */
int FUN_000c2378(param_1, param_2)
  uint *param_1;
  uint *param_2;
{
  byte bVar1;
  ushort uVar2;
  undefined4 uVar3;
  ushort uVar4;
  uint uVar5;
  ushort *puVar6;
  ushort *puVar7;
  ushort *puVar8;
  ushort local_7e;
  ushort local_6e;
  int local_64;
  uint local_48;
  int local_44;
  uint local_40;
  byte *local_38;
  char *local_34;
  uint *local_30;
  byte *local_2c;
  ushort *local_28;
  uint local_24;
  uint local_20;
  
  *(char *)(param_1 + 4) = (char)param_2[3];
  *(undefined1 *)((int)param_1 + 0x11) = *(undefined1 *)((int)param_2 + 0xd);
  if (*param_1 != 0) {
    local_38 = (byte *)((int)param_2 + 0x62);
    local_34 = (char *)((int)param_2 + 0x53);
    local_30 = param_2 + 0x22;
    local_2c = (byte *)((int)param_2 + 0x79);
    local_28 = (ushort *)((int)param_2 + 0x56);
    local_48 = 0;
    local_64 = 0;
    do {
      puVar8 = (ushort *)(local_64 + param_1[2]);
      _memset(puVar8,0,0x80);
      puVar8[0x40] = 0;
      puVar8[0x41] = 0;
      puVar8[0x42] = 0;
      puVar8[0x43] = 0;
      puVar8[0x44] = 0;
      puVar8[0x45] = 0;
      uVar5 = param_2[0x12];
      if (uVar5 == 2) {
        puVar8[0x46] = 1;
        puVar8[0x47] = 0;
        puVar8[0x48] = 0;
        puVar8[0x49] = 0;
        puVar8[0x4a] = 0;
        puVar8[0x4b] = 0;
        bVar1 = *local_38;
        if (bVar1 == 2) {
          puVar8[10] = 0xf;
          puVar8[0x40] = *local_28;
          puVar8[0x18] = 1;
          puVar8[0x19] = 0;
          puVar8[0x1d] = 1;
        }
        else if (bVar1 < 3) {
          if (bVar1 == 1) {
LAB_000c27b4:
            puVar8[3] = 0xf;
            puVar8[2] = (ushort)param_2[0x15];
            puVar8[10] = ~(ushort)*(byte *)((int)param_2 + 0x67) & 0xf;
            puVar8[0x40] = *local_28;
          }
        }
        else if (bVar1 < 5) goto LAB_000c27b4;
        puVar8[0x14] = CONCAT11(*(undefined1 *)((int)param_2 + 0x61),*local_38);
        puVar8[0x16] = 0;
        puVar8[0x17] = 0x3f80;
      }
      else if (uVar5 < 3) {
        if (uVar5 == 1) {
          puVar8[0x46] = 0;
          puVar8[0x47] = 0;
          puVar8[0x48] = 0;
          puVar8[0x49] = 0;
          puVar8[0x4a] = 0;
          puVar8[0x4b] = 0;
          if (*local_34 == '\0') {
            puVar8[0x16] = 0;
            puVar8[0x17] = 0x3f80;
          }
          else {
            puVar8[3] = 0xf;
            puVar8[2] = *(ushort *)((int)param_2 + 0x4e);
            puVar8[10] = 0xf;
            puVar8[0x40] = *(byte *)((int)param_2 + 0x52) | 0xc000;
            *(undefined4 *)(puVar8 + 0x16) =
                 *(undefined4 *)(&DAT_001eeec0 + (uint)*(byte *)((int)param_2 + 0x55) * 4);
            if (*local_34 == '\x02') {
              puVar8[0x1d] = 2;
            }
            else if (*local_34 == '\x03') {
              puVar8[0x1d] = 3;
            }
          }
          if (*(char *)((int)param_2 + 0x51) == '\0') {
            puVar8[0x36] = 0;
            puVar8[0x37] = 0x3f80;
          }
          else {
            puVar8[0x23] = 0xf;
            puVar8[0x22] = (ushort)param_2[0x13];
            puVar8[0x2d] = 0xf;
            puVar8[0x43] = (byte)param_2[0x14] | 0xa000;
            *(undefined4 *)(puVar8 + 0x36) =
                 *(undefined4 *)(&DAT_001eeec0 + (uint)(byte)param_2[0x15] * 4);
          }
        }
      }
      else if (uVar5 < 5) {
        puVar8[0x46] = 2;
        puVar8[0x47] = 0;
        puVar8[0x48] = 0;
        puVar8[0x49] = 0;
        puVar8[0x4a] = 0;
        puVar8[0x4b] = 0;
        puVar8[0x40] = *(ushort *)((int)param_2 + 0x56);
        puVar8[0x41] = (ushort)param_2[0x16];
        puVar8[0x42] = *(ushort *)((int)param_2 + 0x5a);
        puVar8[0x43] = *(ushort *)((int)param_2 + 0x62);
        puVar8[0x44] = (ushort)param_2[0x19];
        puVar8[0x45] = *(ushort *)((int)param_2 + 0x66);
        local_44 = 0;
        puVar6 = puVar8;
        puVar7 = puVar8;
        do {
          puVar6[0x3a] = 1;
          puVar6[0x1a] = 1;
          uVar3 = DAT_001eec68;
          *(undefined4 *)(puVar7 + 0x24) = DAT_001eec68;
          *(undefined4 *)(puVar7 + 4) = uVar3;
          local_44 = local_44 + 1;
          puVar6 = puVar6 + 1;
          puVar7 = puVar7 + 2;
        } while (local_44 != 3);
        puVar8[2] = (ushort)param_2[0x15];
        puVar8[3] = (ushort)(byte)param_2[0x17];
        *puVar8 = (ushort)*(byte *)((int)param_2 + 0x5e);
        puVar8[1] = (ushort)*(byte *)((int)param_2 + 0x5d);
        puVar8[0x14] = *(ushort *)(&DAT_001eee80 + (uint)*local_2c * 4);
        uVar2 = *(ushort *)(&DAT_001eee82 + (uint)*local_2c * 4);
        if (uVar2 != 0) {
LAB_000c2572:
          bVar1 = *(byte *)((int)param_2 + 0x75);
          *(undefined4 *)(puVar8 + 4) = (DAT_001eee00)[*(byte *)((int)param_2 + 0x72)];
          puVar8[5] = puVar8[5] | (ushort)bVar1 << 0xc;
          local_20 = 1;
          puVar6 = puVar8 + 4;
          if (1 < uVar2) {
            do {
              if (local_20 == 1) {
                uVar4 = (ushort)*(byte *)((int)param_2 + 0x73);
                local_6e = (ushort)*(byte *)((int)param_2 + 0x76);
              }
              else {
                if (local_20 == 0) goto LAB_000c2572;
                if (local_20 == 2) {
                  uVar4 = (ushort)(byte)param_2[0x1d];
                  local_6e = (ushort)*(byte *)((int)param_2 + 0x77);
                }
                else {
                  uVar4 = 0;
                  local_6e = 0;
                }
              }
              *(undefined4 *)(puVar6 + 2) = (DAT_001eee00)[uVar4];
              puVar6[3] = puVar6[3] | local_6e << 0xc;
              local_20 = local_20 + 1;
              puVar6 = puVar6 + 2;
              if (uVar2 <= local_20) break;
            } while( true );
          }
        }
        puVar8[0x15] = (ushort)(byte)param_2[0x1e];
        if (*(char *)((int)param_2 + 0x7b) == '\x01') {
          *(uint *)(puVar8 + 0x18) = *(uint *)(puVar8 + 0x18) | 8;
        }
        *(undefined4 *)(puVar8 + 0x16) =
             *(undefined4 *)(&DAT_001eeec0 + (uint)*(byte *)((int)param_2 + 0x7a) * 4);
        puVar8[0x22] = (ushort)param_2[0x18];
        if ((char)param_2[0x1a] != '\0') {
          puVar8[0x23] = 8;
        }
        puVar8[0x20] = (ushort)*(byte *)((int)param_2 + 0x6a);
        if (*(char *)((int)param_2 + 0x69) != '\0') {
          puVar8[0x21] = 8;
        }
        if (*(char *)((int)param_2 + 0x6b) != '\0') {
          puVar8[0x21] = puVar8[0x21] | 0x10;
        }
        puVar8[0x34] = *(ushort *)(&DAT_001eedc0 + (uint)(byte)*local_30 * 4);
        local_24 = (uint)*(ushort *)(&DAT_001eedc2 + (uint)(byte)*local_30 * 4);
        if (*local_2c == 2) {
          if (local_24 < 2) {
            local_24 = 2;
          }
LAB_000c2812:
          do {
            uVar5 = (uint)*(byte *)((int)param_2 + 0x81);
            local_7e = (ushort)(byte)param_2[0x21];
            local_40 = 0;
            puVar6 = puVar8 + 0x24;
            while( true ) {
              while( true ) {
                *(undefined4 *)puVar6 = (DAT_001eed60)[uVar5];
                puVar6[1] = puVar6[1] | local_7e << 0xc;
                local_40 = local_40 + 1;
                if (local_24 <= local_40) goto LAB_000c268c;
                if (local_40 != 1) break;
                uVar5 = (uint)*(byte *)((int)param_2 + 0x82);
                local_7e = (ushort)*(byte *)((int)param_2 + 0x85);
                puVar6 = puVar6 + 2;
              }
              if (local_40 == 0) break;
              if (local_40 == 2) {
                uVar5 = (uint)*(byte *)((int)param_2 + 0x83);
                local_7e = (ushort)*(byte *)((int)param_2 + 0x86);
                puVar6 = puVar6 + 2;
              }
              else {
                uVar5 = 0;
                local_7e = 0;
                puVar6 = puVar6 + 2;
              }
            }
          } while( true );
        }
        if (*(ushort *)(&DAT_001eedc2 + (uint)(byte)*local_30 * 4) != 0) goto LAB_000c2812;
LAB_000c268c:
        puVar8[0x35] = (ushort)*(byte *)((int)param_2 + 0x87);
        if (*(char *)((int)param_2 + 0x8a) == '\x01') {
          *(uint *)(puVar8 + 0x38) = *(uint *)(puVar8 + 0x38) | 8;
        }
        *(undefined4 *)(puVar8 + 0x36) =
             *(undefined4 *)(&DAT_001eeec0 + (uint)*(byte *)((int)param_2 + 0x89) * 4);
        FUN_000be6b4(puVar8);
        FUN_000becfb(puVar8);
      }
      local_48 = local_48 + 1;
      local_64 = local_64 + 0xa0;
      local_38 = local_38 + 0x48;
      local_34 = local_34 + 0x48;
      local_30 = local_30 + 0x12;
      local_2c = local_2c + 0x48;
      local_28 = local_28 + 0x24;
      param_2 = param_2 + 0x12;
    } while (local_48 < *param_1);
  }
  return;
}

/* FUN_000c2919 @ 0xc2919 (1430 bytes) */
int FUN_000c2919(param_1, param_2, param_3)
  uint *param_1;
  undefined4 *param_2;
  uint *param_3;
{
  undefined2 uVar1;
  undefined2 uVar2;
  ushort uVar3;
  undefined4 uVar4;
  byte bVar5;
  float fVar6;
  double dVar7;
  uint uVar8;
  undefined2 *puVar9;
  undefined1 uVar10;
  short sVar11;
  undefined4 *puVar12;
  short sVar13;
  undefined2 *puVar14;
  int iVar15;
  undefined2 *local_80;
  undefined2 *local_7c;
  ushort *local_78;
  int local_68;
  uint local_64;
  undefined1 local_5f;
  undefined1 local_5e;
  undefined1 local_5d;
  byte local_5c;
  byte local_4c;
  undefined2 *local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  
  uVar4 = param_2[1];
  _memset(param_2,0,0x48);
  param_2[1] = uVar4;
  param_2[2] = *param_1;
  *(char *)(param_2 + 3) = (char)param_1[4];
  *(undefined1 *)((int)param_2 + 0xd) = *(undefined1 *)((int)param_1 + 0x11);
  *param_3 = 0;
  if (*param_1 != 0) {
    local_5f = 1;
    local_64 = 0;
    local_2c = 0;
    do {
      puVar12 = param_2 + 0x12;
      _memset(puVar12,0,0x48);
      puVar9 = (undefined2 *)(local_2c + param_1[2]);
      uVar1 = puVar9[2];
      uVar2 = puVar9[0x22];
      iVar15 = *(int *)(puVar9 + 0x46);
      if (iVar15 == 1) {
        *puVar12 = 2;
        *(undefined2 *)(param_2 + 0x15) = uVar1;
        *(undefined2 *)((int)param_2 + 0x56) = puVar9[0x40];
        if ((puVar9[1] == 0 && puVar9[3] == 0) && ((*(byte *)(puVar9 + 0x18) & 1) == 0)) {
          *(undefined1 *)((int)param_2 + 0x62) = 0;
          *(undefined1 *)((int)param_2 + 0x61) = 0;
        }
        else {
          *(char *)((int)param_2 + 0x62) = (char)puVar9[0x14];
          *(undefined1 *)((int)param_2 + 0x61) = *(undefined1 *)((int)puVar9 + 0x29);
        }
        *(byte *)((int)param_2 + 0x67) = *(byte *)(puVar9 + 10) ^ 0xf;
        *(undefined1 *)(param_2 + 0x1a) = local_5f;
        local_5f = 0;
      }
      else if (iVar15 == 0) {
        *puVar12 = 1;
        *(undefined2 *)((int)param_2 + 0x4e) = uVar1;
        *(undefined2 *)(param_2 + 0x13) = uVar2;
        if ((puVar9[1] == 0 && puVar9[3] == 0) && ((*(byte *)(puVar9 + 0x18) & 1) == 0)) {
          *(undefined1 *)((int)param_2 + 0x53) = 0;
        }
        else {
          sVar11 = puVar9[0x1d];
          if (sVar11 == 2) {
            *(undefined1 *)((int)param_2 + 0x53) = 2;
          }
          else if (sVar11 == 3) {
            *(undefined1 *)((int)param_2 + 0x53) = 3;
          }
          else if (sVar11 == 0) {
            *(undefined1 *)((int)param_2 + 0x53) = 1;
          }
        }
        if ((puVar9[0x21] == 0 && puVar9[0x23] == 0) && ((*(byte *)(puVar9 + 0x38) & 1) == 0)) {
          uVar10 = 0;
        }
        else {
          uVar10 = 1;
        }
        *(undefined1 *)((int)param_2 + 0x51) = uVar10;
        sVar11 = puVar9[0x40];
        if (sVar11 == -1) {
          sVar11 = 0;
        }
        *(char *)((int)param_2 + 0x52) = (char)sVar11;
        sVar11 = 0;
        if (puVar9[0x43] != -1) {
          sVar11 = puVar9[0x43];
        }
        *(char *)(param_2 + 0x14) = (char)sVar11;
        fVar6 = FLOAT_001c5ba4;
        *(bool *)((int)param_2 + 0x55) = FLOAT_001c5ba4 != *(float *)(puVar9 + 0x16);
        *(bool *)(param_2 + 0x15) = fVar6 != *(float *)(puVar9 + 0x36);
        *(undefined1 *)((int)param_2 + 0x56) = 0;
        *(undefined1 *)((int)param_2 + 0x57) = 0;
      }
      else if (iVar15 == 2) {
        *puVar12 = 3;
        *(undefined2 *)(param_2 + 0x15) = uVar1;
        *(undefined2 *)(param_2 + 0x18) = uVar2;
        *(char *)((int)param_2 + 0x5d) = (char)puVar9[1];
        *(char *)((int)param_2 + 0x5e) = (char)*puVar9;
        *(byte *)((int)param_2 + 0x69) = (byte)((ushort)puVar9[0x21] >> 3) & 1;
        uVar3 = puVar9[0x21];
        *(byte *)((int)param_2 + 0x6b) = (byte)(uVar3 >> 4) & 1;
        if ((uVar3 >> 4 & 1) != 0) {
          *param_3 = *param_3 | 1;
        }
        *(char *)((int)param_2 + 0x6a) = (char)puVar9[0x20];
        *(char *)(param_2 + 0x17) = (char)puVar9[3];
        *(byte *)(param_2 + 0x1a) = (byte)((ushort)puVar9[0x23] >> 3) & 1;
        local_28 = 0;
        local_30 = puVar9;
        do {
          sVar11 = local_30[0x40];
          sVar13 = local_30[0x43];
          if (sVar11 == -1) {
            sVar11 = -0x8000;
          }
          if (sVar13 == -1) {
            sVar13 = -0x8000;
          }
          if (local_28 == 1) {
            *(short *)(param_2 + 0x16) = sVar11;
            *(short *)(param_2 + 0x19) = sVar13;
          }
          else if (local_28 == 0) {
            *(short *)((int)param_2 + 0x56) = sVar11;
            *(short *)((int)param_2 + 0x62) = sVar13;
          }
          else if (local_28 == 2) {
            *(short *)((int)param_2 + 0x5a) = sVar11;
            *(short *)((int)param_2 + 0x66) = sVar13;
          }
          local_28 = local_28 + 1;
          local_30 = local_30 + 1;
        } while (local_28 != 3);
        local_68 = 0;
        local_7c = puVar9;
        do {
          local_5e = 0;
          local_5c = 0;
          local_5d = 0;
          local_4c = 0;
          local_20 = 0;
          local_78 = local_7c + 4;
          do {
            uVar3 = local_78[1];
            bVar5 = (byte)(uVar3 >> 8) & 0x30;
            if (local_20 == 0) {
              if ((uVar3 & 0x300) == 0x100) {
                uVar8 = 6;
              }
              else if ((uVar3 & 0x300) == 0x200) {
                uVar8 = 5;
              }
              else {
                uVar8 = (uint)(uVar3 & 0x1f);
              }
              local_5e = (DAT_001eed00)[(uint)(*local_78 & 3) + uVar8 * 4];
              local_5c = bVar5 >> 4;
            }
            else if (local_20 == 1) {
              local_5d = (DAT_001eeca0)[(uint)(*local_78 & 3) + (uint)(uVar3 & 0x1f) * 4];
              local_4c = bVar5 >> 4;
            }
            local_20 = local_20 + 1;
            local_78 = local_78 + 0x20;
          } while (local_20 != 2);
          if (local_68 == 1) {
            *(undefined1 *)((int)param_2 + 0x73) = local_5e;
            *(byte *)((int)param_2 + 0x76) = local_5c;
            *(undefined1 *)((int)param_2 + 0x82) = local_5d;
            *(byte *)((int)param_2 + 0x85) = local_4c;
          }
          else if (local_68 == 0) {
            *(undefined1 *)((int)param_2 + 0x72) = local_5e;
            *(byte *)((int)param_2 + 0x75) = local_5c;
            *(undefined1 *)((int)param_2 + 0x81) = local_5d;
            *(byte *)(param_2 + 0x21) = local_4c;
          }
          else if (local_68 == 2) {
            *(undefined1 *)(param_2 + 0x1d) = local_5e;
            *(byte *)((int)param_2 + 0x77) = local_5c;
            *(undefined1 *)((int)param_2 + 0x83) = local_5d;
            *(byte *)((int)param_2 + 0x86) = local_4c;
          }
          dVar7 = DOUBLE_001cf3b8;
          local_68 = local_68 + 1;
          local_7c = local_7c + 2;
        } while (local_68 != 3);
        local_24 = 0;
        puVar14 = puVar9;
        do {
          uVar10 = (undefined1)(int)((double)*(float *)(puVar14 + 0x16) * dVar7);
          switch((int)((double)*(float *)(puVar14 + 0x16) * dVar7) & 0xff) {
          case 1:
            uVar10 = 6;
            break;
          case 2:
            uVar10 = 5;
            break;
          case 4:
            uVar10 = 4;
            break;
          case 8:
            uVar10 = 0;
            break;
          case 0x10:
            uVar10 = 1;
            break;
          case 0x20:
            uVar10 = 2;
            break;
          case 0x40:
            uVar10 = 3;
          }
          if (local_24 == 0) {
            *(undefined1 *)((int)param_2 + 0x7a) = uVar10;
            *(byte *)((int)param_2 + 0x7b) = (byte)(*(uint *)(puVar9 + 0x18) >> 3) & 1;
          }
          else if (local_24 == 1) {
            *(undefined1 *)((int)param_2 + 0x89) = uVar10;
            *(byte *)((int)param_2 + 0x8a) = (byte)(*(uint *)(puVar9 + 0x38) >> 3) & 1;
          }
          local_24 = local_24 + 1;
          puVar14 = puVar14 + 0x20;
        } while (local_24 != 2);
        iVar15 = 0;
        local_80 = puVar9;
        do {
          if (iVar15 == 0) {
            *(undefined *)((int)param_2 + 0x79) =
                 (DAT_001eec6c)[iVar15 + (uint)(ushort)local_80[0x14] * 2];
            *(char *)(param_2 + 0x1e) = (char)puVar9[0x15];
          }
          else if (iVar15 == 1) {
            *(undefined *)(param_2 + 0x22) =
                 (DAT_001eec6c)[iVar15 + (uint)(ushort)local_80[0x14] * 2];
            *(char *)((int)param_2 + 0x87) = (char)puVar9[0x35];
          }
          iVar15 = iVar15 + 1;
          local_80 = local_80 + 0x20;
        } while (iVar15 != 2);
        *(undefined1 *)(param_2 + 0x1f) = 0;
        local_5f = 1;
      }
      local_64 = local_64 + 1;
      local_2c = local_2c + 0xa0;
      param_2 = puVar12;
    } while (local_64 < *param_1);
  }
  return;
}

/* FUN_000c2fb4 @ 0xc2fb4 (423 bytes) */
int FUN_000c2fb4(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  uint param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
{
  ushort uVar1;
  ushort uVar2;
  
  uVar2 = (ushort)(param_2 & 7);
  if ((param_2 & 7) != 0) {
    uVar1 = (ushort)param_2;
    switch(param_1) {
    case 0:
    case 4:
    case 8:
    case 0xf:
      break;
    case 1:
    case 5:
    case 9:
    case 0x10:
      uVar2 = 1;
      break;
    case 2:
    case 6:
    case 10:
    case 0x11:
      uVar2 = 2;
      break;
    case 3:
    case 7:
    case 0xb:
    case 0x12:
      uVar2 = 4;
      break;
    case 0xc:
    case 0xd:
    case 0xe:
    case 0x13:
      uVar2 = 8;
      break;
    default:
      uVar2 = 0;
      break;
    case 0x17:
    case 0x18:
    case 0x19:
      uVar2 = (uVar1 & 3) * 2 | (ushort)((param_2 & 4) >> 2);
      break;
    case 0x1a:
    case 0x1b:
    case 0x1c:
      uVar2 = (uVar1 & 1) * 4 | (ushort)((param_2 & 6) >> 1);
      break;
    case 0x1d:
    case 0x1e:
    case 0x1f:
      uVar2 = (uVar1 & 1) * 8 | (uVar1 & 2) * 2 | (ushort)((param_2 & 4) >> 1);
    }
    switch(param_1) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 0x17:
    case 0x1a:
      *(ushort *)(param_5 + 2) = *(ushort *)(param_5 + 2) | uVar2;
      return;
    case 4:
    case 5:
    case 6:
    case 7:
    case 0x18:
    case 0x1b:
      *(ushort *)(param_5 + 6) = *(ushort *)(param_5 + 6) | uVar2;
      return;
    case 8:
    case 9:
    case 10:
    case 0xb:
    case 0x19:
    case 0x1c:
      *(ushort *)(param_5 + 10) = *(ushort *)(param_5 + 10) | uVar2;
      return;
    case 0xc:
      *(ushort *)(param_5 + 0xe) = *(ushort *)(param_5 + 0xe) | uVar2;
      return;
    case 0xd:
      *(ushort *)(param_5 + 0x12) = *(ushort *)(param_5 + 0x12) | uVar2;
      return;
    case 0xe:
      *(ushort *)(param_5 + 0x16) = *(ushort *)(param_5 + 0x16) | uVar2;
      return;
    case 0xf:
    case 0x10:
    case 0x11:
    case 0x12:
      *(ushort *)(param_5 + 2) = *(ushort *)(param_5 + 2) | uVar2;
      *(ushort *)(param_6 + 2) = *(ushort *)(param_6 + 2) | uVar2;
      if (param_3 - 1U < 2) {
        *(ushort *)(param_5 + 6) = *(ushort *)(param_5 + 6) | uVar2;
        *(ushort *)(param_6 + 6) = *(ushort *)(param_6 + 6) | uVar2;
      }
      break;
    case 0x13:
      *(ushort *)(param_5 + 0xe) = *(ushort *)(param_5 + 0xe) | uVar2;
      *(ushort *)(param_6 + 10) = *(ushort *)(param_6 + 10) | uVar2;
      if (param_4 - 1U < 2) {
        *(ushort *)(param_5 + 0x12) = *(ushort *)(param_5 + 0x12) | uVar2;
        *(ushort *)(param_6 + 0xe) = *(ushort *)(param_6 + 0xe) | uVar2;
        return;
      }
      break;
    case 0x1d:
      *(ushort *)(param_5 + 2) = *(ushort *)(param_5 + 2) | uVar2 & 7;
      *(ushort *)(param_5 + 0xe) = *(ushort *)(param_5 + 0xe) | uVar2 & 8;
      return;
    case 0x1e:
      *(ushort *)(param_5 + 6) = *(ushort *)(param_5 + 6) | uVar2 & 7;
      *(ushort *)(param_5 + 0x12) = *(ushort *)(param_5 + 0x12) | uVar2 & 8;
      return;
    case 0x1f:
      *(ushort *)(param_5 + 10) = *(ushort *)(param_5 + 10) | uVar2 & 7;
      *(ushort *)(param_5 + 0x16) = *(ushort *)(param_5 + 0x16) | uVar2 & 8;
      return;
    }
  }
  return;
}

/* FUN_000c325f @ 0xc325f (259 bytes) */
int FUN_000c325f(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
{
  ushort uVar1;
  
  if ((param_2 & 8) != 0) {
    switch(param_1) {
    case 0:
    case 3:
    case 6:
    case 0xc:
      uVar1 = 1;
      break;
    case 1:
    case 4:
    case 7:
    case 0xd:
      uVar1 = 2;
      break;
    case 2:
    case 5:
    case 8:
    case 0xe:
      uVar1 = 4;
      break;
    case 9:
    case 10:
    case 0xb:
    case 0xf:
      uVar1 = 8;
      break;
    default:
      uVar1 = 0;
    }
    switch(param_1) {
    case 0:
    case 1:
    case 2:
      *(ushort *)(param_5 + 2) = *(ushort *)(param_5 + 2) | uVar1;
      return;
    case 3:
    case 4:
    case 5:
      *(ushort *)(param_5 + 6) = *(ushort *)(param_5 + 6) | uVar1;
      return;
    case 6:
    case 7:
    case 8:
      *(ushort *)(param_5 + 10) = *(ushort *)(param_5 + 10) | uVar1;
      return;
    case 9:
      *(ushort *)(param_5 + 0xe) = *(ushort *)(param_5 + 0xe) | uVar1;
      return;
    case 10:
      *(ushort *)(param_5 + 0x12) = *(ushort *)(param_5 + 0x12) | uVar1;
      return;
    case 0xb:
      *(ushort *)(param_5 + 0x16) = *(ushort *)(param_5 + 0x16) | uVar1;
      return;
    case 0xc:
    case 0xd:
    case 0xe:
      *(ushort *)(param_5 + 2) = *(ushort *)(param_5 + 2) | uVar1;
      *(ushort *)(param_6 + 2) = *(ushort *)(param_6 + 2) | uVar1;
      if ((ushort)(param_3 - 1U) < 2) {
        *(ushort *)(param_5 + 6) = *(ushort *)(param_5 + 6) | uVar1;
        *(ushort *)(param_6 + 6) = *(ushort *)(param_6 + 6) | uVar1;
        return;
      }
      break;
    case 0xf:
      *(ushort *)(param_5 + 0xe) = *(ushort *)(param_5 + 0xe) | uVar1;
      *(ushort *)(param_6 + 10) = *(ushort *)(param_6 + 10) | uVar1;
      if ((ushort)(param_4 - 1U) < 2) {
        *(ushort *)(param_5 + 0x12) = *(ushort *)(param_5 + 0x12) | uVar1;
        *(ushort *)(param_6 + 0xe) = *(ushort *)(param_6 + 0xe) | uVar1;
      }
    }
  }
  return;
}

/* FUN_000c33e7 @ 0xc33e7 (524 bytes) */
int FUN_000c33e7(param_1, param_2, param_3)
  ushort *param_1;
  int *param_2;
  int *param_3;
{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  short sVar4;
  uint uVar5;
  uint uVar6;
  ushort *puVar7;
  int iVar8;
  int iVar9;
  ushort uVar10;
  int iVar11;
  int local_20;
  ushort uStack_12;
  int local_10;
  
  uVar2 = param_1[1];
  if (uVar2 != 0) {
    uVar10 = *param_1;
    if (uVar10 < *(ushort *)(param_2 + 2)) {
      iVar8 = param_2[1];
      uStack_12 = (uVar2 == 8) + 7;
    }
    else {
      uVar10 = uVar10 - *(ushort *)(param_2 + 2);
      iVar8 = *param_2;
      uStack_12 = 0xf;
    }
    puVar7 = (ushort *)(iVar8 + (uint)uVar10 * 8);
    uVar10 = puVar7[2];
    param_1[1] = uVar2 & uVar10;
    if ((uVar2 & uVar10) != 0) {
      if (uStack_12 == 8) {
        uVar2 = puVar7[1];
      }
      else {
        uVar2 = *puVar7;
      }
      *param_1 = uVar2;
      uVar2 = param_1[1];
      uVar10 = puVar7[2];
      puVar7[2] = ~uVar2 & uVar10;
      uVar1 = *param_1;
      uVar6 = (uint)*(ushort *)(param_3 + 1);
      uVar5 = uVar6 - 1;
      if ((uStack_12 & ~uVar2 & uVar10) != 0) {
        return;
      }
      if (uVar5 == 0) {
        local_10 = 0;
        uVar5 = 0;
        local_20 = *param_3;
      }
      else {
        local_10 = uVar5 * 4;
        local_20 = *param_3;
        if (uVar1 <= *(ushort *)(local_10 + local_20 + -4)) {
          puVar7 = (ushort *)(local_10 + local_20 + -8);
          do {
            local_10 = local_10 + -4;
            uVar5 = uVar5 - 1;
            if (uVar5 == 0) {
              local_10 = 0;
              break;
            }
            uVar2 = *puVar7;
            puVar7 = puVar7 + -2;
          } while (uVar1 <= uVar2);
        }
      }
      if (uVar1 == *(ushort *)(local_10 + local_20)) {
        puVar7 = (ushort *)(local_10 + local_20) + 1;
        *puVar7 = *puVar7 | uStack_12;
      }
      else {
        if (uVar5 < uVar6) {
          iVar8 = uVar6 * 4;
          while( true ) {
            *(undefined4 *)(iVar8 + local_20) = ((undefined4 *)(iVar8 + local_20))[-1];
            uVar6 = uVar6 - 1;
            iVar8 = iVar8 + -4;
            if (uVar6 <= uVar5) break;
            local_20 = *param_3;
          }
          local_20 = *param_3;
        }
        *(ushort *)(local_10 + local_20) = uVar1;
        *(ushort *)(local_10 + 2 + *param_3) = uStack_12;
        *(short *)(param_3 + 1) = (short)param_3[1] + 1;
      }
      iVar8 = *param_3;
      iVar3 = *(ushort *)(param_3 + 1) - 2;
      if (iVar3 == -1) {
        return;
      }
      iVar11 = iVar3 * 4;
      sVar4 = *(short *)(iVar8 + -4 + (uint)*(ushort *)(param_3 + 1) * 4) + -1;
      if (sVar4 != *(short *)(iVar8 + iVar11)) {
        return;
      }
      if (((short *)(iVar8 + iVar11))[1] != 0xf) {
        return;
      }
      iVar9 = 0;
      while( true ) {
        iVar11 = iVar11 + -4;
        *(short *)(param_3 + 1) = (short)param_3[1] + -1;
        if (iVar3 == iVar9) {
          return;
        }
        sVar4 = sVar4 + -1;
        if (sVar4 != *(short *)(iVar8 + iVar11)) break;
        iVar9 = iVar9 + 1;
        if (((short *)(iVar8 + iVar11))[1] != 0xf) {
          return;
        }
      }
      return;
    }
  }
  *param_1 = 0;
  return;
}

/* FUN_000c35f3 @ 0xc35f3 (504 bytes) */
int FUN_000c35f3(param_1, param_2, param_3)
  ushort *param_1;
  int *param_2;
  int *param_3;
{
  ushort *puVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  ushort *puVar5;
  int iVar6;
  ushort uVar7;
  ushort *puVar8;
  uint uVar9;
  int local_14;
  uint local_10;
  
  uVar7 = *param_1;
  if (-1 < (short)uVar7) {
    uVar2 = param_1[1];
    if (uVar2 == 0) {
      *param_1 = 0;
      return;
    }
    if (uVar7 < *(ushort *)(param_2 + 2)) {
      iVar4 = param_2[1];
      if (uVar2 == 8) {
        uVar2 = 8;
      }
      else {
        param_1[1] = uVar2 & 0xfff7;
        uVar2 = 7;
      }
    }
    else {
      uVar7 = uVar7 - *(ushort *)(param_2 + 2);
      iVar4 = *param_2;
      uVar2 = 0xf;
    }
    puVar1 = (ushort *)(iVar4 + (uint)uVar7 * 8);
    uVar7 = puVar1[2];
    if (uVar7 == 0) {
      *puVar1 = 0xffff;
      puVar1[1] = 0xffff;
    }
    puVar1[2] = uVar7 | param_1[1];
    if ((uVar2 & uVar7) == 0) {
      puVar5 = (ushort *)*param_3;
      if ((uVar2 & ~puVar5[1]) == 0) {
        uVar9 = 0;
        local_14 = 0;
        local_10 = 1;
      }
      else {
        puVar8 = puVar5 + 3;
        uVar9 = 0;
        do {
          local_10 = uVar9;
          uVar9 = local_10 + 1;
          uVar7 = *puVar8;
          puVar8 = puVar8 + 2;
        } while ((uVar2 & ~uVar7) != 0);
        local_14 = uVar9 * 4;
        puVar5 = puVar5 + uVar9 * 2;
        local_10 = local_10 + 2;
      }
      uVar7 = *puVar5;
      puVar5[1] = puVar5[1] & ~uVar2;
      uVar3 = *(ushort *)(param_3 + 1);
      if (uVar3 == local_10) {
        if (*(short *)(local_14 + 2 + *param_3) != 0) {
          *(ushort *)(param_3 + 1) = uVar3 + 1;
          uVar9 = local_10;
        }
        *(ushort *)(*param_3 + uVar9 * 4) = uVar7 + 1;
        *(undefined2 *)(uVar9 * 4 + 2 + *param_3) = 0xf;
      }
      else {
        iVar4 = *param_3;
        if ((*(short *)(iVar4 + 2 + local_14) == 0) &&
           (*(ushort *)(param_3 + 1) = uVar3 - 1, uVar9 < (ushort)(uVar3 - 1))) {
          iVar6 = uVar9 * 4;
          while( true ) {
            *(undefined4 *)(iVar6 + iVar4) = ((undefined4 *)(iVar6 + iVar4))[1];
            uVar9 = uVar9 + 1;
            iVar6 = iVar6 + 4;
            if (*(ushort *)(param_3 + 1) <= uVar9) break;
            iVar4 = *param_3;
          }
        }
      }
      if ((uVar2 & 7) != 0) {
        *puVar1 = uVar7;
      }
      if ((uVar2 & 8) != 0) {
        puVar1[1] = uVar7;
      }
    }
    if (uVar2 == 8) {
      uVar7 = puVar1[1];
    }
    else {
      uVar7 = *puVar1;
    }
    *param_1 = uVar7;
  }
  return;
}

/* FUN_000c37eb @ 0xc37eb (540 bytes) */
int FUN_000c37eb(param_1)
  int param_1;
{
  int iVar1;
  ushort *puVar2;
  int iVar3;
  uint local_60;
  ushort local_3c [22];
  
  if (*(short *)(param_1 + 0x14) != 0) {
    return;
  }
  puVar2 = local_3c;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    puVar2[0] = 0;
    puVar2[1] = 0;
    puVar2 = puVar2 + 2;
  }
  if (*(int *)(param_1 + 8) != 0) {
    local_60 = 1;
    iVar1 = 0;
    do {
      if (*(uint *)(param_1 + 0x48 + iVar1) < 6) {
                    
                    
        (*(code *)(*(int *)(((unsigned char *)0x000c39e4) + *(int *)(param_1 + 0x48 + iVar1) * 4) + 0xc37fc))();
        return;
      }
      local_60 = local_60 + 1;
      iVar1 = iVar1 + 0x48;
    } while (local_60 <= *(uint *)(param_1 + 8));
  }
  *(undefined2 *)(param_1 + 0x16) = 1;
  *(undefined2 *)(param_1 + 0x18) = 1;
  *(undefined2 *)(param_1 + 0x1a) = 0;
  *(undefined2 *)(param_1 + 0x1c) = 1;
  *(undefined2 *)(param_1 + 0x1e) = 1;
  *(undefined2 *)(param_1 + 0x20) = 0;
  *(undefined2 *)(param_1 + 0x22) = 0;
  *(undefined2 *)(param_1 + 0x24) = 0;
  *(undefined2 *)(param_1 + 0x26) = 1;
  *(undefined2 *)(param_1 + 0x28) = 0;
  iVar3 = 1;
  iVar1 = param_1;
  puVar2 = local_3c;
  do {
    if (0xff < *puVar2) {
      *puVar2 = 0xff;
    }
    *(char *)(iVar1 + 0x2a) = (char)*puVar2;
    iVar3 = iVar3 + 1;
    iVar1 = iVar1 + 1;
    puVar2 = puVar2 + 1;
  } while (iVar3 != 0x11);
  *(undefined2 *)(param_1 + 0x14) = 1;
  return;
}

/* FUN_000c3d65 @ 0xc3d65 (3301 bytes) */
int FUN_000c3d65(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  ushort uVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined2 uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  uint *local_8dc;
  uint local_8d8;
  int local_8b0;
  uint *local_8ac;
  uint auStack_870 [512];
  uint local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined2 *local_48;
  undefined2 *local_44;
  short local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined2 *local_34;
  undefined2 local_30;
  short asStack_2e [15];
  
  asStack_2e[8] = 0;
  asStack_2e[7] = 0;
  asStack_2e[6] = 0;
  asStack_2e[5] = 0;
  asStack_2e[4] = 0;
  asStack_2e[3] = 0;
  asStack_2e[2] = 0;
  asStack_2e[1] = 0;
  local_34 = *(undefined2 **)(param_1 + 0x1c);
  *local_34 = 0;
  local_34[1] = 0xf;
  local_30 = 1;
  local_40 = param_3;
  local_48 = local_34 + *(int *)(param_1 + 0x30) * 2;
  _memset(local_48,0,*(int *)(param_1 + 0x30) << 3);
  if (param_3 == 0) {
    local_44 = (undefined2 *)0x0;
  }
  else {
    local_44 = local_48 + *(int *)(param_1 + 0x30) * 4;
    _memset(local_44,0,*(int *)(param_1 + 0x30) * 8);
  }
  iVar3 = *(int *)(param_2 + 8);
  if (iVar3 != 0) {
    local_8d8 = 0;
    local_8dc = (uint *)0x0;
    local_8b0 = 0;
    local_8ac = (uint *)(param_2 + iVar3 * 0x48);
    do {
      uVar7 = *local_8ac;
      if (uVar7 == 2) {
        local_3c = CONCAT22(0xf,(short)local_8ac[3]);
        if (*(char *)((int)local_8ac + 0x1a) == '\0') {
          *(undefined2 *)(local_8ac + 3) = 0;
          *(undefined2 *)((int)local_8ac + 0xe) = 0;
          *(undefined1 *)((int)local_8ac + 0x19) = 0;
          *(undefined1 *)((int)local_8ac + 0x1f) = 0xf;
        }
        else {
          if (*(char *)((int)local_8ac + 0x1a) == '\x02') {
            *(undefined2 *)(local_8ac + 3) = 0;
          }
          else {
            ((int (*)())FUN_000c33e7)();
            *(short *)(local_8ac + 3) = (short)local_3c;
          }
          local_70 = (uint)(uint3)(CONCAT12(*(undefined1 *)((int)local_8ac + 0x1f),
                                            *(undefined2 *)((int)local_8ac + 0xe)) ^ 0xf0000);
          ((int (*)())FUN_000c35f3)();
          *(short *)((int)local_8ac + 0xe) = (short)local_70;
        }
        if (((local_8dc == (uint *)0x0) || (*local_8dc != 2)) || ((char)local_8dc[8] != '\0')) {
          local_8d8 = 0;
        }
        if (*(char *)((int)local_8ac + 0x1a) != '\0') {
          if (local_8d8 == 0) {
            uVar7 = (uint)*(ushort *)((int)local_8ac + 0xe);
          }
          else {
            uVar10 = 0;
            uVar7 = (uint)*(ushort *)((int)local_8ac + 0xe);
            uVar9 = local_8d8;
            do {
              uVar4 = auStack_870[uVar10];
              if (((ushort)local_8ac[3] == uVar4) && (*(char *)((int)local_8ac + 0x1a) != '\x02')) {
                *(undefined1 *)(local_8dc + 8) = 1;
                local_8d8 = 0;
                if (uVar4 == uVar7) {
                  uVar9 = uVar10;
                }
                break;
              }
              if (uVar4 == uVar7) {
                uVar9 = uVar10;
              }
              uVar10 = uVar10 + 1;
            } while (uVar10 < local_8d8);
            if (uVar9 < local_8d8) goto LAB_000c3e4b;
          }
          auStack_870[local_8d8] = uVar7;
          local_8d8 = local_8d8 + 1;
        }
        goto LAB_000c3e4b;
      }
      if (uVar7 < 3) {
        if (uVar7 == 1) {
          local_3c = CONCAT22(0xf,*(undefined2 *)((int)local_8ac + 6));
          local_38 = CONCAT22(0xf,(short)local_8ac[1]);
          if (*(char *)((int)local_8ac + 0xb) == '\0') {
            *(undefined2 *)((int)local_8ac + 6) = 0;
            *(undefined1 *)((int)local_8ac + 10) = 0;
            *(undefined1 *)((int)local_8ac + 0xd) = 0;
            *(undefined1 *)((int)local_8ac + 0xf) = 0xf;
            cVar2 = *(char *)((int)local_8ac + 9);
          }
          else {
            ((int (*)())FUN_000c33e7)();
            *(short *)((int)local_8ac + 6) = (short)local_3c;
            *(byte *)((int)local_8ac + 0xf) = (*(unsigned char *)((unsigned char *)&(local_3c) + 2)) ^ 0xf;
            cVar2 = *(char *)((int)local_8ac + 9);
          }
          if (cVar2 == '\0') {
            *(undefined2 *)(local_8ac + 1) = 0;
            *(undefined1 *)(local_8ac + 2) = 0;
            *(undefined1 *)(local_8ac + 3) = 0;
            *(undefined1 *)((int)local_8ac + 0xe) = 0xf;
          }
          else {
            ((int (*)())FUN_000c33e7)();
            *(short *)(local_8ac + 1) = (short)local_38;
            *(byte *)((int)local_8ac + 0xe) = (*(unsigned char *)((unsigned char *)&(local_38) + 2)) ^ 0xf;
          }
        }
        goto LAB_000c3e4b;
      }
      if (4 < uVar7) goto LAB_000c3e4b;
      local_3c = (uint)CONCAT12((char)local_8ac[5],(short)local_8ac[3]);
      if ((char)local_8ac[8] == '\0') {
        uVar6 = 0;
      }
      else {
        uVar6 = 8;
      }
      local_38 = CONCAT22(uVar6,(short)local_8ac[6]);
      ((int (*)())FUN_000c33e7)();
      *(short *)(local_8ac + 3) = (short)local_3c;
      *(byte *)(local_8ac + 5) = (byte)(local_3c >> 0x10);
      ((int (*)())FUN_000c33e7)();
      *(short *)(local_8ac + 6) = (short)local_38;
      *(bool *)(local_8ac + 8) = (*(unsigned short *)((unsigned char *)&(local_38) + 2)) != 0;
      puVar11 = &local_70;
      for (iVar8 = 6; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar11 = 0;
        puVar11 = puVar11 + 1;
      }
      local_58 = 0;
      local_54 = 0;
      local_50 = 0;
      local_4c = 0;
      switch(*(undefined1 *)((int)local_8ac + 0x31)) {
      case 0:
      case 7:
      case 8:
        ((int (*)())FUN_000c2fb4)(*(undefined1 *)((int)local_8ac + 0x3f),&local_70,&local_58);
        ((int (*)())FUN_000c2fb4)(*(undefined1 *)((int)local_8ac + 0x3f),&local_70,&local_58);
        goto LAB_000c40dc;
      case 1:
      case 4:
      case 5:
        ((int (*)())FUN_000c2fb4)(*(undefined1 *)((int)local_8ac + 0x3f),&local_70,&local_58);
        goto LAB_000c40dc;
      case 2:
        ((int (*)())FUN_000c2fb4)(*(undefined1 *)((int)local_8ac + 0x3f),&local_70,&local_58);
        ((int (*)())FUN_000c2fb4)(*(undefined1 *)((int)local_8ac + 0x3f),&local_70,&local_58);
        ((int (*)())FUN_000c325f)(*(undefined1 *)((int)local_8ac + 0x3f),&local_70,&local_58);
        ((int (*)())FUN_000c325f)(*(undefined1 *)((int)local_8ac + 0x3f),&local_70,&local_58);
        break;
      case 3:
        ((int (*)())FUN_000c2fb4)(*(undefined1 *)((int)local_8ac + 0x3f),&local_70,&local_58);
        ((int (*)())FUN_000c2fb4)(*(undefined1 *)((int)local_8ac + 0x3f),&local_70,&local_58);
LAB_000c40dc:
        ((int (*)())FUN_000c2fb4)(*(undefined1 *)((int)local_8ac + 0x3f),&local_70,&local_58);
        break;
      case 9:
        ((int (*)())FUN_000c2fb4)(*(undefined1 *)((int)local_8ac + 0x3f),&local_70,&local_58);
      }
      if ((byte)local_8ac[0x10] < 0xc) {
        uVar7 = 1 << ((byte)local_8ac[0x10] & 0x1f);
        if ((uVar7 & 0x61) == 0) {
          if ((uVar7 & 0xc) == 0) {
            if ((uVar7 & 0xf80) != 0) {
              ((int (*)())FUN_000c325f)(*(undefined1 *)((int)local_8ac + 0x3f),&local_70,&local_58);
            }
            goto LAB_000c41c7;
          }
          ((int (*)())FUN_000c325f)(*(undefined1 *)((int)local_8ac + 0x3f),&local_70,&local_58);
        }
        else {
          ((int (*)())FUN_000c325f)(*(undefined1 *)((int)local_8ac + 0x3f),&local_70,&local_58);
          ((int (*)())FUN_000c325f)(*(undefined1 *)((int)local_8ac + 0x3f),&local_70,&local_58);
        }
        ((int (*)())FUN_000c325f)(*(undefined1 *)((int)local_8ac + 0x3f),&local_70,&local_58);
      }
LAB_000c41c7:
      local_70 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_70) + 2)),*(undefined2 *)((int)local_8ac + 0xe));
      local_6c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_6c) + 2)),(short)local_8ac[4]);
      local_68 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_68) + 2)),*(undefined2 *)((int)local_8ac + 0x12));
      local_64 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_64) + 2)),*(undefined2 *)((int)local_8ac + 0x1a));
      local_60 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_60) + 2)),(short)local_8ac[7]);
      local_5c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_5c) + 2)),*(undefined2 *)((int)local_8ac + 0x1e));
      local_58 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_58) + 2)),*(undefined2 *)((int)local_8ac + 0xe));
      local_54 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_54) + 2)),(short)local_8ac[4]);
      local_50 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_50) + 2)),*(undefined2 *)((int)local_8ac + 0x1a));
      local_4c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_4c) + 2)),(short)local_8ac[7]);
      ((int (*)())FUN_000c35f3)();
      *(short *)((int)local_8ac + 0xe) = (short)local_70;
      ((int (*)())FUN_000c35f3)();
      *(short *)(local_8ac + 4) = (short)local_6c;
      ((int (*)())FUN_000c35f3)();
      *(short *)((int)local_8ac + 0x12) = (short)local_68;
      ((int (*)())FUN_000c35f3)();
      *(short *)((int)local_8ac + 0x1a) = (short)local_64;
      ((int (*)())FUN_000c35f3)();
      *(short *)(local_8ac + 7) = (short)local_60;
      ((int (*)())FUN_000c35f3)();
      *(short *)((int)local_8ac + 0x1e) = (short)local_5c;
      *(undefined1 *)(local_8ac + 0xd) = 0;
      if ((local_8dc != (uint *)0x0) && (*local_8dc - 3 < 2)) {
        uVar1 = ~-(ushort)((char)local_8ac[8] == '\0') & 8 | (ushort)(byte)local_8ac[5];
        iVar8 = 1;
        iVar5 = 2;
        while( true ) {
          if (((short)local_8ac[3] == asStack_2e[3]) &&
             ((*(ushort *)((int)asStack_2e + iVar5 + 0xc) & uVar1) != 0)) {
            *(undefined1 *)(local_8ac + 0xd) = 1;
          }
          if (((short)local_8ac[6] == *(short *)((int)asStack_2e + iVar5)) &&
             ((*(ushort *)((int)asStack_2e + iVar5 + 8) & uVar1) != 0)) {
            *(undefined1 *)(local_8ac + 0xd) = 1;
          }
          iVar8 = iVar8 + 1;
          if (iVar8 == 3) break;
          asStack_2e[3] = *(short *)((int)asStack_2e + iVar5 + 6);
          iVar5 = iVar5 + 2;
        }
      }
      asStack_2e[3] = *(short *)((int)local_8ac + 0xe);
      asStack_2e[4] = (short)local_8ac[4];
      asStack_2e[1] = *(undefined2 *)((int)local_8ac + 0x1a);
      asStack_2e[2] = (short)local_8ac[7];
      asStack_2e[7] = (*(unsigned short *)((unsigned char *)&(local_58) + 2));
      asStack_2e[8] = (*(unsigned short *)((unsigned char *)&(local_54) + 2));
      asStack_2e[5] = (*(unsigned short *)((unsigned char *)&(local_50) + 2));
      asStack_2e[6] = (*(unsigned short *)((unsigned char *)&(local_4c) + 2));
LAB_000c3e4b:
      local_8b0 = local_8b0 + 1;
      local_8dc = local_8ac;
      local_8ac = local_8ac + -0x12;
    } while (iVar3 != local_8b0);
  }
  ((int (*)())FUN_000c37eb)(param_2);
  return;
}

/* FUN_000c4a74 @ 0xc4a74 (22 bytes) */
int FUN_000c4a74(param_1, param_2)
  undefined4 param_1;
  size_t param_2;
{
  _calloc(param_2,1);
  return;
}

/* FUN_000c4a8a @ 0xc4a8a (21 bytes) */
int FUN_000c4a8a(param_1, param_2)
  undefined4 param_1;
  void *param_2;
{
  _free(param_2);
  return 0;
}

/* FUN_000c4a9f @ 0xc4a9f (16 bytes) */
int FUN_000c4a9f(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  *param_3 = 0;
  return 0;
}

/* FUN_000c4aaf @ 0xc4aaf (94 bytes) */
int FUN_000c4aaf(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  char *param_2;
  char *param_3;
  va_list param_4;
{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  char local_10c [256];
  
  _strcpy(local_10c,param_2);
  uVar2 = 0xffffffff;
  pcVar3 = local_10c;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  _vsnprintf(local_10c + (~uVar2 - 1),0x100 - (~uVar2 - 1),param_3,param_4);
  return;
}

/* FUN_000c4b0d @ 0xc4b0d (87 bytes) */
int FUN_000c4b0d(param_1, param_2, param_3)
  undefined4 param_1;
  char *param_2;
  int param_3;
{
  FILE *pFVar1;
  
  if (param_3 == 2) {
    pFVar1 = _fopen(param_2,"w");
    return pFVar1;
  }
  if (param_3 != 3) {
    if (param_3 != 1) {
      return (FILE *)0x0;
    }
    pFVar1 = _fopen(param_2,"r");
    return pFVar1;
  }
  pFVar1 = _fopen(param_2,"r+");
  return pFVar1;
}

/* FUN_000c4b64 @ 0xc4b64 (27 bytes) */
int FUN_000c4b64(param_1, param_2)
  undefined4 param_1;
  FILE *param_2;
{
  int iVar1;
  
  iVar1 = _fclose(param_2);
  return iVar1 == 0;
}

/* FUN_000c4b7f @ 0xc4b7f (46 bytes) */
int FUN_000c4b7f(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  FILE *param_2;
  void *param_3;
  size_t param_4;
{
  size_t sVar1;
  
  if ((param_3 != (void *)0x0) && (param_2 != (FILE *)0x0)) {
    sVar1 = _fwrite(param_3,1,param_4,param_2);
    return sVar1;
  }
  return 0;
}

/* FUN_000c4bad @ 0xc4bad (46 bytes) */
int FUN_000c4bad(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  FILE *param_2;
  void *param_3;
  size_t param_4;
{
  size_t sVar1;
  
  if ((param_3 != (void *)0x0) && (param_2 != (FILE *)0x0)) {
    sVar1 = _fread(param_3,1,param_4,param_2);
    return sVar1;
  }
  return 0;
}

/* FUN_000c4bdb @ 0xc4bdb (449 bytes) */
int FUN_000c4bdb(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_54;
  undefined4 *local_50;
  code *local_4c;
  code *local_48;
  code *local_44;
  code *local_40;
  code *local_3c;
  code *local_38;
  code *local_34;
  code *local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  _memset(&local_7c,0,0x54);
  local_28 = 0;
  local_20 = 0;
  local_78 = *(undefined4 *)(param_1 + 0x23d8);
  if (param_2 == 0) {
    local_7c = 0x2c;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x23d4);
    if (((iVar1 - 0x7240U < 0x10) || (iVar1 - 0x7100U < 0x10)) ||
       (((((iVar1 != 0x71c0 &&
           ((((iVar1 != 0x71c2 && (iVar1 != 0x71c6)) && (iVar1 != 0x71ce)) &&
            ((iVar1 != 0x71d2 && (iVar1 != 0x71de)))))) && (iVar1 != 0x71c4)) &&
         (((iVar1 != 0x71c5 && (iVar1 != 0x7140)) &&
          ((iVar1 != 0x7142 && (((iVar1 != 0x7146 && (iVar1 != 0x714e)) && (iVar1 != 0x7152))))))))
        && (((iVar1 != 0x715e && (iVar1 != 0x7144)) &&
            ((iVar1 != 0x7145 && ((iVar1 != 29000 && (iVar1 != 0x7149)))))))))) {
      local_7c = 0x3c;
    }
    else {
      local_7c = 0x3e;
    }
  }
  local_54 = 2;
  local_4c = FUN_000c4a74;
  local_48 = FUN_000c4a8a;
  local_44 = FUN_000c4a9f;
  local_40 = FUN_000c4aaf;
  local_3c = FUN_000c4b0d;
  local_38 = FUN_000c4b64;
  local_34 = FUN_000c4b7f;
  local_30 = FUN_000c4bad;
  local_24 = 0x7b;
  local_50 = (undefined4 *)(param_1 + 0x186c);
  uVar2 = ((int (*)())FUN_000cafc8)(&local_7c,&local_28,((unsigned char *)0x00010001));
  *(undefined4 *)(param_1 + 0x186c) = uVar2;
  *(undefined4 *)(param_1 + 0x1870) = local_24;
  return;
}

/* FUN_000c4d9c @ 0xc4d9c (25 bytes) */
int FUN_000c4d9c(param_1)
  int *param_1;
{
  if (*param_1 != 0) {
    ((int (*)())FUN_000cb076)(*param_1);
  }
  return;
}

/* FUN_000c4db8 @ 0xc4db8 (44 bytes) */
int FUN_000c4db8(param_1)
  void *param_1;
{
  if (param_1 != (void *)0x0) {
    ((int (*)())FUN_000c4db8)(*(undefined4 *)((int)param_1 + 0x24));
    _free(param_1);
    return;
  }
  return;
}

/* FUN_000c4de4 @ 0xc4de4 (43 bytes) */
int FUN_000c4de4(param_1)
  int param_1;
{
  if (param_1 == 2) {
    return 2;
  }
  if (param_1 != 3) {
    if (param_1 != 1) {
      return 0;
    }
    return 1;
  }
  return 3;
}

/* FUN_000c4e0f @ 0xc4e0f (23 bytes) */
int FUN_000c4e0f(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  *(undefined4 *)(param_1 + 0x2238 + param_2 * 4) = param_3;
  *(undefined4 *)(param_1 + 0x2278 + param_2 * 4) = 1;
  return;
}

/* FUN_000c4e26 @ 0xc4e26 (133 bytes) */
int FUN_000c4e26(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 *param_3;
{
  uint *puVar1;
  int iVar2;
  
  iVar2 = param_2 * 0x10 + param_1;
  *(undefined4 *)(iVar2 + 0x1a8) = *param_3;
  *(undefined4 *)(iVar2 + 0x1ac) = param_3[1];
  *(undefined4 *)(iVar2 + 0x1b0) = param_3[2];
  *(undefined4 *)(iVar2 + 0x1b4) = param_3[3];
  iVar2 = param_2;
  if (param_2 < 0) {
    iVar2 = param_2 + 0x1f;
  }
  if (param_2 < 0) {
    puVar1 = (uint *)(param_1 + 0x188 + (iVar2 >> 5) * 4);
    *puVar1 = *puVar1 | 1 << ((byte)param_2 & 0x1f);
    return;
  }
  puVar1 = (uint *)(param_1 + 0x188 + (iVar2 >> 5) * 4);
  *puVar1 = *puVar1 | 1 << ((byte)param_2 & 0x1f);
  return;
}

/* FUN_000c4eab @ 0xc4eab (133 bytes) */
int FUN_000c4eab(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 *param_3;
{
  uint *puVar1;
  int iVar2;
  
  iVar2 = param_2 * 0x10 + param_1;
  *(undefined4 *)(iVar2 + 0x11c8) = *param_3;
  *(undefined4 *)(iVar2 + 0x11cc) = param_3[1];
  *(undefined4 *)(iVar2 + 0x11d0) = param_3[2];
  *(undefined4 *)(iVar2 + 0x11d4) = param_3[3];
  iVar2 = param_2;
  if (param_2 < 0) {
    iVar2 = param_2 + 0x1f;
  }
  if (param_2 < 0) {
    puVar1 = (uint *)(param_1 + 0x11a8 + (iVar2 >> 5) * 4);
    *puVar1 = *puVar1 | 1 << ((byte)param_2 & 0x1f);
    return;
  }
  puVar1 = (uint *)(param_1 + 0x11a8 + (iVar2 >> 5) * 4);
  *puVar1 = *puVar1 | 1 << ((byte)param_2 & 0x1f);
  return;
}

/* FUN_000c4f30 @ 0xc4f30 (52 bytes) */
int FUN_000c4f30(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0;
  do {
    uVar2 = 1 << ((byte)iVar1 & 0x1f);
    if ((uVar2 & *(uint *)(param_1 + 8)) == 0) {
      *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | uVar2;
      return iVar1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 != 8);
  return 0x11;
}

/* FUN_000c4f64 @ 0xc4f64 (16 bytes) */
int FUN_000c4f64(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x50);
  *(int *)(param_1 + 0x50) = iVar1 + 1;
  return iVar1;
}

/* FUN_000c4f74 @ 0xc4f74 (100 bytes) */
int FUN_000c4f74(param_1)
  int param_1;
{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar3 = 0;
  iVar4 = param_1;
  do {
    uVar2 = *(uint *)(iVar4 + 0xc);
    if (uVar2 != 0) {
      if ((uVar2 & 1) == 0) {
        iVar4 = 0;
        do {
          iVar4 = iVar4 + 1;
          uVar5 = 1 << ((byte)iVar4 & 0x1f);
        } while ((uVar2 & uVar5) == 0);
        uVar5 = ~uVar5;
      }
      else {
        iVar4 = 0;
        uVar5 = 0xfffffffe;
      }
      puVar1 = (uint *)(param_1 + 0xc + iVar3 * 4);
      *puVar1 = *puVar1 & uVar5;
      return iVar4 + iVar3 * 0x20;
    }
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 + 4;
  } while (iVar3 != 8);
  return -1;
}

/* FUN_000c4fd8 @ 0xc4fd8 (329 bytes) */
int FUN_000c4fd8(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint3 *param_2;
  int param_3;
  int param_4;
  undefined4 *param_5;
{
  byte bVar1;
  uint uVar2;
  
  if ((*(uint *)(param_1 + 0x70) & 1 << (param_4 & 0x1f)) == 0) {
    return param_5;
  }
  *param_5 = 0x51;
  param_5[1] = *(ushort *)(param_1 + 0x184) | 0x440000;
  param_5[2] = 0x40;
  param_5[3] = *param_2 & 0x3fffff | 0x400000;
  if ((*param_2 & 0x400000) == 0) {
    uVar2 = 0x5555;
    goto LAB_000c5052;
  }
  bVar1 = *(byte *)(param_3 + 2) >> 5;
  if (bVar1 == 1) {
    uVar2 = 1;
  }
  else if (bVar1 < 2) {
    if (bVar1 == 0) {
      uVar2 = 5;
    }
    else {
LAB_000c50e4:
      uVar2 = 0;
    }
  }
  else if (bVar1 == 2) {
    uVar2 = 2;
  }
  else {
    if (bVar1 != 3) goto LAB_000c50e4;
    uVar2 = 3;
  }
  uVar2 = uVar2 << 4 | uVar2 | uVar2 << 8 | uVar2 << 0xc;
LAB_000c5052:
  param_5[4] = uVar2;
  param_5[5] = 0x49;
  param_5[6] = *(ushort *)(param_1 + 0x184) | 0x440000;
  param_5[7] = 0x110;
  param_5[8] = *(ushort *)(param_1 + 0x184) | 0x440000;
  param_5[9] = 0x3333;
  param_5[10] = *param_2 & 0x3fffff | 0x400000;
  param_5[0xb] = 0x2222;
  return param_5 + 0xc;
}

/* FUN_000c5121 @ 0xc5121 (514 bytes) */
int FUN_000c5121(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  uint *param_3;
  uint *param_4;
  int param_5;
  int param_6;
  uint *param_7;
{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  undefined *local_24;
  
  if ((*(uint *)(param_1 + 0x70) & 1 << ((byte)param_5 & 0x1f)) != 0) {
    *param_7 = 0x5b;
    param_7[1] = *(ushort *)(param_1 + 0x180) | 0x440000;
    param_7[2] = 0x10;
    param_7[3] = *(ushort *)(param_1 + 0x184) | 0x440000;
    param_7[4] = 0x2222;
    param_7[5] = (uint3)*param_3 & 0x3fffff | 0x400000;
    param_7[6] = 0x2222;
    local_24 = (undefined *)0xd;
    switch(*(undefined4 *)(param_1 + 0x138 + param_5 * 4)) {
    case 0x200:
    case 0x202:
    case 0x207:
      local_24 = ((unsigned char *)0x0001000d);
      break;
    case 0x201:
      local_24 = (undefined *)0x5000d;
      break;
    case 0x203:
      local_24 = (undefined *)0x4000d;
      break;
    case 0x204:
      local_24 = (undefined *)0x3000d;
      break;
    case 0x205:
      local_24 = (undefined *)0xd;
      break;
    case 0x206:
      local_24 = (undefined *)0x2000d;
    }
    param_7[7] = (uint)local_24;
    if (param_6 == 0) {
      param_7[8] = *param_3;
      puVar3 = param_7 + 9;
    }
    else {
      *(byte *)((int)param_3 + 2) = *(byte *)((int)param_3 + 2) | 0x40;
      param_7[8] = *param_3;
      puVar3 = param_7 + 9;
      if (param_6 != 0) {
        param_7[9] = *param_4;
        puVar3 = param_7 + 10;
      }
    }
    *puVar3 = *(ushort *)(param_1 + 0x180) | 0x440000;
    iVar1 = *(int *)(param_1 + 0x138 + param_5 * 4);
    if ((iVar1 == 0x200) || (iVar1 != 0x207)) {
      uVar2 = 0x2222;
    }
    else {
      uVar2 = 0x4444;
    }
    puVar3[1] = uVar2;
    puVar3[2] = (ushort)*param_3 | 0x440000;
    puVar3[3] = 0x5555;
    puVar3[4] = *(ushort *)(param_1 + 0xb8 + param_5 * 4) | 0x410000;
    puVar3[5] = 0x2222;
    param_7 = puVar3 + 6;
  }
  return param_7;
}

/* FUN_000c5345 @ 0xc5345 (1329 bytes) */
int FUN_000c5345(param_1, param_2)
  undefined4 *param_1;
  uint param_2;
{
  undefined2 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  
  if (*(int *)(param_2 + 0x22fc) != 0) {
    iVar6 = 0;
    uVar3 = param_2;
    uVar4 = param_2;
    do {
      if (*(int *)(uVar3 + 0x21f0) != 0) {
        *param_1 = 0x47;
        param_1[1] = *(ushort *)(uVar3 + 0x21e0) | 0x440000;
        param_1[2] = 0x115;
        uVar4 = *(ushort *)(uVar3 + 0x21e0) | 0x40000;
        param_1[3] = uVar4;
        param_1 = param_1 + 4;
      }
      iVar6 = iVar6 + 1;
      uVar3 = uVar3 + 4;
    } while (iVar6 != 4);
    iVar6 = *(int *)(param_2 + 0x22fc);
    uVar1 = (undefined2)(uVar4 >> 0x10);
    if (iVar6 == 2) {
      *param_1 = 0x49;
      param_1[1] = *(ushort *)(param_2 + 0x2300) | 0x440000;
      param_1[2] = 1;
      param_1[3] = CONCAT22(uVar1,*(undefined2 *)(param_2 + 0x2304)) & 0xffc0ffff | 0x410000;
      param_1[4] = 0x2222;
      param_1[5] = *(ushort *)(param_2 + 0x68) | 0x510000;
      param_1[6] = -(uint)(*(int *)(param_2 + 0x230c) == 0) & 0x100000;
      param_1[7] = 0x2d;
      param_1[8] = *(ushort *)(param_2 + 0x2300) | 0x440000;
      param_1[9] = 0x101;
      param_1[10] = *(ushort *)(param_2 + 0x2300) | 0x440000;
      param_1[0xb] = 0x8888;
      param_1 = param_1 + 0xc;
    }
    else if (iVar6 == 3) {
      *param_1 = 0x49;
      param_1[1] = *(ushort *)(param_2 + 0x2300) | 0x440000;
      param_1[2] = 1;
      param_1[3] = CONCAT22(uVar1,*(undefined2 *)(param_2 + 0x2304)) & 0xffc0ffff | 0x410000;
      param_1[4] = 0x3333;
      param_1[5] = *(ushort *)(param_2 + 0x68) | 0x510000;
      param_1[6] = -(uint)(*(int *)(param_2 + 0x230c) == 0) & 0x100000;
      param_1[7] = 0x49;
      param_1[8] = CONCAT22(4,*(undefined2 *)(param_2 + 0x2300));
      uVar5 = CONCAT22(4,*(undefined2 *)(param_2 + 0x2300));
      param_1[9] = uVar5;
      param_1[10] = uVar5;
      param_1[0xb] = 0x2d;
      param_1[0xc] = *(ushort *)(param_2 + 0x2300) | 0x440000;
      param_1[0xd] = 0x101;
      param_1[0xe] = *(ushort *)(param_2 + 0x2300) | 0x440000;
      param_1[0xf] = 0x8888;
      param_1 = param_1 + 0x10;
    }
    else if (iVar6 == 1) {
      *param_1 = 0x40;
      param_1[1] = *(ushort *)(param_2 + 0x2300) | 0x440000;
      param_1[2] = 0x101;
      param_1[3] = *(ushort *)(param_2 + 0x68) | 0x510000;
      param_1[4] = -(uint)(*(int *)(param_2 + 0x230c) == 0) & 0x100000;
      param_1[5] = CONCAT22(0x40,*(undefined2 *)(param_2 + 0x2304)) | 0x410000;
      param_1[6] = 0;
      param_1[7] = CONCAT22(0x41,*(undefined2 *)(param_2 + 0x2304)) & 0xffc0ffff | 0x410000;
      param_1[8] = 0x1111;
      param_1 = param_1 + 9;
    }
    uVar3 = param_2;
    do {
      if (*(int *)(uVar3 + 0x21f0) != 0) {
        *param_1 = 0x3f;
        param_1[1] = *(ushort *)(param_2 + 0x21e0) | 0x440000;
        param_1[2] = 0x15;
        param_1[3] = *(ushort *)(param_2 + 0x2300) | 0x440000;
        param_1[4] = 0;
        param_1[5] = CONCAT22(4,*(undefined2 *)(param_2 + 0x21e0));
        param_1[6] = *(ushort *)(param_2 + 0x2308) | 0x10000;
        param_1 = param_1 + 7;
      }
      uVar3 = uVar3 + 4;
    } while (uVar3 != param_2 + 0x10);
  }
  if (*(int *)(param_2 + 0x21d0) != 0) {
    uVar3 = param_2;
    do {
      if (*(int *)(uVar3 + 0x21f0) != 0) {
        *param_1 = 0x49;
        param_1[1] = *(ushort *)(uVar3 + 0x21e0) | 0x440000;
        param_1[2] = 0x40;
        param_1[3] = CONCAT22(4,*(undefined2 *)(uVar3 + 0x21e0));
        param_1[4] = *(ushort *)(param_2 + 0x21dc) | 0x440000;
        param_1[5] = 0;
        param_1 = param_1 + 6;
      }
      uVar3 = uVar3 + 4;
    } while (param_2 + 0x10 != uVar3);
  }
  iVar6 = 0;
  uVar3 = param_2;
  do {
    if (*(int *)(uVar3 + 0x21f0) != 0) {
      *param_1 = 0x47;
      param_1[1] = CONCAT22(0x17,(short)iVar6);
      param_1[2] = CONCAT22(4,*(undefined2 *)(uVar3 + 0x21e0));
      param_1 = param_1 + 3;
    }
    iVar6 = iVar6 + 1;
    uVar3 = uVar3 + 4;
  } while (iVar6 != 4);
  if (((*(int *)(param_2 + 0x220c) != 0) && (*(int *)(param_2 + 0x2204) != 0)) &&
     (*(int *)(param_2 + 0x2234) == 0)) {
    if (*(int *)(param_2 + 0x2210) == 0xffff) {
      *param_1 = 0x47;
      param_1[1] = 0x530000;
      param_1[2] = 0x40;
    }
    else {
      *param_1 = 0x47;
      param_1[1] = *(ushort *)(param_2 + 0x2210) | 0x510000;
      param_1[2] = 1;
    }
    param_1[3] = *(ushort *)(param_2 + 0x2208) | 0x440000;
    param_1[4] = 0;
    param_1 = param_1 + 5;
  }
  if ((*(int *)(param_2 + 0x2218) == 0) && (*(int *)(param_2 + 0x2220) == 0)) {
    if (*(int *)(param_2 + 0x2234) != 0) {
      return param_1;
    }
    iVar6 = *(int *)(param_2 + 0x2214);
  }
  else {
    iVar6 = *(int *)(param_2 + 0x2214);
  }
  if ((iVar6 == 0) && (*(int *)(param_2 + 0x221c) != 0)) {
    *param_1 = 0x47;
    param_1[1] = 0x120000;
    param_1[2] = 0x10000;
    param_1 = param_1 + 3;
    iVar6 = *(int *)(param_2 + 0x2234);
  }
  else {
    iVar6 = *(int *)(param_2 + 0x2234);
  }
  if (iVar6 == 0) {
    *param_1 = 0x47;
    param_1[1] = 0xe0000;
    param_1[2] = CONCAT22(4,*(undefined2 *)(param_2 + 0x2200));
    puVar2 = param_1 + 3;
    if (*(int *)(param_2 + 0x2310) != 0) {
      param_1[3] = 0x47;
      param_1[4] = CONCAT22(0x11,*(undefined2 *)(param_2 + 0x2314));
      param_1[5] = CONCAT22(4,*(undefined2 *)(param_2 + 0x2200));
      puVar2 = param_1 + 6;
    }
    return puVar2;
  }
  return param_1;
}

/* FUN_000c5876 @ 0xc5876 (1088 bytes) */
int FUN_000c5876(param_1, param_2)
  uint *param_1;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint *local_44;
  uint local_3c;
  uint local_38;
  int local_34;
  int local_30;
  undefined4 local_18;
  uint local_14;
  uint local_10;
  
  uVar3 = ((int (*)())FUN_000c4f64)();
  *(undefined4 *)(param_2 + 0x21e0) = uVar3;
  uVar3 = ((int (*)())FUN_000c4f64)();
  *(undefined4 *)(param_2 + 0x21e4) = uVar3;
  uVar3 = ((int (*)())FUN_000c4f64)();
  *(undefined4 *)(param_2 + 0x21e8) = uVar3;
  uVar3 = ((int (*)())FUN_000c4f64)();
  *(undefined4 *)(param_2 + 0x21ec) = uVar3;
  if (*(int *)(param_2 + 0x2324) != 0) {
    uVar3 = ((int (*)())FUN_000c4f64)();
    *(undefined4 *)(param_2 + 9000) = uVar3;
  }
  uVar3 = ((int (*)())FUN_000c4f64)();
  *(undefined4 *)(param_2 + 0x2200) = uVar3;
  uVar3 = ((int (*)())FUN_000c4f64)();
  *(undefined4 *)(param_2 + 0x2208) = uVar3;
  if (*(int *)(param_2 + 100) != 0) {
    uVar3 = ((int (*)())FUN_000c4f30)();
    *(undefined4 *)(param_2 + 0x68) = uVar3;
  }
  local_44 = param_1;
  if (*(int *)(param_2 + 0x22fc) != 0) {
    uVar3 = ((int (*)())FUN_000c4f64)();
    *(undefined4 *)(param_2 + 0x2300) = uVar3;
    uVar3 = ((int (*)())FUN_000c4f74)();
    *(undefined4 *)(param_2 + 0x2304) = uVar3;
    uVar3 = ((int (*)())FUN_000c4f74)();
    *(undefined4 *)(param_2 + 0x2308) = uVar3;
    *param_1 = 0x1ff0016;
    param_1[1] = CONCAT22(0x11,*(undefined2 *)(param_2 + 0x68));
    local_44 = param_1 + 2;
  }
  if (*(int *)(param_2 + 0x21d0) != 0) {
    uVar3 = ((int (*)())FUN_000c4f64)();
    *(undefined4 *)(param_2 + 0x21dc) = uVar3;
    *local_44 = 0x1ff0016;
    local_44[1] = CONCAT22(0x11,*(undefined2 *)(param_2 + 0x21d4));
    local_44[2] = *(int *)(param_2 + 0x21d4) << 0x10 | 0xb000019;
    local_44 = local_44 + 3;
  }
  if (*(int *)(param_2 + 0x4c) != 0) {
    uVar3 = ((int (*)())FUN_000c4f64)();
    *(undefined4 *)(param_2 + 0x54) = uVar3;
    uVar3 = ((int (*)())FUN_000c4f74)();
    *(undefined4 *)(param_2 + 0x58) = uVar3;
    uVar3 = ((int (*)())FUN_000c4f74)();
    *(undefined4 *)(param_2 + 0x5c) = uVar3;
    uVar3 = ((int (*)())FUN_000c4f30)();
    *(undefined4 *)(param_2 + 0x60) = uVar3;
    *local_44 = 0x1ff0016;
    local_44[1] = CONCAT22(0x11,*(undefined2 *)(param_2 + 0x60));
    local_44[2] = 0x51;
    local_44[3] = *(ushort *)(param_2 + 0x54) | 0x440000;
    local_44[4] = 0x40;
    local_18 = (uint)CONCAT12(0x11,(short)*(undefined4 *)(param_2 + 0x60));
    local_44[5] = local_18;
    local_44[6] = 0x49;
    local_44[7] = *(ushort *)(param_2 + 0x54) | 0x440000;
    local_44[8] = 0x15;
    local_18 = (uint)CONCAT12(0x44,(short)*(undefined4 *)(param_2 + 0x54));
    local_44[9] = local_18;
    local_44[10] = 0x3333;
    local_14 = (uint)CONCAT12(0x11,(short)*(undefined4 *)(param_2 + 0x60));
    local_44[0xb] = local_14;
    local_44[0xc] = 0x40;
    local_44[0xd] = *(ushort *)(param_2 + 0x54) | 0x440000;
    local_44[0xe] = 0x15;
    local_18 = (uint)CONCAT12(4,(short)*(undefined4 *)(param_2 + 0x54));
    local_44[0xf] = local_18;
    local_14 = (uint)CONCAT12(1,(short)*(undefined4 *)(param_2 + 0x58));
    local_44[0x10] = local_14;
    local_10 = (uint)CONCAT12(1,(short)*(undefined4 *)(param_2 + 0x5c));
    local_44[0x11] = local_10;
    local_44 = local_44 + 0x12;
  }
  if (*(int *)(param_2 + 0x2234) != 0) {
    uVar1 = *(uint *)(param_2 + 0x70);
    uVar2 = *(uint *)(param_2 + 0x74);
    local_3c = 0;
    local_30 = 0;
    local_34 = param_2;
    do {
      while (uVar6 = 1 << ((byte)local_30 & 0x1f), ((uVar1 | uVar2) & uVar6) == 0) {
        if ((*(uint *)(param_2 + 0x74) & uVar6) == 0) goto LAB_000c5942;
LAB_000c5986:
        uVar3 = ((int (*)())FUN_000c4f64)();
        *(undefined4 *)(param_2 + 0x184) = uVar3;
        uVar6 = 2;
        if (1 < local_3c) {
          uVar6 = local_3c;
        }
        local_30 = local_30 + 1;
        local_34 = local_34 + 4;
        local_3c = uVar6;
        if (local_30 == 0x10) goto LAB_000c59b1;
      }
      uVar3 = ((int (*)())FUN_000c4f74)();
      *(undefined4 *)(local_34 + 0xb8) = uVar3;
      uVar4 = 1;
      if (local_3c != 0) {
        uVar4 = local_3c;
      }
      local_3c = uVar4;
      if ((*(uint *)(param_2 + 0x74) & uVar6) != 0) goto LAB_000c5986;
LAB_000c5942:
      local_30 = local_30 + 1;
      local_34 = local_34 + 4;
    } while (local_30 != 0x10);
LAB_000c59b1:
    if (local_3c != 0) {
      local_38 = 0;
      iVar7 = param_2;
      do {
        uVar3 = ((int (*)())FUN_000c4f64)();
        *(undefined4 *)(iVar7 + 0x17c) = uVar3;
        local_38 = local_38 + 1;
        iVar7 = iVar7 + 4;
      } while (local_38 != local_3c);
    }
  }
  if (*(int *)(param_2 + 0x21d0) != 0) {
    *local_44 = (*(ushort *)(param_2 + 0x21d4) & 0x3fff) << 0x10 | 0x5d;
    local_44[1] = CONCAT22(4,*(undefined2 *)(param_2 + 0x21dc));
    local_18 = (uint)CONCAT12(0x11,(short)*(undefined4 *)(param_2 + 0x21d8));
    local_44[2] = local_18;
    local_44 = local_44 + 3;
  }
  iVar5 = 0;
  iVar7 = param_2;
  do {
    *(int *)(iVar7 + 0x232c) = iVar5;
    iVar5 = iVar5 + 1;
    iVar7 = iVar7 + 4;
  } while (iVar5 != 0x10);
  iVar7 = 0;
  iVar5 = 0;
  uVar1 = *(uint *)(param_2 + 8);
  do {
    if ((1 << ((byte)iVar7 & 0x1f) & uVar1) == 0) {
      *(int *)(param_2 + 0x232c + iVar5 * 4) = iVar7;
      iVar5 = iVar5 + 1;
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 != 0x10);
  return local_44;
}

/* FUN_000c5cb6 @ 0xc5cb6 (247 bytes) */
int FUN_000c5cb6(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int *param_3;
  int param_4;
  int param_5;
{
  if (*param_3 <= param_1) {
    if (param_3[1] < param_1) goto joined_r0x000c5d01;
    *param_3 = param_1 + 1;
  }
  if ((param_1 <= param_3[1]) && (*param_3 <= param_1)) {
    param_3[1] = param_1 + -1;
  }
joined_r0x000c5d01:
  if (param_2 == 0x17) {
    param_3[param_1 + 0x87c] = 1;
    if (((((param_4 & 3) == 1) || ((param_4 & 0xc) == 4)) || ((param_4 & 0x30) == 0x10)) ||
       (((param_4 & 0xc0) == 0x40 || (param_5 == 0)))) {
      param_3[0x889] = 1;
      return;
    }
  }
  else {
    if (param_2 == 0x18) {
      param_3[0x889] = 1;
      param_3[0x88a] = 1;
      return;
    }
    if (param_2 == 0x12) {
      param_3[param_1 + 0x885] = 1;
    }
    else {
      if (param_2 == 0x13) {
        param_3[param_1 + 0x887] = 1;
        return;
      }
      if (param_2 == 0x10) {
        param_3[0x883] = 1;
        return;
      }
      if (param_2 == 0x11) {
        if (param_3[0x8c7] < param_1) {
          param_3[0x8c7] = param_1;
        }
        param_3[2] = param_3[2] | 1 << ((byte)param_1 & 0x1f);
        return;
      }
    }
  }
  return;
}

/* FUN_000c5dad @ 0xc5dad (71 bytes) */
int FUN_000c5dad(param_1, param_2, param_3)
  uint *param_1;
  undefined4 param_2;
  int param_3;
{
  byte bVar1;
  
  bVar1 = *(byte *)((int)param_1 + 2);
  if ((bVar1 & 0x3f) == 0x16) {
    *param_1 = *param_1 & 0xffc0ffff | 0x40000;
    *(ushort *)param_1 = (ushort)*(undefined4 *)(param_3 + 0x54);
    bVar1 = *(byte *)((int)param_1 + 2);
  }
  if ((bVar1 & 0x3f) != 0xf) {
    return;
  }
  *(ushort *)param_1 = (ushort)*(undefined4 *)(param_3 + 0x232c + (uint)(ushort)*param_1 * 4);
  return;
}

/* FUN_000c5df4 @ 0xc5df4 (249 bytes) */
int FUN_000c5df4(param_1, param_2, param_3)
  ushort *param_1;
  undefined4 param_2;
  int param_3;
{
  uint *puVar1;
  ushort uVar2;
  byte bVar3;
  int iVar4;
  byte bVar5;
  int iVar6;
  
  uVar2 = *param_1;
  bVar3 = (byte)param_1[1] & 0x3f;
  iVar4 = (int)(uint)uVar2 >> 5;
  if (bVar3 == 1) {
    if ((param_1[1] & 0x180) == 0) {
      bVar5 = (byte)uVar2 & 0x1f;
      puVar1 = (uint *)(param_3 + 0xc + iVar4 * 4);
      *puVar1 = *puVar1 & (-2 << bVar5 | 0xfffffffeU >> 0x20 - bVar5);
    }
    else {
      iVar6 = 8;
      iVar4 = param_3;
      do {
        *(undefined4 *)(iVar4 + 0xc) = 0;
        iVar4 = iVar4 + 4;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
  }
  else if (bVar3 == 2) {
    if ((param_1[1] & 0x180) == 0) {
      bVar5 = (byte)uVar2 & 0x1f;
      puVar1 = (uint *)(param_3 + 0x2c + iVar4 * 4);
      *puVar1 = *puVar1 & (-2 << bVar5 | 0xfffffffeU >> 0x20 - bVar5);
    }
    else {
      iVar6 = 8;
      iVar4 = param_3;
      do {
        *(undefined4 *)(iVar4 + 0x2c) = 0;
        iVar4 = iVar4 + 4;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
  }
  else {
    if (bVar3 == 3) {
      if (uVar2 == 0) goto LAB_000c5e2d;
    }
    else if (bVar3 != 0x15) goto LAB_000c5e2d;
    *(undefined4 *)(param_3 + 0x21c8) = 5;
  }
LAB_000c5e2d:
  if ((param_1[1] & 0x180) != 0) {
    if (bVar3 == 1) {
      *(undefined4 *)(param_3 + 0x2230) = 1;
      return;
    }
    *(undefined4 *)(param_3 + 0x21c8) = 4;
  }
  return;
}

/* FUN_000c5eed @ 0xc5eed (400 bytes) */
int FUN_000c5eed(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  int param_2;
  int param_3;
  int param_4;
{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint *puVar4;
  uint *puVar5;
  short local_38;
  
  uVar1 = *param_1;
  puVar5 = param_1 + 1;
  if (param_2 != 0) {
    uVar2 = param_1[1];
    puVar5 = param_1 + 2;
    uVar3 = uVar1;
    if ((uVar2 >> 0x10 & 0x40) != 0) {
      uVar3 = param_1[2];
      puVar5 = param_1 + 3;
    }
    ((int (*)())FUN_000c5cb6)(uVar3,uVar2 >> 0x16 & 1);
    local_38 = (short)uVar1;
    if ((local_38 == 0x48) && ((short)uVar2 != 0)) {
      *(undefined4 *)(param_4 + 0x21c8) = 5;
    }
    if ((uVar2 >> 0x10 & 0x180) != 0) {
      puVar5 = puVar5 + 1;
      *(undefined4 *)(param_4 + 0x21c8) = 4;
    }
  }
  if (0 < param_3) {
    uVar2 = *puVar5;
    puVar4 = puVar5 + 1;
    if ((uVar2 & 0x400000) != 0) {
      puVar4 = puVar5 + 2;
    }
    puVar5 = puVar4;
    if ((uVar2 & 0x1800000) != 0) {
      puVar5 = puVar4 + 1;
    }
    ((int (*)())FUN_000c5df4)();
  }
  if (1 < param_3) {
    uVar2 = *puVar5;
    puVar4 = puVar5 + 1;
    if ((uVar2 & 0x400000) != 0) {
      puVar4 = puVar5 + 2;
    }
    puVar5 = puVar4;
    if ((uVar2 & 0x1800000) != 0) {
      puVar5 = puVar4 + 1;
    }
    ((int (*)())FUN_000c5df4)();
  }
  if (2 < param_3) {
    uVar2 = *puVar5;
    puVar4 = puVar5 + 1;
    if ((uVar2 & 0x400000) != 0) {
      puVar4 = puVar5 + 2;
    }
    puVar5 = puVar4;
    if ((uVar2 & 0x1800000) != 0) {
      puVar5 = puVar4 + 1;
    }
    ((int (*)())FUN_000c5df4)();
  }
  return puVar5;
}

/* FUN_000c607d @ 0xc607d (890 bytes) */
int FUN_000c607d(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  int *param_2;
  int param_3;
  int param_4;
  int param_5;
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  byte bVar3;
  undefined2 uVar5;
  uint uVar4;
  uint *puVar6;
  uint *local_3c;
  uint *local_38;
  uint *local_34;
  uint *local_30;
  uint local_24;
  uint local_20;
  uint local_1c;
  
  puVar1 = (undefined4 *)*param_1;
  puVar2 = (undefined4 *)*param_2;
  *puVar1 = *puVar2;
  local_3c = puVar1 + 1;
  local_38 = puVar2 + 1;
  if (param_3 != 0) {
    uVar4 = puVar2[1];
    local_38 = puVar2 + 2;
    bVar3 = (byte)(uVar4 >> 0x10) & 0x3f;
    uVar5 = (undefined2)(uVar4 >> 0x10);
    if (bVar3 == 0x17) {
      *(undefined4 *)(param_5 + 0x21f0 + (uVar4 & 0xffff) * 4) = 1;
      uVar4 = CONCAT22(uVar5,*(undefined2 *)(param_5 + 0x21e0 + (uVar4 & 0xffff) * 4)) & 0xffc0ffff
              | 0x40000;
    }
    else if (bVar3 == 0x10) {
      uVar4 = CONCAT22(uVar5,*(undefined2 *)(param_5 + 0x2208)) & 0xffc0ffff | 0x40000;
    }
    else if (bVar3 == 0xe) {
      if (*(int *)(param_5 + 0x2234) == 0) {
        uVar4 = CONCAT22(uVar5,*(undefined2 *)(param_5 + 0x2200)) & 0xffc0ffff | 0x40000;
      }
    }
    else if (bVar3 == 0xd) {
      if ((*(int *)(param_5 + 0x2234) == 0) && (*(int *)(param_5 + 0x2324) != 0)) {
        uVar4 = CONCAT22(uVar5,*(undefined2 *)(param_5 + 9000)) & 0xffc0ffff | 0x40000;
      }
    }
    else if (bVar3 == 0xf) {
      uVar4 = CONCAT22(uVar5,*(undefined2 *)(param_5 + 0x232c + (uVar4 & 0xffff) * 4));
    }
    *(uint *)(param_5 + 0x2318) = uVar4;
    *local_3c = uVar4;
    local_3c = puVar1 + 2;
    if ((uVar4 & 0x400000) != 0) {
      puVar1[2] = *local_38;
      local_3c = puVar1 + 3;
      local_38 = puVar2 + 3;
    }
  }
  local_30 = local_3c;
  if (0 < param_4) {
    uVar4 = *local_38;
    puVar6 = local_38 + 1;
    if ((uVar4 & 0x400000) == 0) {
      ((int (*)())FUN_000c5dad)();
      *local_3c = uVar4;
      if ((uVar4 & 0x400000) == 0) goto LAB_000c615c;
LAB_000c62b8:
      local_3c[1] = local_24;
      local_30 = local_3c + 2;
    }
    else {
      local_24 = local_38[1];
      puVar6 = local_38 + 2;
      ((int (*)())FUN_000c5dad)();
      *local_3c = uVar4;
      if ((uVar4 & 0x400000) != 0) goto LAB_000c62b8;
LAB_000c615c:
      local_30 = local_3c + 1;
    }
    local_38 = puVar6;
    if ((uVar4 & 0x1800000) != 0) {
      *local_30 = *puVar6;
      local_30 = local_30 + 1;
      local_38 = puVar6 + 1;
    }
  }
  if (param_4 < 2) goto joined_r0x000c6233;
  uVar4 = *local_38;
  local_34 = local_38 + 1;
  if ((uVar4 & 0x400000) == 0) {
    ((int (*)())FUN_000c5dad)();
    *local_30 = uVar4;
    if ((uVar4 & 0x400000) == 0) goto LAB_000c61aa;
LAB_000c624e:
    local_30[1] = local_20;
    local_30 = local_30 + 2;
    local_38 = local_34;
  }
  else {
    local_20 = local_38[1];
    local_34 = local_38 + 2;
    ((int (*)())FUN_000c5dad)();
    *local_30 = uVar4;
    if ((uVar4 & 0x400000) != 0) goto LAB_000c624e;
LAB_000c61aa:
    local_30 = local_30 + 1;
    local_38 = local_34;
  }
  if ((uVar4 & 0x1800000) != 0) {
    *local_30 = *local_38;
    local_30 = local_30 + 1;
    local_38 = local_38 + 1;
  }
joined_r0x000c6233:
  if (param_4 < 3) {
    *param_1 = (int)local_30;
    *param_2 = (int)local_38;
    return local_38;
  }
  uVar4 = *local_38;
  puVar6 = local_38 + 1;
  if ((uVar4 & 0x400000) == 0) {
    ((int (*)())FUN_000c5dad)();
    *local_30 = uVar4;
  }
  else {
    local_1c = local_38[1];
    puVar6 = local_38 + 2;
    ((int (*)())FUN_000c5dad)();
    *local_30 = uVar4;
  }
  if ((uVar4 & 0x400000) == 0) {
    local_30 = local_30 + 1;
  }
  else {
    local_30[1] = local_1c;
    local_30 = local_30 + 2;
  }
  if ((uVar4 & 0x1800000) != 0) {
    *local_30 = *puVar6;
    local_30 = local_30 + 1;
    puVar6 = puVar6 + 1;
  }
  *param_1 = (int)local_30;
  *param_2 = (int)puVar6;
  return puVar6;
}

/* FUN_000c63f7 @ 0xc63f7 (92 bytes) */
int FUN_000c63f7(param_1, param_2)
  undefined4 *param_1;
  undefined4 *param_2;
{
  undefined4 *puVar1;
  
  puVar1 = _malloc(0x28);
  puVar1[9] = *param_1;
  *param_1 = puVar1;
  *puVar1 = *param_2;
  puVar1[1] = param_2[1];
  puVar1[2] = param_2[2];
  puVar1[3] = param_2[3];
  puVar1[4] = param_2[4];
  puVar1[5] = param_2[5];
  puVar1[6] = param_2[6];
  puVar1[7] = param_2[7];
  puVar1[8] = param_2[8];
  return;
}

/* FUN_000c6453 @ 0xc6453 (39 bytes) */
int FUN_000c6453(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 in_XMM0_Da;
  undefined4 in_XMM1_Da;
  undefined4 in_XMM2_Da;
  undefined4 in_XMM3_Da;
  
  param_1 = param_2 * 0x10 + param_1;
  *(undefined4 *)(param_1 + 0x90) = in_XMM0_Da;
  *(undefined4 *)(param_1 + 0x94) = in_XMM1_Da;
  *(undefined4 *)(param_1 + 0x98) = in_XMM2_Da;
  *(undefined4 *)(param_1 + 0x9c) = in_XMM3_Da;
  return;
}

/* FUN_000c647a @ 0xc647a (8556 bytes) */
int FUN_000c647a(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  undefined4 *param_3;
{
  char cVar1;
  bool bVar2;
  byte bVar3;
  byte bVar4;
  void *pvVar5;
  int iVar6;
  void *pvVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  int iVar11;
  int iVar12;
  undefined1 *puVar13;
  undefined4 *puVar14;
  uint uVar15;
  uint *puVar16;
  uint *puVar17;
  uint uVar18;
  uint *puVar19;
  char *pcVar20;
  uint uVar21;
  int *piVar22;
  undefined4 *local_2c54;
  undefined4 *local_2c50;
  int local_2c40;
  undefined4 *local_2c3c;
  undefined1 *local_2c38;
  undefined4 *local_2c34;
  undefined4 *local_2c30;
  undefined4 *local_2c2c;
  uint local_2c08;
  uint local_2c04;
  uint local_2c00;
  uint local_2bf4;
  undefined4 *local_2bdc;
  uint local_2bd8;
  int local_2bc8;
  int local_2bc0;
  uint local_2bbc;
  undefined4 local_2bb8;
  uint local_2bb4;
  uint local_2bb0;
  byte local_2bac;
  uint local_2ba8;
  uint local_2ba4;
  undefined4 local_2ba0;
  byte local_2b9c;
  int local_2b8c;
  int local_2b88;
  int local_2b84;
  int local_2b80;
  uint local_2b6c;
  uint local_2b68;
  uint local_2b64;
  int local_2b60;
  uint local_2b5c [7];
  undefined4 local_2b40;
  undefined4 local_2b3c;
  undefined4 local_2b38;
  undefined4 local_2b34;
  undefined4 local_2b30 [4];
  undefined4 local_2b20;
  undefined4 local_2b1c;
  undefined4 local_2b18;
  undefined4 local_2b14;
  int local_2b10;
  uint local_2b0c;
  undefined4 local_2af8;
  uint local_2aec;
  uint local_2ae8;
  int aiStack_2a64 [32];
  uint local_29e4;
  uint auStack_29d4 [6];
  undefined1 auStack_29bc [8];
  float afStack_29b4 [1024];
  undefined4 auStack_19b4 [8];
  int aiStack_1994 [1024];
  int local_994;
  int local_98c;
  int local_96c [5];
  uint local_958;
  int local_950;
  uint local_94c;
  int local_948;
  int local_944;
  int local_940;
  int local_93c;
  undefined4 local_938;
  undefined4 local_934;
  undefined4 local_930;
  undefined4 local_92c;
  int local_928;
  undefined4 auStack_924 [16];
  undefined4 auStack_8e4 [16];
  int aiStack_8a4 [17];
  int local_860;
  uint local_84c;
  uint local_848;
  undefined4 local_840;
  int local_83c;
  uint local_838;
  undefined4 local_7f0;
  undefined1 local_7ec [72];
  undefined4 local_7a4;
  undefined4 local_7a0;
  uint local_798;
  uint local_794;
  void *local_78c;
  void *local_788;
  undefined4 local_6e8;
  undefined1 local_6e4;
  undefined1 local_6e3 [3];
  byte local_6e0 [764];
  int local_3e4;
  char local_3e0 [576];
  undefined4 local_1a0;
  undefined4 *local_19c;
  int *local_198;
  uint local_190;
  undefined4 local_18c;
  uint local_17c;
  undefined1 local_178 [76];
  undefined4 *local_12c;
  int local_128;
  undefined4 auStack_120 [8];
  undefined4 auStack_100 [16];
  void *local_c0 [9];
  void *local_9c [8];
  uint local_7c;
  uint local_78;
  uint local_74;
  uint local_70;
  uint local_6c;
  uint local_68;
  uint local_54;
  uint local_48;
  uint local_44;
  uint local_3c;
  uint local_38;
  uint local_30;
  uint local_2c;
  uint *local_24;
  uint *local_20;
  
  iVar11 = 1;
  do {
    local_c0[iVar11] = (void *)0xffffffff;
    local_c0[iVar11 + 8] = (void *)0xffffffff;
    iVar11 = iVar11 + 1;
  } while (iVar11 != 9);
  pvVar5 = _malloc(0x400);
  local_98c = 0;
  bVar4 = *(byte *)(param_1 + 0x46);
  if ((bVar4 & 4) == 0) {
    local_958 = (uint)(*(byte *)(param_1 + 0x44) >> 7);
    local_94c = 0xffff;
  }
  else {
    local_958 = bVar4 >> 4 & 1;
    if ((bVar4 >> 4 & 1) == 0) {
      local_94c = 0xffff;
    }
    else {
      local_94c = (uint)*(byte *)(param_1 + 0x11d1);
    }
  }
  local_928 = 0;
  local_860 = 0;
  local_840 = 0;
  local_838 = (uint)(param_2[6] == 0);
  local_7f0 = 0;
  local_84c = bVar4 >> 5 & 1;
  local_848 = (uint)*(byte *)(param_1 + 0x11d2);
  iVar11 = param_2[1];
  puVar10 = (undefined4 *)*param_2;
  local_2b5c[0] = 0;
  local_2b5c[1] = 0xffff;
  local_2b10 = 0;
  local_2af8 = 0;
  local_2b34 = local_c0[8];
  local_2b38 = local_c0[7];
  local_2b3c = local_c0[6];
  local_2b40 = local_c0[5];
  local_2b5c[6] = (uint)local_c0[4];
  local_2b5c[5] = (uint)local_c0[3];
  local_2b5c[4] = (uint)local_c0[2];
  local_2b5c[3] = (uint)local_c0[1];
  local_2b14 = local_9c[7];
  local_2b18 = local_9c[6];
  local_2b1c = local_9c[5];
  local_2b20 = local_9c[4];
  local_2b30[3] = local_9c[3];
  local_2b30[2] = local_9c[2];
  local_2b30[1] = local_9c[1];
  local_2b30[0] = local_9c[0];
  local_2b5c[2] = 0;
  local_29e4 = 0;
  local_994 = 0;
  local_96c[0] = 0;
  local_96c[1] = 0;
  local_96c[2] = 0;
  local_96c[3] = 0;
  local_948 = 0;
  local_944 = 0;
  local_940 = 0;
  local_93c = 0;
  local_950 = 0;
  local_938 = 0;
  local_934 = 0;
  local_930 = 0;
  local_92c = 0;
  iVar12 = 0;
  iVar6 = 0;
  do {
    *(undefined4 *)(iVar6 + 0x188 + (int)local_2b5c) = 0;
    *(undefined4 *)(iVar6 + 0x11a8 + (int)local_2b5c) = 0;
    iVar12 = iVar12 + 1;
    iVar6 = iVar6 + 4;
  } while (iVar12 != 8);
  iVar12 = 0;
  iVar6 = 0;
  do {
    *(undefined4 *)(iVar6 + 0x2238 + (int)local_2b5c) = 0;
    *(undefined4 *)(iVar6 + 0x2278 + (int)local_2b5c) = 0;
    iVar12 = iVar12 + 1;
    iVar6 = iVar6 + 4;
  } while (iVar12 != 0x10);
  local_24 = puVar10 + 2;
  local_2bc8 = 0;
  local_2bc0 = 0;
  local_2bbc = 0;
  puVar19 = puVar10 + 2;
switchD_000c67ba_caseD_18:
  puVar17 = puVar19;
  if (puVar17 < puVar10 + iVar11) goto code_r0x000c6799;
  if (local_994 != 0) {
    local_2bdc = (undefined4 *)0x0;
    local_2bd8 = 0;
    goto LAB_000c6d3c;
  }
  local_2b0c = local_2b5c[0];
  iVar6 = (local_2bc8 + iVar11) * 4;
  if (local_2b10 != 0) {
    iVar6 = iVar6 + 0x48;
  }
  uVar15 = iVar6 + local_2bc0 * 4;
  if (local_98c != 0) {
    uVar15 = uVar15 + 0x14;
  }
  uVar21 = uVar15;
  if ((local_96c[0] != 0) && (uVar21 = uVar15 + 0xc, local_98c != 0)) {
    uVar21 = uVar15 + 0x24;
  }
  uVar15 = uVar21;
  if ((local_96c[1] != 0) && (uVar15 = uVar21 + 0xc, local_98c != 0)) {
    uVar15 = uVar21 + 0x24;
  }
  uVar21 = uVar15;
  if ((local_96c[2] != 0) && (uVar21 = uVar15 + 0xc, local_98c != 0)) {
    uVar21 = uVar15 + 0x24;
  }
  local_2b6c = uVar21;
  if ((local_96c[3] != 0) && (local_2b6c = uVar21 + 0xc, local_98c != 0)) {
    local_2b6c = uVar21 + 0x24;
  }
  if (((local_950 != 0) && (local_958 != 0)) && (local_928 == 0)) {
    local_2b6c = local_2b6c + 0x14;
  }
  if (local_860 == 1) {
    local_2b6c = local_2b6c + 0x24;
  }
  else if (local_860 == 2) {
    local_2b6c = local_2b6c + 0x30;
  }
  else if (local_860 == 3) {
    local_2b6c = local_2b6c + 0x40;
  }
  else if (local_860 == 0) goto LAB_000c6aa7;
  local_2b6c = local_2b6c + 8;
  iVar6 = 0;
  piVar22 = local_96c;
  do {
    if (*piVar22 != 0) {
      local_2b6c = local_2b6c + 0x2c;
    }
    iVar6 = iVar6 + 1;
    piVar22 = piVar22 + 1;
  } while (iVar6 != 4);
LAB_000c6aa7:
  if (((local_944 != 0) || (local_93c != 0)) || (local_928 == 0)) {
    uVar15 = local_2b6c;
    if ((local_948 == 0) && (local_940 != 0)) {
      uVar15 = local_2b6c + 0xc;
    }
    local_2b6c = uVar15;
    if ((local_928 == 0) && (local_2b6c = uVar15 + 0xc, local_84c != 0)) {
      local_2b6c = uVar15 + 0x18;
    }
  }
  local_2bdc = _malloc(local_2b6c + 0x10);
  *local_2bdc = *puVar10;
  local_2bdc[1] = puVar10[1];
  local_20 = local_2bdc + 2;
  local_24 = puVar10 + 2;
  bVar2 = true;
  puVar19 = local_24;
switchD_000c6b91_caseD_18:
  puVar16 = puVar19;
  puVar17 = local_20;
  if (puVar10 + iVar11 <= puVar16) {
    local_2b5c[2] = local_2b5c[2] | local_2bbc;
    local_2bd8 = local_2b6c >> 2;
LAB_000c6d3c:
    iVar11 = local_994;
    if (local_994 == 0) {
      param_3[0x1587] = 0;
      param_3[0x1502] = 0;
      param_3[0x1589] = 0;
      local_2b60 = 0;
      local_2b80 = 0;
      local_2c2c = param_3 + 0x1002;
      local_2c34 = param_3 + 0x1001;
      local_2c38 = auStack_29bc;
      local_2c3c = param_3 + 0x1000;
      local_2c40 = 0x180;
      local_2c30 = local_2c34;
      do {
        local_2c54 = local_2c3c + 1;
        local_2c50 = (undefined4 *)(local_2c38 + 8);
        puVar10 = local_2c34 + 1;
        iVar11 = 0;
        uVar15 = *(uint *)((int)local_2b5c + local_2c40 + 8);
        do {
          while ((uVar15 & 1 << ((byte)iVar11 & 0x1f)) == 0) {
            *(undefined1 *)(local_2c54 + 4) = 0;
            iVar11 = iVar11 + 1;
            local_2c54 = local_2c54 + 5;
            local_2c50 = local_2c50 + 4;
            puVar10 = puVar10 + 5;
            if (iVar11 == 0x20) goto LAB_000c6eb4;
          }
          *(undefined4 *)((int)puVar10 + ((int)local_2c30 - (int)local_2c2c)) = *local_2c50;
          *puVar10 = local_2c50[1];
          puVar10[1] = local_2c50[2];
          puVar10[2] = local_2c50[3];
          *(undefined1 *)(puVar10 + 3) = 1;
          if ((uint)param_3[0x1502] < (uint)(local_2b80 + iVar11)) {
            param_3[0x1502] = local_2b80 + iVar11;
          }
          iVar11 = iVar11 + 1;
          local_2c54 = local_2c54 + 5;
          local_2c50 = local_2c50 + 4;
          puVar10 = puVar10 + 5;
        } while (iVar11 != 0x20);
LAB_000c6eb4:
        local_2b60 = local_2b60 + 1;
        local_2c40 = local_2c40 + 4;
        local_2b80 = local_2b80 + 0x20;
        local_2c3c = local_2c3c + 0xa0;
        local_2c38 = local_2c38 + 0x200;
        local_2c34 = local_2c34 + 0xa0;
        local_2c30 = local_2c30 + 0xa0;
        local_2c2c = local_2c2c + 0xa0;
      } while (local_2b60 != 8);
      if ((int)param_3[0x1587] < (int)param_3[0x1502]) {
        param_3[0x1587] = param_3[0x1502];
      }
      _memset(local_178,0,0xbc);
      _memset(local_7ec,0,0x674);
      pvVar7 = (void *)(**(code **)(param_1 + 0xc))(*(undefined4 *)(param_1 + 0x1870));
      local_12c = local_2bdc;
      local_128 = local_2bd8 << 2;
      iVar11 = 0;
      iVar6 = 0;
      local_c0[0] = pvVar7;
      do {
        *(undefined4 *)(local_178 + iVar6 + 0x58) = *(undefined4 *)(iVar6 + 0xc + (int)local_2b5c);
        *(undefined4 *)(local_178 + iVar6 + 0x78) = *(undefined4 *)(iVar6 + 0x2c + (int)local_2b5c);
        iVar11 = iVar11 + 1;
        iVar6 = iVar6 + 4;
      } while (iVar11 != 8);
      local_1a0 = 0x400;
      local_19c = _malloc(0x40000);
      local_198 = _malloc(0x40000);
      local_7a0 = 0x40;
      local_788 = _malloc(0x900);
      local_7a4 = 0x40;
      local_78c = _malloc(0x900);
      iVar11 = 0;
      puVar13 = local_6e3;
      do {
        *puVar13 = (char)iVar11;
        iVar11 = iVar11 + 1;
        puVar13 = puVar13 + 0xc;
      } while (iVar11 != 0x40);
      if (*(int *)(param_1 + 0x186c) == 0) {
        ((int (*)())FUN_000c4bdb)(param_1,1);
      }
      iVar11 = ((int (*)())FUN_000cb0bc)(*(undefined4 *)(param_1 + 0x186c),local_178,local_7ec);
      if (iVar11 == 0) {
        param_3[0x1000] = local_190;
        if (local_190 != 0) {
          uVar15 = 0;
          puVar10 = local_19c;
          puVar14 = param_3;
          do {
            *puVar14 = *puVar10;
            puVar14[1] = puVar10[1];
            puVar14[2] = puVar10[2];
            puVar14[3] = puVar10[3];
            puVar10 = puVar10 + 4;
            uVar15 = uVar15 + 1;
            puVar14 = puVar14 + 4;
          } while (uVar15 < local_190);
        }
        if ((uint)param_3[0x1502] < local_17c) {
          param_3[0x1502] = local_17c;
          param_3[0x1501] = local_17c + 1;
        }
        else {
          param_3[0x1501] = param_3[0x1502] + 1;
        }
        if (0xff < (uint)param_3[0x1502]) {
          param_3[0x1502] = 0xff;
        }
        if (0x100 < (uint)param_3[0x1501]) {
          param_3[0x1501] = 0x100;
        }
        if (local_794 != 0) {
          local_2b68 = 0;
          local_2b84 = 0;
          do {
            piVar22 = (int *)(local_2b84 + (int)local_788);
            if (piVar22[2] == 0x16) {
              iVar11 = piVar22[4];
              iVar6 = *piVar22;
              iVar12 = iVar11;
              if (iVar11 < 0) {
                iVar12 = iVar11 + 0x1f;
              }
              if ((auStack_29d4[iVar12 >> 5] & 1 << ((byte)iVar11 & 0x1f)) == 0) {
                ((int (*)())FUN_000c63f7)(param_3 + 0x1589,piVar22);
              }
              else {
                iVar12 = ((int (*)())FUN_000c4de4)();
                iVar8 = ((int (*)())FUN_000c4de4)();
                aiStack_1994[iVar12 + iVar6 * 4] = (int)afStack_29b4[iVar8 + iVar11 * 4];
              }
            }
            else if (piVar22[2] == 0x18) {
              ((int (*)())FUN_000c63f7)(param_3 + 0x1589,piVar22);
            }
            local_2b68 = local_2b68 + 1;
            local_2b84 = local_2b84 + 0x24;
          } while (local_2b68 < local_794);
        }
        if (local_798 != 0) {
          local_2b64 = 0;
          local_2b88 = 0;
          do {
            puVar19 = (uint *)(local_2b88 + (int)local_78c);
            if (puVar19[2] == 1) {
              uVar15 = *puVar19;
              iVar11 = ((int (*)())FUN_000c4de4)();
              param_3[uVar15 * 5 + iVar11 + 0x1001] = puVar19[5];
              *(undefined1 *)(param_3 + uVar15 * 5 + 0x1005) = 1;
              if ((uint)param_3[0x1502] < uVar15) {
                param_3[0x1502] = uVar15;
              }
            }
            local_2b64 = local_2b64 + 1;
            local_2b88 = local_2b88 + 0x24;
          } while (local_2b64 < local_798);
        }
        param_3[0x1505] = local_18c;
        param_3[0x1503] = local_6e8;
        param_3[0x1504] = local_3e4;
        param_3[0x1506] = 0;
        *(undefined1 *)(param_3 + 0x1507) = 0;
        param_3[0x151d] = 0;
        param_3[0x151e] = 0;
        param_3[0x1588] = 0;
        if (local_3e4 == 0) {
          bVar4 = *(byte *)(param_3 + 0x151d);
        }
        else {
          uVar15 = 0;
          pcVar20 = local_3e0;
          bVar4 = *(byte *)(param_3 + 0x151d);
          do {
            cVar1 = *pcVar20;
            if (cVar1 == '\x01') {
              *(byte *)((int)param_3 + 0x5476) = *(byte *)((int)param_3 + 0x5476) | 1;
            }
            else if (cVar1 == '\0') {
              *(undefined1 *)(param_3 + 0x1507) = 1;
              bVar4 = bVar4 | 1;
              *(byte *)(param_3 + 0x151d) = bVar4;
            }
            else if (cVar1 == '\x02') {
              cVar1 = pcVar20[1];
              if (cVar1 == '\x01') {
                bVar4 = bVar4 | 4;
                *(byte *)(param_3 + 0x151d) = bVar4;
              }
              else if (cVar1 == '\0') {
                bVar4 = bVar4 | 2;
                *(byte *)(param_3 + 0x151d) = bVar4;
              }
              else if (cVar1 == '\x02') {
                bVar4 = bVar4 | 8;
                *(byte *)(param_3 + 0x151d) = bVar4;
              }
              else if (cVar1 == '\x03') {
                bVar4 = bVar4 | 0x10;
                *(byte *)(param_3 + 0x151d) = bVar4;
              }
            }
            else if (cVar1 == '\x05') {
              uVar21 = 4 << (pcVar20[1] * '\x03' & 0x1fU);
              param_3[0x151e] = param_3[0x151e] | uVar21;
              param_3[0x1588] = param_3[0x1588] | uVar21;
            }
            uVar15 = uVar15 + 1;
            pcVar20 = pcVar20 + 0xc;
          } while (uVar15 < (uint)param_3[0x1504]);
        }
        if ((bVar4 & 0x18) != 0) {
          *(byte *)(param_3 + 0x151d) = bVar4 | 0x1c;
        }
        iVar11 = 0x16;
        puVar10 = param_3;
        do {
          puVar10[0x1571] = 0x16;
          puVar10 = puVar10 + 1;
          iVar11 = iVar11 + -1;
        } while (iVar11 != 0);
        uVar15 = param_3[0x1503];
        if (uVar15 != 0) {
          uVar21 = 0;
          puVar13 = &local_6e4;
          do {
            param_3[(byte)puVar13[1] + 0x1571] =
                 (uint)(byte)puVar13[(int)(local_6e0 + -(int)&local_6e4)];
            uVar21 = uVar21 + 1;
            puVar13 = puVar13 + 0xc;
          } while (uVar21 < uVar15);
        }
        if (uVar15 < 2) {
          if (uVar15 == 0) {
            param_3[0x1571] = 0;
            param_3[0x1572] = 1;
          }
          else {
            param_3[0x1572] = (uint)(param_3[0x1571] == 0);
          }
        }
        iVar11 = *local_198;
        param_3[0x151f] = (uint)(iVar11 != 0);
        param_3[0x1520] = 0;
        if (((iVar11 != 0) != 0) && (iVar11 = *local_198, 0 < iVar11)) {
          iVar6 = 0;
          local_2b8c = 0;
          puVar10 = param_3;
          do {
            puVar10[0x1531] = 0;
            puVar10[0x1541] = 0;
            puVar10[0x1551] = 0;
            if (*(int *)((int)local_198 + local_2b8c + 0xc) == 0x3e) {
              param_3[0x1520] = param_3[0x1520] | 2 << ((char)iVar6 * '\x02' & 0x1fU);
              *(char *)(param_3 + iVar6 + 0x1551) =
                   (char)aiStack_1994[*(int *)((int)local_198 + local_2b8c + 0x10) * 4 + 1];
              *(char *)((int)param_3 + iVar6 * 4 + 0x5545) =
                   (char)aiStack_1994[*(int *)((int)local_198 + local_2b8c + 0x10) * 4 + 2];
              *(short *)(param_3 + iVar6 + 0x1531) =
                   (short)*(undefined4 *)((int)local_198 + local_2b8c + 0x14);
              *(short *)((int)param_3 + iVar6 * 4 + 0x54c6) =
                   (short)aiStack_1994[*(int *)((int)local_198 + local_2b8c + 0x10) * 4];
              *(short *)(param_3 + iVar6 + 0x1541) =
                   (short)*(undefined4 *)((int)local_198 + local_2b8c + 0x1c);
              *(short *)((int)param_3 + iVar6 * 4 + 0x5506) =
                   *(short *)((int)local_198 + local_2b8c + 0x14) + 1;
              param_3[*(int *)((int)local_198 + local_2b8c + 0x10) + 0x1561] = iVar6;
            }
            iVar6 = iVar6 + 1;
            local_2b8c = local_2b8c + 0x1c;
            puVar10 = puVar10 + 1;
          } while (iVar11 != iVar6);
        }
        if (local_19c != (undefined4 *)0x0) {
          _free(local_19c);
        }
        if (pvVar5 != (void *)0x0) {
          _free(pvVar5);
        }
        if (local_198 != (int *)0x0) {
          _free(local_198);
        }
        if (local_2bdc != (undefined4 *)0x0) {
          _free(local_2bdc);
        }
        if (pvVar7 != (void *)0x0) {
          _free(pvVar7);
        }
        if (local_788 != (void *)0x0) {
          _free(local_788);
        }
        iVar11 = 0;
        if (local_78c != (void *)0x0) {
          _free(local_78c);
          iVar11 = 0;
        }
      }
      else {
        iVar11 = 2;
      }
    }
    return iVar11;
  }
  uVar15 = *puVar16;
  puVar19 = puVar16;
  switch(uVar15 & 0xffff) {
  default:
    goto switchD_000c67ba_caseD_0;
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
    if (bVar2) {
      local_20 = (uint *)((int (*)())FUN_000c5876)();
      bVar2 = false;
    }
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
    if (bVar2) {
      local_20 = (uint *)((int (*)())FUN_000c5876)();
      bVar2 = false;
    }
    local_24 = (uint *)((int (*)())FUN_000c607d)(2,local_2b5c);
    puVar19 = local_24;
    goto switchD_000c6b91_caseD_18;
  case 6:
  case 0x10:
  case 0x27:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x4b:
  case 0x53:
    *local_20 = uVar15;
    local_20 = local_20 + 1;
    local_24 = puVar16 + 1;
    puVar19 = local_24;
    goto switchD_000c6b91_caseD_18;
  case 7:
  case 0x11:
    goto LAB_000c7817;
  case 8:
  case 0x15:
  case 0x16:
  case 0x32:
    *local_20 = uVar15;
    local_20[1] = puVar16[1];
    local_20 = local_20 + 2;
    local_24 = puVar16 + 2;
    puVar19 = local_24;
    goto switchD_000c6b91_caseD_18;
  case 9:
  case 0x14:
  case 0x1d:
    *local_20 = uVar15;
    local_20[1] = puVar16[1];
    local_20[2] = puVar16[2];
    local_20 = local_20 + 3;
    local_24 = puVar16 + 3;
    puVar19 = local_24;
    goto switchD_000c6b91_caseD_18;
  case 10:
  case 0xd:
  case 0x21:
  case 0x2f:
  case 0x3f:
  case 0x40:
  case 100:
    if (bVar2) {
      local_20 = (uint *)((int (*)())FUN_000c5876)();
      bVar2 = false;
    }
    local_24 = (uint *)((int (*)())FUN_000c607d)(3,local_2b5c);
    puVar19 = local_24;
    goto switchD_000c6b91_caseD_18;
  case 0xf:
    *local_20 = uVar15;
    local_24 = puVar16 + 2;
    local_20[1] = puVar16[1];
    local_20 = local_20 + 2;
    uVar15 = puVar16[1];
    puVar19 = local_24;
    if ((ushort)uVar15 != 0) {
      uVar21 = 0;
      do {
        *local_20 = *local_24;
        local_20 = local_20 + 1;
        local_24 = local_24 + 1;
        uVar21 = uVar21 + 1;
        puVar19 = local_24;
      } while ((ushort)uVar15 != uVar21);
    }
  case 0x18:
    goto switchD_000c6b91_caseD_18;
  case 0x19:
    local_24 = puVar16 + 1;
    if ((uVar15 >> 0x18 & 0x18) == 0) {
      if (aiStack_8a4[uVar15 >> 0x10 & 0xff] == 2) {
        uVar15 = uVar15 & 0xe7ffffff | 0x10000000;
      }
      else {
        uVar15 = uVar15 & 0xe7ffffff | 0x8000000;
      }
    }
    goto LAB_000c7e50;
  case 0x1a:
    local_24 = puVar16 + 1;
    *local_20 = uVar15;
    puVar19 = local_20 + 1;
    if ((int)uVar15 < 0) {
      uVar15 = *local_24;
      local_24 = puVar16 + 2;
      local_20[1] = uVar15;
      puVar19 = local_20 + 2;
    }
    local_20 = puVar19;
    uVar15 = *local_24;
    local_24 = local_24 + 1;
LAB_000c7e50:
    *local_20 = uVar15;
    local_20 = local_20 + 1;
    puVar19 = local_24;
    goto switchD_000c6b91_caseD_18;
  case 0x1c:
    *local_20 = uVar15;
    local_20 = local_20 + 1;
    local_24 = puVar16 + 1;
    puVar19 = local_24;
    if ((puVar16[1] >> 0x10 & 0x3f) - 1 < 2) {
      puVar17[1] = puVar16[1];
      puVar17[2] = puVar16[2];
      puVar17[3] = puVar16[3];
      puVar17[4] = puVar16[4];
      puVar17[5] = puVar16[5];
      local_20 = puVar17 + 6;
      local_24 = puVar16 + 6;
      puVar19 = local_24;
    }
    goto switchD_000c6b91_caseD_18;
  case 0x28:
    local_24 = puVar16 + 1;
    puVar19 = (uint *)((int (*)())FUN_000c5345)();
    *puVar19 = uVar15;
    local_20 = puVar19 + 1;
    puVar19 = local_24;
    goto switchD_000c6b91_caseD_18;
  case 0x34:
LAB_000c7817:
    local_24 = (uint *)((int (*)())FUN_000c607d)(2,local_2b5c);
    puVar19 = local_24;
    goto switchD_000c6b91_caseD_18;
  case 0x35:
    *local_20 = uVar15;
    local_20 = local_20 + 1;
    local_54 = puVar16[1];
    local_24 = puVar16 + 2;
    ((int (*)())FUN_000c5dad)();
    *local_20 = local_54;
    local_20 = local_20 + 1;
    puVar19 = local_24;
    goto switchD_000c6b91_caseD_18;
  case 0x37:
  case 0x3e:
    local_24 = (uint *)((int (*)())FUN_000c607d)(1,local_2b5c);
    puVar19 = local_24;
    goto switchD_000c6b91_caseD_18;
  case 0x3b:
    break;
  case 0x5d:
    if (bVar2) {
      local_20 = (uint *)((int (*)())FUN_000c5876)();
      bVar2 = false;
      puVar16 = local_24;
    }
    uVar15 = *puVar16;
    puVar19 = puVar16 + 1;
    uVar21 = uVar15 >> 0x10 & 0xff;
    if ((uVar15 & 0x80000000) == 0) {
      local_2bb4 = 0;
    }
    else {
      local_2bb4 = puVar16[1];
      puVar19 = puVar16 + 2;
    }
    if ((uVar15 & 0x40000000) == 0) {
      local_2bb0 = 0;
    }
    else {
      local_2bb0 = *puVar19;
      puVar19 = puVar19 + 1;
    }
    local_3c = *puVar19;
    puVar17 = puVar19 + 1;
    if ((local_3c & 0x400000) != 0) {
      local_2c04 = puVar19[1];
      puVar17 = puVar19 + 2;
    }
    local_6c = *puVar17;
    local_24 = puVar17 + 1;
    if ((local_6c & 0x400000) != 0) {
      local_48 = puVar17[1];
      local_24 = puVar17 + 2;
    }
    bVar4 = (byte)(uVar15 >> 0x18) & 0xc;
    local_2bac = (byte)(uVar15 >> 0x10);
    if (bVar4 == 4) {
LAB_000c873e:
      if (local_2aec << (local_2bac & 0x1f) == 0) {
        uVar18 = 1 << (local_2bac & 0x1f);
        goto LAB_000c79b5;
      }
      local_20 = (uint *)((int (*)())FUN_000c4fd8)(uVar21,local_20);
      if ((local_3c & 0x400000) == 0) {
        uVar18 = 1 << (local_2bac & 0x1f);
        local_2bb8 = 0;
      }
      else {
        local_30 = local_2c04;
        local_3c = local_3c & 0xffbfffff;
        uVar18 = 1 << (local_2bac & 0x1f);
        local_2bb8 = 1;
      }
    }
    else {
      if (bVar4 == 8) {
        uVar18 = 1 << (local_2bac & 0x1f);
        if ((local_2ae8 & uVar18) != 0) goto LAB_000c873e;
      }
      else {
        uVar18 = 1 << (local_2bac & 0x1f);
      }
LAB_000c79b5:
      local_2bb8 = 0;
    }
    ((int (*)())FUN_000c5dad)();
    *local_20 = uVar15;
    puVar19 = local_20 + 1;
    if ((uVar15 & 0x80000000) != 0) {
      local_20[1] = local_2bb4;
      puVar19 = local_20 + 2;
    }
    local_20 = puVar19;
    if ((uVar15 & 0x40000000) != 0) {
      *local_20 = local_2bb0;
      local_20 = local_20 + 1;
    }
    *local_20 = local_3c;
    puVar19 = local_20 + 1;
    if ((local_3c & 0x400000) != 0) {
      local_20[1] = local_2c04;
      puVar19 = local_20 + 2;
    }
    local_20 = puVar19;
    puVar19 = local_20;
    *local_20 = local_6c;
    local_20 = local_20 + 1;
    if ((local_6c & 0x400000) != 0) {
      puVar19[1] = local_48;
      local_20 = puVar19 + 2;
    }
    if (((bVar4 == 4) || ((bVar4 == 8 && ((local_2ae8 & uVar18) != 0)))) &&
       (local_2aec << (local_2bac & 0x1f) != 0)) {
      local_20 = (uint *)((int (*)())FUN_000c5121)(&local_30,uVar21,local_2bb8,local_20);
    }
    puVar19 = local_24;
    if ((uVar18 & local_2aec) != 0) {
      *local_20 = 0x47;
      uVar15 = local_2c04;
      uVar18 = local_3c;
      if ((local_3c & 0x400000) == 0) {
        uVar18 = local_3c | 0x400000;
        uVar15 = 0x55;
      }
      if (aiStack_2a64[uVar21] == 0x1906) {
        if (((byte)uVar15 & 3) == 1) {
          uVar15 = uVar15 & 0xfffffffc | 2;
        }
        if (((byte)uVar15 & 0xc) == 4) {
          uVar15 = uVar15 & 0xfffffff3 | 8;
        }
        if (((byte)uVar15 & 0x30) == 0x10) {
          uVar15 = uVar15 & 0xffffffcf | 0x20;
        }
      }
      else if ((aiStack_2a64[uVar21] == 0x1909) && (((byte)uVar15 & 0xc0) == 0x40)) {
        uVar15 = uVar15 | 0xc0;
      }
      goto LAB_000c7af9;
    }
    goto switchD_000c6b91_caseD_18;
  case 0x5e:
    if (bVar2) {
      local_20 = (uint *)((int (*)())FUN_000c5876)();
      bVar2 = false;
      puVar16 = local_24;
    }
    uVar15 = *puVar16;
    puVar19 = puVar16 + 1;
    uVar21 = uVar15 >> 0x10 & 0xff;
    if ((uVar15 & 0x80000000) == 0) {
      local_2ba8 = 0;
    }
    else {
      local_2ba8 = puVar16[1];
      puVar19 = puVar16 + 2;
    }
    if ((uVar15 & 0x40000000) == 0) {
      local_2ba4 = 0;
    }
    else {
      local_2ba4 = *puVar19;
      puVar19 = puVar19 + 1;
    }
    local_3c = *puVar19;
    puVar17 = puVar19 + 1;
    if ((*puVar19 & 0x400000) != 0) {
      local_2c08 = puVar19[1];
      puVar17 = puVar19 + 2;
    }
    local_48 = *puVar17;
    puVar19 = puVar17 + 1;
    if ((*puVar17 & 0x400000) != 0) {
      local_6c = puVar17[1];
      puVar19 = puVar17 + 2;
    }
    local_44 = *puVar19;
    local_24 = puVar19 + 1;
    if ((*puVar19 & 0x400000) != 0) {
      local_68 = puVar19[1];
      local_24 = puVar19 + 2;
    }
    bVar4 = (byte)(uVar15 >> 0x18) & 0xc;
    local_2b9c = (byte)(uVar15 >> 0x10);
    if (bVar4 == 4) {
LAB_000c867f:
      if (local_2aec << (local_2b9c & 0x1f) == 0) {
        uVar18 = 1 << (local_2b9c & 0x1f);
        local_2ba0 = 0;
      }
      else {
        local_20 = (uint *)((int (*)())FUN_000c4fd8)(uVar21,local_20);
        if ((local_3c & 0x400000) == 0) goto LAB_000c7be9;
        local_30 = local_2c08;
        local_3c = local_3c & 0xffbfffff;
        uVar18 = 1 << (local_2b9c & 0x1f);
        local_2ba0 = 1;
      }
    }
    else {
      if (bVar4 == 8) {
        uVar18 = 1 << (local_2b9c & 0x1f);
        if ((local_2ae8 & uVar18) != 0) goto LAB_000c867f;
      }
      else {
LAB_000c7be9:
        uVar18 = 1 << (local_2b9c & 0x1f);
      }
      local_2ba0 = 0;
    }
    *local_20 = uVar15;
    puVar19 = local_20 + 1;
    if ((uVar15 & 0x80000000) != 0) {
      local_20[1] = local_2ba8;
      puVar19 = local_20 + 2;
    }
    local_20 = puVar19;
    if ((uVar15 & 0x40000000) != 0) {
      *local_20 = local_2ba4;
      local_20 = local_20 + 1;
    }
    *local_20 = local_3c;
    puVar19 = local_20 + 1;
    if ((local_3c & 0x400000) != 0) {
      local_20[1] = local_2c08;
      puVar19 = local_20 + 2;
    }
    local_20 = puVar19;
    *local_20 = local_48;
    puVar19 = local_20 + 1;
    if ((local_48 & 0x400000) != 0) {
      local_20[1] = local_6c;
      puVar19 = local_20 + 2;
    }
    local_20 = puVar19;
    puVar19 = local_20;
    *local_20 = local_44;
    local_20 = local_20 + 1;
    if ((local_44 & 0x400000) != 0) {
      puVar19[1] = local_68;
      local_20 = puVar19 + 2;
    }
    if (((bVar4 == 4) || ((bVar4 == 8 && ((local_2ae8 & uVar18) != 0)))) &&
       (local_2aec << (local_2b9c & 0x1f) != 0)) {
      local_20 = (uint *)((int (*)())FUN_000c5121)(&local_30,uVar21,local_2ba0,local_20);
    }
    puVar19 = local_24;
    if ((uVar18 & local_2aec) != 0) {
      *local_20 = 0x47;
      uVar15 = local_2c08;
      uVar18 = local_3c;
      if ((local_3c & 0x400000) == 0) {
        uVar18 = local_3c | 0x400000;
        uVar15 = 0x55;
      }
      if (aiStack_2a64[uVar21] == 0x1906) {
        if (((byte)uVar15 & 3) == 1) {
          uVar15 = uVar15 & 0xfffffffc | 2;
        }
        if (((byte)uVar15 & 0xc) == 4) {
          uVar15 = uVar15 & 0xfffffff3 | 8;
        }
        if (((byte)uVar15 & 0x30) == 0x10) {
          uVar15 = uVar15 & 0xffffffcf | 0x20;
        }
      }
      else if ((aiStack_2a64[uVar21] == 0x1909) && (((byte)uVar15 & 0xc0) == 0x40)) {
        uVar15 = uVar15 | 0xc0;
      }
LAB_000c7af9:
      local_20[1] = uVar18;
      local_20[2] = uVar15;
      local_20[3] = uVar18 & 0x3fffff;
      local_20 = local_20 + 4;
      puVar19 = local_24;
    }
    goto switchD_000c6b91_caseD_18;
  }
  local_24 = (uint *)((int (*)())FUN_000c607d)(1,local_2b5c);
  puVar19 = local_24;
  goto switchD_000c6b91_caseD_18;
code_r0x000c6799:
  uVar15 = *puVar17;
  puVar19 = puVar17;
  switch(uVar15 & 0xffff) {
  default:
    goto switchD_000c67ba_caseD_0;
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
    break;
  case 3:
  case 0xc:
  case 0x13:
  case 0x1f:
  case 0x20:
  case 0x22:
  case 0x23:
  case 0x41:
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x49:
  case 0x4e:
  case 0x52:
  case 0x56:
  case 0x5b:
    break;
  case 6:
  case 0x10:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x4b:
  case 0x53:
    local_24 = puVar17 + 1;
    puVar19 = puVar17 + 1;
    goto switchD_000c67ba_caseD_18;
  case 7:
  case 0x11:
    goto LAB_000c754e;
  case 8:
  case 0x32:
    local_24 = puVar17 + 2;
    puVar19 = puVar17 + 2;
    goto switchD_000c67ba_caseD_18;
  case 9:
  case 0x1d:
    local_24 = puVar17 + 3;
    puVar19 = puVar17 + 3;
    goto switchD_000c67ba_caseD_18;
  case 10:
  case 0xd:
  case 0x21:
  case 0x2f:
  case 0x3f:
  case 0x40:
  case 100:
    break;
  case 0xf:
    local_24 = puVar17 + (ushort)puVar17[1] + 2;
    puVar19 = puVar17 + (ushort)puVar17[1] + 2;
    goto switchD_000c67ba_caseD_18;
  case 0x14:
    local_24 = puVar17 + 3;
    puVar19 = puVar17 + 3;
    goto switchD_000c67ba_caseD_18;
  case 0x15:
    local_24 = puVar17 + 2;
    puVar19 = puVar17 + 2;
    goto switchD_000c67ba_caseD_18;
  case 0x16:
    local_24 = puVar17 + 1;
    bVar4 = (byte)puVar17[1];
    bVar3 = (byte)(puVar17[1] >> 0x10) & 0x3f;
    ((int (*)())FUN_000c5cb6)(0,0);
    if (bVar3 == 0x16) {
      local_2b10 = 1;
    }
    else if (bVar3 == 0x11) {
      local_2b5c[2] = local_2b5c[2] | 1 << (bVar4 & 0x1f);
    }
    else if (bVar3 == 0xf) {
      local_2bbc = local_2bbc | 1 << (bVar4 & 0x1f);
    }
    else {
      uVar9 = 1;
      if (bVar3 != 0x10) {
        uVar9 = local_2af8;
      }
      local_2af8 = uVar9;
    }
    goto LAB_000c748a;
  case 0x18:
    goto switchD_000c67ba_caseD_18;
  case 0x19:
    bVar4 = (byte)(uVar15 >> 0x1b) & 3;
    if ((bVar4 == 2) || ((bVar4 == 0 && (aiStack_8a4[uVar15 >> 0x10 & 0xff] == 2)))) {
      local_29e4 = local_29e4 | 1 << ((byte)(uVar15 >> 0x10) & 0x1f);
    }
    ((int (*)())FUN_000c4e0f)();
    local_24 = local_24 + 1;
    puVar19 = local_24;
    goto switchD_000c67ba_caseD_18;
  case 0x1a:
    local_24 = puVar17 + 1;
    if ((int)uVar15 < 0) {
      local_24 = puVar17 + 2;
    }
LAB_000c748a:
    local_24 = local_24 + 1;
    puVar19 = local_24;
    goto switchD_000c67ba_caseD_18;
  case 0x1c:
    local_24 = puVar17 + 1;
    uVar15 = puVar17[1] >> 0x10 & 0x3f;
    if (uVar15 == 1) {
      local_7c = puVar17[2];
      local_78 = puVar17[3];
      local_74 = puVar17[4];
      local_70 = puVar17[5];
      local_24 = puVar17 + 6;
      ((int (*)())FUN_000c4e26)();
      puVar19 = local_24;
    }
    else {
      puVar19 = puVar17 + 1;
      if (uVar15 == 2) {
        local_7c = puVar17[2];
        local_78 = puVar17[3];
        local_74 = puVar17[4];
        local_70 = puVar17[5];
        local_24 = puVar17 + 6;
        ((int (*)())FUN_000c4eab)();
        puVar19 = local_24;
      }
    }
    goto switchD_000c67ba_caseD_18;
  case 0x24:
    local_24 = (uint *)((int (*)())FUN_000c5eed)(local_2b5c);
    local_2bc8 = local_2bc8 + 5;
    puVar19 = local_24;
    goto switchD_000c67ba_caseD_18;
  case 0x34:
    goto LAB_000c754e;
  case 0x35:
    local_54 = puVar17[1];
    local_24 = puVar17 + 2;
    ((int (*)())FUN_000c5df4)();
    puVar19 = local_24;
    goto switchD_000c67ba_caseD_18;
  case 0x37:
    local_24 = (uint *)((int (*)())FUN_000c5eed)(local_2b5c);
    local_930 = 1;
    puVar19 = local_24;
    goto switchD_000c67ba_caseD_18;
  case 0x3b:
    break;
  case 0x3e:
LAB_000c754e:
    local_24 = (uint *)((int (*)())FUN_000c5eed)(local_2b5c);
    puVar19 = local_24;
    goto switchD_000c67ba_caseD_18;
  case 0x5d:
    local_83c = local_83c + 1;
    local_24 = puVar17 + 2;
    bVar4 = *(byte *)((int)puVar17 + 3);
    if ((((bVar4 & 0xc) == 4) ||
        (((bVar4 & 0xc) == 8 && ((local_2ae8 & 1 << (*(byte *)((int)puVar17 + 2) & 0x1f)) != 0))))
       && (local_2aec << (*(byte *)((int)puVar17 + 2) & 0x1f) != 0)) {
      local_2bc0 = local_2bc0 + 0x1b;
      local_2ae8 = local_2ae8 | 1 << (*(byte *)((int)puVar17 + 2) & 0x1f);
      bVar4 = *(byte *)((int)puVar17 + 3);
    }
    if ((char)bVar4 < '\0') {
      local_24 = puVar17 + 3;
      bVar4 = *(byte *)((int)puVar17 + 3);
    }
    if ((bVar4 & 0x40) != 0) {
      local_24 = local_24 + 1;
    }
    if ((puVar17[1] >> 0x10 & 0x40) != 0) {
      local_2bf4 = *local_24;
      local_24 = local_24 + 1;
    }
    ((int (*)())FUN_000c5cb6)(local_2bf4,puVar17[1] >> 0x16 & 1);
    iVar6 = local_2bc0 + 4;
    if ((local_2aec & 1 << (*(byte *)((int)puVar17 + 2) & 0x1f)) == 0) {
      iVar6 = local_2bc0;
    }
    local_6c = *local_24;
    puVar19 = local_24 + 1;
    if ((local_6c & 0x400000) != 0) {
      local_30 = local_24[1];
      puVar19 = local_24 + 2;
    }
    local_24 = puVar19;
    ((int (*)())FUN_000c5df4)();
    puVar19 = local_24;
    local_2bc0 = iVar6;
    goto switchD_000c67ba_caseD_18;
  case 0x5e:
    local_83c = local_83c + 1;
    local_24 = puVar17 + 2;
    bVar4 = *(byte *)((int)puVar17 + 3);
    if ((((bVar4 & 0xc) == 4) ||
        (((bVar4 & 0xc) == 8 && ((local_2ae8 & 1 << (*(byte *)((int)puVar17 + 2) & 0x1f)) != 0))))
       && (local_2aec << (*(byte *)((int)puVar17 + 2) & 0x1f) != 0)) {
      local_2bc0 = local_2bc0 + 0x1b;
      local_2ae8 = local_2ae8 | 1 << (*(byte *)((int)puVar17 + 2) & 0x1f);
      bVar4 = *(byte *)((int)puVar17 + 3);
    }
    if ((char)bVar4 < '\0') {
      local_24 = puVar17 + 3;
      bVar4 = *(byte *)((int)puVar17 + 3);
    }
    if ((bVar4 & 0x40) != 0) {
      local_24 = local_24 + 1;
    }
    if ((puVar17[1] >> 0x10 & 0x40) != 0) {
      local_2c00 = *local_24;
      local_24 = local_24 + 1;
    }
    ((int (*)())FUN_000c5cb6)(local_2c00,puVar17[1] >> 0x16 & 1);
    iVar6 = local_2bc0 + 4;
    if ((local_2aec & 1 << (*(byte *)((int)puVar17 + 2) & 0x1f)) == 0) {
      iVar6 = local_2bc0;
    }
    local_30 = *local_24;
    puVar19 = local_24 + 1;
    if ((local_30 & 0x400000) != 0) {
      local_3c = local_24[1];
      puVar19 = local_24 + 2;
    }
    local_2c = *puVar19;
    local_24 = puVar19 + 1;
    if ((local_2c & 0x400000) != 0) {
      local_38 = puVar19[1];
      local_24 = puVar19 + 2;
    }
    ((int (*)())FUN_000c5df4)();
    ((int (*)())FUN_000c5df4)();
    puVar19 = local_24;
    local_2bc0 = iVar6;
    goto switchD_000c67ba_caseD_18;
  }
  local_24 = (uint *)((int (*)())FUN_000c5eed)(local_2b5c);
  puVar19 = local_24;
  goto switchD_000c67ba_caseD_18;
switchD_000c67ba_caseD_0:
                    
  _exit(0);
}

/* FUN_000c890f @ 0xc890f (4297 bytes) */
int FUN_000c890f(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int *param_2;
  int *param_3;
  int *param_4;
  undefined4 *param_5;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  bool bVar5;
  byte bVar6;
  void *pvVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  void *pvVar11;
  int *piVar12;
  byte bVar13;
  int iVar14;
  undefined1 *puVar15;
  int iVar16;
  int *piVar17;
  uint *puVar18;
  uint *puVar19;
  uint uVar20;
  int iVar21;
  byte *pbVar22;
  char *pcVar23;
  uint local_c2a4;
  int local_c2a0;
  undefined4 *local_c294;
  int local_c28c;
  undefined1 *local_c27c;
  int *local_c278;
  int local_c274;
  uint *local_c26c;
  uint uStack_c23c;
  uint uStack_c238;
  uint uStack_c234;
  uint uStack_c228;
  undefined4 *local_c214;
  int local_c210;
  uint local_c20c;
  int local_c1f8;
  int local_c1f0;
  uint local_c1ec;
  undefined4 uStack_c1e8;
  uint uStack_c1e4;
  uint uStack_c1e0;
  byte bStack_c1dc;
  uint uStack_c1d8;
  uint uStack_c1d4;
  undefined4 uStack_c1d0;
  byte bStack_c1cc;
  int local_c1c0;
  undefined4 *local_c1bc;
  int local_c1b4;
  uint *local_c1b0;
  int local_c1ac;
  int local_c1a8;
  int local_c1a4;
  uint local_c198;
  undefined1 local_c180 [72];
  undefined4 local_c138;
  uint local_c12c;
  void *local_c120;
  uint auStack_c0e8 [27];
  uint local_c07c;
  char local_c078 [1348];
  undefined1 auStack_bb34 [37816];
  int local_277c;
  uint local_24f8 [7];
  undefined4 local_24dc;
  undefined4 local_24d8;
  undefined4 local_24d4;
  undefined4 local_24d0;
  undefined4 local_24cc [4];
  undefined4 local_24bc;
  undefined4 local_24b8;
  undefined4 local_24b4;
  undefined4 local_24b0;
  int local_24ac;
  uint local_24a8;
  int local_24a0;
  int local_249c;
  int local_2498;
  int local_2494;
  int local_2490;
  int local_248c;
  uint local_2488;
  uint local_2484;
  int local_2440 [16];
  uint auStack_2400 [16];
  uint auStack_23c0 [16];
  uint local_2380;
  uint local_2370 [1032];
  undefined4 local_1350 [8];
  undefined4 local_1330 [2];
  undefined1 local_1328 [4088];
  int local_330;
  int local_328;
  int local_324;
  undefined4 local_320;
  int local_308 [5];
  int local_2f4;
  int local_2ec;
  int local_2e4;
  int local_2e0;
  int local_2dc;
  int local_2d8;
  undefined4 local_2d4;
  int local_2d0;
  int local_2cc;
  undefined4 local_2c8;
  int local_2c4;
  int aiStack_2c0 [16];
  undefined4 auStack_280 [14];
  undefined1 auStack_248 [8];
  uint local_240 [17];
  int local_1fc;
  int local_1f4;
  int local_1f0;
  undefined4 local_1ec;
  int local_1e8;
  undefined4 local_1dc;
  int local_1d8;
  undefined4 local_18c;
  undefined1 local_188 [72];
  uint *local_140;
  undefined4 *local_13c;
  int local_138;
  undefined4 auStack_130 [8];
  undefined4 auStack_110 [16];
  void *local_d0;
  uint local_cc [8];
  uint local_ac [8];
  uint local_8c [4];
  uint uStack_7c;
  uint uStack_78;
  uint uStack_74;
  uint uStack_70;
  uint uStack_60;
  uint uStack_54;
  uint uStack_50;
  uint uStack_48;
  uint uStack_44;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_30;
  uint uStack_2c;
  uint *local_24;
  uint *local_20;
  
  iVar14 = 1;
  do {
    local_cc[iVar14 + -1] = 0xffffffff;
    local_cc[iVar14 + 7] = 0;
    iVar14 = iVar14 + 1;
  } while (iVar14 != 9);
  local_cc[0] = local_cc[0] & 0xffff0000;
  pvVar7 = _malloc(0x400);
  local_2484 = 0;
  local_1dc = 0;
  local_1d8 = 0;
  local_18c = 0;
  if (param_1 == 0) {
    local_2488 = 0;
  }
  else {
    local_2488 = 0;
    local_c2a0 = param_1;
    iVar14 = 0;
    iVar21 = 0;
    do {
      while ((iVar16 = *(int *)(local_c2a0 + 0x13f8), iVar16 == 0 ||
             (*(short *)(iVar16 + 0x38) != 0x1902))) {
LAB_000c89c4:
        iVar14 = iVar14 + 1;
        iVar21 = iVar21 + 4;
        local_c2a0 = local_c2a0 + 4;
        if (iVar14 == 0x10) goto LAB_000c8a44;
      }
      uVar8 = 1 << ((byte)iVar14 & 0x1f);
      local_2488 = local_2488 | uVar8;
      *(uint *)((int)auStack_2400 + iVar21) = (uint)*(ushort *)(iVar16 + 0x58);
      *(uint *)((int)auStack_23c0 + iVar21) = (uint)*(ushort *)(iVar16 + 0x5c);
      if (*(short *)(iVar16 + 0x5a) == 0) goto LAB_000c89c4;
      local_2484 = local_2484 | uVar8;
      iVar14 = iVar14 + 1;
      iVar21 = iVar21 + 4;
      local_c2a0 = local_c2a0 + 4;
    } while (iVar14 != 0x10);
  }
LAB_000c8a44:
  local_c26c = local_24f8;
  if ((char)param_3[0x46] == '\0') {
    local_328 = 0;
  }
  else {
    local_328 = 1;
    local_324 = param_3[0x2b];
    if (param_1 == 0) {
      local_320 = 0;
    }
    else {
      local_320 = *(undefined4 *)(param_1 + 0x276c);
    }
  }
  iVar14 = 0;
  puVar15 = auStack_248;
  do {
    *(undefined4 *)(puVar15 + 8) = 0;
    if ((param_1 != 0) && (iVar21 = *(int *)(*param_2 + 0x13f8 + iVar14 * 4), iVar21 != 0)) {
      *(uint *)(puVar15 + 8) = (uint)*(byte *)(iVar21 + 0x30);
    }
    iVar14 = iVar14 + 1;
    puVar15 = puVar15 + 4;
  } while (iVar14 != 0x10);
  local_1fc = param_3[0x45];
  local_2c4 = 1;
  local_2f4 = 0;
  if ((param_1 == 0) || (*(short *)(*(int *)(*(int *)(param_1 + 4) + 0x10) + 0x2e06) != -0x7baf)) {
    local_1ec = 0;
  }
  else {
    local_1ec = 1;
  }
  iVar14 = param_4[1];
  puVar1 = (undefined4 *)*param_4;
  local_24f8[0] = 0;
  local_24f8[1] = 0xffff;
  local_24ac = 0;
  local_2494 = 0;
  local_24d0 = local_cc[7];
  local_24d4 = local_cc[6];
  local_24d8 = local_cc[5];
  local_24dc = local_cc[4];
  local_24f8[6] = local_cc[3];
  local_24f8[5] = local_cc[2];
  local_24f8[4] = local_cc[1];
  local_24f8[3] = local_cc[0];
  local_24b0 = local_ac[7];
  local_24b4 = local_ac[6];
  local_24b8 = local_ac[5];
  local_24bc = local_ac[4];
  local_24cc[3] = local_ac[3];
  local_24cc[2] = local_ac[2];
  local_24cc[1] = local_ac[1];
  local_24cc[0] = local_ac[0];
  local_24f8[2] = 0;
  local_2380 = 0;
  local_330 = 0;
  local_308[0] = 0;
  local_308[1] = 0;
  local_308[2] = 0;
  local_308[3] = 0;
  local_2e4 = 0;
  local_2e0 = 0;
  local_2dc = 0;
  local_2d8 = 0;
  local_2ec = 0;
  local_2d4 = 0;
  local_2d0 = 0;
  local_2cc = 0;
  local_2c8 = 0;
  iVar16 = 0;
  iVar21 = 0;
  do {
    *(undefined4 *)(iVar21 + 0x188 + (int)local_c26c) = 0;
    *(undefined4 *)(iVar21 + 0x11a8 + (int)local_c26c) = 0;
    iVar16 = iVar16 + 1;
    iVar21 = iVar21 + 4;
  } while (iVar16 != 8);
  iVar16 = 0;
  iVar21 = 0;
  do {
    *(undefined4 *)(iVar21 + 0x2238 + (int)local_c26c) = 0;
    *(undefined4 *)(iVar21 + 0x2278 + (int)local_c26c) = 0;
    iVar16 = iVar16 + 1;
    iVar21 = iVar21 + 4;
  } while (iVar16 != 0x10);
  local_20 = puVar1 + 2;
  local_c1f8 = 0;
  local_c1f0 = 0;
  local_c1ec = 0;
  puVar9 = puVar1 + 2;
code_r0x000c8d44:
  puVar19 = puVar9;
  if (puVar19 < puVar1 + iVar14) goto code_r0x000c8d52;
  if (local_330 != 0) {
    local_c214 = (undefined4 *)0x0;
    local_c20c = 0;
    goto LAB_000c92f4;
  }
  local_24a8 = local_24f8[0];
  iVar21 = (iVar14 + local_c1f8) * 4;
  if (local_24ac != 0) {
    iVar21 = iVar21 + 0x48;
  }
  uVar8 = iVar21 + local_c1f0 * 4;
  if (local_328 != 0) {
    uVar8 = uVar8 + 0x14;
  }
  uVar10 = uVar8;
  if ((local_308[0] != 0) && (uVar10 = uVar8 + 0xc, local_328 != 0)) {
    uVar10 = uVar8 + 0x24;
  }
  uVar8 = uVar10;
  if ((local_308[1] != 0) && (uVar8 = uVar10 + 0xc, local_328 != 0)) {
    uVar8 = uVar10 + 0x24;
  }
  uVar10 = uVar8;
  if ((local_308[2] != 0) && (uVar10 = uVar8 + 0xc, local_328 != 0)) {
    uVar10 = uVar8 + 0x24;
  }
  local_c198 = uVar10;
  if ((local_308[3] != 0) && (local_c198 = uVar10 + 0xc, local_328 != 0)) {
    local_c198 = uVar10 + 0x24;
  }
  if (((local_2ec != 0) && (local_2f4 != 0)) && (local_2c4 == 0)) {
    local_c198 = local_c198 + 0x14;
  }
  if (local_1fc == 1) {
    local_c198 = local_c198 + 0x24;
  }
  else if (local_1fc == 2) {
    local_c198 = local_c198 + 0x30;
  }
  else if (local_1fc == 3) {
    local_c198 = local_c198 + 0x40;
  }
  else if (local_1fc == 0) goto LAB_000c905e;
  local_c198 = local_c198 + 8;
  iVar21 = 0;
  piVar17 = local_308;
  do {
    if (*piVar17 != 0) {
      local_c198 = local_c198 + 0x2c;
    }
    iVar21 = iVar21 + 1;
    piVar17 = piVar17 + 1;
  } while (iVar21 != 4);
LAB_000c905e:
  if (((local_2e0 != 0) || (local_2d8 != 0)) || (local_2c4 == 0)) {
    uVar8 = local_c198;
    if ((local_2e4 == 0) && (local_2dc != 0)) {
      uVar8 = local_c198 + 0xc;
    }
    local_c198 = uVar8;
    if ((local_2c4 == 0) && (local_c198 = uVar8 + 0xc, local_1e8 != 0)) {
      local_c198 = uVar8 + 0x18;
    }
  }
  local_c214 = _malloc(local_c198 + 0x10);
  *local_c214 = *puVar1;
  local_c214[1] = puVar1[1];
  local_24 = local_c214 + 2;
  local_20 = puVar1 + 2;
  bVar5 = true;
  puVar9 = local_20;
code_r0x000c9123:
  puVar18 = puVar9;
  puVar19 = local_24;
  if (puVar1 + iVar14 <= puVar18) {
    local_24f8[2] = local_24f8[2] | local_c1ec;
    local_c20c = local_c198 >> 2;
LAB_000c92f4:
    if (local_330 != 0) {
      _free(local_c214);
      return local_330;
    }
    if ((local_24ac == 0) || (local_2498 == 0x11)) {
      *(undefined1 *)((int)param_2 + 0x1e2f) = 0;
      *(undefined1 *)(param_2 + 0x7a6) = 0;
    }
    else {
      *(undefined1 *)((int)param_2 + 0x1e2f) = 1;
      *(undefined1 *)(param_2 + 0x7a6) = 1;
      param_2[0x7a4] = local_2498 + 2;
      param_3[0x2e] = local_24a0 + param_2[0x7c7];
      param_3[0x2f] = local_249c + param_2[0x7c7];
    }
    if ((local_2494 == 0) || (local_2490 == 0x11)) {
      *(undefined1 *)((int)param_2 + 0x1e2e) = 0;
    }
    else {
      *(undefined1 *)((int)param_2 + 0x1e2e) = 1;
      param_2[0x7a3] = local_2490 + 2;
    }
    if (local_1fc == 0) {
      *(undefined1 *)(param_2 + 0x7a8) = 0;
    }
    else {
      param_2[0x7a3] = local_248c;
      param_3[0x38] = local_1f4 + param_2[0x7c7];
      param_3[0x39] = local_1f0 + param_2[0x7c7];
      *(undefined1 *)(param_2 + 0x7a8) = 1;
    }
    *(bool *)((int)param_2 + 0x1efd) = local_2d0 != 0;
    *(bool *)(param_2 + 0x7c1) = local_2cc != 0;
    iVar14 = 0;
    piVar17 = param_3;
    do {
      if ((local_24f8[2] & 1 << ((byte)iVar14 & 0x1f)) == 0) {
        *(undefined1 *)(piVar17 + 0x2c) = 0;
      }
      else if ((local_24ac == 0) || (local_2498 != iVar14)) {
        *(undefined1 *)(piVar17 + 0x2c) = 1;
      }
      else {
        *(undefined1 *)(iVar14 + 0xb0 + (int)param_3) = 0;
      }
      iVar14 = iVar14 + 1;
      piVar17 = (int *)((int)piVar17 + 1);
    } while (iVar14 != 8);
    param_2[0x7a9] = 0;
    param_3[0x36] = 0;
    *(int *)(*param_3 + 0x10e4) = local_2440[0];
    local_c1a4 = 0;
    iVar14 = 0;
    piVar17 = param_2;
    piVar12 = param_2;
    do {
      uVar8 = 1 << ((byte)local_c1a4 & 0x1f);
      *(bool *)(piVar17 + 0x582) = (local_2380 & uVar8) != 0;
      if ((local_2488 & uVar8) == 0) {
        *(undefined1 *)(piVar17 + 0x586) = 0;
      }
      else {
        param_2[0x7a9] = 1;
        *(undefined1 *)(piVar17 + 0x586) = 1;
        piVar12[0x7aa] = *(int *)(iVar14 + 0xb8 + (int)local_c26c) + param_2[0x7c7];
      }
      piVar12[0x572] = *(int *)(iVar14 + 0x2238 + (int)local_c26c);
      *(char *)(piVar17 + 0x56e) = (char)*(undefined4 *)(iVar14 + 0x2278 + (int)local_c26c);
      local_c1a4 = local_c1a4 + 1;
      iVar14 = iVar14 + 4;
      piVar12 = piVar12 + 1;
      piVar17 = (int *)((int)piVar17 + 1);
    } while (local_c1a4 != 0x10);
    local_c1a8 = 0;
    piVar17 = param_2;
    do {
      if (((param_1 != 0) && ((char)piVar17[0x586] != '\0')) &&
         (*(int *)(*param_2 + 0x13f8 + local_c1a8 * 4) != 0)) {
        ((int (*)())FUN_000c6453)();
      }
      local_c1a8 = local_c1a8 + 1;
      piVar17 = (int *)((int)piVar17 + 1);
    } while (local_c1a8 != 0x10);
    local_c1b4 = 0;
    local_c1b0 = local_c26c;
    local_c27c = local_1328;
    local_c28c = 0;
    local_c294 = local_1330;
    do {
      local_c1bc = local_c294 + 2;
      local_c210 = 0;
      iVar14 = local_c1b4;
      do {
        uVar8 = 1 << ((byte)local_c210 & 0x1f);
        if ((local_c1b0[0x62] & uVar8) != 0) {
          ((int (*)())FUN_000c6453)();
        }
        if ((local_c1b0[0x46a] & uVar8) != 0) {
          uVar2 = *local_c1bc;
          uVar3 = *(undefined4 *)
                   ((int)local_c1bc + (int)local_c26c + ((local_c28c + 0x11cc) - (int)local_c27c));
          iVar21 = *param_3;
          *(char *)(iVar21 + 0x36cc + iVar14 * 4) =
               (char)*(undefined4 *)
                      ((int)local_c1bc + (int)local_c26c + ((local_c28c + 0x11c8) - (int)local_c27c)
                      );
          (*(unsigned char *)((unsigned char *)&(local_c2a0) + 0)) = (undefined1)uVar3;
          *(undefined1 *)(iVar21 + 0x36cd + iVar14 * 4) = (undefined1)local_c2a0;
          *(char *)(iVar21 + 0x36ce + iVar14 * 4) = (char)uVar2;
        }
        local_c210 = local_c210 + 1;
        iVar14 = iVar14 + 1;
        local_c1bc = local_c1bc + 4;
      } while (local_c210 != 0x20);
      local_c1b4 = local_c1b4 + 0x20;
      local_c294 = local_c294 + 0x80;
      local_c28c = local_c28c + 0x200;
      local_c27c = local_c27c + 0x200;
      local_c1b0 = local_c1b0 + 1;
    } while (local_c1b4 != 0x100);
    *(undefined4 *)(*param_3 + 0x374c) = local_1350[0];
    _memset(local_188,0,0xbc);
    _memset(local_c180,0,0x9c88);
    pvVar11 = _malloc(param_5[1]);
    if (pvVar11 == (void *)0x0) {
      return -1;
    }
    _memset(pvVar11,0,param_5[1]);
    local_13c = local_c214;
    local_138 = local_c20c << 2;
    iVar14 = 0;
    iVar21 = 0;
    local_d0 = pvVar11;
    do {
      *(undefined4 *)(local_188 + iVar21 + 0x58) = *(undefined4 *)(iVar21 + 0xc + (int)local_c26c);
      *(undefined4 *)(local_188 + iVar21 + 0x78) = *(undefined4 *)(iVar21 + 0x2c + (int)local_c26c);
      iVar14 = iVar14 + 1;
      iVar21 = iVar21 + 4;
    } while (iVar14 != 8);
    local_8c[0] = local_8c[0] & 0xfffffc02 | 0x112;
    local_140 = local_8c;
    local_c138 = 0x40;
    local_c120 = _malloc(0x900);
    iVar14 = ((int (*)())FUN_000cb0bc)(*param_5,local_188,local_c180);
    if (iVar14 != 0) {
      return 2;
    }
    iVar14 = 0;
    puVar15 = auStack_bb34;
    do {
      _memcpy((void *)(param_3[3] + iVar14),puVar15,0x48);
      piVar17 = (int *)(iVar14 + param_3[3]);
      if ((*piVar17 == 1) && ((char)piVar17[2] == '\x0f')) {
        *(char *)(piVar17 + 2) = (char)local_2490;
      }
      iVar14 = iVar14 + 0x48;
      puVar15 = puVar15 + 0x48;
    } while (iVar14 != 0x9360);
    local_c1ac = 0;
    local_c1c0 = 0;
    local_c274 = 0x1a20;
    local_c278 = param_2 + 0x594;
    do {
      uVar8 = auStack_c0e8[local_c1ac] | local_2370[local_c1ac];
      *(uint *)(*param_3 + 0x10bc + local_c1ac * 4) = uVar8;
      if (uVar8 != 0) {
        pbVar22 = (byte *)(local_c278 + 2);
        piVar17 = (int *)((int)param_2 + local_c274);
        iVar14 = param_2[0x7c7];
        iVar21 = local_c1c0;
        do {
          *pbVar22 = (byte)uVar8 & 1;
          *piVar17 = iVar14 + iVar21;
          pbVar22 = pbVar22 + 1;
          iVar21 = iVar21 + 1;
          piVar17 = piVar17 + 1;
          uVar8 = uVar8 >> 1;
        } while (uVar8 != 0);
      }
      local_c1ac = local_c1ac + 1;
      local_c1c0 = local_c1c0 + 0x20;
      local_c278 = local_c278 + 8;
      local_c274 = local_c274 + 0x80;
    } while (local_c1ac != 8);
    if (*(int *)(*param_3 + 0x10bc) == 0) {
      *(undefined4 *)(*param_3 + 0x10dc) = 0;
    }
    if (local_277c != 0) {
      iVar14 = 0;
      do {
        iVar14 = iVar14 + 1;
      } while (local_277c != iVar14);
    }
    if (local_c12c != 0) {
      local_c2a4 = 0;
      iVar14 = 0;
      do {
        piVar17 = (int *)(iVar14 + (int)local_c120);
        switch(piVar17[2]) {
        case 1:
          iVar21 = *piVar17;
          iVar16 = *param_3;
          iVar4 = piVar17[1];
          if (iVar4 == 1) {
            piVar12 = (int *)(iVar21 * 0x10 + 0x94 + iVar16);
          }
          else if (iVar4 == 0) {
            piVar12 = (int *)(iVar21 * 0x10 + 0x90 + iVar16);
          }
          else if (iVar4 == 2) {
            piVar12 = (int *)(iVar21 * 0x10 + 0x98 + iVar16);
          }
          else if (iVar4 == 3) {
            piVar12 = (int *)(iVar21 * 0x10 + 0x9c + iVar16);
          }
          else {
            piVar12 = (int *)0x0;
          }
          *piVar12 = piVar17[5];
          break;
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 0xb:
        case 0xc:
        case 0xd:
          ((int (*)())FUN_000c63f7)(param_3 + 0x48,piVar17);
        }
        local_c2a4 = local_c2a4 + 1;
        iVar14 = iVar14 + 0x24;
      } while (local_c2a4 < local_c12c);
    }
    if (local_c07c != 0) {
      uVar8 = 0;
      iVar14 = 0;
      pcVar23 = local_c078;
      do {
        if (*pcVar23 != '\x02') {
          iVar14 = iVar14 + 1;
        }
        if (*pcVar23 == '\x04') {
          *(undefined1 *)((int)param_2 + 0x1e2e) = 1;
          param_2[0x7a3] = local_2490 + 2;
        }
        uVar8 = uVar8 + 1;
        pcVar23 = pcVar23 + 0xc;
      } while (uVar8 < local_c07c);
      if (8 < iVar14) {
        iVar14 = 1;
        goto LAB_000ca9eb;
      }
    }
    iVar14 = 0;
LAB_000ca9eb:
    iVar21 = 0;
    do {
      iVar16 = iVar21 * 0x10;
      *(undefined4 *)(iVar16 + param_3[1] + 0x108) = 0;
      *(undefined4 *)(iVar16 + param_3[1] + 0x10c) = 1;
      *(undefined4 *)(iVar16 + param_3[1] + 0x110) = 2;
      *(undefined4 *)(iVar16 + param_3[1] + 0x114) = 3;
      iVar21 = iVar21 + 1;
    } while (iVar21 != 0x10);
    _free(local_c120);
    _free(pvVar11);
    if (pvVar7 != (void *)0x0) {
      _free(pvVar7);
    }
    if (local_c214 != (undefined4 *)0x0) {
      _free(local_c214);
    }
    return iVar14;
  }
  uVar8 = *puVar18;
  puVar9 = puVar18;
  switch(uVar8 & 0xffff) {
  default:
    goto LAB_000c8f0c;
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
    if (bVar5) {
      local_24 = (uint *)((int (*)())FUN_000c5876)();
      bVar5 = false;
    }
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
    if (bVar5) {
      local_24 = (uint *)((int (*)())FUN_000c5876)();
      bVar5 = false;
    }
    local_20 = (uint *)((int (*)())FUN_000c607d)(2,local_c26c);
    puVar9 = local_20;
    goto code_r0x000c9123;
  case 6:
  case 0x10:
  case 0x27:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x4b:
  case 0x53:
    *local_24 = uVar8;
    local_24 = local_24 + 1;
    local_20 = puVar18 + 1;
    puVar9 = local_20;
    goto code_r0x000c9123;
  case 7:
  case 0x11:
    goto code_r0x000c9931;
  case 8:
  case 0x15:
  case 0x16:
  case 0x32:
    *local_24 = uVar8;
    local_24[1] = puVar18[1];
    local_24 = local_24 + 2;
    local_20 = puVar18 + 2;
    puVar9 = local_20;
    goto code_r0x000c9123;
  case 9:
  case 0x14:
  case 0x1d:
    *local_24 = uVar8;
    local_24[1] = puVar18[1];
    local_24[2] = puVar18[2];
    local_24 = local_24 + 3;
    local_20 = puVar18 + 3;
    puVar9 = local_20;
    goto code_r0x000c9123;
  case 10:
  case 0xd:
  case 0x21:
  case 0x2f:
  case 0x3f:
  case 0x40:
  case 100:
    if (bVar5) {
      local_24 = (uint *)((int (*)())FUN_000c5876)();
      bVar5 = false;
    }
    local_20 = (uint *)((int (*)())FUN_000c607d)(3,local_c26c);
    puVar9 = local_20;
    goto code_r0x000c9123;
  case 0xf:
    *local_24 = uVar8;
    local_20 = puVar18 + 2;
    local_24[1] = puVar18[1];
    local_24 = local_24 + 2;
    uVar8 = puVar18[1];
    puVar9 = local_20;
    if ((ushort)uVar8 != 0) {
      uVar10 = 0;
      do {
        *local_24 = *local_20;
        local_24 = local_24 + 1;
        local_20 = local_20 + 1;
        uVar10 = uVar10 + 1;
        puVar9 = local_20;
      } while ((ushort)uVar8 != uVar10);
    }
  case 0x18:
    goto code_r0x000c9123;
  case 0x19:
    local_20 = puVar18 + 1;
    if ((uVar8 >> 0x18 & 0x18) == 0) {
      if (local_240[uVar8 >> 0x10 & 0xff] == 2) {
        uVar8 = uVar8 & 0xe7ffffff | 0x10000000;
      }
      else {
        uVar8 = uVar8 & 0xe7ffffff | 0x8000000;
      }
    }
    goto code_r0x000c9f8e;
  case 0x1a:
    local_20 = puVar18 + 1;
    *local_24 = uVar8;
    puVar9 = local_24 + 1;
    if ((int)uVar8 < 0) {
      uVar8 = *local_20;
      local_20 = puVar18 + 2;
      local_24[1] = uVar8;
      puVar9 = local_24 + 2;
    }
    local_24 = puVar9;
    uVar8 = *local_20;
    local_20 = local_20 + 1;
code_r0x000c9f8e:
    *local_24 = uVar8;
    local_24 = local_24 + 1;
    puVar9 = local_20;
    goto code_r0x000c9123;
  case 0x1c:
    *local_24 = uVar8;
    local_24 = local_24 + 1;
    local_20 = puVar18 + 1;
    puVar9 = local_20;
    if ((puVar18[1] >> 0x10 & 0x3f) - 1 < 2) {
      puVar19[1] = puVar18[1];
      puVar19[2] = puVar18[2];
      puVar19[3] = puVar18[3];
      puVar19[4] = puVar18[4];
      puVar19[5] = puVar18[5];
      local_24 = puVar19 + 6;
      local_20 = puVar18 + 6;
      puVar9 = local_20;
    }
    goto code_r0x000c9123;
  case 0x28:
    local_20 = puVar18 + 1;
    puVar9 = (uint *)((int (*)())FUN_000c5345)();
    *puVar9 = uVar8;
    local_24 = puVar9 + 1;
    puVar9 = local_20;
    goto code_r0x000c9123;
  case 0x34:
code_r0x000c9931:
    local_20 = (uint *)((int (*)())FUN_000c607d)(2,local_c26c);
    puVar9 = local_20;
    goto code_r0x000c9123;
  case 0x35:
    *local_24 = uVar8;
    local_24 = local_24 + 1;
    uStack_60 = puVar18[1];
    local_20 = puVar18 + 2;
    ((int (*)())FUN_000c5dad)();
    *local_24 = uStack_60;
    local_24 = local_24 + 1;
    puVar9 = local_20;
    goto code_r0x000c9123;
  case 0x37:
  case 0x3e:
    local_20 = (uint *)((int (*)())FUN_000c607d)(1,local_c26c);
    puVar9 = local_20;
    goto code_r0x000c9123;
  case 0x3b:
    break;
  case 0x5d:
    if (bVar5) {
      local_24 = (uint *)((int (*)())FUN_000c5876)();
      bVar5 = false;
      puVar18 = local_20;
    }
    uVar8 = *puVar18;
    puVar9 = puVar18 + 1;
    uVar10 = uVar8 >> 0x10 & 0xff;
    if ((uVar8 & 0x80000000) == 0) {
      uStack_c1e4 = 0;
    }
    else {
      uStack_c1e4 = puVar18[1];
      puVar9 = puVar18 + 2;
    }
    if ((uVar8 & 0x40000000) == 0) {
      uStack_c1e0 = 0;
    }
    else {
      uStack_c1e0 = *puVar9;
      puVar9 = puVar9 + 1;
    }
    uStack_30 = *puVar9;
    puVar19 = puVar9 + 1;
    if ((uStack_30 & 0x400000) != 0) {
      uStack_c238 = puVar9[1];
      puVar19 = puVar9 + 2;
    }
    uStack_54 = *puVar19;
    local_20 = puVar19 + 1;
    if ((uStack_54 & 0x400000) != 0) {
      uStack_48 = puVar19[1];
      local_20 = puVar19 + 2;
    }
    bVar6 = (byte)(uVar8 >> 0x18) & 0xc;
    bStack_c1dc = (byte)(uVar8 >> 0x10);
    if (bVar6 == 4) {
code_r0x000cacb7:
      if (local_2488 << (bStack_c1dc & 0x1f) == 0) {
        uVar20 = 1 << (bStack_c1dc & 0x1f);
        goto code_r0x000c9adf;
      }
      local_24 = (uint *)((int (*)())FUN_000c4fd8)(uVar10,local_24);
      if ((uStack_30 & 0x400000) == 0) {
        uVar20 = 1 << (bStack_c1dc & 0x1f);
        uStack_c1e8 = 0;
      }
      else {
        uStack_3c = uStack_c238;
        uStack_30 = uStack_30 & 0xffbfffff;
        uVar20 = 1 << (bStack_c1dc & 0x1f);
        uStack_c1e8 = 1;
      }
    }
    else {
      if (bVar6 == 8) {
        uVar20 = 1 << (bStack_c1dc & 0x1f);
        if ((local_2484 & uVar20) != 0) goto code_r0x000cacb7;
      }
      else {
        uVar20 = 1 << (bStack_c1dc & 0x1f);
      }
code_r0x000c9adf:
      uStack_c1e8 = 0;
    }
    ((int (*)())FUN_000c5dad)();
    *local_24 = uVar8;
    puVar9 = local_24 + 1;
    if ((uVar8 & 0x80000000) != 0) {
      local_24[1] = uStack_c1e4;
      puVar9 = local_24 + 2;
    }
    local_24 = puVar9;
    if ((uVar8 & 0x40000000) != 0) {
      *local_24 = uStack_c1e0;
      local_24 = local_24 + 1;
    }
    *local_24 = uStack_30;
    puVar9 = local_24 + 1;
    if ((uStack_30 & 0x400000) != 0) {
      local_24[1] = uStack_c238;
      puVar9 = local_24 + 2;
    }
    local_24 = puVar9;
    puVar9 = local_24;
    *local_24 = uStack_54;
    local_24 = local_24 + 1;
    if ((uStack_54 & 0x400000) != 0) {
      puVar9[1] = uStack_48;
      local_24 = puVar9 + 2;
    }
    if (((bVar6 == 4) || ((bVar6 == 8 && ((local_2484 & uVar20) != 0)))) &&
       (local_2488 << (bStack_c1dc & 0x1f) != 0)) {
      local_24 = (uint *)((int (*)())FUN_000c5121)(&uStack_3c,uVar10,uStack_c1e8,local_24);
    }
    puVar9 = local_20;
    if ((local_2488 & uVar20) != 0) {
      *local_24 = 0x47;
      uVar8 = uStack_c238;
      uVar20 = uStack_30;
      if ((uStack_30 & 0x400000) == 0) {
        uVar20 = uStack_30 | 0x400000;
        uVar8 = 0x55;
      }
      if (auStack_2400[uVar10] == 0x1906) {
        if (((byte)uVar8 & 3) == 1) {
          uVar8 = uVar8 & 0xfffffffc | 2;
        }
        if (((byte)uVar8 & 0xc) == 4) {
          uVar8 = uVar8 & 0xfffffff3 | 8;
        }
        if (((byte)uVar8 & 0x30) == 0x10) {
          uVar8 = uVar8 & 0xffffffcf | 0x20;
        }
      }
      else if ((auStack_2400[uVar10] == 0x1909) && (((byte)uVar8 & 0xc0) == 0x40)) {
        uVar8 = uVar8 | 0xc0;
      }
      goto code_r0x000c9c2d;
    }
    goto code_r0x000c9123;
  case 0x5e:
    if (bVar5) {
      local_24 = (uint *)((int (*)())FUN_000c5876)();
      bVar5 = false;
      puVar18 = local_20;
    }
    uVar8 = *puVar18;
    puVar9 = puVar18 + 1;
    uVar10 = uVar8 >> 0x10 & 0xff;
    if ((uVar8 & 0x80000000) == 0) {
      uStack_c1d8 = 0;
    }
    else {
      uStack_c1d8 = puVar18[1];
      puVar9 = puVar18 + 2;
    }
    if ((uVar8 & 0x40000000) == 0) {
      uStack_c1d4 = 0;
    }
    else {
      uStack_c1d4 = *puVar9;
      puVar9 = puVar9 + 1;
    }
    uStack_30 = *puVar9;
    puVar19 = puVar9 + 1;
    if ((*puVar9 & 0x400000) != 0) {
      uStack_c23c = puVar9[1];
      puVar19 = puVar9 + 2;
    }
    uStack_48 = *puVar19;
    puVar9 = puVar19 + 1;
    if ((*puVar19 & 0x400000) != 0) {
      uStack_54 = puVar19[1];
      puVar9 = puVar19 + 2;
    }
    uStack_44 = *puVar9;
    local_20 = puVar9 + 1;
    if ((*puVar9 & 0x400000) != 0) {
      uStack_50 = puVar9[1];
      local_20 = puVar9 + 2;
    }
    bVar6 = (byte)(uVar8 >> 0x18) & 0xc;
    bStack_c1cc = (byte)(uVar8 >> 0x10);
    if (bVar6 == 4) {
code_r0x000cae45:
      if (local_2488 << (bStack_c1cc & 0x1f) == 0) {
        uVar20 = 1 << (bStack_c1cc & 0x1f);
        uStack_c1d0 = 0;
      }
      else {
        local_24 = (uint *)((int (*)())FUN_000c4fd8)(uVar10,local_24);
        if ((uStack_30 & 0x400000) == 0) goto code_r0x000c9d1d;
        uStack_3c = uStack_c23c;
        uStack_30 = uStack_30 & 0xffbfffff;
        uVar20 = 1 << (bStack_c1cc & 0x1f);
        uStack_c1d0 = 1;
      }
    }
    else {
      if (bVar6 == 8) {
        uVar20 = 1 << (bStack_c1cc & 0x1f);
        if ((local_2484 & uVar20) != 0) goto code_r0x000cae45;
      }
      else {
code_r0x000c9d1d:
        uVar20 = 1 << (bStack_c1cc & 0x1f);
      }
      uStack_c1d0 = 0;
    }
    *local_24 = uVar8;
    puVar9 = local_24 + 1;
    if ((uVar8 & 0x80000000) != 0) {
      local_24[1] = uStack_c1d8;
      puVar9 = local_24 + 2;
    }
    local_24 = puVar9;
    if ((uVar8 & 0x40000000) != 0) {
      *local_24 = uStack_c1d4;
      local_24 = local_24 + 1;
    }
    *local_24 = uStack_30;
    puVar9 = local_24 + 1;
    if ((uStack_30 & 0x400000) != 0) {
      local_24[1] = uStack_c23c;
      puVar9 = local_24 + 2;
    }
    local_24 = puVar9;
    *local_24 = uStack_48;
    puVar9 = local_24 + 1;
    if ((uStack_48 & 0x400000) != 0) {
      local_24[1] = uStack_54;
      puVar9 = local_24 + 2;
    }
    local_24 = puVar9;
    puVar9 = local_24;
    *local_24 = uStack_44;
    local_24 = local_24 + 1;
    if ((uStack_44 & 0x400000) != 0) {
      puVar9[1] = uStack_50;
      local_24 = puVar9 + 2;
    }
    if (((bVar6 == 4) || ((bVar6 == 8 && ((local_2484 & uVar20) != 0)))) &&
       (local_2488 << (bStack_c1cc & 0x1f) != 0)) {
      local_24 = (uint *)((int (*)())FUN_000c5121)(&uStack_3c,uVar10,uStack_c1d0,local_24);
    }
    puVar9 = local_20;
    if ((local_2488 & uVar20) != 0) {
      *local_24 = 0x47;
      uVar8 = uStack_c23c;
      uVar20 = uStack_30;
      if ((uStack_30 & 0x400000) == 0) {
        uVar20 = uStack_30 | 0x400000;
        uVar8 = 0x55;
      }
      if (auStack_2400[uVar10] == 0x1906) {
        if (((byte)uVar8 & 3) == 1) {
          uVar8 = uVar8 & 0xfffffffc | 2;
        }
        if (((byte)uVar8 & 0xc) == 4) {
          uVar8 = uVar8 & 0xfffffff3 | 8;
        }
        if (((byte)uVar8 & 0x30) == 0x10) {
          uVar8 = uVar8 & 0xffffffcf | 0x20;
        }
      }
      else if ((auStack_2400[uVar10] == 0x1909) && (((byte)uVar8 & 0xc0) == 0x40)) {
        uVar8 = uVar8 | 0xc0;
      }
code_r0x000c9c2d:
      local_24[1] = uVar20;
      local_24[2] = uVar8;
      local_24[3] = uVar20 & 0x3fffff;
      local_24 = local_24 + 4;
      puVar9 = local_20;
    }
    goto code_r0x000c9123;
  }
  local_20 = (uint *)((int (*)())FUN_000c607d)(1,local_c26c);
  puVar9 = local_20;
  goto code_r0x000c9123;
code_r0x000c8d52:
  uVar8 = *puVar19;
  puVar9 = puVar19;
  switch(uVar8 & 0xffff) {
  default:
    goto LAB_000c8f0c;
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
    break;
  case 3:
  case 0xc:
  case 0x13:
  case 0x1f:
  case 0x20:
  case 0x22:
  case 0x23:
  case 0x41:
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x49:
  case 0x4e:
  case 0x52:
  case 0x56:
  case 0x5b:
    break;
  case 6:
  case 0x10:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x4b:
  case 0x53:
    local_20 = puVar19 + 1;
    puVar9 = puVar19 + 1;
    goto code_r0x000c8d44;
  case 7:
  case 0x11:
    goto code_r0x000c9394;
  case 8:
  case 0x32:
    local_20 = puVar19 + 2;
    puVar9 = puVar19 + 2;
    goto code_r0x000c8d44;
  case 9:
  case 0x1d:
    local_20 = puVar19 + 3;
    puVar9 = puVar19 + 3;
    goto code_r0x000c8d44;
  case 10:
  case 0xd:
  case 0x21:
  case 0x2f:
  case 0x3f:
  case 0x40:
  case 100:
    break;
  case 0xf:
    local_20 = puVar19 + (ushort)puVar19[1] + 2;
    puVar9 = puVar19 + (ushort)puVar19[1] + 2;
    goto code_r0x000c8d44;
  case 0x14:
    local_20 = puVar19 + 3;
    puVar9 = puVar19 + 3;
    goto code_r0x000c8d44;
  case 0x15:
    local_20 = puVar19 + 2;
    puVar9 = puVar19 + 2;
    goto code_r0x000c8d44;
  case 0x16:
    local_20 = puVar19 + 1;
    bVar6 = (byte)puVar19[1];
    bVar13 = (byte)(puVar19[1] >> 0x10) & 0x3f;
    ((int (*)())FUN_000c5cb6)(0,0);
    if (bVar13 == 0x16) {
      local_24ac = 1;
    }
    else if (bVar13 == 0x11) {
      local_24f8[2] = local_24f8[2] | 1 << (bVar6 & 0x1f);
    }
    else if (bVar13 == 0xf) {
      local_c1ec = local_c1ec | 1 << (bVar6 & 0x1f);
    }
    else {
      iVar21 = 1;
      if (bVar13 != 0x10) {
        iVar21 = local_2494;
      }
      local_2494 = iVar21;
    }
    goto code_r0x000c93de;
  case 0x18:
    goto code_r0x000c8d44;
  case 0x19:
    bVar6 = (byte)(uVar8 >> 0x1b) & 3;
    if ((bVar6 == 2) || ((bVar6 == 0 && (local_240[uVar8 >> 0x10 & 0xff] == 2)))) {
      local_2380 = local_2380 | 1 << ((byte)(uVar8 >> 0x10) & 0x1f);
    }
    ((int (*)())FUN_000c4e0f)();
    local_20 = local_20 + 1;
    puVar9 = local_20;
    goto code_r0x000c8d44;
  case 0x1a:
    local_20 = puVar19 + 1;
    if ((int)uVar8 < 0) {
      local_20 = puVar19 + 2;
    }
code_r0x000c93de:
    local_20 = local_20 + 1;
    puVar9 = local_20;
    goto code_r0x000c8d44;
  case 0x1c:
    local_20 = puVar19 + 1;
    uVar8 = puVar19[1] >> 0x10 & 0x3f;
    if (uVar8 == 1) {
      uStack_7c = puVar19[2];
      uStack_78 = puVar19[3];
      uStack_74 = puVar19[4];
      uStack_70 = puVar19[5];
      local_20 = puVar19 + 6;
      ((int (*)())FUN_000c4e26)();
      puVar9 = local_20;
    }
    else {
      puVar9 = puVar19 + 1;
      if (uVar8 == 2) {
        uStack_7c = puVar19[2];
        uStack_78 = puVar19[3];
        uStack_74 = puVar19[4];
        uStack_70 = puVar19[5];
        local_20 = puVar19 + 6;
        ((int (*)())FUN_000c4eab)();
        puVar9 = local_20;
      }
    }
    goto code_r0x000c8d44;
  case 0x24:
    local_20 = (uint *)((int (*)())FUN_000c5eed)(local_c26c);
    local_c1f8 = local_c1f8 + 5;
    puVar9 = local_20;
    goto code_r0x000c8d44;
  case 0x34:
    goto code_r0x000c9394;
  case 0x35:
    uStack_60 = puVar19[1];
    local_20 = puVar19 + 2;
    ((int (*)())FUN_000c5df4)();
    puVar9 = local_20;
    goto code_r0x000c8d44;
  case 0x37:
    local_20 = (uint *)((int (*)())FUN_000c5eed)(local_c26c);
    local_2cc = 1;
    puVar9 = local_20;
    goto code_r0x000c8d44;
  case 0x3b:
    break;
  case 0x3e:
code_r0x000c9394:
    local_20 = (uint *)((int (*)())FUN_000c5eed)(local_c26c);
    puVar9 = local_20;
    goto code_r0x000c8d44;
  case 0x5d:
    local_1d8 = local_1d8 + 1;
    local_20 = puVar19 + 2;
    bVar6 = *(byte *)((int)puVar19 + 3);
    if ((((bVar6 & 0xc) == 4) ||
        (((bVar6 & 0xc) == 8 && ((local_2484 & 1 << (*(byte *)((int)puVar19 + 2) & 0x1f)) != 0))))
       && (local_2488 << (*(byte *)((int)puVar19 + 2) & 0x1f) != 0)) {
      local_c1f0 = local_c1f0 + 0x1b;
      local_2484 = local_2484 | 1 << (*(byte *)((int)puVar19 + 2) & 0x1f);
      bVar6 = *(byte *)((int)puVar19 + 3);
    }
    if ((char)bVar6 < '\0') {
      local_20 = puVar19 + 3;
      bVar6 = *(byte *)((int)puVar19 + 3);
    }
    if ((bVar6 & 0x40) != 0) {
      local_20 = local_20 + 1;
    }
    if ((puVar19[1] >> 0x10 & 0x40) != 0) {
      uStack_c228 = *local_20;
      local_20 = local_20 + 1;
    }
    ((int (*)())FUN_000c5cb6)(uStack_c228,puVar19[1] >> 0x16 & 1);
    iVar21 = local_c1f0 + 4;
    if ((local_2488 & 1 << (*(byte *)((int)puVar19 + 2) & 0x1f)) == 0) {
      iVar21 = local_c1f0;
    }
    uStack_3c = *local_20;
    puVar9 = local_20 + 1;
    if ((uStack_3c & 0x400000) != 0) {
      uStack_30 = local_20[1];
      puVar9 = local_20 + 2;
    }
    local_20 = puVar9;
    ((int (*)())FUN_000c5df4)();
    puVar9 = local_20;
    local_c1f0 = iVar21;
    goto code_r0x000c8d44;
  case 0x5e:
    local_1d8 = local_1d8 + 1;
    local_20 = puVar19 + 2;
    bVar6 = *(byte *)((int)puVar19 + 3);
    if ((((bVar6 & 0xc) == 4) ||
        (((bVar6 & 0xc) == 8 && ((local_2484 & 1 << (*(byte *)((int)puVar19 + 2) & 0x1f)) != 0))))
       && (local_2488 << (*(byte *)((int)puVar19 + 2) & 0x1f) != 0)) {
      local_c1f0 = local_c1f0 + 0x1b;
      local_2484 = local_2484 | 1 << (*(byte *)((int)puVar19 + 2) & 0x1f);
      bVar6 = *(byte *)((int)puVar19 + 3);
    }
    if ((char)bVar6 < '\0') {
      local_20 = puVar19 + 3;
      bVar6 = *(byte *)((int)puVar19 + 3);
    }
    if ((bVar6 & 0x40) != 0) {
      local_20 = local_20 + 1;
    }
    if ((puVar19[1] >> 0x10 & 0x40) != 0) {
      uStack_c234 = *local_20;
      local_20 = local_20 + 1;
    }
    ((int (*)())FUN_000c5cb6)(uStack_c234,puVar19[1] >> 0x16 & 1);
    iVar21 = local_c1f0 + 4;
    if ((local_2488 & 1 << (*(byte *)((int)puVar19 + 2) & 0x1f)) == 0) {
      iVar21 = local_c1f0;
    }
    uStack_30 = *local_20;
    puVar9 = local_20 + 1;
    if ((uStack_30 & 0x400000) != 0) {
      uStack_3c = local_20[1];
      puVar9 = local_20 + 2;
    }
    uStack_2c = *puVar9;
    local_20 = puVar9 + 1;
    if ((uStack_2c & 0x400000) != 0) {
      uStack_38 = puVar9[1];
      local_20 = puVar9 + 2;
    }
    ((int (*)())FUN_000c5df4)();
    ((int (*)())FUN_000c5df4)();
    puVar9 = local_20;
    local_c1f0 = iVar21;
    goto code_r0x000c8d44;
  }
  local_20 = (uint *)((int (*)())FUN_000c5eed)(local_c26c);
  puVar9 = local_20;
  goto code_r0x000c8d44;
LAB_000c8f0c:
                    
  _exit(0);
}

/* FUN_000cafc8 @ 0xcafc8 (166 bytes) */
int FUN_000cafc8(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  if ((((((param_1 == 0) || (*(code **)(param_1 + 0x30) == (code *)0x0)) ||
        (*(int *)(param_1 + 0x34) == 0)) ||
       ((*(int *)(param_1 + 0x38) == 0 || (*(int *)(param_1 + 0x40) == 0)))) ||
      ((*(int *)(param_1 + 0x44) == 0 ||
       ((*(int *)(param_1 + 0x48) == 0 || (*(int *)(param_1 + 0x4c) == 0)))))) ||
     ((param_2 == 0 ||
      (iVar1 = (**(code **)(param_1 + 0x30))(*(undefined4 *)(param_1 + 0x2c),0x44), iVar1 == 0)))) {
    iVar1 = 0;
  }
  else {
    FUN_000d93a8(iVar1,param_1);
    iVar2 = FUN_000d9704(iVar1);
    if (iVar2 != 0) {
      FUN_000d973c(iVar1,1);
      (**(code **)(param_1 + 0x34))(*(undefined4 *)(param_1 + 0x2c),iVar1);
      iVar1 = 0;
    }
  }
  return iVar1;
}

/* FUN_000cb076 @ 0xcb076 (70 bytes) */
int FUN_000cb076(param_1)
  undefined4 *param_1;
{
  undefined4 uVar1;
  code *pcVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    uVar1 = param_1[1];
    pcVar2 = (code *)*param_1;
    FUN_000d973c(param_1,1);
    (*pcVar2)(uVar1,param_1);
    return 0;
  }
  return 3;
}

/* FUN_000cb0bc @ 0xcb0bc (23 bytes) */
int FUN_000cb0bc(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    uVar1 = FUN_000d9646();
    return uVar1;
  }
  return 3;
}

/* FUN_000cb0d4 @ 0xcb0d4 (26 bytes) */
int FUN_000cb0d4(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    uVar1 = FUN_000d969e();
    return uVar1;
  }
  return 3;
}

/* FUN_000cb0ee @ 0xcb0ee (14 bytes) */
int FUN_000cb0ee(param_1)
  int param_1;
{
  return -(param_1 == 0) & 3;
}

/* FUN_000cb0fc @ 0xcb0fc (40 bytes) */
int FUN_000cb0fc(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())FUN_000cb280)(param_1,param_2,param_3,&STACKARG(0x10));
  return;
}

/* FUN_000cb124 @ 0xcb124 (33 bytes) */
int FUN_000cb124(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_000cb2dc)(param_1,param_2,&STACKARG(0xc));
  return;
}

/* FUN_000cb146 @ 0xcb146 (47 bytes) */
int FUN_000cb146(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())FUN_000cbd5a)(param_1,param_2,param_3,param_4,&STACKARG(0x14));
  return;
}

/* FUN_000cb176 @ 0xcb176 (33 bytes) */
int FUN_000cb176(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_000cbdc6)(param_1,param_2,&STACKARG(0xc));
  return;
}

/* FUN_000cb198 @ 0xcb198 (9 bytes) */
int FUN_000cb198()
{
  ((int (*)())FUN_000cbe24)();
  return;
}

/* FUN_000cb1a2 @ 0xcb1a2 (38 bytes) */
int FUN_000cb1a2(param_1)
  undefined4 param_1;
{
  switch(param_1) {
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x39:
    return 1;
  case 0x1d:
  case 0x38:
  case 0x3a:
  case 0x3b:
    return 2;
  default:
    return 0;
  case 0x3c:
  case 0x3d:
  case 0x3e:
  case 0x3f:
    return 3;
  }
}

/* FUN_000cb276 @ 0xcb276 (10 bytes) */
int FUN_000cb276()
{
  return 1;
}

/* FUN_000cb280 @ 0xcb280 (35 bytes) */
int FUN_000cb280(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
{
  if (((param_4 != 0) && (param_2 != 0)) && (param_3 != 0)) {
    FUN_000e1300();
    return;
  }
  return;
}

/* FUN_000cb2a4 @ 0xcb2a4 (56 bytes) */
int FUN_000cb2a4(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 *param_2;
  undefined4 param_3;
{
  (*(code *)*param_2)(param_1,"",param_3,&STACKARG(0x10));
  return;
}

/* FUN_000cb2dc @ 0xcb2dc (2685 bytes) */
int FUN_000cb2dc(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  int param_3;
{
  undefined4 *puVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint local_228;
  uint local_224;
  uint local_220;
  undefined1 local_21c [128];
  undefined1 local_19c [128];
  undefined1 local_11c [128];
  undefined1 local_9c [140];
  
  if (param_2 == (int *)0x0) {
    return;
  }
  if (param_3 == 0) {
    return;
  }
  ((int (*)())FUN_000cb2a4)(param_1,param_3,"; ------------- SC_SRCSHADER Dump ------------------\r\n");
  ((int (*)())FUN_000cb2a4)(param_1,param_3,"SC_SHADERSTATE: u32NumIntVSConst = %d\r\n",param_2[3]);
  ((int (*)())FUN_000cb2a4)(param_1,param_3,"SC_SHADERSTATE: u32NumIntPSConst = %d\r\n",param_2[4]);
  uVar5 = param_2[5];
  ((int (*)())FUN_000cb2a4)(param_1,param_3,"SC_SHADERSTATE: u32NumIntGSConst = %d\r\n",uVar5);
  if (((param_2[3] != 0) && (*param_2 != 0)) &&
     (((int (*)())FUN_000cb2a4)(param_1,param_3,"\r\nSC_SHADERSTATE: *** Integer VS Constants",uVar5),
     param_2[3] != 0)) {
    uVar3 = 0;
    do {
      puVar1 = (undefined4 *)(uVar3 * 0x10 + *param_2);
      uVar5 = uVar3;
      ((int (*)())FUN_000cb2a4)(param_1,param_3,
                   "SC_SHADERSTATE: i%d = Count(%d), LoopStart(%d), LoopStep(%d)\r\n",uVar3,*puVar1,
                   puVar1[1],puVar1[2]);
      uVar3 = uVar3 + 1;
    } while (uVar3 < (uint)param_2[3]);
  }
  if ((param_2[4] != 0) &&
     (((int (*)())FUN_000cb2a4)(param_1,param_3,"\r\nSC_SHADERSTATE: *** Integer PS Constants",uVar5),
     param_2[4] != 0)) {
    uVar3 = 0;
    do {
      puVar1 = (undefined4 *)(uVar3 * 0x10 + param_2[1]);
      uVar5 = uVar3;
      ((int (*)())FUN_000cb2a4)(param_1,param_3,
                   "SC_SHADERSTATE: i%d = Count(%d), LoopStart(%d), LoopStep(%d)\r\n",uVar3,*puVar1,
                   puVar1[1],puVar1[2]);
      uVar3 = uVar3 + 1;
    } while (uVar3 < (uint)param_2[4]);
  }
  if ((param_2[5] != 0) &&
     (((int (*)())FUN_000cb2a4)(param_1,param_3,"\r\nSC_SHADERSTATE: *** Integer GS Constants",uVar5),
     param_2[5] != 0)) {
    uVar5 = 0;
    do {
      puVar1 = (undefined4 *)(uVar5 * 0x10 + param_2[2]);
      ((int (*)())FUN_000cb2a4)(param_1,param_3,
                   "SC_SHADERSTATE: i%d = Count(%d), LoopStart(%d), LoopStep(%d)\r\n",uVar5,*puVar1,
                   puVar1[1],puVar1[2]);
      uVar5 = uVar5 + 1;
    } while (uVar5 < (uint)param_2[5]);
  }
  ((int (*)())FUN_000cb2a4)(param_1,param_3,"SC_SHADERSTATE: u32NumBoolVSConst = %d\r\n",param_2[9]);
  ((int (*)())FUN_000cb2a4)(param_1,param_3,"SC_SHADERSTATE: u32NumBoolPSConst = %d\r\n",param_2[10]);
  uVar5 = param_2[0xb];
  ((int (*)())FUN_000cb2a4)(param_1,param_3,"SC_SHADERSTATE: u32NumBoolGSConst = %d\r\n",uVar5);
  if (param_2[9] == 0) goto LAB_000cb4de;
  if (param_2[6] != 0) {
    ((int (*)())FUN_000cb2a4)(param_1,param_3,"\r\nSC_SHADERSTATE: *** Bool VS Constants",uVar5);
    if (param_2[9] == 0) goto LAB_000cb4de;
    uVar3 = 0;
    do {
      if (*(int *)(param_2[6] + uVar3 * 4) == 0) {
        pcVar2 = "FALSE";
      }
      else {
        pcVar2 = "TRUE";
      }
      uVar5 = uVar3;
      ((int (*)())FUN_000cb2a4)(param_1,param_3,"SC_SHADERSTATE: b%d = %s\r\n",uVar3,pcVar2);
      uVar3 = uVar3 + 1;
    } while (uVar3 < (uint)param_2[9]);
    if (param_2[9] == 0) goto LAB_000cb4de;
  }
  if (param_2[7] != 0) {
    ((int (*)())FUN_000cb2a4)(param_1,param_3,"\r\nSC_SHADERSTATE: *** Bool PS Constants",uVar5);
    if (param_2[10] != 0) {
      uVar3 = 0;
      do {
        if (*(int *)(param_2[7] + uVar3 * 4) == 0) {
          pcVar2 = "FALSE";
        }
        else {
          pcVar2 = "TRUE";
        }
        uVar5 = uVar3;
        ((int (*)())FUN_000cb2a4)(param_1,param_3,"SC_SHADERSTATE: b%d = %s\r\n",uVar3,pcVar2);
        uVar3 = uVar3 + 1;
      } while (uVar3 < (uint)param_2[10]);
    }
    if (param_2[9] == 0) goto LAB_000cb4de;
  }
  if ((param_2[8] != 0) &&
     (((int (*)())FUN_000cb2a4)(param_1,param_3,"\r\nSC_SHADERSTATE: *** Bool GS Constants",uVar5),
     param_2[0xb] != 0)) {
    uVar5 = 0;
    do {
      if (*(int *)(param_2[8] + uVar5 * 4) == 0) {
        pcVar2 = "FALSE";
      }
      else {
        pcVar2 = "TRUE";
      }
      ((int (*)())FUN_000cb2a4)(param_1,param_3,"SC_SHADERSTATE: b%d = %s\r\n",uVar5,pcVar2);
      uVar5 = uVar5 + 1;
    } while (uVar5 < (uint)param_2[0xb]);
  }
LAB_000cb4de:
  ((int (*)())FUN_000cb2a4)(param_1,param_3,"SC_SHADERSTATE: u32NumFloatVSConst = %d\r\n",param_2[0xf]);
  ((int (*)())FUN_000cb2a4)(param_1,param_3,"SC_SHADERSTATE: u32NumFloatPSConst = %d\r\n",param_2[0x10]);
  uVar5 = param_2[0x11];
  ((int (*)())FUN_000cb2a4)(param_1,param_3,"SC_SHADERSTATE: u32NumFloatGSConst = %d\r\n",uVar5);
  if (((param_2[0xf] != 0) && (param_2[0xc] != 0)) &&
     (((int (*)())FUN_000cb2a4)(param_1,param_3,"\r\nSC_SHADERSTATE: *** Float VS Constants",uVar5),
     param_2[0xf] != 0)) {
    local_228 = 0;
    do {
      iVar4 = local_228 * 0x10;
      ((char * (*)())FUN_000cbe42)(*(undefined4 *)(param_2[0xc] + iVar4),10,local_9c);
      ((char * (*)())FUN_000cbe42)(*(undefined4 *)(param_2[0xc] + 4 + iVar4),10,local_11c);
      ((char * (*)())FUN_000cbe42)(*(undefined4 *)(param_2[0xc] + 8 + iVar4),10,local_19c);
      ((char * (*)())FUN_000cbe42)(*(undefined4 *)(param_2[0xc] + 0xc + iVar4),10,local_21c);
      uVar5 = local_228;
      ((int (*)())FUN_000cb2a4)(param_1,param_3,"SC_SHADERSTATE: c%d = (%s,%s,%s,%s)\r\n",local_228,local_9c,
                   local_11c,local_19c,local_21c);
      local_228 = local_228 + 1;
    } while (local_228 < (uint)param_2[0xf]);
  }
  if (((param_2[0x10] != 0) && (param_2[0xd] != 0)) &&
     (((int (*)())FUN_000cb2a4)(param_1,param_3,"\r\nSC_SHADERSTATE: *** Float PS Constants",uVar5),
     param_2[0x10] != 0)) {
    local_224 = 0;
    do {
      iVar4 = local_224 * 0x10;
      ((char * (*)())FUN_000cbe42)(*(undefined4 *)(param_2[0xd] + iVar4),10,local_9c);
      ((char * (*)())FUN_000cbe42)(*(undefined4 *)(param_2[0xd] + 4 + iVar4),10,local_11c);
      ((char * (*)())FUN_000cbe42)(*(undefined4 *)(param_2[0xd] + 8 + iVar4),10,local_19c);
      ((char * (*)())FUN_000cbe42)(*(undefined4 *)(param_2[0xd] + 0xc + iVar4),10,local_21c);
      uVar5 = local_224;
      ((int (*)())FUN_000cb2a4)(param_1,param_3,"SC_SHADERSTATE: c%d = (%s,%s,%s,%s)\r\n",local_224,local_9c,
                   local_11c,local_19c,local_21c);
      local_224 = local_224 + 1;
    } while (local_224 < (uint)param_2[0x10]);
  }
  if (((param_2[0x11] != 0) && (param_2[0xe] != 0)) &&
     (((int (*)())FUN_000cb2a4)(param_1,param_3,"\r\nSC_SHADERSTATE: *** Float GS Constants",uVar5),
     param_2[0x11] != 0)) {
    local_220 = 0;
    do {
      iVar4 = local_220 * 0x10;
      ((char * (*)())FUN_000cbe42)(*(undefined4 *)(param_2[0xe] + iVar4),10,local_9c);
      ((char * (*)())FUN_000cbe42)(*(undefined4 *)(param_2[0xe] + 4 + iVar4),10,local_11c);
      ((char * (*)())FUN_000cbe42)(*(undefined4 *)(param_2[0xe] + 8 + iVar4),10,local_19c);
      ((char * (*)())FUN_000cbe42)(*(undefined4 *)(param_2[0xe] + 0xc + iVar4),10,local_21c);
      ((int (*)())FUN_000cb2a4)(param_1,param_3,"SC_SHADERSTATE: c%d = (%s,%s,%s,%s)\r\n",local_220,local_9c,
                   local_11c,local_19c,local_21c);
      local_220 = local_220 + 1;
    } while (local_220 < (uint)param_2[0x11]);
  }
  ((int (*)())FUN_000cb2a4)(param_1,param_3,"u32Copts = 0x%08X",param_2[0x15]);
  ((int (*)())FUN_000cb2a4)(param_1,param_3,"fConstantsAvailable = %d",param_2[0x16],param_2[0x17],param_2[0x18],
               param_2[0x19],param_2[0x1a],param_2[0x1b],param_2[0x1c],param_2[0x1d]);
  ((int (*)())FUN_000cb2a4)(param_1,param_3,"iConstantsAvailable = %d",param_2[0x1e],param_2[0x1f],param_2[0x20],
               param_2[0x21],param_2[0x22],param_2[0x23],param_2[0x24],param_2[0x25]);
  ((int (*)())FUN_000cb2a4)(param_1,param_3,"bConstantsAvailable = %d",param_2[0x26],param_2[0x27],param_2[0x28],
               param_2[0x29],param_2[0x2a],param_2[0x2b],param_2[0x2c],param_2[0x2d]);
  return;
}

/* FUN_000cbd5a @ 0xcbd5a (107 bytes) */
int FUN_000cbd5a(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  if (((param_2 != 0) && (param_5 != 0)) && (*(int *)(param_2 + 0xfc) - 1U < 3)) {
    if (*(int *)(param_2 + 0xf8) == 0) {
      FUN_000cefe8(param_1,param_2,param_3,param_5);
      return;
    }
    if (*(int *)(param_2 + 0xf8) == 1) {
      FUN_000d4e2a(param_1,param_2,param_3,param_5);
      return;
    }
  }
  return;
}

/* FUN_000cbdc6 @ 0xcbdc6 (93 bytes) */
int FUN_000cbdc6(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int param_3;
{
  if (((param_2 != 0) && (param_3 != 0)) && (*(int *)(param_2 + 0xfc) - 1U < 3)) {
    if (*(int *)(param_2 + 0xf8) == 0) {
      FUN_000cefaa(param_1,param_2,param_3);
      return;
    }
    if (*(int *)(param_2 + 0xf8) == 1) {
      FUN_000d4e14(param_1,param_2,param_3);
      return;
    }
  }
  return;
}

/* FUN_000cbe24 @ 0xcbe24 (5 bytes) */
int FUN_000cbe24()
{
  return;
}

