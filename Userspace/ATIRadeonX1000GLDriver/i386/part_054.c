#include "decls.h"

/* FUN_001b1e60 @ 0x1b1e60 (65 bytes) */
int FUN_001b1e60(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_2 + 0xbc);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x98);
  *puVar2 = uVar1;
  *(undefined1 *)(puVar2 + 7) = 0;
  puVar2[1] = &PTR_FUN_001fe088;
  return puVar2 + 1;
}

/* FUN_001b1ea2 @ 0x1b1ea2 (132 bytes) */
int FUN_001b1ea2(param_1)
  undefined4 *param_1;
{
  int iVar1;
  
  *param_1 = &PTR_FUN_001fe088;
  iVar1 = param_1[0x24];
  if (iVar1 != 0) {
    FUN_001a7aba(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = param_1[0x23];
  if (iVar1 != 0) {
    FUN_001a7aba(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  FUN_001af390();
  return;
}

/* FUN_001b1f38 @ 0x1b1f38 (132 bytes) */
int FUN_001b1f38(param_1)
  undefined4 *param_1;
{
  int iVar1;
  
  *param_1 = &PTR_FUN_001fe088;
  iVar1 = param_1[0x24];
  if (iVar1 != 0) {
    FUN_001a7aba(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = param_1[0x23];
  if (iVar1 != 0) {
    FUN_001a7aba(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  FUN_001af390();
  return;
}

/* FUN_001b1fce @ 0x1b1fce (307 bytes) */
int FUN_001b1fce(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  char *pcVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  pcVar1 = *(char **)(param_2 + 0xac);
  FUN_001a7f3c(param_1[0x23],*(int *)(param_1[0x23] + 4) + -1);
  if (*pcVar1 == '\0') {
    iVar3 = param_1[0x23];
    uVar5 = *(int *)(iVar3 + 4) - 1;
    if (uVar5 < *(uint *)(iVar3 + 4)) {
      piVar2 = (int *)(*(int *)(iVar3 + 8) + uVar5 * 4);
    }
    else {
      piVar2 = (int *)0x0;
    }
    iVar3 = *piVar2;
    FUN_000e4164(param_3,iVar3);
    if (iVar3 != 0) {
      iVar3 = FUN_0010a17a(0x58,param_4);
      iVar4 = FUN_001b13a8(param_1);
      *(undefined4 *)(iVar3 + 0x94) = *(undefined4 *)(iVar4 + 0x94);
      *(undefined4 *)(iVar3 + 0x98) = 0;
      *(undefined4 *)(iVar3 + 0x9c) = DAT_001cf30c;
      FUN_0010ba02(iVar3,1,iVar4,0,param_4);
      iVar4 = FUN_0010b0f4(iVar3,1);
      *(undefined4 *)(iVar4 + 0x10) = DAT_001cf308;
      FUN_000e9540(param_2,iVar3);
    }
  }
                    
                    
  (**(code **)(*param_1 + 0x34))();
  return;
}

/* FUN_001b2102 @ 0x1b2102 (568 bytes) */
int FUN_001b2102(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  
  pcVar1 = *(char **)(param_2 + 0xac);
  if (((0 < *(int *)(*(int *)(param_2 + 0x124) + 0x130)) ||
      (*(char *)(*(int *)(param_2 + 0x124) + 0x134) != '\0')) &&
     (FUN_001a7f3c(param_1[0x23],*(int *)(param_1[0x23] + 4) + -1), *pcVar1 == '\0')) {
    iVar5 = param_1[0x23];
    uVar7 = *(int *)(iVar5 + 4) - 1;
    if (uVar7 < *(uint *)(iVar5 + 4)) {
      puVar4 = (undefined4 *)(*(int *)(iVar5 + 8) + uVar7 * 4);
    }
    else {
      puVar4 = (undefined4 *)0x0;
    }
    FUN_000e4164(param_3,*puVar4);
    iVar5 = param_1[0x24];
    iVar2 = *(int *)(iVar5 + 4);
    if (0 < iVar2) {
      uVar7 = iVar2 - 1;
      if (uVar7 < *(uint *)(iVar5 + 4)) {
        puVar4 = (undefined4 *)(*(int *)(iVar5 + 8) + uVar7 * 4);
      }
      else {
        puVar4 = (undefined4 *)0x0;
      }
      uVar3 = *puVar4;
      FUN_001a7f3c(iVar5,iVar2 + -1);
      iVar5 = FUN_001b13a8(param_1);
      iVar5 = *(int *)(iVar5 + 0x94);
      piVar6 = (int *)FUN_0010a17a(0x5a,param_4);
      piVar6[0x25] = iVar5;
      piVar6[0x26] = 0;
      piVar6[0x27] = DAT_001cf30c;
      FUN_0010ba02(piVar6,1,uVar3,0,param_4);
      if (3 < iVar2) {
        if (iVar2 < 8) {
          uVar7 = iVar2 - 4;
        }
        else {
          uVar7 = 0;
        }
      }
      (**(code **)(*piVar6 + 0x88))(piVar6,1,0,uVar7);
      (**(code **)(*piVar6 + 0x88))(piVar6,1,1,uVar7);
      (**(code **)(*piVar6 + 0x88))(piVar6,1,2,uVar7);
      (**(code **)(*piVar6 + 0x88))(piVar6,1,3,uVar7);
      FUN_000e9540(param_2,piVar6);
    }
  }
                    
                    
  (**(code **)(*param_1 + 0x34))();
  return;
}

/* FUN_001b233a @ 0x1b233a (1078 bytes) */
int FUN_001b233a(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  char *pcVar1;
  uint *puVar2;
  code *pcVar3;
  char cVar4;
  int *piVar5;
  int *piVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  uint uVar10;
  int iVar11;
  bool bVar12;
  bool bVar13;
  
  pcVar1 = *(char **)(param_2 + 0xac);
  piVar5 = (int *)FUN_000e9644(param_2);
  if (*pcVar1 != '\0') {
    (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined1 *)(param_2 + 0xdc));
    puVar2 = (uint *)param_1[0x23];
    uVar10 = puVar2[1];
    if (*puVar2 <= uVar10) {
      puVar9 = (undefined4 *)FUN_001a7f7c(puVar2,uVar10);
      *puVar9 = 3;
      return;
    }
    _memset((void *)(uVar10 * 4 + puVar2[2]),0,4);
    puVar2[1] = uVar10 + 1;
    *(undefined4 *)(uVar10 * 4 + puVar2[2]) = 3;
    return;
  }
  (**(code **)(*piVar5 + 0x14))(piVar5);
  iVar11 = param_1[0x23];
  uVar10 = *(int *)(iVar11 + 4) - 1;
  if (uVar10 < *(uint *)(iVar11 + 4)) {
    bVar12 = *(int *)(*(int *)(iVar11 + 8) + uVar10 * 4) != 0;
    iVar11 = piVar5[0x4b];
    iVar8 = iVar11 + -1;
    bVar13 = false;
    if (iVar8 != 0) goto LAB_001b241b;
  }
  else {
    bVar12 = MACH_HEADER.magic != 0;
    iVar11 = piVar5[0x4b];
    iVar8 = iVar11 + -1;
    bVar13 = iVar11 == 1;
    if (!bVar13) {
LAB_001b241b:
      if (bVar13 || SBORROW4(iVar11,1) != iVar8 < 0) {
        if (iVar11 == 0) {
          cVar4 = (-!bVar12 & 0x27U) + 0x2c;
        }
        else {
LAB_001b2433:
          cVar4 = '\0';
        }
      }
      else if (iVar11 == 2) {
        cVar4 = (-!bVar12 & 0x27U) + 0x2e;
      }
      else {
        if (iVar11 != 3) goto LAB_001b2433;
        cVar4 = (-!bVar12 & 0x27U) + 0x2f;
      }
      piVar6 = (int *)FUN_0010a17a(cVar4,param_4);
      goto joined_r0x001b2619;
    }
  }
  piVar6 = (int *)FUN_0010a17a((-!bVar12 & 0x27U) + 0x2d,param_4);
joined_r0x001b2619:
  if (bVar12) {
    iVar11 = FUN_001b13a8(param_1);
    piVar6[0x25] = *(int *)(iVar11 + 0x94);
    piVar6[0x26] = 0;
    piVar6[0x27] = DAT_001cf30c;
    FUN_0010ba02(piVar6,1,iVar11,0,param_4);
    iVar11 = FUN_0010b0f4(piVar6,1);
    *(undefined4 *)(iVar11 + 0x10) = DAT_001cf308;
    uVar7 = FUN_0010b180(piVar5,1);
    FUN_0010ba02(piVar6,2,uVar7,0,param_4);
  }
  else {
    if (*(char *)(param_2 + 0x13c) == '\0') {
      iVar11 = FUN_001b13a8(param_1);
      piVar6[0x25] = *(int *)(iVar11 + 0x94);
      piVar6[0x26] = 0;
      piVar6[0x27] = DAT_001cf30c;
    }
    else {
      piVar6[0x25] = 0;
      piVar6[0x26] = 0;
      piVar6[0x27] = DAT_001cf310;
    }
    uVar7 = FUN_0010b180(piVar5,1);
    FUN_0010ba02(piVar6,1,uVar7,0,param_4);
  }
  iVar11 = 0;
  do {
    pcVar3 = *(code **)(*piVar6 + 0x88);
    iVar8 = FUN_0010b0f4(piVar5,1);
    (*pcVar3)(piVar6,2 - (uint)!bVar12,iVar11,*(undefined1 *)(iVar8 + 0x13));
    iVar11 = iVar11 + 1;
  } while (iVar11 != 4);
  if ((*(byte *)(piVar5 + 0x2e) & 1) != 0) {
    FUN_00109c0e(piVar6 + ((uint)!bVar12 * -3 + 6) * 2 + 0x23,1,1);
  }
  FUN_000e9512(param_2,piVar6);
  FUN_001a7c98(piVar5);
  *(undefined4 *)(param_2 + 0x128) = 0;
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined1 *)(param_2 + 0xdc));
  puVar2 = (uint *)param_1[0x23];
  uVar10 = puVar2[1];
  if (*puVar2 <= uVar10) {
    puVar9 = (undefined4 *)FUN_001a7f7c(puVar2,uVar10);
    *puVar9 = 3;
    return;
  }
  _memset((void *)(uVar10 * 4 + puVar2[2]),0,4);
  puVar2[1] = uVar10 + 1;
  *(undefined4 *)(uVar10 * 4 + puVar2[2]) = 3;
  return;
}

/* FUN_001b2770 @ 0x1b2770 (132 bytes) */
int FUN_001b2770(param_1, param_2)
  int param_1;
  int param_2;
{
  uint *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  FUN_001ae952(param_1,param_2);
  puVar1 = *(uint **)(param_1 + 0x8c);
  uVar2 = puVar1[1];
  if (uVar2 < *puVar1) {
    _memset((void *)(uVar2 * 4 + puVar1[2]),0,4);
    puVar1[1] = uVar2 + 1;
    *(undefined4 *)(uVar2 * 4 + puVar1[2]) = 0;
    return;
  }
  puVar3 = (undefined4 *)FUN_001a7f7c(puVar1,uVar2);
  *puVar3 = 0;
  return;
}

/* FUN_001b27f4 @ 0x1b27f4 (832 bytes) */
int FUN_001b27f4(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  char *pcVar1;
  code *UNRECOVERED_JUMPTABLE;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  uint *puVar8;
  undefined4 local_2c;
  uint local_20;
  
  pcVar1 = *(char **)(param_2 + 0xac);
  if ((*(int *)(param_2 + 0x130) < 1) && (*(char *)(param_2 + 0x134) == '\0')) goto LAB_001b28bf;
  iVar3 = FUN_001b13a8(param_1);
  local_2c = *(undefined4 *)(iVar3 + 0x94);
  puVar8 = (uint *)param_1[0x23];
  if (puVar8[1] - 1 < puVar8[1]) {
    if (*(int *)(puVar8[2] + (puVar8[1] - 1) * 4) == 0) goto LAB_001b286f;
LAB_001b2926:
    if (*pcVar1 != '\0') goto LAB_001b287b;
    iVar7 = *(int *)(param_1[0x24] + 4);
    if (2 < iVar7) {
      if (iVar7 < 7) {
        local_2c = FUN_00137d6c(pcVar1,0);
        iVar7 = iVar7 + -3;
      }
      else {
        local_2c = 0;
        iVar7 = 0;
      }
    }
    iVar5 = FUN_0010dbb8(0x66,param_4);
    *(undefined4 *)(iVar5 + 0x94) = local_2c;
    *(undefined4 *)(iVar5 + 0x98) = 0;
    *(undefined4 *)(iVar5 + 0x9c) = DAT_001cf310;
    *(undefined1 *)(iVar7 + 0x9c + iVar5) = 0;
    FUN_0010ba02(iVar5,1,iVar3,0,param_4);
    iVar3 = FUN_0010b0f4(iVar5,1);
    *(undefined4 *)(iVar3 + 0x10) = DAT_001cf308;
    *(uint *)(iVar5 + 0x14) = *(uint *)(iVar5 + 0x14) & 0xfffffffb;
    FUN_000e9512(param_2,iVar5);
    puVar8 = (uint *)param_1[0x24];
    uVar2 = puVar8[1];
    if (uVar2 < *puVar8) {
      _memset((void *)(uVar2 * 4 + puVar8[2]),0,4);
      puVar8[1] = uVar2 + 1;
      piVar6 = (int *)(uVar2 * 4 + puVar8[2]);
    }
    else {
      piVar6 = (int *)FUN_001a7f7c(puVar8,uVar2);
    }
    *piVar6 = iVar5;
    puVar8 = (uint *)param_1[0x23];
    local_20 = puVar8[1];
    if (*puVar8 <= local_20) goto LAB_001b2a44;
LAB_001b2889:
    _memset((void *)(local_20 * 4 + puVar8[2]),0,4);
    puVar8[1] = local_20 + 1;
    puVar4 = (undefined4 *)(local_20 * 4 + puVar8[2]);
  }
  else {
    if (MACH_HEADER.magic != 0) goto LAB_001b2926;
LAB_001b286f:
    if (*pcVar1 == '\0') {
      iVar3 = FUN_0010a17a(0x53,param_4);
      *(undefined4 *)(iVar3 + 0x94) = local_2c;
      *(undefined4 *)(iVar3 + 0x98) = 0;
      *(undefined4 *)(iVar3 + 0x9c) = DAT_001cf30c;
      FUN_000fa0d2(iVar3,pcVar1,1,0,0,0,0);
      *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) & 0xfffffffb;
      FUN_000e9512(param_2,iVar3);
      puVar8 = (uint *)param_1[0x23];
    }
LAB_001b287b:
    local_20 = puVar8[1];
    if (local_20 < *puVar8) goto LAB_001b2889;
LAB_001b2a44:
    puVar4 = (undefined4 *)FUN_001a7f7c(puVar8,local_20);
  }
  *puVar4 = 3;
LAB_001b28bf:
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined1 *)(param_2 + 0xdc));
  UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x9c);
  FUN_000e9a1c(param_2);
                    
                    
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

/* FUN_001b2b34 @ 0x1b2b34 (88 bytes) */
int FUN_001b2b34(param_1, param_2)
  int param_1;
  int param_2;
{
  if ((*(byte *)(param_1 + 2) & 0x40) != 0) {
    if (param_2 == 1) {
      return *(byte *)(param_1 + 4) >> 2 & 3;
    }
    if (param_2 < 2) {
      if (param_2 == 0) {
        return *(byte *)(param_1 + 4) & 3;
      }
    }
    else {
      if (param_2 == 2) {
        return *(byte *)(param_1 + 4) >> 4 & 3;
      }
      if (param_2 == 3) {
        return *(byte *)(param_1 + 4) >> 6;
      }
    }
  }
  return 1;
}

/* FUN_001b2b8c @ 0x1b2b8c (134 bytes) */
int FUN_001b2b8c(param_1, param_2)
  int param_1;
  int param_2;
{
  if ((*(byte *)(param_1 + 2) & 0x40) == 0) {
    if (param_2 == 1) {
      return 1;
    }
    if (param_2 < 2) {
      if (param_2 == 0) {
        return 0;
      }
    }
    else {
      if (param_2 == 2) {
        return 2;
      }
      if (param_2 == 3) {
        return 3;
      }
    }
  }
  else {
    if (param_2 == 1) {
      return *(byte *)(param_1 + 4) >> 4 & 7;
    }
    if (param_2 < 2) {
      if (param_2 == 0) {
        return *(byte *)(param_1 + 4) & 7;
      }
    }
    else {
      if (param_2 == 2) {
        return *(byte *)(param_1 + 5) & 7;
      }
      if (param_2 == 3) {
        return *(byte *)(param_1 + 5) >> 4 & 7;
      }
    }
  }
  return 0xffffffff;
}

/* FUN_001b2c12 @ 0x1b2c12 (26 bytes) */
int FUN_001b2c12(param_1)
  int param_1;
{
  if ((*(byte *)(param_1 + 2) & 0x40) != 0) {
    return *(uint *)(param_1 + 4) & 0x8888;
  }
  return 0;
}

/* FUN_001b2c2c @ 0x1b2c2c (91 bytes) */
int FUN_001b2c2c(param_1, param_2)
  int param_1;
  int param_2;
{
  if ((*(byte *)(param_1 + 2) & 0x40) != 0) {
    if (param_2 == 1) {
      return *(byte *)(param_1 + 4) >> 7;
    }
    if (param_2 < 2) {
      if (param_2 == 0) {
        return *(byte *)(param_1 + 4) >> 3 & 1;
      }
    }
    else {
      if (param_2 == 2) {
        return *(byte *)(param_1 + 5) >> 3 & 1;
      }
      if (param_2 == 3) {
        return *(byte *)(param_1 + 5) >> 7;
      }
    }
  }
  return 0;
}

/* FUN_001b2c88 @ 0x1b2c88 (131 bytes) */
int FUN_001b2c88(param_1)
  int param_1;
{
  byte bVar1;
  int iVar2;
  
  if ((*(byte *)(param_1 + 2) & 0x40) == 0) {
    return 0;
  }
  bVar1 = *(byte *)(param_1 + 4);
  if (1 < (byte)((bVar1 & 3) - 2)) {
    iVar2 = 0;
    do {
      while( true ) {
        do {
          while( true ) {
            iVar2 = iVar2 + 1;
            if (3 < iVar2) {
              return 0;
            }
            if (iVar2 != 1) break;
            if ((bVar1 & 0xc) == 8) {
              return 1;
            }
            if ((bVar1 & 0xc) == 0xc) {
              return 1;
            }
          }
        } while (iVar2 < 2);
        if (iVar2 != 2) break;
        if ((bVar1 & 0x30) == 0x20) {
          return 1;
        }
        if ((bVar1 & 0x30) == 0x30) {
          return 1;
        }
      }
    } while ((iVar2 != 3) || (((bVar1 & 0xc0) != 0x80 && ((bVar1 & 0xc0) != 0xc0))));
  }
  return 1;
}

/* FUN_001b2d0c @ 0x1b2d0c (123 bytes) */
int FUN_001b2d0c(param_1)
  int param_1;
{
  byte bVar1;
  byte bVar2;
  int iVar3;
  
  if ((*(byte *)(param_1 + 2) & 0x40) == 0) {
    return 0;
  }
  if (1 < (byte)((*(byte *)(param_1 + 4) & 7) - 4)) {
    iVar3 = 0;
    bVar2 = *(byte *)(param_1 + 4) & 0x70;
LAB_001b2d2f:
    do {
      do {
        while( true ) {
          iVar3 = iVar3 + 1;
          if (3 < iVar3) {
            return 0;
          }
          if (iVar3 != 1) break;
          bVar1 = bVar2;
          if (bVar2 == 0x40) {
            return 1;
          }
joined_r0x001b2d6b:
          if (bVar1 == 0x50) {
            return 1;
          }
        }
      } while (iVar3 < 2);
      if (iVar3 != 2) {
        if (iVar3 == 3) {
          bVar1 = *(byte *)(param_1 + 5) & 0x70;
          if (bVar1 == 0x40) {
            return 1;
          }
          goto joined_r0x001b2d6b;
        }
        goto LAB_001b2d2f;
      }
    } while (1 < (byte)((*(byte *)(param_1 + 5) & 7) - 4));
  }
  return 1;
}

/* FUN_001b2d88 @ 0x1b2d88 (76 bytes) */
int FUN_001b2d88(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  
  if (param_1 == 1) {
    return param_3 + 4;
  }
  if (param_2 < 0) {
    return param_3;
  }
  iVar2 = 0;
  do {
    iVar1 = ((int (*)())FUN_001b2dd4)(param_3);
    param_3 = param_3 + iVar1 * 4;
    iVar2 = iVar2 + 1;
  } while (iVar2 <= param_2);
  return param_3;
}

/* FUN_001b2dd4 @ 0x1b2dd4 (164 bytes) */
int FUN_001b2dd4(param_1)
  int param_1;
{
  ushort uVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  
  iVar4 = param_1 + 4;
  if ((*(byte *)(param_1 + 2) & 0x40) != 0) {
    iVar4 = param_1 + 8;
  }
  uVar1 = *(ushort *)(param_1 + 2);
  if ((uVar1 & 0x180) == 0) {
    bVar3 = *(byte *)(param_1 + 3);
    if ((bVar3 & 2) != 0) {
      uVar5 = 0;
      do {
        iVar2 = ((int (*)())FUN_001b2dd4)(iVar4);
        iVar4 = iVar4 + iVar2 * 4;
        uVar5 = uVar5 + 1;
        bVar3 = *(byte *)(param_1 + 3);
      } while (uVar5 < (bVar3 >> 1 & 1));
      uVar1 = *(ushort *)(param_1 + 2);
    }
    if ((uVar1 & 0x180) == 0) goto LAB_001b2e0e;
  }
  iVar4 = ((int (*)())FUN_001b2d88)();
  bVar3 = *(byte *)(param_1 + 3);
LAB_001b2e0e:
  if ((bVar3 & 4) != 0) {
    iVar4 = iVar4 + 4;
  }
  return iVar4 - param_1 >> 2;
}

/* FUN_001b2e78 @ 0x1b2e78 (94 bytes) */
int FUN_001b2e78(param_1)
  short *param_1;
{
  short *psVar1;
  short *psVar2;
  
  if (*param_1 == 0x7d) {
    return 1;
  }
  psVar2 = param_1 + 2;
  if ((char)*(byte *)((int)param_1 + 3) < '\0') {
    psVar2 = param_1 + 4;
  }
  if (*param_1 != 0x17) {
    psVar1 = psVar2 + 2;
    if ((*(byte *)((int)param_1 + 3) & 0x40) == 0) {
      psVar1 = psVar2;
    }
    return (int)psVar1 - (int)param_1 >> 2;
  }
  return (int)psVar2 - (int)param_1 >> 2;
}

/* FUN_001b2ed6 @ 0x1b2ed6 (102 bytes) */
int FUN_001b2ed6(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = param_1 + 4;
  if ((*(byte *)(param_1 + 2) & 0x40) != 0) {
    iVar1 = param_1 + 8;
  }
  if ((*(ushort *)(param_1 + 2) & 0x180) == 0) {
    if ((*(byte *)(param_1 + 3) & 4) != 0) {
      iVar1 = iVar1 + 4;
    }
    return iVar1 - param_1 >> 2;
  }
  iVar1 = ((int (*)())FUN_001b2d88)();
  if ((*(byte *)(param_1 + 3) & 4) != 0) {
    iVar1 = iVar1 + 4;
  }
  return iVar1 - param_1 >> 2;
}

/* FUN_001b2f3c @ 0x1b2f3c (125 bytes) */
int FUN_001b2f3c(param_1, param_2)
  int param_1;
  int param_2;
{
  uint *puVar1;
  char cVar2;
  
  cVar2 = *(char *)(param_1 + 2);
  if (cVar2 == '\x01') {
    puVar1 = (uint *)(*(int *)(param_2 + 0x3f4) + 0x30);
    *puVar1 = *puVar1 | 0x2000;
    *(int *)(param_2 + 0x54) = (*(int **)(param_2 + 0x58))[2];
                    
                    
    (**(code **)(**(int **)(param_2 + 0x58) + 8))();
    return;
  }
  if (cVar2 != '\x02') {
    if (cVar2 != '\0') {
      return;
    }
    puVar1 = (uint *)(*(int *)(param_2 + 0x3f4) + 0x30);
    *puVar1 = *puVar1 | 1;
    *(int *)(param_2 + 0x54) = (*(int **)(param_2 + 0x58))[1];
                    
                    
    (**(code **)(**(int **)(param_2 + 0x58) + 0xc))();
    return;
  }
  puVar1 = (uint *)(*(int *)(param_2 + 0x3f4) + 0x30);
  *puVar1 = *puVar1 | 0x4000;
  *(int *)(param_2 + 0x54) = (*(int **)(param_2 + 0x58))[3];
                    
                    
  (**(code **)(**(int **)(param_2 + 0x58) + 0x10))();
  return;
}

/* FUN_001b2fba @ 0x1b2fba (22 bytes) */
int FUN_001b2fba(param_1)
  int param_1;
{
  *(undefined **)(param_1 + 0xc) = &DAT_001f9660;
  return;
}

/* FUN_001b2fd0 @ 0x1b2fd0 (5 bytes) */
int FUN_001b2fd0()
{
  return;
}

/* FUN_001b2fd8 @ 0x1b2fd8 (399 bytes) */
int FUN_001b2fd8(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  undefined *puVar2;
  void *pvVar3;
  
  *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(param_4 + 0x54);
  pvVar3 = (void *)FUN_000e2790(param_4,0x963c,param_3);
  *(void **)(param_1 + 0xac) = pvVar3;
  _memset(pvVar3,0,0x963c);
  iVar1 = *(int *)(*(int *)(param_4 + 0x54) + 0x40);
  *(undefined4 **)(param_1 + 0xa8) = *(undefined4 **)(param_1 + 0xac);
  *(undefined4 *)(param_1 + 0x60) = 1;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x80) = 1;
  *(undefined4 *)(param_1 + 0x84) = 1;
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(int *)(param_1 + 0xc) = param_4;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  *(undefined4 *)(param_1 + 0x14) = param_3;
  *(undefined4 *)(param_1 + 0x94) = 1;
  *(undefined4 *)(param_1 + 0x98) = 1;
  *(undefined4 *)(param_1 + 0xb0) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xb4) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xb8) = 0;
  *(undefined4 *)(param_1 + 0xbc) = 0;
  **(undefined4 **)(param_1 + 0xac) = 0;
  *(int *)(*(int *)(param_1 + 0xa8) + 4) = iVar1 + 1;
  puVar2 = PTR_DAT_00213a35;
  *(undefined4 *)(PTR_DAT_00213a35 + 0x10ac) = 0xc;
  *(undefined4 *)(puVar2 + 0x10e4) = 0xd;
  *(undefined4 *)(puVar2 + 0x22d4) = 0xe;
  *(undefined4 *)(puVar2 + 0x229c) = 0xb;
  *(undefined4 *)(puVar2 + 0x2344) = 0xf;
  *(undefined4 *)(puVar2 + 0x230c) = 0xc;
  *(undefined4 *)(puVar2 + 0x261c) = 5;
  *(undefined4 *)(puVar2 + 0x1a4c) = 6;
  *(undefined4 *)(puVar2 + 0x2654) = 7;
  return;
}

/* FUN_001b3168 @ 0x1b3168 (72 bytes) */
int FUN_001b3168(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  param_2 = param_2 * 0x48;
  *(undefined4 *)(*(int *)(param_1 + 0xa8) + param_2) = 1;
  *(undefined1 *)(param_2 + 10 + *(int *)(param_1 + 0xa8)) = param_3;
  *(undefined1 *)(param_2 + 0xb + *(int *)(param_1 + 0xa8)) = param_4;
  *(undefined2 *)(param_2 + 6 + *(int *)(param_1 + 0xa8)) = param_5;
  return;
}

/* FUN_001b31b0 @ 0x1b31b0 (85 bytes) */
int FUN_001b31b0(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
{
  param_2 = param_2 * 0x48;
  *(undefined4 *)(*(int *)(param_1 + 0xa8) + param_2) = 1;
  *(undefined1 *)(param_2 + 8 + *(int *)(param_1 + 0xa8)) = param_3;
  *(undefined1 *)(param_2 + 9 + *(int *)(param_1 + 0xa8)) = param_4;
  *(undefined2 *)(param_2 + 4 + *(int *)(param_1 + 0xa8)) = param_5;
  *(undefined1 *)(param_2 + 0xc + *(int *)(param_1 + 0xa8)) = param_6;
  return;
}

/* FUN_001b3206 @ 0x1b3206 (50 bytes) */
int FUN_001b3206(param_1)
  int param_1;
{
  _memset((void *)(*(int *)(param_1 + 0xa8) + *(int *)(param_1 + 0x60) * 0x48),0,0x48);
  return;
}

/* FUN_001b3238 @ 0x1b3238 (196 bytes) */
int FUN_001b3238(param_1)
  int param_1;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*(int *)(param_1 + 0xa8) + *(int *)(param_1 + 0x60) * 0x48);
  *puVar1 = 3;
  *(undefined2 *)((int)puVar1 + 0xe) = 0x8000;
  *(undefined2 *)(puVar1 + 4) = 0x8000;
  *(undefined2 *)((int)puVar1 + 0x12) = 0x8000;
  *(undefined2 *)((int)puVar1 + 0x1a) = 0x8000;
  *(undefined2 *)(puVar1 + 7) = 0x8000;
  *(undefined2 *)((int)puVar1 + 0x1e) = 0x8000;
  *(undefined1 *)((int)puVar1 + 0x2a) = 0;
  *(byte *)(puVar1 + 9) = *(byte *)(puVar1 + 9) & 0xc0 | 0x24;
  *(ushort *)(puVar1 + 9) = *(ushort *)(puVar1 + 9) & 0xfe3f | 0x100;
  *(undefined1 *)((int)puVar1 + 0x2b) = 0;
  *(byte *)((int)puVar1 + 0x26) = *(byte *)((int)puVar1 + 0x26) & 0xc0 | 0x24;
  *(ushort *)((int)puVar1 + 0x26) = *(ushort *)((int)puVar1 + 0x26) & 0xfe3f | 0x100;
  *(undefined1 *)(puVar1 + 0xb) = 0;
  *(byte *)(puVar1 + 10) = *(byte *)(puVar1 + 10) & 0xc0 | 0x24;
  *(ushort *)(puVar1 + 10) = *(ushort *)(puVar1 + 10) & 0xfe3f | 0x100;
  *(undefined1 *)((int)puVar1 + 0x31) = 0;
  *(undefined1 *)((int)puVar1 + 0x39) = 0;
  *(undefined1 *)((int)puVar1 + 0x3a) = 0;
  *(undefined1 *)((int)puVar1 + 0x3b) = 0;
  *(undefined1 *)((int)puVar1 + 0x36) = 4;
  *(undefined1 *)((int)puVar1 + 0x37) = 4;
  *(undefined1 *)(puVar1 + 0xe) = 4;
  *(undefined1 *)(puVar1 + 0x10) = 0;
  return;
}

/* FUN_001b32fc @ 0x1b32fc (53 bytes) */
int FUN_001b32fc(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  FUN_001a922a(param_2,*(undefined4 *)(param_1 + 0xac),param_1 + 0x90,param_3,param_1);
  return;
}

/* FUN_001b3332 @ 0x1b3332 (57 bytes) */
int FUN_001b3332(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
  uint param_5;
{
  uint *puVar1;
  
  *(undefined4 *)(param_2 * 4 + param_3) = 3;
  puVar1 = (uint *)(param_2 * 4 + param_4);
  *puVar1 = param_5 & 0xff | *puVar1 | (param_5 >> 8 & 0xff) << 3 | param_5 >> 10 & 0x3fc0;
  return;
}

/* FUN_001b336c @ 0x1b336c (34 bytes) */
int FUN_001b336c(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
  uint param_5;
{
  *(undefined4 *)(param_2 * 4 + param_3) = 3;
  *(uint *)(param_2 * 4 + param_4) = (param_5 >> 0x18) << 9;
  return;
}

/* FUN_001b338e @ 0x1b338e (77 bytes) */
int FUN_001b338e(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  param_2 = param_2 * 4;
  *(undefined4 *)(param_2 + param_3) = param_5;
  if ((char)param_6 == '\x03') {
    *(uint *)(param_2 + param_4) = *(uint *)(param_2 + param_4) | 3;
  }
  if ((char)((uint)param_6 >> 8) == '\x03') {
    *(uint *)(param_2 + param_4) = *(uint *)(param_2 + param_4) | 0x18;
  }
  if ((char)((uint)param_6 >> 0x10) != '\x03') {
    return;
  }
  *(uint *)(param_2 + param_4) = *(uint *)(param_2 + param_4) | 0xc0;
  return;
}

/* FUN_001b33dc @ 0x1b33dc (54 bytes) */
int FUN_001b33dc(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
  undefined4 param_5;
  uint param_6;
{
  uint *puVar1;
  
  *(undefined4 *)(param_2 * 4 + param_3) = param_5;
  puVar1 = (uint *)(param_2 * 4 + param_4);
  *puVar1 = param_6 & 0xff | *puVar1 | (param_6 >> 8 & 0xff) << 3 | param_6 >> 10 & 0x3fc0;
  return;
}

/* FUN_001b3412 @ 0x1b3412 (42 bytes) */
int FUN_001b3412(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  uint *puVar1;
  
  *(undefined4 *)(param_2 * 4 + param_3) = param_5;
  if ((*(unsigned char *)((unsigned char *)&(param_6) + 3)) != 3) {
    puVar1 = (uint *)(param_2 * 4 + param_4);
    *puVar1 = *puVar1 | (uint)(*(unsigned char *)((unsigned char *)&(param_6) + 3)) << 9;
  }
  return;
}

/* FUN_001b343c @ 0x1b343c (38 bytes) */
int FUN_001b343c(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  uint *puVar1;
  
  *(undefined4 *)(param_2 * 4 + param_3) = param_5;
  if ((*(unsigned char *)((unsigned char *)&(param_6) + 3)) != '\x03') {
    return;
  }
  puVar1 = (uint *)(param_2 * 4 + param_4);
  *puVar1 = *puVar1 | 0x600;
  return;
}

/* FUN_001b3462 @ 0x1b3462 (358 bytes) */
int FUN_001b3462(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined2 uVar4;
  
  piVar3 = (int *)(param_3 + 4);
  iVar2 = 1;
LAB_001b3475:
  do {
    iVar1 = iVar2;
    if ((param_2 >> ((byte)iVar1 & 0x1f) & 1U) != 0) {
      uVar4 = (undefined2)*piVar3;
      if ((-1 < *piVar3) && (iVar1 == 1)) {
        *(undefined2 *)(*(int *)(param_1 + 0xa8) + 0xe + *(int *)(param_1 + 0x60) * 0x48) = uVar4;
      }
      if (-1 < *piVar3) {
        if (iVar1 == 2) {
          *(undefined2 *)(*(int *)(param_1 + 0xa8) + 0x10 + *(int *)(param_1 + 0x60) * 0x48) = uVar4
          ;
          piVar3 = piVar3 + 1;
          iVar2 = 3;
          goto LAB_001b3475;
        }
        if (iVar1 == 3) {
          *(undefined2 *)(*(int *)(param_1 + 0xa8) + 0x12 + *(int *)(param_1 + 0x60) * 0x48) = uVar4
          ;
          break;
        }
      }
    }
    piVar3 = piVar3 + 1;
    iVar2 = iVar1 + 1;
  } while (iVar1 + 1 != 4);
  iVar2 = CONCAT31((int3)((uint)(iVar1 + 1) >> 8),1);
  piVar3 = (int *)(param_5 + 4);
LAB_001b34b4:
  do {
    if ((param_4 >> ((byte)iVar2 & 0x1f) & 1U) != 0) {
      uVar4 = (undefined2)*piVar3;
      if ((-1 < *piVar3) && (iVar2 == 1)) {
        *(undefined2 *)(*(int *)(param_1 + 0xa8) + 0x1a + *(int *)(param_1 + 0x60) * 0x48) = uVar4;
      }
      if (-1 < *piVar3) {
        if (iVar2 == 2) {
          *(undefined2 *)(*(int *)(param_1 + 0xa8) + 0x1c + *(int *)(param_1 + 0x60) * 0x48) = uVar4
          ;
          iVar2 = 3;
          piVar3 = piVar3 + 1;
          goto LAB_001b34b4;
        }
        if (iVar2 == 3) {
          *(undefined2 *)(*(int *)(param_1 + 0xa8) + 0x1e + *(int *)(param_1 + 0x60) * 0x48) = uVar4
          ;
          return;
        }
      }
    }
    iVar2 = iVar2 + 1;
    piVar3 = piVar3 + 1;
    if (iVar2 == 4) {
      return;
    }
  } while( true );
}

/* FUN_001b35c8 @ 0x1b35c8 (635 bytes) */
int FUN_001b35c8(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  undefined1 uVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  undefined1 uVar5;
  
  if (param_2 != -1) goto LAB_001b35dd;
  if (param_3 == 0x34) {
LAB_001b36b6:
    iVar3 = *(int *)(param_1 + 0xa8) + *(int *)(param_1 + 0x60) * 0x48;
    *(undefined1 *)(iVar3 + 0x3b) = *(undefined1 *)(iVar3 + 0x3a);
    iVar3 = *(int *)(param_1 + 0xa8) + *(int *)(param_1 + 0x60) * 0x48;
    *(undefined1 *)(iVar3 + 0x3e) = *(undefined1 *)(iVar3 + 0x3d);
    iVar3 = *(int *)(param_1 + 0xa8) + *(int *)(param_1 + 0x60) * 0x48;
    *(undefined1 *)(iVar3 + 0x38) = *(undefined1 *)(iVar3 + 0x37);
    *(undefined1 *)(*(int *)(param_1 + 0xa8) + 0x37 + *(int *)(param_1 + 0x60) * 0x48) = 6;
    *(undefined1 *)(*(int *)(param_1 + 0xa8) + 0x3d + *(int *)(param_1 + 0x60) * 0x48) = 0;
    param_2 = 0;
  }
  else {
    if (param_3 < 0x35) {
      if (param_3 == 0x13) {
LAB_001b3698:
        *(undefined1 *)(*(int *)(param_1 + 0xa8) + 0x38 + *(int *)(param_1 + 0x60) * 0x48) = 4;
        param_2 = 0;
        goto LAB_001b35dd;
      }
      if (param_3 < 0x14) {
        if (param_3 == 0x12) goto LAB_001b36b6;
      }
      else {
        if (param_3 == 0x25) goto LAB_001b3768;
        if (param_3 == 0x31) goto LAB_001b3687;
      }
    }
    else {
      if (param_3 == 0x8b) goto LAB_001b36b6;
      if (param_3 < 0x8c) {
        if (param_3 != 0x36) {
          if (param_3 != 0x66) {
            param_2 = -1;
            goto LAB_001b35dd;
          }
LAB_001b3687:
          *(undefined1 *)(*(int *)(param_1 + 0xa8) + 0x37 + *(int *)(param_1 + 0x60) * 0x48) = 6;
        }
        goto LAB_001b3698;
      }
      if (param_3 == 0x9d) {
LAB_001b3768:
        iVar3 = *(int *)(param_1 + 0xa8) + *(int *)(param_1 + 0x60) * 0x48;
        uVar5 = *(undefined1 *)(iVar3 + 0x39);
        uVar1 = *(undefined1 *)(iVar3 + 0x3c);
        uVar2 = *(undefined1 *)(iVar3 + 0x36);
        *(undefined1 *)(iVar3 + 0x39) = *(undefined1 *)(iVar3 + 0x3a);
        iVar3 = *(int *)(param_1 + 0xa8) + *(int *)(param_1 + 0x60) * 0x48;
        *(undefined1 *)(iVar3 + 0x3c) = *(undefined1 *)(iVar3 + 0x3d);
        iVar3 = *(int *)(param_1 + 0xa8) + *(int *)(param_1 + 0x60) * 0x48;
        *(undefined1 *)(iVar3 + 0x36) = *(undefined1 *)(iVar3 + 0x37);
        iVar3 = *(int *)(param_1 + 0xa8) + *(int *)(param_1 + 0x60) * 0x48;
        *(undefined1 *)(iVar3 + 0x3a) = *(undefined1 *)(iVar3 + 0x3b);
        iVar3 = *(int *)(param_1 + 0xa8) + *(int *)(param_1 + 0x60) * 0x48;
        *(undefined1 *)(iVar3 + 0x3d) = *(undefined1 *)(iVar3 + 0x3e);
        iVar3 = *(int *)(param_1 + 0xa8) + *(int *)(param_1 + 0x60) * 0x48;
        *(undefined1 *)(iVar3 + 0x37) = *(undefined1 *)(iVar3 + 0x38);
        *(undefined1 *)(*(int *)(param_1 + 0xa8) + 0x3b + *(int *)(param_1 + 0x60) * 0x48) = uVar5;
        *(undefined1 *)(*(int *)(param_1 + 0xa8) + 0x3e + *(int *)(param_1 + 0x60) * 0x48) = uVar1;
        *(undefined1 *)(*(int *)(param_1 + 0xa8) + 0x38 + *(int *)(param_1 + 0x60) * 0x48) = uVar2;
        param_2 = (param_3 != 0x9d) + 5;
        goto LAB_001b35dd;
      }
      if (param_3 == 0xb4) {
        *(undefined1 *)(*(int *)(param_1 + 0xa8) + 0x36 + *(int *)(param_1 + 0x60) * 0x48) = 4;
        *(undefined1 *)(*(int *)(param_1 + 0xa8) + 0x37 + *(int *)(param_1 + 0x60) * 0x48) = 4;
        param_2 = 0;
        goto LAB_001b35dd;
      }
    }
    param_2 = -1;
  }
LAB_001b35dd:
  *(char *)(*(int *)(param_1 + 0xa8) + 0x40 + *(int *)(param_1 + 0x60) * 0x48) = (char)param_2;
  if (*(char *)(param_4 + 0x120) != '\0') {
    *(undefined1 *)(*(int *)(param_1 + 0xa8) + 0x42 + *(int *)(param_1 + 0x60) * 0x48) = 1;
  }
  iVar3 = *(int *)(param_1 + 0x60);
  iVar4 = *(int *)(param_1 + 0xa8);
  uVar5 = FUN_001a8fe0(*(undefined4 *)(param_4 + 0x124));
  *(undefined1 *)(iVar4 + iVar3 * 0x48 + 0x41) = uVar5;
  return;
}

/* FUN_001b3844 @ 0x1b3844 (35 bytes) */
int FUN_001b3844(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 0x74) + 1 < *(int *)(param_1 + 0x60)) {
    *(undefined1 *)(*(int *)(param_1 + 0xa8) + 0xb + *(int *)(param_1 + 0x60) * 0x48) = 1;
  }
  return;
}

/* FUN_001b3868 @ 0x1b3868 (165 bytes) */
int FUN_001b3868(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  
  *(undefined2 *)(*(int *)(param_1 + 0xa8) + 0x24) = param_2;
  iVar1 = *(int *)(param_1 + 0xa8);
  *(int *)(iVar1 + 8) = *(int *)(param_1 + 0x60) + -1;
  *(char *)(iVar1 + 0xe) = (char)*(undefined4 *)(param_1 + 0x9c);
  *(undefined1 *)(iVar1 + 0xc) = 0;
  *(undefined1 *)(iVar1 + 0xd) = 6;
  *(undefined1 *)(iVar1 + 0xf) = 0;
  *(undefined2 *)(iVar1 + 0x10) = 0;
  *(short *)(iVar1 + 0x12) =
       ((short)*(undefined4 *)(param_1 + 0x60) - *(short *)(param_1 + 0x74)) + -2;
  *(undefined2 *)(iVar1 + 0x14) = 1;
  *(undefined2 *)(iVar1 + 0x16) = 1;
  *(short *)(iVar1 + 0x18) = (short)*(undefined4 *)(param_1 + 0x74);
  *(short *)(iVar1 + 0x1a) = (short)*(undefined4 *)(param_1 + 0x68);
  *(short *)(iVar1 + 0x1c) = (short)*(undefined4 *)(param_1 + 100);
  *(short *)(iVar1 + 0x1e) = (short)*(undefined4 *)(param_1 + 100);
  *(short *)(iVar1 + 0x20) =
       ((((short)*(undefined4 *)(param_1 + 0x60) - *(short *)(param_1 + 100)) -
        *(short *)(param_1 + 0x68)) - *(short *)(param_1 + 0x74)) + -1;
  *(undefined2 *)(iVar1 + 0x22) = param_3;
  *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + -0x3e) = 1;
  return;
}

/* FUN_001b390e @ 0x1b390e (42 bytes) */
int FUN_001b390e(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x60) * 0x48;
  if (-1 < iVar1) {
    *param_2 = iVar1 >> 2;
    return;
  }
  *param_2 = iVar1 + 3 >> 2;
  return;
}

/* FUN_001b3938 @ 0x1b3938 (166 bytes) */
int FUN_001b3938(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  *(undefined4 *)(param_1[0x2a] + param_1[0x18] * 0x48) = 5;
  *(undefined1 *)(param_1[0x2a] + 0xe + param_1[0x18] * 0x48) = 0;
  if (param_2 == '\0') {
    *(undefined1 *)(param_1[0x2a] + 0x12 + param_1[0x18] * 0x48) = 0x55;
  }
  else {
    *(undefined1 *)(param_1[0x2a] + 0x12 + param_1[0x18] * 0x48) = 0xaa;
  }
  *(undefined1 *)(param_1[0x2a] + 0x14 + param_1[0x18] * 0x48) = 0;
  *(undefined1 *)(param_1[0x2a] + 0x15 + param_1[0x18] * 0x48) = 0;
  *(undefined1 *)(param_1[0x2a] + 0x17 + param_1[0x18] * 0x48) = param_3;
  (**(code **)(*param_1 + 0x15c))(param_1);
  return param_1[0x18] + -1;
}

/* FUN_001b39de @ 0x1b39de (25 bytes) */
int FUN_001b39de(param_1)
  int param_1;
{
  *(undefined1 *)(*(int *)(param_1 + 0xa8) + 9 + *(int *)(param_1 + 0x60) * 0x48) = 1;
  return;
}

/* FUN_001b39f8 @ 0x1b39f8 (147 bytes) */
int FUN_001b39f8(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint *param_3;
{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint local_24;
  int local_20 [4];
  
  if (*(int *)(param_2 + 300) == 3) {
    iVar2 = 0;
    iVar3 = param_2;
    do {
      if ((((int)*(char *)(param_2 + 0x15c) >> ((byte)iVar2 & 0x1f) & 1U) != 0) &&
         (*(int *)(iVar3 + 0x1c) == 2)) {
        uVar4 = *(undefined4 *)(param_2 + 0x20 + iVar2 * 0x18);
        goto LAB_001b3a3d;
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x18;
    } while (iVar2 != 4);
    uVar4 = 0;
LAB_001b3a3d:
    cVar1 = ((undefined4 (*)())FUN_001a5162)(*(undefined4 *)(param_1 + 0xa4),uVar4,local_20,&local_24);
    if (cVar1 != '\0') {
      *param_3 = local_20[0] << 3 | local_24 | 0x2000;
      return 1;
    }
  }
  return 0;
}

/* FUN_001b3a8c @ 0x1b3a8c (242 bytes) */
int FUN_001b3a8c(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
  uint param_5;
{
  uint *puVar1;
  float fVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  if (1 < *(int *)(param_4 + 0x84)) {
    puVar1 = (uint *)(param_3 + param_2 * 4);
    iVar7 = 2;
    do {
      piVar4 = (int *)FUN_0010b180(param_4,iVar7);
      if (piVar4 != (int *)0x0) {
        cVar3 = (**(code **)(*piVar4 + 0x48))(piVar4);
        if ((cVar3 != '\0') && ((byte)(param_5 >> 0x18) < 4)) {
          iVar5 = FUN_0010b0f4(param_4,iVar7);
          uVar6 = (uint)*(byte *)((param_5 >> 0x18) + 0x10 + iVar5);
          if (uVar6 < 4) {
            fVar2 = (float)piVar4[uVar6 * 6 + 8];
            uVar6 = *puVar1 & 0xfffff1ff;
            *puVar1 = uVar6;
            if ((fVar2 != FLOAT_001c5b9c) || (NAN(fVar2) || NAN(FLOAT_001c5b9c))) {
              if ((fVar2 != FLOAT_001c5bd4) || (NAN(fVar2) || NAN(FLOAT_001c5bd4))) {
                if ((fVar2 == FLOAT_001c5ba4) && (!NAN(fVar2) && !NAN(FLOAT_001c5ba4))) {
                  *puVar1 = uVar6 | 0xc00;
                }
              }
              else {
                *puVar1 = uVar6 | 0xa00;
              }
            }
            else {
              *puVar1 = uVar6 | 0x800;
            }
          }
        }
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 <= *(int *)(param_4 + 0x84));
  }
  return;
}

/* FUN_001b3b7e @ 0x1b3b7e (298 bytes) */
int FUN_001b3b7e(param_1)
  int *param_1;
{
  void *pvVar1;
  
  if (param_1[0x1d] == 0) {
    pvVar1 = (void *)(param_1[0x18] * 0x48 + param_1[0x2a]);
    _memcpy((void *)((int)pvVar1 + 0x48),pvVar1,0x48);
    _memset((void *)(param_1[0x2a] + param_1[0x18] * 0x48),0,0x48);
    param_1[0x1d] = 1;
    param_1[0x18] = 2;
    (**(code **)(*param_1 + 0xc4))(param_1,1,0,0,0,0);
    (**(code **)(*param_1 + 200))(param_1,1,0,0,0,0);
    (**(code **)(*param_1 + 0xcc))(param_1,1,0xf);
    (**(code **)(*param_1 + 0xd0))(param_1,1,0xf);
  }
  param_1[0x18] = param_1[0x18] + 1;
  param_1[0x20] = 1;
  param_1[0x21] = 1;
  return;
}

/* FUN_001b3ca8 @ 0x1b3ca8 (11 bytes) */
int FUN_001b3ca8(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  return *(undefined4 *)(param_2 + 4);
}

/* FUN_001b3cb4 @ 0x1b3cb4 (264 bytes) */
int FUN_001b3cb4(param_1)
  int *param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  *(int *)(param_1[0x2b] + 0x93b8) = param_1[0x24];
  *(int *)(param_1[0x2b] + 0x9364) = *(int *)(*(int *)(param_1[3] + 0x3f4) + 0x7c) + 1;
  *(undefined4 *)(param_1[0x2b] + 0x9368) = *(undefined4 *)(*(int *)(param_1[3] + 0x3f4) + 0x84);
  iVar3 = FUN_00137d0a(*(undefined4 *)(param_1[3] + 0x3f4),0);
  if (iVar3 == 0) {
    iVar3 = 0;
    iVar1 = param_1[0x18];
    iVar2 = *(int *)(iVar1 * 0x48 + param_1[0x2a] + -0x48);
  }
  else {
    iVar3 = iVar3 + -1;
    iVar1 = param_1[0x18];
    iVar2 = *(int *)(iVar1 * 0x48 + param_1[0x2a] + -0x48);
  }
  if ((iVar2 == 3) && (param_1[0x2d] != (iVar1 - param_1[0x1d]) + -1)) {
    (**(code **)(*param_1 + 0x144))(param_1,param_1[0x1e],iVar3);
    return;
  }
  (**(code **)(*param_1 + 0xbc))(param_1);
  (**(code **)(*param_1 + 0xc0))(param_1);
  (**(code **)(*param_1 + 0x15c))(param_1);
  (**(code **)(*param_1 + 0x144))(param_1,param_1[0x1e],iVar3);
  return;
}

/* FUN_001b3dbc @ 0x1b3dbc (305 bytes) */
int FUN_001b3dbc(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  if (param_2 != 2) {
    if (param_2 != 3) {
      return;
    }
    *(undefined1 *)(*(int *)(param_1 + 0xa8) + 6 + *(int *)(param_1 + 0x60) * 0x48) = 1;
    *(undefined1 *)(*(int *)(param_1 + 0xa8) + 8 + *(int *)(param_1 + 0x60) * 0x48) = 1;
  }
  if (param_3 == DAT_001cf324) {
    *(undefined1 *)(*(int *)(param_1 + 0xa8) + 5 + *(int *)(param_1 + 0x60) * 0x48) = 1;
    *(undefined1 *)(*(int *)(param_1 + 0xa8) + 7 + *(int *)(param_1 + 0x60) * 0x48) = 5;
    return;
  }
  if (param_3 == DAT_001cf320) {
    *(undefined1 *)(*(int *)(param_1 + 0xa8) + 5 + *(int *)(param_1 + 0x60) * 0x48) = 2;
    *(undefined1 *)(*(int *)(param_1 + 0xa8) + 7 + *(int *)(param_1 + 0x60) * 0x48) = 2;
    return;
  }
  if (param_3 != DAT_001cf31c) {
    if (param_3 == DAT_001cf318) {
      *(undefined1 *)(*(int *)(param_1 + 0xa8) + 5 + *(int *)(param_1 + 0x60) * 0x48) = 4;
      *(undefined1 *)(*(int *)(param_1 + 0xa8) + 7 + *(int *)(param_1 + 0x60) * 0x48) = 4;
      return;
    }
    if (param_3 != DAT_001cf314) {
      return;
    }
    *(undefined1 *)(*(int *)(param_1 + 0xa8) + 5 + *(int *)(param_1 + 0x60) * 0x48) = 5;
    *(undefined1 *)(*(int *)(param_1 + 0xa8) + 7 + *(int *)(param_1 + 0x60) * 0x48) = 5;
    return;
  }
  *(undefined1 *)(*(int *)(param_1 + 0xa8) + 5 + *(int *)(param_1 + 0x60) * 0x48) = 3;
  *(undefined1 *)(*(int *)(param_1 + 0xa8) + 7 + *(int *)(param_1 + 0x60) * 0x48) = 3;
  return;
}

/* FUN_001b3eee @ 0x1b3eee (133 bytes) */
int FUN_001b3eee(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 param_3;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar1 = param_1[0x18];
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined1 *)(param_2 + 0xdc));
  if ((*(char *)(param_2 + 0xdc) != '\0') && (iVar1 == param_1[0x18])) {
    uVar3 = 1;
    iVar4 = 0;
    iVar1 = *(int *)(param_2 + 0xd0);
    if (*(int *)(iVar1 + 4) != 0) {
      do {
        iVar2 = *(int *)(iVar4 + *(int *)(iVar1 + 8));
        if (iVar2 != 0) {
          *(undefined1 *)(iVar2 + 0xdc) = 1;
        }
        uVar3 = uVar3 + 1;
        iVar4 = iVar4 + 4;
      } while (uVar3 <= *(uint *)(iVar1 + 4));
      return;
    }
  }
  return;
}

/* FUN_001b3f74 @ 0x1b3f74 (190 bytes) */
int FUN_001b3f74(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 param_3;
{
  undefined1 uVar1;
  int iVar2;
  code *pcVar3;
  bool bVar4;
  undefined4 uVar5;
  
  iVar2 = param_1[0x18];
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined1 *)(param_2 + 0xdc));
  if ((*(char *)(param_2 + 0xdc) == '\0') || (iVar2 != param_1[0x18])) {
    bVar4 = false;
  }
  else {
    bVar4 = true;
  }
  pcVar3 = *(code **)(*param_1 + 0x9c);
  uVar1 = *(undefined1 *)(param_2 + 300);
  uVar5 = FUN_000e9a1c(param_2);
  (*pcVar3)(param_1,uVar5,uVar1);
  if (bVar4) {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + -0x44) = 1;
  }
  if (*(char *)(param_2 + 300) != '\0') {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + -0x3a) = 3;
  }
  return;
}

/* FUN_001b4032 @ 0x1b4032 (1400 bytes) */
int FUN_001b4032(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  undefined1 uVar1;
  byte bVar2;
  undefined1 uVar3;
  ushort uVar4;
  int iVar5;
  undefined1 uVar6;
  int iVar7;
  undefined4 local_18;
  
  if (param_2 != -1) goto LAB_001b4047;
  if (param_3 == 0x34) {
LAB_001b41ca:
    iVar7 = *(int *)(param_1 + 0xa8) + *(int *)(param_1 + 0x60) * 0x48;
    *(undefined1 *)(iVar7 + 0x2c) = *(undefined1 *)(iVar7 + 0x2b);
    iVar7 = *(int *)(param_1 + 0xa8) + *(int *)(param_1 + 0x60) * 0x48;
    *(undefined1 *)(iVar7 + 0x2f) = *(undefined1 *)(iVar7 + 0x2e);
    iVar7 = *(int *)(param_1 + 0xa8) + *(int *)(param_1 + 0x60) * 0x48;
    *(byte *)(iVar7 + 0x28) = *(byte *)(iVar7 + 0x28) & 0xf8 | *(byte *)(iVar7 + 0x26) & 7;
    iVar7 = *(int *)(param_1 + 0xa8) + *(int *)(param_1 + 0x60) * 0x48;
    *(byte *)(iVar7 + 0x28) = *(byte *)(iVar7 + 0x28) & 199 | *(byte *)(iVar7 + 0x26) & 0x38;
    iVar7 = *(int *)(param_1 + 0xa8) + *(int *)(param_1 + 0x60) * 0x48;
    *(ushort *)(iVar7 + 0x28) =
         *(ushort *)(iVar7 + 0x28) & 0xfe3f | *(ushort *)(iVar7 + 0x26) & 0x1c0;
    iVar7 = *(int *)(param_1 + 0x60) * 0x48;
    *(byte *)(iVar7 + 0x26 + *(int *)(param_1 + 0xa8)) =
         *(byte *)(iVar7 + 0x26 + *(int *)(param_1 + 0xa8)) & 0xf8 | 6;
    iVar7 = *(int *)(param_1 + 0x60) * 0x48;
    *(byte *)(iVar7 + 0x26 + *(int *)(param_1 + 0xa8)) =
         *(byte *)(iVar7 + 0x26 + *(int *)(param_1 + 0xa8)) & 199 | 0x30;
    iVar7 = *(int *)(param_1 + 0x60) * 0x48;
    *(ushort *)(iVar7 + 0x26 + *(int *)(param_1 + 0xa8)) =
         *(ushort *)(iVar7 + 0x26 + *(int *)(param_1 + 0xa8)) & 0xfe3f | 0x180;
    *(undefined1 *)(*(int *)(param_1 + 0xa8) + 0x2e + *(int *)(param_1 + 0x60) * 0x48) = 0;
    param_2 = 0;
  }
  else {
    if (param_3 < 0x35) {
      if (param_3 == 0x13) {
LAB_001b415c:
        iVar7 = *(int *)(param_1 + 0x60) * 0x48;
        *(byte *)(iVar7 + 0x28 + *(int *)(param_1 + 0xa8)) =
             *(byte *)(iVar7 + 0x28 + *(int *)(param_1 + 0xa8)) & 0xf8 | 4;
        iVar7 = *(int *)(param_1 + 0x60) * 0x48;
        *(byte *)(iVar7 + 0x28 + *(int *)(param_1 + 0xa8)) =
             *(byte *)(iVar7 + 0x28 + *(int *)(param_1 + 0xa8)) & 199 | 0x20;
        iVar7 = *(int *)(param_1 + 0x60) * 0x48;
        *(ushort *)(iVar7 + 0x28 + *(int *)(param_1 + 0xa8)) =
             *(ushort *)(iVar7 + 0x28 + *(int *)(param_1 + 0xa8)) & 0xfe3f | 0x100;
        param_2 = 0;
        goto LAB_001b4047;
      }
      if (param_3 < 0x14) {
        if (param_3 == 0x12) goto LAB_001b41ca;
      }
      else {
        if (param_3 == 0x25) goto LAB_001b43c0;
        if (param_3 == 0x31) goto LAB_001b40fd;
      }
    }
    else {
      if (param_3 == 0x8b) goto LAB_001b41ca;
      if (param_3 < 0x8c) {
        if (param_3 != 0x36) {
          if (param_3 != 0x66) {
            param_2 = -1;
            goto LAB_001b4047;
          }
LAB_001b40fd:
          iVar7 = *(int *)(param_1 + 0x60) * 0x48;
          *(byte *)(iVar7 + 0x26 + *(int *)(param_1 + 0xa8)) =
               *(byte *)(iVar7 + 0x26 + *(int *)(param_1 + 0xa8)) & 0xf8 | 6;
          iVar7 = *(int *)(param_1 + 0x60) * 0x48;
          *(byte *)(iVar7 + 0x26 + *(int *)(param_1 + 0xa8)) =
               *(byte *)(iVar7 + 0x26 + *(int *)(param_1 + 0xa8)) & 199 | 0x30;
          iVar7 = *(int *)(param_1 + 0x60) * 0x48;
          *(ushort *)(iVar7 + 0x26 + *(int *)(param_1 + 0xa8)) =
               *(ushort *)(iVar7 + 0x26 + *(int *)(param_1 + 0xa8)) & 0xfe3f | 0x180;
        }
        goto LAB_001b415c;
      }
      if (param_3 == 0x9d) {
LAB_001b43c0:
        iVar7 = *(int *)(param_1 + 0xa8) + *(int *)(param_1 + 0x60) * 0x48;
        uVar6 = *(undefined1 *)(iVar7 + 0x2a);
        uVar1 = *(undefined1 *)(iVar7 + 0x2d);
        bVar2 = *(byte *)(iVar7 + 0x24);
        uVar3 = *(undefined1 *)(iVar7 + 0x24);
        uVar4 = *(ushort *)(iVar7 + 0x24);
        *(undefined1 *)(iVar7 + 0x2a) = *(undefined1 *)(iVar7 + 0x2b);
        iVar7 = *(int *)(param_1 + 0xa8) + *(int *)(param_1 + 0x60) * 0x48;
        *(undefined1 *)(iVar7 + 0x2d) = *(undefined1 *)(iVar7 + 0x2e);
        iVar7 = *(int *)(param_1 + 0xa8) + *(int *)(param_1 + 0x60) * 0x48;
        *(byte *)(iVar7 + 0x24) = *(byte *)(iVar7 + 0x24) & 199 | *(byte *)(iVar7 + 0x26) & 0x38;
        iVar7 = *(int *)(param_1 + 0xa8) + *(int *)(param_1 + 0x60) * 0x48;
        *(ushort *)(iVar7 + 0x24) =
             *(ushort *)(iVar7 + 0x24) & 0xfe3f | *(ushort *)(iVar7 + 0x26) & 0x1c0;
        iVar7 = *(int *)(param_1 + 0xa8) + *(int *)(param_1 + 0x60) * 0x48;
        *(byte *)(iVar7 + 0x24) = *(byte *)(iVar7 + 0x24) & 0xf8 | *(byte *)(iVar7 + 0x26) & 7;
        iVar7 = *(int *)(param_1 + 0xa8) + *(int *)(param_1 + 0x60) * 0x48;
        *(undefined1 *)(iVar7 + 0x2b) = *(undefined1 *)(iVar7 + 0x2c);
        iVar7 = *(int *)(param_1 + 0xa8) + *(int *)(param_1 + 0x60) * 0x48;
        *(undefined1 *)(iVar7 + 0x2e) = *(undefined1 *)(iVar7 + 0x2f);
        iVar7 = *(int *)(param_1 + 0xa8) + *(int *)(param_1 + 0x60) * 0x48;
        *(byte *)(iVar7 + 0x26) = *(byte *)(iVar7 + 0x26) & 0xf8 | *(byte *)(iVar7 + 0x28) & 7;
        iVar7 = *(int *)(param_1 + 0xa8) + *(int *)(param_1 + 0x60) * 0x48;
        *(byte *)(iVar7 + 0x26) = *(byte *)(iVar7 + 0x26) & 199 | *(byte *)(iVar7 + 0x28) & 0x38;
        iVar7 = *(int *)(param_1 + 0xa8) + *(int *)(param_1 + 0x60) * 0x48;
        *(ushort *)(iVar7 + 0x26) =
             *(ushort *)(iVar7 + 0x26) & 0xfe3f | *(ushort *)(iVar7 + 0x28) & 0x1c0;
        *(undefined1 *)(*(int *)(param_1 + 0xa8) + 0x2c + *(int *)(param_1 + 0x60) * 0x48) = uVar6;
        *(undefined1 *)(*(int *)(param_1 + 0xa8) + 0x2f + *(int *)(param_1 + 0x60) * 0x48) = uVar1;
        iVar7 = *(int *)(param_1 + 0x60) * 0x48;
        *(byte *)(iVar7 + 0x28 + *(int *)(param_1 + 0xa8)) =
             *(byte *)(iVar7 + 0x28 + *(int *)(param_1 + 0xa8)) & 0xf8 | bVar2 & 7;
        iVar7 = *(int *)(param_1 + 0x60) * 0x48;
        (*(unsigned int *)((unsigned char *)&(local_18) + 0)) = (uint3)uVar4;
        local_18 = CONCAT13(uVar3,(uint3)local_18) & 0x38ffffff;
        *(byte *)(iVar7 + 0x28 + *(int *)(param_1 + 0xa8)) =
             *(byte *)(iVar7 + 0x28 + *(int *)(param_1 + 0xa8)) & 199 | (*(unsigned char *)((unsigned char *)&(local_18) + 3));
        iVar7 = *(int *)(param_1 + 0x60) * 0x48;
        *(ushort *)(iVar7 + 0x28 + *(int *)(param_1 + 0xa8)) =
             *(ushort *)(iVar7 + 0x28 + *(int *)(param_1 + 0xa8)) & 0xfe3f |
             (ushort)local_18 & 0x1c0;
        param_2 = (param_3 != 0x9d) + 7;
        goto LAB_001b4047;
      }
      if (param_3 == 0xb4) {
        *(undefined4 *)(param_1 + 0x9c) = 1;
        iVar7 = *(int *)(param_1 + 0x60) * 0x48;
        *(ushort *)(iVar7 + 0x24 + *(int *)(param_1 + 0xa8)) =
             *(ushort *)(iVar7 + 0x24 + *(int *)(param_1 + 0xa8)) & 0xfe3f | 0x180;
        iVar7 = *(int *)(param_1 + 0x60) * 0x48;
        *(byte *)(iVar7 + 0x26 + *(int *)(param_1 + 0xa8)) =
             *(byte *)(iVar7 + 0x26 + *(int *)(param_1 + 0xa8)) & 0xf8 | 6;
        iVar7 = *(int *)(param_1 + 0x60) * 0x48;
        *(byte *)(iVar7 + 0x26 + *(int *)(param_1 + 0xa8)) =
             *(byte *)(iVar7 + 0x26 + *(int *)(param_1 + 0xa8)) & 199 | 0x30;
        iVar7 = *(int *)(param_1 + 0x60) * 0x48;
        *(byte *)(iVar7 + 0x28 + *(int *)(param_1 + 0xa8)) =
             *(byte *)(iVar7 + 0x28 + *(int *)(param_1 + 0xa8)) & 0xf8 | 4;
        iVar7 = *(int *)(param_1 + 0x60) * 0x48;
        *(ushort *)(iVar7 + 0x28 + *(int *)(param_1 + 0xa8)) =
             *(ushort *)(iVar7 + 0x28 + *(int *)(param_1 + 0xa8)) & 0xfe3f | 0x100;
        iVar7 = *(int *)(param_1 + 0x60) * 0x48;
        *(byte *)(iVar7 + 0x28 + *(int *)(param_1 + 0xa8)) =
             *(byte *)(iVar7 + 0x28 + *(int *)(param_1 + 0xa8)) & 199 | 0x20;
        param_2 = 0;
        goto LAB_001b4047;
      }
    }
    param_2 = -1;
  }
LAB_001b4047:
  *(char *)(*(int *)(param_1 + 0xa8) + 0x31 + *(int *)(param_1 + 0x60) * 0x48) = (char)param_2;
  if (*(char *)(param_4 + 0x120) != '\0') {
    *(undefined1 *)(*(int *)(param_1 + 0xa8) + 0x33 + *(int *)(param_1 + 0x60) * 0x48) = 1;
  }
  iVar7 = *(int *)(param_1 + 0x60);
  iVar5 = *(int *)(param_1 + 0xa8);
  uVar6 = FUN_001a8fe0(*(undefined4 *)(param_4 + 0x124));
  *(undefined1 *)(iVar5 + iVar7 * 0x48 + 0x32) = uVar6;
  return;
}

/* FUN_001b45aa @ 0x1b45aa (178 bytes) */
int FUN_001b45aa(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  char cVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  
  piVar2 = (int *)FUN_0010b180(param_2,param_3);
  if (piVar2[0x20] != 0) {
    cVar1 = FUN_0012dfd8(piVar2[0x26]);
    if ((cVar1 != '\0') && ((*(byte *)(piVar2 + 5) & 2) == 0)) {
      cVar1 = (**(code **)(*piVar2 + 0x50))(piVar2);
      if (cVar1 == '\0') goto LAB_001b461d;
    }
  }
  cVar1 = (**(code **)(*piVar2 + 0x50))(piVar2);
  if (cVar1 == '\0') {
    if (piVar2[0x26] == 0x29) {
      iVar3 = FUN_0010b6e4(param_2,param_3);
      uVar4 = iVar3 + *(int *)(*(int *)(param_4 + 0x3f4) + 0x3e4) | 0x4000;
    }
    else {
      uVar4 = 0;
    }
    return uVar4;
  }
LAB_001b461d:
  uVar4 = FUN_0013c4e0();
  return uVar4;
}

/* FUN_001b465c @ 0x1b465c (208 bytes) */
int FUN_001b465c(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
  undefined4 param_5;
{
  uint *puVar1;
  float fVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  undefined4 local_20;
  
  iVar4 = FUN_0010b180(param_5,param_2);
  puVar1 = (uint *)(param_4 + param_2 * 4);
  local_20 = 0;
  bVar6 = 0;
  do {
    iVar5 = FUN_0010b0f4(param_5,param_2);
    bVar3 = *(byte *)(local_20 + 0x10 + iVar5);
    if (bVar3 < 4) {
      fVar2 = *(float *)(iVar4 + 0x20 + (uint)bVar3 * 0x18);
      if ((fVar2 != FLOAT_001c5b9c) || (NAN(fVar2) || NAN(FLOAT_001c5b9c))) {
        if ((fVar2 != FLOAT_001c5bd4) || (NAN(fVar2) || NAN(FLOAT_001c5bd4))) {
          if ((fVar2 == FLOAT_001c5ba4) && (!NAN(fVar2) && !NAN(FLOAT_001c5ba4))) {
            *puVar1 = *puVar1 | 6 << (bVar6 & 0x1f);
          }
        }
        else {
          *puVar1 = *puVar1 | 5 << (bVar6 & 0x1f);
        }
      }
      else {
LAB_001b46ca:
        *puVar1 = *puVar1 | 4 << (bVar6 & 0x1f);
      }
    }
    else {
      if (bVar3 != 6) goto LAB_001b46ca;
      *puVar1 = *puVar1 | 6 << (bVar6 & 0x1f);
    }
    local_20 = local_20 + 1;
    bVar6 = bVar6 + 3;
    if (local_20 == 3) {
      return;
    }
  } while( true );
}

/* FUN_001b472c @ 0x1b472c (197 bytes) */
int FUN_001b472c(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
  undefined4 param_5;
{
  int iVar1;
  float fVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = FUN_0010b180(param_5,param_2);
  iVar1 = param_2 * 4;
  *(undefined4 *)(iVar1 + param_3) = 0;
  iVar5 = FUN_0010b0f4(param_5,param_2);
  bVar3 = *(byte *)(iVar5 + 0x13);
  if (bVar3 < 4) {
    fVar2 = *(float *)(iVar4 + 0x20 + (uint)bVar3 * 0x18);
    if ((fVar2 != FLOAT_001c5b9c) || (NAN(fVar2) || NAN(FLOAT_001c5b9c))) {
      if ((fVar2 == FLOAT_001c5bd4) && (!NAN(fVar2) && !NAN(FLOAT_001c5bd4))) {
        *(uint *)(iVar1 + param_4) = *(uint *)(iVar1 + param_4) | 0xa00;
        return;
      }
      if (fVar2 != FLOAT_001c5ba4) {
        return;
      }
      if (NAN(fVar2) || NAN(FLOAT_001c5ba4)) {
        return;
      }
      *(uint *)(iVar1 + param_4) = *(uint *)(iVar1 + param_4) | 0xc00;
      return;
    }
  }
  else if (bVar3 == 6) {
    *(uint *)(iVar1 + param_4) = *(uint *)(iVar1 + param_4) | 0xc00;
    return;
  }
  *(uint *)(iVar1 + param_4) = *(uint *)(iVar1 + param_4) | 0x800;
  return;
}

/* FUN_001b47f2 @ 0x1b47f2 (348 bytes) */
int FUN_001b47f2(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
{
  uint *puVar1;
  float fVar2;
  byte bVar3;
  char cVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  int local_28;
  byte *local_24;
  int local_20;
  
  if (*(int *)(param_4 + 0x84) < 2) {
    return;
  }
  puVar1 = (uint *)(param_3 + param_2 * 4);
  local_28 = 2;
  do {
    piVar5 = (int *)FUN_0010b180(param_4,local_28);
    if (piVar5 != (int *)0x0) {
      cVar4 = (**(code **)(*piVar5 + 0x48))(piVar5);
      if (cVar4 != '\0') {
        local_24 = &STACKARG(0x14);
        local_20 = 0;
        do {
          bVar3 = *local_24;
          if (bVar3 < 4) {
            iVar6 = FUN_0010b0f4(param_4,local_28);
            uVar7 = (uint)*(byte *)(bVar3 + 0x10 + iVar6);
            if (uVar7 < 4) {
              fVar2 = (float)piVar5[uVar7 * 6 + 8];
              if ((fVar2 != FLOAT_001c5b9c) || (NAN(fVar2) || NAN(FLOAT_001c5b9c))) {
                if ((fVar2 != FLOAT_001c5bd4) || (NAN(fVar2) || NAN(FLOAT_001c5bd4))) {
                  if ((fVar2 == FLOAT_001c5ba4) && (!NAN(fVar2) && !NAN(FLOAT_001c5ba4))) {
                    *puVar1 = ~(7 << ((byte)local_20 & 0x1f)) & *puVar1 |
                              6 << ((byte)local_20 & 0x1f);
                  }
                }
                else {
                  *puVar1 = ~(7 << ((byte)local_20 & 0x1f)) & *puVar1 | 5 << ((byte)local_20 & 0x1f)
                  ;
                }
              }
              else {
                *puVar1 = ~(7 << ((byte)local_20 & 0x1f)) & *puVar1 | 4 << ((byte)local_20 & 0x1f);
              }
            }
          }
          local_24 = local_24 + 1;
          local_20 = local_20 + 3;
        } while (local_20 != 9);
      }
    }
    local_28 = local_28 + 1;
  } while (local_28 <= *(int *)(param_4 + 0x84));
  return;
}

/* FUN_001b494e @ 0x1b494e (1168 bytes) */
int FUN_001b494e(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int *param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
  int param_7;
  int param_8;
{
  byte *pbVar1;
  undefined1 uVar2;
  int iVar3;
  int local_18;
  int local_14;
  
  local_18 = (**(code **)(*param_2 + 0x14))(param_2);
  if (*(int *)(param_2[0x22] + 8) == 0xb4) {
    local_18 = 3;
  }
  else if (local_18 < 1) {
    return;
  }
  do {
    if (param_3 != 0) {
      *(char *)(*(int *)(param_1 + 0xa8) + 0x2a + *(int *)(param_1 + 0x60) * 0x48) =
           (char)*(undefined4 *)(param_4 + 4);
      iVar3 = *(int *)(param_1 + 0x60) * 0x48;
      *(byte *)(iVar3 + 0x24 + *(int *)(param_1 + 0xa8)) =
           *(byte *)(iVar3 + 0x24 + *(int *)(param_1 + 0xa8)) & 0xf8 | *(byte *)(param_5 + 4) & 7;
      iVar3 = *(int *)(param_1 + 0x60) * 0x48;
      *(byte *)(iVar3 + 0x24 + *(int *)(param_1 + 0xa8)) =
           *(byte *)(iVar3 + 0x24 + *(int *)(param_1 + 0xa8)) & 199 |
           ((byte)(*(int *)(param_5 + 4) >> 3) & 7) << 3;
      iVar3 = *(int *)(param_1 + 0x60) * 0x48;
      *(ushort *)(iVar3 + 0x24 + *(int *)(param_1 + 0xa8)) =
           *(ushort *)(iVar3 + 0x24 + *(int *)(param_1 + 0xa8)) & 0xfe3f |
           (ushort)((*(int *)(param_5 + 4) >> 6 & 7U) << 6);
    }
    if (param_6 != 0) {
      *(char *)(*(int *)(param_1 + 0xa8) + 0x39 + *(int *)(param_1 + 0x60) * 0x48) =
           (char)*(undefined4 *)(param_7 + 4);
      *(byte *)(*(int *)(param_1 + 0xa8) + 0x36 + *(int *)(param_1 + 0x60) * 0x48) =
           (byte)(*(int *)(param_8 + 4) >> 9) & 7;
    }
    local_14 = 1;
    while( true ) {
      pbVar1 = (byte *)(*(int *)(param_1 + 0xa8) + 0x2a + *(int *)(param_1 + 0x60) * 0x48);
      *pbVar1 = *pbVar1 | 0x80;
      pbVar1 = (byte *)(*(int *)(param_1 + 0xa8) + 0x39 + *(int *)(param_1 + 0x60) * 0x48);
      *pbVar1 = *pbVar1 | 0x80;
      pbVar1 = (byte *)(*(int *)(param_1 + 0xa8) + 0x2b + *(int *)(param_1 + 0x60) * 0x48);
      *pbVar1 = *pbVar1 | 0x80;
      pbVar1 = (byte *)(*(int *)(param_1 + 0xa8) + 0x3a + *(int *)(param_1 + 0x60) * 0x48);
      *pbVar1 = *pbVar1 | 0x80;
      pbVar1 = (byte *)(*(int *)(param_1 + 0xa8) + 0x2c + *(int *)(param_1 + 0x60) * 0x48);
      *pbVar1 = *pbVar1 | 0x80;
      pbVar1 = (byte *)(*(int *)(param_1 + 0xa8) + 0x3b + *(int *)(param_1 + 0x60) * 0x48);
      *pbVar1 = *pbVar1 | 0x80;
      uVar2 = FUN_001a90e8(*(byte *)(param_2 + local_14 * 6 + 0x28) & 1,
                           (uint)param_2[local_14 * 6 + 0x28] >> 1 & 1);
      if (param_6 != 0) {
        if (local_14 == 1) {
          *(undefined1 *)(*(int *)(param_1 + 0xa8) + 0x3c + *(int *)(param_1 + 0x60) * 0x48) = uVar2
          ;
        }
        else if (local_14 == 2) {
          *(undefined1 *)(*(int *)(param_1 + 0xa8) + 0x3d + *(int *)(param_1 + 0x60) * 0x48) = uVar2
          ;
        }
        else if (local_14 == 3) {
          *(undefined1 *)(*(int *)(param_1 + 0xa8) + 0x3e + *(int *)(param_1 + 0x60) * 0x48) = uVar2
          ;
        }
      }
      if (param_3 != 0) {
        if (local_14 == 1) {
          *(undefined1 *)(*(int *)(param_1 + 0xa8) + 0x2d + *(int *)(param_1 + 0x60) * 0x48) = uVar2
          ;
        }
        else if (local_14 == 2) {
          *(undefined1 *)(*(int *)(param_1 + 0xa8) + 0x2e + *(int *)(param_1 + 0x60) * 0x48) = uVar2
          ;
        }
        else if (local_14 == 3) {
          *(undefined1 *)(*(int *)(param_1 + 0xa8) + 0x2f + *(int *)(param_1 + 0x60) * 0x48) = uVar2
          ;
        }
      }
      local_14 = local_14 + 1;
      if (local_18 < local_14) {
        return;
      }
      if (local_14 == 1) break;
      if (local_14 == 2) {
        if (param_3 != 0) {
          *(char *)(*(int *)(param_1 + 0xa8) + 0x2b + *(int *)(param_1 + 0x60) * 0x48) =
               (char)*(undefined4 *)(param_4 + 8);
          iVar3 = *(int *)(param_1 + 0x60) * 0x48;
          *(byte *)(iVar3 + 0x26 + *(int *)(param_1 + 0xa8)) =
               *(byte *)(iVar3 + 0x26 + *(int *)(param_1 + 0xa8)) & 0xf8 |
               *(byte *)(param_5 + 8) & 7;
          iVar3 = *(int *)(param_1 + 0x60) * 0x48;
          *(byte *)(iVar3 + 0x26 + *(int *)(param_1 + 0xa8)) =
               *(byte *)(iVar3 + 0x26 + *(int *)(param_1 + 0xa8)) & 199 |
               ((byte)(*(int *)(param_5 + 8) >> 3) & 7) << 3;
          iVar3 = *(int *)(param_1 + 0x60) * 0x48;
          *(ushort *)(iVar3 + 0x26 + *(int *)(param_1 + 0xa8)) =
               *(ushort *)(iVar3 + 0x26 + *(int *)(param_1 + 0xa8)) & 0xfe3f |
               (ushort)((*(int *)(param_5 + 8) >> 6 & 7U) << 6);
        }
        if (param_6 != 0) {
          *(char *)(*(int *)(param_1 + 0xa8) + 0x3a + *(int *)(param_1 + 0x60) * 0x48) =
               (char)*(undefined4 *)(param_7 + 8);
          *(byte *)(*(int *)(param_1 + 0xa8) + 0x37 + *(int *)(param_1 + 0x60) * 0x48) =
               (byte)(*(int *)(param_8 + 8) >> 9) & 7;
        }
      }
      else if (local_14 == 3) {
        if (param_3 != 0) {
          *(char *)(*(int *)(param_1 + 0xa8) + 0x2c + *(int *)(param_1 + 0x60) * 0x48) =
               (char)*(undefined4 *)(param_4 + 0xc);
          iVar3 = *(int *)(param_1 + 0x60) * 0x48;
          *(byte *)(iVar3 + 0x28 + *(int *)(param_1 + 0xa8)) =
               *(byte *)(iVar3 + 0x28 + *(int *)(param_1 + 0xa8)) & 0xf8 |
               *(byte *)(param_5 + 0xc) & 7;
          iVar3 = *(int *)(param_1 + 0x60) * 0x48;
          *(byte *)(iVar3 + 0x28 + *(int *)(param_1 + 0xa8)) =
               *(byte *)(iVar3 + 0x28 + *(int *)(param_1 + 0xa8)) & 199 |
               ((byte)(*(int *)(param_5 + 0xc) >> 3) & 7) << 3;
          iVar3 = *(int *)(param_1 + 0x60) * 0x48;
          *(ushort *)(iVar3 + 0x28 + *(int *)(param_1 + 0xa8)) =
               *(ushort *)(iVar3 + 0x28 + *(int *)(param_1 + 0xa8)) & 0xfe3f |
               (ushort)((*(int *)(param_5 + 0xc) >> 6 & 7U) << 6);
        }
        if (param_6 != 0) {
          *(char *)(*(int *)(param_1 + 0xa8) + 0x3b + *(int *)(param_1 + 0x60) * 0x48) =
               (char)*(undefined4 *)(param_7 + 0xc);
          *(byte *)(*(int *)(param_1 + 0xa8) + 0x38 + *(int *)(param_1 + 0x60) * 0x48) =
               (byte)(*(int *)(param_8 + 0xc) >> 9) & 7;
        }
      }
    }
  } while( true );
}

/* FUN_001b4dde @ 0x1b4dde (253 bytes) */
int FUN_001b4dde(param_1, param_2)
  int param_1;
  undefined1 *param_2;
{
  undefined4 uVar1;
  char cVar2;
  bool bVar3;
  int local_4c;
  float local_48;
  int local_34;
  float local_30;
  
  uVar1 = DAT_001cf32c;
  cVar2 = FUN_000f7e7e(param_1,1,DAT_001cf32c,&local_34);
  if ((((cVar2 == '\0') || (local_34 != 2)) ||
      (cVar2 = FUN_000f7e7e(param_1,2,uVar1,&local_4c), cVar2 == '\0')) || (local_4c != 2)) {
    *param_2 = 0;
    bVar3 = false;
  }
  else {
    switch(*(undefined4 *)(param_1 + 300)) {
    case 0:
      bVar3 = local_30 == local_48;
      break;
    case 1:
      bVar3 = local_30 != local_48;
      break;
    case 2:
      bVar3 = local_48 < local_30;
      break;
    case 3:
      bVar3 = local_48 <= local_30;
      break;
    case 4:
      bVar3 = local_30 < local_48;
      break;
    case 5:
      bVar3 = local_30 <= local_48;
      break;
    default:
      bVar3 = false;
    }
    *param_2 = 1;
  }
  return bVar3;
}

/* FUN_001b4ef6 @ 0x1b4ef6 (109 bytes) */
int FUN_001b4ef6(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 0x24);
  uVar4 = *(int *)(iVar1 + 4) - 1;
  if (uVar4 < *(uint *)(iVar1 + 4)) {
    piVar3 = (int *)(*(int *)(iVar1 + 8) + uVar4 * 4);
  }
  else {
    piVar3 = (int *)0x0;
  }
  iVar2 = *piVar3;
  FUN_001a7f3c(iVar1,*(int *)(iVar1 + 4) + -1);
  *(short *)(*(int *)(param_1 + 0xa8) + 0xc + iVar2 * 0x48) =
       ((short)*(undefined4 *)(param_1 + 0x60) - *(short *)(param_1 + 0x74)) + -1;
  *(int *)(param_1 + 0xb4) = (*(int *)(param_1 + 0x60) - *(int *)(param_1 + 0x74)) + -1;
  return;
}

/* FUN_001b4f64 @ 0x1b4f64 (306 bytes) */
int FUN_001b4f64(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  bool bVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  
  iVar5 = FUN_000e9644(param_2);
  iVar1 = *(int *)(iVar5 + 300);
  uVar6 = FUN_0010b180(iVar5,1);
  uVar6 = FUN_0013c4e0(*(undefined4 *)(param_4 + 0x3f4),uVar6);
  iVar5 = param_1[0x18];
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined1 *)(param_2 + 0xdc));
  if ((*(char *)(param_2 + 0xdc) == '\0') || (iVar5 != param_1[0x18])) {
    bVar4 = false;
  }
  else {
    bVar4 = true;
  }
  uVar6 = (**(code **)(*param_1 + 0x98))(param_1,iVar1 != 1,uVar6,0);
  if (bVar4) {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + -0x44) = 1;
  }
  puVar2 = *(uint **)(param_1[4] + 0x24);
  uVar3 = puVar2[1];
  if (uVar3 < *puVar2) {
    _memset((void *)(uVar3 * 4 + puVar2[2]),0,4);
    puVar2[1] = uVar3 + 1;
    *(undefined4 *)(uVar3 * 4 + puVar2[2]) = uVar6;
    return;
  }
  puVar7 = (undefined4 *)FUN_001a7f7c(puVar2,uVar3);
  *puVar7 = uVar6;
  return;
}

/* FUN_001b5096 @ 0x1b5096 (65 bytes) */
int FUN_001b5096(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_2 + 0xbc);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,FUN_000010c4);
  *puVar2 = uVar1;
  *(undefined1 *)(puVar2 + 7) = 0;
  puVar2[1] = &PTR_FUN_001fe168;
  return puVar2 + 1;
}

/* FUN_001b50d8 @ 0x1b50d8 (258 bytes) */
int FUN_001b50d8(param_1)
  int *param_1;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  short sVar4;
  uint uVar5;
  
  iVar1 = *(int *)(param_1[4] + 0x28);
  iVar2 = *(int *)(iVar1 + 4);
  do {
    if (iVar2 == 0) {
      sVar4 = -1;
LAB_001b514b:
      *(undefined4 *)(param_1[0x2a] + param_1[0x18] * 0x48) = 5;
      *(undefined1 *)(param_1[0x2a] + 0x12 + param_1[0x18] * 0x48) = 0xff;
      *(undefined1 *)(param_1[0x2a] + 0x10 + param_1[0x18] * 0x48) = 1;
      *(undefined1 *)(param_1[0x2a] + 0xe + param_1[0x18] * 0x48) = 2;
      *(short *)(param_1[0x2a] + 0xc + param_1[0x18] * 0x48) = sVar4 - (short)param_1[0x1d];
                    
                    
      (**(code **)(*param_1 + 0x15c))();
      return;
    }
    uVar5 = *(int *)(iVar1 + 4) - 1;
    if (uVar5 < *(uint *)(iVar1 + 4)) {
      piVar3 = (int *)(*(int *)(iVar1 + 8) + uVar5 * 4);
    }
    else {
      piVar3 = (int *)0x0;
    }
    iVar2 = *piVar3;
    FUN_001a7f3c(iVar1,*(int *)(iVar1 + 4) + -1);
    if ((*(char *)(iVar2 + 0xe) == '\x03') || (*(char *)(iVar2 + 0xe) == '\x01')) {
      sVar4 = *(short *)(iVar2 + 0xc);
      *(short *)(iVar2 + 0xc) = (short)param_1[0x18] - (short)param_1[0x1d];
      goto LAB_001b514b;
    }
    *(short *)(iVar2 + 0xc) = (short)param_1[0x18] - (short)param_1[0x1d];
    iVar1 = *(int *)(param_1[4] + 0x28);
    iVar2 = *(int *)(iVar1 + 4);
  } while( true );
}

/* FUN_001b51da @ 0x1b51da (147 bytes) */
int FUN_001b51da(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 param_3;
{
  int iVar1;
  bool bVar2;
  
  iVar1 = param_1[0x18];
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined1 *)(param_2 + 0xdc));
  if ((*(char *)(param_2 + 0xdc) == '\0') || (iVar1 != param_1[0x18])) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  ((int (*)())FUN_001b50d8)(param_1);
  if (*(char *)(*(int *)(param_2 + 0x124) + 300) != '\0') {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + -0x3a) = 4;
  }
  if (bVar2) {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + -0x44) = 1;
  }
  return;
}

