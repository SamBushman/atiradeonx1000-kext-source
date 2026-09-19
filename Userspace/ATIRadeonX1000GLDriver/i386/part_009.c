#include "decls.h"

/* FUN_000633b0 @ 0x633b0 (989 bytes) */
int FUN_000633b0(param_1)
  int param_1;
{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  uint uVar8;
  byte bVar9;
  char *pcVar10;
  char *pcVar11;
  bool bVar12;
  char *local_80;
  uint local_68;
  uint local_5c;
  uint local_58;
  uint local_54;
  int local_50;
  char local_44 [8];
  undefined4 local_3c;
  uint local_38;
  undefined4 local_14;
  int local_10;
  
  pcVar6 = local_44;
  for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
    pcVar6[0] = '\0';
    pcVar6[1] = '\0';
    pcVar6[2] = '\0';
    pcVar6[3] = '\0';
    pcVar6 = pcVar6 + 4;
  }
  local_44[3] = local_44[3] | 0x10;
  local_3c = *(undefined4 *)(param_1 + 0x1804);
  bVar1 = *(byte *)(param_1 + 0x46);
  if ((bVar1 & 0x30) != 0) {
    local_38 = bVar1 >> 4 & 1 | (bVar1 >> 5 & 1) * 2 | (uint)*(byte *)(param_1 + 0x11d3) << 2;
  }
  local_80 = *(char **)(param_1 + 0x14c);
  bVar12 = local_80 == (char *)0x0;
  if (!bVar12) {
    iVar5 = 0x30;
    pcVar6 = local_80;
    pcVar10 = local_44;
    do {
      pcVar7 = pcVar6;
      pcVar11 = pcVar10;
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      pcVar11 = pcVar10 + 1;
      pcVar7 = pcVar6 + 1;
      bVar12 = *pcVar6 == *pcVar10;
      pcVar6 = pcVar7;
      pcVar10 = pcVar11;
    } while (bVar12);
    iVar5 = 0;
    if (!bVar12) {
      iVar5 = (uint)(byte)pcVar7[-1] - (uint)(byte)pcVar11[-1];
    }
    if (iVar5 == 0) goto LAB_00063442;
  }
  local_80 = (char *)FUN_0009cdff(param_1,local_44);
  if (local_80 == (char *)0x0) {
    uVar2 = *(uint *)(param_1 + 0x1804);
    bVar9 = *(byte *)(param_1 + 0x46) >> 5 & 1;
    bVar1 = *(byte *)(param_1 + 0x11d2);
    puVar4 = (undefined4 *)FUN_0008dbba(param_1,1,0);
    *puVar4 = 0;
    FUN_0006331a(param_1,puVar4,&local_10,&local_14);
    if (bVar9 == 0) {
      uVar8 = uVar2 >> 1 & 1;
      local_54 = uVar2 >> 3 & 1;
      local_68 = 0;
    }
    else {
      uVar8 = uVar2 >> 1 & 1;
      local_54 = uVar2 >> 3 & 1;
      local_68 = bVar1 + 2 + (-local_54 & 2) + ((uVar2 & 1) != 0) + uVar8;
    }
    local_58 = uVar2 & 1;
    FUN_0008dd2f(puVar4,bVar9,(uint)bVar1);
    if (uVar8 == 0) {
      iVar5 = 1;
      local_50 = 2;
    }
    else {
      puVar4[0x13] = 1;
      FUN_0008e180(puVar4);
      iVar5 = 2;
      local_50 = 3;
    }
    puVar4[3] = iVar5;
    FUN_0008de84(puVar4,3,0,0);
    if (local_58 != 0) {
      puVar4[4] = local_50;
      FUN_0008de84(puVar4,4,1,0);
      if ((uVar2 & 4) != 0) {
        puVar4[0x14] = local_50;
        puVar4[0x15] = 3;
        FUN_0008e212(puVar4);
      }
      local_50 = iVar5 + 2;
    }
    if (local_54 != 0) {
      puVar4[5] = local_50;
      FUN_0008de84(puVar4,3,2,1);
      puVar4[6] = local_50 + 1;
      local_50 = local_50 + 2;
      puVar4[0x20] = 0;
      FUN_0008de84(puVar4,4,3,1);
    }
    uVar8 = (uint)(local_54 != 0);
    if (uVar2 >> 4 != 0) {
      local_5c = 0;
      iVar5 = param_1;
      do {
        iVar3 = *(int *)(iVar5 + 0x1824);
        puVar4[iVar3 + 0xb] = local_50;
        local_50 = local_50 + 1;
        if (uVar8 == local_68) {
          uVar8 = uVar8 + 1;
        }
        puVar4[iVar3 + 0x21] = uVar8;
        uVar8 = uVar8 + 1;
        FUN_0008e025(puVar4,iVar3);
        local_5c = local_5c + 1;
        iVar5 = iVar5 + 4;
      } while (uVar2 >> 4 != local_5c);
    }
    FUN_00098884(puVar4);
    local_10 = local_50;
    local_80 = (char *)FUN_0009a799(param_1,local_44,puVar4,local_50,local_14,0,0,1);
    local_80[0x34] = '\0';
    local_80[0x35] = '\0';
    local_80[0x36] = '\0';
    local_80[0x37] = '\0';
    *(int *)(local_80 + 0x38) = *(int *)(*(int *)(local_80 + 0x54) + 0x3cc) + -1;
  }
LAB_00063442:
  if (local_80 != *(char **)(param_1 + 0x14c)) {
    *(char **)(param_1 + 0x14c) = local_80;
    *(byte *)(param_1 + 0x8d) = *(byte *)(param_1 + 0x8d) | 0x20;
  }
  (**(code **)(param_1 + 0x1294))
            (param_1,*(int *)(local_80 + 0x54) + 0x750,*(undefined4 *)(local_80 + 0x3c));
  return;
}

/* FUN_0006378d @ 0x6378d (569 bytes) */
int FUN_0006378d(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  undefined4 *puVar2;
  uint *puVar3;
  int iVar4;
  void *pvVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar4 = *(int *)(param_2 + 0x54);
  iVar1 = iVar4 + 0x750;
  puVar2 = (undefined4 *)(iVar4 + 0x768);
  iVar7 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  iVar8 = 0;
  iVar6 = iVar1;
  do {
    *(undefined4 *)(iVar6 + 0x1018) = 0;
    iVar8 = iVar8 + 1;
    iVar6 = iVar6 + 4;
  } while (iVar8 != 8);
  *(undefined4 *)(iVar4 + 0x1990) = 0xffff;
  if (*(char *)(param_2 + 0x58) == '\0') {
    if (*(int *)(param_2 + 0x48) == 0) {
      *(undefined4 *)(iVar4 + 0x1788) = 0;
    }
    else {
      pvVar5 = *(void **)(param_2 + 0x4c);
      FUN_0009d07e(param_1,param_2);
      _memcpy(puVar2,pvVar5,*(int *)(param_2 + 0x48) << 4);
      iVar7 = *(int *)(param_2 + 0x48);
      if (0 < iVar7) {
        iVar6 = 0;
        do {
          iVar7 = iVar6;
          if (iVar6 < 0) {
            iVar7 = iVar6 + 0x1f;
          }
          puVar3 = (uint *)(iVar4 + 0x1768 + (iVar7 >> 5) * 4);
          *puVar3 = *puVar3 | 1 << ((byte)iVar6 & 0x1f);
          iVar6 = iVar6 + 1;
          iVar7 = *(int *)(param_2 + 0x48);
        } while (iVar6 < iVar7);
      }
      *(int *)(iVar4 + 0x1788) = iVar7;
    }
  }
  else {
    if ((*(byte *)((int)&switchdataD_000013c0 + param_1) & 4) == 0) {
      *puVar2 = *(undefined4 *)(iVar7 + 0x2460);
      *(undefined4 *)(iVar4 + 0x76c) = *(undefined4 *)(iVar7 + 0x2470);
      *(undefined4 *)(iVar4 + 0x770) = *(undefined4 *)(iVar7 + 0x2480);
      *(undefined4 *)(iVar4 + 0x774) = *(undefined4 *)(iVar7 + 0x2490);
      *(undefined4 *)(iVar4 + 0x778) = *(undefined4 *)(iVar7 + 0x2464);
      *(undefined4 *)(iVar4 + 0x77c) = *(undefined4 *)(iVar7 + 0x2474);
      *(undefined4 *)(iVar4 + 0x780) = *(undefined4 *)(iVar7 + 0x2484);
      *(undefined4 *)(iVar4 + 0x784) = *(undefined4 *)(iVar7 + 0x2494);
      *(undefined4 *)(iVar4 + 0x788) = *(undefined4 *)(iVar7 + 0x2468);
      *(undefined4 *)(iVar4 + 0x78c) = *(undefined4 *)(iVar7 + 0x2478);
      *(undefined4 *)(iVar4 + 0x790) = *(undefined4 *)(iVar7 + 0x2488);
      *(undefined4 *)(iVar4 + 0x794) = *(undefined4 *)(iVar7 + 0x2498);
      *(undefined4 *)(iVar4 + 0x798) = *(undefined4 *)(iVar7 + 0x246c);
      *(undefined4 *)(iVar4 + 0x79c) = *(undefined4 *)(iVar7 + 0x247c);
      *(undefined4 *)(iVar4 + 0x7a0) = *(undefined4 *)(iVar7 + 0x248c);
      *(undefined4 *)(iVar4 + 0x7a4) = *(undefined4 *)(iVar7 + 0x249c);
    }
    else {
      *puVar2 = *(undefined4 *)(iVar7 + 0x2460);
      *(undefined4 *)(iVar4 + 0x76c) = *(undefined4 *)(iVar7 + 0x2464);
      *(undefined4 *)(iVar4 + 0x770) = *(undefined4 *)(iVar7 + 0x2468);
      *(undefined4 *)(iVar4 + 0x774) = *(undefined4 *)(iVar7 + 0x246c);
      *(undefined4 *)(iVar4 + 0x778) = *(undefined4 *)(iVar7 + 0x2470);
      *(undefined4 *)(iVar4 + 0x77c) = *(undefined4 *)(iVar7 + 0x2474);
      *(undefined4 *)(iVar4 + 0x780) = *(undefined4 *)(iVar7 + 0x2478);
      *(undefined4 *)(iVar4 + 0x784) = *(undefined4 *)(iVar7 + 0x247c);
      *(undefined4 *)(iVar4 + 0x788) = *(undefined4 *)(iVar7 + 0x2480);
      *(undefined4 *)(iVar4 + 0x78c) = *(undefined4 *)(iVar7 + 0x2484);
      *(undefined4 *)(iVar4 + 0x790) = *(undefined4 *)(iVar7 + 0x2488);
      *(undefined4 *)(iVar4 + 0x794) = *(undefined4 *)(iVar7 + 0x248c);
      *(undefined4 *)(iVar4 + 0x798) = *(undefined4 *)(iVar7 + 0x2490);
      *(undefined4 *)(iVar4 + 0x79c) = *(undefined4 *)(iVar7 + 0x2494);
      *(undefined4 *)(iVar4 + 0x7a0) = *(undefined4 *)(iVar7 + 0x2498);
      *(undefined4 *)(iVar4 + 0x7a4) = *(undefined4 *)(iVar7 + 0x249c);
    }
    *(undefined4 *)(iVar4 + 0x1768) = 0xf;
    *(undefined4 *)(iVar4 + 0x1788) = 4;
  }
  if ((*(char *)(iVar4 + 0x751) != '\0') && (iVar1 == *(int *)(param_1 + 0x148c))) {
    (**(code **)(param_1 + 0x12a0))(param_1,iVar1);
    return;
  }
  return;
}

/* FUN_000639c6 @ 0x639c6 (50 bytes) */
int FUN_000639c6(param_1, param_2)
  int param_1;
  int param_2;
{
  if (((*(byte *)(param_1 + 0x45) & 8) == 0) || (*(char *)(param_1 + 0x124) != '\0')) {
    (**(code **)(param_1 + 0x1298))(param_1,*(int *)(param_2 + 0x54) + 0x750);
  }
  return;
}

/* FUN_000639f8 @ 0x639f8 (5 bytes) */
int FUN_000639f8()
{
  return;
}

/* FUN_000639fd @ 0x639fd (246 bytes) */
int FUN_000639fd(param_1, param_2)
  int param_1;
  int param_2;
{
  uint *puVar1;
  void *pvVar2;
  uint uVar3;
  
  puVar1 = (uint *)(param_2 + 0x754);
  if (*(uint *)(param_2 + 0x758) <= *(uint *)(param_2 + 0x754)) {
    pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 0x758) * 4 + 0x200);
    if (*(void **)(param_2 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar2,*(void **)(param_2 + 0x75c),*(int *)(param_2 + 0x754) << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0x75c));
    }
    *(void **)(param_2 + 0x75c) = pvVar2;
    *(int *)(param_2 + 0x758) = *(int *)(param_2 + 0x758) + 0x80;
  }
  *(undefined4 *)(*(int *)(param_2 + 0x75c) + *puVar1 * 4) = 1;
  uVar3 = *puVar1 + 1;
  *puVar1 = uVar3;
  if (uVar3 < *(uint *)(param_2 + 0x758)) {
    *(undefined4 *)(*(int *)(param_2 + 0x75c) + uVar3 * 4) = 0x200;
    *puVar1 = *puVar1 + 1;
    return;
  }
  pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 0x758) * 4 + 0x200);
  if (*(void **)(param_2 + 0x75c) != (void *)0x0) {
    _memcpy(pvVar2,*(void **)(param_2 + 0x75c),*puVar1 << 2);
    (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0x75c));
  }
  *(void **)(param_2 + 0x75c) = pvVar2;
  *(int *)(param_2 + 0x758) = *(int *)(param_2 + 0x758) + 0x80;
  *(undefined4 *)(*(int *)(param_2 + 0x75c) + *puVar1 * 4) = 0x200;
  *puVar1 = *puVar1 + 1;
  return;
}

/* FUN_00063af3 @ 0x63af3 (159 bytes) */
int FUN_00063af3(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  void *pvVar2;
  
  piVar1 = (int *)(param_2 + 0x754);
  if (*(uint *)(param_2 + 0x754) < *(uint *)(param_2 + 0x758)) {
    *(undefined4 *)(*(int *)(param_2 + 0x75c) + *piVar1 * 4) = 0x28;
    *piVar1 = *piVar1 + 1;
    return;
  }
  pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 0x758) * 4 + 0x200);
  if (*(void **)(param_2 + 0x75c) != (void *)0x0) {
    _memcpy(pvVar2,*(void **)(param_2 + 0x75c),*(int *)(param_2 + 0x754) << 2);
    (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0x75c));
  }
  *(void **)(param_2 + 0x75c) = pvVar2;
  *(int *)(param_2 + 0x758) = *(int *)(param_2 + 0x758) + 0x80;
  *(undefined4 *)(*(int *)(param_2 + 0x75c) + *piVar1 * 4) = 0x28;
  *piVar1 = *piVar1 + 1;
  return;
}

/* FUN_00063b92 @ 0x63b92 (1616 bytes) */
int FUN_00063b92(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  int param_1;
  uint param_2;
  int param_3;
  int *param_4;
  uint param_5;
  int param_6;
  byte *param_7;
  uint *param_8;
  uint param_9;
  int param_10;
  byte *param_11;
  uint *param_12;
{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  uint *puVar4;
  uint uVar5;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  
  puVar4 = (uint *)(param_1 + 0x754);
  local_54 = 0;
  uVar5 = 0;
  local_48 = 0;
  local_44 = (uint)param_3 | (param_2 & 0x3f) << 0x10;
  if ((param_2 == 0x12) || (param_2 == 0x13)) {
    local_44 = local_44 | 0x400000;
    local_48 = 0x55;
  }
  if ((((*param_4 == 0) || (param_4[1] == 0)) || (param_4[2] == 0)) || (param_4[3] == 0)) {
    local_44 = local_44 | 0x400000;
    local_48 = (uint)(*param_4 != 0) | (uint)(param_4[1] != 0) << 2 | (uint)(param_4[2] != 0) << 4 |
               (uint)(param_4[3] != 0) << 6;
  }
  local_4c = (uint)param_6 | (param_5 & 0x3f) << 0x10;
  if (((((*param_8 != 0) || (param_8[1] != 0)) ||
       ((param_8[2] != 0 || ((param_8[3] != 0 || (*(int *)param_7 != 0)))))) ||
      (*(int *)(param_7 + 4) != 1)) ||
     ((*(int *)(param_7 + 8) != 2 || (*(int *)(param_7 + 0xc) != 3)))) {
    local_4c = local_4c | 0x400000;
    uVar5 = *param_7 & 7 | (*param_8 & 1) * 8 | (param_7[4] & 7) << 4 | ((byte)param_8[1] & 1) << 7
            | (param_7[8] & 7) << 8 | ((byte)param_8[2] & 1) << 0xb | (param_7[0xc] & 7) << 0xc |
            ((byte)param_8[3] & 1) << 0xf;
  }
  local_50 = (uint)param_10 | (param_9 & 0x3f) << 0x10;
  if ((((*param_12 != 0) || (param_12[1] != 0)) || (param_12[2] != 0)) ||
     (((param_12[3] != 0 || (*(int *)param_11 != 0)) ||
      ((*(int *)(param_11 + 4) != 1 ||
       ((*(int *)(param_11 + 8) != 2 || (*(int *)(param_11 + 0xc) != 3)))))))) {
    local_50 = local_50 | 0x400000;
    local_54 = *param_11 & 7 | (*param_12 & 1) * 8 | (param_11[4] & 7) << 4 |
               ((byte)param_12[1] & 1) << 7 | (param_11[8] & 7) << 8 |
               ((byte)param_12[2] & 1) << 0xb | (param_11[0xc] & 7) << 0xc |
               ((byte)param_12[3] & 1) << 0xf;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = 0x23;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_44;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  if ((local_44 & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_48;
    *puVar4 = *puVar4 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_4c;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  if ((local_4c & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = uVar5;
    *puVar4 = *puVar4 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_50;
  uVar5 = *puVar4;
  *puVar4 = uVar5 + 1;
  if ((local_50 & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar5 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_54;
    *puVar4 = *puVar4 + 1;
  }
  return;
}

/* FUN_000641e2 @ 0x641e2 (1104 bytes) */
int FUN_000641e2(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  int param_3;
  int *param_4;
  uint param_5;
  int param_6;
  byte *param_7;
  uint *param_8;
{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  uint *puVar4;
  uint uVar5;
  uint local_44;
  uint local_40;
  uint local_3c;
  
  puVar4 = (uint *)(param_1 + 0x754);
  uVar5 = 0;
  local_40 = 0;
  local_3c = (uint)param_3 | (param_2 & 0x3f) << 0x10;
  if ((param_2 == 0x12) || (param_2 == 0x13)) {
    local_3c = local_3c | 0x400000;
    local_40 = 0x55;
  }
  if ((((*param_4 == 0) || (param_4[1] == 0)) || (param_4[2] == 0)) || (param_4[3] == 0)) {
    local_3c = local_3c | 0x400000;
    local_40 = (uint)(*param_4 != 0) | (uint)(param_4[1] != 0) << 2 | (uint)(param_4[2] != 0) << 4 |
               (uint)(param_4[3] != 0) << 6;
  }
  local_44 = (uint)param_6 | (param_5 & 0x3f) << 0x10;
  if (((((*param_8 != 0) || (param_8[1] != 0)) ||
       ((param_8[2] != 0 || ((param_8[3] != 0 || (*(int *)param_7 != 0)))))) ||
      (*(int *)(param_7 + 4) != 1)) ||
     ((*(int *)(param_7 + 8) != 2 || (*(int *)(param_7 + 0xc) != 3)))) {
    local_44 = local_44 | 0x400000;
    uVar5 = *param_7 & 7 | (*param_8 & 1) * 8 | (param_7[4] & 7) << 4 | ((byte)param_8[1] & 1) << 7
            | (param_7[8] & 7) << 8 | ((byte)param_8[2] & 1) << 0xb | (param_7[0xc] & 7) << 0xc |
            ((byte)param_8[3] & 1) << 0xf;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = 0x47;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_3c;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  if ((local_3c & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_40;
    *puVar4 = *puVar4 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_44;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  if ((local_44 & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = uVar5;
    *puVar4 = *puVar4 + 1;
  }
  return;
}

/* FUN_00064632 @ 0x64632 (1616 bytes) */
int FUN_00064632(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  int param_1;
  uint param_2;
  int param_3;
  int *param_4;
  uint param_5;
  int param_6;
  byte *param_7;
  uint *param_8;
  uint param_9;
  int param_10;
  byte *param_11;
  uint *param_12;
{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  uint *puVar4;
  uint uVar5;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  
  puVar4 = (uint *)(param_1 + 0x754);
  local_54 = 0;
  uVar5 = 0;
  local_48 = 0;
  local_44 = (uint)param_3 | (param_2 & 0x3f) << 0x10;
  if ((param_2 == 0x12) || (param_2 == 0x13)) {
    local_44 = local_44 | 0x400000;
    local_48 = 0x55;
  }
  if ((((*param_4 == 0) || (param_4[1] == 0)) || (param_4[2] == 0)) || (param_4[3] == 0)) {
    local_44 = local_44 | 0x400000;
    local_48 = (uint)(*param_4 != 0) | (uint)(param_4[1] != 0) << 2 | (uint)(param_4[2] != 0) << 4 |
               (uint)(param_4[3] != 0) << 6;
  }
  local_4c = (uint)param_6 | (param_5 & 0x3f) << 0x10;
  if (((((*param_8 != 0) || (param_8[1] != 0)) ||
       ((param_8[2] != 0 || ((param_8[3] != 0 || (*(int *)param_7 != 0)))))) ||
      (*(int *)(param_7 + 4) != 1)) ||
     ((*(int *)(param_7 + 8) != 2 || (*(int *)(param_7 + 0xc) != 3)))) {
    local_4c = local_4c | 0x400000;
    uVar5 = *param_7 & 7 | (*param_8 & 1) * 8 | (param_7[4] & 7) << 4 | ((byte)param_8[1] & 1) << 7
            | (param_7[8] & 7) << 8 | ((byte)param_8[2] & 1) << 0xb | (param_7[0xc] & 7) << 0xc |
            ((byte)param_8[3] & 1) << 0xf;
  }
  local_50 = (uint)param_10 | (param_9 & 0x3f) << 0x10;
  if ((((*param_12 != 0) || (param_12[1] != 0)) || (param_12[2] != 0)) ||
     (((param_12[3] != 0 || (*(int *)param_11 != 0)) ||
      ((*(int *)(param_11 + 4) != 1 ||
       ((*(int *)(param_11 + 8) != 2 || (*(int *)(param_11 + 0xc) != 3)))))))) {
    local_50 = local_50 | 0x400000;
    local_54 = *param_11 & 7 | (*param_12 & 1) * 8 | (param_11[4] & 7) << 4 |
               ((byte)param_12[1] & 1) << 7 | (param_11[8] & 7) << 8 |
               ((byte)param_12[2] & 1) << 0xb | (param_11[0xc] & 7) << 0xc |
               ((byte)param_12[3] & 1) << 0xf;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = 0x49;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_44;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  if ((local_44 & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_48;
    *puVar4 = *puVar4 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_4c;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  if ((local_4c & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = uVar5;
    *puVar4 = *puVar4 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_50;
  uVar5 = *puVar4;
  *puVar4 = uVar5 + 1;
  if ((local_50 & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar5 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_54;
    *puVar4 = *puVar4 + 1;
  }
  return;
}

/* FUN_00064c82 @ 0x64c82 (1616 bytes) */
int FUN_00064c82(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  int param_1;
  uint param_2;
  int param_3;
  int *param_4;
  uint param_5;
  int param_6;
  byte *param_7;
  uint *param_8;
  uint param_9;
  int param_10;
  byte *param_11;
  uint *param_12;
{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  uint *puVar4;
  uint uVar5;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  
  puVar4 = (uint *)(param_1 + 0x754);
  local_54 = 0;
  uVar5 = 0;
  local_48 = 0;
  local_44 = (uint)param_3 | (param_2 & 0x3f) << 0x10;
  if ((param_2 == 0x12) || (param_2 == 0x13)) {
    local_44 = local_44 | 0x400000;
    local_48 = 0x55;
  }
  if ((((*param_4 == 0) || (param_4[1] == 0)) || (param_4[2] == 0)) || (param_4[3] == 0)) {
    local_44 = local_44 | 0x400000;
    local_48 = (uint)(*param_4 != 0) | (uint)(param_4[1] != 0) << 2 | (uint)(param_4[2] != 0) << 4 |
               (uint)(param_4[3] != 0) << 6;
  }
  local_4c = (uint)param_6 | (param_5 & 0x3f) << 0x10;
  if (((((*param_8 != 0) || (param_8[1] != 0)) ||
       ((param_8[2] != 0 || ((param_8[3] != 0 || (*(int *)param_7 != 0)))))) ||
      (*(int *)(param_7 + 4) != 1)) ||
     ((*(int *)(param_7 + 8) != 2 || (*(int *)(param_7 + 0xc) != 3)))) {
    local_4c = local_4c | 0x400000;
    uVar5 = *param_7 & 7 | (*param_8 & 1) * 8 | (param_7[4] & 7) << 4 | ((byte)param_8[1] & 1) << 7
            | (param_7[8] & 7) << 8 | ((byte)param_8[2] & 1) << 0xb | (param_7[0xc] & 7) << 0xc |
            ((byte)param_8[3] & 1) << 0xf;
  }
  local_50 = (uint)param_10 | (param_9 & 0x3f) << 0x10;
  if ((((*param_12 != 0) || (param_12[1] != 0)) || (param_12[2] != 0)) ||
     (((param_12[3] != 0 || (*(int *)param_11 != 0)) ||
      ((*(int *)(param_11 + 4) != 1 ||
       ((*(int *)(param_11 + 8) != 2 || (*(int *)(param_11 + 0xc) != 3)))))))) {
    local_50 = local_50 | 0x400000;
    local_54 = *param_11 & 7 | (*param_12 & 1) * 8 | (param_11[4] & 7) << 4 |
               ((byte)param_12[1] & 1) << 7 | (param_11[8] & 7) << 8 |
               ((byte)param_12[2] & 1) << 0xb | (param_11[0xc] & 7) << 0xc |
               ((byte)param_12[3] & 1) << 0xf;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = 3;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_44;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  if ((local_44 & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_48;
    *puVar4 = *puVar4 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_4c;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  if ((local_4c & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = uVar5;
    *puVar4 = *puVar4 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_50;
  uVar5 = *puVar4;
  *puVar4 = uVar5 + 1;
  if ((local_50 & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar5 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_54;
    *puVar4 = *puVar4 + 1;
  }
  return;
}

/* FUN_000652d2 @ 0x652d2 (2129 bytes) */
int FUN_000652d2(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13, param_14, param_15, param_16)
  int param_1;
  uint param_2;
  int param_3;
  int *param_4;
  uint param_5;
  int param_6;
  byte *param_7;
  uint *param_8;
  uint param_9;
  int param_10;
  byte *param_11;
  uint *param_12;
  uint param_13;
  int param_14;
  byte *param_15;
  uint *param_16;
{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  uint *puVar4;
  uint uVar5;
  uint local_64;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  
  puVar4 = (uint *)(param_1 + 0x754);
  local_64 = 0;
  local_5c = 0;
  uVar5 = 0;
  local_50 = 0;
  local_4c = (uint)param_3 | (param_2 & 0x3f) << 0x10;
  if ((param_2 == 0x12) || (param_2 == 0x13)) {
    local_4c = local_4c | 0x400000;
    local_50 = 0x55;
  }
  if ((((*param_4 == 0) || (param_4[1] == 0)) || (param_4[2] == 0)) || (param_4[3] == 0)) {
    local_4c = local_4c | 0x400000;
    local_50 = (uint)(*param_4 != 0) | (uint)(param_4[1] != 0) << 2 | (uint)(param_4[2] != 0) << 4 |
               (uint)(param_4[3] != 0) << 6;
  }
  local_54 = (uint)param_6 | (param_5 & 0x3f) << 0x10;
  if (((((*param_8 != 0) || (param_8[1] != 0)) ||
       ((param_8[2] != 0 || ((param_8[3] != 0 || (*(int *)param_7 != 0)))))) ||
      (*(int *)(param_7 + 4) != 1)) ||
     ((*(int *)(param_7 + 8) != 2 || (*(int *)(param_7 + 0xc) != 3)))) {
    local_54 = local_54 | 0x400000;
    uVar5 = *param_7 & 7 | (*param_8 & 1) * 8 | (param_7[4] & 7) << 4 | ((byte)param_8[1] & 1) << 7
            | (param_7[8] & 7) << 8 | ((byte)param_8[2] & 1) << 0xb | (param_7[0xc] & 7) << 0xc |
            ((byte)param_8[3] & 1) << 0xf;
  }
  local_58 = (uint)param_10 | (param_9 & 0x3f) << 0x10;
  if ((((*param_12 != 0) || (param_12[1] != 0)) || (param_12[2] != 0)) ||
     (((param_12[3] != 0 || (*(int *)param_11 != 0)) ||
      ((*(int *)(param_11 + 4) != 1 ||
       ((*(int *)(param_11 + 8) != 2 || (*(int *)(param_11 + 0xc) != 3)))))))) {
    local_58 = local_58 | 0x400000;
    local_5c = *param_11 & 7 | (*param_12 & 1) * 8 | (param_11[4] & 7) << 4 |
               ((byte)param_12[1] & 1) << 7 | (param_11[8] & 7) << 8 |
               ((byte)param_12[2] & 1) << 0xb | (param_11[0xc] & 7) << 0xc |
               ((byte)param_12[3] & 1) << 0xf;
  }
  local_60 = (uint)param_14 | (param_13 & 0x3f) << 0x10;
  if ((((*param_16 != 0) || (param_16[1] != 0)) || (param_16[2] != 0)) ||
     (((param_16[3] != 0 || (*(int *)param_15 != 0)) ||
      ((*(int *)(param_15 + 4) != 1 ||
       ((*(int *)(param_15 + 8) != 2 || (*(int *)(param_15 + 0xc) != 3)))))))) {
    local_60 = local_60 | 0x400000;
    local_64 = *param_15 & 7 | (*param_16 & 1) * 8 | (param_15[4] & 7) << 4 |
               ((byte)param_16[1] & 1) << 7 | (param_15[8] & 7) << 8 |
               ((byte)param_16[2] & 1) << 0xb | (param_15[0xc] & 7) << 0xc |
               ((byte)param_16[3] & 1) << 0xf;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = 0x40;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_4c;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  if ((local_4c & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_50;
    *puVar4 = *puVar4 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_54;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  if ((local_54 & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = uVar5;
    *puVar4 = *puVar4 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_58;
  uVar5 = *puVar4;
  *puVar4 = uVar5 + 1;
  if ((local_58 & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar5 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_5c;
    *puVar4 = *puVar4 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_60;
  uVar5 = *puVar4;
  *puVar4 = uVar5 + 1;
  if ((local_60 & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar5 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_64;
    *puVar4 = *puVar4 + 1;
  }
  return;
}

/* FUN_00065b23 @ 0x65b23 (3364 bytes) */
int FUN_00065b23(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13, param_14, param_15, param_16)
  int param_1;
  uint param_2;
  int param_3;
  int *param_4;
  int param_5;
  uint param_6;
  byte *param_7;
  uint *param_8;
  uint param_9;
  int param_10;
  byte *param_11;
  uint *param_12;
  uint param_13;
  int param_14;
  byte *param_15;
  uint *param_16;
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  void *pvVar4;
  uint uVar5;
  uint *puVar6;
  uint local_b0;
  uint local_ac;
  uint local_a8;
  uint local_a4;
  uint local_a0;
  uint local_9c;
  uint local_98;
  uint local_94;
  undefined1 local_34 [4];
  ushort local_30;
  
  puVar6 = (uint *)(param_1 + 0x754);
  local_b0 = 0;
  local_a8 = 0;
  local_a0 = 0;
  local_98 = 0;
  (**(code **)(param_1 + 0x748))(param_1,0,local_34);
  uVar5 = (uint)local_30;
  uVar3 = (uint)(param_5 & 0x3f) << 0x10;
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *(uint *)(param_1 + 0x754)) {
    pvVar4 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar4,*(void **)(param_1 + 0x75c),*(int *)(param_1 + 0x754) << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar4;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x75c) + *puVar6 * 4) = 3;
  uVar2 = *puVar6;
  *puVar6 = uVar2 + 1;
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
    pvVar4 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar4,*(void **)(param_1 + 0x75c),*puVar6 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar4;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar6 * 4) = uVar5 | 0x40000;
  *puVar6 = *puVar6 + 1;
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar6) {
    pvVar4 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar4,*(void **)(param_1 + 0x75c),*puVar6 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar4;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar6 * 4) = param_6 & 0xffff | uVar3;
  *puVar6 = *puVar6 + 1;
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar6) {
    pvVar4 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar4,*(void **)(param_1 + 0x75c),*puVar6 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar4;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar6 * 4) = param_6 & 0xffff | uVar3;
  *puVar6 = *puVar6 + 1;
  local_94 = (uint)param_3 | (param_2 & 0x3f) << 0x10;
  if (param_2 == 0x12) {
    local_94 = local_94 | 0x400000;
    local_98 = 0x55;
  }
  else if (param_2 == 0x13) {
    local_94 = local_94 | 0x400000;
    local_98 = 0x55;
  }
  if ((((*param_4 == 0) || (param_4[1] == 0)) || (param_4[2] == 0)) || (param_4[3] == 0)) {
    local_94 = local_94 | 0x400000;
    local_98 = (uint)(*param_4 != 0) | (uint)(param_4[1] != 0) << 2 | (uint)(param_4[2] != 0) << 4 |
               (uint)(param_4[3] != 0) << 6;
  }
  local_9c = (CONCAT12(param_5,local_30) & 0x3fffff) & 0xfe40ffff | (uint)(param_5 & 0x3f) << 0x10;
  if (((((*param_8 != 0) || (param_8[1] != 0)) ||
       ((param_8[2] != 0 || ((param_8[3] != 0 || (*(int *)param_7 != 0)))))) ||
      (*(int *)(param_7 + 4) != 1)) ||
     ((*(int *)(param_7 + 8) != 2 || (*(int *)(param_7 + 0xc) != 3)))) {
    local_9c = local_9c | 0x400000;
    local_a0 = *param_7 & 7 | (*param_8 & 1) * 8 | (param_7[4] & 7) << 4 |
               ((byte)param_8[1] & 1) << 7 | (param_7[8] & 7) << 8 | ((byte)param_8[2] & 1) << 0xb |
               (param_7[0xc] & 7) << 0xc | ((byte)param_8[3] & 1) << 0xf;
  }
  local_a4 = (uint)param_10 | (param_9 & 0x3f) << 0x10;
  if ((((*param_12 != 0) || (param_12[1] != 0)) || (param_12[2] != 0)) ||
     (((param_12[3] != 0 || (*(int *)param_11 != 0)) ||
      ((*(int *)(param_11 + 4) != 1 ||
       ((*(int *)(param_11 + 8) != 2 || (*(int *)(param_11 + 0xc) != 3)))))))) {
    local_a4 = local_a4 | 0x400000;
    local_a8 = *param_11 & 7 | (*param_12 & 1) * 8 | (param_11[4] & 7) << 4 |
               ((byte)param_12[1] & 1) << 7 | (param_11[8] & 7) << 8 |
               ((byte)param_12[2] & 1) << 0xb | (param_11[0xc] & 7) << 0xc |
               ((byte)param_12[3] & 1) << 0xf;
  }
  local_ac = (uint)param_14 | (param_13 & 0x3f) << 0x10;
  if ((((*param_16 != 0) || (param_16[1] != 0)) || (param_16[2] != 0)) ||
     (((param_16[3] != 0 || (*(int *)param_15 != 0)) ||
      ((*(int *)(param_15 + 4) != 1 ||
       ((*(int *)(param_15 + 8) != 2 || (*(int *)(param_15 + 0xc) != 3)))))))) {
    local_ac = local_ac | 0x400000;
    local_b0 = *param_15 & 7 | (*param_16 & 1) * 8 | (param_15[4] & 7) << 4 |
               ((byte)param_16[1] & 1) << 7 | (param_15[8] & 7) << 8 |
               ((byte)param_16[2] & 1) << 0xb | (param_15[0xc] & 7) << 0xc |
               ((byte)param_16[3] & 1) << 0xf;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar6) {
    pvVar4 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar4,*(void **)(param_1 + 0x75c),*puVar6 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar4;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x75c) + *puVar6 * 4) = 0x40;
  uVar3 = *puVar6;
  *puVar6 = uVar3 + 1;
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar3 + 1) {
    pvVar4 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar4,*(void **)(param_1 + 0x75c),*puVar6 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar4;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar6 * 4) = local_94;
  uVar3 = *puVar6;
  *puVar6 = uVar3 + 1;
  if ((local_94 & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar3 + 1) {
      pvVar4 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar4,*(void **)(param_1 + 0x75c),*puVar6 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar4;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar6 * 4) = local_98;
    *puVar6 = *puVar6 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar6) {
    pvVar4 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar4,*(void **)(param_1 + 0x75c),*puVar6 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar4;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar6 * 4) = local_9c;
  uVar3 = *puVar6;
  *puVar6 = uVar3 + 1;
  if ((local_9c & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar3 + 1) {
      pvVar4 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar4,*(void **)(param_1 + 0x75c),*puVar6 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar4;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar6 * 4) = local_a0;
    *puVar6 = *puVar6 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar6) {
    pvVar4 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar4,*(void **)(param_1 + 0x75c),*puVar6 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar4;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar6 * 4) = local_a4;
  uVar3 = *puVar6;
  *puVar6 = uVar3 + 1;
  if ((local_a4 & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar3 + 1) {
      pvVar4 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar4,*(void **)(param_1 + 0x75c),*puVar6 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar4;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar6 * 4) = local_a8;
    *puVar6 = *puVar6 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar6) {
    pvVar4 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar4,*(void **)(param_1 + 0x75c),*puVar6 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar4;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar6 * 4) = local_ac;
  uVar3 = *puVar6;
  *puVar6 = uVar3 + 1;
  if ((local_ac & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar3 + 1) {
      pvVar4 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar4,*(void **)(param_1 + 0x75c),*puVar6 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar4;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar6 * 4) = local_b0;
    *puVar6 = *puVar6 + 1;
  }
  return;
}

/* FUN_00066847 @ 0x66847 (4349 bytes) */
int FUN_00066847(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13, param_14, param_15, param_16)
  int param_1;
  uint param_2;
  int param_3;
  int *param_4;
  uint param_5;
  int param_6;
  byte *param_7;
  uint *param_8;
  uint param_9;
  int param_10;
  byte *param_11;
  uint *param_12;
  int param_13;
  int param_14;
  byte *param_15;
  byte *param_16;
{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  void *pvVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint *puVar12;
  uint local_c8;
  undefined4 local_c4;
  uint local_c0;
  uint local_bc;
  uint local_b8;
  uint local_b4;
  undefined1 local_34 [4];
  uint local_30;
  
  puVar12 = (uint *)(param_1 + 0x754);
  local_c8 = 0;
  local_c0 = 0;
  local_b8 = 0;
  (**(code **)(param_1 + 0x748))(param_1,0,local_34);
  uVar9 = local_30 & 0xffff;
  local_bc = (uint)param_6 | (param_5 & 0x3f) << 0x10;
  if ((((*param_8 != 0) || (param_8[1] != 0)) || (param_8[2] != 0)) ||
     (((param_8[3] != 0 || (*(int *)param_7 != 0)) ||
      ((*(int *)(param_7 + 4) != 1 ||
       ((*(int *)(param_7 + 8) != 2 || (*(int *)(param_7 + 0xc) != 3)))))))) {
    local_bc = local_bc | 0x400000;
    local_c0 = *param_7 & 7 | (*param_8 & 1) * 8 | (param_7[4] & 7) << 4 |
               ((byte)param_8[1] & 1) << 7 | (param_7[8] & 7) << 8 | ((byte)param_8[2] & 1) << 0xb |
               (param_7[0xc] & 7) << 0xc | ((byte)param_8[3] & 1) << 0xf;
  }
  local_c4 = (uint)param_10 | (param_9 & 0x3f) << 0x10;
  if ((((*param_12 != 0) || (param_12[1] != 0)) || (param_12[2] != 0)) ||
     (((param_12[3] != 0 || (*(int *)param_11 != 0)) ||
      ((*(int *)(param_11 + 4) != 1 ||
       ((*(int *)(param_11 + 8) != 2 || (*(int *)(param_11 + 0xc) != 3)))))))) {
    local_c4 = local_c4 | 0x400000;
    local_c8 = *param_11 & 7 | (*param_12 & 1) * 8 | (param_11[4] & 7) << 4 |
               ((byte)param_12[1] & 1) << 7 | (param_11[8] & 7) << 8 |
               ((byte)param_12[2] & 1) << 0xb | (param_11[0xc] & 7) << 0xc |
               ((byte)param_12[3] & 1) << 0xf;
  }
  iVar5 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar12) {
    pvVar8 = (void *)(**(code **)(iVar5 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar8,*(void **)(param_1 + 0x75c),*puVar12 << 2);
      (**(code **)(iVar5 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar8;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x75c) + *puVar12 * 4) = 0x49;
  uVar11 = *puVar12;
  *puVar12 = uVar11 + 1;
  iVar5 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar11 + 1) {
    pvVar8 = (void *)(**(code **)(iVar5 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar8,*(void **)(param_1 + 0x75c),*puVar12 << 2);
      (**(code **)(iVar5 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar8;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar12 * 4) = uVar9 | 0x40000;
  *puVar12 = *puVar12 + 1;
  iVar5 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar12) {
    pvVar8 = (void *)(**(code **)(iVar5 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar8,*(void **)(param_1 + 0x75c),*puVar12 << 2);
      (**(code **)(iVar5 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar8;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar12 * 4) = local_bc;
  uVar9 = *puVar12;
  *puVar12 = uVar9 + 1;
  if ((local_bc & 0x400000) != 0) {
    iVar5 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar9 + 1) {
      pvVar8 = (void *)(**(code **)(iVar5 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar8,*(void **)(param_1 + 0x75c),*puVar12 << 2);
        (**(code **)(iVar5 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar8;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar12 * 4) = local_c0;
    *puVar12 = *puVar12 + 1;
  }
  iVar5 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar12) {
    pvVar8 = (void *)(**(code **)(iVar5 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar8,*(void **)(param_1 + 0x75c),*puVar12 << 2);
      (**(code **)(iVar5 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar8;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar12 * 4) = local_c4;
  uVar9 = *puVar12;
  *puVar12 = uVar9 + 1;
  if ((local_c4 & 0x400000) != 0) {
    iVar5 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar9 + 1) {
      pvVar8 = (void *)(**(code **)(iVar5 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar8,*(void **)(param_1 + 0x75c),*puVar12 << 2);
        (**(code **)(iVar5 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar8;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar12 * 4) = local_c8;
    *puVar12 = *puVar12 + 1;
  }
  uVar7 = (uint)(ushort)local_30;
  local_bc = CONCAT22((*(unsigned short *)((unsigned char *)&(local_bc) + 2)),(ushort)local_30);
  uVar9 = local_bc & 0xfe40ffff | 0x440000;
  local_c4 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_c4) + 2)),param_14);
  uVar11 = local_c4 & 0xfe40ffff | (uint)(param_13 & 0x3f) << 0x10 | 0x400000;
  uVar10 = (uint)(*param_15 & 7);
  bVar1 = *param_16;
  bVar2 = param_16[4];
  bVar3 = param_16[8];
  bVar4 = param_16[0xc];
  iVar5 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar12) {
    pvVar8 = (void *)(**(code **)(iVar5 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar8,*(void **)(param_1 + 0x75c),*puVar12 << 2);
      (**(code **)(iVar5 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar8;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x75c) + *puVar12 * 4) = 0x41;
  uVar6 = *puVar12;
  *puVar12 = uVar6 + 1;
  iVar5 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar6 + 1) {
    pvVar8 = (void *)(**(code **)(iVar5 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar8,*(void **)(param_1 + 0x75c),*puVar12 << 2);
      (**(code **)(iVar5 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar8;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar12 * 4) = uVar7 | 0x40000;
  *puVar12 = *puVar12 + 1;
  iVar5 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar12) {
    pvVar8 = (void *)(**(code **)(iVar5 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar8,*(void **)(param_1 + 0x75c),*puVar12 << 2);
      (**(code **)(iVar5 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar8;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar12 * 4) = uVar9;
  uVar7 = *puVar12;
  *puVar12 = uVar7 + 1;
  if ((uVar9 & 0x400000) != 0) {
    iVar5 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar7 + 1) {
      pvVar8 = (void *)(**(code **)(iVar5 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar8,*(void **)(param_1 + 0x75c),*puVar12 << 2);
        (**(code **)(iVar5 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar8;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(undefined4 *)(*(int *)(param_1 + 0x75c) + *puVar12 * 4) = 0x3333;
    *puVar12 = *puVar12 + 1;
  }
  iVar5 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar12) {
    pvVar8 = (void *)(**(code **)(iVar5 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar8,*(void **)(param_1 + 0x75c),*puVar12 << 2);
      (**(code **)(iVar5 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar8;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar12 * 4) = uVar11;
  uVar7 = *puVar12;
  *puVar12 = uVar7 + 1;
  iVar5 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar7 + 1) {
    pvVar8 = (void *)(**(code **)(iVar5 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar8,*(void **)(param_1 + 0x75c),*puVar12 << 2);
      (**(code **)(iVar5 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar8;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar12 * 4) =
       uVar10 | (bVar1 & 1) << 3 | uVar10 << 4 | (bVar2 & 1) << 7 | uVar10 << 8 | (bVar3 & 1) << 0xb
       | uVar10 << 0xc | (bVar4 & 1) << 0xf;
  *puVar12 = *puVar12 + 1;
  local_b4 = (uint)param_3 | (param_2 & 0x3f) << 0x10;
  if (param_2 == 0x12) {
    local_b4 = local_b4 | 0x400000;
    local_b8 = 0x55;
  }
  else if (param_2 == 0x13) {
    local_b4 = local_b4 | 0x400000;
    local_b8 = 0x55;
  }
  if ((((*param_4 == 0) || (param_4[1] == 0)) || (param_4[2] == 0)) || (param_4[3] == 0)) {
    local_b4 = local_b4 | 0x400000;
    local_b8 = (uint)(*param_4 != 0) | (uint)(param_4[1] != 0) << 2 | (uint)(param_4[2] != 0) << 4 |
               (uint)(param_4[3] != 0) << 6;
  }
  uVar9 = CONCAT22((short)(uVar9 >> 0x10),(ushort)local_30) & 0xfe40ffff | 0x440000;
  (*(unsigned short *)((unsigned char *)&(local_c4) + 2)) = (undefined2)(uVar11 >> 0x10);
  local_c4 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_c4) + 2)),param_14);
  uVar11 = *(uint *)(param_15 + 0xc) & 7;
  bVar1 = *param_16;
  bVar2 = param_16[4];
  bVar3 = param_16[8];
  bVar4 = param_16[0xc];
  iVar5 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar12) {
    pvVar8 = (void *)(**(code **)(iVar5 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar8,*(void **)(param_1 + 0x75c),*puVar12 << 2);
      (**(code **)(iVar5 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar8;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x75c) + *puVar12 * 4) = 0x44;
  uVar7 = *puVar12;
  *puVar12 = uVar7 + 1;
  iVar5 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar7 + 1) {
    pvVar8 = (void *)(**(code **)(iVar5 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar8,*(void **)(param_1 + 0x75c),*puVar12 << 2);
      (**(code **)(iVar5 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar8;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar12 * 4) = local_b4;
  uVar7 = *puVar12;
  *puVar12 = uVar7 + 1;
  if ((local_b4 & 0x400000) != 0) {
    iVar5 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar7 + 1) {
      pvVar8 = (void *)(**(code **)(iVar5 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar8,*(void **)(param_1 + 0x75c),*puVar12 << 2);
        (**(code **)(iVar5 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar8;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar12 * 4) = local_b8;
    *puVar12 = *puVar12 + 1;
  }
  iVar5 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar12) {
    pvVar8 = (void *)(**(code **)(iVar5 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar8,*(void **)(param_1 + 0x75c),*puVar12 << 2);
      (**(code **)(iVar5 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar8;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar12 * 4) = uVar9;
  uVar7 = *puVar12;
  *puVar12 = uVar7 + 1;
  if ((uVar9 & 0x400000) != 0) {
    iVar5 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar7 + 1) {
      pvVar8 = (void *)(**(code **)(iVar5 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar8,*(void **)(param_1 + 0x75c),*puVar12 << 2);
        (**(code **)(iVar5 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar8;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(undefined4 *)(*(int *)(param_1 + 0x75c) + *puVar12 * 4) = 0x3333;
    *puVar12 = *puVar12 + 1;
  }
  iVar5 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar12) {
    pvVar8 = (void *)(**(code **)(iVar5 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar8,*(void **)(param_1 + 0x75c),*puVar12 << 2);
      (**(code **)(iVar5 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar8;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar12 * 4) =
       local_c4 & 0xfe40ffff | (uint)(param_13 & 0x3f) << 0x10 | 0x400000;
  uVar9 = *puVar12;
  *puVar12 = uVar9 + 1;
  iVar5 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar9 + 1) {
    pvVar8 = (void *)(**(code **)(iVar5 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar8,*(void **)(param_1 + 0x75c),*puVar12 << 2);
      (**(code **)(iVar5 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar8;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar12 * 4) =
       uVar11 | (bVar1 & 1) << 3 | uVar11 << 4 | (bVar2 & 1) << 7 | uVar11 << 8 | (bVar3 & 1) << 0xb
       | uVar11 << 0xc | (bVar4 & 1) << 0xf;
  *puVar12 = *puVar12 + 1;
  (**(code **)(param_1 + 0x74c))(param_1,local_34);
  return;
}

/* FUN_00067944 @ 0x67944 (1616 bytes) */
int FUN_00067944(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  int param_1;
  uint param_2;
  int param_3;
  int *param_4;
  uint param_5;
  int param_6;
  byte *param_7;
  uint *param_8;
  uint param_9;
  int param_10;
  byte *param_11;
  uint *param_12;
{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  uint *puVar4;
  uint uVar5;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  
  puVar4 = (uint *)(param_1 + 0x754);
  local_54 = 0;
  uVar5 = 0;
  local_48 = 0;
  local_44 = (uint)param_3 | (param_2 & 0x3f) << 0x10;
  if ((param_2 == 0x12) || (param_2 == 0x13)) {
    local_44 = local_44 | 0x400000;
    local_48 = 0x55;
  }
  if ((((*param_4 == 0) || (param_4[1] == 0)) || (param_4[2] == 0)) || (param_4[3] == 0)) {
    local_44 = local_44 | 0x400000;
    local_48 = (uint)(*param_4 != 0) | (uint)(param_4[1] != 0) << 2 | (uint)(param_4[2] != 0) << 4 |
               (uint)(param_4[3] != 0) << 6;
  }
  local_4c = (uint)param_6 | (param_5 & 0x3f) << 0x10;
  if (((((*param_8 != 0) || (param_8[1] != 0)) ||
       ((param_8[2] != 0 || ((param_8[3] != 0 || (*(int *)param_7 != 0)))))) ||
      (*(int *)(param_7 + 4) != 1)) ||
     ((*(int *)(param_7 + 8) != 2 || (*(int *)(param_7 + 0xc) != 3)))) {
    local_4c = local_4c | 0x400000;
    uVar5 = *param_7 & 7 | (*param_8 & 1) * 8 | (param_7[4] & 7) << 4 | ((byte)param_8[1] & 1) << 7
            | (param_7[8] & 7) << 8 | ((byte)param_8[2] & 1) << 0xb | (param_7[0xc] & 7) << 0xc |
            ((byte)param_8[3] & 1) << 0xf;
  }
  local_50 = (uint)param_10 | (param_9 & 0x3f) << 0x10;
  if ((((*param_12 != 0) || (param_12[1] != 0)) || (param_12[2] != 0)) ||
     (((param_12[3] != 0 || (*(int *)param_11 != 0)) ||
      ((*(int *)(param_11 + 4) != 1 ||
       ((*(int *)(param_11 + 8) != 2 || (*(int *)(param_11 + 0xc) != 3)))))))) {
    local_50 = local_50 | 0x400000;
    local_54 = *param_11 & 7 | (*param_12 & 1) * 8 | (param_11[4] & 7) << 4 |
               ((byte)param_12[1] & 1) << 7 | (param_11[8] & 7) << 8 |
               ((byte)param_12[2] & 1) << 0xb | (param_11[0xc] & 7) << 0xc |
               ((byte)param_12[3] & 1) << 0xf;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = 0x44;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_44;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  if ((local_44 & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_48;
    *puVar4 = *puVar4 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_4c;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  if ((local_4c & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = uVar5;
    *puVar4 = *puVar4 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_50;
  uVar5 = *puVar4;
  *puVar4 = uVar5 + 1;
  if ((local_50 & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar5 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_54;
    *puVar4 = *puVar4 + 1;
  }
  return;
}

/* FUN_00067f94 @ 0x67f94 (1616 bytes) */
int FUN_00067f94(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  int param_1;
  uint param_2;
  int param_3;
  int *param_4;
  uint param_5;
  int param_6;
  byte *param_7;
  uint *param_8;
  uint param_9;
  int param_10;
  byte *param_11;
  uint *param_12;
{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  uint *puVar4;
  uint uVar5;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  
  puVar4 = (uint *)(param_1 + 0x754);
  local_54 = 0;
  uVar5 = 0;
  local_48 = 0;
  local_44 = (uint)param_3 | (param_2 & 0x3f) << 0x10;
  if ((param_2 == 0x12) || (param_2 == 0x13)) {
    local_44 = local_44 | 0x400000;
    local_48 = 0x55;
  }
  if ((((*param_4 == 0) || (param_4[1] == 0)) || (param_4[2] == 0)) || (param_4[3] == 0)) {
    local_44 = local_44 | 0x400000;
    local_48 = (uint)(*param_4 != 0) | (uint)(param_4[1] != 0) << 2 | (uint)(param_4[2] != 0) << 4 |
               (uint)(param_4[3] != 0) << 6;
  }
  local_4c = (uint)param_6 | (param_5 & 0x3f) << 0x10;
  if (((((*param_8 != 0) || (param_8[1] != 0)) ||
       ((param_8[2] != 0 || ((param_8[3] != 0 || (*(int *)param_7 != 0)))))) ||
      (*(int *)(param_7 + 4) != 1)) ||
     ((*(int *)(param_7 + 8) != 2 || (*(int *)(param_7 + 0xc) != 3)))) {
    local_4c = local_4c | 0x400000;
    uVar5 = *param_7 & 7 | (*param_8 & 1) * 8 | (param_7[4] & 7) << 4 | ((byte)param_8[1] & 1) << 7
            | (param_7[8] & 7) << 8 | ((byte)param_8[2] & 1) << 0xb | (param_7[0xc] & 7) << 0xc |
            ((byte)param_8[3] & 1) << 0xf;
  }
  local_50 = (uint)param_10 | (param_9 & 0x3f) << 0x10;
  if ((((*param_12 != 0) || (param_12[1] != 0)) || (param_12[2] != 0)) ||
     (((param_12[3] != 0 || (*(int *)param_11 != 0)) ||
      ((*(int *)(param_11 + 4) != 1 ||
       ((*(int *)(param_11 + 8) != 2 || (*(int *)(param_11 + 0xc) != 3)))))))) {
    local_50 = local_50 | 0x400000;
    local_54 = *param_11 & 7 | (*param_12 & 1) * 8 | (param_11[4] & 7) << 4 |
               ((byte)param_12[1] & 1) << 7 | (param_11[8] & 7) << 8 |
               ((byte)param_12[2] & 1) << 0xb | (param_11[0xc] & 7) << 0xc |
               ((byte)param_12[3] & 1) << 0xf;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = 0x41;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_44;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  if ((local_44 & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_48;
    *puVar4 = *puVar4 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_4c;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  if ((local_4c & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = uVar5;
    *puVar4 = *puVar4 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_50;
  uVar5 = *puVar4;
  *puVar4 = uVar5 + 1;
  if ((local_50 & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar5 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_54;
    *puVar4 = *puVar4 + 1;
  }
  return;
}

/* FUN_000685e4 @ 0x685e4 (1616 bytes) */
int FUN_000685e4(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  int param_1;
  uint param_2;
  int param_3;
  int *param_4;
  uint param_5;
  int param_6;
  byte *param_7;
  uint *param_8;
  uint param_9;
  int param_10;
  byte *param_11;
  uint *param_12;
{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  uint *puVar4;
  uint uVar5;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  
  puVar4 = (uint *)(param_1 + 0x754);
  local_54 = 0;
  uVar5 = 0;
  local_48 = 0;
  local_44 = (uint)param_3 | (param_2 & 0x3f) << 0x10;
  if ((param_2 == 0x12) || (param_2 == 0x13)) {
    local_44 = local_44 | 0x400000;
    local_48 = 0x55;
  }
  if ((((*param_4 == 0) || (param_4[1] == 0)) || (param_4[2] == 0)) || (param_4[3] == 0)) {
    local_44 = local_44 | 0x400000;
    local_48 = (uint)(*param_4 != 0) | (uint)(param_4[1] != 0) << 2 | (uint)(param_4[2] != 0) << 4 |
               (uint)(param_4[3] != 0) << 6;
  }
  local_4c = (uint)param_6 | (param_5 & 0x3f) << 0x10;
  if (((((*param_8 != 0) || (param_8[1] != 0)) ||
       ((param_8[2] != 0 || ((param_8[3] != 0 || (*(int *)param_7 != 0)))))) ||
      (*(int *)(param_7 + 4) != 1)) ||
     ((*(int *)(param_7 + 8) != 2 || (*(int *)(param_7 + 0xc) != 3)))) {
    local_4c = local_4c | 0x400000;
    uVar5 = *param_7 & 7 | (*param_8 & 1) * 8 | (param_7[4] & 7) << 4 | ((byte)param_8[1] & 1) << 7
            | (param_7[8] & 7) << 8 | ((byte)param_8[2] & 1) << 0xb | (param_7[0xc] & 7) << 0xc |
            ((byte)param_8[3] & 1) << 0xf;
  }
  local_50 = (uint)param_10 | (param_9 & 0x3f) << 0x10;
  if ((((*param_12 != 0) || (param_12[1] != 0)) || (param_12[2] != 0)) ||
     (((param_12[3] != 0 || (*(int *)param_11 != 0)) ||
      ((*(int *)(param_11 + 4) != 1 ||
       ((*(int *)(param_11 + 8) != 2 || (*(int *)(param_11 + 0xc) != 3)))))))) {
    local_50 = local_50 | 0x400000;
    local_54 = *param_11 & 7 | (*param_12 & 1) * 8 | (param_11[4] & 7) << 4 |
               ((byte)param_12[1] & 1) << 7 | (param_11[8] & 7) << 8 |
               ((byte)param_12[2] & 1) << 0xb | (param_11[0xc] & 7) << 0xc |
               ((byte)param_12[3] & 1) << 0xf;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = 0x50056;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_44;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  if ((local_44 & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_48;
    *puVar4 = *puVar4 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_4c;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  if ((local_4c & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = uVar5;
    *puVar4 = *puVar4 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_50;
  uVar5 = *puVar4;
  *puVar4 = uVar5 + 1;
  if ((local_50 & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar5 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_54;
    *puVar4 = *puVar4 + 1;
  }
  return;
}

/* FUN_00068c34 @ 0x68c34 (1616 bytes) */
int FUN_00068c34(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  int param_1;
  uint param_2;
  int param_3;
  int *param_4;
  uint param_5;
  int param_6;
  byte *param_7;
  uint *param_8;
  uint param_9;
  int param_10;
  byte *param_11;
  uint *param_12;
{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  uint *puVar4;
  uint uVar5;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  
  puVar4 = (uint *)(param_1 + 0x754);
  local_54 = 0;
  uVar5 = 0;
  local_48 = 0;
  local_44 = (uint)param_3 | (param_2 & 0x3f) << 0x10;
  if ((param_2 == 0x12) || (param_2 == 0x13)) {
    local_44 = local_44 | 0x400000;
    local_48 = 0x55;
  }
  if ((((*param_4 == 0) || (param_4[1] == 0)) || (param_4[2] == 0)) || (param_4[3] == 0)) {
    local_44 = local_44 | 0x400000;
    local_48 = (uint)(*param_4 != 0) | (uint)(param_4[1] != 0) << 2 | (uint)(param_4[2] != 0) << 4 |
               (uint)(param_4[3] != 0) << 6;
  }
  local_4c = (uint)param_6 | (param_5 & 0x3f) << 0x10;
  if (((((*param_8 != 0) || (param_8[1] != 0)) ||
       ((param_8[2] != 0 || ((param_8[3] != 0 || (*(int *)param_7 != 0)))))) ||
      (*(int *)(param_7 + 4) != 1)) ||
     ((*(int *)(param_7 + 8) != 2 || (*(int *)(param_7 + 0xc) != 3)))) {
    local_4c = local_4c | 0x400000;
    uVar5 = *param_7 & 7 | (*param_8 & 1) * 8 | (param_7[4] & 7) << 4 | ((byte)param_8[1] & 1) << 7
            | (param_7[8] & 7) << 8 | ((byte)param_8[2] & 1) << 0xb | (param_7[0xc] & 7) << 0xc |
            ((byte)param_8[3] & 1) << 0xf;
  }
  local_50 = (uint)param_10 | (param_9 & 0x3f) << 0x10;
  if ((((*param_12 != 0) || (param_12[1] != 0)) || (param_12[2] != 0)) ||
     (((param_12[3] != 0 || (*(int *)param_11 != 0)) ||
      ((*(int *)(param_11 + 4) != 1 ||
       ((*(int *)(param_11 + 8) != 2 || (*(int *)(param_11 + 0xc) != 3)))))))) {
    local_50 = local_50 | 0x400000;
    local_54 = *param_11 & 7 | (*param_12 & 1) * 8 | (param_11[4] & 7) << 4 |
               ((byte)param_12[1] & 1) << 7 | (param_11[8] & 7) << 8 |
               ((byte)param_12[2] & 1) << 0xb | (param_11[0xc] & 7) << 0xc |
               ((byte)param_12[3] & 1) << 0xf;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = 0x20056;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_44;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  if ((local_44 & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_48;
    *puVar4 = *puVar4 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_4c;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  if ((local_4c & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = uVar5;
    *puVar4 = *puVar4 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_50;
  uVar5 = *puVar4;
  *puVar4 = uVar5 + 1;
  if ((local_50 & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar5 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_54;
    *puVar4 = *puVar4 + 1;
  }
  return;
}

/* FUN_00069284 @ 0x69284 (1104 bytes) */
int FUN_00069284(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  int param_3;
  int *param_4;
  uint param_5;
  int param_6;
  byte *param_7;
  uint *param_8;
{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  uint *puVar4;
  uint uVar5;
  uint local_44;
  uint local_40;
  uint local_3c;
  
  puVar4 = (uint *)(param_1 + 0x754);
  uVar5 = 0;
  local_40 = 0;
  local_3c = (uint)param_3 | (param_2 & 0x3f) << 0x10;
  if ((param_2 == 0x12) || (param_2 == 0x13)) {
    local_3c = local_3c | 0x400000;
    local_40 = 0x55;
  }
  if ((((*param_4 == 0) || (param_4[1] == 0)) || (param_4[2] == 0)) || (param_4[3] == 0)) {
    local_3c = local_3c | 0x400000;
    local_40 = (uint)(*param_4 != 0) | (uint)(param_4[1] != 0) << 2 | (uint)(param_4[2] != 0) << 4 |
               (uint)(param_4[3] != 0) << 6;
  }
  local_44 = (uint)param_6 | (param_5 & 0x3f) << 0x10;
  if (((((*param_8 != 0) || (param_8[1] != 0)) ||
       ((param_8[2] != 0 || ((param_8[3] != 0 || (*(int *)param_7 != 0)))))) ||
      (*(int *)(param_7 + 4) != 1)) ||
     ((*(int *)(param_7 + 8) != 2 || (*(int *)(param_7 + 0xc) != 3)))) {
    local_44 = local_44 | 0x400000;
    uVar5 = *param_7 & 7 | (*param_8 & 1) * 8 | (param_7[4] & 7) << 4 | ((byte)param_8[1] & 1) << 7
            | (param_7[8] & 7) << 8 | ((byte)param_8[2] & 1) << 0xb | (param_7[0xc] & 7) << 0xc |
            ((byte)param_8[3] & 1) << 0xf;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = 0x54;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_3c;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  if ((local_3c & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_40;
    *puVar4 = *puVar4 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_44;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  if ((local_44 & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = uVar5;
    *puVar4 = *puVar4 + 1;
  }
  return;
}

/* FUN_000696d4 @ 0x696d4 (1104 bytes) */
int FUN_000696d4(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  int param_3;
  int *param_4;
  uint param_5;
  int param_6;
  byte *param_7;
  uint *param_8;
{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  uint *puVar4;
  uint uVar5;
  uint local_44;
  uint local_40;
  uint local_3c;
  
  puVar4 = (uint *)(param_1 + 0x754);
  uVar5 = 0;
  local_40 = 0;
  local_3c = (uint)param_3 | (param_2 & 0x3f) << 0x10;
  if ((param_2 == 0x12) || (param_2 == 0x13)) {
    local_3c = local_3c | 0x400000;
    local_40 = 0x55;
  }
  if ((((*param_4 == 0) || (param_4[1] == 0)) || (param_4[2] == 0)) || (param_4[3] == 0)) {
    local_3c = local_3c | 0x400000;
    local_40 = (uint)(*param_4 != 0) | (uint)(param_4[1] != 0) << 2 | (uint)(param_4[2] != 0) << 4 |
               (uint)(param_4[3] != 0) << 6;
  }
  local_44 = (uint)param_6 | (param_5 & 0x3f) << 0x10;
  if (((((*param_8 != 0) || (param_8[1] != 0)) ||
       ((param_8[2] != 0 || ((param_8[3] != 0 || (*(int *)param_7 != 0)))))) ||
      (*(int *)(param_7 + 4) != 1)) ||
     ((*(int *)(param_7 + 8) != 2 || (*(int *)(param_7 + 0xc) != 3)))) {
    local_44 = local_44 | 0x400000;
    uVar5 = *param_7 & 7 | (*param_8 & 1) * 8 | (param_7[4] & 7) << 4 | ((byte)param_8[1] & 1) << 7
            | (param_7[8] & 7) << 8 | ((byte)param_8[2] & 1) << 0xb | (param_7[0xc] & 7) << 0xc |
            ((byte)param_8[3] & 1) << 0xf;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = 0x51;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_3c;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  if ((local_3c & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_40;
    *puVar4 = *puVar4 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_44;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  if ((local_44 & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = uVar5;
    *puVar4 = *puVar4 + 1;
  }
  return;
}

/* FUN_00069b24 @ 0x69b24 (1104 bytes) */
int FUN_00069b24(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  int param_3;
  int *param_4;
  uint param_5;
  int param_6;
  byte *param_7;
  uint *param_8;
{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  uint *puVar4;
  uint uVar5;
  uint local_44;
  uint local_40;
  uint local_3c;
  
  puVar4 = (uint *)(param_1 + 0x754);
  uVar5 = 0;
  local_40 = 0;
  local_3c = (uint)param_3 | (param_2 & 0x3f) << 0x10;
  if ((param_2 == 0x12) || (param_2 == 0x13)) {
    local_3c = local_3c | 0x400000;
    local_40 = 0x55;
  }
  if ((((*param_4 == 0) || (param_4[1] == 0)) || (param_4[2] == 0)) || (param_4[3] == 0)) {
    local_3c = local_3c | 0x400000;
    local_40 = (uint)(*param_4 != 0) | (uint)(param_4[1] != 0) << 2 | (uint)(param_4[2] != 0) << 4 |
               (uint)(param_4[3] != 0) << 6;
  }
  local_44 = (uint)param_6 | (param_5 & 0x3f) << 0x10;
  if (((((*param_8 != 0) || (param_8[1] != 0)) ||
       ((param_8[2] != 0 || ((param_8[3] != 0 || (*(int *)param_7 != 0)))))) ||
      (*(int *)(param_7 + 4) != 1)) ||
     ((*(int *)(param_7 + 8) != 2 || (*(int *)(param_7 + 0xc) != 3)))) {
    local_44 = local_44 | 0x400000;
    uVar5 = *param_7 & 7 | (*param_8 & 1) * 8 | (param_7[4] & 7) << 4 | ((byte)param_8[1] & 1) << 7
            | (param_7[8] & 7) << 8 | ((byte)param_8[2] & 1) << 0xb | (param_7[0xc] & 7) << 0xc |
            ((byte)param_8[3] & 1) << 0xf;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = 0x55;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_3c;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  if ((local_3c & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_40;
    *puVar4 = *puVar4 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_44;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  if ((local_44 & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = uVar5;
    *puVar4 = *puVar4 + 1;
  }
  return;
}

/* FUN_00069f74 @ 0x69f74 (1104 bytes) */
int FUN_00069f74(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  int param_3;
  int *param_4;
  uint param_5;
  int param_6;
  byte *param_7;
  uint *param_8;
{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  uint *puVar4;
  uint uVar5;
  uint local_44;
  uint local_40;
  uint local_3c;
  
  puVar4 = (uint *)(param_1 + 0x754);
  uVar5 = 0;
  local_40 = 0;
  local_3c = (uint)param_3 | (param_2 & 0x3f) << 0x10;
  if ((param_2 == 0x12) || (param_2 == 0x13)) {
    local_3c = local_3c | 0x400000;
    local_40 = 0x55;
  }
  if ((((*param_4 == 0) || (param_4[1] == 0)) || (param_4[2] == 0)) || (param_4[3] == 0)) {
    local_3c = local_3c | 0x400000;
    local_40 = (uint)(*param_4 != 0) | (uint)(param_4[1] != 0) << 2 | (uint)(param_4[2] != 0) << 4 |
               (uint)(param_4[3] != 0) << 6;
  }
  local_44 = (uint)param_6 | (param_5 & 0x3f) << 0x10;
  if (((((*param_8 != 0) || (param_8[1] != 0)) ||
       ((param_8[2] != 0 || ((param_8[3] != 0 || (*(int *)param_7 != 0)))))) ||
      (*(int *)(param_7 + 4) != 1)) ||
     ((*(int *)(param_7 + 8) != 2 || (*(int *)(param_7 + 0xc) != 3)))) {
    local_44 = local_44 | 0x400000;
    uVar5 = *param_7 & 7 | (*param_8 & 1) * 8 | (param_7[4] & 7) << 4 | ((byte)param_8[1] & 1) << 7
            | (param_7[8] & 7) << 8 | ((byte)param_8[2] & 1) << 0xb | (param_7[0xc] & 7) << 0xc |
            ((byte)param_8[3] & 1) << 0xf;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = 0x2d;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_3c;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  if ((local_3c & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_40;
    *puVar4 = *puVar4 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_44;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  if ((local_44 & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = uVar5;
    *puVar4 = *puVar4 + 1;
  }
  return;
}

/* FUN_0006a3c4 @ 0x6a3c4 (1104 bytes) */
int FUN_0006a3c4(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  int param_3;
  int *param_4;
  uint param_5;
  int param_6;
  byte *param_7;
  uint *param_8;
{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  uint *puVar4;
  uint uVar5;
  uint local_44;
  uint local_40;
  uint local_3c;
  
  puVar4 = (uint *)(param_1 + 0x754);
  uVar5 = 0;
  local_40 = 0;
  local_3c = (uint)param_3 | (param_2 & 0x3f) << 0x10;
  if ((param_2 == 0x12) || (param_2 == 0x13)) {
    local_3c = local_3c | 0x400000;
    local_40 = 0x55;
  }
  if ((((*param_4 == 0) || (param_4[1] == 0)) || (param_4[2] == 0)) || (param_4[3] == 0)) {
    local_3c = local_3c | 0x400000;
    local_40 = (uint)(*param_4 != 0) | (uint)(param_4[1] != 0) << 2 | (uint)(param_4[2] != 0) << 4 |
               (uint)(param_4[3] != 0) << 6;
  }
  local_44 = (uint)param_6 | (param_5 & 0x3f) << 0x10;
  if (((((*param_8 != 0) || (param_8[1] != 0)) ||
       ((param_8[2] != 0 || ((param_8[3] != 0 || (*(int *)param_7 != 0)))))) ||
      (*(int *)(param_7 + 4) != 1)) ||
     ((*(int *)(param_7 + 8) != 2 || (*(int *)(param_7 + 0xc) != 3)))) {
    local_44 = local_44 | 0x400000;
    uVar5 = *param_7 & 7 | (*param_8 & 1) * 8 | (param_7[4] & 7) << 4 | ((byte)param_8[1] & 1) << 7
            | (param_7[8] & 7) << 8 | ((byte)param_8[2] & 1) << 0xb | (param_7[0xc] & 7) << 0xc |
            ((byte)param_8[3] & 1) << 0xf;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = 0x2c;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_3c;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  if ((local_3c & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_40;
    *puVar4 = *puVar4 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_44;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  if ((local_44 & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = uVar5;
    *puVar4 = *puVar4 + 1;
  }
  return;
}

/* FUN_0006a814 @ 0x6a814 (1616 bytes) */
int FUN_0006a814(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  int param_1;
  uint param_2;
  int param_3;
  int *param_4;
  uint param_5;
  int param_6;
  byte *param_7;
  uint *param_8;
  uint param_9;
  int param_10;
  byte *param_11;
  uint *param_12;
{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  uint *puVar4;
  uint uVar5;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  
  puVar4 = (uint *)(param_1 + 0x754);
  local_54 = 0;
  uVar5 = 0;
  local_48 = 0;
  local_44 = (uint)param_3 | (param_2 & 0x3f) << 0x10;
  if ((param_2 == 0x12) || (param_2 == 0x13)) {
    local_44 = local_44 | 0x400000;
    local_48 = 0x55;
  }
  if ((((*param_4 == 0) || (param_4[1] == 0)) || (param_4[2] == 0)) || (param_4[3] == 0)) {
    local_44 = local_44 | 0x400000;
    local_48 = (uint)(*param_4 != 0) | (uint)(param_4[1] != 0) << 2 | (uint)(param_4[2] != 0) << 4 |
               (uint)(param_4[3] != 0) << 6;
  }
  local_4c = (uint)param_6 | (param_5 & 0x3f) << 0x10;
  if (((((*param_8 != 0) || (param_8[1] != 0)) ||
       ((param_8[2] != 0 || ((param_8[3] != 0 || (*(int *)param_7 != 0)))))) ||
      (*(int *)(param_7 + 4) != 1)) ||
     ((*(int *)(param_7 + 8) != 2 || (*(int *)(param_7 + 0xc) != 3)))) {
    local_4c = local_4c | 0x400000;
    uVar5 = *param_7 & 7 | (*param_8 & 1) * 8 | (param_7[4] & 7) << 4 | ((byte)param_8[1] & 1) << 7
            | (param_7[8] & 7) << 8 | ((byte)param_8[2] & 1) << 0xb | (param_7[0xc] & 7) << 0xc |
            ((byte)param_8[3] & 1) << 0xf;
  }
  local_50 = (uint)param_10 | (param_9 & 0x3f) << 0x10;
  if ((((*param_12 != 0) || (param_12[1] != 0)) || (param_12[2] != 0)) ||
     (((param_12[3] != 0 || (*(int *)param_11 != 0)) ||
      ((*(int *)(param_11 + 4) != 1 ||
       ((*(int *)(param_11 + 8) != 2 || (*(int *)(param_11 + 0xc) != 3)))))))) {
    local_50 = local_50 | 0x400000;
    local_54 = *param_11 & 7 | (*param_12 & 1) * 8 | (param_11[4] & 7) << 4 |
               ((byte)param_12[1] & 1) << 7 | (param_11[8] & 7) << 8 |
               ((byte)param_12[2] & 1) << 0xb | (param_11[0xc] & 7) << 0xc |
               ((byte)param_12[3] & 1) << 0xf;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = 0x4e;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_44;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  if ((local_44 & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_48;
    *puVar4 = *puVar4 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_4c;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  if ((local_4c & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = uVar5;
    *puVar4 = *puVar4 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_50;
  uVar5 = *puVar4;
  *puVar4 = uVar5 + 1;
  if ((local_50 & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar5 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_54;
    *puVar4 = *puVar4 + 1;
  }
  return;
}

/* FUN_0006ae64 @ 0x6ae64 (1619 bytes) */
int FUN_0006ae64(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  int param_1;
  uint param_2;
  int param_3;
  int *param_4;
  uint param_5;
  int param_6;
  byte *param_7;
  uint *param_8;
  uint param_9;
  int param_10;
  byte *param_11;
  uint *param_12;
{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  uint *puVar4;
  uint uVar5;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  
  puVar4 = (uint *)(param_1 + 0x754);
  local_54 = 0;
  uVar5 = 0;
  local_48 = 0x155;
  local_44 = CONCAT22(0x40,param_3) | (param_2 & 0x3f) << 0x10;
  if ((param_2 == 0x12) || (param_2 == 0x13)) {
    local_44 = local_44 | 0x400000;
    local_48 = 0x55;
  }
  if ((((*param_4 == 0) || (param_4[1] == 0)) || (param_4[2] == 0)) || (param_4[3] == 0)) {
    local_44 = local_44 | 0x400000;
    local_48 = local_48 & 0xffffff00 | (uint)(*param_4 != 0) | (uint)(param_4[1] != 0) << 2 |
               (uint)(param_4[2] != 0) << 4 | (uint)(param_4[3] != 0) << 6;
  }
  local_4c = (uint)param_6 | (param_5 & 0x3f) << 0x10;
  if (((((*param_8 != 0) || (param_8[1] != 0)) ||
       ((param_8[2] != 0 || ((param_8[3] != 0 || (*(int *)param_7 != 0)))))) ||
      (*(int *)(param_7 + 4) != 1)) ||
     ((*(int *)(param_7 + 8) != 2 || (*(int *)(param_7 + 0xc) != 3)))) {
    local_4c = local_4c | 0x400000;
    uVar5 = *param_7 & 7 | (*param_8 & 1) * 8 | (param_7[4] & 7) << 4 | ((byte)param_8[1] & 1) << 7
            | (param_7[8] & 7) << 8 | ((byte)param_8[2] & 1) << 0xb | (param_7[0xc] & 7) << 0xc |
            ((byte)param_8[3] & 1) << 0xf;
  }
  local_50 = (uint)param_10 | (param_9 & 0x3f) << 0x10;
  if ((((*param_12 != 0) || (param_12[1] != 0)) || (param_12[2] != 0)) ||
     (((param_12[3] != 0 || (*(int *)param_11 != 0)) ||
      ((*(int *)(param_11 + 4) != 1 ||
       ((*(int *)(param_11 + 8) != 2 || (*(int *)(param_11 + 0xc) != 3)))))))) {
    local_50 = local_50 | 0x400000;
    local_54 = *param_11 & 7 | (*param_12 & 1) * 8 | (param_11[4] & 7) << 4 |
               ((byte)param_12[1] & 1) << 7 | (param_11[8] & 7) << 8 |
               ((byte)param_12[2] & 1) << 0xb | (param_11[0xc] & 7) << 0xc |
               ((byte)param_12[3] & 1) << 0xf;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = 0x4e;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_44;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  if ((local_44 & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_48;
    *puVar4 = *puVar4 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_4c;
  uVar2 = *puVar4;
  *puVar4 = uVar2 + 1;
  if ((local_4c & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = uVar5;
    *puVar4 = *puVar4 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar4) {
    pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar3;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_50;
  uVar5 = *puVar4;
  *puVar4 = uVar5 + 1;
  if ((local_50 & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar5 + 1) {
      pvVar3 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar3,*(void **)(param_1 + 0x75c),*puVar4 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar3;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar4 * 4) = local_54;
    *puVar4 = *puVar4 + 1;
  }
  return;
}

/* FUN_0006b4b7 @ 0x6b4b7 (3893 bytes) */
int FUN_0006b4b7(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13, param_14, param_15, param_16)
  int param_1;
  uint param_2;
  int param_3;
  int *param_4;
  uint param_5;
  int param_6;
  byte *param_7;
  uint *param_8;
  uint param_9;
  int param_10;
  byte *param_11;
  uint *param_12;
  uint param_13;
  int param_14;
  byte *param_15;
  uint *param_16;
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  void *pvVar4;
  uint uVar5;
  uint *puVar6;
  uint local_bc;
  uint local_b8;
  uint local_b4;
  undefined1 local_34 [4];
  ushort local_30;
  
  puVar6 = (uint *)(param_1 + 0x754);
  (**(code **)(param_1 + 0x748))(param_1,0,local_34);
  local_bc = 0;
  uVar3 = (uint)local_30;
  local_b8 = (uint)param_10 | (param_9 & 0x3f) << 0x10;
  if ((((*param_12 != 0) || (param_12[1] != 0)) || (param_12[2] != 0)) ||
     (((param_12[3] != 0 || (*(int *)param_11 != 0)) ||
      ((*(int *)(param_11 + 4) != 1 ||
       ((*(int *)(param_11 + 8) != 2 || (*(int *)(param_11 + 0xc) != 3)))))))) {
    local_b8 = local_b8 | 0x400000;
    local_bc = *param_11 & 7 | (*param_12 & 1) * 8 | (param_11[4] & 7) << 4 |
               ((byte)param_12[1] & 1) << 7 | (param_11[8] & 7) << 8 |
               ((byte)param_12[2] & 1) << 0xb | (param_11[0xc] & 7) << 0xc |
               ((byte)param_12[3] & 1) << 0xf;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar6) {
    pvVar4 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar4,*(void **)(param_1 + 0x75c),*puVar6 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar4;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x75c) + *puVar6 * 4) = 0x47;
  uVar5 = *puVar6;
  *puVar6 = uVar5 + 1;
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar5 + 1) {
    pvVar4 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar4,*(void **)(param_1 + 0x75c),*puVar6 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar4;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar6 * 4) = uVar3 | 0x440000;
  uVar3 = *puVar6;
  *puVar6 = uVar3 + 1;
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar3 + 1) {
    pvVar4 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar4,*(void **)(param_1 + 0x75c),*puVar6 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar4;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x75c) + *puVar6 * 4) = 1;
  *puVar6 = *puVar6 + 1;
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar6) {
    pvVar4 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar4,*(void **)(param_1 + 0x75c),*puVar6 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar4;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar6 * 4) = local_b8;
  uVar3 = *puVar6;
  *puVar6 = uVar3 + 1;
  if ((local_b8 & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar3 + 1) {
      pvVar4 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar4,*(void **)(param_1 + 0x75c),*puVar6 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar4;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar6 * 4) = local_bc;
    *puVar6 = *puVar6 + 1;
  }
  local_bc = 0;
  uVar3 = CONCAT22(0x44,local_30) & 0xffc0ffff | 0x440000;
  local_b8 = (uint)param_6 | (param_5 & 0x3f) << 0x10;
  if ((((*param_8 != 0) || (param_8[1] != 0)) || (param_8[2] != 0)) ||
     (((param_8[3] != 0 || (*(int *)param_7 != 0)) ||
      ((*(int *)(param_7 + 4) != 1 ||
       ((*(int *)(param_7 + 8) != 2 || (*(int *)(param_7 + 0xc) != 3)))))))) {
    local_b8 = local_b8 | 0x400000;
    local_bc = *param_7 & 7 | (*param_8 & 1) * 8 | (param_7[4] & 7) << 4 |
               ((byte)param_8[1] & 1) << 7 | (param_7[8] & 7) << 8 | ((byte)param_8[2] & 1) << 0xb |
               (param_7[0xc] & 7) << 0xc | ((byte)param_8[3] & 1) << 0xf;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar6) {
    pvVar4 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar4,*(void **)(param_1 + 0x75c),*puVar6 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar4;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x75c) + *puVar6 * 4) = 0x47;
  uVar5 = *puVar6;
  *puVar6 = uVar5 + 1;
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar5 + 1) {
    pvVar4 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar4,*(void **)(param_1 + 0x75c),*puVar6 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar4;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar6 * 4) = uVar3;
  uVar5 = *puVar6;
  *puVar6 = uVar5 + 1;
  if ((uVar3 & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar5 + 1) {
      pvVar4 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar4,*(void **)(param_1 + 0x75c),*puVar6 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar4;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(undefined4 *)(*(int *)(param_1 + 0x75c) + *puVar6 * 4) = 4;
    *puVar6 = *puVar6 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar6) {
    pvVar4 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar4,*(void **)(param_1 + 0x75c),*puVar6 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar4;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar6 * 4) = local_b8;
  uVar5 = *puVar6;
  *puVar6 = uVar5 + 1;
  if ((local_b8 & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar5 + 1) {
      pvVar4 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar4,*(void **)(param_1 + 0x75c),*puVar6 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar4;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar6 * 4) = local_bc;
    *puVar6 = *puVar6 + 1;
  }
  local_bc = 0;
  uVar3 = CONCAT22((short)(uVar3 >> 0x10),local_30) & 0xffc0ffff | 0x440000;
  uVar5 = 0x40;
  local_b8 = (uint)param_14 | (param_13 & 0x3f) << 0x10;
  if (((((*param_16 != 0) || (param_16[1] != 0)) || (param_16[2] != 0)) ||
      ((param_16[3] != 0 || (*(int *)param_15 != 0)))) ||
     ((*(int *)(param_15 + 4) != 1 ||
      ((*(int *)(param_15 + 8) != 2 || (*(int *)(param_15 + 0xc) != 3)))))) {
    local_b8 = local_b8 | 0x400000;
    local_bc = *param_15 & 7 | (*param_16 & 1) * 8 | (param_15[4] & 7) << 4 |
               ((byte)param_16[1] & 1) << 7 | (param_15[8] & 7) << 8 |
               ((byte)param_16[2] & 1) << 0xb | (param_15[0xc] & 7) << 0xc |
               ((byte)param_16[3] & 1) << 0xf;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar6) {
    pvVar4 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar4,*(void **)(param_1 + 0x75c),*puVar6 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar4;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x75c) + *puVar6 * 4) = 0x47;
  uVar2 = *puVar6;
  *puVar6 = uVar2 + 1;
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
    pvVar4 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar4,*(void **)(param_1 + 0x75c),*puVar6 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar4;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar6 * 4) = uVar3;
  uVar2 = *puVar6;
  *puVar6 = uVar2 + 1;
  if ((uVar3 & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
      pvVar4 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar4,*(void **)(param_1 + 0x75c),*puVar6 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar4;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(undefined4 *)(*(int *)(param_1 + 0x75c) + *puVar6 * 4) = 0x40;
    *puVar6 = *puVar6 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar6) {
    pvVar4 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar4,*(void **)(param_1 + 0x75c),*puVar6 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar4;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar6 * 4) = local_b8;
  uVar2 = *puVar6;
  *puVar6 = uVar2 + 1;
  if ((local_b8 & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar2 + 1) {
      pvVar4 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar4,*(void **)(param_1 + 0x75c),*puVar6 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar4;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar6 * 4) = local_bc;
    *puVar6 = *puVar6 + 1;
  }
  local_b4 = CONCAT22((short)(uVar3 >> 0x10),param_3) & 0xffc0ffff | (param_2 & 0x3f) << 0x10;
  if ((param_2 == 0x12) || (param_2 == 0x13)) {
    local_b4 = local_b4 | 0x400000;
    uVar5 = 0x55;
  }
  if ((((*param_4 == 0) || (param_4[1] == 0)) || (param_4[2] == 0)) || (param_4[3] == 0)) {
    local_b4 = local_b4 | 0x400000;
    uVar5 = (uint)(*param_4 != 0) | (uint)(param_4[1] != 0) << 2 | (uint)(param_4[2] != 0) << 4 |
            (uint)(param_4[3] != 0) << 6;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar6) {
    pvVar4 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar4,*(void **)(param_1 + 0x75c),*puVar6 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar4;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x75c) + *puVar6 * 4) = 0x39;
  uVar3 = *puVar6;
  *puVar6 = uVar3 + 1;
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar3 + 1) {
    pvVar4 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar4,*(void **)(param_1 + 0x75c),*puVar6 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar4;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar6 * 4) = local_b4;
  uVar3 = *puVar6;
  *puVar6 = uVar3 + 1;
  if ((local_b4 & 0x400000) != 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar3 + 1) {
      pvVar4 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
        _memcpy(pvVar4,*(void **)(param_1 + 0x75c),*puVar6 << 2);
        (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(void **)(param_1 + 0x75c) = pvVar4;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(*(int *)(param_1 + 0x75c) + *puVar6 * 4) = uVar5;
    *puVar6 = *puVar6 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= *puVar6) {
    pvVar4 = (void *)(**(code **)(iVar1 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(void **)(param_1 + 0x75c) != (void *)0x0) {
      _memcpy(pvVar4,*(void **)(param_1 + 0x75c),*puVar6 << 2);
      (**(code **)(iVar1 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(void **)(param_1 + 0x75c) = pvVar4;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(*(int *)(param_1 + 0x75c) + *puVar6 * 4) = local_30 | 0x40000;
  *puVar6 = *puVar6 + 1;
  (**(code **)(param_1 + 0x74c))(param_1,local_34);
  return;
}

/* FUN_0006c3ec @ 0x6c3ec (130 bytes) */
int FUN_0006c3ec(param_1, param_2, param_3)
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

/* FUN_0006c46e @ 0x6c46e (1534 bytes) */
int FUN_0006c46e(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint local_1c;
  uint local_14;
  
  iVar3 = *(int *)(param_4 + 0x28);
  if (iVar3 == 0x87c3) {
    *(int *)(param_2 + 0x60) = *(int *)(param_2 + 0x60) + 1;
    *(int *)(param_3 + 0x118) = *(int *)(param_3 + 0x118) + 1;
    *(undefined1 *)(param_4 + 0x3d) = 1;
    iVar3 = *(int *)(param_4 + 0x24);
    if (iVar3 == 0x87bf) {
      *(int *)(param_3 + 0x4c) = *(int *)(param_3 + 0x4c) + 1;
      bVar1 = false;
      iVar3 = 0;
      for (uVar5 = 0; uVar5 < *(uint *)(param_3 + 0x48); uVar5 = uVar5 + 1) {
        while( true ) {
          if (bVar1) goto LAB_0006c790;
          if (*(char *)(iVar3 + 0x10 + *(int *)(param_3 + 0x44)) != '\0') break;
          bVar1 = true;
          if (*(uint *)(param_3 + 0x48) <= uVar5) goto LAB_0006c4e6;
        }
        iVar3 = iVar3 + 0x28;
      }
LAB_0006c4e6:
      if (bVar1) {
LAB_0006c790:
        *(uint *)(param_4 + 4) = uVar5;
        *(undefined1 *)(*(int *)(param_3 + 0x44) + 0x10 + uVar5 * 0x28) = 1;
        return 0;
      }
      *(undefined1 *)(param_2 + 0x10) = 0;
      iVar3 = *(int *)(param_3 + 0x48);
      uVar2 = (**(code **)(param_1 + 0x10))(iVar3 + 0x40,0x28);
      (**(code **)(param_1 + 0x1344))
                (uVar2,*(undefined4 *)(param_3 + 0x44),*(int *)(param_3 + 0x48) * 0x28);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x44));
LAB_0006c541:
      *(undefined4 *)(param_3 + 0x44) = uVar2;
      *(int *)(param_3 + 0x48) = *(int *)(param_3 + 0x48) + 0x40;
      *(int *)(param_4 + 4) = iVar3;
      *(undefined1 *)(*(int *)(param_3 + 0x44) + 0x10 + iVar3 * 0x28) = 1;
      return 0;
    }
    if (iVar3 == 0x87c0) {
      *(int *)(param_3 + 0x4c) = *(int *)(param_3 + 0x4c) + 4;
      uVar5 = *(int *)(param_3 + 0x48) - 3;
      bVar1 = false;
      iVar3 = 0;
      for (local_14 = 0; local_14 < uVar5; local_14 = local_14 + 1) {
        while( true ) {
          if (bVar1) goto LAB_0006c722;
          if (*(char *)(iVar3 + 0x10 + *(int *)(param_3 + 0x44)) != '\0') break;
          bVar1 = true;
          if (uVar5 <= local_14) goto LAB_0006c71a;
        }
        iVar3 = iVar3 + 0x28;
      }
LAB_0006c71a:
      if (bVar1) {
LAB_0006c722:
        iVar3 = local_14 * 0x28;
        iVar4 = iVar3 + *(int *)(param_3 + 0x44);
        if (((*(char *)(iVar4 + 0x38) == '\0') && (*(char *)(iVar4 + 0x60) == '\0')) &&
           (*(char *)(iVar4 + 0x88) == '\0')) {
          iVar4 = 0;
          do {
            *(uint *)(param_4 + 0x10) = local_14 + iVar4;
            *(undefined1 *)(*(int *)(param_3 + 0x44) + 0x10 + iVar3) = 1;
            iVar4 = iVar4 + 1;
            param_4 = param_4 + 4;
            iVar3 = iVar3 + 0x28;
          } while (iVar4 != 4);
          return 0;
        }
      }
      *(undefined1 *)(param_2 + 0x10) = 0;
      iVar4 = *(int *)(param_3 + 0x48);
      uVar2 = (**(code **)(param_1 + 0x10))(iVar4 + 0x40,0x28);
      (**(code **)(param_1 + 0x1344))
                (uVar2,*(undefined4 *)(param_3 + 0x44),*(int *)(param_3 + 0x48) * 0x28);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x44));
      *(undefined4 *)(param_3 + 0x44) = uVar2;
      *(int *)(param_3 + 0x48) = *(int *)(param_3 + 0x48) + 0x40;
      iVar3 = iVar4 * 0x28;
      iVar6 = 0;
      do {
        *(int *)(param_4 + 0x10) = iVar4 + iVar6;
        *(undefined1 *)(*(int *)(param_3 + 0x44) + 0x10 + iVar3) = 1;
        iVar6 = iVar6 + 1;
        param_4 = param_4 + 4;
        iVar3 = iVar3 + 0x28;
      } while (iVar6 != 4);
      return 0;
    }
    if (iVar3 == 0x87be) {
      *(int *)(param_3 + 0x4c) = *(int *)(param_3 + 0x4c) + 1;
      bVar1 = false;
      iVar3 = 0;
      for (uVar5 = 0; uVar5 < *(uint *)(param_3 + 0x48); uVar5 = uVar5 + 1) {
        while( true ) {
          if (bVar1) goto LAB_0006c5d4;
          if (*(char *)(iVar3 + 0x10 + *(int *)(param_3 + 0x44)) != '\0') break;
          bVar1 = true;
          if (*(uint *)(param_3 + 0x48) <= uVar5) goto LAB_0006c5cc;
        }
        iVar3 = iVar3 + 0x28;
      }
LAB_0006c5cc:
      if (bVar1) {
LAB_0006c5d4:
        *(uint *)(param_4 + 4) = uVar5;
        *(undefined4 *)(param_4 + 8) = 0;
        *(undefined1 *)(*(int *)(param_3 + 0x44) + 0x10 + uVar5 * 0x28) = 1;
        return 0;
      }
      *(undefined1 *)(param_2 + 0x10) = 0;
      iVar3 = *(int *)(param_3 + 0x48);
      uVar2 = (**(code **)(param_1 + 0x10))(iVar3 + 0x40,0x28);
      (**(code **)(param_1 + 0x1344))
                (uVar2,*(undefined4 *)(param_3 + 0x44),*(int *)(param_3 + 0x48) * 0x28);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x44));
LAB_0006c6c2:
      *(undefined4 *)(param_3 + 0x44) = uVar2;
      *(int *)(param_3 + 0x48) = *(int *)(param_3 + 0x48) + 0x40;
      *(int *)(param_4 + 4) = iVar3;
      *(undefined4 *)(param_4 + 8) = 0;
      *(undefined1 *)(*(int *)(param_3 + 0x44) + 0x10 + iVar3 * 0x28) = 1;
      return 0;
    }
  }
  else {
    if (iVar3 == 0x87c4) {
      return 0;
    }
    if (iVar3 == 0x87c2) {
      *(int *)(param_2 + 0x5c) = *(int *)(param_2 + 0x5c) + 1;
      if (*(char *)(param_4 + 0x44) == '\0') {
        *(int *)(param_3 + 0x118) = *(int *)(param_3 + 0x118) + 1;
      }
      else {
        *(int *)(param_3 + 0x120) = *(int *)(param_3 + 0x120) + 1;
      }
      *(undefined1 *)(param_4 + 0x3d) = 1;
      iVar3 = *(int *)(param_4 + 0x24);
      if (iVar3 == 0x87bf) {
        *(int *)(param_3 + 0x4c) = *(int *)(param_3 + 0x4c) + 1;
        bVar1 = false;
        iVar3 = 0;
        for (uVar5 = 0; uVar5 < *(uint *)(param_3 + 0x48); uVar5 = uVar5 + 1) {
          while( true ) {
            if (bVar1) goto LAB_0006c790;
            if (*(char *)(iVar3 + 0x10 + *(int *)(param_3 + 0x44)) != '\0') break;
            bVar1 = true;
            if (*(uint *)(param_3 + 0x48) <= uVar5) goto LAB_0006c88c;
          }
          iVar3 = iVar3 + 0x28;
        }
LAB_0006c88c:
        if (bVar1) goto LAB_0006c790;
        *(undefined1 *)(param_2 + 0x10) = 0;
        iVar3 = *(int *)(param_3 + 0x48);
        uVar2 = (**(code **)(param_1 + 0x10))(iVar3 + 0x40,0x28);
        (**(code **)(param_1 + 0x1344))
                  (uVar2,*(undefined4 *)(param_3 + 0x44),*(int *)(param_3 + 0x48) * 0x28);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x44));
        goto LAB_0006c541;
      }
      if (iVar3 == 0x87c0) {
        *(int *)(param_3 + 0x4c) = *(int *)(param_3 + 0x4c) + 4;
        uVar5 = *(int *)(param_3 + 0x48) - 3;
        bVar1 = false;
        iVar3 = 0;
        for (local_1c = 0; local_1c < uVar5; local_1c = local_1c + 1) {
          while( true ) {
            if (bVar1) goto LAB_0006c92d;
            if (*(char *)(iVar3 + 0x10 + *(int *)(param_3 + 0x44)) != '\0') break;
            bVar1 = true;
            if (uVar5 <= local_1c) goto LAB_0006c929;
          }
          iVar3 = iVar3 + 0x28;
        }
LAB_0006c929:
        if (bVar1) {
LAB_0006c92d:
          iVar3 = local_1c * 0x28;
          iVar4 = iVar3 + *(int *)(param_3 + 0x44);
          if (((*(char *)(iVar4 + 0x38) == '\0') && (*(char *)(iVar4 + 0x60) == '\0')) &&
             (*(char *)(iVar4 + 0x88) == '\0')) {
            iVar4 = 0;
            do {
              *(uint *)(param_4 + 0x10) = local_1c + iVar4;
              *(undefined1 *)(*(int *)(param_3 + 0x44) + 0x10 + iVar3) = 1;
              iVar4 = iVar4 + 1;
              param_4 = param_4 + 4;
              iVar3 = iVar3 + 0x28;
            } while (iVar4 != 4);
            return 0;
          }
        }
        *(undefined1 *)(param_2 + 0x10) = 0;
        iVar4 = *(int *)(param_3 + 0x48);
        uVar2 = (**(code **)(param_1 + 0x10))(iVar4 + 0x40,0x28);
        (**(code **)(param_1 + 0x1344))
                  (uVar2,*(undefined4 *)(param_3 + 0x44),*(int *)(param_3 + 0x48) * 0x28);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x44));
        *(undefined4 *)(param_3 + 0x44) = uVar2;
        *(int *)(param_3 + 0x48) = *(int *)(param_3 + 0x48) + 0x40;
        iVar3 = iVar4 * 0x28;
        iVar6 = 0;
        do {
          *(int *)(param_4 + 0x10) = iVar4 + iVar6;
          *(undefined1 *)(iVar3 + 0x10 + *(int *)(param_3 + 0x44)) = 1;
          iVar6 = iVar6 + 1;
          param_4 = param_4 + 4;
          iVar3 = iVar3 + 0x28;
        } while (iVar6 != 4);
        return 0;
      }
      if (iVar3 == 0x87be) {
        *(int *)(param_3 + 0x4c) = *(int *)(param_3 + 0x4c) + 1;
        bVar1 = false;
        iVar3 = 0;
        for (uVar5 = 0; uVar5 < *(uint *)(param_3 + 0x48); uVar5 = uVar5 + 1) {
          while( true ) {
            if (bVar1) goto LAB_0006c5d4;
            if (*(char *)(iVar3 + 0x10 + *(int *)(param_3 + 0x44)) != '\0') break;
            bVar1 = true;
            if (*(uint *)(param_3 + 0x48) <= uVar5) goto LAB_0006c667;
          }
          iVar3 = iVar3 + 0x28;
        }
LAB_0006c667:
        if (bVar1) goto LAB_0006c5d4;
        *(undefined1 *)(param_2 + 0x10) = 0;
        iVar3 = *(int *)(param_3 + 0x48);
        uVar2 = (**(code **)(param_1 + 0x10))(iVar3 + 0x40,0x28);
        (**(code **)(param_1 + 0x1344))
                  (uVar2,*(undefined4 *)(param_3 + 0x44),*(int *)(param_3 + 0x48) * 0x28);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x44));
        goto LAB_0006c6c2;
      }
    }
  }
  return 1;
}

/* FUN_0006ca6c @ 0x6ca6c (237 bytes) */
int FUN_0006ca6c(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int *param_3;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint local_10;
  
  if (*param_3 == 2) {
    iVar3 = param_3[1];
    iVar4 = iVar3 * 0x54;
    iVar1 = *(int *)(param_2 + 0x20);
    iVar2 = iVar4 + iVar1;
    if (*(char *)(iVar2 + 0x3d) == '\0') {
      if (*(int *)(iVar2 + 0x30) == 0) {
        if (*(uint *)(iVar2 + 0x34) < 2) {
          iVar2 = ((int (*)())FUN_0006c46e)(iVar2);
          if (iVar2 != 1) {
            return 0;
          }
          return 1;
        }
      }
      else {
        iVar3 = FUN_0005369a(param_2 + 0x1c,*(int *)(iVar2 + 0x30));
        iVar4 = iVar3 * 0x54;
        iVar1 = *(int *)(param_2 + 0x20);
      }
      if (*(int *)(iVar4 + 0x34 + iVar1) != 0) {
        iVar3 = iVar3 * 0x54;
        local_10 = 0;
        do {
          iVar2 = ((int (*)())FUN_0006c46e)(iVar1 + iVar3);
          if (iVar2 == 1) {
            return 1;
          }
          local_10 = local_10 + 1;
          iVar1 = *(int *)(param_2 + 0x20);
          iVar3 = iVar3 + 0x54;
        } while (local_10 < *(uint *)(iVar1 + 0x34 + iVar4));
      }
    }
  }
  return 0;
}

/* FUN_0006cb59 @ 0x6cb59 (1151 bytes) */
int FUN_0006cb59(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int *param_4;
{
  int *piVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  int local_44;
  int local_40;
  int local_20;
  
  if (*param_4 != 2) {
    return;
  }
  iVar2 = param_4[1];
  local_44 = *(int *)(param_2 + 0x20) + iVar2 * 0x54;
  if (*(int *)(local_44 + 0x28) != 0x87c4) {
    return;
  }
  if (*(char *)(local_44 + 0x3d) != '\0') {
    return;
  }
  *(undefined1 *)(local_44 + 0x3d) = 1;
  *(int *)(param_2 + 100) = *(int *)(param_2 + 100) + 1;
  iVar8 = *(int *)(iVar2 * 0x54 + 0x24 + *(int *)(param_2 + 0x20));
  if (iVar8 == 0x87bf) {
    bVar10 = false;
    for (uVar5 = 0; uVar5 < *(uint *)(param_3 + 0x40); uVar5 = uVar5 + 1) {
      while( true ) {
        if (bVar10) goto LAB_0006cc79;
        if (*(char *)(*(int *)(param_3 + 0x3c) + 0x10 + uVar5 * 0x28) != '\0') break;
        bVar10 = true;
        if (*(uint *)(param_3 + 0x40) <= uVar5) goto LAB_0006cc6f;
      }
    }
LAB_0006cc6f:
    if (!bVar10) {
      *(undefined1 *)(param_2 + 0x10) = 0;
      iVar8 = *(int *)(param_3 + 0x40);
      uVar6 = (**(code **)(param_1 + 0x10))(iVar8 + 0x40,0x28);
      (**(code **)(param_1 + 0x1344))
                (uVar6,*(undefined4 *)(param_3 + 0x3c),*(int *)(param_3 + 0x40) * 0x28);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x3c));
      *(undefined4 *)(param_3 + 0x3c) = uVar6;
      *(int *)(param_3 + 0x40) = *(int *)(param_3 + 0x40) + 0x40;
      *(int *)(local_44 + 4) = iVar8;
      iVar8 = iVar8 * 0x28;
      *(undefined1 *)(*(int *)(param_3 + 0x3c) + 0x10 + iVar8) = 1;
      *(undefined4 *)(iVar8 + 0x14 + *(int *)(param_3 + 0x3c)) = 4;
      *(int *)(iVar8 + 0x18 + *(int *)(param_3 + 0x3c)) = iVar2;
      *(int *)(iVar8 + 0x1c + *(int *)(param_3 + 0x3c)) = iVar2;
      *(int *)(iVar8 + 0x20 + *(int *)(param_3 + 0x3c)) = iVar2;
      *(int *)(iVar8 + 0x24 + *(int *)(param_3 + 0x3c)) = iVar2;
      return;
    }
LAB_0006cc79:
    *(uint *)(local_44 + 4) = uVar5;
    iVar8 = uVar5 * 0x28;
    *(undefined1 *)(*(int *)(param_3 + 0x3c) + 0x10 + iVar8) = 1;
    *(undefined4 *)(iVar8 + 0x14 + *(int *)(param_3 + 0x3c)) = 4;
    *(int *)(iVar8 + 0x18 + *(int *)(param_3 + 0x3c)) = iVar2;
    *(int *)(iVar8 + 0x1c + *(int *)(param_3 + 0x3c)) = iVar2;
    *(int *)(iVar8 + 0x20 + *(int *)(param_3 + 0x3c)) = iVar2;
    *(int *)(iVar8 + 0x24 + *(int *)(param_3 + 0x3c)) = iVar2;
    return;
  }
  if (iVar8 == 0x87c0) {
    uVar5 = *(int *)(param_3 + 0x40) - 3;
    bVar10 = false;
    for (uVar7 = 0; uVar7 < uVar5; uVar7 = uVar7 + 1) {
      while( true ) {
        if (bVar10) goto LAB_0006ccff;
        if (*(char *)(*(int *)(param_3 + 0x3c) + 0x10 + uVar7 * 0x28) != '\0') break;
        bVar10 = true;
        if (uVar5 <= uVar7) goto LAB_0006ccf5;
      }
    }
LAB_0006ccf5:
    if (bVar10) {
LAB_0006ccff:
      iVar8 = uVar7 * 0x28;
      iVar4 = iVar8 + *(int *)(param_3 + 0x3c);
      if (((*(char *)(iVar4 + 0x38) == '\0') && (*(char *)(iVar4 + 0x60) == '\0')) &&
         (*(char *)(iVar4 + 0x88) == '\0')) {
        local_20 = 0;
        local_40 = local_44;
        do {
          *(uint *)(local_40 + 0x10) = local_20 + uVar7;
          *(undefined1 *)(*(int *)(param_3 + 0x3c) + 0x10 + iVar8) = 1;
          *(undefined4 *)(*(int *)(param_3 + 0x3c) + 0x14 + iVar8) = 4;
          *(int *)(*(int *)(param_3 + 0x3c) + 0x18 + iVar8) = iVar2;
          *(int *)(*(int *)(param_3 + 0x3c) + 0x1c + iVar8) = iVar2;
          *(int *)(*(int *)(param_3 + 0x3c) + 0x20 + iVar8) = iVar2;
          *(int *)(*(int *)(param_3 + 0x3c) + 0x24 + iVar8) = iVar2;
          local_20 = local_20 + 1;
          local_40 = local_40 + 4;
          iVar8 = iVar8 + 0x28;
        } while (local_20 != 4);
        return;
      }
    }
    *(undefined1 *)(param_2 + 0x10) = 0;
    iVar4 = *(int *)(param_3 + 0x40);
    uVar6 = (**(code **)(param_1 + 0x10))(iVar4 + 0x40,0x28);
    (**(code **)(param_1 + 0x1344))
              (uVar6,*(undefined4 *)(param_3 + 0x3c),*(int *)(param_3 + 0x40) * 0x28);
    (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x3c));
    *(undefined4 *)(param_3 + 0x3c) = uVar6;
    *(int *)(param_3 + 0x40) = *(int *)(param_3 + 0x40) + 0x40;
    iVar8 = iVar4 * 0x28;
    iVar9 = 0;
    do {
      *(int *)(local_44 + 0x10) = iVar4 + iVar9;
      *(undefined1 *)(*(int *)(param_3 + 0x3c) + 0x10 + iVar8) = 1;
      *(undefined4 *)(*(int *)(param_3 + 0x3c) + 0x14 + iVar8) = 4;
      *(int *)(*(int *)(param_3 + 0x3c) + 0x18 + iVar8) = iVar2;
      *(int *)(*(int *)(param_3 + 0x3c) + 0x1c + iVar8) = iVar2;
      *(int *)(*(int *)(param_3 + 0x3c) + 0x20 + iVar8) = iVar2;
      *(int *)(*(int *)(param_3 + 0x3c) + 0x24 + iVar8) = iVar2;
      iVar9 = iVar9 + 1;
      local_44 = local_44 + 4;
      iVar8 = iVar8 + 0x28;
    } while (iVar9 != 4);
    return;
  }
  if (iVar8 != 0x87be) {
    return;
  }
  uVar5 = *(uint *)(param_3 + 0x40);
  uVar7 = 0;
  iVar8 = 0;
LAB_0006cbdb:
  bVar10 = false;
  bVar3 = false;
  do {
    if (uVar5 <= uVar7) {
      if (bVar3) {
LAB_0006cc07:
        *(uint *)(local_44 + 4) = uVar7;
        iVar8 = uVar7 * 0x28;
        *(undefined4 *)(local_44 + 8) = *(undefined4 *)(*(int *)(param_3 + 0x3c) + 0x14 + iVar8);
        iVar4 = iVar8 + *(int *)(param_3 + 0x3c);
        *(int *)(iVar4 + 0x18 + *(int *)(iVar4 + 0x14) * 4) = iVar2;
        piVar1 = (int *)(iVar8 + *(int *)(param_3 + 0x3c) + 0x14);
        *piVar1 = *piVar1 + 1;
        return;
      }
      if (uVar5 == 0) goto LAB_0006cf17;
      uVar7 = 0;
      break;
    }
    if (bVar10) goto LAB_0006cc07;
    iVar4 = iVar8 + *(int *)(param_3 + 0x3c);
    if ((*(char *)(iVar4 + 0x10) == '\0') || (3 < *(uint *)(iVar4 + 0x14))) goto LAB_0006cc38;
    bVar10 = true;
    bVar3 = true;
  } while( true );
LAB_0006cefe:
  bVar10 = *(char *)(*(int *)(param_3 + 0x3c) + 0x10 + uVar7 * 0x28) != '\0';
  if (bVar10) {
    uVar7 = uVar7 + 1;
  }
  if (uVar5 <= uVar7) {
    if (bVar10) {
LAB_0006cf17:
      *(undefined1 *)(param_2 + 0x10) = 0;
      iVar8 = *(int *)(param_3 + 0x40);
      uVar6 = (**(code **)(param_1 + 0x10))(iVar8 + 0x40,0x28);
      (**(code **)(param_1 + 0x1344))
                (uVar6,*(undefined4 *)(param_3 + 0x3c),*(int *)(param_3 + 0x40) * 0x28);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x3c));
      *(undefined4 *)(param_3 + 0x3c) = uVar6;
      *(int *)(param_3 + 0x40) = *(int *)(param_3 + 0x40) + 0x40;
      *(int *)(local_44 + 4) = iVar8;
      *(undefined4 *)(local_44 + 8) = 0;
      iVar8 = iVar8 * 0x28;
      *(undefined1 *)(*(int *)(param_3 + 0x3c) + 0x10 + iVar8) = 1;
      *(undefined4 *)(iVar8 + 0x14 + *(int *)(param_3 + 0x3c)) = 1;
      *(int *)(iVar8 + 0x18 + *(int *)(param_3 + 0x3c)) = iVar2;
      return;
    }
    goto LAB_0006cfa3;
  }
  if (!bVar10) {
LAB_0006cfa3:
    *(uint *)(local_44 + 4) = uVar7;
    *(undefined4 *)(local_44 + 8) = 0;
    iVar8 = uVar7 * 0x28;
    *(undefined1 *)(*(int *)(param_3 + 0x3c) + 0x10 + iVar8) = 1;
    *(undefined4 *)(iVar8 + 0x14 + *(int *)(param_3 + 0x3c)) = 1;
    *(int *)(iVar8 + 0x18 + *(int *)(param_3 + 0x3c)) = iVar2;
    return;
  }
  goto LAB_0006cefe;
LAB_0006cc38:
  uVar7 = uVar7 + 1;
  iVar8 = iVar8 + 0x28;
  goto LAB_0006cbdb;
}

/* FUN_0006cfd8 @ 0x6cfd8 (42 bytes) */
int FUN_0006cfd8(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  
  if ((*param_1 == 2) &&
     ((((iVar1 = param_1[1], iVar1 == *(int *)(param_2 + 0x18) ||
        (iVar1 == *(int *)(param_2 + 0x1c))) || (iVar1 == *(int *)(param_2 + 0x20))) ||
      (iVar1 == *(int *)(param_2 + 0x24))))) {
    return 1;
  }
  return 0;
}

/* FUN_0006d002 @ 0x6d002 (5 bytes) */
int FUN_0006d002()
{
  return;
}

/* FUN_0006d007 @ 0x6d007 (5 bytes) */
int FUN_0006d007()
{
  return;
}

/* FUN_0006d00c @ 0x6d00c (63 bytes) */
int FUN_0006d00c(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  iVar1 = *(int *)(param_1 + 0x60);
  do {
    uVar3 = uVar2;
    if (iVar1 == -1) {
      return uVar2;
    }
    do {
      uVar2 = uVar3 + 1;
      if (0x15 < uVar2) {
        return 0xffffffff;
      }
      uVar3 = uVar2;
    } while (((uVar2 == 1) || (uVar3 = 0x12, uVar2 == 0x12)) || (uVar3 = uVar2, uVar2 == 0x13));
    iVar1 = *(int *)(param_1 + 0x60 + uVar2 * 4);
  } while( true );
}

/* FUN_0006d04b @ 0x6d04b (139 bytes) */
int FUN_0006d04b(param_1)
  int param_1;
{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  int local_14;
  int local_10;
  
  if (*(int *)(param_1 + 0x40) == 0) {
    return -1;
  }
  iVar2 = *(int *)(param_1 + 0x3c);
  if (*(char *)(iVar2 + 0x10) == '\0') {
    iVar5 = 0;
    local_14 = 0;
    local_10 = iVar2;
  }
  else {
    pcVar4 = (char *)(iVar2 + 0x38);
    iVar5 = 0;
    iVar3 = 0x28;
    do {
      local_14 = iVar3;
      iVar5 = iVar5 + 1;
      if (iVar5 == *(int *)(param_1 + 0x40)) {
        return -1;
      }
      local_10 = iVar2 + local_14;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 0x28;
      iVar3 = local_14 + 0x28;
    } while (cVar1 != '\0');
  }
  *(undefined1 *)(local_10 + 0x10) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x3c) + 0x14 + local_14) = 4;
  return iVar5;
}

/* FUN_0006d0d6 @ 0x6d0d6 (2607 bytes) */
int FUN_0006d0d6(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  uint *puVar1;
  short sVar2;
  undefined2 uVar3;
  ushort uVar4;
  int iVar5;
  void *pvVar6;
  uint uVar7;
  uint uVar8;
  
  iVar5 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  puVar1 = (uint *)(param_2 + 4);
  if (param_4 != 0) {
    *(undefined1 *)(param_2 + 3) = 1;
    sVar2 = *(short *)(iVar5 + 0x2e04);
    if (sVar2 == 0x801) {
      if (*(uint *)(param_2 + 8) <= *(uint *)(param_2 + 4)) {
        pvVar6 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
        if (*(void **)(param_2 + 0xc) != (void *)0x0) {
          _memcpy(pvVar6,*(void **)(param_2 + 0xc),*(int *)(param_2 + 4) << 2);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
        }
        *(void **)(param_2 + 0xc) = pvVar6;
        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
      }
      *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = 0x49;
      uVar7 = *puVar1;
      *puVar1 = uVar7 + 1;
      uVar3 = *(undefined2 *)((int)&switchdataD_000013c0 + param_3);
      if (*(uint *)(param_2 + 8) <= uVar7 + 1) {
        pvVar6 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
        if (*(void **)(param_2 + 0xc) != (void *)0x0) {
          _memcpy(pvVar6,*(void **)(param_2 + 0xc),*puVar1 << 2);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
        }
        *(void **)(param_2 + 0xc) = pvVar6;
        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
      }
      *(uint *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = CONCAT22(4,uVar3);
      uVar7 = *puVar1;
      *puVar1 = uVar7 + 1;
      uVar8 = *(ushort *)((int)&switchdataD_000013c0 + param_3) | 0x40000;
      if (*(uint *)(param_2 + 8) <= uVar7 + 1) {
        pvVar6 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
        if (*(void **)(param_2 + 0xc) != (void *)0x0) {
          _memcpy(pvVar6,*(void **)(param_2 + 0xc),*puVar1 << 2);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
        }
        *(void **)(param_2 + 0xc) = pvVar6;
        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
      }
      *(uint *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = uVar8;
      uVar7 = *puVar1;
      *puVar1 = uVar7 + 1;
      if (*(uint *)(param_2 + 8) <= uVar7 + 1) {
        pvVar6 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
        if (*(void **)(param_2 + 0xc) != (void *)0x0) {
          _memcpy(pvVar6,*(void **)(param_2 + 0xc),*puVar1 << 2);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
        }
        *(void **)(param_2 + 0xc) = pvVar6;
        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
      }
      *(uint *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = uVar8;
      *puVar1 = *puVar1 + 1;
      uVar7 = *(uint *)(param_2 + 8);
      if (uVar7 <= *puVar1) goto LAB_0006d529;
    }
    else {
      if (sVar2 == 0x2601) {
        if (*(uint *)(param_2 + 8) <= *(uint *)(param_2 + 4)) {
          pvVar6 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar6,*(void **)(param_2 + 0xc),*(int *)(param_2 + 4) << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar6;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = 0x23;
        uVar7 = *puVar1;
        *puVar1 = uVar7 + 1;
        if (*(uint *)(param_2 + 8) <= uVar7 + 1) {
          pvVar6 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar6,*(void **)(param_2 + 0xc),*puVar1 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar6;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = 0x100000;
        uVar7 = *puVar1;
        *puVar1 = uVar7 + 1;
        uVar4 = *(ushort *)((int)&switchdataD_000013c0 + param_3);
        if (*(uint *)(param_2 + 8) <= uVar7 + 1) {
          pvVar6 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar6,*(void **)(param_2 + 0xc),*puVar1 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar6;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(uint *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = uVar4 | 0x440000;
        uVar7 = *puVar1;
        *puVar1 = uVar7 + 1;
        if (*(uint *)(param_2 + 8) <= uVar7 + 1) {
          pvVar6 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar6,*(void **)(param_2 + 0xc),*puVar1 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar6;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = 0x4054;
        uVar7 = *puVar1;
        *puVar1 = uVar7 + 1;
        uVar4 = *(ushort *)((int)&UINT_000013c4 + param_3);
        if (*(uint *)(param_2 + 8) <= uVar7 + 1) {
          pvVar6 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar6,*(void **)(param_2 + 0xc),*puVar1 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar6;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(uint *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = uVar4 | 0x410000;
        uVar7 = *puVar1;
        *puVar1 = uVar7 + 1;
        if (*(uint *)(param_2 + 8) <= uVar7 + 1) {
          pvVar6 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar6,*(void **)(param_2 + 0xc),*puVar1 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar6;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = 0x4214;
        *puVar1 = *puVar1 + 1;
        return;
      }
      if (sVar2 != 0x800) {
        return;
      }
      uVar7 = *(uint *)(param_2 + 8);
      if (uVar7 <= *puVar1) {
LAB_0006d529:
        pvVar6 = (void *)(**(code **)(param_1 + 0xc))(uVar7 * 4 + 0x200);
        if (*(void **)(param_2 + 0xc) != (void *)0x0) {
          _memcpy(pvVar6,*(void **)(param_2 + 0xc),*puVar1 << 2);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
        }
        *(void **)(param_2 + 0xc) = pvVar6;
        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
      }
    }
    *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = 0x49;
    uVar7 = *puVar1;
    *puVar1 = uVar7 + 1;
    uVar3 = *(undefined2 *)((int)&switchdataD_000013c0 + param_3);
    if (*(uint *)(param_2 + 8) <= uVar7 + 1) {
      pvVar6 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar6,*(void **)(param_2 + 0xc),*puVar1 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar6;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(uint *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = CONCAT22(4,uVar3);
    uVar7 = *puVar1;
    *puVar1 = uVar7 + 1;
    uVar4 = *(ushort *)((int)&switchdataD_000013c0 + param_3);
    if (*(uint *)(param_2 + 8) <= uVar7 + 1) {
      pvVar6 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar6,*(void **)(param_2 + 0xc),*puVar1 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar6;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(uint *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = uVar4 | 0x40000;
    uVar7 = *puVar1;
    *puVar1 = uVar7 + 1;
    uVar4 = *(ushort *)((int)&UINT_000013c4 + param_3);
    if (*(uint *)(param_2 + 8) <= uVar7 + 1) {
      pvVar6 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar6,*(void **)(param_2 + 0xc),*puVar1 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar6;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(uint *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = uVar4 | 0x410000;
    uVar7 = *puVar1;
    *puVar1 = uVar7 + 1;
    if (*(uint *)(param_2 + 8) <= uVar7 + 1) {
      pvVar6 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar6,*(void **)(param_2 + 0xc),*puVar1 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar6;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = 0x2222;
    uVar7 = *puVar1;
    *puVar1 = uVar7 + 1;
    if (*(uint *)(param_2 + 8) <= uVar7 + 1) {
      pvVar6 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar6,*(void **)(param_2 + 0xc),*puVar1 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar6;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = 0x2c;
    uVar7 = *puVar1;
    *puVar1 = uVar7 + 1;
    if (*(uint *)(param_2 + 8) <= uVar7 + 1) {
      pvVar6 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar6,*(void **)(param_2 + 0xc),*puVar1 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar6;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = 0x100000;
    uVar7 = *puVar1;
    *puVar1 = uVar7 + 1;
    uVar8 = *(ushort *)((int)&switchdataD_000013c0 + param_3) | 0x440000;
    if (*(uint *)(param_2 + 8) <= uVar7 + 1) {
      pvVar6 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar6,*(void **)(param_2 + 0xc),*puVar1 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar6;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    goto LAB_0006d164;
  }
  if (*(uint *)(param_2 + 4) < *(uint *)(param_2 + 8)) {
    *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = 0x47;
    uVar8 = *puVar1;
    *puVar1 = uVar8 + 1;
    uVar7 = *(uint *)(param_2 + 8);
    if (uVar7 <= uVar8 + 1) {
LAB_0006d430:
      pvVar6 = (void *)(**(code **)(param_1 + 0xc))(uVar7 * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar6,*(void **)(param_2 + 0xc),*puVar1 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar6;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
  }
  else {
    pvVar6 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
    if (*(void **)(param_2 + 0xc) != (void *)0x0) {
      _memcpy(pvVar6,*(void **)(param_2 + 0xc),*(int *)(param_2 + 4) << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
    }
    *(void **)(param_2 + 0xc) = pvVar6;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = 0x47;
    uVar8 = *puVar1;
    *puVar1 = uVar8 + 1;
    uVar7 = *(uint *)(param_2 + 8);
    if (uVar7 <= uVar8 + 1) goto LAB_0006d430;
  }
  *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = 0x100000;
  uVar7 = *puVar1;
  *puVar1 = uVar7 + 1;
  uVar8 = *(ushort *)((int)&switchdataD_000013c0 + param_3) | 0x440000;
  if (*(uint *)(param_2 + 8) <= uVar7 + 1) {
    pvVar6 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
    if (*(void **)(param_2 + 0xc) != (void *)0x0) {
      _memcpy(pvVar6,*(void **)(param_2 + 0xc),*puVar1 << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
    }
    *(void **)(param_2 + 0xc) = pvVar6;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
  }
LAB_0006d164:
  *(uint *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = uVar8;
  uVar7 = *puVar1;
  *puVar1 = uVar7 + 1;
  if (*(uint *)(param_2 + 8) <= uVar7 + 1) {
    pvVar6 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
    if (*(void **)(param_2 + 0xc) != (void *)0x0) {
      _memcpy(pvVar6,*(void **)(param_2 + 0xc),*puVar1 << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
    }
    *(void **)(param_2 + 0xc) = pvVar6;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
  }
  *(undefined4 *)(*(int *)(param_2 + 0xc) + *puVar1 * 4) = 0;
  *puVar1 = *puVar1 + 1;
  return;
}

/* FUN_0006db05 @ 0x6db05 (8130 bytes) */
int FUN_0006db05(param_1, param_2)
  int param_1;
  int *param_2;
{
  int *piVar1;
  undefined4 *puVar2;
  byte *pbVar3;
  int iVar4;
  char cVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  bool bVar15;
  bool bVar16;
  byte bVar17;
  byte bVar18;
  byte bVar19;
  byte bVar20;
  uint local_a0;
  int local_9c;
  uint local_84;
  uint local_78;
  uint local_44;
  uint local_40;
  byte local_38;
  byte local_37;
  byte local_36;
  byte local_35;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  uint local_24;
  uint local_20;
  
  iVar4 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  *(undefined4 *)(iVar4 + 0x137c) = 0;
  *(undefined1 *)((int)&UINT_000013d0 + iVar4) = 0;
  if ((param_2[6] == 0) || (param_2[5] == 0)) {
    param_2[0xc] = 0;
    param_2[0x15] = 0;
    param_2[0x16] = 0;
    param_2[0x17] = 0;
    param_2[0x18] = 0;
    param_2[0x19] = 0;
    return 1;
  }
  *(undefined1 *)(param_2 + 4) = 1;
  uVar6 = ((int (*)())FUN_0006d04b)(iVar4);
  *(undefined4 *)((int)&switchdataD_000013c0 + iVar4) = uVar6;
  uVar6 = ((int (*)())FUN_0006d04b)(iVar4);
  *(undefined4 *)((int)&UINT_000013cc + iVar4) = uVar6;
  iVar11 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  iVar10 = 0;
  iVar7 = iVar11;
  do {
    *(undefined4 *)(iVar7 + 0x60) = 0xffffffff;
    *(undefined4 *)(iVar7 + 0xb8) = 0xffffffff;
    iVar10 = iVar10 + 1;
    iVar7 = iVar7 + 4;
  } while (iVar10 != 0x16);
  *(undefined4 *)(iVar11 + 0x110) = 0;
  *(undefined4 *)(iVar11 + 0x1398) = 0;
  if (param_2[5] == 0) {
    local_28 = 1;
  }
  else {
    local_78 = 0;
    local_28 = 1;
    local_2c = 0;
    do {
      iVar9 = local_28;
      iVar8 = param_2[6];
      iVar10 = *(int *)(param_1 + 0x118c);
      iVar12 = *param_2;
      iVar7 = **(int **)(iVar12 + iVar10 * 4);
      if (((*(int *)(local_2c + iVar8 + 0x20) == 2) &&
          (puVar2 = (undefined4 *)(param_2[8] + *(int *)(local_2c + iVar8 + 0x24) * 0x54),
          puVar2[10] == 0x87c1)) && (*(char *)((int)puVar2 + 0x3d) == '\0')) {
        *puVar2 = 0;
        *(undefined1 *)((int)puVar2 + 0x3d) = 1;
        param_2[0x16] = param_2[0x16] + 1;
        if ((*(char *)(puVar2 + 0x11) == '\0') || (puVar2[0x12] == 0x12)) {
          iVar10 = puVar2[9];
          if (iVar10 == 0x87bf) {
            puVar2[1] = local_28;
            iVar10 = local_28 * 0x28;
            local_28 = local_28 + 1;
          }
          else if (iVar10 == 0x87c0) {
            puVar2[4] = local_28;
            puVar2[5] = local_28;
            puVar2[6] = local_28;
            puVar2[7] = local_28;
            iVar10 = local_28 * 0x28;
            local_28 = local_28 + 4;
          }
          else if (iVar10 == 0x87be) {
            puVar2[1] = local_28;
            iVar10 = local_28 * 0x28;
            local_28 = local_28 + 1;
          }
          else {
            iVar10 = 0;
          }
          *(undefined1 *)(*(int *)(iVar7 + 0x10) + 0x10 + iVar10) = 1;
          iVar10 = *(int *)(param_1 + 0x118c);
          iVar12 = *param_2;
          iVar8 = param_2[6];
        }
        else {
          switch(puVar2[0x12]) {
          case 0:
            iVar9 = local_28 + 1;
            *(undefined4 *)(iVar7 + 0xb8) = 0;
            *(undefined4 *)(iVar7 + 0x60) = 1;
            *(undefined1 *)(iVar7 + 0x18) = 1;
            local_28 = 0;
            iVar10 = 0;
            break;
          case 1:
            iVar9 = local_28 + 1;
            param_2[0xc] = param_2[0xc] | 8;
            *(int *)(iVar7 + 0x139c) = local_28;
            *(int *)(iVar7 + 0xbc) = local_28;
            *(undefined4 *)(iVar7 + 100) = 1;
            iVar10 = local_28 * 0x28;
            break;
          case 2:
            iVar9 = local_28 + 1;
            iVar10 = puVar2[0x13];
            param_2[0xc] = param_2[0xc] | 4;
            *(undefined1 *)(iVar10 + 0x34 + (int)param_2) = 1;
            *(int *)(iVar7 + 0x13a0 + iVar10 * 4) = local_28;
            *(int *)(iVar7 + 0xb8 + (iVar10 + 10) * 4) = local_28;
            *(undefined4 *)(iVar7 + 0x60 + (iVar10 + 10) * 4) = 1;
            iVar10 = local_28 * 0x28;
            break;
          case 3:
            iVar9 = local_28 + 1;
            param_2[0xc] = param_2[0xc] | 1;
            *(int *)(iVar7 + 5000) = local_28;
            *(int *)(iVar7 + 0xc0) = local_28;
            *(undefined4 *)(iVar7 + 0x68) = 1;
            iVar10 = local_28 * 0x28;
            break;
          case 4:
            iVar9 = local_28 + 1;
            *(int *)(iVar7 + 0xc4) = local_28;
            *(undefined4 *)(iVar7 + 0x6c) = 1;
            *(undefined1 *)(iVar7 + 0x23) = 1;
            iVar10 = local_28 * 0x28;
            break;
          case 5:
            iVar9 = local_28 + 1;
            *(int *)(iVar7 + 200) = local_28;
            *(undefined4 *)(iVar7 + 0x70) = 1;
            *(undefined1 *)(iVar7 + 0x24) = 1;
            iVar10 = local_28 * 0x28;
            break;
          case 6:
            iVar9 = local_28 + 1;
            *(int *)(iVar7 + 0xcc) = local_28;
            *(undefined4 *)(iVar7 + 0x74) = 1;
            *(undefined1 *)(iVar7 + 0x25) = 1;
            iVar10 = local_28 * 0x28;
            break;
          case 7:
            iVar9 = local_28 + 1;
            *(int *)(iVar7 + 0xd0) = local_28;
            *(undefined4 *)(iVar7 + 0x78) = 1;
            *(undefined1 *)(iVar7 + 0x22) = 1;
            iVar10 = local_28 * 0x28;
            break;
          case 8:
            iVar9 = local_28 + 1;
            *(int *)(iVar7 + 0xd4) = local_28;
            *(undefined4 *)(iVar7 + 0x7c) = 1;
            *(undefined1 *)(iVar7 + 0x27) = 1;
            iVar10 = local_28 * 0x28;
            break;
          case 9:
            iVar9 = local_28 + 1;
            *(int *)(iVar7 + 0xd8) = local_28;
            *(undefined4 *)(iVar7 + 0x80) = 1;
            *(undefined1 *)(iVar7 + 0x28) = 1;
            iVar10 = local_28 * 0x28;
            break;
          case 10:
            iVar9 = local_28 + 1;
            *(int *)(iVar7 + 0xdc) = local_28;
            *(undefined4 *)(iVar7 + 0x84) = 1;
            *(undefined1 *)(iVar7 + 0x29) = 1;
            iVar10 = local_28 * 0x28;
            break;
          case 0xb:
            iVar9 = local_28 + 1;
            *(int *)(iVar7 + 0xd0) = local_28;
            *(undefined4 *)(iVar7 + 0x78) = 1;
            *(undefined1 *)(iVar7 + 0x26) = 1;
            iVar10 = local_28 * 0x28;
            break;
          case 0xc:
            if (*(int *)(iVar7 + 0x1398) == 0) {
              *(int *)(iVar7 + 0x1398) = local_28;
              iVar9 = local_28 + 1;
            }
            local_28 = *(int *)(iVar7 + 0x1398);
            puVar2[2] = 2;
            *(int *)(iVar7 + 0x100) = local_28;
            *(undefined4 *)(iVar7 + 0xa8) = 1;
            iVar10 = local_28 * 0x28;
            break;
          case 0xd:
            if (*(int *)(iVar7 + 0x1398) == 0) {
              *(int *)(iVar7 + 0x1398) = local_28;
              local_28 = local_28 + 1;
            }
            iVar12 = *(int *)(iVar7 + 0x1398);
            puVar2[2] = 3;
            *(int *)(iVar7 + 0x100) = iVar12;
            *(undefined4 *)(iVar7 + 0xa8) = 1;
            iVar10 = iVar12 * 0x28;
            iVar9 = local_28;
            local_28 = iVar12;
            break;
          case 0xe:
            param_2[0xc] = param_2[0xc] | 2;
            *(int *)(iVar7 + 0x138c) = local_28;
            *(int *)(iVar7 + 0xc4) = local_28;
            *(undefined4 *)(iVar7 + 0x6c) = 1;
            iVar10 = local_28 * 0x28;
            iVar9 = local_28 + 1;
            break;
          case 0xf:
            param_2[0xc] = param_2[0xc] | 0x40;
            *(int *)(iVar7 + 0x1390) = local_28;
            *(int *)(iVar7 + 0x100) = local_28;
            *(undefined4 *)(iVar7 + 0xa8) = 1;
            puVar2[2] = 1;
            iVar10 = local_28 * 0x28;
            iVar9 = local_28 + 1;
            break;
          case 0x10:
            param_2[0xc] = param_2[0xc] | 0x80;
            *(int *)(iVar7 + 0x1394) = local_28;
            *(int *)(iVar7 + 0x104) = local_28;
            *(undefined4 *)(iVar7 + 0xac) = 1;
            iVar10 = local_28 * 0x28;
            iVar9 = local_28 + 1;
            break;
          default:
            local_28 = 0;
            iVar10 = 0;
          }
          puVar2[1] = local_28;
          *(undefined1 *)(*(int *)(iVar7 + 0x10) + 0x10 + iVar10) = 1;
          iVar10 = *(int *)(param_1 + 0x118c);
          iVar12 = *param_2;
          iVar8 = param_2[6];
          local_28 = iVar9;
        }
      }
      iVar9 = local_28;
      iVar7 = **(int **)(iVar12 + iVar10 * 4);
      if (((*(int *)(local_2c + iVar8 + 0x3c) == 2) &&
          (puVar2 = (undefined4 *)(param_2[8] + *(int *)(local_2c + iVar8 + 0x40) * 0x54),
          puVar2[10] == 0x87c1)) && (*(char *)((int)puVar2 + 0x3d) == '\0')) {
        *puVar2 = 0;
        *(undefined1 *)((int)puVar2 + 0x3d) = 1;
        param_2[0x16] = param_2[0x16] + 1;
        if ((*(char *)(puVar2 + 0x11) == '\0') || (puVar2[0x12] == 0x12)) {
          iVar10 = puVar2[9];
          if (iVar10 == 0x87bf) {
            puVar2[1] = local_28;
            iVar10 = local_28 * 0x28;
            local_28 = local_28 + 1;
          }
          else if (iVar10 == 0x87c0) {
            puVar2[4] = local_28;
            puVar2[5] = local_28;
            puVar2[6] = local_28;
            puVar2[7] = local_28;
            iVar10 = local_28 * 0x28;
            local_28 = local_28 + 4;
          }
          else if (iVar10 == 0x87be) {
            puVar2[1] = local_28;
            iVar10 = local_28 * 0x28;
            local_28 = local_28 + 1;
          }
          else {
            iVar10 = 0;
          }
          *(undefined1 *)(*(int *)(iVar7 + 0x10) + 0x10 + iVar10) = 1;
          iVar10 = *(int *)(param_1 + 0x118c);
          iVar12 = *param_2;
          iVar8 = param_2[6];
        }
        else {
          switch(puVar2[0x12]) {
          case 0:
            iVar9 = local_28 + 1;
            *(undefined4 *)(iVar7 + 0xb8) = 0;
            *(undefined4 *)(iVar7 + 0x60) = 1;
            *(undefined1 *)(iVar7 + 0x18) = 1;
            local_28 = 0;
            iVar10 = 0;
            break;
          case 1:
            iVar9 = local_28 + 1;
            param_2[0xc] = param_2[0xc] | 8;
            *(int *)(iVar7 + 0x139c) = local_28;
            *(int *)(iVar7 + 0xbc) = local_28;
            *(undefined4 *)(iVar7 + 100) = 1;
            iVar10 = local_28 * 0x28;
            break;
          case 2:
            iVar9 = local_28 + 1;
            iVar10 = puVar2[0x13];
            param_2[0xc] = param_2[0xc] | 4;
            *(undefined1 *)(iVar10 + 0x34 + (int)param_2) = 1;
            *(int *)(iVar7 + 0x13a0 + iVar10 * 4) = local_28;
            *(int *)(iVar7 + 0xb8 + (iVar10 + 10) * 4) = local_28;
            *(undefined4 *)(iVar7 + 0x60 + (iVar10 + 10) * 4) = 1;
            iVar10 = local_28 * 0x28;
            break;
          case 3:
            iVar9 = local_28 + 1;
            param_2[0xc] = param_2[0xc] | 1;
            *(int *)(iVar7 + 5000) = local_28;
            *(int *)(iVar7 + 0xc0) = local_28;
            *(undefined4 *)(iVar7 + 0x68) = 1;
            iVar10 = local_28 * 0x28;
            break;
          case 4:
            iVar9 = local_28 + 1;
            *(int *)(iVar7 + 0xc4) = local_28;
            *(undefined4 *)(iVar7 + 0x6c) = 1;
            *(undefined1 *)(iVar7 + 0x23) = 1;
            iVar10 = local_28 * 0x28;
            break;
          case 5:
            iVar9 = local_28 + 1;
            *(int *)(iVar7 + 200) = local_28;
            *(undefined4 *)(iVar7 + 0x70) = 1;
            *(undefined1 *)(iVar7 + 0x24) = 1;
            iVar10 = local_28 * 0x28;
            break;
          case 6:
            iVar9 = local_28 + 1;
            *(int *)(iVar7 + 0xcc) = local_28;
            *(undefined4 *)(iVar7 + 0x74) = 1;
            *(undefined1 *)(iVar7 + 0x25) = 1;
            iVar10 = local_28 * 0x28;
            break;
          case 7:
            iVar9 = local_28 + 1;
            *(int *)(iVar7 + 0xd0) = local_28;
            *(undefined4 *)(iVar7 + 0x78) = 1;
            *(undefined1 *)(iVar7 + 0x22) = 1;
            iVar10 = local_28 * 0x28;
            break;
          case 8:
            iVar9 = local_28 + 1;
            *(int *)(iVar7 + 0xd4) = local_28;
            *(undefined4 *)(iVar7 + 0x7c) = 1;
            *(undefined1 *)(iVar7 + 0x27) = 1;
            iVar10 = local_28 * 0x28;
            break;
          case 9:
            iVar9 = local_28 + 1;
            *(int *)(iVar7 + 0xd8) = local_28;
            *(undefined4 *)(iVar7 + 0x80) = 1;
            *(undefined1 *)(iVar7 + 0x28) = 1;
            iVar10 = local_28 * 0x28;
            break;
          case 10:
            iVar9 = local_28 + 1;
            *(int *)(iVar7 + 0xdc) = local_28;
            *(undefined4 *)(iVar7 + 0x84) = 1;
            *(undefined1 *)(iVar7 + 0x29) = 1;
            iVar10 = local_28 * 0x28;
            break;
          case 0xb:
            iVar9 = local_28 + 1;
            *(int *)(iVar7 + 0xd0) = local_28;
            *(undefined4 *)(iVar7 + 0x78) = 1;
            *(undefined1 *)(iVar7 + 0x26) = 1;
            iVar10 = local_28 * 0x28;
            break;
          case 0xc:
            if (*(int *)(iVar7 + 0x1398) == 0) {
              *(int *)(iVar7 + 0x1398) = local_28;
              local_28 = local_28 + 1;
            }
            iVar12 = *(int *)(iVar7 + 0x1398);
            puVar2[2] = 2;
            *(int *)(iVar7 + 0x100) = iVar12;
            *(undefined4 *)(iVar7 + 0xa8) = 1;
            iVar10 = iVar12 * 0x28;
            iVar9 = local_28;
            local_28 = iVar12;
            break;
          case 0xd:
            if (*(int *)(iVar7 + 0x1398) == 0) {
              *(int *)(iVar7 + 0x1398) = local_28;
              local_28 = local_28 + 1;
            }
            iVar12 = *(int *)(iVar7 + 0x1398);
            puVar2[2] = 3;
            *(int *)(iVar7 + 0x100) = iVar12;
            *(undefined4 *)(iVar7 + 0xa8) = 1;
            iVar10 = iVar12 * 0x28;
            iVar9 = local_28;
            local_28 = iVar12;
            break;
          case 0xe:
            param_2[0xc] = param_2[0xc] | 2;
            *(int *)(iVar7 + 0x138c) = local_28;
            *(int *)(iVar7 + 0xc4) = local_28;
            *(undefined4 *)(iVar7 + 0x6c) = 1;
            iVar10 = local_28 * 0x28;
            iVar9 = local_28 + 1;
            break;
          case 0xf:
            param_2[0xc] = param_2[0xc] | 0x40;
            *(int *)(iVar7 + 0x1390) = local_28;
            *(int *)(iVar7 + 0x100) = local_28;
            *(undefined4 *)(iVar7 + 0xa8) = 1;
            puVar2[2] = 1;
            iVar10 = local_28 * 0x28;
            iVar9 = local_28 + 1;
            break;
          case 0x10:
            param_2[0xc] = param_2[0xc] | 0x80;
            *(int *)(iVar7 + 0x1394) = local_28;
            *(int *)(iVar7 + 0x104) = local_28;
            *(undefined4 *)(iVar7 + 0xac) = 1;
            iVar10 = local_28 * 0x28;
            iVar9 = local_28 + 1;
            break;
          default:
            local_28 = 0;
            iVar10 = 0;
          }
          puVar2[1] = local_28;
          *(undefined1 *)(*(int *)(iVar7 + 0x10) + 0x10 + iVar10) = 1;
          iVar10 = *(int *)(param_1 + 0x118c);
          iVar12 = *param_2;
          iVar8 = param_2[6];
          local_28 = iVar9;
        }
      }
      iVar9 = local_28;
      iVar7 = **(int **)(iVar12 + iVar10 * 4);
      if (((*(int *)(local_2c + iVar8 + 0x58) == 2) &&
          (puVar2 = (undefined4 *)(param_2[8] + *(int *)(local_2c + iVar8 + 0x5c) * 0x54),
          puVar2[10] == 0x87c1)) && (*(char *)((int)puVar2 + 0x3d) == '\0')) {
        *puVar2 = 0;
        *(undefined1 *)((int)puVar2 + 0x3d) = 1;
        param_2[0x16] = param_2[0x16] + 1;
        if ((*(char *)(puVar2 + 0x11) == '\0') || (puVar2[0x12] == 0x12)) {
          iVar10 = puVar2[9];
          if (iVar10 == 0x87bf) {
            puVar2[1] = local_28;
            iVar10 = local_28 * 0x28;
            local_28 = local_28 + 1;
          }
          else if (iVar10 == 0x87c0) {
            puVar2[4] = local_28;
            puVar2[5] = local_28;
            puVar2[6] = local_28;
            puVar2[7] = local_28;
            iVar10 = local_28 * 0x28;
            local_28 = local_28 + 4;
          }
          else if (iVar10 == 0x87be) {
            puVar2[1] = local_28;
            iVar10 = local_28 * 0x28;
            local_28 = local_28 + 1;
          }
          else {
            iVar10 = 0;
          }
          *(undefined1 *)(*(int *)(iVar7 + 0x10) + 0x10 + iVar10) = 1;
        }
        else {
          switch(puVar2[0x12]) {
          case 0:
            iVar9 = local_28 + 1;
            *(undefined4 *)(iVar7 + 0xb8) = 0;
            *(undefined4 *)(iVar7 + 0x60) = 1;
            *(undefined1 *)(iVar7 + 0x18) = 1;
            local_28 = 0;
            iVar10 = 0;
            break;
          case 1:
            iVar9 = local_28 + 1;
            param_2[0xc] = param_2[0xc] | 8;
            *(int *)(iVar7 + 0x139c) = local_28;
            *(int *)(iVar7 + 0xbc) = local_28;
            *(undefined4 *)(iVar7 + 100) = 1;
            iVar10 = local_28 * 0x28;
            break;
          case 2:
            iVar9 = local_28 + 1;
            iVar10 = puVar2[0x13];
            param_2[0xc] = param_2[0xc] | 4;
            *(undefined1 *)(iVar10 + 0x34 + (int)param_2) = 1;
            *(int *)(iVar7 + 0x13a0 + iVar10 * 4) = local_28;
            *(int *)(iVar7 + 0xb8 + (iVar10 + 10) * 4) = local_28;
            *(undefined4 *)(iVar7 + 0x60 + (iVar10 + 10) * 4) = 1;
            iVar10 = local_28 * 0x28;
            break;
          case 3:
            iVar9 = local_28 + 1;
            param_2[0xc] = param_2[0xc] | 1;
            *(int *)(iVar7 + 5000) = local_28;
            *(int *)(iVar7 + 0xc0) = local_28;
            *(undefined4 *)(iVar7 + 0x68) = 1;
            iVar10 = local_28 * 0x28;
            break;
          case 4:
            iVar9 = local_28 + 1;
            *(int *)(iVar7 + 0xc4) = local_28;
            *(undefined4 *)(iVar7 + 0x6c) = 1;
            *(undefined1 *)(iVar7 + 0x23) = 1;
            iVar10 = local_28 * 0x28;
            break;
          case 5:
            iVar9 = local_28 + 1;
            *(int *)(iVar7 + 200) = local_28;
            *(undefined4 *)(iVar7 + 0x70) = 1;
            *(undefined1 *)(iVar7 + 0x24) = 1;
            iVar10 = local_28 * 0x28;
            break;
          case 6:
            iVar9 = local_28 + 1;
            *(int *)(iVar7 + 0xcc) = local_28;
            *(undefined4 *)(iVar7 + 0x74) = 1;
            *(undefined1 *)(iVar7 + 0x25) = 1;
            iVar10 = local_28 * 0x28;
            break;
          case 7:
            iVar9 = local_28 + 1;
            *(int *)(iVar7 + 0xd0) = local_28;
            *(undefined4 *)(iVar7 + 0x78) = 1;
            *(undefined1 *)(iVar7 + 0x22) = 1;
            iVar10 = local_28 * 0x28;
            break;
          case 8:
            iVar9 = local_28 + 1;
            *(int *)(iVar7 + 0xd4) = local_28;
            *(undefined4 *)(iVar7 + 0x7c) = 1;
            *(undefined1 *)(iVar7 + 0x27) = 1;
            iVar10 = local_28 * 0x28;
            break;
          case 9:
            iVar9 = local_28 + 1;
            *(int *)(iVar7 + 0xd8) = local_28;
            *(undefined4 *)(iVar7 + 0x80) = 1;
            *(undefined1 *)(iVar7 + 0x28) = 1;
            iVar10 = local_28 * 0x28;
            break;
          case 10:
            iVar9 = local_28 + 1;
            *(int *)(iVar7 + 0xdc) = local_28;
            *(undefined4 *)(iVar7 + 0x84) = 1;
            *(undefined1 *)(iVar7 + 0x29) = 1;
            iVar10 = local_28 * 0x28;
            break;
          case 0xb:
            iVar9 = local_28 + 1;
            *(int *)(iVar7 + 0xd0) = local_28;
            *(undefined4 *)(iVar7 + 0x78) = 1;
            *(undefined1 *)(iVar7 + 0x26) = 1;
            iVar10 = local_28 * 0x28;
            break;
          case 0xc:
            if (*(int *)(iVar7 + 0x1398) == 0) {
              *(int *)(iVar7 + 0x1398) = local_28;
              iVar9 = local_28 + 1;
            }
            local_28 = *(int *)(iVar7 + 0x1398);
            puVar2[2] = 2;
            *(int *)(iVar7 + 0x100) = local_28;
            *(undefined4 *)(iVar7 + 0xa8) = 1;
            iVar10 = local_28 * 0x28;
            break;
          case 0xd:
            if (*(int *)(iVar7 + 0x1398) == 0) {
              *(int *)(iVar7 + 0x1398) = local_28;
              local_28 = local_28 + 1;
            }
            iVar12 = *(int *)(iVar7 + 0x1398);
            puVar2[2] = 3;
            *(int *)(iVar7 + 0x100) = iVar12;
            *(undefined4 *)(iVar7 + 0xa8) = 1;
            iVar10 = iVar12 * 0x28;
            iVar9 = local_28;
            local_28 = iVar12;
            break;
          case 0xe:
            param_2[0xc] = param_2[0xc] | 2;
            *(int *)(iVar7 + 0x138c) = local_28;
            *(int *)(iVar7 + 0xc4) = local_28;
            *(undefined4 *)(iVar7 + 0x6c) = 1;
            iVar10 = local_28 * 0x28;
            iVar9 = local_28 + 1;
            break;
          case 0xf:
            param_2[0xc] = param_2[0xc] | 0x40;
            *(int *)(iVar7 + 0x1390) = local_28;
            *(int *)(iVar7 + 0x100) = local_28;
            *(undefined4 *)(iVar7 + 0xa8) = 1;
            puVar2[2] = 1;
            iVar10 = local_28 * 0x28;
            iVar9 = local_28 + 1;
            break;
          case 0x10:
            param_2[0xc] = param_2[0xc] | 0x80;
            *(int *)(iVar7 + 0x1394) = local_28;
            *(int *)(iVar7 + 0x104) = local_28;
            *(undefined4 *)(iVar7 + 0xac) = 1;
            iVar10 = local_28 * 0x28;
            iVar9 = local_28 + 1;
            break;
          default:
            local_28 = 0;
            iVar10 = 0;
          }
          puVar2[1] = local_28;
          *(undefined1 *)(*(int *)(iVar7 + 0x10) + 0x10 + iVar10) = 1;
          local_28 = iVar9;
        }
      }
      local_78 = local_78 + 1;
      local_2c = local_2c + 0x74;
    } while (local_78 < (uint)param_2[5]);
  }
  *(int *)(iVar11 + 0x130) = local_28;
  if (param_2[5] != 0) {
    local_24 = 0;
    local_30 = 0;
    do {
      iVar8 = param_2[6];
      iVar10 = *(int *)(param_1 + 0x118c);
      iVar12 = *param_2;
      iVar7 = **(int **)(iVar12 + iVar10 * 4);
      if ((((*(int *)(local_30 + iVar8 + 0x20) == 2) &&
           (piVar1 = (int *)(param_2[8] + *(int *)(local_30 + iVar8 + 0x24) * 0x54),
           piVar1[10] == 0x87c1)) && (((char)piVar1[0x11] == '\0' || (piVar1[0x12] == 0x12)))) &&
         ((piVar1 != (int *)0x0 && (*piVar1 == 0)))) {
        *(undefined1 *)((int)piVar1 + 0x3d) = 1;
        if (piVar1[9] == 0x87bf) {
          iVar10 = ((int (*)())FUN_0006d00c)();
          *(int *)(iVar7 + 0xb8 + iVar10 * 4) = piVar1[1];
          *(undefined4 *)(iVar7 + 0x60 + iVar10 * 4) = 1;
          iVar7 = (**(code **)(param_1 + 0x12a8))(param_1,iVar10,4);
          *piVar1 = iVar7;
          iVar10 = *(int *)(param_1 + 0x118c);
          iVar12 = *param_2;
          iVar8 = param_2[6];
        }
        else {
          iVar10 = *(int *)(param_1 + 0x118c);
          iVar12 = *param_2;
          iVar8 = param_2[6];
        }
      }
      iVar7 = **(int **)(iVar12 + iVar10 * 4);
      if ((((*(int *)(local_30 + iVar8 + 0x3c) == 2) &&
           (piVar1 = (int *)(param_2[8] + *(int *)(local_30 + iVar8 + 0x40) * 0x54),
           piVar1[10] == 0x87c1)) && (((char)piVar1[0x11] == '\0' || (piVar1[0x12] == 0x12)))) &&
         ((piVar1 != (int *)0x0 && (*piVar1 == 0)))) {
        *(undefined1 *)((int)piVar1 + 0x3d) = 1;
        if (piVar1[9] == 0x87bf) {
          iVar10 = ((int (*)())FUN_0006d00c)();
          *(int *)(iVar7 + 0xb8 + iVar10 * 4) = piVar1[1];
          *(undefined4 *)(iVar7 + 0x60 + iVar10 * 4) = 1;
          iVar7 = (**(code **)(param_1 + 0x12a8))(param_1,iVar10,4);
          *piVar1 = iVar7;
          iVar10 = *(int *)(param_1 + 0x118c);
          iVar12 = *param_2;
          iVar8 = param_2[6];
        }
        else {
          iVar10 = *(int *)(param_1 + 0x118c);
          iVar12 = *param_2;
          iVar8 = param_2[6];
        }
      }
      iVar7 = **(int **)(iVar12 + iVar10 * 4);
      if ((((*(int *)(local_30 + iVar8 + 0x58) == 2) &&
           (piVar1 = (int *)(param_2[8] + *(int *)(local_30 + iVar8 + 0x5c) * 0x54),
           piVar1[10] == 0x87c1)) && (((char)piVar1[0x11] == '\0' || (piVar1[0x12] == 0x12)))) &&
         (((piVar1 != (int *)0x0 && (*piVar1 == 0)) &&
          (*(undefined1 *)((int)piVar1 + 0x3d) = 1, piVar1[9] == 0x87bf)))) {
        iVar10 = ((int (*)())FUN_0006d00c)();
        *(int *)(iVar7 + 0xb8 + iVar10 * 4) = piVar1[1];
        *(undefined4 *)(iVar7 + 0x60 + iVar10 * 4) = 1;
        iVar7 = (**(code **)(param_1 + 0x12a8))(param_1,iVar10,4);
        *piVar1 = iVar7;
      }
      local_24 = local_24 + 1;
      local_30 = local_30 + 0x74;
    } while (local_24 < (uint)param_2[5]);
  }
  iVar7 = iVar11;
  do {
    if (*(int *)(iVar7 + 0x60) != -1) {
      *(int *)(iVar11 + 0x110) = *(int *)(iVar11 + 0x110) + 1;
    }
    iVar7 = iVar7 + 4;
  } while (iVar11 + 0x58 != iVar7);
  *(undefined4 *)(iVar4 + 0x120) = 0;
  *(undefined4 *)(iVar4 + 0x118) = 0;
  if (param_2[5] != 0) {
    uVar14 = 0;
    iVar11 = 0;
    do {
      iVar7 = ((int (*)())FUN_0006ca6c)(iVar11 + param_2[6] + 0x20);
      if (iVar7 == 1) {
        param_2[0xc] = 0;
        param_2[0x15] = 0;
        param_2[0x16] = 0;
        param_2[0x17] = 0;
        param_2[0x18] = 0;
        param_2[0x19] = 0;
        return 0;
      }
      iVar7 = ((int (*)())FUN_0006ca6c)(iVar11 + param_2[6] + 0x3c);
      if (iVar7 == 1) goto LAB_0006e6d8;
      iVar7 = ((int (*)())FUN_0006ca6c)(iVar11 + param_2[6] + 0x58);
      if (iVar7 == 1) {
        param_2[0xc] = 0;
        param_2[0x15] = 0;
        param_2[0x16] = 0;
        param_2[0x17] = 0;
        param_2[0x18] = 0;
        param_2[0x19] = 0;
        return 0;
      }
      uVar14 = uVar14 + 1;
      iVar11 = iVar11 + 0x74;
    } while (uVar14 < (uint)param_2[5]);
  }
  *(undefined4 *)(iVar4 + 4) = 0;
  ((int (*)())FUN_0006c3ec)();
  ((int (*)())FUN_0006c3ec)();
  uVar14 = 0;
  if (*(int *)(iVar4 + 0x130) != 0) {
    uVar13 = 0;
    do {
      ((int (*)())FUN_0006c3ec)();
      ((int (*)())FUN_0006c3ec)();
      uVar13 = uVar13 + 1;
      uVar14 = *(uint *)(iVar4 + 0x130);
    } while (uVar13 < uVar14);
  }
  *(uint *)(iVar4 + 0x1178) = uVar14;
  if (param_2[7] != 0) {
    local_20 = 0;
    iVar11 = 0;
    do {
      iVar7 = iVar11 + param_2[8];
      if ((iVar7 != 0) && (*(int *)(iVar7 + 0x28) == 0x87c3)) {
        iVar7 = *(int *)(iVar7 + 0x24);
        if (iVar7 == 0x87bf) {
          ((int (*)())FUN_0006c3ec)();
          ((int (*)())FUN_0006c3ec)();
          ((int (*)())FUN_0006c3ec)();
          ((int (*)())FUN_0006c3ec)();
          ((int (*)())FUN_0006c3ec)();
          ((int (*)())FUN_0006c3ec)();
        }
        else if (iVar7 == 0x87c0) {
          ((int (*)())FUN_0006c3ec)();
          ((int (*)())FUN_0006c3ec)();
          ((int (*)())FUN_0006c3ec)();
          ((int (*)())FUN_0006c3ec)();
          ((int (*)())FUN_0006c3ec)();
          ((int (*)())FUN_0006c3ec)();
          ((int (*)())FUN_0006c3ec)();
          ((int (*)())FUN_0006c3ec)();
          ((int (*)())FUN_0006c3ec)();
          ((int (*)())FUN_0006c3ec)();
          ((int (*)())FUN_0006c3ec)();
          ((int (*)())FUN_0006c3ec)();
          ((int (*)())FUN_0006c3ec)();
          ((int (*)())FUN_0006c3ec)();
          ((int (*)())FUN_0006c3ec)();
          ((int (*)())FUN_0006c3ec)();
          ((int (*)())FUN_0006c3ec)();
          ((int (*)())FUN_0006c3ec)();
          ((int (*)())FUN_0006c3ec)();
          ((int (*)())FUN_0006c3ec)();
          ((int (*)())FUN_0006c3ec)();
          ((int (*)())FUN_0006c3ec)();
          ((int (*)())FUN_0006c3ec)();
          ((int (*)())FUN_0006c3ec)();
        }
        else if (iVar7 == 0x87be) {
          ((int (*)())FUN_0006c3ec)();
          ((int (*)())FUN_0006c3ec)();
          ((int (*)())FUN_0006c3ec)();
          ((int (*)())FUN_0006c3ec)();
          ((int (*)())FUN_0006c3ec)();
          ((int (*)())FUN_0006c3ec)();
        }
      }
      local_20 = local_20 + 1;
      iVar11 = iVar11 + 0x54;
    } while (local_20 < (uint)param_2[7]);
  }
  if (param_2[5] == 0) {
    local_84 = 0;
  }
  else {
    local_a0 = 0;
    local_84 = 0;
    local_9c = 0;
    do {
      if (0x20 < *(int *)(local_9c + param_2[6]) - 0x8782U) {
LAB_0006e6d8:
        param_2[0xc] = 0;
        param_2[0x15] = 0;
        param_2[0x16] = 0;
        param_2[0x17] = 0;
        param_2[0x18] = 0;
        param_2[0x19] = 0;
        return 0;
      }
      ((int (*)())FUN_0006cb59)((int *)(local_9c + param_2[6]) + 1);
      ((int (*)())FUN_0006cb59)(local_9c + param_2[6] + 0x20);
      ((int (*)())FUN_0006cb59)(local_9c + param_2[6] + 0x3c);
      ((int (*)())FUN_0006cb59)(local_9c + param_2[6] + 0x58);
      uVar14 = param_2[0x19];
      if ((uint)param_2[0x19] <= local_84) {
        uVar14 = local_84;
      }
      iVar11 = (**(code **)(&UNK_001cc938 + *(int *)(local_9c + param_2[6]) * 4))
                         (param_1,iVar4 + 0x13c,param_2,(int *)(local_9c + param_2[6]));
      if (iVar11 < 0) {
        param_2[0xc] = 0;
        param_2[0x15] = 0;
        param_2[0x16] = 0;
        param_2[0x17] = 0;
        param_2[0x18] = 0;
        param_2[0x19] = 0;
        *(undefined1 *)(param_2 + 4) = 0;
        return 0;
      }
      *(int *)(iVar4 + 4) = *(int *)(iVar4 + 4) + iVar11;
      if ((*(char *)((int)param_2 + 0x7b) == '\0') &&
         (iVar11 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4),
         *(int *)(iVar11 + 0x40) != 0)) {
        local_44 = 0;
        local_34 = 0;
        do {
          iVar7 = local_34 + *(int *)(iVar11 + 0x3c);
          if (*(char *)(iVar7 + 0x10) != '\0') {
            iVar10 = *(int *)(iVar7 + 0x18);
            if (((((iVar10 == 0) && (*(int *)(iVar7 + 0x1c) == 0)) && (*(int *)(iVar7 + 0x20) == 0))
                && (*(int *)(iVar7 + 0x24) == 0)) || (uVar13 = param_2[5], uVar13 <= local_a0 + 1))
            {
              bVar16 = true;
            }
            else {
              iVar12 = local_9c + 0x74 + param_2[6];
              bVar16 = true;
              local_38 = 0;
              local_37 = 0;
              local_36 = 0;
              local_35 = 0;
              local_40 = local_a0 + 1;
              do {
                cVar5 = ((int (*)())FUN_0006cfd8)();
                if (((cVar5 == '\0') && (cVar5 = ((int (*)())FUN_0006cfd8)(), cVar5 == '\0')) &&
                   (cVar5 = ((int (*)())FUN_0006cfd8)(), cVar5 == '\0')) {
                  cVar5 = ((int (*)())FUN_0006cfd8)();
                  if (cVar5 != '\0') {
                    iVar8 = *(int *)(iVar12 + 8);
                    if (*(int *)(param_2[8] + 0x24 + iVar8 * 0x54) == 0x87be) {
                      bVar17 = iVar10 == iVar8;
                      bVar18 = iVar8 == *(int *)(iVar7 + 0x1c);
                      bVar19 = iVar8 == *(int *)(iVar7 + 0x20);
                      bVar20 = iVar8 == *(int *)(iVar7 + 0x24);
                    }
                    else {
                      bVar17 = *(byte *)(iVar12 + 0xc);
                      bVar18 = *(byte *)(iVar12 + 0x10);
                      bVar19 = *(byte *)(iVar12 + 0x14);
                      bVar20 = *(byte *)(iVar12 + 0x18);
                    }
                    local_35 = local_35 | bVar20;
                    local_36 = local_36 | bVar19;
                    local_37 = local_37 | bVar18;
                    local_38 = local_38 | bVar17;
                    if (((local_38 != 0) && (local_37 != 0)) && (local_36 != 0)) {
                      bVar15 = local_35 != 0;
                      goto LAB_0006e4ae;
                    }
                  }
                  bVar15 = false;
                }
                else {
                  bVar16 = false;
                  bVar15 = true;
                }
LAB_0006e4ae:
                local_40 = local_40 + 1;
              } while ((uVar13 != local_40) && (iVar12 = iVar12 + 0x74, !bVar15));
            }
            if (local_44 == *(uint *)((int)&switchdataD_000013c0 + iVar11)) {
              bVar16 = false;
            }
            if ((local_44 != *(uint *)((int)&UINT_000013cc + iVar11)) && (bVar16)) {
              *(undefined1 *)(param_2[8] + 0x3d + iVar10 * 0x54) = 0;
              *(undefined1 *)
               (param_2[8] + 0x3d + *(int *)(*(int *)(iVar11 + 0x3c) + 0x1c + local_34) * 0x54) = 0;
              *(undefined1 *)
               (param_2[8] + 0x3d + *(int *)(*(int *)(iVar11 + 0x3c) + 0x20 + local_34) * 0x54) = 0;
              *(undefined1 *)
               (param_2[8] + 0x3d + *(int *)(*(int *)(iVar11 + 0x3c) + 0x24 + local_34) * 0x54) = 0;
              *(undefined1 *)(*(int *)(iVar11 + 0x3c) + 0x10 + local_34) = 0;
              *(undefined4 *)(*(int *)(iVar11 + 0x3c) + 0x14 + local_34) = 0;
              *(undefined4 *)(*(int *)(iVar11 + 0x3c) + 0x18 + local_34) = 0;
              *(undefined4 *)(*(int *)(iVar11 + 0x3c) + 0x1c + local_34) = 0;
              *(undefined4 *)(*(int *)(iVar11 + 0x3c) + 0x20 + local_34) = 0;
              *(undefined4 *)(*(int *)(iVar11 + 0x3c) + 0x24 + local_34) = 0;
              param_2[0x19] = param_2[0x19] + -1;
            }
          }
          local_44 = local_44 + 1;
          local_34 = local_34 + 0x28;
        } while (local_44 < *(uint *)(iVar11 + 0x40));
      }
      local_9c = local_9c + 0x74;
      local_a0 = local_a0 + 1;
      local_84 = uVar14;
    } while (local_a0 < (uint)param_2[5]);
  }
  if (*(char *)((int)param_2 + 0x7a) != '\0') {
    bVar16 = (*(byte *)(param_1 + 0x46) & 0x14) == 0x14;
    if (bVar16) {
      *(undefined1 *)((int)&UINT_000013c8 + iVar4 + 1) = *(undefined1 *)(param_1 + 0x11d1);
      pbVar3 = (byte *)(*(byte *)(param_1 + 0x11d1) + 0x71 + (int)param_2);
      *pbVar3 = *pbVar3 | 1;
      *(undefined1 *)((int)&UINT_000013c8 + iVar4) = 0;
    }
    else {
      *(undefined1 *)((int)&UINT_000013c8 + iVar4) = 1;
    }
    if ((*(byte *)(param_1 + 0x46) & 4) == 0) {
      uVar6 = 1;
    }
    else {
      if (!bVar16) goto LAB_0006e5fd;
      uVar6 = 0;
    }
    iVar11 = *(int *)(iVar4 + 0x4c);
    *(int *)((int)&UINT_000013c4 + iVar4) = iVar11;
    *(int *)(iVar4 + 0x4c) = iVar11 + 1;
    ((int (*)())FUN_0006d0d6)(uVar6);
  }
LAB_0006e5fd:
  ((int (*)())FUN_0006c3ec)();
  param_2[0x15] = *(int *)(iVar4 + 4);
  param_2[0x19] = local_84;
  if (*(int *)(iVar4 + 0x118) != 0) {
    uVar6 = (**(code **)(param_1 + 0xc))(*(int *)(iVar4 + 0x118) << 2);
    *(undefined4 *)(iVar4 + 0x114) = uVar6;
    if (param_2[7] != 0) {
      uVar14 = 0;
      iVar7 = 0;
      iVar11 = 0;
      do {
        iVar10 = iVar11 + param_2[8];
        if (*(char *)(iVar10 + 0x3d) != '\0') {
          if (*(int *)(iVar10 + 0x28) == 0x87c2) {
            if (*(char *)(iVar10 + 0x44) == '\0') {
LAB_0006f77b:
              *(uint *)(*(int *)(iVar4 + 0x114) + iVar7 * 4) = uVar14;
              iVar7 = iVar7 + 1;
            }
          }
          else if (*(int *)(iVar10 + 0x28) == 0x87c3) goto LAB_0006f77b;
        }
        uVar14 = uVar14 + 1;
        iVar11 = iVar11 + 0x54;
      } while (uVar14 < (uint)param_2[7]);
    }
  }
  if (*(int *)(iVar4 + 0x4c) != 0) {
    uVar6 = (**(code **)(param_1 + 0xc))(*(int *)(iVar4 + 0x4c) * 0x10 + 0x10);
    *(undefined4 *)(iVar4 + 0x124) = uVar6;
    *(undefined4 *)(iVar4 + 0x1174) = *(undefined4 *)(iVar4 + 0x4c);
  }
  *(undefined1 *)(iVar4 + 0x36) = *(undefined1 *)((int)param_2 + 0x79);
  iVar11 = (**(code **)(param_1 + 0x128c))(param_1,iVar4 + 0x13c);
  if (iVar11 != 0) {
    *(undefined1 *)(param_2 + 4) = 0;
  }
  (**(code **)(param_1 + 0x12b8))(param_1,param_2);
  *(undefined1 *)(param_1 + 0x29) = 1;
  FUN_000728b0(param_1,param_2);
  *(undefined1 *)(param_2[1] + *(int *)(param_1 + 0x118c)) = 0;
  if (*(int *)(iVar4 + 0x13d8) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(iVar4 + 0x13d8));
    *(undefined4 *)(iVar4 + 0x13d8) = 0;
  }
  return (char)param_2[4];
}

/* FUN_0006fb97 @ 0x6fb97 (2728 bytes) */
int FUN_0006fb97(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  uint *param_2;
  int param_3;
  int *param_4;
  int param_5;
  uint *param_6;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  void *pvVar8;
  uint uVar9;
  uint uVar10;
  uint local_38;
  
  uVar9 = 0x3210;
  switch(param_4[2]) {
  case 0x87d9:
    uVar9 = 0x3218;
  case 0x87d5:
    break;
  case 0x87da:
    uVar9 = 0x3218;
  case 0x87d6:
    uVar9 = uVar9 | 1;
    break;
  case 0x87db:
    uVar9 = 0x3218;
  case 0x87d7:
    uVar9 = uVar9 | 2;
    break;
  case 0x87dc:
    uVar9 = 0x3218;
  case 0x87d8:
    uVar9 = uVar9 | 3;
    break;
  case 0x87dd:
    uVar9 = 0x3214;
    break;
  case 0x87de:
    uVar9 = 0x3215;
  }
  switch(param_4[3]) {
  case 0x87d9:
    uVar9 = uVar9 | 0x80;
  case 0x87d5:
    uVar9 = uVar9 & 0xffffff8f;
    break;
  case 0x87da:
    uVar9 = uVar9 | 0x80;
  case 0x87d6:
    uVar9 = uVar9 & 0xffffff8f | 0x10;
    break;
  case 0x87db:
    uVar9 = uVar9 | 0x80;
  case 0x87d7:
    uVar9 = uVar9 & 0xffffff8f | 0x20;
    break;
  case 0x87dc:
    uVar9 = uVar9 | 0x80;
  case 0x87d8:
    uVar9 = uVar9 & 0xffffff8f | 0x30;
    break;
  case 0x87dd:
    uVar9 = uVar9 & 0xffffff8f | 0x40;
    break;
  case 0x87de:
    uVar9 = uVar9 & 0xffffff8f | 0x50;
  }
  switch(param_4[4]) {
  case 0x87d9:
    uVar9 = uVar9 | 0x800;
  case 0x87d5:
    uVar9 = uVar9 & 0xfffff8ff;
    break;
  case 0x87da:
    uVar9 = uVar9 | 0x800;
  case 0x87d6:
    uVar9 = uVar9 & 0xfffff8ff | 0x100;
    break;
  case 0x87db:
    uVar9 = uVar9 | 0x800;
  case 0x87d7:
    uVar9 = uVar9 & 0xfffff8ff | 0x200;
    break;
  case 0x87dc:
    uVar9 = uVar9 | 0x800;
  case 0x87d8:
    uVar9 = uVar9 & 0xfffff8ff | 0x300;
    break;
  case 0x87dd:
    uVar9 = uVar9 & 0xfffff8ff | 0x400;
    break;
  case 0x87de:
    uVar9 = uVar9 & 0xfffff8ff | 0x500;
  }
  switch(param_4[5]) {
  case 0x87d9:
    uVar9 = uVar9 | 0x8000;
  case 0x87d5:
    uVar9 = uVar9 & 0xffff8fff;
    break;
  case 0x87da:
    uVar9 = uVar9 | 0x8000;
  case 0x87d6:
    uVar9 = uVar9 & 0xffff8fff | 0x1000;
    break;
  case 0x87db:
    uVar9 = uVar9 | 0x8000;
  case 0x87d7:
    uVar9 = uVar9 & 0xffff8fff | 0x2000;
    break;
  case 0x87dc:
    uVar9 = uVar9 | 0x8000;
  case 0x87d8:
    uVar9 = uVar9 & 0xffff8fff | 0x3000;
    break;
  case 0x87dd:
    uVar9 = uVar9 & 0xffff8fff | 0x4000;
    break;
  case 0x87de:
    uVar9 = uVar9 & 0xffff8fff | 0x5000;
  }
  if (param_6 != (uint *)0x0) {
    uVar10 = *param_6;
    uVar3 = uVar10 & 3;
    if (uVar3 == 2) {
      uVar9 = uVar9 & 0xfffffff8 | uVar9 >> 8 & 7;
    }
    else if (uVar3 == 3) {
      uVar9 = uVar9 & 0xfffffff8 | uVar9 >> 0xc & 7;
    }
    else if (uVar3 == 1) {
      uVar9 = uVar9 & 0xfffffff8 | uVar9 >> 4 & 7;
    }
    uVar3 = param_6[1];
    uVar4 = uVar3 & 3;
    if (uVar4 == 1) {
LAB_0006fd47:
      uVar4 = param_6[2];
      uVar5 = uVar4 & 3;
      if (uVar5 != 1) goto LAB_0006fd58;
LAB_0006ffaa:
      uVar9 = uVar9 & 0xfffff8ff | (uVar9 & 0x70) << 4;
LAB_0006fd70:
      uVar5 = param_6[3];
      uVar6 = uVar5 & 3;
      if (uVar6 != 1) goto LAB_0006fd81;
LAB_0006ff75:
      uVar9 = uVar9 & 0xffff8fff | (uVar9 & 0x70) << 8;
    }
    else {
      if (uVar4 != 0) {
        if (uVar4 == 2) {
          uVar9 = uVar9 & 0xffffff8f | uVar9 >> 4 & 0x70;
        }
        else if (uVar4 == 3) {
          uVar9 = uVar9 & 0xffffff8f | uVar9 >> 8 & 0x70;
        }
        goto LAB_0006fd47;
      }
      uVar9 = uVar9 & 0xffffff8f | (uVar9 & 7) << 4;
      uVar4 = param_6[2];
      uVar5 = uVar4 & 3;
      if (uVar5 == 1) goto LAB_0006ffaa;
LAB_0006fd58:
      if (uVar5 != 0) {
        if ((uVar5 != 2) && (uVar5 == 3)) {
          uVar9 = uVar9 & 0xfffff8ff | uVar9 >> 4 & 0x700;
        }
        goto LAB_0006fd70;
      }
      uVar9 = uVar9 & 0xfffff8ff | (uVar9 & 7) << 8;
      uVar5 = param_6[3];
      uVar6 = uVar5 & 3;
      if (uVar6 == 1) goto LAB_0006ff75;
LAB_0006fd81:
      if (uVar6 == 0) {
        uVar9 = uVar9 & 0xffff8fff | (uVar9 & 7) << 0xc;
      }
      else if (uVar6 == 2) {
        uVar9 = uVar9 & 0xffff8fff | (uVar9 & 0x700) << 4;
      }
    }
    if ((uVar10 & 4) != 0) {
      uVar9 = uVar9 & 0xfffffff7 | ((byte)~(byte)(uVar9 >> 3) & 1) << 3;
    }
    if ((uVar3 & 4) != 0) {
      uVar9 = uVar9 & 0xffffff7f | ((byte)~(byte)(uVar9 >> 7) & 1) << 7;
    }
    if ((uVar4 & 4) != 0) {
      uVar9 = uVar9 & 0xfffff7ff | ((byte)~(byte)(uVar9 >> 0xb) & 1) << 0xb;
    }
    if ((uVar5 & 4) != 0) {
      uVar9 = uVar9 & 0xffff7fff | ((byte)~(byte)(uVar9 >> 0xf) & 1) << 0xf;
    }
    if ((uVar10 & 8) != 0) {
      uVar9 = uVar9 & 0xffff7777 | 0x100000;
    }
    if ((uVar3 & 8) != 0) {
      uVar9 = uVar9 & 0xffff7777 | 0x100000;
    }
    if ((uVar4 & 8) != 0) {
      uVar9 = uVar9 & 0xffff7777 | 0x100000;
    }
    if ((uVar5 & 8) != 0) {
      uVar9 = uVar9 & 0xffff7777 | 0x100000;
    }
  }
  uVar10 = uVar9;
  if (*param_4 != 2) {
    if (*param_4 != 0) {
      return 0;
    }
    local_38 = 0x40000;
    goto LAB_0006fe69;
  }
  iVar1 = *(int *)(param_3 + 0x20) + param_4[1] * 0x54;
  iVar2 = *(int *)(iVar1 + 0x24);
  uVar3 = *(uint *)(iVar1 + 0x28);
  if (uVar3 < 0x87c4) {
    if (uVar3 < 0x87c2) {
      if (uVar3 != 0x87c1) {
        return 0;
      }
      if (iVar2 == 0x87bf) {
        local_38 = CONCAT22(5,*(undefined2 *)(iVar1 + 4));
        if ((*(char *)(iVar1 + 0x44) != '\0') && (*(int *)(iVar1 + 0x48) == 1)) {
          uVar10 = uVar9 & 0xffff8fff | 0x4000;
        }
      }
      else if (iVar2 == 0x87c0) {
        local_38 = CONCAT22(5,*(undefined2 *)(iVar1 + 0x10));
      }
      else {
        if (iVar2 != 0x87be) {
          return 0;
        }
        local_38 = CONCAT22(5,*(undefined2 *)(iVar1 + 4));
        uVar10 = (uint)(*(byte *)(iVar1 + 8) & 7);
        uVar10 = uVar9 & 0xffff8888 | uVar10 | uVar10 << 4 | uVar10 << 8 | uVar10 << 0xc;
        if ((*(char *)(iVar1 + 0x44) != '\0') && (*(int *)(iVar1 + 0x48) == 0xf)) {
          uVar10 = uVar9 & 0xffff8888 | 0x5441;
        }
      }
      goto LAB_0006fe69;
    }
    if (iVar2 == 0x87bf) {
      local_38 = CONCAT22(1,*(undefined2 *)(iVar1 + 4));
      goto LAB_0006fe69;
    }
    if (iVar2 == 0x87c0) {
      local_38 = CONCAT22(1,*(undefined2 *)(iVar1 + 0x10));
      goto LAB_0006fe69;
    }
    if (iVar2 != 0x87be) {
      return 0;
    }
    local_38 = CONCAT22(1,*(undefined2 *)(iVar1 + 4));
  }
  else {
    if (uVar3 != 0x87c4) {
      return 0;
    }
    if (iVar2 == 0x87bf) {
      local_38 = CONCAT22(4,*(undefined2 *)(iVar1 + 4));
      goto LAB_0006fe69;
    }
    if (iVar2 == 0x87c0) {
      local_38 = CONCAT22(4,*(undefined2 *)(iVar1 + 0x10));
      goto LAB_0006fe69;
    }
    if (iVar2 != 0x87be) {
      return 0;
    }
    local_38 = CONCAT22(4,*(undefined2 *)(iVar1 + 4));
  }
  uVar10 = (uint)(*(byte *)(iVar1 + 8) & 7);
  uVar10 = uVar9 & 0xffff8888 | uVar10 | uVar10 << 4 | uVar10 << 8 | uVar10 << 0xc;
LAB_0006fe69:
  if ((param_5 == '\0') && (uVar10 == 0x3210)) {
    if ((char)param_4[6] == '\0') {
      if (param_2[1] <= *param_2) {
        pvVar8 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
        if ((void *)param_2[2] != (void *)0x0) {
          _memcpy(pvVar8,(void *)param_2[2],*param_2 << 2);
          (**(code **)(param_1 + 0x18))(param_2[2]);
        }
        param_2[2] = (uint)pvVar8;
        param_2[1] = param_2[1] + 0x80;
      }
      *(uint *)(param_2[2] + *param_2 * 4) = local_38;
      *param_2 = *param_2 + 1;
      uVar7 = 1;
    }
    else {
      if (param_2[1] <= *param_2) {
        pvVar8 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
        if ((void *)param_2[2] != (void *)0x0) {
          _memcpy(pvVar8,(void *)param_2[2],*param_2 << 2);
          (**(code **)(param_1 + 0x18))(param_2[2]);
        }
        param_2[2] = (uint)pvVar8;
        param_2[1] = param_2[1] + 0x80;
      }
      *(uint *)(param_2[2] + *param_2 * 4) = local_38 | 0x800000;
      uVar9 = *param_2;
      *param_2 = uVar9 + 1;
      if (param_2[1] <= uVar9 + 1) {
        pvVar8 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
        if ((void *)param_2[2] != (void *)0x0) {
          _memcpy(pvVar8,(void *)param_2[2],*param_2 << 2);
          (**(code **)(param_1 + 0x18))(param_2[2]);
        }
        param_2[2] = (uint)pvVar8;
        param_2[1] = param_2[1] + 0x80;
      }
      *(undefined4 *)(param_2[2] + *param_2 * 4) = 0;
      *param_2 = *param_2 + 1;
      uVar7 = 2;
    }
    return uVar7;
  }
  if ((char)param_4[6] != '\0') {
    if (param_2[1] <= *param_2) {
      pvVar8 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
      if ((void *)param_2[2] != (void *)0x0) {
        _memcpy(pvVar8,(void *)param_2[2],*param_2 << 2);
        (**(code **)(param_1 + 0x18))(param_2[2]);
      }
      param_2[2] = (uint)pvVar8;
      param_2[1] = param_2[1] + 0x80;
    }
    *(uint *)(param_2[2] + *param_2 * 4) = local_38 | 0xc00000;
    uVar9 = *param_2;
    *param_2 = uVar9 + 1;
    if (param_2[1] <= uVar9 + 1) {
      pvVar8 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
      if ((void *)param_2[2] != (void *)0x0) {
        _memcpy(pvVar8,(void *)param_2[2],*param_2 << 2);
        (**(code **)(param_1 + 0x18))(param_2[2]);
      }
      param_2[2] = (uint)pvVar8;
      param_2[1] = param_2[1] + 0x80;
    }
    *(uint *)(param_2[2] + *param_2 * 4) = uVar10;
    uVar9 = *param_2;
    *param_2 = uVar9 + 1;
    if (param_2[1] <= uVar9 + 1) {
      pvVar8 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
      if ((void *)param_2[2] != (void *)0x0) {
        _memcpy(pvVar8,(void *)param_2[2],*param_2 << 2);
        (**(code **)(param_1 + 0x18))(param_2[2]);
      }
      param_2[2] = (uint)pvVar8;
      param_2[1] = param_2[1] + 0x80;
    }
    *(undefined4 *)(param_2[2] + *param_2 * 4) = 0;
    *param_2 = *param_2 + 1;
    return 3;
  }
  if (param_2[1] <= *param_2) {
    pvVar8 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar8,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar8;
    param_2[1] = param_2[1] + 0x80;
  }
  *(uint *)(param_2[2] + *param_2 * 4) = local_38 | 0x400000;
  uVar9 = *param_2;
  *param_2 = uVar9 + 1;
  if (param_2[1] <= uVar9 + 1) {
    pvVar8 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar8,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar8;
    param_2[1] = param_2[1] + 0x80;
  }
  *(uint *)(param_2[2] + *param_2 * 4) = uVar10;
  *param_2 = *param_2 + 1;
  return 2;
}

/* FUN_000706e4 @ 0x706e4 (1157 bytes) */
int FUN_000706e4(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint *param_2;
  int *param_3;
  int *param_4;
  int param_5;
{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  void *pvVar6;
  uint uVar7;
  undefined4 local_20;
  
  iVar2 = **(int **)(*param_3 + *(int *)(param_1 + 0x118c) * 4);
  uVar7 = 0x55;
  if (param_4[2] == 0) {
    uVar7 = 0x54;
  }
  if (param_4[3] == 0) {
    uVar7 = uVar7 & 0xfffffff3;
  }
  if (param_4[4] == 0) {
    uVar7 = uVar7 & 0xffffffcf;
  }
  if (param_4[5] == 0) {
    uVar7 = uVar7 & 0xffffff3f;
  }
  if (*param_4 == 1) {
    puVar4 = (uint *)param_4[1];
    if (puVar4 == (uint *)0x879b) {
      local_20 = 0x120000;
      uVar7 = uVar7 | 0x100;
      *(undefined1 *)((int)param_3 + 0x6d) = 1;
    }
    else if (puVar4 < &UINT_0000879c) {
      if (puVar4 == (uint *)0x610f) {
        local_20 = 0x120001;
        uVar7 = uVar7 | 0x100;
        *(undefined1 *)((int)param_3 + 0x6f) = 1;
      }
      else if (puVar4 < (uint *)0x6110) {
        if (puVar4 != (uint *)0x610e) {
          return 0;
        }
        local_20 = 0xd0000;
        uVar7 = uVar7 & 0xffffff03;
        *(undefined1 *)((int)param_3 + 0x79) = 1;
      }
      else if (puVar4 == (uint *)0x6110) {
        local_20 = 0x130001;
        uVar7 = uVar7 | 0x100;
        *(undefined1 *)(param_3 + 0x1c) = 1;
      }
      else {
        if (puVar4 != (uint *)0x879a) {
          return 0;
        }
        local_20 = 0xe0000;
      }
    }
    else if (puVar4 < (uint *)0x87a5) {
      if (puVar4 < (uint *)0x879d) {
        local_20 = 0x130000;
        uVar7 = uVar7 | 0x100;
        *(undefined1 *)((int)param_3 + 0x6e) = 1;
      }
      else {
        local_20 = CONCAT22(0x11,(short)puVar4 + 0x7863);
        if (param_4[2] == 1) {
          *(byte *)((int)(puVar4 + -0x21cb) + (int)param_3) =
               *(byte *)((int)(puVar4 + -0x21cb) + (int)param_3) | 1;
        }
        if (param_4[3] == 1) {
          pbVar1 = (byte *)(param_4[1] + -0x872c + (int)param_3);
          *pbVar1 = *pbVar1 | 2;
        }
        if (param_4[4] == 1) {
          pbVar1 = (byte *)(param_4[1] + -0x872c + (int)param_3);
          *pbVar1 = *pbVar1 | 4;
        }
        if (param_4[5] == 1) {
          pbVar1 = (byte *)(param_4[1] + -0x872c + (int)param_3);
          *pbVar1 = *pbVar1 | 8;
        }
      }
    }
    else {
      if (puVar4 != (uint *)0x87bd) {
        return 0;
      }
      local_20 = CONCAT22(4,*(undefined2 *)((int)&switchdataD_000013c0 + iVar2));
      uVar7 = uVar7 & 0xffffff03;
      *(undefined1 *)((int)param_3 + 0x7a) = 1;
      *(undefined1 *)(iVar2 + 0x33) = 1;
    }
  }
  else {
    if (*param_4 != 2) {
      return 0;
    }
    iVar2 = param_3[8] + param_4[1] * 0x54;
    iVar3 = *(int *)(iVar2 + 0x24);
    if (*(int *)(iVar2 + 0x28) == 0x87c4) {
      if (iVar3 == 0x87bf) {
        local_20 = CONCAT22(4,*(undefined2 *)(iVar2 + 4));
      }
      else if (iVar3 == 0x87c0) {
        local_20 = CONCAT22(4,*(undefined2 *)(iVar2 + 0x10));
      }
      else {
        if (iVar3 != 0x87be) {
          return 0;
        }
        local_20 = CONCAT22(4,*(undefined2 *)(iVar2 + 4));
        iVar2 = *(int *)(iVar2 + 8);
        if (iVar2 == 1) {
          uVar7 = uVar7 & 0xffffff0c;
        }
        else if (iVar2 == 0) {
          uVar7 = uVar7 & 0xffffff03;
        }
        else if (iVar2 == 2) {
          uVar7 = uVar7 & 0xffffff30;
        }
        else {
          if (iVar2 != 3) {
            return 0;
          }
          uVar7 = uVar7 & 0xffffffc0;
        }
      }
    }
    else {
      if (*(int *)(iVar2 + 0x28) != -1) {
        return 0;
      }
      local_20 = 0x30000;
    }
  }
  if ((param_5 == '\0') && (uVar7 == 0x55)) {
    if (param_2[1] <= *param_2) {
      pvVar6 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
      if ((void *)param_2[2] != (void *)0x0) {
        _memcpy(pvVar6,(void *)param_2[2],*param_2 << 2);
        (**(code **)(param_1 + 0x18))(param_2[2]);
      }
      param_2[2] = (uint)pvVar6;
      param_2[1] = param_2[1] + 0x80;
    }
    *(uint *)(param_2[2] + *param_2 * 4) = local_20;
    *param_2 = *param_2 + 1;
    return 1;
  }
  if (param_2[1] <= *param_2) {
    pvVar6 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar6,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar6;
    param_2[1] = param_2[1] + 0x80;
  }
  *(uint *)(param_2[2] + *param_2 * 4) = local_20 | 0x400000;
  uVar5 = *param_2;
  *param_2 = uVar5 + 1;
  if (param_2[1] <= uVar5 + 1) {
    pvVar6 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar6,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar6;
    param_2[1] = param_2[1] + 0x80;
  }
  *(uint *)(param_2[2] + *param_2 * 4) = uVar7;
  *param_2 = *param_2 + 1;
  return 2;
}

/* FUN_00070b69 @ 0x70b69 (163 bytes) */
int FUN_00070b69(param_1, param_2, param_3, param_4)
  int param_1;
  uint *param_2;
  int param_3;
  int param_4;
{
  void *pvVar1;
  uint uVar2;
  
  uVar2 = (uint)param_3 | (param_4 & 0x3fff) << 0x10;
  if (*param_2 < param_2[1]) {
    *(uint *)(param_2[2] + *param_2 * 4) = uVar2;
    *param_2 = *param_2 + 1;
    return 1;
  }
  pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
  if ((void *)param_2[2] != (void *)0x0) {
    _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
    (**(code **)(param_1 + 0x18))(param_2[2]);
  }
  param_2[2] = (uint)pvVar1;
  param_2[1] = param_2[1] + 0x80;
  *(uint *)(param_2[2] + *param_2 * 4) = uVar2;
  *param_2 = *param_2 + 1;
  return 1;
}

/* FUN_00070c0c @ 0x70c0c (186 bytes) */
int FUN_00070c0c()
{
  int iVar1;
  int in_stack_00000010;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  iVar1 = ((int (*)())FUN_00070b69)(0);
  if (iVar1 != 0) {
    local_28 = *(undefined4 *)(in_stack_00000010 + 4);
    local_24 = *(undefined4 *)(in_stack_00000010 + 8);
    local_10 = *(undefined4 *)(in_stack_00000010 + 0x1c);
    local_20 = 1;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    iVar1 = ((int (*)())FUN_000706e4)(&local_28,1);
    if ((iVar1 != 0) && (iVar1 = ((int (*)())FUN_0006fb97)(in_stack_00000010 + 0x20,0,0), iVar1 != 0)) {
      return 1;
    }
  }
  return 0xffffffff;
}

/* FUN_00070cc6 @ 0x70cc6 (160 bytes) */
int FUN_00070cc6()
{
  int iVar1;
  int in_stack_00000010;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  iVar1 = ((int (*)())FUN_00070b69)(0);
  if ((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000706e4)(in_stack_00000010 + 4,0), iVar1 != 0)) {
    local_1c = 0xc;
    local_18 = 4;
    local_14 = 4;
    local_10 = 4;
    iVar1 = ((int (*)())FUN_0006fb97)(in_stack_00000010 + 0x20,1,&local_1c);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0xffffffff;
}

/* FUN_00070d66 @ 0x70d66 (133 bytes) */
int FUN_00070d66()
{
  int iVar1;
  int in_stack_00000010;
  
  iVar1 = ((int (*)())FUN_00070b69)(0);
  if (((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000706e4)(in_stack_00000010 + 4,0), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_0006fb97)(in_stack_00000010 + 0x20,1,0), iVar1 != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00070deb @ 0x70deb (182 bytes) */
int FUN_00070deb()
{
  int iVar1;
  int in_stack_00000010;
  
  iVar1 = ((int (*)())FUN_00070b69)(0);
  if ((((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000706e4)(in_stack_00000010 + 4,0), iVar1 != 0)) &&
      (iVar1 = ((int (*)())FUN_0006fb97)(in_stack_00000010 + 0x20,0,0), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_0006fb97)(in_stack_00000010 + 0x3c,0,0), iVar1 != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00070ea1 @ 0x70ea1 (133 bytes) */
int FUN_00070ea1()
{
  int iVar1;
  int in_stack_00000010;
  
  iVar1 = ((int (*)())FUN_00070b69)(0);
  if (((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000706e4)(in_stack_00000010 + 4,0), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_0006fb97)(in_stack_00000010 + 0x20,0,0), iVar1 != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00070f26 @ 0x70f26 (396 bytes) */
int FUN_00070f26(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  iVar2 = FUN_00053994(param_3 + 0x1c,param_4 + 4);
  uVar1 = *(uint *)(param_4 + 0x40);
  if (((uVar1 < 4) && (iVar3 = ((int (*)())FUN_00070b69)(0), iVar3 != 0)) &&
     (iVar3 = ((int (*)())FUN_000706e4)(param_4 + 4,0), iVar3 != 0)) {
    local_38 = *(undefined4 *)(param_4 + 0x20);
    local_34 = *(int *)(param_4 + 0x24);
    local_30 = *(undefined4 *)(param_4 + 0x28);
    local_2c = *(undefined4 *)(param_4 + 0x2c);
    local_28 = *(undefined4 *)(param_4 + 0x30);
    local_24 = *(undefined4 *)(param_4 + 0x34);
    local_20 = *(undefined4 *)(param_4 + 0x38);
    if (iVar2 == 0x87be) {
      if (uVar1 == 1) {
        local_1c = 1;
        local_18 = 1;
        local_14 = 1;
        local_10 = 1;
      }
      else if (uVar1 == 0) {
        local_1c = 0;
        local_18 = 0;
        local_14 = 0;
        local_10 = 0;
      }
      else if (uVar1 == 2) {
        local_1c = 2;
        local_18 = 2;
        local_14 = 2;
        local_10 = 2;
      }
      else if (uVar1 == 3) {
        local_1c = 3;
        local_18 = 3;
        local_14 = 3;
        local_10 = 3;
      }
      puVar4 = &local_1c;
    }
    else {
      local_34 = uVar1 + local_34;
      puVar4 = (undefined4 *)0x0;
    }
    iVar2 = ((int (*)())FUN_0006fb97)(&local_38,1,puVar4);
    if (iVar2 != 0) {
      return 1;
    }
  }
  return 0xffffffff;
}

/* FUN_000710b2 @ 0x710b2 (604 bytes) */
int FUN_000710b2(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  iVar2 = FUN_00053994(param_3 + 0x1c,param_4 + 4);
  uVar1 = *(uint *)(param_4 + 0x40);
  if ((uVar1 < 4) && (iVar3 = ((int (*)())FUN_00070b69)(0), iVar3 != 0)) {
    if (iVar2 == 0x87bf) {
      local_28 = *(undefined4 *)(param_4 + 4);
      local_24 = *(int *)(param_4 + 8);
      local_20 = *(undefined4 *)(param_4 + 0xc);
      local_1c = *(undefined4 *)(param_4 + 0x10);
      local_18 = *(undefined4 *)(param_4 + 0x14);
      local_14 = *(undefined4 *)(param_4 + 0x18);
      local_10 = *(undefined4 *)(param_4 + 0x1c);
      if (uVar1 == 1) {
        local_20 = 0;
        local_18 = 0;
        local_14 = 0;
      }
      else if (uVar1 == 0) {
        local_1c = 0;
        local_18 = 0;
        local_14 = 0;
      }
      else if (uVar1 == 2) {
        local_20 = 0;
        local_1c = 0;
        local_14 = 0;
      }
      else if (uVar1 == 3) {
        local_20 = 0;
        local_1c = 0;
        local_18 = 0;
      }
    }
    else {
      local_28 = *(undefined4 *)(param_4 + 4);
      local_20 = *(undefined4 *)(param_4 + 0xc);
      local_1c = *(undefined4 *)(param_4 + 0x10);
      local_18 = *(undefined4 *)(param_4 + 0x14);
      local_14 = *(undefined4 *)(param_4 + 0x18);
      local_10 = *(undefined4 *)(param_4 + 0x1c);
      local_24 = uVar1 + *(int *)(param_4 + 8);
    }
    puVar4 = &local_28;
    iVar3 = ((int (*)())FUN_000706e4)(puVar4,1);
    if (iVar3 != 0) {
      if (iVar2 == 0x87bf) {
        if (uVar1 == 1) {
          local_28 = 1;
          local_24 = 1;
          local_20 = 1;
          local_1c = 1;
        }
        else if (uVar1 == 0) {
          local_28 = 0;
          local_24 = 0;
          local_20 = 0;
          local_1c = 0;
        }
        else if (uVar1 == 2) {
          local_28 = 2;
          local_24 = 2;
          local_20 = 2;
          local_1c = 2;
        }
        else if (uVar1 == 3) {
          local_28 = 3;
          local_24 = 3;
          local_20 = 3;
          local_1c = 3;
        }
      }
      else {
        puVar4 = (undefined4 *)0x0;
      }
      ((int (*)())FUN_0006fb97)(param_4 + 0x20,1,puVar4);
      return 1;
    }
  }
  return 0xffffffff;
}

/* FUN_0007130e @ 0x7130e (133 bytes) */
int FUN_0007130e()
{
  int iVar1;
  int in_stack_00000010;
  
  iVar1 = ((int (*)())FUN_00070b69)(0);
  if (((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000706e4)(in_stack_00000010 + 4,1), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_0006fb97)(in_stack_00000010 + 0x20,0,0), iVar1 != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00071393 @ 0x71393 (133 bytes) */
int FUN_00071393()
{
  int iVar1;
  int in_stack_00000010;
  
  iVar1 = ((int (*)())FUN_00070b69)(0);
  if (((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000706e4)(in_stack_00000010 + 4,0), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_0006fb97)(in_stack_00000010 + 0x20,0,0), iVar1 != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00071418 @ 0x71418 (133 bytes) */
int FUN_00071418()
{
  int iVar1;
  int in_stack_00000010;
  
  iVar1 = ((int (*)())FUN_00070b69)(0);
  if (((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000706e4)(in_stack_00000010 + 4,0), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_0006fb97)(in_stack_00000010 + 0x20,0,0), iVar1 != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_0007149d @ 0x7149d (182 bytes) */
int FUN_0007149d()
{
  int iVar1;
  int in_stack_00000010;
  
  iVar1 = ((int (*)())FUN_00070b69)(0);
  if ((((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000706e4)(in_stack_00000010 + 4,0), iVar1 != 0)) &&
      (iVar1 = ((int (*)())FUN_0006fb97)(in_stack_00000010 + 0x3c,0,0), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_0006fb97)(in_stack_00000010 + 0x20,0,0), iVar1 != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00071553 @ 0x71553 (182 bytes) */
int FUN_00071553()
{
  int iVar1;
  int in_stack_00000010;
  
  iVar1 = ((int (*)())FUN_00070b69)(0);
  if ((((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000706e4)(in_stack_00000010 + 4,0), iVar1 != 0)) &&
      (iVar1 = ((int (*)())FUN_0006fb97)(in_stack_00000010 + 0x20,0,0), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_0006fb97)(in_stack_00000010 + 0x3c,0,0), iVar1 != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00071609 @ 0x71609 (182 bytes) */
int FUN_00071609()
{
  int iVar1;
  int in_stack_00000010;
  
  iVar1 = ((int (*)())FUN_00070b69)(0);
  if ((((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000706e4)(in_stack_00000010 + 4,0), iVar1 != 0)) &&
      (iVar1 = ((int (*)())FUN_0006fb97)(in_stack_00000010 + 0x20,0,0), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_0006fb97)(in_stack_00000010 + 0x3c,0,0), iVar1 != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_000716bf @ 0x716bf (133 bytes) */
int FUN_000716bf()
{
  int iVar1;
  int in_stack_00000010;
  
  iVar1 = ((int (*)())FUN_00070b69)(3);
  if (((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000706e4)(in_stack_00000010 + 4,0), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_0006fb97)(in_stack_00000010 + 0x20,0,0), iVar1 != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00071744 @ 0x71744 (133 bytes) */
int FUN_00071744()
{
  int iVar1;
  int in_stack_00000010;
  
  iVar1 = ((int (*)())FUN_00070b69)(3);
  if (((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000706e4)(in_stack_00000010 + 4,0), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_0006fb97)(in_stack_00000010 + 0x20,0,0), iVar1 != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_000717c9 @ 0x717c9 (182 bytes) */
int FUN_000717c9()
{
  int iVar1;
  int in_stack_00000010;
  
  iVar1 = ((int (*)())FUN_00070b69)(0);
  if ((((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000706e4)(in_stack_00000010 + 4,0), iVar1 != 0)) &&
      (iVar1 = ((int (*)())FUN_0006fb97)(in_stack_00000010 + 0x20,0,0), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_0006fb97)(in_stack_00000010 + 0x3c,0,0), iVar1 != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_0007187f @ 0x7187f (133 bytes) */
int FUN_0007187f()
{
  int iVar1;
  int in_stack_00000010;
  
  iVar1 = ((int (*)())FUN_00070b69)(0);
  if (((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000706e4)(in_stack_00000010 + 4,0), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_0006fb97)(in_stack_00000010 + 0x20,0,0), iVar1 != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00071904 @ 0x71904 (133 bytes) */
int FUN_00071904()
{
  int iVar1;
  int in_stack_00000010;
  
  iVar1 = ((int (*)())FUN_00070b69)(0);
  if (((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000706e4)(in_stack_00000010 + 4,0), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_0006fb97)(in_stack_00000010 + 0x20,0,0), iVar1 != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00071989 @ 0x71989 (133 bytes) */
int FUN_00071989()
{
  int iVar1;
  int in_stack_00000010;
  
  iVar1 = ((int (*)())FUN_00070b69)(0);
  if (((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000706e4)(in_stack_00000010 + 4,0), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_0006fb97)(in_stack_00000010 + 0x20,0,0), iVar1 != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00071a0e @ 0x71a0e (133 bytes) */
int FUN_00071a0e()
{
  int iVar1;
  int in_stack_00000010;
  
  iVar1 = ((int (*)())FUN_00070b69)(0);
  if (((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000706e4)(in_stack_00000010 + 4,0), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_0006fb97)(in_stack_00000010 + 0x20,0,0), iVar1 != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00071a93 @ 0x71a93 (228 bytes) */
int FUN_00071a93()
{
  int iVar1;
  int in_stack_00000010;
  
  iVar1 = ((int (*)())FUN_00070b69)(0);
  if ((((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000706e4)(in_stack_00000010 + 4,0), iVar1 != 0)) &&
      (iVar1 = ((int (*)())FUN_0006fb97)(in_stack_00000010 + 0x20,0,0), iVar1 != 0)) &&
     ((iVar1 = ((int (*)())FUN_0006fb97)(in_stack_00000010 + 0x3c,0,0), iVar1 != 0 &&
      (iVar1 = ((int (*)())FUN_0006fb97)(in_stack_00000010 + 0x58,0,0), iVar1 != 0)))) {
    return 1;
  }
  return 0xffffffff;
}

