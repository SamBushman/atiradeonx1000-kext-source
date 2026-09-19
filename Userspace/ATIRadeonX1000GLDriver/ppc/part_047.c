#include "decls.h"

/* FUN_00176ed4 @ 0x176ed4 (56 bytes) */
int FUN_00176ed4(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0;
  if (0 < param_2) {
    iVar2 = FUN_00173330(*(undefined4 *)(param_1 + 0x238));
    uVar1 = *(undefined4 *)(iVar2 + 0xc);
  }
  return uVar1;
}

/* FUN_00176f0c @ 0x176f0c (56 bytes) */
int FUN_00176f0c(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0;
  if (0 < param_2) {
    iVar2 = FUN_00173330(*(undefined4 *)(param_1 + 0x238));
    uVar1 = *(undefined4 *)(iVar2 + 0x10);
  }
  return uVar1;
}

/* FUN_00176f44 @ 0x176f44 (144 bytes) */
int FUN_00176f44(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar4 = (undefined4 *)(param_2 * 0x10 + param_1 + 0x168);
  puVar5 = (undefined4 *)(param_3 * 0x10 + param_1 + 0x168);
  iVar3 = 0;
  while ((iVar2 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0),
         *(char *)(iVar3 + iVar2 + 0x10) == '\x01' ||
         (iVar2 = FUN_00176d6c(*puVar4,*puVar5,*(undefined4 *)(param_1 + 0x238)), iVar2 != 0))) {
    bVar1 = iVar3 == 3;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
    iVar3 = iVar3 + 1;
    if (bVar1) {
      return 1;
    }
  }
  return 0;
}

/* FUN_00176fd4 @ 0x176fd4 (144 bytes) */
int FUN_00176fd4(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar4 = (undefined4 *)(param_2 * 0x10 + param_1 + 0x168);
  puVar5 = (undefined4 *)(param_3 * 0x10 + param_1 + 0x168);
  iVar3 = 0;
  while ((iVar2 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0),
         *(char *)(iVar3 + iVar2 + 0x10) == '\x01' ||
         (iVar2 = FUN_00176e20(*puVar4,*puVar5,*(undefined4 *)(param_1 + 0x238)), iVar2 != 0))) {
    bVar1 = iVar3 == 3;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
    iVar3 = iVar3 + 1;
    if (bVar1) {
      return 1;
    }
  }
  return 0;
}

/* FUN_00177064 @ 0x177064 (128 bytes) */
int FUN_00177064(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = (int *)(param_3 * 0x10 + param_1 + 0x168);
  iVar3 = 0;
  while ((iVar2 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0),
         *(char *)(iVar3 + iVar2 + 0x10) == '\x01' || (*piVar4 == param_2))) {
    bVar1 = iVar3 == 3;
    piVar4 = piVar4 + 1;
    iVar3 = iVar3 + 1;
    if (bVar1) {
      return 1;
    }
  }
  return 0;
}

/* FUN_001770e4 @ 0x1770e4 (204 bytes) */
int FUN_001770e4(param_1, param_2, param_3)
  undefined4 *param_1;
  int param_2;
  int param_3;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  
  iVar6 = 0;
  bVar1 = false;
  bVar2 = true;
  piVar8 = (int *)(param_3 * 0x10 + param_2 + 0x168);
  iVar7 = 0;
  do {
    iVar4 = FUN_001054ec(*(undefined4 *)(param_2 + 0xb0),0);
    if (*(char *)(iVar7 + iVar4 + 0x10) != '\x01') {
      if (bVar2) {
        iVar6 = *piVar8;
        bVar1 = iVar6 < 0;
        bVar2 = iVar6 == 0;
      }
      else if (*piVar8 != iVar6) goto LAB_00177184;
    }
    bVar3 = iVar7 != 3;
    piVar8 = piVar8 + 1;
    iVar7 = iVar7 + 1;
  } while (bVar3);
  if (bVar1) {
    puVar5 = (undefined4 *)FUN_00173360(*(undefined4 *)(param_2 + 0x238),iVar6);
    *param_1 = *puVar5;
  }
  else {
LAB_00177184:
    *param_1 = 0x7ffffffe;
  }
  return param_1;
}

/* FUN_001771b0 @ 0x1771b0 (236 bytes) */
int FUN_001771b0(param_1)
  int *param_1;
{
  bool bVar1;
  int iVar2;
  float *pfVar3;
  int iVar4;
  int *piVar5;
  
  iVar4 = 0;
  piVar5 = param_1;
  do {
    iVar2 = FUN_001054ec(param_1[0x2c],0);
    if (*(char *)(iVar4 + iVar2 + 0x10) != '\x01') {
      if ((float *)piVar5[0xc] == (float *)0x0) {
        if (*piVar5 < 0) {
          pfVar3 = (float *)FUN_00173360(param_1[0x8e]);
          iVar2 = ((undefined4 (*)())FUN_00176350)((double)*pfVar3);
        }
        else {
          iVar2 = piVar5[0x10];
          if (iVar2 == 0) {
            if (*piVar5 < 1) {
              iVar2 = 0;
              goto LAB_00177254;
            }
            iVar2 = FUN_00173330(param_1[0x8e]);
          }
          iVar2 = *(int *)(iVar2 + 0x10);
        }
      }
      else {
        iVar2 = ((undefined4 (*)())FUN_00176350)((double)*(float *)piVar5[0xc]);
      }
LAB_00177254:
      if (*(int *)(param_1[0x2c] + 0x120) == 0) {
        piVar5[0x14] = iVar2;
      }
      else {
        piVar5[0x14] = (DAT_001e6158)[iVar2];
      }
    }
    bVar1 = iVar4 == 3;
    piVar5 = piVar5 + 1;
    iVar4 = iVar4 + 1;
    if (bVar1) {
      return;
    }
  } while( true );
}

/* FUN_0017729c @ 0x17729c (224 bytes) */
int FUN_0017729c(param_1)
  int *param_1;
{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  
  iVar4 = 0;
  piVar5 = param_1;
  do {
    iVar2 = FUN_001054ec(param_1[0x2c],0);
    if (*(char *)(iVar4 + iVar2 + 0x10) != '\x01') {
      puVar3 = (undefined4 *)piVar5[0xc];
      if (puVar3 == (undefined4 *)0x0) {
        if (*piVar5 < 0) {
          puVar3 = (undefined4 *)FUN_00173360(param_1[0x8e]);
          goto LAB_00177304;
        }
        iVar2 = piVar5[0x10];
        if (iVar2 == 0) {
          if (0 < *piVar5) {
            iVar2 = FUN_00173330(param_1[0x8e]);
            goto LAB_00177330;
          }
          iVar2 = 0;
        }
        else {
LAB_00177330:
          iVar2 = *(int *)(iVar2 + 0xc);
        }
      }
      else {
LAB_00177304:
        iVar2 = FUN_00176324(*puVar3);
      }
      if (*(int *)(param_1[0x2c] + 0x120) == 0) {
        piVar5[0x20] = iVar2;
      }
      else {
        piVar5[0x20] = (DAT_001e61a0)[iVar2];
      }
    }
    bVar1 = iVar4 == 3;
    piVar5 = piVar5 + 1;
    iVar4 = iVar4 + 1;
    if (bVar1) {
      return;
    }
  } while( true );
}

/* FUN_0017737c @ 0x17737c (144 bytes) */
int FUN_0017737c(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  piVar4 = (int *)(param_2 * 0x10 + param_1 + 0x168);
  piVar5 = (int *)(param_3 * 0x10 + param_1 + 0x168);
  iVar3 = 0;
  while ((iVar2 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0),
         *(char *)(iVar3 + iVar2 + 0x10) == '\x01' || (*piVar4 == *piVar5))) {
    bVar1 = iVar3 == 3;
    piVar4 = piVar4 + 1;
    piVar5 = piVar5 + 1;
    iVar3 = iVar3 + 1;
    if (bVar1) {
      return 1;
    }
  }
  return 0;
}

/* FUN_0017740c @ 0x17740c (156 bytes) */
undefined4 FUN_0017740c(double param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  piVar4 = (int *)(param_3 * 0x10 + param_2 + 0x168);
  iVar2 = FUN_00173e10(*(undefined4 *)(param_2 + 0x238),(float)param_1);
  iVar5 = 0;
  while ((iVar3 = FUN_001054ec(*(undefined4 *)(param_2 + 0xb0),0),
         *(char *)(iVar5 + iVar3 + 0x10) == '\x01' || (*piVar4 == *(int *)(iVar2 + 4)))) {
    bVar1 = iVar5 == 3;
    piVar4 = piVar4 + 1;
    iVar5 = iVar5 + 1;
    if (bVar1) {
      return 1;
    }
  }
  return 0;
}

/* FUN_00177548 @ 0x177548 (144 bytes) */
int FUN_00177548(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    iVar2 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
    if (*(char *)(iVar3 + iVar2 + 0x10) == '\0') {
      *(undefined1 *)(iVar3 + *(int *)(param_1 + 0xb0) + 0x9c) = 1;
    }
    bVar1 = iVar3 != 3;
    iVar3 = iVar3 + 1;
  } while (bVar1);
  iVar3 = *(int *)(param_1 + 0xb0);
  if ((*(uint *)(iVar3 + 0x14) & 0x200) == 0) {
    FUN_001049e8(iVar3,*(undefined4 *)(iVar3 + 0x8c),*(undefined4 *)(param_1 + 0x238));
    return;
  }
  return;
}

/* FUN_001775d8 @ 0x1775d8 (224 bytes) */
int FUN_001775d8(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = *(int *)(param_1 + 0xb0);
  if ((*(int *)(iVar2 + 0x120) == 0) && (*(int *)(iVar2 + 0x124) == 0)) {
    if (((*(uint *)(iVar2 + 0xb8) & 2) == 0) && ((*(uint *)(iVar2 + 0xb8) & 1) != 0)) {
      iVar3 = 0;
      iVar4 = param_1;
      while( true ) {
        iVar2 = FUN_001054ec(iVar2,0);
        if ((*(char *)(iVar3 + iVar2 + 0x10) != '\x01') && (*(int *)(iVar4 + 0x30) == 0)) {
          iVar2 = *(int *)(iVar4 + 0x40);
          if (iVar2 == 0) {
            iVar2 = FUN_00174ce0(*(undefined4 *)(param_1 + 0x238),iVar3,param_1);
            *(int *)(iVar4 + 0x40) = iVar2;
          }
          *(int *)(iVar2 + 4) = param_1;
          *(int *)(*(int *)(iVar4 + 0x40) + 8) = iVar3;
          *(undefined4 *)(*(int *)(iVar4 + 0x40) + 0x20) = 1;
          *(undefined4 *)(*(int *)(iVar4 + 0x40) + 0x24) = *(undefined4 *)(iVar4 + 0x178);
        }
        bVar1 = iVar3 == 3;
        iVar4 = iVar4 + 4;
        iVar3 = iVar3 + 1;
        if (bVar1) break;
        iVar2 = *(int *)(param_1 + 0xb0);
      }
    }
  }
  return;
}

/* FUN_001776b8 @ 0x1776b8 (144 bytes) */
int FUN_001776b8(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = param_2 * 4 + param_1;
  iVar2 = FUN_00176ec0(param_1,*(undefined4 *)(iVar5 + 0x178),*(undefined4 *)(iVar5 + 0x188));
  if (iVar2 != 0) {
    uVar4 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xd0);
    uVar1 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xb8);
    if (((uVar1 & 1) == (uVar4 & 1)) && ((uVar1 >> 1 & 1) == (uVar4 >> 1 & 1))) {
      uVar3 = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),0);
      *(undefined4 *)(iVar5 + 0x30) = uVar3;
      return 1;
    }
  }
  return 0;
}

/* FUN_00177748 @ 0x177748 (408 bytes) */
int FUN_00177748(param_1)
  int param_1;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  float local_38 [2];
  float local_30;
  
  iVar3 = FUN_0010b5f8(*(undefined4 *)(param_1 + 0xb0));
  ((int (*)())FUN_001770e4)(local_38,param_1,2);
  local_30 = local_38[0];
  if ((local_38[0] == FLOAT_001aa0d4) &&
     (piVar4 = *(int **)(*(int *)(param_1 + 0x238) + 0x30c),
     iVar5 = (**(code **)(*piVar4 + 0x2c))(piVar4,iVar3), iVar5 == 0)) {
    iVar9 = 0;
    iVar5 = 0;
    iVar10 = param_1;
    do {
      iVar6 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
      iVar8 = iVar5;
      if (*(char *)(iVar9 + iVar6 + 0x10) != '\x01') {
        if (*(int *)(iVar10 + 0x178) < 0) {
          puVar7 = (undefined4 *)FUN_00173360(*(undefined4 *)(param_1 + 0x238));
          iVar8 = FUN_00176324(*puVar7);
        }
        else {
          if (*(int *)(iVar10 + 0x178) < 1) {
            return;
          }
          iVar8 = FUN_00173330(*(undefined4 *)(param_1 + 0x238));
          iVar8 = *(int *)(iVar8 + 0xc);
          uVar2 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xb8);
          if ((uVar2 & 2) != 0) {
            iVar8 = (DAT_001e61d0)[iVar8];
          }
          if ((uVar2 & 1) != 0) {
            iVar8 = *(int *)(&DAT_001e61b8 + iVar8 * 4);
          }
        }
        if (iVar8 == 0) {
          return;
        }
        if ((iVar5 != 0) && (bVar1 = iVar8 != iVar5, iVar8 = iVar5, bVar1)) {
          return;
        }
      }
      bVar1 = iVar9 != 3;
      iVar10 = iVar10 + 4;
      iVar9 = iVar9 + 1;
      iVar5 = iVar8;
    } while (bVar1);
    piVar4 = *(int **)(*(int *)(param_1 + 0x238) + 0x30c);
    iVar5 = (**(code **)(*piVar4 + 0x30))(piVar4,iVar3,iVar8);
    if (iVar3 != iVar5) {
      FUN_0010b914(*(undefined4 *)(param_1 + 0xb0),iVar5);
      return;
    }
  }
  return;
}

/* FUN_001778e0 @ 0x1778e0 (272 bytes) */
int FUN_001778e0(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  double dVar6;
  
  iVar2 = *(int *)(param_1 + 0xb0);
  if ((((*(int *)(iVar2 + 0x120) == 0) && ((*(uint *)(iVar2 + 0xb8) & 1) == 0)) &&
      ((*(uint *)(iVar2 + 0xb8) & 2) == 0)) && (*(int *)(iVar2 + 0x124) != 0)) {
    iVar5 = 0;
    iVar4 = param_1;
    while( true ) {
      iVar2 = FUN_001054ec(iVar2,0);
      if ((*(char *)(iVar5 + iVar2 + 0x10) != '\x01') && (*(int *)(iVar4 + 0x30) == 0)) {
        if (*(int *)(iVar4 + 0x40) == 0) {
          uVar3 = FUN_00174ce0(*(undefined4 *)(param_1 + 0x238),iVar5,param_1);
          *(undefined4 *)(iVar4 + 0x40) = uVar3;
        }
        iVar2 = FUN_00174ce0(*(undefined4 *)(param_1 + 0x238),iVar5,param_1);
        *(int *)(iVar4 + 0x40) = iVar2;
        *(int *)(iVar2 + 4) = param_1;
        *(int *)(*(int *)(iVar4 + 0x40) + 8) = iVar5;
        *(undefined4 *)(*(int *)(iVar4 + 0x40) + 0x14) = 1;
        *(undefined4 *)(*(int *)(iVar4 + 0x40) + 0x18) = *(undefined4 *)(iVar4 + 0x178);
        iVar2 = *(int *)(iVar4 + 0x40);
        dVar6 = (double)((double (*)())FUN_0010aad4)(*(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x124));
        *(float *)(iVar2 + 0x1c) = (float)dVar6;
      }
      bVar1 = iVar5 == 3;
      iVar4 = iVar4 + 4;
      iVar5 = iVar5 + 1;
      if (bVar1) break;
      iVar2 = *(int *)(param_1 + 0xb0);
    }
  }
  return;
}

/* FUN_001779f0 @ 0x1779f0 (224 bytes) */
int FUN_001779f0(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = *(int *)(param_1 + 0xb0);
  if ((*(int *)(iVar2 + 0x120) == 0) && (*(int *)(iVar2 + 0x124) == 0)) {
    if (((*(uint *)(iVar2 + 0xb8) & 1) == 0) && ((*(uint *)(iVar2 + 0xb8) & 2) == 0)) {
      iVar3 = 0;
      iVar4 = param_1;
      while( true ) {
        iVar2 = FUN_001054ec(iVar2,0);
        if ((*(char *)(iVar3 + iVar2 + 0x10) != '\x01') && (*(int *)(iVar4 + 0x30) == 0)) {
          iVar2 = *(int *)(iVar4 + 0x40);
          if (iVar2 == 0) {
            iVar2 = FUN_00174ce0(*(undefined4 *)(param_1 + 0x238),iVar3,param_1);
            *(int *)(iVar4 + 0x40) = iVar2;
          }
          *(int *)(iVar2 + 4) = param_1;
          *(int *)(*(int *)(iVar4 + 0x40) + 8) = iVar3;
          *(undefined4 *)(*(int *)(iVar4 + 0x40) + 0x28) = 1;
          *(undefined4 *)(*(int *)(iVar4 + 0x40) + 0x2c) = *(undefined4 *)(iVar4 + 0x178);
        }
        bVar1 = iVar3 == 3;
        iVar4 = iVar4 + 4;
        iVar3 = iVar3 + 1;
        if (bVar1) break;
        iVar2 = *(int *)(param_1 + 0xb0);
      }
    }
  }
  return;
}

/* FUN_00177ad0 @ 0x177ad0 (124 bytes) */
int FUN_00177ad0(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0xb0);
  if (((*(uint *)(iVar1 + 0xb8) & 1) == 0) || ((*(uint *)(iVar1 + 0xd0) & 1) == 0)) {
    uVar2 = 0;
  }
  else {
    FUN_00103d50(iVar1 + 0xa4,1,0);
    FUN_00103d50(*(int *)(param_1 + 0xb0) + 0xbc,1,0);
    FUN_001745ac(param_1);
    uVar2 = 1;
  }
  return uVar2;
}

/* FUN_00177b4c @ 0x177b4c (388 bytes) */
int FUN_00177b4c(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  
  uVar4 = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x158);
  iVar1 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 0x238));
  FUN_001046c8(iVar1,0,*(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c));
  uVar3 = *(undefined4 *)(PTR_DAT_001e8b64 + param_3 * 4);
  *(undefined4 *)(iVar1 + 0x94) = *(undefined4 *)(iVar1 + 0x14c);
  *(undefined4 *)(iVar1 + 0x9c) = uVar3;
  *(undefined4 *)(iVar1 + 0x98) = 0;
  iVar5 = param_2 * 0x18 + 0x80;
  FUN_001046c8(iVar1,1,*(undefined4 *)(param_2 * 0x18 + *(int *)(param_1 + 0xb0) + 0x8c));
  iVar2 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),param_2);
  uVar3 = *(undefined4 *)(PTR_DAT_001e8b8c + (uint)*(byte *)(param_3 + iVar2 + 0x10) * 4);
  iVar2 = FUN_001054ec(iVar1,1);
  *(undefined4 *)(iVar2 + 0x10) = uVar3;
  FUN_00103d50(iVar1 + 0xa4,2,*(uint *)(*(int *)(param_1 + 0xb0) + iVar5 + 0x20) >> 1 & 1);
  FUN_00103d50(iVar1 + 0xa4,1,*(uint *)(*(int *)(param_1 + 0xb0) + iVar5 + 0x20) & 1);
  *(undefined4 *)(iVar1 + 0x120) = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x120);
  *(undefined4 *)(iVar1 + 0x124) = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x124);
  FUN_001049e8(iVar1,*(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c),
               *(undefined4 *)(param_1 + 0x238));
  *(undefined1 *)(param_3 + *(int *)(param_1 + 0xb0) + 0x9c) = 1;
  iVar2 = *(int *)(param_1 + 0xb0);
  if ((*(uint *)(iVar2 + 0x14) & 0x200) == 0) {
    FUN_001049e8(iVar2,*(undefined4 *)(iVar2 + 0x8c),*(undefined4 *)(param_1 + 0x238));
    iVar2 = *(int *)(param_1 + 0xb0);
  }
  FUN_000e7738(uVar4,iVar2,iVar1);
  return iVar1;
}

/* FUN_00177cd0 @ 0x177cd0 (324 bytes) */
int FUN_00177cd0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar4 = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x158);
  iVar1 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 0x238));
  FUN_001046c8(iVar1,0,*(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c));
  uVar3 = *(undefined4 *)(PTR_DAT_001e8b64 + param_3 * 4);
  *(undefined4 *)(iVar1 + 0x94) = *(undefined4 *)(iVar1 + 0x14c);
  *(undefined4 *)(iVar1 + 0x98) = 0;
  *(undefined4 *)(iVar1 + 0x9c) = uVar3;
  FUN_001046c8(iVar1,1,*(undefined4 *)(param_2 + 0xc));
  uVar3 = *(undefined4 *)(PTR_DAT_001e8b8c + *(int *)(param_2 + 0x10) * 4);
  iVar2 = FUN_001054ec(iVar1,1);
  *(undefined4 *)(iVar2 + 0x10) = uVar3;
  if (*(int *)(param_2 + 0x18) != 0) {
    FUN_00103d50(iVar1 + 0xa4,1,1);
  }
  *(undefined4 *)(iVar1 + 0x120) = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x120);
  *(undefined4 *)(iVar1 + 0x124) = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x124);
  FUN_001049e8(iVar1,*(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c),
               *(undefined4 *)(param_1 + 0x238));
  *(undefined1 *)(param_3 + *(int *)(param_1 + 0xb0) + 0x9c) = 1;
  iVar2 = *(int *)(param_1 + 0xb0);
  if ((*(uint *)(iVar2 + 0x14) & 0x200) == 0) {
    FUN_001049e8(iVar2,*(undefined4 *)(iVar2 + 0x8c),*(undefined4 *)(param_1 + 0x238));
    iVar2 = *(int *)(param_1 + 0xb0);
  }
  FUN_000e7738(uVar4,iVar2,iVar1);
  return iVar1;
}

/* FUN_00177e14 @ 0x177e14 (528 bytes) */
int FUN_00177e14(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
  int param_5;
{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  
  uVar5 = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x158);
  iVar2 = FUN_001043f0(param_2,*(undefined4 *)(param_1 + 0x238));
  FUN_001046c8(iVar2,0,*(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c));
  uVar4 = *(undefined4 *)(PTR_DAT_001e8b64 + param_5 * 4);
  *(undefined4 *)(iVar2 + 0x94) = *(undefined4 *)(iVar2 + 0x14c);
  *(undefined4 *)(iVar2 + 0x9c) = uVar4;
  *(undefined4 *)(iVar2 + 0x98) = 0;
  iVar6 = param_3 * 0x18 + 0x80;
  FUN_001046c8(iVar2,1,*(undefined4 *)(param_3 * 0x18 + *(int *)(param_1 + 0xb0) + 0x8c));
  iVar3 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),param_3);
  puVar1 = PTR_DAT_001e8b8c;
  uVar4 = *(undefined4 *)(PTR_DAT_001e8b8c + (uint)*(byte *)(param_5 + iVar3 + 0x10) * 4);
  iVar3 = FUN_001054ec(iVar2,1);
  *(undefined4 *)(iVar3 + 0x10) = uVar4;
  FUN_00103d50(iVar2 + 0xa4,2,*(uint *)(*(int *)(param_1 + 0xb0) + iVar6 + 0x20) >> 1 & 1);
  FUN_00103d50(iVar2 + 0xa4,1,*(uint *)(*(int *)(param_1 + 0xb0) + iVar6 + 0x20) & 1);
  iVar6 = param_4 * 0x18 + 0x80;
  FUN_001046c8(iVar2,2,*(undefined4 *)(param_4 * 0x18 + *(int *)(param_1 + 0xb0) + 0x8c));
  iVar3 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),param_4);
  uVar4 = *(undefined4 *)(puVar1 + (uint)*(byte *)(param_5 + iVar3 + 0x10) * 4);
  iVar3 = FUN_001054ec(iVar2,2);
  *(undefined4 *)(iVar3 + 0x10) = uVar4;
  FUN_00103d50(iVar2 + 0xbc,2,*(uint *)(*(int *)(param_1 + 0xb0) + iVar6 + 0x20) >> 1 & 1);
  FUN_00103d50(iVar2 + 0xbc,1,*(uint *)(*(int *)(param_1 + 0xb0) + iVar6 + 0x20) & 1);
  *(undefined4 *)(iVar2 + 0x120) = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x120);
  *(undefined4 *)(iVar2 + 0x124) = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x124);
  FUN_001049e8(iVar2,*(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c),
               *(undefined4 *)(param_1 + 0x238));
  *(undefined1 *)(param_5 + *(int *)(param_1 + 0xb0) + 0x9c) = 1;
  iVar3 = *(int *)(param_1 + 0xb0);
  if ((*(uint *)(iVar3 + 0x14) & 0x200) == 0) {
    FUN_001049e8(iVar3,*(undefined4 *)(iVar3 + 0x8c),*(undefined4 *)(param_1 + 0x238));
    iVar3 = *(int *)(param_1 + 0xb0);
  }
  FUN_000e7738(uVar5,iVar3,iVar2);
  return iVar2;
}

/* FUN_00178024 @ 0x178024 (384 bytes) */
int FUN_00178024(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  
  uVar4 = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x158);
  iVar1 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 0x238));
  FUN_001046c8(iVar1,0,*(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c));
  uVar3 = *(undefined4 *)(PTR_DAT_001e8b64 + param_3 * 4);
  *(undefined4 *)(iVar1 + 0x94) = *(undefined4 *)(iVar1 + 0x14c);
  *(undefined4 *)(iVar1 + 0x9c) = uVar3;
  *(undefined4 *)(iVar1 + 0x98) = 0;
  iVar5 = param_2 * 0x18 + 0x80;
  FUN_001046c8(iVar1,1,*(undefined4 *)(param_2 * 0x18 + *(int *)(param_1 + 0xb0) + 0x8c));
  iVar2 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),param_2);
  uVar3 = *(undefined4 *)(PTR_DAT_001e8b8c + (uint)*(byte *)(param_3 + iVar2 + 0x10) * 4);
  iVar2 = FUN_001054ec(iVar1,1);
  *(undefined4 *)(iVar2 + 0x10) = uVar3;
  FUN_00103d50(iVar1 + 0xa4,2,*(uint *)(*(int *)(param_1 + 0xb0) + iVar5 + 0x20) >> 1 & 1);
  FUN_00103d50(iVar1 + 0xa4,1,*(uint *)(*(int *)(param_1 + 0xb0) + iVar5 + 0x20) & 1);
  iVar2 = *(int *)(param_1 + 0xb0);
  *(undefined4 *)(iVar1 + 0x124) = param_4;
  *(undefined4 *)(iVar1 + 0x120) = *(undefined4 *)(iVar2 + 0x120);
  FUN_001049e8(iVar1,*(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c),
               *(undefined4 *)(param_1 + 0x238));
  *(undefined1 *)(param_3 + *(int *)(param_1 + 0xb0) + 0x9c) = 1;
  iVar2 = *(int *)(param_1 + 0xb0);
  if ((*(uint *)(iVar2 + 0x14) & 0x200) == 0) {
    FUN_001049e8(iVar2,*(undefined4 *)(iVar2 + 0x8c),*(undefined4 *)(param_1 + 0x238));
    iVar2 = *(int *)(param_1 + 0xb0);
  }
  FUN_000e7738(uVar4,iVar2,iVar1);
  return iVar1;
}

/* FUN_001781a4 @ 0x1781a4 (404 bytes) */
int FUN_001781a4(param_1, param_2, param_3)
  float *param_1;
  int param_2;
  undefined4 *param_3;
{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 local_68 [6];
  int local_50 [6];
  float local_38;
  float local_34 [2];
  
  iVar5 = 5;
  *param_1 = NAN;
  puVar1 = local_68;
  do {
    *puVar1 = 0x7ffffffe;
    puVar1 = puVar1 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  piVar3 = local_50;
  iVar4 = 4;
  for (iVar5 = 1; iVar2 = (**(code **)(**(int **)(param_2 + 0xb0) + 0x14))(), iVar5 <= iVar2;
      iVar5 = iVar5 + 1) {
    iVar2 = FUN_0011346c(*(undefined4 *)(param_2 + 0x238),*(undefined4 *)(param_2 + 0xb0));
    if (iVar2 == 0) {
      *piVar3 = 0;
    }
    else if (iVar5 == 2) {
      local_50[1] = 0;
    }
    else if (iVar5 == 3) {
      local_50[2] = 1;
    }
    else if (iVar5 == 1) {
      local_50[0] = 3;
    }
    iVar2 = *piVar3;
    piVar3 = piVar3 + 1;
    puVar1 = (undefined4 *)
             FUN_00173360(*(undefined4 *)(param_2 + 0x238),
                          *(undefined4 *)((iVar4 + iVar2) * 4 + param_2 + 0x168));
    *(undefined4 *)(iVar4 + (int)local_68) = *puVar1;
    iVar4 = iVar4 + 4;
  }
  piVar3 = *(int **)(*(int *)(param_2 + 0xb0) + 0x88);
  (**(code **)(*piVar3 + 4))(piVar3,param_1,local_68,*(undefined4 *)(param_2 + 0x238));
  if (*param_1 != FLOAT_001aa1d0) {
    ((float * (*)())FUN_0010aee8)(&local_38,*(undefined4 *)(param_2 + 0xb0),*param_1);
    *param_1 = local_38;
    ((void (*)())FUN_0010b118)(local_34,*(undefined4 *)(param_2 + 0xb0));
    if (local_34[0] != *param_1) {
      *param_3 = 1;
      *param_1 = local_34[0];
    }
  }
  return param_1;
}

/* FUN_00178338 @ 0x178338 (656 bytes) */
int FUN_00178338(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  uint uVar2;
  float *pfVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  int local_54 [9];
  
  iVar1 = param_2 * 4;
  if (*(int *)(iVar1 + param_1 + 0x30) == 0) {
    piVar8 = (int *)(iVar1 + param_1 + 0x178);
    piVar9 = local_54;
    iVar6 = 0x98;
    for (iVar7 = 1; iVar4 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))(), iVar7 <= iVar4;
        iVar7 = iVar7 + 1) {
      if (*piVar8 < 0) {
        pfVar3 = (float *)FUN_00173360(*(undefined4 *)(param_1 + 0x238));
        iVar4 = ((undefined4 (*)())FUN_00176350)((double)*pfVar3);
        *piVar9 = iVar4;
      }
      else if (*piVar8 < 1) {
        *piVar9 = 0;
      }
      else {
        iVar4 = FUN_00173330(*(undefined4 *)(param_1 + 0x238));
        iVar4 = *(int *)(iVar4 + 0x10);
        *piVar9 = iVar4;
        iVar5 = *(int *)(param_1 + 0xb0) + iVar6;
        uVar2 = *(uint *)(iVar5 + 0x20);
        if ((uVar2 & 2) != 0) {
          *piVar9 = *(int *)(&DAT_001e6188 + iVar4 * 4);
          uVar2 = *(uint *)(iVar5 + 0x20);
        }
        if ((uVar2 & 1) != 0) {
          *piVar9 = *(int *)(&DAT_001e6170 + *piVar9 * 4);
        }
      }
      iVar6 = iVar6 + 0x18;
      piVar9 = piVar9 + 1;
      piVar8 = piVar8 + 4;
    }
    iVar6 = *(int *)(param_1 + 0xb0);
    switch(*(undefined4 *)(*(int *)(iVar6 + 0x88) + 8)) {
    case 0x12:
      local_54[0] = *(int *)(&DAT_001e5bf4 + (local_54[0] * 6 + local_54[1]) * 4);
      break;
    case 0x13:
      local_54[0] = *(int *)(&DAT_001e5ad4 + (local_54[0] * 6 + local_54[1]) * 4);
      break;
    default:
      local_54[0] = 0;
      break;
    case 0x17:
      local_54[0] = *(int *)(&DAT_001e5a44 + (local_54[0] * 6 + local_54[1]) * 4);
      break;
    case 0x19:
      local_54[0] = *(int *)(&DAT_001e59b4 + (local_54[0] * 6 + local_54[1]) * 4);
      break;
    case 0x24:
    case 0x25:
    case 0x26:
      local_54[0] = *(int *)(&DAT_001e5b64 + (local_54[1] * 6 + local_54[2]) * 4);
      break;
    case 0x31: ;
    }
    if ((0 < *(int *)(iVar6 + 0x124)) && (local_54[0] != 2)) {
      local_54[0] = 0;
    }
    iVar7 = local_54[0];
    if (*(int *)(iVar6 + 0x120) != 0) {
      iVar7 = (DAT_001e6158)[local_54[0]];
      if (local_54[0] == iVar7) {
        *(undefined4 *)(iVar1 + param_3) = 0;
        iVar7 = local_54[0];
      }
      else {
        *(undefined4 *)(iVar1 + param_3) = 1;
      }
    }
    iVar6 = *(int *)(iVar1 + param_1 + 0x40);
    if (iVar6 == 0) {
      iVar6 = FUN_00174ce0(*(undefined4 *)(param_1 + 0x238),param_2,param_1);
      *(int *)(iVar1 + param_1 + 0x40) = iVar6;
    }
    *(int *)(iVar6 + 0x10) = iVar7;
  }
  return;
}

/* FUN_00178648 @ 0x178648 (708 bytes) */
int FUN_00178648(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  int local_54 [9];
  
  iVar2 = param_2 * 4 + param_1;
  if (*(int *)(iVar2 + 0x30) == 0) {
    piVar8 = (int *)(iVar2 + 0x178);
    piVar9 = local_54;
    iVar2 = 0x98;
    iVar6 = 0x98;
    for (iVar7 = 1; iVar4 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))(), iVar7 <= iVar4;
        iVar7 = iVar7 + 1) {
      if (*piVar8 < 0) {
        puVar3 = (undefined4 *)FUN_00173360(*(undefined4 *)(param_1 + 0x238));
        iVar4 = FUN_00176324(*puVar3);
        *piVar9 = iVar4;
      }
      else {
        if (*piVar8 < 1) {
          *piVar9 = 0;
          iVar4 = *(int *)(param_1 + 0xb0) + iVar2;
          uVar1 = *(uint *)(iVar4 + 0x20);
          if ((uVar1 & 2) != 0) {
            *piVar9 = DAT_001e61d0[0];
            uVar1 = *(uint *)(iVar4 + 0x20);
          }
        }
        else {
          iVar4 = FUN_00173330(*(undefined4 *)(param_1 + 0x238));
          iVar4 = *(int *)(iVar4 + 0xc);
          *piVar9 = iVar4;
          iVar5 = *(int *)(param_1 + 0xb0) + iVar6;
          uVar1 = *(uint *)(iVar5 + 0x20);
          if ((uVar1 & 2) != 0) {
            *piVar9 = (DAT_001e61d0)[iVar4];
            uVar1 = *(uint *)(iVar5 + 0x20);
          }
        }
        if ((uVar1 & 1) != 0) {
          *piVar9 = *(int *)(&DAT_001e61b8 + *piVar9 * 4);
        }
      }
      iVar6 = iVar6 + 0x18;
      iVar2 = iVar2 + 0x18;
      piVar9 = piVar9 + 1;
      piVar8 = piVar8 + 4;
    }
    switch(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8)) {
    case 0x12:
      iVar2 = *(int *)(&DAT_001e5ec4 + (local_54[0] * 6 + local_54[1]) * 4);
      break;
    case 0x13:
      iVar2 = *(int *)(&DAT_001e5c84 + (local_54[0] * 6 + local_54[1]) * 4);
      break;
    case 0x14:
      iVar2 = *(int *)(&DAT_001e5ec4 +
                      (*(int *)(&DAT_001e5c84 + (local_54[0] * 6 + local_54[1]) * 4) * 6 +
                      local_54[2]) * 4);
      break;
    default:
      iVar2 = 0;
      break;
    case 0x17:
      iVar2 = *(int *)(&DAT_001e5da4 + (local_54[0] * 6 + local_54[1]) * 4);
      break;
    case 0x19:
      iVar2 = *(int *)(&DAT_001e5d14 + (local_54[0] * 6 + local_54[1]) * 4);
      break;
    case 0x24:
    case 0x25:
    case 0x26:
      iVar2 = *(int *)(&DAT_001e5e34 + (local_54[1] * 6 + local_54[2]) * 4);
      break;
    case 0x31:
    case 0x3e:
    case 0x3f:
    case 0x40:
    case 0x41:
    case 0x42:
    case 0x43:
      iVar2 = local_54[0];
    }
    if (*(int *)(*(int *)(param_1 + 0xb0) + 0x120) != 0) {
      iVar2 = (DAT_001e61a0)[iVar2];
    }
    iVar7 = param_2 * 4 + param_1;
    iVar6 = *(int *)(iVar7 + 0x40);
    if (iVar6 == 0) {
      iVar6 = FUN_00174ce0(*(undefined4 *)(param_1 + 0x238),param_2,param_1);
      *(int *)(iVar7 + 0x40) = iVar6;
    }
    *(int *)(iVar6 + 0xc) = iVar2;
  }
  return;
}

/* FUN_001789d4 @ 0x1789d4 (28 bytes) */
int FUN_001789d4(param_1)
  int param_1;
{
  return *(int *)(*(int *)(param_1 + 0x88) + 8) - 0x8bU < 2;
}

/* FUN_001789f0 @ 0x1789f0 (168 bytes) */
int FUN_001789f0(param_1)
  int param_1;
{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  piVar1 = *(int **)(param_1 + 0xb0);
  uVar3 = *(int *)(piVar1[0x22] + 8) - 0x12;
  if ((uVar3 < 0x20) && (iVar4 = 1, (1 << (uVar3 & 0x3f) & 0x800000a7U) != 0)) {
    while( true ) {
      iVar2 = (**(code **)(*piVar1 + 0x14))();
      if (iVar2 < iVar4) {
        return 1;
      }
      piVar1 = *(int **)(param_1 + 0xb0);
      if (((piVar1[iVar4 * 6 + 0x28] & 1U) != 0) || ((piVar1[iVar4 * 6 + 0x28] & 2U) != 0)) break;
      iVar4 = iVar4 + 1;
    }
  }
  return 0;
}

/* FUN_00178a98 @ 0x178a98 (132 bytes) */
int FUN_00178a98(param_1, param_2)
  int param_1;
  int param_2;
{
  if (*(int *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8) == 0x32) {
    if (param_2 == 1) {
      return *(uint *)(param_1 + 0x178) >> 0x1f;
    }
    if (param_2 < 2) {
      if (param_2 == 0) {
        return 1;
      }
    }
    else {
      if (param_2 == 2) {
        if (((*(int *)(param_1 + 0x178) < 0) && (*(int *)(param_1 + 0x180) < 0)) &&
           (*(int *)(param_1 + 0x184) < 0)) {
          return 1;
        }
        return 0;
      }
      if (param_2 == 3) {
        return 1;
      }
    }
  }
  return 0;
}

/* FUN_00178b1c @ 0x178b1c (360 bytes) */
int FUN_00178b1c(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  piVar3 = *(int **)(param_1 + 0xb0);
  iVar2 = *(int *)(piVar3[0x22] + 8);
  if (iVar2 == 0x1c) {
    for (iVar2 = 1; iVar5 = (**(code **)(*piVar3 + 0x14))(), iVar2 <= iVar5; iVar2 = iVar2 + 1) {
      iVar5 = 0;
      piVar3 = (int *)(iVar2 * 0x10 + param_1 + 0x168);
      do {
        if (-1 < *piVar3) goto LAB_00178b50;
        bVar1 = iVar5 != 2;
        piVar3 = piVar3 + 1;
        iVar5 = iVar5 + 1;
      } while (bVar1);
      piVar3 = *(int **)(param_1 + 0xb0);
    }
LAB_00178bc4:
    uVar4 = 1;
  }
  else {
    if (iVar2 < 0x1d) {
      if (iVar2 == 0x18) {
LAB_00178b6c:
        for (iVar2 = 1; iVar5 = (**(code **)(*piVar3 + 0x14))(), iVar2 <= iVar5; iVar2 = iVar2 + 1)
        {
          iVar5 = 4;
          piVar3 = (int *)(iVar2 * 0x10 + param_1 + 0x168);
          do {
            if (-1 < *piVar3) goto LAB_00178b50;
            piVar3 = piVar3 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          piVar3 = *(int **)(param_1 + 0xb0);
        }
        goto LAB_00178bc4;
      }
    }
    else {
      if (iVar2 == 0x1d) goto LAB_00178b6c;
      if (iVar2 == 0x1e) {
        iVar2 = 1;
        iVar5 = param_1 + 0x170;
        do {
          piVar3 = (int *)(iVar5 + 8);
          iVar6 = 0;
          do {
            if (-1 < *piVar3) goto LAB_00178b50;
            bVar1 = iVar6 != 1;
            piVar3 = piVar3 + 1;
            iVar6 = iVar6 + 1;
          } while (bVar1);
          bVar1 = iVar2 != 2;
          iVar5 = iVar5 + 0x10;
          iVar2 = iVar2 + 1;
        } while (bVar1);
        if (*(int *)(param_1 + 0x1a0) < 0) goto LAB_00178bc4;
      }
    }
LAB_00178b50:
    uVar4 = 0;
  }
  return uVar4;
}

/* FUN_00178c84 @ 0x178c84 (244 bytes) */
int FUN_00178c84(param_1, param_2, param_3)
  undefined4 *param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = *(int **)(param_2 + 0xb0);
  if (*(int *)(piVar4[0x22] + 8) == 0x32) {
    iVar1 = (**(code **)(*piVar4 + 0x14))(piVar4);
    if (iVar1 == 1) {
      iVar3 = param_3 * 0x10 + param_2;
      iVar1 = *(int *)(iVar3 + 0x168);
      if ((iVar1 != *(int *)(iVar3 + 0x16c)) || (iVar1 != *(int *)(iVar3 + 0x174)))
      goto LAB_00178d10;
    }
    else {
      if (iVar1 != 3) goto LAB_00178d10;
      if (param_3 == 2) {
        iVar1 = *(int *)(param_2 + 0x18c);
      }
      else if (param_3 == 3) {
        iVar1 = *(int *)(param_2 + 0x1a4);
      }
      else {
        if (param_3 != 1) goto LAB_00178d10;
        iVar1 = *(int *)(param_2 + 0x178);
      }
    }
    if (iVar1 < 0) {
      puVar2 = (undefined4 *)FUN_00173360(*(undefined4 *)(param_2 + 0x238));
      *param_1 = *puVar2;
      return param_1;
    }
  }
LAB_00178d10:
  *param_1 = 0x7ffffffe;
  return param_1;
}

/* FUN_00178d78 @ 0x178d78 (280 bytes) */
int FUN_00178d78(param_1, param_2, param_3)
  undefined4 *param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar1 = *(int *)(*(int *)(*(int *)(param_2 + 0xb0) + 0x88) + 8);
  if (iVar1 == 0x1c) {
    iVar1 = param_3 * 0x10 + param_2;
    iVar3 = *(int *)(iVar1 + 0x168);
    if ((iVar3 != *(int *)(iVar1 + 0x16c)) || (iVar3 != *(int *)(iVar1 + 0x170))) goto LAB_00178de8;
  }
  else {
    if (iVar1 < 0x1d) {
      if (iVar1 != 0x18) goto LAB_00178de8;
    }
    else if (iVar1 != 0x1d) {
      if (iVar1 != 0x1e) goto LAB_00178de8;
      if (param_3 - 1U < 2) {
        iVar1 = param_3 * 0x10 + param_2;
        iVar3 = *(int *)(iVar1 + 0x168);
        if (iVar3 != *(int *)(iVar1 + 0x16c)) goto LAB_00178de8;
      }
      else {
        iVar3 = *(int *)(param_3 * 0x10 + param_2 + 0x170);
      }
      goto LAB_00178e60;
    }
    iVar1 = param_3 * 0x10 + param_2;
    iVar3 = *(int *)(iVar1 + 0x168);
    if (((iVar3 != *(int *)(iVar1 + 0x16c)) || (iVar3 != *(int *)(iVar1 + 0x170))) ||
       (iVar3 != *(int *)(iVar1 + 0x174))) goto LAB_00178de8;
  }
LAB_00178e60:
  if (iVar3 < 0) {
    puVar2 = (undefined4 *)FUN_00173360(*(undefined4 *)(param_2 + 0x238));
    *param_1 = *puVar2;
    return param_1;
  }
LAB_00178de8:
  *param_1 = 0x7ffffffe;
  return param_1;
}

/* FUN_00178e90 @ 0x178e90 (468 bytes) */
int FUN_00178e90(param_1, param_2, param_3)
  float *param_1;
  int param_2;
  int param_3;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  int iVar5;
  double dVar6;
  double dVar7;
  float local_58 [15];
  
  iVar5 = 5;
  pfVar4 = local_58;
  do {
    *pfVar4 = NAN;
    pfVar4 = pfVar4 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  *param_1 = NAN;
  if (*(int *)(*(int *)(*(int *)(param_2 + 0xb0) + 0x88) + 8) == 0x32) {
    if (param_3 == 1) {
      pfVar4 = (float *)FUN_00173360(*(undefined4 *)(param_2 + 0x238),
                                     *(undefined4 *)(param_2 + 0x178));
      fVar3 = *pfVar4;
      fVar2 = fVar3;
      if (fVar3 < 0.0) {
        fVar2 = FLOAT_001aa0d4;
      }
      fVar1 = FLOAT_001aa0d4;
      if (-fVar3 < 0.0) {
        fVar1 = fVar2;
      }
      *param_1 = fVar1;
    }
    else {
      if (param_3 < 2) {
        if (param_3 != 0) {
          return param_1;
        }
      }
      else {
        if (param_3 == 2) {
          pfVar4 = (float *)FUN_00173360(*(undefined4 *)(param_2 + 0x238),
                                         *(undefined4 *)(param_2 + 0x178));
          local_58[0] = *pfVar4;
          pfVar4 = (float *)FUN_00173360(*(undefined4 *)(param_2 + 0x238),
                                         *(undefined4 *)(param_2 + 0x17c));
          local_58[1] = *pfVar4;
          if ((FLOAT_001aa0d4 < local_58[0]) && (FLOAT_001aa0d4 < local_58[1])) {
            pfVar4 = (float *)FUN_00173360(*(undefined4 *)(param_2 + 0x238),
                                           *(undefined4 *)(param_2 + 0x184));
            local_58[3] = *pfVar4;
            fVar2 = FLOAT_001aa1d4;
            if (FLOAT_001aa1d4 <= local_58[3]) {
              fVar3 = FLOAT_001aa1d8;
              if (local_58[3] - FLOAT_001aa1d8 < 0.0) {
                fVar3 = local_58[3];
              }
              fVar2 = local_58[3];
              if (-(local_58[3] - FLOAT_001aa1d8) < 0.0) {
                fVar2 = fVar3;
              }
            }
            dVar6 = (double)_log((double)local_58[1]);
            dVar7 = (double)_log(DOUBLE_001aa2a0);
            dVar6 = (double)_pow(DOUBLE_001aa2a0,(double)(fVar2 * (float)(dVar6 / dVar7)));
            *param_1 = (float)dVar6;
            return param_1;
          }
          *param_1 = 0.0;
          return param_1;
        }
        if (param_3 != 3) {
          return param_1;
        }
      }
      *param_1 = 1.0;
    }
  }
  return param_1;
}

/* FUN_00179064 @ 0x179064 (212 bytes) */
int FUN_00179064(param_1, param_2)
  int param_1;
  int param_2;
{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  (**(code **)(**(int **)(param_1 + 0xb0) + 0x48))();
  uVar4 = *(undefined4 *)(param_2 * 0x18 + *(int *)(param_1 + 0xb0) + 0x20);
  iVar3 = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),uVar4);
  if ((((*(char *)(iVar3 + 8) != '\0') && (bVar1 = *(byte *)(iVar3 + 9), (bVar1 & 1) == 0)) &&
      ((bVar1 & 2) == 0)) && (((bVar1 & 4) == 0 && ((bVar1 & 8) == 0)))) {
    return iVar3;
  }
  *(undefined1 *)(iVar3 + 8) = 2;
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c);
  *(int *)(iVar3 + 0x10) = param_2;
  *(undefined4 *)(iVar3 + 0xc) = uVar2;
  *(undefined4 *)(iVar3 + 0x14) = uVar4;
  *(undefined1 *)(iVar3 + 9) = 0;
  *(undefined4 *)(iVar3 + 0x1c) = 0;
  *(undefined4 *)(iVar3 + 0x18) = 0;
  FUN_0017629c(iVar3,*(undefined4 *)(param_1 + 0x238));
  return iVar3;
}

/* FUN_00179138 @ 0x179138 (408 bytes) */
int FUN_00179138(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  
  iVar2 = FUN_0010a240(0xa2,*(undefined4 *)(param_1 + 0x238));
  iVar1 = *(int *)(param_1 + 0x238);
  uVar3 = *(undefined4 *)(*(int *)(iVar1 + 0x6c4) + 0x3ac);
  iVar5 = *(int *)(iVar1 + 0x3b0) + -1;
  *(int *)(iVar1 + 0x3b0) = iVar5;
  iVar1 = FUN_00127608(uVar3,0x36,iVar5,0);
  FUN_0012306c(iVar1,iVar2);
  piVar6 = *(int **)(*(int *)(param_1 + 0xb0) + 0x158);
  iVar5 = (**(code **)(*piVar6 + 0x24))(piVar6);
  if (iVar5 == 0) {
    FUN_000e7700(piVar6,*(undefined4 *)(param_1 + 0xb0),iVar2);
  }
  else {
    FUN_000e7688(piVar6[1],iVar2);
  }
  if (*(int *)(*(int *)(iVar1 + 0x2c) + 4) == 0) {
    uVar3 = *(undefined4 *)(*(int *)(param_1 + 0x238) + 0x378);
    puVar4 = (undefined4 *)FUN_00193e18(uVar3,0x240);
    *puVar4 = uVar3;
    FUN_00173938(puVar4 + 1,iVar2,*(undefined4 *)(param_1 + 0x238));
    FUN_000e9c00(piVar6,iVar1,puVar4 + 1);
  }
  *(undefined4 *)(iVar2 + 300) = 1;
  *(undefined4 *)(iVar2 + 0x84) = 1;
  FUN_001046c8(iVar2,0,iVar1);
  uVar3 = *(undefined4 *)(param_2 * 0x18 + *(int *)(param_1 + 0xb0) + 0x8c);
  FUN_001046c8(iVar2,1,uVar3);
  iVar5 = param_2 * 4 + param_1;
  FUN_001236e4(uVar3,1,iVar2);
  FUN_00106004(iVar2,1,*(undefined4 *)(iVar5 + 0x210),0,*(undefined4 *)(param_1 + 0x238));
  FUN_001046c8(*(undefined4 *)(param_1 + 0xb0),param_2,iVar1);
  FUN_001236e4(iVar1,param_2,*(undefined4 *)(param_1 + 0xb0));
  *(int *)(iVar5 + 0x210) = iVar2;
  return iVar2;
}

/* FUN_001792f0 @ 0x1792f0 (232 bytes) */
int FUN_001792f0(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  
  piVar1 = *(int **)(param_1 + 0xb0);
  puVar6 = *(uint **)(piVar1[param_2 * 6 + 0x23] + 0x2c);
  uVar5 = puVar6[1];
  uVar4 = uVar5 - 1;
  if (uVar4 < *puVar6) {
    if (uVar5 <= uVar4) {
      _memset((void *)(uVar5 * 4 + puVar6[2]),0,(uVar4 - uVar5) * 4 + 4);
      puVar6[1] = uVar5;
      piVar1 = *(int **)(param_1 + 0xb0);
    }
    piVar3 = (int *)(uVar4 * 4 + puVar6[2]);
  }
  else {
    piVar3 = (int *)FUN_0019423c(puVar6,uVar4);
    piVar1 = *(int **)(param_1 + 0xb0);
  }
  iVar7 = *piVar3;
  iVar2 = (**(code **)(*piVar1 + 100))();
  if ((iVar2 != 0) &&
     (iVar2 = FUN_001131c0(*(undefined4 *)(*(int *)(*(int *)(iVar7 + 0xb0) + 0x88) + 8),
                           *(undefined4 *)(param_1 + 0x238)), iVar2 != 0)) {
    return 1;
  }
  return 0;
}

/* FUN_001793d8 @ 0x1793d8 (560 bytes) */
int FUN_001793d8(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  uint *puVar11;
  undefined4 uStack00000020;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c [4];
  
  piVar10 = (int *)(param_2 * 0x10 + param_1 + 0x168);
  iVar4 = 0;
  uStack00000020 = param_3;
  pcVar7 = (char *)&STACKARG(0x20);
  do {
    if (*pcVar7 != '\0') {
      if (iVar4 == 0) {
        iVar4 = *piVar10;
      }
      else {
        iVar9 = FUN_00176264(iVar4,*piVar10);
        if (iVar9 == 0) {
          return 4;
        }
      }
    }
    pcVar7 = pcVar7 + 1;
    piVar10 = piVar10 + 1;
  } while (pcVar7 != &STACKARG(0x24));
  puVar11 = *(uint **)(*(int *)(param_2 * 0x18 + *(int *)(param_1 + 0xb0) + 0x8c) + 0x2c);
  uVar5 = puVar11[1];
  uVar8 = uVar5 - 1;
  if (uVar8 < *puVar11) {
    if (uVar5 <= uVar8) {
      _memset((void *)(uVar5 * 4 + puVar11[2]),0,(uVar8 - uVar5) * 4 + 4);
      puVar11[1] = uVar5;
    }
    piVar10 = (int *)(uVar8 * 4 + puVar11[2]);
  }
  else {
    piVar10 = (int *)FUN_0019423c(puVar11,uVar8);
  }
  iVar6 = *piVar10;
  uVar5 = 0;
  iVar9 = iVar6;
  do {
    iVar2 = FUN_001054ec(*(undefined4 *)(iVar6 + 0xb0),0);
    if (*(char *)(uVar5 + iVar2 + 0x10) != '\x01') {
      iVar2 = *(int *)(iVar9 + 0x20);
      if (iVar2 < 0) {
        puVar3 = (undefined4 *)FUN_00173360(*(undefined4 *)(param_1 + 0x238));
        ((void (*)())FUN_0010b2dc)(&local_38,*(undefined4 *)(param_1 + 0xb0),param_2,*puVar3);
        ((void (*)())FUN_0010b284)(&local_34,*(undefined4 *)(param_1 + 0xb0),param_2,local_38);
        iVar2 = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),local_34);
        iVar2 = *(int *)(iVar2 + 4);
      }
      if (iVar2 == iVar4) {
        return uVar5;
      }
    }
    bVar1 = uVar5 != 3;
    iVar9 = iVar9 + 4;
    uVar5 = uVar5 + 1;
  } while (bVar1);
  iVar9 = 0;
  do {
    iVar2 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
    if (*(char *)(iVar9 + iVar2 + 0x10) != '\x01') {
      iVar2 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),param_2);
      uVar5 = (uint)*(byte *)(iVar9 + iVar2 + 0x10);
      iVar2 = *(int *)(uVar5 * 4 + iVar6 + 0x20);
      if (iVar2 < 0) {
        puVar3 = (undefined4 *)FUN_00173360(*(undefined4 *)(param_1 + 0x238));
        ((void (*)())FUN_0010b2dc)(&local_30,*(undefined4 *)(param_1 + 0xb0),param_2,*puVar3);
        ((void (*)())FUN_0010b284)(local_2c,*(undefined4 *)(param_1 + 0xb0),param_2,local_30);
        iVar2 = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),local_2c[0]);
        iVar2 = *(int *)(iVar2 + 4);
      }
      if (iVar2 == iVar4) {
        return uVar5;
      }
    }
    bVar1 = iVar9 == 3;
    iVar9 = iVar9 + 1;
    if (bVar1) {
      return 4;
    }
  } while( true );
}

/* FUN_00179608 @ 0x179608 (456 bytes) */
int FUN_00179608(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  byte bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  
  iVar3 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),param_3);
  bVar1 = *(byte *)(param_2 + iVar3 + 0x10);
  iVar3 = *(int *)((param_3 * 4 + param_2) * 4 + param_1 + 0x168);
  if (iVar3 < 0) {
    iVar4 = *(int *)(param_1 + 0xb0);
    if (*(int *)(*(int *)(iVar4 + 0x88) + 8) != 0x8e) {
      puVar7 = *(uint **)(*(int *)(param_3 * 0x18 + iVar4 + 0x8c) + 0x2c);
      uVar6 = puVar7[1];
      uVar5 = uVar6 - 1;
      if (uVar5 < *puVar7) {
        if (uVar6 <= uVar5) {
          _memset((void *)(uVar6 * 4 + puVar7[2]),0,(uVar5 - uVar6) * 4 + 4);
          puVar7[1] = uVar6;
          iVar4 = *(int *)(param_1 + 0xb0);
        }
        piVar2 = (int *)(uVar5 * 4 + puVar7[2]);
      }
      else {
        piVar2 = (int *)FUN_0019423c(puVar7,uVar5);
        iVar4 = *(int *)(param_1 + 0xb0);
      }
      iVar3 = *(int *)((uint)bVar1 * 4 + *piVar2 + 0x20);
    }
  }
  else {
    iVar4 = *(int *)(param_1 + 0xb0);
  }
  iVar4 = FUN_001054ec(iVar4,param_4);
  bVar1 = *(byte *)(param_2 + iVar4 + 0x10);
  iVar4 = *(int *)((param_4 * 4 + param_2) * 4 + param_1 + 0x168);
  if ((iVar4 < 0) && (*(int *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8) != 0x8e)) {
    puVar7 = *(uint **)(*(int *)(param_4 * 0x18 + *(int *)(param_1 + 0xb0) + 0x8c) + 0x2c);
    uVar5 = puVar7[1];
    uVar6 = uVar5 - 1;
    if (uVar6 < *puVar7) {
      if (uVar5 <= uVar6) {
        _memset((void *)(uVar5 * 4 + puVar7[2]),0,(uVar6 - uVar5) * 4 + 4);
        puVar7[1] = uVar5;
      }
      piVar2 = (int *)(uVar6 * 4 + puVar7[2]);
    }
    else {
      piVar2 = (int *)FUN_0019423c(puVar7,uVar6);
    }
    iVar4 = *(int *)((uint)bVar1 * 4 + *piVar2 + 0x20);
  }
  FUN_00176264(iVar3,iVar4);
  return;
}

/* FUN_001797d0 @ 0x1797d0 (196 bytes) */
int FUN_001797d0(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  iVar2 = ((int (*)())FUN_00179608)(param_1,param_2,2,3);
  if (iVar2 != 0) {
    iVar2 = *(int *)(param_1 + 0xb0);
    uVar4 = *(uint *)(iVar2 + 0xe8);
    uVar1 = *(uint *)(iVar2 + 0xd0) & 1;
    if ((uVar1 == (uVar4 & 1)) && ((*(uint *)(iVar2 + 0xd0) >> 1 & 1) == (uVar4 >> 1 & 1))) {
      if ((*(int *)(iVar2 + 0x120) == 0) &&
         (((*(int *)(iVar2 + 0x124) == 0 && (uVar1 == 0)) && ((uVar4 & 2) == 0)))) {
        iVar2 = param_2 * 4 + param_1;
        uVar3 = FUN_00173360(*(undefined4 *)(param_1 + 0x238),*(undefined4 *)(iVar2 + 0x198));
        *(undefined4 *)(iVar2 + 0x30) = uVar3;
        return 1;
      }
      return 1;
    }
  }
  return 0;
}

/* FUN_00179894 @ 0x179894 (184 bytes) */
int FUN_00179894(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = ((int (*)())FUN_00179608)(param_1,param_2,1,2);
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
  
  iVar2 = ((int (*)())FUN_00179608)(param_1,param_2,1,2);
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
  
  iVar2 = ((int (*)())FUN_00179608)(param_1,param_2,1,2);
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
  
  iVar2 = ((int (*)())FUN_00179608)(param_1,param_2,1,2);
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
      iVar2 = ((int (*)())FUN_00179608)(param_1,param_2,iVar1 + -1,iVar1);
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
         (iVar2 = ((int (*)())FUN_00179608)(param_1,iVar3,param_2,param_3), iVar2 != 0))) {
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
  
  iVar1 = ((int (*)())FUN_00179608)(param_1,param_2,1,2);
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
    ((int (*)())FUN_00178d78)(local_48,param_1,iVar7);
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
  undefined4 uStack_fc;
  undefined4 local_f8 [5];
  undefined4 local_e4 [23];
  float local_88;
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
                  iVar7 = ((int (*)())FUN_00179138)(param_1,iVar16);
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
      iVar6 = ((int (*)())FUN_001789f0)(param_1);
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
                    iVar8 = ((int (*)())FUN_00179138)(param_1,iVar15);
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
                  dVar23 = (double)local_88;
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
        uVar5 = (&uStack_fc)[iVar22];
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

