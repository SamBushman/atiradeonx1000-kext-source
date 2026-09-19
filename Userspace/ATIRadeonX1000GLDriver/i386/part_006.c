#include "decls.h"

/* FUN_000496b0 @ 0x496b0 (110 bytes) */
int FUN_000496b0(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined1 *puVar1;
  
  puVar1 = *(undefined1 **)(param_1 + 0x1488);
  if ((puVar1 != (undefined1 *)0x0) &&
     ((0x40 < *(int *)(puVar1 + 0x37dc) || (0x40 < *(int *)(puVar1 + 0x37e0))))) {
    if (param_2 != '\0') {
      *(undefined4 *)(param_1 + 0x1e68) = 0;
      *puVar1 = 0;
      *(undefined4 *)(param_1 + 0x1488) = 0;
    }
    FUN_00083d86(param_1,puVar1);
    return 1;
  }
  return 0;
}

/* FUN_0004971e @ 0x4971e (205 bytes) */
int FUN_0004971e(param_1, param_2)
  int param_1;
  byte *param_2;
{
  byte *pbVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0x13b2) != '\0') {
    iVar2 = 0;
    pbVar1 = param_2 + 6;
    do {
      pbVar1[0x82] = pbVar1[0x82] & 0xc0;
      pbVar1[0x83] = pbVar1[0x83] & 0x1f;
      pbVar1[0x84] = pbVar1[0x84] & 0xc0 | 0x11;
      *(ushort *)(pbVar1 + 0x84) = *(ushort *)(pbVar1 + 0x84) & 0xfe3f | 0xc0;
      pbVar1[-2] = pbVar1[-2] & 0xef;
      *pbVar1 = *pbVar1 & 0xfc;
      iVar2 = iVar2 + 1;
      pbVar1 = pbVar1 + 4;
    } while (iVar2 < (int)(uint)*(byte *)(param_1 + 0x13b2));
  }
  param_2[5] = param_2[5] & 0xf;
  param_2[6] = param_2[6] & 0xfc | 1;
  *(ushort *)(param_2 + 0x88) = *(ushort *)(param_2 + 0x88) & 0xfe3f;
  param_2[0x89] = param_2[0x89] & 0xe1;
  param_2[0x208] = param_2[0x208] & 0x80;
  *(ushort *)(param_2 + 0x208) = *(ushort *)(param_2 + 0x208) & 0xf87f | 0x80;
  *param_2 = *param_2 & 0xf0;
  param_2[0x20c] = 1;
  param_2[0x20d] = 0;
  param_2[0x20e] = 0;
  param_2[0x20f] = 0;
  param_2[0x210] = 0;
  param_2[0x211] = 0;
  param_2[0x212] = 0;
  param_2[0x213] = 0;
  param_2[0x218] = 0;
  param_2[0x219] = 0;
  param_2[0x21a] = 0;
  param_2[0x21b] = 0;
  param_2[0x21c] = 0;
  param_2[0x21d] = 0;
  param_2[0x21e] = 0;
  param_2[0x21f] = 0;
  return;
}

/* FUN_000497eb @ 0x497eb (317 bytes) */
int FUN_000497eb(param_1)
  int param_1;
{
  int iVar1;
  
  FUN_000b432e(param_1,(PTR_DAT_002131c9[(uint)*(byte *)(param_1 + 0x293f) * 0x24 + 0x21] ^ 1) & 1,1
              );
  *(uint *)(*(int *)(param_1 + 0x1e60) + 0x1548) =
       *(uint *)(*(int *)(param_1 + 0x1e60) + 0x1548) & 0xffc0003f | 0x40;
  *(undefined4 *)(*(int *)(param_1 + 0x1e60) + 0x109c) = 1;
  ((int (*)())FUN_0004971e)(param_1,*(int *)(param_1 + 0x1e60) + 0x10f0);
  *(undefined4 *)(param_1 + 0x277c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1e64) = 0;
  *(undefined4 *)(param_1 + 0x1e80) = 0;
  *(undefined4 *)(param_1 + 0x1e84) = 0;
  if (0 < *(int *)(param_1 + 0x1e74)) {
    iVar1 = 0;
    do {
      *(undefined1 *)(*(int *)(*(int *)(param_1 + 0x1e7c) + iVar1 * 4) + 0x10ed) = 0;
      *(undefined1 *)(*(int *)(*(int *)(param_1 + 0x1e7c) + iVar1 * 4) + 0x10ee) = 0;
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x1e74));
  }
  *(undefined4 *)(param_1 + 0x1e74) = 0;
  if (*(int *)(param_1 + 0x1e5c) == 0) {
    *(undefined4 *)(param_1 + 0x1e5c) = *(undefined4 *)(param_1 + 0x1e60);
  }
  *(undefined4 *)(param_1 + 0x1e80) = 0;
  *(undefined4 *)(param_1 + 0x1e84) = 0;
  iVar1 = 1;
  do {
    *(undefined4 *)(param_1 + 0x1e84 + iVar1 * 4) = 0;
    iVar1 = iVar1 + 1;
  } while (iVar1 != 9);
  return;
}

/* FUN_00049928 @ 0x49928 (1525 bytes) */
int FUN_00049928(param_1)
  int param_1;
{
  float fVar1;
  int *piVar2;
  undefined4 uVar3;
  bool bVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  undefined4 *puVar11;
  int iVar12;
  undefined4 *local_80;
  int local_70;
  int local_6c;
  uint local_68;
  uint local_60;
  int *local_54;
  int local_50;
  int *local_4c;
  int local_48;
  int local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
  piVar2 = *(int **)(param_1 + 0x1e5c);
  piVar2[0x42f] = piVar2[0x42f] & 0xffff00ff;
  uVar9 = (uint)*(byte *)(param_1 + 0x13b2);
  if ((uint)*(byte *)(param_1 + 0x2b) <= (uint)*(byte *)(param_1 + 0x13b2)) {
    uVar9 = (uint)*(byte *)(param_1 + 0x2b);
  }
  if (uVar9 == 0) {
    bVar4 = false;
  }
  else {
    local_68 = 0;
    bVar4 = false;
    iVar12 = param_1;
    do {
      iVar10 = *(int *)(iVar12 + 0x13f8);
      if (((iVar10 != 0) && (*(short *)(iVar10 + 0x38) == 0x1902)) &&
         (fVar1 = *(float *)(iVar10 + 0x50), fVar1 != 0.0)) {
        if ((int)local_68 < 0) {
          iVar5 = (int)(local_68 + 3) >> 2;
          local_60 = iVar5 + 0x10;
          iVar10 = iVar5 + -1;
          if (iVar10 == 0) goto LAB_00049e37;
        }
        else {
          iVar5 = (int)local_68 >> 2;
          local_60 = iVar5 + 0x10;
          iVar10 = iVar5 + -1;
          if (iVar5 == 1) {
LAB_00049e37:
            iVar10 = FUN_0004951b(fVar1);
            piVar2[local_60 * 4 + 0x25] = iVar10;
            uVar8 = local_60 >> 5;
            (*(unsigned char *)((unsigned char *)&(local_60) + 0)) = (byte)local_60 & 0x1f;
            piVar2[uVar8 + 0x42f] = piVar2[uVar8 + 0x42f] | 1 << (byte)local_60;
            bVar4 = true;
            goto LAB_00049a64;
          }
        }
        if (SBORROW4(iVar5,1) == iVar10 < 0) {
          if (iVar5 == 2) {
            iVar10 = FUN_0004951b(fVar1);
            piVar2[local_60 * 4 + 0x26] = iVar10;
          }
          else if (iVar5 == 3) {
            iVar10 = FUN_0004951b(fVar1);
            piVar2[local_60 * 4 + 0x27] = iVar10;
          }
        }
        else if (iVar5 == 0) {
          iVar10 = FUN_0004951b(fVar1);
          piVar2[local_60 * 4 + 0x24] = iVar10;
        }
        uVar8 = local_60 >> 5;
        (*(unsigned char *)((unsigned char *)&(local_60) + 0)) = (byte)local_60 & 0x1f;
        piVar2[uVar8 + 0x42f] = piVar2[uVar8 + 0x42f] | 1 << (byte)local_60;
        bVar4 = true;
      }
LAB_00049a64:
      local_68 = local_68 + 1;
      iVar12 = iVar12 + 4;
    } while (uVar9 != local_68);
  }
  if (*(char *)(param_1 + 0x121) != '\0') {
    iVar12 = *(int *)(*(int *)(param_1 + 4) + 0x10);
    local_3c = *(undefined4 *)(iVar12 + 0x2de0);
    local_38 = *(undefined4 *)(iVar12 + 0x2de4);
    local_34 = *(undefined4 *)(iVar12 + 0x2de8);
    local_30 = 0;
    local_2c = FLOAT_001c5bdc / (*(float *)(iVar12 + 0x2df8) - *(float *)(iVar12 + 0x2df4));
    local_28 = *(float *)(iVar12 + 0x2df8) * *(float *)(iVar12 + 0x2dfc);
    local_24 = (float)((double)*(float *)(iVar12 + 0x2df0) / DOUBLE_001cf390);
    local_20 = (float)((double)*(float *)(iVar12 + 0x2df0) / DOUBLE_001cf398);
    uVar3 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1e5c) + 0x36c4) + 0x3890);
    (**(code **)(param_1 + 0x1280))(param_1,0,uVar3,uVar3,&local_3c,1,1);
    uVar3 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1e5c) + 0x36c4) + 0x3894);
    (**(code **)(param_1 + 0x1280))(param_1,0,uVar3,uVar3,&local_2c,1,1);
  }
  FUN_000b3654(param_1,*(int *)(param_1 + 0x1e5c) + 0x1788,*(int *)(param_1 + 0x1e5c) + 0x1664);
  uVar9 = (uint)*(byte *)(param_1 + 0x20);
  if (*(byte *)(param_1 + 0x20) != 0) {
    local_40 = 0;
    iVar12 = param_1 + 0x28b4;
    do {
      while ((uVar9 & 1) != 0) {
        (**(code **)(param_1 + 0x1280))(param_1,0,local_40 + 0x14,local_40 + 0x14,iVar12,1,1);
        local_40 = local_40 + 1;
        iVar12 = iVar12 + 0x10;
        uVar9 = uVar9 >> 1;
        if (uVar9 == 0) goto LAB_00049a2a;
      }
      local_40 = local_40 + 1;
      iVar12 = iVar12 + 0x10;
      uVar9 = uVar9 >> 1;
    } while (uVar9 != 0);
  }
LAB_00049a2a:
  if ((bVar4) && (*(undefined1 *)((int)piVar2 + 0x10ef) = 0, piVar2 == *(int **)(param_1 + 0x1e64)))
  {
    if (*(int *)(param_1 + 0x23e0) == 0) {
      local_50 = piVar2[0xdad];
      local_54 = piVar2 + 0x43c;
      piVar6 = piVar2 + 0x424;
      piVar7 = piVar2;
    }
    else {
      local_50 = piVar2[0xdb0];
      local_54 = piVar2 + 0x4c7;
      piVar6 = piVar2 + 0x425;
      piVar7 = piVar2 + 7;
    }
    *(int **)(param_1 + 0x1e64) = piVar2;
    if (*piVar7 == 0) {
      *(int *)(param_1 + 0x2350) = piVar7[1];
      *(undefined4 *)(param_1 + 0x234c) = 1;
      *(int *)(param_1 + 0x2338) = *piVar6;
      *piVar7 = 1;
      *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x100000;
    }
    if (*(char *)((int)piVar2 + 0x10ef) == '\0') {
      iVar10 = 0;
      piVar7 = piVar2;
      iVar12 = param_1;
      do {
        *(int *)(iVar12 + 0x1e88) = piVar7[0x42f];
        iVar10 = iVar10 + 1;
        piVar7 = piVar7 + 1;
        iVar12 = iVar12 + 4;
      } while (iVar10 != 8);
      local_48 = 0;
      local_6c = param_1 + 0x1f30;
      local_70 = 0x90;
      local_4c = piVar2;
      do {
        uVar9 = local_4c[0x42f];
        if (uVar9 != 0) {
          puVar11 = (undefined4 *)((int)piVar2 + local_70);
          local_80 = (undefined4 *)(local_6c + 8);
          iVar12 = local_48;
          do {
            if (((uVar9 & 1) != 0) && ((piVar2[0x437] & 1 << ((byte)iVar12 & 0x1f)) == 0)) {
              *local_80 = *puVar11;
              local_80[1] = puVar11[1];
              local_80[2] = puVar11[2];
              local_80[3] = puVar11[3];
            }
            iVar12 = iVar12 + 1;
            puVar11 = puVar11 + 4;
            local_80 = local_80 + 4;
            uVar9 = uVar9 >> 1;
          } while (uVar9 != 0);
        }
        local_4c = local_4c + 1;
        local_48 = local_48 + 0x20;
        local_70 = local_70 + 0x200;
        local_6c = local_6c + 0x200;
      } while (local_48 != 0x100);
      *(undefined1 *)((int)piVar2 + 0x10ef) = 1;
      *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x40000000;
    }
    if (local_54[0x85] == 0) {
      *(int *)(param_1 + 0x1f2c) = local_54[0x82];
      *(int *)(param_1 + 0x1f30) = *local_54;
      *(byte *)(param_1 + 0x1f30) = *(byte *)(param_1 + 0x1f30) & 0x1f;
      *(int *)(param_1 + 0x1f34) = local_50;
      _memcpy((void *)(param_1 + 0x1ea8),local_54 + 1,local_50 << 2);
      *(int *)(param_1 + 0x1ee8) = local_54[0x22];
      *(int *)(param_1 + 0x1eec) = local_54[0x23];
      *(int *)(param_1 + 0x1ef0) = local_54[0x24];
      *(int *)(param_1 + 0x1ef4) = local_54[0x25];
      *(int *)(param_1 + 0x1ef8) = local_54[0x26];
      *(int *)(param_1 + 0x1efc) = local_54[0x27];
      *(int *)(param_1 + 0x1f00) = local_54[0x28];
      *(int *)(param_1 + 0x1f04) = local_54[0x29];
      local_54[0x85] = 1;
      *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x80000000;
      return;
    }
  }
  return;
}

/* FUN_00049f1d @ 0x49f1d (607 bytes) */
int FUN_00049f1d(param_1, param_2)
  int param_1;
  int param_2;
{
  byte *pbVar1;
  char cVar2;
  undefined1 *puVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = *(int *)(param_1 + 0x276c);
  if (((*(byte *)(param_1 + 0x45) & 0x40) == 0) || (*(int *)(param_1 + 0x1e70) == 0)) {
LAB_00049f58:
    bVar4 = true;
    iVar6 = *(int *)(param_1 + 0x1e5c);
  }
  else {
    if ((*(byte *)(param_1 + 0x46) & 4) == 0) {
      cVar2 = *(char *)(param_1 + 0x1136);
    }
    else {
      cVar2 = *(char *)(param_1 + 0x11d0);
    }
    if (cVar2 != '\0') goto LAB_00049f58;
    bVar4 = false;
    iVar6 = *(int *)(param_1 + 0x1e70);
  }
  *(uint *)(param_1 + 0x23e0) = (uint)(param_2 != 0);
  puVar3 = *(undefined1 **)(iVar6 + 0x36c4);
  if (puVar3 == (undefined1 *)0x0) {
    return;
  }
  if (param_2 == *(int *)(iVar6 + 0x10e8)) {
    if (*(char *)(iVar6 + 0x36c8) == '\0') {
      if (param_2 != 0) goto LAB_00049f95;
      cVar2 = *(char *)(iVar6 + 0x10ed);
    }
    else {
      if (param_2 == 0) goto LAB_00049fca;
      cVar2 = *(char *)(iVar6 + 0x10ee);
    }
    if (cVar2 != '\0') {
      return;
    }
    if (!bVar4) {
      *puVar3 = 0;
      *(undefined1 *)(iVar6 + 0x10ee) = 0;
      *(undefined1 *)(iVar6 + 0x10ed) = 0;
      FUN_00083d86(param_1,*(undefined4 *)(iVar6 + 0x36c4));
      return;
    }
    iVar7 = *(int *)(param_1 + 0x1e5c);
    *(undefined1 *)(iVar7 + 0x10ee) = 0;
    *(undefined1 *)(iVar7 + 0x10ed) = 0;
  }
  else {
    if (param_2 != 0) {
LAB_00049f95:
      if (*(char *)(iVar6 + 0x36c8) == '\0') {
        if (bVar4) {
          FUN_000b4709(param_1,1);
        }
        else {
          FUN_00083a8c(param_1,0,puVar3,puVar3 + 4);
        }
        *(undefined1 *)(iVar6 + 0x36c8) = 1;
      }
    }
LAB_00049fca:
    *(int *)(iVar6 + 0x10e8) = param_2;
    *(int *)(iVar6 + 0x152c) = param_2;
    *(int *)(iVar6 + 0x1300) = param_2;
    if (param_2 == 2) {
      uVar5 = 4;
    }
    else {
      uVar5 = (uint)((char)(*(ushort *)(iVar6 + 0x13e4 + iVar7 * 4) >> 6) + 1U & 0x3f);
    }
    *(uint *)(iVar6 + 0x13e4 + iVar7 * 4) =
         *(uint *)(iVar6 + 0x13e4 + iVar7 * 4) & 0xfffc0fff | uVar5 << 0xc;
    pbVar1 = (byte *)(iVar6 + 0x13e6 + iVar7 * 4);
    *pbVar1 = *pbVar1 | 0xfc;
    if (!bVar4) {
      **(undefined1 **)(iVar6 + 0x36c4) = 0;
      *(undefined1 *)(iVar6 + 0x10ee) = 0;
      *(undefined1 *)(iVar6 + 0x10ed) = 0;
      *(undefined4 *)(param_1 + 0x1e68) = 0;
      FUN_00083d86(param_1,*(undefined4 *)(iVar6 + 0x36c4));
      return;
    }
    iVar7 = *(int *)(param_1 + 0x1e5c);
    *(undefined1 *)(iVar7 + 0x10ee) = 0;
    *(undefined1 *)(iVar7 + 0x10ed) = 0;
    *(undefined4 *)(param_1 + 0x1e68) = 0;
    (**(code **)(param_1 + 0x1334))(param_1,1);
  }
  (**(code **)(param_1 + 0x294c))(param_1,iVar7);
  (**(code **)(param_1 + 0x1330))(param_1,*(undefined4 *)(param_1 + 0x1930));
  *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) & 0x3fefffff;
  return;
}

/* FUN_0004a17c @ 0x4a17c (128 bytes) */
int FUN_0004a17c(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x1448 + param_2 * 4) != 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x1930);
    *(undefined4 *)(param_1 + 0x23e0) = 0;
    **(undefined1 **)(param_1 + 0x1448 + param_2 * 4) = 0;
    (**(code **)(param_1 + 0x1290))(param_1,*(undefined4 *)(param_1 + 0x1448 + param_2 * 4));
    *(byte *)(param_1 + 0x1f2c) = *(byte *)(param_1 + 0x1f2c) & 0x80;
    *(ushort *)(param_1 + 0x1f2c) = *(ushort *)(param_1 + 0x1f2c) & 0xf87f | 0x80;
    (**(code **)(param_1 + 0x1330))(param_1,0xc0100000);
    *(undefined4 *)(param_1 + 0x1930) = uVar1;
  }
  return;
}

/* FUN_0004a1fc @ 0x4a1fc (118 bytes) */
int FUN_0004a1fc(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  do {
    iVar1 = *(int *)(param_1 + 0x1e74);
    if (iVar1 < 1) {
      return;
    }
    while( true ) {
      piVar3 = *(int **)(param_1 + 0x1e7c);
      if (param_2 == *piVar3) {
        iVar2 = 0;
      }
      else {
        iVar2 = 0;
        do {
          iVar2 = iVar2 + 1;
          if (iVar2 == iVar1) {
            return;
          }
        } while (param_2 != piVar3[iVar2]);
      }
      iVar1 = iVar1 + -1;
      *(int *)(param_1 + 0x1e74) = iVar1;
      if (iVar1 == iVar2) {
        return;
      }
      if (iVar1 <= iVar2) break;
      iVar1 = iVar2 * 4;
      while( true ) {
        *(undefined4 *)(iVar1 + (int)piVar3) = ((undefined4 *)(iVar1 + (int)piVar3))[1];
        iVar2 = iVar2 + 1;
        iVar1 = iVar1 + 4;
        if (*(int *)(param_1 + 0x1e74) <= iVar2) break;
        piVar3 = *(int **)(param_1 + 0x1e7c);
      }
      iVar1 = *(int *)(param_1 + 0x1e74);
      if (iVar1 < 1) {
        return;
      }
    }
  } while( true );
}

/* FUN_0004a272 @ 0x4a272 (229 bytes) */
int FUN_0004a272(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  FUN_0004965b(param_1,param_2);
  if ((param_1 != 0) && (iVar1 = *(int *)(param_2 + 0x36c4), iVar1 != 0)) {
    (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar1 + 0xc));
    *(undefined4 *)(iVar1 + 0xc) = 0;
    iVar1 = *(int *)(param_2 + 0x36c4);
    while (iVar2 = *(int *)(param_1 + 0x1e74), 0 < iVar2) {
      piVar4 = *(int **)(param_1 + 0x1e7c);
      if (param_2 == *piVar4) {
        iVar3 = 0;
      }
      else {
        iVar3 = 0;
        do {
          iVar3 = iVar3 + 1;
          if (iVar2 == iVar3) goto LAB_0004a328;
        } while (piVar4[iVar3] != param_2);
      }
      iVar2 = iVar2 + -1;
      *(int *)(param_1 + 0x1e74) = iVar2;
      if (iVar2 == iVar3) break;
      if (iVar3 < iVar2) {
        iVar2 = iVar3 * 4;
        while( true ) {
          *(undefined4 *)(iVar2 + (int)piVar4) = ((undefined4 *)(iVar2 + (int)piVar4))[1];
          iVar3 = iVar3 + 1;
          iVar2 = iVar2 + 4;
          if (*(int *)(param_1 + 0x1e74) <= iVar3) break;
          piVar4 = *(int **)(param_1 + 0x1e7c);
        }
      }
    }
LAB_0004a328:
    (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0x36c4));
    if (param_2 != iVar1 + 0x130) {
      *(undefined4 *)(param_2 + 0x36c4) = 0;
    }
  }
  return;
}

/* FUN_0004a357 @ 0x4a357 (192 bytes) */
int FUN_0004a357(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  undefined4 local_10;
  
  if (*(short *)(param_1 + 0x1e6c) != 0) {
    local_10 = 0;
    iVar2 = 0;
    do {
      iVar1 = iVar2 + *(int *)(param_1 + 0x1e60);
      *(undefined4 *)(iVar1 + 0x1784) = 0;
      ((int (*)())FUN_0004a272)(param_1,iVar1);
      local_10 = local_10 + 1;
      iVar2 = iVar2 + 0x3760;
    } while (local_10 < (int)(uint)*(ushort *)(param_1 + 0x1e6c));
  }
  _free(*(void **)(param_1 + 0x1e60));
  _memset(*(void **)(param_1 + 0x1114),0xff,(uint)*(ushort *)(param_1 + 0x1110) * 2);
  *(undefined2 *)(param_1 + 0x1e6c) = 0;
  *(undefined4 *)(param_1 + 0x1e80) = 0;
  *(undefined4 *)(param_1 + 0x1e84) = 0;
  *(undefined4 *)(param_1 + 0x1e60) = 0;
  *(undefined4 *)(param_1 + 0x1e5c) = 0;
  return;
}

/* FUN_0004a417 @ 0x4a417 (328 bytes) */
int FUN_0004a417(param_1)
  int param_1;
{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar1 = *(int *)(param_1 + 0x112c);
  ((int (*)())FUN_0004a357)(param_1);
  *(undefined2 *)(param_1 + 0x1e6c) = 1;
  pvVar2 = _malloc(0x3760);
  *(void **)(param_1 + 0x1e60) = pvVar2;
  _memset(pvVar2,0,0x3760);
  *(undefined4 *)(param_1 + 0x1e5c) = 0;
  ((int (*)())FUN_000497eb)(param_1);
  *(undefined2 *)(*(int *)(param_1 + 0x1e60) + 0x15cc) = 0xffff;
  FUN_000b42eb(param_1);
  iVar4 = *(int *)(param_1 + 0x1154);
  iVar3 = *(int *)(iVar4 + 0x88);
  if ((iVar3 != 0) && (*(int *)(iVar4 + 4) != 0)) {
    uVar5 = 0;
    do {
      iVar3 = *(int *)(*(int *)(uVar5 * 0x78 + 0x70 + iVar3) + *(int *)(param_1 + 0x113c) * 4);
      if (iVar3 != 0) {
        *(undefined1 *)(iVar3 + 0x119) = 1;
      }
      do {
        uVar5 = uVar5 + 1;
        if (*(uint *)(iVar4 + 4) <= uVar5) goto LAB_0004a4b2;
        iVar3 = *(int *)(iVar4 + 0x88);
      } while (iVar3 == 0);
    } while( true );
  }
LAB_0004a4b2:
  if (*(int *)(iVar1 + 4) != 0) {
    uVar5 = 0;
    iVar4 = 0;
    do {
      while (((iVar3 = iVar4 + *(int *)(iVar1 + 8), *(int *)(iVar3 + 4) != 0x8804 ||
              (iVar3 = *(int *)(*(int *)(iVar3 + 0x14) + 0x70), iVar3 == 0)) ||
             (iVar3 = *(int *)(iVar3 + *(int *)(param_1 + 0x1130) * 4), iVar3 == 0))) {
        uVar5 = uVar5 + 1;
        iVar4 = iVar4 + 0x18;
        if (*(uint *)(iVar1 + 4) <= uVar5) {
          return;
        }
      }
      *(undefined1 *)(iVar3 + 0x119) = 1;
      uVar5 = uVar5 + 1;
      iVar4 = iVar4 + 0x18;
    } while (uVar5 < *(uint *)(iVar1 + 4));
  }
  return;
}

/* FUN_0004a55f @ 0x4a55f (542 bytes) */
int FUN_0004a55f(param_1, param_2)
  int param_1;
  int param_2;
{
  ushort *puVar1;
  ushort uVar2;
  int iVar3;
  uint *puVar4;
  void *pvVar5;
  uint *puVar6;
  uint *puVar7;
  ushort uVar8;
  int iVar9;
  uint uVar10;
  byte bVar11;
  uint *puVar12;
  uint *local_30;
  ushort local_1a;
  uint local_14;
  
  iVar3 = *(int *)(param_1 + 0x1e60);
  uVar2 = *(ushort *)(param_1 + 0x1110);
  if (uVar2 != 0x2811) {
    uVar8 = 0x2811;
    if ((ushort)(uVar2 + param_2) < 0x2812) {
      uVar8 = uVar2 + param_2;
    }
    *(ushort *)(param_1 + 0x1110) = uVar8;
    pvVar5 = (void *)(**(code **)(param_1 + 0xc))((uint)uVar8 * 2);
    _memset(pvVar5,0xff,(uint)*(ushort *)(param_1 + 0x1110) * 2);
    if (uVar2 == 0) {
      iVar9 = *(int *)(param_1 + 0x1114);
    }
    else {
      local_14 = 0;
      iVar9 = *(int *)(param_1 + 0x1114);
      do {
        local_1a = *(ushort *)(iVar9 + local_14 * 2);
        if (local_1a != 0xffff) {
          do {
            iVar9 = (uint)local_1a * 0x3760 + iVar3;
            puVar6 = (uint *)(iVar9 + 0x1548);
            puVar12 = (uint *)(iVar9 + 0x15cc);
            if (puVar12 < (uint *)(iVar9 + 0x1574)) {
              uVar10 = 0;
            }
            else {
              uVar10 = 0;
              puVar7 = puVar6;
              puVar4 = (uint *)(iVar9 + 0x1574);
              do {
                puVar6 = puVar4;
                uVar10 = uVar10 ^ *puVar7 ^ (puVar7[1] >> 0x1d | puVar7[1] << 3) ^
                         (puVar7[2] >> 0x1a | puVar7[2] << 6) ^ (puVar7[3] >> 0x17 | puVar7[3] << 9)
                         ^ (puVar7[4] >> 0x14 | puVar7[4] << 0xc) ^
                         (puVar7[5] >> 0x11 | puVar7[5] << 0xf) ^
                         (puVar7[6] >> 0xe | puVar7[6] << 0x12) ^
                         (puVar7[7] >> 0xb | puVar7[7] << 0x15) ^
                         (puVar7[8] >> 8 | puVar7[8] << 0x18) ^ (puVar7[9] >> 5 | puVar7[9] << 0x1b)
                         ^ (puVar7[10] >> 2 | puVar7[10] << 0x1e);
                puVar7 = puVar6;
                puVar4 = puVar6 + 0xb;
              } while (puVar6 + 0xb <= puVar12);
            }
            local_30 = puVar6 + 5;
            if (puVar12 < local_30) {
              bVar11 = 0;
              local_30 = puVar6;
            }
            else {
              uVar10 = uVar10 ^ *puVar6 ^ (puVar6[1] >> 0x1d | puVar6[1] << 3) ^
                       (puVar6[2] >> 0x1a | puVar6[2] << 6) ^ (puVar6[3] >> 0x17 | puVar6[3] << 9) ^
                       (puVar6[4] >> 0x14 | puVar6[4] << 0xc);
              bVar11 = 0xf;
            }
            for (; local_30 < puVar12; local_30 = local_30 + 1) {
              uVar10 = uVar10 ^ (*local_30 << (bVar11 & 0x1f) | *local_30 >> 0x20 - (bVar11 & 0x1f))
              ;
              bVar11 = bVar11 + 3;
            }
            uVar8 = *(ushort *)(iVar9 + 0x15cc);
            puVar1 = (ushort *)((int)pvVar5 + (uVar10 % (uint)*(ushort *)(param_1 + 0x1110)) * 2);
            *(ushort *)(iVar9 + 0x15cc) = *puVar1;
            *puVar1 = local_1a;
            local_1a = uVar8;
          } while (uVar8 != 0xffff);
          iVar9 = *(int *)(param_1 + 0x1114);
        }
        local_14 = local_14 + 1;
      } while (local_14 < uVar2);
    }
    (**(code **)(param_1 + 0x18))(iVar9);
    *(void **)(param_1 + 0x1114) = pvVar5;
  }
  return;
}

/* FUN_0004a77d @ 0x4a77d (1343 bytes) */
int FUN_0004a77d(param_1)
  int param_1;
{
  ushort uVar1;
  uint *puVar2;
  undefined1 uVar3;
  void *pvVar4;
  uint *puVar5;
  byte bVar6;
  uint *puVar7;
  uint uVar8;
  uint *puVar9;
  short *psVar10;
  int iVar11;
  uint *puVar12;
  uint uVar13;
  uint *local_50;
  ushort local_32;
  int local_30;
  uint local_2c;
  uint local_14;
  
  puVar7 = (uint *)(param_1 + 0x18a4);
  if (*(byte *)(param_1 + 0x2b) < 9) {
    local_2c = (uint)*(byte *)(param_1 + 0x2b) * 2 + 1;
  }
  else {
    local_2c = 0x11;
  }
  if (*(char *)(param_1 + 0x1112) == '\0') {
    puVar9 = (uint *)(param_1 + 0x18e8);
    if (puVar9 < (uint *)(param_1 + 0x18d0)) {
      uVar8 = 0;
      local_50 = (uint *)(param_1 + 0x18b8);
      puVar12 = puVar7;
      if (puVar9 < local_50) goto LAB_0004a988;
LAB_0004a9dc:
      uVar8 = uVar8 ^ *puVar12 ^ (puVar12[1] >> 0x1d | puVar12[1] << 3) ^
              (puVar12[2] >> 0x1a | puVar12[2] << 6) ^ (puVar12[3] >> 0x17 | puVar12[3] << 9) ^
              (puVar12[4] >> 0x14 | puVar12[4] << 0xc);
      bVar6 = 0xf;
    }
    else {
      uVar8 = 0;
      puVar5 = puVar7;
      puVar2 = (uint *)(param_1 + 0x18d0);
      do {
        puVar12 = puVar2;
        uVar8 = uVar8 ^ *puVar5 ^ (puVar5[1] >> 0x1d | puVar5[1] << 3) ^
                (puVar5[2] >> 0x1a | puVar5[2] << 6) ^ (puVar5[3] >> 0x17 | puVar5[3] << 9) ^
                (puVar5[4] >> 0x14 | puVar5[4] << 0xc) ^ (puVar5[5] >> 0x11 | puVar5[5] << 0xf) ^
                (puVar5[6] >> 0xe | puVar5[6] << 0x12) ^ (puVar5[7] >> 0xb | puVar5[7] << 0x15) ^
                (puVar5[8] >> 8 | puVar5[8] << 0x18) ^ (puVar5[9] >> 5 | puVar5[9] << 0x1b) ^
                (puVar5[10] >> 2 | puVar5[10] << 0x1e);
        puVar5 = puVar12;
        puVar2 = puVar12 + 0xb;
      } while (puVar12 + 0xb <= puVar9);
      local_50 = puVar12 + 5;
      if (local_50 <= puVar9) goto LAB_0004a9dc;
LAB_0004a988:
      bVar6 = 0;
      local_50 = puVar12;
    }
    for (; local_50 < puVar9; local_50 = local_50 + 1) {
      uVar8 = uVar8 ^ (*local_50 << (bVar6 & 0x1f) | *local_50 >> 0x20 - (bVar6 & 0x1f));
      bVar6 = bVar6 + 3;
    }
    uVar8 = uVar8 % (uint)*(ushort *)(param_1 + 0x1110);
  }
  else {
    uVar8 = (uint)(*(int *)(param_1 + 0x18a8) + *(int *)(param_1 + 0x18b0) +
                   *(int *)(param_1 + 0x18b8) + *(int *)(param_1 + 0x18c0)) %
            (uint)*(ushort *)(param_1 + 0x1110);
  }
  *(undefined4 *)(param_1 + 0x277c) = 0xffffffff;
  uVar1 = *(ushort *)(*(int *)(param_1 + 0x1114) + uVar8 * 2);
  if (uVar1 == 0xffff) {
    uVar13 = 0xffffffff;
    local_30 = 0;
  }
  else {
    local_30 = 0;
    do {
      local_32 = uVar1;
      iVar11 = *(int *)(param_1 + 0x1e60) + (uint)local_32 * 0x3760;
      local_30 = local_30 + 1;
      if ((*puVar7 == *(uint *)(iVar11 + 0x1548) &&
          *(int *)(param_1 + 0x18a8) == *(int *)(iVar11 + 0x154c)) &&
          *(int *)(param_1 + 0x18ac) == *(int *)(iVar11 + 0x1550)) {
        if (local_2c < 4) {
LAB_0004a8e1:
          *(int *)(param_1 + 0x1e5c) = iVar11;
          return 1;
        }
        if (*(int *)(iVar11 + 0x1554) == *(int *)(param_1 + 0x18b0) &&
            *(int *)(iVar11 + 0x1558) == *(int *)(param_1 + 0x18b4)) {
          local_14 = 3;
          do {
            local_14 = local_14 + 2;
            if (local_2c <= local_14) goto LAB_0004a8e1;
            puVar9 = (uint *)(local_14 * 4 + iVar11 + 0x1548);
          } while (*puVar9 == puVar7[local_14] && (puVar7 + local_14)[1] == puVar9[1]);
        }
      }
      uVar1 = *(ushort *)(iVar11 + 0x15cc);
    } while (*(ushort *)(iVar11 + 0x15cc) != 0xffff);
    uVar13 = (uint)local_32;
  }
  if ((*(char *)(param_1 + 0x1112) == '\0') || (local_30 < 7)) {
    if ((local_30 < 8) || (0x2810 < *(ushort *)(param_1 + 0x1110))) {
      if (0x400 < *(ushort *)(param_1 + 0x1e6c)) {
        ((int (*)())FUN_0004a357)(param_1);
        *(undefined2 *)(param_1 + 0x1e6c) = 1;
        pvVar4 = _malloc(0x3760);
        *(void **)(param_1 + 0x1e60) = pvVar4;
        _memset(pvVar4,0,0x3760);
        ((int (*)())FUN_000497eb)(param_1);
        *(undefined2 *)(*(int *)(param_1 + 0x1e60) + 0x15cc) = 0xffff;
        uVar13 = 0;
      }
      *(short *)(param_1 + 0x1e6c) = *(short *)(param_1 + 0x1e6c) + 1;
      if (*(int *)(param_1 + 0x1e68) != 0) {
        *(undefined1 *)(*(int *)(param_1 + 0x1e68) + 0x10ed) = 0;
        *(undefined1 *)(*(int *)(param_1 + 0x1e68) + 0x10ee) = 0;
        *(undefined1 *)(*(int *)(param_1 + 0x1e68) + 0x10ef) = 0;
        *(undefined4 *)(param_1 + 0x1e68) = 0;
      }
      if (0 < *(int *)(param_1 + 0x1e74)) {
        iVar11 = 0;
        do {
          *(undefined1 *)(*(int *)(*(int *)(param_1 + 0x1e7c) + iVar11 * 4) + 0x10ed) = 0;
          *(undefined1 *)(*(int *)(*(int *)(param_1 + 0x1e7c) + iVar11 * 4) + 0x10ee) = 0;
          iVar11 = iVar11 + 1;
        } while (iVar11 < *(int *)(param_1 + 0x1e74));
      }
      *(undefined4 *)(param_1 + 0x1e74) = 0;
      pvVar4 = _realloc(*(void **)(param_1 + 0x1e60),(uint)*(ushort *)(param_1 + 0x1e6c) * 0x3760);
      *(void **)(param_1 + 0x1e60) = pvVar4;
      if (pvVar4 != (void *)0x0) {
        *(uint *)(param_1 + 0x1e5c) =
             (int)pvVar4 + (uint)*(ushort *)(param_1 + 0x1e6c) * 0x3760 + -0x3760;
        psVar10 = (short *)(uVar8 * 2 + *(int *)(param_1 + 0x1114));
        if (*psVar10 == -1) {
          *psVar10 = *(short *)(param_1 + 0x1e6c) + -1;
        }
        else {
          *(short *)((uVar13 & 0xffff) * 0x3760 + 0x15cc + (int)pvVar4) =
               *(short *)(param_1 + 0x1e6c) + -1;
        }
        _memset(*(void **)(param_1 + 0x1e5c),0,0x3760);
        *(undefined2 *)(*(int *)(param_1 + 0x1e5c) + 0x15cc) = 0xffff;
        _memcpy((void *)(*(int *)(param_1 + 0x1e5c) + 0x1548),puVar7,0x84);
      }
      return 0;
    }
    if (*(char *)(param_1 + 0x1112) == '\0') {
      ((int (*)())FUN_0004a55f)();
      goto LAB_0004aa55;
    }
  }
  ((int (*)())FUN_0004a55f)();
  *(undefined1 *)(param_1 + 0x1112) = 0;
LAB_0004aa55:
  uVar3 = ((int (*)())FUN_0004a77d)(param_1);
  return uVar3;
}

/* FUN_0004acbc @ 0x4acbc (395 bytes) */
int FUN_0004acbc(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = *(int *)(param_2 + 0x1e64);
  if (iVar1 != 0) {
    if (*(int *)(param_2 + 0x23e0) == 0) {
      puVar2 = (undefined4 *)(iVar1 + 4);
      iVar3 = iVar1 + 0x10f0;
      uVar4 = *(uint *)(iVar1 + 0x36ac);
    }
    else {
      puVar2 = (undefined4 *)(iVar1 + 0x20);
      iVar3 = iVar1 + 0x131c;
      uVar4 = *(uint *)(iVar1 + 0x36b8);
    }
    *(undefined4 *)(param_1 + 0x250) = *(undefined4 *)(iVar3 + 0x44);
    *(undefined4 *)(param_1 + 600) = *(undefined4 *)(iVar3 + 0x48);
    *(undefined4 *)(param_1 + 0x220) = puVar2[2];
    *(undefined4 *)(param_1 + 0x218) = 0;
    *(undefined4 *)(param_1 + 0x210) = puVar2[3];
    *(undefined4 *)(param_1 + 0x208) = *puVar2;
    *(undefined4 *)(param_1 + 0x200) = puVar2[1];
    if (uVar4 != 0) {
      *(undefined4 *)(param_1 + 0x108) = *(undefined4 *)puVar2[4];
      *(undefined4 *)(param_1 + 0x110) = *(undefined4 *)(puVar2[4] + 4);
      *(undefined4 *)(param_1 + 0x118) = *(undefined4 *)(puVar2[4] + 8);
      *(undefined4 *)(param_1 + 0x120) = *(undefined4 *)(puVar2[4] + 0xc);
      *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(puVar2[4] + 0x10);
      *(undefined4 *)(param_1 + 0x130) = *(undefined4 *)(puVar2[4] + 0x14);
      if (1 < uVar4) {
        *(undefined4 *)(param_1 + 0x138) = *(undefined4 *)(puVar2[4] + 0x18);
        *(undefined4 *)(param_1 + 0x140) = *(undefined4 *)(puVar2[4] + 0x1c);
        *(undefined4 *)(param_1 + 0x148) = *(undefined4 *)(puVar2[4] + 0x20);
        *(undefined4 *)(param_1 + 0x150) = *(undefined4 *)(puVar2[4] + 0x24);
        *(undefined4 *)(param_1 + 0x158) = *(undefined4 *)(puVar2[4] + 0x28);
        *(undefined4 *)(param_1 + 0x160) = *(undefined4 *)(puVar2[4] + 0x2c);
        return;
      }
      goto LAB_0004ae25;
    }
  }
  *(undefined4 *)(param_1 + 0x24c) = 0xc0001000;
  *(undefined4 *)(param_1 + 0x254) = 0xc0001000;
  *(undefined4 *)(param_1 + 0x21c) = 0xc0001000;
  *(undefined4 *)(param_1 + 0x214) = 0xc0001000;
  *(undefined4 *)(param_1 + 0x20c) = 0xc0001000;
  *(undefined4 *)(param_1 + 0x204) = 0xc0001000;
  *(undefined4 *)(param_1 + 0x1fc) = 0xc0001000;
  *(undefined4 *)(param_1 + 0x104) = 0xc00a1000;
LAB_0004ae25:
  *(undefined4 *)(param_1 + 0x134) = 0xc00a1000;
  return;
}

/* FUN_0004ae47 @ 0x4ae47 (5 bytes) */
int FUN_0004ae47()
{
  return;
}

/* FUN_0004ae4c @ 0x4ae4c (25 bytes) */
int FUN_0004ae4c(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0x1e68) = 0;
  FUN_000495a3();
  return;
}

/* FUN_0004ae65 @ 0x4ae65 (38 bytes) */
int FUN_0004ae65(param_1)
  int param_1;
{
  if (*(void **)(param_1 + 0x10) != (void *)0x0) {
    _free(*(void **)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return;
}

/* FUN_0004ae8b @ 0x4ae8b (851 bytes) */
int FUN_0004ae8b(param_1, param_2, param_3)
  uint *param_1;
  int param_2;
  int param_3;
{
  char cVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  byte bVar12;
  uint *puVar13;
  ushort uVar14;
  int iVar15;
  int iVar16;
  uint *puVar17;
  uint uVar18;
  uint uVar19;
  int local_30;
  uint local_28;
  uint *local_24;
  uint local_20;
  int local_14;
  int local_10;
  
  if (param_3 == '\0') {
    local_24 = (uint *)(param_2 + 4);
    iVar15 = param_2 + 0x10f0;
    local_20 = *(uint *)(param_2 + 0x36ac);
    cVar1 = *(char *)(param_2 + 0x10ed);
  }
  else {
    local_24 = (uint *)(param_2 + 0x20);
    iVar15 = param_2 + 0x131c;
    local_20 = *(uint *)(param_2 + 0x36b8);
    cVar1 = *(char *)(param_2 + 0x10ee);
  }
  if (local_20 != 0) {
    if (cVar1 == '\0') {
      iVar16 = iVar15 + 0x44;
      *param_1 = 0x1181;
      param_1[1] = *local_24;
      param_1[2] = 0x1189;
      param_1[3] = local_24[1];
      param_1[4] = 0x1188;
      param_1[5] = 0;
      param_1[6] = 0x118c;
      param_1[7] = local_24[2];
      param_1[8] = 0x118d;
      param_1[9] = local_24[3];
      param_1[10] = 0x118e;
      param_1[0xb] = 0;
      param_1[0xc] = 0x10c1;
      param_1[0xd] = *(uint *)(iVar15 + 0x44);
      param_1[0xe] = (uint)(*(byte *)(iVar15 + 0x44) & 0xf) << 0x10 | 0x10c8;
      param_1 = param_1 + 0xf;
      bVar2 = *(byte *)(iVar15 + 0x44);
      bVar12 = bVar2 & 0xf;
      if (bVar12 == 0) {
        uVar18 = 0;
      }
      else {
        uVar18 = 0;
        puVar13 = param_1;
        do {
          *puVar13 = *(uint *)(iVar16 + 4);
          puVar13[1] = *(uint *)(iVar16 + 8);
          uVar18 = uVar18 + 2;
          puVar13 = puVar13 + 2;
          iVar16 = iVar16 + 8;
        } while (uVar18 < bVar12);
        param_1 = param_1 + uVar18;
      }
      if ((bVar2 & 1) == 0) {
        *param_1 = *(uint *)(iVar15 + 0x48 + uVar18 * 4);
        param_1 = param_1 + 1;
      }
      *param_1 = 0x1094;
      param_1[1] = 0;
      puVar13 = param_1 + 2;
      iVar15 = -(((uint)(param_1 + 3) & 0xf) >> 2);
      iVar16 = iVar15 + 4;
      if (iVar16 != 0) {
        if (iVar16 == 1) {
          uVar18 = 0x80000000;
        }
        else {
          uVar18 = (iVar15 + 2) * 0x10000 | 0xc0001000;
        }
        *puVar13 = uVar18;
      }
      puVar13[iVar16] = (local_20 * 6 + -1) * 0x10000 | 0x9095;
      param_1 = puVar13 + iVar16 + 1;
      puVar13 = (uint *)local_24[4];
      if (0 < (int)local_20 / 2) {
        iVar15 = 0;
        puVar17 = puVar13;
        do {
          uVar18 = puVar17[1];
          uVar19 = puVar17[2];
          uVar3 = puVar17[3];
          uVar4 = puVar17[4];
          uVar5 = puVar17[5];
          uVar6 = puVar17[6];
          uVar7 = puVar17[7];
          uVar8 = puVar17[8];
          uVar9 = puVar17[9];
          uVar10 = puVar17[10];
          uVar11 = puVar17[0xb];
          *param_1 = *puVar17;
          param_1[1] = uVar18;
          param_1[2] = uVar19;
          param_1[3] = uVar3;
          param_1[4] = uVar4;
          param_1[5] = uVar5;
          param_1[6] = uVar6;
          param_1[7] = uVar7;
          param_1[8] = uVar8;
          param_1[9] = uVar9;
          param_1[10] = uVar10;
          param_1[0xb] = uVar11;
          param_1 = param_1 + 0xc;
          puVar13 = puVar13 + 0xc;
          puVar17 = puVar17 + 0xc;
          iVar15 = iVar15 + 1;
        } while ((int)local_20 / 2 != iVar15);
      }
      if ((local_20 & 1) != 0) {
        uVar3 = puVar13[1];
        uVar4 = puVar13[2];
        uVar5 = puVar13[3];
        uVar18 = puVar13[4];
        uVar19 = puVar13[5];
        *param_1 = *puVar13;
        param_1[1] = uVar3;
        param_1[2] = uVar4;
        param_1[3] = uVar5;
        param_1[4] = uVar18;
        param_1[5] = uVar19;
        param_1 = param_1 + 6;
      }
    }
    if (*(char *)(param_2 + 0x10ef) == '\0') {
      local_28 = 0x10000;
      local_14 = param_2;
      local_10 = 0;
      local_30 = 0x90;
      do {
        uVar18 = *(uint *)(local_14 + 0x10bc);
        if (uVar18 != 0) {
          uVar14 = (ushort)local_10;
          puVar13 = (uint *)(param_2 + local_30);
          do {
            if ((uVar18 & 1) != 0) {
              local_28 = local_28 & 0xfffffe00 | (uint)(uVar14 & 0x1ff);
              *param_1 = 0x1094;
              param_1[1] = local_28;
              param_1[2] = 0x39095;
              param_1[3] = *puVar13;
              param_1[4] = puVar13[1];
              param_1[5] = puVar13[2];
              param_1[6] = puVar13[3];
              param_1 = param_1 + 7;
            }
            uVar14 = (uVar14 & 0x1ff) + 1;
            puVar13 = puVar13 + 4;
            uVar18 = uVar18 >> 1;
          } while (uVar18 != 0);
        }
        local_14 = local_14 + 4;
        local_10 = local_10 + 0x20;
        local_30 = local_30 + 0x200;
      } while (local_10 != 0x100);
      uVar18 = *(uint *)(param_2 + 0x374c);
      if (uVar18 != 0) {
        uVar19 = 0x1300;
        iVar15 = param_2;
        do {
          if ((uVar18 & 1) != 0) {
            *param_1 = uVar19;
            param_1[1] = *(uint *)(iVar15 + 0x36cc);
            param_1 = param_1 + 2;
          }
          uVar19 = uVar19 + 1;
          iVar15 = iVar15 + 4;
          uVar18 = uVar18 >> 1;
        } while (uVar18 != 0);
      }
    }
    if (param_3 == '\0') {
      *(undefined1 *)(param_2 + 0x10ed) = 1;
      *(undefined1 *)(param_2 + 0x10ee) = 0;
    }
    else {
      *(undefined1 *)(param_2 + 0x10ed) = 0;
      *(undefined1 *)(param_2 + 0x10ee) = 1;
    }
    *(undefined1 *)(param_2 + 0x10ef) = 1;
    return param_1;
  }
  return param_1;
}

/* FUN_0004b1de @ 0x4b1de (421 bytes) */
int FUN_0004b1de(param_1, param_2)
  int param_1;
  int param_2;
{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 0x1e68);
  if (iVar5 != param_2) {
    if (iVar5 != 0) {
      *(undefined1 *)(iVar5 + 0x10ed) = 0;
      *(undefined1 *)(*(int *)(param_1 + 0x1e68) + 0x10ee) = 0;
      *(undefined1 *)(*(int *)(param_1 + 0x1e68) + 0x10ef) = 0;
    }
    *(undefined1 *)(param_2 + 0x10ed) = 0;
    *(undefined1 *)(param_2 + 0x10ee) = 0;
    *(undefined1 *)(param_2 + 0x10ef) = 0;
  }
  *(int *)(param_1 + 0x1e68) = param_2;
  if ((iVar5 != param_2) && (*(int *)(param_2 + 0x10dc) != 0)) {
    ((int (*)())FUN_0004c845)(param_1);
  }
  if (*(int *)(param_1 + 0x23e0) == 0) {
    cVar1 = *(char *)(param_2 + 0x10ed);
  }
  else {
    cVar1 = *(char *)(param_2 + 0x10ee);
  }
  if ((cVar1 == '\0') || (*(char *)(param_2 + 0x10ef) == '\0')) {
    if ((char)*(int *)(param_1 + 0x23e0) == '\0') {
      iVar4 = param_2 + 0x10f0;
      iVar5 = *(int *)(param_2 + 0x36ac);
    }
    else {
      iVar4 = param_2 + 0x131c;
      iVar5 = *(int *)(param_2 + 0x36b8);
    }
    uVar2 = (**(code **)(param_1 + 0x2758))
                      (param_1,(*(byte *)(iVar4 + 0x44) & 0xf) + 0x910 + iVar5 * 6);
    *(undefined4 *)(param_1 + 0x274c) = uVar2;
    puVar3 = (undefined4 *)((int (*)())FUN_0004ae8b)(uVar2,param_2,*(undefined1 *)(param_1 + 0x23e0));
    *puVar3 = 0x7101d;
    *(undefined4 **)(param_1 + 0x274c) = puVar3 + 1;
    iVar5 = param_1;
    do {
      puVar3 = *(undefined4 **)(param_1 + 0x274c);
      *puVar3 = *(undefined4 *)(iVar5 + 0x1ee8);
      *(undefined4 **)(param_1 + 0x274c) = puVar3 + 1;
      iVar5 = iVar5 + 4;
    } while (param_1 + 0x20 != iVar5);
    puVar3[1] = 0x11ad;
    puVar3[2] = *(undefined4 *)(param_1 + 0x234c);
    puVar3[3] = 0x10c0;
    puVar3[4] = *(undefined4 *)(param_1 + 0x1f2c);
    *(undefined4 **)(param_1 + 0x274c) = puVar3 + 5;
    (**(code **)(param_1 + 0x275c))(param_1,puVar3 + 5);
  }
  *(int *)(param_1 + 0x1e64) = param_2;
  return;
}

/* FUN_0004b383 @ 0x4b383 (1923 bytes) */
int FUN_0004b383(param_1, param_2)
  int param_1;
  int param_2;
{
  byte *pbVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int local_58;
  uint local_54;
  int local_48;
  int local_40;
  int local_3c;
  uint local_34;
  uint local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  
  uVar11 = *(uint *)(param_1 + 0x1b9c);
  local_54 = *(uint *)(param_1 + 0x1ba0);
  iVar4 = *(int *)(param_1 + 0x1bb0);
  if (((*(byte *)(param_1 + 0x45) & 0x40) != 0) &&
     (local_48 = *(int *)(param_1 + 0x1e70), local_48 != 0)) {
    if ((*(byte *)(param_1 + 0x46) & 4) == 0) {
      cVar2 = *(char *)(param_1 + 0x1136);
    }
    else {
      cVar2 = *(char *)(param_1 + 0x11d0);
    }
    if (cVar2 == '\0') {
      uVar10 = (uint)(*(int *)(param_1 + 0x2768) == 0);
      goto LAB_0004b3e3;
    }
  }
  local_48 = *(int *)(param_1 + 0x1e5c);
  uVar10 = 1;
LAB_0004b3e3:
  if (*(int *)(param_1 + 0x23e0) == 0) {
    local_48 = local_48 + 0x10f0;
  }
  else {
    local_48 = local_48 + 0x131c;
  }
  if ((uVar10 == 0) || ((*(byte *)(param_1 + 0x45) & 8) == 0)) {
    local_3c = 0;
  }
  else {
    local_3c = *(int *)(param_1 + 0x1168);
  }
  uVar6 = (uint)((*(uint *)(param_1 + 0x44) & 0x41000) != 0x40000);
  if (((((param_2 != 0) || (local_3c != 0)) || (uVar10 != *(uint *)(local_48 + 0x228))) ||
      ((*(uint *)(local_48 + 0x218) != uVar11 || (*(int *)(local_48 + 0x220) != iVar4)))) ||
     ((*(uint *)(local_48 + 0x21c) != local_54 || (uVar6 != *(uint *)(local_48 + 0x224))))) {
    if ((*(int *)(param_1 + 0x23e0) != 0) && (*(int *)(param_1 + 0x2768) != 0)) {
      local_54 = local_54 & ~(7 << ((char)*(undefined4 *)(param_1 + 0x276c) * '\x03' & 0x1fU));
      *(uint *)(param_1 + 0x1ba0) = local_54;
    }
    *(uint *)(local_48 + 0x218) = uVar11;
    *(uint *)(local_48 + 0x21c) = local_54;
    *(int *)(local_48 + 0x220) = iVar4;
    *(uint *)(local_48 + 0x224) = uVar6;
    bVar3 = *(byte *)(local_48 + 0x228);
    *(byte *)(local_48 + 0x228) = bVar3 & 0xfe | (byte)uVar10;
    *(byte *)(local_48 + 0x228) =
         bVar3 & 0xf8 | (byte)uVar10 | (*(int *)(param_1 + 0x2768) != 0) << 2 |
         (local_3c != 0) * '\x02';
    iVar8 = (uVar11 >> 1 & 1) + (uVar11 >> 2 & 1) + (uVar11 >> 3 & 1) + (uVar11 >> 4 & 1);
    iVar7 = 2;
    if (iVar8 != 4) {
      iVar7 = iVar8;
    }
    if (*(int *)(local_48 + 0x228) == 4) {
      local_58 = local_48;
      uVar11 = 0;
      bVar3 = 0;
      local_1c = 0;
      do {
        iVar8 = *(int *)(param_1 + 0x276c);
        if (iVar8 == local_1c) {
          if (*(int *)(local_48 + 0x210) < 3) {
            local_34 = 0x3e000;
          }
          else {
            local_34 = (uVar11 + 2) * 0x1000;
          }
          *(uint *)(local_48 + 200 + iVar8 * 4) =
               *(uint *)(local_48 + 200 + iVar8 * 4) & 0xff000000 | uVar11 & 0x3f |
               (uVar11 + 1 & 0x3f) << 6 | local_34 & 0x3f000 | 0xfc0000;
          uVar10 = *(uint *)(local_48 + 0x210);
        }
        else {
          *(uint *)(local_58 + 200) =
               *(uint *)(local_58 + 200) & 0xff000000 | uVar11 & 0x3f | (uVar11 + 1 & 0x3f) << 6 |
               (uVar11 + 2 & 0x3f) << 0xc | (uVar11 + 3 & 0x3f) << 0x12;
          uVar10 = local_54 >> (bVar3 & 0x1f) & 7;
        }
        uVar11 = uVar11 + uVar10;
        bVar3 = bVar3 + 3;
        local_1c = local_1c + 1;
        local_58 = local_58 + 4;
      } while (local_1c != 8);
    }
    else if (local_3c == 0) {
      if ((*(int *)(param_1 + 0x23e0) == 0) || (*(int *)(param_1 + 0x2768) == 0)) {
        local_58 = local_48;
        uVar11 = 0;
        iVar8 = 0;
        do {
          *(uint *)(local_58 + 200) =
               *(uint *)(local_58 + 200) & 0xff000000 | uVar11 & 0x3f | (uVar11 + 1 & 0x3f) << 6 |
               (uVar11 + 2 & 0x3f) << 0xc | (uVar11 + 3 & 0x3f) << 0x12;
          uVar11 = uVar11 + (local_54 >> ((byte)iVar8 & 0x1f) & 7);
          iVar8 = iVar8 + 3;
          local_58 = local_58 + 4;
        } while (iVar8 != 0x18);
      }
      else {
        uVar11 = 0;
        bVar3 = 0;
        local_20 = 0;
        iVar8 = local_48;
        do {
          iVar5 = *(int *)(param_1 + 0x276c);
          if (iVar5 == local_20) {
            if (*(int *)(local_48 + 0x210) < 3) {
              local_30 = 0x3e000;
            }
            else {
              local_30 = (uVar11 + 2) * 0x1000;
            }
            *(uint *)(local_48 + 200 + iVar5 * 4) =
                 *(uint *)(local_48 + 200 + iVar5 * 4) & 0xff000000 | uVar11 & 0x3f |
                 (uVar11 + 1 & 0x3f) << 6 | local_30 & 0x3f000 | 0xfc0000;
            uVar10 = *(uint *)(local_48 + 0x210);
          }
          else {
            *(uint *)(iVar8 + 200) =
                 *(uint *)(iVar8 + 200) & 0xff000000 | uVar11 & 0x3f | (uVar11 + 1 & 0x3f) << 6 |
                 (uVar11 + 2 & 0x3f) << 0xc | (uVar11 + 3 & 0x3f) << 0x12;
            uVar10 = local_54 >> (bVar3 & 0x1f) & 7;
          }
          uVar11 = uVar11 + uVar10;
          bVar3 = bVar3 + 3;
          local_20 = local_20 + 1;
          iVar8 = iVar8 + 4;
        } while (local_20 != 8);
      }
    }
    else if (*(int *)(param_1 + 0x23e0) == 0) {
      local_28 = local_3c;
      local_24 = local_48;
      uVar11 = 0;
      local_40 = 0;
      do {
        bVar3 = *(byte *)(local_28 + 0x71);
        if (bVar3 == 0) {
          uVar10 = (uVar11 + 3) * 0x40000;
          uVar9 = (uVar11 + 2) * 0x1000;
        }
        else {
          if ((bVar3 & 4) == 0) {
            uVar9 = 0x3e000;
          }
          else {
            uVar9 = (uVar11 + 2) * 0x1000;
          }
          if ((bVar3 & 8) == 0) {
            uVar10 = 0xfc0000;
          }
          else {
            uVar10 = (uVar11 + 3) * 0x40000;
          }
        }
        *(uint *)(local_24 + 200) =
             *(uint *)(local_24 + 200) & 0xff000000 | uVar11 & 0x3f | (uVar11 + 1 & 0x3f) << 6 |
             uVar9 & 0x3f000 | uVar10 & 0xfc0000;
        uVar11 = uVar11 + (local_54 >> ((byte)local_40 & 0x1f) & 7);
        local_40 = local_40 + 3;
        local_28 = local_28 + 1;
        local_24 = local_24 + 4;
      } while (local_40 != 0x18);
    }
    else {
      local_58 = local_48;
      local_2c = local_3c;
      uVar11 = 0;
      local_18 = 0;
      iVar8 = 0;
      do {
        while( true ) {
          *(uint *)(local_58 + 200) =
               *(uint *)(local_58 + 200) & 0xff000000 | uVar11 & 0x3f | (uVar11 + 1 & 0x3f) << 6 |
               (uVar11 + 2 & 0x3f) << 0xc | (uVar11 + 3 & 0x3f) << 0x12;
          uVar11 = uVar11 + (local_54 >> ((byte)local_18 & 0x1f) & 7);
          local_18 = local_18 + 3;
          bVar3 = *(byte *)(local_2c + 0x71);
          if (bVar3 != 0) {
            if ((bVar3 & 4) == 0) {
              *(uint *)(local_48 + 200 + iVar8 * 4) =
                   *(uint *)(local_48 + 200 + iVar8 * 4) & 0xfffc0fff | 0x3e000;
            }
            if ((bVar3 & 8) == 0) {
              pbVar1 = (byte *)(local_48 + 0xca + iVar8 * 4);
              *pbVar1 = *pbVar1 | 0xfc;
            }
          }
          if (*(int *)(param_1 + 0x276c) != iVar8) break;
          if (*(int *)(local_48 + 0x210) == 2) {
            *(uint *)(local_48 + 200 + iVar8 * 4) =
                 *(uint *)(local_48 + 200 + iVar8 * 4) & 0xfffc0fff | 0x3e000;
          }
          pbVar1 = (byte *)(local_48 + 0xca + iVar8 * 4);
          *pbVar1 = *pbVar1 | 0xfc;
          uVar11 = uVar11 + *(int *)(local_48 + 0x210);
          iVar8 = iVar8 + 1;
          local_58 = local_58 + 4;
          local_2c = local_2c + 1;
          if (local_18 == 0x18) goto LAB_0004b631;
        }
        iVar8 = iVar8 + 1;
        local_58 = local_58 + 4;
        local_2c = local_2c + 1;
      } while (local_18 != 0x18);
    }
LAB_0004b631:
    if ((uVar11 == 0) && (iVar7 == 0)) {
      uVar10 = 0x80;
    }
    else {
      uVar10 = iVar7 << 7;
    }
    uVar11 = uVar11 & 0x7f | uVar10 | 0x40000;
    *(uint *)(local_48 + 0x208) = uVar11;
    *(byte *)(local_48 + 0x8d) = *(byte *)(local_48 + 0x8d) & 0xe1 | (-(uVar6 == 0) & 2U) * '\x02';
    *(byte *)(local_48 + 0xcb) = *(byte *)(local_48 + 0xcb) & 0xf8;
    *(byte *)(local_48 + 0xcf) = *(byte *)(local_48 + 0xcf) & 0xf8 | 1;
    *(uint *)(param_1 + 0x1f2c) = uVar11;
    *(undefined4 *)(param_1 + 0x1ee8) = *(undefined4 *)(local_48 + 200);
    *(undefined4 *)(param_1 + 0x1eec) = *(undefined4 *)(local_48 + 0xcc);
    *(undefined4 *)(param_1 + 0x1ef0) = *(undefined4 *)(local_48 + 0xd0);
    *(undefined4 *)(param_1 + 0x1ef4) = *(undefined4 *)(local_48 + 0xd4);
    *(undefined4 *)(param_1 + 0x1ef8) = *(undefined4 *)(local_48 + 0xd8);
    *(undefined4 *)(param_1 + 0x1efc) = *(undefined4 *)(local_48 + 0xdc);
    *(undefined4 *)(param_1 + 0x1f00) = *(undefined4 *)(local_48 + 0xe0);
    *(undefined4 *)(param_1 + 0x1f04) = *(undefined4 *)(local_48 + 0xe4);
    *(uint *)(param_1 + 0x1ba4) = local_54;
    *(int *)(param_1 + 0x1bb4) = iVar4;
    if ((*(byte *)(param_1 + 0x44) & 4) != 0) {
      *(undefined4 *)(param_1 + 0x277c) = 0xffffffff;
    }
  }
  return;
}

/* FUN_0004bb08 @ 0x4bb08 (625 bytes) */
int FUN_0004bb08(param_1)
  int param_1;
{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  byte bVar8;
  int iVar9;
  
  iVar2 = *(int *)(param_1 + 0x1ae0);
  iVar3 = *(int *)(param_1 + 0x1ab0);
  iVar7 = *(int *)(param_1 + 4);
  iVar4 = *(int *)(iVar7 + 0x10);
  sVar1 = *(short *)(iVar4 + 0x2dc4);
  iVar9 = iVar7 + 0x30;
  if (*(int *)(iVar7 + 0x150) != 0) {
    iVar9 = *(int *)(iVar7 + 0x150);
  }
  if ((((*(char *)(iVar4 + 0x2dc8) == '\0') || (*(char *)(iVar4 + 0x2e44) == '\0')) ||
      (sVar1 == 0x200)) || (sVar1 == 0x202)) {
LAB_0004bb5e:
    bVar5 = false;
  }
  else {
    if (DOUBLE_001cf330 == *(double *)(iVar4 + 0x1830)) {
      if (((DOUBLE_001cf330 == *(double *)(iVar4 + 0x1838)) &&
          (!NAN(DOUBLE_001cf330) && !NAN(*(double *)(iVar4 + 0x1838)))) && (sVar1 == 0x203))
      goto LAB_0004bb5e;
    }
    bVar5 = true;
  }
  if (((*(char *)(iVar9 + 0xc5) == '\0') && (*(char *)(iVar4 + 0x2dc8) != '\0')) &&
     ((*(byte *)(param_1 + 0x46) & 0x40) == 0)) {
    switch(sVar1) {
    case 0x200:
    case 0x201:
    case 0x202:
    case 0x203:
      if ((*(uint *)(iVar9 + 0xc4) & 0xff00ff) == 0) {
        bVar6 = true;
        iVar7 = 0x201;
      }
      else {
        bVar6 = false;
        iVar7 = 0x201;
      }
      break;
    case 0x204:
    case 0x205:
    case 0x206:
      if ((*(char *)(iVar9 + 0xc4) == '\0') && (*(char *)(iVar9 + 0xc6) != '\0')) {
        bVar6 = true;
        iVar7 = 0x204;
      }
      else {
        bVar6 = false;
        iVar7 = 0x204;
      }
      break;
    case 0x207:
      bVar6 = false;
      iVar7 = 0x207;
      break;
    default:
      bVar6 = false;
      iVar7 = 0x200;
    }
    if (((*(int *)(iVar4 + 0x31c0) != 0) &&
        ((((*(short *)(iVar4 + 0x31a2) != 0x1e00 || (*(short *)(iVar4 + 0x31a4) != 0x1e00)) ||
          (*(short *)(iVar4 + 0x31ba) != 0x1e00)) || (*(short *)(iVar4 + 0x31bc) != 0x1e00)))) ||
       (bVar6)) goto LAB_0004bb72;
    if (iVar7 == 0x204) {
      bVar8 = *(byte *)(param_1 + 0x1ae0) | 3;
      *(byte *)(param_1 + 0x1ae0) = bVar8;
      *(byte *)(param_1 + 0x1ab0) = *(byte *)(param_1 + 0x1ab0) | 3;
    }
    else if (iVar7 == 0x207) {
      bVar8 = *(byte *)(param_1 + 0x1ae0) & 0xfe;
      *(byte *)(param_1 + 0x1ae0) = bVar8;
      *(byte *)(param_1 + 0x1ab0) = *(byte *)(param_1 + 0x1ab0) | 1;
    }
    else {
      bVar8 = *(byte *)(param_1 + 0x1ae0) & 0xfd | 1;
      *(byte *)(param_1 + 0x1ae0) = bVar8;
      *(byte *)(param_1 + 0x1ab0) = *(byte *)(param_1 + 0x1ab0) & 0xfd | 1;
    }
    *(byte *)(iVar9 + 0xc6) = (bVar8 >> 1 ^ 1) & 1;
    if (bVar5) {
      *(undefined1 *)(iVar9 + 0xc4) = 0;
    }
  }
  else {
LAB_0004bb72:
    *(byte *)(param_1 + 0x1ae0) = *(byte *)(param_1 + 0x1ae0) & 0xfe;
    *(byte *)(param_1 + 0x1ab0) = *(byte *)(param_1 + 0x1ab0) & 0xfe;
    if (bVar5) {
      *(undefined1 *)(iVar9 + 0xc5) = 1;
      iVar7 = *(int *)(param_1 + 0x1ae0);
      goto joined_r0x0004bbb4;
    }
  }
  iVar7 = *(int *)(param_1 + 0x1ae0);
joined_r0x0004bbb4:
  if ((iVar2 != iVar7) || (iVar3 != *(int *)(param_1 + 0x1ab0))) {
    *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x1000;
  }
  return;
}

/* FUN_0004bd9c @ 0x4bd9c (1142 bytes) */
int FUN_0004bd9c(param_1)
  int param_1;
{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  char cVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  int iVar10;
  
  iVar3 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  iVar10 = *(int *)(param_1 + 0x1a4c);
  iVar4 = *(int *)(param_1 + 0x1e5c);
  if ((((*(byte *)(param_1 + 0x1a80) & 1) == 0) || ((*(byte *)(param_1 + 0x1aa0) & 6) == 6)) ||
     (*(char *)(param_1 + 0x23ed) != '\0')) goto LAB_0004bdf7;
  if (*(char *)(iVar3 + 0x2d66) == '\0') {
    if (((*(short *)(iVar3 + 0x2d80) != -0x7ffa) ||
        (*(int *)(iVar3 + 0x2d68) != *(int *)(iVar3 + 0x2d6c))) ||
       (*(char *)(*(int *)(param_1 + 4) + 0x2b7e) != '\0')) {
LAB_0004bdf7:
      if (*(char *)(iVar3 + 0x2d66) != '\0') goto LAB_0004bfaa;
      goto LAB_0004be04;
    }
    sVar1 = *(short *)(iVar3 + 0x2d68);
    sVar2 = *(short *)(iVar3 + 0x2d6a);
    bVar8 = *(byte *)(param_1 + 0x8d) & 2;
    if (((bVar8 == 0) || (*(char *)(param_1 + 0x2450) == '\0')) ||
       ((*(byte *)(param_1 + 0x8c) & 1) != 0)) {
      bVar5 = false;
    }
    else {
      bVar5 = true;
    }
    if (((bVar8 == 0) || (sVar1 != 0x302)) || (sVar2 != 0x303)) {
      if (bVar5) {
        if (sVar1 == 0) {
          if (sVar2 == 0x301) {
LAB_0004c199:
            if (*(int *)(iVar4 + 0x109c) == 1) {
              if ((*(double *)(iVar3 + 0x1830) != *(double *)(iVar3 + 0x1838)) ||
                 (NAN(*(double *)(iVar3 + 0x1830)) || NAN(*(double *)(iVar3 + 0x1838)))) {
                bVar5 = true;
                goto LAB_0004c1f3;
              }
            }
          }
        }
        else if (((sVar1 == 1) || (sVar1 == 0x306)) && (sVar2 == 1)) goto LAB_0004c199;
      }
      goto LAB_0004bdf7;
    }
    bVar5 = false;
LAB_0004c1f3:
    *(undefined1 *)(param_1 + 0x1a4c) = 0;
    *(byte *)(param_1 + 0x1a4d) = *(byte *)(param_1 + 0x1a4d) & 0xf8 | 0xc;
  }
  else {
LAB_0004bfaa:
    if (*(short *)(iVar3 + 0x2d64) == 0x207) {
LAB_0004be04:
      *(byte *)(param_1 + 0x1a4d) = *(byte *)(param_1 + 0x1a4d) & 0xf7;
      bVar5 = false;
    }
    else {
      *(byte *)(param_1 + 0x1a4d) = *(byte *)(param_1 + 0x1a4d) | 8;
      bVar5 = false;
    }
  }
  if (iVar10 != *(int *)(param_1 + 0x1a4c)) {
    *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x200;
  }
  if (bVar5) {
    *(byte *)(param_1 + 0x18a4) = *(byte *)(param_1 + 0x18a4) | 0x10;
    if ((*(byte *)(iVar4 + 0x1548) & 0x10) == 0) {
LAB_0004bfdb:
      FUN_000b4709(param_1,0);
      (**(code **)(param_1 + 0x1334))(param_1,0);
      (**(code **)(param_1 + 0x294c))(param_1,*(undefined4 *)(param_1 + 0x1e5c));
    }
  }
  else {
    *(byte *)(param_1 + 0x18a4) = *(byte *)(param_1 + 0x18a4) & 0xef;
    if ((*(byte *)(iVar4 + 0x1548) & 0x10) != 0) goto LAB_0004bfdb;
  }
  ((int (*)())FUN_0004bb08)(param_1);
  iVar3 = *(int *)(param_1 + 0x1ab8);
  iVar10 = *(int *)(param_1 + 4);
  *(byte *)(param_1 + 0x1ab8) = *(byte *)(param_1 + 0x1ab8) | 1;
  bVar8 = *(byte *)(param_1 + 0x1aa0);
  if ((((bVar8 & 6) == 6) || (*(char *)(iVar10 + 0x2b7e) != '\0')) ||
     (*(char *)(param_1 + 0x23ed) != '\0')) {
    bVar9 = *(byte *)(param_1 + 0x1a4d);
    if (((bVar9 & 8) == 0) && ((*(ushort *)(param_1 + 0x44) & 0x4006) != 2)) {
      if ((*(char *)(*(int *)(iVar10 + 0x10) + 0x2e2d) != '\0') &&
         ((*(byte *)(param_1 + 0x45) & 0x40) == 0)) {
        cVar6 = FUN_00017bd8(iVar10,*(undefined4 *)(iVar10 + 0x26a0));
        if (cVar6 == '\0') {
          bVar8 = *(byte *)(param_1 + 0x1aa0);
          bVar9 = *(byte *)(param_1 + 0x1a4d);
          goto LAB_0004bed1;
        }
        iVar10 = *(int *)(param_1 + 4);
        bVar8 = *(byte *)(param_1 + 0x1aa0);
        bVar9 = *(byte *)(param_1 + 0x1a4d);
      }
      iVar10 = *(int *)(iVar10 + 0x10);
      if (((((*(char *)(iVar10 + 0x2e2c) == '\0') || ((*(byte *)(param_1 + 0x45) & 0x40) != 0)) ||
           (*(short *)(iVar10 + 0x2e28) == -1)) &&
          (((*(char *)(iVar10 + 0x3178) == '\0' || ((*(byte *)(param_1 + 0x45) & 0x40) != 0)) ||
           ((*(short *)(iVar10 + 0x3170) != 0x1b02 && (*(short *)(iVar10 + 0x3172) != 0x1b02))))))
         && (((*(byte *)(param_1 + 0x1a4e) & 1) == 0 &&
             ((*(uint *)(param_1 + 0x44) & 0x800040) == 0)))) goto LAB_0004bed8;
    }
LAB_0004bed1:
    *(byte *)(param_1 + 0x1ab8) = *(byte *)(param_1 + 0x1ab8) & 0xfe;
  }
  else {
    bVar9 = *(byte *)(param_1 + 0x1a4d);
  }
LAB_0004bed8:
  if ((((bVar9 & 8) != 0) && (*(int *)(param_1 + 0x27b0) == 1)) &&
     ((*(byte *)(param_1 + 0x8d) & 2) != 0)) {
    *(byte *)(param_1 + 0x1ab8) = *(byte *)(param_1 + 0x1ab8) & 0xfe;
  }
  if (((bVar8 & 2) != 0) && ((*(byte *)(param_1 + 0x46) >> 6 & 1) != 0)) {
    *(byte *)(param_1 + 0x1ab8) = *(byte *)(param_1 + 0x1ab8) & 0xfe;
  }
  if (iVar3 != *(int *)(param_1 + 0x1ab8)) {
    *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x20000;
  }
  if (*(int *)(param_1 + 0x23dc) == 1) {
    return;
  }
  bVar8 = *(byte *)(param_1 + 0x1bd4);
  bVar9 = *(byte *)(param_1 + 0x1aa7);
  cVar6 = FUN_00017bd8(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 0x2460));
  if (cVar6 == '\0') {
    if ((*(byte *)(param_1 + 0x1ab8) & 1) == 0) {
      bVar7 = *(byte *)(param_1 + 0x1bd4);
      goto LAB_0004c03c;
    }
    bVar7 = *(byte *)(param_1 + 0x1bd4) | 1;
    *(byte *)(param_1 + 0x1bd4) = bVar7;
    if (*(int *)(param_1 + 0x1af4) == 0) {
      *(byte *)(param_1 + 0x1aa7) = *(byte *)(param_1 + 0x1aa7) | 8;
      goto joined_r0x0004c050;
    }
  }
  else {
    bVar7 = *(byte *)(param_1 + 0x1bd4);
    if ((bVar7 & 1) == 0) goto joined_r0x0004c050;
LAB_0004c03c:
    bVar7 = bVar7 & 0xfe;
    *(byte *)(param_1 + 0x1bd4) = bVar7;
  }
  *(byte *)(param_1 + 0x1aa7) = *(byte *)(param_1 + 0x1aa7) & 0xf7;
joined_r0x0004c050:
  if (((bVar8 & 1) != (bVar7 & 1)) || ((bVar9 >> 3 & 1) != (*(byte *)(param_1 + 0x1aa7) >> 3 & 1)))
  {
    *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x20800;
  }
  return;
}

/* FUN_0004c212 @ 0x4c212 (310 bytes) */
int FUN_0004c212(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_34;
  undefined1 local_d;
  
  if ((*(byte *)(param_1 + 0x45) & 0x40) == 0) {
    FUN_000b4709(param_1,0);
    (**(code **)(param_1 + 0x294c))(param_1,*(undefined4 *)(param_1 + 0x1e5c));
    return;
  }
  if ((*(byte *)(param_1 + 0x46) & 4) != 0) {
    FUN_000aea8d(param_1,0);
    return;
  }
  if ((*(ushort *)(param_1 + 0x44) & 0x801) == 1) {
    if (*(short *)(*(int *)(*(int *)(param_1 + 4) + 0x10) + 0x2d48) == -0x7e06) goto LAB_0004c312;
  }
  else if ((*(byte *)(param_1 + 0x45) & 1) != 0) {
LAB_0004c312:
    local_d = '\x01';
    goto LAB_0004c269;
  }
  local_d = '\0';
LAB_0004c269:
  local_34 = *(int *)(param_1 + 0x1154);
  if (*(int *)(local_34 + 4) != 0) {
    uVar3 = 0;
    iVar2 = 0;
    do {
      iVar1 = *(int *)(*(int *)(*(int *)(local_34 + 0x88) + 0x70 + iVar2) +
                      *(int *)(param_1 + 0x113c) * 4);
      if ((iVar1 != 0) && (local_d != *(char *)(iVar1 + 0x121c))) {
        *(undefined4 *)(iVar1 + 0x1700) = 1;
        *(undefined1 *)(iVar1 + 0x119) = 1;
        local_34 = *(int *)(param_1 + 0x1154);
      }
      uVar3 = uVar3 + 1;
      iVar2 = iVar2 + 0x78;
    } while (uVar3 < *(uint *)(local_34 + 4));
  }
  FUN_000b1aed(param_1);
  return;
}

/* FUN_0004c348 @ 0x4c348 (878 bytes) */
int FUN_0004c348(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  byte bVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  
  iVar1 = *(int *)(param_1 + 4);
  iVar2 = *(int *)(iVar1 + 0x10);
  iVar3 = *(int *)(param_1 + 0x1c8c);
  iVar4 = *(int *)(param_1 + 0x1c88);
  iVar5 = *(int *)(param_1 + 0x1c94);
  iVar6 = *(int *)(param_1 + 0x1c90);
  iVar7 = *(int *)(param_1 + 0x1c9c);
  iVar8 = *(int *)(param_1 + 0x1c98);
  *(undefined4 *)(param_1 + 0x1c9c) = *(undefined4 *)(iVar2 + 0x1818);
  *(undefined4 *)(param_1 + 0x1c98) = *(undefined4 *)(iVar2 + 0x1828);
  fVar13 = *(float *)(iVar1 + 0x2a54);
  fVar12 = *(float *)(iVar1 + 0x2a58);
  fVar16 = (float)*(int *)(iVar2 + 0x184c) * fVar12 * FLOAT_001c5bd4;
  fVar15 = (float)*(int *)(iVar2 + 0x1844) * fVar12 + fVar16;
  fVar14 = (float)*(int *)(iVar2 + 0x1848) * fVar13 * FLOAT_001c5bd4;
  iVar9 = *(int *)(iVar2 + 0x1840);
  if (*(char *)(param_1 + 0x293c) != '\0') {
    fVar16 = (float)((uint)fVar16 ^ _DAT_001c6170);
    fVar15 = (float)*(int *)(iVar1 + 0x160) * fVar12 - fVar15;
  }
  *(float *)(param_1 + 0x1c8c) = fVar14;
  *(float *)(param_1 + 0x1c88) = (float)iVar9 * fVar13 + fVar14;
  *(float *)(param_1 + 0x1c94) = fVar16;
  *(float *)(param_1 + 0x1c90) = fVar15;
  if (*(char *)(param_1 + 0x124) != '\0') {
    *(undefined4 *)(param_1 + 0x1c8c) = *(undefined4 *)(param_1 + 0x2814);
    *(undefined4 *)(param_1 + 0x1c94) = *(undefined4 *)(param_1 + 0x2818);
  }
  *(undefined4 *)(param_1 + 0x1cb0) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x1ca8) = 0x3f800000;
  if (((((iVar3 != *(int *)(param_1 + 0x1c8c)) || (iVar4 != *(int *)(param_1 + 0x1c88))) ||
       (iVar5 != *(int *)(param_1 + 0x1c94))) ||
      ((iVar6 != *(int *)(param_1 + 0x1c90) || (iVar7 != *(int *)(param_1 + 0x1c9c))))) ||
     (iVar8 != *(int *)(param_1 + 0x1c98))) {
    *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x80;
  }
  iVar3 = *(int *)(param_1 + 0x1b14);
  bVar11 = *(byte *)(param_1 + 0x1b14) & 0xf8;
  *(byte *)(param_1 + 0x1b14) = bVar11;
  if (((*(short *)(iVar2 + 0x317c) != 0) || (*(char *)(iVar2 + 0x317b) != '\0')) &&
     ((*(float *)(iVar2 + 0x316c) != 0.0 ||
      ((NAN(*(float *)(iVar2 + 0x316c)) || (*(float *)(iVar2 + 0x3168) != 0.0)))))) {
    if (*(char *)(iVar2 + 0x317b) != '\0') {
      if (*(short *)(iVar2 + 0x3170) == 0x1b00) {
        bVar11 = bVar11 | 1;
        *(byte *)(param_1 + 0x1b14) = bVar11;
      }
      if (*(short *)(iVar2 + 0x3172) == 0x1b00) {
        bVar11 = bVar11 | 2;
        *(byte *)(param_1 + 0x1b14) = bVar11;
      }
    }
    if (*(char *)(iVar2 + 0x317c) != '\0') {
      if (*(short *)(iVar2 + 0x3170) == 0x1b01) {
        bVar11 = bVar11 | 1;
        *(byte *)(param_1 + 0x1b14) = bVar11;
      }
      if (*(short *)(iVar2 + 0x3172) == 0x1b01) {
        bVar11 = bVar11 | 2;
        *(byte *)(param_1 + 0x1b14) = bVar11;
      }
    }
    if (*(char *)(iVar2 + 0x317d) != '\0') {
      if (*(short *)(iVar2 + 0x3170) == 0x1b02) {
        bVar11 = bVar11 | 1;
        *(byte *)(param_1 + 0x1b14) = bVar11;
      }
      if (*(short *)(iVar2 + 0x3172) == 0x1b02) {
        *(byte *)(param_1 + 0x1b14) = bVar11 | 2;
      }
    }
    uVar10 = *(uint *)(param_1 + 8);
    if ((int)uVar10 < 0) {
      fVar13 = (float)uVar10 * *(float *)(iVar2 + 0x3168);
      uVar10 = *(uint *)(iVar1 + 0x154);
    }
    else {
      fVar13 = (float)(int)uVar10 * *(float *)(iVar2 + 0x3168);
      uVar10 = *(uint *)(iVar1 + 0x154);
    }
    fVar12 = FLOAT_001c5c1c;
    if ((uVar10 & 0x30000) != 0x10000) {
      fVar12 = FLOAT_001c5bcc;
    }
    fVar12 = fVar12 * *(float *)(iVar2 + 0x316c);
    *(float *)(param_1 + 0x1b1c) = fVar13;
    *(float *)(param_1 + 0x1b18) = fVar12;
    *(float *)(param_1 + 0x1b24) = fVar13;
    *(float *)(param_1 + 0x1b20) = fVar12;
    *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x20;
  }
  if (iVar3 != *(int *)(param_1 + 0x1b14)) {
    *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x20;
  }
  return;
}

/* FUN_0004c6b6 @ 0x4c6b6 (356 bytes) */
int FUN_0004c6b6(param_1)
  int param_1;
{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  iVar3 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if ((*(char *)(iVar3 + 0x2dc8) == '\0') || (*(char *)(param_1 + 0x1490) == '\0')) {
    *(byte *)(param_1 + 0x1aa0) = *(byte *)(param_1 + 0x1aa0) & 0xfd;
    uVar5 = *(uint *)(param_1 + 0x1930);
  }
  else {
    uVar2 = *(ushort *)(iVar3 + 0x2dc4);
    iVar4 = *(int *)(param_1 + 0x1a50);
    bVar1 = *(byte *)(param_1 + 0x1aa0);
    *(byte *)(param_1 + 0x1aa0) = bVar1 | 2;
    if (uVar2 == 0x202) {
      *(byte *)(param_1 + 0x1aa0) = bVar1 & 0xfb | 2;
    }
    else if ((((uVar2 != 0x203) || (DOUBLE_001cf330 != *(double *)(iVar3 + 0x1830))) ||
             (DOUBLE_001cf330 != *(double *)(iVar3 + 0x1838))) ||
            (NAN(DOUBLE_001cf330) || NAN(*(double *)(iVar3 + 0x1838)))) {
      *(byte *)(param_1 + 0x1aa0) = bVar1 & 0xfb | 2 | (*(byte *)(iVar3 + 0x2e44) & 1) << 2;
    }
    else {
      *(byte *)(param_1 + 0x1aa0) = bVar1 & 0xfb | 2;
    }
    *(byte *)(param_1 + 0x1aa4) =
         *(byte *)(param_1 + 0x1aa4) & 0xf8 | (DAT_001edf40)[(uVar2 & 7) * 4] & 7;
    if ((*(byte *)(param_1 + 0x46) & 0x40) == 0) {
      *(byte *)(param_1 + 0x1a50) = *(byte *)(param_1 + 0x1a50) & 0xfe;
    }
    else {
      *(byte *)(param_1 + 0x1a50) = *(byte *)(param_1 + 0x1a50) | 1;
    }
    if (iVar4 != *(int *)(param_1 + 0x1a50)) {
      uVar5 = *(uint *)(param_1 + 0x1930);
      uVar6 = uVar5 | 0x8000000;
      *(uint *)(param_1 + 0x1930) = uVar6;
      *(uint *)(param_1 + 0x1930) = CONCAT22((short)(uVar6 >> 0x10),(short)uVar5) | 0x800;
      return;
    }
    uVar5 = *(uint *)(param_1 + 0x1930);
  }
  *(uint *)(param_1 + 0x1930) = uVar5 | 0x800;
  return;
}

/* FUN_0004c81a @ 0x4c81a (43 bytes) */
int FUN_0004c81a(param_1)
  int param_1;
{
  if (*(char *)(param_1 + 0x124) != '\0') {
    FUN_0007e10d(param_1);
  }
  *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x40000;
  return;
}

/* FUN_0004c845 @ 0x4c845 (281 bytes) */
int FUN_0004c845(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_14;
  
  if ((*(byte *)(param_1 + 0x45) & 0x40) == 0) {
    uVar2 = (uint)*(byte *)(param_1 + 0x2b);
    if ((uint)*(byte *)(param_1 + 0x13b2) < (uint)*(byte *)(param_1 + 0x2b)) {
      uVar2 = (uint)*(byte *)(param_1 + 0x13b2);
    }
    if (uVar2 != 0) {
      local_14 = 0;
      iVar4 = param_1;
      iVar5 = param_1;
      do {
        *(undefined4 *)(iVar4 + 0x1f38) = *(undefined4 *)(iVar5 + 0x47c);
        *(undefined4 *)(iVar4 + 0x1f3c) = *(undefined4 *)(iVar5 + 0x480);
        *(undefined4 *)(iVar4 + 8000) = *(undefined4 *)(iVar5 + 0x484);
        *(undefined4 *)(iVar4 + 0x1f44) = *(undefined4 *)(iVar5 + 0x488);
        iVar1 = *(int *)(param_1 + 0x1e68);
        if ((iVar1 != 0) && ((*(uint *)(iVar1 + 0x10dc) & 1 << ((byte)local_14 & 0x1f)) != 0)) {
          iVar3 = local_14 * 0x10;
          *(undefined4 *)(iVar3 + 0x90 + iVar1) = *(undefined4 *)(iVar4 + 0x1f38);
          *(undefined4 *)(iVar3 + *(int *)(param_1 + 0x1e68) + 0x94) =
               *(undefined4 *)(iVar4 + 0x1f3c);
          *(undefined4 *)(iVar3 + *(int *)(param_1 + 0x1e68) + 0x98) = *(undefined4 *)(iVar4 + 8000)
          ;
          *(undefined4 *)(iVar3 + *(int *)(param_1 + 0x1e68) + 0x9c) =
               *(undefined4 *)(iVar4 + 0x1f44);
        }
        local_14 = local_14 + 1;
        iVar5 = iVar5 + 0xcc;
        iVar4 = iVar4 + 0x10;
      } while (uVar2 != local_14);
    }
    *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x4000000;
  }
  return;
}

/* FUN_0004c95e @ 0x4c95e (38 bytes) */
int FUN_0004c95e(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *param_2 = 0x110f8;
  param_2[1] = *(undefined4 *)(param_1 + 7000);
  param_2[2] = *(undefined4 *)(param_1 + 0x1b10);
  return param_2 + 3;
}

/* FUN_0004c984 @ 0x4c984 (117 bytes) */
int FUN_0004c984(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *param_2 = 0x50766;
  param_2[1] = *(undefined4 *)(param_1 + 0x1c8c);
  param_2[2] = *(undefined4 *)(param_1 + 0x1c88);
  param_2[3] = *(undefined4 *)(param_1 + 0x1c94);
  param_2[4] = *(undefined4 *)(param_1 + 0x1c90);
  param_2[5] = *(undefined4 *)(param_1 + 0x1c9c);
  param_2[6] = *(undefined4 *)(param_1 + 0x1c98);
  param_2[7] = 0x30888;
  param_2[8] = *(undefined4 *)(param_1 + 0x1ca8);
  param_2[9] = *(undefined4 *)(param_1 + 0x1cac);
  param_2[10] = *(undefined4 *)(param_1 + 0x1cb0);
  param_2[0xb] = *(undefined4 *)(param_1 + 0x1cb4);
  return param_2 + 0xc;
}

/* FUN_0004c9f9 @ 0x4c9f9 (80 bytes) */
int FUN_0004c9f9(param_1)
  int param_1;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
  *(undefined4 **)(param_1 + 0x274c) = puVar1;
  *puVar1 = 0x1040;
  puVar1[1] = 0;
  *(int *)(param_1 + 0x274c) = *(int *)(param_1 + 0x274c) + 8;
                    
                    
  (**(code **)(param_1 + 0x275c))();
  return;
}

/* FUN_0004ca49 @ 0x4ca49 (149 bytes) */
int FUN_0004ca49(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
  undefined4 *param_5;
  int param_6;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined4 *puVar5;
  int iVar6;
  
  if (param_2 == 0) {
    if (((*(byte *)(param_1 + 0x45) & 0x40) == 0) ||
       (param_2 = *(int *)(param_1 + 0x1e70), param_2 == 0)) {
      param_2 = *(int *)(param_1 + 0x1e5c);
    }
  }
  else {
    param_2 = param_2 + 0x130;
  }
  if (0 < param_6) {
    pcVar4 = (char *)(param_4 + 0x2de0 + param_2);
    iVar6 = 0;
    puVar5 = (undefined4 *)(param_4 * 0x10 + 0x90 + param_2);
    do {
      while ((*pcVar4 != '\0' && (pcVar4[0x100] == '\0'))) {
        uVar1 = param_5[1];
        uVar2 = param_5[2];
        uVar3 = param_5[3];
        *puVar5 = *param_5;
        puVar5[1] = uVar1;
        puVar5[2] = uVar2;
        puVar5[3] = uVar3;
        iVar6 = iVar6 + 1;
        puVar5 = puVar5 + 4;
        pcVar4 = pcVar4 + 1;
        param_5 = param_5 + 4;
        if (iVar6 == param_6) goto LAB_0004cab5;
      }
      iVar6 = iVar6 + 1;
      puVar5 = puVar5 + 4;
      pcVar4 = pcVar4 + 1;
      param_5 = param_5 + 4;
    } while (iVar6 != param_6);
  }
LAB_0004cab5:
  *(undefined1 *)(param_2 + 0x10ef) = 0;
  return;
}

/* FUN_0004cade @ 0x4cade (2646 bytes) */
int FUN_0004cade(param_1)
  int param_1;
{
  int *piVar1;
  float *pfVar2;
  ushort *puVar3;
  byte *pbVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  byte bVar9;
  uint uVar10;
  ushort uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  float fVar18;
  int local_58;
  uint local_44;
  int local_40;
  int local_34;
  uint local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  
  uVar11 = *(ushort *)(param_1 + 0x32) | *(ushort *)(param_1 + 0x34);
  local_44 = (uint)uVar11;
  if ((uVar11 != 0) && (*(char *)(param_1 + 0x121) != '\0')) {
    if (*(byte *)(param_1 + 0x13b0) == 0) {
LAB_0004d301:
      *(undefined1 *)(param_1 + 0x120) = 0xff;
    }
    else {
      if (*(int *)(param_1 + 0x48) == 0) {
        uVar10 = 0;
      }
      else {
        uVar10 = 0;
        iVar15 = param_1;
        do {
          uVar10 = uVar10 + 1;
          if (*(byte *)(param_1 + 0x13b0) == uVar10) goto LAB_0004d301;
          piVar1 = (int *)(iVar15 + 0x4c);
          iVar15 = iVar15 + 4;
        } while (*piVar1 != 0);
      }
      *(byte *)(param_1 + 0x120) = (byte)uVar10;
      bVar9 = (byte)uVar10 & 7;
      *(byte *)(param_1 + 0x1879) = *(byte *)(param_1 + 0x1879) & 0xf8 | bVar9;
      *(byte *)(param_1 + 0x18a7) = *(byte *)(param_1 + 0x18a7) & 0xe3 | bVar9 << 2;
    }
  }
  iVar15 = *(int *)(param_1 + 0x1808);
  iVar16 = *(int *)(param_1 + 0x27b4);
  uVar10 = ~(iVar16 << 8) & *(uint *)(param_1 + 0x27b0);
  *(uint *)(param_1 + 0x27b0) = uVar10;
  if (uVar11 != 0) {
    local_2c = param_1;
    local_28 = param_1;
    local_24 = param_1;
    local_20 = param_1;
    local_40 = 0;
    do {
      if ((local_44 & 1) != 0) {
        if (iVar15 == 0) {
          iVar16 = *(int *)(local_20 + 0x13f8);
          if (iVar16 == 0) {
            *(uint *)(param_1 + 0x27b0) =
                 *(uint *)(param_1 + 0x27b0) &
                 (-2 << ((byte)local_40 & 0x1f) | 0xfffffffeU >> 0x20 - ((byte)local_40 & 0x1f));
          }
          else {
            uVar10 = 1 << ((byte)local_40 & 0x1f);
            *(uint *)(param_1 + 0x1934) = *(uint *)(param_1 + 0x1934) | uVar10;
            *(uint *)(param_1 + 0x27b0) = *(uint *)(param_1 + 0x27b0) | uVar10;
            *(undefined4 *)(local_2c + 0x1d5c) = *(undefined4 *)(iVar16 + 0x1c);
            *(undefined4 *)(local_2c + 0x1d9c) = *(undefined4 *)(iVar16 + 0x20);
            *(undefined4 *)(local_2c + 0x1ddc) = *(undefined4 *)(iVar16 + 0x24);
            *(undefined4 *)(param_1 + 0x1e1c + local_40 * 4) = *(undefined4 *)(iVar16 + 0x28);
            *(uint *)(local_2c + 0x1cdc) = *(uint *)(iVar16 + 0x14) & 0xfffffff | local_40 << 0x1c;
            *(uint *)(local_2c + 0x1d1c) =
                 *(uint *)(iVar16 + 0x18) & 0xffffe007 |
                 (*(ushort *)(local_28 + 0x46e) & 0x3ff) << 3;
            FUN_000b50a3(param_1,iVar16,local_40,
                         *(undefined4 *)(&DAT_001ee584 + (uint)*(byte *)(param_1 + 0x2941) * 4));
          }
        }
        else {
          uVar10 = 1 << ((byte)local_40 & 0x1f);
          *(uint *)(param_1 + 0x1934) = *(uint *)(param_1 + 0x1934) | uVar10;
          if ((local_40 == *(int *)(param_1 + 0x276c)) && (*(int *)(param_1 + 0x2768) != 0)) {
            local_34 = *(int *)(*(int *)(param_1 + 0x2768) + 0xbc);
          }
          else {
            local_34 = *(int *)(local_20 + 0x13f8);
            if (local_34 == 0) {
              *(uint *)(param_1 + 0x27b0) = *(uint *)(param_1 + 0x27b0) & ~uVar10;
              *(uint *)(param_1 + 0x27b4) = *(uint *)(param_1 + 0x27b4) & ~uVar10;
              goto LAB_0004cc1b;
            }
          }
          if ((*(byte *)(param_1 + 0x45) & 0x40) == 0) {
            if (((int)(uint)*(byte *)(param_1 + 0x20) >> ((byte)local_40 & 0x1f) & 1U) == 0) {
              *(uint *)(param_1 + 0x27b4) = *(uint *)(param_1 + 0x27b4) & ~uVar10;
              bVar8 = false;
            }
            else {
              iVar12 = *(int *)(local_24 + 0x2854);
              iVar6 = *(int *)(local_24 + 0x2858);
              iVar7 = *(int *)(local_24 + 0x285c);
              iVar13 = local_40 * 0x10;
              iVar16 = param_1 + 0x28b4 + iVar13;
              if (*(char *)(param_1 + 0x21 + local_40) == '\x01') {
                *(float *)(param_1 + 0x28b4 + iVar13) = *(float *)(local_34 + 0x44) / (float)iVar12;
                fVar18 = (float)iVar7;
                *(float *)(iVar16 + 4) = *(float *)(local_34 + 0x44) / fVar18;
                *(float *)(iVar16 + 8) = (float)((uint)(float)iVar6 ^ _DAT_001c6180) / fVar18;
                *(float *)(iVar16 + 0xc) =
                     ((float)(iVar12 + iVar6) * FLOAT_001c5bd4) / *(float *)(local_34 + 0x44);
              }
              else {
                *(float *)(param_1 + 0x28b4 + iVar13) = *(float *)(local_34 + 0x48) / (float)iVar12;
                fVar18 = (float)iVar7;
                *(float *)(iVar16 + 4) = *(float *)(local_34 + 0x48) / fVar18;
                *(float *)(iVar16 + 8) = (float)((uint)(float)iVar6 ^ _DAT_001c6180) / fVar18;
                *(float *)(iVar16 + 0xc) =
                     ((float)(iVar12 + iVar6) * FLOAT_001c5bd4) / *(float *)(local_34 + 0x48);
              }
              ((int (*)())FUN_0004ca49)(param_1,0,local_40 + 0x14,local_40 + 0x14,iVar16,1,0);
              *(uint *)(param_1 + 0x27b4) = *(uint *)(param_1 + 0x27b4) | uVar10;
              bVar8 = false;
            }
          }
          else {
            sVar5 = *(short *)(local_34 + 0x38);
            *(uint *)(*(int *)(param_1 + 0x1144) + 0x2c + local_40 * 4) =
                 (uint)*(byte *)(local_34 + 0x30);
            local_58 = *(int *)(param_1 + 0x1154);
            if (*(int *)(local_58 + 4) != 0) {
              local_30 = 0;
              iVar16 = 0;
              do {
                iVar12 = *(int *)(*(int *)(*(int *)(local_58 + 0x88) + 0x70 + iVar16) +
                                 *(int *)(param_1 + 0x113c) * 4);
                if ((iVar12 != 0) &&
                   ((*(char *)(local_34 + 0x30) == '\x02') !=
                    (bool)*(char *)(local_40 + iVar12 + 0x2ec0))) {
                  *(undefined4 *)(iVar12 + 0x1700) = 1;
                  *(undefined1 *)(iVar12 + 0x119) = 1;
                  local_58 = *(int *)(param_1 + 0x1154);
                }
                local_30 = local_30 + 1;
                iVar16 = iVar16 + 0x78;
              } while (local_30 < *(uint *)(local_58 + 4));
            }
            if ((*(byte *)(param_1 + 0x46) & 4) == 0) {
LAB_0004cfda:
              bVar8 = false;
            }
            else {
              iVar16 = *(int *)(*(int *)(*(int *)(param_1 + 0x121c) + 0x70) +
                               *(int *)(param_1 + 0x1130) * 4);
              if (iVar16 == 0) {
                iVar12 = 0;
              }
              else {
                iVar12 = iVar16 + 0x130;
              }
              if (sVar5 == 0x1902) {
                uVar14 = (uint)*(ushort *)(local_34 + 0x5c) * 2 - 0x400;
                uVar17 = uVar14 | 1;
                if (*(short *)(local_34 + 0x58) == 0x1909) {
                  uVar17 = uVar14 | 0x11;
                }
                else if (*(short *)(local_34 + 0x58) == -0x7fb7) {
                  uVar17 = uVar14 | 0x21;
                }
              }
              else {
                uVar17 = 0;
              }
              if (iVar12 == 0) goto LAB_0004cfda;
              if ((uVar17 != *(uint *)(iVar12 + 0x15d4 + local_40 * 4)) &&
                 (*(undefined4 *)(iVar12 + 0x15d0) = 1, iVar16 != 0)) {
                *(undefined1 *)(iVar16 + 0x119) = 1;
              }
              if (*(char *)(local_40 + 0x1614 + iVar12) == '\0') goto LAB_0004cfda;
              fVar18 = *(float *)(local_34 + 0x4c) + *(float *)(local_28 + 0x470);
              pfVar2 = (float *)(iVar12 + 0x1624 + local_40 * 4);
              if ((fVar18 != *pfVar2) || (NAN(fVar18) || NAN(*pfVar2))) {
                iVar16 = *(int *)(*(int *)(*(int *)(param_1 + 0x121c) + 0x70) +
                                 *(int *)(param_1 + 0x1130) * 4);
                if (iVar16 != 0) {
                  *(undefined1 *)(iVar16 + 0x119) = 1;
                }
                *(undefined4 *)(iVar12 + 0x15d0) = 1;
                bVar8 = true;
              }
              else {
                bVar8 = true;
              }
            }
            *(uint *)(param_1 + 0x27b4) = *(uint *)(param_1 + 0x27b4) & ~uVar10;
          }
          *(uint *)(param_1 + 0x27b0) = *(uint *)(param_1 + 0x27b0) | uVar10;
          *(undefined4 *)(local_2c + 0x1d5c) = *(undefined4 *)(local_34 + 0x1c);
          *(undefined4 *)(local_2c + 0x1d9c) = *(undefined4 *)(local_34 + 0x20);
          *(undefined4 *)(local_2c + 0x1ddc) = *(undefined4 *)(local_34 + 0x24);
          *(undefined4 *)(param_1 + 0x1e1c + local_40 * 4) = *(undefined4 *)(local_34 + 0x28);
          *(uint *)(local_2c + 0x1cdc) =
               *(uint *)(local_34 + 0x14) & 0xfffffff | (uint)((byte)local_40 & 0xf) << 0x1c;
          uVar14 = *(uint *)(local_34 + 0x18);
          if (bVar8) {
            uVar14 = uVar14 & 0xffffe007;
          }
          else if (*(float *)(local_34 + 0x4c) == FLOAT_001c5b9c) {
            uVar14 = uVar14 & 0xffffe007 | (*(ushort *)(local_28 + 0x46e) & 0x3ff) << 3;
          }
          else {
            uVar17 = ((int (*)())FUN_0008256b)(param_1,*(undefined4 *)(local_28 + 0x470),
                                  *(float *)(local_34 + 0x4c));
            uVar14 = uVar14 & 0xffffe007 | (uVar17 & 0x3ff) << 3;
          }
          *(uint *)(local_2c + 0x1d1c) = uVar14;
          FUN_000b50a3(param_1,local_34,local_40,
                       *(undefined4 *)(&DAT_001ee584 + (uint)*(byte *)(param_1 + 0x2941) * 4));
          if ((*(byte *)(local_34 + 0x15) & 0x1e) == 10) {
            bVar9 = *(byte *)(local_34 + 0x14);
            if ((bVar9 & 7) == 4) {
              *(byte *)(param_1 + 0x1cdc + local_40 * 4) =
                   *(byte *)(param_1 + 0x1cdc + local_40 * 4) & 0xf8 | 2;
              bVar9 = *(byte *)(local_34 + 0x14);
            }
            else if ((bVar9 & 7) == 5) {
              *(byte *)(param_1 + 0x1cdc + local_40 * 4) =
                   *(byte *)(param_1 + 0x1cdc + local_40 * 4) & 0xf8 | 3;
              bVar9 = *(byte *)(local_34 + 0x14);
            }
            if ((bVar9 & 0x38) == 0x20) {
              *(byte *)(param_1 + 0x1cdc + local_40 * 4) =
                   *(byte *)(param_1 + 0x1cdc + local_40 * 4) & 199 | 0x10;
            }
            else if ((bVar9 & 0x38) == 0x28) {
              *(byte *)(param_1 + 0x1cdc + local_40 * 4) =
                   *(byte *)(param_1 + 0x1cdc + local_40 * 4) & 199 | 0x18;
            }
            uVar11 = *(ushort *)(local_34 + 0x14) & 0x1c0;
            if (uVar11 == 0x100) {
              *(ushort *)(param_1 + 0x1cdc + local_40 * 4) =
                   *(ushort *)(param_1 + 0x1cdc + local_40 * 4) & 0xfe3f | 0x80;
            }
            else if (uVar11 == 0x140) {
              *(ushort *)(param_1 + 0x1cdc + local_40 * 4) =
                   *(ushort *)(param_1 + 0x1cdc + local_40 * 4) & 0xfe3f | 0xc0;
            }
          }
          if (*(char *)(local_34 + 0x31) != '\x03') {
            puVar3 = (ushort *)(param_1 + 0x1cdc + local_40 * 4);
            *puVar3 = *puVar3 & 0xfe3f;
          }
          if (*(char *)(local_34 + 0x31) == '\x01') {
            pbVar4 = (byte *)(param_1 + 0x1cdc + local_40 * 4);
            *pbVar4 = *pbVar4 & 199;
          }
          *(ushort *)(param_1 + 0x1d1c + local_40 * 4) =
               *(ushort *)(param_1 + 0x1d1c + local_40 * 4) & 0xe007 |
               (*(ushort *)(local_28 + 0x46e) & 0x3ff) << 3;
          if ((*(uint *)(param_1 + 0x27b4) & uVar10) != 0) {
            iVar16 = local_40 + 8;
            *(undefined4 *)(local_2c + 0x1cfc) = *(undefined4 *)(local_2c + 0x1cdc);
            *(byte *)(param_1 + 0x1cdf + iVar16 * 4) =
                 *(byte *)(param_1 + 0x1cdf + iVar16 * 4) & 0xf |
                 (((byte)local_40 & 0xf) + 8) * '\x10';
            *(undefined4 *)(local_2c + 0x1d3c) = *(undefined4 *)(local_2c + 0x1d1c);
            *(undefined4 *)(local_2c + 0x1d7c) = *(undefined4 *)(local_2c + 0x1d5c);
            *(undefined4 *)(local_2c + 0x1dbc) = *(undefined4 *)(local_2c + 0x1d9c);
            *(undefined4 *)(local_2c + 0x1dfc) = *(undefined4 *)(local_2c + 0x1ddc);
            *(undefined4 *)(local_2c + 0x1e3c) = *(undefined4 *)(local_2c + 0x1e1c);
            if (*(char *)(param_1 + 0x21 + local_40) == '\x01') {
              *(ushort *)(param_1 + 0x1d5c + local_40 * 4) =
                   *(ushort *)(param_1 + 0x1d5c + local_40 * 4) & 0xf800 |
                   *(short *)(local_24 + 0x2854) - 1U & 0x7ff;
              *(ushort *)(param_1 + 0x1d5c + iVar16 * 4) =
                   *(ushort *)(param_1 + 0x1d5c + iVar16 * 4) & 0xf800 |
                   *(short *)(local_24 + 0x285c) - 1U & 0x7ff;
            }
            else {
              *(uint *)(param_1 + 0x1d5c + local_40 * 4) =
                   *(uint *)(param_1 + 0x1d5c + local_40 * 4) & 0xffc007ff |
                   (*(ushort *)(local_24 + 0x2854) - 1 & 0x7ff) << 0xb;
              *(uint *)(param_1 + 0x1d5c + iVar16 * 4) =
                   *(uint *)(param_1 + 0x1d5c + iVar16 * 4) & 0xffc007ff |
                   (*(ushort *)(local_24 + 0x285c) - 1 & 0x7ff) << 0xb;
            }
          }
        }
      }
LAB_0004cc1b:
      local_40 = local_40 + 1;
      local_2c = local_2c + 4;
      local_28 = local_28 + 0xcc;
      local_24 = local_24 + 0xc;
      local_20 = local_20 + 4;
      local_44 = local_44 >> 1;
    } while (local_44 != 0);
    iVar16 = *(int *)(param_1 + 0x27b4);
    uVar10 = *(uint *)(param_1 + 0x27b0);
  }
  *(uint *)(param_1 + 0x27b0) = iVar16 << 8 | uVar10;
  bVar9 = *(byte *)(param_1 + 0x45);
  if (((bVar9 & 8) != 0) && (*(code **)(param_1 + 0x11cc) != (code *)0x0)) {
    (**(code **)(param_1 + 0x11cc))(param_1);
    bVar9 = *(byte *)(param_1 + 0x45);
  }
  if ((bVar9 & 0x40) != 0) {
    if ((*(byte *)(param_1 + 0x46) & 4) != 0) {
      FUN_000aea8d(param_1,0);
      return;
    }
    FUN_000b1aed(param_1);
    return;
  }
  FUN_000b4709(param_1,0);
  (**(code **)(param_1 + 0x294c))(param_1,*(undefined4 *)(param_1 + 0x1e5c));
  return;
}

/* FUN_0004d534 @ 0x4d534 (216 bytes) */
int FUN_0004d534(param_1)
  int param_1;
{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
  if (*(int *)(param_1 + 0x243c) == 0) {
    return;
  }
  uVar1 = *(int *)(param_1 + 0x243c) + 1U >> 1;
  puVar2 = (uint *)(**(code **)(param_1 + 0x2758))(param_1,uVar1 * 2 + 2);
  *(uint **)(param_1 + 0x274c) = puVar2;
  uVar4 = (uVar1 - 1) * 0x10000;
  *puVar2 = uVar4 | 0x854;
  puVar2[uVar1 + 1] = uVar4 | 0x878;
  if (uVar1 != 0) {
    uVar4 = 0;
    iVar3 = 0;
    do {
      puVar2[uVar4 + 1] = *(uint *)(iVar3 + *(int *)(param_1 + 0x2440));
      puVar2[uVar1 + uVar4 + 2] = *(uint *)(*(int *)(param_1 + 0x2444) + iVar3);
      uVar4 = uVar4 + 1;
      iVar3 = iVar3 + 4;
    } while (uVar1 != uVar4);
  }
  iVar3 = *(int *)(param_1 + 0x274c) + 8 + uVar1 * 8;
  *(int *)(param_1 + 0x274c) = iVar3;
  (**(code **)(param_1 + 0x275c))(param_1,iVar3);
  return;
}

/* FUN_0004d60c @ 0x4d60c (168 bytes) */
int FUN_0004d60c(param_1)
  int param_1;
{
  uint uVar1;
  double dVar2;
  double dVar3;
  uint local_3c;
  
  uVar1 = *(uint *)(*(int *)(param_1 + 4) + 0x154) & 0x30000;
  dVar2 = DOUBLE_001cf3b0;
  if (((uVar1 != 0x20000) && (uVar1 != 0x30000)) && (dVar2 = DOUBLE_001cf3a0, uVar1 != 0x10000)) {
    dVar2 = DOUBLE_001cf3a8;
  }
  dVar2 = dVar2 * *(double *)(*(int *)(*(int *)(param_1 + 4) + 0x10) + 0x2d88);
  dVar3 = dVar2;
  if (DAT_001c61a0 <= dVar2) {
    dVar3 = DAT_001c61a0;
  }
  if (dVar3 <= 0.0) {
    dVar3 = 0.0;
  }
  local_3c = (uint)(DAT_001c6190 <= dVar2) * -0x80000000 ^
             (int)(dVar3 - (double)((ulonglong)DAT_001c6190 & -(ulonglong)(DAT_001c6190 <= dVar2)));
  return local_3c;
}

/* FUN_0004d6b4 @ 0x4d6b4 (236 bytes) */
int FUN_0004d6b4(param_1)
  int param_1;
{
  byte bVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  iVar4 = *(int *)(param_1 + 0x1b3c);
  if (*(int *)(iVar3 + 0x3170) == 0x1b021b02) {
    *(byte *)(param_1 + 0x1b3c) = *(byte *)(param_1 + 0x1b3c) & 0xfc;
  }
  else {
    bVar1 = *(byte *)(param_1 + 0x1b3c);
    *(byte *)(param_1 + 0x1b3c) = bVar1 & 0xfc | 1;
    sVar2 = *(short *)(iVar3 + 0x3170);
    if (sVar2 == 0x1b01) {
      *(byte *)(param_1 + 0x1b3c) = bVar1 & 0x8c | 0x11;
    }
    else if (sVar2 == 0x1b02) {
      *(byte *)(param_1 + 0x1b3c) = bVar1 & 0x8c | 0x21;
    }
    else if (sVar2 == 0x1b00) {
      *(byte *)(param_1 + 0x1b3c) = bVar1 & 0x8c | 1;
    }
    sVar2 = *(short *)(iVar3 + 0x3172);
    if (sVar2 == 0x1b01) {
      *(ushort *)(param_1 + 0x1b3c) = *(ushort *)(param_1 + 0x1b3c) & 0xfc7f | 0x80;
    }
    else if (sVar2 == 0x1b02) {
      *(ushort *)(param_1 + 0x1b3c) = *(ushort *)(param_1 + 0x1b3c) & 0xfc7f | 0x100;
    }
    else if (sVar2 == 0x1b00) {
      *(ushort *)(param_1 + 0x1b3c) = *(ushort *)(param_1 + 0x1b3c) & 0xfc7f;
    }
  }
  if (iVar4 != *(int *)(param_1 + 0x1b3c)) {
    *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x2000;
  }
  ((int (*)())FUN_0004c348)();
  return;
}

/* FUN_0004d7a0 @ 0x4d7a0 (376 bytes) */
int FUN_0004d7a0(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 0x2768);
  uVar2 = *(uint *)(param_1 + 8);
  iVar4 = *(int *)(param_1 + 4);
  if ((*(char *)(*(int *)(iVar4 + 0x10) + 0x2e2d) != '\0') &&
     ((*(byte *)(param_1 + 0x45) & 0x40) == 0)) {
    cVar3 = FUN_00017bd8(iVar4,*(undefined4 *)(iVar4 + 0x26a0));
    if ((cVar3 == '\0') && (iVar1 != 0)) {
      *(short *)(param_1 + 0x1b40) = (short)*(undefined4 *)(iVar1 + 0x18);
      *(byte *)(param_1 + 0x1b42) = *(byte *)(param_1 + 0x1b42) | 3;
      goto LAB_0004d81b;
    }
    iVar4 = *(int *)(param_1 + 4);
  }
  iVar4 = ((int (*)())FUN_000a1c97)(param_1,*(undefined4 *)(*(int *)(iVar4 + 0x10) + 0x2e20));
  *(short *)(param_1 + 0x1b40) = (short)(iVar4 * uVar2 >> 1);
  cVar3 = FUN_00017bd8(*(int *)(param_1 + 4),*(undefined4 *)(*(int *)(param_1 + 4) + 0x26a0));
  if (cVar3 == '\0') {
    *(byte *)(param_1 + 0x1b42) = *(byte *)(param_1 + 0x1b42) & 0xfc | 2;
  }
  else {
    *(byte *)(param_1 + 0x1b42) = *(byte *)(param_1 + 0x1b42) | 3;
  }
LAB_0004d81b:
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (((*(char *)(iVar4 + 0x2e2c) != '\0') && ((*(byte *)(param_1 + 0x45) & 0x40) == 0)) &&
     (*(short *)(iVar4 + 0x2e28) != -1)) {
    *(uint *)(param_1 + 0x1b64) =
         *(uint *)(param_1 + 0x1b64) & 3 |
         (uint)(FLOAT_001c5ba4 / ((float)*(int *)(iVar4 + 0x2e24) * FLOAT_001c5bc4 * (float)uVar2))
         & 0xfffffffc;
  }
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0x1b70) = *(undefined4 *)(iVar1 + 0x24);
  }
  *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x4000;
  ((int (*)())FUN_0004c348)();
  return;
}

/* FUN_0004d918 @ 0x4d918 (691 bytes) */
int FUN_0004d918(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  float fVar3;
  char cVar4;
  undefined2 uVar5;
  
  iVar1 = *(int *)(param_1 + 0x2768);
  uVar2 = *(uint *)(param_1 + 8);
  cVar4 = FUN_000a1d35(param_1);
  if (((*(ushort *)(param_1 + 0x44) & 0x4006) == 2) && (iVar1 != 0)) {
    *(short *)(param_1 + 0x1cce) = (short)*(undefined4 *)(iVar1 + 4);
    *(short *)(param_1 + 0x1ccc) = (short)*(undefined4 *)(iVar1 + 4);
    *(undefined4 *)(param_1 + 0x1cc0) = *(undefined4 *)(iVar1 + 0xc);
    *(undefined4 *)(param_1 + 0x1cc8) = *(undefined4 *)(iVar1 + 0x10);
  }
  else {
    if (cVar4 == '\0') {
      uVar5 = (undefined2)(uVar2 * *(int *)(param_1 + 0xe4) >> 1);
    }
    else {
      uVar5 = (undefined2)((int)(FLOAT_001c5bd4 + *(float *)(param_1 + 0xf0)) * uVar2 >> 1);
    }
    *(undefined2 *)(param_1 + 0x1cce) = uVar5;
    *(undefined2 *)(param_1 + 0x1ccc) = uVar5;
  }
  fVar3 = FLOAT_001c5ba4;
  if ((*(ushort *)(param_1 + 0x44) & 0x4006) == 2) {
    if (cVar4 == '\0') {
      *(short *)(param_1 + 0x1cd0) =
           (short)((int)(*(float *)(param_1 + 0x100) + FLOAT_001c5ba4) * uVar2 >> 1);
      *(short *)(param_1 + 0x1cd2) =
           (short)(uVar2 * (int)(fVar3 + *(float *)(param_1 + 0x104)) >> 1);
    }
    else if ((*(byte *)(param_1 + 0x47) & 1) == 0) {
      *(short *)(param_1 + 0x1cd0) = (short)((int)*(float *)(param_1 + 0x100) * uVar2 >> 1);
      *(short *)(param_1 + 0x1cd2) = (short)(uVar2 * (int)*(float *)(param_1 + 0x104) >> 1);
    }
    else {
      *(short *)(param_1 + 0x1cd0) =
           (short)((int)((float)uVar2 * *(float *)((int)&UINT_000013c4 + param_1)) >> 1);
      *(short *)(param_1 + 0x1cd2) =
           (short)((int)((float)uVar2 * *(float *)((int)&UINT_000013c8 + param_1)) >> 1);
    }
  }
  else if ((*(byte *)(param_1 + 0x47) & 1) == 0) {
    *(short *)(param_1 + 0x1cd0) = (short)(uVar2 * *(int *)(param_1 + 0x108) >> 1);
    *(short *)(param_1 + 0x1cd2) = (short)(uVar2 * *(int *)(param_1 + 0x10c) >> 1);
  }
  else {
    *(short *)(param_1 + 0x1cd0) =
         (short)((int)(uVar2 * *(int *)((int)&UINT_000013d0 + param_1)) >> 1);
    *(short *)(param_1 + 0x1cd2) = (short)((int)(uVar2 * *(int *)(param_1 + 0x13d4)) >> 1);
  }
  *(byte *)(param_1 + 0x1b75) = *(byte *)(param_1 + 0x1b75) & 0x3f;
  if ((*(byte *)(param_1 + 0x44) & 4) == 0) {
    *(undefined4 *)(param_1 + 0x1cc4) = 0;
    *(undefined4 *)(param_1 + 0x1cbc) = 0;
    iVar1 = *(int *)(param_1 + 0x2768);
  }
  else {
    *(undefined4 *)(param_1 + 0x1cc4) = 0x3f800000;
    *(undefined4 *)(param_1 + 0x1cc8) = 0;
    *(undefined4 *)(param_1 + 0x1cbc) = 0;
    *(undefined4 *)(param_1 + 0x1cc0) = 0x3f800000;
    iVar1 = *(int *)(param_1 + 0x2768);
  }
  if ((iVar1 == 0) && ((*(byte *)(param_1 + 0x44) & 4) == 0)) {
    *(undefined4 *)(param_1 + 0x1b50) = 0;
    *(byte *)(param_1 + 0x1b50) = *(byte *)(param_1 + 0x1b50) | 7;
    if ((*(byte *)(param_1 + 0x1a64) & 0x10) != 0) {
      *(byte *)(param_1 + 0x1a64) = *(byte *)(param_1 + 0x1a64) & 0xef;
      uVar2 = *(uint *)(param_1 + 0x1930);
      *(uint *)(param_1 + 0x1930) = uVar2 | 0x2000;
      *(uint *)(param_1 + 0x1930) = uVar2 | 0xc0a000;
      ((int (*)())FUN_0004c348)();
      return;
    }
  }
  *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0xc08000;
  ((int (*)())FUN_0004c348)();
  return;
}

/* FUN_0004dbcb @ 0x4dbcb (198 bytes) */
int FUN_0004dbcb(param_1)
  int param_1;
{
  char cVar1;
  short sVar2;
  int iVar3;
  byte bVar4;
  
  iVar3 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (*(char *)(param_1 + 0x13b8) == '\0') {
    if (*(short *)(iVar3 + 0x3174) == 0x900) goto LAB_0004dbeb;
  }
  else if (*(short *)(iVar3 + 0x3174) != 0x900) {
LAB_0004dbeb:
    bVar4 = *(byte *)(param_1 + 0x1b30) & 0xfb;
    *(byte *)(param_1 + 0x1b30) = bVar4;
    cVar1 = *(char *)(iVar3 + 0x317a);
    goto joined_r0x0004dc4d;
  }
  bVar4 = *(byte *)(param_1 + 0x1b30) | 4;
  *(byte *)(param_1 + 0x1b30) = bVar4;
  cVar1 = *(char *)(iVar3 + 0x317a);
joined_r0x0004dc4d:
  if (cVar1 == '\0') {
    *(byte *)(param_1 + 0x1b30) = bVar4 & 0xfc;
  }
  else {
    sVar2 = *(short *)(iVar3 + 0x3176);
    if (sVar2 == 0x405) {
      *(byte *)(param_1 + 0x1b30) = bVar4 & 0xfe | 2;
      *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x400;
      return;
    }
    if (sVar2 == 0x408) {
      *(byte *)(param_1 + 0x1b30) = bVar4 | 3;
      *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x400;
      return;
    }
    if (sVar2 == 0x404) {
      *(byte *)(param_1 + 0x1b30) = bVar4 & 0xfd | 1;
    }
  }
  *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x400;
  return;
}

/* FUN_0004dc91 @ 0x4dc91 (353 bytes) */
int FUN_0004dc91(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  uint uVar2;
  float fVar3;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (param_2 == 2) {
    fVar3 = FLOAT_001c5bb8 * *(float *)(iVar1 + 0x2de4);
    if (fVar3 <= 0.0) {
      fVar3 = 0.0;
    }
    uVar2 = (int)(fVar3 - (float)((uint)DAT_001c61b0 & -(uint)(DAT_001c61b0 <= fVar3))) |
            -(uint)(DAT_001c61c0 <= fVar3);
    return uVar2 >> 6 & 3 | uVar2 * 4;
  }
  if (param_2 != 3) {
    if (param_2 != 1) {
      return 0;
    }
    fVar3 = FLOAT_001c5bb8 * *(float *)(iVar1 + 0x2de0);
    if (fVar3 <= 0.0) {
      fVar3 = 0.0;
    }
    uVar2 = (int)(fVar3 - (float)((uint)DAT_001c61b0 & -(uint)(DAT_001c61b0 <= fVar3))) |
            -(uint)(DAT_001c61c0 <= fVar3);
    return uVar2 >> 6 & 3 | uVar2 * 4;
  }
  fVar3 = FLOAT_001c5bb8 * *(float *)(iVar1 + 0x2de8);
  if (fVar3 <= 0.0) {
    fVar3 = 0.0;
  }
  uVar2 = (int)(fVar3 - (float)((uint)DAT_001c61b0 & -(uint)(DAT_001c61b0 <= fVar3))) |
          -(uint)(DAT_001c61c0 <= fVar3);
  return uVar2 >> 6 & 3 | uVar2 * 4;
}

/* FUN_0004ddf2 @ 0x4ddf2 (603 bytes) */
int FUN_0004ddf2(param_1)
  int param_1;
{
  byte bVar1;
  char cVar2;
  byte bVar3;
  short sVar4;
  int iVar5;
  undefined *puVar6;
  ushort uVar7;
  
  puVar6 = PTR_DAT_002131c9;
  bVar1 = *(byte *)(param_1 + 0x293f);
  if ((*(uint *)(param_1 + 0x44) & 0x40080) == 0x80) {
    iVar5 = *(int *)(*(int *)(param_1 + 4) + 0x10);
    sVar4 = *(short *)(iVar5 + 0x2e04);
    if (sVar4 == 0x801) {
      *(undefined4 *)(param_1 + 0x134) = 0;
      *(uint *)(param_1 + 0x138) =
           (uint)(*(float *)(iVar5 + 0x2df0) * *(float *)(iVar5 + 0x2df0)) ^ _DAT_001c61d0;
    }
    else if (sVar4 == 0x2601) {
      *(float *)(param_1 + 0x134) = *(float *)(iVar5 + 0x2df8) * *(float *)(iVar5 + 0x2dfc);
      *(uint *)(param_1 + 0x138) = *(uint *)(iVar5 + 0x2dfc) ^ 0x80000000;
    }
    else if (sVar4 == 0x800) {
      *(undefined4 *)(param_1 + 0x134) = 0;
      *(uint *)(param_1 + 0x138) = *(uint *)(iVar5 + 0x2df0) ^ 0x80000000;
    }
    *(byte *)(param_1 + 0x1a64) = *(byte *)(param_1 + 0x1a64) & 0xf8 | 1;
    *(byte *)(param_1 + 0x1aec) = *(byte *)(param_1 + 0x1aec) & 0xf9 | 1;
    *(undefined4 *)(param_1 + 0x1a78) = 0x3f800000;
    *(undefined4 *)(param_1 + 0x1a7c) = 0xbf800000;
    *(byte *)(param_1 + 0x18a7) = *(byte *)(param_1 + 0x18a7) & 0xfd;
    *(byte *)(param_1 + 0x1879) = *(byte *)(param_1 + 0x1879) & 0xf7;
    cVar2 = *(char *)(param_1 + 0x121);
  }
  else {
    *(byte *)(param_1 + 0x1aec) = *(byte *)(param_1 + 0x1aec) & 0xfe;
    *(byte *)(param_1 + 0x18a7) = *(byte *)(param_1 + 0x18a7) & 0xfd;
    *(byte *)(param_1 + 0x1879) = *(byte *)(param_1 + 0x1879) & 0xf7;
    cVar2 = *(char *)(param_1 + 0x121);
  }
  if (cVar2 == '\0') {
    bVar3 = *(byte *)(param_1 + 0x45);
  }
  else {
    *(undefined1 *)(param_1 + 0x121) = 0;
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
    *(undefined1 *)(param_1 + 0x29) = 1;
    bVar3 = *(byte *)(param_1 + 0x45);
  }
  if ((bVar3 & 0x40) == 0) {
    FUN_000b4709(param_1,0);
    (**(code **)(param_1 + 0x294c))(param_1,*(undefined4 *)(param_1 + 0x1e5c));
  }
  else if ((*(byte *)(param_1 + 0x46) & 4) == 0) {
    FUN_000b1aed(param_1);
  }
  else {
    FUN_000aea8d(param_1,0);
  }
  uVar7 = ((int (*)())FUN_0004dc91)(param_1,puVar6[(uint)bVar1 * 0x24 + 0x1c] & 3);
  *(ushort *)(param_1 + 0x1a54) = *(ushort *)(param_1 + 0x1a54) & 0xfc00 | uVar7 & 0x3ff;
  uVar7 = ((int (*)())FUN_0004dc91)(param_1,(byte)puVar6[(uint)bVar1 * 0x24 + 0x1b] >> 5 & 3);
  *(ushort *)(param_1 + 0x1a58) = *(ushort *)(param_1 + 0x1a58) & 0xfc00 | uVar7 & 0x3ff;
  uVar7 = ((int (*)())FUN_0004dc91)(param_1,(byte)puVar6[(uint)bVar1 * 0x24 + 0x1b] >> 3 & 3);
  *(ushort *)(param_1 + 0x1a5c) = *(ushort *)(param_1 + 0x1a5c) & 0xfc00 | uVar7 & 0x3ff;
  *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 1;
  return;
}

/* FUN_0004e04d @ 0x4e04d (397 bytes) */
int FUN_0004e04d(param_1)
  int param_1;
{
  bool bVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  undefined4 local_20;
  
  iVar3 = (int)((float)*(int *)(param_1 + 0x1358) * *(float *)(param_1 + 0x2814));
  uVar6 = (uint)(*(float *)(param_1 + 0x2814) * (float)*(int *)(param_1 + 0x1360) - FLOAT_001c5ba4);
  iVar5 = (int)((float)*(int *)(param_1 + 0x135c) * *(float *)(param_1 + 0x2818));
  uVar8 = (uint)(*(float *)(param_1 + 0x2818) * (float)*(int *)(param_1 + 0x1364) - FLOAT_001c5ba4);
  iVar7 = 0;
  if (-1 < iVar3) {
    iVar7 = iVar3;
  }
  uVar4 = (uint)*(ushort *)(param_1 + 0x13bc);
  if ((int)uVar6 <= (int)(uint)*(ushort *)(param_1 + 0x13bc)) {
    uVar4 = uVar6;
  }
  if (*(char *)(param_1 + 0x13b8) == '\0') {
    uVar2 = 0;
    if (-1 < iVar5) {
      uVar2 = (ushort)iVar5;
    }
    local_20 = (uint)uVar2;
    uVar6 = *(ushort *)(param_1 + 0x13ba) - 1;
    if ((int)uVar6 < (int)uVar8) {
      uVar8 = uVar6;
    }
  }
  else {
    uVar2 = 0xffff;
    if (-2 < iVar5) {
      uVar2 = (ushort)iVar5;
    }
    local_20 = (uint)uVar2;
    if ((int)(uint)*(ushort *)(param_1 + 0x13ba) < (int)uVar8) {
      uVar8 = (uint)*(ushort *)(param_1 + 0x13ba);
    }
  }
  iVar3 = *(int *)(param_1 + 7000);
  uVar6 = *(uint *)(param_1 + 0x1b10);
  *(ushort *)(param_1 + 7000) = *(ushort *)(param_1 + 7000) & 0xe000 | (ushort)iVar7 & 0x1fff;
  *(uint *)(param_1 + 7000) = *(uint *)(param_1 + 7000) & 0xfc001fff | (local_20 & 0x1fff) << 0xd;
  *(ushort *)(param_1 + 0x1b10) = *(ushort *)(param_1 + 0x1b10) & 0xe000 | (ushort)uVar4 & 0x1fff;
  uVar8 = *(uint *)(param_1 + 0x1b10) & 0xfc001fff | (uVar8 & 0x1fff) << 0xd;
  *(uint *)(param_1 + 0x1b10) = uVar8;
  if ((iVar3 == *(int *)(param_1 + 7000)) && (uVar6 == uVar8)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 2;
  }
  return;
}

/* FUN_0004e1da @ 0x4e1da (2093 bytes) */
int FUN_0004e1da(param_1)
  int param_1;
{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  
  *(undefined4 *)(param_1 + 0x1930) = 0;
  *(undefined4 *)(param_1 + 0x1934) = 0;
  *(undefined4 *)(param_1 + 0x1938) = 0;
  *(undefined4 *)(param_1 + 0x193c) = 0;
  *(undefined4 *)(param_1 + 0x1a4c) = 0;
  *(undefined4 *)(param_1 + 0x1a50) = 0;
  *(byte *)(param_1 + 0x1a50) = *(byte *)(param_1 + 0x1a50) & 0xfe;
  *(undefined4 *)(param_1 + 0x1a54) = 0;
  *(undefined4 *)(param_1 + 0x1a58) = 0;
  *(undefined4 *)(param_1 + 0x1a5c) = 0;
  *(undefined4 *)(param_1 + 0x1aec) = 0;
  *(undefined4 *)(param_1 + 0x1bcc) = 0;
  *(undefined4 *)(param_1 + 0x1bd0) = 0;
  if ((*(byte *)(param_1 + 0x2454) & 0x10) != 0) {
    *(byte *)(param_1 + 0x1bcc) = *(byte *)(param_1 + 0x1bcc) | 1;
  }
  if (*(int *)(param_1 + 0x23dc) == 2) {
    *(byte *)(param_1 + 0x1bd0) = *(byte *)(param_1 + 0x1bd0) | 3;
  }
  else {
    *(byte *)(param_1 + 0x1bd0) = *(byte *)(param_1 + 0x1bd0) & 0xfc | 1;
  }
  *(undefined4 *)(param_1 + 0x1b50) = 0;
  *(byte *)(param_1 + 0x1b50) = *(byte *)(param_1 + 0x1b50) | 7;
  *(undefined4 *)(param_1 + 0x1b4c) = 0;
  *(byte *)(param_1 + 0x1b4c) = *(byte *)(param_1 + 0x1b4c) | 2;
  *(undefined1 *)(param_1 + 0x247c) = 1;
  *(undefined4 *)(param_1 + 0x1a64) = 0;
  *(undefined4 *)(param_1 + 0x1cbc) = 0;
  *(undefined4 *)(param_1 + 0x1cc4) = 0;
  *(undefined4 *)(param_1 + 0x1cc0) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x1cc8) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x1b54) = 0;
  *(byte *)(param_1 + 0x1b54) = *(byte *)(param_1 + 0x1b54) & 0xf0 | 5;
  *(byte *)(param_1 + 0x1b56) = *(byte *)(param_1 + 0x1b56) & 0xf0 | 5;
  *(undefined4 *)(param_1 + 0x1ccc) = 0;
  *(undefined4 *)(param_1 + 0x1cd0) = 0;
  *(undefined4 *)(param_1 + 0x1b40) = 0;
  *(byte *)(param_1 + 0x1b42) = *(byte *)(param_1 + 0x1b42) & 0xfc | 2;
  *(undefined4 *)(param_1 + 0x1b64) = 0;
  *(undefined4 *)(param_1 + 0x1b68) = 0;
  *(undefined4 *)(param_1 + 0x1b6c) = 0;
  *(undefined4 *)(param_1 + 0x1b70) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x1b2c) = 0;
  *(byte *)(param_1 + 0x1b2e) = *(byte *)(param_1 + 0x1b2e) | 3;
  *(undefined4 *)(param_1 + 0x1a70) = 0;
  *(undefined4 *)(param_1 + 0x1a74) = 0;
  *(undefined4 *)(param_1 + 0x1b3c) = 0;
  *(undefined4 *)(param_1 + 0x1b48) = 0;
  *(byte *)(param_1 + 0x1b48) = *(byte *)(param_1 + 0x1b48) & 0xcc | 1;
  *(undefined4 *)(param_1 + 0x1b44) = 0;
  *(undefined4 *)(param_1 + 0x1a78) = 0;
  *(undefined4 *)(param_1 + 0x1a7c) = 0;
  *(undefined4 *)(param_1 + 0x1a60) = 0;
  *(undefined4 *)(param_1 + 8) = 0xc;
  *(undefined4 *)(param_1 + 0x1a68) = 0x66666666;
  *(undefined4 *)(param_1 + 0x1a6c) = 0x6666666;
  *(undefined1 *)(param_1 + 0x1a6b) = 0x55;
  *(byte *)(param_1 + 0x1a6f) = *(byte *)(param_1 + 0x1a6f) & 0xf0 | 5;
  *(undefined4 *)(param_1 + 0x23c0) = 0;
  *(undefined4 *)(param_1 + 0x1a80) = 0;
  *(byte *)(param_1 + 0x1a82) = *(byte *)(param_1 + 0x1a82) & 0xc0 | 0x22;
  *(byte *)(param_1 + 0x1a83) = *(byte *)(param_1 + 0x1a83) & 0xc0 | 0x20;
  *(byte *)(param_1 + 0x1a81) = *(byte *)(param_1 + 0x1a81) & 0x8f;
  *(byte *)(param_1 + 0x1af4) = *(byte *)(param_1 + 0x1af4) | 0xf;
  *(byte *)(param_1 + 0x1af8) = *(byte *)(param_1 + 0x1af8) & 0xfb;
  *(undefined4 *)(param_1 + 0x1af0) = 0;
  *(byte *)(param_1 + 0x1abc) = *(byte *)(param_1 + 0x1abc) & 0xe0 | 5;
  *(ushort *)(param_1 + 0x1abc) = *(ushort *)(param_1 + 0x1abc) & 0xfc1f | 0x120;
  *(byte *)(param_1 + 0x1abd) = *(byte *)(param_1 + 0x1abd) & 0x83 | 0x14;
  *(uint *)(param_1 + 0x1abc) = *(uint *)(param_1 + 0x1abc) & 0xfff07fff | 0x48000;
  *(ushort *)(param_1 + 0x1abe) = *(ushort *)(param_1 + 0x1abe) & 0xfe0f | 0x1a0;
  *(byte *)(param_1 + 0x1abf) = *(byte *)(param_1 + 0x1abf) & 0xc1 | 0x2c;
  *(undefined4 *)(param_1 + 0x1ae0) = 0;
  *(undefined4 *)(param_1 + 7000) = 0;
  *(undefined4 *)(param_1 + 0x1b10) = 0;
  *(undefined4 *)(param_1 + 0x1b60) = 0xffffff;
  *(undefined4 *)(param_1 + 0x1bd4) = 0;
  *(undefined4 *)(param_1 + 0x1b30) = 0;
  *(undefined4 *)(param_1 + 0x1b14) = 0;
  *(undefined4 *)(param_1 + 0x1b28) = 0;
  *(undefined4 *)(param_1 + 0x27b0) = 0;
  puVar5 = (undefined4 *)(param_1 + 0x1cdc);
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  *(undefined4 *)(param_1 + 0x233c) = 0;
  *(byte *)(param_1 + 0x233c) = *(byte *)(param_1 + 0x233c) & 0xe0 | 0xf;
  *(undefined1 *)(param_1 + 0x233d) = 0x1b;
  uVar3 = *(undefined4 *)(param_1 + 0x233c);
  *(undefined4 *)(param_1 + 0x2340) = uVar3;
  *(undefined4 *)(param_1 + 0x2344) = uVar3;
  *(undefined4 *)(param_1 + 0x2348) = uVar3;
  ((int (*)())FUN_000497eb)(param_1);
  *(undefined4 *)(param_1 + 0x1b7c) = 0;
  *(undefined1 *)(param_1 + 0x1b7c) = 0x6a;
  bVar1 = *(byte *)(param_1 + 0x1b7e);
  *(byte *)(param_1 + 0x1b7e) = bVar1 | 0x80;
  bVar2 = *(byte *)(param_1 + 0x2454);
  if ((bVar2 & 1) == 0) {
    if ((bVar2 & 0x10) == 0) {
      if ((bVar2 & 0x40) == 0) {
        *(byte *)(param_1 + 0x1b7d) = *(byte *)(param_1 + 0x1b7d) & 0xf0 | 4;
      }
      else {
        *(byte *)(param_1 + 0x1b7d) = *(byte *)(param_1 + 0x1b7d) & 0xf0 | 2;
      }
    }
    else {
      *(byte *)(param_1 + 0x1b7d) = *(byte *)(param_1 + 0x1b7d) & 0xf0 | 5;
    }
  }
  else {
    *(byte *)(param_1 + 0x1b7d) = *(byte *)(param_1 + 0x1b7d) & 0xf0 | 8;
  }
  *(byte *)(param_1 + 0x1b7e) = bVar1 & 0xc3 | 0xb0;
  *(undefined1 *)(param_1 + 0x23ec) = 1;
  *(undefined4 *)(param_1 + 0x1b80) = 0;
  *(undefined4 *)(param_1 + 0x1ca0) = 0;
  *(undefined4 *)(param_1 + 0x1b9c) = 0;
  *(undefined4 *)(param_1 + 0x1ba0) = 0;
  *(undefined4 *)(param_1 + 0x1ca8) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x1cac) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x1cb0) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x1cb4) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x1b84) = 0;
  *(byte *)(param_1 + 0x1b84) = *(byte *)(param_1 + 0x1b84) | 0x3f;
  *(byte *)(param_1 + 0x1b85) = *(byte *)(param_1 + 0x1b85) & 0xfc | 4;
  *(undefined4 *)(param_1 + 0x1b74) = 0;
  *(undefined4 *)(param_1 + 0x1b98) = 0;
  *(undefined4 *)(param_1 + 0x1bc8) = 0;
  *(undefined4 *)(param_1 + 0x1b88) = 0xffff;
  *(undefined4 *)(param_1 + 0x1aa0) = 0;
  *(byte *)(param_1 + 0x1aa0) = *(byte *)(param_1 + 0x1aa0) | 0x10;
  *(undefined4 *)(param_1 + 0x1ab0) = 0;
  bVar1 = *(byte *)(param_1 + 0x1ab1);
  *(byte *)(param_1 + 0x1ab1) = bVar1 | 8;
  *(byte *)(param_1 + 0x1ab2) = *(byte *)(param_1 + 0x1ab2) | 0xc;
  if (*(char *)(param_1 + 0x2451) != '\0') {
    *(byte *)(param_1 + 0x1ab1) = bVar1 & 0x8f | 0x38;
  }
  *(undefined4 *)(param_1 + 0x1ae4) = 0;
  *(undefined4 *)(param_1 + 0x1a98) = 0;
  *(undefined4 *)(param_1 + 0x1a9c) = 0;
  *(undefined4 *)(param_1 + 0x1afc) = 0;
  *(byte *)(param_1 + 0x1ab8) = *(byte *)(param_1 + 0x1ab8) | 1;
  *(undefined4 *)(param_1 + 0x1b38) = 0x4b7fffff;
  *(undefined4 *)(param_1 + 0x1b34) = 0;
  *(uint *)(param_1 + 0x1cd4) = *(uint *)(param_1 + 0x1cd4) & 0xfffc0003;
  *(ushort *)(param_1 + 0x1cd8) = *(ushort *)(param_1 + 0x1cd8) & 0xc00f;
  *(undefined4 *)(param_1 + 0x1ae8) = 0;
  *(undefined4 *)(param_1 + 0x1ab4) = 0;
  *(undefined4 *)(param_1 + 0x1aa8) = 0;
  *(undefined1 *)(param_1 + 0x1aa9) = 0xff;
  *(undefined1 *)(param_1 + 0x1aaa) = 0xff;
  *(undefined1 *)(param_1 + 0x1aa8) = 0;
  *(undefined4 *)(param_1 + 0x1aa4) = 0;
  *(undefined4 *)(param_1 + 0x1bd8) = 0;
  *(byte *)(param_1 + 0x1bd8) = *(byte *)(param_1 + 0x1bd8) | 1;
  *(undefined4 *)(param_1 + 0x2358) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x235c) = 0;
  *(undefined4 *)(param_1 + 0x2360) = DAT_001ee520;
  *(undefined4 *)(param_1 + 0x2364) = DAT_001ee524;
  *(undefined4 *)(param_1 + 0x236c) = DAT_001ee52c;
  *(undefined4 *)(param_1 + 0x2368) = DAT_001ee528;
  *(undefined4 *)(param_1 + 0x2370) = DAT_001ee530;
  iVar4 = *(int *)(param_1 + 0x23d0) * 0xb4;
  *(undefined4 *)(param_1 + 0x2374) = *(undefined4 *)(&DAT_001ee1a0 + iVar4);
  *(undefined4 *)(param_1 + 0x237c) = *(undefined4 *)(&DAT_001ee1a8 + iVar4);
  *(undefined4 *)(param_1 + 0x2378) = *(undefined4 *)(&DAT_001ee1a4 + iVar4);
  *(undefined4 *)(param_1 + 0x2380) = *(undefined4 *)(&DAT_001ee1ac + iVar4);
  *(undefined4 *)(param_1 + 0x2384) = *(undefined4 *)(&DAT_001edeac + iVar4);
  *(undefined4 *)(param_1 + 0x2388) = *(undefined4 *)(&DAT_001edeb0 + iVar4);
  *(undefined **)(param_1 + 0x2398) = (PTR_FUN_001edeb8)[*(int *)(param_1 + 0x23d0) * 0x2d];
  *(undefined4 *)(param_1 + 0x238c) = *(undefined4 *)(&DAT_001edeb4 + iVar4);
  *(undefined4 *)(param_1 + 0x239c) = *(undefined4 *)(&DAT_001edebc + iVar4);
  *(undefined4 *)(param_1 + 0x2390) = *(undefined4 *)(&DAT_001edec0 + iVar4);
  *(undefined4 *)(param_1 + 0x23a0) = *(undefined4 *)(&DAT_001edec8 + iVar4);
  *(undefined4 *)(param_1 + 0x2394) = *(undefined4 *)(&DAT_001edec4 + iVar4);
  *(undefined4 *)(param_1 + 0x23a4) = *(undefined4 *)(&DAT_001edecc + iVar4);
  *(undefined4 *)(param_1 + 0x23c4) = 0;
  *(undefined4 *)(param_1 + 0x23c8) = 0;
  *(undefined4 *)(param_1 + 0x23cc) = 0;
  if (*(int *)(param_1 + 0x23d0) == 4) {
    *(byte *)(param_1 + 0x23c4) = *(byte *)(param_1 + 0x23c4) & 0x8f | 0x11;
    *(byte *)(param_1 + 0x23c5) = *(byte *)(param_1 + 0x23c5) & 0xd8 | 1;
    *(byte *)(param_1 + 0x23c6) = *(byte *)(param_1 + 0x23c6) & 0xfd;
    *(ushort *)(param_1 + 0x23c8) = *(ushort *)(param_1 + 0x23c8) & 0xfe00 | 0x1fe;
    *(byte *)(param_1 + 0x23ca) = *(byte *)(param_1 + 0x23ca) & 0xd8 | 1;
    *(ushort *)(param_1 + 0x23cc) = *(ushort *)(param_1 + 0x23cc) & 0xfe00 | 0x1fe;
    *(byte *)(param_1 + 0x23ce) = *(byte *)(param_1 + 0x23ce) & 0xd8 | 1;
  }
  *(undefined4 *)(param_1 + 0x1bb8) = 0;
  *(undefined1 *)(param_1 + 0x1bb8) = 0xaa;
  *(undefined1 *)(param_1 + 0x1bb9) = 0xaa;
  *(byte *)(param_1 + 0x1bba) = *(byte *)(param_1 + 0x1bba) & 0xf0 | 10;
  *(undefined4 *)(param_1 + 0x1bac) = 0;
  *(undefined4 *)(param_1 + 0x1bb0) = 0;
  *(undefined4 *)(param_1 + 0x1bbc) = 0;
  *(byte *)(param_1 + 0x1bbc) = *(byte *)(param_1 + 0x1bbc) & 0xfe;
  *(undefined4 *)(param_1 + 0x1bc0) = 0;
  *(undefined4 *)(param_1 + 0x1bc4) = 0;
  *(undefined4 *)(param_1 + 0x2354) = 0;
  *(undefined4 *)(param_1 + 0x23e0) = 0;
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
  return;
}

/* FUN_0004ea07 @ 0x4ea07 (356 bytes) */
int FUN_0004ea07(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
  int param_7;
  int param_8;
{
  uint uVar1;
  undefined1 local_d;
  
  if ((*(char *)(param_1 + 0x1868) == '\0') ||
     (param_5 = *(int *)(*(int *)(param_1 + 0x1864) + param_5 * 4), param_5 != 0x16)) {
    local_d = '\x0f';
  }
  else {
    local_d = '\0';
  }
  uVar1 = param_2 >> 1;
  if ((param_2 & 1) != 0) {
    *(byte *)(param_1 + 0x1be6 + uVar1 * 4) = param_3 & 0xf | param_4 << 4;
    *(byte *)(param_1 + 0x1be7 + uVar1 * 4) =
         (byte)param_5 & 0x1f | (param_6 & 1) << 5 | (param_7 & 1) << 6 | param_8 << 7;
    *(byte *)(param_1 + 0x1c06 + uVar1 * 4) = *(byte *)(param_1 + 0x1c06 + uVar1 * 4) & 0xc0 | 8;
    *(ushort *)(param_1 + 0x1c06 + uVar1 * 4) =
         *(ushort *)(param_1 + 0x1c06 + uVar1 * 4) & 0xfe3f | 0x80;
    *(byte *)(param_1 + 0x1c07 + uVar1 * 4) =
         *(byte *)(param_1 + 0x1c07 + uVar1 * 4) & 1 | 6 | local_d << 4;
    return;
  }
  *(byte *)(param_1 + 0x1be4 + uVar1 * 4) = param_3 & 0xf | param_4 << 4;
  *(byte *)(param_1 + 0x1be5 + uVar1 * 4) =
       (byte)param_5 & 0x1f | (param_6 & 1) << 5 | (param_7 & 1) << 6 | param_8 << 7;
  *(byte *)(param_1 + 0x1c04 + uVar1 * 4) = *(byte *)(param_1 + 0x1c04 + uVar1 * 4) & 0xc0 | 8;
  *(ushort *)(param_1 + 0x1c04 + uVar1 * 4) =
       *(ushort *)(param_1 + 0x1c04 + uVar1 * 4) & 0xfe3f | 0x80;
  *(byte *)(param_1 + 0x1c05 + uVar1 * 4) =
       *(byte *)(param_1 + 0x1c05 + uVar1 * 4) & 1 | 6 | local_d << 4;
  return;
}

/* FUN_0004eb6b @ 0x4eb6b (528 bytes) */
int FUN_0004eb6b(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  int iVar7;
  uint *puVar8;
  int iVar9;
  int iVar10;
  int local_44;
  int local_40;
  int local_38;
  uint local_24;
  int local_20;
  
  iVar1 = *(int *)(param_1 + 0x1154);
  if (*(char *)(param_1 + 0x1134) == '\0') {
    local_40 = *(int *)(param_1 + 0x1144);
  }
  else {
    local_40 = iVar1 + 0x10;
  }
  local_38 = 0;
  local_24 = 0x1300;
  local_20 = 0;
  local_44 = 0;
  iVar10 = param_1;
  do {
    iVar9 = *(int *)(param_1 + 0x1e70);
    if ((((*(uint *)(iVar9 + 0x10bc) & 1 << ((byte)local_38 & 0x1f)) != 0) &&
        (*(char *)(*(int *)(local_40 + 0x28) + local_20) == '\0')) &&
       (pcVar6 = (char *)(local_20 + *(int *)(iVar1 + 0xc)), *pcVar6 != '\0')) {
      uVar2 = *(uint *)(pcVar6 + 4);
      uVar3 = *(uint *)(*(int *)(iVar1 + 0xc) + 8 + local_20);
      uVar4 = *(uint *)(local_20 + 0xc + *(int *)(iVar1 + 0xc));
      uVar5 = *(uint *)(local_20 + 0x10 + *(int *)(iVar1 + 0xc));
      iVar7 = local_44 + iVar9;
      if (((uVar2 != *(uint *)(iVar7 + 0x90)) || (uVar3 != *(uint *)(iVar7 + 0x94))) ||
         ((uVar4 != *(uint *)(iVar7 + 0x98) || (uVar5 != *(uint *)(iVar7 + 0x9c))))) {
        *(uint *)(local_44 + 0x90 + iVar9) = uVar2;
        *(uint *)(local_44 + *(int *)(param_1 + 0x1e70) + 0x94) = uVar3;
        *(uint *)(local_44 + *(int *)(param_1 + 0x1e70) + 0x98) = uVar4;
        *(uint *)(local_44 + *(int *)(param_1 + 0x1e70) + 0x9c) = uVar5;
        *(uint *)(iVar10 + 0x1f38) = uVar2;
        *(uint *)(iVar10 + 0x1f3c) = uVar3;
        *(uint *)(iVar10 + 8000) = uVar4;
        *(uint *)(iVar10 + 0x1f44) = uVar5;
        puVar8 = (uint *)(**(code **)(param_1 + 0x2758))(param_1,5);
        *(uint **)(param_1 + 0x274c) = puVar8;
        *puVar8 = local_24 | 0x30000;
        puVar8[1] = uVar2;
        puVar8[2] = uVar3;
        puVar8[3] = uVar4;
        puVar8[4] = uVar5;
        iVar9 = *(int *)(param_1 + 0x274c) + 0x14;
        *(int *)(param_1 + 0x274c) = iVar9;
        (**(code **)(param_1 + 0x275c))(param_1,iVar9);
        *(undefined4 *)(param_1 + 0x1e68) = 0;
      }
    }
    local_38 = local_38 + 1;
    local_44 = local_44 + 0x10;
    iVar10 = iVar10 + 0x10;
    local_24 = local_24 + 4;
    local_20 = local_20 + 0x14;
  } while (local_38 != 8);
  return;
}

/* FUN_0004ed7b @ 0x4ed7b (420 bytes) */
int FUN_0004ed7b(param_1)
  int param_1;
{
  int iVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  byte bVar4;
  uint uVar5;
  int local_20;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (*(char *)(iVar1 + 0x2d66) == '\0') {
    *(byte *)(param_1 + 0x1a4d) = *(byte *)(param_1 + 0x1a4d) & 0xf7;
    *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x200;
    return;
  }
  switch(*(undefined2 *)(iVar1 + 0x2d64)) {
  case 0x201:
    local_20 = 1;
    bVar4 = 1;
    break;
  case 0x202:
    local_20 = 2;
    bVar4 = 2;
    break;
  case 0x203:
    local_20 = 3;
    bVar4 = 3;
    break;
  case 0x204:
    local_20 = 4;
    bVar4 = 4;
    break;
  case 0x205:
    local_20 = 5;
    bVar4 = 5;
    break;
  case 0x206:
    local_20 = 6;
    bVar4 = 6;
    break;
  case 0x207:
    local_20 = 7;
    bVar4 = 7;
    break;
  default:
    local_20 = 0;
    bVar4 = 0;
  }
  bVar4 = *(byte *)(param_1 + 0x1a4d) & 0xf8 | bVar4;
  *(byte *)(param_1 + 0x1a4d) = bVar4;
  uVar5 = (uint)(FLOAT_001c5c20 * *(float *)(iVar1 + 0x2d60));
  uVar2 = 0xff;
  if (uVar5 < 0x100) {
    uVar2 = (undefined1)uVar5;
  }
  *(undefined1 *)(param_1 + 0x1a4c) = uVar2;
  if ((PTR_DAT_002131c9[(uint)*(byte *)(param_1 + 0x293f) * 0x24 + 0x1a] & 0x3c) == 0x28) {
    uVar3 = FUN_0001b725(*(undefined4 *)(iVar1 + 0x2d60));
    *(undefined2 *)(param_1 + 0x1bdc) = uVar3;
    bVar4 = *(byte *)(param_1 + 0x1a4d);
  }
  else {
    *(short *)(param_1 + 0x1bdc) =
         (short)(int)(FLOAT_001c5c0c * *(float *)(iVar1 + 0x2d60) + FLOAT_001c5bd4);
  }
  *(byte *)(param_1 + 0x1a4d) = bVar4 & 0xf7 | (local_20 != 7) << 3 | 0x10;
  *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x200;
  return;
}

/* FUN_0004ef3c @ 0x4ef3c (436 bytes) */
int FUN_0004ef3c(param_1)
  int param_1;
{
  byte bVar1;
  int iVar2;
  undefined *puVar3;
  uint uVar4;
  
  puVar3 = PTR_DAT_002131c9;
  iVar2 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  bVar1 = *(byte *)(param_1 + 0x293f);
  if ((*(uint *)(param_1 + 0x18a4) & 0x3fffc0) == 0) {
    *(undefined4 *)(param_1 + 0x1af4) = 0;
    *(byte *)(param_1 + 0x1b2e) = *(byte *)(param_1 + 0x1b2e) | 3;
    iVar2 = *(int *)(iVar2 + 0x3194);
  }
  else {
    uVar4 = (uint)(*(char *)(iVar2 + 0x2e40) == '\x01') *
            (uint)((byte)PTR_DAT_002131c9[(uint)bVar1 * 0x24 + 0x1c] >> 4);
    *(uint *)(param_1 + 0x1af4) = uVar4;
    uVar4 = (uint)(*(char *)(iVar2 + 0x2e41) == '\x01') *
            (uint)(puVar3[(uint)bVar1 * 0x24 + 0x1d] & 0xf) | uVar4;
    *(uint *)(param_1 + 0x1af4) = uVar4;
    uVar4 = (uint)(*(char *)(iVar2 + 0x2e42) == '\x01') *
            (uint)((byte)puVar3[(uint)bVar1 * 0x24 + 0x1d] >> 4) | uVar4;
    *(uint *)(param_1 + 0x1af4) = uVar4;
    *(uint *)(param_1 + 0x1af4) =
         uVar4 | (uint)(*(char *)(iVar2 + 0x2e43) == '\x01') *
                 (uint)(puVar3[(uint)bVar1 * 0x24 + 0x1e] & 0xf);
    *(byte *)(param_1 + 0x1b2e) = *(byte *)(param_1 + 0x1b2e) | 3;
    iVar2 = *(int *)(iVar2 + 0x3194);
  }
  if (iVar2 != 0x1d01) {
    *(byte *)(param_1 + 0x1b2c) = *(byte *)(param_1 + 0x1b2c) & 0xc0 | 0x15;
    *(byte *)(param_1 + 0x1b2d) = *(byte *)(param_1 + 0x1b2d) & 0xc0 | 0x15;
    if ((*(byte *)(param_1 + 0x46) & 4) == 0) {
      *(undefined1 *)(param_1 + 0x1b2c) = 0x95;
      *(undefined1 *)(param_1 + 0x1b2d) = 0x95;
    }
    else {
      *(undefined1 *)(param_1 + 0x1b2c) = 0x55;
      *(undefined1 *)(param_1 + 0x1b2d) = 0x55;
    }
    *(byte *)(param_1 + 0x1bba) = *(byte *)(param_1 + 0x1bba) & 0xf0 | 5;
    *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x10;
    return;
  }
  *(undefined1 *)(param_1 + 0x1b2c) = 0xaa;
  *(undefined1 *)(param_1 + 0x1b2d) = 0xaa;
  *(byte *)(param_1 + 0x1bba) = *(byte *)(param_1 + 0x1bba) & 0xf0 | 10;
  *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x10;
  return;
}

/* FUN_0004f0f0 @ 0x4f0f0 (3112 bytes) */
int FUN_0004f0f0(param_1)
  int param_1;
{
  byte bVar1;
  undefined4 uVar2;
  undefined *puVar3;
  char cVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  uint uVar11;
  int *local_34;
  int *local_30;
  int *local_2c;
  int *local_28;
  int *local_24;
  int *local_20;
  
  iVar8 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  puVar5 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,6);
  *puVar5 = 0x10a4;
  puVar5[1] = 0;
  *(undefined4 **)(param_1 + 0x274c) = puVar5 + 2;
  (**(code **)(param_1 + 0x275c))(param_1,puVar5 + 2);
  puVar5 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,4);
  *puVar5 = 0x1393;
  puVar5[1] = 10;
  puVar5[2] = 0x13c6;
  puVar5[3] = 3;
  *(undefined4 **)(param_1 + 0x274c) = puVar5 + 4;
  (**(code **)(param_1 + 0x275c))(param_1,puVar5 + 4);
  puVar6 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0x1b4);
  *(undefined4 **)(param_1 + 0x274c) = puVar6;
  *puVar6 = 0x1394;
  puVar6[1] = *(undefined4 *)(param_1 + 0x1af0);
  puVar6[2] = 0x850;
  puVar6[3] = *(undefined4 *)(param_1 + 0x1b80);
  puVar6[4] = 0x110ad;
  puVar6[5] = *(undefined4 *)(param_1 + 0x1b14);
  puVar6[6] = *(undefined4 *)(param_1 + 0x1b30);
  puVar6[7] = 0x110a2;
  puVar6[8] = *(undefined4 *)(param_1 + 0x1b3c);
  puVar6[9] = *(undefined4 *)(param_1 + 0x1b48);
  puVar6[10] = 0x108d;
  puVar6[0xb] = *(undefined4 *)(param_1 + 0x1b40);
  puVar6[0xc] = 0x1002;
  puVar6[0xd] = *(undefined4 *)(param_1 + 0x1b50);
  puVar6[0xe] = 0x1085;
  puVar6[0xf] = *(undefined4 *)(param_1 + 0x1b54);
  puVar6[0x10] = FUN_0000108e;
  puVar6[0x11] = *(undefined4 *)(param_1 + 0x1b64);
  puVar6[0x12] = 0x1098;
  puVar6[0x13] = *(undefined4 *)(param_1 + 0x1b68);
  puVar6[0x14] = 0x11099;
  puVar6[0x15] = *(undefined4 *)(param_1 + 0x1b6c);
  puVar6[0x16] = *(undefined4 *)(param_1 + 0x1b70);
  puVar6[0x17] = 0x823;
  puVar6[0x18] = 0;
  puVar6[0x19] = 0x11007;
  puVar6[0x1a] = *(undefined4 *)(param_1 + 0x1a64);
  puVar6[0x1b] = *(undefined4 *)(param_1 + 0x1a60);
  puVar6[0x1c] = 0x11004;
  puVar6[0x1d] = *(undefined4 *)(param_1 + 0x1a68);
  puVar6[0x1e] = *(undefined4 *)(param_1 + 0x1a6c);
  puVar6[0x1f] = 0x10fa;
  puVar6[0x20] = *(undefined4 *)(param_1 + 0x1b60);
  puVar6[0x21] = 0x13a2;
  puVar6[0x22] = *(undefined4 *)(param_1 + 0x23c0);
  puVar6[0x23] = 0x109d;
  puVar6[0x24] = *(undefined4 *)(param_1 + 0x1b4c);
  puVar6[0x25] = 0x10a8;
  puVar6[0x26] = *(undefined4 *)(param_1 + 0x1b28);
  puVar6[0x27] = 0x311a9;
  puVar6[0x28] = *(undefined4 *)(param_1 + 0x233c);
  puVar6[0x29] = *(undefined4 *)(param_1 + 0x2340);
  puVar6[0x2a] = *(undefined4 *)(param_1 + 0x2344);
  puVar6[0x2b] = *(undefined4 *)(param_1 + 0x2348);
  puVar6[0x2c] = 0x1385;
  puVar6[0x2d] = *(undefined4 *)(param_1 + 0x1a94);
  puVar6[0x2e] = 0x110a5;
  puVar6[0x2f] = *(undefined4 *)(param_1 + 0x1a7c);
  puVar6[0x30] = *(undefined4 *)(param_1 + 0x1a78);
  puVar6[0x31] = 0x109e;
  puVar6[0x32] = *(undefined4 *)(param_1 + 0x1b2c);
  puVar6[0x33] = 0x861;
  puVar6[0x34] = *(undefined4 *)(param_1 + 0x1ca0);
  puVar6[0x35] = 0x10824;
  puVar6[0x36] = *(undefined4 *)(param_1 + 0x1b9c);
  puVar6[0x37] = *(undefined4 *)(param_1 + 0x1ba0);
  puVar6[0x38] = 0x1082c;
  puVar6[0x39] = *(undefined4 *)(param_1 + 0x1b84);
  puVar6[0x3a] = *(undefined4 *)(param_1 + 0x248c);
  puVar6[0x3b] = 0x860;
  puVar6[0x3c] = *(undefined4 *)(param_1 + 0x1b78);
  puVar6[0x3d] = 0x887;
  puVar6[0x3e] = *(undefined4 *)(param_1 + 0x1b74);
  puVar6[0x3f] = 0x8a2;
  puVar6[0x40] = *(undefined4 *)(param_1 + 0x1b88);
  puVar6[0x41] = 0x877;
  puVar6[0x42] = *(undefined4 *)(param_1 + 0x1cb8);
  puVar6[0x43] = 0x1084d;
  puVar6[0x44] = 0xffffff;
  puVar6[0x45] = 0;
  puVar6[0x46] = 0x5c8;
  puVar6[0x47] = 0x8000;
  puVar6[0x48] = 0xc0001000;
  puVar6[0x49] = 0;
  puVar6[0x4a] = 0x10ea;
  puVar6[0x4b] = *(undefined4 *)(param_1 + 0x1abc);
  puVar6[0x4c] = 0x1096;
  puVar6[0x4d] = *(undefined4 *)(param_1 + 0x1bb8);
  puVar6[0x4e] = 0x1046;
  puVar6[0x4f] = *(undefined4 *)(param_1 + 0x1bbc);
  puVar6[0x50] = 0x1048;
  puVar6[0x51] = *(undefined4 *)(param_1 + 0x1bc0);
  puVar6[0x52] = 0x1047;
  puVar6[0x53] = *(undefined4 *)(param_1 + 0x1bb0);
  puVar6[0x54] = 0x1045;
  puVar6[0x55] = *(undefined4 *)(param_1 + 0x1bc4);
  puVar6[0x56] = 0x886;
  puVar6[0x57] = *(undefined4 *)(param_1 + 0x1bc8);
  puVar6[0x58] = 0x1180;
  puVar6[0x59] = 2;
  puVar5 = puVar6 + 0x5a;
  if ((*(byte *)(param_1 + 0x2454) & 0x10) != 0) {
    puVar6[0x5a] = 0x12fb;
    puVar6[0x5b] = *(undefined4 *)(param_1 + 0x1bcc);
    puVar6[0x5c] = 0x12fa;
    puVar6[0x5d] = *(undefined4 *)(param_1 + 0x1bd0);
    puVar6[0x5e] = 0x10e6;
    puVar6[0x5f] = *(undefined4 *)(param_1 + 0x1bd4);
    puVar6[0x60] = 0x11f2;
    puVar6[0x61] = *(undefined4 *)(param_1 + 0x1bd8);
    puVar5 = puVar6 + 0x62;
  }
  *(undefined4 **)(param_1 + 0x274c) = puVar5;
  (**(code **)(param_1 + 0x275c))(param_1,puVar5);
  ((int (*)())FUN_0004d534)(param_1);
  uVar11 = *(uint *)(param_1 + 0x27b0) |
           (*(uint *)(param_1 + 0x27b0) & *(uint *)(param_1 + 0x27b4)) << 8;
  if (uVar11 != 0) {
    piVar9 = (int *)(**(code **)(param_1 + 0x2758))(param_1,0xe0);
    *(int **)(param_1 + 0x274c) = piVar9;
    local_28 = (int *)(param_1 + 0x1cdc);
    local_2c = (int *)(param_1 + 0x1d1c);
    local_30 = (int *)(param_1 + 0x1d5c);
    local_34 = (int *)(param_1 + 0x1d9c);
    local_20 = (int *)(param_1 + 0x1ddc);
    local_24 = (int *)(param_1 + 0x1e1c);
    iVar10 = *(int *)(param_1 + 0x1938);
    do {
      if ((uVar11 & 1) != 0) {
        *piVar9 = iVar10 + 0x1100;
        piVar9[1] = *local_28;
        piVar9[2] = iVar10 + 0x1110;
        piVar9[3] = *local_2c;
        piVar9[4] = iVar10 + 0x1120;
        piVar9[5] = *local_30;
        piVar9[6] = iVar10 + 0x1130;
        piVar9[7] = *local_34;
        piVar9[8] = iVar10 + 0x1170;
        piVar9[9] = *local_24;
        piVar9[10] = iVar10 + 0x1160;
        piVar9[0xb] = 0;
        piVar9[0xc] = iVar10 + 0x1140;
        piVar9[0xd] = *local_20;
        piVar9 = piVar9 + 0xe;
      }
      iVar10 = iVar10 + 1;
      local_28 = local_28 + 1;
      local_2c = local_2c + 1;
      local_30 = local_30 + 1;
      local_34 = local_34 + 1;
      local_24 = local_24 + 1;
      local_20 = local_20 + 1;
      uVar11 = uVar11 >> 1;
    } while (uVar11 != 0);
    *(int **)(param_1 + 0x274c) = piVar9;
    (**(code **)(param_1 + 0x275c))(param_1,piVar9);
  }
  if ((*(char *)(param_1 + 0x46) < '\0') && ((*(byte *)(param_1 + 0x27b0) & 1) == 0)) {
    puVar5 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,4);
    *puVar5 = 0x1041;
    puVar5[1] = (*(uint *)(param_1 + 0x27b0) | 1) <<
                ((byte)*(undefined4 *)(param_1 + 0x1938) & 0x1f);
    puVar5[2] = *(int *)(param_1 + 0x1938) + 0x1100;
    puVar5[3] = 0;
    *(undefined4 **)(param_1 + 0x274c) = puVar5 + 4;
    (**(code **)(param_1 + 0x275c))(param_1,puVar5 + 4);
  }
  else {
    puVar5 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
    *puVar5 = 0x1041;
    puVar5[1] = *(int *)(param_1 + 0x27b0) << ((byte)*(undefined4 *)(param_1 + 0x1938) & 0x1f);
    *(undefined4 **)(param_1 + 0x274c) = puVar5 + 2;
    (**(code **)(param_1 + 0x275c))(param_1,puVar5 + 2);
  }
  uVar7 = (**(code **)(param_1 + 0x2758))(param_1,0x90);
  *(undefined4 *)(param_1 + 0x274c) = uVar7;
  puVar6 = (undefined4 *)((int (*)())FUN_0004c984)(param_1,uVar7);
  *puVar6 = 0x108c;
  puVar6[1] = *(undefined4 *)(param_1 + 0x1cd0);
  puVar6[2] = 0x1087;
  puVar6[3] = *(undefined4 *)(param_1 + 0x1ccc);
  puVar6[4] = 0x31080;
  puVar6[5] = *(undefined4 *)(param_1 + 0x1cbc);
  puVar6[6] = *(undefined4 *)(param_1 + 0x1cc4);
  puVar6[7] = *(undefined4 *)(param_1 + 0x1cc0);
  puVar6[8] = *(undefined4 *)(param_1 + 0x1cc8);
  puVar5 = puVar6 + 9;
  if ((*(int *)(iVar8 + 0x31c0) != 0) && (*(char *)(param_1 + 0x1491) != '\0')) {
    puVar6[9] = 0x13c2;
    puVar6[10] = *(undefined4 *)(param_1 + 0x1aa8);
    puVar5 = puVar6 + 0xb;
  }
  *puVar5 = 0x1386;
  puVar5[1] = *(undefined4 *)(param_1 + 0x1af8);
  puVar5[2] = 0x1383;
  puVar5[3] = *(undefined4 *)(param_1 + 0x1af4);
  puVar6 = puVar5 + 4;
  if ((*(byte *)(param_1 + 0x1b14) & 3) != 0) {
    puVar5[4] = 0x310a9;
    puVar5[5] = *(undefined4 *)(param_1 + 0x1b1c);
    puVar5[6] = *(undefined4 *)(param_1 + 0x1b18);
    puVar5[7] = *(undefined4 *)(param_1 + 0x1b24);
    puVar5[8] = *(undefined4 *)(param_1 + 0x1b20);
    puVar6 = puVar5 + 9;
  }
  puVar5 = (undefined4 *)((int (*)())FUN_0004c95e)(param_1,puVar6);
  *puVar5 = 0x112f5;
  uVar11 = *(uint *)(param_1 + 0x1a4c);
  puVar5[1] = uVar11;
  puVar3 = PTR_DAT_002131c9;
  if ((PTR_DAT_002131c9[(uint)*(byte *)(param_1 + 0x293f) * 0x24 + 0x1a] & 1) == 0) {
    puVar5[1] = uVar11 & 0xfffff7ff;
  }
  puVar5[2] = *(undefined4 *)(param_1 + 0x1a50);
  puVar5[3] = 0x12f8;
  puVar5[4] = *(undefined4 *)(param_1 + 0x1bdc);
  puVar5[5] = 0x212f2;
  puVar5[6] = *(undefined4 *)(param_1 + 0x1a54);
  puVar5[7] = *(undefined4 *)(param_1 + 0x1a58);
  puVar5[8] = *(undefined4 *)(param_1 + 0x1a5c);
  puVar5[9] = 0x1007;
  puVar5[10] = *(undefined4 *)(param_1 + 0x1a64);
  puVar5[0xb] = 0x12f0;
  uVar11 = *(uint *)(param_1 + 0x1aec);
  puVar5[0xc] = uVar11;
  if ((puVar3[(uint)*(byte *)(param_1 + 0x293f) * 0x24 + 0x1a] & 1) == 0) {
    puVar5[0xc] = uVar11 & 0xfffffffe;
  }
  puVar5[0xd] = 0x1109f;
  puVar5[0xe] = *(undefined4 *)(param_1 + 0x1a70);
  puVar5[0xf] = *(undefined4 *)(param_1 + 0x1a74);
  puVar5[0x10] = 0x11381;
  uVar11 = *(uint *)(param_1 + 0x1a80);
  puVar5[0x11] = uVar11;
  if ((puVar3[(uint)*(byte *)(param_1 + 0x293f) * 0x24 + 0x1a] & 2) == 0) {
    puVar5[0x11] = uVar11 & 0xfffffffc;
  }
  puVar5[0x12] = *(undefined4 *)(param_1 + 0x1a84);
  puVar5[0x13] = 0x1384;
  puVar5[0x14] = *(undefined4 *)(param_1 + 0x1a88);
  puVar5[0x15] = ((unsigned char *)0x000013be);
  puVar5[0x16] = *(undefined4 *)(param_1 + 0x1a8c);
  puVar5[0x17] = ((unsigned char *)0x000013bf);
  puVar5[0x18] = *(undefined4 *)(param_1 + 0x1a90);
  puVar5[0x19] = 0x13c5;
  puVar5[0x1a] = *(undefined4 *)(param_1 + 0x1ab8);
  puVar5[0x1b] = 0x113c0;
  puVar5[0x1c] = *(undefined4 *)(param_1 + 0x1aa0);
  puVar5[0x1d] = *(undefined4 *)(param_1 + 0x1aa4);
  puVar5[0x1e] = 0x110b0;
  puVar5[0x1f] = *(undefined4 *)(param_1 + 0x1b38);
  puVar5[0x20] = *(undefined4 *)(param_1 + 0x1b34);
  puVar5[0x21] = 0x100a;
  puVar5[0x22] = *(undefined4 *)(param_1 + 0x2354);
  puVar5[0x23] = 0x113a8;
  puVar5[0x24] = *(undefined4 *)(param_1 + 0x235c);
  puVar5[0x25] = *(undefined4 *)(param_1 + 0x2358);
  puVar5[0x26] = 0x413de;
  puVar5[0x27] = *(undefined4 *)(param_1 + 0x2360);
  puVar5[0x28] = *(undefined4 *)(param_1 + 0x2364);
  puVar5[0x29] = *(undefined4 *)(param_1 + 0x2368);
  puVar5[0x2a] = *(undefined4 *)(param_1 + 0x236c);
  puVar5[0x2b] = *(undefined4 *)(param_1 + 0x2370);
  puVar5[0x2c] = 0x313e9;
  puVar5[0x2d] = *(undefined4 *)(param_1 + 0x2374);
  puVar5[0x2e] = *(undefined4 *)(param_1 + 0x2378);
  puVar5[0x2f] = *(undefined4 *)(param_1 + 0x237c);
  puVar5[0x30] = *(undefined4 *)(param_1 + 0x2380);
  puVar5[0x31] = 0x813ad;
  puVar5[0x32] = *(undefined4 *)(param_1 + 0x2384);
  puVar5[0x33] = *(undefined4 *)(param_1 + 0x2388);
  puVar5[0x34] = *(undefined4 *)(param_1 + 0x238c);
  puVar5[0x35] = *(undefined4 *)(param_1 + 0x2390);
  puVar5[0x36] = *(undefined4 *)(param_1 + 0x2394);
  puVar5[0x37] = *(undefined4 *)(param_1 + 0x2398);
  puVar5[0x38] = *(undefined4 *)(param_1 + 0x239c);
  puVar5[0x39] = *(undefined4 *)(param_1 + 0x23a0);
  puVar5[0x3a] = *(undefined4 *)(param_1 + 0x23a4);
  puVar5[0x3b] = 0x13e6;
  puVar5[0x3c] = *(undefined4 *)(param_1 + 0x23c4);
  puVar5[0x3d] = 0x13e7;
  puVar5[0x3e] = *(undefined4 *)(param_1 + 0x23c8);
  puVar5[0x3f] = 0x13e8;
  puVar5[0x40] = *(undefined4 *)(param_1 + 0x23cc);
  if ((*(byte *)(param_1 + 0x45) & 0x40) == 0) {
    *(undefined4 *)(param_1 + 0x1e68) = 0;
  }
  *(undefined4 **)(param_1 + 0x274c) = puVar5 + 0x41;
  (**(code **)(param_1 + 0x275c))(param_1,puVar5 + 0x41);
  if (*(int *)(param_1 + 0x2494) != 0) {
    puVar5 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0x12);
    *(undefined4 **)(param_1 + 0x274c) = puVar5;
    *puVar5 = 0x830;
    puVar5[1] = *(undefined4 *)(param_1 + 0x2490);
    puVar5[2] = 0x831;
    puVar5[3] = **(undefined4 **)(param_1 + 0x2494);
    puVar5[4] = 0x834;
    puVar5[5] = *(undefined4 *)(*(int *)(param_1 + 0x2494) + 4);
    puVar5[6] = 0x837;
    puVar5[7] = *(undefined4 *)(*(int *)(param_1 + 0x2494) + 8);
    puVar5[8] = 0x83a;
    puVar5[9] = *(undefined4 *)(*(int *)(param_1 + 0x2494) + 0xc);
    puVar5[10] = 0x83d;
    puVar5[0xb] = *(undefined4 *)(*(int *)(param_1 + 0x2494) + 0x10);
    puVar5[0xc] = 0x840;
    puVar5[0xd] = *(undefined4 *)(*(int *)(param_1 + 0x2494) + 0x14);
    puVar5[0xe] = 0x843;
    puVar5[0xf] = *(undefined4 *)(*(int *)(param_1 + 0x2494) + 0x18);
    puVar5[0x10] = 0x846;
    puVar5[0x11] = *(undefined4 *)(*(int *)(param_1 + 0x2494) + 0x1c);
    iVar8 = *(int *)(param_1 + 0x274c) + 0x48;
    *(int *)(param_1 + 0x274c) = iVar8;
    (**(code **)(param_1 + 0x275c))(param_1,iVar8);
  }
  cVar4 = ((int (*)())FUN_000496b0)(param_1,1);
  if (cVar4 == '\0') {
    (**(code **)(param_1 + 0x1330))(param_1,0xc0100000);
    (**(code **)(param_1 + 0x1338))(param_1);
    FUN_000823ae(param_1);
  }
  bVar1 = *(byte *)(param_1 + 0x8d);
  *(byte *)(param_1 + 0x8d) = bVar1 | 0xa0;
  *(byte *)(param_1 + 0x8e) = *(byte *)(param_1 + 0x8e) | 1;
  *(undefined1 *)(param_1 + 0x23ec) = 1;
  if ((((*(byte *)(param_1 + 0x8c) & 10) == 0) && (*(code **)(param_1 + 0x12b0) != (code *)0x0)) &&
     ((bVar1 & 4) != 0)) {
    uVar7 = *(undefined4 *)(param_1 + 0x38);
    uVar2 = *(undefined4 *)(param_1 + 0x3c);
    (**(code **)(param_1 + 0x12b0))(param_1);
    *(undefined4 *)(param_1 + 0x38) = uVar7;
    *(undefined4 *)(param_1 + 0x3c) = uVar2;
    *(undefined1 *)(param_1 + 0x23ec) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 0x23ec) = 1;
  FUN_0009b26d(param_1);
  *(undefined1 *)(param_1 + 0x23ec) = 1;
  return;
}

/* FUN_0004fd18 @ 0x4fd18 (273 bytes) */
int FUN_0004fd18(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  
  uVar2 = (uint)(0x80 / (ulonglong)param_3);
  uVar3 = (uint)(0x80 / (ulonglong)param_2);
  if (uVar3 < uVar2) {
    uVar2 = uVar3;
  }
  if (10 < uVar2) {
    uVar2 = 10;
  }
  if (param_4 == 0) {
    uVar3 = 6;
    bVar1 = *(byte *)(param_1 + 0x1b7c);
  }
  else {
    uVar3 = (uint)(0x80 / (ulonglong)param_4);
    if (6 < uVar3) {
      uVar3 = 6;
    }
    bVar1 = *(byte *)(param_1 + 0x1b7c);
  }
  if ((uVar2 != (bVar1 & 0xf)) || (uVar3 != bVar1 >> 4)) {
    *(byte *)(param_1 + 0x1b7c) = (byte)uVar2 & 0xf | (char)uVar3 << 4;
    *(undefined1 *)(param_1 + 0x23ec) = 1;
  }
  if (*(char *)(param_1 + 0x23ec) != '\0') {
    puVar4 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,4);
    *(undefined4 **)(param_1 + 0x274c) = puVar4;
    *puVar4 = 0x8a1;
    puVar4[1] = 0;
    puVar4[2] = 0x820;
    puVar4[3] = *(undefined4 *)(param_1 + 0x1b7c);
    iVar5 = *(int *)(param_1 + 0x274c) + 0x10;
    *(int *)(param_1 + 0x274c) = iVar5;
    (**(code **)(param_1 + 0x275c))(param_1,iVar5);
    *(undefined1 *)(param_1 + 0x23ec) = 0;
  }
  return;
}

/* FUN_0004fe29 @ 0x4fe29 (1145 bytes) */
int FUN_0004fe29(param_1)
  int param_1;
{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  byte local_28;
  char local_15;
  char local_14;
  char local_13;
  char local_12;
  byte local_11;
  
  iVar2 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if ((*(int *)(iVar2 + 0x31c0) == 0) || (*(char *)(param_1 + 0x1491) == '\0')) {
    *(byte *)(param_1 + 0x1aa0) = *(byte *)(param_1 + 0x1aa0) & 0xfe;
  }
  else {
    *(byte *)(param_1 + 0x8c) = *(byte *)(param_1 + 0x8c) | 4;
    uVar3 = *(undefined4 *)(&DAT_001edf20 + (*(ushort *)(iVar2 + 0x31a0) & 7) * 4);
    uVar1 = *(ushort *)(iVar2 + 0x31a2);
    if (uVar1 == 0x1e02) {
      local_28 = 3;
    }
    else if (uVar1 < 0x1e03) {
      if (uVar1 == 0x150a) {
        local_28 = 5;
      }
      else if (uVar1 == 0x1e01) {
        local_28 = 2;
      }
      else if (uVar1 == 0) {
        local_28 = 1;
      }
      else {
LAB_0004ff0b:
        local_28 = 0;
      }
    }
    else if (uVar1 == 0x8507) {
      local_28 = 6;
    }
    else if (uVar1 == 0x8508) {
      local_28 = 7;
    }
    else {
      if (uVar1 != 0x1e03) goto LAB_0004ff0b;
      local_28 = 4;
    }
    uVar1 = *(ushort *)(iVar2 + 0x31a6);
    if (uVar1 == 0x1e02) {
      local_15 = '\x03';
    }
    else if (uVar1 < 0x1e03) {
      if (uVar1 == 0x150a) {
        local_15 = '\x05';
      }
      else if (uVar1 == 0x1e01) {
        local_15 = '\x02';
      }
      else if (uVar1 == 0) {
        local_15 = '\x01';
      }
      else {
LAB_0004ff2f:
        local_15 = '\0';
      }
    }
    else if (uVar1 == 0x8507) {
      local_15 = '\x06';
    }
    else if (uVar1 == 0x8508) {
      local_15 = '\a';
    }
    else {
      if (uVar1 != 0x1e03) goto LAB_0004ff2f;
      local_15 = '\x04';
    }
    uVar1 = *(ushort *)(iVar2 + 0x31a4);
    if (uVar1 == 0x1e02) {
      local_14 = '\x03';
    }
    else if (uVar1 < 0x1e03) {
      if (uVar1 == 0x150a) {
        local_14 = '\x05';
      }
      else if (uVar1 == 0x1e01) {
        local_14 = '\x02';
      }
      else if (uVar1 == 0) {
        local_14 = '\x01';
      }
      else {
LAB_0004ff85:
        local_14 = '\0';
      }
    }
    else if (uVar1 == 0x8507) {
      local_14 = '\x06';
    }
    else if (uVar1 == 0x8508) {
      local_14 = '\a';
    }
    else {
      if (uVar1 != 0x1e03) goto LAB_0004ff85;
      local_14 = '\x04';
    }
    *(char *)(param_1 + 0x1aa8) = (char)*(undefined4 *)(iVar2 + 0x319c);
    *(char *)(param_1 + 0x1aa9) = (char)*(undefined4 *)(iVar2 + 0x3198);
    *(char *)(param_1 + 0x1aaa) = (char)*(undefined4 *)(iVar2 + 0x2e38);
    uVar4 = *(uint *)(&DAT_001edf20 + (*(ushort *)(iVar2 + 0x31b8) & 7) * 4);
    uVar1 = *(ushort *)(iVar2 + 0x31ba);
    if (uVar1 == 0x1e02) {
      local_13 = '\x03';
    }
    else if (uVar1 < 0x1e03) {
      if (uVar1 == 0x150a) {
        local_13 = '\x05';
      }
      else if (uVar1 == 0x1e01) {
        local_13 = '\x02';
      }
      else if (uVar1 == 0) {
        local_13 = '\x01';
      }
      else {
LAB_0005000c:
        local_13 = '\0';
      }
    }
    else if (uVar1 == 0x8507) {
      local_13 = '\x06';
    }
    else if (uVar1 == 0x8508) {
      local_13 = '\a';
    }
    else {
      if (uVar1 != 0x1e03) goto LAB_0005000c;
      local_13 = '\x04';
    }
    uVar1 = *(ushort *)(iVar2 + 0x31be);
    if (uVar1 == 0x1e02) {
      local_12 = '\x03';
    }
    else if (uVar1 < 0x1e03) {
      if (uVar1 == 0x150a) {
        local_12 = '\x05';
      }
      else if (uVar1 == 0x1e01) {
        local_12 = '\x02';
      }
      else if (uVar1 == 0) {
        local_12 = '\x01';
      }
      else {
LAB_00050062:
        local_12 = '\0';
      }
    }
    else if (uVar1 == 0x8507) {
      local_12 = '\x06';
    }
    else if (uVar1 == 0x8508) {
      local_12 = '\a';
    }
    else {
      if (uVar1 != 0x1e03) goto LAB_00050062;
      local_12 = '\x04';
    }
    uVar1 = *(ushort *)(iVar2 + 0x31bc);
    if (uVar1 == 0x1e02) {
      local_11 = 3;
    }
    else if (uVar1 < 0x1e03) {
      if (uVar1 == 0x150a) {
        local_11 = 5;
      }
      else if (uVar1 == 0x1e01) {
        local_11 = 2;
      }
      else if (uVar1 == 0) {
        local_11 = 1;
      }
      else {
LAB_000500b8:
        local_11 = 0;
      }
    }
    else if (uVar1 == 0x8507) {
      local_11 = 6;
    }
    else if (uVar1 == 0x8508) {
      local_11 = 7;
    }
    else {
      if (uVar1 != 0x1e03) goto LAB_000500b8;
      local_11 = 4;
    }
    *(byte *)(param_1 + 0x1aa0) = *(byte *)(param_1 + 0x1aa0) | 1;
    *(byte *)(param_1 + 0x1aa4) = *(byte *)(param_1 + 0x1aa4) & 199 | ((byte)uVar3 & 7) << 3;
    *(ushort *)(param_1 + 0x1aa4) = *(ushort *)(param_1 + 0x1aa4) & 0xfe3f | (ushort)local_28 << 6;
    *(uint *)(param_1 + 0x1aa4) = *(uint *)(param_1 + 0x1aa4) & 0xfffc7fff | (uVar4 & 7) << 0xf;
    *(byte *)(param_1 + 0x1aa5) =
         *(byte *)(param_1 + 0x1aa5) & 0x81 | local_15 * '\x02' | local_14 << 4;
    *(byte *)(param_1 + 0x1aa6) = *(byte *)(param_1 + 0x1aa6) & 3 | local_13 << 2 | local_12 << 5;
    *(byte *)(param_1 + 0x1aa7) = *(byte *)(param_1 + 0x1aa7) & 0xf8 | local_11;
    *(undefined1 *)(param_1 + 0x23ed) = 1;
    if ((*(int *)(iVar2 + 0x2e38) != 0) && ((*(uint *)(param_1 + 0x1aa4) & 0x7fc7fc0) != 0))
    goto LAB_0004fe61;
  }
  *(undefined1 *)(param_1 + 0x23ed) = 0;
LAB_0004fe61:
  *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x808;
  return;
}

/* FUN_000502a2 @ 0x502a2 (3258 bytes) */
int FUN_000502a2(param_1)
  int param_1;
{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined *puVar8;
  double dVar9;
  bool bVar10;
  bool bVar11;
  float fVar12;
  float fVar13;
  undefined2 uVar14;
  char cVar15;
  byte bVar16;
  char cVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  uint local_bc;
  char local_22;
  char local_21;
  byte local_20;
  byte local_1f;
  undefined1 local_1e;
  byte local_1d;
  
  iVar5 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  bVar1 = *(byte *)(param_1 + 0x1a80);
  iVar6 = *(int *)(param_1 + 0x1af8);
  *(byte *)(param_1 + 0x1a80) = bVar1 & 0xfe;
  *(byte *)(param_1 + 0x1a83) = *(byte *)(param_1 + 0x1a83) & 0x3f;
  if (((*(char *)(iVar5 + 0x2d84) == '\0') || (*(char *)(iVar5 + 0x2e33) != '\0')) ||
     ((*(int *)(iVar5 + 0x2d80) == -0x7ff97ffa &&
      ((((*(short *)(iVar5 + 0x2d68) == 1 && (*(short *)(iVar5 + 0x2d6c) == 1)) &&
        (*(short *)(iVar5 + 0x2d6a) == 0)) && (*(short *)(iVar5 + 0x2d6e) == 0))))))
  goto LAB_00050304;
  uVar2 = *(ushort *)(iVar5 + 0x2d80);
  if (uVar2 == 0x8008) {
    bVar10 = true;
    local_22 = '\x05';
  }
  else if (uVar2 < 0x8009) {
    if (uVar2 == 0x8007) {
      bVar10 = true;
      local_22 = '\x04';
    }
    else {
LAB_00050401:
      bVar10 = false;
      local_22 = '\0';
    }
  }
  else if (uVar2 == 0x800a) {
    bVar10 = false;
    local_22 = '\x02';
  }
  else {
    if (uVar2 != 0x800b) goto LAB_00050401;
    bVar10 = false;
    local_22 = '\x06';
  }
  uVar3 = *(ushort *)(iVar5 + 0x2d82);
  if (uVar3 == 0x8008) {
    bVar11 = true;
    local_21 = '\x05';
  }
  else if (uVar3 < 0x8009) {
    if (uVar3 == 0x8007) {
      bVar11 = true;
      local_21 = '\x04';
    }
    else {
LAB_0005042d:
      bVar11 = false;
      local_21 = '\0';
    }
  }
  else if (uVar3 == 0x800a) {
    bVar11 = false;
    local_21 = '\x02';
  }
  else {
    if (uVar3 != 0x800b) goto LAB_0005042d;
    bVar11 = false;
    local_21 = '\x06';
  }
  uVar3 = *(ushort *)(iVar5 + 0x2d68);
  if (uVar3 == 0x305) {
    local_1f = 0x29;
    bVar10 = true;
    local_20 = 0x29;
  }
  else if (uVar3 < 0x306) {
    if (uVar3 == 0x301) {
      local_1f = 0x23;
      local_20 = 0x23;
    }
    else if (uVar3 < 0x302) {
      if (uVar3 == 0) {
        local_1f = 0x20;
        local_20 = 0x20;
      }
      else {
        if (uVar3 != 0x300) goto LAB_00050b24;
        local_1f = 0x22;
        local_20 = 0x22;
      }
    }
    else if (uVar3 == 0x303) {
      local_1f = 0x27;
      local_20 = 0x27;
    }
    else if (uVar3 < 0x304) {
      local_1f = 0x26;
      local_20 = 0x26;
    }
    else {
      local_1f = 0x28;
      bVar10 = true;
      local_20 = 0x28;
    }
  }
  else if (uVar3 == 0x8001) {
    local_1f = 0x2b;
    local_20 = 0x2b;
  }
  else if (uVar3 < 0x8002) {
    if (uVar3 == 0x307) {
      local_1f = 0x25;
      bVar10 = true;
      local_20 = 0x25;
    }
    else if (uVar3 < 0x307) {
      local_1f = 0x24;
      bVar10 = true;
      local_20 = 0x24;
    }
    else {
      if (uVar3 != 0x308) goto LAB_00050b24;
      local_1f = 0x2a;
      bVar10 = true;
      local_20 = 0x2a;
    }
  }
  else if (uVar3 == 0x8003) {
    local_1f = 0x2d;
    local_20 = 0x2d;
  }
  else if (uVar3 < 0x8003) {
    local_1f = 0x2c;
    local_20 = 0x2c;
  }
  else if (uVar3 == 0x8004) {
    local_1f = 0x2e;
    local_20 = 0x2e;
  }
  else {
LAB_00050b24:
    local_1f = 0x21;
    local_20 = 0x21;
  }
  uVar4 = *(ushort *)(iVar5 + 0x2d6c);
  if (uVar3 != uVar4) {
    if (uVar4 == 0x305) {
      bVar11 = true;
      local_1f = 0x29;
    }
    else if (uVar4 < 0x306) {
      if (uVar4 == 0x301) {
        local_1f = 0x23;
      }
      else if (uVar4 < 0x302) {
        if (uVar4 == 0) {
          local_1f = 0x20;
        }
        else {
          if (uVar4 != 0x300) goto LAB_00050604;
          local_1f = 0x22;
        }
      }
      else if (uVar4 == 0x303) {
        local_1f = 0x27;
      }
      else if (uVar4 < 0x304) {
        local_1f = 0x26;
      }
      else {
        bVar11 = true;
        local_1f = 0x28;
      }
    }
    else if (uVar4 == 0x8001) {
      local_1f = 0x2b;
    }
    else if (uVar4 < 0x8002) {
      if (uVar4 == 0x307) {
        bVar11 = true;
        local_1f = 0x25;
      }
      else if (uVar4 < 0x307) {
        bVar11 = true;
        local_1f = 0x24;
      }
      else if (uVar4 == 0x308) {
        bVar11 = true;
        local_1f = 0x2a;
      }
      else {
LAB_00050604:
        local_1f = 0x21;
      }
    }
    else if (uVar4 == 0x8003) {
      local_1f = 0x2d;
    }
    else if (uVar4 < 0x8003) {
      local_1f = 0x2c;
    }
    else {
      if (uVar4 != 0x8004) goto LAB_00050604;
      local_1f = 0x2e;
    }
  }
  uVar3 = *(ushort *)(iVar5 + 0x2d6a);
  if (uVar3 == 0x305) {
    local_1d = 0x29;
    bVar10 = true;
    local_1e = 0x29;
  }
  else if (uVar3 < 0x306) {
    if (uVar3 == 0x301) {
      local_1d = 0x23;
      bVar10 = true;
      local_1e = 0x23;
    }
    else if (uVar3 < 0x302) {
      if (uVar3 == 1) {
        local_1d = 0x21;
        bVar10 = true;
        local_1e = 0x21;
      }
      else {
        if (uVar3 != 0x300) goto LAB_00050adc;
        local_1d = 0x22;
        bVar10 = true;
        local_1e = 0x22;
      }
    }
    else if (uVar3 == 0x303) {
      local_1d = 0x27;
      bVar10 = true;
      local_1e = 0x27;
    }
    else if (uVar3 < 0x304) {
      local_1d = 0x26;
      bVar10 = true;
      local_1e = 0x26;
    }
    else {
      local_1d = 0x28;
      bVar10 = true;
      local_1e = 0x28;
    }
  }
  else if (uVar3 == 0x8001) {
    local_1d = 0x2b;
    bVar10 = true;
    local_1e = 0x2b;
  }
  else if (uVar3 < 0x8002) {
    if (uVar3 == 0x306) {
      local_1d = 0x24;
      bVar10 = true;
      local_1e = 0x24;
    }
    else if (uVar3 == 0x307) {
      local_1d = 0x25;
      bVar10 = true;
      local_1e = 0x25;
    }
    else {
LAB_00050adc:
      local_1d = 0x20;
      local_1e = 0x20;
    }
  }
  else if (uVar3 == 0x8003) {
    local_1d = 0x2d;
    bVar10 = true;
    local_1e = 0x2d;
  }
  else if (uVar3 < 0x8003) {
    local_1d = 0x2c;
    bVar10 = true;
    local_1e = 0x2c;
  }
  else {
    if (uVar3 != 0x8004) goto LAB_00050adc;
    local_1d = 0x2e;
    bVar10 = true;
    local_1e = 0x2e;
  }
  uVar4 = *(ushort *)(iVar5 + 0x2d6e);
  if (uVar3 != uVar4) {
    if (uVar4 == 0x305) {
      bVar11 = true;
      local_1d = 0x29;
    }
    else if (uVar4 < 0x306) {
      if (uVar4 == 0x301) {
        bVar11 = true;
        local_1d = 0x23;
      }
      else if (uVar4 < 0x302) {
        if (uVar4 == 1) {
          bVar11 = true;
          local_1d = 0x21;
        }
        else {
          if (uVar4 != 0x300) goto LAB_000506f0;
          bVar11 = true;
          local_1d = 0x22;
        }
      }
      else if (uVar4 == 0x303) {
        bVar11 = true;
        local_1d = 0x27;
      }
      else if (uVar4 < 0x304) {
        bVar11 = true;
        local_1d = 0x26;
      }
      else {
        bVar11 = true;
        local_1d = 0x28;
      }
    }
    else if (uVar4 == 0x8001) {
      bVar11 = true;
      local_1d = 0x2b;
    }
    else if (uVar4 < 0x8002) {
      if (uVar4 == 0x306) {
        bVar11 = true;
        local_1d = 0x24;
      }
      else if (uVar4 == 0x307) {
        bVar11 = true;
        local_1d = 0x25;
      }
      else {
LAB_000506f0:
        local_1d = 0x20;
      }
    }
    else if (uVar4 == 0x8003) {
      bVar11 = true;
      local_1d = 0x2d;
    }
    else if (uVar4 < 0x8003) {
      bVar11 = true;
      local_1d = 0x2c;
    }
    else {
      if (uVar4 != 0x8004) goto LAB_000506f0;
      bVar11 = true;
      local_1d = 0x2e;
    }
  }
  if ((uVar2 == 0x8006) &&
     (puVar8 = *(undefined **)(iVar5 + 0x2d68), puVar8 == *(undefined **)(iVar5 + 0x2d6c))) {
    if ((puVar8 == (undefined *)0x3030302) ||
       ((puVar8 == (undefined *)0x10302 || (puVar8 == (undefined *)0x3030000)))) {
      cVar17 = '\x01';
    }
    else if ((((puVar8 == (undefined *)0x3010000) || (puVar8 == ((unsigned char *)0x00010001))) ||
             (puVar8 == (undefined *)0x10306)) || (puVar8 == (undefined *)0x10304)) {
      if ((*(byte *)(param_1 + 0x8d) & 2) == 0) goto LAB_00050f8b;
      cVar17 = '\x02';
    }
    else if (puVar8 == (undefined *)0x10307) {
LAB_00050f8b:
      cVar17 = '\x03';
    }
    else if (puVar8 == (undefined *)0x10303) {
      cVar17 = '\x04';
    }
    else {
      if (puVar8 != (undefined *)0x306) goto LAB_00050705;
      cVar17 = '\x06';
    }
  }
  else {
LAB_00050705:
    cVar17 = '\0';
  }
  *(byte *)(param_1 + 0x1a80) = bVar1 & 0xfe | 3;
  if ((bVar10) || (bVar11)) {
    cVar15 = '\x01';
  }
  else {
    cVar15 = '\0';
  }
  *(byte *)(param_1 + 0x1a80) = bVar1 & 0xc2 | 3 | cVar15 << 2 | cVar17 << 3;
  *(byte *)(param_1 + 0x1a81) = *(byte *)(param_1 + 0x1a81) & 0x8f | local_22 << 4;
  *(byte *)(param_1 + 0x1a82) = *(byte *)(param_1 + 0x1a82) & 0xc0 | local_20;
  *(undefined1 *)(param_1 + 0x1a83) = local_1e;
  *(byte *)(param_1 + 0x1a85) = *(byte *)(param_1 + 0x1a85) & 0x8f | local_21 << 4;
  *(byte *)(param_1 + 0x1a86) = *(byte *)(param_1 + 0x1a86) & 0xc0 | local_1f;
  *(byte *)(param_1 + 0x1a87) = *(byte *)(param_1 + 0x1a87) & 0xc0 | local_1d;
  dVar18 = (double)*(float *)(iVar5 + 0x2d7c) * DOUBLE_001cf380;
  dVar19 = dVar18;
  if (DAT_001c61f0 <= dVar18) {
    dVar19 = DAT_001c61f0;
  }
  if (dVar19 <= 0.0) {
    dVar19 = 0.0;
  }
  dVar20 = (double)*(float *)(iVar5 + 0x2d70) * DOUBLE_001cf380;
  dVar21 = dVar20;
  if (DAT_001c61f0 <= dVar20) {
    dVar21 = DAT_001c61f0;
  }
  if (dVar21 <= 0.0) {
    dVar21 = 0.0;
  }
  dVar22 = (double)*(float *)(iVar5 + 0x2d74) * DOUBLE_001cf380;
  dVar23 = dVar22;
  if (DAT_001c61f0 <= dVar22) {
    dVar23 = DAT_001c61f0;
  }
  if (dVar23 <= 0.0) {
    dVar23 = 0.0;
  }
  dVar24 = (double)*(float *)(iVar5 + 0x2d78) * DOUBLE_001cf380;
  dVar9 = dVar24;
  if (DAT_001c61f0 <= dVar24) {
    dVar9 = DAT_001c61f0;
  }
  if (dVar9 <= 0.0) {
    dVar9 = 0.0;
  }
  local_bc = (uint)(DAT_001c61e0 <= dVar24) * -0x80000000 ^
             (int)(dVar9 - (double)((ulonglong)DAT_001c61e0 & -(ulonglong)(DAT_001c61e0 <= dVar24)))
  ;
  *(uint *)(param_1 + 0x1a88) =
       (int)(dVar19 - (double)(-(ulonglong)(DAT_001c61e0 <= dVar18) & (ulonglong)DAT_001c61e0)) <<
       0x18 | (int)(dVar21 - (double)(-(ulonglong)(DAT_001c61e0 <= dVar20) & (ulonglong)DAT_001c61e0
                                     )) << 0x10 |
       (int)(dVar23 - (double)(-(ulonglong)(DAT_001c61e0 <= dVar22) & (ulonglong)DAT_001c61e0)) << 8
       | local_bc;
  fVar13 = FLOAT_001c5c0c;
  fVar12 = FLOAT_001c5bd4;
  if ((PTR_DAT_002131c9[(uint)*(byte *)(param_1 + 0x293f) * 0x24 + 0x1a] & 0x3c) == 0x28) {
    uVar14 = FUN_0001b725(*(undefined4 *)(iVar5 + 0x2d70));
    *(undefined2 *)(param_1 + 0x1a8c) = uVar14;
    uVar14 = FUN_0001b725(*(undefined4 *)(iVar5 + 0x2d7c));
    *(undefined2 *)(param_1 + 0x1a8e) = uVar14;
    uVar14 = FUN_0001b725(*(undefined4 *)(iVar5 + 0x2d78));
    *(undefined2 *)(param_1 + 0x1a90) = uVar14;
    uVar14 = FUN_0001b725(*(undefined4 *)(iVar5 + 0x2d74));
    *(undefined2 *)(param_1 + 0x1a92) = uVar14;
  }
  else {
    *(short *)(param_1 + 0x1a8c) =
         (short)(int)(*(float *)(iVar5 + 0x2d70) * FLOAT_001c5c0c + FLOAT_001c5bd4);
    *(short *)(param_1 + 0x1a8e) = (short)(int)(*(float *)(iVar5 + 0x2d7c) * fVar13 + fVar12);
    *(short *)(param_1 + 0x1a90) = (short)(int)(*(float *)(iVar5 + 0x2d78) * fVar13 + fVar12);
    *(short *)(param_1 + 0x1a92) = (short)(int)(fVar13 * *(float *)(iVar5 + 0x2d74) + fVar12);
  }
LAB_00050304:
  if ((*(char *)(iVar5 + 0x2ddc) == '\0') || ((*(uint *)(*(int *)(param_1 + 4) + 0x154) & 0xf) != 3)
     ) {
    *(byte *)(param_1 + 0x1af0) = *(byte *)(param_1 + 0x1af0) & 0xf0 | 5;
  }
  else {
    *(byte *)(param_1 + 0x1af0) = *(byte *)(param_1 + 0x1af0) & 0xf0 | 6;
  }
  if ((*(char *)(iVar5 + 0x2e33) == '\0') || (*(char *)(param_1 + 0x1492) != '\0')) {
    *(byte *)(param_1 + 0x1af8) = *(byte *)(param_1 + 0x1af8) & 0xfb;
  }
  else {
    switch(*(undefined2 *)(iVar5 + 0x2e30)) {
    case 0x1500:
      bVar16 = 0;
      break;
    case 0x1501:
      bVar16 = 8;
      break;
    case 0x1502:
      bVar16 = 4;
      break;
    default:
      bVar16 = 0xc;
      break;
    case 0x1504:
      bVar16 = 2;
      break;
    case 0x1505:
      bVar16 = 10;
      break;
    case 0x1506:
      bVar16 = 6;
      break;
    case 0x1507:
      bVar16 = 0xe;
      break;
    case 0x1508:
      bVar16 = 1;
      break;
    case 0x1509:
      bVar16 = 9;
      break;
    case 0x150a:
      bVar16 = 5;
      break;
    case 0x150b:
      bVar16 = 0xd;
      break;
    case 0x150c:
      bVar16 = 3;
      break;
    case 0x150d:
      bVar16 = 0xb;
      break;
    case 0x150e:
      bVar16 = 7;
      break;
    case 0x150f:
      bVar16 = 0xf;
    }
    *(byte *)(param_1 + 0x1af9) = *(byte *)(param_1 + 0x1af9) & 0xf0 | bVar16;
    *(byte *)(param_1 + 0x1af8) = *(byte *)(param_1 + 0x1af8) | 4;
  }
  uVar7 = *(uint *)(param_1 + 0x1930);
  *(uint *)(param_1 + 0x1930) = uVar7 | 4;
  if (iVar6 != *(int *)(param_1 + 0x1af8)) {
    *(uint *)(param_1 + 0x1930) = uVar7 | 0x10004;
  }
  if (((bVar1 & 1) == 0) && ((*(byte *)(param_1 + 0x1a80) & 1) != 0)) {
    *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x100;
  }
  return;
}

/* FUN_00050f9f @ 0x50f9f (393 bytes) */
int FUN_00050f9f(param_1)
  int param_1;
{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  
  iVar3 = *(int *)(param_1 + 4);
  iVar4 = *(int *)(iVar3 + 0x10);
  iVar5 = *(int *)(param_1 + 0x1c8c);
  iVar6 = *(int *)(param_1 + 0x1c88);
  iVar7 = *(int *)(param_1 + 0x1c94);
  iVar8 = *(int *)(param_1 + 0x1c90);
  iVar9 = *(int *)(param_1 + 0x1c9c);
  iVar10 = *(int *)(param_1 + 0x1c98);
  *(undefined4 *)(param_1 + 0x1c9c) = *(undefined4 *)(iVar4 + 0x1818);
  *(undefined4 *)(param_1 + 0x1c98) = *(undefined4 *)(iVar4 + 0x1828);
  fVar1 = *(float *)(iVar3 + 0x2a54);
  fVar2 = *(float *)(iVar3 + 0x2a58);
  fVar13 = (float)*(int *)(iVar4 + 0x184c) * fVar2 * FLOAT_001c5bd4;
  fVar12 = (float)*(int *)(iVar4 + 0x1844) * fVar2 + fVar13;
  fVar11 = (float)*(int *)(iVar4 + 0x1848) * fVar1 * FLOAT_001c5bd4;
  iVar4 = *(int *)(iVar4 + 0x1840);
  if (*(char *)(param_1 + 0x293c) != '\0') {
    fVar13 = (float)((uint)fVar13 ^ _DAT_001c6200);
    fVar12 = (float)*(int *)(iVar3 + 0x160) * fVar2 - fVar12;
  }
  *(float *)(param_1 + 0x1c8c) = fVar11;
  *(float *)(param_1 + 0x1c88) = (float)iVar4 * fVar1 + fVar11;
  *(float *)(param_1 + 0x1c94) = fVar13;
  *(float *)(param_1 + 0x1c90) = fVar12;
  if (*(char *)(param_1 + 0x124) != '\0') {
    *(undefined4 *)(param_1 + 0x1c8c) = *(undefined4 *)(param_1 + 0x2814);
    *(undefined4 *)(param_1 + 0x1c94) = *(undefined4 *)(param_1 + 0x2818);
  }
  *(undefined4 *)(param_1 + 0x1cb0) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x1ca8) = 0x3f800000;
  if ((((iVar5 != *(int *)(param_1 + 0x1c8c)) || (iVar6 != *(int *)(param_1 + 0x1c88))) ||
      (iVar7 != *(int *)(param_1 + 0x1c94))) ||
     (((iVar8 != *(int *)(param_1 + 0x1c90) || (iVar9 != *(int *)(param_1 + 0x1c9c))) ||
      (iVar10 != *(int *)(param_1 + 0x1c98))))) {
    *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x80;
  }
  ((int (*)())FUN_0004e04d)();
  return;
}

/* FUN_00051128 @ 0x51128 (2692 bytes) */
int FUN_00051128(param_1)
  int param_1;
{
  uint *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  short local_34;
  int *local_30;
  int *local_2c;
  int *local_28;
  int *local_24;
  int *local_20;
  
  uVar3 = *(uint *)(param_1 + 0x1930);
  uVar7 = *(uint *)(param_1 + 0x1934) & *(uint *)(param_1 + 0x27b0);
  uVar7 = uVar7 | (uVar7 & *(uint *)(param_1 + 0x27b4)) << 8;
  if (uVar7 != 0) {
    piVar4 = (int *)(**(code **)(param_1 + 0x2758))(param_1,0xe0);
    *(int **)(param_1 + 0x274c) = piVar4;
    local_20 = (int *)(param_1 + 0x1cdc);
    local_24 = (int *)(param_1 + 0x1d1c);
    local_28 = (int *)(param_1 + 0x1d5c);
    local_2c = (int *)(param_1 + 0x1d9c);
    local_30 = (int *)(param_1 + 0x1ddc);
    piVar9 = (int *)(param_1 + 0x1e1c);
    iVar8 = *(int *)(param_1 + 0x1938);
    do {
      if ((uVar7 & 1) != 0) {
        *piVar4 = iVar8 + 0x1100;
        piVar4[1] = *local_20;
        piVar4[2] = iVar8 + 0x1110;
        piVar4[3] = *local_24;
        piVar4[4] = iVar8 + 0x1120;
        piVar4[5] = *local_28;
        piVar4[6] = iVar8 + 0x1130;
        piVar4[7] = *local_2c;
        piVar4[8] = iVar8 + 0x1170;
        piVar4[9] = *piVar9;
        piVar4[10] = iVar8 + 0x1160;
        piVar4[0xb] = 0;
        piVar4[0xc] = iVar8 + 0x1140;
        piVar4[0xd] = *local_30;
        piVar4 = piVar4 + 0xe;
      }
      iVar8 = iVar8 + 1;
      local_20 = local_20 + 1;
      local_24 = local_24 + 1;
      local_28 = local_28 + 1;
      local_2c = local_2c + 1;
      piVar9 = piVar9 + 1;
      local_30 = local_30 + 1;
      uVar7 = uVar7 >> 1;
    } while (uVar7 != 0);
    *(int **)(param_1 + 0x274c) = piVar4;
    (**(code **)(param_1 + 0x275c))(param_1,piVar4);
  }
  if ((*(char *)(param_1 + 0x46) < '\0') && ((*(byte *)(param_1 + 0x27b0) & 1) == 0)) {
    puVar2 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,4);
    *puVar2 = 0x1041;
    puVar2[1] = (*(uint *)(param_1 + 0x27b0) | 1) <<
                ((byte)*(undefined4 *)(param_1 + 0x1938) & 0x1f);
    puVar2[2] = *(int *)(param_1 + 0x1938) + 0x1100;
    puVar2[3] = 0;
    *(undefined4 **)(param_1 + 0x274c) = puVar2 + 4;
    (**(code **)(param_1 + 0x275c))(param_1,puVar2 + 4);
  }
  else {
    puVar2 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
    *puVar2 = 0x1041;
    puVar2[1] = *(int *)(param_1 + 0x27b0) << ((byte)*(undefined4 *)(param_1 + 0x1938) & 0x1f);
    *(undefined4 **)(param_1 + 0x274c) = puVar2 + 2;
    (**(code **)(param_1 + 0x275c))(param_1,puVar2 + 2);
  }
  if (uVar3 == 0) {
    *(undefined4 *)(param_1 + 0x1934) = 0;
    return;
  }
  puVar2 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0xde);
  *(undefined4 **)(param_1 + 0x274c) = puVar2;
  if ((uVar3 & 0x100) != 0) {
    *puVar2 = 0x1393;
    puVar2[1] = 10;
    puVar2 = puVar2 + 2;
  }
  if ((uVar3 & 0x2000000) != 0) {
    *puVar2 = 0x13c6;
    puVar2[1] = 3;
    puVar2 = puVar2 + 2;
  }
  if ((uVar3 & 1) != 0) {
    *puVar2 = 0x212f2;
    puVar2[1] = *(undefined4 *)(param_1 + 0x1a54);
    puVar2[2] = *(undefined4 *)(param_1 + 0x1a58);
    puVar2[3] = *(undefined4 *)(param_1 + 0x1a5c);
    puVar2[4] = 0x12f0;
    uVar7 = *(uint *)(param_1 + 0x1aec);
    puVar2[5] = uVar7;
    if ((PTR_DAT_002131c9[(uint)*(byte *)(param_1 + 0x293f) * 0x24 + 0x1a] & 1) == 0) {
      puVar2[5] = uVar7 & 0xfffffffe;
    }
    puVar2[6] = 0x110a5;
    puVar2[7] = *(undefined4 *)(param_1 + 0x1a7c);
    puVar2[8] = *(undefined4 *)(param_1 + 0x1a78);
    puVar2[9] = 0x1007;
    puVar2[10] = *(undefined4 *)(param_1 + 0x1a64);
    puVar2 = puVar2 + 0xb;
  }
  if ((uVar3 & 4) != 0) {
    *puVar2 = 0x11381;
    uVar7 = *(uint *)(param_1 + 0x1a80);
    puVar2[1] = uVar7;
    if ((PTR_DAT_002131c9[(uint)*(byte *)(param_1 + 0x293f) * 0x24 + 0x1a] & 2) == 0) {
      puVar2[1] = uVar7 & 0xfffffffc;
    }
    puVar2[2] = *(undefined4 *)(param_1 + 0x1a84);
    puVar2[3] = 0x1384;
    puVar2[4] = *(undefined4 *)(param_1 + 0x1a88);
    puVar2[5] = 0x1394;
    puVar2[6] = *(undefined4 *)(param_1 + 0x1af0);
    puVar2[7] = ((unsigned char *)0x000013be);
    puVar2[8] = *(undefined4 *)(param_1 + 0x1a8c);
    puVar2[9] = ((unsigned char *)0x000013bf);
    puVar2[10] = *(undefined4 *)(param_1 + 0x1a90);
    puVar2 = puVar2 + 0xb;
  }
  if ((uVar3 & 0x10000) != 0) {
    *puVar2 = 0x1386;
    puVar2[1] = *(undefined4 *)(param_1 + 0x1af8);
    puVar2 = puVar2 + 2;
  }
  if ((uVar3 & 0x200) != 0) {
    *puVar2 = 0x12f5;
    uVar7 = *(uint *)(param_1 + 0x1a4c);
    puVar2[1] = uVar7;
    if ((PTR_DAT_002131c9[(uint)*(byte *)(param_1 + 0x293f) * 0x24 + 0x1a] & 1) == 0) {
      puVar2[1] = uVar7 & 0xfffff7ff;
    }
    puVar2[2] = 0x12f8;
    puVar2[3] = *(undefined4 *)(param_1 + 0x1bdc);
    puVar2 = puVar2 + 4;
  }
  if ((uVar3 & 0x8000000) != 0) {
    *puVar2 = 0x12f6;
    puVar2[1] = *(undefined4 *)(param_1 + 0x1a50);
    puVar2 = puVar2 + 2;
  }
  puVar5 = puVar2;
  if ((uVar3 & 0x20000) != 0) {
    *puVar2 = 0x13c5;
    puVar2[1] = *(undefined4 *)(param_1 + 0x1ab8);
    puVar5 = puVar2 + 2;
    if (1 < *(int *)(param_1 + 0x23dc)) {
      puVar2[2] = 0x10e6;
      puVar2[3] = *(undefined4 *)(param_1 + 0x1bd4);
      puVar5 = puVar2 + 4;
    }
  }
  if ((uVar3 & 0x800) != 0) {
    *puVar5 = 0x113c0;
    puVar5[1] = *(undefined4 *)(param_1 + 0x1aa0);
    puVar5[2] = *(undefined4 *)(param_1 + 0x1aa4);
    puVar5 = puVar5 + 3;
  }
  if ((uVar3 & 8) != 0) {
    *puVar5 = 0x13c2;
    puVar5[1] = *(undefined4 *)(param_1 + 0x1aa8);
    puVar5 = puVar5 + 2;
  }
  if ((uVar3 & 0x1000) != 0) {
    iVar8 = *(int *)(param_1 + 4);
    puVar1 = *(uint **)(iVar8 + 0x1d8);
    *puVar1 = *puVar1 | (int)puVar5 - (int)puVar1 >> 2;
    *(undefined4 **)(iVar8 + 0x1d8) = puVar5;
    *puVar5 = 0x2f000000;
    puVar5[1] = 0x10e9;
    puVar5[2] = *(undefined4 *)(param_1 + 0x1ae0);
    puVar5[3] = 0x13c7;
    puVar5[4] = *(undefined4 *)(param_1 + 0x1ab0);
    puVar5 = puVar5 + 5;
  }
  if ((uVar3 & 0x20) != 0) {
    *puVar5 = 0x410a9;
    puVar5[1] = *(undefined4 *)(param_1 + 0x1b1c);
    puVar5[2] = *(undefined4 *)(param_1 + 0x1b18);
    puVar5[3] = *(undefined4 *)(param_1 + 0x1b24);
    puVar5[4] = *(undefined4 *)(param_1 + 0x1b20);
    puVar5[5] = *(undefined4 *)(param_1 + 0x1b14);
    puVar5 = puVar5 + 6;
  }
  if ((uVar3 & 0x2000) != 0) {
    *puVar5 = 0x10a2;
    puVar5[1] = *(undefined4 *)(param_1 + 0x1b3c);
    puVar5[2] = 0x1002;
    puVar5[3] = *(undefined4 *)(param_1 + 0x1b50);
    puVar5[4] = 0x1007;
    puVar5[5] = *(undefined4 *)(param_1 + 0x1a64);
    puVar5[6] = 0x825;
    puVar5[7] = *(undefined4 *)(param_1 + 0x1ba0);
    puVar5[8] = 0x1048;
    puVar5[9] = *(undefined4 *)(param_1 + 0x1bc0);
    puVar5 = puVar5 + 10;
  }
  local_34 = (short)uVar3;
  if (local_34 < 0) {
    *puVar5 = 0x1087;
    puVar5[1] = *(undefined4 *)(param_1 + 0x1ccc);
    puVar5[2] = 0x31080;
    puVar5[3] = *(undefined4 *)(param_1 + 0x1cbc);
    puVar5[4] = *(undefined4 *)(param_1 + 0x1cc4);
    puVar5[5] = *(undefined4 *)(param_1 + 0x1cc0);
    puVar5[6] = *(undefined4 *)(param_1 + 0x1cc8);
    puVar5[7] = 0x108c;
    puVar5[8] = *(undefined4 *)(param_1 + 0x1cd0);
    puVar5 = puVar5 + 9;
  }
  if ((uVar3 & 0x4000) != 0) {
    *puVar5 = 0x1108d;
    puVar5[1] = *(undefined4 *)(param_1 + 0x1b40);
    puVar5[2] = *(undefined4 *)(param_1 + 0x1b64);
    puVar5[3] = 0x109a;
    puVar5[4] = *(undefined4 *)(param_1 + 0x1b70);
    puVar5 = puVar5 + 5;
  }
  if ((uVar3 & 0x10) != 0) {
    *puVar5 = 0x1383;
    puVar5[1] = *(undefined4 *)(param_1 + 0x1af4);
    puVar5[2] = 0x109e;
    puVar5[3] = *(undefined4 *)(param_1 + 0x1b2c);
    puVar5 = puVar5 + 4;
  }
  if ((uVar3 & 0x40) != 0) {
    *puVar5 = 0x311a9;
    puVar5[1] = *(undefined4 *)(param_1 + 0x233c);
    puVar5[2] = *(undefined4 *)(param_1 + 0x2340);
    puVar5[3] = *(undefined4 *)(param_1 + 0x2344);
    puVar5[4] = *(undefined4 *)(param_1 + 0x2348);
    puVar5[5] = 0x10b1;
    puVar5[6] = *(undefined4 *)(param_1 + 0x1b34);
    puVar5[7] = 0x10b0;
    puVar5[8] = *(undefined4 *)(param_1 + 0x1b38);
    puVar5 = puVar5 + 9;
  }
  if ((uVar3 & 0x400) != 0) {
    *puVar5 = 0x10ae;
    puVar5[1] = *(undefined4 *)(param_1 + 0x1b30);
    puVar5 = puVar5 + 2;
  }
  if ((uVar3 & 0x80000) != 0) {
    *puVar5 = 0x1008;
    puVar5[1] = *(undefined4 *)(param_1 + 0x1a60);
    puVar5[2] = 0x11004;
    puVar5[3] = *(undefined4 *)(param_1 + 0x1a68);
    puVar5[4] = *(undefined4 *)(param_1 + 0x1a6c);
    puVar5[5] = 0x10fa;
    puVar5[6] = *(undefined4 *)(param_1 + 0x1b60);
    puVar5 = puVar5 + 7;
  }
  if ((uVar3 & 2) != 0) {
    puVar5 = (undefined4 *)((int (*)())FUN_0004c95e)(param_1,puVar5);
  }
  (*(unsigned char *)((unsigned char *)&(local_34) + 0)) = (char)uVar3;
  if ((char)local_34 < '\0') {
    puVar5 = (undefined4 *)((int (*)())FUN_0004c984)(param_1,puVar5);
  }
  puVar2 = puVar5;
  if ((uVar3 & 0x40000) != 0) {
    *puVar5 = 0x10860;
    puVar5[1] = *(undefined4 *)(param_1 + 0x1b78);
    puVar5[2] = *(undefined4 *)(param_1 + 0x1ca0);
    puVar5[3] = 0x82d;
    puVar5[4] = *(undefined4 *)(param_1 + 0x1ca4);
    puVar5[5] = 0x10824;
    puVar5[6] = *(undefined4 *)(param_1 + 0x1b9c);
    puVar5[7] = *(undefined4 *)(param_1 + 0x1ba0);
    puVar5[8] = 0x1047;
    puVar5[9] = *(undefined4 *)(param_1 + 0x1bb0);
    if ((-1 < (int)uVar3) || (puVar2 = puVar5 + 10, *(char *)(param_1 + 0x1868) != '\0')) {
      puVar5[10] = 0x10c0;
      puVar5[0xb] = *(undefined4 *)(param_1 + 0x1f2c);
      puVar5[0xc] = *(uint *)(param_1 + 0x1f28) | 0x70000;
      iVar6 = 1;
      iVar8 = param_1;
      do {
        puVar5[iVar6 + 0xc] = *(undefined4 *)(iVar8 + 0x1ee8);
        iVar6 = iVar6 + 1;
        iVar8 = iVar8 + 4;
      } while (iVar6 != 9);
      puVar2 = puVar5 + 0x15;
    }
  }
  if ((uVar3 & 0x400000) != 0) {
    *puVar2 = 0x887;
    puVar2[1] = *(undefined4 *)(param_1 + 0x1b74);
    puVar2 = puVar2 + 2;
  }
  if ((uVar3 & 0x800000) != 0) {
    *puVar2 = 0x1002;
    puVar2[1] = *(undefined4 *)(param_1 + 0x1b50);
    puVar2[2] = 0x825;
    puVar2[3] = *(undefined4 *)(param_1 + 0x1ba0);
    puVar2[4] = 0x1048;
    puVar2[5] = *(undefined4 *)(param_1 + 0x1bc0);
    puVar2 = puVar2 + 6;
  }
  if ((uVar3 & 0x4000000) != 0) {
    *(undefined4 *)(param_1 + 0x1e68) = 0;
  }
  if ((uVar3 & 0x10000000) != 0) {
    *puVar2 = 0x413de;
    puVar2[1] = *(undefined4 *)(param_1 + 0x2360);
    puVar2[2] = *(undefined4 *)(param_1 + 0x2364);
    puVar2[3] = *(undefined4 *)(param_1 + 0x2368);
    puVar2[4] = *(undefined4 *)(param_1 + 0x236c);
    puVar2[5] = *(undefined4 *)(param_1 + 0x2370);
    puVar2[6] = 0x313e9;
    puVar2[7] = *(undefined4 *)(param_1 + 0x2374);
    puVar2[8] = *(undefined4 *)(param_1 + 0x2378);
    puVar2[9] = *(undefined4 *)(param_1 + 0x237c);
    puVar2[10] = *(undefined4 *)(param_1 + 0x2380);
    puVar2 = puVar2 + 0xb;
  }
  if ((uVar3 & 0x20000000) != 0) {
    *puVar2 = 0x813ad;
    puVar2[1] = *(undefined4 *)(param_1 + 0x2384);
    puVar2[2] = *(undefined4 *)(param_1 + 0x2388);
    puVar2[3] = *(undefined4 *)(param_1 + 0x238c);
    puVar2[4] = *(undefined4 *)(param_1 + 0x2390);
    puVar2[5] = *(undefined4 *)(param_1 + 0x2394);
    puVar2[6] = *(undefined4 *)(param_1 + 0x2398);
    puVar2[7] = *(undefined4 *)(param_1 + 0x239c);
    puVar2[8] = *(undefined4 *)(param_1 + 0x23a0);
    puVar2[9] = *(undefined4 *)(param_1 + 0x23a4);
    puVar2 = puVar2 + 10;
  }
  uVar3 = (-(int)puVar2 & 0x3fU) >> 2;
  if (uVar3 != 0) {
    uVar7 = 0;
    do {
      puVar2[uVar7] = 0x80000000;
      uVar7 = uVar7 + 1;
    } while (uVar3 != uVar7);
  }
  *(undefined4 **)(param_1 + 0x274c) = puVar2 + uVar3;
  (**(code **)(param_1 + 0x275c))(param_1,puVar2 + uVar3);
  uVar3 = *(uint *)(param_1 + 0x1930);
  if ((uVar3 & 0xc0100000) != 0) {
    (**(code **)(param_1 + 0x1330))(param_1,0xc0100000);
    uVar3 = *(uint *)(param_1 + 0x1930);
  }
  if ((uVar3 & 0x200000) != 0) {
    FUN_000823ae(param_1);
    uVar3 = *(uint *)(param_1 + 0x1930);
  }
  if ((uVar3 & 0x1000000) != 0) {
    FUN_000824aa(param_1);
  }
  *(undefined4 *)(param_1 + 0x1930) = 0;
  *(undefined4 *)(param_1 + 0x1934) = 0;
  return;
}

/* FUN_00051bac @ 0x51bac (333 bytes) */
int FUN_00051bac(param_1)
  int param_1;
{
  char cVar1;
  
  if (param_1 != -0x1168) {
    if (*(char *)(param_1 + 0x1868) == '\0') {
      *(undefined **)(param_1 + 0x11a0) = PTR_LAB_002132bd;
      *(undefined **)(param_1 + 0x11a8) = PTR_LAB_002132b1;
      *(undefined **)(param_1 + 0x11a4) = PTR_FUN_002132c1;
      *(undefined **)(param_1 + 0x11ac) = PTR_FUN_002132c5;
      *(undefined **)(param_1 + 0x1190) = PTR_LAB_000795ff_1_002132a1;
      *(undefined **)(param_1 + 0x1194) = PTR_FUN_002132ad;
      *(undefined **)(param_1 + 0x119c) = PTR_LAB_0005d682_4_002132e1;
      *(undefined **)(param_1 + 0x1198) = PTR_FUN_0021329d;
      *(undefined **)(param_1 + 0x11b0) = PTR_LAB_002132d1;
      cVar1 = *(char *)(param_1 + 0x1868);
    }
    else {
      *(undefined **)(param_1 + 0x11a0) = PTR_FUN_002132b5;
      *(undefined **)(param_1 + 0x11a8) = PTR_FUN_002132a9;
      *(undefined **)(param_1 + 0x11a4) = PTR_FUN_002132c9;
      *(undefined **)(param_1 + 0x11ac) = PTR_LAB_00072de8_4_002132cd;
      *(undefined **)(param_1 + 0x1190) = PTR_FUN_00213299;
      *(undefined **)(param_1 + 0x1194) = PTR_LAB_0006db00_4_002132dd;
      *(undefined **)(param_1 + 0x119c) = PTR_LAB_002132d5;
      *(undefined **)(param_1 + 0x1198) = PTR_LAB_0007261e_4_002132b9;
      *(undefined **)(param_1 + 0x11b0) = PTR_LAB_002132d1;
      cVar1 = *(char *)(param_1 + 0x1868);
    }
    if (cVar1 == '\0') {
      *(undefined4 *)(param_1 + 0x134c) = 0;
      *(undefined **)(param_1 + 0x1350) = PTR_FUN_002132d9;
      *(undefined4 *)(param_1 + 0x1354) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x134c) = 0;
      *(undefined **)(param_1 + 0x1350) = PTR_LAB_00072efa_4_002132a5;
      *(undefined4 *)(param_1 + 0x1354) = 0;
    }
    *(undefined1 *)(param_1 + 0x13b0) = 8;
    FUN_0005344c(param_1);
    return 1;
  }
  return 0;
}

/* FUN_00051cf9 @ 0x51cf9 (9 bytes) */
int FUN_00051cf9()
{
  FUN_00053412();
  return;
}

/* FUN_00051d02 @ 0x51d02 (107 bytes) */
int FUN_00051d02(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  *(byte *)(param_1 + 0x45) =
       *(byte *)(param_1 + 0x45) & 0xe7 | (param_3 & 1) * '\b' | (param_3 & 1) << 4;
  *(undefined4 *)(param_1 + 0x274c) = param_2;
  if (*(char *)(param_1 + 0x1868) != '\0') {
    (**(code **)(param_1 + 0x11cc))(param_1);
    *(undefined1 *)(param_1 + 0x2d) = 0;
    return *(undefined4 *)(param_1 + 0x274c);
  }
  FUN_00062d7a(param_1);
  *(undefined1 *)(param_1 + 0x2d) = 0;
  return *(undefined4 *)(param_1 + 0x274c);
}

/* FUN_00051d6d @ 0x51d6d (102 bytes) */
int FUN_00051d6d(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x1168) + 0x1c;
  iVar1 = FUN_0005369a(iVar2,param_2);
  if (iVar1 == 0) {
    iVar2 = *(int *)(param_1 + 0x116c) + 0x14;
    iVar1 = FUN_0005369a(iVar2,param_2);
    if (iVar1 == 0) {
      return -0x3ffcf000;
    }
  }
  iVar1 = *(int *)(*(int *)(iVar2 + 4) + iVar1 * 0x54);
  if (iVar1 == 0) {
    return -0x3ffcf000;
  }
  return iVar1;
}

/* FUN_00051dd3 @ 0x51dd3 (108 bytes) */
int FUN_00051dd3(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x1168) + 0x1c;
  iVar1 = FUN_0005369a(iVar2,param_2);
  if (iVar1 == 0) {
    iVar2 = *(int *)(param_1 + 0x116c) + 0x14;
    iVar1 = FUN_0005369a(iVar2,param_2);
    if (iVar1 == 0) {
      return 0;
    }
  }
  iVar1 = *(int *)(*(int *)(iVar2 + 4) + 4 + iVar1 * 0x54);
  if (iVar1 == 0) {
    iVar1 = 0x81;
  }
  return iVar1;
}

/* FUN_00051e3f @ 0x51e3f (37 bytes) */
int FUN_00051e3f(param_1, param_2)
  int param_1;
  uint param_2;
{
  *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
  *(undefined1 *)(param_1 + 0x29) = 1;
  *(byte *)(param_1 + 0x2d) = *(byte *)(param_1 + 0x2d) | ~-((param_2 & 2) == 0) & 0xcU;
  return;
}

/* FUN_00051e64 @ 0x51e64 (21 bytes) */
int FUN_00051e64(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  return (-(uint)(param_2 == '\0') & 0xfffff782) + 0x882;
}

/* FUN_00051e79 @ 0x51e79 (5 bytes) */
int FUN_00051e79()
{
  return;
}

/* FUN_00051e7e @ 0x51e7e (39 bytes) */
int FUN_00051e7e(param_1)
  int param_1;
{
  if ((*(int *)(param_1 + 0x1168) != 0) && (*(char *)(*(int *)(param_1 + 0x1168) + 0x10) != '\0')) {
    return 1;
  }
  return 0;
}

