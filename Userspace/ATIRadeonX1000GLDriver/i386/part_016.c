#include "decls.h"

/* FUN_000b155a @ 0xb155a (438 bytes) */
int FUN_000b155a(param_1, param_2)
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
  *(undefined4 *)(param_2[2] + *param_2 * 4) = 0x47;
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
  *(undefined4 *)(param_2[2] + *param_2 * 4) = 0x410000;
  uVar1 = *param_2;
  *param_2 = uVar1 + 1;
  if (uVar1 + 1 < param_2[1]) {
    *(undefined4 *)(param_2[2] + *param_2 * 4) = 0x4444;
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
  *(undefined4 *)(param_2[2] + *param_2 * 4) = 0x4444;
  *param_2 = *param_2 + 1;
  return;
}

/* FUN_000b1710 @ 0xb1710 (989 bytes) */
int FUN_000b1710(param_1, param_2, param_3, param_4)
  int param_1;
  uint *param_2;
  int param_3;
  int param_4;
{
  void *pvVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 local_28;
  int local_20;
  int local_10;
  
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (param_2[1] <= *param_2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(param_2[2] + *param_2 * 4) = 0x1ff0016;
  uVar5 = *param_2;
  *param_2 = uVar5 + 1;
  if (param_2[1] <= uVar5 + 1) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(param_2[2] + *param_2 * 4) = 0x120000;
  uVar5 = *param_2;
  *param_2 = uVar5 + 1;
  if (*(char *)(param_4 + 0x6c) == '\0') {
    if ((*(ushort *)(param_1 + 0x44) & 0x801) == 1) {
      if (*(short *)(iVar4 + 0x2d48) != -0x7e06) goto LAB_000b17c3;
    }
    else if ((*(byte *)(param_1 + 0x45) & 1) == 0) goto LAB_000b17c3;
  }
  if (param_2[1] <= uVar5 + 1) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(param_2[2] + *param_2 * 4) = 0x1ff0016;
  uVar5 = *param_2;
  *param_2 = uVar5 + 1;
  if (param_2[1] <= uVar5 + 1) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(param_2[2] + *param_2 * 4) = 0x130000;
  *param_2 = *param_2 + 1;
LAB_000b17c3:
  if (*(char *)(param_1 + 0x13b0) != '\0') {
    iVar4 = 0;
    do {
      if (((int)(uint)*(byte *)(param_3 + 1) >> ((byte)iVar4 & 0x1f) & 1U) != 0) {
        local_28 = CONCAT22(0x11,(short)iVar4);
        if (*param_2 < param_2[1]) {
          *(undefined4 *)(param_2[2] + *param_2 * 4) = 0x1ff0016;
          uVar5 = *param_2;
          *param_2 = uVar5 + 1;
          uVar3 = param_2[1];
          if (uVar3 <= uVar5 + 1) goto LAB_000b189f;
        }
        else {
          pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
          if ((void *)param_2[2] != (void *)0x0) {
            _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
            (**(code **)(param_1 + 0x18))(param_2[2]);
          }
          param_2[2] = (uint)pvVar1;
          param_2[1] = param_2[1] + 0x80;
          *(undefined4 *)(param_2[2] + *param_2 * 4) = 0x1ff0016;
          uVar5 = *param_2;
          *param_2 = uVar5 + 1;
          uVar3 = param_2[1];
          if (uVar3 <= uVar5 + 1) {
LAB_000b189f:
            pvVar1 = (void *)(**(code **)(param_1 + 0xc))(uVar3 * 4 + 0x200);
            if ((void *)param_2[2] != (void *)0x0) {
              _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
              (**(code **)(param_1 + 0x18))(param_2[2]);
            }
            param_2[2] = (uint)pvVar1;
            param_2[1] = param_2[1] + 0x80;
          }
        }
        *(undefined4 *)(param_2[2] + *param_2 * 4) = local_28;
        *param_2 = *param_2 + 1;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)(uint)*(byte *)(param_1 + 0x13b0));
  }
  uVar5 = (uint)*(ushort *)(param_3 + 0x14);
  if (uVar5 != 0) {
    local_20 = 0;
    local_10 = 0;
    do {
      pcVar2 = (char *)(local_10 + *(int *)(param_4 + 0xc));
      if (((*pcVar2 != '\0') && (pcVar2[1] != '\0')) ||
         ((pcVar2 = (char *)(*(int *)(param_4 + 0xc) + (local_20 + uVar5) * 0xc), *pcVar2 != '\0' &&
          (pcVar2[1] != '\0')))) {
        if (param_2[1] <= *param_2) {
          pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
          if ((void *)param_2[2] != (void *)0x0) {
            _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
            (**(code **)(param_1 + 0x18))(param_2[2]);
          }
          param_2[2] = (uint)pvVar1;
          param_2[1] = param_2[1] + 0x80;
        }
        *(uint *)(param_2[2] + *param_2 * 4) = local_20 << 0x10 | 0x19;
        *param_2 = *param_2 + 1;
        uVar5 = (uint)*(ushort *)(param_3 + 0x14);
      }
      local_20 = local_20 + 1;
      local_10 = local_10 + 0xc;
    } while (local_20 < (int)uVar5);
  }
  return;
}

/* FUN_000b1aed @ 0xb1aed (3146 bytes) */
int FUN_000b1aed(param_1)
  int param_1;
{
  undefined4 *puVar1;
  code *pcVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  undefined1 *puVar12;
  int *piVar13;
  uint local_94;
  undefined1 *local_90;
  int local_74;
  undefined1 *local_70;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_48;
  uint local_44;
  int local_40;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 local_28 [8];
  undefined4 local_20;
  
  iVar10 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (*(char *)(param_1 + 0x1134) == '\0') {
    local_74 = *(int *)(param_1 + 0x1144);
  }
  else {
    local_74 = *(int *)(param_1 + 0x1154) + 0x10;
  }
  local_70 = *(undefined1 **)(*(int *)(local_74 + 0x70) + *(int *)(param_1 + 0x113c) * 4);
  if (local_70 != (undefined1 *)0x0) {
    if ((*(byte *)(param_1 + 0x45) & 8) == 0) {
      if ((((*(byte *)(param_1 + 0x44) & 1) != 0) && (*(short *)(iVar10 + 0x2d48) == -0x7e06)) ||
         ((*(ushort *)(param_1 + 0x44) & 0x101) == 0x100)) goto LAB_000b1e05;
LAB_000b1b68:
      if (local_70[0x118] != '\0') goto LAB_000b1b7c;
LAB_000b1e1c:
      if (*(char *)(param_1 + 0x1136) != '\0') {
        *local_70 = 0;
      }
    }
    else {
      if (((*(byte *)(param_1 + 0x45) & 1) == 0) ||
         (*(char *)(*(int *)(param_1 + 0x1168) + 0x6e) == '\0')) goto LAB_000b1b68;
LAB_000b1e05:
      if (local_70[0x118] == '\x01') goto LAB_000b1e1c;
LAB_000b1b7c:
      local_70[0x119] = 1;
    }
    if (local_70[0x119] == '\0') goto LAB_000b1d1a;
  }
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  FUN_000b01a8();
  FUN_000b01a8();
  iVar4 = 1;
  do {
    local_28[iVar4 + -1] = 0;
    iVar4 = iVar4 + 1;
  } while (iVar4 != 9);
  if (local_70 != (undefined1 *)0x0) {
    puVar1 = (undefined4 *)(*(int *)(local_74 + 0x70) + *(int *)(param_1 + 0x113c) * 4);
    uVar5 = *puVar1;
    *puVar1 = 0;
    (**(code **)(param_1 + 0x1158))(param_1,uVar5);
  }
  iVar4 = *(int *)(param_1 + 0x113c);
  iVar7 = *(int *)(local_74 + 0x70);
  pcVar2 = *(code **)(param_1 + 0x10);
  uVar5 = (**(code **)(param_1 + 0x1284))(param_1);
  uVar5 = (*pcVar2)(1,uVar5);
  *(undefined4 *)(iVar7 + iVar4 * 4) = uVar5;
  local_70 = *(undefined1 **)(*(int *)(local_74 + 0x70) + *(int *)(param_1 + 0x113c) * 4);
  *local_70 = 0;
  iVar4 = *(int *)(local_74 + 4);
  ((int (*)())FUN_000b1710)(local_74);
  ((int (*)())FUN_000b155a)();
  if (iVar4 < 1) {
    if ((*(ushort *)(param_1 + 0x44) & 0x801) != 1) goto LAB_000b1c96;
LAB_000b1e34:
    if (*(short *)(iVar10 + 0x2d48) == -0x7e06) goto LAB_000b1e46;
LAB_000b1ca0:
    local_70[0x118] = 0;
  }
  else {
    local_58 = 0;
    local_54 = 0;
    local_50 = 0;
    local_68 = 0;
    do {
      FUN_000b0e42(local_68,iVar4,local_28);
      local_64 = 0;
      local_60 = 0;
      local_5c = 0;
LAB_000b1f99:
      iVar7 = *(int *)(*(int *)(local_74 + 0x14) + local_68 * 4);
      iVar9 = *(int *)(*(int *)(local_74 + 0x20) + local_68 * 4);
      if (local_5c < iVar7 + iVar9) {
LAB_000b1fba:
        if (((local_58 < *(int *)(local_74 + 0x18)) && (local_64 < iVar7)) &&
           (piVar13 = (int *)(*(int *)(local_74 + 0x10) + local_58 * 0x4c),
           local_50 == piVar13[0x11])) {
          local_58 = local_58 + 1;
          local_64 = local_64 + 1;
          local_5c = local_5c + 1;
          local_50 = local_50 + 1;
        }
        else {
          piVar13 = (int *)0x0;
        }
        if (((local_54 < *(int *)(local_74 + 0x24)) && (local_60 < iVar9)) &&
           (piVar11 = (int *)(*(int *)(local_74 + 0x1c) + local_54 * 0x4c),
           local_50 == piVar11[0x11])) {
          local_60 = local_60 + 1;
          local_5c = local_5c + 1;
          local_54 = local_54 + 1;
          local_50 = local_50 + 1;
          if (piVar13 != (int *)0x0) goto LAB_000b2010;
          goto LAB_000b207a;
        }
        piVar11 = (int *)0x0;
        if (piVar13 == (int *)0x0) goto LAB_000b207a;
LAB_000b2010:
        if (piVar11 == (int *)0x0) goto LAB_000b2120;
        switch(*piVar11) {
        case 0x8961:
          local_44 = 1;
          break;
        default:
          local_44 = 0;
          break;
        case 0x8963:
        case 0x8964:
        case 0x8965:
          goto switchD_000b2032_caseD_8963;
        case 0x8966:
        case 0x8967:
          if (*piVar11 == *piVar13) goto LAB_000b2120;
switchD_000b2032_caseD_8963:
          local_44 = 2;
          iVar7 = piVar13[1];
          iVar9 = piVar11[9];
          iVar8 = piVar11[0xd];
          if (iVar7 == piVar11[5]) goto LAB_000b21a5;
          goto LAB_000b2110;
        case 0x8968:
        case 0x8969:
        case 0x896a:
        case 0x896b:
          goto switchD_000b2032_caseD_8968;
        case 0x896c:
          if (*piVar13 == 0x896c) goto LAB_000b2120;
          goto switchD_000b2032_caseD_8968;
        }
        goto LAB_000b20fe;
      }
LAB_000b228b:
      local_68 = local_68 + 1;
    } while (iVar4 != local_68);
    if ((*(ushort *)(param_1 + 0x44) & 0x801) == 1) goto LAB_000b1e34;
LAB_000b1c96:
    if ((*(byte *)(param_1 + 0x45) & 1) == 0) goto LAB_000b1ca0;
LAB_000b1e46:
    FUN_000b037c();
    local_70[0x118] = 1;
  }
  FUN_000b022a();
  FUN_000b01a8();
  *(undefined4 *)(local_70 + 0x11c) = 0;
  local_94 = (uint)*(ushort *)(param_1 + 0x114a);
  if (local_94 != 0) {
    iVar4 = 0;
    iVar10 = 0;
    local_90 = local_70;
    do {
      if (*(char *)(*(int *)(local_74 + 0x28) + iVar10) != '\0') {
        *(uint *)(local_70 + 0x11c) = *(uint *)(local_70 + 0x11c) | 1 << ((byte)iVar4 & 0x1f);
        *(undefined4 *)(local_90 + 0x98) = *(undefined4 *)(*(int *)(local_74 + 0x28) + 4 + iVar10);
        *(undefined4 *)(local_90 + 0x9c) = *(undefined4 *)(*(int *)(local_74 + 0x28) + 8 + iVar10);
        *(undefined4 *)(local_90 + 0xa0) = *(undefined4 *)(*(int *)(local_74 + 0x28) + 0xc + iVar10)
        ;
        *(undefined4 *)(local_90 + 0xa4) =
             *(undefined4 *)(*(int *)(local_74 + 0x28) + 0x10 + iVar10);
        local_94 = (uint)*(ushort *)(param_1 + 0x114a);
      }
      iVar4 = iVar4 + 1;
      iVar10 = iVar10 + 0x14;
      local_90 = local_90 + 0x10;
    } while (iVar4 < (int)local_94);
  }
  local_70[0x120] = 1;
  (**(code **)(param_1 + 0x1288))(param_1,0,local_70,&local_34);
  local_70[0x119] = 0;
LAB_000b1d1a:
  *(undefined1 *)(param_1 + 0x1136) = 0;
  iVar10 = 0;
  local_40 = 0;
  puVar12 = local_70 + 0x98;
  do {
    while ((*(uint *)(local_70 + 0x11c) & 1 << ((byte)iVar10 & 0x1f)) != 0) {
      (**(code **)(param_1 + 0x1280))(param_1,local_70,iVar10,iVar10,puVar12,1,0);
      iVar10 = iVar10 + 1;
      puVar12 = puVar12 + 0x10;
      local_40 = local_40 + 0x14;
      if (iVar10 == 8) goto LAB_000b1da8;
    }
    pcVar6 = (char *)(*(int *)(*(int *)(param_1 + 0x1154) + 0xc) + local_40);
    if (*pcVar6 != '\0') {
      (**(code **)(param_1 + 0x1280))(param_1,local_70,iVar10,iVar10,pcVar6 + 4,1,0);
    }
    iVar10 = iVar10 + 1;
    puVar12 = puVar12 + 0x10;
    local_40 = local_40 + 0x14;
  } while (iVar10 != 8);
LAB_000b1da8:
  if ((*(uint *)(param_1 + 0x44) & 0x44000) != 0x4000) {
    return 1;
  }
  (**(code **)(param_1 + 0x1290))(param_1,local_70);
  return 1;
switchD_000b2032_caseD_8968:
  local_44 = 3;
LAB_000b20fe:
  iVar7 = piVar13[1];
  iVar9 = piVar11[9];
  iVar8 = piVar11[0xd];
  if (iVar7 != piVar11[5]) {
LAB_000b2110:
    if ((iVar7 == iVar9) && (1 < local_44)) {
      local_48 = piVar13[1];
      piVar13[1] = 6;
      bVar3 = true;
      goto LAB_000b2136;
    }
    if ((iVar7 == iVar8) && (2 < local_44)) {
      local_48 = piVar13[1];
      piVar13[1] = 6;
      bVar3 = true;
      goto LAB_000b2136;
    }
LAB_000b2120:
    if (piVar13 != (int *)0x0) {
      bVar3 = false;
      local_48 = 0;
      goto LAB_000b2136;
    }
LAB_000b207a:
    bVar3 = false;
    local_48 = 0;
    goto switchD_000b2156_caseD_8962;
  }
LAB_000b21a5:
  local_48 = piVar13[1];
  piVar13[1] = 6;
  bVar3 = true;
LAB_000b2136:
  local_20 = 0;
  switch(*piVar13) {
  case 0x8961:
    local_20 = 0x47;
    FUN_000b01a8();
    FUN_000b0b1b(0,1,local_28);
    goto LAB_000b2538;
  default:
    goto switchD_000b2156_caseD_8962;
  case 0x8963:
    local_20 = 3;
    break;
  case 0x8964:
    local_20 = 0x49;
    goto LAB_000b2641;
  case 0x8965:
    local_20 = 0x5b;
    break;
  case 0x8966:
    if ((piVar11 != (int *)0x0) && (*piVar11 == 0x8966)) {
      piVar13[2] = piVar13[2] | 8;
    }
    local_20 = 0x22;
LAB_000b2641:
    FUN_000b01a8();
    FUN_000b0b1b(0,1,local_28);
    FUN_000b07df(0,1,local_28);
    goto LAB_000b2538;
  case 0x8967:
    if ((piVar11 != (int *)0x0) && (*piVar11 == 0x8967)) {
      piVar13[2] = piVar13[2] | 8;
    }
    local_20 = 0x23;
    break;
  case 0x8968:
    local_20 = 0x40;
    goto LAB_000b24b4;
  case 0x8969:
    local_20 = 0x3f;
    goto LAB_000b24b4;
  case 0x896a:
    local_20 = 0x43000d;
    goto LAB_000b2588;
  case 0x896b:
    local_20 = 0x2000d;
LAB_000b2588:
    FUN_000b01a8();
    FUN_000b0b1b(0,1,local_28);
    FUN_000b07df(0,1,local_28);
    goto LAB_000b25de;
  case 0x896c:
    if ((piVar11 != (int *)0x0) && (*piVar11 == 0x896c)) {
      piVar13[2] = piVar13[2] | 8;
    }
    local_20 = 0x21;
LAB_000b24b4:
    FUN_000b01a8();
    FUN_000b0b1b(0,1,local_28);
    FUN_000b07df(0,1,local_28);
    FUN_000b07df(0,1,local_28);
    goto LAB_000b2538;
  }
  FUN_000b01a8();
  FUN_000b0b1b(0,1,local_28);
LAB_000b25de:
  FUN_000b07df(0,1,local_28);
LAB_000b2538:
  FUN_000b07df(0,1,local_28);
switchD_000b2156_caseD_8962:
  if (piVar11 == (int *)0x0) goto switchD_000b20b0_caseD_8962;
  local_20 = 0;
  switch(*piVar11) {
  case 0x8961:
    local_20 = 0x47;
    FUN_000b01a8();
    FUN_000b0b1b(0,0,local_28);
    goto LAB_000b2224;
  default:
    goto switchD_000b20b0_caseD_8962;
  case 0x8963:
    local_20 = 3;
    break;
  case 0x8964:
    local_20 = 0x49;
    break;
  case 0x8965:
    local_20 = 0x5b;
    break;
  case 0x8968:
    local_20 = 0x40;
    goto LAB_000b2336;
  case 0x8969:
    local_20 = 0x3f;
LAB_000b2336:
    FUN_000b01a8();
    FUN_000b0b1b(0,0,local_28);
    FUN_000b07df(0,0,local_28);
    FUN_000b07df(0,0,local_28);
    goto LAB_000b2224;
  case 0x896a:
    local_20 = 0x43000d;
    goto LAB_000b23fb;
  case 0x896b:
    local_20 = 0x2000d;
LAB_000b23fb:
    FUN_000b01a8();
    FUN_000b0b1b(0,0,local_28);
    FUN_000b07df(0,0,local_28);
    FUN_000b07df(0,0,local_28);
    goto LAB_000b2224;
  }
  FUN_000b01a8();
  FUN_000b0b1b(0,0,local_28);
  FUN_000b07df(0,0,local_28);
LAB_000b2224:
  FUN_000b07df(0,0,local_28);
switchD_000b20b0_caseD_8962:
  if (!bVar3) goto LAB_000b1f99;
  FUN_000b05ac(piVar13[1],piVar13[2]);
  piVar13[1] = local_48;
  iVar7 = *(int *)(*(int *)(local_74 + 0x14) + local_68 * 4);
  iVar9 = *(int *)(*(int *)(local_74 + 0x20) + local_68 * 4);
  if (iVar7 + iVar9 <= local_5c) goto LAB_000b228b;
  goto LAB_000b1fba;
}

/* FUN_000b27c8 @ 0xb27c8 (5 bytes) */
int FUN_000b27c8()
{
  return;
}

/* FUN_000b27cd @ 0xb27cd (2436 bytes) */
int FUN_000b27cd(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int *param_2;
  int *param_3;
  int *param_4;
  int param_5;
{
  int *piVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int *local_40;
  int local_30;
  undefined1 auStack_25 [21];
  
  if ((((param_2 == (int *)0x0) || (param_3 == (int *)0x0)) || (param_4 == (int *)0x0)) ||
     (param_5 == 0)) {
    return 1;
  }
  *param_2 = param_1;
  param_2[1] = 0;
  param_2[2] = 0;
  *(undefined1 *)(param_2 + 3) = 0;
  *(undefined1 *)((int)param_2 + 0xd) = 0;
  *(undefined1 *)((int)param_2 + 0xe) = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  param_2[6] = 0x21;
  param_2[7] = 0;
  param_2[9] = 0;
  param_2[10] = 0;
  param_2[0xb] = 0;
  param_2[0xc] = 0;
  *(undefined1 *)(param_2 + 0xd) = 0;
  param_2[8] = 0;
  param_2[0xe] = 0;
  iVar8 = 3;
  piVar1 = param_2;
  piVar7 = param_2;
  piVar6 = param_2;
  do {
    piVar1[0xf] = 0x21;
    piVar1[0x12] = 0;
    piVar7[0x15] = 0;
    piVar7[0x16] = 1;
    piVar7[0x17] = 2;
    piVar7[0x18] = 3;
    *(undefined1 *)(piVar1 + 0x21) = 0;
    *(undefined1 *)((int)piVar1 + 0x85) = 0;
    *(undefined1 *)((int)piVar1 + 0x86) = 0;
    *(undefined1 *)((int)piVar1 + 0x87) = 0;
    *(undefined1 *)(piVar6 + 0x24) = 0;
    *(undefined1 *)((int)piVar6 + 0x93) = 0;
    *(undefined1 *)((int)piVar6 + 0x96) = 0;
    *(undefined1 *)((int)piVar6 + 0x99) = 0;
    *(undefined1 *)(piVar6 + 0x27) = 0;
    piVar1[0x28] = 0;
    piVar1 = piVar1 + 1;
    piVar7 = piVar7 + 4;
    piVar6 = (int *)((int)piVar6 + 1);
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  *(undefined1 *)(param_2 + 0x2b) = 0;
  param_2[0x2c] = 0;
  param_2[0x2d] = 0;
  iVar8 = 0x10;
  piVar1 = param_2;
  piVar7 = param_2;
  do {
    *(undefined1 *)(piVar1 + 0x56e) = 0;
    piVar7[0x572] = 0;
    *(undefined1 *)(piVar1 + 0x582) = 0;
    *(undefined1 *)(piVar1 + 0x586) = 0;
    piVar7[0x7aa] = 0;
    piVar1 = (int *)((int)piVar1 + 1);
    piVar7 = piVar7 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  iVar8 = 0x30;
  piVar1 = param_2;
  piVar7 = param_2;
  do {
    *(undefined1 *)(piVar7 + 0x58a) = 0;
    piVar1[0x658] = 0;
    piVar7 = (int *)((int)piVar7 + 1);
    piVar1 = piVar1 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  param_2[0x656] = 0;
  param_2[0x788] = 0;
  param_2[0x78a] = 0x100;
  local_40 = param_2;
  iVar8 = 0;
  piVar1 = param_2;
  piVar7 = param_2;
  do {
    *(undefined1 *)(piVar7 + 0x596) = 0;
    *(undefined1 *)(piVar7 + 0x5d6) = 0;
    local_40[0x688] = 0;
    piVar1[0x6e] = 0;
    piVar1[0x6f] = 0;
    piVar1[0x70] = 0;
    piVar1[0x71] = 0;
    *(undefined1 *)(piVar7 + 0x2e) = 0;
    iVar8 = iVar8 + 1;
    piVar7 = (int *)((int)piVar7 + 1);
    local_40 = local_40 + 1;
    piVar1 = piVar1 + 5;
  } while (iVar8 < param_2[0x78a]);
  param_2[0x657] = 0;
  param_2[0x789] = 0;
  *(undefined1 *)(param_2 + 0x78b) = 0;
  *(undefined1 *)((int)param_2 + 0x1e2d) = 0;
  *(undefined1 *)((int)param_2 + 0x1e2e) = 0;
  *(undefined1 *)((int)param_2 + 0x1e2f) = 0;
  *(undefined1 *)(param_2 + 0x78c) = 0;
  param_2[0x7a3] = 0;
  param_2[0x7a4] = 0;
  param_2[0x7a5] = 0;
  iVar8 = 8;
  piVar1 = param_2;
  piVar7 = param_2;
  do {
    *(undefined1 *)((int)piVar7 + 0x1e31) = 0;
    *(undefined1 *)((int)piVar7 + 0x1e39) = 0;
    piVar1[0x793] = 0;
    piVar1[0x79b] = 0;
    piVar7 = (int *)((int)piVar7 + 1);
    piVar1 = piVar1 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  param_2[0x791] = 0;
  param_2[0x792] = 0;
  *(undefined1 *)(param_2 + 0x7a6) = 0;
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
  param_2[0x7a9] = 0;
  iVar8 = 4;
  piVar1 = param_2;
  do {
    *(undefined1 *)(piVar1 + 0x7be) = 0;
    piVar1 = (int *)((int)piVar1 + 1);
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  *(undefined1 *)(param_2 + 0x7bf) = 0;
  *(undefined1 *)((int)param_2 + 0x1efd) = 0;
  *(undefined1 *)(param_2 + 0x7c1) = 0;
  param_2[0x7c2] = 1;
  param_2[0x7c3] = 0;
  param_2[0x7c4] = 0;
  param_2[0x7c5] = 0;
  param_2[0x7c6] = 0;
  param_2[0x7c7] = 0x8000;
  *param_3 = param_5;
  param_3[1] = param_5 + 0x10f0;
  *(undefined4 *)(param_5 + 0x1300) = 0;
  *(undefined4 *)(*param_3 + 0x10e8) = 0xffffffff;
  iVar5 = 0x10;
  iVar8 = param_5;
  do {
    *(undefined4 *)(iVar8 + 0x15d4) = 0;
    *(undefined1 *)(param_5 + 0x1614) = 0;
    *(undefined4 *)(iVar8 + 0x1624) = 0;
    iVar8 = iVar8 + 4;
    param_5 = param_5 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  *(undefined4 *)(*param_3 + 0x10e4) = 0;
  *(undefined4 *)(*param_3 + 0x15d0) = 0;
  *(undefined1 *)(*param_3 + 0x10ed) = 0;
  *(undefined1 *)(*param_3 + 0x10ee) = 0;
  param_3[0x12] = 1;
  param_3[0x13] = 0;
  param_3[0x14] = 0;
  param_3[0x15] = 0;
  param_3[0x16] = 0;
  param_3[0x18] = 0;
  param_3[0x17] = 0;
  param_3[0x19] = 0;
  param_3[0x1a] = 0;
  iVar8 = 8;
  piVar1 = param_3;
  do {
    piVar1[0x1b] = 0;
    piVar1[0x23] = 0;
    piVar1 = piVar1 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  iVar8 = 0;
  do {
    *(undefined4 *)(*param_3 + 0x10ac + iVar8 * 4) = 0;
    *(undefined4 *)(*param_3 + 0x109c + iVar8 * 4) = 0;
    iVar8 = iVar8 + 1;
  } while (iVar8 != 4);
  iVar8 = 8;
  piVar1 = param_3;
  do {
    *(undefined1 *)(piVar1 + 0x2c) = 0;
    piVar1 = (int *)((int)piVar1 + 1);
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  param_3[0x2e] = 0x8000;
  param_3[0x2f] = 0x8000;
  param_3[0x30] = 0x8000;
  param_3[0x31] = 0x8000;
  param_3[0x32] = 0x8000;
  param_3[0x33] = 0x8000;
  param_3[0x34] = 0x8000;
  param_3[0x35] = 0x8000;
  param_3[0x37] = 0x8000;
  param_3[0x3a] = 0;
  param_3[0x3b] = 0;
  param_3[0x3c] = 0;
  param_3[0x3d] = 0;
  param_3[0x42] = 0;
  param_3[0x36] = 0;
  iVar8 = 4;
  piVar1 = param_3;
  do {
    piVar1[0x3e] = 0;
    piVar1 = piVar1 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  *(undefined1 *)(param_3 + 0x43) = 0;
  *(undefined1 *)((int)param_3 + 0x10d) = 0;
  *(undefined1 *)((int)param_3 + 0x10e) = 0;
  *(undefined1 *)((int)param_3 + 0x10f) = 0;
  *(undefined1 *)(param_3 + 0x44) = 0;
  param_2[2] = *param_4;
  *(byte *)((int)param_2 + 0x1f05) = *(byte *)(param_4 + 3) & 1;
  *(byte *)((int)param_2 + 0x1f06) = *(byte *)(param_4 + 3) & 2;
  uVar2 = (uint)param_4[3] >> 2 & 3;
  param_3[0x45] = uVar2;
  if (uVar2 == 0) {
    if ((*(byte *)((int)param_4 + 0xd) & 1) == 0) goto LAB_000b2f56;
LAB_000b2dc3:
    *(undefined1 *)(param_3 + 0x46) = 1;
    param_3[1] = *param_3 + 0x131c;
    if ((*(byte *)((int)param_4 + 0xd) & 4) == 0) goto LAB_000b2f74;
LAB_000b2de1:
    param_3[0x47] = param_4[4];
  }
  else {
    *(undefined1 *)(param_2 + 0x7a8) = 1;
    if ((*(byte *)((int)param_4 + 0xd) & 1) != 0) goto LAB_000b2dc3;
LAB_000b2f56:
    *(undefined1 *)(param_3 + 0x46) = 0;
    param_3[1] = *param_3 + 0x10f0;
    if ((*(byte *)((int)param_4 + 0xd) & 4) != 0) goto LAB_000b2de1;
LAB_000b2f74:
    param_3[0x47] = 0;
  }
  *(bool *)((int)param_3 + 0x119) = (*(byte *)((int)param_4 + 0xd) & 2) != 0;
  iVar8 = 1;
  do {
    (auStack_25 + 1)[iVar8 + -1] = 0;
    iVar8 = iVar8 + 1;
  } while (iVar8 != 9);
  puVar3 = (undefined4 *)FUN_000a5302(0x48000);
  param_3[3] = (int)puVar3;
  _memset(puVar3,0,0x48);
  *puVar3 = 0;
  puVar3[1] = 0x1000;
  puVar3[2] = 0;
  *(undefined1 *)(puVar3 + 3) = 0;
  *(undefined1 *)((int)puVar3 + 0xd) = 0;
  *(undefined2 *)(puVar3 + 5) = 0;
  *(undefined2 *)((int)puVar3 + 0x22) = 0;
  param_3[2] = (int)(puVar3 + 0x12);
  iVar8 = FUN_000835af(param_1,param_2,param_3,param_3[1],puVar3 + 0x12,auStack_25 + 1,0,0,0);
  param_3[2] = iVar8;
  *(undefined1 *)(param_2 + 0x7c8) = 1;
  iVar8 = 0;
  do {
    iVar5 = iVar8 * 0x10;
    *(undefined4 *)(iVar5 + param_3[1] + 0x108) = 0;
    *(undefined4 *)(iVar5 + param_3[1] + 0x10c) = 1;
    *(undefined4 *)(iVar5 + param_3[1] + 0x110) = 2;
    *(undefined4 *)(iVar5 + param_3[1] + 0x114) = 3;
    iVar8 = iVar8 + 1;
  } while (iVar8 != 0x10);
  if (param_1 == 0) {
    iVar8 = param_4[6];
  }
  else {
    if (*(int *)(param_1 + 0x186c) == 0) {
      FUN_000c4bdb(param_1,*(undefined4 *)(param_1 + 0x2454));
    }
    iVar8 = param_1 + 0x186c;
  }
  iVar8 = FUN_000c890f(param_1,param_2,param_3,param_4,iVar8);
  if (iVar8 != 0) {
    return 2;
  }
  FUN_000c37eb(param_3[3]);
  iVar8 = param_3[3];
  FUN_000c37eb(iVar8);
  if ((*(byte *)((int)param_4 + 0xd) & 1) == 0) {
    local_30 = *param_3 + 4;
  }
  else {
    local_30 = *param_3 + 0x20;
  }
  uVar4 = FUN_000a5302(((uint)*(ushort *)(iVar8 + 0x1c) + (uint)*(ushort *)(iVar8 + 0x1a) +
                       (uint)*(ushort *)(iVar8 + 0x20)) * 0x18);
  *(undefined4 *)(local_30 + 0x10) = uVar4;
  iVar8 = ((int (*)())FUN_000bd709)(param_3[3],param_3[1] + 0x44,local_30);
  if ((*(byte *)((int)param_4 + 0xd) & 1) == 0) {
    *(uint *)(*param_3 + 0x36ac) =
         ((uint)(*(ushort *)(local_30 + 10) & 0x1ff) - (uint)(*(ushort *)(local_30 + 8) & 0x1ff)) +
         1;
    *(uint *)(*param_3 + 0x36b4) = (*(byte *)(param_3[1] + 0x44) & 0xf) + 1;
  }
  else {
    *(uint *)(*param_3 + 0x36b8) =
         ((uint)(*(ushort *)(local_30 + 10) & 0x1ff) - (uint)(*(ushort *)(local_30 + 8) & 0x1ff)) +
         1;
    *(uint *)(*param_3 + 0x36c0) = (*(byte *)(param_3[1] + 0x44) & 0xf) + 1;
  }
  *(undefined1 *)(*param_3 + 0x36c9) = 1;
  _free((void *)param_3[3]);
  if (8 < param_2[0x791] + param_2[0x792] + (uint)(*(char *)((int)param_2 + 0x1e2e) != '\0') +
          (uint)(*(char *)((int)param_2 + 0x1e2f) != '\0')) {
    param_2[1] = 6;
    return 6;
  }
  if (iVar8 == 0) {
LAB_000b31ac:
    uVar4 = 0;
  }
  else {
    switch(iVar8) {
    case -0x7fffffff:
    case -0x7ffffff0:
      uVar4 = 3;
      break;
    case -0x7ffffffe:
    case -0x7fffffee:
      uVar4 = 4;
      break;
    case -0x7ffffffd:
    case -0x7fffffec:
      uVar4 = 6;
      break;
    case -0x7ffffffc:
    case -0x7fffffea:
      uVar4 = 9;
      break;
    case -0x7ffffffb:
    case -0x7fffffeb:
      uVar4 = 10;
      break;
    case -0x7ffffffa:
    case -0x7fffffef:
      uVar4 = 8;
      break;
    default:
      goto LAB_000b31ac;
    case -0x7fffffed:
      uVar4 = 5;
      break;
    case -0x7fffffe9:
      uVar4 = 0xb;
      break;
    case -0x7fffffe8:
      uVar4 = 0xc;
    }
  }
  return uVar4;
}

/* FUN_000b320d @ 0xb320d (581 bytes) */
int FUN_000b320d(param_1, param_2)
  int param_1;
  int param_2;
{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  undefined1 local_2070 [5560];
  char acStack_ab8 [16];
  uint local_aa8 [16];
  char acStack_a68 [2085];
  undefined1 local_243;
  undefined1 local_242;
  undefined1 local_241;
  undefined1 local_173;
  undefined1 local_16c;
  undefined1 local_14c [176];
  char acStack_9c [116];
  int local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_28 = *(int *)(*(int *)(param_2 + 0x74) + 0x58) + 10;
  local_24 = *(int *)(*(int *)(param_2 + 0x74) + 0x5c) + -10 >> 2;
  local_20 = 0;
  local_1c = 0;
  iVar3 = ((int (*)())FUN_000b27cd)(param_1,local_2070,local_14c,&local_28,
                       *(undefined4 *)(*(int *)(param_2 + 0x70) + *(int *)(param_1 + 0x1130) * 4));
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
  if (iVar3 == 0) {
    *(undefined1 *)(*(int *)(param_2 + 0x74) + 4) = local_173;
    **(undefined1 **)(param_2 + 0x74) = local_243;
    *(undefined1 *)(*(int *)(param_2 + 0x74) + 1) = local_242;
    *(undefined1 *)(*(int *)(param_2 + 0x74) + 2) = local_241;
    *(undefined1 *)(*(int *)(param_2 + 0x74) + 3) = local_16c;
    *(undefined1 *)(*(int *)(param_2 + 0x74) + 5) = 0;
    iVar3 = 0;
    do {
      if (acStack_9c[iVar3] != '\0') {
        puVar4 = (uint *)(*(int *)(param_2 + 0x74) + 0xc);
        *puVar4 = *puVar4 | 1 << ((byte)iVar3 & 0x1f);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 != 8);
    iVar3 = 0;
    puVar4 = local_aa8;
    do {
      if (acStack_ab8[iVar3] != '\0') {
        puVar1 = (uint *)(*(int *)(param_2 + 0x74) + 0x10);
        *puVar1 = *puVar1 | 1 << ((byte)iVar3 & 0x1f);
        uVar2 = *puVar4;
        if (uVar2 == 2) {
          *(uint *)(*(int *)(param_2 + 0x74) + 0x14 + iVar3 * 4) =
               (-(uint)(acStack_a68[iVar3] == '\0') & 0xfffffffd) + 5;
        }
        else if (uVar2 < 3) {
          if (uVar2 == 1) {
            *(undefined4 *)(*(int *)(param_2 + 0x74) + 0x14 + iVar3 * 4) = 1;
          }
        }
        else if (uVar2 == 3) {
          *(undefined4 *)(*(int *)(param_2 + 0x74) + 0x14 + iVar3 * 4) = 3;
        }
        else if (uVar2 == 4) {
          *(undefined4 *)(*(int *)(param_2 + 0x74) + 0x14 + iVar3 * 4) = 4;
        }
      }
      puVar4 = puVar4 + 1;
      iVar3 = iVar3 + 1;
    } while (iVar3 != 0x10);
    *(undefined1 *)(param_2 + 0x6c) = 1;
    return 1;
  }
  if (iVar3 != 1) {
    *(undefined1 *)(param_2 + 0x6c) = 0;
    return 1;
  }
  *(undefined1 *)(param_2 + 0x6c) = 0;
  return 0;
}

/* FUN_000b3452 @ 0xb3452 (177 bytes) */
int FUN_000b3452(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  undefined4 uVar1;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM1_Da;
  undefined4 in_XMM2_Da;
  undefined4 in_XMM3_Da;
  
  if (param_3 != 0) {
    param_1 = param_2 * 0x10 + param_1;
    *(undefined4 *)(param_1 + 0x90) = in_XMM0_Da;
    *(undefined4 *)(param_1 + 0x94) = in_XMM1_Da;
    *(undefined4 *)(param_1 + 0x98) = in_XMM2_Da;
    *(undefined4 *)(param_1 + 0x9c) = in_XMM3_Da;
    return;
  }
  uVar1 = FUN_0004951b();
  param_1 = param_2 * 0x10 + param_1;
  *(undefined4 *)(param_1 + 0x90) = uVar1;
  uVar1 = FUN_0004951b(in_XMM1_Da);
  *(undefined4 *)(param_1 + 0x94) = uVar1;
  uVar1 = FUN_0004951b(in_XMM2_Da);
  *(undefined4 *)(param_1 + 0x98) = uVar1;
  uVar1 = FUN_0004951b(in_XMM3_Da);
  *(undefined4 *)(param_1 + 0x9c) = uVar1;
  return;
}

/* FUN_000b3503 @ 0xb3503 (120 bytes) */
int FUN_000b3503(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int *param_3;
  int param_4;
{
  if (((param_4 < 0x100) && (*(char *)(param_4 + 0x1658 + param_2) != '\0')) &&
     (*(char *)(param_4 + 0x1758 + param_2) == '\0')) {
    ((int (*)())FUN_000b3452)();
    *(undefined4 *)(param_1 + 0x1e64) = 0;
    *(undefined1 *)(*param_3 + 0x10ef) = 0;
  }
  return;
}

/* FUN_000b357b @ 0xb357b (217 bytes) */
int FUN_000b357b(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 local_28;
  undefined4 local_24;
  
  if (*(char *)(param_1 + 0x13b1) != '\0') {
    local_24 = param_1;
    local_28 = 0;
    do {
      if (*(char *)(param_2 + 0x1618) != '\0') {
        if (*(int *)(local_24 + 0x13f8) != 0) {
          ((int (*)())FUN_000b3452)();
        }
      }
      local_28 = local_28 + 1;
      param_2 = param_2 + 1;
      local_24 = local_24 + 4;
    } while (local_28 < (int)(uint)*(byte *)(param_1 + 0x13b1));
  }
  return;
}

/* FUN_000b3654 @ 0xb3654 (5 bytes) */
int FUN_000b3654()
{
  return;
}

/* FUN_000b3659 @ 0xb3659 (327 bytes) */
int FUN_000b3659(param_1, param_2)
  int param_1;
  int param_2;
{
  if (*(char *)(param_2 + 0x1e2f) != '\0') {
    ((int (*)())FUN_000b3452)((float)*(int *)(*(int *)(*(int *)(param_1 + 4) + 0x10) + 0x184c) *
                 *(float *)(*(int *)(param_1 + 4) + 0x2a58) * FLOAT_001c5bd4);
    ((int (*)())FUN_000b3452)();
    *(undefined4 *)(param_1 + 0x1e64) = 0;
  }
  return;
}

/* FUN_000b37a0 @ 0xb37a0 (214 bytes) */
int FUN_000b37a0(param_1, param_2)
  int param_1;
  int param_2;
{
  if (*(char *)(param_2 + 0x1ea0) != '\0') {
    ((int (*)())FUN_000b3452)();
    ((int (*)())FUN_000b3452)();
    *(undefined4 *)(param_1 + 0x1e64) = 0;
  }
  return;
}

/* FUN_000b3876 @ 0xb3876 (5 bytes) */
int FUN_000b3876()
{
  return;
}

/* FUN_000b387b @ 0xb387b (783 bytes) */
int FUN_000b387b(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  
  iVar5 = *(int *)(param_2 + 0x14);
  iVar1 = *(int *)(iVar5 + 0x4024);
  iVar9 = iVar1 * 4;
  puVar2 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
  *(undefined4 **)(param_1 + 0x274c) = puVar2;
  *puVar2 = 0x8a1;
  puVar2[1] = 0;
  iVar3 = *(int *)(param_1 + 0x274c) + 8;
  *(int *)(param_1 + 0x274c) = iVar3;
  (**(code **)(param_1 + 0x275c))(param_1,iVar3);
  puVar2 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,6);
  *(undefined4 **)(param_1 + 0x274c) = puVar2;
  *puVar2 = 0x208b4;
  puVar2[1] = *(undefined4 *)(param_1 + 0x1b90);
  puVar2[2] = *(undefined4 *)(param_1 + 0x1b8c);
  puVar2[3] = *(undefined4 *)(param_1 + 0x1b94);
  puVar2[4] = 0x820;
  puVar2[5] = *(undefined4 *)(param_1 + 0x1b7c);
  iVar3 = *(int *)(param_1 + 0x274c) + 0x18;
  *(int *)(param_1 + 0x274c) = iVar3;
  (**(code **)(param_1 + 0x275c))(param_1,iVar3);
  puVar2 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
  *(undefined4 **)(param_1 + 0x274c) = puVar2;
  *puVar2 = 0x8b7;
  puVar2[1] = *(undefined4 *)(param_1 + 0x1b98);
  iVar3 = *(int *)(param_1 + 0x274c) + 8;
  *(int *)(param_1 + 0x274c) = iVar3;
  (**(code **)(param_1 + 0x275c))(param_1,iVar3);
  puVar2 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,iVar9 + 3);
  *(undefined4 **)(param_1 + 0x274c) = puVar2;
  *puVar2 = 0x880;
  puVar2[1] = (uint)(*(ushort *)(iVar5 + 0x548c) & 0x3ff);
  puVar2[2] = (iVar9 + -1) * 0x10000 | 0x8882;
  _memcpy(puVar2 + 3,(void *)(iVar5 + 0x24),*(int *)(iVar5 + 0x4024) << 4);
  iVar9 = iVar1 * 0x10 + *(int *)(param_1 + 0x274c) + 0xc;
  *(int *)(param_1 + 0x274c) = iVar9;
  (**(code **)(param_1 + 0x275c))(param_1,iVar9);
  puVar2 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0x15);
  *(undefined4 **)(param_1 + 0x274c) = puVar2;
  *puVar2 = 0x82d;
  puVar2[1] = *(undefined4 *)(param_1 + 0x1ca4);
  puVar2[2] = 0x861;
  puVar2[3] = *(undefined4 *)(param_1 + 0x1ca0);
  puVar2[4] = 0x824;
  puVar2[5] = *(undefined4 *)(param_1 + 0x1b9c);
  puVar2[6] = 0x825;
  puVar2[7] = *(undefined4 *)(param_1 + 0x1ba0);
  puVar2[8] = 0x10c0;
  puVar2[9] = *(undefined4 *)(param_1 + 0x1f2c);
  puVar2[10] = *(uint *)(param_1 + 0x1f28) | 0x70000;
  iVar5 = 0;
  iVar9 = param_1;
  do {
    puVar2[iVar5 + 0xb] = *(undefined4 *)(iVar9 + 0x1ee8);
    iVar5 = iVar5 + 1;
    iVar9 = iVar9 + 4;
  } while (iVar5 != 8);
  puVar2[0x13] = 0x1047;
  puVar2[0x14] = *(undefined4 *)(param_1 + 0x1bb0);
  iVar9 = *(int *)(param_1 + 0x274c) + 0x54;
  *(int *)(param_1 + 0x274c) = iVar9;
  (**(code **)(param_1 + 0x275c))(param_1,iVar9);
  if (*(int *)(param_1 + 0x243c) == 0) {
    return;
  }
  uVar8 = *(int *)(param_1 + 0x243c) + 1U >> 1;
  puVar4 = (uint *)(**(code **)(param_1 + 0x2758))(param_1,uVar8 * 2 + 2);
  *(uint **)(param_1 + 0x274c) = puVar4;
  uVar7 = (uVar8 - 1) * 0x10000;
  *puVar4 = uVar7 | 0x854;
  puVar4 = puVar4 + 1;
  if (uVar8 != 0) {
    uVar6 = 0;
    do {
      *puVar4 = *(uint *)(*(int *)(param_1 + 0x2440) + uVar6 * 4);
      puVar4 = puVar4 + 1;
      uVar6 = uVar6 + 1;
    } while (uVar8 != uVar6);
  }
  *puVar4 = uVar7 | 0x878;
  if (uVar8 != 0) {
    uVar7 = 0;
    do {
      puVar4[uVar7 + 1] = *(uint *)(*(int *)(param_1 + 0x2444) + uVar7 * 4);
      uVar7 = uVar7 + 1;
    } while (uVar8 != uVar7);
  }
  iVar9 = *(int *)(param_1 + 0x274c) + 8 + uVar8 * 8;
  *(int *)(param_1 + 0x274c) = iVar9;
  (**(code **)(param_1 + 0x275c))(param_1,iVar9);
  return;
}

/* FUN_000b3b8a @ 0xb3b8a (641 bytes) */
int FUN_000b3b8a(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int local_10;
  
  if (*(int *)(param_2 + 0x14) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x14));
  }
  puVar1 = (undefined4 *)(**(code **)(param_1 + 0xc))(0x569c);
  *(undefined4 **)(param_2 + 0x14) = puVar1;
  puVar1[2] = 0;
  *puVar1 = *(undefined4 *)(param_2 + 0xc);
  puVar1[1] = *(undefined4 *)(param_2 + 4);
  puVar1[3] = *(undefined4 *)(param_1 + 0x2454);
  puVar1[4] = *(undefined4 *)(param_1 + 0x2454);
  puVar1[6] = (uint)(*(byte *)(param_1 + 0x47) & 1);
  puVar1[7] = 1;
  puVar1[8] = 1;
  if (*(char *)(param_1 + 0x1869) == '\0') {
    iVar2 = 0xe;
  }
  else {
    puVar5 = puVar1 + 9;
    iVar2 = FUN_000c647a(param_1,puVar1,puVar5);
    if (iVar2 == 0) {
      *(ushort *)(puVar1 + 0x1523) = *(ushort *)(puVar1 + 0x1523) & 0xfc00;
      iVar2 = puVar1[0x1009];
      *(ushort *)((int)puVar1 + 0x548e) =
           *(ushort *)((int)puVar1 + 0x548e) & 0xc00f | (ushort)((iVar2 - 1U & 0xffff03ff) << 4);
      *(undefined1 *)(puVar1 + 0x1525) = 0;
      iVar6 = puVar1[0x150b];
      *(char *)((int)puVar1 + 0x5496) = (char)iVar6;
      if (*(int *)(param_2 + 0x1240) < (int)puVar1[0x1590]) {
        *(undefined4 *)(param_2 + 0x1240) = puVar1[0x1590];
        iVar2 = puVar1[0x1009];
        iVar6 = puVar1[0x150b];
      }
      iVar4 = iVar2;
      if (iVar2 == 0) {
        uVar3 = 0;
      }
      else {
        do {
          if (((byte)((*(byte *)((int)puVar5 + iVar4 * 0x10 + -0xf) & 0xf) - 2) < 2) &&
             ((puVar5[iVar4 * 4 + -4] & 0xfe000) == 0)) {
            uVar3 = iVar4 - 1;
          }
          else {
            uVar3 = 0;
          }
          iVar4 = iVar4 + -1;
        } while ((iVar4 != 0) && (uVar3 == 0));
      }
      puVar1[0x1523] = puVar1[0x1523] & 0xfff003ff | (uVar3 & 0x3ff) << 10;
      if (iVar2 == 0) {
        local_10 = 0;
      }
      else {
        puVar5 = puVar5 + iVar2 * 4 + -4;
        do {
          if ((((*(byte *)(puVar5 + 1) & 7) == 1) || ((*(byte *)(puVar5 + 2) & 7) == 1)) ||
             ((*(byte *)(puVar5 + 3) & 7) == 1)) {
            local_10 = iVar2 + -1;
          }
          else {
            local_10 = 0;
          }
          iVar2 = iVar2 + -1;
          puVar5 = puVar5 + -4;
        } while ((iVar2 != 0) && (local_10 == 0));
      }
      *(int *)(param_2 + 0x1038) = iVar6;
      if (0 < iVar6) {
        iVar6 = 0;
        puVar5 = puVar1;
        iVar2 = param_2;
        do {
          if (*(char *)(puVar5 + 0x100e) != '\0') {
            *(undefined4 *)(iVar2 + 0x18) = puVar5[0x100a];
            *(undefined4 *)(iVar2 + 0x1c) = puVar5[0x100b];
            *(undefined4 *)(iVar2 + 0x20) = puVar5[0x100c];
            *(undefined4 *)(iVar2 + 0x24) = puVar5[0x100d];
            if (*(int *)(param_2 + 0x1240) < iVar6) {
              *(int *)(param_2 + 0x1240) = iVar6;
            }
          }
          iVar6 = iVar6 + 1;
          puVar5 = puVar5 + 5;
          iVar2 = iVar2 + 0x10;
        } while (iVar6 < *(int *)(param_2 + 0x1038));
      }
      *(ushort *)(puVar1 + 0x1524) =
           *(ushort *)(puVar1 + 0x1524) & 0xfc00 | (ushort)local_10 & 0x3ff;
      *(undefined1 *)(param_2 + 1) = 1;
      return 0;
    }
  }
  return iVar2;
}

/* FUN_000b3e0b @ 0xb3e0b (221 bytes) */
int FUN_000b3e0b(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_2 + 0x14);
  iVar2 = *(int *)(param_2 + 0x1240) + 1;
  iVar4 = *(int *)(iVar1 + 0x5428);
  if (iVar2 < *(int *)(iVar1 + 0x5428)) {
    iVar4 = iVar2;
  }
  iVar2 = iVar4 * 4;
  if (iVar2 != 0) {
    puVar3 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,iVar2 + 5);
    *(undefined4 **)(param_1 + 0x274c) = puVar3;
    *puVar3 = 0x8a1;
    puVar3[1] = 0;
    puVar3[2] = 0x880;
    puVar3[3] = (uint)*(byte *)(iVar1 + 0x5494) + *(int *)(param_1 + 0x2448);
    puVar3[4] = (iVar2 + -1) * 0x10000 | 0x8882;
    _memcpy(puVar3 + 5,(void *)(param_2 + 0x18),iVar4 * 0x10);
    iVar4 = iVar4 * 0x10 + *(int *)(param_1 + 0x274c) + 0x14;
    *(int *)(param_1 + 0x274c) = iVar4;
    (**(code **)(param_1 + 0x275c))(param_1,iVar4);
  }
  *(char *)(iVar1 + 0x5496) = (char)*(undefined4 *)(param_2 + 0x1038);
  return;
}

/* FUN_000b3ee8 @ 0xb3ee8 (35 bytes) */
int FUN_000b3ee8()
{
  ((int (*)())FUN_000b387b)();
  ((int (*)())FUN_000b3e0b)();
  return 0;
}

/* FUN_000b3f0b @ 0xb3f0b (21 bytes) */
int FUN_000b3f0b()
{
  ((int (*)())FUN_000b387b)();
  return 0;
}

/* FUN_000b3f20 @ 0xb3f20 (21 bytes) */
int FUN_000b3f20()
{
  ((int (*)())FUN_000b3e0b)();
  return 0;
}

/* FUN_000b3f35 @ 0xb3f35 (889 bytes) */
int FUN_000b3f35(param_1, param_2, param_3)
  int param_1;
  uint *param_2;
  undefined4 param_3;
{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int local_30;
  uint local_1c;
  uint local_10;
  
  if (*(char *)(param_1 + 0x3d4) == '\0') {
    *(uint **)(param_1 + 0x148c) = param_2;
    if ((*(char *)(param_1 + 0x124) == '\0') || ((*(byte *)(param_1 + 0x45) & 8) == 0)) {
      *(uint **)(param_1 + 0x148c) = param_2;
      uVar2 = param_2[1];
    }
    else {
      uVar2 = param_2[1];
    }
    if (uVar2 == 0) {
      return 1;
    }
    if ((*param_2 & 0xffff00) == 0) {
      ((int (*)())FUN_000b3b8a)(param_1,param_2);
      *(bool *)((int)param_2 + 2) = *(char *)((int)param_2 + 1) == '\0';
    }
    uVar2 = param_2[5];
    iVar4 = 0;
    uVar3 = uVar2;
    do {
      *(undefined4 *)(*(int *)(param_1 + 0x1864) + iVar4) = *(undefined4 *)(uVar3 + 0x55e8);
      iVar4 = iVar4 + 4;
      uVar3 = uVar3 + 4;
    } while (iVar4 != 0x58);
    *(undefined4 *)(param_1 + 0x1b90) = *(undefined4 *)(uVar2 + 0x548c);
    *(undefined4 *)(param_1 + 0x1b94) = *(undefined4 *)(uVar2 + 0x5490);
    *(undefined4 *)(param_1 + 0x1b8c) = *(undefined4 *)(uVar2 + 0x5494);
    *(undefined4 *)(param_1 + 0x1b98) = *(undefined4 *)(uVar2 + 0x54a4);
    FUN_0004fd18(param_1,param_3,*(undefined4 *)(uVar2 + 0x5434),*(undefined4 *)(uVar2 + 0x5438));
    *(undefined4 *)(param_1 + 0x1b9c) = *(undefined4 *)(uVar2 + 0x5498);
    *(undefined4 *)(param_1 + 0x1ba0) = *(undefined4 *)(uVar2 + 0x549c);
    bVar1 = *(byte *)(param_1 + 0x45);
    if ((bVar1 & 8) == 0) {
      iVar4 = *(int *)(*(int *)(param_1 + 4) + 0x10);
      *(undefined4 *)(param_1 + 0x1ca0) = 1;
      if ((*(byte *)(param_1 + 0x44) & 1) == 0) {
        if (((*(byte *)(param_1 + 0x8c) >> 5 | *(byte *)(param_1 + 0x8d) >> 3 |
             *(byte *)(param_1 + 0x8c) >> 4) & 1) != 0) {
          *(undefined4 *)(param_1 + 0x1ca0) = 3;
        }
        uVar3 = *(uint *)(param_1 + 0x1ca0);
        local_1c = uVar3 | 4;
        *(uint *)(param_1 + 0x1ca0) = local_1c;
        if ((bVar1 & 0x85) != 0) {
          local_1c = uVar3 | 0xc;
          *(uint *)(param_1 + 0x1ca0) = local_1c;
        }
      }
      else {
        local_1c = 3;
        *(undefined4 *)(param_1 + 0x1ca0) = 3;
        if (*(char *)(iVar4 + 0x2d4b) != '\0') {
          local_1c = 7;
          *(undefined4 *)(param_1 + 0x1ca0) = 7;
        }
      }
      if (((*(uint *)(param_1 + 0x44) & 0x100080) != 0) && (*(short *)(iVar4 + 0x2e06) == -0x7baf))
      {
        local_1c = local_1c | 0x40000;
        *(uint *)(param_1 + 0x1ca0) = local_1c;
      }
      if (*(char *)(iVar4 + 0x4301) != '\0') {
        local_1c = local_1c | 0x80000;
        *(uint *)(param_1 + 0x1ca0) = local_1c;
      }
      if ((bVar1 & 0x40) == 0) {
        bVar1 = *(byte *)(param_1 + 0x2b);
        if (*(byte *)(param_1 + 0x13b0) < bVar1) {
          bVar1 = *(byte *)(param_1 + 0x13b0);
        }
        local_10 = (uint)bVar1;
        if (local_10 != 0) {
          local_30 = param_1;
          uVar3 = 0;
          iVar4 = param_1;
          do {
            if ((*(char *)(iVar4 + 0x1438) != '\0') && (*(int *)(local_30 + 0x13f8) != 0)) {
              local_1c = local_1c | 1 << ((char)uVar3 + 10U & 0x1f);
              *(uint *)(param_1 + 0x1ca0) = local_1c;
            }
            uVar3 = uVar3 + 1;
            iVar4 = iVar4 + 1;
            local_30 = local_30 + 4;
          } while (uVar3 != local_10);
        }
      }
      else {
        if ((*(byte *)(param_1 + 0x46) & 4) == 0) {
          bVar1 = *(byte *)(param_1 + 0x1135);
        }
        else {
          bVar1 = *(byte *)(param_1 + 0x11d3);
        }
        if (*(char *)(param_1 + 0x13b0) != '\0') {
          iVar4 = 0;
          do {
            if (((uint)bVar1 & 1 << ((byte)iVar4 & 0x1f)) != 0) {
              local_1c = local_1c | 1 << ((byte)iVar4 + 10 & 0x1f);
              *(uint *)(param_1 + 0x1ca0) = local_1c;
            }
            iVar4 = iVar4 + 1;
          } while (iVar4 < (int)(uint)*(byte *)(param_1 + 0x13b0));
        }
      }
      *(uint *)(uVar2 + 0x5444) = local_1c;
    }
    (**(code **)(param_1 + 0x1334))(param_1,1);
    *(undefined4 *)(uVar2 + 0x5650) = *(undefined4 *)(param_1 + 0x1ba4);
    *(undefined4 *)(uVar2 + 0x5658) = *(undefined4 *)(param_1 + 0x1b50);
    if ((*(char *)(param_1 + 0x124) == '\0') && ((*(byte *)(param_1 + 0x45) & 8) == 0)) {
      (**(code **)(param_1 + 0x1340))(param_1);
      FUN_0008ab11(param_1);
    }
    ((int (*)())FUN_000b387b)();
    ((int (*)())FUN_000b3e0b)();
  }
  return 0;
}

/* FUN_000b42ae @ 0xb42ae (61 bytes) */
int FUN_000b42ae(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  void *pvVar1;
  
  pvVar1 = *(void **)(param_2 + 0x14);
  if (pvVar1 != (void *)0x0) {
    if (*(int *)((int)pvVar1 + 0x5648) != 0) {
      FUN_000c4db8(*(int *)((int)pvVar1 + 0x5648));
      pvVar1 = *(void **)(param_2 + 0x14);
    }
    _free(pvVar1);
    *(undefined4 *)(param_2 + 0x14) = 0;
  }
  return 0;
}

/* FUN_000b42eb @ 0xb42eb (67 bytes) */
int FUN_000b42eb(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1;
  do {
    iVar1 = *(int *)(iVar2 + 0x1448);
    if (iVar1 != 0) {
      *(undefined4 *)(iVar2 + 0x1448) = 0;
      (**(code **)(param_1 + 0x1224))(param_1,iVar1);
    }
    iVar2 = iVar2 + 4;
  } while (iVar2 != param_1 + 0x10);
  return;
}

/* FUN_000b432e @ 0xb432e (987 bytes) */
int FUN_000b432e(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint param_3;
{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  void *pvVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  undefined4 local_24;
  uint local_20;
  
  if (*(int *)(param_1 + 0x1448 + param_3 * 4) != 0) {
    return;
  }
  pcVar1 = *(code **)(param_1 + 0x10);
  uVar2 = (**(code **)(param_1 + 0x1284))(param_1);
  iVar3 = (*pcVar1)(1,uVar2);
  *(int *)(param_1 + 0x1448 + param_3 * 4) = iVar3;
  puVar6 = (uint *)(iVar3 + 4);
  *(undefined4 *)(iVar3 + 4) = 0;
  *(undefined4 *)(iVar3 + 8) = 0;
  *(undefined4 *)(iVar3 + 0xc) = 0;
  pvVar4 = (void *)(**(code **)(param_1 + 0xc))(0x200);
  if (*(void **)(iVar3 + 0xc) != (void *)0x0) {
    _memcpy(pvVar4,*(void **)(iVar3 + 0xc),*(int *)(iVar3 + 4) << 2);
    (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0xc));
  }
  *(void **)(iVar3 + 0xc) = pvVar4;
  *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + 0x80;
  *(undefined4 *)((int)pvVar4 + *(int *)(iVar3 + 4) * 4) = 1;
  uVar5 = *(int *)(iVar3 + 4) + 1;
  *(uint *)(iVar3 + 4) = uVar5;
  if (*(uint *)(iVar3 + 8) <= uVar5) {
    pvVar4 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(iVar3 + 8) * 4 + 0x200);
    if (*(void **)(iVar3 + 0xc) != (void *)0x0) {
      _memcpy(pvVar4,*(void **)(iVar3 + 0xc),*(int *)(iVar3 + 4) << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0xc));
    }
    *(void **)(iVar3 + 0xc) = pvVar4;
    *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + 0x80;
  }
  *(undefined **)(*(int *)(iVar3 + 0xc) + *puVar6 * 4) = ((unsigned char *)0x00010200);
  uVar5 = *puVar6;
  *puVar6 = uVar5 + 1;
  if (*(uint *)(iVar3 + 8) <= uVar5 + 1) {
    pvVar4 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(iVar3 + 8) * 4 + 0x200);
    if (*(void **)(iVar3 + 0xc) != (void *)0x0) {
      _memcpy(pvVar4,*(void **)(iVar3 + 0xc),*puVar6 << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0xc));
    }
    *(void **)(iVar3 + 0xc) = pvVar4;
    *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + 0x80;
  }
  *(undefined4 *)(*(int *)(iVar3 + 0xc) + *puVar6 * 4) = 0x1ff0016;
  uVar5 = *puVar6;
  *puVar6 = uVar5 + 1;
  if (*(uint *)(iVar3 + 8) <= uVar5 + 1) {
    pvVar4 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(iVar3 + 8) * 4 + 0x200);
    if (*(void **)(iVar3 + 0xc) != (void *)0x0) {
      _memcpy(pvVar4,*(void **)(iVar3 + 0xc),*puVar6 << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0xc));
    }
    *(void **)(iVar3 + 0xc) = pvVar4;
    *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + 0x80;
  }
  *(undefined4 *)(*(int *)(iVar3 + 0xc) + *puVar6 * 4) = 0x120000;
  *puVar6 = *puVar6 + 1;
  local_20 = (uint)(ushort)((-(ushort)(param_2 == 0) & 0x39) + 0xe);
  local_24 = 0x170000;
  iVar7 = 0;
  do {
    if ((param_3 & 1 << ((byte)iVar7 & 0x1f)) != 0) {
      local_24 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_24) + 2)),(short)iVar7);
      if (*(uint *)(iVar3 + 8) <= *puVar6) {
        pvVar4 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(iVar3 + 8) * 4 + 0x200);
        if (*(void **)(iVar3 + 0xc) != (void *)0x0) {
          _memcpy(pvVar4,*(void **)(iVar3 + 0xc),*puVar6 << 2);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0xc));
        }
        *(void **)(iVar3 + 0xc) = pvVar4;
        *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + 0x80;
      }
      *(uint *)(*(int *)(iVar3 + 0xc) + *puVar6 * 4) = local_20;
      uVar5 = *puVar6;
      *puVar6 = uVar5 + 1;
      if (*(uint *)(iVar3 + 8) <= uVar5 + 1) {
        pvVar4 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(iVar3 + 8) * 4 + 0x200);
        if (*(void **)(iVar3 + 0xc) != (void *)0x0) {
          _memcpy(pvVar4,*(void **)(iVar3 + 0xc),*puVar6 << 2);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0xc));
        }
        *(void **)(iVar3 + 0xc) = pvVar4;
        *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + 0x80;
      }
      *(undefined4 *)(*(int *)(iVar3 + 0xc) + *puVar6 * 4) = local_24;
      uVar5 = *puVar6;
      *puVar6 = uVar5 + 1;
      if (*(uint *)(iVar3 + 8) <= uVar5 + 1) {
        pvVar4 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(iVar3 + 8) * 4 + 0x200);
        if (*(void **)(iVar3 + 0xc) != (void *)0x0) {
          _memcpy(pvVar4,*(void **)(iVar3 + 0xc),*puVar6 << 2);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0xc));
        }
        *(void **)(iVar3 + 0xc) = pvVar4;
        *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + 0x80;
      }
      *(undefined4 *)(*(int *)(iVar3 + 0xc) + *puVar6 * 4) = 0x120000;
      *puVar6 = *puVar6 + 1;
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 != 4);
  if (*(uint *)(iVar3 + 8) <= *puVar6) {
    pvVar4 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(iVar3 + 8) * 4 + 0x200);
    if (*(void **)(iVar3 + 0xc) != (void *)0x0) {
      _memcpy(pvVar4,*(void **)(iVar3 + 0xc),*puVar6 << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0xc));
    }
    *(void **)(iVar3 + 0xc) = pvVar4;
    *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + 0x80;
  }
  *(undefined4 *)(*(int *)(iVar3 + 0xc) + *puVar6 * 4) = 0x28;
  *puVar6 = *puVar6 + 1;
  (**(code **)(param_1 + 0x1288))(param_1,0,iVar3,puVar6);
  return;
}

/* FUN_000b4709 @ 0xb4709 (2458 bytes) */
int FUN_000b4709(param_1, param_2)
  int param_1;
  int param_2;
{
  byte bVar1;
  short sVar2;
  int iVar3;
  bool bVar4;
  char cVar5;
  undefined1 *puVar6;
  void *pvVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint *puVar12;
  short *local_6c;
  char local_65;
  undefined4 local_64;
  undefined1 local_49;
  uint local_48;
  int local_34;
  int local_30;
  uint local_28 [5];
  undefined4 local_14;
  
  local_65 = param_2;
  iVar8 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (param_2 == '\0') {
    cVar5 = FUN_0004a77d(param_1);
    if (cVar5 != '\0') {
      iVar10 = *(int *)(param_1 + 0x1e5c);
      if ((*(int *)(iVar10 + 0x36c4) == 0) ||
         (*(int *)(param_1 + 0x1488) != *(int *)(iVar10 + 0x36c4))) {
        if (*(char *)(param_1 + 0x1868) == '\0') {
          (**(code **)(param_1 + 0x1334))(param_1,0);
        }
        FUN_00049928(param_1);
        *(undefined4 *)(param_1 + 0x1488) = *(undefined4 *)(*(int *)(param_1 + 0x1e5c) + 0x36c4);
        *(undefined1 *)(*(int *)(param_1 + 0x1e5c) + 0x10ef) = 0;
        *(undefined4 *)(*(int *)(param_1 + 0x1e5c) + 0x1304) = 0;
        **(undefined4 **)(param_1 + 0x1e5c) = 0;
        iVar10 = *(int *)(param_1 + 0x1e5c);
      }
      *(undefined4 *)(iVar10 + 0x10e8) = 0xffffffff;
      if (*(int *)(param_1 + 0x23e0) == 0) {
        return;
      }
      iVar10 = *(int *)(param_1 + 0x1e5c);
      if (*(char *)(iVar10 + 0x36c8) != '\0') {
        *(undefined1 *)(iVar10 + 0x10ef) = 0;
        *(undefined4 *)(*(int *)(param_1 + 0x1e5c) + 0x1530) = 0;
        *(undefined4 *)(*(int *)(param_1 + 0x1e5c) + 0x1c) = 0;
        return;
      }
      local_65 = '\x01';
      goto LAB_000b473a;
    }
  }
  else {
    iVar10 = *(int *)(param_1 + 0x1e5c);
LAB_000b473a:
    *(undefined1 *)(iVar10 + 0x36c8) = 1;
    *(undefined4 *)(*(int *)(param_1 + 0x1e5c) + 0x1c) = 0;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x1e5c) + 0x10e8) = 0xffffffff;
  puVar6 = (undefined1 *)(**(code **)(param_1 + 0xc))(0x38a0);
  iVar10 = *(int *)(param_1 + 0x1e5c);
  if (*(int *)(iVar10 + 0x36c4) != 0) {
    pvVar7 = *(void **)(*(int *)(iVar10 + 0x36c4) + 0xc);
    if (pvVar7 != (void *)0x0) {
      _free(pvVar7);
      *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1e5c) + 0x36c4) + 0xc) = 0;
      iVar10 = *(int *)(param_1 + 0x1e5c);
    }
    _free(*(void **)(iVar10 + 0x36c4));
    iVar10 = *(int *)(param_1 + 0x1e5c);
  }
  *(undefined1 **)(iVar10 + 0x36c4) = puVar6;
  **(undefined4 **)(param_1 + 0x1e5c) = 0;
  *puVar6 = 0;
  *(uint *)(puVar6 + 0x1678) =
       *(uint *)(puVar6 + 0x1678) & 0xffc0003f | *(uint *)(param_1 + 0x18a4) & 0x3fffc0;
  puVar12 = (uint *)(puVar6 + 4);
  *(undefined4 *)(puVar6 + 4) = 0;
  *(undefined4 *)(puVar6 + 8) = 0;
  *(undefined4 *)(puVar6 + 0xc) = 0;
  pvVar7 = (void *)(**(code **)(param_1 + 0xc))(0x200);
  if (*(void **)(puVar6 + 0xc) != (void *)0x0) {
    _memcpy(pvVar7,*(void **)(puVar6 + 0xc),*(int *)(puVar6 + 4) << 2);
    (**(code **)(param_1 + 0x18))(*(undefined4 *)(puVar6 + 0xc));
  }
  *(void **)(puVar6 + 0xc) = pvVar7;
  *(int *)(puVar6 + 8) = *(int *)(puVar6 + 8) + 0x80;
  *(undefined4 *)((int)pvVar7 + *(int *)(puVar6 + 4) * 4) = 1;
  iVar10 = *(int *)(puVar6 + 4);
  *(uint *)(puVar6 + 4) = iVar10 + 1U;
  if (*(uint *)(puVar6 + 8) <= iVar10 + 1U) {
    pvVar7 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(puVar6 + 8) * 4 + 0x200);
    if (*(void **)(puVar6 + 0xc) != (void *)0x0) {
      _memcpy(pvVar7,*(void **)(puVar6 + 0xc),*(int *)(puVar6 + 4) << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(puVar6 + 0xc));
    }
    *(void **)(puVar6 + 0xc) = pvVar7;
    *(int *)(puVar6 + 8) = *(int *)(puVar6 + 8) + 0x80;
  }
  *(undefined **)(*(int *)(puVar6 + 0xc) + *puVar12 * 4) = ((unsigned char *)0x00010200);
  *puVar12 = *puVar12 + 1;
  iVar10 = 0;
  do {
    *(undefined1 *)(iVar10 + 0x2de0 + *(int *)(param_1 + 0x1e5c)) = 1;
    iVar10 = iVar10 + 1;
  } while (iVar10 != 0x14);
  uVar9 = (uint)*(byte *)(param_1 + 0x13b2);
  if ((uint)*(byte *)(param_1 + 0x2b) <= (uint)*(byte *)(param_1 + 0x13b2)) {
    uVar9 = (uint)*(byte *)(param_1 + 0x2b);
  }
  FUN_000d562f(param_1,puVar6);
  FUN_000d7bf5(param_1,puVar6,0);
  iVar10 = *(int *)(puVar6 + 4);
  if (uVar9 == 0) {
    local_49 = 1;
    local_48 = 0;
  }
  else {
    local_34 = param_1;
    local_30 = param_1;
    uVar11 = 0;
    local_49 = 1;
    local_48 = 0;
    local_6c = (short *)(param_1 + 0x454);
    do {
      iVar3 = *(int *)(local_34 + 0x13f8);
      if (iVar3 != 0) {
        if (*(short *)(local_30 + 0x450) == -0x7a90) {
          if (*local_6c != -0x7885) {
            FUN_000d5edd(param_1,puVar6,*(undefined2 *)(iVar3 + 0x38),uVar11,iVar3,local_49,local_48
                        );
            local_49 = 0;
            local_48 = uVar11;
          }
        }
        else {
          FUN_000d6f8b(param_1,puVar6,*(undefined2 *)(iVar3 + 0x38),*(short *)(local_30 + 0x450),
                       uVar11,iVar3,local_49,local_48);
          local_49 = 0;
          local_48 = uVar11;
        }
      }
      uVar11 = uVar11 + 1;
      local_6c = local_6c + 0x66;
      local_34 = local_34 + 4;
      local_30 = local_30 + 0xcc;
    } while (uVar9 != uVar11);
  }
  bVar1 = *(byte *)(param_1 + 0x45);
  if ((bVar1 & 8) == 0) {
    if ((((*(byte *)(param_1 + 0x44) & 1) != 0) &&
        (*(short *)(*(int *)(*(int *)(param_1 + 4) + 0x10) + 0x2d48) == -0x7e06)) ||
       ((*(ushort *)(param_1 + 0x44) & 0x101) == 0x100)) goto LAB_000b4d64;
LAB_000b4a37:
    bVar4 = false;
  }
  else {
    if (((bVar1 & 1) == 0) || (*(char *)(*(int *)(param_1 + 0x1168) + 0x6e) == '\0'))
    goto LAB_000b4a37;
LAB_000b4d64:
    bVar4 = true;
  }
  if ((bVar4) || ((bVar1 & 4) != 0)) {
    FUN_000d539a(param_1,puVar12,local_49,local_48);
  }
  if (iVar10 == *(int *)(puVar6 + 4)) {
    local_64 = 0x170000;
    iVar10 = 0;
    do {
      if (((int)(*(uint *)(puVar6 + 0x1678) >> 6 & 0xffff) >> ((byte)iVar10 & 0x1f) & 1U) != 0) {
        local_64 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_64) + 2)),(short)iVar10);
        if (*(uint *)(puVar6 + 8) <= *puVar12) {
          pvVar7 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(puVar6 + 8) * 4 + 0x200);
          if (*(void **)(puVar6 + 0xc) != (void *)0x0) {
            _memcpy(pvVar7,*(void **)(puVar6 + 0xc),*puVar12 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(puVar6 + 0xc));
          }
          *(void **)(puVar6 + 0xc) = pvVar7;
          *(int *)(puVar6 + 8) = *(int *)(puVar6 + 8) + 0x80;
        }
        *(undefined4 *)(*(int *)(puVar6 + 0xc) + *puVar12 * 4) = 0x47;
        uVar9 = *puVar12;
        *puVar12 = uVar9 + 1;
        if (*(uint *)(puVar6 + 8) <= uVar9 + 1) {
          pvVar7 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(puVar6 + 8) * 4 + 0x200);
          if (*(void **)(puVar6 + 0xc) != (void *)0x0) {
            _memcpy(pvVar7,*(void **)(puVar6 + 0xc),*puVar12 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(puVar6 + 0xc));
          }
          *(void **)(puVar6 + 0xc) = pvVar7;
          *(int *)(puVar6 + 8) = *(int *)(puVar6 + 8) + 0x80;
        }
        *(undefined4 *)(*(int *)(puVar6 + 0xc) + *puVar12 * 4) = local_64;
        uVar9 = *puVar12;
        *puVar12 = uVar9 + 1;
        if (*(uint *)(puVar6 + 8) <= uVar9 + 1) {
          pvVar7 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(puVar6 + 8) * 4 + 0x200);
          if (*(void **)(puVar6 + 0xc) != (void *)0x0) {
            _memcpy(pvVar7,*(void **)(puVar6 + 0xc),*puVar12 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(puVar6 + 0xc));
          }
          *(void **)(puVar6 + 0xc) = pvVar7;
          *(int *)(puVar6 + 8) = *(int *)(puVar6 + 8) + 0x80;
        }
        *(undefined4 *)(*(int *)(puVar6 + 0xc) + *puVar12 * 4) = 0x120000;
        *puVar12 = *puVar12 + 1;
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 != 4);
    uVar9 = *(uint *)(puVar6 + 8);
    if (*puVar12 < uVar9) goto LAB_000b4b0a;
  }
  else {
    FUN_000d51f7(param_1,puVar12,0,local_48,*(uint *)(puVar6 + 0x1678) >> 6 & 0xffff);
    uVar9 = *(uint *)(puVar6 + 8);
    if (*puVar12 < uVar9) goto LAB_000b4b0a;
  }
  pvVar7 = (void *)(**(code **)(param_1 + 0xc))(uVar9 * 4 + 0x200);
  if (*(void **)(puVar6 + 0xc) != (void *)0x0) {
    _memcpy(pvVar7,*(void **)(puVar6 + 0xc),*puVar12 << 2);
    (**(code **)(param_1 + 0x18))(*(undefined4 *)(puVar6 + 0xc));
  }
  *(void **)(puVar6 + 0xc) = pvVar7;
  *(int *)(puVar6 + 8) = *(int *)(puVar6 + 8) + 0x80;
LAB_000b4b0a:
  *(undefined4 *)(*(int *)(puVar6 + 0xc) + *puVar12 * 4) = 0x28;
  *puVar12 = *puVar12 + 1;
  puVar12 = local_28;
  for (iVar10 = 7; iVar10 != 0; iVar10 = iVar10 + -1) {
    *puVar12 = 0;
    puVar12 = puVar12 + 1;
  }
  local_28[0] = *(uint *)(puVar6 + 0xc);
  local_28[1] = *(uint *)(puVar6 + 4);
  local_28[2] = 0;
  local_28[3] = 0x83;
  local_14 = 2;
  _memset((void *)(*(int *)(param_1 + 0x1e5c) + 0x2fe0),0,0x100);
  iVar10 = 0;
  do {
    *(undefined1 *)(iVar10 + 0x2fe0 + *(int *)(param_1 + 0x1e5c)) = 1;
    iVar10 = iVar10 + 1;
  } while (iVar10 != 0x14);
  *(undefined4 *)(*(int *)(param_1 + 0x1e5c) + 0x1784) = 0;
  if (local_65 != '\0') {
    *(undefined4 *)(*(int *)(param_1 + 0x1e5c) + 0x1710) = *(undefined4 *)(param_1 + 0x276c);
    local_28[3] = local_28[3] | 0x100;
  }
  if (*(char *)(param_1 + 0x121) != '\0') {
    sVar2 = *(short *)(iVar8 + 0x2e04);
    if (sVar2 == 0x801) {
      local_28[3] = local_28[3] | 0xc;
    }
    else if (sVar2 == 0x2601) {
      local_28[3] = local_28[3] | 4;
    }
    else if (sVar2 == 0x800) {
      local_28[3] = local_28[3] | 8;
    }
  }
  if (*(int *)(param_1 + 0x245c) != 0) {
    local_28[4] = 0;
    iVar8 = 0;
    do {
      local_28[4] = local_28[4] * 2 | 1;
      iVar8 = iVar8 + 1;
    } while (*(int *)(param_1 + 0x245c) != iVar8);
    local_28[3] = local_28[3] | 0x400;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x1e5c) + 0x10dc) = 0xff;
  iVar8 = *(int *)(param_1 + 0x1e5c);
  ((int (*)())FUN_000b27cd)(param_1,iVar8 + 0x1788,iVar8 + 0x1664,local_28,iVar8);
  (**(code **)(param_1 + 0x1334))(param_1,0);
  if ((local_65 == '\0') && (*(int *)(param_1 + 0x23e0) != 0)) {
    *(undefined4 *)(*(int *)(param_1 + 0x1e5c) + 0x1710) = *(undefined4 *)(param_1 + 0x276c);
    local_28[3] = local_28[3] | 0x100;
    iVar8 = *(int *)(param_1 + 0x1e5c);
    ((int (*)())FUN_000b27cd)(param_1,iVar8 + 0x1788,iVar8 + 0x1664,local_28,iVar8);
    if (*(char *)(param_1 + 0x1868) == '\0') {
      (**(code **)(param_1 + 0x1334))(param_1,0);
    }
  }
  if (*(char *)(param_1 + 0x121) != '\0') {
    iVar8 = *(int *)(param_1 + 0x1e5c);
    *(int *)(*(int *)(iVar8 + 0x36c4) + 0x3890) =
         *(int *)(iVar8 + 0x1748) - *(int *)(iVar8 + 0x36a4);
    iVar8 = *(int *)(param_1 + 0x1e5c);
    *(int *)(*(int *)(iVar8 + 0x36c4) + 0x3894) =
         *(int *)(iVar8 + 0x1744) - *(int *)(iVar8 + 0x36a4);
    *(undefined1 *)
     (*(int *)(*(int *)(*(int *)(param_1 + 0x1e5c) + 0x36c4) + 0x3890) + 0x2de0 +
     *(int *)(param_1 + 0x1e5c)) = 1;
    *(undefined1 *)
     (*(int *)(*(int *)(*(int *)(param_1 + 0x1e5c) + 0x36c4) + 0x3894) + 0x2de0 +
     *(int *)(param_1 + 0x1e5c)) = 1;
  }
  ((int (*)())FUN_000b3654)(param_1,*(int *)(param_1 + 0x1e5c) + 0x1788,*(int *)(param_1 + 0x1e5c) + 0x1664);
  *(undefined1 **)(param_1 + 0x1488) = puVar6;
  FUN_00049928(param_1);
  return;
}

/* FUN_000b50a3 @ 0xb50a3 (978 bytes) */
int FUN_000b50a3(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  byte *pbVar1;
  uint *puVar2;
  ushort *puVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  float fVar9;
  float fVar10;
  byte bVar11;
  uint uVar12;
  byte bVar13;
  float fVar14;
  undefined4 in_XMM0_Db;
  undefined4 in_XMM0_Dc;
  undefined4 in_XMM0_Dd;
  undefined1 auVar15 [16];
  undefined1 auVar16 [16];
  float fVar17;
  float fVar18;
  float fVar19;
  
  if (param_4 != 0) {
    iVar5 = *(int *)(param_1 + 4);
    bVar13 = *(byte *)(param_1 + 0x1cdd + param_3 * 4);
    bVar11 = bVar13 >> 5 & 3;
    bVar4 = *(byte *)(param_1 + 0x1cde + param_3 * 4);
    uVar6 = 1 << (bVar4 >> 5);
    fVar19 = 0.0;
    fVar18 = *(float *)(param_2 + 0x4c) + *(float *)(param_1 + 0x470 + param_3 * 0xcc) + 0.0;
    pbVar1 = (byte *)(param_1 + 0x1d1d + param_3 * 4);
    *pbVar1 = *pbVar1 & 0xdf;
    puVar2 = (uint *)(param_1 + 0x1d1c + param_3 * 4);
    *puVar2 = *puVar2 & 0xfffe7fff;
    puVar3 = (ushort *)(param_1 + 0x1d1e + param_3 * 4);
    *puVar3 = *puVar3 & 0xe07f;
    *(byte *)(param_1 + 0x1d1e + param_3 * 4) =
         *(byte *)(param_1 + 0x1d1e + param_3 * 4) & 0xf1 | 0x10;
    *(byte *)(param_1 + 0x1d1f + param_3 * 4) =
         *(byte *)(param_1 + 0x1d1f + param_3 * 4) & 0xbf | 0x20;
    fVar10 = DAT_001c64a0;
    fVar9 = DAT_001c6490;
    fVar17 = (float)*(int *)(iVar5 + 0x15c) / FLOAT_001c5c50;
    fVar14 = (float)*(int *)(iVar5 + 0x160) / FLOAT_001c5c54;
    if (fVar17 <= fVar14) {
      fVar14 = fVar17;
    }
    fVar14 = fVar14 * fVar18 * FLOAT_001c5c58 + fVar14;
    if (bVar11 == 2) {
      (*(unsigned int *)((unsigned char *)&(auVar16) + 4)) = in_XMM0_Db;
      (*(unsigned int *)((unsigned char *)&(auVar16) + 0)) = fVar14;
      (*(unsigned int *)((unsigned char *)&(auVar16) + 8)) = in_XMM0_Dc;
      (*(unsigned int *)((unsigned char *)&(auVar16) + 12)) = in_XMM0_Dd;
      (*(unsigned int *)((unsigned char *)&(auVar15) + 4)) = (*(unsigned int *)((unsigned char *)&(auVar16) + 4));
      (*(unsigned int *)((unsigned char *)&(auVar15) + 0)) = fVar14 * FLOAT_001c5c5c;
    }
    else {
      _memset(auVar15, 0, 16);
    }
    if (param_4 == 1) {
      fVar17 = (*(unsigned int *)((unsigned char *)&(auVar15) + 0));
      if ((bVar13 >> 3 & 3) == 3) {
        if (uVar6 < 4) {
          if (fVar17 <= 0.0) {
            (*(unsigned int *)((unsigned char *)&(auVar8) + 12)) = 0;
            (*(unsigned int *)((unsigned char *)&(auVar8) + 0)) = (*(unsigned int *)((unsigned char *)&(auVar15) + 4));
            { unsigned char t_[16]; _memset(t_, 0, 16); _memcpy(t_ + 4, auVar8, 12); _memcpy(auVar15, t_, 16); }
          }
          fVar14 = (*(unsigned int *)((unsigned char *)&(auVar15) + 0));
          uVar12 = (int)(fVar14 - (float)(-(uint)(DAT_001c6490 <= fVar14) & (uint)DAT_001c6490)) |
                   -(uint)(DAT_001c64a0 <= fVar14);
          bVar13 = 0;
        }
        else {
          fVar17 = fVar17 * FLOAT_001c5bf0;
          if (fVar17 <= FLOAT_001c5c10) {
            if (0.0 <= fVar17) {
              if (fVar17 <= 0.0) {
                fVar17 = 0.0;
              }
              uVar12 = (int)(fVar17 - (float)(-(uint)(DAT_001c6490 <= fVar17) & (uint)DAT_001c6490))
                       | -(uint)(DAT_001c64a0 <= fVar17);
            }
            else {
              uVar12 = 0;
            }
          }
          else {
            uVar12 = 3;
          }
          if ((((bVar11 != 0) || ((bVar13 >> 1 & 3) != 2)) || (fVar18 != 0.0)) || (NAN(fVar18))) {
            fVar19 = fVar14 * FLOAT_001c5c60 * FLOAT_001c5bc0;
            fVar14 = fVar14 * FLOAT_001c5c64;
            if (fVar14 <= 0.0) {
              fVar14 = 0.0;
            }
            bVar13 = (byte)(int)(fVar14 - (float)(-(uint)(DAT_001c6490 <= fVar14) &
                                                 (uint)DAT_001c6490)) | -(DAT_001c64a0 <= fVar14);
          }
          else {
            bVar13 = 0;
          }
        }
      }
      else {
        if (fVar17 <= 0.0) {
          (*(unsigned int *)((unsigned char *)&(auVar7) + 12)) = 0;
          (*(unsigned int *)((unsigned char *)&(auVar7) + 0)) = (*(unsigned int *)((unsigned char *)&(auVar15) + 4));
          { unsigned char t_[16]; _memset(t_, 0, 16); _memcpy(t_ + 4, auVar7, 12); _memcpy(auVar15, t_, 16); }
        }
        fVar14 = (*(unsigned int *)((unsigned char *)&(auVar15) + 0));
        uVar12 = (int)(fVar14 - (float)(-(uint)(DAT_001c6490 <= fVar14) & (uint)DAT_001c6490)) |
                 -(uint)(DAT_001c64a0 <= fVar14);
        bVar13 = 0;
      }
      *(byte *)(param_1 + 0x1cde + param_3 * 4) =
           bVar4 & 0x1f | (char)*(undefined4 *)(&DAT_001eec00 + uVar6 * 4) << 5;
      *(uint *)(param_1 + 0x1d1c + param_3 * 4) =
           *(uint *)(param_1 + 0x1d1c + param_3 * 4) & 0xfffe7fff | (uVar12 & 3) << 0xf;
      if (fVar19 <= 0.0) {
        fVar19 = 0.0;
      }
      *(ushort *)(param_1 + 0x1d1e + param_3 * 4) =
           *(ushort *)(param_1 + 0x1d1e + param_3 * 4) & 0xe07f |
           (ushort)((((int)(fVar19 - (float)((uint)fVar9 & -(uint)(fVar9 <= fVar19))) |
                     -(uint)(fVar10 <= fVar19)) & 0x3f) << 7);
      *(byte *)(param_1 + 0x1d1e + param_3 * 4) =
           *(byte *)(param_1 + 0x1d1e + param_3 * 4) & 0xf1 | (bVar13 & 7) * '\x02';
    }
  }
  return;
}

/* FUN_000b5478 @ 0xb5478 (101 bytes) */
int FUN_000b5478(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 *param_2;
  int param_3;
  undefined1 *param_4;
  undefined1 *param_5;
  undefined1 *param_6;
  undefined1 *param_7;
{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  bool bVar15;
  undefined1 uVar16;
  int iVar17;
  bool bVar18;
  
  cVar1 = *(char *)(param_2 + 3);
  cVar2 = *(char *)(param_2 + 4);
  cVar3 = *(char *)(param_2 + 5);
  cVar4 = *(char *)(param_2 + 6);
  switch(*param_2) {
  case 0x8782:
code_r0x000b559b:
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
    iVar17 = FUN_00053994(param_1,param_2 + 8);
    if (iVar17 != 0x87bf) goto code_r0x000b5581;
    if (((cVar1 == '\0') || ((param_2[10] != 0x87d5 && (param_2[10] != 0x87d9)))) &&
       ((((cVar2 == '\0' || ((param_2[0xb] != 0x87d5 && (param_2[0xb] != 0x87d9)))) &&
         ((cVar3 == '\0' || ((param_2[0xc] != 0x87d5 && (param_2[0xc] != 0x87d9)))))) &&
        ((cVar4 == '\0' || ((param_2[0xd] != 0x87d5 && (param_2[0xd] != 0x87d9)))))))) {
      uVar16 = 0;
    }
    else {
      uVar16 = 1;
    }
    *param_4 = uVar16;
    if ((((cVar1 == '\0') || ((param_2[10] != 0x87d6 && (param_2[10] != 0x87da)))) &&
        ((cVar2 == '\0' || ((param_2[0xb] != 0x87d6 && (param_2[0xb] != 0x87da)))))) &&
       ((cVar3 == '\0' || ((param_2[0xc] != 0x87d6 && (param_2[0xc] != 0x87da))))))
    goto joined_r0x000b5d0d;
code_r0x000b60a1:
    uVar16 = 1;
    goto code_r0x000b5d15;
  case 0x8784:
    if ((param_2[8] == 2) && (param_3 == param_2[9])) {
      iVar17 = param_2[10];
      if ((((iVar17 == 0x87d5) || (iVar17 == 0x87d9)) || (param_2[0xb] == 0x87d5)) ||
         (((param_2[0xb] == 0x87d9 || (param_2[0xc] == 0x87d5)) || (param_2[0xc] == 0x87d9)))) {
        bVar8 = true;
      }
      else {
        bVar8 = false;
      }
      if (((iVar17 == 0x87d6) || (iVar17 == 0x87da)) ||
         ((param_2[0xb] == 0x87d6 ||
          (((param_2[0xb] == 0x87da || (param_2[0xc] == 0x87d6)) || (param_2[0xc] == 0x87da)))))) {
        bVar10 = true;
      }
      else {
        bVar10 = false;
      }
      if (((iVar17 == 0x87d7) || (iVar17 == 0x87db)) ||
         (((param_2[0xb] == 0x87d7 || ((param_2[0xb] == 0x87db || (param_2[0xc] == 0x87d7)))) ||
          (param_2[0xc] == 0x87db)))) {
        bVar11 = true;
      }
      else {
        bVar11 = false;
      }
      if (((((iVar17 != 0x87d8) && (iVar17 != 0x87dc)) && (param_2[0xb] != 0x87d8)) &&
          ((param_2[0xb] != 0x87dc && (param_2[0xc] != 0x87d8)))) && (param_2[0xc] != 0x87dc))
      goto code_r0x000b5a26;
      bVar13 = true;
    }
    else {
      bVar8 = false;
      bVar10 = false;
      bVar11 = false;
code_r0x000b5a26:
      bVar13 = false;
    }
    if ((param_2[0xf] == 2) && (param_3 == param_2[0x10])) {
      iVar17 = param_2[0x11];
      if ((((iVar17 == 0x87d5) || (iVar17 == 0x87d9)) || (param_2[0x12] == 0x87d5)) ||
         (((param_2[0x12] == 0x87d9 || (param_2[0x13] == 0x87d5)) || (param_2[0x13] == 0x87d9)))) {
        bVar9 = true;
      }
      else {
        bVar9 = false;
      }
      if (((iVar17 == 0x87d6) || (iVar17 == 0x87da)) ||
         ((param_2[0x12] == 0x87d6 ||
          (((param_2[0x12] == 0x87da || (param_2[0x13] == 0x87d6)) || (param_2[0x13] == 0x87da))))))
      {
        bVar18 = true;
      }
      else {
        bVar18 = false;
      }
      if (((iVar17 == 0x87d7) || (iVar17 == 0x87db)) ||
         (((param_2[0x12] == 0x87d7 || ((param_2[0x12] == 0x87db || (param_2[0x13] == 0x87d7)))) ||
          (param_2[0x13] == 0x87db)))) {
        bVar12 = true;
      }
      else {
        bVar12 = false;
      }
      if (((((iVar17 != 0x87d8) && (iVar17 != 0x87dc)) && (param_2[0x12] != 0x87d8)) &&
          ((param_2[0x12] != 0x87dc && (param_2[0x13] != 0x87d8)))) && (param_2[0x13] != 0x87dc))
      goto code_r0x000b5a3c;
      bVar14 = true;
    }
    else {
      bVar9 = false;
      bVar18 = false;
      bVar12 = false;
code_r0x000b5a3c:
      bVar14 = false;
    }
    if ((bVar8) || (bVar9)) {
      uVar16 = 1;
    }
    else {
      uVar16 = 0;
    }
    *param_4 = uVar16;
    if ((bVar10) || (uVar16 = 0, bVar18)) {
      uVar16 = 1;
    }
    *param_5 = uVar16;
    if ((bVar11) || (bVar12)) {
      uVar16 = 1;
    }
    else {
      uVar16 = 0;
    }
    *param_6 = uVar16;
    if (bVar13) goto code_r0x000b5681;
    goto code_r0x000b59fc;
  case 0x8785:
    if ((param_2[8] == 2) && (param_3 == param_2[9])) {
      iVar17 = param_2[10];
      if ((((((iVar17 == 0x87d5) || (iVar17 == 0x87d9)) || (param_2[0xb] == 0x87d5)) ||
           ((param_2[0xb] == 0x87d9 || (param_2[0xc] == 0x87d5)))) || (param_2[0xc] == 0x87d9)) ||
         ((param_2[0xd] == 0x87d5 || (param_2[0xd] == 0x87d9)))) {
        bVar8 = true;
      }
      else {
        bVar8 = false;
      }
      if ((((iVar17 == 0x87d6) || (iVar17 == 0x87da)) || (param_2[0xb] == 0x87d6)) ||
         (((param_2[0xb] == 0x87da || (param_2[0xc] == 0x87d6)) ||
          ((param_2[0xc] == 0x87da || ((param_2[0xd] == 0x87d6 || (param_2[0xd] == 0x87da)))))))) {
        bVar10 = true;
      }
      else {
        bVar10 = false;
      }
      if ((((iVar17 == 0x87d7) || (iVar17 == 0x87db)) || (param_2[0xb] == 0x87d7)) ||
         (((param_2[0xb] == 0x87db || (param_2[0xc] == 0x87d7)) ||
          ((param_2[0xc] == 0x87db || ((param_2[0xd] == 0x87d7 || (param_2[0xd] == 0x87db)))))))) {
        bVar11 = true;
      }
      else {
        bVar11 = false;
      }
      if (((((iVar17 != 0x87d8) && (iVar17 != 0x87dc)) && (param_2[0xb] != 0x87d8)) &&
          ((param_2[0xb] != 0x87dc && (param_2[0xc] != 0x87d8)))) &&
         ((param_2[0xc] != 0x87dc && ((param_2[0xd] != 0x87d8 && (param_2[0xd] != 0x87dc))))))
      goto code_r0x000b5f41;
      bVar13 = true;
    }
    else {
      bVar8 = false;
      bVar10 = false;
      bVar11 = false;
code_r0x000b5f41:
      bVar13 = false;
    }
    if ((param_2[0xf] == 2) && (param_3 == param_2[0x10])) {
      iVar17 = param_2[0x11];
      if ((((iVar17 == 0x87d5) || (iVar17 == 0x87d9)) || (param_2[0x12] == 0x87d5)) ||
         (((param_2[0x12] == 0x87d9 || (param_2[0x13] == 0x87d5)) ||
          ((param_2[0x13] == 0x87d9 || ((param_2[0x14] == 0x87d5 || (param_2[0x14] == 0x87d9))))))))
      {
        bVar9 = true;
      }
      else {
        bVar9 = false;
      }
      if ((((iVar17 == 0x87d6) || (iVar17 == 0x87da)) || (param_2[0x12] == 0x87d6)) ||
         (((param_2[0x12] == 0x87da || (param_2[0x13] == 0x87d6)) ||
          ((param_2[0x13] == 0x87da || ((param_2[0x14] == 0x87d6 || (param_2[0x14] == 0x87da))))))))
      {
        bVar18 = true;
      }
      else {
        bVar18 = false;
      }
      if (((((iVar17 == 0x87d7) || (iVar17 == 0x87db)) || (param_2[0x12] == 0x87d7)) ||
          ((param_2[0x12] == 0x87db || (param_2[0x13] == 0x87d7)))) ||
         ((param_2[0x13] == 0x87db || ((param_2[0x14] == 0x87d7 || (param_2[0x14] == 0x87db)))))) {
        bVar12 = true;
      }
      else {
        bVar12 = false;
      }
      if ((((iVar17 != 0x87d8) && (iVar17 != 0x87dc)) && (param_2[0x12] != 0x87d8)) &&
         (((param_2[0x12] != 0x87dc && (param_2[0x13] != 0x87d8)) &&
          ((param_2[0x13] != 0x87dc && ((param_2[0x14] != 0x87d8 && (param_2[0x14] != 0x87dc))))))))
      goto code_r0x000b5f57;
      bVar14 = true;
    }
    else {
      bVar9 = false;
      bVar18 = false;
      bVar12 = false;
code_r0x000b5f57:
      bVar14 = false;
    }
    if ((bVar8) || (bVar9)) {
      uVar16 = 1;
    }
    else {
      uVar16 = 0;
    }
    *param_4 = uVar16;
    if ((bVar10) || (uVar16 = 0, bVar18)) {
      uVar16 = 1;
    }
    *param_5 = uVar16;
    if ((bVar11) || (bVar12)) {
      uVar16 = 1;
    }
    else {
      uVar16 = 0;
    }
    *param_6 = uVar16;
    break;
  case 0x8786:
  case 0x8787:
  case 0x878a:
  case 0x878b:
  case 0x878c:
  case 0x878d:
  case 0x8796:
    if ((param_2[8] == 2) && (param_3 == param_2[9])) {
      iVar17 = FUN_00053994(param_1,param_2 + 8);
      if (iVar17 == 0x87bf) {
        if (((((cVar1 == '\0') || ((param_2[10] != 0x87d5 && (param_2[10] != 0x87d9)))) &&
             ((cVar2 == '\0' || ((param_2[0xb] != 0x87d5 && (param_2[0xb] != 0x87d9)))))) &&
            ((cVar3 == '\0' || ((param_2[0xc] != 0x87d5 && (param_2[0xc] != 0x87d9)))))) &&
           ((cVar4 == '\0' || ((param_2[0xd] != 0x87d5 && (param_2[0xd] != 0x87d9)))))) {
          bVar11 = false;
        }
        else {
          bVar11 = true;
        }
        if ((((cVar1 == '\0') || ((param_2[10] != 0x87d6 && (param_2[10] != 0x87da)))) &&
            ((cVar2 == '\0' || ((param_2[0xb] != 0x87d6 && (param_2[0xb] != 0x87da)))))) &&
           (((cVar3 == '\0' || ((param_2[0xc] != 0x87d6 && (param_2[0xc] != 0x87da)))) &&
            ((cVar4 == '\0' || ((param_2[0xd] != 0x87d6 && (param_2[0xd] != 0x87da)))))))) {
          bVar8 = false;
        }
        else {
          bVar8 = true;
        }
        if ((((cVar1 == '\0') || ((param_2[10] != 0x87d7 && (param_2[10] != 0x87db)))) &&
            ((cVar2 == '\0' || ((param_2[0xb] != 0x87d7 && (param_2[0xb] != 0x87db)))))) &&
           (((cVar3 == '\0' || ((param_2[0xc] != 0x87d7 && (param_2[0xc] != 0x87db)))) &&
            ((cVar4 == '\0' || ((param_2[0xd] != 0x87d7 && (param_2[0xd] != 0x87db)))))))) {
          bVar10 = false;
        }
        else {
          bVar10 = true;
        }
        if (((((cVar1 == '\0') || ((param_2[10] != 0x87d8 && (param_2[10] != 0x87dc)))) &&
             ((cVar2 == '\0' || ((param_2[0xb] != 0x87d8 && (param_2[0xb] != 0x87dc)))))) &&
            ((cVar3 == '\0' || ((param_2[0xc] != 0x87d8 && (param_2[0xc] != 0x87dc)))))) &&
           ((cVar4 == '\0' || ((param_2[0xd] != 0x87d8 && (param_2[0xd] != 0x87dc))))))
        goto code_r0x000b5bac;
        bVar13 = true;
      }
      else {
        bVar11 = true;
        bVar8 = true;
        bVar10 = true;
        bVar13 = true;
      }
    }
    else {
      bVar11 = false;
      bVar8 = false;
      bVar10 = false;
code_r0x000b5bac:
      bVar13 = false;
    }
    if ((param_2[0xf] == 2) && (param_3 == param_2[0x10])) {
      iVar17 = FUN_00053994(param_1,param_2 + 0xf);
      if (iVar17 == 0x87bf) {
        if ((((cVar1 == '\0') || ((param_2[0x11] != 0x87d5 && (param_2[0x11] != 0x87d9)))) &&
            ((cVar2 == '\0' || ((param_2[0x12] != 0x87d5 && (param_2[0x12] != 0x87d9)))))) &&
           (((cVar3 == '\0' || ((param_2[0x13] != 0x87d5 && (param_2[0x13] != 0x87d9)))) &&
            ((cVar4 == '\0' || ((param_2[0x14] != 0x87d5 && (param_2[0x14] != 0x87d9)))))))) {
          bVar9 = false;
        }
        else {
          bVar9 = true;
        }
        if ((((cVar1 == '\0') || ((param_2[0x11] != 0x87d6 && (param_2[0x11] != 0x87da)))) &&
            ((cVar2 == '\0' || ((param_2[0x12] != 0x87d6 && (param_2[0x12] != 0x87da)))))) &&
           (((cVar3 == '\0' || ((param_2[0x13] != 0x87d6 && (param_2[0x13] != 0x87da)))) &&
            ((cVar4 == '\0' || ((param_2[0x14] != 0x87d6 && (param_2[0x14] != 0x87da)))))))) {
          bVar12 = false;
        }
        else {
          bVar12 = true;
        }
        if (((((cVar1 == '\0') || ((param_2[0x11] != 0x87d7 && (param_2[0x11] != 0x87db)))) &&
             ((cVar2 == '\0' || ((param_2[0x12] != 0x87d7 && (param_2[0x12] != 0x87db)))))) &&
            ((cVar3 == '\0' || ((param_2[0x13] != 0x87d7 && (param_2[0x13] != 0x87db)))))) &&
           ((cVar4 == '\0' || ((param_2[0x14] != 0x87d7 && (param_2[0x14] != 0x87db)))))) {
          bVar18 = false;
        }
        else {
          bVar18 = true;
        }
        if ((((cVar1 == '\0') || ((param_2[0x11] != 0x87d8 && (param_2[0x11] != 0x87dc)))) &&
            ((cVar2 == '\0' || ((param_2[0x12] != 0x87d8 && (param_2[0x12] != 0x87dc)))))) &&
           (((cVar3 == '\0' || ((param_2[0x13] != 0x87d8 && (param_2[0x13] != 0x87dc)))) &&
            ((cVar4 == '\0' || ((param_2[0x14] != 0x87d8 && (param_2[0x14] != 0x87dc))))))))
        goto code_r0x000b5bc4;
        bVar14 = true;
      }
      else {
        bVar9 = true;
        bVar12 = true;
        bVar18 = true;
        bVar14 = true;
      }
    }
    else {
      bVar9 = false;
      bVar12 = false;
      bVar18 = false;
code_r0x000b5bc4:
      bVar14 = false;
    }
    if ((bVar11) || (bVar9)) {
      uVar16 = 1;
    }
    else {
      uVar16 = 0;
    }
    *param_4 = uVar16;
    if ((bVar8) || (bVar12)) {
      uVar16 = 1;
    }
    else {
      uVar16 = 0;
    }
    *param_5 = uVar16;
    if ((bVar10) || (bVar18)) {
      uVar16 = 1;
    }
    else {
      uVar16 = 0;
    }
    *param_6 = uVar16;
    break;
  case 0x8788:
  case 0x878e:
    if ((param_2[8] == 2) && (param_3 == param_2[9])) {
      iVar17 = FUN_00053994(param_1,param_2 + 8);
      if (iVar17 == 0x87bf) {
        if (((((cVar1 == '\0') || ((param_2[10] != 0x87d5 && (param_2[10] != 0x87d9)))) &&
             ((cVar2 == '\0' || ((param_2[0xb] != 0x87d5 && (param_2[0xb] != 0x87d9)))))) &&
            ((cVar3 == '\0' || ((param_2[0xc] != 0x87d5 && (param_2[0xc] != 0x87d9)))))) &&
           ((cVar4 == '\0' || ((param_2[0xd] != 0x87d5 && (param_2[0xd] != 0x87d9)))))) {
          bVar11 = false;
        }
        else {
          bVar11 = true;
        }
        if ((((cVar1 == '\0') || ((param_2[10] != 0x87d6 && (param_2[10] != 0x87da)))) &&
            ((cVar2 == '\0' || ((param_2[0xb] != 0x87d6 && (param_2[0xb] != 0x87da)))))) &&
           (((cVar3 == '\0' || ((param_2[0xc] != 0x87d6 && (param_2[0xc] != 0x87da)))) &&
            ((cVar4 == '\0' || ((param_2[0xd] != 0x87d6 && (param_2[0xd] != 0x87da)))))))) {
          bVar8 = false;
        }
        else {
          bVar8 = true;
        }
        if (((((cVar1 == '\0') || ((param_2[10] != 0x87d7 && (param_2[10] != 0x87db)))) &&
             ((cVar2 == '\0' || ((param_2[0xb] != 0x87d7 && (param_2[0xb] != 0x87db)))))) &&
            ((cVar3 == '\0' || ((param_2[0xc] != 0x87d7 && (param_2[0xc] != 0x87db)))))) &&
           ((cVar4 == '\0' || ((param_2[0xd] != 0x87d7 && (param_2[0xd] != 0x87db)))))) {
          bVar10 = false;
        }
        else {
          bVar10 = true;
        }
        if (((((cVar1 == '\0') || ((param_2[10] != 0x87d8 && (param_2[10] != 0x87dc)))) &&
             ((cVar2 == '\0' || ((param_2[0xb] != 0x87d8 && (param_2[0xb] != 0x87dc)))))) &&
            ((cVar3 == '\0' || ((param_2[0xc] != 0x87d8 && (param_2[0xc] != 0x87dc)))))) &&
           ((cVar4 == '\0' || ((param_2[0xd] != 0x87d8 && (param_2[0xd] != 0x87dc))))))
        goto code_r0x000b55cb;
        bVar9 = true;
      }
      else {
        bVar11 = true;
        bVar8 = true;
        bVar10 = true;
        bVar9 = true;
      }
    }
    else {
      bVar11 = false;
      bVar8 = false;
      bVar10 = false;
code_r0x000b55cb:
      bVar9 = false;
    }
    if ((param_2[0xf] == 2) && (param_3 == param_2[0x10])) {
      iVar17 = FUN_00053994(param_1,param_2 + 0xf);
      if (iVar17 == 0x87bf) {
        if ((((cVar1 == '\0') || ((param_2[0x11] != 0x87d5 && (param_2[0x11] != 0x87d9)))) &&
            ((cVar2 == '\0' || ((param_2[0x12] != 0x87d5 && (param_2[0x12] != 0x87d9)))))) &&
           (((cVar3 == '\0' || ((param_2[0x13] != 0x87d5 && (param_2[0x13] != 0x87d9)))) &&
            ((cVar4 == '\0' || ((param_2[0x14] != 0x87d5 && (param_2[0x14] != 0x87d9)))))))) {
          bVar12 = false;
        }
        else {
          bVar12 = true;
        }
        if ((((cVar1 == '\0') || ((param_2[0x11] != 0x87d6 && (param_2[0x11] != 0x87da)))) &&
            ((cVar2 == '\0' || ((param_2[0x12] != 0x87d6 && (param_2[0x12] != 0x87da)))))) &&
           (((cVar3 == '\0' || ((param_2[0x13] != 0x87d6 && (param_2[0x13] != 0x87da)))) &&
            ((cVar4 == '\0' || ((param_2[0x14] != 0x87d6 && (param_2[0x14] != 0x87da)))))))) {
          bVar18 = false;
        }
        else {
          bVar18 = true;
        }
        if (((((cVar1 == '\0') || ((param_2[0x11] != 0x87d7 && (param_2[0x11] != 0x87db)))) &&
             ((cVar2 == '\0' || ((param_2[0x12] != 0x87d7 && (param_2[0x12] != 0x87db)))))) &&
            ((cVar3 == '\0' || ((param_2[0x13] != 0x87d7 && (param_2[0x13] != 0x87db)))))) &&
           ((cVar4 == '\0' || ((param_2[0x14] != 0x87d7 && (param_2[0x14] != 0x87db)))))) {
          bVar15 = false;
        }
        else {
          bVar15 = true;
        }
        if ((((cVar1 == '\0') || ((param_2[0x11] != 0x87d8 && (param_2[0x11] != 0x87dc)))) &&
            ((cVar2 == '\0' || ((param_2[0x12] != 0x87d8 && (param_2[0x12] != 0x87dc)))))) &&
           (((cVar3 == '\0' || ((param_2[0x13] != 0x87d8 && (param_2[0x13] != 0x87dc)))) &&
            ((cVar4 == '\0' || ((param_2[0x14] != 0x87d8 && (param_2[0x14] != 0x87dc))))))))
        goto code_r0x000b55e5;
        bVar13 = true;
      }
      else {
        bVar12 = true;
        bVar18 = true;
        bVar15 = true;
        bVar13 = true;
      }
    }
    else {
      bVar12 = false;
      bVar18 = false;
      bVar15 = false;
code_r0x000b55e5:
      bVar13 = false;
    }
    if ((param_2[0x16] == 2) && (param_3 == param_2[0x17])) {
      iVar17 = FUN_00053994(param_1,param_2 + 0x16);
      if (iVar17 == 0x87bf) {
        if (((((cVar1 == '\0') || ((param_2[0x18] != 0x87d5 && (param_2[0x18] != 0x87d9)))) &&
             ((cVar2 == '\0' || ((param_2[0x19] != 0x87d5 && (param_2[0x19] != 0x87d9)))))) &&
            ((cVar3 == '\0' || ((param_2[0x1a] != 0x87d5 && (param_2[0x1a] != 0x87d9)))))) &&
           ((cVar4 == '\0' || ((param_2[0x1b] != 0x87d5 && (param_2[0x1b] != 0x87d9)))))) {
          bVar5 = false;
        }
        else {
          bVar5 = true;
        }
        if (((((cVar1 == '\0') || ((param_2[0x18] != 0x87d6 && (param_2[0x18] != 0x87da)))) &&
             ((cVar2 == '\0' || ((param_2[0x19] != 0x87d6 && (param_2[0x19] != 0x87da)))))) &&
            ((cVar3 == '\0' || ((param_2[0x1a] != 0x87d6 && (param_2[0x1a] != 0x87da)))))) &&
           ((cVar4 == '\0' || ((param_2[0x1b] != 0x87d6 && (param_2[0x1b] != 0x87da)))))) {
          bVar6 = false;
        }
        else {
          bVar6 = true;
        }
        if ((((cVar1 == '\0') || ((param_2[0x18] != 0x87d7 && (param_2[0x18] != 0x87db)))) &&
            ((cVar2 == '\0' || ((param_2[0x19] != 0x87d7 && (param_2[0x19] != 0x87db)))))) &&
           (((cVar3 == '\0' || ((param_2[0x1a] != 0x87d7 && (param_2[0x1a] != 0x87db)))) &&
            ((cVar4 == '\0' || ((param_2[0x1b] != 0x87d7 && (param_2[0x1b] != 0x87db)))))))) {
          bVar7 = false;
        }
        else {
          bVar7 = true;
        }
        if ((((cVar1 == '\0') || ((param_2[0x18] != 0x87d8 && (param_2[0x18] != 0x87dc)))) &&
            ((cVar2 == '\0' || ((param_2[0x19] != 0x87d8 && (param_2[0x19] != 0x87dc)))))) &&
           (((cVar3 == '\0' || ((param_2[0x1a] != 0x87d8 && (param_2[0x1a] != 0x87dc)))) &&
            ((cVar4 == '\0' || ((param_2[0x1b] != 0x87d8 && (param_2[0x1b] != 0x87dc))))))))
        goto code_r0x000b55fd;
        bVar14 = true;
      }
      else {
        bVar5 = true;
        bVar6 = true;
        bVar7 = true;
        bVar14 = true;
      }
    }
    else {
      bVar5 = false;
      bVar6 = false;
      bVar7 = false;
code_r0x000b55fd:
      bVar14 = false;
    }
    if (((bVar11) || (bVar12)) || (bVar5)) {
      uVar16 = 1;
    }
    else {
      uVar16 = 0;
    }
    *param_4 = uVar16;
    if (((bVar8) || (bVar18)) || (bVar6)) {
      uVar16 = 1;
    }
    else {
      uVar16 = 0;
    }
    *param_5 = uVar16;
    if (((bVar10) || (bVar15)) || (bVar7)) {
      uVar16 = 1;
    }
    else {
      uVar16 = 0;
    }
    *param_6 = uVar16;
    if (bVar9) goto code_r0x000b5681;
    break;
  case 0x8791:
  case 0x8792:
  case 0x8793:
  case 0x8794:
  case 0x8795:
code_r0x000b5581:
    *param_4 = 1;
    *param_5 = 1;
    *param_6 = 1;
    *param_7 = 1;
    return;
  case 0x8797:
    if ((param_2[8] == 2) && (param_3 == param_2[9])) {
      if ((((cVar1 == '\0') ||
           (((param_2[0xb] != 0x87d5 && (param_2[0xb] != 0x87d9)) &&
            ((param_2[0xc] != 0x87d5 && (param_2[0xc] != 0x87d9)))))) &&
          ((cVar2 == '\0' ||
           ((((param_2[10] != 0x87d5 && (param_2[10] != 0x87d9)) && (param_2[0xc] != 0x87d5)) &&
            (param_2[0xc] != 0x87d9)))))) &&
         ((cVar3 == '\0' ||
          (((param_2[10] != 0x87d5 && (param_2[10] != 0x87d9)) &&
           ((param_2[0xb] != 0x87d5 && (param_2[0xb] != 0x87d9)))))))) {
        bVar8 = false;
      }
      else {
        bVar8 = true;
      }
      if ((((cVar1 == '\0') ||
           (((param_2[0xb] != 0x87d6 && (param_2[0xb] != 0x87da)) &&
            ((param_2[0xc] != 0x87d6 && (param_2[0xc] != 0x87da)))))) &&
          ((cVar2 == '\0' ||
           ((((param_2[10] != 0x87d6 && (param_2[10] != 0x87da)) && (param_2[0xc] != 0x87d6)) &&
            (param_2[0xc] != 0x87da)))))) &&
         ((cVar3 == '\0' ||
          (((param_2[10] != 0x87d6 && (param_2[10] != 0x87da)) &&
           ((param_2[0xb] != 0x87d6 && (param_2[0xb] != 0x87da)))))))) {
        bVar10 = false;
      }
      else {
        bVar10 = true;
      }
      if ((((cVar1 == '\0') ||
           (((param_2[0xb] != 0x87d7 && (param_2[0xb] != 0x87db)) &&
            ((param_2[0xc] != 0x87d7 && (param_2[0xc] != 0x87db)))))) &&
          ((cVar2 == '\0' ||
           ((((param_2[10] != 0x87d7 && (param_2[10] != 0x87db)) && (param_2[0xc] != 0x87d7)) &&
            (param_2[0xc] != 0x87db)))))) &&
         ((cVar3 == '\0' ||
          (((param_2[10] != 0x87d7 && (param_2[10] != 0x87db)) &&
           ((param_2[0xb] != 0x87d7 && (param_2[0xb] != 0x87db)))))))) {
        bVar11 = false;
      }
      else {
        bVar11 = true;
      }
      if ((((cVar1 == '\0') ||
           (((param_2[0xb] != 0x87d8 && (param_2[0xb] != 0x87dc)) &&
            ((param_2[0xc] != 0x87d8 && (param_2[0xc] != 0x87dc)))))) &&
          ((cVar2 == '\0' ||
           ((((param_2[10] != 0x87d8 && (param_2[10] != 0x87dc)) && (param_2[0xc] != 0x87d8)) &&
            (param_2[0xc] != 0x87dc)))))) &&
         ((cVar3 == '\0' ||
          (((param_2[10] != 0x87d8 && (param_2[10] != 0x87dc)) &&
           ((param_2[0xb] != 0x87d8 && (param_2[0xb] != 0x87dc)))))))) goto code_r0x000b5e3a;
      bVar13 = true;
    }
    else {
      bVar8 = false;
      bVar10 = false;
      bVar11 = false;
code_r0x000b5e3a:
      bVar13 = false;
    }
    if ((param_2[0xf] == 2) && (param_3 == param_2[0x10])) {
      if ((((cVar1 == '\0') ||
           ((((param_2[0x12] != 0x87d5 && (param_2[0x12] != 0x87d9)) && (param_2[0x13] != 0x87d5))
            && (param_2[0x13] != 0x87d9)))) &&
          ((cVar2 == '\0' ||
           (((param_2[0x11] != 0x87d5 && (param_2[0x11] != 0x87d9)) &&
            ((param_2[0x13] != 0x87d5 && (param_2[0x13] != 0x87d9)))))))) &&
         ((cVar3 == '\0' ||
          (((param_2[0x11] != 0x87d5 && (param_2[0x11] != 0x87d9)) &&
           ((param_2[0x12] != 0x87d5 && (param_2[0x12] != 0x87d9)))))))) {
        bVar9 = false;
      }
      else {
        bVar9 = true;
      }
      if ((((cVar1 == '\0') ||
           ((((param_2[0x12] != 0x87d6 && (param_2[0x12] != 0x87da)) && (param_2[0x13] != 0x87d6))
            && (param_2[0x13] != 0x87da)))) &&
          ((cVar2 == '\0' ||
           (((param_2[0x11] != 0x87d6 && (param_2[0x11] != 0x87da)) &&
            ((param_2[0x13] != 0x87d6 && (param_2[0x13] != 0x87da)))))))) &&
         ((cVar3 == '\0' ||
          (((param_2[0x11] != 0x87d6 && (param_2[0x11] != 0x87da)) &&
           ((param_2[0x12] != 0x87d6 && (param_2[0x12] != 0x87da)))))))) {
        bVar18 = false;
      }
      else {
        bVar18 = true;
      }
      if ((((cVar1 == '\0') ||
           ((((param_2[0x12] != 0x87d7 && (param_2[0x12] != 0x87db)) && (param_2[0x13] != 0x87d7))
            && (param_2[0x13] != 0x87db)))) &&
          ((cVar2 == '\0' ||
           (((param_2[0x11] != 0x87d7 && (param_2[0x11] != 0x87db)) &&
            ((param_2[0x13] != 0x87d7 && (param_2[0x13] != 0x87db)))))))) &&
         ((cVar3 == '\0' ||
          (((param_2[0x11] != 0x87d7 && (param_2[0x11] != 0x87db)) &&
           ((param_2[0x12] != 0x87d7 && (param_2[0x12] != 0x87db)))))))) {
        bVar12 = false;
      }
      else {
        bVar12 = true;
      }
      if (((cVar1 == '\0') ||
          ((((param_2[0x12] != 0x87d8 && (param_2[0x12] != 0x87dc)) && (param_2[0x13] != 0x87d8)) &&
           (param_2[0x13] != 0x87dc)))) &&
         (((cVar2 == '\0' ||
           (((param_2[0x11] != 0x87d8 && (param_2[0x11] != 0x87dc)) &&
            ((param_2[0x13] != 0x87d8 && (param_2[0x13] != 0x87dc)))))) &&
          ((cVar3 == '\0' ||
           (((param_2[0x11] != 0x87d8 && (param_2[0x11] != 0x87dc)) &&
            ((param_2[0x12] != 0x87d8 && (param_2[0x12] != 0x87dc)))))))))) goto code_r0x000b5e50;
      bVar14 = true;
    }
    else {
      bVar9 = false;
      bVar18 = false;
      bVar12 = false;
code_r0x000b5e50:
      bVar14 = false;
    }
    if ((bVar8) || (bVar9)) {
      uVar16 = 1;
    }
    else {
      uVar16 = 0;
    }
    *param_4 = uVar16;
    if ((bVar10) || (uVar16 = 0, bVar18)) {
      uVar16 = 1;
    }
    *param_5 = uVar16;
    if ((bVar11) || (bVar12)) {
      uVar16 = 1;
    }
    else {
      uVar16 = 0;
    }
    *param_6 = uVar16;
    break;
  case 0x8798:
    if (((param_2[0x11] == 0x87d5) ||
        (((((param_2[0x11] == 0x87d9 || (param_2[0x12] == 0x87d5)) || (param_2[0x12] == 0x87d9)) ||
          ((param_2[0x13] == 0x87d5 || (param_2[0x13] == 0x87d9)))) || (param_2[0x14] == 0x87d5))))
       || (param_2[0x14] == 0x87d9)) {
      uVar16 = 1;
    }
    else {
      uVar16 = 0;
    }
    *param_4 = uVar16;
    if ((((param_2[0x11] == 0x87d6) || (param_2[0x11] == 0x87da)) ||
        ((param_2[0x12] == 0x87d6 ||
         (((param_2[0x12] == 0x87da || (param_2[0x13] == 0x87d6)) || (param_2[0x13] == 0x87da))))))
       || ((param_2[0x14] == 0x87d6 || (param_2[0x14] == 0x87da)))) {
      uVar16 = 1;
    }
    else {
      uVar16 = 0;
    }
    *param_5 = uVar16;
    if ((((param_2[0x11] == 0x87d7) || (param_2[0x11] == 0x87db)) ||
        ((param_2[0x12] == 0x87d7 ||
         (((param_2[0x12] == 0x87db || (param_2[0x13] == 0x87d7)) || (param_2[0x13] == 0x87db))))))
       || ((param_2[0x14] == 0x87d7 || (param_2[0x14] == 0x87db)))) {
      uVar16 = 1;
    }
    else {
      uVar16 = 0;
    }
    *param_6 = uVar16;
    if (((param_2[0x11] == 0x87d8) || (param_2[0x11] == 0x87dc)) ||
       ((param_2[0x12] == 0x87d8 ||
        (((param_2[0x12] == 0x87dc || (param_2[0x13] == 0x87d8)) || (param_2[0x13] == 0x87dc))))))
    goto code_r0x000b596d;
    iVar17 = param_2[0x14];
    goto joined_r0x000b5b86;
  case 0x879a:
  case 0x879b:
    if (((((cVar1 == '\0') || ((param_2[10] != 0x87d5 && (param_2[10] != 0x87d9)))) &&
         ((cVar2 == '\0' || ((param_2[0xb] != 0x87d5 && (param_2[0xb] != 0x87d9)))))) &&
        ((cVar3 == '\0' || ((param_2[0xc] != 0x87d5 && (param_2[0xc] != 0x87d9)))))) &&
       ((cVar4 == '\0' || ((param_2[0xd] != 0x87d5 && (param_2[0xd] != 0x87d9)))))) {
      uVar16 = 0;
    }
    else {
      uVar16 = 1;
    }
    *param_4 = uVar16;
    if ((((cVar1 != '\0') && ((param_2[10] == 0x87d6 || (param_2[10] == 0x87da)))) ||
        ((cVar2 != '\0' && ((param_2[0xb] == 0x87d6 || (param_2[0xb] == 0x87da)))))) ||
       ((cVar3 != '\0' && ((param_2[0xc] == 0x87d6 || (param_2[0xc] == 0x87da))))))
    goto code_r0x000b60a1;
joined_r0x000b5d0d:
    if ((cVar4 != '\0') && ((param_2[0xd] == 0x87d6 || (param_2[0xd] == 0x87da))))
    goto code_r0x000b60a1;
    uVar16 = 0;
code_r0x000b5d15:
    *param_5 = uVar16;
    if ((((cVar1 == '\0') || ((param_2[10] != 0x87d7 && (param_2[10] != 0x87db)))) &&
        ((cVar2 == '\0' || ((param_2[0xb] != 0x87d7 && (param_2[0xb] != 0x87db)))))) &&
       (((cVar3 == '\0' || ((param_2[0xc] != 0x87d7 && (param_2[0xc] != 0x87db)))) &&
        ((cVar4 == '\0' || ((param_2[0xd] != 0x87d7 && (param_2[0xd] != 0x87db)))))))) {
      uVar16 = 0;
    }
    else {
      uVar16 = 1;
    }
    *param_6 = uVar16;
    if (((((cVar1 != '\0') && ((param_2[10] == 0x87d8 || (param_2[10] == 0x87dc)))) ||
         ((cVar2 != '\0' && ((param_2[0xb] == 0x87d8 || (param_2[0xb] == 0x87dc)))))) ||
        ((cVar3 != '\0' && ((param_2[0xc] == 0x87d8 || (param_2[0xc] == 0x87dc)))))) ||
       ((cVar4 != '\0' && ((param_2[0xd] == 0x87d8 || (param_2[0xd] == 0x87dc))))))
    goto code_r0x000b5681;
    goto code_r0x000b5a06;
  case 0x879d:
    iVar17 = FUN_00053994(param_1,param_2 + 8);
    if (iVar17 != 0x87bf) goto code_r0x000b559b;
    iVar17 = param_2[0x10];
    if (iVar17 == 0) {
      iVar17 = param_2[10];
      if (iVar17 != 0x87d5) goto code_r0x000b5ad5;
code_r0x000b613f:
      uVar16 = 1;
    }
    else if (iVar17 == 1) {
      iVar17 = param_2[0xb];
      if (iVar17 != 0x87d5) goto code_r0x000b5ad5;
      uVar16 = 1;
    }
    else {
      if (iVar17 == 2) {
        iVar17 = param_2[0xc];
        if (iVar17 == 0x87d5) goto code_r0x000b613f;
code_r0x000b5ad5:
        if (iVar17 == 0x87d9) goto code_r0x000b613f;
      }
      else if (iVar17 == 3) {
        iVar17 = param_2[0xd];
        if (iVar17 == 0x87d5) {
          uVar16 = 1;
          goto code_r0x000b5ae2;
        }
        goto code_r0x000b5ad5;
      }
      uVar16 = 0;
    }
code_r0x000b5ae2:
    *param_4 = uVar16;
    iVar17 = param_2[0x10];
    if (iVar17 == 0) {
      iVar17 = param_2[10];
      if (iVar17 == 0x87d6) {
        uVar16 = 1;
        goto code_r0x000b5b1f;
      }
code_r0x000b5b12:
      if (iVar17 == 0x87da) {
code_r0x000b60f4:
        uVar16 = 1;
      }
      else {
code_r0x000b5b1d:
        uVar16 = 0;
      }
    }
    else {
      if (iVar17 != 1) {
        if (iVar17 == 2) {
          iVar17 = param_2[0xc];
joined_r0x000b60ee:
          if (iVar17 != 0x87d6) goto code_r0x000b5b12;
          goto code_r0x000b60f4;
        }
        if (iVar17 == 3) {
          iVar17 = param_2[0xd];
          goto joined_r0x000b60ee;
        }
        goto code_r0x000b5b1d;
      }
      iVar17 = param_2[0xb];
      if (iVar17 != 0x87d6) goto code_r0x000b5b12;
      uVar16 = 1;
    }
code_r0x000b5b1f:
    *param_5 = uVar16;
    iVar17 = param_2[0x10];
    if (iVar17 == 0) {
      iVar17 = param_2[10];
      if (iVar17 == 0x87d7) {
        uVar16 = 1;
        goto code_r0x000b5b5c;
      }
code_r0x000b5b4f:
      if (iVar17 == 0x87db) {
code_r0x000b6115:
        uVar16 = 1;
      }
      else {
code_r0x000b5b5a:
        uVar16 = 0;
      }
    }
    else {
      if (iVar17 != 1) {
        if (iVar17 == 2) {
          iVar17 = param_2[0xc];
joined_r0x000b610f:
          if (iVar17 != 0x87d7) goto code_r0x000b5b4f;
          goto code_r0x000b6115;
        }
        if (iVar17 == 3) {
          iVar17 = param_2[0xd];
          goto joined_r0x000b610f;
        }
        goto code_r0x000b5b5a;
      }
      iVar17 = param_2[0xb];
      if (iVar17 != 0x87d7) goto code_r0x000b5b4f;
      uVar16 = 1;
    }
code_r0x000b5b5c:
    *param_6 = uVar16;
    iVar17 = param_2[0x10];
    if (iVar17 == 0) goto code_r0x000b5f13;
    if (iVar17 == 1) {
      iVar17 = param_2[0xb];
    }
    else {
      if (iVar17 != 2) {
        if (iVar17 != 3) goto code_r0x000b5835;
        goto code_r0x000b595a;
      }
      iVar17 = param_2[0xc];
    }
joined_r0x000b5b86:
    if (iVar17 != 0x87d8) {
code_r0x000b5828:
      if (iVar17 != 0x87dc) {
code_r0x000b5835:
        *param_7 = 0;
        return;
      }
    }
code_r0x000b596d:
    *param_7 = 1;
    return;
  case 0x879e:
    if (((((param_2[10] == 0x87d5) || (param_2[10] == 0x87d9)) || (param_2[0xb] == 0x87d5)) ||
        ((param_2[0xb] == 0x87d9 || (param_2[0xd] == 0x87d5)))) || (param_2[0xd] == 0x87d9)) {
      uVar16 = 1;
    }
    else {
      uVar16 = 0;
    }
    *param_4 = uVar16;
    if (((param_2[10] == 0x87d6) || (param_2[10] == 0x87da)) ||
       ((param_2[0xb] == 0x87d6 ||
        (((param_2[0xb] == 0x87da || (param_2[0xd] == 0x87d6)) || (param_2[0xd] == 0x87da)))))) {
      uVar16 = 1;
    }
    else {
      uVar16 = 0;
    }
    *param_5 = uVar16;
    if (((param_2[10] == 0x87d7) || (param_2[10] == 0x87db)) ||
       (((param_2[0xb] == 0x87d7 || ((param_2[0xb] == 0x87db || (param_2[0xd] == 0x87d7)))) ||
        (param_2[0xd] == 0x87db)))) {
      uVar16 = 1;
    }
    else {
      uVar16 = 0;
    }
    *param_6 = uVar16;
    if ((((param_2[10] == 0x87d8) || (param_2[10] == 0x87dc)) || (param_2[0xb] == 0x87d8)) ||
       (param_2[0xb] == 0x87dc)) goto code_r0x000b596d;
code_r0x000b595a:
    iVar17 = param_2[0xd];
    goto joined_r0x000b5f1b;
  case 0x879f:
    if ((param_2[8] == 2) && (param_3 == param_2[9])) {
      iVar17 = param_2[0xb];
      if ((((iVar17 == 0x87d5) || (iVar17 == 0x87d9)) || (param_2[0xc] == 0x87d5)) ||
         (param_2[0xc] == 0x87d9)) {
        bVar8 = true;
      }
      else {
        bVar8 = false;
      }
      if (((iVar17 == 0x87d6) || (iVar17 == 0x87da)) ||
         ((param_2[0xc] == 0x87d6 || (param_2[0xc] == 0x87da)))) {
        bVar10 = true;
      }
      else {
        bVar10 = false;
      }
      if (((iVar17 == 0x87d7) || (iVar17 == 0x87db)) ||
         ((param_2[0xc] == 0x87d7 || (param_2[0xc] == 0x87db)))) {
        bVar11 = true;
      }
      else {
        bVar11 = false;
      }
      if ((((iVar17 != 0x87d8) && (iVar17 != 0x87dc)) && (param_2[0xc] != 0x87d8)) &&
         (param_2[0xc] != 0x87dc)) goto code_r0x000b598d;
      bVar13 = true;
    }
    else {
      bVar8 = false;
      bVar10 = false;
      bVar11 = false;
code_r0x000b598d:
      bVar13 = false;
    }
    if ((param_2[0xf] == 2) && (param_2[0x10] == param_3)) {
      iVar17 = param_2[0x12];
      if (((iVar17 == 0x87d5) || (iVar17 == 0x87d9)) ||
         ((param_2[0x14] == 0x87d5 || (param_2[0x14] == 0x87d9)))) {
        bVar9 = true;
      }
      else {
        bVar9 = false;
      }
      if ((((iVar17 == 0x87d6) || (iVar17 == 0x87da)) || (param_2[0x14] == 0x87d6)) ||
         (param_2[0x14] == 0x87da)) {
        bVar18 = true;
      }
      else {
        bVar18 = false;
      }
      if (((iVar17 == 0x87d7) || (iVar17 == 0x87db)) ||
         ((param_2[0x14] == 0x87d7 || (param_2[0x14] == 0x87db)))) {
        bVar12 = true;
      }
      else {
        bVar12 = false;
      }
      if (((iVar17 != 0x87d8) && (iVar17 != 0x87dc)) &&
         ((param_2[0x14] != 0x87d8 && (param_2[0x14] != 0x87dc)))) goto code_r0x000b59a3;
      bVar14 = true;
    }
    else {
      bVar9 = false;
      bVar18 = false;
      bVar12 = false;
code_r0x000b59a3:
      bVar14 = false;
    }
    if ((bVar8) || (bVar9)) {
      uVar16 = 1;
    }
    else {
      uVar16 = 0;
    }
    *param_4 = uVar16;
    if ((bVar10) || (uVar16 = 0, bVar18)) {
      uVar16 = 1;
    }
    *param_5 = uVar16;
    if ((bVar11) || (bVar12)) {
      uVar16 = 1;
    }
    else {
      uVar16 = 0;
    }
    *param_6 = uVar16;
    break;
  case 0x87a0:
  case 0x87a1:
  case 0x87a2:
    if ((param_2[10] == 0x87d5) || (param_2[10] == 0x87d9)) {
      uVar16 = 1;
    }
    else {
      uVar16 = 0;
    }
    *param_4 = uVar16;
    if ((param_2[10] == 0x87d6) || (param_2[10] == 0x87da)) {
      uVar16 = 1;
    }
    else {
      uVar16 = 0;
    }
    *param_5 = uVar16;
    if ((param_2[10] == 0x87d7) || (param_2[10] == 0x87db)) {
      uVar16 = 1;
    }
    else {
      uVar16 = 0;
    }
    *param_6 = uVar16;
code_r0x000b5f13:
    iVar17 = param_2[10];
joined_r0x000b5f1b:
    if (iVar17 == 0x87d8) goto code_r0x000b596d;
    goto code_r0x000b5828;
  default:
    *param_4 = 0;
    *param_5 = 0;
    *param_6 = 0;
    *param_7 = 0;
    return;
  }
  if (!bVar13) {
code_r0x000b59fc:
    if (!bVar14) {
code_r0x000b5a06:
      *param_7 = 0;
      return;
    }
  }
code_r0x000b5681:
  *param_7 = 1;
  return;
}

/* FUN_000b7a8e @ 0xb7a8e (5682 bytes) */
int FUN_000b7a8e(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 *puVar1;
  int *piVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  bool bVar7;
  bool bVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  uint uVar14;
  int iVar15;
  int *piVar16;
  int iVar17;
  void *pvVar18;
  int iVar19;
  int iVar20;
  undefined4 *puVar21;
  int iVar22;
  uint local_d0;
  uint local_c8;
  uint local_a4;
  uint local_a0;
  byte local_94;
  byte local_93;
  byte local_92;
  byte local_91;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  uint local_68;
  uint local_58;
  uint local_50;
  uint local_4c;
  uint local_48;
  byte local_38;
  byte local_37;
  byte local_36;
  byte local_35;
  byte local_34;
  byte local_33;
  byte local_32;
  byte local_31;
  byte local_30;
  byte local_2f;
  byte local_2e;
  byte local_2d;
  char local_20;
  char local_1f;
  char local_1e;
  char local_1d [13];
  
  iVar9 = param_2 + 0x1c;
  iVar22 = *(int *)(param_2 + 0x14);
  if (iVar22 != 0) {
    local_6c = iVar22 * 0x74;
    local_70 = 0;
    do {
      uVar14 = iVar22 - local_70;
      iVar20 = *(int *)(param_2 + 0x18);
      iVar17 = local_6c + iVar20;
      cVar3 = *(char *)(iVar17 + -0x68);
      cVar4 = *(char *)(iVar17 + -100);
      cVar5 = *(char *)(iVar17 + -0x60);
      cVar6 = *(char *)(iVar17 + -0x5c);
      if ((((cVar3 == '\0') && (cVar4 == '\0')) && (cVar5 == '\0')) && (cVar6 == '\0')) {
LAB_000b7e56:
        uVar11 = *(uint *)(param_2 + 0x14);
joined_r0x000b7e6b:
        iVar20 = local_6c;
        if (uVar14 < uVar11) {
          do {
            pvVar18 = (void *)(iVar20 + *(int *)(param_2 + 0x18));
            _memcpy((void *)((int)pvVar18 + -0x74),pvVar18,0x74);
            uVar14 = uVar14 + 1;
            uVar11 = *(uint *)(param_2 + 0x14);
            iVar20 = iVar20 + 0x74;
          } while (uVar14 < uVar11);
        }
        *(uint *)(param_2 + 0x14) = uVar11 - 1;
      }
      else {
        iVar19 = *(int *)(iVar17 + -0x70);
        if (iVar19 == 1) {
          uVar11 = *(uint *)(param_2 + 0x14);
          if (uVar14 < uVar11) {
            local_37 = 0;
            local_34 = 0;
            local_31 = 0;
            local_2e = 0;
            iVar19 = 0;
            iVar20 = iVar17;
            do {
              if ((*(int *)(iVar20 + 4) == 1) && (*(int *)(iVar20 + 8) == *(int *)(iVar17 + -0x6c)))
              {
                local_37 = local_37 | *(byte *)(iVar20 + 0xc);
                local_34 = local_34 | *(byte *)(iVar20 + 0x10);
                local_31 = local_31 | *(byte *)(iVar20 + 0x14);
                local_2e = local_2e | *(byte *)(iVar20 + 0x18);
              }
              iVar19 = iVar19 + 1;
              iVar20 = iVar20 + 0x74;
            } while (iVar19 != uVar11 - uVar14);
          }
          else {
            local_37 = 0;
            local_34 = 0;
            local_31 = 0;
            local_2e = 0;
          }
          if ((((cVar3 == '\0') || (local_37 != 0)) && ((cVar4 == '\0' || (local_34 != 0)))) &&
             (((cVar5 == '\0' || (local_31 != 0)) && ((cVar6 == '\0' || (local_2e != 0))))))
          goto joined_r0x000b7e6b;
        }
        else {
          if (*(int *)(iVar17 + -0x74) == 0x87a2) {
            uVar11 = *(uint *)(param_2 + 0x14);
            if (uVar14 < uVar11) {
              bVar7 = true;
              local_38 = 0;
              local_35 = 0;
              local_32 = 0;
              local_2f = 0;
              iVar19 = 0;
              iVar20 = iVar17;
              do {
                if (((*(char *)(iVar20 + 0x38) == '\0') && (*(char *)(iVar20 + 0x54) == '\0')) &&
                   (*(char *)(iVar20 + 0x70) == '\0')) {
                  iVar15 = *(int *)(iVar20 + 4);
                }
                else {
                  bVar7 = false;
                  iVar15 = *(int *)(iVar20 + 4);
                }
                if ((iVar15 == 2) && (*(int *)(iVar20 + 8) == *(int *)(iVar17 + -0x6c))) {
                  local_38 = local_38 | *(byte *)(iVar20 + 0xc);
                  local_35 = local_35 | *(byte *)(iVar20 + 0x10);
                  local_32 = local_32 | *(byte *)(iVar20 + 0x14);
                  local_2f = local_2f | *(byte *)(iVar20 + 0x18);
                }
                iVar19 = iVar19 + 1;
                iVar20 = iVar20 + 0x74;
              } while (iVar19 != uVar11 - uVar14);
            }
            else {
              bVar7 = true;
              local_38 = 0;
              local_35 = 0;
              local_32 = 0;
              local_2f = 0;
            }
            if (((((cVar3 == '\0') || (local_38 != 0)) && ((cVar4 == '\0' || (local_35 != 0)))) &&
                ((((cVar5 == '\0' || (local_32 != 0)) && ((cVar6 == '\0' || (local_2f != 0)))) &&
                 (bVar7)))) || (uVar11 <= uVar14)) goto joined_r0x000b7e6b;
            bVar7 = true;
            iVar20 = 0;
            do {
              if (((*(char *)(iVar17 + 0x38) != '\0') || (*(char *)(iVar17 + 0x54) != '\0')) ||
                 (*(char *)(iVar17 + 0x70) != '\0')) {
                bVar7 = false;
              }
              iVar20 = iVar20 + 1;
              iVar17 = iVar17 + 0x74;
            } while (iVar20 != uVar11 - uVar14);
          }
          else {
            if (*(char *)(param_2 + 0x7b) == '\0') {
              if (iVar19 == 2) {
                iVar19 = *(int *)(iVar17 + -0x6c);
                iVar15 = *(int *)(param_2 + 0x20);
                goto LAB_000b7f57;
              }
LAB_000b7b6d:
              uVar11 = *(uint *)(param_2 + 0x14);
            }
            else {
              if (iVar19 != 2) goto LAB_000b7b6d;
              iVar19 = *(int *)(iVar17 + -0x6c);
              iVar15 = *(int *)(param_2 + 0x20);
              if (*(int *)(iVar15 + 0x28 + iVar19 * 0x54) == 0x87c4) goto LAB_000b7d4b;
LAB_000b7f57:
              if (*(int *)(iVar15 + 0x24 + iVar19 * 0x54) == 0x87c0) goto LAB_000b7d4b;
              uVar11 = *(uint *)(param_2 + 0x14);
            }
            if (uVar14 < uVar11) {
              local_74 = local_6c;
              local_2d = 0;
              local_30 = 0;
              local_33 = 0;
              local_36 = 0;
              bVar7 = true;
              local_a4 = uVar14;
              do {
                iVar20 = iVar20 + local_74;
                if ((*(int *)(iVar20 + 0x20) == 2) &&
                   (*(int *)(iVar20 + 0x24) == *(int *)(iVar17 + -0x6c))) {
LAB_000b7ff1:
                  ((int (*)())FUN_000b5478)(iVar9,iVar20,*(undefined4 *)(iVar17 + -0x6c),local_1d,&local_1e,
                               &local_1f,&local_20);
                  if ((((cVar3 == '\0') || ((local_1d[0] == '\0' || (local_36 != 0)))) &&
                      ((cVar4 == '\0' || ((local_1e == '\0' || (local_33 != 0)))))) &&
                     (((cVar5 == '\0' || ((local_1f == '\0' || (local_30 != 0)))) &&
                      ((cVar6 == '\0' || ((local_20 == '\0' || (local_2d != 0))))))))
                  goto LAB_000b7fb3;
                  bVar7 = false;
                  iVar19 = *(int *)(iVar20 + 4);
                }
                else {
                  if (*(int *)(iVar20 + 0x3c) == 2) {
                    if (*(int *)(iVar20 + 0x40) == *(int *)(iVar17 + -0x6c)) goto LAB_000b7ff1;
                    iVar19 = *(int *)(iVar20 + 0x58);
                  }
                  else {
                    iVar19 = *(int *)(iVar20 + 0x58);
                  }
                  if ((iVar19 == 2) && (*(int *)(iVar20 + 0x5c) == *(int *)(iVar17 + -0x6c)))
                  goto LAB_000b7ff1;
LAB_000b7fb3:
                  iVar19 = *(int *)(iVar20 + 4);
                }
                if ((iVar19 == 2) && (*(int *)(iVar20 + 8) == *(int *)(iVar17 + -0x6c))) {
                  local_36 = local_36 | *(byte *)(iVar20 + 0xc);
                  local_33 = local_33 | *(byte *)(iVar20 + 0x10);
                  local_30 = local_30 | *(byte *)(iVar20 + 0x14);
                  local_2d = local_2d | *(byte *)(iVar20 + 0x18);
                }
                local_a4 = local_a4 + 1;
                local_74 = local_74 + 0x74;
                if (*(uint *)(param_2 + 0x14) <= local_a4) goto LAB_000b7b90;
                iVar20 = *(int *)(param_2 + 0x18);
              } while( true );
            }
            bVar7 = true;
            local_36 = 0;
            local_33 = 0;
            local_30 = 0;
            local_2d = 0;
LAB_000b7b90:
            if ((((((cVar3 == '\0') || (local_36 != 0)) && ((cVar4 == '\0' || (local_33 != 0)))) &&
                 ((cVar5 == '\0' || (local_30 != 0)))) && ((cVar6 == '\0' || (local_2d != 0)))) &&
               (bVar7)) goto LAB_000b7e56;
            if (*(uint *)(param_2 + 0x14) <= uVar14) {
              uVar11 = *(uint *)(param_2 + 0x14);
              goto joined_r0x000b7e6b;
            }
            local_78 = local_6c;
            bVar7 = true;
            local_94 = 0;
            local_93 = 0;
            local_92 = 0;
            local_91 = 0;
            local_50 = uVar14;
LAB_000b7c19:
            do {
              iVar20 = local_78 + *(int *)(param_2 + 0x18);
              if ((*(int *)(iVar20 + 0x20) == 2) &&
                 (*(int *)(iVar20 + 0x24) == *(int *)(iVar17 + -0x6c))) {
LAB_000b7c30:
                ((int (*)())FUN_000b5478)(iVar9,iVar20,*(undefined4 *)(iVar17 + -0x6c),local_1d,&local_1e,
                             &local_1f,&local_20);
                if ((((cVar3 == '\0') || ((local_1d[0] == '\0' || (local_94 != 0)))) &&
                    ((cVar4 == '\0' || ((local_1e == '\0' || (local_93 != 0)))))) &&
                   (((cVar5 == '\0' || ((local_1f == '\0' || (local_92 != 0)))) &&
                    ((cVar6 == '\0' || ((local_20 == '\0' || (local_91 != 0))))))))
                goto LAB_000b7bf8;
                bVar7 = false;
                iVar19 = *(int *)(iVar20 + 4);
              }
              else {
                if (*(int *)(iVar20 + 0x3c) == 2) {
                  if (*(int *)(iVar20 + 0x40) == *(int *)(iVar17 + -0x6c)) goto LAB_000b7c30;
                  iVar19 = *(int *)(iVar20 + 0x58);
                }
                else {
                  iVar19 = *(int *)(iVar20 + 0x58);
                }
                if ((iVar19 == 2) && (*(int *)(iVar20 + 0x5c) == *(int *)(iVar17 + -0x6c)))
                goto LAB_000b7c30;
LAB_000b7bf8:
                iVar19 = *(int *)(iVar20 + 4);
              }
              if ((iVar19 == 2) && (*(int *)(iVar20 + 8) == *(int *)(iVar17 + -0x6c))) {
                local_94 = local_94 | *(byte *)(iVar20 + 0xc);
                local_93 = local_93 | *(byte *)(iVar20 + 0x10);
                local_92 = local_92 | *(byte *)(iVar20 + 0x14);
                local_91 = local_91 | *(byte *)(iVar20 + 0x18);
                local_50 = local_50 + 1;
                local_78 = local_78 + 0x74;
                if (*(uint *)(param_2 + 0x14) <= local_50) break;
                goto LAB_000b7c19;
              }
              local_50 = local_50 + 1;
              local_78 = local_78 + 0x74;
            } while (local_50 < *(uint *)(param_2 + 0x14));
          }
          if (bVar7) {
            uVar11 = *(uint *)(param_2 + 0x14);
            goto joined_r0x000b7e6b;
          }
        }
      }
LAB_000b7d4b:
      local_70 = local_70 + 1;
      local_6c = local_6c + -0x74;
    } while (iVar22 != local_70);
  }
  if (*(int *)(param_2 + 0x14) != 0) {
    local_58 = 0;
    local_d0 = *(uint *)(param_2 + 0x14);
    do {
      while( true ) {
        iVar22 = *(int *)(param_2 + 0x18);
        puVar21 = (undefined4 *)(local_58 * 0x74 + iVar22);
        if ((undefined *)*puVar21 == ((unsigned char *)0x00008786)) break;
LAB_000b7d88:
        local_58 = local_58 + 1;
        if (*(uint *)(param_2 + 0x14) <= local_58) goto LAB_000b7dd6;
      }
      if ((((puVar21[1] == 2) && (puVar21[3] != 0)) && (puVar21[4] != 0)) &&
         ((puVar21[5] != 0 && (puVar21[6] != 0)))) {
        uVar14 = local_58 + 1;
        local_4c = uVar14;
        if (uVar14 < local_d0) {
          do {
            local_80 = local_4c * 0x74;
            puVar12 = (undefined4 *)(local_80 + iVar22);
            if ((undefined *)*puVar12 == ((unsigned char *)0x00008787)) {
              iVar20 = puVar12[8];
              if ((iVar20 == 2) && (puVar12[9] == puVar21[2])) {
LAB_000b878c:
                if ((puVar12[0xf] != 2) || (puVar12[9] != puVar12[0x10])) {
LAB_000b86f8:
                  if (local_4c <= uVar14) {
LAB_000b8708:
                    bVar7 = true;
                    uVar11 = local_4c + 1;
                    if (uVar11 < local_d0) {
                      iVar17 = iVar22 + uVar11 * 0x74;
                      iVar19 = 0;
                      do {
                        if ((*(int *)(iVar17 + 0x20) == 2) &&
                           (*(int *)(iVar17 + 0x24) == puVar21[2])) {
LAB_000b8777:
                          bVar7 = false;
                        }
                        else if ((*(int *)(iVar17 + 0x3c) == 2) &&
                                (*(int *)(iVar17 + 0x40) == puVar21[2])) {
                          bVar7 = false;
                        }
                        else if ((*(int *)(iVar17 + 0x58) == 2) &&
                                (*(int *)(iVar17 + 0x5c) == puVar21[2])) goto LAB_000b8777;
                        iVar19 = iVar19 + 1;
                        iVar17 = iVar17 + 0x74;
                      } while (iVar19 != local_d0 - uVar11);
                      if (!bVar7) {
                        if (uVar14 < local_4c) goto LAB_000b8869;
                        bVar7 = true;
                        goto LAB_000b87e6;
                      }
                    }
                    *puVar12 = &switchdataD_00008788;
                    if (puVar12[9] == puVar21[2]) {
                      puVar12[0x16] = puVar12[0xf];
                      puVar12[0x17] = puVar12[0x10];
                      puVar12[0x18] = puVar12[0x11];
                      puVar12[0x19] = puVar12[0x12];
                      puVar12[0x1a] = puVar12[0x13];
                      puVar12[0x1b] = puVar12[0x14];
                      puVar12[0x1c] = puVar12[0x15];
                      uVar10 = puVar12[10];
                    }
                    else {
                      puVar12[0x16] = iVar20;
                      puVar12[0x17] = puVar12[9];
                      puVar12[0x18] = puVar12[10];
                      puVar12[0x19] = puVar12[0xb];
                      puVar12[0x1a] = puVar12[0xc];
                      puVar12[0x1b] = puVar12[0xd];
                      puVar12[0x1c] = puVar12[0xe];
                      uVar10 = puVar12[0x11];
                      puVar12[10] = uVar10;
                      puVar12[0xb] = puVar12[0x12];
                      puVar12[0xc] = puVar12[0x13];
                      puVar12[0xd] = puVar12[0x14];
                    }
                    puVar13 = puVar12 + 0x11;
                    switch(uVar10) {
                    case 0x87d9:
                      uVar10 = 0x87d5;
                      break;
                    case 0x87da:
                      uVar10 = 0x87d6;
                      break;
                    case 0x87db:
                      uVar10 = 0x87d7;
                      break;
                    case 0x87dc:
                      uVar10 = 0x87d8;
                      break;
                    case 0x87df:
                      uVar10 = 0x87de;
                    }
                    *puVar13 = uVar10;
                    uVar10 = puVar12[0xb];
                    switch(uVar10) {
                    case 0x87d9:
                      uVar10 = 0x87d5;
                      break;
                    case 0x87da:
                      uVar10 = 0x87d6;
                      break;
                    case 0x87db:
                      uVar10 = 0x87d7;
                      break;
                    case 0x87dc:
                      uVar10 = 0x87d8;
                      break;
                    case 0x87df:
                      uVar10 = 0x87de;
                    }
                    puVar12[0x12] = uVar10;
                    uVar10 = puVar12[0xc];
                    switch(uVar10) {
                    case 0x87d9:
                      uVar10 = 0x87d5;
                      break;
                    case 0x87da:
                      uVar10 = 0x87d6;
                      break;
                    case 0x87db:
                      uVar10 = 0x87d7;
                      break;
                    case 0x87dc:
                      uVar10 = 0x87d8;
                      break;
                    case 0x87df:
                      uVar10 = 0x87de;
                    }
                    puVar12[0x13] = uVar10;
                    uVar10 = puVar12[0xd];
                    switch(uVar10) {
                    case 0x87d9:
                      uVar10 = 0x87d5;
                      break;
                    case 0x87da:
                      uVar10 = 0x87d6;
                      break;
                    case 0x87db:
                      uVar10 = 0x87d7;
                      break;
                    case 0x87dc:
                      uVar10 = 0x87d8;
                      break;
                    case 0x87df:
                      uVar10 = 0x87de;
                    }
                    puVar12[0x14] = uVar10;
                    puVar12[9] = puVar21[9];
                    puVar1 = puVar21 + 10;
                    uVar10 = puVar12[10];
                    switch(uVar10) {
                    case 0x87d5:
                      uVar10 = *puVar1;
                      break;
                    case 0x87d6:
                      uVar10 = puVar21[0xb];
                      break;
                    case 0x87d7:
                      uVar10 = puVar21[0xc];
                      break;
                    case 0x87d8:
                      uVar10 = puVar21[0xd];
                      break;
                    case 0x87d9:
                      uVar10 = *puVar1;
                      switch(uVar10) {
                      case 0x87d5:
code_r0x000ba664:
                        uVar10 = 0x87d9;
                        break;
                      case 0x87d6:
code_r0x000ba66e:
                        uVar10 = 0x87da;
                        break;
                      case 0x87d7:
code_r0x000b8ca8:
                        uVar10 = 0x87db;
                        break;
                      case 0x87d8:
code_r0x000ba678:
                        uVar10 = 0x87dc;
                        break;
                      case 0x87d9:
code_r0x000ba682:
                        uVar10 = 0x87d5;
                        break;
                      case 0x87da:
code_r0x000ba68c:
                        uVar10 = 0x87d6;
                        break;
                      case 0x87db:
code_r0x000ba696:
                        uVar10 = 0x87d7;
                        break;
                      case 0x87dc:
code_r0x000ba6a0:
                        uVar10 = 0x87d8;
                        break;
                      case 0x87de:
code_r0x000ba6aa:
                        uVar10 = 0x87df;
                        break;
                      case 0x87df:
code_r0x000ba6b4:
                        uVar10 = 0x87de;
                      }
                      break;
                    case 0x87da:
                      uVar10 = puVar21[0xb];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000ba664;
                      case 0x87d6:
                        goto code_r0x000ba66e;
                      case 0x87d7:
                        goto code_r0x000b8ca8;
                      case 0x87d8:
                        goto code_r0x000ba678;
                      case 0x87d9:
                        goto code_r0x000ba682;
                      case 0x87da:
                        goto code_r0x000ba68c;
                      case 0x87db:
                        goto code_r0x000ba696;
                      case 0x87dc:
                        goto code_r0x000ba6a0;
                      case 0x87de:
                        goto code_r0x000ba6aa;
                      case 0x87df:
                        goto code_r0x000ba6b4;
                      }
                      break;
                    case 0x87db:
                      uVar10 = puVar21[0xc];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000ba664;
                      case 0x87d6:
                        goto code_r0x000ba66e;
                      case 0x87d7:
                        goto code_r0x000b8ca8;
                      case 0x87d8:
                        goto code_r0x000ba678;
                      case 0x87d9:
                        goto code_r0x000ba682;
                      case 0x87da:
                        goto code_r0x000ba68c;
                      case 0x87db:
                        goto code_r0x000ba696;
                      case 0x87dc:
                        goto code_r0x000ba6a0;
                      case 0x87de:
                        goto code_r0x000ba6aa;
                      case 0x87df:
                        goto code_r0x000ba6b4;
                      }
                      break;
                    case 0x87dc:
                      uVar10 = puVar21[0xd];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000ba664;
                      case 0x87d6:
                        goto code_r0x000ba66e;
                      case 0x87d7:
                        goto code_r0x000b8ca8;
                      case 0x87d8:
                        goto code_r0x000ba678;
                      case 0x87d9:
                        goto code_r0x000ba682;
                      case 0x87da:
                        goto code_r0x000ba68c;
                      case 0x87db:
                        goto code_r0x000ba696;
                      case 0x87dc:
                        goto code_r0x000ba6a0;
                      case 0x87de:
                        goto code_r0x000ba6aa;
                      case 0x87df:
                        goto code_r0x000ba6b4;
                      }
                    }
                    puVar12[10] = uVar10;
                    uVar10 = puVar12[0xb];
                    switch(uVar10) {
                    case 0x87d5:
                      uVar10 = *puVar1;
                      break;
                    case 0x87d6:
                      uVar10 = puVar21[0xb];
                      break;
                    case 0x87d7:
                      uVar10 = puVar21[0xc];
                      break;
                    case 0x87d8:
                      uVar10 = puVar21[0xd];
                      break;
                    case 0x87d9:
                      uVar10 = *puVar1;
                      switch(uVar10) {
                      case 0x87d5:
code_r0x000ba808:
                        uVar10 = 0x87d9;
                        break;
                      case 0x87d6:
code_r0x000ba812:
                        uVar10 = 0x87da;
                        break;
                      case 0x87d7:
code_r0x000b8ce8:
                        uVar10 = 0x87db;
                        break;
                      case 0x87d8:
code_r0x000ba81c:
                        uVar10 = 0x87dc;
                        break;
                      case 0x87d9:
code_r0x000ba826:
                        uVar10 = 0x87d5;
                        break;
                      case 0x87da:
code_r0x000ba830:
                        uVar10 = 0x87d6;
                        break;
                      case 0x87db:
code_r0x000ba83a:
                        uVar10 = 0x87d7;
                        break;
                      case 0x87dc:
code_r0x000ba844:
                        uVar10 = 0x87d8;
                        break;
                      case 0x87de:
code_r0x000ba84e:
                        uVar10 = 0x87df;
                        break;
                      case 0x87df:
code_r0x000ba858:
                        uVar10 = 0x87de;
                      }
                      break;
                    case 0x87da:
                      uVar10 = puVar21[0xb];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000ba808;
                      case 0x87d6:
                        goto code_r0x000ba812;
                      case 0x87d7:
                        goto code_r0x000b8ce8;
                      case 0x87d8:
                        goto code_r0x000ba81c;
                      case 0x87d9:
                        goto code_r0x000ba826;
                      case 0x87da:
                        goto code_r0x000ba830;
                      case 0x87db:
                        goto code_r0x000ba83a;
                      case 0x87dc:
                        goto code_r0x000ba844;
                      case 0x87de:
                        goto code_r0x000ba84e;
                      case 0x87df:
                        goto code_r0x000ba858;
                      }
                      break;
                    case 0x87db:
                      uVar10 = puVar21[0xc];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000ba808;
                      case 0x87d6:
                        goto code_r0x000ba812;
                      case 0x87d7:
                        goto code_r0x000b8ce8;
                      case 0x87d8:
                        goto code_r0x000ba81c;
                      case 0x87d9:
                        goto code_r0x000ba826;
                      case 0x87da:
                        goto code_r0x000ba830;
                      case 0x87db:
                        goto code_r0x000ba83a;
                      case 0x87dc:
                        goto code_r0x000ba844;
                      case 0x87de:
                        goto code_r0x000ba84e;
                      case 0x87df:
                        goto code_r0x000ba858;
                      }
                      break;
                    case 0x87dc:
                      uVar10 = puVar21[0xd];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000ba808;
                      case 0x87d6:
                        goto code_r0x000ba812;
                      case 0x87d7:
                        goto code_r0x000b8ce8;
                      case 0x87d8:
                        goto code_r0x000ba81c;
                      case 0x87d9:
                        goto code_r0x000ba826;
                      case 0x87da:
                        goto code_r0x000ba830;
                      case 0x87db:
                        goto code_r0x000ba83a;
                      case 0x87dc:
                        goto code_r0x000ba844;
                      case 0x87de:
                        goto code_r0x000ba84e;
                      case 0x87df:
                        goto code_r0x000ba858;
                      }
                    }
                    puVar12[0xb] = uVar10;
                    uVar10 = puVar12[0xc];
                    switch(uVar10) {
                    case 0x87d5:
                      uVar10 = *puVar1;
                      break;
                    case 0x87d6:
                      uVar10 = puVar21[0xb];
                      break;
                    case 0x87d7:
                      uVar10 = puVar21[0xc];
                      break;
                    case 0x87d8:
                      uVar10 = puVar21[0xd];
                      break;
                    case 0x87d9:
                      uVar10 = *puVar1;
                      switch(uVar10) {
                      case 0x87d5:
code_r0x000ba9ac:
                        uVar10 = 0x87d9;
                        break;
                      case 0x87d6:
code_r0x000ba9b6:
                        uVar10 = 0x87da;
                        break;
                      case 0x87d7:
code_r0x000b8d2c:
                        uVar10 = 0x87db;
                        break;
                      case 0x87d8:
code_r0x000ba9c0:
                        uVar10 = 0x87dc;
                        break;
                      case 0x87d9:
code_r0x000ba9ca:
                        uVar10 = 0x87d5;
                        break;
                      case 0x87da:
code_r0x000ba9d4:
                        uVar10 = 0x87d6;
                        break;
                      case 0x87db:
code_r0x000ba9de:
                        uVar10 = 0x87d7;
                        break;
                      case 0x87dc:
code_r0x000ba9e8:
                        uVar10 = 0x87d8;
                        break;
                      case 0x87de:
code_r0x000ba9f2:
                        uVar10 = 0x87df;
                        break;
                      case 0x87df:
code_r0x000ba9fc:
                        uVar10 = 0x87de;
                      }
                      break;
                    case 0x87da:
                      uVar10 = puVar21[0xb];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000ba9ac;
                      case 0x87d6:
                        goto code_r0x000ba9b6;
                      case 0x87d7:
                        goto code_r0x000b8d2c;
                      case 0x87d8:
                        goto code_r0x000ba9c0;
                      case 0x87d9:
                        goto code_r0x000ba9ca;
                      case 0x87da:
                        goto code_r0x000ba9d4;
                      case 0x87db:
                        goto code_r0x000ba9de;
                      case 0x87dc:
                        goto code_r0x000ba9e8;
                      case 0x87de:
                        goto code_r0x000ba9f2;
                      case 0x87df:
                        goto code_r0x000ba9fc;
                      }
                      break;
                    case 0x87db:
                      uVar10 = puVar21[0xc];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000ba9ac;
                      case 0x87d6:
                        goto code_r0x000ba9b6;
                      case 0x87d7:
                        goto code_r0x000b8d2c;
                      case 0x87d8:
                        goto code_r0x000ba9c0;
                      case 0x87d9:
                        goto code_r0x000ba9ca;
                      case 0x87da:
                        goto code_r0x000ba9d4;
                      case 0x87db:
                        goto code_r0x000ba9de;
                      case 0x87dc:
                        goto code_r0x000ba9e8;
                      case 0x87de:
                        goto code_r0x000ba9f2;
                      case 0x87df:
                        goto code_r0x000ba9fc;
                      }
                      break;
                    case 0x87dc:
                      uVar10 = puVar21[0xd];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000ba9ac;
                      case 0x87d6:
                        goto code_r0x000ba9b6;
                      case 0x87d7:
                        goto code_r0x000b8d2c;
                      case 0x87d8:
                        goto code_r0x000ba9c0;
                      case 0x87d9:
                        goto code_r0x000ba9ca;
                      case 0x87da:
                        goto code_r0x000ba9d4;
                      case 0x87db:
                        goto code_r0x000ba9de;
                      case 0x87dc:
                        goto code_r0x000ba9e8;
                      case 0x87de:
                        goto code_r0x000ba9f2;
                      case 0x87df:
                        goto code_r0x000ba9fc;
                      }
                    }
                    puVar12[0xc] = uVar10;
                    uVar10 = puVar12[0xd];
                    switch(uVar10) {
                    case 0x87d5:
                      uVar10 = *puVar1;
                      break;
                    case 0x87d6:
                      uVar10 = puVar21[0xb];
                      break;
                    case 0x87d7:
                      uVar10 = puVar21[0xc];
                      break;
                    case 0x87d8:
                      uVar10 = puVar21[0xd];
                      break;
                    case 0x87d9:
                      uVar10 = *puVar1;
                      switch(uVar10) {
                      case 0x87d5:
code_r0x000bab50:
                        uVar10 = 0x87d9;
                        break;
                      case 0x87d6:
code_r0x000bab5a:
                        uVar10 = 0x87da;
                        break;
                      case 0x87d7:
code_r0x000b8d70:
                        uVar10 = 0x87db;
                        break;
                      case 0x87d8:
code_r0x000bab64:
                        uVar10 = 0x87dc;
                        break;
                      case 0x87d9:
code_r0x000bab6e:
                        uVar10 = 0x87d5;
                        break;
                      case 0x87da:
code_r0x000bab78:
                        uVar10 = 0x87d6;
                        break;
                      case 0x87db:
code_r0x000bab82:
                        uVar10 = 0x87d7;
                        break;
                      case 0x87dc:
code_r0x000bab8c:
                        uVar10 = 0x87d8;
                        break;
                      case 0x87de:
code_r0x000bab96:
                        uVar10 = 0x87df;
                        break;
                      case 0x87df:
code_r0x000baba0:
                        uVar10 = 0x87de;
                      }
                      break;
                    case 0x87da:
                      uVar10 = puVar21[0xb];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000bab50;
                      case 0x87d6:
                        goto code_r0x000bab5a;
                      case 0x87d7:
                        goto code_r0x000b8d70;
                      case 0x87d8:
                        goto code_r0x000bab64;
                      case 0x87d9:
                        goto code_r0x000bab6e;
                      case 0x87da:
                        goto code_r0x000bab78;
                      case 0x87db:
                        goto code_r0x000bab82;
                      case 0x87dc:
                        goto code_r0x000bab8c;
                      case 0x87de:
                        goto code_r0x000bab96;
                      case 0x87df:
                        goto code_r0x000baba0;
                      }
                      break;
                    case 0x87db:
                      uVar10 = puVar21[0xc];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000bab50;
                      case 0x87d6:
                        goto code_r0x000bab5a;
                      case 0x87d7:
                        goto code_r0x000b8d70;
                      case 0x87d8:
                        goto code_r0x000bab64;
                      case 0x87d9:
                        goto code_r0x000bab6e;
                      case 0x87da:
                        goto code_r0x000bab78;
                      case 0x87db:
                        goto code_r0x000bab82;
                      case 0x87dc:
                        goto code_r0x000bab8c;
                      case 0x87de:
                        goto code_r0x000bab96;
                      case 0x87df:
                        goto code_r0x000baba0;
                      }
                      break;
                    case 0x87dc:
                      uVar10 = puVar21[0xd];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000bab50;
                      case 0x87d6:
                        goto code_r0x000bab5a;
                      case 0x87d7:
                        goto code_r0x000b8d70;
                      case 0x87d8:
                        goto code_r0x000bab64;
                      case 0x87d9:
                        goto code_r0x000bab6e;
                      case 0x87da:
                        goto code_r0x000bab78;
                      case 0x87db:
                        goto code_r0x000bab82;
                      case 0x87dc:
                        goto code_r0x000bab8c;
                      case 0x87de:
                        goto code_r0x000bab96;
                      case 0x87df:
                        goto code_r0x000baba0;
                      }
                    }
                    puVar12[0xd] = uVar10;
                    puVar12[0x10] = puVar21[0x10];
                    puVar1 = puVar21 + 0x11;
                    uVar10 = *puVar13;
                    switch(uVar10) {
                    case 0x87d5:
                      uVar10 = *puVar1;
                      break;
                    case 0x87d6:
                      uVar10 = puVar21[0x12];
                      break;
                    case 0x87d7:
                      uVar10 = puVar21[0x13];
                      break;
                    case 0x87d8:
                      uVar10 = puVar21[0x14];
                      break;
                    case 0x87d9:
                      uVar10 = *puVar1;
                      switch(uVar10) {
                      case 0x87d5:
code_r0x000bacf4:
                        uVar10 = 0x87d9;
                        break;
                      case 0x87d6:
code_r0x000bacfe:
                        uVar10 = 0x87da;
                        break;
                      case 0x87d7:
code_r0x000b8dc4:
                        uVar10 = 0x87db;
                        break;
                      case 0x87d8:
code_r0x000bad08:
                        uVar10 = 0x87dc;
                        break;
                      case 0x87d9:
code_r0x000bad12:
                        uVar10 = 0x87d5;
                        break;
                      case 0x87da:
code_r0x000bad1c:
                        uVar10 = 0x87d6;
                        break;
                      case 0x87db:
code_r0x000bad26:
                        uVar10 = 0x87d7;
                        break;
                      case 0x87dc:
code_r0x000bad30:
                        uVar10 = 0x87d8;
                        break;
                      case 0x87de:
code_r0x000bad3a:
                        uVar10 = 0x87df;
                        break;
                      case 0x87df:
code_r0x000bad44:
                        uVar10 = 0x87de;
                      }
                      break;
                    case 0x87da:
                      uVar10 = puVar21[0x12];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000bacf4;
                      case 0x87d6:
                        goto code_r0x000bacfe;
                      case 0x87d7:
                        goto code_r0x000b8dc4;
                      case 0x87d8:
                        goto code_r0x000bad08;
                      case 0x87d9:
                        goto code_r0x000bad12;
                      case 0x87da:
                        goto code_r0x000bad1c;
                      case 0x87db:
                        goto code_r0x000bad26;
                      case 0x87dc:
                        goto code_r0x000bad30;
                      case 0x87de:
                        goto code_r0x000bad3a;
                      case 0x87df:
                        goto code_r0x000bad44;
                      }
                      break;
                    case 0x87db:
                      uVar10 = puVar21[0x13];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000bacf4;
                      case 0x87d6:
                        goto code_r0x000bacfe;
                      case 0x87d7:
                        goto code_r0x000b8dc4;
                      case 0x87d8:
                        goto code_r0x000bad08;
                      case 0x87d9:
                        goto code_r0x000bad12;
                      case 0x87da:
                        goto code_r0x000bad1c;
                      case 0x87db:
                        goto code_r0x000bad26;
                      case 0x87dc:
                        goto code_r0x000bad30;
                      case 0x87de:
                        goto code_r0x000bad3a;
                      case 0x87df:
                        goto code_r0x000bad44;
                      }
                      break;
                    case 0x87dc:
                      uVar10 = puVar21[0x14];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000bacf4;
                      case 0x87d6:
                        goto code_r0x000bacfe;
                      case 0x87d7:
                        goto code_r0x000b8dc4;
                      case 0x87d8:
                        goto code_r0x000bad08;
                      case 0x87d9:
                        goto code_r0x000bad12;
                      case 0x87da:
                        goto code_r0x000bad1c;
                      case 0x87db:
                        goto code_r0x000bad26;
                      case 0x87dc:
                        goto code_r0x000bad30;
                      case 0x87de:
                        goto code_r0x000bad3a;
                      case 0x87df:
                        goto code_r0x000bad44;
                      }
                    }
                    *puVar13 = uVar10;
                    uVar10 = puVar12[0x12];
                    switch(uVar10) {
                    case 0x87d5:
                      uVar10 = *puVar1;
                      break;
                    case 0x87d6:
                      uVar10 = puVar21[0x12];
                      break;
                    case 0x87d7:
                      uVar10 = puVar21[0x13];
                      break;
                    case 0x87d8:
                      uVar10 = puVar21[0x14];
                      break;
                    case 0x87d9:
                      uVar10 = *puVar1;
                      switch(uVar10) {
                      case 0x87d5:
code_r0x000bae98:
                        uVar10 = 0x87d9;
                        break;
                      case 0x87d6:
code_r0x000baea2:
                        uVar10 = 0x87da;
                        break;
                      case 0x87d7:
code_r0x000b8e0c:
                        uVar10 = 0x87db;
                        break;
                      case 0x87d8:
code_r0x000baeac:
                        uVar10 = 0x87dc;
                        break;
                      case 0x87d9:
code_r0x000baeb6:
                        uVar10 = 0x87d5;
                        break;
                      case 0x87da:
code_r0x000baec0:
                        uVar10 = 0x87d6;
                        break;
                      case 0x87db:
code_r0x000baeca:
                        uVar10 = 0x87d7;
                        break;
                      case 0x87dc:
code_r0x000baed4:
                        uVar10 = 0x87d8;
                        break;
                      case 0x87de:
code_r0x000baede:
                        uVar10 = 0x87df;
                        break;
                      case 0x87df:
code_r0x000baee8:
                        uVar10 = 0x87de;
                      }
                      break;
                    case 0x87da:
                      uVar10 = puVar21[0x12];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000bae98;
                      case 0x87d6:
                        goto code_r0x000baea2;
                      case 0x87d7:
                        goto code_r0x000b8e0c;
                      case 0x87d8:
                        goto code_r0x000baeac;
                      case 0x87d9:
                        goto code_r0x000baeb6;
                      case 0x87da:
                        goto code_r0x000baec0;
                      case 0x87db:
                        goto code_r0x000baeca;
                      case 0x87dc:
                        goto code_r0x000baed4;
                      case 0x87de:
                        goto code_r0x000baede;
                      case 0x87df:
                        goto code_r0x000baee8;
                      }
                      break;
                    case 0x87db:
                      uVar10 = puVar21[0x13];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000bae98;
                      case 0x87d6:
                        goto code_r0x000baea2;
                      case 0x87d7:
                        goto code_r0x000b8e0c;
                      case 0x87d8:
                        goto code_r0x000baeac;
                      case 0x87d9:
                        goto code_r0x000baeb6;
                      case 0x87da:
                        goto code_r0x000baec0;
                      case 0x87db:
                        goto code_r0x000baeca;
                      case 0x87dc:
                        goto code_r0x000baed4;
                      case 0x87de:
                        goto code_r0x000baede;
                      case 0x87df:
                        goto code_r0x000baee8;
                      }
                      break;
                    case 0x87dc:
                      uVar10 = puVar21[0x14];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000bae98;
                      case 0x87d6:
                        goto code_r0x000baea2;
                      case 0x87d7:
                        goto code_r0x000b8e0c;
                      case 0x87d8:
                        goto code_r0x000baeac;
                      case 0x87d9:
                        goto code_r0x000baeb6;
                      case 0x87da:
                        goto code_r0x000baec0;
                      case 0x87db:
                        goto code_r0x000baeca;
                      case 0x87dc:
                        goto code_r0x000baed4;
                      case 0x87de:
                        goto code_r0x000baede;
                      case 0x87df:
                        goto code_r0x000baee8;
                      }
                    }
                    puVar12[0x12] = uVar10;
                    uVar10 = puVar12[0x13];
                    switch(uVar10) {
                    case 0x87d5:
                      uVar10 = *puVar1;
                      break;
                    case 0x87d6:
                      uVar10 = puVar21[0x12];
                      break;
                    case 0x87d7:
                      uVar10 = puVar21[0x13];
                      break;
                    case 0x87d8:
                      uVar10 = puVar21[0x14];
                      break;
                    case 0x87d9:
                      uVar10 = *puVar1;
                      switch(uVar10) {
                      case 0x87d5:
code_r0x000b9014:
                        uVar10 = 0x87d9;
                        break;
                      case 0x87d6:
code_r0x000b901e:
                        uVar10 = 0x87da;
                        break;
                      case 0x87d7:
code_r0x000b8e54:
                        uVar10 = 0x87db;
                        break;
                      case 0x87d8:
code_r0x000b9028:
                        uVar10 = 0x87dc;
                        break;
                      case 0x87d9:
code_r0x000b9032:
                        uVar10 = 0x87d5;
                        break;
                      case 0x87da:
code_r0x000b903c:
                        uVar10 = 0x87d6;
                        break;
                      case 0x87db:
code_r0x000b9046:
                        uVar10 = 0x87d7;
                        break;
                      case 0x87dc:
code_r0x000b9050:
                        uVar10 = 0x87d8;
                        break;
                      case 0x87de:
code_r0x000b905a:
                        uVar10 = 0x87df;
                        break;
                      case 0x87df:
code_r0x000b9064:
                        uVar10 = 0x87de;
                      }
                      break;
                    case 0x87da:
                      uVar10 = puVar21[0x12];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000b9014;
                      case 0x87d6:
                        goto code_r0x000b901e;
                      case 0x87d7:
                        goto code_r0x000b8e54;
                      case 0x87d8:
                        goto code_r0x000b9028;
                      case 0x87d9:
                        goto code_r0x000b9032;
                      case 0x87da:
                        goto code_r0x000b903c;
                      case 0x87db:
                        goto code_r0x000b9046;
                      case 0x87dc:
                        goto code_r0x000b9050;
                      case 0x87de:
                        goto code_r0x000b905a;
                      case 0x87df:
                        goto code_r0x000b9064;
                      }
                      break;
                    case 0x87db:
                      uVar10 = puVar21[0x13];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000b9014;
                      case 0x87d6:
                        goto code_r0x000b901e;
                      case 0x87d7:
                        goto code_r0x000b8e54;
                      case 0x87d8:
                        goto code_r0x000b9028;
                      case 0x87d9:
                        goto code_r0x000b9032;
                      case 0x87da:
                        goto code_r0x000b903c;
                      case 0x87db:
                        goto code_r0x000b9046;
                      case 0x87dc:
                        goto code_r0x000b9050;
                      case 0x87de:
                        goto code_r0x000b905a;
                      case 0x87df:
                        goto code_r0x000b9064;
                      }
                      break;
                    case 0x87dc:
                      uVar10 = puVar21[0x14];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000b9014;
                      case 0x87d6:
                        goto code_r0x000b901e;
                      case 0x87d7:
                        goto code_r0x000b8e54;
                      case 0x87d8:
                        goto code_r0x000b9028;
                      case 0x87d9:
                        goto code_r0x000b9032;
                      case 0x87da:
                        goto code_r0x000b903c;
                      case 0x87db:
                        goto code_r0x000b9046;
                      case 0x87dc:
                        goto code_r0x000b9050;
                      case 0x87de:
                        goto code_r0x000b905a;
                      case 0x87df:
                        goto code_r0x000b9064;
                      }
                    }
                    puVar12[0x13] = uVar10;
                    uVar10 = puVar12[0x14];
                    switch(uVar10) {
                    case 0x87d5:
                      uVar10 = *puVar1;
                      break;
                    case 0x87d6:
                      uVar10 = puVar21[0x12];
                      break;
                    case 0x87d7:
                      uVar10 = puVar21[0x13];
                      break;
                    case 0x87d8:
                      uVar10 = puVar21[0x14];
                      break;
                    case 0x87d9:
                      uVar10 = *puVar1;
                      switch(uVar10) {
                      case 0x87d5:
code_r0x000b91b8:
                        uVar10 = 0x87d9;
                        break;
                      case 0x87d6:
code_r0x000b91c2:
                        uVar10 = 0x87da;
                        break;
                      case 0x87d7:
code_r0x000b8e9c:
                        uVar10 = 0x87db;
                        break;
                      case 0x87d8:
code_r0x000b91cc:
                        uVar10 = 0x87dc;
                        break;
                      case 0x87d9:
code_r0x000b91d6:
                        uVar10 = 0x87d5;
                        break;
                      case 0x87da:
code_r0x000b91e0:
                        uVar10 = 0x87d6;
                        break;
                      case 0x87db:
code_r0x000b91ea:
                        uVar10 = 0x87d7;
                        break;
                      case 0x87dc:
code_r0x000b91f4:
                        uVar10 = 0x87d8;
                        break;
                      case 0x87de:
code_r0x000b91fe:
                        uVar10 = 0x87df;
                        break;
                      case 0x87df:
code_r0x000b9208:
                        uVar10 = 0x87de;
                      }
                      break;
                    case 0x87da:
                      uVar10 = puVar21[0x12];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000b91b8;
                      case 0x87d6:
                        goto code_r0x000b91c2;
                      case 0x87d7:
                        goto code_r0x000b8e9c;
                      case 0x87d8:
                        goto code_r0x000b91cc;
                      case 0x87d9:
                        goto code_r0x000b91d6;
                      case 0x87da:
                        goto code_r0x000b91e0;
                      case 0x87db:
                        goto code_r0x000b91ea;
                      case 0x87dc:
                        goto code_r0x000b91f4;
                      case 0x87de:
                        goto code_r0x000b91fe;
                      case 0x87df:
                        goto code_r0x000b9208;
                      }
                      break;
                    case 0x87db:
                      uVar10 = puVar21[0x13];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000b91b8;
                      case 0x87d6:
                        goto code_r0x000b91c2;
                      case 0x87d7:
                        goto code_r0x000b8e9c;
                      case 0x87d8:
                        goto code_r0x000b91cc;
                      case 0x87d9:
                        goto code_r0x000b91d6;
                      case 0x87da:
                        goto code_r0x000b91e0;
                      case 0x87db:
                        goto code_r0x000b91ea;
                      case 0x87dc:
                        goto code_r0x000b91f4;
                      case 0x87de:
                        goto code_r0x000b91fe;
                      case 0x87df:
                        goto code_r0x000b9208;
                      }
                      break;
                    case 0x87dc:
                      uVar10 = puVar21[0x14];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000b91b8;
                      case 0x87d6:
                        goto code_r0x000b91c2;
                      case 0x87d7:
                        goto code_r0x000b8e9c;
                      case 0x87d8:
                        goto code_r0x000b91cc;
                      case 0x87d9:
                        goto code_r0x000b91d6;
                      case 0x87da:
                        goto code_r0x000b91e0;
                      case 0x87db:
                        goto code_r0x000b91ea;
                      case 0x87dc:
                        goto code_r0x000b91f4;
                      case 0x87de:
                        goto code_r0x000b91fe;
                      case 0x87df:
                        goto code_r0x000b9208;
                      }
                    }
                    puVar12[0x14] = uVar10;
                    local_d0 = *(int *)(param_2 + 0x14) - 1;
                    *(uint *)(param_2 + 0x14) = local_d0;
                    uVar11 = local_58;
                    local_84 = local_58 * 0x74;
                    if (local_58 < local_d0) {
                      do {
                        local_4c = uVar11;
                        pvVar18 = (void *)(local_84 + *(int *)(param_2 + 0x18));
                        _memcpy(pvVar18,(void *)((int)pvVar18 + 0x74),0x74);
                        uVar11 = local_4c + 1;
                        local_84 = local_84 + 0x74;
                      } while (uVar11 < *(uint *)(param_2 + 0x14));
                      local_4c = local_4c + 2;
                      bVar7 = true;
                      local_d0 = *(uint *)(param_2 + 0x14);
                    }
                    else {
                      bVar7 = true;
                      local_4c = uVar14;
                    }
                    goto LAB_000b8477;
                  }
                  iVar17 = iVar22 + uVar14 * 0x74;
                  bVar7 = true;
                  local_7c = 0;
                  do {
                    if ((*(int *)(iVar17 + 0x20) == 2) && (*(int *)(iVar17 + 0x24) == puVar21[2])) {
                      bVar7 = false;
                    }
                    else if ((*(int *)(iVar17 + 0x3c) == 2) &&
                            (*(int *)(iVar17 + 0x40) == puVar21[2])) {
                      bVar7 = false;
                    }
                    else if ((*(int *)(iVar17 + 0x58) == 2) &&
                            (*(int *)(iVar17 + 0x5c) == puVar21[2])) {
                      bVar7 = false;
                    }
                    else {
                      iVar19 = *(int *)(iVar17 + 4);
                      if ((iVar19 == 2) && (*(int *)(iVar17 + 8) == puVar21[2])) {
                        bVar7 = false;
                      }
                      else if ((iVar19 == puVar21[8]) && (*(int *)(iVar17 + 8) == puVar21[9])) {
                        bVar7 = false;
                      }
                      else if ((iVar19 == puVar21[0xf]) && (*(int *)(iVar17 + 8) == puVar21[0x10]))
                      {
                        bVar7 = false;
                      }
                    }
                    local_7c = local_7c + 1;
                    iVar17 = iVar17 + 0x74;
                  } while (local_7c != local_4c - uVar14);
                  if (bVar7) goto LAB_000b8708;
LAB_000b8869:
                  local_c8 = local_4c + 1;
                  iVar17 = iVar22 + uVar14 * 0x74;
                  bVar7 = true;
                  local_a0 = uVar14;
                  do {
                    if ((*(int *)(iVar17 + 0x20) == 2) && (*(int *)(iVar17 + 0x24) == puVar21[2])) {
LAB_000b892b:
                      bVar7 = false;
                    }
                    else if ((*(int *)(iVar17 + 0x3c) == 2) &&
                            (*(int *)(iVar17 + 0x40) == puVar21[2])) {
                      bVar7 = false;
                    }
                    else if ((*(int *)(iVar17 + 0x58) == 2) &&
                            (*(int *)(iVar17 + 0x5c) == puVar21[2])) {
                      bVar7 = false;
                    }
                    else if ((*(int *)(iVar17 + 0x20) == 2) &&
                            (*(int *)(iVar17 + 0x24) == puVar12[2])) {
                      bVar7 = false;
                    }
                    else if ((*(int *)(iVar17 + 0x3c) == 2) &&
                            (*(int *)(iVar17 + 0x40) == puVar12[2])) {
                      bVar7 = false;
                    }
                    else {
                      if ((*(int *)(iVar17 + 0x58) == 2) && (*(int *)(iVar17 + 0x5c) == puVar12[2]))
                      goto LAB_000b892b;
                      iVar19 = *(int *)(iVar17 + 4);
                      if ((iVar20 == iVar19) && (*(int *)(iVar17 + 8) == puVar12[9])) {
                        bVar7 = false;
                      }
                      else if ((iVar19 == puVar12[0xf]) && (*(int *)(iVar17 + 8) == puVar12[0x10]))
                      {
                        bVar7 = false;
                      }
                      else if ((iVar19 == puVar12[1]) && (*(int *)(iVar17 + 8) == puVar12[2])) {
                        bVar7 = false;
                      }
                    }
                    local_a0 = local_a0 + 1;
                    iVar17 = iVar17 + 0x74;
                  } while (local_a0 < local_4c);
                  if (!bVar7) {
                    local_4c = local_c8;
                    bVar7 = true;
                    goto LAB_000b8477;
                  }
LAB_000b87e6:
                  local_c8 = local_4c + 1;
                  if (local_c8 < local_d0) {
                    iVar22 = iVar22 + local_c8 * 0x74;
                    iVar17 = 0;
                    do {
                      if ((*(int *)(iVar22 + 0x20) == 2) && (*(int *)(iVar22 + 0x24) == puVar21[2]))
                      {
                        bVar7 = false;
                      }
                      else if ((*(int *)(iVar22 + 0x3c) == 2) &&
                              (*(int *)(iVar22 + 0x40) == puVar21[2])) {
                        bVar7 = false;
                      }
                      else if ((*(int *)(iVar22 + 0x58) == 2) &&
                              (*(int *)(iVar22 + 0x5c) == puVar21[2])) {
                        bVar7 = false;
                      }
                      iVar17 = iVar17 + 1;
                      iVar22 = iVar22 + 0x74;
                    } while (local_d0 - local_c8 != iVar17);
                    if (bVar7) goto LAB_000b92b2;
                  }
                  else {
LAB_000b92b2:
                    *puVar21 = &switchdataD_00008788;
                    iVar22 = puVar12[9];
                    if (iVar22 == puVar21[2]) {
                      puVar21[0x16] = puVar12[0xf];
                      puVar21[0x17] = puVar12[0x10];
                      puVar21[0x18] = puVar12[0x11];
                      puVar21[0x19] = puVar12[0x12];
                      puVar21[0x1a] = puVar12[0x13];
                      puVar21[0x1b] = puVar12[0x14];
                      puVar21[0x1c] = puVar12[0x15];
                    }
                    else {
                      puVar21[0x16] = iVar20;
                      puVar21[0x17] = iVar22;
                      puVar21[0x18] = puVar12[10];
                      puVar21[0x19] = puVar12[0xb];
                      puVar21[0x1a] = puVar12[0xc];
                      puVar21[0x1b] = puVar12[0xd];
                      puVar21[0x1c] = puVar12[0xe];
                      puVar12[10] = puVar12[0x11];
                      puVar12[0xb] = puVar12[0x12];
                      puVar12[0xc] = puVar12[0x13];
                      puVar12[0xd] = puVar12[0x14];
                    }
                    puVar21[1] = puVar12[1];
                    puVar21[2] = puVar12[2];
                    puVar21[3] = puVar12[3];
                    puVar21[4] = puVar12[4];
                    puVar21[5] = puVar12[5];
                    puVar21[6] = puVar12[6];
                    puVar21[7] = puVar12[7];
                    puVar13 = puVar12 + 0x11;
                    uVar10 = puVar12[10];
                    switch(uVar10) {
                    case 0x87d9:
                      uVar10 = 0x87d5;
                      break;
                    case 0x87da:
                      uVar10 = 0x87d6;
                      break;
                    case 0x87db:
                      uVar10 = 0x87d7;
                      break;
                    case 0x87dc:
                      uVar10 = 0x87d8;
                      break;
                    case 0x87df:
                      uVar10 = 0x87de;
                    }
                    *puVar13 = uVar10;
                    uVar10 = puVar12[0xb];
                    switch(uVar10) {
                    case 0x87d9:
                      uVar10 = 0x87d5;
                      break;
                    case 0x87da:
                      uVar10 = 0x87d6;
                      break;
                    case 0x87db:
                      uVar10 = 0x87d7;
                      break;
                    case 0x87dc:
                      uVar10 = 0x87d8;
                      break;
                    case 0x87df:
                      uVar10 = 0x87de;
                    }
                    puVar12[0x12] = uVar10;
                    uVar10 = puVar12[0xc];
                    switch(uVar10) {
                    case 0x87d9:
                      uVar10 = 0x87d5;
                      break;
                    case 0x87da:
                      uVar10 = 0x87d6;
                      break;
                    case 0x87db:
                      uVar10 = 0x87d7;
                      break;
                    case 0x87dc:
                      uVar10 = 0x87d8;
                      break;
                    case 0x87df:
                      uVar10 = 0x87de;
                    }
                    puVar12[0x13] = uVar10;
                    uVar10 = puVar12[0xd];
                    switch(uVar10) {
                    case 0x87d9:
                      uVar10 = 0x87d5;
                      break;
                    case 0x87da:
                      uVar10 = 0x87d6;
                      break;
                    case 0x87db:
                      uVar10 = 0x87d7;
                      break;
                    case 0x87dc:
                      uVar10 = 0x87d8;
                      break;
                    case 0x87df:
                      uVar10 = 0x87de;
                    }
                    puVar12[0x14] = uVar10;
                    puVar1 = puVar21 + 10;
                    uVar10 = puVar12[10];
                    switch(uVar10) {
                    case 0x87d5:
                      uVar10 = *puVar1;
                      break;
                    case 0x87d6:
                      uVar10 = puVar21[0xb];
                      break;
                    case 0x87d7:
                      uVar10 = puVar21[0xc];
                      break;
                    case 0x87d8:
                      uVar10 = puVar21[0xd];
                      break;
                    case 0x87d9:
                      uVar10 = *puVar1;
                      switch(uVar10) {
                      case 0x87d5:
code_r0x000b95ec:
                        uVar10 = 0x87d9;
                        break;
                      case 0x87d6:
code_r0x000b95f6:
                        uVar10 = 0x87da;
                        break;
                      case 0x87d7:
code_r0x000ba1e9:
                        uVar10 = 0x87db;
                        break;
                      case 0x87d8:
code_r0x000ba1f3:
                        uVar10 = 0x87dc;
                        break;
                      case 0x87d9:
code_r0x000ba1fd:
                        uVar10 = 0x87d5;
                        break;
                      case 0x87da:
code_r0x000ba207:
                        uVar10 = 0x87d6;
                        break;
                      case 0x87db:
code_r0x000ba211:
                        uVar10 = 0x87d7;
                        break;
                      case 0x87dc:
code_r0x000ba21b:
                        uVar10 = 0x87d8;
                        break;
                      case 0x87de:
code_r0x000ba225:
                        uVar10 = 0x87df;
                        break;
                      case 0x87df:
code_r0x000ba22f:
                        uVar10 = 0x87de;
                      }
                      break;
                    case 0x87da:
                      uVar10 = puVar21[0xb];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000b95ec;
                      case 0x87d6:
                        goto code_r0x000b95f6;
                      case 0x87d7:
                        goto code_r0x000ba1e9;
                      case 0x87d8:
                        goto code_r0x000ba1f3;
                      case 0x87d9:
                        goto code_r0x000ba1fd;
                      case 0x87da:
                        goto code_r0x000ba207;
                      case 0x87db:
                        goto code_r0x000ba211;
                      case 0x87dc:
                        goto code_r0x000ba21b;
                      case 0x87de:
                        goto code_r0x000ba225;
                      case 0x87df:
                        goto code_r0x000ba22f;
                      }
                      break;
                    case 0x87db:
                      uVar10 = puVar21[0xc];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000b95ec;
                      case 0x87d6:
                        goto code_r0x000b95f6;
                      case 0x87d7:
                        goto code_r0x000ba1e9;
                      case 0x87d8:
                        goto code_r0x000ba1f3;
                      case 0x87d9:
                        goto code_r0x000ba1fd;
                      case 0x87da:
                        goto code_r0x000ba207;
                      case 0x87db:
                        goto code_r0x000ba211;
                      case 0x87dc:
                        goto code_r0x000ba21b;
                      case 0x87de:
                        goto code_r0x000ba225;
                      case 0x87df:
                        goto code_r0x000ba22f;
                      }
                      break;
                    case 0x87dc:
                      uVar10 = puVar21[0xd];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000b95ec;
                      case 0x87d6:
                        goto code_r0x000b95f6;
                      case 0x87d7:
                        goto code_r0x000ba1e9;
                      case 0x87d8:
                        goto code_r0x000ba1f3;
                      case 0x87d9:
                        goto code_r0x000ba1fd;
                      case 0x87da:
                        goto code_r0x000ba207;
                      case 0x87db:
                        goto code_r0x000ba211;
                      case 0x87dc:
                        goto code_r0x000ba21b;
                      case 0x87de:
                        goto code_r0x000ba225;
                      case 0x87df:
                        goto code_r0x000ba22f;
                      }
                    }
                    puVar12[10] = uVar10;
                    uVar10 = puVar12[0xb];
                    switch(uVar10) {
                    case 0x87d5:
                      uVar10 = *puVar1;
                      break;
                    case 0x87d6:
                      uVar10 = puVar21[0xb];
                      break;
                    case 0x87d7:
                      uVar10 = puVar21[0xc];
                      break;
                    case 0x87d8:
                      uVar10 = puVar21[0xd];
                      break;
                    case 0x87d9:
                      uVar10 = *puVar1;
                      switch(uVar10) {
                      case 0x87d5:
code_r0x000ba380:
                        uVar10 = 0x87d9;
                        break;
                      case 0x87d6:
code_r0x000ba38a:
                        uVar10 = 0x87da;
                        break;
                      case 0x87d7:
code_r0x000ba394:
                        uVar10 = 0x87db;
                        break;
                      case 0x87d8:
code_r0x000ba39e:
                        uVar10 = 0x87dc;
                        break;
                      case 0x87d9:
code_r0x000ba3a8:
                        uVar10 = 0x87d5;
                        break;
                      case 0x87da:
code_r0x000ba3b2:
                        uVar10 = 0x87d6;
                        break;
                      case 0x87db:
code_r0x000ba3bc:
                        uVar10 = 0x87d7;
                        break;
                      case 0x87dc:
code_r0x000ba3c6:
                        uVar10 = 0x87d8;
                        break;
                      case 0x87de:
code_r0x000ba3d0:
                        uVar10 = 0x87df;
                        break;
                      case 0x87df:
code_r0x000ba3da:
                        uVar10 = 0x87de;
                      }
                      break;
                    case 0x87da:
                      uVar10 = puVar21[0xb];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000ba380;
                      case 0x87d6:
                        goto code_r0x000ba38a;
                      case 0x87d7:
                        goto code_r0x000ba394;
                      case 0x87d8:
                        goto code_r0x000ba39e;
                      case 0x87d9:
                        goto code_r0x000ba3a8;
                      case 0x87da:
                        goto code_r0x000ba3b2;
                      case 0x87db:
                        goto code_r0x000ba3bc;
                      case 0x87dc:
                        goto code_r0x000ba3c6;
                      case 0x87de:
                        goto code_r0x000ba3d0;
                      case 0x87df:
                        goto code_r0x000ba3da;
                      }
                      break;
                    case 0x87db:
                      uVar10 = puVar21[0xc];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000ba380;
                      case 0x87d6:
                        goto code_r0x000ba38a;
                      case 0x87d7:
                        goto code_r0x000ba394;
                      case 0x87d8:
                        goto code_r0x000ba39e;
                      case 0x87d9:
                        goto code_r0x000ba3a8;
                      case 0x87da:
                        goto code_r0x000ba3b2;
                      case 0x87db:
                        goto code_r0x000ba3bc;
                      case 0x87dc:
                        goto code_r0x000ba3c6;
                      case 0x87de:
                        goto code_r0x000ba3d0;
                      case 0x87df:
                        goto code_r0x000ba3da;
                      }
                      break;
                    case 0x87dc:
                      uVar10 = puVar21[0xd];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000ba380;
                      case 0x87d6:
                        goto code_r0x000ba38a;
                      case 0x87d7:
                        goto code_r0x000ba394;
                      case 0x87d8:
                        goto code_r0x000ba39e;
                      case 0x87d9:
                        goto code_r0x000ba3a8;
                      case 0x87da:
                        goto code_r0x000ba3b2;
                      case 0x87db:
                        goto code_r0x000ba3bc;
                      case 0x87dc:
                        goto code_r0x000ba3c6;
                      case 0x87de:
                        goto code_r0x000ba3d0;
                      case 0x87df:
                        goto code_r0x000ba3da;
                      }
                    }
                    puVar12[0xb] = uVar10;
                    uVar10 = puVar12[0xc];
                    switch(uVar10) {
                    case 0x87d5:
                      uVar10 = *puVar1;
                      break;
                    case 0x87d6:
                      uVar10 = puVar21[0xb];
                      break;
                    case 0x87d7:
                      uVar10 = puVar21[0xc];
                      break;
                    case 0x87d8:
                      uVar10 = puVar21[0xd];
                      break;
                    case 0x87d9:
                      uVar10 = *puVar1;
                      switch(uVar10) {
                      case 0x87d5:
code_r0x000b9728:
                        uVar10 = 0x87d9;
                        break;
                      case 0x87d6:
code_r0x000b9732:
                        uVar10 = 0x87da;
                        break;
                      case 0x87d7:
code_r0x000b973c:
                        uVar10 = 0x87db;
                        break;
                      case 0x87d8:
code_r0x000b9746:
                        uVar10 = 0x87dc;
                        break;
                      case 0x87d9:
code_r0x000b9750:
                        uVar10 = 0x87d5;
                        break;
                      case 0x87da:
code_r0x000b975a:
                        uVar10 = 0x87d6;
                        break;
                      case 0x87db:
code_r0x000b9764:
                        uVar10 = 0x87d7;
                        break;
                      case 0x87dc:
code_r0x000b976e:
                        uVar10 = 0x87d8;
                        break;
                      case 0x87de:
code_r0x000b9778:
                        uVar10 = 0x87df;
                        break;
                      case 0x87df:
code_r0x000b9782:
                        uVar10 = 0x87de;
                      }
                      break;
                    case 0x87da:
                      uVar10 = puVar21[0xb];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000b9728;
                      case 0x87d6:
                        goto code_r0x000b9732;
                      case 0x87d7:
                        goto code_r0x000b973c;
                      case 0x87d8:
                        goto code_r0x000b9746;
                      case 0x87d9:
                        goto code_r0x000b9750;
                      case 0x87da:
                        goto code_r0x000b975a;
                      case 0x87db:
                        goto code_r0x000b9764;
                      case 0x87dc:
                        goto code_r0x000b976e;
                      case 0x87de:
                        goto code_r0x000b9778;
                      case 0x87df:
                        goto code_r0x000b9782;
                      }
                      break;
                    case 0x87db:
                      uVar10 = puVar21[0xc];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000b9728;
                      case 0x87d6:
                        goto code_r0x000b9732;
                      case 0x87d7:
                        goto code_r0x000b973c;
                      case 0x87d8:
                        goto code_r0x000b9746;
                      case 0x87d9:
                        goto code_r0x000b9750;
                      case 0x87da:
                        goto code_r0x000b975a;
                      case 0x87db:
                        goto code_r0x000b9764;
                      case 0x87dc:
                        goto code_r0x000b976e;
                      case 0x87de:
                        goto code_r0x000b9778;
                      case 0x87df:
                        goto code_r0x000b9782;
                      }
                      break;
                    case 0x87dc:
                      uVar10 = puVar21[0xd];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000b9728;
                      case 0x87d6:
                        goto code_r0x000b9732;
                      case 0x87d7:
                        goto code_r0x000b973c;
                      case 0x87d8:
                        goto code_r0x000b9746;
                      case 0x87d9:
                        goto code_r0x000b9750;
                      case 0x87da:
                        goto code_r0x000b975a;
                      case 0x87db:
                        goto code_r0x000b9764;
                      case 0x87dc:
                        goto code_r0x000b976e;
                      case 0x87de:
                        goto code_r0x000b9778;
                      case 0x87df:
                        goto code_r0x000b9782;
                      }
                    }
                    puVar12[0xc] = uVar10;
                    uVar10 = puVar12[0xd];
                    switch(uVar10) {
                    case 0x87d5:
                      uVar10 = *puVar1;
                      break;
                    case 0x87d6:
                      uVar10 = puVar21[0xb];
                      break;
                    case 0x87d7:
                      uVar10 = puVar21[0xc];
                      break;
                    case 0x87d8:
                      uVar10 = puVar21[0xd];
                      break;
                    case 0x87d9:
                      uVar10 = *puVar1;
                      switch(uVar10) {
                      case 0x87d5:
code_r0x000b9914:
                        uVar10 = 0x87d9;
                        break;
                      case 0x87d6:
code_r0x000b991e:
                        uVar10 = 0x87da;
                        break;
                      case 0x87d7:
code_r0x000b9928:
                        uVar10 = 0x87db;
                        break;
                      case 0x87d8:
code_r0x000b9932:
                        uVar10 = 0x87dc;
                        break;
                      case 0x87d9:
code_r0x000b993c:
                        uVar10 = 0x87d5;
                        break;
                      case 0x87da:
code_r0x000b9946:
                        uVar10 = 0x87d6;
                        break;
                      case 0x87db:
code_r0x000b9950:
                        uVar10 = 0x87d7;
                        break;
                      case 0x87dc:
code_r0x000b995a:
                        uVar10 = 0x87d8;
                        break;
                      case 0x87de:
code_r0x000b9964:
                        uVar10 = 0x87df;
                        break;
                      case 0x87df:
code_r0x000b996e:
                        uVar10 = 0x87de;
                      }
                      break;
                    case 0x87da:
                      uVar10 = puVar21[0xb];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000b9914;
                      case 0x87d6:
                        goto code_r0x000b991e;
                      case 0x87d7:
                        goto code_r0x000b9928;
                      case 0x87d8:
                        goto code_r0x000b9932;
                      case 0x87d9:
                        goto code_r0x000b993c;
                      case 0x87da:
                        goto code_r0x000b9946;
                      case 0x87db:
                        goto code_r0x000b9950;
                      case 0x87dc:
                        goto code_r0x000b995a;
                      case 0x87de:
                        goto code_r0x000b9964;
                      case 0x87df:
                        goto code_r0x000b996e;
                      }
                      break;
                    case 0x87db:
                      uVar10 = puVar21[0xc];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000b9914;
                      case 0x87d6:
                        goto code_r0x000b991e;
                      case 0x87d7:
                        goto code_r0x000b9928;
                      case 0x87d8:
                        goto code_r0x000b9932;
                      case 0x87d9:
                        goto code_r0x000b993c;
                      case 0x87da:
                        goto code_r0x000b9946;
                      case 0x87db:
                        goto code_r0x000b9950;
                      case 0x87dc:
                        goto code_r0x000b995a;
                      case 0x87de:
                        goto code_r0x000b9964;
                      case 0x87df:
                        goto code_r0x000b996e;
                      }
                      break;
                    case 0x87dc:
                      uVar10 = puVar21[0xd];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000b9914;
                      case 0x87d6:
                        goto code_r0x000b991e;
                      case 0x87d7:
                        goto code_r0x000b9928;
                      case 0x87d8:
                        goto code_r0x000b9932;
                      case 0x87d9:
                        goto code_r0x000b993c;
                      case 0x87da:
                        goto code_r0x000b9946;
                      case 0x87db:
                        goto code_r0x000b9950;
                      case 0x87dc:
                        goto code_r0x000b995a;
                      case 0x87de:
                        goto code_r0x000b9964;
                      case 0x87df:
                        goto code_r0x000b996e;
                      }
                    }
                    puVar12[0xd] = uVar10;
                    puVar1 = puVar21 + 0x11;
                    uVar10 = *puVar13;
                    switch(uVar10) {
                    case 0x87d5:
                      uVar10 = *puVar1;
                      break;
                    case 0x87d6:
                      uVar10 = puVar21[0x12];
                      break;
                    case 0x87d7:
                      uVar10 = puVar21[0x13];
                      break;
                    case 0x87d8:
                      uVar10 = puVar21[0x14];
                      break;
                    case 0x87d9:
                      uVar10 = *puVar1;
                      switch(uVar10) {
                      case 0x87d5:
code_r0x000b9afc:
                        uVar10 = 0x87d9;
                        break;
                      case 0x87d6:
code_r0x000b9b06:
                        uVar10 = 0x87da;
                        break;
                      case 0x87d7:
code_r0x000b9b10:
                        uVar10 = 0x87db;
                        break;
                      case 0x87d8:
code_r0x000b9b1a:
                        uVar10 = 0x87dc;
                        break;
                      case 0x87d9:
code_r0x000b9b24:
                        uVar10 = 0x87d5;
                        break;
                      case 0x87da:
code_r0x000b9b2e:
                        uVar10 = 0x87d6;
                        break;
                      case 0x87db:
code_r0x000b9b38:
                        uVar10 = 0x87d7;
                        break;
                      case 0x87dc:
code_r0x000b9b42:
                        uVar10 = 0x87d8;
                        break;
                      case 0x87de:
code_r0x000b9b4c:
                        uVar10 = 0x87df;
                        break;
                      case 0x87df:
code_r0x000b9b56:
                        uVar10 = 0x87de;
                      }
                      break;
                    case 0x87da:
                      uVar10 = puVar21[0x12];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000b9afc;
                      case 0x87d6:
                        goto code_r0x000b9b06;
                      case 0x87d7:
                        goto code_r0x000b9b10;
                      case 0x87d8:
                        goto code_r0x000b9b1a;
                      case 0x87d9:
                        goto code_r0x000b9b24;
                      case 0x87da:
                        goto code_r0x000b9b2e;
                      case 0x87db:
                        goto code_r0x000b9b38;
                      case 0x87dc:
                        goto code_r0x000b9b42;
                      case 0x87de:
                        goto code_r0x000b9b4c;
                      case 0x87df:
                        goto code_r0x000b9b56;
                      }
                      break;
                    case 0x87db:
                      uVar10 = puVar21[0x13];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000b9afc;
                      case 0x87d6:
                        goto code_r0x000b9b06;
                      case 0x87d7:
                        goto code_r0x000b9b10;
                      case 0x87d8:
                        goto code_r0x000b9b1a;
                      case 0x87d9:
                        goto code_r0x000b9b24;
                      case 0x87da:
                        goto code_r0x000b9b2e;
                      case 0x87db:
                        goto code_r0x000b9b38;
                      case 0x87dc:
                        goto code_r0x000b9b42;
                      case 0x87de:
                        goto code_r0x000b9b4c;
                      case 0x87df:
                        goto code_r0x000b9b56;
                      }
                      break;
                    case 0x87dc:
                      uVar10 = puVar21[0x14];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000b9afc;
                      case 0x87d6:
                        goto code_r0x000b9b06;
                      case 0x87d7:
                        goto code_r0x000b9b10;
                      case 0x87d8:
                        goto code_r0x000b9b1a;
                      case 0x87d9:
                        goto code_r0x000b9b24;
                      case 0x87da:
                        goto code_r0x000b9b2e;
                      case 0x87db:
                        goto code_r0x000b9b38;
                      case 0x87dc:
                        goto code_r0x000b9b42;
                      case 0x87de:
                        goto code_r0x000b9b4c;
                      case 0x87df:
                        goto code_r0x000b9b56;
                      }
                    }
                    *puVar13 = uVar10;
                    uVar10 = puVar12[0x12];
                    switch(uVar10) {
                    case 0x87d5:
                      uVar10 = *puVar1;
                      break;
                    case 0x87d6:
                      uVar10 = puVar21[0x12];
                      break;
                    case 0x87d7:
                      uVar10 = puVar21[0x13];
                      break;
                    case 0x87d8:
                      uVar10 = puVar21[0x14];
                      break;
                    case 0x87d9:
                      uVar10 = *puVar1;
                      switch(uVar10) {
                      case 0x87d5:
code_r0x000b9ce4:
                        uVar10 = 0x87d9;
                        break;
                      case 0x87d6:
code_r0x000b9cee:
                        uVar10 = 0x87da;
                        break;
                      case 0x87d7:
code_r0x000b9cf8:
                        uVar10 = 0x87db;
                        break;
                      case 0x87d8:
code_r0x000b9d02:
                        uVar10 = 0x87dc;
                        break;
                      case 0x87d9:
code_r0x000b9d0c:
                        uVar10 = 0x87d5;
                        break;
                      case 0x87da:
code_r0x000b9d16:
                        uVar10 = 0x87d6;
                        break;
                      case 0x87db:
code_r0x000b9d20:
                        uVar10 = 0x87d7;
                        break;
                      case 0x87dc:
code_r0x000b9d2a:
                        uVar10 = 0x87d8;
                        break;
                      case 0x87de:
code_r0x000b9d34:
                        uVar10 = 0x87df;
                        break;
                      case 0x87df:
code_r0x000b9d3e:
                        uVar10 = 0x87de;
                      }
                      break;
                    case 0x87da:
                      uVar10 = puVar21[0x12];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000b9ce4;
                      case 0x87d6:
                        goto code_r0x000b9cee;
                      case 0x87d7:
                        goto code_r0x000b9cf8;
                      case 0x87d8:
                        goto code_r0x000b9d02;
                      case 0x87d9:
                        goto code_r0x000b9d0c;
                      case 0x87da:
                        goto code_r0x000b9d16;
                      case 0x87db:
                        goto code_r0x000b9d20;
                      case 0x87dc:
                        goto code_r0x000b9d2a;
                      case 0x87de:
                        goto code_r0x000b9d34;
                      case 0x87df:
                        goto code_r0x000b9d3e;
                      }
                      break;
                    case 0x87db:
                      uVar10 = puVar21[0x13];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000b9ce4;
                      case 0x87d6:
                        goto code_r0x000b9cee;
                      case 0x87d7:
                        goto code_r0x000b9cf8;
                      case 0x87d8:
                        goto code_r0x000b9d02;
                      case 0x87d9:
                        goto code_r0x000b9d0c;
                      case 0x87da:
                        goto code_r0x000b9d16;
                      case 0x87db:
                        goto code_r0x000b9d20;
                      case 0x87dc:
                        goto code_r0x000b9d2a;
                      case 0x87de:
                        goto code_r0x000b9d34;
                      case 0x87df:
                        goto code_r0x000b9d3e;
                      }
                      break;
                    case 0x87dc:
                      uVar10 = puVar21[0x14];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000b9ce4;
                      case 0x87d6:
                        goto code_r0x000b9cee;
                      case 0x87d7:
                        goto code_r0x000b9cf8;
                      case 0x87d8:
                        goto code_r0x000b9d02;
                      case 0x87d9:
                        goto code_r0x000b9d0c;
                      case 0x87da:
                        goto code_r0x000b9d16;
                      case 0x87db:
                        goto code_r0x000b9d20;
                      case 0x87dc:
                        goto code_r0x000b9d2a;
                      case 0x87de:
                        goto code_r0x000b9d34;
                      case 0x87df:
                        goto code_r0x000b9d3e;
                      }
                    }
                    puVar12[0x12] = uVar10;
                    uVar10 = puVar12[0x13];
                    switch(uVar10) {
                    case 0x87d5:
                      uVar10 = *puVar1;
                      break;
                    case 0x87d6:
                      uVar10 = puVar21[0x12];
                      break;
                    case 0x87d7:
                      uVar10 = puVar21[0x13];
                      break;
                    case 0x87d8:
                      uVar10 = puVar21[0x14];
                      break;
                    case 0x87d9:
                      uVar10 = *puVar1;
                      switch(uVar10) {
                      case 0x87d5:
code_r0x000b9ecc:
                        uVar10 = 0x87d9;
                        break;
                      case 0x87d6:
code_r0x000b9ed6:
                        uVar10 = 0x87da;
                        break;
                      case 0x87d7:
code_r0x000b9ee0:
                        uVar10 = 0x87db;
                        break;
                      case 0x87d8:
code_r0x000b9eea:
                        uVar10 = 0x87dc;
                        break;
                      case 0x87d9:
code_r0x000b9ef4:
                        uVar10 = 0x87d5;
                        break;
                      case 0x87da:
code_r0x000b9efe:
                        uVar10 = 0x87d6;
                        break;
                      case 0x87db:
code_r0x000b9f08:
                        uVar10 = 0x87d7;
                        break;
                      case 0x87dc:
code_r0x000b9f12:
                        uVar10 = 0x87d8;
                        break;
                      case 0x87de:
code_r0x000b9f1c:
                        uVar10 = 0x87df;
                        break;
                      case 0x87df:
code_r0x000b9f26:
                        uVar10 = 0x87de;
                      }
                      break;
                    case 0x87da:
                      uVar10 = puVar21[0x12];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000b9ecc;
                      case 0x87d6:
                        goto code_r0x000b9ed6;
                      case 0x87d7:
                        goto code_r0x000b9ee0;
                      case 0x87d8:
                        goto code_r0x000b9eea;
                      case 0x87d9:
                        goto code_r0x000b9ef4;
                      case 0x87da:
                        goto code_r0x000b9efe;
                      case 0x87db:
                        goto code_r0x000b9f08;
                      case 0x87dc:
                        goto code_r0x000b9f12;
                      case 0x87de:
                        goto code_r0x000b9f1c;
                      case 0x87df:
                        goto code_r0x000b9f26;
                      }
                      break;
                    case 0x87db:
                      uVar10 = puVar21[0x13];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000b9ecc;
                      case 0x87d6:
                        goto code_r0x000b9ed6;
                      case 0x87d7:
                        goto code_r0x000b9ee0;
                      case 0x87d8:
                        goto code_r0x000b9eea;
                      case 0x87d9:
                        goto code_r0x000b9ef4;
                      case 0x87da:
                        goto code_r0x000b9efe;
                      case 0x87db:
                        goto code_r0x000b9f08;
                      case 0x87dc:
                        goto code_r0x000b9f12;
                      case 0x87de:
                        goto code_r0x000b9f1c;
                      case 0x87df:
                        goto code_r0x000b9f26;
                      }
                      break;
                    case 0x87dc:
                      uVar10 = puVar21[0x14];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000b9ecc;
                      case 0x87d6:
                        goto code_r0x000b9ed6;
                      case 0x87d7:
                        goto code_r0x000b9ee0;
                      case 0x87d8:
                        goto code_r0x000b9eea;
                      case 0x87d9:
                        goto code_r0x000b9ef4;
                      case 0x87da:
                        goto code_r0x000b9efe;
                      case 0x87db:
                        goto code_r0x000b9f08;
                      case 0x87dc:
                        goto code_r0x000b9f12;
                      case 0x87de:
                        goto code_r0x000b9f1c;
                      case 0x87df:
                        goto code_r0x000b9f26;
                      }
                    }
                    puVar12[0x13] = uVar10;
                    uVar10 = puVar12[0x14];
                    switch(uVar10) {
                    case 0x87d5:
                      uVar10 = *puVar1;
                      break;
                    case 0x87d6:
                      uVar10 = puVar21[0x12];
                      break;
                    case 0x87d7:
                      uVar10 = puVar21[0x13];
                      break;
                    case 0x87d8:
                      uVar10 = puVar21[0x14];
                      break;
                    case 0x87d9:
                      uVar10 = *puVar1;
                      switch(uVar10) {
                      case 0x87d5:
code_r0x000ba124:
                        uVar10 = 0x87d9;
                        break;
                      case 0x87d6:
code_r0x000ba12e:
                        uVar10 = 0x87da;
                        break;
                      case 0x87d7:
code_r0x000ba138:
                        uVar10 = 0x87db;
                        break;
                      case 0x87d8:
code_r0x000ba142:
                        uVar10 = 0x87dc;
                        break;
                      case 0x87d9:
code_r0x000ba14c:
                        uVar10 = 0x87d5;
                        break;
                      case 0x87da:
code_r0x000ba156:
                        uVar10 = 0x87d6;
                        break;
                      case 0x87db:
code_r0x000ba160:
                        uVar10 = 0x87d7;
                        break;
                      case 0x87dc:
code_r0x000ba16a:
                        uVar10 = 0x87d8;
                        break;
                      case 0x87de:
code_r0x000ba174:
                        uVar10 = 0x87df;
                        break;
                      case 0x87df:
code_r0x000ba17e:
                        uVar10 = 0x87de;
                      }
                      break;
                    case 0x87da:
                      uVar10 = puVar21[0x12];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000ba124;
                      case 0x87d6:
                        goto code_r0x000ba12e;
                      case 0x87d7:
                        goto code_r0x000ba138;
                      case 0x87d8:
                        goto code_r0x000ba142;
                      case 0x87d9:
                        goto code_r0x000ba14c;
                      case 0x87da:
                        goto code_r0x000ba156;
                      case 0x87db:
                        goto code_r0x000ba160;
                      case 0x87dc:
                        goto code_r0x000ba16a;
                      case 0x87de:
                        goto code_r0x000ba174;
                      case 0x87df:
                        goto code_r0x000ba17e;
                      }
                      break;
                    case 0x87db:
                      uVar10 = puVar21[0x13];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000ba124;
                      case 0x87d6:
                        goto code_r0x000ba12e;
                      case 0x87d7:
                        goto code_r0x000ba138;
                      case 0x87d8:
                        goto code_r0x000ba142;
                      case 0x87d9:
                        goto code_r0x000ba14c;
                      case 0x87da:
                        goto code_r0x000ba156;
                      case 0x87db:
                        goto code_r0x000ba160;
                      case 0x87dc:
                        goto code_r0x000ba16a;
                      case 0x87de:
                        goto code_r0x000ba174;
                      case 0x87df:
                        goto code_r0x000ba17e;
                      }
                      break;
                    case 0x87dc:
                      uVar10 = puVar21[0x14];
                      switch(uVar10) {
                      case 0x87d5:
                        goto code_r0x000ba124;
                      case 0x87d6:
                        goto code_r0x000ba12e;
                      case 0x87d7:
                        goto code_r0x000ba138;
                      case 0x87d8:
                        goto code_r0x000ba142;
                      case 0x87d9:
                        goto code_r0x000ba14c;
                      case 0x87da:
                        goto code_r0x000ba156;
                      case 0x87db:
                        goto code_r0x000ba160;
                      case 0x87dc:
                        goto code_r0x000ba16a;
                      case 0x87de:
                        goto code_r0x000ba174;
                      case 0x87df:
                        goto code_r0x000ba17e;
                      }
                    }
                    puVar12[0x14] = uVar10;
                    puVar21[10] = puVar12[10];
                    puVar21[0xb] = puVar12[0xb];
                    puVar21[0xc] = puVar12[0xc];
                    puVar21[0xd] = puVar12[0xd];
                    puVar21[0x11] = puVar12[0x11];
                    puVar21[0x12] = puVar12[0x12];
                    puVar21[0x13] = puVar12[0x13];
                    puVar21[0x14] = puVar12[0x14];
                    uVar11 = *(int *)(param_2 + 0x14) - 1;
                    *(uint *)(param_2 + 0x14) = uVar11;
                    if (local_4c < uVar11) {
                      do {
                        pvVar18 = (void *)(local_80 + *(int *)(param_2 + 0x18));
                        _memcpy(pvVar18,(void *)((int)pvVar18 + 0x74),0x74);
                        local_4c = local_4c + 1;
                        local_80 = local_80 + 0x74;
                      } while (local_4c < *(uint *)(param_2 + 0x14));
                      local_d0 = *(uint *)(param_2 + 0x14);
                    }
                    else {
                      local_d0 = *(uint *)(param_2 + 0x14);
                    }
                  }
                  local_4c = local_c8;
                  bVar7 = true;
                  goto LAB_000b8477;
                }
              }
              else if ((puVar12[0xf] == 2) && (puVar12[0x10] == puVar21[2])) {
                if (iVar20 == 2) goto LAB_000b878c;
                goto LAB_000b86f8;
              }
              bVar7 = false;
              local_4c = local_4c + 1;
            }
            else {
              local_4c = local_4c + 1;
              bVar7 = false;
            }
LAB_000b8477:
            if ((local_d0 <= local_4c) || (bVar7)) break;
            iVar22 = *(int *)(param_2 + 0x18);
          } while( true );
        }
        goto LAB_000b7d88;
      }
      local_58 = local_58 + 1;
    } while (local_58 < *(uint *)(param_2 + 0x14));
LAB_000b7dd6:
    if (local_d0 != 0) {
      uVar14 = 0;
      do {
        iVar22 = *(int *)(param_2 + 0x18);
        piVar2 = (int *)(iVar22 + uVar14 * 0x74);
        if ((((uint *)*piVar2 == &UINT_00008798) && (piVar2[1] == 2)) && (piVar2[8] == 2)) {
          iVar20 = *(int *)(param_2 + 0x20) + piVar2[9] * 0x54;
          if ((*(char *)(iVar20 + 0x44) != '\0') && (*(int *)(iVar20 + 0x48) == 0xba6)) {
            local_48 = uVar14 + 1;
            if (local_48 < local_d0) {
              piVar16 = (int *)(iVar22 + 0x3c + local_48 * 0x74);
              bVar7 = true;
              local_68 = 0;
              do {
                if ((*piVar16 == 2) && (piVar16[1] == piVar2[2])) {
                  if (((((uint *)piVar16[-0xf] == &UINT_00008798) && (piVar16[-7] == 2)) &&
                      (iVar20 = *(int *)(param_2 + 0x20) + piVar16[-6] * 0x54,
                      *(char *)(iVar20 + 0x44) != '\0')) &&
                     ((*(int *)(iVar20 + 0x48) == 0xba7 && (local_68 == 0)))) {
                    local_68 = local_48;
                    bVar8 = false;
                  }
                  else {
LAB_000b8676:
                    bVar7 = false;
                    bVar8 = true;
                  }
                }
                else {
                  if (((piVar16[-7] == 2) && (piVar16[-6] == piVar2[2])) ||
                     ((piVar16[7] == 2 && (piVar16[8] == piVar2[2])))) goto LAB_000b8676;
                  if ((piVar16[-0xe] == 2) && (piVar16[-0xd] == piVar2[2])) {
                    bVar8 = true;
                  }
                  else {
                    bVar8 = false;
                  }
                }
                local_48 = local_48 + 1;
              } while ((local_d0 != local_48) && (piVar16 = piVar16 + 0x1d, !bVar8));
              if (!bVar7) goto LAB_000b7e06;
              local_88 = local_68 * 0x74;
            }
            else {
              local_68 = 0;
              local_88 = 0;
            }
            if (*(int *)(param_2 + 0x2c) == 0) {
              uVar10 = FUN_000536b4(param_1,iVar9,*(undefined4 *)(*(int *)(param_1 + 0x116c) + 0x18)
                                   );
              *(undefined4 *)(param_2 + 0x2c) = uVar10;
              iVar22 = *(int *)(param_2 + 0x18);
            }
            local_88 = local_88 + iVar22;
            piVar2[9] = *(int *)(param_2 + 0x2c);
            piVar2[1] = *(int *)(local_88 + 4);
            piVar2[2] = *(int *)(local_88 + 8);
            piVar2[3] = *(int *)(local_88 + 0xc);
            piVar2[4] = *(int *)(local_88 + 0x10);
            piVar2[5] = *(int *)(local_88 + 0x14);
            piVar2[6] = *(int *)(local_88 + 0x18);
            piVar2[7] = *(int *)(local_88 + 0x1c);
            uVar11 = *(int *)(param_2 + 0x14) - 1;
            *(uint *)(param_2 + 0x14) = uVar11;
            if (local_68 < uVar11) {
              iVar22 = local_68 * 0x74;
              do {
                pvVar18 = (void *)(iVar22 + *(int *)(param_2 + 0x18));
                _memcpy(pvVar18,(void *)((int)pvVar18 + 0x74),0x74);
                local_68 = local_68 + 1;
                iVar22 = iVar22 + 0x74;
              } while (local_68 < *(uint *)(param_2 + 0x14));
              local_d0 = *(uint *)(param_2 + 0x14);
            }
            else {
              local_d0 = *(uint *)(param_2 + 0x14);
            }
          }
        }
LAB_000b7e06:
        uVar14 = uVar14 + 1;
      } while (uVar14 < local_d0);
    }
  }
  return;
}

/* FUN_000baf88 @ 0xbaf88 (117 bytes) */
int FUN_000baf88(param_1)
  int param_1;
{
  undefined4 *puVar1;
  int iVar2;
  
  if ((*(byte *)(param_1 + 0x45) & 8) == 0) {
    puVar1 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
    *(undefined4 **)(param_1 + 0x274c) = puVar1;
    *puVar1 = 0x860;
    *(undefined4 *)(*(int *)(param_1 + 0x274c) + 4) = *(undefined4 *)(param_1 + 0x1b78);
    iVar2 = *(int *)(param_1 + 0x274c) + 8;
    *(int *)(param_1 + 0x274c) = iVar2;
    (**(code **)(param_1 + 0x275c))(param_1,iVar2);
    FUN_00099ef5(param_1);
    FUN_0009ab2f(param_1);
  }
  FUN_0004c212();
  return;
}

/* FUN_000baffd @ 0xbaffd (1132 bytes) */
int FUN_000baffd(param_1)
  int param_1;
{
  byte *pbVar1;
  ushort *puVar2;
  byte bVar3;
  short sVar4;
  byte bVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  byte bVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  int local_4c;
  uint local_44;
  uint local_38;
  byte local_34;
  byte local_30;
  byte local_2c;
  byte local_28;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  if (((((*(byte *)(param_1 + 0x46) & 4) == 0) || ((*(byte *)(param_1 + 0x2e) & 1) != 0)) ||
      (*(short *)(param_1 + 0x38) < 0)) || (*(short *)(param_1 + 0x40) != 0)) {
    local_20 = param_1 + 0x44;
    *(byte *)(param_1 + 0x8d) = *(byte *)(param_1 + 0x8d) & 0xfe;
    *(byte *)(param_1 + 0x8c) = *(byte *)(param_1 + 0x8c) & 0xf;
    *(byte *)(param_1 + 0x1874) = *(byte *)(param_1 + 0x1874) & 0xbf;
    uVar7 = (uint)*(byte *)(param_1 + 0x13b0);
    if ((uint)*(byte *)(param_1 + 0x2b) <= (uint)*(byte *)(param_1 + 0x13b0)) {
      uVar7 = (uint)*(byte *)(param_1 + 0x2b);
    }
    bVar6 = *(byte *)(param_1 + 0x45);
    if ((bVar6 & 0x40) == 0) {
      *(undefined1 *)(param_1 + 0x1878) = 0;
      local_38 = 0;
    }
    else {
      if ((*(byte *)(param_1 + 0x46) & 4) == 0) {
        bVar3 = *(byte *)(param_1 + 0x1135);
      }
      else {
        bVar3 = *(byte *)(param_1 + 0x11d3);
      }
      local_38 = (uint)bVar3;
      *(byte *)(param_1 + 0x1878) = bVar3;
    }
    if (uVar7 != 0) {
      local_1c = param_1;
      local_18 = param_1;
      local_14 = param_1;
      local_44 = 0;
      local_4c = 0;
      do {
        uVar12 = *(uint *)(local_20 + 4) & 0x1e0;
        if ((bVar6 & 0x40) == 0) {
          if ((*(uint *)(local_20 + 4) & 0x1f) == 0) goto LAB_000bb0fb;
LAB_000bb184:
          bVar14 = *(char *)(local_14 + 0x2784) == '\0';
          *(uint *)(local_1c + 0x150) = (uint)bVar14;
          *(byte *)(param_1 + 0x187c + local_44 * 2) =
               *(byte *)(param_1 + 0x187c + local_44 * 2) & 0xfd | bVar14 * '\x02';
          if (uVar12 == 0) {
            puVar2 = (ushort *)(param_1 + 0x187c + local_44 * 2);
            *puVar2 = *puVar2 & 0xc003;
            bVar6 = *(byte *)(param_1 + 0x8c);
          }
          else {
            uVar11 = uVar12 >> 5 & 1;
            uVar8 = uVar12 >> 6 & 1;
            sVar4 = *(short *)(local_18 + 0x4b0);
            bVar14 = *(short *)(local_18 + 0x48c) == 0x2402 || sVar4 == 0x2402;
            uVar9 = uVar12 >> 7 & 1;
            if ((uVar9 == 0) || (1 < (ushort)(*(short *)(local_18 + 0x4d4) + 0x7aefU))) {
              bVar6 = 0;
            }
            else {
              bVar6 = 1;
            }
            bVar6 = ((sVar4 == -0x7aee || (ushort)(*(short *)(local_18 + 0x48c) + 0x7aefU) < 2) ||
                    sVar4 == -0x7aef) | bVar6;
            if (uVar11 == 0) {
              uVar13 = 0;
            }
            else {
              uVar13 = *(uint *)(&DAT_001eec44 +
                                ((int)(*(ushort *)(local_18 + 0x48c) & 0x10) >> 2 |
                                *(ushort *)(local_18 + 0x48c) & 3) * 4);
            }
            if (uVar8 != 0) {
              uVar13 = uVar13 | *(int *)(&DAT_001eec44 +
                                        ((int)(*(ushort *)(local_18 + 0x4b0) & 0x10) >> 2 |
                                        *(ushort *)(local_18 + 0x4b0) & 3) * 4) << 3;
            }
            if (uVar9 != 0) {
              uVar13 = uVar13 | *(int *)(&DAT_001eec44 +
                                        ((int)(*(ushort *)(local_18 + 0x4d4) & 0x10) >> 2 |
                                        *(ushort *)(local_18 + 0x4d4) & 3) * 4) << 6;
            }
            if (uVar12 >> 8 != 0) {
              uVar13 = uVar13 | *(int *)(&DAT_001eec44 +
                                        ((int)(*(ushort *)(local_18 + 0x4f8) & 0x10) >> 2 |
                                        *(ushort *)(local_18 + 0x4f8) & 3) * 4) << 9;
            }
            *(ushort *)(param_1 + 0x187c + local_44 * 2) =
                 *(ushort *)(param_1 + 0x187c + local_44 * 2) & 0xc003 |
                 (ushort)((uVar13 & 0xffff0fff) << 2);
            bVar5 = bVar6 | bVar14;
            *(byte *)(param_1 + 0x1874) =
                 *(byte *)(param_1 + 0x1874) & 0xbf |
                 (*(byte *)(param_1 + 0x1874) >> 6 & 1 | bVar5) << 6;
            bVar3 = *(byte *)(param_1 + 0x8c);
            bVar10 = (bVar6 | bVar3 >> 4 & 1) << 4;
            bVar6 = (byte)(((uint)bVar14 | (bVar3 & 0xffffe020) >> 5) << 5);
            *(byte *)(param_1 + 0x8c) = bVar3 & 0xcf | bVar10 | bVar6;
            local_34 = (byte)uVar11;
            local_30 = (byte)uVar8;
            local_2c = (byte)uVar9;
            local_28 = (byte)(uVar12 >> 8);
            bVar6 = bVar3 & 0x8f | bVar10 | bVar6 |
                    ((bVar3 & 0x40) >> 6 |
                    bVar5 | *(short *)(local_18 + 0x48c) == 0x2400 & local_34 |
                            *(short *)(local_18 + 0x4b0) == 0x2400 & local_30 |
                            *(short *)(local_18 + 0x4d4) == 0x2400 & local_2c |
                            *(short *)(local_18 + 0x4f8) == 0x2400 & local_28) << 6;
            *(byte *)(param_1 + 0x8c) = bVar6;
          }
          *(byte *)(param_1 + 0x8d) = *(byte *)(param_1 + 0x8d) | 1;
          *(byte *)(param_1 + 0x8c) = bVar6 & 0x7f | (0 < (int)local_44) << 7;
          *(uint *)(param_1 + 0x98 + local_4c * 4) = local_44;
          local_4c = local_4c + 1;
        }
        else {
          if ((local_38 & 1 << ((byte)local_44 & 0x1f)) != 0) goto LAB_000bb184;
LAB_000bb0fb:
          *(undefined4 *)(local_1c + 0x150) = 0;
          pbVar1 = (byte *)(param_1 + 0x187c + local_44 * 2);
          *pbVar1 = *pbVar1 & 0xfd;
          puVar2 = (ushort *)(param_1 + 0x187c + local_44 * 2);
          *puVar2 = *puVar2 & 0xc003;
        }
        local_44 = local_44 + 1;
        local_20 = local_20 + 4;
        local_1c = local_1c + 4;
        local_18 = local_18 + 0xcc;
        local_14 = local_14 + 1;
        if (uVar7 == local_44) goto LAB_000bb08c;
        bVar6 = *(byte *)(param_1 + 0x45);
      } while( true );
    }
    local_4c = 0;
LAB_000bb08c:
    *(int *)(param_1 + 0x94) = local_4c;
  }
  return;
}

/* FUN_000bb46c @ 0xbb46c (1497 bytes) */
int FUN_000bb46c(param_1, param_2, param_3, param_4)
  ushort *param_1;
  byte *param_2;
  undefined4 *param_3;
  undefined4 *param_4;
{
  ushort *puVar1;
  int *piVar2;
  byte bVar3;
  ushort uVar4;
  uint uVar5;
  ushort *puVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  uint uVar10;
  uint uVar11;
  int local_2c;
  int local_28;
  uint local_20;
  uint local_14;
  int *local_10;
  
  if (((param_4 == (undefined4 *)0x0) || (param_4[0xd] != -0x54520ff3)) ||
     (param_3 == (undefined4 *)0x0)) {
    return 0x80000005;
  }
  uVar5 = (uint)((byte)*param_1 & 0xf);
  local_20 = uVar5 + 1;
  iVar7 = -(*param_2 & 7);
  local_14 = iVar7 + 3;
  if (local_14 < 4) {
    uVar8 = local_14;
    if ((*param_2 >> 3 & 1) == 0) {
      local_20 = uVar5 + 2 + (*(ushort *)(param_2 + local_14 * 4 + 8) >> 6 & 0x3f);
      uVar8 = iVar7 + 4;
      if (3 < uVar8) goto LAB_000bb531;
    }
    do {
      local_20 = local_20 + (param_2[uVar8 * 4 + 10] >> 1 & 0x1f) + 2 +
                 (*(ushort *)(param_2 + uVar8 * 4 + 8) >> 6 & 0x3f);
      uVar8 = uVar8 + 1;
    } while (uVar8 < 4);
  }
LAB_000bb531:
  local_10 = (int *)*param_3;
  if (local_10 == (int *)0x0) {
    local_10 = (int *)(*(code *)*param_4)(local_20 * 0x48 + 0x48);
    *local_10 = 0;
    local_10[1] = local_20 + 1;
    *param_3 = local_10;
  }
  else {
    if (*local_10 != 0) {
      return 0x80000006;
    }
    if ((uint)local_10[1] <= local_20) {
      return 0x80000006;
    }
  }
  local_10[2] = 0;
  *(undefined2 *)(local_10 + 5) = 0;
  *(byte *)((int)local_10 + 0xd) = (byte)*param_1 >> 5;
  uVar5 = 0;
  puVar1 = param_1;
  piVar2 = local_10;
  do {
    uVar8 = uVar5;
    puVar6 = puVar1 + 2;
    piVar2[0x12] = 1;
    *(byte *)(piVar2 + 0x14) = (byte)*puVar6 & 0xf;
    *(byte *)((int)piVar2 + 0x51) = (byte)*puVar6 >> 4 & 1;
    *(byte *)((int)piVar2 + 0x52) = *(byte *)((int)puVar1 + 5) >> 4;
    *(byte *)((int)piVar2 + 0x53) = (byte)puVar1[3] & 3;
    *(byte *)(piVar2 + 0x15) = *(byte *)((int)puVar1 + 7) >> 1 & 1;
    *(byte *)((int)piVar2 + 0x55) = *(byte *)((int)puVar1 + 7) >> 3;
    *(ushort *)((int)piVar2 + 0x4e) = puVar1[3] >> 2 & 0x7f;
    *(ushort *)(piVar2 + 0x13) = *puVar6 >> 5 & 0x7f;
    *(undefined1 *)((int)piVar2 + 0x57) = 0;
    *(undefined1 *)((int)piVar2 + 0x56) = 0;
    uVar5 = uVar8 + 1;
    puVar1 = puVar6;
    piVar2 = piVar2 + 0x12;
  } while (uVar5 <= ((byte)*param_1 & 0xf));
  bVar3 = *param_2 >> 3 & 1;
  if (local_14 < 4) {
    local_2c = (uVar8 + 2) * 0x48;
    local_28 = local_2c;
    do {
      uVar8 = *(uint *)(param_2 + local_14 * 4 + 8) >> 0xc & 0x1f;
      uVar5 = (uint)(param_2[local_14 * 4 + 8] & 0x3f);
      uVar4 = *(ushort *)(param_2 + local_14 * 4 + 8);
      if ((bVar3 != 0) &&
         (uVar10 = (param_2[local_14 * 4 + 10] >> 1 & 0x1f) + uVar8, uVar8 <= uVar10)) {
        puVar9 = (undefined4 *)((int)local_10 + local_2c);
        iVar7 = uVar8 << 2;
        uVar11 = uVar8;
        do {
          *puVar9 = 2;
          *(byte *)((int)puVar9 + 0x19) = *(byte *)(iVar7 + 1 + *(int *)(param_2 + 0x1c)) >> 3 & 0xf
          ;
          *(byte *)((int)puVar9 + 0x1a) =
               (byte)(*(uint *)(iVar7 + *(int *)(param_2 + 0x1c)) >> 0xf) & 7;
          *(undefined1 *)((int)puVar9 + 0x1f) = 0;
          *(bool *)(puVar9 + 8) = uVar11 == uVar8;
          *(ushort *)((int)puVar9 + 0xe) =
               (ushort)(*(byte *)(iVar7 + *(int *)(param_2 + 0x1c)) & 0x1f);
          *(ushort *)(puVar9 + 3) = *(ushort *)(iVar7 + *(int *)(param_2 + 0x1c)) >> 6 & 0x1f;
          local_2c = local_2c + 0x48;
          local_28 = local_28 + 0x48;
          uVar11 = uVar11 + 1;
          puVar9 = puVar9 + 0x12;
          iVar7 = iVar7 + 4;
        } while (uVar11 <= uVar10);
      }
      uVar8 = uVar5 + (uVar4 >> 6 & 0x3f);
      if (uVar5 <= uVar8) {
        puVar9 = (undefined4 *)((int)local_10 + local_28);
        iVar7 = uVar5 << 2;
        do {
          *puVar9 = 3;
          *(byte *)(puVar9 + 5) = (byte)(*(ushort *)(*(int *)(param_2 + 0x20) + 2 + iVar7) >> 7) & 7
          ;
          *(byte *)((int)puVar9 + 0x15) = *(byte *)(*(int *)(param_2 + 0x20) + 3 + iVar7) >> 2 & 7;
          *(byte *)((int)puVar9 + 0x16) = *(byte *)(*(int *)(param_2 + 0x20) + 3 + iVar7) >> 5 & 3;
          bVar3 = *(byte *)(*(int *)(param_2 + 0x20) + iVar7) & 0x3f;
          uVar4 = (ushort)bVar3;
          if (0x1f < bVar3) {
            uVar4 = uVar4 - 0x20 | 0x8000;
          }
          *(ushort *)((int)puVar9 + 0xe) = uVar4;
          uVar4 = *(ushort *)(*(int *)(param_2 + 0x20) + iVar7) >> 6 & 0x3f;
          if (0x1f < uVar4) {
            uVar4 = uVar4 - 0x20 | 0x8000;
          }
          *(ushort *)(puVar9 + 4) = uVar4;
          uVar4 = (ushort)(*(uint *)(*(int *)(param_2 + 0x20) + iVar7) >> 0xc) & 0x3f;
          if (0x1f < uVar4) {
            uVar4 = uVar4 - 0x20 | 0x8000;
          }
          *(ushort *)((int)puVar9 + 0x12) = uVar4;
          *(ushort *)(puVar9 + 3) = *(byte *)(*(int *)(param_2 + 0x20) + 2 + iVar7) >> 2 & 0x1f;
          *(byte *)(puVar9 + 8) = *(byte *)(*(int *)(param_2 + 0x24) + 2 + iVar7) >> 7;
          *(byte *)((int)puVar9 + 0x21) = *(byte *)(*(int *)(param_2 + 0x24) + 3 + iVar7) & 1;
          *(byte *)((int)puVar9 + 0x22) = *(byte *)(*(int *)(param_2 + 0x24) + 3 + iVar7) >> 1 & 3;
          *(byte *)((int)puVar9 + 0x23) = *(byte *)(*(int *)(param_2 + 0x24) + 3 + iVar7) >> 3 & 1;
          bVar3 = *(byte *)(*(int *)(param_2 + 0x24) + iVar7) & 0x3f;
          uVar4 = (ushort)bVar3;
          if (0x1f < bVar3) {
            uVar4 = uVar4 - 0x20 | 0x8000;
          }
          *(ushort *)((int)puVar9 + 0x1a) = uVar4;
          uVar4 = *(ushort *)(*(int *)(param_2 + 0x24) + iVar7) >> 6 & 0x3f;
          if (0x1f < uVar4) {
            uVar4 = uVar4 - 0x20 | 0x8000;
          }
          *(ushort *)(puVar9 + 7) = uVar4;
          uVar4 = (ushort)(*(uint *)(*(int *)(param_2 + 0x24) + iVar7) >> 0xc) & 0x3f;
          if (0x1f < uVar4) {
            uVar4 = uVar4 - 0x20 | 0x8000;
          }
          *(ushort *)((int)puVar9 + 0x1e) = uVar4;
          *(ushort *)(puVar9 + 6) = *(byte *)(*(int *)(param_2 + 0x24) + 2 + iVar7) >> 2 & 0x1f;
          *(byte *)((int)puVar9 + 0x2a) = *(byte *)(*(int *)(param_2 + 0x2c) + iVar7) & 0x1f;
          *(byte *)((int)puVar9 + 0x2d) = *(byte *)(*(int *)(param_2 + 0x2c) + iVar7) >> 5 & 3;
          *(byte *)((int)puVar9 + 0x2b) =
               (byte)(*(ushort *)(*(int *)(param_2 + 0x2c) + iVar7) >> 7) & 0x1f;
          *(byte *)((int)puVar9 + 0x2e) = *(byte *)(*(int *)(param_2 + 0x2c) + 1 + iVar7) >> 4 & 3;
          *(byte *)(puVar9 + 0xb) =
               (byte)(*(uint *)(*(int *)(param_2 + 0x2c) + iVar7) >> 0xe) & 0x1f;
          *(byte *)((int)puVar9 + 0x2f) = *(byte *)(*(int *)(param_2 + 0x2c) + 2 + iVar7) >> 3 & 3;
          *(byte *)(puVar9 + 0xc) = *(byte *)(*(int *)(param_2 + 0x2c) + 2 + iVar7) >> 5 & 3;
          *(byte *)((int)puVar9 + 0x31) =
               (byte)(*(ushort *)(*(int *)(param_2 + 0x2c) + 2 + iVar7) >> 7) & 0xf;
          *(byte *)((int)puVar9 + 0x32) = *(byte *)(*(int *)(param_2 + 0x2c) + 3 + iVar7) >> 3 & 7;
          *(byte *)((int)puVar9 + 0x33) = *(byte *)(*(int *)(param_2 + 0x2c) + 3 + iVar7) >> 6 & 1;
          *(byte *)(puVar9 + 0xd) = *(byte *)(*(int *)(param_2 + 0x2c) + 3 + iVar7) >> 7;
          *(byte *)((int)puVar9 + 0x39) = *(byte *)(iVar7 + *(int *)(param_2 + 0x30)) & 0x1f;
          *(byte *)(puVar9 + 0xf) = *(byte *)(iVar7 + *(int *)(param_2 + 0x30)) >> 5 & 3;
          *(byte *)((int)puVar9 + 0x3a) =
               (byte)(*(ushort *)(iVar7 + *(int *)(param_2 + 0x30)) >> 7) & 0x1f;
          *(byte *)((int)puVar9 + 0x3d) = *(byte *)(iVar7 + 1 + *(int *)(param_2 + 0x30)) >> 4 & 3;
          *(byte *)((int)puVar9 + 0x3b) =
               (byte)(*(uint *)(iVar7 + *(int *)(param_2 + 0x30)) >> 0xe) & 0x1f;
          *(byte *)((int)puVar9 + 0x3e) = *(byte *)(iVar7 + 2 + *(int *)(param_2 + 0x30)) >> 3 & 3;
          *(byte *)((int)puVar9 + 0x3f) = *(byte *)(iVar7 + 2 + *(int *)(param_2 + 0x30)) >> 5 & 3;
          *(byte *)(puVar9 + 0x10) =
               (byte)(*(ushort *)(iVar7 + 2 + *(int *)(param_2 + 0x30)) >> 7) & 0xf;
          *(byte *)((int)puVar9 + 0x41) = *(byte *)(iVar7 + 3 + *(int *)(param_2 + 0x30)) >> 3 & 7;
          *(byte *)((int)puVar9 + 0x42) = *(byte *)(iVar7 + 3 + *(int *)(param_2 + 0x30)) >> 6 & 1;
          local_2c = local_2c + 0x48;
          local_28 = local_28 + 0x48;
          uVar5 = uVar5 + 1;
          puVar9 = puVar9 + 0x12;
          iVar7 = iVar7 + 4;
        } while (uVar5 <= uVar8);
      }
      local_14 = local_14 + 1;
      bVar3 = 1;
    } while (local_14 != 4);
  }
  local_10[2] = local_20;
  return 0;
}

/* FUN_000bba45 @ 0xbba45 (3171 bytes) */
int FUN_000bba45(param_1, param_2, param_3)
  int param_1;
  byte *param_2;
  byte *param_3;
{
  byte *pbVar1;
  byte bVar2;
  ushort uVar3;
  undefined2 uVar4;
  uint uVar5;
  bool bVar6;
  bool bVar7;
  byte bVar8;
  int iVar10;
  uint *puVar11;
  byte bVar12;
  int iVar13;
  uint uVar14;
  char local_65;
  byte *local_64;
  int *local_5c;
  char local_54;
  int local_50;
  byte local_4c;
  uint local_3c;
  int local_38;
  uint local_34;
  int local_30;
  uint local_24;
  char local_1d;
  uint *local_1c;
  uint *local_18;
  int *local_14;
  int *local_10;
  short sVar9;
  
  uVar3 = *(ushort *)(param_1 + 0x16);
  uVar4 = *(undefined2 *)(param_1 + 0x22);
  uVar5 = *(uint *)(param_1 + 8);
  local_50 = 4 - (uint)uVar3;
  local_5c = (int *)(param_1 + 0x48);
  if ((*(int *)(param_1 + 0x48) == 1) && (uVar5 != 0)) {
    local_14 = (int *)(param_1 + 0x90);
    iVar10 = 0;
    local_24 = 1;
    local_10 = local_14;
    do {
      if ((local_5c[2] & 0xff00ff00U) != 0) {
        pbVar1 = param_2 + iVar10 * 4 + 4;
        pbVar1[0] = 0;
        pbVar1[1] = 0;
        pbVar1[2] = 0;
        pbVar1[3] = 0;
        bVar2 = *(byte *)(local_5c + 2);
        bVar12 = param_2[iVar10 * 4 + 4];
        param_2[iVar10 * 4 + 4] = bVar12 & 0xf0 | bVar2 & 0xf;
        param_2[iVar10 * 4 + 4] =
             bVar12 & 0xe0 | bVar2 & 0xf | (*(byte *)((int)local_5c + 9) & 1) << 4;
        param_2[iVar10 * 4 + 5] = param_2[iVar10 * 4 + 5] & 0xf | *(char *)((int)local_5c + 10) << 4
        ;
        param_2[iVar10 * 4 + 6] =
             param_2[iVar10 * 4 + 6] & 0xfc | *(byte *)((int)local_5c + 0xb) & 3;
        bVar12 = (*(byte *)(local_5c + 3) & 1) * '\x02';
        bVar2 = param_2[iVar10 * 4 + 7];
        param_2[iVar10 * 4 + 7] = bVar2 & 0xfd | bVar12;
        param_2[iVar10 * 4 + 7] = bVar2 & 5 | bVar12 | *(char *)((int)local_5c + 0xd) << 3;
        *(ushort *)(param_2 + iVar10 * 4 + 4) =
             *(ushort *)(param_2 + iVar10 * 4 + 4) & 0xf01f | (*(byte *)(local_5c + 1) & 0x7f) << 5;
        *(ushort *)(param_2 + iVar10 * 4 + 6) =
             *(ushort *)(param_2 + iVar10 * 4 + 6) & 0xfe03 |
             (*(byte *)((int)local_5c + 6) & 0x7f) << 2;
        iVar10 = iVar10 + 1;
      }
      local_24 = local_24 + 1;
      local_5c = local_14;
      if (*local_10 != 1) break;
      local_14 = local_14 + 0x12;
      local_10 = local_10 + 0x12;
    } while (local_24 <= uVar5);
    if (iVar10 != 0) goto LAB_000bbaa1;
  }
  else {
    local_24 = 1;
  }
  param_2[4] = 0;
  param_2[5] = 0;
  param_2[6] = 0;
  param_2[7] = 0;
  iVar10 = 1;
LAB_000bbaa1:
  param_2[0] = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  bVar12 = (char)iVar10 - 1U & 0xf;
  bVar2 = *param_2;
  *param_2 = bVar2 & 0xf0 | bVar12;
  *param_2 = bVar2 & 0x10 | bVar12 | *(char *)(param_1 + 0xd) << 5;
  param_3[4] = 0;
  param_3[5] = 0;
  param_3[6] = 0;
  param_3[7] = 0;
  local_4c = (byte)uVar4;
  param_3[4] = param_3[4] & 0x80 | local_4c & 0x7f;
  param_3[0] = 0;
  param_3[1] = 0;
  param_3[2] = 0;
  param_3[3] = 0;
  local_54 = (char)uVar3;
  *param_3 = *param_3 & 0xf8 | local_54 - 1U & 7;
  param_3[8] = 0;
  param_3[9] = 0;
  param_3[10] = 0;
  param_3[0xb] = 0;
  param_3[0xc] = 0;
  param_3[0xd] = 0;
  param_3[0xe] = 0;
  param_3[0xf] = 0;
  param_3[0x10] = 0;
  param_3[0x11] = 0;
  param_3[0x12] = 0;
  param_3[0x13] = 0;
  param_3[0x14] = 0;
  param_3[0x15] = 0;
  param_3[0x16] = 0;
  param_3[0x17] = 0;
  param_3[0x18] = 0;
  param_3[0x19] = 0;
  param_3[0x1a] = 0;
  param_3[0x1b] = 0;
  param_3[0x34] = 0;
  param_3[0x35] = 0;
  param_3[0x36] = 0;
  param_3[0x37] = 0;
  param_3[0x34] = param_3[0x34] & 0xfe;
  if (local_24 <= uVar5) {
    local_1c = (uint *)(param_1 + local_24 * 0x48);
    local_18 = local_1c + 0x1a;
    bVar7 = false;
    local_34 = 0;
    local_3c = 0;
    local_30 = 0;
    local_38 = 0;
    bVar12 = 0;
    bVar2 = 0;
    bVar6 = false;
    local_64 = param_3 + local_50 * 4 + 10;
    do {
      while( true ) {
        iVar10 = local_34 + local_30;
        uVar14 = *local_1c;
        if (uVar14 != 2) break;
        if (*(char *)((int)local_1c + 0x1a) == '\0') goto LAB_000bc136;
        iVar13 = (local_3c + local_38) * 4;
        *(undefined4 *)(*(int *)(param_3 + 0x1c) + iVar13) = 0;
        *(uint *)(iVar13 + *(int *)(param_3 + 0x1c)) =
             *(uint *)(iVar13 + *(int *)(param_3 + 0x1c)) & 0xffffffe0 |
             (uint)(*(byte *)((int)local_1c + 0xe) & 0x1f);
        *(uint *)(iVar13 + *(int *)(param_3 + 0x1c)) =
             *(uint *)(iVar13 + *(int *)(param_3 + 0x1c)) & 0xfffff83f |
             (uint)((byte)local_1c[3] & 0x1f) << 6;
        *(uint *)(iVar13 + *(int *)(param_3 + 0x1c)) =
             *(uint *)(iVar13 + *(int *)(param_3 + 0x1c)) & 0xffff87ff |
             (*(byte *)((int)local_1c + 0x19) & 0xf) << 0xb;
        *(uint *)(iVar13 + *(int *)(param_3 + 0x1c)) =
             *(uint *)(iVar13 + *(int *)(param_3 + 0x1c)) & 0xfffc7fff |
             (*(byte *)((int)local_1c + 0x1a) & 7) << 0xf;
        *(uint *)(iVar13 + *(int *)(param_3 + 0x1c)) =
             *(uint *)(iVar13 + *(int *)(param_3 + 0x1c)) & 0xfff7ffff |
             (*(ushort *)((int)local_1c + 0xe) >> 5 & 1) << 0x13;
        *(uint *)(iVar13 + *(int *)(param_3 + 0x1c)) =
             *(uint *)(iVar13 + *(int *)(param_3 + 0x1c)) & 0xffefffff |
             ((ushort)((ushort)local_1c[3] >> 5) & 1) << 0x14;
        if (!bVar6) {
          *param_3 = *param_3 | 8;
          bVar6 = true;
        }
        local_38 = local_38 + 1;
        bVar7 = false;
        if (local_24 != uVar5) goto LAB_000bc142;
LAB_000bc277:
        if (local_38 == 0) {
          local_38 = 1;
          local_1d = '\x01';
          uVar14 = 0;
        }
        else {
          local_1d = (char)local_38;
          uVar14 = local_38 - 1;
        }
        if (local_30 == 0) {
          iVar10 = iVar10 * 4;
          *(undefined4 *)(*(int *)(param_3 + 0x20) + iVar10) = 0;
          *(undefined4 *)(*(int *)(param_3 + 0x24) + iVar10) = 0;
          if (*(int *)(param_3 + 0x28) != 0) {
            *(undefined4 *)(*(int *)(param_3 + 0x28) + iVar10) = 0;
          }
          *(undefined4 *)(*(int *)(param_3 + 0x2c) + iVar10) = 0;
          *(undefined4 *)(*(int *)(param_3 + 0x30) + iVar10) = 0;
          local_30 = 1;
          local_65 = '\x01';
        }
        else {
          local_65 = (char)local_30;
        }
        *(uint *)(local_64 + -2) = *(uint *)(local_64 + -2) & 0xfffe0fff | (local_3c & 0x1f) << 0xc;
        local_64[-2] = local_64[-2] & 0xc0 | (byte)local_34 & 0x3f;
        *local_64 = *local_64 & 0xc1 | (local_1d - 1U & 0x1f) * '\x02';
        *(ushort *)(local_64 + -2) =
             *(ushort *)(local_64 + -2) & 0xf03f | ((byte)(local_65 - 1) & 0x3f) << 6;
        local_64[1] = (byte)(local_3c >> 5) & 0xf | (char)(uVar14 >> 5) << 4;
        if (local_50 == 1) {
          param_3[0x19] = param_3[0x19] & 0x8f | ((byte)(local_34 >> 6) & 7) << 4;
          *(uint *)(param_3 + 0x18) =
               *(uint *)(param_3 + 0x18) & 0xfffc7fff | (local_30 - 1U & 0x1c0) << 9;
        }
        else if (local_50 == 0) {
          *(ushort *)(param_3 + 0x18) =
               *(ushort *)(param_3 + 0x18) & 0xfe3f | (ushort)((local_34 >> 6 & 7) << 6);
          param_3[0x19] = param_3[0x19] & 0xf1 | ((byte)(local_30 - 1U >> 6) & 7) * '\x02';
        }
        else if (local_50 == 2) {
          param_3[0x1a] =
               param_3[0x1a] & 3 | ((byte)(local_34 >> 6) & 7) << 2 |
               (char)(local_30 - 1U >> 6) << 5;
        }
        else if (local_50 == 3) {
          param_3[0x1b] =
               param_3[0x1b] & 0xc0 | (byte)(local_34 >> 6) & 7 |
               ((byte)(local_30 - 1U >> 6) & 7) << 3;
        }
        if (bVar2 != 0) {
          *local_64 = *local_64 | 0x40;
        }
        if (bVar12 != 0) {
          *local_64 = *local_64 | 0x80;
          param_3[0x34] = param_3[0x34] | 1;
        }
        uVar14 = local_3c + local_38;
        if (!bVar6) {
          uVar14 = local_3c;
        }
        local_34 = local_34 + local_30;
        local_50 = local_50 + 1;
        local_64 = local_64 + 4;
        local_30 = 0;
        local_38 = 0;
        bVar12 = 0;
        bVar2 = 0;
        bVar6 = true;
        local_24 = local_24 + 1;
        local_1c = local_1c + 0x12;
        local_18 = local_18 + 0x12;
        local_3c = uVar14;
        if (uVar5 < local_24) {
          return;
        }
      }
      if ((uVar14 < 2) || (4 < uVar14)) goto LAB_000bc136;
      iVar13 = iVar10 * 4;
      *(undefined4 *)(*(int *)(param_3 + 0x20) + iVar13) = 0;
      puVar11 = (uint *)(iVar13 + *(int *)(param_3 + 0x20));
      bVar8 = (byte)*(short *)((int)local_1c + 0xe);
      if (*(short *)((int)local_1c + 0xe) < 0) {
        *puVar11 = *puVar11 & 0xffffffc0 | (uint)(byte)((bVar8 & 0x1f) + 0x20);
        puVar11 = (uint *)(iVar13 + *(int *)(param_3 + 0x20));
        sVar9 = (short)local_1c[4];
        if (sVar9 < 0) goto LAB_000bc69d;
LAB_000bbbe1:
        bVar8 = (byte)sVar9 & 0x1f;
      }
      else {
        *puVar11 = *puVar11 & 0xffffffc0 | (uint)(bVar8 & 0x1f);
        puVar11 = (uint *)(iVar13 + *(int *)(param_3 + 0x20));
        sVar9 = (short)local_1c[4];
        if (-1 < sVar9) goto LAB_000bbbe1;
LAB_000bc69d:
        bVar8 = ((byte)sVar9 & 0x1f) + 0x20;
      }
      *puVar11 = *puVar11 & 0xfffff03f | (uint)bVar8 << 6;
      bVar8 = (byte)*(short *)((int)local_1c + 0x12);
      if (*(short *)((int)local_1c + 0x12) < 0) {
        bVar8 = (bVar8 & 0x1f) + 0x20;
      }
      else {
        bVar8 = bVar8 & 0x1f;
      }
      *(uint *)(iVar13 + *(int *)(param_3 + 0x20)) =
           *(uint *)(iVar13 + *(int *)(param_3 + 0x20)) & 0xfffc0fff | (uint)bVar8 << 0xc;
      *(uint *)(iVar13 + *(int *)(param_3 + 0x20)) =
           *(uint *)(iVar13 + *(int *)(param_3 + 0x20)) & 0xff83ffff |
           (uint)((byte)local_1c[3] & 0x1f) << 0x12;
      *(uint *)(iVar13 + *(int *)(param_3 + 0x20)) =
           *(uint *)(iVar13 + *(int *)(param_3 + 0x20)) & 0xfc7fffff |
           ((byte)local_1c[5] & 7) << 0x17;
      *(uint *)(iVar13 + *(int *)(param_3 + 0x20)) =
           *(uint *)(iVar13 + *(int *)(param_3 + 0x20)) & 0xe3ffffff |
           (*(byte *)((int)local_1c + 0x15) & 7) << 0x1a;
      *(uint *)(iVar13 + *(int *)(param_3 + 0x20)) =
           *(uint *)(iVar13 + *(int *)(param_3 + 0x20)) & 0x9fffffff |
           (*(byte *)((int)local_1c + 0x16) & 3) << 0x1d;
      *(undefined4 *)(*(int *)(param_3 + 0x24) + iVar13) = 0;
      bVar8 = (byte)*(short *)((int)local_1c + 0x1a);
      if (*(short *)((int)local_1c + 0x1a) < 0) {
        bVar8 = (bVar8 & 0x1f) + 0x20;
      }
      else {
        bVar8 = bVar8 & 0x1f;
      }
      *(uint *)(iVar13 + *(int *)(param_3 + 0x24)) =
           *(uint *)(iVar13 + *(int *)(param_3 + 0x24)) & 0xffffffc0 | (uint)bVar8;
      bVar8 = (byte)(short)local_1c[7];
      if ((short)local_1c[7] < 0) {
        bVar8 = (bVar8 & 0x1f) + 0x20;
      }
      else {
        bVar8 = bVar8 & 0x1f;
      }
      *(uint *)(iVar13 + *(int *)(param_3 + 0x24)) =
           *(uint *)(iVar13 + *(int *)(param_3 + 0x24)) & 0xfffff03f | (uint)bVar8 << 6;
      bVar8 = (byte)*(short *)((int)local_1c + 0x1e);
      if (*(short *)((int)local_1c + 0x1e) < 0) {
        bVar8 = (bVar8 & 0x1f) + 0x20;
      }
      else {
        bVar8 = bVar8 & 0x1f;
      }
      *(uint *)(iVar13 + *(int *)(param_3 + 0x24)) =
           *(uint *)(iVar13 + *(int *)(param_3 + 0x24)) & 0xfffc0fff | (uint)bVar8 << 0xc;
      *(uint *)(iVar13 + *(int *)(param_3 + 0x24)) =
           *(uint *)(iVar13 + *(int *)(param_3 + 0x24)) & 0xff83ffff |
           (uint)((byte)local_1c[6] & 0x1f) << 0x12;
      *(uint *)(iVar13 + *(int *)(param_3 + 0x24)) =
           *(uint *)(iVar13 + *(int *)(param_3 + 0x24)) & 0xff7fffff |
           ((byte)local_1c[8] & 1) << 0x17;
      *(uint *)(iVar13 + *(int *)(param_3 + 0x24)) =
           *(uint *)(iVar13 + *(int *)(param_3 + 0x24)) & 0xfeffffff |
           (*(byte *)((int)local_1c + 0x21) & 1) << 0x18;
      *(uint *)(iVar13 + *(int *)(param_3 + 0x24)) =
           *(uint *)(iVar13 + *(int *)(param_3 + 0x24)) & 0xf9ffffff |
           (*(byte *)((int)local_1c + 0x22) & 3) << 0x19;
      *(uint *)(iVar13 + *(int *)(param_3 + 0x24)) =
           *(uint *)(iVar13 + *(int *)(param_3 + 0x24)) & 0xf7ffffff |
           (*(byte *)((int)local_1c + 0x23) & 1) << 0x1b;
      if (*(int *)(param_3 + 0x28) != 0) {
        *(undefined4 *)(*(int *)(param_3 + 0x28) + iVar13) = 0;
        *(uint *)(iVar13 + *(int *)(param_3 + 0x28)) =
             *(uint *)(iVar13 + *(int *)(param_3 + 0x28)) & 0xfffffffe |
             *(ushort *)((int)local_1c + 0xe) >> 5 & 1;
        *(uint *)(iVar13 + *(int *)(param_3 + 0x28)) =
             *(uint *)(iVar13 + *(int *)(param_3 + 0x28)) & 0xfffffffd |
             ((ushort)((ushort)local_1c[4] >> 5) & 1) * 2;
        *(uint *)(iVar13 + *(int *)(param_3 + 0x28)) =
             *(uint *)(iVar13 + *(int *)(param_3 + 0x28)) & 0xfffffffb |
             (*(ushort *)((int)local_1c + 0x12) >> 5 & 1) << 2;
        *(uint *)(iVar13 + *(int *)(param_3 + 0x28)) =
             *(uint *)(iVar13 + *(int *)(param_3 + 0x28)) & 0xfffffff7 |
             ((ushort)((ushort)local_1c[3] >> 5) & 1) << 3;
        *(uint *)(iVar13 + *(int *)(param_3 + 0x28)) =
             *(uint *)(iVar13 + *(int *)(param_3 + 0x28)) & 0xffffffef |
             (*(ushort *)((int)local_1c + 0x1a) >> 5 & 1) << 4;
        *(uint *)(iVar13 + *(int *)(param_3 + 0x28)) =
             *(uint *)(iVar13 + *(int *)(param_3 + 0x28)) & 0xffffffdf |
             ((ushort)((ushort)local_1c[7] >> 5) & 1) << 5;
        *(uint *)(iVar13 + *(int *)(param_3 + 0x28)) =
             *(uint *)(iVar13 + *(int *)(param_3 + 0x28)) & 0xffffffbf |
             (*(ushort *)((int)local_1c + 0x1e) >> 5 & 1) << 6;
        *(uint *)(iVar13 + *(int *)(param_3 + 0x28)) =
             *(uint *)(iVar13 + *(int *)(param_3 + 0x28)) & 0xffffff7f |
             ((ushort)((ushort)local_1c[6] >> 5) & 1) << 7;
      }
      *(undefined4 *)(*(int *)(param_3 + 0x2c) + iVar13) = 0;
      *(uint *)(iVar13 + *(int *)(param_3 + 0x2c)) =
           *(uint *)(iVar13 + *(int *)(param_3 + 0x2c)) & 0xffffffe0 |
           *(byte *)((int)local_1c + 0x2a) & 0x1f;
      *(uint *)(iVar13 + *(int *)(param_3 + 0x2c)) =
           *(uint *)(iVar13 + *(int *)(param_3 + 0x2c)) & 0xffffff9f |
           (*(byte *)((int)local_1c + 0x2d) & 3) << 5;
      *(uint *)(iVar13 + *(int *)(param_3 + 0x2c)) =
           *(uint *)(iVar13 + *(int *)(param_3 + 0x2c)) & 0xfffff07f |
           (*(byte *)((int)local_1c + 0x2b) & 0x1f) << 7;
      *(uint *)(iVar13 + *(int *)(param_3 + 0x2c)) =
           *(uint *)(iVar13 + *(int *)(param_3 + 0x2c)) & 0xffffcfff |
           (*(byte *)((int)local_1c + 0x2e) & 3) << 0xc;
      *(uint *)(iVar13 + *(int *)(param_3 + 0x2c)) =
           *(uint *)(iVar13 + *(int *)(param_3 + 0x2c)) & 0xfff83fff |
           ((byte)local_1c[0xb] & 0x1f) << 0xe;
      *(uint *)(iVar13 + *(int *)(param_3 + 0x2c)) =
           *(uint *)(iVar13 + *(int *)(param_3 + 0x2c)) & 0xffe7ffff |
           (*(byte *)((int)local_1c + 0x2f) & 3) << 0x13;
      *(uint *)(iVar13 + *(int *)(param_3 + 0x2c)) =
           *(uint *)(iVar13 + *(int *)(param_3 + 0x2c)) & 0xff9fffff |
           ((byte)local_1c[0xc] & 3) << 0x15;
      *(uint *)(iVar13 + *(int *)(param_3 + 0x2c)) =
           *(uint *)(iVar13 + *(int *)(param_3 + 0x2c)) & 0xf87fffff |
           (*(byte *)((int)local_1c + 0x31) & 0xf) << 0x17;
      *(uint *)(iVar13 + *(int *)(param_3 + 0x2c)) =
           *(uint *)(iVar13 + *(int *)(param_3 + 0x2c)) & 0xc7ffffff |
           (*(byte *)((int)local_1c + 0x32) & 7) << 0x1b;
      *(uint *)(iVar13 + *(int *)(param_3 + 0x2c)) =
           *(uint *)(iVar13 + *(int *)(param_3 + 0x2c)) & 0xbfffffff |
           (*(byte *)((int)local_1c + 0x33) & 1) << 0x1e;
      *(uint *)(iVar13 + *(int *)(param_3 + 0x2c)) =
           *(uint *)(iVar13 + *(int *)(param_3 + 0x2c)) & 0x7fffffff |
           (uint)(byte)local_1c[0xd] << 0x1f;
      *(undefined4 *)(*(int *)(param_3 + 0x30) + iVar13) = 0;
      *(uint *)(iVar13 + *(int *)(param_3 + 0x30)) =
           *(uint *)(iVar13 + *(int *)(param_3 + 0x30)) & 0xffffffe0 |
           *(byte *)((int)local_1c + 0x39) & 0x1f;
      *(uint *)(iVar13 + *(int *)(param_3 + 0x30)) =
           *(uint *)(iVar13 + *(int *)(param_3 + 0x30)) & 0xffffff9f |
           ((byte)local_1c[0xf] & 3) << 5;
      *(uint *)(iVar13 + *(int *)(param_3 + 0x30)) =
           *(uint *)(iVar13 + *(int *)(param_3 + 0x30)) & 0xfffff07f |
           (*(byte *)((int)local_1c + 0x3a) & 0x1f) << 7;
      *(uint *)(iVar13 + *(int *)(param_3 + 0x30)) =
           *(uint *)(iVar13 + *(int *)(param_3 + 0x30)) & 0xffffcfff |
           (*(byte *)((int)local_1c + 0x3d) & 3) << 0xc;
      *(uint *)(iVar13 + *(int *)(param_3 + 0x30)) =
           *(uint *)(iVar13 + *(int *)(param_3 + 0x30)) & 0xfff83fff |
           (*(byte *)((int)local_1c + 0x3b) & 0x1f) << 0xe;
      *(uint *)(iVar13 + *(int *)(param_3 + 0x30)) =
           *(uint *)(iVar13 + *(int *)(param_3 + 0x30)) & 0xffe7ffff |
           (*(byte *)((int)local_1c + 0x3e) & 3) << 0x13;
      *(uint *)(iVar13 + *(int *)(param_3 + 0x30)) =
           *(uint *)(iVar13 + *(int *)(param_3 + 0x30)) & 0xff9fffff |
           (*(byte *)((int)local_1c + 0x3f) & 3) << 0x15;
      *(uint *)(iVar13 + *(int *)(param_3 + 0x30)) =
           *(uint *)(iVar13 + *(int *)(param_3 + 0x30)) & 0xf87fffff |
           ((byte)local_1c[0x10] & 0xf) << 0x17;
      *(uint *)(iVar13 + *(int *)(param_3 + 0x30)) =
           *(uint *)(iVar13 + *(int *)(param_3 + 0x30)) & 0xc7ffffff |
           (*(byte *)((int)local_1c + 0x41) & 7) << 0x1b;
      *(uint *)(iVar13 + *(int *)(param_3 + 0x30)) =
           *(uint *)(iVar13 + *(int *)(param_3 + 0x30)) & 0xbfffffff |
           (*(byte *)((int)local_1c + 0x42) & 1) << 0x1e;
      bVar2 = bVar2 | *(byte *)((int)local_1c + 0x15) | *(byte *)((int)local_1c + 0x21);
      bVar12 = bVar12 | *(byte *)((int)local_1c + 0x23);
      local_30 = local_30 + 1;
      bVar7 = true;
LAB_000bc136:
      if (local_24 == uVar5) goto LAB_000bc277;
LAB_000bc142:
      if ((local_18[-8] == 2) && ((bVar7 || ((char)*local_18 != '\0')))) goto LAB_000bc277;
      local_24 = local_24 + 1;
      local_1c = local_1c + 0x12;
      local_18 = local_18 + 0x12;
    } while (local_24 <= uVar5);
  }
  return;
}

/* FUN_000bc6a8 @ 0xbc6a8 (144 bytes) */
int FUN_000bc6a8(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  FUN_000c37eb(param_1);
  if (*(ushort *)(param_1 + 0x16) < 5) {
    if (*(ushort *)(param_1 + 0x18) < 0x11) {
      if (*(ushort *)(param_1 + 0x1a) < 0x21) {
        if (*(ushort *)(param_1 + 0x1e) < 0x41) {
          if (*(short *)(param_1 + 0x20) == 0) {
            if (*(ushort *)(param_1 + 0x22) < 0x20) {
              if (*(ushort *)(param_1 + 0x24) < 0x20) {
                ((int (*)())FUN_000bba45)(0);
                uVar1 = 0;
              }
              else {
                uVar1 = 0x80000013;
              }
            }
            else {
              uVar1 = 0x80000012;
            }
          }
          else {
            uVar1 = 0x80000017;
          }
        }
        else {
          uVar1 = 0x80000016;
        }
      }
      else {
        uVar1 = 0x80000015;
      }
    }
    else {
      uVar1 = 0x80000014;
    }
  }
  else {
    uVar1 = 0x80000011;
  }
  return uVar1;
}

/* FUN_000bc738 @ 0xbc738 (1243 bytes) */
int FUN_000bc738(param_1)
  int param_1;
{
  int *piVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  bool bVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  uint *puVar9;
  int iVar10;
  uint *puVar11;
  ushort *puVar12;
  undefined1 *puVar13;
  ushort *puVar14;
  int local_138;
  uint local_134;
  int local_130;
  ushort *local_12c;
  ushort *local_128;
  ushort *local_124;
  ushort *local_120;
  uint *local_11c;
  uint *local_118;
  uint local_110;
  uint local_10c [64];
  
  FUN_000c37eb(param_1);
  if (*(ushort *)(param_1 + 0x16) < 5) {
    if (*(ushort *)(param_1 + 0x18) < 0x11) {
      if (*(ushort *)(param_1 + 0x1a) < 0x201) {
        if (*(ushort *)(param_1 + 0x1e) < 0x201) {
          if (*(short *)(param_1 + 0x20) == 0) {
            if (*(ushort *)(param_1 + 0x22) < 0x40) {
              if (*(ushort *)(param_1 + 0x24) < 0x40) {
                uVar4 = *(uint *)(param_1 + 8);
                iVar8 = 1;
                do {
                  (&local_110)[iVar8] = 0xffffffff;
                  iVar8 = iVar8 + 1;
                } while (iVar8 != 0x41);
                if ((uVar4 != 0) &&
                   (puVar11 = (uint *)(param_1 + 0x48), *(int *)(param_1 + 0x48) == 1)) {
                  local_118 = (uint *)(param_1 + 0x90);
                  local_134 = 1;
                  bVar5 = false;
                  puVar9 = puVar11;
                  local_11c = local_118;
                  do {
                    if ((*(char *)((int)puVar9 + 9) != '\0') &&
                       (uVar6 = puVar9[1],
                       *(undefined4 *)((int)local_10c + (uint)(ushort)uVar6 * 4) = 0,
                       ((ushort)uVar6 & 0x20) != 0)) {
                      bVar5 = true;
                    }
                    if ((*(char *)((int)puVar9 + 0xb) != '\0') &&
                       (uVar3 = *(ushort *)((int)puVar9 + 6),
                       *(undefined4 *)((int)local_10c + (uint)uVar3 * 4) = 0, (uVar3 & 0x20) != 0))
                    {
                      bVar5 = true;
                    }
                    local_134 = local_134 + 1;
                    if (uVar4 < local_134) break;
                    uVar6 = *local_118;
                    local_118 = local_118 + 0x12;
                    puVar9 = local_11c;
                    local_11c = local_11c + 0x12;
                  } while (uVar6 == 1);
                  if (bVar5) {
                    local_138 = 0x20;
                    iVar8 = 0;
                    puVar13 = &STACKARG(0xfffffff4);
                    do {
                      if (*(int *)(puVar13 + -0x80) == 0) {
                        if (*(int *)((int)local_10c + iVar8 * 4) != -1) {
                          iVar10 = (int)local_10c + iVar8 * 4;
                          do {
                            iVar8 = iVar8 + 1;
                            piVar1 = (int *)(iVar10 + 4);
                            iVar10 = iVar10 + 4;
                          } while (*piVar1 != -1);
                        }
                        *(int *)(puVar13 + -0x80) = iVar8;
                        *(int *)((int)local_10c + iVar8 * 4) = local_138;
                      }
                      local_138 = local_138 + 1;
                      puVar13 = puVar13 + 4;
                    } while (local_138 != 0x40);
                    local_12c = (ushort *)(param_1 + 0x66);
                    local_128 = (ushort *)(param_1 + 0x4e);
                    local_124 = (ushort *)(param_1 + 0x4c);
                    local_110 = 1;
                    local_130 = 0;
                    puVar14 = (ushort *)(param_1 + 0x56);
                    local_120 = (ushort *)(param_1 + 0x54);
                    do {
                      uVar6 = *puVar11;
                      if (uVar6 != 2) {
                        if (uVar6 < 3) {
                          if (uVar6 == 1) {
                            if ((*(char *)((int)puVar11 + 9) != '\0') &&
                               (iVar8 = *(int *)((int)local_10c + (uint)*local_124 * 4), iVar8 != -1
                               )) {
                              *local_124 = (ushort)iVar8;
                            }
                            if (*(char *)((int)puVar11 + 0xb) != '\0') {
                              iVar8 = *(int *)((int)local_10c + (uint)*local_128 * 4);
                              puVar12 = local_128;
joined_r0x000bcb92:
                              if (iVar8 != -1) {
                                *puVar12 = (ushort)iVar8;
                              }
                            }
                          }
                        }
                        else if (uVar6 < 5) {
                          if ((char)puVar11[5] != '\0') {
                            puVar12 = (ushort *)(local_130 + param_1 + 0x54);
                            iVar8 = *(int *)((int)local_10c + (uint)*puVar12 * 4);
                            if (iVar8 != -1) {
                              *puVar12 = (ushort)iVar8;
                            }
                          }
                          puVar12 = (ushort *)(local_130 + param_1 + 0x56);
                          uVar3 = *puVar12;
                          if ((-1 < (short)uVar3) &&
                             (iVar8 = *(int *)((int)local_10c + (uint)uVar3 * 4), iVar8 != -1)) {
                            *puVar12 = (ushort)iVar8;
                          }
                          puVar12 = (ushort *)(param_1 + 0x58 + local_130);
                          uVar3 = *puVar12;
                          if ((-1 < (short)uVar3) &&
                             (iVar8 = *(int *)((int)local_10c + (uint)uVar3 * 4), iVar8 != -1)) {
                            *puVar12 = (ushort)iVar8;
                          }
                          puVar12 = (ushort *)(param_1 + 0x5a + local_130);
                          uVar3 = *puVar12;
                          if ((-1 < (short)uVar3) &&
                             (iVar8 = *(int *)((int)local_10c + (uint)uVar3 * 4), iVar8 != -1)) {
                            *puVar12 = (ushort)iVar8;
                          }
                          if ((char)puVar11[8] != '\0') {
                            puVar12 = (ushort *)(param_1 + 0x60 + local_130);
                            iVar8 = *(int *)((int)local_10c + (uint)*puVar12 * 4);
                            if (iVar8 != -1) {
                              *puVar12 = (ushort)iVar8;
                            }
                          }
                          puVar12 = (ushort *)(param_1 + 0x62 + local_130);
                          uVar3 = *puVar12;
                          if ((-1 < (short)uVar3) &&
                             (iVar8 = *(int *)((int)local_10c + (uint)uVar3 * 4), iVar8 != -1)) {
                            *puVar12 = (ushort)iVar8;
                          }
                          puVar12 = (ushort *)(param_1 + 100 + local_130);
                          uVar3 = *puVar12;
                          if ((-1 < (short)uVar3) &&
                             (iVar8 = *(int *)((int)local_10c + (uint)uVar3 * 4), iVar8 != -1)) {
                            *puVar12 = (ushort)iVar8;
                          }
                          if (-1 < (short)*local_12c) {
                            iVar8 = *(int *)((int)local_10c + (uint)*local_12c * 4);
                            puVar12 = local_12c;
                            goto joined_r0x000bcb92;
                          }
                        }
                        goto LAB_000bc9b3;
                      }
                      bVar2 = *(byte *)((int)puVar11 + 0x1a);
                      if (bVar2 == 2) {
LAB_000bcbee:
                        iVar8 = *(int *)((int)local_10c + (uint)*puVar14 * 4);
                        if (iVar8 != -1) {
                          *puVar14 = (ushort)iVar8;
                        }
                      }
                      else if (bVar2 < 3) {
                        if (bVar2 == 1) {
LAB_000bcbd6:
                          iVar8 = *(int *)((int)local_10c + (uint)*local_120 * 4);
                          if (iVar8 != -1) {
                            *local_120 = (ushort)iVar8;
                          }
                          goto LAB_000bcbee;
                        }
                      }
                      else if (bVar2 < 5) goto LAB_000bcbd6;
LAB_000bc9b3:
                      local_110 = local_110 + 1;
                      local_130 = local_130 + 0x48;
                      puVar11 = puVar11 + 0x12;
                      puVar14 = puVar14 + 0x24;
                      local_12c = local_12c + 0x24;
                      local_128 = local_128 + 0x24;
                      local_124 = local_124 + 0x24;
                      local_120 = local_120 + 0x24;
                    } while (local_110 <= uVar4);
                  }
                }
                ((int (*)())FUN_000bba45)(1);
                uVar7 = 0;
              }
              else {
                uVar7 = 0x80000013;
              }
            }
            else {
              uVar7 = 0x80000012;
            }
          }
          else {
            uVar7 = 0x80000017;
          }
        }
        else {
          uVar7 = 0x80000016;
        }
      }
      else {
        uVar7 = 0x80000015;
      }
    }
    else {
      uVar7 = 0x80000014;
    }
  }
  else {
    uVar7 = 0x80000011;
  }
  return uVar7;
}

/* FUN_000bcc13 @ 0xbcc13 (1241 bytes) */
int FUN_000bcc13(param_1, param_2)
  int param_1;
  uint param_2;
{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  char cVar7;
  char cVar8;
  uint uVar9;
  int *piVar10;
  uint uVar11;
  uint *puVar12;
  char cVar13;
  uint uVar14;
  int iVar15;
  undefined1 *puVar16;
  uint local_28;
  uint local_18;
  uint local_14;
  uint local_10;
  
  if (param_2 <= (*(byte *)(param_1 + 0xf) & 0xf)) {
    return;
  }
  uVar3 = *(uint *)(param_1 + 8);
  if ((*(int *)(param_1 + 0x48) == 1) && (uVar3 != 0)) {
    piVar10 = (int *)(param_1 + 0x90);
    local_10 = 1;
    do {
      local_10 = local_10 + 1;
      if (*piVar10 != 1) goto LAB_000bcc45;
      piVar10 = piVar10 + 0x12;
    } while (local_10 <= uVar3);
LAB_000bceb3:
    bVar4 = false;
    bVar1 = 0;
    bVar5 = false;
  }
  else {
    local_10 = 1;
LAB_000bcc45:
    if (uVar3 < local_10) goto LAB_000bceb3;
    puVar12 = (uint *)(param_1 + local_10 * 0x48);
    local_28 = 0;
    bVar4 = false;
    bVar1 = 0;
    bVar5 = false;
    uVar11 = local_10;
    uVar9 = 0;
    do {
      while (uVar14 = uVar9, uVar9 = *puVar12, uVar9 < 5) {
        if (uVar9 < 3) {
          if ((uVar9 == 2) &&
             (bVar1 = bVar1 | (byte)puVar12[1] | *(byte *)((int)puVar12 + 0x1b),
             *(char *)((int)puVar12 + 0x1a) != '\0')) {
            bVar5 = (bool)(bVar5 | (puVar12[7] & 0xffff00) != 0);
          }
        }
        else {
          bVar1 = bVar1 | (byte)puVar12[1];
        }
LAB_000bcc8f:
        uVar11 = uVar11 + 1;
        puVar12 = puVar12 + 0x12;
        uVar9 = uVar14 + 1;
        if (uVar3 < uVar11) goto LAB_000bcd3f;
      }
      if ((uVar9 != 5) || (bVar1 = bVar1 | (byte)puVar12[1], bVar4)) goto LAB_000bcc8f;
      if ((*(char *)((int)puVar12 + 0xe) != '\0') || (*(char *)((int)puVar12 + 0x11) != '\0')) {
        bVar4 = true;
      }
      uVar9 = puVar12[4] & 0xff00ff;
      if ((uVar9 != 0) &&
         (((ushort)puVar12[3] < uVar14 || (*(char *)((int)puVar12 + 0x19) != '\0')))) {
        bVar4 = true;
      }
      cVar7 = (char)puVar12[5];
      cVar8 = *(char *)((int)puVar12 + 0x15);
      cVar13 = cVar7;
      if ((uVar9 != 0) && (cVar13 = cVar8, uVar9 == 0xff0001)) {
        cVar7 = cVar8;
      }
      cVar8 = cVar13;
      if ((cVar7 == '\x01') || (cVar8 = cVar7, cVar7 != '\0')) {
        if (cVar8 == '\x02') goto LAB_000bd0e3;
        if (cVar8 == '\x01') {
          local_28 = local_28 - *(byte *)((int)puVar12 + 0x13);
        }
      }
      else if (cVar13 == '\x02') {
LAB_000bd0e3:
        local_28 = local_28 + 1;
      }
      bVar6 = true;
      if (local_28 < 5) {
        bVar6 = bVar4;
      }
      bVar4 = bVar6;
      uVar11 = uVar11 + 1;
      puVar12 = puVar12 + 0x12;
      uVar9 = uVar14 + 1;
    } while (uVar11 <= uVar3);
LAB_000bcd3f:
    iVar15 = uVar14 + 1;
    if (iVar15 != 0) goto LAB_000bcd48;
  }
  iVar15 = 1;
LAB_000bcd48:
  if ((*(short *)(param_1 + 0x20) == 0) && (*(short *)(param_1 + 0x12) == 0)) {
    *(short *)(param_1 + 0x12) = (short)iVar15 + -1;
  }
  if (bVar4) {
    *(undefined2 *)(param_1 + 0x28) = 1;
  }
  if ((*(short *)(param_1 + 0x28) != 0) && (*(short *)(param_1 + 0x22) == 0)) {
    *(undefined2 *)(param_1 + 0x22) = 1;
  }
  if (local_10 <= uVar3) {
    puVar12 = (uint *)(param_1 + local_10 * 0x48);
    puVar16 = (undefined1 *)((int)puVar12 + -3);
    local_18 = 100000;
    local_14 = 0;
    uVar11 = local_10;
    uVar9 = local_14;
    do {
      while (local_14 = uVar9, uVar9 = *puVar12, uVar14 = local_18, uVar9 < 5) {
        if (uVar9 < 3) {
          if (uVar9 == 2) {
            if (bVar5) {
              bVar2 = *(byte *)((int)puVar12 + 0x1f);
            }
            else {
              *(undefined1 *)((int)puVar12 + 0x1d) = 7;
              *(undefined1 *)((int)puVar12 + 0x1e) = 1;
              *(undefined1 *)((int)puVar12 + 0x15) = 0xe4;
              *(undefined1 *)(puVar12 + 5) = 0xe4;
              bVar2 = *(byte *)((int)puVar12 + 0x1f);
            }
            if (bVar2 != 0) {
              if ((bVar2 & 2) != 0) {
                *(byte *)((int)puVar12 + 0x15) =
                     *(byte *)((int)puVar12 + 0x15) & 0xf3 |
                     (*(byte *)((int)puVar12 + 0x15) & 3) << 2;
              }
              if ((*(byte *)((int)puVar12 + 0x1f) & 4) != 0) {
                *(byte *)((int)puVar12 + 0x15) =
                     *(byte *)((int)puVar12 + 0x15) & 0xcf |
                     (*(byte *)((int)puVar12 + 0x15) & 3) << 4;
              }
              if ((*(byte *)((int)puVar12 + 0x1f) & 8) != 0) {
                *(byte *)((int)puVar12 + 0x15) =
                     *(byte *)((int)puVar12 + 0x15) & 0x3f | *(byte *)((int)puVar12 + 0x15) << 6;
              }
            }
            uVar14 = uVar11;
            if (((bVar1 == 0) && ((char)puVar12[8] != '\0')) && (local_18 != 100000)) {
              iVar15 = param_1 + local_18 * 0x48;
              *(undefined1 *)(iVar15 + 0x1b) = 1;
              *(undefined1 *)(iVar15 + 4) = 1;
              *(undefined1 *)(puVar12 + 1) = 1;
            }
          }
        }
        else {
          if (((*(char *)((int)puVar12 + 0x15) == '\0') && ((puVar12[8] & 0xff00ff00) == 0)) &&
             (local_14 != *(ushort *)(param_1 + 0x12))) {
            *puVar12 = 4;
          }
          if ((bVar1 != 0) || (local_18 == 100000)) goto LAB_000bce1f;
          iVar15 = param_1 + local_18 * 0x48;
          *(undefined1 *)(iVar15 + 0x1b) = 1;
          *(undefined1 *)(iVar15 + 4) = 1;
          *(undefined1 *)(puVar12 + 1) = 1;
          local_18 = 100000;
          uVar14 = local_18;
        }
LAB_000bcdb8:
        local_18 = uVar14;
        uVar11 = uVar11 + 1;
        puVar12 = puVar12 + 0x12;
        puVar16 = puVar16 + 0x48;
        uVar9 = local_14 + 1;
        if (uVar3 < uVar11) goto LAB_000bce38;
      }
      if (uVar9 != 5) goto LAB_000bcdb8;
      if ((bVar1 == 0) && (local_18 != 100000)) {
        iVar15 = param_1 + local_18 * 0x48;
        *(undefined1 *)(iVar15 + 0x1b) = 1;
        *(undefined1 *)(iVar15 + 4) = 1;
        *(undefined1 *)(puVar12 + 1) = 1;
      }
      if ((((byte)(*(byte *)((int)puVar12 + 0x12) & 0xf0) !=
            (byte)(*(byte *)((int)puVar12 + 0x12) * '\x10')) && (local_14 != 0)) &&
         (*(int *)(puVar16 + -0x45) - 3U < 2)) {
        *puVar16 = 1;
        local_18 = 100000;
        uVar14 = local_18;
        goto LAB_000bcdb8;
      }
LAB_000bce1f:
      local_18 = 100000;
      uVar11 = uVar11 + 1;
      puVar12 = puVar12 + 0x12;
      puVar16 = puVar16 + 0x48;
      uVar9 = local_14 + 1;
    } while (uVar11 <= uVar3);
LAB_000bce38:
    if (((local_14 != 0xffffffff) &&
        (piVar10 = (int *)(param_1 + (*(ushort *)(param_1 + 0x12) + local_10) * 0x48), *piVar10 == 3
        )) && (bVar1 == 0)) {
      *(undefined1 *)(piVar10 + 1) = 1;
    }
  }
  if (((bVar5) || (bVar1 != 0)) || (*(short *)(param_1 + 0x20) != 0)) {
    param_2 = param_2 | param_2 << 4;
  }
  *(undefined1 *)(param_1 + 0xf) = (undefined1)param_2;
  return;
}

/* FUN_000bd0ec @ 0xbd0ec (42 bytes) */
int FUN_000bd0ec(param_1, param_2, param_3, param_4)
  uint *param_1;
  undefined4 *param_2;
  undefined4 *param_3;
  undefined4 *param_4;
{
  uint uVar1;
  
  uVar1 = *param_1;
  if ((char)uVar1 < '\0') {
    *param_1 = uVar1 & 0xffffff7f;
  }
  else {
    switch(uVar1) {
    case 0:
      *param_1 = 0;
      *param_2 = 0;
      *param_3 = 1;
      *param_4 = 2;
      return;
    case 1:
      *param_1 = 0;
      *param_2 = 0;
      *param_3 = 0;
      *param_4 = 0;
      return;
    case 2:
      *param_1 = 0;
      *param_2 = 1;
      *param_3 = 1;
      *param_4 = 1;
      return;
    case 3:
      *param_1 = 0;
      *param_2 = 2;
      *param_3 = 2;
      *param_4 = 2;
      return;
    case 4:
      *param_1 = 1;
      *param_2 = 0;
      *param_3 = 1;
      *param_4 = 2;
      return;
    case 5:
      *param_1 = 1;
      *param_2 = 0;
      *param_3 = 0;
      *param_4 = 0;
      return;
    case 6:
      *param_1 = 1;
      *param_2 = 1;
      *param_3 = 1;
      *param_4 = 1;
      return;
    case 7:
      *param_1 = 1;
      *param_2 = 2;
      *param_3 = 2;
      *param_4 = 2;
      return;
    case 8:
      *param_1 = 2;
      *param_2 = 0;
      *param_3 = 1;
      *param_4 = 2;
      return;
    case 9:
      *param_1 = 2;
      *param_2 = 0;
      *param_3 = 0;
      *param_4 = 0;
      return;
    case 10:
      *param_1 = 2;
      *param_2 = 1;
      *param_3 = 1;
      *param_4 = 1;
      return;
    case 0xb:
      *param_1 = 2;
      *param_2 = 2;
      *param_3 = 2;
      *param_4 = 2;
      return;
    case 0xc:
      *param_1 = 0;
      *param_2 = 3;
      *param_3 = 3;
      *param_4 = 3;
      return;
    case 0xd:
      *param_1 = 1;
      *param_2 = 3;
      *param_3 = 3;
      *param_4 = 3;
      return;
    case 0xe:
      *param_1 = 2;
      *param_2 = 3;
      *param_3 = 3;
      *param_4 = 3;
      return;
    case 0xf:
      *param_1 = 3;
      *param_2 = 0;
      *param_3 = 1;
      *param_4 = 2;
      return;
    case 0x10:
      *param_1 = 3;
      *param_2 = 0;
      *param_3 = 0;
      *param_4 = 0;
      return;
    case 0x11:
      *param_1 = 3;
      *param_2 = 1;
      *param_3 = 1;
      *param_4 = 1;
      return;
    case 0x12:
      *param_1 = 3;
      *param_2 = 2;
      *param_3 = 2;
      *param_4 = 2;
      return;
    case 0x13:
      *param_1 = 3;
      *param_2 = 3;
      *param_3 = 3;
      *param_4 = 3;
      return;
    case 0x14:
      *param_1 = 0;
      *param_2 = 4;
      *param_3 = 4;
      *param_4 = 4;
      return;
    case 0x15:
      *param_1 = 0;
      *param_2 = 6;
      *param_3 = 6;
      *param_4 = 6;
      return;
    case 0x16:
      *param_1 = 0;
      *param_2 = 5;
      *param_3 = 5;
      *param_4 = 5;
      return;
    case 0x17:
      *param_1 = 0;
      *param_2 = 1;
      *param_3 = 2;
      *param_4 = 0;
      return;
    case 0x18:
      *param_1 = 1;
      *param_2 = 1;
      *param_3 = 2;
      *param_4 = 0;
      return;
    case 0x19:
      *param_1 = 2;
      *param_2 = 1;
      *param_3 = 2;
      *param_4 = 0;
      return;
    case 0x1a:
      *param_1 = 0;
      *param_2 = 2;
      *param_3 = 0;
      *param_4 = 1;
      return;
    case 0x1b:
      *param_1 = 1;
      *param_2 = 2;
      *param_3 = 0;
      *param_4 = 1;
      return;
    case 0x1c:
      *param_1 = 2;
      *param_2 = 2;
      *param_3 = 0;
      *param_4 = 1;
      return;
    case 0x1d:
      *param_1 = 0;
      *param_2 = 3;
      *param_3 = 2;
      *param_4 = 1;
      return;
    case 0x1e:
      *param_1 = 1;
      *param_2 = 3;
      *param_3 = 2;
      *param_4 = 1;
      return;
    case 0x1f:
      *param_1 = 2;
      *param_2 = 3;
      *param_3 = 2;
      *param_4 = 1;
      return;
    }
  }
  return;
}

/* FUN_000bd578 @ 0xbd578 (40 bytes) */
int FUN_000bd578(param_1, param_2)
  uint *param_1;
  undefined4 *param_2;
{
  uint uVar1;
  
  uVar1 = *param_1;
  if ((char)uVar1 < '\0') {
    *param_1 = uVar1 & 0xffffff7f;
  }
  else {
    switch(uVar1) {
    case 0:
      *param_1 = 0;
      *param_2 = 0;
      return;
    case 1:
      *param_1 = 0;
      *param_2 = 1;
      return;
    case 2:
      *param_1 = 0;
      *param_2 = 2;
      return;
    case 3:
      *param_1 = 1;
      *param_2 = 0;
      return;
    case 4:
      *param_1 = 1;
      *param_2 = 1;
      return;
    case 5:
      *param_1 = 1;
      *param_2 = 2;
      return;
    case 6:
      *param_1 = 2;
      *param_2 = 0;
      return;
    case 7:
      *param_1 = 2;
      *param_2 = 1;
      return;
    case 8:
      *param_1 = 2;
      *param_2 = 2;
      return;
    case 9:
      *param_1 = 0;
      *param_2 = 3;
      return;
    case 10:
      *param_1 = 1;
      *param_2 = 3;
      return;
    case 0xb:
      *param_1 = 2;
      *param_2 = 3;
      return;
    case 0xc:
      *param_1 = 3;
      *param_2 = 0;
      return;
    case 0xd:
      *param_1 = 3;
      *param_2 = 1;
      return;
    case 0xe:
      *param_1 = 3;
      *param_2 = 2;
      return;
    case 0xf:
      *param_1 = 3;
      *param_2 = 3;
      return;
    case 0x10:
      *param_1 = 0;
      *param_2 = 4;
      return;
    case 0x11:
      *param_1 = 0;
      *param_2 = 6;
      return;
    case 0x12:
      *param_1 = 0;
      *param_2 = 5;
      return;
    }
  }
  return;
}

/* FUN_000bd709 @ 0xbd709 (4011 bytes) */
int FUN_000bd709(param_1, param_2, param_3)
  int param_1;
  byte *param_2;
  byte *param_3;
{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  char cVar6;
  undefined1 uVar7;
  byte bVar8;
  byte bVar9;
  byte bVar10;
  byte bVar11;
  byte bVar12;
  byte bVar13;
  byte bVar14;
  byte bVar15;
  byte bVar16;
  ushort uVar17;
  ushort uVar18;
  ushort uVar19;
  ushort uVar20;
  ushort uVar21;
  ushort uVar22;
  uint uVar23;
  uint uVar24;
  bool bVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  byte bVar30;
  int iVar31;
  uint uVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  uint uVar36;
  uint uVar37;
  uint uVar38;
  uint uVar39;
  uint uVar40;
  uint uVar41;
  uint uVar42;
  uint uVar43;
  uint uVar44;
  uint uVar45;
  int iVar46;
  uint uVar47;
  uint uVar48;
  int iVar49;
  int *piVar50;
  byte bStack_6d;
  uint local_40;
  int local_38;
  uint local_30;
  uint *local_2c;
  int local_28;
  int *local_24;
  int *local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  
  FUN_000c37eb(param_1);
  if (0x10 < *(ushort *)(param_1 + 0x18)) {
    return 0x80000014;
  }
  if (0x200 < (uint)*(ushort *)(param_1 + 0x1a) + (uint)*(ushort *)(param_1 + 0x1c) +
              (uint)*(ushort *)(param_1 + 0x20)) {
    return 0x80000018;
  }
  if (0x7f < *(ushort *)(param_1 + 0x22)) {
    return 0x80000012;
  }
  if (0xff < *(ushort *)(param_1 + 0x24)) {
    return 0x80000013;
  }
  ((int (*)())FUN_000bcc13)(param_1,1);
  uVar23 = *(uint *)(param_1 + 8);
  if ((*(int *)(param_1 + 0x48) == 1) && (uVar23 != 0)) {
    local_20 = (int *)(param_1 + 0x90);
    local_30 = 1;
    iVar31 = 0;
    piVar50 = (int *)(param_1 + 0x48);
    local_24 = local_20;
    do {
      if ((piVar50[2] & 0xff00ff00U) != 0) {
        pbVar1 = param_2 + iVar31 * 4 + 4;
        pbVar1[0] = 0;
        pbVar1[1] = 0;
        pbVar1[2] = 0;
        pbVar1[3] = 0;
        bStack_6d = *(byte *)(piVar50 + 2) & 0xf;
        bVar2 = param_2[iVar31 * 4 + 4];
        param_2[iVar31 * 4 + 4] = bVar2 & 0xf0 | bStack_6d;
        param_2[iVar31 * 4 + 4] = bVar2 & 0xe0 | bStack_6d | (*(byte *)((int)piVar50 + 9) & 1) << 4;
        param_2[iVar31 * 4 + 5] = param_2[iVar31 * 4 + 5] & 0xf | *(char *)((int)piVar50 + 10) << 4;
        bStack_6d = *(byte *)((int)piVar50 + 0xb) & 3;
        param_2[iVar31 * 4 + 6] = param_2[iVar31 * 4 + 6] & 0xfc | bStack_6d;
        param_2[iVar31 * 4 + 7] =
             param_2[iVar31 * 4 + 7] & 0xfd | (*(byte *)(piVar50 + 3) & 1) * '\x02';
        *(ushort *)(param_2 + iVar31 * 4 + 4) =
             *(ushort *)(param_2 + iVar31 * 4 + 4) & 0xf01f | (*(byte *)(piVar50 + 1) & 0x7f) << 5;
        *(ushort *)(param_2 + iVar31 * 4 + 6) =
             *(ushort *)(param_2 + iVar31 * 4 + 6) & 0xfe03 |
             (*(byte *)((int)piVar50 + 6) & 0x7f) << 2;
        iVar31 = iVar31 + 1;
      }
      local_30 = local_30 + 1;
      if (*local_20 != 1) break;
      local_20 = local_20 + 0x12;
      piVar50 = local_24;
      local_24 = local_24 + 0x12;
    } while (local_30 <= uVar23);
    if (iVar31 == 0) goto LAB_000bd79a;
  }
  else {
    local_30 = 1;
LAB_000bd79a:
    param_2[4] = 0;
    param_2[5] = 0;
    param_2[6] = 0;
    param_2[7] = 0;
    iVar31 = 1;
  }
  param_2[0] = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  bVar30 = (char)iVar31 - 1U & 0xf;
  bVar2 = *param_2;
  *param_2 = bVar2 & 0xf0 | bVar30;
  *param_2 = bVar2 & 0x10 | bVar30 | *(char *)(param_1 + 0xd) << 5;
  if (uVar23 < local_30) {
    local_38 = 0;
    bVar2 = 0;
    iVar46 = 0;
    iVar49 = 1;
  }
  else {
    local_2c = (uint *)(param_1 + local_30 * 0x48);
    local_38 = 0;
    bVar2 = 0;
    bVar25 = true;
    local_28 = 0;
    iVar31 = local_38;
    do {
      local_38 = iVar31;
      local_40 = 0;
      uVar24 = *local_2c;
      if (uVar24 < 5) {
        if (uVar24 < 3) {
          if (uVar24 == 2) {
            local_40 = ((byte)local_2c[1] & 1) << 2 | 3 | (*(byte *)((int)local_2c + 5) & 7) << 3 |
                       (*(byte *)((int)local_2c + 6) & 1) << 6 |
                       (*(byte *)((int)local_2c + 7) & 7) << 0x19 | ((byte)local_2c[2] & 1) << 0x16
                       | (*(byte *)((int)local_2c + 9) & 1) << 7 |
                       (*(byte *)((int)local_2c + 0xb) & 1) << 10 |
                       (*(byte *)((int)local_2c + 0x1d) & 7) << 0xb |
                       (*(byte *)((int)local_2c + 0x1e) & 1) << 0xe;
            uVar17 = *(ushort *)((int)local_2c + 0xe);
            uVar24 = local_2c[3];
            bVar30 = *(byte *)((int)local_2c + 0x15);
            bVar3 = (byte)local_2c[5];
            uVar26 = local_2c[4];
            uVar18 = *(ushort *)((int)local_2c + 0x12);
            bVar4 = *(byte *)((int)local_2c + 0x16);
            bVar5 = *(byte *)((int)local_2c + 0x17);
            *(uint *)(local_28 + 4 + *(int *)(param_3 + 0x10)) =
                 (*(byte *)((int)local_2c + 0x19) & 0xf) << 0x10 |
                 (*(byte *)((int)local_2c + 0x1a) & 7) << 0x16 | ((byte)local_2c[6] & 1) << 0x1b |
                 ((byte)local_2c[7] & 1) << 0x1a | (*(byte *)((int)local_2c + 0x1b) & 1) << 0x19;
            *(uint *)(local_28 + 8 + *(int *)(param_3 + 0x10)) =
                 uVar17 & 0x7f | uVar17 >> 7 & 0x80 | ((ushort)uVar24 & 0x7f) << 0x10 |
                 ((ushort)uVar24 & 0x4000) << 9 | (bVar30 & 3) << 8 | (bVar30 >> 2 & 3) << 10 |
                 (bVar30 >> 4 & 3) << 0xc | (uint)(bVar30 >> 6) << 0xe | (bVar3 & 3) << 0x18 |
                 (bVar3 >> 2 & 3) << 0x1a | (bVar3 >> 4 & 3) << 0x1c | (uint)(bVar3 >> 6) << 0x1e;
            *(uint *)(local_28 + 0xc + *(int *)(param_3 + 0x10)) =
                 (ushort)uVar26 & 0x7f | (ushort)((ushort)uVar26 >> 7) & 0x80 |
                 (uVar18 & 0x7f) << 0x10 | (uVar18 & 0x4000) << 9 | (bVar4 & 3) << 8 |
                 (bVar4 >> 2 & 3) << 10 | (bVar4 >> 4 & 3) << 0xc | (uint)(bVar4 >> 6) << 0xe |
                 (bVar5 & 3) << 0x18 | (bVar5 >> 2 & 3) << 0x1a | (bVar5 >> 4 & 3) << 0x1c |
                 (uint)(bVar5 >> 6) << 0x1e;
            *(undefined4 *)(local_28 + 0x10 + *(int *)(param_3 + 0x10)) = 0;
            *(undefined4 *)(local_28 + 0x14 + *(int *)(param_3 + 0x10)) = 0;
            bVar25 = true;
          }
        }
        else {
          local_40 = (uint)(*local_2c == 3) | ((byte)local_2c[1] & 1) << 2 |
                     (*(byte *)((int)local_2c + 5) & 7) << 3 |
                     (*(byte *)((int)local_2c + 6) & 1) << 6 |
                     (*(byte *)((int)local_2c + 7) & 7) << 0x19 | ((byte)local_2c[2] & 1) << 0x16 |
                     (*(byte *)((int)local_2c + 9) & 1) << 7 |
                     (*(byte *)((int)local_2c + 10) & 1) << 8 | ((byte)local_2c[5] & 7) << 0xb |
                     ((byte)local_2c[8] & 1) << 0xe | (*(byte *)((int)local_2c + 0x15) & 7) << 0xf |
                     (*(byte *)((int)local_2c + 0x21) & 1) << 0x12 |
                     (*(byte *)((int)local_2c + 0x33) & 1) << 0x13 |
                     (*(byte *)((int)local_2c + 0x42) & 1) << 0x14 | ((byte)local_2c[0xd] & 1) << 9
                     | (*(byte *)((int)local_2c + 0x43) & 1) << 0x15 |
                     ((byte)local_2c[0x11] & 3) << 0x17;
          uVar17 = *(ushort *)((int)local_2c + 0xe);
          uVar18 = (ushort)local_2c[4];
          uVar19 = *(ushort *)((int)local_2c + 0x12);
          uVar24 = local_2c[0xc];
          uVar20 = *(ushort *)((int)local_2c + 0x1a);
          uVar21 = (ushort)local_2c[7];
          uVar22 = *(ushort *)((int)local_2c + 0x1e);
          bVar30 = *(byte *)((int)local_2c + 0x3f);
          local_1c = (uint)*(byte *)((int)local_2c + 0x2a);
          local_10 = (byte)local_2c[9] & 7;
          local_14 = (byte)((byte)local_2c[9] >> 3) & 7;
          local_18 = (ushort)((ushort)local_2c[9] >> 6) & 7;
          ((int (*)())FUN_000bd0ec)(&local_18);
          uVar32 = local_1c & 3;
          uVar33 = local_10 & 7;
          uVar48 = local_14 & 7;
          uVar34 = local_18 & 7;
          local_18 = (uint)*(byte *)((int)local_2c + 0x2b);
          local_14 = *(byte *)((int)local_2c + 0x26) & 7;
          local_10 = *(byte *)((int)local_2c + 0x26) >> 3 & 7;
          local_1c = *(ushort *)((int)local_2c + 0x26) >> 6 & 7;
          ((int (*)())FUN_000bd0ec)(&local_1c);
          uVar35 = local_18 & 3;
          uVar36 = local_14 & 7;
          uVar37 = local_10 & 7;
          uVar38 = local_1c & 7;
          bVar3 = *(byte *)((int)local_2c + 0x2d);
          bVar4 = *(byte *)((int)local_2c + 0x2e);
          bVar5 = *(byte *)((int)local_2c + 0x32);
          bVar8 = *(byte *)((int)local_2c + 0x16);
          bVar9 = *(byte *)((int)local_2c + 0x45);
          local_1c = (uint)*(byte *)((int)local_2c + 0x39);
          local_10 = (uint)*(byte *)((int)local_2c + 0x36);
          ((int (*)())FUN_000bd578)();
          uVar47 = local_1c & 3;
          uVar39 = local_10 & 7;
          local_10 = (uint)*(byte *)((int)local_2c + 0x3a);
          local_1c = (uint)*(byte *)((int)local_2c + 0x37);
          ((int (*)())FUN_000bd578)();
          uVar40 = local_10 & 3;
          uVar41 = local_1c & 7;
          uVar26 = local_2c[0xf];
          bVar10 = *(byte *)((int)local_2c + 0x3d);
          bVar11 = *(byte *)((int)local_2c + 0x41);
          bVar12 = *(byte *)((int)local_2c + 0x22);
          bVar13 = *(byte *)((int)local_2c + 0x23);
          uVar27 = local_2c[0x10];
          uVar28 = local_2c[6];
          bVar14 = *(byte *)((int)local_2c + 0x31);
          uVar29 = local_2c[3];
          local_1c = (uint)(byte)local_2c[0xb];
          local_10 = (byte)local_2c[10] & 7;
          local_14 = (byte)((byte)local_2c[10] >> 3) & 7;
          local_18 = (ushort)((ushort)local_2c[10] >> 6) & 7;
          ((int (*)())FUN_000bd0ec)(&local_18);
          uVar42 = local_1c & 3;
          uVar43 = local_10 & 7;
          uVar44 = local_14 & 7;
          uVar45 = local_18 & 7;
          local_18 = (uint)*(byte *)((int)local_2c + 0x3b);
          local_10 = (uint)(byte)local_2c[0xe];
          ((int (*)())FUN_000bd578)();
          bVar15 = *(byte *)((int)local_2c + 0x2f);
          bVar16 = *(byte *)((int)local_2c + 0x3e);
          *(uint *)(local_28 + 4 + *(int *)(param_3 + 0x10)) =
               (uint)CONCAT21(uVar17 >> 0xf,~-((uVar17 & 0x2000) == 0) & 0x80U | (byte)uVar17 & 0x7f
                             ) | uVar17 >> 5 & 0x200 |
               (uint)(~-((uVar18 & 0x2000) == 0) & 0x80U | (byte)uVar18 & 0x7f) << 10 |
               (uint)(uVar18 >> 0xf) << 0x12 | (uVar18 & 0x4000) << 5 |
               (uint)(~-((uVar19 & 0x2000) == 0) & 0x80U | (byte)uVar19 & 0x7f) << 0x14 |
               (uint)(uVar19 >> 0xf) << 0x1c | (uVar19 & 0x4000) << 0xf | (uint)(byte)uVar24 << 0x1e
          ;
          *(uint *)(local_28 + 8 + *(int *)(param_3 + 0x10)) =
               (uint)CONCAT21(uVar20 >> 0xf,~-((uVar20 & 0x2000) == 0) & 0x80U | (byte)uVar20 & 0x7f
                             ) | uVar20 >> 5 & 0x200 |
               (uint)(~-((uVar21 & 0x2000) == 0) & 0x80U | (byte)uVar21 & 0x7f) << 10 |
               (uint)(uVar21 >> 0xf) << 0x12 | (uVar21 & 0x4000) << 5 |
               (uint)(~-((uVar22 & 0x2000) == 0) & 0x80U | (byte)uVar22 & 0x7f) << 0x14 |
               (uint)(uVar22 >> 0xf) << 0x1c | (uVar22 & 0x4000) << 0xf | (uint)bVar30 << 0x1e;
          *(uint *)(local_28 + 0xc + *(int *)(param_3 + 0x10)) =
               uVar32 | uVar33 << 2 | uVar48 << 5 | uVar34 << 8 | uVar35 << 0xd | uVar36 << 0xf |
               uVar37 << 0x12 | uVar38 << 0x15 | (bVar3 & 3) << 0xb | (bVar4 & 3) << 0x18 |
               (bVar5 & 7) << 0x1a | (bVar8 & 3) << 0x1d | (uint)bVar9 << 0x1f;
          *(uint *)(local_28 + 0x10 + *(int *)(param_3 + 0x10)) =
               uVar47 << 0xc | uVar39 << 0xe | uVar40 << 0x13 | uVar41 << 0x15 |
               ((byte)uVar26 & 3) << 0x11 | (bVar10 & 3) << 0x18 | (bVar11 & 7) << 0x1a |
               (bVar12 & 3) << 0x1d | (uint)bVar13 << 0x1f | (byte)uVar27 & 0xf |
               ((ushort)uVar28 & 0x7f) << 4 | (ushort)((ushort)uVar28 >> 3) & 0x800;
          *(uint *)(local_28 + 0x14 + *(int *)(param_3 + 0x10)) =
               bVar14 & 0xf | ((ushort)uVar29 & 0x7f) << 4 | (ushort)((ushort)uVar29 >> 3) & 0x800 |
               uVar42 << 0xc | uVar43 << 0xe | uVar44 << 0x11 | uVar45 << 0x14 |
               (local_18 & 3) << 0x19 | (local_10 & 7) << 0x1b | (bVar15 & 3) << 0x17 |
               (uint)bVar16 << 0x1e;
          if (*local_2c != 3) goto LAB_000bddea;
          bVar2 = bVar2 | *(byte *)((int)local_2c + 0x23);
          bVar25 = false;
        }
      }
      else if (uVar24 == 5) {
        local_40 = ((byte)local_2c[1] & 1) << 2 | 2 | (*(byte *)((int)local_2c + 5) & 7) << 3 |
                   (*(byte *)((int)local_2c + 6) & 1) << 6 |
                   (*(byte *)((int)local_2c + 0xb) & 1) << 10;
        bVar30 = *(byte *)((int)local_2c + 0x17);
        uVar24 = local_2c[6];
        uVar26 = local_2c[3];
        bVar3 = *(byte *)((int)local_2c + 0x19);
        bVar4 = *(byte *)((int)local_2c + 0xe);
        bVar5 = *(byte *)((int)local_2c + 0xf);
        uVar27 = local_2c[4];
        cVar6 = *(char *)((int)local_2c + 0x11);
        uVar7 = *(undefined1 *)((int)local_2c + 0x12);
        bVar8 = *(byte *)((int)local_2c + 0x13);
        uVar28 = local_2c[5];
        bVar9 = *(byte *)((int)local_2c + 0x15);
        bVar10 = *(byte *)((int)local_2c + 0x16);
        *(undefined4 *)(*(int *)(param_3 + 0x10) + 4 + local_28) = 0;
        *(uint *)(*(int *)(param_3 + 0x10) + 8 + local_28) =
             (uint)CONCAT11(uVar7,bVar4 & 7 | (bVar5 & 1) << 4 | ((byte)uVar27 & 1) << 5 |
                                  cVar6 << 6) | (bVar8 & 0x1f) << 0x10 | ((byte)uVar28 & 3) << 0x18
             | (bVar9 & 3) << 0x1a | (bVar10 & 1) << 0x1c;
        *(uint *)(*(int *)(param_3 + 0x10) + 0xc + local_28) =
             bVar30 & 0x1f | ((byte)uVar24 & 0x1f) << 8 | ((ushort)uVar26 & 0x1ff) << 0x10 |
             (uint)bVar3 << 0x1f;
        *(undefined4 *)(*(int *)(param_3 + 0x10) + 0x10 + local_28) = 0;
        *(undefined4 *)(*(int *)(param_3 + 0x10) + 0x14 + local_28) = 0;
LAB_000bddea:
        bVar25 = false;
      }
      *(uint *)(*(int *)(param_3 + 0x10) + local_28) = local_40;
      iVar31 = local_38 + 1;
      local_30 = local_30 + 1;
      local_2c = local_2c + 0x12;
      local_28 = local_28 + 0x18;
    } while (local_30 <= uVar23);
    if (!bVar25) goto LAB_000bd870;
    iVar46 = iVar31 * 0x18;
    iVar49 = local_38 + 2;
    local_38 = iVar31;
  }
  *(undefined4 *)(*(int *)(param_3 + 0x10) + iVar46) = 0;
  *(undefined4 *)(iVar46 + 4 + *(int *)(param_3 + 0x10)) = 0;
  *(undefined4 *)(iVar46 + 8 + *(int *)(param_3 + 0x10)) = 0;
  *(undefined4 *)(iVar46 + 0xc + *(int *)(param_3 + 0x10)) = 0;
  *(undefined4 *)(iVar46 + 0x10 + *(int *)(param_3 + 0x10)) = 0;
  *(undefined4 *)(iVar46 + 0x14 + *(int *)(param_3 + 0x10)) = 0;
  *(byte *)(iVar46 + *(int *)(param_3 + 0x10)) =
       *(byte *)(iVar46 + *(int *)(param_3 + 0x10)) & 0xfc | 1;
  *(byte *)(iVar46 + *(int *)(param_3 + 0x10)) = *(byte *)(iVar46 + *(int *)(param_3 + 0x10)) | 4;
  iVar31 = iVar49;
  if ((local_38 != 0) && ((uint)*(ushort *)(param_1 + 0x12) == local_38 - 1U)) {
    *(ushort *)(param_1 + 0x12) = *(ushort *)(param_1 + 0x12) + 1;
  }
LAB_000bd870:
  local_38 = iVar31;
  param_3[0xc] = 0;
  param_3[0xd] = 0;
  param_3[0xe] = 0;
  param_3[0xf] = 0;
  *(ushort *)(param_3 + 0xc) = *(ushort *)(param_3 + 0xc) & 0xfe00;
  *(ushort *)(param_3 + 0xe) = *(ushort *)(param_3 + 0xe) & 0xfe00 | (short)local_38 - 1U & 0x1ff;
  param_3[8] = 0;
  param_3[9] = 0;
  param_3[10] = 0;
  param_3[0xb] = 0;
  *(ushort *)(param_3 + 8) = *(ushort *)(param_3 + 8) & 0xfe00 | *(ushort *)(param_1 + 0x10) & 0x1ff
  ;
  *(ushort *)(param_3 + 10) =
       *(ushort *)(param_3 + 10) & 0xfe00 | *(ushort *)(param_1 + 0x12) & 0x1ff;
  param_3[4] = 0;
  param_3[5] = 0;
  param_3[6] = 0;
  param_3[7] = 0;
  param_3[7] = param_3[7] & 0x7f | (char)*(undefined2 *)(param_1 + 0x28) << 7;
  param_3[0] = 0;
  param_3[1] = 0;
  param_3[2] = 0;
  param_3[3] = 0;
  *param_3 = *param_3 & 0x80 | *(byte *)(param_1 + 0x22) & 0x7f;
  param_3[0x14] = 0;
  param_3[0x15] = 0;
  param_3[0x16] = 0;
  param_3[0x17] = 0;
  param_3[0x14] = param_3[0x14] & 0xfe | bVar2 != 0;
  return 0;
}

/* FUN_000be6b4 @ 0xbe6b4 (1607 bytes) */
int FUN_000be6b4(param_1)
  int param_1;
{
  ushort uVar1;
  short sVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  ushort uVar6;
  ushort *puVar7;
  int iVar8;
  ushort uVar9;
  ushort uVar10;
  undefined4 *puVar11;
  int iVar12;
  ushort uVar13;
  ushort *local_44;
  int local_40;
  uint local_38;
  int local_34;
  undefined4 local_2c;
  ushort local_26;
  ushort local_24;
  ushort local_22;
  int local_20;
  int local_18;
  int local_14;
  
  local_20 = 0;
  local_34 = 0;
  local_22 = 0;
  local_14 = 0;
  do {
    iVar12 = param_1 + local_14 * 0x40;
    *(undefined4 *)(iVar12 + 0x14) = 0;
    *(undefined4 *)(iVar12 + 0x18) = 0;
    *(undefined4 *)(iVar12 + 0x1c) = 0;
    *(undefined4 *)(iVar12 + 0x20) = 0;
    *(undefined4 *)(iVar12 + 0x24) = 0;
    uVar4 = *(uint *)(iVar12 + 0x30) & 0xffffff89;
    *(uint *)(iVar12 + 0x30) = uVar4;
    if (*(short *)(iVar12 + 0x28) == 2) {
      *(uint *)(iVar12 + 0x30) = uVar4 | 0x52;
      local_20 = iVar12;
    }
    if (*(short *)(iVar12 + 0x28) == 0xd) {
      local_34 = local_14 + 1;
    }
    local_40 = local_14 + 1;
    local_38 = 0;
    local_44 = (ushort *)(iVar12 + 8);
    local_18 = iVar12;
    do {
      uVar1 = *local_44;
      uVar6 = uVar1 & 3;
      uVar13 = local_44[1];
      local_2c = CONCAT22(uVar13,uVar13) & 0x300001f;
      if ((uVar13 & 0x300) == 0x300) {
        *(uint *)(iVar12 + 0x30) = *(uint *)(iVar12 + 0x30) | 0x10;
      }
      if (*(short *)(iVar12 + 0x28) == 3) {
        uVar4 = uVar13 & 0x1f;
        if ((uVar4 | 0xfffffff9) == 0xffffffff) {
          uVar4 = 4 - (local_38 < 2);
          uVar9 = (ushort)uVar4;
          if ((*(unsigned short *)((unsigned char *)&(local_2c) + 2)) == 0x200) {
            uVar9 = (ushort)((uVar4 & 1) << 2) | (ushort)((int)(uVar4 & 6) >> 1);
          }
          else if ((*(unsigned short *)((unsigned char *)&(local_2c) + 2)) == 0x300) {
            uVar9 = (uVar9 & 2) * 2 | (ushort)((uVar4 & 1) << 3) | (ushort)((int)(uVar4 & 4) >> 1);
          }
          else if ((*(unsigned short *)((unsigned char *)&(local_2c) + 2)) == 0x100) {
            uVar9 = (uVar9 & 3) * 2 | (ushort)((int)(uVar4 & 4) >> 2);
          }
          (*(unsigned short *)((unsigned char *)&(local_2c) + 0)) = (ushort)local_2c & uVar9;
          uVar4 = (uint)(ushort)local_2c;
        }
      }
      else {
        uVar4 = uVar13 & 0x1f;
      }
      puVar7 = (ushort *)(local_18 + 0x34);
      *(undefined2 *)(local_18 + 0x34) = 0;
      if ((uVar4 & 0x10) == 0) {
        if ((*(unsigned short *)((unsigned char *)&(local_2c) + 2)) == 0) {
          if (((*(ushort *)(iVar12 + 6) | *(ushort *)(iVar12 + 2)) & 0xffef & ~uVar4) != 0) {
            *(undefined2 *)(local_18 + 0x34) = 8;
          }
        }
        else {
          *(undefined2 *)(local_18 + 0x34) = 8;
        }
      }
      if (uVar6 == 3) {
        local_22 = local_22 | uVar1 & 0x300;
        iVar8 = ((uVar1 & 0x300) >> 8) - 1;
        sVar2 = *(short *)(iVar8 * 0x40 + 0x2a + param_1);
        if (local_14 != iVar8) {
          *(uint *)(iVar12 + 0x30) = *(uint *)(iVar12 + 0x30) | 0x20;
        }
        *puVar7 = *puVar7 | 0x10;
        local_26 = 0;
        local_24 = (ushort)((ushort)(sVar2 - 1U) < 2);
      }
      else {
        local_26 = uVar6;
        local_24 = uVar6;
        if ((ushort)local_2c == 0x11) {
          *puVar7 = *puVar7 | 4;
        }
        else if ((ushort)local_2c == 0x12) {
          *puVar7 = *puVar7 | 2;
        }
        else if ((ushort)local_2c == 0x10) {
          *puVar7 = *puVar7 | 1;
        }
      }
      if ((uVar13 & 0x1000) != 0) {
        *puVar7 = *puVar7 | 0x20;
      }
      if ((uVar13 & 0x2000) != 0) {
        *puVar7 = *puVar7 | 0x40;
      }
      iVar8 = local_20;
      if ((local_14 == 1) && (iVar8 = 0, local_38 != 2)) {
        iVar8 = local_20;
      }
      local_20 = iVar8;
      if ((uVar1 & 0x100) != 0) {
        uVar13 = (ushort)(local_2c & 7);
        if ((~(local_2c & 7) & 6) == 0) {
          uVar9 = *(ushort *)(iVar12 + 6) | *(ushort *)(iVar12 + 2);
          uVar4 = (uint)uVar9;
          uVar10 = uVar9 & 0xffef;
          if ((*(unsigned short *)((unsigned char *)&(local_2c) + 2)) == 0x200) {
            uVar10 = (ushort)((uVar4 & 1) << 2) | (ushort)((int)(uVar4 & 6) >> 1);
          }
          else if ((*(unsigned short *)((unsigned char *)&(local_2c) + 2)) == 0x300) {
            uVar10 = (uVar9 & 2) * 2 | (ushort)((int)(uVar4 & 4) >> 1);
          }
          else if ((*(unsigned short *)((unsigned char *)&(local_2c) + 2)) == 0x100) {
            uVar10 = (uVar9 & 3) * 2 | (ushort)((int)(uVar4 & 4) >> 2);
          }
          if ((*(ushort *)(iVar12 + 0x28) < 9) &&
             ((1 << ((byte)*(undefined2 *)(iVar12 + 0x28) & 0x1f) & 0x1f1U) != 0)) {
            uVar13 = uVar10 & uVar13;
          }
        }
        uVar4 = (uint)local_26;
        puVar7 = (ushort *)(iVar12 + 0x14 + uVar4 * 2);
        *puVar7 = *puVar7 | uVar13;
        if (local_20 != 0) {
          puVar7 = (ushort *)(local_20 + 0x14 + uVar4 * 2);
          *puVar7 = *puVar7 | uVar13;
        }
        if (uVar6 == 3) {
          uVar5 = (uint)local_24;
          puVar7 = (ushort *)(iVar12 + 0x14 + uVar5 * 2);
          *puVar7 = *puVar7 | uVar13;
          puVar7 = (ushort *)(iVar12 + 0x20 + uVar4 * 2);
          *puVar7 = *puVar7 | uVar13;
          puVar7 = (ushort *)(iVar12 + 0x20 + uVar5 * 2);
          *puVar7 = *puVar7 | uVar13;
          if (local_20 != 0) {
            puVar7 = (ushort *)(local_20 + 0x14 + uVar5 * 2);
            *puVar7 = *puVar7 | uVar13;
            puVar7 = (ushort *)(local_20 + 0x20 + uVar4 * 2);
            *puVar7 = *puVar7 | uVar13;
            puVar7 = (ushort *)(local_20 + 0x20 + uVar5 * 2);
            *puVar7 = *puVar7 | uVar13;
          }
        }
      }
      if ((uVar1 & 0x200) != 0) {
        (*(unsigned short *)((unsigned char *)&(local_2c) + 0)) = (ushort)local_2c & 8;
        if (((((*(unsigned short *)((unsigned char *)&(local_2c) + 2)) == 0x300) && (*(ushort *)(iVar12 + 0x28) < 9)) &&
            ((1 << ((byte)*(undefined2 *)(iVar12 + 0x28) & 0x1f) & 0x1f1U) != 0)) &&
           (((*(ushort *)(iVar12 + 6) | *(ushort *)(iVar12 + 2)) & 1) == 0)) {
          (*(unsigned short *)((unsigned char *)&(local_2c) + 0)) = 0;
        }
        uVar4 = (uint)local_26;
        puVar7 = (ushort *)(iVar12 + 0x1a + uVar4 * 2);
        *puVar7 = *puVar7 | (ushort)local_2c;
        if (local_20 != 0) {
          puVar7 = (ushort *)(local_20 + 0x1a + uVar4 * 2);
          *puVar7 = *puVar7 | (ushort)local_2c;
        }
        if (uVar6 == 3) {
          uVar5 = (uint)local_24;
          puVar7 = (ushort *)(iVar12 + 0x1a + uVar5 * 2);
          *puVar7 = *puVar7 | (ushort)local_2c;
          puVar7 = (ushort *)(iVar12 + 0x24 + uVar4 * 2);
          *puVar7 = *puVar7 | (ushort)local_2c;
          puVar7 = (ushort *)(iVar12 + 0x24 + uVar5 * 2);
          *puVar7 = *puVar7 | (ushort)local_2c;
          if (local_20 != 0) {
            puVar7 = (ushort *)(local_20 + 0x1a + uVar5 * 2);
            *puVar7 = *puVar7 | (ushort)local_2c;
            puVar7 = (ushort *)(local_20 + 0x24 + uVar4 * 2);
            *puVar7 = *puVar7 | (ushort)local_2c;
            puVar7 = (ushort *)(local_20 + 0x24 + uVar5 * 2);
            *puVar7 = *puVar7 | (ushort)local_2c;
          }
        }
      }
      local_38 = local_38 + 1;
      local_44 = local_44 + 2;
      local_18 = local_18 + 2;
    } while (local_38 != 3);
    local_14 = local_40;
  } while (local_40 != 2);
  if (local_34 == 1) {
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x54);
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x58);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x5c);
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x60);
    *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 100);
    *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 4;
  }
  else if (local_34 == 2) {
    *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_1 + 0x14);
    *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_1 + 0x18);
    *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)(param_1 + 0x1c);
    *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(param_1 + 0x20);
    *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x24);
    *(uint *)(param_1 + 0x70) = *(uint *)(param_1 + 0x70) | 4;
  }
  iVar8 = 2;
  iVar12 = param_1;
  do {
    if ((*(short *)(iVar12 + 2) == 0 && *(short *)(iVar12 + 6) == 0) &&
       ((*(uint *)(iVar12 + 0x30) & 1) == 0)) {
      *(uint *)(iVar12 + 0x30) = *(uint *)(iVar12 + 0x30) & 0xfffffffb;
    }
    iVar12 = iVar12 + 0x40;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  iVar8 = 0;
  puVar11 = (undefined4 *)(param_1 + 0x14);
  iVar12 = param_1;
  do {
    iVar8 = iVar8 + 1;
    if (((uint)local_22 & iVar8 * 0x100) == 0) {
      *(undefined2 *)((int)puVar11 + 0x16) = 0;
    }
    if ((*(short *)((int)puVar11 + -0x12) == 0 && *(short *)((int)puVar11 + -0xe) == 0) &&
       (uVar4 = puVar11[7], (uVar4 & 1) == 0)) {
      *puVar11 = 0;
      puVar11[1] = 0;
      puVar11[2] = 0;
      puVar11[3] = 0;
      puVar11[4] = 0;
      puVar11[7] = uVar4 & 0xfffffff7;
      puVar11[6] = 0x3f800000;
      if ((*(byte *)(iVar12 + 0x70) & 6) == 0) {
        puVar11[7] = uVar4 & 0xffffffe5;
        *(undefined2 *)(puVar11 + 9) = 1;
        *(undefined2 *)((int)puVar11 + 0x22) = 1;
        *(undefined2 *)(puVar11 + 8) = 1;
        uVar3 = DAT_001eec68;
        puVar11[-1] = DAT_001eec68;
        puVar11[-2] = uVar3;
        puVar11[-3] = uVar3;
        *(undefined2 *)(puVar11 + 5) = 0;
      }
    }
    puVar11 = puVar11 + 0x10;
    iVar12 = iVar12 + -0x40;
  } while (iVar8 != 2);
  iVar8 = 2;
  iVar12 = param_1;
  do {
    if (((*(short *)(iVar12 + 2) != 0 || *(short *)(iVar12 + 6) != 0) ||
        ((*(byte *)(iVar12 + 0x30) & 1) != 0)) &&
       ((*(short *)(param_1 + 0x1a) != 0 || *(short *)(param_1 + 0x1c) != 0) ||
        *(short *)(param_1 + 0x1e) != 0)) {
      *(uint *)(iVar12 + 0x30) = *(uint *)(iVar12 + 0x30) | 2;
    }
    iVar12 = iVar12 + 0x40;
    param_1 = param_1 + 0x3a;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  return;
}

/* FUN_000becfb @ 0xbecfb (1769 bytes) */
int FUN_000becfb(param_1)
  int param_1;
{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  undefined2 uVar4;
  uint uVar5;
  undefined4 uVar6;
  bool bVar7;
  ushort uVar8;
  uint uVar9;
  int iVar10;
  short *psVar11;
  int iVar12;
  int iVar13;
  ushort *puVar14;
  int local_70;
  ushort uStack_2e;
  int local_2c;
  int local_28;
  int local_24;
  
  bVar7 = false;
  local_24 = 1;
  iVar10 = param_1;
  do {
    if ((*(short *)(iVar10 + 0x82) != -1) &&
       (*(short *)(iVar10 + 0x82) == *(short *)(iVar10 + 0x80))) {
      uVar2 = (ushort)(local_24 << 8) | 1;
      local_70 = 0;
      do {
        iVar12 = param_1 + local_70;
        iVar13 = 3;
        do {
          if (uVar2 == *(ushort *)(iVar12 + 8)) {
            *(ushort *)(iVar12 + 8) = uVar2 ^ 1;
            bVar7 = true;
          }
          iVar12 = iVar12 + 4;
          iVar13 = iVar13 + -1;
        } while (iVar13 != 0);
        local_70 = local_70 + 0x40;
      } while (local_70 != 0x80);
    }
    sVar1 = *(short *)(iVar10 + 0x84);
    if (sVar1 != -1) {
      if (sVar1 == *(short *)(iVar10 + 0x80)) {
        uVar2 = (ushort)(local_24 << 8);
        local_70 = 0;
        do {
          iVar12 = param_1 + local_70;
          iVar13 = 3;
          do {
            if ((uVar2 | 2) == *(ushort *)(iVar12 + 8)) {
              *(ushort *)(iVar12 + 8) = (uVar2 | 2) ^ 2;
              bVar7 = true;
            }
            iVar12 = iVar12 + 4;
            iVar13 = iVar13 + -1;
          } while (iVar13 != 0);
          local_70 = local_70 + 0x40;
        } while (local_70 != 0x80);
      }
      else if (sVar1 == *(short *)(iVar10 + 0x82)) {
        uVar2 = (ushort)(local_24 << 8) | 2;
        local_70 = 0;
        do {
          iVar12 = param_1 + local_70;
          iVar13 = 3;
          do {
            if (uVar2 == *(ushort *)(iVar12 + 8)) {
              *(ushort *)(iVar12 + 8) = uVar2 ^ 3;
              bVar7 = true;
            }
            iVar12 = iVar12 + 4;
            iVar13 = iVar13 + -1;
          } while (iVar13 != 0);
          local_70 = local_70 + 0x40;
        } while (local_70 != 0x80);
      }
    }
    local_24 = local_24 + 1;
    iVar10 = iVar10 + 6;
  } while (local_24 != 3);
  if (bVar7) {
    ((int (*)())FUN_000be6b4)(param_1);
    iVar12 = 0;
    iVar10 = param_1 + 0x10;
    do {
      psVar11 = (short *)(iVar10 + 4);
      iVar13 = 3;
      do {
        if (*psVar11 == 0 && psVar11[0x20] == 0) {
          psVar11[0x36] = -1;
        }
        psVar11 = psVar11 + 1;
        iVar13 = iVar13 + -1;
      } while (iVar13 != 0);
      iVar12 = iVar12 + 1;
      iVar10 = iVar10 + 6;
    } while (iVar12 != 2);
  }
  bVar7 = false;
  uStack_2e = 0;
  local_28 = 0;
  do {
    iVar10 = local_28 + param_1;
    uVar5 = *(uint *)(iVar10 + 0x30);
    uVar9 = CONCAT22((short)(uVar5 >> 0x10),(ushort)(byte)uVar5);
    *(uint *)(iVar10 + 0x30) = uVar9;
    if ((*(ushort *)(iVar10 + 2) != 0 || *(ushort *)(iVar10 + 6) != 0) || ((uVar5 & 1) != 0)) {
      if ((*(short *)(iVar10 + 0x28) == 5) &&
         ((*(short *)(iVar10 + 8) == *(short *)(iVar10 + 0xc) &&
          ((*(ushort *)(iVar10 + 10) ^ *(ushort *)(iVar10 + 0xe)) == 0x1000)))) {
        *(undefined2 *)(iVar10 + 0x28) = 0;
        *(ushort *)(iVar10 + 0x34) = *(ushort *)(iVar10 + 0x34) & 0xffdf | 0x40;
        *(ushort *)(iVar10 + 10) = *(ushort *)(iVar10 + 10) & 0xefff | 0x2000;
        *(undefined2 *)(iVar10 + 0x36) = 2;
        *(undefined4 *)(iVar10 + 0xc) = DAT_001eec64;
        *(undefined2 *)(iVar10 + 0x38) = 1;
        *(undefined4 *)(iVar10 + 0x10) = DAT_001eec68;
        bVar7 = true;
      }
      if ((((*(short *)(iVar10 + 0x28) == 7) && (*(short *)(iVar10 + 8) == *(short *)(iVar10 + 0xc))
           ) && (*(int *)(iVar10 + 8) == *(int *)(iVar10 + 0x10))) &&
         ((*(ushort *)(iVar10 + 10) ^ *(ushort *)(iVar10 + 0xe)) == 0x1000)) {
        *(undefined2 *)(iVar10 + 0x28) = 0;
        *(ushort *)(iVar10 + 0x34) = *(ushort *)(iVar10 + 0x34) & 0xffdf | 0x40;
        *(ushort *)(iVar10 + 10) = *(ushort *)(iVar10 + 10) & 0xefff | 0x2000;
        *(undefined2 *)(iVar10 + 0x36) = 2;
        *(undefined4 *)(iVar10 + 0xc) = DAT_001eec64;
        *(undefined2 *)(iVar10 + 0x38) = 1;
        *(undefined4 *)(iVar10 + 0x10) = DAT_001eec68;
        bVar7 = true;
      }
      if (*(short *)(iVar10 + 0x28) == 0) {
        if (((*(ushort *)(iVar10 + 0x34) | *(ushort *)(iVar10 + 0x36)) & 1) == 0) {
          if ((*(ushort *)(iVar10 + 8) & 0x300) != 0) goto LAB_000bedf8;
LAB_000bf090:
          if ((*(ushort *)(iVar10 + 0x36) & 2) != 0) goto LAB_000bedf8;
          uVar4 = *(undefined2 *)(iVar10 + 0x34);
          uVar6 = *(undefined4 *)(iVar10 + 8);
          *(ushort *)(iVar10 + 0x34) = *(ushort *)(iVar10 + 0x36);
          *(undefined4 *)(iVar10 + 8) = *(undefined4 *)(iVar10 + 0xc);
          *(undefined2 *)(iVar10 + 0x36) = uVar4;
          *(undefined4 *)(iVar10 + 0xc) = uVar6;
          if ((*(byte *)(iVar10 + 0x36) & 0x20) != 0) goto LAB_000bf068;
LAB_000bee02:
          uVar2 = *(ushort *)(iVar10 + 0x38);
        }
        else {
          *(undefined2 *)(iVar10 + 0x34) = *(undefined2 *)(iVar10 + 0x38);
          *(undefined4 *)(iVar10 + 8) = *(undefined4 *)(iVar10 + 0x10);
          *(undefined2 *)(iVar10 + 0x36) = 2;
          *(undefined4 *)(iVar10 + 0xc) = DAT_001eec64;
          *(undefined2 *)(iVar10 + 0x38) = 1;
          *(undefined4 *)(iVar10 + 0x10) = DAT_001eec68;
          bVar7 = true;
          if ((*(ushort *)(iVar10 + 8) & 0x300) == 0) goto LAB_000bf090;
LAB_000bedf8:
          if ((*(byte *)(iVar10 + 0x36) & 0x20) == 0) goto LAB_000bee02;
LAB_000bf068:
          *(ushort *)(iVar10 + 0x34) = *(ushort *)(iVar10 + 0x34) ^ 0x20;
          *(ushort *)(iVar10 + 0x36) = *(ushort *)(iVar10 + 0x36) ^ 0x20;
          *(ushort *)(iVar10 + 10) = *(ushort *)(iVar10 + 10) ^ 0x1000;
          *(ushort *)(iVar10 + 0xe) = *(ushort *)(iVar10 + 0xe) ^ 0x1000;
          uVar2 = *(ushort *)(iVar10 + 0x38);
        }
        if ((uVar2 & 1) == 0) {
          if (((*(ushort *)(iVar10 + 0x36) & 2) == 0) || ((*(ushort *)(iVar10 + 8) & 0x300) != 0)) {
            iVar12 = *(int *)(iVar10 + 8);
          }
          else {
            uVar8 = *(ushort *)(iVar10 + 0x34);
            uVar6 = *(undefined4 *)(iVar10 + 8);
            *(ushort *)(iVar10 + 0x34) = uVar2;
            iVar12 = *(int *)(iVar10 + 0x10);
            *(int *)(iVar10 + 8) = iVar12;
            *(ushort *)(iVar10 + 0x38) = uVar8;
            *(undefined4 *)(iVar10 + 0x10) = uVar6;
            if ((uVar8 & 1) != 0) goto LAB_000bee0f;
          }
          if (((iVar12 == *(int *)(iVar10 + 0x10)) && ((*(ushort *)(iVar10 + 0x36) & 2) != 0)) &&
             (*(float *)(iVar10 + 0x2c) <= FLOAT_001c5bc8 &&
              FLOAT_001c5bc8 != *(float *)(iVar10 + 0x2c))) {
            *(undefined2 *)(iVar10 + 0x38) = 1;
            *(undefined4 *)(iVar10 + 0x10) = DAT_001eec68;
            *(float *)(iVar10 + 0x2c) = *(float *)(iVar10 + 0x2c) + *(float *)(iVar10 + 0x2c);
            bVar7 = true;
          }
        }
LAB_000bee0f:
        if ((uVar5 & 8) == 0) {
          if ((FLOAT_001c5ba4 == *(float *)(iVar10 + 0x2c)) &&
             (!NAN(FLOAT_001c5ba4) && !NAN(*(float *)(iVar10 + 0x2c)))) {
            uVar2 = *(ushort *)(iVar10 + 0x34);
            if (((((uVar2 | *(ushort *)(iVar10 + 0x36)) & 0x18) == 0) &&
                ((*(byte *)(iVar10 + 0x38) & 1) != 0)) &&
               (((((byte)*(ushort *)(iVar10 + 0x36) ^ (byte)uVar2) & 0x40) == 0 ||
                ((*(ushort *)(iVar10 + 0xc) & 0x300) == 0)))) {
              *(uint *)(iVar10 + 0x30) = uVar9 | 0x100;
              if ((uVar2 & 0x40) != 0) {
                *(uint *)(iVar10 + 0x30) = uVar9 | 0x1100;
              }
              if ((*(byte *)(iVar10 + 0x34) & 0x20) == 0) {
                uVar9 = *(uint *)(iVar10 + 0x30);
              }
              else {
                uVar9 = *(uint *)(iVar10 + 0x30) | 0x800;
                *(uint *)(iVar10 + 0x30) = uVar9;
              }
            }
            if (((((byte)uVar2 | (byte)*(undefined2 *)(iVar10 + 0x38)) & 0x18) == 0) &&
               ((*(byte *)(iVar10 + 0x36) & 2) != 0)) {
              uVar9 = uVar9 | 0x200;
              *(uint *)(iVar10 + 0x30) = uVar9;
            }
            if ((uVar9 | 0xfffffcff) == 0xffffffff) {
              *(uint *)(iVar10 + 0x30) = uVar9 | 0x400;
            }
          }
        }
      }
      if ((*(ushort *)(iVar10 + 0x28) < 9) &&
         ((1 << ((byte)*(undefined2 *)(iVar10 + 0x28) & 0x1f) & 0x1f1U) != 0)) {
        uVar2 = *(ushort *)(iVar10 + 6) | *(ushort *)(iVar10 + 2);
        uVar8 = uVar2 & 0xffef;
        if (((ushort)(uVar8 - 1) < 2) || (uVar8 == 4)) {
          local_2c = 0;
          uVar5 = (uint)uVar8;
          do {
            puVar14 = (ushort *)(local_2c + iVar10 + 8);
            uVar3 = puVar14[1];
            if ((uVar3 | 0xfffffff9) == 0xffffffff) {
              uVar9 = uVar3 & 0x300;
              if (uVar9 == 0x100) {
                uStack_2e = (uVar2 & 3) * 2 | (ushort)((int)(uVar5 & 4) >> 2);
              }
              else if (uVar9 < 0x101) {
                if ((uVar3 & 0x300) == 0) {
                  uStack_2e = uVar8;
                }
              }
              else if (uVar9 == 0x200) {
                uStack_2e = (short)(uVar5 & 1) * 4 | (ushort)((int)(uVar5 & 6) >> 1);
              }
              else if (uVar9 == 0x300) {
                uStack_2e = (uVar2 & 2) * 2 | (ushort)((int)(uVar5 & 4) >> 1) |
                            (ushort)((uVar5 & 1) << 3);
                if ((uVar2 & 1) == 0) {
                  *puVar14 = *puVar14 & 0xfdff;
                }
                else {
                  *puVar14 = *puVar14 & 0xfeff;
                }
              }
              puVar14[1] = puVar14[1] & (uStack_2e & 0xfcef ^ 0xfcf0);
              bVar7 = true;
            }
            local_2c = local_2c + 4;
          } while (local_2c != 0xc);
        }
      }
      iVar13 = 3;
      iVar12 = iVar10;
      do {
        uVar2 = *(ushort *)(iVar12 + 10);
        uVar8 = uVar2 & 0x1f;
        if (uVar8 == 0x10) {
          *(ushort *)(iVar12 + 10) = uVar2 & 0xcfff;
          *(ushort *)(iVar10 + 0x34) = *(ushort *)(iVar10 + 0x34) & 0xff9f;
        }
        else if ((0xf < uVar8) && (uVar8 < 0x13)) {
          *(ushort *)(iVar12 + 10) = uVar2 & 0xdfff;
          *(ushort *)(iVar10 + 0x34) = *(ushort *)(iVar10 + 0x34) & 0xffbf;
        }
        iVar12 = iVar12 + 4;
        iVar10 = iVar10 + 2;
        iVar13 = iVar13 + -1;
      } while (iVar13 != 0);
    }
    local_28 = local_28 + 0x40;
    if (local_28 == 0x80) {
      if (!bVar7) {
        return;
      }
      ((int (*)())FUN_000be6b4)();
      return;
    }
  } while( true );
}

/* FUN_000bf3e4 @ 0xbf3e4 (1585 bytes) */
int FUN_000bf3e4(param_1, param_2, param_3)
  ushort *param_1;
  int param_2;
  int param_3;
{
  ushort uVar1;
  uint uVar2;
  ushort uVar3;
  undefined4 uVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  ushort *puVar10;
  ushort *puVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  short local_7e;
  uint local_3c;
  int local_38;
  undefined4 local_34;
  uint local_30;
  uint local_2c;
  undefined4 local_28;
  uint local_24;
  uint local_20;
  
  _memset(param_1,0,0x80);
  param_1[0x40] = 0;
  param_1[0x41] = 0;
  param_1[0x42] = 0;
  param_1[0x43] = 0;
  param_1[0x44] = 0;
  param_1[0x45] = 0;
  iVar12 = *(int *)(param_1 + 0x48);
  iVar9 = *(int *)(param_1 + 0x46);
  if (iVar9 != 1) {
    if (iVar9 == 0) {
      param_1[2] = *(ushort *)(param_2 + 6 + iVar12 * 4) >> 2 & 0x7f;
      param_1[0x40] = *(byte *)(param_2 + 5 + iVar12 * 4) >> 4 | 0xc000;
      if ((*(byte *)(param_2 + 6 + iVar12 * 4) & 3) != 0) {
        param_1[3] = 0xf;
        param_1[10] = 0xf;
        bVar5 = *(byte *)(param_2 + 6 + iVar12 * 4) & 3;
        if (bVar5 == 2) {
          param_1[0x1d] = 2;
        }
        else if (bVar5 == 3) {
          param_1[0x1d] = 3;
        }
      }
      *(undefined4 *)(param_1 + 0x16) =
           *(undefined4 *)(&DAT_001eeec0 + (uint)(*(byte *)(param_2 + 7 + iVar12 * 4) >> 3) * 4);
      param_1[0x22] = *(ushort *)(param_2 + 4 + iVar12 * 4) >> 5 & 0x7f;
      param_1[0x43] = *(byte *)(param_2 + 4 + iVar12 * 4) & 0xf | 0xa000;
      if ((*(byte *)(param_2 + 4 + iVar12 * 4) & 0x10) == 0) {
        *(undefined4 *)(param_1 + 0x36) =
             *(undefined4 *)(&DAT_001eeec0 + (*(byte *)(param_2 + 7 + iVar12 * 4) >> 1 & 1) * 4);
      }
      else {
        param_1[0x23] = 0xf;
        param_1[0x2d] = 0xf;
        *(undefined4 *)(param_1 + 0x36) =
             *(undefined4 *)(&DAT_001eeec0 + (*(byte *)(param_2 + 7 + iVar12 * 4) >> 1 & 1) * 4);
      }
      return;
    }
    if (iVar9 != 2) {
      return;
    }
    uVar7 = *(uint *)(param_3 + 0x98 + iVar12 * 4);
    uVar6 = *(uint *)(param_3 + 0x198 + iVar12 * 4);
    uVar14 = *(uint *)(param_3 + 0x298 + iVar12 * 4);
    uVar2 = *(uint *)(param_3 + 0x398 + iVar12 * 4);
    param_1[0x40] = (ushort)uVar7 & 0x3f;
    param_1[0x41] = (ushort)(uVar7 >> 6) & 0x3f;
    param_1[0x42] = (ushort)(uVar7 >> 0xc) & 0x3f;
    param_1[0x43] = (ushort)uVar6 & 0x3f;
    param_1[0x44] = (ushort)(uVar6 >> 6) & 0x3f;
    param_1[0x45] = (ushort)(uVar6 >> 0xc) & 0x3f;
    local_38 = 0;
    iVar12 = 0x80;
    do {
      puVar10 = (ushort *)((int)param_1 + iVar12);
      iVar9 = 0;
      do {
        if (0x1f < *puVar10) {
          *puVar10 = *puVar10 - 0x20 | 0x8000;
        }
        iVar9 = iVar9 + 1;
        puVar10 = puVar10 + 1;
      } while (iVar9 != 3);
      local_38 = local_38 + 1;
      iVar12 = iVar12 + 6;
    } while (local_38 != 2);
    iVar12 = 0;
    puVar10 = param_1;
    puVar11 = param_1;
    do {
      puVar10[0x3a] = 1;
      puVar10[0x1a] = 1;
      uVar4 = DAT_001eec68;
      *(undefined4 *)(puVar11 + 0x24) = DAT_001eec68;
      *(undefined4 *)(puVar11 + 4) = uVar4;
      iVar12 = iVar12 + 1;
      puVar10 = puVar10 + 1;
      puVar11 = puVar11 + 2;
    } while (iVar12 != 3);
    uVar1 = (ushort)(uVar7 >> 0x10);
    param_1[2] = uVar1 >> 2 & 0x1f;
    param_1[3] = uVar1 >> 7 & 7;
    *param_1 = uVar1 >> 0xd & 3;
    param_1[1] = uVar1 >> 10 & 7;
    uVar7 = uVar14 >> 0x17 & 0xf;
    param_1[0x14] = *(ushort *)(&DAT_001eee80 + uVar7 * 4);
    uVar1 = *(ushort *)(&DAT_001eee82 + uVar7 * 4);
    uVar3 = (ushort)(uVar14 >> 0x10);
    if (uVar1 != 0) {
      local_30 = CONCAT22((short)(uVar14 >> 0xe),(short)(uVar14 >> 5)) & 0x1f0003;
      uVar7 = CONCAT22((short)uVar14,(short)(uVar14 >> 7));
      local_2c = uVar7 & 0x1f001f;
      local_34 = CONCAT22((short)(uVar14 >> 0xc),uVar3 >> 3) & 0x30003;
      do {
        local_7e = (short)local_30;
        uVar13 = 0;
        uVar8 = (uVar7 & 0x1fffff) >> 0x10;
        puVar10 = param_1 + 4;
        while( true ) {
          while( true ) {
            *(undefined4 *)puVar10 = (DAT_001eee00)[uVar8 & 0xffff];
            puVar10[1] = puVar10[1] | local_7e << 0xc;
            uVar13 = uVar13 + 1;
            if (uVar1 <= uVar13) goto LAB_000bf7d5;
            if (uVar13 != 1) break;
            local_7e = (*(unsigned short *)((unsigned char *)&(local_34) + 2));
            puVar10 = puVar10 + 2;
            uVar8 = local_2c;
          }
          if (uVar13 == 0) break;
          if (uVar13 == 2) {
            local_7e = (short)local_34;
            puVar10 = puVar10 + 2;
            uVar8 = local_30 >> 0x10;
          }
          else {
            local_7e = 0;
            puVar10 = puVar10 + 2;
            uVar8 = 0;
          }
        }
      } while( true );
    }
LAB_000bf7d5:
    param_1[0x15] = uVar3 >> 5 & 3;
    if ((uVar14 & 0x40000000) != 0) {
      *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 8;
    }
    *(undefined4 *)(param_1 + 0x16) = *(undefined4 *)(&DAT_001eeec0 + (uVar14 >> 0x1b & 7) * 4);
    uVar1 = (ushort)(uVar6 >> 0x10);
    param_1[0x22] = uVar1 >> 2 & 0x1f;
    if ((char)(uVar6 >> 0x10) < '\0') {
      param_1[0x23] = 8;
    }
    param_1[0x20] = uVar1 >> 9 & 3;
    if ((uVar6 >> 0x18 & 1) != 0) {
      param_1[0x21] = 8;
    }
    if ((uVar6 >> 0x18 & 8) != 0) {
      param_1[0x21] = param_1[0x21] | 0x10;
    }
    uVar7 = uVar2 >> 0x17 & 0xf;
    param_1[0x34] = *(ushort *)(&DAT_001eedc0 + uVar7 * 4);
    local_3c = (uint)*(ushort *)(&DAT_001eedc2 + uVar7 * 4);
    uVar1 = (ushort)(uVar2 >> 0x10);
    if ((uVar3 & 0x780) == 0x100) {
      if (local_3c < 2) {
        local_3c = 2;
      }
    }
    else if (*(ushort *)(&DAT_001eedc2 + uVar7 * 4) == 0) {
LAB_000bf943:
      param_1[0x35] = uVar1 >> 5 & 3;
      if ((uVar2 & 0x40000000) != 0) {
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 8;
      }
      *(undefined4 *)(param_1 + 0x36) = *(undefined4 *)(&DAT_001eeec0 + (uVar2 >> 0x1b & 7) * 4);
      ((int (*)())FUN_000be6b4)(param_1);
      ((int (*)())FUN_000becfb)();
      return;
    }
    local_24 = CONCAT22((short)(uVar2 >> 0xe),(short)(uVar2 >> 5)) & 0x1f0003;
    uVar7 = CONCAT22((short)uVar2,(short)(uVar2 >> 7));
    local_20 = uVar7 & 0x1f001f;
    local_28 = CONCAT22((short)(uVar2 >> 0xc),uVar1 >> 3) & 0x30003;
    do {
      local_7e = (short)local_24;
      uVar14 = 0;
      uVar6 = (uVar7 & 0x1fffff) >> 0x10;
      puVar10 = param_1 + 0x24;
      while( true ) {
        while( true ) {
          *(undefined4 *)puVar10 = (DAT_001eed60)[uVar6 & 0xffff];
          puVar10[1] = puVar10[1] | local_7e << 0xc;
          uVar14 = uVar14 + 1;
          if (local_3c <= uVar14) goto LAB_000bf943;
          if (uVar14 != 1) break;
          local_7e = (*(unsigned short *)((unsigned char *)&(local_28) + 2));
          puVar10 = puVar10 + 2;
          uVar6 = local_20;
        }
        if (uVar14 == 0) break;
        if (uVar14 == 2) {
          local_7e = (short)local_28;
          puVar10 = puVar10 + 2;
          uVar6 = local_24 >> 0x10;
        }
        else {
          local_7e = 0;
          puVar10 = puVar10 + 2;
          uVar6 = 0;
        }
      }
    } while( true );
  }
  param_1[2] = *(ushort *)(param_3 + 0x18 + iVar12 * 4) >> 6 & 0x1f;
  param_1[0x40] = (ushort)(*(byte *)(param_3 + 0x18 + iVar12 * 4) & 0x1f);
  uVar7 = *(uint *)(param_3 + 0x18 + iVar12 * 4);
  uVar6 = uVar7 >> 0xf & 7;
  if (uVar6 == 2) {
    param_1[10] = 0xf;
    param_1[0x18] = 1;
    param_1[0x19] = 0;
    param_1[0x1d] = 1;
    uVar7 = *(uint *)(param_3 + 0x18 + iVar12 * 4);
  }
  else {
    if (uVar6 < 3) {
      if (uVar6 != 1) goto LAB_000bf59c;
    }
    else if (4 < uVar6) goto LAB_000bf59c;
    param_1[3] = 0xf;
    param_1[10] = 0xf;
    uVar7 = *(uint *)(param_3 + 0x18 + iVar12 * 4);
  }
LAB_000bf59c:
  param_1[0x14] =
       (ushort)(uVar7 >> 0xf) & 7 | (*(byte *)(param_3 + 0x19 + iVar12 * 4) >> 3 & 0xf) << 8;
  param_1[0x16] = 0;
  param_1[0x17] = 0x3f80;
  return;
}

/* FUN_000bfa15 @ 0xbfa15 (300 bytes) */
int FUN_000bfa15(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  undefined2 uVar1;
  int iVar2;
  ushort uVar3;
  int iVar4;
  ushort uVar5;
  undefined4 local_10;
  
  if (((*(uint *)(param_1 + 0x30) | *(uint *)(param_1 + 0x70)) & 0x10) != 0) {
    return 0;
  }
  if (param_3 == 0) {
    if (*(short *)(param_1 + 0x20 + param_2 * 4) != 0 ||
        *(short *)(param_1 + 0x60 + param_2 * 4) != 0) {
      return 0;
    }
LAB_000bfa5a:
    if (param_4 != 1) goto LAB_000bfa65;
  }
  else if (param_3 != 1) goto LAB_000bfa5a;
  if (*(short *)(param_1 + 0x22 + param_2 * 4) != 0 || *(short *)(param_1 + 0x62 + param_2 * 4) != 0
     ) {
    return 0;
  }
LAB_000bfa65:
  iVar2 = param_2 * 3 + (uint)param_3;
  uVar1 = *(undefined2 *)(param_1 + 0x80 + iVar2 * 2);
  iVar4 = param_2 * 3 + (uint)param_4;
  *(undefined2 *)(param_1 + 0x80 + iVar2 * 2) = *(undefined2 *)(param_1 + 0x80 + iVar4 * 2);
  *(undefined2 *)(param_1 + 0x80 + iVar4 * 2) = uVar1;
  local_10 = 0;
  do {
    iVar2 = param_1 + local_10;
    iVar4 = 3;
    do {
      uVar5 = *(ushort *)(iVar2 + 8) & 3;
      uVar3 = *(ushort *)(iVar2 + 8) & 0x300;
      if ((uint)uVar3 == (param_2 + 1) * 0x100) {
        if (param_3 == uVar5) {
          *(ushort *)(iVar2 + 8) = uVar3 | param_4;
        }
        else if (param_4 == uVar5) {
          *(ushort *)(iVar2 + 8) = uVar3 | param_3;
        }
      }
      iVar2 = iVar2 + 4;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    local_10 = local_10 + 0x40;
  } while (local_10 != 0x80);
  return 1;
}

/* FUN_000bfb41 @ 0xbfb41 (223 bytes) */
int FUN_000bfb41(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  uint uVar2;
  undefined4 local_10;
  
  if (*(ushort *)(param_1 + 0x84 + param_2 * 6) < *(ushort *)(param_1 + 0x82 + param_2 * 6)) {
    local_10 = ((int (*)())FUN_000bfa15)(param_1,param_2,1,2);
  }
  else {
    local_10 = 0;
  }
  iVar1 = param_1 + param_2 * 6;
  if (*(ushort *)(iVar1 + 0x82) < *(ushort *)(iVar1 + 0x80)) {
    uVar2 = ((int (*)())FUN_000bfa15)(param_1,param_2,0,1);
    local_10 = local_10 | uVar2;
  }
  if (*(ushort *)(iVar1 + 0x84) < *(ushort *)(iVar1 + 0x82)) {
    uVar2 = ((int (*)())FUN_000bfa15)(param_1,param_2,1,2);
    local_10 = local_10 | uVar2;
  }
  if (local_10 != 0) {
    ((int (*)())FUN_000be6b4)(param_1);
  }
  return local_10;
}

/* FUN_000bfc20 @ 0xbfc20 (2874 bytes) */
int FUN_000bfc20(param_1, param_2, param_3)
  uint *param_1;
  int param_2;
  int param_3;
{
  uint *puVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  byte bVar10;
  byte bVar11;
  short sVar12;
  byte bVar13;
  uint uVar14;
  ushort *puVar15;
  byte *pbVar16;
  byte *pbVar17;
  byte bVar18;
  byte bVar19;
  byte *pbVar20;
  double dVar21;
  double dVar22;
  uint local_bc;
  byte *local_a4;
  uint local_9c;
  int local_68;
  int local_64;
  uint local_60;
  uint local_5c;
  uint local_4c;
  ushort local_3a;
  ushort local_38;
  byte *local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  
  if (*param_1 != 0) {
    local_60 = 0;
    local_2c = 0;
    do {
      while( true ) {
        pbVar20 = (byte *)(local_2c + param_1[2]);
        iVar4 = *(int *)(pbVar20 + 0x90);
        uVar2 = *(ushort *)(pbVar20 + 4);
        uVar3 = *(ushort *)(pbVar20 + 0x44);
        iVar5 = *(int *)(pbVar20 + 0x8c);
        if (iVar5 != 1) break;
        *(ushort *)(param_3 + 0x18 + iVar4 * 4) =
             *(ushort *)(param_3 + 0x18 + iVar4 * 4) & 0xf83f | (ushort)((uVar2 & 0x1f) << 6);
        if ((*(short *)(pbVar20 + 2) == 0 && *(short *)(pbVar20 + 6) == 0) &&
           ((pbVar20[0x30] & 1) == 0)) {
          puVar1 = (uint *)(param_3 + 0x18 + iVar4 * 4);
          *puVar1 = *puVar1 & 0xfffc7fff;
        }
        *(byte *)(param_3 + 0x18 + iVar4 * 4) =
             *(byte *)(param_3 + 0x18 + iVar4 * 4) & 0xe0 | pbVar20[0x80] & 0x1f;
        *(uint *)(param_3 + 0x18 + iVar4 * 4) =
             *(uint *)(param_3 + 0x18 + iVar4 * 4) & 0xfffc7fff | (uint)(pbVar20[0x28] & 7) << 0xf;
        *(byte *)(param_3 + 0x19 + iVar4 * 4) =
             *(byte *)(param_3 + 0x19 + iVar4 * 4) & 0x87 | (pbVar20[0x29] & 0xf) << 3;
        pbVar20 = (byte *)(param_3 + 0x1a + iVar4 * 4);
        *pbVar20 = *pbVar20 & 0xfb;
LAB_000bfc57:
        local_60 = local_60 + 1;
        local_2c = local_2c + 0xa0;
        if (*param_1 <= local_60) {
          return;
        }
      }
      if (iVar5 != 0) {
        if (iVar5 == 2) {
          *(byte *)(param_3 + 0x9a + iVar4 * 4) =
               *(byte *)(param_3 + 0x9a + iVar4 * 4) & 0x83 | ((byte)uVar2 & 0x1f) << 2;
          bVar10 = ((byte)uVar3 & 0x1f) << 2;
          bVar13 = *(byte *)(param_3 + 0x19a + iVar4 * 4);
          *(byte *)(param_3 + 0x19a + iVar4 * 4) = bVar13 & 0x83 | bVar10;
          bVar19 = (pbVar20[2] & 7) << 2;
          bVar18 = *(byte *)(param_3 + 0x9b + iVar4 * 4);
          *(byte *)(param_3 + 0x9b + iVar4 * 4) = bVar18 & 0xe3 | bVar19;
          *(byte *)(param_3 + 0x9b + iVar4 * 4) = bVar18 & 0x83 | bVar19 | (*pbVar20 & 3) << 5;
          bVar19 = (byte)(*(ushort *)(pbVar20 + 0x42) >> 3) & 1;
          bVar18 = *(byte *)(param_3 + 0x19b + iVar4 * 4);
          *(byte *)(param_3 + 0x19b + iVar4 * 4) = bVar18 & 0xfe | bVar19;
          bVar11 = ((byte)(*(ushort *)(pbVar20 + 0x42) >> 4) & 1) << 3;
          *(byte *)(param_3 + 0x19b + iVar4 * 4) = bVar18 & 0xf6 | bVar19 | bVar11;
          *(byte *)(param_3 + 0x19b + iVar4 * 4) =
               bVar18 & 0xf0 | bVar19 | bVar11 | (pbVar20[0x40] & 3) * '\x02';
          *(ushort *)(param_3 + 0x9a + iVar4 * 4) =
               *(ushort *)(param_3 + 0x9a + iVar4 * 4) & 0xfc7f | (pbVar20[6] & 7) << 7;
          *(byte *)(param_3 + 0x19a + iVar4 * 4) =
               bVar13 & 3 | bVar10 | (char)(*(ushort *)(pbVar20 + 0x46) >> 3) << 7;
          local_28 = 0;
          local_30 = pbVar20;
          do {
            uVar2 = *(ushort *)(local_30 + 0x80);
            local_bc = (uint)uVar2;
            uVar3 = *(ushort *)(local_30 + 0x86);
            uVar14 = (uint)uVar3;
            if (uVar2 == 0xffff) {
              local_bc = 0x20;
            }
            else if ((short)uVar2 < 0) {
              local_bc = (uint)(ushort)((uVar2 & 0x7fff) + 0x20);
            }
            if (uVar3 == 0xffff) {
              uVar14 = 0x20;
            }
            else if ((short)uVar3 < 0) {
              uVar14 = (uVar3 & 0x7fff) + 0x20;
            }
            if (local_28 == 1) {
              *(ushort *)(param_3 + 0x98 + iVar4 * 4) =
                   *(ushort *)(param_3 + 0x98 + iVar4 * 4) & 0xf03f | ((ushort)local_bc & 0x3f) << 6
              ;
              *(ushort *)(param_3 + 0x198 + iVar4 * 4) =
                   *(ushort *)(param_3 + 0x198 + iVar4 * 4) & 0xf03f |
                   (ushort)((uVar14 & 0x3f) << 6);
            }
            else if (local_28 == 0) {
              *(byte *)(param_3 + 0x98 + iVar4 * 4) =
                   *(byte *)(param_3 + 0x98 + iVar4 * 4) & 0xc0 | (byte)local_bc & 0x3f;
              *(byte *)(param_3 + 0x198 + iVar4 * 4) =
                   *(byte *)(param_3 + 0x198 + iVar4 * 4) & 0xc0 | (byte)uVar14 & 0x3f;
            }
            else if (local_28 == 2) {
              *(uint *)(param_3 + 0x98 + iVar4 * 4) =
                   *(uint *)(param_3 + 0x98 + iVar4 * 4) & 0xfffc0fff | (local_bc & 0x3f) << 0xc;
              *(uint *)(param_3 + 0x198 + iVar4 * 4) =
                   *(uint *)(param_3 + 0x198 + iVar4 * 4) & 0xfffc0fff | (uVar14 & 0x3f) << 0xc;
            }
            local_28 = local_28 + 1;
            local_30 = local_30 + 2;
          } while (local_28 != 3);
          local_68 = 0;
          local_a4 = pbVar20;
          do {
            local_5c = 0;
            local_3a = 0;
            local_4c = 0;
            local_38 = 0;
            local_20 = 0;
            puVar15 = (ushort *)(local_a4 + 8);
            do {
              uVar2 = puVar15[1];
              if (local_20 == 0) {
                if ((uVar2 & 0x300) == 0x100) {
                  uVar14 = 6;
                }
                else if ((uVar2 & 0x300) == 0x200) {
                  uVar14 = 5;
                }
                else {
                  uVar14 = (uint)(uVar2 & 0x1f);
                }
                local_5c = (uint)(byte)(DAT_001eed00)[(uint)(*puVar15 & 3) + uVar14 * 4];
                local_3a = (uVar2 & 0x3000) >> 0xc;
              }
              else if (local_20 == 1) {
                local_4c = (uint)(byte)(DAT_001eeca0)[(uint)(*puVar15 & 3) + (uint)(uVar2 & 0x1f) * 4];
                local_38 = (uVar2 & 0x3000) >> 0xc;
              }
              local_20 = local_20 + 1;
              puVar15 = puVar15 + 0x20;
            } while (local_20 != 2);
            if (local_68 == 1) {
              *(ushort *)(param_3 + 0x298 + iVar4 * 4) =
                   *(ushort *)(param_3 + 0x298 + iVar4 * 4) & 0xf07f |
                   ((ushort)local_5c & 0x1f) << 7;
              *(byte *)(param_3 + 0x299 + iVar4 * 4) =
                   *(byte *)(param_3 + 0x299 + iVar4 * 4) & 0xcf | (char)local_3a << 4;
              *(ushort *)(param_3 + 0x398 + iVar4 * 4) =
                   *(ushort *)(param_3 + 0x398 + iVar4 * 4) & 0xf07f |
                   ((ushort)local_4c & 0x1f) << 7;
              *(byte *)(param_3 + 0x399 + iVar4 * 4) =
                   *(byte *)(param_3 + 0x399 + iVar4 * 4) & 0xcf | (char)local_38 << 4;
            }
            else if (local_68 == 0) {
              *(byte *)(param_3 + 0x298 + iVar4 * 4) =
                   *(byte *)(param_3 + 0x298 + iVar4 * 4) & 0x80 | (byte)local_5c & 0x1f |
                   (char)local_3a << 5;
              *(byte *)(param_3 + 0x398 + iVar4 * 4) =
                   *(byte *)(param_3 + 0x398 + iVar4 * 4) & 0x80 | (byte)local_4c & 0x1f |
                   (char)local_38 << 5;
            }
            else if (local_68 == 2) {
              *(uint *)(param_3 + 0x298 + iVar4 * 4) =
                   *(uint *)(param_3 + 0x298 + iVar4 * 4) & 0xfff83fff | (local_5c & 0x1f) << 0xe;
              *(byte *)(param_3 + 0x29a + iVar4 * 4) =
                   *(byte *)(param_3 + 0x29a + iVar4 * 4) & 0xe7 | (char)local_3a << 3;
              *(uint *)(param_3 + 0x398 + iVar4 * 4) =
                   *(uint *)(param_3 + 0x398 + iVar4 * 4) & 0xfff83fff | (local_4c & 0x1f) << 0xe;
              *(byte *)(param_3 + 0x39a + iVar4 * 4) =
                   *(byte *)(param_3 + 0x39a + iVar4 * 4) & 0xe7 | (char)local_38 << 3;
            }
            dVar9 = DOUBLE_001cf3b8;
            dVar8 = DAT_001c64c0;
            dVar7 = DAT_001c64b0;
            local_68 = local_68 + 1;
            local_a4 = local_a4 + 4;
          } while (local_68 != 3);
          local_24 = 0;
          pbVar16 = pbVar20;
          do {
            dVar21 = (double)*(float *)(pbVar16 + 0x2c) * dVar9;
            dVar22 = dVar21;
            if (dVar8 <= dVar21) {
              dVar22 = dVar8;
            }
            if (dVar22 <= 0.0) {
              dVar22 = 0.0;
            }
            uVar14 = (uint)(dVar22 - (double)(-(ulonglong)(dVar7 <= dVar21) & (ulonglong)dVar7));
            local_9c = (uint)(dVar7 <= dVar21) * -0x80000000 ^ uVar14;
            if (local_9c < 0x41) {
              switch((switchdataD_000c01d4)[uVar14] + 0xbfc31) {
              case 0xc02d8:
                local_9c = 2;
                break;
              case 0xc0695:
                local_9c = 6;
                break;
              case 0xc069f:
                local_9c = 5;
                break;
              case 0xc06a9:
                local_9c = 4;
                break;
              case 0xc06b3:
                local_9c = 0;
                break;
              case 0xc06ba:
                local_9c = 1;
                break;
              case 0xc06c4:
                local_9c = 3;
              }
            }
            if (local_24 == 0) {
              bVar18 = ((byte)local_9c & 7) << 3;
              bVar13 = *(byte *)(param_3 + 0x29b + iVar4 * 4);
              *(byte *)(param_3 + 0x29b + iVar4 * 4) = bVar13 & 199 | bVar18;
              *(byte *)(param_3 + 0x29b + iVar4 * 4) =
                   bVar13 & 0x87 | bVar18 | ((byte)(*(uint *)(pbVar20 + 0x30) >> 3) & 1) << 6;
            }
            else if (local_24 == 1) {
              bVar18 = ((byte)local_9c & 7) << 3;
              bVar13 = *(byte *)(param_3 + 0x39b + iVar4 * 4);
              *(byte *)(param_3 + 0x39b + iVar4 * 4) = bVar13 & 199 | bVar18;
              *(byte *)(param_3 + 0x39b + iVar4 * 4) =
                   bVar13 & 0x87 | bVar18 | ((byte)(*(uint *)(pbVar20 + 0x70) >> 3) & 1) << 6;
            }
            local_24 = local_24 + 1;
            pbVar16 = pbVar16 + 0x40;
          } while (local_24 != 2);
          local_64 = 0;
          uVar14 = (uint)(byte)(DAT_001eec6c)[(uint)*(ushort *)(pbVar20 + 0x28) * 2];
          pbVar16 = pbVar20;
          do {
            *(ushort *)(param_3 + 0x29a + iVar4 * 4) =
                 *(ushort *)(param_3 + 0x29a + iVar4 * 4) & 0xf87f | (ushort)((uVar14 & 0xf) << 7);
            *(byte *)(param_3 + 0x29a + iVar4 * 4) =
                 *(byte *)(param_3 + 0x29a + iVar4 * 4) & 0x9f | (pbVar20[0x2a] & 3) << 5;
            pbVar17 = pbVar16;
            while( true ) {
              local_64 = local_64 + 1;
              pbVar16 = pbVar17 + 0x40;
              if (local_64 == 2) goto LAB_000bfc57;
              uVar14 = (uint)(byte)(DAT_001eec6c)[local_64 + (uint)*(ushort *)(pbVar17 + 0x68) * 2]
              ;
              if (local_64 == 0) break;
              pbVar17 = pbVar16;
              if (local_64 == 1) {
                *(ushort *)(param_3 + 0x39a + iVar4 * 4) =
                     *(ushort *)(param_3 + 0x39a + iVar4 * 4) & 0xf87f |
                     (ushort)((uVar14 & 0xf) << 7);
                *(byte *)(param_3 + 0x39a + iVar4 * 4) =
                     *(byte *)(param_3 + 0x39a + iVar4 * 4) & 0x9f | (pbVar20[0x6a] & 3) << 5;
              }
            }
          } while( true );
        }
        goto LAB_000bfc57;
      }
      *(ushort *)(param_2 + 6 + iVar4 * 4) =
           *(ushort *)(param_2 + 6 + iVar4 * 4) & 0xfe03 | (ushort)((uVar2 & 0x7f) << 2);
      *(ushort *)(param_2 + 4 + iVar4 * 4) =
           *(ushort *)(param_2 + 4 + iVar4 * 4) & 0xf01f | (uVar3 & 0x7f) << 5;
      if ((*(short *)(pbVar20 + 2) == 0 && *(short *)(pbVar20 + 6) == 0) &&
         ((pbVar20[0x30] & 1) == 0)) {
        pbVar16 = (byte *)(param_2 + 6 + iVar4 * 4);
        *pbVar16 = *pbVar16 & 0xfc;
      }
      else {
        sVar12 = *(short *)(pbVar20 + 0x3a);
        if (sVar12 == 2) {
          *(byte *)(param_2 + 6 + iVar4 * 4) = *(byte *)(param_2 + 6 + iVar4 * 4) & 0xfc | 2;
        }
        else if (sVar12 == 3) {
          pbVar16 = (byte *)(param_2 + 6 + iVar4 * 4);
          *pbVar16 = *pbVar16 | 3;
        }
        else if (sVar12 == 0) {
          *(byte *)(param_2 + 6 + iVar4 * 4) = *(byte *)(param_2 + 6 + iVar4 * 4) & 0xfc | 1;
        }
      }
      if ((*(short *)(pbVar20 + 0x42) == 0 && *(short *)(pbVar20 + 0x46) == 0) &&
         ((pbVar20[0x70] & 1) == 0)) {
        bVar13 = *(byte *)(param_2 + 4 + iVar4 * 4) & 0xef;
        *(byte *)(param_2 + 4 + iVar4 * 4) = bVar13;
        sVar12 = *(short *)(pbVar20 + 0x80);
        if (sVar12 == -1) goto LAB_000bfe95;
LAB_000bfd46:
        *(byte *)(param_2 + 5 + iVar4 * 4) =
             *(byte *)(param_2 + 5 + iVar4 * 4) & 0xf | (char)sVar12 << 4;
        sVar12 = *(short *)(pbVar20 + 0x86);
        if (sVar12 != -1) goto LAB_000bfd74;
LAB_000bfeab:
        *(byte *)(param_2 + 4 + iVar4 * 4) = bVar13 & 0xf0;
      }
      else {
        bVar13 = *(byte *)(param_2 + 4 + iVar4 * 4) & 0xef | 0x10;
        *(byte *)(param_2 + 4 + iVar4 * 4) = bVar13;
        sVar12 = *(short *)(pbVar20 + 0x80);
        if (sVar12 != -1) goto LAB_000bfd46;
LAB_000bfe95:
        pbVar16 = (byte *)(param_2 + 5 + iVar4 * 4);
        *pbVar16 = *pbVar16 & 0xf;
        sVar12 = *(short *)(pbVar20 + 0x86);
        if (sVar12 == -1) goto LAB_000bfeab;
LAB_000bfd74:
        *(byte *)(param_2 + 4 + iVar4 * 4) = bVar13 & 0xf0 | (byte)sVar12 & 0xf;
      }
      fVar6 = FLOAT_001c5ba4;
      bVar18 = (FLOAT_001c5ba4 != *(float *)(pbVar20 + 0x2c)) << 3;
      bVar13 = *(byte *)(param_2 + 7 + iVar4 * 4);
      *(byte *)(param_2 + 7 + iVar4 * 4) = bVar13 & 7 | bVar18;
      *(byte *)(param_2 + 7 + iVar4 * 4) =
           bVar13 & 5 | bVar18 | (fVar6 != *(float *)(pbVar20 + 0x6c)) * '\x02';
      local_60 = local_60 + 1;
      local_2c = local_2c + 0xa0;
    } while (local_60 < *param_1);
  }
  return;
}

/* FUN_000c085e @ 0xc085e (1448 bytes) */
int FUN_000c085e(param_1, param_2, param_3, param_4)
  int param_1;
  uint *param_2;
  int param_3;
  undefined4 param_4;
{
  undefined2 *puVar1;
  ushort *puVar2;
  void *pvVar3;
  float fVar4;
  ushort uVar5;
  undefined2 *puVar6;
  undefined2 uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  short *psVar11;
  undefined2 uVar12;
  ushort uVar13;
  uint uVar14;
  int iVar15;
  ushort *puVar16;
  uint uVar17;
  int iVar18;
  int local_a4;
  int local_9c;
  int local_98;
  int local_94;
  uint *local_88;
  int local_74;
  int local_70;
  int local_44;
  int local_40;
  ushort *local_3c;
  int local_38;
  uint local_34;
  int local_30;
  uint local_28;
  uint local_24;
  undefined2 *local_20;
  
  pvVar3 = (void *)param_2[3];
  uVar14 = *(uint *)(param_1 + 0x30);
  puVar1 = (undefined2 *)((int)pvVar3 + uVar14 * 4);
  local_20 = puVar1 + 8;
  if (param_3 == 0) {
    local_88 = (uint *)0x0;
  }
  else {
    local_88 = &local_28;
    uVar14 = 0x80;
  }
  iVar10 = 0;
  puVar6 = puVar1;
  do {
    *puVar6 = (short)iVar10;
    puVar6[1] = 0xf;
    iVar10 = iVar10 + 1;
    puVar6 = puVar6 + 2;
  } while (iVar10 != 4);
  puVar1[1] = puVar1[1] | 0x10;
  _memset(pvVar3,0,*(int *)(param_1 + 0x30) << 2);
  if (uVar14 == 0) {
    uVar14 = 0;
  }
  else {
    uVar9 = 0;
    uVar17 = uVar14;
    do {
      uVar17 = uVar17 - 1;
      local_20[uVar9] = (short)uVar17;
      uVar9 = uVar9 + 1;
    } while (uVar14 != uVar9);
  }
  local_28 = uVar14 & 0xffff;
  local_24 = 0;
  uVar14 = *param_2;
  local_30 = (uVar14 * 5 + -5) * 0x20;
  local_34 = 0;
  do {
    fVar4 = FLOAT_001c5ba4;
    iVar10 = local_30 + param_2[2];
    if (*(int *)(iVar10 + 0x8c) == 2) {
      iVar8 = 0;
      iVar18 = 0;
      iVar15 = iVar10;
      do {
        if (((*(ushort *)(iVar15 + 6) != 0) && ((*(uint *)(iVar15 + 0x30) & 0x400) != 0)) &&
           ((*(uint *)(iVar15 + 0x30) & 0x1800) == 0)) {
          if (((fVar4 == *(float *)(iVar15 + 0x2c)) &&
              (!NAN(fVar4) && !NAN(*(float *)(iVar15 + 0x2c)))) &&
             (((*(ushort *)(iVar15 + 10) & 0x10) == 0 &&
              ((*(short *)(iVar10 + 0x80 + (iVar18 + (*(ushort *)(iVar15 + 8) & 3)) * 2) ==
                *(short *)(iVar15 + 4) &&
               ((~(*(ushort *)(iVar15 + 10) & 0xf) & *(ushort *)(iVar15 + 6)) == 0)))))) {
            *(undefined2 *)(iVar15 + 6) = 0;
          }
        }
        iVar8 = iVar8 + 1;
        iVar15 = iVar15 + 0x40;
        iVar18 = iVar18 + 3;
      } while (iVar8 != 2);
    }
    if (*(int *)(iVar10 + 0x8c) == 2) {
      iVar15 = 0;
      do {
        puVar2 = (ushort *)(iVar15 + iVar10);
        uVar13 = puVar2[1];
        uVar5 = uVar13 >> 4;
        if (((uVar5 & 1) != 0) && ((*(byte *)(puVar1 + 1) & 0x10) == 0)) {
          uVar13 = uVar13 & 0xffef;
          puVar2[1] = uVar13;
        }
        uVar13 = (puVar1[(uint)*puVar2 * 2 + 1] | 0x10) & uVar13;
        puVar2[1] = uVar13;
        puVar1[(uint)*puVar2 * 2 + 1] = puVar1[(uint)*puVar2 * 2 + 1] & ~uVar13;
        if ((uVar5 & 1) != 0) {
          puVar1[1] = puVar1[1] & 0xffef;
        }
        iVar15 = iVar15 + 0x40;
      } while (iVar15 != 0x80);
    }
    uVar7 = *(undefined2 *)((int)pvVar3 + (uint)*(ushort *)(iVar10 + 4) * 4);
    uVar12 = *(undefined2 *)((int)pvVar3 + (uint)*(ushort *)(iVar10 + 0x44) * 4);
    local_38 = 0;
    iVar15 = iVar10;
    do {
      puVar6 = (undefined2 *)((int)pvVar3 + (uint)*(ushort *)(iVar15 + 4) * 4);
      uVar13 = puVar6[1];
      uVar5 = uVar13 & *(ushort *)(iVar15 + 6);
      *(ushort *)(iVar15 + 6) = uVar5;
      if ((*(int *)(iVar10 + 0x8c) != 2) && (uVar5 != 0)) {
        uVar5 = 0xf;
        *(undefined2 *)(iVar15 + 6) = 0xf;
      }
      puVar6[1] = puVar6[1] & ~uVar5;
      if ((*(short *)(iVar15 + 2) == 0 && *(short *)(iVar15 + 6) == 0) &&
         ((*(byte *)(iVar15 + 0x30) & 1) == 0)) {
        *(undefined4 *)(iVar15 + 0x14) = 0;
        *(undefined4 *)(iVar15 + 0x18) = 0;
        *(undefined4 *)(iVar15 + 0x1c) = 0;
        *(undefined4 *)(iVar15 + 0x20) = 0;
        *(undefined4 *)(iVar15 + 0x24) = 0;
      }
      if (((local_88 != (uint *)0x0) && (uVar13 != 0)) && (puVar6[1] == 0)) {
        uVar17 = *local_88;
        *(undefined2 *)(local_88[2] + uVar17 * 2) = *puVar6;
        *local_88 = uVar17 + 1;
        *puVar6 = 0;
      }
      local_38 = local_38 + 0x40;
      iVar15 = iVar15 + 0x40;
    } while (local_38 != 0x80);
    local_70 = 0;
    local_98 = 0x80;
    local_9c = iVar10;
    do {
      local_3c = (ushort *)(iVar10 + local_98);
      local_74 = 0;
      local_94 = local_9c + 0x10;
      do {
        if (-1 < (short)*local_3c) {
          puVar2 = (ushort *)((int)pvVar3 + (uint)*local_3c * 4);
          puVar16 = (ushort *)(local_94 + 4);
          local_44 = 2;
          do {
            uVar13 = *puVar16;
            uVar5 = puVar2[1];
            puVar2[1] = uVar13 | uVar5;
            if ((uVar5 == 0) && (uVar13 != 0)) {
              local_28 = local_28 - 1;
              uVar13 = local_20[local_28];
              uVar17 = (uint)uVar13;
              if (uVar13 <= local_24) {
                uVar17 = local_24;
              }
              *puVar2 = uVar13;
              local_24 = uVar17;
            }
            puVar16 = puVar16 + 0x20;
            local_44 = local_44 + -1;
          } while (local_44 != 0);
        }
        local_74 = local_74 + 1;
        local_94 = local_94 + 2;
        local_3c = local_3c + 1;
      } while (local_74 != 3);
      local_70 = local_70 + 1;
      local_9c = local_9c + 6;
      local_98 = local_98 + 6;
    } while (local_70 != 2);
    if (*(short *)(iVar10 + 6) == 0) {
      uVar7 = 0;
    }
    *(undefined2 *)(iVar10 + 4) = uVar7;
    if (*(short *)(iVar10 + 0x46) == 0) {
      uVar12 = 0;
    }
    *(undefined2 *)(iVar10 + 0x44) = uVar12;
    iVar15 = 0;
    local_a4 = iVar10 + 0x10;
    do {
      psVar11 = (short *)(local_a4 + 4);
      iVar8 = 3;
      do {
        if (*psVar11 == 0 && psVar11[0x20] == 0) {
          psVar11[0x36] = -1;
        }
        else if (-1 < psVar11[0x36]) {
          psVar11[0x36] = *(short *)((int)pvVar3 + (uint)(ushort)psVar11[0x36] * 4);
        }
        psVar11 = psVar11 + 1;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
      iVar15 = iVar15 + 1;
      local_a4 = local_a4 + 6;
    } while (iVar15 != 2);
    if (*(int *)(iVar10 + 0x8c) == 2) {
      ((int (*)())FUN_000be6b4)(iVar10);
      ((int (*)())FUN_000bfb41)(iVar10,0);
      ((int (*)())FUN_000bfb41)(iVar10,1);
      ((int (*)())FUN_000becfb)(iVar10);
    }
    local_34 = local_34 + 1;
    local_30 = local_30 + -0xa0;
  } while (uVar14 != local_34);
  if (*param_2 == 0) {
    *param_2 = 0;
    param_2[1] = local_24 + 1;
  }
  else {
    uVar17 = 0;
    uVar14 = 0;
    local_40 = 0;
    do {
      pvVar3 = (void *)(param_2[2] + local_40);
      if (((*(short *)((int)pvVar3 + 2) != 0 || *(short *)((int)pvVar3 + 6) != 0) ||
          ((*(byte *)((int)pvVar3 + 0x30) & 1) != 0)) ||
         ((*(short *)((int)pvVar3 + 0x42) != 0 || *(short *)((int)pvVar3 + 0x46) != 0 ||
          ((*(byte *)((int)pvVar3 + 0x70) & 1) != 0)))) {
        if (uVar14 < uVar17) {
          _memcpy((void *)(uVar14 * 0xa0 + param_2[2]),pvVar3,0xa0);
        }
        uVar14 = uVar14 + 1;
      }
      uVar17 = uVar17 + 1;
      local_40 = local_40 + 0xa0;
    } while (uVar17 < *param_2);
    *param_2 = uVar14;
    param_2[1] = local_24 + 1;
    if (uVar14 != 0) {
      if (param_3 != 0) {
        ((int (*)())FUN_000bfc20)(param_2,param_3,param_4);
      }
      return 0;
    }
  }
  return 0x80000004;
}

/* FUN_000c0e06 @ 0xc0e06 (41 bytes) */
int FUN_000c0e06(param_1)
  int param_1;
{
  param_1 = param_1 & 0xf;
  if (((1 < (ushort)(param_1 - 1)) && (param_1 != 4)) && (param_1 != 8)) {
    return 0;
  }
  return 1;
}

/* FUN_000c0e2f @ 0xc0e2f (32 bytes) */
int FUN_000c0e2f(param_1, param_2)
  int param_1;
  uint param_2;
{
  if (((*(byte *)(param_1 + 0x46) & 8) != 0) && (*(ushort *)(param_1 + 0x44) == param_2)) {
    return 1;
  }
  return 0;
}

/* FUN_000c0e4f @ 0xc0e4f (118 bytes) */
int FUN_000c0e4f(param_1, param_2)
  int param_1;
  uint param_2;
{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  int local_18;
  int local_10;
  
  local_10 = 0;
  local_18 = param_1 + 0x54;
  iVar3 = param_1 + 0x14;
  param_1 = param_1 + 0x50;
  do {
    pbVar2 = (byte *)(param_1 + 4);
    iVar1 = 3;
    do {
      if ((*(ushort *)(pbVar2 + 0x2c) == param_2) &&
         (((pbVar2[iVar3 - local_18] & 8) != 0 || ((*pbVar2 & 8) != 0)))) {
        return 1;
      }
      pbVar2 = pbVar2 + 2;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    local_10 = local_10 + 1;
    param_1 = param_1 + 6;
    iVar3 = iVar3 + 6;
    local_18 = local_18 + 6;
    if (local_10 == 2) {
      return 0;
    }
  } while( true );
}

/* FUN_000c0ec5 @ 0xc0ec5 (149 bytes) */
int FUN_000c0ec5(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint param_3;
{
  ushort *puVar1;
  ushort *puVar2;
  int iVar3;
  int iVar4;
  int local_20;
  int local_1c;
  int local_14;
  int local_10;
  
  local_14 = 0;
  local_20 = param_1;
  do {
    local_10 = 0;
    iVar4 = local_20 + 0x10;
    local_1c = 0;
    do {
      puVar2 = (ushort *)(iVar4 + 4);
      puVar1 = (ushort *)(local_1c + 0x80 + param_1);
      iVar3 = 3;
      do {
        if (((*puVar2 & param_2) != 0) && (*puVar1 == param_3)) {
          return 1;
        }
        puVar2 = puVar2 + 1;
        puVar1 = puVar1 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      local_10 = local_10 + 1;
      local_1c = local_1c + 6;
      iVar4 = iVar4 + 6;
    } while (local_10 != 2);
    local_14 = local_14 + 1;
    local_20 = local_20 + 0x40;
    if (local_14 == 2) {
      return 0;
    }
  } while( true );
}

/* FUN_000c0f5a @ 0xc0f5a (155 bytes) */
int FUN_000c0f5a(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint param_3;
{
  ushort *puVar1;
  ushort *puVar2;
  int iVar3;
  int iVar4;
  int local_20;
  int local_1c;
  int local_14;
  int local_10;
  
  local_14 = 0;
  local_20 = param_1;
  do {
    local_10 = 0;
    iVar4 = local_20 + 0x10;
    local_1c = 0;
    do {
      puVar2 = (ushort *)(iVar4 + 4);
      puVar1 = (ushort *)(local_1c + 0x80 + param_1);
      iVar3 = 3;
      do {
        if ((((param_2 & *puVar2) != 0) && (*puVar2 != param_2)) && (*puVar1 == param_3)) {
          return 1;
        }
        puVar2 = puVar2 + 1;
        puVar1 = puVar1 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      local_10 = local_10 + 1;
      local_1c = local_1c + 6;
      iVar4 = iVar4 + 6;
    } while (local_10 != 2);
    local_14 = local_14 + 1;
    local_20 = local_20 + 0x40;
    if (local_14 == 2) {
      return 0;
    }
  } while( true );
}

/* FUN_000c0ff5 @ 0xc0ff5 (58 bytes) */
int FUN_000c0ff5(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint param_3;
{
  if (*(ushort *)(param_1 + 4) == param_3) {
    param_2 = param_2 & ~*(ushort *)(param_1 + 6);
  }
  if (param_3 == *(ushort *)(param_1 + 0x44)) {
    param_2 = param_2 & ~*(ushort *)(param_1 + 0x46);
  }
  return param_2 == 0;
}

/* FUN_000c102f @ 0xc102f (36 bytes) */
int FUN_000c102f(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (*(short *)(param_1 + 0x86) == -1) {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
    param_1 = param_1 + 2;
  } while (iVar1 != 3);
  return -1;
}

/* FUN_000c1053 @ 0xc1053 (24 bytes) */
int FUN_000c1053(param_1)
  undefined4 param_1;
{
  uint uVar1;
  
  uVar1 = ((int (*)())FUN_000c102f)(param_1);
  return ~uVar1 >> 0x1f;
}

/* FUN_000c106b @ 0xc106b (337 bytes) */
int FUN_000c106b(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  uint param_3;
  int param_4;
  int param_5;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 local_18;
  undefined2 local_14;
  
  uVar1 = param_3 >> 3 & 1;
  if ((param_3 & 7) != 0) {
    uVar1 = 0;
  }
  if (param_4 == 2) {
    local_14 = 2;
  }
  else if (param_4 == 3) {
    local_14 = 3;
  }
  else if (param_4 == 1) {
    local_14 = 1;
  }
  else {
    local_14 = 0;
  }
  local_18 = 0;
  do {
    iVar2 = param_1 + local_18 * 0x40;
    iVar3 = 0;
    do {
      if ((*(ushort *)(iVar2 + 10) & 0x1f) == param_2) {
        if (*(short *)(param_1 + 0x80 +
                      ((uint)(param_2 == 8) * 3 + (*(ushort *)(iVar2 + 8) & 3)) * 2) == param_5) {
          *(ushort *)(iVar2 + 10) = *(ushort *)(iVar2 + 10) & 0xffe0 | (ushort)param_3;
          *(ushort *)(iVar2 + 8) = *(ushort *)(iVar2 + 8) & 0xfcfc | 0x200 | local_14;
          *(short *)(param_1 + 0x80 + (uVar1 * 3 + param_4) * 2) = param_5;
        }
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 4;
    } while (iVar3 != 3);
    local_18 = local_18 + 1;
  } while (local_18 != 2);
  if (*(int *)(param_1 + 0x8c) != 2) {
    return 1;
  }
  ((int (*)())FUN_000be6b4)(param_1);
  ((int (*)())FUN_000becfb)(param_1);
  return 1;
}

/* FUN_000c11bc @ 0xc11bc (865 bytes) */
int FUN_000c11bc(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  uint param_5;
  uint param_6;
{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined2 *puVar10;
  uint uVar11;
  int iVar12;
  ushort *puVar13;
  int local_60;
  int local_5c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  uint local_38;
  int local_34;
  int local_30;
  int local_24 [6];
  
  uVar7 = ~-(uint)((param_5 & 8) == 0) & 0x200;
  if ((param_5 & 7) == 0) {
    if (uVar7 == 0) {
      return 0;
    }
  }
  else {
    uVar7 = (uint)(byte)((byte)(uVar7 >> 8) | 1) << 8;
  }
  uVar2 = (uint)(param_4 == 8);
  if ((param_5 == 0x10) || (param_5 == 0x12)) {
    iVar12 = param_1 + uVar2 * 0x40;
    iVar9 = 0;
    do {
      *(ushort *)(iVar12 + 8) = *(ushort *)(iVar12 + 8) & 0xfcff;
      *(ushort *)(iVar12 + 10) = (ushort)param_5;
      iVar9 = iVar9 + 1;
      iVar12 = iVar12 + 4;
    } while (iVar9 != 3);
  }
  else {
    local_30 = 0;
    uVar8 = uVar7 >> 8 & 1;
    puVar13 = (ushort *)(param_1 + 10 + uVar2 * 0x40);
    do {
      uVar11 = puVar13[-1] & 3;
      if (((uVar11 < 3) && ((*puVar13 & 0x1f) == param_6)) &&
         (uVar3 = (uint)((puVar13[-1] & 0x300) != 0x100),
         *(short *)(param_1 + 0x80 + (uVar3 * 3 + uVar11) * 2) == param_2)) {
        local_34 = 0;
        iVar12 = 0;
        do {
          puVar4 = (undefined4 *)((int)local_24 + iVar12);
          iVar9 = 3;
          do {
            *puVar4 = 0;
            puVar4 = puVar4 + 1;
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
          local_34 = local_34 + 1;
          iVar12 = iVar12 + 0xc;
        } while (local_34 != 2);
        local_3c = param_1;
        local_38 = 0;
        do {
          local_40 = local_38 * 0x40 + param_1;
          local_44 = 0;
          do {
            if ((uVar2 != local_38) || (local_30 != local_44)) {
              uVar1 = *(ushort *)(local_40 + 8);
              uVar5 = uVar1 & 3;
              if (uVar5 == 3) {
                iVar12 = local_24[1];
                if ((uVar1 & 0x100) != 0) {
                  local_24[0] = 1;
                  iVar12 = 1;
                  if (1 < (ushort)(*(short *)(local_3c + 0x2a) - 1U)) {
                    iVar12 = local_24[1];
                  }
                }
                local_24[1] = iVar12;
                if (((uVar1 & 0x200) != 0) &&
                   (local_24[3] = 1, (ushort)(*(short *)(local_3c + 0x2a) - 1U) < 2)) {
                  local_24[4] = 1;
                }
              }
              else {
                if ((uVar1 & 0x100) != 0) {
                  local_24[uVar5] = 1;
                }
                if ((uVar1 & 0x200) != 0) {
                  local_24[uVar5 + 3] = 1;
                }
              }
            }
            local_44 = local_44 + 1;
            local_40 = local_40 + 4;
          } while (local_44 != 3);
          local_38 = local_38 + 1;
          local_3c = local_3c + 0x40;
        } while (local_38 != 2);
        local_48 = 0;
        local_5c = 0x80;
        local_60 = 0;
        do {
          piVar6 = local_24 + local_60;
          puVar10 = (undefined2 *)(param_1 + local_5c);
          iVar12 = 3;
          do {
            if (*piVar6 == 0) {
              *puVar10 = 0xffff;
            }
            piVar6 = piVar6 + 1;
            puVar10 = puVar10 + 1;
            iVar12 = iVar12 + -1;
          } while (iVar12 != 0);
          local_48 = local_48 + 1;
          local_60 = local_60 + 3;
          local_5c = local_5c + 6;
        } while (local_48 != 2);
        iVar9 = 0;
        iVar12 = param_1;
        while ((((uVar8 != 0 && (*(short *)(iVar12 + 0x80) != -1)) &&
                (param_3 != *(short *)(iVar12 + 0x80))) ||
               (((uVar7 >> 9 != 0 && (*(short *)(iVar12 + 0x86) != -1)) &&
                (param_3 != *(short *)(iVar12 + 0x86)))))) {
          iVar9 = iVar9 + 1;
          iVar12 = iVar12 + 2;
          if (iVar9 == 3) {
            *(short *)(param_1 + 0x80 + (uVar3 * 3 + uVar11) * 2) = param_2;
            return 0;
          }
        }
        if (uVar8 != 0) {
          *(short *)(param_1 + 0x80 + iVar9 * 2) = param_3;
        }
        if (uVar7 >> 9 != 0) {
          *(short *)(param_1 + 0x86 + iVar9 * 2) = param_3;
        }
        *puVar13 = *puVar13 & 0xffe0 | (ushort)param_5;
        puVar13[-1] = (puVar13[-1] & 0xfffc | (ushort)iVar9) & 0xfcff | (ushort)uVar7;
      }
      local_30 = local_30 + 1;
      puVar13 = puVar13 + 2;
    } while (local_30 != 3);
  }
  if (*(int *)(param_1 + 0x8c) == 2) {
    ((int (*)())FUN_000be6b4)(param_1);
    ((int (*)())FUN_000becfb)(param_1);
  }
  return 0;
}

/* FUN_000c151d @ 0xc151d (124 bytes) */
int FUN_000c151d(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  int iVar1;
  ushort *puVar2;
  int iVar3;
  int local_18;
  int local_10;
  
  local_10 = 0;
  local_18 = param_1 + 0x54;
  iVar3 = param_1 + 0x14;
  param_1 = param_1 + 0x50;
  do {
    puVar2 = (ushort *)(param_1 + 4);
    iVar1 = 2;
    do {
      if ((puVar2[0x16] == param_2) &&
         (((param_3 & *(ushort *)((iVar3 - local_18) + (int)puVar2)) != 0 ||
          ((param_3 & *puVar2) != 0)))) {
        return 1;
      }
      puVar2 = puVar2 + 3;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    local_10 = local_10 + 1;
    param_1 = param_1 + 2;
    iVar3 = iVar3 + 2;
    local_18 = local_18 + 2;
    if (local_10 == 3) {
      return 0;
    }
  } while( true );
}

/* FUN_000c1599 @ 0xc1599 (97 bytes) */
int FUN_000c1599(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  ushort *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  param_1 = param_1 + 0x10;
  do {
    puVar1 = (ushort *)(param_1 + 4);
    iVar2 = 2;
    do {
      if (((puVar1[0x36] == param_2) && ((param_3 & *puVar1) != 0)) && ((~param_3 & *puVar1) != 0))
      {
        return 1;
      }
      puVar1 = puVar1 + 3;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    iVar3 = iVar3 + 1;
    param_1 = param_1 + 2;
    if (iVar3 == 3) {
      return 0;
    }
  } while( true );
}

/* FUN_000c15fa @ 0xc15fa (53 bytes) */
int FUN_000c15fa(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  int iVar1;
  
  iVar1 = 2;
  while ((*(ushort *)(param_1 + 4) != param_2 || ((param_3 & *(ushort *)(param_1 + 6)) == 0))) {
    param_1 = param_1 + 0x40;
    iVar1 = iVar1 + -1;
    if (iVar1 == 0) {
      return 0;
    }
  }
  return 1;
}

/* FUN_000c162f @ 0xc162f (94 bytes) */
int FUN_000c162f(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1 + (uint)(param_2 == 8) * 0x40;
  iVar1 = 3;
  do {
    if ((*(ushort *)(iVar2 + 8) & 3) == 3) {
      return 0;
    }
    iVar2 = iVar2 + 4;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if (((*(byte *)((1 - (uint)(param_2 == 8)) * 0x40 + 0x30 + param_1) & 0x20) == 0) &&
     (1 < param_3 - 1U)) {
    return 1;
  }
  return 0;
}

/* FUN_000c168d @ 0xc168d (213 bytes) */
int FUN_000c168d(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  ushort uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int local_14;
  
  local_14 = 0;
  do {
    iVar4 = param_1 + local_14 * 0x40;
    iVar3 = 3;
    do {
      uVar1 = *(ushort *)(iVar4 + 8);
      uVar5 = uVar1 & 3;
      if (((uVar1 & 0x300) != 0) &&
         (((-(uint)(param_4 == 0) & 0xffffff00) + 0x200 & uVar1 & 0x300) != 0)) {
        if (uVar5 == param_2) {
          *(ushort *)(iVar4 + 8) = uVar1 & 0xfffc | param_3;
        }
        if (uVar5 == param_3) {
          *(ushort *)(iVar4 + 8) = *(ushort *)(iVar4 + 8) & 0xfffc | param_2;
        }
      }
      iVar4 = iVar4 + 4;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    local_14 = local_14 + 1;
  } while (local_14 != 2);
  iVar3 = param_4 * 3 + (uint)param_2;
  uVar2 = *(undefined2 *)(param_1 + 0x80 + iVar3 * 2);
  iVar4 = param_4 * 3 + (uint)param_3;
  *(undefined2 *)(param_1 + 0x80 + iVar3 * 2) = *(undefined2 *)(param_1 + 0x80 + iVar4 * 2);
  *(undefined2 *)(param_1 + 0x80 + iVar4 * 2) = uVar2;
  return;
}

/* FUN_000c1762 @ 0xc1762 (1583 bytes) */
int FUN_000c1762(param_1, param_2, param_3, param_4, param_5, param_6)
  void *param_1;
  int param_2;
  int param_3;
  int param_4;
  uint param_5;
  uint param_6;
{
  ushort *puVar1;
  ushort *puVar2;
  ushort uVar3;
  bool bVar4;
  char cVar5;
  short *psVar6;
  ushort uVar7;
  int iVar8;
  void *pvVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  void *local_130;
  void *local_110;
  short *local_10c;
  uint local_ec;
  int local_e8;
  int local_e4;
  int local_dc;
  uint local_d8;
  int local_d0;
  int local_c4;
  int local_c0;
  undefined1 local_b4 [160];
  uint local_14 [2];
  
  _memcpy(local_b4,param_1,0xa0);
  iVar12 = 0;
  iVar8 = (int)param_1 + 0x10;
  do {
    psVar6 = (short *)(iVar8 + 4);
    iVar11 = 0;
    do {
      if ((*psVar6 == 0) && (psVar6[0x20] == 0)) {
        psVar6[0x36] = -1;
      }
      iVar11 = iVar11 + 1;
      psVar6 = psVar6 + 1;
    } while (iVar11 != 3);
    iVar12 = iVar12 + 1;
    iVar8 = iVar8 + 6;
  } while (iVar12 != 2);
  if (((param_6 & 7) != 0) && (param_2 != *(short *)((int)param_1 + 0x80))) {
    if ((*(short *)((int)param_1 + 0x82) == -1) || (param_2 == *(short *)((int)param_1 + 0x82))) {
      ((int (*)())FUN_000c168d)(0);
    }
    else if ((*(short *)((int)param_1 + 0x84) == -1) || (param_2 == *(short *)((int)param_1 + 0x84))
            ) {
      ((int (*)())FUN_000c168d)(0);
    }
  }
  uVar13 = param_6 >> 3 & 1;
  cVar5 = (char)uVar13;
  if (cVar5 == '\0') {
    local_dc = 0;
    goto LAB_000c186d;
  }
  if (param_2 != *(short *)((int)param_1 + 0x86)) {
    if ((*(short *)((int)param_1 + 0x88) == -1) || (param_2 == *(short *)((int)param_1 + 0x88))) {
      ((int (*)())FUN_000c168d)(1);
      local_dc = 1;
      goto LAB_000c186d;
    }
    if ((*(short *)((int)param_1 + 0x8a) == -1) || (param_2 == *(short *)((int)param_1 + 0x8a))) {
      ((int (*)())FUN_000c168d)(1);
      local_dc = 1;
      goto LAB_000c186d;
    }
  }
  local_dc = 1;
LAB_000c186d:
  local_c0 = 0;
  do {
    pvVar9 = (void *)((int)param_1 + local_c0 * 0x40);
    local_d0 = 3;
    local_130 = pvVar9;
    do {
      uVar7 = *(ushort *)((int)pvVar9 + 8);
      if ((uVar7 & 0x100) == 0) {
        if ((uVar7 & 0x200) != 0) {
          uVar3 = *(ushort *)((int)local_130 + 0x1a);
          local_c4 = 1;
          goto LAB_000c18dc;
        }
      }
      else {
        uVar3 = *(ushort *)((int)local_130 + 0x14);
        local_c4 = 0;
LAB_000c18dc:
        local_d8 = (uint)uVar3;
        if ((((uVar7 & 3) < 3) &&
            (param_2 == *(short *)((int)param_1 + ((uVar7 & 3) + local_c4 * 3) * 2 + 0x80))) &&
           ((~param_5 & *(ushort *)((int)pvVar9 + 10) & 0x1f & local_d8) != 0)) {
          uVar10 = (uint)(*(short *)((int)param_1 + local_c4 * 6 + 0x82) == -1);
          if (*(short *)((int)param_1 + local_c4 * 6 + 0x84) == -1) {
            uVar10 = 2;
          }
          *(short *)((int)param_1 + (local_c4 * 3 + uVar10) * 2 + 0x80) = param_2;
          *(ushort *)((int)pvVar9 + 8) = (ushort)uVar10 | *(ushort *)((int)pvVar9 + 8) & 0xfffc;
        }
      }
      pvVar9 = (void *)((int)pvVar9 + 4);
      local_130 = (void *)((int)local_130 + 2);
      local_d0 = local_d0 + -1;
    } while (local_d0 != 0);
    local_c0 = local_c0 + 1;
    if (local_c0 == 2) {
      bVar4 = false;
      local_e8 = 0;
      local_110 = param_1;
      do {
        local_ec = 0;
        local_10c = (short *)((int)local_110 + 0x80);
        do {
          if (*local_10c == param_2) {
            local_e4 = 0;
            do {
              pvVar9 = (void *)((int)param_1 + local_e4 * 0x40);
              iVar8 = 3;
              do {
                local_14[0] = 0x100;
                local_14[1] = 0x200;
                puVar1 = (ushort *)((int)pvVar9 + 8);
                if (((*(ushort *)((int)pvVar9 + 8) & 3) == local_ec) &&
                   ((local_14[local_e8] & *(ushort *)((int)pvVar9 + 8) & 0x300) != 0)) {
                  puVar2 = (ushort *)((int)pvVar9 + 10);
                  uVar7 = *(ushort *)((int)pvVar9 + 10);
                  uVar10 = (uint)uVar7;
                  if ((param_5 & uVar10) != 0) {
                    if ((uVar7 & 0x2000) == 0) {
                      uVar7 = uVar7 ^ 0x1000;
                      uVar10 = (uint)uVar7;
                      *(ushort *)((int)pvVar9 + 10) = uVar7;
                      *(ushort *)((int)pvVar9 + 8) = *(ushort *)((int)pvVar9 + 8) & 0xfffc | 3;
                      if (param_4 == 7) goto LAB_000c1ce1;
LAB_000c1ade:
                      *(ushort *)((int)pvVar9 + 10) = uVar7 | (ushort)param_6;
                    }
                    else {
                      *(ushort *)((int)pvVar9 + 8) = *(ushort *)((int)pvVar9 + 8) & 0xfffc | 3;
                      if (param_4 != 7) goto LAB_000c1ade;
LAB_000c1ce1:
                      if ((1 < (uVar10 & 0x1f) - 1) && ((uVar10 & 0x1f) != 4)) goto LAB_000c1ade;
                    }
                    if ((param_6 & 1) == 0) {
                      *puVar2 = *puVar2 & 0xfffe;
                    }
                    if ((param_6 & 2) == 0) {
                      *puVar2 = *puVar2 & 0xfffd;
                    }
                    if ((param_6 & 4) == 0) {
                      *puVar2 = *puVar2 & 0xfffb;
                    }
                    if (uVar13 == 0) {
                      *puVar2 = *puVar2 & 0xfff7;
                      uVar7 = *puVar1;
                      *puVar1 = uVar7 & 0xfcff;
                      *puVar1 = uVar7 & 0xfcff | (ushort)local_14[local_dc];
                      bVar4 = true;
                    }
                    else {
                      uVar7 = *puVar1;
                      *puVar1 = uVar7 & 0xfcff;
                      *puVar1 = uVar7 & 0xfcff | (ushort)local_14[local_dc];
                      bVar4 = true;
                    }
                  }
                }
                pvVar9 = (void *)((int)pvVar9 + 4);
                iVar8 = iVar8 + -1;
              } while (iVar8 != 0);
              local_e4 = local_e4 + 1;
            } while (local_e4 != 2);
          }
          local_ec = local_ec + 1;
          local_10c = local_10c + 1;
        } while (local_ec != 3);
        local_e8 = local_e8 + 1;
        local_110 = (void *)((int)local_110 + 6);
        if (local_e8 == 2) {
          if (!bVar4) {
            _memcpy(param_1,local_b4,0xa0);
            return 1;
          }
          if ((param_6 & 7) != 0) {
            *(undefined2 *)((int)param_1 + 0x80) = param_3;
          }
          if (cVar5 != '\0') {
            *(undefined2 *)((int)param_1 + 0x86) = param_3;
          }
          ((int (*)())FUN_000be6b4)(param_1);
          ((int (*)())FUN_000becfb)(param_1);
          return 1;
        }
      } while( true );
    }
  } while( true );
}

