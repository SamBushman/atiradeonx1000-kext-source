#include "decls.h"

/* FUN_000839cf @ 0x839cf (169 bytes) */
int FUN_000839cf(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2 + 0x130;
  if (iVar2 == *(int *)(param_1 + 0x1e70)) {
    *(undefined4 *)(param_1 + 0x1e70) = 0;
    FUN_0004a272(param_1,iVar2);
    iVar1 = *(int *)(param_1 + 0x1e64);
  }
  else {
    FUN_0004a272(param_1,iVar2);
    iVar1 = *(int *)(param_1 + 0x1e64);
  }
  if (iVar2 == iVar1) {
    *(undefined4 *)(param_1 + 0x1e64) = 0;
    iVar1 = *(int *)(param_1 + 0x1488);
  }
  else {
    iVar1 = *(int *)(param_1 + 0x1488);
  }
  if (iVar1 == param_2) {
    *(undefined4 *)(param_1 + 0x1488) = 0;
    iVar1 = *(int *)(param_1 + 0x1e5c);
  }
  else {
    iVar1 = *(int *)(param_1 + 0x1e5c);
  }
  if (iVar2 == iVar1) {
    FUN_0004a17c();
    return;
  }
  return;
}

/* FUN_00083a78 @ 0x83a78 (10 bytes) */
int FUN_00083a78()
{
  return 0x38a0;
}

/* FUN_00083a82 @ 0x83a82 (10 bytes) */
int FUN_00083a82()
{
  return 0x38a0;
}

/* FUN_00083a8c @ 0x83a8c (762 bytes) */
int FUN_00083a8c(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  int param_2;
  int param_3;
  undefined4 *param_4;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  int local_38;
  int local_34;
  uint local_28 [5];
  undefined4 local_14;
  
  iVar5 = param_3 + 0x130;
  *(char *)(param_3 + 0x37f8) = (char)param_1[0x8f8];
  *(undefined4 *)(param_3 + 0x37dc) = 0;
  if (param_3 == 0) {
    return 0;
  }
  *(int *)(param_3 + 0x37f4) = param_3;
  iVar4 = param_1[0x8f8];
  *(undefined4 *)(param_3 + 4) = *param_4;
  *(undefined4 *)(param_3 + 8) = param_4[1];
  *(undefined4 *)(param_3 + 0xc) = param_4[2];
  puVar6 = local_28;
  for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  local_28[0] = param_4[2];
  local_28[1] = *param_4;
  local_28[2] = 0;
  local_28[3] = 0;
  local_14 = 2;
  if (param_2 == 0) {
    local_28[3] = 2;
    _memset((void *)(param_3 + 0x3110),0,0x100);
    iVar1 = 0x10;
    iVar3 = iVar5;
    do {
      *(undefined1 *)(iVar3 + 0x2fe0) = 1;
      iVar3 = iVar3 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    *(undefined4 *)(param_3 + 0x120c) = 0;
  }
  else {
    *(undefined4 *)(param_3 + 0x120c) = 0;
    iVar3 = *(int *)(param_2 + 0x74);
    iVar1 = FUN_000aa836(param_1);
    if (iVar1 == 0x801) {
      local_28[3] = local_28[3] | 0xc;
    }
    else if (iVar1 == 0x2601) {
      local_28[3] = local_28[3] | 4;
    }
    else if (iVar1 == 0x800) {
      local_28[3] = local_28[3] | 8;
    }
    if (*(char *)(iVar3 + 5) != '\0') goto LAB_00083ba0;
  }
  if (param_1[0x917] != 0) {
    local_28[4] = 0;
    iVar3 = 0;
    do {
      local_28[4] = local_28[4] * 2 | 1;
      iVar3 = iVar3 + 1;
    } while (param_1[0x917] != iVar3);
    local_28[3] = local_28[3] | 0x400;
  }
LAB_00083ba0:
  if (iVar4 != 0) {
    *(undefined4 *)(param_3 + 0x1840) = param_1[0x9db];
    local_28[3] = local_28[3] | 0x100;
  }
  uVar2 = local_28[3] | 0x80;
  if (*(char *)(param_3 + 0x120) != '\0') {
    uVar2 = local_28[3] | 0x280;
  }
  local_28[3] = uVar2;
  iVar3 = FUN_000b27cd(param_1,param_3 + 0x18b8,param_3 + 0x1794,local_28,iVar5);
  if (iVar3 == 1) {
    return 0xfffffffe;
  }
  if (param_2 != 0) {
    if (iVar4 != 0) {
      local_38 = *(int *)(param_3 + 0x37e8);
      local_34 = *(int *)(param_3 + 0x37ec);
    }
    else {
      local_38 = *(int *)(param_3 + 0x37dc);
      local_34 = *(int *)(param_3 + 0x37e0);
    }
    if (iVar3 == 0) {
      *(undefined1 *)(param_2 + 0x6c) = 1;
    }
    else {
      *(undefined1 *)(param_2 + 0x6c) = 0;
      *param_1 = 1;
    }
    *(undefined4 *)(param_2 + 0x5c) = *(undefined4 *)(param_3 + 0x3884);
    *(int *)(param_2 + 0x54) = local_38;
    *(int *)(param_2 + 0x58) = local_34;
    *(undefined4 *)(param_2 + 100) = 0;
    iVar4 = 8;
    do {
      for (uVar2 = *(uint *)(iVar5 + 0x10bc); uVar2 != 0; uVar2 = uVar2 >> 1) {
        if ((uVar2 & 1) != 0) {
          *(int *)(param_2 + 100) = *(int *)(param_2 + 100) + 1;
        }
      }
      iVar5 = iVar5 + 4;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    *(int *)(param_2 + 0x68) = *(int *)(param_3 + 0x3880) + 1;
    *(undefined4 *)(param_2 + 0x60) = *(undefined4 *)(*(int *)(param_2 + 0x74) + 0x7c);
    *(int *)(param_2 + 0x50) = local_38 + local_34;
    *(undefined1 *)(param_2 + 2) = *(undefined1 *)(param_3 + 0x36e7);
    *(undefined1 *)(param_2 + 1) = *(undefined1 *)(param_3 + 0x36e6);
  }
  if (iVar3 == 0) {
    return 0;
  }
  return 0xffffffff;
}

/* FUN_00083d86 @ 0x83d86 (809 bytes) */
int FUN_00083d86(param_1, param_2)
  int param_1;
  char *param_2;
{
  char *pcVar1;
  undefined4 uVar2;
  char *pcVar3;
  char *local_10;
  
  pcVar3 = param_2 + 0x130;
  if (param_2 != (char *)0x0) {
    if (*(int *)(param_1 + 0x23e0) == 0) {
      if (*(int *)(param_2 + 0x37dc) == 0) {
        ((int (*)())FUN_00083a8c)(param_1,0,*(int *)(param_2 + 0x37f4),*(int *)(param_2 + 0x37f4) + 4);
        *param_2 = '\0';
      }
      local_10 = pcVar3;
      if (0 < *(int *)(param_2 + 0x37dc)) {
        *(char **)(param_1 + 0x1e70) = pcVar3;
        *(char **)(param_1 + 0x1e5c) = pcVar3;
        *(char **)(param_2 + 0x37f4) = param_2;
      }
    }
    else {
      if (*(int *)(param_2 + 0x37e8) == 0) {
        ((int (*)())FUN_00083a8c)(param_1,0,*(int *)(param_2 + 0x37f4),*(int *)(param_2 + 0x37f4) + 4);
        *param_2 = '\0';
      }
      if (0 < *(int *)(param_2 + 0x37e8)) {
        *(char **)(param_1 + 0x1e70) = pcVar3;
        *(char **)(param_1 + 0x1e5c) = pcVar3;
        *(char **)(param_2 + 0x37f4) = param_2;
      }
      local_10 = param_2 + 0x14c;
    }
    pcVar1 = *(char **)(param_1 + 0x1488);
    if ((pcVar1 != (char *)0x0) && (param_2 != pcVar1)) {
      *pcVar1 = '\0';
    }
    if (*param_2 == '\0') {
      *(undefined4 *)(param_1 + 0x1488) = 0;
      if ((*(int *)(param_1 + 0x2768) == 0) || (*(int *)(param_1 + 0x277c) == -1)) {
        uVar2 = 0;
      }
      else {
        uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x2768) + 0xc0 + *(int *)(param_1 + 0x277c) * 4);
      }
      *(undefined4 *)(param_2 + 0x1218) = uVar2;
      *(undefined4 *)(param_2 + 0x165c) = uVar2;
      param_2[0x1430] = '\0';
      param_2[0x1431] = '\0';
      param_2[0x1432] = '\0';
      param_2[0x1433] = '\0';
    }
    if (param_2 == *(char **)(param_1 + 0x1488)) {
      if ((param_2[0x36e7] != '\0') &&
         (((*(byte *)(param_1 + 0x39) & 4) != 0 || ((*(byte *)(param_1 + 0x3c) & 1) != 0)))) {
        FUN_000b3659(param_1,param_2 + 0x18b8,param_2 + 0x1794);
        param_2[0x121f] = '\0';
      }
      if ((param_2[0x3758] != '\0') && ((*(byte *)(param_1 + 0x39) & 1) != 0)) {
        FUN_000b37a0(param_1,param_2 + 0x18b8,param_2 + 0x1794);
        param_2[0x121f] = '\0';
      }
      if ((*(int *)(param_2 + 0x375c) != 0) &&
         (*(short *)(param_1 + 0x34) != 0 || *(short *)(param_1 + 0x32) != 0)) {
        FUN_000b357b(param_1,param_2 + 0x18b8,param_2 + 0x1794);
        param_2[0x121f] = '\0';
      }
    }
    else {
      if (*(char *)(param_1 + 0x1868) == '\0') {
        (**(code **)(param_1 + 0x1334))(param_1,0);
      }
      *(char **)(param_1 + 0x1488) = param_2;
      *param_2 = '\x01';
      local_10[0] = '\0';
      local_10[1] = '\0';
      local_10[2] = '\0';
      local_10[3] = '\0';
      param_2[0x121f] = '\0';
      param_2[0x1434] = '\0';
      param_2[0x1435] = '\0';
      param_2[0x1436] = '\0';
      param_2[0x1437] = '\0';
      if (param_2[0x36e7] != '\0') {
        FUN_000b3659(param_1,param_2 + 0x18b8,param_2 + 0x1794);
      }
      if (param_2[0x3758] != '\0') {
        FUN_000b37a0(param_1,param_2 + 0x18b8,param_2 + 0x1794);
      }
      if (*(int *)(param_2 + 0x375c) != 0) {
        FUN_000b357b(param_1,param_2 + 0x18b8,param_2 + 0x1794);
      }
    }
    (**(code **)(param_1 + 0x294c))(param_1,pcVar3);
    if ((*(uint *)(param_1 + 0x1930) & 0xc0100000) != 0) {
      (**(code **)(param_1 + 0x1330))(param_1,*(uint *)(param_1 + 0x1930));
      *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) & 0x3fefffff;
    }
  }
  return 0;
}

/* FUN_000840b0 @ 0x840b0 (279 bytes) */
int FUN_000840b0(param_1)
  int param_1;
{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int local_20;
  int local_1c;
  int local_14;
  
  local_1c = DAT_001ee940 + -1;
  pbVar1 = *(byte **)(param_1 + 8);
  iVar2 = *(int *)(param_1 + 0xc) - (int)pbVar1;
  local_20 = 0;
  local_14 = 0;
LAB_000840f8:
  do {
    iVar3 = (local_20 + local_1c) / 2;
    if (iVar2 < 1) {
LAB_00084182:
      iVar4 = 0;
    }
    else {
      pcVar5 = (PTR_s_1D_001fb6a0)[iVar3 * 3];
      local_14 = (uint)*pbVar1 - (int)*pcVar5;
      if (local_14 != 0) goto LAB_00084182;
      iVar4 = 0;
      do {
        iVar4 = iVar4 + 1;
        if (iVar2 == iVar4) {
          local_14 = 0;
          goto LAB_00084155;
        }
        local_14 = (uint)pbVar1[iVar4] - (int)pcVar5[iVar4];
      } while (local_14 == 0);
    }
    if (local_14 < 1) {
      if (local_14 == 0) {
        pcVar5 = (PTR_s_1D_001fb6a0)[iVar3 * 3];
LAB_00084155:
        if (pcVar5[iVar4] == '\0') {
          *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(&DAT_001fb6a4 + iVar3 * 0xc);
          *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(&DAT_001fb6a8 + iVar3 * 0xc);
          return;
        }
      }
      local_1c = iVar3 + -1;
      if (local_1c < local_20) goto LAB_00084169;
      goto LAB_000840f8;
    }
    local_20 = iVar3 + 1;
    if (local_1c < local_20) {
LAB_00084169:
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined4 *)(param_1 + 0x18) = 0;
      return;
    }
  } while( true );
}

/* FUN_000841c7 @ 0x841c7 (669 bytes) */
int FUN_000841c7(param_1)
  int param_1;
{
  bool bVar1;
  undefined1 auVar2 [12];
  double dVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  byte bVar7;
  byte *pbVar8;
  double dVar9;
  double dVar10;
  
  dVar9 = DOUBLE_001cf370;
  pbVar6 = *(byte **)(param_1 + 0xc);
  bVar7 = *pbVar6;
  dVar10 = 0.0;
  if ((byte)(bVar7 - 0x30) < 10) {
    dVar10 = 0.0;
    do {
      dVar10 = dVar10 * dVar9 + (double)(int)(bVar7 - 0x30);
      pbVar6 = pbVar6 + 1;
      *(byte **)(param_1 + 0xc) = pbVar6;
      bVar7 = *pbVar6;
    } while ((byte)(bVar7 - 0x30) < 10);
  }
  if ((*pbVar6 == 0x2e) && (pbVar8 = pbVar6 + 1, pbVar6[1] != 0x2e)) {
    *(byte **)(param_1 + 0xc) = pbVar8;
    dVar3 = DOUBLE_001cf378;
    bVar7 = pbVar6[1];
    dVar9 = DOUBLE_001cf378;
    while ((byte)(bVar7 - 0x30) < 10) {
      dVar10 = dVar10 + (double)(int)(bVar7 - 0x30) * dVar9;
      dVar9 = dVar9 * dVar3;
      pbVar8 = pbVar8 + 1;
      *(byte **)(param_1 + 0xc) = pbVar8;
      bVar7 = *pbVar8;
    }
    bVar1 = false;
    pbVar6 = *(byte **)(param_1 + 0xc);
    bVar7 = *pbVar6;
  }
  else {
    bVar1 = true;
    pbVar6 = *(byte **)(param_1 + 0xc);
    bVar7 = *pbVar6;
  }
  if ((bVar7 != 0x45) && (bVar7 != 0x65)) goto LAB_00084243;
  *(byte **)(param_1 + 0xc) = pbVar6 + 1;
  if (pbVar6[1] == 0x2d) {
    *(byte **)(param_1 + 0xc) = pbVar6 + 2;
    bVar1 = true;
  }
  else {
    if (pbVar6[1] == 0x2b) {
      *(byte **)(param_1 + 0xc) = pbVar6 + 2;
    }
    bVar1 = false;
  }
  pbVar6 = *(byte **)(param_1 + 0xc);
  bVar7 = *pbVar6;
  if ((byte)(bVar7 - 0x30) < 10) {
LAB_00084379:
    iVar4 = 0;
    do {
      iVar4 = (bVar7 - 0x30) + iVar4 * 10;
      if (1000 < iVar4) {
        iVar4 = 1000;
      }
      pbVar6 = pbVar6 + 1;
      *(byte **)(param_1 + 0xc) = pbVar6;
      bVar7 = *pbVar6;
    } while ((byte)(bVar7 - 0x30) < 10);
    dVar9 = DOUBLE_001cf330;
    if (0 < iVar4) {
      iVar5 = 0;
      do {
        dVar9 = dVar9 * DOUBLE_001cf370;
        iVar5 = iVar5 + 1;
      } while (iVar4 != iVar5);
      pbVar6 = *(byte **)(param_1 + 0xc);
    }
  }
  else {
    ((int (*)())FUN_000848a2)();
    pbVar6 = *(byte **)(param_1 + 0xc);
    bVar7 = *pbVar6;
    dVar9 = DOUBLE_001cf330;
    if ((byte)(bVar7 - 0x30) < 10) goto LAB_00084379;
  }
  if (bVar1) {
    dVar9 = DOUBLE_001cf330 / dVar9;
  }
  dVar10 = dVar10 * dVar9;
  bVar1 = false;
LAB_00084243:
  bVar7 = *pbVar6;
  if ((((byte)(bVar7 + 0xbf) < 0x1a) || ((byte)(bVar7 + 0x9f) < 0x1a)) || (bVar7 == 0x5f)) {
    ((int (*)())FUN_000848a2)();
  }
  iVar4 = (int)dVar10;
  *(int *)(param_1 + 0x18) = iVar4;
  *(double *)(param_1 + 0x1c) = dVar10;
  if (bVar1) {
    (*(unsigned int *)((unsigned char *)&(auVar2) + 4)) = iVar4;
    (*(unsigned int *)((unsigned char *)&(auVar2) + 0)) = iVar4;
    (*(unsigned int *)((unsigned char *)&(auVar2) + 8)) = _UNK_001c63c4;
    dVar9 = ((double)((ulonglong)_DAT_001c63c0 << 0x20) - _DAT_001c63d0) +
            ((*(unsigned long long *)((unsigned char *)&(auVar2) + 4)) - _UNK_001c63d8);
    if ((dVar10 == dVar9) && (!NAN(dVar10) && !NAN(dVar9))) {
      *(undefined4 *)(param_1 + 0x14) = 0xf;
      return;
    }
  }
  *(undefined4 *)(param_1 + 0x14) = 0x10;
  return;
}

/* FUN_00084464 @ 0x84464 (168 bytes) */
int FUN_00084464(param_1)
  int param_1;
{
  char cVar1;
  bool bVar2;
  bool bVar3;
  undefined1 auVar4 [12];
  bool bVar5;
  double dVar6;
  int iVar7;
  undefined1 *puVar8;
  int iVar9;
  byte *pbVar10;
  byte bVar11;
  undefined1 *puVar12;
  int iVar13;
  byte *pbVar14;
  char *pcVar15;
  double dVar16;
  double dVar17;
  int iStack_20;
  int iStack_1c;
  int local_14;
  
  puVar8 = *(undefined1 **)(param_1 + 0xc);
  if (*(undefined1 **)(param_1 + 0x10) != puVar8) {
    bVar3 = false;
    bVar2 = false;
    bVar5 = false;
    do {
      switch(*puVar8) {
      case 9:
      case 0x20:
        if (bVar2) {
          *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
          bVar3 = false;
          bVar2 = false;
        }
        else {
          if (!bVar3) goto code_r0x00084525;
          *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
          bVar3 = false;
          bVar2 = false;
        }
        break;
      case 10:
        if (bVar3) {
          *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
          bVar3 = true;
          bVar5 = false;
        }
        else {
          bVar3 = true;
          bVar5 = false;
        }
        break;
      default:
        if ((bVar2) || (bVar3)) {
          *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
          bVar3 = false;
        }
        if (!bVar5) goto LAB_00084538;
code_r0x00084525:
        bVar2 = false;
        break;
      case 0xd:
        if ((bVar2) || (bVar3)) {
          *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
          bVar3 = false;
          bVar2 = true;
          bVar5 = false;
        }
        else {
          bVar2 = true;
          bVar5 = false;
        }
        break;
      case 0x23:
        if ((bVar2) || (bVar3)) {
          *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
          bVar3 = false;
          bVar2 = false;
        }
        bVar5 = true;
      }
      puVar8 = puVar8 + 1;
      *(undefined1 **)(param_1 + 0xc) = puVar8;
    } while (*(undefined1 **)(param_1 + 0x10) != puVar8);
  }
LAB_00084538:
  if (*(undefined1 **)(param_1 + 0x10) <= puVar8) {
    *(undefined4 *)(param_1 + 0x14) = 0x1c;
    return;
  }
  *(undefined1 **)(param_1 + 8) = puVar8;
  dVar16 = DOUBLE_001cf370;
  switch(*puVar8) {
  case 0x2b:
    *(undefined4 *)(param_1 + 0x14) = 0x19;
    *(undefined1 **)(param_1 + 0xc) = puVar8 + 1;
    break;
  case 0x2c:
    *(undefined4 *)(param_1 + 0x14) = 0x13;
    *(undefined1 **)(param_1 + 0xc) = puVar8 + 1;
    break;
  case 0x2d:
    *(undefined4 *)(param_1 + 0x14) = 0x1a;
    *(undefined1 **)(param_1 + 0xc) = puVar8 + 1;
    break;
  case 0x2e:
    if (puVar8[1] == '.') {
      *(undefined4 *)(param_1 + 0x14) = 0x12;
      *(undefined1 **)(param_1 + 0xc) = puVar8 + 2;
      return;
    }
    if (9 < (byte)(puVar8[1] - 0x30)) {
      *(undefined4 *)(param_1 + 0x14) = 0x11;
      *(undefined1 **)(param_1 + 0xc) = puVar8 + 1;
      return;
    }
    goto FUN_000841c7;
  default:
    ((int (*)())FUN_000848a2)();
    return;
  case 0x30:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x38:
  case 0x39:
    goto FUN_000841c7;
  case 0x31:
  case 0x32:
  case 0x33:
    if (puVar8[1] == 'D') {
      do {
        do {
          puVar12 = puVar8 + 1;
          *(undefined1 **)(param_1 + 0xc) = puVar12;
          cVar1 = puVar8[1];
          puVar8 = puVar12;
        } while ((byte)(cVar1 + 0xbfU) < 0x1a);
      } while ((((byte)(cVar1 + 0x9fU) < 0x1a) || ((byte)(cVar1 - 0x30U) < 10)) || (cVar1 == '_'));
      goto FUN_000840b0;
    }
FUN_000841c7:
    pbVar10 = *(byte **)(param_1 + 0xc);
    bVar11 = *pbVar10;
    dVar17 = 0.0;
    if ((byte)(bVar11 - 0x30) < 10) {
      dVar17 = 0.0;
      do {
        dVar17 = dVar17 * dVar16 + (double)(int)(bVar11 - 0x30);
        pbVar10 = pbVar10 + 1;
        *(byte **)(param_1 + 0xc) = pbVar10;
        bVar11 = *pbVar10;
      } while ((byte)(bVar11 - 0x30) < 10);
    }
    if ((*pbVar10 == 0x2e) && (pbVar14 = pbVar10 + 1, pbVar10[1] != 0x2e)) {
      *(byte **)(param_1 + 0xc) = pbVar14;
      dVar6 = DOUBLE_001cf378;
      bVar11 = pbVar10[1];
      dVar16 = DOUBLE_001cf378;
      while ((byte)(bVar11 - 0x30) < 10) {
        dVar17 = dVar17 + (double)(int)(bVar11 - 0x30) * dVar16;
        dVar16 = dVar16 * dVar6;
        pbVar14 = pbVar14 + 1;
        *(byte **)(param_1 + 0xc) = pbVar14;
        bVar11 = *pbVar14;
      }
      bVar2 = false;
      pbVar10 = *(byte **)(param_1 + 0xc);
      bVar11 = *pbVar10;
    }
    else {
      bVar2 = true;
      pbVar10 = *(byte **)(param_1 + 0xc);
      bVar11 = *pbVar10;
    }
    if ((bVar11 != 0x45) && (bVar11 != 0x65)) goto LAB_00084243;
    *(byte **)(param_1 + 0xc) = pbVar10 + 1;
    if (pbVar10[1] == 0x2d) {
      *(byte **)(param_1 + 0xc) = pbVar10 + 2;
      bVar2 = true;
    }
    else {
      if (pbVar10[1] == 0x2b) {
        *(byte **)(param_1 + 0xc) = pbVar10 + 2;
      }
      bVar2 = false;
    }
    pbVar10 = *(byte **)(param_1 + 0xc);
    bVar11 = *pbVar10;
    if ((byte)(bVar11 - 0x30) < 10) {
LAB_00084379:
      iVar7 = 0;
      do {
        iVar7 = (bVar11 - 0x30) + iVar7 * 10;
        if (1000 < iVar7) {
          iVar7 = 1000;
        }
        pbVar10 = pbVar10 + 1;
        *(byte **)(param_1 + 0xc) = pbVar10;
        bVar11 = *pbVar10;
      } while ((byte)(bVar11 - 0x30) < 10);
      dVar16 = DOUBLE_001cf330;
      if (0 < iVar7) {
        iVar9 = 0;
        do {
          dVar16 = dVar16 * DOUBLE_001cf370;
          iVar9 = iVar9 + 1;
        } while (iVar7 != iVar9);
        pbVar10 = *(byte **)(param_1 + 0xc);
      }
    }
    else {
      ((int (*)())FUN_000848a2)();
      pbVar10 = *(byte **)(param_1 + 0xc);
      bVar11 = *pbVar10;
      dVar16 = DOUBLE_001cf330;
      if ((byte)(bVar11 - 0x30) < 10) goto LAB_00084379;
    }
    if (bVar2) {
      dVar16 = DOUBLE_001cf330 / dVar16;
    }
    dVar17 = dVar17 * dVar16;
    bVar2 = false;
LAB_00084243:
    bVar11 = *pbVar10;
    if ((((byte)(bVar11 + 0xbf) < 0x1a) || ((byte)(bVar11 + 0x9f) < 0x1a)) || (bVar11 == 0x5f)) {
      ((int (*)())FUN_000848a2)();
    }
    iVar7 = (int)dVar17;
    *(int *)(param_1 + 0x18) = iVar7;
    *(double *)(param_1 + 0x1c) = dVar17;
    if (bVar2) {
      (*(unsigned int *)((unsigned char *)&(auVar4) + 4)) = iVar7;
      (*(unsigned int *)((unsigned char *)&(auVar4) + 0)) = iVar7;
      (*(unsigned int *)((unsigned char *)&(auVar4) + 8)) = _UNK_001c63c4;
      dVar16 = ((double)((ulonglong)_DAT_001c63c0 << 0x20) - _DAT_001c63d0) +
               ((*(unsigned long long *)((unsigned char *)&(auVar4) + 4)) - _UNK_001c63d8);
      if ((dVar17 == dVar16) && (!NAN(dVar17) && !NAN(dVar16))) {
        *(undefined4 *)(param_1 + 0x14) = 0xf;
        return;
      }
    }
    *(undefined4 *)(param_1 + 0x14) = 0x10;
    return;
  case 0x3b:
    *(undefined4 *)(param_1 + 0x14) = 0x14;
    *(undefined1 **)(param_1 + 0xc) = puVar8 + 1;
    break;
  case 0x3d:
    *(undefined4 *)(param_1 + 0x14) = 0x1b;
    *(undefined1 **)(param_1 + 0xc) = puVar8 + 1;
    break;
  case 0x41:
  case 0x42:
  case 0x43:
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x47:
  case 0x48:
  case 0x49:
  case 0x4a:
  case 0x4b:
  case 0x4c:
  case 0x4d:
  case 0x4e:
  case 0x4f:
  case 0x50:
  case 0x51:
  case 0x52:
  case 0x53:
  case 0x54:
  case 0x55:
  case 0x56:
  case 0x57:
  case 0x58:
  case 0x59:
  case 0x5a:
  case 0x5f:
  case 0x61:
  case 0x62:
  case 99:
  case 100:
  case 0x65:
  case 0x66:
  case 0x67:
  case 0x68:
  case 0x69:
  case 0x6a:
  case 0x6b:
  case 0x6c:
  case 0x6d:
  case 0x6e:
  case 0x6f:
  case 0x70:
  case 0x71:
  case 0x72:
  case 0x73:
  case 0x74:
  case 0x75:
  case 0x76:
  case 0x77:
  case 0x78:
  case 0x79:
  case 0x7a:
    do {
      do {
        puVar12 = puVar8 + 1;
        *(undefined1 **)(param_1 + 0xc) = puVar12;
        cVar1 = puVar8[1];
        puVar8 = puVar12;
      } while ((byte)(cVar1 + 0xbfU) < 0x1a);
    } while ((((byte)(cVar1 + 0x9fU) < 0x1a) || ((byte)(cVar1 - 0x30U) < 10)) || (cVar1 == '_'));
FUN_000840b0:
    iStack_1c = DAT_001ee940 + -1;
    pbVar10 = *(byte **)(param_1 + 8);
    iVar7 = *(int *)(param_1 + 0xc) - (int)pbVar10;
    iStack_20 = 0;
    local_14 = 0;
LAB_000840f8:
    do {
      iVar9 = (iStack_20 + iStack_1c) / 2;
      if (iVar7 < 1) {
LAB_00084182:
        iVar13 = 0;
      }
      else {
        pcVar15 = (PTR_s_1D_001fb6a0)[iVar9 * 3];
        local_14 = (uint)*pbVar10 - (int)*pcVar15;
        if (local_14 != 0) goto LAB_00084182;
        iVar13 = 0;
        do {
          iVar13 = iVar13 + 1;
          if (iVar7 == iVar13) {
            local_14 = 0;
            goto LAB_00084155;
          }
          local_14 = (uint)pbVar10[iVar13] - (int)pcVar15[iVar13];
        } while (local_14 == 0);
      }
      if (local_14 < 1) {
        if (local_14 == 0) {
          pcVar15 = (PTR_s_1D_001fb6a0)[iVar9 * 3];
LAB_00084155:
          if (pcVar15[iVar13] == '\0') {
            *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(&DAT_001fb6a4 + iVar9 * 0xc);
            *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(&DAT_001fb6a8 + iVar9 * 0xc);
            return;
          }
        }
        iStack_1c = iVar9 + -1;
        if (iStack_1c < iStack_20) goto LAB_00084169;
        goto LAB_000840f8;
      }
      iStack_20 = iVar9 + 1;
      if (iStack_1c < iStack_20) {
LAB_00084169:
        *(undefined4 *)(param_1 + 0x14) = 0;
        *(undefined4 *)(param_1 + 0x18) = 0;
        return;
      }
    } while( true );
  case 0x5b:
    *(undefined4 *)(param_1 + 0x14) = 0x15;
    *(undefined1 **)(param_1 + 0xc) = puVar8 + 1;
    break;
  case 0x5d:
    *(undefined4 *)(param_1 + 0x14) = 0x16;
    *(undefined1 **)(param_1 + 0xc) = puVar8 + 1;
    break;
  case 0x7b:
    *(undefined4 *)(param_1 + 0x14) = 0x17;
    *(undefined1 **)(param_1 + 0xc) = puVar8 + 1;
    break;
  case 0x7d:
    *(undefined4 *)(param_1 + 0x14) = 0x18;
    *(undefined1 **)(param_1 + 0xc) = puVar8 + 1;
  }
  return;
}

/* FUN_000848a2 @ 0x848a2 (61 bytes) */
int FUN_000848a2(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  if ((int)param_1[10] < 0) {
    param_1[10] = param_1[2] - param_1[1];
    param_1[0xb] = param_1[9];
    param_1[0xc] = param_2;
  }
  param_1[3] = param_1[4];
  ((int (*)())FUN_00084464)();
  *(undefined4 *)*param_1 = 0x502;
  return;
}

/* FUN_000848df @ 0x848df (20 bytes) */
int FUN_000848df()
{
  ((int (*)())FUN_000848a2)();
  return;
}

/* FUN_000848f3 @ 0x848f3 (141 bytes) */
int FUN_000848f3(param_1)
  int *param_1;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)(*param_1 + 0xc))(0x2c);
  if (puVar1 == (undefined4 *)0x0) {
    ((int (*)())FUN_000848df)();
  }
  else {
    puVar1[2] = 0;
    puVar1[1] = 0;
    *puVar1 = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = puVar1 + 6;
    puVar1[6] = 4;
    puVar1[7] = 0;
    puVar1[8] = 0x36;
    puVar1[9] = 0;
    puVar1[10] = 0;
    if (param_1[0x11] == 0) {
      param_1[0x11] = (int)puVar1;
    }
    else {
      *(undefined4 **)param_1[0x12] = puVar1;
    }
    param_1[0x12] = (int)puVar1;
  }
  return puVar1;
}

/* FUN_00084980 @ 0x84980 (247 bytes) */
int FUN_00084980(param_1)
  int param_1;
{
  char *pcVar1;
  char *pcVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  pcVar1 = *(char **)(param_1 + 8);
  pcVar2 = *(char **)(param_1 + 0xc);
  iVar4 = (int)pcVar2 - (int)pcVar1;
  if (*(int *)(param_1 + 0x14) != 0) {
    ((int (*)())FUN_000848a2)();
    return (undefined4 *)0x0;
  }
  puVar3 = *(undefined4 **)(param_1 + 0x3c);
  do {
    while( true ) {
      if (puVar3 == (undefined4 *)0x0) {
        puVar3 = *(undefined4 **)(param_1 + 0x4c);
        do {
          if (puVar3 == (undefined4 *)0x0) {
            return (undefined4 *)0x0;
          }
          if (iVar4 == puVar3[2]) {
            if (iVar4 < 1) {
              if (pcVar2 == pcVar1) {
                return (undefined4 *)puVar3[3];
              }
            }
            else if (*pcVar1 == *(char *)puVar3[1]) {
              iVar5 = 0;
              do {
                iVar5 = iVar5 + 1;
                if (iVar4 == iVar5) {
                  return (undefined4 *)puVar3[3];
                }
              } while (pcVar1[iVar5] == ((char *)puVar3[1])[iVar5]);
            }
          }
          puVar3 = (undefined4 *)*puVar3;
        } while( true );
      }
      if (iVar4 == puVar3[2]) break;
LAB_000849b6:
      puVar3 = (undefined4 *)*puVar3;
    }
    if (0 < iVar4) {
      if (*pcVar1 == *(char *)puVar3[1]) {
        iVar5 = 0;
        do {
          iVar5 = iVar5 + 1;
          if (iVar4 == iVar5) {
            return puVar3;
          }
        } while (pcVar1[iVar5] == ((char *)puVar3[1])[iVar5]);
      }
      goto LAB_000849b6;
    }
    if (pcVar2 == pcVar1) {
      return puVar3;
    }
    puVar3 = (undefined4 *)*puVar3;
  } while( true );
}

/* FUN_00084a77 @ 0x84a77 (20 bytes) */
int FUN_00084a77()
{
  ((int (*)())FUN_000848a2)();
  return;
}

/* FUN_00084a8b @ 0x84a8b (31 bytes) */
int FUN_00084a8b(param_1, param_2)
  int param_1;
  int param_2;
{
  if (*(int *)(param_1 + 0x14) != param_2) {
    ((int (*)())FUN_000848a2)();
    return;
  }
  ((int (*)())FUN_00084464)();
  return;
}

/* FUN_00084aaa @ 0x84aaa (57 bytes) */
int FUN_00084aaa(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  switch(param_2) {
  case 0x61:
  case 0x77:
    return 3;
  case 0x62:
  case 0x7a:
    return 2;
  default:
    ((int (*)())FUN_000848a2)();
code_r0x00084b45:
    return 0;
  case 0x67:
  case 0x79:
    return 1;
  case 0x72:
  case 0x78:
    goto code_r0x00084b45;
  }
}

/* FUN_00084b6e @ 0x84b6e (178 bytes) */
int FUN_00084b6e(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  uint uVar2;
  
  if (*(uint *)(param_2 + 0xc) == 0) {
    *(undefined4 *)(param_2 + 0x18) = 4;
    *(undefined4 *)(param_2 + 0x1c) = 0;
    *(undefined4 *)(param_2 + 0x20) = 0x36;
    *(undefined4 *)(param_2 + 0x24) = 0;
    *(undefined4 *)(param_2 + 0x28) = 0;
    return (undefined4 *)(param_2 + 0x18);
  }
  uVar2 = *(uint *)(param_2 + 0x10);
  if (uVar2 < *(uint *)(param_2 + 0xc)) {
    puVar1 = (undefined4 *)(*(int *)(param_2 + 0x14) + uVar2 * 0x14);
    *(uint *)(param_2 + 0x10) = uVar2 + 1;
    *puVar1 = 4;
    puVar1[1] = 0;
    puVar1[2] = 0x36;
    puVar1[3] = 0;
    puVar1[4] = 0;
    return puVar1;
  }
  ((int (*)())FUN_000848a2)();
  *(undefined4 *)(param_2 + 0x18) = 4;
  *(undefined4 *)(param_2 + 0x1c) = 0;
  *(undefined4 *)(param_2 + 0x20) = 0x36;
  *(undefined4 *)(param_2 + 0x24) = 0;
  *(undefined4 *)(param_2 + 0x28) = 0;
  return (undefined4 *)(param_2 + 0x18);
}

/* FUN_00084c20 @ 0x84c20 (219 bytes) */
int FUN_00084c20(param_1, param_2)
  int *param_1;
  float *param_2;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = param_1[0x9116];
  if (iVar1 == 0) {
    if (*(int *)(*param_1 + 0x11e4) < 1) {
LAB_00084ce4:
      ((int (*)())FUN_000848a2)();
      return 0;
    }
  }
  else {
    iVar2 = 0;
    piVar3 = param_1;
    do {
      if ((*param_2 == (float)piVar3[0x9016]) && (!NAN(*param_2) && !NAN((float)piVar3[0x9016]))) {
        if (((float)piVar3[0x9017] == param_2[1]) &&
           (!NAN((float)piVar3[0x9017]) && !NAN(param_2[1]))) {
          if ((((float)piVar3[0x9018] == param_2[2]) &&
              (!NAN((float)piVar3[0x9018]) && !NAN(param_2[2]))) &&
             ((float)piVar3[0x9019] == param_2[3])) {
            return iVar2;
          }
        }
      }
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 4;
    } while (iVar2 != iVar1);
    if (*(int *)(*param_1 + 0x11e4) <= iVar1) goto LAB_00084ce4;
  }
  param_1[iVar1 * 4 + 0x9016] = (int)*param_2;
  param_1[iVar1 * 4 + 0x9017] = (int)param_2[1];
  param_1[iVar1 * 4 + 0x9018] = (int)param_2[2];
  param_1[iVar1 * 4 + 0x9019] = (int)param_2[3];
  param_1[0x9116] = param_1[0x9116] + 1;
  return iVar1;
}

/* FUN_00084cfb @ 0x84cfb (297 bytes) */
int FUN_00084cfb(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_1[5] == 0) {
    iVar1 = param_1[6];
    if ((((iVar1 == 0xc) || (iVar1 == 0x1d)) || (iVar1 == 0x20)) ||
       ((iVar1 == 0x27 || (iVar1 == 0x2a)))) {
      ((int (*)())FUN_000848a2)();
    }
    else {
      iVar1 = ((int (*)())FUN_00084980)();
      if (iVar1 == 0) {
        puVar2 = (undefined4 *)(**(code **)(*param_1 + 0xc))(0x2c);
        if (puVar2 != (undefined4 *)0x0) {
          puVar2[2] = param_1[3] - param_1[2];
          puVar2[1] = param_1[2];
          *puVar2 = 0;
          puVar2[3] = 0;
          puVar2[4] = 0;
          puVar2[5] = puVar2 + 6;
          puVar2[6] = 4;
          puVar2[7] = 0;
          puVar2[8] = 0x36;
          puVar2[9] = 0;
          puVar2[10] = 0;
          if (param_1[0xf] == 0) {
            param_1[0xf] = (int)puVar2;
            param_1[0x10] = (int)puVar2;
          }
          else {
            *(undefined4 **)param_1[0x10] = puVar2;
            param_1[0x10] = (int)puVar2;
          }
          ((int (*)())FUN_00084464)();
          return puVar2;
        }
        ((int (*)())FUN_000848df)();
      }
      else {
        ((int (*)())FUN_000848a2)();
      }
    }
  }
  else {
    ((int (*)())FUN_00084a77)();
  }
  ((int (*)())FUN_00084464)();
  return (undefined4 *)0x0;
}

/* FUN_00084e24 @ 0x84e24 (280 bytes) */
int FUN_00084e24(param_1, param_2)
  int *param_1;
  undefined4 *param_2;
{
  int local_20;
  
  if ((param_1[5] != 0) || (param_1[6] != 0x20)) {
    ((int (*)())FUN_000848a2)();
  }
  ((int (*)())FUN_00084464)();
  ((int (*)())FUN_00084a8b)();
  if (param_1[5] == 0) {
    param_2[2] = 0x35;
    *param_2 = 3;
    if (param_1[6] == 4) {
      ((int (*)())FUN_00084464)();
      param_2[1] = 0;
      if (*(char *)((int)param_1 + 0x3a) != '\0') {
        if (param_1[5] == 0x15) {
          ((int (*)())FUN_00084464)();
          if (((param_1[5] == 0xf) && (local_20 = param_1[6], -1 < local_20)) &&
             (local_20 < (int)(uint)*(byte *)(*param_1 + 0x13b3))) {
            ((int (*)())FUN_00084464)();
          }
          else {
            ((int (*)())FUN_000848a2)();
            local_20 = 0;
          }
          ((int (*)())FUN_00084a8b)();
        }
        else {
          local_20 = 0;
        }
        param_2[3] = local_20;
        return;
      }
      param_2[3] = 0;
      return;
    }
    if (param_1[6] == 5) {
      ((int (*)())FUN_00084464)();
      param_2[1] = 1;
      return;
    }
  }
  ((int (*)())FUN_000848a2)();
  return;
}

/* FUN_00084f3c @ 0x84f3c (50 bytes) */
int FUN_00084f3c(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 0x14) == 0x19) {
    ((int (*)())FUN_00084464)();
    return 1;
  }
  if (*(int *)(param_1 + 0x14) != 0x1a) {
    return 1;
  }
  ((int (*)())FUN_00084464)();
  return 0xffffffff;
}

/* FUN_00084f6e @ 0x84f6e (113 bytes) */
int FUN_00084f6e(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = ((int (*)())FUN_00084f3c)();
  if (1 < *(int *)(param_1 + 0x14) - 0xfU) {
    ((int (*)())FUN_000848a2)();
    return;
  }
  ((int (*)())FUN_00084464)((double)iVar1,*(undefined8 *)(param_1 + 0x1c));
  return;
}

/* FUN_00084fdf @ 0x84fdf (332 bytes) */
int FUN_00084fdf(param_1)
  int param_1;
{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 in_XMM0_Da;
  float fVar4;
  undefined4 in_XMM0_Db;
  float fVar5;
  float fVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  puVar1 = (undefined4 *)((int (*)())FUN_00084b6e)();
  puVar1[2] = 0x34;
  *puVar1 = 2;
  if (0x1a < *(uint *)(param_1 + 0x14)) {
LAB_00085055:
    ((int (*)())FUN_000848a2)();
    return;
  }
  uVar2 = 1 << ((byte)*(undefined4 *)(param_1 + 0x14) & 0x1f);
  if ((uVar2 & 0x6018000) != 0) {
    ((int (*)())FUN_00084f6e)();
    fVar4 = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
    uVar3 = ((int (*)())FUN_00084c20)(fVar4,fVar4,fVar4,fVar4);
    puVar1[3] = uVar3;
    return;
  }
  if ((uVar2 & 0x800000) == 0) goto LAB_00085055;
  ((int (*)())FUN_00084464)();
  uVar3 = 0;
  uVar7 = 0;
  uVar8 = 0x3f800000;
  ((int (*)())FUN_00084f6e)();
  fVar4 = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
  if (*(int *)(param_1 + 0x14) == 0x13) {
    fVar5 = fVar4;
    ((int (*)())FUN_00084464)(fVar4,uVar3,uVar7,uVar8);
    ((int (*)())FUN_00084f6e)();
    fVar4 = (float)(double)CONCAT44(in_XMM0_Db,fVar4);
    if (*(int *)(param_1 + 0x14) == 0x13) {
      fVar6 = fVar4;
      ((int (*)())FUN_00084464)(fVar5,fVar4,uVar7,uVar8);
      ((int (*)())FUN_00084f6e)();
      if (*(int *)(param_1 + 0x14) == 0x13) {
        ((int (*)())FUN_00084464)(fVar5,fVar6,(float)(double)CONCAT44(in_XMM0_Db,fVar4));
        ((int (*)())FUN_00084f6e)();
        goto LAB_0008509d;
      }
    }
  }
  if ((*(int *)(param_1 + 0x28) < 0) && (*(int *)(param_1 + 0x2c) == -1)) {
    *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x24);
    *(char **)(param_1 + 0x30) =
         "warning: <paramConstVector> rule match where parser is supplying some default component(s)"
    ;
  }
LAB_0008509d:
  ((int (*)())FUN_00084a8b)();
  uVar3 = ((int (*)())FUN_00084c20)();
  puVar1[3] = uVar3;
  return;
}

/* FUN_0008512b @ 0x8512b (71 bytes) */
int FUN_0008512b(param_1)
  int *param_1;
{
  int iVar1;
  
  if (((param_1[5] == 0xf) && (iVar1 = param_1[6], -1 < iVar1)) &&
     (iVar1 < *(int *)(*param_1 + 0x11fc))) {
    ((int (*)())FUN_00084464)();
    return iVar1;
  }
  ((int (*)())FUN_000848a2)();
  return 0;
}

/* FUN_00085172 @ 0x85172 (71 bytes) */
int FUN_00085172(param_1)
  int *param_1;
{
  int iVar1;
  
  if (((param_1[5] == 0xf) && (iVar1 = param_1[6], -1 < iVar1)) &&
     (iVar1 < *(int *)(*param_1 + 0x1200))) {
    ((int (*)())FUN_00084464)();
    return iVar1;
  }
  ((int (*)())FUN_000848a2)();
  return 0;
}

/* FUN_000851b9 @ 0x851b9 (114 bytes) */
int FUN_000851b9(param_1)
  int *param_1;
{
  int iVar1;
  
  if (param_1[5] == 0x15) {
    ((int (*)())FUN_00084464)();
    if (((param_1[5] != 0xf) || (iVar1 = param_1[6], iVar1 < 0)) ||
       ((int)(uint)*(byte *)(*param_1 + 0x13b0) <= iVar1)) {
      ((int (*)())FUN_000848a2)();
      iVar1 = param_1[6];
    }
    ((int (*)())FUN_00084464)();
    ((int (*)())FUN_00084a8b)();
    return iVar1;
  }
  return 0;
}

/* FUN_0008522b @ 0x8522b (60 bytes) */
int FUN_0008522b(param_1)
  int param_1;
{
  uint uVar1;
  
  if (((*(int *)(param_1 + 0x14) == 0xf) && (uVar1 = *(uint *)(param_1 + 0x18), -1 < (int)uVar1)) &&
     (uVar1 < 4)) {
    ((int (*)())FUN_00084464)();
    return uVar1;
  }
  ((int (*)())FUN_000848a2)();
  return 0;
}

/* FUN_00085267 @ 0x85267 (74 bytes) */
int FUN_00085267(param_1)
  int *param_1;
{
  int iVar1;
  
  if (((param_1[5] == 0xf) && (iVar1 = param_1[6], -1 < iVar1)) &&
     (iVar1 < (int)(uint)*(byte *)(*param_1 + 0x13b5))) {
    ((int (*)())FUN_00084464)();
    return iVar1;
  }
  ((int (*)())FUN_000848a2)();
  return 0;
}

/* FUN_000852b1 @ 0x852b1 (132 bytes) */
int FUN_000852b1(param_1, param_2, param_3)
  int *param_1;
  undefined4 param_2;
  int param_3;
{
  byte *pbVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  int iVar5;
  int iVar6;
  bool bVar7;
  int iStackY_20;
  
  ((int (*)())FUN_00084464)();
  ((int (*)())FUN_00084a8b)();
  if (param_1[5] != 0) {
    ((int (*)())FUN_000848a2)();
  }
  puVar2 = (undefined4 *)((int (*)())FUN_00084b6e)();
  *puVar2 = 2;
  switch(param_1[6]) {
  case 5:
    if (param_1[5] != 0) {
code_r0x00084a77:
      ((int (*)())FUN_000848a2)();
      return;
    }
    ((int (*)())FUN_00084464)();
    ((int (*)())FUN_00084a8b)();
    if ((param_1[5] == 0) && (param_1[6] == 0x1f)) {
      ((int (*)())FUN_00084464)();
      puVar2[2] = 0x18;
      return;
    }
    break;
  default:
    break;
  case 10:
    if (param_1[5] != 0) goto code_r0x00084a77;
    ((int (*)())FUN_00084464)();
    ((int (*)())FUN_00084a8b)();
    if (param_1[5] == 0) {
      if (param_1[6] == 4) {
        ((int (*)())FUN_00084464)();
        puVar2[2] = 0x16;
        return;
      }
      if (param_1[6] == 0x1a) {
        ((int (*)())FUN_00084464)();
        puVar2[2] = 0x17;
        return;
      }
    }
    break;
  case 0x11:
    if (param_1[5] != 0) goto code_r0x00084a77;
    ((int (*)())FUN_00084464)();
    ((int (*)())FUN_00084a8b)();
    uVar3 = ((int (*)())FUN_00085267)();
    puVar2[3] = uVar3;
    ((int (*)())FUN_00084a8b)();
    ((int (*)())FUN_00084a8b)();
    if (param_1[5] == 0) {
      switch(param_1[6]) {
      default:
        goto code_r0x000859eb;
      case 1:
        puVar2[2] = 10;
        break;
      case 2:
        puVar2[2] = 0xe;
        break;
      case 6:
        puVar2[2] = 0xb;
        break;
      case 0xe:
        puVar2[2] = 0x10;
        break;
      case 0x1b:
        puVar2[2] = 0xd;
        break;
      case 0x25:
        puVar2[2] = 0xc;
        break;
      case 0x26:
        ((int (*)())FUN_00084464)();
        ((int (*)())FUN_00084a8b)();
        if ((param_1[5] != 0) || (param_1[6] != 7)) goto code_r0x000853aa;
        puVar2[2] = 0xf;
      }
code_r0x00084464:
      pbVar1 = (byte *)param_1[3];
      if (((byte *)param_1[4] != pbVar1) && (*pbVar1 - 9 < 0x1b)) {
                    
                    
        (*(code *)(*(int *)(((unsigned char *)0x000844a4) + (*pbVar1 - 9) * 4) + 0x84472))();
        return;
      }
      if ((byte *)param_1[4] <= pbVar1) {
        param_1[5] = 0x1c;
        return;
      }
      param_1[2] = (int)pbVar1;
      if (0x52 < *pbVar1 - 0x2b) {
        ((int (*)())FUN_000848a2)();
        return;
      }
                    
                    
      (*(code *)(*(int *)(((unsigned char *)0x0008460c) + (*pbVar1 - 0x2b) * 4) + 0x84472))
                (unaff_EBX,unaff_ESI,unaff_EDI,unaff_EBP);
      return;
    }
code_r0x000859eb:
    break;
  case 0x12:
    if (param_1[5] != 0) {
      ((int (*)())FUN_00084a77)();
    }
    ((int (*)())FUN_00084464)();
    ((int (*)())FUN_00084a8b)();
    if (param_1[5] != 0) break;
    puVar2[3] = 0;
    iVar5 = param_1[6];
    if (iVar5 == 3) {
      puVar2[3] = 1;
code_r0x00085acd:
      ((int (*)())FUN_00084464)();
      ((int (*)())FUN_00084a8b)();
    }
    else {
      if (iVar5 == 0xd) goto code_r0x00085acd;
      if (iVar5 == 1) {
        puVar2[2] = 0x11;
        goto code_r0x00084464;
      }
    }
    if ((param_1[5] == 0) && (param_1[6] == 0x22)) {
      puVar2[2] = 0x12;
      goto code_r0x00084464;
    }
    break;
  case 0x13:
    if (param_1[5] != 0) goto code_r0x00084a77;
    ((int (*)())FUN_00084464)();
    ((int (*)())FUN_00084a8b)();
    uVar3 = ((int (*)())FUN_00085267)();
    puVar2[3] = uVar3;
    ((int (*)())FUN_00084a8b)();
    ((int (*)())FUN_00084a8b)();
    puVar2[4] = 0;
    if (param_1[5] != 0) break;
    if (param_1[6] == 3) {
      puVar2[4] = 1;
code_r0x00085b11:
      ((int (*)())FUN_00084464)();
      ((int (*)())FUN_00084a8b)();
    }
    else if (param_1[6] == 0xd) goto code_r0x00085b11;
    if (param_1[5] == 0) {
      iVar5 = param_1[6];
      if (iVar5 == 6) {
        puVar2[2] = 0x14;
      }
      else if (iVar5 == 0x25) {
        puVar2[2] = 0x15;
      }
      else {
        if (iVar5 != 1) break;
        puVar2[2] = 0x13;
      }
      goto code_r0x00084464;
    }
    break;
  case 0x15:
    if (param_1[5] != 0) goto code_r0x00084a77;
    ((int (*)())FUN_00084464)();
    ((int (*)())FUN_00084a8b)();
    puVar2[3] = 0;
    if (param_1[5] == 0) {
      if (param_1[6] == 3) {
        puVar2[3] = 1;
code_r0x00085aef:
        ((int (*)())FUN_00084464)();
        ((int (*)())FUN_00084a8b)();
      }
      else if (param_1[6] == 0xd) goto code_r0x00085aef;
      if (param_1[5] == 0) {
        switch(param_1[6]) {
        default:
          goto code_r0x000859f6;
        case 1:
          puVar2[2] = 5;
          break;
        case 6:
          puVar2[2] = 6;
          break;
        case 8:
          puVar2[2] = 8;
          break;
        case 0x24:
          puVar2[2] = 9;
          break;
        case 0x25:
          puVar2[2] = 7;
        }
        goto code_r0x00084464;
      }
    }
code_r0x000859f6:
    break;
  case 0x16:
    if (param_1[5] != 0) goto code_r0x00084a77;
    ((int (*)())FUN_00084464)();
    ((int (*)())FUN_00084a8b)();
    if (param_1[5] != 0) {
      ((int (*)())FUN_000848a2)();
    }
    switch(param_1[6]) {
    case 0x17:
      ((int (*)())FUN_00084464)();
      puVar2[2] = 0x1a;
      if (param_1[5] == 0x15) {
        ((int (*)())FUN_00084464)();
        if (((param_1[5] == 0xf) && (iVar5 = param_1[6], -1 < iVar5)) &&
           (iVar5 < (int)(uint)*(byte *)(*param_1 + 0x13b4))) {
          ((int (*)())FUN_00084464)();
        }
        else {
          ((int (*)())FUN_000848a2)();
          iVar5 = 0;
        }
        ((int (*)())FUN_00084a8b)();
      }
      else {
        iVar5 = 0;
      }
      puVar2[3] = iVar5;
      break;
    case 0x18:
      ((int (*)())FUN_00084464)();
      puVar2[2] = 0x22;
      break;
    case 0x19:
      ((int (*)())FUN_00084464)();
      puVar2[2] = 0x2a;
      ((int (*)())FUN_00084a8b)();
      ((int (*)())FUN_000848a2)();
      puVar2[3] = 0;
      ((int (*)())FUN_00084a8b)();
      break;
    default:
      ((int (*)())FUN_000848a2)();
      break;
    case 0x1d:
      ((int (*)())FUN_00084464)();
      puVar2[2] = 0x2e;
      ((int (*)())FUN_00084a8b)();
      if (((param_1[5] == 0xf) && (iVar5 = param_1[6], -1 < iVar5)) &&
         (iVar5 < *(int *)(*param_1 + 0x149c))) {
        ((int (*)())FUN_00084464)();
      }
      else {
        ((int (*)())FUN_000848a2)();
        iVar5 = 0;
      }
      puVar2[3] = iVar5;
      ((int (*)())FUN_00084a8b)();
      break;
    case 0x1e:
      ((int (*)())FUN_00084464)();
      puVar2[2] = 0x1e;
      break;
    case 0x2a:
      ((int (*)())FUN_00084464)();
      puVar2[2] = 0x26;
      uVar3 = ((int (*)())FUN_000851b9)();
      puVar2[3] = uVar3;
    }
    if (param_1[5] == 0x11) {
      ((int (*)())FUN_00084464)();
      if (param_1[5] != 0) break;
      iVar5 = param_1[6];
      if (iVar5 == 0x10) {
        ((int (*)())FUN_00084464)();
        bVar7 = param_1[5] == 0x11;
        if (bVar7) {
          ((int (*)())FUN_00084464)();
        }
        puVar2[4] = 3;
code_r0x00085cb0:
        if (!bVar7) goto code_r0x00085862;
      }
      else {
        if (iVar5 == 0x2b) {
          ((int (*)())FUN_00084464)();
          bVar7 = param_1[5] == 0x11;
          if (bVar7) {
            ((int (*)())FUN_00084464)();
          }
          puVar2[4] = 2;
          goto code_r0x00085cb0;
        }
        if (iVar5 == 0xf) {
          ((int (*)())FUN_00084464)();
          bVar7 = param_1[5] == 0x11;
          if (bVar7) {
            ((int (*)())FUN_00084464)();
          }
          puVar2[4] = 1;
          goto code_r0x00085cb0;
        }
        puVar2[4] = 0;
      }
      if ((param_1[5] == 0) && (param_1[6] == 0x21)) {
        ((int (*)())FUN_00084464)();
        ((int (*)())FUN_00084a8b)();
        iVar5 = ((int (*)())FUN_0008522b)();
        iStackY_20 = iVar5;
        if ((param_3 != '\0') && (param_1[5] == 0x12)) {
          ((int (*)())FUN_00084464)();
          iStackY_20 = ((int (*)())FUN_0008522b)();
          if (iStackY_20 < iVar5) break;
        }
        ((int (*)())FUN_00084a8b)();
        iVar6 = iVar5 + 1;
        goto code_r0x0008587a;
      }
    }
    else {
code_r0x00085862:
      if (param_3 != '\0') {
        iStackY_20 = 3;
        iVar5 = 0;
        iVar6 = 1;
code_r0x0008587a:
        puVar2[2] = puVar2[2] + iVar5;
        for (; iVar6 <= iStackY_20; iVar6 = iVar6 + 1) {
          puVar4 = (undefined4 *)((int (*)())FUN_00084b6e)();
          *puVar4 = *puVar2;
          puVar4[1] = puVar2[1];
          iVar5 = puVar2[2];
          puVar4[2] = iVar5;
          puVar4[3] = puVar2[3];
          puVar4[4] = puVar2[4];
          puVar4[2] = iVar5 + 1;
          puVar2 = puVar4;
        }
        return;
      }
    }
    break;
  case 0x29:
    if (param_1[5] != 0) goto code_r0x00084a77;
    ((int (*)())FUN_00084464)();
    if (param_1[5] == 0x15) {
      ((int (*)())FUN_00084464)();
      if (((param_1[5] != 0xf) || (iVar5 = param_1[6], iVar5 < 0)) ||
         ((int)(uint)*(byte *)(*param_1 + 0x13b2) <= iVar5)) {
        ((int (*)())FUN_000848a2)();
        iVar5 = param_1[6];
      }
      ((int (*)())FUN_00084464)();
      ((int (*)())FUN_00084a8b)();
    }
    else {
      iVar5 = 0;
    }
    puVar2[3] = iVar5;
    ((int (*)())FUN_00084a8b)();
    if ((param_1[5] == 0) && (param_1[6] == 4)) {
      puVar2[2] = 0x19;
      goto code_r0x00084464;
    }
  }
code_r0x000853aa:
  ((int (*)())FUN_000848a2)();
  return;
}

/* FUN_00085de7 @ 0x85de7 (499 bytes) */
int FUN_00085de7(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int local_28;
  int local_20;
  
  if (0x1a < *(uint *)(param_1 + 0x14)) goto LAB_00085e3f;
  uVar1 = 1 << ((byte)*(undefined4 *)(param_1 + 0x14) & 0x1f);
  if ((uVar1 & 0x818000) != 0) {
LAB_00085e17:
    ((int (*)())FUN_00084fdf)();
    return;
  }
  if ((uVar1 & 1) == 0) {
    if (((uVar1 & 0x6000000) != 0) && (param_4 != '\0')) goto LAB_00085e17;
  }
  else if (*(int *)(param_1 + 0x18) == 0x1d) {
    ((int (*)())FUN_00084464)(param_2);
    ((int (*)())FUN_00084a8b)();
    puVar2 = (undefined4 *)((int (*)())FUN_00084b6e)();
    *puVar2 = 2;
    if (*(int *)(param_1 + 0x14) == 0) {
      if (*(int *)(param_1 + 0x18) == 9) {
        puVar2[2] = 0x32;
        ((int (*)())FUN_00084464)(param_2);
        ((int (*)())FUN_00084a8b)();
        local_28 = ((int (*)())FUN_00085172)();
        local_20 = local_28;
        if ((param_3 != '\0') && (*(int *)(param_1 + 0x14) == 0x12)) {
          ((int (*)())FUN_00084464)();
          local_20 = ((int (*)())FUN_00085172)();
          if (local_20 < local_28) goto LAB_00085e3f;
        }
      }
      else {
        if (*(int *)(param_1 + 0x18) != 0x14) goto LAB_00085e3f;
        puVar2[2] = 0x33;
        ((int (*)())FUN_00084464)(param_2);
        ((int (*)())FUN_00084a8b)();
        local_28 = ((int (*)())FUN_0008512b)();
        local_20 = local_28;
        if ((param_3 != '\0') && (*(int *)(param_1 + 0x14) == 0x12)) {
          ((int (*)())FUN_00084464)();
          local_20 = ((int (*)())FUN_0008512b)();
          if (local_20 < local_28) goto LAB_00085e3f;
        }
      }
      ((int (*)())FUN_00084a8b)();
      puVar2[3] = local_28;
      while (local_28 = local_28 + 1, local_28 <= local_20) {
        puVar3 = (undefined4 *)((int (*)())FUN_00084b6e)();
        *puVar3 = *puVar2;
        puVar3[1] = puVar2[1];
        puVar3[2] = puVar2[2];
        puVar3[3] = puVar2[3];
        puVar3[4] = puVar2[4];
        puVar3[3] = local_28;
        puVar2 = puVar3;
      }
      return;
    }
  }
  else if (*(int *)(param_1 + 0x18) == 0x27) {
    ((int (*)())FUN_000852b1)();
    return;
  }
LAB_00085e3f:
  ((int (*)())FUN_000848a2)();
  return;
}

/* FUN_00085fda @ 0x85fda (307 bytes) */
int FUN_00085fda(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  undefined4 uVar2;
  
  if ((*(int *)(param_1 + 0x14) == 0) && (*(int *)(param_1 + 0x18) == 0xc)) {
    *(undefined4 *)(param_2 + 0x18) = 1;
    ((int (*)())FUN_00084464)();
    ((int (*)())FUN_00084a8b)();
    if (*(int *)(param_1 + 0x14) != 0) {
      ((int (*)())FUN_000848a2)();
    }
    uVar1 = *(uint *)(param_1 + 0x18);
    if (uVar1 == 0xb) {
      ((int (*)())FUN_00084464)();
      *(undefined4 *)(param_2 + 0x20) = 3;
      return;
    }
    if (uVar1 < 0xc) {
      if (uVar1 == 4) {
        ((int (*)())FUN_00084464)();
        *(undefined4 *)(param_2 + 0x20) = 1;
        if (*(int *)(param_1 + 0x14) == 0x11) {
          ((int (*)())FUN_00084464)();
          if (*(int *)(param_1 + 0x14) == 0) {
            if (*(int *)(param_1 + 0x18) != 0x1c) {
              if (*(int *)(param_1 + 0x18) == 0x23) {
                ((int (*)())FUN_00084464)();
                uVar2 = 1;
                goto LAB_00086057;
              }
              *(int *)(param_1 + 0xc) = *(int *)(param_1 + 8) + -1;
            }
            ((int (*)())FUN_00084464)();
            uVar2 = 0;
          }
          else {
            ((int (*)())FUN_000848a2)();
            uVar2 = 0;
          }
        }
        else {
          uVar2 = 0;
        }
LAB_00086057:
        *(undefined4 *)(param_2 + 0x24) = uVar2;
        return;
      }
    }
    else {
      if (uVar1 == 0x1b) {
        ((int (*)())FUN_00084464)();
        *(undefined4 *)(param_2 + 0x20) = 4;
        return;
      }
      if (uVar1 == 0x28) {
        ((int (*)())FUN_00084464)();
        *(undefined4 *)(param_2 + 0x20) = 2;
        uVar2 = ((int (*)())FUN_000851b9)();
        goto LAB_00086057;
      }
    }
  }
  ((int (*)())FUN_000848a2)();
  return;
}

/* FUN_0008610d @ 0x8610d (90 bytes) */
int FUN_0008610d(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 0x14) == 0) && (*(int *)(param_1 + 0xc) + -1 == *(int *)(param_1 + 8))) {
    uVar1 = ((int (*)())FUN_00084aaa)();
    ((int (*)())FUN_00084464)();
    return uVar1;
  }
  ((int (*)())FUN_000848a2)();
  return 0;
}

/* FUN_00086167 @ 0x86167 (260 bytes) */
int FUN_00086167(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  uint uVar1;
  int iVar2;
  
  *param_2 = param_3;
  uVar1 = *(uint *)(param_1 + 0x14);
  if (uVar1 < 0x11) {
    if (uVar1 < 0xf) {
      if (uVar1 == 0) {
        if ((*(int *)(param_1 + 0x18) == 0x1d) || (*(int *)(param_1 + 0x18) == 0x27)) {
          ((int (*)())FUN_00085de7)(0);
          param_2[6] = 0;
          return;
        }
        if (*(int *)(param_3 + 0xc) == 0) {
          ((int (*)())FUN_00084464)();
          param_2[6] = 0;
          return;
        }
        ((int (*)())FUN_00084464)();
        ((int (*)())FUN_00084a8b)();
        if ((*(int *)(param_1 + 0x14) == 0xf) &&
           (iVar2 = *(int *)(param_1 + 0x18), param_2[6] = iVar2, iVar2 <= *(int *)(param_3 + 0xc)))
        {
          ((int (*)())FUN_00084464)();
          ((int (*)())FUN_00084a8b)();
          return;
        }
        ((int (*)())FUN_000848a2)();
        return;
      }
LAB_000861b4:
      ((int (*)())FUN_00084a77)();
      return;
    }
  }
  else if (uVar1 != 0x17) goto LAB_000861b4;
  ((int (*)())FUN_00085de7)(0);
  param_2[6] = 0;
  return;
}

/* FUN_0008626b @ 0x8626b (72 bytes) */
int FUN_0008626b(param_1, param_2, param_3)
  int param_1;
  undefined4 *param_2;
  undefined4 param_3;
{
  *param_2 = param_3;
  if (*(int *)(param_1 + 0x14) != 0) {
    ((int (*)())FUN_00084a77)();
    return;
  }
  if (*(int *)(param_1 + 0x18) != 0xc) {
    ((int (*)())FUN_00084464)();
    param_2[6] = 0;
    return;
  }
  ((int (*)())FUN_00085fda)();
  param_2[6] = 0;
  return;
}

/* FUN_000862b3 @ 0x862b3 (234 bytes) */
int FUN_000862b3(param_1, param_2)
  int param_1;
  int *param_2;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = *(uint *)(param_1 + 0x14);
  if (uVar1 < 0x11) {
    if (uVar1 < 0xf) {
      if (uVar1 != 0) goto LAB_000862fa;
      iVar3 = *(int *)(param_1 + 0x18);
      if ((iVar3 != 0x1d) && (iVar3 != 0x27)) {
        if (iVar3 == 0xc) {
          iVar3 = ((int (*)())FUN_000848f3)();
          if (iVar3 == 0) {
            return;
          }
LAB_0008635e:
          ((int (*)())FUN_0008626b)();
          return;
        }
        iVar3 = ((int (*)())FUN_00084980)();
        if (iVar3 == 0) {
LAB_000862fa:
          ((int (*)())FUN_000848a2)();
          return;
        }
        iVar2 = *(int *)(iVar3 + 0x18);
        if (iVar2 == 1) goto LAB_0008635e;
        if (iVar2 == 0) {
          *param_2 = iVar3;
          param_2[6] = 0;
          ((int (*)())FUN_00084464)();
          return;
        }
        if (iVar2 != 2) {
          if (iVar2 != 3) {
            ((int (*)())FUN_00084a77)();
            return;
          }
          goto LAB_000862fa;
        }
        goto LAB_000862dd;
      }
    }
  }
  else if (uVar1 != 0x17) goto LAB_000862fa;
  iVar3 = ((int (*)())FUN_000848f3)();
  if (iVar3 == 0) {
    return;
  }
LAB_000862dd:
  ((int (*)())FUN_00086167)();
  return;
}

/* FUN_0008639d @ 0x8639d (330 bytes) */
int FUN_0008639d(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int local_20;
  
  iVar3 = ((int (*)())FUN_00084f3c)();
  if (*(int *)(param_1 + 0x14) == 0) {
    bVar2 = **(char **)(param_1 + 8) + 0x9f;
    if (bVar2 < 0x1a) {
      uVar4 = 1 << (bVar2 & 0x1f);
      if ((uVar4 & 0x20043) == 0) {
        if ((uVar4 & 0x3c00000) == 0) goto LAB_000863ff;
        local_20 = 0;
        goto LAB_00086406;
      }
      local_20 = 1;
      uVar5 = ((int (*)())FUN_0008610d)();
      iVar1 = *param_2;
    }
    else {
LAB_000863ff:
      local_20 = -1;
LAB_00086406:
      uVar5 = ((int (*)())FUN_0008610d)();
      iVar1 = *param_2;
    }
    if (iVar1 == -1) {
      *param_2 = local_20;
    }
    if (local_20 == *param_2) goto LAB_000863d7;
  }
  else if (*(int *)(param_1 + 0x14) == 0xf) {
    if (*(int *)(param_1 + 0x18) == 0) {
      ((int (*)())FUN_00084464)();
      uVar5 = 4;
      goto LAB_000863d7;
    }
    if (*(int *)(param_1 + 0x18) == 1) {
      ((int (*)())FUN_00084464)();
      uVar5 = 5;
      goto LAB_000863d7;
    }
  }
  ((int (*)())FUN_000848a2)();
  uVar5 = 0;
LAB_000863d7:
  if (iVar3 == -1) {
    switch(uVar5) {
    case 0:
      uVar5 = 6;
      break;
    case 1:
      uVar5 = 7;
      break;
    case 2:
      uVar5 = 8;
      break;
    case 3:
      uVar5 = 9;
      break;
    case 4:
      uVar5 = 4;
      break;
    case 5:
      uVar5 = 10;
      break;
    default:
      ((int (*)())FUN_00084a77)();
    }
  }
  return uVar5;
}

/* FUN_00086501 @ 0x86501 (382 bytes) */
int FUN_00086501(param_1, param_2)
  int param_1;
  int *param_2;
{
  char cVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  uint local_24;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    if (*(int *)(param_1 + 0x18) == 0x20) {
      iVar4 = ((int (*)())FUN_000848f3)();
      if (iVar4 != 0) {
        ((int (*)())FUN_00084e24)();
      }
      goto LAB_00086592;
    }
    iVar4 = ((int (*)())FUN_00084980)();
    if (iVar4 == 0) {
      ((int (*)())FUN_000848a2)();
      goto LAB_00086592;
    }
    uVar6 = *(uint *)(iVar4 + 0x18);
    if (uVar6 < 3) {
      if (uVar6 == 0) goto LAB_000865e2;
      ((int (*)())FUN_000848a2)();
      iVar4 = 0;
      goto LAB_00086592;
    }
    if (uVar6 == 3) {
LAB_000865e2:
      ((int (*)())FUN_00084464)();
      goto LAB_00086592;
    }
    ((int (*)())FUN_00084a77)();
    *param_2 = 0;
    iVar4 = *(int *)(param_1 + 0x14);
  }
  else {
    ((int (*)())FUN_000848a2)();
    iVar4 = 0;
LAB_00086592:
    *param_2 = iVar4;
    iVar4 = *(int *)(param_1 + 0x14);
  }
  if (iVar4 == 0x11) {
    ((int (*)())FUN_00084464)();
    if (*(int *)(param_1 + 0x14) == 0) {
      uVar6 = *(uint *)(param_1 + 8);
      if ((int)(*(uint *)(param_1 + 0xc) - uVar6) < 5) {
        if (uVar6 < *(uint *)(param_1 + 0xc)) {
          cVar2 = '\x02';
          local_24 = 0;
          do {
            bVar3 = ((int (*)())FUN_00084aaa)();
            uVar5 = 1 << (bVar3 & 0x1f);
            cVar1 = 3 < (byte)(**(char **)(param_1 + 8) + 0x89U);
            if ((cVar2 == '\x02') || (bVar7 = cVar2 == cVar1, cVar1 = cVar2, bVar7)) {
              cVar2 = cVar1;
              if (local_24 < uVar5) {
                local_24 = local_24 | uVar5;
              }
              else {
                ((int (*)())FUN_000848a2)();
              }
            }
            else {
              ((int (*)())FUN_000848a2)();
            }
            uVar6 = uVar6 + 1;
          } while (uVar6 < *(uint *)(param_1 + 0xc));
        }
        else {
          local_24 = 0;
        }
        ((int (*)())FUN_00084464)();
        goto LAB_000865a4;
      }
    }
    ((int (*)())FUN_000848a2)();
  }
  local_24 = 0xf;
LAB_000865a4:
  param_2[1] = local_24;
  return;
}

/* FUN_0008667f @ 0x8667f (395 bytes) */
int FUN_0008667f(param_1, param_2)
  int param_1;
  int param_2;
{
  char cVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = ((int (*)())FUN_00084f3c)();
  *(bool *)(param_2 + 0x14) = iVar3 == -1;
  ((int (*)())FUN_000862b3)();
  if (*(int *)(param_1 + 0x14) != 0x11) {
    *(undefined4 *)(param_2 + 4) = 0;
    *(undefined4 *)(param_2 + 8) = 1;
    *(undefined4 *)(param_2 + 0xc) = 2;
    *(undefined4 *)(param_2 + 0x10) = 3;
    return;
  }
  ((int (*)())FUN_00084464)();
  if ((*(int *)(param_1 + 0x14) != 0) ||
     ((iVar3 = *(int *)(param_1 + 0xc) - *(int *)(param_1 + 8), iVar3 != 1 && (iVar3 != 4)))) {
    ((int (*)())FUN_000848a2)();
    return;
  }
  uVar4 = ((int (*)())FUN_00084aaa)();
  *(undefined4 *)(param_2 + 4) = uVar4;
  if (*(int *)(param_1 + 0xc) - *(int *)(param_1 + 8) < 2) {
    *(undefined4 *)(param_2 + 8) = uVar4;
    *(undefined4 *)(param_2 + 0xc) = uVar4;
    *(undefined4 *)(param_2 + 0x10) = uVar4;
  }
  else {
    uVar4 = ((int (*)())FUN_00084aaa)();
    *(undefined4 *)(param_2 + 8) = uVar4;
    uVar4 = ((int (*)())FUN_00084aaa)();
    *(undefined4 *)(param_2 + 0xc) = uVar4;
    uVar4 = ((int (*)())FUN_00084aaa)();
    *(undefined4 *)(param_2 + 0x10) = uVar4;
    pcVar2 = *(char **)(param_1 + 8);
    if ((byte)(*pcVar2 + 0x89U) < 4) {
      cVar1 = pcVar2[1];
      if (((((cVar1 != 'r') && (cVar1 != 'g')) && (cVar1 != 'b')) &&
          (((cVar1 != 'a' && (cVar1 = pcVar2[2], cVar1 != 'r')) &&
           (((cVar1 != 'g' && ((cVar1 != 'b' && (cVar1 != 'a')))) &&
            (cVar1 = pcVar2[3], cVar1 != 'r')))))) &&
         (((cVar1 != 'g' && (cVar1 != 'b')) && (cVar1 != 'a')))) goto LAB_000867ae;
    }
    else if (((((3 < (byte)(pcVar2[1] + 0x89U)) && (cVar1 = pcVar2[2], cVar1 != 'x')) &&
              (cVar1 != 'y')) &&
             (((cVar1 != 'z' && (cVar1 != 'w')) &&
              ((cVar1 = pcVar2[3], cVar1 != 'x' && ((cVar1 != 'y' && (cVar1 != 'z')))))))) &&
            (cVar1 != 'w')) goto LAB_000867ae;
    ((int (*)())FUN_000848a2)();
  }
LAB_000867ae:
  ((int (*)())FUN_00084464)();
  return;
}

/* FUN_0008680a @ 0x8680a (65 bytes) */
int FUN_0008680a(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = ((int (*)())FUN_00084f3c)();
  *(bool *)(param_2 + 0x14) = iVar1 == -1;
  ((int (*)())FUN_000862b3)();
  ((int (*)())FUN_00084a8b)();
  uVar2 = ((int (*)())FUN_0008610d)();
  *(undefined4 *)(param_2 + 4) = uVar2;
  *(undefined4 *)(param_2 + 8) = uVar2;
  *(undefined4 *)(param_2 + 0xc) = uVar2;
  *(undefined4 *)(param_2 + 0x10) = uVar2;
  return;
}

/* FUN_0008684b @ 0x8684b (1665 bytes) */
int FUN_0008684b(param_1)
  int *param_1;
{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  char *pcVar7;
  int iVar8;
  int local_38;
  
  pcVar2 = (char *)param_1[3];
  cVar1 = *pcVar2;
  pcVar7 = pcVar2 + 1;
  param_1[3] = (int)pcVar7;
  if (cVar1 == '!') {
    cVar1 = pcVar2[1];
    pcVar7 = pcVar2 + 2;
    param_1[3] = (int)pcVar7;
    if (cVar1 == '!') {
      cVar1 = pcVar2[2];
      pcVar7 = pcVar2 + 3;
      param_1[3] = (int)pcVar7;
      if (cVar1 == 'A') {
        cVar1 = pcVar2[3];
        pcVar7 = pcVar2 + 4;
        param_1[3] = (int)pcVar7;
        if (cVar1 == 'R') {
          cVar1 = pcVar2[4];
          pcVar7 = pcVar2 + 5;
          param_1[3] = (int)pcVar7;
          if (cVar1 == 'B') {
            cVar1 = pcVar2[5];
            pcVar7 = pcVar2 + 6;
            param_1[3] = (int)pcVar7;
            if (cVar1 == 'f') {
              cVar1 = pcVar2[6];
              pcVar7 = pcVar2 + 7;
              param_1[3] = (int)pcVar7;
              if (cVar1 == 'p') {
                cVar1 = pcVar2[7];
                pcVar7 = pcVar2 + 8;
                param_1[3] = (int)pcVar7;
                if (cVar1 == '1') {
                  cVar1 = pcVar2[8];
                  pcVar7 = pcVar2 + 9;
                  param_1[3] = (int)pcVar7;
                  if (cVar1 == '.') {
                    cVar1 = pcVar2[9];
                    pcVar7 = pcVar2 + 10;
                    param_1[3] = (int)pcVar7;
                    if (cVar1 == '0') {
                      ((int (*)())FUN_00084464)();
                      iVar5 = param_1[5];
                      while (iVar5 == 8) {
                        ((int (*)())FUN_00084464)();
                        if (param_1[5] == 1) {
                          *(undefined1 *)(param_1[6] + 0x34 + (int)param_1) = 1;
                          ((int (*)())FUN_00084464)();
                        }
                        else {
                          ((int (*)())FUN_000848a2)();
                        }
                        ((int (*)())FUN_00084a8b)();
                        iVar5 = param_1[5];
                      }
LAB_0008691d:
                      do {
                        while( true ) {
                          uVar3 = param_1[5];
                          if ((uVar3 == 6) || (uVar3 == 0x1c)) {
                            ((int (*)())FUN_00084a8b)();
                            ((int (*)())FUN_00084a8b)();
                            return (uint)param_1[10] >> 0x1f;
                          }
                          if (uVar3 < 0xe) break;
LAB_00086950:
                          ((int (*)())FUN_000848a2)();
LAB_0008695d:
                          ((int (*)())FUN_00084a8b)();
                        }
                        uVar4 = 1 << ((byte)uVar3 & 0x1f);
                        if ((uVar4 & 0x3618) == 0) {
                          if ((uVar4 & 0x24) != 0) {
                            if ((uVar3 != 2) && (uVar3 != 5)) {
                              ((int (*)())FUN_00084a77)();
                            }
                            if (param_1[5] == 2) {
                              ((int (*)())FUN_00084464)();
                              iVar5 = ((int (*)())FUN_00084980)();
                              if (iVar5 != 0) {
                                ((int (*)())FUN_000848a2)();
                              }
                              piVar6 = (int *)(**(code **)(*param_1 + 0xc))(0x10);
                              if (piVar6 == (int *)0x0) {
                                ((int (*)())FUN_000848df)();
                              }
                              piVar6[2] = param_1[3] - param_1[2];
                              piVar6[1] = param_1[2];
                              *piVar6 = param_1[0x13];
                              piVar6[3] = 0;
                              param_1[0x13] = (int)piVar6;
                              ((int (*)())FUN_00084464)();
                              ((int (*)())FUN_00084a8b)();
                              iVar5 = ((int (*)())FUN_00084980)();
                              if (iVar5 == 0) {
                                ((int (*)())FUN_000848a2)();
                              }
                              else {
                                piVar6[3] = iVar5;
                                ((int (*)())FUN_00084464)();
                              }
                            }
                            else {
                              iVar5 = param_1[6];
                              if (iVar5 == 1) {
                                ((int (*)())FUN_00084464)();
                                iVar5 = ((int (*)())FUN_00084cfb)();
                                if (iVar5 != 0) {
                                  ((int (*)())FUN_00084a8b)();
                                  ((int (*)())FUN_00085fda)();
                                }
                              }
                              else if (iVar5 == 0) {
                                do {
                                  ((int (*)())FUN_00084464)();
                                  if ((param_1[5] == 0x1c) || (iVar5 = ((int (*)())FUN_00084cfb)(), iVar5 == 0))
                                  break;
                                  *(undefined4 *)(iVar5 + 0x18) = 0;
                                  *(undefined4 *)(iVar5 + 0x20) = 0;
                                } while (param_1[5] == 0x13);
                              }
                              else if (iVar5 == 2) {
                                ((int (*)())FUN_00084464)();
                                iVar5 = ((int (*)())FUN_00084cfb)();
                                if (iVar5 != 0) {
                                  *(undefined4 *)(iVar5 + 0x18) = 2;
                                  if (param_1[5] == 0x15) {
                                    ((int (*)())FUN_00084464)();
                                    if (param_1[5] == 0xf) {
                                      iVar8 = param_1[6];
                                      if ((iVar8 == 0) || (*(int *)(*param_1 + 0x11e4) < iVar8)) {
                                        ((int (*)())FUN_000848a2)();
                                        iVar8 = 1;
                                      }
                                      else {
                                        ((int (*)())FUN_00084464)();
                                      }
                                    }
                                    else {
                                      iVar8 = *(int *)(*param_1 + 0x11e4) + 1;
                                    }
                                    *(int *)(iVar5 + 0xc) = iVar8;
                                    iVar8 = (**(code **)(*param_1 + 0xc))(iVar8 * 0x14);
                                    *(int *)(iVar5 + 0x14) = iVar8;
                                    *(undefined4 *)(iVar5 + 0x10) = 0;
                                    if (iVar8 == 0) {
                                      ((int (*)())FUN_000848df)();
                                    }
                                    else {
                                      ((int (*)())FUN_00084a8b)();
                                      ((int (*)())FUN_00084a8b)();
                                      ((int (*)())FUN_00084a8b)();
                                      iVar8 = param_1[5];
                                      while ((iVar8 != 0x1c && (((int (*)())FUN_00085de7)(1), param_1[5] == 0x13)
                                             )) {
                                        ((int (*)())FUN_00084464)();
                                        iVar8 = param_1[5];
                                      }
                                      if (*(int *)(*param_1 + 0x11e4) < *(int *)(iVar5 + 0xc)) {
                                        *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar5 + 0x10)
                                        ;
                                      }
                                      else if (*(int *)(iVar5 + 0xc) != *(int *)(iVar5 + 0x10)) {
                                        ((int (*)())FUN_000848a2)();
                                      }
                                      ((int (*)())FUN_00084a8b)();
                                    }
                                  }
                                  else {
                                    *(undefined4 *)(iVar5 + 0xc) = 0;
                                    ((int (*)())FUN_00084a8b)();
                                    ((int (*)())FUN_00085de7)(1);
                                  }
                                }
                              }
                              else if (iVar5 == 3) {
                                ((int (*)())FUN_00084464)();
                                iVar5 = ((int (*)())FUN_00084cfb)();
                                if (iVar5 != 0) {
                                  ((int (*)())FUN_00084a8b)();
                                  ((int (*)())FUN_00084e24)();
                                }
                              }
                              else {
                                ((int (*)())FUN_00084a77)();
                              }
                            }
                            goto LAB_0008695d;
                          }
                          if ((uVar4 & 0x880) == 0) goto LAB_00086950;
                          if (param_1[0x9015] < *(int *)(*param_1 + 0x1208)) {
                            piVar6 = param_1 + (param_1[0x9015] + param_1[0x9014]) * 0x18 + 0x14;
                            if (uVar3 == 7) {
                              *piVar6 = param_1[6];
                              ((int (*)())FUN_00084464)();
                              piVar6[1] = 0;
                              ((int (*)())FUN_0008667f)();
LAB_00086ae0:
                              piVar6[10] = 0;
                              piVar6[0x11] = 0;
                            }
                            else {
                              if (uVar3 == 0xb) {
                                *piVar6 = param_1[6];
                                ((int (*)())FUN_00084464)();
                                ((int (*)())FUN_00086501)();
                                ((int (*)())FUN_00084a8b)();
                                ((int (*)())FUN_0008667f)();
                                ((int (*)())FUN_00084a8b)();
                                if ((param_1[5] != 0) || (param_1[6] != 0x2a)) {
                                  ((int (*)())FUN_000848a2)();
                                }
                                ((int (*)())FUN_00084464)();
                                if (param_1[5] == 0x15) {
                                  ((int (*)())FUN_00084464)();
                                  if (((param_1[5] != 0xf) || (local_38 = param_1[6], local_38 < 0))
                                     || ((int)(uint)*(byte *)(*param_1 + 0x13b1) <= local_38)) {
                                    ((int (*)())FUN_000848a2)();
                                    local_38 = param_1[6];
                                  }
                                  ((int (*)())FUN_00084464)();
                                  ((int (*)())FUN_00084a8b)();
                                }
                                else {
                                  local_38 = 0;
                                }
                                piVar6[0x10] = local_38;
                                ((int (*)())FUN_00084a8b)();
                                if (param_1[5] != 0xe) {
                                  ((int (*)())FUN_000848a2)();
                                }
                                ((int (*)())FUN_00084464)();
                                iVar5 = param_1[6];
                                piVar6[0x17] = iVar5;
                                if ((*(char *)((int)param_1 + 0x39) == '\0') && (iVar5 - 6U < 3)) {
                                  ((int (*)())FUN_000848a2)();
                                }
                                goto LAB_00086ae0;
                              }
                              ((int (*)())FUN_00084a77)();
                            }
                            param_1[0x9015] = param_1[0x9015] + 1;
                            goto LAB_0008695d;
                          }
                          ((int (*)())FUN_000848a2)();
                          goto LAB_0008691d;
                        }
                        if (param_1[0x9014] < *(int *)(*param_1 + 0x1204)) {
                          piVar6 = param_1 + (param_1[0x9014] + param_1[0x9015]) * 0x18 + 0x14;
                          switch(uVar3) {
                          case 3:
                            *piVar6 = param_1[6];
                            ((int (*)())FUN_00084464)();
                            ((int (*)())FUN_00086501)();
                            ((int (*)())FUN_00084a8b)();
                            ((int (*)())FUN_0008667f)();
                            ((int (*)())FUN_00084a8b)();
                            ((int (*)())FUN_0008667f)();
                            piVar6[0x11] = 0;
                            break;
                          case 4:
                            *piVar6 = param_1[6];
                            ((int (*)())FUN_00084464)();
                            ((int (*)())FUN_00086501)();
                            ((int (*)())FUN_00084a8b)();
                            ((int (*)())FUN_0008680a)();
                            ((int (*)())FUN_00084a8b)();
                            ((int (*)())FUN_0008680a)();
                            piVar6[0x11] = 0;
                            break;
                          default:
                            ((int (*)())FUN_00084a77)();
                            break;
                          case 9:
                            *piVar6 = param_1[6];
                            ((int (*)())FUN_00084464)();
                            ((int (*)())FUN_00086501)();
                            ((int (*)())FUN_00084a8b)();
                            ((int (*)())FUN_0008680a)();
                            piVar6[10] = 0;
                            piVar6[0x11] = 0;
                            break;
                          case 10:
                            *piVar6 = param_1[6];
                            ((int (*)())FUN_00084464)();
                            ((int (*)())FUN_00086501)();
                            ((int (*)())FUN_00084a8b)();
                            ((int (*)())FUN_000862b3)();
                            ((int (*)())FUN_00084a8b)();
                            iVar5 = ((int (*)())FUN_0008639d)();
                            piVar6[4] = iVar5;
                            ((int (*)())FUN_00084a8b)();
                            iVar5 = ((int (*)())FUN_0008639d)();
                            piVar6[5] = iVar5;
                            ((int (*)())FUN_00084a8b)();
                            iVar5 = ((int (*)())FUN_0008639d)();
                            piVar6[6] = iVar5;
                            ((int (*)())FUN_00084a8b)();
                            iVar5 = ((int (*)())FUN_0008639d)();
                            piVar6[7] = iVar5;
                            *(undefined1 *)(piVar6 + 8) = 0;
                            piVar6[10] = 0;
                            piVar6[0x11] = 0;
                            break;
                          case 0xc:
                            *piVar6 = param_1[6];
                            ((int (*)())FUN_00084464)();
                            ((int (*)())FUN_00086501)();
                            ((int (*)())FUN_00084a8b)();
                            ((int (*)())FUN_0008667f)();
                            ((int (*)())FUN_00084a8b)();
                            ((int (*)())FUN_0008667f)();
                            ((int (*)())FUN_00084a8b)();
                            ((int (*)())FUN_0008667f)();
                            break;
                          case 0xd:
                            *piVar6 = param_1[6];
                            ((int (*)())FUN_00084464)();
                            ((int (*)())FUN_00086501)();
                            ((int (*)())FUN_00084a8b)();
                            ((int (*)())FUN_0008667f)();
                            piVar6[10] = 0;
                            piVar6[0x11] = 0;
                          }
                          param_1[0x9014] = param_1[0x9014] + 1;
                          goto LAB_0008695d;
                        }
                        ((int (*)())FUN_000848a2)();
                      } while( true );
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  param_1[2] = (int)(pcVar7 + -1);
  ((int (*)())FUN_000848a2)();
  return 0;
}

/* FUN_00087179 @ 0x87179 (164 bytes) */
int FUN_00087179(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int param_2;
  uint *param_3;
  uint param_4;
  undefined4 param_5;
  undefined4 *param_6;
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *param_3;
  if (0 < (int)uVar2) {
    uVar3 = 0;
    iVar1 = param_2;
    do {
      if (((*(int *)(iVar1 + 8) == param_6[2]) && (*(int *)(iVar1 + 0xc) == param_6[3])) &&
         (*(int *)(iVar1 + 0x10) == param_6[4])) {
        if (-1 < (int)uVar3) {
          param_6[1] = uVar3;
          return uVar3;
        }
        break;
      }
      uVar3 = uVar3 + 1;
      iVar1 = iVar1 + 0x14;
    } while (uVar2 != uVar3);
  }
  if (uVar2 < param_4) {
    param_6[1] = uVar2;
    iVar1 = uVar2 * 0x14;
    *(undefined4 *)(iVar1 + param_2) = *param_6;
    *(undefined4 *)(iVar1 + 4 + param_2) = param_6[1];
    *(undefined4 *)(iVar1 + 8 + param_2) = param_6[2];
    *(undefined4 *)(iVar1 + 0xc + param_2) = param_6[3];
    *(undefined4 *)(iVar1 + 0x10 + param_2) = param_6[4];
    *param_3 = *param_3 + 1;
  }
  else {
    ((int (*)())FUN_000848a2)(param_3,param_2,param_1);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* FUN_0008721d @ 0x8721d (4073 bytes) */
int FUN_0008721d(param_1, param_2, param_3, param_4)
  int param_1;
  undefined1 *param_2;
  size_t param_3;
  void *param_4;
{
  uint *puVar1;
  void *pvVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  bool bVar5;
  char cVar6;
  int *piVar7;
  void *pvVar8;
  int *piVar9;
  char *pcVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  byte bVar14;
  int iVar15;
  uint uVar16;
  undefined1 *puVar17;
  int iVar18;
  uint *puVar19;
  uint uVar20;
  uint uVar21;
  uint *puVar22;
  uint *puVar23;
  byte bVar24;
  bool bVar25;
  uint local_dc;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_a8;
  uint local_a4;
  uint local_a0;
  uint local_9c;
  uint local_98;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  uint local_5c [19];
  
  piVar7 = (int *)(**(code **)(param_1 + 0xc))(0x24a30);
  param_2[0x54] = 0;
  if (*(int *)(param_2 + 0x60) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x60));
    *(undefined4 *)(param_2 + 0x60) = 0;
  }
  *(undefined4 *)(param_2 + 100) = 0;
  *(undefined4 *)(param_2 + 0x78) = 0;
  *(undefined4 *)(param_2 + 0x7c) = 0;
  *(undefined4 *)(param_2 + 0x80) = 0;
  *(undefined4 *)(param_2 + 0x84) = 0;
  *(undefined4 *)(param_2 + 0x8c) = 0;
  *(undefined4 *)(param_2 + 0x90) = 0;
  *(undefined4 *)(param_2 + 0x88) = 0;
  *(undefined4 *)(param_2 + 0x74) = 0;
  *(undefined4 *)(param_2 + 0x6c) = 0;
  *(undefined4 *)(param_2 + 0x70) = 0;
  *(undefined4 *)(param_2 + 0x68) = 0;
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  *(undefined4 *)(param_2 + 0xc) = 0;
  *(undefined4 *)(param_2 + 0x10) = 0;
  if (*(char *)(param_1 + 0x13b1) != '\0') {
    iVar15 = 0;
    puVar17 = param_2;
    do {
      *(undefined4 *)(puVar17 + 0x14) = 0;
      iVar15 = iVar15 + 1;
      puVar17 = puVar17 + 4;
    } while (iVar15 < (int)(uint)*(byte *)(param_1 + 0x13b1));
  }
  if (0 < *(int *)(param_1 + 0x11d4)) {
    iVar15 = 0;
    do {
      *(undefined1 *)(*(int *)(param_2 + 0x94) + iVar15) = 0;
      iVar15 = iVar15 + 1;
    } while (iVar15 < *(int *)(param_1 + 0x11d4));
  }
  pvVar8 = (void *)(**(code **)(param_1 + 0xc))(param_3 + 1);
  if (pvVar8 == (void *)0x0) {
    _free(piVar7);
    return;
  }
  _memcpy(pvVar8,param_4,param_3);
  *(undefined1 *)((int)pvVar8 + param_3) = 0;
  *piVar7 = param_1;
  piVar7[1] = (int)pvVar8;
  piVar7[2] = (int)pvVar8;
  piVar7[3] = (int)pvVar8;
  piVar7[4] = (int)((int)pvVar8 + param_3);
  piVar7[9] = 1;
  piVar7[10] = -1;
  piVar7[0xb] = -1;
  piVar7[0xc] = (int)"";
  iVar15 = 0;
  piVar9 = piVar7;
  do {
    *(undefined1 *)(piVar9 + 0xd) = 0;
    iVar15 = iVar15 + 1;
    piVar9 = (int *)((int)piVar9 + 1);
  } while (iVar15 != 7);
  piVar7[0xf] = 0;
  piVar7[0x10] = 0;
  piVar7[0x11] = 0;
  piVar7[0x12] = 0;
  piVar7[0x13] = 0;
  piVar7[0x9014] = 0;
  piVar7[0x9015] = 0;
  piVar7[0x9116] = 0;
  piVar7[0x9149] = 0;
  piVar7[0x928a] = 0;
  piVar7[0x928b] = 0;
  cVar6 = ((int (*)())FUN_0008684b)();
  if (cVar6 != '\0') {
    iVar15 = *piVar7;
    bVar24 = (char)piVar7[0xd] == '\x01';
    if (*(char *)((int)piVar7 + 0x35) == '\x01') {
      bVar24 = bVar24 + 1;
    }
    if (*(char *)((int)piVar7 + 0x36) == '\x01') {
      bVar24 = bVar24 + 1;
    }
    bVar25 = bVar24 == 1;
    if (bVar24 < 2) {
      bVar24 = *(char *)((int)piVar7 + 0x37) == '\x01';
      if ((char)piVar7[0xe] == '\x01') {
        bVar24 = bVar24 + 1;
      }
      if (bVar24 < 2) {
LAB_0008763a:
        puVar4 = (undefined4 *)piVar7[0xf];
        local_b0 = 0;
joined_r0x0008764c:
        for (; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {
          iVar12 = puVar4[6];
          if (iVar12 == 1) {
            iVar12 = ((int (*)())FUN_00087179)(*(int *)(iVar15 + 0x11ec) - (uint)bVar25,
                                  "too many fragment attributes",puVar4 + 6);
            if (iVar12 < 0) goto LAB_00087466;
          }
          else if (iVar12 == 0) {
            if ((int)(*(int *)(iVar15 + 0x11dc) - (uint)bVar25) <= piVar7[0x928b]) {
              ((int (*)())FUN_000848a2)();
              goto LAB_00087466;
            }
            puVar4[7] = piVar7[0x928b];
            piVar7[0x928b] = piVar7[0x928b] + 1;
          }
          else {
            if (iVar12 != 2) {
              if (iVar12 == 3) goto LAB_000876db;
              ((int (*)())FUN_00084a77)();
              goto LAB_00087466;
            }
            local_b4 = puVar4[3];
            if (local_b4 == 0) {
              local_b4 = 1;
            }
            else if (local_b4 < 1) goto LAB_000876db;
            local_bc = 0;
            iVar12 = 0;
            do {
              iVar11 = ((int (*)())FUN_00087179)(*(int *)(iVar15 + 0x11e4) -
                                    ((int)((uint)bVar25 << 0x1f) >> 0x1f & 2U),
                                    "too many program parameters",iVar12 + puVar4[5]);
              if (iVar11 < 0) goto LAB_00087466;
              local_bc = local_bc + 1;
              iVar12 = iVar12 + 0x14;
            } while (local_b4 != local_bc);
          }
LAB_000876db: ;
        }
        local_b0 = local_b0 + 1;
        if (local_b0 < 2) {
          if (local_b0 != 0) {
            puVar4 = (undefined4 *)piVar7[0x11];
            goto joined_r0x0008764c;
          }
          goto LAB_0008763a;
        }
        iVar12 = piVar7[0x9014];
        iVar18 = piVar7[0x9015] + iVar12;
        iVar11 = *(int *)(iVar15 + 0x11d4);
        if (iVar11 < iVar18) {
LAB_000878eb:
          ((int (*)())FUN_000848a2)();
          goto LAB_00087466;
        }
        if (bVar25) {
          if ((char)piVar7[0xd] == '\x01') {
            if (*(int *)(iVar15 + 0x1204) + -3 < iVar12) {
              ((int (*)())FUN_000848a2)();
              goto LAB_00087466;
            }
            if (iVar11 + -3 < iVar18) goto LAB_000878eb;
          }
          if (*(char *)((int)piVar7 + 0x35) == '\x01') {
            if (iVar12 <= *(int *)(iVar15 + 0x1204) + -4) {
              if (iVar11 + -4 < iVar18) goto LAB_000878eb;
              goto LAB_00087743;
            }
LAB_00087f4d:
            ((int (*)())FUN_000848a2)();
            goto LAB_00087466;
          }
LAB_00087743:
          if (*(char *)((int)piVar7 + 0x36) == '\x01') {
            if (*(int *)(iVar15 + 0x1204) + -2 < iVar12) goto LAB_00087f4d;
            if (iVar11 + -2 < iVar18) goto LAB_000878eb;
          }
        }
        bVar24 = *(byte *)(iVar15 + 0x13b1);
        if (bVar24 != 0) {
          uVar16 = 0;
          do {
            local_5c[uVar16] = 0;
            uVar16 = uVar16 + 1;
          } while (bVar24 != uVar16);
        }
        if (iVar18 < 1) {
          bVar5 = false;
          local_a8 = 1;
LAB_00087791:
          if (*(int *)(iVar15 + 0x120c) < local_a8) {
            ((int (*)())FUN_000848a2)();
          }
          else {
            iVar12 = (**(code **)(iVar15 + 0xc))
                               (iVar18 * 0x70 + (piVar7[0x9149] + piVar7[0x928a]) * 0x14 + 0x70 +
                                piVar7[0x9116] * 0x10);
            *(int *)(param_2 + 0x60) = iVar12;
            if (iVar12 != 0) {
              if (bVar5) {
                param_2[3] = 1;
              }
              if (*(char *)((int)piVar7 + 0x3a) == '\x01') {
                param_2[5] = 1;
              }
              if (bVar25) {
                param_2[1] = 1;
                if ((char)piVar7[0xd] == '\x01') {
                  *(undefined4 *)(param_2 + 8) = 0x800;
                }
                else if (*(char *)((int)piVar7 + 0x35) == '\x01') {
                  *(undefined4 *)(param_2 + 8) = 0x801;
                }
                else {
                  uVar13 = 0x2601;
                  if (*(char *)((int)piVar7 + 0x36) != '\x01') {
                    uVar13 = 0;
                  }
                  *(undefined4 *)(param_2 + 8) = uVar13;
                }
              }
              else {
                *(undefined4 *)(param_2 + 8) = 0;
              }
              if (*(char *)(iVar15 + 0x13b1) != '\0') {
                puVar17 = param_2;
                iVar12 = 1;
                do {
                  *(uint *)(puVar17 + 0x14) = local_5c[iVar12 + -1];
                  puVar17 = puVar17 + 4;
                  bVar25 = iVar12 < (int)(uint)*(byte *)(iVar15 + 0x13b1);
                  iVar12 = iVar12 + 1;
                } while (bVar25);
              }
              *(int *)(param_2 + 100) = *(int *)(param_2 + 0x60);
              *(int *)(param_2 + 0x68) = piVar7[0x9014] + piVar7[0x9015];
              *(int *)(param_2 + 0x6c) = piVar7[0x9014];
              *(int *)(param_2 + 0x70) = piVar7[0x9015];
              pvVar2 = (void *)((piVar7[0x9014] + piVar7[0x9015]) * 0x70 + 0x70 +
                               *(int *)(param_2 + 0x60));
              *(void **)(param_2 + 0x78) = pvVar2;
              *(int *)(param_2 + 0x7c) = piVar7[0x9149];
              pvVar8 = (void *)((int)pvVar2 + piVar7[0x9149] * 0x14);
              *(void **)(param_2 + 0x80) = pvVar8;
              *(int *)(param_2 + 0x84) = piVar7[0x928a];
              *(void **)(param_2 + 0x8c) = (void *)((int)pvVar8 + piVar7[0x928a] * 0x14);
              *(int *)(param_2 + 0x90) = piVar7[0x9116];
              *(int *)(param_2 + 0x88) = piVar7[0x928b];
              *(int *)(param_2 + 0x74) = local_a8;
              _memcpy(pvVar2,piVar7 + 0x9117,piVar7[0x9149] * 0x14);
              _memcpy(*(void **)(param_2 + 0x80),piVar7 + 0x914a,piVar7[0x928a] * 0x14);
              _memcpy(*(void **)(param_2 + 0x8c),piVar7 + 0x9016,piVar7[0x9116] << 4);
              if (piVar7[0x9015] + piVar7[0x9014] < 1) {
                local_64 = 0;
              }
              else {
                local_64 = 0;
                local_74 = 0;
                local_70 = 0;
                do {
                  puVar22 = (uint *)((int)piVar7 + local_74 + 0x50);
                  puVar19 = (uint *)(local_70 + *(int *)(param_2 + 100));
                  _memset(puVar19,0,0x70);
                  *puVar19 = *puVar22;
                  uVar16 = puVar22[1];
                  *(undefined1 *)(*(int *)(param_2 + 0x94) + local_64) = 0;
                  if (uVar16 != 0) {
                    uVar21 = *(uint *)(uVar16 + 0x1c);
                    puVar19[1] = *(uint *)(uVar16 + 0x18);
                    puVar19[2] = uVar21;
                    if (*(int *)(uVar16 + 0x18) == 3) {
                      if (*(int *)(uVar16 + 0x1c) == 1) {
                        param_2[4] = 1;
                      }
                      else if (*(int *)(uVar16 + 0x1c) == 0) {
                        *(char *)(local_64 + *(int *)(param_2 + 0x94)) =
                             (char)*(undefined4 *)(uVar16 + 0x24);
                      }
                    }
                  }
                  puVar19[3] = puVar22[2];
                  local_b8 = 0;
                  puVar23 = puVar19;
                  do {
                    uVar16 = puVar22[3];
                    if (uVar16 == 0) {
                      uVar16 = *puVar19;
                      if ((0x1c < uVar16) &&
                         (((uVar16 < 0x20 || (uVar16 - 0x3d < 3)) &&
                          (puVar23[0xb] = puVar22[9], local_b8 == 1)))) {
                        *(uint *)(param_2 + 0x10) =
                             *(uint *)(param_2 + 0x10) | 1 << ((byte)puVar19[0x13] & 0x1f);
                      }
                    }
                    else {
                      if (*(int *)(uVar16 + 0xc) == 0) {
                        uVar21 = *(uint *)(uVar16 + 0x1c);
                        puVar23[4] = *(uint *)(uVar16 + 0x18);
                        puVar23[5] = uVar21;
                        puVar23[0xb] = 0;
                      }
                      else {
                        puVar1 = (uint *)(*(int *)(uVar16 + 0x14) + puVar22[9] * 0x14);
                        uVar16 = puVar1[1];
                        puVar23[4] = *puVar1;
                        puVar23[5] = uVar16;
                        puVar23[0xb] = 0;
                      }
                      if (puVar23[4] == 1) {
                        iVar15 = *(int *)(param_2 + 0x78) + puVar23[5] * 0x14;
                        iVar12 = *(int *)(iVar15 + 8);
                        if (iVar12 == 1) {
                          if (*(int *)(iVar15 + 0xc) == 1) {
                            *param_2 = 1;
                          }
                        }
                        else if (iVar12 == 2) {
                          *(uint *)(param_2 + 0xc) =
                               *(uint *)(param_2 + 0xc) |
                               1 << ((byte)*(undefined4 *)(iVar15 + 0xc) & 0x1f);
                        }
                        else if (iVar12 == 3) {
                          param_2[1] = 1;
                        }
                        else if (iVar12 == 4) {
                          param_2[2] = 1;
                        }
                      }
                      puVar23[6] = puVar22[4];
                      puVar23[7] = puVar22[5];
                      puVar23[8] = puVar22[6];
                      puVar23[9] = puVar22[7];
                      *(char *)(puVar23 + 10) = (char)puVar22[8];
                    }
                    local_b8 = local_b8 + 1;
                    puVar22 = puVar22 + 7;
                    puVar23 = puVar23 + 8;
                  } while (local_b8 != 3);
                  local_64 = local_64 + 1;
                  local_74 = local_74 + 0x60;
                  local_70 = local_70 + 0x70;
                } while (local_64 < piVar7[0x9015] + piVar7[0x9014]);
              }
              _memset((void *)(local_64 * 0x70 + *(int *)(param_2 + 100)),0,0x70);
              *(undefined4 *)(local_64 * 0x70 + *(int *)(param_2 + 100)) = 0x41;
              param_2[0x54] = 1;
            }
          }
          goto LAB_00087466;
        }
        local_a4 = 0;
        local_a0 = 0;
        local_9c = 0;
        local_98 = 0;
        local_68 = 0;
        bVar5 = false;
        local_a8 = 1;
        local_6c = 0;
        do {
          puVar19 = (uint *)((int)piVar7 + local_6c + 0x50);
          uVar16 = *puVar19;
          if (0x1f < uVar16) {
            if (uVar16 - 0x3d < 3) goto LAB_00087b05;
LAB_00087968:
            if (*(int *)(puVar19[3] + 0x18) == 0) {
              uVar21 = *(uint *)(puVar19[3] + 0x1c);
              uVar20 = uVar21 >> 5 & 1;
              bVar24 = (byte)uVar21;
              local_9c = local_9c | (uVar20 ^ 1) << (bVar24 & 0x1f);
              local_98 = local_98 | uVar20 << (bVar24 & 0x1f);
            }
            uVar21 = puVar19[10];
            if ((uVar21 != 0) && (*(int *)(uVar21 + 0x18) == 0)) {
              uVar20 = *(uint *)(uVar21 + 0x1c) >> 5 & 1;
              bVar24 = (byte)*(uint *)(uVar21 + 0x1c);
              local_9c = local_9c | (uVar20 ^ 1) << (bVar24 & 0x1f);
              local_98 = local_98 | uVar20 << (bVar24 & 0x1f);
            }
            uVar21 = puVar19[0x11];
            if ((uVar21 != 0) && (*(int *)(uVar21 + 0x18) == 0)) {
              uVar20 = *(uint *)(uVar21 + 0x1c) >> 5 & 1;
              bVar24 = (byte)*(uint *)(uVar21 + 0x1c);
              local_9c = local_9c | (uVar20 ^ 1) << (bVar24 & 0x1f);
              local_98 = local_98 | uVar20 << (bVar24 & 0x1f);
            }
            local_dc = puVar19[1];
            if (*(int *)(local_dc + 0x18) == 0) {
              uVar21 = *(uint *)(local_dc + 0x1c) >> 5 & 1;
              bVar24 = (byte)*(uint *)(local_dc + 0x1c);
              local_9c = local_9c | (uVar21 ^ 1) << (bVar24 & 0x1f);
              local_98 = local_98 | uVar21 << (bVar24 & 0x1f);
            }
            if (uVar16 == 0xb) goto LAB_00087abc;
            goto LAB_00087a7f;
          }
          if ((uVar16 < 0x1d) && (uVar16 != 0xb)) goto LAB_00087968;
LAB_00087b05:
          uVar21 = *(uint *)(puVar19[3] + 0x1c);
          if (*(int *)(puVar19[3] + 0x18) == 0) {
            bVar14 = (byte)uVar21;
            bVar24 = bVar14 & 0x1f;
            uVar20 = local_a4 >> bVar24 | local_a0 << 0x20 - bVar24;
            if ((uVar21 & 0x20) != 0) {
              uVar20 = local_a0 >> (bVar14 & 0x1f);
            }
            if ((uVar20 & 1) == 0) goto LAB_00087b35;
LAB_00087b7a:
            local_a8 = local_a8 + 1;
            if (uVar16 == 0xb) {
              local_a4 = 0;
              local_a0 = 0;
              bVar5 = true;
              local_9c = 0;
              local_98 = 0;
              goto LAB_00087abc;
            }
            local_a4 = 0;
            local_a0 = 0;
            local_9c = 0;
            local_98 = 0;
LAB_00087be6:
            if (local_5c[puVar19[0x10]] == 0) {
              local_5c[puVar19[0x10]] = puVar19[0x17];
              local_dc = puVar19[1];
LAB_00087a7f:
              if (*(int *)(local_dc + 0x18) == 0) {
                uVar16 = *(uint *)(local_dc + 0x1c) >> 5 & 1;
                bVar24 = (byte)*(uint *)(local_dc + 0x1c);
                local_a4 = local_a4 | (uVar16 ^ 1) << (bVar24 & 0x1f);
                local_a0 = local_a0 | uVar16 << (bVar24 & 0x1f);
              }
              goto LAB_00087abc;
            }
            if (local_5c[puVar19[0x10]] == puVar19[0x17]) {
              local_dc = puVar19[1];
              goto LAB_00087a7f;
            }
            ((int (*)())FUN_000848a2)();
            goto LAB_00087466;
          }
LAB_00087b35:
          if (uVar16 != 0xb) {
            if (*(int *)(puVar19[1] + 0x18) == 0) {
              uVar21 = *(uint *)(puVar19[1] + 0x1c);
              bVar14 = (byte)uVar21;
              bVar24 = bVar14 & 0x1f;
              uVar20 = local_9c >> bVar24 | local_98 << 0x20 - bVar24;
              if ((uVar21 & 0x20) != 0) {
                uVar20 = local_98 >> (bVar14 & 0x1f);
              }
              if ((uVar20 & 1) != 0) goto LAB_00087b7a;
            }
            goto LAB_00087be6;
          }
          bVar5 = true;
LAB_00087abc:
          local_68 = local_68 + 1;
          local_6c = local_6c + 0x60;
          if (iVar18 == local_68) goto LAB_00087791;
        } while( true );
      }
      ((int (*)())FUN_000848a2)();
    }
    else {
      ((int (*)())FUN_000848a2)();
    }
  }
LAB_00087466:
  *(int *)(param_1 + 0x1124) = piVar7[10];
  if (*(int *)(param_1 + 0x1128) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_1 + 0x1128));
  }
  uVar16 = 0xffffffff;
  pcVar10 = (char *)piVar7[0xc];
  do {
    if (uVar16 == 0) break;
    uVar16 = uVar16 - 1;
    cVar6 = *pcVar10;
    pcVar10 = pcVar10 + 1;
  } while (cVar6 != '\0');
  pcVar10 = (char *)(**(code **)(param_1 + 0xc))(~uVar16 + 10);
  *(char **)(param_1 + 0x1128) = pcVar10;
  if ((uint)piVar7[0xb] < 10000) {
    _sprintf(pcVar10,"line %d: %s",piVar7[0xb],piVar7[0xc]);
  }
  else {
    _strcpy(pcVar10,(char *)piVar7[0xc]);
  }
  if (piVar7[1] != 0) {
    (**(code **)(param_1 + 0x18))(piVar7[1]);
  }
  puVar4 = (undefined4 *)piVar7[0xf];
  while (puVar4 != (undefined4 *)0x0) {
    if ((undefined4 *)puVar4[5] != puVar4 + 6) {
      (**(code **)(param_1 + 0x18))((undefined4 *)puVar4[5]);
    }
    puVar3 = (undefined4 *)*puVar4;
    (**(code **)(param_1 + 0x18))(puVar4);
    puVar4 = puVar3;
  }
  puVar4 = (undefined4 *)piVar7[0x11];
  while (puVar4 != (undefined4 *)0x0) {
    if ((undefined4 *)puVar4[5] != puVar4 + 6) {
      (**(code **)(param_1 + 0x18))((undefined4 *)puVar4[5]);
    }
    puVar3 = (undefined4 *)*puVar4;
    (**(code **)(param_1 + 0x18))(puVar4);
    puVar4 = puVar3;
  }
  puVar4 = (undefined4 *)piVar7[0x13];
  while (puVar4 != (undefined4 *)0x0) {
    puVar3 = (undefined4 *)*puVar4;
    (**(code **)(param_1 + 0x18))(puVar4);
    puVar4 = puVar3;
  }
                    
                    
  (**(code **)(param_1 + 0x18))();
  return;
}

/* FUN_00088206 @ 0x88206 (1416 bytes) */
int FUN_00088206(param_1)
  int param_1;
{
  char *pcVar1;
  undefined1 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  uint local_1c;
  uint local_18;
  byte local_14;
  
  iVar10 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  iVar14 = param_1 + 0x11d0;
  bVar7 = *(byte *)(param_1 + 0x46) >> 2 & 1;
  pcVar1 = *(char **)(param_1 + 0x121c);
  *(undefined1 *)(param_1 + 0x11d1) = 0;
  *(undefined1 *)(param_1 + 0x11d2) = 0;
  if (*(char *)(*(int *)(pcVar1 + 0x74) + 0x54) == '\0') {
    *(undefined1 *)(param_1 + 0x11d3) = 0;
    *(undefined4 *)(param_1 + 0x1228) = 0;
    if (*(char *)(param_1 + 0x13b1) != '\0') {
      iVar13 = 0;
      iVar11 = iVar14;
      do {
        *(undefined4 *)(iVar11 + 0x5c) = 0;
        iVar13 = iVar13 + 1;
        iVar11 = iVar11 + 4;
      } while (iVar13 < (int)(uint)*(byte *)(param_1 + 0x13b1));
    }
    local_1c = 0xffffffff;
  }
  else {
    uVar4 = *(uint *)(pcVar1 + 8);
    *(char *)(param_1 + 0x11d3) = (char)uVar4;
    uVar12 = *(uint *)(pcVar1 + 0xc);
    *(uint *)(param_1 + 0x1228) = uVar12;
    uVar3 = *(byte *)(param_1 + 0x13b6) - 1;
    if ((int)uVar3 < 0) {
LAB_000887d1:
      local_1c = 0xffffffff;
    }
    else {
      uVar12 = uVar4 & 0xff | uVar12;
      local_14 = (byte)uVar3;
      local_1c = uVar3;
      if ((uVar12 >> (local_14 & 0x1f) & 1) == 0) {
        uVar4 = 0;
        do {
          local_1c = local_1c - 1;
          if (uVar4 == uVar3) goto LAB_000887d1;
          uVar4 = uVar4 + 1;
        } while ((uVar12 >> ((byte)local_1c & 0x1f) & 1) == 0);
      }
    }
    if (*(char *)(param_1 + 0x13b1) != '\0') {
      iVar13 = 0;
      pcVar6 = pcVar1;
      iVar11 = iVar14;
      do {
        switch(*(undefined4 *)(pcVar6 + 0x10)) {
        case 0:
          *(undefined4 *)(iVar11 + 0x5c) = 0;
          break;
        case 1:
        case 6:
          *(undefined4 *)(iVar11 + 0x5c) = 0x10;
          break;
        case 2:
        case 7:
          *(undefined4 *)(iVar11 + 0x5c) = 8;
          break;
        case 3:
          *(undefined4 *)(iVar11 + 0x5c) = 2;
          break;
        case 4:
          *(undefined4 *)(iVar11 + 0x5c) = 1;
          break;
        case 5:
        case 8:
          *(undefined4 *)(iVar11 + 0x5c) = 4;
        }
        iVar13 = iVar13 + 1;
        pcVar6 = pcVar6 + 4;
        iVar11 = iVar11 + 4;
      } while (iVar13 < (int)(uint)*(byte *)(param_1 + 0x13b1));
    }
  }
  if ((pcVar1[4] == '\0') || (bVar7 == 0)) {
    bVar9 = *(byte *)(param_1 + 0x46);
    if ((bVar9 & 0x40) != 0) {
      bVar9 = bVar9 & 0xbf;
      *(byte *)(param_1 + 0x46) = bVar9;
      *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 1;
      *(undefined1 *)(param_1 + 0x29) = 1;
    }
  }
  else {
    bVar9 = *(byte *)(param_1 + 0x46);
    if ((bVar9 & 0x40) == 0) {
      bVar9 = bVar9 | 0x40;
      *(byte *)(param_1 + 0x46) = bVar9;
      *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 1;
      *(undefined1 *)(param_1 + 0x29) = 1;
    }
  }
  if ((*pcVar1 == '\0') || (bVar7 == 0)) {
    if ((bVar9 & 8) != 0) {
      bVar9 = bVar9 & 0xf7;
      *(byte *)(param_1 + 0x46) = bVar9;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
      *(undefined1 *)(param_1 + 0x29) = 1;
    }
    if ((bVar7 == 0) && ((bVar9 & 2) != 0)) goto LAB_000885c5;
    if ((char)*(byte *)(param_1 + 0x45) < '\0') {
      *(byte *)(param_1 + 0x45) = *(byte *)(param_1 + 0x45) & 0x7f;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
      *(undefined1 *)(param_1 + 0x29) = 1;
    }
  }
  else {
    if ((bVar9 & 8) == 0) {
      bVar9 = bVar9 | 8;
      *(byte *)(param_1 + 0x46) = bVar9;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
      *(undefined1 *)(param_1 + 0x29) = 1;
    }
LAB_000885c5:
    if (-1 < (char)*(byte *)(param_1 + 0x45)) {
      *(byte *)(param_1 + 0x45) = *(byte *)(param_1 + 0x45) | 0x80;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
      *(undefined1 *)(param_1 + 0x29) = 1;
    }
  }
  if ((pcVar1[3] == '\0') || (bVar7 == 0)) {
    if ((char)bVar9 < '\0') {
      bVar9 = bVar9 & 0x7f;
      *(byte *)(param_1 + 0x46) = bVar9;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 1;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(undefined1 *)(param_1 + 0x2a) = 1;
    }
  }
  else if (-1 < (char)bVar9) {
    bVar9 = bVar9 | 0x80;
    *(byte *)(param_1 + 0x46) = bVar9;
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 1;
    *(undefined1 *)(param_1 + 0x29) = 1;
    *(undefined1 *)(param_1 + 0x2a) = 1;
  }
  if ((pcVar1[1] == '\0') || (bVar7 == 0)) {
    if ((bVar9 & 0x10) != 0) {
      bVar9 = bVar9 & 0xef;
      *(byte *)(param_1 + 0x46) = bVar9;
      *(byte *)(param_1 + 0x1876) = *(byte *)(param_1 + 0x1876) & 0xfb;
      goto LAB_00088595;
    }
  }
  else {
    if ((bVar9 & 0x10) == 0) {
      bVar9 = bVar9 | 0x10;
      *(byte *)(param_1 + 0x46) = bVar9;
      *(byte *)(param_1 + 0x1876) = *(byte *)(param_1 + 0x1876) | 4;
    }
LAB_00088595:
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
    *(undefined1 *)(param_1 + 0x29) = 1;
  }
  if ((pcVar1[2] == '\0') || (bVar7 == 0)) {
    if ((bVar9 & 0x20) != 0) {
      bVar9 = bVar9 & 0xdf;
      *(byte *)(param_1 + 0x46) = bVar9;
      *(byte *)(param_1 + 0x1876) = *(byte *)(param_1 + 0x1876) & 0xf7;
      goto LAB_00088578;
    }
  }
  else {
    if ((bVar9 & 0x20) == 0) {
      bVar9 = bVar9 | 0x20;
      *(byte *)(param_1 + 0x46) = bVar9;
      *(byte *)(param_1 + 0x1876) = *(byte *)(param_1 + 0x1876) | 8;
    }
LAB_00088578:
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
    *(undefined1 *)(param_1 + 0x29) = 1;
  }
  uVar4 = local_1c;
  if ((bVar9 & 0x30) != 0) {
    bVar8 = *(byte *)(param_1 + 0x13b0);
    if (bVar8 == 0) {
      local_18 = 0xffffffff;
      uVar12 = 0xffffffff;
    }
    else {
      uVar5 = 0;
      local_18 = 0xffffffff;
      uVar3 = 0xffffffff;
      do {
        uVar12 = uVar3;
        if (((((int)(uint)*(byte *)(param_1 + 0x11d3) >> ((byte)uVar5 & 0x1f) & 1U) == 0) &&
            (uVar12 = uVar5, uVar3 != 0xffffffff)) && (uVar12 = uVar3, local_18 == 0xffffffff)) {
          local_18 = uVar5;
        }
        uVar5 = uVar5 + 1;
        uVar3 = uVar12;
      } while (uVar5 != bVar8);
    }
    if ((bVar9 & 0x10) == 0) {
      if ((bVar9 & 0x20) != 0) {
        uVar4 = (uint)bVar8;
        if (uVar12 != 0xffffffff) {
          uVar4 = uVar12;
        }
        *(char *)(param_1 + 0x11d2) = (char)uVar4;
        uVar4 = uVar12;
        if ((int)uVar12 <= (int)local_1c) {
          uVar4 = local_1c;
        }
      }
    }
    else {
      uVar4 = (uint)bVar8;
      if (uVar12 != 0xffffffff) {
        uVar4 = uVar12;
      }
      *(char *)(param_1 + 0x11d1) = (char)uVar4;
      if ((int)uVar12 <= (int)local_1c) {
        uVar12 = local_1c;
      }
      uVar4 = uVar12;
      if ((*(byte *)(param_1 + 0x46) & 0x20) != 0) {
        if (local_18 == 0xffffffff) {
          uVar2 = *(undefined1 *)(param_1 + 0x13b0);
        }
        else {
          uVar2 = (undefined1)local_18;
        }
        *(undefined1 *)(param_1 + 0x11d2) = uVar2;
        if ((int)uVar12 < (int)local_18) {
          local_1c = local_18;
          uVar4 = local_1c;
        }
      }
    }
  }
  local_1c = uVar4;
  if ((bVar7 == 0) && (*(char *)(iVar10 + 0x2e0a) != '\0')) {
    if (-1 < (char)*(byte *)(param_1 + 0x44)) {
      bVar9 = *(byte *)(param_1 + 0x44) | 0x80;
      *(byte *)(param_1 + 0x44) = bVar9;
      *(byte *)(param_1 + 0x18a4) = *(byte *)(param_1 + 0x18a4) | 1;
      uVar4 = *(uint *)(param_1 + 0x38);
      *(uint *)(param_1 + 0x38) = uVar4 | 0x100;
      *(undefined1 *)(param_1 + 0x29) = 1;
      bVar7 = *(byte *)(param_1 + 0x45);
      if (((bVar9 | bVar7 | bVar7 >> 2) & 1) != 0 || (char)bVar7 < '\0') {
        *(uint *)(param_1 + 0x38) = uVar4 | 0x120;
      }
    }
  }
  else {
    if ((char)*(byte *)(param_1 + 0x44) < '\0') {
      bVar8 = *(byte *)(param_1 + 0x44) & 0x7f;
      *(byte *)(param_1 + 0x44) = bVar8;
      *(byte *)(param_1 + 0x18a4) = *(byte *)(param_1 + 0x18a4) & 0xfe;
      uVar4 = *(uint *)(param_1 + 0x38);
      *(uint *)(param_1 + 0x38) = uVar4 | 0x100;
      *(undefined1 *)(param_1 + 0x29) = 1;
      bVar9 = *(byte *)(param_1 + 0x45);
      if (((bVar8 | bVar9 | bVar9 >> 2) & 1) != 0 || (char)bVar9 < '\0') {
        *(uint *)(param_1 + 0x38) = uVar4 | 0x120;
        if (bVar7 == 0) goto LAB_00088484;
        goto LAB_000884a3;
      }
    }
    if (bVar7 != 0) {
LAB_000884a3:
      if (*(char *)(param_1 + 0x13b1) != '\0') {
        iVar11 = 0;
        iVar10 = param_1;
        do {
          uVar4 = *(uint *)(iVar10 + 0x48) & 0xffffffe0;
          *(uint *)(iVar10 + 0x48) = uVar4;
          *(uint *)(iVar10 + 0x48) = uVar4 | *(uint *)(iVar14 + 0x5c);
          iVar11 = iVar11 + 1;
          iVar10 = iVar10 + 4;
          iVar14 = iVar14 + 4;
        } while (iVar11 < (int)(uint)*(byte *)(param_1 + 0x13b1));
      }
      if ((int)(uint)*(byte *)(param_1 + 0x2b) <= (int)local_1c) {
        *(char *)(param_1 + 0x2b) = (char)local_1c + '\x01';
      }
      *(byte *)(param_1 + 0x2e) = *(byte *)(param_1 + 0x2e) | 3;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x2200;
      *(ushort *)(param_1 + 0x34) =
           *(ushort *)(param_1 + 0x34) | (short)(1 << (*(byte *)(param_1 + 0x13b6) & 0x1f)) - 1U;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x40;
      *(undefined1 *)(param_1 + 0x29) = 1;
      return;
    }
  }
LAB_00088484:
  uVar4 = *(uint *)(param_1 + 0x3c);
  *(uint *)(param_1 + 0x3c) = uVar4 | 0x100;
  *(undefined1 *)(param_1 + 0x29) = 1;
  *(uint *)(param_1 + 0x3c) = uVar4 | 0x140;
  *(undefined1 *)(param_1 + 0x29) = 1;
  return;
}

/* FUN_000887e9 @ 0x887e9 (75 bytes) */
int FUN_000887e9(param_1, param_2)
  int param_1;
  int param_2;
{
  if (*(int *)(param_1 + 0x1270) != param_2) {
    *(int *)(param_1 + 0x1270) = param_2;
    *(undefined4 *)(param_1 + 0x121c) =
         *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x112c) + 8) + 0x14 + param_2 * 0x18);
    ((int (*)())FUN_00088206)(param_1);
    *(undefined1 *)(param_1 + 0x11d0) = 1;
  }
  return;
}

/* FUN_00088834 @ 0x88834 (15 bytes) */
int FUN_00088834(param_1)
  int param_1;
{
                    
                    
  (**(code **)(param_1 + 0x1278))();
  return;
}

/* FUN_00088843 @ 0x88843 (271 bytes) */
int FUN_00088843(param_1, param_2)
  int param_1;
  undefined1 *param_2;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[4] = 0;
  *(undefined4 *)(param_2 + 8) = 0;
  *(undefined4 *)(param_2 + 0xc) = 0;
  if (*(char *)(param_1 + 0x13b1) != '\0') {
    iVar4 = 0;
    puVar5 = param_2;
    do {
      *(undefined4 *)(puVar5 + 0x10) = 0;
      iVar4 = iVar4 + 1;
      puVar5 = puVar5 + 4;
    } while (iVar4 < (int)(uint)*(byte *)(param_1 + 0x13b1));
  }
  uVar1 = (**(code **)(param_1 + 0x10))(*(undefined4 *)(*(int *)(param_1 + 0x112c) + 0x10),4);
  *(undefined4 *)(param_2 + 0x70) = uVar1;
  *(undefined4 *)(param_2 + 0x50) = 0;
  *(undefined4 *)(param_2 + 0x54) = 0;
  *(undefined4 *)(param_2 + 0x58) = 0;
  *(undefined4 *)(param_2 + 0x5c) = 0;
  *(undefined4 *)(param_2 + 0x60) = 0;
  *(undefined4 *)(param_2 + 100) = 0;
  *(undefined4 *)(param_2 + 0x68) = 0;
  param_2[0x6c] = 1;
  iVar2 = (**(code **)(param_1 + 0xc))(0x98);
  *(int *)(param_2 + 0x74) = iVar2;
  *(undefined1 *)(iVar2 + 0x54) = 0;
  *(undefined1 *)(*(int *)(param_2 + 0x74) + 0x55) = 0;
  *(undefined4 *)(*(int *)(param_2 + 0x74) + 0x60) = 0;
  *(undefined4 *)(*(int *)(param_2 + 0x74) + 0x58) = 0;
  iVar4 = *(int *)(param_1 + 0x11d4);
  iVar3 = (**(code **)(param_1 + 0x10))(iVar4,1);
  *(int *)(iVar2 + 0x94) = iVar3;
  if (0 < iVar4) {
    iVar2 = 0;
    do {
      *(undefined1 *)(iVar3 + iVar2) = 0;
      iVar2 = iVar2 + 1;
    } while (iVar4 != iVar2);
  }
  return;
}

/* FUN_00088952 @ 0x88952 (301 bytes) */
int FUN_00088952(param_1, param_2)
  int param_1;
  undefined1 *param_2;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[4] = 0;
  *(undefined4 *)(param_2 + 8) = 0;
  *(undefined4 *)(param_2 + 0xc) = 0;
  if (*(char *)(param_1 + 0x13b1) != '\0') {
    iVar3 = 0;
    puVar5 = param_2;
    do {
      *(undefined4 *)(puVar5 + 0x10) = 0;
      iVar3 = iVar3 + 1;
      puVar5 = puVar5 + 4;
    } while (iVar3 < (int)(uint)*(byte *)(param_1 + 0x13b1));
  }
  iVar3 = *(int *)(param_1 + 0x112c);
  if (*(int *)(param_2 + 0x70) != 0) {
    if (*(int *)(iVar3 + 0x10) < 1) {
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0x70));
      *(undefined4 *)(param_2 + 0x70) = 0;
    }
    else {
      iVar6 = 0;
      iVar4 = *(int *)(param_2 + 0x70);
      do {
        piVar1 = (int *)(iVar4 + iVar6 * 4);
        iVar2 = *piVar1;
        if (iVar2 != 0) {
          *piVar1 = 0;
          (**(code **)(param_1 + 0x1224))(param_1,iVar2);
          iVar4 = *(int *)(param_2 + 0x70);
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < *(int *)(iVar3 + 0x10));
      (**(code **)(param_1 + 0x18))(iVar4);
      *(undefined4 *)(param_2 + 0x70) = 0;
    }
  }
  iVar3 = *(int *)(param_2 + 0x74);
  if (iVar3 != 0) {
    if (*(int *)(iVar3 + 0x60) != 0) {
      (**(code **)(param_1 + 0x18))(*(int *)(iVar3 + 0x60));
      *(undefined4 *)(*(int *)(param_2 + 0x74) + 0x60) = 0;
      iVar3 = *(int *)(param_2 + 0x74);
    }
    if (*(int *)(iVar3 + 0x94) != 0) {
      (**(code **)(param_1 + 0x18))(*(int *)(iVar3 + 0x94));
      *(undefined4 *)(*(int *)(param_2 + 0x74) + 0x94) = 0;
      iVar3 = *(int *)(param_2 + 0x74);
    }
    (**(code **)(param_1 + 0x18))(iVar3);
    *(undefined4 *)(param_2 + 0x74) = 0;
  }
  return;
}

/* FUN_00088a7f @ 0x88a7f (760 bytes) */
int FUN_00088a7f(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  char *param_4;
{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined1 *puVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  char *pcVar12;
  bool bVar13;
  
  puVar8 = (undefined1 *)param_1[0x487];
  if ((*(int *)(puVar8 + 0x74) != 0) && (iVar5 = (*(code *)param_1[3])(0x78), iVar5 != 0)) {
    ((int (*)())FUN_00088843)(param_1,iVar5);
    iVar1 = *(int *)(iVar5 + 0x74);
    if (iVar1 == 0) {
      ((int (*)())FUN_00088952)(param_1,iVar5);
      (*(code *)param_1[6])(iVar5);
      *param_1 = 0x505;
      return;
    }
    iVar2 = param_1[1099];
    iVar7 = 10;
    bVar13 = false;
    pcVar9 = param_4;
    pcVar11 = "!!ILfs1.0\n";
    do {
      pcVar10 = pcVar9;
      pcVar12 = pcVar11;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      pcVar12 = pcVar11 + 1;
      pcVar10 = pcVar9 + 1;
      bVar13 = *pcVar9 == *pcVar11;
      pcVar9 = pcVar10;
      pcVar11 = pcVar12;
    } while (bVar13);
    iVar7 = 0;
    if (!bVar13) {
      iVar7 = (uint)(byte)pcVar10[-1] - (uint)(byte)pcVar12[-1];
    }
    if (iVar7 == 0) {
      *(undefined1 *)(iVar1 + 0x55) = 1;
      *(char **)(*(int *)(iVar5 + 0x74) + 0x58) = param_4;
      *(undefined4 *)(*(int *)(iVar5 + 0x74) + 0x5c) = param_3;
      *(undefined1 *)(*(int *)(iVar5 + 0x74) + 0x54) = 1;
    }
    else {
      *(undefined1 *)(iVar1 + 0x55) = 0;
      ((int (*)())FUN_0008721d)(param_4);
      if (*(char *)(*(int *)(iVar5 + 0x74) + 0x54) == '\0') {
        ((int (*)())FUN_00088952)(param_1,iVar5);
        (*(code *)param_1[6])(iVar5);
        *param_1 = 0x502;
        return;
      }
    }
    param_1[0x487] = iVar5;
    *(int *)(*(int *)(iVar2 + 8) + 0x14 + param_1[0x49c] * 0x18) = iVar5;
    iVar1 = *(int *)(puVar8 + 0x74);
    *(undefined1 *)(iVar5 + 2) = *(undefined1 *)(iVar1 + 2);
    *(undefined1 *)(iVar5 + 1) = *(undefined1 *)(iVar1 + 1);
    cVar4 = (*(code *)param_1[0x49f])(param_1,1);
    if (cVar4 == '\0') {
      *param_1 = 0x502;
    }
    iVar1 = *(int *)(param_1[1099] + 8) + param_1[0x49c] * 0x18;
    *(undefined4 *)(iVar1 + 8) = param_2;
    *(undefined4 *)(iVar1 + 0xc) = param_3;
    if (*(int *)(iVar1 + 0x10) != 0) {
      (*(code *)param_1[6])(*(int *)(iVar1 + 0x10));
    }
    uVar6 = (*(code *)param_1[3])(param_3);
    *(undefined4 *)(iVar1 + 0x10) = uVar6;
    (*(code *)param_1[0x4d1])(uVar6,param_4,param_3);
    *(undefined4 *)(*(int *)(iVar5 + 0x74) + 0x58) = *(undefined4 *)(iVar1 + 0x10);
    param_1[0x487] = puVar8;
    *(undefined1 **)(*(int *)(iVar2 + 8) + 0x14 + param_1[0x49c] * 0x18) = puVar8;
    *(undefined4 *)(puVar8 + 0x50) = *(undefined4 *)(iVar5 + 0x50);
    *(undefined4 *)(puVar8 + 0x54) = *(undefined4 *)(iVar5 + 0x54);
    *(undefined4 *)(puVar8 + 0x58) = *(undefined4 *)(iVar5 + 0x58);
    *(undefined4 *)(puVar8 + 0x5c) = *(undefined4 *)(iVar5 + 0x5c);
    *(undefined4 *)(puVar8 + 0x60) = *(undefined4 *)(iVar5 + 0x60);
    *(undefined4 *)(puVar8 + 100) = *(undefined4 *)(iVar5 + 100);
    *(undefined4 *)(puVar8 + 0x68) = *(undefined4 *)(iVar5 + 0x68);
    puVar8[0x6c] = *(undefined1 *)(iVar5 + 0x6c);
    uVar6 = *(undefined4 *)(puVar8 + 0x70);
    *(undefined4 *)(puVar8 + 0x70) = *(undefined4 *)(iVar5 + 0x70);
    *(undefined4 *)(iVar5 + 0x70) = uVar6;
    uVar6 = *(undefined4 *)(puVar8 + 0x74);
    *(undefined4 *)(puVar8 + 0x74) = *(undefined4 *)(iVar5 + 0x74);
    *(undefined4 *)(iVar5 + 0x74) = uVar6;
    ((int (*)())FUN_00088952)(param_1,iVar5);
    (*(code *)param_1[6])(iVar5);
    puVar3 = *(undefined1 **)(puVar8 + 0x74);
    puVar8[4] = puVar3[4];
    *puVar8 = *puVar3;
    puVar8[1] = puVar3[1];
    puVar8[2] = puVar3[2];
    puVar8[3] = puVar3[3];
    *(undefined4 *)(puVar8 + 8) = *(undefined4 *)(puVar3 + 0xc);
    *(undefined4 *)(puVar8 + 0xc) = *(undefined4 *)(puVar3 + 0x10);
    if (*(char *)((int)param_1 + 0x13b1) != '\0') {
      iVar5 = 0;
      do {
        *(undefined4 *)(puVar8 + 0x10) = *(undefined4 *)(puVar3 + iVar5 * 4 + 0x14);
        iVar5 = iVar5 + 1;
        puVar8 = puVar8 + 4;
      } while (iVar5 < (int)(uint)*(byte *)((int)param_1 + 0x13b1));
    }
    ((int (*)())FUN_00088206)(param_1);
    *(undefined1 *)(param_1 + 0x474) = 1;
  }
  return;
}

/* FUN_00088d77 @ 0x88d77 (170 bytes) */
int FUN_00088d77(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  void *param_4;
{
  size_t sVar1;
  undefined4 *puVar2;
  
  sVar1 = param_2 * 4;
  puVar2 = _malloc(sVar1 + 0xd);
  *puVar2 = 0x4c492121;
  puVar2[1] = 0x2e317366;
  puVar2[2] = 0xa0a0a30;
  *(undefined1 *)(puVar2 + 3) = 0;
  _memcpy((void *)((int)puVar2 + 10),param_4,sVar1);
  *(undefined1 *)(puVar2 + param_2 + 3) = 0;
  ((int (*)())FUN_00088a7f)(param_1,0x8875,sVar1 + 0xc,puVar2);
  _free(puVar2);
  return;
}

/* FUN_00089a08 @ 0x89a08 (5564 bytes) */
int FUN_00089a08(param_1, param_2, param_3)
  int param_1;
  int param_2;
  float *param_3;
{
  float *pfVar1;
  float *pfVar2;
  int iVar3;
  float *pfVar4;
  float *pfVar5;
  float *pfVar6;
  float *pfVar7;
  float *pfVar8;
  undefined8 *puVar9;
  int iVar10;
  int iVar11;
  float *pfVar12;
  float *pfVar13;
  float *pfVar14;
  int iVar15;
  uint uVar16;
  float *pfVar17;
  float *pfVar18;
  float *pfVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float *local_118;
  float *local_114;
  float local_dc [48];
  undefined4 uStack_1c;
  float *local_18;
  int local_14;
  
  uStack_1c = 0x89a16;
  local_14 = param_2;
  local_18 = param_3;
  iVar10 = *(int *)(param_1 + 4);
  iVar11 = *(int *)(iVar10 + 0x10);
  iVar3 = *(int *)(param_2 + 0xc);
  iVar15 = *(int *)(param_2 + 8);
  switch(iVar15) {
  case 5:
    if (iVar3 == 0) {
      *param_3 = *(float *)(iVar11 + 0x28c0);
      param_3[1] = *(float *)(iVar11 + 0x28c4);
      param_3[2] = *(float *)(iVar11 + 0x28c8);
      param_3[3] = *(float *)(iVar11 + 0x28cc);
    }
    else {
      *param_3 = *(float *)(iVar11 + 0x2b00);
      param_3[1] = *(float *)(iVar11 + 0x2b04);
      param_3[2] = *(float *)(iVar11 + 0x2b08);
      param_3[3] = *(float *)(iVar11 + 0x2b0c);
    }
    break;
  case 6:
    if (iVar3 == 0) {
      *param_3 = *(float *)(iVar11 + 0x28d0);
      param_3[1] = *(float *)(iVar11 + 0x28d4);
      param_3[2] = *(float *)(iVar11 + 0x28d8);
      param_3[3] = *(float *)(iVar11 + 0x28dc);
    }
    else {
      *param_3 = *(float *)(iVar11 + 0x2b10);
      param_3[1] = *(float *)(iVar11 + 0x2b14);
      param_3[2] = *(float *)(iVar11 + 0x2b18);
      param_3[3] = *(float *)(iVar11 + 0x2b1c);
    }
    break;
  case 7:
    if (iVar3 == 0) {
      *param_3 = *(float *)(iVar11 + 0x28e0);
      param_3[1] = *(float *)(iVar11 + 0x28e4);
      param_3[2] = *(float *)(iVar11 + 0x28e8);
      param_3[3] = *(float *)(iVar11 + 0x28ec);
    }
    else {
      *param_3 = *(float *)(iVar11 + 0x2b20);
      param_3[1] = *(float *)(iVar11 + 0x2b24);
      param_3[2] = *(float *)(iVar11 + 0x2b28);
      param_3[3] = *(float *)(iVar11 + 0x2b2c);
    }
    break;
  case 8:
    if (iVar3 == 0) {
      *param_3 = *(float *)(iVar11 + 0x28f0);
      param_3[1] = *(float *)(iVar11 + 0x28f4);
      param_3[2] = *(float *)(iVar11 + 0x28f8);
      param_3[3] = *(float *)(iVar11 + 0x28fc);
    }
    else {
      *param_3 = *(float *)(iVar11 + 0x2b30);
      param_3[1] = *(float *)(iVar11 + 0x2b34);
      param_3[2] = *(float *)(iVar11 + 0x2b38);
      param_3[3] = *(float *)(iVar11 + 0x2b3c);
    }
    break;
  case 9:
    if (iVar3 == 0) {
      fVar23 = *(float *)(iVar11 + 0x2900);
    }
    else {
      fVar23 = *(float *)(iVar11 + 0x2b40);
    }
    *param_3 = fVar23;
    param_3[2] = 0.0;
    param_3[1] = 0.0;
    param_3[3] = 1.0;
    break;
  case 10:
    *param_3 = *(float *)(iVar3 * 0x80 + 0x24c0 + iVar11);
    param_3[1] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + 0x24c4 + iVar11);
    param_3[2] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + 0x24c8 + iVar11);
    param_3[3] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + 0x24cc + iVar11);
    break;
  case 0xb:
    *param_3 = *(float *)(iVar3 * 0x80 + 0x24d0 + iVar11);
    param_3[1] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + 0x24d4 + iVar11);
    param_3[2] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + 0x24d8 + iVar11);
    param_3[3] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + 0x24dc + iVar11);
    break;
  case 0xc:
    *param_3 = *(float *)(iVar3 * 0x80 + 0x24e0 + iVar11);
    param_3[1] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + 0x24e4 + iVar11);
    param_3[2] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + 0x24e8 + iVar11);
    param_3[3] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + 0x24ec + iVar11);
    break;
  case 0xd:
    *param_3 = *(float *)(iVar3 * 0x80 + 0x24f0 + iVar11);
    param_3[1] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + 0x24f4 + iVar11);
    param_3[2] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + 0x24f8 + iVar11);
    param_3[3] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + 0x24fc + iVar11);
    break;
  case 0xe:
    *param_3 = *(float *)(iVar3 * 0x80 + 0x2510 + iVar11);
    param_3[1] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + 0x2514 + iVar11);
    param_3[2] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + 0x2518 + iVar11);
    param_3[3] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + 0x251c + iVar11);
    break;
  case 0xf:
    *param_3 = *(float *)(iVar3 * 0x80 + 0x2500 + iVar11);
    param_3[1] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + 0x2504 + iVar11);
    param_3[2] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + 0x2508 + iVar11);
    param_3[3] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + 0x250c + iVar11);
    break;
  case 0x10:
    fVar23 = *(float *)(iVar3 * 0x80 + 0x24f0 + iVar11);
    *param_3 = fVar23;
    fVar20 = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + 0x24f4 + iVar11);
    param_3[1] = fVar20;
    fVar21 = FLOAT_001c5ba4;
    fVar22 = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + 0x24f8 + iVar11) + FLOAT_001c5ba4;
    fVar23 = FLOAT_001c5ba4 / SQRT(fVar23 * fVar23 + fVar20 * fVar20 + fVar22 * fVar22);
    *param_3 = fVar23 * *param_3;
    param_3[1] = fVar20 * fVar23;
    param_3[2] = fVar22 * fVar23;
    param_3[3] = fVar21;
    break;
  case 0x11:
    *param_3 = *(float *)(iVar11 + 0x24b0);
    param_3[1] = *(float *)(iVar11 + 0x24b4);
    param_3[2] = *(float *)(iVar11 + 0x24b8);
    param_3[3] = *(float *)(iVar11 + 0x24bc);
    break;
  case 0x12:
    if (iVar3 == 0) {
      *param_3 = *(float *)(iVar11 + 0x24b0) * *(float *)(iVar11 + 0x28c0) +
                 *(float *)(iVar11 + 0x28f0);
      param_3[1] = *(float *)(iVar11 + 0x24b4) * *(float *)(iVar11 + 0x28c4) +
                   *(float *)(iVar11 + 0x28f4);
      param_3[2] = *(float *)(iVar11 + 0x24b8) * *(float *)(iVar11 + 0x28c8) +
                   *(float *)(iVar11 + 0x28f8);
      param_3[3] = *(float *)(iVar11 + 0x28dc);
    }
    else {
      *param_3 = *(float *)(iVar11 + 0x24b0) * *(float *)(iVar11 + 0x2b00) +
                 *(float *)(iVar11 + 0x2b30);
      param_3[1] = *(float *)(iVar11 + 0x24b4) * *(float *)(iVar11 + 0x2b04) +
                   *(float *)(iVar11 + 0x2b34);
      param_3[2] = *(float *)(iVar11 + 0x24b8) * *(float *)(iVar11 + 0x2b08) +
                   *(float *)(iVar11 + 0x2b38);
      param_3[3] = *(float *)(iVar11 + 0x2b1c);
    }
    break;
  case 0x13:
    if (*(int *)(param_2 + 0x10) == 0) {
      fVar23 = *(float *)(iVar11 + 0x28c0);
    }
    else {
      fVar23 = *(float *)(iVar11 + 0x2b00);
    }
    *param_3 = fVar23 * *(float *)(iVar3 * 0x80 + 0x24c0 + iVar11);
    if (*(int *)(param_2 + 0x10) == 0) {
      fVar23 = *(float *)(iVar11 + 0x28c4);
    }
    else {
      fVar23 = *(float *)(iVar11 + 0x2b04);
    }
    param_3[1] = fVar23 * *(float *)(*(int *)(param_2 + 0xc) * 0x80 + 0x24c4 + iVar11);
    if (*(int *)(param_2 + 0x10) == 0) {
      fVar23 = *(float *)(iVar11 + 0x28c8);
    }
    else {
      fVar23 = *(float *)(iVar11 + 0x2b08);
    }
    param_3[2] = fVar23 * *(float *)(*(int *)(param_2 + 0xc) * 0x80 + 0x24c8 + iVar11);
    if (*(int *)(param_2 + 0x10) == 0) {
      fVar23 = *(float *)(iVar11 + 0x28cc);
    }
    else {
      fVar23 = *(float *)(iVar11 + 0x2b0c);
    }
    goto LAB_00089bab;
  case 0x14:
    if (*(int *)(param_2 + 0x10) == 0) {
      fVar23 = *(float *)(iVar11 + 0x28d0);
    }
    else {
      fVar23 = *(float *)(iVar11 + 0x2b10);
    }
    *param_3 = fVar23 * *(float *)(iVar3 * 0x80 + 0x24d0 + iVar11);
    if (*(int *)(param_2 + 0x10) == 0) {
      fVar23 = *(float *)(iVar11 + 0x28d4);
    }
    else {
      fVar23 = *(float *)(iVar11 + 0x2b14);
    }
    param_3[1] = fVar23 * *(float *)(*(int *)(param_2 + 0xc) * 0x80 + 0x24d4 + iVar11);
    if (*(int *)(param_2 + 0x10) == 0) {
      fVar23 = *(float *)(iVar11 + 0x28d8);
    }
    else {
      fVar23 = *(float *)(iVar11 + 0x2b18);
    }
    param_3[2] = fVar23 * *(float *)(*(int *)(param_2 + 0xc) * 0x80 + 0x24d8 + iVar11);
    if (*(int *)(param_2 + 0x10) == 0) {
      fVar23 = *(float *)(iVar11 + 0x28dc);
    }
    else {
      fVar23 = *(float *)(iVar11 + 0x2b1c);
    }
    goto LAB_00089bab;
  case 0x15:
    if (*(int *)(param_2 + 0x10) == 0) {
      fVar23 = *(float *)(iVar11 + 0x28e0);
    }
    else {
      fVar23 = *(float *)(iVar11 + 0x2b20);
    }
    *param_3 = fVar23 * *(float *)(iVar3 * 0x80 + 0x24e0 + iVar11);
    if (*(int *)(param_2 + 0x10) == 0) {
      fVar23 = *(float *)(iVar11 + 0x28e4);
    }
    else {
      fVar23 = *(float *)(iVar11 + 0x2b24);
    }
    param_3[1] = fVar23 * *(float *)(*(int *)(param_2 + 0xc) * 0x80 + 0x24e4 + iVar11);
    if (*(int *)(param_2 + 0x10) == 0) {
      fVar23 = *(float *)(iVar11 + 0x28e8);
    }
    else {
      fVar23 = *(float *)(iVar11 + 0x2b28);
    }
    param_3[2] = fVar23 * *(float *)(*(int *)(param_2 + 0xc) * 0x80 + 0x24e8 + iVar11);
    if (*(int *)(param_2 + 0x10) == 0) {
      fVar23 = *(float *)(iVar11 + 0x28ec);
    }
    else {
      fVar23 = *(float *)(iVar11 + 0x2b2c);
    }
LAB_00089bab:
    param_3[3] = fVar23;
    break;
  case 0x16:
    *param_3 = *(float *)(iVar11 + 0x2de0);
    param_3[1] = *(float *)(iVar11 + 0x2de4);
    param_3[2] = *(float *)(iVar11 + 0x2de8);
    param_3[3] = *(float *)(iVar11 + 0x2dec);
    break;
  case 0x17:
    *param_3 = *(float *)(iVar11 + 0x2df0);
    param_3[1] = *(float *)(iVar11 + 0x2df4);
    param_3[2] = *(float *)(iVar11 + 0x2df8);
    param_3[3] = *(float *)(iVar11 + 0x2dfc);
    break;
  case 0x18:
    *param_3 = (float)*(double *)(iVar11 + 0x1830);
    param_3[1] = (float)*(double *)(iVar11 + 0x1838);
    param_3[2] = (float)(*(double *)(iVar11 + 0x1838) - *(double *)(iVar11 + 0x1830));
    param_3[3] = 1.0;
    break;
  case 0x19:
    *param_3 = *(float *)(iVar3 * 0x7c + 0x31c4 + iVar11);
    param_3[1] = *(float *)(*(int *)(param_2 + 0xc) * 0x7c + *(int *)(iVar10 + 0x10) + 0x31c8);
    param_3[2] = *(float *)(*(int *)(param_2 + 0xc) * 0x7c + *(int *)(iVar10 + 0x10) + 0x31cc);
    param_3[3] = *(float *)(*(int *)(param_2 + 0xc) * 0x7c + *(int *)(iVar10 + 0x10) + 0x31d0);
    break;
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1d:
    iVar15 = iVar15 + -0x1a;
    iVar11 = iVar11 + 0x1960 + iVar3 * 0x40;
    goto LAB_0008a24c;
  case 0x1e:
  case 0x1f:
  case 0x20:
  case 0x21:
    iVar15 = iVar15 + -0x1e;
    iVar11 = iVar11 + 0x1920;
    goto LAB_0008a24c;
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x25:
    iVar15 = iVar15 + -0x22;
    iVar11 = iVar11 + 0x1860;
    goto LAB_0008a24c;
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
    iVar15 = iVar15 + -0x26;
    iVar11 = iVar11 + 0x1c60 + iVar3 * 0x40;
    goto LAB_0008a24c;
  case 0x2e:
  case 0x2f:
  case 0x30:
  case 0x31:
    iVar15 = iVar15 + -0x2e;
    iVar11 = iVar11 + 0x1a60 + iVar3 * 0x40;
LAB_0008a24c:
    uVar16 = 0;
    do {
      while (-1 < (int)uVar16) {
        iVar10 = (int)uVar16 >> 2;
        if ((int)uVar16 < 0) goto LAB_00088e82;
LAB_00088e52:
        local_dc[uVar16 + 0x20] = *(float *)(iVar11 + ((uVar16 & 0x80000003) + iVar10 * 4) * 4);
        uVar16 = uVar16 + 1;
        if (uVar16 == 0x10) goto LAB_00088e9d;
      }
      iVar10 = (int)(uVar16 + 3) >> 2;
      if (-1 < (int)uVar16) goto LAB_00088e52;
LAB_00088e82:
      local_dc[uVar16 + 0x20] =
           *(float *)(iVar11 + (((uVar16 & 0x80000003) - 1 | 0xfffffffc) + 1 + iVar10 * 4) * 4);
      uVar16 = uVar16 + 1;
    } while (uVar16 != 0x10);
LAB_00088e9d:
    iVar11 = *(int *)(param_2 + 0x10);
    if ((iVar11 != 1) && (iVar11 != 3)) goto LAB_00088eb0;
    local_dc[0] = local_dc[0x20];
    local_dc[1] = local_dc[0x24];
    local_dc[2] = local_dc[0x28];
    local_dc[3] = local_dc[0x2c];
    local_dc[4] = 1.0;
    local_dc[7] = 0.0;
    local_dc[6] = 0.0;
    local_dc[5] = 0.0;
    local_dc[8] = local_dc[0x21];
    local_dc[9] = local_dc[0x25];
    local_dc[10] = local_dc[0x29];
    local_dc[0xb] = local_dc[0x2d];
    local_dc[0xd] = 1.0;
    local_dc[0xf] = 0.0;
    local_dc[0xe] = 0.0;
    local_dc[0xc] = 0.0;
    local_dc[0x10] = local_dc[0x22];
    local_dc[0x11] = local_dc[0x26];
    local_dc[0x12] = local_dc[0x2a];
    local_dc[0x13] = local_dc[0x2e];
    local_dc[0x16] = 1.0;
    local_dc[0x17] = 0.0;
    local_dc[0x15] = 0.0;
    local_dc[0x14] = 0.0;
    local_dc[0x18] = local_dc[0x23];
    local_dc[0x19] = local_dc[0x27];
    local_dc[0x1a] = local_dc[0x2b];
    local_dc[0x1b] = local_dc[0x2f];
    local_dc[0x1f] = 1.0;
    local_dc[0x1e] = 0.0;
    local_dc[0x1d] = 0.0;
    local_dc[0x1c] = 0.0;
    pfVar17 = local_dc + 0x18;
    pfVar19 = local_dc + 0x10;
    if ((float)((uint)local_dc[0x23] & DAT_001c63e0) <= (float)((uint)local_dc[0x22] & DAT_001c63e0)
       ) {
      pfVar17 = local_dc + 0x10;
      pfVar19 = local_dc + 0x18;
    }
    pfVar13 = local_dc + 8;
    fVar23 = *pfVar17;
    if ((float)((uint)*pfVar17 & DAT_001c63e0) <= (float)((uint)local_dc[0x21] & DAT_001c63e0)) {
      pfVar13 = pfVar17;
      pfVar17 = local_dc + 8;
      fVar23 = local_dc[0x21];
    }
    pfVar18 = pfVar17;
    local_118 = local_dc;
    if ((float)((uint)local_dc[0x20] & DAT_001c63e0) < (float)((uint)fVar23 & DAT_001c63e0)) {
      pfVar18 = local_dc;
      local_118 = pfVar17;
    }
    fVar23 = *local_118;
    if (fVar23 == 0.0) goto LAB_00088eb0;
    fVar21 = *pfVar18 / fVar23;
    fVar22 = *pfVar13 / fVar23;
    fVar23 = *pfVar19 / fVar23;
    fVar20 = local_118[1];
    pfVar18[1] = pfVar18[1] - fVar21 * fVar20;
    pfVar17 = pfVar13 + 1;
    pfVar13[1] = pfVar13[1] - fVar22 * fVar20;
    pfVar1 = pfVar19 + 1;
    pfVar19[1] = pfVar19[1] - fVar20 * fVar23;
    fVar20 = local_118[2];
    pfVar18[2] = pfVar18[2] - fVar21 * fVar20;
    pfVar13[2] = pfVar13[2] - fVar22 * fVar20;
    pfVar19[2] = pfVar19[2] - fVar20 * fVar23;
    fVar20 = local_118[3];
    pfVar18[3] = pfVar18[3] - fVar21 * fVar20;
    pfVar13[3] = pfVar13[3] - fVar22 * fVar20;
    pfVar19[3] = pfVar19[3] - fVar20 * fVar23;
    pfVar4 = local_118 + 4;
    fVar20 = local_118[4];
    if (fVar20 != 0.0) {
      pfVar18[4] = pfVar18[4] - fVar21 * fVar20;
      pfVar13[4] = pfVar13[4] - fVar22 * fVar20;
      pfVar19[4] = pfVar19[4] - fVar20 * fVar23;
    }
    pfVar5 = local_118 + 5;
    fVar20 = local_118[5];
    if (fVar20 != 0.0) {
      pfVar18[5] = pfVar18[5] - fVar21 * fVar20;
      pfVar13[5] = pfVar13[5] - fVar22 * fVar20;
      pfVar19[5] = pfVar19[5] - fVar20 * fVar23;
    }
    pfVar6 = local_118 + 6;
    fVar20 = local_118[6];
    if (fVar20 != 0.0) {
      pfVar18[6] = pfVar18[6] - fVar21 * fVar20;
      pfVar13[6] = pfVar13[6] - fVar22 * fVar20;
      pfVar19[6] = pfVar19[6] - fVar20 * fVar23;
    }
    pfVar7 = local_118 + 7;
    fVar20 = local_118[7];
    pfVar12 = pfVar13;
    if (fVar20 == 0.0) {
      fVar23 = *pfVar1;
      fVar20 = *pfVar17;
      if ((float)((uint)fVar20 & DAT_001c63e0) < (float)((uint)fVar23 & DAT_001c63e0)) {
LAB_00089293:
        pfVar12 = pfVar19;
        pfVar17 = pfVar1;
        pfVar19 = pfVar13;
        fVar20 = fVar23;
      }
    }
    else {
      pfVar18[7] = pfVar18[7] - fVar21 * fVar20;
      pfVar13[7] = pfVar13[7] - fVar22 * fVar20;
      pfVar19[7] = pfVar19[7] - fVar23 * fVar20;
      fVar23 = *pfVar1;
      fVar20 = *pfVar17;
      if ((float)((uint)fVar20 & DAT_001c63e0) < (float)((uint)fVar23 & DAT_001c63e0))
      goto LAB_00089293;
    }
    fVar23 = pfVar18[1];
    pfVar13 = pfVar12;
    local_114 = pfVar18 + 1;
    if ((float)((uint)fVar23 & DAT_001c63e0) < (float)((uint)fVar20 & DAT_001c63e0)) {
      fVar23 = *pfVar17;
      pfVar13 = pfVar18;
      pfVar18 = pfVar12;
      local_114 = pfVar17;
    }
    if (fVar23 != 0.0) {
      fVar21 = pfVar13[1] / fVar23;
      fVar23 = pfVar19[1] / fVar23;
      pfVar13[2] = pfVar13[2] - fVar21 * pfVar18[2];
      pfVar19[2] = pfVar19[2] - fVar23 * pfVar18[2];
      pfVar13[3] = pfVar13[3] - fVar21 * pfVar18[3];
      pfVar19[3] = pfVar19[3] - fVar23 * pfVar18[3];
      pfVar17 = pfVar18 + 4;
      fVar20 = pfVar18[4];
      if (fVar20 != 0.0) {
        pfVar13[4] = pfVar13[4] - fVar21 * fVar20;
        pfVar19[4] = pfVar19[4] - fVar20 * fVar23;
      }
      pfVar1 = pfVar18 + 5;
      fVar20 = pfVar18[5];
      if (fVar20 != 0.0) {
        pfVar13[5] = pfVar13[5] - fVar21 * fVar20;
        pfVar19[5] = pfVar19[5] - fVar20 * fVar23;
      }
      pfVar12 = pfVar18 + 6;
      fVar20 = pfVar18[6];
      if (fVar20 != 0.0) {
        pfVar13[6] = pfVar13[6] - fVar21 * fVar20;
        pfVar19[6] = pfVar19[6] - fVar20 * fVar23;
      }
      pfVar2 = pfVar18 + 7;
      fVar20 = pfVar18[7];
      if (fVar20 != 0.0) {
        pfVar13[7] = pfVar13[7] - fVar21 * fVar20;
        pfVar19[7] = pfVar19[7] - fVar23 * fVar20;
      }
      fVar23 = pfVar19[2];
      fVar20 = pfVar13[2];
      pfVar8 = pfVar13 + 2;
      pfVar14 = pfVar13;
      if ((float)((uint)fVar20 & DAT_001c63e0) < (float)((uint)fVar23 & DAT_001c63e0)) {
        pfVar8 = pfVar19 + 2;
        pfVar14 = pfVar19;
        pfVar19 = pfVar13;
        fVar20 = fVar23;
      }
      if (fVar20 == 0.0) {
        iVar11 = *(int *)(param_2 + 0x10);
        goto LAB_00088eb0;
      }
      fVar20 = pfVar19[2] / fVar20;
      fVar23 = pfVar19[3] - fVar20 * pfVar14[3];
      pfVar19[3] = fVar23;
      pfVar19[4] = pfVar19[4] - fVar20 * pfVar14[4];
      pfVar19[5] = pfVar19[5] - fVar20 * pfVar14[5];
      pfVar19[6] = pfVar19[6] - fVar20 * pfVar14[6];
      pfVar19[7] = pfVar19[7] - fVar20 * pfVar14[7];
      if (fVar23 != 0.0) {
        fVar23 = FLOAT_001c5ba4 / fVar23;
        pfVar19[4] = fVar23 * pfVar19[4];
        pfVar19[5] = fVar23 * pfVar19[5];
        pfVar19[6] = fVar23 * pfVar19[6];
        pfVar19[7] = fVar23 * pfVar19[7];
        fVar23 = pfVar14[3];
        fVar20 = FLOAT_001c5ba4 / *pfVar8;
        pfVar14[4] = (pfVar14[4] - fVar23 * pfVar19[4]) * fVar20;
        pfVar14[5] = (pfVar14[5] - fVar23 * pfVar19[5]) * fVar20;
        pfVar14[6] = (pfVar14[6] - fVar23 * pfVar19[6]) * fVar20;
        pfVar14[7] = (pfVar14[7] - fVar23 * pfVar19[7]) * fVar20;
        fVar23 = pfVar18[3];
        *pfVar17 = *pfVar17 - fVar23 * pfVar19[4];
        *pfVar1 = *pfVar1 - fVar23 * pfVar19[5];
        *pfVar12 = *pfVar12 - fVar23 * pfVar19[6];
        *pfVar2 = *pfVar2 - fVar23 * pfVar19[7];
        fVar23 = local_118[3];
        *pfVar4 = *pfVar4 - fVar23 * pfVar19[4];
        *pfVar5 = *pfVar5 - fVar23 * pfVar19[5];
        *pfVar6 = *pfVar6 - fVar23 * pfVar19[6];
        *pfVar7 = *pfVar7 - fVar23 * pfVar19[7];
        fVar23 = pfVar18[2];
        fVar20 = FLOAT_001c5ba4 / *local_114;
        *pfVar17 = (*pfVar17 - fVar23 * pfVar14[4]) * fVar20;
        *pfVar1 = (*pfVar1 - fVar23 * pfVar14[5]) * fVar20;
        *pfVar12 = (*pfVar12 - fVar23 * pfVar14[6]) * fVar20;
        *pfVar2 = (*pfVar2 - fVar23 * pfVar14[7]) * fVar20;
        fVar23 = local_118[2];
        *pfVar4 = *pfVar4 - fVar23 * pfVar14[4];
        *pfVar5 = *pfVar5 - fVar23 * pfVar14[5];
        *pfVar6 = *pfVar6 - fVar23 * pfVar14[6];
        *pfVar7 = *pfVar7 - fVar23 * pfVar14[7];
        fVar23 = local_118[1];
        fVar20 = FLOAT_001c5ba4 / *local_118;
        *pfVar4 = (*pfVar4 - fVar23 * *pfVar17) * fVar20;
        *pfVar5 = (*pfVar5 - fVar23 * *pfVar1) * fVar20;
        *pfVar6 = (*pfVar6 - fVar23 * *pfVar12) * fVar20;
        local_dc[0x2c] = (*pfVar7 - fVar23 * *pfVar2) * fVar20;
        *pfVar7 = local_dc[0x2c];
        local_dc[0x20] = *pfVar4;
        local_dc[0x24] = *pfVar5;
        local_dc[0x28] = *pfVar6;
        local_dc[0x21] = *pfVar17;
        local_dc[0x25] = *pfVar1;
        local_dc[0x29] = *pfVar12;
        local_dc[0x2d] = *pfVar2;
        local_dc[0x22] = pfVar14[4];
        local_dc[0x26] = pfVar14[5];
        local_dc[0x2a] = pfVar14[6];
        local_dc[0x2e] = pfVar14[7];
        local_dc[0x23] = pfVar19[4];
        local_dc[0x27] = pfVar19[5];
        local_dc[0x2b] = pfVar19[6];
        local_dc[0x2f] = pfVar19[7];
        iVar11 = *(int *)(param_2 + 0x10);
        goto LAB_00088eb0;
      }
    }
    iVar11 = *(int *)(param_2 + 0x10);
LAB_00088eb0:
    if (-1 < iVar11) {
      if (iVar11 < 2) {
        pfVar17 = local_dc + iVar15 + 0x20;
        iVar11 = 1;
        do {
          param_3[iVar11 + -1] = *pfVar17;
          iVar11 = iVar11 + 1;
          pfVar17 = pfVar17 + 4;
        } while (iVar11 != 5);
      }
      else if (iVar11 < 4) {
        pfVar17 = local_dc + iVar15 * 4 + 0x20;
        iVar11 = 1;
        do {
          param_3[iVar11 + -1] = *pfVar17;
          iVar11 = iVar11 + 1;
          pfVar17 = pfVar17 + 1;
        } while (iVar11 != 5);
        return;
      }
    }
    return;
  case 0x32:
    puVar9 = (undefined8 *)(iVar11 + 0x1010 + iVar3 * 0x10);
    *(undefined8 *)param_3 = *puVar9;
    *(undefined8 *)(param_3 + 2) = puVar9[1];
    break;
  case 0x33:
    puVar9 = (undefined8 *)
             (iVar3 * 0x10 + *(int *)(**(int **)(*(int *)(iVar10 + 0x18) + 400) + 0x18));
    *(undefined8 *)param_3 = *puVar9;
    *(undefined8 *)(param_3 + 2) = puVar9[1];
  }
  return;
}

/* FUN_0008a49a @ 0x8a49a (384 bytes) */
int FUN_0008a49a(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = param_1 + 0x11d0;
  iVar1 = *(int *)(param_1 + 0x112c);
  *(undefined4 *)(param_1 + 0x126c) = 1;
  *(undefined4 *)(param_1 + 0x1220) = 2;
  (**(code **)(param_1 + 0x1274))(param_1);
  *(undefined1 *)(param_1 + 0x11d3) = 0;
  *(undefined4 *)(param_1 + 0x1228) = 0;
  if (*(char *)(param_1 + 0x13b1) != '\0') {
    iVar3 = 0;
    do {
      *(undefined4 *)(iVar4 + 0x5c) = 0;
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 4;
    } while (iVar3 < (int)(uint)*(byte *)(param_1 + 0x13b1));
  }
  FUN_0009f272(param_1,*(int *)(iVar1 + 8) + *(int *)(param_1 + 0x126c) * 0x18);
  *(undefined4 *)(*(int *)(iVar1 + 8) + 4 + *(int *)(param_1 + 0x126c) * 0x18) = 0x8804;
  *(undefined4 *)(*(int *)(iVar1 + 8) + *(int *)(param_1 + 0x126c) * 0x18) = 0;
  iVar4 = *(int *)(param_1 + 0x126c);
  iVar3 = *(int *)(iVar1 + 8);
  uVar2 = (**(code **)(param_1 + 0xc))(0x78);
  *(undefined4 *)(iVar3 + iVar4 * 0x18 + 0x14) = uVar2;
  ((int (*)())FUN_00088843)(param_1,*(undefined4 *)
                        (*(int *)(iVar1 + 8) + 0x14 + *(int *)(param_1 + 0x126c) * 0x18));
  FUN_0009f272(param_1,*(int *)(iVar1 + 8) + *(int *)(param_1 + 0x1220) * 0x18);
  *(undefined4 *)(*(int *)(iVar1 + 8) + 4 + *(int *)(param_1 + 0x1220) * 0x18) = 0x8804;
  *(undefined4 *)(*(int *)(iVar1 + 8) + *(int *)(param_1 + 0x1220) * 0x18) = 0;
  iVar4 = *(int *)(param_1 + 0x1220);
  iVar3 = *(int *)(iVar1 + 8);
  uVar2 = (**(code **)(param_1 + 0xc))(0x78);
  *(undefined4 *)(iVar3 + iVar4 * 0x18 + 0x14) = uVar2;
  ((int (*)())FUN_00088843)(param_1,*(undefined4 *)
                        (*(int *)(iVar1 + 8) + 0x14 + *(int *)(param_1 + 0x1220) * 0x18));
  return;
}

/* FUN_0008a61a @ 0x8a61a (101 bytes) */
int FUN_0008a61a(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  void *pvVar2;
  void *pvVar3;
  
  iVar1 = *(int *)(param_1 + 0x112c);
  pvVar2 = *(void **)(param_2 + 0x70);
  pvVar3 = (void *)(**(code **)(param_1 + 0x10))(*(undefined4 *)(iVar1 + 0x10),4);
  *(void **)(param_2 + 0x70) = pvVar3;
  _memcpy(pvVar3,pvVar2,*(int *)(iVar1 + 0x10) * 4 - 4);
                    
                    
  (**(code **)(param_1 + 0x18))();
  return;
}

/* FUN_0008a67f @ 0x8a67f (130 bytes) */
int FUN_0008a67f(param_1)
  int param_1;
{
  *(undefined1 *)(param_1 + 0x11d0) = 1;
  *(int *)(param_1 + 0x1270) = *(int *)(param_1 + 0x126c);
  *(undefined4 *)(param_1 + 0x121c) =
       *(undefined4 *)
        (*(int *)(*(int *)(param_1 + 0x112c) + 8) + 0x14 + *(int *)(param_1 + 0x126c) * 0x18);
  ((int (*)())FUN_0008721d)("!!ARBfp1.0\nEND\n");
  ((int (*)())FUN_000887e9)(param_1,*(undefined4 *)(param_1 + 0x126c));
  return;
}

/* FUN_0008a701 @ 0x8a701 (808 bytes) */
int FUN_0008a701(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  int *param_4;
{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  bool bVar9;
  float fVar10;
  int iVar11;
  undefined4 *puVar12;
  undefined4 uVar13;
  float fVar14;
  float fVar15;
  int local_c0;
  undefined1 local_a8 [152];
  
  iVar3 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  iVar11 = (**(code **)(param_1 + 0x2758))(param_1,10000);
  *(int *)(param_1 + 0x274c) = iVar11;
  (**(code **)(param_1 + 0x275c))(param_1,iVar11);
  iVar4 = *(int *)(param_1 + 4);
  if (((((*(uint *)(iVar4 + 0x154) & 0x700000) == 0) || (*param_4 != 0)) || (param_4[1] != 0)) ||
     ((param_4[2] != *(int *)(iVar4 + 0x15c) || (param_4[3] != *(int *)(iVar4 + 0x160))))) {
    bVar9 = false;
    local_c0 = 0;
  }
  else {
    FUN_000a4262(param_1,param_2);
    local_c0 = *(int *)(param_1 + 0x274c);
    bVar9 = true;
  }
  FUN_000827ac(param_1,1,0,0,local_a8);
  puVar12 = (undefined4 *)
            (**(code **)(param_1 + 0x2758))
                      (param_1,(-(*(char *)(param_1 + 0x2802) == '\0') & 2U) + 0x23);
  *(undefined4 **)(param_1 + 0x274c) = puVar12;
  if (*(char *)(param_1 + 0x2802) == '\0') {
    *puVar12 = 0x5c8;
    puVar12[1] = 0x10000000;
    *(undefined1 *)(param_1 + 0x2802) = 1;
  }
  uVar13 = (**(code **)(param_1 + 0x2758))(param_1,0x23);
  *(undefined4 *)(param_1 + 0x274c) = uVar13;
  puVar12 = (undefined4 *)FUN_0007edb0(param_1,uVar13);
  if (bVar9) {
    *(int *)(iVar11 + 8) = (int)puVar12 - iVar11 >> 2;
  }
  fVar10 = FLOAT_001c5bd4;
  uVar13 = *(undefined4 *)(iVar3 + 0x2dac);
  uVar1 = *(undefined4 *)(iVar3 + 0x2da8);
  uVar2 = *(undefined4 *)(iVar3 + 0x2da4);
  uVar5 = *(undefined4 *)(iVar3 + 0x2da0);
  iVar3 = param_4[2];
  iVar4 = param_4[3];
  iVar6 = *param_4;
  iVar7 = param_4[1];
  uVar8 = *(uint *)(param_1 + 8);
  fVar14 = *(float *)(param_1 + 0x2818) * FLOAT_001c5bd4;
  fVar15 = *(float *)(param_1 + 0x2814) * FLOAT_001c5bd4;
  *puVar12 = 0x1087;
  puVar12[1] = (int)(fVar14 * (float)uVar8 * ((float)iVar4 - (float)iVar7)) & 0xffffU |
               (int)((float)uVar8 * fVar15 * ((float)iVar3 - (float)iVar6)) << 0x10;
  puVar12[2] = 0x82c;
  puVar12[3] = *(undefined4 *)(param_1 + 0x1b84);
  puVar12[4] = 0xc0083500;
  puVar12[5] = ((unsigned char *)0x00010031);
  puVar12[6] = ((float)iVar3 + (float)iVar6) * fVar10;
  puVar12[7] = ((float)iVar4 + (float)iVar7) * fVar10;
  puVar12[8] = 0;
  puVar12[9] = 0x3f800000;
  puVar12[10] = uVar5;
  puVar12[0xb] = uVar2;
  puVar12[0xc] = uVar1;
  puVar12[0xd] = uVar13;
  puVar12[0xe] = 0x1087;
  puVar12[0xf] = *(undefined4 *)(param_1 + 0x1ccc);
  *(undefined4 **)(param_1 + 0x274c) = puVar12 + 0x10;
  (**(code **)(param_1 + 0x275c))(param_1,puVar12 + 0x10);
  FUN_0009b2d9(param_1);
  FUN_00082e73(param_1,local_a8);
  if (bVar9) {
    *(int *)(iVar11 + 4) = *(int *)(param_1 + 0x274c) - local_c0 >> 2;
  }
  return;
}

/* FUN_0008aa29 @ 0x8aa29 (232 bytes) */
int FUN_0008aa29(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  if (*(int *)(*(int *)(*(int *)(param_1 + 4) + 0x10) + 0x3e28) != 0) {
    FUN_000824aa(param_1);
  }
  iVar1 = *(int *)(param_1 + 0x1b7c);
  *(undefined1 *)(param_1 + 0x23ec) = 1;
  if (*(char *)(param_1 + 0x1868) == '\0') {
    if ((*(byte *)(param_1 + 0x45) & 8) != 0) {
      FUN_00062f8b(param_1);
      FUN_0009b26d(param_1);
      *(bool *)(param_1 + 0x23ec) = iVar1 != *(int *)(param_1 + 0x1b7c);
      return;
    }
  }
  else if ((*(byte *)(param_1 + 0x45) & 8) != 0) {
    iVar2 = **(int **)(**(int **)(param_1 + 0x1168) + *(int *)(param_1 + 0x118c) * 4);
    (**(code **)(param_1 + 0x1294))(param_1,iVar2 + 0x13c,*(undefined4 *)(iVar2 + 0x130));
    FUN_0009b26d(param_1);
    *(bool *)(param_1 + 0x23ec) = iVar1 != *(int *)(param_1 + 0x1b7c);
    return;
  }
  FUN_0009b26d(param_1);
  *(bool *)(param_1 + 0x23ec) = iVar1 != *(int *)(param_1 + 0x1b7c);
  return;
}

/* FUN_0008ab11 @ 0x8ab11 (1370 bytes) */
int FUN_0008ab11(param_1)
  int param_1;
{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  uint local_1c;
  uint local_14;
  int local_10;
  
  iVar3 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  _memset((void *)(param_1 + 0x19c),-1,0x68);
  FUN_0004ea07(param_1,0,3,0,0,0,0,0);
  *(undefined4 *)(param_1 + 0x19c) = 0;
  if ((*(byte *)(param_1 + 0x44) & 1) == 0) {
    if (((*(byte *)(param_1 + 0x8c) >> 5 | *(byte *)(param_1 + 0x8d) >> 3 |
         *(byte *)(param_1 + 0x8c) >> 4) & 1) == 0) {
      iVar6 = 1;
      uVar5 = 1;
      local_10 = 2;
    }
    else {
      FUN_0004ea07(param_1,1,3,0,1,0,0,0);
      *(undefined4 *)(param_1 + 0x1a0) = 1;
      iVar6 = 2;
      uVar5 = 2;
      local_10 = 3;
    }
    FUN_0004ea07(param_1,uVar5,3,0,uVar5,0,0,0);
    *(undefined4 *)(param_1 + 0x1a8) = uVar5;
    bVar2 = *(byte *)(param_1 + 0x45);
    if ((bVar2 & 0x85) != 0) {
      FUN_0004ea07(param_1,local_10,3,0,local_10,0,0,0);
      *(int *)(param_1 + 0x1ac) = local_10;
      local_10 = iVar6 + 2;
      bVar2 = *(byte *)(param_1 + 0x45);
    }
  }
  else {
    FUN_0004ea07(param_1,1,3,0,1,0,0,0);
    *(undefined4 *)(param_1 + 0x1a0) = 1;
    if (*(char *)(iVar3 + 0x2d4b) == '\0') {
      local_10 = 2;
      bVar2 = *(byte *)(param_1 + 0x45);
    }
    else {
      FUN_0004ea07(param_1,2,3,0,2,0,0,0);
      *(undefined4 *)(param_1 + 0x1a8) = 2;
      local_10 = 3;
      bVar2 = *(byte *)(param_1 + 0x45);
    }
  }
  if ((bVar2 & 0x40) == 0) {
    uVar4 = (uint)*(byte *)(param_1 + 0x13b0);
    if ((uint)*(byte *)(param_1 + 0x2b) <= (uint)*(byte *)(param_1 + 0x13b0)) {
      uVar4 = (uint)*(byte *)(param_1 + 0x2b);
    }
    if (uVar4 != 0) {
      local_14 = 0;
      iVar6 = param_1;
      iVar7 = param_1;
      do {
        if ((*(char *)(iVar6 + 0x1438) != '\0') && (*(int *)(iVar7 + 0x13f8) != 0)) {
          FUN_0004ea07(param_1,local_10,3,0,local_10,0,0,0);
          *(int *)(iVar7 + 0x1c8) = local_10;
          local_10 = local_10 + 1;
        }
        local_14 = local_14 + 1;
        iVar6 = iVar6 + 1;
        iVar7 = iVar7 + 4;
      } while (local_14 != uVar4);
    }
  }
  else {
    if ((*(byte *)(param_1 + 0x46) & 4) == 0) {
      bVar2 = *(byte *)(param_1 + 0x1135);
    }
    else {
      bVar2 = *(byte *)(param_1 + 0x11d3);
    }
    local_1c = (uint)bVar2;
    if (*(char *)(param_1 + 0x13b0) != '\0') {
      iVar7 = 0;
      iVar6 = param_1;
      do {
        while ((local_1c & 1 << ((byte)iVar7 & 0x1f)) == 0) {
          iVar7 = iVar7 + 1;
          iVar6 = iVar6 + 4;
          if ((int)(uint)*(byte *)(param_1 + 0x13b0) <= iVar7) goto LAB_0008acdf;
        }
        FUN_0004ea07(param_1,local_10,3,0,local_10,0,0,0);
        *(int *)(iVar6 + 0x1c8) = local_10;
        local_10 = local_10 + 1;
        iVar7 = iVar7 + 1;
        iVar6 = iVar6 + 4;
      } while (iVar7 < (int)(uint)*(byte *)(param_1 + 0x13b0));
    }
  }
LAB_0008acdf:
  if (((*(uint *)(param_1 + 0x44) & 0x100080) != 0) && (*(short *)(iVar3 + 0x2e06) == -0x7baf)) {
    FUN_0004ea07(param_1,local_10,3,0,local_10,0,0,0);
    *(int *)(param_1 + 0x1ec) = local_10;
    *(undefined4 *)(param_1 + 0x1f0) = 0;
    local_10 = local_10 + 1;
  }
  if (*(char *)(iVar3 + 0x4301) != '\0') {
    FUN_0004ea07(param_1,local_10,3,0,local_10,0,0,0);
    *(int *)(param_1 + 0x1f8) = local_10;
    local_10 = local_10 + 1;
  }
  iVar3 = (int)(local_10 - 1U) >> 1;
  if ((local_10 - 1U & 1) == 0) {
    pbVar1 = (byte *)(param_1 + 0x1be5 + iVar3 * 4);
    *pbVar1 = *pbVar1 | 0x20;
  }
  else {
    pbVar1 = (byte *)(param_1 + 0x1be7 + iVar3 * 4);
    *pbVar1 = *pbVar1 | 0x20;
  }
  *(byte *)(param_1 + 0x1ca4) = *(byte *)(param_1 + 0x1ca4) & 0x80 | (byte)(local_10 << 2) & 0x7f;
  *(int *)(param_1 + 0x2430) = local_10;
  *(int *)(param_1 + 0x2438) = local_10;
  *(int *)(param_1 + 0x243c) = local_10;
  *(char *)(param_1 + 0x131) = (char)local_10;
  *(undefined1 *)(param_1 + 0x2435) = 1;
  return;
}

/* FUN_0008b06b @ 0x8b06b (901 bytes) */
int FUN_0008b06b(param_1)
  int param_1;
{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  byte bVar6;
  int iVar7;
  int iVar8;
  uint local_1c;
  uint local_18;
  uint local_10;
  
  iVar7 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  iVar2 = *(int *)(param_1 + 0x1b9c);
  iVar3 = *(int *)(param_1 + 0x1ba0);
  iVar4 = *(int *)(param_1 + 0x1ca0);
  if ((*(char *)(param_1 + 0x1868) != '\0') && (*(char *)(param_1 + 0x124) != '\0')) {
    FUN_0004c81a();
    return;
  }
  *(undefined4 *)(param_1 + 0x1ca0) = 1;
  if ((*(byte *)(param_1 + 0x44) & 1) == 0) {
    if (((*(byte *)(param_1 + 0x8c) >> 5 | *(byte *)(param_1 + 0x8d) >> 3 |
         *(byte *)(param_1 + 0x8c) >> 4) & 1) != 0) {
      *(undefined4 *)(param_1 + 0x1ca0) = 3;
    }
    uVar5 = *(uint *)(param_1 + 0x1ca0);
    *(uint *)(param_1 + 0x1ca0) = uVar5 | 4;
    bVar6 = *(byte *)(param_1 + 0x45);
    if ((bVar6 & 0x85) != 0) {
      *(uint *)(param_1 + 0x1ca0) = uVar5 | 0xc;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x1ca0) = 3;
    if (*(char *)(iVar7 + 0x2d4b) == '\0') {
      bVar6 = *(byte *)(param_1 + 0x45);
    }
    else {
      *(undefined4 *)(param_1 + 0x1ca0) = 7;
      bVar6 = *(byte *)(param_1 + 0x45);
    }
  }
  if (((*(uint *)(param_1 + 0x44) & 0x100080) != 0) && (*(short *)(iVar7 + 0x2e06) == -0x7baf)) {
    *(uint *)(param_1 + 0x1ca0) = *(uint *)(param_1 + 0x1ca0) | 0x40000;
  }
  if (*(char *)(iVar7 + 0x4301) != '\0') {
    *(uint *)(param_1 + 0x1ca0) = *(uint *)(param_1 + 0x1ca0) | 0x80000;
  }
  *(undefined4 *)(param_1 + 0x1b9c) = 3;
  *(undefined4 *)(param_1 + 0x1ba0) = 0;
  if ((*(byte *)(param_1 + 0x44) & 1) == 0) {
    bVar1 = *(byte *)(param_1 + 0x45);
    if (((bVar1 >> 2 | bVar1) & 1) != 0 || (char)bVar1 < '\0') {
      *(byte *)(param_1 + 0x1b9c) = *(byte *)(param_1 + 0x1b9c) | 4;
    }
  }
  else {
    if (*(short *)(iVar7 + 0x2d48) == -0x7e06) {
      *(byte *)(param_1 + 0x1b9c) = *(byte *)(param_1 + 0x1b9c) | 4;
    }
    if (*(char *)(iVar7 + 0x2d4c) != '\0') {
      *(byte *)(param_1 + 0x1b9c) = *(byte *)(param_1 + 0x1b9c) | 0x1c;
    }
  }
  if ((*(byte *)(param_1 + 0xe8) & 1) != 0) {
    *(byte *)(param_1 + 0x1b9e) = *(byte *)(param_1 + 0x1b9e) | 1;
  }
  if (((char)*(byte *)(param_1 + 0x44) < '\0') && (*(char *)(param_1 + 0x121) == '\0')) {
    *(byte *)(param_1 + 0x1b9c) = *(byte *)(param_1 + 0x1b9c) | 4;
  }
  if ((bVar6 & 0x40) == 0) {
    bVar6 = *(byte *)(param_1 + 0x2b);
    if (*(byte *)(param_1 + 0x13b0) < bVar6) {
      bVar6 = *(byte *)(param_1 + 0x13b0);
    }
    local_18 = (uint)bVar6;
    if (local_18 != 0) {
      local_10 = 0;
      bVar6 = 0;
      iVar7 = param_1;
      iVar8 = param_1;
      do {
        if ((*(char *)(iVar7 + 0x1438) != '\0') && (*(int *)(iVar8 + 0x13f8) != 0)) {
          *(uint *)(param_1 + 0x1ca0) =
               *(uint *)(param_1 + 0x1ca0) | 1 << ((char)local_10 + 10U & 0x1f);
          *(uint *)(param_1 + 0x1ba0) = *(uint *)(param_1 + 0x1ba0) | 4 << (bVar6 & 0x1f);
        }
        local_10 = local_10 + 1;
        iVar7 = iVar7 + 1;
        bVar6 = bVar6 + 3;
        iVar8 = iVar8 + 4;
      } while (local_10 != local_18);
    }
  }
  else {
    bVar6 = *(byte *)(param_1 + 0x46);
    if ((bVar6 & 4) == 0) {
      local_1c = (uint)*(byte *)(param_1 + 0x1135);
    }
    else {
      local_1c = (uint)*(byte *)(param_1 + 0x11d3);
      if ((bVar6 & 0x10) != 0) {
        *(uint *)(param_1 + 0x1ba0) =
             *(uint *)(param_1 + 0x1ba0) | 4 << (*(char *)(param_1 + 0x11d1) * '\x03' & 0x1fU);
      }
      if ((bVar6 & 0x20) != 0) {
        *(uint *)(param_1 + 0x1ba0) =
             *(uint *)(param_1 + 0x1ba0) | 4 << (*(char *)(param_1 + 0x11d2) * '\x03' & 0x1fU);
      }
    }
    if (*(char *)(param_1 + 0x13b0) != '\0') {
      iVar7 = 0;
      bVar6 = 0;
      do {
        if ((local_1c & 1 << ((byte)iVar7 & 0x1f)) != 0) {
          *(uint *)(param_1 + 0x1ca0) = *(uint *)(param_1 + 0x1ca0) | 1 << ((byte)iVar7 + 10 & 0x1f)
          ;
          *(uint *)(param_1 + 0x1ba0) = *(uint *)(param_1 + 0x1ba0) | 4 << (bVar6 & 0x1f);
        }
        iVar7 = iVar7 + 1;
        bVar6 = bVar6 + 3;
      } while (iVar7 < (int)(uint)*(byte *)(param_1 + 0x13b0));
    }
  }
  if ((((iVar2 != *(int *)(param_1 + 0x1b9c)) || (iVar3 != *(int *)(param_1 + 0x1ba0))) ||
      (iVar4 != *(int *)(param_1 + 0x1ca0))) || (*(char *)(param_1 + 299) != '\0')) {
    *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x40000;
    ((int (*)())FUN_0008ab11)(param_1);
    (**(code **)(param_1 + 0x1334))(param_1,1);
    *(undefined1 *)(param_1 + 299) = 0;
  }
  return;
}

/* FUN_0008b3f0 @ 0x8b3f0 (900 bytes) */
int FUN_0008b3f0(param_1)
  int param_1;
{
  byte bVar1;
  uint uVar2;
  
  if (*(char *)(param_1 + 0x1868) == '\0') {
LAB_0008b41f:
    bVar1 = *(byte *)(param_1 + 0x1808);
  }
  else {
    if ((*(byte *)(param_1 + 0x45) & 8) == 0) {
      *(code **)(param_1 + 0x12b4) = FUN_0008b06b;
      goto LAB_0008b41f;
    }
    *(undefined **)(param_1 + 0x12b4) = PTR_LAB_002132e5;
    bVar1 = *(byte *)(param_1 + 0x1808);
  }
  if ((bVar1 & 4) != 0) {
    FUN_000a2d65(param_1);
  }
  uVar2 = *(uint *)(param_1 + 0x38);
  if (uVar2 == 0) goto LAB_0008b48d;
  if ((uVar2 & 4) == 0) {
    if ((uVar2 & 2) == 0) goto LAB_0008b443;
LAB_0008b5e5:
    FUN_0004d7a0(param_1);
    uVar2 = *(uint *)(param_1 + 0x38);
    if ((uVar2 & 8) != 0) goto LAB_0008b5f8;
LAB_0008b44b:
    if ((uVar2 & 0x400) == 0) goto LAB_0008b454;
LAB_0008b60c:
    FUN_00050f9f(param_1);
    uVar2 = *(uint *)(param_1 + 0x38);
    if ((uVar2 & 0x100) != 0) goto LAB_0008b620;
LAB_0008b45d:
    if ((uVar2 & 0x800) == 0) goto LAB_0008b466;
LAB_0008b6f8:
    FUN_0009af19(param_1);
    uVar2 = *(uint *)(param_1 + 0x38);
    if ((uVar2 & 0x4000) != 0) goto LAB_0008b70c;
LAB_0008b46f:
    if ((uVar2 & 0x2200) == 0) goto LAB_0008b478;
LAB_0008b656:
    FUN_0004cade(param_1);
    uVar2 = *(uint *)(param_1 + 0x38);
    bVar1 = *(byte *)(param_1 + 0x8c);
  }
  else {
    FUN_0004d6b4(param_1);
    uVar2 = *(uint *)(param_1 + 0x38);
    if ((uVar2 & 2) != 0) goto LAB_0008b5e5;
LAB_0008b443:
    if ((uVar2 & 8) == 0) goto LAB_0008b44b;
LAB_0008b5f8:
    FUN_0004d918(param_1);
    uVar2 = *(uint *)(param_1 + 0x38);
    if ((uVar2 & 0x400) != 0) goto LAB_0008b60c;
LAB_0008b454:
    if ((uVar2 & 0x100) == 0) goto LAB_0008b45d;
LAB_0008b620:
    FUN_0004ddf2(param_1);
    FUN_0009ae39(param_1);
    uVar2 = *(uint *)(param_1 + 0x38);
    if ((uVar2 & 0x800) != 0) goto LAB_0008b6f8;
LAB_0008b466:
    if ((uVar2 & 0x4000) == 0) goto LAB_0008b46f;
LAB_0008b70c:
    FUN_0004dbcb(param_1);
    uVar2 = *(uint *)(param_1 + 0x38);
    if ((uVar2 & 0x2200) != 0) goto LAB_0008b656;
LAB_0008b478:
    bVar1 = *(byte *)(param_1 + 0x8c);
  }
  if ((bVar1 & 2) == 0) {
    if ((uVar2 & 0x20000) != 0) {
      FUN_0008242b(param_1);
      uVar2 = *(uint *)(param_1 + 0x38);
    }
    if ((uVar2 & 0x20) != 0) {
      FUN_000baf88(param_1);
      uVar2 = *(uint *)(param_1 + 0x38);
    }
    if ((uVar2 & 0x1000) != 0) {
      if (*(char *)(param_1 + 0x1868) == '\0') {
        FUN_00062d7a(param_1);
      }
      else {
        (**(code **)(param_1 + 0x11cc))(param_1);
      }
    }
  }
  else if ((uVar2 & 0x20) != 0) {
    FUN_0004c212(param_1);
  }
LAB_0008b48d:
  uVar2 = *(uint *)(param_1 + 0x3c);
  if (uVar2 != 0) {
    if ((uVar2 & 1) != 0) {
      FUN_0004c6b6(param_1);
      uVar2 = *(uint *)(param_1 + 0x3c);
    }
    if ((uVar2 & 2) != 0) {
      FUN_0004e04d(param_1);
      uVar2 = *(uint *)(param_1 + 0x3c);
    }
    if ((uVar2 & 8) != 0) {
      FUN_000502a2(param_1);
      uVar2 = *(uint *)(param_1 + 0x3c);
    }
    if ((uVar2 & 0x10) != 0) {
      FUN_0004ed7b(param_1);
      uVar2 = *(uint *)(param_1 + 0x3c);
    }
    if ((uVar2 & 0x20) != 0) {
      FUN_0004fe29(param_1);
      uVar2 = *(uint *)(param_1 + 0x3c);
    }
    if ((uVar2 & 0x40) != 0) {
      FUN_0004ef3c(param_1);
      uVar2 = *(uint *)(param_1 + 0x3c);
    }
    if ((uVar2 & 0x400) != 0) {
      FUN_0004c845(param_1);
      uVar2 = *(uint *)(param_1 + 0x3c);
    }
    if ((uVar2 & 0x1000) != 0) {
      FUN_000a4461(param_1);
    }
  }
  if ((*(byte *)(param_1 + 0x45) & 8) == 0) {
    if ((*(byte *)(param_1 + 0x8c) & 2) == 0) {
      if (((*(uint *)(param_1 + 0x38) & 0x4b928) == 0) && (*(short *)(param_1 + 0x34) == 0)) {
        if (*(char *)(param_1 + 299) != '\0') {
          ((int (*)())FUN_0008b06b)(param_1);
        }
      }
      else {
        ((int (*)())FUN_0008b06b)(param_1);
      }
    }
    else {
      FUN_0004c81a(param_1);
    }
  }
  FUN_0004bd9c(param_1);
  FUN_00051128(param_1);
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined1 *)(param_1 + 0x29) = 0;
  *(undefined2 *)(param_1 + 0x32) = 0;
  *(undefined2 *)(param_1 + 0x34) = 0;
  *(undefined1 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined1 *)(param_1 + 0x2d) = 0;
  *(undefined1 *)(param_1 + 0x2e) = 0;
  *(undefined4 *)(param_1 + 0x180c) = 0;
  *(undefined4 *)(param_1 + 0x1810) = 0;
  return;
}

/* FUN_0008b774 @ 0x8b774 (244 bytes) */
int FUN_0008b774(param_1)
  int param_1;
{
  undefined4 *puVar1;
  int iVar2;
  byte bVar3;
  
  if ((*(byte *)(param_1 + 0x8c) & 2) == 0) {
    *(byte *)(param_1 + 0x1b84) = *(byte *)(param_1 + 0x1b84) | 0x3f;
    *(byte *)(param_1 + 0x1b85) = *(byte *)(param_1 + 0x1b85) & 0xfc | 4;
    *(byte *)(param_1 + 0x1b76) = *(byte *)(param_1 + 0x1b76) & 0xfe;
  }
  else {
    bVar3 = *(byte *)(param_1 + 0x1b84) & 0xc0;
    *(byte *)(param_1 + 0x1b84) = bVar3;
    *(byte *)(param_1 + 0x1b85) = *(byte *)(param_1 + 0x1b85) & 0xfb | 3;
    if ((FLOAT_001c5ba4 != *(float *)(param_1 + 0x2814)) ||
       (FLOAT_001c5ba4 != *(float *)(param_1 + 0x2818))) {
      *(byte *)(param_1 + 0x1b84) = bVar3 | 5;
    }
    *(byte *)(param_1 + 0x1b76) = *(byte *)(param_1 + 0x1b76) | 1;
  }
  puVar1 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,4);
  *(undefined4 **)(param_1 + 0x274c) = puVar1;
  *puVar1 = 0x82c;
  *(undefined4 *)(*(int *)(param_1 + 0x274c) + 4) = *(undefined4 *)(param_1 + 0x1b84);
  *(undefined4 *)(*(int *)(param_1 + 0x274c) + 8) = 0x887;
  *(undefined4 *)(*(int *)(param_1 + 0x274c) + 0xc) = *(undefined4 *)(param_1 + 0x1b74);
  iVar2 = *(int *)(param_1 + 0x274c) + 0x10;
  *(int *)(param_1 + 0x274c) = iVar2;
  (**(code **)(param_1 + 0x275c))(param_1,iVar2);
  return;
}

/* FUN_0008b868 @ 0x8b868 (49 bytes) */
int FUN_0008b868(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((*(char *)(iVar1 + 0x20) != '\0') && ((*(byte *)(param_1 + 0x8c) & 2) != 0)) {
    *(undefined1 *)(iVar1 + 0x20) = 0;
    *(undefined4 *)(iVar1 + 0x1cc) = 0;
    ((int (*)())FUN_0008b774)();
    return;
  }
  return;
}

/* FUN_0008b899 @ 0x8b899 (640 bytes) */
int FUN_0008b899(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  byte bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = *(int *)(param_1 + 4);
  iVar4 = *(int *)(iVar3 + 0x10);
  if ((*(int *)(iVar4 + 0x3e28) == 0) || (*(char *)(param_1 + 0x13a8) != '\0')) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if ((((((*(char *)(iVar3 + 0x21) == '\0') || ((*(byte *)((int)param_2 + 0xf) & 0x10) != 0)) ||
        ((*(int *)(*(int *)(iVar3 + 0x18) + 0x198) != 0 && (*(int *)(iVar3 + 0x1cc) == 0)))) ||
       ((*(char *)(iVar4 + 0x4304) != '\0' && (*(int *)(iVar3 + 0x1cc) == 0)))) ||
      ((*(char *)(iVar4 + 0x2d4a) != '\0' && (*(char *)(iVar4 + 0x2d4e) != '\0')))) || (bVar2)) {
    if (*(char *)(iVar3 + 0x20) != '\0') {
      *(undefined1 *)(iVar3 + 0x20) = 0;
      *(undefined1 *)(param_1 + 0x126) = 1;
      *(undefined1 *)(param_1 + 0x124) = 1;
      *(byte *)(param_1 + 0x8c) = *(byte *)(param_1 + 0x8c) | 2;
      *(undefined1 *)(param_1 + 0x125) = 0;
      *(undefined1 *)(param_1 + 299) = 1;
      *param_2 = 0xffffffff;
      param_2[1] = param_2[1] | 0x3ffffff;
      param_2[2] = param_2[2] | 0xfffffffd;
      param_2[3] = param_2[3] | 0x7ffffff;
      param_2[4] = 0xffffffff;
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
        iVar5 = 0;
        iVar4 = param_1;
        do {
          *(undefined1 *)(iVar4 + 0x1814) = 0x3f;
          *(undefined1 *)(iVar4 + 0x181c) = 3;
          iVar5 = iVar5 + 1;
          iVar4 = iVar4 + 1;
        } while (iVar5 < (int)(uint)bVar1);
      }
      *(undefined1 *)(param_1 + 0x23ec) = 1;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(undefined1 *)(param_1 + 0x247d) = 1;
      *(undefined1 *)(param_1 + 0x2803) = 1;
      *(uint *)(param_1 + 0x2488) = *(uint *)(param_1 + 0x2488) | 7;
    }
    *(undefined4 *)(iVar3 + 0x1cc) = 0;
  }
  else if (*(char *)(iVar3 + 0x20) == '\0') {
    *(undefined1 *)(iVar3 + 0x20) = 1;
    *(undefined1 *)(param_1 + 0x126) = 0;
    *(undefined1 *)(param_1 + 0x124) = 0;
    *(byte *)(param_1 + 0x8c) = *(byte *)(param_1 + 0x8c) & 0xfd;
    *(undefined1 *)(param_1 + 0x125) = 0;
    *(undefined1 *)(param_1 + 299) = 1;
    *param_2 = 0xffffffff;
    param_2[1] = param_2[1] | 0x3ffffff;
    param_2[2] = param_2[2] | 0xfffffffd;
    param_2[3] = param_2[3] | 0x7ffffff;
    param_2[4] = 0xffffffff;
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
      iVar4 = 0;
      iVar3 = param_1;
      do {
        *(undefined1 *)(iVar3 + 0x1814) = 0x3f;
        *(undefined1 *)(iVar3 + 0x181c) = 3;
        iVar4 = iVar4 + 1;
        iVar3 = iVar3 + 1;
      } while (iVar4 < (int)(uint)bVar1);
    }
    *(undefined1 *)(param_1 + 0x23ec) = 1;
    *(undefined1 *)(param_1 + 0x29) = 1;
    *(undefined1 *)(param_1 + 0x247d) = 1;
    *(undefined1 *)(param_1 + 0x2803) = 1;
    *(uint *)(param_1 + 0x2488) = *(uint *)(param_1 + 0x2488) | 7;
  }
  return;
}

