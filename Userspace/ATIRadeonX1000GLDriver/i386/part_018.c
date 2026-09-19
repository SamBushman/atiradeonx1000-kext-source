#include "decls.h"

/* FUN_000cbe2a @ 0xcbe2a (23 bytes) */
int FUN_000cbe2a(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 0x4c) != 0) {
    return *(undefined1 *)(*(int *)(param_1 + 0x4c) + 6);
  }
  return 1;
}

/* FUN_000cbe42 @ 0xcbe42 (883 bytes) */
char * FUN_000cbe42(float param_1,int param_2,char *param_3)

{
  uint uVar1;
  char cVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  bool bVar8;
  longdouble lVar9;
  longdouble lVar10;
  char *local_70;
  int local_50;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  int local_24;
  uint local_20 [4];
  
  local_20[0] = 0;
  local_24 = 0;
  pcVar3 = _ecvt((double)param_1,param_2,(int *)local_20,&local_24);
  bVar8 = local_24 != 0;
  if (bVar8) {
    *param_3 = '-';
  }
  local_44 = (uint)bVar8;
  uVar4 = (uint)bVar8;
  if (((int)local_20[0] < 1 - param_2) || (param_2 < (int)local_20[0])) {
    param_3[local_44] = *pcVar3;
    param_3[uVar4 + 1] = '.';
    iVar5 = uVar4 + 2;
    cVar2 = pcVar3[1];
    if (cVar2 == '\0') {
      param_3[iVar5] = 'e';
      local_50 = uVar4 + 3;
    }
    else {
      iVar6 = 1;
      while( true ) {
        param_3[iVar6 + uVar4 + 1] = cVar2;
        cVar2 = pcVar3[iVar6 + 1];
        if (cVar2 == '\0') break;
        iVar6 = iVar6 + 1;
      }
      iVar5 = iVar5 + iVar6;
      param_3[iVar5] = 'e';
      local_50 = iVar5 + 1;
    }
    uVar4 = local_20[0] - 1;
    if ((int)(local_20[0] - 1) < 0) {
      param_3[local_50] = '-';
      local_50 = iVar5 + 2;
      uVar4 = -(local_20[0] - 1);
    }
    local_20[0] = uVar4;
    lVar9 = (longdouble)_log((double)(int)local_20[0]);
    lVar10 = (longdouble)_log(0,0x40240000);
    local_3c = (uint)(longlong)ROUND((double)lVar9 / (double)lVar10);
    uVar4 = local_3c;
    local_40 = local_3c;
    local_48 = 0;
    local_70 = param_3 + local_50;
    do {
      lVar9 = (longdouble)_pow(0,0x40240000,(double)(int)local_40);
      uVar1 = local_20[0];
      cVar2 = (char)((ulonglong)local_20[0] / ((longlong)ROUND(lVar9) & 0xffffffffU));
      *local_70 = cVar2 + '0';
      lVar9 = (longdouble)_pow(0,0x40240000,(double)(int)local_40);
      local_3c = (uint)(longlong)ROUND(lVar9);
      local_20[0] = uVar1 - (int)cVar2 * local_3c;
      local_48 = local_48 + 1;
      local_70 = local_70 + 1;
      local_40 = local_40 - 1;
    } while (local_48 <= uVar4);
    param_3[local_48 + local_50] = '\0';
  }
  else {
    if ((int)local_20[0] < 1) {
      param_3[local_44] = '0';
      param_3[uVar4 + 1] = '.';
      local_44 = uVar4 + 2;
      if ((int)local_20[0] < 0) {
        pcVar7 = param_3 + local_44;
        do {
          *pcVar7 = '0';
          local_44 = local_44 + 1;
          pcVar7 = pcVar7 + 1;
          local_20[0] = local_20[0] + 1;
        } while ((int)local_20[0] < 0);
      }
      local_20[0] = 0xffffffff;
    }
    if (*pcVar3 != '\0') {
      uVar4 = 0;
      pcVar7 = pcVar3;
      do {
        while (uVar4 == local_20[0]) {
          param_3[local_44] = '.';
          local_20[0] = 0xffffffff;
          param_3[local_44 + 1] = *pcVar7;
          local_44 = local_44 + 2;
          uVar4 = uVar4 + 1;
          pcVar7 = pcVar3 + uVar4;
          if (*pcVar7 == '\0') goto LAB_000cbf0a;
        }
        param_3[local_44] = *pcVar7;
        local_44 = local_44 + 1;
        uVar4 = uVar4 + 1;
        pcVar7 = pcVar3 + uVar4;
      } while (*pcVar7 != '\0');
    }
LAB_000cbf0a:
    pcVar3 = param_3 + local_44;
    *pcVar3 = '\0';
    if (local_20[0] == 0xffffffff) {
      cVar2 = *param_3;
      if (cVar2 != '\0') {
        iVar5 = 0;
        uVar4 = local_44;
        do {
          if (cVar2 != '0') {
            if (cVar2 == '.') {
              uVar4 = iVar5 + 2U;
              if (local_44 <= iVar5 + 2U) {
                uVar4 = local_44;
              }
            }
            else {
              uVar4 = iVar5 + 1;
            }
          }
          iVar5 = iVar5 + 1;
          cVar2 = param_3[iVar5];
        } while (cVar2 != '\0');
        pcVar3 = param_3 + uVar4;
      }
      *pcVar3 = '\0';
      return param_3;
    }
  }
  return param_3;
}

/* FUN_000cc1b8 @ 0xcc1b8 (35 bytes) */
int FUN_000cc1b8(param_1)
  undefined4 *param_1;
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}

/* FUN_000cc1dc @ 0xcc1dc (35 bytes) */
int FUN_000cc1dc(param_1)
  undefined4 *param_1;
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}

/* FUN_000cc200 @ 0xcc200 (179 bytes) */
int FUN_000cc200(param_1, param_2)
  int param_1;
  char *param_2;
{
  char cVar1;
  char *pcVar2;
  char local_a0 [128];
  undefined1 *local_20;
  
  if (*(int *)(param_1 + 8) != 0) {
    local_20 = &STACKARG(0xc);
    _vsprintf(local_a0,param_2,local_20);
    pcVar2 = _strchr(local_a0,0x3f);
    if (pcVar2 != (char *)0x0) {
      for (; (((cVar1 = *pcVar2, cVar1 == '?' || (cVar1 == ' ')) || (cVar1 == ',')) ||
             (cVar1 == '\t')); pcVar2 = pcVar2 + -1) {
      }
      pcVar2[1] = '\0';
    }
    _sprintf(local_a0,"%s\n",local_a0);
    (*(code *)**(undefined4 **)(param_1 + 8))(*(undefined4 *)(param_1 + 0xc),"",local_a0,local_20);
  }
  return;
}

/* FUN_000cc2b4 @ 0xcc2b4 (1124 bytes) */
int FUN_000cc2b4(param_1, param_2, param_3)
  undefined4 param_1;
  uint *param_2;
  char *param_3;
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  byte bVar6;
  uint uVar7;
  char *pcVar8;
  bool bVar9;
  char *local_4c;
  int local_48;
  char local_21 [17];
  
  uVar2 = *param_2;
  uVar5 = uVar2 & 0xf;
  uVar7 = (uVar2 & 0x1fe0) >> 5;
  uVar3 = uVar2 & 0x1e000000;
  *param_3 = '\0';
  if (uVar3 == 0x1e000000) {
    uVar4 = 0xffffffff;
    pcVar8 = param_3;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    (param_3 + (~uVar4 - 1))[0] = '-';
    (param_3 + (~uVar4 - 1))[1] = '\0';
    bVar9 = false;
  }
  else {
    bVar9 = uVar3 != 0;
  }
  if (uVar5 == 1) {
    uVar5 = 0xffffffff;
    pcVar8 = param_3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    (param_3 + (~uVar5 - 1))[0] = 'v';
    (param_3 + (~uVar5 - 1))[1] = '\0';
  }
  else if (uVar5 == 0) {
    uVar5 = 0xffffffff;
    pcVar8 = param_3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    (param_3 + (~uVar5 - 1))[0] = 'r';
    (param_3 + (~uVar5 - 1))[1] = '\0';
  }
  else if (uVar5 == 2) {
    uVar5 = 0xffffffff;
    pcVar8 = param_3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    (param_3 + (~uVar5 - 1))[0] = 'c';
    (param_3 + (~uVar5 - 1))[1] = '\0';
  }
  else {
    if (uVar5 != 3) {
      uVar5 = 0xffffffff;
      pcVar8 = param_3;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      (param_3 + (~uVar5 - 1))[0] = '?';
      (param_3 + (~uVar5 - 1))[1] = '\0';
      _sprintf(local_21,"%d",uVar7);
      goto joined_r0x000cc418;
    }
    uVar5 = 0xffffffff;
    pcVar8 = param_3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    (param_3 + (~uVar5 - 1))[0] = 't';
    (param_3 + (~uVar5 - 1))[1] = '\0';
  }
  _sprintf(local_21,"%d",uVar7);
joined_r0x000cc418:
  if ((uVar2 & 0x80000010) == 0) {
    local_4c = local_21;
    _strcat(param_3,local_4c);
  }
  else {
    local_4c = local_21;
    if ((uVar2 & 0x80000010) == 0x10) {
      uVar5 = 0xffffffff;
      pcVar8 = param_3;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      builtin_strncpy(param_3 + (~uVar5 - 1),"[a0",4);
    }
    else {
      uVar5 = 0xffffffff;
      pcVar8 = param_3;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      builtin_strncpy(param_3 + (~uVar5 - 1),"[i0",4);
    }
    switch((uVar2 & 0x60000000) >> 0x1d) {
    case 0:
      uVar5 = 0xffffffff;
      pcVar8 = param_3;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      pcVar8 = param_3 + (~uVar5 - 1);
      pcVar8[0] = '.';
      pcVar8[1] = 'x';
      pcVar8[2] = '\0';
      break;
    case 1:
      uVar5 = 0xffffffff;
      pcVar8 = param_3;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      pcVar8 = param_3 + (~uVar5 - 1);
      pcVar8[0] = '.';
      pcVar8[1] = 'y';
      pcVar8[2] = '\0';
      break;
    case 2:
      uVar5 = 0xffffffff;
      pcVar8 = param_3;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      pcVar8 = param_3 + (~uVar5 - 1);
      pcVar8[0] = '.';
      pcVar8[1] = 'z';
      pcVar8[2] = '\0';
      break;
    case 3:
      uVar5 = 0xffffffff;
      pcVar8 = param_3;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      pcVar8 = param_3 + (~uVar5 - 1);
      pcVar8[0] = '.';
      pcVar8[1] = 'w';
      pcVar8[2] = '\0';
      break;
    default:
      uVar5 = 0xffffffff;
      pcVar8 = param_3;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      pcVar8 = param_3 + (~uVar5 - 1);
      pcVar8[0] = '.';
      pcVar8[1] = '?';
      pcVar8[2] = '\0';
    }
    uVar5 = 0xffffffff;
    pcVar8 = param_3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    (param_3 + (~uVar5 - 1))[0] = '+';
    (param_3 + (~uVar5 - 1))[1] = '\0';
    _strcat(param_3,local_4c);
    uVar5 = 0xffffffff;
    pcVar8 = param_3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    (param_3 + (~uVar5 - 1))[0] = ']';
    (param_3 + (~uVar5 - 1))[1] = '\0';
  }
  if (((uVar2 & 0x1ffe000) != 0xd10000) || (bVar9)) {
    uVar5 = 0xffffffff;
    pcVar8 = param_3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    (param_3 + (~uVar5 - 1))[0] = '.';
    (param_3 + (~uVar5 - 1))[1] = '\0';
    local_48 = 0;
    bVar6 = 0xd;
    do {
      if (((uVar3 & 0x2000000 << ((byte)local_48 & 0x1f)) != 0) && (bVar9)) {
        uVar5 = 0xffffffff;
        pcVar8 = param_3;
        do {
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        (param_3 + (~uVar5 - 1))[0] = '-';
        (param_3 + (~uVar5 - 1))[1] = '\0';
      }
      switch((7 << (bVar6 & 0x1f) & uVar2 & 0x1ffe000) >> (bVar6 & 0x1f)) {
      case 0:
        uVar5 = 0xffffffff;
        pcVar8 = param_3;
        do {
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        (param_3 + (~uVar5 - 1))[0] = 'x';
        (param_3 + (~uVar5 - 1))[1] = '\0';
        break;
      case 1:
        uVar5 = 0xffffffff;
        pcVar8 = param_3;
        do {
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        (param_3 + (~uVar5 - 1))[0] = 'y';
        (param_3 + (~uVar5 - 1))[1] = '\0';
        break;
      case 2:
        uVar5 = 0xffffffff;
        pcVar8 = param_3;
        do {
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        (param_3 + (~uVar5 - 1))[0] = 'z';
        (param_3 + (~uVar5 - 1))[1] = '\0';
        break;
      case 3:
        uVar5 = 0xffffffff;
        pcVar8 = param_3;
        do {
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        (param_3 + (~uVar5 - 1))[0] = 'w';
        (param_3 + (~uVar5 - 1))[1] = '\0';
        break;
      case 4:
        uVar5 = 0xffffffff;
        pcVar8 = param_3;
        do {
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        (param_3 + (~uVar5 - 1))[0] = '0';
        (param_3 + (~uVar5 - 1))[1] = '\0';
        break;
      case 5:
        uVar5 = 0xffffffff;
        pcVar8 = param_3;
        do {
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        (param_3 + (~uVar5 - 1))[0] = '1';
        (param_3 + (~uVar5 - 1))[1] = '\0';
        break;
      default:
        uVar5 = 0xffffffff;
        pcVar8 = param_3;
        do {
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        (param_3 + (~uVar5 - 1))[0] = '?';
        (param_3 + (~uVar5 - 1))[1] = '\0';
      }
      local_48 = local_48 + 1;
      bVar6 = bVar6 + 3;
    } while (local_48 != 4);
  }
  return param_2 + 1;
}

/* FUN_000cc794 @ 0xcc794 (64 bytes) */
int FUN_000cc794(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  if (*(char *)(param_2 + 3) < '\0') {
    ((int (*)())FUN_000cc200)(param_1,";    v%d = dx v%d",*(undefined1 *)(param_2 + 4),
                 *(undefined1 *)(param_2 + 1));
  }
  return;
}

/* FUN_000cc7d4 @ 0xcc7d4 (849 bytes) */
int FUN_000cc7d4(param_1, param_2)
  undefined4 param_1;
  undefined1 *param_2;
{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  int iVar8;
  int iVar9;
  char *local_210;
  char local_1fc [256];
  char local_fc [128];
  undefined4 local_7c;
  undefined4 local_78;
  uint local_74;
  undefined1 local_70;
  uint auStack_40 [5];
  char local_2c [12];
  char local_20 [16];
  
  if (-1 < (char)param_2[3]) {
    return;
  }
  switch(*param_2) {
  case 0:
    local_7c = 0x705f4c49;
    local_78 = CONCAT13((*(unsigned char *)((unsigned char *)&(local_78) + 3)),0x736f);
    break;
  case 1:
    local_7c = 0x705f4c49;
    local_78 = 0x746e696f;
    local_74 = 0x657a6973;
    local_70 = 0;
    break;
  case 2:
    local_7c = 0x635f4c49;
    local_78 = 0x726f6c6f;
    local_74 = local_74 & 0xffffff00;
    break;
  case 3:
    local_7c = 0x625f4c49;
    local_78 = 0x636b6361;
    local_74 = 0x726f6c6f;
    local_70 = 0;
    break;
  case 4:
    local_7c = 0x665f4c49;
    local_78 = CONCAT13((*(unsigned char *)((unsigned char *)&(local_78) + 3)),0x676f);
    break;
  case 5:
    local_7c = 0x675f4c49;
    local_78 = 0x72656e65;
    local_74 = CONCAT13((*(unsigned char *)((unsigned char *)&(local_74) + 3)),0x6369);
    break;
  default:
    local_7c = 0x755f4c49;
    local_78 = 0x6f6e6b6e;
    local_74 = CONCAT13((*(unsigned char *)((unsigned char *)&(local_74) + 3)),0x6e77);
  }
  _sprintf(local_2c,"%d",(uint)(byte)param_2[1]);
  builtin_strncpy(local_20,"xyzw",4);
  bVar1 = param_2[3];
  iVar9 = 0;
  bVar3 = false;
  iVar6 = 0;
  puVar7 = param_2;
  do {
    if ((bVar1 & 0xf & 1 << ((byte)iVar6 & 0x1f)) != 0) {
      bVar2 = puVar7[4];
      auStack_40[iVar9 + 1] = (uint)bVar2;
      bVar4 = bVar3;
      if ((iVar9 != 0) && (bVar4 = true, (uint)bVar2 == auStack_40[iVar9])) {
        bVar4 = bVar3;
      }
      bVar3 = bVar4;
      iVar9 = iVar9 + 1;
    }
    iVar6 = iVar6 + 1;
    puVar7 = puVar7 + 1;
  } while (iVar6 != 4);
  if (bVar3) {
    iVar6 = 0;
    puVar7 = param_2;
    local_210 = local_1fc;
    do {
      if (((byte)param_2[3] & 0xf & 1 << ((byte)iVar6 & 0x1f)) == 0) {
        local_1fc[iVar6 * 0x40] = '\0';
      }
      else {
        _sprintf(local_210,"o%d.%c ",(uint)(byte)puVar7[4],(int)local_20[(byte)puVar7[8]]);
      }
      iVar6 = iVar6 + 1;
      local_210 = local_210 + 0x40;
      puVar7 = puVar7 + 1;
    } while (iVar6 != 4);
    _sprintf(local_fc,"%s%s%s%s",local_1fc,local_1fc + 0x40,local_1fc + 0x80,local_1fc + 0xc0);
    goto LAB_000cc9c1;
  }
  if ((bVar1 & 8) == 0) {
    iVar6 = 0x5f;
    if ((bVar1 & 4) == 0) goto LAB_000cc8c8;
LAB_000cca66:
    iVar9 = (int)local_20[(byte)param_2[10]];
    if ((bVar1 & 2) != 0) goto LAB_000cca7e;
LAB_000cc8d9:
    iVar8 = 0x5f;
    if ((bVar1 & 1) == 0) goto LAB_000cc8e7;
LAB_000cca93:
    iVar5 = (int)local_20[(byte)param_2[8]];
  }
  else {
    iVar6 = (int)local_20[(byte)param_2[0xb]];
    if ((bVar1 & 4) != 0) goto LAB_000cca66;
LAB_000cc8c8:
    iVar9 = 0x5f;
    if ((bVar1 & 2) == 0) goto LAB_000cc8d9;
LAB_000cca7e:
    iVar8 = (int)local_20[(byte)param_2[9]];
    if ((bVar1 & 1) != 0) goto LAB_000cca93;
LAB_000cc8e7:
    iVar5 = 0x5f;
  }
  _sprintf(local_fc,"o%d.%c%c%c%c",(uint)(byte)param_2[4],iVar5,iVar8,iVar9,iVar6);
LAB_000cc9c1:
  ((int (*)())FUN_000cc200)(param_1,";    %s = %s%s",local_fc,&local_7c,local_2c);
  return;
}

/* FUN_000ccb40 @ 0xccb40 (591 bytes) */
int FUN_000ccb40(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  ((int (*)())FUN_000cc200)(param_1,"");
  ((int (*)())FUN_000cc200)(param_1,";*****************************************");
  ((int (*)())FUN_000cc200)(param_1,";                 VS Data");
  ((int (*)())FUN_000cc200)(param_1,";*****************************************");
  ((int (*)())FUN_000cc200)(param_1,"; Input Semantic Mappings");
  if (*(int *)(param_2 + 0x104) == 0) {
    ((int (*)())FUN_000cc200)(param_1,";    No input mappings");
  }
  else {
    iVar2 = 0;
    iVar1 = param_2 + 0x108;
    do {
      ((int (*)())FUN_000cc794)(param_1,iVar1,iVar2);
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0xc;
    } while (iVar2 != 0x40);
  }
  ((int (*)())FUN_000cc200)(param_1,"");
  ((int (*)())FUN_000cc200)(param_1,"; Output Semantic Mappings");
  if (*(int *)(param_2 + 0x408) == 0) {
    ((int (*)())FUN_000cc200)(param_1,";    No output mappings");
  }
  else {
    iVar2 = 0;
    iVar1 = param_2 + 0x40c;
    do {
      ((int (*)())FUN_000cc7d4)(param_1,iVar1,iVar2);
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0xc;
    } while (iVar2 != 0x30);
  }
  ((int (*)())FUN_000cc200)(param_1,"");
  ((int (*)())FUN_000cc200)(param_1,"; Num Insts = %d",*(undefined4 *)(param_2 + 0x65c));
  ((int (*)())FUN_000cc200)(param_1,"; Max Temp = %d",*(int *)(param_2 + 0x660) + -1);
  ((int (*)())FUN_000cc200)(param_1,"; Max AltTemp = %d",*(int *)(param_2 + 0x664) + -1);
  ((int (*)())FUN_000cc200)(param_1,"; Max Constants = %d",*(int *)(param_2 + 0x670) + -1);
  ((int (*)())FUN_000cc200)(param_1,"; Last Pos Inst = %d",*(undefined4 *)(param_2 + 0x668));
  uVar3 = *(undefined4 *)(param_2 + 0x66c);
  ((int (*)())FUN_000cc200)(param_1,"; Last Src Inst = %d",uVar3);
  if (*(int *)(param_2 + 0x658) != 0) {
    ((int (*)())FUN_000cc200)(param_1,"; Shader uses relative addressing",uVar3);
  }
  return 1;
}

/* FUN_000ccd90 @ 0xccd90 (879 bytes) */
int FUN_000ccd90(param_1, param_2, param_3)
  undefined4 param_1;
  uint *param_2;
  char *param_3;
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char local_21 [17];
  
  uVar3 = *param_2;
  uVar4 = (uVar3 & 0x60000000) >> 0x1d;
  switch((uVar3 & 0xf00) >> 8) {
  case 0:
    param_3[0] = 'r';
    param_3[1] = '\0';
    break;
  case 1:
    param_3[0] = 'a';
    param_3[1] = '\0';
    break;
  case 2:
    param_3[0] = 'o';
    param_3[1] = '\0';
    break;
  case 3:
    param_3[0] = 'o';
    param_3[1] = 'x';
    param_3[2] = '\0';
    break;
  case 4:
    param_3[0] = 't';
    param_3[1] = '\0';
    break;
  case 5:
    param_3[0] = 'v';
    param_3[1] = '\0';
    break;
  default:
    param_3[0] = '?';
    param_3[1] = '\0';
  }
  _sprintf(local_21,"%d",(uVar3 & 0xfe000) >> 0xd);
  if ((uVar3 & 0x80001000) == 0) {
    _strcat(param_3,local_21);
    goto LAB_000ccf01;
  }
  if ((uVar3 & 0x80001000) == 0x80000000) {
    uVar2 = 0xffffffff;
    pcVar5 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    builtin_strncpy(param_3 + (~uVar2 - 1),"[a0",4);
    if (5 < uVar4) goto LAB_000cce9f;
LAB_000cce5b:
    switch((switchdataD_000cce68)[uVar4] + 0xccd9e) {
    case 0xcd07c:
      uVar4 = 0xffffffff;
      pcVar5 = param_3;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      pcVar5 = param_3 + (~uVar4 - 1);
      pcVar5[0] = '.';
      pcVar5[1] = 'x';
      pcVar5[2] = '\0';
      break;
    case 0xcd0a0:
      uVar4 = 0xffffffff;
      pcVar5 = param_3;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      pcVar5 = param_3 + (~uVar4 - 1);
      pcVar5[0] = '.';
      pcVar5[1] = 'y';
      pcVar5[2] = '\0';
      break;
    case 0xcd0c4:
      uVar4 = 0xffffffff;
      pcVar5 = param_3;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      pcVar5 = param_3 + (~uVar4 - 1);
      pcVar5[0] = '.';
      pcVar5[1] = 'z';
      pcVar5[2] = '\0';
      break;
    case 0xcd0e8:
      uVar4 = 0xffffffff;
      pcVar5 = param_3;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      pcVar5 = param_3 + (~uVar4 - 1);
      pcVar5[0] = '.';
      pcVar5[1] = 'w';
      pcVar5[2] = '\0';
    }
  }
  else {
    uVar2 = 0xffffffff;
    pcVar5 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    builtin_strncpy(param_3 + (~uVar2 - 1),"[i0",4);
    if (uVar4 < 6) goto LAB_000cce5b;
LAB_000cce9f:
    uVar4 = 0xffffffff;
    pcVar5 = param_3;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    pcVar5 = param_3 + (~uVar4 - 1);
    pcVar5[0] = '.';
    pcVar5[1] = '?';
    pcVar5[2] = '\0';
  }
  uVar4 = 0xffffffff;
  pcVar5 = param_3;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  (param_3 + (~uVar4 - 1))[0] = '+';
  (param_3 + (~uVar4 - 1))[1] = '\0';
  _strcat(param_3,local_21);
  uVar4 = 0xffffffff;
  pcVar5 = param_3;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  (param_3 + (~uVar4 - 1))[0] = ']';
  (param_3 + (~uVar4 - 1))[1] = '\0';
LAB_000ccf01:
  if ((uVar3 & 0x40) == 0) {
    if ((uVar3 & 0x1000000) != 0) {
      uVar4 = 0xffffffff;
      pcVar5 = param_3;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      builtin_strncpy(param_3 + (~uVar4 - 1),"_sat",5);
    }
  }
  else if ((uVar3 & 0x2000000) != 0) {
    uVar4 = 0xffffffff;
    pcVar5 = param_3;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    builtin_strncpy(param_3 + (~uVar4 - 1),"_sat",5);
  }
  if ((uVar3 & 0xf00000) != 0xf00000) {
    uVar4 = 0xffffffff;
    pcVar5 = param_3;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    (param_3 + (~uVar4 - 1))[0] = '.';
    (param_3 + (~uVar4 - 1))[1] = '\0';
    if ((uVar3 & 0x100000) != 0) {
      uVar4 = 0xffffffff;
      pcVar5 = param_3;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      (param_3 + (~uVar4 - 1))[0] = 'x';
      (param_3 + (~uVar4 - 1))[1] = '\0';
    }
    if ((uVar3 & 0x200000) != 0) {
      uVar4 = 0xffffffff;
      pcVar5 = param_3;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      (param_3 + (~uVar4 - 1))[0] = 'y';
      (param_3 + (~uVar4 - 1))[1] = '\0';
    }
    if ((uVar3 & 0x400000) != 0) {
      uVar4 = 0xffffffff;
      pcVar5 = param_3;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      (param_3 + (~uVar4 - 1))[0] = 'z';
      (param_3 + (~uVar4 - 1))[1] = '\0';
    }
    if ((uVar3 & 0x800000) != 0) {
      uVar3 = 0xffffffff;
      pcVar5 = param_3;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      (param_3 + (~uVar3 - 1))[0] = 'w';
      (param_3 + (~uVar3 - 1))[1] = '\0';
    }
  }
  return param_2 + 1;
}

/* FUN_000cd17a @ 0xcd17a (2403 bytes) */
int FUN_000cd17a(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  uint *param_2;
  char *param_3;
  char *param_4;
  char *param_5;
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  byte bVar7;
  char *pcVar8;
  bool bVar9;
  int local_38;
  char local_26 [5];
  char local_21 [17];
  
  uVar6 = param_2[-3];
  uVar2 = *param_2;
  uVar3 = uVar2 & 0x18000000;
  uVar4 = uVar2 & 0xf;
  param_3[0] = ' ';
  param_3[1] = ' ';
  param_3[2] = ' ';
  param_3[3] = ' ';
  *(undefined ***)(param_3 + 4) = &PTR_PTR_00207544;
  switch((uVar2 & 0x1e00000) >> 0x15 | ((uVar2 & 4) >> 2) << 4 | 0x40) {
  case 0x40:
    uVar5 = 0xffffffff;
    pcVar8 = param_3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    builtin_strncpy(param_3 + (~uVar5 - 1),"NOPme     ",0xb);
    break;
  case 0x41:
    uVar5 = 0xffffffff;
    pcVar8 = param_3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    builtin_strncpy(param_3 + (~uVar5 - 1),"EXPP      ",0xb);
    break;
  case 0x42:
    uVar5 = 0xffffffff;
    pcVar8 = param_3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    builtin_strncpy(param_3 + (~uVar5 - 1),"LOGP      ",0xb);
    break;
  case 0x43:
    uVar5 = 0xffffffff;
    pcVar8 = param_3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    builtin_strncpy(param_3 + (~uVar5 - 1),"EXPPE     ",0xb);
    break;
  case 0x44:
    uVar5 = 0xffffffff;
    pcVar8 = param_3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    builtin_strncpy(param_3 + (~uVar5 - 1),"LIT       ",0xb);
    break;
  case 0x45:
    uVar5 = 0xffffffff;
    pcVar8 = param_3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    builtin_strncpy(param_3 + (~uVar5 - 1),"POW       ",0xb);
    break;
  case 0x46:
    uVar5 = 0xffffffff;
    pcVar8 = param_3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    builtin_strncpy(param_3 + (~uVar5 - 1),"RCP       ",0xb);
    break;
  case 0x47:
    uVar5 = 0xffffffff;
    pcVar8 = param_3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    builtin_strncpy(param_3 + (~uVar5 - 1),"RCPFF     ",0xb);
    break;
  case 0x48:
    uVar5 = 0xffffffff;
    pcVar8 = param_3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    builtin_strncpy(param_3 + (~uVar5 - 1),"RSQ       ",0xb);
    break;
  case 0x49:
    uVar5 = 0xffffffff;
    pcVar8 = param_3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    builtin_strncpy(param_3 + (~uVar5 - 1),"RSQFF     ",0xb);
    break;
  case 0x4a:
    uVar5 = 0xffffffff;
    pcVar8 = param_3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    builtin_strncpy(param_3 + (~uVar5 - 1),"MULme     ",0xb);
    break;
  case 0x4b:
    uVar5 = 0xffffffff;
    pcVar8 = param_3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    builtin_strncpy(param_3 + (~uVar5 - 1),"EXP       ",0xb);
    break;
  case 0x4c:
    uVar5 = 0xffffffff;
    pcVar8 = param_3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    builtin_strncpy(param_3 + (~uVar5 - 1),"LOG       ",0xb);
    break;
  case 0x4d:
    uVar5 = 0xffffffff;
    pcVar8 = param_3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    builtin_strncpy(param_3 + (~uVar5 - 1),"POWB      ",0xb);
    break;
  case 0x4e:
    uVar5 = 0xffffffff;
    pcVar8 = param_3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    builtin_strncpy(param_3 + (~uVar5 - 1),"POWB1     ",0xb);
    break;
  case 0x4f:
    uVar5 = 0xffffffff;
    pcVar8 = param_3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    builtin_strncpy(param_3 + (~uVar5 - 1),"POW01     ",0xb);
    break;
  case 0x50:
    uVar5 = 0xffffffff;
    pcVar8 = param_3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    builtin_strncpy(param_3 + (~uVar5 - 1),"SIN       ",0xb);
    break;
  case 0x51:
    uVar5 = 0xffffffff;
    pcVar8 = param_3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    builtin_strncpy(param_3 + (~uVar5 - 1),"COS       ",0xb);
    break;
  case 0x52:
    uVar5 = 0xffffffff;
    pcVar8 = param_3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    builtin_strncpy(param_3 + (~uVar5 - 1),"LOGIE3    ",0xb);
    break;
  case 0x53:
    uVar5 = 0xffffffff;
    pcVar8 = param_3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    builtin_strncpy(param_3 + (~uVar5 - 1),"RCPIE3    ",0xb);
    break;
  case 0x54:
    uVar5 = 0xffffffff;
    pcVar8 = param_3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    builtin_strncpy(param_3 + (~uVar5 - 1),"RSQIE3    ",0xb);
    break;
  case 0x55:
    uVar5 = 0xffffffff;
    pcVar8 = param_3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    builtin_strncpy(param_3 + (~uVar5 - 1),"Prd_EQ    ",0xb);
    break;
  case 0x56:
    uVar5 = 0xffffffff;
    pcVar8 = param_3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    builtin_strncpy(param_3 + (~uVar5 - 1),"Prd_GT    ",0xb);
    break;
  case 0x57:
    uVar5 = 0xffffffff;
    pcVar8 = param_3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    builtin_strncpy(param_3 + (~uVar5 - 1),"Prd_GTE   ",0xb);
    break;
  case 0x58:
    uVar5 = 0xffffffff;
    pcVar8 = param_3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    builtin_strncpy(param_3 + (~uVar5 - 1),"Prd_NEQ   ",0xb);
    break;
  case 0x59:
    uVar5 = 0xffffffff;
    pcVar8 = param_3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    builtin_strncpy(param_3 + (~uVar5 - 1),"Prd_CLR   ",0xb);
    break;
  case 0x5a:
    uVar5 = 0xffffffff;
    pcVar8 = param_3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    builtin_strncpy(param_3 + (~uVar5 - 1),"Prd_INV   ",0xb);
    break;
  case 0x5b:
    uVar5 = 0xffffffff;
    pcVar8 = param_3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    builtin_strncpy(param_3 + (~uVar5 - 1),"Prd_POP   ",0xb);
    break;
  case 0x5c:
    uVar5 = 0xffffffff;
    pcVar8 = param_3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    builtin_strncpy(param_3 + (~uVar5 - 1),"Prd_RSTOR ",0xb);
    break;
  default:
    uVar5 = 0xffffffff;
    pcVar8 = param_3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    builtin_strncpy(param_3 + (~uVar5 - 1),"ERROR     ",0xb);
  }
  param_4[0] = 't';
  param_4[1] = '\0';
  _sprintf(local_21,"%d",(uVar2 & 0x180000) >> 0x13);
  if ((uVar6 & 0x2000000) != 0) {
    uVar6 = 0xffffffff;
    pcVar8 = param_4;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    builtin_strncpy(param_4 + (~uVar6 - 1),"_sat",5);
  }
  _strcat(param_4,local_21);
  uVar6 = 0xffffffff;
  pcVar8 = param_4;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  (param_4 + (~uVar6 - 1))[0] = '.';
  (param_4 + (~uVar6 - 1))[1] = '\0';
  if (uVar3 == 0) {
    uVar6 = 0xffffffff;
    pcVar8 = param_4;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    (param_4 + (~uVar6 - 1))[0] = 'x';
    (param_4 + (~uVar6 - 1))[1] = '\0';
    uVar6 = 0xffffffff;
    pcVar8 = param_4;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    (param_4 + (~uVar6 - 1))[0] = ',';
    (param_4 + (~uVar6 - 1))[1] = '\0';
  }
  else {
    if (uVar3 == 0x8000000) {
      uVar6 = 0xffffffff;
      pcVar8 = param_4;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      (param_4 + (~uVar6 - 1))[0] = 'y';
      (param_4 + (~uVar6 - 1))[1] = '\0';
    }
    else if (uVar3 == 0x10000000) {
      uVar6 = 0xffffffff;
      pcVar8 = param_4;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      (param_4 + (~uVar6 - 1))[0] = 'z';
      (param_4 + (~uVar6 - 1))[1] = '\0';
    }
    else if (uVar3 == 0x18000000) {
      uVar6 = 0xffffffff;
      pcVar8 = param_4;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      (param_4 + (~uVar6 - 1))[0] = 'w';
      (param_4 + (~uVar6 - 1))[1] = '\0';
    }
    uVar6 = 0xffffffff;
    pcVar8 = param_4;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    (param_4 + (~uVar6 - 1))[0] = ',';
    (param_4 + (~uVar6 - 1))[1] = '\0';
  }
  if (uVar4 == 1) {
    param_5[0] = 'v';
    param_5[1] = '\0';
  }
  else if (uVar4 == 0) {
    param_5[0] = 'r';
    param_5[1] = '\0';
  }
  else if (uVar4 == 2) {
    param_5[0] = 'c';
    param_5[1] = '\0';
  }
  else if (uVar4 == 3) {
    param_5[0] = 't';
    param_5[1] = '\0';
  }
  else {
    param_5[0] = '?';
    param_5[1] = '\0';
  }
  _sprintf(local_26,"%d",(uVar2 & 0x1fe0) >> 5);
  _strcat(param_5,local_26);
  bVar9 = (uVar2 & 0x6000000) == 0;
  if (((uVar2 & 0x7e000) == 0x10000) && (bVar9)) {
    return param_2 + 1;
  }
  uVar6 = 0xffffffff;
  pcVar8 = param_5;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  (param_5 + (~uVar6 - 1))[0] = '.';
  (param_5 + (~uVar6 - 1))[1] = '\0';
  local_38 = 0;
  bVar7 = 0xd;
  do {
    if (((uVar2 & 0x6000000 & 0x2000000 << ((byte)local_38 & 0x1f)) != 0) && (!bVar9)) {
      uVar6 = 0xffffffff;
      pcVar8 = param_5;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (bVar9 != (bool)cVar1);
      (param_5 + (~uVar6 - 1))[0] = '-';
      (param_5 + (~uVar6 - 1))[1] = '\0';
    }
    switch((7 << (bVar7 & 0x1f) & uVar2 & 0x7e000) >> (bVar7 & 0x1f)) {
    case 0:
      uVar6 = 0xffffffff;
      pcVar8 = param_5;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      (param_5 + (~uVar6 - 1))[0] = 'x';
      (param_5 + (~uVar6 - 1))[1] = '\0';
      break;
    case 1:
      uVar6 = 0xffffffff;
      pcVar8 = param_5;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      (param_5 + (~uVar6 - 1))[0] = 'y';
      (param_5 + (~uVar6 - 1))[1] = '\0';
      break;
    case 2:
      uVar6 = 0xffffffff;
      pcVar8 = param_5;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      (param_5 + (~uVar6 - 1))[0] = 'z';
      (param_5 + (~uVar6 - 1))[1] = '\0';
      break;
    case 3:
      uVar6 = 0xffffffff;
      pcVar8 = param_5;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      (param_5 + (~uVar6 - 1))[0] = 'w';
      (param_5 + (~uVar6 - 1))[1] = '\0';
      break;
    case 4:
      uVar6 = 0xffffffff;
      pcVar8 = param_5;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      (param_5 + (~uVar6 - 1))[0] = '0';
      (param_5 + (~uVar6 - 1))[1] = '\0';
      break;
    case 5:
      uVar6 = 0xffffffff;
      pcVar8 = param_5;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      (param_5 + (~uVar6 - 1))[0] = '1';
      (param_5 + (~uVar6 - 1))[1] = '\0';
      break;
    default:
      uVar6 = 0xffffffff;
      pcVar8 = param_5;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      (param_5 + (~uVar6 - 1))[0] = '?';
      (param_5 + (~uVar6 - 1))[1] = '\0';
    }
    local_38 = local_38 + 1;
    bVar7 = bVar7 + 3;
    if (local_38 == 2) {
      return param_2 + 1;
    }
  } while( true );
}

/* FUN_000cdb6a @ 0xcdb6a (2519 bytes) */
int FUN_000cdb6a(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  uint *param_2;
  int *param_3;
  undefined4 *param_4;
  undefined4 *param_5;
{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  int *piVar4;
  
  uVar2 = *param_2;
  *param_4 = 0;
  if ((uVar2 & 0x10000000) != 0) {
    *param_4 = 1;
  }
  if ((uVar2 & 0x4000000) == 0) {
    *param_3 = (int)&DAT_00202020;
  }
  else {
    *param_3 = ~-(uint)((uVar2 & 0x8000000) == 0) + 0x207021;
  }
  switch(uVar2 & 0xff) {
  case 0:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"NOPv",4);
    goto LAB_000cde36;
  case 1:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"DP4     ",8);
    goto LAB_000cde78;
  case 2:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"MULve   ",8);
    goto LAB_000cde78;
  case 3:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"ADD     ",8);
    goto LAB_000cde78;
  case 4:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"MAD     ",8);
    goto LAB_000cdefe;
  case 5:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"DST     ",8);
    goto LAB_000cde78;
  case 6:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"FRC     ",8);
    break;
  case 7:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"MAX     ",8);
    goto LAB_000cde78;
  case 8:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"MIN     ",8);
    goto LAB_000cde78;
  case 9:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"SGE     ",8);
    goto LAB_000cde78;
  case 10:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"SLT     ",8);
    goto LAB_000cde78;
  case 0xb:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"M2xADD  ",8);
    goto LAB_000cde78;
  case 0xc:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"MULCLAMP",8);
    goto LAB_000cde78;
  case 0xd:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"F2F_FLR ",8);
    break;
  case 0xe:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"F2F_RND ",8);
    break;
  case 0xf:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    builtin_strncpy((char *)((~uVar2 - 1) + (int)param_3),"PrdEQ_PSH ",0xb);
    *param_5 = 2;
    return 0;
  case 0x10:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    builtin_strncpy((char *)((~uVar2 - 1) + (int)param_3),"PrdGT_PSH",10);
    *param_5 = 2;
    return 0;
  case 0x11:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"PrdGTE_P",8);
    goto LAB_000ce13c;
  case 0x12:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"PrdNEQ_P",8);
LAB_000ce13c:
    pcVar3[8] = 'S';
    pcVar3[9] = 'H';
    pcVar3[10] = '\0';
    *param_5 = 2;
    return 0;
  case 0x13:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    builtin_strncpy((char *)((~uVar2 - 1) + (int)param_3),"CND_WR_EQ ",0xb);
    *param_5 = 3;
    return 0;
  case 0x14:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    builtin_strncpy((char *)((~uVar2 - 1) + (int)param_3),"CND_WR_GT",10);
    *param_5 = 2;
    return 0;
  case 0x15:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    builtin_strncpy((char *)((~uVar2 - 1) + (int)param_3),"CND_WR_GTE",0xb);
    *param_5 = 2;
    return 0;
  case 0x16:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"CND_WR_N",8);
    goto LAB_000ce251;
  case 0x17:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"CND_MUX_",8);
LAB_000ce251:
    pcVar3[8] = 'E';
    pcVar3[9] = 'Q';
    pcVar3[10] = '\0';
    *param_5 = 3;
    return 0;
  case 0x18:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    builtin_strncpy((char *)((~uVar2 - 1) + (int)param_3),"CND_MUX_GT",0xb);
    *param_5 = 3;
    return 0;
  case 0x19:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    builtin_strncpy((char *)((~uVar2 - 1) + (int)param_3),"CND_MUX_GTE",0xc);
    *param_5 = 3;
    return 0;
  case 0x1a:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"SGT     ",8);
    goto LAB_000cde78;
  case 0x1b:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"SEQ     ",8);
    goto LAB_000cde78;
  case 0x1c:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"SNE     ",8);
    goto LAB_000cde78;
  default:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    builtin_strncpy((char *)((~uVar2 - 1) + (int)param_3),"ERROR     ",0xb);
    return 1;
  case 0x40:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"NOPm",4);
LAB_000cde36:
    builtin_strncpy(pcVar3 + 4,"e   ",4);
LAB_000cde3d:
    pcVar3[8] = ' ';
    pcVar3[9] = ' ';
    pcVar3[10] = '\0';
    *param_5 = 0;
    return 0;
  case 0x41:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"EXPP    ",8);
    break;
  case 0x42:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"LOGP    ",8);
    break;
  case 0x43:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"EXPPE   ",8);
    break;
  case 0x44:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"LIT     ",8);
    goto LAB_000cdefe;
  case 0x45:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"POW     ",8);
    goto LAB_000cde78;
  case 0x46:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"RCP     ",8);
    break;
  case 0x47:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"RCPFF   ",8);
    break;
  case 0x48:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"RSQ     ",8);
    break;
  case 0x49:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"RSQFF   ",8);
    break;
  case 0x4a:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"MULme   ",8);
LAB_000cde78:
    pcVar3[8] = ' ';
    pcVar3[9] = ' ';
    pcVar3[10] = '\0';
    *param_5 = 2;
    return 0;
  case 0x4b:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"EXP     ",8);
    break;
  case 0x4c:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"LOG     ",8);
    break;
  case 0x4d:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"POWB    ",8);
    break;
  case 0x4e:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"POWB1   ",8);
    break;
  case 0x4f:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"POW01   ",8);
    break;
  case 0x50:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"SIN     ",8);
    break;
  case 0x51:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"COS     ",8);
    break;
  case 0x55:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"Prd_EQ  ",8);
    break;
  case 0x58:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"Prd_NEQ ",8);
    break;
  case 0x59:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"Prd_CLR ",8);
    goto LAB_000cde3d;
  case 0x5a:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"Prd_INV ",8);
    break;
  case 0x5b:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"Prd_POP ",8);
    break;
  case 0x5c:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    builtin_strncpy((char *)((~uVar2 - 1) + (int)param_3),"Prd_RSTOR ",0xb);
    *param_5 = 1;
    return 0;
  case 0x80:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    pcVar3 = (char *)((~uVar2 - 1) + (int)param_3);
    builtin_strncpy(pcVar3,"MADmac  ",8);
LAB_000cdefe:
    pcVar3[8] = ' ';
    pcVar3[9] = ' ';
    pcVar3[10] = '\0';
    *param_5 = 3;
    return 0;
  case 0x81:
    uVar2 = 0xffffffff;
    piVar4 = param_3;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    builtin_strncpy((char *)((~uVar2 - 1) + (int)param_3),"M2xADDmac ",0xb);
    *param_5 = 2;
    return 0;
  }
  pcVar3[8] = ' ';
  pcVar3[9] = ' ';
  pcVar3[10] = '\0';
  *param_5 = 1;
  return 0;
}

/* FUN_000ce74c @ 0xce74c (88 bytes) */
int FUN_000ce74c(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  if (param_2 == 0x3e) {
    return "loop   ";
  }
  if (param_2 < 0x3f) {
    if (param_2 == 0x35) {
      return "ifnz  ";
    }
    if (param_2 < 0x36) {
      if (param_2 == 8) {
        return "call   ";
      }
      if (param_2 == 9) {
        return "callnz ";
      }
    }
  }
  else if (param_2 == 0x53) {
    return "ret    ";
  }
  return "unknown";
}

/* FUN_000ce7a4 @ 0xce7a4 (588 bytes) */
int FUN_000ce7a4(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  undefined4 uVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = param_2[2];
  if (uVar3 == 0x35) {
    if (*param_2 == 0) {
      pcVar2 = "!=";
    }
    else {
      pcVar2 = "==";
    }
    ((int (*)())FUN_000cc200)(param_1,"          CF- IF  B%d %s 0, if = %d, else = %d, endif = %d",param_2[3],
                 pcVar2,param_2[4] + 1,param_2[5] + 1,param_2[6]);
    return;
  }
  if (uVar3 < 0x36) {
    if (uVar3 == 0x27) {
      return;
    }
    if (uVar3 < 0x28) {
      if (uVar3 == 8) {
        ((int (*)())FUN_000cc200)(param_1,"          CF- CALL at %d, subroutine from %d to %d",param_2[4],
                     param_2[5],param_2[6]);
        return;
      }
      if (uVar3 == 9) {
        if (*param_2 == 0) {
          pcVar2 = "!=";
        }
        else {
          pcVar2 = "==";
        }
        ((int (*)())FUN_000cc200)(param_1,"          CF- CALL at %d if B%d %s 0, subroutine from %d to %d",
                     param_2[4],param_2[3],pcVar2,param_2[5],param_2[6]);
        return;
      }
    }
    else if (uVar3 == 0x29) {
      return;
    }
  }
  else {
    if (uVar3 == 0x3e) {
      if (param_2[1] != 0) {
        ((int (*)())FUN_000cc200)(param_1,"          CF- Rep  I%d first in loop = %d last in loop = %d",
                     param_2[3],param_2[4] + 1,param_2[6]);
        return;
      }
      ((int (*)())FUN_000cc200)(param_1,"          CF- Loop I%d first in loop = %d last in loop = %d",param_2[3],
                   param_2[4] + 1,param_2[6]);
      return;
    }
    if (uVar3 == 0x53) {
      return;
    }
  }
  iVar4 = param_2[3];
  uVar1 = ((int (*)())FUN_000ce74c)(param_1,uVar3);
  ((int (*)())FUN_000cc200)(param_1,"\nNot = %d, op=%s(%d), reg =%d",*param_2,uVar1,uVar3,iVar4);
  iVar4 = param_2[4];
  ((int (*)())FUN_000cc200)(param_1," ifinst = %d begInst= %d callinst = %d",iVar4,iVar4,iVar4);
  ((int (*)())FUN_000cc200)(param_1," else=%d, labelinst=%d",param_2[5],param_2[5]);
  iVar4 = param_2[6];
  ((int (*)())FUN_000cc200)(param_1," endif= %d , endinst = %d, retinst = %d",iVar4,iVar4,iVar4);
  return;
}

/* FUN_000ce9f0 @ 0xce9f0 (238 bytes) */
int FUN_000ce9f0(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  undefined4 param_2;
  char *param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  char local_80 [112];
  
  *param_3 = '\0';
  iVar4 = *param_1;
  if ((*(int **)(iVar4 + 0x654) != (int *)0x0) && (iVar2 = **(int **)(iVar4 + 0x654), 0 < iVar2)) {
    iVar5 = 0;
    while( true ) {
      iVar4 = iVar5 * 0x1c + *(int *)(iVar4 + 0x654);
      if (*(int *)(iVar4 + 0x14) + 1 == param_1[1]) {
        ((int (*)())FUN_000ce7a4)(param_1,iVar4 + 4);
      }
      if (iVar2 == iVar5 + 1) break;
      iVar5 = iVar5 + 1;
      iVar4 = *param_1;
    }
  }
  _sprintf(local_80,"%3d:",param_1[1]);
  _strcat(param_3,local_80);
  param_1[1] = param_1[1] + 1;
  uVar3 = 0xffffffff;
  pcVar6 = param_3;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  ((int (*)())FUN_000cdb6a)(param_1,param_2,param_3 + (~uVar3 - 1),param_4,param_5);
  return;
}

/* FUN_000ceade @ 0xceade (1227 bytes) */
int FUN_000ceade(param_1, param_2)
  int *param_1;
  int param_2;
{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  char *pcVar9;
  int local_a8;
  int local_a4;
  char acStack_93 [22];
  char acStack_7d [23];
  undefined1 local_66 [22];
  undefined1 local_50 [21];
  char acStack_3b [23];
  int local_24;
  int local_20 [4];
  
  local_a4 = *(int *)(param_2 + 0x650);
  iVar5 = *(int *)(param_2 + 0x65c);
  *param_1 = param_2;
  ((int (*)())FUN_000cc200)(param_1,";*****************************************");
  ((int (*)())FUN_000cc200)(param_1,";              VS Disassembly             ");
  ((int (*)())FUN_000cc200)(param_1,";*****************************************");
  if (iVar5 != 0) {
    local_a8 = 0;
    pcVar3 = acStack_93 + 1;
    pcVar1 = acStack_3b + 1;
    pcVar2 = acStack_7d + 1;
    do {
      iVar6 = ((int (*)())FUN_000ce9f0)(param_1,local_a4,local_50,local_20,&local_24);
      if (iVar6 == 0) {
        if (local_20[0] == 0) {
          uVar7 = ((int (*)())FUN_000ccd90)(param_1,local_a4,pcVar3);
          uVar7 = ((int (*)())FUN_000cc2b4)(param_1,uVar7,pcVar1);
          uVar7 = ((int (*)())FUN_000cc2b4)(param_1,uVar7,pcVar2);
          local_a4 = ((int (*)())FUN_000cc2b4)(param_1,uVar7,local_66);
          if (local_24 != 1) {
            if (local_24 == 0) {
              ((int (*)())FUN_000cc200)(param_1,"%s %-10s",local_50,pcVar3);
            }
            else if (local_24 == 2) {
              uVar8 = 0xffffffff;
              pcVar9 = pcVar3;
              do {
                if (uVar8 == 0) break;
                uVar8 = uVar8 - 1;
                cVar4 = *pcVar9;
                pcVar9 = pcVar9 + 1;
              } while (cVar4 != '\0');
              (pcVar3 + (~uVar8 - 1))[0] = ',';
              (pcVar3 + (~uVar8 - 1))[1] = '\0';
              uVar8 = 0xffffffff;
              pcVar9 = pcVar1;
              do {
                if (uVar8 == 0) break;
                uVar8 = uVar8 - 1;
                cVar4 = *pcVar9;
                pcVar9 = pcVar9 + 1;
              } while (cVar4 != '\0');
              (pcVar1 + (~uVar8 - 1))[0] = ',';
              (pcVar1 + (~uVar8 - 1))[1] = '\0';
              ((int (*)())FUN_000cc200)(param_1,"%s %-10s%-15s%-15s",local_50,pcVar3,pcVar1,pcVar2);
            }
            else {
              uVar8 = 0xffffffff;
              pcVar9 = pcVar3;
              do {
                if (uVar8 == 0) break;
                uVar8 = uVar8 - 1;
                cVar4 = *pcVar9;
                pcVar9 = pcVar9 + 1;
              } while (cVar4 != '\0');
              (pcVar3 + (~uVar8 - 1))[0] = ',';
              (pcVar3 + (~uVar8 - 1))[1] = '\0';
              uVar8 = 0xffffffff;
              pcVar9 = pcVar1;
              do {
                if (uVar8 == 0) break;
                uVar8 = uVar8 - 1;
                cVar4 = *pcVar9;
                pcVar9 = pcVar9 + 1;
              } while (cVar4 != '\0');
              (pcVar1 + (~uVar8 - 1))[0] = ',';
              (pcVar1 + (~uVar8 - 1))[1] = '\0';
              uVar8 = 0xffffffff;
              pcVar9 = pcVar2;
              do {
                if (uVar8 == 0) break;
                uVar8 = uVar8 - 1;
                cVar4 = *pcVar9;
                pcVar9 = pcVar9 + 1;
              } while (cVar4 != '\0');
              (pcVar2 + (~uVar8 - 1))[0] = ',';
              (pcVar2 + (~uVar8 - 1))[1] = '\0';
              ((int (*)())FUN_000cc200)(param_1,"%s %-10s%-15s%-15s%s",local_50,pcVar3,pcVar1,pcVar2,local_66);
            }
            goto LAB_000ced18;
          }
          uVar8 = 0xffffffff;
          pcVar9 = pcVar3;
          do {
            if (uVar8 == 0) break;
            uVar8 = uVar8 - 1;
            cVar4 = *pcVar9;
            pcVar9 = pcVar9 + 1;
          } while (cVar4 != '\0');
          (pcVar3 + (~uVar8 - 1))[0] = ',';
          (pcVar3 + (~uVar8 - 1))[1] = '\0';
        }
        else {
          uVar7 = ((int (*)())FUN_000ccd90)(param_1,local_a4,pcVar3);
          uVar7 = ((int (*)())FUN_000cc2b4)(param_1,uVar7,pcVar1);
          uVar7 = ((int (*)())FUN_000cc2b4)(param_1,uVar7,pcVar2);
          uVar8 = 0xffffffff;
          pcVar9 = pcVar3;
          do {
            if (uVar8 == 0) break;
            uVar8 = uVar8 - 1;
            cVar4 = *pcVar9;
            pcVar9 = pcVar9 + 1;
          } while (cVar4 != '\0');
          (pcVar3 + (~uVar8 - 1))[0] = ',';
          (pcVar3 + (~uVar8 - 1))[1] = '\0';
          uVar8 = 0xffffffff;
          pcVar9 = pcVar1;
          do {
            if (uVar8 == 0) break;
            uVar8 = uVar8 - 1;
            cVar4 = *pcVar9;
            pcVar9 = pcVar9 + 1;
          } while (cVar4 != '\0');
          (pcVar1 + (~uVar8 - 1))[0] = ',';
          (pcVar1 + (~uVar8 - 1))[1] = '\0';
          ((int (*)())FUN_000cc200)(param_1,"%s %-10s%-15s%-15s",local_50,pcVar3,pcVar1,pcVar2);
          local_a4 = ((int (*)())FUN_000cd17a)(param_1,uVar7,local_50,pcVar3,pcVar1);
        }
        ((int (*)())FUN_000cc200)(param_1,"%s %-10s%-15s",local_50,pcVar3,pcVar1);
      }
      else {
        local_a4 = local_a4 + 0x10;
        ((int (*)())FUN_000cc200)(param_1,"%s",local_50);
      }
LAB_000ced18:
      local_a8 = local_a8 + 1;
    } while (iVar5 != local_a8);
  }
  ((int (*)())FUN_000cc200)(param_1,"");
  param_1[1] = 0;
  return 1;
}

/* FUN_000cefaa @ 0xcefaa (53 bytes) */
int FUN_000cefaa(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined1 local_1c [8];
  undefined4 local_14;
  undefined4 local_10;
  
  ((int (*)())FUN_000cc1dc)(local_1c);
  local_10 = param_1;
  local_14 = param_3;
  ((int (*)())FUN_000ccb40)(local_1c,param_2);
  return 0;
}

/* FUN_000cefe8 @ 0xcefe8 (53 bytes) */
int FUN_000cefe8(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined1 local_1c [8];
  undefined4 local_14;
  undefined4 local_10;
  
  ((int (*)())FUN_000cc1dc)(local_1c);
  local_10 = param_1;
  local_14 = param_4;
  ((int (*)())FUN_000ceade)(local_1c,param_2);
  return 0;
}

/* FUN_000cf028 @ 0xcf028 (105 bytes) */
int FUN_000cf028(param_1, param_2)
  undefined4 param_1;
  char *param_2;
{
  char local_10f [255];
  undefined1 *local_10;
  
  if (DAT_002106b8 != (undefined4 *)0x0) {
    local_10 = &STACKARG(0xc);
    _vsprintf(local_10f,param_2,local_10);
    (*(code *)*DAT_002106b8)(DAT_002106b4,"",local_10f,local_10);
  }
  return;
}

/* FUN_000cf092 @ 0xcf092 (5 bytes) */
int FUN_000cf092()
{
  return;
}

/* FUN_000cf098 @ 0xcf098 (78 bytes) */
int FUN_000cf098(param_1, param_2)
  char *param_1;
  uint param_2;
{
  if ((short)param_2 < 0) {
    _sprintf(param_1,"c%02u",param_2 & 0xffff7fff);
    return;
  }
  _sprintf(param_1,"r%02u",param_2);
  return;
}

/* FUN_000cf0e6 @ 0xcf0e6 (813 bytes) */
int FUN_000cf0e6(param_1)
  char *param_1;
{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  uint in_stack_00000014;
  int in_stack_00000018;
  char *local_34;
  undefined1 local_28 [6];
  char local_22 [18];
  
  if (in_stack_00000018 == 1) {
    builtin_strncpy(param_1,"neg(",5);
  }
  else if (in_stack_00000018 == 0) {
    *param_1 = '\0';
  }
  else if (in_stack_00000018 == 2) {
    builtin_strncpy(param_1,"abs(",5);
  }
  else if (in_stack_00000018 == 3) {
    builtin_strncpy(param_1,"nab(",5);
  }
  else {
    builtin_strncpy(param_1,"???(",5);
  }
  if (in_stack_00000014 < 0x20) {
    switch((switchdataD_000cf208)[in_stack_00000014] + 0xcf0f4) {
    case 0xcf3db:
      ((int (*)())FUN_000cf098)();
      break;
    case 0xcf3ee:
      ((int (*)())FUN_000cf098)();
      ((int (*)())FUN_000cf098)();
      break;
    case 0xcf40c:
      ((int (*)())FUN_000cf098)();
      ((int (*)())FUN_000cf098)();
      break;
    case 0xcf42b:
      ((int (*)())FUN_000cf098)();
      ((int (*)())FUN_000cf098)();
      break;
    case 0xcf44c:
      ((int (*)())FUN_000cf098)();
      break;
    case 0xcf45f:
      ((int (*)())FUN_000cf098)();
      break;
    case 0xcf474:
      ((int (*)())FUN_000cf098)();
      break;
    case 0xcf489:
      builtin_strncpy(local_22,"0.5",4);
      break;
    case 0xcf49b:
      builtin_strncpy(local_22,"1.0",4);
      break;
    case 0xcf4ad:
      builtin_strncpy(local_22,"0.0",4);
      break;
    case 0xcf4bf:
      builtin_strncpy(local_22,"srcp",5);
      break;
    case 0xcf4d5:
      builtin_strncpy(local_22,"srcp",5);
      break;
    case 0xcf4eb:
      ((int (*)())FUN_000cf098)();
      break;
    case 0xcf501:
      ((int (*)())FUN_000cf098)();
    }
  }
  else {
    builtin_strncpy(local_22,"???",4);
  }
  local_34 = local_22;
  uVar2 = 0xffffffff;
  pcVar3 = param_1;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  pcVar3 = param_1 + (~uVar2 - 1);
  switch(in_stack_00000014) {
  case 0:
  case 4:
  case 8:
  case 0xf:
    _sprintf(pcVar3,"%s.rgb",local_34);
    break;
  case 1:
  case 5:
  case 9:
  case 0x10:
    _sprintf(pcVar3,"%s.rrr",local_34);
    break;
  case 2:
  case 6:
  case 10:
  case 0x11:
    _sprintf(pcVar3,"%s.ggg",local_34);
    break;
  case 3:
  case 7:
  case 0xb:
  case 0x12:
    _sprintf(pcVar3,"%s.bbb",local_34);
    break;
  case 0xc:
  case 0xd:
  case 0xe:
  case 0x13:
    _sprintf(pcVar3,"%s.aaa",local_34);
    break;
  default:
    _strcpy(pcVar3,local_34);
    break;
  case 0x17:
  case 0x18:
  case 0x19:
    _sprintf(pcVar3,"%s.gbr",local_34);
    break;
  case 0x1a:
  case 0x1b:
  case 0x1c:
    _sprintf(pcVar3,"%s.brg",local_34);
    break;
  case 0x1d:
  case 0x1e:
  case 0x1f:
    _sprintf(pcVar3,"%s.a:%s.bg",local_34,local_28);
  }
  uVar2 = 0xffffffff;
  pcVar3 = param_1;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if (in_stack_00000018 != 0) {
    (param_1 + (~uVar2 - 1))[0] = ')';
    (param_1 + (~uVar2 - 1))[1] = '\0';
  }
  return;
}

/* FUN_000cf516 @ 0xcf516 (582 bytes) */
int FUN_000cf516(param_1)
  char *param_1;
{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  undefined4 in_stack_00000014;
  int in_stack_00000018;
  char *local_30;
  char local_22 [18];
  
  if (in_stack_00000018 == 1) {
    builtin_strncpy(param_1,"neg(",5);
  }
  else if (in_stack_00000018 == 0) {
    *param_1 = '\0';
  }
  else if (in_stack_00000018 == 2) {
    builtin_strncpy(param_1,"abs(",5);
  }
  else if (in_stack_00000018 == 3) {
    builtin_strncpy(param_1,"nab(",5);
  }
  else {
    builtin_strncpy(param_1,"???(",5);
  }
  switch(in_stack_00000014) {
  case 0:
  case 1:
  case 2:
    ((int (*)())FUN_000cf098)();
    break;
  case 3:
  case 4:
  case 5:
    ((int (*)())FUN_000cf098)();
    break;
  case 6:
  case 7:
  case 8:
    ((int (*)())FUN_000cf098)();
    break;
  case 9:
    ((int (*)())FUN_000cf098)();
    break;
  case 10:
    ((int (*)())FUN_000cf098)();
    break;
  case 0xb:
    ((int (*)())FUN_000cf098)();
    break;
  case 0xc:
  case 0xd:
  case 0xe:
    builtin_strncpy(local_22,"srcp",5);
    break;
  case 0xf:
    builtin_strncpy(local_22,"srcp",5);
    break;
  case 0x10:
    builtin_strncpy(local_22,"0.0",4);
    break;
  case 0x11:
    builtin_strncpy(local_22,"1.0",4);
    break;
  case 0x12:
    builtin_strncpy(local_22,"0.5",4);
    break;
  default:
    builtin_strncpy(local_22,"???",4);
  }
  local_30 = local_22;
  uVar2 = 0xffffffff;
  pcVar3 = param_1;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  pcVar3 = param_1 + (~uVar2 - 1);
  switch(in_stack_00000014) {
  case 0:
  case 3:
  case 6:
  case 0xc:
    _sprintf(pcVar3,"%s.r",local_30);
    break;
  case 1:
  case 4:
  case 7:
  case 0xd:
    _sprintf(pcVar3,"%s.g",local_30);
    break;
  case 2:
  case 5:
  case 8:
  case 0xe:
    _sprintf(pcVar3,"%s.b",local_30);
    break;
  case 9:
  case 10:
  case 0xb:
  case 0xf:
    _sprintf(pcVar3,"%s.a",local_30);
    break;
  default:
    _strcpy(pcVar3,local_30);
  }
  uVar2 = 0xffffffff;
  pcVar3 = param_1;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if (in_stack_00000018 != 0) {
    (param_1 + (~uVar2 - 1))[0] = ')';
    (param_1 + (~uVar2 - 1))[1] = '\0';
  }
  return;
}

/* FUN_000cf7ec @ 0xcf7ec (1312 bytes) */
int FUN_000cf7ec(param_1, param_2)
  int param_1;
  uint param_2;
{
  int iVar1;
  byte bVar2;
  byte bVar3;
  short sVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  bool bVar8;
  char cVar9;
  char cVar10;
  int *piVar11;
  uint uVar12;
  uint uVar13;
  char cVar14;
  uint *puVar15;
  uint uVar16;
  uint local_3c;
  uint local_38;
  undefined1 *local_28;
  uint local_24;
  uint local_20;
  
  if (param_2 <= (*(byte *)(param_1 + 0xf) & 0xf)) {
    return;
  }
  uVar5 = *(uint *)(param_1 + 8);
  if ((*(int *)(param_1 + 0x48) == 1) && (uVar5 != 0)) {
    piVar11 = (int *)(param_1 + 0x90);
    local_20 = 1;
    do {
      local_20 = local_20 + 1;
      if (*piVar11 != 1) goto LAB_000cf824;
      piVar11 = piVar11 + 0x12;
    } while (local_20 <= uVar5);
LAB_000cf9f5:
    bVar8 = false;
    bVar2 = 0;
    bVar7 = false;
  }
  else {
    local_20 = 1;
LAB_000cf824:
    if (uVar5 < local_20) goto LAB_000cf9f5;
    puVar15 = (uint *)(param_1 + local_20 * 0x48);
    local_38 = 0;
    local_3c = 0;
    bVar7 = false;
    bVar2 = 0;
    bVar8 = false;
    uVar16 = local_20;
    uVar12 = local_3c;
LAB_000cf89c:
    do {
      local_3c = uVar12;
      uVar12 = *puVar15;
      if (uVar12 < 5) {
        if (uVar12 < 3) {
          if (uVar12 != 2) goto LAB_000cf873;
          bVar2 = bVar2 | (byte)puVar15[1] | *(byte *)((int)puVar15 + 0x1b);
          if (*(char *)((int)puVar15 + 0x1a) != '\0') {
            bVar8 = (bool)(bVar8 | (puVar15[7] & 0xffff00) != 0);
          }
        }
        else {
          bVar2 = bVar2 | (byte)puVar15[1];
        }
      }
      else if (uVar12 == 5) {
        bVar2 = bVar2 | (byte)puVar15[1];
        if (!bVar7) {
          if ((*(char *)((int)puVar15 + 0xe) != '\0') || (*(char *)((int)puVar15 + 0x11) != '\0')) {
            bVar7 = true;
          }
          uVar12 = puVar15[4] & 0xff00ff;
          if ((uVar12 != 0) &&
             (((ushort)puVar15[3] < local_3c || (*(char *)((int)puVar15 + 0x19) != '\0')))) {
            bVar7 = true;
          }
          cVar9 = (char)puVar15[5];
          cVar10 = *(char *)((int)puVar15 + 0x15);
          cVar14 = cVar9;
          if ((uVar12 != 0) && (cVar14 = cVar10, uVar12 == 0xff0001)) {
            cVar9 = cVar10;
          }
          cVar10 = cVar14;
          if ((cVar9 == '\x01') || (cVar10 = cVar9, cVar9 != '\0')) {
            if (cVar10 == '\x02') goto LAB_000cfd03;
            if (cVar10 == '\x01') {
              local_38 = local_38 - *(byte *)((int)puVar15 + 0x13);
            }
          }
          else if (cVar14 == '\x02') {
LAB_000cfd03:
            local_38 = local_38 + 1;
          }
          if (4 < local_38) {
            bVar7 = true;
            uVar16 = uVar16 + 1;
            puVar15 = puVar15 + 0x12;
            uVar12 = local_3c + 1;
            if (uVar5 < uVar16) break;
            goto LAB_000cf89c;
          }
        }
      }
      else {
LAB_000cf873:
        ((int (*)())FUN_000cf028)(0,"Bad Instruction Type!");
      }
      uVar16 = uVar16 + 1;
      puVar15 = puVar15 + 0x12;
      uVar12 = local_3c + 1;
    } while (uVar16 <= uVar5);
    local_3c = local_3c + 1;
    if (local_3c != 0) {
      sVar4 = *(short *)(param_1 + 0x20);
      goto joined_r0x000cfa19;
    }
  }
  local_3c = 1;
  sVar4 = *(short *)(param_1 + 0x20);
joined_r0x000cfa19:
  if ((sVar4 == 0) && (*(short *)(param_1 + 0x12) == 0)) {
    *(short *)(param_1 + 0x12) = (short)local_3c + -1;
  }
  if (bVar7) {
    *(undefined2 *)(param_1 + 0x28) = 1;
  }
  if ((*(short *)(param_1 + 0x28) != 0) && (*(short *)(param_1 + 0x22) == 0)) {
    *(undefined2 *)(param_1 + 0x22) = 1;
  }
  if (local_20 <= uVar5) {
    puVar15 = (uint *)(param_1 + local_20 * 0x48);
    local_28 = (undefined1 *)((int)puVar15 + -3);
    local_24 = 0;
    uVar16 = 100000;
    uVar12 = local_20;
    do {
      uVar6 = *puVar15;
      uVar13 = uVar16;
      if (uVar6 < 5) {
        if (uVar6 < 3) {
          if (uVar6 == 2) {
            if (bVar8) {
              bVar3 = *(byte *)((int)puVar15 + 0x1f);
            }
            else {
              *(undefined1 *)((int)puVar15 + 0x1d) = 7;
              *(undefined1 *)((int)puVar15 + 0x1e) = 1;
              *(undefined1 *)((int)puVar15 + 0x15) = 0xe4;
              *(undefined1 *)(puVar15 + 5) = 0xe4;
              bVar3 = *(byte *)((int)puVar15 + 0x1f);
            }
            if (bVar3 != 0) {
              if ((bVar3 & 2) != 0) {
                *(byte *)((int)puVar15 + 0x15) =
                     *(byte *)((int)puVar15 + 0x15) & 0xf3 |
                     (*(byte *)((int)puVar15 + 0x15) & 3) << 2;
              }
              if ((*(byte *)((int)puVar15 + 0x1f) & 4) != 0) {
                *(byte *)((int)puVar15 + 0x15) =
                     *(byte *)((int)puVar15 + 0x15) & 0xcf |
                     (*(byte *)((int)puVar15 + 0x15) & 3) << 4;
              }
              if ((*(byte *)((int)puVar15 + 0x1f) & 8) != 0) {
                *(byte *)((int)puVar15 + 0x15) =
                     *(byte *)((int)puVar15 + 0x15) & 0x3f | *(byte *)((int)puVar15 + 0x15) << 6;
              }
            }
            uVar13 = uVar12;
            if (((bVar2 == 0) && ((char)puVar15[8] != '\0')) && (uVar16 != 100000)) {
              iVar1 = param_1 + uVar16 * 0x48;
              *(undefined1 *)(iVar1 + 0x1b) = 1;
              *(undefined1 *)(iVar1 + 4) = 1;
              *(undefined1 *)(puVar15 + 1) = 1;
            }
          }
        }
        else {
          if (((*(char *)((int)puVar15 + 0x15) == '\0') && ((puVar15[8] & 0xff00ff00) == 0)) &&
             (local_24 != *(ushort *)(param_1 + 0x12))) {
            *puVar15 = 4;
          }
          if ((bVar2 != 0) || (uVar16 == 100000)) goto LAB_000cfb6d;
          iVar1 = param_1 + uVar16 * 0x48;
          *(undefined1 *)(iVar1 + 0x1b) = 1;
          *(undefined1 *)(iVar1 + 4) = 1;
          *(undefined1 *)(puVar15 + 1) = 1;
          uVar13 = 100000;
        }
      }
      else if (uVar6 == 5) {
        if ((bVar2 == 0) && (uVar16 != 100000)) {
          iVar1 = param_1 + uVar16 * 0x48;
          *(undefined1 *)(iVar1 + 0x1b) = 1;
          *(undefined1 *)(iVar1 + 4) = 1;
          *(undefined1 *)(puVar15 + 1) = 1;
        }
        if ((byte)(*(byte *)((int)puVar15 + 0x12) & 0xf0) ==
            (byte)(*(byte *)((int)puVar15 + 0x12) * '\x10')) {
LAB_000cfb6d:
          uVar13 = 100000;
        }
        else if (local_24 == 0) {
          ((int (*)())FUN_000cf028)(0,"FC ALU result test is first US instruction");
          uVar13 = 100000;
        }
        else if (*(int *)(local_28 + -0x45) - 3U < 2) {
          *local_28 = 1;
          uVar13 = 100000;
        }
        else {
          ((int (*)())FUN_000cf028)(0,"FC ALU result test follows non-ALU instruction");
          uVar13 = 100000;
        }
      }
      local_24 = local_24 + 1;
      uVar12 = uVar12 + 1;
      puVar15 = puVar15 + 0x12;
      local_28 = local_28 + 0x48;
      uVar16 = uVar13;
    } while (uVar12 <= uVar5);
    if (((local_24 != 0) &&
        (piVar11 = (int *)(param_1 + (*(ushort *)(param_1 + 0x12) + local_20) * 0x48), *piVar11 == 3
        )) && (bVar2 == 0)) {
      *(undefined1 *)(piVar11 + 1) = 1;
    }
  }
  if (((bVar8) || (bVar2 != 0)) || (*(short *)(param_1 + 0x20) != 0)) {
    (*(unsigned char *)((unsigned char *)&(param_2) + 0)) = (byte)param_2 | (byte)(param_2 << 4);
  }
  *(byte *)(param_1 + 0xf) = (byte)param_2;
  return;
}

/* FUN_000cfd0c @ 0xcfd0c (44 bytes) */
int FUN_000cfd0c(param_1)
  int param_1;
{
  if (((((byte)param_1 & 7) != 3) && (((byte)param_1 & 0x38) != 0x18)) &&
     ((param_1 & 0x1c0) != 0xc0)) {
    return 0;
  }
  return 1;
}

/* FUN_000cfd38 @ 0xcfd38 (793 bytes) */
int FUN_000cfd38(param_1, param_2)
  char *param_1;
  uint param_2;
{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  longdouble lVar5;
  longdouble lVar6;
  double dVar7;
  double dVar8;
  float local_38;
  char local_2b [10];
  undefined1 local_21;
  undefined1 local_20;
  char local_1f;
  char local_1e;
  undefined1 uStack_1d;
  
  if ((short)param_2 < 0) {
    _sprintf(param_1,"c%02u",param_2 & 0xffff7fff);
    return;
  }
  if ((param_2 & 0x4000) == 0) {
    if ((param_2 & 0x2000) != 0) {
      lVar5 = (longdouble)FUN_000d9a14(param_2 & 0xffffdfff);
      local_38 = (float)lVar5;
      if ((local_38 != 0.0) || (NAN(local_38))) {
        if (local_38 < 0.0) {
          local_2b[0] = '-';
          local_38 = -local_38;
        }
        else {
          local_2b[0] = '+';
        }
        lVar5 = (longdouble)
                _pow(0,0x40000000,(double)(int)((((uint)local_38 & 0x7f800000) >> 0x17) - 0x7f));
        lVar5 = (longdouble)_log((double)lVar5);
        lVar6 = (longdouble)_log(0,0x40240000);
        lVar5 = (longdouble)_floor((double)lVar5 / (double)lVar6);
        iVar4 = (int)lVar5;
        dVar7 = (double)iVar4;
        lVar5 = (longdouble)_pow(0,0x40240000,dVar7);
        dVar8 = (double)local_38 / (double)lVar5 + DOUBLE_001cf3c0;
        if (DOUBLE_001cf370 <= dVar8) {
          iVar4 = iVar4 + 1;
          dVar7 = (double)iVar4;
          lVar5 = (longdouble)_pow(0,0x40240000,dVar7);
          dVar8 = (double)local_38 / (double)lVar5 + DOUBLE_001cf3c0;
        }
        lVar5 = (longdouble)_floor(dVar8,dVar7,dVar8);
        iVar2 = (int)lVar5;
        local_2b[1] = (char)iVar2 + '0';
        local_2b[2] = 0x2e;
        iVar3 = 3;
        do {
          dVar8 = (dVar8 - (double)iVar2) * DOUBLE_001cf370;
          lVar5 = (longdouble)_floor(dVar8);
          iVar2 = (int)lVar5;
          local_2b[iVar3] = (char)iVar2 + '0';
          iVar3 = iVar3 + 1;
        } while (iVar3 != 10);
        if (iVar4 < 0) {
          local_20 = 0x2d;
          iVar4 = -iVar4;
        }
        else {
          local_20 = 0x2b;
        }
        cVar1 = (char)(iVar4 / 10);
        local_1f = cVar1 + '0';
        local_1e = (char)iVar4 + cVar1 * -10 + '0';
      }
      else {
        local_2b[0] = ' ';
        local_2b[1] = '0';
        local_2b[2] = 0x2e;
        iVar4 = 3;
        do {
          local_2b[iVar4] = '0';
          iVar4 = iVar4 + 1;
        } while (iVar4 != 10);
        local_20 = 0x2b;
        local_1f = '0';
        local_1e = '0';
      }
      local_21 = 0x45;
      uStack_1d = 0;
      _sprintf(param_1,"(%s)",local_2b);
      return;
    }
    _sprintf(param_1,"r%02u",param_2);
    return;
  }
  _sprintf(param_1,"r[AL+%02u]",param_2 & 0xffffbfff);
  return;
}

/* FUN_000d0052 @ 0xd0052 (509 bytes) */
int FUN_000d0052(param_1)
  char *param_1;
{
  char cVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  int in_stack_00000014;
  int in_stack_00000018;
  uint in_stack_0000001c;
  int in_stack_00000020;
  undefined4 local_2e;
  undefined1 local_2a;
  
  if (in_stack_00000018 == 1) {
    builtin_strncpy(param_1,"neg(",5);
  }
  else if (in_stack_00000018 == 0) {
    *param_1 = '\0';
  }
  else if (in_stack_00000018 == 2) {
    builtin_strncpy(param_1,"abs(",5);
  }
  else if (in_stack_00000018 == 3) {
    builtin_strncpy(param_1,"nab(",5);
  }
  else {
    builtin_strncpy(param_1,"???(",5);
  }
  if (in_stack_00000020 - 0xbU < 2) {
LAB_000d00a5:
    ((int (*)())FUN_000cfd38)();
  }
  else {
    iVar3 = ((int (*)())FUN_000cfd0c)();
    if (iVar3 == 0) {
      if (in_stack_00000014 == 1) {
        ((int (*)())FUN_000cfd38)();
        goto LAB_000d00af;
      }
      if (in_stack_00000014 == 0) goto LAB_000d00a5;
      if (in_stack_00000014 == 2) {
        ((int (*)())FUN_000cfd38)();
        goto LAB_000d00af;
      }
    }
    else {
      if (in_stack_00000014 == 1) {
        ((int (*)())FUN_000cfd38)();
        goto LAB_000d00af;
      }
      if (in_stack_00000014 == 0) {
        ((int (*)())FUN_000cfd38)();
        goto LAB_000d00af;
      }
      if (in_stack_00000014 == 2) {
        ((int (*)())FUN_000cfd38)();
        goto LAB_000d00af;
      }
    }
    if (in_stack_00000014 == 3) {
      local_2e = 0x70637273;
      local_2a = 0;
    }
    else {
      local_2e = 0x3f3f3f;
    }
  }
LAB_000d00af:
  uVar4 = 0xffffffff;
  pcVar5 = param_1;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar2 = (ushort)in_stack_0000001c & 0x1ff;
  if (((uVar2 == 0x124) || (uVar2 == 0x1b6)) || (uVar2 == 0x16d)) {
    _strcpy(param_1 + (~uVar4 - 1),&DAT_001eefa0 + (in_stack_0000001c & 7) * 4);
  }
  else {
    _sprintf(param_1 + (~uVar4 - 1),"%s.%s%s%s",&local_2e,
             &DAT_001eefa0 + (in_stack_0000001c & 7) * 4,
             &DAT_001eefa0 + (in_stack_0000001c >> 3 & 7) * 4,
             &DAT_001eefa0 + (in_stack_0000001c >> 6 & 7) * 4);
  }
  uVar4 = 0xffffffff;
  pcVar5 = param_1;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  if (in_stack_00000018 != 0) {
    (param_1 + (~uVar4 - 1))[0] = ')';
    (param_1 + (~uVar4 - 1))[1] = '\0';
  }
  return;
}

/* FUN_000d0250 @ 0xd0250 (477 bytes) */
int FUN_000d0250(param_1)
  char *param_1;
{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int in_stack_00000014;
  int in_stack_00000018;
  int in_stack_0000001c;
  int in_stack_00000020;
  undefined4 local_2e;
  undefined1 local_2a;
  
  if (in_stack_00000018 == 1) {
    builtin_strncpy(param_1,"neg(",5);
LAB_000d0276:
    if (in_stack_00000020 - 0xeU < 2) goto LAB_000d0320;
LAB_000d0285:
    if (in_stack_0000001c == 3) {
      if (in_stack_00000014 == 1) {
        ((int (*)())FUN_000cfd38)();
      }
      else {
        if (in_stack_00000014 == 0) goto LAB_000d0320;
        if (in_stack_00000014 != 2) goto LAB_000d02a7;
        ((int (*)())FUN_000cfd38)();
      }
    }
    else if (in_stack_00000014 == 1) {
      ((int (*)())FUN_000cfd38)();
    }
    else if (in_stack_00000014 == 0) {
      ((int (*)())FUN_000cfd38)();
    }
    else if (in_stack_00000014 == 2) {
      ((int (*)())FUN_000cfd38)();
    }
    else {
LAB_000d02a7:
      if (in_stack_00000014 != 3) {
        local_2e = 0x3f3f3f;
        uVar2 = 0xffffffff;
        pcVar3 = param_1;
        do {
          if (uVar2 == 0) break;
          uVar2 = uVar2 - 1;
          cVar1 = *pcVar3;
          pcVar3 = pcVar3 + 1;
        } while (cVar1 != '\0');
        goto joined_r0x000d0380;
      }
      local_2e = 0x70637273;
      local_2a = 0;
    }
  }
  else {
    if (in_stack_00000018 == 0) {
      *param_1 = '\0';
      goto LAB_000d0276;
    }
    if (in_stack_00000018 == 2) {
      builtin_strncpy(param_1,"abs(",5);
      goto LAB_000d0276;
    }
    if (in_stack_00000018 == 3) {
      builtin_strncpy(param_1,"nab(",5);
      goto LAB_000d0276;
    }
    builtin_strncpy(param_1,"???(",5);
    if (1 < in_stack_00000020 - 0xeU) goto LAB_000d0285;
LAB_000d0320:
    ((int (*)())FUN_000cfd38)();
  }
  uVar2 = 0xffffffff;
  pcVar3 = param_1;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
joined_r0x000d0380:
  if (in_stack_0000001c - 4U < 3) {
    _strcpy(param_1 + (~uVar2 - 1),&DAT_001eefa0 + in_stack_0000001c * 4);
  }
  else {
    _sprintf(param_1 + (~uVar2 - 1),"%s.%s",&local_2e,&DAT_001eefa0 + in_stack_0000001c * 4);
  }
  uVar2 = 0xffffffff;
  pcVar3 = param_1;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if (in_stack_00000018 != 0) {
    (param_1 + (~uVar2 - 1))[0] = ')';
    (param_1 + (~uVar2 - 1))[1] = '\0';
  }
  return;
}

/* FUN_000d042e @ 0xd042e (18194 bytes) */
int FUN_000d042e(param_1, param_2, param_3)
  undefined4 *param_1;
  uint param_2;
  uint *param_3;
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  byte bVar5;
  byte bVar6;
  char cVar7;
  byte bVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  undefined1 uVar11;
  undefined1 uVar12;
  byte bVar13;
  char cVar14;
  char cVar15;
  ushort uVar16;
  undefined2 uVar17;
  undefined2 uVar18;
  undefined2 uVar19;
  bool bVar20;
  bool bVar21;
  bool bVar22;
  bool bVar23;
  bool bVar24;
  bool bVar25;
  int iVar26;
  int iVar27;
  byte bVar28;
  char cVar29;
  char *pcVar30;
  uint *puVar31;
  uint uVar32;
  uint uVar33;
  uint *puVar34;
  undefined1 *puVar35;
  uint *puVar36;
  int iVar37;
  int iVar38;
  char *pcVar39;
  uint uVar40;
  byte bVar41;
  uint *puVar42;
  uint *puVar43;
  uint uVar44;
  uint uVar45;
  uint uVar46;
  uint *puVar47;
  uint uVar48;
  char *pcVar49;
  bool bVar50;
  undefined4 *puVar51;
  undefined **ppuVar52;
  int *piVar53;
  int iVar54;
  int *piVar55;
  uint *puVar56;
  uint *puVar57;
  uint *puVar58;
  uint *puVar59;
  uint *in_stack_fffffc3c;
  undefined2 uVar60;
  char *local_390;
  char *local_34c;
  char *local_344;
  byte local_33f;
  byte local_33e;
  byte local_33d;
  uint *local_33c;
  char *local_32c;
  char *local_328;
  char *local_324;
  char *local_320;
  uint local_318;
  int local_2fc;
  int local_2b4;
  uint local_2a8;
  uint *local_2a4;
  uint local_29c;
  int *local_238;
  int *local_220;
  int *local_21c;
  uint *local_218;
  int *local_20c;
  uint local_1f0;
  uint *local_1e8;
  int local_1e4;
  int local_1e0;
  char local_1dc [100];
  uint local_178 [8];
  uint local_158 [8];
  uint local_138 [8];
  uint local_118 [8];
  uint local_f8 [8];
  uint local_d8 [8];
  uint local_b8 [8];
  uint local_98 [3];
  char local_89 [15];
  uint local_7a [3];
  uint local_6b [3];
  uint local_5c;
  undefined4 local_58;
  undefined1 local_54;
  uint local_52;
  undefined4 local_4e;
  undefined2 local_4a;
  uint local_48;
  undefined4 local_44;
  undefined2 local_40;
  undefined2 local_3e;
  undefined1 local_3c;
  uint local_34;
  undefined2 local_30;
  uint local_2a;
  undefined4 local_26;
  undefined2 local_22;
  undefined2 local_20;
  undefined1 local_1e;
  
  ((int (*)())FUN_000cf7ec)(param_1,1);
  if ((*(byte *)((int)param_1 + 0xf) & 0x10) == 0) {
    uVar48 = param_1[2];
    uVar40 = param_2;
    puVar42 = param_3;
    ((int (*)())FUN_000cf028)(0,"======== Begin Loki NSF pixel shader dump: %s: %d ========\n",param_2,param_3);
    if (*(short *)(param_1 + 5) == 0) {
      ((int (*)())FUN_000cf028)(0," Shader stats not valid\n \n",uVar40,puVar42);
    }
    else {
      ((int (*)())FUN_000cf028)(0," Shader stats:\n",uVar40,puVar42);
      ((int (*)())FUN_000cf028)(0,"     Levels:                 %2d\n",*(undefined2 *)((int)param_1 + 0x16));
      ((int (*)())FUN_000cf028)(0,"     RS Instructions:        %2d\n",*(undefined2 *)(param_1 + 6));
      ((int (*)())FUN_000cf028)(0,"     TEX Instructions:      %3d\n",*(undefined2 *)((int)param_1 + 0x1a));
      ((int (*)())FUN_000cf028)(0,"     ALU Instructions:      %3d\n",*(undefined2 *)(param_1 + 7));
      ((int (*)())FUN_000cf028)(0,"     ALU Instruction slots: %3d\n",*(undefined2 *)((int)param_1 + 0x1e));
      ((int (*)())FUN_000cf028)(0,"     Pix Size:               %2d\n",*(undefined2 *)((int)param_1 + 0x22));
      ((int (*)())FUN_000cf028)(0,"     Highest Const:          %2d\n",*(undefined2 *)(param_1 + 9));
      ((int (*)())FUN_000cf028)(0,"     Nominal cycle count:    %2d\n",*(undefined2 *)((int)param_1 + 0x26));
      ((int (*)())FUN_000cf028)(0,"     Tex lookup counts:     ");
      iVar54 = 0x10;
      puVar51 = param_1;
      do {
        uVar40 = (uint)*(byte *)((int)puVar51 + 0x2a);
        ((int (*)())FUN_000cf028)(0," %2d",uVar40);
        puVar51 = (undefined4 *)((int)puVar51 + 1);
        iVar54 = iVar54 + -1;
      } while (iVar54 != 0);
      ((int (*)())FUN_000cf028)(0,"\n \n",uVar40);
    }
    ((int (*)())FUN_000cf028)(0," RS Instructions:\n \n",uVar40,puVar42);
    if ((param_1[0x12] == 1) && (uVar48 != 0)) {
      local_20c = param_1 + 0x24;
      local_29c = 1;
      piVar53 = param_1 + 0x12;
      piVar55 = local_20c;
      do {
        uVar40 = local_29c - 1;
        ((int (*)())FUN_000cf028)(0,"   rs %02d:",uVar40,puVar42);
        if (*(char *)((int)piVar53 + 0xb) == '\0') {
          if (*(char *)((int)piVar53 + 9) != '\0') {
            ((int (*)())FUN_000cf028)(0,"                         ",uVar40);
            goto LAB_000d32c4;
          }
LAB_000d31d3:
          ((int (*)())FUN_000cf028)(0,"\n",uVar40,puVar42);
        }
        else {
          uVar32 = (uint)*(byte *)((int)piVar53 + 10);
          puVar42 = (uint *)((*(byte *)((int)piVar53 + 0xf) & 0xf ^ 0xf) * 5 + 0x1eefc0);
          uVar40 = (uint)*(ushort *)((int)piVar53 + 6);
          ((int (*)())FUN_000cf028)(0,"  r%02d.%s = col%02ld",uVar40,puVar42,uVar32);
          if (*(char *)((int)piVar53 + 0xd) == '\0') {
            if (*(char *)((int)piVar53 + 0xb) == '\x02') {
              ((int (*)())FUN_000cf028)(0," fbuf  ",uVar40,puVar42,uVar32);
            }
            else if (*(char *)((int)piVar53 + 0xb) == '\x03') {
              ((int (*)())FUN_000cf028)(0," back  ",uVar40,puVar42,uVar32);
            }
            else {
              if (*(char *)((int)piVar53 + 9) == '\0') goto LAB_000d31d3;
              ((int (*)())FUN_000cf028)(0,"       ",uVar40,puVar42,uVar32);
            }
          }
          else {
            ((int (*)())FUN_000cf028)(0," biased",uVar40,puVar42,uVar32);
          }
LAB_000d32c4:
          if (*(char *)((int)piVar53 + 9) == '\0') goto LAB_000d31d3;
          uVar32 = (uint)*(byte *)(piVar53 + 2);
          puVar42 = (uint *)((*(byte *)((int)piVar53 + 0xe) & 0xf ^ 0xf) * 5 + 0x1eefc0);
          uVar40 = (uint)*(ushort *)(piVar53 + 1);
          ((int (*)())FUN_000cf028)(0,"   r%02d.%s = txc%02ld",uVar40,puVar42,uVar32);
          if ((char)piVar53[3] == '\0') goto LAB_000d31d3;
          ((int (*)())FUN_000cf028)(0," adjusted\n",uVar40,puVar42,uVar32);
        }
        local_29c = local_29c + 1;
        if (*local_20c != 1) break;
        local_20c = local_20c + 0x12;
        piVar53 = piVar55;
        piVar55 = piVar55 + 0x12;
      } while (local_29c <= uVar48);
    }
    else {
      local_29c = 1;
    }
    ((int (*)())FUN_000cf028)(0," \n US Program:\n",uVar40,puVar42);
    if (local_29c <= uVar48) {
      local_218 = param_1 + local_29c * 0x12;
      local_2a8 = 0;
      bVar20 = true;
      local_2a4 = (uint *)0x0;
      local_1f0 = 0;
      do {
        while( true ) {
          if (((*local_218 == 2) && ((bVar20 || ((char)local_218[8] != '\0')))) || (local_2a8 == 0))
          {
            if (local_2a8 < 0x34) {
              (*(unsigned char *)((unsigned char *)&(local_20) + 1)) = '\0';
            }
            else {
              local_1e = 0;
              (*(unsigned char *)((unsigned char *)&(local_20) + 1)) = (char)(local_2a8 / 0x34) + '/';
            }
            cVar29 = (char)(local_2a8 % 0x34);
            if (local_2a8 % 0x34 < 0x1a) {
              cVar29 = cVar29 + 'A';
            }
            else {
              cVar29 = cVar29 + 'G';
            }
            local_20 = CONCAT11((*(unsigned char *)((unsigned char *)&(local_20) + 1)),cVar29);
            local_2a8 = local_2a8 + 1;
            ((int (*)())FUN_000cf028)(0," \n   Level %s:\n",&local_20,puVar42);
          }
          uVar40 = *local_218;
          bVar20 = uVar40 - 3 < 2;
          if (uVar40 == 2) break;
          if ((1 < uVar40) && (uVar40 < 5)) {
            switch(*(undefined1 *)((int)local_218 + 0x31)) {
            case 0:
            case 3:
            case 7:
            case 8:
              bVar24 = false;
              bVar23 = false;
              bVar21 = true;
              bVar50 = true;
              bVar22 = true;
              break;
            case 1:
            case 4:
            case 5:
              bVar24 = false;
              bVar23 = false;
              bVar21 = true;
              bVar50 = true;
              bVar22 = false;
              break;
            case 2:
              bVar24 = true;
              bVar23 = true;
              bVar21 = true;
              bVar50 = true;
              bVar22 = false;
              break;
            default:
              bVar24 = false;
              bVar23 = false;
              bVar21 = false;
              bVar50 = false;
              bVar22 = false;
              break;
            case 9:
              bVar24 = false;
              bVar23 = false;
              bVar21 = true;
              bVar50 = false;
              bVar22 = false;
            }
            bVar25 = false;
            if ((byte)local_218[0x10] < 0xc) {
              uVar40 = 1 << ((byte)local_218[0x10] & 0x1f);
              if ((uVar40 & 0x61) == 0) {
                if ((uVar40 & 0xc) == 0) {
                  if ((uVar40 & 0xf80) != 0) {
                    bVar23 = true;
                  }
                }
                else {
                  bVar25 = false;
                  bVar24 = true;
                  bVar23 = true;
                }
              }
              else {
                bVar25 = true;
                bVar24 = true;
                bVar23 = true;
              }
            }
            uVar60 = *(undefined2 *)((int)local_218 + 0x12);
            uVar17 = *(undefined2 *)((int)local_218 + 0x1a);
            puVar43 = (uint *)(uint)(ushort)local_218[7];
            puVar31 = (uint *)(uint)*(ushort *)((int)local_218 + 0x1e);
            uVar44 = (uint)*(byte *)((int)local_218 + 0x2a);
            uVar32 = (uint)*(byte *)((int)local_218 + 0x2b);
            uVar45 = (uint)(byte)local_218[0xb];
            uVar33 = (uint)*(byte *)((int)local_218 + 0x39);
            uVar46 = (uint)*(byte *)((int)local_218 + 0x3a);
            puVar47 = (uint *)(uint)*(byte *)((int)local_218 + 0x3b);
            uVar9 = *(undefined1 *)((int)local_218 + 0x2d);
            uVar10 = *(undefined1 *)((int)local_218 + 0x2e);
            uVar11 = *(undefined1 *)((int)local_218 + 0x2f);
            uVar40 = local_218[0xf];
            uVar12 = *(undefined1 *)((int)local_218 + 0x3d);
            puVar36 = (uint *)(uint)*(byte *)((int)local_218 + 0x3e);
            bVar1 = bVar21 && uVar44 == 0x13;
            bVar21 = bVar21 && uVar44 - 0xf < 4;
            if (bVar50) {
              bVar21 = bVar21 || uVar32 - 0xf < 4;
              bVar1 = bVar1 || uVar32 == 0x13;
            }
            if (bVar22) {
              bVar21 = (bool)(bVar21 | uVar45 - 0xf < 4);
              bVar1 = (bool)(bVar1 | uVar45 == 0x13);
            }
            if (bVar23) {
              bVar21 = (bool)(bVar21 | uVar33 - 0xc < 3);
              bVar1 = (bool)(bVar1 | uVar33 == 0xf);
            }
            if (bVar24) {
              bVar21 = (bool)(bVar21 | uVar46 - 0xc < 3);
              bVar1 = (bool)(bVar1 | uVar46 == 0xf);
            }
            if (bVar25) {
              bVar21 = (bool)(bVar21 | puVar47 + -3 < (uint *)((int)&MACH_HEADER.magic + 3));
              bVar1 = (bool)(bVar1 | puVar47 == (uint *)((int)&MACH_HEADER.filetype + 3));
            }
            if (bVar21) {
              puVar34 = local_2a4;
              ((int (*)())FUN_000cf028)(0,"     alu %02d pre:  srcp.rgb = ",local_2a4,puVar42);
              cVar29 = (char)local_218[0xc];
              if (cVar29 == '\x01') {
                puVar42 = &local_34;
                ((int (*)())FUN_000cf098)();
                ((int (*)())FUN_000cf098)();
                ((int (*)())FUN_000cf028)(0,"%s.rgb-%s.rgb\n",&local_3e,puVar42);
              }
              else if (cVar29 == '\0') {
                ((int (*)())FUN_000cf098)();
                ((int (*)())FUN_000cf028)(0,"1.0-2.0*%s.rgb\n",&local_34);
              }
              else if (cVar29 == '\x02') {
                puVar42 = &local_34;
                ((int (*)())FUN_000cf098)();
                ((int (*)())FUN_000cf098)();
                ((int (*)())FUN_000cf028)(0,"%s.rgb+%s.rgb\n",&local_3e,puVar42);
              }
              else if (cVar29 == '\x03') {
                ((int (*)())FUN_000cf098)();
                ((int (*)())FUN_000cf028)(0,"1.0-%s.rgb\n",&local_34);
              }
              else {
                ((int (*)())FUN_000cf028)(0,"???\n",puVar34);
              }
            }
            if (bVar1) {
              puVar34 = local_2a4;
              ((int (*)())FUN_000cf028)(0,"     alu %02d pre:  srcp.a   = ",local_2a4,puVar42);
              cVar29 = *(char *)((int)local_218 + 0x3f);
              if (cVar29 == '\x01') {
                puVar42 = &local_34;
                ((int (*)())FUN_000cf098)();
                ((int (*)())FUN_000cf098)();
                ((int (*)())FUN_000cf028)(0,"%s.a-%s.a\n",&local_3e,puVar42);
              }
              else if (cVar29 == '\0') {
                ((int (*)())FUN_000cf098)();
                ((int (*)())FUN_000cf028)(0,"1.0-2.0*%s.a\n",&local_34,puVar42);
              }
              else if (cVar29 == '\x02') {
                puVar42 = &local_34;
                ((int (*)())FUN_000cf098)();
                ((int (*)())FUN_000cf098)();
                ((int (*)())FUN_000cf028)(0,"%s.a+%s.a\n",&local_3e,puVar42);
              }
              else if (cVar29 == '\x03') {
                ((int (*)())FUN_000cf098)();
                ((int (*)())FUN_000cf028)(0,"1.0-%s.a\n",&local_34,puVar42);
              }
              else {
                ((int (*)())FUN_000cf028)(0,"???\n",puVar34,puVar42);
              }
            }
            puVar34 = local_2a4;
            ((int (*)())FUN_000cf028)(0,"     alu %02d rgb:  ",local_2a4,puVar42);
            bVar6 = (byte)local_218[5];
            if (*(byte *)((int)local_218 + 0x15) == 0) {
              ((int (*)())FUN_000cf028)(0,"           ",puVar34,puVar42);
              if (bVar6 == 0) goto LAB_000d29ea;
LAB_000d0ed9:
              puVar42 = (uint *)((uint)bVar6 * 4 + 0x1eef80);
              puVar34 = (uint *)(uint)(ushort)local_218[3];
              ((int (*)())FUN_000cf028)(0,"r%02d.%s = ",puVar34,puVar42);
              cVar29 = *(char *)((int)local_218 + 0x33);
            }
            else {
              puVar42 = (uint *)((uint)*(byte *)((int)local_218 + 0x15) * 4 + 0x1eef80);
              puVar34 = (uint *)(uint)*(byte *)((int)local_218 + 0x16);
              ((int (*)())FUN_000cf028)(0,"out%d.%s = ",puVar34,puVar42);
              if (bVar6 != 0) goto LAB_000d0ed9;
LAB_000d29ea:
              ((int (*)())FUN_000cf028)(0,"          ",puVar34,puVar42);
              cVar29 = *(char *)((int)local_218 + 0x33);
            }
            if (cVar29 != '\0') {
              ((int (*)())FUN_000cf028)(0,"clamped ",puVar34,puVar42);
            }
            puVar34 = local_f8;
            ((int (*)())FUN_000cf0e6)(uVar60,uVar17,puVar43,puVar31,uVar44,uVar9);
            puVar58 = local_118;
            ((int (*)())FUN_000cf0e6)(uVar60,uVar17,puVar43,puVar31,uVar32,uVar10);
            puVar57 = local_138;
            ((int (*)())FUN_000cf0e6)(uVar60,uVar17,puVar43,puVar31,uVar45,uVar11);
            puVar56 = local_158;
            ((int (*)())FUN_000cf516)(uVar60,uVar17,puVar43,puVar31,uVar33,(char)uVar40);
            puVar42 = local_178;
            ((int (*)())FUN_000cf516)(uVar60,uVar17,puVar43,puVar31,uVar46,uVar12);
            puVar59 = local_b8;
            ((int (*)())FUN_000cf516)(uVar60,uVar17,puVar43,puVar31,puVar47,puVar36);
            switch(*(undefined1 *)((int)local_218 + 0x31)) {
            case 0:
              ((int (*)())FUN_000cf028)(0,"mad(%s, %s, %s)",puVar34,puVar58,puVar57);
              break;
            case 1:
              ((int (*)())FUN_000cf028)(0,"dp3(%s, %s)",puVar34,puVar58);
              puVar57 = puVar47;
              break;
            case 2:
              puVar31 = puVar56;
              puVar57 = puVar58;
              puVar36 = puVar42;
              ((int (*)())FUN_000cf028)(0,"dp4(%s:%s, %s:%s)",puVar34,puVar56,puVar58,puVar42);
              puVar58 = puVar31;
              break;
            case 3:
              ((int (*)())FUN_000cf028)(0,"d2a(%s, %s, %s)",puVar34,puVar58,puVar57);
              break;
            case 4:
              ((int (*)())FUN_000cf028)(0,"min(%s, %s)",puVar34,puVar58);
              puVar57 = puVar47;
              break;
            case 5:
              ((int (*)())FUN_000cf028)(0,"max(%s, %s)",puVar34,puVar58);
              puVar57 = puVar47;
              break;
            default:
              ((int (*)())FUN_000cf028)(0,"???()");
              puVar34 = puVar43;
              puVar58 = puVar31;
              puVar57 = puVar47;
              break;
            case 7:
              ((int (*)())FUN_000cf028)(0,"cnd(%s, %s, %s)",puVar34,puVar58,puVar57);
              break;
            case 8:
              ((int (*)())FUN_000cf028)(0,"cmp(%s, %s, %s)",puVar34,puVar58,puVar57);
              break;
            case 9:
              ((int (*)())FUN_000cf028)(0,"frc(%s)",puVar34);
              puVar58 = puVar31;
              puVar57 = puVar47;
              break;
            case 10:
              ((int (*)())FUN_000cf028)(0,"sop()");
              puVar34 = puVar43;
              puVar58 = puVar31;
              puVar57 = puVar47;
            }
            switch(*(undefined1 *)((int)local_218 + 0x32)) {
            case 0:
              ((int (*)())FUN_000cf028)(0,"\n",puVar34,puVar58,puVar57,puVar36);
              break;
            case 1:
              ((int (*)())FUN_000cf028)(0,"*2\n",puVar34,puVar58,puVar57,puVar36);
              break;
            case 2:
              ((int (*)())FUN_000cf028)(0,"*4\n",puVar34,puVar58,puVar57,puVar36);
              break;
            case 3:
              ((int (*)())FUN_000cf028)(0,"*8\n",puVar34,puVar58,puVar57,puVar36);
              break;
            case 4:
              ((int (*)())FUN_000cf028)(0,"/2\n",puVar34,puVar58,puVar57,puVar36);
              break;
            case 5:
              ((int (*)())FUN_000cf028)(0,"/4\n",puVar34,puVar58,puVar57,puVar36);
              break;
            case 6:
              ((int (*)())FUN_000cf028)(0,"/8\n",puVar34,puVar58,puVar57,puVar36);
              break;
            default:
              ((int (*)())FUN_000cf028)(0,"*???\n",puVar34,puVar58,puVar57,puVar36);
            }
            puVar31 = local_2a4;
            ((int (*)())FUN_000cf028)(0,"          alpha:  ",local_2a4,puVar58,puVar57,puVar36);
            uVar40 = local_218[8];
            cVar29 = *(char *)((int)local_218 + 0x21);
            cVar15 = *(char *)((int)local_218 + 0x23);
            if (cVar29 != '\0') {
              puVar31 = (uint *)(uint)*(byte *)((int)local_218 + 0x22);
              ((int (*)())FUN_000cf028)(0,"out%d.a   = ",puVar31);
            }
            if (cVar15 != '\0') {
              ((int (*)())FUN_000cf028)(0,"depth    = ",puVar31);
            }
            if ((cVar29 == '\0') && (cVar15 == '\0')) {
              ((int (*)())FUN_000cf028)(0,"           ",puVar31);
            }
            if ((char)uVar40 == '\0') {
              ((int (*)())FUN_000cf028)(0,"          ",puVar31);
              cVar29 = *(char *)((int)local_218 + 0x42);
            }
            else {
              puVar31 = (uint *)(uint)(ushort)local_218[6];
              ((int (*)())FUN_000cf028)(0,"r%02d.a   = ",puVar31);
              cVar29 = *(char *)((int)local_218 + 0x42);
            }
            if (cVar29 != '\0') {
              ((int (*)())FUN_000cf028)(0,"clamped ",puVar31);
            }
            switch((char)local_218[0x10]) {
            case '\0':
              ((int (*)())FUN_000cf028)(0,"mad(%s, %s, %s)",puVar56,puVar42,puVar59);
              break;
            case '\x01':
              ((int (*)())FUN_000cf028)(0,"dp()",puVar31);
              puVar56 = puVar31;
              puVar42 = puVar58;
              puVar59 = puVar57;
              break;
            case '\x02':
              ((int (*)())FUN_000cf028)(0,"min(%s, %s)",puVar56,puVar42);
              puVar59 = puVar57;
              break;
            case '\x03':
              ((int (*)())FUN_000cf028)(0,"max(%s, %s)",puVar56,puVar42);
              puVar59 = puVar57;
              break;
            default:
              ((int (*)())FUN_000cf028)(0,"???()",puVar31);
              puVar56 = puVar31;
              puVar42 = puVar58;
              puVar59 = puVar57;
              break;
            case '\x05':
              ((int (*)())FUN_000cf028)(0,"cnd(%s, %s, %s)",puVar56,puVar42,puVar59);
              break;
            case '\x06':
              ((int (*)())FUN_000cf028)(0,"cmp(%s, %s, %s)",puVar56,puVar42,puVar59);
              break;
            case '\a':
              ((int (*)())FUN_000cf028)(0,"frc(%s)",puVar56);
              puVar42 = puVar58;
              puVar59 = puVar57;
              break;
            case '\b':
              ((int (*)())FUN_000cf028)(0,"ex2(%s)",puVar56);
              puVar42 = puVar58;
              puVar59 = puVar57;
              break;
            case '\t':
              ((int (*)())FUN_000cf028)(0,"ln2(%s)",puVar56);
              puVar42 = puVar58;
              puVar59 = puVar57;
              break;
            case '\n':
              ((int (*)())FUN_000cf028)(0,"rcp(%s)",puVar56);
              puVar42 = puVar58;
              puVar59 = puVar57;
              break;
            case '\v':
              ((int (*)())FUN_000cf028)(0,"rsq(%s)",puVar56);
              puVar42 = puVar58;
              puVar59 = puVar57;
            }
            switch(*(undefined1 *)((int)local_218 + 0x41)) {
            case 0:
              ((int (*)())FUN_000cf028)(0,"\n",puVar56,puVar42,puVar59);
              break;
            case 1:
              ((int (*)())FUN_000cf028)(0,"*2\n",puVar56,puVar42,puVar59);
              break;
            case 2:
              ((int (*)())FUN_000cf028)(0,"*4\n",puVar56,puVar42,puVar59);
              break;
            case 3:
              ((int (*)())FUN_000cf028)(0,"*8\n",puVar56,puVar42,puVar59);
              break;
            case 4:
              ((int (*)())FUN_000cf028)(0,"/2\n",puVar56,puVar42,puVar59);
              break;
            case 5:
              ((int (*)())FUN_000cf028)(0,"/4\n",puVar56,puVar42,puVar59);
              break;
            case 6:
              ((int (*)())FUN_000cf028)(0,"/8\n",puVar56,puVar42,puVar59);
              break;
            default:
              ((int (*)())FUN_000cf028)(0,"*???\n",puVar56,puVar42,puVar59);
            }
            if ((char)local_218[0xd] != '\0') {
              ((int (*)())FUN_000cf028)(0,"     alu %02d post-NOP\n",local_2a4,puVar42,puVar59);
            }
            local_2a4 = (uint *)((int)local_2a4 + 1);
          }
          local_29c = local_29c + 1;
          local_218 = local_218 + 0x12;
          if (uVar48 < local_29c) goto LAB_000d1369;
        }
        uVar40 = local_1f0;
        ((int (*)())FUN_000cf028)(0,"     tex %02d    :  ",local_1f0,puVar42);
        uVar60 = *(undefined2 *)((int)local_218 + 0xe);
        uVar32 = (uint)(ushort)local_218[3];
        uVar9 = *(undefined1 *)((int)local_218 + 0x19);
        if ((*(byte *)((int)local_218 + 0x1a) < 5) &&
           ((1 << (*(byte *)((int)local_218 + 0x1a) & 0x1f) & 0x1aU) != 0)) {
          ((int (*)())FUN_000cf028)(0,"r%02d.rgba = ",uVar32);
          uVar40 = uVar32;
        }
        uVar32 = *(byte *)((int)local_218 + 0x1f) & 0xf ^ 0xf;
        switch(*(undefined1 *)((int)local_218 + 0x1a)) {
        case 0:
          ((int (*)())FUN_000cf028)(0,"NOP\n",uVar40);
          break;
        case 1:
          puVar42 = (uint *)(uVar32 * 5 + 0x1eefc0);
          ((int (*)())FUN_000cf028)(0,"lookup(r%02d.%s, tex%02d)\n",uVar60,puVar42,uVar9);
          break;
        case 2:
          puVar42 = (uint *)(uVar32 * 5 + 0x1eefc0);
          ((int (*)())FUN_000cf028)(0,"kill(r%02d.%s)\n",uVar60,puVar42);
          break;
        case 3:
          puVar42 = (uint *)(uVar32 * 5 + 0x1eefc0);
          ((int (*)())FUN_000cf028)(0,"lookup_proj(r%02d.%s, tex%02d)\n",uVar60,puVar42,uVar9);
          break;
        case 4:
          puVar42 = (uint *)(uVar32 * 5 + 0x1eefc0);
          ((int (*)())FUN_000cf028)(0,"lookup_lodbias(r%02d.%s, tex%02d)\n",uVar60,puVar42,uVar9);
          break;
        default:
          ((int (*)())FUN_000cf028)(0,"???()\n",uVar40);
        }
        local_1f0 = local_1f0 + 1;
        local_29c = local_29c + 1;
        local_218 = local_218 + 0x12;
      } while (local_29c <= uVar48);
    }
LAB_000d1369:
    ((int (*)())FUN_000cf028)(0,"======== End   Loki NSF pixel shader dump: %s: %d ========\n",param_2,param_3);
    uVar48 = param_1[2];
    uVar40 = param_2;
    puVar42 = param_3;
    ((int (*)())FUN_000cf028)(0,"+++ BEGIN_PSN                       # \"%s\" %d\n",param_2,param_3);
    uVar32 = 0;
    do {
      switch(*param_1) {
      case 0:
        puVar42 = (uint *)param_1[2];
        uVar40 = param_1[1];
        ((int (*)())FUN_000cf028)(0,
                     "+++ R300PSN_INST_HEADER : %08x %08x %02x %02x %04x %04x %04x %04x %04x %04x %04x\n"
                     ,uVar40,puVar42,*(undefined1 *)(param_1 + 3),
                     *(undefined1 *)((int)param_1 + 0xd),*(undefined2 *)(param_1 + 5),
                     *(undefined2 *)((int)param_1 + 0x16),*(undefined2 *)(param_1 + 6),
                     *(undefined2 *)((int)param_1 + 0x1a),*(undefined2 *)(param_1 + 7),
                     *(undefined2 *)((int)param_1 + 0x1e),*(undefined2 *)((int)param_1 + 0x22));
        break;
      case 1:
        puVar42 = (uint *)(uint)*(ushort *)((int)param_1 + 6);
        uVar40 = (uint)*(ushort *)(param_1 + 1);
        ((int (*)())FUN_000cf028)(0,
                     "+++ R300PSN_INST_RS     : %04x %04x %02x %02x %02x %02x %02x %02x %02x %02x\n"
                     ,uVar40,puVar42,*(undefined1 *)(param_1 + 2),*(undefined1 *)((int)param_1 + 9),
                     *(undefined1 *)((int)param_1 + 10),*(undefined1 *)((int)param_1 + 0xb),
                     *(undefined1 *)(param_1 + 3),*(undefined1 *)((int)param_1 + 0xd),
                     *(undefined1 *)((int)param_1 + 0xe),*(undefined1 *)((int)param_1 + 0xf));
        break;
      case 2:
        puVar42 = (uint *)(uint)*(ushort *)((int)param_1 + 0xe);
        uVar40 = (uint)*(ushort *)(param_1 + 3);
        ((int (*)())FUN_000cf028)(0,"+++ R300PSN_INST_TEX    : %04x %04x %02x %02x %02x %02x\n",uVar40,puVar42,
                     *(undefined1 *)((int)param_1 + 0x19),*(undefined1 *)((int)param_1 + 0x1a),
                     *(undefined1 *)((int)param_1 + 0x1f),*(undefined1 *)(param_1 + 8));
        break;
      case 3:
      case 4:
        ((int (*)())FUN_000cf028)(0,"+++ R300PSN_INST_ALU    : \n",uVar40,puVar42);
        ((int (*)())FUN_000cf028)(0,"+++ RGB_ADDR            : %04x %04x %04x %04x %02x %02x %02x\n",
                     *(undefined2 *)(param_1 + 3),*(undefined2 *)((int)param_1 + 0xe),
                     *(undefined2 *)(param_1 + 4),*(undefined2 *)((int)param_1 + 0x12),
                     *(undefined1 *)(param_1 + 5),*(undefined1 *)((int)param_1 + 0x15),
                     *(undefined1 *)((int)param_1 + 0x16));
        ((int (*)())FUN_000cf028)(0,"+++ ALPHA_ADDR          : %04x %04x %04x %04x %02x %02x %02x %02x\n",
                     *(undefined2 *)(param_1 + 6),*(undefined2 *)((int)param_1 + 0x1a),
                     *(undefined2 *)(param_1 + 7),*(undefined2 *)((int)param_1 + 0x1e),
                     *(undefined1 *)(param_1 + 8),*(undefined1 *)((int)param_1 + 0x21),
                     *(undefined1 *)((int)param_1 + 0x22),*(undefined1 *)((int)param_1 + 0x23));
        ((int (*)())FUN_000cf028)(0,
                     "+++ RGB_INST            : %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n"
                     ,*(undefined1 *)((int)param_1 + 0x2a),*(undefined1 *)((int)param_1 + 0x2d),
                     *(undefined1 *)((int)param_1 + 0x2b),*(undefined1 *)((int)param_1 + 0x2e),
                     *(undefined1 *)(param_1 + 0xb),*(undefined1 *)((int)param_1 + 0x2f),
                     *(undefined1 *)(param_1 + 0xc),*(undefined1 *)((int)param_1 + 0x31),
                     *(undefined1 *)((int)param_1 + 0x32),*(undefined1 *)((int)param_1 + 0x33),
                     *(undefined1 *)(param_1 + 0xd));
        puVar42 = (uint *)(uint)*(byte *)(param_1 + 0xf);
        uVar40 = (uint)*(byte *)((int)param_1 + 0x39);
        ((int (*)())FUN_000cf028)(0,
                     "+++ ALPHA_INST          : %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n"
                     ,uVar40,puVar42,*(undefined1 *)((int)param_1 + 0x3a),
                     *(undefined1 *)((int)param_1 + 0x3d),*(undefined1 *)((int)param_1 + 0x3b),
                     *(undefined1 *)((int)param_1 + 0x3e),*(undefined1 *)((int)param_1 + 0x3f),
                     *(undefined1 *)(param_1 + 0x10),*(undefined1 *)((int)param_1 + 0x41),
                     *(undefined1 *)((int)param_1 + 0x42));
      }
      uVar32 = uVar32 + 1;
      param_1 = param_1 + 0x12;
    } while (uVar32 <= uVar48);
    ((int (*)())FUN_000cf028)(0,"+++ END_PSN                         # \"%s\" %d\n",param_2,param_3);
    return;
  }
  iVar54 = param_1[2];
  ((int (*)())FUN_000cf028)(0,"======== Begin r520 neutral format pixel shader: %d =============\n",param_3);
  if (*(short *)(param_1 + 5) == 0) {
    ((int (*)())FUN_000cf028)(0," Shader stats not valid\n \n",param_3);
  }
  else {
    ((int (*)())FUN_000cf028)(0," Shader stats:\n",param_3);
    ((int (*)())FUN_000cf028)(0,"     RS Instructions:        %2d\n",*(undefined2 *)(param_1 + 6));
    ((int (*)())FUN_000cf028)(0,"     TEX Instructions:      %3d\n",*(undefined2 *)((int)param_1 + 0x1a));
    ((int (*)())FUN_000cf028)(0,"     ALU Instructions:      %3d\n",*(undefined2 *)(param_1 + 7));
    ((int (*)())FUN_000cf028)(0,"     ALU Instruction slots: %3d\n",*(undefined2 *)((int)param_1 + 0x1e));
    if (*(char *)((int)param_1 + 0xe) != '\0') {
      ((int (*)())FUN_000cf028)(0,"     UMRT_EN:               %3d\n",*(char *)((int)param_1 + 0xe));
    }
    ((int (*)())FUN_000cf028)(0,"     CF Instructions:       %3d\n",*(undefined2 *)(param_1 + 8));
    ((int (*)())FUN_000cf028)(0,"     Pix Size:               %2d\n",*(undefined2 *)((int)param_1 + 0x22));
    ((int (*)())FUN_000cf028)(0,"     Highest Const:          %2d\n",*(undefined2 *)(param_1 + 9));
    ((int (*)())FUN_000cf028)(0,"     Start Addr:            %3d\n",*(undefined2 *)(param_1 + 4));
    param_3 = (uint *)(uint)*(ushort *)((int)param_1 + 0x12);
    ((int (*)())FUN_000cf028)(0,"     End Addr:              %3d\n",param_3);
    ((int (*)())FUN_000cf028)(0," \n");
  }
  ((int (*)())FUN_000cf028)(0," RS Instructions:\n \n",param_3);
  if ((param_1[0x12] == 1) && (0 < iVar54)) {
    local_21c = param_1 + 0x24;
    local_2fc = 1;
    piVar53 = param_1 + 0x12;
    local_220 = local_21c;
    do {
      param_3 = (uint *)(local_2fc + -1);
      ((int (*)())FUN_000cf028)(0,"   rs %02d:",param_3);
      cVar29 = *(char *)((int)piVar53 + 0xb);
      if (cVar29 == '\0') {
        if (*(char *)((int)piVar53 + 9) != '\0') {
          ((int (*)())FUN_000cf028)(0,"                         ",param_3);
          goto LAB_000d343e;
        }
LAB_000d339b:
        ((int (*)())FUN_000cf028)(0,"\n",param_3);
      }
      else {
        uVar48 = *(byte *)((int)piVar53 + 0xf) & 0xf ^ 0xf;
        if (cVar29 == '\x01') {
          uVar40 = (uint)*(byte *)((int)piVar53 + 10);
          iVar37 = uVar48 * 5 + 0x1eefc0;
          param_3 = (uint *)(uint)*(ushort *)((int)piVar53 + 6);
          ((int (*)())FUN_000cf028)(0,"  r%02d.%s = col%02ld",param_3,iVar37,uVar40);
          if (*(char *)((int)piVar53 + 0xd) == '\0') {
            cVar29 = *(char *)((int)piVar53 + 0xb);
          }
          else {
            ((int (*)())FUN_000cf028)(0," biased",param_3,iVar37,uVar40);
            cVar29 = *(char *)((int)piVar53 + 0xb);
          }
        }
        if (cVar29 == '\x02') {
          param_3 = (uint *)(uint)*(ushort *)((int)piVar53 + 6);
          ((int (*)())FUN_000cf028)(0,"  r%02d.%s = fbuf",param_3,uVar48 * 5 + 0x1eefc0);
        }
        else if (cVar29 == '\x03') {
          param_3 = (uint *)(uint)*(ushort *)((int)piVar53 + 6);
          ((int (*)())FUN_000cf028)(0,"  r%02d.%s = back",param_3,uVar48 * 5 + 0x1eefc0);
        }
        else {
          if (*(char *)((int)piVar53 + 9) == '\0') goto LAB_000d339b;
          ((int (*)())FUN_000cf028)(0,"       ",param_3);
        }
LAB_000d343e:
        if (*(char *)((int)piVar53 + 9) == '\0') goto LAB_000d339b;
        uVar48 = (uint)*(byte *)(piVar53 + 2);
        iVar37 = (*(byte *)((int)piVar53 + 0xe) & 0xf ^ 0xf) * 5 + 0x1eefc0;
        param_3 = (uint *)(uint)*(ushort *)(piVar53 + 1);
        ((int (*)())FUN_000cf028)(0,"   r%02d.%s = txc%02ld",param_3,iVar37,uVar48);
        if ((char)piVar53[3] == '\0') goto LAB_000d339b;
        ((int (*)())FUN_000cf028)(0," adjusted\n",param_3,iVar37,uVar48);
      }
      local_2fc = local_2fc + 1;
      if (*local_21c != 1) break;
      local_21c = local_21c + 0x12;
      piVar53 = local_220;
      local_220 = local_220 + 0x12;
    } while (local_2fc <= iVar54);
  }
  else {
    local_2fc = 1;
  }
  ((int (*)())FUN_000cf028)(0," \n US Program:\n",param_3);
  ((int (*)())FUN_000cf028)(0,"\n\n");
  if (local_2fc <= iVar54) {
    local_238 = param_1 + local_2fc * 0x12;
    bVar6 = 0;
    local_318 = 0;
    local_1e8 = (uint *)0x0;
    local_1e4 = 0;
    local_1e0 = 0;
    cVar29 = '\0';
    cVar15 = '\0';
    do {
      if ((char)local_238[7] == '\0') {
        local_5c = local_5c & 0xffffff00;
        if ((char)local_238[1] != '\0') goto LAB_000d0635;
LAB_000d058e:
        local_2a = local_2a & 0xffffff00;
        if (*(char *)((int)local_238 + 0xb) != '\0') goto LAB_000d0659;
LAB_000d05a2:
        local_52 = local_52 & 0xffffff00;
        iVar37 = *local_238;
      }
      else {
        local_5c = 0x6e676920;
        local_58 = 0x636e755f;
        local_54 = 0;
        if ((char)local_238[1] == '\0') goto LAB_000d058e;
LAB_000d0635:
        local_2a = 0x6d657320;
        local_26 = 0x6961775f;
        local_22 = 0x74;
        if (*(char *)((int)local_238 + 0xb) == '\0') goto LAB_000d05a2;
LAB_000d0659:
        local_52 = 0x756c6120;
        local_4e = 0x6961775f;
        local_4a = 0x74;
        iVar37 = *local_238;
      }
      if (iVar37 == 2) {
        ((int (*)())FUN_000cf028)(0,"  %d tex %02d    :  ",local_318,local_1e4);
        uVar16 = *(ushort *)((int)local_238 + 0xe);
        param_3 = (uint *)(uint)uVar16;
        iVar37 = local_238[3];
        puVar42 = (uint *)(uint)*(byte *)((int)local_238 + 0x19);
        bVar5 = *(byte *)(local_238 + 5);
        local_33d = *(byte *)((int)local_238 + 0x1d);
        bVar28 = (byte)(local_33d | *(char *)((int)local_238 + 0x1e) << 3) >> 3 & 1;
        if (bVar28 == 0) {
          local_34c = "_";
          local_33f = (local_33d & 4) >> 2;
          if (local_33f != 0) goto LAB_000d2ac1;
LAB_000d0718:
          local_344 = "_";
          local_33e = (local_33d & 2) >> 1;
          if (local_33e != 0) goto LAB_000d2ae8;
LAB_000d0736:
          pcVar49 = "_";
          if ((local_33d & 1) != 0) goto LAB_000d2b06;
LAB_000d074b:
          pcVar39 = "_";
        }
        else {
          local_34c = &DAT_001eefa0 + (uint)(bVar5 >> 6) * 4;
          local_33f = (local_33d & 4) >> 2;
          if (local_33f == 0) goto LAB_000d0718;
LAB_000d2ac1:
          local_344 = &DAT_001eefa0 + (bVar5 >> 4 & 3) * 4;
          local_33e = (local_33d & 2) >> 1;
          if (local_33e == 0) goto LAB_000d0736;
LAB_000d2ae8:
          pcVar49 = &DAT_001eefa0 + (bVar5 >> 2 & 3) * 4;
          if ((local_33d & 1) == 0) goto LAB_000d074b;
LAB_000d2b06:
          pcVar39 = &DAT_001eefa0 + (bVar5 & 3) * 4;
        }
        local_33d = local_33d & 1;
        _sprintf(local_89,"%s%s%s%s",pcVar39,pcVar49,local_344,local_34c);
        if ((*(byte *)((int)local_238 + 0x1a) < 7) &&
           ((1 << (*(byte *)((int)local_238 + 0x1a) & 0x1f) & 0x7aU) != 0)) {
          ((int (*)())FUN_000cf028)(0,"r%02d.%s = ",(short)iVar37,local_89);
        }
        if (*(char *)((int)local_238 + 0x1a) == '\x02') {
          bVar5 = *(byte *)((int)local_238 + 0x15);
          if (bVar28 == 0) {
            local_33c = (uint *)0x1b72a8;
          }
          else {
            local_33c = (uint *)(&DAT_001eefa0 + (uint)(bVar5 >> 6) * 4);
          }
          if (local_33f == 0) {
            pcVar49 = "-";
          }
          else {
            pcVar49 = &DAT_001eefa0 + (bVar5 >> 4 & 3) * 4;
          }
          if (local_33e == 0) {
            pcVar39 = "-";
          }
          else {
            pcVar39 = &DAT_001eefa0 + (bVar5 >> 2 & 3) * 4;
          }
          if (local_33d == 0) {
            pcVar30 = "-";
          }
          else {
            pcVar30 = &DAT_001eefa0 + (bVar5 & 3) * 4;
          }
        }
        else {
          bVar6 = *(byte *)((int)local_238 + 0x1f);
          bVar5 = *(byte *)((int)local_238 + 0x15);
          if ((bVar6 & 1) == 0) {
            local_33c = (uint *)(&DAT_001eefa0 + (uint)(bVar5 >> 6) * 4);
            pcVar49 = &DAT_001eefa0 + (bVar5 >> 4 & 3) * 4;
            pcVar39 = &DAT_001eefa0 + (bVar5 >> 2 & 3) * 4;
            pcVar30 = &DAT_001eefa0 + (bVar5 & 3) * 4;
          }
          else {
            pcVar30 = "-";
            pcVar39 = pcVar30;
            pcVar49 = pcVar30;
            local_33c = (uint *)pcVar30;
          }
        }
        puVar36 = local_98;
        _sprintf((char *)puVar36,"%s%s%s%s",pcVar30,pcVar39,pcVar49,local_33c);
        if ((uVar16 & 0x4000) == 0) {
          _sprintf((char *)local_6b,"r%02d",param_3,pcVar39,pcVar49,local_33c);
          if (*(char *)((int)local_238 + 0x1b) == '\0') goto LAB_000d0898;
LAB_000d3160:
          local_48 = 0x6d657320;
          local_44 = 0x6172675f;
          local_40 = 0x62;
        }
        else {
          param_3 = (uint *)((uint)param_3 & 0xffffbfff);
          _sprintf((char *)local_6b,"r[AL+%02d]",param_3,pcVar39,pcVar49,local_33c);
          if (*(char *)((int)local_238 + 0x1b) != '\0') goto LAB_000d3160;
LAB_000d0898:
          local_48 = local_48 & 0xffffff00;
        }
        puVar31 = local_6b;
        switch(*(char *)((int)local_238 + 0x1a)) {
        case '\0':
          ((int (*)())FUN_000cf028)(0,"NOP\n");
          break;
        case '\x01':
          in_stack_fffffc3c = &local_48;
          local_33c = &local_2a;
          ((int (*)())FUN_000cf028)(0,"lookup(%s.%s, tex%02d)%s%s%s%s",puVar31,puVar36,puVar42,local_33c,
                       in_stack_fffffc3c,&local_52,&local_5c);
          param_3 = puVar31;
          pcVar39 = (char *)puVar36;
          pcVar49 = (char *)puVar42;
          break;
        case '\x02':
          in_stack_fffffc3c = &local_52;
          local_33c = &local_48;
          pcVar49 = (char *)&local_2a;
          ((int (*)())FUN_000cf028)(0,"kill(%s.%s)%s%s%s",puVar31,puVar36,pcVar49,local_33c,in_stack_fffffc3c);
          param_3 = puVar31;
          pcVar39 = (char *)puVar36;
          break;
        case '\x03':
          in_stack_fffffc3c = &local_48;
          local_33c = &local_2a;
          ((int (*)())FUN_000cf028)(0,"lookup_proj(%s.%s, tex%02d)%s%s%s%s",puVar31,puVar36,puVar42,local_33c,
                       in_stack_fffffc3c,&local_52,&local_5c);
          param_3 = puVar31;
          pcVar39 = (char *)puVar36;
          pcVar49 = (char *)puVar42;
          break;
        case '\x04':
          in_stack_fffffc3c = &local_48;
          local_33c = &local_2a;
          ((int (*)())FUN_000cf028)(0,"lookup_lodbias(%s.%s, tex%02d)%s%s%s%s",puVar31,puVar36,puVar42,local_33c,
                       in_stack_fffffc3c,&local_52,&local_5c);
          param_3 = puVar31;
          pcVar39 = (char *)puVar36;
          pcVar49 = (char *)puVar42;
          break;
        case '\x05':
          in_stack_fffffc3c = &local_48;
          local_33c = &local_2a;
          ((int (*)())FUN_000cf028)(0,"lookup_lod(%s.%s, tex%02d)%s%s%s%s",puVar31,puVar36,puVar42,local_33c,
                       in_stack_fffffc3c,&local_52,&local_5c);
          param_3 = puVar31;
          pcVar39 = (char *)puVar36;
          pcVar49 = (char *)puVar42;
          break;
        case '\x06':
          bVar5 = *(byte *)((int)local_238 + 0x16);
          if ((bVar6 & 1) == 0) {
            local_32c = &DAT_001eefa0 + (uint)(bVar5 >> 6) * 4;
            local_328 = &DAT_001eefa0 + (bVar5 >> 4 & 3) * 4;
            pcVar39 = &DAT_001eefa0 + (bVar5 >> 2 & 3) * 4;
            pcVar49 = &DAT_001eefa0 + (bVar5 & 3) * 4;
          }
          else {
            pcVar49 = "-";
            pcVar39 = pcVar49;
            local_32c = pcVar49;
            local_328 = pcVar49;
          }
          local_33c = local_7a;
          _sprintf((char *)local_33c,"%s%s%s%s",pcVar49,pcVar39,local_328,local_32c);
          pcVar49 = (char *)(uint)*(ushort *)(local_238 + 4);
          bVar5 = *(byte *)((int)local_238 + 0x16);
          if ((bVar6 & 1) == 0) {
            local_324 = &DAT_001eefa0 + (uint)(bVar5 >> 6) * 4;
            local_320 = &DAT_001eefa0 + (bVar5 >> 4 & 3) * 4;
            pcVar30 = &DAT_001eefa0 + (bVar5 >> 2 & 3) * 4;
            pcVar39 = &DAT_001eefa0 + (bVar5 & 3) * 4;
          }
          else {
            pcVar39 = "-";
            pcVar30 = pcVar39;
            local_324 = pcVar39;
            local_320 = pcVar39;
          }
          _sprintf((char *)local_b8,"%s%s%s%s",pcVar39,pcVar30,local_320,local_324);
          in_stack_fffffc3c = (uint *)(uint)*(ushort *)((int)local_238 + 0x12);
          ((int (*)())FUN_000cf028)(0,"lookup_dxdy(%s.%s, r%02d.%s, r%02d.%s,  tex%02d)%s%s%s%s",puVar31,puVar36,
                       pcVar49,local_33c,in_stack_fffffc3c,local_b8,puVar42,&local_2a,&local_48,
                       &local_52,&local_5c);
          param_3 = puVar31;
          pcVar39 = (char *)puVar36;
          break;
        case '\a':
          in_stack_fffffc3c = &local_48;
          local_33c = &local_2a;
          ((int (*)())FUN_000cf028)(0,"lookup_uncached(%s.%s, tex%02d)%s%s%s%s",puVar31,puVar36,puVar42,local_33c
                       ,in_stack_fffffc3c,&local_52,&local_5c);
          param_3 = puVar31;
          pcVar39 = (char *)puVar36;
          pcVar49 = (char *)puVar42;
          break;
        default:
          local_33c = &local_5c;
          pcVar49 = (char *)&local_52;
          pcVar39 = (char *)&local_48;
          param_3 = &local_2a;
          ((int (*)())FUN_000cf028)(0,"UNKNOWN_OP%s%s%s%s",param_3,pcVar39,pcVar49,local_33c);
        }
        if (*(char *)((int)local_238 + 5) != '\0') {
          if (*(char *)((int)local_238 + 6) == '\0') {
            local_20 = 0x70;
          }
          else {
            local_20 = 0x7021;
            local_1e = 0;
          }
          switch(*(undefined1 *)((int)local_238 + 5)) {
          case 1:
            param_3 = (uint *)&local_20;
            ((int (*)())FUN_000cf028)(0," %s.rgb",param_3,pcVar39,pcVar49,local_33c);
            break;
          case 2:
            param_3 = (uint *)&local_20;
            ((int (*)())FUN_000cf028)(0," %s.rrr",param_3,pcVar39,pcVar49,local_33c);
            break;
          case 3:
            param_3 = (uint *)&local_20;
            ((int (*)())FUN_000cf028)(0," %s.ggg",param_3,pcVar39,pcVar49,local_33c);
            break;
          case 4:
            param_3 = (uint *)&local_20;
            ((int (*)())FUN_000cf028)(0," %s.bbb",param_3,pcVar39,pcVar49,local_33c);
            break;
          case 5:
            param_3 = (uint *)&local_20;
            ((int (*)())FUN_000cf028)(0," %s.aaa",param_3,pcVar39,pcVar49,local_33c);
          }
        }
        if (*(char *)((int)local_238 + 7) != '\0') {
          if ((char)local_238[2] == '\0') {
            local_20 = 0x70;
          }
          else {
            local_20 = 0x7021;
            local_1e = 0;
          }
          switch(*(undefined1 *)((int)local_238 + 7)) {
          case 1:
          case 5:
            param_3 = (uint *)&local_20;
            ((int (*)())FUN_000cf028)(0," %s.a",param_3,pcVar39,pcVar49,local_33c);
            break;
          case 2:
            param_3 = (uint *)&local_20;
            ((int (*)())FUN_000cf028)(0," %s.r",param_3,pcVar39,pcVar49,local_33c);
            break;
          case 3:
            param_3 = (uint *)&local_20;
            ((int (*)())FUN_000cf028)(0," %s.g",param_3,pcVar39,pcVar49,local_33c);
            break;
          case 4:
            param_3 = (uint *)&local_20;
            ((int (*)())FUN_000cf028)(0," %s.b",param_3,pcVar39,pcVar49,local_33c);
          }
        }
        if (*(char *)((int)local_238 + 9) != '\0') {
          ((int (*)())FUN_000cf028)(0," write_inactive",param_3,pcVar39,pcVar49,local_33c);
        }
        ((int (*)())FUN_000cf028)(0,"\n",param_3);
        local_1e4 = local_1e4 + 1;
      }
      uVar60 = (undefined2)((uint)in_stack_fffffc3c >> 0x10);
      if ((*local_238 == 3) || (*local_238 == 4)) {
        cVar29 = *(char *)((int)local_238 + 0x43);
        cVar15 = (char)local_238[0x11];
        puVar35 = (undefined1 *)((int)local_238 + 0x31);
        switch(*(undefined1 *)((int)local_238 + 0x31)) {
        case 0:
        case 3:
        case 7:
        case 8:
          bVar24 = false;
          bVar23 = false;
          bVar20 = true;
          bVar21 = true;
          bVar22 = true;
          break;
        case 1:
        case 4:
        case 5:
        case 0xb:
        case 0xc:
          bVar24 = false;
          bVar23 = false;
          bVar20 = true;
          bVar21 = true;
          bVar22 = false;
          break;
        case 2:
          bVar24 = true;
          bVar23 = true;
          bVar20 = true;
          bVar21 = true;
          bVar22 = false;
          break;
        default:
          bVar24 = false;
          bVar23 = false;
          bVar20 = false;
          bVar21 = false;
          bVar22 = false;
          break;
        case 9:
          bVar24 = false;
          bVar23 = false;
          bVar20 = true;
          bVar21 = false;
          bVar22 = false;
        }
        bVar50 = false;
        piVar53 = local_238 + 0x10;
        if (*(byte *)(local_238 + 0x10) < 0x10) {
          uVar48 = 1 << (*(byte *)(local_238 + 0x10) & 0x1f);
          if ((uVar48 & 0x61) == 0) {
            if ((uVar48 & 0xc00c) == 0) {
              if ((uVar48 & 0x3f80) != 0) {
                bVar50 = false;
                bVar23 = true;
              }
            }
            else {
              bVar50 = false;
              bVar24 = true;
              bVar23 = true;
            }
          }
          else {
            bVar50 = true;
            bVar24 = true;
            bVar23 = true;
          }
        }
        uVar17 = *(undefined2 *)((int)local_238 + 0x12);
        uVar18 = *(undefined2 *)((int)local_238 + 0x1a);
        puVar47 = (uint *)(uint)*(ushort *)(local_238 + 7);
        puVar36 = (uint *)(uint)*(ushort *)((int)local_238 + 0x1e);
        bVar5 = *(byte *)((int)local_238 + 0x2a) & 0x7f;
        bVar28 = *(byte *)((int)local_238 + 0x2b) & 0x7f;
        bVar2 = *(byte *)(local_238 + 0xb) & 0x7f;
        bVar3 = *(byte *)((int)local_238 + 0x39) & 0x7f;
        bVar41 = *(byte *)((int)local_238 + 0x3a) & 0x7f;
        puVar31 = (uint *)(uint)(*(byte *)((int)local_238 + 0x3b) & 0x7f);
        iVar37 = local_238[9];
        uVar19 = *(undefined2 *)((int)local_238 + 0x26);
        iVar26 = local_238[10];
        cVar4 = *(char *)((int)local_238 + 0x36);
        cVar7 = *(char *)((int)local_238 + 0x37);
        bVar8 = *(byte *)(local_238 + 0xe);
        in_stack_fffffc3c = (uint *)(uint)bVar8;
        uVar9 = *(undefined1 *)((int)local_238 + 0x2d);
        uVar10 = *(undefined1 *)((int)local_238 + 0x2e);
        uVar11 = *(undefined1 *)((int)local_238 + 0x2f);
        iVar27 = local_238[0xf];
        uVar12 = *(undefined1 *)((int)local_238 + 0x3d);
        puVar42 = (uint *)(uint)*(byte *)((int)local_238 + 0x3e);
        if (bVar20) {
          if ((bVar5 == 3) && (iVar38 = ((int (*)())FUN_000cfd0c)(), iVar38 == 0)) {
            bVar20 = true;
LAB_000d362d:
            iVar38 = ((int (*)())FUN_000cfd0c)();
            if (iVar38 != 0) {
              bVar25 = true;
              goto LAB_000d19a2;
            }
          }
          else {
            bVar20 = false;
            if (bVar5 == 3) goto LAB_000d362d;
          }
          bVar25 = false;
        }
        else {
          bVar25 = false;
          bVar20 = false;
        }
LAB_000d19a2:
        if (bVar21) {
          if ((bVar28 == 3) && (iVar38 = ((int (*)())FUN_000cfd0c)(), iVar38 == 0)) {
            bVar13 = 1;
          }
          else {
            bVar13 = 0;
          }
          bVar20 = (bool)(bVar20 | bVar13);
          if ((bVar28 == 3) && (iVar38 = ((int (*)())FUN_000cfd0c)(), iVar38 != 0)) {
            bVar13 = 1;
          }
          else {
            bVar13 = 0;
          }
          bVar25 = (bool)(bVar25 | bVar13);
        }
        if (bVar22) {
          if ((bVar2 == 3) && (iVar38 = ((int (*)())FUN_000cfd0c)(), iVar38 == 0)) {
            bVar13 = 1;
          }
          else {
            bVar13 = 0;
          }
          bVar20 = (bool)(bVar20 | bVar13);
          if ((bVar2 == 3) && (iVar38 = ((int (*)())FUN_000cfd0c)(), iVar38 != 0)) {
            bVar13 = 1;
          }
          else {
            bVar13 = 0;
          }
          bVar25 = (bool)(bVar25 | bVar13);
        }
        if (bVar23) {
          if ((bVar3 == 3) && (cVar4 != '\x03')) {
            bVar13 = 1;
          }
          else {
            bVar13 = 0;
          }
          bVar20 = (bool)(bVar20 | bVar13);
          if ((bVar3 == 3) && (cVar4 == '\x03')) {
            bVar13 = 1;
          }
          else {
            bVar13 = 0;
          }
          bVar25 = (bool)(bVar25 | bVar13);
        }
        if (bVar24) {
          if ((bVar41 == 3) && (cVar7 != '\x03')) {
            bVar13 = 1;
          }
          else {
            bVar13 = 0;
          }
          bVar20 = (bool)(bVar20 | bVar13);
          if ((bVar41 == 3) && (cVar7 == '\x03')) {
            bVar13 = 1;
          }
          else {
            bVar13 = 0;
          }
          bVar25 = (bool)(bVar25 | bVar13);
        }
        if (bVar50) {
          if ((puVar31 == (uint *)((int)&MACH_HEADER.magic + 3)) && (bVar8 != 3)) {
            bVar13 = 1;
          }
          else {
            bVar13 = 0;
          }
          bVar20 = (bool)(bVar20 | bVar13);
          if ((puVar31 == (uint *)((int)&MACH_HEADER.magic + 3)) && (bVar8 == 3)) {
            bVar8 = 1;
          }
          else {
            bVar8 = 0;
          }
          bVar25 = (bool)(bVar25 | bVar8);
        }
        if (bVar20) {
          uVar48 = local_318;
          puVar43 = local_1e8;
          ((int (*)())FUN_000cf028)(0,"  %d alu %02d pre:  srcp.rgb = ",local_318,local_1e8);
          cVar14 = (char)local_238[0xc];
          if (cVar14 == '\x01') {
            ((int (*)())FUN_000cfd38)();
            ((int (*)())FUN_000cfd38)();
            ((int (*)())FUN_000cf028)(0,"%s.rgb-%s.rgb\n",&local_34,&local_3e);
          }
          else if (cVar14 == '\0') {
            ((int (*)())FUN_000cfd38)();
            ((int (*)())FUN_000cf028)(0,"1.0-2.0*%s.rgb\n",&local_3e,puVar43);
          }
          else if (cVar14 == '\x02') {
            ((int (*)())FUN_000cfd38)();
            ((int (*)())FUN_000cfd38)();
            ((int (*)())FUN_000cf028)(0,"%s.rgb+%s.rgb\n",&local_34,&local_3e);
          }
          else if (cVar14 == '\x03') {
            ((int (*)())FUN_000cfd38)();
            ((int (*)())FUN_000cf028)(0,"1.0-%s.rgb\n",&local_3e,puVar43);
          }
          else {
            ((int (*)())FUN_000cf028)(0,"???\n",uVar48,puVar43);
          }
        }
        if (bVar25) {
          uVar48 = local_318;
          puVar43 = local_1e8;
          ((int (*)())FUN_000cf028)(0,"  %d alu %02d pre:  srcp.a   = ",local_318,local_1e8);
          cVar14 = *(char *)((int)local_238 + 0x3f);
          if (cVar14 == '\x01') {
            ((int (*)())FUN_000cfd38)();
            ((int (*)())FUN_000cfd38)();
            ((int (*)())FUN_000cf028)(0,"%s.a-%s.a\n",&local_34,&local_3e);
          }
          else if (cVar14 == '\0') {
            ((int (*)())FUN_000cfd38)();
            ((int (*)())FUN_000cf028)(0,"1.0-2.0*%s.a\n",&local_3e,puVar43);
          }
          else if (cVar14 == '\x02') {
            ((int (*)())FUN_000cfd38)();
            ((int (*)())FUN_000cfd38)();
            ((int (*)())FUN_000cf028)(0,"%s.a+%s.a\n",&local_34,&local_3e);
          }
          else if (cVar14 == '\x03') {
            ((int (*)())FUN_000cfd38)();
            ((int (*)())FUN_000cf028)(0,"1.0-%s.a\n",&local_3e,puVar43);
          }
          else {
            ((int (*)())FUN_000cf028)(0,"???\n",uVar48,puVar43);
          }
        }
        uVar48 = local_318;
        puVar43 = local_1e8;
        ((int (*)())FUN_000cf028)(0,"  %d alu %02d rgb:  ",local_318,local_1e8);
        bVar8 = *(byte *)(local_238 + 5);
        bVar13 = *(byte *)((int)local_238 + 0x15);
        if (bVar13 == 0) {
LAB_000d1b02:
          ((int (*)())FUN_000cf028)(0,"           ",uVar48,puVar43);
        }
        else if (*local_238 == 3) {
          puVar43 = (uint *)((uint)bVar13 * 4 + 0x1eef80);
          uVar48 = (uint)*(byte *)((int)local_238 + 0x16);
          ((int (*)())FUN_000cf028)(0,"out%d.%s = ",uVar48,puVar43);
        }
        else {
          if (*local_238 != 4) goto LAB_000d1b02;
          uVar48 = (uint)bVar13 * 4 + 0x1eef80;
          ((int (*)())FUN_000cf028)(0,"pred.%s = ",uVar48,puVar43);
          cVar14 = *(char *)((int)local_238 + 0x16);
          if (cVar14 == '\x01') {
            ((int (*)())FUN_000cf028)(0,"(<) ",uVar48,puVar43);
          }
          else if (cVar14 == '\0') {
            ((int (*)())FUN_000cf028)(0,"(==) ",uVar48,puVar43);
          }
          else if (cVar14 == '\x02') {
            ((int (*)())FUN_000cf028)(0,"(>=) ",uVar48,puVar43);
          }
          else if (cVar14 == '\x03') {
            ((int (*)())FUN_000cf028)(0,"(!=) ",uVar48,puVar43);
          }
        }
        if (bVar8 == 0) {
          ((int (*)())FUN_000cf028)(0,"          ",uVar48,puVar43);
          cVar14 = *(char *)((int)local_238 + 0x33);
        }
        else {
          puVar43 = (uint *)((uint)bVar8 * 4 + 0x1eef80);
          uVar48 = (uint)*(ushort *)(local_238 + 3);
          ((int (*)())FUN_000cf028)(0,"r%02d.%s = ",uVar48,puVar43);
          cVar14 = *(char *)((int)local_238 + 0x33);
        }
        if (cVar14 != '\0') {
          ((int (*)())FUN_000cf028)(0,"clamped ",uVar48,puVar43);
        }
        puVar34 = local_d8;
        ((int (*)())FUN_000d0052)(uVar17,uVar18,puVar47,puVar36,bVar5,uVar9,CONCAT22(uVar60,(short)iVar37),
                     *puVar35);
        puVar43 = local_178;
        ((int (*)())FUN_000d0052)(uVar17,uVar18,puVar47,puVar36,bVar28,uVar10,uVar19,*puVar35);
        puVar58 = local_158;
        ((int (*)())FUN_000d0052)(uVar17,uVar18,puVar47,puVar36,bVar2,uVar11,(short)iVar26,*puVar35);
        param_3 = local_138;
        ((int (*)())FUN_000d0250)(uVar17,uVar18,puVar47,puVar36,bVar3,(char)iVar27,cVar4,(char)*piVar53);
        puVar57 = local_118;
        ((int (*)())FUN_000d0250)(uVar17,uVar18,puVar47,puVar36,bVar41,uVar12,cVar7,(char)*piVar53);
        puVar56 = local_f8;
        ((int (*)())FUN_000d0250)(uVar17,uVar18,puVar47,puVar36,puVar31,puVar42,in_stack_fffffc3c,(char)*piVar53)
        ;
        switch(*puVar35) {
        case 0:
          ((int (*)())FUN_000cf028)(0,"mad(%s, %s, %s)",puVar34,puVar43,puVar58);
          break;
        case 1:
          ((int (*)())FUN_000cf028)(0,"dp3(%s, %s)",puVar34,puVar43);
          puVar58 = puVar31;
          break;
        case 2:
          puVar36 = param_3;
          puVar58 = puVar43;
          puVar42 = puVar57;
          ((int (*)())FUN_000cf028)(0,"dp4(%s:%s, %s:%s)",puVar34,param_3,puVar43,puVar57);
          puVar43 = puVar36;
          break;
        case 3:
          ((int (*)())FUN_000cf028)(0,"d2a(%s, %s, %s)",puVar34,puVar43,puVar58);
          break;
        case 4:
          ((int (*)())FUN_000cf028)(0,"min(%s, %s)",puVar34,puVar43);
          puVar58 = puVar31;
          break;
        case 5:
          ((int (*)())FUN_000cf028)(0,"max(%s, %s)",puVar34,puVar43);
          puVar58 = puVar31;
          break;
        default:
          ((int (*)())FUN_000cf028)(0,"???()");
          puVar34 = puVar47;
          puVar43 = puVar36;
          puVar58 = puVar31;
          break;
        case 7:
          ((int (*)())FUN_000cf028)(0,"cnd(%s, %s, %s)",puVar34,puVar43,puVar58);
          break;
        case 8:
          ((int (*)())FUN_000cf028)(0,"cmp(%s, %s, %s)",puVar34,puVar43,puVar58);
          break;
        case 9:
          ((int (*)())FUN_000cf028)(0,"frc(%s)",puVar34);
          puVar43 = puVar36;
          puVar58 = puVar31;
          break;
        case 10:
          ((int (*)())FUN_000cf028)(0,"sop()");
          puVar34 = puVar47;
          puVar43 = puVar36;
          puVar58 = puVar31;
          break;
        case 0xb:
          ((int (*)())FUN_000cf028)(0,"mdh(%s, %s)",puVar34,puVar43);
          puVar58 = puVar31;
          break;
        case 0xc:
          ((int (*)())FUN_000cf028)(0,"mdv(%s, %s)",puVar34,puVar43);
          puVar58 = puVar31;
        }
        switch(*(undefined1 *)((int)local_238 + 0x32)) {
        case 0:
          break;
        case 1:
          ((int (*)())FUN_000cf028)(0,"*2",puVar34,puVar43,puVar58,puVar42);
          break;
        case 2:
          ((int (*)())FUN_000cf028)(0,"*4",puVar34,puVar43,puVar58,puVar42);
          break;
        case 3:
          ((int (*)())FUN_000cf028)(0,"*8",puVar34,puVar43,puVar58,puVar42);
          break;
        case 4:
          ((int (*)())FUN_000cf028)(0,"/2",puVar34,puVar43,puVar58,puVar42);
          break;
        case 5:
          ((int (*)())FUN_000cf028)(0,"/4",puVar34,puVar43,puVar58,puVar42);
          break;
        case 6:
          ((int (*)())FUN_000cf028)(0,"/8",puVar34,puVar43,puVar58,puVar42);
          break;
        default:
          ((int (*)())FUN_000cf028)(0,"*???",puVar34,puVar43,puVar58,puVar42);
        }
        if (((char)local_2a != '\0') || ((char)local_52 != '\0')) {
          puVar43 = &local_52;
          puVar34 = &local_2a;
          ((int (*)())FUN_000cf028)(0,"%s%s",puVar34,puVar43,puVar58,puVar42);
        }
        if (*(char *)((int)local_238 + 5) != '\0') {
          if (*(char *)((int)local_238 + 6) == '\0') {
            local_20 = 0x70;
          }
          else {
            local_20 = 0x7021;
            local_1e = 0;
          }
          switch(*(undefined1 *)((int)local_238 + 5)) {
          case 1:
            puVar34 = (uint *)&local_20;
            ((int (*)())FUN_000cf028)(0," %s.rgb",puVar34,puVar43,puVar58,puVar42);
            break;
          case 2:
            puVar34 = (uint *)&local_20;
            ((int (*)())FUN_000cf028)(0," %s.rrr",puVar34,puVar43,puVar58,puVar42);
            break;
          case 3:
            puVar34 = (uint *)&local_20;
            ((int (*)())FUN_000cf028)(0," %s.ggg",puVar34,puVar43,puVar58,puVar42);
            break;
          case 4:
            puVar34 = (uint *)&local_20;
            ((int (*)())FUN_000cf028)(0," %s.bbb",puVar34,puVar43,puVar58,puVar42);
            break;
          case 5:
            puVar34 = (uint *)&local_20;
            ((int (*)())FUN_000cf028)(0," %s.aaa",puVar34,puVar43,puVar58,puVar42);
          }
        }
        ((int (*)())FUN_000cf028)(0,"\n",puVar34,puVar43);
        puVar42 = local_1e8;
        ((int (*)())FUN_000cf028)(0,"         alpha:  ",local_1e8);
        iVar37 = local_238[8];
        cVar4 = *(char *)((int)local_238 + 0x21);
        cVar7 = *(char *)((int)local_238 + 0x23);
        if (cVar4 != '\0') {
          if (*local_238 == 3) {
            puVar42 = (uint *)(uint)*(byte *)((int)local_238 + 0x22);
            ((int (*)())FUN_000cf028)(0,"out%d.a   = ",puVar42);
          }
          else if (*local_238 == 4) {
            ((int (*)())FUN_000cf028)(0,"pred.a   = ",puVar42);
            cVar14 = *(char *)((int)local_238 + 0x22);
            if (cVar14 == '\x01') {
              ((int (*)())FUN_000cf028)(0,"(<) ",puVar42);
            }
            else if (cVar14 == '\0') {
              ((int (*)())FUN_000cf028)(0,"(==) ",puVar42);
            }
            else if (cVar14 == '\x02') {
              ((int (*)())FUN_000cf028)(0,"(>=) ",puVar42);
            }
            else if (cVar14 == '\x03') {
              ((int (*)())FUN_000cf028)(0,"(!=) ",puVar42);
            }
          }
        }
        if (cVar7 != '\0') {
          ((int (*)())FUN_000cf028)(0,"depth    = ",puVar42);
        }
        if ((cVar4 == '\0') && (cVar7 == '\0')) {
          ((int (*)())FUN_000cf028)(0,"           ",puVar42);
        }
        if ((char)iVar37 == '\0') {
          ((int (*)())FUN_000cf028)(0,"          ",puVar42);
          cVar4 = *(char *)((int)local_238 + 0x42);
        }
        else {
          puVar42 = (uint *)(uint)*(ushort *)(local_238 + 6);
          ((int (*)())FUN_000cf028)(0,"r%02d.a   = ",puVar42);
          cVar4 = *(char *)((int)local_238 + 0x42);
        }
        if (cVar4 != '\0') {
          ((int (*)())FUN_000cf028)(0,"clamped ",puVar42);
        }
        switch((char)*piVar53) {
        case '\0':
          ((int (*)())FUN_000cf028)(0,"mad(%s, %s, %s)",param_3,puVar57,puVar56);
          break;
        case '\x01':
          ((int (*)())FUN_000cf028)(0,"dp()",puVar42);
          param_3 = puVar42;
          puVar57 = puVar43;
          puVar56 = puVar58;
          break;
        case '\x02':
          ((int (*)())FUN_000cf028)(0,"min(%s, %s)",param_3,puVar57);
          puVar56 = puVar58;
          break;
        case '\x03':
          ((int (*)())FUN_000cf028)(0,"max(%s, %s)",param_3,puVar57);
          puVar56 = puVar58;
          break;
        default:
          ((int (*)())FUN_000cf028)(0,"???()",puVar42);
          param_3 = puVar42;
          puVar57 = puVar43;
          puVar56 = puVar58;
          break;
        case '\x05':
          ((int (*)())FUN_000cf028)(0,"cnd(%s, %s, %s)",param_3,puVar57,puVar56);
          break;
        case '\x06':
          ((int (*)())FUN_000cf028)(0,"cmp(%s, %s, %s)",param_3,puVar57,puVar56);
          break;
        case '\a':
          ((int (*)())FUN_000cf028)(0,"frc(%s)",param_3);
          puVar57 = puVar43;
          puVar56 = puVar58;
          break;
        case '\b':
          ((int (*)())FUN_000cf028)(0,"ex2(%s)",param_3);
          puVar57 = puVar43;
          puVar56 = puVar58;
          break;
        case '\t':
          ((int (*)())FUN_000cf028)(0,"ln2(%s)",param_3);
          puVar57 = puVar43;
          puVar56 = puVar58;
          break;
        case '\n':
          ((int (*)())FUN_000cf028)(0,"rcp(%s)",param_3);
          puVar57 = puVar43;
          puVar56 = puVar58;
          break;
        case '\v':
          ((int (*)())FUN_000cf028)(0,"rsq(%s)",param_3);
          puVar57 = puVar43;
          puVar56 = puVar58;
          break;
        case '\f':
          ((int (*)())FUN_000cf028)(0,"sin(%s)",param_3);
          puVar57 = puVar43;
          puVar56 = puVar58;
          break;
        case '\r':
          ((int (*)())FUN_000cf028)(0,"cos(%s)",param_3);
          puVar57 = puVar43;
          puVar56 = puVar58;
          break;
        case '\x0e':
          ((int (*)())FUN_000cf028)(0,"mdh(%s, %s)",param_3,puVar57);
          puVar56 = puVar58;
          break;
        case '\x0f':
          ((int (*)())FUN_000cf028)(0,"mdv(%s, %s)",param_3,puVar57);
          puVar56 = puVar58;
        }
        switch(*(undefined1 *)((int)local_238 + 0x41)) {
        case 0:
          ((int (*)())FUN_000cf028)(0," ",param_3,puVar57,puVar56);
          break;
        case 1:
          ((int (*)())FUN_000cf028)(0,"*2",param_3,puVar57,puVar56);
          break;
        case 2:
          ((int (*)())FUN_000cf028)(0,"*4",param_3,puVar57,puVar56);
          break;
        case 3:
          ((int (*)())FUN_000cf028)(0,"*8",param_3,puVar57,puVar56);
          break;
        case 4:
          ((int (*)())FUN_000cf028)(0,"/2",param_3,puVar57,puVar56);
          break;
        case 5:
          ((int (*)())FUN_000cf028)(0,"/4",param_3,puVar57,puVar56);
          break;
        case 6:
          ((int (*)())FUN_000cf028)(0,"/8",param_3,puVar57,puVar56);
          break;
        default:
          ((int (*)())FUN_000cf028)(0,"*???",param_3,puVar57,puVar56);
        }
        if (*(char *)((int)local_238 + 10) == '\0') {
          if (*(char *)((int)local_238 + 7) != '\0') {
            if ((char)local_238[2] == '\0') {
              local_20 = 0x70;
            }
            else {
              local_20 = 0x7021;
              local_1e = 0;
            }
            switch(*(undefined1 *)((int)local_238 + 7)) {
            case 1:
            case 5:
              param_3 = (uint *)&local_20;
              ((int (*)())FUN_000cf028)(0," %s.a",param_3,puVar57,puVar56);
              break;
            case 2:
              param_3 = (uint *)&local_20;
              ((int (*)())FUN_000cf028)(0," %s.r",param_3,puVar57,puVar56);
              break;
            case 3:
              param_3 = (uint *)&local_20;
              ((int (*)())FUN_000cf028)(0," %s.g",param_3,puVar57,puVar56);
              break;
            case 4:
              param_3 = (uint *)&local_20;
              ((int (*)())FUN_000cf028)(0," %s.b",param_3,puVar57,puVar56);
            }
          }
          if (*(char *)((int)local_238 + 9) != '\0') {
            ((int (*)())FUN_000cf028)(0," write_inactive",param_3);
          }
          ((int (*)())FUN_000cf028)(0," \n",param_3);
        }
        else {
          ((int (*)())FUN_000cf028)(0," last\n",param_3,puVar57,puVar56);
        }
        if ((char)local_238[0xd] != '\0') {
          param_3 = local_1e8;
          ((int (*)())FUN_000cf028)(0,"   alu %02d post-NOP\n",local_1e8);
        }
        local_1e8 = (uint *)((int)local_1e8 + 1);
      }
      if (*local_238 == 5) {
        if (cVar15 == '\x01') {
          local_3e = 0x746c;
LAB_000d25db:
          local_3c = 0;
          if (cVar29 != '\0') goto LAB_000d214b;
LAB_000d25e9:
          local_34 = 0x646572;
        }
        else {
          if (cVar15 == '\0') {
            local_3e = 0x7165;
            goto LAB_000d25db;
          }
          if (cVar15 == '\x02') {
            local_3e = 0x6567;
            goto LAB_000d25db;
          }
          if (cVar15 == '\x03') {
            local_3e = 0x656e;
            goto LAB_000d25db;
          }
          local_3e = 0x20;
          if (cVar29 == '\0') goto LAB_000d25e9;
LAB_000d214b:
          if (cVar29 == '\x01') {
            local_34 = 0x68706c61;
            local_30 = 0x61;
          }
          else {
            local_34 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_34) + 2)),0x20);
          }
        }
        ((int (*)())FUN_000cf028)(0,"  %d cf  %02d    :  ",local_318,local_1e0);
        in_stack_fffffc3c = (uint *)(&DAT_001eef5f + (uint)*(byte *)(local_238 + 5) * 10);
        pcVar49 = local_1dc;
        _sprintf(pcVar49,"0x%02x %1d %s %s %s %s %1d %1d %d",(uint)*(byte *)((int)local_238 + 0x12),
                 (uint)*(byte *)(local_238 + 4),
                 (uint)*(byte *)((int)local_238 + 0xe) * 10 + 0x1eef00,
                 (uint)*(byte *)((int)local_238 + 0x11) * 5 + 0x1eef50,in_stack_fffffc3c,
                 &DAT_001eef5f + (uint)*(byte *)((int)local_238 + 0x15) * 10,
                 (uint)*(byte *)((int)local_238 + 0x13),(uint)*(byte *)((int)local_238 + 0xf),
                 (uint)*(ushort *)(local_238 + 3));
        local_390 = PTR_s_0x55_0_JUMP_NONE_NONE_NONE_001ef024;
        if (PTR_s_0x55_0_JUMP_NONE_NONE_NONE_001ef024 == (undefined *)0x0) {
          local_2b4 = 0;
        }
        else {
          local_2b4 = 0;
          ppuVar52 = PTR_s_IF_b_001ef020;
          do {
            uVar48 = 0xffffffff;
            pcVar39 = local_390;
            do {
              if (uVar48 == 0) break;
              uVar48 = uVar48 - 1;
              cVar4 = *pcVar39;
              pcVar39 = pcVar39 + 1;
            } while (cVar4 != '\0');
            iVar37 = _strncmp(local_390,pcVar49,~uVar48 - 1);
            if (iVar37 == 0) break;
            local_2b4 = local_2b4 + 2;
            local_390 = ppuVar52[3];
            ppuVar52 = ppuVar52 + 2;
          } while (local_390 != (char *)0x0);
        }
        param_3 = (uint *)(PTR_s_IF_b_001ef020)[local_2b4];
        puVar42 = &local_52;
        puVar36 = &local_2a;
        ((int (*)())FUN_000cf028)(0,"%s(%s)%s%s",param_3,pcVar49,puVar36,puVar42);
        cVar4 = *(char *)((int)local_238 + 0x12);
        if ((cVar4 == -0x10) || (cVar4 == '\x0f')) {
          param_3 = &local_34;
          ((int (*)())FUN_000cf028)(0,"( prev_alu: %s %s )\n",param_3,&local_3e,puVar36,puVar42);
        }
        else if ((cVar4 == -0x56) || (cVar4 == 'U')) {
          param_3 = (uint *)(uint)*(byte *)((int)local_238 + 0x17);
          ((int (*)())FUN_000cf028)(0,"( bool_addr: %d )\n",param_3,pcVar49,puVar36,puVar42);
        }
        else {
          ((int (*)())FUN_000cf028)(0,"\n",param_3,pcVar49,puVar36,puVar42);
        }
        local_1e0 = local_1e0 + 1;
      }
      local_2fc = local_2fc + 1;
      local_318 = local_318 + 1;
      local_238 = local_238 + 0x12;
    } while (local_2fc <= iVar54);
  }
  ((int (*)())FUN_000cf028)(0,"\n\n",param_3);
  ((int (*)())FUN_000cf028)(0,"======== End r520 neutral format pixel shader =============\n");
  return;
}

/* FUN_000d4d9a @ 0xd4d9a (21 bytes) */
int FUN_000d4d9a(param_1)
  undefined4 *param_1;
{
  *param_1 = 0;
  param_1[1] = 0;
  return;
}

/* FUN_000d4db0 @ 0xd4db0 (21 bytes) */
int FUN_000d4db0(param_1)
  undefined4 *param_1;
{
  *param_1 = 0;
  param_1[1] = 0;
  return;
}

/* FUN_000d4dc6 @ 0xd4dc6 (77 bytes) */
int FUN_000d4dc6(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  DAT_002106b8 = *param_1;
  DAT_002106b4 = param_1[1];
  ((int (*)())FUN_000d042e)(param_2 + 0x64c,"SC Generated Shader",0);
  return 1;
}

/* FUN_000d4e14 @ 0xd4e14 (21 bytes) */
int FUN_000d4e14()
{
  undefined1 local_14 [16];
  
  ((int (*)())FUN_000d4db0)(local_14);
  return 0;
}

/* FUN_000d4e2a @ 0xd4e2a (53 bytes) */
int FUN_000d4e2a(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 local_14;
  undefined4 local_10;
  
  ((int (*)())FUN_000d4db0)(&local_14);
  local_10 = param_1;
  local_14 = param_4;
  ((int (*)())FUN_000d4dc6)(&local_14,param_2);
  return 0;
}

/* FUN_000d4e67 @ 0xd4e67 (528 bytes) */
int FUN_000d4e67(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  int param_1;
  uint param_2;
  uint param_3;
  uint *param_4;
  uint *param_5;
  uint param_6;
  undefined4 param_7;
  int param_8;
  int param_9;
{
  uint uVar1;
  
  uVar1 = param_2 - 0x84c0;
  if (0xf < uVar1) {
    if (param_2 < 2) {
      if (param_2 == 0) {
        *param_4 = *param_4 & 0xffc0ffff | 0x120000;
        *(undefined2 *)param_4 = 0;
        *(byte *)((int)param_4 + 2) = *(byte *)((int)param_4 + 2) | 0x40;
        if (param_3 != 0x301) {
          if (param_3 < 0x302) {
            if (param_3 != 0x300) {
              return;
            }
          }
          else if (param_3 != 0x302) {
            if (param_3 != 0x303) {
              return;
            }
            goto LAB_000d4f9b;
          }
LAB_000d502e:
          *param_5 = *param_5 & 0xfffff888 | 0x444;
          return;
        }
      }
      else {
        if (param_2 != 1) {
          return;
        }
        *param_4 = *param_4 & 0xffc0ffff | 0x120000;
        *(undefined2 *)param_4 = 0;
        *(byte *)((int)param_4 + 2) = *(byte *)((int)param_4 + 2) | 0x40;
        if (param_3 == 0x301) goto LAB_000d502e;
        if (param_3 < 0x302) {
          if (param_3 != 0x300) {
            return;
          }
        }
        else if (param_3 != 0x302) {
          if (param_3 != 0x303) {
            return;
          }
          goto LAB_000d502e;
        }
      }
LAB_000d4f9b:
      *param_5 = *param_5 & 0xfffff888 | 0x555;
      return;
    }
    if (param_2 == 0x8576) {
      *param_4 = *param_4 & 0xffc0ffff | 0x10000;
      *(short *)param_4 = (short)param_6;
      goto LAB_000d4e9f;
    }
    if (0x8576 < param_2) {
      if (param_2 != 0x8577) {
        if (param_2 != 0x8578) goto LAB_000d4e9f;
        if (param_8 == '\0') {
          *param_4 = *param_4 & 0xffc0ffff | 0x40000;
          *(ushort *)param_4 = (ushort)*(byte *)(param_1 + 0x13b2) + param_9;
          goto LAB_000d4e9f;
        }
      }
      *param_4 = *param_4 & 0xffc0ffff | 0x120000;
      goto LAB_000d4e9f;
    }
    uVar1 = param_6;
    if (param_2 != 0x1702) goto LAB_000d4e9f;
  }
  *param_4 = *param_4 & 0xffc0ffff | 0x40000;
  *(short *)param_4 = (short)uVar1;
LAB_000d4e9f:
  if (param_3 == 0x302) {
    *(byte *)((int)param_4 + 2) = *(byte *)((int)param_4 + 2) | 0x40;
  }
  else {
    if (param_3 != 0x303) {
      if (param_3 != 0x301) {
        return;
      }
      *(byte *)((int)param_4 + 2) = *(byte *)((int)param_4 + 2) | 0x40;
      *(byte *)((int)param_5 + 2) = *(byte *)((int)param_5 + 2) | 1;
      *param_5 = *param_5 & 0xfffff888 | 0x210;
      return;
    }
    *(byte *)((int)param_4 + 2) = *(byte *)((int)param_4 + 2) | 0x40;
    *(byte *)((int)param_5 + 2) = *(byte *)((int)param_5 + 2) | 1;
  }
  *param_5 = *param_5 & 0xfffff888 | 0x333;
  return;
}

/* FUN_000d5077 @ 0xd5077 (384 bytes) */
int FUN_000d5077(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  int param_1;
  uint param_2;
  int param_3;
  uint *param_4;
  uint *param_5;
  uint param_6;
  undefined4 param_7;
  int param_8;
  int param_9;
{
  uint uVar1;
  
  uVar1 = param_2 - 0x84c0;
  if (0xf < uVar1) {
    if (param_2 < 2) {
      if (param_2 == 0) {
        *param_4 = *param_4 & 0xffc0ffff | 0x120000;
        *(undefined2 *)param_4 = 0;
        *(byte *)((int)param_4 + 2) = *(byte *)((int)param_4 + 2) | 0x40;
        if (param_3 != 0x302) {
          if (param_3 != 0x303) {
            return;
          }
          goto LAB_000d51e5;
        }
      }
      else {
        if (param_2 != 1) {
          return;
        }
        *param_4 = *param_4 & 0xffc0ffff | 0x120000;
        *(undefined2 *)param_4 = 0;
        *(byte *)((int)param_4 + 2) = *(byte *)((int)param_4 + 2) | 0x40;
        if (param_3 == 0x302) {
LAB_000d51e5:
          *param_5 = *param_5 & 0xffff8fff | 0x5000;
          return;
        }
        if (param_3 != 0x303) {
          return;
        }
      }
      *param_5 = *param_5 & 0xffff8fff | 0x4000;
      return;
    }
    if (param_2 == 0x8576) {
      *param_4 = *param_4 & 0xffc0ffff | 0x10000;
      *(short *)param_4 = (short)param_6;
      goto LAB_000d50ad;
    }
    if (0x8576 < param_2) {
      if (param_2 != 0x8577) {
        if (param_2 != 0x8578) goto LAB_000d50ad;
        if (param_8 == '\0') {
          *param_4 = *param_4 & 0xffc0ffff | 0x40000;
          *(ushort *)param_4 = (ushort)*(byte *)(param_1 + 0x13b2) + param_9;
          goto LAB_000d50ad;
        }
      }
      *param_4 = *param_4 & 0xffc0ffff | 0x120000;
      *(undefined2 *)param_4 = 0;
      goto LAB_000d50ad;
    }
    uVar1 = param_6;
    if (param_2 != 0x1702) goto LAB_000d50ad;
  }
  *param_4 = *param_4 & 0xffc0ffff | 0x40000;
  *(short *)param_4 = (short)uVar1;
LAB_000d50ad:
  if (param_3 != 0x303) {
    return;
  }
  *(byte *)((int)param_4 + 2) = *(byte *)((int)param_4 + 2) | 0x40;
  *(byte *)((int)param_5 + 2) = *(byte *)((int)param_5 + 2) | 1;
  *param_5 = *param_5 & 0xffff8fff | 0x3000;
  return;
}

/* FUN_000d51f7 @ 0xd51f7 (419 bytes) */
int FUN_000d51f7(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint *param_2;
  int param_3;
  int param_4;
  uint param_5;
{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  undefined4 local_24;
  undefined4 local_20;
  
  local_20 = 0x170000;
  if (param_3 == '\0') {
    local_24 = CONCAT22(4,(ushort)*(byte *)(param_1 + 0x13b2) + param_4);
  }
  else {
    local_24 = 0x120000;
  }
  iVar3 = 0;
  do {
    if ((param_5 & 1 << ((byte)iVar3 & 0x1f)) != 0) {
      local_20 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_20) + 2)),(short)iVar3);
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
      *(undefined4 *)(param_2[2] + *param_2 * 4) = local_20;
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
      *(undefined4 *)(param_2[2] + *param_2 * 4) = local_24;
      *param_2 = *param_2 + 1;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 4);
  return;
}

/* FUN_000d539a @ 0xd539a (661 bytes) */
int FUN_000d539a(param_1, param_2, param_3, param_4)
  int param_1;
  uint *param_2;
  int param_3;
  int param_4;
{
  byte bVar1;
  uint uVar2;
  void *pvVar3;
  uint uVar4;
  undefined4 uVar5;
  
  if (param_2[1] <= *param_2) {
    pvVar3 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar3,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar3;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(param_2[2] + *param_2 * 4) = 3;
  uVar4 = *param_2;
  *param_2 = uVar4 + 1;
  bVar1 = *(byte *)(param_1 + 0x13b2);
  if (param_2[1] <= uVar4 + 1) {
    pvVar3 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar3,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar3;
    param_2[1] = param_2[1] + 0x80;
  }
  *(uint *)(param_2[2] + *param_2 * 4) = CONCAT22(4,(ushort)bVar1 + param_4);
  uVar4 = *param_2 + 1;
  *param_2 = uVar4;
  if (param_3 == '\0') {
    uVar5 = CONCAT22(4,(ushort)*(byte *)(param_1 + 0x13b2) + param_4);
    uVar2 = param_2[1];
    if (uVar2 <= uVar4) goto LAB_000d5480;
LAB_000d5415:
    *(undefined4 *)(param_2[2] + *param_2 * 4) = uVar5;
    uVar2 = *param_2;
    *param_2 = uVar2 + 1;
    uVar4 = param_2[1];
    if (uVar4 <= uVar2 + 1) {
LAB_000d54e2:
      pvVar3 = (void *)(**(code **)(param_1 + 0xc))(uVar4 * 4 + 0x200);
      if ((void *)param_2[2] != (void *)0x0) {
        _memcpy(pvVar3,(void *)param_2[2],*param_2 << 2);
        (**(code **)(param_1 + 0x18))(param_2[2]);
      }
      param_2[2] = (uint)pvVar3;
      param_2[1] = param_2[1] + 0x80;
      *(undefined4 *)(param_2[2] + *param_2 * 4) = 0x530000;
      uVar2 = *param_2;
      *param_2 = uVar2 + 1;
      uVar4 = param_2[1];
      if (uVar4 <= uVar2 + 1) goto LAB_000d5541;
      goto LAB_000d544d;
    }
  }
  else {
    uVar5 = 0x120000;
    uVar2 = param_2[1];
    if (uVar4 < uVar2) goto LAB_000d5415;
LAB_000d5480:
    pvVar3 = (void *)(**(code **)(param_1 + 0xc))(uVar2 * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar3,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar3;
    param_2[1] = param_2[1] + 0x80;
    *(undefined4 *)(param_2[2] + *param_2 * 4) = uVar5;
    uVar2 = *param_2;
    *param_2 = uVar2 + 1;
    uVar4 = param_2[1];
    if (uVar4 <= uVar2 + 1) goto LAB_000d54e2;
  }
  *(undefined4 *)(param_2[2] + *param_2 * 4) = 0x530000;
  uVar2 = *param_2;
  *param_2 = uVar2 + 1;
  uVar4 = param_2[1];
  if (uVar4 <= uVar2 + 1) {
LAB_000d5541:
    pvVar3 = (void *)(**(code **)(param_1 + 0xc))(uVar4 * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar3,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar3;
    param_2[1] = param_2[1] + 0x80;
    *(undefined4 *)(param_2[2] + *param_2 * 4) = 0x4210;
    *param_2 = *param_2 + 1;
    return;
  }
LAB_000d544d:
  *(undefined4 *)(param_2[2] + *param_2 * 4) = 0x4210;
  *param_2 = *param_2 + 1;
  return;
}

/* FUN_000d562f @ 0xd562f (2222 bytes) */
int FUN_000d562f(param_1, param_2)
  int param_1;
  int param_2;
{
  uint *puVar1;
  int iVar2;
  bool bVar3;
  void *pvVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int local_60;
  int local_30;
  
  iVar2 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  puVar1 = (uint *)(param_2 + 4);
  if (*(uint *)(param_2 + 8) <= *(uint *)(param_2 + 4)) {
    pvVar4 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
    if (*(void **)(param_2 + 0xc) != (void *)0x0) {
      _memcpy(pvVar4,*(void **)(param_2 + 0xc),*(int *)(param_2 + 4) << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
    }
    *(void **)(param_2 + 0xc) = pvVar4;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
  }
  *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = 0x1ff0016;
  uVar6 = *puVar1;
  *puVar1 = uVar6 + 1;
  if (*(uint *)(param_2 + 8) <= uVar6 + 1) {
    pvVar4 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
    if (*(void **)(param_2 + 0xc) != (void *)0x0) {
      _memcpy(pvVar4,*(void **)(param_2 + 0xc),*puVar1 << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
    }
    *(void **)(param_2 + 0xc) = pvVar4;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
  }
  *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = 0x120000;
  uVar6 = *puVar1;
  *puVar1 = uVar6 + 1;
  if (((*(byte *)(param_1 + 0x45) & 5) != 0) ||
     (((*(byte *)(param_1 + 0x44) & 1) != 0 && (*(short *)(iVar2 + 0x2d48) == -0x7e06)))) {
    if (uVar6 + 1 < *(uint *)(param_2 + 8)) {
      *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = 0x1ff0016;
      uVar5 = *puVar1;
      *puVar1 = uVar5 + 1;
      uVar6 = *(uint *)(param_2 + 8);
      if (uVar6 <= uVar5 + 1) {
LAB_000d5d7a:
        pvVar4 = (void *)(**(code **)(param_1 + 0xc))(uVar6 * 4 + 0x200);
        if (*(void **)(param_2 + 0xc) != (void *)0x0) {
          _memcpy(pvVar4,*(void **)(param_2 + 0xc),*puVar1 << 2);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
        }
        *(void **)(param_2 + 0xc) = pvVar4;
        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = 0x130000;
        *puVar1 = *puVar1 + 1;
        goto LAB_000d569e;
      }
    }
    else {
      pvVar4 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar4,*(void **)(param_2 + 0xc),*puVar1 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar4;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
      *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = 0x1ff0016;
      uVar5 = *puVar1;
      *puVar1 = uVar5 + 1;
      uVar6 = *(uint *)(param_2 + 8);
      if (uVar6 <= uVar5 + 1) goto LAB_000d5d7a;
    }
    *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = 0x130000;
    *puVar1 = *puVar1 + 1;
  }
LAB_000d569e:
  if (*(char *)(param_1 + 0x13b2) == '\0') {
    bVar3 = false;
  }
  else {
    local_30 = param_1;
    local_60 = 0;
    bVar3 = false;
    do {
      if (((*(byte *)(param_1 + 0x45) & 8) != 0) &&
         (*(char *)(local_60 + 0x71 + *(int *)(param_1 + 0x1168)) == '\0')) {
        bVar3 = true;
      }
      if (*(int *)(local_30 + 0x13f8) != 0) {
        if (*puVar1 < *(uint *)(param_2 + 8)) {
          *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = 0x1ff0016;
          uVar6 = *puVar1;
          *puVar1 = uVar6 + 1;
          uVar5 = *(uint *)(param_2 + 8);
          if (uVar6 + 1 < uVar5) goto LAB_000d56df;
LAB_000d580c:
          pvVar4 = (void *)(**(code **)(param_1 + 0xc))(uVar5 * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar4,*(void **)(param_2 + 0xc),*puVar1 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar4;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          *(uint *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = CONCAT22(0x11,(undefined2)local_60);
          uVar6 = *puVar1;
          *puVar1 = uVar6 + 1;
          uVar7 = local_60 << 0x10 | 0x19;
          uVar5 = *(uint *)(param_2 + 8);
          if (uVar5 <= uVar6 + 1) {
LAB_000d5877:
            pvVar4 = (void *)(**(code **)(param_1 + 0xc))(uVar5 * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar4,*(void **)(param_2 + 0xc),*puVar1 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar4;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
        }
        else {
          pvVar4 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar4,*(void **)(param_2 + 0xc),*puVar1 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar4;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = 0x1ff0016;
          uVar6 = *puVar1;
          *puVar1 = uVar6 + 1;
          uVar5 = *(uint *)(param_2 + 8);
          if (uVar5 <= uVar6 + 1) goto LAB_000d580c;
LAB_000d56df:
          *(uint *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = CONCAT22(0x11,(undefined2)local_60);
          uVar6 = *puVar1;
          *puVar1 = uVar6 + 1;
          uVar7 = local_60 << 0x10 | 0x19;
          uVar5 = *(uint *)(param_2 + 8);
          if (uVar5 <= uVar6 + 1) goto LAB_000d5877;
        }
        *(uint *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = uVar7;
        uVar6 = *puVar1;
        *puVar1 = uVar6 + 1;
        if (((int)(uint)*(byte *)(param_1 + 0x20) >> ((byte)local_60 & 0x1f) & 1U) != 0) {
          if (*(uint *)(param_2 + 8) <= uVar6 + 1) {
            pvVar4 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar4,*(void **)(param_2 + 0xc),*puVar1 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar4;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(uint *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = (local_60 + 8) * 0x10000 | 0x19;
          *puVar1 = *puVar1 + 1;
        }
      }
      local_60 = local_60 + 1;
      local_30 = local_30 + 4;
    } while (local_60 < (int)(uint)*(byte *)(param_1 + 0x13b2));
  }
  if (*(char *)(param_1 + 0x121) != '\0') {
    if (*puVar1 < *(uint *)(param_2 + 8)) {
      *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = 0x1ff0016;
      uVar5 = *puVar1;
      *puVar1 = uVar5 + 1;
      uVar6 = *(uint *)(param_2 + 8);
      if (uVar6 <= uVar5 + 1) {
LAB_000d5e33:
        pvVar4 = (void *)(**(code **)(param_1 + 0xc))(uVar6 * 4 + 0x200);
        if (*(void **)(param_2 + 0xc) != (void *)0x0) {
          _memcpy(pvVar4,*(void **)(param_2 + 0xc),*puVar1 << 2);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
        }
        *(void **)(param_2 + 0xc) = pvVar4;
        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
      }
    }
    else {
      pvVar4 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar4,*(void **)(param_2 + 0xc),*puVar1 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar4;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
      *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = 0x1ff0016;
      uVar5 = *puVar1;
      *puVar1 = uVar5 + 1;
      uVar6 = *(uint *)(param_2 + 8);
      if (uVar6 <= uVar5 + 1) goto LAB_000d5e33;
    }
    *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = 0x100000;
    *puVar1 = *puVar1 + 1;
  }
  if (!bVar3) {
    return;
  }
  if (*puVar1 < *(uint *)(param_2 + 8)) {
    *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = 0x1c;
    uVar5 = *puVar1;
    *puVar1 = uVar5 + 1;
    uVar6 = *(uint *)(param_2 + 8);
    if (uVar5 + 1 < uVar6) goto LAB_000d595c;
LAB_000d5c7d:
    pvVar4 = (void *)(**(code **)(param_1 + 0xc))(uVar6 * 4 + 0x200);
    if (*(void **)(param_2 + 0xc) != (void *)0x0) {
      _memcpy(pvVar4,*(void **)(param_2 + 0xc),*puVar1 << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
    }
    *(void **)(param_2 + 0xc) = pvVar4;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    *(undefined **)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = ((unsigned char *)0x00010011);
    uVar5 = *puVar1;
    *puVar1 = uVar5 + 1;
    uVar6 = *(uint *)(param_2 + 8);
    if (uVar6 <= uVar5 + 1) goto LAB_000d5baf;
LAB_000d5982:
    *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = 0;
    uVar5 = *puVar1;
    *puVar1 = uVar5 + 1;
    uVar6 = *(uint *)(param_2 + 8);
    if (uVar5 + 1 < uVar6) goto LAB_000d59a1;
LAB_000d5b43:
    pvVar4 = (void *)(**(code **)(param_1 + 0xc))(uVar6 * 4 + 0x200);
    if (*(void **)(param_2 + 0xc) != (void *)0x0) {
      _memcpy(pvVar4,*(void **)(param_2 + 0xc),*puVar1 << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
    }
    *(void **)(param_2 + 0xc) = pvVar4;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = 0;
    uVar5 = *puVar1;
    *puVar1 = uVar5 + 1;
    uVar6 = *(uint *)(param_2 + 8);
    if (uVar6 <= uVar5 + 1) goto LAB_000d5ad9;
LAB_000d59c0:
    *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = 0;
    uVar5 = *puVar1;
    *puVar1 = uVar5 + 1;
    uVar6 = *(uint *)(param_2 + 8);
    if (uVar5 + 1 < uVar6) goto LAB_000d59dd;
  }
  else {
    pvVar4 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
    if (*(void **)(param_2 + 0xc) != (void *)0x0) {
      _memcpy(pvVar4,*(void **)(param_2 + 0xc),*puVar1 << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
    }
    *(void **)(param_2 + 0xc) = pvVar4;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = 0x1c;
    uVar5 = *puVar1;
    *puVar1 = uVar5 + 1;
    uVar6 = *(uint *)(param_2 + 8);
    if (uVar6 <= uVar5 + 1) goto LAB_000d5c7d;
LAB_000d595c:
    *(undefined **)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = ((unsigned char *)0x00010011);
    uVar5 = *puVar1;
    *puVar1 = uVar5 + 1;
    uVar6 = *(uint *)(param_2 + 8);
    if (uVar5 + 1 < uVar6) goto LAB_000d5982;
LAB_000d5baf:
    pvVar4 = (void *)(**(code **)(param_1 + 0xc))(uVar6 * 4 + 0x200);
    if (*(void **)(param_2 + 0xc) != (void *)0x0) {
      _memcpy(pvVar4,*(void **)(param_2 + 0xc),*puVar1 << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
    }
    *(void **)(param_2 + 0xc) = pvVar4;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = 0;
    uVar5 = *puVar1;
    *puVar1 = uVar5 + 1;
    uVar6 = *(uint *)(param_2 + 8);
    if (uVar6 <= uVar5 + 1) goto LAB_000d5b43;
LAB_000d59a1:
    *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = 0;
    uVar5 = *puVar1;
    *puVar1 = uVar5 + 1;
    uVar6 = *(uint *)(param_2 + 8);
    if (uVar5 + 1 < uVar6) goto LAB_000d59c0;
LAB_000d5ad9:
    pvVar4 = (void *)(**(code **)(param_1 + 0xc))(uVar6 * 4 + 0x200);
    if (*(void **)(param_2 + 0xc) != (void *)0x0) {
      _memcpy(pvVar4,*(void **)(param_2 + 0xc),*puVar1 << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
    }
    *(void **)(param_2 + 0xc) = pvVar4;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = 0;
    uVar5 = *puVar1;
    *puVar1 = uVar5 + 1;
    uVar6 = *(uint *)(param_2 + 8);
    if (uVar5 + 1 < uVar6) goto LAB_000d59dd;
  }
  pvVar4 = (void *)(**(code **)(param_1 + 0xc))(uVar6 * 4 + 0x200);
  if (*(void **)(param_2 + 0xc) != (void *)0x0) {
    _memcpy(pvVar4,*(void **)(param_2 + 0xc),*puVar1 << 2);
    (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
  }
  *(void **)(param_2 + 0xc) = pvVar4;
  *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
LAB_000d59dd:
  *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = 0x3f800000;
  *puVar1 = *puVar1 + 1;
  return;
}

/* FUN_000d5edd @ 0xd5edd (4270 bytes) */
int FUN_000d5edd(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
  undefined4 param_5;
  int param_6;
  undefined4 param_7;
{
  float fVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  short sVar5;
  void *pvVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  uint *puVar11;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  int local_a4;
  int local_a0;
  int local_74;
  int local_70;
  int local_58 [3];
  byte bStack_4a;
  undefined1 local_48;
  byte local_47;
  byte local_46;
  undefined4 local_44;
  byte abStack_3e [4];
  byte local_3a;
  undefined4 local_38;
  byte local_34 [4];
  byte local_30;
  byte local_2f;
  byte local_2e;
  undefined4 local_2c;
  byte abStack_26 [4];
  byte local_22;
  undefined1 local_20 [16];
  
  iVar9 = 1;
  do {
    (&local_2c)[iVar9] = 0;
    (&local_38)[iVar9] = 0;
    (&local_44)[iVar9] = 0;
    local_58[iVar9 + 2] = 0;
    iVar9 = iVar9 + 1;
  } while (iVar9 != 4);
  iVar9 = param_1 + 0x450 + param_4 * 0xcc;
  ((int (*)())FUN_000d4e67)(&STACKARG(0xffffffd8),local_34,param_4,param_3,param_6,param_7);
  ((int (*)())FUN_000d4e67)((int)abStack_26 + 2,&local_30,param_4,param_3,param_6,param_7);
  ((int (*)())FUN_000d4e67)(local_20,&local_2c,param_4,param_3,param_6,param_7);
  fVar1 = *(float *)(iVar9 + 0x24);
  uVar3 = *(ushort *)(iVar9 + 4);
  puVar11 = (uint *)(param_2 + 4);
  local_c4 = 0;
  if (uVar3 < 0x86b0) {
    if (uVar3 < 0x86ae) {
      if (uVar3 == 0x2100) {
        local_c4 = 0x49;
        local_58[0] = 0;
        local_58[1] = 1;
        local_a0 = 2;
      }
      else if (uVar3 < 0x2101) {
        if (uVar3 == 0x104) {
          local_c4 = 3;
          local_58[0] = 0;
          local_58[1] = 1;
          local_a0 = 2;
        }
        else {
          if (uVar3 != 0x1e01) goto LAB_000d66f6;
          local_c4 = 0x47;
          local_58[0] = 0;
          local_a0 = 1;
        }
      }
      else {
        if (uVar3 == 0x8574) {
          local_c4 = 3;
          local_58[0] = 0;
          local_58[1] = 1;
          if ((local_22 & 0x40) == 0) {
            local_22 = local_22 | 0x40;
            local_30 = local_30 & 0x88 | 0x10;
            local_2f = local_2f & 0xf8 | 2;
          }
          goto LAB_000d60ad;
        }
        if (uVar3 == 0x8575) {
          local_c4 = 0x3f;
          local_58[0] = 2;
          local_58[1] = 0;
          local_58[2] = 1;
          local_a0 = 3;
        }
        else {
          if (uVar3 != 0x84e7) goto LAB_000d66f6;
          local_c4 = 0x5b;
          local_58[0] = 0;
          local_58[1] = 1;
          local_a0 = 2;
        }
      }
    }
    else {
LAB_000d607a:
      local_c4 = 0x22;
      local_58[0] = 0;
      local_58[1] = 1;
      if ((abStack_26[0] & 0x40) == 0) {
        abStack_26[0] = abStack_26[0] | 0x40;
        local_34[0] = local_34[0] & 0x88 | 0x10;
        local_34[1] = local_34[1] & 0xf8 | 2;
      }
      if ((local_22 & 0x40) == 0) {
        local_22 = local_22 | 0x40;
        local_30 = local_30 & 0x88 | 0x10;
        local_2f = local_2f & 0xf8 | 2;
      }
      local_34[2] = local_34[2] | 2;
LAB_000d60ad:
      local_58[1] = 1;
      local_58[0] = 0;
      local_2e = local_2e | 2;
      local_a0 = 2;
    }
  }
  else if (uVar3 == 0x8744) {
    local_c4 = 0x40;
    local_58[0] = 0;
    local_58[1] = 2;
    local_58[2] = 1;
    local_a0 = 3;
  }
  else if (uVar3 < 0x8745) {
    if ((ushort)(uVar3 + 0x78c0) < 2) goto LAB_000d607a;
LAB_000d66f6:
    local_a0 = 0;
  }
  else if (uVar3 == 0x8745) {
    local_c4 = 0x40;
    local_58[0] = 0;
    local_58[1] = 2;
    local_58[2] = 1;
    if ((local_22 & 0x40) == 0) {
      local_22 = local_22 | 0x40;
      local_30 = local_30 & 0x88 | 0x10;
      local_2f = local_2f & 0xf8 | 2;
    }
    local_2e = local_2e | 2;
    local_a0 = 3;
  }
  else {
    if (uVar3 != 0x8746) goto LAB_000d66f6;
    local_c4 = 0x40;
    local_58[0] = 0;
    local_58[1] = 2;
    local_58[2] = 1;
    if ((local_22 & 0x40) == 0) {
      local_22 = local_22 | 0x40;
      local_30 = local_30 & 0x88 | 0x10;
      local_2f = local_2f & 0xf8 | 2;
    }
    local_30 = local_30 | 0x88;
    local_2f = local_2f | 8;
    local_a0 = 3;
  }
  sVar5 = (short)param_4;
  bVar2 = *(byte *)(param_1 + 0x13b2);
  if (uVar3 - 0x86ae < 2) {
    if ((fVar1 == FLOAT_001c5ba4) && (!NAN(fVar1) && !NAN(FLOAT_001c5ba4))) goto LAB_000d62e7;
    if ((fVar1 != FLOAT_001c5bd0) || (NAN(fVar1) || NAN(FLOAT_001c5bd0))) {
      local_34[2] = local_34[2] | 4;
    }
    local_c0 = 0x715;
LAB_000d62f1:
    uVar8 = *(uint *)(param_2 + 8);
    if (uVar8 <= *puVar11) goto LAB_000d613f;
LAB_000d62fc:
    *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar11 * 4) = local_c4;
    uVar4 = *puVar11;
    *puVar11 = uVar4 + 1;
    uVar8 = *(uint *)(param_2 + 8);
    if (uVar8 <= uVar4 + 1) goto LAB_000d61b0;
  }
  else {
    if (((fVar1 == FLOAT_001c5bcc) || (uVar3 == 0x8740)) || (uVar3 == 0x8741)) {
LAB_000d62e7:
      local_c0 = 0x515;
      goto LAB_000d62f1;
    }
    uVar10 = 0x315;
    if (fVar1 != FLOAT_001c5bd0) {
      uVar10 = 0x115;
    }
    local_c0 = 0x115;
    if (!NAN(fVar1) && !NAN(FLOAT_001c5bd0)) {
      local_c0 = uVar10;
    }
    uVar8 = *(uint *)(param_2 + 8);
    if (*puVar11 < uVar8) goto LAB_000d62fc;
LAB_000d613f:
    pvVar6 = (void *)(**(code **)(param_1 + 0xc))(uVar8 * 4 + 0x200);
    if (*(void **)(param_2 + 0xc) != (void *)0x0) {
      _memcpy(pvVar6,*(void **)(param_2 + 0xc),*puVar11 << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
    }
    *(void **)(param_2 + 0xc) = pvVar6;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar11 * 4) = local_c4;
    uVar4 = *puVar11;
    *puVar11 = uVar4 + 1;
    uVar8 = *(uint *)(param_2 + 8);
    if (uVar8 <= uVar4 + 1) {
LAB_000d61b0:
      pvVar6 = (void *)(**(code **)(param_1 + 0xc))(uVar8 * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar6,*(void **)(param_2 + 0xc),*puVar11 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar6;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
  }
  *(uint *)(*(int *)(param_2 + 0xc) + *puVar11 * 4) = CONCAT22(0x44,(ushort)bVar2 + sVar5);
  uVar8 = *puVar11;
  *puVar11 = uVar8 + 1;
  if (*(uint *)(param_2 + 8) <= uVar8 + 1) {
    pvVar6 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
    if (*(void **)(param_2 + 0xc) != (void *)0x0) {
      _memcpy(pvVar6,*(void **)(param_2 + 0xc),*puVar11 << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
    }
    *(void **)(param_2 + 0xc) = pvVar6;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
  }
  *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar11 * 4) = local_c0;
  *puVar11 = *puVar11 + 1;
  if (local_a0 != 0) {
    local_a4 = 0;
    do {
      iVar7 = local_58[local_a4] * 4;
      uVar10 = *(undefined4 *)((int)&STACKARG(0xffffffd8) + local_58[local_a4] * 4);
      if (*(uint *)(param_2 + 8) <= *puVar11) {
        pvVar6 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
        if (*(void **)(param_2 + 0xc) != (void *)0x0) {
          _memcpy(pvVar6,*(void **)(param_2 + 0xc),*puVar11 << 2);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
        }
        *(void **)(param_2 + 0xc) = pvVar6;
        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
      }
      *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar11 * 4) = uVar10;
      uVar8 = *puVar11;
      *puVar11 = uVar8 + 1;
      if ((abStack_26[iVar7] & 0x40) != 0) {
        uVar10 = *(undefined4 *)(local_34 + iVar7);
        if (*(uint *)(param_2 + 8) <= uVar8 + 1) {
          pvVar6 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar6,*(void **)(param_2 + 0xc),*puVar11 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar6;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar11 * 4) = uVar10;
        *puVar11 = *puVar11 + 1;
      }
      local_a4 = local_a4 + 1;
    } while (local_a0 != local_a4);
  }
  if ((*(short *)(iVar9 + 4) == -0x78bf) || (*(short *)(iVar9 + 4) == -0x7951)) {
    if (*(uint *)(param_2 + 8) <= *puVar11) {
      pvVar6 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar6,*(void **)(param_2 + 0xc),*puVar11 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar6;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar11 * 4) = 0x47;
    uVar8 = *puVar11;
    *puVar11 = uVar8 + 1;
    bVar2 = *(byte *)(param_1 + 0x13b2);
    if (*(uint *)(param_2 + 8) <= uVar8 + 1) {
      pvVar6 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar6,*(void **)(param_2 + 0xc),*puVar11 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar6;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(uint *)(*(int *)(param_2 + 0xc) + *puVar11 * 4) = (uint)bVar2 + param_4 & 0xffff | 0x440000;
    uVar8 = *puVar11;
    *puVar11 = uVar8 + 1;
    if (*(uint *)(param_2 + 8) <= uVar8 + 1) {
      pvVar6 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar6,*(void **)(param_2 + 0xc),*puVar11 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar6;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar11 * 4) = 0x40;
    uVar8 = *puVar11;
    *puVar11 = uVar8 + 1;
    bVar2 = *(byte *)(param_1 + 0x13b2);
    if (*(uint *)(param_2 + 8) <= uVar8 + 1) {
      pvVar6 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar6,*(void **)(param_2 + 0xc),*puVar11 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar6;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(uint *)(*(int *)(param_2 + 0xc) + *puVar11 * 4) = (ushort)((ushort)bVar2 + sVar5) | 0x440000;
    uVar8 = *puVar11;
    *puVar11 = uVar8 + 1;
    if (*(uint *)(param_2 + 8) <= uVar8 + 1) {
      pvVar6 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar6,*(void **)(param_2 + 0xc),*puVar11 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar6;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar11 * 4) = 0;
    *puVar11 = *puVar11 + 1;
    return;
  }
  ((int (*)())FUN_000d5077)(&STACKARG(0xffffffc0),&STACKARG(0xffffffb4),param_4,param_3,param_6,param_7);
  ((int (*)())FUN_000d5077)((int)abStack_3e + 2,&local_48,param_4,param_3,param_6,param_7);
  ((int (*)())FUN_000d5077)(&local_38,&local_44,param_4,param_3,param_6,param_7);
  fVar1 = *(float *)(iVar9 + 0x28);
  uVar3 = *(ushort *)(iVar9 + 2);
  local_cc = 0;
  if (uVar3 == 0x8574) {
    local_cc = 3;
    local_58[0] = 0;
    local_58[1] = 1;
    if ((local_3a & 0x40) == 0) {
      local_3a = local_3a | 0x40;
      local_47 = local_47 & 0x8f | 0x30;
    }
    local_46 = local_46 | 2;
    local_70 = 2;
  }
  else if (uVar3 < 0x8575) {
    if (uVar3 == 0x1e01) {
      local_cc = 0x47;
      local_58[0] = 0;
      local_70 = 1;
    }
    else if (uVar3 < 0x1e02) {
      if (uVar3 != 0x104) goto LAB_000d6daa;
      local_cc = 3;
      local_58[0] = 0;
      local_58[1] = 1;
      local_70 = 2;
    }
    else if (uVar3 == 0x2100) {
      local_cc = 0x49;
      local_58[0] = 0;
      local_58[1] = 1;
      local_70 = 2;
    }
    else {
      if (uVar3 != 0x84e7) goto LAB_000d6daa;
      local_cc = 0x5b;
      local_58[0] = 0;
      local_58[1] = 1;
      local_70 = 2;
    }
  }
  else if (uVar3 == 0x8744) {
    local_cc = 0x40;
    local_58[0] = 0;
    local_58[1] = 2;
    local_58[2] = 1;
    local_70 = 3;
  }
  else if (uVar3 < 0x8745) {
    if (uVar3 == 0x8575) {
      local_cc = 0x3f;
      local_58[0] = 2;
      local_58[1] = 0;
      local_58[2] = 1;
      local_70 = 3;
    }
    else {
LAB_000d6daa:
      local_70 = 0;
    }
  }
  else if (uVar3 == 0x8745) {
    local_cc = 0x40;
    local_58[0] = 0;
    local_58[1] = 2;
    local_58[2] = 1;
    if ((local_3a & 0x40) == 0) {
      local_3a = local_3a | 0x40;
      local_47 = local_47 & 0x8f | 0x30;
    }
    local_46 = local_46 | 2;
    local_70 = 3;
  }
  else {
    if (uVar3 != 0x8746) goto LAB_000d6daa;
    local_cc = 0x40;
    local_58[0] = 0;
    local_58[1] = 2;
    local_58[2] = 1;
    if ((local_3a & 0x40) == 0) {
      local_3a = local_3a | 0x40;
      local_47 = local_47 & 0x8f | 0x30;
    }
    local_47 = local_47 | 0x80;
    local_70 = 3;
  }
  bVar2 = *(byte *)(param_1 + 0x13b2);
  if (uVar3 == 0x86af) {
    if ((fVar1 != FLOAT_001c5ba4) || (NAN(fVar1) || NAN(FLOAT_001c5ba4))) {
      if ((fVar1 != FLOAT_001c5bd0) || (NAN(fVar1) || NAN(FLOAT_001c5bd0))) {
        bStack_4a = bStack_4a | 4;
      }
      local_c8 = 0x740;
      goto LAB_000d6a5e;
    }
LAB_000d6be4:
    local_c8 = 0x540;
    uVar8 = *(uint *)(param_2 + 8);
    if (*puVar11 < uVar8) goto LAB_000d6a69;
LAB_000d6bf9:
    pvVar6 = (void *)(**(code **)(param_1 + 0xc))(uVar8 * 4 + 0x200);
    if (*(void **)(param_2 + 0xc) != (void *)0x0) {
      _memcpy(pvVar6,*(void **)(param_2 + 0xc),*puVar11 << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
    }
    *(void **)(param_2 + 0xc) = pvVar6;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar11 * 4) = local_cc;
    uVar4 = *puVar11;
    *puVar11 = uVar4 + 1;
    uVar8 = *(uint *)(param_2 + 8);
    if (uVar4 + 1 < uVar8) goto LAB_000d6a89;
  }
  else {
    if ((fVar1 == FLOAT_001c5bcc) || (uVar3 == 0x8741)) goto LAB_000d6be4;
    uVar10 = 0x340;
    if (fVar1 != FLOAT_001c5bd0) {
      uVar10 = 0x140;
    }
    local_c8 = 0x140;
    if (!NAN(fVar1) && !NAN(FLOAT_001c5bd0)) {
      local_c8 = uVar10;
    }
LAB_000d6a5e:
    uVar8 = *(uint *)(param_2 + 8);
    if (uVar8 <= *puVar11) goto LAB_000d6bf9;
LAB_000d6a69:
    *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar11 * 4) = local_cc;
    uVar4 = *puVar11;
    *puVar11 = uVar4 + 1;
    uVar8 = *(uint *)(param_2 + 8);
    if (uVar4 + 1 < uVar8) goto LAB_000d6a89;
  }
  pvVar6 = (void *)(**(code **)(param_1 + 0xc))(uVar8 * 4 + 0x200);
  if (*(void **)(param_2 + 0xc) != (void *)0x0) {
    _memcpy(pvVar6,*(void **)(param_2 + 0xc),*puVar11 << 2);
    (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
  }
  *(void **)(param_2 + 0xc) = pvVar6;
  *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
LAB_000d6a89:
  *(uint *)(*(int *)(param_2 + 0xc) + *puVar11 * 4) = CONCAT22(0x44,(ushort)bVar2 + sVar5);
  uVar8 = *puVar11;
  *puVar11 = uVar8 + 1;
  if (*(uint *)(param_2 + 8) <= uVar8 + 1) {
    pvVar6 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
    if (*(void **)(param_2 + 0xc) != (void *)0x0) {
      _memcpy(pvVar6,*(void **)(param_2 + 0xc),*puVar11 << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
    }
    *(void **)(param_2 + 0xc) = pvVar6;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
  }
  *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar11 * 4) = local_c8;
  *puVar11 = *puVar11 + 1;
  if (local_70 != 0) {
    local_74 = 0;
    do {
      iVar9 = local_58[local_74];
      uVar10 = *(undefined4 *)((int)&STACKARG(0xffffffc0) + iVar9 * 4);
      if (*(uint *)(param_2 + 8) <= *puVar11) {
        pvVar6 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
        if (*(void **)(param_2 + 0xc) != (void *)0x0) {
          _memcpy(pvVar6,*(void **)(param_2 + 0xc),*puVar11 << 2);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
        }
        *(void **)(param_2 + 0xc) = pvVar6;
        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
      }
      *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar11 * 4) = uVar10;
      uVar8 = *puVar11;
      *puVar11 = uVar8 + 1;
      if ((abStack_3e[iVar9 * 4] & 0x40) != 0) {
        uVar10 = *(undefined4 *)((int)&STACKARG(0xffffffb4) + iVar9 * 4);
        if (*(uint *)(param_2 + 8) <= uVar8 + 1) {
          pvVar6 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar6,*(void **)(param_2 + 0xc),*puVar11 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar6;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar11 * 4) = uVar10;
        *puVar11 = *puVar11 + 1;
      }
      local_74 = local_74 + 1;
    } while (local_70 != local_74);
  }
  return;
}

/* FUN_000d6f8b @ 0xd6f8b (3178 bytes) */
int FUN_000d6f8b(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  uint param_3;
  uint param_4;
  int param_5;
  int param_6;
  int param_7;
  int param_8;
{
  uint uVar1;
  ushort uVar2;
  void *pvVar3;
  uint uVar4;
  uint *puVar5;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_10;
  
  puVar5 = (uint *)(param_2 + 4);
  local_1c = 0;
  local_20 = 0;
  local_24 = 0;
  local_28 = 0;
  local_2c = 0;
  local_30 = 0;
  local_38 = 0;
  if ((((param_3 == 0x1902) || (param_3 == 0x81a5)) || (param_3 == 0x81a7)) || (param_3 == 0x81a6))
  {
    param_3 = (uint)*(ushort *)(param_6 + 0x58);
  }
  local_18 = 0;
  uVar2 = (ushort)*(byte *)(param_1 + 0x13b2);
  local_34 = CONCAT22(4,uVar2 + param_5);
  if (param_4 == 0x1e01) {
    if (param_3 != 0x1908) {
      if (param_3 < 0x1909) {
        if (param_3 == 0x1906) {
          local_18 = 3;
          if (param_7 == '\0') {
            local_1c = CONCAT22(4,uVar2 + param_8);
          }
          else {
            local_1c = 0x120000;
          }
          local_1c = local_1c | 0x400000;
          local_28 = 0x4210;
          local_20 = param_5 | 0x440000;
          local_2c = 0x3444;
          local_10 = 2;
          goto LAB_000d705d;
        }
        if (param_3 != 0x1907) goto LAB_000d7056;
LAB_000d72d3:
        local_18 = 3;
        if (param_7 == '\0') {
          local_1c = CONCAT22(4,(ushort)*(byte *)(param_1 + 0x13b2) + param_8);
        }
        else {
          local_1c = 0x120000;
        }
        local_1c = local_1c | 0x400000;
        local_28 = 0x3444;
        local_20 = param_5 | 0x440000;
        local_2c = 0x4210;
        local_10 = 2;
        goto LAB_000d705d;
      }
      if (param_3 != 0x190a) {
        if (param_3 < 0x190a) goto LAB_000d72d3;
        if (param_3 != 0x8049) goto LAB_000d7056;
      }
    }
    local_18 = 0x47;
    local_1c = CONCAT22(4,param_5);
    local_10 = 1;
  }
  else if (param_4 < 0x1e02) {
    if (param_4 == 0x104) {
      local_18 = 0x40;
      if (param_7 == '\0') {
        local_1c = CONCAT22(4,uVar2 + param_8);
      }
      else {
        local_1c = 0x120000;
      }
      local_24 = param_5 | 0x440000;
      local_20 = local_24;
      if (param_3 < 0x190b) {
        if (param_3 < 0x1907) {
          if (param_3 == 0x1906) {
            local_2c = 0x555;
            local_30 = 0x444;
            goto LAB_000d76b3;
          }
        }
        else {
LAB_000d765a:
          local_2c = 0x555;
          local_30 = 0x210;
        }
        if (param_3 == 0x8049) {
          local_2c = local_2c | 0x5000;
          local_30 = local_30 | 0x3000;
          local_10 = 3;
          goto LAB_000d705d;
        }
      }
      else if (param_3 == 0x8049) goto LAB_000d765a;
LAB_000d76b3:
      local_2c = local_2c | 0x3000;
      local_30 = local_30 | 0x4000;
      local_10 = 3;
    }
    else {
      if ((param_4 != 0xbe2) || (param_3 < 0x1906)) goto LAB_000d7056;
      if (param_3 < 0x190b) {
        local_1c = CONCAT22(4,param_5);
        local_20 = CONCAT22(1,param_5);
        if (param_7 == '\0') {
          local_24 = CONCAT22(4,uVar2 + param_8);
        }
        else {
          local_24 = 0x120000;
        }
        if (*(uint *)(param_2 + 8) <= *puVar5) {
          pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar5 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar3;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar5 * 4) = 0x3f;
        uVar4 = *puVar5;
        *puVar5 = uVar4 + 1;
        if (*(uint *)(param_2 + 8) <= uVar4 + 1) {
          pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar5 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar3;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(uint *)(*(int *)(param_2 + 0xc) + *puVar5 * 4) = local_34 | 0x400000;
        uVar4 = *puVar5;
        *puVar5 = uVar4 + 1;
        if (*(uint *)(param_2 + 8) <= uVar4 + 1) {
          pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar5 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar3;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar5 * 4) = 0x15;
        uVar4 = *puVar5;
        *puVar5 = uVar4 + 1;
        if (*(uint *)(param_2 + 8) <= uVar4 + 1) {
          pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar5 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar3;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(uint *)(*(int *)(param_2 + 0xc) + *puVar5 * 4) = local_1c;
        uVar4 = *puVar5;
        *puVar5 = uVar4 + 1;
        if (*(uint *)(param_2 + 8) <= uVar4 + 1) {
          pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar5 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar3;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(uint *)(*(int *)(param_2 + 0xc) + *puVar5 * 4) = local_20;
        uVar4 = *puVar5;
        *puVar5 = uVar4 + 1;
        if (*(uint *)(param_2 + 8) <= uVar4 + 1) {
          pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar5 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar3;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(uint *)(*(int *)(param_2 + 0xc) + *puVar5 * 4) = local_24;
        *puVar5 = *puVar5 + 1;
        local_18 = 0x49;
        local_1c = CONCAT22(4,param_5);
        if (param_7 == '\0') {
          local_20 = CONCAT22(4,(ushort)*(byte *)(param_1 + 0x13b2) + param_8);
        }
        else {
          local_20 = 0x120000;
        }
        local_34 = (ushort)(uVar2 + param_5) | 0x440000;
        local_38 = 0x40;
        local_10 = 2;
      }
      else {
        if (param_3 != 0x8049) goto LAB_000d7056;
        local_18 = 0x3f;
        local_1c = CONCAT22(4,param_5);
        local_20 = CONCAT22(1,param_5);
        if (param_7 == '\0') {
          local_24 = CONCAT22(4,uVar2 + param_8);
          local_10 = 0;
        }
        else {
          local_24 = 0x120000;
          local_10 = 0;
        }
      }
    }
  }
  else if (param_4 == 0x2100) {
    if (param_3 == 0x1906) {
      local_18 = 0x49;
      local_1c = CONCAT22(4,param_5);
      if (param_7 == '\0') {
        local_20 = CONCAT22(4,uVar2 + param_8);
      }
      else {
        local_20 = 0x120000;
      }
      local_1c = local_1c | 0x400000;
      local_28 = 0x3555;
      local_10 = 2;
    }
    else if (param_3 == 0x1907) {
      local_18 = 0x49;
      local_1c = CONCAT22(4,param_5);
      if (param_7 == '\0') {
        local_20 = CONCAT22(4,uVar2 + param_8);
      }
      else {
        local_20 = 0x120000;
      }
      local_1c = local_1c | 0x400000;
      local_28 = 0x5210;
      local_10 = 2;
    }
    else {
      local_18 = 0x49;
      local_1c = CONCAT22(4,param_5);
      if (param_7 == '\0') {
        local_20 = CONCAT22(4,uVar2 + param_8);
        local_10 = 2;
      }
      else {
        local_20 = 0x120000;
        local_10 = 2;
      }
    }
  }
  else if (param_4 == 0x2101) {
    if (param_3 == 0x1907) {
      local_18 = 3;
      local_1c = CONCAT22(4,param_5);
      if (param_7 == '\0') {
        local_20 = CONCAT22(4,uVar2 + param_8);
      }
      else {
        local_20 = 0x120000;
      }
      local_1c = local_1c | 0x400000;
      local_28 = 0x4210;
      local_20 = local_20 | 0x400000;
      local_2c = 0x3444;
      local_10 = 2;
    }
    else {
      if (param_3 != 0x1908) goto LAB_000d7056;
      local_18 = 0x3f;
      local_1c = CONCAT22(4,param_5);
      local_20 = CONCAT22(4,param_5);
      if (param_7 == '\0') {
        local_24 = CONCAT22(4,uVar2 + param_8);
      }
      else {
        local_24 = 0x120000;
      }
      local_1c = local_1c | 0x400000;
      local_28 = 0x4333;
      local_20 = local_20 | 0x400000;
      local_2c = 0x4210;
      local_10 = 3;
    }
  }
  else {
LAB_000d7056:
    local_10 = 0;
  }
LAB_000d705d:
  if (*puVar5 < *(uint *)(param_2 + 8)) {
    *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar5 * 4) = local_18;
    uVar1 = *puVar5;
    *puVar5 = uVar1 + 1;
    uVar4 = *(uint *)(param_2 + 8);
    if (uVar1 + 1 < uVar4) goto LAB_000d7085;
  }
  else {
    pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
    if (*(void **)(param_2 + 0xc) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar5 << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
    }
    *(void **)(param_2 + 0xc) = pvVar3;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar5 * 4) = local_18;
    uVar1 = *puVar5;
    *puVar5 = uVar1 + 1;
    uVar4 = *(uint *)(param_2 + 8);
    if (uVar1 + 1 < uVar4) goto LAB_000d7085;
  }
  pvVar3 = (void *)(**(code **)(param_1 + 0xc))(uVar4 * 4 + 0x200);
  if (*(void **)(param_2 + 0xc) != (void *)0x0) {
    _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar5 << 2);
    (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
  }
  *(void **)(param_2 + 0xc) = pvVar3;
  *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
LAB_000d7085:
  *(uint *)(*(int *)(param_2 + 0xc) + *puVar5 * 4) = local_34;
  uVar4 = *puVar5;
  *puVar5 = uVar4 + 1;
  if ((local_34 & 0x400000) != 0) {
    if (*(uint *)(param_2 + 8) <= uVar4 + 1) {
      pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar5 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar3;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar5 * 4) = local_38;
    *puVar5 = *puVar5 + 1;
  }
  if (local_10 != 0) {
    if (*(uint *)(param_2 + 8) <= *puVar5) {
      pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar5 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar3;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(uint *)(*(int *)(param_2 + 0xc) + *puVar5 * 4) = local_1c;
    uVar4 = *puVar5;
    *puVar5 = uVar4 + 1;
    if ((local_1c & 0x400000) != 0) {
      if (*(uint *)(param_2 + 8) <= uVar4 + 1) {
        pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
        if (*(void **)(param_2 + 0xc) != (void *)0x0) {
          _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar5 << 2);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
        }
        *(void **)(param_2 + 0xc) = pvVar3;
        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
      }
      *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar5 * 4) = local_28;
      *puVar5 = *puVar5 + 1;
    }
  }
  if (1 < local_10) {
    if (*(uint *)(param_2 + 8) <= *puVar5) {
      pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar5 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar3;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(uint *)(*(int *)(param_2 + 0xc) + *puVar5 * 4) = local_20;
    uVar4 = *puVar5;
    *puVar5 = uVar4 + 1;
    if ((local_20 & 0x400000) != 0) {
      if (*(uint *)(param_2 + 8) <= uVar4 + 1) {
        pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
        if (*(void **)(param_2 + 0xc) != (void *)0x0) {
          _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar5 << 2);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
        }
        *(void **)(param_2 + 0xc) = pvVar3;
        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
      }
      *(uint *)(*(int *)(param_2 + 0xc) + *puVar5 * 4) = local_2c;
      *puVar5 = *puVar5 + 1;
    }
  }
  if (2 < local_10) {
    if (*(uint *)(param_2 + 8) <= *puVar5) {
      pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar5 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar3;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(uint *)(*(int *)(param_2 + 0xc) + *puVar5 * 4) = local_24;
    uVar4 = *puVar5;
    *puVar5 = uVar4 + 1;
    if ((local_24 & 0x400000) != 0) {
      if (*(uint *)(param_2 + 8) <= uVar4 + 1) {
        pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
        if (*(void **)(param_2 + 0xc) != (void *)0x0) {
          _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar5 << 2);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
        }
        *(void **)(param_2 + 0xc) = pvVar3;
        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
      }
      *(uint *)(*(int *)(param_2 + 0xc) + *puVar5 * 4) = local_30;
      *puVar5 = *puVar5 + 1;
    }
  }
  return;
}

/* FUN_000d7bf5 @ 0xd7bf5 (4641 bytes) */
int FUN_000d7bf5(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  uint uVar1;
  uint uVar2;
  void *pvVar3;
  ushort uVar4;
  short sVar5;
  char *pcVar6;
  uint *puVar7;
  undefined4 uVar8;
  uint uVar9;
  bool bVar10;
  int local_b8;
  uint local_a8;
  int local_30;
  int local_2c;
  int local_28;
  char acStack_1c [16];
  
  puVar7 = (uint *)(param_2 + 4);
  if (*(char *)(param_1 + 0x13b2) != '\0') {
    local_30 = param_1;
    local_2c = param_1;
    local_28 = param_1;
    local_a8 = 0;
    local_b8 = param_1 + 0x450;
    do {
      if (*(int *)(local_30 + 0x13f8) != 0) {
        sVar5 = (short)local_a8;
        if ((*(byte *)(param_1 + 0x45) & 8) == 0) {
          bVar10 = false;
          uVar1 = (int)(uint)*(byte *)(param_1 + 0x20) >> ((byte)local_a8 & 0x1f);
        }
        else {
          bVar10 = *(char *)(local_a8 + 0x71 + *(int *)(param_1 + 0x1168)) == '\0';
          uVar1 = (int)(uint)*(byte *)(param_1 + 0x20) >> ((byte)local_a8 & 0x1f);
        }
        if ((uVar1 & 1) == 0) {
          if (*(short *)(local_2c + 0x450) == -0x7a90) {
            if (*(short *)(local_b8 + 4) == -0x7885) goto LAB_000d8171;
            uVar9 = (local_a8 & 0xff) << 0x10 | 0x800005d;
            uVar1 = *(uint *)(param_2 + 8);
            if (uVar1 <= *puVar7) goto LAB_000d8d5c;
          }
          else {
            uVar9 = (local_a8 & 0xff) << 0x10 | 0x800005d;
            uVar1 = *(uint *)(param_2 + 8);
            if (uVar1 <= *puVar7) {
LAB_000d8d5c:
              pvVar3 = (void *)(**(code **)(param_1 + 0xc))(uVar1 * 4 + 0x200);
              if (*(void **)(param_2 + 0xc) != (void *)0x0) {
                _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
                (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
              }
              *(void **)(param_2 + 0xc) = pvVar3;
              *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
            }
          }
          *(uint *)(*(int *)(param_2 + 0xc) + *puVar7 * 4) = uVar9;
          uVar1 = *puVar7;
          *puVar7 = uVar1 + 1;
          if (*(uint *)(param_2 + 8) <= uVar1 + 1) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(uint *)(*(int *)(param_2 + 0xc) + *puVar7 * 4) = CONCAT22(4,sVar5);
          uVar1 = *puVar7 + 1;
          *puVar7 = uVar1;
          if ((param_3 == '\0') || (acStack_1c[local_a8] == '\0')) {
            if ((!bVar10) ||
               (((*(byte *)(param_1 + 0x44) & 4) != 0 &&
                ((*(uint *)(param_1 + 0xec) & 1 << ((byte)local_a8 & 0x1f)) != 0)))) {
              uVar9 = CONCAT22(0x11,sVar5);
              goto LAB_000d8388;
            }
            uVar9 = 0x410011;
            uVar2 = *(uint *)(param_2 + 8);
            if (uVar2 <= uVar1) goto LAB_000d82b3;
LAB_000d8399:
            *(uint *)(*(int *)(param_2 + 0xc) + *puVar7 * 4) = uVar9;
            uVar1 = *puVar7;
            *puVar7 = uVar1 + 1;
            uVar9 = *(uint *)(param_2 + 8);
            if (uVar9 <= uVar1 + 1) {
LAB_000d8315:
              pvVar3 = (void *)(**(code **)(param_1 + 0xc))(uVar9 * 4 + 0x200);
              if (*(void **)(param_2 + 0xc) != (void *)0x0) {
                _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
                (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
              }
              *(void **)(param_2 + 0xc) = pvVar3;
              *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
            }
          }
          else {
            uVar9 = CONCAT22(4,sVar5 + (ushort)*(byte *)(param_1 + 0x13b2) * 2);
LAB_000d8388:
            uVar9 = uVar9 | 0x400000;
            uVar2 = *(uint *)(param_2 + 8);
            if (uVar1 < uVar2) goto LAB_000d8399;
LAB_000d82b3:
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(uVar2 * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
            *(uint *)(*(int *)(param_2 + 0xc) + *puVar7 * 4) = uVar9;
            uVar1 = *puVar7;
            *puVar7 = uVar1 + 1;
            uVar9 = *(uint *)(param_2 + 8);
            if (uVar9 <= uVar1 + 1) goto LAB_000d8315;
          }
          *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar7 * 4) = 0x603210;
          *puVar7 = *puVar7 + 1;
        }
        else {
          if (*(uint *)(param_2 + 8) <= *puVar7) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar7 * 4) = 0x49;
          uVar1 = *puVar7;
          *puVar7 = uVar1 + 1;
          if (*(uint *)(param_2 + 8) <= uVar1 + 1) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar7 * 4) = 0x40020;
          uVar1 = *puVar7;
          *puVar7 = uVar1 + 1;
          if (*(uint *)(param_2 + 8) <= uVar1 + 1) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(uint *)(*(int *)(param_2 + 0xc) + *puVar7 * 4) = CONCAT22(0x11,sVar5);
          uVar1 = *puVar7;
          *puVar7 = uVar1 + 1;
          uVar4 = sVar5 + 0x14;
          if (*(uint *)(param_2 + 8) <= uVar1 + 1) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(uint *)(*(int *)(param_2 + 0xc) + *puVar7 * 4) = uVar4 | 0x410000;
          uVar1 = *puVar7;
          *puVar7 = uVar1 + 1;
          pcVar6 = (char *)(local_28 + 0x21);
          uVar9 = 0x50;
          if (*(char *)(local_28 + 0x21) != '\x01') {
            uVar9 = 5;
          }
          if (*(uint *)(param_2 + 8) <= uVar1 + 1) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(uint *)(*(int *)(param_2 + 0xc) + *puVar7 * 4) = uVar9 | 0x5500;
          uVar1 = *puVar7;
          *puVar7 = uVar1 + 1;
          if (*(uint *)(param_2 + 8) <= uVar1 + 1) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(uint *)(*(int *)(param_2 + 0xc) + *puVar7 * 4) = (local_a8 & 0xff) << 0x10 | 0x800005d;
          uVar1 = *puVar7;
          *puVar7 = uVar1 + 1;
          if (*(uint *)(param_2 + 8) <= uVar1 + 1) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar7 * 4) = 0x40020;
          uVar1 = *puVar7;
          *puVar7 = uVar1 + 1;
          if (*(uint *)(param_2 + 8) <= uVar1 + 1) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar7 * 4) = 0x440020;
          uVar1 = *puVar7;
          *puVar7 = uVar1 + 1;
          if (*(uint *)(param_2 + 8) <= uVar1 + 1) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar7 * 4) = 0x603210;
          uVar1 = *puVar7;
          *puVar7 = uVar1 + 1;
          if (*(uint *)(param_2 + 8) <= uVar1 + 1) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar7 * 4) = 0x40;
          uVar1 = *puVar7;
          *puVar7 = uVar1 + 1;
          if (*(uint *)(param_2 + 8) <= uVar1 + 1) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar7 * 4) = 0x40021;
          uVar1 = *puVar7;
          *puVar7 = uVar1 + 1;
          if (*(uint *)(param_2 + 8) <= uVar1 + 1) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(uint *)(*(int *)(param_2 + 0xc) + *puVar7 * 4) = CONCAT22(0x11,sVar5);
          uVar1 = *puVar7;
          *puVar7 = uVar1 + 1;
          if (*(uint *)(param_2 + 8) <= uVar1 + 1) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(uint *)(*(int *)(param_2 + 0xc) + *puVar7 * 4) = uVar4 | 0x410000;
          uVar1 = *puVar7;
          *puVar7 = uVar1 + 1;
          uVar9 = 0x51;
          if (*pcVar6 != '\x01') {
            uVar9 = 0x15;
          }
          if (*(uint *)(param_2 + 8) <= uVar1 + 1) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(uint *)(*(int *)(param_2 + 0xc) + *puVar7 * 4) = uVar9 | 0x5500;
          uVar1 = *puVar7;
          *puVar7 = uVar1 + 1;
          if (*(uint *)(param_2 + 8) <= uVar1 + 1) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(uint *)(*(int *)(param_2 + 0xc) + *puVar7 * 4) = uVar4 | 0x410000;
          uVar1 = *puVar7;
          *puVar7 = uVar1 + 1;
          uVar9 = 0x42;
          if (*pcVar6 != '\x01') {
            uVar9 = 0x24;
          }
          if (*(uint *)(param_2 + 8) <= uVar1 + 1) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(uint *)(*(int *)(param_2 + 0xc) + *puVar7 * 4) = uVar9 | 0x4400;
          uVar1 = *puVar7;
          *puVar7 = uVar1 + 1;
          if (*(uint *)(param_2 + 8) <= uVar1 + 1) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(uint *)(*(int *)(param_2 + 0xc) + *puVar7 * 4) =
               (uint)(byte)((byte)local_a8 + 8) << 0x10 | 0x800005d;
          uVar1 = *puVar7;
          *puVar7 = uVar1 + 1;
          if (*(uint *)(param_2 + 8) <= uVar1 + 1) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar7 * 4) = 0x40021;
          uVar1 = *puVar7;
          *puVar7 = uVar1 + 1;
          if (*(uint *)(param_2 + 8) <= uVar1 + 1) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar7 * 4) = 0x440021;
          uVar1 = *puVar7;
          *puVar7 = uVar1 + 1;
          if (*(uint *)(param_2 + 8) <= uVar1 + 1) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar7 * 4) = 0x603210;
          uVar1 = *puVar7;
          *puVar7 = uVar1 + 1;
          if (*(uint *)(param_2 + 8) <= uVar1 + 1) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar7 * 4) = 0x5b;
          uVar1 = *puVar7;
          *puVar7 = uVar1 + 1;
          if (*(uint *)(param_2 + 8) <= uVar1 + 1) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar7 * 4) = 0x40022;
          uVar1 = *puVar7;
          *puVar7 = uVar1 + 1;
          if (*(uint *)(param_2 + 8) <= uVar1 + 1) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(uint *)(*(int *)(param_2 + 0xc) + *puVar7 * 4) = local_a8 & 0xffff | 0x510000;
          uVar1 = *puVar7;
          *puVar7 = uVar1 + 1;
          uVar8 = 0x1111;
          if (*pcVar6 == '\x01') {
            uVar8 = 0;
          }
          if (*(uint *)(param_2 + 8) <= uVar1 + 1) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar7 * 4) = uVar8;
          uVar1 = *puVar7;
          *puVar7 = uVar1 + 1;
          if (*(uint *)(param_2 + 8) <= uVar1 + 1) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(uint *)(*(int *)(param_2 + 0xc) + *puVar7 * 4) = uVar4 | 0x410000;
          uVar1 = *puVar7;
          *puVar7 = uVar1 + 1;
          if (*(uint *)(param_2 + 8) <= uVar1 + 1) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar7 * 4) = 0x3333;
          uVar1 = *puVar7;
          *puVar7 = uVar1 + 1;
          if (*(uint *)(param_2 + 8) <= uVar1 + 1) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar7 * 4) = 0x3000d;
          uVar1 = *puVar7;
          *puVar7 = uVar1 + 1;
          if (*(uint *)(param_2 + 8) <= uVar1 + 1) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(uint *)(*(int *)(param_2 + 0xc) + *puVar7 * 4) = CONCAT22(4,sVar5);
          uVar1 = *puVar7;
          *puVar7 = uVar1 + 1;
          if (*(uint *)(param_2 + 8) <= uVar1 + 1) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar7 * 4) = 0x40022;
          uVar1 = *puVar7;
          *puVar7 = uVar1 + 1;
          if (*(uint *)(param_2 + 8) <= uVar1 + 1) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar7 * 4) = 0x40021;
          uVar1 = *puVar7;
          *puVar7 = uVar1 + 1;
          if (*(uint *)(param_2 + 8) <= uVar1 + 1) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar7 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar7 * 4) = 0x40020;
          *puVar7 = *puVar7 + 1;
        }
      }
LAB_000d8171:
      local_a8 = local_a8 + 1;
      local_b8 = local_b8 + 0xcc;
      local_30 = local_30 + 4;
      local_2c = local_2c + 0xcc;
      local_28 = local_28 + 1;
    } while ((int)local_a8 < (int)(uint)*(byte *)(param_1 + 0x13b2));
  }
  return;
}

/* FUN_000d8e16 @ 0xd8e16 (69 bytes) */
int FUN_000d8e16(param_1, param_2, param_3)
  undefined4 param_1;
  uint *param_2;
  int param_3;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    uVar2 = *param_2;
    if (uVar2 != 0) {
      iVar1 = 0;
      do {
        if ((uVar2 & 1) != 0) {
          if (param_3 == 0) {
            return iVar1 + iVar3;
          }
          param_3 = param_3 + -1;
        }
        iVar1 = iVar1 + 1;
        uVar2 = uVar2 >> 1;
      } while (uVar2 != 0);
    }
    iVar3 = iVar3 + 0x20;
    param_2 = param_2 + 1;
  } while (iVar3 != 0x100);
  return -1;
}

/* FUN_000d8e5c @ 0xd8e5c (249 bytes) */
int FUN_000d8e5c(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  
  if (param_6 == '\0') {
    piVar1 = *(int **)(param_5 + 0x84);
    if (piVar1 != (int *)0x0) {
      uVar2 = *(uint *)(param_5 + 0x78);
      if (uVar2 == 0) {
LAB_000d8ed0:
        if (*(uint *)(param_5 + 0x6c) <= uVar2) {
          return 0;
        }
        *(uint *)(param_5 + 0x78) = uVar2 + 1;
        iVar6 = uVar2 * 0x14;
      }
      else if (*piVar1 == param_2) {
        iVar6 = 0;
      }
      else {
        uVar4 = 0;
        iVar3 = 0x14;
        piVar5 = piVar1;
        do {
          iVar6 = iVar3;
          piVar5 = piVar5 + 5;
          uVar4 = uVar4 + 1;
          if (uVar2 == uVar4) goto LAB_000d8ed0;
          iVar3 = iVar6 + 0x14;
        } while (*piVar5 != param_2);
      }
      *(int *)(iVar6 + (int)piVar1) = param_2;
      ((int *)(iVar6 + (int)piVar1))[param_4 + 1] = param_3;
      return 1;
    }
  }
  else {
    uVar2 = *(uint *)(param_5 + 0x54);
    if (uVar2 < *(uint *)(param_5 + 0x48)) {
      *(uint *)(param_5 + 0x54) = uVar2 + 1;
      piVar1 = (int *)(*(int *)(param_5 + 0x60) + uVar2 * 0x24);
      *piVar1 = param_2;
      piVar1[1] = param_4;
      piVar1[2] = 1;
      piVar1[5] = param_3;
      return 1;
    }
  }
  return 0;
}

/* FUN_000d8f56 @ 0xd8f56 (241 bytes) */
int FUN_000d8f56(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  
  if (param_6 == '\0') {
    piVar1 = *(int **)(param_5 + 0x88);
    if (piVar1 != (int *)0x0) {
      uVar2 = *(uint *)(param_5 + 0x7c);
      if (uVar2 == 0) {
LAB_000d8fc6:
        if (*(uint *)(param_5 + 0x70) <= uVar2) {
          return 0;
        }
        *(uint *)(param_5 + 0x7c) = uVar2 + 1;
        iVar6 = uVar2 * 0x14;
      }
      else if (*piVar1 == param_2) {
        iVar6 = 0;
      }
      else {
        uVar4 = 0;
        iVar3 = 0x14;
        piVar5 = piVar1;
        do {
          iVar6 = iVar3;
          piVar5 = piVar5 + 5;
          uVar4 = uVar4 + 1;
          if (uVar2 == uVar4) goto LAB_000d8fc6;
          iVar3 = iVar6 + 0x14;
        } while (*piVar5 != param_2);
      }
      *(int *)(iVar6 + (int)piVar1) = param_2;
      ((int *)(iVar6 + (int)piVar1))[param_4 + 1] = param_3;
      return 1;
    }
  }
  else {
    uVar2 = *(uint *)(param_5 + 0x58);
    if (uVar2 < *(uint *)(param_5 + 0x4c)) {
      *(uint *)(param_5 + 0x58) = uVar2 + 1;
      piVar1 = (int *)(*(int *)(param_5 + 100) + uVar2 * 0x24);
      *piVar1 = param_2;
      piVar1[1] = param_4;
      piVar1[2] = 0;
      piVar1[5] = param_3;
      return 1;
    }
  }
  return 0;
}

/* FUN_000d9048 @ 0xd9048 (253 bytes) */
int FUN_000d9048(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  
  if (param_6 == '\0') {
    piVar1 = *(int **)(param_5 + 0x8c);
    if (piVar1 != (int *)0x0) {
      uVar2 = *(uint *)(param_5 + 0x80);
      if (uVar2 == 0) {
LAB_000d90c0:
        if (*(uint *)(param_5 + 0x74) <= uVar2) {
          return 0;
        }
        *(uint *)(param_5 + 0x80) = uVar2 + 1;
        iVar6 = uVar2 * 0x14;
      }
      else if (*piVar1 == param_2) {
        iVar6 = 0;
      }
      else {
        uVar4 = 0;
        iVar3 = 0x14;
        piVar5 = piVar1;
        do {
          iVar6 = iVar3;
          piVar5 = piVar5 + 5;
          uVar4 = uVar4 + 1;
          if (uVar2 == uVar4) goto LAB_000d90c0;
          iVar3 = iVar6 + 0x14;
        } while (*piVar5 != param_2);
      }
      *(int *)(iVar6 + (int)piVar1) = param_2;
      ((int *)(iVar6 + (int)piVar1))[param_4 + 1] = (uint)param_3;
      return 1;
    }
  }
  else {
    uVar2 = *(uint *)(param_5 + 0x5c);
    if (uVar2 < *(uint *)(param_5 + 0x50)) {
      *(uint *)(param_5 + 0x5c) = uVar2 + 1;
      piVar1 = (int *)(*(int *)(param_5 + 0x68) + uVar2 * 0x24);
      *piVar1 = param_2;
      piVar1[1] = param_4;
      piVar1[2] = 2;
      piVar1[5] = (uint)param_3;
      return 1;
    }
  }
  return 0;
}

/* FUN_000d9146 @ 0xd9146 (63 bytes) */
int FUN_000d9146(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  int param_6;
{
  undefined4 *puVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_6 + 0x54);
  if (uVar2 < *(uint *)(param_6 + 0x48)) {
    *(uint *)(param_6 + 0x54) = uVar2 + 1;
    puVar1 = (undefined4 *)(*(int *)(param_6 + 0x60) + uVar2 * 0x24);
    *puVar1 = param_2;
    puVar1[1] = param_5;
    puVar1[2] = param_3;
    puVar1[4] = param_4;
    return 1;
  }
  return 0;
}

/* FUN_000d9186 @ 0xd9186 (122 bytes) */
int FUN_000d9186(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  int param_7;
  int param_8;
  undefined4 param_9;
  int param_10;
{
  undefined4 *puVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_10 + 0x58);
  if (uVar2 < *(uint *)(param_10 + 0x4c)) {
    *(uint *)(param_10 + 0x58) = uVar2 + 1;
    puVar1 = (undefined4 *)(*(int *)(param_10 + 100) + uVar2 * 0x24);
    *puVar1 = param_2;
    puVar1[1] = 0;
    if (param_8 == -1) {
      puVar1[2] = (param_7 != 0xff) + 0x15;
    }
    else {
      puVar1[2] = (param_7 != 0xff) + 0x17;
    }
    puVar1[4] = param_5;
    puVar1[3] = param_6;
    puVar1[8] = param_9;
    puVar1[7] = param_8;
    return 1;
  }
  return 0;
}

/* FUN_000d9200 @ 0xd9200 (10 bytes) */
int FUN_000d9200()
{
  return 1;
}

/* FUN_000d920a @ 0xd920a (48 bytes) */
int FUN_000d920a(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  if (param_2 == '\0') {
    iVar1 = *(int *)(*(int *)(param_1 + 0x2c) + 0x48);
  }
  else {
    iVar1 = *(int *)(*(int *)(param_1 + 0x30) + 0x48);
  }
  if (iVar1 != 0) {
    return (*(byte *)(iVar1 + 1) & 4) == 0;
  }
  return true;
}

/* FUN_000d923a @ 0xd923a (10 bytes) */
int FUN_000d923a()
{
  return 1;
}

/* FUN_000d9244 @ 0xd9244 (28 bytes) */
int FUN_000d9244(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 != '\0') {
    return *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x3c);
  }
  return *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x40);
}

/* FUN_000d9260 @ 0xd9260 (28 bytes) */
int FUN_000d9260(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 != '\0') {
    return *(undefined4 *)(*(int *)(param_1 + 0x30) + 0xc);
  }
  return *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x10);
}

/* FUN_000d927c @ 0xd927c (28 bytes) */
int FUN_000d927c(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 != '\0') {
    return *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x24);
  }
  return *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x28);
}

/* FUN_000d9298 @ 0xd9298 (93 bytes) */
int FUN_000d9298(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 *param_5;
{
  undefined4 *puVar1;
  
  if (param_2 != '\0') {
    puVar1 = (undefined4 *)(*(int *)(*(int *)(param_1 + 0x30) + 0x30) + param_3 * 0x10);
    *param_5 = *puVar1;
    param_5[1] = puVar1[1];
    param_5[2] = puVar1[2];
    param_5[3] = puVar1[3];
    return;
  }
  puVar1 = (undefined4 *)(*(int *)(*(int *)(param_1 + 0x2c) + 0x34) + param_3 * 0x10);
  *param_5 = *puVar1;
  param_5[1] = puVar1[1];
  param_5[2] = puVar1[2];
  param_5[3] = puVar1[3];
  return;
}

/* FUN_000d92f6 @ 0xd92f6 (92 bytes) */
int FUN_000d92f6(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 *param_5;
{
  undefined4 *puVar1;
  
  if (param_2 != '\0') {
    puVar1 = (undefined4 *)(**(int **)(param_1 + 0x30) + param_3 * 0x10);
    *param_5 = *puVar1;
    param_5[1] = puVar1[1];
    param_5[2] = puVar1[2];
    param_5[3] = puVar1[3];
    return;
  }
  puVar1 = (undefined4 *)(*(int *)(*(int *)(param_1 + 0x2c) + 4) + param_3 * 0x10);
  *param_5 = *puVar1;
  param_5[1] = puVar1[1];
  param_5[2] = puVar1[2];
  param_5[3] = puVar1[3];
  return;
}

/* FUN_000d9352 @ 0xd9352 (50 bytes) */
int FUN_000d9352(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 *param_5;
{
  if (param_2 != '\0') {
    *param_5 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x30) + 0x18) + param_3 * 4);
    return;
  }
  *param_5 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x2c) + 0x1c) + param_3 * 4);
  return;
}

/* FUN_000d9384 @ 0xd9384 (36 bytes) */
int FUN_000d9384(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  
  if (param_2 != '\0') {
    piVar1 = (int *)(*(int *)(param_1 + 0x3c) + 0x100);
    *piVar1 = *piVar1 + 1;
    return;
  }
  piVar1 = (int *)(*(int *)(param_1 + 0x38) + 0x100);
  *piVar1 = *piVar1 + 1;
  return;
}

/* FUN_000d93a8 @ 0xd93a8 (661 bytes) */
int FUN_000d93a8(param_1, param_2)
  undefined4 *param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar4 = (*(code *)param_2[0xc])(param_2[0xb],0x3f8);
  uVar5 = param_2[0xd];
  *param_1 = uVar5;
  uVar1 = param_2[0xb];
  param_1[1] = uVar1;
  param_1[3] = *param_2;
  param_1[5] = param_2[1];
  param_1[4] = param_2[0x14];
  if (iVar4 == 0) {
    param_1[2] = 0;
    return;
  }
  FUN_000e2d5a(iVar4,uVar1,param_2[0xc],uVar5,0,0,param_2[0xf],param_2[0x10],param_2[0x11],
               param_2[0x12],param_2[0x13],param_2[0xe]);
  param_1[2] = iVar4;
  if (*(int *)(iVar4 + 0x5c) != 0) {
    return;
  }
  iVar4 = _setjmp(*(int **)(iVar4 + 4));
  if (iVar4 != 0) {
    return;
  }
  if (param_1[3] == -1) {
    param_1[10] = param_2[2];
  }
  else {
    uVar5 = FUN_000cb1a2(param_1[3]);
    param_1[10] = uVar5;
  }
  iVar4 = param_2[4];
  iVar2 = param_2[3];
  iVar3 = param_1[10];
  if (iVar3 == 2) {
    FUN_000e2ebc(param_1[2],2);
    if (iVar4 - 1U < 0x20c) {
      *(int *)(*(int *)(*(int *)(param_1[2] + 0x58) + 8) + 0x40) = iVar4;
    }
    else {
      *(undefined4 *)(*(int *)(*(int *)(param_1[2] + 0x58) + 8) + 0x40) = 0x20c;
    }
    if (iVar2 - 1U < 0x100) goto LAB_000d955b;
  }
  else {
    if (iVar3 == 3) {
      FUN_000e2ebc(param_1[2],4);
      if (iVar4 - 1U < 0x200) {
        *(int *)(*(int *)(*(int *)(param_1[2] + 0x58) + 8) + 0x40) = iVar4;
      }
      else {
        *(undefined4 *)(*(int *)(*(int *)(param_1[2] + 0x58) + 8) + 0x40) = 0x200;
      }
      if (0x3ff < iVar2 - 1U) {
        *(undefined4 *)(*(int *)(*(int *)(param_1[2] + 0x58) + 4) + 0x40) = 0x400;
        return;
      }
LAB_000d955b:
      *(int *)(*(int *)(*(int *)(param_1[2] + 0x58) + 4) + 0x40) = iVar2;
      return;
    }
    if (iVar3 != 1) {
      *(undefined4 *)(param_1[2] + 0x5c) = 0xe;
      FUN_000e2ebc(param_1[2],1);
      return;
    }
    FUN_000e2ebc(param_1[2],1);
    if (iVar4 - 1U < 0x60) {
      *(int *)(*(int *)(*(int *)(param_1[2] + 0x58) + 8) + 0x40) = iVar4;
    }
    else {
      *(undefined4 *)(*(int *)(*(int *)(param_1[2] + 0x58) + 8) + 0x40) = 0x60;
    }
    if (iVar2 - 1U < 0x100) {
      *(int *)(*(int *)(*(int *)(param_1[2] + 0x58) + 4) + 0x40) = iVar4;
      return;
    }
  }
  *(undefined4 *)(*(int *)(*(int *)(param_1[2] + 0x58) + 4) + 0x40) = 0x100;
  return;
}

/* FUN_000d9646 @ 0xd9646 (88 bytes) */
int FUN_000d9646(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x38) = param_3;
  *(undefined4 *)(param_1 + 0x3c) = param_3;
  *(undefined4 *)(param_1 + 0x40) = param_3;
  *(int *)(param_1 + 0x2c) = param_2;
  *(int *)(param_1 + 0x30) = param_2;
  *(int *)(param_1 + 0x34) = param_2;
  if (*(int *)(param_1 + 8) != 0) {
    uVar1 = FUN_000e39de(*(int *)(param_1 + 8),param_3,*(undefined4 *)(param_2 + 0x4c),
                         *(undefined4 *)(param_2 + 0x54),param_1);
    return uVar1;
  }
  return 2;
}

