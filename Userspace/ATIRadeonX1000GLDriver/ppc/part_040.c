#include "decls.h"

/* FUN_00179894 @ 0x179894 (184 bytes) */
int FUN_00179894(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = FUN_00179608(param_1,param_2,1,2);
  if (iVar1 != 0) {
    uVar3 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xb8);
    uVar4 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xd0);
    if (((uVar3 & 1) == (uVar4 & 1)) && ((uVar3 >> 1 & 1) == (uVar4 >> 1 & 1))) {
      iVar1 = ((bool (*)())FUN_0010b820)((double)FLOAT_001aa0d4,(double)FLOAT_001aa0d4);
      uVar2 = 0x3f800000;
      if (iVar1 == 0) {
        uVar2 = 0;
      }
      uVar2 = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),uVar2);
      *(undefined4 *)(param_2 * 4 + param_1 + 0x30) = uVar2;
      return 1;
    }
  }
  return 0;
}

/* FUN_0017994c @ 0x17994c (232 bytes) */
int FUN_0017994c(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  
  iVar2 = FUN_00179608(param_1,param_2,1,2);
  if (iVar2 != 0) {
    uVar5 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xd0);
    uVar1 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xb8);
    if ((((uVar1 & 1) != (uVar5 & 1)) && ((uVar1 >> 1 & 1) == (uVar5 >> 1 & 1))) &&
       (iVar2 = param_2 * 4 + param_1, *(int *)(iVar2 + 0x178) < 0)) {
      piVar3 = (int *)FUN_00173360(*(undefined4 *)(param_1 + 0x238));
      if ((*(int *)(*(int *)(param_1 + 0xb0) + 0x120) == 0) &&
         (*(int *)(*(int *)(param_1 + 0xb0) + 0x124) == 0)) {
        uVar4 = FUN_00173360(*(undefined4 *)(param_1 + 0x238),
                             *(undefined4 *)
                              (((1 - (*piVar3 >> 0x1f)) * 4 + param_2) * 4 + param_1 + 0x168));
        *(undefined4 *)(iVar2 + 0x30) = uVar4;
        return 1;
      }
      return 1;
    }
  }
  return 0;
}

/* FUN_00179a34 @ 0x179a34 (244 bytes) */
int FUN_00179a34(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  
  iVar2 = FUN_00179608(param_1,param_2,1,2);
  if (iVar2 != 0) {
    uVar5 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xd0);
    uVar1 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xb8);
    if ((((uVar1 & 1) != (uVar5 & 1)) && ((uVar1 >> 1 & 1) == (uVar5 >> 1 & 1))) &&
       (*(int *)(param_2 * 4 + param_1 + 0x178) < 0)) {
      piVar3 = (int *)FUN_00173360(*(undefined4 *)(param_1 + 0x238));
      iVar2 = 1;
      if (0 < *piVar3) {
        iVar2 = 2;
      }
      if ((*(int *)(*(int *)(param_1 + 0xb0) + 0x120) == 0) &&
         (*(int *)(*(int *)(param_1 + 0xb0) + 0x124) == 0)) {
        uVar4 = FUN_00173360(*(undefined4 *)(param_1 + 0x238),
                             *(undefined4 *)((iVar2 * 4 + param_2) * 4 + param_1 + 0x168));
        *(undefined4 *)(param_2 * 4 + param_1 + 0x30) = uVar4;
        return 1;
      }
      return 1;
    }
  }
  return 0;
}

/* FUN_00179b28 @ 0x179b28 (148 bytes) */
int FUN_00179b28(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  iVar2 = FUN_00179608(param_1,param_2,1,2);
  if (iVar2 != 0) {
    uVar4 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xd0);
    uVar1 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xb8);
    if (((uVar1 & 1) != (uVar4 & 1)) && ((uVar1 >> 1 & 1) == (uVar4 >> 1 & 1))) {
      uVar3 = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),0);
      *(undefined4 *)(param_2 * 4 + param_1 + 0x30) = uVar3;
      return 1;
    }
  }
  return 0;
}

/* FUN_00179bbc @ 0x179bbc (136 bytes) */
int FUN_00179bbc(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0xb0) + 0x84);
  if ((iVar1 != 1) && (1 < iVar1)) {
    iVar1 = 2;
    do {
      iVar2 = FUN_00179608(param_1,param_2,iVar1 + -1,iVar1);
      if (iVar2 == 0) {
        return 0;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 <= *(int *)(*(int *)(param_1 + 0xb0) + 0x84));
  }
  return 1;
}

/* FUN_00179c44 @ 0x179c44 (124 bytes) */
int FUN_00179c44(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  while ((iVar2 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0),
         *(char *)(iVar3 + iVar2 + 0x10) == '\x01' ||
         (iVar2 = FUN_00179608(param_1,iVar3,param_2,param_3), iVar2 != 0))) {
    bVar1 = iVar3 == 3;
    iVar3 = iVar3 + 1;
    if (bVar1) {
      return 1;
    }
  }
  return 0;
}

/* FUN_00179cc0 @ 0x179cc0 (240 bytes) */
int FUN_00179cc0(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  
  iVar7 = 1;
  iVar3 = param_2 * 4 + param_1;
  piVar8 = (int *)(iVar3 + 0x178);
  while ((-1 < *piVar8 ||
         (piVar4 = (int *)FUN_00173360(*(undefined4 *)(param_1 + 0x238)), *piVar4 != 0))) {
    bVar1 = iVar7 == 2;
    piVar8 = piVar8 + 4;
    iVar7 = iVar7 + 1;
    if (bVar1) {
      return 0;
    }
  }
  iVar6 = *(int *)(param_1 + 0xb0);
  iVar7 = (iVar7 == 1) + 1;
  if ((((*(int *)(iVar6 + 0x120) == 0) && (*(int *)(iVar6 + 0x124) == 0)) &&
      (uVar2 = *(uint *)(iVar7 * 0x18 + iVar6 + 0xa0), (uVar2 & 1) == 0)) && ((uVar2 & 2) == 0)) {
    uVar5 = FUN_00173360(*(undefined4 *)(param_1 + 0x238),
                         *(undefined4 *)((iVar7 * 4 + param_2) * 4 + param_1 + 0x168));
    *(undefined4 *)(iVar3 + 0x30) = uVar5;
    return 1;
  }
  return 1;
}

/* FUN_00179db0 @ 0x179db0 (196 bytes) */
int FUN_00179db0(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  
  iVar2 = param_2 * 4 + param_1;
  piVar6 = (int *)(iVar2 + 0x178);
  iVar5 = 1;
  while ((-1 < *piVar6 ||
         (piVar3 = (int *)FUN_00173360(*(undefined4 *)(param_1 + 0x238)), *piVar3 != 0))) {
    bVar1 = iVar5 == 2;
    piVar6 = piVar6 + 4;
    iVar5 = iVar5 + 1;
    if (bVar1) {
      return 0;
    }
  }
  iVar5 = *(int *)(param_1 + 0xb0);
  if ((((*(int *)(iVar5 + 0x120) == 0) && (*(int *)(iVar5 + 0x124) == 0)) &&
      ((*(uint *)(iVar5 + 0xe8) & 1) == 0)) && ((*(uint *)(iVar5 + 0xe8) & 2) == 0)) {
    uVar4 = FUN_00173360(*(undefined4 *)(param_1 + 0x238),*(undefined4 *)(iVar2 + 0x198));
    *(undefined4 *)(iVar2 + 0x30) = uVar4;
    return 1;
  }
  return 1;
}

/* FUN_00179e74 @ 0x179e74 (196 bytes) */
int FUN_00179e74(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  iVar1 = FUN_00179608(param_1,param_2,1,2);
  if (iVar1 != 0) {
    iVar1 = *(int *)(param_1 + 0xb0);
    uVar3 = *(uint *)(iVar1 + 0xb8);
    if (((uVar3 & 1) == (*(uint *)(iVar1 + 0xd0) & 1)) &&
       ((uVar3 >> 1 & 1) == (*(uint *)(iVar1 + 0xd0) >> 1 & 1))) {
      if ((*(int *)(iVar1 + 0x120) == 0) &&
         (((*(int *)(iVar1 + 0x124) == 0 && ((uVar3 & 1) == 0)) && ((uVar3 & 2) == 0)))) {
        iVar1 = param_2 * 4 + param_1;
        uVar2 = FUN_00173360(*(undefined4 *)(param_1 + 0x238),*(undefined4 *)(iVar1 + 0x178));
        *(undefined4 *)(iVar1 + 0x30) = uVar2;
        return 1;
      }
      return 1;
    }
  }
  return 0;
}

/* FUN_00179f38 @ 0x179f38 (252 bytes) */
int FUN_00179f38(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  float *pfVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  
  iVar7 = 1;
  iVar3 = param_2 * 4 + param_1;
  piVar8 = (int *)(iVar3 + 0x178);
  while ((-1 < *piVar8 ||
         (pfVar4 = (float *)FUN_00173360(*(undefined4 *)(param_1 + 0x238)), *pfVar4 != 1.0))) {
    bVar1 = iVar7 == 2;
    piVar8 = piVar8 + 4;
    iVar7 = iVar7 + 1;
    if (bVar1) {
      return 0;
    }
  }
  iVar6 = *(int *)(param_1 + 0xb0);
  iVar7 = (iVar7 == 1) + 1;
  if ((*(int *)(iVar6 + 0x120) == 0) &&
     (((*(int *)(iVar6 + 0x124) == 0 &&
       (uVar2 = *(uint *)(iVar7 * 0x18 + iVar6 + 0xa0), (uVar2 & 1) == 0)) && ((uVar2 & 2) == 0))))
  {
    uVar5 = FUN_00173360(*(undefined4 *)(param_1 + 0x238),
                         *(undefined4 *)((iVar7 * 4 + param_2) * 4 + param_1 + 0x168));
    *(undefined4 *)(iVar3 + 0x30) = uVar5;
    return 1;
  }
  return 1;
}

/* FUN_0017a034 @ 0x17a034 (252 bytes) */
int FUN_0017a034(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  uint uVar2;
  float *pfVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = param_2 * 4 + param_1;
  uVar1 = 0;
  if (*(int *)(iVar7 + 0x178) < 0) {
    pfVar3 = (float *)FUN_00173360(*(undefined4 *)(param_1 + 0x238));
    pfVar4 = (float *)FUN_00173e10(*(undefined4 *)(param_1 + 0x238),0);
    iVar5 = ((bool (*)())FUN_0010b820)((double)*pfVar3,(double)*pfVar4,*(undefined4 *)(param_1 + 0xb0));
    iVar6 = *(int *)(param_1 + 0xb0);
    iVar5 = (iVar5 == 0) + 2;
    if ((((*(int *)(iVar6 + 0x120) == 0) && (*(int *)(iVar6 + 0x124) == 0)) &&
        (uVar2 = *(uint *)(iVar5 * 0x18 + iVar6 + 0xa0), (uVar2 & 1) == 0)) && ((uVar2 & 2) == 0)) {
      if (*(int *)((iVar5 * 4 + param_2) * 4 + param_1 + 0x168) < 0) {
        uVar1 = FUN_00173360(*(undefined4 *)(param_1 + 0x238));
        *(undefined4 *)(iVar7 + 0x30) = uVar1;
        return 1;
      }
      uVar1 = FUN_00173330(*(undefined4 *)(param_1 + 0x238));
      *(undefined4 *)(iVar7 + 0x40) = uVar1;
      return 1;
    }
    uVar1 = 1;
  }
  return uVar1;
}

/* FUN_0017a130 @ 0x17a130 (324 bytes) */
int FUN_0017a130(param_1, param_2, param_3, param_4)
  int param_1;
  float *param_2;
  int param_3;
  int param_4;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  
  uVar4 = DAT_001b01d8;
  if (param_1 == 0) {
    *(undefined4 *)(param_3 + 0x9c) = DAT_001b01d8;
  }
  else {
    iVar3 = FUN_001054ec(param_3,param_1);
    *(undefined4 *)(iVar3 + 0x10) = uVar4;
  }
  FUN_000f79c4((double)*param_2,(double)param_2[1],(double)param_2[2],(double)param_2[3],param_3,
               *(undefined4 *)(param_4 + 0x6c4),param_1);
  piVar1 = *(int **)(*(int *)(param_1 * 0x18 + param_3 + 0x8c) + 0x18);
  if (*piVar1 == 0) {
    piVar1 = (int *)FUN_0019423c(piVar1,0);
  }
  else {
    if (piVar1[1] == 0) {
      *(undefined4 *)piVar1[2] = 0;
      piVar1[1] = 1;
    }
    piVar1 = (int *)piVar1[2];
  }
  iVar5 = *piVar1;
  iVar3 = *(int *)(iVar5 + 0x8c);
  if (*(int *)(*(int *)(iVar3 + 0x2c) + 4) == 0) {
    uVar4 = *(undefined4 *)(param_4 + 0x378);
    puVar2 = (undefined4 *)FUN_00193e18(uVar4,0x240);
    puVar6 = puVar2 + 1;
    *puVar2 = uVar4;
    FUN_00173938(puVar6,iVar5,param_4);
    FUN_00174e0c(puVar6);
    FUN_00173278(puVar6);
    FUN_00123424(iVar3,*(undefined4 *)(*(int *)(iVar5 + 0x158) + 0xb0),puVar6);
  }
  FUN_001046c8(param_3,param_1,iVar3);
  return iVar5;
}

/* FUN_0017a294 @ 0x17a294 (320 bytes) */
int FUN_0017a294(param_1, param_2, param_3)
  int param_1;
  float *param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  iVar2 = *(int *)(param_1 + 0xb0);
  iVar1 = *(int *)(*(int *)(iVar2 + 0x88) + 8);
  if (iVar1 == 0x8b) {
    FUN_00104be8(iVar2,1);
    uVar3 = ((int (*)())FUN_0017a130)(1,param_2,*(undefined4 *)(param_1 + 0xb0),param_3);
    *(undefined4 *)(param_1 + 0x214) = uVar3;
    FUN_000f79c4((double)*param_2,(double)param_2[1],(double)param_2[2],(double)param_2[3],
                 *(undefined4 *)(param_1 + 0xb0),*(undefined4 *)(param_3 + 0x6c4),1);
    FUN_00104be8(*(undefined4 *)(param_1 + 0xb0),2);
    local_24 = DAT_001b01ec;
    local_28 = DAT_001b01e8;
    local_20 = DAT_001b01f0;
    local_1c = DAT_001b01f4;
    uVar3 = ((int (*)())FUN_0017a130)(2,&local_28,*(undefined4 *)(param_1 + 0xb0),param_3);
    *(undefined4 *)(param_1 + 0x218) = uVar3;
    *(undefined4 *)(*(int *)(param_1 + 0xb0) + 300) = 0;
  }
  else if (iVar1 == 0x8c) {
    FUN_00104be8(iVar2,1);
    uVar3 = ((int (*)())FUN_0017a130)(1,param_2,*(undefined4 *)(param_1 + 0xb0),param_3);
    *(undefined4 *)(param_1 + 0x214) = uVar3;
    FUN_000f79c4((double)*param_2,(double)param_2[1],(double)param_2[2],(double)param_2[3],
                 *(undefined4 *)(param_1 + 0xb0),*(undefined4 *)(param_3 + 0x6c4),1);
    *(undefined4 *)(*(int *)(param_1 + 0xb0) + 300) = 0;
  }
  return;
}

/* FUN_0017a3d4 @ 0x17a3d4 (884 bytes) */
int FUN_0017a3d4(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  float fVar3;
  uint uVar4;
  float fVar5;
  float *pfVar6;
  float *pfVar7;
  int iVar8;
  float *pfVar9;
  int iVar10;
  int iVar11;
  float *pfVar12;
  int iVar13;
  int *piVar14;
  int *piVar15;
  bool bVar16;
  int iVar17;
  int iVar18;
  int local_94 [2];
  float local_8c [9];
  int local_68;
  
  iVar17 = 4;
  pfVar12 = local_8c + 3;
  pfVar6 = pfVar12;
  do {
    *pfVar6 = NAN;
    pfVar6 = pfVar6 + 1;
    iVar17 = iVar17 + -1;
  } while (iVar17 != 0);
  iVar17 = 0;
  iVar18 = 4;
  do {
    *(undefined4 *)(iVar17 + (int)pfVar12) = 0;
    iVar17 = iVar17 + 4;
    iVar18 = iVar18 + -1;
  } while (iVar18 != 0);
  bVar16 = false;
  local_68 = 1;
  iVar17 = 0;
  iVar18 = param_1 + 0x170;
  pfVar6 = pfVar12;
  fVar3 = FLOAT_001aa114;
  do {
    iVar8 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
    pfVar7 = local_8c;
    if (*(char *)(iVar17 + iVar8 + 0x10) != '\x01') {
      do {
        *pfVar7 = NAN;
        pfVar7 = pfVar7 + 1;
      } while (pfVar12 != pfVar7);
      piVar14 = (int *)(iVar18 + 8);
      bVar2 = true;
      iVar8 = 1;
      piVar15 = local_94;
      iVar13 = 0x98;
      pfVar7 = local_8c;
      do {
        pfVar7 = pfVar7 + 1;
        *piVar15 = 0;
        if (*piVar14 < 0) {
          pfVar9 = (float *)FUN_00173360(*(undefined4 *)(param_1 + 0x238));
          *pfVar7 = *pfVar9;
          iVar10 = FUN_00176324(*pfVar9);
          *piVar15 = iVar10;
        }
        else {
          if (*piVar14 < 1) {
            return 0;
          }
          iVar10 = FUN_00173330(*(undefined4 *)(param_1 + 0x238));
          iVar11 = *(int *)(iVar10 + 0xc);
          *piVar15 = iVar11;
          iVar10 = *(int *)(param_1 + 0xb0) + iVar13;
          uVar4 = *(uint *)(iVar10 + 0x20);
          if ((uVar4 & 2) != 0) {
            *piVar15 = (DAT_001e61d0)[iVar11];
            uVar4 = *(uint *)(iVar10 + 0x20);
          }
          if ((uVar4 & 1) == 0) {
            iVar10 = *piVar15;
            bVar16 = true;
            bVar2 = false;
          }
          else {
            bVar16 = true;
            bVar2 = false;
            iVar10 = *(int *)(&DAT_001e61b8 + *piVar15 * 4);
            *piVar15 = iVar10;
          }
        }
        iVar11 = local_94[0];
        if (iVar10 == 0) {
          return 0;
        }
        bVar1 = iVar8 != 2;
        iVar13 = iVar13 + 0x18;
        piVar15 = piVar15 + 1;
        piVar14 = piVar14 + 4;
        iVar8 = iVar8 + 1;
      } while (bVar1);
      if (bVar2) {
        iVar8 = ((bool (*)())FUN_0010b820)((double)local_8c[1],(double)local_8c[2],*(undefined4 *)(param_1 + 0xb0)
                            );
        fVar5 = 0.0;
        if (iVar8 == 0) {
LAB_0017a608:
          fVar5 = 1.0;
        }
        *pfVar6 = fVar5;
      }
      else {
        iVar8 = FUN_0010b5f8(*(undefined4 *)(param_1 + 0xb0));
        iVar8 = *(int *)(&DAT_001e61e8 + (iVar8 * 6 + iVar11 * 0x30 + local_94[1]) * 4);
        if (iVar8 == 1) {
          *pfVar6 = 0.0;
        }
        else {
          if (iVar8 == 2) goto LAB_0017a608;
          if (iVar8 == 0) {
            return 0;
          }
        }
      }
      if (fVar3 == FLOAT_001aa114) {
        fVar3 = *pfVar6;
      }
      else if (*pfVar6 != fVar3) {
        local_68 = 0;
      }
    }
    bVar2 = iVar17 == 3;
    iVar18 = iVar18 + 4;
    pfVar6 = pfVar6 + 1;
    iVar17 = iVar17 + 1;
    if (bVar2) {
      if (bVar16) {
        iVar17 = *(int *)(*(int *)(param_1 + 0x238) + 0x6c4);
        *(int *)(iVar17 + 0x134) = *(int *)(iVar17 + 0x134) + 1;
      }
      ((int (*)())FUN_0017a294)(param_1,pfVar12,*(undefined4 *)(param_1 + 0x238));
      iVar17 = FUN_000e07dc(*(undefined4 *)(param_1 + 0x238),0xd);
      if ((iVar17 != 0) && (local_68 != 0)) {
        piVar15 = *(int **)(*(int *)(param_1 + 0xb0) + 0x158);
        bVar16 = fVar3 != FLOAT_001aa0d4;
        iVar17 = (**(code **)(*piVar15 + 0x24))(piVar15);
        if (iVar17 != 0) {
          if (bVar16) {
            iVar17 = piVar15[0x4d];
          }
          else {
            iVar17 = piVar15[0x4e];
          }
          FUN_0012cfa4(*(undefined4 *)(*(int *)(param_1 + 0x238) + 0x6c4),piVar15,iVar17,
                       piVar15[0x4f]);
          if (bVar16) {
            iVar17 = 2;
          }
          else {
            iVar17 = 1;
          }
          piVar15[0x53] = iVar17;
          return 1;
        }
      }
      return 1;
    }
  } while( true );
}

/* FUN_0017a748 @ 0x17a748 (348 bytes) */
int FUN_0017a748(param_1)
  int param_1;
{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 local_38 [8];
  
  iVar4 = ((int (*)())FUN_00179c44)(param_1,1,2);
  if (iVar4 != 0) {
    uVar6 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xd0);
    uVar2 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xb8);
    if (((uVar2 & 1) == (uVar6 & 1)) && ((uVar2 >> 1 & 1) == (uVar6 >> 1 & 1))) {
      puVar7 = local_38;
      iVar4 = 4;
      puVar3 = puVar7;
      do {
        *puVar3 = 0x7ffffffe;
        puVar3 = puVar3 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      iVar4 = 0;
      iVar8 = 4;
      do {
        *(undefined4 *)(iVar4 + (int)puVar7) = 0;
        iVar4 = iVar4 + 4;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
      iVar4 = FUN_00176324(0);
      iVar8 = 0;
      do {
        iVar5 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
        if (*(char *)(iVar8 + iVar5 + 0x10) != '\x01') {
          iVar5 = FUN_0010b5f8(*(undefined4 *)(param_1 + 0xb0));
          if (*(int *)(&DAT_001e61e8 + (iVar5 * 6 + iVar4 * 0x31) * 4) == 1) {
            *puVar7 = 0;
          }
          else if (*(int *)(&DAT_001e61e8 + (iVar5 * 6 + iVar4 * 0x31) * 4) == 2) {
            *puVar7 = 0x3f800000;
          }
        }
        bVar1 = iVar8 != 3;
        puVar7 = puVar7 + 1;
        iVar8 = iVar8 + 1;
      } while (bVar1);
      ((int (*)())FUN_0017a294)(param_1,local_38,*(undefined4 *)(param_1 + 0x238));
      FUN_001745ac(param_1);
      return 1;
    }
  }
  return 0;
}

/* FUN_0017a8a4 @ 0x17a8a4 (680 bytes) */
int FUN_0017a8a4(param_1)
  int param_1;
{
  bool bVar1;
  float fVar2;
  bool bVar3;
  float *pfVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  bool bVar11;
  int iVar12;
  int iVar13;
  float local_58 [7];
  
  iVar12 = 4;
  pfVar4 = local_58;
  do {
    *pfVar4 = NAN;
    pfVar4 = pfVar4 + 1;
    iVar12 = iVar12 + -1;
  } while (iVar12 != 0);
  iVar12 = 0;
  iVar13 = 4;
  do {
    *(undefined4 *)(iVar12 + (int)local_58) = 0;
    iVar12 = iVar12 + 4;
    iVar13 = iVar13 + -1;
  } while (iVar13 != 0);
  iVar13 = FUN_00176324(0);
  bVar11 = false;
  bVar3 = true;
  iVar9 = 0;
  iVar8 = 0;
  iVar12 = param_1;
  fVar2 = FLOAT_001aa114;
  do {
    iVar5 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
    if (*(char *)(iVar9 + iVar5 + 0x10) != '\x01') {
      if (*(int *)(iVar12 + 0x178) < 0) {
        puVar6 = (undefined4 *)FUN_00173360(*(undefined4 *)(param_1 + 0x238));
        iVar5 = FUN_00176324(*puVar6);
        iVar7 = *(int *)(param_1 + 0xb0);
      }
      else {
        if (*(int *)(iVar12 + 0x178) < 1) {
          return 0;
        }
        iVar5 = FUN_00173330(*(undefined4 *)(param_1 + 0x238));
        iVar7 = *(int *)(param_1 + 0xb0);
        iVar5 = *(int *)(iVar5 + 0xc);
        if ((*(uint *)(iVar7 + 0xb8) & 2) != 0) {
          iVar5 = (DAT_001e61d0)[iVar5];
        }
        bVar11 = true;
        if ((*(uint *)(iVar7 + 0xb8) & 1) != 0) {
          iVar5 = *(int *)(&DAT_001e61b8 + iVar5 * 4);
        }
      }
      iVar7 = FUN_0010b5f8(iVar7);
      iVar5 = *(int *)(&DAT_001e61e8 + (iVar7 * 6 + iVar5 * 0x30 + iVar13) * 4);
      if (iVar5 == 1) {
        *(undefined4 *)(iVar8 + (int)local_58) = 0;
      }
      else if (iVar5 == 2) {
        *(undefined4 *)(iVar8 + (int)local_58) = 0x3f800000;
      }
      else if (iVar5 == 0) {
        return 0;
      }
      if (fVar2 == FLOAT_001aa114) {
        fVar2 = *(float *)(iVar8 + (int)local_58);
      }
      else if (*(float *)(iVar8 + (int)local_58) != fVar2) {
        bVar3 = false;
      }
    }
    bVar1 = iVar9 != 3;
    iVar8 = iVar8 + 4;
    iVar12 = iVar12 + 4;
    iVar9 = iVar9 + 1;
  } while (bVar1);
  if (bVar11) {
    iVar12 = *(int *)(*(int *)(param_1 + 0x238) + 0x6c4);
    *(int *)(iVar12 + 0x134) = *(int *)(iVar12 + 0x134) + 1;
  }
  ((int (*)())FUN_0017a294)(param_1,local_58,*(undefined4 *)(param_1 + 0x238));
  iVar12 = FUN_000e07dc(*(undefined4 *)(param_1 + 0x238),0xd);
  if ((iVar12 != 0) && (bVar3)) {
    piVar10 = *(int **)(*(int *)(param_1 + 0xb0) + 0x158);
    bVar11 = fVar2 != FLOAT_001aa0d4;
    iVar12 = (**(code **)(*piVar10 + 0x24))(piVar10);
    if (iVar12 != 0) {
      if (bVar11) {
        iVar12 = piVar10[0x4d];
      }
      else {
        iVar12 = piVar10[0x4e];
      }
      FUN_0012cfa4(*(undefined4 *)(*(int *)(param_1 + 0x238) + 0x6c4),piVar10,iVar12,piVar10[0x4f]);
      if (bVar11) {
        iVar12 = 2;
      }
      else {
        iVar12 = 1;
      }
      piVar10[0x53] = iVar12;
      return 1;
    }
  }
  return 1;
}

/* FUN_0017ab4c @ 0x17ab4c (472 bytes) */
int FUN_0017ab4c(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  double dVar9;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  float local_48 [7];
  
  iVar7 = 1;
  iVar6 = 0x98;
  puVar8 = (undefined4 *)(param_1 + 0x214);
  do {
    FUN_00178d78(local_48,param_1,iVar7);
    if (local_48[0] != NAN) {
      bVar1 = -1 < (int)local_48[0];
      if (bVar1) {
        dVar9 = (double)local_48[0];
      }
      else {
        dVar9 = -(double)local_48[0];
      }
      if ((dVar9 != (double)FLOAT_001aa0e8) && (iVar2 = ((undefined4 (*)())FUN_0010aafc)(dVar9), iVar2 != 0)) {
        iVar2 = ((int (*)())FUN_0010ab40)(dVar9);
        piVar5 = *(int **)(*(int *)(param_1 + 0x238) + 0x30c);
        iVar2 = iVar2 + *(int *)(*(int *)(param_1 + 0xb0) + 0x124);
        iVar3 = (**(code **)(*piVar5 + 0xfc))(piVar5,iVar2);
        if (iVar3 != 0) {
          local_58 = DAT_001b01f8;
          local_54 = DAT_001b01fc;
          local_50 = DAT_001b0200;
          local_4c = DAT_001b0204;
          uVar4 = ((int (*)())FUN_0017a130)(iVar7,&local_58,*(undefined4 *)(param_1 + 0xb0),
                               *(undefined4 *)(param_1 + 0x238));
          iVar3 = *(int *)(param_1 + 0xb0);
          *puVar8 = uVar4;
          *(int *)(iVar3 + 0x124) = iVar2;
          FUN_00103d50(iVar6 + *(int *)(param_1 + 0xb0) + 0xc,1,0);
          FUN_00103d50(iVar6 + *(int *)(param_1 + 0xb0) + 0xc,2,0);
          if (!bVar1) {
            iVar6 = *(int *)(param_1 + 0xb0) + ((iVar7 == 1) - 1) * 0x18 + 0xb0;
            FUN_00103d50(iVar6 + 0xc,1,(*(uint *)(iVar6 + 0x20) ^ 1) & 1);
          }
          FUN_001745ac(param_1);
          return 1;
        }
      }
    }
    bVar1 = iVar7 != 2;
    puVar8 = puVar8 + 1;
    iVar6 = iVar6 + 0x18;
    iVar7 = iVar7 + 1;
  } while (bVar1);
  return 0;
}

/* FUN_0017ad24 @ 0x17ad24 (260 bytes) */
int FUN_0017ad24(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 local_38 [8];
  
  uVar4 = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x158);
  iVar2 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 0x238));
  FUN_001046c8(iVar2,0,*(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c));
  uVar3 = *(undefined4 *)(PTR_DAT_001e8b64 + param_3 * 4);
  iVar1 = 0;
  *(undefined4 *)(iVar2 + 0x94) = *(undefined4 *)(iVar2 + 0x14c);
  iVar5 = 4;
  *(undefined4 *)(iVar2 + 0x98) = 0;
  *(undefined4 *)(iVar2 + 0x9c) = uVar3;
  do {
    *(undefined4 *)(iVar1 + (int)local_38) = param_2;
    iVar1 = iVar1 + 4;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  ((int (*)())FUN_0017a130)(1,local_38,iVar2,*(undefined4 *)(param_1 + 0x238));
  FUN_001049e8(iVar2,*(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c),
               *(undefined4 *)(param_1 + 0x238));
  *(undefined1 *)(param_3 + *(int *)(param_1 + 0xb0) + 0x9c) = 1;
  iVar1 = *(int *)(param_1 + 0xb0);
  if ((*(uint *)(iVar1 + 0x14) & 0x200) == 0) {
    FUN_001049e8(iVar1,*(undefined4 *)(iVar1 + 0x8c),*(undefined4 *)(param_1 + 0x238));
    iVar1 = *(int *)(param_1 + 0xb0);
  }
  FUN_000e7738(uVar4,iVar1,iVar2);
  return iVar2;
}

/* FUN_0017ae28 @ 0x17ae28 (272 bytes) */
int FUN_0017ae28(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  int param_7;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar3 = *(int *)(param_3 + 0x8c);
  if (*(int *)(*(int *)(iVar3 + 0x2c) + 4) == 0) {
    uVar2 = *(undefined4 *)(param_7 + 0x378);
    puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x240);
    puVar4 = puVar1 + 1;
    *puVar1 = uVar2;
    FUN_00173938(puVar4,param_3,param_7);
    FUN_00174e0c(puVar4);
    FUN_00173278(puVar4);
    FUN_00123424(iVar3,*(undefined4 *)(*(int *)(param_3 + 0x158) + 0xb0),puVar4);
  }
  FUN_001046c8(*(undefined4 *)(param_1 + 0xb0),param_2,iVar3);
  if (param_2 == 0) {
    *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x9c) = param_4;
  }
  else {
    iVar3 = FUN_001054ec(*(int *)(param_1 + 0xb0),param_2);
    *(undefined4 *)(iVar3 + 0x10) = param_4;
  }
  iVar3 = param_2 * 0x18 + 0x80;
  FUN_00103d50(iVar3 + *(int *)(param_1 + 0xb0) + 0xc,1,param_5);
  FUN_00103d50(iVar3 + *(int *)(param_1 + 0xb0) + 0xc,2,param_6);
  return param_3;
}

/* FUN_0017af58 @ 0x17af58 (200 bytes) */
int FUN_0017af58(param_1, param_2, param_3)
  undefined4 *param_1;
  int param_2;
  int param_3;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  undefined4 local_28 [6];
  
  piVar7 = (int *)(param_3 * 0x10 + param_2 + 0x168);
  iVar4 = FUN_001054ec(*(undefined4 *)(param_2 + 0xb0),0);
  iVar6 = 0;
  bVar1 = false;
  bVar2 = true;
  iVar3 = 0;
  local_28[0] = *(undefined4 *)(iVar4 + 0x10);
  iVar4 = 4;
  do {
    if (*(char *)((int)local_28 + iVar3) != '\x01') {
      if (bVar2) {
        iVar6 = *piVar7;
        bVar1 = iVar6 < 0;
        bVar2 = iVar6 == 0;
      }
      else if (*piVar7 != iVar6) goto LAB_0017affc;
    }
    iVar3 = iVar3 + 1;
    piVar7 = piVar7 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  if (bVar1) {
    puVar5 = (undefined4 *)FUN_00173360(*(undefined4 *)(param_2 + 0x238));
    *param_1 = *puVar5;
  }
  else {
LAB_0017affc:
    *param_1 = 0x7ffffffe;
  }
  return param_1;
}

/* FUN_0017b020 @ 0x17b020 (268 bytes) */
int FUN_0017b020(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  
  puVar5 = *(uint **)(*(int *)(param_2 * 0x18 + *(int *)(param_1 + 0xb0) + 0x8c) + 0x2c);
  uVar3 = puVar5[1];
  uVar4 = uVar3 - 1;
  if (uVar4 < *puVar5) {
    if (uVar3 <= uVar4) {
      _memset((void *)(uVar3 * 4 + puVar5[2]),0,(uVar4 - uVar3) * 4 + 4);
      puVar5[1] = uVar3;
    }
    piVar1 = (int *)(uVar4 * 4 + puVar5[2]);
  }
  else {
    piVar1 = (int *)FUN_0019423c(puVar5,uVar4);
  }
  iVar6 = *piVar1;
  iVar2 = (**(code **)(**(int **)(iVar6 + 0xb0) + 100))();
  if (((iVar2 != 0) &&
      (iVar2 = FUN_001054ec(*(undefined4 *)(iVar6 + 0xb0),0), *(int *)(iVar2 + 0x10) == DAT_001b01e4
      )) && (iVar2 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),1),
            *(int *)(iVar2 + 0x10) == DAT_001b01d8)) {
    return 1;
  }
  return 0;
}

/* FUN_0017b12c @ 0x17b12c (2112 bytes) */
int FUN_0017b12c(param_1)
  int param_1;
{
  bool bVar1;
  byte bVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  float *pfVar10;
  int iVar11;
  int *piVar12;
  int *piVar13;
  undefined4 *puVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  undefined1 *puVar18;
  uint uVar19;
  char *pcVar20;
  uint *puVar21;
  int iVar22;
  double dVar23;
  undefined8 uVar24;
  int local_138 [6];
  undefined1 local_120 [4];
  int local_11c [4];
  undefined4 local_10c [4];
  undefined4 uStack_fc[0];
  undefined4 local_f8 [5];
  undefined4 local_e4 [23];
  float local_88[0];
  int local_84;
  int *local_80;
  undefined1 *local_7c;
  int *local_78;
  undefined *local_74;
  undefined4 *local_70;
  undefined *local_6c;
  int *local_68;
  
  iVar6 = FUN_000e07dc(*(undefined4 *)(param_1 + 0x238),0xb);
  if (((iVar6 == 0) || (iVar6 = FUN_000e07dc(*(undefined4 *)(param_1 + 0x238),0x3a), iVar6 == 0)) ||
     (*(int *)(*(int *)(param_1 + 0x238) + 0x664) <=
      *(int *)(*(int *)(*(int *)(param_1 + 0x238) + 0x6c4) + 0x228))) {
    local_84 = 0;
  }
  else {
    local_70 = local_e4;
    iVar6 = 0;
    do {
      puVar14 = local_70 + iVar6 * 4;
      iVar22 = 4;
      do {
        *puVar14 = 0xbf800000;
        uVar3 = DAT_001b01dc;
        uVar5 = DAT_001b01d0;
        puVar14 = puVar14 + 1;
        iVar22 = iVar22 + -1;
      } while (iVar22 != 0);
      bVar1 = iVar6 != 4;
      iVar6 = iVar6 + 1;
    } while (bVar1);
    local_74 = &DAT_001ab134;
    local_7c = local_120;
    iVar22 = 5;
    local_6c = &DAT_001ab134;
    iVar6 = 0;
    do {
      *(undefined4 *)((int)local_138 + iVar6 + 4) = 0;
      puVar18 = local_7c;
      *(undefined4 *)((int)local_10c + iVar6) = uVar5;
      *(undefined4 *)(puVar18 + iVar6) = 0;
      *(undefined4 *)((int)local_f8 + iVar6) = uVar3;
      iVar6 = iVar6 + 4;
      iVar22 = iVar22 + -1;
    } while (iVar22 != 0);
    piVar9 = local_138 + 2;
    piVar13 = local_11c;
    local_68 = local_138;
    iVar22 = param_1 + 0x170;
    iVar15 = param_1 + 0x224;
    iVar6 = 0x18;
    local_84 = 0;
    local_80 = piVar9;
    local_78 = piVar13;
    for (iVar16 = 1; iVar8 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))(), iVar16 <= iVar8;
        iVar16 = iVar16 + 1) {
      iVar8 = *(int *)(param_1 + 0xb0);
      if ((iVar16 < 1) || (iVar11 = FUN_00105594(iVar8,iVar16), iVar11 == 0)) {
        uVar5 = *(undefined4 *)(iVar6 + iVar8 + 0x98);
      }
      else {
        iVar8 = FUN_00105594(iVar8,iVar16);
        uVar5 = *(undefined4 *)(iVar8 + 0x98);
      }
      iVar8 = FUN_0012678c(uVar5);
      if (iVar8 == 0) {
        pcVar20 = (char *)(iVar15 + 4);
        piVar12 = (int *)(iVar22 + 8);
        iVar8 = 0;
        do {
          if (*pcVar20 != '\0') {
            iVar11 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),iVar16);
            piVar4 = local_68;
            bVar2 = *(byte *)(iVar8 + iVar11 + 0x10);
            iVar11 = (uint)bVar2 + iVar16 * 4;
            *(undefined1 *)((int)local_68 + iVar11 + 0x2c) = 0;
            *(byte *)((int)local_68 + iVar11 + 0x40) = bVar2;
            if (*piVar12 < 0) {
              pfVar10 = (float *)FUN_00173360(*(undefined4 *)(param_1 + 0x238));
              iVar7 = (**(code **)(**(int **)(*(int *)(param_1 + 0x238) + 0x30c) + 0xf0))
                                ((double)*pfVar10);
              if (iVar7 != 0) {
                if (*piVar9 == 0) {
                  iVar7 = FUN_00179138(param_1,iVar16);
                  *piVar9 = iVar7;
                  *piVar13 = 1;
                  local_84 = 1;
                }
                uVar24 = ((int (*)())FUN_00176474)((double)*pfVar10,iVar7,local_70,iVar16);
                iVar7 = (int)((ulonglong)uVar24 >> 0x20);
                if (*piVar13 < iVar7) {
                  FUN_0010bd50((double)*pfVar10,*piVar9,(int)uVar24,iVar7,
                               *(undefined4 *)(param_1 + 0x238));
                  *piVar13 = iVar7;
                }
                (**(code **)(*(int *)*piVar9 + 0x88))((int *)*piVar9,iVar7,(uint)bVar2,iVar8);
                *(undefined1 *)((int)piVar4 + iVar11 + 0x40) = 4;
              }
            }
          }
          bVar1 = iVar8 != 3;
          pcVar20 = pcVar20 + 1;
          piVar12 = piVar12 + 1;
          iVar8 = iVar8 + 1;
        } while (bVar1);
      }
      iVar6 = iVar6 + 0x18;
      iVar15 = iVar15 + 4;
      iVar22 = iVar22 + 0x10;
      piVar9 = piVar9 + 1;
      piVar13 = piVar13 + 1;
    }
    iVar6 = 0;
    iVar22 = 5;
    do {
      puVar18 = local_7c;
      if (*(int *)((int)local_138 + iVar6 + 4) == 0) {
        uVar5 = *(undefined4 *)(((unsigned char *)0x000050a8) + (int)local_74);
        *(undefined4 *)((int)local_10c + iVar6) = *(undefined4 *)(((unsigned char *)0x0000509c) + (int)local_6c);
        *(undefined4 *)(puVar18 + iVar6) = 0;
        *(undefined4 *)((int)local_f8 + iVar6) = uVar5;
      }
      iVar6 = iVar6 + 4;
      iVar22 = iVar22 + -1;
    } while (iVar22 != 0);
    piVar9 = *(int **)(param_1 + 0xb0);
    if ((((piVar9[5] & 0x200U) != 0) && (piVar9[0x48] == 0)) && (piVar9[0x49] == 0)) {
      iVar6 = FUN_001789f0(param_1);
      if (iVar6 != 0) {
        iVar22 = 0;
        iVar6 = param_1;
        do {
          iVar15 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
          if (*(char *)(iVar22 + iVar15 + 0x10) == '\x01') {
            iVar15 = *(int *)(param_1 + 0xb0);
            puVar21 = *(uint **)(*(int *)(*(int *)(iVar15 + 0x84) * 0x18 + iVar15 + 0x8c) + 0x2c);
            uVar19 = puVar21[1];
            uVar17 = uVar19 - 1;
            if (uVar17 < *puVar21) {
              if (uVar19 <= uVar17) {
                _memset((void *)(uVar19 * 4 + puVar21[2]),0,(uVar17 - uVar19) * 4 + 4);
                puVar21[1] = uVar19;
                iVar15 = *(int *)(param_1 + 0xb0);
              }
              piVar9 = (int *)(uVar17 * 4 + puVar21[2]);
            }
            else {
              piVar9 = (int *)FUN_0019423c(puVar21,uVar17);
              iVar15 = *(int *)(param_1 + 0xb0);
            }
            iVar16 = *piVar9;
            iVar15 = FUN_001054ec(iVar15,0);
            local_138[0] = *(int *)(iVar15 + 0x10);
            if (*(int *)(iVar22 * 4 + iVar16 + 0x20) < 0) {
              pfVar10 = (float *)FUN_00173360(*(undefined4 *)(param_1 + 0x238));
              iVar15 = (**(code **)(**(int **)(*(int *)(param_1 + 0x238) + 0x30c) + 0xf0))
                                 ((double)*pfVar10);
              if (iVar15 != 0) {
                piVar9 = local_80;
                piVar13 = local_78;
                for (iVar15 = 1; iVar16 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))(),
                    iVar15 <= iVar16; iVar15 = iVar15 + 1) {
                  if (*piVar9 == 0) {
                    iVar8 = FUN_00179138(param_1,iVar15);
                    iVar16 = iVar15 * 4;
                    *piVar9 = iVar8;
                    *piVar13 = 1;
                    puVar18 = (undefined1 *)((int)local_f8 + iVar15 * 4);
                    puVar14 = local_10c + iVar15;
                    iVar8 = 0;
                    do {
                      if (*(char *)((int)local_138 + iVar8) == '\0') {
                        iVar11 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),iVar15);
                        *puVar18 = *(undefined1 *)(iVar8 + iVar11 + 0x10);
                        *(undefined1 *)puVar14 = 0;
                        (**(code **)(**(int **)(param_1 + 0xb0) + 0x88))
                                  (*(int **)(param_1 + 0xb0),iVar15,iVar8,iVar8);
                      }
                      bVar1 = iVar8 != 3;
                      puVar18 = puVar18 + 1;
                      puVar14 = (undefined4 *)((int)puVar14 + 1);
                      iVar8 = iVar8 + 1;
                    } while (bVar1);
                    local_84 = 1;
                  }
                  else {
                    iVar16 = iVar15 << 2;
                  }
                  uVar5 = ((float * (*)())FUN_0010b93c)(&local_88,*(undefined4 *)(param_1 + 0xb0),iVar15,*pfVar10,
                                       *(undefined4 *)(param_1 + 0x238));
                  dVar23 = (double)local_88[0];
                  uVar24 = ((int (*)())FUN_00176474)(dVar23,uVar5,local_70,iVar15);
                  iVar8 = (int)((ulonglong)uVar24 >> 0x20);
                  if (*piVar13 < iVar8) {
                    FUN_0010bd50(dVar23,*piVar9,(int)uVar24,iVar8,*(undefined4 *)(param_1 + 0x238));
                    *piVar13 = iVar8;
                  }
                  piVar13 = piVar13 + 1;
                  iVar11 = FUN_000f3108(*(undefined4 *)((int)local_10c + iVar16));
                  piVar12 = (int *)*piVar9;
                  piVar9 = piVar9 + 1;
                  (**(code **)(*piVar12 + 0x88))(piVar12,iVar8,iVar11,iVar11);
                  *(undefined1 *)((int)local_10c + iVar11 + iVar16) = 0;
                  (**(code **)(**(int **)(param_1 + 0xb0) + 0x88))
                            (*(int **)(param_1 + 0xb0),iVar15,iVar22,iVar11);
                }
                *(undefined1 *)(iVar22 + *(int *)(param_1 + 0xb0) + 0x9c) = 0;
                *(float **)(iVar6 + 0x30) = pfVar10;
              }
            }
          }
          bVar1 = iVar22 != 3;
          iVar6 = iVar6 + 4;
          iVar22 = iVar22 + 1;
        } while (bVar1);
      }
      piVar9 = *(int **)(param_1 + 0xb0);
    }
    iVar6 = 1;
    while (iVar22 = (**(code **)(*piVar9 + 0x14))(), iVar6 <= iVar22) {
      iVar22 = iVar6 + 1;
      iVar15 = local_138[iVar22];
      if (iVar15 != 0) {
        *(int *)(iVar15 + 0x9c) = local_11c[iVar6 + 4];
        uVar5 = (uStack_fc)[iVar22];
        iVar6 = FUN_001054ec(iVar15,1);
        *(undefined4 *)(iVar6 + 0x10) = uVar5;
        FUN_0010c37c(iVar15,*(undefined4 *)(param_1 + 0x238));
      }
      piVar9 = *(int **)(param_1 + 0xb0);
      iVar6 = iVar22;
    }
    piVar9 = local_138 + 2;
    for (iVar6 = 1; iVar22 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))(), iVar6 <= iVar22;
        iVar6 = iVar6 + 1) {
      iVar22 = *piVar9;
      if (iVar22 != 0) {
        piVar13 = (int *)FUN_00105594(iVar22,1);
        iVar15 = (**(code **)(*piVar13 + 0x60))();
        if (iVar15 != 0) {
          uVar5 = FUN_00105594(iVar22,1);
          FUN_0010c670(uVar5,iVar22,*(undefined4 *)(param_1 + 0x238));
        }
      }
      piVar9 = piVar9 + 1;
    }
    piVar9 = local_138 + 2;
    iVar22 = 0x18;
    iVar6 = param_1;
    for (iVar15 = 1; iVar16 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))(), iVar15 <= iVar16;
        iVar15 = iVar15 + 1) {
      iVar16 = *piVar9;
      if (iVar16 != 0) {
        puVar21 = *(uint **)(*(int *)(iVar22 + *(int *)(param_1 + 0xb0) + 0x8c) + 0x2c);
        uVar17 = puVar21[1];
        uVar19 = uVar17 - 1;
        if (uVar19 < *puVar21) {
          if (uVar17 <= uVar19) {
            _memset((void *)(uVar17 * 4 + puVar21[2]),0,(uVar19 - uVar17) * 4 + 4);
            puVar21[1] = uVar17;
          }
          puVar14 = (undefined4 *)(uVar19 * 4 + puVar21[2]);
        }
        else {
          puVar14 = (undefined4 *)FUN_0019423c(puVar21,uVar19);
        }
        uVar5 = *puVar14;
        FUN_0017386c(uVar5);
        FUN_00173f1c(uVar5);
        FUN_00174e0c(uVar5);
        FUN_00175b40(uVar5);
        FUN_00173278(uVar5);
        *(int *)(iVar6 + 0x214) = iVar16;
      }
      piVar9 = piVar9 + 1;
      iVar22 = iVar22 + 0x18;
      iVar6 = iVar6 + 4;
    }
    if (local_84 != 0) {
      iVar6 = 4;
      do {
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
  }
  return local_84;
}

/* FUN_0017b96c @ 0x17b96c (748 bytes) */
int FUN_0017b96c(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint *puVar12;
  int iVar13;
  undefined4 local_38 [8];
  
  if ((*(int *)(*(int *)(param_1 + 0x238) + 0x658) <=
       *(int *)(*(int *)(*(int *)(param_1 + 0x238) + 0x6c4) + 0xa8)) ||
     (iVar3 = (**(code **)(**(int **)(param_1 + 0xb0) + 100))(), iVar3 == 0)) {
    return 0;
  }
  iVar3 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),1);
  iVar3 = FUN_000f3190(*(undefined4 *)(iVar3 + 0x10));
  if (iVar3 == 0) {
    iVar3 = *(int *)(param_1 + 0xb0);
    puVar12 = *(uint **)(*(int *)(iVar3 + 0xa4) + 0x2c);
    uVar9 = puVar12[1];
    uVar7 = uVar9 - 1;
    if (uVar7 < *puVar12) {
      if (uVar9 <= uVar7) {
        _memset((void *)(uVar9 * 4 + puVar12[2]),0,(uVar7 - uVar9) * 4 + 4);
        puVar12[1] = uVar9;
        iVar3 = *(int *)(param_1 + 0xb0);
      }
      piVar4 = (int *)(uVar7 * 4 + puVar12[2]);
    }
    else {
      piVar4 = (int *)FUN_0019423c(puVar12,uVar7);
      iVar3 = *(int *)(param_1 + 0xb0);
    }
    iVar10 = *piVar4;
    bVar2 = true;
    iVar13 = 0;
    iVar11 = iVar10;
    while( true ) {
      iVar3 = FUN_001054ec(iVar3,0);
      if (*(char *)(iVar13 + iVar3 + 0x10) != '\x01') {
        iVar3 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),1);
        iVar3 = FUN_00176264(*(undefined4 *)
                              ((uint)*(byte *)(iVar13 + iVar3 + 0x10) * 4 + iVar10 + 0x20),
                             *(undefined4 *)(iVar11 + 0x20));
        if (iVar3 == 0) {
          bVar2 = false;
        }
      }
      bVar1 = iVar13 == 3;
      iVar11 = iVar11 + 4;
      iVar13 = iVar13 + 1;
      if (bVar1) break;
      iVar3 = *(int *)(param_1 + 0xb0);
    }
    if (bVar2) {
      iVar3 = 0;
      local_38[0] = DAT_001b01dc;
      do {
        iVar11 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
        if (*(char *)(iVar3 + iVar11 + 0x10) != '\x01') {
          *(char *)((int)local_38 + iVar3) = (char)iVar3;
        }
        uVar8 = local_38[0];
        bVar2 = iVar3 != 3;
        iVar3 = iVar3 + 1;
      } while (bVar2);
      uVar6 = 1;
      iVar3 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),1);
      *(undefined4 *)(iVar3 + 0x10) = uVar8;
      goto LAB_0017bb2c;
    }
  }
  uVar6 = 0;
LAB_0017bb2c:
  iVar3 = *(int *)(param_1 + 0xb0);
  if ((*(int *)(iVar3 + 0x120) != 0) && (*(int *)(iVar3 + 0x124) == 0)) {
    puVar12 = *(uint **)(*(int *)(iVar3 + 0xa4) + 0x2c);
    uVar9 = puVar12[1];
    uVar7 = uVar9 - 1;
    if (uVar7 < *puVar12) {
      if (uVar9 <= uVar7) {
        _memset((void *)(uVar9 * 4 + puVar12[2]),0,(uVar7 - uVar9) * 4 + 4);
        puVar12[1] = uVar9;
        iVar3 = *(int *)(param_1 + 0xb0);
      }
      puVar5 = (undefined4 *)(uVar7 * 4 + puVar12[2]);
    }
    else {
      puVar5 = (undefined4 *)FUN_0019423c(puVar12,uVar7);
      iVar3 = *(int *)(param_1 + 0xb0);
    }
    uVar7 = *(uint *)(iVar3 + 0xb8);
    iVar11 = 0;
    uVar8 = *puVar5;
    while( true ) {
      iVar3 = FUN_001054ec(iVar3,0);
      if (*(char *)(iVar11 + iVar3 + 0x10) != '\x01') {
        iVar3 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),1);
        iVar3 = FUN_001764e0(uVar8,*(undefined1 *)(iVar11 + iVar3 + 0x10));
        if (iVar3 == 0) {
          return uVar6;
        }
        if ((uVar7 & 1) != 0) {
          return uVar6;
        }
      }
      bVar2 = iVar11 == 3;
      iVar11 = iVar11 + 1;
      if (bVar2) break;
      iVar3 = *(int *)(param_1 + 0xb0);
    }
    uVar6 = 1;
    *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x120) = 0;
  }
  return uVar6;
}

/* FUN_0017bc58 @ 0x17bc58 (288 bytes) */
int FUN_0017bc58(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  uint param_2;
  int param_3;
  undefined4 param_4;
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  uint local_28 [3];
  
  piVar1 = (int *)FUN_00105594(param_1,1);
  while( true ) {
    iVar3 = (**(code **)(*piVar1 + 0x40))(piVar1);
    if (iVar3 != 0) {
      return piVar1;
    }
    iVar3 = FUN_001054ec(piVar1,0);
    uVar4 = *(undefined4 *)(iVar3 + 0x10);
    iVar3 = FUN_00176534(param_1,piVar1);
    if (iVar3 == 2) break;
    if ((iVar3 == 0) && (FUN_000f3908(local_28,uVar4), (param_2 & local_28[0]) != DAT_001b01e0)) {
      return piVar1;
    }
    piVar1 = (int *)FUN_00105594(piVar1,3);
  }
  if ((param_3 != 0) && (piVar2 = (int *)FUN_00105594(param_1,1), piVar1 != piVar2)) {
    FUN_00106004(param_1,1,piVar1,0,param_4);
    return (int *)0x0;
  }
  return (int *)0x0;
}

/* FUN_0017bd78 @ 0x17bd78 (500 bytes) */
int FUN_0017bd78(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
{
  bool bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 local_58;
  
  iVar4 = *(int *)(param_1 + 0xb0);
  uVar8 = *(undefined4 *)(iVar4 + 4);
  uVar9 = *(undefined4 *)(iVar4 + 0x158);
  FUN_0019401c(iVar4);
  uVar13 = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c);
  iVar5 = FUN_001054ec(*(int *)(param_1 + 0xb0),0);
  iVar4 = *(int *)(param_1 + 0xb0);
  uVar11 = *(undefined4 *)(iVar5 + 0x10);
  uVar12 = *(undefined4 *)(param_2 * 0x18 + iVar4 + 0x8c);
  uVar14 = *(undefined4 *)(iVar4 + 0x120);
  iVar4 = FUN_001054ec(iVar4,param_2);
  iVar5 = *(int *)(param_1 + 0xb0);
  bVar2 = *(byte *)(param_3 + iVar4 + 0x10);
  uVar6 = *(uint *)(iVar5 + 0x14);
  uVar3 = *(uint *)(param_2 * 0x18 + iVar5 + 0xa0);
  uVar10 = *(undefined4 *)(param_2 * 4 + param_1 + 0x210);
  bVar1 = (uVar6 >> 9 & 1) == 0;
  if (bVar1) {
    uVar7 = 0;
    local_58 = 0;
  }
  else {
    local_58 = *(undefined4 *)(*(int *)(iVar5 + 0x84) * 4 + param_1 + 0x210);
    uVar7 = *(undefined4 *)(*(int *)(iVar5 + 0x84) * 0x18 + iVar5 + 0x8c);
  }
  uVar15 = *(undefined4 *)(iVar5 + 0x94);
  uVar16 = *(undefined4 *)(iVar5 + 0x98);
  FUN_00108448(iVar5,0x31,*(undefined4 *)(param_1 + 0x238));
  FUN_001046c8(iVar5,0,uVar13);
  *(undefined4 *)(iVar5 + 0x94) = uVar15;
  *(undefined4 *)(iVar5 + 0x98) = uVar16;
  *(undefined4 *)(iVar5 + 0x9c) = uVar11;
  *(undefined4 *)(iVar5 + 0x120) = uVar14;
  *(undefined4 *)(iVar5 + 0x124) = param_4;
  FUN_001046c8(iVar5,1,uVar12);
  uVar11 = *(undefined4 *)(PTR_DAT_001e8b8c + (uint)bVar2 * 4);
  iVar4 = FUN_001054ec(iVar5,1);
  *(undefined4 *)(iVar4 + 0x10) = uVar11;
  FUN_00103d50(iVar5 + 0xa4,1,uVar3 & 1);
  FUN_00103d50(iVar5 + 0xa4,2,uVar3 >> 1 & 1);
  *(undefined4 *)(param_1 + 0x214) = uVar10;
  if (bVar1) {
    *(undefined4 *)(param_1 + 0x218) = 0;
  }
  else {
    FUN_001049e8(iVar5,uVar7,*(undefined4 *)(param_1 + 0x238));
    *(uint *)(iVar5 + 0x14) = *(uint *)(iVar5 + 0x14) | 0x200;
    *(undefined4 *)(param_1 + 0x218) = local_58;
  }
  if ((uVar6 & 0x200000) != 0) {
    *(uint *)(iVar5 + 0x14) = *(uint *)(iVar5 + 0x14) | 0x200000;
  }
  FUN_000e7738(uVar9,uVar8,iVar5);
  return iVar5;
}

/* FUN_0017bf70 @ 0x17bf70 (392 bytes) */
int FUN_0017bf70(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  
  iVar8 = 2;
  iVar2 = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),0);
  iVar2 = *(int *)(iVar2 + 4);
  do {
    iVar3 = FUN_00176854(param_1,iVar8,1,1,1,0);
    if (iVar3 != 0) {
      iVar9 = 0;
      piVar10 = &DAT_001e6134;
      iVar3 = iVar8 * 4;
      do {
        if ((iVar2 == *(int *)((iVar3 + *piVar10) * 4 + param_1 + 0x168)) &&
           (iVar2 == *(int *)((iVar3 + piVar10[1]) * 4 + param_1 + 0x168))) {
          pfVar4 = (float *)FUN_00173360(*(undefined4 *)(param_1 + 0x238),
                                         *(undefined4 *)((iVar3 + piVar10[2]) * 4 + param_1 + 0x168)
                                        );
          if (*pfVar4 == 1.0) {
            iVar7 = *(int *)(*(int *)(param_1 + 0xb0) + 0x124);
LAB_0017c0b0:
            ((int (*)())FUN_0017bd78)(param_1,(iVar8 == 1) + '\x01',iVar9,iVar7);
            FUN_001745ac(param_1);
            return 1;
          }
          iVar7 = ((int (*)())FUN_0010ab40)();
          if (iVar7 != 0) {
            piVar5 = *(int **)(*(int *)(param_1 + 0x238) + 0x30c);
            iVar7 = iVar7 + *(int *)(*(int *)(param_1 + 0xb0) + 0x124);
            iVar6 = (**(code **)(*piVar5 + 0xfc))(piVar5,iVar7);
            if (iVar6 != 0) goto LAB_0017c0b0;
          }
        }
        bVar1 = iVar9 != 2;
        piVar10 = piVar10 + 3;
        iVar9 = iVar9 + 1;
      } while (bVar1);
    }
    iVar8 = iVar8 + -1;
    if (iVar8 == 0) {
      return 0;
    }
  } while( true );
}

/* FUN_0017c0f8 @ 0x17c0f8 (332 bytes) */
int FUN_0017c0f8(param_1)
  int param_1;
{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar1 = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),0);
  iVar9 = *(int *)(iVar1 + 4);
  iVar1 = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),0x3f800000);
  cVar2 = '\x01';
  iVar5 = *(int *)(iVar1 + 4);
  iVar8 = 2;
  iVar1 = param_1 + 0x20;
  do {
    iVar7 = *(int *)(iVar1 + 0x16c);
    if ((((iVar9 == iVar7) && (iVar9 == *(int *)(iVar1 + 0x170))) &&
        (iVar9 == *(int *)(iVar1 + 0x174))) && (iVar5 == *(int *)(iVar1 + 0x168))) {
      uVar3 = 0;
      uVar4 = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x124);
      goto LAB_0017c1c4;
    }
    if (iVar9 == *(int *)(iVar1 + 0x168)) {
      iVar6 = *(int *)(iVar1 + 0x170);
      if (((iVar9 == iVar6) && (iVar6 == *(int *)(iVar1 + 0x174))) && (iVar5 == iVar7)) {
        uVar3 = 1;
        uVar4 = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x124);
        goto LAB_0017c1c4;
      }
      if (iVar9 == iVar7) {
        if ((iVar9 == *(int *)(iVar1 + 0x174)) && (iVar5 == iVar6)) {
          uVar3 = 2;
          uVar4 = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x124);
LAB_0017c1c4:
          ((int (*)())FUN_0017bd78)(param_1,cVar2,uVar3,uVar4);
          FUN_001745ac(param_1);
          return 1;
        }
        if ((iVar9 == iVar6) && (iVar5 == *(int *)(iVar1 + 0x174))) {
          uVar3 = 3;
          uVar4 = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x124);
          goto LAB_0017c1c4;
        }
      }
    }
    iVar8 = iVar8 + -1;
    iVar1 = iVar1 + -0x10;
    if (iVar8 < 1) {
      return 0;
    }
    cVar2 = (iVar8 == 1) + '\x01';
  } while( true );
}

/* FUN_0017c244 @ 0x17c244 (468 bytes) */
int FUN_0017c244(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 local_58;
  
  iVar3 = *(int *)(param_1 + 0xb0);
  uVar7 = *(undefined4 *)(iVar3 + 4);
  uVar8 = *(undefined4 *)(iVar3 + 0x158);
  FUN_0019401c(iVar3);
  uVar12 = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c);
  iVar4 = FUN_001054ec(*(int *)(param_1 + 0xb0),0);
  iVar3 = *(int *)(param_1 + 0xb0);
  uVar10 = *(undefined4 *)(iVar4 + 0x10);
  uVar11 = *(undefined4 *)(param_2 * 0x18 + iVar3 + 0x8c);
  uVar13 = *(undefined4 *)(iVar3 + 0x120);
  uVar14 = *(undefined4 *)(iVar3 + 0x124);
  iVar3 = FUN_001054ec(iVar3,param_2);
  iVar4 = *(int *)(param_1 + 0xb0);
  uVar15 = *(undefined4 *)(iVar3 + 0x10);
  uVar5 = *(uint *)(iVar4 + 0x14);
  uVar2 = *(uint *)(param_2 * 0x18 + iVar4 + 0xa0);
  uVar9 = *(undefined4 *)(param_2 * 4 + param_1 + 0x210);
  bVar1 = (uVar5 >> 9 & 1) == 0;
  if (bVar1) {
    uVar6 = 0;
    local_58 = 0;
  }
  else {
    local_58 = *(undefined4 *)(*(int *)(iVar4 + 0x84) * 4 + param_1 + 0x210);
    uVar6 = *(undefined4 *)(*(int *)(iVar4 + 0x84) * 0x18 + iVar4 + 0x8c);
  }
  uVar16 = *(undefined4 *)(iVar4 + 0x94);
  uVar17 = *(undefined4 *)(iVar4 + 0x98);
  FUN_00108448(iVar4,0x31,*(undefined4 *)(param_1 + 0x238));
  FUN_001046c8(iVar4,0,uVar12);
  *(undefined4 *)(iVar4 + 0x98) = uVar17;
  *(undefined4 *)(iVar4 + 0x94) = uVar16;
  *(undefined4 *)(iVar4 + 0x9c) = uVar10;
  *(undefined4 *)(iVar4 + 0x120) = uVar13;
  *(undefined4 *)(iVar4 + 0x124) = uVar14;
  FUN_001046c8(iVar4,1,uVar11);
  iVar3 = FUN_001054ec(iVar4,1);
  *(undefined4 *)(iVar3 + 0x10) = uVar15;
  FUN_00103d50(iVar4 + 0xa4,1,uVar2 & 1);
  FUN_00103d50(iVar4 + 0xa4,2,uVar2 >> 1 & 1);
  *(undefined4 *)(param_1 + 0x214) = uVar9;
  if (bVar1) {
    *(undefined4 *)(param_1 + 0x218) = 0;
  }
  else {
    FUN_001049e8(iVar4,uVar6,*(undefined4 *)(param_1 + 0x238));
    *(uint *)(iVar4 + 0x14) = *(uint *)(iVar4 + 0x14) | 0x200;
    *(undefined4 *)(param_1 + 0x218) = local_58;
  }
  if ((uVar5 & 0x200000) != 0) {
    *(uint *)(iVar4 + 0x14) = *(uint *)(iVar4 + 0x14) | 0x200000;
  }
  FUN_000e7738(uVar8,uVar7,iVar4);
  return iVar4;
}

/* FUN_0017c41c @ 0x17c41c (136 bytes) */
int FUN_0017c41c(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = ((int (*)())FUN_00179c44)(param_1,2,3);
  if (iVar2 != 0) {
    uVar3 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xe8);
    uVar1 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xd0);
    if (((uVar1 & 1) == (uVar3 & 1)) && ((uVar1 >> 1 & 1) == (uVar3 >> 1 & 1))) {
      ((int (*)())FUN_0017c244)(param_1,2);
      FUN_001745ac(param_1);
      return 1;
    }
  }
  return 0;
}

/* FUN_0017c4a4 @ 0x17c4a4 (316 bytes) */
int FUN_0017c4a4(param_1)
  int param_1;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = (**(code **)(**(int **)(*(int *)(param_1 + 0x238) + 0x30c) + 0x88))();
  if (((iVar3 == 0) || (iVar3 = ((int (*)())FUN_00179c44)(param_1,2,3), iVar3 == 0)) ||
     (iVar3 = ((int (*)())FUN_00179c44)(param_1,1,3), iVar3 == 0)) {
    return 0;
  }
  iVar3 = *(int *)(param_1 + 0xb0);
  if ((*(uint *)(iVar3 + 0xb8) & 2) != 0) {
    return 0;
  }
  if ((*(uint *)(iVar3 + 0xd0) & 2) != 0) {
    return 0;
  }
  if ((*(uint *)(iVar3 + 0xe8) & 2) != 0) {
    return 0;
  }
  uVar1 = *(uint *)(iVar3 + 0xe8) & 1;
  uVar2 = *(uint *)(iVar3 + 0xd0) & 1;
  if ((*(uint *)(iVar3 + 0xb8) & 1) == 0) {
    if (uVar2 != 0) {
      return 0;
    }
    if (uVar1 == 0) {
      return 0;
    }
  }
  else {
    if (uVar2 == 0) {
      if (uVar1 == 0) {
        return 0;
      }
      ((int (*)())FUN_0017c244)(param_1,2);
      FUN_00103d50(*(int *)(param_1 + 0xb0) + 0xa4,2,1);
      iVar3 = *(int *)(param_1 + 0xb0);
      uVar4 = 1;
      goto LAB_0017c5b4;
    }
    if (uVar1 != 0) {
      return 0;
    }
  }
  ((int (*)())FUN_0017c244)(param_1,2);
  iVar3 = *(int *)(param_1 + 0xb0);
  uVar4 = 2;
LAB_0017c5b4:
  FUN_00103d50(iVar3 + 0xa4,uVar4,1);
  FUN_001745ac(param_1);
  return 1;
}

/* FUN_0017c5e0 @ 0x17c5e0 (404 bytes) */
int FUN_0017c5e0(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  bVar2 = false;
  iVar3 = FUN_00176324(0);
  iVar8 = 0;
  iVar7 = -1;
  iVar9 = param_1;
  do {
    iVar4 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
    iVar6 = iVar7;
    if (*(char *)(iVar8 + iVar4 + 0x10) != '\x01') {
      if (*(int *)(iVar9 + 0x178) < 0) {
        puVar5 = (undefined4 *)FUN_00173360(*(undefined4 *)(param_1 + 0x238));
        iVar6 = FUN_00176324(*puVar5);
        iVar4 = *(int *)(param_1 + 0xb0);
      }
      else {
        if (*(int *)(iVar9 + 0x178) < 1) {
          return 0;
        }
        iVar6 = FUN_00173330(*(undefined4 *)(param_1 + 0x238));
        iVar4 = *(int *)(param_1 + 0xb0);
        iVar6 = *(int *)(iVar6 + 0xc);
        if ((*(uint *)(iVar4 + 0xb8) & 2) != 0) {
          iVar6 = (DAT_001e61d0)[iVar6];
        }
        bVar2 = true;
        if ((*(uint *)(iVar4 + 0xb8) & 1) != 0) {
          iVar6 = *(int *)(&DAT_001e61b8 + iVar6 * 4);
        }
      }
      iVar4 = FUN_0010b5f8(iVar4);
      iVar6 = *(int *)(&DAT_001e61e8 + (iVar4 * 6 + iVar6 * 0x30 + iVar3) * 4);
      if (iVar6 == 1) {
        iVar6 = 2;
      }
      else if (iVar6 == 2) {
        iVar6 = 3;
      }
      else {
        if (iVar6 == 0) {
          return 0;
        }
        iVar6 = 0;
      }
      if ((iVar7 != -1) && (bVar1 = iVar6 != iVar7, iVar6 = iVar7, bVar1)) {
        return 0;
      }
    }
    bVar1 = iVar8 == 3;
    iVar9 = iVar9 + 4;
    iVar8 = iVar8 + 1;
    iVar7 = iVar6;
    if (bVar1) {
      if (bVar2) {
        iVar7 = *(int *)(*(int *)(param_1 + 0x238) + 0x6c4);
        *(int *)(iVar7 + 0x134) = *(int *)(iVar7 + 0x134) + 1;
      }
      ((int (*)())FUN_0017c244)(param_1,iVar6);
      FUN_001745ac(param_1);
      return 1;
    }
  } while( true );
}

/* FUN_0017c774 @ 0x17c774 (276 bytes) */
int FUN_0017c774(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = 1;
  iVar2 = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),0x3f800000);
  uVar4 = *(undefined4 *)(iVar2 + 4);
  do {
    iVar2 = FUN_00177064(param_1,uVar4,iVar3);
    if (iVar2 != 0) {
      ((int (*)())FUN_0017c244)(param_1,(iVar3 == 1) + '\x01');
      FUN_001745ac(param_1);
      return 1;
    }
    bVar1 = iVar3 != 2;
    iVar3 = iVar3 + 1;
  } while (bVar1);
  iVar3 = 1;
  iVar2 = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),0xbf800000);
  uVar4 = *(undefined4 *)(iVar2 + 4);
  do {
    iVar2 = FUN_00177064(param_1,uVar4,iVar3);
    if (iVar2 != 0) {
      iVar2 = (iVar3 == 1) + 1;
      ((int (*)())FUN_0017c244)(param_1,iVar2);
      FUN_00103d50(*(int *)(param_1 + 0xb0) + 0xa4,1,
                   *(uint *)(iVar2 * 0x18 + *(int *)(param_1 + 0xb0) + 0xa0) & 1 ^ 1);
      FUN_001745ac(param_1);
      return 1;
    }
    bVar1 = iVar3 != 2;
    iVar3 = iVar3 + 1;
  } while (bVar1);
  return 0;
}

/* FUN_0017c888 @ 0x17c888 (136 bytes) */
int FUN_0017c888(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = ((int (*)())FUN_00179c44)(param_1,1,2);
  if (iVar2 != 0) {
    uVar3 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xd0);
    uVar1 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xb8);
    if (((uVar1 & 1) == (uVar3 & 1)) && ((uVar1 >> 1 & 1) == (uVar3 >> 1 & 1))) {
      ((int (*)())FUN_0017c244)(param_1,1);
      FUN_001745ac(param_1);
      return 1;
    }
  }
  return 0;
}

/* FUN_0017c910 @ 0x17c910 (516 bytes) */
int FUN_0017c910(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  int *piVar14;
  int local_64 [10];
  
  bVar2 = false;
  iVar10 = 0;
  iVar11 = param_1 + 0x170;
  iVar8 = -1;
  do {
    iVar4 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
    iVar9 = iVar8;
    if (*(char *)(iVar10 + iVar4 + 0x10) != '\x01') {
      piVar13 = (int *)(iVar11 + 8);
      piVar14 = local_64;
      iVar12 = 0x98;
      for (iVar4 = 1; iVar6 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))(), iVar4 <= iVar6;
          iVar4 = iVar4 + 1) {
        if (*piVar13 < 0) {
          puVar5 = (undefined4 *)FUN_00173360(*(undefined4 *)(param_1 + 0x238));
          iVar6 = FUN_00176324(*puVar5);
          *piVar14 = iVar6;
        }
        else {
          if (*piVar13 < 1) {
            return 0;
          }
          iVar6 = FUN_00173330(*(undefined4 *)(param_1 + 0x238));
          iVar6 = *(int *)(iVar6 + 0xc);
          *piVar14 = iVar6;
          iVar7 = *(int *)(param_1 + 0xb0) + iVar12;
          uVar3 = *(uint *)(iVar7 + 0x20);
          if ((uVar3 & 2) != 0) {
            *piVar14 = (DAT_001e61d0)[iVar6];
            uVar3 = *(uint *)(iVar7 + 0x20);
          }
          bVar2 = true;
          if ((uVar3 & 1) != 0) {
            *piVar14 = *(int *)(&DAT_001e61b8 + *piVar14 * 4);
          }
        }
        iVar12 = iVar12 + 0x18;
        piVar14 = piVar14 + 1;
        piVar13 = piVar13 + 4;
      }
      if ((local_64[0] != 3) || (local_64[1] != 3)) {
        iVar9 = *(int *)(&DAT_001e6014 + (local_64[0] * 6 + local_64[1]) * 4);
        if (iVar9 == 1) {
          iVar9 = 1;
        }
        else if (iVar9 == 2) {
          iVar9 = 2;
        }
        else {
          if (iVar9 == 0) {
            return 0;
          }
          iVar9 = 0;
        }
        if ((iVar8 != -1) && (bVar1 = iVar9 != iVar8, iVar9 = iVar8, bVar1)) {
          return 0;
        }
      }
    }
    bVar1 = iVar10 == 3;
    iVar11 = iVar11 + 4;
    iVar10 = iVar10 + 1;
    iVar8 = iVar9;
    if (bVar1) {
      if (iVar9 == -1) {
        iVar9 = 1;
      }
      if (bVar2) {
        iVar8 = *(int *)(*(int *)(param_1 + 0x238) + 0x6c4);
        *(int *)(iVar8 + 0x134) = *(int *)(iVar8 + 0x134) + 1;
      }
      ((int (*)())FUN_0017c244)(param_1,iVar9);
      FUN_001745ac(param_1);
      return 1;
    }
  } while( true );
}

/* FUN_0017cb14 @ 0x17cb14 (516 bytes) */
int FUN_0017cb14(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  int *piVar14;
  int local_64 [10];
  
  bVar2 = false;
  iVar10 = 0;
  iVar11 = param_1 + 0x170;
  iVar8 = -1;
  do {
    iVar4 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
    iVar9 = iVar8;
    if (*(char *)(iVar10 + iVar4 + 0x10) != '\x01') {
      piVar13 = (int *)(iVar11 + 8);
      piVar14 = local_64;
      iVar12 = 0x98;
      for (iVar4 = 1; iVar6 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))(), iVar4 <= iVar6;
          iVar4 = iVar4 + 1) {
        if (*piVar13 < 0) {
          puVar5 = (undefined4 *)FUN_00173360(*(undefined4 *)(param_1 + 0x238));
          iVar6 = FUN_00176324(*puVar5);
          *piVar14 = iVar6;
        }
        else {
          if (*piVar13 < 1) {
            return 0;
          }
          iVar6 = FUN_00173330(*(undefined4 *)(param_1 + 0x238));
          iVar6 = *(int *)(iVar6 + 0xc);
          *piVar14 = iVar6;
          iVar7 = *(int *)(param_1 + 0xb0) + iVar12;
          uVar3 = *(uint *)(iVar7 + 0x20);
          if ((uVar3 & 2) != 0) {
            *piVar14 = (DAT_001e61d0)[iVar6];
            uVar3 = *(uint *)(iVar7 + 0x20);
          }
          bVar2 = true;
          if ((uVar3 & 1) != 0) {
            *piVar14 = *(int *)(&DAT_001e61b8 + *piVar14 * 4);
          }
        }
        iVar12 = iVar12 + 0x18;
        piVar14 = piVar14 + 1;
        piVar13 = piVar13 + 4;
      }
      if ((local_64[0] != 3) || (local_64[1] != 3)) {
        iVar9 = *(int *)(&DAT_001e60a4 + (local_64[0] * 6 + local_64[1]) * 4);
        if (iVar9 == 1) {
          iVar9 = 1;
        }
        else if (iVar9 == 2) {
          iVar9 = 2;
        }
        else {
          if (iVar9 == 0) {
            return 0;
          }
          iVar9 = 0;
        }
        if ((iVar8 != -1) && (bVar1 = iVar9 != iVar8, iVar9 = iVar8, bVar1)) {
          return 0;
        }
      }
    }
    bVar1 = iVar10 == 3;
    iVar11 = iVar11 + 4;
    iVar10 = iVar10 + 1;
    iVar8 = iVar9;
    if (bVar1) {
      if (iVar9 == -1) {
        iVar9 = 1;
      }
      if (bVar2) {
        iVar8 = *(int *)(*(int *)(param_1 + 0x238) + 0x6c4);
        *(int *)(iVar8 + 0x134) = *(int *)(iVar8 + 0x134) + 1;
      }
      ((int (*)())FUN_0017c244)(param_1,iVar9);
      FUN_001745ac(param_1);
      return 1;
    }
  } while( true );
}

/* FUN_0017cd18 @ 0x17cd18 (164 bytes) */
int FUN_0017cd18(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar2 = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),0);
  iVar4 = 1;
  uVar3 = *(undefined4 *)(iVar2 + 4);
  do {
    iVar2 = FUN_00177064(param_1,uVar3,iVar4);
    if (iVar2 != 0) {
      iVar2 = FUN_0017737c(param_1,0,3);
      if (iVar2 == 0) {
        ((int (*)())FUN_0017c244)(param_1,3);
      }
      else {
        FUN_00177548(param_1);
      }
      FUN_001745ac(param_1);
      return 1;
    }
    bVar1 = iVar4 != 2;
    iVar4 = iVar4 + 1;
  } while (bVar1);
  return 0;
}

/* FUN_0017cdbc @ 0x17cdbc (192 bytes) */
int FUN_0017cdbc(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  iVar2 = 1;
  iVar1 = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),0);
  uVar4 = *(undefined4 *)(iVar1 + 4);
  do {
    uVar3 = 2;
    do {
      iVar1 = FUN_00177064(param_1,uVar4,iVar2);
      if (iVar1 != 0) {
        iVar1 = FUN_0017737c(param_1,0,uVar3);
        if (iVar1 == 0) {
          ((int (*)())FUN_0017c244)(param_1,uVar3);
        }
        else {
          FUN_00177548(param_1);
        }
        FUN_001745ac(param_1);
        return 1;
      }
      iVar2 = iVar2 + 1;
      if (2 < iVar2) {
        return 0;
      }
      uVar3 = 1;
    } while (iVar2 != 1);
  } while( true );
}

/* FUN_0017ce7c @ 0x17ce7c (492 bytes) */
int FUN_0017ce7c(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  int iVar16;
  
  iVar3 = *(int *)(param_1 + 0xb0);
  uVar8 = *(undefined4 *)(iVar3 + 4);
  uVar9 = *(undefined4 *)(iVar3 + 0x158);
  FUN_0019401c(iVar3);
  uVar13 = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c);
  iVar3 = FUN_001054ec(*(int *)(param_1 + 0xb0),0);
  iVar16 = *(int *)(param_1 + 0xb0);
  uVar12 = *(undefined4 *)(iVar3 + 0x10);
  uVar2 = *(uint *)(iVar16 + 0x14);
  uVar10 = *(undefined4 *)(iVar16 + 0x120);
  uVar11 = *(undefined4 *)(iVar16 + 0x124);
  bVar1 = (uVar2 >> 9 & 1) == 0;
  if (bVar1) {
    uVar6 = 0;
    uVar7 = 0;
  }
  else {
    uVar6 = *(undefined4 *)(*(int *)(iVar16 + 0x84) * 4 + param_1 + 0x210);
    uVar7 = *(undefined4 *)(*(int *)(iVar16 + 0x84) * 0x18 + iVar16 + 0x8c);
  }
  uVar14 = *(undefined4 *)(iVar16 + 0x94);
  uVar15 = *(undefined4 *)(iVar16 + 0x98);
  FUN_00108448(iVar16,0x31,*(undefined4 *)(param_1 + 0x238));
  FUN_001046c8(iVar16,0,uVar13);
  *(undefined4 *)(iVar16 + 0x98) = uVar15;
  *(undefined4 *)(iVar16 + 0x94) = uVar14;
  *(undefined4 *)(iVar16 + 0x9c) = uVar12;
  *(undefined4 *)(iVar16 + 0x120) = uVar10;
  *(undefined4 *)(iVar16 + 0x124) = uVar11;
  FUN_001046c8(iVar16,1,*(undefined4 *)(param_2 + 0xc));
  uVar12 = *(undefined4 *)(PTR_DAT_001e8b8c + *(int *)(param_2 + 0x10) * 4);
  iVar3 = FUN_001054ec(iVar16,1);
  *(undefined4 *)(iVar3 + 0x10) = uVar12;
  if (*(int *)(param_2 + 0x18) != 0) {
    FUN_00103d50(iVar16 + 0xa4,1,1);
  }
  *(undefined4 *)(iVar16 + 0x120) = uVar10;
  *(undefined4 *)(iVar16 + 0x124) = uVar11;
  piVar4 = *(int **)(*(int *)(iVar16 + 0xa4) + 0x18);
  if (*piVar4 == 0) {
    puVar5 = (undefined4 *)FUN_0019423c(piVar4,0);
  }
  else {
    if (piVar4[1] == 0) {
      *(undefined4 *)piVar4[2] = 0;
      piVar4[1] = 1;
    }
    puVar5 = (undefined4 *)piVar4[2];
  }
  *(undefined4 *)(param_1 + 0x214) = *puVar5;
  if (bVar1) {
    *(undefined4 *)(param_1 + 0x218) = 0;
  }
  else {
    FUN_001049e8(iVar16,uVar7,*(undefined4 *)(param_1 + 0x238));
    *(uint *)(iVar16 + 0x14) = *(uint *)(iVar16 + 0x14) | 0x200;
    *(undefined4 *)(param_1 + 0x218) = uVar6;
  }
  if ((uVar2 & 0x200000) != 0) {
    *(uint *)(iVar16 + 0x14) = *(uint *)(iVar16 + 0x14) | 0x200000;
  }
  FUN_000e7738(uVar9,uVar8,iVar16);
  return iVar16;
}

/* FUN_0017d06c @ 0x17d06c (476 bytes) */
int FUN_0017d06c(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 *param_3;
  undefined4 param_4;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int iVar13;
  
  iVar3 = *(int *)(param_1 + 0xb0);
  uVar7 = *(undefined4 *)(iVar3 + 4);
  uVar8 = *(undefined4 *)(iVar3 + 0x158);
  FUN_0019401c(iVar3);
  uVar11 = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c);
  iVar3 = FUN_001054ec(*(int *)(param_1 + 0xb0),0);
  iVar13 = *(int *)(param_1 + 0xb0);
  uVar9 = *(undefined4 *)(iVar3 + 0x10);
  uVar2 = *(uint *)(iVar13 + 0x14);
  bVar1 = (uVar2 >> 9 & 1) == 0;
  if (bVar1) {
    uVar5 = 0;
    uVar6 = 0;
  }
  else {
    uVar5 = *(undefined4 *)(*(int *)(iVar13 + 0x84) * 4 + param_1 + 0x210);
    uVar6 = *(undefined4 *)(*(int *)(iVar13 + 0x84) * 0x18 + iVar13 + 0x8c);
  }
  uVar12 = *(undefined4 *)(iVar13 + 0x94);
  uVar10 = *(undefined4 *)(iVar13 + 0x98);
  FUN_00108448(iVar13,0x31,*(undefined4 *)(param_1 + 0x238));
  FUN_001046c8(iVar13,0,uVar11);
  iVar3 = *(int *)(param_2 + 0x8c);
  *(undefined4 *)(iVar13 + 0x94) = uVar12;
  *(undefined4 *)(iVar13 + 0x98) = uVar10;
  *(undefined4 *)(iVar13 + 0x9c) = uVar9;
  if (*(int *)(*(int *)(iVar3 + 0x2c) + 4) == 0) {
    uVar9 = *(undefined4 *)(*(int *)(param_1 + 0x238) + 0x378);
    puVar4 = (undefined4 *)FUN_00193e18(uVar9,0x240);
    *puVar4 = uVar9;
    puVar4 = puVar4 + 1;
    FUN_00173938(puVar4,param_2,*(undefined4 *)(param_1 + 0x238));
    FUN_00174e0c(puVar4);
    FUN_00173278(puVar4);
    FUN_00123424(iVar3,*(undefined4 *)(*(int *)(param_2 + 0x158) + 0xb0),puVar4);
  }
  FUN_001046c8(iVar13,1,iVar3);
  uVar9 = *param_3;
  iVar3 = FUN_001054ec(iVar13,1);
  *(undefined4 *)(iVar3 + 0x10) = uVar9;
  FUN_00103d50(iVar13 + 0xa4,1,param_4);
  *(int *)(param_1 + 0x214) = param_2;
  if (bVar1) {
    *(undefined4 *)(param_1 + 0x218) = 0;
  }
  else {
    FUN_001049e8(iVar13,uVar6,*(undefined4 *)(param_1 + 0x238));
    *(uint *)(iVar13 + 0x14) = *(uint *)(iVar13 + 0x14) | 0x200;
    *(undefined4 *)(param_1 + 0x218) = uVar5;
  }
  if ((uVar2 & 0x200000) != 0) {
    *(uint *)(iVar13 + 0x14) = *(uint *)(iVar13 + 0x14) | 0x200000;
  }
  FUN_000e7738(uVar8,uVar7,iVar13);
  return iVar13;
}

/* FUN_0017d26c @ 0x17d26c (392 bytes) */
int FUN_0017d26c(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  undefined4 uVar14;
  
  iVar3 = *(int *)(param_1 + 0xb0);
  uVar6 = *(undefined4 *)(iVar3 + 4);
  uVar7 = *(undefined4 *)(iVar3 + 0x158);
  FUN_0019401c(iVar3);
  uVar10 = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c);
  iVar3 = FUN_001054ec(*(int *)(param_1 + 0xb0),0);
  iVar11 = *(int *)(param_1 + 0xb0);
  uVar9 = *(undefined4 *)(iVar3 + 0x10);
  uVar2 = *(uint *)(iVar11 + 0x14);
  bVar1 = (uVar2 >> 9 & 1) == 0;
  if (bVar1) {
    uVar5 = 0;
    uVar8 = 0;
  }
  else {
    uVar5 = *(undefined4 *)(*(int *)(iVar11 + 0x84) * 4 + param_1 + 0x210);
    uVar8 = *(undefined4 *)(*(int *)(iVar11 + 0x84) * 0x18 + iVar11 + 0x8c);
  }
  uVar12 = *(undefined4 *)(iVar11 + 0x94);
  uVar14 = *(undefined4 *)(iVar11 + 0x98);
  FUN_00108448(iVar11,0x31,*(undefined4 *)(param_1 + 0x238));
  FUN_001046c8(iVar11,0,uVar10);
  *(undefined4 *)(iVar11 + 0x94) = uVar12;
  *(undefined4 *)(iVar11 + 0x98) = uVar14;
  if (bVar1) {
    *(undefined4 *)(param_1 + 0x218) = 0;
  }
  else {
    FUN_001049e8(iVar11,uVar8,*(undefined4 *)(param_1 + 0x238));
    *(uint *)(iVar11 + 0x14) = *(uint *)(iVar11 + 0x14) | 0x200;
    *(undefined4 *)(param_1 + 0x218) = uVar5;
  }
  *(undefined4 *)(iVar11 + 0x9c) = uVar9;
  iVar13 = 0;
  uVar9 = ((int (*)())FUN_0017a130)(1,param_2,iVar11,*(undefined4 *)(param_1 + 0x238));
  *(undefined4 *)(param_1 + 0x214) = uVar9;
  iVar3 = param_1;
  do {
    iVar4 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
    if (*(char *)(iVar13 + iVar4 + 0x10) == '\x01') {
      *(undefined4 *)(iVar3 + 0x30) = 0;
    }
    bVar1 = iVar13 != 3;
    iVar3 = iVar3 + 4;
    iVar13 = iVar13 + 1;
  } while (bVar1);
  if ((uVar2 & 0x200000) != 0) {
    *(uint *)(iVar11 + 0x14) = *(uint *)(iVar11 + 0x14) | 0x200000;
  }
  FUN_000e7738(uVar7,uVar6,iVar11);
  return iVar11;
}

/* FUN_0017d3f8 @ 0x17d3f8 (232 bytes) */
int FUN_0017d3f8(param_1)
  int param_1;
{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  undefined4 local_28 [8];
  
  iVar2 = ((int (*)())FUN_00179c44)(param_1,1,2);
  if (iVar2 != 0) {
    uVar3 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xb8);
    uVar5 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xd0);
    if (((uVar3 & 1) == (uVar5 & 1)) && ((uVar3 >> 1 & 1) == (uVar5 >> 1 & 1))) {
      iVar2 = ((bool (*)())FUN_0010b820)((double)FLOAT_001aa0d4,(double)FLOAT_001aa0d4);
      uVar4 = 0x3f800000;
      if (iVar2 == 0) {
        uVar4 = 0;
      }
      iVar2 = 4;
      puVar1 = local_28;
      do {
        *puVar1 = 0x7ffffffe;
        puVar1 = puVar1 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      iVar2 = 0;
      iVar6 = 4;
      do {
        *(undefined4 *)(iVar2 + (int)local_28) = uVar4;
        iVar2 = iVar2 + 4;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      ((int (*)())FUN_0017d26c)(param_1);
      FUN_001745ac(param_1);
      return 1;
    }
  }
  return 0;
}

/* FUN_0017d4e0 @ 0x17d4e0 (156 bytes) */
int FUN_0017d4e0(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  iVar2 = FUN_00176fd4(param_1,1,2);
  if (iVar2 != 0) {
    uVar3 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xd0);
    uVar1 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xb8);
    if (((uVar1 & 1) == (uVar3 & 1)) && ((uVar1 >> 1 & 1) == (uVar3 >> 1 & 1))) {
      local_1c = 0;
      local_28 = 0;
      local_24 = 0;
      local_20 = 0;
      ((int (*)())FUN_0017d26c)(param_1,&local_28);
      FUN_001745ac(param_1);
      return 1;
    }
  }
  return 0;
}

/* FUN_0017d57c @ 0x17d57c (148 bytes) */
int FUN_0017d57c(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  iVar2 = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),0);
  iVar4 = 1;
  uVar3 = *(undefined4 *)(iVar2 + 4);
  do {
    iVar2 = FUN_00177064(param_1,uVar3,iVar4);
    if (iVar2 != 0) {
      local_2c = 0;
      local_38 = 0;
      local_34 = 0;
      local_30 = 0;
      ((int (*)())FUN_0017d26c)(param_1,&local_38);
      FUN_001745ac(param_1);
      return 1;
    }
    bVar1 = iVar4 != 2;
    iVar4 = iVar4 + 1;
  } while (bVar1);
  return 0;
}

/* FUN_0017d610 @ 0x17d610 (156 bytes) */
int FUN_0017d610(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  iVar2 = ((int (*)())FUN_00179c44)(param_1,1,2);
  if (iVar2 != 0) {
    uVar3 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xd0);
    uVar1 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xb8);
    if (((uVar1 & 1) != (uVar3 & 1)) && ((uVar1 >> 1 & 1) == (uVar3 >> 1 & 1))) {
      local_1c = 0;
      local_28 = 0;
      local_24 = 0;
      local_20 = 0;
      ((int (*)())FUN_0017d26c)(param_1,&local_28);
      FUN_001745ac(param_1);
      return 1;
    }
  }
  return 0;
}

/* FUN_0017d6ac @ 0x17d6ac (780 bytes) */
int FUN_0017d6ac(param_1, param_2)
  int param_1;
  float *param_2;
{
  bool bVar1;
  byte bVar2;
  float *pfVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  float *pfVar9;
  float fVar10;
  int iVar11;
  undefined4 local_58;
  float local_54 [4];
  float afStack_44 [3];
  undefined4 local_38;
  undefined4 local_34 [4];
  
  uVar8 = DAT_001b01d8;
  iVar5 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
  FUN_000f3908(&local_38,*(undefined4 *)(iVar5 + 0x10));
  FUN_000f3340(local_34,uVar8,local_38);
  local_58 = local_34[0];
  piVar6 = *(int **)(*(int *)(param_1 + 0x238) + 0x30c);
  iVar5 = (**(code **)(*piVar6 + 0x154))
                    (piVar6,*(undefined4 *)(*(int *)(param_1 + 0x238) + 0x6c4),param_2,&local_58);
  if (iVar5 == 0) {
    iVar5 = 4;
    pfVar3 = local_54;
    do {
      *pfVar3 = NAN;
      pfVar3 = pfVar3 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    iVar5 = 0;
    pfVar3 = local_54;
    pfVar9 = param_2;
    do {
      iVar7 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
      if (*(char *)(iVar5 + iVar7 + 0x10) != '\x01') {
        *pfVar3 = -*pfVar9;
      }
      bVar1 = iVar5 != 3;
      pfVar3 = pfVar3 + 1;
      pfVar9 = pfVar9 + 1;
      iVar5 = iVar5 + 1;
    } while (bVar1);
    piVar6 = *(int **)(*(int *)(param_1 + 0x238) + 0x30c);
    iVar5 = (**(code **)(*piVar6 + 0x154))
                      (piVar6,*(undefined4 *)(*(int *)(param_1 + 0x238) + 0x6c4),local_54,&local_58)
    ;
    if (iVar5 == 0) {
      fVar10 = NAN;
      iVar5 = 0;
      pfVar3 = param_2;
      do {
        iVar7 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
        if (*(char *)(iVar5 + iVar7 + 0x10) != '\x01') {
          FUN_00173e10(*(undefined4 *)(param_1 + 0x238),*pfVar3);
          if (fVar10 == NAN) {
            fVar10 = *pfVar3;
          }
          else if (fVar10 != *pfVar3) {
            return 0;
          }
        }
        bVar1 = iVar5 != 3;
        pfVar3 = pfVar3 + 1;
        iVar5 = iVar5 + 1;
      } while (bVar1);
      iVar5 = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),fVar10);
      if (*(byte *)(iVar5 + 8) == 0) {
        return 0;
      }
      bVar2 = *(byte *)(iVar5 + 9);
      if (((((bVar2 & 1) == 0) && ((bVar2 & 2) == 0)) && ((bVar2 & 4) == 0)) && ((bVar2 & 8) == 0))
      {
        if ((*(byte *)(iVar5 + 8) & 1) == 0) {
          iVar5 = ((int (*)())FUN_0017ce7c)(param_1,iVar5);
          return iVar5;
        }
        iVar5 = 0;
        iVar7 = 4;
        do {
          *(float *)((int)param_2 + iVar5) = fVar10;
          iVar5 = iVar5 + 4;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        iVar5 = ((int (*)())FUN_0017d26c)(param_1,param_2);
        return iVar5;
      }
      iVar7 = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),*(undefined4 *)(iVar5 + 0x14));
      pfVar3 = local_54;
      if ((*(byte *)(iVar7 + 8) & 1) == 0) {
        iVar7 = ((int (*)())FUN_0017ce7c)(param_1);
      }
      else {
        do {
          *pfVar3 = NAN;
          pfVar3 = pfVar3 + 1;
        } while (pfVar3 != afStack_44);
        iVar4 = 0;
        iVar11 = 4;
        do {
          *(undefined4 *)(iVar4 + (int)local_54) = *(undefined4 *)(iVar7 + 0x14);
          iVar4 = iVar4 + 4;
          iVar11 = iVar11 + -1;
        } while (iVar11 != 0);
        iVar7 = ((int (*)())FUN_0017d26c)(param_1,local_54);
      }
      bVar2 = *(byte *)(iVar5 + 9);
      if ((bVar2 & 1) != 0) {
        FUN_00103d50(iVar7 + 0xa4,1,1);
        bVar2 = *(byte *)(iVar5 + 9);
      }
      if ((bVar2 & 2) != 0) {
        *(undefined4 *)(iVar7 + 0x124) = *(undefined4 *)(iVar5 + 0x1c);
        return iVar7;
      }
      return iVar7;
    }
    uVar8 = 1;
  }
  else {
    uVar8 = 0;
  }
  iVar5 = ((int (*)())FUN_0017d06c)(param_1,iVar5,&local_58,uVar8);
  return iVar5;
}

/* FUN_0017d9b8 @ 0x17d9b8 (548 bytes) */
int FUN_0017d9b8(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int *piVar10;
  int iVar11;
  int *piVar12;
  int *piVar13;
  int iVar14;
  int iVar15;
  int local_64 [9];
  
  iVar14 = 4;
  piVar10 = local_64 + 2;
  piVar4 = piVar10;
  do {
    *piVar4 = 0x7ffffffe;
    piVar4 = piVar4 + 1;
    iVar14 = iVar14 + -1;
  } while (iVar14 != 0);
  iVar14 = 0;
  iVar15 = 4;
  do {
    *(undefined4 *)(iVar14 + (int)piVar10) = 0x7ffffffe;
    iVar14 = iVar14 + 4;
    iVar15 = iVar15 + -1;
  } while (iVar15 != 0);
  bVar2 = false;
  iVar14 = 0;
  iVar15 = param_1 + 0x170;
  piVar4 = piVar10;
  do {
    iVar5 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
    if (*(char *)(iVar14 + iVar5 + 0x10) != '\x01') {
      piVar13 = (int *)(iVar15 + 8);
      iVar5 = 1;
      piVar12 = local_64;
      iVar11 = 0x98;
      do {
        *piVar12 = 0;
        if (*piVar13 < 0) {
          puVar6 = (undefined4 *)FUN_00173360(*(undefined4 *)(param_1 + 0x238));
          iVar7 = FUN_00176324(*puVar6);
          *piVar12 = iVar7;
        }
        else {
          if (*piVar13 < 1) goto LAB_0017dbc4;
          iVar7 = FUN_00173330(*(undefined4 *)(param_1 + 0x238));
          iVar8 = *(int *)(iVar7 + 0xc);
          *piVar12 = iVar8;
          iVar7 = *(int *)(param_1 + 0xb0) + iVar11;
          uVar3 = *(uint *)(iVar7 + 0x20);
          if ((uVar3 & 2) != 0) {
            *piVar12 = (DAT_001e61d0)[iVar8];
            uVar3 = *(uint *)(iVar7 + 0x20);
          }
          if ((uVar3 & 1) == 0) {
            iVar7 = *piVar12;
            bVar2 = true;
          }
          else {
            bVar2 = true;
            iVar7 = *(int *)(&DAT_001e61b8 + *piVar12 * 4);
            *piVar12 = iVar7;
          }
        }
        iVar8 = local_64[0];
        if (iVar7 == 0) goto LAB_0017dbc4;
        bVar1 = iVar5 != 2;
        iVar11 = iVar11 + 0x18;
        piVar12 = piVar12 + 1;
        piVar13 = piVar13 + 4;
        iVar5 = iVar5 + 1;
      } while (bVar1);
      iVar5 = FUN_0010b5f8(*(undefined4 *)(param_1 + 0xb0));
      iVar5 = *(int *)(&DAT_001e61e8 + (iVar5 * 6 + iVar8 * 0x30 + local_64[1]) * 4);
      if (iVar5 == 1) {
        *piVar4 = 0x3f800000;
      }
      else if (iVar5 == 2) {
        *piVar4 = 0;
      }
      else if (iVar5 == 0) goto LAB_0017dbc4;
    }
    bVar1 = iVar14 != 3;
    iVar15 = iVar15 + 4;
    piVar4 = piVar4 + 1;
    iVar14 = iVar14 + 1;
  } while (bVar1);
  iVar14 = ((int (*)())FUN_0017d6ac)(param_1,piVar10);
  if (iVar14 == 0) {
LAB_0017dbc4:
    uVar9 = 0;
  }
  else {
    if (bVar2) {
      iVar14 = *(int *)(*(int *)(param_1 + 0x238) + 0x6c4);
      *(int *)(iVar14 + 0x134) = *(int *)(iVar14 + 0x134) + 1;
    }
    FUN_001745ac(param_1);
    uVar9 = 1;
  }
  return uVar9;
}

/* FUN_0017dbdc @ 0x17dbdc (1104 bytes) */
int FUN_0017dbdc(param_1, param_2)
  int param_1;
  int *param_2;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  int local_58 [4];
  int local_48;
  int local_44;
  int local_40;
  int local_3c [6];
  
  uVar6 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8);
  iVar2 = FUN_00176564(uVar6);
  if (iVar2 != 0) {
    return 0;
  }
  iVar2 = FUN_00176574(uVar6);
  if (iVar2 == 0) {
    iVar4 = FUN_00113174(uVar6,*(undefined4 *)(param_1 + 0x238));
    if ((iVar4 == 0) ||
       (iVar4 = FUN_001131c0(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8),
                             *(undefined4 *)(param_1 + 0x238)), iVar4 == 0)) {
      iVar4 = FUN_00113090(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8),
                           *(undefined4 *)(param_1 + 0x238));
      if (iVar4 == 0) {
        iVar2 = 0;
        iVar7 = 0;
        iVar4 = param_1;
        piVar5 = param_2;
        do {
          local_58[0] = 0;
          iVar3 = FUN_001767d8(param_1,iVar7);
          if (iVar3 != 0) {
            FUN_00176c40(local_3c,param_1,iVar7,local_58);
            *piVar5 = local_3c[0];
            if (local_3c[0] != 0x7ffffffe) {
              uVar6 = FUN_00173e10(*(undefined4 *)(param_1 + 0x238));
              *(undefined4 *)(iVar4 + 0x30) = uVar6;
            }
          }
          iVar3 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
          if ((*(char *)(iVar7 + iVar3 + 0x10) == '\0') && (local_58[0] != 0)) {
            iVar2 = 1;
          }
          bVar1 = iVar7 != 3;
          piVar5 = piVar5 + 1;
          iVar4 = iVar4 + 4;
          iVar7 = iVar7 + 1;
        } while (bVar1);
        iVar4 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
        if (*(int *)(iVar4 + 0x10) == DAT_001b01d0) goto LAB_0017dfa0;
        iVar4 = 0;
        piVar5 = param_2;
        do {
          iVar7 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
          if ((*(char *)(iVar4 + iVar7 + 0x10) != '\x01') && (*piVar5 == 0x7ffffffe))
          goto LAB_0017dfa0;
          bVar1 = iVar4 != 3;
          piVar5 = piVar5 + 1;
          iVar4 = iVar4 + 1;
        } while (bVar1);
      }
      else {
        iVar4 = FUN_0017672c(param_1);
        if (iVar4 == 0) goto LAB_0017df9c;
        local_58[0] = iVar2;
        FUN_001781a4(&local_40,param_1,local_58);
        iVar2 = local_58[0];
        if (local_40 == 0x7ffffffe) goto LAB_0017dfa0;
        uVar6 = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),local_40);
        iVar3 = 4;
        iVar7 = 0;
        iVar4 = param_1;
        do {
          *(int *)((int)param_2 + iVar7) = local_40;
          iVar7 = iVar7 + 4;
          *(undefined4 *)(iVar4 + 0x30) = uVar6;
          iVar4 = iVar4 + 4;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
    }
    else {
      iVar4 = FUN_00178b1c(param_1);
      if (iVar4 == 0) {
LAB_0017df9c:
        iVar2 = 0;
LAB_0017dfa0:
        bVar1 = true;
        goto LAB_0017dd38;
      }
      local_58[0] = iVar2;
      FUN_00176a94(&local_44,param_1,local_58);
      iVar2 = local_58[0];
      if (local_44 == 0x7ffffffe) goto LAB_0017dfa0;
      uVar6 = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),local_44);
      iVar3 = 4;
      iVar7 = 0;
      iVar4 = param_1;
      do {
        *(int *)((int)param_2 + iVar7) = local_44;
        iVar7 = iVar7 + 4;
        *(undefined4 *)(iVar4 + 0x30) = uVar6;
        iVar4 = iVar4 + 4;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
  }
  else {
    iVar2 = 0;
    iVar7 = 0;
    iVar4 = param_1;
    piVar5 = param_2;
    do {
      local_58[0] = 0;
      iVar3 = FUN_00178a98(param_1,iVar7);
      if (iVar3 != 0) {
        FUN_00178e90(&local_48,param_1,iVar7,local_58);
        *piVar5 = local_48;
        if (local_48 != 0x7ffffffe) {
          uVar6 = FUN_00173e10(*(undefined4 *)(param_1 + 0x238));
          *(undefined4 *)(iVar4 + 0x30) = uVar6;
        }
      }
      iVar3 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
      if ((*(char *)(iVar7 + iVar3 + 0x10) == '\0') && (local_58[0] != 0)) {
        iVar2 = 1;
      }
      bVar1 = iVar7 != 3;
      piVar5 = piVar5 + 1;
      iVar4 = iVar4 + 4;
      iVar7 = iVar7 + 1;
    } while (bVar1);
    iVar4 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
    if (*(int *)(iVar4 + 0x10) == DAT_001b01d0) goto LAB_0017dfa0;
    iVar4 = 0;
    piVar5 = param_2;
    do {
      iVar7 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
      if ((*(char *)(iVar4 + iVar7 + 0x10) != '\x01') && (*piVar5 == 0x7ffffffe)) goto LAB_0017dfa0;
      bVar1 = iVar4 != 3;
      piVar5 = piVar5 + 1;
      iVar4 = iVar4 + 1;
    } while (bVar1);
  }
  bVar1 = false;
LAB_0017dd38:
  iVar4 = (**(code **)(**(int **)(param_1 + 0xb0) + 100))();
  if ((iVar4 == 0) && (!bVar1)) {
    iVar4 = ((int (*)())FUN_0017d6ac)(param_1,param_2);
    if (iVar4 != 0) {
      FUN_001745ac(param_1);
      return 1;
    }
    iVar4 = *(int *)(*(int *)(param_1 + 0x238) + 0x6c4);
    *(int *)(iVar4 + 0x138) = *(int *)(iVar4 + 0x138) + 1;
    if ((*(int *)(*(int *)(param_1 + 0xb0) + 0x120) != 0) && (iVar2 == 0)) {
      *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x120) = 0;
      FUN_001745ac(param_1);
      return 0;
    }
  }
  return 0;
}

/* FUN_0017e02c @ 0x17e02c (452 bytes) */
int FUN_0017e02c(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  
  iVar4 = *(int *)(param_1 + 0xb0);
  uVar2 = *(undefined4 *)(iVar4 + 4);
  uVar7 = *(undefined4 *)(iVar4 + 0x158);
  FUN_0019401c(iVar4);
  uVar15 = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c);
  iVar5 = FUN_001054ec(*(int *)(param_1 + 0xb0),0);
  iVar4 = *(int *)(param_1 + 0xb0);
  uVar12 = *(undefined4 *)(iVar5 + 0x10);
  uVar13 = *(undefined4 *)(param_2 * 0x18 + iVar4 + 0x8c);
  uVar9 = *(undefined4 *)(iVar4 + 0x120);
  iVar4 = FUN_001054ec(iVar4,param_2);
  iVar5 = *(int *)(param_1 + 0xb0);
  uVar14 = *(undefined4 *)(iVar4 + 0x10);
  uVar6 = *(uint *)(iVar5 + 0x14);
  uVar3 = *(uint *)(param_2 * 0x18 + iVar5 + 0xa0);
  uVar11 = *(undefined4 *)(param_2 * 4 + param_1 + 0x210);
  bVar1 = (uVar6 >> 9 & 1) == 0;
  if (bVar1) {
    uVar8 = 0;
    uVar10 = 0;
  }
  else {
    uVar8 = *(undefined4 *)(*(int *)(iVar5 + 0x84) * 4 + param_1 + 0x210);
    uVar10 = *(undefined4 *)(*(int *)(iVar5 + 0x84) * 0x18 + iVar5 + 0x8c);
  }
  uVar16 = *(undefined4 *)(iVar5 + 0x94);
  uVar17 = *(undefined4 *)(iVar5 + 0x98);
  FUN_00108448(iVar5,0x31,*(undefined4 *)(param_1 + 0x238));
  FUN_001046c8(iVar5,0,uVar15);
  *(undefined4 *)(iVar5 + 0x94) = uVar16;
  *(undefined4 *)(iVar5 + 0x98) = uVar17;
  if (bVar1) {
    *(undefined4 *)(param_1 + 0x218) = 0;
  }
  else {
    FUN_001049e8(iVar5,uVar10,*(undefined4 *)(param_1 + 0x238));
    *(uint *)(iVar5 + 0x14) = *(uint *)(iVar5 + 0x14) | 0x200;
    *(undefined4 *)(param_1 + 0x218) = uVar8;
  }
  *(undefined4 *)(iVar5 + 0x9c) = uVar12;
  FUN_001046c8(iVar5,1,uVar13);
  iVar4 = FUN_001054ec(iVar5,1);
  *(undefined4 *)(iVar4 + 0x10) = uVar14;
  FUN_00103d50(iVar5 + 0xa4,1,uVar3 & 1);
  FUN_00103d50(iVar5 + 0xa4,2,uVar3 >> 1 & 1);
  *(undefined4 *)(iVar5 + 0x120) = uVar9;
  *(undefined4 *)(iVar5 + 0x124) = param_3;
  *(undefined4 *)(param_1 + 0x214) = uVar11;
  if ((uVar6 & 0x200000) != 0) {
    *(uint *)(iVar5 + 0x14) = *(uint *)(iVar5 + 0x14) | 0x200000;
  }
  FUN_000e7738(uVar7,uVar2,iVar5);
  return;
}

/* FUN_0017e1f4 @ 0x17e1f4 (324 bytes) */
int FUN_0017e1f4(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  double dVar6;
  float local_38 [7];
  
  iVar5 = 1;
  do {
    FUN_001770e4(local_38,param_1,iVar5);
    if (local_38[0] != NAN) {
      bVar1 = -1 < (int)local_38[0];
      if (bVar1) {
        dVar6 = (double)local_38[0];
      }
      else {
        dVar6 = -(double)local_38[0];
      }
      iVar2 = ((undefined4 (*)())FUN_0010aafc)(dVar6);
      if (iVar2 != 0) {
        iVar2 = ((int (*)())FUN_0010ab40)(dVar6);
        piVar4 = *(int **)(*(int *)(param_1 + 0x238) + 0x30c);
        iVar2 = iVar2 + *(int *)(*(int *)(param_1 + 0xb0) + 0x124);
        iVar3 = (**(code **)(*piVar4 + 0xfc))(piVar4,iVar2);
        if (iVar3 != 0) {
          iVar5 = (iVar5 == 1) + 1;
          if (!bVar1) {
            iVar3 = *(int *)(param_1 + 0xb0) + iVar5 * 0x18 + 0x80;
            FUN_00103d50(iVar3 + 0xc,1,(*(uint *)(iVar3 + 0x20) ^ 1) & 1);
          }
          ((int (*)())FUN_0017e02c)(param_1,iVar5,iVar2);
          FUN_001745ac(param_1);
          return 1;
        }
      }
    }
    bVar1 = iVar5 != 2;
    iVar5 = iVar5 + 1;
  } while (bVar1);
  return 0;
}

/* FUN_0017e338 @ 0x17e338 (188 bytes) */
int FUN_0017e338(param_1)
  int param_1;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = ((int (*)())FUN_00179c44)(param_1,1,2);
  if (iVar1 != 0) {
    iVar1 = *(int *)(param_1 + 0xb0);
    if (((*(uint *)(iVar1 + 0xb8) & 1) == (*(uint *)(iVar1 + 0xd0) & 1)) &&
       ((*(uint *)(iVar1 + 0xb8) >> 1 & 1) == (*(uint *)(iVar1 + 0xd0) >> 1 & 1))) {
      piVar2 = *(int **)(*(int *)(param_1 + 0x238) + 0x30c);
      iVar3 = *(int *)(iVar1 + 0x124) + 1;
      iVar1 = (**(code **)(*piVar2 + 0xfc))(piVar2,iVar3);
      if (iVar1 != 0) {
        ((int (*)())FUN_0017e02c)(param_1,2,iVar3);
        FUN_001745ac(param_1);
        return 1;
      }
    }
  }
  return 0;
}

/* FUN_0017e3f4 @ 0x17e3f4 (608 bytes) */
int FUN_0017e3f4(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  
  iVar5 = *(int *)(param_1 + 0xb0);
  uVar2 = *(undefined4 *)(iVar5 + 4);
  uVar3 = *(undefined4 *)(iVar5 + 0x158);
  uVar15 = *(undefined4 *)(iVar5 + 0x94);
  uVar16 = *(undefined4 *)(iVar5 + 0x98);
  uVar17 = *(undefined4 *)(iVar5 + 0x8c);
  iVar8 = FUN_001054ec(iVar5,0);
  iVar5 = *(int *)(param_1 + 0xb0);
  uVar9 = *(undefined4 *)(iVar8 + 0x10);
  uVar10 = *(undefined4 *)(param_3 * 0x18 + iVar5 + 0x8c);
  uVar13 = *(undefined4 *)(iVar5 + 0x120);
  uVar14 = *(undefined4 *)(iVar5 + 0x124);
  iVar8 = FUN_001054ec(iVar5,param_3);
  iVar5 = *(int *)(param_1 + 0xb0);
  uVar11 = *(undefined4 *)(iVar8 + 0x10);
  uVar4 = *(uint *)(param_3 * 0x18 + iVar5 + 0xa0);
  uVar6 = *(undefined4 *)(param_4 * 0x18 + iVar5 + 0x8c);
  iVar5 = FUN_001054ec(iVar5,param_4);
  iVar8 = *(int *)(param_1 + 0xb0);
  uVar12 = *(undefined4 *)(iVar5 + 0x10);
  bVar1 = (*(uint *)(iVar8 + 0x14) & 0x200) == 0;
  uVar7 = *(uint *)(param_4 * 0x18 + iVar8 + 0xa0);
  uVar18 = *(undefined4 *)(param_3 * 4 + param_1 + 0x210);
  uVar20 = *(undefined4 *)(param_4 * 4 + param_1 + 0x210);
  if (bVar1) {
    uVar19 = 0;
    uVar21 = 0;
  }
  else {
    uVar19 = *(undefined4 *)(*(int *)(iVar8 + 0x84) * 4 + param_1 + 0x210);
    uVar21 = *(undefined4 *)(*(int *)(iVar8 + 0x84) * 0x18 + iVar8 + 0x8c);
  }
  FUN_0019401c(iVar8);
  iVar5 = *(int *)(param_1 + 0xb0);
  FUN_00108174(iVar5,param_2,*(undefined4 *)(param_1 + 0x238));
  FUN_001046c8(iVar5,0,uVar17);
  *(undefined4 *)(iVar5 + 0x94) = uVar15;
  *(undefined4 *)(iVar5 + 0x98) = uVar16;
  if (bVar1) {
    iVar8 = FUN_00122fa4(uVar17,*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x238) + 0x6c4) + 0x3a0)
                        );
    *(undefined4 *)(param_1 + 0x21c) = *(undefined4 *)(iVar8 + 0xb0);
  }
  else {
    FUN_001049e8(iVar5,uVar21,*(undefined4 *)(param_1 + 0x238));
    *(uint *)(iVar5 + 0x14) = *(uint *)(iVar5 + 0x14) | 0x200;
    *(undefined4 *)(param_1 + 0x21c) = uVar19;
  }
  *(undefined4 *)(iVar5 + 0x9c) = uVar9;
  *(undefined4 *)(iVar5 + 0x120) = uVar13;
  *(undefined4 *)(iVar5 + 0x124) = uVar14;
  FUN_001046c8(iVar5,1,uVar10);
  iVar8 = FUN_001054ec(iVar5,1);
  *(undefined4 *)(iVar8 + 0x10) = uVar11;
  FUN_00103d50(iVar5 + 0xa4,1,uVar4 & 1);
  FUN_00103d50(iVar5 + 0xa4,2,uVar4 >> 1 & 1);
  FUN_001046c8(iVar5,2,uVar6);
  iVar8 = FUN_001054ec(iVar5,2);
  *(undefined4 *)(iVar8 + 0x10) = uVar12;
  FUN_00103d50(iVar5 + 0xbc,1,uVar7 & 1);
  FUN_00103d50(iVar5 + 0xbc,2,uVar7 >> 1 & 1);
  *(undefined4 *)(param_1 + 0x218) = uVar20;
  *(undefined4 *)(param_1 + 0x214) = uVar18;
  FUN_000e7738(uVar3,uVar2,iVar5);
  return;
}

/* FUN_0017e658 @ 0x17e658 (112 bytes) */
int FUN_0017e658(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),0);
  iVar1 = FUN_00177064(param_1,*(undefined4 *)(iVar1 + 4),3);
  if (iVar1 != 0) {
    ((int (*)())FUN_0017e3f4)(param_1,0x13,1,2);
    FUN_001745ac(param_1);
  }
  return iVar1 != 0;
}

/* FUN_0017e6c8 @ 0x17e6c8 (280 bytes) */
int FUN_0017e6c8(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar2 = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),0x3f800000);
  iVar4 = 1;
  uVar3 = *(undefined4 *)(iVar2 + 4);
  do {
    iVar2 = FUN_00177064(param_1,uVar3,iVar4);
    if (iVar2 != 0) {
      ((int (*)())FUN_0017e3f4)(param_1,0x12,(iVar4 == 1) + '\x01',3);
      FUN_001745ac(param_1);
      return 1;
    }
    bVar1 = iVar4 != 2;
    iVar4 = iVar4 + 1;
  } while (bVar1);
  iVar2 = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),0xbf800000);
  iVar4 = 1;
  uVar3 = *(undefined4 *)(iVar2 + 4);
  do {
    iVar2 = FUN_00177064(param_1,uVar3,iVar4);
    if (iVar2 != 0) {
      ((int (*)())FUN_0017e3f4)(param_1,0x12,(iVar4 == 1) + '\x01',3);
      FUN_00103d50(*(int *)(param_1 + 0xb0) + 0xa4,1,
                   (*(uint *)(*(int *)(param_1 + 0xb0) + 0xb8) ^ 1) & 1);
      FUN_001745ac(param_1);
      return 1;
    }
    bVar1 = iVar4 != 2;
    iVar4 = iVar4 + 1;
  } while (bVar1);
  return 0;
}

/* FUN_0017e7e0 @ 0x17e7e0 (972 bytes) */
int FUN_0017e7e0(param_1)
  int param_1;
{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  int iVar16;
  undefined4 uVar17;
  int *piVar18;
  undefined4 uVar19;
  int local_78;
  undefined4 local_74 [3];
  undefined4 local_68;
  undefined4 local_64;
  uint local_60;
  int local_5c;
  int local_58;
  
  iVar4 = *(int *)(param_1 + 0xb0);
  uVar19 = *(undefined4 *)(iVar4 + 0x158);
  uVar17 = *(undefined4 *)(iVar4 + 4);
  uVar9 = *(undefined4 *)(iVar4 + 0x94);
  uVar10 = *(undefined4 *)(iVar4 + 0x98);
  uVar15 = *(undefined4 *)(iVar4 + 0x8c);
  iVar4 = FUN_001054ec(iVar4,0);
  local_78 = *(int *)(iVar4 + 0x10);
  iVar4 = *(int *)(param_1 + 0xb0);
  local_58 = *(int *)(iVar4 + 0x120);
  local_5c = *(int *)(iVar4 + 0x124);
  uVar14 = *(undefined4 *)(iVar4 + 0xa4);
  iVar6 = FUN_001054ec(iVar4,1);
  iVar4 = *(int *)(param_1 + 0xb0);
  uVar13 = *(undefined4 *)(iVar6 + 0x10);
  uVar2 = *(uint *)(iVar4 + 0xb8);
  uVar12 = *(undefined4 *)(iVar4 + 0xbc);
  iVar6 = FUN_001054ec(iVar4,2);
  iVar4 = *(int *)(param_1 + 0xb0);
  uVar11 = *(undefined4 *)(iVar6 + 0x10);
  uVar3 = *(uint *)(iVar4 + 0xd0);
  uVar8 = *(undefined4 *)(iVar4 + 0xd4);
  iVar4 = FUN_001054ec(iVar4,3);
  iVar6 = *(int *)(param_1 + 0xb0);
  local_68 = *(undefined4 *)(iVar4 + 0x10);
  uVar5 = *(uint *)(iVar6 + 0xe8);
  bVar1 = (*(uint *)(iVar6 + 0x14) >> 9 & 1) != 0;
  local_60 = uVar5 >> 1 & 1;
  if (bVar1) {
    local_64 = *(undefined4 *)(*(int *)(iVar6 + 0x84) * 0x18 + iVar6 + 0x8c);
  }
  else {
    local_64 = 0;
  }
  FUN_0019401c(iVar6);
  iVar16 = *(int *)(param_1 + 0xb0);
  FUN_00108174(iVar16,0x13,*(undefined4 *)(param_1 + 0x238));
  FUN_000e7738(uVar19,uVar17,iVar16);
  piVar7 = (int *)FUN_001043f0(0x12,*(undefined4 *)(param_1 + 0x238));
  FUN_000e7738(uVar19,*(undefined4 *)(param_1 + 0xb0),piVar7);
  iVar4 = *(int *)(param_1 + 0x238);
  uVar17 = *(undefined4 *)(*(int *)(iVar4 + 0x6c4) + 0x3ac);
  iVar6 = *(int *)(iVar4 + 0x3ac) + -1;
  *(int *)(iVar4 + 0x3ac) = iVar6;
  uVar17 = FUN_00127608(uVar17,0,iVar6,0);
  FUN_001046c8(iVar16,0,uVar17);
  FUN_001046c8(iVar16,1,uVar14);
  iVar4 = FUN_001054ec(iVar16,1);
  *(undefined4 *)(iVar4 + 0x10) = uVar13;
  FUN_00103d50(iVar16 + 0xa4,1,uVar2 & 1);
  FUN_00103d50(iVar16 + 0xa4,2,uVar2 >> 1 & 1);
  FUN_001046c8(iVar16,2,uVar12);
  iVar4 = FUN_001054ec(iVar16,2);
  *(undefined4 *)(iVar4 + 0x10) = uVar11;
  FUN_00103d50(iVar16 + 0xbc,1,uVar3 & 1);
  FUN_00103d50(iVar16 + 0xbc,2,uVar3 >> 1 & 1);
  *(undefined4 *)(iVar16 + 0x94) = uVar9;
  *(undefined4 *)(iVar16 + 0x98) = uVar10;
  *(int *)(iVar16 + 0x9c) = local_78;
  FUN_0012306c(uVar17,iVar16);
  iVar4 = 0;
  local_74[0] = DAT_001b01dc;
  iVar6 = 4;
  do {
    if (*(char *)((int)local_74 + iVar4 + -4) == '\0') {
      *(char *)((int)local_74 + iVar4) = (char)iVar4;
    }
    iVar4 = iVar4 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  FUN_001046c8(piVar7,0,uVar15);
  piVar7[0x27] = local_78;
  FUN_001046c8(piVar7,1,uVar17);
  uVar9 = local_74[0];
  iVar4 = FUN_001054ec(piVar7,1);
  *(undefined4 *)(iVar4 + 0x10) = uVar9;
  FUN_001046c8(piVar7,2,uVar8);
  iVar4 = FUN_001054ec(piVar7,2);
  *(undefined4 *)(iVar4 + 0x10) = local_68;
  FUN_00103d50(piVar7 + 0x2f,1,uVar5 & 1);
  FUN_00103d50(piVar7 + 0x2f,2,local_60);
  piVar7[0x48] = local_58;
  piVar7[0x49] = local_5c;
  FUN_0012306c(uVar15,piVar7);
  iVar4 = 1;
  piVar18 = piVar7;
  while( true ) {
    iVar6 = (**(code **)(*piVar7 + 0x14))(piVar7);
    if (iVar6 < iVar4) break;
    FUN_001236e4(piVar18[0x29],iVar4,piVar7);
    iVar4 = iVar4 + 1;
    piVar18 = piVar18 + 6;
  }
  if (bVar1) {
    FUN_001049e8(iVar16,local_64,*(undefined4 *)(param_1 + 0x238));
    *(uint *)(iVar16 + 0x14) = *(uint *)(iVar16 + 0x14) | 0x200;
    FUN_001236e4(local_64,*(undefined4 *)(iVar16 + 0x84),iVar16);
    FUN_001049e8(piVar7,uVar15,*(undefined4 *)(param_1 + 0x238));
    piVar7[5] = piVar7[5] | 0x200;
    FUN_001236e4(uVar15,piVar7[0x21],piVar7);
  }
  FUN_001745ac(param_1);
  return;
}

/* FUN_0017ebb0 @ 0x17ebb0 (660 bytes) */
int FUN_0017ebb0(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  int iVar18;
  undefined4 local_58;
  
  iVar3 = *(int *)(param_1 + 0xb0);
  uVar14 = *(undefined4 *)(iVar3 + 4);
  uVar15 = *(undefined4 *)(iVar3 + 0x158);
  uVar12 = *(undefined4 *)(iVar3 + 0x94);
  uVar13 = *(undefined4 *)(iVar3 + 0x98);
  uVar9 = *(undefined4 *)(iVar3 + 0x8c);
  iVar5 = FUN_001054ec(iVar3,0);
  iVar3 = *(int *)(param_1 + 0xb0);
  uVar2 = *(undefined4 *)(param_1 + 0x21c);
  uVar17 = *(undefined4 *)(iVar3 + 0x124);
  uVar11 = *(undefined4 *)(iVar5 + 0x10);
  uVar16 = *(undefined4 *)(iVar3 + 0x120);
  uVar8 = *(undefined4 *)(iVar3 + 0xd4);
  iVar3 = FUN_001054ec(iVar3,3);
  iVar5 = *(int *)(param_1 + 0xb0);
  uVar7 = *(undefined4 *)(iVar3 + 0x10);
  uVar4 = *(uint *)(iVar5 + 0xe8);
  bVar1 = (*(uint *)(iVar5 + 0x14) >> 9 & 1) != 0;
  if (bVar1) {
    uVar10 = *(undefined4 *)(*(int *)(iVar5 + 0x84) * 4 + param_1 + 0x210);
    local_58 = *(undefined4 *)(*(int *)(iVar5 + 0x84) * 0x18 + iVar5 + 0x8c);
  }
  else {
    uVar10 = 0;
    local_58 = 0;
  }
  FUN_0019401c(iVar5);
  iVar3 = *(int *)(param_1 + 0xb0);
  FUN_00108174(iVar3,0x12,*(undefined4 *)(param_1 + 0x238));
  FUN_000e7738(uVar15,uVar14,iVar3);
  *(undefined4 *)(iVar3 + 0x120) = uVar16;
  *(undefined4 *)(iVar3 + 0x124) = uVar17;
  *(undefined4 *)(iVar3 + 0x94) = uVar12;
  *(undefined4 *)(iVar3 + 0x98) = uVar13;
  FUN_001046c8(iVar3,0,uVar9);
  iVar5 = *(int *)(param_2 + 0x8c);
  *(undefined4 *)(iVar3 + 0x9c) = uVar11;
  if (*(int *)(*(int *)(iVar5 + 0x2c) + 4) == 0) {
    uVar11 = *(undefined4 *)(*(int *)(param_1 + 0x238) + 0x378);
    puVar6 = (undefined4 *)FUN_00193e18(uVar11,0x240);
    *puVar6 = uVar11;
    puVar6 = puVar6 + 1;
    FUN_00173938(puVar6,param_2,*(undefined4 *)(param_1 + 0x238));
    FUN_00174e0c(puVar6);
    FUN_00173278(puVar6);
    FUN_00123424(iVar5,*(undefined4 *)(*(int *)(param_2 + 0x158) + 0xb0),puVar6);
  }
  FUN_001046c8(iVar3,1,iVar5);
  iVar5 = FUN_001054ec(iVar3,1);
  *(undefined4 *)(iVar5 + 0x10) = param_3;
  FUN_00103d50(iVar3 + 0xa4,1,param_4);
  FUN_001046c8(iVar3,2,uVar8);
  iVar5 = FUN_001054ec(iVar3,2);
  *(undefined4 *)(iVar5 + 0x10) = uVar7;
  FUN_00103d50(iVar3 + 0xbc,1,uVar4 & 1);
  FUN_00103d50(iVar3 + 0xbc,2,uVar4 >> 1 & 1);
  if (bVar1) {
    FUN_001049e8(iVar3,local_58,*(undefined4 *)(param_1 + 0x238));
    *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) | 0x200;
  }
  *(int *)(param_1 + 0x214) = param_2;
  *(undefined4 *)(param_1 + 0x218) = uVar2;
  if (!bVar1) {
    uVar10 = 0;
  }
  *(undefined4 *)(param_1 + 0x21c) = uVar10;
  FUN_0012306c(uVar9,iVar3);
  if (0 < *(int *)(iVar3 + 0x84)) {
    iVar18 = 1;
    iVar5 = iVar3;
    do {
      puVar6 = (undefined4 *)(iVar5 + 0xa4);
      iVar5 = iVar5 + 0x18;
      FUN_001236e4(*puVar6,iVar18,iVar3);
      iVar18 = iVar18 + 1;
    } while (iVar18 <= *(int *)(iVar3 + 0x84));
  }
  FUN_001745ac(param_1);
  return;
}

/* FUN_0017ee68 @ 0x17ee68 (908 bytes) */
int FUN_0017ee68(param_1)
  int param_1;
{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  undefined *puVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  uint uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  int iVar17;
  int iVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  float local_58 [5];
  
  iVar17 = 1;
  while ((FUN_00178d78(local_58,param_1,iVar17), local_58[0] != FLOAT_001aa0e8 &&
         (local_58[0] != FLOAT_001aa114))) {
    bVar1 = iVar17 == 2;
    iVar17 = iVar17 + 1;
    if (bVar1) {
      return 0;
    }
  }
  iVar5 = *(int *)(param_1 + 0xb0);
  iVar18 = (iVar17 == 1) + 1;
  uVar9 = *(undefined4 *)(iVar5 + 0x8c);
  iVar11 = *(int *)(*(int *)(iVar5 + 0x88) + 8);
  iVar17 = FUN_001054ec(iVar5,0);
  iVar5 = *(int *)(param_1 + 0xb0);
  uVar10 = *(undefined4 *)(iVar17 + 0x10);
  uVar13 = *(undefined4 *)(iVar18 * 0x18 + iVar5 + 0x8c);
  uVar7 = *(undefined4 *)(iVar5 + 0x120);
  uVar8 = *(undefined4 *)(iVar5 + 0x124);
  iVar17 = FUN_001054ec(iVar5,iVar18);
  iVar5 = *(int *)(param_1 + 0xb0);
  uVar14 = *(uint *)(iVar17 + 0x10);
  uVar12 = *(undefined4 *)(iVar18 * 4 + param_1 + 0x210);
  bVar1 = (*(uint *)(iVar5 + 0x14) >> 9 & 1) != 0;
  if (bVar1) {
    uVar6 = *(undefined4 *)(*(int *)(iVar5 + 0x84) * 0x18 + iVar5 + 0x8c);
  }
  else {
    uVar6 = 0;
  }
  uVar20 = *(undefined4 *)(iVar5 + 4);
  uVar15 = *(undefined4 *)(iVar5 + 0x94);
  uVar16 = *(undefined4 *)(iVar5 + 0x98);
  uVar19 = *(undefined4 *)(iVar5 + 0x158);
  FUN_0019401c(iVar5);
  iVar18 = *(int *)(param_1 + 0xb0);
  FUN_00108174(iVar18,0x12,*(undefined4 *)(param_1 + 0x238));
  FUN_000e7738(uVar19,uVar20,iVar18);
  iVar17 = *(int *)(param_1 + 0x238);
  iVar5 = *(int *)(iVar17 + 0x3ac) + -1;
  uVar20 = *(undefined4 *)(*(int *)(iVar17 + 0x6c4) + 0x3ac);
  *(int *)(iVar17 + 0x3ac) = iVar5;
  uVar20 = FUN_00127608(uVar20,0,iVar5,0);
  FUN_0012306c(uVar20,*(undefined4 *)(param_1 + 0xb0));
  FUN_001046c8(*(undefined4 *)(param_1 + 0xb0),0,uVar20);
  *(undefined4 *)(iVar18 + 0x94) = uVar15;
  *(undefined4 *)(iVar18 + 0x98) = uVar16;
  FUN_001046c8(iVar18,1,uVar13);
  FUN_001046c8(iVar18,2,uVar13);
  iVar17 = FUN_001043f0(0x12,*(undefined4 *)(param_1 + 0x238));
  FUN_000e7738(uVar19,iVar18,iVar17);
  FUN_001046c8(iVar17,0,uVar9);
  *(undefined4 *)(iVar17 + 0x94) = uVar15;
  *(undefined4 *)(iVar17 + 0x98) = uVar16;
  *(undefined4 *)(iVar17 + 0x9c) = uVar10;
  if (bVar1) {
    FUN_001049e8(iVar17,uVar6,*(undefined4 *)(param_1 + 0x238));
    *(uint *)(iVar17 + 0x14) = *(uint *)(iVar17 + 0x14) | 0x200;
  }
  *(undefined4 *)(iVar17 + 0x120) = uVar7;
  *(undefined4 *)(iVar17 + 0x124) = uVar8;
  *(undefined4 *)(param_1 + 0x218) = uVar12;
  *(undefined4 *)(param_1 + 0x214) = uVar12;
  puVar4 = PTR_DAT_001e8b8c;
  uVar2 = DAT_001b01d8;
  if (iVar11 == 0x1c) {
    uVar7 = *(undefined4 *)(PTR_DAT_001e8b8c + (uVar14 >> 0x16 & 0x3fc));
    *(uint *)(iVar18 + 0x9c) = DAT_001b01d0 & 0xffffff;
    iVar5 = FUN_001054ec(iVar18,1);
    uVar8 = *(undefined4 *)(puVar4 + (uVar14 >> 0xe & 0x3fc));
    *(undefined4 *)(iVar5 + 0x10) = uVar7;
    iVar5 = FUN_001054ec(iVar18,2);
    *(undefined4 *)(iVar5 + 0x10) = uVar8;
    FUN_001046c8(iVar17,1,uVar20);
    FUN_001046c8(iVar17,2,uVar13);
    uVar7 = *(undefined4 *)puVar4;
    iVar5 = FUN_001054ec(iVar17,1);
    *(undefined4 *)(iVar5 + 0x10) = uVar7;
    uVar7 = *(undefined4 *)(puVar4 + (uVar14 >> 6 & 0x3fc));
    iVar17 = FUN_001054ec(iVar17,2);
    *(undefined4 *)(iVar17 + 0x10) = uVar7;
  }
  else if (iVar11 == 0x1d) {
    *(uint *)(iVar18 + 0x9c) = DAT_001b01d0 & 0xffff;
    iVar5 = FUN_001054ec(iVar18,1);
    uVar3 = DAT_001b01d8;
    *(uint *)(iVar5 + 0x10) = uVar14 & 0xff0000 | uVar14 & 0xff000000 | uVar2 & 0xffff;
    iVar5 = FUN_001054ec(iVar18,2);
    *(uint *)(iVar5 + 0x10) = (uVar14 & 0xff) << 0x10 | (uVar14 & 0xff00) << 0x10 | uVar3 & 0xffff;
    FUN_001046c8(iVar17,1,uVar20);
    FUN_001046c8(iVar17,2,uVar20);
    puVar4 = PTR_DAT_001e8b8c;
    uVar7 = *(undefined4 *)PTR_DAT_001e8b8c;
    iVar5 = FUN_001054ec(iVar17,1);
    uVar8 = *(undefined4 *)(puVar4 + 4);
    *(undefined4 *)(iVar5 + 0x10) = uVar7;
    iVar17 = FUN_001054ec(iVar17,2);
    *(undefined4 *)(iVar17 + 0x10) = uVar8;
  }
  FUN_001745ac(param_1);
  return 1;
}

/* FUN_0017f1f8 @ 0x17f1f8 (512 bytes) */
int FUN_0017f1f8(param_1)
  int param_1;
{
  bool bVar1;
  float *pfVar2;
  int iVar3;
  float *pfVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  undefined4 local_68;
  float local_64 [4];
  float local_54 [7];
  undefined4 local_38;
  undefined4 local_34 [4];
  
  iVar7 = 5;
  pfVar2 = local_54;
  do {
    *pfVar2 = NAN;
    pfVar2 = pfVar2 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  pfVar2 = local_64;
  do {
    *pfVar2 = NAN;
    pfVar2 = pfVar2 + 1;
  } while (pfVar2 != local_54);
  iVar7 = 0;
  iVar8 = 4;
  do {
    *(undefined4 *)(iVar7 + (int)local_64) = 0x7ffffffe;
    iVar7 = iVar7 + 4;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  iVar7 = 0;
  iVar8 = param_1 + 0x170;
  do {
    iVar3 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
    if (*(char *)(iVar7 + iVar3 + 0x10) != '\x01') {
      piVar6 = (int *)(iVar8 + 8);
      pfVar2 = local_54 + 1;
      do {
        if (-1 < *piVar6) {
          return 0;
        }
        piVar6 = piVar6 + 4;
        pfVar4 = (float *)FUN_00173360(*(undefined4 *)(param_1 + 0x238));
        *pfVar2 = *pfVar4;
        pfVar2 = pfVar2 + 1;
      } while (pfVar2 != local_54 + 3);
      local_64[iVar7] = local_54[1] * local_54[2];
    }
    uVar5 = DAT_001b01d8;
    bVar1 = iVar7 != 3;
    iVar8 = iVar8 + 4;
    iVar7 = iVar7 + 1;
  } while (bVar1);
  iVar7 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
  FUN_000f3908(&local_38,*(undefined4 *)(iVar7 + 0x10));
  FUN_000f3340(local_34,uVar5,local_38);
  local_68 = local_34[0];
  piVar6 = *(int **)(*(int *)(param_1 + 0x238) + 0x30c);
  iVar7 = (**(code **)(*piVar6 + 0x154))
                    (piVar6,*(undefined4 *)(*(int *)(param_1 + 0x238) + 0x6c4),local_64,&local_68);
  if (iVar7 == 0) {
    iVar7 = 0;
    pfVar2 = local_64;
    do {
      iVar8 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
      if (*(char *)(iVar7 + iVar8 + 0x10) != '\x01') {
        *pfVar2 = -*pfVar2;
      }
      bVar1 = iVar7 != 3;
      pfVar2 = pfVar2 + 1;
      iVar7 = iVar7 + 1;
    } while (bVar1);
    piVar6 = *(int **)(*(int *)(param_1 + 0x238) + 0x30c);
    iVar7 = (**(code **)(*piVar6 + 0x154))
                      (piVar6,*(undefined4 *)(*(int *)(param_1 + 0x238) + 0x6c4),local_64,&local_68)
    ;
    if (iVar7 == 0) {
      return 0;
    }
    uVar5 = 1;
  }
  else {
    uVar5 = 0;
  }
  ((int (*)())FUN_0017ebb0)(param_1,iVar7,local_68,uVar5);
  return 1;
}

/* FUN_0017f3f8 @ 0x17f3f8 (412 bytes) */
int FUN_0017f3f8(param_1, param_2)
  int param_1;
  uint param_2;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 local_38 [6];
  
  iVar3 = ((int (*)())FUN_00179c44)(param_1,1,2);
  if (iVar3 != 0) {
    iVar3 = *(int *)(param_1 + 0xb0);
    if (((*(uint *)(iVar3 + 0xb8) & 1) != (*(uint *)(iVar3 + 0xd0) & 1)) &&
       ((*(uint *)(iVar3 + 0xb8) >> 1 & 1) == (*(uint *)(iVar3 + 0xd0) >> 1 & 1))) {
      bVar2 = true;
      iVar3 = FUN_001054ec(iVar3,0);
      uVar5 = 0;
      iVar6 = 0;
      local_38[0] = *(undefined4 *)(iVar3 + 0x10);
      iVar3 = param_1;
      do {
        if (*(char *)((int)local_38 + iVar6) == '\0') {
          if (-1 < *(int *)(iVar3 + 0x178)) {
LAB_0017f514:
            iVar3 = (**(code **)(**(int **)(*(int *)(param_1 + 0x238) + 0x30c) + 0x88))();
            if (iVar3 == 0) {
              return 0;
            }
            ((int (*)())FUN_0017c244)(param_1,1);
            FUN_00103d50(*(int *)(param_1 + 0xb0) + 0xa4,2,1);
            FUN_00103d50(*(int *)(param_1 + 0xb0) + 0xa4,1,param_2 ^ 1);
            FUN_001745ac(param_1);
            return 1;
          }
          puVar4 = (uint *)FUN_00173360(*(undefined4 *)(param_1 + 0x238));
          if (bVar2) {
            uVar5 = *puVar4 >> 0x1f;
            bVar2 = false;
          }
          else if (*puVar4 >> 0x1f != uVar5) goto LAB_0017f514;
        }
        bVar1 = iVar6 == 3;
        iVar3 = iVar3 + 4;
        iVar6 = iVar6 + 1;
        if (bVar1) {
          ((int (*)())FUN_0017c244)(param_1,1);
          FUN_00103d50(*(int *)(param_1 + 0xb0) + 0xa4,1,param_2 == uVar5);
          FUN_00103d50(*(int *)(param_1 + 0xb0) + 0xa4,2,0);
          FUN_001745ac(param_1);
          return 1;
        }
      } while( true );
    }
  }
  return 0;
}

/* FUN_0017f594 @ 0x17f594 (8 bytes) */
int FUN_0017f594(param_1)
  undefined4 param_1;
{
  ((int (*)())FUN_0017f3f8)(param_1,1);
  return;
}

/* FUN_0017f59c @ 0x17f59c (8 bytes) */
int FUN_0017f59c(param_1)
  undefined4 param_1;
{
  ((int (*)())FUN_0017f3f8)(param_1,0);
  return;
}

